#include "decls.h"

/* ParseOperand__GetSwizzle @ 0x97bbbfc0 (12 bytes) */
int ParseOperand__GetSwizzle(this, param_2)
  unsigned char * this;
  uint param_2;
{
  return *(undefined1 *)(param_2 + *(int *)(this + 0x10));
}

/* ParseOperand__ClearSwizzles @ 0x97bbbfcc (68 bytes) */
int ParseOperand__ClearSwizzles(this)
  unsigned char * this;
{
  if (*(int *)(this + 0x10) != 0) {
    _free(*(int *)(this + 0x10));
  }
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  return;
}

/* ParseOperand__GetString @ 0x97bbc010 (584 bytes) */
int ParseOperand__GetString(this)
  unsigned char * this;
{
  short sVar1;
  ushort uVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined4 extraout_r4;
  char *pcVar9;
  uint uVar10;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  double in_stack_ffffff98;
  double in_stack_ffffffa0;
  double in_stack_ffffffa8;
  double in_stack_ffffffb0;
  double in_stack_ffffffb8;
  
  if (*(int *)this != 0) {
    iVar3 = _strlen(*(undefined4 *)(*(int *)this + 0x14));
    pcVar4 = (char *)_malloc(iVar3 + 1);
    _sprintf(pcVar4,DAT_a7b7bbdc,*(undefined4 *)(*(int *)this + 0x14));
    return pcVar4;
  }
  if (*(int *)(this + 4) == 0) {
    pcVar5 = (char *)_malloc(10);
    pcVar4 = DAT_a7b7bbf0;
LAB_97bbc23c:
    _sprintf(pcVar5,pcVar4);
  }
  else {
    pcVar5 = (char *)_malloc(0xa0);
    *pcVar5 = '\0';
    iVar3 = *(int *)this;
    if (iVar3 == 0) {
      sVar1 = *(short *)(this + 0x18);
    }
    else {
      sVar1 = *(short *)(iVar3 + 0x2c);
    }
    if (sVar1 != 0x1406) {
      if (iVar3 == 0) {
        sVar1 = *(short *)(this + 0x18);
      }
      else {
        sVar1 = *(short *)(iVar3 + 0x2c);
      }
      if (sVar1 != 0x1404) {
        if (iVar3 == 0) {
          sVar1 = *(short *)(this + 0x18);
        }
        else {
          sVar1 = *(short *)(iVar3 + 0x2c);
        }
        pcVar4 = DAT_a7b7bbec;
        if (sVar1 != -0x74aa) goto LAB_97bbc23c;
      }
    }
    for (uVar10 = 0; uVar8 = ParseOperand__GetBaseSize(this), uVar10 < uVar8; uVar10 = uVar10 + 1) {
      if (uVar10 != 0) {
        _sprintf(pcVar5,DAT_a7b7bbe0,pcVar5);
      }
      if (*(int *)this == 0) {
        uVar2 = *(ushort *)(this + 0x18);
      }
      else {
        uVar2 = *(ushort *)(*(int *)this + 0x2c);
      }
      if (uVar2 == 0x1406) {
        _sprintf(pcVar5,"%s ",pcVar5);
        iVar6 = _strlen(pcVar5);
        iVar7 = _strlen(pcVar5);
        iVar3 = uVar10 * 4;
        ((char * (*)())_glp_dtostr)(iVar7,extraout_r4,pcVar5 + iVar6,0x9f - iVar7,
                    (double)*(float *)(iVar3 + *(int *)(this + 4)),1e-07,in_f3,in_f4,in_f5,in_f6,
                    in_f7,in_f8,in_stack_ffffff98,in_stack_ffffffa0,in_stack_ffffffa8,
                    in_stack_ffffffb0,in_stack_ffffffb8);
LAB_97bbc1b0:
        pcVar9 = *(char **)(iVar3 + *(int *)(this + 4));
        pcVar4 = DAT_a7b7bbe8;
LAB_97bbc1ec:
        _sprintf(pcVar5,pcVar4,pcVar5,pcVar9);
      }
      else if (uVar2 < 0x1407) {
        if (uVar2 == 0x1404) {
          iVar3 = uVar10 << 2;
          goto LAB_97bbc1b0;
        }
      }
      else if (uVar2 == 0x8b56) {
        pcVar4 = DAT_a7b7bbc4;
        if (*(int *)(uVar10 * 4 + *(int *)(this + 4)) == 0) {
          pcVar9 = "false";
        }
        else {
          pcVar9 = "true";
        }
        goto LAB_97bbc1ec;
      }
    }
  }
  return pcVar5;
}

/* __ZN16ParseSymbolTableC2Ej @ 0x97bbc258 (4 bytes) */
int __ZN16ParseSymbolTableC2Ej(this, param_2)
  void *this;
  uint param_2;
{
  int iVar1;
  void *pvVar2;
  uint uVar3;
  
  *(uint *)((int)this + 0x10) = param_2;
  pvVar2 = operator_new__(param_2 << 2);
  uVar3 = 0;
  *(void **)((int)this + 8) = pvVar2;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)this = 0;
  if (*(int *)((int)this + 0x10) != 0) {
    do {
      iVar1 = uVar3 * 4;
      uVar3 = uVar3 + 1;
      *(undefined4 *)(iVar1 + *(int *)((int)this + 8)) = 0;
    } while (uVar3 < *(uint *)((int)this + 0x10));
  }
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  *(undefined4 *)((int)this + 0x28) = 0;
  *(undefined4 *)((int)this + 0x2c) = 0;
  *(undefined4 *)((int)this + 0x30) = 0;
  *(undefined4 *)((int)this + 0x34) = 0;
  *(undefined4 *)((int)this + 0x38) = 0;
  *(undefined4 *)((int)this + 0x40) = 0;
  *(undefined4 *)((int)this + 0x44) = 0;
  *(undefined4 *)((int)this + 0x48) = 0;
  *(undefined4 *)((int)this + 0x4c) = 0;
  *(undefined4 *)((int)this + 0x50) = 0;
  return;
}

/* __ZN16ParseSymbolTableC1Ej @ 0x97bbc25c (4 bytes) */
int __ZN16ParseSymbolTableC1Ej(this, param_2)
  void *this;
  uint param_2;
{
  int iVar1;
  void *pvVar2;
  uint uVar3;
  
  *(uint *)((int)this + 0x10) = param_2;
  pvVar2 = operator_new__(param_2 << 2);
  uVar3 = 0;
  *(void **)((int)this + 8) = pvVar2;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)this = 0;
  if (*(int *)((int)this + 0x10) != 0) {
    do {
      iVar1 = uVar3 * 4;
      uVar3 = uVar3 + 1;
      *(undefined4 *)(iVar1 + *(int *)((int)this + 8)) = 0;
    } while (uVar3 < *(uint *)((int)this + 0x10));
  }
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  *(undefined4 *)((int)this + 0x28) = 0;
  *(undefined4 *)((int)this + 0x2c) = 0;
  *(undefined4 *)((int)this + 0x30) = 0;
  *(undefined4 *)((int)this + 0x34) = 0;
  *(undefined4 *)((int)this + 0x38) = 0;
  *(undefined4 *)((int)this + 0x40) = 0;
  *(undefined4 *)((int)this + 0x44) = 0;
  *(undefined4 *)((int)this + 0x48) = 0;
  *(undefined4 *)((int)this + 0x4c) = 0;
  *(undefined4 *)((int)this + 0x50) = 0;
  return;
}

/* __ZN16ParseSymbolTableC4Ej @ 0x97bbc260 (184 bytes) */
int __ZN16ParseSymbolTableC4Ej(this, param_2)
  void *this;
  uint param_2;
{
  int iVar1;
  void *pvVar2;
  uint uVar3;
  
  *(uint *)((int)this + 0x10) = param_2;
  pvVar2 = operator_new__(param_2 << 2);
  uVar3 = 0;
  *(void **)((int)this + 8) = pvVar2;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)this = 0;
  if (*(int *)((int)this + 0x10) != 0) {
    do {
      iVar1 = uVar3 * 4;
      uVar3 = uVar3 + 1;
      *(undefined4 *)(iVar1 + *(int *)((int)this + 8)) = 0;
    } while (uVar3 < *(uint *)((int)this + 0x10));
  }
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  *(undefined4 *)((int)this + 0x28) = 0;
  *(undefined4 *)((int)this + 0x2c) = 0;
  *(undefined4 *)((int)this + 0x30) = 0;
  *(undefined4 *)((int)this + 0x34) = 0;
  *(undefined4 *)((int)this + 0x38) = 0;
  *(undefined4 *)((int)this + 0x40) = 0;
  *(undefined4 *)((int)this + 0x44) = 0;
  *(undefined4 *)((int)this + 0x48) = 0;
  *(undefined4 *)((int)this + 0x4c) = 0;
  *(undefined4 *)((int)this + 0x50) = 0;
  return;
}

/* __ZN16ParseSymbolTableD2Ev @ 0x97bbc318 (8 bytes) */
int __ZN16ParseSymbolTableD2Ev(this)
  void *this;
{
  ((int (*)())__ZN16ParseSymbolTableD4Ev)(this);
  return;
}

/* __ZN16ParseSymbolTableD1Ev @ 0x97bbc320 (8 bytes) */
int __ZN16ParseSymbolTableD1Ev(this)
  void *this;
{
  ((int (*)())__ZN16ParseSymbolTableD4Ev)(this);
  return;
}

/* __ZN16ParseSymbolTableD4Ev @ 0x97bbc328 (92 bytes) */
int __ZN16ParseSymbolTableD4Ev(this)
  void *this;
{
  void *this_00;
  void *pvVar1;
  
  this_00 = *(void **)this;
  while (this_00 != (void *)0x0) {
    pvVar1 = *(void **)((int)this_00 + 8);
    __ZN11ParseSymbolD1Ev(this_00);
    __ZdlPv(this_00);
    this_00 = pvVar1;
  }
  __ZdlPv(*(void **)((int)this + 8));
  return;
}

/* ParseSymbolTable__processOperand @ 0x97bbc384 (252 bytes) */
int ParseSymbolTable__processOperand(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  bool bVar1;
  unsigned char * pPVar2;
  int iVar3;
  unsigned char * this_00;
  
  if (((param_2 != (unsigned char *)0x0) &&
      (this_00 = *(unsigned char **)param_2, this_00 != (unsigned char *)0x0)) &&
     (*(int *)(this_00 + 0x50) == 0)) {
    if (*(int *)(this_00 + 0x48) == 0) {
      *(undefined2 *)(this_00 + 0x30) = 0;
    }
    else {
      ParseSymbol__SetArrayPositionFromLastIndex(this_00);
    }
    pPVar2 = (unsigned char *)((int (*)())ParseSymbolTable__FindSymbol)(this,this_00);
    if (pPVar2 == (unsigned char *)0x0) {
      pPVar2 = (unsigned char *)((int (*)())ParseSymbolTable__InsertSymbol)(this,this_00);
      bVar1 = pPVar2 == (unsigned char *)0x0;
    }
    else {
      __ZN11ParseSymbolD1Ev(this_00);
      __ZdlPv(this_00);
      bVar1 = false;
    }
    if (((!bVar1) && (*(unsigned char **)param_2 = pPVar2, *(int *)(pPVar2 + 0x34) != 0)) &&
       (iVar3 = GetBuiltInInitialSwizzle(pPVar2), iVar3 != 0)) {
      ParseOperand__AddSwizzle(param_2,(uchar)iVar3);
      return;
    }
  }
  return;
}

/* ParseSymbolTable__AddSymbol @ 0x97bbc480 (140 bytes) */
int ParseSymbolTable__AddSymbol(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(this + 4) == 0) {
    *(unsigned char **)this = param_2;
    iVar3 = *(int *)(this + 8);
    iVar1 = (*(uint *)(param_2 + 0x1c) -
            (*(uint *)(param_2 + 0x1c) / *(uint *)(this + 0x10)) * *(uint *)(this + 0x10)) * 4;
  }
  else {
    *(unsigned char **)(*(int *)(this + 4) + 8) = param_2;
    iVar3 = *(int *)(this + 8);
    iVar1 = (*(uint *)(param_2 + 0x1c) -
            (*(uint *)(param_2 + 0x1c) / *(uint *)(this + 0x10)) * *(uint *)(this + 0x10)) * 4;
    iVar2 = *(int *)(iVar1 + iVar3);
    if (*(int *)(iVar1 + iVar3) != 0) {
      do {
        iVar1 = iVar2;
        iVar2 = *(int *)(iVar1 + 4);
      } while (iVar2 != 0);
      *(unsigned char **)(iVar1 + 4) = param_2;
      goto LAB_97bbc4f8;
    }
  }
  *(unsigned char **)(iVar1 + iVar3) = param_2;
LAB_97bbc4f8:
  *(unsigned char **)(this + 4) = param_2;
  *(int *)(this + 0x14) = *(int *)(this + 0x14) + 1;
  return;
}

/* ParseSymbolTable__InsertSingleSymbol @ 0x97bbc50c (1504 bytes) */
int ParseSymbolTable__InsertSingleSymbol(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  bool bVar1;
  byte bVar2;
  int iVar3;
  short sVar4;
  unsigned char * p_Var5;
  int *a0;
  int iVar6;
  int *a0_00;
  uint uVar7;
  undefined4 a1;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  uint uVar8;
  undefined4 uVar9;
  uint uVar10;
  byte *pbVar11;
  uint local_40 [6];
  
  p_Var5 = (unsigned char *)GetChunkForSymbol(param_2,*(int *)(this + 0x3c));
  *(undefined4 *)(param_2 + 4) = 0;
  *(undefined4 *)(param_2 + 8) = 0;
  ((int (*)())ParseSymbolTable__AddSymbol)(this,param_2);
  *(undefined4 *)(param_2 + 0x50) = 1;
  if (*(int *)(param_2 + 0x38) == 0) {
    uVar9 = 0;
    if ((*(int *)(param_2 + 0x58) == 0) && (*(int *)(param_2 + 0x3c) == 0)) {
      a0 = *(int **)(param_2 + 0xc);
      a0_00 = (int *)0x0;
      if (a0 != (int *)0x0) {
        iVar6 = (**(code **)(*a0 + 0x24))(a0);
        if ((((iVar6 != 0) &&
             (iVar6 = (**(code **)(**(int **)(param_2 + 0xc) + 0x24))(*(int **)(param_2 + 0xc)),
             iVar6 != 9)) &&
            (iVar6 = (**(code **)(**(int **)(param_2 + 0xc) + 0x24))(*(int **)(param_2 + 0xc)),
            iVar6 != 10)) &&
           ((iVar6 = (**(code **)(**(int **)(param_2 + 0xc) + 0x24))(*(int **)(param_2 + 0xc)),
            iVar6 != 0xb &&
            (iVar6 = (**(code **)(**(int **)(param_2 + 0xc) + 0x24))(*(int **)(param_2 + 0xc)),
            iVar6 != 0xc)))) {
          uVar9 = 1;
        }
        goto LAB_97bbc61c;
      }
    }
    else {
LAB_97bbc61c:
      a0_00 = *(int **)(param_2 + 0xc);
    }
    *(undefined4 *)(param_2 + 0x38) = uVar9;
  }
  else {
    a0_00 = *(int **)(param_2 + 0xc);
  }
  iVar6 = (**(code **)(*a0_00 + 0x24))(a0_00);
  *(uint *)(param_2 + 0x60) = (uint)(iVar6 == 4);
  iVar6 = **(int **)(param_2 + 0xc);
  iVar6 = (**(code **)(iVar6 + 0x24))(*(int **)(param_2 + 0xc),a1,in_r5,in_r6,in_r7,in_r8,iVar6);
  *(uint *)(param_2 + 0x5c) = (uint)(iVar6 == 5);
  *(undefined4 *)(param_2 + 0x54) = *(undefined4 *)(this + 0x50);
  uVar7 = GetVec4sForType((uint)*(ushort *)(param_2 + 0x2c));
  ParseSymbol__SetChunk(param_2,p_Var5);
  pbVar11 = *(byte **)param_2;
  *(undefined4 *)(param_2 + 0x44) = 0;
  if (pbVar11 == (byte *)0x0) {
    return param_2;
  }
  bVar2 = *pbVar11;
  if (bVar2 == 2) {
    iVar6 = *(int *)(*(int *)(this + 0xc) + 0x18);
    goto LAB_97bbc70c;
  }
  if (bVar2 < 3) {
    if (bVar2 == 0) {
      iVar6 = *(int *)(*(int *)(this + 0xc) + 4);
      goto LAB_97bbc70c;
    }
  }
  else {
    if (bVar2 == 3) {
      iVar6 = *(int *)(*(int *)(this + 0xc) + 0x10);
      goto LAB_97bbc70c;
    }
    if (bVar2 == 4) {
      iVar6 = *(int *)(*(int *)(this + 0xc) + 0x1c);
      goto LAB_97bbc70c;
    }
  }
  iVar6 = 0;
LAB_97bbc70c:
  uVar10 = 0;
  if ((uVar7 != 0) && (iVar6 != 0)) {
    do {
      bVar1 = uVar10 != 0;
      if (bVar1) {
        pbVar11 = (byte *)_PPStreamChunkCreateFromChunk(pbVar11);
      }
      bVar2 = *pbVar11;
      if (bVar2 == 2) {
        iVar3 = *(int *)(this + 0x18);
        *(short *)(pbVar11 + 0x12) = (short)iVar3;
        *(int *)(this + 0x18) = iVar3 + 1;
        if ((*(uint *)(pbVar11 + 0xc) & 0xf0000) == 0x90000) {
          uVar8 = *(uint *)(this + 0x1c);
          *(uint *)(pbVar11 + 0xc) = uVar8 & 0x1f | *(uint *)(pbVar11 + 0xc) & 0xffffffe0;
          *(uint *)(this + 0x1c) = uVar8 + 1;
          iVar3 = GetScalerWidthForType((uint)*(ushort *)(param_2 + 0x2c));
          *(int *)(this + 0x20) = *(int *)(this + 0x20) + iVar3;
        }
      }
      else if (bVar2 < 3) {
        if (bVar2 == 0) {
          iVar3 = *(int *)(this + 0x38);
          *(short *)(pbVar11 + 0x12) = (short)iVar3;
          *(int *)(this + 0x38) = iVar3 + 1;
          if (*(int *)(param_2 + 0x60) == 0) {
            if (*(int *)(param_2 + 0x5c) != 0) {
              uVar8 = *(uint *)(this + 0x34);
              *(uint *)(pbVar11 + 0xc) = uVar8 & 0x1f | *(uint *)(pbVar11 + 0xc) & 0xffffffe0;
              *(uint *)(this + 0x34) = uVar8 + 1;
            }
          }
          else {
            uVar8 = *(uint *)(this + 0x1c);
            *(uint *)(pbVar11 + 0xc) = uVar8 & 0x1f | *(uint *)(pbVar11 + 0xc) & 0xffffffe0;
            *(uint *)(this + 0x1c) = uVar8 + 1;
            iVar3 = GetScalerWidthForType((uint)*(ushort *)(param_2 + 0x2c));
            *(int *)(this + 0x20) = *(int *)(this + 0x20) + iVar3;
          }
          if (*(int *)(this + 0x50) != 0) {
            pbVar11[0x14] = 0;
            pbVar11[0x15] = 0;
            pbVar11[0x16] = 0;
            pbVar11[0x17] = 1;
          }
        }
      }
      else if (bVar2 == 3) {
        iVar3 = *(int *)(this + 0x24);
        *(short *)(pbVar11 + 0x12) = (short)iVar3;
        *(int *)(this + 0x24) = iVar3 + 1;
        if (*(int *)(this + 0x50) != 0) {
          pbVar11[0x14] = 0;
          pbVar11[0x15] = 0;
          pbVar11[0x16] = 0;
          pbVar11[0x17] = 1;
        }
        uVar8 = *(uint *)(pbVar11 + 0xc) & 0x1f0000;
        if (uVar8 == 0x20000) {
          iVar3 = *(int *)(this + 0x2c);
          *(short *)(pbVar11 + 0xe) = (short)iVar3;
          *(int *)(this + 0x2c) = iVar3 + 1;
        }
        else if (uVar8 == 0x10000) {
          iVar3 = *(int *)(this + 0x28);
          *(short *)(pbVar11 + 0xe) = (short)iVar3;
          *(int *)(this + 0x28) = iVar3 + 1;
        }
        else if (uVar8 == 0x100000) {
          *(uint *)(pbVar11 + 0xc) = (uVar10 & 3) << 0xc | *(uint *)(pbVar11 + 0xc) & 0xffffcfff;
        }
      }
      else if (bVar2 == 4) {
        iVar3 = *(int *)(this + 0x30);
        *(short *)(pbVar11 + 0x12) = (short)iVar3;
        *(int *)(this + 0x30) = iVar3 + 1;
      }
      _PPStreamChunkListAddChunk(iVar6,pbVar11);
      iVar3 = *(int *)(this + 0x50);
      if (iVar3 == 0) {
LAB_97bbc990:
        if (1 < uVar7) {
          if (((bVar1) || (iVar3 == 0)) || (*(int *)(this + 0x40) != 0)) {
            if (((uVar10 == uVar7 - 1) && (iVar3 != 0)) && (*(int *)(this + 0x40) == 0)) {
              bVar2 = **(byte **)(this + 0x48);
              if (bVar2 != 2) {
                if (bVar2 < 3) {
                  if ((bVar2 == 0) &&
                     (iVar3 = *(int *)(*(int *)(*(int *)(this + 0xc) + 8) + 4),
                     *(short *)(iVar3 + 0x12) == 0)) {
                    sVar4 = *(short *)(this + 0x3a);
LAB_97bbcab0:
                    *(short *)(iVar3 + 0x12) = sVar4 + -1;
                  }
                }
                else if ((bVar2 == 3) &&
                        (iVar3 = *(int *)(*(int *)(*(int *)(this + 0xc) + 0x14) + 4),
                        *(short *)(iVar3 + 0x12) == 0)) {
                  sVar4 = *(short *)(this + 0x26);
                  goto LAB_97bbcab0;
                }
              }
            }
          }
          else {
            bVar2 = *pbVar11;
            if (bVar2 != 2) {
              if (bVar2 < 3) {
                if (bVar2 == 0) {
                  local_40[1] = 0;
                  local_40[0] = (uint)(ushort)(*(short *)(this + 0x3a) - 1);
                  _PPStreamAddTempUsageArray(*(undefined4 *)(this + 0xc),local_40);
                }
              }
              else if (bVar2 == 3) {
                local_40[1] = 0;
                local_40[0] = (uint)(ushort)(*(short *)(this + 0x26) - 1);
                _PPStreamAddParamBindingArray(*(undefined4 *)(this + 0xc),local_40);
              }
            }
          }
        }
      }
      else {
        uVar8 = *(uint *)(this + 0x40);
        if (((uVar8 <= *(uint *)(this + 0x44)) || (*(uint *)(this + 0x44) != 0)) || (bVar1))
        goto LAB_97bbc990;
        bVar2 = *pbVar11;
        if (bVar2 != 2) {
          if (bVar2 < 3) {
            if (bVar2 == 0) {
              local_40[1] = 0;
              local_40[0] = (uint)(ushort)(*(short *)(this + 0x3a) - 1);
              _PPStreamAddTempUsageArray(*(undefined4 *)(this + 0xc),local_40);
LAB_97bbc984:
              uVar8 = *(uint *)(this + 0x40);
            }
          }
          else if (bVar2 == 3) {
            local_40[1] = 0;
            local_40[0] = (uint)(ushort)(*(short *)(this + 0x26) - 1);
            _PPStreamAddParamBindingArray(*(undefined4 *)(this + 0xc),local_40);
            goto LAB_97bbc984;
          }
        }
        *(uint *)(this + 0x44) = uVar8;
      }
      uVar10 = uVar10 + 1;
      *(byte **)(this + 0x48) = pbVar11;
    } while (uVar10 < uVar7);
  }
  return param_2;
}

/* ParseSymbolTable__FinishArrayAddition @ 0x97bbcaec (216 bytes) */
int ParseSymbolTable__FinishArrayAddition(this)
  unsigned char * this;
{
  byte bVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(this + 0x50);
  if (((iVar3 == 0) || (*(int *)(this + 0x40) != 0)) || (*(int *)(this + 0x44) == 0)) {
    if (iVar3 != 0) {
      return;
    }
    if (*(int *)(this + 0x44) == 0) {
      return;
    }
  }
  bVar1 = **(byte **)(this + 0x48);
  if (bVar1 != 2) {
    if (bVar1 < 3) {
      if ((bVar1 != 0) ||
         (iVar4 = *(int *)(*(int *)(*(int *)(this + 0xc) + 8) + 4), *(short *)(iVar4 + 0x12) != 0))
      goto LAB_97bbcba4;
      sVar2 = *(short *)(this + 0x3a);
    }
    else {
      if ((bVar1 != 3) ||
         (iVar4 = *(int *)(*(int *)(*(int *)(this + 0xc) + 0x14) + 4), *(short *)(iVar4 + 0x12) != 0
         )) goto LAB_97bbcba4;
      sVar2 = *(short *)(this + 0x26);
    }
    *(short *)(iVar4 + 0x12) = sVar2 + -1;
    iVar3 = *(int *)(this + 0x50);
  }
LAB_97bbcba4:
  if (iVar3 == 0) {
    *(undefined4 *)(this + 0x44) = 0;
    *(undefined4 *)(this + 0x40) = 0;
    return;
  }
  *(undefined4 *)(this + 0x44) = *(undefined4 *)(this + 0x40);
  return;
}

/* ParseSymbolTable__AddTempFromOutput @ 0x97bbcbc4 (324 bytes) */
int ParseSymbolTable__AddTempFromOutput(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  ushort uVar1;
  int iVar2;
  unsigned char * this_00;
  unsigned char * p_Var3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  
  this_00 = operator_new(100);
  __ZN11ParseSymbolC1Ev(this_00);
  p_Var3 = (unsigned char *)_PPStreamChunkCreateWithType(0,0);
  ParseSymbol__operator_(this_00,param_2);
  *(undefined4 *)(this_00 + 8) = 0;
  *(undefined4 *)(this_00 + 4) = 0;
  ((int (*)())ParseSymbolTable__AddSymbol)(this,this_00);
  uVar1 = *(ushort *)(this_00 + 0x2c);
  *(undefined4 *)(this_00 + 0x50) = 1;
  uVar4 = GetVec4sForType((uint)uVar1);
  *(undefined4 *)(this_00 + 0x28) = 0xffffffff;
  *(undefined4 *)(this_00 + 0x38) = 1;
  uVar5 = GetPPStreamTypeForGLType((uint)uVar1);
  uVar9 = *(uint *)(p_Var3 + 0xc);
  uVar5 = (uVar5 & 7) << 0x1a;
  uVar8 = 0;
  *(uint *)(p_Var3 + 0xc) = uVar5 | uVar9 & 0xe3ffffff;
  iVar6 = GetScalerWidthForType((uint)*(ushort *)(this_00 + 0x2c));
  *(uint *)(p_Var3 + 0xc) = (iVar6 + -1) * 0x1000000 & 0x3000000U | uVar5 | uVar9 & 0xffffff;
  ParseSymbol__SetChunk(this_00,p_Var3);
  *(undefined4 *)(this_00 + 0x44) = 0;
  iVar6 = *(int *)this_00;
  iVar7 = *(int *)(*(int *)(this + 0xc) + 4);
  if ((uVar4 != 0) && (iVar7 != 0)) {
    do {
      if (uVar8 != 0) {
        iVar6 = _PPStreamChunkCreateFromChunk(iVar6);
      }
      iVar2 = *(int *)(this + 0x38);
      uVar8 = uVar8 + 1;
      *(short *)(iVar6 + 0x12) = (short)iVar2;
      *(int *)(this + 0x38) = iVar2 + 1;
      _PPStreamChunkListAddChunk(iVar7,iVar6);
    } while (uVar8 < uVar4);
  }
  return this_00;
}

/* ParseSymbolTable__AddFromExternalSymbol @ 0x97bbcd08 (1028 bytes) */
int ParseSymbolTable__AddFromExternalSymbol(this, param_2, param_3, param_4)
  unsigned char * this;
  unsigned char * param_2;
  int param_3;
  int param_4;
{
  byte bVar1;
  int iVar2;
  uint uVar3;
  short sVar4;
  unsigned char * this_00;
  unsigned char * p_Var5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  byte *pbVar10;
  uint local_50 [7];
  
  this_00 = operator_new(100);
  __ZN11ParseSymbolC1Ev(this_00);
  iVar7 = *(int *)param_2;
  iVar8 = 0;
  p_Var5 = (unsigned char *)_PPStreamChunkCreateFromChunk(iVar7);
  ParseSymbol__operator_(this_00,param_2);
  *(undefined4 *)(this_00 + 8) = 0;
  *(undefined4 *)(this_00 + 4) = 0;
  ((int (*)())ParseSymbolTable__AddSymbol)(this,this_00);
  *(undefined4 *)(this_00 + 0x50) = 1;
  uVar6 = GetVec4sForType((uint)*(ushort *)(this_00 + 0x2c));
  ParseSymbol__SetChunk(this_00,p_Var5);
  pbVar10 = *(byte **)this_00;
  *(undefined4 *)(this_00 + 0x44) = 0;
  if (pbVar10 != (byte *)0x0) {
    bVar1 = *pbVar10;
    if (bVar1 == 2) {
      iVar8 = *(int *)(*(int *)(this + 0xc) + 0x18);
    }
    else if (bVar1 < 3) {
      if (bVar1 == 0) {
        iVar8 = *(int *)(*(int *)(this + 0xc) + 4);
      }
    }
    else if (bVar1 == 3) {
      iVar8 = *(int *)(*(int *)(this + 0xc) + 0x10);
    }
    else if (bVar1 == 4) {
      iVar8 = *(int *)(*(int *)(this + 0xc) + 0x1c);
    }
    uVar9 = 0;
    if ((uVar6 != 0) && (iVar8 != 0)) {
      do {
        if ((uVar9 != 0) && (iVar2 = *(int *)(iVar7 + 8), iVar2 != 0)) {
          pbVar10 = (byte *)_PPStreamChunkCreateFromChunk(iVar2);
          iVar7 = iVar2;
        }
        bVar1 = *pbVar10;
        if (bVar1 == 2) {
          iVar2 = *(int *)(this + 0x18);
          *(short *)(pbVar10 + 0x12) = (short)iVar2;
          *(int *)(this + 0x18) = iVar2 + 1;
          if ((*(uint *)(pbVar10 + 0xc) & 0xf0000) == 0x90000) {
            uVar3 = *(uint *)(this + 0x1c);
            *(uint *)(pbVar10 + 0xc) = uVar3 & 0x1f | *(uint *)(pbVar10 + 0xc) & 0xffffffe0;
            *(uint *)(this + 0x1c) = uVar3 + 1;
            iVar2 = GetScalerWidthForType((uint)*(ushort *)(this_00 + 0x2c));
            *(int *)(this + 0x20) = *(int *)(this + 0x20) + iVar2;
          }
        }
        else if (bVar1 < 3) {
          if (bVar1 == 0) {
            iVar2 = *(int *)(this + 0x38);
            *(short *)(pbVar10 + 0x12) = (short)iVar2;
            *(int *)(this + 0x38) = iVar2 + 1;
            if (*(int *)(this_00 + 0x60) == 0) {
              if (*(int *)(this_00 + 0x5c) != 0) {
                uVar3 = *(uint *)(this + 0x34);
                *(uint *)(pbVar10 + 0xc) = uVar3 & 0x1f | *(uint *)(pbVar10 + 0xc) & 0xffffffe0;
                *(uint *)(this + 0x34) = uVar3 + 1;
              }
            }
            else {
              uVar3 = *(uint *)(this + 0x1c);
              *(uint *)(pbVar10 + 0xc) = uVar3 & 0x1f | *(uint *)(pbVar10 + 0xc) & 0xffffffe0;
              *(uint *)(this + 0x1c) = uVar3 + 1;
              iVar2 = GetScalerWidthForType((uint)*(ushort *)(this_00 + 0x2c));
              *(int *)(this + 0x20) = *(int *)(this + 0x20) + iVar2;
            }
            if (*(int *)(this + 0x50) != 0) {
              pbVar10[0x14] = 0;
              pbVar10[0x15] = 0;
              pbVar10[0x16] = 0;
              pbVar10[0x17] = 1;
            }
          }
        }
        else if (bVar1 == 3) {
          iVar2 = *(int *)(this + 0x24);
          *(short *)(pbVar10 + 0x12) = (short)iVar2;
          *(int *)(this + 0x24) = iVar2 + 1;
          uVar3 = *(uint *)(pbVar10 + 0xc) & 0x1f0000;
          if (uVar3 == 0x20000) {
            iVar2 = *(int *)(this + 0x2c);
            *(short *)(pbVar10 + 0xe) = (short)iVar2;
            *(int *)(this + 0x2c) = iVar2 + 1;
          }
          else if (uVar3 == 0x10000) {
            iVar2 = *(int *)(this + 0x28);
            *(short *)(pbVar10 + 0xe) = (short)iVar2;
            *(int *)(this + 0x28) = iVar2 + 1;
          }
          else if (uVar3 == 0x100000) {
            *(uint *)(pbVar10 + 0xc) = (uVar9 & 3) << 0xc | *(uint *)(pbVar10 + 0xc) & 0xffffcfff;
          }
        }
        else if (bVar1 == 4) {
          iVar2 = *(int *)(this + 0x30);
          *(short *)(pbVar10 + 0x12) = (short)iVar2;
          *(int *)(this + 0x30) = iVar2 + 1;
        }
        _PPStreamChunkListAddChunk(iVar8,pbVar10);
        if ((uVar9 == 0) && (param_3 != 0)) {
          bVar1 = *pbVar10;
          if (bVar1 != 2) {
            if (bVar1 < 3) {
              if (bVar1 == 0) {
                local_50[1] = 0;
                local_50[0] = (uint)(ushort)(*(short *)(this + 0x3a) - 1);
                _PPStreamAddTempUsageArray(*(undefined4 *)(this + 0xc),local_50);
              }
            }
            else if (bVar1 == 3) {
              local_50[1] = 0;
              local_50[0] = (uint)(ushort)(*(short *)(this + 0x26) - 1);
              _PPStreamAddParamBindingArray(*(undefined4 *)(this + 0xc),local_50);
            }
          }
        }
        if ((uVar9 == uVar6 - 1) && (param_4 != 0)) {
          bVar1 = *pbVar10;
          if (bVar1 != 2) {
            if (bVar1 < 3) {
              if ((bVar1 == 0) &&
                 (iVar2 = *(int *)(*(int *)(*(int *)(this + 0xc) + 8) + 4),
                 *(short *)(iVar2 + 0x12) == 0)) {
                sVar4 = *(short *)(this + 0x3a);
LAB_97bbd0d4:
                *(short *)(iVar2 + 0x12) = sVar4 + -1;
              }
            }
            else if ((bVar1 == 3) &&
                    (iVar2 = *(int *)(*(int *)(*(int *)(this + 0xc) + 0x14) + 4),
                    *(short *)(iVar2 + 0x12) == 0)) {
              sVar4 = *(short *)(this + 0x26);
              goto LAB_97bbd0d4;
            }
          }
        }
        uVar9 = uVar9 + 1;
      } while (uVar9 < uVar6);
    }
  }
  return this_00;
}

/* ParseSymbolTable__InsertSymbol @ 0x97bbd10c (952 bytes) */
int ParseSymbolTable__InsertSymbol(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  bool bVar1;
  undefined1 *puVar2;
  int iVar3;
  short sVar5;
  undefined4 uVar4;
  unsigned char * pPVar6;
  unsigned char * pPVar7;
  int *a0;
  int iVar8;
  undefined4 uVar9;
  uint uVar10;
  uint uVar11;
  char acStack_40 [20];
  
  puVar2 = DAT_a7b7bcfc;
  uVar9 = 0;
  if (param_2 == (unsigned char *)0x0) {
    return 0;
  }
  if ((*(int *)(this + 0x4c) != 0) || (*(int *)(param_2 + 0x24) == 0)) {
    sVar5 = *(short *)(param_2 + 0x2c);
LAB_97bbd254:
    if (sVar5 == 0x7ffe) {
      iVar3 = *(int *)(*(int *)(param_2 + 0xc) + 8);
      if (iVar3 != 0) {
        uVar11 = 0;
        uVar10 = *(int *)(iVar3 + 8) - *(int *)(iVar3 + 4) >> 3;
        if (uVar10 != 0) {
          do {
            pPVar6 = operator_new(100);
            __ZN11ParseSymbolC1ERKS_(pPVar6,param_2);
            ParseSymbol__CatName(pPVar6,".");
            a0 = *(int **)(*(int *)(iVar3 + 4) + uVar11 * 8);
            iVar8 = (**(code **)(*a0 + 0x1c))(a0);
            *(undefined1 *)(*(int *)(iVar8 + 4) + *(int *)(*(int *)(iVar8 + 4) + -0xc)) = *puVar2;
            ParseSymbol__CatName(pPVar6,*(char **)(iVar8 + 4));
            ParseSymbol__SetParseTreeType(pPVar6,*(unsigned char **)(*(int *)(iVar3 + 4) + uVar11 * 8));
            *(undefined4 *)(pPVar6 + 0x48) = 0;
            ParseSymbol__ResolveOpenGLType(pPVar6);
            uVar4 = 0;
            if ((*(int *)(param_2 + 0x3c) != 0) || (*(int *)(param_2 + 0x40) != 0)) {
              uVar4 = 1;
            }
            *(undefined4 *)(pPVar6 + 0x40) = uVar4;
            *(undefined4 *)(pPVar6 + 0x3c) = 0;
            uVar11 = uVar11 + 1;
            pPVar7 = operator_new(0x38);
            __ZN12ParseOperandC1Ev(pPVar7);
            *(unsigned char **)pPVar7 = pPVar6;
            ((int (*)())ParseSymbolTable__processOperand)(this,pPVar7);
            __ZN12ParseOperandD1Ev(pPVar7);
            __ZdlPv(pPVar7);
          } while (uVar11 < uVar10);
        }
      }
    }
    else if (sVar5 == 0x7fff) {
      uVar10 = 0;
      if (0 < *(int *)(*(int *)(param_2 + 0xc) + 4)) {
        do {
          pPVar6 = operator_new(100);
          __ZN11ParseSymbolC1ERKS_(pPVar6,param_2);
          ParseSymbol__AddDirectIndex(pPVar6,uVar10);
          _sprintf(acStack_40,"[%d]",uVar10);
          ParseSymbol__CatName(pPVar6,acStack_40);
          *(undefined4 *)(pPVar6 + 0x48) = 1;
          ParseSymbol__ResolveOpenGLType(pPVar6);
          uVar4 = 0;
          if ((*(int *)(param_2 + 0x3c) != 0) || (*(int *)(param_2 + 0x40) != 0)) {
            uVar4 = 1;
          }
          *(undefined4 *)(pPVar6 + 0x40) = uVar4;
          *(undefined4 *)(pPVar6 + 0x3c) = 0;
          pPVar7 = operator_new(0x38);
          __ZN12ParseOperandC1Ev(pPVar7);
          *(unsigned char **)pPVar7 = pPVar6;
          if (uVar10 == 0) {
            *(int *)(this + 0x40) = *(int *)(this + 0x40) + 1;
          }
          ((int (*)())ParseSymbolTable__processOperand)(this,pPVar7);
          if (uVar10 == *(int *)(*(int *)(param_2 + 0xc) + 4) - 1U) {
            *(int *)(this + 0x40) = *(int *)(this + 0x40) + -1;
            ((int (*)())ParseSymbolTable__FinishArrayAddition)(this);
          }
          if (pPVar7 != (unsigned char *)0x0) {
            __ZN12ParseOperandD1Ev(pPVar7);
            __ZdlPv(pPVar7);
          }
          uVar10 = uVar10 + 1;
        } while ((int)uVar10 < *(int *)(*(int *)(param_2 + 0xc) + 4));
      }
    }
    else {
      uVar9 = ((int (*)())ParseSymbolTable__InsertSingleSymbol)(this,param_2);
    }
    return uVar9;
  }
  sVar5 = *(short *)(param_2 + 0x2c);
  if (((sVar5 != 0x7fff) || (*(int *)(param_2 + 0x3c) != 0)) || (*(int *)(param_2 + 0x40) != 0))
  goto LAB_97bbd254;
  bVar1 = false;
  if (-1 < *(int *)(param_2 + 0x28)) {
    for (iVar3 = *(int *)this; iVar3 != 0; iVar3 = *(int *)(iVar3 + 8)) {
      if (*(int *)(param_2 + 0x28) == *(int *)(iVar3 + 0x28)) {
        bVar1 = true;
        break;
      }
    }
    if (bVar1) goto LAB_97bbd244;
  }
  *(undefined4 *)(this + 0x4c) = 1;
  pPVar6 = operator_new(100);
  __ZN11ParseSymbolC1ERKS_(pPVar6,param_2);
  ParseSymbol__TrimNameToBase(pPVar6);
  ParseSymbol__SetParseTreeType(pPVar6,*(unsigned char **)(param_2 + 0x10));
  uVar9 = 0;
  if ((*(int *)(param_2 + 0x3c) != 0) || (*(int *)(param_2 + 0x40) != 0)) {
    uVar9 = 1;
  }
  *(undefined4 *)(pPVar6 + 0x40) = uVar9;
  *(undefined4 *)(pPVar6 + 0x3c) = 0;
  pPVar7 = operator_new(0x38);
  __ZN12ParseOperandC1Ev(pPVar7);
  *(unsigned char **)pPVar7 = pPVar6;
  ((int (*)())ParseSymbolTable__processOperand)(this,pPVar7);
  __ZN12ParseOperandD1Ev(pPVar7);
  __ZdlPv(pPVar7);
LAB_97bbd244:
  *(undefined4 *)(this + 0x4c) = 0;
  return 0;
}

/* ParseSymbolTable__FindFirstElement @ 0x97bbd4c4 (624 bytes) */
int ParseSymbolTable__FindFirstElement(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  unsigned char * pPVar1;
  int iVar2;
  char *pcVar3;
  undefined4 a1;
  unsigned char * pTVar4;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  undefined4 uVar10;
  uint uVar11;
  char acStack_30 [16];
  
  uVar10 = 0;
  if (param_2 != (unsigned char *)0x0) {
    if (*(short *)(param_2 + 0x2c) == 0x7ffe) {
      iVar9 = *(int *)(*(int *)(param_2 + 0xc) + 8);
      if (iVar9 != 0) {
        pPVar1 = operator_new(100);
        __ZN11ParseSymbolC1Ev(pPVar1);
        iVar5 = *(int *)**(undefined4 **)(iVar9 + 4);
        iVar5 = (**(code **)(iVar5 + 0x1c))
                          ((int *)**(undefined4 **)(iVar9 + 4),a1,in_r5,in_r6,in_r7,in_r8,iVar5);
        *(undefined1 *)(*(int *)(iVar5 + 4) + *(int *)(*(int *)(iVar5 + 4) + -0xc)) = *DAT_a7b7bcfc;
        uVar10 = *(undefined4 *)(iVar5 + 4);
        iVar5 = _strlen(uVar10);
        iVar5 = iVar5 + 1;
        if (*(int *)(param_2 + 0x14) != 0) {
          iVar2 = _strlen(*(int *)(param_2 + 0x14));
          iVar5 = iVar5 + iVar2 + 1;
        }
        pcVar3 = (char *)_malloc(iVar5);
        if (*(int *)(param_2 + 0x14) == 0) {
          _strcpy(pcVar3,uVar10);
        }
        else {
          _sprintf(pcVar3,DAT_a7b7bbf4,*(int *)(param_2 + 0x14),uVar10);
        }
        ParseSymbol__SetName(pPVar1,pcVar3);
        iVar5 = *(int *)(param_2 + 0x3c);
        *(undefined4 *)(pPVar1 + 0x28) = *(undefined4 *)(param_2 + 0x28);
        uVar10 = 0;
        if ((iVar5 != 0) || (*(int *)(param_2 + 0x40) != 0)) {
          uVar10 = 1;
        }
        *(undefined4 *)(pPVar1 + 0x40) = uVar10;
        ParseSymbol__SetParseTreeType(pPVar1,(unsigned char *)**(undefined4 **)(iVar9 + 4));
        uVar10 = ((int (*)())ParseSymbolTable__FindFirstElement)(this,pPVar1);
        if (pPVar1 != (unsigned char *)0x0) {
          __ZN11ParseSymbolD1Ev(pPVar1);
          __ZdlPv(pPVar1);
        }
        _free(pcVar3);
      }
    }
    else if (*(short *)(param_2 + 0x2c) == 0x7fff) {
      uVar11 = 0;
      if (0 < *(int *)(*(int *)(param_2 + 0xc) + 4)) {
        do {
          pPVar1 = operator_new(100);
          __ZN11ParseSymbolC1Ev(pPVar1);
          ParseSymbol__SetName(pPVar1,*(char **)(param_2 + 0x14));
          ParseSymbol__AddDirectIndex(pPVar1,uVar11);
          _sprintf(acStack_30,DAT_a7b7bbf8,uVar11);
          ParseSymbol__CatName(pPVar1,acStack_30);
          uVar10 = *(undefined4 *)(param_2 + 0x40);
          uVar6 = *(undefined4 *)(param_2 + 0x3c);
          uVar8 = *(undefined4 *)(param_2 + 0x60);
          uVar7 = *(undefined4 *)(param_2 + 0x5c);
          pTVar4 = *(unsigned char **)(param_2 + 0xc);
          *(undefined4 *)(pPVar1 + 0x28) = *(undefined4 *)(param_2 + 0x28);
          *(undefined4 *)(pPVar1 + 0x40) = uVar10;
          *(undefined4 *)(pPVar1 + 0x3c) = uVar6;
          *(undefined4 *)(pPVar1 + 0x60) = uVar8;
          *(undefined4 *)(pPVar1 + 0x5c) = uVar7;
          ParseSymbol__SetParseTreeType(pPVar1,pTVar4);
          *(undefined4 *)(pPVar1 + 0x48) = 1;
          ParseSymbol__ResolveOpenGLType(pPVar1);
          uVar10 = ((int (*)())ParseSymbolTable__FindFirstElement)(this,pPVar1);
          if (pPVar1 != (unsigned char *)0x0) {
            __ZN11ParseSymbolD1Ev(pPVar1);
            __ZdlPv(pPVar1);
          }
          uVar11 = uVar11 + 1;
        } while ((int)uVar11 < *(int *)(*(int *)(param_2 + 0xc) + 4));
      }
    }
    else {
      uVar10 = ((int (*)())ParseSymbolTable__FindSymbol)(this,param_2);
    }
  }
  return uVar10;
}

/* ParseSymbolTable__FindSymbol @ 0x97bbd734 (120 bytes) */
int ParseSymbolTable__FindSymbol(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  int iVar1;
  unsigned char * pPVar2;
  
  pPVar2 = *(unsigned char **)
            ((*(uint *)(param_2 + 0x1c) -
             (*(uint *)(param_2 + 0x1c) / *(uint *)(this + 0x10)) * *(uint *)(this + 0x10)) * 4 +
            *(int *)(this + 8));
  while( true ) {
    if (pPVar2 == (unsigned char *)0x0) {
      return (unsigned char *)0x0;
    }
    iVar1 = __ZeqRK11ParseSymbolS1_(pPVar2,param_2);
    if (iVar1 != 0) break;
    pPVar2 = *(unsigned char **)(pPVar2 + 4);
  }
  return pPVar2;
}

/* ParseSymbolTable__NextSymbol @ 0x97bbd7ac (24 bytes) */
int ParseSymbolTable__NextSymbol(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  if (param_2 != (unsigned char *)0x0) {
    return *(undefined4 *)(param_2 + 8);
  }
  return *(undefined4 *)this;
}

/* ParseSymbolTable__NextSymbolInHash @ 0x97bbd7c4 (20 bytes) */
int ParseSymbolTable__NextSymbolInHash(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  if (param_2 == (unsigned char *)0x0) {
    return 0;
  }
  return *(undefined4 *)(param_2 + 4);
}

/* ParseSymbolTable__FirstSymbolInHash @ 0x97bbd7d8 (32 bytes) */
int ParseSymbolTable__FirstSymbolInHash(this, param_2)
  unsigned char * this;
  uint param_2;
{
  return *(undefined4 *)
          ((param_2 - (param_2 / *(uint *)(this + 0x10)) * *(uint *)(this + 0x10)) * 4 +
          *(int *)(this + 8));
}

/* ParseSymbolTable__FindGlobalSymbolByName @ 0x97bbd7f8 (244 bytes) */
int ParseSymbolTable__FindGlobalSymbolByName(this, param_2)
  unsigned char * this;
  char *param_2;
{
  unsigned char * this_00;
  int iVar1;
  unsigned char * pPVar2;
  
  if (param_2 != (char *)0x0) {
    this_00 = operator_new(100);
    __ZN11ParseSymbolC1Ev(this_00);
    if (this_00 != (unsigned char *)0x0) {
      ParseSymbol__SetName(this_00,param_2);
      for (pPVar2 = *(unsigned char **)
                     ((*(uint *)(this_00 + 0x1c) -
                      (*(uint *)(this_00 + 0x1c) / *(uint *)(this + 0x10)) * *(uint *)(this + 0x10))
                      * 4 + *(int *)(this + 8)); pPVar2 != (unsigned char *)0x0;
          pPVar2 = *(unsigned char **)(pPVar2 + 4)) {
        if ((*(int *)(pPVar2 + 0x38) != 0) &&
           (iVar1 = __ZeqRK11ParseSymbolS1_(pPVar2,this_00), iVar1 != 0)) {
          __ZN11ParseSymbolD1Ev(this_00);
          __ZdlPv(this_00);
          return pPVar2;
        }
      }
      __ZN11ParseSymbolD1Ev(this_00);
      __ZdlPv(this_00);
    }
  }
  return (unsigned char *)0x0;
}

/* ParseSymbolTable__FindSymbolByName @ 0x97bbd8ec (232 bytes) */
int ParseSymbolTable__FindSymbolByName(this, param_2)
  unsigned char * this;
  char *param_2;
{
  unsigned char * this_00;
  int iVar1;
  unsigned char * pPVar2;
  
  if (param_2 != (char *)0x0) {
    this_00 = operator_new(100);
    __ZN11ParseSymbolC1Ev(this_00);
    if (this_00 != (unsigned char *)0x0) {
      ParseSymbol__SetName(this_00,param_2);
      for (pPVar2 = *(unsigned char **)
                     ((*(uint *)(this_00 + 0x1c) -
                      (*(uint *)(this_00 + 0x1c) / *(uint *)(this + 0x10)) * *(uint *)(this + 0x10))
                      * 4 + *(int *)(this + 8)); pPVar2 != (unsigned char *)0x0;
          pPVar2 = *(unsigned char **)(pPVar2 + 4)) {
        iVar1 = __ZeqRK11ParseSymbolS1_(pPVar2,this_00);
        if (iVar1 != 0) {
          __ZN11ParseSymbolD1Ev(this_00);
          __ZdlPv(this_00);
          return pPVar2;
        }
      }
      __ZN11ParseSymbolD1Ev(this_00);
      __ZdlPv(this_00);
    }
  }
  return (unsigned char *)0x0;
}

/* ParseSymbolTable__FindNextParamSymbolByName @ 0x97bbd9d4 (192 bytes) */
int ParseSymbolTable__FindNextParamSymbolByName(this, param_2, param_3)
  unsigned char * this;
  unsigned char * param_2;
  char *param_3;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = 0;
  if (param_3 != (char *)0x0) {
    iVar1 = _strlen(param_3);
    if (param_2 == (unsigned char *)0x0) {
      iVar4 = *(int *)this;
    }
    else {
      iVar4 = *(int *)(param_2 + 8);
    }
    while ((iVar2 = 0, iVar4 != 0 &&
           (((iVar3 = *(int *)(iVar4 + 0x14), iVar3 == 0 ||
             (iVar2 = _strncmp(param_3,iVar3,iVar1), iVar2 != 0)) ||
            ((iVar2 = iVar4, *(int *)(iVar4 + 0x20) != iVar1 &&
             ((*(char *)(iVar3 + iVar1) != '.' && (*(char *)(iVar3 + iVar1) != '['))))))))) {
      iVar4 = *(int *)(iVar4 + 8);
    }
  }
  return iVar2;
}

/* ParseSymbolTable__RemoveSymbol @ 0x97bbda94 (600 bytes) */
int ParseSymbolTable__RemoveSymbol(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  byte bVar1;
  unsigned char * pPVar2;
  unsigned char * pPVar3;
  unsigned char * pPVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  byte *pbVar8;
  
  uVar7 = 0;
  uVar5 = GetVec4sForType((uint)*(ushort *)(param_2 + 0x2c));
  pbVar8 = *(byte **)param_2;
  if (uVar5 != 0) {
    do {
      bVar1 = *pbVar8;
      if (bVar1 == 2) {
LAB_97bbdb58:
        *(int *)(this + 0x18) = *(int *)(this + 0x18) + -1;
        if ((*(uint *)(pbVar8 + 0xc) & 0xf0000) == 0x90000) {
          *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + -1;
          iVar6 = GetScalerWidthForType((uint)*(ushort *)(param_2 + 0x2c));
          *(int *)(this + 0x20) = *(int *)(this + 0x20) - iVar6;
        }
      }
      else if (bVar1 < 3) {
        if (bVar1 == 0) {
          if (*(int *)(param_2 + 0x60) == 0) {
            if (*(int *)(param_2 + 0x5c) != 0) {
              *(int *)(this + 0x34) = *(int *)(this + 0x34) + -1;
            }
          }
          else {
            *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + -1;
            iVar6 = GetScalerWidthForType((uint)*(ushort *)(param_2 + 0x2c));
            *(int *)(this + 0x20) = *(int *)(this + 0x20) - iVar6;
          }
          *(int *)(this + 0x38) = *(int *)(this + 0x38) + -1;
          goto LAB_97bbdb58;
        }
      }
      else if (bVar1 == 3) {
        *(int *)(this + 0x24) = *(int *)(this + 0x24) + -1;
        if ((*(uint *)(pbVar8 + 0xc) & 0x1f0000) == 0x20000) {
          *(int *)(this + 0x2c) = *(int *)(this + 0x2c) + -1;
        }
        else if ((*(uint *)(pbVar8 + 0xc) & 0x1f0000) == 0x10000) {
          *(int *)(this + 0x28) = *(int *)(this + 0x28) + -1;
        }
      }
      else if (bVar1 == 4) {
        *(int *)(this + 0x30) = *(int *)(this + 0x30) + -1;
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < uVar5);
  }
  *(int *)(this + 0x14) = *(int *)(this + 0x14) + -1;
  pPVar2 = (unsigned char *)0x0;
  for (pPVar3 = *(unsigned char **)
                 ((*(uint *)(param_2 + 0x1c) -
                  (*(uint *)(param_2 + 0x1c) / *(uint *)(this + 0x10)) * *(uint *)(this + 0x10)) * 4
                 + *(int *)(this + 8)); pPVar3 != (unsigned char *)0x0;
      pPVar3 = *(unsigned char **)(pPVar3 + 4)) {
    if (pPVar3 == param_2) {
      if (pPVar2 == (unsigned char *)0x0) {
        *(undefined4 *)
         ((*(uint *)(param_2 + 0x1c) -
          (*(uint *)(param_2 + 0x1c) / *(uint *)(this + 0x10)) * *(uint *)(this + 0x10)) * 4 +
         *(int *)(this + 8)) = *(undefined4 *)(param_2 + 4);
      }
      else {
        *(undefined4 *)(pPVar2 + 4) = *(undefined4 *)(param_2 + 4);
      }
    }
    pPVar2 = pPVar3;
  }
  pPVar3 = *(unsigned char **)this;
  pPVar2 = (unsigned char *)0x0;
  do {
    pPVar4 = pPVar3;
    if (pPVar4 == (unsigned char *)0x0) {
LAB_97bbdcd0:
      *(undefined4 *)(param_2 + 0x50) = 0;
      return;
    }
    if (pPVar4 == param_2) {
      if (pPVar2 == (unsigned char *)0x0) {
        *(undefined4 *)this = *(undefined4 *)(param_2 + 8);
      }
      else {
        *(undefined4 *)(pPVar2 + 8) = *(undefined4 *)(param_2 + 8);
      }
      if (*(unsigned char **)(this + 4) == pPVar4) {
        *(unsigned char **)(this + 4) = pPVar2;
      }
      goto LAB_97bbdcd0;
    }
    pPVar3 = *(unsigned char **)(pPVar4 + 8);
    pPVar2 = pPVar4;
  } while( true );
}

/* ParseSymbolTable__RemoveEndSymbol @ 0x97bbdcec (704 bytes) */
int ParseSymbolTable__RemoveEndSymbol(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  byte bVar1;
  unsigned char * pPVar2;
  unsigned char * pPVar3;
  unsigned char * pPVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  byte *pbVar10;
  
  iVar8 = 1;
  uVar9 = 0;
  uVar5 = GetVec4sForType((uint)*(ushort *)(param_2 + 0x2c));
  pbVar10 = *(byte **)param_2;
  if (uVar5 != 0) {
    do {
      bVar1 = *pbVar10;
      if (bVar1 == 2) {
        if (*(int *)(this + 0x18) - 1U != (uint)*(ushort *)(pbVar10 + 0x12)) goto LAB_97bbde78;
        *(uint *)(this + 0x18) = *(int *)(this + 0x18) - 1U;
        if ((*(uint *)(pbVar10 + 0xc) & 0xf0000) == 0x90000) {
          *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + -1;
          iVar7 = GetScalerWidthForType((uint)*(ushort *)(param_2 + 0x2c));
          *(int *)(this + 0x20) = *(int *)(this + 0x20) - iVar7;
        }
      }
      else if (bVar1 < 3) {
        if (bVar1 == 0) {
          iVar7 = *(int *)(this + 0x38);
          if (iVar7 - 1U != (uint)*(ushort *)(pbVar10 + 0x12)) goto LAB_97bbde78;
          if (*(int *)(param_2 + 0x60) == 0) {
            if (*(int *)(param_2 + 0x5c) != 0) {
              *(int *)(this + 0x34) = *(int *)(this + 0x34) + -1;
            }
          }
          else {
            *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + -1;
            iVar6 = GetScalerWidthForType((uint)*(ushort *)(param_2 + 0x2c));
            *(int *)(this + 0x20) = *(int *)(this + 0x20) - iVar6;
          }
          *(int *)(this + 0x38) = iVar7 + -1;
        }
      }
      else if (bVar1 == 3) {
        if (*(int *)(this + 0x24) - 1U == (uint)*(ushort *)(pbVar10 + 0x12)) {
          *(uint *)(this + 0x24) = *(int *)(this + 0x24) - 1U;
          if ((*(uint *)(pbVar10 + 0xc) & 0x1f0000) == 0x20000) {
            *(int *)(this + 0x2c) = *(int *)(this + 0x2c) + -1;
          }
          else if ((*(uint *)(pbVar10 + 0xc) & 0x1f0000) == 0x10000) {
            *(int *)(this + 0x28) = *(int *)(this + 0x28) + -1;
          }
        }
        else {
LAB_97bbde78:
          iVar8 = 0;
        }
      }
      else if (bVar1 == 4) {
        if (*(int *)(this + 0x30) - 1U != (uint)*(ushort *)(pbVar10 + 0x12)) goto LAB_97bbde78;
        *(uint *)(this + 0x30) = *(int *)(this + 0x30) - 1U;
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 < uVar5);
    if (iVar8 == 0) {
      return 0;
    }
  }
  *(int *)(this + 0x14) = *(int *)(this + 0x14) + -1;
  pPVar2 = (unsigned char *)0x0;
  for (pPVar3 = *(unsigned char **)
                 ((*(uint *)(param_2 + 0x1c) -
                  (*(uint *)(param_2 + 0x1c) / *(uint *)(this + 0x10)) * *(uint *)(this + 0x10)) * 4
                 + *(int *)(this + 8)); pPVar3 != (unsigned char *)0x0;
      pPVar3 = *(unsigned char **)(pPVar3 + 4)) {
    iVar7 = __ZeqRK11ParseSymbolS1_(pPVar3,param_2);
    if (iVar7 != 0) {
      if (pPVar2 == (unsigned char *)0x0) {
        *(undefined4 *)
         ((*(uint *)(param_2 + 0x1c) -
          (*(uint *)(param_2 + 0x1c) / *(uint *)(this + 0x10)) * *(uint *)(this + 0x10)) * 4 +
         *(int *)(this + 8)) = *(undefined4 *)(pPVar3 + 4);
      }
      else {
        *(undefined4 *)(pPVar2 + 4) = *(undefined4 *)(pPVar3 + 4);
      }
    }
    pPVar2 = pPVar3;
  }
  pPVar3 = *(unsigned char **)this;
  pPVar2 = (unsigned char *)0x0;
  do {
    pPVar4 = pPVar3;
    if (pPVar4 == (unsigned char *)0x0) {
LAB_97bbdf8c:
      *(undefined4 *)(param_2 + 0x50) = 0;
      return iVar8;
    }
    iVar7 = __ZeqRK11ParseSymbolS1_(pPVar4,param_2);
    if (iVar7 != 0) {
      if (pPVar2 == (unsigned char *)0x0) {
        *(undefined4 *)this = *(undefined4 *)(pPVar4 + 8);
      }
      else {
        *(undefined4 *)(pPVar2 + 8) = *(undefined4 *)(pPVar4 + 8);
      }
      if (*(unsigned char **)(this + 4) == pPVar4) {
        *(unsigned char **)(this + 4) = pPVar2;
      }
      goto LAB_97bbdf8c;
    }
    pPVar3 = *(unsigned char **)(pPVar4 + 8);
    pPVar2 = pPVar4;
  } while( true );
}

/* ParseSymbolTable__CopySymbolTable @ 0x97bbdfac (228 bytes) */
int ParseSymbolTable__CopySymbolTable(this)
  unsigned char * this;
{
  undefined4 uVar1;
  unsigned char * this_00;
  unsigned char * this_01;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  unsigned char * pPVar10;
  
  this_00 = operator_new(0x54);
  ((int (*)())__ZN16ParseSymbolTableC1Ej)(this_00,0x80);
  for (pPVar10 = *(unsigned char **)this; pPVar10 != (unsigned char *)0x0;
      pPVar10 = *(unsigned char **)(pPVar10 + 8)) {
    this_01 = operator_new(100);
    __ZN11ParseSymbolC1Ev(this_01);
    ParseSymbol__operator_(this_01,pPVar10);
    ParseSymbol__SetChunk(this_01,*(unsigned char **)pPVar10);
    *(undefined4 *)(this_01 + 0x44) = 0;
    ((int (*)())ParseSymbolTable__AddSymbol)(this_00,this_01);
  }
  uVar2 = *(undefined4 *)(this + 0x3c);
  uVar1 = *(undefined4 *)(this + 0x1c);
  uVar7 = *(undefined4 *)(this + 0x20);
  uVar9 = *(undefined4 *)(this + 0x24);
  uVar8 = *(undefined4 *)(this + 0x28);
  uVar6 = *(undefined4 *)(this + 0x2c);
  uVar5 = *(undefined4 *)(this + 0x30);
  uVar4 = *(undefined4 *)(this + 0x34);
  uVar3 = *(undefined4 *)(this + 0x38);
  *(undefined4 *)(this_00 + 0x18) = *(undefined4 *)(this + 0x18);
  *(undefined4 *)(this_00 + 0x1c) = uVar1;
  *(undefined4 *)(this_00 + 0x20) = uVar7;
  *(undefined4 *)(this_00 + 0x24) = uVar9;
  *(undefined4 *)(this_00 + 0x28) = uVar8;
  *(undefined4 *)(this_00 + 0x2c) = uVar6;
  *(undefined4 *)(this_00 + 0x30) = uVar5;
  *(undefined4 *)(this_00 + 0x34) = uVar4;
  *(undefined4 *)(this_00 + 0x38) = uVar3;
  *(undefined4 *)(this_00 + 0x3c) = uVar2;
  return this_00;
}

/* ParseSymbolTable__ChangeChunk @ 0x97bbe090 (128 bytes) */
int ParseSymbolTable__ChangeChunk(this, param_2, param_3, param_4)
  unsigned char * this;
  unsigned char * param_2;
  unsigned char * param_3;
  int param_4;
{
  unsigned char * this_00;
  
  this_00 = *(unsigned char **)this;
  if (this_00 != (unsigned char *)0x0) {
    do {
      if (*(unsigned char **)this_00 == param_2) {
        ParseSymbol__SetChunk(this_00,param_3);
        if (param_4 != 0) {
          *(undefined4 *)(this_00 + 0x44) = 0;
        }
        return 1;
      }
      this_00 = *(unsigned char **)(this_00 + 8);
    } while (this_00 != (unsigned char *)0x0);
  }
  return 0;
}

/* ParseSymbolTable__ClearCompilerTempData @ 0x97bbe110 (40 bytes) */
int ParseSymbolTable__ClearCompilerTempData(this)
  unsigned char * this;
{
  int iVar1;
  
  iVar1 = *(int *)this;
  if (iVar1 != 0) {
    do {
      *(undefined4 *)(iVar1 + 0xc) = 0;
      *(undefined4 *)(iVar1 + 0x10) = 0;
      iVar1 = *(int *)(iVar1 + 8);
    } while (iVar1 != 0);
    return;
  }
  return;
}

/* ParseSymbolTable__Dump @ 0x97bbe138 (84 bytes) */
int ParseSymbolTable__Dump(this)
  unsigned char * this;
{
  undefined *puVar1;
  int iVar2;
  
  puVar1 = PTR_DAT_a7b7c0bc;
  for (iVar2 = *(int *)this; iVar2 != 0; iVar2 = *(int *)(iVar2 + 8)) {
    _fflush(puVar1 + 0x58);
  }
  return;
}

/* ParseSymbolTable__GetString @ 0x97bbe18c (992 bytes) */
int ParseSymbolTable__GetString(this, param_2)
  unsigned char * this;
  int param_2;
{
  uint uVar1;
  unsigned char * pPVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  undefined4 uVar7;
  uint uVar8;
  char cVar9;
  int iVar10;
  uint uVar11;
  
  pPVar2 = (unsigned char *)((int (*)())ParseSymbolTable__NextSymbol)(this,(unsigned char *)0x0);
  pcVar3 = (char *)_malloc(0x800);
  uVar8 = 0x800;
  iVar10 = 0;
  cVar9 = '\x02';
  pcVar6 = (char *)0x0;
  if (pcVar3 != (char *)0x0) {
    *pcVar3 = '\0';
    pcVar6 = pcVar3;
    if (param_2 == 1) {
      uVar11 = *(uint *)(this + 0x10);
      uVar1 = 0;
      if (uVar11 != 0) {
        do {
          pPVar2 = (unsigned char *)((int (*)())ParseSymbolTable__FirstSymbolInHash)(this,uVar1);
          if (pPVar2 != (unsigned char *)0x0) {
            _sprintf(pcVar6,DAT_a7b7bc08,pcVar6,uVar1);
            iVar10 = _strlen(pcVar6);
            pcVar3 = pcVar6;
            do {
              iVar4 = ParseSymbol__GetString(pPVar2,1);
              pcVar6 = pcVar3;
              if (iVar4 != 0) {
                iVar5 = _strlen(iVar4);
                iVar5 = iVar5 + iVar10;
                uVar11 = iVar5 + 1;
                if (uVar8 < uVar11) {
                  uVar8 = 0x800;
                  if (0x800 < uVar11 >> 2) {
                    uVar8 = uVar11 >> 2;
                  }
                  uVar8 = uVar11 + uVar8;
                  pcVar6 = (char *)_malloc(uVar8);
                  if (pcVar6 == (char *)0x0) goto LAB_97bbe3d4;
                  _memmove(pcVar6,pcVar3,iVar10 + 1);
                  _free(pcVar3);
                }
                iVar10 = iVar5 + 1;
                _strcat(pcVar6,iVar4);
                pcVar6[iVar5] = '\n';
                pcVar6[iVar10] = '\0';
                _free(iVar4);
              }
              pPVar2 = (unsigned char *)((int (*)())ParseSymbolTable__NextSymbolInHash)(this,pPVar2);
              pcVar3 = pcVar6;
            } while (pPVar2 != (unsigned char *)0x0);
            _strcat(pcVar6,DAT_a7b7bc0c);
            uVar11 = *(uint *)(this + 0x10);
          }
          uVar1 = uVar1 + 1;
        } while (uVar1 < uVar11);
      }
    }
    else if (param_2 < 2) {
      if (param_2 == 0) {
        while (pcVar6 = pcVar3, pPVar2 != (unsigned char *)0x0) {
          iVar4 = ParseSymbol__GetString(pPVar2,1);
          if (iVar4 != 0) {
            iVar5 = _strlen(iVar4);
            iVar5 = iVar5 + iVar10;
            uVar1 = iVar5 + 1;
            if (uVar8 < uVar1) {
              uVar8 = 0x800;
              if (0x800 < uVar1 >> 2) {
                uVar8 = uVar1 >> 2;
              }
              uVar8 = uVar1 + uVar8;
              pcVar6 = (char *)_malloc(uVar8);
              if (pcVar6 == (char *)0x0) {
LAB_97bbe3d4:
                _free(pcVar3);
                _free(iVar4);
                return (char *)0x0;
              }
              _memmove(pcVar6,pcVar3,iVar10 + 1);
              _free(pcVar3);
            }
            iVar10 = iVar5 + 1;
            _strcat(pcVar6,iVar4);
            pcVar6[iVar5] = '\n';
            pcVar6[iVar10] = '\0';
            _free(iVar4);
          }
          pPVar2 = (unsigned char *)((int (*)())ParseSymbolTable__NextSymbol)(this,pPVar2);
          pcVar3 = pcVar6;
        }
      }
    }
    else if (param_2 == 2) {
      _sprintf(pcVar3,DAT_a7b7bc10);
      iVar10 = _strlen(pcVar3);
      do {
        while( true ) {
          pPVar2 = (unsigned char *)((int (*)())ParseSymbolTable__NextSymbol)(this,(unsigned char *)0x0);
          while (pPVar2 != (unsigned char *)0x0) {
            pcVar6 = pcVar3;
            if ((**(char **)pPVar2 == cVar9) &&
               (iVar4 = ParseSymbol__GetString(pPVar2,0), iVar4 != 0)) {
              iVar5 = _strlen(iVar4);
              iVar5 = iVar5 + iVar10;
              uVar1 = iVar5 + 2;
              if (uVar8 < uVar1) {
                uVar8 = 0x800;
                if (0x800 < uVar1 >> 2) {
                  uVar8 = uVar1 >> 2;
                }
                uVar8 = uVar1 + uVar8;
                pcVar6 = (char *)_malloc(uVar8);
                if (pcVar6 == (char *)0x0) goto LAB_97bbe3d4;
                _memmove(pcVar6,pcVar3,iVar10 + 1);
                _free(pcVar3);
              }
              iVar10 = iVar5 + 1;
              _strcat(pcVar6,iVar4);
              pcVar6[iVar5] = '\n';
              pcVar6[iVar10] = '\0';
              _free(iVar4);
            }
            pPVar2 = (unsigned char *)((int (*)())ParseSymbolTable__NextSymbol)(this,pPVar2);
            pcVar3 = pcVar6;
          }
          if (cVar9 != '\x02') break;
          cVar9 = '\x03';
          _strcat(pcVar3,DAT_a7b7bc14);
          uVar7 = DAT_a7b7bc14;
LAB_97bbe53c:
          iVar4 = _strlen(uVar7);
          iVar10 = iVar10 + iVar4;
        }
        if (cVar9 == '\x03') {
          cVar9 = '\x04';
          _strcat(pcVar3,DAT_a7b7bc18);
          uVar7 = DAT_a7b7bc18;
          goto LAB_97bbe53c;
        }
        if (cVar9 == '\x04') {
          cVar9 = '\0';
          _strcat(pcVar3,DAT_a7b7bc1c);
          uVar7 = DAT_a7b7bc1c;
          goto LAB_97bbe53c;
        }
        pcVar6 = pcVar3;
      } while (cVar9 != '\0');
    }
  }
  return pcVar6;
}

/* TIntermSymbol__compileNode @ 0x97bbe56c (304 bytes) */
int TIntermSymbol__compileNode(this, param_2, param_3, param_4, param_5, param_6)
  unsigned char * this;
  unsigned char * param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  undefined1 *puVar1;
  int iVar2;
  undefined4 uVar3;
  unsigned char * this_00;
  unsigned char * pTVar4;
  undefined4 a1;
  int a6;
  undefined4 *this_01;
  
  this_01 = (undefined4 *)0x0;
  iVar2 = (**(code **)(*(int *)this + 0x60))(this);
  puVar1 = DAT_a7b7bd04;
  a6 = *(int *)(iVar2 + 4);
  *(undefined1 *)(a6 + *(int *)(a6 + -0xc)) = *DAT_a7b7bd04;
  if (*(int *)(iVar2 + 4) != 0) {
    uVar3 = (*(code *)**(undefined4 **)this)(this,a1,param_3,param_4,param_5,param_6,a6);
    *(undefined4 *)(param_2 + 0x90) = uVar3;
    this_00 = operator_new(100);
    __ZN11ParseSymbolC1Ev(this_00);
    iVar2 = (**(code **)(*(int *)this + 0x60))(this);
    *(undefined1 *)(*(int *)(iVar2 + 4) + *(int *)(*(int *)(iVar2 + 4) + -0xc)) = *puVar1;
    ParseSymbol__SetName(this_00,*(char **)(iVar2 + 4));
    uVar3 = (**(code **)(*(int *)this + 0x5c))(this);
    *(undefined4 *)(this_00 + 0x28) = uVar3;
    pTVar4 = (unsigned char *)(**(code **)(*(int *)this + 0x3c))(this);
    ParseSymbol__SetParseTreeType(this_00,pTVar4);
    uVar3 = (**(code **)(*(int *)this + 0x3c))(this);
    *(undefined4 *)(this_00 + 0x10) = uVar3;
    this_01 = operator_new(0x38);
    __ZN12ParseOperandC1Ev(this_01);
    *this_01 = this_00;
  }
  return this_01;
}

/* TIntermConstantUnion__compileNode @ 0x97bbe69c (340 bytes) */
int TIntermConstantUnion__compileNode(this, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  unsigned char * this;
  unsigned char * param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  int iVar1;
  uint uVar2;
  undefined2 uVar3;
  void *this_00;
  undefined4 uVar4;
  undefined **local_50 [9];
  uint local_2c;
  
  this_00 = operator_new(0x38);
  __ZN12ParseOperandC1Ev(this_00);
  uVar4 = (*(code *)**(undefined4 **)this)(this);
  *(undefined4 *)(param_2 + 0x90) = uVar4;
  (**(code **)(*(int *)this + 0x38))(local_50,this);
  if ((local_2c & 0x400) == 0) {
    iVar1 = (int)(local_2c << 0xd | local_2c >> 0x13) >> 0x18;
  }
  else {
    iVar1 = (int)(local_2c << 0xd | local_2c >> 0x13) >> 0x18;
    iVar1 = iVar1 * iVar1;
  }
  *(int *)((int)this_00 + 0x24) = iVar1;
  local_50[0] = &PTR___ZN5TTypeD1Ev_a7b7d730;
  *(undefined4 *)((int)this_00 + 4) = *(undefined4 *)(this + 0x30);
  (**(code **)(*(int *)this + 0x38))(local_50,this);
  local_50[0] = &PTR___ZN5TTypeD1Ev_a7b7d730;
  uVar2 = local_2c >> 0x13 & 0x3f;
  if (uVar2 == 2) {
    uVar3 = 0x1404;
LAB_97bbe7a0:
    *(undefined2 *)((int)this_00 + 0x18) = uVar3;
  }
  else {
    if (uVar2 < 3) {
      if (uVar2 == 1) {
        uVar3 = 0x1406;
        goto LAB_97bbe7a0;
      }
    }
    else {
      if (uVar2 == 3) {
        uVar3 = 0x8b56;
        goto LAB_97bbe7a0;
      }
      if (uVar2 == 0xe) {
        TPPStreamCompiler__error
                  (param_2,(char *)0x1,(char *)0x0,
                   "TIntermConstantUnion::compileNode: EbtStruct constant union type, investigate",
                   param_5,param_6,param_7,param_8);
      }
    }
    TPPStreamCompiler__error
              (param_2,(char *)0x1,(char *)0x0,
               "TIntermConstantUnion::compileNode: Unexpected constant union type",param_5,param_6,
               param_7,param_8);
  }
  return this_00;
}

/* TIntermBinary__compileNode @ 0x97bbe7f0 (3444 bytes) */
int TIntermBinary__compileNode(this, param_2, param_3, param_4, param_5, param_6)
  unsigned char * this;
  unsigned char * param_2;
  undefined4 param_3;
  char *param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  ushort uVar1;
  unsigned char * pPVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  unsigned char * pTVar7;
  unsigned char * pPVar8;
  unsigned char * pPVar9;
  undefined1 uVar13;
  int iVar10;
  int iVar11;
  void *pvVar12;
  undefined4 a1;
  undefined4 a1_00;
  undefined4 a1_01;
  undefined4 a1_02;
  uchar uVar14;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  unsigned char ** ppPVar15;
  undefined4 *puVar16;
  uint *a6;
  undefined4 uVar17;
  uint uVar18;
  int iVar19;
  undefined8 uVar20;
  uint local_c0;
  uint local_bc;
  uint local_b8;
  undefined4 local_b4;
  uint local_b0;
  undefined4 local_ac;
  uint local_a8;
  undefined4 local_a4;
  uint local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  uint local_80;
  undefined4 local_7c;
  undefined **local_70 [2];
  int local_68;
  int local_40;
  unsigned char * local_3c;
  unsigned char * local_38;
  unsigned char * local_34;
  unsigned char * local_30 [6];
  
  uVar17 = 0;
  local_98 = 0;
  local_94 = 0;
  local_c0 = 0;
  local_bc = 0;
  local_b8 = 0;
  local_b4 = 0;
  local_b0 = 0;
  local_ac = 0;
  local_a8 = 0;
  local_a4 = 0;
  local_a0 = 0;
  local_9c = 0;
  local_8c = 0;
  local_30[0] = (unsigned char *)0x0;
  local_38 = (unsigned char *)0x0;
  local_34 = (unsigned char *)0x0;
  local_90 = 0;
  local_90 = (*(code *)**(undefined4 **)this)(this);
  puVar16 = *(undefined4 **)this;
  local_c0 = local_c0 & 0x1fffffff | 0x40000000;
  uVar4 = (*(code *)*puVar16)(this,a1,param_3,param_4,param_5,param_6,puVar16);
  *(undefined4 *)(param_2 + 0x90) = uVar4;
  piVar5 = *(int **)(this + 0x34);
  if (piVar5 != (int *)0x0) {
    local_38 = (unsigned char *)(**(code **)(*piVar5 + 0xc))(piVar5,param_2);
    iVar3 = *(int *)(this + 0x30);
    if (((iVar3 != 0x2d) && (iVar3 != 0x2e)) && (iVar3 != 0x2f)) {
      ((int (*)())ParseSymbolTable__processOperand)(*(unsigned char **)(param_2 + 0x68),local_38);
    }
  }
  piVar5 = *(int **)(this + 0x38);
  if (piVar5 != (int *)0x0) {
    local_34 = (unsigned char *)(**(code **)(*piVar5 + 0xc))(piVar5,param_2);
    ((int (*)())ParseSymbolTable__processOperand)(*(unsigned char **)(param_2 + 0x68),local_34);
  }
  iVar3 = *(int *)(this + 0x30);
  if (iVar3 == 0x2d) {
    ((int (*)())ParseSymbolTable__processOperand)(*(unsigned char **)(param_2 + 0x68),local_34);
    a6 = *(uint **)(local_34 + 4);
    uVar18 = *a6;
    piVar5 = (int *)(**(code **)(**(int **)(this + 0x34) + 0x3c))
                              (*(int **)(this + 0x34),a1_00,param_3,param_4,iVar3,param_6,a6);
    iVar6 = (**(code **)(*piVar5 + 0x38))(piVar5);
    if (iVar6 == 0) {
      ParseOperand__AddDirectIndex(local_38,uVar18);
    }
    else {
      ParseSymbol__AddDirectIndex(*(unsigned char **)local_38,uVar18);
      _sprintf((char *)&local_80,"[%d]",uVar18);
      ParseSymbol__CatName(*(unsigned char **)local_38,(char *)&local_80);
      iVar6 = (**(code **)(*(int *)this + 0x54))(this);
      if (iVar6 == 0) {
        uVar4 = 1;
LAB_97bbf03c:
        pPVar9 = *(unsigned char **)local_38;
        *(undefined4 *)(pPVar9 + 0x48) = uVar4;
        ParseSymbol__ResolveOpenGLType(pPVar9);
      }
      else {
        TPPStreamCompiler__error
                  (param_2,(char *)0x1,(char *)0x0,
                   "TIntermBinary::compileNode: Array index results in another array, this is not handled"
                   ,iVar3,param_6,a6,uVar17);
      }
    }
LAB_97bbf04c:
    local_30[0] = local_38;
    goto LAB_97bbf4fc;
  }
  if (iVar3 == 0x2e) {
    if (*(int *)local_38 == 0) {
      pTVar7 = (unsigned char *)(**(code **)(**(int **)(this + 0x34) + 0x3c))(*(int **)(this + 0x34));
      pPVar8 = (unsigned char *)
               TPPStreamCompiler__newIndirectOperandFromConstant(param_2,local_38,pTVar7);
      pPVar2 = local_38;
      if (local_38 != (unsigned char *)0x0) {
        __ZN12ParseOperandD1Ev(local_38);
        __ZdlPv(pPVar2);
      }
    }
    else {
      piVar5 = (int *)(**(code **)(**(int **)(this + 0x34) + 0x3c))(*(int **)(this + 0x34));
      iVar6 = (**(code **)(*piVar5 + 0x38))(piVar5);
      pPVar8 = local_38;
      if (iVar6 != 0) {
        _sprintf((char *)&local_80,"[%d]",0);
        ParseSymbol__CatName(*(unsigned char **)local_38,(char *)&local_80);
        iVar6 = (**(code **)(*(int *)this + 0x54))(this);
        if (iVar6 == 0) {
          pPVar9 = *(unsigned char **)local_38;
          *(undefined4 *)(pPVar9 + 0x48) = 1;
          ParseSymbol__ResolveOpenGLType(pPVar9);
          pPVar8 = local_38;
        }
        else {
          param_4 = 
          "TIntermBinary::compileNode: Array index results in another array, this is not handled";
          TPPStreamCompiler__error
                    (param_2,(char *)0x1,(char *)0x0,
                     "TIntermBinary::compileNode: Array index results in another array, this is not handled"
                     ,iVar3,param_6,puVar16,uVar17);
          pPVar8 = local_38;
        }
      }
    }
    local_38 = pPVar8;
    piVar5 = (int *)(**(code **)(**(int **)(this + 0x34) + 0x3c))(*(int **)(this + 0x34));
    iVar6 = (**(code **)(*piVar5 + 0x38))(piVar5);
    if (iVar6 == 0) {
      ParseOperand__AddDirectIndex(local_38,0);
    }
    else {
      ParseSymbol__AddDirectIndex(*(unsigned char **)local_38,0);
    }
    ((int (*)())ParseSymbolTable__processOperand)(*(unsigned char **)(param_2 + 0x68),local_38);
    piVar5 = (int *)(**(code **)(**(int **)(this + 0x34) + 0x3c))(*(int **)(this + 0x34));
    iVar6 = (**(code **)(*piVar5 + 0x38))(piVar5);
    if (iVar6 == 0) {
      piVar5 = (int *)(**(code **)(**(int **)(this + 0x34) + 0x3c))(*(int **)(this + 0x34));
      iVar6 = (**(code **)(*piVar5 + 0x34))(piVar5);
      if (iVar6 == 0) {
        *(unsigned char **)(local_38 + 0xc) = local_34;
        local_34 = (unsigned char *)0x0;
        goto LAB_97bbf04c;
      }
    }
    piVar5 = (int *)(**(code **)(**(int **)(this + 0x34) + 0x3c))(*(int **)(this + 0x34));
    iVar6 = (**(code **)(*piVar5 + 0x38))(piVar5);
    if (iVar6 == 0) {
      local_40 = 1;
    }
    else {
      local_40 = TPPStreamCompiler__getArrayOffset(param_2,local_38);
    }
    local_30[0] = local_38;
    local_3c = *(unsigned char **)(local_38 + 8);
    if (local_3c == (unsigned char *)0x0) {
      local_3c = (unsigned char *)TPPStreamCompiler__newAddressTemp(param_2);
      if (local_40 < 2) {
        local_c0 = local_c0 & 0x3c03ffff | 0x20000000;
        TPPStreamCompiler__getOperandAsDestVar
                  ((unsigned char *)&local_80,param_2,local_3c,param_4,iVar3,param_6);
        local_b8 = local_80;
        local_b4 = local_7c;
        TPPStreamCompiler__getOperandAsSourceVar
                  ((unsigned char *)&local_80,param_2,local_34,param_4,iVar3,param_6,puVar16,uVar17);
        local_bc = (local_b8 >> 0xc & 1) << 0x1c | local_bc & 0xefffffff;
        local_b0 = local_80;
        local_ac = local_7c;
      }
      else {
        local_c0 = local_c0 & 0xfc03ffff | 0x880000;
        TPPStreamCompiler__getOperandAsDestVar
                  ((unsigned char *)&local_80,param_2,local_3c,param_4,iVar3,param_6);
        local_b8 = local_80;
        local_b4 = local_7c;
        TPPStreamCompiler__getOperandAsSourceVar
                  ((unsigned char *)&local_80,param_2,local_34,param_4,iVar3,param_6,puVar16,uVar17);
        local_b0 = local_80;
        local_ac = local_7c;
        if (*(int *)local_3c == 0) {
          uVar1 = *(ushort *)(local_3c + 0x18);
        }
        else {
          uVar1 = *(ushort *)(*(int *)local_3c + 0x2c);
        }
        TPPStreamCompiler__getConstantAsSourceVar
                  ((unsigned char *)&local_80,(uint)param_2,&local_40,1,(uint)uVar1);
        local_bc = (local_b8 >> 0xc & 1) << 0x1c | local_bc & 0xefffffff;
        local_a8 = local_80;
        local_a4 = local_7c;
      }
      if (*(int *)local_3c == 0) {
        uVar1 = *(ushort *)(local_3c + 0x18);
      }
      else {
        uVar1 = *(ushort *)(*(int *)local_3c + 0x2c);
      }
      uVar18 = GetPPStreamTypeForGLType((uint)uVar1);
      local_bc = (uVar18 & 7) << 0x17 | local_bc & 0xfc7fffff;
      iVar3 = ParseOperand__GetLogicalSize(local_3c);
      local_bc = (iVar3 + -1) * 0x4000000 & 0xc000000U | local_bc & 0xf3ffffff;
      TPPStreamCompiler__AddOperation
                (param_2,&local_3c,(unsigned char *)&local_c0,(char *)0x0,0);
      *(unsigned char **)(local_30[0] + 8) = local_3c;
      goto LAB_97bbf4fc;
    }
    if (local_40 < 2) {
      local_c0 = local_c0 & 0xfc03ffff | 0x7c0000;
      TPPStreamCompiler__getOperandAsDestVar
                ((unsigned char *)&local_80,param_2,local_3c,param_4,iVar3,param_6);
      local_b8 = local_80;
      local_b4 = local_7c;
      TPPStreamCompiler__getOperandAsSourceVar
                ((unsigned char *)&local_80,param_2,local_34,param_4,iVar3,param_6,puVar16,uVar17);
      local_b0 = local_80;
      local_ac = local_7c;
      TPPStreamCompiler__getOperandAsSourceVar
                ((unsigned char *)&local_80,param_2,local_3c,param_4,iVar3,param_6,puVar16,uVar17);
      local_bc = (local_b8 >> 0xc & 1) << 0x1c | local_bc & 0xefffffff;
      local_a8 = local_80;
      local_a4 = local_7c;
    }
    else {
      local_c0 = local_c0 & 0x7c03ffff | 0x60fc0000;
      TPPStreamCompiler__getOperandAsDestVar
                ((unsigned char *)&local_80,param_2,local_3c,param_4,iVar3,param_6);
      local_b8 = local_80;
      local_b4 = local_7c;
      TPPStreamCompiler__getOperandAsSourceVar
                ((unsigned char *)&local_80,param_2,local_34,param_4,iVar3,param_6,puVar16,uVar17);
      local_b0 = local_80;
      local_ac = local_7c;
      if (*(int *)local_3c == 0) {
        uVar1 = *(ushort *)(local_3c + 0x18);
      }
      else {
        uVar1 = *(ushort *)(*(int *)local_3c + 0x2c);
      }
      uVar18 = (uint)uVar1;
      uVar4 = 1;
      pPVar8 = local_3c;
      TPPStreamCompiler__getConstantAsSourceVar
                ((unsigned char *)&local_80,(uint)param_2,&local_40,1,uVar18);
      local_a8 = local_80;
      local_a4 = local_7c;
      TPPStreamCompiler__getOperandAsSourceVar
                ((unsigned char *)&local_80,param_2,local_3c,uVar4,uVar18,param_6,pPVar8,uVar17);
      local_bc = (local_b8 >> 0xc & 1) << 0x1c | local_bc & 0xefffffff;
      local_a0 = local_80;
      local_9c = local_7c;
    }
    if (*(int *)local_3c == 0) {
      uVar1 = *(ushort *)(local_3c + 0x18);
    }
    else {
      uVar1 = *(ushort *)(*(int *)local_3c + 0x2c);
    }
    uVar18 = GetPPStreamTypeForGLType((uint)uVar1);
    local_bc = (uVar18 & 7) << 0x17 | local_bc & 0xfc7fffff;
    iVar3 = ParseOperand__GetLogicalSize(local_3c);
    local_bc = (iVar3 + -1) * 0x4000000 & 0xc000000U | local_bc & 0xf3ffffff;
    ppPVar15 = &local_3c;
  }
  else {
    if (iVar3 == 0x2f) {
      pPVar9 = *(unsigned char **)local_38;
      (**(code **)(**(int **)(this + 0x34) + 0x38))(local_70,*(int **)(this + 0x34));
      local_70[0] = &PTR___ZN5TTypeD1Ev_a7b7d730;
      ((int (*)())ParseSymbolTable__processOperand)(*(unsigned char **)(param_2 + 0x68),local_34);
      iVar19 = **(int **)(local_34 + 4);
      ParseSymbol__CatName(pPVar9,".");
      piVar5 = *(int **)(*(int *)(local_68 + 4) + iVar19 * 8);
      iVar6 = *piVar5;
      iVar3 = (**(code **)(iVar6 + 0x1c))(piVar5,a1_01,param_3,param_4,iVar3,param_6,iVar6);
      *(undefined1 *)(*(int *)(iVar3 + 4) + *(int *)(*(int *)(iVar3 + 4) + -0xc)) = *DAT_a7b7bd04;
      ParseSymbol__CatName(pPVar9,*(char **)(iVar3 + 4));
      ParseSymbol__SetParseTreeType(pPVar9,*(unsigned char **)(*(int *)(local_68 + 4) + iVar19 * 8));
      uVar4 = 0;
      goto LAB_97bbf03c;
    }
    if (iVar3 == 0x30) {
      iVar6 = 0;
      local_30[0] = local_38;
      iVar19 = *(int *)(local_38 + 0x14);
      if (iVar19 != 0) {
        uVar18 = 0;
        iVar6 = _malloc(iVar19);
        if (0 < iVar19) {
          do {
            uVar13 = ((int (*)())ParseOperand__GetSwizzle)(local_30[0],uVar18);
            *(undefined1 *)(iVar6 + uVar18) = uVar13;
            uVar18 = uVar18 + 1;
          } while ((int)uVar18 < iVar19);
        }
        ((int (*)())ParseOperand__ClearSwizzles)(local_30[0]);
      }
      iVar10 = (**(code **)(**(int **)(this + 0x38) + 0x1c))(*(int **)(this + 0x38));
      if (iVar10 == 0) {
        TPPStreamCompiler__error
                  (param_2,(char *)0x1,*(char **)(*(int *)local_38 + 0x14),
                   "Right hand child of vector swizzle is not an aggregate node.",iVar3,param_6,
                   *(int *)local_38,uVar17);
      }
      else {
        piVar5 = (int *)(**(code **)(**(int **)(this + 0x38) + 0x1c))(*(int **)(this + 0x38));
        iVar10 = (**(code **)(*piVar5 + 100))(piVar5);
        for (puVar16 = *(undefined4 **)(iVar10 + 4); puVar16 != *(undefined4 **)(iVar10 + 8);
            puVar16 = puVar16 + 1) {
          piVar5 = (int *)(**(code **)(*(int *)*puVar16 + 0x14))((int *)*puVar16);
          iVar11 = (**(code **)(*piVar5 + 0x18))(piVar5);
          if (iVar11 == 0) {
            TPPStreamCompiler__error
                      (param_2,(char *)0x1,*(char **)(*(int *)local_38 + 0x14),
                       "Unexpected non-constant in vector swizzle.",iVar3,param_6,*(int *)local_38,
                       uVar17);
          }
          else {
            if (iVar19 == 0) {
              piVar5 = (int *)(**(code **)(*(int *)*puVar16 + 0x14))((int *)*puVar16,a1_02);
              iVar11 = (**(code **)(*piVar5 + 0x18))(piVar5);
              uVar14 = *(uchar *)(*(int *)(iVar11 + 0x30) + 3);
            }
            else {
              piVar5 = (int *)(**(code **)(*(int *)*puVar16 + 0x14))((int *)*puVar16);
              iVar11 = (**(code **)(*piVar5 + 0x18))(piVar5);
              uVar14 = *(uchar *)(iVar6 + **(int **)(iVar11 + 0x30));
            }
            ParseOperand__AddSwizzle(local_30[0],uVar14);
          }
        }
      }
      goto LAB_97bbf4fc;
    }
    if (iVar3 < 0x31) {
      if (iVar3 - 0x1dU < 2) {
        pTVar7 = (unsigned char *)(**(code **)(*(int *)this + 0x3c))(this);
        pPVar8 = (unsigned char *)&local_38;
        ppPVar15 = &local_34;
        uVar20 = TPPStreamCompiler__equalOperands
                           (param_2,pTVar7,(unsigned char **)pPVar8,ppPVar15,(uint)(iVar3 == 0x1d));
      }
      else {
LAB_97bbf334:
        pTVar7 = (unsigned char *)(**(code **)(*(int *)this + 0x3c))(this);
        local_30[0] = (unsigned char *)TPPStreamCompiler__newTemporary(param_2,pTVar7);
        ppPVar15 = &local_34;
        __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_S2_
                  (param_2,local_30,&local_38,ppPVar15);
LAB_97bbf370:
        TPPStreamCompiler__getOperandAsSourceVar
                  ((unsigned char *)&local_80,param_2,local_38,ppPVar15,iVar3,param_6,puVar16,uVar17)
        ;
        local_b0 = local_80;
        local_ac = local_7c;
        TPPStreamCompiler__getOperandAsSourceVar
                  ((unsigned char *)&local_80,param_2,local_34,ppPVar15,iVar3,param_6,puVar16,uVar17)
        ;
        local_a8 = local_80;
        local_a4 = local_7c;
        pPVar8 = local_30;
        TPPStreamCompiler__getOperandAsDestVar
                  ((unsigned char *)&local_80,param_2,local_30[0],ppPVar15,iVar3,param_6);
        uVar20 = CONCAT44(local_30[0],extraout_r4_00);
        local_b8 = local_80;
        local_b4 = local_7c;
      }
    }
    else {
      if (iVar3 != 0x76) {
        if ((iVar3 < 0x76) || (0x7e < iVar3)) goto LAB_97bbf334;
        if ((*(int *)(local_38 + 0xc) == 0) && (*(int *)(local_38 + 8) == 0)) {
          local_30[0] = local_38;
        }
        else {
          pPVar8 = operator_new(0x38);
          __ZN12ParseOperandC1ERKS_(pPVar8,local_38);
          local_30[0] = pPVar8;
          if (*(int *)(local_38 + 0xc) != 0) {
            pvVar12 = operator_new(0x38);
            __ZN12ParseOperandC1ERKS_(pvVar12,*(unsigned char **)(local_38 + 0xc));
            *(void **)(pPVar8 + 0xc) = pvVar12;
          }
          pPVar8 = local_30;
          if (*(int *)(local_38 + 8) != 0) {
            pvVar12 = operator_new(0x38);
            __ZN12ParseOperandC1ERKS_(pvVar12,*(unsigned char **)(local_38 + 8));
            *(void **)(pPVar8 + 8) = pvVar12;
          }
        }
        ppPVar15 = &local_34;
        __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_S2_
                  (param_2,local_30,&local_38,ppPVar15);
        goto LAB_97bbf370;
      }
      pPVar8 = (unsigned char *)&local_34;
      ppPVar15 = (unsigned char **)0x1;
      local_30[0] = local_38;
      TPPStreamCompiler__assignOperands(param_2,&local_38,(unsigned char **)pPVar8,1);
      uVar20 = CONCAT44(local_30[0],extraout_r4);
    }
    local_30[0] = (unsigned char *)((ulonglong)uVar20 >> 0x20);
    iVar6 = *(int *)(this + 0x30);
    iVar3 = iVar6 * 4;
    local_c0 = (*(uint *)(&_operatorToken + iVar3) & 0xff) << 0x12 | local_c0 & 0xfc03ffff;
    piVar5 = *(int **)(*(int *)local_30[0] + 0xc);
    if (piVar5 != (int *)0x0) {
      iVar6 = (**(code **)(*piVar5 + 0x24))(piVar5,(int)uVar20,pPVar8,ppPVar15,iVar6,param_6,iVar3);
      if (iVar6 == 0xd) {
        *(undefined4 *)(param_2 + 0xa4) = 1;
      }
      iVar6 = *(int *)(this + 0x30);
    }
    if (iVar6 < 0x31) {
      if (0x2c < iVar6) goto LAB_97bbf4fc;
      if (0x16 < iVar6) {
        if (iVar6 < 0x1d) goto LAB_97bbf46c;
        if (iVar6 < 0x1f) goto LAB_97bbf4fc;
      }
    }
    else {
      if (iVar6 == 0x76) goto LAB_97bbf4fc;
      if ((0x75 < iVar6) && (iVar6 - 0x7fU < 6)) {
LAB_97bbf46c:
        TPPStreamCompiler__error
                  (param_2,(char *)0x1,(char *)0x0,
                   "TIntermBinary::compileNode: Unsupported operation (TOperator: %d)",iVar6,param_6
                   ,iVar3,uVar17);
        goto LAB_97bbf4fc;
      }
    }
    uVar18 = ParseOperand__IsMatrix(local_30[0]);
    local_bc = (uVar18 & 1) << 0x1c | local_bc & 0xefffffff;
    if (*(int *)local_30[0] == 0) {
      uVar1 = *(ushort *)(local_30[0] + 0x18);
    }
    else {
      uVar1 = *(ushort *)(*(int *)local_30[0] + 0x2c);
    }
    uVar18 = GetPPStreamTypeForGLType((uint)uVar1);
    local_bc = (uVar18 & 7) << 0x17 | local_bc & 0xfc7fffff;
    iVar3 = ParseOperand__GetLogicalSize(local_30[0]);
    local_bc = (iVar3 + -1) * 0x4000000 & 0xc000000U | local_bc & 0xf3ffffff;
    ppPVar15 = local_30;
  }
  TPPStreamCompiler__AddOperation(param_2,ppPVar15,(unsigned char *)&local_c0,(char *)0x0,0);
LAB_97bbf4fc:
  pPVar8 = local_34;
  if (local_34 != (unsigned char *)0x0) {
    __ZN12ParseOperandD1Ev(local_34);
    __ZdlPv(pPVar8);
  }
  pPVar8 = local_38;
  if ((local_38 != (unsigned char *)0x0) && (local_30[0] != local_38)) {
    __ZN12ParseOperandD1Ev(local_38);
    __ZdlPv(pPVar8);
  }
  return local_30[0];
}

/* TIntermUnary__compileNode @ 0x97bbf564 (1824 bytes) */
int TIntermUnary__compileNode(this, param_2, param_3, param_4, param_5, param_6)
  unsigned char * this;
  unsigned char * param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  uint param_6;
{
  ushort uVar1;
  bool bVar2;
  undefined4 uVar3;
  uint uVar4;
  unsigned char * pTVar5;
  int *a0;
  undefined4 a1;
  undefined4 a1_00;
  undefined4 a1_01;
  unsigned char * a2;
  unsigned char * pPVar6;
  undefined4 a4;
  unsigned char * pPVar7;
  uint uVar8;
  int iVar9;
  uint local_b0;
  uint local_ac;
  uint local_a8;
  undefined4 local_a4;
  uint local_a0;
  undefined4 local_9c;
  uint local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  uint local_70;
  undefined4 local_6c;
  uint local_60;
  uint local_5c;
  uint local_58;
  undefined4 local_54;
  uint local_50;
  undefined4 local_4c;
  uint local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  unsigned char * local_20;
  unsigned char * local_1c;
  undefined4 local_18 [2];
  
  pPVar7 = (unsigned char *)0x0;
  local_88 = 0;
  local_84 = 0;
  local_b0 = 0;
  local_ac = 0;
  local_a8 = 0;
  local_a4 = 0;
  bVar2 = true;
  local_a0 = 0;
  local_9c = 0;
  local_98 = 0;
  local_94 = 0;
  local_90 = 0;
  local_8c = 0;
  local_7c = 0;
  local_20 = (unsigned char *)0x0;
  local_80 = 0;
  local_80 = (*(code *)**(undefined4 **)this)(this);
  local_b0 = local_b0 & 0x1fffffff | 0x20000000;
  uVar3 = (*(code *)**(undefined4 **)this)(this);
  *(undefined4 *)(param_2 + 0x90) = uVar3;
  local_1c = (unsigned char *)
             (**(code **)(**(int **)(this + 0x34) + 0xc))(*(int **)(this + 0x34),param_2);
  ((int (*)())ParseSymbolTable__processOperand)(*(unsigned char **)(param_2 + 0x68),local_1c);
  uVar8 = *(uint *)(this + 0x30);
  if (uVar8 - 5 < 8) {
    pPVar7 = (unsigned char *)((uVar8 - 5) * 4);
    switch(uVar8) {
    default:
      bVar2 = false;
      goto LAB_97bbfa5c;
    case 6:
    case 7:
      goto switchD_97bbf664_caseD_6;
    case 9:
    case 10:
      pTVar5 = (unsigned char *)(**(code **)(*(int *)this + 0x3c))
                                  (this,a1,param_3,param_4,param_5,param_6,pPVar7,uVar8);
      local_20 = (unsigned char *)TPPStreamCompiler__newTemporary(param_2,pTVar5);
      __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_
                (param_2,&local_20,&local_1c);
      TPPStreamCompiler__getOperandAsSourceVar
                ((unsigned char *)&local_70,param_2,local_1c,param_4,param_5,param_6,pPVar7,uVar8);
      local_a0 = local_70;
      local_9c = local_6c;
      TPPStreamCompiler__getOperandAsDestVar
                ((unsigned char *)&local_70,param_2,local_20,param_4,param_5,param_6);
      local_ac = (local_70 >> 0xc & 1) << 0x1c | local_ac & 0xefffffff;
      local_b0 = local_b0 & 0xfc03ffff;
      local_a4 = local_6c;
      local_a8 = local_70;
      if (*(int *)local_20 == 0) {
        uVar1 = *(ushort *)(local_20 + 0x18);
      }
      else {
        uVar1 = *(ushort *)(*(int *)local_20 + 0x2c);
      }
      pPVar7 = local_20;
      uVar8 = GetPPStreamTypeForGLType((uint)uVar1);
      local_ac = (uVar8 & 7) << 0x17 | local_ac & 0xfc7fffff;
      iVar9 = ParseOperand__GetLogicalSize(local_20);
      local_ac = (iVar9 + -1) * 0x4000000 & 0xc000000U | local_ac & 0xf3ffffff;
      a2 = (unsigned char *)&local_b0;
      uVar3 = 0;
      a4 = 0;
      TPPStreamCompiler__AddOperation(param_2,&local_20,a2,(char *)0x0,0);
      local_38 = 0;
      local_34 = 0;
      local_60 = 0;
      local_5c = 0;
      local_58 = 0;
      local_54 = 0;
      local_50 = 0;
      local_4c = 0;
      local_48 = 0;
      local_44 = 0;
      local_40 = 0;
      local_3c = 0;
      local_2c = 0;
      local_30 = 0;
      local_30 = (*(code *)**(undefined4 **)this)
                           (this,a1_00,a2,uVar3,a4,param_6,*(undefined4 **)this);
      local_60 = local_60 & 0x1fffffff | 0x40000000;
      if (*(int *)local_1c == 0) {
        uVar1 = *(ushort *)(local_1c + 0x18);
      }
      else {
        uVar1 = *(ushort *)(*(int *)local_1c + 0x2c);
      }
      pPVar6 = local_1c;
      uVar8 = GetPPStreamTypeForGLType((uint)uVar1);
      if (uVar8 == 3) {
        a4 = 0x1404;
LAB_97bbf88c:
        local_18[0] = 1;
LAB_97bbf894:
        uVar3 = 1;
        TPPStreamCompiler__getConstantAsSourceVar
                  ((unsigned char *)&local_70,(uint)param_2,local_18,1,a4);
        local_48 = local_70;
        local_44 = local_6c;
      }
      else if (uVar8 < 4) {
        if (uVar8 == 1) {
          a4 = 0x1406;
          local_18[0] = 0x3f800000;
          goto LAB_97bbf894;
        }
      }
      else if (uVar8 == 4) {
        a4 = 0x8b56;
        goto LAB_97bbf88c;
      }
      __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_
                (param_2,&local_1c,&local_1c);
      TPPStreamCompiler__getOperandAsSourceVar
                ((unsigned char *)&local_70,param_2,local_1c,uVar3,a4,param_6,pPVar6,pPVar7);
      local_50 = local_70;
      local_4c = local_6c;
      TPPStreamCompiler__getOperandAsDestVar
                ((unsigned char *)&local_70,param_2,local_1c,uVar3,a4,param_6);
      param_6 = *(uint *)(&_operatorToken + *(int *)(this + 0x30) * 4);
      uVar8 = (param_6 & 0xff) << 0x12 | local_60 & 0xfc03ffff;
      local_5c = (local_a8 >> 0xc & 1) << 0x1c | local_5c & 0xefffffff;
      local_58 = local_70;
      local_54 = local_6c;
      if (*(int *)local_1c == 0) {
        uVar1 = *(ushort *)(local_1c + 0x18);
      }
      else {
        uVar1 = *(ushort *)(*(int *)local_1c + 0x2c);
      }
      pPVar7 = local_1c;
      local_60 = uVar8;
      uVar4 = GetPPStreamTypeForGLType((uint)uVar1);
      local_5c = (uVar4 & 7) << 0x17 | local_5c & 0xfc7fffff;
      bVar2 = false;
      iVar9 = ParseOperand__GetLogicalSize(local_1c);
      local_5c = (iVar9 + -1) * 0x4000000 & 0xc000000U | local_5c & 0xf3ffffff;
      param_4 = 0;
      param_5 = 0;
      TPPStreamCompiler__AddOperation
                (param_2,&local_1c,(unsigned char *)&local_60,(char *)0x0,0);
      break;
    case 0xb:
    case 0xc:
      local_b0 = local_b0 & 0x1fffffff | 0x40000000;
      if (*(int *)local_1c == 0) {
        uVar1 = *(ushort *)(local_1c + 0x18);
      }
      else {
        uVar1 = *(ushort *)(*(int *)local_1c + 0x2c);
      }
      uVar4 = GetPPStreamTypeForGLType((uint)uVar1);
      if (uVar4 == 3) {
        param_5 = 0x1404;
LAB_97bbfa3c:
        local_18[0] = 1;
LAB_97bbfa44:
        param_4 = 1;
        TPPStreamCompiler__getConstantAsSourceVar
                  ((unsigned char *)&local_70,(uint)param_2,local_18,1,param_5);
        local_98 = local_70;
        local_94 = local_6c;
      }
      else if (uVar4 < 4) {
        if (uVar4 == 1) {
          param_5 = 0x1406;
          local_18[0] = 0x3f800000;
          goto LAB_97bbfa44;
        }
      }
      else if (uVar4 == 4) {
        param_5 = 0x8b56;
        goto LAB_97bbfa3c;
      }
LAB_97bbfa5c:
      local_20 = local_1c;
    }
  }
  else {
switchD_97bbf664_caseD_6:
    pTVar5 = (unsigned char *)(**(code **)(*(int *)this + 0x3c))(this);
    local_20 = (unsigned char *)TPPStreamCompiler__newTemporary(param_2,pTVar5);
  }
  if (bVar2) {
    __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_(param_2,&local_20,&local_1c)
    ;
    TPPStreamCompiler__getOperandAsSourceVar
              ((unsigned char *)&local_70,param_2,local_1c,param_4,param_5,param_6,pPVar7,uVar8);
    local_a0 = local_70;
    local_9c = local_6c;
    pPVar6 = local_20;
    TPPStreamCompiler__getOperandAsDestVar
              ((unsigned char *)&local_70,param_2,local_20,param_4,param_5,param_6);
    iVar9 = *(int *)(this + 0x30);
    local_b0 = (*(uint *)(&_operatorToken + iVar9 * 4) & 0xff) << 0x12 | local_b0 & 0xfc03ffff;
    local_a4 = local_6c;
    local_a8 = local_70;
    pPVar7 = *(unsigned char **)local_20;
    a0 = *(int **)(pPVar7 + 0xc);
    if (a0 == (int *)0x0) goto LAB_97bbfb3c;
    iVar9 = (**(code **)(*a0 + 0x24))(a0,a1_01,pPVar6,param_4,param_5,param_6,pPVar7,iVar9);
    if (iVar9 == 0xd) {
      *(undefined4 *)(param_2 + 0xa4) = 1;
    }
  }
  iVar9 = *(int *)(this + 0x30);
LAB_97bbfb3c:
  if (iVar9 == 5) {
    *(uint *)(local_1c + 0x28) = (uint)(*(int *)(local_1c + 0x28) != 1);
  }
  else if (iVar9 == 8) {
    TPPStreamCompiler__error
              (param_2,(char *)0x1,(char *)0x0,
               "SecondPassProcessAggregateOp: EOpBitwiseNot not supported",param_5,param_6,pPVar7,8)
    ;
  }
  if (bVar2) {
    iVar9 = *(int *)(this + 0x30);
    if (((iVar9 == 0x4b) || (iVar9 == 0x57)) || (iVar9 == 0x58)) {
      local_ac = (local_a0 >> 0xe & 1) << 0x1c | local_ac & 0xefffffff;
      if (*(int *)local_1c == 0) {
        uVar1 = *(ushort *)(local_1c + 0x18);
      }
      else {
        uVar1 = *(ushort *)(*(int *)local_1c + 0x2c);
      }
      uVar8 = GetPPStreamTypeForGLType((uint)uVar1);
      pPVar7 = local_1c;
    }
    else {
      local_ac = (local_a8 >> 0xc & 1) << 0x1c | local_ac & 0xefffffff;
      if (*(int *)local_20 == 0) {
        uVar1 = *(ushort *)(local_20 + 0x18);
      }
      else {
        uVar1 = *(ushort *)(*(int *)local_20 + 0x2c);
      }
      uVar8 = GetPPStreamTypeForGLType((uint)uVar1);
      pPVar7 = local_20;
    }
    local_ac = (uVar8 & 7) << 0x17 | local_ac & 0xfc7fffff;
    iVar9 = ParseOperand__GetLogicalSize(pPVar7);
    local_ac = (iVar9 + -1) * 0x4000000 & 0xc000000U | local_ac & 0xf3ffffff;
    TPPStreamCompiler__AddOperation(param_2,&local_20,(unsigned char *)&local_b0,(char *)0x0,0)
    ;
  }
  pPVar7 = local_1c;
  if ((local_20 != local_1c) && (local_1c != (unsigned char *)0x0)) {
    __ZN12ParseOperandD1Ev(local_1c);
    __ZdlPv(pPVar7);
  }
  return local_20;
}

/* TIntermAggregate__compileNode @ 0x97bbfca4 (4308 bytes) */
int TIntermAggregate__compileNode(this, param_2, param_3, param_4, param_5, param_6)
  unsigned char * this;
  unsigned char * param_2;
  unsigned char ** param_3;
  int param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  bool bVar1;
  byte bVar2;
  ushort uVar3;
  byte *pbVar4;
  undefined **ppuVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  char *pcVar9;
  unsigned char * pTVar10;
  int *piVar11;
  unsigned char ** ppPVar12;
  unsigned char * this_00;
  unsigned char * this_01;
  undefined4 extraout_r4;
  undefined4 a1;
  undefined4 a1_00;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  undefined4 extraout_r4_02;
  undefined4 extraout_r4_03;
  undefined4 extraout_r4_04;
  undefined4 a1_01;
  undefined4 extraout_r4_05;
  undefined4 extraout_r4_06;
  undefined4 extraout_r4_07;
  undefined4 a1_02;
  undefined4 a1_03;
  undefined4 extraout_r4_08;
  undefined4 extraout_r4_09;
  undefined4 extraout_r4_10;
  undefined4 extraout_r4_11;
  undefined4 a1_04;
  undefined4 extraout_r4_12;
  undefined4 a1_05;
  undefined4 a1_06;
  unsigned char ** ppPVar13;
  unsigned char ** ppPVar14;
  unsigned char * a2;
  uint uVar15;
  int iVar16;
  uint a5;
  uint uVar17;
  uint a7;
  int iVar18;
  unsigned char ** ppPVar19;
  int iVar20;
  undefined4 *puVar21;
  unsigned char * pPVar22;
  undefined4 uVar23;
  uint *puVar24;
  unsigned char * pPVar25;
  undefined4 *puVar26;
  void *pvVar27;
  char in_RESERVE;
  byte in_cr0;
  undefined8 uVar28;
  uint local_d0 [2];
  undefined **local_c8;
  uint local_c4;
  undefined **local_c0;
  uint local_bc;
  undefined **local_b8;
  uint local_b4;
  uint local_b0;
  undefined4 local_ac;
  undefined **local_a8;
  uint local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined **local_90;
  uint local_8c;
  uint local_6c;
  undefined **local_60 [4];
  unsigned char * local_50;
  unsigned char * local_4c;
  unsigned char * local_48 [3];
  
  ppPVar19 = (unsigned char **)0x0;
  local_a8 = (undefined **)0x0;
  local_a4 = 0;
  local_d0[0] = 0;
  local_d0[1] = 0;
  local_c8 = (undefined **)0x0;
  local_c4 = 0;
  local_c0 = (undefined **)0x0;
  local_bc = 0;
  local_b8 = (undefined **)0x0;
  local_b4 = 0;
  local_b0 = 0;
  local_ac = 0;
  local_48[0] = (unsigned char *)0x0;
  local_a0 = 0;
  local_9c = 0;
  iVar20 = *(int *)(param_2 + 0x70);
  iVar18 = *(int *)(this + 0x3c) - *(int *)(this + 0x38) >> 2;
  local_a0 = (*(code *)**(undefined4 **)this)
                       (this,param_2,param_3,param_4,param_5,param_6,*(int *)(this + 0x38));
  uVar7 = (*(code *)**(undefined4 **)this)(this);
  *(undefined4 *)(param_2 + 0x90) = uVar7;
  iVar6 = *(int *)(this + 0x30);
  if (iVar6 == 3) {
    iVar6 = (**(code **)(*(int *)this + 0x6c))(this);
    pbVar4 = DAT_a7b7bd04;
    *(byte *)(*(int *)(iVar6 + 4) + *(int *)(*(int *)(iVar6 + 4) + -0xc)) = *DAT_a7b7bd04;
    uVar7 = _strlen(*(undefined4 *)(iVar6 + 4));
    iVar6 = (**(code **)(*(int *)this + 0x6c))(this);
    *(byte *)(*(int *)(iVar6 + 4) + *(int *)(*(int *)(iVar6 + 4) + -0xc)) = *pbVar4;
    _PPStreamAddLabel(iVar20,*(undefined4 *)(iVar6 + 4),uVar7);
    iVar6 = (**(code **)(*(int *)this + 0x6c))(this);
    *(byte *)(*(int *)(iVar6 + 4) + *(int *)(*(int *)(iVar6 + 4) + -0xc)) = *pbVar4;
    iVar6 = FunctionTable__addFunction(*(unsigned char **)(param_2 + 0x6c),*(char **)(iVar6 + 4));
    iVar8 = (**(code **)(*(int *)this + 0x6c))(this);
    *(byte *)(*(int *)(iVar8 + 4) + *(int *)(*(int *)(iVar8 + 4) + -0xc)) = *pbVar4;
    ParseFunctionStack__push((unsigned char *)(param_2 + 0x58),*(char **)(iVar8 + 4));
    iVar8 = (**(code **)(*(int *)this + 0x6c))(this);
    *(byte *)(*(int *)(iVar8 + 4) + *(int *)(*(int *)(iVar8 + 4) + -0xc)) = *pbVar4;
    iVar8 = _memcmp(*(undefined4 *)(iVar8 + 4),"main(",5);
    if (iVar8 == 0) {
      param_3 = (unsigned char **)0x0;
      FunctionTable__setFirstOp(*(unsigned char **)(param_2 + 0x6c),iVar6,0);
      *(undefined4 *)(param_2 + 0xac) = 1;
      while (iVar8 = ((int (*)())size)((unsigned char *)(param_2 + 0x4c)), iVar8 != 0) {
        piVar11 = (int *)fetch((unsigned char *)(param_2 + 0x4c));
        (**(code **)(*piVar11 + 0xc))(piVar11,param_2);
      }
    }
    else {
      iVar8 = TPPStreamCompiler__LastOperationIndex(param_2);
      param_3 = (unsigned char **)0x1;
      if (iVar8 != -1) {
        param_3 = (unsigned char **)(iVar8 + 1);
      }
      FunctionTable__setFirstOp(*(unsigned char **)(param_2 + 0x6c),iVar6,(uint)param_3);
    }
    (**(code **)(*(int *)this + 0x38))(&local_90,this);
    uVar15 = local_6c & 0x1f80000;
    in_cr0 = (uVar15 == 0) << 1;
    local_90 = &PTR___ZN5TTypeD1Ev_a7b7d730;
    uVar7 = a1;
    if (uVar15 != 0) {
      iVar8 = (**(code **)(*(int *)this + 0x6c))(this,a1,param_3,param_4,param_5,param_6,uVar15);
      iVar16 = *(int *)(iVar8 + 4);
      *(byte *)(iVar16 + *(int *)(iVar16 + -0xc)) = *DAT_a7b7bd04;
      uVar7 = *(undefined4 *)(iVar8 + 4);
      pcVar9 = (char *)(**(code **)(*(int *)this + 0x3c))
                                 (this,a1_00,param_3,param_4,param_5,param_6,iVar16,iVar8);
      local_48[0] = (unsigned char *)TPPStreamCompiler__newReturnValue((unsigned char *)param_2,pcVar9,uVar7)
      ;
      param_3 = (unsigned char **)0x1;
      FunctionTable__setReturnVal(*(unsigned char **)(param_2 + 0x6c),iVar6,1);
      uVar7 = extraout_r4_00;
    }
  }
  else {
    uVar7 = extraout_r4;
    if ((iVar6 != 2) && (iVar6 == 1)) {
      iVar6 = *(int *)(param_2 + 0x98);
      if (0 < iVar6) {
        uVar28 = ParseFunctionStack__empty((unsigned char *)(param_2 + 0x58));
        uVar7 = (undefined4)uVar28;
        if ((int)((ulonglong)uVar28 >> 0x20) != 0) {
          ((int (*)())store)((unsigned char *)(param_2 + 0x4c),this);
          return (unsigned char *)0x0;
        }
        iVar6 = *(int *)(param_2 + 0x98);
      }
      *(int *)(param_2 + 0x98) = iVar6 + 1;
    }
  }
  bVar1 = iVar18 != 0;
  if (bVar1) {
    ppPVar19 = (unsigned char **)_malloc(iVar18 << 2);
    uVar7 = extraout_r4_01;
    ppPVar12 = ppPVar19;
    for (puVar26 = *(undefined4 **)(this + 0x38); puVar26 != *(undefined4 **)(this + 0x3c);
        puVar26 = puVar26 + 1) {
      pPVar25 = (unsigned char *)(**(code **)(*(int *)*puVar26 + 0xc))((int *)*puVar26,param_2);
      *ppPVar12 = pPVar25;
      ppPVar12 = ppPVar12 + 1;
      ((int (*)())ParseSymbolTable__processOperand)(*(unsigned char **)(param_2 + 0x68),pPVar25);
      uVar7 = extraout_r4_02;
    }
  }
  uVar28 = CONCAT44(local_48[0],uVar7);
  a5 = *(uint *)(this + 0x30);
  a7 = (*(uint *)(&_operatorToken + a5 * 4) & 0xff) << 0x12 |
       iVar18 << 0x1d | local_d0[0] & 0x1c03ffff;
  uVar15 = a7;
  switch(a5) {
  case 0x15:
    uVar15 = iVar18 << 0x1d | local_d0[0] & 0x1c03ffff | 0x8c0000;
  case 0x17:
  case 0x1f:
  case 0x20:
  case 0x21:
  case 0x22:
  case 0x23:
  case 0x24:
  case 0x38:
  case 0x39:
  case 0x45:
  case 0x46:
  case 0x47:
  case 0x48:
  case 0x49:
  case 0x4a:
  case 0x4c:
  case 0x4d:
  case 0x4e:
  case 0x50:
  case 0x51:
  case 0x52:
  case 0x85:
  case 0x8a:
  case 0x8b:
  case 0x8c:
  case 0x8d:
  case 0x8e:
  case 0x8f:
  case 0x90:
  case 0x91:
  case 0x92:
  case 0x93:
  case 0x94:
  case 0x95:
  case 0x96:
  case 0x97:
  case 0x98:
  case 0x99:
  case 0x9a:
  case 0x9b:
  case 0x9c:
  case 0x9d:
  case 0x9e:
  case 0x9f:
  case 0xa0:
  case 0xa1:
  case 0xa2:
  case 0xa3:
    local_d0[0] = uVar15;
    pTVar10 = (unsigned char *)(**(code **)(*(int *)this + 0x3c))
                                 (this,uVar7,param_3,param_4,param_5,a5,a5 * 4,a7);
    uVar28 = TPPStreamCompiler__newTemporary(param_2,pTVar10);
    a5 = *(uint *)(this + 0x30);
    uVar15 = local_d0[0];
    break;
  case 0x25:
    uVar28 = CONCAT44(ppPVar19[iVar18 + -1],uVar7);
  }
  local_d0[0] = uVar15;
  local_48[0] = (unsigned char *)((ulonglong)uVar28 >> 0x20);
  if ((((local_48[0] != (unsigned char *)0x0) && (a5 != 3)) && (*(int *)local_48[0] != 0)) &&
     (piVar11 = *(int **)(*(int *)local_48[0] + 0xc), piVar11 != (int *)0x0)) {
    iVar6 = (**(code **)(*piVar11 + 0x24))(piVar11,(int)uVar28,param_3,param_4,param_5,a5);
    uVar28 = CONCAT44(local_48[0],extraout_r4_03);
    if (iVar6 == 0xd) {
      *(undefined4 *)(param_2 + 0xa4) = 1;
    }
    a5 = *(uint *)(this + 0x30);
  }
  local_48[0] = (unsigned char *)((ulonglong)uVar28 >> 0x20);
  if (0xa3 < a5) {
switchD_97bc03dc_caseD_0:
    TType__getCompleteString(&local_90,this + 8);
    bVar2 = *DAT_a7b7bd04;
    *(byte *)(local_8c + *(int *)(local_8c - 0xc)) = bVar2;
    TPPStreamCompiler__error
              (param_2,(char *)0x1,(char *)0x0,
               "TIntermAggregate::compileNode- unhandle operation %s at %d\n",local_8c,
               *(undefined4 *)(this + 4),(uint)bVar2,a7);
    piVar11 = (int *)(local_8c - 4);
    local_60[0] = local_90;
    do {
      iVar6 = *piVar11;
      if (in_RESERVE != '\0') {
        iVar20 = storeWordConditionalIndexed(iVar6 + -1,0,piVar11);
        *piVar11 = iVar20;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar6 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_8c - 0xc),local_60);
    }
    goto switchD_97bc03dc_caseD_25;
  }
  iVar6 = a5 * 4;
  switch(a5) {
  default:
    goto switchD_97bc03dc_caseD_0;
  case 1:
    *(int *)(param_2 + 0x98) = *(int *)(param_2 + 0x98) + -1;
    break;
  case 2:
    iVar6 = 0;
    ppPVar12 = (unsigned char **)0x0;
    if (bVar1) {
      iVar6 = _malloc(iVar18 << 2);
      ppPVar12 = (unsigned char **)_malloc(iVar18 << 2);
      uVar28 = CONCAT44(local_48[0],extraout_r4_11);
    }
    pbVar4 = DAT_a7b7bd04;
    local_48[0] = (unsigned char *)((ulonglong)uVar28 >> 0x20);
    iVar20 = 0;
    puVar26 = *(undefined4 **)(this + 0x38);
    if (0 < iVar18) {
      do {
        iVar8 = iVar20 * 4;
        iVar16 = (**(code **)(*(int *)this + 0x6c))(this);
        bVar2 = *pbVar4;
        *(byte *)(*(int *)(iVar16 + 4) + *(int *)(*(int *)(iVar16 + 4) + -0xc)) = bVar2;
        pcVar9 = *(char **)(iVar16 + 4);
        piVar11 = (int *)(**(code **)(*(int *)*puVar26 + 0x14))
                                   ((int *)*puVar26,a1_04,param_3,param_4,param_5,a5,(uint)bVar2);
        pTVar10 = (unsigned char *)(**(code **)(*piVar11 + 0x3c))(piVar11);
        uVar7 = TPPStreamCompiler__newParam(param_2,pTVar10,pcVar9,iVar20);
        *(undefined4 *)(iVar8 + iVar6) = uVar7;
        if ((*(int *)(ppPVar19[iVar20] + 0xc) == 0) && (*(int *)(ppPVar19[iVar20] + 8) == 0)) {
          ppPVar12[iVar20] = (unsigned char *)0x0;
        }
        else {
          this_01 = operator_new(0x38);
          __ZN12ParseOperandC1ERKS_(this_01,ppPVar19[iVar20]);
          ppPVar12[iVar20] = this_01;
          pPVar25 = ppPVar19[iVar20];
          if (*(int *)(pPVar25 + 0xc) != 0) {
            pvVar27 = operator_new(0x38);
            __ZN12ParseOperandC1ERKS_(pvVar27,*(unsigned char **)(ppPVar19[iVar20] + 0xc));
            *(void **)(this_01 + 0xc) = pvVar27;
            pPVar25 = ppPVar19[iVar20];
          }
          if (*(int *)(pPVar25 + 8) != 0) {
            pPVar25 = ppPVar12[iVar20];
            pvVar27 = operator_new(0x38);
            __ZN12ParseOperandC1ERKS_(pvVar27,*(unsigned char **)(ppPVar19[iVar20] + 8));
            *(void **)(pPVar25 + 8) = pvVar27;
          }
        }
        param_3 = ppPVar19 + iVar20;
        iVar20 = iVar20 + 1;
        param_4 = 0;
        TPPStreamCompiler__assignOperands(param_2,(unsigned char **)(iVar6 + iVar8),param_3,0);
        uVar28 = CONCAT44(local_48[0],extraout_r4_12);
        puVar26 = puVar26 + 1;
      } while (iVar20 < iVar18);
    }
    local_48[0] = (unsigned char *)((ulonglong)uVar28 >> 0x20);
    local_d0[0] = local_d0[0] & 0x1c03ffff | 0x1300000;
    iVar8 = 0;
    iVar20 = (**(code **)(*(int *)this + 0x6c))
                       (this,(int)uVar28,param_3,param_4,param_5,a5,*(int *)this);
    pbVar4 = DAT_a7b7bd04;
    *(byte *)(*(int *)(iVar20 + 4) + *(int *)(*(int *)(iVar20 + 4) + -0xc)) = *DAT_a7b7bd04;
    local_9c = _strlen(*(undefined4 *)(iVar20 + 4));
    iVar20 = (**(code **)(*(int *)this + 0x6c))(this);
    a2 = (unsigned char *)local_d0;
    uVar7 = 0;
    *(byte *)(*(int *)(iVar20 + 4) + *(int *)(*(int *)(iVar20 + 4) + -0xc)) = *pbVar4;
    pcVar9 = *(char **)(iVar20 + 4);
    TPPStreamCompiler__AddOperation(param_2,(unsigned char **)0x0,a2,pcVar9,0);
    if (0 < iVar18) {
      do {
        iVar20 = ParseOperand__isWriteable(ppPVar19[iVar8]);
        if (iVar20 != 0) {
          ppPVar13 = ppPVar12;
          if (ppPVar12[iVar8] == (unsigned char *)0x0) {
            ppPVar13 = ppPVar19;
          }
          a2 = (unsigned char *)(iVar6 + iVar8 * 4);
          pcVar9 = (char *)0x0;
          TPPStreamCompiler__assignOperands(param_2,ppPVar13 + iVar8,(unsigned char **)a2,0);
        }
        pvVar27 = *(void **)(iVar8 * 4 + iVar6);
        if (pvVar27 != (void *)0x0) {
          __ZN12ParseOperandD1Ev(pvVar27);
          __ZdlPv(pvVar27);
        }
        pPVar25 = ppPVar12[iVar8];
        if (pPVar25 != (unsigned char *)0x0) {
          __ZN12ParseOperandD1Ev(pPVar25);
          __ZdlPv(pPVar25);
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 < iVar18);
    }
    if (iVar6 != 0) {
      _free(iVar6);
    }
    if (ppPVar12 != (unsigned char **)0x0) {
      _free(ppPVar12);
    }
    (**(code **)(*(int *)this + 0x38))(&local_90,this);
    local_90 = &PTR___ZN5TTypeD1Ev_a7b7d730;
    if ((local_6c & 0x1f80000) != 0) {
      iVar6 = (**(code **)(*(int *)this + 0x6c))(this,a1_05,a2,pcVar9,uVar7,a5,local_6c & 0x1f80000)
      ;
      iVar20 = *(int *)(iVar6 + 4);
      *(byte *)(iVar20 + *(int *)(iVar20 + -0xc)) = *DAT_a7b7bd04;
      uVar23 = *(undefined4 *)(iVar6 + 4);
      pcVar9 = (char *)(**(code **)(*(int *)this + 0x3c))
                                 (this,a1_06,a2,pcVar9,uVar7,a5,iVar20,iVar6);
      local_48[0] = (unsigned char *)
                    TPPStreamCompiler__newReturnValue((unsigned char *)param_2,pcVar9,uVar23);
    }
    break;
  case 3:
    pPVar22 = (unsigned char *)(param_2 + 0x58);
    puVar26 = (undefined4 *)ParseFunctionStack__getCurrentParamList(pPVar22);
    ppPVar12 = (unsigned char **)ParseFunctionStack__getCurrentNumParams(pPVar22);
    pcVar9 = (char *)ParseFunctionStack__current(pPVar22);
    iVar6 = FunctionTable__findFunction
                      (*(unsigned char **)(param_2 + 0x6c),pcVar9,param_3,param_4,param_5,a5);
    iVar8 = FunctionTable__getFirstOp(*(unsigned char **)(param_2 + 0x6c),iVar6);
    if (iVar8 == 0) {
LAB_97bc06f4:
      this_00 = *(unsigned char **)(param_2 + 0x6c);
      uVar7 = 0;
    }
    else {
      iVar8 = ParseFunctionStack__getLastParamOpIndex(pPVar22);
      iVar16 = TPPStreamCompiler__LastOperationIndex(param_2);
      if (iVar8 != iVar16) goto LAB_97bc06f4;
      this_00 = *(unsigned char **)(param_2 + 0x6c);
      uVar7 = 1;
    }
    FunctionTable__setEmpty(this_00,iVar6,uVar7);
    ppPVar13 = ppPVar12;
    FunctionTable__setNumParams(*(unsigned char **)(param_2 + 0x6c),iVar6,(int)ppPVar12);
    iVar8 = (**(code **)(*(int *)this + 0x6c))(this);
    *(byte *)(*(int *)(iVar8 + 4) + *(int *)(*(int *)(iVar8 + 4) + -0xc)) = *DAT_a7b7bd04;
    pcVar9 = *(char **)(iVar8 + 4);
    iVar20 = *(int *)(*(int *)(iVar20 + 0x20) + 4);
    uVar7 = extraout_r4_04;
    if ((iVar20 == 0) || ((*(uint *)(iVar20 + 0xc) & 0x3fc0000) != 0x1340000)) {
LAB_97bc0788:
      iVar20 = 0;
      if (0 < (int)ppPVar12) {
        do {
          ppPVar14 = (unsigned char **)(puVar26 + iVar20);
          if (((int *)puVar26[iVar20] != (int *)0x0) &&
             ((piVar11 = *(int **)(*(int *)puVar26[iVar20] + 0xc), iVar8 = *piVar11,
              iVar8 = (**(code **)(iVar8 + 0x24))(piVar11,uVar7,ppPVar13,param_4,param_5,a5,iVar8),
              iVar8 == 10 ||
              (piVar11 = *(int **)(*(int *)puVar26[iVar20] + 0xc),
              iVar8 = (**(code **)(*piVar11 + 0x24))
                                (piVar11,a1_01,ppPVar13,param_4,param_5,a5,*(int *)puVar26[iVar20]),
              uVar7 = extraout_r4_05, iVar8 == 0xb)))) {
            local_50 = (unsigned char *)
                       TPPStreamCompiler__newParam
                                 (param_2,*(unsigned char **)(*(int *)puVar26[iVar20] + 0xc),pcVar9,iVar20);
            param_4 = 0;
            TPPStreamCompiler__assignOperands(param_2,&local_50,ppPVar14,0);
            pPVar25 = local_50;
            uVar7 = extraout_r4_06;
            ppPVar13 = ppPVar14;
            if (local_50 != (unsigned char *)0x0) {
              __ZN12ParseOperandD1Ev(local_50);
              __ZdlPv(pPVar25);
              uVar7 = extraout_r4_07;
              ppPVar13 = ppPVar14;
            }
          }
          iVar20 = iVar20 + 1;
        } while (iVar20 < (int)ppPVar12);
      }
      local_d0[1] = 0;
      local_a8 = (undefined **)0x0;
      local_a4 = 0;
      local_c8 = (undefined **)0x0;
      local_c4 = 0;
      local_c0 = (undefined **)0x0;
      local_bc = 0;
      local_b8 = (undefined **)0x0;
      local_b4 = 0;
      local_b0 = 0;
      local_ac = 0;
      local_9c = 0;
      local_d0[0] = 0x1340000;
      local_a0 = 0;
      local_a0 = (*(code *)**(undefined4 **)this)(this,uVar7,ppPVar13,param_4,param_5,a5,0x1340000);
      TPPStreamCompiler__AddOperation
                (param_2,(unsigned char **)0x0,(unsigned char *)local_d0,(char *)0x0,0);
    }
    else {
      iVar20 = TPPStreamCompiler__LastOperationIndex(param_2);
      uVar28 = FunctionTable__getFirstOp(*(unsigned char **)(param_2 + 0x6c),iVar6);
      uVar7 = (undefined4)uVar28;
      if (iVar20 < (int)((ulonglong)uVar28 >> 0x20)) goto LAB_97bc0788;
    }
    if (puVar26 != (undefined4 *)0x0) {
      puVar21 = puVar26;
      if (0 < (int)ppPVar12) {
        do {
          pvVar27 = (void *)*puVar21;
          if (pvVar27 != (void *)0x0) {
            __ZN12ParseOperandD1Ev(pvVar27);
            __ZdlPv(pvVar27);
          }
          ppPVar12 = (unsigned char **)((int)ppPVar12 + -1);
          puVar21 = puVar21 + 1;
        } while (ppPVar12 != (unsigned char **)0x0);
      }
      _free(puVar26);
    }
    ParseFunctionStack__pop(pPVar22);
    uVar15 = TPPStreamCompiler__LastOperationIndex(param_2);
    FunctionTable__setLastOp(*(unsigned char **)(param_2 + 0x6c),iVar6,uVar15);
    break;
  case 4:
    pPVar22 = (unsigned char *)(param_2 + 0x58);
    iVar6 = 0;
    uVar28 = ParseFunctionStack__current(pPVar22);
    uVar7 = (undefined4)uVar28;
    if (0 < iVar18) {
      do {
        if ((ppPVar19[iVar6] != (unsigned char *)0x0) &&
           (((piVar11 = *(int **)(*(int *)ppPVar19[iVar6] + 0xc), iVar20 = *piVar11,
             iVar20 = (**(code **)(iVar20 + 0x24))(piVar11,uVar7,param_3,param_4,param_5,a5,iVar20),
             iVar20 == 9 ||
             (piVar11 = *(int **)(*(int *)ppPVar19[iVar6] + 0xc),
             iVar20 = (**(code **)(*piVar11 + 0x24))
                                (piVar11,a1_02,param_3,param_4,param_5,a5,*(int *)ppPVar19[iVar6]),
             iVar20 == 0xb)) ||
            (piVar11 = *(int **)(*(int *)ppPVar19[iVar6] + 0xc),
            iVar20 = (**(code **)(*piVar11 + 0x24))
                               (piVar11,a1_03,param_3,param_4,param_5,a5,*(int *)ppPVar19[iVar6]),
            uVar7 = extraout_r4_08, iVar20 == 0xc)))) {
          local_4c = (unsigned char *)
                     TPPStreamCompiler__newParam
                               (param_2,*(unsigned char **)(*(int *)ppPVar19[iVar6] + 0xc),
                                (char *)((ulonglong)uVar28 >> 0x20),iVar6);
          param_3 = &local_4c;
          param_4 = 0;
          TPPStreamCompiler__assignOperands(param_2,ppPVar19 + iVar6,param_3,0);
          pPVar25 = local_4c;
          uVar7 = extraout_r4_09;
          if (local_4c != (unsigned char *)0x0) {
            __ZN12ParseOperandD1Ev(local_4c);
            __ZdlPv(pPVar25);
            uVar7 = extraout_r4_10;
          }
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < iVar18);
    }
    iVar6 = TPPStreamCompiler__LastOperationIndex(param_2);
    ParseFunctionStack__setLastParamOpIndex(pPVar22,iVar6);
    ParseFunctionStack__setCurrentParamList(pPVar22,ppPVar19);
    ParseFunctionStack__setCurrentNumParams(pPVar22,iVar18);
    break;
  case 0x15:
  case 0x17:
  case 0x1f:
  case 0x20:
  case 0x21:
  case 0x22:
  case 0x23:
  case 0x24:
  case 0x39:
  case 0x45:
  case 0x46:
  case 0x47:
  case 0x4a:
  case 0x4c:
  case 0x4d:
  case 0x4e:
  case 0x50:
  case 0x51:
  case 0x52:
    param_4 = iVar18;
    __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_i
              (param_2,local_48,ppPVar19,iVar18);
    if (0 < iVar18) {
      puVar24 = local_d0;
      iVar20 = iVar18;
      ppPVar12 = ppPVar19;
      do {
        pPVar25 = *ppPVar12;
        ppPVar12 = ppPVar12 + 1;
        TPPStreamCompiler__getOperandAsSourceVar
                  ((unsigned char *)&local_90,param_2,pPVar25,param_4,param_5,a5,iVar6,a7);
        ppuVar5 = local_90;
        iVar20 = iVar20 + -1;
        puVar24[5] = local_8c;
        puVar24[4] = (uint)ppuVar5;
        puVar24 = puVar24 + 2;
      } while (iVar20 != 0);
    }
    goto LAB_97bc11d8;
  case 0x25:
    break;
  case 0x38:
    param_4 = iVar18;
    __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_i
              (param_2,local_48,ppPVar19,iVar18);
    if (0 < iVar18) {
      puVar24 = local_d0;
      iVar20 = iVar18;
      ppPVar12 = ppPVar19;
      do {
        pPVar25 = *ppPVar12;
        ppPVar12 = ppPVar12 + 1;
        TPPStreamCompiler__getOperandAsSourceVar
                  ((unsigned char *)&local_90,param_2,pPVar25,param_4,param_5,a5,iVar6,a7);
        ppuVar5 = local_90;
        iVar20 = iVar20 + -1;
        puVar24[5] = local_8c;
        puVar24[4] = (uint)ppuVar5;
        puVar24 = puVar24 + 2;
      } while (iVar20 != 0);
    }
    goto LAB_97bc11d8;
  case 0x48:
  case 0x49:
    param_4 = iVar18;
    __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_i
              (param_2,local_48,ppPVar19,iVar18);
    if (0 < iVar18) {
      puVar24 = local_d0 + iVar18 * 2;
      iVar20 = iVar18;
      ppPVar12 = ppPVar19;
      do {
        pPVar25 = *ppPVar12;
        ppPVar12 = ppPVar12 + 1;
        TPPStreamCompiler__getOperandAsSourceVar
                  ((unsigned char *)&local_90,param_2,pPVar25,param_4,param_5,a5,iVar6,a7);
        ppuVar5 = local_90;
        iVar20 = iVar20 + -1;
        puVar24[3] = local_8c;
        puVar24[2] = (uint)ppuVar5;
        puVar24 = puVar24 + -2;
      } while (iVar20 != 0);
    }
    goto LAB_97bc11d8;
  case 0x66:
  case 0x67:
  case 0x68:
  case 0x69:
  case 0x6a:
  case 0x6b:
  case 0x6c:
  case 0x6d:
  case 0x6e:
  case 0x6f:
  case 0x70:
  case 0x71:
  case 0x72:
  case 0x73:
  case 0x74:
  case 0x75:
    pTVar10 = (unsigned char *)(**(code **)(*(int *)this + 0x3c))(this);
    local_48[0] = (unsigned char *)TPPStreamCompiler__construct(param_2,pTVar10,ppPVar19,iVar18);
    break;
  case 0x85:
    iVar18 = 2;
    local_d0[0] = local_d0[0] & 0x1fffffff | 0x40000000;
    ppPVar19 = (unsigned char **)_malloc(8);
    pPVar25 = (unsigned char *)TPPStreamCompiler__getVertex(param_2);
    ppPVar19[1] = pPVar25;
    pPVar25 = (unsigned char *)TPPStreamCompiler__getMVP(param_2);
    *ppPVar19 = pPVar25;
    TPPStreamCompiler__getOperandAsSourceVar
              ((unsigned char *)&local_90,param_2,pPVar25,param_4,param_5,a5,iVar6,a7);
    local_c0 = local_90;
    local_bc = local_8c;
    TPPStreamCompiler__getOperandAsSourceVar
              ((unsigned char *)&local_90,param_2,ppPVar19[1],param_4,param_5,a5,iVar6,a7);
    local_b8 = local_90;
    local_b4 = local_8c;
    goto LAB_97bc11d8;
  case 0x8a:
  case 0x8b:
  case 0x8e:
  case 0x8f:
  case 0x92:
  case 0x93:
  case 0x96:
  case 0x98:
  case 0x99:
  case 0x9a:
  case 0x9b:
    if (iVar18 == 3) {
      switch(a5) {
      case 0x8a:
      case 0x8e:
      case 0x92:
      case 0x96:
      case 0x98:
      case 0x99:
        iVar6 = 0x44;
        break;
      case 0x8b:
      case 0x8f:
      case 0x93:
      case 0x9a:
      case 0x9b:
        iVar6 = 0x45;
        break;
      default:
        goto switchD_97bc03dc_caseD_8c;
      }
      local_d0[0] = iVar6 << 0x12 | local_d0[0] & 0xfc03ffff;
    }
  case 0x8c:
  case 0x8d:
  case 0x90:
  case 0x91:
  case 0x94:
  case 0x95:
  case 0x97:
  case 0x9c:
  case 0x9d:
  case 0x9e:
  case 0x9f:
  case 0xa0:
  case 0xa1:
  case 0xa2:
  case 0xa3:
switchD_97bc03dc_caseD_8c:
    uVar17 = a5 - 0x8a;
    iVar6 = 4;
    uVar15 = uVar17;
    if (uVar17 < 0x1a) {
      uVar15 = uVar17 * 4;
      switch(uVar17) {
      default:
        iVar6 = 4;
        break;
      case 4:
      case 5:
      case 6:
      case 7:
        iVar6 = 3;
        break;
      case 8:
      case 9:
      case 10:
      case 0xb:
        iVar6 = 1;
        break;
      case 0xc:
      case 0xd:
        iVar6 = 0;
        break;
      case 0xe:
      case 0x10:
      case 0x12:
      case 0x14:
        iVar6 = 7;
        break;
      case 0xf:
      case 0x11:
      case 0x13:
      case 0x15:
        iVar6 = 6;
        break;
      case 0x16:
      case 0x17:
        iVar6 = 2;
        break;
      case 0x18:
      case 0x19:
        iVar6 = 5;
      }
    }
    param_4 = iVar18;
    __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_i
              (param_2,local_48,ppPVar19,iVar18);
    if (bVar1) {
      TPPStreamCompiler__getOperandAsSourceVar
                ((unsigned char *)&local_90,param_2,ppPVar19[1],param_4,param_5,a5,uVar15,a7);
      local_c0 = local_90;
      local_bc = local_8c;
      TPPStreamCompiler__getOperandAsSourceVar
                ((unsigned char *)&local_90,param_2,*ppPVar19,param_4,param_5,a5,uVar15,a7);
      local_b0 = iVar6 << 5 | local_b0 & 0xffffff1f;
      local_b8 = local_90;
      local_b4 = local_8c;
      if (iVar18 == 3) {
        TPPStreamCompiler__getOperandAsSourceVar
                  ((unsigned char *)&local_90,param_2,ppPVar19[2],param_4,param_5,a5,local_b0,a7);
        local_a8 = local_90;
        local_a4 = local_8c;
      }
    }
    local_d0[0] = (iVar18 + 1) * 0x20000000 | local_d0[0] & 0x1fffffff;
LAB_97bc11d8:
    TPPStreamCompiler__getOperandAsDestVar
              ((unsigned char *)&local_90,param_2,local_48[0],param_4,param_5,a5);
    local_c8 = local_90;
    local_c4 = local_8c;
    if ((*(int *)(this + 0x30) == 0x4c) || (*(int *)(this + 0x30) == 0x4d)) {
      local_d0[1] = ((uint)local_c0 >> 0xe & 1) << 0x1c | local_d0[1] & 0xefffffff;
      iVar6 = *(int *)*ppPVar19;
      if (iVar6 == 0) {
        uVar3 = *(ushort *)(*ppPVar19 + 0x18);
      }
      else {
        uVar3 = *(ushort *)(iVar6 + 0x2c);
      }
      uVar15 = GetPPStreamTypeForGLType((uint)uVar3);
      local_d0[1] = (uVar15 & 7) << 0x17 | local_d0[1] & 0xfc7fffff;
      pPVar25 = *ppPVar19;
    }
    else {
      local_d0[1] = ((uint)local_90 >> 0xc & 1) << 0x1c | local_d0[1] & 0xefffffff;
      if (*(int *)local_48[0] == 0) {
        uVar3 = *(ushort *)(local_48[0] + 0x18);
      }
      else {
        uVar3 = *(ushort *)(*(int *)local_48[0] + 0x2c);
      }
      uVar15 = GetPPStreamTypeForGLType((uint)uVar3);
      local_d0[1] = (uVar15 & 7) << 0x17 | local_d0[1] & 0xfc7fffff;
      pPVar25 = local_48;
    }
    iVar6 = ParseOperand__GetLogicalSize(pPVar25);
    local_d0[1] = (iVar6 + -1) * 0x4000000 & 0xc000000U | local_d0[1] & 0xf3ffffff;
    TPPStreamCompiler__AddOperation(param_2,local_48,(unsigned char *)local_d0,(char *)0x0,0);
  }
switchD_97bc03dc_caseD_25:
  if (*(int *)(this + 0x30) != 4) {
    ppPVar12 = ppPVar19;
    if (0 < iVar18) {
      do {
        pPVar25 = *ppPVar12;
        if ((pPVar25 != (unsigned char *)0x0) && (pPVar25 != local_48[0])) {
          __ZN12ParseOperandD1Ev(pPVar25);
          __ZdlPv(pPVar25);
        }
        iVar18 = iVar18 + -1;
        ppPVar12 = ppPVar12 + 1;
      } while (iVar18 != 0);
    }
    if (ppPVar19 != (unsigned char **)0x0) {
      _free(ppPVar19);
    }
  }
  return local_48[0];
}

/* TIntermSelection__compileNode @ 0x97bc1348 (2232 bytes) */
int TIntermSelection__compileNode(this, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  unsigned char * this;
  unsigned char * param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 *param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  bool bVar1;
  ushort uVar2;
  bool bVar3;
  int *piVar4;
  unsigned char * pTVar5;
  unsigned char * pPVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined4 a1;
  int a1_00;
  int extraout_r4;
  int extraout_r4_00;
  undefined4 a1_01;
  int extraout_r4_01;
  int extraout_r4_02;
  int extraout_r4_03;
  int extraout_r4_04;
  int a1_02;
  int extraout_r4_05;
  int extraout_r4_06;
  char *pcVar10;
  undefined4 *a6;
  undefined4 uVar11;
  int iVar12;
  int iVar13;
  char *a2;
  uint uVar14;
  undefined8 uVar15;
  char acStack_f0 [32];
  char acStack_d0 [32];
  uint local_b0;
  uint local_ac;
  undefined **local_a8;
  undefined4 local_a4;
  undefined **local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  uint local_80;
  uint local_7c;
  undefined **local_70;
  undefined4 local_6c;
  uint local_4c;
  unsigned char * local_40;
  unsigned char * local_3c;
  unsigned char * local_38 [3];
  
  pcVar10 = *(char **)(param_2 + 0x8c);
  a2 = "gl__IfEnd_";
  *(char **)(param_2 + 0x8c) = pcVar10 + 1;
  local_38[0] = (unsigned char *)0x0;
  local_40 = (unsigned char *)0x0;
  local_3c = (unsigned char *)0x0;
  iVar12 = *(int *)(param_2 + 0x70);
  _sprintf(acStack_f0,"%s%d","gl__IfElse_",pcVar10);
  _sprintf(acStack_d0,"%s%d",(int)"gl__IfEnd_",(int)pcVar10);
  bVar3 = false;
  iVar13 = 1;
  (**(code **)(*(int *)this + 0x38))((unsigned char *)&local_70,this);
  local_70 = &PTR___ZN5TTypeD1Ev_a7b7d730;
  if ((local_4c & 0x1f80000) != 0) {
    pTVar5 = (unsigned char *)(**(code **)(*(int *)this + 0x3c))
                                (this,a1,a2,pcVar10,param_5,param_6,local_4c & 0x1f80000);
    local_40 = (unsigned char *)TPPStreamCompiler__newTemporary(param_2,pTVar5);
  }
  pPVar6 = (unsigned char *)
           (**(code **)(**(int **)(this + 0x30) + 0xc))(*(int **)(this + 0x30),param_2);
  ((int (*)())ParseSymbolTable__processOperand)(*(unsigned char **)(param_2 + 0x68),pPVar6);
  piVar4 = *(int **)(pPVar6 + 4);
  if (piVar4 != (int *)0x0) {
    iVar13 = *piVar4;
  }
  uVar14 = (uint)(piVar4 != (int *)0x0);
  bVar1 = uVar14 == 0;
  iVar8 = a1_00;
  if (bVar1) {
    local_ac = 0;
    a6 = *(undefined4 **)this;
    local_88 = 0;
    local_84 = 0;
    local_a8 = (undefined **)0x0;
    local_a4 = 0;
    local_a0 = (undefined **)0x0;
    local_9c = 0;
    local_98 = 0;
    local_94 = 0;
    local_90 = 0;
    local_8c = 0;
    local_b0 = 0x21540000;
    local_80 = uVar14;
    local_7c = uVar14;
    local_80 = (*(code *)*a6)(this,a1_00,a2,pcVar10,param_5,param_6,a6);
    TPPStreamCompiler__getOperandAsSourceVar
              ((unsigned char *)&local_70,param_2,pPVar6,pcVar10,param_5,param_6,a6,param_8);
    local_ac = ((uint)local_70 >> 0xe & 1) << 0x1c | local_ac & 0xefffffff;
    local_9c = local_6c;
    local_a0 = local_70;
    if (*(int *)pPVar6 == 0) {
      uVar2 = *(ushort *)(pPVar6 + 0x18);
    }
    else {
      uVar2 = *(ushort *)(*(int *)pPVar6 + 0x2c);
    }
    uVar7 = GetPPStreamTypeForGLType((uint)uVar2);
    local_ac = (uVar7 & 7) << 0x17 | local_ac & 0xfc7fffff;
    iVar8 = ParseOperand__GetLogicalSize(pPVar6);
    local_ac = (iVar8 + -1) * 0x4000000 & 0xc000000U | local_ac & 0xf3ffffff;
    local_7c = _strlen(acStack_f0);
    a2 = (char *)&local_b0;
    pcVar10 = acStack_f0;
    param_5 = 0;
    TPPStreamCompiler__AddOperation(param_2,(unsigned char **)0x0,(unsigned char *)a2,pcVar10,0)
    ;
    iVar8 = extraout_r4;
  }
  if ((*(int *)(this + 0x34) != 0) && ((uVar14 != 1 || (iVar13 != 0)))) {
    iVar9 = TPPStreamCompiler__LastOperationIndex(param_2);
    local_3c = (unsigned char *)
               (**(code **)(**(int **)(this + 0x34) + 0xc))(*(int **)(this + 0x34),param_2);
    ((int (*)())ParseSymbolTable__processOperand)(*(unsigned char **)(param_2 + 0x68),local_3c);
    iVar8 = extraout_r4_00;
    if (bVar1) {
      uVar15 = TPPStreamCompiler__LastOperationIndex(param_2);
      iVar8 = (int)uVar15;
      if ((((int)((ulonglong)uVar15 >> 0x20) - iVar9 == 1) && (local_40 == (unsigned char *)0x0)) &&
         (*(int *)(this + 0x38) == 0)) {
        iVar8 = *(int *)(*(int *)(iVar12 + 0x20) + 4);
        if ((*(uint *)(iVar8 + 0xc) & 0x3fc0000) == 0x13c0000) {
          _PPStreamChunkListRemoveChunk(*(int *)(iVar12 + 0x20),iVar8);
          _PPStreamChunkListRemoveChunk
                    (*(int *)(iVar12 + 0x20),*(undefined4 *)(*(int *)(iVar12 + 0x20) + 4));
          uVar11 = 0x4f;
          local_ac = 0;
          local_88 = 0;
          local_84 = 0;
          local_a8 = (undefined **)0x0;
          local_a4 = 0;
          local_a0 = (undefined **)0x0;
          local_9c = 0;
          local_98 = 0;
          local_94 = 0;
          local_90 = 0;
          local_8c = 0;
          local_b0 = 0x13c0000;
          local_80 = uVar14;
          local_7c = uVar14;
          local_80 = (*(code *)**(undefined4 **)this)(this,a1_01,a2,pcVar10,param_5,param_6,0x4f);
          local_b0 = local_b0 & 0x1fffffff | 0x20000000;
          *(undefined4 *)(pPVar6 + 0x28) = 1;
          TPPStreamCompiler__getOperandAsSourceVar
                    ((unsigned char *)&local_70,param_2,pPVar6,pcVar10,param_5,param_6,uVar11,param_8
                    );
          local_ac = ((uint)local_70 >> 0xe & 1) << 0x1c | local_ac & 0xefffffff;
          local_9c = local_6c;
          local_a0 = local_70;
          if (*(int *)pPVar6 == 0) {
            uVar2 = *(ushort *)(pPVar6 + 0x18);
          }
          else {
            uVar2 = *(ushort *)(*(int *)pPVar6 + 0x2c);
          }
          uVar7 = GetPPStreamTypeForGLType((uint)uVar2);
          local_ac = (uVar7 & 7) << 0x17 | local_ac & 0xfc7fffff;
          iVar8 = ParseOperand__GetLogicalSize(pPVar6);
          local_ac = (iVar8 + -1) * 0x4000000 & 0xc000000U | local_ac & 0xf3ffffff;
          a2 = (char *)&local_b0;
          pcVar10 = (char *)0x0;
          param_5 = 0;
          TPPStreamCompiler__AddOperation
                    (param_2,(unsigned char **)0x0,(unsigned char *)a2,(char *)0x0,0);
          bVar3 = true;
          __ZN12ParseOperandD1Ev(pPVar6);
          __ZdlPv(pPVar6);
          iVar8 = extraout_r4_01;
          pPVar6 = local_3c;
          goto LAB_97bc18ac;
        }
      }
    }
    if (pPVar6 != (unsigned char *)0x0) {
      __ZN12ParseOperandD1Ev(pPVar6);
      __ZdlPv(pPVar6);
      iVar8 = extraout_r4_02;
    }
    pPVar6 = local_3c;
    if (local_40 != (unsigned char *)0x0) {
      uVar11 = 0;
      param_8 = 0;
      local_ac = 0;
      param_6 = *(undefined4 **)this;
      local_88 = 0;
      local_84 = 0;
      local_7c = 0;
      local_a8 = (undefined **)0x0;
      local_a4 = 0;
      local_a0 = (undefined **)0x0;
      local_9c = 0;
      local_98 = 0;
      local_94 = 0;
      local_90 = 0;
      local_8c = 0;
      local_80 = 0;
      local_b0 = 0x20000000;
      local_80 = (*(code *)*param_6)(this,iVar8,a2,pcVar10,param_5,param_6,0,0);
      __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_
                (param_2,&local_40,&local_3c);
      TPPStreamCompiler__getOperandAsDestVar
                ((unsigned char *)&local_70,param_2,local_40,pcVar10,param_5,param_6);
      local_a8 = local_70;
      local_a4 = local_6c;
      TPPStreamCompiler__getOperandAsSourceVar
                ((unsigned char *)&local_70,param_2,local_3c,pcVar10,param_5,param_6,uVar11,param_8);
      local_ac = ((uint)local_a8 >> 0xc & 1) << 0x1c | local_ac & 0xefffffff;
      local_a0 = local_70;
      local_9c = local_6c;
      if (*(int *)local_40 == 0) {
        uVar2 = *(ushort *)(local_40 + 0x18);
      }
      else {
        uVar2 = *(ushort *)(*(int *)local_40 + 0x2c);
      }
      uVar7 = GetPPStreamTypeForGLType((uint)uVar2);
      local_ac = (uVar7 & 7) << 0x17 | local_ac & 0xfc7fffff;
      iVar8 = ParseOperand__GetLogicalSize(local_40);
      local_ac = (iVar8 + -1) * 0x4000000 & 0xc000000U | local_ac & 0xf3ffffff;
      a2 = (char *)&local_b0;
      pcVar10 = (char *)0x0;
      param_5 = 0;
      TPPStreamCompiler__AddOperation(param_2,&local_40,(unsigned char *)a2,(char *)0x0,0);
      iVar8 = extraout_r4_03;
      pPVar6 = local_3c;
    }
  }
LAB_97bc18ac:
  if (pPVar6 != (unsigned char *)0x0) {
    __ZN12ParseOperandD1Ev(pPVar6);
    __ZdlPv(pPVar6);
    iVar8 = extraout_r4_04;
  }
  piVar4 = *(int **)(this + 0x38);
  if ((piVar4 != (int *)0x0) && ((uVar14 != 1 || (iVar13 != 1)))) {
    if (bVar1) {
      local_ac = 0;
      local_88 = 0;
      local_84 = 0;
      local_a8 = (undefined **)0x0;
      local_a4 = 0;
      local_a0 = (undefined **)0x0;
      local_9c = 0;
      local_98 = 0;
      local_94 = 0;
      local_90 = 0;
      local_8c = 0;
      local_b0 = 0x1600000;
      local_80 = uVar14;
      local_7c = uVar14;
      local_80 = (*(code *)**(undefined4 **)this)(this,iVar8,a2,pcVar10,param_5,param_6,0x58);
      local_7c = _strlen(acStack_d0);
      param_5 = 0;
      pcVar10 = acStack_d0;
      TPPStreamCompiler__AddOperation
                (param_2,(unsigned char **)0x0,(unsigned char *)&local_b0,acStack_d0,0);
      a2 = (char *)_strlen(acStack_f0);
      _PPStreamAddLabel(iVar12,acStack_f0,a2);
      piVar4 = *(int **)(this + 0x38);
    }
    local_38[0] = (unsigned char *)(**(code **)(*piVar4 + 0xc))(piVar4,param_2);
    ((int (*)())ParseSymbolTable__processOperand)(*(unsigned char **)(param_2 + 0x68),local_38[0]);
    iVar8 = a1_02;
    if (local_40 != (unsigned char *)0x0) {
      local_ac = 0;
      uVar11 = 0;
      local_80 = 0;
      local_7c = 0;
      local_88 = 0;
      local_84 = 0;
      local_a8 = (undefined **)0x0;
      local_a4 = 0;
      local_a0 = (undefined **)0x0;
      local_9c = 0;
      local_98 = 0;
      local_94 = 0;
      local_90 = 0;
      local_8c = 0;
      local_b0 = 0;
      local_80 = (*(code *)**(undefined4 **)this)(this,a1_02,a2,pcVar10,param_5,param_6,0);
      local_b0 = local_b0 & 0x1fffffff | 0x20000000;
      __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_
                (param_2,&local_40,local_38);
      TPPStreamCompiler__getOperandAsDestVar
                ((unsigned char *)&local_70,param_2,local_40,pcVar10,param_5,param_6);
      local_a8 = local_70;
      local_a4 = local_6c;
      TPPStreamCompiler__getOperandAsSourceVar
                ((unsigned char *)&local_70,param_2,local_38[0],pcVar10,param_5,param_6,uVar11,
                 param_8);
      local_ac = ((uint)local_a8 >> 0xc & 1) << 0x1c | local_ac & 0xefffffff;
      local_a0 = local_70;
      local_9c = local_6c;
      if (*(int *)local_40 == 0) {
        uVar2 = *(ushort *)(local_40 + 0x18);
      }
      else {
        uVar2 = *(ushort *)(*(int *)local_40 + 0x2c);
      }
      uVar7 = GetPPStreamTypeForGLType((uint)uVar2);
      local_ac = (uVar7 & 7) << 0x17 | local_ac & 0xfc7fffff;
      iVar13 = ParseOperand__GetLogicalSize(local_40);
      local_ac = (iVar13 + -1) * 0x4000000 & 0xc000000U | local_ac & 0xf3ffffff;
      a2 = (char *)&local_b0;
      pcVar10 = (char *)0x0;
      param_5 = 0;
      TPPStreamCompiler__AddOperation(param_2,&local_40,(unsigned char *)a2,(char *)0x0,0);
      iVar8 = extraout_r4_05;
    }
    pPVar6 = local_38;
    if (local_38[0] != (unsigned char *)0x0) {
      __ZN12ParseOperandD1Ev(local_38[0]);
      __ZdlPv(pPVar6);
      iVar8 = extraout_r4_06;
    }
  }
  if ((!bVar3) && (bVar1)) {
    local_ac = 0;
    local_88 = 0;
    local_84 = 0;
    local_a8 = (undefined **)0x0;
    local_a4 = 0;
    local_a0 = (undefined **)0x0;
    local_9c = 0;
    local_98 = 0;
    local_94 = 0;
    local_90 = 0;
    local_8c = 0;
    local_b0 = 0x1640000;
    local_80 = uVar14;
    local_7c = uVar14;
    local_80 = (*(code *)**(undefined4 **)this)(this,iVar8,a2,pcVar10,param_5,param_6,0x1640000);
    TPPStreamCompiler__AddOperation
              (param_2,(unsigned char **)0x0,(unsigned char *)&local_b0,(char *)0x0,0);
    pcVar10 = acStack_f0;
    if (*(int *)(this + 0x38) != 0) {
      pcVar10 = acStack_d0;
    }
    uVar11 = _strlen(pcVar10);
    pcVar10 = acStack_f0;
    if (*(int *)(this + 0x38) != 0) {
      pcVar10 = acStack_d0;
    }
    _PPStreamAddLabel(iVar12,pcVar10,uVar11);
  }
  return local_40;
}

/* TIntermLoop__compileNode @ 0x97bc1c00 (3000 bytes) */
int TIntermLoop__compileNode(this, param_2, param_3, param_4, param_5, param_6)
  unsigned char * this;
  unsigned char * param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  ushort uVar1;
  int iVar2;
  unsigned char * pPVar3;
  undefined4 uVar4;
  int *piVar5;
  unsigned char * pTVar6;
  uint uVar7;
  int iVar8;
  void *pvVar9;
  undefined4 a1;
  undefined4 a1_00;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 a1_01;
  undefined4 a1_02;
  undefined4 extraout_r4_01;
  undefined4 extraout_r4_02;
  undefined4 a1_03;
  undefined4 a1_04;
  unsigned char * p_Var10;
  char *pcVar11;
  undefined4 uVar12;
  char *a5;
  undefined4 uVar13;
  undefined4 uVar14;
  int *piVar15;
  int iVar16;
  int iVar17;
  undefined8 uVar18;
  char acStack_130 [32];
  char acStack_110 [32];
  char acStack_f0 [32];
  char acStack_d0 [32];
  undefined4 local_b0;
  uint local_ac;
  uint local_a8;
  undefined4 local_a4;
  uint local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  int local_80;
  int local_7c;
  uint local_70;
  undefined4 local_6c;
  unsigned char * local_60;
  unsigned char * local_5c [6];
  
  iVar17 = *(int *)(param_2 + 0x8c);
  a5 = "gl__WhileEndIf_";
  iVar16 = *(int *)(param_2 + 0x70);
  *(int *)(param_2 + 0x8c) = iVar17 + 1;
  local_60 = (unsigned char *)0x0;
  local_5c[0] = (unsigned char *)0x0;
  piVar15 = *(int **)(iVar16 + 0x20);
  if ((((*(int *)(param_2 + 0xc4) < 2) || (*(int *)(this + 0xc) != 0)) || (*(int *)(this + 8) != 0))
     || (*(int *)(this + 0x10) != 0)) {
    _sprintf(acStack_130,"%s%d","gl__WhileBody_",iVar17);
    _sprintf(acStack_110,"%s%d","gl__WhileEnd_",iVar17);
    _sprintf(acStack_f0,"%s%d","gl__WhileStart_",iVar17);
    _sprintf(acStack_d0,"%s%d","gl__WhileEndIf_");
    pcVar11 = acStack_110;
    ParseWhileLoopStack__push((unsigned char *)(param_2 + 0x5c),acStack_130,acStack_110);
    local_ac = 0;
    local_88 = 0;
    local_84 = 0;
    local_a8 = 0;
    local_a4 = 0;
    local_a0 = 0;
    local_9c = 0;
    local_98 = 0;
    local_94 = 0;
    local_90 = 0;
    local_8c = 0;
    local_7c = 0;
    local_b0 = 0x1a80000;
    local_80 = 0;
    local_80 = (*(code *)**(undefined4 **)this)(this,a1,pcVar11,iVar17,param_5,a5,0x1a80000);
    local_7c = _strlen(acStack_110);
    uVar12 = 0;
    pcVar11 = acStack_110;
    TPPStreamCompiler__AddOperation
              (param_2,(unsigned char **)0x0,(unsigned char *)&local_b0,acStack_110,0);
    iVar17 = 0;
    for (iVar8 = *piVar15; iVar8 != 0; iVar8 = *(int *)(iVar8 + 8)) {
      iVar17 = iVar8;
    }
    uVar4 = _strlen(acStack_f0);
    _PPStreamAddLabel(iVar16,acStack_f0,uVar4);
    if ((*(int *)(this + 0x14) != 0) && (piVar5 = *(int **)(this + 0xc), piVar5 != (int *)0x0)) {
      local_5c[0] = (unsigned char *)(**(code **)(*piVar5 + 0xc))(piVar5,param_2);
      ((int (*)())ParseSymbolTable__processOperand)(*(unsigned char **)(param_2 + 0x68),local_5c[0]);
      pTVar6 = (unsigned char *)(**(code **)(**(int **)(this + 0xc) + 0x3c))(*(int **)(this + 0xc));
      uVar18 = TPPStreamCompiler__newTemporary(param_2,pTVar6);
      local_60 = (unsigned char *)((ulonglong)uVar18 >> 0x20);
      uVar13 = 0;
      uVar14 = 0;
      local_ac = 0;
      local_88 = 0;
      local_84 = 0;
      local_a8 = 0;
      local_a4 = 0;
      local_a0 = 0;
      local_9c = 0;
      local_98 = 0;
      local_94 = 0;
      local_90 = 0;
      local_8c = 0;
      local_7c = 0;
      local_b0 = 0x20280000;
      local_80 = 0;
      local_80 = (*(code *)**(undefined4 **)this)(this,(int)uVar18,uVar4,pcVar11,uVar12,a5,0,0);
      __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_
                (param_2,&local_60,local_5c);
      TPPStreamCompiler__getOperandAsDestVar
                ((unsigned char *)&local_70,param_2,local_60,pcVar11,uVar12,a5);
      local_a8 = local_70;
      local_a4 = local_6c;
      TPPStreamCompiler__getOperandAsSourceVar
                ((unsigned char *)&local_70,param_2,local_5c[0],pcVar11,uVar12,a5,uVar13,uVar14);
      local_ac = (local_a8 >> 0xc & 1) << 0x1c | local_ac & 0xefffffff;
      local_a0 = local_70;
      local_9c = local_6c;
      if (*(int *)local_60 == 0) {
        uVar1 = *(ushort *)(local_60 + 0x18);
      }
      else {
        uVar1 = *(ushort *)(*(int *)local_60 + 0x2c);
      }
      uVar7 = GetPPStreamTypeForGLType((uint)uVar1);
      local_ac = (uVar7 & 7) << 0x17 | local_ac & 0xfc7fffff;
      iVar8 = ParseOperand__GetLogicalSize(local_60);
      local_ac = (iVar8 + -1) * 0x4000000 & 0xc000000U | local_ac & 0xf3ffffff;
      uVar12 = 0;
      uVar4 = 0;
      p_Var10 = (unsigned char *)&local_b0;
      TPPStreamCompiler__AddOperation
                (param_2,&local_60,(unsigned char *)&local_b0,(char *)0x0,0);
      uVar13 = 0;
      uVar14 = 0;
      local_ac = 0;
      local_88 = 0;
      local_84 = 0;
      local_7c = 0;
      local_b0 = 0x21540000;
      local_a8 = 0;
      local_a4 = 0;
      local_a0 = 0;
      local_9c = 0;
      local_98 = 0;
      local_94 = 0;
      local_90 = 0;
      local_8c = 0;
      local_80 = 0;
      local_80 = (*(code *)**(undefined4 **)this)(this,a1_00,p_Var10,uVar12,uVar4,a5,0,0);
      TPPStreamCompiler__getOperandAsSourceVar
                ((unsigned char *)&local_70,param_2,local_60,uVar12,uVar4,a5,uVar13,uVar14);
      local_ac = (local_70 >> 0xe & 1) << 0x1c | local_ac & 0xefffffff;
      local_9c = local_6c;
      local_a0 = local_70;
      if (*(int *)local_60 == 0) {
        uVar1 = *(ushort *)(local_60 + 0x18);
      }
      else {
        uVar1 = *(ushort *)(*(int *)local_60 + 0x2c);
      }
      uVar7 = GetPPStreamTypeForGLType((uint)uVar1);
      local_ac = (uVar7 & 7) << 0x17 | local_ac & 0xfc7fffff;
      iVar8 = ParseOperand__GetLogicalSize(local_60);
      local_ac = (iVar8 + -1) * 0x4000000 & 0xc000000U | local_ac & 0xf3ffffff;
      local_7c = _strlen(acStack_d0);
      uVar4 = 0;
      p_Var10 = (unsigned char *)&local_b0;
      pcVar11 = acStack_d0;
      TPPStreamCompiler__AddOperation
                (param_2,(unsigned char **)0x0,(unsigned char *)&local_b0,acStack_d0,0);
      pPVar3 = local_60;
      uVar12 = extraout_r4;
      if (local_60 != (unsigned char *)0x0) {
        __ZN12ParseOperandD1Ev(local_60);
        __ZdlPv(pPVar3);
        uVar12 = extraout_r4_00;
      }
      local_ac = 0;
      local_b0 = 0x1500000;
      local_a8 = 0;
      local_a4 = 0;
      local_a0 = 0;
      local_9c = 0;
      local_98 = 0;
      local_94 = 0;
      local_90 = 0;
      local_8c = 0;
      local_88 = 0;
      local_84 = 0;
      local_80 = 0;
      local_7c = 0;
      local_80 = (*(code *)**(undefined4 **)this)
                           (this,uVar12,p_Var10,pcVar11,uVar4,a5,*(undefined4 **)this);
      local_7c = _strlen(acStack_110);
      uVar12 = 0;
      p_Var10 = (unsigned char *)&local_b0;
      pcVar11 = acStack_110;
      TPPStreamCompiler__AddOperation
                (param_2,(unsigned char **)0x0,(unsigned char *)&local_b0,acStack_110,0);
      local_ac = 0;
      local_b0 = 0x1640000;
      local_88 = 0;
      local_84 = 0;
      local_a8 = 0;
      local_a4 = 0;
      local_a0 = 0;
      local_9c = 0;
      local_98 = 0;
      local_94 = 0;
      local_90 = 0;
      local_8c = 0;
      local_7c = 0;
      local_80 = 0;
      local_80 = (*(code *)**(undefined4 **)this)
                           (this,a1_01,p_Var10,pcVar11,uVar12,a5,*(undefined4 **)this);
      pcVar11 = (char *)0x0;
      uVar12 = 0;
      TPPStreamCompiler__AddOperation
                (param_2,(unsigned char **)0x0,(unsigned char *)&local_b0,(char *)0x0,0);
      uVar4 = _strlen(acStack_d0);
      _PPStreamAddLabel(iVar16,acStack_d0,uVar4);
      pPVar3 = local_5c;
      if (local_5c[0] != (unsigned char *)0x0) {
        __ZN12ParseOperandD1Ev(local_5c[0]);
        __ZdlPv(pPVar3);
      }
    }
    piVar5 = *(int **)(this + 8);
    if ((piVar5 != (int *)0x0) &&
       (pvVar9 = (void *)(**(code **)(*piVar5 + 0xc))(piVar5,param_2), pvVar9 != (void *)0x0)) {
      __ZN12ParseOperandD1Ev(pvVar9);
      __ZdlPv(pvVar9);
    }
    uVar4 = _strlen(acStack_130);
    _PPStreamAddLabel(iVar16,acStack_130,uVar4);
    piVar5 = *(int **)(this + 0x10);
    if ((piVar5 != (int *)0x0) &&
       (pvVar9 = (void *)(**(code **)(*piVar5 + 0xc))(piVar5,param_2), pvVar9 != (void *)0x0)) {
      __ZN12ParseOperandD1Ev(pvVar9);
      __ZdlPv(pvVar9);
    }
    iVar8 = *(int *)(this + 0x14);
    if ((iVar8 == 0) && (piVar5 = *(int **)(this + 0xc), piVar5 != (int *)0x0)) {
      local_5c[0] = (unsigned char *)(**(code **)(*piVar5 + 0xc))(piVar5,param_2);
      ((int (*)())ParseSymbolTable__processOperand)(*(unsigned char **)(param_2 + 0x68),local_5c[0]);
      pTVar6 = (unsigned char *)(**(code **)(**(int **)(this + 0xc) + 0x3c))(*(int **)(this + 0xc));
      uVar18 = TPPStreamCompiler__newTemporary(param_2,pTVar6);
      local_60 = (unsigned char *)((ulonglong)uVar18 >> 0x20);
      uVar13 = 0;
      uVar14 = 0;
      local_ac = 0;
      local_88 = 0;
      local_84 = 0;
      local_a8 = 0;
      local_a4 = 0;
      local_a0 = 0;
      local_9c = 0;
      local_98 = 0;
      local_94 = 0;
      local_90 = 0;
      local_8c = 0;
      local_b0 = 0x20280000;
      local_80 = iVar8;
      local_7c = iVar8;
      local_80 = (*(code *)**(undefined4 **)this)(this,(int)uVar18,uVar4,pcVar11,uVar12,a5,0,0);
      __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_
                (param_2,&local_60,local_5c);
      TPPStreamCompiler__getOperandAsDestVar
                ((unsigned char *)&local_70,param_2,local_60,pcVar11,uVar12,a5);
      local_a8 = local_70;
      local_a4 = local_6c;
      TPPStreamCompiler__getOperandAsSourceVar
                ((unsigned char *)&local_70,param_2,local_5c[0],pcVar11,uVar12,a5,uVar13,uVar14);
      local_ac = (local_a8 >> 0xc & 1) << 0x1c | local_ac & 0xefffffff;
      local_a0 = local_70;
      local_9c = local_6c;
      if (*(int *)local_60 == 0) {
        uVar1 = *(ushort *)(local_60 + 0x18);
      }
      else {
        uVar1 = *(ushort *)(*(int *)local_60 + 0x2c);
      }
      uVar7 = GetPPStreamTypeForGLType((uint)uVar1);
      local_ac = (uVar7 & 7) << 0x17 | local_ac & 0xfc7fffff;
      iVar8 = ParseOperand__GetLogicalSize(local_60);
      local_ac = (iVar8 + -1) * 0x4000000 & 0xc000000U | local_ac & 0xf3ffffff;
      uVar12 = 0;
      uVar4 = 0;
      p_Var10 = (unsigned char *)&local_b0;
      TPPStreamCompiler__AddOperation
                (param_2,&local_60,(unsigned char *)&local_b0,(char *)0x0,0);
      uVar13 = 0;
      uVar14 = 0;
      local_ac = 0;
      local_88 = 0;
      local_84 = 0;
      local_7c = 0;
      local_b0 = 0x21540000;
      local_a8 = 0;
      local_a4 = 0;
      local_a0 = 0;
      local_9c = 0;
      local_98 = 0;
      local_94 = 0;
      local_90 = 0;
      local_8c = 0;
      local_80 = 0;
      local_80 = (*(code *)**(undefined4 **)this)(this,a1_02,p_Var10,uVar12,uVar4,a5,0,0);
      TPPStreamCompiler__getOperandAsSourceVar
                ((unsigned char *)&local_70,param_2,local_60,uVar12,uVar4,a5,uVar13,uVar14);
      local_ac = (local_70 >> 0xe & 1) << 0x1c | local_ac & 0xefffffff;
      local_9c = local_6c;
      local_a0 = local_70;
      if (*(int *)local_60 == 0) {
        uVar1 = *(ushort *)(local_60 + 0x18);
      }
      else {
        uVar1 = *(ushort *)(*(int *)local_60 + 0x2c);
      }
      uVar7 = GetPPStreamTypeForGLType((uint)uVar1);
      local_ac = (uVar7 & 7) << 0x17 | local_ac & 0xfc7fffff;
      iVar8 = ParseOperand__GetLogicalSize(local_60);
      local_ac = (iVar8 + -1) * 0x4000000 & 0xc000000U | local_ac & 0xf3ffffff;
      local_7c = _strlen(acStack_d0);
      uVar4 = 0;
      p_Var10 = (unsigned char *)&local_b0;
      pcVar11 = acStack_d0;
      TPPStreamCompiler__AddOperation
                (param_2,(unsigned char **)0x0,(unsigned char *)&local_b0,acStack_d0,0);
      pPVar3 = local_60;
      uVar12 = extraout_r4_01;
      if (local_60 != (unsigned char *)0x0) {
        __ZN12ParseOperandD1Ev(local_60);
        __ZdlPv(pPVar3);
        uVar12 = extraout_r4_02;
      }
      local_ac = 0;
      local_b0 = 0x1500000;
      local_a8 = 0;
      local_a4 = 0;
      local_a0 = 0;
      local_9c = 0;
      local_98 = 0;
      local_94 = 0;
      local_90 = 0;
      local_8c = 0;
      local_88 = 0;
      local_84 = 0;
      local_80 = 0;
      local_7c = 0;
      local_80 = (*(code *)**(undefined4 **)this)
                           (this,uVar12,p_Var10,pcVar11,uVar4,a5,*(undefined4 **)this);
      local_7c = _strlen(acStack_110);
      uVar12 = 0;
      p_Var10 = (unsigned char *)&local_b0;
      pcVar11 = acStack_110;
      TPPStreamCompiler__AddOperation
                (param_2,(unsigned char **)0x0,(unsigned char *)&local_b0,acStack_110,0);
      local_ac = 0;
      local_b0 = 0x1640000;
      local_88 = 0;
      local_84 = 0;
      local_a8 = 0;
      local_a4 = 0;
      local_a0 = 0;
      local_9c = 0;
      local_98 = 0;
      local_94 = 0;
      local_90 = 0;
      local_8c = 0;
      local_7c = 0;
      local_80 = 0;
      local_80 = (*(code *)**(undefined4 **)this)
                           (this,a1_03,p_Var10,pcVar11,uVar12,a5,*(undefined4 **)this);
      pcVar11 = (char *)0x0;
      uVar12 = 0;
      TPPStreamCompiler__AddOperation
                (param_2,(unsigned char **)0x0,(unsigned char *)&local_b0,(char *)0x0,0);
      uVar4 = _strlen(acStack_d0);
      _PPStreamAddLabel(iVar16,acStack_d0,uVar4);
      pPVar3 = local_5c;
      if (local_5c[0] != (unsigned char *)0x0) {
        __ZN12ParseOperandD1Ev(local_5c[0]);
        __ZdlPv(pPVar3);
      }
    }
    ParseWhileLoopStack__pop((unsigned char *)(param_2 + 0x5c));
    iVar8 = 0;
    for (iVar2 = iVar17; iVar2 != 0; iVar2 = *(int *)(iVar2 + 8)) {
      iVar8 = iVar2;
    }
    if ((*(int *)(param_2 + 0xc4) < 2) || (iVar8 != iVar17)) {
      local_ac = 0;
      local_88 = 0;
      local_84 = 0;
      local_a8 = 0;
      local_a4 = 0;
      local_a0 = 0;
      local_9c = 0;
      local_98 = 0;
      local_94 = 0;
      local_90 = 0;
      local_8c = 0;
      local_7c = 0;
      local_b0 = 0x1ac0000;
      local_80 = 0;
      local_80 = (*(code *)**(undefined4 **)this)
                           (this,a1_04,uVar4,pcVar11,uVar12,a5,0x1ac0000,*(undefined4 **)this);
      local_7c = _strlen(acStack_f0);
      TPPStreamCompiler__AddOperation
                (param_2,(unsigned char **)0x0,(unsigned char *)&local_b0,acStack_f0,0);
      uVar12 = _strlen(acStack_110);
      _PPStreamAddLabel(iVar16,acStack_110,uVar12);
    }
    else {
      _PPStreamChunkListRemoveChunk(piVar15,iVar8);
      iVar17 = 0;
      for (iVar8 = **(int **)(iVar16 + 0x24); iVar8 != 0; iVar8 = *(int *)(iVar8 + 8)) {
        iVar17 = iVar8;
      }
      _PPStreamChunkListRemoveChunk(*(int **)(iVar16 + 0x24),iVar17);
    }
  }
  return 0;
}

/* TIntermBranch__compileNode @ 0x97bc27b8 (1420 bytes) */
int TIntermBranch__compileNode(this, param_2, param_3, param_4, param_5, param_6)
  unsigned char * this;
  unsigned char * param_2;
  unsigned char ** param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  ushort uVar1;
  int iVar2;
  unsigned char * pPVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 a1;
  undefined4 extraout_r4_01;
  undefined4 extraout_r4_02;
  undefined4 extraout_r4_03;
  char *pcVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  unsigned char ** ppPVar11;
  unsigned char * this_00;
  undefined8 uVar12;
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
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_70;
  undefined4 local_6c;
  undefined **local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  uint local_3c;
  undefined4 local_30;
  unsigned char * local_2c;
  unsigned char * local_28;
  unsigned char * local_24;
  
  local_24 = (unsigned char *)0x0;
  local_b0 = 0;
  local_ac = 0;
  local_a8 = 0;
  local_a4 = 0;
  local_a0 = 0;
  local_9c = 0;
  local_98 = 0;
  local_94 = 0;
  local_90 = 0;
  local_8c = 0;
  local_88 = 0;
  local_84 = 0;
  local_80 = 0;
  local_7c = 0;
  local_80 = (*(code *)**(undefined4 **)this)(this);
  piVar8 = *(int **)(this + 0xc);
  local_b0 = local_b0 & 0x1fffffff;
  uVar5 = extraout_r4;
  if (piVar8 != (int *)0x0) {
    local_24 = (unsigned char *)
               (**(code **)(*piVar8 + 0xc))(piVar8,param_2,param_3,param_4,param_5,param_6,piVar8);
    ((int (*)())ParseSymbolTable__processOperand)(*(unsigned char **)(param_2 + 0x68),local_24);
    uVar5 = extraout_r4_00;
  }
  iVar4 = *(int *)(this + 8);
  if (iVar4 == 99) {
    this_00 = (unsigned char *)(param_2 + 0x58);
    iVar10 = 0;
    pcVar7 = (char *)ParseFunctionStack__current(this_00);
    iVar4 = ParseFunctionStack__getCurrentNumParams(this_00);
    uVar12 = ParseFunctionStack__getCurrentParamList(this_00);
    iVar6 = (int)((ulonglong)uVar12 >> 0x20);
    uVar5 = (undefined4)uVar12;
    local_b0 = local_b0 & 0xfc03ffff;
    if (0 < iVar4) {
      do {
        iVar2 = iVar10 * 4;
        ppPVar11 = (unsigned char **)(iVar2 + iVar6);
        if ((*(int **)(iVar2 + iVar6) != (int *)0x0) &&
           ((piVar8 = *(int **)(**(int **)(iVar2 + iVar6) + 0xc), iVar9 = *piVar8,
            iVar9 = (**(code **)(iVar9 + 0x24))(piVar8,uVar5,param_3,param_4,param_5,param_6,iVar9),
            iVar9 == 10 ||
            (piVar8 = *(int **)(**(int **)(iVar2 + iVar6) + 0xc),
            iVar9 = (**(code **)(*piVar8 + 0x24))
                              (piVar8,a1,param_3,param_4,param_5,param_6,**(int **)(iVar2 + iVar6)),
            uVar5 = extraout_r4_01, iVar9 == 0xb)))) {
          local_2c = (unsigned char *)
                     TPPStreamCompiler__newParam
                               (param_2,*(unsigned char **)(**(int **)(iVar2 + iVar6) + 0xc),pcVar7,iVar10);
          param_4 = 0;
          TPPStreamCompiler__assignOperands(param_2,&local_2c,ppPVar11,0);
          pPVar3 = local_2c;
          uVar5 = extraout_r4_02;
          param_3 = ppPVar11;
          if (local_2c != (unsigned char *)0x0) {
            __ZN12ParseOperandD1Ev(local_2c);
            __ZdlPv(pPVar3);
            uVar5 = extraout_r4_03;
            param_3 = ppPVar11;
          }
        }
        iVar10 = iVar10 + 1;
      } while (iVar10 < iVar4);
    }
    if (local_24 != (unsigned char *)0x0) {
      if (*(int *)(local_24 + 4) == 0) {
        local_28 = (unsigned char *)
                   TPPStreamCompiler__newReturnValue
                             ((unsigned char *)param_2,*(char **)(*(int *)local_24 + 0xc),pcVar7);
      }
      else {
        iVar4 = 0;
        if (*(int *)local_24 == 0) {
          uVar1 = *(ushort *)(local_24 + 0x18);
        }
        else {
          uVar1 = *(ushort *)(*(int *)local_24 + 0x2c);
        }
        if (uVar1 == 0x1406) {
          iVar4 = 1;
        }
        else if (uVar1 < 0x1407) {
          if (uVar1 == 0x1404) {
            iVar4 = 2;
          }
        }
        else if (uVar1 == 0x8b56) {
          iVar4 = 3;
        }
        local_3c = iVar4 << 0x13 | local_3c & 0x9ff | 0x800;
        local_60 = &PTR___ZN5TTypeD1Ev_a7b7d730;
        local_5c = 0;
        local_58 = 0;
        local_54 = 0;
        local_50 = 0;
        local_4c = 0;
        local_48 = 0;
        local_44 = 0;
        local_40 = 0;
        local_28 = (unsigned char *)
                   TPPStreamCompiler__newReturnValue((unsigned char *)param_2,(char *)&local_60,pcVar7);
        local_60 = &PTR___ZN5TTypeD1Ev_a7b7d730;
      }
      TPPStreamCompiler__assignOperands(param_2,&local_28,&local_24,0);
      pPVar3 = local_24;
      if (local_24 != (unsigned char *)0x0) {
        __ZN12ParseOperandD1Ev(local_24);
        __ZdlPv(pPVar3);
      }
      pPVar3 = local_28;
      if (local_28 != (unsigned char *)0x0) {
        __ZN12ParseOperandD1Ev(local_28);
        __ZdlPv(pPVar3);
      }
    }
    local_ac = 0;
    pcVar7 = (char *)0x0;
    local_88 = 0;
    local_84 = 0;
    local_7c = 0;
    local_b0 = 0x1340000;
    local_a8 = 0;
    local_a4 = 0;
    local_a0 = 0;
    local_9c = 0;
    local_98 = 0;
    local_94 = 0;
    local_90 = 0;
    local_8c = 0;
    local_80 = 0;
  }
  else if (iVar4 < 100) {
    if (iVar4 != 0x62) {
      return 0;
    }
    local_ac = 0;
    local_88 = 0;
    local_84 = 0;
    local_b0 = 0x13c0000;
    local_a8 = 0;
    local_a4 = 0;
    local_a0 = 0;
    local_9c = 0;
    local_98 = 0;
    local_94 = 0;
    local_90 = 0;
    local_8c = 0;
    local_7c = 0;
    local_80 = 0;
    local_80 = (*(code *)**(undefined4 **)this)
                         (this,uVar5,param_3,param_4,param_5,param_6,*(undefined4 **)this);
    local_b0 = local_b0 & 0x1fffffff | 0x20000000;
    local_30 = 0xbf800000;
    TPPStreamCompiler__getConstantAsSourceVar
              ((unsigned char *)&local_70,(uint)param_2,&local_30,1,0x1406);
    local_ac = local_ac & 0xfc7fffff | 0x800000;
    pcVar7 = (char *)0x0;
    local_a0 = local_70;
    local_9c = local_6c;
  }
  else if (iVar4 == 100) {
    local_ac = 0;
    local_b0 = 0x1500000;
    local_88 = 0;
    local_84 = 0;
    local_a8 = 0;
    local_a4 = 0;
    local_a0 = 0;
    local_9c = 0;
    local_98 = 0;
    local_94 = 0;
    local_90 = 0;
    local_8c = 0;
    local_7c = 0;
    local_80 = 0;
    local_80 = (*(code *)**(undefined4 **)this)
                         (this,uVar5,param_3,param_4,param_5,param_6,*(undefined4 **)this);
    uVar5 = ParseWhileLoopStack__breakLabel((unsigned char *)(param_2 + 0x5c));
    local_7c = _strlen(uVar5);
    pcVar7 = (char *)ParseWhileLoopStack__breakLabel((unsigned char *)(param_2 + 0x5c));
  }
  else {
    if (iVar4 != 0x65) {
      return 0;
    }
    local_ac = 0;
    local_b0 = 0x1a40000;
    local_88 = 0;
    local_84 = 0;
    local_a8 = 0;
    local_a4 = 0;
    local_a0 = 0;
    local_9c = 0;
    local_98 = 0;
    local_94 = 0;
    local_90 = 0;
    local_8c = 0;
    local_7c = 0;
    local_80 = 0;
    local_80 = (*(code *)**(undefined4 **)this)
                         (this,uVar5,param_3,param_4,param_5,param_6,*(undefined4 **)this);
    uVar5 = ParseWhileLoopStack__continueLabel((unsigned char *)(param_2 + 0x5c));
    local_7c = _strlen(uVar5);
    pcVar7 = (char *)ParseWhileLoopStack__continueLabel((unsigned char *)(param_2 + 0x5c));
  }
  TPPStreamCompiler__AddOperation
            (param_2,(unsigned char **)0x0,(unsigned char *)&local_b0,pcVar7,0);
  return 0;
}

/* TIntermSymbol__indirectNode @ 0x97bc2d44 (312 bytes) */
int TIntermSymbol__indirectNode(this, param_2, param_3, param_4, param_5, param_6)
  unsigned char * this;
  unsigned char * param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  undefined1 *puVar1;
  int iVar2;
  undefined4 uVar3;
  unsigned char * this_00;
  unsigned char * pTVar4;
  undefined4 a1;
  int a6;
  undefined4 *this_01;
  
  this_01 = (undefined4 *)0x0;
  iVar2 = (**(code **)(*(int *)this + 0x60))(this);
  puVar1 = DAT_a7b7bd0c;
  a6 = *(int *)(iVar2 + 4);
  *(undefined1 *)(a6 + *(int *)(a6 + -0xc)) = *DAT_a7b7bd0c;
  if (**(char **)(iVar2 + 4) != '\0') {
    uVar3 = (*(code *)**(undefined4 **)this)(this,a1,param_3,param_4,param_5,param_6,a6);
    *(undefined4 *)(param_2 + 0x90) = uVar3;
    this_00 = operator_new(100);
    __ZN11ParseSymbolC1Ev(this_00);
    iVar2 = (**(code **)(*(int *)this + 0x60))(this);
    *(undefined1 *)(*(int *)(iVar2 + 4) + *(int *)(*(int *)(iVar2 + 4) + -0xc)) = *puVar1;
    ParseSymbol__SetName(this_00,*(char **)(iVar2 + 4));
    uVar3 = (**(code **)(*(int *)this + 0x5c))(this);
    *(undefined4 *)(this_00 + 0x28) = uVar3;
    pTVar4 = (unsigned char *)(**(code **)(*(int *)this + 0x3c))(this);
    ParseSymbol__SetParseTreeType(this_00,pTVar4);
    uVar3 = (**(code **)(*(int *)this + 0x3c))(this);
    *(undefined4 *)(this_00 + 0x10) = uVar3;
    this_01 = operator_new(0x38);
    __ZN12ParseOperandC1Ev(this_01);
    *this_01 = this_00;
  }
  return this_01;
}

/* TIntermConstantUnion__indirectNode @ 0x97bc2e7c (340 bytes) */
int TIntermConstantUnion__indirectNode(this, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  unsigned char * this;
  unsigned char * param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  int iVar1;
  uint uVar2;
  undefined2 uVar3;
  void *this_00;
  undefined4 uVar4;
  undefined **local_50 [9];
  uint local_2c;
  
  this_00 = operator_new(0x38);
  __ZN12ParseOperandC1Ev(this_00);
  uVar4 = (*(code *)**(undefined4 **)this)(this);
  *(undefined4 *)(param_2 + 0x90) = uVar4;
  (**(code **)(*(int *)this + 0x38))(local_50,this);
  if ((local_2c & 0x400) == 0) {
    iVar1 = (int)(local_2c << 0xd | local_2c >> 0x13) >> 0x18;
  }
  else {
    iVar1 = (int)(local_2c << 0xd | local_2c >> 0x13) >> 0x18;
    iVar1 = iVar1 * iVar1;
  }
  *(int *)((int)this_00 + 0x24) = iVar1;
  local_50[0] = &PTR___ZN5TTypeD1Ev_a7b7d778;
  *(undefined4 *)((int)this_00 + 4) = *(undefined4 *)(this + 0x30);
  (**(code **)(*(int *)this + 0x38))(local_50,this);
  local_50[0] = &PTR___ZN5TTypeD1Ev_a7b7d778;
  uVar2 = local_2c >> 0x13 & 0x3f;
  if (uVar2 == 2) {
    uVar3 = 0x1404;
LAB_97bc2f80:
    *(undefined2 *)((int)this_00 + 0x18) = uVar3;
  }
  else {
    if (uVar2 < 3) {
      if (uVar2 == 1) {
        uVar3 = 0x1406;
        goto LAB_97bc2f80;
      }
    }
    else {
      if (uVar2 == 3) {
        uVar3 = 0x8b56;
        goto LAB_97bc2f80;
      }
      if (uVar2 == 0xe) {
        TPPStreamCompiler__error
                  (param_2,(char *)0x1,(char *)0x0,
                   "TIntermConstantUnion::indirectNode: EbtStruct constant union type, investigate",
                   param_5,param_6,param_7,param_8);
      }
    }
    TPPStreamCompiler__error
              (param_2,(char *)0x1,(char *)0x0,
               "TIntermConstantUnion::indirectNode: Unexpected constant union type",param_5,param_6,
               param_7,param_8);
  }
  return this_00;
}

/* TIntermBinary__indirectNode @ 0x97bc2fd0 (1000 bytes) */
int TIntermBinary__indirectNode(this, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  unsigned char * this;
  unsigned char * param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  unsigned char * pPVar5;
  unsigned char * pTVar6;
  unsigned char * pPVar7;
  unsigned char * this_00;
  int iVar8;
  uint *puVar9;
  void *this_01;
  unsigned char * this_02;
  uint uVar10;
  undefined **local_60 [2];
  int local_58;
  undefined **local_50;
  uint local_4c;
  
  this_02 = (unsigned char *)0x0;
  this_01 = (void *)0x0;
  uVar3 = (*(code *)**(undefined4 **)this)(this);
  *(undefined4 *)(param_2 + 0x90) = uVar3;
  piVar4 = *(int **)(this + 0x34);
  if (piVar4 != (int *)0x0) {
    this_02 = (unsigned char *)(**(code **)(*piVar4 + 0x10))(piVar4,param_2);
  }
  piVar4 = *(int **)(this + 0x38);
  if (piVar4 != (int *)0x0) {
    this_01 = (void *)(**(code **)(*piVar4 + 0x10))(piVar4,param_2);
  }
  bVar1 = this_02 == (unsigned char *)0x0;
  pPVar7 = (unsigned char *)0x0;
  if (bVar1) goto LAB_97bc3364;
  iVar2 = *(int *)(this + 0x30);
  if (iVar2 == 0x2d) {
    uVar10 = **(uint **)((int)this_01 + 4);
    pPVar7 = this_02;
    if (*(int *)(*(unsigned char **)this_02 + 0x4c) == 0) goto LAB_97bc3364;
    ParseSymbol__AddDirectIndex(*(unsigned char **)this_02,uVar10);
    _sprintf((char *)local_60,"[%d]",uVar10);
    ParseSymbol__CatName(*(unsigned char **)this_02,(char *)local_60);
    iVar2 = (**(code **)(*(int *)this + 0x54))(this);
    if (iVar2 != 0) {
      TPPStreamCompiler__error
                (param_2,(char *)0x1,(char *)0x0,
                 "TIntermBinary::: Array index results in another array, this is not handled",
                 param_5,param_6,param_7,param_8);
      goto LAB_97bc3364;
    }
    pPVar5 = *(unsigned char **)this_02;
    *(undefined4 *)(pPVar5 + 0x48) = 1;
  }
  else {
    if (iVar2 == 0x2e) {
      if (*(int *)this_02 == 0) {
        pTVar6 = (unsigned char *)(**(code **)(**(int **)(this + 0x34) + 0x3c))(*(int **)(this + 0x34));
        pPVar7 = (unsigned char *)
                 TPPStreamCompiler__newIndirectOperandFromConstant(param_2,this_02,pTVar6);
        __ZN12ParseOperandD1Ev(this_02);
        __ZdlPv(this_02);
        bVar1 = pPVar7 == (unsigned char *)0x0;
        this_02 = pPVar7;
      }
      else {
        if (*(int *)(*(int *)this_02 + 0x4c) == 0) {
          piVar4 = (int *)(**(code **)(**(int **)(this + 0x34) + 0x3c))(*(int **)(this + 0x34));
          iVar2 = (**(code **)(*piVar4 + 0x34))(piVar4);
          pPVar7 = this_02;
          if (iVar2 == 0) goto LAB_97bc3364;
          this_00 = *(unsigned char **)(param_2 + 0x68);
          *(undefined4 *)(param_2 + 0xa8) = 1;
        }
        else {
          (**(code **)(**(int **)(this + 0x34) + 0x38))(&local_50,*(int **)(this + 0x34));
          *(undefined4 *)(param_2 + 0xa8) = 1;
          local_50 = &PTR___ZN5TTypeD1Ev_a7b7d778;
          ((int (*)())ParseSymbolTable__processOperand)(*(unsigned char **)(param_2 + 0x68),this_02);
          ParseSymbol__AddDirectIndex(*(unsigned char **)this_02,local_4c);
          _sprintf((char *)local_60,"[%d]",0);
          ParseSymbol__CatName(*(unsigned char **)this_02,(char *)local_60);
          iVar2 = (**(code **)(*(int *)this + 0x54))(this);
          if (iVar2 == 0) {
            pPVar5 = *(unsigned char **)this_02;
            *(undefined4 *)(pPVar5 + 0x48) = 1;
            ParseSymbol__ResolveOpenGLType(pPVar5);
          }
          this_00 = *(unsigned char **)(param_2 + 0x68);
        }
        ((int (*)())ParseSymbolTable__processOperand)(this_00,this_02);
        pPVar7 = this_02;
      }
      goto LAB_97bc3364;
    }
    if (iVar2 != 0x2f) goto LAB_97bc3364;
    pPVar5 = *(unsigned char **)this_02;
    (**(code **)(**(int **)(this + 0x34) + 0x38))(local_60,*(int **)(this + 0x34));
    local_60[0] = &PTR___ZN5TTypeD1Ev_a7b7d778;
    puVar9 = *(uint **)((int)this_01 + 4);
    uVar10 = *puVar9;
    if (pPVar5 == (unsigned char *)0x0) {
      TPPStreamCompiler__error
                (param_2,(char *)0x1,(char *)0x0,
                 "TIntermBinary::indirectNode: Structure symbol, parse error.",param_5,param_6,
                 puVar9,param_8);
    }
    if (local_58 == 0) {
      TPPStreamCompiler__error
                (param_2,(char *)0x1,(char *)0x0,
                 "TIntermBinary::indirectNode: No structure fields, parse error.",param_5,param_6,
                 puVar9,param_8);
    }
    if ((uint)(*(int *)(local_58 + 8) - *(int *)(local_58 + 4) >> 3) <= uVar10) {
      TPPStreamCompiler__error
                (param_2,(char *)0x1,(char *)0x0,
                 "TIntermBinary::indirectNode: Structure index too big for field size, parse error",
                 param_5,param_6,puVar9,param_8);
    }
    iVar2 = uVar10 * 8;
    ParseSymbol__CatName(pPVar5,".");
    piVar4 = *(int **)(*(int *)(local_58 + 4) + iVar2);
    iVar8 = (**(code **)(*piVar4 + 0x1c))(piVar4);
    *(undefined1 *)(*(int *)(iVar8 + 4) + *(int *)(*(int *)(iVar8 + 4) + -0xc)) = *DAT_a7b7bd0c;
    ParseSymbol__CatName(pPVar5,*(char **)(iVar8 + 4));
    ParseSymbol__SetParseTreeType(pPVar5,*(unsigned char **)(*(int *)(local_58 + 4) + iVar2));
    pPVar5 = *(unsigned char **)this_02;
    *(undefined4 *)(pPVar5 + 0x48) = 0;
  }
  ParseSymbol__ResolveOpenGLType(pPVar5);
  pPVar7 = this_02;
LAB_97bc3364:
  if (this_01 != (void *)0x0) {
    __ZN12ParseOperandD1Ev(this_01);
    __ZdlPv(this_01);
  }
  if ((!bVar1) && (pPVar7 != this_02)) {
    __ZN12ParseOperandD1Ev(this_02);
    __ZdlPv(this_02);
  }
  return pPVar7;
}

/* TIntermUnary__indirectNode @ 0x97bc33b8 (112 bytes) */
int TIntermUnary__indirectNode(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  undefined4 uVar1;
  void *this_00;
  
  uVar1 = (*(code *)**(undefined4 **)this)(this);
  *(undefined4 *)(param_2 + 0x90) = uVar1;
  this_00 = (void *)(**(code **)(**(int **)(this + 0x34) + 0x10))(*(int **)(this + 0x34),param_2);
  if (this_00 != (void *)0x0) {
    __ZN12ParseOperandD1Ev(this_00);
    __ZdlPv(this_00);
  }
  return 0;
}

/* TIntermAggregate__indirectNode @ 0x97bc3428 (232 bytes) */
int TIntermAggregate__indirectNode(this, param_2, param_3, param_4, param_5, param_6)
  unsigned char * this;
  unsigned char * param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  void *this_00;
  
  iVar3 = *(int *)(this + 0x3c) - *(int *)(this + 0x38) >> 2;
  uVar1 = (*(code *)**(undefined4 **)this)(this,param_2,param_3,param_4,param_5,param_6,this + 0x34)
  ;
  *(undefined4 *)(param_2 + 0x90) = uVar1;
  puVar2 = (undefined4 *)_malloc(iVar3 << 2);
  puVar4 = puVar2;
  for (puVar5 = *(undefined4 **)(this + 0x38); puVar5 != *(undefined4 **)(this + 0x3c);
      puVar5 = puVar5 + 1) {
    uVar1 = (**(code **)(*(int *)*puVar5 + 0x10))((int *)*puVar5,param_2);
    *puVar4 = uVar1;
    puVar4 = puVar4 + 1;
  }
  puVar4 = puVar2;
  if (0 < iVar3) {
    do {
      this_00 = (void *)*puVar4;
      if (this_00 != (void *)0x0) {
        __ZN12ParseOperandD1Ev(this_00);
        __ZdlPv(this_00);
      }
      iVar3 = iVar3 + -1;
      puVar4 = puVar4 + 1;
    } while (iVar3 != 0);
  }
  if (puVar2 != (undefined4 *)0x0) {
    _free(puVar2);
  }
  return 0;
}

/* TIntermSelection__indirectNode @ 0x97bc3510 (204 bytes) */
int TIntermSelection__indirectNode(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  void *pvVar1;
  int *piVar2;
  
  piVar2 = (int *)0x0;
  if (*(int *)(this + 0x34) != 0) {
    pvVar1 = (void *)(**(code **)(**(int **)(this + 0x30) + 0x10))(*(int **)(this + 0x30));
    if (pvVar1 != (void *)0x0) {
      __ZN12ParseOperandD1Ev(pvVar1);
      __ZdlPv(pvVar1);
    }
    piVar2 = *(int **)(this + 0x34);
  }
  if (piVar2 != (int *)0x0) {
    pvVar1 = (void *)(**(code **)(*piVar2 + 0x10))(piVar2,param_2);
    if (pvVar1 != (void *)0x0) {
      __ZN12ParseOperandD1Ev(pvVar1);
      __ZdlPv(pvVar1);
    }
  }
  piVar2 = *(int **)(this + 0x38);
  if ((piVar2 != (int *)0x0) &&
     (pvVar1 = (void *)(**(code **)(*piVar2 + 0x10))(piVar2,param_2), pvVar1 != (void *)0x0)) {
    __ZN12ParseOperandD1Ev(pvVar1);
    __ZdlPv(pvVar1);
  }
  return 0;
}

/* TIntermLoop__indirectNode @ 0x97bc35dc (200 bytes) */
int TIntermLoop__indirectNode(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  int *piVar1;
  void *pvVar2;
  
  piVar1 = *(int **)(this + 0xc);
  if (piVar1 != (int *)0x0) {
    pvVar2 = (void *)(**(code **)(*piVar1 + 0x10))(piVar1);
    if (pvVar2 != (void *)0x0) {
      __ZN12ParseOperandD1Ev(pvVar2);
      __ZdlPv(pvVar2);
    }
  }
  piVar1 = *(int **)(this + 8);
  if (piVar1 != (int *)0x0) {
    pvVar2 = (void *)(**(code **)(*piVar1 + 0x10))(piVar1,param_2);
    if (pvVar2 != (void *)0x0) {
      __ZN12ParseOperandD1Ev(pvVar2);
      __ZdlPv(pvVar2);
    }
  }
  piVar1 = *(int **)(this + 0x10);
  if ((piVar1 != (int *)0x0) &&
     (pvVar2 = (void *)(**(code **)(*piVar1 + 0x10))(piVar1,param_2), pvVar2 != (void *)0x0)) {
    __ZN12ParseOperandD1Ev(pvVar2);
    __ZdlPv(pvVar2);
  }
  return 0;
}

/* TIntermBranch__indirectNode @ 0x97bc36a4 (88 bytes) */
int TIntermBranch__indirectNode(param_1)
  unsigned char * param_1;
{
  int *a0;
  void *this;
  
  a0 = *(int **)(param_1 + 0xc);
  if ((a0 != (int *)0x0) && (this = (void *)(**(code **)(*a0 + 0x10))(a0), this != (void *)0x0)) {
    __ZN12ParseOperandD1Ev(this);
    __ZdlPv(this);
  }
  return 0;
}

/* __ZN22ConstantAllocationListC2Ev @ 0x97bc36fc (4 bytes) */
int __ZN22ConstantAllocationListC2Ev(this)
  void *this;
{
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)this = 0;
  return;
}

/* __ZN22ConstantAllocationListC1Ev @ 0x97bc3700 (4 bytes) */
int __ZN22ConstantAllocationListC1Ev(this)
  void *this;
{
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)this = 0;
  return;
}

/* __ZN22ConstantAllocationListC4Ev @ 0x97bc3704 (16 bytes) */
int __ZN22ConstantAllocationListC4Ev(this)
  void *this;
{
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)this = 0;
  return;
}

/* __ZN22ConstantAllocationListD2Ev @ 0x97bc3714 (8 bytes) */
int __ZN22ConstantAllocationListD2Ev(this)
  void *this;
{
  ((int (*)())__ZN22ConstantAllocationListD4Ev)(this);
  return;
}

/* __ZN22ConstantAllocationListD1Ev @ 0x97bc371c (8 bytes) */
int __ZN22ConstantAllocationListD1Ev(this)
  void *this;
{
  ((int (*)())__ZN22ConstantAllocationListD4Ev)(this);
  return;
}

/* __ZN22ConstantAllocationListD4Ev @ 0x97bc3724 (16 bytes) */
int __ZN22ConstantAllocationListD4Ev(this)
  void *this;
{
  if (*(int *)this == 0) {
    return;
  }
  _free(*(int *)this);
  return;
}

/* ConstantAllocationList__clear @ 0x97bc3734 (68 bytes) */
int ConstantAllocationList__clear(this)
  unsigned char * this;
{
  if (*(int *)this != 0) {
    _free(*(int *)this);
  }
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)this = 0;
  return;
}

/* ConstantAllocationList__addConstant @ 0x97bc3778 (320 bytes) */
int ConstantAllocationList__addConstant(this, param_2, param_3, param_4)
  unsigned char * this;
  int param_2;
  bool *param_3;
  int param_4;
{
  bool *pbVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  uint uVar11;
  
  uVar11 = *(uint *)(this + 4);
  if ((uVar11 & 0xf) == 0) {
    iVar3 = _malloc(uVar11 * 0x18 + 0x180);
    _memset(iVar3,0,*(int *)(this + 4) * 0x18 + 0x180);
    uVar11 = *(uint *)(this + 4);
    iVar5 = 0;
    if ((int)uVar11 < 1) {
      iVar4 = *(int *)this;
    }
    else {
      iVar4 = *(int *)this;
      iVar6 = 0;
      do {
        iVar10 = iVar6 + iVar4;
        uVar8 = *(undefined4 *)(iVar10 + 4);
        iVar5 = iVar5 + 1;
        uVar9 = *(undefined4 *)(iVar10 + 8);
        iVar2 = iVar6 + iVar3;
        uVar7 = *(undefined4 *)(iVar10 + 0xc);
        *(undefined4 *)(iVar6 + iVar3) = *(undefined4 *)(iVar6 + iVar4);
        iVar6 = iVar6 + 0x18;
        *(undefined4 *)(iVar2 + 4) = uVar8;
        *(undefined4 *)(iVar2 + 8) = uVar9;
        *(undefined4 *)(iVar2 + 0xc) = uVar7;
        uVar7 = *(undefined4 *)(iVar10 + 0x10);
        *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(iVar10 + 0x14);
        *(undefined4 *)(iVar2 + 0x10) = uVar7;
      } while (iVar5 < (int)uVar11);
    }
    if (iVar4 != 0) {
      _free(iVar4);
      uVar11 = *(uint *)(this + 4);
    }
    *(int *)this = iVar3;
  }
  iVar3 = 0;
  *(int *)(uVar11 * 0x18 + *(int *)this) = param_2;
  iVar5 = 4;
  *(ushort *)(*(int *)(this + 4) * 0x18 + *(int *)this + 0x14) = param_4;
  do {
    pbVar1 = param_3 + iVar3;
    iVar4 = iVar3 + *(int *)(this + 4) * 0x18 + *(int *)this;
    iVar3 = iVar3 + 4;
    *(undefined4 *)(iVar4 + 4) = *(undefined4 *)pbVar1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  *(int *)(this + 4) = *(int *)(this + 4) + 1;
  return;
}

/* ConstantAllocationList__updateConstant @ 0x97bc38b8 (128 bytes) */
int ConstantAllocationList__updateConstant(this, param_2, param_3, param_4)
  unsigned char * this;
  int param_2;
  bool *param_3;
  uint param_4;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  iVar5 = *(int *)(this + 4);
  iVar3 = 0;
  if (0 < iVar5) {
    piVar4 = *(int **)this;
    do {
      iVar2 = *piVar4;
      piVar4 = piVar4 + 6;
      if (param_2 == iVar2) break;
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar5);
  }
  if (iVar5 <= iVar3) {
    return;
  }
  iVar5 = *(int *)this;
  iVar2 = 0;
  if (*(ushort *)(iVar3 * 0x18 + iVar5 + 0x14) == param_4) {
    while( true ) {
      iVar1 = iVar2 * 4;
      iVar2 = iVar2 + 1;
      *(undefined4 *)(iVar1 + iVar3 * 0x18 + iVar5 + 4) = *(undefined4 *)(param_3 + iVar1);
      if (3 < iVar2) break;
      iVar5 = *(int *)this;
    }
    return;
  }
  return;
}

/* ConstantAllocationList__getConstantUsage @ 0x97bc3938 (132 bytes) */
int ConstantAllocationList__getConstantUsage(this, param_2, param_3, param_4)
  unsigned char * this;
  int param_2;
  bool *param_3;
  ushort *param_4;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar5 = *(int *)(this + 4);
  iVar2 = 0;
  if (0 < iVar5) {
    piVar3 = *(int **)this;
    do {
      iVar1 = *piVar3;
      piVar3 = piVar3 + 6;
      if (param_2 == iVar1) break;
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar5);
  }
  uVar4 = 0;
  if (iVar2 < iVar5) {
    iVar5 = 0;
    iVar1 = 4;
    *param_4 = *(ushort *)(iVar2 * 0x18 + *(int *)this + 0x14);
    do {
      uVar4 = 1;
      *(undefined4 *)(param_3 + iVar5) = *(undefined4 *)(iVar5 + iVar2 * 0x18 + *(int *)this + 4);
      iVar5 = iVar5 + 4;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return uVar4;
}

/* newQueue @ 0x97bc39bc (20 bytes) */
int newQueue(param_1)
  unsigned char * param_1;
{
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)param_1 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}

/* size @ 0x97bc39d0 (8 bytes) */
int size(param_1)
  unsigned char * param_1;
{
  return *(undefined4 *)(param_1 + 8);
}

/* store @ 0x97bc39d8 (108 bytes) */
int store(param_1, param_2)
  unsigned char * param_1;
  void *param_2;
{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)_malloc(8);
  iVar1 = *(int *)(param_1 + 8);
  *puVar2 = param_2;
  puVar2[1] = 0;
  if (iVar1 == 0) {
    *(undefined4 **)param_1 = puVar2;
    iVar1 = 0;
  }
  else {
    *(undefined4 **)(*(int *)(param_1 + 4) + 4) = puVar2;
    iVar1 = *(int *)(param_1 + 8);
  }
  *(undefined4 **)(param_1 + 4) = puVar2;
  *(int *)(param_1 + 8) = iVar1 + 1;
  return;
}

