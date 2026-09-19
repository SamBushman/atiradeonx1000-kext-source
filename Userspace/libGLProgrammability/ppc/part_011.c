#include "decls.h"

/* ParseOperand__GetSwizzle @ 0x97bbbfc0 (12 bytes) */
int ParseOperand__GetSwizzle(this, param_1)
  unsigned char * this;
  uint param_1;
{
  return *(undefined1 *)(param_1 + *(int *)(this + 0x10));
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
  uint uVar7;
  char *pcVar8;
  uint uVar9;
  
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
    for (uVar9 = 0; uVar7 = ParseOperand__GetBaseSize(this), uVar9 < uVar7; uVar9 = uVar9 + 1) {
      if (uVar9 != 0) {
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
        _strlen(pcVar6);
        _strlen(pcVar6);
        iVar3 = uVar9 * 4;
        ((char * (*)())_glp_dtostr)((double)*(float *)(iVar3 + *(int *)(this + 4)),DOUBLE_97c30a70);
LAB_97bbc1b0:
        pcVar8 = *(char **)(iVar3 + *(int *)(this + 4));
        pcVar5 = DAT_a7b7bbe8;
LAB_97bbc1ec:
        _sprintf(pcVar6,pcVar5,pcVar6,pcVar8);
      }
      else if (uVar2 < 0x1407) {
        if (uVar2 == 0x1404) {
          iVar3 = uVar9 << 2;
          goto LAB_97bbc1b0;
        }
      }
      else if (uVar2 == 0x8b56) {
        pcVar5 = DAT_a7b7bbc4;
        if (*(int *)(uVar9 * 4 + *(int *)(this + 4)) == 0) {
          pcVar8 = "false";
        }
        else {
          pcVar8 = "true";
        }
        goto LAB_97bbc1ec;
      }
    }
  }
  return pcVar6;
}

/* ParseSymbolTable__ParseSymbolTable @ 0x97bbc258 (4 bytes) */
int ParseSymbolTable__ParseSymbolTable(this, param_1)
  unsigned char * this;
  uint param_1;
{
  int iVar1;
  void *pvVar2;
  uint uVar3;
  
  *(uint *)(this + 0x10) = param_1;
  pvVar2 = operator_new__(param_1 << 2);
  uVar3 = 0;
  *(void **)(this + 8) = pvVar2;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)this = 0;
  if (*(int *)(this + 0x10) != 0) {
    do {
      iVar1 = uVar3 * 4;
      uVar3 = uVar3 + 1;
      *(undefined4 *)(iVar1 + *(int *)(this + 8)) = 0;
    } while (uVar3 < *(uint *)(this + 0x10));
  }
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x40) = 0;
  *(undefined4 *)(this + 0x44) = 0;
  *(undefined4 *)(this + 0x48) = 0;
  *(undefined4 *)(this + 0x4c) = 0;
  *(undefined4 *)(this + 0x50) = 0;
  return;
}

/* ParseSymbolTable__ParseSymbolTable_97bbc25c @ 0x97bbc25c (4 bytes) */
int ParseSymbolTable__ParseSymbolTable_97bbc25c(this, param_1)
  unsigned char * this;
  uint param_1;
{
  int iVar1;
  void *pvVar2;
  uint uVar3;
  
  *(uint *)(this + 0x10) = param_1;
  pvVar2 = operator_new__(param_1 << 2);
  uVar3 = 0;
  *(void **)(this + 8) = pvVar2;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)this = 0;
  if (*(int *)(this + 0x10) != 0) {
    do {
      iVar1 = uVar3 * 4;
      uVar3 = uVar3 + 1;
      *(undefined4 *)(iVar1 + *(int *)(this + 8)) = 0;
    } while (uVar3 < *(uint *)(this + 0x10));
  }
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x40) = 0;
  *(undefined4 *)(this + 0x44) = 0;
  *(undefined4 *)(this + 0x48) = 0;
  *(undefined4 *)(this + 0x4c) = 0;
  *(undefined4 *)(this + 0x50) = 0;
  return;
}

/* ParseSymbolTable__ParseSymbolTable_97bbc260 @ 0x97bbc260 (184 bytes) */
int ParseSymbolTable__ParseSymbolTable_97bbc260(this, param_1)
  unsigned char * this;
  uint param_1;
{
  int iVar1;
  void *pvVar2;
  uint uVar3;
  
  *(uint *)(this + 0x10) = param_1;
  pvVar2 = operator_new__(param_1 << 2);
  uVar3 = 0;
  *(void **)(this + 8) = pvVar2;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)this = 0;
  if (*(int *)(this + 0x10) != 0) {
    do {
      iVar1 = uVar3 * 4;
      uVar3 = uVar3 + 1;
      *(undefined4 *)(iVar1 + *(int *)(this + 8)) = 0;
    } while (uVar3 < *(uint *)(this + 0x10));
  }
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x40) = 0;
  *(undefined4 *)(this + 0x44) = 0;
  *(undefined4 *)(this + 0x48) = 0;
  *(undefined4 *)(this + 0x4c) = 0;
  *(undefined4 *)(this + 0x50) = 0;
  return;
}

/* ParseSymbolTable___ParseSymbolTable @ 0x97bbc318 (8 bytes) */
int ParseSymbolTable___ParseSymbolTable(this)
  unsigned char * this;
{
  ~ParseSymbolTable(this);
  return;
}

/* ParseSymbolTable___ParseSymbolTable_97bbc320 @ 0x97bbc320 (8 bytes) */
int ParseSymbolTable___ParseSymbolTable_97bbc320(this)
  unsigned char * this;
{
  ~ParseSymbolTable(this);
  return;
}

/* ParseSymbolTable___ParseSymbolTable_97bbc328 @ 0x97bbc328 (92 bytes) */
int ParseSymbolTable___ParseSymbolTable_97bbc328(this)
  unsigned char * this;
{
  unsigned char * this_00;
  unsigned char * pPVar1;
  
  this_00 = *(unsigned char **)this;
  while (this_00 != (unsigned char *)0x0) {
    pPVar1 = *(unsigned char **)(this_00 + 8);
    ParseSymbol___ParseSymbol(this_00);
    operator_delete(this_00);
    this_00 = pPVar1;
  }
  operator_delete(*(void **)(this + 8));
  return;
}

/* ParseSymbolTable__processOperand @ 0x97bbc384 (252 bytes) */
int ParseSymbolTable__processOperand(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  bool bVar1;
  unsigned char * pPVar2;
  int iVar3;
  unsigned char * this_00;
  
  if (((param_1 != (unsigned char *)0x0) &&
      (this_00 = *(unsigned char **)param_1, this_00 != (unsigned char *)0x0)) &&
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
      ParseSymbol___ParseSymbol(this_00);
      operator_delete(this_00);
      bVar1 = false;
    }
    if (((!bVar1) && (*(unsigned char **)param_1 = pPVar2, *(int *)(pPVar2 + 0x34) != 0)) &&
       (iVar3 = GetBuiltInInitialSwizzle(pPVar2), iVar3 != 0)) {
      ParseOperand__AddSwizzle(param_1,(uchar)iVar3);
      return;
    }
  }
  return;
}

/* ParseSymbolTable__AddSymbol @ 0x97bbc480 (140 bytes) */
int ParseSymbolTable__AddSymbol(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(this + 4) == 0) {
    *(unsigned char **)this = param_1;
    iVar3 = *(int *)(this + 8);
    iVar1 = (*(uint *)(param_1 + 0x1c) -
            (*(uint *)(param_1 + 0x1c) / *(uint *)(this + 0x10)) * *(uint *)(this + 0x10)) * 4;
  }
  else {
    *(unsigned char **)(*(int *)(this + 4) + 8) = param_1;
    iVar3 = *(int *)(this + 8);
    iVar1 = (*(uint *)(param_1 + 0x1c) -
            (*(uint *)(param_1 + 0x1c) / *(uint *)(this + 0x10)) * *(uint *)(this + 0x10)) * 4;
    iVar2 = *(int *)(iVar1 + iVar3);
    if (*(int *)(iVar1 + iVar3) != 0) {
      do {
        iVar1 = iVar2;
        iVar2 = *(int *)(iVar1 + 4);
      } while (iVar2 != 0);
      *(unsigned char **)(iVar1 + 4) = param_1;
      goto LAB_97bbc4f8;
    }
  }
  *(unsigned char **)(iVar1 + iVar3) = param_1;
LAB_97bbc4f8:
  *(unsigned char **)(this + 4) = param_1;
  *(int *)(this + 0x14) = *(int *)(this + 0x14) + 1;
  return;
}

/* ParseSymbolTable__InsertSingleSymbol @ 0x97bbc50c (1504 bytes) */
int ParseSymbolTable__InsertSingleSymbol(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
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
  
  p_Var5 = (unsigned char *)GetChunkForSymbol(param_1,*(int *)(this + 0x3c));
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  ((int (*)())ParseSymbolTable__AddSymbol)(this,param_1);
  *(undefined4 *)(param_1 + 0x50) = 1;
  if (*(int *)(param_1 + 0x38) == 0) {
    uVar10 = 0;
    if ((*(int *)(param_1 + 0x58) == 0) && (*(int *)(param_1 + 0x3c) == 0)) {
      piVar7 = (int *)0x0;
      if (*(int **)(param_1 + 0xc) != (int *)0x0) {
        iVar6 = (**(code **)(**(int **)(param_1 + 0xc) + 0x24))();
        if ((((iVar6 != 0) &&
             (iVar6 = (**(code **)(**(int **)(param_1 + 0xc) + 0x24))(), iVar6 != 9)) &&
            (iVar6 = (**(code **)(**(int **)(param_1 + 0xc) + 0x24))(), iVar6 != 10)) &&
           ((iVar6 = (**(code **)(**(int **)(param_1 + 0xc) + 0x24))(), iVar6 != 0xb &&
            (iVar6 = (**(code **)(**(int **)(param_1 + 0xc) + 0x24))(), iVar6 != 0xc)))) {
          uVar10 = 1;
        }
        goto LAB_97bbc61c;
      }
    }
    else {
LAB_97bbc61c:
      piVar7 = *(int **)(param_1 + 0xc);
    }
    *(undefined4 *)(param_1 + 0x38) = uVar10;
  }
  else {
    piVar7 = *(int **)(param_1 + 0xc);
  }
  iVar6 = (**(code **)(*piVar7 + 0x24))();
  *(uint *)(param_1 + 0x60) = (uint)(iVar6 == 4);
  iVar6 = (**(code **)(**(int **)(param_1 + 0xc) + 0x24))(*(int **)(param_1 + 0xc));
  *(uint *)(param_1 + 0x5c) = (uint)(iVar6 == 5);
  *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(this + 0x50);
  uVar8 = GetVec4sForType(*(ushort *)(param_1 + 0x2c));
  ParseSymbol__SetChunk(param_1,p_Var5);
  pbVar12 = *(byte **)param_1;
  *(undefined4 *)(param_1 + 0x44) = 0;
  if (pbVar12 == (byte *)0x0) {
    return param_1;
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
          iVar3 = GetScalerWidthForType(*(ushort *)(param_1 + 0x2c));
          *(int *)(this + 0x20) = *(int *)(this + 0x20) + iVar3;
        }
      }
      else if (bVar2 < 3) {
        if (bVar2 == 0) {
          iVar3 = *(int *)(this + 0x38);
          *(short *)(pbVar12 + 0x12) = (short)iVar3;
          *(int *)(this + 0x38) = iVar3 + 1;
          if (*(int *)(param_1 + 0x60) == 0) {
            if (*(int *)(param_1 + 0x5c) != 0) {
              uVar9 = *(uint *)(this + 0x34);
              *(uint *)(pbVar12 + 0xc) = uVar9 & 0x1f | *(uint *)(pbVar12 + 0xc) & 0xffffffe0;
              *(uint *)(this + 0x34) = uVar9 + 1;
            }
          }
          else {
            uVar9 = *(uint *)(this + 0x1c);
            *(uint *)(pbVar12 + 0xc) = uVar9 & 0x1f | *(uint *)(pbVar12 + 0xc) & 0xffffffe0;
            *(uint *)(this + 0x1c) = uVar9 + 1;
            iVar3 = GetScalerWidthForType(*(ushort *)(param_1 + 0x2c));
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
  return param_1;
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
int ParseSymbolTable__AddTempFromOutput(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
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
  ParseSymbol__ParseSymbol(this_00);
  p_Var3 = (unsigned char *)_PPStreamChunkCreateWithType(0,0);
  ParseSymbol__operator_(this_00,param_1);
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
int ParseSymbolTable__AddFromExternalSymbol(this, param_1, param_2, param_3)
  unsigned char * this;
  unsigned char * param_1;
  int param_2;
  int param_3;
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
  ParseSymbol__ParseSymbol(this_00);
  iVar7 = *(int *)param_1;
  iVar8 = 0;
  p_Var5 = (unsigned char *)_PPStreamChunkCreateFromChunk(iVar7);
  ParseSymbol__operator_(this_00,param_1);
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
        if ((uVar9 == 0) && (CONCAT31(in_register_00000014,param_2) != 0)) {
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
        if ((uVar9 == uVar6 - 1) && (CONCAT31(in_register_00000018,param_3) != 0)) {
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
int ParseSymbolTable__InsertSymbol(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
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
  if (param_1 == (unsigned char *)0x0) {
    return 0;
  }
  if ((*(int *)(this + 0x4c) != 0) || (*(int *)(param_1 + 0x24) == 0)) {
    sVar5 = *(short *)(param_1 + 0x2c);
LAB_97bbd254:
    if (sVar5 == 0x7ffe) {
      iVar3 = *(int *)(*(int *)(param_1 + 0xc) + 8);
      if (iVar3 != 0) {
        uVar11 = 0;
        uVar10 = *(int *)(iVar3 + 8) - *(int *)(iVar3 + 4) >> 3;
        if (uVar10 != 0) {
          do {
            pPVar6 = operator_new(100);
            ParseSymbol__ParseSymbol(pPVar6,param_1);
            ParseSymbol__CatName(pPVar6,".");
            iVar8 = (**(code **)(**(int **)(*(int *)(iVar3 + 4) + uVar11 * 8) + 0x1c))();
            *(undefined1 *)(*(int *)(iVar8 + 4) + *(int *)(*(int *)(iVar8 + 4) + -0xc)) = *puVar2;
            ParseSymbol__CatName(pPVar6,*(char **)(iVar8 + 4));
            ParseSymbol__SetParseTreeType(pPVar6,*(unsigned char **)(*(int *)(iVar3 + 4) + uVar11 * 8));
            *(undefined4 *)(pPVar6 + 0x48) = 0;
            ParseSymbol__ResolveOpenGLType(pPVar6);
            uVar4 = 0;
            if ((*(int *)(param_1 + 0x3c) != 0) || (*(int *)(param_1 + 0x40) != 0)) {
              uVar4 = 1;
            }
            *(undefined4 *)(pPVar6 + 0x40) = uVar4;
            *(undefined4 *)(pPVar6 + 0x3c) = 0;
            uVar11 = uVar11 + 1;
            pPVar7 = operator_new(0x38);
            ParseOperand__ParseOperand(pPVar7);
            *(unsigned char **)pPVar7 = pPVar6;
            ((int (*)())ParseSymbolTable__processOperand)(this,pPVar7);
            ParseOperand___ParseOperand(pPVar7);
            operator_delete(pPVar7);
          } while (uVar11 < uVar10);
        }
      }
    }
    else if (sVar5 == 0x7fff) {
      uVar10 = 0;
      if (0 < *(int *)(*(int *)(param_1 + 0xc) + 4)) {
        do {
          pPVar6 = operator_new(100);
          ParseSymbol__ParseSymbol(pPVar6,param_1);
          ParseSymbol__AddDirectIndex(pPVar6,uVar10);
          _sprintf(acStack_40,"[%d]",uVar10);
          ParseSymbol__CatName(pPVar6,acStack_40);
          *(undefined4 *)(pPVar6 + 0x48) = 1;
          ParseSymbol__ResolveOpenGLType(pPVar6);
          uVar4 = 0;
          if ((*(int *)(param_1 + 0x3c) != 0) || (*(int *)(param_1 + 0x40) != 0)) {
            uVar4 = 1;
          }
          *(undefined4 *)(pPVar6 + 0x40) = uVar4;
          *(undefined4 *)(pPVar6 + 0x3c) = 0;
          pPVar7 = operator_new(0x38);
          ParseOperand__ParseOperand(pPVar7);
          *(unsigned char **)pPVar7 = pPVar6;
          if (uVar10 == 0) {
            *(int *)(this + 0x40) = *(int *)(this + 0x40) + 1;
          }
          ((int (*)())ParseSymbolTable__processOperand)(this,pPVar7);
          if (uVar10 == *(int *)(*(int *)(param_1 + 0xc) + 4) - 1U) {
            *(int *)(this + 0x40) = *(int *)(this + 0x40) + -1;
            ((int (*)())ParseSymbolTable__FinishArrayAddition)(this);
          }
          if (pPVar7 != (unsigned char *)0x0) {
            ParseOperand___ParseOperand(pPVar7);
            operator_delete(pPVar7);
          }
          uVar10 = uVar10 + 1;
        } while ((int)uVar10 < *(int *)(*(int *)(param_1 + 0xc) + 4));
      }
    }
    else {
      uVar9 = ((int (*)())ParseSymbolTable__InsertSingleSymbol)(this,param_1);
    }
    return uVar9;
  }
  sVar5 = *(short *)(param_1 + 0x2c);
  if (((sVar5 != 0x7fff) || (*(int *)(param_1 + 0x3c) != 0)) || (*(int *)(param_1 + 0x40) != 0))
  goto LAB_97bbd254;
  bVar1 = false;
  if (-1 < *(int *)(param_1 + 0x28)) {
    for (iVar3 = *(int *)this; iVar3 != 0; iVar3 = *(int *)(iVar3 + 8)) {
      if (*(int *)(param_1 + 0x28) == *(int *)(iVar3 + 0x28)) {
        bVar1 = true;
        break;
      }
    }
    if (bVar1) goto LAB_97bbd244;
  }
  *(undefined4 *)(this + 0x4c) = 1;
  pPVar6 = operator_new(100);
  ParseSymbol__ParseSymbol(pPVar6,param_1);
  ParseSymbol__TrimNameToBase(pPVar6);
  ParseSymbol__SetParseTreeType(pPVar6,*(unsigned char **)(param_1 + 0x10));
  uVar9 = 0;
  if ((*(int *)(param_1 + 0x3c) != 0) || (*(int *)(param_1 + 0x40) != 0)) {
    uVar9 = 1;
  }
  *(undefined4 *)(pPVar6 + 0x40) = uVar9;
  *(undefined4 *)(pPVar6 + 0x3c) = 0;
  pPVar7 = operator_new(0x38);
  ParseOperand__ParseOperand(pPVar7);
  *(unsigned char **)pPVar7 = pPVar6;
  ((int (*)())ParseSymbolTable__processOperand)(this,pPVar7);
  ParseOperand___ParseOperand(pPVar7);
  operator_delete(pPVar7);
LAB_97bbd244:
  *(undefined4 *)(this + 0x4c) = 0;
  return 0;
}

/* ParseSymbolTable__FindFirstElement @ 0x97bbd4c4 (624 bytes) */
int ParseSymbolTable__FindFirstElement(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
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
  if (param_1 != (unsigned char *)0x0) {
    if (*(short *)(param_1 + 0x2c) == 0x7ffe) {
      iVar10 = *(int *)(*(int *)(param_1 + 0xc) + 8);
      if (iVar10 != 0) {
        pPVar1 = operator_new(100);
        ParseSymbol__ParseSymbol(pPVar1);
        iVar2 = (**(code **)(*(int *)**(undefined4 **)(iVar10 + 4) + 0x1c))();
        *(undefined1 *)(*(int *)(iVar2 + 4) + *(int *)(*(int *)(iVar2 + 4) + -0xc)) = *DAT_a7b7bcfc;
        pcVar12 = *(char **)(iVar2 + 4);
        sVar3 = _strlen(pcVar12);
        sVar3 = sVar3 + 1;
        if (*(char **)(param_1 + 0x14) != (char *)0x0) {
          sVar4 = _strlen(*(char **)(param_1 + 0x14));
          sVar3 = sVar3 + sVar4 + 1;
        }
        pcVar5 = _malloc(sVar3);
        if (*(int *)(param_1 + 0x14) == 0) {
          _strcpy(pcVar5,pcVar12);
        }
        else {
          _sprintf(pcVar5,DAT_a7b7bbf4,*(int *)(param_1 + 0x14),pcVar12);
        }
        ParseSymbol__SetName(pPVar1,pcVar5);
        iVar2 = *(int *)(param_1 + 0x3c);
        *(undefined4 *)(pPVar1 + 0x28) = *(undefined4 *)(param_1 + 0x28);
        uVar11 = 0;
        if ((iVar2 != 0) || (*(int *)(param_1 + 0x40) != 0)) {
          uVar11 = 1;
        }
        *(undefined4 *)(pPVar1 + 0x40) = uVar11;
        ParseSymbol__SetParseTreeType(pPVar1,(unsigned char *)**(undefined4 **)(iVar10 + 4));
        uVar11 = ((int (*)())ParseSymbolTable__FindFirstElement)(this,pPVar1);
        if (pPVar1 != (unsigned char *)0x0) {
          ParseSymbol___ParseSymbol(pPVar1);
          operator_delete(pPVar1);
        }
        _free(pcVar5);
      }
    }
    else if (*(short *)(param_1 + 0x2c) == 0x7fff) {
      uVar13 = 0;
      if (0 < *(int *)(*(int *)(param_1 + 0xc) + 4)) {
        do {
          pPVar1 = operator_new(100);
          ParseSymbol__ParseSymbol(pPVar1);
          ParseSymbol__SetName(pPVar1,*(char **)(param_1 + 0x14));
          ParseSymbol__AddDirectIndex(pPVar1,uVar13);
          _sprintf(acStack_30,DAT_a7b7bbf8,uVar13);
          ParseSymbol__CatName(pPVar1,acStack_30);
          uVar11 = *(undefined4 *)(param_1 + 0x40);
          uVar7 = *(undefined4 *)(param_1 + 0x3c);
          uVar9 = *(undefined4 *)(param_1 + 0x60);
          uVar8 = *(undefined4 *)(param_1 + 0x5c);
          pTVar6 = *(unsigned char **)(param_1 + 0xc);
          *(undefined4 *)(pPVar1 + 0x28) = *(undefined4 *)(param_1 + 0x28);
          *(undefined4 *)(pPVar1 + 0x40) = uVar11;
          *(undefined4 *)(pPVar1 + 0x3c) = uVar7;
          *(undefined4 *)(pPVar1 + 0x60) = uVar9;
          *(undefined4 *)(pPVar1 + 0x5c) = uVar8;
          ParseSymbol__SetParseTreeType(pPVar1,pTVar6);
          *(undefined4 *)(pPVar1 + 0x48) = 1;
          ParseSymbol__ResolveOpenGLType(pPVar1);
          uVar11 = ((int (*)())ParseSymbolTable__FindFirstElement)(this,pPVar1);
          if (pPVar1 != (unsigned char *)0x0) {
            ParseSymbol___ParseSymbol(pPVar1);
            operator_delete(pPVar1);
          }
          uVar13 = uVar13 + 1;
        } while ((int)uVar13 < *(int *)(*(int *)(param_1 + 0xc) + 4));
      }
    }
    else {
      uVar11 = ((int (*)())ParseSymbolTable__FindSymbol)(this,param_1);
    }
  }
  return uVar11;
}

/* ParseSymbolTable__FindSymbol @ 0x97bbd734 (120 bytes) */
int ParseSymbolTable__FindSymbol(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  int iVar1;
  unsigned char * pPVar2;
  
  pPVar2 = *(unsigned char **)
            ((*(uint *)(param_1 + 0x1c) -
             (*(uint *)(param_1 + 0x1c) / *(uint *)(this + 0x10)) * *(uint *)(this + 0x10)) * 4 +
            *(int *)(this + 8));
  while( true ) {
    if (pPVar2 == (unsigned char *)0x0) {
      return (unsigned char *)0x0;
    }
    iVar1 = operator__(pPVar2,param_1);
    if (iVar1 != 0) break;
    pPVar2 = *(unsigned char **)(pPVar2 + 4);
  }
  return pPVar2;
}

/* ParseSymbolTable__NextSymbol @ 0x97bbd7ac (24 bytes) */
int ParseSymbolTable__NextSymbol(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  if (param_1 != (unsigned char *)0x0) {
    return *(undefined4 *)(param_1 + 8);
  }
  return *(undefined4 *)this;
}

/* ParseSymbolTable__NextSymbolInHash @ 0x97bbd7c4 (20 bytes) */
int ParseSymbolTable__NextSymbolInHash(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  if (param_1 == (unsigned char *)0x0) {
    return 0;
  }
  return *(undefined4 *)(param_1 + 4);
}

/* ParseSymbolTable__FirstSymbolInHash @ 0x97bbd7d8 (32 bytes) */
int ParseSymbolTable__FirstSymbolInHash(this, param_1)
  unsigned char * this;
  uint param_1;
{
  return *(undefined4 *)
          ((param_1 - (param_1 / *(uint *)(this + 0x10)) * *(uint *)(this + 0x10)) * 4 +
          *(int *)(this + 8));
}

/* ParseSymbolTable__FindGlobalSymbolByName @ 0x97bbd7f8 (244 bytes) */
int ParseSymbolTable__FindGlobalSymbolByName(this, param_1)
  unsigned char * this;
  char *param_1;
{
  unsigned char * this_00;
  int iVar1;
  unsigned char * pPVar2;
  
  if (param_1 != (char *)0x0) {
    this_00 = operator_new(100);
    ParseSymbol__ParseSymbol(this_00);
    if (this_00 != (unsigned char *)0x0) {
      ParseSymbol__SetName(this_00,param_1);
      for (pPVar2 = *(unsigned char **)
                     ((*(uint *)(this_00 + 0x1c) -
                      (*(uint *)(this_00 + 0x1c) / *(uint *)(this + 0x10)) * *(uint *)(this + 0x10))
                      * 4 + *(int *)(this + 8)); pPVar2 != (unsigned char *)0x0;
          pPVar2 = *(unsigned char **)(pPVar2 + 4)) {
        if ((*(int *)(pPVar2 + 0x38) != 0) && (iVar1 = operator__(pPVar2,this_00), iVar1 != 0)) {
          ParseSymbol___ParseSymbol(this_00);
          operator_delete(this_00);
          return pPVar2;
        }
      }
      ParseSymbol___ParseSymbol(this_00);
      operator_delete(this_00);
    }
  }
  return (unsigned char *)0x0;
}

/* ParseSymbolTable__FindSymbolByName @ 0x97bbd8ec (232 bytes) */
int ParseSymbolTable__FindSymbolByName(this, param_1)
  unsigned char * this;
  char *param_1;
{
  unsigned char * this_00;
  int iVar1;
  unsigned char * pPVar2;
  
  if (param_1 != (char *)0x0) {
    this_00 = operator_new(100);
    ParseSymbol__ParseSymbol(this_00);
    if (this_00 != (unsigned char *)0x0) {
      ParseSymbol__SetName(this_00,param_1);
      for (pPVar2 = *(unsigned char **)
                     ((*(uint *)(this_00 + 0x1c) -
                      (*(uint *)(this_00 + 0x1c) / *(uint *)(this + 0x10)) * *(uint *)(this + 0x10))
                      * 4 + *(int *)(this + 8)); pPVar2 != (unsigned char *)0x0;
          pPVar2 = *(unsigned char **)(pPVar2 + 4)) {
        iVar1 = operator__(pPVar2,this_00);
        if (iVar1 != 0) {
          ParseSymbol___ParseSymbol(this_00);
          operator_delete(this_00);
          return pPVar2;
        }
      }
      ParseSymbol___ParseSymbol(this_00);
      operator_delete(this_00);
    }
  }
  return (unsigned char *)0x0;
}

/* ParseSymbolTable__FindNextParamSymbolByName @ 0x97bbd9d4 (192 bytes) */
int ParseSymbolTable__FindNextParamSymbolByName(this, param_1, param_2)
  unsigned char * this;
  unsigned char * param_1;
  char *param_2;
{
  size_t sVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  
  iVar2 = 0;
  if (param_2 != (char *)0x0) {
    sVar1 = _strlen(param_2);
    if (param_1 == (unsigned char *)0x0) {
      iVar4 = *(int *)this;
    }
    else {
      iVar4 = *(int *)(param_1 + 8);
    }
    while ((iVar2 = 0, iVar4 != 0 &&
           (((pcVar3 = *(char **)(iVar4 + 0x14), pcVar3 == (char *)0x0 ||
             (iVar2 = _strncmp(param_2,pcVar3,sVar1), iVar2 != 0)) ||
            ((iVar2 = iVar4, *(size_t *)(iVar4 + 0x20) != sVar1 &&
             ((pcVar3[sVar1] != '.' && (pcVar3[sVar1] != '['))))))))) {
      iVar4 = *(int *)(iVar4 + 8);
    }
  }
  return iVar2;
}

/* ParseSymbolTable__RemoveSymbol @ 0x97bbda94 (600 bytes) */
int ParseSymbolTable__RemoveSymbol(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
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
  uVar5 = GetVec4sForType(*(ushort *)(param_1 + 0x2c));
  pbVar8 = *(byte **)param_1;
  if (uVar5 != 0) {
    do {
      bVar1 = *pbVar8;
      if (bVar1 == 2) {
LAB_97bbdb58:
        *(int *)(this + 0x18) = *(int *)(this + 0x18) + -1;
        if ((*(uint *)(pbVar8 + 0xc) & 0xf0000) == 0x90000) {
          *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + -1;
          iVar6 = GetScalerWidthForType(*(ushort *)(param_1 + 0x2c));
          *(int *)(this + 0x20) = *(int *)(this + 0x20) - iVar6;
        }
      }
      else if (bVar1 < 3) {
        if (bVar1 == 0) {
          if (*(int *)(param_1 + 0x60) == 0) {
            if (*(int *)(param_1 + 0x5c) != 0) {
              *(int *)(this + 0x34) = *(int *)(this + 0x34) + -1;
            }
          }
          else {
            *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + -1;
            iVar6 = GetScalerWidthForType(*(ushort *)(param_1 + 0x2c));
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
                 ((*(uint *)(param_1 + 0x1c) -
                  (*(uint *)(param_1 + 0x1c) / *(uint *)(this + 0x10)) * *(uint *)(this + 0x10)) * 4
                 + *(int *)(this + 8)); pPVar3 != (unsigned char *)0x0;
      pPVar3 = *(unsigned char **)(pPVar3 + 4)) {
    if (pPVar3 == param_1) {
      if (pPVar2 == (unsigned char *)0x0) {
        *(undefined4 *)
         ((*(uint *)(param_1 + 0x1c) -
          (*(uint *)(param_1 + 0x1c) / *(uint *)(this + 0x10)) * *(uint *)(this + 0x10)) * 4 +
         *(int *)(this + 8)) = *(undefined4 *)(param_1 + 4);
      }
      else {
        *(undefined4 *)(pPVar2 + 4) = *(undefined4 *)(param_1 + 4);
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
      *(undefined4 *)(param_1 + 0x50) = 0;
      return;
    }
    if (pPVar4 == param_1) {
      if (pPVar2 == (unsigned char *)0x0) {
        *(undefined4 *)this = *(undefined4 *)(param_1 + 8);
      }
      else {
        *(undefined4 *)(pPVar2 + 8) = *(undefined4 *)(param_1 + 8);
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
int ParseSymbolTable__RemoveEndSymbol(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
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
  uVar5 = GetVec4sForType(*(ushort *)(param_1 + 0x2c));
  pbVar10 = *(byte **)param_1;
  if (uVar5 != 0) {
    do {
      bVar1 = *pbVar10;
      if (bVar1 == 2) {
        if (*(int *)(this + 0x18) - 1U != (uint)*(ushort *)(pbVar10 + 0x12)) goto LAB_97bbde78;
        *(uint *)(this + 0x18) = *(int *)(this + 0x18) - 1U;
        if ((*(uint *)(pbVar10 + 0xc) & 0xf0000) == 0x90000) {
          *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + -1;
          iVar7 = GetScalerWidthForType(*(ushort *)(param_1 + 0x2c));
          *(int *)(this + 0x20) = *(int *)(this + 0x20) - iVar7;
        }
      }
      else if (bVar1 < 3) {
        if (bVar1 == 0) {
          iVar7 = *(int *)(this + 0x38);
          if (iVar7 - 1U != (uint)*(ushort *)(pbVar10 + 0x12)) goto LAB_97bbde78;
          if (*(int *)(param_1 + 0x60) == 0) {
            if (*(int *)(param_1 + 0x5c) != 0) {
              *(int *)(this + 0x34) = *(int *)(this + 0x34) + -1;
            }
          }
          else {
            *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + -1;
            iVar6 = GetScalerWidthForType(*(ushort *)(param_1 + 0x2c));
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
                 ((*(uint *)(param_1 + 0x1c) -
                  (*(uint *)(param_1 + 0x1c) / *(uint *)(this + 0x10)) * *(uint *)(this + 0x10)) * 4
                 + *(int *)(this + 8)); pPVar3 != (unsigned char *)0x0;
      pPVar3 = *(unsigned char **)(pPVar3 + 4)) {
    iVar7 = operator__(pPVar3,param_1);
    if (iVar7 != 0) {
      if (pPVar2 == (unsigned char *)0x0) {
        *(undefined4 *)
         ((*(uint *)(param_1 + 0x1c) -
          (*(uint *)(param_1 + 0x1c) / *(uint *)(this + 0x10)) * *(uint *)(this + 0x10)) * 4 +
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
      *(undefined4 *)(param_1 + 0x50) = 0;
      return iVar8;
    }
    iVar7 = operator__(pPVar4,param_1);
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
  ParseSymbolTable(this_00,0x80);
  for (pPVar10 = *(unsigned char **)this; pPVar10 != (unsigned char *)0x0;
      pPVar10 = *(unsigned char **)(pPVar10 + 8)) {
    this_01 = operator_new(100);
    ParseSymbol__ParseSymbol(this_01);
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
int ParseSymbolTable__ChangeChunk(this, param_1, param_2, param_3)
  unsigned char * this;
  unsigned char * param_1;
  unsigned char * param_2;
  int param_3;
{
  undefined3 in_register_00000018;
  unsigned char * this_00;
  
  this_00 = *(unsigned char **)this;
  if (this_00 != (unsigned char *)0x0) {
    do {
      if (*(unsigned char **)this_00 == param_1) {
        ParseSymbol__SetChunk(this_00,param_2);
        if (CONCAT31(in_register_00000018,param_3) != 0) {
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
int ParseSymbolTable__GetString(this, param_1)
  unsigned char * this;
  int param_1;
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
    if (param_1 == 1) {
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
    else if (param_1 < 2) {
      if (param_1 == 0) {
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
    else if (param_1 == 2) {
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
int TIntermSymbol__compileNode(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  undefined1 *puVar1;
  int iVar2;
  undefined4 uVar3;
  unsigned char * this_00;
  unsigned char * this_01;
  
  this_01 = (unsigned char *)0x0;
  iVar2 = (**(code **)(*(int *)this + 0x60))();
  puVar1 = DAT_a7b7bd04;
  *(undefined1 *)(*(int *)(iVar2 + 4) + *(int *)(*(int *)(iVar2 + 4) + -0xc)) = *DAT_a7b7bd04;
  if (*(int *)(iVar2 + 4) != 0) {
    uVar3 = (*(code *)**(undefined4 **)this)(this);
    *(undefined4 *)(param_1 + 0x90) = uVar3;
    this_00 = operator_new(100);
    ParseSymbol__ParseSymbol(this_00);
    iVar2 = (**(code **)(*(int *)this + 0x60))(this);
    *(undefined1 *)(*(int *)(iVar2 + 4) + *(int *)(*(int *)(iVar2 + 4) + -0xc)) = *puVar1;
    ParseSymbol__SetName((char *)this_00);
    uVar3 = (**(code **)(*(int *)this + 0x5c))(this);
    *(undefined4 *)(this_00 + 0x28) = uVar3;
    (**(code **)(*(int *)this + 0x3c))(this);
    ParseSymbol__SetParseTreeType((unsigned char *)this_00);
    uVar3 = (**(code **)(*(int *)this + 0x3c))(this);
    *(undefined4 *)(this_00 + 0x10) = uVar3;
    this_01 = operator_new(0x38);
    ParseOperand__ParseOperand(this_01);
    *(unsigned char **)this_01 = this_00;
  }
  return this_01;
}

/* TIntermConstantUnion__compileNode @ 0x97bbe69c (340 bytes) */
int TIntermConstantUnion__compileNode(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  int iVar1;
  uint uVar2;
  undefined2 uVar3;
  unsigned char * this_00;
  undefined4 uVar4;
  undefined **local_50 [9];
  uint local_2c;
  
  this_00 = operator_new(0x38);
  ParseOperand__ParseOperand(this_00);
  uVar4 = (*(code *)**(undefined4 **)this)(this);
  *(undefined4 *)(param_1 + 0x90) = uVar4;
  (**(code **)(*(int *)this + 0x38))(local_50,this);
  if ((local_2c & 0x400) == 0) {
    iVar1 = (int)(local_2c << 0xd | local_2c >> 0x13) >> 0x18;
  }
  else {
    iVar1 = (int)(local_2c << 0xd | local_2c >> 0x13) >> 0x18;
    iVar1 = iVar1 * iVar1;
  }
  *(int *)(this_00 + 0x24) = iVar1;
  local_50[0] = &PTR__TType_a7b7d730;
  *(undefined4 *)(this_00 + 4) = *(undefined4 *)(this + 0x30);
  (**(code **)(*(int *)this + 0x38))(local_50,this);
  local_50[0] = &PTR__TType_a7b7d730;
  uVar2 = local_2c >> 0x13 & 0x3f;
  if (uVar2 == 2) {
    uVar3 = 0x1404;
LAB_97bbe7a0:
    *(undefined2 *)(this_00 + 0x18) = uVar3;
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
                  (SUB41(param_1,0),(char *)0x1,(char *)0x0,
                   "TIntermConstantUnion__compileNode: EbtStruct constant union type, investigate");
      }
    }
    TPPStreamCompiler__error
              (SUB41(param_1,0),(char *)0x1,(char *)0x0,
               "TIntermConstantUnion__compileNode: Unexpected constant union type");
  }
  return this_00;
}

/* TIntermBinary__compileNode @ 0x97bbe7f0 (3444 bytes) */
int TIntermBinary__compileNode(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  int iVar1;
  int *piVar2;
  unsigned char * pPVar3;
  bool bVar10;
  uint uVar4;
  void *pvVar5;
  undefined1 uVar11;
  int iVar6;
  uchar uVar12;
  unsigned char ** ppPVar7;
  unsigned char * pPVar8;
  unsigned char * extraout_r4;
  unsigned char * extraout_r4_00;
  unsigned char * p_Var13;
  undefined4 uVar14;
  unsigned char * pTVar15;
  size_t sVar16;
  undefined4 *puVar17;
  undefined8 uVar18;
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
  int *local_3c;
  unsigned char * local_38;
  unsigned char * local_34;
  unsigned char * local_30 [6];
  ushort uVar9;
  
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
  local_c0 = local_c0 & 0x1fffffff | 0x40000000;
  uVar18 = (*(code *)**(undefined4 **)this)(this);
  pPVar3 = (unsigned char *)uVar18;
  *(int *)(param_1 + 0x90) = (int)((ulonglong)uVar18 >> 0x20);
  piVar2 = *(int **)(this + 0x34);
  if (piVar2 != (int *)0x0) {
    pPVar3 = (unsigned char *)(**(code **)(*piVar2 + 0xc))(piVar2,param_1);
    iVar1 = *(int *)(this + 0x30);
    local_38 = pPVar3;
    if (((iVar1 != 0x2d) && (iVar1 != 0x2e)) && (iVar1 != 0x2f)) {
      ((int (*)())ParseSymbolTable__processOperand)(*(unsigned char **)(param_1 + 0x68));
      pPVar3 = extraout_r4;
    }
  }
  piVar2 = *(int **)(this + 0x38);
  if (piVar2 != (int *)0x0) {
    local_34 = (unsigned char *)(**(code **)(*piVar2 + 0xc))(piVar2,param_1);
    ((int (*)())ParseSymbolTable__processOperand)(*(unsigned char **)(param_1 + 0x68));
    pPVar3 = extraout_r4_00;
  }
  iVar1 = *(int *)(this + 0x30);
  bVar10 = SUB41(param_1,0);
  if (iVar1 == 0x2d) {
    ((int (*)())ParseSymbolTable__processOperand)(*(unsigned char **)(param_1 + 0x68));
    uVar14 = **(undefined4 **)(local_34 + 4);
    piVar2 = (int *)(**(code **)(**(int **)(this + 0x34) + 0x3c))();
    iVar1 = (**(code **)(*piVar2 + 0x38))();
    if (iVar1 == 0) {
      ParseOperand__AddDirectIndex((uint)local_38);
    }
    else {
      ParseSymbol__AddDirectIndex(*(uint *)local_38);
      _sprintf((char *)&local_80,"[%d]",uVar14);
      ParseSymbol__CatName(*(char **)local_38);
      iVar1 = (**(code **)(*(int *)this + 0x54))(this);
      if (iVar1 == 0) {
        uVar14 = 1;
        goto LAB_97bbf03c;
      }
      TPPStreamCompiler__error
                (bVar10,(char *)0x1,(char *)0x0,
                 "TIntermBinary__compileNode: Array index results in another array, this is not handled"
                );
    }
LAB_97bbf04c:
    local_30[0] = local_38;
  }
  else {
    if (iVar1 == 0x2e) {
      if (*(uint *)local_38 == 0) {
        (**(code **)(**(int **)(this + 0x34) + 0x3c))();
        pPVar3 = (unsigned char *)
                 TPPStreamCompiler__newIndirectOperandFromConstant
                           ((unsigned char *)param_1,(unsigned char *)local_38);
        pPVar8 = local_38;
        if (local_38 != (unsigned char *)0x0) {
          ParseOperand___ParseOperand(local_38);
          operator_delete(pPVar8);
        }
      }
      else {
        piVar2 = (int *)(**(code **)(**(int **)(this + 0x34) + 0x3c))();
        iVar1 = (**(code **)(*piVar2 + 0x38))();
        pPVar3 = local_38;
        if (iVar1 != 0) {
          _sprintf((char *)&local_80,"[%d]",0);
          ParseSymbol__CatName(*(char **)local_38);
          iVar1 = (**(code **)(*(int *)this + 0x54))(this);
          if (iVar1 == 0) {
            *(undefined4 *)(*(uint *)local_38 + 0x48) = 1;
            ParseSymbol__ResolveOpenGLType();
            pPVar3 = local_38;
          }
          else {
            TPPStreamCompiler__error
                      (bVar10,(char *)0x1,(char *)0x0,
                       "TIntermBinary__compileNode: Array index results in another array, this is not handled"
                      );
            pPVar3 = local_38;
          }
        }
      }
      local_38 = pPVar3;
      piVar2 = (int *)(**(code **)(**(int **)(this + 0x34) + 0x3c))();
      iVar1 = (**(code **)(*piVar2 + 0x38))();
      if (iVar1 == 0) {
        ParseOperand__AddDirectIndex((uint)local_38);
      }
      else {
        ParseSymbol__AddDirectIndex(*(uint *)local_38);
      }
      ((int (*)())ParseSymbolTable__processOperand)(*(unsigned char **)(param_1 + 0x68));
      piVar2 = (int *)(**(code **)(**(int **)(this + 0x34) + 0x3c))();
      iVar1 = (**(code **)(*piVar2 + 0x38))();
      if (iVar1 == 0) {
        piVar2 = (int *)(**(code **)(**(int **)(this + 0x34) + 0x3c))();
        iVar1 = (**(code **)(*piVar2 + 0x34))();
        if (iVar1 == 0) {
          *(unsigned char **)(local_38 + 0xc) = local_34;
          local_34 = (unsigned char *)0x0;
          goto LAB_97bbf04c;
        }
      }
      piVar2 = (int *)(**(code **)(**(int **)(this + 0x34) + 0x3c))();
      iVar1 = (**(code **)(*piVar2 + 0x38))();
      if (iVar1 == 0) {
        local_40 = 1;
      }
      else {
        local_40 = TPPStreamCompiler__getArrayOffset((unsigned char *)param_1);
      }
      local_30[0] = local_38;
      local_3c = *(int **)(local_38 + 8);
      if (local_3c == (int *)0x0) {
        local_3c = (int *)TPPStreamCompiler__newAddressTemp();
        if (local_40 < 2) {
          local_c0 = local_c0 & 0x3c03ffff | 0x20000000;
          TPPStreamCompiler__getOperandAsDestVar((unsigned char *)&local_80);
          local_b8 = local_80;
          local_b4 = local_7c;
          TPPStreamCompiler__getOperandAsSourceVar((unsigned char *)&local_80);
          local_bc = (local_b8 >> 0xc & 1) << 0x1c | local_bc & 0xefffffff;
          local_b0 = local_80;
          local_ac = local_7c;
        }
        else {
          local_c0 = local_c0 & 0xfc03ffff | 0x880000;
          TPPStreamCompiler__getOperandAsDestVar((unsigned char *)&local_80);
          local_b8 = local_80;
          local_b4 = local_7c;
          TPPStreamCompiler__getOperandAsSourceVar((unsigned char *)&local_80);
          local_b0 = local_80;
          local_ac = local_7c;
          TPPStreamCompiler__getConstantAsSourceVar
                    ((unsigned char *)&local_80,(uint)param_1,(short)&STACKARG(0xffffff00) + 0xc0);
          local_bc = (local_b8 >> 0xc & 1) << 0x1c | local_bc & 0xefffffff;
          local_a8 = local_80;
          local_a4 = local_7c;
        }
        if (*local_3c == 0) {
          uVar9 = *(ushort *)(local_3c + 6);
        }
        else {
          uVar9 = *(ushort *)(*local_3c + 0x2c);
        }
        uVar4 = GetPPStreamTypeForGLType(uVar9);
        local_bc = (uVar4 & 7) << 0x17 | local_bc & 0xfc7fffff;
        iVar1 = ParseOperand__GetLogicalSize();
        local_bc = (iVar1 + -1) * 0x4000000 & 0xc000000U | local_bc & 0xf3ffffff;
        TPPStreamCompiler__AddOperation
                  ((unsigned char **)param_1,(unsigned char *)&local_3c,(char *)&local_c0,0);
        *(int **)(local_30[0] + 8) = local_3c;
        goto LAB_97bbf4fc;
      }
      if (local_40 < 2) {
        local_c0 = local_c0 & 0xfc03ffff | 0x7c0000;
        TPPStreamCompiler__getOperandAsDestVar((unsigned char *)&local_80);
        local_b8 = local_80;
        local_b4 = local_7c;
        TPPStreamCompiler__getOperandAsSourceVar((unsigned char *)&local_80);
        local_b0 = local_80;
        local_ac = local_7c;
        TPPStreamCompiler__getOperandAsSourceVar((unsigned char *)&local_80);
        local_bc = (local_b8 >> 0xc & 1) << 0x1c | local_bc & 0xefffffff;
        local_a8 = local_80;
        local_a4 = local_7c;
      }
      else {
        local_c0 = local_c0 & 0x7c03ffff | 0x60fc0000;
        TPPStreamCompiler__getOperandAsDestVar((unsigned char *)&local_80);
        local_b8 = local_80;
        local_b4 = local_7c;
        TPPStreamCompiler__getOperandAsSourceVar((unsigned char *)&local_80);
        local_b0 = local_80;
        local_ac = local_7c;
        TPPStreamCompiler__getConstantAsSourceVar
                  ((unsigned char *)&local_80,(uint)param_1,(short)&STACKARG(0xffffff00) + 0xc0);
        local_a8 = local_80;
        local_a4 = local_7c;
        TPPStreamCompiler__getOperandAsSourceVar((unsigned char *)&local_80);
        local_bc = (local_b8 >> 0xc & 1) << 0x1c | local_bc & 0xefffffff;
        local_a0 = local_80;
        local_9c = local_7c;
      }
      if (*local_3c == 0) {
        uVar9 = *(ushort *)(local_3c + 6);
      }
      else {
        uVar9 = *(ushort *)(*local_3c + 0x2c);
      }
      uVar4 = GetPPStreamTypeForGLType(uVar9);
      local_bc = (uVar4 & 7) << 0x17 | local_bc & 0xfc7fffff;
      iVar1 = ParseOperand__GetLogicalSize();
      local_bc = (iVar1 + -1) * 0x4000000 & 0xc000000U | local_bc & 0xf3ffffff;
      p_Var13 = (unsigned char *)&local_3c;
    }
    else {
      if (iVar1 == 0x2f) {
        pTVar15 = *(unsigned char **)local_38;
        (**(code **)(**(int **)(this + 0x34) + 0x38))(local_70);
        local_70[0] = &PTR__TType_a7b7d730;
        ((int (*)())ParseSymbolTable__processOperand)(*(unsigned char **)(param_1 + 0x68));
        iVar1 = **(int **)(local_34 + 4);
        ParseSymbol__CatName((char *)pTVar15);
        iVar1 = (**(code **)(**(int **)(*(int *)(local_68 + 4) + iVar1 * 8) + 0x1c))();
        *(undefined1 *)(*(int *)(iVar1 + 4) + *(int *)(*(int *)(iVar1 + 4) + -0xc)) = *DAT_a7b7bd04;
        ParseSymbol__CatName((char *)pTVar15);
        ParseSymbol__SetParseTreeType(pTVar15);
        uVar14 = 0;
LAB_97bbf03c:
        *(undefined4 *)(*(uint *)local_38 + 0x48) = uVar14;
        ParseSymbol__ResolveOpenGLType();
        goto LAB_97bbf04c;
      }
      if (iVar1 == 0x30) {
        local_30[0] = local_38;
        sVar16 = *(size_t *)(local_38 + 0x14);
        if (sVar16 != 0) {
          iVar1 = 0;
          pvVar5 = _malloc(sVar16);
          if (0 < (int)sVar16) {
            do {
              uVar11 = ((int (*)())ParseOperand__GetSwizzle)((uint)local_30[0]);
              *(undefined1 *)((int)pvVar5 + iVar1) = uVar11;
              iVar1 = iVar1 + 1;
            } while (iVar1 < (int)sVar16);
          }
          ((int (*)())ParseOperand__ClearSwizzles)();
        }
        iVar1 = (**(code **)(**(int **)(this + 0x38) + 0x1c))();
        if (iVar1 == 0) {
          TPPStreamCompiler__error
                    (bVar10,(char *)0x1,*(char **)(*(uint *)local_38 + 0x14),
                     "Right hand child of vector swizzle is not an aggregate node.");
        }
        else {
          piVar2 = (int *)(**(code **)(**(int **)(this + 0x38) + 0x1c))();
          iVar1 = (**(code **)(*piVar2 + 100))();
          for (puVar17 = *(undefined4 **)(iVar1 + 4); puVar17 != *(undefined4 **)(iVar1 + 8);
              puVar17 = puVar17 + 1) {
            piVar2 = (int *)(**(code **)(*(int *)*puVar17 + 0x14))();
            iVar6 = (**(code **)(*piVar2 + 0x18))();
            if (iVar6 == 0) {
              TPPStreamCompiler__error
                        (bVar10,(char *)0x1,*(char **)(*(uint *)local_38 + 0x14),
                         "Unexpected non-constant in vector swizzle.");
            }
            else {
              if (sVar16 == 0) {
                piVar2 = (int *)(**(code **)(*(int *)*puVar17 + 0x14))();
                (**(code **)(*piVar2 + 0x18))();
                uVar12 = (uchar)local_30[0];
              }
              else {
                piVar2 = (int *)(**(code **)(*(int *)*puVar17 + 0x14))();
                (**(code **)(*piVar2 + 0x18))();
                uVar12 = (uchar)local_30[0];
              }
              ParseOperand__AddSwizzle(uVar12);
            }
          }
        }
        goto LAB_97bbf4fc;
      }
      if (iVar1 < 0x31) {
        if (iVar1 - 0x1dU < 2) {
          ppPVar7 = (unsigned char **)(**(code **)(*(int *)this + 0x3c))(this);
          local_30[0] = (unsigned char *)
                        TPPStreamCompiler__equalOperands((unsigned char *)param_1,ppPVar7,&local_38,true);
        }
        else {
LAB_97bbf334:
          (**(code **)(*(int *)this + 0x3c))(this,pPVar3);
          local_30[0] = (unsigned char *)TPPStreamCompiler__newTemporary((unsigned char *)param_1);
          TPPStreamCompiler__IndirectAddressHandler((unsigned char **)param_1,local_30,&local_38);
LAB_97bbf370:
          TPPStreamCompiler__getOperandAsSourceVar((unsigned char *)&local_80);
          local_b0 = local_80;
          local_ac = local_7c;
          TPPStreamCompiler__getOperandAsSourceVar((unsigned char *)&local_80);
          local_a8 = local_80;
          local_a4 = local_7c;
          TPPStreamCompiler__getOperandAsDestVar((unsigned char *)&local_80);
          local_b8 = local_80;
          local_b4 = local_7c;
        }
      }
      else {
        if (iVar1 != 0x76) {
          if ((iVar1 < 0x76) || (0x7e < iVar1)) goto LAB_97bbf334;
          if ((*(uint *)(local_38 + 0xc) == 0) && (*(uint *)(local_38 + 8) == 0)) {
            local_30[0] = local_38;
          }
          else {
            pPVar3 = operator_new(0x38);
            ParseOperand__ParseOperand(pPVar3,local_38);
            local_30[0] = pPVar3;
            if (*(uint *)(local_38 + 0xc) != 0) {
              pPVar8 = operator_new(0x38);
              ParseOperand__ParseOperand(pPVar8,*(unsigned char **)(local_38 + 0xc));
              *(unsigned char **)(pPVar3 + 0xc) = pPVar8;
            }
            pPVar3 = local_30;
            if (*(uint *)(local_38 + 8) != 0) {
              pPVar8 = operator_new(0x38);
              ParseOperand__ParseOperand(pPVar8,*(unsigned char **)(local_38 + 8));
              *(unsigned char **)(pPVar3 + 8) = pPVar8;
            }
          }
          TPPStreamCompiler__IndirectAddressHandler((unsigned char **)param_1,local_30,&local_38);
          goto LAB_97bbf370;
        }
        local_30[0] = local_38;
        TPPStreamCompiler__assignOperands((unsigned char **)param_1,&local_38,true);
      }
      iVar1 = *(int *)(this + 0x30);
      local_c0 = (*(uint *)(&_operatorToken + iVar1 * 4) & 0xff) << 0x12 | local_c0 & 0xfc03ffff;
      if (*(int **)(*(uint *)local_30[0] + 0xc) != (int *)0x0) {
        iVar1 = (**(code **)(**(int **)(*(uint *)local_30[0] + 0xc) + 0x24))();
        if (iVar1 == 0xd) {
          *(undefined4 *)(param_1 + 0xa4) = 1;
        }
        iVar1 = *(int *)(this + 0x30);
      }
      if (iVar1 < 0x31) {
        if (0x2c < iVar1) goto LAB_97bbf4fc;
        if (0x16 < iVar1) {
          if (iVar1 < 0x1d) goto LAB_97bbf46c;
          if (iVar1 < 0x1f) goto LAB_97bbf4fc;
        }
      }
      else {
        if (iVar1 == 0x76) goto LAB_97bbf4fc;
        if ((0x75 < iVar1) && (iVar1 - 0x7fU < 6)) {
LAB_97bbf46c:
          TPPStreamCompiler__error
                    (bVar10,(char *)0x1,(char *)0x0,
                     "TIntermBinary__compileNode: Unsupported operation (TOperator: %d)");
          goto LAB_97bbf4fc;
        }
      }
      uVar4 = ParseOperand__IsMatrix();
      local_bc = (uVar4 & 1) << 0x1c | local_bc & 0xefffffff;
      if (*(uint *)local_30[0] == 0) {
        uVar9 = *(ushort *)(local_30[0] + 0x18);
      }
      else {
        uVar9 = *(ushort *)(*(uint *)local_30[0] + 0x2c);
      }
      uVar4 = GetPPStreamTypeForGLType(uVar9);
      local_bc = (uVar4 & 7) << 0x17 | local_bc & 0xfc7fffff;
      iVar1 = ParseOperand__GetLogicalSize();
      local_bc = (iVar1 + -1) * 0x4000000 & 0xc000000U | local_bc & 0xf3ffffff;
      p_Var13 = (unsigned char *)local_30;
    }
    TPPStreamCompiler__AddOperation((unsigned char **)param_1,p_Var13,(char *)&local_c0,0);
  }
LAB_97bbf4fc:
  pPVar3 = local_34;
  if (local_34 != (unsigned char *)0x0) {
    ParseOperand___ParseOperand(local_34);
    operator_delete(pPVar3);
  }
  pPVar3 = local_38;
  if ((local_38 != (unsigned char *)0x0) && (local_30[0] != local_38)) {
    ParseOperand___ParseOperand(local_38);
    operator_delete(pPVar3);
  }
  return local_30[0];
}

/* TIntermUnary__compileNode @ 0x97bbf564 (1824 bytes) */
int TIntermUnary__compileNode(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  bool bVar1;
  unsigned char * pPVar2;
  undefined4 uVar3;
  ushort uVar5;
  uint uVar4;
  int iVar6;
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
  uVar3 = (*(code *)**(undefined4 **)this)(this);
  *(undefined4 *)(param_1 + 0x90) = uVar3;
  local_1c = (unsigned char *)
             (**(code **)(**(int **)(this + 0x34) + 0xc))(*(int **)(this + 0x34),param_1);
  ((int (*)())ParseSymbolTable__processOperand)(*(unsigned char **)(param_1 + 0x68));
  switch(*(undefined4 *)(this + 0x30)) {
  case 5:
  case 8:
    bVar1 = false;
    goto LAB_97bbfa5c;
  default:
    (**(code **)(*(int *)this + 0x3c))(this);
    local_20 = (unsigned char *)TPPStreamCompiler__newTemporary((unsigned char *)param_1);
    break;
  case 9:
  case 10:
    (**(code **)(*(int *)this + 0x3c))(this);
    local_20 = (unsigned char *)TPPStreamCompiler__newTemporary((unsigned char *)param_1);
    TPPStreamCompiler__IndirectAddressHandler((unsigned char **)param_1,&local_20);
    TPPStreamCompiler__getOperandAsSourceVar((unsigned char *)&local_70);
    local_a0 = local_70;
    local_9c = local_6c;
    TPPStreamCompiler__getOperandAsDestVar((unsigned char *)&local_70);
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
    uVar4 = GetPPStreamTypeForGLType(uVar5);
    local_ac = (uVar4 & 7) << 0x17 | local_ac & 0xfc7fffff;
    iVar6 = ParseOperand__GetLogicalSize();
    local_ac = (iVar6 + -1) * 0x4000000 & 0xc000000U | local_ac & 0xf3ffffff;
    TPPStreamCompiler__AddOperation
              ((unsigned char **)param_1,(unsigned char *)&local_20,(char *)&local_b0,0);
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
    uVar4 = GetPPStreamTypeForGLType(uVar5);
    if (uVar4 == 3) {
LAB_97bbf88c:
      uVar5 = (ushort)local_18;
      local_18[0] = 1;
LAB_97bbf894:
      TPPStreamCompiler__getConstantAsSourceVar((unsigned char *)&local_70,(uint)param_1,uVar5);
      local_48 = local_70;
      local_44 = local_6c;
    }
    else if (uVar4 < 4) {
      if (uVar4 == 1) {
        uVar5 = (ushort)local_18;
        local_18[0] = 0x3f800000;
        goto LAB_97bbf894;
      }
    }
    else if (uVar4 == 4) goto LAB_97bbf88c;
    TPPStreamCompiler__IndirectAddressHandler((unsigned char **)param_1,&local_1c);
    TPPStreamCompiler__getOperandAsSourceVar((unsigned char *)&local_70);
    local_50 = local_70;
    local_4c = local_6c;
    TPPStreamCompiler__getOperandAsDestVar((unsigned char *)&local_70);
    local_60 = (*(uint *)(&_operatorToken + *(int *)(this + 0x30) * 4) & 0xff) << 0x12 |
               local_60 & 0xfc03ffff;
    local_5c = (local_a8 >> 0xc & 1) << 0x1c | local_5c & 0xefffffff;
    local_58 = local_70;
    local_54 = local_6c;
    if (*(int *)local_1c == 0) {
      uVar5 = *(ushort *)(local_1c + 0x18);
    }
    else {
      uVar5 = *(ushort *)(*(int *)local_1c + 0x2c);
    }
    uVar4 = GetPPStreamTypeForGLType(uVar5);
    local_5c = (uVar4 & 7) << 0x17 | local_5c & 0xfc7fffff;
    bVar1 = false;
    iVar6 = ParseOperand__GetLogicalSize();
    local_5c = (iVar6 + -1) * 0x4000000 & 0xc000000U | local_5c & 0xf3ffffff;
    TPPStreamCompiler__AddOperation
              ((unsigned char **)param_1,(unsigned char *)&local_1c,(char *)&local_60,0);
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
    uVar4 = GetPPStreamTypeForGLType(uVar5);
    if (uVar4 == 3) {
LAB_97bbfa3c:
      uVar5 = (ushort)local_18;
      local_18[0] = 1;
LAB_97bbfa44:
      TPPStreamCompiler__getConstantAsSourceVar((unsigned char *)&local_70,(uint)param_1,uVar5);
      local_98 = local_70;
      local_94 = local_6c;
    }
    else if (uVar4 < 4) {
      if (uVar4 == 1) {
        uVar5 = (ushort)local_18;
        local_18[0] = 0x3f800000;
        goto LAB_97bbfa44;
      }
    }
    else if (uVar4 == 4) goto LAB_97bbfa3c;
LAB_97bbfa5c:
    local_20 = local_1c;
  }
  if (bVar1) {
    TPPStreamCompiler__IndirectAddressHandler((unsigned char **)param_1,&local_20);
    TPPStreamCompiler__getOperandAsSourceVar((unsigned char *)&local_70);
    local_a0 = local_70;
    local_9c = local_6c;
    TPPStreamCompiler__getOperandAsDestVar((unsigned char *)&local_70);
    iVar6 = *(int *)(this + 0x30);
    local_b0 = (*(uint *)(&_operatorToken + iVar6 * 4) & 0xff) << 0x12 | local_b0 & 0xfc03ffff;
    local_a4 = local_6c;
    local_a8 = local_70;
    if (*(int **)(*(int *)local_20 + 0xc) == (int *)0x0) goto LAB_97bbfb3c;
    iVar6 = (**(code **)(**(int **)(*(int *)local_20 + 0xc) + 0x24))();
    if (iVar6 == 0xd) {
      *(undefined4 *)(param_1 + 0xa4) = 1;
    }
  }
  iVar6 = *(int *)(this + 0x30);
LAB_97bbfb3c:
  if (iVar6 == 5) {
    *(uint *)(local_1c + 0x28) = (uint)(*(int *)(local_1c + 0x28) != 1);
  }
  else if (iVar6 == 8) {
    TPPStreamCompiler__error
              (SUB41(param_1,0),(char *)0x1,(char *)0x0,
               "SecondPassProcessAggregateOp: EOpBitwiseNot not supported");
  }
  if (bVar1) {
    iVar6 = *(int *)(this + 0x30);
    if (((iVar6 == 0x4b) || (iVar6 == 0x57)) || (iVar6 == 0x58)) {
      local_ac = (local_a0 >> 0xe & 1) << 0x1c | local_ac & 0xefffffff;
      if (*(int *)local_1c == 0) {
        uVar5 = *(ushort *)(local_1c + 0x18);
      }
      else {
        uVar5 = *(ushort *)(*(int *)local_1c + 0x2c);
      }
      uVar4 = GetPPStreamTypeForGLType(uVar5);
    }
    else {
      local_ac = (local_a8 >> 0xc & 1) << 0x1c | local_ac & 0xefffffff;
      if (*(int *)local_20 == 0) {
        uVar5 = *(ushort *)(local_20 + 0x18);
      }
      else {
        uVar5 = *(ushort *)(*(int *)local_20 + 0x2c);
      }
      uVar4 = GetPPStreamTypeForGLType(uVar5);
    }
    local_ac = (uVar4 & 7) << 0x17 | local_ac & 0xfc7fffff;
    iVar6 = ParseOperand__GetLogicalSize();
    local_ac = (iVar6 + -1) * 0x4000000 & 0xc000000U | local_ac & 0xf3ffffff;
    TPPStreamCompiler__AddOperation
              ((unsigned char **)param_1,(unsigned char *)&local_20,(char *)&local_b0,0);
  }
  pPVar2 = local_1c;
  if ((local_20 != local_1c) && (local_1c != (unsigned char *)0x0)) {
    ParseOperand___ParseOperand(local_1c);
    operator_delete(pPVar2);
  }
  return local_20;
}

/* TIntermAggregate__compileNode @ 0x97bbfca4 (4308 bytes) */
int TIntermAggregate__compileNode(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  bool bVar1;
  undefined1 *puVar2;
  undefined **ppuVar3;
  int iVar4;
  undefined4 uVar5;
  size_t sVar6;
  uint uVar7;
  char *pcVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  int *piVar12;
  unsigned char * this_00;
  unsigned char ** ppPVar13;
  ushort uVar14;
  int iVar15;
  void *pvVar16;
  int *piVar17;
  int iVar18;
  undefined4 *puVar19;
  unsigned char * pTVar20;
  uint *puVar21;
  unsigned char * pPVar22;
  undefined4 *puVar23;
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
  undefined **local_60;
  unsigned char * local_50;
  unsigned char * local_4c;
  unsigned char * local_48 [3];
  
  piVar17 = (int *)0x0;
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
  iVar18 = *(int *)(param_1 + 0x70);
  iVar15 = *(int *)(this + 0x3c) - *(int *)(this + 0x38) >> 2;
  local_a0 = (*(code *)**(undefined4 **)this)();
  uVar5 = (*(code *)**(undefined4 **)this)(this);
  *(undefined4 *)(param_1 + 0x90) = uVar5;
  iVar4 = *(int *)(this + 0x30);
  if (iVar4 == 3) {
    iVar4 = (**(code **)(*(int *)this + 0x6c))(this);
    puVar2 = DAT_a7b7bd04;
    *(undefined1 *)(*(int *)(iVar4 + 4) + *(int *)(*(int *)(iVar4 + 4) + -0xc)) = *DAT_a7b7bd04;
    sVar6 = _strlen(*(char **)(iVar4 + 4));
    iVar4 = (**(code **)(*(int *)this + 0x6c))(this);
    *(undefined1 *)(*(int *)(iVar4 + 4) + *(int *)(*(int *)(iVar4 + 4) + -0xc)) = *puVar2;
    _PPStreamAddLabel(iVar18,*(undefined4 *)(iVar4 + 4),sVar6);
    iVar4 = (**(code **)(*(int *)this + 0x6c))(this);
    *(undefined1 *)(*(int *)(iVar4 + 4) + *(int *)(*(int *)(iVar4 + 4) + -0xc)) = *puVar2;
    uVar7 = FunctionTable__addFunction(*(char **)(param_1 + 0x6c));
    iVar4 = (**(code **)(*(int *)this + 0x6c))(this);
    *(undefined1 *)(*(int *)(iVar4 + 4) + *(int *)(*(int *)(iVar4 + 4) + -0xc)) = *puVar2;
    ParseFunctionStack__push((char *)(param_1 + 0x58));
    iVar4 = (**(code **)(*(int *)this + 0x6c))(this);
    *(undefined1 *)(*(int *)(iVar4 + 4) + *(int *)(*(int *)(iVar4 + 4) + -0xc)) = *puVar2;
    iVar4 = _memcmp(*(void **)(iVar4 + 4),"main(",5);
    if (iVar4 == 0) {
      FunctionTable__setFirstOp(*(int *)(param_1 + 0x6c),uVar7);
      *(undefined4 *)(param_1 + 0xac) = 1;
      while (iVar4 = ((int (*)())size)((unsigned char *)(param_1 + 0x4c)), iVar4 != 0) {
        piVar9 = (int *)fetch((unsigned char *)(param_1 + 0x4c));
        (**(code **)(*piVar9 + 0xc))(piVar9,param_1);
      }
    }
    else {
      TPPStreamCompiler__LastOperationIndex();
      FunctionTable__setFirstOp(*(int *)(param_1 + 0x6c),uVar7);
    }
    (**(code **)(*(int *)this + 0x38))(&local_90,this);
    bVar1 = (local_6c & 0x1f80000) == 0;
    in_cr0 = bVar1 << 1;
    local_90 = &PTR__TType_a7b7d730;
    if (!bVar1) {
      iVar4 = (**(code **)(*(int *)this + 0x6c))(this);
      *(undefined1 *)(*(int *)(iVar4 + 4) + *(int *)(*(int *)(iVar4 + 4) + -0xc)) = *DAT_a7b7bd04;
      pcVar8 = (char *)(**(code **)(*(int *)this + 0x3c))(this);
      local_48[0] = (unsigned char *)TPPStreamCompiler__newReturnValue((unsigned char *)param_1,pcVar8);
      FunctionTable__setReturnVal(*(int *)(param_1 + 0x6c),SUB41(uVar7,0));
    }
  }
  else if ((iVar4 != 2) && (iVar4 == 1)) {
    iVar4 = *(int *)(param_1 + 0x98);
    if (0 < iVar4) {
      iVar4 = ParseFunctionStack__empty();
      if (iVar4 != 0) {
        ((int (*)())store)((unsigned char *)(param_1 + 0x4c),this);
        return (unsigned char *)0x0;
      }
      iVar4 = *(int *)(param_1 + 0x98);
    }
    *(int *)(param_1 + 0x98) = iVar4 + 1;
  }
  bVar1 = iVar15 != 0;
  if (bVar1) {
    piVar17 = _malloc(iVar15 << 2);
    piVar9 = piVar17;
    for (puVar23 = *(undefined4 **)(this + 0x38); puVar23 != *(undefined4 **)(this + 0x3c);
        puVar23 = puVar23 + 1) {
      iVar4 = (**(code **)(*(int *)*puVar23 + 0xc))((int *)*puVar23,param_1);
      *piVar9 = iVar4;
      piVar9 = piVar9 + 1;
      ((int (*)())ParseSymbolTable__processOperand)(*(unsigned char **)(param_1 + 0x68));
    }
  }
  iVar4 = *(int *)(this + 0x30);
  uVar7 = (*(uint *)(&_operatorToken + iVar4 * 4) & 0xff) << 0x12 |
          iVar15 << 0x1d | local_d0[0] & 0x1c03ffff;
  switch(iVar4) {
  case 0x15:
    uVar7 = iVar15 << 0x1d | local_d0[0] & 0x1c03ffff | 0x8c0000;
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
    local_d0[0] = uVar7;
    (**(code **)(*(int *)this + 0x3c))(this);
    local_48[0] = (unsigned char *)TPPStreamCompiler__newTemporary((unsigned char *)param_1);
    iVar4 = *(int *)(this + 0x30);
    uVar7 = local_d0[0];
    break;
  case 0x25:
    local_48[0] = (unsigned char *)piVar17[iVar15 + -1];
  }
  local_d0[0] = uVar7;
  if ((((local_48[0] != (unsigned char *)0x0) && (iVar4 != 3)) && (*(int *)local_48[0] != 0)) &&
     (piVar9 = *(int **)(*(int *)local_48[0] + 0xc), piVar9 != (int *)0x0)) {
    iVar4 = (**(code **)(*piVar9 + 0x24))();
    if (iVar4 == 0xd) {
      *(undefined4 *)(param_1 + 0xa4) = 1;
    }
    iVar4 = *(int *)(this + 0x30);
  }
  switch(iVar4) {
  default:
    TType__getCompleteString();
    *(undefined1 *)(local_8c + *(int *)(local_8c - 0xc)) = *DAT_a7b7bd04;
    TPPStreamCompiler__error
              (SUB41(param_1,0),(char *)0x1,(char *)0x0,
               "TIntermAggregate__compileNode- unhandle operation %s at %d\n",local_8c,
               *(undefined4 *)(this + 4));
    piVar9 = (int *)(local_8c - 4);
    local_60 = local_90;
    do {
      iVar4 = *piVar9;
      if (in_RESERVE != '\0') {
        iVar18 = storeWordConditionalIndexed(iVar4 + -1,0,piVar9);
        *piVar9 = iVar18;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar4 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_8c - 0xc));
    }
    break;
  case 1:
    *(int *)(param_1 + 0x98) = *(int *)(param_1 + 0x98) + -1;
    break;
  case 2:
    pvVar16 = (void *)0x0;
    piVar9 = (int *)0x0;
    if (bVar1) {
      pvVar16 = _malloc(iVar15 << 2);
      piVar9 = _malloc(iVar15 << 2);
    }
    puVar2 = DAT_a7b7bd04;
    iVar4 = 0;
    puVar23 = *(undefined4 **)(this + 0x38);
    if (0 < iVar15) {
      do {
        iVar18 = iVar4 * 4;
        iVar11 = (**(code **)(*(int *)this + 0x6c))(this);
        *(undefined1 *)(*(int *)(iVar11 + 4) + *(int *)(*(int *)(iVar11 + 4) + -0xc)) = *puVar2;
        iVar11 = *(int *)(iVar11 + 4);
        piVar12 = (int *)(**(code **)(*(int *)*puVar23 + 0x14))();
        pcVar8 = (char *)(**(code **)(*piVar12 + 0x3c))();
        uVar5 = TPPStreamCompiler__newParam((unsigned char *)param_1,pcVar8,iVar11);
        *(undefined4 *)(iVar18 + (int)pvVar16) = uVar5;
        if ((*(int *)(piVar17[iVar4] + 0xc) == 0) && (*(int *)(piVar17[iVar4] + 8) == 0)) {
          piVar9[iVar4] = 0;
        }
        else {
          pPVar22 = operator_new(0x38);
          ParseOperand__ParseOperand(pPVar22,(unsigned char *)piVar17[iVar4]);
          piVar9[iVar4] = (int)pPVar22;
          iVar11 = piVar17[iVar4];
          if (*(int *)(iVar11 + 0xc) != 0) {
            this_00 = operator_new(0x38);
            ParseOperand__ParseOperand(this_00,*(unsigned char **)(piVar17[iVar4] + 0xc));
            *(unsigned char **)(pPVar22 + 0xc) = this_00;
            iVar11 = piVar17[iVar4];
          }
          if (*(int *)(iVar11 + 8) != 0) {
            iVar11 = piVar9[iVar4];
            pPVar22 = operator_new(0x38);
            ParseOperand__ParseOperand(pPVar22,*(unsigned char **)(piVar17[iVar4] + 8));
            *(unsigned char **)(iVar11 + 8) = pPVar22;
          }
        }
        iVar4 = iVar4 + 1;
        TPPStreamCompiler__assignOperands
                  ((unsigned char **)param_1,(unsigned char **)((int)pvVar16 + iVar18),
                   (bool)((char)piVar17 + (char)iVar18));
        puVar23 = puVar23 + 1;
      } while (iVar4 < iVar15);
    }
    local_d0[0] = local_d0[0] & 0x1c03ffff | 0x1300000;
    iVar18 = 0;
    iVar4 = (**(code **)(*(int *)this + 0x6c))(this);
    puVar2 = DAT_a7b7bd04;
    *(undefined1 *)(*(int *)(iVar4 + 4) + *(int *)(*(int *)(iVar4 + 4) + -0xc)) = *DAT_a7b7bd04;
    local_9c = _strlen(*(char **)(iVar4 + 4));
    iVar4 = (**(code **)(*(int *)this + 0x6c))(this);
    *(undefined1 *)(*(int *)(iVar4 + 4) + *(int *)(*(int *)(iVar4 + 4) + -0xc)) = *puVar2;
    TPPStreamCompiler__AddOperation
              ((unsigned char **)param_1,(unsigned char *)0x0,(char *)local_d0,
               *(uint *)(iVar4 + 4));
    if (0 < iVar15) {
      do {
        iVar4 = ParseOperand__isWriteable();
        if (iVar4 != 0) {
          piVar12 = piVar9;
          if (piVar9[iVar18] == 0) {
            piVar12 = piVar17;
          }
          TPPStreamCompiler__assignOperands
                    ((unsigned char **)param_1,(unsigned char **)(piVar12 + iVar18),
                     (bool)((char)pvVar16 + (char)(iVar18 * 4)));
        }
        pPVar22 = *(unsigned char **)(iVar18 * 4 + (int)pvVar16);
        if (pPVar22 != (unsigned char *)0x0) {
          ParseOperand___ParseOperand(pPVar22);
          operator_delete(pPVar22);
        }
        pPVar22 = (unsigned char *)piVar9[iVar18];
        if (pPVar22 != (unsigned char *)0x0) {
          ParseOperand___ParseOperand(pPVar22);
          operator_delete(pPVar22);
        }
        iVar18 = iVar18 + 1;
      } while (iVar18 < iVar15);
    }
    if (pvVar16 != (void *)0x0) {
      _free(pvVar16);
    }
    if (piVar9 != (int *)0x0) {
      _free(piVar9);
    }
    (**(code **)(*(int *)this + 0x38))(&local_90,this);
    local_90 = &PTR__TType_a7b7d730;
    if ((local_6c & 0x1f80000) != 0) {
      iVar4 = (**(code **)(*(int *)this + 0x6c))(this);
      *(undefined1 *)(*(int *)(iVar4 + 4) + *(int *)(*(int *)(iVar4 + 4) + -0xc)) = *DAT_a7b7bd04;
      pcVar8 = (char *)(**(code **)(*(int *)this + 0x3c))(this);
      local_48[0] = (unsigned char *)TPPStreamCompiler__newReturnValue((unsigned char *)param_1,pcVar8);
    }
    break;
  case 3:
    puVar23 = (undefined4 *)ParseFunctionStack__getCurrentParamList();
    iVar4 = ParseFunctionStack__getCurrentNumParams();
    ParseFunctionStack__current();
    uVar7 = FunctionTable__findFunction(*(char **)(param_1 + 0x6c));
    iVar11 = FunctionTable__getFirstOp(*(int *)(param_1 + 0x6c));
    if (iVar11 == 0) {
LAB_97bc06f4:
      iVar11 = *(int *)(param_1 + 0x6c);
    }
    else {
      iVar11 = ParseFunctionStack__getLastParamOpIndex();
      iVar10 = TPPStreamCompiler__LastOperationIndex();
      if (iVar11 != iVar10) goto LAB_97bc06f4;
      iVar11 = *(int *)(param_1 + 0x6c);
    }
    FunctionTable__setEmpty(iVar11,SUB41(uVar7,0));
    FunctionTable__setNumParams(*(int *)(param_1 + 0x6c),uVar7);
    iVar11 = (**(code **)(*(int *)this + 0x6c))(this);
    *(undefined1 *)(*(int *)(iVar11 + 4) + *(int *)(*(int *)(iVar11 + 4) + -0xc)) = *DAT_a7b7bd04;
    iVar11 = *(int *)(iVar11 + 4);
    iVar18 = *(int *)(*(int *)(iVar18 + 0x20) + 4);
    if ((iVar18 == 0) || ((*(uint *)(iVar18 + 0xc) & 0x3fc0000) != 0x1340000)) {
LAB_97bc0788:
      iVar18 = 0;
      if (0 < iVar4) {
        do {
          if (((int *)puVar23[iVar18] != (int *)0x0) &&
             ((iVar10 = (**(code **)(**(int **)(*(int *)puVar23[iVar18] + 0xc) + 0x24))(),
              iVar10 == 10 ||
              (iVar10 = (**(code **)(**(int **)(*(int *)puVar23[iVar18] + 0xc) + 0x24))(),
              iVar10 == 0xb)))) {
            local_50 = (unsigned char *)
                       TPPStreamCompiler__newParam
                                 ((unsigned char *)param_1,*(char **)(*(int *)puVar23[iVar18] + 0xc),iVar11)
            ;
            TPPStreamCompiler__assignOperands
                      ((unsigned char **)param_1,&local_50,
                       (bool)((char)iVar18 * '\x04' + (char)puVar23));
            pPVar22 = local_50;
            if (local_50 != (unsigned char *)0x0) {
              ParseOperand___ParseOperand(local_50);
              operator_delete(pPVar22);
            }
          }
          iVar18 = iVar18 + 1;
        } while (iVar18 < iVar4);
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
                ((unsigned char **)param_1,(unsigned char *)0x0,(char *)local_d0,0);
    }
    else {
      iVar18 = TPPStreamCompiler__LastOperationIndex();
      iVar10 = FunctionTable__getFirstOp(*(int *)(param_1 + 0x6c));
      if (iVar18 < iVar10) goto LAB_97bc0788;
    }
    if (puVar23 != (undefined4 *)0x0) {
      puVar19 = puVar23;
      if (0 < iVar4) {
        do {
          pPVar22 = (unsigned char *)*puVar19;
          if (pPVar22 != (unsigned char *)0x0) {
            ParseOperand___ParseOperand(pPVar22);
            operator_delete(pPVar22);
          }
          iVar4 = iVar4 + -1;
          puVar19 = puVar19 + 1;
        } while (iVar4 != 0);
      }
      _free(puVar23);
    }
    ParseFunctionStack__pop();
    TPPStreamCompiler__LastOperationIndex();
    FunctionTable__setLastOp(*(int *)(param_1 + 0x6c),uVar7);
    break;
  case 4:
    pTVar20 = param_1 + 0x58;
    iVar18 = 0;
    iVar4 = ParseFunctionStack__current();
    if (0 < iVar15) {
      do {
        if (((int *)piVar17[iVar18] != (int *)0x0) &&
           (((iVar11 = (**(code **)(**(int **)(*(int *)piVar17[iVar18] + 0xc) + 0x24))(),
             iVar11 == 9 ||
             (iVar11 = (**(code **)(**(int **)(*(int *)piVar17[iVar18] + 0xc) + 0x24))(),
             iVar11 == 0xb)) ||
            (iVar11 = (**(code **)(**(int **)(*(int *)piVar17[iVar18] + 0xc) + 0x24))(),
            iVar11 == 0xc)))) {
          local_4c = (unsigned char *)
                     TPPStreamCompiler__newParam
                               ((unsigned char *)param_1,*(char **)(*(int *)piVar17[iVar18] + 0xc),iVar4);
          TPPStreamCompiler__assignOperands
                    ((unsigned char **)param_1,(unsigned char **)(piVar17 + iVar18),
                     (bool)((char)&STACKARG(0xfffffef0) + -0x3c));
          pPVar22 = local_4c;
          if (local_4c != (unsigned char *)0x0) {
            ParseOperand___ParseOperand(local_4c);
            operator_delete(pPVar22);
          }
        }
        iVar18 = iVar18 + 1;
      } while (iVar18 < iVar15);
    }
    TPPStreamCompiler__LastOperationIndex();
    ParseFunctionStack__setLastParamOpIndex((int)pTVar20);
    ParseFunctionStack__setCurrentParamList((unsigned char **)pTVar20);
    ParseFunctionStack__setCurrentNumParams((int)pTVar20);
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
    TPPStreamCompiler__IndirectAddressHandler((unsigned char **)param_1,local_48,(int)piVar17);
    if (0 < iVar15) {
      puVar21 = local_d0;
      iVar4 = iVar15;
      do {
        TPPStreamCompiler__getOperandAsSourceVar((unsigned char *)&local_90);
        ppuVar3 = local_90;
        iVar4 = iVar4 + -1;
        puVar21[5] = local_8c;
        puVar21[4] = (uint)ppuVar3;
        puVar21 = puVar21 + 2;
      } while (iVar4 != 0);
    }
    goto LAB_97bc11d8;
  case 0x25:
    break;
  case 0x38:
    TPPStreamCompiler__IndirectAddressHandler((unsigned char **)param_1,local_48,(int)piVar17);
    if (0 < iVar15) {
      puVar21 = local_d0;
      iVar4 = iVar15;
      do {
        TPPStreamCompiler__getOperandAsSourceVar((unsigned char *)&local_90);
        ppuVar3 = local_90;
        iVar4 = iVar4 + -1;
        puVar21[5] = local_8c;
        puVar21[4] = (uint)ppuVar3;
        puVar21 = puVar21 + 2;
      } while (iVar4 != 0);
    }
    goto LAB_97bc11d8;
  case 0x48:
  case 0x49:
    TPPStreamCompiler__IndirectAddressHandler((unsigned char **)param_1,local_48,(int)piVar17);
    if (0 < iVar15) {
      puVar21 = local_d0 + iVar15 * 2;
      iVar4 = iVar15;
      do {
        TPPStreamCompiler__getOperandAsSourceVar((unsigned char *)&local_90);
        ppuVar3 = local_90;
        iVar4 = iVar4 + -1;
        puVar21[3] = local_8c;
        puVar21[2] = (uint)ppuVar3;
        puVar21 = puVar21 + -2;
      } while (iVar4 != 0);
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
    ppPVar13 = (unsigned char **)(**(code **)(*(int *)this + 0x3c))(this);
    local_48[0] = (unsigned char *)
                  TPPStreamCompiler__construct((unsigned char *)param_1,ppPVar13,(int)piVar17);
    break;
  case 0x85:
    iVar15 = 2;
    local_d0[0] = local_d0[0] & 0x1fffffff | 0x40000000;
    piVar17 = _malloc(8);
    iVar4 = TPPStreamCompiler__getVertex();
    piVar17[1] = iVar4;
    iVar4 = TPPStreamCompiler__getMVP();
    *piVar17 = iVar4;
    TPPStreamCompiler__getOperandAsSourceVar((unsigned char *)&local_90);
    local_c0 = local_90;
    local_bc = local_8c;
    TPPStreamCompiler__getOperandAsSourceVar((unsigned char *)&local_90);
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
    if (iVar15 == 3) {
      switch(iVar4) {
      case 0x8a:
      case 0x8e:
      case 0x92:
      case 0x96:
      case 0x98:
      case 0x99:
        iVar18 = 0x44;
        break;
      case 0x8b:
      case 0x8f:
      case 0x93:
      case 0x9a:
      case 0x9b:
        iVar18 = 0x45;
        break;
      default:
        goto switchD_97bc03dc_caseD_8c;
      }
      local_d0[0] = iVar18 << 0x12 | local_d0[0] & 0xfc03ffff;
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
    iVar18 = 4;
    switch(iVar4) {
    case 0x8a:
    case 0x8b:
    case 0x8c:
    case 0x8d:
      iVar18 = 4;
      break;
    case 0x8e:
    case 0x8f:
    case 0x90:
    case 0x91:
      iVar18 = 3;
      break;
    case 0x92:
    case 0x93:
    case 0x94:
    case 0x95:
      iVar18 = 1;
      break;
    case 0x96:
    case 0x97:
      iVar18 = 0;
      break;
    case 0x98:
    case 0x9a:
    case 0x9c:
    case 0x9e:
      iVar18 = 7;
      break;
    case 0x99:
    case 0x9b:
    case 0x9d:
    case 0x9f:
      iVar18 = 6;
      break;
    case 0xa0:
    case 0xa1:
      iVar18 = 2;
      break;
    case 0xa2:
    case 0xa3:
      iVar18 = 5;
    }
    TPPStreamCompiler__IndirectAddressHandler((unsigned char **)param_1,local_48,(int)piVar17);
    if (bVar1) {
      TPPStreamCompiler__getOperandAsSourceVar((unsigned char *)&local_90);
      local_c0 = local_90;
      local_bc = local_8c;
      TPPStreamCompiler__getOperandAsSourceVar((unsigned char *)&local_90);
      local_b0 = iVar18 << 5 | local_b0 & 0xffffff1f;
      local_b8 = local_90;
      local_b4 = local_8c;
      if (iVar15 == 3) {
        TPPStreamCompiler__getOperandAsSourceVar((unsigned char *)&local_90);
        local_a8 = local_90;
        local_a4 = local_8c;
      }
    }
    local_d0[0] = (iVar15 + 1) * 0x20000000 | local_d0[0] & 0x1fffffff;
LAB_97bc11d8:
    TPPStreamCompiler__getOperandAsDestVar((unsigned char *)&local_90);
    local_c8 = local_90;
    local_c4 = local_8c;
    if ((*(int *)(this + 0x30) == 0x4c) || (*(int *)(this + 0x30) == 0x4d)) {
      local_d0[1] = ((uint)local_c0 >> 0xe & 1) << 0x1c | local_d0[1] & 0xefffffff;
      iVar4 = *(int *)*piVar17;
      if (iVar4 == 0) {
        uVar14 = *(ushort *)((int *)*piVar17 + 6);
      }
      else {
        uVar14 = *(ushort *)(iVar4 + 0x2c);
      }
      uVar7 = GetPPStreamTypeForGLType(uVar14);
      local_d0[1] = (uVar7 & 7) << 0x17 | local_d0[1] & 0xfc7fffff;
    }
    else {
      local_d0[1] = ((uint)local_90 >> 0xc & 1) << 0x1c | local_d0[1] & 0xefffffff;
      if (*(int *)local_48[0] == 0) {
        uVar14 = *(ushort *)(local_48[0] + 0x18);
      }
      else {
        uVar14 = *(ushort *)(*(int *)local_48[0] + 0x2c);
      }
      uVar7 = GetPPStreamTypeForGLType(uVar14);
      local_d0[1] = (uVar7 & 7) << 0x17 | local_d0[1] & 0xfc7fffff;
    }
    iVar4 = ParseOperand__GetLogicalSize();
    local_d0[1] = (iVar4 + -1) * 0x4000000 & 0xc000000U | local_d0[1] & 0xf3ffffff;
    TPPStreamCompiler__AddOperation
              ((unsigned char **)param_1,(unsigned char *)local_48,(char *)local_d0,0);
  }
  if (*(int *)(this + 0x30) != 4) {
    piVar9 = piVar17;
    if (0 < iVar15) {
      do {
        pPVar22 = (unsigned char *)*piVar9;
        if ((pPVar22 != (unsigned char *)0x0) && (pPVar22 != local_48[0])) {
          ParseOperand___ParseOperand(pPVar22);
          operator_delete(pPVar22);
        }
        iVar15 = iVar15 + -1;
        piVar9 = piVar9 + 1;
      } while (iVar15 != 0);
    }
    if (piVar17 != (int *)0x0) {
      _free(piVar17);
    }
  }
  return local_48[0];
}

/* TIntermSelection__compileNode @ 0x97bc1348 (2232 bytes) */
int TIntermSelection__compileNode(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  bool bVar1;
  bool bVar2;
  undefined *puVar3;
  undefined *puVar4;
  int *piVar5;
  unsigned char * pPVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  size_t sVar10;
  char *pcVar11;
  int iVar13;
  int iVar14;
  uint uVar15;
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
  unsigned char * local_38;
  ushort uVar12;
  
  puVar4 = PTR_s_gl__IfEnd__a7b7d714;
  puVar3 = PTR_s_gl__IfElse__a7b7d710;
  iVar13 = *(int *)(param_1 + 0x8c);
  *(int *)(param_1 + 0x8c) = iVar13 + 1;
  local_38 = (unsigned char *)0x0;
  local_40 = (unsigned char *)0x0;
  local_3c = (unsigned char *)0x0;
  iVar14 = *(int *)(param_1 + 0x70);
  _sprintf(acStack_f0,"%s%d",puVar3,iVar13);
  _sprintf(acStack_d0,"%s%d",puVar4,iVar13);
  bVar2 = false;
  iVar13 = 1;
  (**(code **)(*(int *)this + 0x38))((unsigned char *)&local_70,this);
  local_70 = &PTR__TType_a7b7d730;
  if ((local_4c & 0x1f80000) != 0) {
    (**(code **)(*(int *)this + 0x3c))(this);
    local_40 = (unsigned char *)TPPStreamCompiler__newTemporary((unsigned char *)param_1);
  }
  pPVar6 = (unsigned char *)
           (**(code **)(**(int **)(this + 0x30) + 0xc))(*(int **)(this + 0x30),param_1);
  ((int (*)())ParseSymbolTable__processOperand)(*(unsigned char **)(param_1 + 0x68));
  piVar5 = *(int **)(pPVar6 + 4);
  if (piVar5 != (int *)0x0) {
    iVar13 = *piVar5;
  }
  uVar15 = (uint)(piVar5 != (int *)0x0);
  bVar1 = uVar15 != 0;
  if (!bVar1) {
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
    local_b0 = 0x21540000;
    local_80 = uVar15;
    local_7c = uVar15;
    local_80 = (*(code *)**(undefined4 **)this)(this);
    TPPStreamCompiler__getOperandAsSourceVar((unsigned char *)&local_70);
    local_ac = ((uint)local_70 >> 0xe & 1) << 0x1c | local_ac & 0xefffffff;
    local_9c = local_6c;
    local_a0 = local_70;
    if (*(int *)pPVar6 == 0) {
      uVar12 = *(ushort *)(pPVar6 + 0x18);
    }
    else {
      uVar12 = *(ushort *)(*(int *)pPVar6 + 0x2c);
    }
    uVar7 = GetPPStreamTypeForGLType(uVar12);
    local_ac = (uVar7 & 7) << 0x17 | local_ac & 0xfc7fffff;
    iVar8 = ParseOperand__GetLogicalSize();
    local_ac = (iVar8 + -1) * 0x4000000 & 0xc000000U | local_ac & 0xf3ffffff;
    local_7c = _strlen(acStack_f0);
    TPPStreamCompiler__AddOperation
              ((unsigned char **)param_1,(unsigned char *)0x0,(char *)&local_b0,(uint)acStack_f0
              );
  }
  if ((*(int *)(this + 0x34) != 0) && ((uVar15 != 1 || (iVar13 != 0)))) {
    iVar8 = TPPStreamCompiler__LastOperationIndex();
    local_3c = (unsigned char *)
               (**(code **)(**(int **)(this + 0x34) + 0xc))(*(int **)(this + 0x34),param_1);
    ((int (*)())ParseSymbolTable__processOperand)(*(unsigned char **)(param_1 + 0x68));
    if ((bVar1) ||
       ((((iVar9 = TPPStreamCompiler__LastOperationIndex(), iVar9 - iVar8 != 1 ||
          (local_40 != (unsigned char *)0x0)) || (*(int *)(this + 0x38) != 0)) ||
        ((*(uint *)(*(int *)(*(int *)(iVar14 + 0x20) + 4) + 0xc) & 0x3fc0000) != 0x13c0000)))) {
      if (pPVar6 != (unsigned char *)0x0) {
        ParseOperand___ParseOperand(pPVar6);
        operator_delete(pPVar6);
      }
      pPVar6 = local_3c;
      if (local_40 != (unsigned char *)0x0) {
        local_ac = 0;
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
        local_80 = (*(code *)**(undefined4 **)this)(this);
        TPPStreamCompiler__IndirectAddressHandler((unsigned char **)param_1,&local_40);
        TPPStreamCompiler__getOperandAsDestVar((unsigned char *)&local_70);
        local_a8 = local_70;
        local_a4 = local_6c;
        TPPStreamCompiler__getOperandAsSourceVar((unsigned char *)&local_70);
        local_ac = ((uint)local_a8 >> 0xc & 1) << 0x1c | local_ac & 0xefffffff;
        local_a0 = local_70;
        local_9c = local_6c;
        if (*(int *)local_40 == 0) {
          uVar12 = *(ushort *)(local_40 + 0x18);
        }
        else {
          uVar12 = *(ushort *)(*(int *)local_40 + 0x2c);
        }
        uVar7 = GetPPStreamTypeForGLType(uVar12);
        local_ac = (uVar7 & 7) << 0x17 | local_ac & 0xfc7fffff;
        iVar8 = ParseOperand__GetLogicalSize();
        local_ac = (iVar8 + -1) * 0x4000000 & 0xc000000U | local_ac & 0xf3ffffff;
        TPPStreamCompiler__AddOperation
                  ((unsigned char **)param_1,(unsigned char *)&local_40,(char *)&local_b0,0);
        pPVar6 = local_3c;
      }
    }
    else {
      _PPStreamChunkListRemoveChunk();
      _PPStreamChunkListRemoveChunk
                (*(int *)(iVar14 + 0x20),*(undefined4 *)(*(int *)(iVar14 + 0x20) + 4));
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
      local_80 = uVar15;
      local_7c = uVar15;
      local_80 = (*(code *)**(undefined4 **)this)(this);
      local_b0 = local_b0 & 0x1fffffff | 0x20000000;
      *(undefined4 *)(pPVar6 + 0x28) = 1;
      TPPStreamCompiler__getOperandAsSourceVar((unsigned char *)&local_70);
      local_ac = ((uint)local_70 >> 0xe & 1) << 0x1c | local_ac & 0xefffffff;
      local_9c = local_6c;
      local_a0 = local_70;
      if (*(int *)pPVar6 == 0) {
        uVar12 = *(ushort *)(pPVar6 + 0x18);
      }
      else {
        uVar12 = *(ushort *)(*(int *)pPVar6 + 0x2c);
      }
      uVar7 = GetPPStreamTypeForGLType(uVar12);
      local_ac = (uVar7 & 7) << 0x17 | local_ac & 0xfc7fffff;
      iVar8 = ParseOperand__GetLogicalSize();
      local_ac = (iVar8 + -1) * 0x4000000 & 0xc000000U | local_ac & 0xf3ffffff;
      TPPStreamCompiler__AddOperation
                ((unsigned char **)param_1,(unsigned char *)0x0,(char *)&local_b0,0);
      bVar2 = true;
      ParseOperand___ParseOperand(pPVar6);
      operator_delete(pPVar6);
      pPVar6 = local_3c;
    }
  }
  if (pPVar6 != (unsigned char *)0x0) {
    ParseOperand___ParseOperand(pPVar6);
    operator_delete(pPVar6);
  }
  piVar5 = *(int **)(this + 0x38);
  if ((piVar5 != (int *)0x0) && ((uVar15 != 1 || (iVar13 != 1)))) {
    if (!bVar1) {
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
      local_80 = uVar15;
      local_7c = uVar15;
      local_80 = (*(code *)**(undefined4 **)this)(this);
      local_7c = _strlen(acStack_d0);
      TPPStreamCompiler__AddOperation
                ((unsigned char **)param_1,(unsigned char *)0x0,(char *)&local_b0,
                 (uint)acStack_d0);
      sVar10 = _strlen(acStack_f0);
      _PPStreamAddLabel(iVar14,acStack_f0,sVar10);
      piVar5 = *(int **)(this + 0x38);
    }
    local_38 = (unsigned char *)(**(code **)(*piVar5 + 0xc))(piVar5,param_1);
    ((int (*)())ParseSymbolTable__processOperand)(*(unsigned char **)(param_1 + 0x68));
    if (local_40 != (unsigned char *)0x0) {
      local_ac = 0;
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
      TPPStreamCompiler__IndirectAddressHandler((unsigned char **)param_1,&local_40);
      TPPStreamCompiler__getOperandAsDestVar((unsigned char *)&local_70);
      local_a8 = local_70;
      local_a4 = local_6c;
      TPPStreamCompiler__getOperandAsSourceVar((unsigned char *)&local_70);
      local_ac = ((uint)local_a8 >> 0xc & 1) << 0x1c | local_ac & 0xefffffff;
      local_a0 = local_70;
      local_9c = local_6c;
      if (*(int *)local_40 == 0) {
        uVar12 = *(ushort *)(local_40 + 0x18);
      }
      else {
        uVar12 = *(ushort *)(*(int *)local_40 + 0x2c);
      }
      uVar7 = GetPPStreamTypeForGLType(uVar12);
      local_ac = (uVar7 & 7) << 0x17 | local_ac & 0xfc7fffff;
      iVar13 = ParseOperand__GetLogicalSize();
      local_ac = (iVar13 + -1) * 0x4000000 & 0xc000000U | local_ac & 0xf3ffffff;
      TPPStreamCompiler__AddOperation
                ((unsigned char **)param_1,(unsigned char *)&local_40,(char *)&local_b0,0);
    }
    pPVar6 = local_38;
    if (local_38 != (unsigned char *)0x0) {
      ParseOperand___ParseOperand(local_38);
      operator_delete(pPVar6);
    }
  }
  if ((!bVar2) && (!bVar1)) {
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
    local_80 = uVar15;
    local_7c = uVar15;
    local_80 = (*(code *)**(undefined4 **)this)(this);
    TPPStreamCompiler__AddOperation
              ((unsigned char **)param_1,(unsigned char *)0x0,(char *)&local_b0,0);
    pcVar11 = acStack_f0;
    if (*(int *)(this + 0x38) != 0) {
      pcVar11 = acStack_d0;
    }
    sVar10 = _strlen(pcVar11);
    pcVar11 = acStack_f0;
    if (*(int *)(this + 0x38) != 0) {
      pcVar11 = acStack_d0;
    }
    _PPStreamAddLabel(iVar14,pcVar11,sVar10);
  }
  return local_40;
}

/* TIntermLoop__compileNode @ 0x97bc1c00 (3000 bytes) */
int TIntermLoop__compileNode(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  int iVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  size_t sVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  unsigned char * pPVar10;
  int *piVar12;
  int iVar13;
  int iVar14;
  char acStack_130 [32];
  char acStack_110 [32];
  char acStack_f0 [32];
  char acStack_d0 [32];
  char local_b0 [4];
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
  unsigned char * local_5c;
  ushort uVar11;
  
  puVar5 = PTR_s_gl__WhileEndIf__a7b7d724;
  puVar4 = PTR_s_gl__WhileStart__a7b7d720;
  puVar3 = PTR_s_gl__WhileEnd__a7b7d71c;
  puVar2 = PTR_s_gl__WhileBody__a7b7d718;
  iVar14 = *(int *)(param_1 + 0x8c);
  iVar13 = *(int *)(param_1 + 0x70);
  *(int *)(param_1 + 0x8c) = iVar14 + 1;
  local_60 = (unsigned char *)0x0;
  local_5c = (unsigned char *)0x0;
  piVar12 = *(int **)(iVar13 + 0x20);
  if ((((*(int *)(param_1 + 0xc4) < 2) || (*(int *)(this + 0xc) != 0)) || (*(int *)(this + 8) != 0))
     || (*(int *)(this + 0x10) != 0)) {
    _sprintf(acStack_130,"%s%d",puVar2,iVar14);
    _sprintf(acStack_110,"%s%d",puVar3,iVar14);
    _sprintf(acStack_f0,"%s%d",puVar4,iVar14);
    _sprintf(acStack_d0,"%s%d",puVar5,iVar14);
    ParseWhileLoopStack__push((char *)(param_1 + 0x5c),acStack_130);
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
    local_b0[0] = '\x01';
    local_b0[1] = -0x58;
    local_b0[2] = '\0';
    local_b0[3] = '\0';
    local_80 = 0;
    local_80 = (*(code *)**(undefined4 **)this)(this);
    local_7c = _strlen(acStack_110);
    TPPStreamCompiler__AddOperation
              ((unsigned char **)param_1,(unsigned char *)0x0,local_b0,(uint)acStack_110);
    iVar14 = 0;
    for (iVar9 = *piVar12; iVar9 != 0; iVar9 = *(int *)(iVar9 + 8)) {
      iVar14 = iVar9;
    }
    sVar6 = _strlen(acStack_f0);
    _PPStreamAddLabel(iVar13,acStack_f0,sVar6);
    if ((*(int *)(this + 0x14) != 0) && (piVar7 = *(int **)(this + 0xc), piVar7 != (int *)0x0)) {
      local_5c = (unsigned char *)(**(code **)(*piVar7 + 0xc))(piVar7,param_1);
      ((int (*)())ParseSymbolTable__processOperand)(*(unsigned char **)(param_1 + 0x68));
      (**(code **)(**(int **)(this + 0xc) + 0x3c))();
      local_60 = (unsigned char *)TPPStreamCompiler__newTemporary((unsigned char *)param_1);
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
      local_b0[0] = ' ';
      local_b0[1] = '(';
      local_b0[2] = '\0';
      local_b0[3] = '\0';
      local_80 = 0;
      local_80 = (*(code *)**(undefined4 **)this)(this);
      TPPStreamCompiler__IndirectAddressHandler((unsigned char **)param_1,&local_60);
      TPPStreamCompiler__getOperandAsDestVar((unsigned char *)&local_70);
      local_a8 = local_70;
      local_a4 = local_6c;
      TPPStreamCompiler__getOperandAsSourceVar((unsigned char *)&local_70);
      local_ac = (local_a8 >> 0xc & 1) << 0x1c | local_ac & 0xefffffff;
      local_a0 = local_70;
      local_9c = local_6c;
      if (*(int *)local_60 == 0) {
        uVar11 = *(ushort *)(local_60 + 0x18);
      }
      else {
        uVar11 = *(ushort *)(*(int *)local_60 + 0x2c);
      }
      uVar8 = GetPPStreamTypeForGLType(uVar11);
      local_ac = (uVar8 & 7) << 0x17 | local_ac & 0xfc7fffff;
      iVar9 = ParseOperand__GetLogicalSize();
      local_ac = (iVar9 + -1) * 0x4000000 & 0xc000000U | local_ac & 0xf3ffffff;
      TPPStreamCompiler__AddOperation
                ((unsigned char **)param_1,(unsigned char *)&local_60,local_b0,0);
      local_ac = 0;
      local_88 = 0;
      local_84 = 0;
      local_7c = 0;
      local_b0[0] = '!';
      local_b0[1] = 'T';
      local_b0[2] = '\0';
      local_b0[3] = '\0';
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
      TPPStreamCompiler__getOperandAsSourceVar((unsigned char *)&local_70);
      local_ac = (local_70 >> 0xe & 1) << 0x1c | local_ac & 0xefffffff;
      local_9c = local_6c;
      local_a0 = local_70;
      if (*(int *)local_60 == 0) {
        uVar11 = *(ushort *)(local_60 + 0x18);
      }
      else {
        uVar11 = *(ushort *)(*(int *)local_60 + 0x2c);
      }
      uVar8 = GetPPStreamTypeForGLType(uVar11);
      local_ac = (uVar8 & 7) << 0x17 | local_ac & 0xfc7fffff;
      iVar9 = ParseOperand__GetLogicalSize();
      local_ac = (iVar9 + -1) * 0x4000000 & 0xc000000U | local_ac & 0xf3ffffff;
      local_7c = _strlen(acStack_d0);
      TPPStreamCompiler__AddOperation
                ((unsigned char **)param_1,(unsigned char *)0x0,local_b0,(uint)acStack_d0);
      pPVar10 = local_60;
      if (local_60 != (unsigned char *)0x0) {
        ParseOperand___ParseOperand(local_60);
        operator_delete(pPVar10);
      }
      local_ac = 0;
      local_b0[0] = '\x01';
      local_b0[1] = 'P';
      local_b0[2] = '\0';
      local_b0[3] = '\0';
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
                ((unsigned char **)param_1,(unsigned char *)0x0,local_b0,(uint)acStack_110);
      local_ac = 0;
      local_b0[0] = '\x01';
      local_b0[1] = 'd';
      local_b0[2] = '\0';
      local_b0[3] = '\0';
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
      TPPStreamCompiler__AddOperation((unsigned char **)param_1,(unsigned char *)0x0,local_b0,0)
      ;
      sVar6 = _strlen(acStack_d0);
      _PPStreamAddLabel(iVar13,acStack_d0,sVar6);
      pPVar10 = local_5c;
      if (local_5c != (unsigned char *)0x0) {
        ParseOperand___ParseOperand(local_5c);
        operator_delete(pPVar10);
      }
    }
    piVar7 = *(int **)(this + 8);
    if ((piVar7 != (int *)0x0) &&
       (pPVar10 = (unsigned char *)(**(code **)(*piVar7 + 0xc))(piVar7,param_1),
       pPVar10 != (unsigned char *)0x0)) {
      ParseOperand___ParseOperand(pPVar10);
      operator_delete(pPVar10);
    }
    sVar6 = _strlen(acStack_130);
    _PPStreamAddLabel(iVar13,acStack_130,sVar6);
    piVar7 = *(int **)(this + 0x10);
    if ((piVar7 != (int *)0x0) &&
       (pPVar10 = (unsigned char *)(**(code **)(*piVar7 + 0xc))(piVar7,param_1),
       pPVar10 != (unsigned char *)0x0)) {
      ParseOperand___ParseOperand(pPVar10);
      operator_delete(pPVar10);
    }
    iVar9 = *(int *)(this + 0x14);
    if ((iVar9 == 0) && (piVar7 = *(int **)(this + 0xc), piVar7 != (int *)0x0)) {
      local_5c = (unsigned char *)(**(code **)(*piVar7 + 0xc))(piVar7,param_1);
      ((int (*)())ParseSymbolTable__processOperand)(*(unsigned char **)(param_1 + 0x68));
      (**(code **)(**(int **)(this + 0xc) + 0x3c))();
      local_60 = (unsigned char *)TPPStreamCompiler__newTemporary((unsigned char *)param_1);
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
      local_b0[0] = ' ';
      local_b0[1] = '(';
      local_b0[2] = '\0';
      local_b0[3] = '\0';
      local_80 = iVar9;
      local_7c = iVar9;
      local_80 = (*(code *)**(undefined4 **)this)(this);
      TPPStreamCompiler__IndirectAddressHandler((unsigned char **)param_1,&local_60);
      TPPStreamCompiler__getOperandAsDestVar((unsigned char *)&local_70);
      local_a8 = local_70;
      local_a4 = local_6c;
      TPPStreamCompiler__getOperandAsSourceVar((unsigned char *)&local_70);
      local_ac = (local_a8 >> 0xc & 1) << 0x1c | local_ac & 0xefffffff;
      local_a0 = local_70;
      local_9c = local_6c;
      if (*(int *)local_60 == 0) {
        uVar11 = *(ushort *)(local_60 + 0x18);
      }
      else {
        uVar11 = *(ushort *)(*(int *)local_60 + 0x2c);
      }
      uVar8 = GetPPStreamTypeForGLType(uVar11);
      local_ac = (uVar8 & 7) << 0x17 | local_ac & 0xfc7fffff;
      iVar9 = ParseOperand__GetLogicalSize();
      local_ac = (iVar9 + -1) * 0x4000000 & 0xc000000U | local_ac & 0xf3ffffff;
      TPPStreamCompiler__AddOperation
                ((unsigned char **)param_1,(unsigned char *)&local_60,local_b0,0);
      local_ac = 0;
      local_88 = 0;
      local_84 = 0;
      local_7c = 0;
      local_b0[0] = '!';
      local_b0[1] = 'T';
      local_b0[2] = '\0';
      local_b0[3] = '\0';
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
      TPPStreamCompiler__getOperandAsSourceVar((unsigned char *)&local_70);
      local_ac = (local_70 >> 0xe & 1) << 0x1c | local_ac & 0xefffffff;
      local_9c = local_6c;
      local_a0 = local_70;
      if (*(int *)local_60 == 0) {
        uVar11 = *(ushort *)(local_60 + 0x18);
      }
      else {
        uVar11 = *(ushort *)(*(int *)local_60 + 0x2c);
      }
      uVar8 = GetPPStreamTypeForGLType(uVar11);
      local_ac = (uVar8 & 7) << 0x17 | local_ac & 0xfc7fffff;
      iVar9 = ParseOperand__GetLogicalSize();
      local_ac = (iVar9 + -1) * 0x4000000 & 0xc000000U | local_ac & 0xf3ffffff;
      local_7c = _strlen(acStack_d0);
      TPPStreamCompiler__AddOperation
                ((unsigned char **)param_1,(unsigned char *)0x0,local_b0,(uint)acStack_d0);
      pPVar10 = local_60;
      if (local_60 != (unsigned char *)0x0) {
        ParseOperand___ParseOperand(local_60);
        operator_delete(pPVar10);
      }
      local_ac = 0;
      local_b0[0] = '\x01';
      local_b0[1] = 'P';
      local_b0[2] = '\0';
      local_b0[3] = '\0';
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
                ((unsigned char **)param_1,(unsigned char *)0x0,local_b0,(uint)acStack_110);
      local_ac = 0;
      local_b0[0] = '\x01';
      local_b0[1] = 'd';
      local_b0[2] = '\0';
      local_b0[3] = '\0';
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
      TPPStreamCompiler__AddOperation((unsigned char **)param_1,(unsigned char *)0x0,local_b0,0)
      ;
      sVar6 = _strlen(acStack_d0);
      _PPStreamAddLabel(iVar13,acStack_d0,sVar6);
      pPVar10 = local_5c;
      if (local_5c != (unsigned char *)0x0) {
        ParseOperand___ParseOperand(local_5c);
        operator_delete(pPVar10);
      }
    }
    ParseWhileLoopStack__pop();
    iVar9 = 0;
    for (iVar1 = iVar14; iVar1 != 0; iVar1 = *(int *)(iVar1 + 8)) {
      iVar9 = iVar1;
    }
    if ((*(int *)(param_1 + 0xc4) < 2) || (iVar9 != iVar14)) {
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
      local_b0[0] = '\x01';
      local_b0[1] = -0x54;
      local_b0[2] = '\0';
      local_b0[3] = '\0';
      local_80 = 0;
      local_80 = (*(code *)**(undefined4 **)this)(this);
      local_7c = _strlen(acStack_f0);
      TPPStreamCompiler__AddOperation
                ((unsigned char **)param_1,(unsigned char *)0x0,local_b0,(uint)acStack_f0);
      sVar6 = _strlen(acStack_110);
      _PPStreamAddLabel(iVar13,acStack_110,sVar6);
    }
    else {
      _PPStreamChunkListRemoveChunk(piVar12,iVar9);
      iVar14 = 0;
      for (iVar9 = **(int **)(iVar13 + 0x24); iVar9 != 0; iVar9 = *(int *)(iVar9 + 8)) {
        iVar14 = iVar9;
      }
      _PPStreamChunkListRemoveChunk(*(int **)(iVar13 + 0x24),iVar14);
    }
  }
  return 0;
}

/* TIntermBranch__compileNode @ 0x97bc27b8 (1420 bytes) */
int TIntermBranch__compileNode(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  ushort uVar1;
  int iVar2;
  unsigned char * pPVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int *piVar10;
  int iVar11;
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
  piVar10 = *(int **)(this + 0xc);
  local_b0 = local_b0 & 0x1fffffff;
  if (piVar10 != (int *)0x0) {
    local_24 = (unsigned char *)(**(code **)(*piVar10 + 0xc))(piVar10,param_1);
    ((int (*)())ParseSymbolTable__processOperand)(*(unsigned char **)(param_1 + 0x68));
  }
  iVar4 = *(int *)(this + 8);
  if (iVar4 == 99) {
    iVar11 = 0;
    iVar4 = ParseFunctionStack__current();
    iVar6 = ParseFunctionStack__getCurrentNumParams();
    iVar7 = ParseFunctionStack__getCurrentParamList();
    local_b0 = local_b0 & 0xfc03ffff;
    if (0 < iVar6) {
      do {
        iVar2 = iVar11 * 4;
        if ((*(int **)(iVar2 + iVar7) != (int *)0x0) &&
           ((iVar8 = (**(code **)(**(int **)(**(int **)(iVar2 + iVar7) + 0xc) + 0x24))(),
            iVar8 == 10 ||
            (iVar8 = (**(code **)(**(int **)(**(int **)(iVar2 + iVar7) + 0xc) + 0x24))(),
            iVar8 == 0xb)))) {
          local_2c = (unsigned char *)
                     TPPStreamCompiler__newParam
                               ((unsigned char *)param_1,*(char **)(**(int **)(iVar2 + iVar7) + 0xc),iVar4);
          TPPStreamCompiler__assignOperands
                    ((unsigned char **)param_1,&local_2c,(bool)((char)iVar2 + (char)iVar7));
          pPVar3 = local_2c;
          if (local_2c != (unsigned char *)0x0) {
            ParseOperand___ParseOperand(local_2c);
            operator_delete(pPVar3);
          }
        }
        iVar11 = iVar11 + 1;
      } while (iVar11 < iVar6);
    }
    if (local_24 != (unsigned char *)0x0) {
      if (*(int *)(local_24 + 4) == 0) {
        local_28 = (unsigned char *)
                   TPPStreamCompiler__newReturnValue
                             ((unsigned char *)param_1,*(char **)(*(int *)local_24 + 0xc));
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
        local_60 = &PTR__TType_a7b7d730;
        local_5c = 0;
        local_58 = 0;
        local_54 = 0;
        local_50 = 0;
        local_4c = 0;
        local_48 = 0;
        local_44 = 0;
        local_40 = 0;
        local_28 = (unsigned char *)
                   TPPStreamCompiler__newReturnValue((unsigned char *)param_1,(char *)&local_60);
        local_60 = &PTR__TType_a7b7d730;
      }
      TPPStreamCompiler__assignOperands
                ((unsigned char **)param_1,&local_28,(bool)((char)&STACKARG(0xffffff10) + -0x34));
      pPVar3 = local_24;
      if (local_24 != (unsigned char *)0x0) {
        ParseOperand___ParseOperand(local_24);
        operator_delete(pPVar3);
      }
      pPVar3 = local_28;
      if (local_28 != (unsigned char *)0x0) {
        ParseOperand___ParseOperand(local_28);
        operator_delete(pPVar3);
      }
    }
    local_ac = 0;
    uVar9 = 0;
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
              ((unsigned char *)&local_70,(uint)param_1,(short)&STACKARG(0xffffff10) + 0xc0);
    local_ac = local_ac & 0xfc7fffff | 0x800000;
    uVar9 = 0;
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
    pcVar5 = (char *)ParseWhileLoopStack__breakLabel();
    local_7c = _strlen(pcVar5);
    uVar9 = ParseWhileLoopStack__breakLabel();
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
    pcVar5 = (char *)ParseWhileLoopStack__continueLabel();
    local_7c = _strlen(pcVar5);
    uVar9 = ParseWhileLoopStack__continueLabel();
  }
  TPPStreamCompiler__AddOperation
            ((unsigned char **)param_1,(unsigned char *)0x0,(char *)&local_b0,uVar9);
  return 0;
}

/* TIntermSymbol__indirectNode @ 0x97bc2d44 (312 bytes) */
int TIntermSymbol__indirectNode(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  undefined1 *puVar1;
  int iVar2;
  undefined4 uVar3;
  unsigned char * this_00;
  unsigned char * this_01;
  
  this_01 = (unsigned char *)0x0;
  iVar2 = (**(code **)(*(int *)this + 0x60))();
  puVar1 = DAT_a7b7bd0c;
  *(undefined1 *)(*(int *)(iVar2 + 4) + *(int *)(*(int *)(iVar2 + 4) + -0xc)) = *DAT_a7b7bd0c;
  if (**(char **)(iVar2 + 4) != '\0') {
    uVar3 = (*(code *)**(undefined4 **)this)(this);
    *(undefined4 *)(param_1 + 0x90) = uVar3;
    this_00 = operator_new(100);
    ParseSymbol__ParseSymbol(this_00);
    iVar2 = (**(code **)(*(int *)this + 0x60))(this);
    *(undefined1 *)(*(int *)(iVar2 + 4) + *(int *)(*(int *)(iVar2 + 4) + -0xc)) = *puVar1;
    ParseSymbol__SetName((char *)this_00);
    uVar3 = (**(code **)(*(int *)this + 0x5c))(this);
    *(undefined4 *)(this_00 + 0x28) = uVar3;
    (**(code **)(*(int *)this + 0x3c))(this);
    ParseSymbol__SetParseTreeType((unsigned char *)this_00);
    uVar3 = (**(code **)(*(int *)this + 0x3c))(this);
    *(undefined4 *)(this_00 + 0x10) = uVar3;
    this_01 = operator_new(0x38);
    ParseOperand__ParseOperand(this_01);
    *(unsigned char **)this_01 = this_00;
  }
  return this_01;
}

/* TIntermConstantUnion__indirectNode @ 0x97bc2e7c (340 bytes) */
int TIntermConstantUnion__indirectNode(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  int iVar1;
  uint uVar2;
  undefined2 uVar3;
  unsigned char * this_00;
  undefined4 uVar4;
  undefined **local_50 [9];
  uint local_2c;
  
  this_00 = operator_new(0x38);
  ParseOperand__ParseOperand(this_00);
  uVar4 = (*(code *)**(undefined4 **)this)(this);
  *(undefined4 *)(param_1 + 0x90) = uVar4;
  (**(code **)(*(int *)this + 0x38))(local_50,this);
  if ((local_2c & 0x400) == 0) {
    iVar1 = (int)(local_2c << 0xd | local_2c >> 0x13) >> 0x18;
  }
  else {
    iVar1 = (int)(local_2c << 0xd | local_2c >> 0x13) >> 0x18;
    iVar1 = iVar1 * iVar1;
  }
  *(int *)(this_00 + 0x24) = iVar1;
  local_50[0] = &PTR__TType_a7b7d778;
  *(undefined4 *)(this_00 + 4) = *(undefined4 *)(this + 0x30);
  (**(code **)(*(int *)this + 0x38))(local_50,this);
  local_50[0] = &PTR__TType_a7b7d778;
  uVar2 = local_2c >> 0x13 & 0x3f;
  if (uVar2 == 2) {
    uVar3 = 0x1404;
LAB_97bc2f80:
    *(undefined2 *)(this_00 + 0x18) = uVar3;
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
                  (SUB41(param_1,0),(char *)0x1,(char *)0x0,
                   "TIntermConstantUnion__indirectNode: EbtStruct constant union type, investigate")
        ;
      }
    }
    TPPStreamCompiler__error
              (SUB41(param_1,0),(char *)0x1,(char *)0x0,
               "TIntermConstantUnion__indirectNode: Unexpected constant union type");
  }
  return this_00;
}

/* TIntermBinary__indirectNode @ 0x97bc2fd0 (1000 bytes) */
int TIntermBinary__indirectNode(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  bool bVar6;
  unsigned char * pPVar5;
  unsigned char * pTVar7;
  unsigned char * this_00;
  unsigned char * this_01;
  uint uVar8;
  undefined **local_60 [2];
  int local_58;
  undefined **local_50 [12];
  
  this_01 = (unsigned char *)0x0;
  this_00 = (unsigned char *)0x0;
  uVar3 = (*(code *)**(undefined4 **)this)();
  *(undefined4 *)(param_1 + 0x90) = uVar3;
  piVar4 = *(int **)(this + 0x34);
  if (piVar4 != (int *)0x0) {
    this_01 = (unsigned char *)(**(code **)(*piVar4 + 0x10))(piVar4,param_1);
  }
  piVar4 = *(int **)(this + 0x38);
  if (piVar4 != (int *)0x0) {
    this_00 = (unsigned char *)(**(code **)(*piVar4 + 0x10))(piVar4,param_1);
  }
  bVar1 = this_01 == (unsigned char *)0x0;
  pPVar5 = (unsigned char *)0x0;
  if (bVar1) goto LAB_97bc3364;
  iVar2 = *(int *)(this + 0x30);
  bVar6 = SUB41(param_1,0);
  if (iVar2 == 0x2d) {
    uVar3 = **(undefined4 **)(this_00 + 4);
    pPVar5 = this_01;
    if (*(int *)(*(uint *)this_01 + 0x4c) == 0) goto LAB_97bc3364;
    ParseSymbol__AddDirectIndex(*(uint *)this_01);
    _sprintf((char *)local_60,"[%d]",uVar3);
    ParseSymbol__CatName(*(char **)this_01);
    iVar2 = (**(code **)(*(int *)this + 0x54))(this);
    if (iVar2 != 0) {
      TPPStreamCompiler__error
                (bVar6,(char *)0x1,(char *)0x0,
                 "TIntermBinary::: Array index results in another array, this is not handled");
      goto LAB_97bc3364;
    }
    *(undefined4 *)(*(int *)this_01 + 0x48) = 1;
  }
  else {
    if (iVar2 == 0x2e) {
      if (*(int *)this_01 == 0) {
        (**(code **)(**(int **)(this + 0x34) + 0x3c))();
        pPVar5 = (unsigned char *)
                 TPPStreamCompiler__newIndirectOperandFromConstant
                           ((unsigned char *)param_1,(unsigned char *)this_01);
        ParseOperand___ParseOperand(this_01);
        operator_delete(this_01);
        bVar1 = pPVar5 == (unsigned char *)0x0;
        this_01 = pPVar5;
      }
      else {
        if (*(int *)(*(int *)this_01 + 0x4c) == 0) {
          piVar4 = (int *)(**(code **)(**(int **)(this + 0x34) + 0x3c))();
          iVar2 = (**(code **)(*piVar4 + 0x34))();
          pPVar5 = this_01;
          if (iVar2 == 0) goto LAB_97bc3364;
          pPVar5 = *(unsigned char **)(param_1 + 0x68);
          *(undefined4 *)(param_1 + 0xa8) = 1;
        }
        else {
          (**(code **)(**(int **)(this + 0x34) + 0x38))(local_50);
          *(undefined4 *)(param_1 + 0xa8) = 1;
          local_50[0] = &PTR__TType_a7b7d778;
          ((int (*)())ParseSymbolTable__processOperand)(*(unsigned char **)(param_1 + 0x68));
          ParseSymbol__AddDirectIndex(*(uint *)this_01);
          _sprintf((char *)local_60,"[%d]",0);
          ParseSymbol__CatName(*(char **)this_01);
          iVar2 = (**(code **)(*(int *)this + 0x54))(this);
          if (iVar2 == 0) {
            *(undefined4 *)(*(int *)this_01 + 0x48) = 1;
            ParseSymbol__ResolveOpenGLType();
          }
          pPVar5 = *(unsigned char **)(param_1 + 0x68);
        }
        ((int (*)())ParseSymbolTable__processOperand)(pPVar5);
        pPVar5 = this_01;
      }
      goto LAB_97bc3364;
    }
    if (iVar2 != 0x2f) goto LAB_97bc3364;
    pTVar7 = *(unsigned char **)this_01;
    (**(code **)(**(int **)(this + 0x34) + 0x38))(local_60);
    local_60[0] = &PTR__TType_a7b7d778;
    uVar8 = **(uint **)(this_00 + 4);
    if (pTVar7 == (unsigned char *)0x0) {
      TPPStreamCompiler__error
                (bVar6,(char *)0x1,(char *)0x0,
                 "TIntermBinary__indirectNode: Structure symbol, parse error.");
    }
    if (local_58 == 0) {
      TPPStreamCompiler__error
                (bVar6,(char *)0x1,(char *)0x0,
                 "TIntermBinary__indirectNode: No structure fields, parse error.");
    }
    if ((uint)(*(int *)(local_58 + 8) - *(int *)(local_58 + 4) >> 3) <= uVar8) {
      TPPStreamCompiler__error
                (bVar6,(char *)0x1,(char *)0x0,
                 "TIntermBinary__indirectNode: Structure index too big for field size, parse error")
      ;
    }
    ParseSymbol__CatName((char *)pTVar7);
    iVar2 = (**(code **)(**(int **)(*(int *)(local_58 + 4) + uVar8 * 8) + 0x1c))();
    *(undefined1 *)(*(int *)(iVar2 + 4) + *(int *)(*(int *)(iVar2 + 4) + -0xc)) = *DAT_a7b7bd0c;
    ParseSymbol__CatName((char *)pTVar7);
    ParseSymbol__SetParseTreeType(pTVar7);
    *(undefined4 *)(*(int *)this_01 + 0x48) = 0;
  }
  ParseSymbol__ResolveOpenGLType();
  pPVar5 = this_01;
LAB_97bc3364:
  if (this_00 != (unsigned char *)0x0) {
    ParseOperand___ParseOperand(this_00);
    operator_delete(this_00);
  }
  if ((!bVar1) && (pPVar5 != this_01)) {
    ParseOperand___ParseOperand(this_01);
    operator_delete(this_01);
  }
  return pPVar5;
}

/* TIntermUnary__indirectNode @ 0x97bc33b8 (112 bytes) */
int TIntermUnary__indirectNode(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  undefined4 uVar1;
  unsigned char * this_00;
  
  uVar1 = (*(code *)**(undefined4 **)this)();
  *(undefined4 *)(param_1 + 0x90) = uVar1;
  this_00 = (unsigned char *)
            (**(code **)(**(int **)(this + 0x34) + 0x10))(*(int **)(this + 0x34),param_1);
  if (this_00 != (unsigned char *)0x0) {
    ParseOperand___ParseOperand(this_00);
    operator_delete(this_00);
  }
  return 0;
}

/* TIntermAggregate__indirectNode @ 0x97bc3428 (232 bytes) */
int TIntermAggregate__indirectNode(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  unsigned char * this_00;
  
  iVar3 = *(int *)(this + 0x3c) - *(int *)(this + 0x38) >> 2;
  uVar1 = (*(code *)**(undefined4 **)this)();
  *(undefined4 *)(param_1 + 0x90) = uVar1;
  puVar2 = _malloc(iVar3 << 2);
  puVar4 = puVar2;
  for (puVar5 = *(undefined4 **)(this + 0x38); puVar5 != *(undefined4 **)(this + 0x3c);
      puVar5 = puVar5 + 1) {
    uVar1 = (**(code **)(*(int *)*puVar5 + 0x10))((int *)*puVar5,param_1);
    *puVar4 = uVar1;
    puVar4 = puVar4 + 1;
  }
  puVar4 = puVar2;
  if (0 < iVar3) {
    do {
      this_00 = (unsigned char *)*puVar4;
      if (this_00 != (unsigned char *)0x0) {
        ParseOperand___ParseOperand(this_00);
        operator_delete(this_00);
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
int TIntermSelection__indirectNode(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  unsigned char * pPVar1;
  int *piVar2;
  
  piVar2 = (int *)0x0;
  if (*(int *)(this + 0x34) != 0) {
    pPVar1 = (unsigned char *)(**(code **)(**(int **)(this + 0x30) + 0x10))();
    if (pPVar1 != (unsigned char *)0x0) {
      ParseOperand___ParseOperand(pPVar1);
      operator_delete(pPVar1);
    }
    piVar2 = *(int **)(this + 0x34);
  }
  if (piVar2 != (int *)0x0) {
    pPVar1 = (unsigned char *)(**(code **)(*piVar2 + 0x10))(piVar2,param_1);
    if (pPVar1 != (unsigned char *)0x0) {
      ParseOperand___ParseOperand(pPVar1);
      operator_delete(pPVar1);
    }
  }
  piVar2 = *(int **)(this + 0x38);
  if ((piVar2 != (int *)0x0) &&
     (pPVar1 = (unsigned char *)(**(code **)(*piVar2 + 0x10))(piVar2,param_1),
     pPVar1 != (unsigned char *)0x0)) {
    ParseOperand___ParseOperand(pPVar1);
    operator_delete(pPVar1);
  }
  return 0;
}

/* TIntermLoop__indirectNode @ 0x97bc35dc (200 bytes) */
int TIntermLoop__indirectNode(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  unsigned char * pPVar1;
  int *piVar2;
  
  if (*(int **)(this + 0xc) != (int *)0x0) {
    pPVar1 = (unsigned char *)(**(code **)(**(int **)(this + 0xc) + 0x10))();
    if (pPVar1 != (unsigned char *)0x0) {
      ParseOperand___ParseOperand(pPVar1);
      operator_delete(pPVar1);
    }
  }
  piVar2 = *(int **)(this + 8);
  if (piVar2 != (int *)0x0) {
    pPVar1 = (unsigned char *)(**(code **)(*piVar2 + 0x10))(piVar2,param_1);
    if (pPVar1 != (unsigned char *)0x0) {
      ParseOperand___ParseOperand(pPVar1);
      operator_delete(pPVar1);
    }
  }
  piVar2 = *(int **)(this + 0x10);
  if ((piVar2 != (int *)0x0) &&
     (pPVar1 = (unsigned char *)(**(code **)(*piVar2 + 0x10))(piVar2,param_1),
     pPVar1 != (unsigned char *)0x0)) {
    ParseOperand___ParseOperand(pPVar1);
    operator_delete(pPVar1);
  }
  return 0;
}

/* TIntermBranch__indirectNode @ 0x97bc36a4 (88 bytes) */
int TIntermBranch__indirectNode(param_1)
  unsigned char * param_1;
{
  unsigned char * this;
  
  if ((*(int **)(param_1 + 0xc) != (int *)0x0) &&
     (this = (unsigned char *)(**(code **)(**(int **)(param_1 + 0xc) + 0x10))(),
     this != (unsigned char *)0x0)) {
    ParseOperand___ParseOperand(this);
    operator_delete(this);
  }
  return 0;
}

/* ConstantAllocationList__ConstantAllocationList @ 0x97bc36fc (4 bytes) */
int ConstantAllocationList__ConstantAllocationList(this)
  unsigned char * this;
{
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)this = 0;
  return;
}

/* ConstantAllocationList__ConstantAllocationList_97bc3700 @ 0x97bc3700 (4 bytes) */
int ConstantAllocationList__ConstantAllocationList_97bc3700(this)
  unsigned char * this;
{
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)this = 0;
  return;
}

/* ConstantAllocationList__ConstantAllocationList_97bc3704 @ 0x97bc3704 (16 bytes) */
int ConstantAllocationList__ConstantAllocationList_97bc3704(this)
  unsigned char * this;
{
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)this = 0;
  return;
}

/* ConstantAllocationList___ConstantAllocationList @ 0x97bc3714 (8 bytes) */
int ConstantAllocationList___ConstantAllocationList(this)
  unsigned char * this;
{
  ~ConstantAllocationList(this);
  return;
}

/* ConstantAllocationList___ConstantAllocationList_97bc371c @ 0x97bc371c (8 bytes) */
int ConstantAllocationList___ConstantAllocationList_97bc371c(this)
  unsigned char * this;
{
  ~ConstantAllocationList(this);
  return;
}

/* ConstantAllocationList___ConstantAllocationList_97bc3724 @ 0x97bc3724 (16 bytes) */
int ConstantAllocationList___ConstantAllocationList_97bc3724(this)
  unsigned char * this;
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
int ConstantAllocationList__addConstant(this, param_1, param_2, param_3)
  unsigned char * this;
  int param_1;
  bool *param_2;
  int param_3;
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
  *(int *)(uVar9 * 0x18 + *(int *)this) = param_1;
  iVar10 = 4;
  *(ushort *)(*(int *)(this + 4) * 0x18 + *(int *)this + 0x14) = param_3;
  do {
    pbVar1 = param_2 + iVar5;
    iVar2 = iVar5 + *(int *)(this + 4) * 0x18 + *(int *)this;
    iVar5 = iVar5 + 4;
    *(undefined4 *)(iVar2 + 4) = *(undefined4 *)pbVar1;
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  *(int *)(this + 4) = *(int *)(this + 4) + 1;
  return;
}

/* ConstantAllocationList__updateConstant @ 0x97bc38b8 (128 bytes) */
int ConstantAllocationList__updateConstant(this, param_1, param_2, param_3)
  unsigned char * this;
  int param_1;
  bool *param_2;
  int param_3;
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
      if (param_1 == iVar2) break;
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar5);
  }
  if (iVar5 <= iVar3) {
    return;
  }
  iVar5 = *(int *)this;
  iVar2 = 0;
  if ((uint)*(ushort *)(iVar3 * 0x18 + iVar5 + 0x14) == CONCAT22(in_register_00000018,param_3)) {
    while( true ) {
      iVar1 = iVar2 * 4;
      iVar2 = iVar2 + 1;
      *(undefined4 *)(iVar1 + iVar3 * 0x18 + iVar5 + 4) = *(undefined4 *)(param_2 + iVar1);
      if (3 < iVar2) break;
      iVar5 = *(int *)this;
    }
    return;
  }
  return;
}

/* ConstantAllocationList__getConstantUsage @ 0x97bc3938 (132 bytes) */
int ConstantAllocationList__getConstantUsage(this, param_1, param_2, param_3)
  unsigned char * this;
  int param_1;
  bool *param_2;
  ushort *param_3;
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
      if (param_1 == iVar1) break;
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar5);
  }
  uVar4 = 0;
  if (iVar2 < iVar5) {
    iVar5 = 0;
    iVar1 = 4;
    *param_3 = *(ushort *)(iVar2 * 0x18 + *(int *)this + 0x14);
    do {
      uVar4 = 1;
      *(undefined4 *)(param_2 + iVar5) = *(undefined4 *)(iVar5 + iVar2 * 0x18 + *(int *)this + 4);
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

