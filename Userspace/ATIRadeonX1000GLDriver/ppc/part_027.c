#include "decls.h"

/* IROperand__setModifierBits @ 0x103d50 (40 bytes) */
int IROperand__setModifierBits(operandRecord, mask, set)
  int operandRecord;
  uint mask;
  int set;
{
  if (set != 0) {
    *(uint *)(operandRecord + 0x14) = mask | *(uint *)(operandRecord + 0x14);
    return;
  }
  *(uint *)(operandRecord + 0x14) = *(uint *)(operandRecord + 0x14) & ~mask;
  return;
}

/* FUN_00103d78 @ 0x103d78 (220 bytes) */
int FUN_00103d78(undefined4 param_1,int param_2,uint param_3,double fparam_1)
{
  float fVar1;
  uint uVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  
  uVar2 = 1 << (param_2 - 1U & 0x3f);
  dVar5 = (double)(float)((double)CONCAT44(0x43300000,-uVar2 ^ 0x80000000) - DOUBLE_001aa1e0);
  dVar3 = (double)((float)((double)CONCAT44(0x43300000,uVar2 ^ 0x80000000) - DOUBLE_001aa1e0) +
                  FLOAT_001aa114 /
                  (float)((double)CONCAT44(0x43300000,1 << (param_3 - 1 & 0x3f) ^ 0x80000000) -
                         DOUBLE_001aa1e0));
  fVar1 = (float)(dVar3 - fparam_1);
  dVar4 = fparam_1;
  if (fVar1 < 0.0) {
    dVar4 = dVar3;
  }
  if (-fVar1 < 0.0) {
    dVar4 = fparam_1;
  }
  fVar1 = (float)(dVar4 - dVar5);
  dVar3 = dVar4;
  if (fVar1 < 0.0) {
    dVar3 = dVar5;
  }
  if (-fVar1 < 0.0) {
    dVar3 = dVar4;
  }
  return (int)(dVar3 * (double)(float)((double)CONCAT44(0x43300000,
                                                        1 << (param_3 & 0x3f) ^ 0x80000000) -
                                      DOUBLE_001aa1e0));
}

/* constantZeroFloat @ 0x103e54 (28 bytes) */
double constantZeroFloat( void)
{
  return (double)FLOAT_001aa0d4;
}

/* isLessThan2 @ 0x103e70 (16 bytes) */
int isLessThan2(param_1)
  uint param_1;
{
  return param_1 < 2;
}

/* FUN_00103e84 @ 0x103e84 (56 bytes) */
int FUN_00103e84(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_2 == 0) {
    *(undefined4 *)(param_1 + 0x10) = DAT_001af9c0;
    return;
  }
  *(undefined4 *)(param_1 + 0x10) = DAT_001af9bc;
  return;
}

/* FUN_00103ebc @ 0x103ebc (92 bytes) */
int FUN_00103ebc(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
{
  int iVar1;
  
  _memcpy(param_2,param_1,0x164);
  if (param_4 == 0) {
    iVar1 = *(int *)(param_3 + 0x324);
    *(int *)(param_2 + 0x14c) = iVar1;
    *(int *)(param_3 + 0x324) = iVar1 + 1;
  }
  return param_2;
}

/* IRInst__saveCounters @ 0x103f18 (44 bytes) */
int IRInst__saveCounters(inst, snapshot, mask)
  int inst;
  uint *snapshot;
  uint mask;
{
  *snapshot = mask;
  if ((mask & 1) != 0) {
    snapshot[1] = *(uint *)(inst + 0x160);
  }
  if ((*snapshot & 2) == 0) {
    return;
  }
  snapshot[2] = *(uint *)(inst + 0x14c);
  return;
}

/* IRInst__restoreCounters @ 0x103f44 (64 bytes) */
int IRInst__restoreCounters(inst, snapshot)
  int inst;
  uint *snapshot;
{
  uint mask;
  
  mask = *snapshot;
  if ((mask & 1) != 0) {
    *(uint *)(inst + 0x160) = snapshot[1];
    mask = *snapshot;
    snapshot[1] = 0;
  }
  if ((mask & 2) != 0) {
    *(uint *)(inst + 0x14c) = snapshot[2];
  }
  *snapshot = 0;
  snapshot[2] = 0;
  return;
}

/* IRInst__copyBodyFrom @ 0x103f84 (100 bytes) */
int IRInst__copyBodyFrom(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  local_20 = 0;
  local_28 = 0;
  local_24 = 0;
  ((int (*)())IRInst__saveCounters)(param_1,&local_28,0xffffffff);
  _memcpy(param_1,param_2,0x164);
  return ((int (*)())IRInst__restoreCounters)(param_1,&local_28);
}

/* operandsHaveSameConstant @ 0x103fe8 (52 bytes) */
int operandsHaveSameConstant(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  
  iVar1 = param_3 * 0x18 + param_2;
  if ((*(int *)(param_1 + 0x94) == *(int *)(iVar1 + 0x94)) &&
     (*(int *)(param_1 + 0x98) == *(int *)(iVar1 + 0x98))) {
    return 1;
  }
  return 0;
}

/* FUN_0010401c @ 0x10401c (56 bytes) */
int FUN_0010401c(param_1)
  int param_1;
{
  DList__unlink(param_1);
  *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) & 0xfffffffe;
  return;
}

/* IRInst__useCount @ 0x104054 (24 bytes) */
int IRInst__useCount(obj, program)
  int obj;
  int program;
{
  int count;
  
  count = *(int *)(obj + 0x160) - *(int *)(program + PROG_useEpoch);
  if (-1 < count) {
    return count;
  }
  return 0;
}

/* FUN_0010406c @ 0x10406c (68 bytes) */
int FUN_0010406c(param_1)
  int param_1;
{
  if ((*(uint *)(PTR_PTR_001e8c60 + param_1 * 0x10 + 4) & 0x400) != 0) {
    return 0x16;
  }
  if ((*(uint *)(PTR_PTR_001e8c60 + param_1 * 0x10 + 4) & 0x800) == 0) {
    return param_1;
  }
  return 0x15;
}

/* RegKind__laneCount @ 0x1040b0 (84 bytes) */
int RegKind__laneCount(param_1)
  int param_1;
{
  if ((*(uint *)(PTR_PTR_001e8c60 + param_1 * 0x10 + 4) & 0x400) != 0) {
    return '\x04';
  }
  if ((*(uint *)(PTR_PTR_001e8c60 + param_1 * 0x10 + 4) & 0x800) != 0) {
    return '\x03';
  }
  return (param_1 == 7) + '\x01';
}

/* FUN_00104104 @ 0x104104 (124 bytes) */
int FUN_00104104(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  uint param_3;
  uint param_4;
{
  if (param_2 == 1) {
    *(uint *)(param_1 + 0x130) = (param_3 & 0xff) << 0x10 | param_4 & 0xffff;
    return;
  }
  if (param_2 < 2) {
    if (param_2 != 0) {
      return;
    }
    *(uint *)(param_1 + 300) = (param_3 & 0xff) << 0x10 | param_4 & 0xffff;
    return;
  }
  if (param_2 == 2) {
    *(uint *)(param_1 + 0x134) = (param_3 & 0xff) << 0x10 | param_4 & 0xffff;
    return;
  }
  if (param_2 != 3) {
    return;
  }
  *(uint *)(param_1 + 0x138) = (param_3 & 0xff) << 0x10 | param_4 & 0xffff;
  return;
}

/* FUN_00104180 @ 0x104180 (80 bytes) */
int FUN_00104180(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_2 == 1) {
    return *(undefined2 *)(param_1 + 0x132);
  }
  if (param_2 < 2) {
    if (param_2 == 0) {
      return *(undefined2 *)(param_1 + 0x12e);
    }
  }
  else {
    if (param_2 == 2) {
      return *(undefined2 *)(param_1 + 0x136);
    }
    if (param_2 == 3) {
      return *(undefined2 *)(param_1 + 0x13a);
    }
  }
  return 0;
}

/* FUN_001041d0 @ 0x1041d0 (156 bytes) */
int FUN_001041d0(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  uint param_4;
  uint param_5;
{
  if (param_2 == 1) {
    *(uint *)(param_1 + 0x130) = param_3 << 0x18 | (param_4 & 0xff) << 0x10 | param_5 & 0xffff;
    return;
  }
  if (param_2 < 2) {
    if (param_2 != 0) {
      return;
    }
    *(uint *)(param_1 + 300) = param_3 << 0x18 | (param_4 & 0xff) << 0x10 | param_5 & 0xffff;
    return;
  }
  if (param_2 == 2) {
    *(uint *)(param_1 + 0x134) = param_3 << 0x18 | (param_4 & 0xff) << 0x10 | param_5 & 0xffff;
    return;
  }
  if (param_2 != 3) {
    return;
  }
  *(uint *)(param_1 + 0x138) = param_3 << 0x18 | (param_4 & 0xff) << 0x10 | param_5 & 0xffff;
  return;
}

/* FUN_0010426c @ 0x10426c (80 bytes) */
int FUN_0010426c(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_2 == 1) {
    return *(undefined2 *)(param_1 + 0x132);
  }
  if (param_2 < 2) {
    if (param_2 == 0) {
      return *(undefined2 *)(param_1 + 0x12e);
    }
  }
  else {
    if (param_2 == 2) {
      return *(undefined2 *)(param_1 + 0x136);
    }
    if (param_2 == 3) {
      return *(undefined2 *)(param_1 + 0x13a);
    }
  }
  return 0;
}

/* FUN_001042bc @ 0x1042bc (116 bytes) */
int FUN_001042bc(param_1, param_2)
  int *param_1;
  int param_2;
{
  char cVar1;
  int iVar2;
  int loopIndex;
  char *pcVar4;
  
  pcVar4 = (char *)((int)param_1 + param_2 + 0xb4);
  loopIndex = 1;
  while( true ) {
    iVar2 = (**(code **)(*param_1 + 0x14))(param_1);
    if (iVar2 < loopIndex) {
      return -1;
    }
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 0x18;
    if (cVar1 != '\x04') break;
    loopIndex = loopIndex + 1;
  }
  return loopIndex;
}

/* IRVertexFetch__initSemantics @ 0x104330 (52 bytes) */
int IRVertexFetch__initSemantics(param_1)
  int param_1;
{
  *(undefined4 *)(param_1 + 0xac) = 0;
  *(undefined4 *)(param_1 + 0x98) = 0;
  *(undefined4 *)(param_1 + 0xb0) = 0x1f;
  *(undefined4 *)(param_1 + 0x9c) = DAT_001af9c0;
  return;
}

/* FUN_00104364 @ 0x104364 (24 bytes) */
int FUN_00104364(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 *param_2;
  undefined4 *param_3;
  undefined4 *param_4;
{
  *param_2 = 0;
  *param_3 = 0;
  *param_4 = 4;
  return;
}

/* IRInst__vslot28_hasFlag0x4000AndClass0x24 @ 0x10437c (36 bytes) */
int IRInst__vslot28_hasFlag0x4000AndClass0x24(this, param_2)
  int this;
  int param_2;
{
  if (((*(uint *)(param_2 + 0x30) & 0x4000) != 0) && (*(int *)(this + 0x98) == 0x24)) {
    return 1;
  }
  return 0;
}

/* FUN_001043a0 @ 0x1043a0 (80 bytes) */
int FUN_001043a0()
{
  int iVar1;
  int *piVar2;
  int loopIndex;
  int iVar4;
  
  loopIndex = 0;
  iVar4 = 0x15;
  piVar2 = &DAT_001ea500;
  do {
    iVar1 = *piVar2;
    piVar2 = piVar2 + 2;
    if (iVar1 != loopIndex) {
      return 0;
    }
    loopIndex = loopIndex + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return 1;
}

/* IRInst__create @ 0x1043f0 (108 bytes) */
int IRInst__create(opcode, compiler)
  undefined4 opcode;
  undefined4 compiler;
{
  int inst;
  undefined4 opcodeInfo;
  
  inst = OpcodeTraits__getInstClass(opcode,compiler);
  inst = (**(code **)(&DAT_001ea4fc + inst * 8))(opcode,compiler);
  opcodeInfo = Opcode__getInfo(opcode);
  *(undefined4 *)(inst + 0x88) = opcodeInfo;
  return inst;
}

/* IRInst__clone @ 0x10445c (132 bytes) */
int IRInst__clone(srcInst, compiler, keepId)
  undefined4 srcInst;
  int compiler;
  int keepId;
{
  int newId;
  undefined4 *newBlock;
  
  newBlock = (undefined4 *)Arena__alloc(*(undefined4 *)(compiler + COMP_arenaA),0x168);
  *newBlock = *(undefined4 *)(compiler + COMP_arenaA);
  _memcpy(newBlock + 1,srcInst,0x164);
  if (keepId == 0) {
    newId = *(int *)(compiler + COMP_nextInstId);
    newBlock[0x54] = newId;
    *(int *)(compiler + COMP_nextInstId) = newId + 1;
  }
  newBlock[0x57] = 0;
  newBlock[3] = 0;
  newBlock[2] = 0;
  return newBlock + 1;
}

/* FUN_001044e0 @ 0x1044e0 (60 bytes) */
int FUN_001044e0(param_1, param_2, compiler)
  int param_1;
  undefined4 param_2;
  int compiler;
{
  Arena__free(*(undefined4 *)(compiler + COMP_arenaA),*(undefined4 *)(param_1 + 0x13c));
  *(undefined4 *)(param_1 + 0x13c) = param_2;
  return;
}

/* FUN_0010453c @ 0x10453c (168 bytes) */
int FUN_0010453c(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  unsigned int ghidra_home[8] = { param_1, param_2, param_3, param_4, param_5, param_6, param_7, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  byte *pbVar4;
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 8)) = param_3;
  if (*(int *)(param_1 + 0x98) == 0x33) {
    pbVar4 = (byte *)&(*(unsigned int *)((unsigned char *)ghidra_home + 8));
    do {
      uVar1 = (uint)*pbVar4;
      if ((uVar1 != 4) &&
         ((((int)*(char *)(param_1 + 0x15c) >> (uVar1 & 0x3f) & 1U) == 0 ||
          (iVar2 = (**(code **)(**(int **)(param_2 + 0x30c) + 0xf0))
                             ((double)*(float *)(uVar1 * 0x18 + param_1 + 0x20)), iVar2 == 0))))
      goto LAB_001045cc;
      pbVar4 = pbVar4 + 1;
    } while (pbVar4 != &(*(unsigned int *)((unsigned char *)ghidra_home + 12)));
    uVar3 = 1;
  }
  else {
LAB_001045cc:
    uVar3 = 0;
  }
  return uVar3;
}

/* IRInst__isProjectionOfClass26or3a @ 0x1045e4 (96 bytes) */
int IRInst__isProjectionOfClass26or3a(param_1)
  int *param_1;
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*param_1 + 0x54))(param_1);
  uVar2 = 0;
  if ((iVar1 != 0) && ((param_1[0x26] == 0x26 || (param_1[0x26] == 0x3a)))) {
    uVar2 = 1;
  }
  return uVar2;
}

/* IRInst__isProjectionOfClass44 @ 0x104644 (88 bytes) */
int IRInst__isProjectionOfClass44(param_1)
  int *param_1;
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*param_1 + 0x54))(param_1);
  if ((iVar1 == 0) || (uVar2 = 1, param_1[0x26] != 0x44)) {
    uVar2 = 0;
  }
  return uVar2;
}

/* IRInst__setHardwareRegisterAndAdd @ 0x10469c (44 bytes) */
int IRInst__setHardwareRegisterAndAdd(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  *(undefined4 *)(param_1 + 0x94) = param_4;
  *(undefined4 *)(param_1 + 0x98) = param_3;
  *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 0x42;
  *(undefined4 *)(param_1 + 0x80) = 0;
  return Program__addInst(param_2,param_1);
}

/* IRInst__setOperandRef @ 0x1046c8 (104 bytes) */
int IRInst__setOperandRef(inst, operandIndex, operandRef)
  int inst;
  int operandIndex;
  int *operandRef;
{
  int refWord2;
  int record;
  undefined4 destKind;
  
  record = operandIndex * 0x18 + inst;
  *(int *)(record + 0x98) = operandRef[1];
  refWord2 = operandRef[2];
  *(int **)(record + 0x8c) = operandRef;
  *(int *)(record + 0x94) = refWord2;
  if (operandIndex == 0) {
    destKind = (**(code **)(*operandRef + 0x24))(operandRef);
    *(undefined4 *)(inst + 0x128) = destKind;
  }
  return;
}

/* IROperand__copyFrom @ 0x104730 (120 bytes) */
int IROperand__copyFrom(param_1, param_2)
  undefined4 *param_1;
  undefined4 *param_2;
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  ((int (*)())IROperand__setModifierBits)(param_1,1,param_2[5] & 1);
  ((int (*)())IROperand__setModifierBits)(param_1,2,(uint)param_2[5] >> 1 & 1);
  uVar1 = *param_2;
  uVar2 = param_2[1];
  uVar4 = param_2[2];
  uVar3 = param_2[3];
  param_1[4] = param_2[4];
  *param_1 = uVar1;
  param_1[1] = uVar2;
  param_1[2] = uVar4;
  param_1[3] = uVar3;
  return;
}

/* FUN_001047a8 @ 0x1047a8 (88 bytes) */
int FUN_001047a8(param_1, param_2)
  int param_1;
  int param_2;
{
  ((int (*)())IROperand__setModifierBits)(param_1,1,*(uint *)(param_2 + 0x14) & 1);
  ((int (*)())IROperand__setModifierBits)(param_1,2,*(uint *)(param_2 + 0x14) >> 1 & 1);
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_2 + 0x10);
  return;
}

/* FUN_00104800 @ 0x104800 (92 bytes) */
int FUN_00104800(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0x158) != *(int *)(param_2 + 0x158)) {
    uVar2 = FUN_000e78f8(*(int *)(param_1 + 0x158),*(int *)(param_2 + 0x158));
    return uVar2;
  }
  if (param_1 != param_2) {
    iVar1 = *(int *)(param_2 + 4);
    while( true ) {
      if (iVar1 == 0) {
        return 0;
      }
      if (param_1 == iVar1) break;
      iVar1 = *(int *)(iVar1 + 4);
    }
  }
  return 1;
}

/* Inst__nearestCommonAncestorBlock @ 0x10485c (120 bytes) */
int Inst__nearestCommonAncestorBlock(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = ((int (*)())FUN_00104800)(param_1,param_2);
  iVar3 = param_1;
  if ((iVar1 == 0) && (iVar1 = ((int (*)())FUN_00104800)(param_2,param_1), iVar3 = param_2, iVar1 == 0)) {
    uVar2 = Block__nearestCommonAncestor(*(undefined4 *)(param_1 + 0x158),*(undefined4 *)(param_2 + 0x158));
    iVar3 = Block__resolveRedirect(uVar2);
    return iVar3;
  }
  return iVar3;
}

/* FUN_001048d4 @ 0x1048d4 (56 bytes) */
void FUN_001048d4(int param_1,double fparam_1)
{
  undefined2 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x13c);
  uVar1 = ((int (*)())FUN_00103d78)(param_1,3,4,fparam_1);
  *(undefined2 *)(iVar2 + 0x18) = uVar1;
  return;
}

/* FUN_0010490c @ 0x10490c (56 bytes) */
void FUN_0010490c(int param_1,double fparam_1)
{
  undefined2 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x13c);
  uVar1 = ((int (*)())FUN_00103d78)(param_1,3,4,fparam_1);
  *(undefined2 *)(iVar2 + 0x18) = uVar1;
  return;
}

/* FUN_00104944 @ 0x104944 (56 bytes) */
void FUN_00104944(int param_1,double fparam_1)
{
  undefined2 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x13c);
  uVar1 = ((int (*)())FUN_00103d78)(param_1,3,4,fparam_1);
  *(undefined2 *)(iVar2 + 0x18) = uVar1;
  return;
}

/* IRInst__hasSingleUse @ 0x10497c (36 bytes) */
int IRInst__hasSingleUse(obj, program)
  int obj;
  int program;
{
  int useCount;
  
  useCount = *(int *)(obj + 0x160) - *(int *)(program + PROG_useEpoch);
  if (useCount < 0) {
    useCount = 0;
  }
  return useCount == 1;
}

/* FUN_001049a0 @ 0x1049a0 (36 bytes) */
int FUN_001049a0(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x160) - *(int *)(param_2 + 0x478);
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  return iVar1 == 2;
}

/* FUN_001049c4 @ 0x1049c4 (36 bytes) */
int FUN_001049c4(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  return *(int *)(param_1 + 0x160) - *(int *)(param_2 + 0x478) < 0 ||
         *(int *)(param_1 + 0x160) == *(int *)(param_2 + 0x478);
}

/* IRInst__appendSource @ 0x1049e8 (172 bytes) */
int IRInst__appendSource(inst, operandRef)
  int *inst;
  int operandRef;
{
  int flagsAddr;
  int oldCount;
  int newCount;
  int virtualCallResult;
  
  oldCount = inst[0x21];
  ((int (*)())IRInst__setOperandRef)(inst,oldCount + 1,operandRef);
  newCount = inst[0x21];
  inst[0x21] = newCount + 1;
  if (((0 < inst[0x20]) && (operandRef == inst[0x23])) &&
     (virtualCallResult = (**(code **)(*inst + 0x14))(inst), flagsAddr = DAT_001af9bc, virtualCallResult < newCount + 1)) {
    inst[5] = inst[5] | 0x200;
    inst[(oldCount + 1) * 6 + 0x27] = flagsAddr;
  }
  return;
}

/* FUN_00104a94 @ 0x104a94 (80 bytes) */
int FUN_00104a94(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_2 == 1) {
    return *(undefined1 *)(param_1 + 0x130);
  }
  if (param_2 < 2) {
    if (param_2 == 0) {
      return *(undefined1 *)(param_1 + 300);
    }
  }
  else {
    if (param_2 == 2) {
      return *(undefined1 *)(param_1 + 0x134);
    }
    if (param_2 == 3) {
      return *(undefined1 *)(param_1 + 0x138);
    }
  }
  return 0;
}

/* FUN_00104ae4 @ 0x104ae4 (136 bytes) */
int FUN_00104ae4(param_1, param_2)
  undefined1 *param_1;
  undefined4 param_2;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  
  iVar3 = 0;
  puVar4 = param_1;
  do {
    iVar2 = ((int (*)())FUN_00104a94)(param_2,iVar3);
    if (iVar2 == 1) {
      *puVar4 = 5;
    }
    else if (iVar2 == 2) {
      *puVar4 = 6;
    }
    else {
      *puVar4 = 4;
    }
    bVar1 = iVar3 != 3;
    puVar4 = puVar4 + 1;
    iVar3 = iVar3 + 1;
  } while (bVar1);
  return param_1;
}

/* FUN_00104b6c @ 0x104b6c (80 bytes) */
int FUN_00104b6c(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_2 == 1) {
    return *(undefined1 *)(param_1 + 0x131);
  }
  if (param_2 < 2) {
    if (param_2 == 0) {
      return *(undefined1 *)(param_1 + 0x12d);
    }
  }
  else {
    if (param_2 == 2) {
      return *(undefined1 *)(param_1 + 0x135);
    }
    if (param_2 == 3) {
      return *(undefined1 *)(param_1 + 0x139);
    }
  }
  return 0;
}

/* IROperand__init @ 0x104bbc (44 bytes) */
int IROperand__init(param_1)
  undefined4 *param_1;
{
  param_1[3] = 0x46;
  param_1[5] = param_1[5] & 0xfffffffc;
  param_1[1] = 0;
  param_1[2] = 0xffffffff;
  *param_1 = 0;
  return;
}

/* FUN_00104be8 @ 0x104be8 (16 bytes) */
int FUN_00104be8(inst, param_2)
  int inst;
  int param_2;
{
  return ((int (*)())IROperand__init)(param_2 * 0x18 + inst + 0x8c);
}

/* FUN_00104bf8 @ 0x104bf8 (324 bytes) */
int FUN_00104bf8(inst, compiler)
  int inst;
  undefined4 compiler;
{
  int loopIndex;
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  int instFlagBit2Result;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  
  *(undefined4 *)(inst + 0x11c) = 0;
  *(undefined4 *)(inst + 0x80) = 0;
  *(undefined4 *)(inst + 0x84) = 0;
  *(undefined4 *)(inst + 0x10) = 0;
  ((int (*)())FUN_00104be8)(inst,0);
  uVar3 = DAT_001af9bc;
  *(undefined4 *)(inst + 0x9c) = DAT_001af9c0;
  *(undefined4 *)(inst + 0x154) = uVar3;
  *(undefined4 *)(inst + 0xc) = 0;
  loopIndex = 1;
  iVar8 = inst;
  do {
    ((int (*)())FUN_00104be8)(inst,loopIndex);
    *(undefined4 *)(iVar8 + 0xb4) = DAT_001af9bc;
    instFlagBit2Result = OpcodeTraits__instFlagBit2(compiler,inst);
    if (instFlagBit2Result != 0) {
      if (loopIndex == 1) {
        puVar5 = &DAT_001af9d0;
      }
      else {
        puVar5 = &DAT_001af9cc;
      }
      *(undefined4 *)(iVar8 + 0xb4) = *puVar5;
    }
    bVar1 = loopIndex != 4;
    iVar8 = iVar8 + 0x18;
    loopIndex = loopIndex + 1;
  } while (bVar1);
  *(undefined4 *)(inst + 0x124) = 0;
  uVar6 = 0;
  *(undefined4 *)(inst + 0x120) = 0;
  iVar7 = 4;
  iVar8 = inst;
  do {
    *(undefined4 *)(iVar8 + 0x1c) = 0;
    uVar2 = uVar6 & 0x3f;
    *(undefined4 *)(iVar8 + 0x20) = 0;
    uVar6 = uVar6 + 1;
    iVar8 = iVar8 + 0x18;
    *(byte *)(inst + 0x15c) = *(byte *)(inst + 0x15c) & ~(byte)(1 << uVar2);
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  *(undefined4 *)(inst + 300) = 0;
  *(undefined4 *)(inst + 0x148) = 0;
  *(undefined4 *)(inst + 0x130) = 0;
  *(undefined4 *)(inst + 0x134) = 0;
  *(undefined4 *)(inst + 0x138) = 0;
  *(undefined4 *)(inst + 0x13c) = 0;
  *(undefined4 *)(inst + 0x140) = 0;
  *(undefined4 *)(inst + 0x144) = 0;
  return;
}

/* FUN_00104d3c @ 0x104d3c (44 bytes) */
int FUN_00104d3c(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined4 *)(param_2 + 4) = *(undefined4 *)(*(int *)(param_1 + 0x84) * 0x18 + param_1 + 0x90);
  *(undefined4 *)(param_2 + 0x10) =
       *(undefined4 *)(*(int *)(param_1 + 0x84) * 0x18 + param_1 + 0x9c);
  return;
}

/* FUN_00104d68 @ 0x104d68 (184 bytes) */
int FUN_00104d68(param_1, param_2)
  int *param_1;
  char *param_2;
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int loopIndex;
  int iVar5;
  
  loopIndex = 0;
  piVar3 = param_1 + 0x27;
  do {
    if (*param_2 == '\0') {
      *(undefined1 *)piVar3 = 1;
      for (iVar5 = 1; iVar2 = (**(code **)(*param_1 + 0x14))(param_1), iVar5 <= iVar2;
          iVar5 = iVar5 + 1) {
        (**(code **)(*param_1 + 0x88))(param_1,iVar5,loopIndex,4);
      }
    }
    else {
      *(undefined1 *)piVar3 = 0;
    }
    bVar1 = loopIndex != 3;
    piVar3 = (int *)((int)piVar3 + 1);
    param_2 = param_2 + 1;
    loopIndex = loopIndex + 1;
  } while (bVar1);
  return;
}

/* IRLoadConst__removeFromListEx @ 0x104e20 (196 bytes) */
int IRLoadConst__removeFromListEx(this, param_2, compiler)
  int this;
  undefined4 param_2;
  int compiler;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = *(int *)(this + 0x98);
  if (iVar1 == 0xc) {
    FUN_000f4d80(*(undefined4 *)(*(int *)(compiler + COMP_currentProgram) + 0x3ac),this);
    iVar1 = *(int *)(this + 0x98);
  }
  if ((iVar1 != 2) && (iVar1 != 0x33)) {
    iVar3 = *(int *)(this + 4);
    iVar1 = *(int *)(*(int *)(compiler + COMP_currentProgram) + 0x3a0);
    if (this == *(int *)(iVar1 + 300)) {
      *(int *)(iVar1 + 300) = iVar3;
    }
    uVar2 = *(uint *)(this + 0x14);
    if ((((uVar2 & 4) == 0) && (iVar3 != 0)) && ((*(uint *)(iVar3 + 0x14) & 4) != 0)) {
      *(uint *)(iVar3 + 0x14) = *(uint *)(iVar3 + 0x14) & 0xfffffffb;
      uVar2 = *(uint *)(this + 0x14);
    }
    *(uint *)(this + 0x14) = uVar2 & 0xfffffffe;
    DList__unlink(this);
    return;
  }
  return;
}

/* FUN_00104ee4 @ 0x104ee4 (80 bytes) */
int FUN_00104ee4(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_2 == 1) {
    return *(undefined1 *)(param_1 + 0x131);
  }
  if (param_2 < 2) {
    if (param_2 == 0) {
      return *(undefined1 *)(param_1 + 0x12d);
    }
  }
  else {
    if (param_2 == 2) {
      return *(undefined1 *)(param_1 + 0x135);
    }
    if (param_2 == 3) {
      return *(undefined1 *)(param_1 + 0x139);
    }
  }
  return 0;
}

/* FUN_00104f34 @ 0x104f34 (156 bytes) */
int FUN_00104f34(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  undefined4 opcodeInfo;
  
  if (param_2 == 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x88) + 8);
    if (iVar1 == 0x2b) {
      opcodeInfo = Opcode__getInfo(0xa6);
      *(undefined4 *)(param_1 + 0x88) = opcodeInfo;
    }
    else if (iVar1 == 99) {
      opcodeInfo = Opcode__getInfo(100);
      *(undefined4 *)(param_1 + 0x88) = opcodeInfo;
    }
  }
  else {
    iVar1 = *(int *)(*(int *)(param_1 + 0x88) + 8);
    if (iVar1 == 0xa6) {
      opcodeInfo = Opcode__getInfo(0x2b);
      *(undefined4 *)(param_1 + 0x88) = opcodeInfo;
    }
    else if (iVar1 == 100) {
      opcodeInfo = Opcode__getInfo(99);
      *(undefined4 *)(param_1 + 0x88) = opcodeInfo;
    }
  }
  return;
}

/* FUN_00104fd0 @ 0x104fd0 (92 bytes) */
int FUN_00104fd0(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x88) + 8);
  if (iVar1 < 0xae) {
    if ((0xaa < iVar1) || ((0x23 < iVar1 && ((iVar1 < 0x27 || (iVar1 == 0x9d)))))) {
      return 1;
    }
  }
  else if (0xeb < iVar1) {
    if (iVar1 < 0xef) {
      return 1;
    }
    if (iVar1 - 0xf2U < 3) {
      return 1;
    }
  }
  return 0;
}

/* IRInst__ctor_10502c @ 0x10502c (312 bytes) */
int IRInst__ctor_10502c(this, param_2, compiler)
  undefined4 *this;
  undefined4 param_2;
  int compiler;
{
  bool bVar1;
  undefined4 arena;
  undefined4 *allocation;
  int iVar4;
  
  this[0x1f] = 0;
  this[1] = 0;
  this[2] = 0;
  *this = &PTR_FUN_001e9fc8;
  iVar4 = 5;
  allocation = this + 0x23;
  do {
    *allocation = 0;
    allocation[1] = 0;
    allocation[5] = 0;
    allocation = allocation + 6;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  iVar4 = *(int *)(compiler + COMP_nextInstId);
  this[0x53] = iVar4;
  *(int *)(compiler + COMP_nextInstId) = iVar4 + 1;
  this[0x58] = 0;
  iVar4 = 0;
  this[0x54] = 0;
  this[0x56] = 0;
  *(undefined1 *)(this + 0x57) = 0;
  allocation = this;
  do {
    bVar1 = iVar4 != 1;
    allocation[5] = 0;
    iVar4 = iVar4 + 1;
    allocation = allocation + 1;
  } while (bVar1);
  arena = Opcode__getInfo(param_2);
  this[0x22] = arena;
  this[5] = this[5] | 1;
  ((int (*)())FUN_00104bf8)(this,compiler);
  (*(code *)**(undefined4 **)this[0x22])((undefined4 *)this[0x22],this,compiler);
  if ((*(uint *)(*(int *)(compiler + COMP_currentProgram) + 0x30) & 0x80) != 0) {
    arena = *(undefined4 *)(compiler + COMP_arenaB);
    allocation = (undefined4 *)Arena__alloc(arena,0x14);
    *allocation = arena;
    allocation[1] = 2;
    allocation[2] = 0;
    allocation[4] = arena;
    arena = Arena__alloc(arena,8);
    allocation[3] = arena;
    this[4] = allocation + 1;
  }
  return;
}

/* IRInst__ctor_1051b0 @ 0x1051b0 (312 bytes) */
int IRInst__ctor_1051b0(this, param_2, compiler)
  undefined4 *this;
  undefined4 param_2;
  int compiler;
{
  bool bVar1;
  undefined4 arena;
  undefined4 *allocation;
  int iVar4;
  
  this[0x1f] = 0;
  this[1] = 0;
  this[2] = 0;
  *this = &PTR_FUN_001e9fc8;
  iVar4 = 5;
  allocation = this + 0x23;
  do {
    *allocation = 0;
    allocation[1] = 0;
    allocation[5] = 0;
    allocation = allocation + 6;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  iVar4 = *(int *)(compiler + COMP_nextInstId);
  this[0x53] = iVar4;
  *(int *)(compiler + COMP_nextInstId) = iVar4 + 1;
  this[0x58] = 0;
  iVar4 = 0;
  this[0x54] = 0;
  this[0x56] = 0;
  *(undefined1 *)(this + 0x57) = 0;
  allocation = this;
  do {
    bVar1 = iVar4 != 1;
    allocation[5] = 0;
    iVar4 = iVar4 + 1;
    allocation = allocation + 1;
  } while (bVar1);
  arena = Opcode__getInfo(param_2);
  this[0x22] = arena;
  this[5] = this[5] | 1;
  ((int (*)())FUN_00104bf8)(this,compiler);
  (*(code *)**(undefined4 **)this[0x22])((undefined4 *)this[0x22],this,compiler);
  if ((*(uint *)(*(int *)(compiler + COMP_currentProgram) + 0x30) & 0x80) != 0) {
    arena = *(undefined4 *)(compiler + COMP_arenaB);
    allocation = (undefined4 *)Arena__alloc(arena,0x14);
    *allocation = arena;
    allocation[1] = 2;
    allocation[2] = 0;
    allocation[4] = arena;
    arena = Arena__alloc(arena,8);
    allocation[3] = arena;
    this[4] = allocation + 1;
  }
  return;
}

/* IRInst__setOperandSourceRaw @ 0x105334 (152 bytes) */
int IRInst__setOperandSourceRaw(inst, operandIndex, source, compiler)
  int inst;
  int operandIndex;
  undefined4 source;
  int compiler;
{
  undefined4 *allocation;
  int *piVar2;
  uint uVar3;
  undefined4 arena;
  uint uVar5;
  uint *puVar6;
  
  if (operandIndex < 5) {
    *(undefined4 *)(operandIndex * 0x18 + inst + 0x90) = source;
  }
  else {
    puVar6 = *(uint **)(inst + 0x118);
    if (puVar6 == (uint *)0x0) {
      arena = *(undefined4 *)(compiler + COMP_arenaA);
      allocation = (undefined4 *)Arena__alloc(arena,0x14);
      puVar6 = allocation + 1;
      *allocation = arena;
      allocation[1] = 2;
      allocation[2] = 0;
      allocation[4] = arena;
      arena = Arena__alloc(arena,8);
      allocation[3] = arena;
      *(uint **)(inst + 0x118) = puVar6;
    }
    if ((int)puVar6[1] < (int)(operandIndex - 4U)) {
      arena = *(undefined4 *)(compiler + COMP_arenaA);
      allocation = (undefined4 *)Arena__alloc(arena,0x1c);
      *allocation = arena;
      allocation[1] = 0;
      allocation[2] = 0;
      allocation[6] = 0;
      puVar6 = *(uint **)(inst + 0x118);
      uVar5 = puVar6[1];
      if (uVar5 < *puVar6) {
        _memset((void *)(uVar5 * 4 + puVar6[2]),0,4);
        piVar2 = (int *)(uVar5 * 4 + puVar6[2]);
        puVar6[1] = uVar5 + 1;
      }
      else {
        piVar2 = (int *)Vector__elementRefGrow(puVar6,uVar5);
      }
      *piVar2 = (int)(allocation + 1);
      ((int (*)())FUN_00103e84)(allocation + 1,operandIndex);
      puVar6 = *(uint **)(inst + 0x118);
    }
    uVar5 = operandIndex - 5;
    if (uVar5 < *puVar6) {
      uVar3 = puVar6[1];
      if (uVar3 <= uVar5) {
        _memset((void *)(uVar3 * 4 + puVar6[2]),0,(uVar5 - uVar3) * 4 + 4);
        puVar6[1] = operandIndex - 4U;
      }
      piVar2 = (int *)(uVar5 * 4 + puVar6[2]);
    }
    else {
      piVar2 = (int *)Vector__elementRefGrow(puVar6,uVar5);
    }
    *(undefined4 *)(*piVar2 + 4) = source;
  }
  return;
}

/* IRInst__getOperandRecord @ 0x1054ec (168 bytes) */
int IRInst__getOperandRecord(inst, operandIndex)
  int inst;
  int operandIndex;
{
  int record;
  uint count;
  int *elementRef;
  uint extraIndex;
  uint *vectorHeader;
  
  if (operandIndex < 5) {
    record = operandIndex * 0x18 + inst + 0x8c;
  }
  else {
    vectorHeader = *(uint **)(inst + 0x118);
    extraIndex = operandIndex - 5;
    if (extraIndex < *vectorHeader) {
      count = vectorHeader[1];
      if (count <= extraIndex) {
        _memset(count * 4 + vectorHeader[2],0,(extraIndex - count) * 4 + 4);
        vectorHeader[1] = operandIndex - 4;
      }
      elementRef = (int *)(extraIndex * 4 + vectorHeader[2]);
    }
    else {
      elementRef = (int *)Vector__elementRefGrow(vectorHeader,extraIndex);
    }
    record = *elementRef;
  }
  return record;
}

/* IRInst__getOperandSource @ 0x105594 (56 bytes) */
int IRInst__getOperandSource(inst, operandIndex)
  undefined4 inst;
  undefined4 operandIndex;
{
  int record;
  
  record = ((int (*)())IRInst__getOperandRecord)(inst,operandIndex);
  if ((record == 0) || (record = *(int *)(record + 4), record == 0)) {
    record = 0;
  }
  return record;
}

/* FUN_001055cc @ 0x1055cc (128 bytes) */
int FUN_001055cc(param_1)
  int *param_1;
{
  int operandSource;
  int iVar1;
  bool bVar2;
  
  iVar1 = (**(code **)(*param_1 + 0x54))(param_1);
  bVar2 = false;
  if (iVar1 != 0) {
    operandSource = ((int (*)())IRInst__getOperandSource)(param_1,1);
    if (operandSource == 0) {
      bVar2 = param_1[0x2c] == 0x2a;
    }
    else {
      bVar2 = *(int *)(operandSource + 0x98) == 0x2a;
    }
  }
  return bVar2;
}


/* issue: auto-generated aliases bridging data.s/code.s references (written
 * without a leading underscore, matching the raw stock-binary symbol name)
 * against the real compiled C symbols (gcc adds one underscore automatically).
 * Needed because ld64 (required for this PPC binary's size - stock ld breaks on
 * large PPC links) does not silently reconcile this the way stock ld did. */
asm(".globl FUN_0010437c");
asm(".set FUN_0010437c, _IRInst__vslot28_hasFlag0x4000AndClass0x24");
asm(".globl FUN_00104e20");
asm(".set FUN_00104e20, _IRLoadConst__removeFromListEx");
