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
  if (*(void **)(this + 0x10) != (void *)0x0) {
    _free(*(void **)(this + 0x10));
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
  size_t sVar4;
  char *pcVar5;
  char *pcVar6;
  size_t sVar7;
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
    sVar4 = _strlen(*(char **)(*(int *)this + 0x14));
    pcVar5 = _malloc(sVar4 + 1);
    _sprintf(pcVar5,DAT_a7b7bbdc,*(undefined4 *)(*(int *)this + 0x14));
    return pcVar5;
  }
  if (*(int *)(this + 4) == 0) {
    pcVar6 = _malloc(10);
    pcVar5 = DAT_a7b7bbf0;
LAB_97bbc23c:
    _sprintf(pcVar6,pcVar5);
  }
  else {
    pcVar6 = _malloc(0xa0);
    *pcVar6 = '\0';
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
        pcVar5 = DAT_a7b7bbec;
        if (sVar1 != -0x74aa) goto LAB_97bbc23c;
      }
    }
    for (uVar10 = 0; uVar8 = ParseOperand__GetBaseSize(this), uVar10 < uVar8; uVar10 = uVar10 + 1) {
      if (uVar10 != 0) {
        _sprintf(pcVar6,DAT_a7b7bbe0,pcVar6);
      }
      if (*(int *)this == 0) {
        uVar2 = *(ushort *)(this + 0x18);
      }
      else {
        uVar2 = *(ushort *)(*(int *)this + 0x2c);
      }
      if (uVar2 == 0x1406) {
        _sprintf(pcVar6,"%s ",pcVar6);
        sVar4 = _strlen(pcVar6);
        sVar7 = _strlen(pcVar6);
        iVar3 = uVar10 * 4;
        ((char * (*)())_glp_dtostr)(sVar7,extraout_r4,pcVar6 + sVar4,0x9f - sVar7,
                    (double)*(float *)(iVar3 + *(int *)(this + 4)),DOUBLE_97c30a70,in_f3,in_f4,in_f5
                    ,in_f6,in_f7,in_f8,in_stack_ffffff98,in_stack_ffffffa0,in_stack_ffffffa8,
                    in_stack_ffffffb0,in_stack_ffffffb8);
LAB_97bbc1b0:
        pcVar9 = *(char **)(iVar3 + *(int *)(this + 4));
        pcVar5 = DAT_a7b7bbe8;
LAB_97bbc1ec:
        _sprintf(pcVar6,pcVar5,pcVar6,pcVar9);
      }
      else if (uVar2 < 0x1407) {
        if (uVar2 == 0x1404) {
          iVar3 = uVar10 << 2;
          goto LAB_97bbc1b0;
        }
      }
      else if (uVar2 == 0x8b56) {
        pcVar5 = DAT_a7b7bbc4;
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
  return pcVar6;
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
  int iVar6;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  undefined4 uVar10;
  uint uVar11;
  byte *pbVar12;
  uint local_40 [6];
  
  p_Var5 = (unsigned char *)GetChunkForSymbol(param_2,*(int *)(this + 0x3c));
  *(undefined4 *)(param_2 + 4) = 0;
  *(undefined4 *)(param_2 + 8) = 0;
  ((int (*)())ParseSymbolTable__AddSymbol)(this,param_2);
  *(undefined4 *)(param_2 + 0x50) = 1;
  if (*(int *)(param_2 + 0x38) == 0) {
    uVar10 = 0;
    if ((*(int *)(param_2 + 0x58) == 0) && (*(int *)(param_2 + 0x3c) == 0)) {
      piVar7 = (int *)0x0;
      if (*(int **)(param_2 + 0xc) != (int *)0x0) {
        iVar6 = (**(code **)(**(int **)(param_2 + 0xc) + 0x24))();
        if ((((iVar6 != 0) &&
             (iVar6 = (**(code **)(**(int **)(param_2 + 0xc) + 0x24))(), iVar6 != 9)) &&
            (iVar6 = (**(code **)(**(int **)(param_2 + 0xc) + 0x24))(), iVar6 != 10)) &&
           ((iVar6 = (**(code **)(**(int **)(param_2 + 0xc) + 0x24))(), iVar6 != 0xb &&
            (iVar6 = (**(code **)(**(int **)(param_2 + 0xc) + 0x24))(), iVar6 != 0xc)))) {
          uVar10 = 1;
        }
        goto LAB_97bbc61c;
      }
    }
    else {
LAB_97bbc61c:
      piVar7 = *(int **)(param_2 + 0xc);
    }
    *(undefined4 *)(param_2 + 0x38) = uVar10;
  }
  else {
    piVar7 = *(int **)(param_2 + 0xc);
  }
  iVar6 = (**(code **)(*piVar7 + 0x24))();
  *(uint *)(param_2 + 0x60) = (uint)(iVar6 == 4);
  iVar6 = (**(code **)(**(int **)(param_2 + 0xc) + 0x24))(*(int **)(param_2 + 0xc));
  *(uint *)(param_2 + 0x5c) = (uint)(iVar6 == 5);
  *(undefined4 *)(param_2 + 0x54) = *(undefined4 *)(this + 0x50);
  uVar8 = GetVec4sForType(*(ushort *)(param_2 + 0x2c));
  ParseSymbol__SetChunk(param_2,p_Var5);
  pbVar12 = *(byte **)param_2;
  *(undefined4 *)(param_2 + 0x44) = 0;
  if (pbVar12 == (byte *)0x0) {
    return param_2;
  }
  bVar2 = *pbVar12;
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
  uVar11 = 0;
  if ((uVar8 != 0) && (iVar6 != 0)) {
    do {
      bVar1 = uVar11 != 0;
      if (bVar1) {
        pbVar12 = (byte *)_PPStreamChunkCreateFromChunk(pbVar12);
      }
      bVar2 = *pbVar12;
      if (bVar2 == 2) {
        iVar3 = *(int *)(this + 0x18);
        *(short *)(pbVar12 + 0x12) = (short)iVar3;
        *(int *)(this + 0x18) = iVar3 + 1;
        if ((*(uint *)(pbVar12 + 0xc) & 0xf0000) == 0x90000) {
          uVar9 = *(uint *)(this + 0x1c);
          *(uint *)(pbVar12 + 0xc) = uVar9 & 0x1f | *(uint *)(pbVar12 + 0xc) & 0xffffffe0;
          *(uint *)(this + 0x1c) = uVar9 + 1;
          iVar3 = GetScalerWidthForType(*(ushort *)(param_2 + 0x2c));
          *(int *)(this + 0x20) = *(int *)(this + 0x20) + iVar3;
        }
      }
      else if (bVar2 < 3) {
        if (bVar2 == 0) {
          iVar3 = *(int *)(this + 0x38);
          *(short *)(pbVar12 + 0x12) = (short)iVar3;
          *(int *)(this + 0x38) = iVar3 + 1;
          if (*(int *)(param_2 + 0x60) == 0) {
            if (*(int *)(param_2 + 0x5c) != 0) {
              uVar9 = *(uint *)(this + 0x34);
              *(uint *)(pbVar12 + 0xc) = uVar9 & 0x1f | *(uint *)(pbVar12 + 0xc) & 0xffffffe0;
              *(uint *)(this + 0x34) = uVar9 + 1;
            }
          }
          else {
            uVar9 = *(uint *)(this + 0x1c);
            *(uint *)(pbVar12 + 0xc) = uVar9 & 0x1f | *(uint *)(pbVar12 + 0xc) & 0xffffffe0;
            *(uint *)(this + 0x1c) = uVar9 + 1;
            iVar3 = GetScalerWidthForType(*(ushort *)(param_2 + 0x2c));
            *(int *)(this + 0x20) = *(int *)(this + 0x20) + iVar3;
          }
          if (*(int *)(this + 0x50) != 0) {
            pbVar12[0x14] = 0;
            pbVar12[0x15] = 0;
            pbVar12[0x16] = 0;
            pbVar12[0x17] = 1;
          }
        }
      }
      else if (bVar2 == 3) {
        iVar3 = *(int *)(this + 0x24);
        *(short *)(pbVar12 + 0x12) = (short)iVar3;
        *(int *)(this + 0x24) = iVar3 + 1;
        if (*(int *)(this + 0x50) != 0) {
          pbVar12[0x14] = 0;
          pbVar12[0x15] = 0;
          pbVar12[0x16] = 0;
          pbVar12[0x17] = 1;
        }
        uVar9 = *(uint *)(pbVar12 + 0xc) & 0x1f0000;
        if (uVar9 == 0x20000) {
          iVar3 = *(int *)(this + 0x2c);
          *(short *)(pbVar12 + 0xe) = (short)iVar3;
          *(int *)(this + 0x2c) = iVar3 + 1;
        }
        else if (uVar9 == 0x10000) {
          iVar3 = *(int *)(this + 0x28);
          *(short *)(pbVar12 + 0xe) = (short)iVar3;
          *(int *)(this + 0x28) = iVar3 + 1;
        }
        else if (uVar9 == 0x100000) {
          *(uint *)(pbVar12 + 0xc) = (uVar11 & 3) << 0xc | *(uint *)(pbVar12 + 0xc) & 0xffffcfff;
        }
      }
      else if (bVar2 == 4) {
        iVar3 = *(int *)(this + 0x30);
        *(short *)(pbVar12 + 0x12) = (short)iVar3;
        *(int *)(this + 0x30) = iVar3 + 1;
      }
      _PPStreamChunkListAddChunk(iVar6,pbVar12);
      iVar3 = *(int *)(this + 0x50);
      if (iVar3 == 0) {
LAB_97bbc990:
        if (1 < uVar8) {
          if (((bVar1) || (iVar3 == 0)) || (*(int *)(this + 0x40) != 0)) {
            if (((uVar11 == uVar8 - 1) && (iVar3 != 0)) && (*(int *)(this + 0x40) == 0)) {
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
            bVar2 = *pbVar12;
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
        uVar9 = *(uint *)(this + 0x40);
        if (((uVar9 <= *(uint *)(this + 0x44)) || (*(uint *)(this + 0x44) != 0)) || (bVar1))
        goto LAB_97bbc990;
        bVar2 = *pbVar12;
        if (bVar2 != 2) {
          if (bVar2 < 3) {
            if (bVar2 == 0) {
              local_40[1] = 0;
              local_40[0] = (uint)(ushort)(*(short *)(this + 0x3a) - 1);
              _PPStreamAddTempUsageArray(*(undefined4 *)(this + 0xc),local_40);
LAB_97bbc984:
              uVar9 = *(uint *)(this + 0x40);
            }
          }
          else if (bVar2 == 3) {
            local_40[1] = 0;
            local_40[0] = (uint)(ushort)(*(short *)(this + 0x26) - 1);
            _PPStreamAddParamBindingArray(*(undefined4 *)(this + 0xc),local_40);
            goto LAB_97bbc984;
          }
        }
        *(uint *)(this + 0x44) = uVar9;
      }
      uVar11 = uVar11 + 1;
      *(byte **)(this + 0x48) = pbVar12;
    } while (uVar11 < uVar8);
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
  uVar4 = GetVec4sForType(uVar1);
  *(undefined4 *)(this_00 + 0x28) = 0xffffffff;
  *(undefined4 *)(this_00 + 0x38) = 1;
  uVar5 = GetPPStreamTypeForGLType(uVar1);
  uVar9 = *(uint *)(p_Var3 + 0xc);
  uVar5 = (uVar5 & 7) << 0x1a;
  uVar8 = 0;
  *(uint *)(p_Var3 + 0xc) = uVar5 | uVar9 & 0xe3ffffff;
  iVar6 = GetScalerWidthForType(*(ushort *)(this_00 + 0x2c));
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
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
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
  uVar6 = GetVec4sForType(*(ushort *)(this_00 + 0x2c));
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
            iVar2 = GetScalerWidthForType(*(ushort *)(this_00 + 0x2c));
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
              iVar2 = GetScalerWidthForType(*(ushort *)(this_00 + 0x2c));
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
        if ((uVar9 == 0) && (CONCAT31(in_register_00000014,param_3) != 0)) {
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
        if ((uVar9 == uVar6 - 1) && (CONCAT31(in_register_00000018,param_4) != 0)) {
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
            iVar8 = (**(code **)(**(int **)(*(int *)(iVar3 + 4) + uVar11 * 8) + 0x1c))();
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
  size_t sVar3;
  size_t sVar4;
  char *pcVar5;
  unsigned char * pTVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  undefined4 uVar11;
  char *pcVar12;
  uint uVar13;
  char acStack_30 [16];
  
  uVar11 = 0;
  if (param_2 != (unsigned char *)0x0) {
    if (*(short *)(param_2 + 0x2c) == 0x7ffe) {
      iVar10 = *(int *)(*(int *)(param_2 + 0xc) + 8);
      if (iVar10 != 0) {
        pPVar1 = operator_new(100);
        __ZN11ParseSymbolC1Ev(pPVar1);
        iVar2 = (**(code **)(*(int *)**(undefined4 **)(iVar10 + 4) + 0x1c))();
        *(undefined1 *)(*(int *)(iVar2 + 4) + *(int *)(*(int *)(iVar2 + 4) + -0xc)) = *DAT_a7b7bcfc;
        pcVar12 = *(char **)(iVar2 + 4);
        sVar3 = _strlen(pcVar12);
        sVar3 = sVar3 + 1;
        if (*(char **)(param_2 + 0x14) != (char *)0x0) {
          sVar4 = _strlen(*(char **)(param_2 + 0x14));
          sVar3 = sVar3 + sVar4 + 1;
        }
        pcVar5 = _malloc(sVar3);
        if (*(int *)(param_2 + 0x14) == 0) {
          _strcpy(pcVar5,pcVar12);
        }
        else {
          _sprintf(pcVar5,DAT_a7b7bbf4,*(int *)(param_2 + 0x14),pcVar12);
        }
        ParseSymbol__SetName(pPVar1,pcVar5);
        iVar2 = *(int *)(param_2 + 0x3c);
        *(undefined4 *)(pPVar1 + 0x28) = *(undefined4 *)(param_2 + 0x28);
        uVar11 = 0;
        if ((iVar2 != 0) || (*(int *)(param_2 + 0x40) != 0)) {
          uVar11 = 1;
        }
        *(undefined4 *)(pPVar1 + 0x40) = uVar11;
        ParseSymbol__SetParseTreeType(pPVar1,(unsigned char *)**(undefined4 **)(iVar10 + 4));
        uVar11 = ((int (*)())ParseSymbolTable__FindFirstElement)(this,pPVar1);
        if (pPVar1 != (unsigned char *)0x0) {
          __ZN11ParseSymbolD1Ev(pPVar1);
          __ZdlPv(pPVar1);
        }
        _free(pcVar5);
      }
    }
    else if (*(short *)(param_2 + 0x2c) == 0x7fff) {
      uVar13 = 0;
      if (0 < *(int *)(*(int *)(param_2 + 0xc) + 4)) {
        do {
          pPVar1 = operator_new(100);
          __ZN11ParseSymbolC1Ev(pPVar1);
          ParseSymbol__SetName(pPVar1,*(char **)(param_2 + 0x14));
          ParseSymbol__AddDirectIndex(pPVar1,uVar13);
          _sprintf(acStack_30,DAT_a7b7bbf8,uVar13);
          ParseSymbol__CatName(pPVar1,acStack_30);
          uVar11 = *(undefined4 *)(param_2 + 0x40);
          uVar7 = *(undefined4 *)(param_2 + 0x3c);
          uVar9 = *(undefined4 *)(param_2 + 0x60);
          uVar8 = *(undefined4 *)(param_2 + 0x5c);
          pTVar6 = *(unsigned char **)(param_2 + 0xc);
          *(undefined4 *)(pPVar1 + 0x28) = *(undefined4 *)(param_2 + 0x28);
          *(undefined4 *)(pPVar1 + 0x40) = uVar11;
          *(undefined4 *)(pPVar1 + 0x3c) = uVar7;
          *(undefined4 *)(pPVar1 + 0x60) = uVar9;
          *(undefined4 *)(pPVar1 + 0x5c) = uVar8;
          ParseSymbol__SetParseTreeType(pPVar1,pTVar6);
          *(undefined4 *)(pPVar1 + 0x48) = 1;
          ParseSymbol__ResolveOpenGLType(pPVar1);
          uVar11 = ((int (*)())ParseSymbolTable__FindFirstElement)(this,pPVar1);
          if (pPVar1 != (unsigned char *)0x0) {
            __ZN11ParseSymbolD1Ev(pPVar1);
            __ZdlPv(pPVar1);
          }
          uVar13 = uVar13 + 1;
        } while ((int)uVar13 < *(int *)(*(int *)(param_2 + 0xc) + 4));
      }
    }
    else {
      uVar11 = ((int (*)())ParseSymbolTable__FindSymbol)(this,param_2);
    }
  }
  return uVar11;
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
  size_t sVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  
  iVar2 = 0;
  if (param_3 != (char *)0x0) {
    sVar1 = _strlen(param_3);
    if (param_2 == (unsigned char *)0x0) {
      iVar4 = *(int *)this;
    }
    else {
      iVar4 = *(int *)(param_2 + 8);
    }
    while ((iVar2 = 0, iVar4 != 0 &&
           (((pcVar3 = *(char **)(iVar4 + 0x14), pcVar3 == (char *)0x0 ||
             (iVar2 = _strncmp(param_3,pcVar3,sVar1), iVar2 != 0)) ||
            ((iVar2 = iVar4, *(size_t *)(iVar4 + 0x20) != sVar1 &&
             ((pcVar3[sVar1] != '.' && (pcVar3[sVar1] != '['))))))))) {
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
  uVar5 = GetVec4sForType(*(ushort *)(param_2 + 0x2c));
  pbVar8 = *(byte **)param_2;
  if (uVar5 != 0) {
    do {
      bVar1 = *pbVar8;
      if (bVar1 == 2) {
LAB_97bbdb58:
        *(int *)(this + 0x18) = *(int *)(this + 0x18) + -1;
        if ((*(uint *)(pbVar8 + 0xc) & 0xf0000) == 0x90000) {
          *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + -1;
          iVar6 = GetScalerWidthForType(*(ushort *)(param_2 + 0x2c));
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
            iVar6 = GetScalerWidthForType(*(ushort *)(param_2 + 0x2c));
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
  uVar5 = GetVec4sForType(*(ushort *)(param_2 + 0x2c));
  pbVar10 = *(byte **)param_2;
  if (uVar5 != 0) {
    do {
      bVar1 = *pbVar10;
      if (bVar1 == 2) {
        if (*(int *)(this + 0x18) - 1U != (uint)*(ushort *)(pbVar10 + 0x12)) goto LAB_97bbde78;
        *(uint *)(this + 0x18) = *(int *)(this + 0x18) - 1U;
        if ((*(uint *)(pbVar10 + 0xc) & 0xf0000) == 0x90000) {
          *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + -1;
          iVar7 = GetScalerWidthForType(*(ushort *)(param_2 + 0x2c));
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
            iVar6 = GetScalerWidthForType(*(ushort *)(param_2 + 0x2c));
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
  undefined3 in_register_00000018;
  unsigned char * this_00;
  
  this_00 = *(unsigned char **)this;
  if (this_00 != (unsigned char *)0x0) {
    do {
      if (*(unsigned char **)this_00 == param_2) {
        ParseSymbol__SetChunk(this_00,param_3);
        if (CONCAT31(in_register_00000018,param_4) != 0) {
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
    _fflush((FILE *)(puVar1 + 0x58));
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
  char *pcVar4;
  size_t sVar5;
  char *pcVar6;
  size_t sVar7;
  uint uVar8;
  int iVar9;
  char cVar10;
  int iVar11;
  uint uVar12;
  
  pPVar2 = (unsigned char *)((int (*)())ParseSymbolTable__NextSymbol)(this,(unsigned char *)0x0);
  pcVar3 = _malloc(0x800);
  uVar8 = 0x800;
  iVar11 = 0;
  cVar10 = '\x02';
  pcVar6 = (char *)0x0;
  if (pcVar3 != (char *)0x0) {
    *pcVar3 = '\0';
    pcVar6 = pcVar3;
    if (param_2 == 1) {
      uVar12 = *(uint *)(this + 0x10);
      uVar1 = 0;
      if (uVar12 != 0) {
        do {
          pPVar2 = (unsigned char *)((int (*)())ParseSymbolTable__FirstSymbolInHash)(this,uVar1);
          if (pPVar2 != (unsigned char *)0x0) {
            _sprintf(pcVar6,DAT_a7b7bc08,pcVar6,uVar1);
            sVar5 = _strlen(pcVar6);
            pcVar3 = pcVar6;
            do {
              pcVar4 = (char *)ParseSymbol__GetString(pPVar2,true);
              pcVar6 = pcVar3;
              if (pcVar4 != (char *)0x0) {
                sVar7 = _strlen(pcVar4);
                iVar11 = sVar7 + sVar5;
                uVar12 = iVar11 + 1;
                if (uVar8 < uVar12) {
                  uVar8 = 0x800;
                  if (0x800 < uVar12 >> 2) {
                    uVar8 = uVar12 >> 2;
                  }
                  uVar8 = uVar12 + uVar8;
                  pcVar6 = _malloc(uVar8);
                  if (pcVar6 == (char *)0x0) goto LAB_97bbe3d4;
                  _memmove(pcVar6,pcVar3,sVar5 + 1);
                  _free(pcVar3);
                }
                sVar5 = iVar11 + 1;
                _strcat(pcVar6,pcVar4);
                pcVar6[iVar11] = '\n';
                pcVar6[sVar5] = '\0';
                _free(pcVar4);
              }
              pPVar2 = (unsigned char *)((int (*)())ParseSymbolTable__NextSymbolInHash)(this,pPVar2);
              pcVar3 = pcVar6;
            } while (pPVar2 != (unsigned char *)0x0);
            _strcat(pcVar6,DAT_a7b7bc0c);
            uVar12 = *(uint *)(this + 0x10);
          }
          uVar1 = uVar1 + 1;
        } while (uVar1 < uVar12);
      }
    }
    else if (param_2 < 2) {
      if (param_2 == 0) {
        while (pcVar6 = pcVar3, pPVar2 != (unsigned char *)0x0) {
          pcVar4 = (char *)ParseSymbol__GetString(pPVar2,true);
          if (pcVar4 != (char *)0x0) {
            sVar5 = _strlen(pcVar4);
            iVar9 = sVar5 + iVar11;
            uVar1 = iVar9 + 1;
            if (uVar8 < uVar1) {
              uVar8 = 0x800;
              if (0x800 < uVar1 >> 2) {
                uVar8 = uVar1 >> 2;
              }
              uVar8 = uVar1 + uVar8;
              pcVar6 = _malloc(uVar8);
              if (pcVar6 == (char *)0x0) {
LAB_97bbe3d4:
                _free(pcVar3);
                _free(pcVar4);
                return (char *)0x0;
              }
              _memmove(pcVar6,pcVar3,iVar11 + 1);
              _free(pcVar3);
            }
            iVar11 = iVar9 + 1;
            _strcat(pcVar6,pcVar4);
            pcVar6[iVar9] = '\n';
            pcVar6[iVar11] = '\0';
            _free(pcVar4);
          }
          pPVar2 = (unsigned char *)((int (*)())ParseSymbolTable__NextSymbol)(this,pPVar2);
          pcVar3 = pcVar6;
        }
      }
    }
    else if (param_2 == 2) {
      _sprintf(pcVar3,DAT_a7b7bc10);
      sVar5 = _strlen(pcVar3);
      do {
        while( true ) {
          pPVar2 = (unsigned char *)((int (*)())ParseSymbolTable__NextSymbol)(this,(unsigned char *)0x0);
          while (pPVar2 != (unsigned char *)0x0) {
            pcVar6 = pcVar3;
            if ((**(char **)pPVar2 == cVar10) &&
               (pcVar4 = (char *)ParseSymbol__GetString(pPVar2,false), pcVar4 != (char *)0x0)) {
              sVar7 = _strlen(pcVar4);
              iVar11 = sVar7 + sVar5;
              uVar1 = iVar11 + 2;
              if (uVar8 < uVar1) {
                uVar8 = 0x800;
                if (0x800 < uVar1 >> 2) {
                  uVar8 = uVar1 >> 2;
                }
                uVar8 = uVar1 + uVar8;
                pcVar6 = _malloc(uVar8);
                if (pcVar6 == (char *)0x0) goto LAB_97bbe3d4;
                _memmove(pcVar6,pcVar3,sVar5 + 1);
                _free(pcVar3);
              }
              sVar5 = iVar11 + 1;
              _strcat(pcVar6,pcVar4);
              pcVar6[iVar11] = '\n';
              pcVar6[sVar5] = '\0';
              _free(pcVar4);
            }
            pPVar2 = (unsigned char *)((int (*)())ParseSymbolTable__NextSymbol)(this,pPVar2);
            pcVar3 = pcVar6;
          }
          if (cVar10 != '\x02') break;
          cVar10 = '\x03';
          _strcat(pcVar3,DAT_a7b7bc14);
          pcVar6 = DAT_a7b7bc14;
LAB_97bbe53c:
          sVar7 = _strlen(pcVar6);
          sVar5 = sVar5 + sVar7;
        }
        if (cVar10 == '\x03') {
          cVar10 = '\x04';
          _strcat(pcVar3,DAT_a7b7bc18);
          pcVar6 = DAT_a7b7bc18;
          goto LAB_97bbe53c;
        }
        if (cVar10 == '\x04') {
          cVar10 = '\0';
          _strcat(pcVar3,DAT_a7b7bc1c);
          pcVar6 = DAT_a7b7bc1c;
          goto LAB_97bbe53c;
        }
        pcVar6 = pcVar3;
      } while (cVar10 != '\0');
    }
  }
  return pcVar6;
}

/* TIntermSymbol__compileNode @ 0x97bbe56c (304 bytes) */
int TIntermSymbol__compileNode(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  undefined1 *puVar1;
  int iVar2;
  undefined4 uVar3;
  unsigned char * this_00;
  unsigned char * pTVar4;
  undefined4 *this_01;
  
  this_01 = (undefined4 *)0x0;
  iVar2 = (**(code **)(*(int *)this + 0x60))();
  puVar1 = DAT_a7b7bd04;
  *(undefined1 *)(*(int *)(iVar2 + 4) + *(int *)(*(int *)(iVar2 + 4) + -0xc)) = *DAT_a7b7bd04;
  if (*(int *)(iVar2 + 4) != 0) {
    uVar3 = (*(code *)**(undefined4 **)this)(this);
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
int TIntermConstantUnion__compileNode(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  int iVar1;
  uint uVar2;
  undefined2 uVar3;
  void *this_00;
  undefined4 uVar4;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 in_r9;
  undefined4 in_r10;
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
                  (SUB41(param_2,0),(char *)0x1,(char *)0x0,
                   "TIntermConstantUnion::compileNode: EbtStruct constant union type, investigate",
                   in_r7,in_r8,in_r9,in_r10);
      }
    }
    TPPStreamCompiler__error
              (SUB41(param_2,0),(char *)0x1,(char *)0x0,
               "TIntermConstantUnion::compileNode: Unexpected constant union type",in_r7,in_r8,in_r9
               ,in_r10);
  }
  return this_00;
}

/* TIntermBinary__compileNode @ 0x97bbe7f0 (3444 bytes) */
int TIntermBinary__compileNode(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  unsigned char * pPVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  bool bVar11;
  int iVar5;
  unsigned char * pTVar6;
  unsigned char * pPVar7;
  ushort uVar10;
  unsigned char * pPVar8;
  undefined1 uVar12;
  int iVar9;
  uchar uVar14;
  unsigned char ** ppPVar13;
  char *in_r6;
  undefined4 in_r8;
  undefined4 *puVar15;
  uint *puVar16;
  undefined4 uVar17;
  void *pvVar18;
  uint uVar19;
  size_t sVar20;
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
  local_90 = (*(code *)**(undefined4 **)this)();
  puVar15 = *(undefined4 **)this;
  local_c0 = local_c0 & 0x1fffffff | 0x40000000;
  uVar3 = (*(code *)*puVar15)(this);
  *(undefined4 *)(param_2 + 0x90) = uVar3;
  piVar4 = *(int **)(this + 0x34);
  if (piVar4 != (int *)0x0) {
    local_38 = (unsigned char *)(**(code **)(*piVar4 + 0xc))(piVar4,param_2);
    iVar2 = *(int *)(this + 0x30);
    if (((iVar2 != 0x2d) && (iVar2 != 0x2e)) && (iVar2 != 0x2f)) {
      ((int (*)())ParseSymbolTable__processOperand)(*(unsigned char **)(param_2 + 0x68),local_38);
    }
  }
  piVar4 = *(int **)(this + 0x38);
  if (piVar4 != (int *)0x0) {
    local_34 = (unsigned char *)(**(code **)(*piVar4 + 0xc))(piVar4,param_2);
    ((int (*)())ParseSymbolTable__processOperand)(*(unsigned char **)(param_2 + 0x68),local_34);
  }
  iVar2 = *(int *)(this + 0x30);
  bVar11 = SUB41(param_2,0);
  if (iVar2 == 0x2d) {
    ((int (*)())ParseSymbolTable__processOperand)(*(unsigned char **)(param_2 + 0x68),local_34);
    puVar16 = *(uint **)(local_34 + 4);
    uVar19 = *puVar16;
    piVar4 = (int *)(**(code **)(**(int **)(this + 0x34) + 0x3c))();
    iVar5 = (**(code **)(*piVar4 + 0x38))();
    if (iVar5 == 0) {
      ParseOperand__AddDirectIndex(local_38,uVar19);
    }
    else {
      ParseSymbol__AddDirectIndex(*(unsigned char **)local_38,uVar19);
      _sprintf((char *)&local_80,"[%d]",uVar19);
      ParseSymbol__CatName(*(unsigned char **)local_38,(char *)&local_80);
      iVar5 = (**(code **)(*(int *)this + 0x54))(this);
      if (iVar5 == 0) {
        uVar3 = 1;
LAB_97bbf03c:
        pPVar8 = *(unsigned char **)local_38;
        *(undefined4 *)(pPVar8 + 0x48) = uVar3;
        ParseSymbol__ResolveOpenGLType(pPVar8);
      }
      else {
        TPPStreamCompiler__error
                  (bVar11,(char *)0x1,(char *)0x0,
                   "TIntermBinary::compileNode: Array index results in another array, this is not handled"
                   ,iVar2,in_r8,puVar16,uVar17);
      }
    }
LAB_97bbf04c:
    local_30[0] = local_38;
    goto LAB_97bbf4fc;
  }
  if (iVar2 == 0x2e) {
    if (*(int *)local_38 == 0) {
      pTVar6 = (unsigned char *)(**(code **)(**(int **)(this + 0x34) + 0x3c))();
      pPVar7 = (unsigned char *)
               TPPStreamCompiler__newIndirectOperandFromConstant(param_2,local_38,pTVar6);
      pPVar1 = local_38;
      if (local_38 != (unsigned char *)0x0) {
        __ZN12ParseOperandD1Ev(local_38);
        __ZdlPv(pPVar1);
      }
    }
    else {
      piVar4 = (int *)(**(code **)(**(int **)(this + 0x34) + 0x3c))();
      iVar5 = (**(code **)(*piVar4 + 0x38))();
      pPVar7 = local_38;
      if (iVar5 != 0) {
        _sprintf((char *)&local_80,"[%d]",0);
        ParseSymbol__CatName(*(unsigned char **)local_38,(char *)&local_80);
        iVar5 = (**(code **)(*(int *)this + 0x54))(this);
        if (iVar5 == 0) {
          pPVar8 = *(unsigned char **)local_38;
          *(undefined4 *)(pPVar8 + 0x48) = 1;
          ParseSymbol__ResolveOpenGLType(pPVar8);
          pPVar7 = local_38;
        }
        else {
          in_r6 = 
          "TIntermBinary::compileNode: Array index results in another array, this is not handled";
          TPPStreamCompiler__error
                    (bVar11,(char *)0x1,(char *)0x0,
                     "TIntermBinary::compileNode: Array index results in another array, this is not handled"
                     ,iVar2,in_r8,puVar15,uVar17);
          pPVar7 = local_38;
        }
      }
    }
    local_38 = pPVar7;
    piVar4 = (int *)(**(code **)(**(int **)(this + 0x34) + 0x3c))();
    iVar5 = (**(code **)(*piVar4 + 0x38))();
    if (iVar5 == 0) {
      ParseOperand__AddDirectIndex(local_38,0);
    }
    else {
      ParseSymbol__AddDirectIndex(*(unsigned char **)local_38,0);
    }
    ((int (*)())ParseSymbolTable__processOperand)(*(unsigned char **)(param_2 + 0x68),local_38);
    piVar4 = (int *)(**(code **)(**(int **)(this + 0x34) + 0x3c))();
    iVar5 = (**(code **)(*piVar4 + 0x38))();
    if (iVar5 == 0) {
      piVar4 = (int *)(**(code **)(**(int **)(this + 0x34) + 0x3c))();
      iVar5 = (**(code **)(*piVar4 + 0x34))();
      if (iVar5 == 0) {
        *(unsigned char **)(local_38 + 0xc) = local_34;
        local_34 = (unsigned char *)0x0;
        goto LAB_97bbf04c;
      }
    }
    piVar4 = (int *)(**(code **)(**(int **)(this + 0x34) + 0x3c))();
    iVar5 = (**(code **)(*piVar4 + 0x38))();
    if (iVar5 == 0) {
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
                  ((unsigned char *)&local_80,param_2,local_3c,in_r6,iVar2,in_r8);
        local_b8 = local_80;
        local_b4 = local_7c;
        TPPStreamCompiler__getOperandAsSourceVar
                  ((unsigned char *)&local_80,param_2,local_34,in_r6,iVar2,in_r8,puVar15,uVar17);
        local_bc = (local_b8 >> 0xc & 1) << 0x1c | local_bc & 0xefffffff;
        local_b0 = local_80;
        local_ac = local_7c;
      }
      else {
        local_c0 = local_c0 & 0xfc03ffff | 0x880000;
        TPPStreamCompiler__getOperandAsDestVar
                  ((unsigned char *)&local_80,param_2,local_3c,in_r6,iVar2,in_r8);
        local_b8 = local_80;
        local_b4 = local_7c;
        TPPStreamCompiler__getOperandAsSourceVar
                  ((unsigned char *)&local_80,param_2,local_34,in_r6,iVar2,in_r8,puVar15,uVar17);
        local_b0 = local_80;
        local_ac = local_7c;
        if (*(int *)local_3c == 0) {
          uVar10 = *(ushort *)(local_3c + 0x18);
        }
        else {
          uVar10 = *(ushort *)(*(int *)local_3c + 0x2c);
        }
        TPPStreamCompiler__getConstantAsSourceVar
                  ((unsigned char *)&local_80,(uint)param_2,(short)&STACKARG(0xffffff00) + 0xc0,1,
                   (uint)uVar10);
        local_bc = (local_b8 >> 0xc & 1) << 0x1c | local_bc & 0xefffffff;
        local_a8 = local_80;
        local_a4 = local_7c;
      }
      if (*(int *)local_3c == 0) {
        uVar10 = *(ushort *)(local_3c + 0x18);
      }
      else {
        uVar10 = *(ushort *)(*(int *)local_3c + 0x2c);
      }
      uVar19 = GetPPStreamTypeForGLType(uVar10);
      local_bc = (uVar19 & 7) << 0x17 | local_bc & 0xfc7fffff;
      iVar2 = ParseOperand__GetLogicalSize(local_3c);
      local_bc = (iVar2 + -1) * 0x4000000 & 0xc000000U | local_bc & 0xf3ffffff;
      TPPStreamCompiler__AddOperation
                (param_2,&local_3c,(unsigned char *)&local_c0,(char *)0x0,0);
      *(unsigned char **)(local_30[0] + 8) = local_3c;
      goto LAB_97bbf4fc;
    }
    if (local_40 < 2) {
      local_c0 = local_c0 & 0xfc03ffff | 0x7c0000;
      TPPStreamCompiler__getOperandAsDestVar
                ((unsigned char *)&local_80,param_2,local_3c,in_r6,iVar2,in_r8);
      local_b8 = local_80;
      local_b4 = local_7c;
      TPPStreamCompiler__getOperandAsSourceVar
                ((unsigned char *)&local_80,param_2,local_34,in_r6,iVar2,in_r8,puVar15,uVar17);
      local_b0 = local_80;
      local_ac = local_7c;
      TPPStreamCompiler__getOperandAsSourceVar
                ((unsigned char *)&local_80,param_2,local_3c,in_r6,iVar2,in_r8,puVar15,uVar17);
      local_bc = (local_b8 >> 0xc & 1) << 0x1c | local_bc & 0xefffffff;
      local_a8 = local_80;
      local_a4 = local_7c;
    }
    else {
      local_c0 = local_c0 & 0x7c03ffff | 0x60fc0000;
      TPPStreamCompiler__getOperandAsDestVar
                ((unsigned char *)&local_80,param_2,local_3c,in_r6,iVar2,in_r8);
      local_b8 = local_80;
      local_b4 = local_7c;
      TPPStreamCompiler__getOperandAsSourceVar
                ((unsigned char *)&local_80,param_2,local_34,in_r6,iVar2,in_r8,puVar15,uVar17);
      local_b0 = local_80;
      local_ac = local_7c;
      if (*(int *)local_3c == 0) {
        uVar10 = *(ushort *)(local_3c + 0x18);
      }
      else {
        uVar10 = *(ushort *)(*(int *)local_3c + 0x2c);
      }
      uVar19 = (uint)uVar10;
      uVar3 = 1;
      pPVar7 = local_3c;
      TPPStreamCompiler__getConstantAsSourceVar
                ((unsigned char *)&local_80,(uint)param_2,(short)&STACKARG(0xffffff00) + 0xc0,1,uVar19);
      local_a8 = local_80;
      local_a4 = local_7c;
      TPPStreamCompiler__getOperandAsSourceVar
                ((unsigned char *)&local_80,param_2,local_3c,uVar3,uVar19,in_r8,pPVar7,uVar17);
      local_bc = (local_b8 >> 0xc & 1) << 0x1c | local_bc & 0xefffffff;
      local_a0 = local_80;
      local_9c = local_7c;
    }
    if (*(int *)local_3c == 0) {
      uVar10 = *(ushort *)(local_3c + 0x18);
    }
    else {
      uVar10 = *(ushort *)(*(int *)local_3c + 0x2c);
    }
    uVar19 = GetPPStreamTypeForGLType(uVar10);
    local_bc = (uVar19 & 7) << 0x17 | local_bc & 0xfc7fffff;
    iVar2 = ParseOperand__GetLogicalSize(local_3c);
    local_bc = (iVar2 + -1) * 0x4000000 & 0xc000000U | local_bc & 0xf3ffffff;
    ppPVar13 = &local_3c;
  }
  else {
    if (iVar2 == 0x2f) {
      pPVar8 = *(unsigned char **)local_38;
      (**(code **)(**(int **)(this + 0x34) + 0x38))(local_70);
      local_70[0] = &PTR___ZN5TTypeD1Ev_a7b7d730;
      ((int (*)())ParseSymbolTable__processOperand)(*(unsigned char **)(param_2 + 0x68),local_34);
      iVar5 = **(int **)(local_34 + 4);
      ParseSymbol__CatName(pPVar8,".");
      iVar2 = (**(code **)(**(int **)(*(int *)(local_68 + 4) + iVar5 * 8) + 0x1c))();
      *(undefined1 *)(*(int *)(iVar2 + 4) + *(int *)(*(int *)(iVar2 + 4) + -0xc)) = *DAT_a7b7bd04;
      ParseSymbol__CatName(pPVar8,*(char **)(iVar2 + 4));
      ParseSymbol__SetParseTreeType(pPVar8,*(unsigned char **)(*(int *)(local_68 + 4) + iVar5 * 8));
      uVar3 = 0;
      goto LAB_97bbf03c;
    }
    if (iVar2 == 0x30) {
      pvVar18 = (void *)0x0;
      local_30[0] = local_38;
      sVar20 = *(size_t *)(local_38 + 0x14);
      if (sVar20 != 0) {
        uVar19 = 0;
        pvVar18 = _malloc(sVar20);
        if (0 < (int)sVar20) {
          do {
            uVar12 = ((int (*)())ParseOperand__GetSwizzle)(local_30[0],uVar19);
            *(undefined1 *)((int)pvVar18 + uVar19) = uVar12;
            uVar19 = uVar19 + 1;
          } while ((int)uVar19 < (int)sVar20);
        }
        ((int (*)())ParseOperand__ClearSwizzles)(local_30[0]);
      }
      iVar5 = (**(code **)(**(int **)(this + 0x38) + 0x1c))();
      if (iVar5 == 0) {
        TPPStreamCompiler__error
                  (bVar11,(char *)0x1,*(char **)(*(int *)local_38 + 0x14),
                   "Right hand child of vector swizzle is not an aggregate node.",iVar2,in_r8,
                   *(int *)local_38,uVar17);
      }
      else {
        piVar4 = (int *)(**(code **)(**(int **)(this + 0x38) + 0x1c))();
        iVar5 = (**(code **)(*piVar4 + 100))();
        for (puVar15 = *(undefined4 **)(iVar5 + 4); puVar15 != *(undefined4 **)(iVar5 + 8);
            puVar15 = puVar15 + 1) {
          piVar4 = (int *)(**(code **)(*(int *)*puVar15 + 0x14))();
          iVar9 = (**(code **)(*piVar4 + 0x18))();
          if (iVar9 == 0) {
            TPPStreamCompiler__error
                      (bVar11,(char *)0x1,*(char **)(*(int *)local_38 + 0x14),
                       "Unexpected non-constant in vector swizzle.",iVar2,in_r8,*(int *)local_38,
                       uVar17);
          }
          else {
            if (sVar20 == 0) {
              piVar4 = (int *)(**(code **)(*(int *)*puVar15 + 0x14))();
              iVar9 = (**(code **)(*piVar4 + 0x18))();
              uVar14 = *(uchar *)(*(int *)(iVar9 + 0x30) + 3);
            }
            else {
              piVar4 = (int *)(**(code **)(*(int *)*puVar15 + 0x14))();
              iVar9 = (**(code **)(*piVar4 + 0x18))();
              uVar14 = *(uchar *)((int)pvVar18 + **(int **)(iVar9 + 0x30));
            }
            ParseOperand__AddSwizzle(local_30[0],uVar14);
          }
        }
      }
      goto LAB_97bbf4fc;
    }
    if (iVar2 < 0x31) {
      if (iVar2 - 0x1dU < 2) {
        pTVar6 = (unsigned char *)(**(code **)(*(int *)this + 0x3c))(this);
        local_30[0] = (unsigned char *)
                      TPPStreamCompiler__equalOperands
                                (param_2,pTVar6,&local_38,&local_34,iVar2 == 0x1d);
      }
      else {
LAB_97bbf334:
        pTVar6 = (unsigned char *)(**(code **)(*(int *)this + 0x3c))(this);
        local_30[0] = (unsigned char *)TPPStreamCompiler__newTemporary(param_2,pTVar6);
        ppPVar13 = &local_34;
        __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_S2_
                  (param_2,local_30,&local_38,ppPVar13);
LAB_97bbf370:
        TPPStreamCompiler__getOperandAsSourceVar
                  ((unsigned char *)&local_80,param_2,local_38,ppPVar13,iVar2,in_r8,puVar15,uVar17);
        local_b0 = local_80;
        local_ac = local_7c;
        TPPStreamCompiler__getOperandAsSourceVar
                  ((unsigned char *)&local_80,param_2,local_34,ppPVar13,iVar2,in_r8,puVar15,uVar17);
        local_a8 = local_80;
        local_a4 = local_7c;
        TPPStreamCompiler__getOperandAsDestVar
                  ((unsigned char *)&local_80,param_2,local_30[0],ppPVar13,iVar2,in_r8);
        local_b8 = local_80;
        local_b4 = local_7c;
      }
    }
    else {
      if (iVar2 != 0x76) {
        if ((iVar2 < 0x76) || (0x7e < iVar2)) goto LAB_97bbf334;
        if ((*(int *)(local_38 + 0xc) == 0) && (*(int *)(local_38 + 8) == 0)) {
          local_30[0] = local_38;
        }
        else {
          pPVar7 = operator_new(0x38);
          __ZN12ParseOperandC1ERKS_(pPVar7,local_38);
          local_30[0] = pPVar7;
          if (*(int *)(local_38 + 0xc) != 0) {
            pvVar18 = operator_new(0x38);
            __ZN12ParseOperandC1ERKS_(pvVar18,*(unsigned char **)(local_38 + 0xc));
            *(void **)(pPVar7 + 0xc) = pvVar18;
          }
          pPVar7 = local_30;
          if (*(int *)(local_38 + 8) != 0) {
            pvVar18 = operator_new(0x38);
            __ZN12ParseOperandC1ERKS_(pvVar18,*(unsigned char **)(local_38 + 8));
            *(void **)(pPVar7 + 8) = pvVar18;
          }
        }
        ppPVar13 = &local_34;
        __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_S2_
                  (param_2,local_30,&local_38,ppPVar13);
        goto LAB_97bbf370;
      }
      local_30[0] = local_38;
      TPPStreamCompiler__assignOperands(param_2,&local_38,&local_34,true);
    }
    iVar5 = *(int *)(this + 0x30);
    iVar2 = iVar5 * 4;
    local_c0 = (*(uint *)(&_operatorToken + iVar2) & 0xff) << 0x12 | local_c0 & 0xfc03ffff;
    if (*(int **)(*(int *)local_30[0] + 0xc) != (int *)0x0) {
      iVar5 = (**(code **)(**(int **)(*(int *)local_30[0] + 0xc) + 0x24))();
      if (iVar5 == 0xd) {
        *(undefined4 *)(param_2 + 0xa4) = 1;
      }
      iVar5 = *(int *)(this + 0x30);
    }
    if (iVar5 < 0x31) {
      if (0x2c < iVar5) goto LAB_97bbf4fc;
      if (0x16 < iVar5) {
        if (iVar5 < 0x1d) goto LAB_97bbf46c;
        if (iVar5 < 0x1f) goto LAB_97bbf4fc;
      }
    }
    else {
      if (iVar5 == 0x76) goto LAB_97bbf4fc;
      if ((0x75 < iVar5) && (iVar5 - 0x7fU < 6)) {
LAB_97bbf46c:
        TPPStreamCompiler__error
                  (bVar11,(char *)0x1,(char *)0x0,
                   "TIntermBinary::compileNode: Unsupported operation (TOperator: %d)",iVar5,in_r8,
                   iVar2,uVar17);
        goto LAB_97bbf4fc;
      }
    }
    uVar19 = ParseOperand__IsMatrix(local_30[0]);
    local_bc = (uVar19 & 1) << 0x1c | local_bc & 0xefffffff;
    if (*(int *)local_30[0] == 0) {
      uVar10 = *(ushort *)(local_30[0] + 0x18);
    }
    else {
      uVar10 = *(ushort *)(*(int *)local_30[0] + 0x2c);
    }
    uVar19 = GetPPStreamTypeForGLType(uVar10);
    local_bc = (uVar19 & 7) << 0x17 | local_bc & 0xfc7fffff;
    iVar2 = ParseOperand__GetLogicalSize(local_30[0]);
    local_bc = (iVar2 + -1) * 0x4000000 & 0xc000000U | local_bc & 0xf3ffffff;
    ppPVar13 = local_30;
  }
  TPPStreamCompiler__AddOperation(param_2,ppPVar13,(unsigned char *)&local_c0,(char *)0x0,0);
LAB_97bbf4fc:
  pPVar7 = local_34;
  if (local_34 != (unsigned char *)0x0) {
    __ZN12ParseOperandD1Ev(local_34);
    __ZdlPv(pPVar7);
  }
  pPVar7 = local_38;
  if ((local_38 != (unsigned char *)0x0) && (local_30[0] != local_38)) {
    __ZN12ParseOperandD1Ev(local_38);
    __ZdlPv(pPVar7);
  }
  return local_30[0];
}

/* TIntermUnary__compileNode @ 0x97bbf564 (1824 bytes) */
int TIntermUnary__compileNode(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  bool bVar1;
  undefined4 uVar2;
  ushort uVar5;
  uint uVar3;
  unsigned char * pTVar4;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 uVar6;
  uint in_r8;
  unsigned char * pPVar7;
  unsigned char * pPVar8;
  uint uVar9;
  int iVar10;
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
  bVar1 = true;
  local_a0 = 0;
  local_9c = 0;
  local_98 = 0;
  local_94 = 0;
  local_90 = 0;
  local_8c = 0;
  local_7c = 0;
  local_20 = (unsigned char *)0x0;
  local_80 = 0;
  local_80 = (*(code *)**(undefined4 **)this)();
  local_b0 = local_b0 & 0x1fffffff | 0x20000000;
  uVar2 = (*(code *)**(undefined4 **)this)(this);
  *(undefined4 *)(param_2 + 0x90) = uVar2;
  local_1c = (unsigned char *)
             (**(code **)(**(int **)(this + 0x34) + 0xc))(*(int **)(this + 0x34),param_2);
  ((int (*)())ParseSymbolTable__processOperand)(*(unsigned char **)(param_2 + 0x68),local_1c);
  uVar9 = *(uint *)(this + 0x30);
  if (uVar9 - 5 < 8) {
    pPVar7 = (unsigned char *)((uVar9 - 5) * 4);
    switch(uVar9) {
    default:
      bVar1 = false;
      goto LAB_97bbfa5c;
    case 6:
    case 7:
      goto switchD_97bbf664_caseD_6;
    case 9:
    case 10:
      pTVar4 = (unsigned char *)(**(code **)(*(int *)this + 0x3c))(this);
      local_20 = (unsigned char *)TPPStreamCompiler__newTemporary(param_2,pTVar4);
      __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_
                (param_2,&local_20,&local_1c);
      TPPStreamCompiler__getOperandAsSourceVar
                ((unsigned char *)&local_70,param_2,local_1c,in_r6,in_r7,in_r8,pPVar7,uVar9);
      local_a0 = local_70;
      local_9c = local_6c;
      TPPStreamCompiler__getOperandAsDestVar
                ((unsigned char *)&local_70,param_2,local_20,in_r6,in_r7,in_r8);
      local_ac = (local_70 >> 0xc & 1) << 0x1c | local_ac & 0xefffffff;
      local_b0 = local_b0 & 0xfc03ffff;
      local_a4 = local_6c;
      local_a8 = local_70;
      if (*(int *)local_20 == 0) {
        uVar5 = *(ushort *)(local_20 + 0x18);
      }
      else {
        uVar5 = *(ushort *)(*(int *)local_20 + 0x2c);
      }
      pPVar7 = local_20;
      uVar9 = GetPPStreamTypeForGLType(uVar5);
      local_ac = (uVar9 & 7) << 0x17 | local_ac & 0xfc7fffff;
      iVar10 = ParseOperand__GetLogicalSize(local_20);
      local_ac = (iVar10 + -1) * 0x4000000 & 0xc000000U | local_ac & 0xf3ffffff;
      uVar2 = 0;
      uVar6 = 0;
      TPPStreamCompiler__AddOperation
                (param_2,&local_20,(unsigned char *)&local_b0,(char *)0x0,0);
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
      local_30 = (*(code *)**(undefined4 **)this)(this);
      local_60 = local_60 & 0x1fffffff | 0x40000000;
      if (*(int *)local_1c == 0) {
        uVar5 = *(ushort *)(local_1c + 0x18);
      }
      else {
        uVar5 = *(ushort *)(*(int *)local_1c + 0x2c);
      }
      pPVar8 = local_1c;
      uVar9 = GetPPStreamTypeForGLType(uVar5);
      if (uVar9 == 3) {
        uVar6 = 0x1404;
LAB_97bbf88c:
        uVar5 = (ushort)local_18;
        local_18[0] = 1;
LAB_97bbf894:
        uVar2 = 1;
        TPPStreamCompiler__getConstantAsSourceVar
                  ((unsigned char *)&local_70,(uint)param_2,uVar5,1,uVar6);
        local_48 = local_70;
        local_44 = local_6c;
      }
      else if (uVar9 < 4) {
        if (uVar9 == 1) {
          uVar5 = (ushort)local_18;
          uVar6 = 0x1406;
          local_18[0] = 0x3f800000;
          goto LAB_97bbf894;
        }
      }
      else if (uVar9 == 4) {
        uVar6 = 0x8b56;
        goto LAB_97bbf88c;
      }
      __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_
                (param_2,&local_1c,&local_1c);
      TPPStreamCompiler__getOperandAsSourceVar
                ((unsigned char *)&local_70,param_2,local_1c,uVar2,uVar6,in_r8,pPVar8,pPVar7);
      local_50 = local_70;
      local_4c = local_6c;
      TPPStreamCompiler__getOperandAsDestVar
                ((unsigned char *)&local_70,param_2,local_1c,uVar2,uVar6,in_r8);
      in_r8 = *(uint *)(&_operatorToken + *(int *)(this + 0x30) * 4);
      uVar9 = (in_r8 & 0xff) << 0x12 | local_60 & 0xfc03ffff;
      local_5c = (local_a8 >> 0xc & 1) << 0x1c | local_5c & 0xefffffff;
      local_58 = local_70;
      local_54 = local_6c;
      if (*(int *)local_1c == 0) {
        uVar5 = *(ushort *)(local_1c + 0x18);
      }
      else {
        uVar5 = *(ushort *)(*(int *)local_1c + 0x2c);
      }
      pPVar7 = local_1c;
      local_60 = uVar9;
      uVar3 = GetPPStreamTypeForGLType(uVar5);
      local_5c = (uVar3 & 7) << 0x17 | local_5c & 0xfc7fffff;
      bVar1 = false;
      iVar10 = ParseOperand__GetLogicalSize(local_1c);
      local_5c = (iVar10 + -1) * 0x4000000 & 0xc000000U | local_5c & 0xf3ffffff;
      in_r6 = 0;
      in_r7 = 0;
      TPPStreamCompiler__AddOperation
                (param_2,&local_1c,(unsigned char *)&local_60,(char *)0x0,0);
      break;
    case 0xb:
    case 0xc:
      local_b0 = local_b0 & 0x1fffffff | 0x40000000;
      if (*(int *)local_1c == 0) {
        uVar5 = *(ushort *)(local_1c + 0x18);
      }
      else {
        uVar5 = *(ushort *)(*(int *)local_1c + 0x2c);
      }
      uVar3 = GetPPStreamTypeForGLType(uVar5);
      if (uVar3 == 3) {
        in_r7 = 0x1404;
LAB_97bbfa3c:
        uVar5 = (ushort)local_18;
        local_18[0] = 1;
LAB_97bbfa44:
        in_r6 = 1;
        TPPStreamCompiler__getConstantAsSourceVar
                  ((unsigned char *)&local_70,(uint)param_2,uVar5,1,in_r7);
        local_98 = local_70;
        local_94 = local_6c;
      }
      else if (uVar3 < 4) {
        if (uVar3 == 1) {
          uVar5 = (ushort)local_18;
          in_r7 = 0x1406;
          local_18[0] = 0x3f800000;
          goto LAB_97bbfa44;
        }
      }
      else if (uVar3 == 4) {
        in_r7 = 0x8b56;
        goto LAB_97bbfa3c;
      }
LAB_97bbfa5c:
      local_20 = local_1c;
    }
  }
  else {
switchD_97bbf664_caseD_6:
    pTVar4 = (unsigned char *)(**(code **)(*(int *)this + 0x3c))(this);
    local_20 = (unsigned char *)TPPStreamCompiler__newTemporary(param_2,pTVar4);
  }
  if (bVar1) {
    __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_(param_2,&local_20,&local_1c)
    ;
    TPPStreamCompiler__getOperandAsSourceVar
              ((unsigned char *)&local_70,param_2,local_1c,in_r6,in_r7,in_r8,pPVar7,uVar9);
    local_a0 = local_70;
    local_9c = local_6c;
    TPPStreamCompiler__getOperandAsDestVar
              ((unsigned char *)&local_70,param_2,local_20,in_r6,in_r7,in_r8);
    iVar10 = *(int *)(this + 0x30);
    local_b0 = (*(uint *)(&_operatorToken + iVar10 * 4) & 0xff) << 0x12 | local_b0 & 0xfc03ffff;
    local_a4 = local_6c;
    local_a8 = local_70;
    pPVar7 = *(unsigned char **)local_20;
    if (*(int **)(pPVar7 + 0xc) == (int *)0x0) goto LAB_97bbfb3c;
    iVar10 = (**(code **)(**(int **)(pPVar7 + 0xc) + 0x24))();
    if (iVar10 == 0xd) {
      *(undefined4 *)(param_2 + 0xa4) = 1;
    }
  }
  iVar10 = *(int *)(this + 0x30);
LAB_97bbfb3c:
  if (iVar10 == 5) {
    *(uint *)(local_1c + 0x28) = (uint)(*(int *)(local_1c + 0x28) != 1);
  }
  else if (iVar10 == 8) {
    TPPStreamCompiler__error
              (SUB41(param_2,0),(char *)0x1,(char *)0x0,
               "SecondPassProcessAggregateOp: EOpBitwiseNot not supported",in_r7,in_r8,pPVar7,8);
  }
  if (bVar1) {
    iVar10 = *(int *)(this + 0x30);
    if (((iVar10 == 0x4b) || (iVar10 == 0x57)) || (iVar10 == 0x58)) {
      local_ac = (local_a0 >> 0xe & 1) << 0x1c | local_ac & 0xefffffff;
      if (*(int *)local_1c == 0) {
        uVar5 = *(ushort *)(local_1c + 0x18);
      }
      else {
        uVar5 = *(ushort *)(*(int *)local_1c + 0x2c);
      }
      uVar9 = GetPPStreamTypeForGLType(uVar5);
      pPVar7 = local_1c;
    }
    else {
      local_ac = (local_a8 >> 0xc & 1) << 0x1c | local_ac & 0xefffffff;
      if (*(int *)local_20 == 0) {
        uVar5 = *(ushort *)(local_20 + 0x18);
      }
      else {
        uVar5 = *(ushort *)(*(int *)local_20 + 0x2c);
      }
      uVar9 = GetPPStreamTypeForGLType(uVar5);
      pPVar7 = local_20;
    }
    local_ac = (uVar9 & 7) << 0x17 | local_ac & 0xfc7fffff;
    iVar10 = ParseOperand__GetLogicalSize(pPVar7);
    local_ac = (iVar10 + -1) * 0x4000000 & 0xc000000U | local_ac & 0xf3ffffff;
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
int TIntermAggregate__compileNode(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  byte bVar1;
  byte *pbVar2;
  undefined **ppuVar3;
  int iVar4;
  undefined4 uVar5;
  size_t sVar6;
  int iVar7;
  char *pcVar8;
  unsigned char * pTVar9;
  int *piVar10;
  int iVar11;
  int iVar12;
  unsigned char * this_00;
  unsigned char * this_01;
  void *pvVar13;
  ushort uVar14;
  uint uVar15;
  bool bVar17;
  unsigned char ** ppPVar16;
  int in_r6;
  undefined4 in_r7;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  int iVar21;
  unsigned char ** ppPVar22;
  unsigned char ** ppPVar23;
  int iVar24;
  undefined4 *puVar25;
  unsigned char * pPVar26;
  uint *puVar27;
  unsigned char * pPVar28;
  undefined4 *puVar29;
  void *pvVar30;
  char in_RESERVE;
  byte in_cr0;
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
  size_t local_9c;
  undefined **local_90;
  uint local_8c;
  uint local_6c;
  undefined **local_60 [4];
  unsigned char * local_50;
  unsigned char * local_4c;
  unsigned char * local_48 [3];
  
  ppPVar23 = (unsigned char **)0x0;
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
  iVar24 = *(int *)(param_2 + 0x70);
  iVar21 = *(int *)(this + 0x3c) - *(int *)(this + 0x38) >> 2;
  local_a0 = (*(code *)**(undefined4 **)this)();
  uVar5 = (*(code *)**(undefined4 **)this)(this);
  *(undefined4 *)(param_2 + 0x90) = uVar5;
  iVar4 = *(int *)(this + 0x30);
  if (iVar4 == 3) {
    iVar4 = (**(code **)(*(int *)this + 0x6c))(this);
    pbVar2 = DAT_a7b7bd04;
    *(byte *)(*(int *)(iVar4 + 4) + *(int *)(*(int *)(iVar4 + 4) + -0xc)) = *DAT_a7b7bd04;
    sVar6 = _strlen(*(char **)(iVar4 + 4));
    iVar4 = (**(code **)(*(int *)this + 0x6c))(this);
    *(byte *)(*(int *)(iVar4 + 4) + *(int *)(*(int *)(iVar4 + 4) + -0xc)) = *pbVar2;
    _PPStreamAddLabel(iVar24,*(undefined4 *)(iVar4 + 4),sVar6);
    iVar4 = (**(code **)(*(int *)this + 0x6c))(this);
    *(byte *)(*(int *)(iVar4 + 4) + *(int *)(*(int *)(iVar4 + 4) + -0xc)) = *pbVar2;
    iVar4 = FunctionTable__addFunction(*(unsigned char **)(param_2 + 0x6c),*(char **)(iVar4 + 4));
    iVar7 = (**(code **)(*(int *)this + 0x6c))(this);
    *(byte *)(*(int *)(iVar7 + 4) + *(int *)(*(int *)(iVar7 + 4) + -0xc)) = *pbVar2;
    ParseFunctionStack__push((unsigned char *)(param_2 + 0x58),*(char **)(iVar7 + 4));
    iVar7 = (**(code **)(*(int *)this + 0x6c))(this);
    *(byte *)(*(int *)(iVar7 + 4) + *(int *)(*(int *)(iVar7 + 4) + -0xc)) = *pbVar2;
    iVar7 = _memcmp(*(void **)(iVar7 + 4),"main(",5);
    if (iVar7 == 0) {
      FunctionTable__setFirstOp(*(unsigned char **)(param_2 + 0x6c),iVar4,0);
      *(undefined4 *)(param_2 + 0xac) = 1;
      while (iVar7 = ((int (*)())size)((unsigned char *)(param_2 + 0x4c)), iVar7 != 0) {
        piVar10 = (int *)fetch((unsigned char *)(param_2 + 0x4c));
        (**(code **)(*piVar10 + 0xc))(piVar10,param_2);
      }
    }
    else {
      iVar7 = TPPStreamCompiler__LastOperationIndex(param_2);
      uVar15 = 1;
      if (iVar7 != -1) {
        uVar15 = iVar7 + 1;
      }
      FunctionTable__setFirstOp(*(unsigned char **)(param_2 + 0x6c),iVar4,uVar15);
    }
    (**(code **)(*(int *)this + 0x38))(&local_90,this);
    bVar17 = (local_6c & 0x1f80000) == 0;
    in_cr0 = bVar17 << 1;
    local_90 = &PTR___ZN5TTypeD1Ev_a7b7d730;
    if (!bVar17) {
      iVar7 = (**(code **)(*(int *)this + 0x6c))(this);
      *(byte *)(*(int *)(iVar7 + 4) + *(int *)(*(int *)(iVar7 + 4) + -0xc)) = *DAT_a7b7bd04;
      uVar5 = *(undefined4 *)(iVar7 + 4);
      pcVar8 = (char *)(**(code **)(*(int *)this + 0x3c))(this);
      local_48[0] = (unsigned char *)TPPStreamCompiler__newReturnValue((unsigned char *)param_2,pcVar8,uVar5)
      ;
      FunctionTable__setReturnVal(*(unsigned char **)(param_2 + 0x6c),iVar4,true);
    }
  }
  else if ((iVar4 != 2) && (iVar4 == 1)) {
    iVar4 = *(int *)(param_2 + 0x98);
    if (0 < iVar4) {
      iVar4 = ParseFunctionStack__empty((unsigned char *)(param_2 + 0x58));
      if (iVar4 != 0) {
        ((int (*)())store)((unsigned char *)(param_2 + 0x4c),this);
        return (unsigned char *)0x0;
      }
      iVar4 = *(int *)(param_2 + 0x98);
    }
    *(int *)(param_2 + 0x98) = iVar4 + 1;
  }
  bVar17 = iVar21 != 0;
  if (bVar17) {
    ppPVar23 = _malloc(iVar21 << 2);
    ppPVar22 = ppPVar23;
    for (puVar29 = *(undefined4 **)(this + 0x38); puVar29 != *(undefined4 **)(this + 0x3c);
        puVar29 = puVar29 + 1) {
      pPVar28 = (unsigned char *)(**(code **)(*(int *)*puVar29 + 0xc))((int *)*puVar29,param_2);
      *ppPVar22 = pPVar28;
      ppPVar22 = ppPVar22 + 1;
      ((int (*)())ParseSymbolTable__processOperand)(*(unsigned char **)(param_2 + 0x68),pPVar28);
    }
  }
  uVar18 = *(uint *)(this + 0x30);
  uVar20 = (*(uint *)(&_operatorToken + uVar18 * 4) & 0xff) << 0x12 |
           iVar21 << 0x1d | local_d0[0] & 0x1c03ffff;
  uVar15 = uVar20;
  switch(uVar18) {
  case 0x15:
    uVar15 = iVar21 << 0x1d | local_d0[0] & 0x1c03ffff | 0x8c0000;
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
    pTVar9 = (unsigned char *)(**(code **)(*(int *)this + 0x3c))(this);
    local_48[0] = (unsigned char *)TPPStreamCompiler__newTemporary(param_2,pTVar9);
    uVar18 = *(uint *)(this + 0x30);
    uVar15 = local_d0[0];
    break;
  case 0x25:
    local_48[0] = ppPVar23[iVar21 + -1];
  }
  local_d0[0] = uVar15;
  if ((((local_48[0] != (unsigned char *)0x0) && (uVar18 != 3)) && (*(int *)local_48[0] != 0)) &&
     (piVar10 = *(int **)(*(int *)local_48[0] + 0xc), piVar10 != (int *)0x0)) {
    iVar4 = (**(code **)(*piVar10 + 0x24))();
    if (iVar4 == 0xd) {
      *(undefined4 *)(param_2 + 0xa4) = 1;
    }
    uVar18 = *(uint *)(this + 0x30);
  }
  if (0xa3 < uVar18) {
switchD_97bc03dc_caseD_0:
    TType__getCompleteString(&local_90,this + 8);
    bVar1 = *DAT_a7b7bd04;
    *(byte *)(local_8c + *(int *)(local_8c - 0xc)) = bVar1;
    TPPStreamCompiler__error
              (SUB41(param_2,0),(char *)0x1,(char *)0x0,
               "TIntermAggregate::compileNode- unhandle operation %s at %d\n",local_8c,
               *(undefined4 *)(this + 4),(uint)bVar1,uVar20);
    piVar10 = (int *)(local_8c - 4);
    local_60[0] = local_90;
    do {
      iVar4 = *piVar10;
      if (in_RESERVE != '\0') {
        iVar24 = storeWordConditionalIndexed(iVar4 + -1,0,piVar10);
        *piVar10 = iVar24;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar4 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_8c - 0xc),local_60);
    }
    goto switchD_97bc03dc_caseD_25;
  }
  iVar4 = uVar18 * 4;
  switch(uVar18) {
  default:
    goto switchD_97bc03dc_caseD_0;
  case 1:
    *(int *)(param_2 + 0x98) = *(int *)(param_2 + 0x98) + -1;
    break;
  case 2:
    pvVar30 = (void *)0x0;
    ppPVar22 = (unsigned char **)0x0;
    if (bVar17) {
      pvVar30 = _malloc(iVar21 << 2);
      ppPVar22 = _malloc(iVar21 << 2);
    }
    pbVar2 = DAT_a7b7bd04;
    iVar4 = 0;
    puVar29 = *(undefined4 **)(this + 0x38);
    if (0 < iVar21) {
      do {
        iVar24 = iVar4 * 4;
        iVar7 = (**(code **)(*(int *)this + 0x6c))(this);
        *(byte *)(*(int *)(iVar7 + 4) + *(int *)(*(int *)(iVar7 + 4) + -0xc)) = *pbVar2;
        pcVar8 = *(char **)(iVar7 + 4);
        piVar10 = (int *)(**(code **)(*(int *)*puVar29 + 0x14))();
        pTVar9 = (unsigned char *)(**(code **)(*piVar10 + 0x3c))();
        uVar5 = TPPStreamCompiler__newParam(param_2,pTVar9,pcVar8,iVar4);
        *(undefined4 *)(iVar24 + (int)pvVar30) = uVar5;
        if ((*(int *)(ppPVar23[iVar4] + 0xc) == 0) && (*(int *)(ppPVar23[iVar4] + 8) == 0)) {
          ppPVar22[iVar4] = (unsigned char *)0x0;
        }
        else {
          this_01 = operator_new(0x38);
          __ZN12ParseOperandC1ERKS_(this_01,ppPVar23[iVar4]);
          ppPVar22[iVar4] = this_01;
          pPVar28 = ppPVar23[iVar4];
          if (*(int *)(pPVar28 + 0xc) != 0) {
            pvVar13 = operator_new(0x38);
            __ZN12ParseOperandC1ERKS_(pvVar13,*(unsigned char **)(ppPVar23[iVar4] + 0xc));
            *(void **)(this_01 + 0xc) = pvVar13;
            pPVar28 = ppPVar23[iVar4];
          }
          if (*(int *)(pPVar28 + 8) != 0) {
            pPVar28 = ppPVar22[iVar4];
            pvVar13 = operator_new(0x38);
            __ZN12ParseOperandC1ERKS_(pvVar13,*(unsigned char **)(ppPVar23[iVar4] + 8));
            *(void **)(pPVar28 + 8) = pvVar13;
          }
        }
        ppPVar16 = ppPVar23 + iVar4;
        iVar4 = iVar4 + 1;
        TPPStreamCompiler__assignOperands
                  (param_2,(unsigned char **)((int)pvVar30 + iVar24),ppPVar16,false);
        puVar29 = puVar29 + 1;
      } while (iVar4 < iVar21);
    }
    local_d0[0] = local_d0[0] & 0x1c03ffff | 0x1300000;
    iVar24 = 0;
    iVar4 = (**(code **)(*(int *)this + 0x6c))(this);
    pbVar2 = DAT_a7b7bd04;
    *(byte *)(*(int *)(iVar4 + 4) + *(int *)(*(int *)(iVar4 + 4) + -0xc)) = *DAT_a7b7bd04;
    local_9c = _strlen(*(char **)(iVar4 + 4));
    iVar4 = (**(code **)(*(int *)this + 0x6c))(this);
    *(byte *)(*(int *)(iVar4 + 4) + *(int *)(*(int *)(iVar4 + 4) + -0xc)) = *pbVar2;
    TPPStreamCompiler__AddOperation
              (param_2,(unsigned char **)0x0,(unsigned char *)local_d0,*(char **)(iVar4 + 4),0);
    if (0 < iVar21) {
      do {
        iVar4 = ParseOperand__isWriteable(ppPVar23[iVar24]);
        if (iVar4 != 0) {
          ppPVar16 = ppPVar22;
          if (ppPVar22[iVar24] == (unsigned char *)0x0) {
            ppPVar16 = ppPVar23;
          }
          TPPStreamCompiler__assignOperands
                    (param_2,ppPVar16 + iVar24,(unsigned char **)((int)pvVar30 + iVar24 * 4),false);
        }
        pvVar13 = *(void **)(iVar24 * 4 + (int)pvVar30);
        if (pvVar13 != (void *)0x0) {
          __ZN12ParseOperandD1Ev(pvVar13);
          __ZdlPv(pvVar13);
        }
        pPVar28 = ppPVar22[iVar24];
        if (pPVar28 != (unsigned char *)0x0) {
          __ZN12ParseOperandD1Ev(pPVar28);
          __ZdlPv(pPVar28);
        }
        iVar24 = iVar24 + 1;
      } while (iVar24 < iVar21);
    }
    if (pvVar30 != (void *)0x0) {
      _free(pvVar30);
    }
    if (ppPVar22 != (unsigned char **)0x0) {
      _free(ppPVar22);
    }
    (**(code **)(*(int *)this + 0x38))(&local_90,this);
    local_90 = &PTR___ZN5TTypeD1Ev_a7b7d730;
    if ((local_6c & 0x1f80000) != 0) {
      iVar4 = (**(code **)(*(int *)this + 0x6c))(this);
      *(byte *)(*(int *)(iVar4 + 4) + *(int *)(*(int *)(iVar4 + 4) + -0xc)) = *DAT_a7b7bd04;
      uVar5 = *(undefined4 *)(iVar4 + 4);
      pcVar8 = (char *)(**(code **)(*(int *)this + 0x3c))(this);
      local_48[0] = (unsigned char *)TPPStreamCompiler__newReturnValue((unsigned char *)param_2,pcVar8,uVar5)
      ;
    }
    break;
  case 3:
    pPVar26 = (unsigned char *)(param_2 + 0x58);
    puVar29 = (undefined4 *)ParseFunctionStack__getCurrentParamList(pPVar26);
    iVar4 = ParseFunctionStack__getCurrentNumParams(pPVar26);
    pcVar8 = (char *)ParseFunctionStack__current(pPVar26);
    iVar7 = FunctionTable__findFunction(*(unsigned char **)(param_2 + 0x6c),pcVar8);
    iVar11 = FunctionTable__getFirstOp(*(unsigned char **)(param_2 + 0x6c),iVar7);
    if (iVar11 == 0) {
LAB_97bc06f4:
      this_00 = *(unsigned char **)(param_2 + 0x6c);
      bVar17 = false;
    }
    else {
      iVar11 = ParseFunctionStack__getLastParamOpIndex(pPVar26);
      iVar12 = TPPStreamCompiler__LastOperationIndex(param_2);
      if (iVar11 != iVar12) goto LAB_97bc06f4;
      this_00 = *(unsigned char **)(param_2 + 0x6c);
      bVar17 = true;
    }
    FunctionTable__setEmpty(this_00,iVar7,bVar17);
    FunctionTable__setNumParams(*(unsigned char **)(param_2 + 0x6c),iVar7,iVar4);
    iVar11 = (**(code **)(*(int *)this + 0x6c))(this);
    *(byte *)(*(int *)(iVar11 + 4) + *(int *)(*(int *)(iVar11 + 4) + -0xc)) = *DAT_a7b7bd04;
    pcVar8 = *(char **)(iVar11 + 4);
    iVar24 = *(int *)(*(int *)(iVar24 + 0x20) + 4);
    if ((iVar24 == 0) || ((*(uint *)(iVar24 + 0xc) & 0x3fc0000) != 0x1340000)) {
LAB_97bc0788:
      iVar24 = 0;
      if (0 < iVar4) {
        do {
          if (((int *)puVar29[iVar24] != (int *)0x0) &&
             ((iVar11 = (**(code **)(**(int **)(*(int *)puVar29[iVar24] + 0xc) + 0x24))(),
              iVar11 == 10 ||
              (iVar11 = (**(code **)(**(int **)(*(int *)puVar29[iVar24] + 0xc) + 0x24))(),
              iVar11 == 0xb)))) {
            local_50 = (unsigned char *)
                       TPPStreamCompiler__newParam
                                 (param_2,*(unsigned char **)(*(int *)puVar29[iVar24] + 0xc),pcVar8,iVar24);
            TPPStreamCompiler__assignOperands
                      (param_2,&local_50,(unsigned char **)(puVar29 + iVar24),false);
            pPVar28 = local_50;
            if (local_50 != (unsigned char *)0x0) {
              __ZN12ParseOperandD1Ev(local_50);
              __ZdlPv(pPVar28);
            }
          }
          iVar24 = iVar24 + 1;
        } while (iVar24 < iVar4);
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
      local_a0 = (*(code *)**(undefined4 **)this)(this);
      TPPStreamCompiler__AddOperation
                (param_2,(unsigned char **)0x0,(unsigned char *)local_d0,(char *)0x0,0);
    }
    else {
      iVar24 = TPPStreamCompiler__LastOperationIndex(param_2);
      iVar11 = FunctionTable__getFirstOp(*(unsigned char **)(param_2 + 0x6c),iVar7);
      if (iVar24 < iVar11) goto LAB_97bc0788;
    }
    if (puVar29 != (undefined4 *)0x0) {
      puVar25 = puVar29;
      if (0 < iVar4) {
        do {
          pvVar30 = (void *)*puVar25;
          if (pvVar30 != (void *)0x0) {
            __ZN12ParseOperandD1Ev(pvVar30);
            __ZdlPv(pvVar30);
          }
          iVar4 = iVar4 + -1;
          puVar25 = puVar25 + 1;
        } while (iVar4 != 0);
      }
      _free(puVar29);
    }
    ParseFunctionStack__pop(pPVar26);
    uVar15 = TPPStreamCompiler__LastOperationIndex(param_2);
    FunctionTable__setLastOp(*(unsigned char **)(param_2 + 0x6c),iVar7,uVar15);
    break;
  case 4:
    pPVar26 = (unsigned char *)(param_2 + 0x58);
    iVar4 = 0;
    pcVar8 = (char *)ParseFunctionStack__current(pPVar26);
    if (0 < iVar21) {
      do {
        if ((ppPVar23[iVar4] != (unsigned char *)0x0) &&
           (((iVar24 = (**(code **)(**(int **)(*(int *)ppPVar23[iVar4] + 0xc) + 0x24))(),
             iVar24 == 9 ||
             (iVar24 = (**(code **)(**(int **)(*(int *)ppPVar23[iVar4] + 0xc) + 0x24))(),
             iVar24 == 0xb)) ||
            (iVar24 = (**(code **)(**(int **)(*(int *)ppPVar23[iVar4] + 0xc) + 0x24))(),
            iVar24 == 0xc)))) {
          local_4c = (unsigned char *)
                     TPPStreamCompiler__newParam
                               (param_2,*(unsigned char **)(*(int *)ppPVar23[iVar4] + 0xc),pcVar8,iVar4);
          TPPStreamCompiler__assignOperands(param_2,ppPVar23 + iVar4,&local_4c,false);
          pPVar28 = local_4c;
          if (local_4c != (unsigned char *)0x0) {
            __ZN12ParseOperandD1Ev(local_4c);
            __ZdlPv(pPVar28);
          }
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar21);
    }
    iVar4 = TPPStreamCompiler__LastOperationIndex(param_2);
    ParseFunctionStack__setLastParamOpIndex(pPVar26,iVar4);
    ParseFunctionStack__setCurrentParamList(pPVar26,ppPVar23);
    ParseFunctionStack__setCurrentNumParams(pPVar26,iVar21);
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
    in_r6 = iVar21;
    __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_i
              (param_2,local_48,ppPVar23,iVar21);
    if (0 < iVar21) {
      puVar27 = local_d0;
      iVar24 = iVar21;
      ppPVar22 = ppPVar23;
      do {
        pPVar28 = *ppPVar22;
        ppPVar22 = ppPVar22 + 1;
        TPPStreamCompiler__getOperandAsSourceVar
                  ((unsigned char *)&local_90,param_2,pPVar28,in_r6,in_r7,uVar18,iVar4,uVar20);
        ppuVar3 = local_90;
        iVar24 = iVar24 + -1;
        puVar27[5] = local_8c;
        puVar27[4] = (uint)ppuVar3;
        puVar27 = puVar27 + 2;
      } while (iVar24 != 0);
    }
    goto LAB_97bc11d8;
  case 0x25:
    break;
  case 0x38:
    in_r6 = iVar21;
    __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_i
              (param_2,local_48,ppPVar23,iVar21);
    if (0 < iVar21) {
      puVar27 = local_d0;
      iVar24 = iVar21;
      ppPVar22 = ppPVar23;
      do {
        pPVar28 = *ppPVar22;
        ppPVar22 = ppPVar22 + 1;
        TPPStreamCompiler__getOperandAsSourceVar
                  ((unsigned char *)&local_90,param_2,pPVar28,in_r6,in_r7,uVar18,iVar4,uVar20);
        ppuVar3 = local_90;
        iVar24 = iVar24 + -1;
        puVar27[5] = local_8c;
        puVar27[4] = (uint)ppuVar3;
        puVar27 = puVar27 + 2;
      } while (iVar24 != 0);
    }
    goto LAB_97bc11d8;
  case 0x48:
  case 0x49:
    in_r6 = iVar21;
    __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_i
              (param_2,local_48,ppPVar23,iVar21);
    if (0 < iVar21) {
      puVar27 = local_d0 + iVar21 * 2;
      iVar24 = iVar21;
      ppPVar22 = ppPVar23;
      do {
        pPVar28 = *ppPVar22;
        ppPVar22 = ppPVar22 + 1;
        TPPStreamCompiler__getOperandAsSourceVar
                  ((unsigned char *)&local_90,param_2,pPVar28,in_r6,in_r7,uVar18,iVar4,uVar20);
        ppuVar3 = local_90;
        iVar24 = iVar24 + -1;
        puVar27[3] = local_8c;
        puVar27[2] = (uint)ppuVar3;
        puVar27 = puVar27 + -2;
      } while (iVar24 != 0);
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
    pTVar9 = (unsigned char *)(**(code **)(*(int *)this + 0x3c))(this);
    local_48[0] = (unsigned char *)TPPStreamCompiler__construct(param_2,pTVar9,ppPVar23,iVar21);
    break;
  case 0x85:
    iVar21 = 2;
    local_d0[0] = local_d0[0] & 0x1fffffff | 0x40000000;
    ppPVar23 = _malloc(8);
    pPVar28 = (unsigned char *)TPPStreamCompiler__getVertex(param_2);
    ppPVar23[1] = pPVar28;
    pPVar28 = (unsigned char *)TPPStreamCompiler__getMVP(param_2);
    *ppPVar23 = pPVar28;
    TPPStreamCompiler__getOperandAsSourceVar
              ((unsigned char *)&local_90,param_2,pPVar28,in_r6,in_r7,uVar18,iVar4,uVar20);
    local_c0 = local_90;
    local_bc = local_8c;
    TPPStreamCompiler__getOperandAsSourceVar
              ((unsigned char *)&local_90,param_2,ppPVar23[1],in_r6,in_r7,uVar18,iVar4,uVar20);
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
    if (iVar21 == 3) {
      switch(uVar18) {
      case 0x8a:
      case 0x8e:
      case 0x92:
      case 0x96:
      case 0x98:
      case 0x99:
        iVar4 = 0x44;
        break;
      case 0x8b:
      case 0x8f:
      case 0x93:
      case 0x9a:
      case 0x9b:
        iVar4 = 0x45;
        break;
      default:
        goto switchD_97bc03dc_caseD_8c;
      }
      local_d0[0] = iVar4 << 0x12 | local_d0[0] & 0xfc03ffff;
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
    uVar19 = uVar18 - 0x8a;
    iVar4 = 4;
    uVar15 = uVar19;
    if (uVar19 < 0x1a) {
      uVar15 = uVar19 * 4;
      switch(uVar19) {
      default:
        iVar4 = 4;
        break;
      case 4:
      case 5:
      case 6:
      case 7:
        iVar4 = 3;
        break;
      case 8:
      case 9:
      case 10:
      case 0xb:
        iVar4 = 1;
        break;
      case 0xc:
      case 0xd:
        iVar4 = 0;
        break;
      case 0xe:
      case 0x10:
      case 0x12:
      case 0x14:
        iVar4 = 7;
        break;
      case 0xf:
      case 0x11:
      case 0x13:
      case 0x15:
        iVar4 = 6;
        break;
      case 0x16:
      case 0x17:
        iVar4 = 2;
        break;
      case 0x18:
      case 0x19:
        iVar4 = 5;
      }
    }
    in_r6 = iVar21;
    __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_i
              (param_2,local_48,ppPVar23,iVar21);
    if (bVar17) {
      TPPStreamCompiler__getOperandAsSourceVar
                ((unsigned char *)&local_90,param_2,ppPVar23[1],in_r6,in_r7,uVar18,uVar15,uVar20);
      local_c0 = local_90;
      local_bc = local_8c;
      TPPStreamCompiler__getOperandAsSourceVar
                ((unsigned char *)&local_90,param_2,*ppPVar23,in_r6,in_r7,uVar18,uVar15,uVar20);
      local_b0 = iVar4 << 5 | local_b0 & 0xffffff1f;
      local_b8 = local_90;
      local_b4 = local_8c;
      if (iVar21 == 3) {
        TPPStreamCompiler__getOperandAsSourceVar
                  ((unsigned char *)&local_90,param_2,ppPVar23[2],in_r6,in_r7,uVar18,local_b0,uVar20)
        ;
        local_a8 = local_90;
        local_a4 = local_8c;
      }
    }
    local_d0[0] = (iVar21 + 1) * 0x20000000 | local_d0[0] & 0x1fffffff;
LAB_97bc11d8:
    TPPStreamCompiler__getOperandAsDestVar
              ((unsigned char *)&local_90,param_2,local_48[0],in_r6,in_r7,uVar18);
    local_c8 = local_90;
    local_c4 = local_8c;
    if ((*(int *)(this + 0x30) == 0x4c) || (*(int *)(this + 0x30) == 0x4d)) {
      local_d0[1] = ((uint)local_c0 >> 0xe & 1) << 0x1c | local_d0[1] & 0xefffffff;
      iVar4 = *(int *)*ppPVar23;
      if (iVar4 == 0) {
        uVar14 = *(ushort *)(*ppPVar23 + 0x18);
      }
      else {
        uVar14 = *(ushort *)(iVar4 + 0x2c);
      }
      uVar15 = GetPPStreamTypeForGLType(uVar14);
      local_d0[1] = (uVar15 & 7) << 0x17 | local_d0[1] & 0xfc7fffff;
      pPVar28 = *ppPVar23;
    }
    else {
      local_d0[1] = ((uint)local_90 >> 0xc & 1) << 0x1c | local_d0[1] & 0xefffffff;
      if (*(int *)local_48[0] == 0) {
        uVar14 = *(ushort *)(local_48[0] + 0x18);
      }
      else {
        uVar14 = *(ushort *)(*(int *)local_48[0] + 0x2c);
      }
      uVar15 = GetPPStreamTypeForGLType(uVar14);
      local_d0[1] = (uVar15 & 7) << 0x17 | local_d0[1] & 0xfc7fffff;
      pPVar28 = local_48;
    }
    iVar4 = ParseOperand__GetLogicalSize(pPVar28);
    local_d0[1] = (iVar4 + -1) * 0x4000000 & 0xc000000U | local_d0[1] & 0xf3ffffff;
    TPPStreamCompiler__AddOperation(param_2,local_48,(unsigned char *)local_d0,(char *)0x0,0);
  }
switchD_97bc03dc_caseD_25:
  if (*(int *)(this + 0x30) != 4) {
    ppPVar22 = ppPVar23;
    if (0 < iVar21) {
      do {
        pPVar28 = *ppPVar22;
        if ((pPVar28 != (unsigned char *)0x0) && (pPVar28 != local_48[0])) {
          __ZN12ParseOperandD1Ev(pPVar28);
          __ZdlPv(pPVar28);
        }
        iVar21 = iVar21 + -1;
        ppPVar22 = ppPVar22 + 1;
      } while (iVar21 != 0);
    }
    if (ppPVar23 != (unsigned char **)0x0) {
      _free(ppPVar23);
    }
  }
  return local_48[0];
}

/* TIntermSelection__compileNode @ 0x97bc1348 (2232 bytes) */
int TIntermSelection__compileNode(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  bool bVar1;
  bool bVar2;
  undefined *puVar3;
  undefined *a0;
  int *piVar4;
  unsigned char * pTVar5;
  unsigned char * pPVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  size_t sVar10;
  undefined4 in_r7;
  undefined4 *in_r8;
  char *pcVar12;
  undefined4 *puVar13;
  undefined4 uVar14;
  undefined4 in_r10;
  int iVar15;
  int iVar16;
  uint uVar17;
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
  size_t local_7c;
  undefined **local_70;
  undefined4 local_6c;
  uint local_4c;
  unsigned char * local_40;
  unsigned char * local_3c;
  unsigned char * local_38 [3];
  ushort uVar11;
  
  a0 = PTR_s_gl__IfEnd__a7b7d714;
  puVar3 = PTR_s_gl__IfElse__a7b7d710;
  pcVar12 = *(char **)(param_2 + 0x8c);
  *(char **)(param_2 + 0x8c) = pcVar12 + 1;
  local_38[0] = (unsigned char *)0x0;
  local_40 = (unsigned char *)0x0;
  local_3c = (unsigned char *)0x0;
  iVar15 = *(int *)(param_2 + 0x70);
  _sprintf(acStack_f0,"%s%d",puVar3,pcVar12);
  _sprintf(acStack_d0,"%s%d",(int)a0,(int)pcVar12);
  bVar2 = false;
  iVar16 = 1;
  (**(code **)(*(int *)this + 0x38))((unsigned char *)&local_70,this);
  local_70 = &PTR___ZN5TTypeD1Ev_a7b7d730;
  if ((local_4c & 0x1f80000) != 0) {
    pTVar5 = (unsigned char *)(**(code **)(*(int *)this + 0x3c))(this);
    local_40 = (unsigned char *)TPPStreamCompiler__newTemporary(param_2,pTVar5);
  }
  pPVar6 = (unsigned char *)
           (**(code **)(**(int **)(this + 0x30) + 0xc))(*(int **)(this + 0x30),param_2);
  ((int (*)())ParseSymbolTable__processOperand)(*(unsigned char **)(param_2 + 0x68),pPVar6);
  piVar4 = *(int **)(pPVar6 + 4);
  if (piVar4 != (int *)0x0) {
    iVar16 = *piVar4;
  }
  uVar17 = (uint)(piVar4 != (int *)0x0);
  bVar1 = uVar17 == 0;
  if (bVar1) {
    local_ac = 0;
    puVar13 = *(undefined4 **)this;
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
    local_80 = uVar17;
    local_7c = uVar17;
    local_80 = (*(code *)*puVar13)(this);
    TPPStreamCompiler__getOperandAsSourceVar
              ((unsigned char *)&local_70,param_2,pPVar6,pcVar12,in_r7,in_r8,puVar13,in_r10);
    local_ac = ((uint)local_70 >> 0xe & 1) << 0x1c | local_ac & 0xefffffff;
    local_9c = local_6c;
    local_a0 = local_70;
    if (*(int *)pPVar6 == 0) {
      uVar11 = *(ushort *)(pPVar6 + 0x18);
    }
    else {
      uVar11 = *(ushort *)(*(int *)pPVar6 + 0x2c);
    }
    uVar7 = GetPPStreamTypeForGLType(uVar11);
    local_ac = (uVar7 & 7) << 0x17 | local_ac & 0xfc7fffff;
    iVar8 = ParseOperand__GetLogicalSize(pPVar6);
    local_ac = (iVar8 + -1) * 0x4000000 & 0xc000000U | local_ac & 0xf3ffffff;
    local_7c = _strlen(acStack_f0);
    pcVar12 = acStack_f0;
    in_r7 = 0;
    TPPStreamCompiler__AddOperation
              (param_2,(unsigned char **)0x0,(unsigned char *)&local_b0,pcVar12,0);
  }
  if ((*(int *)(this + 0x34) != 0) && ((uVar17 != 1 || (iVar16 != 0)))) {
    iVar8 = TPPStreamCompiler__LastOperationIndex(param_2);
    local_3c = (unsigned char *)
               (**(code **)(**(int **)(this + 0x34) + 0xc))(*(int **)(this + 0x34),param_2);
    ((int (*)())ParseSymbolTable__processOperand)(*(unsigned char **)(param_2 + 0x68),local_3c);
    if ((bVar1) &&
       (((iVar9 = TPPStreamCompiler__LastOperationIndex(param_2), iVar9 - iVar8 == 1 &&
         (local_40 == (unsigned char *)0x0)) && (*(int *)(this + 0x38) == 0)))) {
      iVar8 = *(int *)(*(int *)(iVar15 + 0x20) + 4);
      if ((*(uint *)(iVar8 + 0xc) & 0x3fc0000) == 0x13c0000) {
        _PPStreamChunkListRemoveChunk(*(int *)(iVar15 + 0x20),iVar8);
        _PPStreamChunkListRemoveChunk
                  (*(int *)(iVar15 + 0x20),*(undefined4 *)(*(int *)(iVar15 + 0x20) + 4));
        uVar14 = 0x4f;
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
        local_80 = uVar17;
        local_7c = uVar17;
        local_80 = (*(code *)**(undefined4 **)this)(this);
        local_b0 = local_b0 & 0x1fffffff | 0x20000000;
        *(undefined4 *)(pPVar6 + 0x28) = 1;
        TPPStreamCompiler__getOperandAsSourceVar
                  ((unsigned char *)&local_70,param_2,pPVar6,pcVar12,in_r7,in_r8,uVar14,in_r10);
        local_ac = ((uint)local_70 >> 0xe & 1) << 0x1c | local_ac & 0xefffffff;
        local_9c = local_6c;
        local_a0 = local_70;
        if (*(int *)pPVar6 == 0) {
          uVar11 = *(ushort *)(pPVar6 + 0x18);
        }
        else {
          uVar11 = *(ushort *)(*(int *)pPVar6 + 0x2c);
        }
        uVar7 = GetPPStreamTypeForGLType(uVar11);
        local_ac = (uVar7 & 7) << 0x17 | local_ac & 0xfc7fffff;
        iVar8 = ParseOperand__GetLogicalSize(pPVar6);
        local_ac = (iVar8 + -1) * 0x4000000 & 0xc000000U | local_ac & 0xf3ffffff;
        pcVar12 = (char *)0x0;
        in_r7 = 0;
        TPPStreamCompiler__AddOperation
                  (param_2,(unsigned char **)0x0,(unsigned char *)&local_b0,(char *)0x0,0);
        bVar2 = true;
        __ZN12ParseOperandD1Ev(pPVar6);
        __ZdlPv(pPVar6);
        pPVar6 = local_3c;
        goto LAB_97bc18ac;
      }
    }
    if (pPVar6 != (unsigned char *)0x0) {
      __ZN12ParseOperandD1Ev(pPVar6);
      __ZdlPv(pPVar6);
    }
    pPVar6 = local_3c;
    if (local_40 != (unsigned char *)0x0) {
      uVar14 = 0;
      in_r10 = 0;
      local_ac = 0;
      in_r8 = *(undefined4 **)this;
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
      local_80 = (*(code *)*in_r8)(this);
      __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_
                (param_2,&local_40,&local_3c);
      TPPStreamCompiler__getOperandAsDestVar
                ((unsigned char *)&local_70,param_2,local_40,pcVar12,in_r7,in_r8);
      local_a8 = local_70;
      local_a4 = local_6c;
      TPPStreamCompiler__getOperandAsSourceVar
                ((unsigned char *)&local_70,param_2,local_3c,pcVar12,in_r7,in_r8,uVar14,in_r10);
      local_ac = ((uint)local_a8 >> 0xc & 1) << 0x1c | local_ac & 0xefffffff;
      local_a0 = local_70;
      local_9c = local_6c;
      if (*(int *)local_40 == 0) {
        uVar11 = *(ushort *)(local_40 + 0x18);
      }
      else {
        uVar11 = *(ushort *)(*(int *)local_40 + 0x2c);
      }
      uVar7 = GetPPStreamTypeForGLType(uVar11);
      local_ac = (uVar7 & 7) << 0x17 | local_ac & 0xfc7fffff;
      iVar8 = ParseOperand__GetLogicalSize(local_40);
      local_ac = (iVar8 + -1) * 0x4000000 & 0xc000000U | local_ac & 0xf3ffffff;
      pcVar12 = (char *)0x0;
      in_r7 = 0;
      TPPStreamCompiler__AddOperation
                (param_2,&local_40,(unsigned char *)&local_b0,(char *)0x0,0);
      pPVar6 = local_3c;
    }
  }
LAB_97bc18ac:
  if (pPVar6 != (unsigned char *)0x0) {
    __ZN12ParseOperandD1Ev(pPVar6);
    __ZdlPv(pPVar6);
  }
  piVar4 = *(int **)(this + 0x38);
  if ((piVar4 != (int *)0x0) && ((uVar17 != 1 || (iVar16 != 1)))) {
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
      local_80 = uVar17;
      local_7c = uVar17;
      local_80 = (*(code *)**(undefined4 **)this)(this);
      local_7c = _strlen(acStack_d0);
      in_r7 = 0;
      pcVar12 = acStack_d0;
      TPPStreamCompiler__AddOperation
                (param_2,(unsigned char **)0x0,(unsigned char *)&local_b0,acStack_d0,0);
      sVar10 = _strlen(acStack_f0);
      _PPStreamAddLabel(iVar15,acStack_f0,sVar10);
      piVar4 = *(int **)(this + 0x38);
    }
    local_38[0] = (unsigned char *)(**(code **)(*piVar4 + 0xc))(piVar4,param_2);
    ((int (*)())ParseSymbolTable__processOperand)(*(unsigned char **)(param_2 + 0x68),local_38[0]);
    if (local_40 != (unsigned char *)0x0) {
      local_ac = 0;
      uVar14 = 0;
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
      local_80 = (*(code *)**(undefined4 **)this)(this);
      local_b0 = local_b0 & 0x1fffffff | 0x20000000;
      __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_
                (param_2,&local_40,local_38);
      TPPStreamCompiler__getOperandAsDestVar
                ((unsigned char *)&local_70,param_2,local_40,pcVar12,in_r7,in_r8);
      local_a8 = local_70;
      local_a4 = local_6c;
      TPPStreamCompiler__getOperandAsSourceVar
                ((unsigned char *)&local_70,param_2,local_38[0],pcVar12,in_r7,in_r8,uVar14,in_r10);
      local_ac = ((uint)local_a8 >> 0xc & 1) << 0x1c | local_ac & 0xefffffff;
      local_a0 = local_70;
      local_9c = local_6c;
      if (*(int *)local_40 == 0) {
        uVar11 = *(ushort *)(local_40 + 0x18);
      }
      else {
        uVar11 = *(ushort *)(*(int *)local_40 + 0x2c);
      }
      uVar7 = GetPPStreamTypeForGLType(uVar11);
      local_ac = (uVar7 & 7) << 0x17 | local_ac & 0xfc7fffff;
      iVar16 = ParseOperand__GetLogicalSize(local_40);
      local_ac = (iVar16 + -1) * 0x4000000 & 0xc000000U | local_ac & 0xf3ffffff;
      TPPStreamCompiler__AddOperation
                (param_2,&local_40,(unsigned char *)&local_b0,(char *)0x0,0);
    }
    pPVar6 = local_38;
    if (local_38[0] != (unsigned char *)0x0) {
      __ZN12ParseOperandD1Ev(local_38[0]);
      __ZdlPv(pPVar6);
    }
  }
  if ((!bVar2) && (bVar1)) {
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
    local_80 = uVar17;
    local_7c = uVar17;
    local_80 = (*(code *)**(undefined4 **)this)(this);
    TPPStreamCompiler__AddOperation
              (param_2,(unsigned char **)0x0,(unsigned char *)&local_b0,(char *)0x0,0);
    pcVar12 = acStack_f0;
    if (*(int *)(this + 0x38) != 0) {
      pcVar12 = acStack_d0;
    }
    sVar10 = _strlen(pcVar12);
    pcVar12 = acStack_f0;
    if (*(int *)(this + 0x38) != 0) {
      pcVar12 = acStack_d0;
    }
    _PPStreamAddLabel(iVar15,pcVar12,sVar10);
  }
  return local_40;
}

/* TIntermLoop__compileNode @ 0x97bc1c00 (3000 bytes) */
int TIntermLoop__compileNode(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  int iVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  unsigned char * pPVar6;
  size_t sVar7;
  int *piVar8;
  unsigned char * pTVar9;
  uint uVar10;
  int iVar11;
  void *pvVar12;
  char *pcVar14;
  undefined4 uVar15;
  undefined *puVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  int *piVar20;
  int iVar21;
  int iVar22;
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
  size_t local_7c;
  uint local_70;
  undefined4 local_6c;
  unsigned char * local_60;
  unsigned char * local_5c [6];
  ushort uVar13;
  
  puVar5 = PTR_s_gl__WhileEndIf__a7b7d724;
  puVar4 = PTR_s_gl__WhileStart__a7b7d720;
  puVar3 = PTR_s_gl__WhileEnd__a7b7d71c;
  puVar2 = PTR_s_gl__WhileBody__a7b7d718;
  iVar22 = *(int *)(param_2 + 0x8c);
  iVar21 = *(int *)(param_2 + 0x70);
  *(int *)(param_2 + 0x8c) = iVar22 + 1;
  local_60 = (unsigned char *)0x0;
  local_5c[0] = (unsigned char *)0x0;
  piVar20 = *(int **)(iVar21 + 0x20);
  if ((((*(int *)(param_2 + 0xc4) < 2) || (*(int *)(this + 0xc) != 0)) || (*(int *)(this + 8) != 0))
     || (*(int *)(this + 0x10) != 0)) {
    puVar16 = puVar5;
    _sprintf(acStack_130,"%s%d",puVar2,iVar22);
    _sprintf(acStack_110,"%s%d",puVar3,iVar22);
    _sprintf(acStack_f0,"%s%d",puVar4,iVar22);
    _sprintf(acStack_d0,"%s%d",puVar5,iVar22);
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
    local_80 = (*(code *)**(undefined4 **)this)(this);
    local_7c = _strlen(acStack_110);
    uVar15 = 0;
    pcVar14 = acStack_110;
    TPPStreamCompiler__AddOperation
              (param_2,(unsigned char **)0x0,(unsigned char *)&local_b0,acStack_110,0);
    iVar22 = 0;
    for (iVar11 = *piVar20; iVar11 != 0; iVar11 = *(int *)(iVar11 + 8)) {
      iVar22 = iVar11;
    }
    sVar7 = _strlen(acStack_f0);
    _PPStreamAddLabel(iVar21,acStack_f0,sVar7);
    if ((*(int *)(this + 0x14) != 0) && (piVar8 = *(int **)(this + 0xc), piVar8 != (int *)0x0)) {
      local_5c[0] = (unsigned char *)(**(code **)(*piVar8 + 0xc))(piVar8,param_2);
      ((int (*)())ParseSymbolTable__processOperand)(*(unsigned char **)(param_2 + 0x68),local_5c[0]);
      pTVar9 = (unsigned char *)(**(code **)(**(int **)(this + 0xc) + 0x3c))();
      local_60 = (unsigned char *)TPPStreamCompiler__newTemporary(param_2,pTVar9);
      uVar17 = 0;
      uVar18 = 0;
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
      local_80 = (*(code *)**(undefined4 **)this)(this);
      __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_
                (param_2,&local_60,local_5c);
      TPPStreamCompiler__getOperandAsDestVar
                ((unsigned char *)&local_70,param_2,local_60,pcVar14,uVar15,puVar16);
      local_a8 = local_70;
      local_a4 = local_6c;
      TPPStreamCompiler__getOperandAsSourceVar
                ((unsigned char *)&local_70,param_2,local_5c[0],pcVar14,uVar15,puVar16,uVar17,uVar18)
      ;
      local_ac = (local_a8 >> 0xc & 1) << 0x1c | local_ac & 0xefffffff;
      local_a0 = local_70;
      local_9c = local_6c;
      if (*(int *)local_60 == 0) {
        uVar13 = *(ushort *)(local_60 + 0x18);
      }
      else {
        uVar13 = *(ushort *)(*(int *)local_60 + 0x2c);
      }
      uVar10 = GetPPStreamTypeForGLType(uVar13);
      local_ac = (uVar10 & 7) << 0x17 | local_ac & 0xfc7fffff;
      iVar11 = ParseOperand__GetLogicalSize(local_60);
      local_ac = (iVar11 + -1) * 0x4000000 & 0xc000000U | local_ac & 0xf3ffffff;
      uVar15 = 0;
      uVar17 = 0;
      TPPStreamCompiler__AddOperation
                (param_2,&local_60,(unsigned char *)&local_b0,(char *)0x0,0);
      uVar18 = 0;
      uVar19 = 0;
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
      local_80 = (*(code *)**(undefined4 **)this)(this);
      TPPStreamCompiler__getOperandAsSourceVar
                ((unsigned char *)&local_70,param_2,local_60,uVar15,uVar17,puVar16,uVar18,uVar19);
      local_ac = (local_70 >> 0xe & 1) << 0x1c | local_ac & 0xefffffff;
      local_9c = local_6c;
      local_a0 = local_70;
      if (*(int *)local_60 == 0) {
        uVar13 = *(ushort *)(local_60 + 0x18);
      }
      else {
        uVar13 = *(ushort *)(*(int *)local_60 + 0x2c);
      }
      uVar10 = GetPPStreamTypeForGLType(uVar13);
      local_ac = (uVar10 & 7) << 0x17 | local_ac & 0xfc7fffff;
      iVar11 = ParseOperand__GetLogicalSize(local_60);
      local_ac = (iVar11 + -1) * 0x4000000 & 0xc000000U | local_ac & 0xf3ffffff;
      local_7c = _strlen(acStack_d0);
      TPPStreamCompiler__AddOperation
                (param_2,(unsigned char **)0x0,(unsigned char *)&local_b0,acStack_d0,0);
      pPVar6 = local_60;
      if (local_60 != (unsigned char *)0x0) {
        __ZN12ParseOperandD1Ev(local_60);
        __ZdlPv(pPVar6);
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
      local_80 = (*(code *)**(undefined4 **)this)(this);
      local_7c = _strlen(acStack_110);
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
      local_80 = (*(code *)**(undefined4 **)this)(this);
      pcVar14 = (char *)0x0;
      uVar15 = 0;
      TPPStreamCompiler__AddOperation
                (param_2,(unsigned char **)0x0,(unsigned char *)&local_b0,(char *)0x0,0);
      sVar7 = _strlen(acStack_d0);
      _PPStreamAddLabel(iVar21,acStack_d0,sVar7);
      pPVar6 = local_5c;
      if (local_5c[0] != (unsigned char *)0x0) {
        __ZN12ParseOperandD1Ev(local_5c[0]);
        __ZdlPv(pPVar6);
      }
    }
    piVar8 = *(int **)(this + 8);
    if ((piVar8 != (int *)0x0) &&
       (pvVar12 = (void *)(**(code **)(*piVar8 + 0xc))(piVar8,param_2), pvVar12 != (void *)0x0)) {
      __ZN12ParseOperandD1Ev(pvVar12);
      __ZdlPv(pvVar12);
    }
    sVar7 = _strlen(acStack_130);
    _PPStreamAddLabel(iVar21,acStack_130,sVar7);
    piVar8 = *(int **)(this + 0x10);
    if ((piVar8 != (int *)0x0) &&
       (pvVar12 = (void *)(**(code **)(*piVar8 + 0xc))(piVar8,param_2), pvVar12 != (void *)0x0)) {
      __ZN12ParseOperandD1Ev(pvVar12);
      __ZdlPv(pvVar12);
    }
    iVar11 = *(int *)(this + 0x14);
    if ((iVar11 == 0) && (piVar8 = *(int **)(this + 0xc), piVar8 != (int *)0x0)) {
      local_5c[0] = (unsigned char *)(**(code **)(*piVar8 + 0xc))(piVar8,param_2);
      ((int (*)())ParseSymbolTable__processOperand)(*(unsigned char **)(param_2 + 0x68),local_5c[0]);
      pTVar9 = (unsigned char *)(**(code **)(**(int **)(this + 0xc) + 0x3c))();
      local_60 = (unsigned char *)TPPStreamCompiler__newTemporary(param_2,pTVar9);
      uVar17 = 0;
      uVar18 = 0;
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
      local_80 = iVar11;
      local_7c = iVar11;
      local_80 = (*(code *)**(undefined4 **)this)(this);
      __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_
                (param_2,&local_60,local_5c);
      TPPStreamCompiler__getOperandAsDestVar
                ((unsigned char *)&local_70,param_2,local_60,pcVar14,uVar15,puVar16);
      local_a8 = local_70;
      local_a4 = local_6c;
      TPPStreamCompiler__getOperandAsSourceVar
                ((unsigned char *)&local_70,param_2,local_5c[0],pcVar14,uVar15,puVar16,uVar17,uVar18)
      ;
      local_ac = (local_a8 >> 0xc & 1) << 0x1c | local_ac & 0xefffffff;
      local_a0 = local_70;
      local_9c = local_6c;
      if (*(int *)local_60 == 0) {
        uVar13 = *(ushort *)(local_60 + 0x18);
      }
      else {
        uVar13 = *(ushort *)(*(int *)local_60 + 0x2c);
      }
      uVar10 = GetPPStreamTypeForGLType(uVar13);
      local_ac = (uVar10 & 7) << 0x17 | local_ac & 0xfc7fffff;
      iVar11 = ParseOperand__GetLogicalSize(local_60);
      local_ac = (iVar11 + -1) * 0x4000000 & 0xc000000U | local_ac & 0xf3ffffff;
      uVar15 = 0;
      uVar17 = 0;
      TPPStreamCompiler__AddOperation
                (param_2,&local_60,(unsigned char *)&local_b0,(char *)0x0,0);
      uVar18 = 0;
      uVar19 = 0;
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
      local_80 = (*(code *)**(undefined4 **)this)(this);
      TPPStreamCompiler__getOperandAsSourceVar
                ((unsigned char *)&local_70,param_2,local_60,uVar15,uVar17,puVar16,uVar18,uVar19);
      local_ac = (local_70 >> 0xe & 1) << 0x1c | local_ac & 0xefffffff;
      local_9c = local_6c;
      local_a0 = local_70;
      if (*(int *)local_60 == 0) {
        uVar13 = *(ushort *)(local_60 + 0x18);
      }
      else {
        uVar13 = *(ushort *)(*(int *)local_60 + 0x2c);
      }
      uVar10 = GetPPStreamTypeForGLType(uVar13);
      local_ac = (uVar10 & 7) << 0x17 | local_ac & 0xfc7fffff;
      iVar11 = ParseOperand__GetLogicalSize(local_60);
      local_ac = (iVar11 + -1) * 0x4000000 & 0xc000000U | local_ac & 0xf3ffffff;
      local_7c = _strlen(acStack_d0);
      TPPStreamCompiler__AddOperation
                (param_2,(unsigned char **)0x0,(unsigned char *)&local_b0,acStack_d0,0);
      pPVar6 = local_60;
      if (local_60 != (unsigned char *)0x0) {
        __ZN12ParseOperandD1Ev(local_60);
        __ZdlPv(pPVar6);
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
      local_80 = (*(code *)**(undefined4 **)this)(this);
      local_7c = _strlen(acStack_110);
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
      local_80 = (*(code *)**(undefined4 **)this)(this);
      TPPStreamCompiler__AddOperation
                (param_2,(unsigned char **)0x0,(unsigned char *)&local_b0,(char *)0x0,0);
      sVar7 = _strlen(acStack_d0);
      _PPStreamAddLabel(iVar21,acStack_d0,sVar7);
      pPVar6 = local_5c;
      if (local_5c[0] != (unsigned char *)0x0) {
        __ZN12ParseOperandD1Ev(local_5c[0]);
        __ZdlPv(pPVar6);
      }
    }
    ParseWhileLoopStack__pop((unsigned char *)(param_2 + 0x5c));
    iVar11 = 0;
    for (iVar1 = iVar22; iVar1 != 0; iVar1 = *(int *)(iVar1 + 8)) {
      iVar11 = iVar1;
    }
    if ((*(int *)(param_2 + 0xc4) < 2) || (iVar11 != iVar22)) {
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
      local_80 = (*(code *)**(undefined4 **)this)(this);
      local_7c = _strlen(acStack_f0);
      TPPStreamCompiler__AddOperation
                (param_2,(unsigned char **)0x0,(unsigned char *)&local_b0,acStack_f0,0);
      sVar7 = _strlen(acStack_110);
      _PPStreamAddLabel(iVar21,acStack_110,sVar7);
    }
    else {
      _PPStreamChunkListRemoveChunk(piVar20,iVar11);
      iVar22 = 0;
      for (iVar11 = **(int **)(iVar21 + 0x24); iVar11 != 0; iVar11 = *(int *)(iVar11 + 8)) {
        iVar22 = iVar11;
      }
      _PPStreamChunkListRemoveChunk(*(int **)(iVar21 + 0x24),iVar22);
    }
  }
  return 0;
}

/* TIntermBranch__compileNode @ 0x97bc27b8 (1420 bytes) */
int TIntermBranch__compileNode(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  ushort uVar1;
  int iVar2;
  unsigned char * pPVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  int *piVar8;
  int iVar9;
  unsigned char * this_00;
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
  size_t local_7c;
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
  local_80 = (*(code *)**(undefined4 **)this)();
  piVar8 = *(int **)(this + 0xc);
  local_b0 = local_b0 & 0x1fffffff;
  if (piVar8 != (int *)0x0) {
    local_24 = (unsigned char *)(**(code **)(*piVar8 + 0xc))(piVar8,param_2);
    ((int (*)())ParseSymbolTable__processOperand)(*(unsigned char **)(param_2 + 0x68),local_24);
  }
  iVar4 = *(int *)(this + 8);
  if (iVar4 == 99) {
    this_00 = (unsigned char *)(param_2 + 0x58);
    iVar9 = 0;
    pcVar7 = (char *)ParseFunctionStack__current(this_00);
    iVar4 = ParseFunctionStack__getCurrentNumParams(this_00);
    iVar5 = ParseFunctionStack__getCurrentParamList(this_00);
    local_b0 = local_b0 & 0xfc03ffff;
    if (0 < iVar4) {
      do {
        iVar2 = iVar9 * 4;
        if ((*(int **)(iVar2 + iVar5) != (int *)0x0) &&
           ((iVar6 = (**(code **)(**(int **)(**(int **)(iVar2 + iVar5) + 0xc) + 0x24))(),
            iVar6 == 10 ||
            (iVar6 = (**(code **)(**(int **)(**(int **)(iVar2 + iVar5) + 0xc) + 0x24))(),
            iVar6 == 0xb)))) {
          local_2c = (unsigned char *)
                     TPPStreamCompiler__newParam
                               (param_2,*(unsigned char **)(**(int **)(iVar2 + iVar5) + 0xc),pcVar7,iVar9);
          TPPStreamCompiler__assignOperands
                    (param_2,&local_2c,(unsigned char **)(iVar2 + iVar5),false);
          pPVar3 = local_2c;
          if (local_2c != (unsigned char *)0x0) {
            __ZN12ParseOperandD1Ev(local_2c);
            __ZdlPv(pPVar3);
          }
        }
        iVar9 = iVar9 + 1;
      } while (iVar9 < iVar4);
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
      TPPStreamCompiler__assignOperands(param_2,&local_28,&local_24,false);
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
    local_80 = (*(code *)**(undefined4 **)this)(this);
    local_b0 = local_b0 & 0x1fffffff | 0x20000000;
    local_30 = 0xbf800000;
    TPPStreamCompiler__getConstantAsSourceVar
              ((unsigned char *)&local_70,(uint)param_2,(short)&STACKARG(0xffffff10) + 0xc0,1,0x1406);
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
    local_80 = (*(code *)**(undefined4 **)this)(this);
    pcVar7 = (char *)ParseWhileLoopStack__breakLabel((unsigned char *)(param_2 + 0x5c));
    local_7c = _strlen(pcVar7);
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
    local_80 = (*(code *)**(undefined4 **)this)(this);
    pcVar7 = (char *)ParseWhileLoopStack__continueLabel((unsigned char *)(param_2 + 0x5c));
    local_7c = _strlen(pcVar7);
    pcVar7 = (char *)ParseWhileLoopStack__continueLabel((unsigned char *)(param_2 + 0x5c));
  }
  TPPStreamCompiler__AddOperation
            (param_2,(unsigned char **)0x0,(unsigned char *)&local_b0,pcVar7,0);
  return 0;
}

/* TIntermSymbol__indirectNode @ 0x97bc2d44 (312 bytes) */
int TIntermSymbol__indirectNode(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  undefined1 *puVar1;
  int iVar2;
  undefined4 uVar3;
  unsigned char * this_00;
  unsigned char * pTVar4;
  undefined4 *this_01;
  
  this_01 = (undefined4 *)0x0;
  iVar2 = (**(code **)(*(int *)this + 0x60))();
  puVar1 = DAT_a7b7bd0c;
  *(undefined1 *)(*(int *)(iVar2 + 4) + *(int *)(*(int *)(iVar2 + 4) + -0xc)) = *DAT_a7b7bd0c;
  if (**(char **)(iVar2 + 4) != '\0') {
    uVar3 = (*(code *)**(undefined4 **)this)(this);
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
int TIntermConstantUnion__indirectNode(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  int iVar1;
  uint uVar2;
  undefined2 uVar3;
  void *this_00;
  undefined4 uVar4;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 in_r9;
  undefined4 in_r10;
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
                  (SUB41(param_2,0),(char *)0x1,(char *)0x0,
                   "TIntermConstantUnion::indirectNode: EbtStruct constant union type, investigate",
                   in_r7,in_r8,in_r9,in_r10);
      }
    }
    TPPStreamCompiler__error
              (SUB41(param_2,0),(char *)0x1,(char *)0x0,
               "TIntermConstantUnion::indirectNode: Unexpected constant union type",in_r7,in_r8,
               in_r9,in_r10);
  }
  return this_00;
}

/* TIntermBinary__indirectNode @ 0x97bc2fd0 (1000 bytes) */
int TIntermBinary__indirectNode(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  bool bVar9;
  unsigned char * pPVar5;
  unsigned char * pTVar6;
  unsigned char * pPVar7;
  unsigned char * this_00;
  int iVar8;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 in_r9;
  uint *puVar10;
  undefined4 in_r10;
  void *this_01;
  unsigned char * this_02;
  uint uVar11;
  undefined **local_60 [2];
  int local_58;
  undefined **local_50;
  uint local_4c;
  
  this_02 = (unsigned char *)0x0;
  this_01 = (void *)0x0;
  uVar3 = (*(code *)**(undefined4 **)this)();
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
  bVar9 = SUB41(param_2,0);
  if (iVar2 == 0x2d) {
    uVar11 = **(uint **)((int)this_01 + 4);
    pPVar7 = this_02;
    if (*(int *)(*(unsigned char **)this_02 + 0x4c) == 0) goto LAB_97bc3364;
    ParseSymbol__AddDirectIndex(*(unsigned char **)this_02,uVar11);
    _sprintf((char *)local_60,"[%d]",uVar11);
    ParseSymbol__CatName(*(unsigned char **)this_02,(char *)local_60);
    iVar2 = (**(code **)(*(int *)this + 0x54))(this);
    if (iVar2 != 0) {
      TPPStreamCompiler__error
                (bVar9,(char *)0x1,(char *)0x0,
                 "TIntermBinary::: Array index results in another array, this is not handled",in_r7,
                 in_r8,in_r9,in_r10);
      goto LAB_97bc3364;
    }
    pPVar5 = *(unsigned char **)this_02;
    *(undefined4 *)(pPVar5 + 0x48) = 1;
  }
  else {
    if (iVar2 == 0x2e) {
      if (*(int *)this_02 == 0) {
        pTVar6 = (unsigned char *)(**(code **)(**(int **)(this + 0x34) + 0x3c))();
        pPVar7 = (unsigned char *)
                 TPPStreamCompiler__newIndirectOperandFromConstant(param_2,this_02,pTVar6);
        __ZN12ParseOperandD1Ev(this_02);
        __ZdlPv(this_02);
        bVar1 = pPVar7 == (unsigned char *)0x0;
        this_02 = pPVar7;
      }
      else {
        if (*(int *)(*(int *)this_02 + 0x4c) == 0) {
          piVar4 = (int *)(**(code **)(**(int **)(this + 0x34) + 0x3c))();
          iVar2 = (**(code **)(*piVar4 + 0x34))();
          pPVar7 = this_02;
          if (iVar2 == 0) goto LAB_97bc3364;
          this_00 = *(unsigned char **)(param_2 + 0x68);
          *(undefined4 *)(param_2 + 0xa8) = 1;
        }
        else {
          (**(code **)(**(int **)(this + 0x34) + 0x38))(&local_50);
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
    (**(code **)(**(int **)(this + 0x34) + 0x38))(local_60);
    local_60[0] = &PTR___ZN5TTypeD1Ev_a7b7d778;
    puVar10 = *(uint **)((int)this_01 + 4);
    uVar11 = *puVar10;
    if (pPVar5 == (unsigned char *)0x0) {
      TPPStreamCompiler__error
                (bVar9,(char *)0x1,(char *)0x0,
                 "TIntermBinary::indirectNode: Structure symbol, parse error.",in_r7,in_r8,puVar10,
                 in_r10);
    }
    if (local_58 == 0) {
      TPPStreamCompiler__error
                (bVar9,(char *)0x1,(char *)0x0,
                 "TIntermBinary::indirectNode: No structure fields, parse error.",in_r7,in_r8,
                 puVar10,in_r10);
    }
    if ((uint)(*(int *)(local_58 + 8) - *(int *)(local_58 + 4) >> 3) <= uVar11) {
      TPPStreamCompiler__error
                (bVar9,(char *)0x1,(char *)0x0,
                 "TIntermBinary::indirectNode: Structure index too big for field size, parse error",
                 in_r7,in_r8,puVar10,in_r10);
    }
    iVar2 = uVar11 * 8;
    ParseSymbol__CatName(pPVar5,".");
    iVar8 = (**(code **)(**(int **)(*(int *)(local_58 + 4) + iVar2) + 0x1c))();
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
  
  uVar1 = (*(code *)**(undefined4 **)this)();
  *(undefined4 *)(param_2 + 0x90) = uVar1;
  this_00 = (void *)(**(code **)(**(int **)(this + 0x34) + 0x10))(*(int **)(this + 0x34),param_2);
  if (this_00 != (void *)0x0) {
    __ZN12ParseOperandD1Ev(this_00);
    __ZdlPv(this_00);
  }
  return 0;
}

/* TIntermAggregate__indirectNode @ 0x97bc3428 (232 bytes) */
int TIntermAggregate__indirectNode(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  void *this_00;
  
  iVar3 = *(int *)(this + 0x3c) - *(int *)(this + 0x38) >> 2;
  uVar1 = (*(code *)**(undefined4 **)this)();
  *(undefined4 *)(param_2 + 0x90) = uVar1;
  puVar2 = _malloc(iVar3 << 2);
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
    pvVar1 = (void *)(**(code **)(**(int **)(this + 0x30) + 0x10))();
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
  void *pvVar1;
  int *piVar2;
  
  if (*(int **)(this + 0xc) != (int *)0x0) {
    pvVar1 = (void *)(**(code **)(**(int **)(this + 0xc) + 0x10))();
    if (pvVar1 != (void *)0x0) {
      __ZN12ParseOperandD1Ev(pvVar1);
      __ZdlPv(pvVar1);
    }
  }
  piVar2 = *(int **)(this + 8);
  if (piVar2 != (int *)0x0) {
    pvVar1 = (void *)(**(code **)(*piVar2 + 0x10))(piVar2,param_2);
    if (pvVar1 != (void *)0x0) {
      __ZN12ParseOperandD1Ev(pvVar1);
      __ZdlPv(pvVar1);
    }
  }
  piVar2 = *(int **)(this + 0x10);
  if ((piVar2 != (int *)0x0) &&
     (pvVar1 = (void *)(**(code **)(*piVar2 + 0x10))(piVar2,param_2), pvVar1 != (void *)0x0)) {
    __ZN12ParseOperandD1Ev(pvVar1);
    __ZdlPv(pvVar1);
  }
  return 0;
}

/* TIntermBranch__indirectNode @ 0x97bc36a4 (88 bytes) */
int TIntermBranch__indirectNode(param_1)
  unsigned char * param_1;
{
  void *this;
  
  if ((*(int **)(param_1 + 0xc) != (int *)0x0) &&
     (this = (void *)(**(code **)(**(int **)(param_1 + 0xc) + 0x10))(), this != (void *)0x0)) {
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
  if (*(void **)this == (void *)0x0) {
    return;
  }
  _free(*(void **)this);
  return;
}

/* ConstantAllocationList__clear @ 0x97bc3734 (68 bytes) */
int ConstantAllocationList__clear(this)
  unsigned char * this;
{
  if (*(void **)this != (void *)0x0) {
    _free(*(void **)this);
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
  void *pvVar3;
  void *pvVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  uint uVar9;
  int iVar10;
  
  uVar9 = *(uint *)(this + 4);
  if ((uVar9 & 0xf) == 0) {
    pvVar3 = _malloc(uVar9 * 0x18 + 0x180);
    _memset(pvVar3,0,*(int *)(this + 4) * 0x18 + 0x180);
    uVar9 = *(uint *)(this + 4);
    iVar5 = 0;
    if ((int)uVar9 < 1) {
      pvVar4 = *(void **)this;
    }
    else {
      pvVar4 = *(void **)this;
      iVar10 = 0;
      do {
        uVar7 = *(undefined4 *)((int)pvVar4 + iVar10 + 4);
        iVar5 = iVar5 + 1;
        uVar8 = *(undefined4 *)((int)pvVar4 + iVar10 + 8);
        uVar6 = *(undefined4 *)((int)pvVar4 + iVar10 + 0xc);
        *(undefined4 *)(iVar10 + (int)pvVar3) = *(undefined4 *)(iVar10 + (int)pvVar4);
        *(undefined4 *)((int)pvVar3 + iVar10 + 4) = uVar7;
        *(undefined4 *)((int)pvVar3 + iVar10 + 8) = uVar8;
        *(undefined4 *)((int)pvVar3 + iVar10 + 0xc) = uVar6;
        uVar6 = *(undefined4 *)((int)pvVar4 + iVar10 + 0x10);
        *(undefined4 *)((int)pvVar3 + iVar10 + 0x14) = *(undefined4 *)((int)pvVar4 + iVar10 + 0x14);
        *(undefined4 *)((int)pvVar3 + iVar10 + 0x10) = uVar6;
        iVar10 = iVar10 + 0x18;
      } while (iVar5 < (int)uVar9);
    }
    if (pvVar4 != (void *)0x0) {
      _free(pvVar4);
      uVar9 = *(uint *)(this + 4);
    }
    *(void **)this = pvVar3;
  }
  iVar5 = 0;
  *(int *)(uVar9 * 0x18 + *(int *)this) = param_2;
  iVar10 = 4;
  *(ushort *)(*(int *)(this + 4) * 0x18 + *(int *)this + 0x14) = param_4;
  do {
    pbVar1 = param_3 + iVar5;
    iVar2 = iVar5 + *(int *)(this + 4) * 0x18 + *(int *)this;
    iVar5 = iVar5 + 4;
    *(undefined4 *)(iVar2 + 4) = *(undefined4 *)pbVar1;
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  *(int *)(this + 4) = *(int *)(this + 4) + 1;
  return;
}

/* ConstantAllocationList__updateConstant @ 0x97bc38b8 (128 bytes) */
int ConstantAllocationList__updateConstant(this, param_2, param_3, param_4)
  unsigned char * this;
  int param_2;
  bool *param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined2 in_register_00000018;
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
  if ((uint)*(ushort *)(iVar3 * 0x18 + iVar5 + 0x14) == CONCAT22(in_register_00000018,param_4)) {
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
  
  puVar2 = _malloc(8);
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

