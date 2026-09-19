#include "decls.h"

/* ParseSymbol__AddDirectIndex @ 0x97bbadac (196 bytes) */
int ParseSymbol__AddDirectIndex(this, param_1)
  unsigned char * this;
  uint param_1;
{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  void *pvVar4;
  uint uVar5;
  
  uVar2 = *(uint *)(this + 0x24);
  if ((uVar2 & 3) == 0) {
    pvVar3 = _malloc(uVar2 * 4 + 0x10);
    _memset(pvVar3,0,*(int *)(this + 0x24) * 4 + 0x10);
    uVar2 = *(uint *)(this + 0x24);
    uVar5 = 0;
    if (uVar2 == 0) {
      pvVar4 = *(void **)(this + 0x18);
    }
    else {
      pvVar4 = *(void **)(this + 0x18);
      do {
        iVar1 = uVar5 * 4;
        uVar5 = uVar5 + 1;
        *(undefined4 *)(iVar1 + (int)pvVar3) = *(undefined4 *)(iVar1 + (int)pvVar4);
      } while (uVar5 < uVar2);
    }
    if (pvVar4 != (void *)0x0) {
      _free(pvVar4);
      uVar2 = *(uint *)(this + 0x24);
    }
    *(void **)(this + 0x18) = pvVar3;
  }
  *(uint *)(uVar2 * 4 + *(int *)(this + 0x18)) = param_1;
  *(int *)(this + 0x24) = *(int *)(this + 0x24) + 1;
  return;
}

/* ParseSymbol__PopDirectIndex @ 0x97bbae70 (64 bytes) */
int ParseSymbol__PopDirectIndex(this)
  unsigned char * this;
{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)(this + 0x24);
  uVar2 = 0;
  *(int *)(this + 0x24) = iVar1 + -1;
  if (iVar1 + -1 != 0) {
    do {
      iVar1 = uVar2 * 4;
      uVar2 = uVar2 + 1;
      *(undefined4 *)(iVar1 + *(int *)(this + 0x18)) =
           *(undefined4 *)(iVar1 + *(int *)(this + 0x18) + 4);
    } while (uVar2 < *(uint *)(this + 0x24));
    return;
  }
  return;
}

/* ParseSymbol__RemoveDirectIndex @ 0x97bbaeb0 (16 bytes) */
int ParseSymbol__RemoveDirectIndex(this)
  unsigned char * this;
{
  *(int *)(this + 0x24) = *(int *)(this + 0x24) + -1;
  return;
}

/* ParseSymbol__GetDirectIndex @ 0x97bbaec0 (16 bytes) */
int ParseSymbol__GetDirectIndex(this, param_1)
  unsigned char * this;
  uint param_1;
{
  return *(undefined4 *)(param_1 * 4 + *(int *)(this + 0x18));
}

/* ParseSymbol__GetString @ 0x97bbaed0 (724 bytes) */
int ParseSymbol__GetString(this, param_1)
  unsigned char * this;
  int param_1;
{
  byte bVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined3 in_register_00000010;
  int iVar4;
  byte *pbVar5;
  char *pcVar6;
  uint uVar7;
  
  iVar4 = CONCAT31(in_register_00000010,param_1);
  pcVar6 = (char *)0x0;
  pcVar2 = _malloc(*(int *)(this + 0x20) + 0x200);
  if (pcVar2 == (char *)0x0) {
    return (char *)0x0;
  }
  *pcVar2 = '\0';
  pbVar5 = *(byte **)this;
  if (pbVar5 == (byte *)0x0) {
LAB_97bbb054:
    if (pcVar6 != (char *)0x0) {
      _sprintf(pcVar2,DAT_a7b7bbbc,pcVar2,pcVar6,*(undefined4 *)(this + 0x14),
               *(undefined4 *)(this + 0x28));
      _free(pcVar6);
      goto LAB_97bbb0a4;
    }
  }
  else {
    bVar1 = *pbVar5;
    if (bVar1 == 2) {
      if (iVar4 != 0) {
        _sprintf(pcVar2,_symbolUtilString);
        pbVar5 = *(byte **)this;
      }
      pcVar6 = (char *)PrintAttribute(*(undefined4 *)(pbVar5 + 0xc),*(undefined4 *)(pbVar5 + 0x10));
      goto LAB_97bbb054;
    }
    if (2 < bVar1) {
      if (bVar1 == 3) {
        if (iVar4 != 0) {
          _sprintf(pcVar2,DAT_a7b7bba8);
          pbVar5 = *(byte **)this;
        }
        pcVar6 = (char *)PrintParam(*(undefined4 *)(pbVar5 + 0xc),*(undefined4 *)(pbVar5 + 0x10));
      }
      else {
        if (bVar1 != 4) goto LAB_97bbb038;
        if (iVar4 != 0) {
          _sprintf(pcVar2,DAT_a7b7bbac);
          pbVar5 = *(byte **)this;
        }
        pcVar6 = (char *)PrintOutput(*(undefined4 *)(pbVar5 + 0xc),*(undefined4 *)(pbVar5 + 0x10));
      }
      goto LAB_97bbb054;
    }
    if (bVar1 != 0) {
LAB_97bbb038:
      pcVar6 = _malloc(0x20);
      _strcpy(pcVar6,DAT_a7b7bbb8);
      goto LAB_97bbb054;
    }
    pcVar6 = DAT_a7b7bbb4;
    if (iVar4 != 0) {
      pcVar6 = DAT_a7b7bbb0;
    }
    _sprintf(pcVar2,pcVar6,(uint)*(ushort *)(pbVar5 + 0x12));
  }
  _sprintf(pcVar2,DAT_a7b7bbc0,pcVar2,*(undefined4 *)(this + 0x14),*(undefined4 *)(this + 0x28));
LAB_97bbb0a4:
  uVar3 = GetGLStringForType(*(ushort *)(this + 0x2c));
  _sprintf(pcVar2,DAT_a7b7bbc4,pcVar2,uVar3);
  if (1 < *(short *)(this + 0x2e)) {
    _sprintf(pcVar2,DAT_a7b7bbc8,pcVar2,(int)*(short *)(this + 0x30));
  }
  pcVar6 = _malloc(0x40);
  *pcVar6 = '\0';
  uVar7 = 0;
  if (*(int *)(this + 0x24) != 0) {
    do {
      if (uVar7 == 0) {
        _sprintf(pcVar6,DAT_a7b7bbd0);
      }
      else {
        _sprintf(pcVar6,DAT_a7b7bbcc,pcVar6);
      }
      uVar3 = GetDirectIndex(this,uVar7);
      _sprintf(pcVar6,DAT_a7b7bbd4,pcVar6,uVar3);
      uVar7 = uVar7 + 1;
    } while (uVar7 < *(uint *)(this + 0x24));
  }
  _sprintf(pcVar2,DAT_a7b7bbd8,pcVar2,pcVar6);
  _free(pcVar6);
  return pcVar2;
}

/* ParseOperand__ClearDirectIndex @ 0x97bbb1a4 (68 bytes) */
int ParseOperand__ClearDirectIndex(this)
  unsigned char * this;
{
  if (*(void **)(this + 0x1c) != (void *)0x0) {
    _free(*(void **)(this + 0x1c));
  }
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  return;
}

/* ParseOperand__ParseOperand @ 0x97bbb1e8 (4 bytes) */
int ParseOperand__ParseOperand(this)
  unsigned char * this;
{
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined2 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  return;
}

/* ParseOperand__ParseOperand_97bbb1ec @ 0x97bbb1ec (4 bytes) */
int ParseOperand__ParseOperand_97bbb1ec(this)
  unsigned char * this;
{
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined2 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  return;
}

/* ParseOperand__ParseOperand_97bbb1f0 @ 0x97bbb1f0 (56 bytes) */
int ParseOperand__ParseOperand_97bbb1f0(this)
  unsigned char * this;
{
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined2 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  return;
}

/* ParseOperand__ParseOperand_97bbb228 @ 0x97bbb228 (4 bytes) */
int ParseOperand__ParseOperand_97bbb228(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uchar uVar5;
  undefined4 uVar6;
  uint uVar7;
  
  uVar7 = 0;
  *(undefined4 *)(this + 0x20) = 0;
  iVar2 = *(int *)(param_1 + 0x20);
  uVar1 = *(undefined2 *)(param_1 + 0x18);
  uVar3 = *(undefined4 *)(param_1 + 4);
  uVar6 = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)(this + 4) = uVar3;
  *(undefined2 *)(this + 0x18) = uVar1;
  *(undefined4 *)(this + 0x24) = uVar6;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  if (iVar2 != 0) {
    do {
      uVar4 = GetDirectIndex(param_1,uVar7);
      AddDirectIndex(this,uVar4);
      uVar7 = uVar7 + 1;
    } while (uVar7 < *(uint *)(param_1 + 0x20));
  }
  uVar7 = 0;
  if (*(int *)(param_1 + 0x14) != 0) {
    do {
      uVar5 = ((int (*)())ParseOperand__GetSwizzle)(param_1,uVar7);
      ((int (*)())ParseOperand__AddSwizzle)(this,uVar5);
      uVar7 = uVar7 + 1;
    } while (uVar7 < *(uint *)(param_1 + 0x14));
  }
  uVar3 = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(this + 0x28) = uVar3;
  return;
}

/* ParseOperand__ParseOperand_97bbb22c @ 0x97bbb22c (4 bytes) */
int ParseOperand__ParseOperand_97bbb22c(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  ParseOperand(this,param_1);
  return;
}

/* ParseOperand__ParseOperand_97bbb230 @ 0x97bbb230 (232 bytes) */
int ParseOperand__ParseOperand_97bbb230(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uchar uVar5;
  undefined4 uVar6;
  uint uVar7;
  
  uVar7 = 0;
  *(undefined4 *)(this + 0x20) = 0;
  iVar2 = *(int *)(param_1 + 0x20);
  uVar1 = *(undefined2 *)(param_1 + 0x18);
  uVar3 = *(undefined4 *)(param_1 + 4);
  uVar6 = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)(this + 4) = uVar3;
  *(undefined2 *)(this + 0x18) = uVar1;
  *(undefined4 *)(this + 0x24) = uVar6;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  if (iVar2 != 0) {
    do {
      uVar4 = GetDirectIndex(param_1,uVar7);
      AddDirectIndex(this,uVar4);
      uVar7 = uVar7 + 1;
    } while (uVar7 < *(uint *)(param_1 + 0x20));
  }
  uVar7 = 0;
  if (*(int *)(param_1 + 0x14) != 0) {
    do {
      uVar5 = ((int (*)())ParseOperand__GetSwizzle)(param_1,uVar7);
      ((int (*)())ParseOperand__AddSwizzle)(this,uVar5);
      uVar7 = uVar7 + 1;
    } while (uVar7 < *(uint *)(param_1 + 0x14));
  }
  uVar3 = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(this + 0x28) = uVar3;
  return;
}

/* ParseOperand___ParseOperand @ 0x97bbb318 (8 bytes) */
int ParseOperand___ParseOperand(this)
  unsigned char * this;
{
  ~ParseOperand(this);
  return;
}

/* ParseOperand___ParseOperand_97bbb320 @ 0x97bbb320 (8 bytes) */
int ParseOperand___ParseOperand_97bbb320(this)
  unsigned char * this;
{
  ~ParseOperand(this);
  return;
}

/* ParseOperand___ParseOperand_97bbb328 @ 0x97bbb328 (232 bytes) */
int ParseOperand___ParseOperand_97bbb328(this)
  unsigned char * this;
{
  unsigned char * this_00;
  
  this_00 = *(unsigned char **)this;
  if (this_00 == (unsigned char *)0x0) goto LAB_97bbb3cc;
  if ((*(int *)(this_00 + 0x3c) == 0) || (temporaryAllocator == (unsigned char *)0x0)) {
    if ((*(int *)(this_00 + 0x58) != 0) && (addressTempAllocator != (unsigned char *)0x0)) {
      AddressTempAllocator__releaseTemporary(addressTempAllocator,*(uint *)(this_00 + 0x28));
      goto LAB_97bbb3a4;
    }
  }
  else {
    TemporaryAllocator__releaseTemporary
              (temporaryAllocator,*(ushort *)(this_00 + 0x2c),*(uint *)(this_00 + 0x28));
LAB_97bbb3a4:
    this_00 = *(unsigned char **)this;
  }
  if ((*(int *)(this_00 + 0x50) == 0) && (this_00 != (unsigned char *)0x0)) {
    ParseSymbol___ParseSymbol(this_00);
    operator_delete(this_00);
  }
LAB_97bbb3cc:
  if (*(void **)(this + 0x1c) != (void *)0x0) {
    _free(*(void **)(this + 0x1c));
  }
  if (*(void **)(this + 0x10) != (void *)0x0) {
    _free(*(void **)(this + 0x10));
    return;
  }
  return;
}

/* ParseOperand__operator_ @ 0x97bbb410 (220 bytes) */
int ParseOperand__operator_(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  undefined2 uVar1;
  undefined4 uVar2;
  uint uVar3;
  uchar uVar4;
  undefined4 uVar5;
  uint uVar6;
  
  if (this != param_1) {
    uVar2 = *(undefined4 *)(param_1 + 4);
    uVar1 = *(undefined2 *)(param_1 + 0x18);
    uVar5 = *(undefined4 *)(param_1 + 0x24);
    *(undefined4 *)this = *(undefined4 *)param_1;
    *(undefined4 *)(this + 4) = uVar2;
    *(undefined2 *)(this + 0x18) = uVar1;
    *(undefined4 *)(this + 0x24) = uVar5;
    ClearDirectIndex(this);
    uVar6 = 0;
    if (*(int *)(param_1 + 0x20) != 0) {
      do {
        uVar3 = GetDirectIndex(param_1,uVar6);
        AddDirectIndex(this,uVar3);
        uVar6 = uVar6 + 1;
      } while (uVar6 < *(uint *)(param_1 + 0x20));
    }
    uVar6 = 0;
    if (*(int *)(param_1 + 0x14) != 0) {
      do {
        uVar4 = ((int (*)())ParseOperand__GetSwizzle)(param_1,uVar6);
        ((int (*)())ParseOperand__AddSwizzle)(this,uVar4);
        uVar6 = uVar6 + 1;
      } while (uVar6 < *(uint *)(param_1 + 0x14));
    }
    uVar2 = *(undefined4 *)(param_1 + 0x28);
    *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
    *(undefined4 *)(this + 0x28) = uVar2;
  }
  return this;
}

/* operator___97bbb4ec @ 0x97bbb4ec (328 bytes) */
int operator___97bbb4ec(param_1, param_2)
  unsigned char * param_1;
  unsigned char * param_2;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if ((*(int *)param_1 == *(int *)param_2) && (*(int *)(param_1 + 4) == *(int *)(param_2 + 4))) {
    iVar1 = ((int (*)())ParseOperand__GetBaseSize)(param_1);
    iVar2 = ((int (*)())ParseOperand__GetBaseSize)(param_2);
    if (iVar1 == iVar2) {
      iVar1 = ((int (*)())ParseOperand__IsMatrix)(param_1);
      iVar2 = ((int (*)())ParseOperand__IsMatrix)(param_2);
      if ((((iVar1 == iVar2) && (*(int *)(param_1 + 0x28) == *(int *)(param_2 + 0x28))) &&
          (*(int *)(param_1 + 0x2c) == *(int *)(param_2 + 0x2c))) &&
         (*(int *)(param_1 + 0x20) == *(int *)(param_2 + 0x20))) {
        uVar3 = 0;
        if (*(int *)(param_1 + 0x20) != 0) {
          do {
            iVar1 = ((int (*)())ParseOperand__GetDirectIndex)(param_1,uVar3);
            iVar2 = ((int (*)())ParseOperand__GetDirectIndex)(param_2,uVar3);
            if (iVar1 != iVar2) {
              return 0;
            }
            uVar3 = 0;
            if (*(int *)(param_2 + 0x14) != 0) {
              do {
                iVar1 = ((int (*)())ParseOperand__GetSwizzle)(param_1,uVar3);
                iVar2 = ((int (*)())ParseOperand__GetSwizzle)(param_2,uVar3);
                if (iVar1 != iVar2) {
                  return 0;
                }
                uVar3 = uVar3 + 1;
              } while (uVar3 < *(uint *)(param_2 + 0x14));
            }
            uVar3 = uVar3 + 1;
          } while (uVar3 < *(uint *)(param_2 + 0x20));
        }
        return 1;
      }
    }
  }
  return 0;
}

/* ParseOperand__Clear @ 0x97bbb634 (88 bytes) */
int ParseOperand__Clear(this)
  unsigned char * this;
{
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined2 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  ClearDirectIndex(this);
  ((int (*)())ParseOperand__ClearSwizzles)(this);
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  return;
}

/* ParseOperand__AddDirectIndex @ 0x97bbb68c (196 bytes) */
int ParseOperand__AddDirectIndex(this, param_1)
  unsigned char * this;
  uint param_1;
{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  void *pvVar4;
  uint uVar5;
  
  uVar2 = *(uint *)(this + 0x20);
  if ((uVar2 & 3) == 0) {
    pvVar3 = _malloc(uVar2 * 4 + 0x10);
    _memset(pvVar3,0,*(int *)(this + 0x20) * 4 + 0x10);
    uVar2 = *(uint *)(this + 0x20);
    uVar5 = 0;
    if (uVar2 == 0) {
      pvVar4 = *(void **)(this + 0x1c);
    }
    else {
      pvVar4 = *(void **)(this + 0x1c);
      do {
        iVar1 = uVar5 * 4;
        uVar5 = uVar5 + 1;
        *(undefined4 *)(iVar1 + (int)pvVar3) = *(undefined4 *)(iVar1 + (int)pvVar4);
      } while (uVar5 < uVar2);
    }
    if (pvVar4 != (void *)0x0) {
      _free(pvVar4);
      uVar2 = *(uint *)(this + 0x20);
    }
    *(void **)(this + 0x1c) = pvVar3;
  }
  *(uint *)(uVar2 * 4 + *(int *)(this + 0x1c)) = param_1;
  *(int *)(this + 0x20) = *(int *)(this + 0x20) + 1;
  return;
}

/* ParseOperand__PopDirectIndex @ 0x97bbb750 (64 bytes) */
int ParseOperand__PopDirectIndex(this)
  unsigned char * this;
{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)(this + 0x20);
  uVar2 = 0;
  *(int *)(this + 0x20) = iVar1 + -1;
  if (iVar1 + -1 != 0) {
    do {
      iVar1 = uVar2 * 4;
      uVar2 = uVar2 + 1;
      *(undefined4 *)(iVar1 + *(int *)(this + 0x1c)) =
           *(undefined4 *)(iVar1 + *(int *)(this + 0x1c) + 4);
    } while (uVar2 < *(uint *)(this + 0x20));
    return;
  }
  return;
}

/* ParseOperand__RemoveDirectIndex @ 0x97bbb790 (16 bytes) */
int ParseOperand__RemoveDirectIndex(this)
  unsigned char * this;
{
  *(int *)(this + 0x20) = *(int *)(this + 0x20) + -1;
  return;
}

/* ParseOperand__GetDirectIndex @ 0x97bbb7a0 (16 bytes) */
int ParseOperand__GetDirectIndex(this, param_1)
  unsigned char * this;
  uint param_1;
{
  return *(undefined4 *)(param_1 * 4 + *(int *)(this + 0x1c));
}

/* ParseOperand__GetAsDestVar @ 0x97bbb7b0 (716 bytes) */
int ParseOperand__GetAsDestVar(param_1)
  int param_1;
{
  undefined3 in_register_0000000c;
  uint *puVar1;
  short sVar4;
  uint uVar2;
  int iVar3;
  unsigned char * in_r4;
  int in_r5;
  short sVar5;
  uint uVar6;
  uint uVar7;
  
  puVar1 = (uint *)CONCAT31(in_register_0000000c,param_1);
  *puVar1 = 0;
  puVar1[1] = 0;
  sVar5 = 0;
  uVar6 = 0;
  sVar4 = GetScalerWidthForType(*(ushort *)(*(int *)in_r4 + 0x2c));
  *puVar1 = (sVar4 + -1) * 0x400 & 0xc00U | *puVar1 & 0xfffff04f | 0x6c;
  uVar2 = ((int (*)())ParseOperand__IsMatrix)(in_r4);
  *puVar1 = (uVar2 & 1) << 0xc | *puVar1 & 0xffffefff;
  iVar3 = ((int (*)())ParseOperand__IsMatrix)(in_r4);
  sVar4 = 0;
  if (iVar3 == 0) {
LAB_97bbb868:
    sVar5 = sVar4;
    uVar2 = *(uint *)(in_r4 + 0x20);
  }
  else {
    uVar2 = 0;
    if (*(int *)(in_r4 + 0x20) != 0) {
      sVar4 = GetDirectIndex(in_r4,0);
      uVar6 = 1;
      *puVar1 = *puVar1 & 0xffffefff;
      goto LAB_97bbb868;
    }
  }
  if (uVar6 == uVar2) {
    if (*(int *)(in_r4 + 0x14) == 0) {
      uVar2 = *puVar1;
      uVar6 = uVar2 >> 10 & 3;
      if (uVar6 == 1) {
LAB_97bbb950:
        uVar2 = uVar2 | 0x4000;
        *puVar1 = uVar2;
      }
      else if (uVar6 != 0) {
        if (uVar6 != 2) {
          if (uVar6 != 3) goto LAB_97bbba00;
          uVar2 = uVar2 | 0x10000;
          *puVar1 = uVar2;
        }
        uVar2 = uVar2 | 0x8000;
        *puVar1 = uVar2;
        goto LAB_97bbb950;
      }
      *puVar1 = uVar2 | 0x2000;
    }
    else {
      uVar2 = 0;
      if (*(int *)(in_r4 + 0x14) != 0) {
        do {
          iVar3 = ((int (*)())ParseOperand__GetSwizzle)(in_r4,uVar2);
          if (iVar3 == 1) {
            uVar6 = (uVar2 & 3) << 6 | *puVar1 & 0xffffff3f | 0x4000;
LAB_97bbb900:
            *puVar1 = uVar6;
          }
          else {
            if (1 < iVar3) {
              if (iVar3 == 2) {
                uVar6 = (uVar2 & 3) << 4 | *puVar1 & 0xffffffcf | 0x8000;
              }
              else {
                if (iVar3 != 3) goto LAB_97bbb904;
                uVar6 = (uVar2 & 3) << 2 | *puVar1 & 0xfffffff3 | 0x10000;
              }
              goto LAB_97bbb900;
            }
            if (iVar3 == 0) {
              uVar6 = (uVar2 & 3) << 8 | *puVar1 & 0xfffffcff | 0x2000;
              goto LAB_97bbb900;
            }
          }
LAB_97bbb904:
          uVar2 = uVar2 + 1;
        } while (uVar2 < *(uint *)(in_r4 + 0x14));
      }
    }
  }
  else {
    uVar7 = uVar6;
    if (uVar6 < uVar2) {
      do {
        iVar3 = GetDirectIndex(in_r4,uVar7);
        if (iVar3 == 1) {
          uVar2 = (uVar7 - uVar6) * 0x40 & 0xc0 | *puVar1 & 0xffffff3f | 0x4000;
LAB_97bbb9ec:
          *puVar1 = uVar2;
          uVar2 = *(uint *)(in_r4 + 0x20);
        }
        else {
          if (iVar3 == 0) {
            uVar2 = (uVar7 - uVar6) * 0x100 & 0x300 | *puVar1 & 0xfffffcff | 0x2000;
            goto LAB_97bbb9ec;
          }
          if (iVar3 == 2) {
            uVar2 = (uVar7 - uVar6) * 0x10 & 0x30 | *puVar1 & 0xffffffcf | 0x8000;
            goto LAB_97bbb9ec;
          }
          if (iVar3 == 3) {
            uVar2 = (uVar7 - uVar6) * 4 & 0xc | *puVar1 & 0xfffffff3 | 0x10000;
            goto LAB_97bbb9ec;
          }
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < uVar2);
    }
  }
LAB_97bbba00:
  if (*(char *)**(undefined4 **)in_r4 == '\0') {
    uVar2 = *puVar1;
    iVar3 = 1;
  }
  else {
    if (*(char *)**(undefined4 **)in_r4 != '\x04') goto LAB_97bbba4c;
    uVar2 = *puVar1;
    iVar3 = 3;
  }
  *puVar1 = iVar3 << 0x11 | uVar2 & 0xfff1ffff;
  *(short *)((int)puVar1 + 6) = *(short *)(**(int **)in_r4 + 0x12) + sVar5;
LAB_97bbba4c:
  if (in_r5 != 0) {
    puVar1[1] = puVar1[1] & 0x800fffff | 0x80000000;
  }
  return puVar1;
}

/* ParseOperand__GetAsSourceVar @ 0x97bbba7c (676 bytes) */
int ParseOperand__GetAsSourceVar(param_1)
  int param_1;
{
  byte bVar1;
  uint uVar2;
  undefined3 in_register_0000000c;
  uint *puVar3;
  ushort uVar5;
  int iVar4;
  unsigned char * in_r4;
  int in_r5;
  uint uVar6;
  ushort uVar8;
  uint uVar9;
  int iVar10;
  short sVar7;
  
  puVar3 = (uint *)CONCAT31(in_register_0000000c,param_1);
  *puVar3 = 0;
  puVar3[1] = 0;
  uVar6 = 0;
  sVar7 = 0;
  uVar5 = GetScalerWidthForType(*(ushort *)(*(int *)in_r4 + 0x2c));
  uVar9 = 0;
  *puVar3 = *puVar3 & 0xff85ffff | 0xd8000;
  uVar2 = *(uint *)(in_r4 + 0x14);
  if (uVar2 != 0) {
    do {
      if (uVar9 == 1) {
        uVar2 = ((int (*)())ParseOperand__GetSwizzle)(in_r4,1);
        uVar2 = (uVar2 & 3) << 0x13 | *puVar3 & 0xffe7ffff;
LAB_97bbbb6c:
        *puVar3 = uVar2;
        uVar2 = *(uint *)(in_r4 + 0x14);
      }
      else {
        if (uVar9 == 0) {
          uVar2 = ((int (*)())ParseOperand__GetSwizzle)(in_r4,0);
          uVar2 = (uVar2 & 3) << 0x15 | *puVar3 & 0xff9fffff;
          goto LAB_97bbbb6c;
        }
        if (uVar9 == 2) {
          uVar2 = ((int (*)())ParseOperand__GetSwizzle)(in_r4,2);
          uVar2 = (uVar2 & 3) << 0x11 | *puVar3 & 0xfff9ffff;
          goto LAB_97bbbb6c;
        }
        if (uVar9 == 3) {
          uVar2 = ((int (*)())ParseOperand__GetSwizzle)(in_r4,3);
          uVar2 = (uVar2 & 3) << 0xf | *puVar3 & 0xfffe7fff;
          goto LAB_97bbbb6c;
        }
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 < uVar2);
  }
  iVar4 = ((int (*)())ParseOperand__IsMatrix)(in_r4);
  uVar8 = 1;
  if (iVar4 != 0) {
    uVar8 = uVar5;
  }
  if (uVar5 == 1) {
    iVar4 = *(int *)(in_r4 + 0x20);
    if (iVar4 == 0) {
      uVar2 = *puVar3 >> 0x15 & 3;
      *puVar3 = uVar2 << 0x13 | uVar2 << 0x11 | uVar2 << 0xf | *puVar3 & 0xffe07fff;
      goto LAB_97bbbbc4;
    }
  }
  else {
LAB_97bbbbc4:
    iVar4 = *(int *)(in_r4 + 0x20);
  }
  iVar10 = iVar4;
  if (iVar4 != 0) {
    while( true ) {
      if (uVar8 < 2) {
        if (1 < uVar5) {
          uVar5 = 1;
        }
      }
      else {
        uVar8 = 1;
      }
      uVar2 = GetDirectIndex(in_r4,iVar4 - iVar10);
      if (uVar5 < 2) {
        *puVar3 = (uVar2 & 3) << 0x15 |
                  (uVar2 & 3) << 0x13 |
                  (uVar2 & 3) << 0x11 | (uVar2 & 3) << 0xf | *puVar3 & 0xff807fff;
        uVar2 = uVar6;
      }
      sVar7 = (short)uVar2;
      if (iVar10 + -1 == 0) break;
      iVar4 = *(int *)(in_r4 + 0x20);
      uVar6 = uVar2;
      iVar10 = iVar10 + -1;
    }
  }
  bVar1 = *(byte *)**(undefined4 **)in_r4;
  if (bVar1 == 2) {
    uVar6 = *puVar3 & 0xfc7fffff;
  }
  else {
    if (bVar1 < 3) {
      if (bVar1 != 0) goto LAB_97bbbcb0;
      uVar6 = *puVar3;
      iVar4 = 1;
    }
    else if (bVar1 == 3) {
      uVar6 = *puVar3;
      iVar4 = 2;
    }
    else {
      if (bVar1 != 4) goto LAB_97bbbcb0;
      uVar6 = *puVar3;
      iVar4 = 3;
    }
    uVar6 = iVar4 << 0x17 | uVar6 & 0xfc7fffff;
  }
  *puVar3 = uVar6;
  *(short *)((int)puVar3 + 6) = *(short *)(**(int **)in_r4 + 0x12) + sVar7;
LAB_97bbbcb0:
  *puVar3 = (uint)(uVar8 != 1) * 0x4000 | *puVar3 & 0xffffbfff;
  iVar4 = ((int (*)())ParseOperand__GetLogicalSize)(in_r4);
  uVar9 = *puVar3;
  uVar6 = (iVar4 + -1) * 0x1000 & 0x3000;
  *puVar3 = uVar6 | uVar9 & 0xffffcfff;
  uVar2 = (*(uint *)(in_r4 + 0x28) & 1) << 0x1b;
  *puVar3 = uVar2 | uVar6 | uVar9 & 0xf7ffcfff;
  if (in_r5 != 0) {
    *puVar3 = uVar2 | uVar6 | uVar9 & 0x87ffcfff | 0x80000000;
    *(undefined1 *)((int)puVar3 + 3) = 0;
  }
  return puVar3;
}

/* ParseOperand__IsMatrix @ 0x97bbbd20 (52 bytes) */
int ParseOperand__IsMatrix(this)
  unsigned char * this;
{
  ushort uVar1;
  
  if (*(int *)this == 0) {
    uVar1 = *(ushort *)(this + 0x18);
  }
  else {
    uVar1 = *(ushort *)(*(int *)this + 0x2c);
  }
  return uVar1 - 0x8b5a < 3;
}

/* ParseOperand__GetBaseSize @ 0x97bbbd54 (76 bytes) */
int ParseOperand__GetBaseSize(this)
  unsigned char * this;
{
  int iVar1;
  
  if (*(int *)this == 0) {
    iVar1 = *(int *)(this + 0x24);
  }
  else {
    iVar1 = *(int *)(this + 0x14);
    if (iVar1 == 0) {
      iVar1 = GetScalerWidthForType(*(ushort *)(*(int *)this + 0x2c));
    }
  }
  return iVar1;
}

/* ParseOperand__GetLogicalSize @ 0x97bbbda0 (132 bytes) */
int ParseOperand__GetLogicalSize(this)
  unsigned char * this;
{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  if (*(int *)this == 0) {
    uVar1 = 1;
    if (*(int *)(this + 0x20) == 0) {
      uVar1 = ((int (*)())ParseOperand__GetBaseSize)(this);
    }
  }
  else {
    uVar3 = *(uint *)(this + 0x20);
    if (((uVar3 == 1) && (iVar2 = ((int (*)())ParseOperand__IsMatrix)(this), iVar2 == 0)) || (1 < uVar3)) {
      uVar1 = 1;
    }
    else {
      uVar1 = ((int (*)())ParseOperand__GetBaseSize)(this);
    }
  }
  return uVar1;
}

/* ParseOperand__isWriteable @ 0x97bbbe24 (132 bytes) */
int ParseOperand__isWriteable(this)
  unsigned char * this;
{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (*(int *)this != 0) {
    uVar1 = (**(code **)(**(int **)(*(int *)this + 0xc) + 0x24))();
    switch(uVar1) {
    case 0:
    case 1:
    case 5:
    case 7:
    case 8:
    case 9:
    case 10:
    case 0xb:
    case 0xd:
    case 0xe:
    case 0xf:
    case 0x12:
    case 0x13:
      uVar1 = 1;
      break;
    default:
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* ParseOperand__AddSwizzle @ 0x97bbbef8 (184 bytes) */
int ParseOperand__AddSwizzle(this, param_1)
  unsigned char * this;
  int param_1;
{
  uint uVar1;
  void *pvVar2;
  uint uVar3;
  void *pvVar4;
  
  uVar1 = *(uint *)(this + 0x14);
  if ((uVar1 & 3) == 0) {
    pvVar2 = _malloc(uVar1 + 4);
    _memset(pvVar2,0,*(int *)(this + 0x14) + 4);
    uVar1 = *(uint *)(this + 0x14);
    uVar3 = 0;
    if (uVar1 == 0) {
      pvVar4 = *(void **)(this + 0x10);
    }
    else {
      pvVar4 = *(void **)(this + 0x10);
      do {
        *(undefined1 *)((int)pvVar2 + uVar3) = *(undefined1 *)((int)pvVar4 + uVar3);
        uVar3 = uVar3 + 1 & 0xff;
      } while (uVar3 < uVar1);
    }
    if (pvVar4 != (void *)0x0) {
      _free(pvVar4);
      uVar1 = *(uint *)(this + 0x14);
    }
    *(void **)(this + 0x10) = pvVar2;
  }
  *(uchar *)(*(int *)(this + 0x10) + uVar1) = param_1;
  *(int *)(this + 0x14) = *(int *)(this + 0x14) + 1;
  return;
}

/* ParseOperand__RemoveSwizzle @ 0x97bbbfb0 (16 bytes) */
int ParseOperand__RemoveSwizzle(this)
  unsigned char * this;
{
  *(int *)(this + 0x14) = *(int *)(this + 0x14) + -1;
  return;
}

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
    for (uVar9 = 0; uVar7 = ((int (*)())ParseOperand__GetBaseSize)(this), uVar9 < uVar7; uVar9 = uVar9 + 1) {
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
      ((int (*)())ParseOperand__AddSwizzle)(param_1,(uchar)iVar3);
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
            ((int (*)())ParseOperand__ParseOperand)(pPVar7);
            *(unsigned char **)pPVar7 = pPVar6;
            ((int (*)())ParseSymbolTable__processOperand)(this,pPVar7);
            ((int (*)())ParseOperand___ParseOperand)(pPVar7);
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
          ((int (*)())ParseSymbol__AddDirectIndex)(pPVar6,uVar10);
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
          ((int (*)())ParseOperand__ParseOperand)(pPVar7);
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
            ((int (*)())ParseOperand___ParseOperand)(pPVar7);
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
  ((int (*)())ParseOperand__ParseOperand)(pPVar7);
  *(unsigned char **)pPVar7 = pPVar6;
  ((int (*)())ParseSymbolTable__processOperand)(this,pPVar7);
  ((int (*)())ParseOperand___ParseOperand)(pPVar7);
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
          ((int (*)())ParseSymbol__AddDirectIndex)(pPVar1,uVar13);
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

