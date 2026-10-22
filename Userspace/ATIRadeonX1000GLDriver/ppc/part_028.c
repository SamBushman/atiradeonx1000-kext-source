#include "decls.h"

/* FUN_0010564c @ 0x10564c (584 bytes) */
int FUN_0010564c(inst, param_2, param_3)
  int *inst;
  int param_2;
  int param_3;
{
  int loopIndex;
  int iVar1;
  undefined4 uVar2;
  int *a0;
  int iVar3;
  int *a0_00;
  int operandVReg;
  int iVar5;
  
  iVar1 = IRInst__useCount(inst,*(undefined4 *)(param_2 + 0x6c4));
  uVar2 = 0;
  if (iVar1 == 0) {
    if (param_3 == 0) {
      iVar1 = inst[0x21];
      iVar3 = 1;
      if (0 < iVar1) {
        do {
          iVar5 = IRInst__getOperandSource(inst,iVar3);
          iVar1 = inst[0x21];
          iVar3 = iVar3 + 1;
          *(int *)(iVar5 + 0x160) = *(int *)(iVar5 + 0x160) + -1;
        } while (iVar3 <= iVar1);
      }
    }
    else {
      iVar1 = inst[0x21];
    }
    if (0 < iVar1) {
      loopIndex = 1;
      do {
        a0 = (int *)IRInst__getOperandSource(inst,loopIndex);
        iVar3 = (**(code **)(*a0 + 0x5c))(a0);
        if ((iVar3 != 0) || (iVar3 = (**(code **)(*a0 + 0x60))(a0), iVar3 != 0)) {
          iVar5 = 1;
          iVar3 = IRInst__useCount(a0,*(undefined4 *)(param_2 + 0x6c4));
          if (iVar3 == 0) {
            for (; iVar3 = (**(code **)(*a0 + 0x14))(a0), iVar5 <= iVar3; iVar5 = iVar5 + 1) {
              a0_00 = (int *)IRInst__getOperandSource(a0,iVar5);
              a0_00[0x58] = a0_00[0x58] + -1;
              iVar3 = (**(code **)(*a0_00 + 0x5c))(a0_00);
              if ((iVar3 != 0) &&
                 (iVar3 = IRInst__useCount(a0_00,*(undefined4 *)(param_2 + 0x6c4)), iVar3 == 0)) {
                (**(code **)(*a0 + 0x60))(a0);
                for (iVar3 = 1; operandVReg = (**(code **)(*a0_00 + 0x14))(a0_00), iVar3 <= operandVReg;
                    iVar3 = iVar3 + 1) {
                  operandVReg = IRInst__getOperandSource(a0_00,iVar3);
                  *(int *)(operandVReg + 0x160) = *(int *)(operandVReg + 0x160) + -1;
                }
                (**(code **)(*a0_00 + 0xc))(a0_00,param_3,param_2);
              }
            }
            (**(code **)(*a0 + 0xc))(a0,param_3,param_2);
          }
        }
        loopIndex = loopIndex + 1;
      } while (loopIndex <= inst[0x21]);
    }
    (**(code **)(*inst + 0xc))(inst,param_3,param_2);
    uVar2 = 1;
  }
  return uVar2;
}

/* FUN_00105894 @ 0x105894 (20 bytes) */
int FUN_00105894(inst, arg)
  int inst;
  undefined4 arg;
{
  undefined4 uVar1;
  
  *(int *)(inst + 0x160) = *(int *)(inst + 0x160) + -1;
  uVar1 = ((int (*)())FUN_0010564c)(inst,arg,0);
  return uVar1;
}

/* FUN_001058a8 @ 0x1058a8 (136 bytes) */
int FUN_001058a8(inst, param_2)
  int inst;
  int param_2;
{
  int operandVReg;
  int iVar2;
  
  if (((*(uint *)(param_2 + 0x30) & 0x80) != 0) && (iVar2 = 1, 0 < *(int *)(inst + 0x84))) {
    do {
      operandVReg = IRInst__getOperandSource(inst,iVar2);
      if (operandVReg != 0) {
        operandVReg = IRInst__getOperandSource(inst,iVar2);
        *(int *)(operandVReg + 0x160) = *(int *)(operandVReg + 0x160) + -1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 <= *(int *)(inst + 0x84));
  }
  return;
}

/* FUN_00105930 @ 0x105930 (276 bytes) */
int FUN_00105930(inst, param_2)
  int inst;
  int param_2;
{
  int operandVReg;
  uint uVar2;
  int *piVar3;
  int iVar4;
  uint loopIndex;
  uint *puVar6;
  
  if (((*(uint *)(param_2 + 0x30) & 0x80) != 0) && (iVar4 = 1, 0 < *(int *)(inst + 0x84))) {
    do {
      operandVReg = IRInst__getOperandSource(inst,iVar4);
      if (operandVReg != 0) {
        operandVReg = IRInst__getOperandSource(inst,iVar4);
        puVar6 = *(uint **)(operandVReg + 0x10);
        uVar2 = puVar6[1];
        if (0 < (int)uVar2) {
          loopIndex = 0;
          do {
            if (loopIndex < *puVar6) {
              if (uVar2 <= loopIndex) {
                _memset(uVar2 * 4 + puVar6[2],0,(loopIndex - uVar2) * 4 + 4);
                puVar6[1] = loopIndex + 1;
              }
              piVar3 = (int *)(loopIndex * 4 + puVar6[2]);
            }
            else {
              piVar3 = (int *)Vector__elementRefGrow(puVar6,loopIndex);
            }
            if (inst == *piVar3) {
              Vector__removeAt(puVar6,loopIndex);
              break;
            }
            uVar2 = puVar6[1];
            loopIndex = loopIndex + 1;
          } while ((int)loopIndex < (int)uVar2);
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 <= *(int *)(inst + 0x84));
  }
  return;
}

/* IRStartCallRoutine__vslot4 @ 0x105a44 (224 bytes) */
int IRStartCallRoutine__vslot4(param_1, param_2)
  int *param_1;
  int param_2;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = (**(code **)(*param_1 + 0x34))(param_1,param_2);
  if (iVar2 == 0) {
    (**(code **)(*param_1 + 0x38))(param_1);
  }
  ((int (*)())FUN_00105930)(param_1,*(undefined4 *)(param_2 + 0x6c4));
  iVar3 = param_1[1];
  iVar2 = (**(code **)(*param_1 + 0x40))(param_1);
  if ((iVar2 != 0) &&
     (iVar2 = *(int *)(*(int *)(param_2 + 0x6c4) + 0x3a0), param_1 == *(int **)(iVar2 + 300))) {
    *(int *)(iVar2 + 300) = iVar3;
  }
  uVar1 = param_1[5];
  if ((((uVar1 & 4) == 0) && (iVar3 != 0)) && ((*(uint *)(iVar3 + 0x14) & 4) != 0)) {
    *(uint *)(iVar3 + 0x14) = *(uint *)(iVar3 + 0x14) & 0xfffffffb;
    uVar1 = param_1[5];
  }
  param_1[5] = uVar1 & 0xfffffffe;
  return DList__unlink(param_1);
}

/* FUN_00105b24 @ 0x105b24 (88 bytes) */
int FUN_00105b24(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  if ((*(uint *)(param_2 + 0x30) & 0x80) != 0) {
    ((int (*)())FUN_00105930)(param_1,param_2);
    ((int (*)())FUN_001058a8)(param_1,param_2);
    return;
  }
  return;
}

/* IRStartCallRoutine__vslot3 @ 0x105b7c (224 bytes) */
int IRStartCallRoutine__vslot3(param_1, param_2, param_3)
  int *param_1;
  undefined4 param_2;
  int param_3;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = (**(code **)(*param_1 + 0x34))(param_1,param_2,param_3);
  if (iVar2 == 0) {
    (**(code **)(*param_1 + 0x38))(param_1);
  }
  ((int (*)())FUN_00105b24)(param_1,*(undefined4 *)(param_3 + 0x6c4));
  iVar3 = param_1[1];
  iVar2 = (**(code **)(*param_1 + 0x40))(param_1);
  if ((iVar2 != 0) &&
     (iVar2 = *(int *)(*(int *)(param_3 + 0x6c4) + 0x3a0), param_1 == *(int **)(iVar2 + 300))) {
    *(int *)(iVar2 + 300) = iVar3;
  }
  uVar1 = param_1[5];
  if ((((uVar1 & 4) == 0) && (iVar3 != 0)) && ((*(uint *)(iVar3 + 0x14) & 4) != 0)) {
    *(uint *)(iVar3 + 0x14) = *(uint *)(iVar3 + 0x14) & 0xfffffffb;
    uVar1 = param_1[5];
  }
  param_1[5] = uVar1 & 0xfffffffe;
  return DList__unlink(param_1);
}

/* FUN_00105c5c @ 0x105c5c (168 bytes) */
int FUN_00105c5c(inst, param_2)
  int inst;
  int param_2;
{
  int operandVReg;
  undefined4 uVar2;
  int *piVar3;
  
  while( true ) {
    if (param_2 == 0) {
      return *(undefined4 *)(inst + 0x128);
    }
    operandVReg = IRInst__getOperandSource(inst,param_2);
    if (operandVReg == 0) break;
    inst = IRInst__getOperandSource(inst,param_2);
    param_2 = 0;
  }
  piVar3 = *(int **)(param_2 * 0x18 + inst + 0x8c);
  if (piVar3 == (int *)0x0) {
    return 0;
  }
                    
                    
  uVar2 = (**(code **)(*piVar3 + 0x24))(piVar3);
  return uVar2;
}

/* FUN_00105d04 @ 0x105d04 (184 bytes) */
int FUN_00105d04(param_1, inst)
  undefined4 *param_1;
  int *inst;
{
  int iVar1;
  int operandRecord;
  int iVar3;
  
  if ((inst[5] & 0x200U) == 0) {
    iVar3 = inst[0x21];
  }
  else {
    iVar3 = inst[0x21] + -1;
  }
  iVar1 = (**(code **)(*inst + 0x14))(inst);
  do {
    iVar1 = iVar1 + 1;
    if (iVar3 < iVar1) {
      *param_1 = DAT_001af9bc;
      return param_1;
    }
    operandRecord = IRInst__getOperandRecord(inst,iVar1);
  } while ((*(uint *)(*(int *)(operandRecord + 4) + 0x14) & 0x80000) == 0);
  *param_1 = *(undefined4 *)(operandRecord + 0x10);
  return param_1;
}

/* FUN_00105dbc @ 0x105dbc (152 bytes) */
int FUN_00105dbc(inst, param_2)
  undefined4 inst;
  int param_2;
{
  undefined1 uVar1;
  int iVar2;
  
  if ((param_2 < 1) || (iVar2 = IRInst__getOperandSource(inst,param_2), iVar2 == 0)) {
    iVar2 = IRInst__getOperandRecord(inst,param_2);
    iVar2 = *(int *)(iVar2 + 0xc);
  }
  else {
    iVar2 = IRInst__getOperandSource(inst,param_2);
    iVar2 = *(int *)(iVar2 + 0x98);
  }
  uVar1 = 2;
  if (PTR_PTR_001e8c60[iVar2 * 0x10 + 9] != '\x01') {
    uVar1 = PTR_PTR_001e8c60[iVar2 * 0x10 + 9] == '\x02';
  }
  return uVar1;
}

/* FUN_00105e54 @ 0x105e54 (72 bytes) */
int FUN_00105e54(param_1, param_2, inst, param_4)
  int param_1;
  int param_2;
  undefined4 inst;
  undefined4 param_4;
{
  undefined4 operandRecord;
  
  operandRecord = IRInst__getOperandRecord(inst,param_4);
  return FUN_00104730(param_2 * 0x18 + param_1 + 0x8c,operandRecord);
}

/* FUN_00105e9c @ 0x105e9c (104 bytes) */
int FUN_00105e9c(inst, param_2)
  int inst;
  undefined4 param_2;
{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(inst + 0x84);
  iVar1 = iVar2 + 1;
  *(int *)(inst + 0x84) = iVar1;
  if ((*(uint *)(inst + 0x14) & 0x200) != 0) {
    ((int (*)())FUN_00105e54)(inst,iVar1,inst,iVar2);
    iVar1 = *(int *)(inst + 0x84) + -1;
  }
  return IRInst__setOperandRef(inst,iVar1,param_2);
}

/* IRInst__addToUseLists @ 0x105f04 (256 bytes) */
int IRInst__addToUseLists(inst, program)
  int inst;
  int program;
{
  int operandVReg;
  int *elementRef;
  int operandIndex;
  uint count;
  uint *vectorHeader;
  
  if (((*(uint *)(program + 0x30) & 0x80) != 0) && (operandIndex = 1, 0 < *(int *)(inst + 0x84))) {
    do {
      operandVReg = IRInst__getOperandSource(inst,operandIndex);
      if (operandVReg != 0) {
        operandVReg = IRInst__getOperandSource(inst,operandIndex);
        vectorHeader = *(uint **)(operandVReg + 0x10);
        count = vectorHeader[1];
        if (count < *vectorHeader) {
          _memset(count * 4 + vectorHeader[2],0,4);
          elementRef = (int *)(count * 4 + vectorHeader[2]);
          vectorHeader[1] = count + 1;
        }
        else {
          elementRef = (int *)Vector__elementRefGrow(vectorHeader,count);
        }
        *elementRef = inst;
        operandVReg = IRInst__getOperandSource(inst,operandIndex);
        if (*(int *)(program + 0x478) < *(int *)(operandVReg + 0x160)) {
          *(int *)(operandVReg + 0x160) = *(int *)(operandVReg + 0x160) + 1;
        }
        else {
          *(int *)(operandVReg + 0x160) = *(int *)(program + 0x478) + 1;
        }
      }
      operandIndex = operandIndex + 1;
    } while (operandIndex <= *(int *)(inst + 0x84));
  }
  return;
}

/* IRInst__setOperandSource @ 0x106004 (428 bytes) */
int IRInst__setOperandSource(inst, operandIndex, newSource, trackUses, compilerCtx)
  int inst;
  undefined4 operandIndex;
  int newSource;
  int trackUses;
  int compilerCtx;
{
  int operandVReg;
  uint count;
  int *elementRef;
  int options;
  uint loopIndex;
  uint *vectorHeader;
  
  options = *(int *)(compilerCtx + 0x6c4);
  if ((trackUses != 0) && (operandVReg = IRInst__getOperandSource(inst,operandIndex), operandVReg != 0)) {
    operandVReg = IRInst__getOperandSource(inst,operandIndex);
    vectorHeader = *(uint **)(operandVReg + 0x10);
    count = vectorHeader[1];
    if (0 < (int)count) {
      loopIndex = 0;
      do {
        if (loopIndex < *vectorHeader) {
          if (count <= loopIndex) {
            _memset(count * 4 + vectorHeader[2],0,(loopIndex - count) * 4 + 4);
            vectorHeader[1] = loopIndex + 1;
          }
          elementRef = (int *)(loopIndex * 4 + vectorHeader[2]);
        }
        else {
          elementRef = (int *)Vector__elementRefGrow(vectorHeader,loopIndex);
        }
        if (inst == *elementRef) {
          Vector__removeAt(vectorHeader,loopIndex);
          operandVReg = IRInst__getOperandSource(inst,operandIndex);
          *(int *)(operandVReg + 0x160) = *(int *)(operandVReg + 0x160) + -1;
          break;
        }
        count = vectorHeader[1];
        loopIndex = loopIndex + 1;
      } while ((int)loopIndex < (int)count);
    }
  }
  IRInst__setOperandSourceRaw(inst,operandIndex,newSource,compilerCtx);
  if ((trackUses != 0) && (newSource != 0)) {
    vectorHeader = *(uint **)(newSource + 0x10);
    count = vectorHeader[1];
    if (count < *vectorHeader) {
      _memset(count * 4 + vectorHeader[2],0,4);
      elementRef = (int *)(count * 4 + vectorHeader[2]);
      vectorHeader[1] = count + 1;
    }
    else {
      elementRef = (int *)Vector__elementRefGrow(vectorHeader,count);
    }
    *elementRef = inst;
    options = *(int *)(options + 0x478);
    if (options < *(int *)(newSource + 0x160)) {
      *(int *)(newSource + 0x160) = *(int *)(newSource + 0x160) + 1;
    }
    else {
      *(int *)(newSource + 0x160) = options + 1;
    }
  }
  return;
}

/* FUN_001061b0 @ 0x1061b0 (128 bytes) */
int FUN_001061b0(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  int iVar1;
  int iVar2;
  int loopIndex;
  int iVar4;
  
  iVar1 = *(int *)(param_1 + 0x84);
  iVar2 = *(int *)(param_2 + 0x8c);
  if (0 < iVar1) {
    loopIndex = 1;
    iVar4 = param_1;
    do {
      if (iVar2 == *(int *)(iVar4 + 0xa4)) {
        ((int (*)())IRInst__setOperandSource)(param_1,loopIndex,param_2,0,param_3);
        iVar1 = *(int *)(param_1 + 0x84);
      }
      loopIndex = loopIndex + 1;
      iVar4 = iVar4 + 0x18;
    } while (loopIndex <= iVar1);
  }
  return;
}

/* FUN_00106230 @ 0x106230 (144 bytes) */
int FUN_00106230(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  int param_6;
{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_6 + 0x30c) + 0x11c))
                    (*(int **)(param_6 + 0x30c),param_1,param_2,param_3,param_4,param_5,param_6);
  if (iVar1 != 0) {
    ((int (*)())IRInst__setOperandSource)(param_1,param_2,param_3,0,param_6);
  }
  return iVar1 != 0;
}

/* FUN_001062c0 @ 0x1062c0 (156 bytes) */
int FUN_001062c0(param_1, param_2, param_3, compiler)
  int param_1;
  int param_2;
  undefined4 *param_3;
  int compiler;
{
  undefined4 arena;
  undefined4 *allocation;
  int *piVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uVar8;
  uint *puVar9;
  
  if (param_2 < 5) {
    allocation = (undefined4 *)(param_2 * 0x18 + param_1 + 0x8c);
  }
  else {
    puVar9 = *(uint **)(param_1 + 0x118);
    if (puVar9 == (uint *)0x0) {
      arena = *(undefined4 *)(compiler + 0x374);
      allocation = (undefined4 *)Arena__alloc(arena,0x14);
      puVar9 = allocation + 1;
      *allocation = arena;
      allocation[1] = 2;
      allocation[2] = 0;
      allocation[4] = arena;
      arena = Arena__alloc(arena,8);
      allocation[3] = arena;
      *(uint **)(param_1 + 0x118) = puVar9;
    }
    if ((int)puVar9[1] < (int)(param_2 - 4U)) {
      arena = *(undefined4 *)(compiler + 0x374);
      allocation = (undefined4 *)Arena__alloc(arena,0x1c);
      *allocation = arena;
      allocation[1] = 0;
      allocation[2] = 0;
      allocation[6] = 0;
      puVar9 = *(uint **)(param_1 + 0x118);
      uVar8 = puVar9[1];
      if (uVar8 < *puVar9) {
        _memset((void *)(uVar8 * 4 + puVar9[2]),0,4);
        piVar3 = (int *)(uVar8 * 4 + puVar9[2]);
        puVar9[1] = uVar8 + 1;
      }
      else {
        piVar3 = (int *)Vector__elementRefGrow(puVar9,uVar8);
      }
      *piVar3 = (int)(allocation + 1);
      FUN_00103e84(allocation + 1,param_2);
      puVar9 = *(uint **)(param_1 + 0x118);
    }
    uVar8 = param_2 - 5;
    if (uVar8 < *puVar9) {
      uVar4 = puVar9[1];
      if (uVar4 <= uVar8) {
        _memset((void *)(uVar4 * 4 + puVar9[2]),0,(uVar8 - uVar4) * 4 + 4);
        puVar9[1] = param_2 - 4U;
      }
      allocation = (undefined4 *)(uVar8 * 4 + puVar9[2]);
    }
    else {
      allocation = (undefined4 *)Vector__elementRefGrow(puVar9,uVar8);
    }
    allocation = (undefined4 *)*allocation;
  }
  IROperand__setModifierBits(allocation,1,param_3[5] & 1);
  IROperand__setModifierBits(allocation,2,(uint)param_3[5] >> 1 & 1);
  arena = *param_3;
  uVar5 = param_3[1];
  uVar7 = param_3[2];
  uVar6 = param_3[3];
  allocation[4] = param_3[4];
  *allocation = arena;
  allocation[1] = uVar5;
  allocation[2] = uVar7;
  allocation[3] = uVar6;
  return;
}

/* IRStartCallRoutine__vslot2 @ 0x10647c (620 bytes) */
int IRStartCallRoutine__vslot2(inst, param_2)
  int *inst;
  int param_2;
{
  int loopIndex;
  bool bVar1;
  uint uVar2;
  int iVar3;
  int operandRecord;
  int iVar5;
  int iVar6;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30 [4];
  
  if (0 < inst[0x20]) {
    loopIndex = 0;
    do {
      iVar3 = (**(code **)(*inst + 0x24))(inst);
      if (iVar3 != 0) {
        IRInst__getOperandRecord(inst,loopIndex);
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex < inst[0x20]);
  }
  iVar5 = *(int *)(param_2 + 0x6c4);
  if (((*(uint *)(iVar5 + 0x30) & 8) == 0) && (*(int *)(inst[0x22] + 8) != 0x8e)) {
    iVar3 = IRInst__getOperandRecord(inst,0);
    iVar5 = 0;
    local_38 = *(undefined4 *)(iVar3 + 0x10);
    iVar3 = 4;
    do {
      if (*(char *)((int)&local_38 + iVar5) == '\0') {
        loopIndex = 1;
        if (0 < inst[0x21]) {
          do {
            iVar3 = (**(code **)(*inst + 0x24))(inst);
            if ((iVar3 != 0) || (iVar3 = (**(code **)(*inst + 0x28))(inst), iVar3 != 0)) {
              IRInst__getOperandRecord(inst,loopIndex);
            }
            loopIndex = loopIndex + 1;
          } while (loopIndex <= inst[0x21]);
        }
        goto LAB_0010663c;
      }
      iVar5 = iVar5 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    iVar5 = *(int *)(param_2 + 0x6c4);
    if (((*(uint *)(iVar5 + 0x30) & 0x20000) != 0) && (iVar3 = 1, 0 < inst[0x21])) {
      do {
        iVar5 = IRInst__getOperandRecord(inst,iVar3);
        local_34 = *(undefined4 *)(iVar5 + 0x10);
        iVar5 = IRInst__getOperandSource(inst,iVar3);
        if (iVar5 != 0) {
          operandRecord = IRInst__getOperandRecord(iVar5,0);
          iVar6 = 0;
          local_30[0] = *(undefined4 *)(operandRecord + 0x10);
          do {
            uVar2 = (uint)*(byte *)((int)local_30 + iVar6 + -4);
            if (((uVar2 != 4) && (*(char *)((int)local_30 + uVar2) != '\0')) &&
               ((*(uint *)(iVar5 + 0x14) & 0x200) != 0)) {
              IRInst__getOperandRecord(iVar5,*(undefined4 *)(iVar5 + 0x84));
            }
            bVar1 = iVar6 != 3;
            iVar6 = iVar6 + 1;
          } while (bVar1);
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 <= inst[0x21]);
LAB_0010663c:
      iVar5 = *(int *)(param_2 + 0x6c4);
    }
  }
  if ((*(uint *)(iVar5 + 0x30) & 0x800) == 0) {
    (**(code **)(*inst + 0x68))(inst);
  }
  if (((inst[5] & 0x200U) != 0) && ((*(uint *)(*(int *)(param_2 + 0x6c4) + 0x30) & 8) != 0)) {
    IRInst__getOperandSource(inst,inst[0x21]);
  }
  (**(code **)(*inst + 100))(inst);
  return 1;
}

/* IRProjection__vslot2 @ 0x1066e8 (84 bytes) */
int IRProjection__vslot2(inst, param_2)
  undefined4 inst;
  undefined4 param_2;
{
  int iVar1;
  
  iVar1 = FUN_001045e4(inst);
  if (iVar1 != 0) {
    iVar1 = IRInst__getOperandRecord(inst,1);
    FUN_000f2c5c(*(undefined4 *)(iVar1 + 0x10));
  }
  return ((int (*)())IRStartCallRoutine__vslot2)(inst,param_2);
}

/* IRPresub2__vslot2 @ 0x10673c (68 bytes) */
int IRPresub2__vslot2(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  (**(code **)(*param_1 + 0x14))(param_1,param_2);
  return ((int (*)())IRStartCallRoutine__vslot2)(param_1,param_2);
}

/* IRPhiNode__vslot2 @ 0x106780 (128 bytes) */
int IRPhiNode__vslot2(inst, param_2)
  int inst;
  undefined4 param_2;
{
  int loopIndex;
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(inst + 0x84);
  if (0 < iVar1) {
    loopIndex = 1;
    do {
      iVar1 = IRInst__getOperandRecord(inst,loopIndex);
      loopIndex = loopIndex + 1;
      FUN_000f3190(*(undefined4 *)(iVar1 + 0x10));
      iVar1 = *(int *)(inst + 0x84);
    } while (loopIndex <= iVar1);
  }
  if (1 < iVar1) {
    iVar2 = 2;
    do {
      iVar2 = iVar2 + 1;
    } while (iVar2 <= iVar1);
  }
  return ((int (*)())IRStartCallRoutine__vslot2)(inst,param_2);
}

/* IRInst__setExtraOperandSource @ 0x106804 (484 bytes) */
int IRInst__setExtraOperandSource(inst, newSource, trackUses, compilerCtx)
  int inst;
  int newSource;
  int trackUses;
  int compilerCtx;
{
  undefined4 extraOperandSwizzle;
  uint flagsOrCount;
  int oldSource;
  int *elementRef;
  int options;
  uint loopIndex;
  uint *vectorHeader;
  
  options = *(int *)(compilerCtx + 0x6c4);
  if (trackUses != 0) {
    flagsOrCount = *(uint *)(inst + 0x14);
    if ((flagsOrCount & 0x200) == 0) goto LAB_00106908;
    oldSource = IRInst__getOperandSource(inst,*(undefined4 *)(inst + 0x84));
    if (oldSource != 0) {
      vectorHeader = *(uint **)(oldSource + 0x10);
      flagsOrCount = vectorHeader[1];
      if (0 < (int)flagsOrCount) {
        loopIndex = 0;
        do {
          if (loopIndex < *vectorHeader) {
            if (flagsOrCount <= loopIndex) {
              _memset(flagsOrCount * 4 + vectorHeader[2],0,(loopIndex - flagsOrCount) * 4 + 4);
              vectorHeader[1] = loopIndex + 1;
            }
            elementRef = (int *)(loopIndex * 4 + vectorHeader[2]);
          }
          else {
            elementRef = (int *)Vector__elementRefGrow(vectorHeader,loopIndex);
          }
          if (inst == *elementRef) {
            Vector__removeAt(vectorHeader,loopIndex);
            flagsOrCount = *(uint *)(inst + 0x14);
            *(int *)(oldSource + 0x160) = *(int *)(oldSource + 0x160) + -1;
            goto LAB_00106908;
          }
          flagsOrCount = vectorHeader[1];
          loopIndex = loopIndex + 1;
        } while ((int)loopIndex < (int)flagsOrCount);
      }
    }
  }
  flagsOrCount = *(uint *)(inst + 0x14);
LAB_00106908:
  if ((flagsOrCount & 0x200) == 0) {
    *(uint *)(inst + 0x14) = flagsOrCount | 0x200;
    extraOperandSwizzle = DAT_001af9c4;
    oldSource = *(int *)(inst + 0x84) + 1;
    *(int *)(inst + 0x84) = oldSource;
    oldSource = IRInst__getOperandRecord(inst,oldSource);
    *(undefined4 *)(oldSource + 0x10) = extraOperandSwizzle;
  }
  IRInst__setOperandSourceRaw(inst,*(undefined4 *)(inst + 0x84),newSource,compilerCtx);
  if ((trackUses != 0) && (newSource != 0)) {
    vectorHeader = *(uint **)(newSource + 0x10);
    flagsOrCount = vectorHeader[1];
    if (flagsOrCount < *vectorHeader) {
      _memset(flagsOrCount * 4 + vectorHeader[2],0,4);
      elementRef = (int *)(flagsOrCount * 4 + vectorHeader[2]);
      vectorHeader[1] = flagsOrCount + 1;
    }
    else {
      elementRef = (int *)Vector__elementRefGrow(vectorHeader,flagsOrCount);
    }
    *elementRef = inst;
    options = *(int *)(options + 0x478);
    if (options < *(int *)(newSource + 0x160)) {
      *(int *)(newSource + 0x160) = *(int *)(newSource + 0x160) + 1;
    }
    else {
      *(int *)(newSource + 0x160) = options + 1;
    }
  }
  return;
}

/* FUN_001069e8 @ 0x1069e8 (352 bytes) */
int FUN_001069e8(inst, param_2, param_3)
  int inst;
  undefined4 param_2;
  int param_3;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = *(int *)(inst + 0x84);
  iVar3 = iVar2 + 1;
  *(int *)(inst + 0x84) = iVar3;
  if ((*(uint *)(inst + 0x14) & 0x200) == 0) {
    ((int (*)())IRInst__setOperandSource)(inst,iVar3,param_2,0,param_3);
    uVar1 = DAT_001af9bc;
    if (iVar3 == 0) {
      *(undefined4 *)(inst + 0x9c) = DAT_001af9bc;
    }
    else {
      iVar2 = IRInst__getOperandRecord(inst,iVar3);
      *(undefined4 *)(iVar2 + 0x10) = uVar1;
    }
  }
  else {
    if ((*(uint *)(*(int *)(param_3 + 0x6c4) + 0x30) & 8) == 0) {
      uVar1 = IRInst__getOperandSource(inst,iVar2);
      ((int (*)())IRInst__setOperandSource)(inst,iVar3,uVar1,0,param_3);
    }
    else {
      uVar1 = IRInst__getOperandSource(inst,iVar2);
      ((int (*)())IRInst__setExtraOperandSource)(inst,uVar1,0,param_3);
    }
    iVar4 = *(int *)(inst + 0x84);
    iVar3 = IRInst__getOperandRecord(inst,iVar2);
    uVar1 = *(undefined4 *)(iVar3 + 0x10);
    if (iVar4 == 0) {
      *(undefined4 *)(inst + 0x9c) = uVar1;
    }
    else {
      iVar3 = IRInst__getOperandRecord(inst,iVar4);
      *(undefined4 *)(iVar3 + 0x10) = uVar1;
    }
    ((int (*)())IRInst__setOperandSource)(inst,iVar2,param_2,0,param_3);
    uVar1 = DAT_001af9bc;
    if (iVar2 == 0) {
      *(undefined4 *)(inst + 0x9c) = DAT_001af9bc;
      iVar3 = 0;
    }
    else {
      iVar3 = IRInst__getOperandRecord(inst,iVar2);
      *(undefined4 *)(iVar3 + 0x10) = uVar1;
      iVar3 = iVar2;
    }
  }
  return iVar3;
}

/* FUN_00106b48 @ 0x106b48 (88 bytes) */
int FUN_00106b48(inst, param_2, param_3, param_4)
  int inst;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  int operandRecord;
  undefined4 uVar2;
  
  ((int (*)())IRInst__setExtraOperandSource)(inst,*(undefined4 *)(param_2 + 4),param_3,param_4);
  uVar2 = *(undefined4 *)(param_2 + 0x10);
  if (*(int *)(inst + 0x84) == 0) {
    *(undefined4 *)(inst + 0x9c) = uVar2;
  }
  else {
    operandRecord = IRInst__getOperandRecord(inst,*(int *)(inst + 0x84));
    *(undefined4 *)(operandRecord + 0x10) = uVar2;
  }
  return;
}

/* IRMix__vslot2 @ 0x106ba0 (276 bytes) */
int IRMix__vslot2(inst, param_2, param_3, param_4, param_5, param_6, param_7)
  int *inst;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  int loopIndex2;
  bool bVar1;
  int iVar2;
  undefined4 operandVReg;
  int operandRecord;
  int *a0;
  int loopIndex;
  
  if (0 < inst[0x21]) {
    loopIndex2 = 1;
    do {
      loopIndex2 = loopIndex2 + 1;
    } while (loopIndex2 <= inst[0x21]);
  }
  iVar2 = 0;
  do {
    IRInst__getOperandRecord(inst,0);
    if (0 < inst[0x21]) {
      loopIndex = 1;
      do {
        IRInst__getOperandRecord(inst,loopIndex);
        if ((*(uint *)(*(int *)(param_2 + 0x6c4) + 0x30) & 8) != 0) {
          if (loopIndex != 1) {
            operandVReg = IRInst__getOperandSource(inst,loopIndex);
            operandRecord = IRInst__getOperandRecord(inst,loopIndex);
            FUN_0010453c(operandVReg,param_2,*(undefined4 *)(operandRecord + 0x10),param_4,param_5,param_6,param_7
                        );
          }
          a0 = (int *)IRInst__getOperandSource(inst,loopIndex);
          (**(code **)(*a0 + 0x60))(a0);
        }
        loopIndex = loopIndex + 1;
      } while (loopIndex <= inst[0x21]);
    }
    bVar1 = iVar2 != 3;
    iVar2 = iVar2 + 1;
  } while (bVar1);
  (**(code **)(*inst + 0x14))(inst);
  return ((int (*)())IRStartCallRoutine__vslot2)(inst,param_2);
}

/* IRPresub1__vslot2 @ 0x106cb4 (68 bytes) */
int IRPresub1__vslot2(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  (**(code **)(*param_1 + 0x14))(param_1,param_2);
  return ((int (*)())IRStartCallRoutine__vslot2)(param_1,param_2);
}

/* FUN_00106cf8 @ 0x106cf8 (772 bytes) */
int FUN_00106cf8(inst, param_2)
  int *inst;
  undefined4 param_2;
{
  int *operandVReg;
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 operandVReg2;
  
  if ((inst[5] & 0x200U) != 0) {
    operandVReg = (int *)IRInst__getOperandSource(inst,inst[0x21]);
    iVar2 = (**(code **)(*operandVReg + 0x50))(operandVReg);
    if (iVar2 == 0) {
      if (operandVReg[0x20] == 0) {
        return 0;
      }
      iVar2 = FUN_00126760(operandVReg[0x26]);
      if (iVar2 == 0) {
        return 0;
      }
      if ((operandVReg[5] & 2U) != 0) {
        return 0;
      }
      iVar2 = (**(code **)(*operandVReg + 0x50))(operandVReg);
      if (iVar2 != 0) {
        return 0;
      }
      iVar2 = thunk_FUN_00134de8(param_2,operandVReg);
      iVar3 = thunk_FUN_00134de8(param_2,inst);
      if (iVar2 != iVar3) {
        return 0;
      }
    }
  }
  iVar2 = (**(code **)(*inst + 100))(inst);
  if (iVar2 != 0) {
    for (iVar2 = 1; iVar3 = (**(code **)(*inst + 0x14))(inst), iVar2 <= iVar3;
        iVar2 = iVar2 + 1) {
      if ((inst[iVar2 * 6 + 0x28] & 1U) != 0) {
        return 0;
      }
      if ((inst[iVar2 * 6 + 0x28] & 2U) != 0) {
        return 0;
      }
      iVar3 = FUN_000f31e8(inst,iVar2);
      if (iVar3 == 0) {
        return 0;
      }
    }
    if ((inst[0x48] == 0) && (inst[0x49] == 0)) {
      if ((inst[0x20] != 0) &&
         (((iVar2 = FUN_00126760(inst[0x26]), iVar2 != 0 && ((inst[5] & 2U) == 0)) &&
          (iVar2 = (**(code **)(*inst + 0x50))(inst), iVar2 == 0)))) {
        iVar2 = 4;
        piVar1 = inst;
        do {
          if ((uint)(*(byte *)(piVar1 + 0x27) - 2) < 2) {
            return 0;
          }
          piVar1 = (int *)((int)piVar1 + 1);
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
      IRInst__getOperandRecord(inst,0);
      iVar2 = ((int (*)())FUN_00105dbc)(inst,0);
      if ((((iVar2 == 0) && ((inst[5] & 2U) == 0)) &&
          ((inst[0x20] != 0 &&
           ((iVar2 = FUN_00126760(inst[0x26]), iVar2 != 0 && ((inst[5] & 2U) == 0)))))) &&
         (iVar2 = (**(code **)(*inst + 0x50))(inst), iVar2 == 0)) {
        operandVReg = (int *)IRInst__getOperandSource(inst,1);
        iVar2 = (**(code **)(*operandVReg + 0x50))(operandVReg);
        if (iVar2 != 0) {
          return 1;
        }
        operandVReg = (int *)IRInst__getOperandSource(inst,1);
        if ((((operandVReg[0x20] != 0) && (iVar2 = FUN_00126760(operandVReg[0x26]), iVar2 != 0)) &&
            ((operandVReg[5] & 2U) == 0)) && (iVar2 = (**(code **)(*operandVReg + 0x50))(operandVReg), iVar2 == 0))
        {
          operandVReg2 = IRInst__getOperandSource(inst,1);
          iVar2 = thunk_FUN_00134de8(param_2,operandVReg2);
          iVar3 = thunk_FUN_00134de8(param_2,inst);
          if (iVar2 == iVar3) {
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

/* FUN_00106ffc @ 0x106ffc (80 bytes) */
int FUN_00106ffc(inst, param_2, compiler)
  undefined4 *inst;
  undefined4 param_2;
  undefined4 compiler;
{
  undefined *puVar1;
  
  IRInst__ctor_1051b0(inst,param_2,compiler);
  puVar1 = PTR_DAT_001e8c64;
  inst[0x20] = 1;
  inst[0x21] = 1;
  *inst = puVar1 + 8;
  return;
}

/* FUN_0010704c @ 0x10704c (80 bytes) */
int FUN_0010704c(inst, param_2, compiler)
  undefined4 *inst;
  undefined4 param_2;
  undefined4 compiler;
{
  undefined *puVar1;
  
  IRInst__ctor_1051b0(inst,param_2,compiler);
  puVar1 = PTR_DAT_001e8c64;
  inst[0x20] = 1;
  inst[0x21] = 1;
  *inst = puVar1 + 8;
  return;
}

/* FUN_0010709c @ 0x10709c (92 bytes) */
int FUN_0010709c(inst, param_2, compiler)
  undefined4 *inst;
  undefined4 param_2;
  undefined4 compiler;
{
  undefined *puVar1;
  
  IRInst__ctor_1051b0(inst,param_2,compiler);
  puVar1 = PTR_DAT_001e8b50;
  inst[5] = inst[5] | 0x18000;
  *inst = puVar1 + 8;
  inst[0x20] = 0;
  return;
}

/* FUN_001070f8 @ 0x1070f8 (92 bytes) */
int FUN_001070f8(inst, param_2, compiler)
  undefined4 *inst;
  undefined4 param_2;
  undefined4 compiler;
{
  undefined *puVar1;
  
  IRInst__ctor_1051b0(inst,param_2,compiler);
  puVar1 = PTR_DAT_001e8b50;
  inst[5] = inst[5] | 0x18000;
  *inst = puVar1 + 8;
  inst[0x20] = 0;
  return;
}

/* FUN_00107154 @ 0x107154 (84 bytes) */
int FUN_00107154(inst, param_2, compiler)
  undefined4 *inst;
  undefined4 param_2;
  undefined4 compiler;
{
  undefined *puVar1;
  
  IRInst__ctor_1051b0(inst,param_2,compiler);
  puVar1 = PTR_DAT_001e8c58;
  inst[0x4b] = 0;
  inst[0x20] = 1;
  *inst = puVar1 + 8;
  return;
}

/* FUN_001071a8 @ 0x1071a8 (84 bytes) */
int FUN_001071a8(inst, param_2, compiler)
  undefined4 *inst;
  undefined4 param_2;
  undefined4 compiler;
{
  undefined *puVar1;
  
  IRInst__ctor_1051b0(inst,param_2,compiler);
  puVar1 = PTR_DAT_001e8c58;
  inst[0x4b] = 0;
  inst[0x20] = 1;
  *inst = puVar1 + 8;
  return;
}

/* FUN_001071fc @ 0x1071fc (84 bytes) */
int FUN_001071fc(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined *puVar1;
  
  ((int (*)())FUN_0010704c)(param_1,param_2,param_3);
  puVar1 = PTR_DAT_001e8c10;
  param_1[0x4b] = 0;
  param_1[0x21] = 2;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_00107250 @ 0x107250 (128 bytes) */
int FUN_00107250(this, param_2, param_3, param_4, param_5)
  undefined4 *this;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  undefined4 uVar1;
  undefined *puVar2;
  
  ((int (*)())FUN_0010704c)(this,param_2,param_3);
  uVar1 = DAT_001af9bc;
  puVar2 = PTR_DAT_001e8c08 + 8;
  this[0x4b] = param_5;
  *this = puVar2;
  this[0x4f] = 0;
  this[0x50] = uVar1;
  this[0x4c] = param_4;
  this[0x4d] = 0;
  this[0x4e] = 0;
  return FUN_00104330(this);
}

/* FUN_001072d0 @ 0x1072d0 (128 bytes) */
int FUN_001072d0(this, param_2, compiler, param_4, param_5)
  undefined4 *this;
  undefined4 param_2;
  undefined4 compiler;
  undefined4 param_4;
  undefined4 param_5;
{
  undefined4 uVar1;
  undefined *puVar2;
  
  ((int (*)())FUN_0010704c)(this,param_2,compiler);
  uVar1 = DAT_001af9bc;
  puVar2 = PTR_DAT_001e8c08 + 8;
  this[0x4b] = param_5;
  *this = puVar2;
  this[0x4f] = 0;
  this[0x50] = uVar1;
  this[0x4c] = param_4;
  this[0x4d] = 0;
  this[0x4e] = 0;
  return FUN_00104330(this);
}

/* FUN_00107350 @ 0x107350 (84 bytes) */
int FUN_00107350(param_1, compiler, param_3, param_4)
  undefined4 param_1;
  int compiler;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + 0x374);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  *allocation = arena;
  ((int (*)())FUN_001072d0)(allocation + 1,param_1,compiler,param_3,param_4);
  return allocation + 1;
}

/* IRVertexFetch__ctor_1073dc @ 0x1073dc (68 bytes) */
int IRVertexFetch__ctor_1073dc(this, param_2, param_3)
  undefined4 *this;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())FUN_0010704c)(this,param_2,param_3);
  *this = PTR_DAT_001e8c08 + 8;
  return;
}

/* IRVertexFetch__ctor_107420 @ 0x107420 (68 bytes) */
int IRVertexFetch__ctor_107420(this, param_2, compiler)
  undefined4 *this;
  undefined4 param_2;
  undefined4 compiler;
{
  ((int (*)())FUN_0010704c)(this,param_2,compiler);
  *this = PTR_DAT_001e8c08 + 8;
  return;
}

/* FUN_00107464 @ 0x107464 (68 bytes) */
int FUN_00107464(param_1, compiler)
  undefined4 param_1;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + 0x374);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  *allocation = arena;
  ((int (*)())IRVertexFetch__ctor_107420)(allocation + 1,param_1,compiler);
  return allocation + 1;
}

/* FUN_001074e0 @ 0x1074e0 (232 bytes) */
int FUN_001074e0(param_1, param_2, compiler)
  undefined4 *param_1;
  int param_2;
  int compiler;
{
  undefined4 uVar1;
  undefined *puVar2;
  undefined2 *puVar3;
  
  ((int (*)())FUN_0010704c)(param_1,param_2,compiler);
  puVar2 = PTR_DAT_001e8c0c;
  param_1[0x4c] = 0;
  param_1[0x4d] = 0xffffffff;
  *param_1 = puVar2 + 8;
  param_1[0x26] = 0;
  param_1[0x2c] = 0;
  param_1[0x42] = 0;
  param_1[0x41] = 0;
  puVar3 = (undefined2 *)Arena__alloc(*(undefined4 *)(compiler + 0x374),0x24);
  _memset(puVar3,0,0x24);
  uVar1 = DAT_001af9bc;
  puVar3[4] = 7;
  puVar3[6] = 3;
  puVar3[9] = 1;
  puVar3[10] = 0;
  *puVar3 = 3;
  puVar3[1] = 3;
  puVar3[2] = 3;
  puVar3[3] = 7;
  puVar3[5] = 3;
  puVar3[7] = 1;
  puVar3[8] = 0;
  puVar3[0xb] = 0;
  puVar3[0xc] = 0;
  puVar3[0xd] = 0;
  puVar3[0xe] = 0;
  param_1[0x4f] = puVar3;
  param_1[0x4e] = 0xffffffff;
  param_1[0x50] = uVar1;
  if (param_2 == 0x77) {
    param_1[5] = param_1[5] | 8;
  }
  return;
}

/* FUN_00107600 @ 0x107600 (76 bytes) */
int FUN_00107600(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined *puVar1;
  
  ((int (*)())FUN_001074e0)(param_1,param_2,param_3);
  puVar1 = PTR_DAT_001e8c48;
  param_1[0x21] = 3;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_0010764c @ 0x10764c (232 bytes) */
int FUN_0010764c(param_1, param_2, compiler)
  undefined4 *param_1;
  int param_2;
  int compiler;
{
  undefined4 uVar1;
  undefined *puVar2;
  undefined2 *puVar3;
  
  ((int (*)())FUN_0010704c)(param_1,param_2,compiler);
  puVar2 = PTR_DAT_001e8c0c;
  param_1[0x4c] = 0;
  param_1[0x4d] = 0xffffffff;
  *param_1 = puVar2 + 8;
  param_1[0x26] = 0;
  param_1[0x2c] = 0;
  param_1[0x42] = 0;
  param_1[0x41] = 0;
  puVar3 = (undefined2 *)Arena__alloc(*(undefined4 *)(compiler + 0x374),0x24);
  _memset(puVar3,0,0x24);
  uVar1 = DAT_001af9bc;
  puVar3[4] = 7;
  puVar3[6] = 3;
  puVar3[9] = 1;
  puVar3[10] = 0;
  *puVar3 = 3;
  puVar3[1] = 3;
  puVar3[2] = 3;
  puVar3[3] = 7;
  puVar3[5] = 3;
  puVar3[7] = 1;
  puVar3[8] = 0;
  puVar3[0xb] = 0;
  puVar3[0xc] = 0;
  puVar3[0xd] = 0;
  puVar3[0xe] = 0;
  param_1[0x4f] = puVar3;
  param_1[0x4e] = 0xffffffff;
  param_1[0x50] = uVar1;
  if (param_2 == 0x77) {
    param_1[5] = param_1[5] | 8;
  }
  return;
}

/* FUN_0010776c @ 0x10776c (68 bytes) */
int FUN_0010776c(param_1, compiler)
  undefined4 param_1;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + 0x374);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  *allocation = arena;
  ((int (*)())FUN_0010764c)(allocation + 1,param_1,compiler);
  return allocation + 1;
}

/* FUN_001077e8 @ 0x1077e8 (68 bytes) */
int FUN_001077e8(param_1, compiler)
  undefined4 param_1;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + 0x374);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  *allocation = arena;
  ((int (*)())FUN_0010764c)(allocation + 1,param_1,compiler);
  return allocation + 1;
}

/* FUN_00107864 @ 0x107864 (76 bytes) */
int FUN_00107864(param_1, param_2, compiler)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 compiler;
{
  undefined *puVar1;
  
  ((int (*)())FUN_001074e0)(param_1,param_2,compiler);
  puVar1 = PTR_DAT_001e8c48;
  param_1[0x21] = 3;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_001078b0 @ 0x1078b0 (68 bytes) */
int FUN_001078b0(param_1, compiler)
  undefined4 param_1;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + 0x374);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  *allocation = arena;
  ((int (*)())FUN_00107864)(allocation + 1,param_1,compiler);
  return allocation + 1;
}

/* FUN_0010792c @ 0x10792c (84 bytes) */
int FUN_0010792c(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined *puVar1;
  
  ((int (*)())FUN_0010704c)(param_1,param_2,param_3);
  puVar1 = PTR_DAT_001e8c50;
  param_1[0x4b] = 0;
  param_1[0x21] = 2;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_00107980 @ 0x107980 (84 bytes) */
int FUN_00107980(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined *puVar1;
  
  ((int (*)())FUN_0010704c)(param_1,param_2,param_3);
  puVar1 = PTR_DAT_001e8c50;
  param_1[0x4b] = 0;
  param_1[0x21] = 2;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_001079d4 @ 0x1079d4 (84 bytes) */
int FUN_001079d4(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined *puVar1;
  
  ((int (*)())FUN_0010704c)(param_1,param_2,param_3);
  puVar1 = PTR_DAT_001e8c10;
  param_1[0x4b] = 0;
  param_1[0x21] = 2;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_00107a28 @ 0x107a28 (76 bytes) */
int FUN_00107a28(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined *puVar1;
  
  ((int (*)())FUN_001071a8)(param_1,param_2,param_3);
  puVar1 = PTR_DAT_001e8c2c;
  param_1[0x21] = 0;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_00107a74 @ 0x107a74 (92 bytes) */
int FUN_00107a74(this, param_2, compiler)
  undefined4 *this;
  undefined4 param_2;
  undefined4 compiler;
{
  undefined4 uVar1;
  undefined *puVar2;
  
  ((int (*)())FUN_00107a28)(this,param_2,compiler);
  uVar1 = DAT_001af9c8;
  puVar2 = PTR_DAT_001e8be8 + 8;
  this[0x20] = 0;
  *this = puVar2;
  this[0x27] = uVar1;
  this[0x21] = 0;
  return;
}

/* FUN_00107ad0 @ 0x107ad0 (68 bytes) */
int FUN_00107ad0(param_1, compiler)
  undefined4 param_1;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + 0x374);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  *allocation = arena;
  ((int (*)())FUN_00107a74)(allocation + 1,param_1,compiler);
  return allocation + 1;
}

/* FUN_00107b4c @ 0x107b4c (92 bytes) */
int FUN_00107b4c(this, param_2, param_3)
  undefined4 *this;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 uVar1;
  undefined *puVar2;
  
  ((int (*)())FUN_00107a28)(this,param_2,param_3);
  uVar1 = DAT_001af9c8;
  puVar2 = PTR_DAT_001e8be8 + 8;
  this[0x20] = 0;
  *this = puVar2;
  this[0x27] = uVar1;
  this[0x21] = 0;
  return;
}

/* FUN_00107ba8 @ 0x107ba8 (76 bytes) */
int FUN_00107ba8(param_1, param_2, compiler)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 compiler;
{
  undefined *puVar1;
  
  ((int (*)())FUN_001071a8)(param_1,param_2,compiler);
  puVar1 = PTR_DAT_001e8c2c;
  param_1[0x21] = 0;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_00107bf4 @ 0x107bf4 (68 bytes) */
int FUN_00107bf4(param_1, compiler)
  undefined4 param_1;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + 0x374);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  *allocation = arena;
  ((int (*)())FUN_00107ba8)(allocation + 1,param_1,compiler);
  return allocation + 1;
}

/* FUN_00107c70 @ 0x107c70 (68 bytes) */
int FUN_00107c70(param_1, compiler)
  undefined4 param_1;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + 0x374);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  *allocation = arena;
  ((int (*)())FUN_00107ba8)(allocation + 1,param_1,compiler);
  return allocation + 1;
}

/* FUN_00107cec @ 0x107cec (76 bytes) */
int FUN_00107cec(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined *puVar1;
  
  ((int (*)())FUN_001071a8)(param_1,param_2,param_3);
  puVar1 = PTR_DAT_001e8c68;
  param_1[0x21] = 1;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_00107d38 @ 0x107d38 (112 bytes) */
int FUN_00107d38(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  bool bVar1;
  undefined *puVar2;
  int iVar3;
  
  ((int (*)())FUN_00107cec)(param_1,param_2,param_3);
  puVar2 = PTR_DAT_001e8bf0;
  param_1[0x20] = 1;
  *param_1 = puVar2 + 8;
  iVar3 = 0;
  do {
    bVar1 = iVar3 != 1;
    param_1[0x25] = 0xffffffff;
    param_1[0x26] = 0;
    iVar3 = iVar3 + 1;
    param_1 = param_1 + 6;
  } while (bVar1);
  return;
}

/* FUN_00107da8 @ 0x107da8 (76 bytes) */
int FUN_00107da8(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined *puVar1;
  
  ((int (*)())FUN_001071a8)(param_1,param_2,param_3);
  puVar1 = PTR_DAT_001e8c68;
  param_1[0x21] = 1;
  *param_1 = puVar1 + 8;
  return;
}


/* issue: auto-generated aliases bridging data.s/code.s references (written
 * without a leading underscore, matching the raw stock-binary symbol name)
 * against the real compiled C symbols (gcc adds one underscore automatically).
 * Needed because ld64 (required for this PPC binary's size - stock ld breaks on
 * large PPC links) does not silently reconcile this the way stock ld did. */
asm(".globl FUN_00105a44");
asm(".set FUN_00105a44, _IRStartCallRoutine__vslot4");
asm(".globl FUN_00105b7c");
asm(".set FUN_00105b7c, _IRStartCallRoutine__vslot3");
asm(".globl FUN_00105e9c");
asm(".set FUN_00105e9c, _FUN_00105e9c");
asm(".globl FUN_0010647c");
asm(".set FUN_0010647c, _IRStartCallRoutine__vslot2");
asm(".globl FUN_001066e8");
asm(".set FUN_001066e8, _IRProjection__vslot2");
asm(".globl FUN_0010673c");
asm(".set FUN_0010673c, _IRPresub2__vslot2");
asm(".globl FUN_00106780");
asm(".set FUN_00106780, _IRPhiNode__vslot2");
asm(".globl FUN_001069e8");
asm(".set FUN_001069e8, _FUN_001069e8");
asm(".globl FUN_00106ba0");
asm(".set FUN_00106ba0, _IRMix__vslot2");
asm(".globl FUN_00106cb4");
asm(".set FUN_00106cb4, _IRPresub1__vslot2");
asm(".globl FUN_00107464");
asm(".set FUN_00107464, _FUN_00107464");
asm(".globl FUN_0010776c");
asm(".set FUN_0010776c, _FUN_0010776c");
asm(".globl FUN_001077e8");
asm(".set FUN_001077e8, _FUN_001077e8");
asm(".globl FUN_001078b0");
asm(".set FUN_001078b0, _FUN_001078b0");
asm(".globl FUN_00107ad0");
asm(".set FUN_00107ad0, _FUN_00107ad0");
asm(".globl FUN_00107c70");
asm(".set FUN_00107c70, _FUN_00107c70");
