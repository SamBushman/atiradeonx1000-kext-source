#include "decls.h"

/* KhanPs__vslot76_getBindingLimit @ 0x127ee4 (64 bytes) */
int KhanPs__vslot76_getBindingLimit(this, outLimit)
  int *this;
  undefined4 *outLimit;
{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*this + 0x138))(this,0);
  *outLimit = uVar1;
  return;
}

/* KhanPs__createSchedModels @ 0x127f24 (180 bytes) */
int KhanPs__createSchedModels(this, param_2)
  int this;
  undefined4 param_2;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined *puVar3;
  
  puVar2 = (undefined4 *)FUN_000e1564(param_2,0x6c);
  puVar1 = PTR_DAT_001e90f4;
  puVar3 = PTR_DAT_001e90fc + 8;
  puVar2[2] = param_2;
  *puVar2 = puVar3;
  puVar2[1] = 0;
  *puVar2 = puVar1 + 8;
  PackState__reset(puVar2 + 10);
  R520SchedModel__vslot2_reset(puVar2);
  puVar2[0x1a] = 0;
  *(undefined4 **)(this + 0x60) = puVar2;
  puVar2 = (undefined4 *)FUN_000e1564(param_2,0xc);
  puVar1 = PTR_DAT_001e9100;
  puVar2[1] = 1;
  puVar2[2] = 0;
  *puVar2 = puVar1 + 8;
  *(undefined4 **)(this + 100) = puVar2;
  return;
}

/* FUN_00127fd8 @ 0x127fd8 (32 bytes) */
int FUN_00127fd8(param_1)
  undefined4 param_1;
{
  int extraout_r3;
  int unaff_r27;
  int *unaff_r30;
  
  *unaff_r30 = *(int *)(((unsigned char *)0x000011d0U) + unaff_r27) + 8;
  __Unwind_Resume(param_1);
  *(undefined4 *)(*(int *)(extraout_r3 + 8) + 0x2c) = 0x100;
  return;
}

/* KhanPs__vslot62_lookupTableEntry @ 0x127ff8 (36 bytes) */
int KhanPs__vslot62_lookupTableEntry(this, param_2)
  undefined4 this;
  int param_2;
{
  return *(undefined4 *)(PTR_PTR_001e910c + param_2 * 4);
}

/* KhanPs__vslot90_isProgramKind1 @ 0x12801c (20 bytes) */
int KhanPs__vslot90_isProgramKind1(this, param_2, param_3)
  undefined4 this;
  undefined4 param_2;
  int param_3;
{
  return *(int *)(param_3 + 0x138) == 1;
}

/* KhanPs__getOpcodeTraits @ 0x128030 (28 bytes) */
int KhanPs__getOpcodeTraits()
{
  return &DAT_001dca64;
}

/* KhanPs__vslot35_publishLimitsAndBindingTables @ 0x12804c (356 bytes) */
int KhanPs__vslot35_publishLimitsAndBindingTables(this, compiler, limitsBlob)
  int this;
  int compiler;
  undefined4 limitsBlob;
{
  undefined1 *puVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  int iVar11;
  
  _memcpy(compiler + 0x64c,limitsBlob,0x963c);
  iVar5 = 0;
  *(undefined4 *)(compiler + 0x104) = *(undefined4 *)(((unsigned char *)0x0000172c) + this);
  iVar6 = this + 0x80;
  iVar8 = compiler + 0x100;
  iVar7 = this;
  do {
    puVar9 = (undefined1 *)(iVar6 + 0x14);
    puVar10 = (undefined1 *)(iVar8 + 0xc);
    *(char *)(iVar8 + 8) = (char)*(undefined4 *)(iVar7 + 0x68);
    iVar11 = 4;
    *(char *)(iVar8 + 9) = (char)*(undefined4 *)(iVar7 + 0x6c);
    *(char *)(iVar8 + 10) = (char)*(undefined4 *)(iVar7 + 0x70);
    uVar4 = *(uint *)(iVar8 + 8);
    uVar3 = (*(uint *)(iVar7 + 0x78) & 0xf) << 4;
    *(uint *)(iVar8 + 8) = uVar3 | uVar4 & 0xffffff0f;
    *(uint *)(iVar8 + 8) = *(uint *)(iVar7 + 0x7c) & 1 | uVar3 | uVar4 & 0xffffff0e;
    do {
      *puVar10 = *puVar9;
      puVar1 = puVar9 + 4;
      puVar9 = puVar9 + 1;
      puVar10[4] = *puVar1;
      puVar10 = puVar10 + 1;
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
    bVar2 = iVar5 != 0x3f;
    iVar8 = iVar8 + 0xc;
    iVar6 = iVar6 + 0x34;
    iVar7 = iVar7 + 0x34;
    iVar5 = iVar5 + 1;
  } while (bVar2);
  iVar7 = compiler + 0x400;
  iVar5 = 0;
  *(undefined4 *)(compiler + 0x408) = *(undefined4 *)(((unsigned char *)0x00001728) + this);
  iVar6 = this + 0xd80;
  do {
    puVar9 = (undefined1 *)(iVar6 + 0x14);
    puVar10 = (undefined1 *)(iVar7 + 0x10);
    *(char *)(iVar7 + 0xc) = (char)*(undefined4 *)(this + 0xd68);
    iVar8 = 4;
    *(char *)(iVar7 + 0xd) = (char)*(undefined4 *)(this + 0xd6c);
    *(char *)(iVar7 + 0xe) = (char)*(undefined4 *)(this + 0xd70);
    uVar4 = *(uint *)(iVar7 + 0xc);
    uVar3 = (*(uint *)(this + 0xd78) & 0xf) << 4;
    *(uint *)(iVar7 + 0xc) = uVar3 | uVar4 & 0xffffff0f;
    *(uint *)(iVar7 + 0xc) = *(uint *)(this + 0xd7c) & 1 | uVar3 | uVar4 & 0xffffff0e;
    do {
      *puVar10 = *puVar9;
      puVar1 = puVar9 + 4;
      puVar9 = puVar9 + 1;
      puVar10[4] = *puVar1;
      puVar10 = puVar10 + 1;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
    bVar2 = iVar5 != 0x2f;
    iVar7 = iVar7 + 0xc;
    iVar6 = iVar6 + 0x34;
    this = this + 0x34;
    iVar5 = iVar5 + 1;
  } while (bVar2);
  return 0;
}

/* KhanPs__vslot8_failNotSupported @ 0x1281b0 (56 bytes) */
int KhanPs__vslot8_failNotSupported(this, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 this;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  int param_7;
{
  if (*(int *)(param_7 + 0x6c4) != 0) {
    Compiler__fail(param_7,0xf);
  }
  return 0;
}

/* KhanPs__vslot58_matchImmediateConstantCode @ 0x1281f0 (344 bytes) */
int KhanPs__vslot58_matchImmediateConstantCode(this, constants, outSelectCode, laneSwizzle)
  undefined4 this;
  float *constants;
  undefined4 *outSelectCode;
  undefined4 laneSwizzle;
{
  unsigned int ghidra_home[8] = { this, constants, outSelectCode, laneSwizzle, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  float fVar1;
  float fVar2;
  bool bVar3;
  float *pfVar4;
  undefined4 *puVar5;
  char *pcVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 12)) = laneSwizzle;
  bVar3 = true;
  *outSelectCode = 0xffffffff;
  iVar8 = 4;
  pcVar6 = &(*(unsigned int *)((unsigned char *)ghidra_home + 12));
  pfVar4 = constants;
  fVar1 = FLOAT_001aa0d4;
  do {
    if (*pcVar6 != '\x04') {
      if (bVar3) {
        fVar1 = *pfVar4;
        bVar3 = false;
      }
      else if (*pfVar4 != fVar1) {
        return 0;
      }
    }
    pcVar6 = pcVar6 + 1;
    pfVar4 = pfVar4 + 1;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  iVar8 = 4;
  fVar2 = FLOAT_001aa0d4;
  do {
    fVar2 = fVar2 + fVar1;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  (*(char *)((unsigned char *)ghidra_home + 12)) = (char)((uint)laneSwizzle >> 0x18);
  (*(char *)((unsigned char *)ghidra_home + 13)) = (char)((uint)laneSwizzle >> 0x10);
  (*(char *)((unsigned char *)ghidra_home + 14)) = (char)((uint)laneSwizzle >> 8);
  (*(char *)((unsigned char *)ghidra_home + 15)) = (char)laneSwizzle;
  puVar5 = &DAT_001aff0c;
  while( true ) {
    uVar7 = *puVar5;
    if ((((GH_U2F((unsigned int)(puVar5[1])) == fVar2) &&
         (((*(char *)((unsigned char *)ghidra_home + 12)) == '\x04' || (fVar1 == GH_U2F((unsigned int)(puVar5[-4])))))) &&
        (((*(char *)((unsigned char *)ghidra_home + 13)) == '\x04' || (fVar1 == GH_U2F((unsigned int)(puVar5[-3])))))) &&
       ((((*(char *)((unsigned char *)ghidra_home + 14)) == '\x04' || (fVar1 == GH_U2F((unsigned int)(puVar5[-2])))) &&
        (((*(char *)((unsigned char *)ghidra_home + 15)) == '\x04' || (GH_U2F((unsigned int)(puVar5[-1])) == fVar1)))))) break;
    puVar5 = puVar5 + 6;
    if (puVar5 == (undefined4 *)&UNK_001aff54) {
      return 0;
    }
  }
  iVar8 = 0;
  iVar9 = 4;
  do {
    *(float *)((int)constants + iVar8) = fVar1;
    iVar8 = iVar8 + 4;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  *outSelectCode = uVar7;
  return 1;
}

/* KhanPs__vslot73_seedValueNumbers @ 0x128348 (84 bytes) */
int KhanPs__vslot73_seedValueNumbers(this, param_2)
  undefined4 this;
  undefined4 param_2;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_001aff74;
  do {
    uVar1 = *puVar2;
    puVar2 = puVar2 + 1;
    Compiler__valueNumberForExpr(param_2,uVar1);
  } while (puVar2 != &DAT_001aff9c);
  return;
}

/* KhanPs__vslot74_seedConstantValueNumbers @ 0x12839c (128 bytes) */
int KhanPs__vslot74_seedConstantValueNumbers(this, param_2)
  undefined4 this;
  undefined4 param_2;
{
  undefined4 uVar1;
  int exprRecord;
  undefined4 *puVar3;
  
  puVar3 = &DAT_001aff68;
  do {
    exprRecord = Compiler__valueNumberForExpr(param_2,*puVar3);
    uVar1 = *puVar3;
    *(undefined4 *)(exprRecord + 0x1c) = 0;
    puVar3 = puVar3 + 1;
    *(undefined4 *)(exprRecord + 0x14) = uVar1;
    *(undefined1 *)(exprRecord + 8) = 1;
    *(undefined1 *)(exprRecord + 9) = 0;
    *(undefined4 *)(exprRecord + 0x18) = 0;
    FUN_0017629c(exprRecord,param_2);
  } while (puVar3 != &DAT_001aff74);
  return;
}

/* KhanPs__vslot85_findOrEncodeConstantVector @ 0x128430 (780 bytes) */
int KhanPs__vslot85_findOrEncodeConstantVector(this, program, constants, laneSwizzle)
  int *this;
  int program;
  dword *constants;
  int *laneSwizzle;
{
  float fVar1;
  bool bVar2;
  int *piVar3;
  uint *puVar4;
  char *pcVar5;
  int iVar6;
  dword *pdVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  uint local_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  float local_50;
  
  if (*laneSwizzle != 0x4040404) {
    pcVar5 = "In";
    fVar1 = 0.0;
    iVar9 = 4;
    bVar2 = true;
    iVar6 = 1;
    piVar3 = laneSwizzle;
    pdVar7 = constants;
    do {
      if (*(char *)piVar3 != '\x04') {
        if (bVar2) {
          fVar1 = (float)*pdVar7;
          bVar2 = false;
        }
        else if ((float)*pdVar7 != fVar1) {
          iVar6 = 0;
        }
      }
      piVar3 = (int *)((int)piVar3 + 1);
      pdVar7 = pdVar7 + 1;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    piVar3 = laneSwizzle;
    if (iVar6 == 0) {
      iVar9 = FUN_000f6a04(program,constants,*laneSwizzle);
    }
    else {
      pcVar5 = "";
      iVar9 = 4;
      puVar4 = &local_b8;
      do {
        *puVar4 = 0x7ffffffe;
        puVar4 = puVar4 + 1;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
      pdVar7 = ((unsigned char *)0x4);
      iVar9 = 0;
      iVar10 = 4;
      do {
        local_50 = fVar1;
        *(float *)(iVar9 + (int)&local_b8) = fVar1;
        iVar9 = iVar9 + 4;
        iVar10 = iVar10 + -1;
      } while (iVar10 != 0);
      iVar9 = FUN_000f6a04(program,&local_b8,0x10203);
    }
    if (iVar9 != 0) {
      return iVar9;
    }
    uVar8 = *(undefined4 *)(program + 0x3ac);
    iVar6 = FUN_000f5f94(uVar8,constants,laneSwizzle,piVar3,pcVar5,iVar6,pdVar7);
    if (iVar6 != 0) {
      return iVar6;
    }
    if ((((((*(uint *)(program + 0x30) & 0x100) != 0) && (GH_U2F((unsigned int)(*constants)) == 0.0)) &&
         (GH_U2F((unsigned int)(constants[1])) == 1.0)) && ((GH_U2F((unsigned int)(constants[2])) == 0.0 && (GH_U2F((unsigned int)(constants[3])) == 0.0))))
       && (*laneSwizzle == 0x10203)) {
      FUN_000f4a24(constants,&local_b8);
      iVar6 = FUN_000f5248(uVar8,local_b8,uStack_b4,uStack_b0,uStack_ac,local_a8,local_a4,local_a0);
      return iVar6;
    }
    iVar6 = FUN_000f57f0(uVar8,constants,laneSwizzle,piVar3);
    if ((iVar6 != 0) && (iVar9 = (**(code **)(*this + 0x100))(this,laneSwizzle), iVar9 != 0)) {
      return iVar6;
    }
  }
  return 0;
}

/* KhanPs__vslot59_tryEncodeSourceConstant @ 0x12873c (500 bytes) */
int KhanPs__vslot59_tryEncodeSourceConstant(this, inst, srcIndex, laneSwizzle, compiler)
  undefined4 this;
  int *inst;
  int srcIndex;
  uint laneSwizzle;
  int compiler;
{
  uint uVar1;
  float *pfVar2;
  int iVar3;
  float local_64 [4];
  float local_54 [9];
  float local_30;
  
  iVar3 = 4;
  pfVar2 = local_64;
  do {
    *pfVar2 = GH_U2F(0x7fff0000U);
    pfVar2 = pfVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  iVar3 = 4;
  pfVar2 = local_54;
  do {
    *pfVar2 = GH_U2F(0x7fff0000U);
    pfVar2 = pfVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  uVar1 = laneSwizzle << 0x18 | (laneSwizzle & 0xff00) << 8 | laneSwizzle >> 8 & 0xff00 | laneSwizzle >> 0x18;
  pfVar2 = (float *)&DAT_001aff08;
  while( true ) {
    local_64[1] = pfVar2[-2];
    local_64[0] = pfVar2[-3];
    local_64[2] = pfVar2[-1];
    local_54[0] = -local_64[0];
    local_64[3] = *pfVar2;
    local_54[1] = -local_64[1];
    local_54[2] = -local_64[2];
    local_54[3] = -local_64[3];
    local_30 = local_54[3];
    iVar3 = FUN_000f5c0c(inst,srcIndex,uVar1,local_64);
    if (iVar3 != 0) {
      ((void (*)())FUN_000f79c4)(inst,*(undefined4 *)(compiler + 0x6c4),srcIndex,(double)local_64[0],
                   (double)local_64[1],(double)local_64[2],(double)local_64[3]);
      return 1;
    }
    iVar3 = (**(code **)(*inst + 0x8c))(inst);
    if ((iVar3 != 0) && (iVar3 = FUN_000f5c0c(inst,srcIndex,uVar1,local_54), iVar3 != 0)) break;
    pfVar2 = pfVar2 + 6;
    if (pfVar2 == (float *)&DAT_001aff50) {
      return 0;
    }
  }
  ((void (*)())FUN_000f79c4)(inst,*(undefined4 *)(compiler + 0x6c4),srcIndex,(double)local_64[0],
               (double)local_64[1],(double)local_64[2],(double)local_64[3]);
  if ((inst[srcIndex * 6 + 0x28] & 2U) != 0) {
    return 1;
  }
  IROperand__setModifierBits(inst + srcIndex * 6 + 0x23,1,inst[srcIndex * 6 + 0x28] & 1U ^ 1);
  return 1;
}

/* KhanPs__vslot9_createCompareInst @ 0x128930 (420 bytes) */
int KhanPs__vslot9_createCompareInst(this, param_2, srcRegA, srcSwizzleA, srcRegB, srcSwizzleB, param_7, param_8, param_9, compiler)
  undefined4 this;
  int param_2;
  int srcRegA;
  int srcSwizzleA;
  int srcRegB;
  int srcSwizzleB;
  undefined4 param_7;
  int param_8;
  undefined4 param_9;
  int compiler;
{
  unsigned int ghidra_home[8] = { this, param_2, srcRegA, srcSwizzleA, srcRegB, srcSwizzleB, param_7, param_8 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  int callResult;
  undefined4 uVar2;
  int operandRecord;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  
  uVar5 = *(undefined4 *)(compiler + COMP_currentProgram);
  iVar4 = *(int *)(PTR_DAT_001e8b84 + param_2 * 4);
  (*(unsigned int *)((unsigned char *)ghidra_home + 24)) = param_7;
  callResult = IRInst__create(0x8b,compiler);
  uVar2 = FUN_000ec208(uVar5,srcSwizzleA);
  operandRecord = IRInst__getOperandRecord(callResult,1);
  *(undefined4 *)(operandRecord + 0xc) = uVar2;
  *(int *)(operandRecord + 8) = srcRegA;
  uVar2 = FUN_000ec208(uVar5,srcSwizzleB);
  operandRecord = IRInst__getOperandRecord(callResult,2);
  *(undefined4 *)(operandRecord + 0xc) = uVar2;
  *(int *)(operandRecord + 8) = srcRegB;
  FUN_000f8aa0(uVar5,&(*(unsigned int *)((unsigned char *)ghidra_home + 24)),**(undefined4 **)(param_8 + 0x6c),1,callResult);
  FUN_000f8aa0(uVar5,&(*(unsigned int *)((unsigned char *)ghidra_home + 24)),*(undefined4 *)(*(int *)(param_8 + 0x6c) + 4),2,callResult);
  if ((srcRegA == srcRegB) && (srcSwizzleA == srcSwizzleB)) {
    if ((*(uint *)(callResult + 0xb8) & 1) != (*(uint *)(callResult + 0xd0) & 1)) {
      if (((*(uint *)(callResult + 0xb8) & 2) == 0) && ((*(uint *)(callResult + 0xd0) & 2) == 0)) {
        operandRecord = IRInst__getOperandRecord(callResult,1);
        iVar6 = *(int *)(operandRecord + 0x10);
        operandRecord = IRInst__getOperandRecord(callResult,2);
        if (iVar6 == *(int *)(operandRecord + 0x10)) {
          if ((*(uint *)(callResult + 0xb8) & 1) != 0) {
            IROperand__setModifierBits(callResult + 0xa4,1,0);
            iVar4 = *(int *)(PTR_DAT_001e90f8 + iVar4 * 4);
          }
          FUN_000f7870(callResult,uVar5,2,0,0,0,0);
        }
      }
    }
  }
  *(int *)(callResult + 300) = iVar4;
  return callResult;
}

/* KhanPs__vslot5_materializeSpecialRegister @ 0x128ad4 (680 bytes) */
int KhanPs__vslot5_materializeSpecialRegister(this, param_2, compiler)
  undefined4 this;
  int param_2;
  int compiler;
{
  undefined4 uVar1;
  int callResult;
  undefined4 uVar3;
  int *newInst;
  int iVar5;
  int iVar6;
  int iVar7;
  uint loopIndex;
  int iVar9;
  double dVar10;
  
  if (param_2 == 1) {
    iVar6 = *(int *)(compiler + COMP_currentProgram);
    callResult = FUN_00127534(*(undefined4 *)(iVar6 + 0x3ac),0x1b,0,0);
    if (callResult != 0) {
      FUN_001041d0(*(undefined4 *)(callResult + 0x38),3,3,8,0);
      uVar3 = *(undefined4 *)(iVar6 + 0x3ac);
      iVar5 = *(int *)(compiler + 0x3ac) + -1;
      *(int *)(compiler + 0x3ac) = iVar5;
      iVar7 = 0;
      uVar3 = FUN_001275a0(uVar3,0,iVar5,0);
      for (loopIndex = 1; loopIndex <= *(uint *)(*(int *)(callResult + 0x14) + 4); loopIndex = loopIndex + 1) {
        iVar5 = *(int *)(iVar7 + *(int *)(*(int *)(callResult + 0x14) + 8));
        if (((*(uint *)(iVar5 + 0x14) & 1) != 0) && (iVar9 = 1, 0 < *(int *)(iVar5 + 0x84))) {
          do {
            if (*(int *)(iVar9 * 0x18 + iVar5 + 0x98) == 0x1b) {
              IRInst__setOperandRef(iVar5,iVar9,uVar3);
            }
            iVar9 = iVar9 + 1;
          } while (iVar9 <= *(int *)(iVar5 + 0x84));
        }
        iVar7 = iVar7 + 4;
      }
      iVar5 = FUN_000d9f3c(*(undefined4 *)(compiler + 0x398),0);
      if (iVar5 == 0) {
        newInst = (int *)IRInst__create(0x14,compiler);
        IRInst__setOperandRef(newInst,0,uVar3);
        IRInst__setOperandRef(newInst,1,callResult);
        uVar1 = DAT_001aff48;
        iVar5 = IRInst__getOperandRecord(newInst,1);
        dVar10 = (double)FLOAT_001aa108;
        *(undefined4 *)(iVar5 + 0x10) = uVar1;
        ((void (*)())FUN_000f79c4)(newInst,*(undefined4 *)(compiler + COMP_currentProgram),2,dVar10,dVar10,dVar10,dVar10);
        IROperand__setModifierBits(newInst + 0x2f,1,1);
        dVar10 = (double)FLOAT_001aa0e8;
        ((void (*)())FUN_000f79c4)(newInst,*(undefined4 *)(compiler + COMP_currentProgram),3,dVar10,dVar10,dVar10,dVar10);
        VReg__addUse(callResult,1,newInst);
        FUN_0012306c(uVar3,newInst);
        Block__appendInst(*(undefined4 *)(iVar6 + 0x3a0),newInst);
        (**(code **)(*newInst + 8))(newInst,compiler);
      }
      else {
        newInst = (int *)IRInst__create(0x31,compiler);
        IRInst__setOperandRef(newInst,0,uVar3);
        IRInst__setOperandRef(newInst,1,callResult);
        uVar1 = DAT_001affa4;
        iVar5 = IRInst__getOperandRecord(newInst,1);
        *(undefined4 *)(iVar5 + 0x10) = uVar1;
        VReg__addUse(callResult,1,newInst);
        FUN_0012306c(uVar3,newInst);
        Block__appendInst(*(undefined4 *)(iVar6 + 0x3a0),newInst);
        (**(code **)(*newInst + 8))(newInst,compiler);
      }
    }
  }
  return;
}

/* KhanPs__vslot75_registerConstantMultiples @ 0x128d7c (596 bytes) */
int KhanPs__vslot75_registerConstantMultiples(this, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 this;
  float *param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  int exprRecord2;
  bool bVar1;
  float fVar2;
  byte bVar3;
  int iVar4;
  int exprRecord;
  float *pfVar6;
  
  if (*(char *)(param_2 + 2) == '\0') {
    return;
  }
  bVar3 = *(byte *)((int)param_2 + 9);
  if ((bVar3 & 1) != 0) {
    return;
  }
  if ((bVar3 & 2) != 0) {
    return;
  }
  if ((bVar3 & 4) != 0) {
    return;
  }
  if ((bVar3 & 8) != 0) {
    return;
  }
  exprRecord2 = Compiler__valueNumberForExpr(param_3,GH_F2U(-param_2[5]));
  if (*(char *)(exprRecord2 + 8) == '\0') {
    bVar3 = *(byte *)(exprRecord2 + 9);
  }
  else {
    bVar3 = *(byte *)(exprRecord2 + 9);
    if (((((bVar3 & 1) == 0) && ((bVar3 & 2) == 0)) && ((bVar3 & 4) == 0)) && ((bVar3 & 8) == 0))
    goto LAB_00128e28;
  }
  if (((bVar3 & 1) == 0) || ((bVar3 & 2) != 0)) {
    *(undefined4 *)(exprRecord2 + 0x20) = 0x31;
    FUN_00176280(exprRecord2,param_2);
    fVar2 = param_2[5];
    *(undefined1 *)(exprRecord2 + 9) = 1;
    *(float *)(exprRecord2 + 0x14) = fVar2;
    *(undefined4 *)(exprRecord2 + 0x1c) = 0;
    *(undefined4 *)(exprRecord2 + 0x18) = 1;
  }
LAB_00128e28:
  iVar4 = -3;
  pfVar6 = (float *)&DAT_001aff4c;
  do {
    exprRecord = Compiler__valueNumberForExpr(param_3,GH_F2U(*param_2 * *pfVar6));
    if (*(char *)(exprRecord + 8) == '\0') {
      bVar3 = *(byte *)(exprRecord + 9);
LAB_00128e98:
      if ((((bVar3 & 1) == 0) || ((bVar3 & 2) != 0)) && (((bVar3 & 2) == 0 || ((bVar3 & 1) != 0))))
      {
        *(undefined4 *)(exprRecord + 0x20) = 0x31;
        FUN_00176280(exprRecord,param_2);
        fVar2 = param_2[5];
        *(int *)(exprRecord + 0x1c) = iVar4;
        *(undefined1 *)(exprRecord + 9) = 2;
        *(float *)(exprRecord + 0x14) = fVar2;
        *(undefined4 *)(exprRecord + 0x18) = 0;
      }
    }
    else {
      bVar3 = *(byte *)(exprRecord + 9);
      if ((((bVar3 & 1) != 0) || ((bVar3 & 2) != 0)) || (((bVar3 & 4) != 0 || ((bVar3 & 8) != 0))))
      goto LAB_00128e98;
    }
    bVar1 = iVar4 == 3;
    pfVar6 = pfVar6 + 1;
    iVar4 = iVar4 + 1;
    if (bVar1) {
      pfVar6 = (float *)&DAT_001aff4c;
      iVar4 = -3;
      do {
        exprRecord = Compiler__valueNumberForExpr(param_3,GH_F2U(-*param_2 * *pfVar6));
        if (*(char *)(exprRecord + 8) == '\0') {
          *(undefined4 *)(exprRecord + 0x20) = 0x31;
          FUN_00176280(exprRecord,param_2);
          fVar2 = param_2[5];
          *(undefined1 *)(exprRecord + 9) = 3;
          *(float *)(exprRecord + 0x14) = fVar2;
          *(undefined4 *)(exprRecord + 0x18) = 1;
          *(int *)(exprRecord + 0x1c) = iVar4;
        }
        bVar1 = iVar4 != 3;
        pfVar6 = pfVar6 + 1;
        iVar4 = iVar4 + 1;
      } while (bVar1);
      return;
    }
  } while( true );
}

/* KhanPs__ctor_128fd0 @ 0x128fd0 (312 bytes) */
int KhanPs__ctor_128fd0(this, param_2, param_3)
  undefined4 *this;
  undefined4 param_2;
  int param_3;
{
  undefined *puVar1;
  
  HwLimits__dtor_10dad8(this);
  this[7] = 0;
  puVar1 = PTR_DAT_001e9104;
  this[0xe] = 9;
  this[0x10] = 0x60;
  this[1] = puVar1;
  this[0x15] = 4;
  *this = &PTR_FUN_001ead88;
  this[8] = 0x7fffffff;
  this[0xf] = 0x10;
  this[0x14] = 0x20;
  this[0x16] = 0xfffffffd;
  this[0x17] = 3;
  this[0xb] = 0x20;
  this[10] = 0x10;
  FUN_0010dc20(this);
  BitSet__setBit(this,0x30);
  BitSet__setBit(this,0x31);
  BitSet__setBit(this,0x36);
  BitSet__setBit(this,0x39);
  BitSet__setBit(this,0x3b);
  BitSet__setBit(this,0x3c);
  BitSet__setBit(this,0x40);
  BitSet__setBit(this,0x41);
  BitSet__setBit(this,0x42);
  this[2] = this[2] | 0x20000;
  ((int (*)())KhanPs__vslot96_installHardwareTables)(this);
  if (param_3 != 0) {
    ((int (*)())KhanPs__createSchedModels)(this,param_2);
  }
  return;
}

/* KhanPs__ctor_129130 @ 0x129130 (312 bytes) */
int KhanPs__ctor_129130(this, param_2, param_3)
  undefined4 *this;
  undefined4 param_2;
  int param_3;
{
  undefined *puVar1;
  
  HwLimits__dtor_10dad8(this);
  this[7] = 0;
  puVar1 = PTR_DAT_001e9104;
  this[0xe] = 9;
  this[0x10] = 0x60;
  this[1] = puVar1;
  this[0x15] = 4;
  *this = &PTR_FUN_001ead88;
  this[8] = 0x7fffffff;
  this[0xf] = 0x10;
  this[0x14] = 0x20;
  this[0x16] = 0xfffffffd;
  this[0x17] = 3;
  this[0xb] = 0x20;
  this[10] = 0x10;
  FUN_0010dc20(this);
  BitSet__setBit(this,0x30);
  BitSet__setBit(this,0x31);
  BitSet__setBit(this,0x36);
  BitSet__setBit(this,0x39);
  BitSet__setBit(this,0x3b);
  BitSet__setBit(this,0x3c);
  BitSet__setBit(this,0x40);
  BitSet__setBit(this,0x41);
  BitSet__setBit(this,0x42);
  this[2] = this[2] | 0x20000;
  ((int (*)())KhanPs__vslot96_installHardwareTables)(this);
  if (param_3 != 0) {
    ((int (*)())KhanPs__createSchedModels)(this,param_2);
  }
  return;
}

/* FudoVs__createSchedModels @ 0x129290 (176 bytes) */
int FudoVs__createSchedModels(this, param_2)
  int this;
  undefined4 param_2;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined *puVar3;
  
  puVar2 = (undefined4 *)FUN_000e1564(param_2,0x3c);
  puVar1 = PTR_DAT_001e9110;
  puVar3 = PTR_DAT_001e90fc + 8;
  puVar2[2] = param_2;
  *puVar2 = puVar3;
  puVar2[1] = 0;
  *puVar2 = puVar1 + 8;
  R300VSchedModel__vslot2_reset(puVar2);
  SchedModel__resetCounters(puVar2);
  puVar2[0xe] = 0;
  *(undefined4 **)(this + 0x60) = puVar2;
  puVar2 = (undefined4 *)FUN_000e1564(param_2,0xc);
  puVar1 = PTR_DAT_001e9100;
  puVar2[1] = 1;
  puVar2[2] = 0;
  *puVar2 = puVar1 + 8;
  *(undefined4 **)(this + 100) = puVar2;
  return;
}

/* KhanVs__vslot76_getBindingLimits @ 0x129350 (96 bytes) */
int KhanVs__vslot76_getBindingLimits(this, outLimits)
  int *this;
  undefined4 *outLimits;
{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*this + 0x138))(this,0);
  *outLimits = uVar1;
  uVar1 = (**(code **)(*this + 0x140))(this,0);
  outLimits[1] = uVar1;
  return;
}

/* KhanVs__vslot77_getBindingLimits @ 0x1293b0 (72 bytes) */
int KhanVs__vslot77_getBindingLimits(this, outLimits)
  int *this;
  undefined4 *outLimits;
{
  undefined4 uVar1;
  
  *outLimits = 0;
  uVar1 = (**(code **)(*this + 0x138))(this,0);
  outLimits[1] = uVar1;
  return;
}

/* KhanVs__vslot80_getLimit_0x14 @ 0x1293f8 (8 bytes) */
int KhanVs__vslot80_getLimit_0x14()
{
  return 0x14;
}

/* KhanVs__vslot60_isZeroOrOne @ 0x129408 (60 bytes) */
undefined4 KhanVs__vslot60_isZeroOrOne(double fparam_1)
{
  if ((fparam_1 != (double)FLOAT_001aa0d4) && (fparam_1 != (double)FLOAT_001aa0e8)) {
    return 0;
  }
  return 1;
}

/* KhanVs__vslot73_noOp @ 0x129444 (4 bytes) */
int KhanVs__vslot73_noOp()
{
  return;
}

/* KhanVs__vslot99_matchesRegisterMapEntry @ 0x129448 (48 bytes) */
int KhanVs__vslot99_matchesRegisterMapEntry(this, param_2, param_3)
  undefined4 this;
  uint param_2;
  int param_3;
{
  return *(byte *)(param_2 * 0xc +
                   *(int *)(*(int *)(*(int *)(param_3 + 8) + 0x52c) * 4 + *(int *)(param_3 + 8) +
                           0x524) + 0x10a) == param_2;
}

/* KhanVs__vslot35_publishLimitsAndBindingTables @ 0x129478 (504 bytes) */
int KhanVs__vslot35_publishLimitsAndBindingTables(this, compiler, limitsBlob)
  int this;
  int compiler;
  int *limitsBlob;
{
  uint loopIndex;
  undefined1 *puVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  undefined1 *puVar10;
  int iVar11;
  undefined1 *puVar12;
  
  _memcpy(*(undefined4 *)(compiler + 0x650),limitsBlob[1],*limitsBlob << 4);
  _memcpy(*(undefined4 *)(compiler + 0x654),limitsBlob[2],900);
  iVar4 = limitsBlob[3];
  iVar7 = limitsBlob[4];
  iVar11 = limitsBlob[5];
  iVar8 = limitsBlob[6];
  iVar6 = limitsBlob[7];
  iVar5 = limitsBlob[8];
  *(int *)(compiler + 0x670) = limitsBlob[9];
  *(int *)(compiler + 0x658) = iVar4;
  *(int *)(compiler + 0x65c) = iVar7;
  *(int *)(compiler + 0x660) = iVar11;
  *(int *)(compiler + 0x664) = iVar8;
  *(int *)(compiler + 0x668) = iVar6;
  *(int *)(compiler + 0x66c) = iVar5;
  iVar4 = *(int *)(((unsigned char *)0x0000172c) + this);
  *(int *)(compiler + 0x104) = iVar4;
  if (iVar4 != 0) {
    loopIndex = 0;
    iVar4 = this;
    do {
      loopIndex = loopIndex + 1;
      iVar5 = *(int *)(iVar4 + 0x70) * 0xc + compiler;
      *(uint *)(iVar4 + 0x68) = (uint)*(byte *)(iVar5 + 0x108);
      *(uint *)(iVar4 + 0x6c) = (uint)*(byte *)(iVar5 + 0x109);
      iVar4 = iVar4 + 0x34;
    } while (loopIndex < *(uint *)(compiler + 0x104));
  }
  iVar5 = 0;
  iVar6 = this + 0x80;
  iVar7 = compiler + 0x100;
  iVar4 = this;
  do {
    puVar10 = (undefined1 *)(iVar6 + 0x14);
    puVar12 = (undefined1 *)(iVar7 + 0xc);
    *(char *)(iVar7 + 8) = (char)*(undefined4 *)(iVar4 + 0x68);
    iVar8 = 4;
    *(char *)(iVar7 + 9) = (char)*(undefined4 *)(iVar4 + 0x6c);
    *(char *)(iVar7 + 10) = (char)*(undefined4 *)(iVar4 + 0x70);
    uVar3 = *(uint *)(iVar7 + 8);
    uVar9 = (*(uint *)(iVar4 + 0x78) & 0xf) << 4;
    *(uint *)(iVar7 + 8) = uVar9 | uVar3 & 0xffffff0f;
    *(uint *)(iVar7 + 8) = *(uint *)(iVar4 + 0x7c) & 1 | uVar9 | uVar3 & 0xffffff0e;
    do {
      *puVar12 = *puVar10;
      puVar1 = puVar10 + 4;
      puVar10 = puVar10 + 1;
      puVar12[4] = *puVar1;
      puVar12 = puVar12 + 1;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
    bVar2 = iVar5 != 0x3f;
    iVar7 = iVar7 + 0xc;
    iVar6 = iVar6 + 0x34;
    iVar4 = iVar4 + 0x34;
    iVar5 = iVar5 + 1;
  } while (bVar2);
  iVar4 = compiler + 0x400;
  iVar5 = 0;
  *(undefined4 *)(compiler + 0x408) = *(undefined4 *)(((unsigned char *)0x00001728) + this);
  iVar6 = this + 0xd80;
  do {
    puVar10 = (undefined1 *)(iVar6 + 0x14);
    puVar12 = (undefined1 *)(iVar4 + 0x10);
    *(char *)(iVar4 + 0xc) = (char)*(undefined4 *)(this + 0xd68);
    iVar7 = 4;
    *(char *)(iVar4 + 0xd) = (char)*(undefined4 *)(this + 0xd6c);
    *(char *)(iVar4 + 0xe) = (char)*(undefined4 *)(this + 0xd70);
    uVar3 = *(uint *)(iVar4 + 0xc);
    uVar9 = (*(uint *)(this + 0xd78) & 0xf) << 4;
    *(uint *)(iVar4 + 0xc) = uVar9 | uVar3 & 0xffffff0f;
    *(uint *)(iVar4 + 0xc) = *(uint *)(this + 0xd7c) & 1 | uVar9 | uVar3 & 0xffffff0e;
    do {
      *puVar12 = *puVar10;
      puVar1 = puVar10 + 4;
      puVar10 = puVar10 + 1;
      puVar12[4] = *puVar1;
      puVar12 = puVar12 + 1;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    bVar2 = iVar5 != 0x2f;
    iVar4 = iVar4 + 0xc;
    iVar6 = iVar6 + 0x34;
    this = this + 0x34;
    iVar5 = iVar5 + 1;
  } while (bVar2);
  return 0;
}

/* KhanVs__getOpcodeTraits @ 0x129678 (28 bytes) */
int KhanVs__getOpcodeTraits()
{
  return &DAT_001df1fc;
}

/* FudoVs__vslot8_failNotSupported @ 0x129694 (56 bytes) */
int FudoVs__vslot8_failNotSupported(this, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 this;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  int param_7;
{
  if (*(int *)(param_7 + 0x6c4) != 0) {
    Compiler__fail(param_7,0xf);
  }
  return 0;
}

/* KhanVs__vslot22_appendRegisterBindingWithLaneArrays @ 0x1296cc (124 bytes) */
int KhanVs__vslot22_appendRegisterBindingWithLaneArrays(this, param_2, param_3, bindingKind, param_5, laneMask)
  int this;
  undefined4 *param_2;
  undefined1 *param_3;
  undefined4 bindingKind;
  undefined4 param_5;
  uint laneMask;
{
  int iVar1;
  int record;
  uint uVar3;
  int iVar4;
  
  record = *(int *)(((unsigned char *)0x00001728) + this);
  *(int *)(((unsigned char *)0x00001728) + this) = record + 1;
  uVar3 = 0;
  record = this + record * 0x34 + 0xd60;
  iVar1 = record + 8;
  *(undefined4 *)(record + 8) = bindingKind;
  *(undefined4 *)(record + 0x24) = 1;
  *(undefined4 *)(record + 0x1c) = 1;
  iVar4 = 4;
  *(undefined4 *)(record + 0x10) = param_5;
  *(undefined4 *)(record + 0xc) = param_5;
  *(uint *)(record + 0x18) = laneMask;
  do {
    if ((laneMask & 1 << (uVar3 & 0x3f)) != 0) {
      *(char *)(iVar1 + 0x2c) = (char)*param_2;
      *(undefined1 *)(iVar1 + 0x30) = *param_3;
    }
    uVar3 = uVar3 + 1;
    param_2 = param_2 + 1;
    iVar1 = iVar1 + 1;
    param_3 = param_3 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return;
}

/* KhanVs__vslot21_appendRegisterBinding @ 0x129748 (156 bytes) */
int KhanVs__vslot21_appendRegisterBinding(this, regIndex, bindingKind, param_4, laneSelectWord, param_6, param_7, param_8, param_9, param_10)
  int this;
  undefined4 regIndex;
  int bindingKind;
  undefined4 param_4;
  undefined4 laneSelectWord;
  int param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
  undefined4 param_10;
{
  int record;
  
  record = *(int *)(((unsigned char *)0x00001728) + this);
  *(int *)(((unsigned char *)0x00001728) + this) = record + 1;
  record = this + record * 0x34 + 0xd60;
  *(int *)(record + 8) = bindingKind;
  *(undefined4 *)(record + 0x1c) = 1;
  *(undefined4 *)(record + 0xc) = param_4;
  *(undefined1 *)(record + 0x37) = (undefined1)regIndex;
  *(undefined1 *)(record + 0x34) = (undefined1)regIndex;
  *(undefined1 *)(record + 0x35) = (undefined1)regIndex;
  *(undefined1 *)(record + 0x36) = (undefined1)regIndex;
  if (bindingKind == 4) {
    *(undefined1 *)(record + 0x3b) = 3;
    *(undefined1 *)(record + 0x38) = 3;
    *(undefined1 *)(record + 0x39) = 3;
    *(undefined1 *)(record + 0x3a) = 3;
  }
  else {
    *(char *)(record + 0x38) = (char)((uint)laneSelectWord >> 0x18);
    *(char *)(record + 0x39) = (char)((uint)laneSelectWord >> 0x10);
    *(char *)(record + 0x3a) = (char)((uint)laneSelectWord >> 8);
    *(char *)(record + 0x3b) = (char)laneSelectWord;
  }
  *(undefined4 *)(record + 0x10) = param_10;
  *(uint *)(record + 0x24) = (uint)(param_6 == 0);
  *(undefined4 *)(record + 0x18) = param_9;
  return;
}

/* KhanVs__vslot100_appendIdentityRegisterBinding @ 0x1297e4 (112 bytes) */
int KhanVs__vslot100_appendIdentityRegisterBinding(this, bindingValue, regIndex)
  int this;
  undefined4 bindingValue;
  undefined4 regIndex;
{
  int record;
  
  record = *(int *)(((unsigned char *)0x0000172c) + this);
  *(int *)(((unsigned char *)0x0000172c) + this) = record + 1;
  record = this + record * 0x34 + 0x60;
  *(undefined4 *)(record + 8) = 5;
  *(undefined1 *)(record + 0x38) = 0;
  *(undefined1 *)(record + 0x3a) = 2;
  *(undefined4 *)(record + 0x10) = bindingValue;
  *(undefined1 *)(record + 0x37) = (undefined1)regIndex;
  *(undefined1 *)(record + 0x39) = 1;
  *(undefined1 *)(record + 0x3b) = 3;
  *(undefined4 *)(record + 0x18) = 0xf;
  *(undefined4 *)(record + 0x1c) = 1;
  *(undefined4 *)(record + 0xc) = bindingValue;
  *(undefined1 *)(record + 0x34) = (undefined1)regIndex;
  *(undefined1 *)(record + 0x35) = (undefined1)regIndex;
  *(undefined1 *)(record + 0x36) = (undefined1)regIndex;
  return;
}

/* KhanVs__vslot58_matchImmediateConstantCode @ 0x129854 (312 bytes) */
int KhanVs__vslot58_matchImmediateConstantCode(this, constants, outSelectCode, laneSwizzle)
  undefined4 this;
  float *constants;
  int *outSelectCode;
  undefined4 laneSwizzle;
{
  unsigned int ghidra_home[8] = { this, constants, outSelectCode, laneSwizzle, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  float fVar1;
  int *piVar2;
  float *pfVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  int local_38 [4];
  longlong local_28;
  undefined4 local_20;
  
  pcVar5 = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 12));
  (*(unsigned int *)((unsigned char *)ghidra_home + 12)) = laneSwizzle;
  *outSelectCode = -1;
  iVar7 = 4;
  pfVar3 = constants;
  pcVar6 = pcVar5;
  while ((((*pcVar6 == '\x04' || (fVar1 = *pfVar3, fVar1 == FLOAT_001aa0d4)) ||
          (fVar1 == FLOAT_001aa0e8)) || (local_20 = 0xbf800000, fVar1 == -1.0))) {
    pcVar6 = pcVar6 + 1;
    pfVar3 = pfVar3 + 1;
    iVar7 = iVar7 + -1;
    if (iVar7 == 0) {
      iVar7 = (int)pcVar6 - (int)pcVar5;
      pfVar3 = constants;
      do {
        if (*pcVar5 == '\x04') {
          *pfVar3 = 0.0;
        }
        local_38[3] = DAT_001affcc;
        local_38[2] = DAT_001affc8;
        pcVar5 = pcVar5 + 1;
        pfVar3 = pfVar3 + 1;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      iVar7 = 0;
      iVar4 = 0;
      local_38[1] = DAT_001affc4;
      local_38[0] = DAT_001affc0;
      iVar8 = 4;
      *outSelectCode = 0;
      do {
        fVar1 = *constants;
        constants = constants + 1;
        local_28 = (longlong)(int)fVar1;
        piVar2 = (int *)((int)local_38 + iVar4);
        iVar4 = iVar4 + 4;
        iVar7 = (int)fVar1 * *piVar2 + iVar7;
        *outSelectCode = iVar7;
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
      return 1;
    }
  }
  return 0;
}

/* KhanVs__vslot74 @ 0x12998c (128 bytes) */
int KhanVs__vslot74(this, param_2)
  undefined4 this;
  undefined4 param_2;
{
  undefined4 uVar1;
  int exprRecord;
  undefined4 *puVar3;
  
  puVar3 = &DAT_001affb0;
  do {
    exprRecord = Compiler__valueNumberForExpr(param_2,*puVar3);
    uVar1 = *puVar3;
    *(undefined4 *)(exprRecord + 0x1c) = 0;
    puVar3 = puVar3 + 1;
    *(undefined4 *)(exprRecord + 0x14) = uVar1;
    *(undefined1 *)(exprRecord + 8) = 1;
    *(undefined1 *)(exprRecord + 9) = 0;
    *(undefined4 *)(exprRecord + 0x18) = 0;
    FUN_0017629c(exprRecord,param_2);
  } while (puVar3 != &DAT_001affb8);
  return;
}

/* KhanVs__vslot59_tryEncodeSourceConstant @ 0x129a0c (316 bytes) */
int KhanVs__vslot59_tryEncodeSourceConstant(this, inst, srcIndex, laneSwizzle, compiler)
  undefined4 this;
  undefined4 inst;
  undefined4 srcIndex;
  uint laneSwizzle;
  int compiler;
{
  char cVar1;
  float fVar2;
  int *a0;
  int iVar3;
  undefined4 uVar4;
  float *pfVar5;
  int iVar6;
  uint local_58;
  undefined4 local_54;
  uint local_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  undefined4 local_30;
  
  local_58 = laneSwizzle << 0x18 | (laneSwizzle & 0xff00) << 8 | laneSwizzle >> 8 & 0xff00 | laneSwizzle >> 0x18;
  a0 = (int *)IRInst__getOperandSource(inst,srcIndex);
  iVar3 = (**(code **)(*a0 + 0x48))(a0);
  if (iVar3 == 0) {
LAB_00129b30:
    uVar4 = 0;
  }
  else {
    iVar3 = IRInst__getOperandRecord(inst,srcIndex);
    iVar6 = 0;
    local_54 = *(undefined4 *)(iVar3 + 0x10);
    iVar3 = 4;
    pfVar5 = (float *)&local_50;
    do {
      cVar1 = *(char *)((int)&local_58 + iVar6);
      *pfVar5 = 0.0;
      if (cVar1 == '\0') {
        if ((((int)*(char *)(a0 + 0x57) >> (*(byte *)((int)&local_54 + iVar6) & 0x3f) & 1U) == 0) ||
           (((fVar2 = GH_U2F((unsigned int)(a0[(uint)*(byte *)((int)&local_54 + iVar6) * 6 + 8])), fVar2 != 0.0 &&
             (fVar2 != 1.0)) && (local_30 = 0xbf800000, fVar2 != -1.0)))) goto LAB_00129b30;
        *pfVar5 = fVar2;
      }
      iVar6 = iVar6 + 1;
      pfVar5 = pfVar5 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    ((void (*)())FUN_000f79c4)(inst,*(undefined4 *)(compiler + 0x6c4),srcIndex,(double)GH_U2F((unsigned int)(local_50)),
                 (double)fStack_4c,(double)fStack_48,(double)fStack_44);
    uVar4 = 1;
  }
  return uVar4;
}

/* KhanVs__vslot71_canCombineSources @ 0x129b48 (632 bytes) */
int KhanVs__vslot71_canCombineSources(this, inst, param_3, inst2, param_5, param_6, param_7)
  undefined4 this;
  int *inst;
  int param_3;
  int *inst2;
  undefined4 param_5;
  undefined4 param_6;
  int param_7;
{
  int *operandVReg;
  int loopIndex2;
  bool bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 operandVReg2;
  int iVar6;
  int loopIndex3;
  int *inst3;
  int iVar9;
  int loopIndex;
  int local_58 [10];
  
  iVar3 = 0;
  do {
    bVar1 = iVar3 != 8;
    *(undefined4 *)(iVar3 + (int)local_58) = 0xffffffff;
    *(undefined4 *)(iVar3 + (int)(local_58 + 3)) = 0xffffffff;
    iVar3 = iVar3 + 4;
  } while (bVar1);
  loopIndex3 = 0;
  loopIndex2 = 0;
  loopIndex = 1;
  inst3 = inst;
  do {
    iVar6 = (**(code **)(*inst + 0x14))(inst);
    if (iVar6 < loopIndex) {
      return 1;
    }
    if ((*(uint *)(*(int *)(param_7 + 0x6c4) + 0x30) & 8) == 0) {
      if (loopIndex == param_3) {
        iVar9 = inst2[0x26];
        iVar6 = *(int *)(inst2[0x23] + 8);
      }
      else {
        iVar6 = inst3[0x2b];
        iVar9 = inst3[0x2c];
      }
LAB_00129cc4:
      switch(iVar9) {
      case 2:
      case 0xc:
      case 0x26:
      case 0x28:
        iVar9 = 0;
        piVar4 = local_58;
        while( true ) {
          iVar2 = *piVar4;
          piVar4 = piVar4 + 1;
          if (iVar2 == -1) break;
          if ((iVar6 == iVar2) || (bVar1 = iVar9 == 2, iVar9 = iVar9 + 1, bVar1))
          goto switchD_00129ce4_caseD_0;
        }
        loopIndex3 = loopIndex3 + 1;
        local_58[iVar9] = iVar6;
        break;
      case 0x29:
      case 0x37:
        iVar9 = 0;
        piVar4 = local_58 + 3;
        while( true ) {
          iVar2 = *piVar4;
          piVar4 = piVar4 + 1;
          if (iVar2 == -1) break;
          if ((iVar6 == iVar2) || (bVar1 = iVar9 == 2, iVar9 = iVar9 + 1, bVar1))
          goto switchD_00129ce4_caseD_0;
        }
        loopIndex2 = loopIndex2 + 1;
        local_58[iVar9 + 3] = iVar6;
      }
    }
    else {
      if (loopIndex == param_3) {
        iVar6 = (**(code **)(*inst2 + 0x60))(inst2);
        if (iVar6 == 0) {
          iVar6 = inst2[0x25];
          iVar9 = inst2[0x26];
        }
        else {
          iVar6 = IRInst__getOperandSource(inst2,1);
          iVar9 = *(int *)(iVar6 + 0x98);
          iVar6 = IRInst__getOperandSource(inst2,1);
          iVar6 = *(int *)(iVar6 + 0x94);
        }
        goto LAB_00129cc4;
      }
      iVar6 = IRInst__getOperandSource(inst,loopIndex);
      if (iVar6 != 0) {
        operandVReg = (int *)IRInst__getOperandSource(inst,loopIndex);
        iVar6 = (**(code **)(*operandVReg + 0x60))(operandVReg);
        if (iVar6 == 0) {
          iVar6 = IRInst__getOperandSource(inst,loopIndex);
          iVar9 = *(int *)(iVar6 + 0x98);
          iVar6 = IRInst__getOperandSource(inst,loopIndex);
          iVar6 = *(int *)(iVar6 + 0x94);
        }
        else {
          operandVReg2 = IRInst__getOperandSource(inst,loopIndex);
          iVar6 = IRInst__getOperandSource(operandVReg2,1);
          iVar9 = *(int *)(iVar6 + 0x98);
          operandVReg2 = IRInst__getOperandSource(inst,loopIndex);
          iVar6 = IRInst__getOperandSource(operandVReg2,1);
          iVar6 = *(int *)(iVar6 + 0x94);
        }
        goto LAB_00129cc4;
      }
    }
switchD_00129ce4_caseD_0:
    if ((1 < loopIndex3) || (inst3 = inst3 + 6, 1 < loopIndex2)) {
      return 0;
    }
    loopIndex = loopIndex + 1;
  } while( true );
}

/* KhanVs__vslot85_findOrEncodeConstantVector @ 0x129eb4 (344 bytes) */
int KhanVs__vslot85_findOrEncodeConstantVector(this, program, constants, laneSwizzle)
  undefined4 this;
  int program;
  dword *constants;
  int *laneSwizzle;
{
  float fVar1;
  bool bVar2;
  int *piVar3;
  uint *puVar4;
  char *pcVar5;
  int iVar6;
  dword *pdVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  uint local_38;
  float local_20;
  
  if (*laneSwizzle != 0x4040404) {
    pcVar5 = "te()\n";
    fVar1 = 0.0;
    iVar9 = 4;
    bVar2 = true;
    iVar6 = 1;
    piVar3 = laneSwizzle;
    pdVar7 = constants;
    do {
      if (*(char *)piVar3 != '\x04') {
        if (bVar2) {
          fVar1 = (float)*pdVar7;
          bVar2 = false;
        }
        else if ((float)*pdVar7 != fVar1) {
          iVar6 = 0;
        }
      }
      piVar3 = (int *)((int)piVar3 + 1);
      pdVar7 = pdVar7 + 1;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    piVar3 = laneSwizzle;
    if (iVar6 == 0) {
      iVar9 = FUN_000f6a04(program,constants,*laneSwizzle);
    }
    else {
      pcVar5 = "";
      iVar9 = 4;
      puVar4 = &local_38;
      do {
        *puVar4 = 0x7ffffffe;
        puVar4 = puVar4 + 1;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
      pdVar7 = ((unsigned char *)0x4);
      iVar9 = 0;
      iVar10 = 4;
      do {
        local_20 = fVar1;
        *(float *)(iVar9 + (int)&local_38) = fVar1;
        iVar9 = iVar9 + 4;
        iVar10 = iVar10 + -1;
      } while (iVar10 != 0);
      iVar9 = FUN_000f6a04(program,&local_38,0x10203);
    }
    if (iVar9 != 0) {
      return iVar9;
    }
    uVar8 = *(undefined4 *)(program + 0x3ac);
    iVar6 = FUN_000f5f94(uVar8,constants,laneSwizzle,piVar3,pcVar5,iVar6,pdVar7);
    if (iVar6 != 0) {
      return iVar6;
    }
    iVar6 = FUN_000f57f0(uVar8,constants,laneSwizzle,piVar3);
    if (iVar6 != 0) {
      return iVar6;
    }
  }
  return 0;
}

/* KhanVs__vslot9_createCompareInst @ 0x12a00c (480 bytes) */
int KhanVs__vslot9_createCompareInst(this, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, compiler)
  undefined4 this;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  int param_8;
  undefined4 param_9;
  int compiler;
{
  unsigned int ghidra_home[8] = { this, param_2, param_3, param_4, param_5, param_6, param_7, param_8 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  bool bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int operandRecord;
  undefined4 uVar5;
  undefined4 *allocation;
  int iVar7;
  undefined4 arena;
  undefined4 *puVar9;
  int iVar10;
  
  iVar7 = compiler;
  arena = *(undefined4 *)(compiler + COMP_currentProgram);
  switch(param_2) {
  case 0:
    uVar2 = 0x27;
    bVar1 = false;
    break;
  case 1:
    uVar2 = 0x2a;
    bVar1 = false;
    break;
  case 2:
    uVar2 = 0x28;
    bVar1 = true;
    break;
  case 3:
    uVar2 = 0x29;
    bVar1 = true;
    break;
  case 4:
    uVar2 = 0x28;
    bVar1 = false;
    break;
  case 5:
    uVar2 = 0x29;
    bVar1 = false;
    break;
  default:
    uVar2 = 0xb5;
    bVar1 = false;
  }
  bVar1 = !bVar1;
  (*(unsigned int *)((unsigned char *)ghidra_home + 24)) = param_7;
  uVar2 = IRInst__create(uVar2,compiler);
  uVar3 = FUN_000ec208(arena,param_4);
  operandRecord = IRInst__getOperandRecord(uVar2,2 - (uint)bVar1);
  *(undefined4 *)(operandRecord + 0xc) = uVar3;
  *(undefined4 *)(operandRecord + 8) = param_3;
  if (bVar1) {
    uVar3 = 2;
  }
  else {
    uVar3 = 1;
  }
  uVar5 = FUN_000ec208(arena,param_6);
  operandRecord = IRInst__getOperandRecord(uVar2,uVar3);
  *(undefined4 *)(operandRecord + 0xc) = uVar5;
  *(undefined4 *)(operandRecord + 8) = param_5;
  if (bVar1) {
    uVar3 = 1;
  }
  else {
    uVar3 = 2;
  }
  FUN_000f8aa0(arena,&(*(unsigned int *)((unsigned char *)ghidra_home + 24)),**(undefined4 **)(param_8 + 0x6c),uVar3,uVar2);
  if (bVar1) {
    uVar3 = 2;
  }
  else {
    uVar3 = 1;
  }
  FUN_000f8aa0(arena,&(*(unsigned int *)((unsigned char *)ghidra_home + 24)),*(undefined4 *)(*(int *)(param_8 + 0x6c) + 4),uVar3,uVar2);
  iVar10 = *(int *)(iVar7 + 0x3ac) + -1;
  *(int *)(iVar7 + 0x3ac) = iVar10;
  operandRecord = IRInst__getOperandRecord(uVar2,0);
  *(undefined4 *)(operandRecord + 0xc) = 0;
  *(int *)(operandRecord + 8) = iVar10;
  FUN_000f92fc(arena,uVar2,param_9);
  arena = *(undefined4 *)(iVar7 + 0x374);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  puVar9 = allocation + 1;
  *allocation = arena;
  IRInst__ctor_10502c(puVar9,0x8c,iVar7);
  iVar7 = IRInst__getOperandRecord(puVar9,1);
  *(int *)(iVar7 + 8) = iVar10;
  *(undefined4 *)(iVar7 + 0xc) = 0;
  allocation[0x4c] = 0;
  return puVar9;
}

/* KhanVs__vslot89_assignLoadBindings @ 0x12a260 (352 bytes) */
int KhanVs__vslot89_assignLoadBindings(this, param_2)
  int *this;
  int param_2;
{
  int operandRecord;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (*(int *)(param_2 + 0x3d4) == 0) {
    iVar1 = *(int *)(*(int *)(param_2 + 0x3a0) + 0x98);
    iVar4 = *(int *)(iVar1 + 8);
    if (iVar4 != 0) {
      iVar3 = 0;
      do {
        iVar2 = iVar4;
        if (((*(uint *)(iVar1 + 0x14) & 1) != 0) && (*(int *)(*(int *)(iVar1 + 0x88) + 8) == 0xa4))
        {
          iVar4 = Compiler__isOptionEnabled(*(undefined4 *)(param_2 + 8),0x3e);
          if ((iVar4 == 0) ||
             (iVar4 = (**(code **)(*this + 0x18c))(this,*(undefined4 *)(iVar1 + 0x94),param_2)
             , iVar4 != 0)) {
            (**(code **)(*this + 400))(this,*(undefined4 *)(iVar1 + 0x94),iVar3);
            operandRecord = IRInst__getOperandRecord(iVar1,0);
            *(int *)(operandRecord + 8) = iVar3;
            iVar2 = *(int *)(iVar1 + 8);
            iVar3 = iVar3 + 1;
          }
          else {
            iVar2 = *(int *)(iVar1 + 8);
          }
        }
        iVar4 = *(int *)(iVar2 + 8);
        iVar1 = iVar2;
      } while (*(int *)(iVar2 + 8) != 0);
    }
  }
  else {
    iVar4 = *(int *)(*(int *)(param_2 + 0x3a0) + 0x98);
    for (iVar1 = *(int *)(iVar4 + 8); iVar1 != 0; iVar1 = *(int *)(iVar1 + 8)) {
      if (((*(uint *)(iVar4 + 0x14) & 1) != 0) && (*(int *)(*(int *)(iVar4 + 0x88) + 8) == 0xa4)) {
        (**(code **)(*this + 400))
                  (this,*(undefined4 *)(iVar4 + 0x94),*(undefined4 *)(iVar4 + 0x94));
        iVar1 = *(int *)(iVar4 + 8);
      }
      iVar4 = iVar1;
    }
  }
  return;
}

/* KhanVs__vslot75_registerConstantMultiples @ 0x12a3c0 (248 bytes) */
int KhanVs__vslot75_registerConstantMultiples(this, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 this;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined4 uVar1;
  byte bVar2;
  int exprRecord;
  
  if ((((*(char *)(param_2 + 8) != '\0') && (bVar2 = *(byte *)(param_2 + 9), (bVar2 & 1) == 0)) &&
      ((bVar2 & 2) == 0)) && (((bVar2 & 4) == 0 && ((bVar2 & 8) == 0)))) {
    exprRecord = Compiler__valueNumberForExpr(param_3,GH_F2U(-*(float *)(param_2 + 0x14)));
    if (*(char *)(exprRecord + 8) == '\0') {
      bVar2 = *(byte *)(exprRecord + 9);
    }
    else {
      bVar2 = *(byte *)(exprRecord + 9);
      if ((((bVar2 & 1) == 0) && ((bVar2 & 2) == 0)) && (((bVar2 & 4) == 0 && ((bVar2 & 8) == 0))))
      {
        return;
      }
    }
    if (((bVar2 & 1) == 0) || ((bVar2 & 2) != 0)) {
      *(undefined4 *)(exprRecord + 0x20) = 0x31;
      FUN_00176280(exprRecord,param_2);
      uVar1 = *(undefined4 *)(param_2 + 0x14);
      *(undefined1 *)(exprRecord + 9) = 1;
      *(undefined4 *)(exprRecord + 0x14) = uVar1;
      *(undefined4 *)(exprRecord + 0x1c) = 0;
      *(undefined4 *)(exprRecord + 0x18) = 1;
    }
  }
  return;
}

/* KhanVs__createSchedModels @ 0x12a4b8 (176 bytes) */
int KhanVs__createSchedModels(this, param_2)
  int this;
  undefined4 param_2;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined *puVar3;
  
  puVar2 = (undefined4 *)FUN_000e1564(param_2,0x3c);
  puVar1 = PTR_DAT_001e9110;
  puVar3 = PTR_DAT_001e90fc + 8;
  puVar2[2] = param_2;
  *puVar2 = puVar3;
  puVar2[1] = 0;
  *puVar2 = puVar1 + 8;
  R300VSchedModel__vslot2_reset(puVar2);
  SchedModel__resetCounters(puVar2);
  puVar2[0xe] = 0;
  *(undefined4 **)(this + 0x60) = puVar2;
  puVar2 = (undefined4 *)FUN_000e1564(param_2,0xc);
  puVar1 = PTR_DAT_001e9100;
  puVar2[1] = 1;
  puVar2[2] = 0;
  *puVar2 = puVar1 + 8;
  *(undefined4 **)(this + 100) = puVar2;
  return;
}

/* KhanVs__ctor_12a578 @ 0x12a578 (288 bytes) */
int KhanVs__ctor_12a578(this, param_2, param_3)
  undefined4 *this;
  undefined4 param_2;
  int param_3;
{
  undefined *puVar1;
  
  HwLimits__dtor_10dad8(this);
  puVar1 = PTR_DAT_001e9114;
  this[4] = 5;
  this[1] = puVar1;
  this[6] = 0x48;
  this[5] = 2;
  this[0x12] = 0x3ff;
  *this = &PTR_FUN_001eaf20;
  this[8] = 0x7fffffff;
  this[0xf] = 0x10;
  this[0x10] = 0x100;
  this[0x13] = 4;
  this[0x14] = 0x20;
  this[0x15] = 1;
  this[2] = this[2] | 0x2000;
  this[7] = 4;
  this[0xb] = 0x100;
  this[9] = 0x100;
  this[10] = 0x100;
  this[0xe] = 0x10;
  this[0x11] = 4;
  FUN_0010dc20(this);
  BitSet__setBit(this,0x3a);
  BitSet__setBit(this,0x3e);
  BitSet__setBit(this,0x3f);
  BitSet__setBit(this,0x4d);
  this[0x19] = 0;
  this[0x18] = 0;
  ((int (*)())KhanVs__vslot96_installHardwareTables)(this);
  if (param_3 != 0) {
    ((int (*)())KhanVs__createSchedModels)(this,param_2);
  }
  return;
}

/* KhanVs__ctor_12a6c0 @ 0x12a6c0 (288 bytes) */
int KhanVs__ctor_12a6c0(this, param_2, param_3)
  undefined4 *this;
  undefined4 param_2;
  int param_3;
{
  undefined *puVar1;
  
  HwLimits__dtor_10dad8(this);
  puVar1 = PTR_DAT_001e9114;
  this[4] = 5;
  this[1] = puVar1;
  this[6] = 0x48;
  this[5] = 2;
  this[0x12] = 0x3ff;
  *this = &PTR_FUN_001eaf20;
  this[8] = 0x7fffffff;
  this[0xf] = 0x10;
  this[0x10] = 0x100;
  this[0x13] = 4;
  this[0x14] = 0x20;
  this[0x15] = 1;
  this[2] = this[2] | 0x2000;
  this[7] = 4;
  this[0xb] = 0x100;
  this[9] = 0x100;
  this[10] = 0x100;
  this[0xe] = 0x10;
  this[0x11] = 4;
  FUN_0010dc20(this);
  BitSet__setBit(this,0x3a);
  BitSet__setBit(this,0x3e);
  BitSet__setBit(this,0x3f);
  BitSet__setBit(this,0x4d);
  this[0x19] = 0;
  this[0x18] = 0;
  ((int (*)())KhanVs__vslot96_installHardwareTables)(this);
  if (param_3 != 0) {
    ((int (*)())KhanVs__createSchedModels)(this,param_2);
  }
  return;
}

/* FudoVs__ctor_12a808 @ 0x12a808 (124 bytes) */
int FudoVs__ctor_12a808(this, param_2, param_3)
  undefined4 *this;
  undefined4 param_2;
  int param_3;
{
  ((int (*)())KhanVs__ctor_12a6c0)(this,param_2,0);
  *this = &PTR_FUN_001eb0c0;
  this[6] = 0x80;
  this[0x10] = 0x400;
  this[2] = this[2] | 0x10100;
  ((int (*)())FudoVs__vslot96_installHardwareTables)(this);
  if (param_3 != 0) {
    ((int (*)())FudoVs__createSchedModels)(this,param_2);
  }
  return;
}

/* FudoVs__ctor_12a8bc @ 0x12a8bc (124 bytes) */
int FudoVs__ctor_12a8bc(this, param_2, param_3)
  undefined4 *this;
  undefined4 param_2;
  int param_3;
{
  ((int (*)())KhanVs__ctor_12a6c0)(this,param_2,0);
  *this = &PTR_FUN_001eb0c0;
  this[6] = 0x80;
  this[0x10] = 0x400;
  this[2] = this[2] | 0x10100;
  ((int (*)())FudoVs__vslot96_installHardwareTables)(this);
  if (param_3 != 0) {
    ((int (*)())FudoVs__createSchedModels)(this,param_2);
  }
  return;
}

/* KhanVs__vslot96_installHardwareTables @ 0x12a970 (116 bytes) */
int KhanVs__vslot96_installHardwareTables(this)
  int this;
{
  PTR_DAT_001e27bc = PTR_DAT_001e9120;
  *(undefined **)(this + 0xc) = &DAT_001e1994;
  PTR_DAT_001e260c = PTR_DAT_001e911c;
  PTR_DAT_001e1c34 = PTR_DAT_001e9128;
  DAT_001e1c2c = 5;
  DAT_001e1c30 = 0;
  PTR_DAT_001e269c = PTR_DAT_001e9124;
  PTR_DAT_001e2630 = PTR_DAT_001e9118;
  DAT_001e2604 = 5;
  DAT_001e2608 = 0;
  return;
}

/* FudoVs__vslot96_installHardwareTables @ 0x12a9e4 (116 bytes) */
int FudoVs__vslot96_installHardwareTables(this)
  int this;
{
  *(undefined **)(this + 0xc) = &DAT_001e1994;
  DAT_001e25f4 = 0x4c;
  PTR_DAT_001e27bc = PTR_DAT_001e8c84;
  DAT_001e1c2c = 4;
  DAT_001e1c30 = PTR_FUN_001e8c7c;
  PTR_DAT_001e1c34 = (undefined *)0x0;
  DAT_001e1c1c = 0x4d;
  PTR_DAT_001e269c = PTR_DAT_001e8c78;
  DAT_001e2604 = 4;
  DAT_001e2608 = PTR_FUN_001e8c7c;
  PTR_DAT_001e260c = (undefined *)0x0;
  PTR_DAT_001e2630 = PTR_DAT_001e8c84;
  return;
}

/* KhanPs__vslot96_installHardwareTables @ 0x12aa58 (32 bytes) */
int KhanPs__vslot96_installHardwareTables(this)
  int this;
{
  *(undefined **)(this + 0xc) = &DAT_001e39a4;
  return;
}

/* FUN_0012aa78 @ 0x12aa78 (104 bytes) */
int FUN_0012aa78(compiler, param_2, param_3, param_4, param_5)
  int compiler;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
{
  if (((*(int *)(param_5 + 0x140) == 0) ||
      (param_2 * param_4 + param_3 <= *(int *)(*(int *)(compiler + COMP_target) + 0x2c))) &&
     ((*(int *)(compiler + 0x318) == 0 ||
      ((param_2 <= *(int *)(compiler + 0x478) &&
       (param_2 * (*(int *)(compiler + COMP_nextInstId) - *(int *)(param_5 + 0x130)) <=
        *(int *)(compiler + 0x478) << 1)))))) {
    return 0;
  }
  return 1;
}

/* FUN_0012aae0 @ 0x12aae0 (36 bytes) */
int FUN_0012aae0(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_2 < 1) {
    return;
  }
  *(undefined4 *)(param_1 + 0x47c) = 1;
  if (param_2 <= *(int *)(param_1 + 0x480)) {
    return;
  }
  *(int *)(param_1 + 0x480) = param_2;
  return;
}

/* FUN_0012ab04 @ 0x12ab04 (108 bytes) */
int FUN_0012ab04(inst)
  int *inst;
{
  int iVar1;
  int loopIndex;
  
  loopIndex = 0;
  while( true ) {
    iVar1 = (**(code **)(*inst + 0x14))(inst);
    if (iVar1 < loopIndex) {
      return 0;
    }
    iVar1 = FUN_00105dbc(inst,loopIndex);
    if (iVar1 == 1) break;
    loopIndex = loopIndex + 1;
  }
  return 1;
}

/* pass_optimize_control_flow @ 0x12ab80 (88 bytes) */
int pass_optimize_control_flow(program)
  int program;
{
  int *targetDescription;
  
  targetDescription = *(int **)(*(int *)(program + 8) + 0x30c);
  (**(code **)(*targetDescription + 0x74))(targetDescription,program);
  return Program__beginPass(program,(int)"optimize_control_flow");
}

/* IfHeader__swapArms @ 0x12abd8 (128 bytes) */
int IfHeader__swapArms(program, ifHeader)
  undefined4 program;
  int ifHeader;
{
  int condition;
  undefined4 extraout_r4;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 in_r9;
  undefined4 branchInst;
  
  branchInst = *(undefined4 *)(ifHeader + 0x134);
  *(undefined4 *)(ifHeader + 0x134) = *(undefined4 *)(ifHeader + 0x138);
  *(undefined4 *)(ifHeader + 0x138) = branchInst;
  DList__unlink(branchInst);
  DList__insertBefore(branchInst,*(undefined4 *)(ifHeader + 0x13c));
  branchInst = Block__getBranchInst(ifHeader,extraout_r4,in_r5,in_r6,in_r7,in_r8,in_r9);
  condition = IRInst__getCompareCondition(branchInst);
  IRInst__setCompareCondition(branchInst,*(undefined4 *)(PTR_DAT_001e912c + condition * 4));
  return ifHeader;
}

/* FUN_0012ac58 @ 0x12ac58 (452 bytes) */
int FUN_0012ac58(param_1, param_2)
  int param_1;
  int *param_2;
{
  int *predecessor;
  int *a0;
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)param_2[0x4b];
  while( true ) {
    while( true ) {
      while( true ) {
        a0 = (int *)Block__getSuccessor(param_2,0);
        iVar1 = (**(code **)(*a0 + 0x10))(a0);
        if ((iVar1 != 0) && (*(int *)(iVar1 + 300) == param_1)) {
          iVar1 = (**(code **)(*piVar2 + 0x2c))(piVar2);
          predecessor = (int *)Block__getPredecessor(piVar2,(uint)(iVar1 != 0));
          return predecessor;
        }
        iVar1 = (**(code **)(*a0 + 0x24))(a0);
        if (iVar1 == 0) break;
        param_2 = (int *)a0[0x4f];
      }
      iVar1 = (**(code **)(*a0 + 0x2c))(a0);
      if (iVar1 == 0) break;
      param_2 = (int *)a0[0x55];
    }
    iVar1 = (**(code **)(*param_2 + 0x38))(param_2);
    if ((iVar1 != 0) || (iVar1 = (**(code **)(*param_2 + 0x3c))(param_2), iVar1 != 0)) break;
    iVar1 = (**(code **)(*a0 + 0x28))(a0);
    if ((iVar1 == 0) && (iVar1 = (**(code **)(*a0 + 0x30))(a0), iVar1 == 0)) {
      iVar1 = (**(code **)(*a0 + 0x20))(a0);
      if (iVar1 == 0) {
        param_2 = (int *)Block__getSuccessor(param_2,0);
      }
    }
    else {
      piVar2 = (int *)a0[0x4b];
      param_2 = a0;
    }
  }
  return param_2;
}

/* FUN_0012ae1c @ 0x12ae1c (80 bytes) */
int FUN_0012ae1c(param_1)
  int *param_1;
{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x30))(param_1);
  if (iVar1 != 0) {
    param_1 = *(int **)(param_1[0x4b] + 0x154);
  }
  return param_1;
}

/* FUN_0012ae6c @ 0x12ae6c (132 bytes) */
int FUN_0012ae6c(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  piVar1 = *(int **)(param_1 + 0x98);
  piVar2 = (int *)(*(int **)(param_1 + 0x98))[2];
  do {
    if (piVar2 == (int *)0x0) {
      return 0;
    }
    if ((piVar1[5] & 1U) != 0) {
      iVar3 = (**(code **)(*piVar1 + 0x28))(piVar1);
      if (iVar3 != 0) {
        return 1;
      }
      piVar2 = (int *)piVar1[2];
    }
    piVar1 = piVar2;
    piVar2 = (int *)piVar2[2];
  } while( true );
}

/* FUN_0012aef0 @ 0x12aef0 (248 bytes) */
int FUN_0012aef0(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
{
  undefined4 successor;
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  
  iVar1 = Block__isSimple(param_2);
  if ((((iVar1 == 0) || (iVar1 = Block__isSimple(param_3), iVar1 == 0)) ||
      (iVar1 = Block__successorCount(param_2), iVar1 != 1)) ||
     ((iVar1 = Block__predecessorCount(param_3), iVar1 != 1 || (iVar1 = FUN_000e79e8(param_3), iVar1 == 0)))) {
    uVar2 = 0;
  }
  else {
    piVar3 = *(int **)(*(int *)(param_3 + 200) + 8);
    while (piVar4 = piVar3, iVar1 = (**(code **)(*piVar4 + 0x38))(piVar4), iVar1 == 0) {
      piVar3 = (int *)piVar4[2];
      if ((piVar4[5] & 1U) != 0) {
        DList__unlink(piVar4);
        Block__appendInst(param_2,piVar4);
      }
    }
    successor = Block__getSuccessor(param_3,0);
    Block__bypassAndDetach(param_3,param_2,successor);
    uVar2 = 1;
  }
  return uVar2;
}

/* FUN_0012afe8 @ 0x12afe8 (344 bytes) */
int FUN_0012afe8(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int *param_3;
  int *param_4;
{
  int iVar1;
  
  if (param_3 != (int *)0x0) {
    do {
      iVar1 = (**(code **)(*param_3 + 0x24))(param_3);
      if (iVar1 == 0) {
        iVar1 = (**(code **)(*param_3 + 0x2c))(param_3);
        if (iVar1 == 0) {
          iVar1 = (**(code **)(*param_3 + 0x28))(param_3);
          if (iVar1 != 0) {
            if (param_1 == 0) {
              return param_3;
            }
            if (param_4 != param_3) {
              return param_3;
            }
            return param_4;
          }
          iVar1 = (**(code **)(*param_3 + 0x30))(param_3);
          if (iVar1 != 0) {
            return param_3;
          }
          iVar1 = (**(code **)(*param_3 + 0x10))(param_3);
          if (((iVar1 != 0) && (param_1 == 0)) &&
             (iVar1 = (**(code **)(*param_3 + 0x10))(param_3), *(int *)(iVar1 + 300) == param_2)) {
            return param_3;
          }
        }
        else {
          param_3 = (int *)param_3[0x54];
        }
      }
      else {
        param_3 = (int *)param_3[0x4f];
      }
      param_3 = (int *)Block__getSuccessor(param_3,0);
    } while (param_3 != (int *)0x0);
  }
  return (int *)0x0;
}

/* FUN_0012b140 @ 0x12b140 (264 bytes) */
int FUN_0012b140(param_1)
  int *param_1;
{
  int iVar1;
  
  iVar1 = *param_1;
  do {
    iVar1 = (**(code **)(iVar1 + 0x2c))(param_1);
    if (iVar1 == 0) {
      param_1 = (int *)Block__getPredecessor(param_1,0);
    }
    else {
      param_1 = (int *)Block__findSimplePredecessor(param_1);
    }
    while( true ) {
      while( true ) {
        if (param_1 == (int *)0x0) {
          return (int *)0x0;
        }
        iVar1 = (**(code **)(*param_1 + 0x24))(param_1);
        if (iVar1 != 0) {
          return param_1;
        }
        iVar1 = (**(code **)(*param_1 + 0x28))(param_1);
        if (iVar1 == 0) break;
        param_1 = (int *)Block__getPredecessor(param_1[0x4b],0);
      }
      iVar1 = (**(code **)(*param_1 + 0x34))(param_1);
      if (iVar1 == 0) break;
      param_1 = (int *)Block__findSimplePredecessor(param_1[0x4b]);
    }
    iVar1 = *param_1;
  } while( true );
}

/* FUN_0012b248 @ 0x12b248 (144 bytes) */
int FUN_0012b248(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  undefined4 inst;
  int operandRecord;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = *(int *)(*(int *)(param_3 + 8) + 0x3ac) + -1;
  *(int *)(*(int *)(param_3 + 8) + 0x3ac) = iVar4;
  inst = IRInst__create(0x31,*(undefined4 *)(param_3 + 8));
  operandRecord = IRInst__getOperandRecord(inst,0);
  uVar3 = *(undefined4 *)(param_1 + 0x8c);
  *(undefined4 *)(operandRecord + 0xc) = 0;
  *(int *)(operandRecord + 8) = iVar4;
  IRInst__setOperandRef(inst,1,uVar3);
  FUN_000ed63c(param_3,inst);
  Block__appendInst(param_2,inst);
  return iVar4;
}

/* FUN_0012b2d8 @ 0x12b2d8 (132 bytes) */
int FUN_0012b2d8(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  undefined4 callResult;
  int operandRecord;
  undefined4 uVar3;
  
  callResult = IRInst__create(0x31,*(undefined4 *)(param_4 + 8));
  operandRecord = IRInst__getOperandRecord(callResult,0);
  uVar3 = *(undefined4 *)(param_1 + 0xa4);
  *(undefined4 *)(operandRecord + 0xc) = 0;
  *(undefined4 *)(operandRecord + 8) = param_3;
  IRInst__setOperandRef(callResult,1,uVar3);
  FUN_000ed63c(param_4,callResult);
  Block__appendInst(param_2,callResult);
  return callResult;
}


/* issue: auto-generated aliases bridging data.s/code.s references (written
 * without a leading underscore, matching the raw stock-binary symbol name)
 * against the real compiled C symbols (gcc adds one underscore automatically).
 * Needed because ld64 (required for this PPC binary's size - stock ld breaks on
 * large PPC links) does not silently reconcile this the way stock ld did. */
asm(".globl FUN_00127ee4");
asm(".set FUN_00127ee4, _KhanPs__vslot76_getBindingLimit");
asm(".globl FUN_00127f24");
asm(".set FUN_00127f24, _KhanPs__createSchedModels");
asm(".globl FUN_00127fd8");
asm(".set FUN_00127fd8, _FUN_00127fd8");
asm(".globl FUN_00127ff8");
asm(".set FUN_00127ff8, _KhanPs__vslot62_lookupTableEntry");
asm(".globl FUN_0012801c");
asm(".set FUN_0012801c, _KhanPs__vslot90_isProgramKind1");
asm(".globl FUN_00128030");
asm(".set FUN_00128030, _KhanPs__getOpcodeTraits");
asm(".globl FUN_0012804c");
asm(".set FUN_0012804c, _KhanPs__vslot35_publishLimitsAndBindingTables");
asm(".globl FUN_001281b0");
asm(".set FUN_001281b0, _KhanPs__vslot8_failNotSupported");
asm(".globl FUN_001281f0");
asm(".set FUN_001281f0, _KhanPs__vslot58_matchImmediateConstantCode");
asm(".globl FUN_00128348");
asm(".set FUN_00128348, _KhanPs__vslot73_seedValueNumbers");
asm(".globl FUN_0012839c");
asm(".set FUN_0012839c, _KhanPs__vslot74_seedConstantValueNumbers");
asm(".globl FUN_00128430");
asm(".set FUN_00128430, _KhanPs__vslot85_findOrEncodeConstantVector");
asm(".globl FUN_0012873c");
asm(".set FUN_0012873c, _KhanPs__vslot59_tryEncodeSourceConstant");
asm(".globl FUN_00128930");
asm(".set FUN_00128930, _KhanPs__vslot9_createCompareInst");
asm(".globl FUN_00128ad4");
asm(".set FUN_00128ad4, _KhanPs__vslot5_materializeSpecialRegister");
asm(".globl FUN_00128d7c");
asm(".set FUN_00128d7c, _KhanPs__vslot75_registerConstantMultiples");
asm(".globl FUN_00129290");
asm(".set FUN_00129290, _FudoVs__createSchedModels");
asm(".globl FUN_00129350");
asm(".set FUN_00129350, _KhanVs__vslot76_getBindingLimits");
asm(".globl FUN_001293b0");
asm(".set FUN_001293b0, _KhanVs__vslot77_getBindingLimits");
asm(".globl FUN_001293f8");
asm(".set FUN_001293f8, _KhanVs__vslot80_getLimit_0x14");
asm(".globl FUN_00129408");
asm(".set FUN_00129408, _KhanVs__vslot60_isZeroOrOne");
asm(".globl FUN_00129444");
asm(".set FUN_00129444, _KhanVs__vslot73_noOp");
asm(".globl FUN_00129448");
asm(".set FUN_00129448, _KhanVs__vslot99_matchesRegisterMapEntry");
asm(".globl FUN_00129478");
asm(".set FUN_00129478, _KhanVs__vslot35_publishLimitsAndBindingTables");
asm(".globl FUN_00129678");
asm(".set FUN_00129678, _KhanVs__getOpcodeTraits");
asm(".globl FUN_00129694");
asm(".set FUN_00129694, _FudoVs__vslot8_failNotSupported");
asm(".globl FUN_001296cc");
asm(".set FUN_001296cc, _KhanVs__vslot22_appendRegisterBindingWithLaneArrays");
asm(".globl FUN_00129748");
asm(".set FUN_00129748, _KhanVs__vslot21_appendRegisterBinding");
asm(".globl FUN_001297e4");
asm(".set FUN_001297e4, _KhanVs__vslot100_appendIdentityRegisterBinding");
asm(".globl FUN_00129854");
asm(".set FUN_00129854, _KhanVs__vslot58_matchImmediateConstantCode");
asm(".globl FUN_0012998c");
asm(".set FUN_0012998c, _KhanVs__vslot74");
asm(".globl FUN_00129a0c");
asm(".set FUN_00129a0c, _KhanVs__vslot59_tryEncodeSourceConstant");
asm(".globl FUN_00129b48");
asm(".set FUN_00129b48, _KhanVs__vslot71_canCombineSources");
asm(".globl FUN_00129eb4");
asm(".set FUN_00129eb4, _KhanVs__vslot85_findOrEncodeConstantVector");
asm(".globl FUN_0012a00c");
asm(".set FUN_0012a00c, _KhanVs__vslot9_createCompareInst");
asm(".globl FUN_0012a260");
asm(".set FUN_0012a260, _KhanVs__vslot89_assignLoadBindings");
asm(".globl FUN_0012a3c0");
asm(".set FUN_0012a3c0, _KhanVs__vslot75_registerConstantMultiples");
asm(".globl FUN_0012a4b8");
asm(".set FUN_0012a4b8, _KhanVs__createSchedModels");
asm(".globl FUN_0012a970");
asm(".set FUN_0012a970, _KhanVs__vslot96_installHardwareTables");
asm(".globl FUN_0012a9e4");
asm(".set FUN_0012a9e4, _FudoVs__vslot96_installHardwareTables");
asm(".globl FUN_0012aa58");
asm(".set FUN_0012aa58, _KhanPs__vslot96_installHardwareTables");
