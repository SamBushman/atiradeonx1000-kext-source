#include "decls.h"

/* IRInst__sourcesAreSameValue @ 0x11e7ec (168 bytes) */
int IRInst__sourcesAreSameValue(inst)
  int inst;
{
  int iVar1;
  int operandVReg;
  int operandVReg2;
  
  if (((*(int *)(inst + 0x84) != 1) || (iVar1 = IRInst__getOperandSource(inst,1), iVar1 == 0)) &&
     (1 < *(int *)(inst + 0x84))) {
    iVar1 = 2;
    do {
      operandVReg = IRInst__getOperandSource(inst,iVar1 + -1);
      operandVReg2 = IRInst__getOperandSource(inst,iVar1);
      if ((operandVReg != operandVReg2) || (operandVReg = IRInst__getOperandSource(inst,iVar1), operandVReg == 0)) {
        return 0;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 <= *(int *)(inst + 0x84));
  }
  return 1;
}

/* FUN_0011e894 @ 0x11e894 (180 bytes) */
int FUN_0011e894(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  uint loopIndex;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 900);
  iVar1 = *(int *)(iVar4 + 8);
  do {
    if (iVar1 == 0) {
      return 1;
    }
    iVar1 = FUN_000e79b8(iVar4);
    if (iVar1 != 0) {
      iVar1 = 0;
      for (loopIndex = 1; loopIndex <= *(uint *)(*(int *)(iVar4 + 0xd4) + 4); loopIndex = loopIndex + 1) {
        iVar2 = *(int *)(*(int *)(*(int *)(iVar4 + 0xd4) + 8) + iVar1);
        if ((iVar2 != 0) && (iVar2 = Block__hasMultipleSuccessors(iVar2), iVar2 != 0)) {
          return 0;
        }
        iVar1 = iVar1 + 4;
      }
    }
    iVar4 = *(int *)(iVar4 + 8);
    iVar1 = *(int *)(iVar4 + 8);
  } while( true );
}

/* Program__isPreassignedHwReg @ 0x11e948 (64 bytes) */
int Program__isPreassignedHwReg(program, param_2)
  undefined4 program;
  int param_2;
{
  int iVar1;
  
  if (((*(uint *)(param_2 + 0x14) & 0x40) != 0) &&
     (iVar1 = Program__isHwRegAllowed(program,*(undefined4 *)(param_2 + 0x94)), iVar1 != 0)) {
    return 1;
  }
  return 0;
}

/* ValueKey__loadSourceDefinitions @ 0x11e988 (280 bytes) */
int ValueKey__loadSourceDefinitions(ctx, param_2)
  int ctx;
  undefined4 param_2;
{
  int iVar1;
  int iVar2;
  int loopIndex;
  int iVar4;
  int iVar5;
  int *piVar6;
  
  loopIndex = 1;
  iVar2 = *(int *)(ctx + 0xb0);
  if (0 < *(int *)(iVar2 + 0x84)) {
    iVar4 = 0x18;
    iVar5 = ctx;
    do {
      iVar2 = iVar4 + iVar2;
      loopIndex = loopIndex + 1;
      iVar4 = iVar4 + 0x18;
      iVar1 = ((int (*)())VReg__currentDefinition)(*(undefined4 *)(iVar2 + 0x8c),param_2,*(uint *)(ctx + 0x238));
      iVar2 = *(int *)(ctx + 0xb0);
      *(undefined4 *)(iVar5 + 0x214) = *(undefined4 *)(iVar1 + 0xb0);
      iVar5 = iVar5 + 4;
    } while (loopIndex <= *(int *)(iVar2 + 0x84));
  }
  iVar2 = Compiler__isOptionEnabled(*(undefined4 *)(ctx + 0x238),7);
  if (((iVar2 != 0) && (iVar2 = Compiler__isOptionEnabled(*(undefined4 *)(ctx + 0x238),9), iVar2 != 0)) &&
     (*(int *)(*(int *)(ctx + 0xb0) + 0x80) != 0)) {
    piVar6 = *(int **)(*(int *)(ctx + 0xb0) + 0x8c);
    iVar2 = (**(code **)(*piVar6 + 0x18))(piVar6);
    if (((iVar2 != 0) && (*(int *)(*(int *)(ctx + 0xb0) + 0x84) != 0)) &&
       ((*(uint *)(*(int *)(ctx + 0xb0) + 0x14) & 0x200) == 0)) {
      iVar2 = ((int (*)())VReg__currentDefinition)(piVar6,param_2,*(uint *)(ctx + 0x238));
      *(undefined4 *)(loopIndex * 4 + ctx + 0x210) = *(undefined4 *)(iVar2 + 0xb0);
    }
  }
  return;
}

/* FUN_0011eaa0 @ 0x11eaa0 (672 bytes) */
int FUN_0011eaa0(program)
  int program;
{
  uint frontierNumber;
  uint defBlockNumber;
  uint frontierBitIndex;
  int *frontierBlock;
  int *definedBitsetCursor;
  int defInstB;
  int *visitedBlocks;
  int registerRecord;
  int bitsetByteSize;
  uint registerId;
  int defByteOffsetB;
  int defByteOffset;
  int clearCountB;
  int clearCountA;
  undefined4 arena;
  uint loopIndex;
  int *definedInBlocksAlias;
  int defInstA;
  int dominanceFrontier;
  undefined4 *allocation;
  undefined4 *visitedBitsetAlloc;
  undefined4 *instAlloc;
  uint definedBitWord;
  int *visitedBitsetCursor;
  uint defBlockWordOffset;
  int frontierByteOffset;
  int *definedInBlocks;
  uint frontierWordOffset;
  int iVar13;
  undefined4 *puVar14;
  int blockCount;
  undefined4 predecessorCount;
  uint clearCountC;
  uint bitsetWordCount;
  /* issue #64 live-repro: iteratorState is the iterator state object passed to FUN_00194938/
   * FUN_00194a94, which read/write program[0..4] - 5 words, 0x14 bytes. iteratorState was declared
   * only 16 bytes (4 words); iteratorCurrent sits exactly at the missing 5th word by its own hex name
   * (0x60-0x50=0x10). The main loop below re-reads iteratorCurrent as its own continuation value
   * (iVar13 = iteratorCurrent) right after each FUN_00194938 call - with the two locals not contiguous,
   * that call's real update to program[4] never reaches iteratorCurrent, so iVar13 never changes and the
   * while(iVar13!=0) loop spins forever (confirmed live: the rebuilt driver hangs at 99% CPU
   * inside FUN_00194938, never returning). Merged into one 0x14-byte buffer. */
  unsigned char iteratorState [0x14];
#define iteratorCurrent (*(int *)(iteratorState + 0x10))
  
  blockCount = *(int *)(*(int *)(program + 0x3bc) + 4);
  arena = *(undefined4 *)(*(int *)(program + 8) + 0x378);
  bitsetWordCount = blockCount + 0x1fU >> 5;
  bitsetByteSize = bitsetWordCount * 4 + 0xc;
  allocation = (undefined4 *)Arena__alloc(arena,bitsetByteSize);
  definedInBlocks = allocation + 1;
  *allocation = arena;
  allocation[1] = bitsetWordCount;
  allocation[2] = blockCount;
  if (bitsetWordCount != 0) {
    definedInBlocksAlias = definedInBlocks;
    clearCountC = bitsetWordCount;
    if (bitsetWordCount == 0) {
      clearCountC = 1;
    }
    do {
      definedInBlocksAlias[2] = 0;
      definedInBlocksAlias = definedInBlocksAlias + 1;
      clearCountC = clearCountC - 1;
    } while (clearCountC != 0);
  }
  arena = *(undefined4 *)(*(int *)(program + 8) + 0x378);
  visitedBitsetAlloc = (undefined4 *)Arena__alloc(arena,bitsetByteSize);
  visitedBlocks = visitedBitsetAlloc + 1;
  *visitedBitsetAlloc = arena;
  visitedBitsetAlloc[1] = bitsetWordCount;
  visitedBitsetAlloc[2] = blockCount;
  if (bitsetWordCount != 0) {
    visitedBitsetCursor = visitedBlocks;
    if (bitsetWordCount == 0) {
      bitsetWordCount = 1;
    }
    do {
      visitedBitsetCursor[2] = 0;
      visitedBitsetCursor = visitedBitsetCursor + 1;
      bitsetWordCount = bitsetWordCount - 1;
    } while (bitsetWordCount != 0);
  }
  FUN_00194a94(iteratorState,*(undefined4 *)(*(int *)(program + 0x3ac) + 4));
  registerRecord = iteratorCurrent;
  while (registerRecord != 0) {
    registerId = *(uint *)(registerRecord + 0x1c);
    iteratorCurrent = registerRecord;
    if ((((-1 < (int)registerId) &&
         ((*(uint *)((registerId >> 3 & 0x1ffffffc) + *(int *)(program + 0x3b0) + 8) >> (registerId & 0x1f)
          & 1) != 0)) || (*(int *)(registerRecord + 4) == 0x3b)) ||
       ((*(int *)(registerRecord + 4) == 0x2c && (*(int *)(program + 0x3b4) != 0)))) {
      clearCountA = *visitedBlocks;
      if (clearCountA != 0) {
        visitedBitsetCursor = visitedBlocks;
        if (clearCountA == 0) {
          clearCountA = 1;
        }
        do {
          visitedBitsetCursor[2] = 0;
          visitedBitsetCursor = visitedBitsetCursor + 1;
          clearCountA = clearCountA + -1;
        } while (clearCountA != 0);
      }
      clearCountB = *definedInBlocks;
      if (clearCountB != 0) {
        definedBitsetCursor = definedInBlocks;
        if (clearCountB == 0) {
          clearCountB = 1;
        }
        do {
          definedBitsetCursor[2] = 0;
          definedBitsetCursor = definedBitsetCursor + 1;
          clearCountB = clearCountB + -1;
        } while (clearCountB != 0);
      }
      defByteOffset = 0;
      for (loopIndex = 1; loopIndex <= *(uint *)(*(int *)(registerRecord + 0x18) + 4); loopIndex = loopIndex + 1) {
        defInstA = *(int *)(*(int *)(*(int *)(registerRecord + 0x18) + 8) + defByteOffset);
        if ((*(uint *)(defInstA + 0x14) & 1) != 0) {
          defBlockNumber = *(uint *)(*(int *)(defInstA + 0x158) + 0xb4);
          defBlockWordOffset = defBlockNumber >> 3 & 0x1ffffffc;
          *(uint *)((int)definedInBlocks + defBlockWordOffset + 8) =
               1 << (defBlockNumber & 0x1f) | *(uint *)((int)definedInBlocks + defBlockWordOffset + 8);
        }
        defByteOffset = defByteOffset + 4;
      }
      defByteOffsetB = 0;
      for (loopIndex = 1; loopIndex <= *(uint *)(*(int *)(registerRecord + 0x18) + 4); loopIndex = loopIndex + 1) {
        defInstB = *(int *)(*(int *)(*(int *)(registerRecord + 0x18) + 8) + defByteOffsetB);
        if ((*(uint *)(defInstB + 0x14) & 1) != 0) {
          defInstB = *(int *)(defInstB + 0x158);
          frontierByteOffset = 0;
          for (frontierNumber = 1; dominanceFrontier = *(int *)(defInstB + 0xf8), frontierNumber <= *(uint *)(dominanceFrontier + 4);
              frontierNumber = frontierNumber + 1) {
            frontierBlock = *(int **)(*(int *)(dominanceFrontier + 8) + frontierByteOffset);
            frontierWordOffset = (uint)frontierBlock[0x2d] >> 3 & 0x1ffffffc;
            frontierBitIndex = frontierBlock[0x2d] & 0x1f;
            if ((*(uint *)((int)visitedBlocks + frontierWordOffset + 8) >> frontierBitIndex & 1) == 0) {
              arena = *(undefined4 *)(*(int *)(program + 8) + 0x374);
              instAlloc = (undefined4 *)Arena__alloc(arena,0x168);
              *instAlloc = arena;
              puVar14 = instAlloc + 1;
              IRPhiNode__ctor_10a398(puVar14,*(undefined4 *)(program + 8));
              predecessorCount = Block__predecessorCount(frontierBlock);
              instAlloc[0x22] = predecessorCount;
              IRInst__setOperandRef(puVar14,0,registerRecord);
              if (*(int *)(registerRecord + 4) == 0x2c) {
                instAlloc[0x28] = UNK_001afee0;
              }
              definedBitWord = *(uint *)((int)definedInBlocks + frontierWordOffset + 8);
              if ((definedBitWord >> frontierBitIndex & 1) == 0) {
                *(uint *)((int)definedInBlocks + frontierWordOffset + 8) = 1 << frontierBitIndex | definedBitWord;
                ((int (*)())FUN_0012306c)(registerRecord,puVar14);
              }
              Block__prependInst(frontierBlock,puVar14);
              (**(code **)(*frontierBlock + 0x48))(frontierBlock);
              *(uint *)((int)visitedBlocks + frontierWordOffset + 8) = 1 << frontierBitIndex | *(uint *)((int)visitedBlocks + frontierWordOffset + 8)
              ;
            }
            frontierByteOffset = frontierByteOffset + 4;
          }
        }
        defByteOffsetB = defByteOffsetB + 4;
      }
    }
    FUN_00194938(iteratorState);
    registerRecord = iteratorCurrent;
  }
  if (definedInBlocks != (int *)0x0) {
    Arena__free(*allocation,allocation);
  }
  if (visitedBlocks != (int *)0x0) {
    Arena__free(*visitedBitsetAlloc,visitedBitsetAlloc);
  }
  return;
}
#undef iteratorCurrent

/* ValueKey__foldMovSources @ 0x11eec8 (1072 bytes) */
int ValueKey__foldMovSources(ctx, param_2)
  int ctx;
  int param_2;
{
  int *ctxVectorAtb0;
  int flagBit7Result;
  int operandSource;
  int operandRecord;
  int constPropEnabled;
  uint uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  char *pcVar11;
  int *piVar12;
  int a2;
  int iVar13;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40 [2];
  undefined4 local_38 [5];
  
  constPropEnabled = Compiler__isOptionEnabled(*(undefined4 *)(param_2 + 8),6);
  if (constPropEnabled != 0) {
    ctxVectorAtb0 = *(int **)(ctx + 0xb0);
    iVar3 = ctx;
    for (a2 = 1; iVar7 = (**(code **)(*ctxVectorAtb0 + 0x14))(ctxVectorAtb0), a2 <= iVar7; a2 = a2 + 1) {
      piVar12 = (int *)(iVar3 + 0x214);
      iVar7 = (**(code **)(**(int **)(iVar3 + 0x214) + 100))(*(int **)(iVar3 + 0x214));
      if ((((iVar7 == 0) ||
           (iVar7 = RegKind__flagBit0(*(undefined4 *)(*(int *)(iVar3 + 0x214) + 0x98)), iVar7 == 0)) ||
          (iVar7 = ((int (*)())Program__isPreassignedHwReg)(param_2,*(undefined4 *)(iVar3 + 0x214)), iVar7 != 0)) ||
         ((iVar7 = *(int *)(iVar3 + 0x214), *(int *)(iVar7 + 0x120) != 0 ||
          (*(int *)(iVar7 + 0x124) != 0)))) {
LAB_0011f2a8:
        ctxVectorAtb0 = *(int **)(ctx + 0xb0);
      }
      else {
        IRInst__getOperandRecord(iVar7,0);
        iVar7 = IRInst__operandKindClass(iVar7,0);
        if (iVar7 != 0) goto LAB_0011f2a8;
        iVar13 = *(int *)(iVar3 + 0x214);
        operandSource = IRInst__getOperandSource(iVar13,1);
        if (operandSource == 0) {
          uVar5 = *(undefined4 *)(iVar13 + 0xb0);
        }
        else {
          operandSource = IRInst__getOperandSource(iVar13,1);
          uVar5 = *(undefined4 *)(operandSource + 0x98);
        }
        flagBit7Result = RegKind__flagBit7(uVar5);
        if (flagBit7Result == 0) {
          iVar13 = *piVar12;
          operandSource = IRInst__getOperandSource(iVar13,1);
          if (operandSource == 0) {
            uVar5 = *(undefined4 *)(iVar13 + 0xb0);
          }
          else {
            operandSource = IRInst__getOperandSource(iVar13,1);
            uVar5 = *(undefined4 *)(operandSource + 0x98);
          }
          iVar7 = RegKind__flagBit8(uVar5);
          if (iVar7 == 0) goto LAB_0011f2a8;
        }
        iVar7 = *piVar12;
        IRInst__getOperandRecord(iVar7,1);
        iVar7 = IRInst__operandKindClass(iVar7,1);
        if (iVar7 == 0) {
          iVar7 = *piVar12;
LAB_0011f054:
          iVar7 = IRInst__getOperandSource(iVar7,1);
          iVar13 = a2 * 0x18;
          uVar2 = *(uint *)(iVar13 + *(int *)(ctx + 0xb0) + 0xa0);
          uVar8 = uVar2 >> 1 & 1;
          uVar1 = *(uint *)(*piVar12 + 0xb8) & 1;
          uVar9 = *(uint *)(*piVar12 + 0xb8) >> 1 & 1;
          if (uVar8 == 0) {
            uVar8 = uVar9;
            if ((uVar2 & 1) == 0) {
              if (uVar1 != 0) goto LAB_0011f0bc;
            }
            else if (uVar1 == 0) {
LAB_0011f0bc:
              uVar9 = 1;
              goto LAB_0011f0c4;
            }
            uVar9 = 0;
          }
LAB_0011f0c4:
          piVar4 = *(int **)(*(int *)(ctx + 0x238) + 0x30c);
          iVar6 = (**(code **)(*piVar4 + 0x11c))
                            (piVar4,*(int *)(ctx + 0xb0),a2,iVar7,uVar8,uVar9,
                             *(int *)(ctx + 0x238));
          if ((iVar6 == 0) ||
             (iVar6 = FUN_000f45f8(*(undefined4 *)(ctx + 0xb0),a2,*piVar12,param_2), iVar6 == 0)
             ) goto LAB_0011f2a8;
          *(int *)(param_2 + 0xa4) = *(int *)(param_2 + 0xa4) + 1;
          iVar6 = *(int *)(ctx + 0xb0);
          iVar10 = iVar6 + iVar13 + 0x80;
          if ((*(uint *)(iVar10 + 0x20) & 2) == 0) {
            if ((*(uint *)(*piVar12 + 0xb8) & 2) != 0) {
              IROperand__setModifierBits(iVar10 + 0xc,2,1);
              iVar6 = *(int *)(ctx + 0xb0);
            }
            if ((*(uint *)(iVar6 + iVar13 + 0x80 + 0x20) & 1) == 0) {
              if ((*(uint *)(*piVar12 + 0xb8) & 1) == 0) goto LAB_0011f190;
LAB_0011f188:
              uVar5 = 1;
            }
            else {
              if ((*(uint *)(*piVar12 + 0xb8) & 1) == 0) goto LAB_0011f188;
LAB_0011f190:
              uVar5 = 0;
            }
            IROperand__setModifierBits(iVar13 + iVar6 + 0x8c,1,uVar5);
            iVar6 = *(int *)(ctx + 0xb0);
          }
          operandRecord = IRInst__getOperandRecord(iVar6,a2);
          local_48 = *(undefined4 *)(operandRecord + 0x10);
          iVar13 = OpcodeTraits__flagBit2(*(undefined4 *)(*(int *)(*(int *)(ctx + 0xb0) + 0x88) + 8),
                                *(undefined4 *)(ctx + 0x238));
          if (iVar13 == 0) {
            SelectWord__maskUnused(local_38,local_48,*(undefined4 *)(iVar3 + 0x228));
            local_48 = local_38[0];
          }
          operandRecord = IRInst__getOperandRecord(*piVar12,1);
          local_44 = *(undefined4 *)(operandRecord + 0x10);
          local_40[0] = 0x4040404;
          iVar13 = 0;
          pcVar11 = (char *)(a2 * 4 + ctx + 0x224);
          iVar6 = 4;
          do {
            if (*pcVar11 != '\0') {
              *(undefined1 *)((int)local_40 + iVar13) =
                   *(undefined1 *)((int)local_40 + (*(byte *)((int)&local_48 + iVar13) - 4));
            }
            uVar5 = local_40[0];
            iVar13 = iVar13 + 1;
            pcVar11 = pcVar11 + 1;
            iVar6 = iVar6 + -1;
          } while (iVar6 != 0);
          if (a2 == 0) {
            *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x9c) = local_40[0];
          }
          else {
            iVar13 = IRInst__getOperandRecord(*(int *)(ctx + 0xb0),a2);
            *(undefined4 *)(iVar13 + 0x10) = uVar5;
          }
          uVar5 = *(undefined4 *)(iVar7 + 0x8c);
          IRInst__setOperandRef(*(undefined4 *)(ctx + 0xb0),a2,uVar5);
          ((int (*)())VReg__addUse)(uVar5,a2,*(undefined4 *)(ctx + 0xb0));
          ctxVectorAtb0 = *(int **)(ctx + 0xb0);
          *piVar12 = iVar7;
        }
        else {
          iVar7 = IRInst__operandKindClass(*piVar12,1);
          if (iVar7 != 1) goto LAB_0011f2a8;
          ctxVectorAtb0 = *(int **)(ctx + 0xb0);
          iVar7 = *piVar12;
          if (ctxVectorAtb0[0x56] == *(int *)(iVar7 + 0x158)) goto LAB_0011f054;
        }
      }
      iVar3 = iVar3 + 4;
    }
  }
  return;
}

/* Program__tryEliminateRedundantCopy @ 0x11f2f8 (640 bytes) */
int Program__tryEliminateRedundantCopy(param_1, inst, param_3)
  int param_1;
  int *inst;
  undefined4 param_3;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int *piVar4;
  
  iVar1 = Compiler__isOptionEnabled(*(undefined4 *)(param_1 + 8),5);
  if ((iVar1 != 0) && (iVar1 = (**(code **)(*inst + 100))(inst), iVar1 != 0)) {
    for (iVar1 = 1; iVar2 = (**(code **)(*inst + 0x14))(inst), iVar1 <= iVar2;
        iVar1 = iVar1 + 1) {
      if ((inst[iVar1 * 6 + 0x28] & 1U) != 0) {
        return 0;
      }
      if ((inst[iVar1 * 6 + 0x28] & 2U) != 0) {
        return 0;
      }
      iVar2 = IRInst__isSourceSelectIdentity(inst,iVar1);
      if (iVar2 == 0) {
        return 0;
      }
    }
    if ((inst[0x48] == 0) && (inst[0x49] == 0)) {
      if ((inst[0x20] != 0) &&
         (((iVar1 = RegKind__flagBit0(inst[0x26]), iVar1 != 0 && ((inst[5] & 2U) == 0)) &&
          (iVar1 = (**(code **)(*inst + 0x50))(inst), iVar1 == 0)))) {
        iVar1 = 4;
        piVar4 = inst;
        do {
          if ((uint)(*(byte *)(piVar4 + 0x27) - 2) < 2) {
            return 0;
          }
          piVar4 = (int *)((int)piVar4 + 1);
          iVar1 = iVar1 + -1;
        } while (iVar1 != 0);
      }
      IRInst__getOperandRecord(inst,0);
      iVar1 = IRInst__operandKindClass(inst,0);
      if (((iVar1 == 0) && ((inst[5] & 2U) == 0)) &&
         (((inst[5] & 0x200U) == 0 && (iVar1 = RegKind__flagBit0(inst[0x26]), iVar1 != 0)))) {
        iVar1 = IRInst__getOperandSource(inst,1);
        if (iVar1 == 0) {
          iVar1 = inst[0x2c];
        }
        else {
          iVar1 = IRInst__getOperandSource(inst,1);
          iVar1 = *(int *)(iVar1 + 0x98);
        }
        iVar1 = RegKind__flagBit6(iVar1);
        if (iVar1 == 0) {
          iVar1 = IRInst__getOperandSource(inst,1);
          if (iVar1 == 0) {
            iVar1 = inst[0x2c];
          }
          else {
            iVar1 = IRInst__getOperandSource(inst,1);
            iVar1 = *(int *)(iVar1 + 0x98);
          }
          if (((iVar1 != 0x31) && (iVar1 = ((int (*)())Program__isPreassignedHwReg)(param_1,inst), iVar1 == 0)) &&
             (*(int *)(param_1 + 0xa0) < *(int *)(*(uint *)(param_1 + 8) + 0x650))) {
            uVar3 = ((int (*)())VReg__currentDefinition)(inst[0x29],*(undefined4 *)(param_1 + 0x3a0),
                                 *(uint *)(param_1 + 8));
            Block__recordDefinition(param_3,inst[0x23],uVar3);
            (**(code **)(*inst + 0xc))
                      (inst,0,*(undefined4 *)(param_1 + 8),in_r6,in_r7,in_r8,
                       *(code **)(*inst + 0xc));
            inst[5] = inst[5] | 0x400;
            *(int *)(param_1 + 0xa0) = *(int *)(param_1 + 0xa0) + 1;
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

/* FUN_0011f578 @ 0x11f578 (588 bytes) */
int FUN_0011f578(param_1)
  int param_1;
{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  int *a0;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  uint loopIndex;
  /* issue #64 live-repro: &local_44 is the same small growable-array header (capacity/count/
   * data-pointer) Vector__elementRefGrow/Vector__removeAt use elsewhere in this file - local_44, local_40 and
   * local_3c are exactly its three words by their own hex offsets (0x44-0x40=4, 0x40-0x3c=4).
   * local_38 is a separate, unrelated value (assigned from param_1 before this header is even
   * built) and stays its own declaration. Left as separate scalars, Vector__removeAt's shrink inside
   * the do-loop below never reaches the same memory local_40/local_44's own loop condition reads,
   * so the loop never sees the array become empty and spins forever (confirmed live: the rebuilt
   * driver hangs at 99-100% CPU inside Vector__removeAt, stuck at its own return statement, never
   * making real progress). Merged the three header words into one 0xc-byte buffer. */
  unsigned char local_44_buf [0xc];
#define local_44 (*(uint *)(local_44_buf + 0x00))
#define local_40 (*(uint *)(local_44_buf + 0x04))
#define local_3c (*(undefined4 **)(local_44_buf + 0x08))
  undefined4 local_38;
  
  local_38 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  local_44 = 2;
  local_40 = 0;
  local_3c = (undefined4 *)Arena__alloc(local_38,8);
  *(undefined4 *)(*(int *)(param_1 + 0x3a0) + 0x114) = 0x10;
  uVar5 = *(undefined4 *)(param_1 + 0x3a0);
  if (local_40 < local_44) {
    local_3c[local_40] = 0;
    puVar3 = local_3c + local_40;
    local_40 = local_40 + 1;
  }
  else {
    puVar3 = (undefined4 *)Vector__elementRefGrow(&local_44,local_40);
  }
  *puVar3 = uVar5;
  do {
    if (local_44 == 0) {
      puVar3 = (undefined4 *)Vector__elementRefGrow(&local_44,0);
    }
    else {
      puVar3 = local_3c;
      if (local_40 == 0) {
        *local_3c = 0;
        local_40 = 1;
      }
    }
    piVar6 = (int *)*puVar3;
    Vector__removeAt(&local_44,0);
    iVar4 = 0;
    for (loopIndex = 1; loopIndex <= *(uint *)(piVar6[0x34] + 4); loopIndex = loopIndex + 1) {
      a0 = *(int **)(*(int *)(piVar6[0x34] + 8) + iVar4);
      if ((a0 != (int *)0x0) && (a0[0x45] == 0)) {
        if (piVar6[0x2e] < a0[0x2e]) {
          a0[0x45] = piVar6[0x45] << 2;
        }
        else {
          iVar2 = (**(code **)(*a0 + 0x34))(a0);
          if (iVar2 == 0) {
            iVar2 = (**(code **)(*piVar6 + 0x24))(piVar6);
            if (iVar2 == 0) {
              iVar2 = (**(code **)(*a0 + 0x28))(a0);
              if (iVar2 != 0) {
                a0[0x45] = piVar6[0x45] << 1;
                goto LAB_0011f744;
              }
              iVar2 = piVar6[0x45];
            }
            else {
              uVar1 = piVar6[0x45];
              iVar2 = ((int)uVar1 >> 1) + (uint)((int)uVar1 < 0 && (uVar1 & 1) != 0);
              if (iVar2 < 1) {
                iVar2 = 1;
              }
            }
            a0[0x45] = iVar2;
          }
          else {
            a0[0x45] = *(int *)(a0[0x4b] + 0x114);
          }
        }
LAB_0011f744:
        if (local_40 < local_44) {
          local_3c[local_40] = 0;
          puVar3 = local_3c + local_40;
          local_40 = local_40 + 1;
        }
        else {
          puVar3 = (undefined4 *)Vector__elementRefGrow(&local_44,local_40);
        }
        *puVar3 = a0;
      }
      iVar4 = iVar4 + 4;
    }
    if (local_40 == 0) {
      Arena__free(local_38,local_3c);
      return;
    }
  } while( true );
}
#undef local_44
#undef local_40
#undef local_3c

/* FUN_0011f7fc @ 0x11f7fc (164 bytes) */
int FUN_0011f7fc(param_1, param_2, vector)
  int param_1;
  int param_2;
  uint *vector;
{
  uint vectorCount;
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = *(int *)(param_1 + 0x474);
  if (iVar2 < *(int *)(param_2 + 0x150)) {
    uVar3 = *(int *)(param_2 + 0x150) - iVar2;
  }
  else {
    vectorCount = vector[1];
    if (vectorCount < *vector) {
      _memset(vectorCount * 4 + vector[2],0,4);
      piVar1 = (int *)(vectorCount * 4 + vector[2]);
      vector[1] = vectorCount + 1;
    }
    else {
      piVar1 = (int *)Vector__elementRefGrow(vector,vectorCount);
    }
    *piVar1 = param_2;
    uVar3 = vector[1];
    *(uint *)(param_2 + 0x150) = uVar3 + iVar2;
  }
  return uVar3 - 1;
}

/* FUN_0011f8a0 @ 0x11f8a0 (756 bytes) */
int FUN_0011f8a0(vector, param_2, param_3, param_4, param_5, block, compiler, param_8, vector2, param_10)
  uint *vector;
  int param_2;
  int *param_3;
  int param_4;
  uint param_5;
  int block;
  int compiler;
  int param_8;
  uint *vector2;
  uint param_10;
{
  uint vectorCount;
  undefined4 *vectorElementRef;
  bool bVar1;
  int *newInst;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  int operandRecord;
  undefined4 uVar7;
  code *pcVar8;
  int *piVar9;
  
  newInst = (int *)IRInst__create(0x31,compiler);
  newInst[0x25] = param_2;
  newInst[0x26] = 0;
  if (param_5 < *vector) {
    vectorCount = vector[1];
    if (vectorCount <= param_5) {
      _memset(vectorCount * 4 + vector[2],0,(param_5 - vectorCount) * 4 + 4);
      vector[1] = param_5 + 1;
    }
  }
  else {
    Vector__elementRefGrow(vector,param_5);
  }
  if (param_5 < *vector) {
    vectorCount = vector[1];
    if (vectorCount <= param_5) {
      _memset(vectorCount * 4 + vector[2],0,(param_5 - vectorCount) * 4 + 4);
      vector[1] = param_5 + 1;
    }
    vectorElementRef = (undefined4 *)(param_5 * 4 + vector[2]);
  }
  else {
    vectorElementRef = (undefined4 *)Vector__elementRefGrow(vector,param_5);
  }
  IRInst__setOperandSource(newInst,1,*vectorElementRef,0,compiler);
  if (param_4 != 0) {
    newInst[5] = newInst[5] | 0x40;
  }
  piVar9 = *(int **)(*(int *)(compiler + COMP_target) + 100);
  pcVar8 = *(code **)(*piVar9 + 0x20);
  if (param_5 < *vector) {
    vectorCount = vector[1];
    if (vectorCount <= param_5) {
      _memset(vectorCount * 4 + vector[2],0,(param_5 - vectorCount) * 4 + 4);
      vector[1] = param_5 + 1;
    }
    vectorElementRef = (undefined4 *)(param_5 * 4 + vector[2]);
  }
  else {
    vectorElementRef = (undefined4 *)Vector__elementRefGrow(vector,param_5);
  }
  iVar5 = (*pcVar8)(piVar9,*vectorElementRef);
  if ((iVar5 != 0) && ((*(uint *)(block + 0xc) & 0x200) == 0)) {
    newInst[5] = newInst[5] | 0x1000;
    *(uint *)(block + 0xc) = *(uint *)(block + 0xc) | 0x200;
  }
  Block__appendInst(block,newInst);
  iVar5 = DAT_001afee4;
  newInst[5] = newInst[5] | 0x40000000;
  if (*param_3 != iVar5) {
    newInst[0x27] = *param_3;
    iVar5 = 0;
    do {
      operandRecord = IRInst__getOperandRecord(newInst,0);
      if (*(char *)(iVar5 + operandRecord + 0x10) == '\x01') {
        (**(code **)(*newInst + 0x88))(newInst,1,iVar5,4);
      }
      bVar1 = iVar5 != 3;
      iVar5 = iVar5 + 1;
    } while (bVar1);
  }
  if (param_8 != 0) {
    if (param_10 < *vector2) {
      uVar3 = vector2[1];
      if (uVar3 <= param_10) {
        _memset(uVar3 * 4 + vector2[2],0,(param_10 - uVar3) * 4 + 4);
        vector2[1] = param_10 + 1;
      }
      puVar4 = (undefined4 *)(param_10 * 4 + vector2[2]);
    }
    else {
      puVar4 = (undefined4 *)Vector__elementRefGrow(vector2,param_10);
    }
    uVar7 = ((int (*)())FUN_0011f7fc)(*(undefined4 *)(compiler + COMP_currentProgram),newInst,vector);
    *puVar4 = uVar7;
  }
  return;
}

/* Program__foldUselessPhis @ 0x11fb94 (944 bytes) */
int Program__foldUselessPhis(program)
  int program;
{
  int uniqueSource;
  int loopIndex;
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  int *piVar8;
  int iVar9;
  /* issue #64 (auto): growable-vector header (capacity/count/data-pointer/arena) used with Vector__elementRefGrow - vecCapacity/vecCount/vecData/vecArena are its four words by their own hex offsets. Vector__elementRefGrow unconditionally reads all four on every call (even its "no grow needed" path reallocs+copies+frees), so they must be one contiguous buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */
  unsigned char local_38_buf [0x10];
  #define vecCapacity (*(uint *)(local_38_buf + 0x00))
  #define vecCount (*(uint *)(local_38_buf + 0x04))
  #define vecData (*(int *)(local_38_buf + 0x08))
  #define vecArena (*(undefined4 *)(local_38_buf + 0x0c))
  
  vecArena = *(undefined4 *)(*(int *)(program + 8) + 0x378);
  vecCount = 0;
  vecCapacity = 2;
  vecData = Arena__alloc(vecArena,8);
  iVar5 = *(int *)(program + 900);
  for (iVar3 = *(int *)(*(int *)(program + 900) + 8); iVar3 != 0; iVar3 = *(int *)(iVar3 + 8)) {
    piVar8 = *(int **)(iVar5 + 0x98);
    piVar4 = (int *)piVar8[2];
    if ((int *)piVar8[2] != (int *)0x0) {
      do {
        piVar1 = piVar4;
        if ((piVar8[5] & 1U) != 0) {
          iVar3 = (**(code **)(*piVar8 + 0x7c))(piVar8);
          uVar7 = vecCount;
          if (iVar3 == 0) {
            piVar1 = (int *)piVar8[2];
          }
          else {
            if (vecCount < vecCapacity) {
              iVar9 = vecCount * 4;
              _memset(iVar9 + vecData,0,4);
              vecCount = uVar7 + 1;
              piVar4 = (int *)(iVar9 + vecData);
            }
            else {
              piVar4 = (int *)Vector__elementRefGrow(&vecCapacity,vecCount);
            }
            *piVar4 = iVar3;
            *(undefined4 *)(iVar3 + 0x134) = 1;
            piVar1 = (int *)piVar8[2];
          }
        }
        piVar4 = (int *)piVar1[2];
        piVar8 = piVar1;
      } while ((int *)piVar1[2] != (int *)0x0);
      iVar3 = *(int *)(iVar5 + 8);
    }
    iVar5 = iVar3;
  }
  while ((vecCount != 0 && (*(int *)(program + 0x22c) < *(int *)(*(int *)(program + 8) + 0x66c)))) {
    uVar7 = vecCount - 1;
    puVar2 = (undefined4 *)0x0;
    if (uVar7 < vecCount) {
      puVar2 = (undefined4 *)(uVar7 * 4 + vecData);
    }
    piVar4 = (int *)*puVar2;
    Vector__removeAt(&vecCapacity,uVar7);
    piVar4[0x4d] = 0;
    uniqueSource = IRPhi__getUniqueSource(piVar4);
    if (uniqueSource != 0) {
      while (piVar8 = (int *)piVar4[4], piVar8[1] != 0) {
        if (*piVar8 == 0) {
          puVar2 = (undefined4 *)Vector__elementRefGrow(piVar8,0);
        }
        else {
          puVar2 = (undefined4 *)piVar8[2];
        }
        piVar8 = (int *)*puVar2;
        iVar9 = 1;
        iVar3 = piVar8[0x22];
        if (*(int *)(iVar3 + 8) == 0x8e) {
          loopIndex = 1;
          if (0 < piVar8[0x21]) {
            do {
              piVar1 = (int *)IRInst__getOperandSource(piVar8,loopIndex);
              if (piVar1 == piVar4) {
                IRInst__setOperandSource(piVar8,loopIndex,uniqueSource,1,*(undefined4 *)(program + 8));
              }
              loopIndex = loopIndex + 1;
            } while (loopIndex <= piVar8[0x21]);
            iVar3 = piVar8[0x22];
          }
          if (((*(int *)(iVar3 + 8) == 0x8e) &&
              (piVar1 = (int *)(**(code **)(*piVar8 + 0x7c))(piVar8), piVar4 != piVar1)) &&
             (iVar3 = (**(code **)(*piVar8 + 0x7c))(piVar8), *(int *)(iVar3 + 0x134) == 0)) {
            uVar6 = (**(code **)(*piVar8 + 0x7c))(piVar8);
            uVar7 = vecCount;
            if (vecCount < vecCapacity) {
              iVar3 = vecCount * 4;
              _memset(iVar3 + vecData,0,4);
              vecCount = uVar7 + 1;
              puVar2 = (undefined4 *)(iVar3 + vecData);
            }
            else {
              puVar2 = (undefined4 *)Vector__elementRefGrow(&vecCapacity,vecCount);
            }
            *puVar2 = uVar6;
            iVar3 = (**(code **)(*piVar8 + 0x7c))(piVar8);
            *(undefined4 *)(iVar3 + 0x134) = 0;
          }
        }
        else {
          for (; iVar3 = (**(code **)(*piVar8 + 0x14))(piVar8), iVar9 <= iVar3; iVar9 = iVar9 + 1) {
            piVar1 = (int *)IRInst__getOperandSource(piVar8,iVar9);
            if (piVar1 == piVar4) {
              IRInst__setOperandSource(piVar8,iVar9,uniqueSource,1,*(undefined4 *)(program + 8));
            }
          }
          if (((piVar8[5] & 0x200U) != 0) &&
             (piVar1 = (int *)IRInst__getOperandSource(piVar8,piVar8[0x21]), piVar1 == piVar4)) {
            IRInst__setExtraOperandSource(piVar8,uniqueSource,1,*(undefined4 *)(program + 8));
          }
        }
      }
      IRInst__useCount(piVar4,program);
      (**(code **)(*piVar4 + 0xc))(piVar4,1,*(undefined4 *)(program + 8));
      *(int *)(program + 0x22c) = *(int *)(program + 0x22c) + 1;
    }
  }
  Arena__free(vecArena,vecData);
  return;
}
#undef vecCapacity
#undef vecCount
#undef vecData
#undef vecArena

/* FUN_0011ff7c @ 0x11ff7c (3416 bytes) */
int FUN_0011ff7c(pass, block, vector, vector2, vector3, vector4, vector5, tempCounter)
  int pass;
  int *block;
  uint *vector;
  uint *vector2;
  uint *vector3;
  uint *vector4;
  uint *vector5;
  int *tempCounter;
{
  uint lastPendingIdx2;
  uint pendingCountG;
  uint readyDstId;
  uint readyCountB;
  uint pendingCountF;
  int newTempId;
  undefined4 *pendingTopRef;
  undefined4 *locationSlotRefB;
  undefined4 *instTableSlotRef;
  undefined4 *readySlotRef;
  undefined4 *pendingSlotRefA;
  uint srcId;
  uint scanIndex;
  uint instTableCountC;
  uint locationCountC;
  uint dstLocationB;
  uint pendingCountE;
  uint locationCountB;
  uint instFlagBit6;
  uint instTableCountB;
  uint instTableCapacity;
  uint lastPendingIndex;
  uint srcLocation;
  int *pendingSlotRefC;
  int successorQuery34;
  int blockQuery38;
  int predQuery2c;
  int pendingByteOffset;
  int phiInst;
  undefined4 cycleCopy;
  undefined4 dstLocation;
  undefined4 cycleDstId;
  undefined4 packedCopyB;
  undefined4 dstRegister;
  int *targetBlockForCopy;
  int *instTableSlotRefB;
  int *instTableSlotRefA;
  int *readySlotRefA;
  uint scanCount;
  uint readyCountA;
  uint decodedDstId;
  uint pendingCountB;
  uint instTableCount;
  uint locationCount;
  uint scanDstId;
  uint vectorCount2;
  uint vectorCount;
  int *vectorElementRef;
  undefined4 phiOperandIndexForPredecessorResult;
  undefined4 predecessor2;
  int *successor;
  int *predecessor;
  int operandRecord2;
  int *operandVReg;
  undefined4 packedCopyA;
  int *nextPhiInst;
  int srcKindFlag;
  int operandRecord;
  uint copyDstId;
  uint copySrcId;
  uint *locationSlotRef;
  undefined4 *flagSlotRef;
  uint pendingCountD;
  int *phiListCursor;
  int predecessorVector;
  undefined4 compiler;
  int predByteOffset;
  uint predNumber;
  undefined4 zeroPredecessorIndex;
  uint pendingCountA;
  int copyEmitted;
  int predBlock;
  
  vector[1] = 0;
  vector2[1] = 0;
  vector3[1] = 0;
  vector4[1] = 0;
  vector5[1] = 0;
  predecessorVector = block[0x34];
  predByteOffset = 0;
  predBlock = 0;
  for (predNumber = 1; predNumber <= *(uint *)(predecessorVector + 4); predNumber = predNumber + 1) {
    predBlock = *(int *)(predByteOffset + *(int *)(predecessorVector + 8));
    if (predBlock != 0) {
      phiOperandIndexForPredecessorResult = Block__phiOperandIndexForPredecessor(predBlock,block);
      phiListCursor = *(int **)(predBlock + 0x98);
      for (nextPhiInst = (int *)(*(int **)(predBlock + 0x98))[2]; nextPhiInst != (int *)0x0;
          nextPhiInst = (int *)nextPhiInst[2]) {
        if ((phiListCursor[5] & 1U) == 0) goto LAB_00120400;
        phiInst = (**(code **)(*phiListCursor + 0x7c))(phiListCursor);
        if (phiInst == 0) {
LAB_001203fc:
          nextPhiInst = (int *)phiListCursor[2];
        }
        else {
          operandVReg = (int *)IRInst__getOperandSource(phiInst,phiOperandIndexForPredecessorResult);
          if ((((operandVReg[0x20] == 0) || (srcKindFlag = RegKind__flagBit0(operandVReg[0x26]), srcKindFlag == 0)) ||
              ((operandVReg[5] & 2U) != 0)) ||
             (srcKindFlag = (**(code **)(*operandVReg + 0x50))(operandVReg), srcKindFlag != 0)) {
            srcKindFlag = (**(code **)(*operandVReg + 0x60))(operandVReg);
            if (srcKindFlag != 0) goto LAB_001200cc;
            goto LAB_001203fc;
          }
          srcKindFlag = IRInst__getOperandRecord(phiInst,0);
          operandRecord = IRInst__getOperandRecord(operandVReg,0);
          if (((srcKindFlag == operandRecord) && (*(int *)(phiInst + 0x98) == operandVReg[0x26])) &&
             ((*(uint *)(phiInst + 0x14) >> 6 & 1) == ((uint)operandVReg[5] >> 6 & 1))) goto LAB_001203fc;
LAB_001200cc:
          copyDstId = ((int (*)())FUN_0011f7fc)(pass,phiInst,vector5);
          copySrcId = ((int (*)())FUN_0011f7fc)(pass,operandVReg,vector5);
          pendingCountA = vector2[1];
          if (pendingCountA < *vector2) {
            _memset(pendingCountA * 4 + vector2[2],0,4);
            vector2[1] = pendingCountA + 1;
            pendingSlotRefC = (int *)(pendingCountA * 4 + vector2[2]);
          }
          else {
            pendingSlotRefC = (int *)Vector__elementRefGrow(vector2,pendingCountA);
          }
          *pendingSlotRefC = copyDstId + copySrcId * 0x10000;
          if (copySrcId < *vector3) {
            locationCount = vector3[1];
            if (locationCount <= copySrcId) {
              _memset(locationCount * 4 + vector3[2],0,(copySrcId - locationCount) * 4 + 4);
              vector3[1] = copySrcId + 1;
            }
            locationSlotRef = (uint *)(copySrcId * 4 + vector3[2]);
          }
          else {
            locationSlotRef = (uint *)Vector__elementRefGrow(vector3,copySrcId);
          }
          *locationSlotRef = copySrcId;
          if (copyDstId < *vector3) {
            locationCount = vector3[1];
            if (locationCount <= copyDstId) {
              _memset(locationCount * 4 + vector3[2],0,(copyDstId - locationCount) * 4 + 4);
              vector3[1] = copyDstId + 1;
            }
            locationSlotRef = (uint *)(copyDstId * 4 + vector3[2]);
          }
          else {
            locationSlotRef = (uint *)Vector__elementRefGrow(vector3,copyDstId);
          }
          *locationSlotRef = copyDstId;
          if (copySrcId < *vector) {
            vectorCount = vector[1];
            if (vectorCount <= copySrcId) {
              _memset(vectorCount * 4 + vector[2],0,(copySrcId - vectorCount) * 4 + 4);
              vector[1] = copySrcId + 1;
            }
            flagSlotRef = (undefined4 *)(copySrcId * 4 + vector[2]);
          }
          else {
            flagSlotRef = (undefined4 *)Vector__elementRefGrow(vector,copySrcId);
          }
          *flagSlotRef = 1;
          if (copySrcId < *vector3) {
            locationCount = vector3[1];
            if (locationCount <= copySrcId) {
              _memset(locationCount * 4 + vector3[2],0,(copySrcId - locationCount) * 4 + 4);
              vector3[1] = copySrcId + 1;
            }
            locationSlotRef = (uint *)(copySrcId * 4 + vector3[2]);
          }
          else {
            locationSlotRef = (uint *)Vector__elementRefGrow(vector3,copySrcId);
          }
          dstLocationB = *locationSlotRef;
          if (dstLocationB < *vector5) {
            instTableCount = vector5[1];
            if (instTableCount <= dstLocationB) {
              _memset(instTableCount * 4 + vector5[2],0,(dstLocationB - instTableCount) * 4 + 4);
              vector5[1] = dstLocationB + 1;
            }
          }
          else {
            Vector__elementRefGrow(vector5,dstLocationB);
          }
          if (copyDstId < *vector3) {
            locationCountC = vector3[1];
            if (locationCountC <= copyDstId) {
              _memset(locationCountC * 4 + vector3[2],0,(copyDstId - locationCountC) * 4 + 4);
              vector3[1] = copyDstId + 1;
            }
            locationSlotRef = (uint *)(copyDstId * 4 + vector3[2]);
          }
          else {
            locationSlotRef = (uint *)Vector__elementRefGrow(vector3,copyDstId);
          }
          srcLocation = *locationSlotRef;
          if (srcLocation < *vector5) {
            instTableCountC = vector5[1];
            if (srcLocation < instTableCountC) goto LAB_001203fc;
            _memset(instTableCountC * 4 + vector5[2],0,(srcLocation - instTableCountC) * 4 + 4);
            vector5[1] = srcLocation + 1;
            nextPhiInst = (int *)phiListCursor[2];
          }
          else {
            Vector__elementRefGrow(vector5,srcLocation);
            nextPhiInst = (int *)phiListCursor[2];
          }
        }
LAB_00120400:
        phiListCursor = nextPhiInst;
      }
      predecessorVector = block[0x34];
    }
    predByteOffset = predByteOffset + 4;
  }
  pendingCountF = vector2[1];
  lastPendingIndex = pendingCountF - 1;
  if (-1 < (int)lastPendingIndex) {
    pendingByteOffset = lastPendingIndex * 4;
    scanIndex = 0;
    do {
      if (lastPendingIndex < *vector2) {
        pendingCountB = vector2[1];
        if (pendingCountB <= lastPendingIndex) {
          _memset(pendingCountB * 4 + vector2[2],0,(lastPendingIndex - pendingCountB) * 4 + 4);
          vector2[1] = lastPendingIndex + 1;
        }
        pendingSlotRefA = (undefined4 *)(pendingByteOffset + vector2[2]);
      }
      else {
        pendingSlotRefA = (undefined4 *)Vector__elementRefGrow(vector2,lastPendingIndex);
      }
      packedCopyA = *pendingSlotRefA;
      decodedDstId = FUN_0011e6ec(packedCopyA);
      if (decodedDstId < *vector) {
        vectorCount2 = vector[1];
        if (vectorCount2 <= decodedDstId) {
          _memset(vectorCount2 * 4 + vector[2],0,(decodedDstId - vectorCount2) * 4 + 4);
          vector[1] = decodedDstId + 1;
        }
        vectorElementRef = (int *)(decodedDstId * 4 + vector[2]);
      }
      else {
        vectorElementRef = (int *)Vector__elementRefGrow(vector,decodedDstId);
      }
      if (*vectorElementRef == 0) {
        readyCountA = vector4[1];
        if (readyCountA < *vector4) {
          _memset(readyCountA * 4 + vector4[2],0,4);
          vector4[1] = readyCountA + 1;
          readySlotRef = (undefined4 *)(readyCountA * 4 + vector4[2]);
        }
        else {
          readySlotRef = (undefined4 *)Vector__elementRefGrow(vector4,readyCountA);
        }
        *readySlotRef = packedCopyA;
        Vector__removeAt(vector2,lastPendingIndex);
      }
      scanIndex = scanIndex + 1;
      lastPendingIndex = lastPendingIndex - 1;
      pendingByteOffset = pendingByteOffset + -4;
    } while (pendingCountF != scanIndex);
  }
  readyCountB = vector4[1];
  do {
    if (readyCountB != 0) goto LAB_00120b04;
    do {
      if (vector2[1] == 0) {
        *(uint *)(pass + 0x474) = *(int *)(pass + 0x474) + vector5[1];
        return;
      }
LAB_00120b04:
      while (readyCountB != 0) {
        lastPendingIndex = readyCountB - 1;
        if (lastPendingIndex < *vector4) {
          if (readyCountB <= lastPendingIndex) {
            _memset(readyCountB * 4 + vector4[2],0,(lastPendingIndex - readyCountB) * 4 + 4);
            vector4[1] = readyCountB;
          }
          readySlotRefA = (int *)(lastPendingIndex * 4 + vector4[2]);
        }
        else {
          readySlotRefA = (int *)Vector__elementRefGrow(vector4,lastPendingIndex);
        }
        srcId = *readySlotRefA >> 0x10;
        readyDstId = FUN_0011e6ec(*readySlotRefA);
        Vector__removeAt(vector4,lastPendingIndex);
        instTableCapacity = *vector5;
        if (readyDstId < instTableCapacity) {
          instTableCount = vector5[1];
          if (instTableCount <= readyDstId) {
            _memset(instTableCount * 4 + vector5[2],0,(readyDstId - instTableCount) * 4 + 4);
            instTableCapacity = *vector5;
            vector5[1] = readyDstId + 1;
          }
          instTableSlotRefA = (int *)(readyDstId * 4 + vector5[2]);
        }
        else {
          instTableSlotRefA = (int *)Vector__elementRefGrow(vector5,readyDstId);
          instTableCapacity = *vector5;
        }
        dstRegister = *(undefined4 *)(*instTableSlotRefA + 0x94);
        if (readyDstId < instTableCapacity) {
          instTableCountB = vector5[1];
          if (instTableCountB <= readyDstId) {
            _memset(instTableCountB * 4 + vector5[2],0,(readyDstId - instTableCountB) * 4 + 4);
            vector5[1] = readyDstId + 1;
          }
          instTableSlotRef = (undefined4 *)(readyDstId * 4 + vector5[2]);
        }
        else {
          instTableSlotRef = (undefined4 *)Vector__elementRefGrow(vector5,readyDstId);
        }
        operandRecord2 = IRInst__getOperandRecord(*instTableSlotRef,0);
        copyEmitted = *(int *)(operandRecord2 + 0x10);
        if (readyDstId < *vector5) {
          instTableCountB = vector5[1];
          if (instTableCountB <= readyDstId) {
            _memset(instTableCountB * 4 + vector5[2],0,(readyDstId - instTableCountB) * 4 + 4);
            vector5[1] = readyDstId + 1;
          }
          instTableSlotRefB = (int *)(readyDstId * 4 + vector5[2]);
        }
        else {
          instTableSlotRefB = (int *)Vector__elementRefGrow(vector5,readyDstId);
        }
        instFlagBit6 = *(uint *)(*instTableSlotRefB + 0x14) >> 6 & 1;
        predecessor = (int *)Block__getPredecessor(block,0);
        predQuery2c = (**(code **)(*predecessor + 0x2c))(predecessor);
        if (predQuery2c == 0) {
LAB_0012079c:
          blockQuery38 = (**(code **)(*block + 0x38))(block);
          if (blockQuery38 != 0) {
            zeroPredecessorIndex = 0;
            targetBlockForCopy = block;
            goto LAB_00120890;
          }
          if (srcId < *vector3) {
            locationCount = vector3[1];
            if (locationCount <= srcId) {
              _memset(locationCount * 4 + vector3[2],0,(srcId - locationCount) * 4 + 4);
              vector3[1] = srcId + 1;
            }
            locationSlotRefB = (undefined4 *)(srcId * 4 + vector3[2]);
          }
          else {
            locationSlotRefB = (undefined4 *)Vector__elementRefGrow(vector3,srcId);
          }
          compiler = *(undefined4 *)(pass + 8);
          dstLocation = *locationSlotRefB;
          targetBlockForCopy = block;
        }
        else {
          successor = (int *)Block__getSuccessor(block,0);
          successorQuery34 = (**(code **)(*successor + 0x34))(successor);
          if (successorQuery34 == 0) goto LAB_0012079c;
          predecessor2 = Block__getPredecessor(block,0);
          predecessor2 = Block__getPredecessor(predecessor2,0);
          if (srcId < *vector3) {
            locationCount = vector3[1];
            if (locationCount <= srcId) {
              _memset(locationCount * 4 + vector3[2],0,(srcId - locationCount) * 4 + 4);
              vector3[1] = srcId + 1;
            }
            locationSlotRefB = (undefined4 *)(srcId * 4 + vector3[2]);
          }
          else {
            locationSlotRefB = (undefined4 *)Vector__elementRefGrow(vector3,srcId);
          }
          ((int (*)())FUN_0011f8a0)(vector5,dstRegister,&copyEmitted,instFlagBit6,*locationSlotRefB,predecessor2,*(undefined4 *)(pass + 8),0,0
                       ,0xffffffff);
          targetBlockForCopy = (int *)Block__getPredecessor(block,0);
          zeroPredecessorIndex = 1;
LAB_00120890:
          targetBlockForCopy = (int *)Block__getPredecessor(targetBlockForCopy,zeroPredecessorIndex);
          if (srcId < *vector3) {
            locationCount = vector3[1];
            if (locationCount <= srcId) {
              _memset(locationCount * 4 + vector3[2],0,(srcId - locationCount) * 4 + 4);
              vector3[1] = srcId + 1;
            }
            locationSlotRefB = (undefined4 *)(srcId * 4 + vector3[2]);
          }
          else {
            locationSlotRefB = (undefined4 *)Vector__elementRefGrow(vector3,srcId);
          }
          dstLocation = *locationSlotRefB;
          compiler = *(undefined4 *)(pass + 8);
        }
        ((int (*)())FUN_0011f8a0)(vector5,dstRegister,&copyEmitted,instFlagBit6,dstLocation,targetBlockForCopy,compiler,0,0,0xffffffff);
        if (copyEmitted == 0) {
          if (srcId < *vector3) {
            locationCountB = vector3[1];
            if (locationCountB <= srcId) {
              _memset(locationCountB * 4 + vector3[2],0,(srcId - locationCountB) * 4 + 4);
              vector3[1] = srcId + 1;
            }
            locationSlotRef = (uint *)(srcId * 4 + vector3[2]);
          }
          else {
            locationSlotRef = (uint *)Vector__elementRefGrow(vector3,srcId);
          }
          *locationSlotRef = readyDstId;
        }
        pendingCountG = vector2[1];
        lastPendingIndex = pendingCountG - 1;
        if (-1 < (int)lastPendingIndex) {
          pendingByteOffset = lastPendingIndex * 4;
          scanCount = 0;
          do {
            if (lastPendingIndex < *vector2) {
              pendingCountD = vector2[1];
              if (pendingCountD <= lastPendingIndex) {
                _memset(pendingCountD * 4 + vector2[2],0,(lastPendingIndex - pendingCountD) * 4 + 4);
                vector2[1] = lastPendingIndex + 1;
              }
              pendingSlotRefA = (undefined4 *)(pendingByteOffset + vector2[2]);
            }
            else {
              pendingSlotRefA = (undefined4 *)Vector__elementRefGrow(vector2,lastPendingIndex);
            }
            packedCopyB = *pendingSlotRefA;
            scanDstId = FUN_0011e6ec(packedCopyB);
            if (srcId == scanDstId) {
              readyCountB = vector4[1];
              if (readyCountB < *vector4) {
                _memset(readyCountB * 4 + vector4[2],0,4);
                vector4[1] = readyCountB + 1;
                readySlotRef = (undefined4 *)(readyCountB * 4 + vector4[2]);
              }
              else {
                readySlotRef = (undefined4 *)Vector__elementRefGrow(vector4,readyCountB);
              }
              *readySlotRef = packedCopyB;
              Vector__removeAt(vector2,lastPendingIndex);
              break;
            }
            scanCount = scanCount + 1;
            lastPendingIndex = lastPendingIndex - 1;
            pendingByteOffset = pendingByteOffset + -4;
          } while (pendingCountG != scanCount);
        }
        readyCountB = vector4[1];
      }
      pendingCountE = vector2[1];
    } while (pendingCountE == 0);
    lastPendingIdx2 = pendingCountE - 1;
    if (lastPendingIdx2 < *vector2) {
      if (pendingCountE <= lastPendingIdx2) {
        _memset(pendingCountE * 4 + vector2[2],0,(lastPendingIdx2 - pendingCountE) * 4 + 4);
        vector2[1] = pendingCountE;
      }
      pendingTopRef = (undefined4 *)(lastPendingIdx2 * 4 + vector2[2]);
    }
    else {
      pendingTopRef = (undefined4 *)Vector__elementRefGrow(vector2,lastPendingIdx2);
    }
    cycleCopy = *pendingTopRef;
    cycleDstId = FUN_0011e6ec(cycleCopy);
    Vector__removeAt(vector2,lastPendingIdx2);
    newTempId = *(int *)(*(int *)(pass + 8) + 0x3c4) + 1;
    *(int *)(*(int *)(pass + 8) + 0x3c4) = newTempId;
    predecessor = (int *)Block__getPredecessor(block,0);
    predQuery2c = (**(code **)(*predecessor + 0x2c))(predecessor);
    if (predQuery2c == 0) {
LAB_00120cb8:
      (**(code **)(*block + 0x38))(block);
    }
    else {
      successor = (int *)Block__getSuccessor(block,0);
      successorQuery34 = (**(code **)(*successor + 0x34))(successor);
      if (successorQuery34 == 0) goto LAB_00120cb8;
    }
    ((int (*)())FUN_0011f8a0)(vector5,newTempId,&DAT_001afee4,0,cycleDstId,block,*(undefined4 *)(pass + 8),1,vector3
                 ,cycleDstId);
    readyCountB = vector4[1];
    if (readyCountB < *vector4) {
      _memset(readyCountB * 4 + vector4[2],0,4);
      vector4[1] = readyCountB + 1;
      readySlotRef = (undefined4 *)(readyCountB * 4 + vector4[2]);
    }
    else {
      readySlotRef = (undefined4 *)Vector__elementRefGrow(vector4,readyCountB);
    }
    *readySlotRef = cycleCopy;
    *tempCounter = *tempCounter + 1;
    readyCountB = vector4[1];
  } while( true );
}

/* FUN_00120cd4 @ 0x120cd4 (384 bytes) */
int FUN_00120cd4(pass)
  int pass;
{
  undefined4 *puVar1;
  int listCount;
  undefined4 *allocation;
  undefined4 *vectorAlloc;
  undefined4 *vectorAlloc2;
  undefined4 *vectorAlloc3;
  undefined4 *vectorAlloc4;
  undefined4 *in_r6;
  undefined4 *in_r7;
  undefined4 *in_r8;
  undefined4 *in_r9;
  int *in_r10;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  int loopIndex;
  undefined4 *puVar12;
  undefined4 arena;
  int local_48 [7];
  
  puVar1 = (undefined4 *)FUN_000ec4f0(pass);
  listCount = DList__count(pass + 0x37c);
  arena = *(undefined4 *)(*(int *)(pass + 8) + 0x378);
  allocation = (undefined4 *)Arena__alloc(arena,0x14);
  *allocation = arena;
  allocation[1] = 2;
  allocation[4] = arena;
  allocation[2] = 0;
  arena = Arena__alloc(arena,8);
  allocation[3] = arena;
  arena = *(undefined4 *)(*(int *)(pass + 8) + 0x378);
  vectorAlloc = (undefined4 *)Arena__alloc(arena,0x14);
  puVar8 = vectorAlloc + 1;
  *vectorAlloc = arena;
  vectorAlloc[1] = 2;
  vectorAlloc[4] = arena;
  vectorAlloc[2] = 0;
  arena = Arena__alloc(arena,8);
  vectorAlloc[3] = arena;
  arena = *(undefined4 *)(*(int *)(pass + 8) + 0x378);
  vectorAlloc2 = (undefined4 *)Arena__alloc(arena,0x14);
  puVar9 = vectorAlloc2 + 1;
  *vectorAlloc2 = arena;
  vectorAlloc2[1] = 2;
  vectorAlloc2[2] = 0;
  vectorAlloc2[4] = arena;
  arena = Arena__alloc(arena,8);
  vectorAlloc2[3] = arena;
  arena = *(undefined4 *)(*(int *)(pass + 8) + 0x378);
  vectorAlloc3 = (undefined4 *)Arena__alloc(arena,0x14);
  puVar10 = vectorAlloc3 + 1;
  vectorAlloc3[1] = 2;
  *vectorAlloc3 = arena;
  vectorAlloc3[2] = 0;
  vectorAlloc3[4] = arena;
  arena = Arena__alloc(arena,8);
  vectorAlloc3[3] = arena;
  arena = *(undefined4 *)(*(int *)(pass + 8) + 0x378);
  vectorAlloc4 = (undefined4 *)Arena__alloc(arena,0x14);
  puVar12 = vectorAlloc4 + 1;
  vectorAlloc4[1] = 2;
  *vectorAlloc4 = arena;
  vectorAlloc4[2] = 0;
  vectorAlloc4[4] = arena;
  arena = Arena__alloc(arena,8);
  vectorAlloc4[3] = arena;
  local_48[0] = 0;
  if (0 < listCount) {
    loopIndex = 1;
    do {
      puVar1 = puVar1 + 1;
      loopIndex = loopIndex + 1;
      in_r10 = local_48;
      in_r6 = puVar8;
      in_r7 = puVar9;
      in_r8 = puVar10;
      in_r9 = puVar12;
      ((int (*)())FUN_0011ff7c)(pass,*puVar1,allocation + 1,puVar8,puVar9,puVar10,puVar12,in_r10);
    } while (loopIndex <= listCount);
  }
  if (puVar12 != (undefined4 *)0x0) {
    Arena__free(vectorAlloc4[4],vectorAlloc4[3]);
    Arena__free(*vectorAlloc4,vectorAlloc4);
  }
  if (puVar10 != (undefined4 *)0x0) {
    Arena__free(vectorAlloc3[4],vectorAlloc3[3]);
    Arena__free(*vectorAlloc3,vectorAlloc3);
  }
  if (puVar9 != (undefined4 *)0x0) {
    Arena__free(vectorAlloc2[4],vectorAlloc2[3]);
    Arena__free(*vectorAlloc2,vectorAlloc2);
  }
  if (puVar8 != (undefined4 *)0x0) {
    Arena__free(vectorAlloc[4],vectorAlloc[3]);
    Arena__free(*vectorAlloc,vectorAlloc);
  }
  if (allocation + 1 != (undefined4 *)0x0) {
    Arena__free(allocation[4],allocation[3]);
    Arena__free(*allocation,allocation);
  }
  if (local_48[0] != 0) {
    Compiler__logf(*(undefined4 *)(pass + 8),
                 "SSA : Phi Replace -> %d added temps to break cycles\n",local_48[0],in_r6,in_r7,
                 in_r8,in_r9,in_r10);
  }
  *(uint *)(pass + 0x30) = *(uint *)(pass + 0x30) & 0xfffffffb | 0x40;
  return;
}

/* FUN_00121000 @ 0x121000 (1160 bytes) */
int FUN_00121000(param_1)
  int param_1;
{
  int sourceDef;
  int *operandVReg;
  uint loopIndex;
  bool bVar1;
  int *piVar2;
  uint uVar3;
  int *piVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  int iVar10;
  int *piVar11;
  int *piVar12;
  int iVar13;
  uint uVar14;
  undefined4 uVar15;
  int **ppiVar16;
  int *piVar17;
  /* issue #64 (auto): growable-vector header (capacity/count/data-pointer/arena) used with Vector__elementRefGrow - vecCapacity/vecCount/vecData/vecArena are its four words by their own hex offsets. Vector__elementRefGrow unconditionally reads all four on every call (even its "no grow needed" path reallocs+copies+frees), so they must be one contiguous buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */
  unsigned char local_78_buf [0x10];
  #define vecCapacity (*(uint *)(local_78_buf + 0x00))
  #define vecCount (*(uint *)(local_78_buf + 0x04))
  #define vecData (*(int *)(local_78_buf + 0x08))
  #define vecArena (*(undefined4 *)(local_78_buf + 0x0c))
  /* issue #64 (auto): growable-vector header (capacity/count/data-pointer/arena) used with Vector__elementRefGrow - vec2Capacity/vec2Count/vec2Data/vec2Arena are its four words by their own hex offsets. Vector__elementRefGrow unconditionally reads all four on every call (even its "no grow needed" path reallocs+copies+frees), so they must be one contiguous buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */
  unsigned char local_68_buf [0x10];
  #define vec2Capacity (*(uint *)(local_68_buf + 0x00))
  #define vec2Count (*(uint *)(local_68_buf + 0x04))
  #define vec2Data (*(int *)(local_68_buf + 0x08))
  #define vec2Arena (*(undefined4 *)(local_68_buf + 0x0c))
  int *local_58 [11];
  
  vecArena = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  vecCount = 0;
  vecCapacity = 2;
  vecData = Arena__alloc(vecArena,8);
  uVar14 = vecCount;
  uVar15 = *(undefined4 *)(param_1 + 0x3a0);
  if (vecCount < vecCapacity) {
    iVar13 = vecCount * 4;
    _memset(vecData + iVar13,0,4);
    vecCount = uVar14 + 1;
    puVar5 = (undefined4 *)(iVar13 + vecData);
  }
  else {
    puVar5 = (undefined4 *)Vector__elementRefGrow(&vecCapacity,vecCount);
  }
  *puVar5 = uVar15;
  vec2Arena = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  vec2Count = 0;
  vec2Capacity = 2;
  iVar13 = *(int *)(param_1 + 0x3a0);
  vec2Data = Arena__alloc(vec2Arena,8);
  do {
    piVar9 = *(int **)(iVar13 + 0x98);
    for (piVar2 = (int *)(*(int **)(iVar13 + 0x98))[2]; piVar2 != (int *)0x0;
        piVar2 = (int *)piVar2[2]) {
      if (((((*(int *)(piVar9[0x22] + 8) != 0x8e) &&
            (iVar6 = (**(code **)(*piVar9 + 0x68))(piVar9), iVar6 == 0)) &&
           (iVar6 = FUN_0012ab04(piVar9), iVar6 == 0)) &&
          ((piVar9[0x21] != 0 && ((piVar9[5] & 8U) == 0)))) &&
         (iVar6 = IRInst__isProjectionOfClass26or3a(piVar9), iVar6 == 0)) {
        iVar6 = 0;
        piVar11 = (int *)piVar9[0x56];
        if (0 < piVar9[0x21]) {
          ppiVar16 = local_58;
          do {
            iVar6 = iVar6 + 1;
            sourceDef = IRInst__getOperandSource(piVar9,iVar6);
            *ppiVar16 = *(int **)(sourceDef + 0x158);
            ppiVar16 = ppiVar16 + 1;
          } while (iVar6 < piVar9[0x21]);
        }
        piVar8 = local_58[0];
        vec2Count = 0;
        piVar12 = (int *)0x0;
        if (piVar11 != (int *)0x0) {
          piVar12 = piVar11;
          piVar17 = piVar11;
          do {
            if (iVar6 < 0) {
LAB_001211d0:
              bVar1 = false;
            }
            else {
              iVar10 = 0;
              iVar7 = 0;
              piVar4 = piVar8;
              while (piVar17 != piVar4) {
                iVar10 = iVar10 + 1;
                if (iVar6 < iVar10) goto LAB_001211d0;
                iVar7 = iVar10 * 4;
                piVar4 = local_58[iVar10];
              }
              bVar1 = true;
              piVar11 = *(int **)((int)local_58 + iVar7);
            }
            iVar7 = (**(code **)(*piVar17 + 0x2c))(piVar17);
            if (iVar7 != 0) {
              if (vec2Count < vec2Capacity) {
                iVar7 = vec2Count * 4;
                vec2Count = vec2Count + 1;
                *(undefined4 *)(iVar7 + vec2Data) = 0;
                puVar5 = (undefined4 *)(iVar7 + vec2Data);
              }
              else {
                puVar5 = (undefined4 *)Vector__elementRefGrow(&vec2Capacity,vec2Count);
              }
              *puVar5 = piVar17;
            }
          } while ((!bVar1) &&
                  (piVar4 = piVar17 + 0x3c, piVar12 = piVar17, piVar17 = (int *)*piVar4,
                  (int *)*piVar4 != (int *)0x0));
        }
        iVar6 = (**(code **)(*piVar11 + 0x2c))(piVar11);
        if (iVar6 != 0) {
          piVar11 = piVar12;
        }
        loopIndex = 0;
        if (vec2Count != 0) {
          do {
            if (loopIndex < vec2Capacity) {
              piVar8 = (int *)(loopIndex * 4 + vec2Data);
            }
            else {
              piVar8 = (int *)Vector__elementRefGrow(&vec2Capacity,loopIndex);
            }
            iVar6 = *(int *)(*piVar8 + 0x98);
            for (iVar7 = *(int *)(*(int *)(*piVar8 + 0x98) + 8); iVar7 != 0;
                iVar7 = *(int *)(iVar7 + 8)) {
              if (((*(uint *)(iVar6 + 0x14) & 1) != 0) &&
                 (*(int *)(*(int *)(iVar6 + 0x88) + 8) == 0x8e)) {
                operandVReg = (int *)IRInst__getOperandSource(iVar6,1);
                if (piVar9 == operandVReg) {
                  bVar1 = false;
                  goto LAB_00121318;
                }
                iVar7 = *(int *)(iVar6 + 8);
              }
              iVar6 = iVar7;
            }
            bVar1 = true;
LAB_00121318:
            loopIndex = loopIndex + 1;
            if (!bVar1) goto LAB_00121390;
          } while (loopIndex < vec2Count);
        }
        if ((piVar11 != (int *)piVar9[0x56]) && (piVar11[0x45] < ((int *)piVar9[0x56])[0x45])) {
          IRInst__unlinkAndClearFlag0(piVar9);
          piVar9[5] = piVar9[5] | 1;
          Block__appendInst(piVar11,piVar9);
          iVar6 = *(int *)(*(int *)(param_1 + 8) + 0x6c4);
          *(int *)(iVar6 + 0x1b8) = *(int *)(iVar6 + 0x1b8) + 1;
        }
      }
LAB_00121390:
      piVar9 = piVar2;
    }
    iVar6 = Block__hasDominatedChildren(iVar13);
    if (iVar6 == 0) {
      piVar9 = (int *)0x0;
      uVar14 = vecCount - 1;
      if (uVar14 < vecCount) {
        piVar9 = (int *)(uVar14 * 4 + vecData);
      }
      iVar13 = *piVar9;
      Vector__removeAt(&vecCapacity,uVar14);
    }
    else {
      iVar6 = *(int *)(iVar13 + 0xf4);
      piVar9 = (int *)0x0;
      if (*(uint *)(iVar6 + 4) != 0) {
        piVar9 = *(int **)(iVar6 + 8);
      }
      iVar13 = *piVar9;
      if (1 < *(uint *)(iVar6 + 4)) {
        loopIndex = 1;
        do {
          uVar3 = vecCount;
          uVar15 = *(undefined4 *)(loopIndex * 4 + *(int *)(iVar6 + 8));
          if (vecCount < vecCapacity) {
            iVar7 = vecCount * 4;
            _memset(iVar7 + vecData,0,4);
            vecCount = uVar3 + 1;
            puVar5 = (undefined4 *)(iVar7 + vecData);
          }
          else {
            puVar5 = (undefined4 *)Vector__elementRefGrow(&vecCapacity,vecCount);
          }
          *puVar5 = uVar15;
          loopIndex = loopIndex + 1;
        } while (loopIndex < *(uint *)(iVar6 + 4));
      }
    }
    if (vecCount == 0) {
      Arena__free(vec2Arena,vec2Data);
      Arena__free(vecArena,vecData);
      return;
    }
  } while( true );
}
#undef vecCapacity
#undef vecCount
#undef vecData
#undef vecArena
#undef vec2Capacity
#undef vec2Count
#undef vec2Data
#undef vec2Arena

/* pass_ssa_build @ 0x1214fc (6188 bytes) */
int pass_ssa_build(program)
  int program;
{
  uint *scopeLaneMatchTablesVec;
  uint *scopeExprTablesVec;
  uint *exprTable;
  uint *keyLaneTable;
  uint *ptrHashTable;
  uint *exprHashTable;
  int tableVec;
  int targetQueryC8;
  int targetQueryC0b;
  int compiler;
  int option7On;
  int *targetC;
  int *targetB;
  int *successorInstNext;
  int *successorDomList;
  int *dominatedList;
  int *successorInstHead;
  uint *scopeBlocksVec;
  int option7Flag;
  int sourceIsTracked;
  int destVRegValue;
  int idomBlock;
  int targetQueryC0;
  int redundantCopyResult;
  int operandCount;
  int vnResultB;
  int vnResultA;
  int sameValueResult;
  int defRegister;
  int defQuery18;
  int instQuery34;
  undefined4 pushedChild;
  undefined4 copySource;
  undefined4 *stackTopRefB;
  undefined4 *stackTopRefA;
  undefined4 *sourceDefSlotRef;
  undefined4 *valueKeyAlloc;
  undefined4 *blockTableCursor;
  undefined4 *scopeBlocksSlotRef;
  undefined4 *scopeSwizzleSlotRef;
  undefined4 *scopeLaneMatchSlotRef;
  undefined4 *scopeExprSlotRef;
  undefined4 *blockStackSlotRefB;
  undefined4 *allocation;
  undefined4 vectorData;
  undefined4 arena;
  int hasChildren;
  int footerSuccessor;
  int destKindFlag0;
  int phiOperandIndex;
  uint loopIndex;
  uint tableSize;
  uint lastIndex;
  uint stackCount;
  uint bucketCount;
  uint blockStackSize;
  uint blockStackSize2;
  uint bucketArray;
  uint *sourceDefinitionStack;
  undefined *swizzleHashFn;
  undefined *laneMatchEqFn;
  undefined *scopedHashFn;
  undefined *keyLaneHashFn;
  undefined *ptrEqFn;
  undefined *hashByExprFn;
  undefined *swizzleEqFn;
  undefined *laneMatchHashFn;
  undefined *scopedEqFn;
  undefined *keyLaneEqFn;
  undefined *ptrHashFn;
  undefined *eqByExprFn;
  int *operandCursor;
  int *destVReg;
  int *nextInst;
  int *successorInst;
  int *phi;
  int scopeDepth;
  int byteOffset2;
  int dominatedVector;
  int bucket;
  int byteOffset;
  int sourceIndex;
  int phi2;
  int isFetch;
  int bucketBytes;
  int loopRemaining;
  int knownCondition;
  int byteOffset3;
  int bucket2;
  int ifFooter;
  int destKind;
  int operandRecord3;
  int operandRecord2;
  int sourceDef;
  int operandRecord;
  undefined *hashByValueNumberFn;
  undefined *eqByValueNumberFn;
  int nextInstId;
  uint predecessorNumber;
  int phiSlotArray;
  int *resumeInst;
  int *inst;
  undefined4 *blockStackSlotRef;
  int *target;
  undefined4 *blockTableAlloc;
  int *workBlock;
  int operandIndex;
  int currentDefinition;
  undefined4 unusedArg6;
  undefined4 unusedArg7;
  undefined4 unusedArg8;
  int copyOffset;
  uint *valueNumberTable;
  uint *laneMatchTable;
  uint *swizzleTable;
  int *currentBlock;
  undefined4 entryBlockValue;
  uint stackCount2;
  uint *scopeSwizzleTablesVec;
  uint bucketIndex;
  int option7Enabled;
  int loopRemaining2;
  undefined4 *valueKey;
  int foldedHeadBlock;
  int foldedTailOrSuccessor;
  /* issue #64 live-repro: &blockStackCapacity is passed to Vector__elementRefGrow/Vector__removeAt as a small growable-
   * array header (capacity/count/data-pointer, program[0]/[1]/[2] there) - blockStackCapacity, blockStackCount and
   * blockStackData are exactly its three words by their own hex offsets (0x5c-0x58=4, 0x58-0x54=4). Left
   * as separate scalars, the rebuild does not place them contiguously, so Vector__removeAt's tail-called
   * _memcpy(iVar2,iVar2+4,(iVar1-param_2)*4) - iVar2 derived from blockStackData's real value, iVar1 from
   * blockStackCapacity's - read/wrote whatever unrelated word followed blockStackCapacity on this build's stack instead,
   * a KERN_PROTECTION_FAILURE inside memcpy at a very small address. Merged into one 0xc-byte
   * buffer. */
  unsigned char local_5c_buf [0xc];
#define blockStackCapacity (*(uint *)(local_5c_buf + 0x00))
#define blockStackCount (*(uint *)(local_5c_buf + 0x04))
#define blockStackData (*(int *)(local_5c_buf + 0x08))
  undefined4 blockStackArena;
  
  blockStackArena = *(undefined4 *)(*(int *)(program + PROG_compiler) + COMP_arenaB);
  blockStackCount = 0;
  blockStackCapacity = 2;
  blockStackData = Arena__alloc(blockStackArena,8);
  blockStackSize = blockStackCount;
  entryBlockValue = *(undefined4 *)(program + PROG_entryBlock);
  if (blockStackCount < blockStackCapacity) {
    byteOffset2 = blockStackCount * 4;
    _memset(blockStackData + byteOffset2,0,4);
    blockStackCount = blockStackSize + 1;
    blockStackSlotRef = (undefined4 *)(byteOffset2 + blockStackData);
  }
  else {
    blockStackSlotRef = (undefined4 *)Vector__elementRefGrow(&blockStackCapacity,blockStackCount);
  }
  *blockStackSlotRef = entryBlockValue;
  currentBlock = *(int **)(program + PROG_entryBlock);
  currentBlock[0x45] = 0x10;
  currentBlock[0x2f] = 0;
  *(int *)(program + PROG_visitStamp) = *(int *)(program + PROG_visitStamp) + 1;
  nextInstId = *(int *)(*(int *)(program + PROG_compiler) + COMP_nextInstId);
  *(undefined4 *)(program + 0x334) = 0;
  *(int *)(program + PROG_useEpoch) = nextInstId * 4 + *(int *)(program + PROG_useEpoch);
  option7On = Compiler__isOptionEnabled(*(int *)(program + PROG_compiler),7);
  if (option7On != 0) {
    compiler = *(int *)(program + PROG_compiler);
    arena = *(undefined4 *)(compiler + 0x378);
    allocation = (undefined4 *)Arena__alloc(arena,0x14);
    *allocation = arena;
    allocation[1] = 2;
    allocation[4] = arena;
    allocation[2] = 0;
    vectorData = Arena__alloc(arena,8);
    allocation[3] = vectorData;
    *(undefined4 **)(compiler + 0x3d8) = allocation + 1;
    compiler = *(int *)(program + PROG_compiler);
    arena = *(undefined4 *)(compiler + 0x378);
    allocation = (undefined4 *)Arena__alloc(arena,0x14);
    *allocation = arena;
    allocation[1] = 2;
    allocation[2] = 0;
    allocation[4] = arena;
    vectorData = Arena__alloc(arena,8);
    allocation[3] = vectorData;
    *(undefined4 **)(compiler + 0x3dc) = allocation + 1;
    compiler = *(int *)(program + PROG_compiler);
    arena = *(undefined4 *)(compiler + 0x378);
    allocation = (undefined4 *)Arena__alloc(arena,0x1c);
    eqByValueNumberFn = PTR_FUN_001e90b8;
    hashByValueNumberFn = PTR_FUN_001e9098;
    valueNumberTable = allocation + 1;
    bucketCount = 1;
    *allocation = arena;
    allocation[4] = eqByValueNumberFn;
    allocation[1] = 1;
    loopRemaining = 0x20;
    allocation[5] = hashByValueNumberFn;
    allocation[6] = arena;
    do {
      bucketCount = bucketCount << 1;
      if (0x3ff < bucketCount) break;
      loopRemaining = loopRemaining + -1;
    } while (loopRemaining != 0);
    *valueNumberTable = bucketCount;
    allocation[2] = 0;
    vectorData = Arena__alloc(arena,*valueNumberTable << 2);
    allocation[3] = vectorData;
    _memset(vectorData,0,*valueNumberTable << 2);
    *(uint **)(compiler + 0x3e0) = valueNumberTable;
    compiler = *(int *)(program + PROG_compiler);
    arena = *(undefined4 *)(compiler + 0x378);
    allocation = (undefined4 *)Arena__alloc(arena,0x1c);
    hashByExprFn = PTR_FUN_001e90bc;
    eqByExprFn = PTR_FUN_001e9090;
    exprHashTable = allocation + 1;
    bucketCount = 1;
    *allocation = arena;
    allocation[4] = eqByExprFn;
    allocation[1] = 1;
    loopRemaining = 0x20;
    allocation[5] = hashByExprFn;
    allocation[6] = arena;
    do {
      bucketCount = bucketCount << 1;
      if (0x3ff < bucketCount) break;
      loopRemaining = loopRemaining + -1;
    } while (loopRemaining != 0);
    *exprHashTable = bucketCount;
    allocation[2] = 0;
    vectorData = Arena__alloc(arena,*exprHashTable << 2);
    allocation[3] = vectorData;
    _memset(vectorData,0,*exprHashTable << 2);
    *(uint **)(compiler + 0x3e4) = exprHashTable;
    compiler = *(int *)(program + PROG_compiler);
    arena = *(undefined4 *)(compiler + 0x378);
    allocation = (undefined4 *)Arena__alloc(arena,0x1c);
    ptrEqFn = PTR_FUN_001e90ac;
    ptrHashFn = PTR_FUN_001e90a8;
    ptrHashTable = allocation + 1;
    bucketCount = 1;
    *allocation = arena;
    allocation[4] = ptrEqFn;
    allocation[1] = 1;
    loopRemaining = 0x20;
    allocation[5] = ptrHashFn;
    allocation[6] = arena;
    do {
      bucketCount = bucketCount << 1;
      if (0x3ff < bucketCount) break;
      loopRemaining = loopRemaining + -1;
    } while (loopRemaining != 0);
    *ptrHashTable = bucketCount;
    allocation[2] = 0;
    vectorData = Arena__alloc(arena,*ptrHashTable << 2);
    allocation[3] = vectorData;
    _memset(vectorData,0,*ptrHashTable << 2);
    *(uint **)(compiler + 1000) = ptrHashTable;
    compiler = *(int *)(program + PROG_compiler);
    arena = *(undefined4 *)(compiler + 0x378);
    allocation = (undefined4 *)Arena__alloc(arena,0x1c);
    keyLaneHashFn = PTR_FUN_001e90b4;
    keyLaneEqFn = PTR_FUN_001e90a0;
    keyLaneTable = allocation + 1;
    bucketCount = 1;
    *allocation = arena;
    allocation[4] = keyLaneEqFn;
    allocation[1] = 1;
    loopRemaining = 0x20;
    allocation[5] = keyLaneHashFn;
    allocation[6] = arena;
    do {
      bucketCount = bucketCount << 1;
      if (0x3ff < bucketCount) break;
      loopRemaining = loopRemaining + -1;
    } while (loopRemaining != 0);
    *keyLaneTable = bucketCount;
    allocation[2] = 0;
    vectorData = Arena__alloc(arena,*keyLaneTable << 2);
    allocation[3] = vectorData;
    bucketBytes = *keyLaneTable << 2;
    _memset(vectorData,0,bucketBytes);
    *(uint **)(compiler + 0x3ec) = keyLaneTable;
    arena = *(undefined4 *)(*(int *)(program + PROG_compiler) + COMP_arenaB);
    allocation = (undefined4 *)Arena__alloc(arena,0x2c);
    *allocation = arena;
    compiler = *(int *)(program + PROG_compiler);
    allocation[1] = 0x7ffffffe;
    allocation[5] = 4;
    allocation[8] = 0;
    allocation[2] = 0;
    *(undefined1 *)(allocation + 3) = 0;
    *(undefined1 *)((int)allocation + 0xd) = 0;
    allocation[4] = 0;
    allocation[7] = 0;
    *(undefined4 **)(compiler + 0x3f0) = allocation + 1;
    arena = *(undefined4 *)(*(int *)(program + PROG_compiler) + COMP_arenaB);
    allocation = (undefined4 *)Arena__alloc(arena,0x34);
    *allocation = arena;
    compiler = *(int *)(program + PROG_compiler);
    allocation[0xc] = 0;
    allocation[2] = 0;
    allocation[4] = 0;
    allocation[5] = 0;
    allocation[6] = 0;
    allocation[7] = 0;
    allocation[9] = 0;
    allocation[10] = 0;
    allocation[0xb] = 0;
    allocation[1] = 0;
    allocation[3] = 0xffffffff;
    allocation[8] = 0;
    *(undefined4 **)(compiler + 0x3f4) = allocation + 1;
    target = *(int **)(*(int *)(program + PROG_compiler) + COMP_target);
    (**(code **)(*target + 0x124))
              (target,*(int *)(program + PROG_compiler),bucketBytes,unusedArg6,unusedArg7,unusedArg8,0xffffffff,compiler);
    target = *(int **)(*(int *)(program + PROG_compiler) + COMP_target);
    (**(code **)(*target + 0x128))(target,*(int *)(program + PROG_compiler));
    noop_1762bc(*(undefined4 *)(program + PROG_compiler));
    FUN_001762c0(*(undefined4 *)(program + PROG_compiler));
  }
  arena = *(undefined4 *)(*(int *)(program + PROG_compiler) + COMP_arenaB);
  allocation = (undefined4 *)Arena__alloc(arena,0x14);
  *allocation = arena;
  allocation[1] = 2;
  allocation[4] = arena;
  allocation[2] = 0;
  vectorData = Arena__alloc(arena,8);
  allocation[3] = vectorData;
  *(undefined4 **)(program + PROG_scopeExprTables) = allocation + 1;
  arena = *(undefined4 *)(*(int *)(program + PROG_compiler) + COMP_arenaB);
  allocation = (undefined4 *)Arena__alloc(arena,0x14);
  *allocation = arena;
  allocation[1] = 2;
  allocation[2] = 0;
  allocation[4] = arena;
  vectorData = Arena__alloc(arena,8);
  allocation[3] = vectorData;
  *(undefined4 **)(program + PROG_scopeLaneMatchTables) = allocation + 1;
  arena = *(undefined4 *)(*(int *)(program + PROG_compiler) + COMP_arenaB);
  allocation = (undefined4 *)Arena__alloc(arena,0x14);
  allocation[1] = 2;
  *allocation = arena;
  allocation[2] = 0;
  allocation[4] = arena;
  vectorData = Arena__alloc(arena,8);
  allocation[3] = vectorData;
  *(undefined4 **)(program + PROG_scopeSwizzleTables) = allocation + 1;
  arena = *(undefined4 *)(*(int *)(program + PROG_compiler) + COMP_arenaB);
  allocation = (undefined4 *)Arena__alloc(arena,0x14);
  allocation[1] = 2;
  *allocation = arena;
  allocation[2] = 0;
  allocation[4] = arena;
  vectorData = Arena__alloc(arena,8);
  allocation[3] = vectorData;
  *(undefined4 **)(program + PROG_scopeBlocks) = allocation + 1;
  target = *(int **)(*(int *)(program + PROG_compiler) + COMP_target);
  targetQueryC0b = (**(code **)(*target + 0xc0))(target);
  if (targetQueryC0b != 0) {
    arena = *(undefined4 *)(*(int *)(program + PROG_compiler) + COMP_arenaA);
    allocation = (undefined4 *)Arena__alloc(arena,0x14);
    *allocation = arena;
    allocation[1] = 2;
    allocation[4] = arena;
    allocation[2] = 0;
    vectorData = Arena__alloc(arena,8);
    allocation[3] = vectorData;
    *(undefined4 **)(program + 0x41c) = allocation + 1;
    arena = *(undefined4 *)(*(int *)(program + PROG_compiler) + COMP_arenaA);
    allocation = (undefined4 *)Arena__alloc(arena,0x14);
    *allocation = arena;
    allocation[1] = 2;
    allocation[2] = 0;
    allocation[4] = arena;
    vectorData = Arena__alloc(arena,8);
    allocation[3] = vectorData;
    *(undefined4 **)(program + 0x420) = allocation + 1;
    arena = *(undefined4 *)(*(int *)(program + PROG_compiler) + COMP_arenaA);
    allocation = (undefined4 *)Arena__alloc(arena,0x14);
    allocation[1] = 2;
    *allocation = arena;
    allocation[2] = 0;
    allocation[4] = arena;
    vectorData = Arena__alloc(arena,8);
    allocation[3] = vectorData;
    *(undefined4 **)(program + 0x424) = allocation + 1;
    arena = *(undefined4 *)(*(int *)(program + PROG_compiler) + COMP_arenaA);
    allocation = (undefined4 *)Arena__alloc(arena,0x14);
    allocation[1] = 2;
    *allocation = arena;
    allocation[2] = 0;
    allocation[4] = arena;
    vectorData = Arena__alloc(arena,8);
    allocation[3] = vectorData;
    *(undefined4 **)(program + 0x418) = allocation + 1;
  }
  scopeDepth = -1;
  exprTable = (uint *)0x0;
  laneMatchTable = (uint *)0x0;
  swizzleTable = (uint *)0x0;
  do {
    if (currentBlock[0x3c] != 0) {
      currentBlock[0x2f] = *(int *)(currentBlock[0x3c] + 0xbc) + 1;
    }
    option7Enabled = Compiler__isOptionEnabled(*(undefined4 *)(program + PROG_compiler),7);
    if (option7Enabled != 0) {
      arena = *(undefined4 *)(*(int *)(program + PROG_compiler) + COMP_arenaB);
      allocation = (undefined4 *)Arena__alloc(arena,0x1c);
      scopedHashFn = PTR_FUN_001e90c4;
      scopedEqFn = PTR_FUN_001e90b0;
      exprTable = allocation + 1;
      bucketCount = 1;
      *allocation = arena;
      allocation[4] = scopedEqFn;
      allocation[1] = 1;
      loopRemaining = 0x20;
      allocation[5] = scopedHashFn;
      allocation[6] = arena;
      do {
        bucketCount = bucketCount << 1;
        if (0xff < bucketCount) break;
        loopRemaining = loopRemaining + -1;
      } while (loopRemaining != 0);
      *exprTable = bucketCount;
      allocation[2] = 0;
      vectorData = Arena__alloc(arena,*exprTable << 2);
      allocation[3] = vectorData;
      _memset(vectorData,0,*exprTable << 2);
      scopeExprTablesVec = *(uint **)(program + PROG_scopeExprTables);
      stackCount = scopeExprTablesVec[1];
      if (stackCount < *scopeExprTablesVec) {
        _memset(stackCount * 4 + scopeExprTablesVec[2],0,4);
        scopeExprSlotRef = (undefined4 *)(stackCount * 4 + scopeExprTablesVec[2]);
        scopeExprTablesVec[1] = stackCount + 1;
      }
      else {
        scopeExprSlotRef = (undefined4 *)Vector__elementRefGrow(scopeExprTablesVec,stackCount);
      }
      *scopeExprSlotRef = exprTable;
      arena = *(undefined4 *)(*(int *)(program + PROG_compiler) + COMP_arenaB);
      allocation = (undefined4 *)Arena__alloc(arena,0x1c);
      laneMatchEqFn = PTR_FUN_001e90c0;
      laneMatchHashFn = PTR_FUN_001e9094;
      laneMatchTable = allocation + 1;
      bucketCount = 1;
      *allocation = arena;
      allocation[4] = laneMatchEqFn;
      allocation[1] = 1;
      loopRemaining = 0x20;
      allocation[5] = laneMatchHashFn;
      allocation[6] = arena;
      do {
        bucketCount = bucketCount << 1;
        if (0xff < bucketCount) break;
        loopRemaining = loopRemaining + -1;
      } while (loopRemaining != 0);
      *laneMatchTable = bucketCount;
      allocation[2] = 0;
      vectorData = Arena__alloc(arena,*laneMatchTable << 2);
      allocation[3] = vectorData;
      _memset(vectorData,0,*laneMatchTable << 2);
      scopeLaneMatchTablesVec = *(uint **)(program + PROG_scopeLaneMatchTables);
      stackCount = scopeLaneMatchTablesVec[1];
      if (stackCount < *scopeLaneMatchTablesVec) {
        _memset(stackCount * 4 + scopeLaneMatchTablesVec[2],0,4);
        scopeLaneMatchSlotRef = (undefined4 *)(stackCount * 4 + scopeLaneMatchTablesVec[2]);
        scopeLaneMatchTablesVec[1] = stackCount + 1;
      }
      else {
        scopeLaneMatchSlotRef = (undefined4 *)Vector__elementRefGrow(scopeLaneMatchTablesVec,stackCount);
      }
      *scopeLaneMatchSlotRef = laneMatchTable;
      arena = *(undefined4 *)(*(int *)(program + PROG_compiler) + COMP_arenaB);
      allocation = (undefined4 *)Arena__alloc(arena,0x1c);
      swizzleHashFn = PTR_FUN_001e90a4;
      swizzleEqFn = PTR_FUN_001e909c;
      swizzleTable = allocation + 1;
      bucketCount = 1;
      *allocation = arena;
      allocation[4] = swizzleEqFn;
      allocation[1] = 1;
      loopRemaining = 0x20;
      allocation[5] = swizzleHashFn;
      allocation[6] = arena;
      do {
        bucketCount = bucketCount << 1;
        if (0xff < bucketCount) break;
        loopRemaining = loopRemaining + -1;
      } while (loopRemaining != 0);
      *swizzleTable = bucketCount;
      allocation[2] = 0;
      vectorData = Arena__alloc(arena,*swizzleTable << 2);
      allocation[3] = vectorData;
      _memset(vectorData,0,*swizzleTable << 2);
      scopeSwizzleTablesVec = *(uint **)(program + PROG_scopeSwizzleTables);
      stackCount = scopeSwizzleTablesVec[1];
      if (stackCount < *scopeSwizzleTablesVec) {
        _memset(stackCount * 4 + scopeSwizzleTablesVec[2],0,4);
        scopeSwizzleSlotRef = (undefined4 *)(stackCount * 4 + scopeSwizzleTablesVec[2]);
        scopeSwizzleTablesVec[1] = stackCount + 1;
      }
      else {
        scopeSwizzleSlotRef = (undefined4 *)Vector__elementRefGrow(scopeSwizzleTablesVec,stackCount);
      }
      *scopeSwizzleSlotRef = swizzleTable;
      arena = *(undefined4 *)(*(int *)(program + PROG_compiler) + COMP_arenaB);
      blockTableAlloc = (undefined4 *)Arena__alloc(arena,0x20c);
      blockTableAlloc[1] = 0x80;
      loopRemaining = 0x80;
      *blockTableAlloc = arena;
      blockTableAlloc[2] = 0x1000;
      blockTableCursor = blockTableAlloc + 1;
      do {
        blockTableCursor[2] = 0;
        blockTableCursor = blockTableCursor + 1;
        loopRemaining = loopRemaining + -1;
      } while (loopRemaining != 0);
      currentBlock[0x4a] = (int)(blockTableAlloc + 1);
      scopeBlocksVec = *(uint **)(program + PROG_scopeBlocks);
      stackCount = scopeBlocksVec[1];
      if (stackCount < *scopeBlocksVec) {
        _memset(stackCount * 4 + scopeBlocksVec[2],0,4);
        scopeBlocksSlotRef = (undefined4 *)(stackCount * 4 + scopeBlocksVec[2]);
        scopeBlocksVec[1] = stackCount + 1;
      }
      else {
        scopeBlocksSlotRef = (undefined4 *)Vector__elementRefGrow(scopeBlocksVec,stackCount);
      }
      *scopeBlocksSlotRef = currentBlock;
      scopeDepth = scopeDepth + 1;
    }
    nextInst = (int *)((int *)currentBlock[0x26])[2];
    workBlock = currentBlock;
    inst = (int *)currentBlock[0x26];
    if (nextInst != (int *)0x0) {
LAB_00122000:
      resumeInst = nextInst;
      if ((inst[5] & 1U) == 0) break;
      option7Enabled = Compiler__isOptionEnabled(*(undefined4 *)(program + PROG_compiler),7);
      if (option7Enabled != 0) {
        currentBlock[0x47] = (int)exprTable;
        currentBlock[0x48] = (int)laneMatchTable;
        currentBlock[0x49] = (int)swizzleTable;
      }
      instQuery34 = (**(code **)(*inst + 0x34))(inst);
      if ((instQuery34 != 0) || (instQuery34 = (**(code **)(*inst + 0x38))(inst), instQuery34 != 0)) {
LAB_001227a8:
        resumeInst = (int *)inst[2];
        break;
      }
      isFetch = (**(code **)(*inst + 0x28))(inst);
      if (isFetch != 0) {
        *(uint *)(inst[0x56] + 0xc) = *(uint *)(inst[0x56] + 0xc) | 1;
        *(uint *)(inst[0x56] + 0xc) = *(uint *)(inst[0x56] + 0xc) | 2;
      }
      arena = *(undefined4 *)(*(int *)(program + PROG_compiler) + COMP_arenaB);
      valueKeyAlloc = (undefined4 *)Arena__alloc(arena,0x240);
      *valueKeyAlloc = arena;
      valueKeyAlloc = valueKeyAlloc + 1;
      ValueKey__init(valueKeyAlloc,inst,*(undefined4 *)(program + PROG_compiler));
      destVReg = (int *)inst[0x23];
      valueKey = valueKeyAlloc;
      if (destVReg != (int *)0x0) {
        destKind = inst[0x26];
        destKindFlag0 = RegKind__flagBit0(destKind);
        if (destKindFlag0 != 0) {
          if ((destVReg[9] & 2U) == 0) {
            defQuery18 = (**(code **)(*destVReg + 0x18))(destVReg);
            if (defQuery18 != 0) {
              inst[0x26] = 0;
              inst[0x25] = inst[0x53];
            }
          }
          else {
            defRegister = destVReg[4];
            inst[0x26] = 0;
            inst[0x25] = defRegister;
            inst[5] = inst[5] | 0x40;
          }
        }
        if (destKind == 0x21) {
          *(uint *)(inst[0x56] + 0xc) = *(uint *)(inst[0x56] + 0xc) | 4;
        }
        else if (destKind == 0x30) {
          *(uint *)(inst[0x56] + 0xc) = *(uint *)(inst[0x56] + 0xc) | 0x10;
        }
      }
      if (*(int *)(inst[0x22] + 8) == 0x8e) {
        phi2 = (**(code **)(*inst + 0x7c))(inst);
        *(undefined4 **)(phi2 + 0x130) = valueKey;
        inst[0x54] = *(int *)(program + PROG_visitStamp);
        option7Enabled = Compiler__isOptionEnabled(*(undefined4 *)(program + PROG_compiler),7);
        if ((option7Enabled != 0) && (*(int *)(program + PROG_vnKillCount) < *(int *)(*(int *)(program + PROG_compiler) + COMP_maxVnKills)))
        {
          copySource = (**(code **)(*inst + 0x7c))(inst);
          sameValueResult = ((int (*)())IRInst__sourcesAreSameValue)(copySource);
          if (sameValueResult != 0) {
            sourceDef = IRInst__getOperandSource(inst,1);
            sourceDefinitionStack = *(uint **)(*(int *)(sourceDef + 0x8c) + 0x2c);
            stackCount2 = sourceDefinitionStack[1];
            lastIndex = stackCount2 - 1;
            if (lastIndex < *sourceDefinitionStack) {
              if (stackCount2 <= lastIndex) {
                _memset(stackCount2 * 4 + sourceDefinitionStack[2],0,(lastIndex - stackCount2) * 4 + 4);
                sourceDefinitionStack[1] = stackCount2;
              }
              sourceDefSlotRef = (undefined4 *)(lastIndex * 4 + sourceDefinitionStack[2]);
            }
            else {
              sourceDefSlotRef = (undefined4 *)Vector__elementRefGrow(sourceDefinitionStack,lastIndex);
            }
            Block__recordDefinition(currentBlock,inst[0x23],*sourceDefSlotRef);
            (**(code **)(*inst + 0xc))(inst,0,*(undefined4 *)(program + PROG_compiler));
            inst[5] = inst[5] | 0x400;
            *(int *)(program + 0x150) = *(int *)(program + 0x150) + 1;
            resumeInst = (int *)inst[2];
            break;
          }
          vnResultA = Program__valueNumberInst(program,scopeDepth,scopeDepth,&valueKey,currentBlock);
          if (vnResultA != 0) goto LAB_001227a8;
        }
LAB_00122704:
        operandCount = inst[0x20];
        if (0 < operandCount) {
          operandIndex = 0;
          operandCursor = inst;
          do {
            Block__recordDefinition(currentBlock,operandCursor[0x23],valueKey);
            operandCount = inst[0x20];
            operandIndex = operandIndex + 1;
            operandCursor = operandCursor + 6;
          } while (operandIndex < operandCount);
        }
        if (((operandCount != 0) && (operandCount = RegKind__flagBit0(inst[0x26]), operandCount != 0)) &&
           (((inst[5] & 2U) == 0 &&
            ((operandCount = (**(code **)(*inst + 0x50))(inst), operandCount == 0 &&
             ((inst[5] & 0x40U) == 0)))))) {
          destVRegValue = inst[0x53];
          operandRecord2 = IRInst__getOperandRecord(inst,0);
          *(int *)(operandRecord2 + 8) = destVRegValue;
          resumeInst = (int *)inst[2];
          break;
        }
        goto LAB_001227a8;
      }
      redundantCopyResult = ((int (*)())Program__tryEliminateRedundantCopy)(program,inst,currentBlock);
      if (redundantCopyResult != 0) goto LAB_001227a8;
      ((int (*)())ValueKey__loadSourceDefinitions)(valueKey,*(undefined4 *)(program + PROG_entryBlock));
      ((int (*)())ValueKey__foldMovSources)(valueKey,program);
      vnResultB = Program__valueNumberInst(program,scopeDepth,0,&valueKey,currentBlock);
      if (vnResultB != 0) goto LAB_001227a8;
      target = *(int **)(*(int *)(program + PROG_compiler) + COMP_target);
      targetQueryC0 = (**(code **)(*target + 0xc0))(target);
      if (targetQueryC0 != 0) {
        FUN_00110020(program,valueKey);
      }
      option7Enabled = Compiler__isOptionEnabled(*(undefined4 *)(program + PROG_compiler),7);
      if ((((option7Enabled == 0) || (option7Enabled = Compiler__isOptionEnabled(*(undefined4 *)(program + PROG_compiler),9), option7Enabled == 0))
          || (option7Enabled = Compiler__isOptionEnabled(*(undefined4 *)(program + PROG_compiler),0xd), option7Enabled == 0)) ||
         ((option7Enabled = (**(code **)(*currentBlock + 0x24))(currentBlock), option7Enabled == 0 || (currentBlock[0x53] == 0))))
      {
        if (0 < inst[0x21]) {
          sourceIndex = 1;
          operandCursor = inst;
          do {
            IRInst__setOperandSource(inst,sourceIndex,valueKey[sourceIndex + 0x84],0,*(undefined4 *)(program + PROG_compiler));
            operandRecord = IRInst__getOperandRecord(inst,sourceIndex);
            operandCursor[0x29] = 0;
            *(undefined4 *)(operandRecord + 0xc) = 0x46;
            *(undefined4 *)(operandRecord + 8) = 0xffffffff;
            sourceIsTracked = (**(code **)(*(int *)valueKey[sourceIndex + 0x84] + 0x74))
                               ((int *)valueKey[sourceIndex + 0x84]);
            if (sourceIsTracked != 0) {
              *(undefined4 *)(program + 0x334) = 1;
            }
            sourceIndex = sourceIndex + 1;
            operandCursor = operandCursor + 6;
          } while (sourceIndex <= inst[0x21]);
        }
        goto LAB_00122704;
      }
      ifFooter = currentBlock[0x4f];
      workBlock = (int *)Block__findSimplePredecessor(currentBlock);
      footerSuccessor = Block__findSimpleSuccessor(ifFooter);
      Program__foldConstantIfRegion(program,currentBlock,ifFooter,&foldedHeadBlock,&foldedTailOrSuccessor);
      Block__popDefinitions(currentBlock);
      if (laneMatchTable != (uint *)0x0) {
        tableSize = *laneMatchTable;
        if (tableSize == 0) {
          bucketArray = laneMatchTable[2];
        }
        else {
          bucketArray = laneMatchTable[2];
          bucketIndex = 0;
          do {
            bucket2 = *(int *)(bucketIndex * 4 + bucketArray);
            if (bucket2 != 0) {
              Arena__free(laneMatchTable[5],bucket2);
              tableSize = *laneMatchTable;
              bucketArray = laneMatchTable[2];
            }
            bucketIndex = bucketIndex + 1;
          } while (bucketIndex < tableSize);
        }
        Arena__free(laneMatchTable[5],bucketArray);
        Arena__free(laneMatchTable[-1],laneMatchTable + -1);
      }
      currentBlock[0x48] = 0;
      if (swizzleTable != (uint *)0x0) {
        tableSize = *swizzleTable;
        if (tableSize == 0) {
          bucketArray = swizzleTable[2];
        }
        else {
          bucketArray = swizzleTable[2];
          bucketIndex = 0;
          do {
            bucket2 = *(int *)(bucketIndex * 4 + bucketArray);
            if (bucket2 != 0) {
              Arena__free(swizzleTable[5],bucket2);
              tableSize = *swizzleTable;
              bucketArray = swizzleTable[2];
            }
            bucketIndex = bucketIndex + 1;
          } while (bucketIndex < tableSize);
        }
        Arena__free(swizzleTable[5],bucketArray);
        Arena__free(swizzleTable[-1],swizzleTable + -1);
      }
      currentBlock[0x49] = 0;
      if (exprTable != (uint *)0x0) {
        tableSize = *exprTable;
        if (tableSize == 0) {
          bucketArray = exprTable[2];
        }
        else {
          bucketArray = exprTable[2];
          bucketIndex = 0;
          do {
            bucket2 = *(int *)(bucketIndex * 4 + bucketArray);
            if (bucket2 != 0) {
              Arena__free(exprTable[5],bucket2);
              tableSize = *exprTable;
              bucketArray = exprTable[2];
            }
            bucketIndex = bucketIndex + 1;
          } while (bucketIndex < tableSize);
        }
        Arena__free(exprTable[5],bucketArray);
        Arena__free(exprTable[-1],exprTable + -1);
      }
      currentBlock[0x47] = 0;
      Vector__removeAt(*(undefined4 *)(program + PROG_scopeExprTables),scopeDepth);
      Vector__removeAt(*(undefined4 *)(program + PROG_scopeLaneMatchTables),scopeDepth);
      Vector__removeAt(*(undefined4 *)(program + PROG_scopeSwizzleTables),scopeDepth);
      Vector__removeAt(*(undefined4 *)(program + PROG_scopeBlocks),scopeDepth);
      scopeDepth = scopeDepth + -1;
      dominatedList = (int *)workBlock[0x3d];
      *(int **)(foldedHeadBlock + 0xf0) = workBlock;
      if (*dominatedList == 0) {
        dominatedList = (int *)Vector__elementRefGrow(dominatedList,0);
      }
      else {
        if (dominatedList[1] == 0) {
          *(undefined4 *)dominatedList[2] = 0;
          dominatedList[1] = 1;
        }
        dominatedList = (int *)dominatedList[2];
      }
      *dominatedList = foldedHeadBlock;
      successorDomList = *(int **)(foldedTailOrSuccessor + 0xf4);
      if (*successorDomList == 0) {
        successorDomList = (int *)Vector__elementRefGrow(successorDomList,0);
      }
      else {
        if (successorDomList[1] == 0) {
          *(undefined4 *)successorDomList[2] = 0;
          successorDomList[1] = 1;
        }
        successorDomList = (int *)successorDomList[2];
      }
      *successorDomList = footerSuccessor;
      *(int *)(footerSuccessor + 0xf0) = foldedTailOrSuccessor;
    }
LAB_001227bc:
    byteOffset = 0;
    foldedTailOrSuccessor = 0;
    for (predecessorNumber = 1; predecessorNumber <= *(uint *)(workBlock[0x34] + 4); predecessorNumber = predecessorNumber + 1) {
      foldedTailOrSuccessor = *(int *)(byteOffset + *(int *)(workBlock[0x34] + 8));
      if (foldedTailOrSuccessor != 0) {
        phiOperandIndex = Block__phiOperandIndexForPredecessor(foldedTailOrSuccessor,workBlock);
        successorInstNext = (int *)(*(int **)(foldedTailOrSuccessor + 0x98))[2];
        if (successorInstNext != (int *)0x0) {
          successorInstHead = *(int **)(foldedTailOrSuccessor + 0x98);
          do {
            successorInst = successorInstNext;
            if ((successorInstHead[5] & 1U) != 0) {
              phi = (int *)(**(code **)(*successorInstHead + 0x7c))(successorInstHead);
              if (phi != (int *)0x0) {
                currentDefinition = ((int (*)())VReg__currentDefinition)(phi[0x23],*(undefined4 *)(program + PROG_entryBlock),
                                      *(uint *)(program + PROG_compiler));
                IRInst__setOperandSource(phi,phiOperandIndex,*(undefined4 *)(currentDefinition + 0xb0),0,
                             *(undefined4 *)(program + PROG_compiler));
                phiSlotArray = phi[0x4e];
                copyOffset = 0;
                loopRemaining2 = 4;
                do {
                  *(undefined4 *)(copyOffset + *(int *)(phiOperandIndex * 4 + phiSlotArray)) =
                       *(undefined4 *)(copyOffset + currentDefinition + 0x20);
                  copyOffset = copyOffset + 4;
                  loopRemaining2 = loopRemaining2 + -1;
                } while (loopRemaining2 != 0);
                if ((((phi[0x20] != 0) && (phiSlotArray = RegKind__flagBit0(phi[0x26]), phiSlotArray != 0)) &&
                    ((phi[5] & 2U) == 0)) &&
                   ((phiSlotArray = (**(code **)(*phi + 0x50))(phi), phiSlotArray == 0 &&
                    ((phi[5] & 0x40U) == 0)))) {
                  knownCondition = phi[0x53];
                  operandRecord3 = IRInst__getOperandRecord(phi,0);
                  *(int *)(operandRecord3 + 8) = knownCondition;
                  successorInst = (int *)successorInstHead[2];
                  goto LAB_001228ec;
                }
              }
              successorInst = (int *)successorInstHead[2];
            }
LAB_001228ec:
            successorInstNext = (int *)successorInst[2];
            successorInstHead = successorInst;
          } while ((int *)successorInst[2] != (int *)0x0);
        }
      }
      byteOffset = byteOffset + 4;
    }
    hasChildren = Block__hasDominatedChildren(workBlock);
    if (hasChildren == 0) {
      Block__popDefinitions(workBlock);
      option7Enabled = Compiler__isOptionEnabled(*(undefined4 *)(program + PROG_compiler),7);
      if (option7Enabled != 0) {
        if (swizzleTable != (uint *)0x0) {
          tableSize = *swizzleTable;
          if (tableSize == 0) {
            bucketArray = swizzleTable[2];
          }
          else {
            bucketArray = swizzleTable[2];
            bucketIndex = 0;
            do {
              bucket = *(int *)(bucketIndex * 4 + bucketArray);
              if (bucket != 0) {
                Arena__free(swizzleTable[5],bucket);
                tableSize = *swizzleTable;
                bucketArray = swizzleTable[2];
              }
              bucketIndex = bucketIndex + 1;
            } while (bucketIndex < tableSize);
          }
          Arena__free(swizzleTable[5],bucketArray);
          Arena__free(swizzleTable[-1],swizzleTable + -1);
        }
        workBlock[0x49] = 0;
        if (laneMatchTable != (uint *)0x0) {
          tableSize = *laneMatchTable;
          if (tableSize == 0) {
            bucketArray = laneMatchTable[2];
          }
          else {
            bucketArray = laneMatchTable[2];
            bucketIndex = 0;
            do {
              bucket = *(int *)(bucketIndex * 4 + bucketArray);
              if (bucket != 0) {
                Arena__free(laneMatchTable[5],bucket);
                tableSize = *laneMatchTable;
                bucketArray = laneMatchTable[2];
              }
              bucketIndex = bucketIndex + 1;
            } while (bucketIndex < tableSize);
          }
          Arena__free(laneMatchTable[5],bucketArray);
          Arena__free(laneMatchTable[-1],laneMatchTable + -1);
        }
        workBlock[0x48] = 0;
        if (exprTable != (uint *)0x0) {
          tableSize = *exprTable;
          if (tableSize == 0) {
            bucketArray = exprTable[2];
          }
          else {
            bucketArray = exprTable[2];
            bucketIndex = 0;
            do {
              bucket = *(int *)(bucketIndex * 4 + bucketArray);
              if (bucket != 0) {
                Arena__free(exprTable[5],bucket);
                tableSize = *exprTable;
                bucketArray = exprTable[2];
              }
              bucketIndex = bucketIndex + 1;
            } while (bucketIndex < tableSize);
          }
          Arena__free(exprTable[5],bucketArray);
          Arena__free(exprTable[-1],exprTable + -1);
        }
        workBlock[0x47] = 0;
        Vector__removeAt(*(undefined4 *)(program + PROG_scopeExprTables),scopeDepth);
        Vector__removeAt(*(undefined4 *)(program + PROG_scopeLaneMatchTables),scopeDepth);
        Vector__removeAt(*(undefined4 *)(program + PROG_scopeSwizzleTables),scopeDepth);
        Vector__removeAt(*(undefined4 *)(program + PROG_scopeBlocks),scopeDepth);
        scopeDepth = scopeDepth + -1;
      }
      idomBlock = workBlock[0x3c];
      blockStackSize = blockStackCount - 1;
      stackTopRefA = (undefined4 *)0x0;
      if (blockStackSize < blockStackCount) {
        stackTopRefA = (undefined4 *)(blockStackSize * 4 + blockStackData);
      }
      currentBlock = (int *)*stackTopRefA;
      Vector__removeAt(&blockStackCapacity,blockStackSize);
      while ((idomBlock != 0 && (idomBlock != currentBlock[0x3c]))) {
        Block__popDefinitions(idomBlock);
        idomBlock = *(int *)(idomBlock + 0xf0);
        option7Flag = Compiler__isOptionEnabled(*(undefined4 *)(program + PROG_compiler),7);
        if (option7Flag != 0) {
          Vector__removeAt(*(undefined4 *)(program + PROG_scopeExprTables),scopeDepth);
          Vector__removeAt(*(undefined4 *)(program + PROG_scopeLaneMatchTables),scopeDepth);
          Vector__removeAt(*(undefined4 *)(program + PROG_scopeSwizzleTables),scopeDepth);
          Vector__removeAt(*(undefined4 *)(program + PROG_scopeBlocks),scopeDepth);
          scopeDepth = scopeDepth + -1;
        }
      }
    }
    else {
      dominatedVector = workBlock[0x3d];
      stackTopRefB = (undefined4 *)0x0;
      if (*(uint *)(dominatedVector + 4) != 0) {
        stackTopRefB = *(undefined4 **)(dominatedVector + 8);
      }
      currentBlock = (int *)*stackTopRefB;
      if (1 < *(uint *)(dominatedVector + 4)) {
        loopIndex = 1;
        do {
          blockStackSize2 = blockStackCount;
          pushedChild = *(undefined4 *)(loopIndex * 4 + *(int *)(dominatedVector + 8));
          if (blockStackCount < blockStackCapacity) {
            byteOffset3 = blockStackCount * 4;
            _memset(byteOffset3 + blockStackData,0,4);
            blockStackCount = blockStackSize2 + 1;
            blockStackSlotRefB = (undefined4 *)(byteOffset3 + blockStackData);
          }
          else {
            blockStackSlotRefB = (undefined4 *)Vector__elementRefGrow(&blockStackCapacity,blockStackCount);
          }
          *blockStackSlotRefB = pushedChild;
          loopIndex = loopIndex + 1;
        } while (loopIndex < *(uint *)(dominatedVector + 4));
      }
    }
    if (blockStackCount == 0) {
      targetB = *(int **)(*(int *)(program + PROG_compiler) + COMP_target);
      targetQueryC0b = (**(code **)(*targetB + 0xc0))(targetB);
      if (targetQueryC0b != 0) {
        FUN_0010f87c(program,2,*(undefined4 *)(program + 0x420));
        option7On = Compiler__isOptionEnabled(*(undefined4 *)(program + PROG_compiler),0x3f);
        if (option7On != 0) {
          FUN_001102e0(program,1,*(undefined4 *)(program + 0x41c));
          targetC = *(int **)(*(int *)(program + PROG_compiler) + COMP_target);
          targetQueryC8 = (**(code **)(*targetC + 200))(targetC);
          if (targetQueryC8 != 0) {
            FUN_001102e0(program,2,*(undefined4 *)(program + 0x420));
          }
        }
      }
      tableVec = *(int *)(program + PROG_scopeExprTables);
      if (tableVec != 0) {
        Arena__free(*(undefined4 *)(tableVec + 0xc),*(undefined4 *)(tableVec + 8));
        Arena__free(*(undefined4 *)(tableVec + -4),tableVec + -4);
      }
      tableVec = *(int *)(program + PROG_scopeLaneMatchTables);
      if (tableVec != 0) {
        Arena__free(*(undefined4 *)(tableVec + 0xc),*(undefined4 *)(tableVec + 8));
        Arena__free(*(undefined4 *)(tableVec + -4),tableVec + -4);
      }
      tableVec = *(int *)(program + PROG_scopeSwizzleTables);
      if (tableVec != 0) {
        Arena__free(*(undefined4 *)(tableVec + 0xc),*(undefined4 *)(tableVec + 8));
        Arena__free(*(undefined4 *)(tableVec + -4),tableVec + -4);
      }
      tableVec = *(int *)(program + PROG_scopeBlocks);
      if (tableVec != 0) {
        Arena__free(*(undefined4 *)(tableVec + 0xc),*(undefined4 *)(tableVec + 8));
        Arena__free(*(undefined4 *)(tableVec + -4),tableVec + -4);
      }
      Arena__free(*(undefined4 *)(*(int *)(program + PROG_compiler) + COMP_arenaB),
                   *(undefined4 *)(*(int *)(program + PROG_compiler) + COMP_exprCreationList));
      option7On = Compiler__isOptionEnabled(*(undefined4 *)(program + PROG_compiler),7);
      if ((option7On != 0) && (option7On = Compiler__isOptionEnabled(*(undefined4 *)(program + PROG_compiler),9), option7On != 0)) {
        noop_172fb0(*(undefined4 *)(program + PROG_compiler));
        noop_172fb4(*(undefined4 *)(program + PROG_compiler));
      }
      *(uint *)(program + PROG_flags) = *(uint *)(program + PROG_flags) | 0xc;
      Program__beginPass(program,(int)"ssa_build");
      Arena__free(blockStackArena,blockStackData);
      return;
    }
  } while( true );
  nextInst = (int *)resumeInst[2];
  inst = resumeInst;
  if ((int *)resumeInst[2] == (int *)0x0) goto LAB_001227bc;
  goto LAB_00122000;
}
#undef blockStackCapacity
#undef blockStackCount
#undef blockStackData

/* FUN_00122de8 @ 0x122de8 (168 bytes) */
int FUN_00122de8(program)
  int program;
{
  int hoistInstructionsEnabled;
  int *piVar1;
  int iVar2;
  
  FUN_0012b520(program);
  FUN_000f88b4(program);
  ((int (*)())FUN_0011eaa0)(program);
  ((int (*)())pass_ssa_build)(program);
  hoistInstructionsEnabled = Compiler__isOptionEnabled(*(undefined4 *)(program + 8),0xe);
  if (hoistInstructionsEnabled != 0) {
    ((int (*)())FUN_0011f578)(program);
    ((int (*)())FUN_00121000)(program);
  }
  FUN_000ec8e4(program);
  piVar1 = *(int **)(program + 0x3b0);
  iVar2 = *piVar1;
  if (iVar2 != 0) {
    if (iVar2 == 0) {
      iVar2 = 1;
    }
    do {
      piVar1[2] = 0;
      piVar1 = piVar1 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return FUN_000f019c(program);
}

/* FUN_00122e90 @ 0x122e90 (44 bytes) */
int FUN_00122e90(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  uint param_3;
  uint param_4;
{
  undefined4 uVar1;
  
                    
                    
  uVar1 = (**(code **)(PTR_PTR_001e8c60 + param_2 * 0x10 + 0xc))(param_1,param_2,param_3,param_4);
  return uVar1;
}

/* VReg__popDefinition @ 0x122ebc (28 bytes) */
int VReg__popDefinition(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x2c) + 4);
  *(undefined4 *)(param_1 + 0x28) = 0xffffffff;
  return Vector__removeAt(*(int *)(param_1 + 0x2c),iVar1 + -1);
}

/* ExportValue__vslot10 @ 0x122ed8 (80 bytes) */
int ExportValue__vslot10(this, param_2)
  int this;
  undefined4 param_2;
{
  unsigned int ghidra_home[8] = { this, param_2, 0, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  char *pcVar1;
  int iVar2;
  int iVar3;
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 4)) = param_2;
  if (*(int *)(*(int *)(this + 0x30) + 0x98) != 8) {
    iVar2 = 0;
    iVar3 = 4;
    pcVar1 = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 4));
    do {
      if (*pcVar1 == '\0') {
        *(undefined1 *)(iVar2 + *(int *)(this + 0x30) + 0x9c) = 0;
      }
      iVar2 = iVar2 + 1;
      pcVar1 = pcVar1 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return *(undefined4 *)(this + 0x34);
}

/* FUN_00122f28 @ 0x122f28 (124 bytes) */
int FUN_00122f28(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  
  if ((param_1[9] & 2U) == 0) {
    iVar1 = (**(code **)(*param_1 + 0x18))(param_1);
    if (iVar1 != 0) {
      *(undefined4 *)(param_2 + 0x98) = 0;
      *(undefined4 *)(param_2 + 0x94) = *(undefined4 *)(param_2 + 0x14c);
    }
  }
  else {
    iVar1 = param_1[4];
    iVar2 = param_1[1];
    *(uint *)(param_2 + 0x14) = *(uint *)(param_2 + 0x14) | 0x40;
    *(int *)(param_2 + 0x94) = iVar1;
    *(int *)(param_2 + 0x98) = iVar2;
  }
  return;
}

/* VReg__currentDefinition @ 0x122fa4 (200 bytes) */
int VReg__currentDefinition(param_1, param_2, param_3)
  int *param_1;
  undefined4 param_2;
  uint param_3;
{
  undefined4 *puVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  undefined4 uVar5;
  
  puVar3 = (uint *)param_1[0xb];
  uVar4 = puVar3[1];
  if (uVar4 == 0) {
    uVar5 = (**(code **)(*param_1 + 8))(param_1,param_2,param_3);
    Block__recordDefinition(param_2,param_1,uVar5);
  }
  else {
    uVar2 = uVar4 - 1;
    if (uVar2 < *puVar3) {
      if (uVar4 <= uVar2) {
        _memset(uVar4 * 4 + puVar3[2],0,(uVar2 - uVar4) * 4 + 4);
        puVar3[1] = uVar4;
      }
      puVar1 = (undefined4 *)(uVar2 * 4 + puVar3[2]);
    }
    else {
      puVar1 = (undefined4 *)Vector__elementRefGrow(puVar3,uVar2);
    }
    uVar5 = *puVar1;
  }
  return uVar5;
}

/* FUN_0012306c @ 0x12306c (120 bytes) */
int FUN_0012306c(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  uint uVar2;
  uint *puVar3;
  
  puVar3 = *(uint **)(param_1 + 0x18);
  uVar2 = puVar3[1];
  if (uVar2 < *puVar3) {
    _memset(uVar2 * 4 + puVar3[2],0,4);
    puVar1 = (undefined4 *)(uVar2 * 4 + puVar3[2]);
    puVar3[1] = uVar2 + 1;
  }
  else {
    puVar1 = (undefined4 *)Vector__elementRefGrow(puVar3,uVar2);
  }
  *puVar1 = param_2;
  return;
}

/* ImmedConstBuffer__clone @ 0x1230e4 (268 bytes) */
int ImmedConstBuffer__clone(this, param_2, compiler)
  int this;
  int *param_2;
  int compiler;
{
  undefined4 *allocation;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  undefined4 arena;
  undefined4 *puVar8;
  int iVar9;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  piVar6 = *(int **)(*(int *)(*(int *)(compiler + COMP_currentProgram) + 0x354) + 300);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  puVar8 = allocation + 1;
  *allocation = arena;
  IRLoadConst__ctor_109938(puVar8,compiler);
  iVar4 = *piVar6;
  iVar9 = 4;
  uVar5 = 0;
  puVar3 = puVar8;
  do {
    *(byte *)(allocation + 0x58) = (byte)(1 << (uVar5 & 0x3f)) | *(byte *)(allocation + 0x58);
    puVar3[7] = 3;
    iVar1 = *(int *)(this + 8) * 4 + uVar5;
    if (iVar4 < iVar1) {
      puVar3[8] = 0;
    }
    else {
      puVar3[8] = piVar6[iVar1 + 1];
    }
    uVar5 = uVar5 + 1;
    puVar3 = puVar3 + 6;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  IRInst__setOperandRef(puVar8,0,this);
  arena = *(undefined4 *)(compiler + COMP_arenaB);
  puVar3 = (undefined4 *)Arena__alloc(arena,0x240);
  puVar2 = puVar3 + 1;
  *puVar3 = arena;
  ValueKey__init(puVar2,puVar8,compiler);
  iVar4 = Compiler__isOptionEnabled(compiler,7);
  if (iVar4 != 0) {
    FUN_00174e0c(puVar2);
    ValueKey__propagateLaneValues(puVar2);
  }
  ((int (*)())FUN_0012306c)(this,puVar8);
  (**(code **)(*param_2 + 0xc))(param_2,puVar8);
  ((int (*)())FUN_00122f28)(this,puVar8);
  return puVar2;
}

/* VertexRegister__clone @ 0x123288 (148 bytes) */
int VertexRegister__clone(this, param_2, compiler)
  int this;
  int *param_2;
  int compiler;
{
  int iVar1;
  undefined4 *allocation;
  int callResult;
  undefined4 *puVar4;
  undefined4 arena;
  
  iVar1 = IRLoadVertex__new_109810(0xa4,compiler);
  IRInst__setOperandRef(iVar1,0,this);
  *(undefined4 *)(iVar1 + 0x9c) = DAT_001afee8;
  *(undefined4 *)(iVar1 + 300) = *(undefined4 *)(this + 8);
  arena = *(undefined4 *)(compiler + COMP_arenaB);
  allocation = (undefined4 *)Arena__alloc(arena,0x240);
  puVar4 = allocation + 1;
  *allocation = arena;
  ValueKey__init(puVar4,iVar1,compiler);
  callResult = Compiler__isOptionEnabled(compiler,7);
  if (callResult != 0) {
    FUN_00174e0c(puVar4);
    ValueKey__propagateLaneValues(puVar4);
  }
  ((int (*)())FUN_0012306c)(this,iVar1);
  (**(code **)(*param_2 + 0xc))(param_2,iVar1);
  ((int (*)())FUN_00122f28)(this,iVar1);
  return puVar4;
}

/* VReg__setTopDefinition @ 0x123398 (140 bytes) */
int VReg__setTopDefinition(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  
  puVar4 = *(uint **)(param_1 + 0x2c);
  uVar2 = puVar4[1];
  uVar3 = uVar2 - 1;
  if (uVar3 < *puVar4) {
    if (uVar2 <= uVar3) {
      _memset(uVar2 * 4 + puVar4[2],0,(uVar3 - uVar2) * 4 + 4);
      puVar4[1] = uVar2;
    }
    puVar1 = (undefined4 *)(uVar3 * 4 + puVar4[2]);
  }
  else {
    puVar1 = (undefined4 *)Vector__elementRefGrow(puVar4,uVar3);
  }
  *puVar1 = param_2;
  return;
}

/* VReg__pushDefinition @ 0x123424 (180 bytes) */
int VReg__pushDefinition(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  undefined4 *puVar1;
  uint uVar2;
  uint *puVar3;
  
  puVar3 = *(uint **)(param_1 + 0x2c);
  if ((puVar3[1] != 0) && (param_2 == *(int *)(param_1 + 0x28))) {
    ((int (*)())VReg__setTopDefinition)(param_1,param_3);
    return;
  }
  *(int *)(param_1 + 0x28) = param_2;
  uVar2 = puVar3[1];
  if (uVar2 < *puVar3) {
    _memset(uVar2 * 4 + puVar3[2],0,4);
    puVar1 = (undefined4 *)(uVar2 * 4 + puVar3[2]);
    puVar3[1] = uVar2 + 1;
  }
  else {
    puVar1 = (undefined4 *)Vector__elementRefGrow(puVar3,uVar2);
  }
  *puVar1 = param_3;
  return;
}

/* FUN_001234d8 @ 0x1234d8 (224 bytes) */
int FUN_001234d8(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  int *piVar2;
  uint loopIndex;
  uint *puVar4;
  uint *puVar5;
  
  uVar1 = (*(uint **)(param_1 + 0x14))[1];
  if (uVar1 != 0) {
    loopIndex = 0;
    puVar4 = *(uint **)(param_1 + 0x14);
    do {
      if (loopIndex < *puVar4) {
        puVar5 = puVar4;
        if (uVar1 <= loopIndex) {
          _memset(uVar1 * 4 + puVar4[2],0,(loopIndex - uVar1) * 4 + 4);
          puVar4[1] = loopIndex + 1;
          puVar5 = *(uint **)(param_1 + 0x14);
        }
        piVar2 = (int *)(loopIndex * 4 + puVar4[2]);
      }
      else {
        piVar2 = (int *)Vector__elementRefGrow(puVar4,loopIndex);
        puVar5 = *(uint **)(param_1 + 0x14);
      }
      if (*piVar2 == param_2) {
        Vector__removeAt(puVar5,loopIndex);
        return;
      }
      uVar1 = puVar5[1];
      loopIndex = loopIndex + 1;
      puVar4 = puVar5;
    } while (loopIndex < uVar1);
  }
  return;
}

/* FUN_001235b8 @ 0x1235b8 (300 bytes) */
int FUN_001235b8(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  uint uVar1;
  int *piVar2;
  undefined4 *puVar3;
  uint loopIndex;
  uint *puVar5;
  uint *puVar6;
  
  uVar1 = (*(uint **)(param_1 + 0x14))[1];
  if (uVar1 != 0) {
    loopIndex = 0;
    puVar5 = *(uint **)(param_1 + 0x14);
    do {
      if (loopIndex < *puVar5) {
        puVar6 = puVar5;
        if (uVar1 <= loopIndex) {
          _memset(uVar1 * 4 + puVar5[2],0,(loopIndex - uVar1) * 4 + 4);
          puVar5[1] = loopIndex + 1;
          puVar6 = *(uint **)(param_1 + 0x14);
        }
        piVar2 = (int *)(loopIndex * 4 + puVar5[2]);
      }
      else {
        piVar2 = (int *)Vector__elementRefGrow(puVar5,loopIndex);
        puVar6 = *(uint **)(param_1 + 0x14);
      }
      if (*piVar2 == param_2) {
        if (loopIndex < *puVar6) {
          uVar1 = puVar6[1];
          if (uVar1 <= loopIndex) {
            _memset(uVar1 * 4 + puVar6[2],0,(loopIndex - uVar1) * 4 + 4);
            puVar6[1] = loopIndex + 1;
          }
          puVar3 = (undefined4 *)(loopIndex * 4 + puVar6[2]);
        }
        else {
          puVar3 = (undefined4 *)Vector__elementRefGrow(puVar6,loopIndex);
        }
        *puVar3 = param_3;
        return;
      }
      uVar1 = puVar6[1];
      loopIndex = loopIndex + 1;
      puVar5 = puVar6;
    } while (loopIndex < uVar1);
  }
  return;
}

/* VReg__addUse @ 0x1236e4 (184 bytes) */
int VReg__addUse(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  
  if (param_2 < 2) {
LAB_00123718:
    puVar5 = *(uint **)(param_1 + 0x14);
    uVar4 = puVar5[1];
    if (uVar4 < *puVar5) {
      _memset(uVar4 * 4 + puVar5[2],0,4);
      piVar2 = (int *)(uVar4 * 4 + puVar5[2]);
      puVar5[1] = uVar4 + 1;
    }
    else {
      piVar2 = (int *)Vector__elementRefGrow(puVar5,uVar4);
    }
    *piVar2 = param_3;
  }
  else if (param_1 != *(int *)(param_3 + 0xa4)) {
    iVar3 = param_2 + -1;
    iVar1 = param_3;
    do {
      iVar3 = iVar3 + -1;
      if (iVar3 == 0) goto LAB_00123718;
      piVar2 = (int *)(iVar1 + 0xbc);
      iVar1 = iVar1 + 0x18;
    } while (param_1 != *piVar2);
  }
  return;
}

/* VRegInfo__ctor_12379c @ 0x12379c (296 bytes) */
int VRegInfo__ctor_12379c(param_1, param_2, param_3, param_4, compiler)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int compiler;
{
  undefined *vtable;
  int iVar2;
  undefined4 *allocation;
  undefined4 arena;
  
  param_1[2] = param_2;
  vtable = PTR_DAT_001e90f0;
  param_1[1] = param_3;
  param_1[3] = param_4;
  *param_1 = vtable + 8;
  param_1[4] = 0xffffffff;
  param_1[7] = 0xffffffff;
  iVar2 = *(int *)(compiler + 0x348);
  param_1[8] = iVar2;
  *(int *)(compiler + 0x348) = iVar2 + 1;
  param_1[10] = 0xffffffff;
  param_1[9] = 0;
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x14);
  *allocation = arena;
  allocation[1] = 2;
  allocation[4] = arena;
  allocation[2] = 0;
  arena = Arena__alloc(arena,8);
  allocation[3] = arena;
  param_1[5] = allocation + 1;
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x14);
  *allocation = arena;
  allocation[1] = 2;
  allocation[4] = arena;
  allocation[2] = 0;
  arena = Arena__alloc(arena,8);
  allocation[3] = arena;
  param_1[6] = allocation + 1;
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x14);
  *allocation = arena;
  allocation[1] = 2;
  allocation[2] = 0;
  allocation[4] = arena;
  arena = Arena__alloc(arena,8);
  allocation[3] = arena;
  param_1[0xb] = allocation + 1;
  return;
}

/* VRegInfo__ctor_1238e8 @ 0x1238e8 (296 bytes) */
int VRegInfo__ctor_1238e8(param_1, param_2, param_3, param_4, compiler)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int compiler;
{
  undefined *vtable;
  int iVar2;
  undefined4 *allocation;
  undefined4 arena;
  
  param_1[2] = param_2;
  vtable = PTR_DAT_001e90f0;
  param_1[1] = param_3;
  param_1[3] = param_4;
  *param_1 = vtable + 8;
  param_1[4] = 0xffffffff;
  param_1[7] = 0xffffffff;
  iVar2 = *(int *)(compiler + 0x348);
  param_1[8] = iVar2;
  *(int *)(compiler + 0x348) = iVar2 + 1;
  param_1[10] = 0xffffffff;
  param_1[9] = 0;
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x14);
  *allocation = arena;
  allocation[1] = 2;
  allocation[4] = arena;
  allocation[2] = 0;
  arena = Arena__alloc(arena,8);
  allocation[3] = arena;
  param_1[5] = allocation + 1;
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x14);
  *allocation = arena;
  allocation[1] = 2;
  allocation[4] = arena;
  allocation[2] = 0;
  arena = Arena__alloc(arena,8);
  allocation[3] = arena;
  param_1[6] = allocation + 1;
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x14);
  *allocation = arena;
  allocation[1] = 2;
  allocation[2] = 0;
  allocation[4] = arena;
  arena = Arena__alloc(arena,8);
  allocation[3] = arena;
  param_1[0xb] = allocation + 1;
  return;
}

/* Interpolator__vslot10 @ 0x123a34 (296 bytes) */
int Interpolator__vslot10(this, param_2, param_3)
  int this;
  undefined4 param_2;
  int param_3;
{
  undefined4 arena;
  unsigned int ghidra_home[8] = { this, param_2, param_3, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  undefined4 *allocation;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 4)) = param_2;
  if ((*(uint *)(param_3 + 0x30) & 0x4000) == 0) {
    if (*(int *)(this + 0x30) == 0) {
      iVar3 = *(int *)(this + 0x3c);
      if (*(int *)(this + 0x3c) == 0) {
        iVar3 = this;
      }
    }
    else {
      if (*(int *)(*(int *)(this + 0x30) + 0x98) != 0x18) {
        iVar3 = 0;
        iVar5 = 4;
        pcVar4 = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 4));
        do {
          if (*pcVar4 == '\0') {
            *(undefined1 *)(iVar3 + *(int *)(this + 0x30) + 0x9c) = 0;
            if (*(int *)(this + 0x34) != 0) {
              *(undefined1 *)(iVar3 + *(int *)(this + 0x34) + 0x9c) = 0;
            }
          }
          iVar3 = iVar3 + 1;
          pcVar4 = pcVar4 + 1;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
      }
      iVar3 = *(int *)(this + 0x3c);
    }
  }
  else {
    iVar5 = *(int *)(param_3 + 8);
    arena = *(undefined4 *)(iVar5 + 0x374);
    allocation = (undefined4 *)Arena__alloc(arena,0x168);
    puVar7 = allocation + 1;
    *allocation = arena;
    IRGeomExport__ctor_108770(puVar7,iVar5);
    allocation[0x28] = (*(unsigned int *)((unsigned char *)ghidra_home + 4));
    allocation[0x51] = *(undefined4 *)(this + 8);
    allocation[0x50] = *(undefined4 *)(this + 4);
    uVar2 = FUN_00127608(*(undefined4 *)(param_3 + 0x3ac),0x2c,0,0);
    IRInst__setOperandRef(puVar7,0,uVar2);
    IRInst__setOperandRef(puVar7,2,uVar2);
    uVar6 = DAT_001afeec;
    iVar3 = IRInst__getOperandRecord(puVar7,2);
    *(undefined4 *)(iVar3 + 0x10) = uVar6;
    ((int (*)())FUN_0012306c)(uVar2,puVar7);
    uVar6 = *(undefined4 *)(param_3 + 0x3ac);
    iVar3 = *(int *)(iVar5 + 0x3ac) + -1;
    *(int *)(iVar5 + 0x3ac) = iVar3;
    uVar6 = FUN_001275a0(uVar6,0,iVar3,0);
    *(undefined4 *)(this + 0x3c) = uVar6;
    IRInst__setOperandRef(puVar7,1,uVar6);
    ((int (*)())VReg__addUse)(*(undefined4 *)(this + 0x3c),1,puVar7);
    ((int (*)())VReg__addUse)(uVar2,2,puVar7);
    *(undefined4 **)(this + 0x30) = puVar7;
    iVar3 = *(int *)(this + 0x3c);
  }
  return iVar3;
}

/* FUN_00123c08 @ 0x123c08 (984 bytes) */
int FUN_00123c08(compiler, param_2, param_3)
  int compiler;
  int *param_2;
  uint param_3;
{
  undefined4 *allocation;
  undefined4 arena;
  int valueNumberEnabled;
  int valueNumberEnabled2;
  int operandRecord;
  undefined4 arenaAt378;
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 *a1;
  uint uVar11;
  uint *puVar12;
  undefined4 uVar13;
  undefined4 arenaAt374;
  uint uVar15;
  int iVar16;
  undefined4 *local_58;
  undefined4 local_54;
  uint local_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  
  if (*(int *)(compiler + COMP_arenaB) == 0) {
    iVar7 = *(int *)(compiler + 8);
    iVar10 = *(int *)(iVar7 + 0x6c4);
    bVar1 = false;
    local_54 = 0;
    iVar9 = 0;
    iVar8 = 0;
    iVar16 = 4;
    iVar3 = iVar10;
    do {
      iVar2 = *(int *)(iVar3 + 0x10);
      if (iVar2 == 1) {
        *(undefined4 *)((int)&local_50 + iVar8) = 0;
      }
      else if (iVar2 == 2) {
        *(undefined4 *)((int)&local_50 + iVar8) = 0x3f800000;
      }
      else if (iVar2 == 0) {
        bVar1 = true;
        *(undefined4 *)((int)&local_50 + iVar8) = 0;
        *(undefined1 *)((int)&local_54 + iVar9) = 1;
      }
      iVar9 = iVar9 + 1;
      iVar8 = iVar8 + 4;
      iVar3 = iVar3 + 4;
      iVar16 = iVar16 + -1;
    } while (iVar16 != 0);
    uVar4 = IRMov__new_1084b8(0x31,iVar7);
    *(undefined4 *)(compiler + COMP_arenaB) = uVar4;
    ((void (*)())IRInst__makeLiteralVec4Float)(uVar4,*(undefined4 *)(*(int *)(compiler + 8) + 0x6c4),1,(double)GH_U2F((unsigned int)(local_50)),
                 (double)fStack_4c,(double)fStack_48,(double)fStack_44);
    iVar3 = *(int *)(*(int *)(compiler + COMP_arenaB) + 0xa4);
    piVar5 = *(int **)(iVar3 + 0x18);
    if (*piVar5 == 0) {
      puVar6 = (undefined4 *)Vector__elementRefGrow(piVar5,0);
    }
    else {
      if (piVar5[1] == 0) {
        *(undefined4 *)piVar5[2] = 0;
        piVar5[1] = 1;
      }
      puVar6 = (undefined4 *)piVar5[2];
    }
    uVar4 = *puVar6;
    if (*(int *)(*(int *)(iVar3 + 0x2c) + 4) == 0) {
      arena = *(undefined4 *)(*(int *)(compiler + 8) + 0x378);
      puVar6 = (undefined4 *)Arena__alloc(arena,0x240);
      *puVar6 = arena;
      puVar6 = puVar6 + 1;
      ValueKey__init(puVar6,uVar4,*(undefined4 *)(compiler + 8));
      valueNumberEnabled = Compiler__isOptionEnabled(*(undefined4 *)(compiler + 8),7);
      if (valueNumberEnabled != 0) {
        FUN_00174e0c(puVar6);
        ValueKey__propagateLaneValues(puVar6);
      }
      ((int (*)())VReg__pushDefinition)(iVar3,param_2[0x2c],puVar6);
    }
    uVar13 = uVar4;
    ((int (*)())VReg__addUse)(iVar3,1,uVar4);
    if (bVar1) {
      arenaAt374 = *(undefined4 *)(*(int *)(compiler + 8) + 0x374);
      allocation = (undefined4 *)Arena__alloc(arenaAt374,0x168);
      *allocation = arenaAt374;
      a1 = allocation + 1;
      IRUndefined__ctor_108fb0(a1,*(undefined4 *)(compiler + 8));
      (**(code **)(**(int **)(compiler + 0x3a0) + 0xc))(*(int **)(compiler + 0x3a0),a1,uVar13);
      iVar7 = *(int *)(*(int *)(compiler + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(compiler + 8) + 0x3ac) = iVar7;
      uVar13 = FUN_00127608(*(undefined4 *)(iVar10 + 0x3ac),0,iVar7,0);
      allocation[0x24] = uVar13;
      operandRecord = IRInst__getOperandRecord(a1,0);
      *(int *)(operandRecord + 8) = iVar7;
      *(undefined4 *)(operandRecord + 0xc) = 0;
      arenaAt378 = *(undefined4 *)(*(int *)(compiler + 8) + 0x378);
      puVar6 = (undefined4 *)Arena__alloc(arenaAt378,0x240);
      *puVar6 = arenaAt378;
      puVar6 = puVar6 + 1;
      ValueKey__init(puVar6,a1,*(undefined4 *)(compiler + 8));
      valueNumberEnabled2 = Compiler__isOptionEnabled(*(undefined4 *)(compiler + 8),7);
      if (valueNumberEnabled2 != 0) {
        FUN_00174e0c(puVar6);
        ValueKey__propagateLaneValues(puVar6);
      }
      ((int (*)())FUN_0012306c)(uVar13,a1);
      Block__recordDefinition(param_2,uVar13,puVar6);
      *(undefined4 *)(*(int *)(compiler + COMP_arenaB) + 0x9c) = local_54;
      IRInst__setExtraOperandSource(*(undefined4 *)(compiler + COMP_arenaB),a1,0,*(undefined4 *)(compiler + 8));
      *(undefined4 *)(*(int *)(compiler + COMP_arenaB) + 0xbc) = uVar13;
      ((int (*)())VReg__addUse)(uVar13,2,*(undefined4 *)(compiler + COMP_arenaB));
    }
    IRInst__setOperandSource(*(undefined4 *)(compiler + COMP_arenaB),1,uVar4,0,*(undefined4 *)(compiler + 8));
    uVar4 = *(undefined4 *)(*(int *)(compiler + COMP_arenaB) + 0x14c);
    operandRecord = IRInst__getOperandRecord(*(int *)(compiler + COMP_arenaB),0);
    *(undefined4 *)(operandRecord + 0xc) = 0;
    *(undefined4 *)(operandRecord + 8) = uVar4;
    iVar3 = *(int *)(*(int *)(compiler + 8) + 0x3ac) + -1;
    *(int *)(*(int *)(compiler + 8) + 0x3ac) = iVar3;
    uVar4 = FUN_00127608(*(undefined4 *)(compiler + 0x3ac),0,iVar3,0);
    *(undefined4 *)(*(int *)(compiler + COMP_arenaB) + 0x8c) = uVar4;
    ((int (*)())FUN_0012306c)(uVar4,*(undefined4 *)(compiler + COMP_arenaB));
    (**(code **)(*param_2 + 0xc))(param_2,*(undefined4 *)(compiler + COMP_arenaB),iVar3);
    arena = *(undefined4 *)(*(int *)(compiler + 8) + 0x378);
    allocation = (undefined4 *)Arena__alloc(arena,0x240);
    *allocation = arena;
    ValueKey__init(allocation + 1,*(undefined4 *)(compiler + COMP_arenaB),*(undefined4 *)(compiler + 8));
    local_58 = allocation + 1;
    Program__valueNumberInst(iVar10,0,0,&local_58,param_2);
    Block__recordDefinition(param_2,uVar4,local_58);
    ((int (*)())FUN_00122f28)(uVar4,*(undefined4 *)(compiler + COMP_arenaB));
  }
  else {
    puVar12 = *(uint **)(*(int *)(*(int *)(compiler + COMP_arenaB) + 0x8c) + 0x2c);
    uVar11 = puVar12[1];
    uVar15 = uVar11 - 1;
    if (uVar15 < *puVar12) {
      if (uVar11 <= uVar15) {
        _memset(uVar11 * 4 + puVar12[2],0,(uVar15 - uVar11) * 4 + 4);
        puVar12[1] = uVar11;
      }
      piVar5 = (int *)(uVar15 * 4 + puVar12[2]);
    }
    else {
      piVar5 = (int *)Vector__elementRefGrow(puVar12,uVar15);
    }
    local_58 = (undefined4 *)*piVar5;
  }
  return local_58;
}

/* TempValue__clone @ 0x1240a8 (180 bytes) */
int TempValue__clone(this, param_2, compiler)
  int this;
  int *param_2;
  int compiler;
{
  undefined4 *allocation;
  int iVar1;
  undefined4 *puVar2;
  int callResult;
  undefined4 *puVar4;
  undefined4 arena;
  
  if (*(int *)(this + 4) == 0x1a) {
    iVar1 = (**(code **)(**(int **)(compiler + COMP_target) + 0x50))
                      (*(int **)(compiler + COMP_target),*(undefined4 *)(this + 8));
    IRInst__setOperandRef(iVar1,0,this);
    *(undefined4 *)(iVar1 + 0x9c) = DAT_001afee8;
    ((int (*)())FUN_0012306c)(this,iVar1);
    arena = *(undefined4 *)(compiler + COMP_arenaB);
    allocation = (undefined4 *)Arena__alloc(arena,0x240);
    puVar4 = allocation + 1;
    *allocation = arena;
    ValueKey__init(puVar4,iVar1,compiler);
    callResult = Compiler__isOptionEnabled(compiler,7);
    if (callResult != 0) {
      FUN_00174e0c(puVar4);
      ValueKey__propagateLaneValues(puVar4);
    }
    *(uint *)(*(int *)(compiler + COMP_target) + 8) = *(uint *)(*(int *)(compiler + COMP_target) + 8) | 0x20;
    (**(code **)(*param_2 + 0xc))(param_2,iVar1);
    ((int (*)())FUN_00122f28)(this,iVar1);
    return puVar4;
  }
  puVar2 = (undefined4 *)((int (*)())FUN_00123c08)(*(undefined4 *)(compiler + COMP_currentProgram),param_2,this);
  return puVar2;
}

/* ExportSlot__clone @ 0x1241fc (184 bytes) */
int ExportSlot__clone(this, param_2, compiler)
  undefined4 this;
  int *param_2;
  int compiler;
{
  undefined4 arena;
  undefined4 *allocation;
  int callResult;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  puVar5 = allocation + 1;
  *allocation = arena;
  IRLoad__ctor_109a80(puVar5,0xfa,compiler);
  IRInst__setOperandRef(puVar5,0,this);
  uVar4 = DAT_001afee8;
  allocation[6] = allocation[6] & 0xffff7fff;
  allocation[0x28] = uVar4;
  arena = *(undefined4 *)(compiler + COMP_arenaB);
  allocation = (undefined4 *)Arena__alloc(arena,0x240);
  puVar3 = allocation + 1;
  *allocation = arena;
  ValueKey__init(puVar3,puVar5,compiler);
  callResult = Compiler__isOptionEnabled(compiler,7);
  if (callResult != 0) {
    FUN_00174e0c(puVar3);
    ValueKey__propagateLaneValues(puVar3);
  }
  ((int (*)())FUN_0012306c)(this,puVar5);
  (**(code **)(*param_2 + 0xc))(param_2,puVar5);
  ((int (*)())FUN_00122f28)(this,puVar5);
  return puVar3;
}

/* Resource__clone @ 0x12434c (152 bytes) */
int Resource__clone(this, param_2, compiler)
  undefined4 this;
  int *param_2;
  int compiler;
{
  undefined4 *allocation;
  int callResult;
  undefined4 *puVar3;
  undefined4 arena;
  undefined4 *puVar5;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  puVar5 = allocation + 1;
  *allocation = arena;
  IRLoadTemp__ctor_109348(puVar5,this,compiler);
  IRInst__setOperandRef(puVar5,0,this);
  arena = *(undefined4 *)(compiler + COMP_arenaB);
  allocation = (undefined4 *)Arena__alloc(arena,0x240);
  puVar3 = allocation + 1;
  *allocation = arena;
  ValueKey__init(puVar3,puVar5,compiler);
  callResult = Compiler__isOptionEnabled(compiler,7);
  if (callResult != 0) {
    FUN_00174e0c(puVar3);
    ValueKey__propagateLaneValues(puVar3);
  }
  ((int (*)())FUN_0012306c)(this,puVar5);
  (**(code **)(*param_2 + 0xc))(param_2,puVar5);
  ((int (*)())FUN_00122f28)(this,puVar5);
  return puVar3;
}

/* FixedValue__clone @ 0x12447c (148 bytes) */
int FixedValue__clone(this, param_2, compiler)
  undefined4 this;
  int *param_2;
  int compiler;
{
  undefined4 *allocation;
  int callResult;
  undefined4 *puVar3;
  undefined4 arena;
  undefined4 *puVar5;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  puVar5 = allocation + 1;
  *allocation = arena;
  IRLoadConst__ctor_109938(puVar5,compiler);
  IRInst__setOperandRef(puVar5,0,this);
  arena = *(undefined4 *)(compiler + COMP_arenaB);
  allocation = (undefined4 *)Arena__alloc(arena,0x240);
  puVar3 = allocation + 1;
  *allocation = arena;
  ValueKey__init(puVar3,puVar5,compiler);
  callResult = Compiler__isOptionEnabled(compiler,7);
  if (callResult != 0) {
    FUN_00174e0c(puVar3);
    ValueKey__propagateLaneValues(puVar3);
  }
  ((int (*)())FUN_0012306c)(this,puVar5);
  (**(code **)(*param_2 + 0xc))(param_2,puVar5);
  ((int (*)())FUN_00122f28)(this,puVar5);
  return puVar3;
}

/* FixedValue__ctor_1245a8 @ 0x1245a8 (304 bytes) */
int FixedValue__ctor_1245a8(this, param_2, param_3, param_4, compiler)
  undefined4 *this;
  int param_2;
  int param_3;
  undefined4 param_4;
  int compiler;
{
  undefined4 *allocation;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 arena;
  
  ((int (*)())VRegInfo__ctor_12379c)(this,param_2,param_3,param_4,compiler);
  this[4] = param_2;
  *this = &PTR_FUN_001ea898;
  *(int *)(compiler + 0x338) = *(int *)(compiler + 0x338) + 1;
  if (param_3 == 3) {
    if (*(int *)(*(int *)(compiler + COMP_target) + 0x24) <= param_2) {
      Compiler__fail(compiler,10);
    }
  }
  else if (param_3 == 4) {
    if (*(int *)(*(int *)(compiler + COMP_target) + 0x28) <= param_2) {
      Compiler__fail(compiler,0xc);
    }
  }
  else if ((param_3 == 2) && (*(int *)(*(int *)(compiler + COMP_target) + 0x2c) <= param_2)) {
    Compiler__fail(compiler,0xb);
  }
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  puVar3 = allocation + 1;
  *allocation = arena;
  IRLoadConst__ctor_109614(puVar3,this,compiler);
  piVar2 = *(int **)(*(int *)(compiler + COMP_currentProgram) + 0x3a0);
  (**(code **)(*piVar2 + 0xc))(piVar2,puVar3);
  IRInst__setOperandRef(puVar3,0,this);
  ((int (*)())FUN_0012306c)(this,puVar3);
  return;
}

/* FixedValue__ctor_124724 @ 0x124724 (304 bytes) */
int FixedValue__ctor_124724(this, param_2, param_3, param_4, compiler)
  undefined4 *this;
  int param_2;
  int param_3;
  undefined4 param_4;
  int compiler;
{
  undefined4 *allocation;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 arena;
  
  ((int (*)())VRegInfo__ctor_12379c)(this,param_2,param_3,param_4,compiler);
  this[4] = param_2;
  *this = &PTR_FUN_001ea898;
  *(int *)(compiler + 0x338) = *(int *)(compiler + 0x338) + 1;
  if (param_3 == 3) {
    if (*(int *)(*(int *)(compiler + COMP_target) + 0x24) <= param_2) {
      Compiler__fail(compiler,10);
    }
  }
  else if (param_3 == 4) {
    if (*(int *)(*(int *)(compiler + COMP_target) + 0x28) <= param_2) {
      Compiler__fail(compiler,0xc);
    }
  }
  else if ((param_3 == 2) && (*(int *)(*(int *)(compiler + COMP_target) + 0x2c) <= param_2)) {
    Compiler__fail(compiler,0xb);
  }
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  puVar3 = allocation + 1;
  *allocation = arena;
  IRLoadConst__ctor_109614(puVar3,this,compiler);
  piVar2 = *(int **)(*(int *)(compiler + COMP_currentProgram) + 0x3a0);
  (**(code **)(*piVar2 + 0xc))(piVar2,puVar3);
  IRInst__setOperandRef(puVar3,0,this);
  ((int (*)())FUN_0012306c)(this,puVar3);
  return;
}

/* VertexRegister__ctor_1248a0 @ 0x1248a0 (76 bytes) */
int VertexRegister__ctor_1248a0(this, param_2, param_3, param_4, compiler)
  undefined4 *this;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 compiler;
{
  ((int (*)())VRegInfo__ctor_12379c)(this,param_2,param_3,param_4,compiler);
  this[4] = param_2;
  *this = &PTR_FUN_001ea860;
  return;
}

/* VertexRegister__ctor_1248ec @ 0x1248ec (76 bytes) */
int VertexRegister__ctor_1248ec(this, param_2, param_3, param_4, compiler)
  undefined4 *this;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 compiler;
{
  ((int (*)())VRegInfo__ctor_12379c)(this,param_2,param_3,param_4,compiler);
  this[4] = param_2;
  *this = &PTR_FUN_001ea860;
  return;
}

/* TempValue__ctor_124938 @ 0x124938 (100 bytes) */
int TempValue__ctor_124938(this, param_2, param_3, param_4, compiler)
  undefined4 *this;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int compiler;
{
  int iVar1;
  
  ((int (*)())VRegInfo__ctor_12379c)(this,param_2,param_3,param_4,compiler);
  *this = &PTR_FUN_001ea7b8;
  iVar1 = *(int *)(compiler + 0x334);
  this[4] = iVar1;
  this[7] = iVar1;
  *(int *)(compiler + 0x334) = iVar1 + 1;
  this[0xc] = 0;
  return;
}

/* PrimitiveIndex__ctor_12499c @ 0x12499c (300 bytes) */
int PrimitiveIndex__ctor_12499c(this, param_2, param_3, param_4, compiler)
  undefined4 *this;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int compiler;
{
  undefined4 arena;
  undefined4 uVar1;
  undefined4 *allocation;
  int iVar3;
  undefined4 in_r8;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 local_38 [7];
  
  iVar3 = compiler;
  ((int (*)())TempValue__ctor_124938)(this,param_2,param_3,param_4,compiler);
  *this = PTR_DAT_001e90c8 + 8;
  local_38[0] = 0x10203;
  iVar4 = *(int *)(compiler + COMP_currentProgram);
  uVar1 = (**(code **)(**(int **)(compiler + COMP_target) + 0xa4))
                    (*(int **)(compiler + COMP_target),local_38,compiler,param_4,iVar3,in_r8,0x10203);
  uVar1 = FUN_00127608(*(undefined4 *)(iVar4 + 0x3ac),0x10,uVar1,0);
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  puVar6 = allocation + 1;
  *allocation = arena;
  IRLoadTemp__ctor_109348(puVar6,this,compiler);
  Block__prependInst(*(undefined4 *)(iVar4 + 0x3a0),puVar6);
  IRInst__setOperandRef(puVar6,0,uVar1);
  ((int (*)())FUN_0012306c)(uVar1,puVar6);
  uVar5 = IRMov__new_1084b8(0x31,compiler);
  IRInst__setOperandRef(uVar5,1,uVar1);
  uVar1 = local_38[0];
  iVar3 = IRInst__getOperandRecord(uVar5,1);
  *(undefined4 *)(iVar3 + 0x10) = uVar1;
  IRInst__setOperandRef(uVar5,0,this);
  ((int (*)())FUN_0012306c)(this,uVar5);
  Block__appendInst(*(undefined4 *)(iVar4 + 0x3a0),uVar5);
  return;
}

/* StandardIndex__ctor_124b24 @ 0x124b24 (276 bytes) */
int StandardIndex__ctor_124b24(this, param_2, param_3, param_4, compiler)
  undefined4 *this;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  int compiler;
{
  undefined4 arena;
  int iVar1;
  undefined4 uVar2;
  undefined4 *allocation;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  
  ((int (*)())TempValue__ctor_124938)(this,param_2,param_3,param_4,compiler);
  *this = PTR_DAT_001e90e0 + 8;
  iVar5 = *(int *)(compiler + COMP_currentProgram);
  iVar1 = *(int *)(param_2 * 4 + iVar5 + 0x38);
  if (iVar1 == 0) {
    uVar2 = FUN_00127608(*(undefined4 *)(iVar5 + 0x3ac),0x10,param_2,0);
    arena = *(undefined4 *)(compiler + COMP_arenaA);
    allocation = (undefined4 *)Arena__alloc(arena,0x168);
    puVar6 = allocation + 1;
    *allocation = arena;
    IRLoadTemp__ctor_109348(puVar6,this,compiler);
    Block__prependInst(*(undefined4 *)(iVar5 + 0x3a0),puVar6);
    IRInst__setOperandRef(puVar6,0,uVar2);
    ((int (*)())FUN_0012306c)(uVar2,puVar6);
    *(undefined4 **)(param_2 * 4 + iVar5 + 0x38) = puVar6;
  }
  else {
    uVar2 = *(undefined4 *)(iVar1 + 0x8c);
  }
  uVar4 = IRMov__new_1084b8(0x31,compiler);
  IRInst__setOperandRef(uVar4,1,uVar2);
  IRInst__setOperandRef(uVar4,0,this);
  ((int (*)())FUN_0012306c)(this,uVar4);
  Block__appendInst(*(undefined4 *)(iVar5 + 0x3a0),uVar4);
  return;
}

/* StandardIndex__ctor_124c94 @ 0x124c94 (276 bytes) */
int StandardIndex__ctor_124c94(this, param_2, param_3, param_4, compiler)
  undefined4 *this;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  int compiler;
{
  undefined4 arena;
  int iVar1;
  undefined4 uVar2;
  undefined4 *allocation;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  
  ((int (*)())TempValue__ctor_124938)(this,param_2,param_3,param_4,compiler);
  *this = PTR_DAT_001e90e0 + 8;
  iVar5 = *(int *)(compiler + COMP_currentProgram);
  iVar1 = *(int *)(param_2 * 4 + iVar5 + 0x38);
  if (iVar1 == 0) {
    uVar2 = FUN_00127608(*(undefined4 *)(iVar5 + 0x3ac),0x10,param_2,0);
    arena = *(undefined4 *)(compiler + COMP_arenaA);
    allocation = (undefined4 *)Arena__alloc(arena,0x168);
    puVar6 = allocation + 1;
    *allocation = arena;
    IRLoadTemp__ctor_109348(puVar6,this,compiler);
    Block__prependInst(*(undefined4 *)(iVar5 + 0x3a0),puVar6);
    IRInst__setOperandRef(puVar6,0,uVar2);
    ((int (*)())FUN_0012306c)(uVar2,puVar6);
    *(undefined4 **)(param_2 * 4 + iVar5 + 0x38) = puVar6;
  }
  else {
    uVar2 = *(undefined4 *)(iVar1 + 0x8c);
  }
  uVar4 = IRMov__new_1084b8(0x31,compiler);
  IRInst__setOperandRef(uVar4,1,uVar2);
  IRInst__setOperandRef(uVar4,0,this);
  ((int (*)())FUN_0012306c)(this,uVar4);
  Block__appendInst(*(undefined4 *)(iVar5 + 0x3a0),uVar4);
  return;
}

/* TempValue__ctor_124e04 @ 0x124e04 (100 bytes) */
int TempValue__ctor_124e04(this, param_2, param_3, param_4, compiler)
  undefined4 *this;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int compiler;
{
  int iVar1;
  
  ((int (*)())VRegInfo__ctor_12379c)(this,param_2,param_3,param_4,compiler);
  *this = &PTR_FUN_001ea7b8;
  iVar1 = *(int *)(compiler + 0x334);
  this[4] = iVar1;
  this[7] = iVar1;
  *(int *)(compiler + 0x334) = iVar1 + 1;
  this[0xc] = 0;
  return;
}

/* ExportValue__ctor_124e68 @ 0x124e68 (552 bytes) */
int ExportValue__ctor_124e68(this, indexValue, param_3, param_4, compiler)
  undefined4 *this;
  undefined4 indexValue;
  int param_3;
  undefined4 param_4;
  int compiler;
{
  undefined4 arena;
  int operandRecord;
  undefined4 *allocation;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_28 [3];
  
  ((int (*)())VRegInfo__ctor_12379c)(this,indexValue,param_3,param_4,compiler);
  this[0xd] = 0;
  *this = &PTR_FUN_001ea748;
  this[0xc] = 0;
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  puVar5 = allocation + 1;
  *allocation = arena;
  IRExport__ctor_108918(puVar5,compiler);
  iVar4 = *(int *)(compiler + COMP_currentProgram);
  Block__prependInst(*(undefined4 *)(iVar4 + 0x3a8),puVar5);
  IRInst__setOperandRef(puVar5,0,this);
  ((int (*)())FUN_0012306c)(this,puVar5);
  this[0xc] = puVar5;
  allocation[0x50] = param_3;
  allocation[0x51] = indexValue;
  uVar3 = FUN_000ec258(iVar4,param_3);
  uVar3 = FUN_000ec2a0(iVar4,uVar3);
  IRLoadInterp__setLaneKindAndIndex(puVar5,0,uVar3,indexValue);
  uVar3 = FUN_000ec258(iVar4,param_3);
  uVar3 = FUN_000ec2a0(iVar4,uVar3);
  IRLoadInterp__setLaneKindAndIndex(puVar5,1,uVar3,indexValue);
  uVar3 = FUN_000ec258(iVar4,param_3);
  uVar3 = FUN_000ec2a0(iVar4,uVar3);
  IRLoadInterp__setLaneKindAndIndex(puVar5,2,uVar3,indexValue);
  uVar3 = FUN_000ec258(iVar4,param_3);
  uVar3 = FUN_000ec2a0(iVar4,uVar3);
  IRLoadInterp__setLaneKindAndIndex(puVar5,3,uVar3,indexValue);
  uVar3 = *(undefined4 *)(iVar4 + 0x3ac);
  iVar2 = *(int *)(compiler + 0x3ac) + -1;
  *(int *)(compiler + 0x3ac) = iVar2;
  uVar3 = FUN_001275a0(uVar3,0,iVar2,0);
  this[0xd] = uVar3;
  IRInst__setOperandRef(puVar5,1,uVar3);
  ((int (*)())VReg__addUse)(this[0xd],1,puVar5);
  uVar3 = DAT_001afeec;
  if (param_3 == 8) {
    operandRecord = IRInst__getOperandRecord(puVar5,1);
    *(undefined4 *)(operandRecord + 0x10) = uVar3;
    (**(code **)(**(int **)(compiler + COMP_target) + 0x118))(local_28);
    allocation[0x28] = local_28[0];
    *(undefined4 **)(iVar4 + 0x34c) = puVar5;
  }
  else if (param_3 == 9) {
    if (this[2] == 0) {
      *(undefined4 **)(iVar4 + 0x348) = puVar5;
    }
  }
  else if (param_3 == 6) {
    *(undefined4 **)(iVar4 + 0x358) = puVar5;
  }
  else if (param_3 == 7) {
    *(undefined4 **)(iVar4 + 0x35c) = puVar5;
    *(undefined4 *)(iVar4 + 0x368) = 1;
  }
  return;
}

/* ExportValue__ctor_1250dc @ 0x1250dc (552 bytes) */
int ExportValue__ctor_1250dc(this, indexValue, param_3, param_4, compiler)
  undefined4 *this;
  undefined4 indexValue;
  int param_3;
  undefined4 param_4;
  int compiler;
{
  undefined4 arena;
  int operandRecord;
  undefined4 *allocation;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_28 [3];
  
  ((int (*)())VRegInfo__ctor_12379c)(this,indexValue,param_3,param_4,compiler);
  this[0xd] = 0;
  *this = &PTR_FUN_001ea748;
  this[0xc] = 0;
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  puVar5 = allocation + 1;
  *allocation = arena;
  IRExport__ctor_108918(puVar5,compiler);
  iVar4 = *(int *)(compiler + COMP_currentProgram);
  Block__prependInst(*(undefined4 *)(iVar4 + 0x3a8),puVar5);
  IRInst__setOperandRef(puVar5,0,this);
  ((int (*)())FUN_0012306c)(this,puVar5);
  this[0xc] = puVar5;
  allocation[0x50] = param_3;
  allocation[0x51] = indexValue;
  uVar3 = FUN_000ec258(iVar4,param_3);
  uVar3 = FUN_000ec2a0(iVar4,uVar3);
  IRLoadInterp__setLaneKindAndIndex(puVar5,0,uVar3,indexValue);
  uVar3 = FUN_000ec258(iVar4,param_3);
  uVar3 = FUN_000ec2a0(iVar4,uVar3);
  IRLoadInterp__setLaneKindAndIndex(puVar5,1,uVar3,indexValue);
  uVar3 = FUN_000ec258(iVar4,param_3);
  uVar3 = FUN_000ec2a0(iVar4,uVar3);
  IRLoadInterp__setLaneKindAndIndex(puVar5,2,uVar3,indexValue);
  uVar3 = FUN_000ec258(iVar4,param_3);
  uVar3 = FUN_000ec2a0(iVar4,uVar3);
  IRLoadInterp__setLaneKindAndIndex(puVar5,3,uVar3,indexValue);
  uVar3 = *(undefined4 *)(iVar4 + 0x3ac);
  iVar2 = *(int *)(compiler + 0x3ac) + -1;
  *(int *)(compiler + 0x3ac) = iVar2;
  uVar3 = FUN_001275a0(uVar3,0,iVar2,0);
  this[0xd] = uVar3;
  IRInst__setOperandRef(puVar5,1,uVar3);
  ((int (*)())VReg__addUse)(this[0xd],1,puVar5);
  uVar3 = DAT_001afeec;
  if (param_3 == 8) {
    operandRecord = IRInst__getOperandRecord(puVar5,1);
    *(undefined4 *)(operandRecord + 0x10) = uVar3;
    (**(code **)(**(int **)(compiler + COMP_target) + 0x118))(local_28);
    allocation[0x28] = local_28[0];
    *(undefined4 **)(iVar4 + 0x34c) = puVar5;
  }
  else if (param_3 == 9) {
    if (this[2] == 0) {
      *(undefined4 **)(iVar4 + 0x348) = puVar5;
    }
  }
  else if (param_3 == 6) {
    *(undefined4 **)(iVar4 + 0x358) = puVar5;
  }
  else if (param_3 == 7) {
    *(undefined4 **)(iVar4 + 0x35c) = puVar5;
    *(undefined4 *)(iVar4 + 0x368) = 1;
  }
  return;
}

/* Interpolator__ctor_125350 @ 0x125350 (988 bytes) */
int Interpolator__ctor_125350(this, indexValue, param_3, param_4, compiler)
  undefined4 *this;
  undefined4 indexValue;
  int param_3;
  undefined4 param_4;
  int compiler;
{
  undefined4 arena;
  int operandRecord;
  bool bVar1;
  int iVar2;
  undefined4 *allocation;
  undefined4 uVar4;
  undefined4 *allocation2;
  undefined4 arena2;
  int iVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  int local_48;
  undefined4 local_44 [3];
  undefined4 local_38 [3];
  
  ((int (*)())VRegInfo__ctor_12379c)(this,indexValue,param_3,param_4,compiler);
  this[0xf] = 0;
  *this = &PTR_FUN_001ea780;
  this[0xc] = 0;
  this[0xd] = 0;
  this[0xe] = 0;
  iVar7 = *(int *)(compiler + COMP_currentProgram);
  if ((*(uint *)(iVar7 + 0x30) & 0x2000) != 0) {
    iVar2 = RegKind__flagBit0(this[1]);
    if (iVar2 != 0) {
      iVar2 = *(int *)(compiler + 0x334);
      this[7] = iVar2;
      *(int *)(compiler + 0x334) = iVar2 + 1;
      this[4] = indexValue;
    }
    arena = *(undefined4 *)(compiler + COMP_arenaA);
    allocation = (undefined4 *)Arena__alloc(arena,0x168);
    puVar9 = allocation + 1;
    *allocation = arena;
    IRLoadInterp__ctor_109198(puVar9,compiler);
    this[0xe] = puVar9;
    (**(code **)(**(int **)(iVar7 + 0x3a0) + 0xc))(*(int **)(iVar7 + 0x3a0),puVar9);
    IRInst__setOperandRef(this[0xe],0,this);
    ((int (*)())FUN_0012306c)(this,this[0xe]);
    *(int *)(this[0xe] + 0x144) = param_3;
    *(undefined4 *)(this[0xe] + 0x148) = indexValue;
    return;
  }
  if ((*(uint *)(iVar7 + 0x30) & 1) == 0) {
    return;
  }
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  puVar9 = allocation + 1;
  *allocation = arena;
  IRExport__ctor_108918(puVar9,compiler);
  Block__appendInst(*(undefined4 *)(iVar7 + 0x3a8),puVar9);
  IRInst__setOperandRef(puVar9,0,this);
  ((int (*)())FUN_0012306c)(this,puVar9);
  this[0xc] = puVar9;
  uVar8 = *(undefined4 *)(iVar7 + 0x3ac);
  iVar2 = *(int *)(compiler + 0x3ac) + -1;
  *(int *)(compiler + 0x3ac) = iVar2;
  uVar8 = FUN_001275a0(uVar8,0,iVar2,0);
  this[0xf] = uVar8;
  iVar2 = (**(code **)(**(int **)(compiler + COMP_target) + 0x120))
                    (*(int **)(compiler + COMP_target),iVar7,compiler);
  if (iVar2 == 0) goto LAB_00125660;
  local_48 = 6;
  local_44[0] = 0;
  iVar2 = FUN_00127324(*(undefined4 *)(iVar7 + 0x3ac),this[1],indexValue,&local_48,local_44);
  if (iVar2 == 0) goto LAB_00125660;
  uVar8 = 0xd;
  if (local_48 != 0x3f) {
    if (local_48 < 0x40) {
      uVar8 = 0xb;
      if (local_48 != 0x3e) {
LAB_00125578:
        uVar8 = 5;
      }
    }
    else {
      uVar8 = 0xe;
      if ((local_48 != 0x40) && (uVar8 = 0xc, local_48 != 0x41)) goto LAB_00125578;
    }
  }
  uVar4 = FUN_001275a0(*(undefined4 *)(iVar7 + 0x3ac),local_48,local_44[0],0);
  arena2 = *(undefined4 *)(compiler + COMP_arenaA);
  allocation2 = (undefined4 *)Arena__alloc(arena2,0x168);
  puVar10 = allocation2 + 1;
  *allocation2 = arena2;
  IRExport__ctor_108918(puVar10,compiler);
  this[0xd] = puVar10;
  Block__appendInst(*(undefined4 *)(iVar7 + 0x3a8),puVar10);
  IRInst__setOperandRef(this[0xd],1,this[0xf]);
  IRInst__setOperandRef(this[0xd],0,uVar4);
  *(undefined4 *)(this[0xd] + 0x9c) = DAT_001afef8;
  ((int (*)())FUN_0012306c)(uVar4,this[0xd]);
  iVar2 = 0;
  do {
    IRLoadInterp__setLaneKindAndIndex(this[0xd],iVar2,uVar8,local_44[0]);
    bVar1 = iVar2 != 3;
    iVar2 = iVar2 + 1;
  } while (bVar1);
LAB_00125660:
  IRInst__setOperandRef(puVar9,1,this[0xf]);
  ((int (*)())VReg__addUse)(this[0xf],1,puVar9);
  allocation[0x50] = param_3;
  allocation[0x51] = indexValue;
  uVar8 = FUN_000ec258(iVar7,param_3);
  uVar8 = FUN_000ec2a0(iVar7,uVar8);
  IRLoadInterp__setLaneKindAndIndex(puVar9,0,uVar8,indexValue);
  uVar8 = FUN_000ec258(iVar7,param_3);
  uVar8 = FUN_000ec2a0(iVar7,uVar8);
  IRLoadInterp__setLaneKindAndIndex(puVar9,1,uVar8,indexValue);
  uVar8 = FUN_000ec258(iVar7,param_3);
  uVar8 = FUN_000ec2a0(iVar7,uVar8);
  IRLoadInterp__setLaneKindAndIndex(puVar9,2,uVar8,indexValue);
  uVar8 = FUN_000ec258(iVar7,param_3);
  uVar8 = FUN_000ec2a0(iVar7,uVar8);
  IRLoadInterp__setLaneKindAndIndex(puVar9,3,uVar8,indexValue);
  uVar8 = DAT_001afeec;
  if (param_3 == 0x18) {
    operandRecord = IRInst__getOperandRecord(puVar9,1);
    *(undefined4 *)(operandRecord + 0x10) = uVar8;
    (**(code **)(**(int **)(compiler + COMP_target) + 0x1c))(local_38);
    allocation[0x28] = local_38[0];
  }
  return;
}

/* Interpolator__ctor_1257b0 @ 0x1257b0 (988 bytes) */
int Interpolator__ctor_1257b0(this, indexValue, param_3, param_4, compiler)
  undefined4 *this;
  undefined4 indexValue;
  int param_3;
  undefined4 param_4;
  int compiler;
{
  undefined4 arena;
  int operandRecord;
  bool bVar1;
  int iVar2;
  undefined4 *allocation;
  undefined4 uVar4;
  undefined4 *allocation2;
  undefined4 arena2;
  int iVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  int local_48;
  undefined4 local_44 [3];
  undefined4 local_38 [3];
  
  ((int (*)())VRegInfo__ctor_12379c)(this,indexValue,param_3,param_4,compiler);
  this[0xf] = 0;
  *this = &PTR_FUN_001ea780;
  this[0xc] = 0;
  this[0xd] = 0;
  this[0xe] = 0;
  iVar7 = *(int *)(compiler + COMP_currentProgram);
  if ((*(uint *)(iVar7 + 0x30) & 0x2000) != 0) {
    iVar2 = RegKind__flagBit0(this[1]);
    if (iVar2 != 0) {
      iVar2 = *(int *)(compiler + 0x334);
      this[7] = iVar2;
      *(int *)(compiler + 0x334) = iVar2 + 1;
      this[4] = indexValue;
    }
    arena = *(undefined4 *)(compiler + COMP_arenaA);
    allocation = (undefined4 *)Arena__alloc(arena,0x168);
    puVar9 = allocation + 1;
    *allocation = arena;
    IRLoadInterp__ctor_109198(puVar9,compiler);
    this[0xe] = puVar9;
    (**(code **)(**(int **)(iVar7 + 0x3a0) + 0xc))(*(int **)(iVar7 + 0x3a0),puVar9);
    IRInst__setOperandRef(this[0xe],0,this);
    ((int (*)())FUN_0012306c)(this,this[0xe]);
    *(int *)(this[0xe] + 0x144) = param_3;
    *(undefined4 *)(this[0xe] + 0x148) = indexValue;
    return;
  }
  if ((*(uint *)(iVar7 + 0x30) & 1) == 0) {
    return;
  }
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  puVar9 = allocation + 1;
  *allocation = arena;
  IRExport__ctor_108918(puVar9,compiler);
  Block__appendInst(*(undefined4 *)(iVar7 + 0x3a8),puVar9);
  IRInst__setOperandRef(puVar9,0,this);
  ((int (*)())FUN_0012306c)(this,puVar9);
  this[0xc] = puVar9;
  uVar8 = *(undefined4 *)(iVar7 + 0x3ac);
  iVar2 = *(int *)(compiler + 0x3ac) + -1;
  *(int *)(compiler + 0x3ac) = iVar2;
  uVar8 = FUN_001275a0(uVar8,0,iVar2,0);
  this[0xf] = uVar8;
  iVar2 = (**(code **)(**(int **)(compiler + COMP_target) + 0x120))
                    (*(int **)(compiler + COMP_target),iVar7,compiler);
  if (iVar2 == 0) goto LAB_00125ac0;
  local_48 = 6;
  local_44[0] = 0;
  iVar2 = FUN_00127324(*(undefined4 *)(iVar7 + 0x3ac),this[1],indexValue,&local_48,local_44);
  if (iVar2 == 0) goto LAB_00125ac0;
  uVar8 = 0xd;
  if (local_48 != 0x3f) {
    if (local_48 < 0x40) {
      uVar8 = 0xb;
      if (local_48 != 0x3e) {
LAB_001259d8:
        uVar8 = 5;
      }
    }
    else {
      uVar8 = 0xe;
      if ((local_48 != 0x40) && (uVar8 = 0xc, local_48 != 0x41)) goto LAB_001259d8;
    }
  }
  uVar4 = FUN_001275a0(*(undefined4 *)(iVar7 + 0x3ac),local_48,local_44[0],0);
  arena2 = *(undefined4 *)(compiler + COMP_arenaA);
  allocation2 = (undefined4 *)Arena__alloc(arena2,0x168);
  puVar10 = allocation2 + 1;
  *allocation2 = arena2;
  IRExport__ctor_108918(puVar10,compiler);
  this[0xd] = puVar10;
  Block__appendInst(*(undefined4 *)(iVar7 + 0x3a8),puVar10);
  IRInst__setOperandRef(this[0xd],1,this[0xf]);
  IRInst__setOperandRef(this[0xd],0,uVar4);
  *(undefined4 *)(this[0xd] + 0x9c) = DAT_001afef8;
  ((int (*)())FUN_0012306c)(uVar4,this[0xd]);
  iVar2 = 0;
  do {
    IRLoadInterp__setLaneKindAndIndex(this[0xd],iVar2,uVar8,local_44[0]);
    bVar1 = iVar2 != 3;
    iVar2 = iVar2 + 1;
  } while (bVar1);
LAB_00125ac0:
  IRInst__setOperandRef(puVar9,1,this[0xf]);
  ((int (*)())VReg__addUse)(this[0xf],1,puVar9);
  allocation[0x50] = param_3;
  allocation[0x51] = indexValue;
  uVar8 = FUN_000ec258(iVar7,param_3);
  uVar8 = FUN_000ec2a0(iVar7,uVar8);
  IRLoadInterp__setLaneKindAndIndex(puVar9,0,uVar8,indexValue);
  uVar8 = FUN_000ec258(iVar7,param_3);
  uVar8 = FUN_000ec2a0(iVar7,uVar8);
  IRLoadInterp__setLaneKindAndIndex(puVar9,1,uVar8,indexValue);
  uVar8 = FUN_000ec258(iVar7,param_3);
  uVar8 = FUN_000ec2a0(iVar7,uVar8);
  IRLoadInterp__setLaneKindAndIndex(puVar9,2,uVar8,indexValue);
  uVar8 = FUN_000ec258(iVar7,param_3);
  uVar8 = FUN_000ec2a0(iVar7,uVar8);
  IRLoadInterp__setLaneKindAndIndex(puVar9,3,uVar8,indexValue);
  uVar8 = DAT_001afeec;
  if (param_3 == 0x18) {
    operandRecord = IRInst__getOperandRecord(puVar9,1);
    *(undefined4 *)(operandRecord + 0x10) = uVar8;
    (**(code **)(**(int **)(compiler + COMP_target) + 0x1c))(local_38);
    allocation[0x28] = local_38[0];
  }
  return;
}

/* Physical__ctor_125c10 @ 0x125c10 (104 bytes) */
int Physical__ctor_125c10(this, hwReg, param_3, param_4, compiler)
  undefined4 *this;
  undefined4 hwReg;
  undefined4 param_3;
  undefined4 param_4;
  int compiler;
{
  ((int (*)())VRegInfo__ctor_12379c)(this,hwReg,param_3,param_4,compiler);
  *this = PTR_DAT_001e90d8 + 8;
  Program__markHwRegUsed(*(undefined4 *)(compiler + 0x6c4),hwReg);
  this[4] = hwReg;
  this[9] = this[9] | 2;
  return;
}

/* Physical__ctor_125c8c @ 0x125c8c (104 bytes) */
int Physical__ctor_125c8c(this, hwReg, param_3, param_4, compiler)
  undefined4 *this;
  undefined4 hwReg;
  undefined4 param_3;
  undefined4 param_4;
  int compiler;
{
  ((int (*)())VRegInfo__ctor_12379c)(this,hwReg,param_3,param_4,compiler);
  *this = PTR_DAT_001e90d8 + 8;
  Program__markHwRegUsed(*(undefined4 *)(compiler + 0x6c4),hwReg);
  this[4] = hwReg;
  this[9] = this[9] | 2;
  return;
}

/* Resource__ctor_125d08 @ 0x125d08 (88 bytes) */
int Resource__ctor_125d08(this, param_2, param_3, param_4, compiler)
  undefined4 *this;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 compiler;
{
  ((int (*)())VRegInfo__ctor_12379c)(this,param_2,param_3,param_4,compiler);
  this[4] = param_2 + param_3 * 0x10000;
  *this = &PTR_FUN_001ea828;
  return;
}

/* Resource__ctor_125d60 @ 0x125d60 (88 bytes) */
int Resource__ctor_125d60(this, param_2, param_3, param_4, compiler)
  undefined4 *this;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 compiler;
{
  ((int (*)())VRegInfo__ctor_12379c)(this,param_2,param_3,param_4,compiler);
  this[4] = param_2 + param_3 * 0x10000;
  *this = &PTR_FUN_001ea828;
  return;
}

/* PrimitiveIndex__ctor_125db8 @ 0x125db8 (300 bytes) */
int PrimitiveIndex__ctor_125db8(this, param_2, param_3, param_4, compiler)
  undefined4 *this;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int compiler;
{
  undefined4 arena;
  undefined4 uVar1;
  undefined4 *allocation;
  int iVar3;
  undefined4 in_r8;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 local_38 [7];
  
  iVar3 = compiler;
  ((int (*)())TempValue__ctor_124938)(this,param_2,param_3,param_4,compiler);
  *this = PTR_DAT_001e90c8 + 8;
  local_38[0] = 0x10203;
  iVar4 = *(int *)(compiler + COMP_currentProgram);
  uVar1 = (**(code **)(**(int **)(compiler + COMP_target) + 0xa4))
                    (*(int **)(compiler + COMP_target),local_38,compiler,param_4,iVar3,in_r8,0x10203);
  uVar1 = FUN_00127608(*(undefined4 *)(iVar4 + 0x3ac),0x10,uVar1,0);
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  puVar6 = allocation + 1;
  *allocation = arena;
  IRLoadTemp__ctor_109348(puVar6,this,compiler);
  Block__prependInst(*(undefined4 *)(iVar4 + 0x3a0),puVar6);
  IRInst__setOperandRef(puVar6,0,uVar1);
  ((int (*)())FUN_0012306c)(uVar1,puVar6);
  uVar5 = IRMov__new_1084b8(0x31,compiler);
  IRInst__setOperandRef(uVar5,1,uVar1);
  uVar1 = local_38[0];
  iVar3 = IRInst__getOperandRecord(uVar5,1);
  *(undefined4 *)(iVar3 + 0x10) = uVar1;
  IRInst__setOperandRef(uVar5,0,this);
  ((int (*)())FUN_0012306c)(this,uVar5);
  Block__appendInst(*(undefined4 *)(iVar4 + 0x3a0),uVar5);
  return;
}

/* AddrIndexedSet__ctor_125f40 @ 0x125f40 (84 bytes) */
int AddrIndexedSet__ctor_125f40(param_1, param_2, param_3, param_4, compiler)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 compiler;
{
  undefined *vtable;
  
  ((int (*)())VRegInfo__ctor_12379c)(param_1,param_2,param_3,param_4,compiler);
  vtable = PTR_DAT_001e90cc;
  param_1[0xc] = 0;
  param_1[4] = param_2;
  *param_1 = vtable + 8;
  return;
}

/* AddrIndexedSet__ctor_125f94 @ 0x125f94 (84 bytes) */
int AddrIndexedSet__ctor_125f94(param_1, param_2, param_3, param_4, compiler)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 compiler;
{
  undefined *vtable;
  
  ((int (*)())VRegInfo__ctor_12379c)(param_1,param_2,param_3,param_4,compiler);
  vtable = PTR_DAT_001e90cc;
  param_1[0xc] = 0;
  param_1[4] = param_2;
  *param_1 = vtable + 8;
  return;
}

/* LoopRegister__ctor_125fe8 @ 0x125fe8 (76 bytes) */
int LoopRegister__ctor_125fe8(param_1, param_2, param_3, param_4, compiler)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 compiler;
{
  undefined *vtable;
  
  ((int (*)())VRegInfo__ctor_12379c)(param_1,param_2,param_3,param_4,compiler);
  vtable = PTR_DAT_001e90e8;
  param_1[4] = param_2;
  *param_1 = vtable + 8;
  return;
}

/* LoopRegister__ctor_126034 @ 0x126034 (76 bytes) */
int LoopRegister__ctor_126034(param_1, param_2, param_3, param_4, compiler)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 compiler;
{
  undefined *vtable;
  
  ((int (*)())VRegInfo__ctor_12379c)(param_1,param_2,param_3,param_4,compiler);
  vtable = PTR_DAT_001e90e8;
  param_1[4] = param_2;
  *param_1 = vtable + 8;
  return;
}

/* LoopIndexedOutputSet__ctor_126080 @ 0x126080 (116 bytes) */
int LoopIndexedOutputSet__ctor_126080(this, param_2, param_3, param_4, compiler)
  undefined4 *this;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int compiler;
{
  undefined *vtable;
  
  ((int (*)())VRegInfo__ctor_12379c)(this,param_2,param_3,param_4,compiler);
  vtable = PTR_DAT_001e90ec;
  this[0xc] = 0;
  *this = vtable + 8;
  *this = PTR_DAT_001e90dc + 8;
  this[4] = *(undefined4 *)(compiler + 0x344);
  *(int *)(compiler + 0x344) = *(int *)(compiler + 0x344) + 1;
  return;
}


/* issue: auto-generated aliases bridging data.s/code.s references (written
 * without a leading underscore, matching the raw stock-binary symbol name)
 * against the real compiled C symbols (gcc adds one underscore automatically).
 * Needed because ld64 (required for this PPC binary's size - stock ld breaks on
 * large PPC links) does not silently reconcile this the way stock ld did. */
asm(".globl ExportValue__vslot10");
asm(".set ExportValue__vslot10, _ExportValue__vslot10");
asm(".globl FUN_001230e4");
asm(".set FUN_001230e4, _ImmedConstBuffer__clone");
asm(".globl FUN_00123288");
asm(".set FUN_00123288, _VertexRegister__clone");
asm(".globl Interpolator__vslot10");
asm(".set Interpolator__vslot10, _Interpolator__vslot10");
asm(".globl FUN_001240a8");
asm(".set FUN_001240a8, _TempValue__clone");
asm(".globl FUN_001241fc");
asm(".set FUN_001241fc, _ExportSlot__clone");
asm(".globl FUN_0012434c");
asm(".set FUN_0012434c, _Resource__clone");
asm(".globl FUN_0012447c");
asm(".set FUN_0012447c, _FixedValue__clone");
