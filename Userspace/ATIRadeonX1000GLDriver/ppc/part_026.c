#include "decls.h"

/* FUN_000f4ddc @ 0xf4ddc (512 bytes) */
int FUN_000f4ddc(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  char cVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  int *piVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  int iVar10;
  uint *puVar11;
  int *piVar12;
  int iVar13;
  uint local_1d8 [4];
  undefined4 local_1c8 [4];
  undefined4 local_1b8 [24];
  int aiStack_158 [75];
  int aiStack_2c [3];
  
  _memcpy(aiStack_158,&DAT_001aa87c,300);
  cVar1 = *(char *)(param_3 + 0x15c);
  puVar9 = local_1b8;
  puVar11 = local_1d8;
  uVar4 = 0;
  iVar13 = 4;
  puVar5 = puVar11;
  puVar8 = puVar9;
  iVar10 = param_3;
  do {
    uVar2 = uVar4 & 0x3f;
    uVar7 = *(undefined4 *)(iVar10 + 0x20);
    *puVar8 = *(undefined4 *)(iVar10 + 0x1c);
    uVar4 = uVar4 + 1;
    puVar8[1] = uVar7;
    iVar10 = iVar10 + 0x18;
    *puVar5 = (int)cVar1 >> uVar2 & 1;
    puVar8 = puVar8 + 6;
    puVar5 = puVar5 + 1;
    iVar13 = iVar13 + -1;
  } while (iVar13 != 0);
  local_1c8[0] = *(undefined4 *)(param_1 + 8);
  local_1c8[1] = *(undefined4 *)(param_1 + 0xc);
  local_1c8[2] = *(undefined4 *)(param_1 + 0x10);
  local_1c8[3] = *(undefined4 *)(param_1 + 0x14);
  if (*(int *)(&DAT_001aa86c + (4 - param_2) * 4) < 0xf) {
    piVar12 = aiStack_158 + *(int *)(&DAT_001aa86c + (4 - param_2) * 4) * 5;
    do {
      iVar13 = 4;
      uVar4 = 0;
      piVar6 = piVar12;
      iVar10 = param_3;
      do {
        iVar3 = piVar6[1];
        if (iVar3 < 0) {
          *(undefined4 *)(iVar10 + 0x1c) = 0;
          *(undefined4 *)(iVar10 + 0x20) = 0;
          *(byte *)(param_3 + 0x15c) = *(byte *)(param_3 + 0x15c) & ~(byte)(1 << (uVar4 & 0x3f));
        }
        else {
          uVar7 = local_1b8[iVar3 * 6];
          *(undefined4 *)(iVar10 + 0x20) = local_1b8[iVar3 * 6 + 1];
          *(undefined4 *)(iVar10 + 0x1c) = uVar7;
          *(byte *)(param_3 + 0x15c) = (byte)(1 << (uVar4 & 0x3f)) | *(byte *)(param_3 + 0x15c);
        }
        uVar4 = uVar4 + 1;
        piVar6 = piVar6 + 1;
        iVar10 = iVar10 + 0x18;
        iVar13 = iVar13 + -1;
      } while (iVar13 != 0);
      iVar10 = *piVar12;
      piVar12 = piVar12 + 5;
      HashTable__insert(local_1c8[iVar10],param_3);
    } while (piVar12 != aiStack_2c);
  }
  iVar13 = 4;
  uVar4 = 0;
  iVar10 = param_3;
  do {
    uVar7 = puVar9[1];
    *(undefined4 *)(iVar10 + 0x1c) = *puVar9;
    *(undefined4 *)(iVar10 + 0x20) = uVar7;
    uVar2 = *puVar11;
    puVar11 = puVar11 + 1;
    if (uVar2 == 0) {
      *(byte *)(param_3 + 0x15c) = *(byte *)(param_3 + 0x15c) & ~(byte)(1 << (uVar4 & 0x3f));
    }
    else {
      *(byte *)(param_3 + 0x15c) = (byte)(1 << (uVar4 & 0x3f)) | *(byte *)(param_3 + 0x15c);
    }
    uVar4 = uVar4 + 1;
    puVar9 = puVar9 + 6;
    iVar10 = iVar10 + 0x18;
    iVar13 = iVar13 + -1;
  } while (iVar13 != 0);
  return;
}

/* Compiler__getOrCreateLoadConstN @ 0xf4fdc (352 bytes) */
int Compiler__getOrCreateLoadConstN(compiler, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int *compiler;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  undefined4 arena;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *allocation;
  int *piVar5;
  undefined4 *puVar6;
  int iVar7;
  uint loopIndex;
  int iVar9;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  /* issue #64 live-repro: same defect as Compiler__getOrCreateConstVectorN in this file (fixed earlier this session) -
   * called below as aiStack_9c[param_2] with param_2 observed as 4, one past this array's declared
   * 4 elements; local_8c (assigned right after, from compiler[5]) sits exactly at the missing 5th
   * index by its own hex offset (0x9c-0x8c=0x10). Extended to 5 elements; local_8c aliased to
   * index 4. */
  int aiStack_9c [5];
#define local_8c aiStack_9c[4]
  undefined4 local_88 [29];
  
  aiStack_9c[1] = compiler[2];
  aiStack_9c[2] = compiler[3];
  iVar9 = 4;
  iVar7 = 0;
  loopIndex = 0;
  local_88[0] = param_3;
  local_88[1] = param_4;
  aiStack_9c[3] = compiler[4];
  local_8c = compiler[5];
  puVar6 = local_88;
  do {
    if ((int)loopIndex < param_2) {
      *(byte *)(compiler[10] + 0x15c) = (byte)(1 << (loopIndex & 0x3f)) | *(byte *)(compiler[10] + 0x15c);
      arena = *(undefined4 *)((int)puVar6 + iVar7);
      iVar2 = iVar7 + 0x10 + compiler[10];
      *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)((int)local_88 + iVar7 + 4);
      *(undefined4 *)(iVar2 + 0xc) = arena;
    }
    else {
      *(byte *)(compiler[10] + 0x15c) = *(byte *)(compiler[10] + 0x15c) & ~(byte)(1 << (loopIndex & 0x3f))
      ;
    }
    loopIndex = loopIndex + 1;
    iVar7 = iVar7 + 0x18;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  uStack00000020 = param_3;
  uStack00000024 = param_4;
  uStack00000028 = param_5;
  uStack0000002c = param_6;
  uStack00000030 = param_7;
  uStack00000034 = param_8;
  puVar3 = (undefined4 *)HashTable__find(aiStack_9c[param_2],compiler[10]);
  if (puVar3 == (undefined4 *)0x0) {
    arena = *(undefined4 *)(*compiler + 0x374);
    allocation = (undefined4 *)Arena__alloc(arena,0x168);
    *allocation = arena;
    puVar3 = allocation + 1;
    IRLoadConst__ctor_109938(puVar3,*compiler);
    if ((*(uint *)(*(int *)(*compiler + 0x6c4) + 0x30) & 0x10000) == 0) {
      arena = FUN_000f4a5c(compiler);
      allocation[0x26] = arena;
      allocation[0x27] = 0xc;
    }
    else {
      arena = FUN_000f4a84(compiler,local_88[0],0,puVar6,iVar7,loopIndex,*compiler);
      allocation[0x26] = arena;
      allocation[0x27] = 0xc;
    }
    loopIndex = 0;
    iVar9 = 4;
    puVar6 = allocation + 5;
    iVar7 = 0;
    do {
      if ((int)loopIndex < param_2) {
        *(byte *)(allocation + 0x58) = (byte)(1 << (loopIndex & 0x3f)) | *(byte *)(allocation + 0x58);
        arena = *(undefined4 *)((int)local_88 + iVar7);
        puVar6[4] = *(undefined4 *)((int)local_88 + iVar7 + 4);
        puVar6[3] = arena;
      }
      else {
        *(byte *)(allocation + 0x58) = *(byte *)(allocation + 0x58) & ~(byte)(1 << (loopIndex & 0x3f));
      }
      loopIndex = loopIndex + 1;
      iVar7 = iVar7 + 0x18;
      puVar6 = puVar6 + 6;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    piVar5 = *(int **)(*(int *)(*compiler + 0x6c4) + 0x3a0);
    (**(code **)(*piVar5 + 0xc))(piVar5,puVar3);
    ((int (*)())FUN_000f4ddc)(compiler,param_2,puVar3);
  }
  return puVar3;
}
#undef local_8c

/* FUN_000f5248 @ 0xf5248 (376 bytes) */
int FUN_000f5248(compiler, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 compiler;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  undefined4 uVar1;
  undefined4 uStack0000001c;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  
  uStack0000001c = param_2;
  uStack00000020 = param_3;
  uStack00000024 = param_4;
  uStack00000028 = param_5;
  uStack0000002c = param_6;
  uStack00000030 = param_7;
  uStack00000034 = param_8;
  uVar1 = ((int (*)())Compiler__getOrCreateLoadConstN)(compiler,4,param_2,param_3,param_4,param_5,param_6,param_7);
  return uVar1;
}

/* Compiler__getOrCreateLoadConst3 @ 0xf53c0 (396 bytes) */
int Compiler__getOrCreateLoadConst3(compiler, operandWord0, operandWord1, operandWord2, operandWord3, operandWord4, operandWord5, operandWord6)
  undefined4 compiler;
  undefined4 operandWord0;
  undefined4 operandWord1;
  undefined4 operandWord2;
  undefined4 operandWord3;
  undefined4 operandWord4;
  undefined4 operandWord5;
  undefined4 operandWord6;
{
  undefined4 operandWord0Home;
  undefined4 operandWord1Home;
  undefined4 operandWord2Home;
  undefined4 operandWord3Home;
  undefined4 operandWord4Home;
  undefined4 operandWord5Home;
  undefined4 operandWord6Home;
  
  operandWord0Home = operandWord0;
  operandWord1Home = operandWord1;
  operandWord2Home = operandWord2;
  operandWord3Home = operandWord3;
  operandWord4Home = operandWord4;
  operandWord5Home = operandWord5;
  operandWord6Home = operandWord6;
  return ((int (*)())Compiler__getOrCreateLoadConstN)(compiler,3,operandWord0,operandWord1,operandWord2,operandWord3,operandWord4,operandWord5);
}

/* Compiler__getOrCreateLoadConst2 @ 0xf554c (352 bytes) */
int Compiler__getOrCreateLoadConst2(compiler, operandWord0, operandWord1, operandWord2, operandWord3, operandWord4, operandWord5, operandWord6)
  undefined4 compiler;
  undefined4 operandWord0;
  undefined4 operandWord1;
  undefined4 operandWord2;
  undefined4 operandWord3;
  undefined4 operandWord4;
  undefined4 operandWord5;
  undefined4 operandWord6;
{
  undefined4 operandWord0Home;
  undefined4 operandWord1Home;
  undefined4 operandWord2Home;
  undefined4 operandWord3Home;
  undefined4 operandWord4Home;
  undefined4 operandWord5Home;
  undefined4 operandWord6Home;
  
  operandWord0Home = operandWord0;
  operandWord1Home = operandWord1;
  operandWord2Home = operandWord2;
  operandWord3Home = operandWord3;
  operandWord4Home = operandWord4;
  operandWord5Home = operandWord5;
  operandWord6Home = operandWord6;
  return ((int (*)())Compiler__getOrCreateLoadConstN)(compiler,2,operandWord0,operandWord1,operandWord2,operandWord3,operandWord4,operandWord5);
}

/* Compiler__getOrCreateLoadConst1 @ 0xf56ac (324 bytes) */
int Compiler__getOrCreateLoadConst1(compiler, operandWord0, operandWord1, operandWord2, operandWord3, operandWord4, operandWord5)
  undefined4 compiler;
  undefined4 operandWord0;
  undefined4 operandWord1;
  undefined4 operandWord2;
  undefined4 operandWord3;
  undefined4 operandWord4;
  undefined4 operandWord5;
{
  undefined4 operandWord0Home;
  undefined4 operandWord1Home;
  undefined4 operandWord2Home;
  undefined4 operandWord3Home;
  undefined4 operandWord4Home;
  undefined4 operandWord5Home;
  
  operandWord0Home = operandWord0;
  operandWord1Home = operandWord1;
  operandWord2Home = operandWord2;
  operandWord3Home = operandWord3;
  operandWord4Home = operandWord4;
  operandWord5Home = operandWord5;
  return ((int (*)())Compiler__getOrCreateLoadConstN)(compiler,1,operandWord0,operandWord1,operandWord2,operandWord3,operandWord4,operandWord5);
}

/* FUN_000f57f0 @ 0xf57f0 (540 bytes) */
int FUN_000f57f0(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  char *param_3;
  undefined4 param_4;
{
  bool bVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  char *pcVar7;
  uint loopIndex;
  uint *puVar9;
  int iVar10;
  int iVar11;
  undefined4 local_38 [8];
  
  if (param_1[7] != 0) {
    loopIndex = 0;
    do {
      puVar9 = (uint *)param_1[8];
      if (loopIndex < *puVar9) {
        uVar4 = puVar9[1];
        if (uVar4 <= loopIndex) {
          _memset(uVar4 * 4 + puVar9[2],0,(loopIndex - uVar4) * 4 + 4);
          puVar9[1] = loopIndex + 1;
        }
        piVar5 = (int *)(loopIndex * 4 + puVar9[2]);
      }
      else {
        piVar5 = (int *)Vector__elementRefGrow(puVar9,loopIndex);
      }
      iVar10 = *piVar5;
      iVar6 = 0;
      pcVar7 = param_3;
      do {
        if (*pcVar7 != '\x04') {
          uVar4 = 0;
          iVar11 = 4;
          iVar3 = iVar10;
          while (((((int)*(char *)(iVar10 + 0x15c) >> (uVar4 & 0x3f) & 1U) == 0 ||
                  (*(int *)(iVar3 + 0x1c) != 2)) ||
                 (*(float *)(iVar3 + 0x20) != *(float *)(param_2 + iVar6)))) {
            uVar4 = uVar4 + 1;
            iVar3 = iVar3 + 0x18;
            iVar11 = iVar11 + -1;
            if (iVar11 == 0) goto LAB_000f59bc;
          }
        }
        bVar1 = iVar6 != 0xc;
        pcVar7 = pcVar7 + 1;
        iVar6 = iVar6 + 4;
      } while (bVar1);
      iVar6 = 0;
      local_38[0] = *(undefined4 *)param_3;
      pcVar7 = param_3;
      do {
        uVar4 = (uint)*(byte *)((int)local_38 + iVar6);
        if (((uVar4 != 4) && (((int)*(char *)(iVar10 + 0x15c) >> (uVar4 & 0x3f) & 1U) != 0)) &&
           (fVar2 = *(float *)(param_2 + iVar6 * 4),
           *(float *)(uVar4 * 0x18 + iVar10 + 0x20) != fVar2)) {
          iVar11 = 4;
          uVar4 = 0;
          iVar3 = iVar10;
          do {
            if (((((int)*(char *)(iVar10 + 0x15c) >> (uVar4 & 0x3f) & 1U) != 0) &&
                (*(int *)(iVar3 + 0x1c) == 2)) && (*(float *)(iVar3 + 0x20) == fVar2)) {
              *pcVar7 = (char)uVar4;
              break;
            }
            uVar4 = uVar4 + 1;
            iVar3 = iVar3 + 0x18;
            iVar11 = iVar11 + -1;
          } while (iVar11 != 0);
        }
        bVar1 = iVar6 != 3;
        pcVar7 = pcVar7 + 1;
        iVar6 = iVar6 + 1;
      } while (bVar1);
      iVar6 = (**(code **)(**(int **)(*param_1 + 0x30c) + 0x100))
                        (*(int **)(*param_1 + 0x30c),param_3);
      if (iVar6 != 0) {
        *(undefined4 *)(iVar10 + 0x9c) = DAT_001aa860;
        return iVar10;
      }
LAB_000f59bc:
      loopIndex = loopIndex + 1;
    } while (loopIndex < (uint)param_1[7]);
  }
  return 0;
}

/* FUN_000f5a0c @ 0xf5a0c (512 bytes) */
int FUN_000f5a0c(inst, operandIndex, inst2, param_4)
  int inst;
  int operandIndex;
  undefined4 inst2;
  int param_4;
{
  int operandRecord;
  int sourceDef;
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  double dVar9;
  
  iVar3 = FUN_0011379c(*(undefined4 *)(param_4 + 8),inst2);
  if (iVar3 == 0) goto LAB_000f5a8c;
  uVar2 = *(uint *)(operandIndex * 0x18 + inst + 0xa0) & 1;
  IRInst__getOperandRecord(inst2,0);
  sourceDef = IRInst__getOperandSource(inst,operandIndex);
  iVar3 = *(int *)(sourceDef + 0x98);
  if (iVar3 == 0xc) {
LAB_000f5b30:
    sourceDef = IRInst__getOperandSource(inst,operandIndex);
    piVar7 = *(int **)(*(int *)(param_4 + 8) + 0x30c);
    iVar8 = 0;
    do {
      operandRecord = IRInst__getOperandRecord(inst2,0);
      if (*(char *)(iVar8 + operandRecord + 0x10) != '\x01') {
        operandRecord = IRInst__getOperandRecord(inst,operandIndex);
        uVar6 = (uint)*(byte *)(iVar8 + operandRecord + 0x10);
        if (uVar6 != 4) {
          if (((int)*(char *)(sourceDef + 0x15c) >> (uVar6 & 0x3f) & 1U) == 0) goto LAB_000f5a8c;
          if (uVar2 == 0) {
            dVar9 = (double)*(float *)(uVar6 * 0x18 + sourceDef + 0x20);
          }
          else {
            dVar9 = -(double)*(float *)(uVar6 * 0x18 + sourceDef + 0x20);
          }
          iVar5 = (**(code **)(*piVar7 + 0xf0))(dVar9,piVar7);
          if (iVar5 == 0) goto LAB_000f5a8c;
        }
      }
      bVar1 = iVar8 != 3;
      iVar8 = iVar8 + 1;
    } while (bVar1);
LAB_000f5b28:
    uVar4 = 1;
  }
  else {
    if (iVar3 == 0x33) {
      if (uVar2 == 0) {
        sourceDef = IRInst__getOperandSource(inst,operandIndex);
        iVar8 = 0;
        piVar7 = *(int **)(*(int *)(param_4 + 8) + 0x30c);
        do {
          operandRecord = IRInst__getOperandRecord(inst2,0);
          if (*(char *)(iVar8 + operandRecord + 0x10) != '\x01') {
            iVar5 = IRInst__getOperandRecord(inst,operandIndex);
            uVar2 = (uint)*(byte *)(iVar8 + iVar5 + 0x10);
            if ((uVar2 != 4) &&
               (iVar5 = (**(code **)(*piVar7 + 0xf0))
                                  ((double)*(float *)(uVar2 * 0x18 + sourceDef + 0x20),piVar7),
               iVar5 == 0)) goto LAB_000f5a8c;
          }
          bVar1 = iVar8 != 3;
          iVar8 = iVar8 + 1;
        } while (bVar1);
        goto LAB_000f5b28;
      }
    }
    else if (iVar3 == 2) goto LAB_000f5b30;
LAB_000f5a8c:
    uVar4 = 0;
  }
  return uVar4;
}

/* IRInst__sourceMatchesConstant @ 0xf5c0c (228 bytes) */
int IRInst__sourceMatchesConstant(inst, operandIndex, param_3, param_4)
  undefined4 inst;
  undefined4 operandIndex;
  undefined4 param_3;
  int *param_4;
{
  unsigned int ghidra_home[8] = { inst, operandIndex, param_3, param_4, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  uint uVar1;
  int *a0;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  undefined4 local_38 [9];
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 8)) = param_3;
  a0 = (int *)IRInst__getOperandSource(inst,operandIndex);
  iVar2 = (**(code **)(*a0 + 0x48))(a0);
  if (iVar2 == 0) {
LAB_000f5cd8:
    uVar3 = 0;
  }
  else {
    iVar2 = IRInst__getOperandRecord(inst,operandIndex);
    iVar4 = 0;
    pcVar5 = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 8));
    local_38[0] = *(undefined4 *)(iVar2 + 0x10);
    iVar2 = 4;
    do {
      if (((*pcVar5 == '\0') && (uVar1 = (uint)*(byte *)((int)local_38 + iVar4), uVar1 < 4)) &&
         ((((int)*(char *)(a0 + 0x57) >> (uVar1 & 0x3f) & 1U) == 0 ||
          (a0[uVar1 * 6 + 8] != *param_4)))) goto LAB_000f5cd8;
      iVar4 = iVar4 + 1;
      pcVar5 = pcVar5 + 1;
      param_4 = param_4 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    uVar3 = 1;
  }
  return uVar3;
}

/* IRInst__getUniformSourceConstant @ 0xf5cf0 (412 bytes) */
int IRInst__getUniformSourceConstant(inst, srcIndex, laneMask, outConst)
  int inst;
  int srcIndex;
  undefined4 laneMask;
  int *outConst;
{
  int lanesLeft;
  int srcRecord;
  unsigned int ghidra_home[8] = { inst, srcIndex, laneMask, outConst, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  bool foundLane;
  int *a0;
  int isConstant;
  int lane;
  char *laneMaskCursor;
  uint readComponent;
  undefined4 srcSelectWord;
  int constKind;
  int laneValueBits;
  int laneWord9;
  int laneWord10;
  int laneWord11;
  int laneWord12;
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 8)) = laneMask;
  a0 = (int *)IRInst__getOperandSource(inst,srcIndex);
  isConstant = (**(code **)(*a0 + 0x48))(a0);
  if (isConstant != 0) {
    srcRecord = IRInst__getOperandRecord(inst,srcIndex);
    foundLane = false;
    lane = 0;
    laneMaskCursor = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 8));
    srcSelectWord = *(undefined4 *)(srcRecord + 0x10);
    lanesLeft = 4;
    do {
      if ((*laneMaskCursor == '\0') && (readComponent = (uint)*(byte *)((int)&srcSelectWord + lane), readComponent < 4)) {
        laneValueBits = a0[readComponent * 6 + 8];
        laneWord9 = a0[readComponent * 6 + 9];
        laneWord10 = a0[readComponent * 6 + 10];
        constKind = a0[readComponent * 6 + 7];
        laneWord12 = a0[readComponent * 6 + 0xc];
        laneWord11 = a0[readComponent * 6 + 0xb];
        if (a0[readComponent * 6 + 7] != 2) {
          return 0;
        }
        if (((int)*(char *)(a0 + 0x57) >> (readComponent & 0x3f) & 1U) == 0) {
          return 0;
        }
        if (foundLane) {
          if (*outConst != 2) {
            return 0;
          }
          if (laneValueBits != outConst[1]) {
            return 0;
          }
          foundLane = true;
        }
        else {
          foundLane = true;
          *outConst = 2;
          outConst[1] = laneValueBits;
        }
      }
      lane = lane + 1;
      laneMaskCursor = laneMaskCursor + 1;
      lanesLeft = lanesLeft + -1;
    } while (lanesLeft != 0);
    if (foundLane) {
      if (((*(uint *)(srcIndex * 0x18 + inst + 0xa0) & 2) != 0) && (GH_U2F((unsigned int)(outConst[1])) < 0.0)) {
        outConst[1] = (int)GH_F2U((float)(-GH_U2F((unsigned int)(outConst[1]))));
      }
      if ((*(uint *)(srcIndex * 0x18 + inst + 0xa0) & 1) != 0) {
        outConst[1] = (int)GH_F2U((float)(-GH_U2F((unsigned int)(outConst[1]))));
        return 1;
      }
      return 1;
    }
  }
  return 0;
}

/* FUN_000f5e8c @ 0xf5e8c (264 bytes) */
int FUN_000f5e8c(inst, operandIndex)
  undefined4 inst;
  undefined4 operandIndex;
{
  int operandRecord;
  int *a0;
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 local_38;
  int local_34;
  float local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  
  a0 = (int *)IRInst__getOperandSource(inst,operandIndex);
  iVar1 = (**(code **)(*a0 + 0x48))(a0);
  if (iVar1 == 0) {
LAB_000f5f7c:
    uVar2 = 0;
  }
  else {
    operandRecord = IRInst__getOperandRecord(inst,operandIndex);
    iVar3 = 0;
    local_38 = *(undefined4 *)(operandRecord + 0x10);
    iVar1 = 4;
    do {
      uVar4 = (uint)*(byte *)((int)&local_38 + iVar3);
      if (uVar4 < 4) {
        local_30 = GH_U2F((unsigned int)(a0[uVar4 * 6 + 8]));
        local_2c = a0[uVar4 * 6 + 9];
        local_28 = a0[uVar4 * 6 + 10];
        local_34 = a0[uVar4 * 6 + 7];
        local_20 = a0[uVar4 * 6 + 0xc];
        local_24 = a0[uVar4 * 6 + 0xb];
        if (((a0[uVar4 * 6 + 7] != 2) || (((int)*(char *)(a0 + 0x57) >> (uVar4 & 0x3f) & 1U) == 0))
           || (GH_U2F((unsigned int)(a0[uVar4 * 6 + 8])) < 0.0)) goto LAB_000f5f7c;
      }
      iVar3 = iVar3 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    uVar2 = 1;
  }
  return uVar2;
}

/* FUN_000f5f94 @ 0xf5f94 (304 bytes) */
int FUN_000f5f94(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  byte *param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  uint loopIndex;
  uint *puVar8;
  int iVar9;
  
  if (*(int *)(param_1 + 0x1c) != 0) {
    loopIndex = 0;
    do {
      puVar8 = *(uint **)(param_1 + 0x20);
      if (loopIndex < *puVar8) {
        uVar1 = puVar8[1];
        if (uVar1 <= loopIndex) {
          _memset(uVar1 * 4 + puVar8[2],0,(loopIndex - uVar1) * 4 + 4);
          puVar8[1] = loopIndex + 1;
        }
        piVar2 = (int *)(loopIndex * 4 + puVar8[2]);
      }
      else {
        piVar2 = (int *)Vector__elementRefGrow(puVar8,loopIndex);
      }
      iVar3 = *piVar2;
      iVar9 = 4;
      iVar5 = 0;
      pbVar6 = param_3;
      while ((uVar1 = (uint)*pbVar6, uVar1 == 4 ||
             (((((int)*(char *)(iVar3 + 0x15c) >> (uVar1 & 0x3f) & 1U) != 0 &&
               (iVar4 = uVar1 * 0x18 + iVar3, *(int *)(iVar4 + 0x1c) == 2)) &&
              (*(float *)(iVar4 + 0x20) == *(float *)(iVar5 + param_2)))))) {
        pbVar6 = pbVar6 + 1;
        iVar5 = iVar5 + 4;
        iVar9 = iVar9 + -1;
        if (iVar9 == 0) {
          *(undefined4 *)(iVar3 + 0x9c) = DAT_001aa860;
          return iVar3;
        }
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex < *(uint *)(param_1 + 0x1c));
  }
  return 0;
}

/* FUN_000f60c4 @ 0xf60c4 (388 bytes) */
int FUN_000f60c4(param_1, param_2)
  int param_1;
  int param_2;
{
  bool bVar1;
  uint uVar2;
  int *piVar3;
  undefined4 uVar4;
  int operandRecord;
  undefined1 *puVar6;
  uint uVar7;
  char *pcVar8;
  undefined4 in_r9;
  undefined4 in_r10;
  uint uVar9;
  uint *puVar10;
  int iVar11;
  undefined1 auStack_b8 [148];
  
  puVar10 = *(uint **)(param_1 + 0x3c8);
  uVar2 = puVar10[1];
  uVar7 = 0;
  if (uVar2 != 0) {
    do {
      if (uVar7 < *puVar10) {
        if (uVar2 <= uVar7) {
          _memset(uVar2 * 4 + puVar10[2],0,(uVar7 - uVar2) * 4 + 4);
          puVar10[1] = uVar7 + 1;
        }
        piVar3 = (int *)(uVar7 * 4 + puVar10[2]);
      }
      else {
        piVar3 = (int *)Vector__elementRefGrow(puVar10,uVar7);
      }
      uVar9 = uVar7 + 1;
      iVar11 = *piVar3;
      if ((((*(uint *)(iVar11 + 0x14) & 1) != 0) && ((*(byte *)(iVar11 + 0x15c) & 1) != 0)) &&
         (*(int *)(iVar11 + 0x98) == 0xc)) {
        uVar2 = 0;
        uVar4 = (**(code **)(**(int **)(param_2 + 0x30c) + 0x158))
                          (*(int **)(param_2 + 0x30c),*(undefined4 *)(iVar11 + 0x94),
                           *(undefined4 *)(iVar11 + 0x1c),0,param_2);
        operandRecord = IRInst__getOperandRecord(iVar11,0);
        *(undefined4 *)(operandRecord + 8) = uVar4;
        puVar6 = *(undefined1 **)(iVar11 + 0x14c);
        uVar4 = *(undefined4 *)(iVar11 + 0x94);
        pcVar8 = "k";
        Compiler__logf(param_2,"(%d)  %d, regnum = %s[%d]: ",puVar6,uVar7,"k",uVar4,in_r9,in_r10);
        do {
          if (((int)*(char *)(iVar11 + 0x15c) >> (uVar2 & 0x3f) & 1U) == 0) break;
          puVar6 = auStack_b8;
          Compiler__logf(param_2,"  %s ",puVar6,uVar7,pcVar8,uVar4,in_r9,in_r10);
          bVar1 = uVar2 != 3;
          uVar2 = uVar2 + 1;
        } while (bVar1);
        Compiler__logf(param_2,"\n",puVar6,uVar7,pcVar8,uVar4,in_r9,in_r10);
      }
      uVar2 = puVar10[1];
      uVar7 = uVar9;
    } while (uVar9 < uVar2);
  }
  return;
}

/* Compiler__getOrCreateConstVectorN @ 0xf6248 (532 bytes) */
int Compiler__getOrCreateConstVectorN(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  int foundEntry;
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint loopIndex;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  /* issue #64 live-repro: called below as auStack_8c[param_2] with param_2 observed as 4 - one
   * past this array's declared 4 elements (indices 0-3). Confirmed in stock's own disassembly: the
   * word this 5th index reads (entry-sp-0x8c+0x10, by this array's own hex name) is the exact same
   * stack slot as local_7c (entry-sp-0x7c), which the very next line fills with a real value
   * (*(param_1+0x14)) - stock never writes a separate word for index 0 either (genuinely padding/
   * unused there), so this is the same locals-that-must-be-contiguous defect as elsewhere this
   * session, just one array cell short instead of a raw address. Left separate, auStack_8c[4] read
   * whatever unrelated word happened to follow it on this build's stack instead of local_7c's real
   * value, corrupting a callback-table lookup several frames down (HashTable__find called through a
   * garbage function pointer, jumping into stack memory as code). Extended to 5 elements; local_7c
   * aliased to index 4 so both names reach the same word. */
  undefined4 auStack_8c [5];
#define local_7c auStack_8c[4]
  undefined4 local_78 [26];
  
  auStack_8c[1] = *(undefined4 *)(param_1 + 8);
  auStack_8c[2] = *(undefined4 *)(param_1 + 0xc);
  iVar7 = 4;
  iVar4 = 0;
  loopIndex = 0;
  local_78[0] = param_3;
  local_78[1] = param_4;
  auStack_8c[3] = *(undefined4 *)(param_1 + 0x10);
  local_7c = *(undefined4 *)(param_1 + 0x14);
  do {
    if ((int)loopIndex < param_2) {
      *(byte *)(*(int *)(param_1 + 0x28) + 0x15c) =
           (byte)(1 << (loopIndex & 0x3f)) | *(byte *)(*(int *)(param_1 + 0x28) + 0x15c);
      uVar1 = *(undefined4 *)((int)local_78 + iVar4);
      iVar2 = iVar4 + 0x10 + *(int *)(param_1 + 0x28);
      *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)((int)local_78 + iVar4 + 4);
      *(undefined4 *)(iVar2 + 0xc) = uVar1;
    }
    else {
      *(byte *)(*(int *)(param_1 + 0x28) + 0x15c) =
           *(byte *)(*(int *)(param_1 + 0x28) + 0x15c) & ~(byte)(1 << (loopIndex & 0x3f));
    }
    loopIndex = loopIndex + 1;
    iVar4 = iVar4 + 0x18;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  uStack00000020 = param_3;
  uStack00000024 = param_4;
  uStack00000028 = param_5;
  uStack0000002c = param_6;
  uStack00000030 = param_7;
  uStack00000034 = param_8;
  foundEntry = HashTable__find(auStack_8c[param_2],*(undefined4 *)(param_1 + 0x28));
  if (foundEntry == 0) {
    uVar1 = FUN_000f4a5c(param_1);
    iVar4 = FUN_001275a0(param_1,0xc,uVar1,0);
    piVar3 = *(int **)(iVar4 + 0x18);
    if (*piVar3 == 0) {
      piVar3 = (int *)Vector__elementRefGrow(piVar3,0);
    }
    else {
      if (piVar3[1] == 0) {
        *(undefined4 *)piVar3[2] = 0;
        piVar3[1] = 1;
      }
      piVar3 = (int *)piVar3[2];
    }
    iVar7 = *piVar3;
    iVar8 = 4;
    loopIndex = 0;
    iVar6 = iVar7 + 0x10;
    iVar2 = 0;
    do {
      if ((int)loopIndex < param_2) {
        *(byte *)(iVar7 + 0x15c) = (byte)(1 << (loopIndex & 0x3f)) | *(byte *)(iVar7 + 0x15c);
        uVar1 = *(undefined4 *)((int)local_78 + iVar2);
        *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)((int)local_78 + iVar2 + 4);
        *(undefined4 *)(iVar6 + 0xc) = uVar1;
      }
      else {
        *(byte *)(iVar7 + 0x15c) = *(byte *)(iVar7 + 0x15c) & ~(byte)(1 << (loopIndex & 0x3f));
      }
      loopIndex = loopIndex + 1;
      iVar2 = iVar2 + 0x18;
      iVar6 = iVar6 + 0x18;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
    ((int (*)())FUN_000f4ddc)(param_1,param_2,iVar7);
  }
  else {
    iVar4 = *(int *)(foundEntry + 0x8c);
  }
  return iVar4;
}
#undef local_7c

/* Compiler__getOrCreateConstVector4 @ 0xf645c (376 bytes) */
int Compiler__getOrCreateConstVector4(owner, operandWord0, operandWord1, operandWord2, operandWord3, operandWord4, operandWord5, operandWord6)
  undefined4 owner;
  undefined4 operandWord0;
  undefined4 operandWord1;
  undefined4 operandWord2;
  undefined4 operandWord3;
  undefined4 operandWord4;
  undefined4 operandWord5;
  undefined4 operandWord6;
{
  undefined4 uVar1;
  undefined4 operandWord0Home;
  undefined4 operandWord1Home;
  undefined4 operandWord2Home;
  undefined4 operandWord3Home;
  undefined4 operandWord4Home;
  undefined4 operandWord5Home;
  undefined4 operandWord6Home;
  
  operandWord0Home = operandWord0;
  operandWord1Home = operandWord1;
  operandWord2Home = operandWord2;
  operandWord3Home = operandWord3;
  operandWord4Home = operandWord4;
  operandWord5Home = operandWord5;
  operandWord6Home = operandWord6;
  uVar1 = ((int (*)())Compiler__getOrCreateConstVectorN)(owner,4,operandWord0,operandWord1,operandWord2,operandWord3,operandWord4,operandWord5);
  return uVar1;
}

/* Compiler__getOrCreateConstVector3 @ 0xf65d4 (396 bytes) */
int Compiler__getOrCreateConstVector3(owner, operandWord0, operandWord1, operandWord2, operandWord3, operandWord4, operandWord5, operandWord6)
  undefined4 owner;
  undefined4 operandWord0;
  undefined4 operandWord1;
  undefined4 operandWord2;
  undefined4 operandWord3;
  undefined4 operandWord4;
  undefined4 operandWord5;
  undefined4 operandWord6;
{
  undefined4 operandWord0Home;
  undefined4 operandWord1Home;
  undefined4 operandWord2Home;
  undefined4 operandWord3Home;
  undefined4 operandWord4Home;
  undefined4 operandWord5Home;
  undefined4 operandWord6Home;
  
  operandWord0Home = operandWord0;
  operandWord1Home = operandWord1;
  operandWord2Home = operandWord2;
  operandWord3Home = operandWord3;
  operandWord4Home = operandWord4;
  operandWord5Home = operandWord5;
  operandWord6Home = operandWord6;
  return ((int (*)())Compiler__getOrCreateConstVectorN)(owner,3,operandWord0,operandWord1,operandWord2,operandWord3,operandWord4,operandWord5);
}

/* Compiler__getOrCreateConstVector2 @ 0xf6760 (352 bytes) */
int Compiler__getOrCreateConstVector2(owner, operandWord0, operandWord1, operandWord2, operandWord3, operandWord4, operandWord5, operandWord6)
  undefined4 owner;
  undefined4 operandWord0;
  undefined4 operandWord1;
  undefined4 operandWord2;
  undefined4 operandWord3;
  undefined4 operandWord4;
  undefined4 operandWord5;
  undefined4 operandWord6;
{
  undefined4 operandWord0Home;
  undefined4 operandWord1Home;
  undefined4 operandWord2Home;
  undefined4 operandWord3Home;
  undefined4 operandWord4Home;
  undefined4 operandWord5Home;
  undefined4 operandWord6Home;
  
  operandWord0Home = operandWord0;
  operandWord1Home = operandWord1;
  operandWord2Home = operandWord2;
  operandWord3Home = operandWord3;
  operandWord4Home = operandWord4;
  operandWord5Home = operandWord5;
  operandWord6Home = operandWord6;
  return ((int (*)())Compiler__getOrCreateConstVectorN)(owner,2,operandWord0,operandWord1,operandWord2,operandWord3,operandWord4,operandWord5);
}

/* Compiler__getOrCreateConstVector1 @ 0xf68c0 (324 bytes) */
int Compiler__getOrCreateConstVector1(owner, operandWord0, operandWord1, operandWord2, operandWord3, operandWord4, operandWord5)
  undefined4 owner;
  undefined4 operandWord0;
  undefined4 operandWord1;
  undefined4 operandWord2;
  undefined4 operandWord3;
  undefined4 operandWord4;
  undefined4 operandWord5;
{
  undefined4 operandWord0Home;
  undefined4 operandWord1Home;
  undefined4 operandWord2Home;
  undefined4 operandWord3Home;
  undefined4 operandWord4Home;
  undefined4 operandWord5Home;
  
  operandWord0Home = operandWord0;
  operandWord1Home = operandWord1;
  operandWord2Home = operandWord2;
  operandWord3Home = operandWord3;
  operandWord4Home = operandWord4;
  operandWord5Home = operandWord5;
  return ((int (*)())Compiler__getOrCreateConstVectorN)(owner,1,operandWord0,operandWord1,operandWord2,operandWord3,operandWord4,operandWord5);
}

/* FUN_000f6a04 @ 0xf6a04 (588 bytes) */
int FUN_000f6a04(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  unsigned int ghidra_home[8] = { param_1, param_2, param_3, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 arena;
  int *piVar5;
  undefined4 *allocation;
  char *pcVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  uint uVar11;
  undefined4 uVar12;
  uint uVar13;
  uint *puVar14;
  int local_98;
  int local_94 [30];
  
  puVar10 = (undefined4 *)0x0;
  iVar9 = *(int *)(param_1 + 8);
  (*(unsigned int *)((unsigned char *)ghidra_home + 8)) = param_3;
  iVar2 = (**(code **)(**(int **)(iVar9 + 0x30c) + 0xe8))
                    (*(int **)(iVar9 + 0x30c),param_2,&local_98,param_3,iVar9);
  if (iVar2 != 0) {
    FUN_000f4a24(param_2,local_94);
    iVar2 = *(int *)(param_1 + 0x3ac);
    uVar13 = 0;
    uVar11 = *(uint *)(*(int *)(iVar2 + 0x18) + 4);
    if (0 < (int)uVar11) {
      while( true ) {
        puVar14 = *(uint **)(iVar2 + 0x18);
        if (uVar13 < *puVar14) {
          uVar3 = puVar14[1];
          if (uVar3 <= uVar13) {
            _memset(uVar3 * 4 + puVar14[2],0,(uVar13 - uVar3) * 4 + 4);
            puVar14[1] = uVar13 + 1;
          }
          piVar5 = (int *)(uVar13 * 4 + puVar14[2]);
        }
        else {
          piVar5 = (int *)Vector__elementRefGrow(puVar14,uVar13);
        }
        puVar10 = (undefined4 *)*piVar5;
        if (puVar10[0x4b] == local_98) {
          pcVar7 = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 8));
          allocation = puVar10 + 4;
          iVar8 = 0;
          iVar2 = 4;
          while ((*pcVar7 == '\x04' ||
                 ((allocation[3] == *(int *)((int)local_94 + iVar8) &&
                  (allocation[4] == *(int *)((int)local_94 + iVar8 + 4)))))) {
            iVar2 = iVar2 + -1;
            iVar8 = iVar8 + 0x18;
            allocation = allocation + 6;
            pcVar7 = pcVar7 + 1;
            if (iVar2 == 0) {
              if (puVar10 != (undefined4 *)0x0) {
                return puVar10;
              }
              goto LAB_000f6b68;
            }
          }
        }
        uVar13 = uVar13 + 1;
        if (uVar11 == uVar13) break;
        iVar2 = *(int *)(param_1 + 0x3ac);
      }
    }
LAB_000f6b68:
    if ((*(uint *)(param_1 + 0x30) & 8) == 0) {
      uVar12 = *(undefined4 *)(param_1 + 0x3ac);
      arena = FUN_000f4a5c(uVar12);
      iVar2 = FUN_001275a0(uVar12,0x33,arena,0);
      piVar5 = *(int **)(iVar2 + 0x18);
      if (*piVar5 == 0) {
        piVar5 = (int *)Vector__elementRefGrow(piVar5,0);
      }
      else {
        if (piVar5[1] == 0) {
          *(undefined4 *)piVar5[2] = 0;
          piVar5[1] = 1;
        }
        piVar5 = (int *)piVar5[2];
      }
      puVar10 = (undefined4 *)*piVar5;
    }
    else {
      arena = *(undefined4 *)(iVar9 + 0x374);
      allocation = (undefined4 *)Arena__alloc(arena,0x168);
      *allocation = arena;
      puVar10 = allocation + 1;
      IRLoadConst__ctor_109938(puVar10,*(undefined4 *)(param_1 + 8));
      arena = FUN_000f4a5c(*(undefined4 *)(param_1 + 0x3ac));
      allocation[0x26] = arena;
      allocation[0x27] = 0x33;
      (**(code **)(**(int **)(param_1 + 0x3a0) + 0xc))(*(int **)(param_1 + 0x3a0),puVar10);
    }
    puVar10[0x4b] = local_98;
    puVar14 = *(uint **)(*(int *)(param_1 + 0x3ac) + 0x18);
    uVar11 = puVar14[1];
    if (uVar11 < *puVar14) {
      _memset(uVar11 * 4 + puVar14[2],0,4);
      piVar5 = (int *)(uVar11 * 4 + puVar14[2]);
      puVar14[1] = uVar11 + 1;
    }
    else {
      piVar5 = (int *)Vector__elementRefGrow(puVar14,uVar11);
    }
    *piVar5 = (int)puVar10;
    iVar9 = 4;
    uVar11 = 0;
    allocation = puVar10 + 4;
    iVar2 = 0;
    do {
      puVar1 = (undefined4 *)((int)local_94 + iVar2);
      arena = *(undefined4 *)((int)local_94 + iVar2 + 4);
      iVar2 = iVar2 + 0x18;
      allocation[3] = *puVar1;
      allocation[4] = arena;
      uVar13 = uVar11 & 0x3f;
      uVar11 = uVar11 + 1;
      allocation = allocation + 6;
      *(byte *)(puVar10 + 0x57) = (byte)(1 << uVar13) | *(byte *)(puVar10 + 0x57);
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  return puVar10;
}

/* FUN_000f6d14 @ 0xf6d14 (2568 bytes) */
int FUN_000f6d14(inst, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13, param_14, param_15, param_16, param_17, param_18, param_19, param_20, param_21, param_22, param_23)
  undefined4 inst;
  int param_2;
  undefined4 param_3;
  int param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
  int param_10;
  undefined4 param_11;
  undefined4 param_12;
  undefined4 param_13;
  undefined4 param_14;
  undefined4 param_15;
  int param_16;
  undefined4 param_17;
  undefined4 param_18;
  undefined4 param_19;
  undefined4 param_20;
  undefined4 param_21;
  int param_22;
  undefined4 param_23;
{
  unsigned int ghidra_home[8] = { inst, param_2, param_3, param_4, param_5, param_6, param_7, param_8 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  undefined1 uVar1;
  undefined1 uVar2;
  uint uVar3;
  int iVar4;
  int **ppiVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int *piVar9;
  uint *puVar10;
  int iVar11;
  uint *puVar12;
  undefined4 uVar13;
  bool bVar14;
  int iVar15;
  int local_288;
  undefined1 auStack_284 [4];
  undefined4 local_280;
  undefined4 local_27c;
  undefined4 local_278;
  int *local_274;
  int *local_270 [11];
  undefined4 local_244;
  undefined4 local_240;
  undefined4 local_23c;
  undefined4 local_238;
  undefined4 local_234;
  undefined4 local_230;
  undefined4 local_22c;
  undefined4 local_228;
  undefined4 local_224;
  undefined4 local_220;
  undefined4 local_21c;
  undefined4 local_218;
  undefined4 local_214;
  undefined4 local_210;
  undefined4 local_20c;
  undefined4 local_208;
  undefined4 local_204;
  undefined4 local_200;
  undefined4 local_1fc;
  undefined4 local_1f8;
  undefined4 local_1f4;
  undefined4 local_1f0;
  undefined4 local_1ec;
  undefined4 local_1e8;
  undefined4 local_1e4;
  undefined4 local_1e0;
  undefined4 local_1dc;
  undefined4 local_1d8;
  undefined4 local_1d4;
  undefined4 local_1d0;
  undefined4 local_1cc;
  undefined4 local_1c8;
  undefined4 local_1c4;
  undefined4 local_1c0;
  undefined4 local_1bc;
  undefined4 local_1b8;
  undefined4 local_1b4;
  undefined4 local_1b0;
  undefined4 local_1ac;
  undefined4 local_1a8;
  undefined4 local_1a4;
  undefined4 local_1a0;
  undefined4 local_19c;
  undefined4 local_198;
  undefined4 local_194;
  undefined4 local_190;
  undefined4 local_18c;
  undefined4 local_188;
  undefined4 local_184;
  undefined4 local_180;
  undefined4 local_17c;
  undefined4 local_178;
  undefined4 local_174;
  undefined4 local_170;
  undefined4 local_16c;
  undefined4 local_168;
  undefined4 local_164;
  undefined4 local_160;
  undefined4 local_15c;
  undefined4 local_158;
  undefined4 local_154;
  undefined4 local_150;
  undefined4 local_14c;
  undefined4 local_148;
  undefined4 local_144;
  undefined4 local_140;
  undefined4 local_13c;
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
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
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  
  uVar13 = *(undefined4 *)(param_2 + 8);
  (*(unsigned int *)((unsigned char *)ghidra_home + 8)) = param_3;
  (*(int *)((unsigned char *)ghidra_home + 12)) = param_4;
  (*(unsigned int *)((unsigned char *)ghidra_home + 16)) = param_5;
  (*(unsigned int *)((unsigned char *)ghidra_home + 20)) = param_6;
  (*(unsigned int *)((unsigned char *)ghidra_home + 24)) = param_7;
  (*(unsigned int *)((unsigned char *)ghidra_home + 28)) = param_8;
  if ((((param_4 == 2) && (param_10 == 2)) && (param_16 == 2)) && (param_22 == 2)) {
    iVar15 = 4;
    ppiVar5 = local_270 + 7;
    do {
      *ppiVar5 = (int *)0x7ffffffe;
      ppiVar5 = ppiVar5 + 1;
      iVar15 = iVar15 + -1;
    } while (iVar15 != 0);
    local_270[8] = (int *)param_11;
    local_270[9] = (int *)param_17;
    local_270[10] = (int *)param_23;
    local_270[7] = (int *)param_5;
    iVar15 = ((int (*)())FUN_000f6a04)(param_2,local_270 + 7,DAT_001aa868);
    if (iVar15 != 0) {
      if ((*(uint *)(param_2 + 0x30) & 8) == 0) {
        IRInst__setOperandRef(inst,(*(unsigned int *)((unsigned char *)ghidra_home + 8)),*(undefined4 *)(iVar15 + 0x8c));
      }
      else {
        IRInst__setOperandSource(inst,(*(unsigned int *)((unsigned char *)ghidra_home + 8)),iVar15,*(uint *)(param_2 + 0x30) >> 7 & 1,uVar13);
      }
      iVar6 = IRInst__getOperandRecord(iVar15,0);
      local_288 = *(int *)(iVar6 + 0x10);
      if (local_288 != DAT_001aa860) {
        iVar6 = 0;
        do {
          iVar7 = IRInst__getOperandRecord(inst,(*(unsigned int *)((unsigned char *)ghidra_home + 8)));
          if (*(byte *)(iVar6 + iVar7 + 0x10) < 4) {
            iVar7 = IRInst__getOperandRecord(inst,(*(unsigned int *)((unsigned char *)ghidra_home + 8)));
            uVar3 = (uint)*(byte *)(iVar6 + iVar7 + 0x10);
            auStack_284[uVar3 - 4] = 0;
            *(byte *)(iVar15 + uVar3 + 0xc) =
                 (byte)(1 << (uVar3 & 0x3f)) | *(byte *)(iVar15 + uVar3 + 0xc);
          }
          bVar14 = iVar6 != 3;
          iVar6 = iVar6 + 1;
        } while (bVar14);
        *(int *)(iVar15 + 0x9c) = local_288;
      }
      return;
    }
  }
  piVar9 = &(*(unsigned int *)((unsigned char *)ghidra_home + 12));
  local_27c = DAT_001aa868;
  local_270[0] = &param_10;
  ppiVar5 = &local_274;
  iVar15 = 0;
  local_270[1] = &param_16;
  local_270[2] = &param_22;
  local_270[6] = (int *)PTR_DAT_001e8b70;
  local_274 = piVar9;
  local_270[3] = (int *)PTR_DAT_001e8b70;
  local_270[4] = (int *)PTR_DAT_001e8b70;
  local_270[5] = (int *)PTR_DAT_001e8b70;
  iVar6 = 0;
LAB_000f6f18:
  do {
    iVar7 = iVar6;
    *(char *)((int)&local_27c + iVar15) = (char)iVar7;
    iVar6 = iVar7 + 1;
    local_270[iVar7 + 3] = piVar9;
LAB_000f6f58:
    iVar4 = 4 - iVar15;
    do {
      iVar11 = iVar15;
      iVar15 = iVar11 + 1;
      ppiVar5 = ppiVar5 + 1;
      iVar4 = iVar4 + -1;
      if (iVar4 == 0) {
        local_278 = DAT_001aa868;
        if (0 < iVar6) {
          do {
            iVar11 = iVar7 + 1;
            iVar4 = 0;
            iVar15 = 0;
            ppiVar5 = local_270 + 4;
            if (iVar7 < 0) {
              iVar11 = 1;
            }
            while (iVar11 = iVar11 + -1, iVar11 != 0) {
              puVar12 = (uint *)ppiVar5[-1];
              puVar10 = (uint *)*ppiVar5;
              uVar3 = *puVar12;
              if (uVar3 == *puVar10) {
                if (uVar3 == 2) {
                  bVar14 = GH_U2F((unsigned int)(puVar12[1])) < GH_U2F((unsigned int)(puVar10[1]));
                }
                else {
                  bVar14 = puVar12[1] < puVar10[1];
                }
              }
              else {
                bVar14 = uVar3 < *puVar10;
              }
              if (bVar14) {
                uVar2 = *(undefined1 *)((int)&local_278 + iVar4);
                uVar1 = *(undefined1 *)((int)&local_278 + iVar15 + 1);
                *ppiVar5 = (int *)puVar12;
                *(undefined1 *)((int)&local_278 + iVar15 + 1) = uVar2;
                ppiVar5[-1] = (int *)puVar10;
                *(undefined1 *)((int)&local_278 + iVar4) = uVar1;
              }
              iVar4 = iVar4 + 1;
              ppiVar5 = ppiVar5 + 1;
              iVar15 = iVar15 + 1;
            }
            bVar14 = 0 < iVar7;
            iVar7 = iVar7 + -1;
          } while (bVar14);
          iVar7 = 0;
          iVar15 = iVar6;
          do {
            auStack_284[*(byte *)((int)&local_278 + iVar7)] = (char)iVar7;
            iVar7 = iVar7 + 1;
            iVar15 = iVar15 + -1;
          } while (iVar15 != 0);
        }
        iVar15 = 0;
        iVar7 = 4;
        do {
          *(undefined1 *)((int)&local_280 + iVar15) =
               auStack_284[*(byte *)((int)&local_27c + iVar15)];
          iVar15 = iVar15 + 1;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
        uVar3 = *(uint *)(param_2 + 0x30);
        if ((uVar3 & 8) == 0) {
          if (iVar6 == 2) {
            local_244 = *local_270[3];
            local_240 = local_270[3][1];
            local_23c = local_270[3][2];
            local_238 = local_270[3][3];
            local_230 = local_270[3][5];
            local_234 = local_270[3][4];
            local_7c = *local_270[4];
            local_78 = local_270[4][1];
            local_74 = local_270[4][2];
            local_70 = local_270[4][3];
            local_68 = local_270[4][5];
            local_6c = local_270[4][4];
            uVar13 = ((int (*)())Compiler__getOrCreateConstVector2)(*(undefined4 *)(param_2 + 0x3ac),local_244,local_240,local_23c,
                                  local_238,local_234,local_230,local_7c);
          }
          else if (iVar6 < 3) {
            if (iVar6 == 1) {
              local_22c = *local_270[3];
              local_228 = local_270[3][1];
              local_224 = local_270[3][2];
              local_220 = local_270[3][3];
              local_218 = local_270[3][5];
              local_21c = local_270[3][4];
              uVar13 = ((int (*)())Compiler__getOrCreateConstVector1)(*(undefined4 *)(param_2 + 0x3ac),local_22c,local_228,local_224,
                                    local_220,local_21c,local_218);
            }
            else {
LAB_000f73f0:
              uVar13 = 0;
            }
          }
          else if (iVar6 == 3) {
            local_94 = *local_270[3];
            local_90 = local_270[3][1];
            local_8c = local_270[3][2];
            local_88 = local_270[3][3];
            local_80 = local_270[3][5];
            local_84 = local_270[3][4];
            local_a8 = local_270[4][1];
            local_a4 = local_270[4][2];
            local_a0 = local_270[4][3];
            local_ac = *local_270[4];
            local_98 = local_270[4][5];
            local_9c = local_270[4][4];
            local_bc = local_270[5][2];
            local_b8 = local_270[5][3];
            local_c4 = *local_270[5];
            local_c0 = local_270[5][1];
            local_b0 = local_270[5][5];
            local_b4 = local_270[5][4];
            uVar13 = ((int (*)())Compiler__getOrCreateConstVector3)(*(undefined4 *)(param_2 + 0x3ac),local_94,local_90,local_8c,
                                  local_88,local_84,local_80,local_ac);
          }
          else {
            if (iVar6 != 4) goto LAB_000f73f0;
            local_dc = *local_270[3];
            local_d8 = local_270[3][1];
            local_d4 = local_270[3][2];
            local_d0 = local_270[3][3];
            local_c8 = local_270[3][5];
            local_cc = local_270[3][4];
            local_f0 = local_270[4][1];
            local_ec = local_270[4][2];
            local_e8 = local_270[4][3];
            local_f4 = *local_270[4];
            local_e0 = local_270[4][5];
            local_e4 = local_270[4][4];
            local_104 = local_270[5][2];
            local_100 = local_270[5][3];
            local_10c = *local_270[5];
            local_108 = local_270[5][1];
            local_f8 = local_270[5][5];
            local_fc = local_270[5][4];
            local_1b4 = *local_270[6];
            local_1b0 = local_270[6][1];
            local_1ac = local_270[6][2];
            local_1a8 = local_270[6][3];
            local_1a0 = local_270[6][5];
            local_1a4 = local_270[6][4];
            uVar13 = ((int (*)())Compiler__getOrCreateConstVector4)(*(undefined4 *)(param_2 + 0x3ac),local_dc,local_d8,local_d4,
                                  local_d0,local_cc,local_c8,local_f4);
          }
          IRInst__setOperandRef(inst,(*(unsigned int *)((unsigned char *)ghidra_home + 8)),uVar13);
          goto LAB_000f76c8;
        }
        if (iVar6 == 2) {
          local_14c = local_270[3][2];
          local_154 = *local_270[3];
          local_150 = local_270[3][1];
          local_148 = local_270[3][3];
          local_140 = local_270[3][5];
          local_144 = local_270[3][4];
          local_16c = *local_270[4];
          local_168 = local_270[4][1];
          local_164 = local_270[4][2];
          local_160 = local_270[4][3];
          local_158 = local_270[4][5];
          local_15c = local_270[4][4];
          uVar8 = ((int (*)())Compiler__getOrCreateLoadConst2)(*(undefined4 *)(param_2 + 0x3ac),local_154,local_150,local_14c,
                               local_148,local_144,local_140,local_16c);
          uVar3 = *(uint *)(param_2 + 0x30);
        }
        else if (iVar6 < 3) {
          if (iVar6 == 1) {
            local_134 = local_270[3][2];
            local_13c = *local_270[3];
            local_138 = local_270[3][1];
            local_130 = local_270[3][3];
            local_128 = local_270[3][5];
            local_12c = local_270[3][4];
            uVar8 = ((int (*)())Compiler__getOrCreateLoadConst1)(*(undefined4 *)(param_2 + 0x3ac),local_13c,local_138,local_134,
                                 local_130,local_12c,local_128);
            uVar3 = *(uint *)(param_2 + 0x30);
          }
          else {
LAB_000f70d4:
            uVar8 = 0;
          }
        }
        else if (iVar6 == 3) {
          local_17c = local_270[3][2];
          local_184 = *local_270[3];
          local_180 = local_270[3][1];
          local_178 = local_270[3][3];
          local_170 = local_270[3][5];
          local_174 = local_270[3][4];
          local_198 = local_270[4][1];
          local_19c = *local_270[4];
          local_194 = local_270[4][2];
          local_190 = local_270[4][3];
          local_188 = local_270[4][5];
          local_18c = local_270[4][4];
          local_124 = *local_270[5];
          local_11c = local_270[5][2];
          local_118 = local_270[5][3];
          local_120 = local_270[5][1];
          local_110 = local_270[5][5];
          local_114 = local_270[5][4];
          uVar8 = ((int (*)())Compiler__getOrCreateLoadConst3)(*(undefined4 *)(param_2 + 0x3ac),local_184,local_180,local_17c,
                               local_178,local_174,local_170,local_19c);
          uVar3 = *(uint *)(param_2 + 0x30);
        }
        else {
          if (iVar6 != 4) goto LAB_000f70d4;
          local_1c4 = local_270[3][2];
          local_1cc = *local_270[3];
          local_1c8 = local_270[3][1];
          local_1c0 = local_270[3][3];
          local_1b8 = local_270[3][5];
          local_1bc = local_270[3][4];
          local_1e0 = local_270[4][1];
          local_1e4 = *local_270[4];
          local_1dc = local_270[4][2];
          local_1d8 = local_270[4][3];
          local_1d0 = local_270[4][5];
          local_1d4 = local_270[4][4];
          local_1fc = *local_270[5];
          local_1f4 = local_270[5][2];
          local_1f0 = local_270[5][3];
          local_1f8 = local_270[5][1];
          local_1e8 = local_270[5][5];
          local_1ec = local_270[5][4];
          local_214 = *local_270[6];
          local_210 = local_270[6][1];
          local_20c = local_270[6][2];
          local_208 = local_270[6][3];
          local_200 = local_270[6][5];
          local_204 = local_270[6][4];
          uVar8 = ((int (*)())FUN_000f5248)(*(undefined4 *)(param_2 + 0x3ac),local_1cc,local_1c8,local_1c4,
                               local_1c0,local_1bc,local_1b8,local_1e4);
          uVar3 = *(uint *)(param_2 + 0x30);
        }
        IRInst__setOperandSource(inst,(*(unsigned int *)((unsigned char *)ghidra_home + 8)),uVar8,uVar3 >> 7 & 1,uVar13);
LAB_000f76c8:
        iVar15 = IRInst__getOperandRecord(inst,(*(unsigned int *)((unsigned char *)ghidra_home + 8)));
        *(undefined4 *)(iVar15 + 0x10) = local_280;
        return;
      }
    } while (iVar6 < 0);
    if (iVar6 != 0) {
      piVar9 = *ppiVar5;
      iVar4 = 0;
      while ((*local_270[iVar4 + 3] != *piVar9 || (local_270[iVar4 + 3][1] != piVar9[1]))) {
        iVar4 = iVar4 + 1;
        if (iVar6 < iVar4) goto LAB_000f6f58;
        if (iVar4 == iVar6) goto LAB_000f6f18;
      }
      *(char *)((int)&local_27c + iVar11 + 1) = (char)iVar4;
      goto LAB_000f6f58;
    }
    piVar9 = *ppiVar5;
  } while( true );
}

/* IRInst__makeLiteralVec4Int @ 0xf771c (340 bytes) */
int IRInst__makeLiteralVec4Int(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  
  return ((int (*)())FUN_000f6d14)(param_1,param_2,param_3,1,param_4,local_b0,local_ac,local_a8,local_a4,1,param_5,
               local_98,local_94,local_90,local_8c,1,param_6,local_80,local_7c,local_78,local_74,1,param_7);
}

/* FUN_000f7870 @ 0xf7870 (340 bytes) */
int FUN_000f7870(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  
  return ((int (*)())FUN_000f6d14)(param_1,param_2,param_3,3,param_4,local_b0,local_ac,local_a8,local_a4,3,param_5,
               local_98,local_94,local_90,local_8c,3,param_6,local_80,local_7c,local_78,local_74,3,param_7);
}

/* the raw 32-bit pattern of a float, as the stock passes it in a general register / stack word (`stfs f1,0xec(r1); lwz r7,0xec(r1)`) */
#ifndef FBITS
#define FBITS(x) ({ float fbits_ = (float)(x); *(unsigned int *)&fbits_; })
#endif
/* IRInst__makeLiteralVec4Float @ 0xf79c4 (332 bytes) */
void IRInst__makeLiteralVec4Float(undefined4 param_1,undefined4 param_2,undefined4 param_3,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  
  ((int (*)())FUN_000f6d14)(param_1,param_2,param_3,2,FBITS(fparam_1),local_a0,local_9c,local_98,local_94,2,
               FBITS(fparam_2),local_88,local_84,local_80,local_7c,2,FBITS(fparam_3),local_70,
               local_6c,local_68,local_64,2,FBITS(fparam_4));
  return;
}

/* FUN_000f7b10 @ 0xf7b10 (228 bytes) */
int FUN_000f7b10(vector, param_2, param_3, param_4, param_5, param_6, param_7)
  uint *vector;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined4 *puVar1;
  uint uVar2;
  uint loopIndex;
  int iStack0000001c;
  int iStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  
  uVar2 = 0;
  if (vector[1] != 0) {
    loopIndex = 0;
    uVar2 = vector[1];
    iStack0000001c = param_2;
    iStack00000020 = param_3;
    uStack00000024 = param_4;
    uStack00000028 = param_5;
    uStack0000002c = param_6;
    uStack00000030 = param_7;
    do {
      if (loopIndex < *vector) {
        if (uVar2 <= loopIndex) {
          _memset(uVar2 * 4 + vector[2],0,(loopIndex - uVar2) * 4 + 4);
          vector[1] = loopIndex + 1;
        }
        puVar1 = (undefined4 *)(loopIndex * 4 + vector[2]);
      }
      else {
        puVar1 = (undefined4 *)Vector__elementRefGrow(vector,loopIndex);
      }
      if ((*(int *)*puVar1 == param_2) && (((int *)*puVar1)[1] == param_3)) {
        return loopIndex;
      }
      uVar2 = vector[1];
      loopIndex = loopIndex + 1;
    } while (loopIndex < uVar2);
  }
  return uVar2;
}

/* FUN_000f7bf4 @ 0xf7bf4 (228 bytes) */
int FUN_000f7bf4(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  int listCount;
  int iVar1;
  undefined4 allocation;
  int iVar3;
  
  param_1[8] = param_2;
  listCount = DList__count(param_2 + 0x37c);
  param_1[7] = listCount;
  iVar3 = *(int *)(param_1[8] + 8);
  iVar1 = listCount * 4 + 4;
  param_1[9] = iVar3;
  allocation = Arena__alloc(*(undefined4 *)(iVar3 + 0x378),iVar1);
  param_1[2] = allocation;
  allocation = Arena__alloc(*(undefined4 *)(param_1[9] + 0x378),iVar1);
  param_1[1] = allocation;
  allocation = Arena__alloc(*(undefined4 *)(param_1[9] + 0x378),iVar1);
  param_1[4] = allocation;
  allocation = Arena__alloc(*(undefined4 *)(param_1[9] + 0x378),iVar1);
  param_1[3] = allocation;
  allocation = Arena__alloc(*(undefined4 *)(param_1[9] + 0x378),iVar1);
  *param_1 = allocation;
  allocation = Arena__alloc(*(undefined4 *)(param_1[9] + 0x378),param_1[7] * 4 + 4);
  param_1[6] = allocation;
  allocation = Arena__alloc(*(undefined4 *)(param_1[9] + 0x378),param_1[7] * 4 + 4);
  param_1[5] = allocation;
  return;
}

/* FUN_000f7cd8 @ 0xf7cd8 (228 bytes) */
int FUN_000f7cd8(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  int listCount;
  int iVar1;
  undefined4 allocation;
  int iVar3;
  
  param_1[8] = param_2;
  listCount = DList__count(param_2 + 0x37c);
  param_1[7] = listCount;
  iVar3 = *(int *)(param_1[8] + 8);
  iVar1 = listCount * 4 + 4;
  param_1[9] = iVar3;
  allocation = Arena__alloc(*(undefined4 *)(iVar3 + 0x378),iVar1);
  param_1[2] = allocation;
  allocation = Arena__alloc(*(undefined4 *)(param_1[9] + 0x378),iVar1);
  param_1[1] = allocation;
  allocation = Arena__alloc(*(undefined4 *)(param_1[9] + 0x378),iVar1);
  param_1[4] = allocation;
  allocation = Arena__alloc(*(undefined4 *)(param_1[9] + 0x378),iVar1);
  param_1[3] = allocation;
  allocation = Arena__alloc(*(undefined4 *)(param_1[9] + 0x378),iVar1);
  *param_1 = allocation;
  allocation = Arena__alloc(*(undefined4 *)(param_1[9] + 0x378),param_1[7] * 4 + 4);
  param_1[6] = allocation;
  allocation = Arena__alloc(*(undefined4 *)(param_1[9] + 0x378),param_1[7] * 4 + 4);
  param_1[5] = allocation;
  return;
}

/* FUN_000f7dbc @ 0xf7dbc (352 bytes) */
int FUN_000f7dbc(param_1)
  int param_1;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint loopIndex;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint loopIndex2;
  uint uVar10;
  
  piVar2 = (int *)FUN_000ec5b8(*(undefined4 *)(param_1 + 0x20));
  if (*(int *)(param_1 + 0x1c) != 0) {
    loopIndex = 1;
    do {
      piVar2 = piVar2 + 1;
      iVar6 = *piVar2;
      iVar5 = *(int *)(iVar6 + 0xe4);
      iVar7 = 0;
      for (loopIndex2 = 1; loopIndex2 <= *(uint *)(*(int *)(iVar6 + 0xd0) + 4); loopIndex2 = loopIndex2 + 1) {
        iVar3 = *(int *)(iVar7 + *(int *)(*(int *)(iVar6 + 0xd0) + 8));
        if ((iVar3 != 0) && (iVar5 != *(int *)(*(int *)(iVar3 + 0xe4) * 4 + *(int *)(param_1 + 8))))
        {
          FUN_000e910c(iVar6,iVar3);
        }
        iVar7 = iVar7 + 4;
      }
      iVar7 = 0;
      for (loopIndex2 = 1; loopIndex2 <= *(uint *)(*(int *)(iVar6 + 0xf4) + 4); loopIndex2 = loopIndex2 + 1) {
        iVar8 = 0;
        iVar3 = *(int *)(iVar7 + *(int *)(*(int *)(iVar6 + 0xf4) + 8));
        for (uVar10 = 1; iVar1 = *(int *)(iVar3 + 0xf8), uVar10 <= *(uint *)(iVar1 + 4);
            uVar10 = uVar10 + 1) {
          iVar1 = *(int *)(iVar8 + *(int *)(iVar1 + 8));
          if (iVar5 != *(int *)(*(int *)(iVar1 + 0xe4) * 4 + *(int *)(param_1 + 8))) {
            FUN_000e910c(iVar6,iVar1);
          }
          iVar8 = iVar8 + 4;
        }
        iVar7 = iVar7 + 4;
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex <= *(uint *)(param_1 + 0x1c));
  }
  return;
}

/* FUN_000f7f1c @ 0xf7f1c (296 bytes) */
int FUN_000f7f1c(param_1)
  undefined4 *param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  uint loopIndex;
  int iVar5;
  
  loopIndex = 0;
  iVar3 = param_1[5];
  do {
    iVar1 = loopIndex * 4;
    iVar2 = *(int *)(iVar1 + iVar3);
    while ((iVar2 != 0 && (iVar5 = *(int *)(iVar2 + 4), iVar5 != 0))) {
      Arena__free(*(undefined4 *)(iVar2 + -4),iVar2 + -4);
      *(int *)(iVar1 + param_1[5]) = iVar5;
      iVar3 = param_1[5];
      iVar2 = *(int *)(iVar1 + iVar3);
    }
    iVar1 = *(int *)(iVar1 + iVar3);
    if (iVar1 != 0) {
      Arena__free(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
      iVar3 = param_1[5];
    }
    loopIndex = loopIndex + 1;
  } while (loopIndex <= (uint)param_1[7]);
  Arena__free(*(undefined4 *)(param_1[9] + 0x378),iVar3);
  Arena__free(*(undefined4 *)(param_1[9] + 0x378),param_1[6]);
  Arena__free(*(undefined4 *)(param_1[9] + 0x378),*param_1);
  Arena__free(*(undefined4 *)(param_1[9] + 0x378),param_1[3]);
  Arena__free(*(undefined4 *)(param_1[9] + 0x378),param_1[4]);
  Arena__free(*(undefined4 *)(param_1[9] + 0x378),param_1[1]);
  Arena__free(*(undefined4 *)(param_1[9] + 0x378),param_1[2]);
  param_1[6] = 0;
  return;
}

/* FUN_000f8044 @ 0xf8044 (296 bytes) */
int FUN_000f8044(param_1)
  undefined4 *param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  uint loopIndex;
  int iVar5;
  
  loopIndex = 0;
  iVar3 = param_1[5];
  do {
    iVar1 = loopIndex * 4;
    iVar2 = *(int *)(iVar1 + iVar3);
    while ((iVar2 != 0 && (iVar5 = *(int *)(iVar2 + 4), iVar5 != 0))) {
      Arena__free(*(undefined4 *)(iVar2 + -4),iVar2 + -4);
      *(int *)(iVar1 + param_1[5]) = iVar5;
      iVar3 = param_1[5];
      iVar2 = *(int *)(iVar1 + iVar3);
    }
    iVar1 = *(int *)(iVar1 + iVar3);
    if (iVar1 != 0) {
      Arena__free(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
      iVar3 = param_1[5];
    }
    loopIndex = loopIndex + 1;
  } while (loopIndex <= (uint)param_1[7]);
  Arena__free(*(undefined4 *)(param_1[9] + 0x378),iVar3);
  Arena__free(*(undefined4 *)(param_1[9] + 0x378),param_1[6]);
  Arena__free(*(undefined4 *)(param_1[9] + 0x378),*param_1);
  Arena__free(*(undefined4 *)(param_1[9] + 0x378),param_1[3]);
  Arena__free(*(undefined4 *)(param_1[9] + 0x378),param_1[4]);
  Arena__free(*(undefined4 *)(param_1[9] + 0x378),param_1[1]);
  Arena__free(*(undefined4 *)(param_1[9] + 0x378),param_1[2]);
  param_1[6] = 0;
  return;
}

/* FUN_000f816c @ 0xf816c (236 bytes) */
int FUN_000f816c(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  int *allocation;
  int *piVar3;
  int iVar4;
  uint *puVar5;
  int arena;
  uint uVar7;
  
  *(int *)(param_1[8] + 0x474) = *(int *)(param_1[8] + 0x474) + 1;
  arena = *(int *)(param_1[9] + 0x378);
  allocation = (int *)Arena__alloc(arena,0x14);
  puVar5 = (uint *)(allocation + 1);
  *allocation = arena;
  allocation[1] = 2;
  allocation[4] = arena;
  allocation[2] = 0;
  arena = Arena__alloc(arena,8);
  allocation[3] = arena;
  *(undefined4 *)(param_2 + 0xe4) = 1;
  *(undefined4 *)(*param_1 + 4) = 0;
  *(int *)(*(int *)(param_2 + 0xe4) * 4 + param_1[6]) = param_2;
  uVar7 = allocation[2];
  if (uVar7 < (uint)allocation[1]) {
    _memset((void *)(uVar7 * 4 + allocation[3]),0,4);
    allocation[2] = uVar7 + 1;
    piVar3 = (int *)(uVar7 * 4 + allocation[3]);
  }
  else {
    piVar3 = (int *)Vector__elementRefGrow(puVar5,uVar7);
  }
  *piVar3 = param_2;
  arena = 2;
  *(int *)(*(int *)(param_2 + 0xe4) * 4 + param_1[1]) = *(int *)(param_2 + 0xe4);
  *(int *)(*(int *)(param_2 + 0xe4) * 4 + param_1[4]) = *(int *)(param_2 + 0xe4);
  while( true ) {
    while( true ) {
      iVar4 = FUN_000e80cc(param_2,*(undefined4 *)(param_1[8] + 0x474));
      if (iVar4 == 0) break;
      uVar7 = allocation[2];
      if (uVar7 < *puVar5) {
        _memset((void *)(uVar7 * 4 + allocation[3]),0,4);
        allocation[2] = uVar7 + 1;
        piVar3 = (int *)(uVar7 * 4 + allocation[3]);
      }
      else {
        piVar3 = (int *)Vector__elementRefGrow(puVar5,uVar7);
      }
      *piVar3 = iVar4;
      iVar1 = arena * 4;
      *(int *)(iVar4 + 0xe4) = arena;
      arena = arena + 1;
      *(undefined4 *)(iVar1 + *param_1) = *(undefined4 *)(param_2 + 0xe4);
      *(int *)(*(int *)(iVar4 + 0xe4) * 4 + param_1[6]) = iVar4;
      *(undefined4 *)(iVar4 + 0x118) = *(undefined4 *)(param_1[8] + 0x474);
      *(int *)(*(int *)(iVar4 + 0xe4) * 4 + param_1[1]) = *(int *)(iVar4 + 0xe4);
      *(int *)(*(int *)(iVar4 + 0xe4) * 4 + param_1[4]) = *(int *)(iVar4 + 0xe4);
      param_2 = iVar4;
    }
    uVar7 = allocation[2];
    if (uVar7 == 0) break;
    piVar3 = (int *)0x0;
    if (uVar7 - 1 < uVar7) {
      piVar3 = (int *)((uVar7 - 1) * 4 + allocation[3]);
    }
    param_2 = *piVar3;
    Vector__removeAt(puVar5,uVar7 - 1);
  }
  if (puVar5 != (uint *)0x0) {
    Arena__free(allocation[4],allocation[3]);
    arena = *allocation;
    if ((*(int *)(arena + 0x28) != 0) && (piVar3 = *(int **)(arena + 0x14), piVar3 == allocation)) {
      _memset(piVar3,0,*(int *)(arena + 8) - (int)piVar3);
      *(undefined4 *)(arena + 8) = *(undefined4 *)(arena + 0x14);
    }
    return;
  }
  return;
}

/* FUN_000f83cc @ 0xf83cc (100 bytes) */
int FUN_000f83cc(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  uint uVar2;
  int *allocation;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint *puVar8;
  int arena;
  
  arena = *(int *)(*(int *)(param_1 + 0x24) + 0x378);
  allocation = (int *)Arena__alloc(arena,0x14);
  puVar8 = (uint *)(allocation + 1);
  *allocation = arena;
  allocation[1] = 2;
  allocation[2] = 0;
  allocation[4] = arena;
  arena = Arena__alloc(arena,8);
  allocation[3] = arena;
  arena = *(int *)(param_1 + 0xc);
  while (*(int *)(*(int *)(param_2 * 4 + arena) * 4 + arena) != 0) {
    uVar2 = allocation[2];
    if (uVar2 < *puVar8) {
      _memset((void *)(uVar2 * 4 + allocation[3]),0,4);
      piVar4 = (int *)(uVar2 * 4 + allocation[3]);
      allocation[2] = uVar2 + 1;
    }
    else {
      piVar4 = (int *)Vector__elementRefGrow(puVar8,uVar2);
    }
    *piVar4 = param_2;
    arena = *(int *)(param_1 + 0xc);
    param_2 = *(int *)(param_2 * 4 + arena);
  }
  while (allocation[2] != 0) {
    uVar2 = allocation[2] - 1;
    piVar4 = (int *)0x0;
    if (uVar2 < (uint)allocation[2]) {
      piVar4 = (int *)(uVar2 * 4 + allocation[3]);
    }
    arena = *piVar4;
    Vector__removeAt(puVar8,allocation[2] - 1);
    iVar6 = *(int *)(param_1 + 0xc);
    arena = arena * 4;
    iVar7 = *(int *)(param_1 + 0x10);
    iVar1 = *(int *)(iVar6 + arena) * 4;
    iVar5 = *(int *)(iVar7 + iVar1);
    if (*(uint *)(iVar5 * 4 + *(int *)(param_1 + 4)) <
        *(uint *)(*(int *)(arena + iVar7) * 4 + *(int *)(param_1 + 4))) {
      *(int *)(arena + iVar7) = iVar5;
      iVar6 = *(int *)(param_1 + 0xc);
    }
    *(undefined4 *)(arena + iVar6) = *(undefined4 *)(iVar1 + iVar6);
  }
  if (puVar8 == (uint *)0x0) {
    return;
  }
  Arena__free(allocation[4],allocation[3]);
  arena = *allocation;
  if ((*(int *)(arena + 0x28) != 0) && (piVar4 = *(int **)(arena + 0x14), piVar4 == allocation)) {
    _memset(piVar4,0,*(int *)(arena + 8) - (int)piVar4);
    *(undefined4 *)(arena + 8) = *(undefined4 *)(arena + 0x14);
  }
  return;
}

/* lazyEntryGet @ 0xf8588 (72 bytes) */
int lazyEntryGet(param_1, param_2)
  int param_1;
  int param_2;
{
  if (*(int *)(*(int *)(param_1 + 0xc) + param_2 * 4) != 0) {
    ((int (*)())FUN_000f83cc)(param_1,param_2);
  }
  return *(undefined4 *)(param_2 * 4 + *(int *)(param_1 + 0x10));
}

/* FUN_000f85d0 @ 0xf85d0 (740 bytes) */
int FUN_000f85d0(param_1)
  int *param_1;
{
  uint loopIndex;
  uint uVar1;
  int iVar2;
  undefined4 *allocation;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 arena;
  uint uVar11;
  int *piVar12;
  
  iVar5 = *(int *)(param_1[8] + 0x3a0);
  if (*(int *)(iVar5 + 0xe4) == 0) {
    iVar4 = *(int *)(param_1[8] + 900);
    for (iVar7 = *(int *)(iVar4 + 8); iVar7 != 0; iVar7 = *(int *)(iVar7 + 8)) {
      *(undefined4 *)(iVar4 + 0xe8) = *(undefined4 *)(iVar4 + 0xe4);
      iVar4 = iVar7;
    }
  }
  ((int (*)())FUN_000f816c)(param_1,iVar5);
  FUN_000ec468(param_1[8],param_1[6],param_1[7]);
  uVar6 = param_1[7];
  if (1 < uVar6) {
    iVar4 = uVar6 << 2;
    do {
      iVar8 = 0;
      iVar7 = *(int *)(param_1[6] + iVar4);
      for (uVar11 = 1; iVar2 = *(int *)(iVar7 + 0xd4), uVar11 <= *(uint *)(iVar2 + 4);
          uVar11 = uVar11 + 1) {
        iVar2 = *(int *)(iVar8 + *(int *)(iVar2 + 8));
        if (iVar2 != 0) {
          iVar9 = param_1[1];
          iVar2 = ((int (*)())lazyEntryGet)(param_1,*(undefined4 *)(iVar2 + 0xe4));
          uVar1 = *(uint *)(iVar2 * 4 + iVar9);
          if (uVar1 < *(uint *)(iVar4 + param_1[1])) {
            *(uint *)(iVar4 + param_1[1]) = uVar1;
          }
        }
        iVar8 = iVar8 + 4;
      }
      arena = *(undefined4 *)(param_1[9] + 0x378);
      allocation = (undefined4 *)Arena__alloc(arena,0xc);
      *allocation = arena;
      allocation[1] = uVar6;
      allocation[2] = 0;
      allocation[2] = *(undefined4 *)(*(int *)(iVar4 + param_1[1]) * 4 + param_1[5]);
      *(undefined4 **)(*(int *)(iVar4 + param_1[1]) * 4 + param_1[5]) = allocation + 1;
      *(undefined4 *)(iVar4 + param_1[3]) = *(undefined4 *)(iVar4 + *param_1);
      for (piVar12 = *(int **)(*(int *)(iVar4 + *param_1) * 4 + param_1[5]); piVar12 != (int *)0x0;
          piVar12 = (int *)piVar12[1]) {
        iVar7 = *piVar12 * 4;
        iVar8 = ((int (*)())lazyEntryGet)(param_1,*piVar12);
        iVar2 = *(int *)(param_1[1] + iVar7);
        if (iVar2 == *(int *)(iVar8 * 4 + param_1[1])) {
          *(int *)(iVar7 + param_1[2]) = iVar2;
        }
        else {
          *(int *)(iVar7 + param_1[2]) = iVar8;
        }
      }
      uVar6 = uVar6 - 1;
      iVar4 = iVar4 + -4;
    } while (1 < uVar6);
  }
  *(undefined4 *)(param_1[2] + 4) = 0;
  uVar6 = param_1[7];
  if (1 < uVar6) {
    uVar11 = 2;
    do {
      iVar4 = uVar11 * 4;
      iVar7 = param_1[2];
      if (*(int *)(iVar4 + iVar7) != *(int *)(iVar4 + param_1[1])) {
        *(undefined4 *)(iVar4 + iVar7) = *(undefined4 *)(*(int *)(iVar4 + iVar7) * 4 + iVar7);
        uVar6 = param_1[7];
      }
      uVar11 = uVar11 + 1;
    } while (uVar11 <= uVar6);
  }
  if (uVar6 != 0) {
    iVar8 = param_1[6];
    iVar7 = 0;
    loopIndex = 1;
    iVar4 = 4;
    while( true ) {
      iVar4 = *(int *)(iVar4 + iVar8);
      *(int *)(iVar4 + 0xf0) = iVar7;
      if (iVar7 != 0) {
        FUN_000e8ce4(iVar7,iVar4);
      }
      loopIndex = loopIndex + 1;
      if ((uint)param_1[7] < loopIndex) break;
      if (loopIndex == 1) {
        iVar8 = param_1[6];
        iVar7 = 0;
        iVar4 = 4;
      }
      else {
        iVar4 = loopIndex * 4;
        iVar8 = param_1[6];
        iVar7 = *(int *)(*(int *)(iVar4 + param_1[2]) * 4 + iVar8);
      }
    }
  }
  ((int (*)())FUN_000f7dbc)(param_1);
  if (*(int *)(iVar5 + 0xe8) == 0) {
    iVar5 = *(int *)(param_1[8] + 900);
    for (iVar4 = *(int *)(*(int *)(param_1[8] + 900) + 8); iVar4 != 0; iVar4 = *(int *)(iVar4 + 8))
    {
      *(undefined4 *)(iVar5 + 0xe4) = *(undefined4 *)(iVar5 + 0xe8);
      iVar5 = iVar4;
    }
  }
  return;
}

/* FUN_000f88b4 @ 0xf88b4 (104 bytes) */
int FUN_000f88b4(param_1)
  int param_1;
{
  int *allocation;
  int *piVar2;
  int arena;
  
  arena = *(int *)(*(int *)(param_1 + 8) + 0x378);
  allocation = (int *)Arena__alloc(arena,0x2c);
  *allocation = arena;
  piVar2 = allocation + 1;
  ((int (*)())FUN_000f7cd8)(piVar2,param_1);
  ((int (*)())FUN_000f85d0)(piVar2);
  if (piVar2 == (int *)0x0) {
    return;
  }
  ((int (*)())FUN_000f8044)(piVar2);
  arena = *allocation;
  if ((*(int *)(arena + 0x28) != 0) && (piVar2 = *(int **)(arena + 0x14), piVar2 == allocation)) {
    _memset(piVar2,0,*(int *)(arena + 8) - (int)piVar2);
    *(undefined4 *)(arena + 8) = *(undefined4 *)(arena + 0x14);
  }
  return;
}

/* FUN_000f8960 @ 0xf8960 (16 bytes) */
int FUN_000f8960(param_1, param_2)
  int param_1;
  int param_2;
{
  return *(undefined4 *)(param_1 * 0x24 + param_2 + 8);
}

/* FUN_000f8970 @ 0xf8970 (16 bytes) */
int FUN_000f8970(param_1, param_2)
  int param_1;
  int param_2;
{
  return *(undefined4 *)(param_1 * 0x24 + param_2 + 4);
}

/* FUN_000f8980 @ 0xf8980 (20 bytes) */
int FUN_000f8980(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  return *(undefined1 *)(param_2 + param_1 * 0x24 + param_3 + 0x1c);
}

/* FUN_000f8994 @ 0xf8994 (16 bytes) */
int FUN_000f8994(param_1, param_2)
  int param_1;
  int param_2;
{
  return *(undefined4 *)(param_1 * 0x24 + param_2 + 0xc);
}

/* FUN_000f89a4 @ 0xf89a4 (16 bytes) */
int FUN_000f89a4(param_1, param_2)
  int param_1;
  int param_2;
{
  return *(undefined4 *)(param_1 * 0x24 + param_2 + 0x10);
}

/* tableWordOrEight @ 0xf89b4 (52 bytes) */
int tableWordOrEight(param_1)
  uint param_1;
{
  if (5 < param_1) {
    return 8;
  }
  return *(undefined4 *)(PTR_DAT_001e8b84 + param_1 * 4);
}

/* remapSelect1To0 @ 0xf89e8 (36 bytes) */
int remapSelect1To0(param_1)
  int param_1;
{
  if (param_1 == 1) {
    return 0;
  }
  return 2 - (uint)(param_1 == 2);
}

/* remapSelectSmall @ 0xf8a0c (36 bytes) */
int remapSelectSmall(param_1)
  int param_1;
{
  if (param_1 == 1) {
    return 0;
  }
  if (param_1 == 2) {
    return 1;
  }
  return 3;
}

/* FUN_000f8a30 @ 0xf8a30 (112 bytes) */
double FUN_000f8a30(int param_1,int param_2,int param_3,int param_4)
{
  undefined *puVar1;
  double dVar2;
  
  puVar1 = PTR_DAT_001e8bb8;
  if (param_1 == 4) {
    dVar2 = (double)FLOAT_001aa0d4;
    *(undefined1 *)(param_3 + param_2) = 0;
    return dVar2;
  }
  if (param_1 == 5) {
    dVar2 = (double)FLOAT_001aa0e8;
    *(undefined1 *)(param_3 + param_2) = 0;
    return dVar2;
  }
  *(undefined1 *)(param_3 + param_2) = 1;
  dVar2 = (double)FLOAT_001aa0d4;
  *(char *)(param_4 + param_2) = (char)*(undefined4 *)(puVar1 + param_1 * 4);
  return dVar2;
}

/* FUN_000f8aa0 @ 0xf8aa0 (488 bytes) */
int FUN_000f8aa0(param_1, param_2, descriptor, param_4, param_5)
  undefined4 param_1;
  uint *param_2;
  uint *descriptor;
  int param_4;
  int *param_5;
{
  uint uVar1;
  int *a4;
  undefined4 in_r8;
  uint uVar2;
  uint uVar3;
  char local_38 [32];
  
  local_38[0] = '\0';
  local_38[1] = 1;
  local_38[2] = 2;
  local_38[3] = 3;
  uVar3 = *param_2;
  a4 = param_5;
  if (descriptor != (uint *)0x0) {
    uVar2 = *descriptor;
    if ((uVar2 & 0x400000) != 0) {
      uVar1 = descriptor[1];
      if ((uVar1 >> 3 & 1 & uVar1 >> 7 & 1 & uVar1 >> 0xb & 1 & uVar1 >> 0xf & 1) != 0) {
        IROperand__setModifierBits(param_5 + param_4 * 6 + 0x23,1,param_5[param_4 * 6 + 0x28] & 1U ^ 1);
        uVar2 = *descriptor;
      }
    }
    if (((uVar2 & 0x400000) != 0) && ((descriptor[1] & 0x100000) != 0)) {
      IROperand__setModifierBits(param_5 + param_4 * 6 + 0x23,2,1);
    }
    local_38[0] = psnPackedLaneSource(descriptor,0);
    local_38[1] = psnPackedLaneSource(descriptor,1);
    local_38[2] = psnPackedLaneSource(descriptor,2);
    local_38[3] = psnPackedLaneSource(descriptor,3);
  }
  (**(code **)(*param_5 + 0x88))
            (param_5,param_4,0,(int)local_38[uVar3 >> 0x18],a4,in_r8,*(code **)(*param_5 + 0x88));
  (**(code **)(*param_5 + 0x88))
            (param_5,param_4,1,(int)local_38[uVar3 >> 0x10 & 0xff],a4,in_r8,
             *(code **)(*param_5 + 0x88));
  (**(code **)(*param_5 + 0x88))
            (param_5,param_4,2,(int)local_38[uVar3 >> 8 & 0xff],a4,in_r8,*(code **)(*param_5 + 0x88)
            );
  (**(code **)(*param_5 + 0x88))
            (param_5,param_4,3,(int)local_38[uVar3 & 0xff],a4,in_r8,*(code **)(*param_5 + 0x88));
  *param_2 = 0x10203;
  return;
}

/* FUN_000f8c88 @ 0xf8c88 (64 bytes) */
int FUN_000f8c88(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = param_1 + -0x30;
  if ((1 < iVar1) && (iVar1 = 2, param_1 != 0x5f)) {
    iVar1 = param_1 + -0x74;
  }
  return *(undefined4 *)(&DAT_001aa9e4 + iVar1 * 4);
}

/* FUN_000f8ccc @ 0xf8ccc (132 bytes) */
int FUN_000f8ccc(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  undefined *puVar2;
  
  iVar1 = (**(code **)(**(int **)(param_2 + 0x30c) + 0xdc))
                    (*(int **)(param_2 + 0x30c),param_2,param_3);
  if (iVar1 == 0) {
    puVar2 = (PTR_DAT_001e9f7c)[param_1 * 3];
  }
  else if (param_3 == 0) {
    puVar2 = (PTR_DAT_001e9f80)[param_1 * 3];
  }
  else {
    puVar2 = (PTR_DAT_001e9f78)[param_1 * 3];
  }
  return puVar2;
}

/* FUN_000f8d50 @ 0xf8d50 (568 bytes) */
int FUN_000f8d50(param_1, param_2, param_3, descriptor, param_5, inst, param_7)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  uint *descriptor;
  undefined4 param_5;
  int inst;
  int param_7;
{
  unsigned int ghidra_home[8] = { param_1, param_2, param_3, descriptor, param_5, inst, param_7, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  undefined *puVar1;
  undefined1 uVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined1 *puVar7;
  char *pcVar8;
  code *pcVar9;
  undefined4 uVar10;
  int *piVar11;
  int iVar12;
  char local_38 [28];
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 8)) = param_3;
  local_38[0] = '\0';
  local_38[1] = '\0';
  local_38[2] = '\0';
  local_38[3] = '\0';
  if (descriptor != (uint *)0x0) {
    uVar6 = *descriptor;
    if ((uVar6 & 0x1800000) == 0x800000) {
      if (*(int *)(param_1 + 0x3e4) == 0) {
        *(undefined4 *)(param_1 + 0x3f4) = *(undefined4 *)(inst + 0x98);
        *(undefined4 *)(param_1 + 0x3e4) = 1;
      }
      uVar5 = *(undefined4 *)(param_1 + 0x3ac);
      uVar10 = *(undefined4 *)(inst + 0x94);
      iVar4 = *(int *)(*(int *)(param_1 + 8) + 0x3c0) + 1;
      *(int *)(*(int *)(param_1 + 8) + 0x3c0) = iVar4;
      iVar4 = FUN_00127608(uVar5,0x2a,iVar4,0);
      *(undefined4 *)(iVar4 + 0x30) = uVar10;
      IRInst__setOperandRef(inst,0,iVar4);
      uVar6 = *descriptor;
    }
    if (((uVar6 & 0x400000) != 0) && ((descriptor[1] & 0x100) != 0)) {
      piVar11 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
      pcVar9 = *(code **)(*piVar11 + 0x78);
      uVar5 = FUN_000ec208(param_1,uVar6 >> 0x10 & 0x3f);
      iVar4 = (*pcVar9)(piVar11,uVar5);
      if (iVar4 == 0) {
        iVar4 = FUN_000ec208(param_1,*descriptor >> 0x10 & 0x3f);
        if (iVar4 != 9) {
          FUN_000ec208(param_1,*descriptor >> 0x10 & 0x3f);
        }
      }
      else {
        *(undefined4 *)(inst + 0x120) = 1;
      }
    }
    iVar4 = psnPackedLaneComponent(descriptor,0);
    puVar1 = PTR_DAT_001e8bc8;
    local_38[0] = (char)*(undefined4 *)(PTR_DAT_001e8bc8 + iVar4 * 4);
    iVar4 = psnPackedLaneComponent(descriptor,1);
    local_38[1] = (char)*(undefined4 *)(puVar1 + iVar4 * 4);
    iVar4 = psnPackedLaneComponent(descriptor,2);
    local_38[2] = (char)*(undefined4 *)(puVar1 + iVar4 * 4);
    iVar4 = psnPackedLaneComponent(descriptor,3);
    local_38[3] = (char)*(undefined4 *)(puVar1 + iVar4 * 4);
  }
  if (param_7 == 0) {
    iVar12 = 4;
    iVar4 = 0;
    pcVar8 = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 8));
    do {
      cVar3 = local_38[iVar4];
      if (*pcVar8 != '\0') {
        cVar3 = *pcVar8;
      }
      *(char *)(inst + 0x9c) = cVar3;
      iVar4 = iVar4 + 1;
      pcVar8 = pcVar8 + 1;
      inst = inst + 1;
      iVar12 = iVar12 + -1;
    } while (iVar12 != 0);
  }
  else {
    iVar12 = 4;
    iVar4 = 0;
    puVar7 = (undefined1 *)&(*(unsigned int *)((unsigned char *)ghidra_home + 8));
    do {
      uVar2 = 1;
      if (local_38[iVar4] != '\x01') {
        uVar2 = *puVar7;
      }
      *(undefined1 *)(inst + 0x9c) = uVar2;
      iVar4 = iVar4 + 1;
      puVar7 = puVar7 + 1;
      inst = inst + 1;
      iVar12 = iVar12 + -1;
    } while (iVar12 != 0);
  }
  return;
}

/* FUN_000f8f88 @ 0xf8f88 (176 bytes) */
int FUN_000f8f88(descriptor, param_2)
  uint *descriptor;
  int *param_2;
{
  bool bVar1;
  undefined *puVar2;
  int psnPackedLaneSourceResult;
  int iVar4;
  
  puVar2 = PTR_DAT_001e8bb8;
  iVar4 = 0;
  do {
    psnPackedLaneSourceResult = psnPackedLaneSource(descriptor,iVar4);
    (**(code **)(*param_2 + 0x88))(param_2,1,iVar4,*(undefined4 *)(puVar2 + psnPackedLaneSourceResult * 4));
    bVar1 = iVar4 != 3;
    iVar4 = iVar4 + 1;
  } while (bVar1);
  if ((*descriptor & 0x400000) != 0) {
    descriptor[1] = descriptor[1] & 0xffff8888 | 0x3210;
  }
  return;
}

/* FUN_000f9038 @ 0xf9038 (264 bytes) */
int FUN_000f9038(param_1, param_2, list)
  int param_1;
  undefined4 param_2;
  undefined4 list;
{
  undefined4 inst;
  int operandRecord;
  double dVar3;
  
  inst = IRInst__create(0x17,*(undefined4 *)(param_1 + 8));
  operandRecord = IRInst__getOperandRecord(inst,0);
  *(undefined4 *)(operandRecord + 0xc) = 0;
  *(undefined4 *)(operandRecord + 8) = param_2;
  operandRecord = IRInst__getOperandRecord(inst,1);
  dVar3 = (double)FLOAT_001aa0d4;
  *(undefined4 *)(operandRecord + 0xc) = 0;
  *(undefined4 *)(operandRecord + 8) = param_2;
  ((void (*)())IRInst__makeLiteralVec4Float)(inst,param_1,2,dVar3,dVar3,dVar3,dVar3);
  DList__pushBack(list,inst);
  inst = IRInst__create(0x19,*(undefined4 *)(param_1 + 8));
  operandRecord = IRInst__getOperandRecord(inst,0);
  *(undefined4 *)(operandRecord + 0xc) = 0;
  *(undefined4 *)(operandRecord + 8) = param_2;
  operandRecord = IRInst__getOperandRecord(inst,1);
  dVar3 = (double)FLOAT_001aa0e8;
  *(undefined4 *)(operandRecord + 0xc) = 0;
  *(undefined4 *)(operandRecord + 8) = param_2;
  ((void (*)())IRInst__makeLiteralVec4Float)(inst,param_1,2,dVar3,dVar3,dVar3,dVar3);
  DList__pushBack(list,inst);
  return inst;
}

/* FUN_000f9140 @ 0xf9140 (284 bytes) */
int FUN_000f9140(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  int *a0;
  int iVar1;
  undefined4 opcodeInfo;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar3;
  
  iVar3 = *(int *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 0xc);
  iVar3 = (**(code **)(param_2 * 0x24 + iVar3 + 0x14))
                    (*(undefined4 *)(param_2 * 0x24 + iVar3),*(int *)(param_1 + 8),param_3,in_r6,
                     in_r7,in_r8,iVar3);
  if ((param_3 != 0) &&
     (a0 = *(int **)(*(int *)(param_1 + 8) + 0x30c), iVar1 = (**(code **)(*a0 + 0xb0))(a0),
     iVar1 != 0)) {
    switch(param_2) {
    case 0x22:
      opcodeInfo = Opcode__getInfo(0xdf);
      *(undefined4 *)(iVar3 + 0x88) = opcodeInfo;
      break;
    case 0x23:
      opcodeInfo = Opcode__getInfo(0xde);
      *(undefined4 *)(iVar3 + 0x88) = opcodeInfo;
      break;
    case 0x40:
      opcodeInfo = Opcode__getInfo(0xf0);
      *(undefined4 *)(iVar3 + 0x88) = opcodeInfo;
      break;
    case 0x41:
      opcodeInfo = Opcode__getInfo(0xb7);
      *(undefined4 *)(iVar3 + 0x88) = opcodeInfo;
      break;
    case 0x44:
      opcodeInfo = Opcode__getInfo(0xb8);
      *(undefined4 *)(iVar3 + 0x88) = opcodeInfo;
      break;
    case 0x49:
      opcodeInfo = Opcode__getInfo(0xb6);
      *(undefined4 *)(iVar3 + 0x88) = opcodeInfo;
    }
  }
  return iVar3;
}

/* FUN_000f92fc @ 0xf92fc (480 bytes) */
int FUN_000f92fc(param_1, inst, block)
  int param_1;
  int *inst;
  undefined4 block;
{
  int operandRecord;
  uint uVar1;
  int iVar2;
  int *piVar3;
  void *inst2;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar2 = (**(code **)(*inst + 0x30))(inst,inst,block);
  if ((iVar2 != 0) &&
     (piVar3 = *(int **)(*(int *)(param_1 + 8) + 0x30c),
     iVar2 = (**(code **)(*piVar3 + 0x168))(piVar3,param_1,inst), iVar2 != 0)) {
    inst2 = IRInst__create(0x13,*(undefined4 *)(param_1 + 8));
    iVar5 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
    *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar5;
    operandRecord = IRInst__getOperandRecord(inst2,0);
    *(undefined4 *)(operandRecord + 0xc) = 0;
    *(int *)(operandRecord + 8) = iVar5;
    uVar1 = inst[0x4d];
    ((int (*)())IRInst__makeLiteralVec4Int)(inst2,param_1,1,uVar1 & 0xffff | 0x60000,uVar1 & 0xffff | 0x70000,
                 uVar1 & 0xffff | 0x70000,uVar1 & 0xffff | 0x70000);
    iVar6 = inst[0x2b];
    iVar7 = inst[0x2c];
    operandRecord = IRInst__getOperandRecord(inst2,2);
    *(int *)(operandRecord + 0xc) = iVar7;
    *(int *)(operandRecord + 8) = iVar6;
    ((int (*)())FUN_000f92fc)(param_1,inst2,block);
    inst2 = IRInst__create(0x31,*(undefined4 *)(param_1 + 8));
    operandRecord = IRInst__getOperandRecord(inst2,0);
    *(undefined4 *)(operandRecord + 0xc) = 0;
    *(int *)(operandRecord + 8) = iVar5;
    *(undefined4 *)((int)inst2 + 0x9c) = 0x1010000;
    iVar6 = inst[0x2b];
    iVar7 = inst[0x2c];
    operandRecord = IRInst__getOperandRecord(inst2,1);
    *(int *)(operandRecord + 8) = iVar6;
    *(int *)(operandRecord + 0xc) = iVar7;
    ((int (*)())FUN_000f92fc)(param_1,inst2,block);
    operandRecord = IRInst__getOperandRecord(inst,1);
    *(undefined4 *)(operandRecord + 0xc) = 0;
    *(int *)(operandRecord + 8) = iVar5;
  }
  Block__appendInst(block,inst);
  FUN_000ed63c(param_1,inst);
                    
                    
  (**(code **)(*inst + 8))(inst,*(undefined4 *)(param_1 + 8));
  return;
}

/* FUN_000f94dc @ 0xf94dc (968 bytes) */
int FUN_000f94dc(compiler, list, descriptor, param_4, param_5, param_6, param_7)
  int compiler;
  undefined4 list;
  uint *descriptor;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined4 successor;
  int operandRecord2;
  undefined4 arenaAt374;
  undefined4 *instAlloc;
  uint loopIndex;
  int loopIndex2;
  uint uVar1;
  undefined4 uVar2;
  undefined4 *allocation;
  int iVar4;
  void *inst;
  int operandRecord;
  int *piVar7;
  undefined4 *puVar8;
  uint uVar9;
  undefined4 *puVar10;
  int iVar11;
  undefined4 *puVar12;
  int iVar13;
  undefined4 arena;
  undefined4 local_68 [4];
  undefined4 local_58 [4];
  
  if (*(int *)(compiler + COMP_arenaA) == 0) {
    uVar9 = 0;
    switch(param_7) {
    case 0:
      uVar9 = 1;
      break;
    case 1:
      uVar9 = 2;
      break;
    case 2:
      uVar9 = 3;
      break;
    case 3:
      uVar9 = 4;
      break;
    case 4:
      uVar9 = 6;
    }
    Block__successorCount(*(undefined4 *)(compiler + 0x3a0));
    successor = Block__getSuccessor(*(undefined4 *)(compiler + 0x3a0),0);
    arena = *(undefined4 *)(*(int *)(compiler + 8) + 0x374);
    allocation = (undefined4 *)Arena__alloc(arena,0x168);
    *allocation = arena;
    puVar12 = allocation + 1;
    FUN_00109cfc(puVar12,0x83,*(undefined4 *)(compiler + 8));
    operandRecord2 = IRInst__getOperandRecord(puVar12,0);
    *(undefined4 *)(operandRecord2 + 0xc) = 0x39;
    *(undefined4 *)(operandRecord2 + 8) = 0;
    uVar1 = uVar9;
    if (3 < uVar9) {
      uVar1 = 3;
    }
    allocation[0x22] = uVar1;
    puVar10 = (undefined4 *)0x0;
    if (uVar9 != 0) {
      loopIndex = 0;
      loopIndex2 = 1;
      iVar11 = -2;
      do {
        iVar13 = loopIndex + 2;
        inst = IRInst__create(0x31,*(undefined4 *)(compiler + 8));
        FUN_00130478(compiler,iVar13);
        operandRecord = IRInst__getOperandRecord(inst,0);
        *(int *)(operandRecord + 8) = iVar13;
        *(undefined4 *)(operandRecord + 0xc) = 0x10;
        *(undefined4 *)((int)inst + 0x9c) = 0x10101;
        Program__markHwRegUsed(compiler,iVar13);
        FUN_00130bd4(compiler,iVar13);
        piVar7 = *(int **)(*(int *)(compiler + 8) + 0x30c);
        arena = (**(code **)(*piVar7 + 0x9c))(piVar7,loopIndex,*(int *)(compiler + 8));
        operandRecord = IRInst__getOperandRecord(inst,1);
        *(undefined4 *)(operandRecord + 8) = arena;
        *(undefined4 *)(operandRecord + 0xc) = 0x1f;
        piVar7 = *(int **)(*(int *)(compiler + 8) + 0x30c);
        (**(code **)(*piVar7 + 0xa0))(local_58,piVar7,loopIndex,*(int *)(compiler + 8));
        arena = local_58[0];
        operandRecord = IRInst__getOperandRecord(inst,1);
        *(undefined4 *)(operandRecord + 0x10) = arena;
        ((int (*)())FUN_000f92fc)(compiler,inst,successor);
        if ((int)loopIndex < 3) {
          IRInst__setOperandRef(puVar12,loopIndex2,*(undefined4 *)((int)inst + 0x8c));
          if (loopIndex2 == 0) {
            allocation[0x28] = 0;
          }
          else {
            operandRecord = IRInst__getOperandRecord(puVar12,loopIndex2);
            *(undefined4 *)(operandRecord + 0x10) = 0;
          }
        }
        else {
          if (puVar10 == (undefined4 *)0x0) {
            arena = *(undefined4 *)(*(int *)(compiler + 8) + 0x374);
            instAlloc = (undefined4 *)Arena__alloc(arena,0x168);
            *instAlloc = arena;
            puVar10 = instAlloc + 1;
            FUN_00109cfc(puVar10,0x83,*(undefined4 *)(compiler + 8));
            operandRecord = IRInst__getOperandRecord(puVar10,0);
            *(undefined4 *)(operandRecord + 0xc) = 0x39;
            arena = 4;
            *(undefined4 *)(operandRecord + 8) = 1;
            if (uVar9 == 4) {
              arena = 2;
            }
            instAlloc[0x22] = arena;
          }
          IRInst__setOperandRef(puVar10,iVar11,*(undefined4 *)((int)inst + 0x8c));
          if (iVar11 == 0) {
            puVar10[0x27] = 0;
          }
          else {
            operandRecord = IRInst__getOperandRecord(puVar10,iVar11);
            *(undefined4 *)(operandRecord + 0x10) = 0;
          }
        }
        arena = *(undefined4 *)(*(int *)(compiler + 8) + 0x374);
        instAlloc = (undefined4 *)Arena__alloc(arena,0x168);
        *instAlloc = arena;
        puVar8 = instAlloc + 1;
        FUN_00109428(puVar8,0x7a,*(undefined4 *)(compiler + 8));
        operandRecord = IRInst__getOperandRecord(puVar8,0);
        *(undefined4 *)(operandRecord + 0xc) = 0x10;
        loopIndex = loopIndex + 1;
        *(int *)(operandRecord + 8) = iVar13;
        loopIndex2 = loopIndex2 + 1;
        iVar11 = iVar11 + 1;
        ((int (*)())FUN_000f92fc)(compiler,puVar8,*(undefined4 *)(compiler + 0x3a0));
      } while (uVar9 != loopIndex);
    }
    ((int (*)())FUN_000f92fc)(compiler,puVar12,successor);
    if (puVar10 == (undefined4 *)0x0) {
      *(undefined4 **)(compiler + COMP_arenaA) = puVar12;
    }
    else {
      arena = 2;
      if (uVar9 != 4) {
        arena = 4;
      }
      IRInst__setOperandRef(puVar10,arena,allocation[0x24]);
      ((int (*)())FUN_000f92fc)(compiler,puVar10,successor);
      *(undefined4 **)(compiler + COMP_arenaA) = puVar10;
    }
  }
  arenaAt374 = *(undefined4 *)(*(int *)(compiler + 8) + 0x374);
  allocation = (undefined4 *)Arena__alloc(arenaAt374,0x168);
  *allocation = arenaAt374;
  puVar12 = allocation + 1;
  IRProjection__ctor_109e28(puVar12,0x84,*(undefined4 *)(compiler + 8));
  iVar11 = *(int *)(*(int *)(compiler + 8) + 0x3b4) + 1;
  *(int *)(*(int *)(compiler + 8) + 0x3b4) = iVar11;
  iVar4 = FUN_00127608(*(undefined4 *)(compiler + 0x3ac),0x3a,iVar11,0);
  *(undefined4 *)(iVar4 + 0x30) = 2;
  IRInst__setOperandRef(puVar12,0,iVar4);
  uVar9 = *descriptor;
  uVar2 = FUN_000ec208(compiler,*descriptor >> 0x10 & 0x3f);
  operandRecord2 = IRInst__getOperandRecord(puVar12,1);
  *(undefined4 *)(operandRecord2 + 0xc) = uVar2;
  *(uint *)(operandRecord2 + 8) = (uint)(ushort)uVar9;
  local_68[0] = 0x10203;
  ((int (*)())FUN_000f8aa0)(compiler,local_68,descriptor,1,puVar12);
  allocation[0x4d] = 1;
  DList__pushBack(list,puVar12);
  inst = IRInst__create(0x31,*(undefined4 *)(compiler + 8));
  uVar2 = FUN_000ec208(compiler,param_6);
  operandRecord2 = IRInst__getOperandRecord(inst,0);
  *(undefined4 *)(operandRecord2 + 0xc) = uVar2;
  *(undefined4 *)(operandRecord2 + 8) = param_5;
  *(undefined4 *)((int)inst + 0x9c) = 0x10101;
  operandRecord2 = IRInst__getOperandRecord(inst,1);
  *(undefined4 *)(operandRecord2 + 0xc) = 0x3a;
  *(int *)(operandRecord2 + 8) = iVar11;
  IRInst__appendSource(inst,*(undefined4 *)(*(int *)(compiler + COMP_arenaA) + 0x8c));
  DList__pushBack(list,inst);
  return;
}

/* FUN_000f9a58 @ 0xf9a58 (2736 bytes) */
int FUN_000f9a58(pass, list, descriptor, param_4, param_5)
  int pass;
  undefined4 list;
  uint *descriptor;
  undefined4 param_4;
  int param_5;
{
  int psnPackedLaneComponentResult;
  void *newInst;
  int operandRecord2;
  int operandRecord;
  int operandRecord3;
  bool bVar1;
  bool bVar2;
  void *pvVar3;
  void *pvVar4;
  int iVar5;
  undefined4 arena;
  undefined4 *allocation;
  int iVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  code *pcVar15;
  uint uVar16;
  uint uVar17;
  int *piVar18;
  undefined4 uVar19;
  int iVar20;
  undefined4 *puVar21;
  double fparam_1;
  undefined4 local_68;
  undefined4 local_64 [7];
  
  iVar8 = (int)(short)*descriptor;
  uVar10 = *descriptor >> 0x10 & 0x3f;
  if (((*descriptor & 0x400000) == 0) || (uVar14 = descriptor[1] >> 9 & 0xf, uVar14 == 0)) {
    pvVar4 = (void *)0x0;
    iVar20 = 0;
  }
  else {
    iVar20 = *(int *)(*(int *)(pass + 8) + 0x3ac) + -1;
    *(int *)(*(int *)(pass + 8) + 0x3ac) = iVar20;
    *(short *)((int)descriptor + 2) = (short)iVar20;
    *descriptor = *descriptor & 0xffc0ffff | 0x40000;
    pvVar4 = IRInst__create(0x13,*(undefined4 *)(pass + 8));
    operandRecord2 = IRInst__getOperandRecord(pvVar4,0);
    *(undefined4 *)(operandRecord2 + 0xc) = 0;
    *(int *)(operandRecord2 + 8) = iVar20;
    operandRecord2 = IRInst__getOperandRecord(pvVar4,1);
    *(undefined4 *)(operandRecord2 + 0xc) = 0;
    fparam_1 = (double)*(float *)(&DAT_001aa9fc + uVar14 * 4);
    *(int *)(operandRecord2 + 8) = iVar20;
    ((void (*)())IRInst__makeLiteralVec4Float)(pvVar4,pass,2,fparam_1,fparam_1,fparam_1,fparam_1);
    DList__pushBack(list,pvVar4);
  }
  uVar14 = 0;
  uVar17 = 0;
  do {
    psnPackedLaneComponentResult = psnPackedLaneComponent(descriptor,uVar17);
    bVar1 = uVar17 != 3;
    uVar14 = uVar14 | (uint)(psnPackedLaneComponentResult == 2) << (uVar17 & 0x3f);
    uVar17 = uVar17 + 1;
  } while (bVar1);
  if (uVar14 != 0) {
    if (pvVar4 == (void *)0x0) {
      iVar20 = *(int *)(*(int *)(pass + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(pass + 8) + 0x3ac) = iVar20;
      *(short *)((int)descriptor + 2) = (short)iVar20;
      *descriptor = *descriptor & 0xffc0ffff | 0x40000;
    }
    pvVar4 = IRInst__create(0x31,*(undefined4 *)(pass + 8));
    operandRecord2 = IRInst__getOperandRecord(pvVar4,0);
    *(undefined4 *)(operandRecord2 + 0xc) = 0;
    *(int *)(operandRecord2 + 8) = iVar20;
    ((void (*)())IRInst__makeLiteralVec4Float)(pvVar4,pass,1,0.0,0.0,0.0,0.0);
    iVar5 = 4;
    uVar17 = 0;
    pvVar3 = pvVar4;
    do {
      if (((int)uVar14 >> (uVar17 & 0x3f) & 1U) == 0) {
        *(undefined1 *)((int)pvVar3 + 0x9c) = 1;
      }
      else {
        *(undefined1 *)((int)pvVar3 + 0x9c) = 0;
      }
      uVar17 = uVar17 + 1;
      pvVar3 = (void *)((int)pvVar3 + 1);
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    DList__pushBack(list,pvVar4);
  }
  uVar14 = 0;
  uVar17 = 0;
  do {
    psnPackedLaneComponentResult = psnPackedLaneComponent(descriptor,uVar17);
    bVar1 = uVar17 != 3;
    uVar14 = uVar14 | (uint)(psnPackedLaneComponentResult == 3) << (uVar17 & 0x3f);
    uVar17 = uVar17 + 1;
  } while (bVar1);
  if (uVar14 != 0) {
    if (pvVar4 == (void *)0x0) {
      iVar20 = *(int *)(*(int *)(pass + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(pass + 8) + 0x3ac) = iVar20;
      *(short *)((int)descriptor + 2) = (short)iVar20;
      *descriptor = *descriptor & 0xffc0ffff | 0x40000;
    }
    pvVar4 = IRInst__create(0x31,*(undefined4 *)(pass + 8));
    operandRecord2 = IRInst__getOperandRecord(pvVar4,0);
    *(undefined4 *)(operandRecord2 + 0xc) = 0;
    *(int *)(operandRecord2 + 8) = iVar20;
    ((void (*)())IRInst__makeLiteralVec4Float)(pvVar4,pass,1,1.0,1.0,1.0,1.0);
    iVar5 = 4;
    uVar17 = 0;
    pvVar3 = pvVar4;
    do {
      if (((int)uVar14 >> (uVar17 & 0x3f) & 1U) == 0) {
        *(undefined1 *)((int)pvVar3 + 0x9c) = 1;
      }
      else {
        *(undefined1 *)((int)pvVar3 + 0x9c) = 0;
      }
      uVar17 = uVar17 + 1;
      pvVar3 = (void *)((int)pvVar3 + 1);
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    DList__pushBack(list,pvVar4);
  }
  uVar14 = 0;
  if ((*descriptor & 0x400000) != 0) {
    uVar14 = descriptor[1];
    uVar14 = (uint)((uVar14 & 0xc0) == 0) |
             (uint)((uVar14 & 0x30) == 0) << 8 |
             (uint)((uVar14 & 0xc) == 0) << 0x10 | (uint)((uVar14 & 3) == 0) << 0x18;
  }
  iVar5 = FUN_0019eb30(descriptor);
  if (iVar5 != 0) {
    pvVar4 = IRInst__create(0x31,*(undefined4 *)(pass + 8));
    operandRecord2 = IRInst__getOperandRecord(pvVar4,0);
    *(undefined4 *)(operandRecord2 + 0xc) = 0;
    *(int *)(operandRecord2 + 8) = iVar20;
    operandRecord2 = IRInst__getOperandRecord(pvVar4,1);
    *(undefined4 *)(operandRecord2 + 0xc) = 0;
    *(int *)(operandRecord2 + 8) = iVar20;
    DList__pushBack(list,pvVar4);
  }
  uVar17 = *descriptor;
  if (((uVar17 & 0x400000) == 0) || ((descriptor[1] & 0x100) == 0)) {
LAB_000f9f08:
    bVar1 = false;
  }
  else {
    piVar18 = *(int **)(*(int *)(pass + 8) + 0x30c);
    pcVar15 = *(code **)(*piVar18 + 0x78);
    arena = FUN_000ec208(pass,uVar10);
    iVar5 = (*pcVar15)(piVar18,arena);
    if (iVar5 == 0) {
      iVar20 = FUN_000ec208(pass,*descriptor >> 0x10 & 0x3f);
      if (iVar20 == 9) {
        uVar17 = *descriptor;
        goto LAB_000f9f08;
      }
      FUN_000ec208(pass,*descriptor >> 0x10 & 0x3f);
      uVar17 = *descriptor;
      bVar1 = false;
    }
    else {
      piVar18 = *(int **)(*(int *)(pass + 8) + 0x30c);
      iVar5 = (**(code **)(*piVar18 + 0x80))(piVar18);
      if (iVar5 == 0) {
        if (pvVar4 == (void *)0x0) {
          iVar20 = *(int *)(*(int *)(pass + 8) + 0x3ac) + -1;
          *(int *)(*(int *)(pass + 8) + 0x3ac) = iVar20;
          *(short *)((int)descriptor + 2) = (short)iVar20;
          *descriptor = *descriptor & 0xffc0ffff | 0x40000;
        }
        pvVar4 = (void *)((int (*)())FUN_000f9038)(pass,iVar20,list);
        uVar17 = *descriptor;
        if ((uVar17 & 0x400000) == 0) goto LAB_000f9f08;
        bVar1 = false;
        descriptor[1] = descriptor[1] & 0xfffffeff;
      }
      else {
        uVar17 = *descriptor;
        bVar1 = true;
      }
    }
  }
  if (pvVar4 != (void *)0x0) {
    if ((uVar17 & 0x1800000) == 0x800000) {
      if (*(int *)(pass + 0x3e4) == 0) {
        *(undefined4 *)(pass + 0x3e4) = 1;
        arena = FUN_000ec208(pass,uVar10);
        *(undefined4 *)(pass + 0x3f4) = arena;
      }
      else {
        FUN_000ec208(pass,uVar10);
      }
      arena = *(undefined4 *)(pass + 0x3ac);
      iVar20 = *(int *)(*(int *)(pass + 8) + 0x3c0) + 1;
      *(int *)(*(int *)(pass + 8) + 0x3c0) = iVar20;
      iVar20 = FUN_00127608(arena,0x2a,iVar20,0);
      *(int *)(iVar20 + 0x30) = iVar8;
      IRInst__setOperandRef(pvVar4,0,iVar20);
      *descriptor = *descriptor & 0xfe7fffff;
    }
    else {
      arena = FUN_000ec208(pass,uVar10);
      operandRecord = IRInst__getOperandRecord(pvVar4,0);
      *(undefined4 *)(operandRecord + 0xc) = arena;
      *(int *)(operandRecord + 8) = iVar8;
    }
    if (bVar1) {
      *(undefined4 *)((int)pvVar4 + 0x120) = 1;
    }
    if ((*descriptor & 0x400000) != 0) {
      descriptor[1] = descriptor[1] & 0xfffffeff;
    }
    iVar20 = 0;
    do {
      psnPackedLaneComponentResult = psnPackedLaneComponent(descriptor,iVar20);
      if (psnPackedLaneComponentResult == 0) {
        *(undefined1 *)((int)pvVar4 + 0x9c) = 1;
      }
      else {
        *(undefined1 *)((int)pvVar4 + 0x9c) = 0;
      }
      bVar1 = iVar20 != 3;
      pvVar4 = (void *)((int)pvVar4 + 1);
      iVar20 = iVar20 + 1;
    } while (bVar1);
    uVar17 = *descriptor;
    if ((uVar17 & 0x400000) != 0) {
      descriptor[1] = descriptor[1] & 0xffffff00 | 0x55;
    }
  }
  if ((uVar10 != 0x1f) || ((*(uint *)(pass + 0x30) & 0x4000) == 0)) {
    bVar1 = false;
    bVar2 = false;
  }
  else {
    bVar1 = true;
    bVar2 = true;
  }
  if (((undefined4 *)(uVar17 & 0x3f0000) != 0x001b0000) && (!bVar1)) goto LAB_000fa744;
  iVar20 = 1;
  iVar5 = *(int *)(*(int *)(pass + 8) + 0x3ac) + -1;
  *(int *)(*(int *)(pass + 8) + 0x3ac) = iVar5;
  uVar17 = *descriptor;
  uVar12 = (uint)(ushort)*descriptor;
  uVar11 = uVar17 >> 0x10 & 0x3f;
  if ((int)uVar17 < 0) {
    iVar20 = 2;
    uVar12 = uVar12 | descriptor[1] << 0x10;
  }
  if ((uVar17 & 0x400000) != 0) {
    iVar20 = iVar20 + 1;
  }
  if ((uVar17 & 0x1800000) == 0x1000000) {
    puVar9 = descriptor + iVar20;
    if (!bVar2) {
      arena = *(undefined4 *)(*(int *)(pass + 8) + 0x374);
      allocation = (undefined4 *)Arena__alloc(arena,0x168);
      *allocation = arena;
      puVar21 = allocation + 1;
      FUN_001071fc(puVar21,0xfc,*(undefined4 *)(pass + 8));
      arena = FUN_000ec208(pass,uVar11);
      operandRecord3 = IRInst__getOperandRecord(puVar21,0);
      *(undefined4 *)(operandRecord3 + 0xc) = arena;
      *(uint *)(operandRecord3 + 8) = uVar12;
      arena = FUN_000ec208(pass,4);
      operandRecord3 = IRInst__getOperandRecord(puVar21,1);
      allocation[0x28] = uVar14;
      *(undefined4 *)(operandRecord3 + 0xc) = arena;
      *(int *)(operandRecord3 + 8) = iVar5;
      if ((*descriptor & 0x4000000) == 0) goto LAB_000fa1bc;
      iVar13 = *(int *)(*(int *)(pass + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(pass + 8) + 0x3ac) = iVar13;
      uVar17 = descriptor[iVar20 + 2];
      newInst = IRInst__create(0xc6,*(undefined4 *)(pass + 8));
      arena = FUN_000ec208(pass,4);
      operandRecord = IRInst__getOperandRecord(newInst,0);
      *(undefined4 *)(operandRecord + 0xc) = arena;
      *(int *)(operandRecord + 8) = iVar13;
      uVar14 = *puVar9;
      arena = FUN_000ec208(pass,*puVar9 >> 0x10 & 0x3f);
      operandRecord = IRInst__getOperandRecord(newInst,1);
      *(undefined4 *)(operandRecord + 0xc) = arena;
      *(uint *)(operandRecord + 8) = (uint)(ushort)uVar14;
      ((int (*)())FUN_000f7870)(newInst,pass,2,uVar17,uVar17,uVar17,uVar17);
      DList__pushBack(list,newInst);
      arena = FUN_000ec208(pass,4);
      operandRecord = IRInst__getOperandRecord(puVar21,2);
      *(undefined4 *)(operandRecord + 0xc) = arena;
      *(int *)(operandRecord + 8) = iVar13;
    }
    else {
      arena = *(undefined4 *)(*(int *)(pass + 8) + 0x374);
      allocation = (undefined4 *)Arena__alloc(arena,0x168);
      *allocation = arena;
      puVar21 = allocation + 1;
      FUN_00108a50(puVar21,0xf9,*(undefined4 *)(pass + 8));
      allocation[0x28] = uVar14;
      allocation[0x22] = 2;
      if ((*descriptor & 0x4000000) != 0) {
        uVar12 = uVar12 + descriptor[iVar20 + 2];
      }
      allocation[0x51] = uVar12;
      allocation[0x50] = 0x24;
      arena = FUN_00127608(*(undefined4 *)(*(int *)(*(int *)(pass + 8) + 0x6c4) + 0x3ac),0x2c,0,0
                          );
      IRInst__setOperandRef(puVar21,0,arena);
      operandRecord = IRInst__getOperandRecord(puVar21,1);
      *(undefined4 *)(operandRecord + 0xc) = 0;
      *(int *)(operandRecord + 8) = iVar5;
LAB_000fa1bc:
      uVar14 = *puVar9;
      arena = FUN_000ec208(pass,*puVar9 >> 0x10 & 0x3f);
      operandRecord = IRInst__getOperandRecord(puVar21,2);
      *(undefined4 *)(operandRecord + 0xc) = arena;
      *(uint *)(operandRecord + 8) = (uint)(ushort)uVar14;
      if (bVar2) goto LAB_000fa4f8;
    }
    arena = FUN_000ec208(pass,uVar11);
    operandRecord = IRInst__getOperandRecord(puVar21,3);
    *(undefined4 *)(operandRecord + 0xc) = arena;
    *(uint *)(operandRecord + 8) = uVar12;
    local_64[0] = 0x10203;
    ((int (*)())FUN_000f8aa0)(pass,local_64,puVar9,2,puVar21);
  }
  else if ((uVar17 & 0x1800000) == 0) {
    uVar16 = 0;
    if ((uVar17 & 0x4000000) != 0) {
      uVar16 = descriptor[iVar20];
    }
    if (bVar2) {
      arena = *(undefined4 *)(*(int *)(pass + 8) + 0x374);
      allocation = (undefined4 *)Arena__alloc(arena,0x168);
      *allocation = arena;
      puVar21 = allocation + 1;
      FUN_00108770(puVar21,*(undefined4 *)(pass + 8));
      allocation[0x28] = uVar14;
      allocation[0x50] = 0x24;
      allocation[0x51] = uVar12;
      arena = FUN_00127608(*(undefined4 *)(*(int *)(*(int *)(pass + 8) + 0x6c4) + 0x3ac),0x2c,0,0
                          );
      IRInst__setOperandRef(puVar21,0,arena);
      operandRecord = IRInst__getOperandRecord(puVar21,1);
      *(undefined4 *)(operandRecord + 0xc) = 0;
      *(int *)(operandRecord + 8) = iVar5;
    }
    else {
      arena = *(undefined4 *)(*(int *)(pass + 8) + 0x374);
      allocation = (undefined4 *)Arena__alloc(arena,0x168);
      *allocation = arena;
      puVar21 = allocation + 1;
      FUN_001071fc(puVar21,0xfc,*(undefined4 *)(pass + 8));
      arena = FUN_000ec208(pass,uVar11);
      operandRecord = IRInst__getOperandRecord(puVar21,0);
      *(undefined4 *)(operandRecord + 0xc) = arena;
      *(uint *)(operandRecord + 8) = uVar12;
      arena = FUN_000ec208(pass,4);
      operandRecord = IRInst__getOperandRecord(puVar21,1);
      *(undefined4 *)(operandRecord + 0xc) = arena;
      *(int *)(operandRecord + 8) = iVar5;
      ((int (*)())FUN_000f7870)(puVar21,pass,2,uVar16,uVar16,uVar16,uVar16);
      allocation[0x28] = uVar14;
    }
  }
  else {
    puVar21 = (undefined4 *)0x0;
  }
LAB_000fa4f8:
  operandRecord = IRInst__getOperandRecord(puVar21,2);
  local_68 = *(undefined4 *)(operandRecord + 0x10);
  piVar18 = *(int **)(*(int *)(pass + 8) + 0x30c);
  iVar20 = (**(code **)(*piVar18 + 0x104))(piVar18,puVar21,2,&local_68,0);
  if (iVar20 == 0) {
    iVar13 = *(int *)(*(int *)(pass + 8) + 0x3ac) + -1;
    *(int *)(*(int *)(pass + 8) + 0x3ac) = iVar13;
    newInst = IRInst__create(0x31,*(undefined4 *)(pass + 8));
    uVar19 = puVar21[0x32];
    arena = puVar21[0x31];
    operandRecord = IRInst__getOperandRecord(newInst,1);
    *(undefined4 *)(operandRecord + 0xc) = uVar19;
    *(undefined4 *)(operandRecord + 8) = arena;
    arena = FUN_000ec208(pass,4);
    operandRecord = IRInst__getOperandRecord(newInst,0);
    *(undefined4 *)(operandRecord + 0xc) = arena;
    *(int *)(operandRecord + 8) = iVar13;
    operandRecord = IRInst__getOperandRecord(puVar21,2);
    arena = *(undefined4 *)(operandRecord + 0x10);
    operandRecord = IRInst__getOperandRecord(newInst,1);
    *(undefined4 *)(operandRecord + 0x10) = arena;
    DList__pushBack(list,newInst);
    arena = FUN_000ec208(pass,4);
    operandRecord = IRInst__getOperandRecord(puVar21,2);
    *(undefined4 *)(operandRecord + 0xc) = arena;
    *(int *)(operandRecord + 8) = iVar13;
    iVar20 = IRInst__getOperandRecord(puVar21,2);
    *(undefined4 *)(iVar20 + 0x10) = 0;
  }
  if ((!bVar2) &&
     (piVar18 = *(int **)(*(int *)(pass + 8) + 0x30c),
     iVar20 = (**(code **)(*piVar18 + 0x104))(piVar18,puVar21,1,&local_68,0), iVar20 == 0)) {
    iVar13 = *(int *)(*(int *)(pass + 8) + 0x3ac) + -1;
    *(int *)(*(int *)(pass + 8) + 0x3ac) = iVar13;
    newInst = IRInst__create(0x31,*(undefined4 *)(pass + 8));
    uVar19 = puVar21[0x2c];
    arena = puVar21[0x2b];
    operandRecord = IRInst__getOperandRecord(newInst,1);
    *(undefined4 *)(operandRecord + 0xc) = uVar19;
    *(undefined4 *)(operandRecord + 8) = arena;
    arena = FUN_000ec208(pass,4);
    operandRecord = IRInst__getOperandRecord(newInst,0);
    *(undefined4 *)(operandRecord + 0xc) = arena;
    *(int *)(operandRecord + 8) = iVar13;
    operandRecord = IRInst__getOperandRecord(puVar21,1);
    arena = *(undefined4 *)(operandRecord + 0x10);
    operandRecord = IRInst__getOperandRecord(newInst,1);
    *(undefined4 *)(operandRecord + 0x10) = arena;
    DList__pushBack(list,newInst);
    arena = FUN_000ec208(pass,4);
    operandRecord = IRInst__getOperandRecord(puVar21,1);
    *(undefined4 *)(operandRecord + 0xc) = arena;
    *(int *)(operandRecord + 8) = iVar13;
    operandRecord = IRInst__getOperandRecord(puVar21,1);
    *(undefined4 *)(operandRecord + 0x10) = 0x10203;
  }
  DList__pushBack(list,puVar21);
  *descriptor = *descriptor & 0xffc0ffff | 0x40000;
  *(short *)((int)descriptor + 2) = (short)iVar5;
LAB_000fa744:
  if ((uVar10 == 0x1f) && ((*(uint *)(pass + 0x30) & 0x200000) != 0)) {
    iVar5 = *(int *)(*(int *)(pass + 8) + 0x3ac) + -1;
    *(int *)(*(int *)(pass + 8) + 0x3ac) = iVar5;
    iVar13 = *(int *)(*(int *)(pass + 8) + 0x3ac) + -1;
    *(int *)(*(int *)(pass + 8) + 0x3ac) = iVar13;
    newInst = IRInst__create(0xcc,*(undefined4 *)(pass + 8));
    operandRecord = IRInst__getOperandRecord(newInst,0);
    *(undefined4 *)(operandRecord + 0xc) = 0;
    *(int *)(operandRecord + 8) = iVar13;
    operandRecord = IRInst__getOperandRecord(newInst,1);
    *(undefined4 *)(operandRecord + 8) = 0;
    *(undefined4 *)(operandRecord + 0xc) = 0x1f;
    operandRecord = IRInst__getOperandRecord(newInst,1);
    *(undefined4 *)(operandRecord + 0x10) = 0x1010101;
    if (param_5 == 1) {
      ((int (*)())FUN_000f7870)(newInst,pass,2,1,1,1,1);
    }
    else if (param_5 < 2) {
      if (param_5 == 0) {
        ((int (*)())FUN_000f7870)(newInst,pass,2,0,0,0,0);
      }
    }
    else if (param_5 == 2) {
      ((int (*)())FUN_000f7870)(newInst,pass,2,2,2,2,2);
    }
    else if (param_5 == 3) {
      ((int (*)())FUN_000f7870)(newInst,pass,2,3,3,3,3);
    }
    DList__pushBack(list,newInst);
    newInst = IRInst__create(0x24,*(undefined4 *)(pass + 8));
    arena = FUN_000ec208(pass,0x1f);
    operandRecord = IRInst__getOperandRecord(newInst,0);
    *(undefined4 *)(operandRecord + 0xc) = arena;
    *(int *)(operandRecord + 8) = iVar8;
    operandRecord = IRInst__getOperandRecord(newInst,1);
    *(undefined4 *)(operandRecord + 0xc) = 0;
    *(int *)(operandRecord + 8) = iVar13;
    arena = FUN_000ec208(pass,4);
    operandRecord = IRInst__getOperandRecord(newInst,2);
    *(undefined4 *)(operandRecord + 0xc) = arena;
    *(int *)(operandRecord + 8) = iVar5;
    arena = FUN_000ec208(pass,0x1f);
    operandRecord = IRInst__getOperandRecord(newInst,3);
    *(undefined4 *)(operandRecord + 0xc) = arena;
    *(int *)(operandRecord + 8) = iVar8;
    DList__pushBack(list,newInst);
    *descriptor = *descriptor & 0xffc0ffff | 0x40000;
    *(short *)((int)descriptor + 2) = (short)iVar5;
  }
  return;
}

/* FUN_000fa958 @ 0xfa958 (1132 bytes) */
int FUN_000fa958(param_1, param_2, operandIndex, param_4, inst, param_6, param_7, param_8, param_9, param_10, block)
  int param_1;
  int param_2;
  int operandIndex;
  int param_4;
  int inst;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
  undefined4 param_10;
  undefined4 block;
{
  undefined4 newInst2;
  int operandRecord2;
  int operandRecord4;
  int newInst;
  int operandRecord;
  int operandRecord3;
  int loopIndex;
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  uint *puVar10;
  uint uVar11;
  undefined4 local_48;
  undefined4 local_44;
  
  uVar11 = *(uint *)(PTR_DAT_001e8b88 + param_2 * 4);
  if (operandIndex != 0) {
    uVar8 = uVar11 >> 0x1c & 1;
LAB_000fabd8:
    if (uVar8 == 0) {
      puVar5 = *(uint **)(((uVar11 >> 0x17 & 7) * 5 + (uVar11 >> 0x1d)) * 4 +
                         *(int *)(param_4 + 0x6c));
      puVar10 = puVar5;
    }
    else {
      puVar5 = (uint *)0x0;
      puVar10 = *(uint **)(((uVar11 >> 0x17 & 7) * 5 + (uVar11 >> 0x1d)) * 4 +
                          *(int *)(param_4 + 100));
      local_44 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_44) + 0)),(short)*puVar10);
      local_44 = *puVar10 & 0x1800000 | *puVar10 & 0x3f0000 | local_44 & 0xfe40ffff;
      puVar10 = &local_44;
    }
    uVar8 = *puVar10 >> 0x10 & 0x3f;
    iVar3 = *(int *)(param_1 + 8);
    if ((((*puVar10 & 0x3f0000) == 0x100000) && (iVar3 != 0)) &&
       ((*(uint *)(*(int *)(iVar3 + 0x30c) + 8) & 0x80) != 0)) {
      iVar7 = 0xf;
    }
    else {
      iVar7 = (int)(short)*puVar10;
    }
    if ((uVar8 == 0x12) && ((uVar11 & 0x3800000) != 0)) {
      iVar7 = 0;
      uVar8 = 0x13;
    }
    if (((uVar11 >> 0x1b & 1) == 0) && ((uVar8 == 1 || (uVar8 == 0x22)))) {
      iVar1 = *(int *)(iVar3 + 0x3ac) + -1;
      *(int *)(iVar3 + 0x3ac) = iVar1;
      newInst2 = IRInst__create(0x31,*(undefined4 *)(param_1 + 8));
      operandRecord = IRInst__getOperandRecord(newInst2,0);
      *(undefined4 *)(operandRecord + 0xc) = 0;
      *(int *)(operandRecord + 8) = iVar1;
      uVar9 = FUN_000ec208(param_1,uVar8);
      operandRecord = IRInst__getOperandRecord(newInst2,1);
      *(undefined4 *)(operandRecord + 0xc) = uVar9;
      *(int *)(operandRecord + 8) = iVar7;
      ((int (*)())FUN_000f8aa0)(param_1,param_8,puVar10,operandIndex,newInst2);
      ((int (*)())FUN_000f92fc)(param_1,newInst2,block);
      uVar8 = 4;
      *puVar10 = *puVar10 & 0xfe3fffff;
      *(short *)((int)puVar10 + 2) = (short)iVar1;
      *puVar10 = *puVar10 & 0xffc0ffff | 0x40000;
      iVar7 = iVar1;
    }
    else {
      ((int (*)())FUN_000f8aa0)(param_1,param_8,puVar5,operandIndex,inst);
    }
    uVar2 = FUN_000ec208(param_1,uVar8);
    operandRecord = IRInst__getOperandRecord(inst,operandIndex);
    *(undefined4 *)(operandRecord + 0xc) = uVar2;
    *(int *)(operandRecord + 8) = iVar7;
    return 0;
  }
  uVar8 = 0;
  if ((uVar11 >> 0x1c & 1) == 0) goto LAB_000fabd8;
  puVar10 = *(uint **)(((uVar11 >> 0x17 & 7) * 5 + (uVar11 >> 0x1d)) * 4 + *(int *)(param_4 + 100));
  iVar7 = (int)(short)*puVar10;
  uVar8 = *puVar10 >> 0x10 & 0x3f;
  uVar2 = FUN_000ec208(param_1,uVar8);
  operandRecord = IRInst__getOperandRecord(inst,0);
  *(undefined4 *)(operandRecord + 0xc) = uVar2;
  uVar2 = 0;
  *(int *)(operandRecord + 8) = iVar7;
  iVar3 = inst;
  ((int (*)())FUN_000f8d50)(param_1,param_9,param_7,puVar10,0,inst,param_10);
  iVar3 = FUN_00113734(*(undefined4 *)(param_1 + 8),inst,param_7,puVar10,uVar2,iVar3,param_10);
  if (iVar3 != 0) {
    operandRecord4 = IRInst__getOperandRecord(inst,0);
    loopIndex = 0;
    iVar3 = 0;
    iVar1 = 0;
    local_48 = *(undefined4 *)(operandRecord4 + 0x10);
    iVar4 = 4;
    do {
      if (*(char *)((int)&local_48 + iVar1) == '\0') {
        loopIndex = loopIndex + 1;
        iVar3 = iVar1;
      }
      iVar1 = iVar1 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    if (1 < loopIndex) {
      local_44 = DAT_001aa9e0;
      *(undefined1 *)((int)&local_44 + iVar3) = 0;
      uVar9 = *(undefined4 *)(iVar3 * 4 + 0x1dc7bc);
      iVar3 = IRInst__create(0x31,*(undefined4 *)(param_1 + 8));
      uVar2 = FUN_000ec208(param_1,uVar8);
      operandRecord3 = IRInst__getOperandRecord(iVar3,0);
      *(undefined4 *)(operandRecord3 + 0xc) = uVar2;
      *(int *)(operandRecord3 + 8) = iVar7;
      *(undefined4 *)(iVar3 + 0x9c) = local_48;
      uVar2 = FUN_000ec208(param_1,uVar8);
      operandRecord3 = IRInst__getOperandRecord(iVar3,1);
      *(undefined4 *)(operandRecord3 + 0xc) = uVar2;
      *(int *)(operandRecord3 + 8) = iVar7;
      operandRecord3 = IRInst__getOperandRecord(iVar3,1);
      *(undefined4 *)(operandRecord3 + 0x10) = uVar9;
      *(uint *)(inst + 0x9c) = local_44;
      goto LAB_000fab1c;
    }
  }
  iVar3 = 0;
LAB_000fab1c:
  if ((uVar11 >> 0x1a & 1) != 0) {
    return iVar3;
  }
  operandRecord4 = IRInst__getOperandRecord(inst,0);
  iVar1 = DAT_001aa9dc;
  if (*(int *)(operandRecord4 + 0x10) == DAT_001aa9dc) {
    return iVar3;
  }
  newInst = IRInst__create(0x31,*(undefined4 *)(param_1 + 8));
  iVar6 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
  *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar6;
  uVar2 = FUN_000ec208(param_1,uVar8);
  operandRecord4 = IRInst__getOperandRecord(newInst,0);
  *(undefined4 *)(operandRecord4 + 0xc) = uVar2;
  *(int *)(operandRecord4 + 8) = iVar7;
  operandRecord2 = IRInst__getOperandRecord(newInst,1);
  *(undefined4 *)(operandRecord2 + 0xc) = 0;
  *(int *)(operandRecord2 + 8) = iVar6;
  operandRecord2 = IRInst__getOperandRecord(inst,0);
  *(undefined4 *)(operandRecord2 + 0xc) = 0;
  *(int *)(operandRecord2 + 8) = iVar6;
  operandRecord2 = IRInst__getOperandRecord(inst,0);
  *(undefined4 *)(newInst + 0x9c) = *(undefined4 *)(operandRecord2 + 0x10);
  *(int *)(inst + 0x9c) = iVar1;
  return newInst;
}

/* FUN_000fadc4 @ 0xfadc4 (240 bytes) */
int FUN_000fadc4(param_1, inst, param_3, param_4, vector, param_6, param_7)
  int param_1;
  undefined4 inst;
  undefined4 param_3;
  undefined4 param_4;
  uint *vector;
  int param_6;
  undefined4 param_7;
{
  int operandRecord2;
  undefined1 uVar1;
  int iVar2;
  undefined4 *allocation;
  int operandRecord;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 arena;
  uint uVar8;
  int iVar9;
  undefined4 local_48 [8];
  
  arena = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
  allocation = (undefined4 *)Arena__alloc(arena,0x15c);
  *allocation = arena;
  puVar6 = allocation + 1;
  IfHeader__ctor_ea6d0(puVar6,inst,param_4,0,*(undefined4 *)(param_1 + 8));
  FUN_000e78c0(puVar6,param_3);
  local_48[0] = DAT_001aa9a8;
  ((int (*)())FUN_000fa958)(param_1,5,1,param_7,inst,1,DAT_001aa9dc,local_48,param_6,1,puVar6);
  operandRecord = IRInst__getOperandRecord(inst,1);
  iVar2 = 0;
  iVar9 = 4;
  (*(unsigned char *)((unsigned char *)&(local_48[0]) + 0)) = (undefined1)((uint)*(undefined4 *)(operandRecord + 0x10) >> 0x18);
  uVar1 = (*(unsigned char *)((unsigned char *)&(local_48[0]) + 0));
  local_48[0] = *(undefined4 *)(operandRecord + 0x10);
  do {
    *(undefined1 *)((int)local_48 + iVar2) = uVar1;
    arena = local_48[0];
    iVar2 = iVar2 + 1;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  operandRecord2 = IRInst__getOperandRecord(inst,1);
  *(undefined4 *)(operandRecord2 + 0x10) = arena;
  FUN_000ed63c(param_1,inst);
  uVar8 = 0;
  if (vector[1] != 0) {
    allocation[0x53] = 0;
    uVar8 = vector[1];
  }
  if (uVar8 < *vector) {
    _memset((void *)(uVar8 * 4 + vector[2]),0,4);
    piVar5 = (int *)(uVar8 * 4 + vector[2]);
    vector[1] = uVar8 + 1;
  }
  else {
    piVar5 = (int *)Vector__elementRefGrow(vector,uVar8);
  }
  *piVar5 = (int)puVar6;
  uVar8 = *(uint *)(param_6 + 4);
  if (uVar8 != 0) {
    piVar5 = (int *)0x0;
    if (uVar8 - 1 < uVar8) {
      piVar5 = (int *)((uVar8 - 1) * 4 + *(int *)(param_6 + 8));
    }
    *(int *)(*piVar5 + 300) = *(int *)(*piVar5 + 300) + 1;
  }
  return puVar6;
}

/* FUN_000fafa4 @ 0xfafa4 (652 bytes) */
int FUN_000fafa4(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
  undefined4 *param_5;
{
  uint uVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  uint *puVar7;
  undefined4 uVar8;
  uint uVar9;
  
  uVar8 = *(undefined4 *)(param_1 + 0x3ac);
  uVar3 = FUN_000ec208(param_1,param_2);
  iVar4 = FUN_00127608(uVar8,uVar3,param_3,0);
  piVar5 = *(int **)(iVar4 + 0x18);
  if (*piVar5 == 0) {
    piVar5 = (int *)Vector__elementRefGrow(piVar5,0);
  }
  else {
    if (piVar5[1] == 0) {
      *(undefined4 *)piVar5[2] = 0;
      piVar5[1] = 1;
    }
    piVar5 = (int *)piVar5[2];
  }
  iVar4 = *(int *)(param_1 + 0x3ac);
  iVar6 = *piVar5;
  puVar7 = *(uint **)(iVar4 + 0x20);
  uVar9 = puVar7[1];
  if (uVar9 < *puVar7) {
    _memset(uVar9 * 4 + puVar7[2],0,4);
    piVar5 = (int *)(uVar9 * 4 + puVar7[2]);
    puVar7[1] = uVar9 + 1;
  }
  else {
    piVar5 = (int *)Vector__elementRefGrow(puVar7,uVar9);
  }
  *piVar5 = iVar6;
  *(int *)(iVar4 + 0x1c) = *(int *)(iVar4 + 0x1c) + 1;
  if (param_2 == 1) {
    if (0 < param_4) {
      uVar9 = 0;
      iVar4 = iVar6;
      do {
        uVar3 = param_5[uVar9];
        *(undefined4 *)(iVar4 + 0x1c) = 2;
        *(undefined4 *)(iVar4 + 0x20) = uVar3;
        uVar1 = uVar9 & 0x3f;
        uVar9 = uVar9 + 1;
        iVar4 = iVar4 + 0x18;
        *(byte *)(iVar6 + 0x15c) = (byte)(1 << uVar1) | *(byte *)(iVar6 + 0x15c);
        param_4 = param_4 + -1;
      } while (param_4 != 0);
    }
  }
  else if (param_2 < 2) {
    if (param_2 == 0) {
      if (param_4 < 1) {
        bVar2 = *(byte *)(iVar6 + 0x15c);
      }
      else {
        uVar9 = 0;
        iVar4 = iVar6;
        do {
          uVar3 = *param_5;
          *(undefined4 *)(iVar4 + 0x1c) = 4;
          *(undefined4 *)(iVar4 + 0x20) = uVar3;
          uVar1 = uVar9 & 0x3f;
          uVar9 = uVar9 + 1;
          iVar4 = iVar4 + 0x18;
          bVar2 = (byte)(1 << uVar1) | *(byte *)(iVar6 + 0x15c);
          *(byte *)(iVar6 + 0x15c) = bVar2;
          param_4 = param_4 + -1;
        } while (param_4 != 0);
      }
      uVar3 = *(undefined4 *)(iVar6 + 0x20);
      *(undefined4 *)(iVar6 + 100) = 4;
      *(byte *)(iVar6 + 0x15c) = bVar2 | 0xe;
      *(undefined4 *)(iVar6 + 0x68) = uVar3;
      *(undefined4 *)(iVar6 + 0x38) = uVar3;
      *(undefined4 *)(iVar6 + 0x50) = uVar3;
      *(undefined4 *)(iVar6 + 0x34) = 4;
      *(undefined4 *)(iVar6 + 0x4c) = 4;
    }
  }
  else if (param_2 == 2) {
    if (0 < param_4) {
      uVar9 = 0;
      iVar4 = iVar6;
      do {
        uVar3 = param_5[uVar9];
        *(undefined4 *)(iVar4 + 0x1c) = 3;
        *(undefined4 *)(iVar4 + 0x20) = uVar3;
        uVar1 = uVar9 & 0x3f;
        uVar9 = uVar9 + 1;
        iVar4 = iVar4 + 0x18;
        *(byte *)(iVar6 + 0x15c) = (byte)(1 << uVar1) | *(byte *)(iVar6 + 0x15c);
        param_4 = param_4 + -1;
      } while (param_4 != 0);
    }
  }
  else if ((param_2 == 0x1d) && (0 < param_4)) {
    uVar9 = 0;
    iVar4 = iVar6;
    do {
      uVar3 = param_5[uVar9];
      *(undefined4 *)(iVar4 + 0x1c) = 3;
      *(undefined4 *)(iVar4 + 0x20) = uVar3;
      uVar1 = uVar9 & 0x3f;
      uVar9 = uVar9 + 1;
      iVar4 = iVar4 + 0x18;
      *(byte *)(iVar6 + 0x15c) = (byte)(1 << uVar1) | *(byte *)(iVar6 + 0x15c);
      param_4 = param_4 + -1;
    } while (param_4 != 0);
  }
  return;
}

/* FUN_000fb230 @ 0xfb230 (420 bytes) */
int FUN_000fb230(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  
  uVar2 = *(uint *)(param_1 + 0x30) & 1 | *(uint *)(param_1 + 0x30) >> 0xe & 1;
  iVar1 = FUN_000d9fc0(*(undefined4 *)(*(int *)(param_1 + 8) + 0x398),uVar2);
  if (0 < iVar1) {
    iVar4 = 0;
    do {
      FUN_000da070(*(undefined4 *)(*(int *)(param_1 + 8) + 0x398),uVar2,iVar4,1,&local_48);
      FUN_000e4724(param_2,iVar4,(uint)(local_48 != 0));
      iVar3 = iVar4 + 1;
      ((int (*)())FUN_000fafa4)(param_1,0,iVar4,1,&local_48);
      iVar4 = iVar3;
    } while (iVar1 != iVar3);
  }
  iVar1 = FUN_000d9fa0(*(undefined4 *)(*(int *)(param_1 + 8) + 0x398),uVar2);
  if (0 < iVar1) {
    iVar4 = 0;
    do {
      FUN_000da028(*(undefined4 *)(*(int *)(param_1 + 8) + 0x398),uVar2,iVar4,4,&local_48);
      FUN_000e4450(param_2,iVar4,local_48,local_44,local_40,local_3c);
      iVar3 = iVar4 + 1;
      ((int (*)())FUN_000fafa4)(param_1,2,iVar4,4,&local_48);
      iVar4 = iVar3;
    } while (iVar1 != iVar3);
  }
  iVar1 = FUN_000d9f80(*(undefined4 *)(*(int *)(param_1 + 8) + 0x398),uVar2);
  if (0 < iVar1) {
    iVar4 = 0;
    do {
      FUN_000d9fe0(*(undefined4 *)(*(int *)(param_1 + 8) + 0x398),uVar2,iVar4,4,&local_38);
      ((void (*)())FUN_000e4780)(param_2,iVar4,(double)local_38,(double)local_34,(double)local_30,(double)local_2c
                  );
      iVar3 = iVar4 + 1;
      ((int (*)())FUN_000fafa4)(param_1,1,iVar4,4,&local_38);
      iVar4 = iVar3;
    } while (iVar1 != iVar3);
  }
  return;
}

/* FUN_000fb3d4 @ 0xfb3d4 (2560 bytes) */
int FUN_000fb3d4(param_1, list, param_3, descriptor, param_5, param_6, param_7)
  int param_1;
  undefined4 list;
  dword *param_3;
  dword *descriptor;
  dword *param_5;
  dword *param_6;
  int param_7;
{
  undefined4 psnPackedLaneSourceResult;
  undefined4 psnPackedLaneSourceResult2;
  void *newInst;
  int *newInst3;
  dword *newInst2;
  dword *newInst4;
  int operandRecord3;
  int operandRecord2;
  undefined4 arenaAt374;
  ushort uVar1;
  bool bVar2;
  bool bVar3;
  dword dVar4;
  undefined *puVar5;
  int iVar6;
  int *piVar7;
  undefined4 arena;
  undefined4 *allocation;
  void *inst;
  int operandRecord;
  undefined4 uVar12;
  undefined4 psnPackedLaneSourceResult3;
  undefined4 uVar14;
  void *pvVar15;
  void *inst2;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  undefined4 extraout_r4_02;
  undefined4 extraout_r4_03;
  undefined4 extraout_r4_04;
  undefined4 extraout_r4_05;
  undefined4 extraout_r4_06;
  undefined4 extraout_r4_07;
  undefined4 extraout_r4_08;
  undefined4 extraout_r4_09;
  undefined4 extraout_r4_10;
  undefined4 extraout_r4_11;
  undefined4 extraout_r4_12;
  undefined4 extraout_r4_13;
  undefined4 extraout_r4_14;
  undefined4 extraout_r4_15;
  undefined4 extraout_r4_16;
  undefined4 extraout_r4_17;
  dword *pdVar17;
  dword *pdVar18;
  uint uVar19;
  int iVar20;
  undefined1 *puVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  dword *pdVar25;
  dword *pdVar26;
  dword *pdVar27;
  dword *pdVar28;
  dword *pdVar29;
  dword *pdVar30;
  dword *pdVar31;
  dword *pdVar32;
  undefined4 *puVar33;
  uint uVar34;
  undefined4 uVar35;
  code *pcVar36;
  uint *puVar37;
  int iVar38;
  double fparam_1;
  double fparam_2;
  double fparam_3;
  double fparam_4;
  undefined8 uVar39;
  undefined4 local_98;
  dword local_94 [3];
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  
  uVar22 = *descriptor;
  uVar23 = uVar22 >> 0x16 & 1;
  iVar20 = *(int *)(param_1 + 8);
  if ((((uVar22 & 0x3f0000) == 0x100000) && (iVar20 != 0)) &&
     ((*(uint *)(*(int *)(iVar20 + 0x30c) + 8) & 0x80) != 0)) {
    pdVar25 = (dword *)((int)((unsigned char *)0xc) + 3);
  }
  else {
    pdVar25 = (dword *)(int)(short)*descriptor;
  }
  uVar24 = uVar22 >> 0x10 & 0x3f;
  arena = list;
  pdVar17 = param_3;
  pdVar18 = descriptor;
  pdVar32 = param_6;
  pdVar31 = pdVar25;
  if ((uVar22 & 0x1800000) == 0x800000) {
    iVar6 = 8;
    if (uVar23 == 0) {
      iVar6 = 4;
    }
    uVar22 = *(uint *)(iVar6 + (int)descriptor);
    uVar1 = *(ushort *)((int)descriptor + iVar6 + 2);
    if ((uVar22 & 0x10000) == 0) {
      pdVar31 = (dword *)(*(int *)(iVar20 + 0x3b4) + 1);
      *(dword **)(iVar20 + 0x3b4) = pdVar31;
      iVar20 = FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),0x26,pdVar31,0);
      *(dword **)(iVar20 + 0x30) = pdVar25;
      arena = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
      allocation = (undefined4 *)Arena__alloc(arena,0x168);
      *allocation = arena;
      puVar33 = allocation + 1;
      IRProjection__ctor_109e28(puVar33,0x84,*(undefined4 *)(param_1 + 8));
      IRInst__setOperandRef(puVar33,0,iVar20);
      pdVar18 = (dword *)0x0;
      uVar24 = 0x22;
      pdVar25 = (dword *)FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),0x25,(uint)uVar1,0);
      pdVar17 = pdVar25;
      IRInst__setOperandRef(puVar33,1,pdVar25);
      arena = *(undefined4 *)(PTR_DAT_001e8b8c + (uVar22 >> 0x11 & 7) * 4);
      operandRecord2 = IRInst__getOperandRecord(puVar33,1);
      *(undefined4 *)(operandRecord2 + 0x10) = arena;
      allocation[0x4c] = pdVar25[0xc];
      DList__pushBack(list,puVar33);
      arena = extraout_r4_01;
    }
    else {
      piVar7 = (int *)0x0;
      uVar22 = param_5[1] - 1;
      if (uVar22 < param_5[1]) {
        piVar7 = (int *)(uVar22 * 4 + param_5[2]);
      }
      iVar20 = *piVar7;
      *(undefined4 *)(iVar20 + 0x140) = 1;
      arena = FUN_000e7d5c(iVar20);
      arena = FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),0x27,arena,0);
      if (uVar24 == 1) {
        pdVar18 = (dword *)0x0;
        pdVar31 = (dword *)(*(int *)(*(int *)(param_1 + 8) + 0x3b8) + 1);
        *(dword **)(*(int *)(param_1 + 8) + 0x3b8) = pdVar31;
        iVar6 = FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),0x28,pdVar31,0);
        *(dword **)(iVar6 + 0x30) = pdVar25;
        arenaAt374 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
        allocation = (undefined4 *)Arena__alloc(arenaAt374,0x168);
        *allocation = arenaAt374;
        pdVar17 = allocation + 1;
        IRInst__ctor_10502c(pdVar17,0x82,*(undefined4 *)(param_1 + 8));
        IRInst__setOperandRef(pdVar17,0,iVar6);
        IRInst__setOperandRef(pdVar17,1,arena);
        uVar24 = 0x23;
        Block__appendInst(iVar20,pdVar17);
        FUN_0012306c(iVar6,pdVar17);
        VReg__addUse(arena,1,pdVar17);
        arena = extraout_r4;
      }
      else {
        if ((*(uint *)(param_1 + 0x30) & 1) == 0) {
          if ((*(uint *)(param_1 + 0x30) & 0x2000) != 0) {
            if (*(int *)(param_1 + 0x3e4) == 0) {
              *(undefined4 *)(param_1 + 0x3e4) = 1;
              uVar35 = FUN_000ec208(param_1,uVar24);
              *(undefined4 *)(param_1 + 0x3f4) = uVar35;
            }
            else {
              FUN_000ec208(param_1,uVar24);
            }
          }
        }
        else {
          *(undefined4 *)(param_1 + 0x3d4) = 1;
        }
        pdVar31 = (dword *)(*(int *)(*(int *)(param_1 + 8) + 0x3bc) + 1);
        *(dword **)(*(int *)(param_1 + 8) + 0x3bc) = pdVar31;
        uVar12 = *(undefined4 *)(param_1 + 0x3ac);
        uVar35 = FUN_000ec208(param_1,0x24);
        pdVar18 = (dword *)0x0;
        iVar6 = FUN_00127608(uVar12,uVar35,pdVar31,0);
        *(dword **)(iVar6 + 0x30) = pdVar25;
        arenaAt374 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
        allocation = (undefined4 *)Arena__alloc(arenaAt374,0x168);
        *allocation = arenaAt374;
        pdVar17 = allocation + 1;
        IRInst__ctor_10502c(pdVar17,0x82,*(undefined4 *)(param_1 + 8));
        IRInst__setOperandRef(pdVar17,0,iVar6);
        IRInst__setOperandRef(pdVar17,1,arena);
        uVar24 = 0x24;
        Block__appendInst(iVar20,pdVar17);
        FUN_0012306c(iVar6,pdVar17);
        VReg__addUse(arena,1,pdVar17);
        arena = extraout_r4_00;
      }
    }
    uVar22 = *descriptor & 0xfe7fffff;
    *descriptor = uVar22;
  }
  if (((uVar22 & 0x3f0000) == 0x1c0000) &&
     ((*(uint *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 8) & 8) == 0)) {
    *descriptor = uVar22 & 0xffc0ffff | 0x10000;
    pdVar25 = descriptor;
    if ((uVar22 & 0x400000) != 0) {
      pdVar25 = descriptor + 1;
    }
    bVar3 = false;
    *(short *)((int)descriptor + 2) = (short)pdVar25[1];
    uVar22 = *descriptor & 0xfbffffff;
    *descriptor = uVar22;
  }
  else {
    bVar3 = true;
  }
  if ((uVar24 == 0x20) && (bVar2 = true, (uVar22 & 0x1800000) == 0x1000000)) {
LAB_000fb800:
    pdVar25 = (dword *)(*(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1);
    *(dword **)(*(int *)(param_1 + 8) + 0x3ac) = pdVar25;
    uVar22 = *descriptor;
    uVar34 = uVar22 >> 0x10 & 0x3f;
    if (!bVar2) {
      arena = 0xfe;
      if (uVar34 != 0x1c) {
        arena = 0xfb;
      }
    }
    else {
      arena = 0x10b;
    }
    iVar20 = 1;
    pdVar18 = pdVar31;
    if ((int)uVar22 < 0) {
      iVar20 = 2;
      pdVar18 = (dword *)((uint)pdVar31 | descriptor[1] << 0x10);
    }
    if ((uVar22 & 0x400000) != 0) {
      iVar20 = iVar20 + 1;
    }
    if ((uVar22 & 0x1800000) == 0x1000000) {
      pdVar29 = descriptor + iVar20;
      if (!bVar2) {
        arenaAt374 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
        allocation = (undefined4 *)Arena__alloc(arenaAt374,0x168);
        *allocation = arenaAt374;
        allocation = allocation + 1;
        FUN_00107980(allocation,arena,*(undefined4 *)(param_1 + 8));
        arena = FUN_000ec208(param_1,uVar34);
        pdVar17 = (dword *)((int)((unsigned char *)0x0) + 2);
        operandRecord3 = IRInst__getOperandRecord(allocation,1);
        *(undefined4 *)(operandRecord3 + 0xc) = arena;
        *(dword **)(operandRecord3 + 8) = pdVar18;
      }
      else {
        pdVar17 = (dword *)((int)((unsigned char *)0x0) + 1);
        allocation = IRInst__create(arena,*(undefined4 *)(param_1 + 8));
        allocation[0x27] = 0;
        allocation[0x50] = 0x10203;
        allocation[0x21] = 2;
        arena = FUN_000ec208(param_1,uVar34);
        operandRecord3 = IRInst__getOperandRecord(allocation,2);
        *(undefined4 *)(operandRecord3 + 0xc) = arena;
        *(undefined4 *)(operandRecord3 + 8) = 0xffffffff;
      }
      arena = FUN_000ec208(param_1,4);
      operandRecord3 = IRInst__getOperandRecord(allocation,0);
      *(undefined4 *)(operandRecord3 + 0xc) = arena;
      *(dword **)(operandRecord3 + 8) = pdVar25;
      if ((*descriptor & 0x4000000) == 0) {
        dVar4 = *pdVar29;
        arena = FUN_000ec208(param_1,*pdVar29 >> 0x10 & 0x3f);
        operandRecord2 = IRInst__getOperandRecord(allocation,pdVar17);
        *(undefined4 *)(operandRecord2 + 0xc) = arena;
        *(uint *)(operandRecord2 + 8) = (uint)GH_F2U((float)((ushort)dVar4));
      }
      else {
        pdVar32 = (dword *)descriptor[iVar20 + 2];
        inst = IRInst__create(0xc6,*(undefined4 *)(param_1 + 8));
        arena = FUN_000ec208(param_1,4);
        operandRecord2 = IRInst__getOperandRecord(inst,0);
        *(undefined4 *)(operandRecord2 + 0xc) = arena;
        *(dword **)(operandRecord2 + 8) = pdVar25;
        dVar4 = *pdVar29;
        arena = FUN_000ec208(param_1,*pdVar29 >> 0x10 & 0x3f);
        operandRecord2 = IRInst__getOperandRecord(inst,1);
        *(undefined4 *)(operandRecord2 + 0xc) = arena;
        *(uint *)(operandRecord2 + 8) = (uint)GH_F2U((float)((ushort)dVar4));
        ((int (*)())FUN_000f7870)(inst,param_1,2,pdVar32,pdVar32,pdVar32,pdVar32);
        DList__pushBack(list,inst);
        arena = FUN_000ec208(param_1,4);
        operandRecord2 = IRInst__getOperandRecord(allocation,pdVar17);
        *(undefined4 *)(operandRecord2 + 0xc) = arena;
        *(dword **)(operandRecord2 + 8) = pdVar25;
      }
      local_98 = 0x10203;
      ((int (*)())FUN_000f8aa0)(param_1,&local_98,pdVar29,pdVar17,allocation);
    }
    else if ((uVar22 & 0x1800000) == 0) {
      pdVar32 = (dword *)descriptor[iVar20];
      arenaAt374 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
      allocation = (undefined4 *)Arena__alloc(arenaAt374,0x168);
      *allocation = arenaAt374;
      allocation = allocation + 1;
      FUN_00107980(allocation,arena,*(undefined4 *)(param_1 + 8));
      arena = FUN_000ec208(param_1,4);
      operandRecord2 = IRInst__getOperandRecord(allocation,0);
      *(undefined4 *)(operandRecord2 + 0xc) = arena;
      *(dword **)(operandRecord2 + 8) = pdVar25;
      arena = FUN_000ec208(param_1,uVar34);
      operandRecord2 = IRInst__getOperandRecord(allocation,1);
      *(undefined4 *)(operandRecord2 + 0xc) = arena;
      *(dword **)(operandRecord2 + 8) = pdVar18;
      ((int (*)())FUN_000f7870)(allocation,param_1,2,pdVar32,pdVar32,pdVar32,pdVar32);
      pdVar17 = (dword *)((int)((unsigned char *)0x0) + 1);
    }
    else {
      allocation = (undefined4 *)0x0;
      pdVar17 = (dword *)((int)((unsigned char *)0x0) + 1);
    }
    operandRecord2 = IRInst__getOperandRecord(allocation,pdVar17);
    local_94[0] = *(dword *)(operandRecord2 + 0x10);
    pdVar18 = local_94;
    param_5 = (dword *)0x0;
    piVar7 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
    iVar20 = (**(code **)(*piVar7 + 0x104))(piVar7,allocation,pdVar17,pdVar18,0);
    if (iVar20 == 0) {
      iVar6 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar6;
      inst = IRInst__create(0x31,*(undefined4 *)(param_1 + 8));
      uVar35 = allocation[0x32];
      arena = allocation[0x31];
      operandRecord2 = IRInst__getOperandRecord(inst,1);
      *(undefined4 *)(operandRecord2 + 0xc) = uVar35;
      *(undefined4 *)(operandRecord2 + 8) = arena;
      arena = FUN_000ec208(param_1,4);
      operandRecord2 = IRInst__getOperandRecord(inst,0);
      *(undefined4 *)(operandRecord2 + 0xc) = arena;
      *(int *)(operandRecord2 + 8) = iVar6;
      operandRecord2 = IRInst__getOperandRecord(allocation,2);
      arena = *(undefined4 *)(operandRecord2 + 0x10);
      operandRecord2 = IRInst__getOperandRecord(inst,1);
      *(undefined4 *)(operandRecord2 + 0x10) = arena;
      DList__pushBack(list,inst);
      arena = FUN_000ec208(param_1,4);
      operandRecord2 = IRInst__getOperandRecord(allocation,2);
      *(undefined4 *)(operandRecord2 + 0xc) = arena;
      *(int *)(operandRecord2 + 8) = iVar6;
      operandRecord2 = IRInst__getOperandRecord(allocation,2);
      *(undefined4 *)(operandRecord2 + 0x10) = 0;
    }
    DList__pushBack(list,allocation);
    bVar3 = false;
    *descriptor = *descriptor & 0xffc0ffff | 0x40000;
    *(short *)((int)descriptor + 2) = (short)pdVar25;
    arena = extraout_r4_02;
  }
  else {
    if (((undefined4 *)(uVar22 & 0x3f0000) == (undefined4 *)0x1c0000) ||
       ((undefined4 *)(uVar22 & 0x3f0000) == 0x001b0000)) {
      bVar2 = false;
      goto LAB_000fb800;
    }
    pdVar25 = (dword *)0x0;
    if ((uVar22 & 0x2000000) != 0) {
      pdVar25 = (dword *)(*(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1);
      *(dword **)(*(int *)(param_1 + 8) + 0x3ac) = pdVar25;
      uVar22 = *descriptor;
      if ((uVar22 & 0x400000) == 0) {
        pdVar32 = (dword *)((int)((unsigned char *)0x0) + 1);
        pdVar29 = (dword *)((int)((unsigned char *)0x0) + 1);
        param_5 = (dword *)((int)((unsigned char *)0x0) + 2);
      }
      else {
        pdVar32 = (dword *)((int)((unsigned char *)0x0) + 2);
        pdVar29 = (dword *)((int)((unsigned char *)0x0) + 2);
        param_5 = (dword *)((int)((unsigned char *)0x0) + 3);
      }
      if ((uVar22 & 0x1800000) == 0x1000000) {
        pdVar17 = descriptor + (int)pdVar29;
        pdVar18 = descriptor + (int)param_5;
        pdVar29 = (dword *)((int)pdVar32 + 2);
        if ((uVar22 & 0x4000000) == 0) {
          param_5 = (dword *)((int)pdVar32 + 3);
          pdVar26 = pdVar29;
        }
        else {
          pdVar29 = (dword *)((int)pdVar32 + 3);
          param_5 = pdVar32 + 1;
          pdVar26 = pdVar29;
        }
      }
      else {
        pdVar17 = (dword *)0x0;
        pdVar18 = (dword *)0x0;
        pdVar26 = pdVar32;
      }
      if ((descriptor[(int)pdVar29] & 0x1800000) == 0x1000000) {
        pdVar30 = descriptor + (int)param_5;
        pdVar28 = (dword *)0x0;
        pdVar27 = descriptor + (int)((int)pdVar26 + 2);
        if ((descriptor[(int)pdVar29] & 0x4000000) != 0) {
          pdVar28 = descriptor + (int)((int)pdVar26 + 3);
        }
      }
      else {
        pdVar30 = (dword *)0x0;
        pdVar27 = (dword *)0x0;
        pdVar28 = (dword *)0x0;
      }
      if (pdVar17 == (dword *)0x0) {
        if (pdVar30 != (dword *)0x0) {
          if ((pdVar18 != (dword *)0x0) || (pdVar27 == (dword *)0x0)) goto LAB_000fc43c;
          newInst4 = IRInst__create(0xe6,*(undefined4 *)(param_1 + 8));
          dVar4 = *descriptor;
          piVar7 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
          arena = (**(code **)(*piVar7 + 0x9c))(piVar7,(short)dVar4);
          piVar7 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
          (**(code **)(*piVar7 + 0xa0))(&local_84,piVar7,(short)dVar4);
          uVar35 = FUN_000ec208(param_1,4);
          operandRecord2 = IRInst__getOperandRecord(newInst4,0);
          pdVar32 = ((unsigned char *)0x4);
          *(undefined4 *)(operandRecord2 + 0xc) = uVar35;
          *(dword **)(operandRecord2 + 8) = pdVar25;
          ((int (*)())FUN_000f7870)(newInst4,param_1,1,4,4,4,4);
          dVar4 = *pdVar30;
          uVar35 = FUN_000ec208(param_1,*pdVar30 >> 0x10 & 0x3f);
          operandRecord2 = IRInst__getOperandRecord(newInst4,2);
          *(undefined4 *)(operandRecord2 + 0xc) = uVar35;
          *(uint *)(operandRecord2 + 8) = (uint)GH_F2U((float)((ushort)dVar4));
          pdVar18 = (dword *)((int)((unsigned char *)0x0) + 2);
          local_98 = 0x10203;
          param_5 = newInst4;
          ((int (*)())FUN_000f8aa0)(param_1,&local_98,pdVar30,2,newInst4);
          DList__pushBack(list,newInst4);
          if ((pdVar28 != (dword *)0x0) && (*pdVar28 != 0)) {
            inst = IRInst__create(0xc6,*(undefined4 *)(param_1 + 8));
            uVar35 = FUN_000ec208(param_1,4);
            operandRecord2 = IRInst__getOperandRecord(inst,0);
            *(undefined4 *)(operandRecord2 + 0xc) = uVar35;
            *(dword **)(operandRecord2 + 8) = pdVar25;
            uVar35 = FUN_000ec208(param_1,4);
            operandRecord2 = IRInst__getOperandRecord(inst,1);
            *(undefined4 *)(operandRecord2 + 0xc) = uVar35;
            pdVar30 = (dword *)((int)((unsigned char *)0x0) + 2);
            *(dword **)(operandRecord2 + 8) = pdVar25;
            pdVar18 = (dword *)(*pdVar28 << 2);
            param_5 = pdVar18;
            pdVar32 = pdVar18;
            ((int (*)())FUN_000f7870)(inst,param_1,2,pdVar18,pdVar18,pdVar18,pdVar18);
            operandRecord2 = IRInst__getOperandRecord(inst,2);
            *(undefined4 *)(operandRecord2 + 0x10) = local_84;
            DList__pushBack(list,inst);
          }
          inst = IRInst__create(0xc6,*(undefined4 *)(param_1 + 8));
          uVar35 = FUN_000ec208(param_1,4);
          operandRecord2 = IRInst__getOperandRecord(inst,0);
          *(undefined4 *)(operandRecord2 + 0xc) = uVar35;
          *(dword **)(operandRecord2 + 8) = pdVar25;
          uVar35 = FUN_000ec208(param_1,4);
          operandRecord2 = IRInst__getOperandRecord(inst,1);
          *(undefined4 *)(operandRecord2 + 0xc) = uVar35;
          *(dword **)(operandRecord2 + 8) = pdVar25;
          operandRecord2 = IRInst__getOperandRecord(inst,2);
          *(undefined4 *)(operandRecord2 + 0xc) = 0x1f;
          *(undefined4 *)(operandRecord2 + 8) = arena;
          operandRecord2 = IRInst__getOperandRecord(inst,2);
          *(undefined4 *)(operandRecord2 + 0x10) = local_84;
          DList__pushBack(list,inst);
          inst = IRInst__create(0x68,*(undefined4 *)(param_1 + 8));
          arena = FUN_000ec208(param_1,4);
          operandRecord2 = IRInst__getOperandRecord(inst,0);
          *(undefined4 *)(operandRecord2 + 0xc) = arena;
          *(dword **)(operandRecord2 + 8) = pdVar25;
          *(undefined4 *)((int)inst + 0x130) = 0;
          pdVar17 = pdVar30;
LAB_000fc3f4:
          *(undefined4 *)((int)inst + 0x140) = 0x10203;
          arena = FUN_000ec208(param_1,4);
          operandRecord2 = IRInst__getOperandRecord(inst,1);
          *(undefined4 *)(operandRecord2 + 0xc) = arena;
          *(dword **)(operandRecord2 + 8) = pdVar25;
          operandRecord2 = IRInst__getOperandRecord(inst,1);
          pvVar15 = (void *)0x0;
          *(undefined4 *)(operandRecord2 + 0x10) = 0;
          goto LAB_000fc74c;
        }
        uVar22 = (uint)*(ushort *)((int)descriptor + (int)pdVar29 * 4 + 2);
        pdVar29 = (dword *)(uint)(ushort)*descriptor;
        if ((*(uint *)(param_1 + 0x30) & 0x40000) == 0) {
          pvVar15 = (void *)0x0;
          inst = IRInst__create(0x68,*(undefined4 *)(param_1 + 8));
          arena = FUN_000ec208(param_1,4);
          operandRecord2 = IRInst__getOperandRecord(inst,0);
          *(undefined4 *)(operandRecord2 + 0xc) = arena;
          *(dword **)(operandRecord2 + 8) = pdVar25;
          *(undefined4 *)((int)inst + 0x140) = 0x10203;
          *(uint *)((int)inst + 0x130) = uVar22;
          piVar7 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
          arena = (**(code **)(*piVar7 + 0x9c))(piVar7,pdVar29);
          pdVar18 = *(dword **)(param_1 + 8);
          (**(code **)(*(*(int * *)(pdVar18 + (0xc3))) + 0xa0))(&local_88);
          operandRecord2 = IRInst__getOperandRecord(inst,1);
          *(undefined4 *)(operandRecord2 + 8) = arena;
          *(undefined4 *)(operandRecord2 + 0xc) = 0x1f;
          operandRecord2 = IRInst__getOperandRecord(inst,1);
          *(undefined4 *)(operandRecord2 + 0x10) = local_88;
          pdVar17 = pdVar29;
          if (uVar22 == *param_6) {
            pdVar17 = *(dword **)(param_1 + 8);
            uVar35 = (**(code **)(*(*(int * *)(pdVar17 + (0xc3))) + 0xa8))((*(int * *)(pdVar17 + (0xc3))),&local_98);
            pvVar15 = IRInst__create(0x31,*(undefined4 *)(param_1 + 8));
            arena = FUN_000ec208(param_1,4);
            operandRecord2 = IRInst__getOperandRecord(pvVar15,0);
            *(undefined4 *)(operandRecord2 + 0xc) = arena;
            *(dword **)(operandRecord2 + 8) = pdVar25;
            *(dword *)((int)pvVar15 + 0x9c) = param_6[1];
            operandRecord2 = IRInst__getOperandRecord(pvVar15,1);
            arena = local_98;
            *(undefined4 *)(operandRecord2 + 0xc) = 0x1f;
            *(undefined4 *)(operandRecord2 + 8) = uVar35;
            operandRecord2 = IRInst__getOperandRecord(pvVar15,1);
            *(undefined4 *)(operandRecord2 + 0x10) = arena;
          }
          goto LAB_000fc74c;
        }
        iVar20 = (int)pdVar29 * 4;
        puVar37 = *(uint **)(iVar20 + param_7);
        if (puVar37 == (uint *)0x0) {
          arena = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
          allocation = (undefined4 *)Arena__alloc(arena,0x14);
          puVar37 = allocation + 1;
          *allocation = arena;
          allocation[1] = 2;
          allocation[2] = 0;
          allocation[4] = arena;
          arena = Arena__alloc(arena,8);
          allocation[3] = arena;
          *(uint **)(iVar20 + param_7) = puVar37;
          arena = extraout_r4_03;
        }
        if (uVar22 < *puVar37) {
          uVar34 = puVar37[1];
          if (uVar34 <= uVar22) {
            pdVar17 = (dword *)((uVar22 - uVar34) * 4 + 4);
            _memset(uVar34 * 4 + puVar37[2],0,pdVar17);
            puVar37[1] = uVar22 + 1;
            arena = extraout_r4_04;
          }
          uVar39 = CONCAT44(uVar22 * 4 + puVar37[2],arena);
        }
        else {
          uVar39 = Vector__elementRefGrow(puVar37,uVar22);
        }
        arena = (undefined4)uVar39;
        if (*(int *)((ulonglong)uVar39 >> 0x20) == 0) {
          iVar6 = FUN_00109810(0xa4,*(undefined4 *)(param_1 + 8));
          *(uint *)(iVar6 + 0x14) = *(uint *)(iVar6 + 0x14) & 0xffff7fff;
          iVar38 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
          *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar38;
          operandRecord = IRInst__getOperandRecord(iVar6,0);
          *(int *)(operandRecord + 8) = iVar38;
          *(undefined4 *)(operandRecord + 0xc) = 0;
          *(dword **)(iVar6 + 0x130) = pdVar29;
          *(uint *)(iVar6 + 300) = uVar22;
          pdVar17 = *(dword **)(param_1 + 0x3a0);
          ((int (*)())FUN_000f92fc)(param_1,iVar6,pdVar17);
          puVar37 = *(uint **)(iVar20 + param_7);
          if (uVar22 < *puVar37) {
            uVar34 = puVar37[1];
            arena = extraout_r4_05;
            if (uVar34 <= uVar22) {
              pdVar17 = (dword *)((uVar22 - uVar34) * 4 + 4);
              _memset(uVar34 * 4 + puVar37[2],0,pdVar17);
              puVar37[1] = uVar22 + 1;
              arena = extraout_r4_06;
            }
            uVar39 = CONCAT44(uVar22 * 4 + puVar37[2],arena);
          }
          else {
            uVar39 = Vector__elementRefGrow(puVar37,uVar22);
          }
          arena = (undefined4)uVar39;
          *(int *)((ulonglong)uVar39 >> 0x20) = iVar6;
        }
        puVar37 = *(uint **)(iVar20 + param_7);
        if (uVar22 < *puVar37) {
          uVar34 = puVar37[1];
          if (uVar34 <= uVar22) {
            pdVar17 = (dword *)((uVar22 - uVar34) * 4 + 4);
            _memset(uVar34 * 4 + puVar37[2],0,pdVar17);
            puVar37[1] = uVar22 + 1;
            arena = extraout_r4_07;
          }
          uVar39 = CONCAT44(uVar22 * 4 + puVar37[2],arena);
        }
        else {
          uVar39 = Vector__elementRefGrow(puVar37,uVar22);
        }
        arena = (undefined4)uVar39;
        pdVar25 = *(dword **)(*(int *)((ulonglong)uVar39 >> 0x20) + 0x94);
      }
      else {
        if (((pdVar18 != (dword *)0x0) && (pdVar30 == (dword *)0x0)) && (pdVar27 == (dword *)0x0)) {
          pdVar32 = ((unsigned char *)0x4);
          param_5 = pdVar25;
          ((int (*)())FUN_000f94dc)(param_1,list,pdVar17,pdVar18,pdVar25,4,*(undefined4 *)(param_1 + 0x400));
          uVar1 = *(ushort *)((int)descriptor + (int)pdVar29 * 4 + 2);
          inst = IRInst__create(0x68,*(undefined4 *)(param_1 + 8));
          arena = FUN_000ec208(param_1,4);
          operandRecord2 = IRInst__getOperandRecord(inst,0);
          *(undefined4 *)(operandRecord2 + 0xc) = arena;
          *(dword **)(operandRecord2 + 8) = pdVar25;
          *(uint *)((int)inst + 0x130) = (uint)uVar1;
          goto LAB_000fc3f4;
        }
LAB_000fc43c:
        ((int (*)())FUN_000f94dc)(param_1,list,pdVar17,pdVar18,pdVar25,4,*(undefined4 *)(param_1 + 0x400));
        uVar34 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) - 1;
        *(uint *)(*(int *)(param_1 + 8) + 0x3ac) = uVar34;
        uVar22 = (uint)(ushort)*pdVar30;
        if (pdVar28 != (dword *)0x0) {
          inst = IRInst__create(0xc6,*(undefined4 *)(param_1 + 8));
          arena = FUN_000ec208(param_1,4);
          operandRecord2 = IRInst__getOperandRecord(inst,0);
          *(undefined4 *)(operandRecord2 + 0xc) = arena;
          *(undefined4 *)((int)inst + 0x9c) = 0x10101;
          *(uint *)(operandRecord2 + 8) = uVar34;
          uVar19 = *pdVar28;
          ((int (*)())FUN_000f7870)(inst,param_1,1,uVar19,uVar19,uVar19,uVar19);
          arena = FUN_000ec208(param_1,*pdVar30 >> 0x10 & 0x3f);
          operandRecord2 = IRInst__getOperandRecord(inst,2);
          *(undefined4 *)(operandRecord2 + 0xc) = arena;
          *(uint *)(operandRecord2 + 8) = uVar22;
          local_94[0] = 0x10203;
          ((int (*)())FUN_000f8aa0)(param_1,local_94,pdVar30,2,inst);
          DList__pushBack(list,inst);
          *pdVar30 = *pdVar30 & 0xffc0ffff | 0x40000;
          uVar22 = uVar34;
        }
        newInst2 = IRInst__create(0xe6,*(undefined4 *)(param_1 + 8));
        arena = FUN_000ec208(param_1,4);
        operandRecord2 = IRInst__getOperandRecord(newInst2,0);
        *(undefined4 *)(operandRecord2 + 0xc) = arena;
        pdVar17 = (dword *)((int)((unsigned char *)0x0) + 1);
        newInst2[0x27] = 0x10101;
        pdVar18 = ((unsigned char *)0x4);
        param_5 = ((unsigned char *)0x4);
        pdVar32 = ((unsigned char *)0x4);
        *(uint *)(operandRecord2 + 8) = uVar34;
        ((int (*)())FUN_000f7870)(newInst2,param_1,1,4,4,4,4);
        arena = FUN_000ec208(param_1,*pdVar30 >> 0x10 & 0x3f);
        operandRecord2 = IRInst__getOperandRecord(newInst2,2);
        *(undefined4 *)(operandRecord2 + 0xc) = arena;
        *(uint *)(operandRecord2 + 8) = uVar22;
        local_98 = 0x10203;
        if (pdVar28 == (dword *)0x0) {
          pdVar18 = (dword *)((int)((unsigned char *)0x0) + 2);
          param_5 = newInst2;
          ((int (*)())FUN_000f8aa0)(param_1,&local_98,pdVar30,2,newInst2);
          pdVar17 = pdVar30;
        }
        else {
          operandRecord2 = IRInst__getOperandRecord(newInst2,2);
          *(undefined4 *)(operandRecord2 + 0x10) = 0;
        }
        DList__pushBack(list,newInst2);
        inst = IRInst__create(0xc6,*(undefined4 *)(param_1 + 8));
        *(undefined4 *)((int)inst + 0x9c) = 0x10101;
        arena = FUN_000ec208(param_1,4);
        operandRecord2 = IRInst__getOperandRecord(inst,0);
        *(undefined4 *)(operandRecord2 + 0xc) = arena;
        *(dword **)(operandRecord2 + 8) = pdVar25;
        arena = FUN_000ec208(param_1,4);
        operandRecord2 = IRInst__getOperandRecord(inst,1);
        *(undefined4 *)(operandRecord2 + 0xc) = arena;
        *(dword **)(operandRecord2 + 8) = pdVar25;
        arena = FUN_000ec208(param_1,4);
        operandRecord2 = IRInst__getOperandRecord(inst,2);
        *(undefined4 *)(operandRecord2 + 0xc) = arena;
        *(uint *)(operandRecord2 + 8) = uVar34;
        operandRecord2 = IRInst__getOperandRecord(inst,1);
        pvVar15 = (void *)0x0;
        *(undefined4 *)(operandRecord2 + 0x10) = 0;
        operandRecord2 = IRInst__getOperandRecord(inst,2);
        *(undefined4 *)(operandRecord2 + 0x10) = 0;
        DList__pushBack(list,inst);
        inst = IRInst__create(0x68,*(undefined4 *)(param_1 + 8));
        arena = FUN_000ec208(param_1,4);
        operandRecord2 = IRInst__getOperandRecord(inst,0);
        *(undefined4 *)(operandRecord2 + 0xc) = arena;
        *(dword **)(operandRecord2 + 8) = pdVar25;
        *(undefined4 *)((int)inst + 0x130) = 0;
        *(undefined4 *)((int)inst + 0x140) = 0x10203;
        arena = FUN_000ec208(param_1,4);
        operandRecord2 = IRInst__getOperandRecord(inst,1);
        *(undefined4 *)(operandRecord2 + 0xc) = arena;
        *(dword **)(operandRecord2 + 8) = pdVar25;
        operandRecord2 = IRInst__getOperandRecord(inst,1);
        *(undefined4 *)(operandRecord2 + 0x10) = 0;
LAB_000fc74c:
        DList__pushBack(list,inst);
        arena = extraout_r4_08;
        if (pvVar15 != (void *)0x0) {
          DList__pushBack(list,pvVar15);
          arena = extraout_r4_09;
        }
      }
      bVar3 = false;
      *descriptor = *descriptor & 0xffc0ffff | 0x40000;
      *(short *)((int)descriptor + 2) = (short)pdVar25;
    }
  }
  if (uVar23 == 0) goto code_r0x000fd490;
  uVar22 = *descriptor;
  if (((uVar22 & 0x400000) == 0) || ((descriptor[1] & 0x4444) == 0)) {
    bVar2 = false;
  }
  else {
    arena = psnPackedLaneSource(descriptor,0);
    psnPackedLaneSourceResult = psnPackedLaneSource(descriptor,1);
    psnPackedLaneSourceResult2 = psnPackedLaneSource(descriptor,2);
    psnPackedLaneSourceResult3 = psnPackedLaneSource(descriptor,3);
    pdVar18 = local_94;
    pdVar25 = (dword *)(*(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1);
    *(dword **)(*(int *)(param_1 + 8) + 0x3ac) = pdVar25;
    inst = IRInst__create(0x31,*(undefined4 *)(param_1 + 8));
    operandRecord2 = IRInst__getOperandRecord(inst,0);
    *(undefined4 *)(operandRecord2 + 0xc) = 0;
    *(dword **)(operandRecord2 + 8) = pdVar25;
    uVar14 = FUN_000ec208(param_1,uVar24);
    operandRecord2 = IRInst__getOperandRecord(inst,1);
    *(undefined4 *)(operandRecord2 + 0xc) = uVar14;
    *(dword **)(operandRecord2 + 8) = pdVar31;
    local_94[0] = 0x10203;
    fparam_1 = (double)((double (*)())FUN_000f8a30)(arena,0,&local_98,pdVar18);
    fparam_2 = (double)((double (*)())FUN_000f8a30)(psnPackedLaneSourceResult,1,&local_98,pdVar18);
    fparam_3 = (double)((double (*)())FUN_000f8a30)(psnPackedLaneSourceResult2,2,&local_98,pdVar18);
    fparam_4 = (double)((double (*)())FUN_000f8a30)(psnPackedLaneSourceResult3,3,&local_98,pdVar18);
    dVar4 = local_94[0];
    operandRecord2 = IRInst__getOperandRecord(inst,1);
    *(dword *)(operandRecord2 + 0x10) = dVar4;
    DList__pushBack(list,inst);
    inst = IRInst__create(0x31,*(undefined4 *)(param_1 + 8));
    operandRecord2 = IRInst__getOperandRecord(inst,0);
    *(undefined4 *)(operandRecord2 + 0xc) = 0;
    *(dword **)(operandRecord2 + 8) = pdVar25;
    pdVar17 = (dword *)((int)((unsigned char *)0x0) + 1);
    ((void (*)())IRInst__makeLiteralVec4Float)(inst,param_1,1,fparam_1,fparam_2,fparam_3,fparam_4);
    *(undefined4 *)((int)inst + 0x9c) = local_98;
    DList__pushBack(list,inst);
    uVar22 = *descriptor;
    arena = extraout_r4_10;
    pdVar31 = pdVar25;
    if ((uVar22 & 0x400000) == 0) {
      uVar24 = 4;
      bVar2 = true;
    }
    else {
      uVar24 = 4;
      bVar2 = true;
      descriptor[1] = descriptor[1] & 0xffff8888 | 0x3210;
    }
  }
  if ((uVar22 & 0x400000) == 0) goto code_r0x000fd490;
  puVar21 = (undefined1 *)descriptor[1];
  pdVar29 = descriptor + 1;
  if (((uint)puVar21 & 0xffff8888) == 0) goto code_r0x000fd490;
  pdVar26 = pdVar31;
  if (((ushort)*param_3 - 0x8e < 0x10) && (((uint)puVar21 & 0x8888) != 0)) {
    descriptor[1] = (uint)puVar21 & 0xffff7777;
    pdVar26 = pdVar25;
    if (!bVar2) {
      puVar21 = *(undefined1 **)(param_1 + 8);
      pdVar26 = (dword *)(*(int *)(puVar21 + 0x3ac) + -1);
      *(dword **)(puVar21 + 0x3ac) = pdVar26;
    }
    bVar2 = true;
    inst = IRInst__create(0xcb,*(undefined4 *)(param_1 + 8));
    operandRecord2 = IRInst__getOperandRecord(inst,0);
    pdVar17 = (dword *)((int)((unsigned char *)0x0) + 2);
    *(undefined4 *)(operandRecord2 + 0xc) = 0;
    *(dword **)(operandRecord2 + 8) = pdVar26;
    ((void (*)())IRInst__makeLiteralVec4Float)(inst,param_1,2,0.0,0.0,0.0,0.0);
    arena = FUN_000ec208(param_1,uVar24);
    operandRecord2 = IRInst__getOperandRecord(inst,1);
    *(dword **)(operandRecord2 + 8) = pdVar31;
    *(undefined4 *)(operandRecord2 + 0xc) = arena;
    DList__pushBack(list,inst);
    uVar22 = *descriptor;
    arena = extraout_r4_11;
    uVar24 = 4;
    pdVar25 = pdVar26;
  }
  pdVar31 = pdVar26;
  if (((uVar22 & 0x400000) != 0) && ((*pdVar29 & 0x10000) != 0)) {
    pdVar31 = pdVar25;
    if (!bVar2) {
      puVar21 = *(undefined1 **)(param_1 + 8);
      pdVar31 = (dword *)(*(int *)(puVar21 + 0x3ac) + -1);
      *(dword **)(puVar21 + 0x3ac) = pdVar31;
    }
    inst = IRInst__create(0x12,*(undefined4 *)(param_1 + 8));
    operandRecord2 = IRInst__getOperandRecord(inst,0);
    *(undefined4 *)(operandRecord2 + 0xc) = 0;
    *(dword **)(operandRecord2 + 8) = pdVar31;
    arena = FUN_000ec208(param_1,uVar24);
    operandRecord2 = IRInst__getOperandRecord(inst,1);
    *(undefined4 *)(operandRecord2 + 0xc) = arena;
    *(dword **)(operandRecord2 + 8) = pdVar26;
    IROperand__setModifierBits((int)inst + 0xa4,1,1);
    if (!bVar2) {
      ((int (*)())FUN_000f8f88)(descriptor,inst);
    }
    pdVar17 = (dword *)((int)((unsigned char *)0x0) + 2);
    uVar24 = 4;
    bVar2 = true;
    ((void (*)())IRInst__makeLiteralVec4Float)(inst,param_1,2,1.0,1.0,1.0,1.0);
    DList__pushBack(list,inst);
    uVar22 = *descriptor;
    arena = extraout_r4_12;
    pdVar25 = pdVar31;
  }
  if ((((uVar22 & 0x400000) == 0) || ((*pdVar29 & 0x20000) == 0)) || ((*pdVar29 & 0x40000) == 0)) {
    if (((uVar22 & 0x400000) == 0) || ((*pdVar29 & 0x20000) == 0)) {
      if (((uVar22 & 0x400000) == 0) || ((*pdVar29 & 0x40000) == 0)) goto code_r0x000fcda8;
      if (!bVar2) {
        puVar21 = *(undefined1 **)(param_1 + 8);
        pdVar25 = (dword *)(*(int *)(puVar21 + 0x3ac) + -1);
        *(dword **)(puVar21 + 0x3ac) = pdVar25;
      }
      inst = IRInst__create(0x13,*(undefined4 *)(param_1 + 8));
      operandRecord2 = IRInst__getOperandRecord(inst,0);
      *(undefined4 *)(operandRecord2 + 0xc) = 0;
      *(dword **)(operandRecord2 + 8) = pdVar25;
      arena = FUN_000ec208(param_1,uVar24);
      operandRecord2 = IRInst__getOperandRecord(inst,1);
      *(undefined4 *)(operandRecord2 + 0xc) = arena;
      *(dword **)(operandRecord2 + 8) = pdVar31;
      if (!bVar2) {
        ((int (*)())FUN_000f8f88)(descriptor,inst);
      }
      pdVar17 = (dword *)((int)((unsigned char *)0x0) + 2);
      ((void (*)())IRInst__makeLiteralVec4Float)(inst,param_1,2,2.0,2.0,2.0,2.0);
      pdVar31 = pdVar25;
    }
    else {
      if (!bVar2) {
        puVar21 = *(undefined1 **)(param_1 + 8);
        pdVar25 = (dword *)(*(int *)(puVar21 + 0x3ac) + -1);
        *(dword **)(puVar21 + 0x3ac) = pdVar25;
      }
      inst = IRInst__create(0x12,*(undefined4 *)(param_1 + 8));
      operandRecord2 = IRInst__getOperandRecord(inst,0);
      *(undefined4 *)(operandRecord2 + 0xc) = 0;
      *(dword **)(operandRecord2 + 8) = pdVar25;
      arena = FUN_000ec208(param_1,uVar24);
      operandRecord2 = IRInst__getOperandRecord(inst,1);
      *(undefined4 *)(operandRecord2 + 0xc) = arena;
      *(dword **)(operandRecord2 + 8) = pdVar31;
      if (!bVar2) {
        ((int (*)())FUN_000f8f88)(descriptor,inst);
      }
      ((void (*)())IRInst__makeLiteralVec4Float)(inst,param_1,2,0.5,0.5,0.5,0.5);
      pdVar17 = (dword *)((int)((unsigned char *)0x0) + 1);
      IROperand__setModifierBits((int)inst + 0xbc,1,1);
      pdVar31 = pdVar25;
    }
    DList__pushBack(list,inst);
    uVar22 = *descriptor;
    uVar24 = 4;
    bVar2 = true;
    arena = extraout_r4_14;
    pdVar25 = pdVar31;
  }
  else {
    if (!bVar2) {
      puVar21 = *(undefined1 **)(param_1 + 8);
      pdVar25 = (dword *)(*(int *)(puVar21 + 0x3ac) + -1);
      *(dword **)(puVar21 + 0x3ac) = pdVar25;
    }
    inst = IRInst__create(0x14,*(undefined4 *)(param_1 + 8));
    operandRecord2 = IRInst__getOperandRecord(inst,0);
    *(undefined4 *)(operandRecord2 + 0xc) = 0;
    *(dword **)(operandRecord2 + 8) = pdVar25;
    arena = FUN_000ec208(param_1,uVar24);
    operandRecord2 = IRInst__getOperandRecord(inst,1);
    *(undefined4 *)(operandRecord2 + 0xc) = arena;
    *(dword **)(operandRecord2 + 8) = pdVar31;
    if (!bVar2) {
      ((int (*)())FUN_000f8f88)(descriptor,inst);
    }
    uVar24 = 4;
    bVar2 = true;
    ((void (*)())IRInst__makeLiteralVec4Float)(inst,param_1,2,2.0,2.0,2.0,2.0);
    ((void (*)())IRInst__makeLiteralVec4Float)(inst,param_1,3,1.0,1.0,1.0,1.0);
    pdVar17 = (dword *)((int)((unsigned char *)0x0) + 1);
    IROperand__setModifierBits((int)inst + 0xd4,1,1);
    DList__pushBack(list,inst);
    uVar22 = *descriptor;
    arena = extraout_r4_13;
    pdVar31 = pdVar25;
  }
code_r0x000fcda8:
  pdVar26 = pdVar31;
  if (((uVar22 & 0x400000) != 0) && ((*pdVar29 & 0x80000) != 0)) {
    puVar21 = *(undefined1 **)(param_1 + 8);
    pdVar26 = (dword *)(*(int *)(puVar21 + 0x3ac) + -1);
    *(dword **)(puVar21 + 0x3ac) = pdVar26;
    inst = IRInst__create(0x26,*(undefined4 *)(param_1 + 8));
    operandRecord2 = IRInst__getOperandRecord(inst,0);
    *(undefined4 *)(operandRecord2 + 0xc) = 0;
    *(dword **)(operandRecord2 + 8) = pdVar26;
    arena = FUN_000ec208(param_1,uVar24);
    operandRecord2 = IRInst__getOperandRecord(inst,1);
    *(undefined4 *)(operandRecord2 + 0xc) = arena;
    *(dword **)(operandRecord2 + 8) = pdVar31;
    ((void (*)())IRInst__makeLiteralVec4Float)(inst,param_1,2,1.0,1.0,1.0,1.0);
    arena = FUN_000ec208(param_1,uVar24);
    operandRecord2 = IRInst__getOperandRecord(inst,3);
    *(undefined4 *)(operandRecord2 + 0xc) = arena;
    *(dword **)(operandRecord2 + 8) = pdVar31;
    if (!bVar2) {
      ((int (*)())FUN_000f8f88)(descriptor,inst);
      operandRecord2 = IRInst__getOperandRecord(inst,1);
      arena = *(undefined4 *)(operandRecord2 + 0x10);
      operandRecord2 = IRInst__getOperandRecord(inst,3);
      *(undefined4 *)(operandRecord2 + 0x10) = arena;
    }
    DList__pushBack(list,inst);
    inst = IRInst__create(0x25,*(undefined4 *)(param_1 + 8));
    operandRecord2 = IRInst__getOperandRecord(inst,0);
    *(undefined4 *)(operandRecord2 + 0xc) = 0;
    *(dword **)(operandRecord2 + 8) = pdVar26;
    operandRecord2 = IRInst__getOperandRecord(inst,1);
    *(undefined4 *)(operandRecord2 + 0xc) = 0;
    uVar24 = 4;
    *(dword **)(operandRecord2 + 8) = pdVar26;
    operandRecord2 = IRInst__getOperandRecord(inst,2);
    *(undefined4 *)(operandRecord2 + 0xc) = 0;
    *(dword **)(operandRecord2 + 8) = pdVar26;
    bVar2 = true;
    ((void (*)())IRInst__makeLiteralVec4Float)(inst,param_1,3,1.0,1.0,1.0,1.0);
    pdVar17 = (dword *)((int)((unsigned char *)0x0) + 1);
    IROperand__setModifierBits((int)inst + 0xd4,1,1);
    DList__pushBack(list,inst);
    uVar22 = *descriptor;
    arena = extraout_r4_15;
    pdVar25 = pdVar26;
  }
  pdVar27 = pdVar26;
  if (((uVar22 & 0x400000) != 0) && (uVar23 = *pdVar29 >> 0x15 & 7, uVar23 != 0)) {
    puVar21 = (undefined1 *)**(undefined4 **)(*(int *)(param_1 + 8) + 0x30c);
    uVar39 = (**(code **)(puVar21 + 0xb4))();
    arena = (undefined4)uVar39;
    if (((int)((ulonglong)uVar39 >> 0x20) == 0) ||
       ((pdVar17 = (dword *)(uint)(ushort)*param_3,
        (uint *)((int)&(*(GhidraMachOSection *)0x00000098).size + 2) < pdVar17 ||
        (pdVar17 != (dword *)((*(GhidraMachOSection *)0x00000054).sectname + 9))))) {
      if (uVar23 == 4) {
code_r0x000fd284:
        uVar22 = *descriptor;
      }
      else {
        if (uVar23 == 1) {
          uVar35 = 0x10101;
          iVar20 = 1;
          arena = 0x1000000;
        }
        else if (uVar23 == 2) {
          uVar35 = 0x101;
          iVar20 = 2;
          arena = 0x1010000;
        }
        else {
          if (uVar23 != 3) goto code_r0x000fd284;
          uVar35 = 1;
          iVar20 = 3;
          arena = 0x1010100;
        }
        inst = IRInst__create(0x40,*(undefined4 *)(param_1 + 8));
        pdVar27 = (dword *)(*(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1);
        *(dword **)(*(int *)(param_1 + 8) + 0x3ac) = pdVar27;
        operandRecord3 = IRInst__getOperandRecord(inst,0);
        *(undefined4 *)(operandRecord3 + 0xc) = 0;
        *(undefined4 *)((int)inst + 0x9c) = 0x1010100;
        *(dword **)(operandRecord3 + 8) = pdVar27;
        uVar12 = FUN_000ec208(param_1,uVar24);
        operandRecord3 = IRInst__getOperandRecord(inst,1);
        *(undefined4 *)(operandRecord3 + 0xc) = uVar12;
        *(dword **)(operandRecord3 + 8) = pdVar26;
        newInst = IRInst__create(0x13,*(undefined4 *)(param_1 + 8));
        operandRecord3 = IRInst__getOperandRecord(newInst,0);
        *(undefined4 *)(operandRecord3 + 0xc) = 0;
        *(dword **)(operandRecord3 + 8) = pdVar27;
        uVar12 = FUN_000ec208(param_1,uVar24);
        operandRecord3 = IRInst__getOperandRecord(newInst,1);
        *(undefined4 *)(operandRecord3 + 0xc) = uVar12;
        *(dword **)(operandRecord3 + 8) = pdVar26;
        inst2 = IRInst__create(0x31,*(undefined4 *)(param_1 + 8));
        operandRecord3 = IRInst__getOperandRecord(inst2,0);
        *(undefined4 *)(operandRecord3 + 0xc) = 0;
        *(dword **)(operandRecord3 + 8) = pdVar27;
        uVar12 = FUN_000ec208(param_1,uVar24);
        operandRecord3 = IRInst__getOperandRecord(inst2,1);
        *(undefined4 *)(operandRecord3 + 0xc) = uVar12;
        *(dword **)(operandRecord3 + 8) = pdVar26;
        if (!bVar2) {
          ((int (*)())FUN_000f8f88)(descriptor,newInst);
          operandRecord3 = IRInst__getOperandRecord(newInst,1);
          uVar12 = *(undefined4 *)(operandRecord3 + 0x10);
          operandRecord3 = IRInst__getOperandRecord(inst2,1);
          *(undefined4 *)(operandRecord3 + 0x10) = uVar12;
        }
        operandRecord3 = IRInst__getOperandRecord(newInst,2);
        puVar5 = PTR_DAT_001e8b8c;
        *(undefined4 *)(operandRecord3 + 0xc) = 0;
        uVar12 = *(undefined4 *)(puVar5 + 0xc);
        uVar24 = 4;
        *(dword **)(operandRecord3 + 8) = pdVar27;
        operandRecord3 = IRInst__getOperandRecord(newInst,2);
        *(undefined4 *)(operandRecord3 + 0x10) = uVar12;
        operandRecord3 = IRInst__getOperandRecord(newInst,1);
        puVar21 = &STACKARG(0xffffff30) + iVar20;
        local_80 = *(undefined4 *)(operandRecord3 + 0x10);
        bVar2 = true;
        uVar12 = *(undefined4 *)(puVar5 + (uint)*(byte *)((int)&local_80 + iVar20) * 4);
        operandRecord2 = IRInst__getOperandRecord(inst,1);
        *(undefined4 *)(operandRecord2 + 0x10) = uVar12;
        *(undefined4 *)((int)newInst + 0x9c) = uVar35;
        *(undefined4 *)((int)inst2 + 0x9c) = arena;
        DList__pushBack(list,inst);
        DList__pushBack(list,newInst);
        DList__pushBack(list,inst2);
        uVar22 = *descriptor;
        arena = extraout_r4_17;
        pdVar25 = pdVar27;
      }
    }
    else if (uVar23 == 3) {
      *(undefined4 *)(param_1 + 0x47c) = 1;
      uVar22 = *descriptor;
    }
    else {
      if (uVar23 != 2) goto code_r0x000fd284;
      puVar21 = *(undefined1 **)(param_1 + 8);
      *(undefined4 *)(param_1 + 0x47c) = 1;
      bVar2 = true;
      pdVar27 = (dword *)(*(int *)(puVar21 + 0x3ac) + -1);
      *(dword **)(puVar21 + 0x3ac) = pdVar27;
      newInst3 = IRInst__create(0x31,*(undefined4 *)(param_1 + 8));
      operandRecord2 = IRInst__getOperandRecord(newInst3,0);
      *(undefined4 *)(operandRecord2 + 0xc) = 0;
      *(dword **)(operandRecord2 + 8) = pdVar27;
      arena = FUN_000ec208(param_1,uVar24);
      operandRecord2 = IRInst__getOperandRecord(newInst3,1);
      *(undefined4 *)(operandRecord2 + 0xc) = arena;
      *(dword **)(operandRecord2 + 8) = pdVar26;
      ((int (*)())FUN_000f8f88)(descriptor,newInst3);
      pcVar36 = *(code **)(*newInst3 + 0x88);
      operandRecord2 = IRInst__getOperandRecord(newInst3,1);
      pdVar18 = (dword *)(uint)*(byte *)(operandRecord2 + 0x12);
      pdVar17 = (dword *)((int)((unsigned char *)0x0) + 3);
      (*pcVar36)(newInst3,1);
      DList__pushBack(list,newInst3);
      uVar22 = *descriptor;
      arena = extraout_r4_16;
      uVar24 = 4;
      pdVar25 = pdVar27;
    }
  }
  pdVar31 = pdVar27;
  if (((((uVar22 & 0x400000) != 0) && ((*pdVar29 & 0x8888) != 0)) &&
      (uVar22 = psnPackedNegateMask(descriptor,arena,pdVar17,pdVar18,param_5,pdVar32,puVar21), uVar22 != 0))
     && (uVar22 != 0x8888)) {
    pdVar31 = pdVar25;
    if (!bVar2) {
      pdVar31 = (dword *)(*(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1);
      *(dword **)(*(int *)(param_1 + 8) + 0x3ac) = pdVar31;
    }
    inst = IRInst__create(0x31,*(undefined4 *)(param_1 + 8));
    operandRecord2 = IRInst__getOperandRecord(inst,0);
    *(dword **)(operandRecord2 + 8) = pdVar31;
    *(undefined4 *)(operandRecord2 + 0xc) = 0;
    arena = FUN_000ec208(param_1,uVar24);
    operandRecord2 = IRInst__getOperandRecord(inst,1);
    *(undefined4 *)(operandRecord2 + 0xc) = arena;
    *(dword **)(operandRecord2 + 8) = pdVar27;
    if (!bVar2) {
      ((int (*)())FUN_000f8f88)(descriptor,inst);
    }
    if (((*descriptor & 0x400000) != 0) && ((*pdVar29 & 0x100000) != 0)) {
      IROperand__setModifierBits((int)inst + 0xa4,2,1);
    }
    DList__pushBack(list,inst);
    operandRecord2 = IRInst__getOperandRecord(inst,1);
    uVar35 = *(undefined4 *)(operandRecord2 + 0x10);
    inst = IRInst__create(0x31,*(undefined4 *)(param_1 + 8));
    operandRecord2 = IRInst__getOperandRecord(inst,0);
    *(undefined4 *)(operandRecord2 + 0xc) = 0;
    *(dword **)(operandRecord2 + 8) = pdVar31;
    arena = FUN_000ec208(param_1,uVar24);
    operandRecord2 = IRInst__getOperandRecord(inst,1);
    *(undefined4 *)(operandRecord2 + 0xc) = arena;
    *(dword **)(operandRecord2 + 8) = pdVar27;
    if (!bVar2) {
      operandRecord2 = IRInst__getOperandRecord(inst,1);
      *(undefined4 *)(operandRecord2 + 0x10) = uVar35;
    }
    IROperand__setModifierBits((int)inst + 0xa4,1,1);
    if ((((*descriptor & 0x400000) != 0) && ((*pdVar29 & 0x100000) != 0)) &&
       (IROperand__setModifierBits((int)inst + 0xa4,2,1), (*descriptor & 0x400000) != 0)) {
      *pdVar29 = *pdVar29 & 0xffefffff;
    }
    *(uint *)((int)inst + 0x9c) =
         uVar22 >> 0xf & 1 ^ 1 |
         (uVar22 >> 0xb & 1 ^ 1) << 8 |
         (uVar22 >> 7 & 1 ^ 1) << 0x10 | (uVar22 >> 3 & 1 ^ 1) << 0x18;
    DList__pushBack(list,inst);
    if ((*descriptor & 0x400000) != 0) {
      *pdVar29 = *pdVar29 & 0xffff7777;
    }
    uVar24 = 4;
  }
code_r0x000fd490:
  if (bVar3) {
    *(short *)((int)descriptor + 2) = (short)pdVar31;
    *descriptor = uVar24 << 0x10 | *descriptor & 0xffc0ffff;
  }
  return;
}

/* FUN_000fd50c @ 0xfd50c (188 bytes) */
int FUN_000fd50c(param_1, param_2, param_3, param_4, param_5, vector)
  int param_1;
  undefined4 param_2;
  undefined4 *param_3;
  undefined4 param_4;
  undefined4 param_5;
  uint *vector;
{
  undefined4 *allocation;
  int *piVar2;
  uint uVar3;
  undefined4 arena;
  
  arena = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  allocation = (undefined4 *)Arena__alloc(arena,0x10);
  *allocation = arena;
  allocation[1] = param_2;
  arena = *param_3;
  allocation[3] = param_4;
  allocation[2] = arena;
  uVar3 = vector[1];
  if (uVar3 < *vector) {
    _memset(uVar3 * 4 + vector[2],0,4);
    piVar2 = (int *)(uVar3 * 4 + vector[2]);
    vector[1] = uVar3 + 1;
  }
  else {
    piVar2 = (int *)Vector__elementRefGrow(vector,uVar3);
  }
  *piVar2 = (int)(allocation + 1);
  *param_3 = 0xffffffff;
  return param_5;
}

/* FUN_000fd5c8 @ 0xfd5c8 (408 bytes) */
int FUN_000fd5c8(program, ilReader)
  int program;
  uint ******ilReader;
{
  undefined4 irOpcode;
  undefined4 enclosingLoopHeader;
  undefined4 ifConditionInst;
  undefined4 comparisonKind;
  undefined4 selectWord;
  undefined4 remappedSelect;
  undefined4 continueTargetBlock;
  undefined4 breakTargetBlock;
  undefined4 opcodeRecordTable;
  undefined4 registerMap;
  undefined4 virtualRegister;
  undefined4 registerInfo;
  undefined4 registerFile;
  undefined4 translationKind;
  undefined4 compilerArenaA;
  undefined4 vectorStorage;
  bool bVar1;
  bool bVar2;
  bool bVar3;
  byte bVar4;
  float fVar5;
  short sVar6;
  ushort uVar7;
  undefined *puVar8;
  undefined *puVar9;
  uint uVar10;
  uint *****pppppuVar11;
  uint *puVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  uint *****pppppuVar15;
  void *pvVar16;
  uint uVar17;
  int *piVar18;
  uint ******ppppppuVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  undefined4 *puVar24;
  int iVar25;
  undefined2 *puVar26;
  undefined4 uVar27;
  undefined2 uVar31;
  undefined4 *puVar28;
  undefined4 *puVar29;
  uint ****ppppuVar30;
  undefined4 *puVar32;
  uint ******in_r6;
  uint ******in_r7;
  uint ******in_r8;
  uint ***pppuVar33;
  int iVar34;
  uint *puVar35;
  int *piVar36;
  uint ******ppppppuVar37;
  uint ******ppppppuVar38;
  uint ******ppppppuVar39;
  uint ******ppppppuVar40;
  undefined4 uVar41;
  uint ***pppuVar42;
  int iVar43;
  uint uVar44;
  uint ****ppppuVar45;
  undefined4 compilerArenaB;
  int iVar47;
  uint ******ppppppuVar48;
  uint ******ppppppuVar49;
  undefined4 uVar50;
  uint ****ppppuVar51;
  uint *****pppppuVar52;
  undefined1 *puVar53;
  double dVar54;
  uint ****local_188;
  uint *****previousBlock;
  uint *****currentBlock;
  int *local_17c;
  undefined4 local_178;
  uint ****local_174;
  uint *****local_170;
  /* issue #64 live-repro (2nd instance, same function): DListNode__init(local_6c=auStack_16c), two lines
   * below DListNode__init(local_68=auStack_154) which already got this fix, writes the same 6-word/0x18-byte
   * sentinel-list header (see the comment on auStack_154 just below) - word[2] (self-referential "next",
   * program[2] = program+3) is what `local_164`'s four loops read as the list head, same shape as
   * local_14c's. auStack_16c was declared only 8 bytes with local_164 as a separate scalar 8 bytes in;
   * live-confirmed the pointer this yields (local_164, still holding the list head's own address) is a
   * real puVar13 but reads back as MallocPreScribble's 0xAA fill - i.e. never received the init write,
   * same root cause as local_14c's, just missed by that fix since it's a second, independent instance.
   * Merged into one 0x18-byte buffer the same way, aliased back to the original name. */
  unsigned char auStack_16c [0x18];
#define local_164 (*(int *)(auStack_16c + 0x08))
  /* issue #64 live-repro: DListNode__init (called below via local_68=auStack_154) writes program[0]
   * through program[5] - 6 words, 0x18 bytes - into whatever auStack_154 points to, including a
   * self-referential empty-list-head init at program[2] (offset 8: *(auStack_154+8) = auStack_154+12).
   * auStack_154 was declared only 8 bytes; local_14c (used as a list head in four separate loops
   * later in this function) sits exactly at that offset-8 slot by its own hex name (0x154-0x14c=8),
   * and the 12 bytes after it (up to local_13c, 0x154-0x13c=0x18) are the same buffer's remaining
   * two words, never individually named. Left separate, local_14c never receives its initializer at
   * all in the rebuild (confirmed live: read as garbage/uninitialized), corrupting every one of the
   * four unlink loops that use it as a list head - traced down to a crash in DList__unlink, a plain
   * linked-list unlink helper, dereferencing garbage. Merged into one 0x18-byte buffer. */
  unsigned char auStack_154 [0x18];
#define local_14c (*(int *)(auStack_154 + 0x08))
  uint *local_13c;
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_124;
  int local_11c;
  uint ****local_118;
  undefined4 local_104;
  int local_100;
  undefined4 local_d8;
  uint ****local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  uint local_c4;
  uint *****local_c0;
  int local_bc;
  int local_b8;
  undefined4 local_b4;
  uint *conditionStack;
  int local_ac;
  uint *****ifStack;
  uint *****local_a4;
  undefined4 *local_a0;
  uint local_9c;
  uint local_98;
  uint local_94;
  uint local_90;
  uint local_8c;
  uint *****local_88;
  uint *****local_84;
  uint local_80;
  uint ****local_7c;
  undefined *local_78;
  int local_74;
  undefined4 *local_70;
  undefined1 *local_6c;
  undefined1 *local_68;
  int local_64;
  undefined *local_60;
  undefined *local_5c;
  uint ****local_58;
  
  iVar34 = *(int *)(*(int *)(program + 8) + 0x30c);
  local_9c = 0;
  local_98 = 0;
  *(uint *)(iVar34 + 8) = *(uint *)(iVar34 + 8) & 0xffffffdf;
  local_94 = 0;
  compilerArenaB = *(undefined4 *)(*(int *)(program + 8) + 0x378);
  iVar34 = *(int *)(*(int *)(*(int *)(program + 8) + 0x30c) + 0x50);
  uVar10 = iVar34 + 0x1fU >> 5;
  puVar13 = (undefined4 *)Arena__alloc(compilerArenaB,uVar10 * 4 + 0xc);
  local_a0 = puVar13 + 1;
  *puVar13 = compilerArenaB;
  puVar13[1] = uVar10;
  puVar13[2] = iVar34;
  local_90 = 0;
  local_8c = 0;
  local_88 = (uint *****)0x0;
  local_84 = (uint *****)0x0;
  local_80 = 0;
  if (uVar10 != 0) {
    puVar13 = local_a0;
    if (uVar10 == 0) {
      uVar10 = 1;
    }
    do {
      uVar10 = uVar10 - 1;
      puVar13[2] = 0;
      puVar13 = puVar13 + 1;
    } while (uVar10 != 0);
  }
  compilerArenaB = *(undefined4 *)(*(int *)(program + 8) + 0x378);
  puVar13 = (undefined4 *)Arena__alloc(compilerArenaB,0x14);
  ppppppuVar37 = (uint ******)(puVar13 + 1);
  *puVar13 = compilerArenaB;
  puVar13[1] = 2;
  puVar13[4] = compilerArenaB;
  puVar13[2] = 0;
  vectorStorage = Arena__alloc(compilerArenaB,8);
  puVar13[3] = vectorStorage;
  local_188 = (uint ****)0x0;
  compilerArenaB = *(undefined4 *)(*(int *)(program + 8) + 0x378);
  puVar14 = (undefined4 *)Arena__alloc(compilerArenaB,0x14);
  ifStack = (uint *****)(puVar14 + 1);
  *puVar14 = compilerArenaB;
  puVar14[1] = 2;
  puVar14[4] = compilerArenaB;
  puVar14[2] = 0;
  pppppuVar15 = (uint *****)Arena__alloc(compilerArenaB,8);
  ifStack[2] = (uint ****)pppppuVar15;
  compilerArenaB = *(undefined4 *)(*(int *)(program + 8) + 0x378);
  puVar14 = (undefined4 *)Arena__alloc(compilerArenaB,0x14);
  conditionStack = puVar14 + 1;
  *puVar14 = compilerArenaB;
  puVar14[1] = 2;
  puVar14[2] = 0;
  puVar14[4] = compilerArenaB;
  uVar10 = Arena__alloc(compilerArenaB,8);
  conditionStack[2] = uVar10;
  compilerArenaB = *(undefined4 *)(*(int *)(program + 8) + 0x378);
  puVar14 = (undefined4 *)Arena__alloc(compilerArenaB,0x14);
  puVar14[1] = 2;
  *puVar14 = compilerArenaB;
  puVar14[2] = 0;
  puVar14[4] = compilerArenaB;
  vectorStorage = Arena__alloc(compilerArenaB,8);
  puVar14[3] = vectorStorage;
  *(undefined4 **)(program + 0x414) = puVar14 + 1;
  compilerArenaB = *(undefined4 *)(*(int *)(program + 8) + 0x378);
  puVar14 = (undefined4 *)Arena__alloc(compilerArenaB,0x14);
  puVar14[1] = 2;
  *puVar14 = compilerArenaB;
  puVar14[2] = 0;
  puVar14[4] = compilerArenaB;
  vectorStorage = Arena__alloc(compilerArenaB,8);
  puVar14[3] = vectorStorage;
  local_5c = &DAT_001ad5d8;
  previousBlock = *(uint ******)(program + 0x3a0);
  local_128 = 0;
  local_170 = (uint *****)0x1010101;
  local_174 = (uint ****)0xffffffff;
  local_138 = 0;
  local_134 = 0;
  local_130 = 0;
  local_12c = 0;
  compilerArenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
  local_13c = puVar14 + 1;
  puVar14 = (undefined4 *)Arena__alloc(compilerArenaA,0x130);
  *puVar14 = compilerArenaA;
  ppppppuVar49 = (uint ******)(puVar14 + 1);
  Block__ctor_ea020(ppppppuVar49,*(undefined4 *)(program + 8));
  currentBlock = (uint *****)ppppppuVar49;
  FUN_000ec3ac(program,previousBlock,ppppppuVar49);
  local_6c = auStack_16c;
  Block__connect(previousBlock,currentBlock);
  local_68 = auStack_154;
  previousBlock = currentBlock;
  DListNode__init(local_6c);
  DListNode__init(local_68);
  *(undefined4 *)(program + 0x3d4) = 0;
  *(undefined4 *)(program + 0x3e4) = 0;
  ((int (*)())FUN_000fb230)(program,ilReader);
  local_a4 = (uint *****)0x0;
  local_ac = 0;
switchD_000fdaf0_caseD_2:
  iVar34 = FUN_000e5e70(ilReader);
  if (iVar34 == 0) {
code_r0x00103c40:
    FUN_000ec728(program);
    Block__connect(currentBlock,*(undefined4 *)(program + 0x3a8));
    *(uint *)(program + 0x30) = *(uint *)(program + 0x30) | 2;
    FUN_0012e8c0(program,*(undefined4 *)(program + 0x3a0),*(undefined4 *)(program + 0x3a8));
    if ((uint ******)ifStack != (uint ******)0x0) {
      Arena__free(ifStack[3],ifStack[2]);
      Arena__free(ifStack[-1],ifStack + -1);
    }
    if (ppppppuVar37 != (uint ******)0x0) {
      Arena__free(puVar13[4],puVar13[3]);
      Arena__free(*puVar13,puVar13);
    }
    if (local_a0 != (undefined4 *)0x0) {
      Arena__free(local_a0[-1],local_a0 + -1);
    }
    Arena__free(*(undefined4 *)(*(int *)(program + 8) + 0x378),*(undefined4 *)(program + 0x78));
    FUN_0011e894(program);
    return;
  }
  iVar34 = FUN_000e43ec(ilReader);
  if (iVar34 != 0) {
    iVar34 = *(int *)(program + 0x3c4);
    iVar43 = 0;
    local_17c = (int *)0x0;
    for (uVar10 = 1; uVar10 <= *(uint *)(iVar34 + 4); uVar10 = uVar10 + 1) {
      local_17c = *(int **)(iVar43 + *(int *)(iVar34 + 8));
      if ((local_17c[5] & 1U) != 0) {
        (**(code **)(*local_17c + 0x68))(local_17c);
        piVar18 = local_17c;
        pvVar16 = IRInst__create(0x31,*(undefined4 *)(program + 8));
        IRInst__setOperandRef(pvVar16,1,local_17c[0x29]);
        puVar12 = local_13c;
        uVar44 = piVar18[0x50];
        if (uVar44 < *local_13c) {
          uVar17 = local_13c[1];
          if (uVar17 <= uVar44) {
            _memset(uVar17 * 4 + local_13c[2],0,(uVar44 - uVar17) * 4 + 4);
            puVar12[1] = uVar44 + 1;
          }
          puVar14 = (undefined4 *)(uVar44 * 4 + puVar12[2]);
        }
        else {
          puVar14 = (undefined4 *)Vector__elementRefGrow(local_13c,uVar44);
        }
        *puVar14 = pvVar16;
        iVar34 = *(int *)(program + 0x3c4);
      }
      iVar43 = iVar43 + 4;
    }
    piVar18 = *(int **)(*(int *)(program + 8) + 0x30c);
    (**(code **)(*piVar18 + 0x17c))(piVar18,program);
    FUN_000e5e70(ilReader);
  }
  ppppppuVar49 = ilReader + 0x23;
  *(undefined4 *)(program + 0x47c) = 0;
  iVar34 = FUN_000e4408(ilReader);
  if (iVar34 == 0x52) {
    *(uint *)(program + 0x30) = *(uint *)(program + 0x30) | 0x100;
  }
  else if (((iVar34 == 0x84) && ((*(uint *)(program + 0x30) & 0x40000) != 0)) &&
          ((*(uint *)(program + 0x30) & 0x200000) == 0)) goto code_r0x00103c40;
  iVar43 = *(int *)(program + 8);
  piVar18 = *(int **)(iVar43 + 0x30c);
  iVar47 = piVar18[3];
  translationKind = ((int (*)())FUN_000f89a4)(iVar34,iVar47);
  switch(translationKind) {
  case 0:
  case 1:
    switch(iVar34) {
    case 0x14:
      if ((*(uint *)(program + 0x30) & 0x4000) == 0) {
        ppppuVar45 = *ilReader[0x1b];
        iVar34 = FUN_000ec208(program,(uint)*ppppuVar45 >> 0x10 & 0x3f);
        iVar43 = *(int *)(program + 8);
        if (((((uint)*ppppuVar45 & 0x3f0000) == 0x100000) && (iVar43 != 0)) &&
           ((*(uint *)(*(int *)(iVar43 + 0x30c) + 8) & 0x80) != 0)) {
          iVar47 = 0xf;
        }
        else {
          iVar47 = (int)*(short *)((int)ppppuVar45 + 2);
        }
        if (((((uint)*ilReader[0x1b][1] & 0x3f0000) == 0x100000) && (iVar43 != 0)) &&
           ((*(uint *)(*(int *)(iVar43 + 0x30c) + 8) & 0x80) != 0)) {
          iVar43 = 0xf;
        }
        else {
          iVar43 = (int)*(short *)((int)ilReader[0x1b][1] + 2);
        }
        if (iVar34 == 0x15) {
code_r0x000fed00:
          if ((*(uint *)(program + 0x30) & 0x4000) == 0) {
            *(int *)(program + 1000) = iVar47;
            *(undefined4 *)(program + 0x3e4) = 1;
            *(int *)(program + 0x3ec) = iVar43 + 1;
            *(int *)(program + 0x3f4) = iVar34;
            if (((*(uint *)(program + 0x30) & 1) != 0) && (iVar47 < iVar43 + 1)) {
              do {
                in_r6 = (uint ******)0x0;
                FUN_00127608(*(undefined4 *)(program + 0x3ac),iVar34,iVar47,0);
                iVar47 = iVar47 + 1;
              } while (iVar47 < *(int *)(program + 0x3ec));
            }
          }
          goto switchD_000fdaf0_caseD_2;
        }
        if (iVar34 < 0x16) {
          if (iVar34 != 0x14) goto switchD_000fdaf0_caseD_2;
        }
        else if (iVar34 != 0x1a) {
          if (iVar34 == 0x24) goto code_r0x000fed00;
          goto switchD_000fdaf0_caseD_2;
        }
        *(int *)(program + 1000) = iVar47;
        *(undefined4 *)(program + 0x3e4) = 1;
        *(int *)(program + 0x3ec) = iVar43 + 1;
        *(int *)(program + 0x3f4) = iVar34;
        if (((*(uint *)(program + 0x30) & 1) != 0) && (iVar47 < iVar43 + 1)) {
          do {
            in_r6 = (uint ******)0x0;
            FUN_00127608(*(undefined4 *)(program + 0x3ac),iVar34,iVar47,0);
            iVar47 = iVar47 + 1;
          } while (iVar47 < *(int *)(program + 0x3ec));
        }
      }
    default:
      goto switchD_000fdaf0_caseD_2;
    case 0x16:
    case 0x18:
      if ((*(uint *)(*(int *)(iVar43 + 0x6c4) + 0x30) & 0x2000) != 0) {
        pppuVar42 = **ilReader[0x19];
        uVar10 = (uint)pppuVar42 >> 0x10 & 0x3f;
        if (((((uint)pppuVar42 & 0x3f0000) == 0x100000) && (iVar43 != 0)) &&
           ((piVar18[2] & 0x80U) != 0)) {
          ppppppuVar19 = (uint ******)((int)((unsigned char *)0xc) + 3);
        }
        else {
          ppppppuVar19 = (uint ******)(int)*(short *)((int)*ilReader[0x19] + 2);
        }
        registerFile = FUN_000ec208(program,uVar10);
        in_r6 = (uint ******)FUN_000ec2a0(program,uVar10);
        iVar34 = FUN_00127608(*(undefined4 *)(program + 0x3ac),registerFile,ppppppuVar19,0);
        iVar34 = *(int *)(iVar34 + 0x38);
        FUN_001041d0(iVar34,0,(uint)*ppppppuVar49 >> 0x10 & 3,in_r6,ppppppuVar19);
        FUN_001041d0(iVar34,1,(uint)*ppppppuVar49 >> 0x12 & 3,in_r6,ppppppuVar19);
        FUN_001041d0(iVar34,2,(uint)*ppppppuVar49 >> 0x14 & 3,in_r6,ppppppuVar19);
        in_r7 = ppppppuVar19;
        FUN_001041d0(iVar34,3,(uint)*ppppppuVar49 >> 0x16 & 3,in_r6,ppppppuVar19);
        pppppuVar15 = *ppppppuVar49;
        if (((uint)pppppuVar15 & 0x1000000) != 0) {
          *(uint *)(iVar34 + 0x13c) = *(uint *)(iVar34 + 0x13c) | 1;
          pppppuVar15 = *ppppppuVar49;
        }
        *(uint *******)(iVar34 + 0x148) = ppppppuVar19;
        *(uint *)(iVar34 + 0x140) = (uint)pppppuVar15 >> 0x19 & 1;
        *(undefined4 *)(iVar34 + 0x144) = registerFile;
      }
      goto switchD_000fdaf0_caseD_2;
    case 0x17:
      ppppppuVar19 = (uint ******)FUN_000ec27c(program,(uint)*ppppppuVar49 >> 0x10 & 0x1f);
      ppppppuVar38 = (uint ******)((uint)*ppppppuVar49 >> 0x15 & 0xff);
      if ((int)*ppppppuVar49 < 0) {
        pppppuVar15 = ilReader[0x24];
        uVar17 = (uint)pppppuVar15 >> 9 & 1;
        uVar10 = (uint)pppppuVar15 >> 8 & 1;
        uVar44 = (uint)pppppuVar15 >> 10 & 1;
        local_178 = (uint ******)
                    (CONCAT31(CONCAT21(CONCAT11((char)pppppuVar15,(char)((uint)pppppuVar15 >> 2)),
                                       (char)((uint)pppppuVar15 >> 4)),
                              (char)((uint)pppppuVar15 >> 6)) & 0x3030303);
      }
      else {
        uVar10 = 0;
        uVar44 = 0;
        uVar17 = 0;
        local_178 = (uint ******)0x3030303;
      }
      iVar43 = (int)*(short *)((int)*ilReader[0x19] + 2);
      registerFile = FUN_000ec208(program,(uint)**ilReader[0x19] >> 0x10 & 0x3f);
      iVar34 = *(int *)(program + 1000);
      if (iVar43 <= *(int *)(program + 1000)) {
        iVar34 = iVar43;
      }
      iVar47 = *(int *)(program + 0x3ec);
      *(int *)(program + 1000) = iVar34;
      if (iVar47 <= iVar43) {
        iVar47 = iVar43 + 1;
      }
      *(int *)(program + 0x3ec) = iVar47;
      *(undefined4 *)(program + 0x3f4) = 0x24;
      in_r6 = (uint ******)0x0;
      iVar34 = FUN_00127608(*(undefined4 *)(program + 0x3ac),registerFile,iVar43,0);
      iVar34 = *(int *)(iVar34 + 0x38);
      if (uVar10 == 0) {
        *(uint *)(iVar34 + 0x13c) = *(uint *)(iVar34 + 0x13c) | 1;
      }
      if (uVar44 != 0) {
        *(uint *)(iVar34 + 0x13c) = *(uint *)(iVar34 + 0x13c) | 4;
      }
      if (uVar17 != 0) {
        *(uint *)(iVar34 + 0x13c) = *(uint *)(iVar34 + 0x13c) | 2;
      }
      local_70 = &local_178;
      iVar43 = 0;
      do {
        if (*(byte *)(iVar43 + (int)local_70) != 0) {
          in_r6 = ppppppuVar19;
          in_r7 = ppppppuVar38;
          FUN_001041d0(iVar34,iVar43,(uint)*(byte *)(iVar43 + (int)local_70),ppppppuVar19,
                       ppppppuVar38);
        }
        bVar1 = iVar43 != 3;
        iVar43 = iVar43 + 1;
      } while (bVar1);
      goto switchD_000fdaf0_caseD_2;
    case 0x19:
      bVar4 = *(byte *)((int)ilReader + 0x8d);
      pppppuVar15 = *ppppppuVar49;
      iVar34 = (uint)bVar4 * 0xc;
      *(uint *)(*(int *)(program + 0x78) + iVar34) = (uint)pppppuVar15 >> 0x1b & 3;
      if (*(int *)(*(int *)(*(int *)(program + 8) + 0x30c) + 0x50) < (int)(uint)bVar4) {
        Compiler__fail(*(int *)(program + 8),7);
      }
      uVar10 = bVar4 >> 3 & 0x1c;
      *(uint *)((int)local_a0 + uVar10 + 8) =
           1 << (bVar4 & 0x1f) | *(uint *)((int)local_a0 + uVar10 + 8);
      *(uint *)(iVar34 + *(int *)(program + 0x78) + 8) = (uint)*ppppppuVar49 >> 0x1d & 1;
      piVar18 = *(int **)(*(int *)(program + 8) + 0x30c);
      iVar43 = (**(code **)(*piVar18 + 0x48))(piVar18,program,(uint)pppppuVar15 >> 0x18 & 7);
      if (iVar43 != 0) {
        *(int *)(iVar34 + *(int *)(program + 0x78) + 4) = iVar43;
      }
      goto switchD_000fdaf0_caseD_2;
    case 0x1a:
      DListNode__init(&local_124);
      pppppuVar15 = *ppppppuVar49;
      in_r7 = (uint ******)0x4050607;
      uVar10 = 0;
      if ((int)pppppuVar15 < 0) {
        pppppuVar52 = ilReader[0x24];
        bVar1 = ((uint)pppppuVar52 & 3) != 0;
        in_r7 = *(uint *******)(local_5c + -0x2bf8);
        if (bVar1) {
          in_r7 = (uint ******)((uint)in_r7 & 0xffffff | 0x4000000);
        }
        uVar10 = (uint)bVar1;
        if (((uint)pppppuVar52 & 0xc) != 0) {
          iVar34 = uVar10 + 4;
          uVar10 = uVar10 + 1;
          in_r7 = (uint ******)(iVar34 * 0x10000 | (uint)in_r7 & 0xff00ffff);
        }
        if (((uint)pppppuVar52 & 0x30) != 0) {
          iVar34 = uVar10 + 4;
          uVar10 = uVar10 + 1;
          in_r7 = (uint ******)(iVar34 * 0x100 | (uint)in_r7 & 0xffff00ff);
        }
        if (((uint)pppppuVar52 & 0xc0) != 0) {
          uVar44 = uVar10 + 4;
          uVar10 = uVar10 + 1;
          in_r7 = (uint ******)(uVar44 | (uint)in_r7 & 0xffffff00);
        }
      }
      in_r6 = (uint ******)*ilReader[0x19];
      if (((uint)*in_r6 & 0x400000) != 0) {
        in_r7 = *(uint *******)(local_5c + -0x2bf8);
        iVar34 = psnPackedLaneComponent(in_r6,0);
        puVar8 = PTR_DAT_001e8bc8;
        if (*(int *)(PTR_DAT_001e8bc8 + iVar34 * 4) == 0) {
          iVar34 = uVar10 + 4;
          uVar10 = uVar10 + 1;
          in_r7 = (uint ******)(iVar34 * 0x1000000 | (uint)in_r7 & 0xffffff);
        }
        iVar34 = psnPackedLaneComponent(in_r6,1);
        if (*(int *)(puVar8 + iVar34 * 4) == 0) {
          iVar34 = uVar10 + 4;
          uVar10 = uVar10 + 1;
          in_r7 = (uint ******)(iVar34 * 0x10000 | (uint)in_r7 & 0xff00ffff);
        }
        iVar34 = psnPackedLaneComponent(in_r6,2);
        if (*(int *)(puVar8 + iVar34 * 4) == 0) {
          iVar34 = uVar10 + 4;
          uVar10 = uVar10 + 1;
          in_r7 = (uint ******)(iVar34 * 0x100 | (uint)in_r7 & 0xffff00ff);
        }
        iVar34 = psnPackedLaneComponent(in_r6,3);
        if (*(int *)(puVar8 + iVar34 * 4) == 0) {
          in_r7 = (uint ******)(uVar10 + 4 | (uint)in_r7 & 0xffffff00);
        }
      }
      iVar43 = (int)*(short *)((int)in_r6 + 2);
      iVar34 = *(int *)(program + 0x3d8);
      if (iVar43 <= *(int *)(program + 0x3d8)) {
        iVar34 = iVar43;
      }
      iVar47 = *(int *)(program + 0x3dc);
      *(int *)(program + 0x3d8) = iVar34;
      if (iVar47 <= iVar43) {
        iVar47 = iVar43 + 1;
      }
      *(int *)(program + 0x3dc) = iVar47;
      piVar18 = *(int **)(*(int *)(program + 8) + 0x30c);
      in_r8 = *(uint *******)(program + 0x3a0);
      (**(code **)(*piVar18 + 0x4c))(piVar18,program,(uint)pppppuVar15 >> 0x10 & 0x3f);
      iVar43 = *(int *)(local_11c + 8);
      iVar34 = local_11c;
      while (iVar47 = iVar43, iVar47 != 0) {
        DList__unlink(iVar34);
        ((int (*)())FUN_000f92fc)(program,iVar34,currentBlock);
        iVar34 = iVar47;
        iVar43 = *(int *)(iVar47 + 8);
      }
      local_124 = (uint *****)(PTR_DAT_001e8b48 + 8);
      local_118 = (uint ****)local_124;
      goto switchD_000fdaf0_caseD_2;
    case 0x1b:
      iVar34 = FUN_000ec27c(program,(uint)*ppppppuVar49 >> 0x10 & 0x1f);
      ppppppuVar19 = (uint ******)((uint)*ppppppuVar49 >> 0x15 & 0xff);
      local_178 = (uint ******)0x0;
      if ((int)*ppppppuVar49 < 0) {
        pppppuVar15 = ilReader[0x24];
        (*(unsigned short *)((unsigned char *)&(local_178) + 2)) =
             (ushort)(((uint)(byte)((((uint)pppppuVar15 & 0xc0) == 0) << 1) << 0x14) >> 0x15);
        local_178 = (uint ******)
                    CONCAT13(((uint)pppppuVar15 & 3) == 0,
                             CONCAT12(((uint)pppppuVar15 & 0xc) == 0,(*(unsigned short *)((unsigned char *)&(local_178) + 2))));
        (*(unsigned short *)((unsigned char *)&(local_178) + 2)) = CONCAT11(((uint)pppppuVar15 & 0x30) == 0,(undefined1)local_178);
      }
      iVar43 = (int)*(short *)((int)*ilReader[0x19] + 2);
      registerFile = FUN_000ec208(program,(uint)**ilReader[0x19] >> 0x10 & 0x3f);
      if (iVar34 == 0) {
        *(int *)(*(int *)(program + 0x3ac) + 0x44) = iVar43;
      }
      else if (iVar34 == 1) {
        *(int *)(*(int *)(program + 0x3ac) + 0x48) = iVar43;
      }
      iVar47 = *(int *)(program + 1000);
      if (iVar43 <= *(int *)(program + 1000)) {
        iVar47 = iVar43;
      }
      iVar20 = *(int *)(program + 0x3ec);
      *(int *)(program + 1000) = iVar47;
      if (iVar20 <= iVar43) {
        iVar20 = iVar43 + 1;
      }
      *(int *)(program + 0x3ec) = iVar20;
      *(undefined4 *)(program + 0x3f4) = 0x24;
      in_r6 = (uint ******)0x0;
      piVar18 = (int *)FUN_00127608(*(undefined4 *)(program + 0x3ac),registerFile,iVar43,0);
      registerInfo = (**(code **)(*piVar18 + 0x2c))();
      local_70 = &local_178;
      iVar43 = 0;
      do {
        if (*(char *)(iVar43 + (int)local_70) == '\0') {
          in_r6 = ppppppuVar19;
          FUN_00104104(registerInfo,iVar43,iVar34,ppppppuVar19);
        }
        bVar1 = iVar43 != 3;
        iVar43 = iVar43 + 1;
      } while (bVar1);
      goto switchD_000fdaf0_caseD_2;
    case 0x1c:
    case 0x1d:
    case 0x79:
      in_r6 = (uint ******)ilReader[0x17];
      pppuVar42 = **ilReader[0x19];
      sVar6 = *(short *)((int)*ilReader[0x19] + 2);
      if ((int)in_r6 < 1) {
        in_r6 = (uint ******)0x0;
      }
      else {
        puVar12 = &local_124;
        ppppppuVar19 = ilReader + (int)ilReader[0x16] + 0x23;
        ppppppuVar49 = in_r6;
        do {
          pppppuVar15 = *ppppppuVar19;
          ppppppuVar19 = ppppppuVar19 + 1;
          *puVar12 = (uint)pppppuVar15;
          puVar12 = puVar12 + 1;
          ppppppuVar49 = (uint ******)((int)ppppppuVar49 - 1);
        } while (ppppppuVar49 != (uint ******)0x0);
      }
      in_r7 = (uint ******)&local_124;
      ((int (*)())FUN_000fafa4)(program,(uint)pppuVar42 >> 0x10 & 0x3f,(int)sVar6,in_r6,in_r7);
      goto switchD_000fdaf0_caseD_2;
    case 0x42:
      compilerArenaA = *(undefined4 *)(iVar43 + 0x374);
      puVar14 = (undefined4 *)Arena__alloc(compilerArenaA,0x168);
      *puVar14 = compilerArenaA;
      piVar18 = puVar14 + 1;
      IRInst__ctor_10502c(piVar18,0x94,*(undefined4 *)(program + 8));
      virtualRegister = FUN_00127608(*(undefined4 *)(program + 0x3ac),0x2f,0,0);
      IRInst__setOperandRef(piVar18,0,virtualRegister);
      puVar14[0x4c] = 0;
      ((int (*)())FUN_000f92fc)(program,piVar18,currentBlock);
      bVar1 = local_ac != 0;
      if (bVar1) {
        (**(code **)(*piVar18 + 0x90))(piVar18,virtualRegister);
      }
      pppppuVar15 = *ppppppuVar49;
      in_r6 = (uint ******)((uint)pppppuVar15 >> 0x17 & 0x3f);
      if (((unsigned char *)0x4) < in_r6) {
        in_r6 = (uint ******)0x0;
      }
      ppppuVar45 = *ilReader[0x1b];
      sVar6 = *(short *)((int)ppppuVar45 + 2);
      uVar50 = FUN_000ec208(program,(uint)*ppppuVar45 >> 0x10 & 0x3f);
      pppuVar42 = *ilReader[0x1b][1];
      if (((((uint)pppuVar42 & 0x3f0000) == 0x100000) && (*(int *)(program + 8) != 0)) &&
         ((*(uint *)(*(int *)(*(int *)(program + 8) + 0x30c) + 8) & 0x80) != 0)) {
        iVar34 = 0xf;
      }
      else {
        iVar34 = (int)*(short *)((int)ilReader[0x1b][1] + 2);
      }
      uVar27 = FUN_000ec208(program,(uint)pppuVar42 >> 0x10 & 0x3f);
      uVar41 = FUN_00127608(*(undefined4 *)(program + 0x3ac),0x2b,0,0);
      piVar18 = IRInst__create(0x14,*(undefined4 *)(program + 8));
      iVar43 = IRInst__getOperandRecord(piVar18,1);
      *(undefined4 *)(iVar43 + 0xc) = uVar50;
      *(int *)(iVar43 + 8) = (int)sVar6;
      local_178 = (uint ******)0x10203;
      ((int (*)())FUN_000f8aa0)(program,&local_178,ppppuVar45,1,piVar18);
      iVar43 = IRInst__getOperandRecord(piVar18,1);
      *(undefined4 *)(iVar43 + 0x10) = 0;
      ((void (*)())IRInst__makeLiteralVec4Float)(piVar18,program,2,0.0,1.0,0.0,0.0);
      local_8c = (uint)(short)((ushort)((uint)pppppuVar15 >> 0x10) & 0x3f);
      local_80 = local_8c | 0x120000;
      in_r8 = (uint ******)(local_8c | 0x100000);
      in_r7 = (uint ******)(local_8c | 0x110000);
      local_8c = local_8c | 0xf0000;
      local_88 = (uint *****)in_r8;
      local_84 = (uint *****)in_r7;
      ((int (*)())IRInst__makeLiteralVec4Int)(piVar18,program,3,local_80,in_r7,in_r8,local_8c);
      iVar43 = IRInst__getOperandRecord(piVar18,0);
      *(undefined4 *)(iVar43 + 0xc) = 0x2b;
      *(undefined4 *)(iVar43 + 8) = 0;
      ((int (*)())FUN_000f92fc)(program,piVar18,currentBlock);
      (**(code **)(*piVar18 + 0x90))(piVar18,virtualRegister);
      if (bVar1) {
        (**(code **)(*piVar18 + 0x90))(piVar18,uVar41);
      }
      IRInst__setHardwareRegisterAndAdd(piVar18,program,0x2b,0);
      piVar18[0x20] = 1;
      piVar18 = (int *)FUN_001084b8(0x31,*(undefined4 *)(program + 8));
      iVar43 = IRInst__getOperandRecord(piVar18,0);
      *(uint *******)(iVar43 + 8) = in_r6;
      *(undefined4 *)(iVar43 + 0xc) = 0x2c;
      iVar43 = IRInst__getOperandRecord(piVar18,1);
      *(undefined4 *)(iVar43 + 0xc) = uVar27;
      *(int *)(iVar43 + 8) = iVar34;
      (**(code **)(*piVar18 + 0x90))(piVar18,uVar41);
      ((int (*)())FUN_000f92fc)(program,piVar18,currentBlock);
      IRInst__setHardwareRegisterAndAdd(piVar18,program,0x2c,in_r6);
      local_ac = 1;
      goto switchD_000fdaf0_caseD_2;
    case 0x43:
      pppppuVar15 = *ppppppuVar49;
      in_r6 = (uint ******)*ilReader[0x19];
      in_r7 = (uint ******)0x4050607;
      if (((uint)*in_r6 & 0x400000) != 0) {
        in_r7 = *(uint *******)(local_5c + -0x2bf8);
        iVar34 = psnPackedLaneComponent(in_r6,0);
        if (*(int *)(PTR_DAT_001e8bc8 + iVar34 * 4) == 0) {
          in_r7 = (uint ******)((uint)in_r7 & 0xffffff | 0x4000000);
        }
        uVar10 = (uint)(*(int *)(PTR_DAT_001e8bc8 + iVar34 * 4) == 0);
        iVar34 = psnPackedLaneComponent(in_r6,1);
        puVar8 = PTR_DAT_001e8bc8;
        if (*(int *)(PTR_DAT_001e8bc8 + iVar34 * 4) == 0) {
          iVar34 = uVar10 + 4;
          uVar10 = uVar10 + 1;
          in_r7 = (uint ******)(iVar34 * 0x10000 | (uint)in_r7 & 0xff00ffff);
        }
        iVar34 = psnPackedLaneComponent(in_r6,2);
        if (*(int *)(puVar8 + iVar34 * 4) == 0) {
          iVar34 = uVar10 + 4;
          uVar10 = uVar10 + 1;
          in_r7 = (uint ******)(iVar34 * 0x100 | (uint)in_r7 & 0xffff00ff);
        }
        iVar34 = psnPackedLaneComponent(in_r6,3);
        if (*(int *)(puVar8 + iVar34 * 4) == 0) {
          iVar43 = *(int *)(program + 8);
          in_r7 = (uint ******)(uVar10 + 4 | (uint)in_r7 & 0xffffff00);
        }
        else {
          iVar43 = *(int *)(program + 8);
        }
      }
      in_r8 = (uint ******)currentBlock;
      (**(code **)(**(int **)(iVar43 + 0x30c) + 0x4c))
                (*(int **)(iVar43 + 0x30c),program,(uint)pppppuVar15 >> 0x10 & 0x3f);
      goto switchD_000fdaf0_caseD_2;
    case 0x6e:
      compilerArenaA = *(undefined4 *)(iVar43 + 0x374);
      pppppuVar15 = ilReader[(int)ilReader[0x16] + 0x23];
      puVar14 = (undefined4 *)Arena__alloc(compilerArenaA,0x134);
      *puVar14 = compilerArenaA;
      pppppuVar52 = (uint *****)(puVar14 + 1);
      Block__ctor_ea148(pppppuVar52,*(undefined4 *)(program + 8));
      puVar14[0x4c] = pppppuVar15;
      puVar14[1] = PTR_DAT_001e8bd0 + 8;
      currentBlock = pppppuVar52;
      FUN_000ec3ac(program,previousBlock,pppppuVar52);
      Block__connect(previousBlock,currentBlock);
      previousBlock = currentBlock;
      compilerArenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
      puVar14 = (undefined4 *)Arena__alloc(compilerArenaA,0x130);
      *puVar14 = compilerArenaA;
      ppppppuVar49 = (uint ******)(puVar14 + 1);
      Block__ctor_ea020(ppppppuVar49,*(undefined4 *)(program + 8));
      currentBlock = (uint *****)ppppppuVar49;
      FUN_000ec3ac(program,previousBlock,ppppppuVar49);
      Block__connect(previousBlock,currentBlock);
      previousBlock = currentBlock;
      goto switchD_000fdaf0_caseD_2;
    case 0x72:
      piVar18 = (int *)Arena__alloc(*(undefined4 *)(iVar43 + 0x378),0xc);
      piVar18[1] = 0;
      piVar18[2] = 0;
      ppppppuVar19 = IRInst__create(0x31,*(undefined4 *)(program + 8));
      iVar43 = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(program + 8) + 0x3ac) = iVar43;
      *piVar18 = iVar43;
      iVar34 = IRInst__getOperandRecord(ppppppuVar19,0);
      *(undefined4 *)(iVar34 + 0xc) = 0;
      *(int *)(iVar34 + 8) = iVar43;
      local_178 = (uint ******)0x10203;
      in_r8 = (uint ******)&local_174;
      ((int (*)())FUN_000fb3d4)(program,local_68,ppppppuVar49,*ilReader[0x1b],ppppppuVar37,in_r8,&local_13c);
      pppuVar42 = **ilReader[0x1b];
      if (((((uint)pppuVar42 & 0x3f0000) == 0x100000) && (*(int *)(program + 8) != 0)) &&
         ((*(uint *)(*(int *)(*(int *)(program + 8) + 0x30c) + 8) & 0x80) != 0)) {
        iVar34 = 0xf;
      }
      else {
        iVar34 = (int)*(short *)((int)*ilReader[0x1b] + 2);
      }
      registerFile = FUN_000ec208(program,(uint)pppuVar42 >> 0x10 & 0x3f);
      iVar43 = IRInst__getOperandRecord(ppppppuVar19,1);
      *(undefined4 *)(iVar43 + 0xc) = registerFile;
      *(int *)(iVar43 + 8) = iVar34;
      in_r6 = (uint ******)((int)((unsigned char *)0x0) + 1);
      in_r7 = ppppppuVar19;
      ((int (*)())FUN_000f8aa0)(program,&local_178,*ilReader[0x1b],1,ppppppuVar19);
      iVar43 = *(int *)(local_14c + 8);
      iVar34 = local_14c;
      while (iVar47 = iVar43, iVar47 != 0) {
        DList__unlink(iVar34);
        ((int (*)())FUN_000f92fc)(program,iVar34,currentBlock);
        iVar34 = iVar47;
        iVar43 = *(int *)(iVar47 + 8);
      }
      ((int (*)())FUN_000f92fc)(program,ppppppuVar19,currentBlock);
      uVar10 = conditionStack[1];
      if (uVar10 < *conditionStack) {
        _memset(uVar10 * 4 + conditionStack[2],0,4);
        conditionStack[1] = uVar10 + 1;
        piVar36 = (int *)(uVar10 * 4 + conditionStack[2]);
      }
      else {
        piVar36 = (int *)Vector__elementRefGrow(conditionStack,uVar10);
      }
      goto code_r0x000febe0;
    case 0x73:
      compilerArenaA = *(undefined4 *)(iVar43 + 0x374);
      puVar14 = (undefined4 *)Arena__alloc(compilerArenaA,0x168);
      *puVar14 = compilerArenaA;
      piVar18 = puVar14 + 1;
      IRInst__ctor_10502c(piVar18,0xf8,*(undefined4 *)(program + 8));
      puVar14[0x4c] = ilReader[(int)ilReader[0x16] + 0x23];
      ((int (*)())FUN_000f92fc)(program,piVar18,currentBlock);
      break;
    case 0x76:
    case 0x77:
      if ((iVar34 == 0x76) && ((int)*ppppppuVar49 < 0)) {
        pppppuVar52 = ilReader[10];
        in_r6 = (uint ******)0x0;
        pppppuVar15 = ilReader[(int)ilReader[0x16] + 0x23];
        virtualRegister = FUN_00127608(*(undefined4 *)(program + 0x3ac),0x43,0xffffffff,0);
        iVar34 = FUN_00109b74(0x10a,*(undefined4 *)(program + 8));
        *(int *)(program + 0x354) = iVar34;
        IRInst__setOperandRef(iVar34,0,virtualRegister);
        *(uint ******)(iVar34 + 300) = pppppuVar52 + (int)pppppuVar15;
        Block__appendInst(*(undefined4 *)(program + 0x3a0),iVar34);
      }
      else {
        iVar34 = 1;
        ppppuVar45 = *ilReader[0x1b];
        uVar44 = (uint)*(ushort *)((int)ppppuVar45 + 2);
        uVar10 = (uint)*ppppuVar45 >> 0x10 & 0x3f;
        if ((int)*ppppuVar45 < 0) {
          iVar34 = 2;
          uVar44 = uVar44 | (int)ppppuVar45[1] << 0x10;
        }
        pppuVar42 = ppppuVar45[iVar34];
        if (uVar10 == 0x1c) {
          puVar12 = *(uint **)(program + 0x90);
          if (puVar12 == (uint *)0x0) {
            compilerArenaA = *(undefined4 *)(iVar43 + 0x374);
            puVar14 = (undefined4 *)Arena__alloc(compilerArenaA,0x14);
            puVar12 = puVar14 + 1;
            *puVar14 = compilerArenaA;
            puVar14[1] = 2;
            puVar14[2] = 0;
            puVar14[4] = compilerArenaA;
            vectorStorage = Arena__alloc(compilerArenaA,8);
            puVar14[3] = vectorStorage;
            *(uint **)(program + 0x90) = puVar12;
          }
        }
        else {
          puVar12 = *(uint **)(program + 0x8c);
          if (puVar12 == (uint *)0x0) {
            compilerArenaA = *(undefined4 *)(iVar43 + 0x374);
            puVar14 = (undefined4 *)Arena__alloc(compilerArenaA,0x14);
            puVar12 = puVar14 + 1;
            *puVar14 = compilerArenaA;
            puVar14[1] = 2;
            puVar14[2] = 0;
            puVar14[4] = compilerArenaA;
            vectorStorage = Arena__alloc(compilerArenaA,8);
            puVar14[3] = vectorStorage;
            *(uint **)(program + 0x8c) = puVar12;
          }
        }
        if (uVar44 < *puVar12) {
          uVar17 = puVar12[1];
          if (uVar17 <= uVar44) {
            _memset(uVar17 * 4 + puVar12[2],0,(uVar44 - uVar17) * 4 + 4);
            puVar12[1] = uVar44 + 1;
          }
          puVar12 = (uint *)(uVar44 * 4 + puVar12[2]);
        }
        else {
          puVar12 = (uint *)Vector__elementRefGrow(puVar12,uVar44);
        }
        *puVar12 = (uint)pppuVar42;
        iVar34 = (uVar44 >> 3 & 0x1ffffffc) + *(int *)(program + 0x434);
        *(uint *)(iVar34 + 8) = 1 << (uVar44 & 0x1f) | *(uint *)(iVar34 + 8);
        if ((*(uint *)(*(int *)(*(int *)(program + 8) + 0x30c) + 8) & 8) != 0) {
          compilerArenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
          puVar14 = (undefined4 *)Arena__alloc(compilerArenaA,0x168);
          *puVar14 = compilerArenaA;
          puVar24 = puVar14 + 1;
          FUN_00109a80(puVar24,0xfa,*(undefined4 *)(program + 8));
          registerFile = FUN_000ec208(program,uVar10);
          iVar34 = IRInst__getOperandRecord(puVar24,0);
          *(undefined4 *)(iVar34 + 0xc) = registerFile;
          *(uint *)(iVar34 + 8) = uVar44;
          puVar14[0x4c] = pppuVar42;
          ((int (*)())FUN_000f92fc)(program,puVar24,*(undefined4 *)(program + 0x3a0));
        }
      }
      goto switchD_000fdaf0_caseD_2;
    case 0x78:
      *(uint *)(program + 0x400) = (uint)*ppppppuVar49 >> 0x10 & 0x3fff;
      goto switchD_000fdaf0_caseD_2;
    case 0x7a:
      *(uint *)(program + 0x3f8) = (uint)*ppppppuVar49 >> 0x10 & 0x3fff;
      goto switchD_000fdaf0_caseD_2;
    case 0x7c:
      *(uint *)(program + 0x3fc) = (uint)*ppppppuVar49 >> 0x10 & 0x3fff;
      goto switchD_000fdaf0_caseD_2;
    case 0x7d:
      ppppuVar45 = *ilReader[0x19];
      if ((*(uint *)(program + 0x30) & 0x4000) == 0) {
        if ((*(uint *)(program + 0x30) & 1) != 0) {
          local_178 = (uint ******)0x0;
          ppppppuVar19 = (uint ******)(int)*(short *)((int)ppppuVar45 + 2);
          registerFile = FUN_000ec208(program,(uint)*ppppuVar45 >> 0x10 & 0x3f);
          iVar34 = FUN_000ec27c(program,(uint)*ppppppuVar49 >> 0x10 & 0x3fff);
          if (iVar34 == 0) {
            *(uint *******)(*(int *)(program + 0x3ac) + 0x44) = ppppppuVar19;
          }
          else if (iVar34 == 1) {
            *(uint *******)(*(int *)(program + 0x3ac) + 0x48) = ppppppuVar19;
          }
          ppppppuVar49 = *(uint *******)(program + 1000);
          if ((int)ppppppuVar19 <= (int)*(uint *******)(program + 1000)) {
            ppppppuVar49 = ppppppuVar19;
          }
          puVar53 = *(undefined1 **)(program + 0x3ec);
          *(uint *******)(program + 1000) = ppppppuVar49;
          if ((int)puVar53 <= (int)ppppppuVar19) {
            puVar53 = (undefined1 *)((int)ppppppuVar19 + 1);
          }
          *(undefined1 **)(program + 0x3ec) = puVar53;
          *(undefined4 *)(program + 0x3f4) = 0x24;
          if (iVar34 == 0xd) {
            iVar43 = *(int *)(program + 0x3ac);
            if (*(int *)(iVar43 + 0x4c) == -1) {
              *(uint *******)(iVar43 + 0x4c) = ppppppuVar19;
            }
            else {
              *(uint *******)(iVar43 + 0x54) = ppppppuVar19;
            }
          }
          else if (iVar34 == 0xe) {
            iVar43 = *(int *)(program + 0x3ac);
            if (*(int *)(iVar43 + 0x50) == -1) {
              *(uint *******)(iVar43 + 0x50) = ppppppuVar19;
            }
            else {
              *(uint *******)(iVar43 + 0x58) = ppppppuVar19;
            }
          }
          else if (iVar34 == 0xb) {
            *(uint *******)(*(int *)(program + 0x3ac) + 0x5c) = ppppppuVar19;
          }
          else if (iVar34 == 0xc) {
            *(uint *******)(*(int *)(program + 0x3ac) + 0x60) = ppppppuVar19;
          }
          else if (iVar34 == 0xf) {
            *(uint *******)(*(int *)(program + 0x3ac) + 100) = ppppppuVar19;
          }
          in_r6 = (uint ******)0x0;
          piVar18 = (int *)FUN_00127608(*(undefined4 *)(program + 0x3ac),registerFile,ppppppuVar19,0);
          iVar43 = (**(code **)(*piVar18 + 0x2c))();
          local_70 = &local_178;
          *(uint *******)(iVar43 + 0x140) = ppppppuVar19;
          iVar47 = 0;
          do {
            if (*(char *)(iVar47 + (int)local_70) == '\0') {
              in_r6 = ppppppuVar19;
              FUN_00104104(iVar43,iVar47,iVar34,ppppppuVar19);
            }
            bVar1 = iVar47 != 3;
            iVar47 = iVar47 + 1;
          } while (bVar1);
        }
      }
      else {
        in_r7 = (uint ******)0x10203;
        in_r6 = (uint ******)(uint)*(ushort *)((int)ppppuVar45 + 2);
        in_r8 = (uint ******)0x0;
        (**(code **)(*piVar18 + 0x54))(piVar18,in_r6,(uint)*ppppppuVar49 >> 0x10 & 0x3fff);
      }
      goto switchD_000fdaf0_caseD_2;
    case 0x7e:
      uVar44 = (uint)*ppppppuVar49 >> 0xe & 0x1f;
      ppppppuVar19 = (uint ******)FUN_000ec27c(program,uVar44);
      uVar10 = (uint)*ppppppuVar49 >> 0x13 & 7;
      if (uVar10 == 3) {
        bVar1 = true;
        bVar3 = false;
        bVar2 = false;
      }
      else if (uVar10 < 4) {
        if (uVar10 == 1) {
          bVar1 = false;
          bVar3 = false;
          bVar2 = true;
        }
        else {
code_r0x000feeb8:
          bVar1 = false;
          bVar3 = false;
          bVar2 = false;
        }
      }
      else if (uVar10 == 4) {
        bVar1 = false;
        bVar3 = true;
        bVar2 = false;
      }
      else {
        if (uVar10 != 5) goto code_r0x000feeb8;
        bVar1 = true;
        bVar3 = true;
        bVar2 = false;
      }
      ppppppuVar49 = (uint ******)*ilReader[0x19];
      pppppuVar15 = *ppppppuVar49;
      if (((uint)pppppuVar15 & 0x400000) == 0) {
        if (((uint)pppppuVar15 & 0x2000000) == 0) {
          ppppppuVar40 = (uint ******)0x0;
          ppppppuVar38 = (uint ******)0x0;
        }
        else {
          ppppppuVar40 = ppppppuVar49 + 1;
          ppppppuVar38 = (uint ******)0x0;
        }
      }
      else {
        ppppppuVar38 = ppppppuVar49 + 1;
        ppppppuVar40 = (uint ******)0x0;
        if (((uint)pppppuVar15 & 0x2000000) != 0) {
          ppppppuVar40 = ppppppuVar49 + 2;
        }
      }
      if (((*(uint *)(program + 0x30) & 1) == 0) && ((*(uint *)(program + 0x30) & 0x2000) == 0)) {
        if (uVar44 == 10) {
          local_174 = (uint ****)(uint)*(ushort *)((int)ppppppuVar40 + 2);
          local_178 = (uint ******)0x10101;
          puVar12 = &local_178;
          if (((uint)*ppppppuVar38 & 3) == 1) {
            puVar12 = &DAT_001aa9d0;
          }
          puVar35 = &local_178;
          local_178 = (uint ******)*puVar12;
          if (((uint)*ppppppuVar38 & 0xc) == 4) {
            puVar35 = &UNK_001aa9c4;
          }
          puVar12 = &local_178;
          local_178 = (uint ******)*puVar35;
          if (((uint)*ppppppuVar38 & 0x30) == 0x10) {
            puVar12 = &UNK_001aa9c0;
          }
          puVar35 = &local_178;
          local_178 = (uint ******)*puVar12;
          if (((uint)*ppppppuVar38 & 0xc0) == 0x40) {
            puVar35 = &UNK_001aa9bc;
          }
          local_178 = (uint ******)*puVar35;
          local_170 = (uint *****)local_178;
        }
      }
      else {
        uVar10 = (uint)pppppuVar15 >> 0x10 & 0x3f;
        ppppppuVar48 = (uint ******)(uint)*(ushort *)((int)ppppppuVar49 + 2);
        registerFile = FUN_000ec208(program,uVar10);
        puVar12 = local_13c;
        ppppppuVar38 = *(uint *******)(program + 1000);
        if ((int)ppppppuVar48 <= (int)*(uint *******)(program + 1000)) {
          ppppppuVar38 = ppppppuVar48;
        }
        puVar53 = *(undefined1 **)(program + 0x3ec);
        *(uint *******)(program + 1000) = ppppppuVar38;
        if ((int)puVar53 <= (int)ppppppuVar48) {
          puVar53 = (undefined1 *)((int)ppppppuVar48 + 1);
        }
        *(undefined1 **)(program + 0x3ec) = puVar53;
        *(undefined4 *)(program + 0x3f4) = 0x24;
        in_r7 = (uint ******)0x4050607;
        if ((*(uint *)(program + 0x30) & 1) == 0) {
          iVar34 = FUN_00127608(*(undefined4 *)(program + 0x3ac),registerFile,ppppppuVar48,0);
          iVar34 = *(int *)(iVar34 + 0x38);
          if (!bVar1) {
            *(uint *)(iVar34 + 0x13c) = *(uint *)(iVar34 + 0x13c) | 1;
          }
          if (bVar3) {
            *(uint *)(iVar34 + 0x13c) = *(uint *)(iVar34 + 0x13c) | 4;
          }
          if (bVar2) {
            *(uint *)(iVar34 + 0x13c) = *(uint *)(iVar34 + 0x13c) | 2;
          }
          iVar43 = 0;
          do {
            in_r6 = ppppppuVar19;
            in_r7 = ppppppuVar48;
            FUN_001041d0(iVar34,iVar43,1,ppppppuVar19,ppppppuVar48);
            bVar1 = iVar43 != 3;
            iVar43 = iVar43 + 1;
          } while (bVar1);
        }
        else if ((*(uint *)(program + 0x30) & 0x40000) == 0) {
          in_r8 = *(uint *******)(program + 0x3a0);
          piVar18 = *(int **)(*(int *)(program + 8) + 0x30c);
          (**(code **)(*piVar18 + 0x4c))(piVar18,program,ppppppuVar48);
          in_r6 = ppppppuVar49;
        }
        else if (uVar10 != 9) {
          uVar10 = (uint)*(ushort *)((int)ppppppuVar40 + 2);
          if (uVar10 < *local_13c) {
            uVar44 = local_13c[1];
            if (uVar44 <= uVar10) {
              _memset(uVar44 * 4 + local_13c[2],0,(uVar10 - uVar44) * 4 + 4);
              puVar12[1] = uVar10 + 1;
            }
            puVar14 = (undefined4 *)(uVar10 * 4 + puVar12[2]);
          }
          else {
            puVar14 = (undefined4 *)Vector__elementRefGrow(local_13c,uVar10);
          }
          ppppppuVar49 = (uint ******)*puVar14;
          in_r6 = (uint ******)0x0;
          iVar34 = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
          *(int *)(*(int *)(program + 8) + 0x3ac) = iVar34;
          virtualRegister = FUN_00127608(*(undefined4 *)(program + 0x3ac),0,iVar34,0);
          IRInst__setOperandRef(ppppppuVar49,0,virtualRegister);
          goto code_r0x000ff070;
        }
      }
      goto switchD_000fdaf0_caseD_2;
    case 0x80:
      bVar4 = *(byte *)((int)ilReader + 0x8d);
      uVar10 = (uint)*ppppppuVar49 >> 0x18 & 0xf;
      if (piVar18[0x14] < (int)(uint)bVar4) {
        Compiler__fail(iVar43,7);
      }
      uVar44 = bVar4 >> 3 & 0x1c;
      iVar34 = (uint)bVar4 * 0xc;
      *(uint *)((int)local_a0 + uVar44 + 8) =
           1 << (bVar4 & 0x1f) | *(uint *)((int)local_a0 + uVar44 + 8);
      *(undefined4 *)(*(int *)(program + 0x78) + iVar34) = 1;
      if (uVar10 != 0) {
        *(uint *)(iVar34 + *(int *)(program + 0x78) + 4) = uVar10;
      }
      goto switchD_000fdaf0_caseD_2;
    case 0x81:
    case 0x84:
    case 0x85:
      local_a4 = (uint *****)((int)local_a4 + 1);
      if ((*(uint *)(program + 0x30) & 0x40000) == 0) {
        if (puVar13[2] != 0) {
          *(uint *)(program + 0x30) = *(uint *)(program + 0x30) | 0x180000;
        }
        if ((uint *****)ifStack[1] != (uint *****)0x0) {
          *(uint *)(program + 0x30) = *(uint *)(program + 0x30) | 0x80000;
        }
        pvVar16 = IRInst__create(*(undefined4 *)
                                (iVar34 * 0x24 + *(int *)(*(int *)(iVar43 + 0x30c) + 0xc)),iVar43);
        iVar34 = IRInst__getOperandRecord(pvVar16,0);
        *(undefined4 *)(iVar34 + 0xc) = 0x2c;
        *(undefined4 *)(iVar34 + 8) = 0;
        *(undefined4 *)((int)pvVar16 + 0x9c) = 0x10101;
        iVar34 = IRInst__getOperandRecord(pvVar16,1);
        *(undefined4 *)(iVar34 + 0xc) = 0x2c;
        *(undefined4 *)(iVar34 + 8) = 0;
        iVar34 = IRInst__getOperandRecord(pvVar16,1);
        *(undefined4 *)(iVar34 + 0x10) = 0;
        ((int (*)())FUN_000f92fc)(program,pvVar16,currentBlock);
      }
      goto switchD_000fdaf0_caseD_2;
    case 0x87:
      uVar10 = (uint)*(byte *)((int)ilReader + 0x8d);
      pppppuVar15 = *ppppppuVar49;
      if (*(int *)(program + 0x7c) < (int)uVar10) {
        *(uint *)(program + 0x7c) = uVar10;
      }
      *(uint *)(program + 0x84) = 1 << (uVar10 & 0x3f) | *(uint *)(program + 0x84);
      local_178 = (uint ******)0x10203;
      registerMap = *(undefined4 *)(program + 0x3ac);
      iVar34 = *(int *)(iVar43 + 0x3ac) + -1;
      *(int *)(iVar43 + 0x3ac) = iVar34;
      virtualRegister = FUN_00127608(registerMap,0,iVar34,0);
      uVar50 = *(undefined4 *)(program + 0x3ac);
      iVar34 = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(program + 8) + 0x3ac) = iVar34;
      uVar50 = FUN_00127608(uVar50,0,iVar34,0);
      pvVar16 = IRInst__create(0x31,*(undefined4 *)(program + 8));
      IRInst__setOperandRef(pvVar16,0,uVar50);
      local_70 = &local_178;
      ((int (*)())FUN_000fa958)(program,5,1,ilReader,pvVar16,1,0,local_70,ppppppuVar37,1,currentBlock);
      ((int (*)())FUN_000f92fc)(program,pvVar16,currentBlock);
      pvVar16 = IRInst__create(0x109,*(undefined4 *)(program + 8));
      *(uint *)((int)pvVar16 + 0x134) = uVar10;
      IRInst__setOperandRef(pvVar16,0,virtualRegister);
      IRInst__setOperandRef(pvVar16,1,uVar50);
      ((int (*)())FUN_000f92fc)(program,pvVar16,currentBlock);
      puVar9 = PTR_DAT_001e8b8c;
      puVar8 = PTR_DAT_001e8b64;
      local_178 = (uint ******)0x10203;
      if (((uint)pppppuVar15 & 0x1f000000) != 0x1000000) {
        iVar34 = 0;
        do {
          pvVar16 = IRInst__create(0xe1,*(undefined4 *)(program + 8));
          IRInst__setOperandRef(pvVar16,0,virtualRegister);
          IRInst__setOperandRef(pvVar16,1,virtualRegister);
          uVar50 = *(undefined4 *)(puVar9 + iVar34);
          *(undefined4 *)((int)pvVar16 + 0x9c) = *(undefined4 *)(puVar8 + iVar34);
          iVar43 = IRInst__getOperandRecord(pvVar16,1);
          *(undefined4 *)(iVar43 + 0x10) = uVar50;
          ((int (*)())FUN_000f92fc)(program,pvVar16,currentBlock);
          bVar1 = iVar34 != 0xc;
          iVar34 = iVar34 + 4;
        } while (bVar1);
      }
      ppppppuVar49 = IRInst__create(0x31,*(undefined4 *)(program + 8));
      in_r8 = (uint ******)((int)((unsigned char *)0x0) + 1);
      in_r6 = ilReader;
      in_r7 = ppppppuVar49;
      ((int (*)())FUN_000fa958)(program,0,0,ilReader,ppppppuVar49,1,0,local_70,ppppppuVar37,1,currentBlock);
      IRInst__setOperandRef(ppppppuVar49,1,virtualRegister);
code_r0x000ff070:
      ((int (*)())FUN_000f92fc)(program,ppppppuVar49,currentBlock);
      goto switchD_000fdaf0_caseD_2;
    case 0xbe:
      compilerArenaA = *(undefined4 *)(iVar43 + 0x374);
      puVar14 = (undefined4 *)Arena__alloc(compilerArenaA,0x168);
      *puVar14 = compilerArenaA;
      ppppppuVar19 = (uint ******)(puVar14 + 1);
      IRInst__ctor_10502c(ppppppuVar19,0xb4,*(undefined4 *)(program + 8));
      if (((uint)*ppppppuVar49 & 0x3fff0000) != 0) {
        puVar14[0x4c] = 1;
      }
      in_r8 = (uint ******)&local_174;
      ((int (*)())FUN_000fb3d4)(program,local_68,ppppppuVar49,*ilReader[0x1b],ppppppuVar37,in_r8,&local_13c);
      pppuVar42 = **ilReader[0x1b];
      if (((((uint)pppuVar42 & 0x3f0000) == 0x100000) && (*(int *)(program + 8) != 0)) &&
         ((*(uint *)(*(int *)(*(int *)(program + 8) + 0x30c) + 8) & 0x80) != 0)) {
        iVar34 = 0xf;
      }
      else {
        iVar34 = (int)*(short *)((int)*ilReader[0x1b] + 2);
      }
      uVar10 = (uint)pppuVar42 >> 0x10 & 0x3f;
      iVar43 = FUN_00127534(*(undefined4 *)(program + 0x3ac),0x2c,0,0);
      if (iVar43 == 0) {
        compilerArenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
        puVar14 = (undefined4 *)Arena__alloc(compilerArenaA,0x168);
        *puVar14 = compilerArenaA;
        puVar24 = puVar14 + 1;
        IRExport__ctor_108918(puVar24,*(undefined4 *)(program + 8));
        puVar14[6] = puVar14[6] | 0x10000;
        *(undefined4 **)(program + 0x350) = puVar24;
        puVar14[0x28] = 0;
        iVar43 = FUN_001275a0(*(undefined4 *)(program + 0x3ac),0x2c,0,0);
        IRInst__setOperandRef(puVar24,0,iVar43);
        IRInst__setOperandRef(puVar24,1,iVar43);
        iVar47 = IRInst__getOperandRecord(puVar24,1);
        *(undefined4 *)(iVar47 + 0x10) = 0x10203;
        Block__appendInst(*(undefined4 *)(program + 0x3a8),puVar24);
        FUN_0012306c(iVar43,puVar24);
        VReg__addUse(iVar43,1,puVar24);
      }
      IRInst__setOperandRef(ppppppuVar19,0,iVar43);
      registerFile = FUN_000ec208(program,uVar10);
      iVar43 = IRInst__getOperandRecord(ppppppuVar19,1);
      *(undefined4 *)(iVar43 + 0xc) = registerFile;
      *(int *)(iVar43 + 8) = iVar34;
      registerFile = FUN_000ec208(program,uVar10);
      iVar43 = IRInst__getOperandRecord(ppppppuVar19,2);
      *(undefined4 *)(iVar43 + 0xc) = registerFile;
      *(int *)(iVar43 + 8) = iVar34;
      registerFile = FUN_000ec208(program,uVar10);
      iVar43 = IRInst__getOperandRecord(ppppppuVar19,3);
      *(undefined4 *)(iVar43 + 0xc) = registerFile;
      local_70 = &local_178;
      *(int *)(iVar43 + 8) = iVar34;
      local_178 = (uint ******)0x10101;
      ((int (*)())FUN_000f8aa0)(program,local_70,*ilReader[0x1b],1,ppppppuVar19);
      local_178 = (uint ******)0x2020202;
      ((int (*)())FUN_000f8aa0)(program,local_70,*ilReader[0x1b],2,ppppppuVar19);
      in_r6 = (uint ******)((int)((unsigned char *)0x0) + 3);
      local_178 = (uint ******)0x3030303;
      in_r7 = ppppppuVar19;
      ((int (*)())FUN_000f8aa0)(program,local_70,*ilReader[0x1b],3,ppppppuVar19);
      iVar43 = *(int *)(local_14c + 8);
      iVar34 = local_14c;
      while (iVar47 = iVar43, iVar47 != 0) {
        DList__unlink(iVar34);
        ((int (*)())FUN_000f92fc)(program,iVar34,currentBlock);
        iVar34 = iVar47;
        iVar43 = *(int *)(iVar47 + 8);
      }
      ((int (*)())FUN_000f92fc)(program,ppppppuVar19,currentBlock);
      goto switchD_000fdaf0_caseD_2;
    case 0xe3:
      compilerArenaA = *(undefined4 *)(iVar43 + 0x374);
      puVar14 = (undefined4 *)Arena__alloc(compilerArenaA,0x168);
      *puVar14 = compilerArenaA;
      piVar18 = puVar14 + 1;
      IRInst__ctor_10502c(piVar18,0x106,*(undefined4 *)(program + 8));
      ((int (*)())FUN_000f92fc)(program,piVar18,currentBlock);
    }
    puVar12 = *(uint **)(program + 0x414);
    uVar10 = puVar12[1];
    if (uVar10 < *puVar12) {
      _memset(uVar10 * 4 + puVar12[2],0,4);
      piVar36 = (int *)(uVar10 * 4 + puVar12[2]);
      puVar12[1] = uVar10 + 1;
    }
    else {
      piVar36 = (int *)Vector__elementRefGrow(puVar12,uVar10);
    }
code_r0x000febe0:
    *piVar36 = (int)piVar18;
    goto switchD_000fdaf0_caseD_2;
  default:
    goto switchD_000fdaf0_caseD_2;
  case 4:
    bVar1 = false;
    break;
  case 5:
    local_78 = &DAT_001ad5d8;
    local_60 = &DAT_001ad5d8;
    iVar47 = *(int *)(iVar34 * 0x24 + iVar47 + 0x18);
    local_124 = (uint *****)0x0;
    local_178 = (uint ******)0x10203;
    compilerArenaB = *(undefined4 *)(iVar43 + 0x378);
    puVar14 = (undefined4 *)Arena__alloc(compilerArenaB,0x14);
    puVar12 = puVar14 + 1;
    *puVar14 = compilerArenaB;
    puVar14[1] = 2;
    puVar14[2] = 0;
    puVar14[4] = compilerArenaB;
    vectorStorage = Arena__alloc(compilerArenaB,8);
    puVar14[3] = vectorStorage;
    compilerArenaB = *(undefined4 *)(*(int *)(program + 8) + 0x378);
    puVar24 = (undefined4 *)Arena__alloc(compilerArenaB,0x14);
    ppppppuVar19 = (uint ******)(puVar24 + 1);
    *puVar24 = compilerArenaB;
    puVar24[1] = 2;
    puVar24[2] = 0;
    puVar24[4] = compilerArenaB;
    vectorStorage = Arena__alloc(compilerArenaB,8);
    puVar24[3] = vectorStorage;
    local_17c = (int *)0x0;
    _memcpy(&local_104,&UNK_001aaa2c,0x24);
    iVar20 = *(int *)(program + 8);
    ppppppuVar38 = (uint ******)0x0;
    opcodeRecordTable = *(undefined4 *)(*(int *)(iVar20 + 0x30c) + 0xc);
    local_c0 = (uint *****)((int (*)())FUN_000f8960)(iVar34,opcodeRecordTable);
    iVar43 = ((int (*)())FUN_000f8970)(iVar34,opcodeRecordTable);
    if (0 < (int)local_c0) {
      do {
        iVar21 = (int)ppppppuVar38 << 2;
        for (iVar22 = 0;
            iVar23 = ((int (*)())FUN_000f8980)(iVar34,ppppppuVar38,
                                  *(undefined4 *)(*(int *)(iVar20 + 0x30c) + 0xc)), iVar22 <= iVar23
            ; iVar22 = iVar22 + 1) {
          in_r6 = ppppppuVar37;
          in_r7 = (uint ******)local_a4;
          ((int (*)())FUN_000f9a58)(program,local_6c,*(undefined4 *)((int)ilReader[0x19] + iVar21),ppppppuVar37,
                       local_a4);
          iVar20 = *(int *)(program + 8);
          iVar21 = iVar21 + 0x14;
        }
        ppppppuVar38 = (uint ******)((int)ppppppuVar38 + 1);
      } while ((uint ******)local_c0 != ppppppuVar38);
    }
    iVar21 = 0;
    if (0 < iVar43) {
      do {
        iVar22 = iVar21 << 2;
        puVar53 = (undefined1 *)((int)local_c0 + iVar21);
        for (iVar23 = 0;
            iVar25 = ((int (*)())FUN_000f8980)(iVar34,puVar53,*(undefined4 *)(*(int *)(iVar20 + 0x30c) + 0xc)),
            iVar23 <= iVar25; iVar23 = iVar23 + 1) {
          in_r6 = *(uint *******)((int)ilReader[0x1b] + iVar22);
          in_r8 = (uint ******)&local_174;
          in_r7 = ppppppuVar37;
          ((int (*)())FUN_000fb3d4)(program,local_68,ppppppuVar49,in_r6,ppppppuVar37,in_r8,&local_13c);
          iVar20 = *(int *)(program + 8);
          iVar22 = iVar22 + 0x14;
        }
        iVar21 = iVar21 + 1;
      } while (iVar43 != iVar21);
    }
    iVar20 = *(int *)(local_14c + 8);
    iVar43 = local_14c;
    while (iVar21 = iVar20, iVar21 != 0) {
      DList__unlink(iVar43);
      ((int (*)())FUN_000f92fc)(program,iVar43,currentBlock);
      iVar43 = iVar21;
      iVar20 = *(int *)(iVar21 + 8);
    }
    local_b4 = 0;
    ppppppuVar38 = (uint ******)0x0;
    ppppppuVar40 = (uint ******)0x0;
code_r0x001005f4:
    ppppppuVar39 = (uint ******)currentBlock;
    ppppppuVar48 = (uint ******)PTR_DAT_001e8bd4;
    uVar10 = *(uint *)(iVar47 + (int)local_17c * 4);
    if (0x71 < uVar10) goto switchD_0010061c_caseD_0;
    switch(uVar10) {
    default:
      goto switchD_0010061c_caseD_0;
    case 1:
    case 0x13:
    case 0x33:
    case 0x39:
    case 0x3b:
    case 0x3c:
    case 0x3e:
    case 0x40:
    case 0x4c:
    case 0x5e:
      goto switchD_0010061c_caseD_1;
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 0xb:
    case 0xc:
    case 0xd:
    case 0xe:
    case 0xf:
    case 0x10:
    case 0x11:
      in_r6 = ilReader;
      in_r7 = ppppppuVar38;
      in_r8 = (uint ******)local_c0;
      iVar43 = ((int (*)())FUN_000fa958)(program,uVar10 - 2,ppppppuVar40,ilReader,ppppppuVar38,local_c0,local_124,
                            &local_178,ppppppuVar37,local_b4,currentBlock);
      if (iVar43 != 0) {
        DList__pushFront(local_6c,iVar43);
      }
      goto code_r0x001025c0;
    case 0x12:
      IROperand__setModifierBits(ppppppuVar38 + (int)ppppppuVar40 * 6 + 0x23,2,1);
      goto code_r0x00101d1c;
    case 0x14:
    case 0x15:
    case 0x16:
      uVar44 = (uint)*ppppppuVar49 >> 0x10 & 0x3fff;
      if (uVar10 == 0x14) {
        in_r7 = (uint ******)(PTR_DAT_001dc78c)[uVar44];
      }
      else if (uVar10 == 0x15) {
        in_r7 = (uint ******)(PTR_DAT_001dc77c)[uVar44];
      }
      else {
        in_r7 = (uint ******)(PTR_DAT_001dc76c)[uVar44];
      }
      goto code_r0x001022b4;
    case 0x17:
      iVar43 = FUN_000e47f4(ilReader);
      if ((iVar43 == 0x3e) || (iVar43 = FUN_000e47f4(ilReader), iVar43 == 0x71)) {
        uVar10 = puVar13[2];
        if (uVar10 != 0) {
          piVar18 = (int *)0x0;
          if (uVar10 - 1 < uVar10) {
            piVar18 = (int *)((uVar10 - 1) * 4 + puVar13[3]);
          }
          iVar43 = *piVar18;
          pppppuVar15 = (uint *****)ifStack[1];
          ppppppuVar48 = (uint ******)PTR_DAT_001e8bbc;
          if (pppppuVar15 != (uint *****)0x0) {
            pppppuVar52 = (uint *****)0x0;
            if ((uint *****)((int)pppppuVar15 - 1U) < pppppuVar15) {
              pppppuVar52 = (uint *****)(ifStack[2] + (int)((int)pppppuVar15 - 1U));
            }
            if ((int)local_188 <= (int)(*pppppuVar52)[0x2e]) {
              breakTargetBlock = *(undefined4 *)(iVar43 + 0x154);
              uVar50 = *(undefined4 *)(*(int *)(program + 8) + 0x374);
              puVar32 = (undefined4 *)Arena__alloc(uVar50,0x138);
              *puVar32 = uVar50;
              ppppppuVar48 = (uint ******)(puVar32 + 1);
              in_r6 = *(uint *******)(program + 8);
              BreakBlock__ctor_ec0c8(ppppppuVar48,iVar43,*(undefined4 *)(iVar43 + 300),in_r6);
              puVar32[0x2f] = local_188;
              FUN_000ec3ac(program,previousBlock,ppppppuVar48);
              Block__connect(previousBlock,ppppppuVar48);
              Block__connect(ppppppuVar48,breakTargetBlock);
              local_bc = 0;
              *(int *)(iVar43 + 0x138) = *(int *)(iVar43 + 0x138) + 1;
              previousBlock = (uint *****)ppppppuVar48;
              break;
            }
          }
          goto code_r0x00103718;
        }
      }
      else {
        iVar43 = FUN_000e47f4(ilReader);
        ppppppuVar48 = (uint ******)PTR_DAT_001e8bb4;
        if (iVar43 == 0x72) {
          piVar18 = (int *)0x0;
          uVar10 = conditionStack[1] - 1;
          if (uVar10 < conditionStack[1]) {
            piVar18 = (int *)(uVar10 * 4 + conditionStack[2]);
          }
          *(int *)(*piVar18 + 4) = *(int *)(*piVar18 + 4) + 1;
code_r0x00103718:
          in_r6 = (uint ******)0x0;
          in_r8 = ppppppuVar19;
          iVar47 = ((int (*)())FUN_000fd50c)(program,iVar47,&local_17c,0,ppppppuVar48,ppppppuVar19);
          in_r7 = ppppppuVar48;
          goto code_r0x0010372c;
        }
      }
      goto switchD_0010061c_caseD_1;
    case 0x1f:
      local_17c = (int *)((int)local_17c + 1);
      uVar10 = *(uint *)(iVar47 + (int)local_17c * 4);
      local_178 = (uint ******)
                  (uVar10 << 0x18 | (uVar10 & 0xff00) << 8 | uVar10 >> 8 & 0xff00 | uVar10 >> 0x18);
      local_bc = 0;
      break;
    case 0x20:
      local_17c = (int *)((int)local_17c + 1);
      uVar10 = *(uint *)(iVar47 + (int)local_17c * 4);
      in_r7 = (uint ******)&local_124;
      local_124 = (uint *****)
                  (uVar10 << 0x18 | (uVar10 & 0xff00) << 8 | uVar10 >> 8 & 0xff00 | uVar10 >> 0x18);
      local_bc = 0;
      break;
    case 0x21:
      ppppppuVar48 = (uint ******)0x0;
      switch((uint)*ppppppuVar49 >> 0x10 & 7) {
      case 0:
        ppppppuVar48 = (uint ******)PTR_DAT_001e8b80;
        break;
      case 1:
        ppppppuVar48 = (uint ******)PTR_DAT_001e8bac;
        break;
      case 2:
        ppppppuVar48 = (uint ******)PTR_DAT_001e8ba8;
        break;
      case 3:
        ppppppuVar48 = (uint ******)PTR_DAT_001e8bcc;
        break;
      case 4:
        ppppppuVar48 = (uint ******)PTR_DAT_001e8b94;
        break;
      case 5:
        ppppppuVar48 = (uint ******)PTR_DAT_001e8b74;
      }
      goto switchD_00102044_default;
    case 0x22:
      uVar10 = (uint)*ppppppuVar49 >> 0x16 & 7;
      if (uVar10 == 0) goto switchD_0010061c_caseD_1;
      ppppppuVar48 = IRInst__create(0x12,*(undefined4 *)(program + 8));
      if (local_100 == 0) {
        local_100 = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
        *(int *)(*(int *)(program + 8) + 0x3ac) = local_100;
      }
      iVar43 = local_100;
      iVar20 = IRInst__getOperandRecord(ppppppuVar48,0);
      *(int *)(iVar20 + 8) = iVar43;
      *(undefined4 *)(iVar20 + 0xc) = 0;
      pppuVar42 = **ilReader[0x1b];
      if (((((uint)pppuVar42 & 0x3f0000) == 0x100000) && (*(int *)(program + 8) != 0)) &&
         ((*(uint *)(*(int *)(*(int *)(program + 8) + 0x30c) + 8) & 0x80) != 0)) {
        iVar20 = 0xf;
      }
      else {
        iVar20 = (int)*(short *)((int)*ilReader[0x1b] + 2);
      }
      registerFile = FUN_000ec208(program,(uint)pppuVar42 >> 0x10 & 0x3f);
      iVar21 = IRInst__getOperandRecord(ppppppuVar48,1);
      *(undefined4 *)(iVar21 + 0xc) = registerFile;
      *(int *)(iVar21 + 8) = iVar20;
      in_r6 = ppppppuVar40;
      in_r7 = ppppppuVar48;
      ((int (*)())FUN_000f8aa0)(program,&local_178,*ilReader[0x1b],ppppppuVar40,ppppppuVar48);
      if (uVar10 == 2) {
        fVar5 = 1.0;
code_r0x001021c0:
        dVar54 = (double)fVar5;
        ((void (*)())IRInst__makeLiteralVec4Float)(ppppppuVar48,program,2,dVar54,dVar54,dVar54,dVar54);
        IROperand__setModifierBits(ppppppuVar48 + 0x2f,1,1);
      }
      else if (uVar10 < 3) {
        if (uVar10 == 1) {
          fVar5 = 0.5;
          goto code_r0x001021c0;
        }
      }
      else {
        if (uVar10 == 3) {
          fVar5 = 0.5;
        }
        else {
          if (uVar10 != 4) goto code_r0x00102220;
          fVar5 = 1.0;
        }
        dVar54 = (double)fVar5;
        ((void (*)())IRInst__makeLiteralVec4Float)(ppppppuVar48,program,2,dVar54,dVar54,dVar54,dVar54);
      }
code_r0x00102220:
      ((int (*)())FUN_000f92fc)(program,ppppppuVar48,currentBlock);
      iVar20 = IRInst__getOperandRecord(ppppppuVar38,ppppppuVar40);
      *(int *)(iVar20 + 8) = iVar43;
      *(undefined4 *)(iVar20 + 0xc) = 0;
      ppppppuVar40 = (uint ******)((int)ppppppuVar40 + 1);
      local_bc = 0;
      local_17c = (int *)((int)local_17c + 1);
      break;
    case 0x23:
      ppppppuVar48 = (uint ******)0x0;
      switch((uint)*ppppppuVar49 >> 0x10 & 7) {
      case 0:
        ppppppuVar48 = (uint ******)PTR_DAT_001e8bc0;
        break;
      case 1:
        ppppppuVar48 = (uint ******)PTR_DAT_001e8b7c;
        break;
      case 2:
        ppppppuVar48 = (uint ******)PTR_DAT_001e8ba4;
        break;
      case 3:
        ppppppuVar48 = (uint ******)PTR_DAT_001e8b90;
        break;
      case 4:
        ppppppuVar48 = (uint ******)PTR_DAT_001e8bc4;
        break;
      case 5:
        ppppppuVar48 = (uint ******)PTR_DAT_001e8ba0;
      }
      goto switchD_00102044_default;
    case 0x24:
      if (puVar13[2] != 0) {
        pppppuVar15 = (uint *****)ifStack[1];
        ppppppuVar48 = (uint ******)PTR_DAT_001e8b78;
        if (pppppuVar15 != (uint *****)0x0) {
          pppppuVar52 = (uint *****)0x0;
          if ((uint *****)((int)pppppuVar15 - 1U) < pppppuVar15) {
            pppppuVar52 = (uint *****)(ifStack[2] + (int)((int)pppppuVar15 - 1U));
          }
          if ((int)local_188 <= (int)(*pppppuVar52)[0x2e]) {
            uVar10 = puVar13[2] - 1;
            piVar18 = (int *)0x0;
            if (uVar10 < (uint)puVar13[2]) {
              piVar18 = (int *)(uVar10 * 4 + puVar13[3]);
            }
            iVar43 = *piVar18;
            uVar50 = *(undefined4 *)(*(int *)(program + 8) + 0x374);
            continueTargetBlock = *(undefined4 *)(iVar43 + 0x150);
            puVar32 = (undefined4 *)Arena__alloc(uVar50,0x138);
            *puVar32 = uVar50;
            ppppppuVar48 = (uint ******)(puVar32 + 1);
            in_r6 = *(uint *******)(program + 8);
            ContinueBlock__ctor_ec178(ppppppuVar48,iVar43,*(undefined4 *)(iVar43 + 300),in_r6);
            puVar32[0x2f] = local_188;
            FUN_000ec3ac(program,previousBlock,ppppppuVar48);
            Block__connect(previousBlock,ppppppuVar48);
            Block__connect(ppppppuVar48,continueTargetBlock);
            local_bc = 0;
            *(undefined4 *)(iVar43 + 0x13c) = 1;
            previousBlock = (uint *****)ppppppuVar48;
            break;
          }
        }
        goto code_r0x00103718;
      }
      goto switchD_0010061c_caseD_1;
    case 0x26:
      puVar32 = (undefined4 *)0x0;
      uVar10 = puVar14[2] - 1;
      if (uVar10 < (uint)puVar14[2]) {
        puVar32 = (undefined4 *)(uVar10 * 4 + puVar14[3]);
      }
      if (*(int *)*puVar32 == 0) goto switchD_0010061c_caseD_1;
      piVar18 = (int *)((int)local_17c * 4 + iVar47);
      do {
        piVar36 = local_17c;
        if (*piVar18 == 0x37) {
          piVar36 = (int *)((int)local_17c + 1);
          piVar18 = piVar18 + 1;
        }
        local_17c = (int *)((int)piVar36 + 1);
        piVar18 = piVar18 + 1;
      } while (*piVar18 != 0x28);
      local_bc = 0;
      local_17c = piVar36;
      break;
    case 0x27:
      pppppuVar52 = (uint *****)0x0;
      pppppuVar15 = (uint *****)((int)ifStack[1] - 1);
      if (pppppuVar15 < ifStack[1]) {
        pppppuVar52 = (uint *****)(ifStack[2] + (int)pppppuVar15);
      }
      ppppuVar45 = *pppppuVar52;
      compilerArenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
      puVar32 = (undefined4 *)Arena__alloc(compilerArenaA,0x130);
      *puVar32 = compilerArenaA;
      ppppppuVar48 = (uint ******)(puVar32 + 1);
      Block__ctor_ea020(ppppppuVar48,*(undefined4 *)(program + 8));
      puVar32[0x2f] = local_188;
      ppppuVar45[0x4e] = (uint ***)ppppppuVar48;
      currentBlock = (uint *****)ppppppuVar48;
      Block__connect(ppppuVar45,ppppppuVar48);
      FUN_000ec3ac(program,previousBlock,currentBlock);
      goto code_r0x00103300;
    case 0x28:
      uVar10 = puVar14[2];
      piVar18 = (int *)0x0;
      if (uVar10 - 1 < uVar10) {
        piVar18 = (int *)((uVar10 - 1) * 4 + puVar14[3]);
      }
      piVar18 = (int *)*piVar18;
      Vector__removeAt(puVar12,uVar10 - 1);
joined_r0x00103afc:
      if (piVar18 != (int *)0x0) {
        Arena__free(piVar18[-1],piVar18 + -1);
        goto code_r0x00101d1c;
      }
      goto switchD_0010061c_caseD_1;
    case 0x29:
      pppppuVar52 = (uint *****)0x0;
      pppppuVar15 = (uint *****)((int)ifStack[1] - 1);
      if (pppppuVar15 < ifStack[1]) {
        pppppuVar52 = (uint *****)(ifStack[2] + (int)pppppuVar15);
      }
      ppppuVar45 = *pppppuVar52;
      pppuVar42 = ppppuVar45[0x4f];
      pppuVar42[0x2e] = (uint **)local_188;
      FUN_000ec3ac(program,previousBlock,pppuVar42);
      piVar18 = (int *)FUN_000e7b9c(ppppuVar45);
      piVar18[0x2e] = (int)local_188;
      iVar43 = (**(code **)(*piVar18 + 0x38))();
      if ((iVar43 == 0) && (iVar43 = (**(code **)(*piVar18 + 0x3c))(piVar18), iVar43 == 0)) {
        Block__connect(piVar18,pppuVar42);
      }
      ppppuVar30 = (uint ****)FUN_000e7a9c(ppppuVar45);
      ppppuVar30[0x2e] = (uint ***)local_188;
      ppppuVar51 = ppppuVar30;
      if (ppppuVar30 == ppppuVar45) {
        compilerArenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
        puVar32 = (undefined4 *)Arena__alloc(compilerArenaA,0x130);
        *puVar32 = compilerArenaA;
        ppppuVar51 = (uint ****)(puVar32 + 1);
        Block__ctor_ea020(ppppuVar51,*(undefined4 *)(program + 8));
        puVar32[0x2f] = local_188;
        ppppuVar30[0x4e] = (uint ***)ppppuVar51;
        Block__connect(ppppuVar30,ppppuVar51);
        FUN_000ec3ac(program,previousBlock,ppppuVar51);
      }
      iVar43 = (*(code *)(*ppppuVar51)[0xe])(ppppuVar51);
      if ((iVar43 == 0) && (iVar43 = (*(code *)(*ppppuVar51)[0xf])(ppppuVar51), iVar43 == 0)) {
        Block__connect(ppppuVar51,pppuVar42);
      }
      compilerArenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
      puVar32 = (undefined4 *)Arena__alloc(compilerArenaA,0x130);
      *puVar32 = compilerArenaA;
      ppppppuVar48 = (uint ******)(puVar32 + 1);
      Block__ctor_ea020(ppppppuVar48,*(undefined4 *)(program + 8));
      puVar32[0x2f] = local_188;
      currentBlock = (uint *****)ppppppuVar48;
      FUN_000ec3ac(program,pppuVar42,ppppppuVar48);
      Block__connect(pppuVar42,currentBlock);
      previousBlock = currentBlock;
      Vector__removeAt(ifStack,(int)ifStack[1] - 1);
      uVar10 = puVar13[2];
      if (uVar10 == 0) goto switchD_0010061c_caseD_1;
      piVar18 = (int *)0x0;
      if (uVar10 - 1 < uVar10) {
        piVar18 = (int *)((uVar10 - 1) * 4 + puVar13[3]);
      }
      local_bc = 0;
      *(int *)(*piVar18 + 300) = *(int *)(*piVar18 + 300) + -1;
      break;
    case 0x2a:
      uVar10 = puVar24[2];
      if (uVar10 != 0) {
        puVar32 = (undefined4 *)0x0;
        if (uVar10 - 1 < uVar10) {
          puVar32 = (undefined4 *)((uVar10 - 1) * 4 + puVar24[3]);
        }
        piVar18 = (int *)*puVar32;
        Vector__removeAt(ppppppuVar19,uVar10 - 1);
        if ((uint ******)piVar18[2] != (uint ******)0x0) {
          currentBlock = (uint *****)piVar18[2];
        }
        local_17c = (int *)piVar18[1];
        iVar47 = *piVar18;
        goto joined_r0x00103afc;
      }
      goto switchD_0010061c_caseD_0;
    case 0x2c:
      local_74 = 0x1dd5d8;
      if ((UNK_001dc660 == 0) || (iVar34 == UNK_001dc660)) {
code_r0x00101020:
        local_64 = 0;
      }
      else {
        piVar18 = &UNK_001dc66c;
        local_64 = 0;
        do {
          iVar43 = *piVar18;
          local_64 = local_64 + 1;
          if (iVar43 == 0) goto code_r0x00101020;
          piVar18 = piVar18 + 3;
        } while (iVar34 != iVar43);
      }
      local_64 = local_64 * 0xc;
      uVar10 = *(uint *)(local_64 + 0x1dc664);
      if ((uVar10 & 0x80) == 0) {
        uVar17 = (uint)*(byte *)((int)ilReader + 0x8d);
        uVar44 = uVar17;
      }
      else {
        uVar17 = (uint)*ppppppuVar49 >> 0x18 & 0x1f;
        uVar44 = (uint)*(byte *)((int)ilReader + 0x8d);
      }
      if (*(int *)(program + 0x7c) < (int)uVar44) {
        *(uint *)(program + 0x7c) = uVar44;
      }
      *(uint *)(program + 0x84) = 1 << (uVar44 & 0x3f) | *(uint *)(program + 0x84);
      puVar26 = (undefined2 *)Arena__alloc(*(undefined4 *)(*(int *)(program + 8) + 0x374),0x24);
      _memset(puVar26,0,0x24);
      puVar26[6] = 3;
      puVar26[4] = 7;
      puVar26[9] = 1;
      puVar26[10] = 0;
      *(uint *)(puVar26 + 0x10) = uVar17;
      *puVar26 = 3;
      puVar26[1] = 3;
      puVar26[2] = 3;
      puVar26[3] = 7;
      puVar26[5] = 3;
      puVar26[7] = 1;
      puVar26[8] = 0;
      puVar26[0xb] = 0;
      puVar26[0xc] = 0;
      puVar26[0xd] = 0;
      puVar26[0xe] = 0;
      if ((int)*ppppppuVar49 < 0) {
        uVar31 = ((int (*)())remapSelectSmall)((uint)ilReader[0x25] & 7);
        *puVar26 = uVar31;
        uVar31 = ((int (*)())remapSelectSmall)((uint)ilReader[0x25] >> 3 & 7);
        puVar26[1] = uVar31;
        uVar31 = ((int (*)())remapSelectSmall)((uint)ilReader[0x25] >> 0xc & 7);
        puVar26[2] = uVar31;
        uVar31 = ((int (*)())remapSelectSmall)((uint)ilReader[0x25] >> 6 & 7);
        puVar26[5] = uVar31;
        uVar31 = ((int (*)())remapSelectSmall)((uint)ilReader[0x25] >> 9 & 7);
        puVar26[6] = uVar31;
        uVar31 = ((int (*)())remapSelectSmall)((uint)ilReader[0x25] >> 0xf & 7);
        puVar26[3] = uVar31;
        puVar26[0xb] = (ushort)((uint)ilReader[0x25] >> 0x12) & 0x7f;
        if ((uVar10 & 4) != 0) {
          puVar26[8] = ((ushort)((uint)ilReader[0x25] >> 0x19) & 1) + 1;
        }
      }
      if (ilReader[0x18] != (uint *****)0x0) {
        pppppuVar15 = ilReader[0x24];
        puVar26[0xc] = (ushort)pppppuVar15 & 0xff;
        puVar26[0xd] = (ushort)((uint)pppppuVar15 >> 8) & 0xff;
        puVar26[0xe] = (ushort)((uint)pppppuVar15 >> 0x10) & 0xff;
      }
      bVar3 = (uVar10 & 1) != 0;
      local_c4 = (uint)*ppppppuVar49 >> 0x18 & 1;
      puVar26[9] = (ushort)local_c4 ^ 1;
      bVar1 = ((uint)*ppppppuVar49 >> 0x19 & 1) == 0;
      puVar26[7] = (ushort)bVar1;
      if (bVar3) {
        puVar26[8] = (ushort)(iVar34 != 0x5f);
      }
      registerMap = *(undefined4 *)(program + 0x3ac);
      iVar43 = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(program + 8) + 0x3ac) = iVar43;
      local_c8 = FUN_00127608(registerMap,0,iVar43,0);
      local_178 = *(uint *******)(local_60 + -0x2c30);
      local_124 = *(uint ******)(local_78 + -0x2bfc);
      registerMap = *(undefined4 *)(program + 0x3ac);
      iVar43 = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(program + 8) + 0x3ac) = iVar43;
      virtualRegister = FUN_00127608(registerMap,0,iVar43,0);
      pvVar16 = IRInst__create(0x31,*(undefined4 *)(program + 8));
      IRInst__setOperandRef(pvVar16,0,virtualRegister);
      local_70 = &local_178;
      ((int (*)())FUN_000fa958)(program,5,1,ilReader,pvVar16,1,local_124,local_70,ppppppuVar37,1,currentBlock);
      ((int (*)())FUN_000f92fc)(program,pvVar16,currentBlock);
      if (bVar3) {
        uVar50 = *(undefined4 *)(program + 0x3ac);
        iVar43 = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
        *(int *)(*(int *)(program + 8) + 0x3ac) = iVar43;
        local_cc = FUN_00127608(uVar50,0,iVar43,0);
        pvVar16 = IRInst__create(0x31,*(undefined4 *)(program + 8));
        IRInst__setOperandRef(pvVar16,0,local_cc);
        ((int (*)())FUN_000fa958)(program,10,1,ilReader,pvVar16,1,local_124,local_70,ppppppuVar37,1,currentBlock);
        ((int (*)())FUN_000f92fc)(program,pvVar16,currentBlock);
      }
      else {
        local_cc = 0;
      }
      bVar2 = (uVar10 >> 3 & 1) != 0;
      if (bVar2) {
        uVar50 = *(undefined4 *)(program + 0x3ac);
        iVar43 = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
        *(int *)(*(int *)(program + 8) + 0x3ac) = iVar43;
        local_d0 = FUN_00127608(uVar50,0,iVar43,0);
        pvVar16 = IRInst__create(0x31,*(undefined4 *)(program + 8));
        IRInst__setOperandRef(pvVar16,0,local_d0);
        ((int (*)())FUN_000fa958)(program,0xe,1,ilReader,pvVar16,1,local_124,local_70,ppppppuVar37,1,currentBlock);
        ((int (*)())FUN_000f92fc)(program,pvVar16,currentBlock);
      }
      else {
        local_d0 = 0;
      }
      if ((uVar10 & 0x40) != 0) {
        pvVar16 = IRInst__create(0x31,*(undefined4 *)(program + 8));
        IRInst__setOperandRef(pvVar16,0,virtualRegister);
        IRInst__setOperandRef(pvVar16,1,local_cc);
        iVar43 = IRInst__getOperandRecord(pvVar16,1);
        *(undefined4 *)(iVar43 + 0x10) = 0;
        *(undefined4 *)((int)pvVar16 + 0x9c) = 0x1010100;
        ((int (*)())FUN_000f92fc)(program,pvVar16,currentBlock);
      }
      iVar20 = uVar44 * 0xc;
      iVar43 = *(int *)(*(int *)(program + 0x78) + iVar20 + 4);
      if ((iVar43 == 4) || (uVar50 = virtualRegister, iVar43 == 0xb)) {
        uVar50 = *(undefined4 *)(program + 0x3ac);
        iVar43 = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
        *(int *)(*(int *)(program + 8) + 0x3ac) = iVar43;
        uVar50 = FUN_00127608(uVar50,0,iVar43,0);
        pvVar16 = IRInst__create(0x1b,*(undefined4 *)(program + 8));
        IRInst__setOperandRef(pvVar16,0,uVar50);
        IRInst__setOperandRef(pvVar16,1,virtualRegister);
        local_178 = (uint ******)0x2020001;
        iVar43 = IRInst__getOperandRecord(pvVar16,1);
        *(undefined4 *)(iVar43 + 0x10) = 0x2020001;
        IRInst__setOperandRef(pvVar16,2,virtualRegister);
        local_178 = (uint ******)0x1000202;
        iVar43 = IRInst__getOperandRecord(pvVar16,2);
        *(undefined4 *)(iVar43 + 0x10) = 0x1000202;
        ((int (*)())FUN_000f92fc)(program,pvVar16,currentBlock);
        pvVar16 = IRInst__create(0x40,*(undefined4 *)(program + 8));
        IRInst__setOperandRef(pvVar16,0,uVar50);
        *(undefined4 *)((int)pvVar16 + 0x9c) = 0x1010001;
        IRInst__setOperandRef(pvVar16,1,uVar50);
        IROperand__setModifierBits((int)pvVar16 + 0xa4,2,1);
        iVar43 = IRInst__getOperandRecord(pvVar16,1);
        *(undefined4 *)(iVar43 + 0x10) = 0x2020202;
        ((int (*)())FUN_000f92fc)(program,pvVar16,currentBlock);
        pvVar16 = IRInst__create(0x14,*(undefined4 *)(program + 8));
        IRInst__setOperandRef(pvVar16,0,uVar50);
        *(undefined1 *)((int)pvVar16 + 0x9c) = 0;
        *(undefined1 *)((int)pvVar16 + 0x9d) = 0;
        *(undefined1 *)((int)pvVar16 + 0x9e) = 1;
        *(undefined1 *)((int)pvVar16 + 0x9f) = 1;
        IRInst__setOperandRef(pvVar16,1,uVar50);
        IRInst__setOperandRef(pvVar16,2,uVar50);
        iVar43 = IRInst__getOperandRecord(pvVar16,2);
        *(undefined4 *)(iVar43 + 0x10) = 0x2020202;
        ((void (*)())IRInst__makeLiteralVec4Float)(pvVar16,program,3,1.5,1.5,1.5,1.5);
        ((int (*)())FUN_000f92fc)(program,pvVar16,currentBlock);
        piVar18 = IRInst__create(0x31,*(undefined4 *)(program + 8));
        IRInst__setOperandRef(piVar18,0,uVar50);
        IRInst__setOperandRef(piVar18,1,uVar50);
        (**(code **)(*piVar18 + 0x88))(piVar18,1,0,1);
        (**(code **)(*piVar18 + 0x88))(piVar18,1,1,0);
        (**(code **)(*piVar18 + 0x88))(piVar18,1,2,3);
        (**(code **)(*piVar18 + 0x88))(piVar18,1,3,0);
        ((int (*)())FUN_000f92fc)(program,piVar18,currentBlock);
        if (iVar34 == 0x8b) {
          pvVar16 = IRInst__create(0x31,*(undefined4 *)(program + 8));
          IRInst__setOperandRef(pvVar16,0,uVar50);
          *(undefined1 *)((int)pvVar16 + 0x9e) = 1;
          *(undefined1 *)((int)pvVar16 + 0x9f) = 0;
          *(undefined1 *)((int)pvVar16 + 0x9c) = 1;
          *(undefined1 *)((int)pvVar16 + 0x9d) = 1;
          IRInst__setOperandRef(pvVar16,1,virtualRegister);
          ((int (*)())FUN_000f92fc)(program,pvVar16,currentBlock);
        }
        piVar18 = *(int **)(*(int *)(program + 8) + 0x30c);
        (**(code **)(*piVar18 + 0x5c))(piVar18,uVar44);
      }
      if (bVar2) {
        pvVar16 = IRInst__create(0x73,*(undefined4 *)(program + 8));
        piVar18 = IRInst__create(0x72,*(undefined4 *)(program + 8));
        virtualRegister = FUN_00127608(*(undefined4 *)(program + 0x3ac),0x1e,0,0);
        IRInst__setOperandRef(pvVar16,0,virtualRegister);
        IRInst__setOperandRef(pvVar16,1,local_cc);
        IRInst__setOperandRef(piVar18,0,virtualRegister);
        IRInst__setOperandRef(piVar18,1,local_d0);
        (**(code **)(*piVar18 + 0x90))(piVar18,virtualRegister);
        ((int (*)())FUN_000f92fc)(program,pvVar16,currentBlock);
        ((int (*)())FUN_000f92fc)(program,piVar18,currentBlock);
      }
      else {
        virtualRegister = 0;
      }
      uVar27 = uVar50;
      if (bVar3) {
        bVar3 = (uVar10 >> 2 & 1) == 0;
        if (!bVar3) {
          uVar27 = *(undefined4 *)(program + 0x3ac);
          iVar43 = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
          *(int *)(*(int *)(program + 8) + 0x3ac) = iVar43;
          uVar27 = FUN_00127608(uVar27,0,iVar43,0);
          pvVar16 = IRInst__create(0x31,*(undefined4 *)(program + 8));
          IRInst__setOperandRef(pvVar16,0,uVar27);
          *(undefined4 *)((int)pvVar16 + 0x9c) = 1;
          IRInst__setOperandRef(pvVar16,1,uVar50);
          ((int (*)())FUN_000f92fc)(program,pvVar16,currentBlock);
          pvVar16 = IRInst__create(0x31,*(undefined4 *)(program + 8));
          IRInst__setOperandRef(pvVar16,0,uVar27);
          *(undefined4 *)((int)pvVar16 + 0x9c) = 0x1010100;
          IRInst__setOperandRef(pvVar16,1,local_cc);
          ((int (*)())FUN_000f92fc)(program,pvVar16,currentBlock);
        }
      }
      else {
        bVar3 = (uVar10 >> 2 & 1) == 0;
      }
      iVar43 = *(int *)(local_64 + local_74 + -0xf70);
      if ((bVar3) || (bVar1)) {
        if ((iVar43 != 0xff) || (*(int *)(iVar20 + *(int *)(program + 0x78) + 4) != 7))
        goto code_r0x001019bc;
        pvVar16 = IRInst__create(0x104,*(undefined4 *)(program + 8));
        *(uint *)((int)pvVar16 + 0x130) = uVar44;
        *(undefined4 *)((int)pvVar16 + 0x140) = *(undefined4 *)(local_60 + -0x2c30);
        IRInst__setOperandRef(pvVar16,0,local_c8);
        IRInst__setOperandRef(pvVar16,1,uVar27);
        ((int (*)())FUN_000f92fc)(program,pvVar16,currentBlock);
      }
      else {
        iVar43 = 0xae;
code_r0x001019bc:
        piVar18 = IRInst__create(iVar43,*(undefined4 *)(program + 8));
        piVar18[0x4f] = (int)puVar26;
        piVar18[0x4d] = uVar44;
        IRInst__setOperandRef(piVar18,0,local_c8);
        IRInst__setOperandRef(piVar18,1,uVar27);
        if (bVar2) {
          (**(code **)(*piVar18 + 0x90))(piVar18,virtualRegister);
        }
        iVar43 = *(int *)(program + 0x78);
        if (*(int *)(iVar20 + iVar43 + 4) == 8) {
          (**(code **)(*piVar18 + 0x88))(piVar18,1,2,1);
          pvVar16 = IRInst__create(0xbe,*(undefined4 *)(program + 8));
          iVar21 = piVar18[0x2b];
          iVar22 = piVar18[0x2c];
          iVar43 = IRInst__getOperandRecord(pvVar16,0);
          *(int *)(iVar43 + 0xc) = iVar22;
          *(int *)(iVar43 + 8) = iVar21;
          iVar21 = piVar18[0x2b];
          iVar22 = piVar18[0x2c];
          iVar43 = IRInst__getOperandRecord(pvVar16,1);
          *(int *)(iVar43 + 0xc) = iVar22;
          *(int *)(iVar43 + 8) = iVar21;
          iVar43 = IRInst__getOperandRecord(pvVar16,1);
          *(undefined4 *)(iVar43 + 0x10) = 0x1010101;
          *(undefined4 *)((int)pvVar16 + 0x9c) = 0x1000101;
          ((int (*)())FUN_000f92fc)(program,pvVar16,currentBlock);
          iVar43 = *(int *)(program + 0x78);
        }
        if (*(int *)(iVar20 + iVar43 + 4) == 9) {
          pvVar16 = IRInst__create(0xbe,*(undefined4 *)(program + 8));
          iVar21 = piVar18[0x2b];
          iVar22 = piVar18[0x2c];
          iVar43 = IRInst__getOperandRecord(pvVar16,0);
          *(int *)(iVar43 + 0xc) = iVar22;
          *(int *)(iVar43 + 8) = iVar21;
          iVar21 = piVar18[0x2b];
          iVar22 = piVar18[0x2c];
          iVar43 = IRInst__getOperandRecord(pvVar16,1);
          *(int *)(iVar43 + 0xc) = iVar22;
          *(int *)(iVar43 + 8) = iVar21;
          iVar43 = IRInst__getOperandRecord(pvVar16,1);
          *(undefined4 *)(iVar43 + 0x10) = 0x2020202;
          *(undefined4 *)((int)pvVar16 + 0x9c) = 0x1010001;
          ((int (*)())FUN_000f92fc)(program,pvVar16,currentBlock);
          iVar43 = *(int *)(program + 0x78);
        }
        iVar43 = ((int (*)())remapSelect1To0)(*(undefined4 *)(iVar20 + iVar43));
        piVar18[0x4e] = iVar43;
        *(short *)(piVar18[0x4f] + 0x12) = (short)local_c4;
        ((int (*)())FUN_000f92fc)(program,piVar18,currentBlock);
        if (*(int *)(iVar20 + *(int *)(program + 0x78) + 8) != 0) {
          pvVar16 = IRInst__create(0x13,*(undefined4 *)(program + 8));
          iVar20 = piVar18[0x25];
          iVar21 = piVar18[0x26];
          iVar43 = IRInst__getOperandRecord(pvVar16,0);
          *(int *)(iVar43 + 0xc) = iVar21;
          *(int *)(iVar43 + 8) = iVar20;
          iVar20 = piVar18[0x26];
          iVar21 = piVar18[0x25];
          iVar43 = IRInst__getOperandRecord(pvVar16,1);
          local_98 = (uint)(short)uVar44;
          *(int *)(iVar43 + 0xc) = iVar20;
          local_90 = local_98 | 0x130000;
          local_94 = local_98 | 0x130000;
          local_9c = local_98 | 0x130000;
          local_98 = local_98 | 0x130000;
          *(int *)(iVar43 + 8) = iVar21;
          ((int (*)())IRInst__makeLiteralVec4Int)(pvVar16,program,2,local_90,local_94,local_98,local_9c);
          ((int (*)())FUN_000f92fc)(program,pvVar16,currentBlock);
        }
      }
      local_178 = *(uint *******)(local_60 + -0x2c30);
      local_124 = *(uint ******)(local_78 + -0x2bfc);
      ppppppuVar38 = IRInst__create(0x31,*(undefined4 *)(program + 8));
      in_r8 = (uint ******)((int)((unsigned char *)0x0) + 1);
      in_r6 = ilReader;
      in_r7 = ppppppuVar38;
      ((int (*)())FUN_000fa958)(program,0,0,ilReader,ppppppuVar38,1,local_124,local_70,ppppppuVar37,1,currentBlock);
      IRInst__setOperandRef(ppppppuVar38,1,local_c8);
      goto code_r0x00101cbc;
    case 0x2d:
    case 0x2e:
      pppppuVar11 = (uint *****)(uint)*(byte *)((int)ilReader + 0x8d);
      pppppuVar15 = (uint *****)Arena__alloc(*(undefined4 *)(*(int *)(program + 8) + 0x374),0x24);
      _memset(pppppuVar15,0,0x24);
      *(undefined2 *)((int)pppppuVar15 + 0x12) = 1;
      *(undefined2 *)((int)pppppuVar15 + 0xe) = 1;
      *(undefined2 *)(pppppuVar15 + 5) = 0;
      *(undefined2 *)(pppppuVar15 + 4) = 0;
      *(undefined2 *)((int)pppppuVar15 + 0x16) = 0;
      *(undefined2 *)(pppppuVar15 + 6) = 0;
      *(undefined2 *)((int)pppppuVar15 + 0x1a) = 0;
      *(undefined2 *)(pppppuVar15 + 7) = 0;
      *(undefined2 *)(pppppuVar15 + 2) = 7;
      *(undefined2 *)(pppppuVar15 + 3) = 3;
      *(undefined2 *)pppppuVar15 = 3;
      *(undefined2 *)((int)pppppuVar15 + 2) = 3;
      *(undefined2 *)(pppppuVar15 + 1) = 3;
      *(undefined2 *)((int)pppppuVar15 + 6) = 7;
      *(undefined2 *)((int)pppppuVar15 + 10) = 3;
      *(ushort *)((int)pppppuVar15 + 0x12) =
           (ushort)(((uint)(byte)((((uint)*ppppppuVar49 & 0x1000000) == 0) << 1) << 0x1c) >> 0x1d);
      bVar1 = ((uint)*ppppppuVar49 >> 0x19 & 1) == 0;
      *(ushort *)((int)pppppuVar15 + 0xe) = (ushort)bVar1;
      registerMap = *(undefined4 *)(program + 0x3ac);
      iVar43 = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(program + 8) + 0x3ac) = iVar43;
      virtualRegister = FUN_00127608(registerMap,0,iVar43,0);
      local_124 = (uint *****)0x1;
      pppppuVar52 = *(uint ******)(local_60 + -0x2c30);
      local_178 = (uint ******)pppppuVar52;
      pvVar16 = IRInst__create(0x31,*(undefined4 *)(program + 8));
      IRInst__setOperandRef(pvVar16,0,virtualRegister);
      *(undefined4 *)((int)pvVar16 + 0x9c) = 1;
      local_70 = &local_178;
      ((int (*)())FUN_000fa958)(program,5,1,ilReader,pvVar16,1,local_124,local_70,ppppppuVar37,1,currentBlock);
      ((int (*)())FUN_000f92fc)(program,pvVar16,currentBlock);
      local_124 = (uint *****)0x1010100;
      local_178 = (uint ******)pppppuVar52;
      ppppppuVar38 = IRInst__create(0x31,*(undefined4 *)(program + 8));
      IRInst__setOperandRef(ppppppuVar38,0,virtualRegister);
      ppppppuVar38[0x27] = (uint *****)0x1010100;
      ((int (*)())FUN_000fa958)(program,10,1,ilReader,ppppppuVar38,1,local_124,local_70,ppppppuVar37,1,currentBlock);
      ((int (*)())FUN_000f92fc)(program,ppppppuVar38,currentBlock);
      if (bVar1) {
        uVar50 = 0x76;
      }
      else {
        uVar50 = 0xae;
        if (uVar10 == 0x2d) {
          Compiler__fail(*(undefined4 *)(program + 8),0xf);
          uVar50 = 0xae;
        }
      }
      local_124 = *(uint ******)(local_78 + -0x2bfc);
      ppppppuVar39 = *(uint *******)(local_60 + -0x2c30);
      local_178 = ppppppuVar39;
      ppppppuVar48 = IRInst__create(uVar50,*(undefined4 *)(program + 8));
      ppppppuVar48[0x4f] = pppppuVar15;
      ppppppuVar48[0x4d] = pppppuVar11;
      if (*(int *)(program + 0x7c) < (int)pppppuVar11) {
        *(uint ******)(program + 0x7c) = pppppuVar11;
      }
      *(uint *)(program + 0x84) = 1 << ((uint)pppppuVar11 & 0x3f) | *(uint *)(program + 0x84);
      pppppuVar15 = (uint *****)
                    ((int (*)())remapSelect1To0)(*(undefined4 *)(*(int *)(program + 0x78) + (int)pppppuVar11 * 0xc))
      ;
      ppppppuVar48[0x4c] = pppppuVar11;
      ppppppuVar48[0x4e] = pppppuVar15;
      in_r8 = (uint ******)((int)((unsigned char *)0x0) + 1);
      in_r6 = ilReader;
      in_r7 = ppppppuVar48;
      iVar43 = ((int (*)())FUN_000fa958)(program,4,0,ilReader,ppppppuVar48,1,local_124,local_70,ppppppuVar37,1,
                            currentBlock);
      if (iVar43 != 0) {
        DList__pushFront(local_6c,iVar43);
      }
      IRInst__setOperandRef(ppppppuVar48,1,virtualRegister);
      iVar43 = IRInst__getOperandRecord(ppppppuVar48,1);
      *(uint *******)(iVar43 + 0x10) = ppppppuVar39;
      pppppuVar15 = (uint *****)
                    ((int (*)())remapSelect1To0)(*(undefined4 *)((int)pppppuVar11 * 0xc + *(int *)(program + 0x78)))
      ;
      ppppppuVar48[0x4e] = pppppuVar15;
      ((int (*)())FUN_000f92fc)(program,ppppppuVar48,currentBlock);
      goto code_r0x00101d1c;
    case 0x2f:
      uVar10 = (uint)*(byte *)((int)ilReader + 0x8d);
      puVar26 = (undefined2 *)Arena__alloc(*(undefined4 *)(*(int *)(program + 8) + 0x374),0x24);
      _memset(puVar26,0,0x24);
      puVar26[9] = 1;
      puVar26[6] = 3;
      puVar26[7] = 1;
      *puVar26 = 3;
      puVar26[1] = 3;
      puVar26[2] = 3;
      puVar26[5] = 3;
      puVar26[4] = 7;
      puVar26[10] = 0;
      puVar26[3] = 7;
      puVar26[8] = 0;
      puVar26[0xb] = 0;
      puVar26[0xc] = 0;
      puVar26[0xd] = 0;
      puVar26[0xe] = 0;
      uVar7 = (byte)((uint)*ppppppuVar49 >> 0x18) & 1;
      puVar26[9] = uVar7 ^ 1;
      puVar26[7] = (ushort)(((uint)(byte)((((uint)*ppppppuVar49 & 0x2000000) == 0) << 1) << 0x1c) >>
                           0x1d);
      registerMap = *(undefined4 *)(program + 0x3ac);
      iVar43 = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(program + 8) + 0x3ac) = iVar43;
      uVar50 = FUN_00127608(registerMap,0,iVar43,0);
      local_178 = *(uint *******)(local_60 + -0x2c30);
      local_124 = *(uint ******)(local_78 + -0x2bfc);
      registerMap = *(undefined4 *)(program + 0x3ac);
      iVar43 = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(program + 8) + 0x3ac) = iVar43;
      uVar27 = FUN_00127608(registerMap,0,iVar43,0);
      pvVar16 = IRInst__create(0x31,*(undefined4 *)(program + 8));
      IRInst__setOperandRef(pvVar16,0,uVar27);
      local_70 = &local_178;
      ((int (*)())FUN_000fa958)(program,5,1,ilReader,pvVar16,1,local_124,local_70,ppppppuVar37,1,currentBlock);
      ((int (*)())FUN_000f92fc)(program,pvVar16,currentBlock);
      virtualRegister = 0;
      if (iVar34 == 0x5f) {
        registerMap = *(undefined4 *)(program + 0x3ac);
        iVar43 = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
        *(int *)(*(int *)(program + 8) + 0x3ac) = iVar43;
        virtualRegister = FUN_00127608(registerMap,0,iVar43,0);
        pvVar16 = IRInst__create(0x31,*(undefined4 *)(program + 8));
        IRInst__setOperandRef(pvVar16,0,virtualRegister);
        ((int (*)())FUN_000fa958)(program,10,1,ilReader,pvVar16,1,local_124,local_70,ppppppuVar37,1,currentBlock);
        ((int (*)())FUN_000f92fc)(program,pvVar16,currentBlock);
        uVar41 = *(undefined4 *)(program + 0x3ac);
        iVar43 = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
        *(int *)(*(int *)(program + 8) + 0x3ac) = iVar43;
        uVar41 = FUN_00127608(uVar41,0,iVar43,0);
        pvVar16 = IRInst__create(0x31,*(undefined4 *)(program + 8));
        IRInst__setOperandRef(pvVar16,0,uVar41);
        ((int (*)())FUN_000fa958)(program,0xe,1,ilReader,pvVar16,1,local_124,local_70,ppppppuVar37,1,currentBlock);
        ((int (*)())FUN_000f92fc)(program,pvVar16,currentBlock);
      }
      else {
        uVar41 = 0;
      }
      pvVar16 = IRInst__create(0x78,*(undefined4 *)(program + 8));
      *(undefined2 **)((int)pvVar16 + 0x13c) = puVar26;
      IRInst__setOperandRef(pvVar16,0,uVar50);
      IRInst__setOperandRef(pvVar16,1,uVar27);
      if (iVar34 == 0x5f) {
        IRInst__setOperandRef(pvVar16,2,virtualRegister);
        IRInst__setOperandRef(pvVar16,3,uVar41);
      }
      *(uint *)((int)pvVar16 + 0x134) = uVar10;
      if (*(int *)(program + 0x7c) < (int)uVar10) {
        *(uint *)(program + 0x7c) = uVar10;
      }
      *(uint *)(program + 0x84) = 1 << (uVar10 & 0x3f) | *(uint *)(program + 0x84);
      remappedSelect = ((int (*)())remapSelect1To0)(*(undefined4 *)(uVar10 * 0xc + *(int *)(program + 0x78)));
      *(undefined4 *)((int)pvVar16 + 0x138) = remappedSelect;
      *(uint *)((int)pvVar16 + 0x130) = uVar10;
      *(ushort *)(*(int *)((int)pvVar16 + 0x13c) + 0x12) = uVar7;
      ((int (*)())FUN_000f92fc)(program,pvVar16,currentBlock);
      local_178 = *(uint *******)(local_60 + -0x2c30);
      local_124 = *(uint ******)(local_78 + -0x2bfc);
      ppppppuVar38 = IRInst__create(0x31,*(undefined4 *)(program + 8));
      in_r8 = (uint ******)((int)((unsigned char *)0x0) + 1);
      in_r6 = ilReader;
      in_r7 = ppppppuVar38;
      ((int (*)())FUN_000fa958)(program,0,0,ilReader,ppppppuVar38,1,local_124,local_70,ppppppuVar37,1,currentBlock);
      IRInst__setOperandRef(ppppppuVar38,1,uVar50);
code_r0x00101cbc:
      ((int (*)())FUN_000f92fc)(program,ppppppuVar38,currentBlock);
      goto code_r0x00101d1c;
    case 0x30:
      iVar43 = iVar47 + (int)local_17c * 4;
      ((void (*)())IRInst__makeLiteralVec4Float)(ppppppuVar38,program,ppppppuVar40,(double)*(float *)(iVar43 + 4),
                   (double)*(float *)(iVar43 + 8),(double)*(float *)(iVar43 + 0xc),
                   (double)*(float *)(iVar43 + 0x10));
      iVar43 = IRInst__getOperandRecord(ppppppuVar38,ppppppuVar40);
      SelectWord__compose(&local_d8,*(undefined4 *)(iVar43 + 0x10),local_178);
      selectWord = local_d8;
      iVar43 = IRInst__getOperandRecord(ppppppuVar38,ppppppuVar40);
      *(undefined4 *)(iVar43 + 0x10) = selectWord;
      ppppppuVar40 = (uint ******)((int)ppppppuVar40 + 1);
      local_bc = 0;
      local_17c = local_17c + 1;
      break;
    case 0x31:
      compilerArenaB = *(undefined4 *)(*(int *)(program + 8) + 0x378);
      puVar32 = (undefined4 *)Arena__alloc(compilerArenaB,0x10);
      *puVar32 = compilerArenaB;
      puVar35 = puVar32 + 1;
      local_17c = (int *)((int)local_17c + 1);
      switch(*(undefined4 *)(iVar47 + (int)local_17c * 4)) {
      case 0x3f:
        *puVar35 = (uint)*ppppppuVar49 >> 0x12 & 1;
        break;
      default:
        *puVar35 = 0;
        break;
      case 0x5f:
        *puVar35 = (uint)*ppppppuVar49 >> 0x18 & 1;
        break;
      case 0x67:
        *puVar35 = 1;
      }
      uVar10 = puVar14[2];
      if (uVar10 < *puVar12) {
        _memset(uVar10 * 4 + puVar14[3],0,4);
        puVar14[2] = uVar10 + 1;
        puVar32 = (undefined4 *)(uVar10 * 4 + puVar14[3]);
      }
      else {
        puVar32 = (undefined4 *)Vector__elementRefGrow(puVar12,uVar10);
      }
      local_bc = 0;
      *puVar32 = puVar35;
      break;
    case 0x32:
      ppppppuVar48 = (uint ******)0x0;
      pppppuVar15 = (uint *****)ifStack[1];
      if (pppppuVar15 != (uint *****)0x0) {
        pppppuVar52 = (uint *****)0x0;
        if ((uint *****)((int)pppppuVar15 - 1U) < pppppuVar15) {
          pppppuVar52 = (uint *****)(ifStack[2] + (int)((int)pppppuVar15 - 1U));
        }
        ppppppuVar48 = (uint ******)*pppppuVar52;
        ppppppuVar48[0x51] = (uint *****)0x0;
      }
      local_17c = (int *)((int)local_17c + 1);
      switch(*(undefined4 *)(iVar47 + (int)local_17c * 4)) {
      case 0x62:
        pvVar16 = IRInst__create(0x8b,*(undefined4 *)(program + 8));
        ((void (*)())IRInst__makeLiteralVec4Float)(pvVar16,program,1,1.0,1.0,1.0,1.0);
        ((void (*)())IRInst__makeLiteralVec4Float)(pvVar16,program,2,1.0,1.0,1.0,1.0);
        *(undefined4 *)((int)pvVar16 + 300) = 0;
        compilerArenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
        puVar32 = (undefined4 *)Arena__alloc(compilerArenaA,0x15c);
        *puVar32 = compilerArenaA;
        pppppuVar15 = (uint *****)(puVar32 + 1);
        in_r6 = (uint ******)0x0;
        in_r7 = *(uint *******)(program + 8);
        IfHeader__ctor_ea6d0(pppppuVar15,pvVar16,ppppppuVar48,0,in_r7);
        break;
      case 99:
        iVar43 = *(int *)(program + 8);
        pppuVar42 = **ilReader[0x1b];
        if (((((uint)pppuVar42 & 0x3f0000) == 0x100000) && (iVar43 != 0)) &&
           ((*(uint *)(*(int *)(iVar43 + 0x30c) + 8) & 0x80) != 0)) {
          iVar20 = 0xf;
        }
        else {
          iVar20 = (int)*(short *)((int)*ilReader[0x1b] + 2);
        }
        pvVar16 = IRInst__create(0x8d,iVar43);
        registerFile = FUN_000ec208(program,(uint)pppuVar42 >> 0x10 & 0x3f);
        iVar43 = IRInst__getOperandRecord(pvVar16,1);
        *(undefined4 *)(iVar43 + 0xc) = registerFile;
        puVar8 = PTR_DAT_001e8b84;
        *(int *)(iVar43 + 8) = iVar20;
        *(undefined4 *)((int)pvVar16 + 300) = *(undefined4 *)puVar8;
        compilerArenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
        puVar32 = (undefined4 *)Arena__alloc(compilerArenaA,0x15c);
        *puVar32 = compilerArenaA;
        pppppuVar15 = (uint *****)(puVar32 + 1);
        in_r6 = *(uint *******)(program + 8);
        IfHeaderStatic__ctor_ebac8(pppppuVar15,pvVar16,ppppppuVar48,in_r6);
        FUN_000e78c0(pppppuVar15,local_188);
        FUN_000ed63c(program,pvVar16);
        pppppuVar52 = (uint *****)0x0;
        if ((uint *****)ifStack[1] != (uint *****)0x0) {
          puVar32[0x53] = 0;
          pppppuVar52 = (uint *****)ifStack[1];
        }
        if (pppppuVar52 < *ifStack) {
          _memset(ifStack[2] + (int)pppppuVar52,0,4);
          ifStack[1] = (uint ****)((int)pppppuVar52 + 1);
          pppppuVar52 = (uint *****)(ifStack[2] + (int)pppppuVar52);
        }
        else {
          pppppuVar52 = (uint *****)Vector__elementRefGrow(ifStack,pppppuVar52);
        }
        *pppppuVar52 = (uint ****)pppppuVar15;
        uVar10 = puVar13[2];
        if (uVar10 == 0) goto code_r0x00103240;
        goto code_r0x00103214;
      case 100:
        ppppuVar45 = *ilReader[0x1b];
        pppuVar42 = *ppppuVar45;
        iVar43 = *(int *)(program + 8);
        if ((((uint)pppuVar42 & 0x3f0000) == 0x100000) && (iVar43 != 0)) {
          piVar18 = *(int **)(iVar43 + 0x30c);
          if ((piVar18[2] & 0x80U) == 0) goto code_r0x00100810;
          iVar20 = 0xf;
        }
        else {
          piVar18 = *(int **)(iVar43 + 0x30c);
code_r0x00100810:
          iVar20 = (int)*(short *)((int)ppppuVar45 + 2);
        }
        ppppuVar45 = ilReader[0x1b][1];
        pppuVar33 = *ppppuVar45;
        if (((((uint)pppuVar33 & 0x3f0000) == 0x100000) && (iVar43 != 0)) &&
           ((piVar18[2] & 0x80U) != 0)) {
          iVar43 = 0xf;
        }
        else {
          iVar43 = (int)*(short *)((int)ppppuVar45 + 2);
        }
        in_r8 = (uint ******)((uint)pppuVar33 >> 0x10 & 0x3f);
        pvVar16 = (void *)(**(code **)(*piVar18 + 0x24))
                                    (piVar18,(uint)*ppppppuVar49 >> 0x10 & 7,iVar20,
                                     (uint)pppuVar42 >> 0x10 & 0x3f,iVar43,in_r8,local_178,ilReader);
        compilerArenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
        puVar32 = (undefined4 *)Arena__alloc(compilerArenaA,0x15c);
        *puVar32 = compilerArenaA;
        pppppuVar15 = (uint *****)(puVar32 + 1);
        in_r6 = (uint ******)0x0;
        in_r7 = *(uint *******)(program + 8);
        IfHeader__ctor_ea6d0(pppppuVar15,pvVar16,ppppppuVar48,0,in_r7);
        break;
      case 0x65:
        compilerArenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
        puVar32 = (undefined4 *)Arena__alloc(compilerArenaA,0x168);
        *puVar32 = compilerArenaA;
        puVar32 = puVar32 + 1;
        IRInst__ctor_10502c(puVar32,0x8c,*(undefined4 *)(program + 8));
        comparisonKind = 6;
        goto code_r0x00102c90;
      case 0x66:
        compilerArenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
        puVar32 = (undefined4 *)Arena__alloc(compilerArenaA,0x168);
        *puVar32 = compilerArenaA;
        puVar32 = puVar32 + 1;
        IRInst__ctor_10502c(puVar32,0x8c,*(undefined4 *)(program + 8));
        comparisonKind = 7;
code_r0x00102c90:
        puVar32[0x4b] = comparisonKind;
        in_r7 = (uint ******)ifStack;
        in_r8 = ppppppuVar37;
        pppppuVar15 = (uint *****)
                      ((int (*)())FUN_000fadc4)(program,puVar32,local_188,ppppppuVar48,ifStack,ppppppuVar37,
                                   ilReader);
        in_r6 = ppppppuVar48;
        goto code_r0x00103240;
      default:
        pppppuVar15 = (uint *****)0x0;
        goto code_r0x00103240;
      case 0x6f:
        uVar10 = conditionStack[1] - 1;
        puVar32 = (undefined4 *)0x0;
        if (uVar10 < conditionStack[1]) {
          puVar32 = (undefined4 *)(uVar10 * 4 + conditionStack[2]);
        }
        piVar18 = *(int **)(*(int *)(program + 8) + 0x30c);
        in_r8 = local_178;
        ifConditionInst = (**(code **)(*piVar18 + 0x28))
                           (piVar18,1,*(undefined4 *)*puVar32,4,ilReader[(int)ilReader[0x16] + 0x23],
                            local_178,ilReader,currentBlock);
        uVar50 = *(undefined4 *)(*(int *)(program + 8) + 0x374);
        puVar32 = (undefined4 *)Arena__alloc(uVar50,0x15c);
        *puVar32 = uVar50;
        pppppuVar15 = (uint *****)(puVar32 + 1);
        in_r6 = (uint ******)0x0;
        in_r7 = *(uint *******)(program + 8);
        IfHeader__ctor_ea6d0(pppppuVar15,ifConditionInst,ppppppuVar48,0,in_r7);
        uVar10 = conditionStack[1] - 1;
        if (uVar10 < conditionStack[1]) {
          piVar18 = (int *)(uVar10 * 4 + conditionStack[2]);
        }
        else {
          piVar18 = (int *)0x0;
        }
        iVar43 = *piVar18;
        FUN_000e77f4(pppppuVar15,*(undefined4 *)(iVar43 + 8));
        *(uint ******)(iVar43 + 8) = pppppuVar15;
        FUN_000e78c0(pppppuVar15,local_188);
        FUN_000ed63c(program,ifConditionInst);
        goto code_r0x0010319c;
      case 0x72:
        iVar43 = *(int *)(program + 8);
        pppuVar42 = **ilReader[0x1b];
        if ((((uint)pppuVar42 & 0x3f0000) == 0x100000) && (iVar43 != 0)) {
          piVar18 = *(int **)(iVar43 + 0x30c);
          if ((piVar18[2] & 0x80U) == 0) goto code_r0x0010082c;
          iVar43 = 0xf;
        }
        else {
          piVar18 = *(int **)(iVar43 + 0x30c);
code_r0x0010082c:
          iVar43 = (int)*(short *)((int)*ilReader[0x1b] + 2);
        }
        in_r8 = local_178;
        pvVar16 = (void *)(**(code **)(*piVar18 + 0x28))
                                    (piVar18,iVar34 == 0x6f,iVar43,(uint)pppuVar42 >> 0x10 & 0x3f,0,
                                     local_178,ilReader,currentBlock);
        compilerArenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
        puVar32 = (undefined4 *)Arena__alloc(compilerArenaA,0x15c);
        *puVar32 = compilerArenaA;
        pppppuVar15 = (uint *****)(puVar32 + 1);
        in_r6 = (uint ******)0x0;
        in_r7 = *(uint *******)(program + 8);
        IfHeader__ctor_ea6d0(pppppuVar15,pvVar16,ppppppuVar48,0,in_r7);
      }
      FUN_000e78c0(pppppuVar15,local_188);
      FUN_000ed63c(program,pvVar16);
code_r0x0010319c:
      pppppuVar52 = (uint *****)0x0;
      if ((uint *****)ifStack[1] != (uint *****)0x0) {
        pppppuVar15[0x52] = (uint ****)0x0;
        pppppuVar52 = (uint *****)ifStack[1];
      }
      if (pppppuVar52 < *ifStack) {
        _memset(ifStack[2] + (int)pppppuVar52,0,4);
        ifStack[1] = (uint ****)((int)pppppuVar52 + 1);
        pppppuVar52 = (uint *****)(ifStack[2] + (int)pppppuVar52);
      }
      else {
        pppppuVar52 = (uint *****)Vector__elementRefGrow(ifStack,pppppuVar52);
      }
      *pppppuVar52 = (uint ****)pppppuVar15;
      uVar10 = puVar13[2];
      if (uVar10 != 0) {
code_r0x00103214:
        piVar18 = (int *)0x0;
        if (uVar10 - 1 < uVar10) {
          piVar18 = (int *)((uVar10 - 1) * 4 + puVar13[3]);
        }
        *(int *)(*piVar18 + 300) = *(int *)(*piVar18 + 300) + 1;
      }
code_r0x00103240:
      FUN_000ec3ac(program,previousBlock,pppppuVar15);
      Block__connect(previousBlock,pppppuVar15);
      currentBlock = (uint *****)pppppuVar15[0x4d];
      previousBlock = pppppuVar15;
      FUN_000ec3ac(program,pppppuVar15,currentBlock);
code_r0x00103300:
      local_bc = 0;
      previousBlock = currentBlock;
      break;
    case 0x34:
      iVar43 = IRInst__getOperandRecord(ppppppuVar38,ppppppuVar40);
      local_bc = 0;
      ppppppuVar40 = (uint ******)((int)ppppppuVar40 + 1);
      *(undefined4 *)(iVar43 + 8) = 0;
      *(undefined4 *)(iVar43 + 0xc) = 0x21;
      break;
    case 0x35:
      piVar18 = (int *)0x0;
      uVar10 = puVar13[2] - 1;
      if (uVar10 < (uint)puVar13[2]) {
        piVar18 = (int *)(uVar10 * 4 + puVar13[3]);
      }
      iVar20 = *piVar18;
      iVar43 = Compiler__isOptionEnabled(*(undefined4 *)(program + 8),3);
      if ((iVar43 == 0) || (iVar43 = FUN_0012c2dc(program,iVar20), iVar43 == 0)) {
        in_r6 = &previousBlock;
        in_r7 = &currentBlock;
        in_r8 = (uint ******)&local_188;
        iVar43 = FUN_0012f0f8(program,ppppppuVar37,iVar20,in_r6,in_r7,in_r8);
        if (iVar43 != 0) goto switchD_0010061c_caseD_1;
        if (*(int *)(*(int *)(*(int *)(program + 8) + 0x30c) + 0x4c) < (int)local_188) {
          Compiler__fail(*(int *)(program + 8),8);
        }
        iVar21 = *(int *)(iVar20 + 0x150);
        FUN_000ec3ac(program,previousBlock,iVar21);
        iVar43 = (*(code *)(*previousBlock)[0xe])();
        if ((iVar43 == 0) && (iVar43 = (*(code *)(*previousBlock)[0xf])(), iVar43 == 0)) {
          Block__connect(previousBlock,iVar21);
        }
        compilerArenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
        puVar32 = (undefined4 *)Arena__alloc(compilerArenaA,0x130);
        *puVar32 = compilerArenaA;
        puVar29 = puVar32 + 1;
        Block__ctor_ea020(puVar29,*(undefined4 *)(program + 8));
        Block__connect(iVar20,puVar29);
        FUN_000ec3ac(program,iVar21,puVar29);
        iVar43 = *(int *)(iVar20 + 0x154);
        Block__connect(puVar29,iVar43);
        FUN_000ec3ac(program,puVar29,iVar43);
        compilerArenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
        puVar29 = (undefined4 *)Arena__alloc(compilerArenaA,0x130);
        *puVar29 = compilerArenaA;
        ppppppuVar48 = (uint ******)(puVar29 + 1);
        Block__ctor_ea020(ppppppuVar48,*(undefined4 *)(program + 8));
        currentBlock = (uint *****)ppppppuVar48;
        FUN_000ec3ac(program,iVar43,ppppppuVar48);
        Block__connect(iVar43,currentBlock);
        previousBlock = currentBlock;
        Vector__removeAt(ppppppuVar37,puVar13[2] + -1);
        local_bc = 0;
        *(uint *****)(iVar21 + 0xb8) = local_188;
        local_188 = (uint ****)((int)local_188 - 1);
        *(uint *****)(iVar43 + 0xb8) = local_188;
        puVar32[0x2f] = local_188;
        currentBlock[0x2e] = local_188;
      }
      else {
        previousBlock = (uint *****)Block__findSimplePredecessor(iVar20);
        if (*(int **)(iVar20 + 0x150) != (int *)0x0) {
          (**(code **)(**(int **)(iVar20 + 0x150) + 4))();
        }
        if (*(int **)(iVar20 + 0x154) != (int *)0x0) {
          (**(code **)(**(int **)(iVar20 + 0x154) + 4))();
        }
        Vector__removeValue(previousBlock[0x34],iVar20);
        do {
          ppppppuVar48 = (uint ******)previousBlock[2];
          pppppuVar15 = ppppppuVar48[0x26];
          for (pppppuVar52 = (uint *****)ppppppuVar48[0x26][2]; pppppuVar52 != (uint *****)0x0;
              pppppuVar52 = (uint *****)pppppuVar52[2]) {
            if (((uint)pppppuVar15[5] & 1) != 0) {
              pppppuVar15[5] = (uint ****)((uint)pppppuVar15[5] & 0xfffffffe);
            }
            pppppuVar15 = pppppuVar52;
          }
          DList__initSentinel(ppppppuVar48 + 0x24);
          DList__unlink(ppppppuVar48);
          if (ppppppuVar48 != (uint ******)0x0) {
            (*(code *)(*ppppppuVar48)[1])(ppppppuVar48);
          }
        } while (ppppppuVar48 != (uint ******)currentBlock);
        local_bc = 0;
        local_188 = (uint ****)((int)local_188 - 1);
        currentBlock = previousBlock;
      }
      break;
    case 0x36:
      uVar10 = puVar13[2];
      enclosingLoopHeader = 0;
      if (uVar10 != 0) {
        puVar32 = (undefined4 *)0x0;
        if (uVar10 - 1 < uVar10) {
          puVar32 = (undefined4 *)((uVar10 - 1) * 4 + puVar13[3]);
        }
        enclosingLoopHeader = *puVar32;
      }
      in_r6 = (uint ******)(uint)(iVar34 == 0x71);
      if (in_r6 == (uint ******)0x0) {
        uVar10 = (uint)*(ushort *)((int)*ilReader[0x1b] + 2);
      }
      else {
        uVar10 = 0;
      }
      uVar50 = *(undefined4 *)(*(int *)(program + 8) + 0x374);
      puVar32 = (undefined4 *)Arena__alloc(uVar50,0x15c);
      *puVar32 = uVar50;
      puVar29 = puVar32 + 1;
      in_r7 = *(uint *******)(program + 8);
      PostLoopFooter__ctor_ea828(puVar29,uVar10,enclosingLoopHeader,in_r6,in_r7);
      puVar32[0x2f] = local_188;
      if (((uint)*ppppppuVar49 & 0x10000) != 0) {
        puVar32[0x4e] = 1;
      }
      FUN_000ed63c(program,puVar32[0x53]);
      pppppuVar15 = (uint *****)puVar13[2];
      if (pppppuVar15 < *ppppppuVar37) {
        _memset((int)pppppuVar15 * 4 + puVar13[3],0,4);
        puVar13[2] = (int)pppppuVar15 + 1;
        puVar28 = (undefined4 *)((int)pppppuVar15 * 4 + puVar13[3]);
      }
      else {
        puVar28 = (undefined4 *)Vector__elementRefGrow(ppppppuVar37,pppppuVar15);
      }
      *puVar28 = puVar29;
      local_188 = (uint ****)((int)local_188 + 1);
      FUN_000ec3ac(program,previousBlock,puVar29);
      Block__connect(previousBlock,puVar29);
      compilerArenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
      puVar28 = (undefined4 *)Arena__alloc(compilerArenaA,0x130);
      *puVar28 = compilerArenaA;
      ppppppuVar48 = (uint ******)(puVar28 + 1);
      Block__ctor_ea020(ppppppuVar48,*(undefined4 *)(program + 8));
      puVar28[0x2f] = local_188;
      currentBlock = (uint *****)ppppppuVar48;
      FUN_000ec3ac(program,puVar29,ppppppuVar48);
      Block__connect(puVar29,currentBlock);
      previousBlock = currentBlock;
      local_bc = 0;
      puVar32[0x4d] = *(undefined4 *)(*(int *)(program + 8) + 0x324);
      break;
    case 0x37:
      local_17c = (int *)((int)local_17c + 1);
      irOpcode = *(undefined4 *)(iVar47 + (int)local_17c * 4);
      if (*(int *)(program + 0x47c) != 0) {
        irOpcode = 0x75;
      }
      ppppppuVar38 = IRInst__create(irOpcode,*(undefined4 *)(program + 8));
      local_bc = 0;
      break;
    case 0x38:
      local_b4 = 1;
      goto code_r0x00101d1c;
    case 0x3a:
      local_bc = 0;
      ppppppuVar38[0x48] = (uint *****)0x1;
      goto code_r0x00103b3c;
    case 0x3d:
      IROperand__setModifierBits(ppppppuVar38 + (int)ppppppuVar40 * 6 + 0x23,1,
                   (uint)ppppppuVar38[(int)ppppppuVar40 * 6 + 0x28] & 1 ^ 1);
      goto code_r0x00101d1c;
    case 0x42:
      local_17c = (int *)((int)local_17c + 1);
      dVar54 = (double)*(float *)(iVar47 + (int)local_17c * 4);
      ((void (*)())IRInst__makeLiteralVec4Float)(ppppppuVar38,program,ppppppuVar40,dVar54,dVar54,dVar54,dVar54);
      goto code_r0x001025c0;
    case 0x43:
    case 0x44:
    case 0x45:
    case 0x46:
    case 0x47:
    case 0x48:
    case 0x49:
      ppppppuVar48 = (uint ******)
                     (PTR_s_IF_b_001dc2cc)[uVar10 * 4 + ((uint)*ppppppuVar49 >> 0x10 & 0x3fff)];
      goto switchD_00102044_default;
    case 0x4a:
      ppppppuVar48 = *(uint *******)((int)&PTR_DAT_001dc75c + ((uint)*ppppppuVar49 >> 0xe & 0xc));
switchD_00102044_default:
      in_r6 = (uint ******)currentBlock;
      in_r8 = ppppppuVar19;
      iVar47 = ((int (*)())FUN_000fd50c)(program,iVar47,&local_17c,currentBlock,ppppppuVar48,ppppppuVar19);
      in_r7 = ppppppuVar48;
code_r0x0010372c:
      local_bc = 0;
      break;
    case 0x4b:
      if ((((uint)*ppppppuVar49 & 0x10000) == 0) ||
         (bVar1 = true, (*(uint *)(*(int *)(*(int *)(program + 8) + 0x30c) + 8) & 0x40) != 0)) {
        bVar1 = false;
      }
      in_r7 = (uint ******)PTR_DAT_001e8b98;
      if (bVar1) {
        in_r7 = (uint ******)PTR_DAT_001e8b9c;
      }
code_r0x001022b4:
      in_r6 = (uint ******)currentBlock;
      in_r8 = ppppppuVar19;
      iVar47 = ((int (*)())FUN_000fd50c)(program,iVar47,&local_17c,currentBlock,in_r7,ppppppuVar19);
      goto code_r0x0010372c;
    case 0x4d:
      local_bc = 0;
      *(ushort *)((int)ppppppuVar38[0x4f] + 0x12) = (byte)((uint)*ppppppuVar49 >> 0x18) & 1;
      break;
    case 0x4e:
      ppppppuVar48 = (uint ******)
                     ((int (*)())FUN_000f8ccc)((uint)*ppppppuVar49 >> 0x10 & 7,*(undefined4 *)(program + 8),0);
      goto code_r0x00101f74;
    case 0x4f:
      local_17c = (int *)((int)local_17c + 1);
      ((void (*)())FUN_001048d4)(ppppppuVar38,(double)*(float *)(iVar47 + (int)local_17c * 4));
      goto code_r0x00101d1c;
    case 0x50:
      local_17c = (int *)((int)local_17c + 1);
      ((void (*)())FUN_0010490c)(ppppppuVar38,(double)*(float *)(iVar47 + (int)local_17c * 4));
      goto code_r0x00101d1c;
    case 0x51:
      bVar4 = *(byte *)((int)ilReader + 0x8d);
      pppppuVar15 = (uint *****)(uint)bVar4;
      if ((*(uint *)((int)local_a0 + (bVar4 >> 3 & 0x1c) + 8) >> (bVar4 & 0x1f) & 1) == 0) {
        Compiler__logf(*(undefined4 *)(program + 8),"TextureStage %d misses DCLPT\n",pppppuVar15,in_r6
                     ,in_r7,in_r8,bVar4 & 0x1f,0);
      }
      pppppuVar52 = *(uint ******)(program + 0x7c);
      if ((int)*(uint ******)(program + 0x7c) < (int)pppppuVar15) {
        pppppuVar52 = pppppuVar15;
      }
      *(uint ******)(program + 0x7c) = pppppuVar52;
      *(uint *)(program + 0x84) = 1 << ((uint)pppppuVar15 & 0x3f) | *(uint *)(program + 0x84);
      ppppppuVar38[0x4d] = pppppuVar15;
      ppppppuVar38[0x4c] = pppppuVar15;
      local_bc = 0;
      pppppuVar15 = (uint *****)
                    ((int (*)())remapSelect1To0)(*(undefined4 *)((int)pppppuVar15 * 0xc + *(int *)(program + 0x78)))
      ;
      ppppppuVar38[0x4e] = pppppuVar15;
      break;
    case 0x52:
      local_bc = 0;
      ppppppuVar38[0x4d] = (uint *****)(uint)*(byte *)((int)ilReader + 0x8d);
      ppppppuVar38[0x4c] = (uint *****)(uint)*(byte *)((int)ilReader + 0x8d);
      break;
    case 0x53:
      ppppppuVar48 = (uint ******)
                     ((int (*)())FUN_000f8ccc)((uint)*ppppppuVar49 >> 0x10 & 7,*(undefined4 *)(program + 8),1);
code_r0x00101f74:
      if (ppppppuVar48 != (uint ******)0x0) goto switchD_00102044_default;
      goto switchD_0010061c_caseD_1;
    case 0x54:
      pppppuVar15 = *ppppppuVar49;
      sVar6 = *(short *)((int)*ilReader[0x19] + 2);
      uVar10 = (uint)**ilReader[0x19] >> 0x10 & 0x3f;
      FUN_000ec208(program,uVar10);
      uVar50 = *(undefined4 *)(program + 0x3ac);
      registerFile = FUN_000ec208(program,uVar10);
      in_r6 = (uint ******)0x0;
      iVar43 = FUN_00127608(uVar50,registerFile,(int)sVar6,0);
      if (((uint)pppppuVar15 >> 0x10 & 0x3fff) == 0) goto switchD_0010061c_caseD_1;
      local_bc = 0;
      *(undefined4 *)(iVar43 + 0x30) = 1;
      break;
    case 0x55:
    case 0x56:
    case 0x57:
    case 0x58:
    case 0x59:
    case 0x5a:
    case 0x5b:
    case 0x5c:
    case 0x5d:
      iVar43 = (&local_104)[uVar10 - 0x55];
      if (iVar43 == 0) {
        iVar43 = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
        *(int *)(*(int *)(program + 8) + 0x3ac) = iVar43;
        (&local_104)[uVar10 - 0x55] = iVar43;
      }
      iVar20 = IRInst__getOperandRecord(ppppppuVar38,ppppppuVar40);
      *(undefined4 *)(iVar20 + 0xc) = 0;
      *(int *)(iVar20 + 8) = iVar43;
      if (ppppppuVar40 == (uint ******)0x0) {
        in_r6 = (uint ******)0x0;
        in_r7 = (uint ******)0x0;
        in_r8 = ppppppuVar38;
        ((int (*)())FUN_000f8d50)(program,ppppppuVar37,local_124,0,0,ppppppuVar38,0);
      }
      else {
        in_r6 = ppppppuVar40;
        in_r7 = ppppppuVar38;
        ((int (*)())FUN_000f8aa0)(program,&local_178,0,ppppppuVar40,ppppppuVar38);
      }
      goto code_r0x001025c0;
    case 0x60:
      puVar32 = (undefined4 *)0x0;
      uVar10 = puVar14[2] - 1;
      if (uVar10 < (uint)puVar14[2]) {
        puVar32 = (undefined4 *)(uVar10 * 4 + puVar14[3]);
      }
      if (*(int *)*puVar32 != 0) goto switchD_0010061c_caseD_1;
      piVar18 = (int *)((int)local_17c * 4 + iVar47);
      do {
        piVar36 = local_17c;
        if (*piVar18 == 0x37) {
          piVar36 = (int *)((int)local_17c + 1);
          piVar18 = piVar18 + 1;
        }
        local_17c = (int *)((int)piVar36 + 1);
        piVar18 = piVar18 + 1;
      } while (*piVar18 != 0x26);
      local_bc = 0;
      local_17c = piVar36;
      break;
    case 0x6a:
      Compiler__fail(*(undefined4 *)(program + 8),0xf);
      goto code_r0x00101d1c;
    case 0x6b:
      iVar43 = Compiler__isOptionEnabled(*(undefined4 *)(program + 8),4);
      in_r7 = (uint ******)PTR_DAT_001e8bd8;
      if (iVar43 != 0) {
        in_r7 = (uint ******)PTR_DAT_001e8bb0;
      }
      in_r8 = ppppppuVar19;
      iVar47 = ((int (*)())FUN_000fd50c)(program,iVar47,&local_17c,ppppppuVar39,in_r7,ppppppuVar19);
      in_r6 = ppppppuVar39;
      goto code_r0x0010372c;
    case 0x6c:
      (*(code *)(*ppppppuVar38)[9])(ppppppuVar38);
      local_bc = 0;
      ppppppuVar38[0x4b] = (uint *****)0x1;
      goto code_r0x00103b3c;
    case 0x6d:
      iVar43 = IRInst__getOperandRecord(ppppppuVar38,1);
      iVar20 = *(int *)(iVar43 + 0x10);
      iVar43 = *(int *)(local_60 + -0x2c30);
      if (iVar20 != iVar43) {
        registerMap = *(undefined4 *)(program + 0x3ac);
        in_r6 = (uint ******)0x0;
        iVar21 = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
        *(int *)(*(int *)(program + 8) + 0x3ac) = iVar21;
        virtualRegister = FUN_00127608(registerMap,0,iVar21,0);
        pvVar16 = IRInst__create(0x31,*(undefined4 *)(program + 8));
        IRInst__setOperandRef(pvVar16,1,virtualRegister);
        pppppuVar52 = ppppppuVar38[0x25];
        pppppuVar15 = ppppppuVar38[0x26];
        iVar21 = IRInst__getOperandRecord(pvVar16,0);
        *(uint ******)(iVar21 + 0xc) = pppppuVar15;
        *(uint ******)(iVar21 + 8) = pppppuVar52;
        iVar21 = IRInst__getOperandRecord(pvVar16,1);
        *(int *)(iVar21 + 0x10) = iVar20;
        iVar21 = IRInst__getOperandRecord(ppppppuVar38,0);
        *(undefined4 *)((int)pvVar16 + 0x9c) = *(undefined4 *)(iVar21 + 0x10);
        IRInst__setOperandRef(ppppppuVar38,0,virtualRegister);
        FUN_000f32cc(&local_d4,iVar20);
        ppppppuVar38[0x27] = (uint *****)local_d4;
        iVar20 = IRInst__getOperandRecord(ppppppuVar38,1);
        *(int *)(iVar20 + 0x10) = iVar43;
        DList__pushFront(local_6c,pvVar16);
        goto code_r0x00101d1c;
      }
switchD_0010061c_caseD_1:
      local_bc = 0;
      break;
    case 0x6e:
      local_17c = (int *)((int)local_17c + 1);
      in_r6 = *(uint *******)(iVar47 + (int)local_17c * 4);
      in_r7 = in_r6;
      in_r8 = in_r6;
      ((int (*)())FUN_000f7870)(ppppppuVar38,program,ppppppuVar40,in_r6,in_r6,in_r6,in_r6);
code_r0x001025c0:
      ppppppuVar40 = (uint ******)((int)ppppppuVar40 + 1);
      local_bc = 0;
      break;
    case 0x70:
      uVar10 = conditionStack[1];
      piVar18 = (int *)0x0;
      if (uVar10 - 1 < uVar10) {
        piVar18 = (int *)((uVar10 - 1) * 4 + conditionStack[2]);
      }
      if (*(int *)(*piVar18 + 4) == 0) {
        puVar32 = (undefined4 *)0x0;
        compilerArenaB = *(undefined4 *)(*(int *)(program + 8) + 0x378);
        if (uVar10 - 1 < conditionStack[1]) {
          puVar32 = (undefined4 *)((uVar10 - 1) * 4 + conditionStack[2]);
        }
        uVar50 = *puVar32;
        Vector__removeAt(conditionStack,conditionStack[1] - 1);
        Arena__free(compilerArenaB,uVar50);
      }
      else {
        piVar18 = (int *)0x0;
        if (uVar10 - 1 < conditionStack[1]) {
          piVar18 = (int *)((uVar10 - 1) * 4 + conditionStack[2]);
        }
        in_r6 = (uint ******)0x0;
        *(int *)(*piVar18 + 4) = *(int *)(*piVar18 + 4) + -1;
        local_17c = (int *)((int)local_17c + -1);
        in_r8 = ppppppuVar19;
        iVar47 = ((int (*)())FUN_000fd50c)(program,iVar47,&local_17c,0,ppppppuVar48,ppppppuVar19);
        in_r7 = ppppppuVar48;
      }
code_r0x00101d1c:
      local_bc = 0;
      break;
    case 0x71:
      local_bc = 0;
      ppppppuVar38[0x50] = *(uint ******)(iVar47 + ((int)local_17c + 1) * 4);
      local_17c = (int *)((int)local_17c + 1);
    }
    goto code_r0x00103b34;
  case 7:
    bVar1 = true;
  }
  ppppppuVar19 = (uint ******)((int (*)())FUN_000f9140)(program,iVar34,(uint)*ppppppuVar49 >> 0x10 & 0x3fff);
  ((int (*)())FUN_000f9a58)(program,local_6c,*ilReader[0x19],ppppppuVar37,local_a4);
  sVar6 = *(short *)((int)*ilReader[0x19] + 2);
  registerFile = FUN_000ec208(program,(uint)**ilReader[0x19] >> 0x10 & 0x3f);
  iVar43 = IRInst__getOperandRecord(ppppppuVar19,0);
  *(undefined4 *)(iVar43 + 0xc) = registerFile;
  *(int *)(iVar43 + 8) = (int)sVar6;
  in_r7 = (uint ******)0x0;
  in_r6 = (uint ******)*ilReader[0x19];
  in_r8 = ppppppuVar19;
  ((int (*)())FUN_000f8d50)(program,ppppppuVar37,0,in_r6,0,ppppppuVar19,0);
  iVar43 = ((int (*)())FUN_000f8970)(iVar34,*(undefined4 *)(*(int *)(*(int *)(program + 8) + 0x30c) + 0xc));
  ppppppuVar38 = (uint ******)(iVar43 + 1);
  if (1 < (int)ppppppuVar38) {
    ppppppuVar40 = (uint ******)((int)((unsigned char *)0x0) + 1);
    iVar43 = 0;
    local_60 = &DAT_001ad5d8;
    do {
      local_178 = *(uint *******)(local_60 + -0x2c30);
      in_r8 = (uint ******)&local_174;
      ((int (*)())FUN_000fb3d4)(program,local_68,ppppppuVar49,*(undefined4 *)(iVar43 + (int)ilReader[0x1b]),
                   ppppppuVar37,&local_174,&local_13c);
      uVar10 = **(uint **)(iVar43 + (int)ilReader[0x1b]);
      if ((((uVar10 & 0x3f0000) == 0x100000) && (*(int *)(program + 8) != 0)) &&
         ((*(uint *)(*(int *)(*(int *)(program + 8) + 0x30c) + 8) & 0x80) != 0)) {
        iVar47 = 0xf;
      }
      else {
        iVar47 = (int)(short)**(uint **)(iVar43 + (int)ilReader[0x1b]);
      }
      registerFile = FUN_000ec208(program,uVar10 >> 0x10 & 0x3f);
      iVar20 = IRInst__getOperandRecord(ppppppuVar19,ppppppuVar40);
      *(undefined4 *)(iVar20 + 0xc) = registerFile;
      *(int *)(iVar20 + 8) = iVar47;
      if ((!bVar1) &&
         (iVar47 = OpcodeTraits__instFlagBit2(*(undefined4 *)(program + 8),ppppppuVar19), iVar47 != 0)) {
        if (ppppppuVar40 == (uint ******)((int)((unsigned char *)0x0) + 1U)) {
          puVar12 = &UNK_001aa9d4;
        }
        else {
          puVar12 = &DAT_001aa9cc;
        }
        local_178 = (uint ******)*puVar12;
      }
      in_r6 = ppppppuVar40;
      in_r7 = ppppppuVar19;
      ((int (*)())FUN_000f8aa0)(program,&local_178,*(undefined4 *)(iVar43 + (int)ilReader[0x1b]),ppppppuVar40,
                   ppppppuVar19);
      ppppppuVar40 = (uint ******)((int)ppppppuVar40 + 1);
      iVar43 = iVar43 + 4;
    } while (ppppppuVar38 != ppppppuVar40);
  }
  local_b8 = IRInst__countWrittenComponents(ppppppuVar19);
  if (bVar1) {
    iVar20 = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
    *(int *)(*(int *)(program + 8) + 0x3ac) = iVar20;
    pppppuVar52 = ppppppuVar19[0x25];
    pppppuVar15 = ppppppuVar19[0x26];
    iVar43 = IRInst__getOperandRecord(ppppppuVar19,0);
    *(int *)(iVar43 + 8) = iVar20;
    *(undefined4 *)(iVar43 + 0xc) = 0;
    iVar43 = OpcodeTraits__instFlagBit2(*(undefined4 *)(program + 8),ppppppuVar19);
    iVar47 = IRInst__getOperandRecord(ppppppuVar19,0);
    ppppppuVar40 = *(uint *******)(iVar47 + 0x10);
    local_178 = ppppppuVar40;
    if (1 < local_b8) {
      local_7c = (uint ****)&local_188;
      iVar47 = 0;
      local_58 = local_7c;
      do {
        iVar21 = SelectWord__firstWrittenComponent(local_178);
        iVar22 = ((int (*)())FUN_000f9140)(program,iVar34,(uint)*ppppppuVar49 >> 0x10 & 0x3fff);
        ppppuVar45 = local_58;
        if (0 < (int)ppppppuVar38) {
          ppppppuVar48 = (uint ******)0x0;
          do {
            in_r6 = ppppppuVar48;
            IRInst__copyOperandFrom(iVar22,ppppppuVar48,ppppppuVar19,ppppppuVar48);
            if (iVar43 != 0) {
              iVar23 = IRInst__getOperandRecord(iVar22,ppppppuVar48);
              pppppuVar11 = *(uint ******)(iVar23 + 0x10);
              if (ppppppuVar48 == (uint ******)((int)((unsigned char *)0x0) + 1U)) {
                local_124 = (uint *****)
                            CONCAT31((int3)((uint)pppppuVar11 >> 8),
                                     *(undefined1 *)((int)ppppuVar45 + iVar21 + 100));
              }
              else if (ppppppuVar48 == (uint ******)((int)((unsigned char *)0x0) + 2U)) {
                local_124 = (uint *****)
                            CONCAT13(*(undefined1 *)((int)ppppuVar45 + iVar21 + 100),
                                     (int3)pppppuVar11);
              }
              else {
                local_124 = pppppuVar11;
                if (ppppppuVar48 == (uint ******)((int)((unsigned char *)0x0) + 3U)) {
                  (*(unsigned short *)((unsigned char *)&(local_124) + 0)) = (undefined2)((uint)pppppuVar11 >> 0x10);
                  (*(unsigned short *)((unsigned char *)&(local_124) + 2)) =
                       CONCAT11(*(undefined1 *)((int)ppppuVar45 + iVar21 + 100),(char)pppppuVar11);
                }
              }
              pppppuVar11 = local_124;
              iVar23 = IRInst__getOperandRecord(iVar22,ppppppuVar48);
              *(uint ******)(iVar23 + 0x10) = pppppuVar11;
            }
            ppppppuVar48 = (uint ******)((int)ppppppuVar48 + 1);
          } while (ppppppuVar38 != ppppppuVar48);
        }
        *(undefined4 *)(iVar22 + 0x9c) = *(undefined4 *)(PTR_DAT_001e8b64 + iVar21 * 4);
        *(undefined1 *)((int)local_7c + iVar21 + 0x10) = 1;
        *(uint ******)(iVar22 + 0x120) = ppppppuVar19[0x48];
        DList__pushBack(local_68,iVar22);
        iVar47 = iVar47 + 1;
      } while (local_b8 + -1 != iVar47);
    }
    ppppppuVar19[0x27] = (uint *****)local_178;
    if ((iVar43 != 0) && (iVar34 = SelectWord__firstWrittenComponent(local_178), 1 < (int)ppppppuVar38)) {
      ppppppuVar49 = (uint ******)((int)((unsigned char *)0x0) + 1);
      do {
        iVar43 = IRInst__getOperandRecord(ppppppuVar19,ppppppuVar49);
        ppppppuVar48 = *(uint *******)(iVar43 + 0x10);
        local_104 = ppppppuVar48;
        if (ppppppuVar49 == (uint ******)((int)((unsigned char *)0x0) + 1U)) {
          local_104 = (uint ******)
                      CONCAT31((int3)((uint)ppppppuVar48 >> 8),
                               *(undefined1 *)((int)&local_104 + iVar34));
        }
        else if (ppppppuVar49 == (uint ******)((int)((unsigned char *)0x0) + 2U)) {
          local_104 = (uint ******)
                      CONCAT13(*(undefined1 *)((int)&local_104 + iVar34),(int3)ppppppuVar48);
        }
        else if (ppppppuVar49 == (uint ******)((int)((unsigned char *)0x0) + 3U)) {
          (*(unsigned short *)((unsigned char *)&(local_104) + 0)) = (undefined2)((uint)ppppppuVar48 >> 0x10);
          (*(unsigned short *)((unsigned char *)&(local_104) + 2)) = CONCAT11(*(undefined1 *)((int)&local_104 + iVar34),(char)ppppppuVar48);
        }
        ppppppuVar48 = local_104;
        iVar43 = IRInst__getOperandRecord(ppppppuVar19,ppppppuVar49);
        ppppppuVar49 = (uint ******)((int)ppppppuVar49 + 1);
        *(uint *******)(iVar43 + 0x10) = ppppppuVar48;
      } while (ppppppuVar38 != ppppppuVar49);
    }
    pvVar16 = IRInst__create(0x31,*(undefined4 *)(program + 8));
    iVar34 = IRInst__getOperandRecord(pvVar16,0);
    *(uint ******)(iVar34 + 0xc) = pppppuVar15;
    *(uint ******)(iVar34 + 8) = pppppuVar52;
    *(uint *******)((int)pvVar16 + 0x9c) = ppppppuVar40;
    iVar34 = IRInst__getOperandRecord(pvVar16,1);
    *(int *)(iVar34 + 8) = iVar20;
    *(undefined4 *)(iVar34 + 0xc) = 0;
    DList__pushFront(local_6c,pvVar16);
  }
  piVar18 = *(int **)(*(int *)(program + 8) + 0x30c);
  iVar34 = (**(code **)(*piVar18 + 0x34))(piVar18,ppppppuVar19);
  if (iVar34 == 0) {
code_r0x001002dc:
    pvVar16 = (void *)0x0;
  }
  else {
    iVar34 = IRInst__getOperandRecord(ppppppuVar19,0);
    iVar47 = 0;
    iVar43 = 0;
    local_178 = *(uint *******)(iVar34 + 0x10);
    in_r8 = (uint ******)&local_104;
    local_104 = *(uint *******)(iVar34 + 0x10);
    iVar20 = 4;
    in_r7 = (uint ******)&local_178;
    iVar34 = -1;
    do {
      iVar21 = iVar34;
      if (*(char *)(iVar43 + (int)in_r8) == '\0') {
        iVar21 = iVar43;
        if ((iVar47 != 0) && (iVar21 = iVar34, 0 < iVar47)) {
          *(undefined1 *)(iVar43 + (int)in_r7) = 1;
        }
        iVar47 = iVar47 + 1;
      }
      iVar43 = iVar43 + 1;
      iVar20 = iVar20 + -1;
      iVar34 = iVar21;
    } while (iVar20 != 0);
    if (iVar47 < 2) goto code_r0x001002dc;
    iVar43 = 4;
    ppppppuVar19[0x27] = (uint *****)local_178;
    iVar34 = 0;
    in_r7 = (uint ******)&local_124;
    do {
      *(char *)(iVar34 + (int)in_r7) = (char)iVar21;
      iVar34 = iVar34 + 1;
      iVar43 = iVar43 + -1;
    } while (iVar43 != 0);
    pvVar16 = IRInst__create(0x31,*(undefined4 *)(program + 8));
    pppppuVar15 = ppppppuVar19[0x25];
    pppppuVar52 = ppppppuVar19[0x26];
    iVar34 = IRInst__getOperandRecord(pvVar16,0);
    *(uint ******)(iVar34 + 0xc) = pppppuVar52;
    *(uint ******)(iVar34 + 8) = pppppuVar15;
    pppppuVar52 = ppppppuVar19[0x25];
    *(uint *******)((int)pvVar16 + 0x9c) = local_104;
    pppppuVar11 = ppppppuVar19[0x26];
    iVar34 = IRInst__getOperandRecord(pvVar16,1);
    pppppuVar15 = local_124;
    *(uint ******)(iVar34 + 0xc) = pppppuVar11;
    *(uint ******)(iVar34 + 8) = pppppuVar52;
    iVar34 = IRInst__getOperandRecord(pvVar16,1);
    *(uint ******)(iVar34 + 0x10) = pppppuVar15;
  }
  iVar43 = *(int *)(local_14c + 8);
  iVar34 = local_14c;
  while (iVar47 = iVar43, iVar47 != 0) {
    DList__unlink(iVar34);
    ((int (*)())FUN_000f92fc)(program,iVar34,currentBlock);
    iVar34 = iVar47;
    iVar43 = *(int *)(iVar47 + 8);
  }
  ((int (*)())FUN_000f92fc)(program,ppppppuVar19,currentBlock);
  if (pvVar16 != (void *)0x0) {
    ((int (*)())FUN_000f92fc)(program,pvVar16,currentBlock);
  }
  iVar43 = *(int *)(local_164 + 8);
  iVar34 = local_164;
  while (iVar47 = iVar43, iVar47 != 0) {
    DList__unlink(iVar34);
    ((int (*)())FUN_000f92fc)(program,iVar34,currentBlock);
    iVar34 = iVar47;
    iVar43 = *(int *)(iVar47 + 8);
  }
  goto switchD_000fdaf0_caseD_2;
switchD_0010061c_caseD_0:
  local_bc = 1;
code_r0x00103b34:
  if (ppppppuVar38 != (uint ******)0x0) {
code_r0x00103b3c:
    iVar43 = (*(code *)(*ppppppuVar38)[5])(ppppppuVar38);
    if ((uint ******)(iVar43 + 1U) == ppppppuVar40) {
      ((int (*)())FUN_000f92fc)(program,ppppppuVar38,currentBlock);
      ppppppuVar38 = (uint ******)0x0;
      ppppppuVar40 = (uint ******)0x0;
      local_178 = *(uint *******)(local_60 + -0x2c30);
      local_124 = *(uint ******)(local_78 + -0x2bfc);
    }
  }
  if (local_bc != 0) goto code_r0x00103bb0;
  local_17c = (int *)((int)local_17c + 1);
  goto code_r0x001005f4;
code_r0x00103bb0:
  iVar43 = *(int *)(local_164 + 8);
  iVar34 = local_164;
  while (iVar47 = iVar43, iVar47 != 0) {
    DList__unlink(iVar34);
    ((int (*)())FUN_000f92fc)(program,iVar34,currentBlock);
    iVar34 = iVar47;
    iVar43 = *(int *)(iVar47 + 8);
  }
  if (puVar12 != (uint *)0x0) {
    Arena__free(puVar14[4],puVar14[3]);
    Arena__free(*puVar14,puVar14);
  }
  if (ppppppuVar19 != (uint ******)0x0) {
    Arena__free(puVar24[4],puVar24[3]);
    Arena__free(*puVar24,puVar24);
  }
  goto switchD_000fdaf0_caseD_2;
}
#undef local_14c
#undef local_164
