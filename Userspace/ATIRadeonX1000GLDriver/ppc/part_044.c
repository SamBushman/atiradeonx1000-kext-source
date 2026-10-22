#include "decls.h"

/* FUN_00158988 @ 0x158988 (496 bytes) */
int FUN_00158988(param_1, inst, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  int *inst;
  int param_3;
  undefined4 param_4;
  uint param_5;
  int param_6;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint local_28 [5];
  
  *(int *)(param_6 + 0x1ac) = *(int *)(param_6 + 0x1ac) + 1;
LAB_001589b0:
  do {
    iVar2 = (**(code **)(*inst + 100))(inst);
    if (iVar2 == 0) {
LAB_00158b48:
      iVar2 = inst[0x49];
LAB_00158b4c:
      uVar1 = inst[5];
    }
    else {
      for (iVar2 = 1; iVar3 = (**(code **)(*inst + 0x14))(inst), iVar2 <= iVar3;
          iVar2 = iVar2 + 1) {
        if ((inst[iVar2 * 6 + 0x28] & 1U) != 0) goto LAB_00158b48;
        if (((inst[iVar2 * 6 + 0x28] & 2U) != 0) ||
           (iVar3 = FUN_000f31e8(inst,iVar2), iVar3 == 0)) goto LAB_00158b3c;
      }
      if (inst[0x48] == 0) {
        iVar2 = inst[0x49];
        if (iVar2 != 0) goto LAB_00158b4c;
        if ((((inst[0x20] != 0) && (iVar2 = FUN_00126760(inst[0x26]), iVar2 != 0)) &&
            ((inst[5] & 2U) == 0)) &&
           (iVar2 = (**(code **)(*inst + 0x50))(inst), iVar2 == 0)) {
          iVar2 = 4;
          piVar4 = inst;
          do {
            if ((uint)(*(byte *)(piVar4 + 0x27) - 2) < 2) goto LAB_00158b48;
            piVar4 = (int *)((int)piVar4 + 1);
            iVar2 = iVar2 + -1;
          } while (iVar2 != 0);
        }
        IRInst__getOperandRecord(inst,0);
        iVar2 = FUN_00105dbc(inst,0);
        if (iVar2 != 0) goto LAB_00158b48;
        uVar1 = inst[5];
        if (((uVar1 & 2) == 0) && ((uVar1 & 0x200) == 0)) {
          inst = (int *)IRInst__getOperandSource(inst,1);
          goto LAB_001589b0;
        }
        iVar2 = inst[0x49];
      }
      else {
LAB_00158b3c:
        iVar2 = inst[0x49];
        uVar1 = inst[5];
      }
    }
    inst[0x49] = param_3 + iVar2;
    while( true ) {
      if ((uVar1 & 0x200) == 0) {
        return;
      }
      inst = (int *)IRInst__getOperandSource(inst,inst[0x21]);
      iVar2 = IRInst__getOperandRecord(inst,0);
      FUN_000f3908(local_28,*(undefined4 *)(iVar2 + 0x10));
      if ((param_5 & local_28[0]) != 0) break;
      uVar1 = inst[5];
    }
  } while( true );
}

/* FUN_00158b78 @ 0x158b78 (196 bytes) */
int FUN_00158b78(param_1, param_2, inst, param_4, param_5, param_6)
  undefined4 param_1;
  int *param_2;
  undefined4 inst;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  int iVar1;
  int iVar2;
  
  iVar1 = (**(code **)(*param_2 + 100))(param_2,param_2,inst,param_4,param_5,param_6);
  if ((((iVar1 != 0) && (param_2[0x48] == 0)) && ((param_2[5] & 0x200U) == 0)) &&
     ((iVar1 = param_2[0x49], iVar1 != 0 &&
      (iVar2 = FUN_0015800c(param_1,inst,iVar1,param_5,param_6,param_4), iVar2 != 0)))) {
    ((int (*)())FUN_00158988)(param_2,inst,iVar1,param_5,param_6,param_4);
    param_2[0x49] = 0;
  }
  return;
}

/* FUN_00158c3c @ 0x158c3c (2424 bytes) */
int FUN_00158c3c(param_1, param_2)
  int param_1;
  int param_2;
{
  int *operandVReg;
  undefined4 uVar1;
  undefined4 uVar2;
  int *piVar3;
  int operandRecord;
  int *callResult;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined4 operandVReg2;
  uint uVar9;
  int *piVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  int iVar13;
  int iVar14;
  uint *puVar15;
  int iVar16;
  /* NOTE (issue #64): local_68/local_64/local_60 are passed by address (&local_68) to Arena__alloc/
   * Vector__removeAt/Vector__elementRefGrow as one contiguous 3-word vector struct (capacity, count, data-ptr).
   * Ghidra split it into 3 separate scalar locals, which -O0 does NOT lay out contiguously (confirmed
   * live: real stack deltas were 0x44/0x4 bytes, not 4/4) - forced into one array so the compiler
   * can't reorder/pad between them. */
  undefined4 local_68vec_158c3c[3];
#define local_68_vec local_68vec_158c3c[0]
#define local_64_vec local_68vec_158c3c[1]
#define local_60_vec local_68vec_158c3c[2]
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50 [6];
  
  local_5c = *(undefined4 *)(*(int *)(param_2 + 8) + 0x378);
  local_68_vec = 2;
  local_64_vec = 0;
  local_60_vec = Arena__alloc(local_5c,8);
  uVar9 = local_64_vec;
  if (local_64_vec < local_68_vec) {
    iVar13 = local_64_vec * 4;
    _memset(local_60_vec + iVar13,0,4);
    local_64_vec = uVar9 + 1;
    piVar3 = (int *)(iVar13 + local_60_vec);
  }
  else {
    piVar3 = (int *)Vector__elementRefGrow(&local_68_vec,local_64_vec);
  }
  *piVar3 = param_1;
  uVar11 = 0;
  do {
    uVar9 = local_64_vec - 1;
    piVar3 = (int *)0x0;
    if (uVar9 < local_64_vec) {
      piVar3 = (int *)(uVar9 * 4 + local_60_vec);
    }
    iVar16 = *piVar3;
    Vector__removeAt(&local_68_vec,uVar9);
    iVar13 = *(int *)(iVar16 + 0x124);
    iVar14 = *(int *)(*(int *)(iVar16 + 0x88) + 8);
    if (iVar14 - 0x12U < 3) {
      operandRecord = IRInst__getOperandRecord(iVar16,0);
      uVar12 = *(undefined4 *)(operandRecord + 0x10);
      operandRecord = IRInst__getOperandRecord(iVar16,1);
      FUN_000f3398(&local_58,*(undefined4 *)(operandRecord + 0x10));
      uVar1 = local_58;
      operandRecord = IRInst__getOperandRecord(iVar16,2);
      FUN_000f3398(&local_54,*(undefined4 *)(operandRecord + 0x10));
      uVar2 = local_54;
      operandVReg = (int *)IRInst__getOperandSource(iVar16,1);
      callResult = (int *)IRInst__getOperandSource(iVar16,2);
      if (iVar14 == 0x13) {
        iVar14 = IRInst__hasSingleUse(operandVReg,param_2);
        if ((iVar14 != 0) && (iVar14 = IRInst__hasSingleUse(callResult,param_2), iVar14 != 0)) {
          ((int (*)())FUN_00158b78)(iVar16,operandVReg,callResult,param_2,uVar12,uVar2);
          ((int (*)())FUN_00158b78)(iVar16,callResult,operandVReg,param_2,uVar12,uVar1);
        }
        if (iVar13 != 0) {
          iVar14 = FUN_0015800c(iVar16,operandVReg,iVar13,uVar12,uVar1,param_2);
          if (iVar14 == 0) {
            iVar14 = FUN_0015800c(iVar16,callResult,iVar13,uVar12,uVar2,param_2);
            if (iVar14 != 0) {
              ((int (*)())FUN_00158988)(iVar16,callResult,iVar13,uVar12,uVar2,param_2);
              *(undefined4 *)(iVar16 + 0x124) = 0;
              goto LAB_00158fc8;
            }
          }
          else {
            ((int (*)())FUN_00158988)(iVar16,operandVReg,iVar13,uVar12,uVar1,param_2);
            uVar9 = local_64_vec;
            *(undefined4 *)(iVar16 + 0x124) = 0;
            if (local_64_vec < local_68_vec) {
              iVar13 = local_64_vec * 4;
              _memset(iVar13 + local_60_vec,0,4);
              local_64_vec = uVar9 + 1;
              puVar6 = (undefined4 *)(iVar13 + local_60_vec);
            }
            else {
              puVar6 = (undefined4 *)Vector__elementRefGrow(&local_68_vec,local_64_vec);
            }
            *puVar6 = operandVReg;
          }
        }
      }
      else if (iVar14 == 0x14) {
        iVar14 = IRInst__hasSingleUse(operandVReg,param_2);
        if ((iVar14 != 0) && (iVar14 = IRInst__hasSingleUse(callResult,param_2), iVar14 != 0)) {
          ((int (*)())FUN_00158b78)(iVar16,operandVReg,callResult,param_2,uVar12,uVar2);
          ((int (*)())FUN_00158b78)(iVar16,callResult,operandVReg,param_2,uVar12,uVar1);
          iVar14 = (**(code **)(*operandVReg + 100))(operandVReg);
          if (iVar14 != 0) {
            puVar15 = (uint *)(operandVReg + 0x2e);
            for (iVar14 = 1; operandRecord = (**(code **)(*operandVReg + 0x14))(operandVReg), iVar14 <= operandRecord;
                iVar14 = iVar14 + 1) {
              uVar9 = *puVar15;
              puVar15 = puVar15 + 6;
              if ((((uVar9 & 1) != 0) || ((uVar9 & 2) != 0)) ||
                 (operandRecord = FUN_000f31e8(operandVReg,iVar14), operandRecord == 0)) goto LAB_00159218;
            }
            if ((operandVReg[0x48] == 0) && (operandVReg[0x49] == 0)) {
              if (((operandVReg[0x20] != 0) &&
                  ((iVar14 = FUN_00126760(operandVReg[0x26]), iVar14 != 0 && ((operandVReg[5] & 2U) == 0))))
                 && (iVar14 = (**(code **)(*operandVReg + 0x50))(operandVReg), iVar14 == 0)) {
                iVar14 = 4;
                piVar10 = operandVReg;
                do {
                  if ((uint)(*(byte *)(piVar10 + 0x27) - 2) < 2) goto LAB_00159218;
                  piVar10 = (int *)((int)piVar10 + 1);
                  iVar14 = iVar14 + -1;
                } while (iVar14 != 0);
              }
              IRInst__getOperandRecord(operandVReg,0);
              iVar14 = FUN_00105dbc(operandVReg,0);
              if (((iVar14 == 0) && ((operandVReg[5] & 2U) == 0)) && ((operandVReg[5] & 0x200U) == 0)) {
                *(int *)(param_2 + 0x17c) = *(int *)(param_2 + 0x17c) + 1;
                uVar7 = IRInst__getOperandSource(operandVReg,1);
                IRInst__setOperandSource(iVar16,1,uVar7,0,*(undefined4 *)(param_2 + 8));
                iVar14 = IRInst__getOperandSource(operandVReg,1);
                if (*(int *)(param_2 + 0x478) < *(int *)(iVar14 + 0x160)) {
                  *(int *)(iVar14 + 0x160) = *(int *)(iVar14 + 0x160) + 1;
                }
                else {
                  *(int *)(iVar14 + 0x160) = *(int *)(param_2 + 0x478) + 1;
                }
                FUN_00105894(operandVReg,*(undefined4 *)(param_2 + 8));
              }
            }
          }
LAB_00159218:
          iVar14 = (**(code **)(*callResult + 100))(callResult);
          if (iVar14 != 0) {
            puVar15 = (uint *)(callResult + 0x2e);
            for (iVar14 = 1; operandRecord = (**(code **)(*callResult + 0x14))(callResult), iVar14 <= operandRecord;
                iVar14 = iVar14 + 1) {
              uVar9 = *puVar15;
              puVar15 = puVar15 + 6;
              if ((((uVar9 & 1) != 0) || ((uVar9 & 2) != 0)) ||
                 (operandRecord = FUN_000f31e8(callResult,iVar14), operandRecord == 0)) goto LAB_001593b8;
            }
            if ((callResult[0x48] == 0) && (callResult[0x49] == 0)) {
              if ((callResult[0x20] != 0) &&
                 (((iVar14 = FUN_00126760(callResult[0x26]), iVar14 != 0 && ((callResult[5] & 2U) == 0)) &&
                  (iVar14 = (**(code **)(*callResult + 0x50))(callResult), iVar14 == 0)))) {
                iVar14 = 4;
                piVar10 = callResult;
                do {
                  if ((uint)(*(byte *)(piVar10 + 0x27) - 2) < 2) goto LAB_001593b8;
                  piVar10 = (int *)((int)piVar10 + 1);
                  iVar14 = iVar14 + -1;
                } while (iVar14 != 0);
              }
              IRInst__getOperandRecord(callResult,0);
              iVar14 = FUN_00105dbc(callResult,0);
              if (((iVar14 == 0) && ((callResult[5] & 2U) == 0)) && ((callResult[5] & 0x200U) == 0)) {
                *(int *)(param_2 + 0x17c) = *(int *)(param_2 + 0x17c) + 1;
                uVar7 = IRInst__getOperandSource(callResult,1);
                IRInst__setOperandSource(iVar16,2,uVar7,0,*(undefined4 *)(param_2 + 8));
                iVar14 = IRInst__getOperandSource(callResult,1);
                if (*(int *)(param_2 + 0x478) < *(int *)(iVar14 + 0x160)) {
                  *(int *)(iVar14 + 0x160) = *(int *)(iVar14 + 0x160) + 1;
                }
                else {
                  *(int *)(iVar14 + 0x160) = *(int *)(param_2 + 0x478) + 1;
                }
                FUN_00105894(callResult,*(undefined4 *)(param_2 + 8));
              }
            }
          }
        }
LAB_001593b8:
        if (iVar13 != 0) {
          operandVReg2 = IRInst__getOperandSource(iVar16,3);
          iVar14 = IRInst__getOperandRecord(iVar16,3);
          FUN_000f3398(local_50,*(undefined4 *)(iVar14 + 0x10));
          uVar7 = local_50[0];
          iVar14 = FUN_0015800c(iVar16,operandVReg2,iVar13,uVar12,local_50[0],param_2);
          if (iVar14 != 0) {
            iVar14 = FUN_0015800c(iVar16,operandVReg,iVar13,uVar12,uVar1,param_2);
            if (iVar14 == 0) {
              iVar14 = FUN_0015800c(iVar16,callResult,iVar13,uVar12,uVar2,param_2);
              if (iVar14 == 0) break;
              ((int (*)())FUN_00158988)(iVar16,callResult,iVar13,uVar12,uVar2,param_2);
              uVar9 = local_64_vec;
              *(undefined4 *)(iVar16 + 0x124) = 0;
              if (local_64_vec < local_68_vec) {
                iVar14 = local_64_vec * 4;
                _memset(iVar14 + local_60_vec,0,4);
                local_64_vec = uVar9 + 1;
                puVar6 = (undefined4 *)(iVar14 + local_60_vec);
              }
              else {
                puVar6 = (undefined4 *)Vector__elementRefGrow(&local_68_vec,local_64_vec);
              }
              *puVar6 = callResult;
            }
            else {
              ((int (*)())FUN_00158988)(iVar16,operandVReg,iVar13,uVar12,uVar1,param_2);
              uVar9 = local_64_vec;
              *(undefined4 *)(iVar16 + 0x124) = 0;
              if (local_64_vec < local_68_vec) {
                iVar14 = local_64_vec * 4;
                _memset(iVar14 + local_60_vec,0,4);
                local_64_vec = uVar9 + 1;
                puVar6 = (undefined4 *)(iVar14 + local_60_vec);
              }
              else {
                puVar6 = (undefined4 *)Vector__elementRefGrow(&local_68_vec,local_64_vec);
              }
              *puVar6 = operandVReg;
            }
            ((int (*)())FUN_00158988)(iVar16,operandVReg2,iVar13,uVar12,uVar7,param_2);
            uVar9 = local_64_vec;
            if (local_64_vec < local_68_vec) {
              iVar13 = local_64_vec * 4;
              _memset(iVar13 + local_60_vec,0,4);
              local_64_vec = uVar9 + 1;
              puVar6 = (undefined4 *)(iVar13 + local_60_vec);
            }
            else {
              puVar6 = (undefined4 *)Vector__elementRefGrow(&local_68_vec,local_64_vec);
            }
            *puVar6 = operandVReg2;
          }
        }
      }
      else if (((iVar14 == 0x12) && (iVar13 != 0)) &&
              ((iVar14 = FUN_0015800c(iVar16,operandVReg,iVar13,uVar12,uVar1,param_2), iVar14 != 0 &&
               (iVar14 = FUN_0015800c(iVar16,callResult,iVar13,uVar12,uVar2,param_2), iVar14 != 0)))) {
        *(undefined4 *)(iVar16 + 0x124) = 0;
        if (param_1 == iVar16) {
          uVar11 = 1;
        }
        ((int (*)())FUN_00158988)(iVar16,operandVReg,iVar13,uVar12,uVar1,param_2);
        uVar9 = local_64_vec;
        if (local_64_vec < local_68_vec) {
          iVar14 = local_64_vec * 4;
          _memset(iVar14 + local_60_vec,0,4);
          local_64_vec = uVar9 + 1;
          puVar6 = (undefined4 *)(iVar14 + local_60_vec);
        }
        else {
          puVar6 = (undefined4 *)Vector__elementRefGrow(&local_68_vec,local_64_vec);
        }
        *puVar6 = operandVReg;
        if (operandVReg != callResult) {
          ((int (*)())FUN_00158988)(iVar16,callResult,iVar13,uVar12,uVar2,param_2);
LAB_00158fc8:
          uVar9 = local_64_vec;
          if (local_64_vec < local_68_vec) {
            iVar13 = local_64_vec * 4;
            _memset(iVar13 + local_60_vec,0,4);
            local_64_vec = uVar9 + 1;
            puVar6 = (undefined4 *)(iVar13 + local_60_vec);
          }
          else {
            puVar6 = (undefined4 *)Vector__elementRefGrow(&local_68_vec,local_64_vec);
          }
          *puVar6 = callResult;
        }
      }
    }
  } while (local_64_vec != 0);
  Arena__free(local_5c,local_60_vec);
  return uVar11;
}

/* FUN_001595f0 @ 0x1595f0 (420 bytes) */
int FUN_001595f0(inst, param_2)
  undefined4 inst;
  int param_2;
{
  bool bVar1;
  int iVar2;
  int operandRecord;
  int *a0;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  undefined4 local_38 [4];
  undefined4 local_28;
  float local_24;
  
  iVar2 = FUN_0017361c(inst);
  if (iVar2 == 0) {
LAB_0015977c:
    uVar5 = 0;
  }
  else {
    iVar2 = IRInst__getOperandRecord(inst,1);
    local_38[0] = *(undefined4 *)(iVar2 + 0x10);
    iVar6 = 0;
    iVar2 = -1;
    do {
      operandRecord = IRInst__getOperandRecord(inst,0);
      iVar4 = iVar2;
      if (*(char *)(iVar6 + operandRecord + 0x10) != '\x01') {
        uVar7 = (uint)*(byte *)((int)local_38 + iVar6);
        a0 = (int *)IRInst__getOperandSource(inst,1);
        iVar4 = (**(code **)(*a0 + 0x60))(a0);
        if (iVar4 != 0) {
          uVar5 = FUN_001042bc(a0,uVar7);
          iVar4 = IRInst__getOperandRecord(a0,uVar5);
          uVar7 = (uint)*(byte *)(uVar7 + iVar4 + 0x10);
          a0 = (int *)IRInst__getOperandSource(a0,uVar5);
        }
        iVar4 = FUN_00126708(a0[0x26]);
        if ((iVar4 == 0) || (((int)*(char *)(a0 + 0x57) >> (uVar7 & 0x3f) & 1U) == 0))
        goto LAB_0015977c;
        FUN_0010b2dc(&local_28,inst,1,a0[uVar7 * 6 + 8]);
        FUN_0010b284(&local_24,inst,1,local_28);
        iVar4 = ((bool (*)())FUN_0010b820)(inst,(double)local_24,0.0);
        iVar4 = (iVar4 == 0) + 2;
        if ((iVar2 != -1) && (bVar1 = iVar4 != iVar2, iVar4 = iVar2, bVar1)) goto LAB_0015977c;
      }
      bVar1 = iVar6 != 3;
      iVar6 = iVar6 + 1;
      iVar2 = iVar4;
    } while (bVar1);
    *(int *)(param_2 + 0x1ec) = *(int *)(param_2 + 0x1ec) + 1;
    FUN_0010d15c(inst,iVar4,0,*(undefined4 *)(param_2 + 8));
    uVar5 = 1;
  }
  return uVar5;
}

/* FUN_00159794 @ 0x159794 (964 bytes) */
int FUN_00159794(inst, param_2, param_3)
  int inst;
  int param_2;
  uint param_3;
{
  int loopIndex;
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *operandVReg;
  int operandVReg2;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28 [2];
  
  iVar2 = *(int *)(inst + 0x88);
  local_2c = 0x3f000000;
  local_38 = 0x3f000000;
  local_34 = 0x3f000000;
  local_30 = 0x3f000000;
  if (*(int *)(iVar2 + 8) == 0x24) {
    uVar3 = Opcode__getInfo(0x25);
    *(undefined4 *)(inst + 0x88) = uVar3;
    IROperand__setModifierBits(inst + 0xa4,1,1);
    IROperand__setModifierBits(inst + 0xa4,2,1);
    iVar2 = *(int *)(inst + 0x88);
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
    if (*(int *)(iVar2 + 8) == 0x26) {
      uVar3 = 1;
      uVar10 = Opcode__getInfo(0x25);
      *(undefined4 *)(inst + 0x88) = uVar10;
      IROperand__setModifierBits(inst + 0xa4,1,*(uint *)(inst + 0xb8) & 1 ^ 1);
      FUN_0010ac38(inst,2,3,param_3);
      iVar2 = *(int *)(inst + 0x88);
    }
  }
  if (((*(int *)(iVar2 + 8) == 0x25) && ((*(uint *)(*(int *)(param_3 + 0x6c4) + 0x30) & 8) != 0)) &&
     (param_2 != 0)) {
    iVar2 = IRInst__getOperandSource(inst,1);
    iVar4 = IRInst__getOperandRecord(iVar2,0);
    uVar10 = *(undefined4 *)(iVar4 + 0x10);
    if ((((*(uint *)(inst + 0xb8) & 2) == 0) && (*(int *)(*(int *)(iVar2 + 0x88) + 8) == 0x12))
       && (((*(uint *)(iVar2 + 0x14) & 0x200) == 0 &&
           ((*(int *)(iVar2 + 0x120) == 0 && (*(int *)(iVar2 + 0x124) == 0)))))) {
      iVar4 = IRInst__getOperandSource(iVar2,1);
      uVar7 = 0;
      if (iVar4 != 0) {
        iVar4 = IRInst__getOperandSource(iVar2,1);
        uVar7 = *(undefined4 *)(iVar4 + 0x98);
      }
      iVar4 = FUN_001267b8(uVar7);
      if (iVar4 == 0) {
        operandVReg = (int *)IRInst__getOperandSource(iVar2,1);
        iVar4 = (**(code **)(*operandVReg + 0x5c))(operandVReg);
        if (iVar4 == 0) {
          return uVar3;
        }
      }
      if (((((*(uint *)(iVar2 + 0xb8) & 2) == 0) &&
           (uVar1 = *(uint *)(inst + 0xb8) & 1, uVar1 == (*(uint *)(iVar2 + 0xd0) & 1))) &&
          (uVar1 != (*(uint *)(iVar2 + 0xb8) & 1))) &&
         (iVar4 = FUN_000f5c0c(iVar2,2,uVar10,&local_38), iVar4 != 0)) {
        uVar3 = Opcode__getInfo(0x9d);
        *(undefined4 *)(inst + 0x88) = uVar3;
        iVar4 = IRInst__getOperandRecord(iVar2,1);
        uVar3 = *(undefined4 *)(iVar4 + 0x10);
        iVar4 = IRInst__getOperandRecord(inst,1);
        FUN_000f2bdc(local_28,uVar3,*(undefined4 *)(iVar4 + 0x10));
        iVar4 = IRInst__getOperandRecord(inst,1);
        *(undefined4 *)(iVar4 + 0x10) = local_28[0];
        IROperand__setModifierBits(inst + 0xa4,1,0);
        FUN_0010ac38(inst,2,3,param_3);
        iVar9 = *(int *)(param_3 + 0x6c4);
        iVar8 = *(int *)(iVar9 + 0x478);
        operandVReg = (int *)IRInst__getOperandSource(iVar2,1);
        iVar4 = (**(code **)(*operandVReg + 0x5c))(operandVReg);
        if ((iVar4 == 0) || (iVar4 = IRInst__hasSingleUse(operandVReg,iVar9), iVar4 != 0)) {
          IRInst__setOperandSource(inst,1,operandVReg,0,param_3);
          if (iVar8 < operandVReg[0x58]) {
            operandVReg[0x58] = operandVReg[0x58] + 1;
          }
          else {
            operandVReg[0x58] = iVar8 + 1;
          }
        }
        else {
          iVar4 = IRInst__clone(operandVReg,param_3,0);
          *(undefined4 *)(iVar4 + 0x94) = *(undefined4 *)(iVar4 + 0x14c);
          Block__insertInstAfter(operandVReg[0x56],operandVReg,iVar4);
          IRInst__setOperandSource(inst,1,iVar4,0,param_3);
          *(int *)(iVar4 + 0x160) = *(int *)(iVar9 + 0x478) + 1;
          if (0 < *(int *)(iVar4 + 0x84)) {
            loopIndex = 1;
            do {
              operandVReg2 = IRInst__getOperandSource(iVar4,loopIndex);
              if (iVar8 < *(int *)(operandVReg2 + 0x160)) {
                *(int *)(operandVReg2 + 0x160) = *(int *)(operandVReg2 + 0x160) + 1;
              }
              else {
                *(int *)(operandVReg2 + 0x160) = iVar8 + 1;
              }
              loopIndex = loopIndex + 1;
            } while (loopIndex <= *(int *)(iVar4 + 0x84));
          }
        }
        FUN_00105894(iVar2,param_3);
        uVar3 = 1;
      }
    }
  }
  return uVar3;
}

/* FUN_00159b58 @ 0x159b58 (2844 bytes) */
int FUN_00159b58(node, param_2, pass)
  int node;
  undefined4 param_2;
  int pass;
{
  int *operandVReg;
  float fVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 a1;
  uint uVar7;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  double fparam_1;
  undefined1 auStack_118 [4];
  undefined4 local_114;
  undefined1 auStack_100 [4];
  undefined4 local_fc;
  undefined1 auStack_e8 [4];
  float local_e4;
  undefined1 auStack_d0 [4];
  float local_cc;
  undefined1 auStack_b8 [4];
  float local_b4;
  undefined1 auStack_a0 [4];
  float local_9c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  float local_70;
  float local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c [3];
  float local_50;
  
  uVar12 = *(uint *)(pass + 8);
  if ((((*(int *)(*(int *)(uVar12 + 0x6c4) + 0x214) + *(int *)(*(int *)(uVar12 + 0x6c4) + 0x218) <
         *(int *)(uVar12 + 0x6a0)) && (node != 0)) && (0 < *(int *)(node + 0x84))) &&
     (iVar2 = IRInst__getOperandSource(node,1), iVar2 != 0)) {
    ((int (*)())FUN_00159794)(node,param_2,uVar12);
    ((int (*)())FUN_00159794)(iVar2,param_2,uVar12);
    iVar8 = *(int *)(node + 0x88);
    if ((*(int *)(iVar8 + 8) == 0x25) && (*(int *)(*(int *)(iVar2 + 0x88) + 8) == 0x25)) {
      iVar8 = FUN_000f48ec(node,1);
      if (iVar8 != 0) {
        iVar8 = IRInst__getOperandRecord(iVar2,0);
        iVar8 = FUN_000f5cf0(iVar2,2,*(undefined4 *)(iVar8 + 0x10),auStack_118);
        if (iVar8 != 0) {
          iVar8 = IRInst__getOperandRecord(iVar2,0);
          iVar8 = FUN_000f5cf0(iVar2,3,*(undefined4 *)(iVar8 + 0x10),auStack_100);
          if (iVar8 != 0) {
            *(int *)(pass + 0x214) = *(int *)(pass + 0x214) + 1;
            operandVReg = (int *)IRInst__getOperandSource(iVar2,1);
            iVar8 = (**(code **)(*operandVReg + 0x5c))(operandVReg);
            piVar4 = operandVReg;
            if ((iVar8 != 0) && (iVar8 = IRInst__hasSingleUse(operandVReg,pass), iVar8 == 0)) {
              piVar4 = (int *)IRInst__clone(operandVReg,uVar12,0);
              piVar4[0x25] = piVar4[0x53];
              Block__insertInstAfter(operandVReg[0x56],operandVReg,piVar4);
              piVar4[0x58] = *(int *)(pass + 0x478);
              if (0 < piVar4[0x21]) {
                iVar8 = 1;
                do {
                  iVar6 = IRInst__getOperandSource(piVar4,iVar8);
                  if (*(int *)(pass + 0x478) < *(int *)(iVar6 + 0x160)) {
                    *(int *)(iVar6 + 0x160) = *(int *)(iVar6 + 0x160) + 1;
                  }
                  else {
                    *(int *)(iVar6 + 0x160) = *(int *)(pass + 0x478) + 1;
                  }
                  iVar8 = iVar8 + 1;
                } while (iVar8 <= piVar4[0x21]);
              }
            }
            FUN_0010aee8(&local_88,iVar2,local_114);
            FUN_0010aee8(&local_84,iVar2,local_fc);
            FUN_0010b118(&local_80,iVar2,local_88);
            FUN_0010b118(&local_7c,iVar2,local_84);
            FUN_0010b2dc(&local_78,node,1,local_80);
            FUN_0010b2dc(&local_74,node,1,local_7c);
            FUN_0010b284(&local_70,node,1,local_78);
            uVar5 = 1;
            FUN_0010b284(&local_6c,node,1,local_74);
            local_50 = local_70;
            if ((0.0 <= local_70) || (local_50 = local_6c, 0.0 <= local_6c)) {
              if ((0.0 > local_70) || (local_50 = local_6c, local_6c < 0.0)) {
                uVar11 = *(uint *)(iVar2 + 0xb8);
                iVar8 = (**(code **)(*piVar4 + 0x5c))
                                  (piVar4,a1,uVar5,local_74,in_r7,in_r8,*(code **)(*piVar4 + 0x5c));
                piVar3 = piVar4;
                if (iVar8 != 0) {
                  iVar6 = *(int *)(pass + 0x478);
                  piVar3 = (int *)IRInst__clone(piVar4,*(undefined4 *)(pass + 8),0);
                  iVar10 = piVar3[0x53];
                  iVar8 = IRInst__getOperandRecord(piVar3,0);
                  *(int *)(iVar8 + 8) = iVar10;
                  piVar3[0x58] = iVar6;
                  for (iVar8 = 1; iVar10 = (**(code **)(*piVar3 + 0x14))(piVar3), iVar8 <= iVar10;
                      iVar8 = iVar8 + 1) {
                    iVar10 = IRInst__getOperandSource(piVar3,iVar8);
                    if (iVar6 < *(int *)(iVar10 + 0x160)) {
                      *(int *)(iVar10 + 0x160) = *(int *)(iVar10 + 0x160) + 1;
                    }
                    else {
                      *(int *)(iVar10 + 0x160) = iVar6 + 1;
                    }
                  }
                  Block__insertInstBefore(piVar4[0x56],piVar4,piVar3);
                }
                IRInst__setOperandSource(node,1,piVar3,0,uVar12);
                if (*(int *)(pass + 0x478) < piVar3[0x58]) {
                  piVar3[0x58] = piVar3[0x58] + 1;
                }
                else {
                  piVar3[0x58] = *(int *)(pass + 0x478) + 1;
                }
                IROperand__setModifierBits(node + 0xa4,1,uVar11 & 1);
                IROperand__setModifierBits(node + 0xa4,2,uVar11 >> 1 & 1);
                iVar8 = IRInst__getOperandRecord(iVar2,1);
                uVar5 = *(undefined4 *)(iVar8 + 0x10);
                iVar8 = IRInst__getOperandRecord(node,1);
                FUN_000f2bdc(&local_68,uVar5,*(undefined4 *)(iVar8 + 0x10));
                iVar8 = IRInst__getOperandRecord(node,1);
                *(undefined4 *)(iVar8 + 0x10) = local_68;
                if ((local_70 < 0.0) || (local_50 = local_6c, 0.0 <= local_6c)) {
                  FUN_0010ac38(node,2,3,uVar12);
                }
                uVar5 = FUN_00105894(iVar2,uVar12);
                return uVar5;
              }
              uVar5 = 2;
            }
            else {
              uVar5 = 3;
            }
            FUN_0010d15c(node,uVar5,0,uVar12);
            return 0;
          }
        }
      }
      iVar8 = *(int *)(node + 0x88);
    }
    if (*(int *)(iVar8 + 8) == 0x8b) {
      iVar8 = *(int *)(node + 300);
      iVar2 = IRInst__getOperandRecord(node,0);
      iVar2 = FUN_000f5cf0(node,2,*(undefined4 *)(iVar2 + 0x10),auStack_e8);
      if (iVar2 == 0) {
        iVar2 = IRInst__getOperandRecord(node,0);
        iVar2 = FUN_000f5cf0(node,1,*(undefined4 *)(iVar2 + 0x10),auStack_e8);
        if (iVar2 == 0) {
          return 0;
        }
        FUN_0010ac38(node,1,2,uVar12);
        iVar8 = *(int *)(PTR_DAT_001e90f8 + iVar8 * 4);
        *(int *)(node + 300) = iVar8;
      }
      iVar2 = IRInst__getOperandSource(node,1);
      if (((*(uint *)(node + 0xb8) & 2) == 0) && ((*(uint *)(node + 0xd0) & 2) == 0)) {
        if ((*(int *)(*(int *)(iVar2 + 0x88) + 8) == 0x12) &&
           (((local_e4 == 0.0 && (*(int *)(iVar2 + 0x120) == 0)) &&
            ((*(uint *)(iVar2 + 0x14) & 0x200) == 0)))) {
          iVar8 = IRInst__getOperandRecord(node,1);
          uVar9 = *(undefined4 *)(iVar8 + 0x10);
          *(int *)(pass + 0x218) = *(int *)(pass + 0x218) + 1;
          uVar5 = IRInst__getOperandSource(node,2);
          FUN_00105894(uVar5,uVar12);
          uVar5 = IRInst__getOperandSource(iVar2,1);
          IRInst__setOperandSource(node,1,uVar5,0,uVar12);
          iVar8 = IRInst__getOperandRecord(iVar2,1);
          FUN_000f2bdc(&local_64,*(undefined4 *)(iVar8 + 0x10),uVar9);
          iVar8 = IRInst__getOperandRecord(node,1);
          *(undefined4 *)(iVar8 + 0x10) = local_64;
          iVar8 = IRInst__getOperandSource(iVar2,1);
          if (*(int *)(pass + 0x478) < *(int *)(iVar8 + 0x160)) {
            *(int *)(iVar8 + 0x160) = *(int *)(iVar8 + 0x160) + 1;
          }
          else {
            *(int *)(iVar8 + 0x160) = *(int *)(pass + 0x478) + 1;
          }
          IROperand__setModifierBits(node + 0xa4,2,*(uint *)(iVar2 + 0xb8) >> 1 & 1);
          uVar5 = IRInst__getOperandSource(iVar2,2);
          IRInst__setOperandSource(node,2,uVar5,0,uVar12);
          iVar8 = IRInst__getOperandRecord(iVar2,2);
          FUN_000f2bdc(&local_60,*(undefined4 *)(iVar8 + 0x10),uVar9);
          iVar8 = IRInst__getOperandRecord(node,2);
          *(undefined4 *)(iVar8 + 0x10) = local_60;
          iVar8 = IRInst__getOperandSource(iVar2,2);
          if (*(int *)(pass + 0x478) < *(int *)(iVar8 + 0x160)) {
            *(int *)(iVar8 + 0x160) = *(int *)(iVar8 + 0x160) + 1;
          }
          else {
            *(int *)(iVar8 + 0x160) = *(int *)(pass + 0x478) + 1;
          }
          IROperand__setModifierBits(node + 0xbc,2,*(uint *)(iVar2 + 0xd0) >> 1 & 1);
          uVar11 = *(uint *)(node + 0xb8) & 1;
          uVar7 = uVar11;
          if ((*(uint *)(iVar2 + 0xb8) & 1) != 0) {
            uVar7 = uVar11 ^ 1;
          }
          if ((*(uint *)(iVar2 + 0xd0) & 1) != 0) {
            uVar11 = uVar11 ^ 1;
          }
          IROperand__setModifierBits(node + 0xa4,1,uVar7);
          IROperand__setModifierBits(node + 0xbc,1,uVar11 ^ 1);
          uVar5 = FUN_00105894(iVar2,uVar12);
          return uVar5;
        }
        iVar6 = IRInst__getOperandRecord(node,0);
        iVar6 = FUN_000f5cf0(node,2,*(undefined4 *)(iVar6 + 0x10),auStack_d0);
        if (((*(int *)(*(int *)(iVar2 + 0x88) + 8) == 0x25) && (iVar6 != 0)) &&
           ((local_cc == 0.0 &&
            (((*(uint *)(iVar2 + 0x14) & 0x200) == 0 ||
             (iVar6 = FUN_000f45f8(node,1,iVar2,pass), iVar6 != 0)))))) {
          iVar6 = IRInst__getOperandRecord(iVar2,0);
          iVar6 = FUN_000f5cf0(iVar2,2,*(undefined4 *)(iVar6 + 0x10),auStack_b8);
          if (iVar6 != 0) {
            iVar6 = IRInst__getOperandRecord(iVar2,0);
            iVar6 = FUN_000f5cf0(iVar2,3,*(undefined4 *)(iVar6 + 0x10),auStack_a0);
            if (iVar6 != 0) {
              *(int *)(pass + 0x218) = *(int *)(pass + 0x218) + 1;
              switch(iVar8) {
              case 0:
                uVar11 = (uint)(local_e4 == local_9c);
                uVar7 = (uint)(local_e4 == local_b4);
                break;
              case 1:
                uVar11 = (uint)(local_e4 != local_9c);
                uVar7 = (uint)(local_e4 != local_b4);
                break;
              case 2:
                uVar11 = (uint)(local_e4 < local_9c);
                uVar7 = (uint)(local_e4 < local_b4);
                break;
              case 3:
                uVar11 = (uint)(local_e4 <= local_9c);
                uVar7 = (uint)(local_e4 <= local_b4);
                break;
              case 4:
                uVar11 = (uint)(local_9c < local_e4);
                uVar7 = (uint)(local_b4 < local_e4);
                break;
              case 5:
                uVar11 = (uint)(local_9c <= local_e4);
                uVar7 = (uint)(local_b4 <= local_e4);
                break;
              default:
                goto switchD_0015a394_default;
              }
              iVar8 = IRInst__getOperandRecord(iVar2,1);
              uVar5 = *(undefined4 *)(iVar8 + 0x10);
              iVar8 = IRInst__getOperandRecord(node,1);
              FUN_000f2bdc(local_5c,uVar5,*(undefined4 *)(iVar8 + 0x10));
              FUN_00105e54(node,1,iVar2,1);
              iVar8 = IRInst__getOperandRecord(node,1);
              *(undefined4 *)(iVar8 + 0x10) = local_5c[0];
              if (uVar7 == uVar11) {
                if (uVar7 == 0) {
                  fVar1 = 1.0;
                }
                else {
                  fVar1 = 0.0;
                }
                fparam_1 = (double)fVar1;
                piVar4 = (int *)0x0;
                ((void (*)())FUN_000f79c4)(node,pass,1,fparam_1,fparam_1,fparam_1,fparam_1);
              }
              else {
                piVar4 = (int *)IRInst__getOperandSource(iVar2,1);
                if (*(int *)(pass + 0x478) < piVar4[0x58]) {
                  piVar4[0x58] = piVar4[0x58] + 1;
                }
                else {
                  piVar4[0x58] = *(int *)(pass + 0x478) + 1;
                }
                *(uint *)(node + 300) = (uVar7 ^ 1) + 3;
              }
              uVar5 = FUN_00105894(iVar2,uVar12);
              if (piVar4 == (int *)0x0) {
                return uVar5;
              }
              iVar2 = (**(code **)(*piVar4 + 0x5c))(piVar4);
              if (iVar2 == 0) {
                return uVar5;
              }
              iVar2 = IRInst__hasSingleUse(piVar4,pass);
              if (iVar2 == 0) {
                iVar8 = *(int *)(pass + 0x478);
                piVar4[0x58] = piVar4[0x58] + -1;
                iVar6 = iVar8 + 1;
                piVar4 = (int *)IRInst__clone(piVar4,*(undefined4 *)(pass + 8),0);
                iVar10 = piVar4[0x53];
                iVar2 = IRInst__getOperandRecord(piVar4,0);
                *(int *)(iVar2 + 8) = iVar10;
                piVar4[0x58] = iVar6;
                for (iVar2 = 1; iVar10 = (**(code **)(*piVar4 + 0x14))(piVar4), iVar2 <= iVar10;
                    iVar2 = iVar2 + 1) {
                  iVar10 = IRInst__getOperandSource(piVar4,iVar2);
                  if (iVar8 < *(int *)(iVar10 + 0x160)) {
                    *(int *)(iVar10 + 0x160) = *(int *)(iVar10 + 0x160) + 1;
                  }
                  else {
                    *(int *)(iVar10 + 0x160) = iVar6;
                  }
                }
                IRInst__setOperandSource(node,1,piVar4,0,uVar12);
                Block__insertInstBefore(*(undefined4 *)(node + 0x158),node,piVar4);
                return uVar5;
              }
              return uVar5;
            }
          }
        }
      }
    }
  }
switchD_0015a394_default:
  return 0;
}

/* FUN_0015a68c @ 0x15a68c (3608 bytes) */
int FUN_0015a68c(param_1, pass)
  int param_1;
  int pass;
{
  int *operandVReg2;
  int *operandVReg;
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int *piVar11;
  int iVar12;
  int *piVar13;
  int iVar14;
  int operandVReg3;
  void *inst;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  code *a7;
  int iVar17;
  uint uVar18;
  int iVar19;
  int *piVar20;
  int *piVar21;
  int *piVar22;
  undefined4 uVar23;
  uint uVar24;
  uint *puVar25;
  int *piVar26;
  int iVar27;
  int iStack00000018;
  undefined4 local_88;
  undefined4 local_84;
  int local_80;
  undefined4 local_7c;
  undefined4 local_78;
  int local_74;
  int local_70;
  uint local_6c;
  int local_68;
  int local_64;
  int *local_60;
  int local_5c;
  int local_58;
  int local_54;
  
  uVar18 = *(uint *)(*(int *)(param_1 + 0x10) + 4);
  iVar5 = uVar18 << 2;
  iStack00000018 = param_1;
  iVar3 = Arena__alloc(*(undefined4 *)(*(int *)(pass + 8) + 0x378),iVar5);
  iVar4 = Arena__alloc(*(undefined4 *)(*(int *)(pass + 8) + 0x378),iVar5);
  iVar5 = Arena__alloc(*(undefined4 *)(*(int *)(pass + 8) + 0x378),iVar5);
  if (0 < (int)uVar18) {
    uVar24 = 0;
    iVar17 = 0;
    iVar19 = 0;
    do {
      puVar25 = *(uint **)(iStack00000018 + 0x10);
      if (uVar24 < *puVar25) {
        uVar6 = puVar25[1];
        if (uVar6 <= uVar24) {
          _memset(uVar6 * 4 + puVar25[2],0,(uVar24 - uVar6) * 4 + 4);
          puVar25[1] = uVar24 + 1;
        }
        puVar7 = (undefined4 *)(iVar19 + puVar25[2]);
      }
      else {
        puVar7 = (undefined4 *)Vector__elementRefGrow(puVar25,uVar24);
      }
      uVar24 = uVar24 + 1;
      piVar21 = (int *)*puVar7;
      bVar2 = false;
      *(int **)(iVar19 + iVar3) = piVar21;
      *(undefined4 *)(iVar19 + iVar4) = 0;
      *(undefined4 *)(iVar19 + iVar5) = 0;
      while ((((*(int *)(piVar21[0x22] + 8) == 0x13 && ((piVar21[5] & 0x200U) == 0)) &&
              (iVar9 = IRInst__hasSingleUse(piVar21,pass), iVar9 != 0)) && (piVar21[0x48] == 0))) {
        piVar10 = (int *)piVar21[4];
        if (*piVar10 == 0) {
          puVar7 = (undefined4 *)Vector__elementRefGrow(piVar10,0);
        }
        else {
          if (piVar10[1] == 0) {
            *(undefined4 *)piVar10[2] = 0;
            piVar10[1] = 1;
          }
          puVar7 = (undefined4 *)piVar10[2];
        }
        piVar10 = (int *)*puVar7;
        bVar1 = false;
        puVar25 = (uint *)(piVar10 + 0x2e);
        for (iVar9 = 1; iVar8 = (**(code **)(*piVar10 + 0x14))(piVar10), iVar9 <= iVar8;
            iVar9 = iVar9 + 1) {
          operandVReg = (int *)IRInst__getOperandSource(piVar10,iVar9);
          if (piVar21 == operandVReg) {
            iVar8 = IRInst__getOperandRecord(piVar10,iVar9);
            iVar8 = FUN_000f3190(*(undefined4 *)(iVar8 + 0x10));
            if ((iVar8 == 0) || ((*puVar25 & 2) != 0)) {
              bVar1 = true;
            }
            *(int *)(iVar19 + iVar5) = iVar9;
          }
          puVar25 = puVar25 + 6;
        }
        if (bVar1) break;
        bVar2 = true;
        piVar21 = piVar10;
      }
      if (bVar2) {
        if (((piVar21[5] & 0x200U) != 0) ||
           ((*(int *)(piVar21[0x22] + 8) != 0x12 && (*(int *)(piVar21[0x22] + 8) != 0x14))))
        goto LAB_0015a760;
        *(undefined4 *)(iVar19 + iVar4) = piVar21;
        iVar17 = iVar17 + 1;
      }
      else if (((*(int *)(piVar21[0x22] + 8) == 0x14) && ((piVar21[5] & 0x200U) == 0)) &&
              ((iVar9 = IRInst__getOperandSource(piVar21,1), iStack00000018 == iVar9 ||
               (iVar9 = IRInst__getOperandSource(piVar21,2), iStack00000018 == iVar9)))) {
        *(undefined4 *)(iVar19 + iVar4) = piVar21;
        iVar8 = IRInst__getOperandSource(piVar21,1);
        iVar9 = 2;
        if (iStack00000018 == iVar8) {
          iVar9 = 1;
        }
        iVar17 = iVar17 + 1;
        *(int *)(iVar19 + iVar5) = iVar9;
      }
      else {
LAB_0015a760:
        *(undefined4 *)(iVar19 + iVar3) = 0;
      }
      iVar19 = iVar19 + 4;
    } while (uVar18 != uVar24);
    if (1 < iVar17) {
      iVar17 = 0;
      uVar23 = 0;
      do {
        iVar19 = iVar17 * 4;
        piVar21 = (int *)(iVar3 + iVar19);
        if ((*(int *)(iVar3 + iVar19) == 0) ||
           ((*(uint *)(*(int *)(iVar3 + iVar19) + 0x14) & 1) == 0)) {
LAB_0015a9bc:
          iVar17 = iVar17 + 1;
        }
        else {
          local_60 = (int *)(iVar4 + iVar19);
          iVar9 = 1;
          if ((*(uint *)(*(int *)(iVar4 + iVar19) + 0x14) & 1) == 0) goto LAB_0015a9bc;
          for (; iVar8 = (**(code **)(*(int *)*piVar21 + 0x14))((int *)*piVar21), iVar9 <= iVar8;
              iVar9 = iVar9 + 1) {
            iVar8 = IRInst__getOperandSource(*piVar21,iVar9);
            if (iStack00000018 == iVar8) {
              iVar8 = IRInst__getOperandRecord(*piVar21,iVar9);
              local_5c = *(int *)(iVar8 + 0x10);
              local_6c = *(uint *)(iVar9 * 0x18 + *piVar21 + 0xa0) >> 1 & 1;
              local_68 = iVar9;
              goto LAB_0015aa4c;
            }
          }
          local_68 = 0;
          local_6c = 0;
LAB_0015aa4c:
          local_70 = iVar17 + 1;
          iVar17 = local_70;
          if (local_70 < (int)uVar18) {
            iVar17 = local_70 * 4;
            piVar22 = (int *)(iVar4 + iVar17);
            piVar20 = (int *)(iVar3 + iVar17);
            local_64 = 3 - local_68;
            piVar10 = (int *)(iVar5 + iVar17);
            iVar9 = 0;
            local_54 = local_64 * 0x18 + 0x80;
            do {
              piVar11 = (int *)*piVar20;
              if ((((piVar11 != (int *)0x0) && ((piVar11[5] & 1U) != 0)) &&
                  ((*(uint *)(*piVar22 + 0x14) & 1) != 0)) &&
                 ((piVar11 != (int *)*piVar21 && (*local_60 == *piVar22)))) {
                if ((*(int *)(iVar5 + iVar19) != *piVar10) &&
                   (((*(int *)(*(int *)(*local_60 + 0x88) + 8) != 0x14 ||
                     (*(int *)(iVar5 + iVar19) == 3)) || (*piVar10 == 3)))) {
                  uVar24 = 0;
                  for (iVar17 = 1; iVar8 = (**(code **)(*piVar11 + 0x14))(piVar11), iVar17 <= iVar8;
                      iVar17 = iVar17 + 1) {
                    iVar8 = IRInst__getOperandSource(*piVar20,iVar17);
                    if (iStack00000018 == iVar8) {
                      iVar8 = IRInst__getOperandRecord(*piVar20,iVar17);
                      local_58 = *(int *)(iVar8 + 0x10);
                      piVar11 = (int *)*piVar20;
                      uVar24 = (uint)piVar11[iVar17 * 6 + 0x28] >> 1 & 1;
                      if ((local_58 == local_5c) && (uVar6 = local_6c, local_6c == uVar24))
                      goto LAB_0015abb0;
                    }
                    else {
                      piVar11 = (int *)*piVar20;
                    }
                  }
                  local_74 = 0;
                  uVar6 = uVar24;
                  iVar17 = local_74;
LAB_0015abb0:
                  local_74 = iVar17;
                  if ((local_58 == local_5c) && (local_6c == uVar6)) {
                    *(int *)(pass + 0x1cc) = *(int *)(pass + 0x1cc) + 1;
                    iVar17 = *piVar21;
                    if (iVar17 != *local_60) {
                      piVar11 = *(int **)(iVar17 + 0x10);
                      if (*piVar11 == 0) {
                        puVar7 = (undefined4 *)Vector__elementRefGrow(piVar11,0);
                        iVar17 = *piVar21;
                      }
                      else {
                        if (piVar11[1] == 0) {
                          *(undefined4 *)piVar11[2] = 0;
                          piVar11[1] = 1;
                          iVar17 = *piVar21;
                        }
                        puVar7 = (undefined4 *)piVar11[2];
                      }
                      piVar26 = (int *)*puVar7;
                      piVar13 = piVar26 + 0x26;
                      local_78 = IRInst__getOperandSource(iVar17,local_64);
                      iVar17 = IRInst__getOperandRecord(*piVar21,local_64);
                      piVar11 = (int *)*piVar21;
                      iVar17 = *(int *)(iVar17 + 0x10);
                      uVar6 = *(uint *)((int)piVar11 + local_54 + 0x20);
                      uVar24 = piVar11[local_68 * 6 + 0x28];
                      (**(code **)(*piVar11 + 0xc))
                                (piVar11,1,*(undefined4 *)(pass + 8),in_r6,in_r7,in_r8,uVar6,
                                 *(code **)(*piVar11 + 0xc));
                      for (iVar8 = 1; iVar12 = (**(code **)(*piVar26 + 0x14))(piVar26),
                          iVar8 <= iVar12; iVar8 = iVar8 + 1) {
                        iVar12 = IRInst__getOperandSource(piVar26,iVar8);
                        if (iVar12 == *piVar21) {
                          in_r7 = *(undefined4 *)(pass + 8);
                          in_r6 = 1;
                          IRInst__setOperandSource(piVar26,iVar8,local_78,1,in_r7);
                          if (iVar8 == 0) {
                            piVar26[0x27] = iVar17;
                          }
                          else {
                            iVar12 = IRInst__getOperandRecord(piVar26,iVar8);
                            *(int *)(iVar12 + 0x10) = iVar17;
                          }
                          IROperand__setModifierBits(piVar13 + 3,2,uVar6 >> 1 & 1);
                          IROperand__setModifierBits(piVar13 + 3,1,(uVar24 ^ uVar6) & 1 ^ piVar13[8] & 1U);
                        }
                        piVar13 = piVar13 + 6;
                      }
                    }
                    iVar17 = *piVar20;
                    if (iVar17 != *piVar22) {
                      piVar11 = *(int **)(iVar17 + 0x10);
                      if (*piVar11 == 0) {
                        puVar7 = (undefined4 *)Vector__elementRefGrow(piVar11,0);
                        iVar17 = *piVar20;
                      }
                      else {
                        if (piVar11[1] == 0) {
                          *(undefined4 *)piVar11[2] = 0;
                          piVar11[1] = 1;
                          iVar17 = *piVar20;
                        }
                        puVar7 = (undefined4 *)piVar11[2];
                      }
                      piVar26 = (int *)*puVar7;
                      iVar8 = 3 - local_74;
                      piVar13 = piVar26 + 0x26;
                      local_7c = IRInst__getOperandSource(iVar17,iVar8);
                      iVar17 = IRInst__getOperandRecord(*piVar20,iVar8);
                      piVar11 = (int *)*piVar20;
                      iVar17 = *(int *)(iVar17 + 0x10);
                      a7 = *(code **)(*piVar11 + 0xc);
                      uVar6 = piVar11[iVar8 * 6 + 0x28];
                      uVar24 = piVar11[local_74 * 6 + 0x28];
                      (*a7)(piVar11,1,*(undefined4 *)(pass + 8),in_r6,in_r7,in_r8,*piVar11,a7);
                      for (iVar8 = 1; iVar12 = (**(code **)(*piVar26 + 0x14))(piVar26),
                          iVar8 <= iVar12; iVar8 = iVar8 + 1) {
                        iVar12 = IRInst__getOperandSource(piVar26,iVar8);
                        if (iVar12 == *piVar20) {
                          IRInst__setOperandSource(piVar26,iVar8,local_7c,1,*(undefined4 *)(pass + 8));
                          if (iVar8 == 0) {
                            piVar26[0x27] = iVar17;
                          }
                          else {
                            iVar12 = IRInst__getOperandRecord(piVar26,iVar8);
                            *(int *)(iVar12 + 0x10) = iVar17;
                          }
                          IROperand__setModifierBits(piVar13 + 3,2,uVar6 >> 1 & 1);
                          IROperand__setModifierBits(piVar13 + 3,1,(uVar24 ^ uVar6) & 1 ^ piVar13[8] & 1U);
                        }
                        piVar13 = piVar13 + 6;
                      }
                    }
                    piVar11 = IRInst__create(0x13,*(undefined4 *)(pass + 8));
                    IRInst__setOperandSource(piVar11,1,iStack00000018,1,*(undefined4 *)(pass + 8));
                    iVar17 = IRInst__getOperandRecord(piVar11,1);
                    *(int *)(iVar17 + 0x10) = local_5c;
                    IROperand__setModifierBits(piVar11 + 0x29,2,local_6c);
                    piVar11[0x26] = 0;
                    piVar11[0x25] = piVar11[0x53];
                    iVar17 = IRInst__getOperandRecord(*piVar22,0);
                    piVar11[0x27] = *(int *)(iVar17 + 0x10);
                    piVar11[0x48] = *(int *)(*piVar22 + 0x120);
                    piVar11[0x49] = *(int *)(*piVar22 + 0x124);
                    iVar17 = *piVar22;
                    iVar8 = *(int *)(*(int *)(iVar17 + 0x10) + 4);
                    uVar24 = iVar8 - 1;
                    if (-1 < (int)uVar24) {
                      iVar12 = uVar24 * 4;
                      local_80 = 0;
                      do {
                        puVar25 = *(uint **)(iVar17 + 0x10);
                        if (uVar24 < *puVar25) {
                          uVar6 = puVar25[1];
                          if (uVar6 <= uVar24) {
                            _memset(uVar6 * 4 + puVar25[2],0,(uVar24 - uVar6) * 4 + 4);
                            puVar25[1] = uVar24 + 1;
                          }
                          piVar13 = (int *)(iVar12 + puVar25[2]);
                        }
                        else {
                          piVar13 = (int *)Vector__elementRefGrow(puVar25,uVar24);
                        }
                        iVar17 = *piVar13;
                        iVar27 = *(int *)(iVar17 + 0x84);
                        if ((*(uint *)(iVar17 + 0x14) & 0x200) == 0) {
LAB_0015b040:
                          if (0 < iVar27) {
                            iVar14 = 1;
                            do {
                              operandVReg3 = IRInst__getOperandSource(iVar17,iVar14);
                              if (operandVReg3 == *piVar22) {
                                IRInst__setOperandSource(iVar17,iVar14,piVar11,1,*(undefined4 *)(pass + 8));
                                break;
                              }
                              iVar14 = iVar14 + 1;
                            } while (iVar14 <= iVar27);
                          }
                        }
                        else {
                          iVar14 = IRInst__getOperandSource(iVar17,iVar27);
                          iVar27 = iVar27 + -1;
                          if (iVar14 != *piVar22) goto LAB_0015b040;
                          IRInst__setExtraOperandSource(iVar17,piVar11,1,*(undefined4 *)(pass + 8));
                        }
                        uVar24 = uVar24 - 1;
                        iVar12 = iVar12 + -4;
                        local_80 = local_80 + 1;
                        if (iVar8 == local_80) break;
                        iVar17 = *piVar22;
                      } while( true );
                    }
                    iVar17 = IRInst__getOperandRecord(piVar11,0);
                    FUN_000f3908(&local_88,*(undefined4 *)(iVar17 + 0x10));
                    FUN_000f3340(&local_84,0x10203,local_88);
                    uVar23 = local_84;
                    iVar17 = IRInst__getOperandRecord(piVar11,2);
                    *(undefined4 *)(iVar17 + 0x10) = uVar23;
                    Block__insertInstAfter(*(undefined4 *)(*piVar22 + 0x158),*piVar22,piVar11);
                    if (*piVar21 == *local_60) {
                      piVar13 = (int *)*piVar22;
LAB_0015b134:
                      (**(code **)(*piVar13 + 0xc))(piVar13,1,*(undefined4 *)(pass + 8));
                      inst = IRInst__create(0x12,*(undefined4 *)(pass + 8));
                      uVar23 = IRInst__getOperandSource(*piVar22,3);
                      IRInst__setOperandSource(inst,2,uVar23,1,*(undefined4 *)(pass + 8));
                      uVar23 = IRInst__getOperandRecord(*piVar22,3);
                      FUN_001062c0(inst,2,uVar23,*(undefined4 *)(pass + 8));
                      if ((*piVar21 == *local_60) && (local_68 == 1)) {
                        iVar17 = *piVar22;
LAB_0015b1ec:
                        uVar23 = IRInst__getOperandSource(iVar17,2);
                        IRInst__setOperandSource(inst,1,uVar23,1,*(undefined4 *)(pass + 8));
                        iVar17 = *piVar22;
                        uVar23 = 2;
                      }
                      else {
                        iVar17 = *piVar22;
                        if ((*piVar20 == iVar17) && (local_74 == 1)) goto LAB_0015b1ec;
                        uVar23 = IRInst__getOperandSource(iVar17,1);
                        IRInst__setOperandSource(inst,1,uVar23,1,*(undefined4 *)(pass + 8));
                        iVar17 = *piVar22;
                        uVar23 = 1;
                      }
                      uVar23 = IRInst__getOperandRecord(iVar17,uVar23);
                      FUN_001062c0(inst,1,uVar23,*(undefined4 *)(pass + 8));
                      IROperand__setModifierBits((int)inst + 0xa4,1,
                                   (*(uint *)(*piVar22 + 0xd0) ^ *(uint *)(*piVar22 + 0xb8)) & 1);
                      *(undefined4 *)((int)inst + 0x98) = 0;
                      *(undefined4 *)((int)inst + 0x94) = *(undefined4 *)((int)inst + 0x14c);
                      iVar17 = IRInst__getOperandRecord(*piVar22,0);
                      in_r6 = 1;
                      *(undefined4 *)((int)inst + 0x9c) = *(undefined4 *)(iVar17 + 0x10);
                      in_r7 = *(undefined4 *)(pass + 8);
                      IRInst__setOperandSource(piVar11,2,inst,1,in_r7);
                      Block__insertInstBefore(piVar11[0x56],piVar11,inst);
                    }
                    else {
                      piVar13 = (int *)*piVar22;
                      if ((int *)*piVar20 == piVar13) goto LAB_0015b134;
                      in_r7 = *(undefined4 *)(pass + 8);
                      in_r6 = 1;
                      IRInst__setOperandSource(piVar11,2,piVar13,1,in_r7);
                      *(undefined4 *)(*piVar22 + 0x120) = 0;
                      *(undefined4 *)(*piVar22 + 0x124) = 0;
                    }
                    *piVar20 = (int)piVar11;
                    *piVar22 = 0;
                    *piVar10 = 0;
                    while (piVar13 = piVar11, *(int *)(piVar13[0x22] + 8) == 0x13) {
                      uVar24 = piVar13[5];
                      if ((uVar24 & 0x200) != 0) goto LAB_0015b3f0;
                      iVar17 = IRInst__hasSingleUse(piVar13,pass);
                      if ((iVar17 == 0) || (piVar13[0x48] != 0)) break;
                      piVar11 = (int *)piVar13[4];
                      if (*piVar11 == 0) {
                        puVar7 = (undefined4 *)Vector__elementRefGrow(piVar11,0);
                      }
                      else {
                        if (piVar11[1] == 0) {
                          *(undefined4 *)piVar11[2] = 0;
                          piVar11[1] = 1;
                        }
                        puVar7 = (undefined4 *)piVar11[2];
                      }
                      piVar11 = (int *)*puVar7;
                      bVar2 = false;
                      puVar25 = (uint *)(piVar11 + 0x2e);
                      for (iVar17 = 1; iVar8 = (**(code **)(*piVar11 + 0x14))(piVar11),
                          iVar17 <= iVar8; iVar17 = iVar17 + 1) {
                        operandVReg2 = (int *)IRInst__getOperandSource(piVar11,iVar17);
                        if (operandVReg2 == piVar13) {
                          iVar8 = IRInst__getOperandRecord(piVar11,iVar17);
                          iVar8 = FUN_000f3190(*(undefined4 *)(iVar8 + 0x10));
                          if ((iVar8 == 0) || ((*puVar25 & 2) != 0)) {
                            bVar2 = true;
                          }
                          *piVar10 = iVar17;
                        }
                        puVar25 = puVar25 + 6;
                      }
                      if (bVar2) break;
                    }
                    uVar24 = piVar13[5];
LAB_0015b3f0:
                    if (((uVar24 & 0x200) == 0) &&
                       ((*(int *)(piVar13[0x22] + 8) == 0x12 ||
                        (*(int *)(piVar13[0x22] + 8) == 0x14)))) {
                      *piVar22 = (int)piVar13;
                    }
                    else {
                      *piVar20 = 0;
                    }
                    if ((*(uint *)(*piVar21 + 0x14) & 1) == 0) {
                      uVar23 = 1;
                      iVar17 = local_70;
                      break;
                    }
                    uVar23 = 1;
                  }
                }
              }
              iVar9 = iVar9 + 1;
              piVar20 = piVar20 + 1;
              piVar10 = piVar10 + 1;
              piVar22 = piVar22 + 1;
              iVar17 = local_70;
            } while (uVar18 - local_70 != iVar9);
          }
        }
        if ((int)uVar18 <= iVar17) {
          Arena__free(*(undefined4 *)(*(int *)(pass + 8) + 0x378),iVar5);
          Arena__free(*(undefined4 *)(*(int *)(pass + 8) + 0x378),iVar4);
          Arena__free(*(undefined4 *)(*(int *)(pass + 8) + 0x378),iVar3);
          return uVar23;
        }
      } while( true );
    }
  }
  return 0;
}

/* FUN_0015b4a4 @ 0x15b4a4 (1044 bytes) */
int FUN_0015b4a4(inst, param_2)
  int inst;
  int param_2;
{
  uint loopIndex;
  bool bVar1;
  byte bVar2;
  int iVar3;
  int *a0;
  int *piVar4;
  undefined4 *puVar5;
  int *operandVReg;
  int operandRecord;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint *puVar11;
  int iVar12;
  undefined4 local_48;
  byte local_44 [24];
  
  if (*(int *)(*(int *)(inst + 0x88) + 8) == 0x31) {
    iVar3 = IRInst__getOperandRecord(inst,1);
    iVar3 = FUN_000f3190(*(undefined4 *)(iVar3 + 0x10));
    if (iVar3 == 0) {
      a0 = (int *)IRInst__getOperandSource(inst,1);
      iVar3 = (**(code **)(*a0 + 0x5c))(a0);
      if (((iVar3 == 0) && ((a0[5] & 0x200U) == 0)) &&
         ((iVar3 = FUN_0011379c(*(undefined4 *)(param_2 + 8),a0), iVar3 != 0 ||
          (iVar3 = FUN_001131c0(*(undefined4 *)(a0[0x22] + 8),*(undefined4 *)(param_2 + 8)),
          iVar3 != 0)))) {
        iVar3 = IRInst__getOperandRecord(inst,1);
        uVar8 = 0;
        local_48 = *(undefined4 *)(iVar3 + 0x10);
        do {
          iVar3 = IRInst__getOperandRecord(inst,0);
          if ((((*(char *)(uVar8 + iVar3 + 0x10) != '\x01') &&
               (uVar10 = (uint)local_44[uVar8 - 4], uVar10 != 4)) && (uVar8 != uVar10)) &&
             (iVar3 = IRInst__getOperandRecord(a0,0), *(char *)(uVar10 + iVar3 + 0x10) != '\x01')) {
            return;
          }
          bVar1 = uVar8 != 3;
          uVar8 = uVar8 + 1;
        } while (bVar1);
        puVar11 = (uint *)a0[4];
        uVar10 = 0;
        uVar8 = puVar11[1];
        if (uVar8 != 0) {
          do {
            if (uVar10 < *puVar11) {
              if (uVar8 <= uVar10) {
                _memset(uVar8 * 4 + puVar11[2],0,(uVar10 - uVar8) * 4 + 4);
                puVar11[1] = uVar10 + 1;
              }
              piVar4 = (int *)(uVar10 * 4 + puVar11[2]);
            }
            else {
              piVar4 = (int *)Vector__elementRefGrow(puVar11,uVar10);
            }
            iVar3 = *piVar4;
            if (((*(uint *)(iVar3 + 0x14) & 0x200) != 0) &&
               (piVar4 = (int *)IRInst__getOperandSource(iVar3,*(undefined4 *)(iVar3 + 0x84)), a0 == piVar4)) {
              return;
            }
            puVar11 = (uint *)a0[4];
            uVar10 = uVar10 + 1;
            uVar8 = puVar11[1];
          } while (uVar10 < uVar8);
        }
        *(int *)(param_2 + 0x164) = *(int *)(param_2 + 0x164) + 1;
        local_44[0] = 4;
        local_44[1] = 4;
        local_44[2] = 4;
        local_44[3] = 4;
        loopIndex = 0;
        IRInst__getOperandRecord(a0,0);
        piVar4 = a0;
        do {
          iVar3 = IRInst__getOperandRecord(inst,0);
          if (*(char *)(loopIndex + iVar3 + 0x10) != '\x01') {
            bVar2 = local_44[loopIndex - 4];
            uVar10 = (uint)bVar2;
            if ((uVar10 != 4) && (uVar10 != loopIndex)) {
              iVar9 = 1;
              iVar3 = FUN_0011379c(*(undefined4 *)(param_2 + 8),a0);
              if (iVar3 != 0) {
                for (; iVar3 = (**(code **)(*a0 + 0x14))(a0), iVar9 <= iVar3; iVar9 = iVar9 + 1) {
                  iVar3 = IRInst__getOperandRecord(a0,iVar9);
                  (**(code **)(*a0 + 0x88))(a0,iVar9,loopIndex,*(undefined1 *)(uVar10 + iVar3 + 0x10));
                }
              }
              iVar3 = IRInst__getOperandRecord(a0,0);
              if (*(char *)(loopIndex + iVar3 + 0x10) != '\0') {
                *(undefined1 *)(piVar4 + 0x27) = 0;
              }
              local_44[loopIndex] = bVar2;
            }
          }
          bVar1 = loopIndex != 3;
          piVar4 = (int *)((int)piVar4 + 1);
          loopIndex = loopIndex + 1;
        } while (bVar1);
        puVar11 = (uint *)a0[4];
        uVar10 = 0;
        uVar8 = puVar11[1];
        if (uVar8 != 0) {
          do {
            if (uVar10 < *puVar11) {
              if (uVar8 <= uVar10) {
                _memset(uVar8 * 4 + puVar11[2],0,(uVar10 - uVar8) * 4 + 4);
                puVar11[1] = uVar10 + 1;
              }
              puVar5 = (undefined4 *)(uVar10 * 4 + puVar11[2]);
            }
            else {
              puVar5 = (undefined4 *)Vector__elementRefGrow(puVar11,uVar10);
            }
            uVar10 = uVar10 + 1;
            piVar4 = (int *)*puVar5;
            for (iVar3 = 1; iVar9 = (**(code **)(*piVar4 + 0x14))(piVar4), iVar3 <= iVar9;
                iVar3 = iVar3 + 1) {
              operandVReg = (int *)IRInst__getOperandSource(piVar4,iVar3);
              if (a0 == operandVReg) {
                iVar9 = 0;
                do {
                  operandRecord = IRInst__getOperandRecord(piVar4,iVar3);
                  iVar12 = 3;
                  if (*(byte *)(iVar9 + operandRecord + 0x10) == local_44[iVar9]) {
                    (**(code **)(*piVar4 + 0x88))(piVar4,iVar3,iVar9,iVar9);
                  }
                  else {
                    do {
                      iVar12 = iVar12 + -1;
                    } while (iVar12 != 0);
                  }
                  bVar1 = iVar9 != 3;
                  iVar9 = iVar9 + 1;
                } while (bVar1);
              }
            }
            puVar11 = (uint *)a0[4];
            uVar8 = puVar11[1];
          } while (uVar10 < uVar8);
        }
      }
    }
  }
  return;
}

/* FUN_0015b8b8 @ 0x15b8b8 (188 bytes) */
int FUN_0015b8b8(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  while( true ) {
    if (((iVar2 == 0) ||
        (((iVar1 = *(int *)(*(int *)(iVar2 + 0x88) + 8), iVar1 != 0x3a && (iVar1 != 0x3b)) ||
         ((*(uint *)(iVar2 + 0xb8) & 1) != 0)))) || (*(int *)(iVar2 + 0x120) != 0)) {
      return 0;
    }
    iVar1 = IRInst__getOperandRecord(iVar2,0);
    iVar1 = FUN_000f37b8(*(undefined4 *)(iVar1 + 0x10));
    if (iVar1 < 0) {
      return 0;
    }
    if (iVar1 == param_2) break;
    if ((*(uint *)(iVar2 + 0x14) & 0x200) == 0) {
      return 0;
    }
    iVar2 = IRInst__getOperandSource(iVar2,*(undefined4 *)(iVar2 + 0x84));
  }
  *param_1 = iVar2;
  return 1;
}

/* FUN_0015b974 @ 0x15b974 (972 bytes) */
int FUN_0015b974(inst, param_2, param_3, param_4, param_5)
  int inst;
  undefined4 *param_2;
  undefined4 *param_3;
  uint *param_4;
  uint *param_5;
{
  int *operandVReg;
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 uVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  int *local_68;
  int *local_64;
  undefined1 auStack_60 [4];
  float local_5c;
  longlong local_48;
  undefined4 local_40;
  uint uStack_3c;
  
  if (*(int *)(*(int *)(inst + 0x88) + 8) == 0x37) {
    iVar1 = IRInst__getOperandRecord(inst,0);
    iVar1 = FUN_000f37b8(*(undefined4 *)(iVar1 + 0x10));
    if ((((-1 < iVar1) && (local_68 = (int *)IRInst__getOperandSource(inst,1), local_68[0x48] == 0)) &&
        ((*(uint *)(inst + 0xb8) & 1) == 0)) && ((*(uint *)(inst + 0xb8) & 2) == 0)) {
      iVar1 = IRInst__getOperandRecord(inst,1);
      uVar5 = (uint)*(byte *)(iVar1 + 0x13);
      iVar7 = *(int *)(local_68[0x22] + 8);
      iVar1 = ((int (*)())FUN_0015b8b8)(&local_68,uVar5);
      if (iVar1 == 0) {
        iVar1 = (**(code **)(*local_68 + 100))(local_68);
        if (iVar1 == 0) {
          if (iVar7 == 0x13) {
            if ((local_68[0x2e] & 1U) != 0) {
              return 0;
            }
            if ((local_68[0x2e] & 2U) != 0) {
              return 0;
            }
            if ((local_68[0x34] & 1U) != 0) {
              return 0;
            }
            if ((local_68[0x34] & 2U) != 0) {
              return 0;
            }
            local_64 = (int *)IRInst__getOperandSource(local_68,1);
            operandVReg = (int *)IRInst__getOperandSource(local_68,2);
            iVar1 = (**(code **)(*operandVReg + 0x48))(operandVReg);
            if (iVar1 == 0) {
              iVar1 = (**(code **)(*local_64 + 0x48))(local_64);
              if (iVar1 == 0) {
                return 0;
              }
              uVar2 = 2;
              uVar4 = 1;
              piVar6 = local_64;
              local_64 = operandVReg;
            }
            else {
              uVar2 = 1;
              uVar4 = 2;
              piVar6 = operandVReg;
            }
            iVar1 = IRInst__getOperandRecord(local_68,uVar2);
            iVar1 = ((int (*)())FUN_0015b8b8)(&local_64,(uint)*(byte *)(uVar5 + iVar1 + 0x10));
            piVar3 = local_68;
            if (iVar1 == 0) {
              return 0;
            }
            iVar1 = IRInst__getOperandRecord(local_68,0);
            iVar1 = FUN_000f5cf0(piVar3,uVar4,*(undefined4 *)(iVar1 + 0x10),auStack_60);
            if (iVar1 == 0) {
              *param_3 = piVar6;
            }
            else {
              local_40 = 0x43300000;
              uVar5 = (uint)(int)local_5c;
              local_48 = (longlong)(int)uVar5;
              uStack_3c = uVar5 ^ 0x80000000;
              if (local_5c != (float)((double)CONCAT44(0x43300000,uStack_3c) - 4503601774854144.0))
              {
                return 0;
              }
              *param_4 = uVar5;
              *param_3 = 0;
            }
            uVar2 = IRInst__getOperandSource(local_64,1);
            *param_2 = uVar2;
            piVar3 = local_64;
            goto LAB_0015bc04;
          }
          if ((iVar7 != 0x12) && (iVar7 != 0x9b)) {
            return 0;
          }
          local_64 = (int *)IRInst__getOperandSource(local_68,1);
          operandVReg = (int *)IRInst__getOperandSource(local_68,2);
          if (operandVReg != local_64) {
            return 0;
          }
          if ((local_68[0x2e] & 1U) != 0) {
            return 0;
          }
          if ((local_68[0x2e] & 2U) != 0) {
            return 0;
          }
          if ((local_68[0x34] & 1U) != 0) {
            return 0;
          }
          if ((local_68[0x34] & 2U) != 0) {
            return 0;
          }
          iVar1 = IRInst__getOperandRecord(local_68,1);
          iVar7 = *(int *)(iVar1 + 0x10);
          iVar1 = IRInst__getOperandRecord(local_68,2);
          if (iVar7 != *(int *)(iVar1 + 0x10)) {
            return 0;
          }
          iVar1 = IRInst__getOperandRecord(local_68,1);
          iVar1 = ((int (*)())FUN_0015b8b8)(&local_64,(uint)*(byte *)(uVar5 + iVar1 + 0x10));
          if (iVar1 == 0) {
            return 0;
          }
          uVar5 = 2;
        }
        else {
          local_64 = (int *)IRInst__getOperandSource(local_68,1);
          if ((local_68[0x2e] & 1U) != 0) {
            return 0;
          }
          if ((local_68[0x2e] & 2U) != 0) {
            return 0;
          }
          iVar1 = ((int (*)())FUN_0015b8b8)(&local_64,uVar5);
          if (iVar1 == 0) {
            return 0;
          }
          uVar5 = 1 << (local_64[0x49] + local_68[0x49] & 0x3fU);
        }
        *param_4 = uVar5;
        *param_3 = 0;
        uVar2 = IRInst__getOperandSource(local_64,1);
        *param_2 = uVar2;
        piVar3 = local_64;
      }
      else {
        *param_4 = 1 << (local_68[0x49] & 0x3fU);
        *param_3 = 0;
        uVar2 = IRInst__getOperandSource(local_68,1);
        *param_2 = uVar2;
        piVar3 = local_68;
      }
LAB_0015bc04:
      iVar1 = IRInst__getOperandRecord(piVar3,1);
      *param_5 = (uint)*(byte *)(iVar1 + 0x13);
      return 1;
    }
  }
  return 0;
}

/* FUN_0015bd40 @ 0x15bd40 (2452 bytes) */
int FUN_0015bd40(node, pass)
  int node;
  int pass;
{
  int *operandVReg;
  int *operandVReg4;
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int operandVReg5;
  int iVar12;
  int *piVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int *operandVReg2;
  int *operandVReg3;
  int *piVar20;
  uint uVar21;
  uint uVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  undefined4 uVar25;
  uint uVar26;
  int *piVar27;
  int local_88;
  undefined4 local_84;
  undefined4 local_80;
  int local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  int local_68;
  undefined4 local_58;
  
  if ((*(uint *)(node + 0x14) & 0x200) == 0) {
    return 0;
  }
  operandVReg5 = IRInst__getOperandSource(node,*(undefined4 *)(node + 0x84));
  if (operandVReg5 == 0) {
    return 0;
  }
  if ((*(uint *)(*(int *)(*(int *)(pass + 8) + 0x30c) + 8) & 0x100) == 0) {
    return 0;
  }
  iVar7 = *(int *)(*(int *)(node + 0x88) + 8);
  iVar9 = *(int *)(*(int *)(operandVReg5 + 0x88) + 8);
  if (iVar7 == 0x12) {
    iVar7 = operandVReg5;
    iVar17 = node;
    if (iVar9 != 0x14) {
      return 0;
    }
  }
  else {
    if (iVar7 != 0x14) {
      return 0;
    }
    iVar7 = node;
    iVar17 = operandVReg5;
    if (iVar9 != 0x12) {
      return 0;
    }
  }
  if (*(int *)(iVar17 + 0x120) != *(int *)(iVar7 + 0x120)) {
    return 0;
  }
  if (*(int *)(iVar17 + 0x124) != *(int *)(iVar7 + 0x124)) {
    return 0;
  }
  iVar9 = IRInst__getOperandRecord(iVar17,0);
  local_80 = *(undefined4 *)(iVar9 + 0x10);
  iVar12 = IRInst__getOperandRecord(iVar7,0);
  iVar9 = 0;
  local_84 = *(undefined4 *)(iVar12 + 0x10);
  iVar12 = 4;
  do {
    if ((*(char *)((int)&local_80 + iVar9) != '\x01') &&
       (*(char *)((int)&local_84 + iVar9) != '\x01')) {
      return 0;
    }
    iVar9 = iVar9 + 1;
    iVar12 = iVar12 + -1;
  } while (iVar12 != 0);
  operandVReg4 = (int *)IRInst__getOperandSource(iVar17,1);
  iVar9 = (**(code **)(*operandVReg4 + 0x60))(operandVReg4);
  if (iVar9 != 0) {
    return 0;
  }
  operandVReg4 = (int *)IRInst__getOperandSource(iVar17,2);
  iVar9 = (**(code **)(*operandVReg4 + 0x60))(operandVReg4);
  if (iVar9 != 0) {
    return 0;
  }
  iVar9 = FUN_001466f4(iVar17,1);
  iVar12 = FUN_001466f4(iVar17,2);
  iVar14 = FUN_001466f4(iVar7,1);
  iVar15 = FUN_001466f4(iVar7,2);
  iVar16 = FUN_001466f4(iVar7,3);
  uVar2 = *(uint *)(iVar7 + 0xd0) & 1;
  uVar3 = *(uint *)(iVar7 + 0xe8) & 1;
  uVar4 = *(uint *)(iVar7 + 0xb8) & 1;
  uVar26 = *(uint *)(iVar7 + 0xd0) >> 1 & 1;
  uVar21 = *(uint *)(iVar7 + 0xe8) >> 1 & 1;
  uVar5 = *(uint *)(iVar17 + 0xb8) & 1;
  uVar6 = *(uint *)(iVar17 + 0xd0) & 1;
  uVar8 = *(uint *)(iVar7 + 0xb8) >> 1 & 1;
  uVar22 = *(uint *)(iVar17 + 0xb8) >> 1 & 1;
  uVar10 = *(uint *)(iVar17 + 0xd0) >> 1 & 1;
  if ((((iVar9 == iVar14) && (iVar12 == iVar16)) && (uVar8 == uVar22)) &&
     ((uVar21 == uVar10 && (uVar3 == uVar6)))) {
    if (uVar2 == 0) {
      if (uVar4 != uVar5) goto LAB_0015bf6c;
    }
    else if (uVar4 == uVar5) goto LAB_0015bf6c;
    uVar23 = 1;
    uVar24 = 3;
    uVar25 = 2;
    goto LAB_0015c078;
  }
LAB_0015bf6c:
  if (((iVar9 == iVar15) && (iVar12 == iVar16)) &&
     ((uVar26 == uVar22 && ((uVar21 == uVar10 && (uVar3 == uVar6)))))) {
    if (uVar4 == 0) {
      if (uVar2 != uVar5) goto LAB_0015bfb0;
    }
    else if (uVar2 == uVar5) goto LAB_0015bfb0;
    uVar23 = 2;
    uVar24 = 3;
    uVar25 = 1;
    goto LAB_0015c078;
  }
LAB_0015bfb0:
  if ((((iVar12 == iVar14) && (iVar9 == iVar16)) && (uVar8 == uVar10)) &&
     ((uVar21 == uVar22 && (uVar3 == uVar5)))) {
    if (uVar2 == 0) {
      if (uVar4 != uVar6) goto LAB_0015bff4;
    }
    else if (uVar4 == uVar6) goto LAB_0015bff4;
    uVar23 = 3;
    uVar24 = 1;
    uVar25 = 2;
  }
  else {
LAB_0015bff4:
    if (iVar12 != iVar15) {
      return 0;
    }
    if (iVar9 != iVar16) {
      return 0;
    }
    if (uVar26 != uVar10) {
      return 0;
    }
    if (uVar21 != uVar22) {
      return 0;
    }
    if (uVar3 != uVar5) {
      return 0;
    }
    if (uVar4 == 0) {
      if (uVar2 != uVar6) {
        return 0;
      }
    }
    else if (uVar2 == uVar6) {
      return 0;
    }
    uVar23 = 3;
    uVar24 = 2;
    uVar25 = 1;
  }
LAB_0015c078:
  local_58 = 0;
  local_6c = 0;
  local_68 = 0;
  if ((*(uint *)(operandVReg5 + 0x14) & 0x200) != 0) {
    FUN_00104d3c(operandVReg5,&local_6c);
  }
  iVar9 = *(int *)(iVar17 + 0x160) - *(int *)(pass + 0x478);
  if (iVar9 < 0) {
    iVar9 = 0;
  }
  if (iVar17 == node) {
    iVar12 = IRInst__getOperandRecord(iVar17,0);
    local_7c = *(int *)(iVar12 + 0x10);
    iVar12 = IRInst__getOperandRecord(iVar17,1);
    local_78 = *(undefined4 *)(iVar12 + 0x10);
    iVar12 = IRInst__getOperandRecord(iVar17,2);
    local_74 = *(undefined4 *)(iVar12 + 0x10);
    iVar12 = IRInst__getOperandRecord(iVar7,uVar25);
    local_70 = *(undefined4 *)(iVar12 + 0x10);
    iVar14 = 4;
    local_88 = local_7c;
    iVar12 = 0;
    do {
      if (*(char *)((int)&local_84 + iVar12) != '\x01') {
        *(char *)((int)&local_88 + iVar12) = *(char *)((int)&local_84 + iVar12);
      }
      iVar12 = iVar12 + 1;
      iVar14 = iVar14 + -1;
    } while (iVar14 != 0);
    iVar12 = IRInst__getOperandSource(iVar17,1);
    *(int *)(iVar12 + 0x160) = *(int *)(iVar12 + 0x160) + -1;
    iVar12 = IRInst__getOperandSource(iVar17,2);
    iVar14 = *(int *)(iVar17 + 4);
    *(int *)(iVar12 + 0x160) = *(int *)(iVar12 + 0x160) + -1;
    DList__unlink(iVar17);
    piVar13 = (int *)FUN_00103ebc(iVar7,iVar17,*(undefined4 *)(pass + 8),0);
    Block__insertInstAfter(*(undefined4 *)(iVar14 + 0x158),iVar14,piVar13);
    iVar12 = piVar13[0x53];
    piVar13[0x27] = local_88;
    iVar17 = IRInst__getOperandRecord(piVar13,0);
    *(int *)(iVar17 + 8) = iVar12;
    operandVReg2 = (int *)IRInst__getOperandSource(iVar7,uVar23);
    operandVReg3 = (int *)IRInst__getOperandSource(iVar7,uVar24);
    operandVReg = (int *)IRInst__getOperandSource(iVar7,uVar25);
    iVar7 = (**(code **)(*operandVReg + 0x60))(operandVReg);
    if (iVar7 == 0) {
      piVar20 = (int *)FUN_0010a240(0xa2,*(undefined4 *)(pass + 8));
      Block__insertInstBefore(piVar13[0x56],piVar13,piVar20);
      piVar20[0x21] = 1;
      piVar20[0x25] = piVar20[0x53];
      piVar20[0x26] = 0x36;
      piVar20[0x27] = local_88;
      iVar7 = IRInst__getOperandSource(piVar13,uVar25);
      IRInst__setOperandSource(piVar20,1,iVar7,0,*(undefined4 *)(pass + 8));
      if (*(int *)(pass + 0x478) < *(int *)(iVar7 + 0x160)) {
        *(int *)(iVar7 + 0x160) = *(int *)(iVar7 + 0x160) + 1;
      }
      else {
        *(int *)(iVar7 + 0x160) = *(int *)(pass + 0x478) + 1;
      }
      iVar7 = 0;
      do {
        if (*(char *)((int)&local_84 + iVar7) != '\x01') {
          (**(code **)(*piVar20 + 0x88))(piVar20,1,iVar7,*(undefined1 *)((int)&local_70 + iVar7));
          (**(code **)(*piVar13 + 0x88))(piVar13,uVar25,iVar7,iVar7);
        }
        bVar1 = iVar7 != 3;
        iVar7 = iVar7 + 1;
      } while (bVar1);
      piVar20[0x21] = 2;
      iVar7 = 0;
      ((void (*)())FUN_000f79c4)(piVar20,pass,2,1.0,1.0,1.0,1.0);
      do {
        if (*(char *)((int)&local_7c + iVar7) != '\x01') {
          (**(code **)(*piVar20 + 0x88))(piVar20,1,iVar7,4);
          (**(code **)(*piVar20 + 0x88))(piVar20,2,iVar7,iVar7);
        }
        bVar1 = iVar7 != 3;
        iVar7 = iVar7 + 1;
      } while (bVar1);
      IRInst__setOperandSource(piVar13,uVar25,piVar20,0,*(undefined4 *)(pass + 8));
      piVar20[0x58] = *(int *)(pass + 0x478) + 1;
    }
    else {
      iVar17 = operandVReg[0x21];
      iVar7 = 0;
      piVar27 = operandVReg;
      do {
        if (*(char *)((int)&local_7c + iVar7) != '\x01') {
          iVar17 = iVar17 + 1;
          operandVReg[0x21] = iVar17;
          ((void (*)())FUN_000f79c4)(operandVReg,pass,iVar17,1.0,1.0,1.0,1.0);
          (**(code **)(*operandVReg + 0x88))(operandVReg,iVar17,iVar7,iVar7);
          *(undefined1 *)(piVar27 + 0x27) = 0;
        }
        bVar1 = iVar7 != 3;
        piVar27 = (int *)((int)piVar27 + 1);
        iVar7 = iVar7 + 1;
      } while (bVar1);
      if (*(int *)(pass + 0x478) < operandVReg[0x58]) {
        operandVReg[0x58] = operandVReg[0x58] + 1;
      }
      else {
        operandVReg[0x58] = *(int *)(pass + 0x478) + 1;
      }
    }
    iVar7 = 0;
    do {
      if (*(char *)((int)&local_7c + iVar7) != '\x01') {
        iVar17 = (**(code **)(*operandVReg2 + 0x60))(operandVReg2);
        if (iVar17 == 0) {
          (**(code **)(*piVar13 + 0x88))
                    (piVar13,uVar23,iVar7,*(undefined1 *)((int)&local_78 + iVar7));
        }
        else {
          iVar17 = IRInst__getOperandRecord(operandVReg2,0);
          iVar17 = FUN_000f3108(*(undefined4 *)(iVar17 + 0x10));
          (**(code **)(*operandVReg2 + 0x88))(operandVReg2,1,iVar17,*(undefined1 *)((int)&local_78 + iVar7));
          (**(code **)(*piVar13 + 0x88))(piVar13,uVar23,iVar7,iVar17);
          *(undefined1 *)((int)operandVReg2 + iVar17 + 0x9c) = 0;
        }
        iVar17 = (**(code **)(*operandVReg3 + 0x60))(operandVReg3);
        if (iVar17 == 0) {
          (**(code **)(*piVar13 + 0x88))
                    (piVar13,uVar24,iVar7,*(undefined1 *)((int)&local_74 + iVar7));
        }
        else {
          iVar17 = IRInst__getOperandRecord(operandVReg3,0);
          iVar17 = FUN_000f3108(*(undefined4 *)(iVar17 + 0x10));
          (**(code **)(*operandVReg3 + 0x88))(operandVReg3,1,iVar17,*(undefined1 *)((int)&local_74 + iVar7));
          (**(code **)(*piVar13 + 0x88))(piVar13,uVar24,iVar7,iVar17);
          *(undefined1 *)((int)operandVReg3 + iVar17 + 0x9c) = 0;
        }
        (**(code **)(*piVar13 + 0x88))(piVar13,uVar25,iVar7,iVar7);
      }
      bVar1 = iVar7 != 3;
      iVar7 = iVar7 + 1;
    } while (bVar1);
    if (*(int *)(pass + 0x478) < operandVReg2[0x58]) {
      operandVReg2[0x58] = operandVReg2[0x58] + 1;
    }
    else {
      operandVReg2[0x58] = *(int *)(pass + 0x478) + 1;
    }
    if (*(int *)(pass + 0x478) < operandVReg3[0x58]) {
      operandVReg3[0x58] = operandVReg3[0x58] + 1;
    }
    else {
      operandVReg3[0x58] = *(int *)(pass + 0x478) + 1;
    }
    if (local_68 != 0) {
      FUN_00106b48(piVar13,&local_6c,0,*(undefined4 *)(pass + 8));
      if (*(int *)(pass + 0x478) < *(int *)(local_68 + 0x160)) {
        *(int *)(local_68 + 0x160) = *(int *)(local_68 + 0x160) + 1;
      }
      else {
        *(int *)(local_68 + 0x160) = *(int *)(pass + 0x478) + 1;
      }
    }
    piVar13[0x58] = iVar9 + *(int *)(pass + 0x478);
    FUN_00105894(operandVReg5,*(undefined4 *)(pass + 8));
  }
  return 0;
}

/* FUN_0015c6d4 @ 0x15c6d4 (2012 bytes) */
int FUN_0015c6d4(inst, param_2)
  int *inst;
  int param_2;
{
  uint loopIndex;
  bool bVar1;
  bool bVar2;
  float fVar3;
  code *pcVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  int *piVar9;
  int operandRecord;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  undefined4 uVar14;
  int iVar15;
  uint loopIndex2;
  uint uVar17;
  uint *puVar18;
  double fparam_1;
  undefined8 operandRecord2;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined1 auStack_78 [4];
  float local_74;
  
  if ((inst[5] & 0x200U) == 0) {
    return 0;
  }
  iVar5 = IRInst__getOperandSource(inst,inst[0x21]);
  if (iVar5 == 0) {
    return 0;
  }
  if ((*(uint *)(*(int *)(*(int *)(param_2 + 8) + 0x30c) + 8) & 0x100) == 0) {
    return 0;
  }
  iVar15 = *(int *)(inst[0x22] + 8);
  if (2 < iVar15 - 0x12U) {
    return 0;
  }
  if (inst[0x48] != 0) {
    return 0;
  }
  uVar17 = 1;
  if (inst[0x49] != 0) {
    return 0;
  }
LAB_0015c82c:
  iVar6 = (**(code **)(*inst + 0x14))(inst);
  if (iVar6 < (int)uVar17) {
    return 0;
  }
  iVar6 = IRInst__getOperandSource(inst,uVar17);
  if ((iVar6 == iVar5) && ((inst[uVar17 * 6 + 0x28] & 2U) == 0)) {
    if (iVar15 == 0x12) {
      if ((inst[uVar17 * 6 + 0x28] & 1U) == 0) {
        uVar11 = uVar17 ^ 3;
        uVar13 = 0xffffffff;
LAB_0015c79c:
        if ((int)uVar17 < 0) {
          return 0;
        }
        uVar12 = 0xffffffff;
LAB_0015c880:
        iVar5 = IRInst__getOperandRecord(inst,0);
        local_88 = *(int *)(iVar5 + 0x10);
        operandRecord2 = IRInst__getOperandRecord(inst,uVar17);
        local_84 = *(undefined4 *)((int)((ulonglong)operandRecord2 >> 0x20) + 0x10);
        iVar5 = (**(code **)(*inst + 0x14))
                          (inst,(int)operandRecord2,in_r5,in_r6,in_r7,in_r8,*(code **)(*inst + 0x14));
        iVar5 = IRInst__getOperandRecord(inst,iVar5 + 1);
        local_80 = *(undefined4 *)(iVar5 + 0x10);
        iVar5 = Compiler__isOptionEnabled(*(undefined4 *)(param_2 + 8),0x30);
        if (iVar5 != 0) {
          if ((char)local_88 == '\0') {
            return 0;
          }
          if ((char)local_80 != '\x04') {
            return 0;
          }
        }
        iVar5 = 0;
        iVar15 = 4;
        do {
          if (*(char *)((int)&local_88 + iVar5) == '\0') {
            if (*(char *)((int)&local_80 + iVar5) != '\x04') {
              return 0;
            }
          }
          else if (*(char *)((int)&local_80 + iVar5) != '\x04') {
            *(undefined1 *)((int)&local_88 + iVar5) = 0;
            *(char *)((int)&local_84 + iVar5) = (char)iVar5;
          }
          uVar14 = local_84;
          iVar5 = iVar5 + 1;
          iVar15 = iVar15 + -1;
        } while (iVar15 != 0);
        iVar5 = IRInst__getOperandRecord(inst,uVar17);
        *(undefined4 *)(iVar5 + 0x10) = uVar14;
        inst[0x27] = local_88;
        iVar5 = IRInst__getOperandSource(inst,uVar17);
        *(int *)(iVar5 + 0x160) = *(int *)(iVar5 + 0x160) + -1;
        uVar14 = *(undefined4 *)(param_2 + 8);
        uVar17 = *(uint *)(param_2 + 0x30) >> 7 & 1;
        if (uVar17 != 0) {
          iVar5 = IRInst__getOperandSource(inst,inst[0x21]);
          puVar18 = *(uint **)(iVar5 + 0x10);
          uVar7 = puVar18[1];
          if (0 < (int)uVar7) {
            loopIndex2 = 0;
            do {
              if (loopIndex2 < *puVar18) {
                if (uVar7 <= loopIndex2) {
                  _memset(uVar7 * 4 + puVar18[2],0,(loopIndex2 - uVar7) * 4 + 4);
                  puVar18[1] = loopIndex2 + 1;
                }
                piVar8 = (int *)(loopIndex2 * 4 + puVar18[2]);
              }
              else {
                piVar8 = (int *)Vector__elementRefGrow(puVar18,loopIndex2);
              }
              if (inst == (int *)*piVar8) {
                Vector__removeAt(puVar18,loopIndex2);
                iVar5 = IRInst__getOperandSource(inst,inst[0x21]);
                *(int *)(iVar5 + 0x160) = *(int *)(iVar5 + 0x160) + -1;
                break;
              }
              uVar7 = puVar18[1];
              loopIndex2 = loopIndex2 + 1;
            } while ((int)loopIndex2 < (int)uVar7);
          }
        }
        loopIndex = 1;
        IRInst__setOperandSource(inst,inst[0x21],0,uVar17,uVar14);
        inst[0x21] = inst[0x21] + -1;
        inst[5] = inst[5] & 0xfffffdff;
        do {
          iVar5 = (**(code **)(*inst + 0x14))(inst);
          if (iVar5 < (int)loopIndex) {
            return 0;
          }
          if (loopIndex == uVar13) {
            fVar3 = 1.0;
LAB_0015ca9c:
            fparam_1 = (double)fVar3;
            piVar8 = (int *)IRInst__getOperandSource(inst,loopIndex);
            iVar5 = IRInst__getOperandRecord(inst,loopIndex);
            local_7c = *(undefined4 *)(iVar5 + 0x10);
            iVar5 = (**(code **)(*piVar8 + 0x60))(piVar8);
            if (iVar5 == 0) {
              iVar5 = 0;
              piVar9 = (int *)FUN_0010a240(0xa2,*(undefined4 *)(param_2 + 8));
              Block__insertInstBefore(inst[0x56],inst,piVar9);
              piVar9[0x21] = 1;
              piVar9[0x25] = piVar9[0x53];
              piVar9[0x26] = 0x36;
              piVar9[0x27] = local_88;
              IRInst__setOperandSource(piVar9,1,piVar8,0,*(undefined4 *)(param_2 + 8));
              piVar9[0x21] = 2;
              ((void (*)())FUN_000f79c4)(piVar9,param_2,2,fparam_1,fparam_1,fparam_1,fparam_1);
              do {
                if (*(char *)((int)&local_88 + iVar5) != '\x01') {
                  if (*(char *)((int)&local_80 + iVar5) == '\x04') {
                    (**(code **)(*piVar9 + 0x88))(piVar9,1,iVar5,auStack_78[iVar5 + -4]);
                    uVar14 = 2;
                    pcVar4 = *(code **)(*piVar9 + 0x88);
                  }
                  else {
                    (**(code **)(*piVar9 + 0x88))(piVar9,2,iVar5,iVar5);
                    uVar14 = 1;
                    pcVar4 = *(code **)(*piVar9 + 0x88);
                  }
                  (*pcVar4)(piVar9,uVar14,iVar5,4);
                  (**(code **)(*inst + 0x88))(inst,loopIndex,iVar5,iVar5);
                }
                bVar1 = iVar5 != 3;
                iVar5 = iVar5 + 1;
              } while (bVar1);
              IRInst__setOperandSource(inst,loopIndex,piVar9,0,*(undefined4 *)(param_2 + 8));
              piVar9[0x58] = *(int *)(param_2 + 0x478) + 1;
            }
            else {
              iVar5 = IRInst__hasSingleUse(piVar8,param_2);
              if (iVar5 == 0) {
                piVar8 = (int *)IRInst__clone(piVar8,*(undefined4 *)(param_2 + 8),0);
                Block__insertInstBefore(inst[0x56],inst,piVar8);
                piVar8[0x58] = *(int *)(param_2 + 0x478) + 1;
              }
              iVar5 = piVar8[0x21];
              if (1 < iVar5) {
                bVar1 = false;
                iVar15 = 2;
                do {
                  iVar5 = IRInst__getOperandRecord(piVar8,0);
                  iVar5 = FUN_000f5cf0(piVar8,iVar15,*(undefined4 *)(iVar5 + 0x10),auStack_78);
                  if ((iVar5 != 0) && (fparam_1 == (double)local_74)) {
                    iVar5 = -1;
                    iVar6 = 0;
                    do {
                      operandRecord = IRInst__getOperandRecord(piVar8,iVar15);
                      if (*(char *)(iVar6 + operandRecord + 0x10) != '\x04') {
                        iVar5 = iVar6;
                      }
                      bVar2 = iVar6 != 3;
                      iVar6 = iVar6 + 1;
                    } while (bVar2);
                    iVar6 = 0;
                    do {
                      if (*(char *)((int)&local_80 + iVar6) != '\x04') {
                        bVar1 = true;
                        (**(code **)(*inst + 0x88))(inst,loopIndex,iVar6,iVar5);
                      }
                      bVar2 = iVar6 != 3;
                      iVar6 = iVar6 + 1;
                    } while (bVar2);
                    if (bVar1) goto LAB_0015ce60;
                  }
                  iVar5 = piVar8[0x21];
                  iVar15 = iVar15 + 1;
                } while (iVar15 <= iVar5);
                if (bVar1) goto LAB_0015ce60;
              }
              iVar5 = iVar5 + 1;
              piVar8[0x21] = iVar5;
              ((void (*)())FUN_000f79c4)(piVar8,param_2,iVar5,fparam_1,fparam_1,fparam_1,fparam_1);
              iVar15 = IRInst__getOperandRecord(piVar8,iVar5);
              *(undefined4 *)(iVar15 + 0x10) = 0x4040404;
              iVar15 = 0;
              do {
                iVar6 = IRInst__getOperandRecord(piVar8,0);
                if (*(char *)(iVar15 + iVar6 + 0x10) != '\0') {
                  (**(code **)(*piVar8 + 0x88))(piVar8,iVar5,iVar15,iVar15);
                  *(undefined1 *)((int)piVar8 + iVar15 + 0x9c) = 0;
                  goto LAB_0015ce20;
                }
                bVar1 = iVar15 != 3;
                iVar15 = iVar15 + 1;
              } while (bVar1);
              iVar15 = -1;
LAB_0015ce20:
              iVar5 = 0;
              do {
                if (*(char *)((int)&local_80 + iVar5) != '\x04') {
                  (**(code **)(*inst + 0x88))(inst,loopIndex,iVar5,iVar15);
                }
                bVar1 = iVar5 != 3;
                iVar5 = iVar5 + 1;
              } while (bVar1);
            }
          }
          else if ((loopIndex == uVar11) || (loopIndex == uVar12)) {
            fVar3 = 0.0;
            goto LAB_0015ca9c;
          }
LAB_0015ce60:
          loopIndex = loopIndex + 1;
        } while( true );
      }
    }
    else if (iVar15 == 0x13) {
      if ((inst[0x2e] & 1U) == (inst[0x34] & 1U)) {
        uVar13 = uVar17 ^ 3;
        uVar11 = 0xffffffff;
        goto LAB_0015c79c;
      }
    }
    else if (iVar15 == 0x14) {
      if (uVar17 == 3) {
        if ((inst[0x3a] & 1U) == 0) {
          uVar17 = 3;
          uVar11 = 1;
          uVar12 = 2;
          uVar13 = 0xffffffff;
          goto LAB_0015c880;
        }
      }
      else if (((int)uVar17 < 3) && ((inst[0x2e] & 1U) == (inst[0x34] & 1U))) {
        uVar13 = uVar17 ^ 3;
        uVar11 = 3;
        goto LAB_0015c79c;
      }
    }
  }
  uVar17 = uVar17 + 1;
  goto LAB_0015c82c;
}

/* FUN_0015ceb0 @ 0x15ceb0 (3720 bytes) */
int FUN_0015ceb0(node, pass)
  int *node;
  int pass;
{
  int *operandVReg3;
  int *operandVReg;
  int *operandVReg4;
  bool bVar1;
  char cVar2;
  bool bVar3;
  bool bVar4;
  code *pcVar5;
  int iVar6;
  int *a0;
  int iVar7;
  int *piVar8;
  int *piVar9;
  int *operandVReg2;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  int iVar14;
  int *piVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  int *piVar23;
  int iVar24;
  int iVar25;
  int local_108;
  int local_104;
  int local_100;
  int local_fc;
  int local_f8;
  int local_f4 [3];
  int local_e8 [5];
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_8c;
  undefined4 local_88;
  int local_84;
  undefined4 local_74;
  int local_68;
  int *local_64;
  undefined *local_60;
  
  if ((node[5] & 0x200U) == 0) {
    return 0;
  }
  a0 = (int *)IRInst__getOperandSource(node,node[0x21]);
  if (a0 == (int *)0x0) {
    return 0;
  }
  if ((*(uint *)(*(int *)(*(int *)(pass + 8) + 0x30c) + 8) & 0x100) == 0) {
    return 0;
  }
  iVar24 = *(int *)(a0[0x22] + 8);
  if (*(int *)(node[0x22] + 8) == 0x12) {
    if (iVar24 == 0x12) {
      operandVReg = (int *)IRInst__getOperandSource(node,1);
      piVar9 = (int *)IRInst__getOperandSource(node,2);
      operandVReg2 = (int *)IRInst__getOperandSource(a0,1);
      piVar15 = (int *)IRInst__getOperandSource(a0,2);
      bVar1 = operandVReg == piVar15;
      if (bVar1) {
        bVar1 = piVar9 == operandVReg2;
        FUN_0010ac38(a0,1,2,*(uint *)(pass + 8));
        bVar4 = true;
        bVar3 = false;
        piVar23 = operandVReg;
        piVar15 = operandVReg2;
      }
      else {
        piVar23 = piVar9;
        if (piVar9 == operandVReg2) {
          FUN_0010ac38(node,1,2,*(uint *)(pass + 8));
          bVar4 = false;
          bVar3 = true;
          piVar9 = operandVReg;
        }
        else {
          bVar1 = piVar9 == piVar15;
          if (bVar1) {
            bVar1 = operandVReg == operandVReg2;
            FUN_0010ac38(a0,1,2,*(uint *)(pass + 8));
            FUN_0010ac38(node,1,2,*(uint *)(pass + 8));
            bVar4 = true;
            bVar3 = true;
            piVar15 = operandVReg2;
            piVar9 = operandVReg;
          }
          else {
            if (operandVReg != operandVReg2) {
              return 0;
            }
            bVar4 = false;
            bVar3 = false;
            piVar23 = operandVReg2;
          }
        }
      }
      iVar24 = IRInst__getOperandRecord(node,0);
      local_fc = *(int *)(iVar24 + 0x10);
      iVar24 = IRInst__getOperandRecord(a0,0);
      local_100 = *(int *)(iVar24 + 0x10);
      if ((((!bVar1) && (a0[0x49] == node[0x49])) && (a0[0x48] == node[0x48])) &&
         ((local_fc != 0x1010100 && (*(int *)(iVar24 + 0x10) != 0x1010100)))) {
        iVar7 = 4;
        local_64 = &local_100;
        iVar24 = 0;
        do {
          if ((*(char *)(iVar24 + (int)&local_100) != '\x01') &&
             (*(char *)((int)&local_fc + iVar24) != '\x01')) goto LAB_0015d1a4;
          iVar24 = iVar24 + 1;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
        if (((((a0[0x2e] & 1U) == (node[0x2e] & 1U)) && ((a0[0x34] & 1U) == (node[0x34] & 1U))
             ) && (((uint)a0[0x2e] >> 1 & 1) == ((uint)node[0x2e] >> 1 & 1))) &&
           (iVar24 = FUN_00146de0(piVar15,piVar9), iVar24 == 0)) {
          *(int *)(pass + 0x280) = *(int *)(pass + 0x280) + 1;
          FUN_000f2f84(&local_68,local_100,local_fc);
          local_104 = local_68;
          piVar9 = (int *)((int (*)())FUN_0010bed0)(2,local_68,piVar9,pass,*(undefined4 *)(pass + 8),1.0);
          if (*(int *)(pass + 0x478) < piVar15[0x58]) {
            piVar15[0x58] = piVar15[0x58] + 1;
          }
          else {
            piVar15[0x58] = *(int *)(pass + 0x478) + 1;
          }
          piVar15 = (int *)((int (*)())FUN_0010bed0)(2,local_104,piVar15,pass,*(undefined4 *)(pass + 8),1.0
                                       );
          iVar24 = IRInst__getOperandRecord(node,2);
          uVar12 = *(undefined4 *)(iVar24 + 0x10);
          iVar24 = IRInst__getOperandRecord(piVar9,1);
          *(undefined4 *)(iVar24 + 0x10) = uVar12;
          iVar24 = IRInst__getOperandRecord(a0,2);
          uVar12 = *(undefined4 *)(iVar24 + 0x10);
          iVar24 = IRInst__getOperandRecord(piVar15,1);
          *(undefined4 *)(iVar24 + 0x10) = uVar12;
          local_a0 = 0;
          local_9c = 0;
          local_8c = 0;
          local_e8[0] = 0;
          local_e8[1] = 0;
          local_d4 = 0;
          local_b8 = 0;
          local_b4 = 0;
          local_a4 = 0;
          local_d0 = 0;
          local_cc = 0;
          local_bc = 0;
          uVar12 = IRInst__getOperandRecord(a0,1);
          FUN_00104730(&local_a0,uVar12);
          uVar12 = IRInst__getOperandRecord(a0,2);
          FUN_00104730(local_e8,uVar12);
          uVar12 = IRInst__getOperandRecord(node,1);
          FUN_00104730(&local_b8,uVar12);
          uVar12 = IRInst__getOperandRecord(node,2);
          FUN_00104730(&local_d0,uVar12);
          iVar24 = IRInst__getOperandRecord(node,1);
          local_f8 = *(int *)(iVar24 + 0x10);
          iVar24 = IRInst__getOperandRecord(a0,1);
          local_108 = *(int *)(iVar24 + 0x10);
          local_f4[0] = 0;
          local_f4[1] = 0;
          local_f4[2] = 0;
          IRInst__saveCounters(node,local_f4,0xffffffff);
          local_88 = 0;
          local_84 = 0;
          local_74 = 0;
          if ((a0[5] & 0x200U) != 0) {
            FUN_00104d3c(a0,&local_88);
          }
          iVar24 = node[1];
          DList__unlink(node);
          FUN_00108304(node,0x14,*(undefined4 *)(pass + 8));
          Block__insertInstAfter(*(undefined4 *)(iVar24 + 0x158),iVar24,node);
          IRInst__restoreCounters(node,local_f4);
          iVar24 = a0[0x49];
          node[0x48] = a0[0x48];
          node[0x49] = iVar24;
          uVar12 = IRInst__getOperandRecord(node,3);
          FUN_00104730(uVar12,&local_b8);
          uVar12 = IRInst__getOperandRecord(node,1);
          FUN_00104730(uVar12,&local_d0);
          uVar12 = IRInst__getOperandRecord(node,2);
          FUN_00104730(uVar12,local_e8);
          IRInst__setOperandSource(node,1,piVar9,0,*(undefined4 *)(pass + 8));
          IRInst__setOperandSource(node,2,piVar15,0,*(undefined4 *)(pass + 8));
          IROperand__setModifierBits(node + 0x29,1,0);
          node[0x26] = 0;
          iVar24 = 0;
          node[0x25] = node[0x53];
          node[0x27] = local_104;
          do {
            if (*(char *)((int)&local_104 + iVar24) == '\0') {
              (**(code **)(*node + 0x88))(node,1,iVar24,iVar24);
              (**(code **)(*node + 0x88))(node,2,iVar24,iVar24);
              iVar7 = IRInst__getOperandRecord(piVar15,1);
              cVar2 = *(char *)(iVar24 + iVar7 + 0x10);
              iVar7 = IRInst__getOperandRecord(piVar9,1);
              if (cVar2 == '\x04') {
                if (*(char *)(iVar24 + iVar7 + 0x10) == '\x04') goto LAB_0015d5cc;
                (**(code **)(*piVar15 + 0x88))(piVar15,2,iVar24,iVar24);
                piVar8 = &local_f8;
                pcVar5 = *(code **)(*node + 0x88);
              }
              else {
                (**(code **)(*piVar9 + 0x88))(piVar9,2,iVar24,iVar24);
                piVar8 = &local_108;
                pcVar5 = *(code **)(*node + 0x88);
              }
              (*pcVar5)(node,3,iVar24,*(undefined1 *)(iVar24 + (int)piVar8));
            }
            else {
              (**(code **)(*node + 0x88))(node,1,iVar24,4);
              (**(code **)(*node + 0x88))(node,2,iVar24,4);
              (**(code **)(*node + 0x88))(node,3,iVar24,4);
            }
LAB_0015d5cc:
            bVar1 = iVar24 == 3;
            iVar24 = iVar24 + 1;
            if (bVar1) {
              Block__insertInstBefore(node[0x56],node,piVar15);
              Block__insertInstBefore(node[0x56],node,piVar9);
              if (local_84 != 0) {
                FUN_00106b48(node,&local_88,0,*(undefined4 *)(pass + 8));
                if (*(int *)(pass + 0x478) < *(int *)(local_84 + 0x160)) {
                  *(int *)(local_84 + 0x160) = *(int *)(local_84 + 0x160) + 1;
                }
                else {
                  *(int *)(local_84 + 0x160) = *(int *)(pass + 0x478) + 1;
                }
              }
              for (iVar24 = 1; iVar7 = (**(code **)(*a0 + 0x14))(a0), iVar24 <= iVar7;
                  iVar24 = iVar24 + 1) {
                operandVReg = (int *)IRInst__getOperandSource(a0,iVar24);
                if ((((a0[5] & 1U) == 0) ||
                    (iVar7 = (**(code **)(*operandVReg + 0x5c))(operandVReg), iVar7 == 0)) ||
                   (iVar7 = IRInst__hasSingleUse(operandVReg,pass), iVar7 != 0)) {
                  iVar7 = (**(code **)(*operandVReg + 0x60))(operandVReg);
                  if (((iVar7 != 0) && ((a0[5] & 1U) == 0)) && (piVar23 != operandVReg)) {
                    FUN_00105894(operandVReg,*(undefined4 *)(pass + 8));
                  }
                }
                else {
                  FUN_001049a0(operandVReg,pass);
                  uVar17 = *(uint *)(pass + 0x30) >> 7 & 1;
                  iVar7 = FUN_0010af38(operandVReg,pass,uVar17);
                  IRInst__setOperandSource(a0,iVar24,iVar7,0,*(undefined4 *)(pass + 8));
                  if (uVar17 == 0) {
                    if (*(int *)(pass + 0x478) < *(int *)(iVar7 + 0x160)) {
                      *(int *)(iVar7 + 0x160) = *(int *)(iVar7 + 0x160) + 1;
                    }
                    else {
                      *(int *)(iVar7 + 0x160) = *(int *)(pass + 0x478) + 1;
                    }
                  }
                  operandVReg[0x58] = operandVReg[0x58] + -1;
                }
              }
              operandVReg = (int *)IRInst__getOperandSource(piVar9,1);
              iVar24 = (**(code **)(*operandVReg + 0x60))(operandVReg);
              if (iVar24 != 0) {
                uVar12 = IRInst__getOperandSource(piVar9,1);
                FUN_0010c670(uVar12,piVar9,*(undefined4 *)(pass + 8));
              }
              operandVReg3 = (int *)IRInst__getOperandSource(piVar15,1);
              iVar24 = (**(code **)(*operandVReg3 + 0x60))(operandVReg3);
              if (iVar24 != 0) {
                uVar12 = IRInst__getOperandSource(piVar15,1);
                FUN_0010c670(uVar12,piVar15,*(undefined4 *)(pass + 8));
              }
              FUN_00105894(a0,*(undefined4 *)(pass + 8));
              if (bVar4) {
                FUN_0010ac38(a0,1,2,*(uint *)(pass + 8));
                return 1;
              }
              return 1;
            }
          } while( true );
        }
      }
LAB_0015d1a4:
      if (bVar4) {
        FUN_0010ac38(a0,1,2,*(uint *)(pass + 8));
      }
      if (!bVar3) {
        return 0;
      }
      FUN_0010ac38(node,1,2,*(uint *)(pass + 8));
      return 0;
    }
    iVar7 = (**(code **)(*a0 + 100))(a0);
    piVar15 = a0;
    piVar9 = node;
    if (iVar7 != 0) goto LAB_0015cf80;
  }
  iVar7 = (**(code **)(*node + 100))(node);
  if (iVar7 == 0) {
    return 0;
  }
  piVar15 = node;
  piVar9 = a0;
  if (iVar24 != 0x12) {
    return 0;
  }
LAB_0015cf80:
  iVar24 = IRInst__getOperandSource(piVar15,1);
  iVar7 = IRInst__getOperandSource(piVar9,1);
  if (iVar24 == iVar7) {
    iVar24 = 1;
    iVar7 = 2;
  }
  else {
    iVar24 = IRInst__getOperandSource(piVar15,1);
    iVar7 = IRInst__getOperandSource(piVar9,2);
    if (iVar24 != iVar7) {
      return 0;
    }
    iVar24 = 2;
    iVar7 = 1;
  }
  iVar11 = IRInst__getOperandRecord(node,0);
  local_108 = *(int *)(iVar11 + 0x10);
  iVar11 = IRInst__getOperandRecord(a0,0);
  local_104 = *(int *)(iVar11 + 0x10);
  if ((a0[0x49] == node[0x49]) && (a0[0x48] == node[0x48])) {
    if (((piVar15[0x2e] & 1U) == (piVar9[iVar24 * 6 + 0x28] & 1U)) &&
       (((uint)piVar15[0x2e] >> 1 & 1) == ((uint)piVar9[iVar24 * 6 + 0x28] >> 1 & 1))) {
      iVar6 = 0;
      iVar25 = 4;
      do {
        if ((*(char *)((int)&local_104 + iVar6) != '\x01') &&
           (*(char *)((int)&local_108 + iVar6) != '\x01')) {
          return 0;
        }
        iVar6 = iVar6 + 1;
        iVar25 = iVar25 + -1;
      } while (iVar25 != 0);
      if ((local_108 != 0x1010100) && (*(int *)(iVar11 + 0x10) != 0x1010100)) {
        *(int *)(pass + 0x280) = *(int *)(pass + 0x280) + 1;
        iVar11 = node[0x58] - *(int *)(pass + 0x478);
        uVar17 = *(uint *)(pass + 0x30) >> 7 & 1;
        if (iVar11 < 0) {
          iVar11 = 0;
        }
        iVar25 = 4;
        iVar18 = node[4];
        iVar19 = node[0x53];
        iVar20 = node[0x26];
        iVar21 = node[0x48];
        iVar6 = 0;
        iVar22 = node[0x49];
        local_64 = &local_100;
        local_100 = local_108;
        do {
          if (*(char *)((int)&local_104 + iVar6) != '\x01') {
            *(char *)(iVar6 + (int)&local_100) = *(char *)((int)&local_104 + iVar6);
          }
          iVar6 = iVar6 + 1;
          iVar25 = iVar25 + -1;
        } while (iVar25 != 0);
        iVar25 = IRInst__getOperandRecord(piVar9,iVar7);
        iVar6 = 0;
        local_fc = *(int *)(iVar25 + 0x10);
        iVar25 = 4;
        do {
          if (*(char *)(iVar6 + (int)local_64) == '\0') {
            *(char *)((int)&local_fc + iVar6) = (char)iVar6;
          }
          iVar6 = iVar6 + 1;
          iVar25 = iVar25 + -1;
        } while (iVar25 != 0);
        iVar6 = IRInst__getOperandRecord(piVar9,iVar24);
        local_e8[0] = *(int *)(iVar6 + 0x10);
        iVar25 = IRInst__getOperandRecord(piVar15,1);
        iVar6 = 0;
        local_f8 = *(int *)(iVar25 + 0x10);
        iVar25 = 4;
        do {
          if (*(char *)((int)local_e8 + iVar6) == '\x04') {
            *(undefined1 *)((int)local_e8 + iVar6) = *(undefined1 *)((int)&local_f8 + iVar6);
          }
          iVar6 = iVar6 + 1;
          iVar25 = iVar25 + -1;
        } while (iVar25 != 0);
        uVar12 = IRInst__getOperandSource(piVar9,iVar7);
        iVar6 = FUN_0010af38(uVar12,pass,uVar17);
        iVar25 = IRInst__getOperandSource(piVar9,iVar24);
        iVar13 = FUN_0010a240(0xa2,*(undefined4 *)(pass + 8));
        Block__insertInstBefore(node[0x56],node,iVar13);
        *(undefined4 *)(iVar13 + 0x84) = 1;
        *(undefined4 *)(iVar13 + 0x94) = *(undefined4 *)(iVar13 + 0x14c);
        *(undefined4 *)(iVar13 + 0x98) = 0x36;
        *(int *)(iVar13 + 0x9c) = local_100;
        IRInst__setOperandSource(iVar13,1,iVar6,0,*(undefined4 *)(pass + 8));
        iVar14 = IRInst__getOperandRecord(piVar9,iVar7);
        uVar12 = *(undefined4 *)(iVar14 + 0x10);
        iVar14 = IRInst__getOperandRecord(iVar13,1);
        *(undefined4 *)(iVar14 + 0x10) = uVar12;
        if (*(int *)(pass + 0x478) < *(int *)(iVar6 + 0x160)) {
          *(int *)(iVar6 + 0x160) = *(int *)(iVar6 + 0x160) + 1;
        }
        else {
          *(int *)(iVar6 + 0x160) = *(int *)(pass + 0x478) + 1;
        }
        *(undefined4 *)(iVar13 + 0x84) = 2;
        ((void (*)())FUN_000f79c4)(iVar13,pass,2,0.0,0.0,0.0,0.0);
        iVar6 = IRInst__getOperandRecord(piVar15,1);
        uVar12 = *(undefined4 *)(iVar6 + 0x10);
        iVar6 = IRInst__getOperandRecord(iVar13,2);
        *(undefined4 *)(iVar6 + 0x10) = uVar12;
        iVar6 = IRInst__getOperandSource(iVar13,2);
        if (*(int *)(pass + 0x478) < *(int *)(iVar6 + 0x160)) {
          *(int *)(iVar6 + 0x160) = *(int *)(iVar6 + 0x160) + 1;
        }
        else {
          *(int *)(iVar6 + 0x160) = *(int *)(pass + 0x478) + 1;
        }
        *(undefined4 *)(iVar13 + 0x160) = *(undefined4 *)(pass + 0x478);
        operandVReg4 = (int *)IRInst__getOperandSource(iVar13,1);
        iVar6 = (**(code **)(*operandVReg4 + 0x60))(operandVReg4);
        if (iVar6 != 0) {
          uVar12 = IRInst__getOperandSource(iVar13,1);
          FUN_0010c670(uVar12,iVar13,*(undefined4 *)(pass + 8));
        }
        iVar6 = 0;
        local_60 = &DAT_001acec0;
        local_f4[0] = 0x4040404;
        if (((a0[5] & 0x200U) != 0) && (iVar6 = IRInst__getOperandSource(a0,a0[0x21]), iVar6 != 0)) {
          iVar16 = IRInst__getOperandRecord(node,node[0x21]);
          iVar14 = 0;
          local_f4[0] = *(int *)(iVar16 + 0x10);
          iVar16 = 4;
          do {
            if (*(char *)(iVar14 + (int)local_64) == '\0') {
              *(undefined1 *)((int)local_f4 + iVar14) = 4;
            }
            iVar14 = iVar14 + 1;
            iVar16 = iVar16 + -1;
          } while (iVar16 != 0);
        }
        if (0 < node[0x21]) {
          iVar14 = 1;
          do {
            iVar16 = IRInst__getOperandSource(node,iVar14);
            *(int *)(iVar16 + 0x160) = *(int *)(iVar16 + 0x160) + -1;
            if (uVar17 != 0) {
              iVar16 = IRInst__getOperandSource(node,iVar14);
              FUN_00194374(*(undefined4 *)(iVar16 + 0x10),node);
            }
            iVar14 = iVar14 + 1;
          } while (iVar14 <= node[0x21]);
        }
        local_a4 = 0;
        local_d0 = 0;
        local_cc = 0;
        local_bc = 0;
        local_b8 = 0;
        local_b4 = 0;
        uVar12 = IRInst__getOperandRecord(piVar9,iVar7);
        FUN_00104730(&local_d0,uVar12);
        uVar12 = IRInst__getOperandRecord(piVar9,iVar24);
        FUN_00104730(&local_b8,uVar12);
        iVar14 = node[1];
        DList__unlink(node);
        FUN_00108174(node,0x12,*(undefined4 *)(pass + 8));
        bVar1 = uVar17 == 0;
        Block__insertInstAfter(*(undefined4 *)(iVar14 + 0x158),iVar14,node);
        iVar14 = *(int *)(pass + 0x478);
        node[4] = iVar18;
        node[0x58] = iVar11 + iVar14;
        node[0x27] = local_100;
        node[0x48] = iVar21;
        node[0x49] = iVar22;
        node[0x25] = iVar19;
        node[0x26] = iVar20;
        uVar12 = IRInst__getOperandRecord(node,iVar7);
        FUN_001047a8(uVar12,&local_d0);
        IRInst__setOperandSource(node,iVar7,iVar13,0,*(undefined4 *)(pass + 8));
        iVar11 = local_fc;
        if (bVar1) {
          if (*(int *)(pass + 0x478) < *(int *)(iVar13 + 0x160)) {
            *(int *)(iVar13 + 0x160) = *(int *)(iVar13 + 0x160) + 1;
          }
          else {
            *(int *)(iVar13 + 0x160) = *(int *)(pass + 0x478) + 1;
          }
        }
        if (iVar7 == 0) {
          node[0x27] = local_fc;
        }
        else {
          iVar7 = IRInst__getOperandRecord(node,iVar7);
          *(int *)(iVar7 + 0x10) = iVar11;
        }
        uVar12 = IRInst__getOperandRecord(node,iVar24);
        FUN_001047a8(uVar12,&local_b8);
        IRInst__setOperandSource(node,iVar24,iVar25,0,*(undefined4 *)(pass + 8));
        iVar7 = local_e8[0];
        if (bVar1) {
          if (*(int *)(pass + 0x478) < *(int *)(iVar25 + 0x160)) {
            *(int *)(iVar25 + 0x160) = *(int *)(iVar25 + 0x160) + 1;
          }
          else {
            *(int *)(iVar25 + 0x160) = *(int *)(pass + 0x478) + 1;
          }
        }
        if (iVar24 == 0) {
          node[0x27] = local_e8[0];
        }
        else {
          iVar24 = IRInst__getOperandRecord(node,iVar24);
          *(int *)(iVar24 + 0x10) = iVar7;
        }
        if ((iVar6 != 0) && (local_f4[0] != *(int *)(((unsigned char *)0x00003190U) + (int)local_60))) {
          IRInst__setExtraOperandSource(node,iVar6,uVar17,*(undefined4 *)(pass + 8));
          iVar24 = local_f4[0];
          iVar7 = IRInst__getOperandRecord(node,3);
          *(int *)(iVar7 + 0x10) = iVar24;
          if (bVar1) {
            if (*(int *)(pass + 0x478) < *(int *)(iVar6 + 0x160)) {
              *(int *)(iVar6 + 0x160) = *(int *)(iVar6 + 0x160) + 1;
            }
            else {
              *(int *)(iVar6 + 0x160) = *(int *)(pass + 0x478) + 1;
            }
          }
        }
        FUN_0010564c(a0,*(undefined4 *)(pass + 8),0);
        return 0;
      }
    }
  }
  return 0;
}

/* FUN_0015df44 @ 0x15df44 (600 bytes) */
int FUN_0015df44(inst, param_2)
  int *inst;
  int param_2;
{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int *operandVReg;
  int *operandVReg2;
  int iVar6;
  int *inst2;
  int iVar8;
  int inst3;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  
  if (*(int *)(inst[0x22] + 8) == 0x13) {
    operandVReg = (int *)IRInst__getOperandSource(inst,1);
    operandVReg2 = (int *)IRInst__getOperandSource(inst,2);
    if ((((((*(int *)(operandVReg[0x22] + 8) == 0x37) &&
           (iVar6 = IRInst__hasSingleUse(operandVReg,param_2), iVar6 != 0)) && ((operandVReg[5] & 0x200U) == 0)) &&
         ((operandVReg[0x48] == 0 && (operandVReg[0x49] == 0)))) &&
        ((*(int *)(operandVReg2[0x22] + 8) == 0x37 &&
         ((iVar6 = IRInst__hasSingleUse(operandVReg2,param_2), iVar6 != 0 && ((operandVReg2[5] & 0x200U) == 0)))))) &&
       ((operandVReg2[0x48] == 0 && (operandVReg2[0x49] == 0)))) {
      iVar13 = inst[0x58] - *(int *)(param_2 + 0x478);
      iVar6 = inst[0x48];
      iVar11 = inst[0x49];
      iVar12 = inst[0x53];
      if (iVar13 < 0) {
        iVar13 = 0;
      }
      iVar14 = inst[0x25];
      bVar1 = ((inst[0x34] ^ inst[0x2e]) & 1U) != 0;
      iVar15 = inst[0x26];
      iVar8 = IRInst__getOperandRecord(inst,0);
      iVar16 = *(int *)(iVar8 + 0x10);
      inst3 = IRInst__create(0x12,*(undefined4 *)(param_2 + 8));
      FUN_00105e54(inst3,1,operandVReg,1);
      FUN_00105e54(inst3,2,operandVReg2,1);
      iVar8 = DAT_001b0054;
      iVar3 = *(int *)(param_2 + 0x478);
      *(undefined4 *)(inst3 + 0x94) = *(undefined4 *)(inst3 + 0x14c);
      *(undefined4 *)(inst3 + 0x98) = 0;
      *(int *)(inst3 + 0x9c) = iVar8;
      iVar10 = inst[0x56];
      *(int *)(inst3 + 0x160) = iVar3 + 1;
      Block__insertInstBefore(iVar10,inst,inst3);
      if (bVar1) {
        inst2 = (int *)IRInst__create(0x37,*(undefined4 *)(param_2 + 8));
        iVar3 = *(int *)(param_2 + 0x478);
        inst2[0x27] = iVar8;
        inst2[0x58] = iVar3 + 1;
        inst2[0x25] = inst2[0x53];
        uVar2 = DAT_001b0050;
        inst2[0x26] = 0;
        iVar8 = IRInst__getOperandRecord(inst2,1);
        *(undefined4 *)(iVar8 + 0x10) = uVar2;
        (**(code **)(*inst2 + 0x88))(inst2,1,3,3);
        Block__insertInstBefore(inst[0x56],inst,inst2);
        DList__unlink(inst);
        FUN_00108448(inst,0x31,*(undefined4 *)(param_2 + 8));
        IRInst__setOperandSource(inst,1,inst2,0,*(undefined4 *)(param_2 + 8));
        Block__insertInstAfter(inst2[0x56],inst2,inst);
        IROperand__setModifierBits(inst + 0x29,1,1);
      }
      else {
        DList__unlink(inst);
        FUN_00107da8(inst,0x37,*(undefined4 *)(param_2 + 8));
        Block__insertInstAfter(*(undefined4 *)(inst3 + 0x158),inst3,inst);
        inst2 = inst;
      }
      IRInst__setOperandSource(inst2,1,inst3,0,*(undefined4 *)(param_2 + 8));
      inst[0x48] = iVar6;
      inst[0x49] = iVar11;
      inst[0x53] = iVar12;
      inst[0x58] = iVar13 + *(int *)(param_2 + 0x478);
      iVar6 = IRInst__getOperandRecord(inst,0);
      inst[0x27] = iVar16;
      *(int *)(iVar6 + 0xc) = iVar15;
      *(int *)(iVar6 + 8) = iVar14;
      if (bVar1) {
        iVar6 = 0;
        do {
          iVar11 = IRInst__getOperandRecord(inst,0);
          if (*(char *)(iVar6 + iVar11 + 0x10) != '\x01') {
            (**(code **)(*inst + 0x88))(inst,1,iVar6,3);
          }
          bVar1 = iVar6 != 3;
          iVar6 = iVar6 + 1;
        } while (bVar1);
      }
      (**(code **)(*operandVReg + 0xc))(operandVReg,0,*(undefined4 *)(param_2 + 8));
      (**(code **)(*operandVReg2 + 0xc))(operandVReg2,0,*(undefined4 *)(param_2 + 8));
      return 1;
    }
  }
  return 0;
}

/* FUN_0015e2f4 @ 0x15e2f4 (416 bytes) */
undefined4 FUN_0015e2f4(int inst,int param_2,undefined4 param_3,undefined4 param_4,double fparam_1)
{
  int iVar1;
  undefined4 operandVReg;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 auStack_48 [4];
  float local_44;
  
  if (((((*(int *)(inst + 0x120) == 0) && (*(int *)(inst + 0x124) == 0)) &&
       ((*(uint *)(inst + 0xb8) & 1) == 0)) &&
      (((*(uint *)(inst + 0xb8) & 2) == 0 && ((*(uint *)(inst + 0xd0) & 1) == 0)))) &&
     (((*(uint *)(inst + 0xd0) & 2) == 0 && (*(int *)(*(int *)(inst + 0x88) + 8) == param_2)))
     ) {
    iVar1 = IRInst__getOperandRecord(inst,0);
    iVar1 = FUN_000f5cf0(inst,1,*(undefined4 *)(iVar1 + 0x10),auStack_48);
    if ((iVar1 != 0) && (fparam_1 == (double)local_44)) {
      operandVReg = IRInst__getOperandSource(inst,2);
      iVar1 = IRInst__getOperandRecord(inst,2);
      uVar4 = *(undefined4 *)(iVar1 + 0x10);
      uVar3 = IRInst__getOperandSource(inst,1);
      IRInst__setOperandSource(inst,2,uVar3,0,param_4);
      iVar1 = IRInst__getOperandRecord(inst,1);
      uVar3 = *(undefined4 *)(iVar1 + 0x10);
      iVar1 = IRInst__getOperandRecord(inst,2);
      *(undefined4 *)(iVar1 + 0x10) = uVar3;
      IRInst__setOperandSource(inst,1,operandVReg,0,param_4);
      iVar1 = IRInst__getOperandRecord(inst,1);
      *(undefined4 *)(iVar1 + 0x10) = uVar4;
      return operandVReg;
    }
    iVar1 = IRInst__getOperandRecord(inst,0);
    iVar1 = FUN_000f5cf0(inst,2,*(undefined4 *)(iVar1 + 0x10),auStack_48);
    if ((iVar1 != 0) && ((double)local_44 == fparam_1)) {
      operandVReg = IRInst__getOperandSource(inst,1);
      return operandVReg;
    }
  }
  return 0;
}

/* FUN_0015e494 @ 0x15e494 (772 bytes) */
int FUN_0015e494(inst, param_2)
  int *inst;
  int param_2;
{
  int loopIndex;
  bool bVar1;
  byte bVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int *operandVReg;
  int operandRecord;
  int operandVReg2;
  undefined4 uVar12;
  undefined4 in_r5;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  undefined4 local_88;
  byte local_84 [4];
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_64;
  
  iVar16 = *(int *)(param_2 + 8);
  iVar3 = (**(code **)(**(int **)(iVar16 + 0x30c) + 0x80))(*(int **)(iVar16 + 0x30c),param_2);
  if (iVar3 == 0) {
    return 0;
  }
  iVar3 = ((undefined4 (*)())FUN_0015e2f4)(inst,0x17,in_r5,iVar16,0.0);
  if (iVar3 == 0) {
    iVar3 = ((undefined4 (*)())FUN_0015e2f4)(inst,0x19,in_r5,iVar16,1.0);
    if (iVar3 == 0) {
      return 0;
    }
    piVar4 = (int *)((undefined4 (*)())FUN_0015e2f4)(iVar3,0x17,in_r5,iVar16,0.0);
  }
  else {
    piVar4 = (int *)((undefined4 (*)())FUN_0015e2f4)(iVar3,0x19,in_r5,iVar16,1.0);
  }
  if (piVar4 == (int *)0x0) {
    return 0;
  }
  if ((*(uint *)(iVar3 + 0x14) & 0x200) != 0) {
    return 0;
  }
  if ((piVar4[5] & 0x200U) != 0) {
    return 0;
  }
  *(int *)(param_2 + 0x1a8) = *(int *)(param_2 + 0x1a8) + 1;
  iVar5 = IRInst__getOperandRecord(inst,0);
  iVar17 = 0;
  local_84[0] = 4;
  local_84[1] = 4;
  local_84[2] = 4;
  local_84[3] = 4;
  local_88 = *(undefined4 *)(iVar5 + 0x10);
  do {
    if (*(char *)((int)&local_88 + iVar17) != '\x01') {
      iVar5 = IRInst__getOperandRecord(inst,1);
      bVar2 = *(byte *)(iVar17 + iVar5 + 0x10);
      iVar5 = IRInst__getOperandRecord(iVar3,1);
      local_84[iVar17] = *(byte *)((uint)bVar2 + iVar5 + 0x10);
    }
    bVar1 = iVar17 != 3;
    iVar17 = iVar17 + 1;
  } while (bVar1);
  iVar17 = *(int *)(param_2 + 0x478);
  iVar5 = inst[0x58] - iVar17;
  if (iVar5 < 0) {
    iVar5 = 0;
  }
  local_64 = 0;
  local_78 = 0;
  local_74 = 0;
  uVar6 = IRInst__getOperandRecord(inst,0);
  FUN_00104730(&local_78,uVar6);
  iVar13 = inst[2];
  if (iVar17 < piVar4[0x58]) {
    piVar4[0x58] = piVar4[0x58] + 1;
  }
  else {
    piVar4[0x58] = iVar17 + 1;
  }
  FUN_00105894(iVar3,iVar16);
  iVar14 = 0;
  if ((inst[5] & 0x200U) != 0) {
    iVar14 = IRInst__getOperandSource(inst,inst[0x21]);
  }
  uVar6 = 0x10203;
  if (iVar14 != 0) {
    iVar7 = IRInst__getOperandRecord(inst,inst[0x21]);
    uVar6 = *(undefined4 *)(iVar7 + 0x10);
  }
  DList__unlink(inst);
  iVar7 = FUN_001134bc(piVar4[0x22],piVar4,param_2);
  iVar8 = FUN_000f31e8(inst,1);
  if (iVar8 != 0) {
    iVar3 = FUN_000f31e8(iVar3,1);
    bVar1 = true;
    if (iVar3 != 0) goto LAB_0015e6ec;
  }
  bVar1 = false;
LAB_0015e6ec:
  iVar3 = (**(code **)(*piVar4 + 0x24))(piVar4);
  if (((iVar3 == 0) || (iVar3 = IRInst__hasSingleUse(piVar4,param_2), iVar3 == 0)) ||
     ((bVar1 = !bVar1, bVar1 &&
      ((((iVar7 != 0 && (iVar7 != 3)) && (iVar7 != 4)) && ((iVar7 != 5 && (iVar7 != 7)))))))) {
    FUN_00108448(inst,0x31,iVar16);
    iVar7 = 0;
    bVar1 = true;
    IRInst__setOperandSource(inst,1,piVar4,0,iVar16);
    iVar3 = IRInst__getOperandRecord(inst,1);
    *(undefined4 *)(iVar3 + 0x10) = 0x10203;
  }
  else {
    iVar3 = 1;
    if (0 < piVar4[0x21]) {
      do {
        iVar8 = IRInst__getOperandSource(piVar4,iVar3);
        if (iVar17 < *(int *)(iVar8 + 0x160)) {
          *(int *)(iVar8 + 0x160) = *(int *)(iVar8 + 0x160) + 1;
        }
        else {
          *(int *)(iVar8 + 0x160) = iVar17 + 1;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 <= piVar4[0x21]);
    }
    inst = (int *)FUN_00103ebc(piVar4,inst,iVar16,0);
    FUN_00105894(piVar4,iVar16);
    if (((piVar4[5] & 1U) != 0) && (iVar3 = 1, 0 < piVar4[0x21])) {
      do {
        operandVReg = (int *)IRInst__getOperandSource(inst,iVar3);
        iVar8 = (**(code **)(*operandVReg + 0x5c))();
        if (iVar8 != 0) {
          iVar15 = iVar17 + 1;
          operandVReg[0x58] = iVar15;
          iVar8 = IRInst__clone(operandVReg,iVar16,0);
          IRInst__setOperandSource(inst,iVar3,iVar8,0,iVar16);
          Block__insertInstAfter(operandVReg[0x56],operandVReg,iVar8);
          uVar12 = *(undefined4 *)(iVar8 + 0x14c);
          *(int *)(iVar8 + 0x160) = iVar15;
          operandRecord = IRInst__getOperandRecord(iVar8,0);
          *(undefined4 *)(operandRecord + 8) = uVar12;
          if (0 < *(int *)(iVar8 + 0x84)) {
            loopIndex = 1;
            do {
              operandVReg2 = IRInst__getOperandSource(iVar8,loopIndex);
              if (iVar17 < *(int *)(operandVReg2 + 0x160)) {
                *(int *)(operandVReg2 + 0x160) = *(int *)(operandVReg2 + 0x160) + 1;
              }
              else {
                *(int *)(operandVReg2 + 0x160) = iVar15;
              }
              loopIndex = loopIndex + 1;
            } while (loopIndex <= *(int *)(iVar8 + 0x84));
          }
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 <= piVar4[0x21]);
    }
  }
  inst[0x58] = iVar17 + iVar5;
  uVar12 = IRInst__getOperandRecord(inst,0);
  FUN_00104730(uVar12,&local_78);
  uVar12 = *(undefined4 *)(iVar13 + 0x158);
  inst[0x48] = 1;
  Block__insertInstBefore(uVar12,iVar13,inst);
  if (iVar14 != 0) {
    IRInst__setExtraOperandSource(inst,iVar14,0,iVar16);
    iVar3 = IRInst__getOperandRecord(inst,inst[0x21]);
    *(undefined4 *)(iVar3 + 0x10) = uVar6;
  }
  if ((bVar1) && (iVar7 == 0)) {
    for (iVar3 = 1; iVar16 = (**(code **)(*inst + 0x14))(inst), iVar3 <= iVar16;
        iVar3 = iVar3 + 1) {
      iVar16 = IRInst__getOperandRecord(inst,iVar3);
      iVar5 = 0;
      local_7c = 0x4040404;
      local_80 = *(undefined4 *)(iVar16 + 0x10);
      iVar16 = 4;
      do {
        if (*(char *)((int)&local_88 + iVar5) == '\0') {
          *(undefined1 *)((int)&local_7c + iVar5) =
               *(undefined1 *)((int)&local_80 + (uint)local_84[iVar5]);
        }
        uVar6 = local_7c;
        iVar5 = iVar5 + 1;
        iVar16 = iVar16 + -1;
      } while (iVar16 != 0);
      iVar16 = IRInst__getOperandRecord(inst,iVar3);
      *(undefined4 *)(iVar16 + 0x10) = uVar6;
    }
  }
  return 1;
}

/* FUN_0015ea3c @ 0x15ea3c (696 bytes) */
int FUN_0015ea3c(param_1, param_2, node, pass)
  int param_1;
  undefined4 param_2;
  int *node;
  int pass;
{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int *operandVReg;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  undefined4 a1;
  undefined4 uVar9;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar10;
  uint uVar11;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  int local_68;
  undefined4 local_64;
  int local_60;
  uint local_5c;
  uint local_58;
  uint local_54;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c [3];
  
  local_70 = 0;
  if ((((param_1 != 0) && (*(int *)(*(int *)(param_1 + 0x88) + 8) != 0x8e)) &&
      ((node[5] & 0x200U) != 0)) && (iVar3 = FUN_00126760(node[0x26]), iVar3 != 0)) {
    iVar3 = (**(code **)(*node + 100))(node);
    if (((iVar3 == 0) || (node[0x48] != 0)) ||
       ((node[0x49] != 0 || (((node[0x2e] & 1U) != 0 || ((node[0x2e] & 2U) != 0)))))) {
      iVar3 = (**(code **)(*node + 100))(node);
      if (iVar3 == 0) {
        operandVReg = (int *)IRInst__getOperandSource(node,node[0x21]);
        iVar3 = (**(code **)(*operandVReg + 100))();
        if ((((iVar3 != 0) && ((operandVReg[5] & 0x200U) == 0)) && (operandVReg[0x48] == 0)) &&
           (((operandVReg[0x49] == 0 && ((operandVReg[0x2e] & 1U) == 0)) &&
            ((uVar11 = operandVReg[0x2e] & 2, uVar11 == 0 &&
             (iVar3 = FUN_000f5a0c(operandVReg,1,operandVReg,pass), iVar3 != 0)))))) {
          *(int *)(pass + 0x228) = *(int *)(pass + 0x228) + 1;
          iVar5 = node[1];
          DList__unlink(node);
          local_5c = uVar11;
          local_58 = uVar11;
          local_54 = uVar11;
          IRInst__saveCounters(node,&local_5c,0xffffffff);
          iVar3 = IRInst__clone(node,*(undefined4 *)(pass + 8),0);
          *(int *)(iVar3 + 0x160) = *(int *)(pass + 0x478) + 1;
          *(undefined4 *)(iVar3 + 0x94) = *(undefined4 *)(iVar3 + 0x14c);
          IRInst__setOperandSource(iVar3,*(undefined4 *)(iVar3 + 0x84),0,0,*(undefined4 *)(pass + 8));
          uVar6 = *(undefined4 *)(iVar5 + 0x158);
          *(int *)(iVar3 + 0x84) = *(int *)(iVar3 + 0x84) + -1;
          *(uint *)(iVar3 + 0x14) = *(uint *)(iVar3 + 0x14) & 0xfffffdff;
          Block__insertInstAfter(uVar6,iVar5,iVar3);
          IRMix__ctor_10a1c0(node,0xa2,*(undefined4 *)(pass + 8));
          iVar7 = 0;
          Block__insertInstAfter(*(undefined4 *)(iVar3 + 0x158),iVar3,node);
          iVar5 = IRInst__getOperandRecord(iVar3,0);
          uVar6 = *(undefined4 *)(iVar5 + 0x10);
          iVar5 = IRInst__getOperandRecord(iVar3,0);
          local_68 = *(int *)(iVar5 + 0x10);
          iVar5 = IRInst__getOperandRecord(operandVReg,0);
          local_64 = *(undefined4 *)(iVar5 + 0x10);
          do {
            iVar5 = IRInst__getOperandRecord(iVar3,0);
            if (*(char *)(iVar7 + iVar5 + 0x10) != '\x01') {
              *(undefined1 *)((int)&local_64 + iVar7) = 1;
            }
            bVar2 = iVar7 != 3;
            iVar7 = iVar7 + 1;
          } while (bVar2);
          iVar7 = IRInst__getOperandRecord(operandVReg,0);
          iVar5 = 0;
          local_6c = *(undefined4 *)(iVar7 + 0x10);
          iVar7 = 4;
          do {
            if (*(char *)((int)&local_6c + iVar5) != '\x01') {
              *(char *)((int)&local_68 + iVar5) = *(char *)((int)&local_6c + iVar5);
            }
            iVar5 = iVar5 + 1;
            iVar7 = iVar7 + -1;
          } while (iVar7 != 0);
          node[0x27] = local_68;
          node[0x25] = node[0x53];
          node[0x26] = 0x36;
          IRInst__restoreCounters(node,&local_5c);
          node[0x21] = 2;
          IRInst__setOperandSource(node,1,iVar3,0,*(undefined4 *)(pass + 8));
          FUN_000f3908(&local_48,uVar6);
          FUN_000f3340(&local_44,0x10203,local_48);
          iVar3 = IRInst__getOperandRecord(node,1);
          *(undefined4 *)(iVar3 + 0x10) = local_44;
          uVar6 = IRInst__getOperandSource(operandVReg,1);
          IRInst__setOperandSource(node,2,uVar6,0,*(undefined4 *)(pass + 8));
          iVar3 = IRInst__getOperandRecord(operandVReg,1);
          uVar6 = *(undefined4 *)(iVar3 + 0x10);
          FUN_000f3908(&local_40,local_64);
          FUN_000f3340(local_3c,uVar6,local_40);
          iVar3 = IRInst__getOperandRecord(node,2);
          *(undefined4 *)(iVar3 + 0x10) = local_3c[0];
          FUN_00105894(operandVReg,*(undefined4 *)(pass + 8));
          ((int (*)())FUN_00160320)(param_1,param_2,node,pass,&local_70);
          return 1;
        }
      }
    }
    else {
      bVar2 = true;
      iVar3 = 0;
      operandVReg = (int *)IRInst__getOperandSource(node,node[0x21]);
      do {
        iVar5 = IRInst__getOperandRecord(node,0);
        if (((*(char *)(iVar3 + iVar5 + 0x10) == '\x01') &&
            (iVar5 = IRInst__getOperandRecord(operandVReg,0), *(char *)(iVar3 + iVar5 + 0x10) == '\x01')) &&
           ((operandVReg[5] & 0x200U) != 0)) {
          bVar2 = false;
        }
        bVar1 = iVar3 != 3;
        iVar3 = iVar3 + 1;
      } while (bVar1);
      if (bVar2) {
        iVar3 = pass;
        iVar5 = FUN_000f5a0c(node,1,node,pass);
        if (iVar5 == 0) {
          iVar3 = (**(code **)(*operandVReg + 100))(operandVReg);
          if (iVar3 == 0) {
            return 0;
          }
          uVar11 = operandVReg[5] & 0x200;
          if (uVar11 != 0) {
            return 0;
          }
          iVar3 = FUN_000f5a0c(operandVReg,1,operandVReg,pass);
          if (iVar3 == 0) {
            return 0;
          }
          *(int *)(pass + 0x228) = *(int *)(pass + 0x228) + 1;
          local_5c = uVar11;
          local_58 = uVar11;
          local_54 = uVar11;
          IRInst__saveCounters(node,&local_5c,0xffffffff);
          uVar6 = IRInst__getOperandSource(node,1);
          iVar3 = IRInst__getOperandRecord(node,0);
          local_60 = *(int *)(iVar3 + 0x10);
          iVar5 = IRInst__getOperandRecord(operandVReg,1);
          iVar3 = 0;
          local_64 = *(undefined4 *)(iVar5 + 0x10);
          iVar5 = 4;
          do {
            if (*(char *)((int)&local_60 + iVar3) != '\x01') {
              *(undefined1 *)((int)&local_64 + iVar3) = 4;
            }
            iVar3 = iVar3 + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
          iVar5 = IRInst__getOperandRecord(operandVReg,0);
          iVar3 = 0;
          local_78 = *(undefined4 *)(iVar5 + 0x10);
          iVar5 = 4;
          do {
            if (*(char *)((int)&local_78 + iVar3) != '\x01') {
              *(char *)((int)&local_60 + iVar3) = *(char *)((int)&local_78 + iVar3);
            }
            iVar3 = iVar3 + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
          iVar3 = IRInst__getOperandRecord(node,1);
          iVar5 = node[1];
          uVar9 = *(undefined4 *)(iVar3 + 0x10);
          DList__unlink(node);
          IRMix__ctor_10a1c0(node,0xa2,*(undefined4 *)(pass + 8));
          IRInst__restoreCounters(node,&local_5c);
          node[0x26] = 0x36;
          node[0x25] = node[0x53];
          node[0x27] = local_60;
          node[0x21] = 2;
          IRInst__setOperandSource(node,1,uVar6,0,*(undefined4 *)(pass + 8));
          iVar3 = IRInst__getOperandRecord(node,1);
          *(undefined4 *)(iVar3 + 0x10) = uVar9;
          uVar6 = IRInst__getOperandSource(operandVReg,1);
          IRInst__setOperandSource(node,2,uVar6,0,*(undefined4 *)(pass + 8));
          uVar6 = local_64;
          iVar3 = IRInst__getOperandRecord(node,2);
          *(undefined4 *)(iVar3 + 0x10) = uVar6;
          Block__insertInstAfter(*(undefined4 *)(iVar5 + 0x158),iVar5,node);
          FUN_00105894(operandVReg,*(undefined4 *)(pass + 8));
        }
        else {
          *(int *)(pass + 0x228) = *(int *)(pass + 0x228) + 1;
          local_54 = 0;
          local_5c = 0;
          local_58 = 0;
          IRInst__saveCounters(node,&local_5c,0xffffffff);
          uVar6 = IRInst__getOperandSource(node,1);
          iVar5 = IRInst__getOperandRecord(node,0);
          local_68 = *(int *)(iVar5 + 0x10);
          iVar7 = IRInst__getOperandRecord(operandVReg,0);
          iVar5 = 0;
          local_74 = *(undefined4 *)(iVar7 + 0x10);
          iVar7 = 4;
          do {
            if (*(char *)((int)&local_74 + iVar5) != '\x01') {
              *(char *)((int)&local_68 + iVar5) = *(char *)((int)&local_74 + iVar5);
            }
            iVar5 = iVar5 + 1;
            iVar7 = iVar7 + -1;
          } while (iVar7 != 0);
          iVar5 = 0;
          local_64 = 0x10203;
          do {
            iVar7 = IRInst__getOperandRecord(node,0);
            if (*(char *)(iVar5 + iVar7 + 0x10) != '\x01') {
              *(undefined1 *)((int)&local_64 + iVar5) = 4;
            }
            bVar2 = iVar5 != 3;
            iVar5 = iVar5 + 1;
          } while (bVar2);
          iVar5 = 0;
          iVar7 = 4;
          do {
            if (*(char *)((int)&local_68 + iVar5) == '\x01') {
              *(undefined1 *)((int)&local_64 + iVar5) = 4;
            }
            iVar5 = iVar5 + 1;
            iVar7 = iVar7 + -1;
          } while (iVar7 != 0);
          iVar5 = IRInst__getOperandRecord(node,1);
          local_60 = *(int *)(iVar5 + 0x10);
          iVar5 = node[1];
          DList__unlink(node);
          uVar9 = *(undefined4 *)(pass + 8);
          IRMix__ctor_10a1c0(node,0xa2,uVar9);
          IRInst__restoreCounters(node,&local_5c);
          node[0x26] = 0x36;
          node[0x25] = node[0x53];
          node[0x27] = local_68;
          iVar3 = (**(code **)(*operandVReg + 0x60))(operandVReg,a1,uVar9,iVar3,in_r7,in_r8,local_68);
          if (iVar3 == 0) {
            node[0x21] = 2;
            IRInst__setOperandSource(node,1,operandVReg,0,*(undefined4 *)(pass + 8));
            uVar9 = local_64;
            iVar3 = IRInst__getOperandRecord(node,1);
            *(undefined4 *)(iVar3 + 0x10) = uVar9;
            IRInst__setOperandSource(node,2,uVar6,0,*(undefined4 *)(pass + 8));
            iVar3 = local_60;
            iVar7 = IRInst__getOperandRecord(node,2);
            *(int *)(iVar7 + 0x10) = iVar3;
          }
          else {
            node[0x21] = operandVReg[0x21] + 1;
            if (0 < operandVReg[0x21]) {
              iVar3 = 1;
              do {
                uVar9 = IRInst__getOperandSource(operandVReg,iVar3);
                IRInst__setOperandSource(node,iVar3,uVar9,0,*(undefined4 *)(pass + 8));
                iVar7 = IRInst__getOperandRecord(operandVReg,iVar3);
                iVar7 = *(int *)(iVar7 + 0x10);
                if (iVar3 == 0) {
                  node[0x27] = iVar7;
                }
                else {
                  iVar8 = IRInst__getOperandRecord(node,iVar3);
                  *(int *)(iVar8 + 0x10) = iVar7;
                }
                iVar3 = iVar3 + 1;
              } while (iVar3 <= operandVReg[0x21]);
            }
            operandVReg[0x58] = operandVReg[0x58] + -1;
            iVar3 = IRInst__getOperandSource(operandVReg,1);
            if (*(int *)(pass + 0x478) < *(int *)(iVar3 + 0x160)) {
              *(int *)(iVar3 + 0x160) = *(int *)(iVar3 + 0x160) + 1;
            }
            else {
              *(int *)(iVar3 + 0x160) = *(int *)(pass + 0x478) + 1;
            }
            iVar3 = node[0x21];
            iVar7 = 0;
            do {
              if ((*(char *)((int)&local_60 + iVar7) != '\x04') && (0 < iVar3)) {
                iVar8 = 1;
                do {
                  iVar10 = iVar8 + 1;
                  (**(code **)(*node + 0x88))(node,iVar8,iVar7,4);
                  iVar3 = node[0x21];
                  iVar8 = iVar10;
                } while (iVar10 <= iVar3);
              }
              bVar2 = iVar7 != 3;
              iVar7 = iVar7 + 1;
            } while (bVar2);
            IRInst__setOperandSource(node,iVar3,uVar6,0,*(undefined4 *)(pass + 8));
            iVar3 = local_60;
            if (node[0x21] == 0) {
              node[0x27] = local_60;
            }
            else {
              iVar7 = IRInst__getOperandRecord(node,node[0x21]);
              *(int *)(iVar7 + 0x10) = iVar3;
            }
          }
          Block__insertInstAfter(*(undefined4 *)(iVar5 + 0x158),iVar5,node);
          FUN_0010564c(operandVReg,*(undefined4 *)(pass + 8),0);
          iVar3 = (**(code **)(*operandVReg + 100))(operandVReg);
          if (iVar3 == 0) {
            return 1;
          }
        }
        ((int (*)())FUN_00160320)(param_1,param_2,node,pass,&local_70);
        return 1;
      }
    }
  }
  return 0;
}

/* FUN_0015f44c @ 0x15f44c (2576 bytes) */
int FUN_0015f44c(inst, param_2, node, pass)
  int inst;
  undefined4 param_2;
  int *node;
  int pass;
{
  int *operandVReg;
  bool bVar1;
  bool bVar2;
  bool bVar3;
  byte bVar4;
  float fVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  int operandRecord;
  int iVar11;
  undefined4 uVar12;
  undefined4 in_r8;
  undefined4 uVar13;
  uint uVar14;
  undefined4 uVar15;
  int iVar16;
  int *piVar17;
  int iVar18;
  int iVar19;
  uint uVar20;
  uint uVar21;
  double fparam_1;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  int local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  int local_ac;
  undefined4 local_a8;
  int local_a0 [5];
  undefined4 *local_8c;
  undefined4 *local_88;
  undefined4 *local_84;
  undefined4 *local_80;
  undefined4 *local_7c;
  undefined4 local_70;
  
  piVar17 = (int *)0x0;
  if ((node[5] & 0x200U) != 0) {
    piVar17 = (int *)IRInst__getOperandSource(node,node[0x21]);
  }
  uVar15 = *(undefined4 *)(pass + 8);
  if ((piVar17 == (int *)0x0) || (iVar6 = (**(code **)(*piVar17 + 0x60))(piVar17), iVar6 == 0)) {
    if ((inst != 0) &&
       (((node != (int *)0x0 && (*(int *)(*(int *)(inst + 0x88) + 8) == 0x8e)) &&
        (iVar6 = (**(code **)(*node + 0x60))(node), iVar6 != 0)))) {
      iVar11 = FUN_001084b8(0x31,*(undefined4 *)(pass + 8));
      iVar6 = *(int *)(pass + 0x478);
      *(undefined4 *)(iVar11 + 0x98) = 0;
      *(int *)(iVar11 + 0x160) = iVar6 + 1;
      *(undefined4 *)(iVar11 + 0x94) = *(undefined4 *)(iVar11 + 0x14c);
      IRInst__setOperandSource(iVar11,1,node,0,*(undefined4 *)(pass + 8));
      iVar6 = IRInst__getOperandRecord(node,0);
      *(undefined4 *)(iVar11 + 0x9c) = *(undefined4 *)(iVar6 + 0x10);
      FUN_000f4698(iVar11,1,pass);
      Block__insertInstAfter(node[0x56],node,iVar11);
      *(uint *)(iVar11 + 0x14) = *(uint *)(iVar11 + 0x14) | 0x80000000;
      IRInst__setOperandSource(inst,param_2,iVar11,0,*(undefined4 *)(pass + 8));
      return 0;
    }
    return 0;
  }
  iVar6 = IRInst__getOperandRecord(node,node[0x21]);
  uVar13 = *(undefined4 *)(iVar6 + 0x10);
  iVar6 = IRInst__getOperandRecord(piVar17,0);
  local_c8 = *(undefined4 *)(iVar6 + 0x10);
  if (0 < node[0x21]) {
    iVar6 = 1;
    do {
      iVar11 = IRInst__getOperandSource(node,iVar6);
      if ((*(int *)(iVar11 + 0x98) != 0x33) ||
         (iVar11 = IRInst__getOperandSource(node,iVar6), *(int *)(iVar11 + 300) == 3)) {
        bVar1 = true;
        goto LAB_0015f564;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 <= node[0x21]);
  }
  bVar1 = false;
LAB_0015f564:
  iVar6 = *(int *)(node[0x22] + 8);
  if (!bVar1) goto LAB_0015fd14;
  operandVReg = (int *)IRInst__getOperandSource(piVar17,1);
  if (((operandVReg[0x20] == 0) || (iVar11 = FUN_00126760(operandVReg[0x26]), iVar11 == 0)) ||
     (((operandVReg[5] & 2U) != 0 || (iVar11 = (**(code **)(*operandVReg + 0x50))(operandVReg), iVar11 != 0)))) {
    iVar11 = IRInst__getOperandRecord(piVar17,1);
    uVar12 = *(undefined4 *)(iVar11 + 0x10);
    iVar11 = IRInst__getOperandRecord(node,0);
    iVar11 = FUN_00146624(uVar12,*(undefined4 *)(iVar11 + 0x10));
    if (iVar11 != 0) goto LAB_0015f5cc;
  }
  else {
LAB_0015f5cc:
    if (iVar6 - 0x12U < 3) {
      iVar11 = (**(code **)(*piVar17 + 0x14))(piVar17);
      local_a0[1] = 0;
      local_b0 = 0;
      local_ac = 0;
      if (iVar11 < 1) {
        local_a0[2] = 0;
        local_a0[4] = 0;
        local_a0[3] = 0;
        goto LAB_0015f7bc;
      }
      iVar16 = 1;
      local_a0[4] = 0;
      uVar14 = 0;
      local_a0[3] = 0;
      do {
        iVar9 = IRInst__getOperandSource(piVar17,iVar16);
        if (*(int *)(iVar9 + 0x98) == 0x33) {
          iVar18 = IRInst__getOperandRecord(piVar17,iVar16);
          uVar21 = 0;
          local_bc = *(undefined4 *)(iVar18 + 0x10);
          do {
            bVar4 = *(byte *)((int)&local_bc + uVar21);
            if ((bVar4 != 4) &&
               (iVar18 = IRInst__getOperandRecord(node,0), *(char *)(uVar21 + iVar18 + 0x10) == '\x01')) {
              fVar5 = *(float *)((uint)bVar4 * 0x18 + iVar9 + 0x20);
              local_70 = 0;
              if (fVar5 == 0.0) {
                local_a0[3] = local_a0[3] | 1 << (uVar21 & 0x3f);
              }
              else {
                local_70 = 0x3f800000;
                if (fVar5 == 1.0) {
                  local_a0[4] = local_a0[4] | 1 << (uVar21 & 0x3f);
                }
                else {
                  uVar14 = uVar14 | 1 << (uVar21 & 0x3f);
                }
              }
            }
            bVar1 = uVar21 != 3;
            uVar21 = uVar21 + 1;
          } while (bVar1);
        }
        else {
          FUN_00104d3c(node,&local_b0);
          local_ac = iVar9;
        }
        iVar16 = iVar16 + 1;
      } while (iVar16 <= iVar11);
      local_a0[2] = 0;
      if ((local_a0[4] != 0) &&
         ((1 < iVar6 - 0x13U || (local_a0[2] = 6, (node[0x2e] & 1U) != (node[0x34] & 1U))))) {
        if (iVar6 == 0x12) {
          local_a0[2] = 2;
          if ((node[0x34] & 1U) != 0) {
            uVar21 = node[0x2e];
            local_a0[2] = 4;
            goto joined_r0x0015f784;
          }
        }
        else {
          if (iVar6 == 0x14) {
            uVar21 = node[0x3a];
            local_a0[2] = 1;
joined_r0x0015f784:
            if ((uVar21 & 1) == 0) goto LAB_0015f7a8;
          }
          local_a0[2] = -1;
        }
      }
LAB_0015f7a8:
      if ((uVar14 == 0) && (-1 < local_a0[2])) {
LAB_0015f7bc:
        uVar14 = 2;
        bVar1 = local_a0[4] == 0;
        iVar11 = IRInst__getOperandRecord(node,0);
        local_8c = &local_bc;
        local_88 = &local_c8;
        local_bc = *(undefined4 *)(iVar11 + 0x10);
        local_84 = local_8c;
        local_80 = local_88;
        local_7c = local_8c;
        do {
          iVar16 = 3 - uVar14;
          iVar11 = (**(code **)(*node + 0x14))(node);
          if (iVar11 < iVar16) {
            IRInst__setOperandSource(node,node[0x21],0,0,uVar15);
            node[0x21] = node[0x21] + -1;
            node[5] = node[5] & 0xfffffdff;
            if (local_ac != 0) {
              iVar6 = IRInst__getOperandRecord(node,0);
              iVar11 = 0;
              piVar7 = local_a0;
              local_b8 = *(int *)(iVar6 + 0x10);
              iVar6 = 4;
              do {
                if (*(char *)((int)&local_b8 + iVar11) != '\x01') {
                  *(undefined1 *)piVar7 = 4;
                }
                iVar11 = iVar11 + 1;
                piVar7 = (int *)((int)piVar7 + 1);
                iVar6 = iVar6 + -1;
              } while (iVar6 != 0);
              if (local_a0[0] != 0x4040404) {
                FUN_00106b48(node,&local_b0,0,uVar15);
                if (*(int *)(pass + 0x478) < *(int *)(local_ac + 0x160)) {
                  *(int *)(local_ac + 0x160) = *(int *)(local_ac + 0x160) + 1;
                }
                else {
                  *(int *)(local_ac + 0x160) = *(int *)(pass + 0x478) + 1;
                }
              }
            }
            (**(code **)(*node + 0x14))(node);
            FUN_00105894(piVar17,uVar15);
            return 1;
          }
          uVar13 = IRInst__getOperandSource(node,iVar16);
          if ((bVar1) || ((local_a0[3] == 0 && (iVar6 == 0x13)))) {
            uVar21 = local_a0[2] >> (uVar14 & 0x3f);
            if ((uVar21 & 1) == 0) goto LAB_0015f88c;
            iVar11 = 2;
            fparam_1 = 1.0;
          }
          else {
            uVar21 = local_a0[2] >> (uVar14 & 0x3f);
            if ((uVar21 & 1) == 0) {
LAB_0015f88c:
              iVar11 = 2;
              fparam_1 = 0.0;
            }
            else {
              iVar11 = 3;
              fparam_1 = 1.0;
            }
          }
          bVar3 = local_a0[3] != 0;
          iVar18 = 0;
          piVar8 = (int *)((int (*)())FUN_0010bed0)(iVar11,0x1010101,uVar13,pass,uVar15,fparam_1);
          iVar9 = IRInst__getOperandRecord(node,iVar16);
          local_b8 = *(int *)(iVar9 + 0x10);
          piVar7 = piVar8;
          do {
            if (*(char *)((int)&local_b8 + iVar18) != '\x04') {
              (**(code **)(*piVar8 + 0x88))(piVar8,1,iVar18);
              *(undefined1 *)(piVar7 + 0x27) = 0;
              (**(code **)(*node + 0x88))(node,iVar16,iVar18,iVar18);
            }
            bVar2 = iVar18 != 3;
            piVar7 = (int *)((int)piVar7 + 1);
            iVar18 = iVar18 + 1;
          } while (bVar2);
          iVar9 = -1;
          iVar18 = -1;
          iVar19 = 0;
          piVar7 = piVar8;
          do {
            operandRecord = IRInst__getOperandRecord(piVar8,1);
            if ((*(char *)(iVar19 + operandRecord + 0x10) == '\x04') &&
               (*(char *)(iVar19 + (int)local_8c) == '\x01')) {
              if ((iVar11 == 3) || (fparam_1 == 1.0)) {
                if (iVar9 < 0) {
                  (**(code **)(*piVar8 + 0x88))(piVar8,2,iVar19,iVar19);
                  *(undefined1 *)(piVar7 + 0x27) = 0;
                  iVar9 = iVar19;
                  goto LAB_0015fa2c;
                }
                if (iVar11 != 3) goto LAB_0015f9e8;
              }
              else {
LAB_0015f9e8:
                if (fparam_1 != 0.0) break;
              }
              if (-1 < iVar18) break;
              (**(code **)(*piVar8 + 0x88))(piVar8,iVar11,iVar19,iVar19);
              *(undefined1 *)(piVar7 + 0x27) = 0;
              iVar18 = iVar19;
            }
LAB_0015fa2c:
            bVar2 = iVar19 != 3;
            piVar7 = (int *)((int)piVar7 + 1);
            iVar19 = iVar19 + 1;
          } while (bVar2);
          if (!bVar1) {
            uVar20 = 0;
            piVar7 = node;
            do {
              if ((((local_a0[4] >> (uVar20 & 0x3f) & 1U) != 0) &&
                  (*(char *)(uVar20 + (int)local_88) != '\x01')) &&
                 (*(char *)(uVar20 + (int)local_84) == '\x01')) {
                if ((uVar21 & 1) == 0) {
                  (**(code **)(*node + 0x88))(node,iVar16,uVar20,iVar18);
                }
                else {
                  (**(code **)(*node + 0x88))(node,iVar16,uVar20,iVar9);
                }
                *(undefined1 *)(piVar7 + 0x27) = 0;
              }
              bVar2 = uVar20 != 3;
              piVar7 = (int *)((int)piVar7 + 1);
              uVar20 = uVar20 + 1;
            } while (bVar2);
          }
          if (bVar3) {
            uVar21 = 0;
            piVar7 = node;
            do {
              if ((((local_a0[3] >> (uVar21 & 0x3f) & 1U) != 0) &&
                  (*(char *)(uVar21 + (int)local_80) != '\x01')) &&
                 (*(char *)(uVar21 + (int)local_7c) == '\x01')) {
                (**(code **)(*node + 0x88))(node,iVar16,uVar21,iVar18);
                *(undefined1 *)(piVar7 + 0x27) = 0;
              }
              bVar3 = uVar21 != 3;
              piVar7 = (int *)((int)piVar7 + 1);
              uVar21 = uVar21 + 1;
            } while (bVar3);
          }
          operandVReg = (int *)IRInst__getOperandSource(piVar8,1);
          iVar11 = (**(code **)(*operandVReg + 0x60))(operandVReg);
          if (iVar11 != 0) {
            uVar13 = IRInst__getOperandSource(piVar8,1);
            FUN_0010c670(uVar13,piVar8,uVar15);
          }
          uVar14 = uVar14 - 1;
          Block__insertInstBefore(node[0x56],node,piVar8);
          IRInst__setOperandSource(node,iVar16,piVar8,0,uVar15);
        } while( true );
      }
    }
  }
  if ((piVar17[0x26] != 0x33) ||
     (iVar6 = IRInst__getOperandSource(node,node[0x21]), *(int *)(iVar6 + 300) == 3)) {
    iVar11 = FUN_001084b8(0x31,*(undefined4 *)(pass + 8));
    iVar6 = *(int *)(pass + 0x478);
    *(undefined4 *)(iVar11 + 0x98) = 0;
    *(int *)(iVar11 + 0x160) = iVar6 + 1;
    *(undefined4 *)(iVar11 + 0x94) = *(undefined4 *)(iVar11 + 0x14c);
    IRInst__setOperandSource(iVar11,1,piVar17,0,*(undefined4 *)(pass + 8));
    uVar15 = IRInst__getOperandSource(node,node[0x21]);
    iVar6 = IRInst__getOperandRecord(uVar15,0);
    *(undefined4 *)(iVar11 + 0x9c) = *(undefined4 *)(iVar6 + 0x10);
    FUN_000f4698(iVar11,1,pass);
    iVar6 = node[0x21];
    *(uint *)(iVar11 + 0x14) = *(uint *)(iVar11 + 0x14) | 0x80000000;
    iVar6 = IRInst__getOperandSource(node,iVar6);
    uVar12 = *(undefined4 *)(iVar6 + 0x158);
    uVar15 = IRInst__getOperandSource(node,node[0x21]);
    Block__insertInstAfter(uVar12,uVar15,iVar11);
    IRInst__setExtraOperandSource(node,iVar11,0,*(undefined4 *)(pass + 8));
    iVar6 = IRInst__getOperandRecord(node,node[0x21]);
    *(undefined4 *)(iVar6 + 0x10) = uVar13;
    return 1;
  }
LAB_0015fd14:
  uVar12 = *(undefined4 *)(pass + 8);
  uVar15 = 0;
  uVar13 = 0;
  IRInst__setOperandSource(node,node[0x21],0,0,uVar12);
  iVar6 = piVar17[0x58];
  node[0x21] = node[0x21] + -1;
  node[5] = node[5] & 0xfffffdff;
  piVar17[0x58] = iVar6 + -1;
  iVar6 = FUN_001049c4(piVar17,pass,uVar15,uVar13,uVar12,in_r8,iVar6 + -1);
  bVar1 = iVar6 != 0;
  if (bVar1) {
    (**(code **)(*piVar17 + 0xc))(piVar17,0,*(undefined4 *)(pass + 8));
  }
  local_a8 = 0;
  local_b0 = 0;
  local_ac = 0;
  IRInst__saveCounters(node,&local_b0,0xffffffff);
  iVar6 = IRInst__clone(node,*(undefined4 *)(pass + 8),0);
  Block__insertInstAfter(*(undefined4 *)(node[1] + 0x158),node[1],iVar6);
  *(int *)(iVar6 + 0x160) = *(int *)(pass + 0x478) + 1;
  *(undefined4 *)(iVar6 + 0x94) = *(undefined4 *)(iVar6 + 0x14c);
  IRMix__ctor_10a1c0(node,0xa2,*(undefined4 *)(pass + 8));
  uVar15 = *(undefined4 *)(iVar6 + 0x158);
  node[0x21] = piVar17[0x21] + 1;
  Block__insertInstAfter(uVar15,iVar6,node);
  iVar11 = IRInst__getOperandRecord(iVar6,0);
  local_b8 = *(int *)(iVar11 + 0x10);
  iVar11 = IRInst__getOperandRecord(piVar17,0);
  iVar16 = 0;
  local_c0 = *(undefined4 *)(iVar11 + 0x10);
  iVar11 = 4;
  do {
    if (*(char *)((int)&local_c0 + iVar16) != '\x01') {
      *(char *)((int)&local_b8 + iVar16) = *(char *)((int)&local_c0 + iVar16);
    }
    iVar16 = iVar16 + 1;
    iVar11 = iVar11 + -1;
  } while (iVar11 != 0);
  iVar11 = IRInst__getOperandSource(piVar17,1);
  if (*(int *)(iVar11 + 0x98) == 0) {
    IRInst__setExtraOperandSource(iVar6,iVar11,0,*(undefined4 *)(pass + 8));
    if (!bVar1) {
      if (*(int *)(pass + 0x478) < *(int *)(iVar11 + 0x160)) {
        *(int *)(iVar11 + 0x160) = *(int *)(iVar11 + 0x160) + 1;
      }
      else {
        *(int *)(iVar11 + 0x160) = *(int *)(pass + 0x478) + 1;
      }
    }
    node[0x21] = node[0x21] + -1;
    IRInst__setOperandSource(node,1,iVar6,0,*(undefined4 *)(pass + 8));
    iVar11 = IRInst__getOperandRecord(node,1);
    iVar16 = 2;
    *(undefined4 *)(iVar11 + 0x10) = 0x10203;
  }
  else {
    IRInst__setOperandSource(node,2,iVar6,0,*(undefined4 *)(pass + 8));
    iVar16 = IRInst__getOperandRecord(node,2);
    *(undefined4 *)(iVar16 + 0x10) = 0x10203;
    IRInst__setOperandSource(node,1,iVar11,0,*(undefined4 *)(pass + 8));
    iVar11 = IRInst__getOperandRecord(piVar17,1);
    uVar15 = *(undefined4 *)(iVar11 + 0x10);
    iVar11 = IRInst__getOperandRecord(node,1);
    iVar16 = 3;
    *(undefined4 *)(iVar11 + 0x10) = uVar15;
  }
  iVar11 = IRInst__getOperandRecord(iVar6,0);
  local_b4 = *(undefined4 *)(iVar11 + 0x10);
  if (1 < piVar17[0x21]) {
    iVar11 = 2;
    do {
      uVar15 = IRInst__getOperandSource(piVar17,iVar11);
      IRInst__setOperandSource(node,iVar16,uVar15,0,*(undefined4 *)(pass + 8));
      if (!bVar1) {
        iVar9 = IRInst__getOperandSource(piVar17,iVar11);
        if (*(int *)(pass + 0x478) < *(int *)(iVar9 + 0x160)) {
          *(int *)(iVar9 + 0x160) = *(int *)(iVar9 + 0x160) + 1;
        }
        else {
          *(int *)(iVar9 + 0x160) = *(int *)(pass + 0x478) + 1;
        }
      }
      iVar9 = IRInst__getOperandRecord(piVar17,iVar11);
      iVar9 = *(int *)(iVar9 + 0x10);
      if (iVar16 == 0) {
        node[0x27] = iVar9;
      }
      else {
        iVar18 = IRInst__getOperandRecord(node,iVar16);
        *(int *)(iVar18 + 0x10) = iVar9;
      }
      iVar18 = IRInst__getOperandRecord(piVar17,iVar11);
      iVar9 = 0;
      local_bc = *(undefined4 *)(iVar18 + 0x10);
      iVar18 = 4;
      do {
        if (*(char *)((int)&local_b4 + iVar9) != '\x04') {
          *(undefined1 *)((int)&local_bc + iVar9) = 4;
        }
        uVar15 = local_bc;
        iVar9 = iVar9 + 1;
        iVar18 = iVar18 + -1;
      } while (iVar18 != 0);
      iVar11 = iVar11 + 1;
      iVar9 = IRInst__getOperandRecord(node,iVar16);
      iVar16 = iVar16 + 1;
      *(undefined4 *)(iVar9 + 0x10) = uVar15;
    } while (iVar11 <= piVar17[0x21]);
  }
  node[0x27] = local_b8;
  node[0x25] = node[0x53];
  node[0x26] = 0x36;
  IRInst__restoreCounters(node,&local_b0);
  node[0x56] = *(int *)(iVar6 + 0x158);
  local_c4 = 0;
  FUN_0014abdc(node,pass,&local_c4);
  ((int (*)())FUN_00160320)(inst,param_2,node,pass,&local_c4);
  return 1;
}

/* FUN_00160320 @ 0x160320 (2960 bytes) */
int FUN_00160320(node, param_2, inst, pass, param_5)
  int *node;
  int param_2;
  int *inst;
  int pass;
  undefined4 *param_5;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  int operandVReg2;
  int iVar5;
  undefined4 uVar6;
  int *operandVReg;
  int *piVar8;
  undefined4 local_64;
  undefined4 local_60;
  uint local_5c;
  undefined4 local_58;
  uint local_54;
  undefined4 local_50;
  undefined4 local_4c;
  uint local_48;
  undefined1 auStack_38 [4];
  undefined1 auStack_34 [4];
  uint local_30;
  uint local_2c;
  uint local_28;
  undefined4 local_24;
  
  iVar2 = (**(code **)(*inst + 0x60))(inst,param_2,inst,pass,param_5);
  if (iVar2 != 0) {
    inst = (int *)IRInst__getOperandSource(inst,1);
  }
  iVar2 = (**(code **)(*inst + 100))(inst);
  if (iVar2 == 0) {
    return 0;
  }
  iVar2 = FUN_00126760(inst[0x26]);
  if (iVar2 == 0) {
    return 0;
  }
  if (((((inst[5] & 0x200U) != 0) && (iVar2 = FUN_000f31e8(inst,1), iVar2 != 0)) &&
      (inst[0x48] == 0)) &&
     (((inst[0x49] == 0 && ((inst[0x2e] & 1U) == 0)) && ((inst[0x2e] & 2U) == 0)))) {
    if (((inst[0x20] != 0) && (iVar2 = FUN_00126760(inst[0x26]), iVar2 != 0)) &&
       (((inst[5] & 2U) == 0 && (iVar2 = (**(code **)(*inst + 0x50))(inst), iVar2 == 0))))
    {
      iVar2 = 4;
      piVar8 = inst;
      do {
        if ((uint)(*(byte *)(piVar8 + 0x27) - 2) < 2) goto LAB_001605dc;
        piVar8 = (int *)((int)piVar8 + 1);
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    if (*(int *)(pass + 0x17c) < *(int *)(*(int *)(pass + 8) + 0x660)) {
      iVar3 = IRInst__getOperandSource(inst,1);
      operandVReg2 = IRInst__getOperandSource(inst,inst[0x21]);
      iVar2 = IRInst__getOperandRecord(inst,0);
      local_60 = *(undefined4 *)(iVar2 + 0x10);
      iVar5 = IRInst__getOperandRecord(operandVReg2,0);
      iVar2 = 0;
      local_64 = *(undefined4 *)(iVar5 + 0x10);
      iVar5 = 4;
      do {
        if ((*(char *)((int)&local_60 + iVar2) != '\x01') &&
           (*(char *)((int)&local_64 + iVar2) != '\x01')) goto LAB_001605dc;
        iVar2 = iVar2 + 1;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
      if (((*(uint *)(operandVReg2 + 0x14) & 0x200) != 0) &&
         (iVar2 = IRInst__getOperandSource(operandVReg2,*(undefined4 *)(operandVReg2 + 0x84)), iVar3 == iVar2)) {
        *(int *)(pass + 0x17c) = *(int *)(pass + 0x17c) + 1;
        iVar2 = (**(code **)(*node + 0x14))(node);
        if ((iVar2 < param_2) &&
           (((node[5] & 0x200U) != 0 &&
            (piVar8 = (int *)IRInst__getOperandSource(node,node[0x21]), inst == piVar8)))) {
          IRInst__setExtraOperandSource(node,operandVReg2,0,*(undefined4 *)(pass + 8));
          iVar3 = *(int *)(pass + 0x478);
          iVar2 = *(int *)(operandVReg2 + 0x160);
          if (iVar3 < iVar2) {
LAB_00160588:
            *(int *)(operandVReg2 + 0x160) = iVar2 + 1;
            goto LAB_00160590;
          }
        }
        else {
          IRInst__setOperandSource(node,param_2,operandVReg2,0,*(undefined4 *)(pass + 8));
          iVar3 = *(int *)(pass + 0x478);
          iVar2 = *(int *)(operandVReg2 + 0x160);
          if (iVar3 < iVar2) goto LAB_00160588;
        }
        *(int *)(operandVReg2 + 0x160) = iVar3 + 1;
LAB_00160590:
        FUN_00105894(inst,*(undefined4 *)(pass + 8));
        *param_5 = 1;
        return 1;
      }
    }
  }
LAB_001605dc:
  iVar2 = (**(code **)(*node + 0x14))(node);
  if (param_2 <= iVar2) {
    iVar2 = (**(code **)(*node + 0x14))(node);
    if (((param_2 <= iVar2) && (inst[0x48] == 0)) && (inst[0x49] == 0)) {
      if (((inst[0x20] != 0) && (iVar2 = FUN_00126760(inst[0x26]), iVar2 != 0)) &&
         (((inst[5] & 2U) == 0 && (iVar2 = (**(code **)(*inst + 0x50))(inst), iVar2 == 0)))
         ) {
        iVar2 = 4;
        piVar8 = inst;
        do {
          if ((uint)(*(byte *)(piVar8 + 0x27) - 2) < 2) {
            return 0;
          }
          piVar8 = (int *)((int)piVar8 + 1);
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
      IRInst__getOperandRecord(inst,0);
      iVar2 = FUN_00105dbc(inst,0);
      if (((iVar2 == 0) && (*(int *)(node[0x22] + 8) != 0x8e)) &&
         (iVar2 = (**(code **)(*node + 0x60))(node), iVar2 == 0)) {
        iVar2 = (**(code **)(*node + 0x28))(node);
        if (iVar2 != 0) {
          piVar8 = (int *)IRInst__getOperandSource(inst,1);
          iVar2 = (**(code **)(*piVar8 + 0x5c))(piVar8);
          if (iVar2 != 0) {
            return 0;
          }
        }
        iVar2 = (**(code **)(*node + 0x28))(node);
        if (iVar2 != 0) {
          iVar2 = IRInst__getOperandSource(inst,1);
          if (iVar2 == 0) {
            iVar2 = inst[0x2c];
          }
          else {
            iVar2 = IRInst__getOperandSource(inst,1);
            iVar2 = *(int *)(iVar2 + 0x98);
          }
          iVar2 = FUN_00126708(iVar2);
          if (iVar2 != 0) {
            return 0;
          }
        }
        if (*(int *)(pass + 0x17c) < *(int *)(*(int *)(pass + 8) + 0x660)) {
          piVar8 = (int *)IRInst__getOperandSource(node,param_2);
          if (inst == piVar8) {
            iVar2 = IRInst__getOperandRecord(piVar8,0);
            FUN_000f3908(&local_30,*(undefined4 *)(iVar2 + 0x10));
            local_5c = local_30;
          }
          else {
            iVar2 = (**(code **)(*piVar8 + 0x60))(piVar8);
            if (iVar2 == 0) {
              return 0;
            }
            operandVReg = (int *)IRInst__getOperandSource(piVar8,1);
            if (inst != operandVReg) {
              return 0;
            }
            iVar2 = IRInst__getOperandRecord(piVar8,0);
            FUN_000f3908(&local_2c,*(undefined4 *)(iVar2 + 0x10));
            local_5c = local_2c;
          }
          iVar2 = IRInst__getOperandRecord(inst,1);
          local_58 = *(undefined4 *)(iVar2 + 0x10);
          if ((inst[5] & 0x200U) == 0) {
            iVar2 = IRInst__getOperandRecord(node,param_2);
            FUN_000f3398(&local_28,*(undefined4 *)(iVar2 + 0x10));
            local_54 = local_28;
            if (((local_5c << 0x18 | (local_5c >> 8 & 0xff) << 0x10 | (local_5c >> 0x10 & 0xff) << 8
                 | local_5c >> 0x18) <
                 (local_28 << 0x18 | (local_28 >> 8 & 0xff) << 0x10 | (local_28 >> 0x10 & 0xff) << 8
                 | local_28 >> 0x18)) && ((node[5] & 2U) != 0)) {
              iVar2 = IRInst__getOperandRecord(inst,0);
              node[0x27] = *(int *)(iVar2 + 0x10);
            }
          }
          else {
            piVar8 = (int *)IRInst__getOperandSource(inst,inst[0x21]);
            operandVReg = (int *)IRInst__getOperandSource(inst,1);
            if (((piVar8 == operandVReg) && ((inst[0x2e] & 2U) == 0)) && ((inst[0x2e] & 1U) == 0))
            {
              iVar2 = 0;
              iVar3 = 4;
              do {
                if (*(char *)((int)&local_5c + iVar2) == '\0') {
                  *(undefined1 *)((int)&local_58 + iVar2) =
                       *(undefined1 *)((int)&DAT_001b004c + iVar2);
                }
                iVar2 = iVar2 + 1;
                iVar3 = iVar3 + -1;
              } while (iVar3 != 0);
            }
            else {
              iVar2 = (**(code **)(*piVar8 + 100))(piVar8);
              if (iVar2 == 0) {
                return 0;
              }
              iVar2 = IRInst__getOperandSource(inst,1);
              iVar3 = IRInst__getOperandSource(piVar8,1);
              if (iVar2 != iVar3) {
                return 0;
              }
              if (((uint)inst[0x2e] >> 1 & 1) != ((uint)piVar8[0x2e] >> 1 & 1)) {
                return 0;
              }
              if ((inst[0x2e] & 1U) != (piVar8[0x2e] & 1U)) {
                return 0;
              }
              if (piVar8[0x48] != 0) {
                return 0;
              }
              if (piVar8[0x49] != 0) {
                return 0;
              }
              iVar2 = IRInst__getOperandRecord(piVar8,0);
              local_54 = *(uint *)(iVar2 + 0x10);
              iVar2 = IRInst__getOperandRecord(piVar8,1);
              local_50 = *(undefined4 *)(iVar2 + 0x10);
              iVar2 = IRInst__getOperandRecord(node,param_2);
              FUN_000f3398(&local_24,*(undefined4 *)(iVar2 + 0x10));
              iVar2 = 0;
              local_4c = local_24;
              iVar3 = 4;
              do {
                if ((*(char *)((int)&local_4c + iVar2) != '\0') &&
                   (*(char *)((int)&local_5c + iVar2) == '\0')) {
                  if (*(char *)((int)&local_54 + iVar2) != '\0') {
                    return 0;
                  }
                  *(undefined1 *)((int)&local_58 + iVar2) = *(undefined1 *)((int)&local_50 + iVar2);
                }
                iVar2 = iVar2 + 1;
                iVar3 = iVar3 + -1;
              } while (iVar3 != 0);
            }
          }
          iVar2 = FUN_00149de4(node,param_2,inst,&local_58,*(undefined4 *)(pass + 8));
          if (iVar2 != 0) goto LAB_00160e58;
        }
      }
    }
    return 0;
  }
  if ((node[5] & 0x200U) == 0) {
    return 0;
  }
  piVar8 = (int *)IRInst__getOperandSource(node,node[0x21]);
  if (inst != piVar8) {
    return 0;
  }
  if ((inst[5] & 0x200U) != 0) {
    return 0;
  }
  if (inst[0x48] != 0) {
    return 0;
  }
  if (inst[0x49] != 0) {
    return 0;
  }
  if ((inst[0x2e] & 1U) != 0) {
    return 0;
  }
  if ((inst[0x2e] & 2U) != 0) {
    return 0;
  }
  if (((inst[0x20] != 0) && (iVar2 = FUN_00126760(inst[0x26]), iVar2 != 0)) &&
     (((inst[5] & 2U) == 0 && (iVar2 = (**(code **)(*inst + 0x50))(inst), iVar2 == 0)))) {
    iVar2 = 4;
    piVar8 = inst;
    do {
      if ((uint)(*(byte *)(piVar8 + 0x27) - 2) < 2) {
        return 0;
      }
      piVar8 = (int *)((int)piVar8 + 1);
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  IRInst__getOperandRecord(inst,0);
  iVar2 = FUN_00105dbc(inst,0);
  if (iVar2 != 0) {
    return 0;
  }
  piVar8 = (int *)IRInst__getOperandSource(inst,1);
  if (piVar8[0x20] == 0) {
    return 0;
  }
  iVar2 = FUN_00126760(piVar8[0x26]);
  if (iVar2 == 0) {
    return 0;
  }
  if ((piVar8[5] & 2U) != 0) {
    return 0;
  }
  iVar2 = (**(code **)(*piVar8 + 0x50))(piVar8);
  if (iVar2 != 0) {
    return 0;
  }
  iVar2 = FUN_000f31e8(inst,1);
  if (iVar2 == 0) {
    return 0;
  }
  piVar8 = (int *)IRInst__getOperandSource(inst,1);
  iVar2 = (**(code **)(*piVar8 + 0x5c))(piVar8);
  if (iVar2 != 0) {
    return 0;
  }
  if (*(int *)(*(int *)(pass + 8) + 0x660) <= *(int *)(pass + 0x17c)) {
    return 0;
  }
  iVar2 = IRInst__getOperandRecord(inst,0);
  FUN_000f3908(auStack_38,*(undefined4 *)(iVar2 + 0x10));
  iVar2 = IRInst__getOperandRecord(node,0);
  FUN_000f3968(auStack_34,*(undefined4 *)(iVar2 + 0x10),0x1010101);
  *(int *)(pass + 0x17c) = *(int *)(pass + 0x17c) + 1;
  iVar2 = IRInst__hasSingleUse(inst,pass);
  if (iVar2 == 0) {
    uVar6 = IRInst__getOperandSource(inst,1);
    IRInst__setExtraOperandSource(node,uVar6,0,*(undefined4 *)(pass + 8));
    inst[0x58] = inst[0x58] + -1;
    iVar2 = IRInst__getOperandSource(inst,1);
    if (*(int *)(pass + 0x478) < *(int *)(iVar2 + 0x160)) {
      *(int *)(iVar2 + 0x160) = *(int *)(iVar2 + 0x160) + 1;
    }
    else {
      *(int *)(iVar2 + 0x160) = *(int *)(pass + 0x478) + 1;
    }
    goto LAB_00160e58;
  }
  iVar2 = (**(code **)(*node + 100))(node);
  if (iVar2 == 0) {
LAB_0016086c:
    uVar6 = IRInst__getOperandSource(inst,1);
    IRInst__setExtraOperandSource(node,uVar6,0,*(undefined4 *)(pass + 8));
  }
  else {
    iVar2 = IRInst__getOperandSource(node,1);
    iVar3 = IRInst__getOperandSource(inst,1);
    if (((iVar2 != iVar3) || (node[0x48] != inst[0x48])) || (node[0x49] != inst[0x49]))
    goto LAB_0016086c;
    if (((node[0x2e] & 1U) != (inst[0x2e] & 1U)) ||
       (((uint)node[0x2e] >> 1 & 1) != ((uint)inst[0x2e] >> 1 & 1))) goto LAB_0016086c;
    iVar2 = IRInst__getOperandRecord(inst,0);
    uVar1 = *(uint *)(iVar2 + 0x10);
    iVar2 = IRInst__getOperandRecord(node,0);
    local_48 = *(uint *)(iVar2 + 0x10);
    uVar1 = (uVar1 << 0x18 | (uVar1 >> 8 & 0xff) << 0x10 | (uVar1 >> 0x10 & 0xff) << 8 |
            uVar1 >> 0x18) &
            (local_48 << 0x18 | (local_48 >> 8 & 0xff) << 0x10 | (local_48 >> 0x10 & 0xff) << 8 |
            local_48 >> 0x18);
    local_54 = uVar1 << 0x18 | (uVar1 & 0xff00) << 8 | uVar1 >> 8 & 0xff00 | uVar1 >> 0x18;
    node[0x27] = local_54;
    iVar2 = IRInst__getOperandRecord(node,1);
    local_58 = *(undefined4 *)(iVar2 + 0x10);
    iVar3 = IRInst__getOperandRecord(inst,1);
    iVar2 = 0;
    local_5c = *(uint *)(iVar3 + 0x10);
    iVar3 = 4;
    do {
      if (*(char *)((int)&local_58 + iVar2) == '\x04') {
        *(undefined1 *)((int)&local_58 + iVar2) = *(undefined1 *)((int)&local_5c + iVar2);
      }
      uVar6 = local_58;
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    iVar2 = IRInst__getOperandRecord(node,1);
    *(undefined4 *)(iVar2 + 0x10) = uVar6;
    IRInst__setOperandSource(node,node[0x21],0,0,*(undefined4 *)(pass + 8));
    node[0x21] = node[0x21] + -1;
    node[5] = node[5] & 0xfffffdff;
    iVar2 = IRInst__getOperandSource(node,1);
    *(int *)(iVar2 + 0x160) = *(int *)(iVar2 + 0x160) + -1;
  }
  (**(code **)(*inst + 0xc))(inst,0,*(undefined4 *)(pass + 8));
LAB_00160e58:
  *param_5 = 1;
  return 1;
}

/* FUN_00160eb0 @ 0x160eb0 (2064 bytes) */
int FUN_00160eb0(param_1, param_2, inst, param_4)
  undefined4 param_1;
  undefined4 param_2;
  int inst;
  int param_4;
{
  int loopIndex;
  bool bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int *piVar12;
  int *piVar13;
  int *piVar14;
  int iVar15;
  undefined4 local_98;
  int *local_94;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  undefined1 local_74 [3];
  undefined1 uStack_71;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  int *local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  int local_48;
  int local_44;
  
  iVar4 = Compiler__isOptionEnabled(*(undefined4 *)(param_4 + 8),0x1e);
  if ((iVar4 != 0) && ((*(uint *)(inst + 0x14) & 0x400000) == 0)) {
    local_78 = 0;
    local_6c = 4;
    local_94 = (int *)0x0;
    local_90 = 0;
    local_88 = 0;
    local_84 = 0;
    local_80 = 0;
    local_7c = 0;
    local_70 = 4;
    iVar4 = ((int (*)())FUN_0015b974)(inst,&local_64,&local_8c,&local_80,local_74);
    if ((iVar4 != 0) && ((-1 < local_80 && (local_80 < 3)))) {
      iVar4 = IRInst__getOperandRecord(inst,0);
      iVar4 = *(int *)(iVar4 + 0x10);
      iVar5 = IRInst__getOperandRecord(inst,0);
      piVar14 = (int *)0x0;
      iVar5 = FUN_000f37b8(*(undefined4 *)(iVar5 + 0x10));
      if ((*(uint *)(inst + 0x14) & 0x200) != 0) {
        piVar14 = (int *)IRInst__getOperandSource(inst,*(undefined4 *)(inst + 0x84));
      }
      bVar1 = piVar14 == (int *)0x0;
      iVar11 = *(int *)(inst + 0x120);
      if (bVar1) {
        piVar13 = (int *)0x0;
        piVar12 = (int *)0x0;
        local_78 = local_80;
        iVar6 = -1;
        local_7c = local_80;
        iVar8 = -1;
      }
      else {
        iVar6 = IRInst__hasSingleUse(piVar14,param_4);
        if (((((iVar6 == 0) ||
              (iVar6 = ((int (*)())FUN_0015b974)(piVar14,&local_94,&local_88,&local_7c,&local_70), iVar6 == 0))
             || (local_8c != local_88)) ||
            ((iVar6 = FUN_0014700c(local_64,local_94), iVar6 == 0 || (local_80 != local_7c)))) ||
           (iVar11 != piVar14[0x48])) {
          bVar1 = true;
          piVar13 = (int *)0x0;
          iVar6 = -1;
          iVar8 = -1;
          local_94 = (int *)0x0;
          piVar12 = piVar14;
          piVar14 = (int *)0x0;
          local_7c = local_80;
          local_78 = local_80;
        }
        else {
          iVar6 = IRInst__getOperandRecord(piVar14,0);
          FUN_000f2f84(&local_48,iVar4,*(undefined4 *)(iVar6 + 0x10));
          iVar4 = IRInst__getOperandRecord(piVar14,0);
          iVar6 = FUN_000f37b8(*(undefined4 *)(iVar4 + 0x10));
          iVar4 = local_48;
          if (((piVar14[5] & 0x200U) == 0) ||
             (piVar7 = (int *)IRInst__getOperandSource(piVar14,piVar14[0x21]), piVar7 == (int *)0x0)) {
            piVar13 = (int *)0x0;
            iVar8 = -1;
            local_78 = local_80;
            piVar12 = (int *)0x0;
          }
          else {
            iVar8 = IRInst__hasSingleUse(piVar7,param_4);
            if ((((iVar8 == 0) ||
                 (iVar8 = ((int (*)())FUN_0015b974)(piVar7,&local_90,&local_84,&local_78,&local_6c), iVar8 == 0))
                || (local_88 != local_84)) ||
               (((iVar8 = FUN_0014700c(local_94,local_90), iVar8 == 0 || (local_80 != local_78)) ||
                (iVar11 != piVar7[0x48])))) {
              piVar13 = (int *)0x0;
              iVar8 = -1;
              local_90 = 0;
              piVar12 = piVar7;
              local_78 = local_80;
            }
            else {
              iVar4 = IRInst__getOperandRecord(piVar7,0);
              FUN_000f2f84(&local_44,local_48,*(undefined4 *)(iVar4 + 0x10));
              iVar4 = IRInst__getOperandRecord(piVar7,0);
              iVar8 = FUN_000f37b8(*(undefined4 *)(iVar4 + 0x10));
              iVar4 = local_44;
              piVar12 = (int *)0x0;
              piVar13 = piVar7;
            }
          }
        }
      }
      if (local_8c == 0) {
        iVar9 = (**(code **)(*local_64 + 0x5c))(local_64);
        if (iVar9 != 0) {
          local_64[0x27] = iVar4;
          loopIndex = 1;
          while( true ) {
            iVar10 = (**(code **)(*local_64 + 0x14))(local_64);
            if (iVar10 < loopIndex) break;
            iVar10 = IRInst__getOperandRecord(local_64,loopIndex);
            *(undefined4 *)(iVar10 + 0x10) = 0x10203;
            (**(code **)(*local_64 + 0x88))(local_64,loopIndex,3,4);
            loopIndex = loopIndex + 1;
          }
        }
        FUN_00147704(inst,piVar14,piVar13,param_4);
        if (bVar1) {
          iVar9 = 0;
        }
        else {
          iVar9 = 1;
          (**(code **)(*piVar14 + 0xc))(piVar14,0,*(undefined4 *)(param_4 + 8));
          if (piVar13 != (int *)0x0) {
            iVar9 = 2;
            (**(code **)(*piVar13 + 0xc))(piVar13,0,*(undefined4 *)(param_4 + 8));
          }
        }
        if (local_80 == 2) {
          iVar9 = iVar9 + -1;
        }
        iVar10 = (**(code **)(*local_64 + 0x5c))(local_64);
        if (iVar10 == 0) {
          if (local_94 == (int *)0x0) {
            local_94 = local_64;
          }
          if (iVar9 < 0) {
            if (*(int *)(param_4 + 0x478) < local_64[0x58]) {
              local_64[0x58] = local_64[0x58] + 1;
            }
            else {
              local_64[0x58] = *(int *)(param_4 + 0x478) + 1;
            }
          }
          else if (0 < iVar9) {
            do {
              local_64[0x58] = local_64[0x58] + -1;
              iVar9 = iVar9 + -1;
            } while (iVar9 != 0);
          }
        }
        else if (local_94 == (int *)0x0) {
          if (iVar9 < 0) {
            iVar10 = *(int *)(param_4 + 0x478);
            local_94 = (int *)IRInst__clone(local_64,*(undefined4 *)(param_4 + 8),0);
            iVar15 = iVar10 + 1;
            local_94[0x26] = 0x31;
            local_94[0x25] = local_94[0x53];
            Block__insertInstAfter(local_64[0x56],local_64,local_94);
            local_94[0x58] = iVar15;
            iVar9 = IRInst__getOperandSource(local_94,1);
            if (iVar10 < *(int *)(iVar9 + 0x160)) {
              *(int *)(iVar9 + 0x160) = *(int *)(iVar9 + 0x160) + 1;
            }
            else {
              *(int *)(iVar9 + 0x160) = iVar15;
            }
            if (1 < local_94[0x21]) {
              iVar9 = IRInst__getOperandSource(local_94,2);
              if (iVar10 < *(int *)(iVar9 + 0x160)) {
                *(int *)(iVar9 + 0x160) = *(int *)(iVar9 + 0x160) + 1;
              }
              else {
                *(int *)(iVar9 + 0x160) = iVar15;
              }
            }
          }
        }
        else if ((0 < iVar9) &&
                ((local_90 == 0 ||
                 (FUN_00105894(local_90,*(undefined4 *)(param_4 + 8)), 0 < iVar9 + -1)))) {
          FUN_00105894(local_94,*(undefined4 *)(param_4 + 8));
        }
        local_68 = 0x4040404;
        *(undefined1 *)((int)&local_68 + iVar5) = uStack_71;
        if (-1 < iVar6) {
          *(char *)((int)&local_68 + iVar6) = (char)local_70;
        }
        if (-1 < iVar8) {
          *(char *)((int)&local_68 + iVar8) = (char)local_6c;
        }
        local_60 = 0;
        local_5c = 0;
        local_58 = 0;
        iVar5 = *(int *)(inst + 4);
        IRInst__saveCounters(inst,&local_60,0xffffffff);
        DList__unlink(inst);
        local_98 = 0;
        if (local_80 == 0) {
          FUN_00108448(inst,0x31,*(undefined4 *)(param_4 + 8));
          *(int *)(inst + 0x9c) = iVar4;
          Block__insertInstAfter(*(undefined4 *)(iVar5 + 0x158),iVar5,inst);
          ((void (*)())FUN_000f79c4)(inst,param_4,1,1.0,1.0,1.0,1.0);
          IRInst__restoreCounters(inst,&local_60);
          if (piVar12 != (int *)0x0) {
            IRInst__setExtraOperandSource(inst,piVar12,0,*(undefined4 *)(param_4 + 8));
          }
        }
        else {
          if (local_80 != 1) {
            FUN_00108174(inst,0x13,*(undefined4 *)(param_4 + 8));
            *(int *)(inst + 0x9c) = iVar4;
            IRInst__restoreCounters(inst,&local_60);
            Block__insertInstAfter(*(undefined4 *)(iVar5 + 0x158),iVar5,inst);
            IRInst__setOperandSource(inst,1,local_64,0,*(undefined4 *)(param_4 + 8));
            IRInst__setOperandSource(inst,2,local_94,0,*(undefined4 *)(param_4 + 8));
            uVar2 = local_68;
            iVar4 = IRInst__getOperandRecord(inst,1);
            uVar3 = local_68;
            *(undefined4 *)(iVar4 + 0x10) = uVar2;
            iVar4 = IRInst__getOperandRecord(inst,2);
            *(undefined4 *)(iVar4 + 0x10) = uVar3;
            if (piVar12 != (int *)0x0) {
              IRInst__setExtraOperandSource(inst,piVar12,0,*(undefined4 *)(param_4 + 8));
            }
            *(undefined4 *)(inst + 0x98) = 0;
            *(int *)(inst + 0x120) = iVar11;
            *(undefined4 *)(inst + 0x94) = *(undefined4 *)(inst + 0x14c);
            return 1;
          }
          FUN_00108448(inst,0x31,*(undefined4 *)(param_4 + 8));
          IRInst__restoreCounters(inst,&local_60);
          *(int *)(inst + 0x9c) = iVar4;
          Block__insertInstAfter(*(undefined4 *)(iVar5 + 0x158),iVar5,inst);
          IRInst__setOperandSource(inst,1,local_64,0,*(undefined4 *)(param_4 + 8));
          uVar2 = local_68;
          iVar4 = IRInst__getOperandRecord(inst,1);
          *(undefined4 *)(iVar4 + 0x10) = uVar2;
          IROperand__setModifierBits(inst + 0xa4,2,1);
          *(undefined4 *)(inst + 0x98) = 0;
          *(undefined4 *)(inst + 0x94) = *(undefined4 *)(inst + 0x14c);
          if (piVar12 != (int *)0x0) {
            IRInst__setExtraOperandSource(inst,piVar12,0,*(undefined4 *)(param_4 + 8));
          }
          *(int *)(inst + 0x120) = iVar11;
        }
        ((int (*)())FUN_00160320)(param_1,param_2,inst,param_4,&local_98);
        return 1;
      }
      if (!bVar1) {
        FUN_000da09c(*(undefined4 *)(*(int *)(param_4 + 8) + 0x398),*(uint *)(param_4 + 0x30) & 1);
      }
      return 1;
    }
  }
  return 0;
}

/* FUN_00161748 @ 0x161748 (2688 bytes) */
int FUN_00161748(inst, inst2, pass)
  int *inst;
  int *inst2;
  int pass;
{
  bool bVar1;
  bool bVar2;
  undefined1 uVar3;
  bool bVar4;
  code *pcVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  int *piVar12;
  int iVar13;
  int *operandVReg;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 in_r9;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  int local_78 [6];
  undefined4 local_60;
  int local_58 [5];
  
  iVar7 = (**(code **)(*inst + 100))(inst,inst2,pass);
  if ((iVar7 != 0) && (iVar7 = (**(code **)(*inst2 + 100))(inst2), iVar7 != 0)) {
    uVar8 = IRInst__getOperandSource(inst,1);
    uVar9 = IRInst__getOperandSource(inst2,1);
    iVar7 = FUN_00146de0(uVar8,uVar9);
    if (iVar7 == 0) {
      iVar7 = IRInst__getOperandSource(inst,1);
      iVar10 = IRInst__getOperandSource(inst2,1);
      if (iVar7 != iVar10) {
        uVar8 = IRInst__getOperandSource(inst,1);
        uVar9 = *(undefined4 *)(pass + 8);
        iVar7 = IRInst__getOperandRecord(inst,1);
        iVar7 = FUN_0010453c(uVar8,uVar9,*(undefined4 *)(iVar7 + 0x10),in_r6,in_r7,in_r8,in_r9);
        uVar8 = IRInst__getOperandSource(inst2,1);
        uVar9 = *(undefined4 *)(pass + 8);
        bVar1 = iVar7 == 0;
        iVar7 = IRInst__getOperandRecord(inst2,1);
        iVar7 = FUN_0010453c(uVar8,uVar9,*(undefined4 *)(iVar7 + 0x10),in_r6,in_r7,in_r8,in_r9);
        if ((!bVar1) || (iVar7 != 0)) {
          if (((inst[0x2e] & 1U) != (inst2[0x2e] & 1U)) &&
             ((iVar7 == 0 || (iVar10 = FUN_00151318(inst2), iVar10 == 0)))) {
            if (bVar1) {
              return 0;
            }
            iVar10 = FUN_00151318(inst);
            if (iVar10 == 0) {
              return 0;
            }
            if ((((uint)inst[0x2e] >> 1 & 1) != ((uint)inst2[0x2e] >> 1 & 1)) &&
               ((((inst[0x2e] & 2U) == 0 || (iVar7 == 0)) && ((inst2[0x2e] & 2U) == 0)))) {
              return 0;
            }
          }
          if ((((inst2[0x48] == inst[0x48]) || ((inst2[0x48] != 0 && (iVar7 != 0)))) ||
              ((inst[0x48] != 0 && (!bVar1)))) &&
             (((inst[0x49] == inst2[0x49] ||
               ((iVar7 != 0 && (iVar10 = FUN_00151318(inst2), iVar10 != 0)))) ||
              ((!bVar1 && (iVar10 = FUN_00151318(inst), iVar10 != 0)))))) {
            iVar10 = IRInst__getOperandRecord(inst,0);
            local_88 = *(undefined4 *)(iVar10 + 0x10);
            iVar11 = IRInst__getOperandRecord(inst2,0);
            iVar10 = 0;
            local_84 = *(undefined4 *)(iVar11 + 0x10);
            iVar11 = 4;
            do {
              if ((*(char *)((int)&local_88 + iVar10) != '\x01') &&
                 (*(char *)((int)&local_84 + iVar10) != '\x01')) {
                return 0;
              }
              iVar10 = iVar10 + 1;
              iVar11 = iVar11 + -1;
            } while (iVar11 != 0);
            iVar10 = Compiler__isOptionEnabled(*(undefined4 *)(pass + 8),0x30);
            if ((iVar10 == 0) || (((char)local_88 != '\0' && ((char)local_84 != '\0')))) {
              iVar10 = inst2[0x49];
              if ((inst[0x49] != iVar10) && (iVar7 != 0)) {
                iVar10 = FUN_00151318(inst2);
                if (iVar10 == 0) {
                  iVar10 = inst2[0x49];
                }
                else {
                  iVar10 = inst[0x49];
                }
              }
              bVar4 = iVar7 == 0;
              iVar7 = inst2[0x48];
              if ((inst[0x48] != iVar7) && (!bVar4)) {
                iVar7 = FUN_00151318(inst2);
                if (iVar7 == 0) {
                  iVar7 = inst2[0x48];
                }
                else {
                  iVar7 = inst[0x48];
                }
              }
              uVar17 = inst[0x2e];
              uVar15 = inst2[0x2e];
              uVar16 = uVar17 & 1;
              if (uVar16 != (uVar15 & 1)) {
                if ((bVar4) || (iVar11 = FUN_00151318(inst2), iVar11 == 0)) {
                  if ((bVar1) || (iVar11 = FUN_00151318(inst), iVar11 == 0)) {
                    uVar17 = inst[0x2e];
                    uVar16 = 0;
                    uVar15 = inst2[0x2e];
                  }
                  else {
                    uVar15 = inst2[0x2e];
                    uVar17 = inst[0x2e];
                    uVar16 = uVar15 & 1;
                  }
                }
                else {
                  uVar17 = inst[0x2e];
                  uVar15 = inst2[0x2e];
                  uVar16 = uVar17 & 1;
                }
              }
              uVar6 = uVar15 >> 1 & 1;
              uVar17 = uVar17 >> 1 & 1;
              uVar15 = uVar6;
              if (((uVar17 != uVar6) && (uVar15 = uVar17, bVar4)) && (uVar15 = uVar6, bVar1)) {
                uVar15 = 0;
              }
              iVar11 = IRInst__getOperandRecord(inst,1);
              local_80 = *(undefined4 *)(iVar11 + 0x10);
              iVar11 = IRInst__getOperandRecord(inst2,1);
              local_7c = *(undefined4 *)(iVar11 + 0x10);
              FUN_000f2f84(local_58,local_84,local_88);
              local_78[0] = local_58[0];
              piVar12 = (int *)FUN_0010a240(0xa2,*(undefined4 *)(pass + 8));
              piVar12[0x26] = 0x36;
              piVar12[0x25] = piVar12[0x53];
              piVar12[0x21] = 2;
              if (bVar4) {
                uVar8 = IRInst__getOperandSource(inst2,1);
              }
              else {
                uVar8 = IRInst__getOperandSource(inst,1);
              }
              IRInst__setOperandSource(piVar12,1,uVar8,0,*(undefined4 *)(pass + 8));
              iVar11 = IRInst__getOperandSource(piVar12,1);
              if (*(int *)(pass + 0x478) < *(int *)(iVar11 + 0x160)) {
                *(int *)(iVar11 + 0x160) = *(int *)(iVar11 + 0x160) + 1;
              }
              else {
                *(int *)(iVar11 + 0x160) = *(int *)(pass + 0x478) + 1;
              }
              if (bVar4) {
                uVar8 = IRInst__getOperandSource(inst,1);
              }
              else {
                uVar8 = IRInst__getOperandSource(inst2,1);
              }
              IRInst__setOperandSource(piVar12,2,uVar8,0,*(undefined4 *)(pass + 8));
              iVar11 = IRInst__getOperandSource(piVar12,2);
              if (*(int *)(pass + 0x478) < *(int *)(iVar11 + 0x160)) {
                *(int *)(iVar11 + 0x160) = *(int *)(iVar11 + 0x160) + 1;
              }
              else {
                *(int *)(iVar11 + 0x160) = *(int *)(pass + 0x478) + 1;
              }
              iVar11 = IRInst__getOperandSource(inst,1);
              *(int *)(iVar11 + 0x160) = *(int *)(iVar11 + 0x160) + -1;
              IRInst__setOperandSource(inst,1,piVar12,0,*(undefined4 *)(pass + 8));
              piVar12[0x58] = *(int *)(pass + 0x478) + 1;
              piVar12[0x27] = 0x1010101;
              iVar11 = IRInst__getOperandRecord(piVar12,1);
              *(undefined4 *)(iVar11 + 0x10) = 0x4040404;
              iVar11 = IRInst__getOperandRecord(piVar12,2);
              *(undefined4 *)(iVar11 + 0x10) = 0x10203;
              iVar11 = IRInst__getOperandRecord(inst,1);
              *(undefined4 *)(iVar11 + 0x10) = 0x4040404;
              if (bVar4) {
                uVar9 = 1;
                uVar8 = 2;
              }
              else {
                uVar9 = 2;
                uVar8 = 1;
              }
              uVar17 = 0;
              iVar11 = 0;
              do {
                iVar13 = IRInst__getOperandRecord(inst,0);
                if ((*(char *)(iVar11 + iVar13 + 0x10) != '\0') || ((!bVar1 && (bVar4)))) {
                  iVar13 = IRInst__getOperandRecord(inst2,0);
                  if ((*(char *)(iVar11 + iVar13 + 0x10) == '\0') && (bVar4)) {
                    uVar6 = (uint)*(byte *)((int)&local_7c + iVar11);
                    (**(code **)(*piVar12 + 0x88))(piVar12,uVar9,uVar6,uVar6);
                    (**(code **)(*piVar12 + 0x88))(piVar12,uVar8,uVar6,4);
                    *(undefined1 *)((int)piVar12 + uVar6 + 0x9c) = 0;
                    pcVar5 = *(code **)(*inst + 0x88);
                    goto LAB_00161e24;
                  }
                  (**(code **)(*piVar12 + 0x88))(piVar12,2,iVar11,4);
                }
                else {
                  IRInst__getOperandRecord(inst2,0);
                  uVar6 = (uint)*(byte *)((int)&local_80 + iVar11);
                  (**(code **)(*piVar12 + 0x88))(piVar12,uVar8,uVar6,uVar6);
                  *(undefined1 *)((int)piVar12 + uVar6 + 0x9c) = 0;
                  (**(code **)(*piVar12 + 0x88))(piVar12,uVar9,uVar6,4);
                  pcVar5 = *(code **)(*inst + 0x88);
LAB_00161e24:
                  uVar17 = uVar17 | 1 << (uVar6 & 0x3f);
                  (*pcVar5)(inst,1,iVar11,uVar6);
                }
                bVar2 = iVar11 == 3;
                iVar11 = iVar11 + 1;
                if (bVar2) {
                  iVar11 = 0;
                  do {
                    if ((*(char *)((int)local_78 + iVar11) == '\0') &&
                       (iVar13 = IRInst__getOperandRecord(inst,1),
                       *(char *)(iVar11 + iVar13 + 0x10) == '\x04')) {
                      if ((uVar17 & 1) == 0) {
                        iVar13 = 0;
                        uVar6 = 1;
                      }
                      else if ((uVar17 & 2) == 0) {
                        iVar13 = 1;
                        uVar6 = 2;
                      }
                      else if ((uVar17 & 4) == 0) {
                        iVar13 = 2;
                        uVar6 = 4;
                      }
                      else {
                        iVar13 = 3;
                        uVar6 = 0;
                      }
                      uVar17 = uVar17 ^ uVar6;
                      (**(code **)(*inst + 0x88))(inst,1,iVar11,iVar13);
                      if (bVar4) {
                        uVar3 = *(undefined1 *)((int)&local_80 + iVar11);
                      }
                      else {
                        uVar3 = *(undefined1 *)((int)&local_7c + iVar11);
                      }
                      (**(code **)(*piVar12 + 0x88))(piVar12,2,iVar13,uVar3);
                      *(undefined1 *)((int)piVar12 + iVar13 + 0x9c) = 0;
                    }
                    bVar1 = iVar11 != 3;
                    iVar11 = iVar11 + 1;
                  } while (bVar1);
                  Block__insertInstBefore(inst[0x56],inst,piVar12);
                  inst[0x27] = local_78[0];
                  IROperand__setModifierBits(inst + 0x29,1,uVar16);
                  IROperand__setModifierBits(inst + 0x29,2,uVar15);
                  inst[0x49] = iVar10;
                  inst[0x48] = iVar7;
                  IRInst__setOperandSource(inst,inst[0x21],0,0,*(undefined4 *)(pass + 8));
                  inst[5] = inst[5] & 0xfffffdff;
                  uVar16 = inst2[5];
                  inst[0x21] = inst[0x21] + -1;
                  if ((uVar16 & 0x200) != 0) {
                    iVar7 = IRInst__getOperandSource(inst2,inst2[0x21]);
                    local_60 = 0;
                    local_78[1] = 0;
                    local_78[2] = 0;
                    FUN_00104d3c(inst2,local_78 + 1);
                    FUN_00106b48(inst,local_78 + 1,0,*(undefined4 *)(pass + 8));
                    if (*(int *)(pass + 0x478) < *(int *)(iVar7 + 0x160)) {
                      *(int *)(iVar7 + 0x160) = *(int *)(iVar7 + 0x160) + 1;
                    }
                    else {
                      *(int *)(iVar7 + 0x160) = *(int *)(pass + 0x478) + 1;
                    }
                  }
                  operandVReg = (int *)IRInst__getOperandSource(piVar12,1);
                  iVar7 = (**(code **)(*operandVReg + 0x60))(operandVReg);
                  if (iVar7 != 0) {
                    uVar8 = IRInst__getOperandSource(piVar12,1);
                    FUN_0010c670(uVar8,piVar12,*(undefined4 *)(pass + 8));
                  }
                  FUN_00105894(inst2,*(undefined4 *)(pass + 8));
                  if ((inst2[5] & 1U) != 0) {
                    operandVReg = (int *)IRInst__getOperandSource(piVar12,1);
                    iVar7 = (**(code **)(*operandVReg + 0x5c))(operandVReg);
                    if (iVar7 != 0) {
                      uVar8 = IRInst__getOperandSource(piVar12,1);
                      iVar7 = IRInst__clone(uVar8,*(undefined4 *)(pass + 8),0);
                      iVar11 = *(int *)(pass + 0x478);
                      *(undefined4 *)(iVar7 + 0x94) = *(undefined4 *)(iVar7 + 0x14c);
                      *(undefined4 *)(iVar7 + 0x98) = 0x31;
                      iVar10 = IRInst__getOperandSource(piVar12,1);
                      uVar9 = *(undefined4 *)(iVar10 + 0x158);
                      uVar8 = IRInst__getOperandSource(piVar12,1);
                      iVar13 = iVar11 + 1;
                      Block__insertInstAfter(uVar9,uVar8,iVar7);
                      *(int *)(iVar7 + 0x160) = iVar13;
                      iVar10 = IRInst__getOperandSource(piVar12,1);
                      *(int *)(iVar10 + 0x160) = *(int *)(iVar10 + 0x160) + -1;
                      iVar10 = IRInst__getOperandSource(iVar7,1);
                      if (iVar11 < *(int *)(iVar10 + 0x160)) {
                        *(int *)(iVar10 + 0x160) = *(int *)(iVar10 + 0x160) + 1;
                      }
                      else {
                        *(int *)(iVar10 + 0x160) = iVar13;
                      }
                      if (1 < *(int *)(iVar7 + 0x84)) {
                        iVar10 = IRInst__getOperandSource(iVar7,2);
                        if (iVar11 < *(int *)(iVar10 + 0x160)) {
                          *(int *)(iVar10 + 0x160) = *(int *)(iVar10 + 0x160) + 1;
                        }
                        else {
                          *(int *)(iVar10 + 0x160) = iVar13;
                        }
                      }
                      IRInst__setOperandSource(piVar12,1,iVar7,0,*(undefined4 *)(pass + 8));
                      return 1;
                    }
                  }
                  return 1;
                }
              } while( true );
            }
          }
        }
      }
    }
  }
  return 0;
}

/* FUN_001621c8 @ 0x1621c8 (2404 bytes) */
int FUN_001621c8(inst, inst2, pass)
  int *inst;
  int *inst2;
  int pass;
{
  bool bVar1;
  bool bVar2;
  undefined1 uVar3;
  float *pfVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  undefined4 uVar10;
  int iVar11;
  float *pfVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  int *piVar17;
  int *inst3;
  int iVar19;
  int iVar20;
  double dVar21;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  int local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  float local_b8 [4];
  float local_a8 [4];
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_84;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 *local_68;
  
  iVar6 = (**(code **)(*inst + 100))(inst,inst2,pass);
  if (iVar6 == 0) {
    return 0;
  }
  iVar6 = (**(code **)(*inst2 + 100))(inst2);
  if (iVar6 == 0) {
    return 0;
  }
  iVar6 = IRInst__getOperandSource(inst2,1);
  if (iVar6 == 0) {
    iVar6 = inst2[0x2c];
  }
  else {
    iVar6 = IRInst__getOperandSource(inst2,1);
    iVar6 = *(int *)(iVar6 + 0x98);
  }
  iVar6 = FUN_00126708(iVar6);
  if (iVar6 == 0) {
    return 0;
  }
  iVar6 = IRInst__getOperandRecord(inst,0);
  local_d8 = *(int *)(iVar6 + 0x10);
  iVar7 = IRInst__getOperandRecord(inst2,0);
  iVar6 = 0;
  local_d4 = *(undefined4 *)(iVar7 + 0x10);
  iVar7 = 4;
  do {
    if ((*(char *)((int)&local_d8 + iVar6) != '\x01') &&
       (*(char *)((int)&local_d4 + iVar6) != '\x01')) {
      return 0;
    }
    iVar6 = iVar6 + 1;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  iVar6 = Compiler__isOptionEnabled(*(undefined4 *)(pass + 8),0x30);
  if (iVar6 != 0) {
    if ((char)local_d8 == '\0') {
      return 0;
    }
    if ((char)local_d4 == '\0') {
      return 0;
    }
  }
  if (inst2[0x48] != 0) {
    return 0;
  }
  iVar16 = inst[0x49];
  iVar6 = inst2[0x49];
  iVar7 = IRInst__getOperandSource(inst,1);
  iVar8 = IRInst__getOperandSource(inst2,1);
  if (iVar7 == iVar8) {
    uVar13 = inst[0x2e];
    if (((inst2[0x2e] & 1U) == (uVar13 & 1)) &&
       (((uint)inst2[0x2e] >> 1 & 1) == (uVar13 >> 1 & 1))) {
      iVar7 = FUN_00105c5c(inst2,1);
      iVar8 = FUN_00105c5c(inst,1);
      if ((iVar7 == iVar8) && (iVar16 == iVar6)) {
        iVar6 = IRInst__getOperandRecord(inst,1);
        local_d0 = *(undefined4 *)(iVar6 + 0x10);
        iVar6 = IRInst__getOperandRecord(inst2,1);
        local_cc = *(undefined4 *)(iVar6 + 0x10);
        local_c8 = 0x4040404;
        iVar6 = 0;
        iVar7 = 4;
        do {
          if (*(char *)((int)&local_d8 + iVar6) == '\0') {
            *(undefined1 *)((int)&local_c8 + iVar6) = *(undefined1 *)((int)&local_d0 + iVar6);
          }
          else if (*(char *)((int)&local_d4 + iVar6) == '\0') {
            *(undefined1 *)((int)&local_c8 + iVar6) = *(undefined1 *)((int)&local_cc + iVar6);
          }
          iVar6 = iVar6 + 1;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
        iVar6 = 0;
        iVar7 = 4;
        do {
          if (*(char *)((int)&local_d4 + iVar6) != '\x01') {
            *(char *)((int)&local_d8 + iVar6) = *(char *)((int)&local_d4 + iVar6);
          }
          uVar10 = local_c8;
          iVar6 = iVar6 + 1;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
        inst[0x27] = local_d8;
        iVar6 = IRInst__getOperandRecord(inst,1);
        *(undefined4 *)(iVar6 + 0x10) = uVar10;
        iVar6 = 0;
        IRInst__setOperandSource(inst,inst[0x21],0,0,*(undefined4 *)(pass + 8));
        inst[5] = inst[5] & 0xfffffdff;
        uVar13 = inst2[5];
        inst[0x21] = inst[0x21] + -1;
        if ((uVar13 & 0x200) != 0) {
          iVar6 = IRInst__getOperandSource(inst2,inst2[0x21]);
          uVar13 = inst2[5];
        }
        local_84 = 0;
        local_98 = 0;
        local_94 = 0;
        if ((uVar13 & 0x200) != 0) {
          FUN_00104d3c(inst2,&local_98);
        }
        if (iVar6 != 0) {
          FUN_00106b48(inst,&local_98,0,*(undefined4 *)(pass + 8));
          if (*(int *)(pass + 0x478) < *(int *)(iVar6 + 0x160)) {
            *(int *)(iVar6 + 0x160) = *(int *)(iVar6 + 0x160) + 1;
          }
          else {
            *(int *)(iVar6 + 0x160) = *(int *)(pass + 0x478) + 1;
          }
        }
        FUN_00105894(inst2,*(undefined4 *)(pass + 8));
        return 1;
      }
      goto LAB_00162370;
    }
  }
  else {
LAB_00162370:
    uVar13 = inst[0x2e];
  }
  if (((((uVar13 & 1) == 0) && ((uVar13 & 2) == 0)) && (inst[0x48] == 0)) && (inst[0x49] == 0)
     ) {
    bVar2 = true;
    iVar7 = 0;
    do {
      iVar8 = IRInst__getOperandRecord(inst,0);
      if ((*(char *)(iVar7 + iVar8 + 0x10) == '\x01') &&
         (iVar8 = IRInst__getOperandRecord(inst2,0), *(char *)(iVar7 + iVar8 + 0x10) == '\x01')) {
        bVar2 = false;
      }
      bVar1 = iVar7 != 3;
      iVar7 = iVar7 + 1;
    } while (bVar1);
    if ((bVar2) &&
       ((iVar7 = FUN_000f5a0c(inst,1,inst,pass), iVar7 != 0 ||
        (((inst2[5] & 0x200U) == 0 &&
         (iVar7 = FUN_000f5a0c(inst2,1,inst2,pass), iVar7 != 0)))))) {
      return 0;
    }
  }
  iVar7 = 4;
  pfVar12 = local_a8;
  pfVar4 = local_b8;
  do {
    *pfVar4 = GH_U2F(0x7fff0000U);
    pfVar4 = pfVar4 + 1;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  piVar17 = inst;
  inst3 = inst2;
  if (iVar6 == 0) {
    iVar6 = iVar16;
    if (iVar16 == 0) {
      iVar6 = 0;
      pfVar4 = local_b8;
      do {
        iVar7 = IRInst__getOperandRecord(inst2,0);
        if (*(char *)(iVar6 + iVar7 + 0x10) == '\x01') {
          *pfVar4 = 0.0;
        }
        else {
          iVar7 = IRInst__getOperandRecord(inst2,1);
          uVar13 = (uint)*(byte *)(iVar6 + iVar7 + 0x10);
          iVar7 = IRInst__getOperandSource(inst2,1);
          if (((int)*(char *)(iVar7 + 0x15c) >> (uVar13 & 0x3f) & 1U) == 0) {
            return 0;
          }
          *pfVar4 = *(float *)(uVar13 * 0x18 + iVar7 + 0x20);
        }
        bVar2 = iVar6 != 3;
        pfVar4 = pfVar4 + 1;
        iVar6 = iVar6 + 1;
      } while (bVar2);
      iVar16 = 0;
      goto LAB_001627ec;
    }
  }
  else {
    piVar17 = inst2;
    inst3 = inst;
    if (iVar16 != 0) {
      iVar7 = 0;
      dVar21 = (double)((double (*)())FUN_0010aad4)(iVar6);
      pfVar4 = local_b8;
      do {
        iVar6 = IRInst__getOperandRecord(inst2,0);
        if (*(char *)(iVar7 + iVar6 + 0x10) == '\x01') {
          *pfVar4 = 0.0;
        }
        else {
          iVar6 = IRInst__getOperandRecord(inst2,1);
          uVar13 = (uint)*(byte *)(iVar7 + iVar6 + 0x10);
          iVar6 = IRInst__getOperandSource(inst2,1);
          if (((int)*(char *)(iVar6 + 0x15c) >> (uVar13 & 0x3f) & 1U) == 0) {
            return 0;
          }
          *pfVar4 = (float)(dVar21 * (double)*(float *)(uVar13 * 0x18 + iVar6 + 0x20));
        }
        bVar2 = iVar7 != 3;
        pfVar4 = pfVar4 + 1;
        iVar7 = iVar7 + 1;
        piVar17 = inst;
        inst3 = inst2;
      } while (bVar2);
      goto LAB_001627ec;
    }
  }
  iVar16 = iVar6;
  iVar6 = 0;
  dVar21 = (double)((double (*)())FUN_0010aad4)(iVar16);
  pfVar4 = local_b8;
  do {
    iVar7 = IRInst__getOperandRecord(inst3,0);
    if (*(char *)(iVar6 + iVar7 + 0x10) == '\x01') {
      *pfVar4 = 0.0;
    }
    else {
      iVar7 = IRInst__getOperandRecord(inst3,1);
      uVar13 = (uint)*(byte *)(iVar6 + iVar7 + 0x10);
      iVar7 = IRInst__getOperandSource(inst3,1);
      if (((int)*(char *)(iVar7 + 0x15c) >> (uVar13 & 0x3f) & 1U) == 0) {
        return 0;
      }
      *pfVar4 = (float)(dVar21 * (double)*(float *)(uVar13 * 0x18 + iVar7 + 0x20));
    }
    bVar2 = iVar6 != 3;
    pfVar4 = pfVar4 + 1;
    iVar6 = iVar6 + 1;
  } while (bVar2);
LAB_001627ec:
  local_68 = &local_98;
  iVar6 = 4;
  pfVar4 = pfVar12;
  do {
    *pfVar4 = GH_U2F(0x7fff0000U);
    pfVar4 = pfVar4 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  dVar21 = (double)((double (*)())FUN_0010aad4)(iVar16);
  iVar6 = 0;
  local_c4 = local_d8;
  iVar7 = 4;
  do {
    if (*(char *)((int)&local_d4 + iVar6) != '\x01') {
      *(char *)((int)&local_c4 + iVar6) = *(char *)((int)&local_d4 + iVar6);
    }
    iVar6 = iVar6 + 1;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  iVar6 = 0;
  pfVar4 = pfVar12;
  do {
    iVar7 = IRInst__getOperandRecord(inst,0);
    if (*(char *)(iVar6 + iVar7 + 0x10) == '\0') {
      *pfVar4 = (float)dVar21;
    }
    else {
      IRInst__getOperandRecord(inst2,0);
      *pfVar4 = 0.0;
    }
    bVar2 = iVar6 != 3;
    pfVar4 = pfVar4 + 1;
    iVar6 = iVar6 + 1;
  } while (bVar2);
  FUN_000f3908(&local_78,local_c4);
  FUN_000f3340(&local_74,0x10203,local_78);
  local_c0 = local_74;
  piVar9 = *(int **)(*(int *)(pass + 8) + 0x30c);
  iVar6 = (**(code **)(*piVar9 + 0x154))(piVar9,pass,pfVar12,&local_c0);
  FUN_000f3908(&local_70,local_c4);
  FUN_000f3340(&local_6c,0x10203,local_70);
  local_bc = local_6c;
  piVar9 = *(int **)(*(int *)(pass + 8) + 0x30c);
  iVar7 = (**(code **)(*piVar9 + 0x154))(piVar9,pass,local_b8,&local_bc);
  if ((iVar6 != 0) && (iVar7 != 0)) {
    if (*(int *)(pass + 0x478) < *(int *)(iVar6 + 0x160)) {
      *(int *)(iVar6 + 0x160) = *(int *)(iVar6 + 0x160) + 1;
    }
    else {
      *(int *)(iVar6 + 0x160) = *(int *)(pass + 0x478) + 1;
    }
    if (*(int *)(pass + 0x478) < *(int *)(iVar7 + 0x160)) {
      *(int *)(iVar7 + 0x160) = *(int *)(iVar7 + 0x160) + 1;
    }
    else {
      *(int *)(iVar7 + 0x160) = *(int *)(pass + 0x478) + 1;
    }
    *(undefined4 *)(iVar7 + 0x9c) = 0;
    iVar15 = piVar17[0x48];
    iVar16 = IRInst__useCount(inst,pass);
    uVar10 = IRInst__getOperandSource(piVar17,1);
    iVar8 = IRInst__getOperandRecord(piVar17,1);
    local_c8 = *(undefined4 *)(iVar8 + 0x10);
    iVar8 = IRInst__getOperandRecord(piVar17,0);
    iVar8 = FUN_000f30d4(*(undefined4 *)(iVar8 + 0x10));
    iVar11 = IRInst__getOperandRecord(piVar17,1);
    uVar3 = *(undefined1 *)(iVar8 + iVar11 + 0x10);
    iVar11 = 4;
    iVar8 = 0;
    do {
      if (*(char *)((int)&local_c4 + iVar8) == '\0') {
        if (*pfVar12 == 0.0) {
          *(undefined1 *)((int)&local_c8 + iVar8) = uVar3;
        }
        else if (*(char *)((int)&local_c8 + iVar8) == '\x04') {
          *(char *)((int)&local_c8 + iVar8) = (char)iVar8;
        }
      }
      else {
        *(undefined1 *)((int)&local_c8 + iVar8) = 4;
      }
      iVar8 = iVar8 + 1;
      pfVar12 = pfVar12 + 1;
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
    uVar14 = inst2[5];
    iVar8 = 0;
    uVar13 = piVar17[0x2e];
    uVar5 = inst3[0x2e];
    if ((uVar14 & 0x200) != 0) {
      iVar8 = IRInst__getOperandSource(inst2,inst2[0x21]);
      uVar14 = inst2[5];
    }
    local_84 = 0;
    local_98 = 0;
    local_94 = 0;
    if ((uVar14 & 0x200) != 0) {
      FUN_00104d3c(inst2,local_68);
    }
    piVar17 = (int *)inst[1];
    uVar14 = inst[5];
    iVar19 = inst[0x26];
    iVar20 = inst[0x25];
    iVar11 = inst[3];
    if (inst2 == piVar17) {
      piVar17 = (int *)inst2[1];
    }
    DList__unlink(inst);
    FUN_00108304(inst,0x14,*(undefined4 *)(pass + 8));
    inst[0x25] = iVar20;
    inst[0x26] = iVar19;
    if ((uVar14 & 2) != 0) {
      inst[5] = inst[5] | 2;
    }
    inst[3] = iVar11;
    inst[0x27] = local_c4;
    inst[0x49] = 0;
    inst[0x48] = iVar15;
    IRInst__setOperandSource(inst,1,uVar10,0,*(undefined4 *)(pass + 8));
    uVar10 = local_c8;
    iVar11 = IRInst__getOperandRecord(inst,1);
    *(undefined4 *)(iVar11 + 0x10) = uVar10;
    IROperand__setModifierBits(inst + 0x29,1,uVar13 & 1);
    IROperand__setModifierBits(inst + 0x29,2,uVar13 >> 1 & 1);
    IRInst__setOperandSource(inst,2,iVar6,0,*(undefined4 *)(pass + 8));
    uVar10 = local_c0;
    iVar6 = IRInst__getOperandRecord(inst,2);
    *(undefined4 *)(iVar6 + 0x10) = uVar10;
    IRInst__setOperandSource(inst,3,iVar7,0,*(undefined4 *)(pass + 8));
    uVar10 = local_bc;
    iVar6 = IRInst__getOperandRecord(inst,3);
    *(undefined4 *)(iVar6 + 0x10) = uVar10;
    IROperand__setModifierBits(inst + 0x35,1,uVar5 & 1);
    IROperand__setModifierBits(inst + 0x35,2,uVar5 >> 1 & 1);
    inst[0x58] = iVar16 + *(int *)(pass + 0x478);
    if (iVar8 != 0) {
      FUN_00106b48(inst,local_68,0,*(undefined4 *)(pass + 8));
      if (*(int *)(pass + 0x478) < *(int *)(iVar8 + 0x160)) {
        *(int *)(iVar8 + 0x160) = *(int *)(iVar8 + 0x160) + 1;
      }
      else {
        *(int *)(iVar8 + 0x160) = *(int *)(pass + 0x478) + 1;
      }
    }
    Block__insertInstAfter(piVar17[0x56],piVar17,inst);
    FUN_00105894(inst2,*(undefined4 *)(pass + 8));
    return 1;
  }
  return 1;
}

/* FUN_00162cc0 @ 0x162cc0 (316 bytes) */
int FUN_00162cc0(inst, param_2)
  int *inst;
  int param_2;
{
  int iVar1;
  undefined4 operandVReg;
  
  iVar1 = (**(code **)(*inst + 100))(inst,param_2);
  if ((((iVar1 != 0) || (*(int *)(inst[0x22] + 8) == 0x13)) && ((inst[5] & 0x200U) != 0)) &&
     ((*(uint *)(*(int *)(*(int *)(param_2 + 8) + 0x30c) + 8) & 0x100) != 0)) {
    operandVReg = IRInst__getOperandSource(inst,inst[0x21]);
    iVar1 = ((int (*)())FUN_00161748)(inst,operandVReg,param_2);
    if (((((iVar1 != 0) || (iVar1 = FUN_00151a74(inst,operandVReg,param_2), iVar1 != 0)) ||
         ((iVar1 = FUN_001524b8(inst,operandVReg,param_2), iVar1 != 0 ||
          ((iVar1 = FUN_00151370(inst,operandVReg,param_2), iVar1 != 0 ||
           (iVar1 = FUN_001541f0(inst,operandVReg,param_2), iVar1 != 0)))))) ||
        (iVar1 = FUN_00152ea8(inst,operandVReg,param_2), iVar1 != 0)) ||
       (iVar1 = ((int (*)())FUN_001621c8)(inst,operandVReg,param_2), iVar1 != 0)) {
      return 1;
    }
  }
  return 0;
}

/* FUN_00162dfc @ 0x162dfc (1532 bytes) */
int FUN_00162dfc(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  int *operandVReg;
  bool bVar1;
  int iVar2;
  int *callResult;
  int iVar4;
  int *piVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined1 *puVar9;
  undefined4 *puVar10;
  int iVar11;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  int local_6c [6];
  undefined4 local_54 [10];
  
  iVar2 = FUN_0011379c(*(undefined4 *)(param_3 + 8),*param_1);
  if ((iVar2 != 0) && (iVar2 = *param_1, (*(uint *)(iVar2 + 0x14) & 0x200) != 0)) {
    callResult = (int *)IRInst__getOperandSource(iVar2,*(undefined4 *)(iVar2 + 0x84));
    if (*(int *)(*(int *)(*param_1 + 0x88) + 8) == *(int *)(callResult[0x22] + 8)) {
      iVar2 = IRInst__getOperandRecord(*param_1,0);
      local_84 = *(undefined4 *)(iVar2 + 0x10);
      iVar4 = IRInst__getOperandRecord(callResult,0);
      iVar2 = 0;
      local_88 = *(undefined4 *)(iVar4 + 0x10);
      iVar4 = 4;
      do {
        if ((*(char *)((int)&local_84 + iVar2) != '\x01') &&
           (*(char *)((int)&local_88 + iVar2) != '\x01')) {
          return 0;
        }
        iVar2 = iVar2 + 1;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      iVar2 = *param_1;
      if ((*(int *)(iVar2 + 0x120) == callResult[0x48]) && (*(int *)(iVar2 + 0x124) == callResult[0x49])) {
        if (param_2 == 0) {
          iVar2 = FUN_00156cb8(iVar2,callResult,param_3);
          if (iVar2 == 0) {
            return 0;
          }
          iVar2 = *param_1;
        }
        iVar11 = 5;
        iVar4 = 0;
        piVar5 = local_6c;
        do {
          *piVar5 = iVar4;
          piVar5 = piVar5 + 1;
          iVar4 = iVar4 + 1;
          iVar11 = iVar11 + -1;
        } while (iVar11 != 0);
        iVar2 = FUN_00112f78(*(undefined4 *)(*(int *)(iVar2 + 0x88) + 8),
                             *(undefined4 *)(param_3 + 8));
        if (iVar2 != 0) {
          iVar2 = IRInst__getOperandSource(*param_1,1);
          iVar4 = IRInst__getOperandSource(callResult,2);
          if (iVar2 == iVar4) {
            iVar2 = IRInst__getOperandSource(*param_1,2);
            iVar4 = IRInst__getOperandSource(callResult,1);
            if (iVar2 == iVar4) {
              local_6c[1] = 2;
              local_6c[2] = 1;
            }
          }
        }
        for (iVar2 = 1; iVar4 = (**(code **)(*(int *)*param_1 + 0x14))((int *)*param_1),
            iVar2 <= iVar4; iVar2 = iVar2 + 1) {
          iVar4 = IRInst__getOperandSource(*param_1,iVar2);
          iVar8 = local_6c[iVar2];
          iVar11 = IRInst__getOperandSource(callResult,iVar8);
          if (iVar4 != iVar11) {
            return 0;
          }
          uVar6 = *(uint *)(iVar2 * 0x18 + *param_1 + 0xa0);
          if ((uVar6 & 1) != (callResult[iVar8 * 6 + 0x28] & 1U)) {
            return 0;
          }
          if ((uVar6 >> 1 & 1) != ((uint)callResult[iVar8 * 6 + 0x28] >> 1 & 1)) {
            return 0;
          }
          operandVReg = (int *)IRInst__getOperandSource(*param_1,iVar2);
          iVar4 = (**(code **)(*operandVReg + 0x48))(operandVReg);
          if (iVar4 != 0) {
            iVar4 = IRInst__getOperandRecord(*param_1,iVar2);
            local_70 = *(undefined4 *)(iVar4 + 0x10);
            iVar4 = IRInst__getOperandRecord(callResult,iVar8);
            local_80 = *(undefined4 *)(iVar4 + 0x10);
            piVar5 = *(int **)(*(int *)(param_3 + 8) + 0x30c);
            iVar4 = (**(code **)(*piVar5 + 0x100))(piVar5,&local_70);
            if (iVar4 != 0) {
              piVar5 = *(int **)(*(int *)(param_3 + 8) + 0x30c);
              iVar4 = (**(code **)(*piVar5 + 0x100))(piVar5,&local_80);
              if (iVar4 != 0) {
                iVar4 = 0;
                local_7c = local_70;
                iVar11 = 4;
                do {
                  if (*(char *)(iVar4 + (int)&local_80) == '\x04') {
                    *(undefined1 *)(iVar4 + (int)&local_80) =
                         *(undefined1 *)((int)&local_7c + iVar4);
                  }
                  iVar4 = iVar4 + 1;
                  iVar11 = iVar11 + -1;
                } while (iVar11 != 0);
                piVar5 = *(int **)(*(int *)(param_3 + 8) + 0x30c);
                iVar4 = (**(code **)(*piVar5 + 0x100))(piVar5,&local_80);
                if (iVar4 == 0) {
                  return 0;
                }
              }
            }
          }
        }
        iVar2 = IRInst__getOperandRecord(*param_1,0);
        puVar10 = local_54;
        local_78 = *(undefined4 *)(iVar2 + 0x10);
        for (iVar2 = 1; iVar4 = (**(code **)(*(int *)*param_1 + 0x14))((int *)*param_1),
            iVar2 <= iVar4; iVar2 = iVar2 + 1) {
          iVar4 = IRInst__getOperandRecord(*param_1,iVar2);
          *puVar10 = *(undefined4 *)(iVar4 + 0x10);
          puVar10 = puVar10 + 1;
        }
        iVar2 = 0;
        do {
          iVar4 = IRInst__getOperandRecord(callResult,0);
          if (*(char *)(iVar2 + iVar4 + 0x10) != '\x01') {
            iVar4 = IRInst__getOperandRecord(callResult,0);
            iVar11 = 1;
            piVar5 = local_6c;
            *(undefined1 *)((int)&local_78 + iVar2) = *(undefined1 *)(iVar2 + iVar4 + 0x10);
            puVar9 = (undefined1 *)((int)local_54 + iVar2);
            while( true ) {
              piVar5 = piVar5 + 1;
              iVar4 = (**(code **)(*callResult + 0x14))(callResult);
              if (iVar4 < iVar11) break;
              iVar11 = iVar11 + 1;
              iVar4 = IRInst__getOperandRecord(callResult,*piVar5);
              *puVar9 = *(undefined1 *)(iVar2 + iVar4 + 0x10);
              puVar9 = puVar9 + 4;
            }
          }
          bVar1 = iVar2 != 3;
          iVar2 = iVar2 + 1;
        } while (bVar1);
        iVar4 = 0;
        iVar2 = IRInst__getOperandRecord(*param_1,*(undefined4 *)(*param_1 + 0x84));
        local_74 = *(undefined4 *)(iVar2 + 0x10);
        do {
          iVar2 = IRInst__getOperandRecord(callResult,0);
          if (*(char *)(iVar4 + iVar2 + 0x10) != '\x01') {
            *(undefined1 *)((int)&local_74 + iVar4) = 4;
          }
          bVar1 = iVar4 != 3;
          iVar4 = iVar4 + 1;
        } while (bVar1);
        iVar2 = 1;
        puVar10 = local_54;
        while( true ) {
          iVar4 = (**(code **)(*(int *)*param_1 + 0x14))((int *)*param_1);
          if (iVar4 < iVar2) {
            puVar10 = local_54;
            *(undefined4 *)(*param_1 + 0x9c) = local_78;
            for (iVar2 = 1; iVar4 = (**(code **)(*(int *)*param_1 + 0x14))((int *)*param_1),
                iVar2 <= iVar4; iVar2 = iVar2 + 1) {
              uVar7 = *puVar10;
              iVar4 = IRInst__getOperandRecord(*param_1,iVar2);
              puVar10 = puVar10 + 1;
              *(undefined4 *)(iVar4 + 0x10) = uVar7;
            }
            if ((callResult[5] & 0x200U) == 0) {
              iVar2 = *param_1;
              IRInst__setOperandSource(iVar2,*(undefined4 *)(iVar2 + 0x84),0,0,*(undefined4 *)(param_3 + 8));
              *(int *)(iVar2 + 0x84) = *(int *)(iVar2 + 0x84) + -1;
              *(uint *)(iVar2 + 0x14) = *(uint *)(iVar2 + 0x14) & 0xfffffdff;
              return 1;
            }
            iVar2 = IRInst__getOperandSource(callResult,callResult[0x21]);
            IRInst__setExtraOperandSource(*param_1,iVar2,0,*(undefined4 *)(param_3 + 8));
            uVar7 = local_74;
            iVar4 = *param_1;
            if (*(int *)(iVar4 + 0x84) == 0) {
              *(undefined4 *)(iVar4 + 0x9c) = local_74;
            }
            else {
              iVar4 = IRInst__getOperandRecord(iVar4,*(int *)(iVar4 + 0x84));
              *(undefined4 *)(iVar4 + 0x10) = uVar7;
            }
            if (*(int *)(iVar2 + 0x160) <= *(int *)(param_3 + 0x478)) {
              *(int *)(iVar2 + 0x160) = *(int *)(param_3 + 0x478) + 1;
              return 1;
            }
            *(int *)(iVar2 + 0x160) = *(int *)(iVar2 + 0x160) + 1;
            return 1;
          }
          piVar5 = *(int **)(*(int *)(param_3 + 8) + 0x30c);
          iVar4 = (**(code **)(*piVar5 + 0x100))(piVar5,puVar10);
          if (iVar4 == 0) break;
          iVar2 = iVar2 + 1;
          puVar10 = puVar10 + 1;
        }
      }
    }
  }
  return 0;
}

/* FUN_001633f8 @ 0x1633f8 (128 bytes) */
int FUN_001633f8(inst, param_2, param_3, param_4, param_5, param_6, param_7)
  int inst;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  unsigned int ghidra_home[8] = { inst, param_2, param_3, param_4, param_5, param_6, param_7, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  int callResult;
  undefined4 uVar2;
  
  uVar2 = 0;
  (*(int *)((unsigned char *)ghidra_home + 0)) = inst;
  if ((*(uint *)(inst + 0x14) & 0x200) != 0) {
    uVar2 = IRInst__getOperandSource(inst,*(undefined4 *)(inst + 0x84));
  }
  callResult = ((int (*)())FUN_00162dfc)(&(*(unsigned int *)((unsigned char *)ghidra_home + 0)),0,param_2);
  if (callResult != 0) {
    *(int *)(param_2 + 0x1fc) = *(int *)(param_2 + 0x1fc) + 1;
    FUN_00105894(uVar2,*(undefined4 *)(param_2 + 8));
  }
  return callResult != 0;
}

/* FUN_00163478 @ 0x163478 (1308 bytes) */
int FUN_00163478(param_1, param_2, inst, param_4)
  undefined4 param_1;
  undefined4 param_2;
  int *inst;
  int param_4;
{
  bool bVar1;
  int iVar2;
  int operandRecord;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined1 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  int iVar14;
  int local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  int local_78;
  undefined4 local_68;
  
  uVar10 = *(undefined4 *)(param_4 + 8);
  iVar11 = *(int *)(inst[0x22] + 8);
  operandRecord = IRInst__getOperandRecord(inst,0);
  local_98 = *(int *)(operandRecord + 0x10);
  if ((iVar11 - 0x1cU < 2) && (operandRecord = FUN_000f3824(local_98), operandRecord != 0)) {
    uVar12 = 0;
    for (operandRecord = 1; iVar11 = (**(code **)(*inst + 0x14))(inst), operandRecord <= iVar11;
        operandRecord = operandRecord + 1) {
      iVar11 = IRInst__getOperandSource(inst,operandRecord);
      if ((((*(int *)(*(int *)(iVar11 + 0x88) + 8) == 0x13) &&
           (iVar4 = IRInst__hasSingleUse(iVar11,param_4), iVar4 != 0)) && (*(int *)(iVar11 + 0x124) == 0))
         && ((*(int *)(iVar11 + 0x120) == 0 && ((*(uint *)(iVar11 + 0x14) & 0x200) == 0)))) {
        iVar4 = IRInst__getOperandRecord(iVar11,1);
        uVar9 = *(undefined4 *)(iVar4 + 0x10);
        iVar4 = IRInst__getOperandRecord(iVar11,2);
        uVar8 = *(undefined4 *)(iVar4 + 0x10);
        iVar4 = FUN_000f2c5c(uVar9);
        if ((iVar4 == 0) || (iVar4 = FUN_000f2c5c(uVar8), iVar4 == 0)) {
          iVar4 = FUN_000f2c5c(uVar9);
          if (iVar4 == 0) {
            iVar4 = FUN_000f2c5c(uVar8);
            if (iVar4 == 0) goto LAB_00163950;
            iVar4 = IRInst__getOperandSource(iVar11,2);
            iVar5 = IRInst__getOperandSource(iVar11,1);
            uVar12 = 2;
            local_94 = uVar8;
            uVar8 = 1;
          }
          else {
            iVar4 = IRInst__getOperandSource(iVar11,1);
            local_94 = uVar9;
            iVar5 = IRInst__getOperandSource(iVar11,2);
            uVar12 = 1;
            uVar8 = 2;
          }
          iVar2 = 0;
          iVar14 = 4;
          do {
            if (*(char *)((int)&local_94 + iVar2) != '\x04') {
              uVar7 = *(undefined1 *)((int)&local_94 + iVar2);
              goto LAB_00163628;
            }
            iVar2 = iVar2 + 1;
            iVar14 = iVar14 + -1;
          } while (iVar14 != 0);
          uVar7 = 0;
LAB_00163628:
          iVar2 = IRInst__getOperandRecord(iVar11,uVar8);
          local_90 = *(undefined4 *)(iVar2 + 0x10);
          iVar2 = IRInst__getOperandRecord(inst,operandRecord);
          local_8c = *(undefined4 *)(iVar2 + 0x10);
          *(int *)(param_4 + 0x284) = *(int *)(param_4 + 0x284) + 1;
          if (*(int *)(param_4 + 0x478) < *(int *)(iVar5 + 0x160)) {
            *(int *)(iVar5 + 0x160) = *(int *)(iVar5 + 0x160) + 1;
          }
          else {
            *(int *)(iVar5 + 0x160) = *(int *)(param_4 + 0x478) + 1;
          }
          if (*(int *)(param_4 + 0x478) < *(int *)(iVar4 + 0x160)) {
            *(int *)(iVar4 + 0x160) = *(int *)(iVar4 + 0x160) + 1;
          }
          else {
            *(int *)(iVar4 + 0x160) = *(int *)(param_4 + 0x478) + 1;
          }
          local_7c = 0;
          local_78 = 0;
          local_68 = 0;
          if ((inst[5] & 0x200U) != 0) {
            FUN_00104d3c(inst,&local_7c);
            IRInst__setOperandSource(inst,inst[0x21],0,0,uVar10);
            inst[0x21] = inst[0x21] + -1;
            inst[5] = inst[5] & 0xfffffdff;
          }
          local_88 = 0;
          local_84 = 0;
          local_80 = 0;
          IRInst__saveCounters(inst,&local_88,0xffffffff);
          iVar2 = inst[0x49];
          iVar14 = inst[0x48];
          inst[0x49] = 0;
          inst[0x48] = 0;
          iVar13 = inst[2];
          DList__unlink(inst);
          iVar4 = IRInst__clone(inst,uVar10,0);
          *(undefined4 *)(iVar4 + 0x98) = 0;
          *(undefined4 *)(iVar4 + 0x94) = *(undefined4 *)(iVar4 + 0x14c);
          piVar6 = (int *)FUN_00103ebc(iVar11,inst,uVar10,0);
          piVar6[0x26] = 0;
          piVar6[0x25] = piVar6[0x53];
          IRInst__setOperandSource(piVar6,uVar8,iVar4,0,uVar10);
          FUN_00105894(iVar11,uVar10);
          Block__insertInstBefore(*(undefined4 *)(iVar13 + 0x158),iVar13,iVar4);
          Block__insertInstAfter(*(undefined4 *)(iVar4 + 0x158),iVar4,piVar6);
          if ((operandRecord == 1) && (iVar13 = IRInst__getOperandSource(iVar4,2), iVar11 == iVar13)) {
            IRInst__setOperandSource(iVar4,2,iVar5,0,uVar10);
          }
          IRInst__setOperandSource(iVar4,operandRecord,iVar5,0,uVar10);
          iVar5 = 4;
          iVar11 = 0;
          do {
            if (*(byte *)((int)&local_8c + iVar11) != 4) {
              *(undefined1 *)((int)&local_8c + iVar11) =
                   *(undefined1 *)((int)&local_90 + (uint)*(byte *)((int)&local_8c + iVar11));
            }
            uVar9 = local_8c;
            iVar11 = iVar11 + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
          if (operandRecord == 0) {
            *(undefined4 *)(iVar4 + 0x9c) = local_8c;
          }
          else {
            iVar11 = IRInst__getOperandRecord(iVar4,operandRecord);
            *(undefined4 *)(iVar11 + 0x10) = uVar9;
          }
          *(int *)(iVar4 + 0x160) = *(int *)(param_4 + 0x478) + 1;
          if (local_78 != 0) {
            FUN_00106b48(piVar6,&local_7c,0,uVar10);
          }
          IRInst__restoreCounters(piVar6,&local_88);
          piVar6[0x48] = iVar14;
          piVar6[0x49] = iVar2;
          iVar11 = 0;
          piVar6[0x27] = local_98;
          do {
            if (*(char *)((int)&local_98 + iVar11) == '\x01') {
              (**(code **)(*piVar6 + 0x88))(piVar6,1,iVar11,4);
              (**(code **)(*piVar6 + 0x88))(piVar6,2,iVar11,4);
            }
            else {
              (**(code **)(*piVar6 + 0x88))(piVar6,uVar12,iVar11,uVar7);
              (**(code **)(*piVar6 + 0x88))(piVar6,uVar8,iVar11,iVar11);
            }
            bVar1 = iVar11 != 3;
            iVar11 = iVar11 + 1;
          } while (bVar1);
          uVar12 = 1;
        }
      }
LAB_00163950: ;
    }
  }
  else {
    uVar12 = 0;
  }
  return uVar12;
}

/* FUN_00163994 @ 0x163994 (3864 bytes) */
int FUN_00163994(node, pass)
  int node;
  int pass;
{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int *operandVReg;
  int iVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  uint uVar10;
  int *piVar11;
  uint uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  uint uVar17;
  uint uVar18;
  int iVar19;
  uint *puVar20;
  int iVar21;
  int iVar22;
  double fparam_1;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  int local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  int local_98;
  undefined4 local_88;
  undefined4 local_84;
  float local_80;
  
  if ((*(uint *)(node + 0x14) & 0x200) == 0) {
    return 0;
  }
  iVar3 = IRInst__getOperandSource(node,*(undefined4 *)(node + 0x84));
  if (iVar3 == 0) {
    return 0;
  }
  if ((*(uint *)(*(int *)(*(int *)(pass + 8) + 0x30c) + 8) & 0x100) == 0) {
    return 0;
  }
  iVar19 = *(int *)(*(int *)(node + 0x88) + 8);
  iVar21 = *(int *)(*(int *)(iVar3 + 0x88) + 8);
  iVar4 = IRInst__getOperandRecord(node,*(undefined4 *)(node + 0x84));
  local_b8 = *(undefined4 *)(iVar4 + 0x10);
  if (iVar19 == 0x31) {
    if (iVar21 != 0x14) {
      return 0;
    }
    iVar4 = IRInst__getOperandRecord(node,0);
    iVar21 = 0;
    local_84 = *(undefined4 *)(iVar4 + 0x10);
    iVar22 = 4;
    do {
      if (*(char *)((int)&local_b8 + iVar21) == '\x04') {
        if (*(char *)((int)&local_84 + iVar21) == '\0') {
          *(char *)((int)&local_b8 + iVar21) = (char)iVar21;
        }
      }
      else {
        *(undefined1 *)((int)&local_b8 + iVar21) = 4;
      }
      iVar21 = iVar21 + 1;
      iVar22 = iVar22 + -1;
      iVar4 = iVar3;
      iVar19 = node;
    } while (iVar22 != 0);
  }
  else {
    if (iVar19 != 0x14) {
      return 0;
    }
    iVar4 = node;
    iVar19 = iVar3;
    if (iVar21 != 0x31) {
      return 0;
    }
  }
  if (*(int *)(iVar19 + 0x120) != *(int *)(iVar4 + 0x120)) {
    return 0;
  }
  if (*(int *)(iVar19 + 0x124) != *(int *)(iVar4 + 0x124)) {
    return 0;
  }
  iVar21 = IRInst__getOperandRecord(iVar19,0);
  local_b4 = *(int *)(iVar21 + 0x10);
  iVar21 = IRInst__getOperandRecord(iVar4,0);
  local_b0 = *(undefined4 *)(iVar21 + 0x10);
  iVar21 = Compiler__isOptionEnabled(*(undefined4 *)(pass + 8),0x30);
  if (iVar21 != 0) {
    if ((char)local_b4 == '\0') {
      return 0;
    }
    if ((char)local_b0 == '\0') {
      return 0;
    }
  }
  iVar21 = 0;
  iVar22 = 4;
  do {
    if ((*(char *)((int)&local_b4 + iVar21) != '\x01') &&
       (*(char *)((int)&local_b0 + iVar21) != '\x01')) {
      return 0;
    }
    iVar21 = iVar21 + 1;
    iVar22 = iVar22 + -1;
  } while (iVar22 != 0);
  operandVReg = (int *)IRInst__getOperandSource(iVar19,1);
  iVar21 = (**(code **)(*operandVReg + 0x60))(operandVReg);
  if (iVar21 != 0) {
    return 0;
  }
  iVar21 = FUN_001466f4(iVar19,1);
  iVar22 = FUN_001466f4(iVar4,1);
  iVar6 = FUN_001466f4(iVar4,2);
  iVar7 = FUN_001466f4(iVar4,3);
  uVar17 = *(uint *)(iVar4 + 0xb8) & 1;
  uVar10 = *(uint *)(iVar4 + 0xd0) & 1;
  uVar18 = *(uint *)(iVar19 + 0xb8) & 1;
  uVar12 = *(uint *)(iVar19 + 0xb8) >> 1 & 1;
  if ((iVar21 == iVar22) && ((*(uint *)(iVar4 + 0xb8) >> 1 & 1) == uVar12)) {
    if (uVar18 == 0) {
      if (uVar17 != uVar10) goto LAB_00163c00;
    }
    else if (uVar17 == uVar10) goto LAB_00163c00;
    uVar13 = 1;
    fparam_1 = 1.0;
    uVar14 = 2;
    uVar15 = 3;
  }
  else {
LAB_00163c00:
    if ((iVar21 == iVar6) && ((*(uint *)(iVar4 + 0xd0) >> 1 & 1) == uVar12)) {
      if (uVar18 == 0) {
        if (uVar17 != uVar10) goto LAB_00163c2c;
      }
      else if (uVar17 == uVar10) goto LAB_00163c2c;
      uVar13 = 2;
      fparam_1 = 1.0;
      uVar14 = 1;
      uVar15 = 3;
    }
    else {
LAB_00163c2c:
      if (iVar21 != iVar7) {
        return 0;
      }
      if ((*(uint *)(iVar4 + 0xe8) >> 1 & 1) != uVar12) {
        return 0;
      }
      if ((*(uint *)(iVar4 + 0xe8) & 1) != uVar18) {
        return 0;
      }
      uVar13 = 3;
      fparam_1 = 0.0;
      uVar14 = 1;
      uVar15 = 2;
    }
  }
  local_88 = 0;
  local_9c = 0;
  local_98 = 0;
  if ((*(uint *)(iVar3 + 0x14) & 0x200) != 0) {
    FUN_00104d3c(iVar3,&local_9c);
  }
  iVar3 = *(int *)(iVar19 + 0x160) - *(int *)(pass + 0x478);
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  iVar21 = IRInst__getOperandRecord(iVar19,1);
  local_a4 = *(undefined4 *)(iVar21 + 0x10);
  iVar21 = IRInst__getOperandRecord(iVar4,uVar14);
  local_a0 = *(undefined4 *)(iVar21 + 0x10);
  iVar21 = IRInst__getOperandRecord(iVar4,uVar15);
  local_ac = *(undefined4 *)(iVar21 + 0x10);
  iVar22 = 4;
  local_a8 = local_b4;
  iVar21 = 0;
  do {
    if (*(char *)((int)&local_b0 + iVar21) != '\x01') {
      *(char *)((int)&local_a8 + iVar21) = *(char *)((int)&local_b0 + iVar21);
    }
    iVar21 = iVar21 + 1;
    iVar22 = iVar22 + -1;
  } while (iVar22 != 0);
  FUN_00105894(iVar19,*(undefined4 *)(pass + 8));
  operandVReg = (int *)IRInst__getOperandSource(iVar4,uVar13);
  piVar8 = (int *)IRInst__getOperandSource(iVar4,uVar14);
  piVar9 = (int *)IRInst__getOperandSource(iVar4,uVar15);
  iVar19 = *(int *)(node + 4);
  DList__unlink(node);
  if ((*(uint *)(iVar4 + 0x14) & 0x200) != 0) {
    uVar16 = *(undefined4 *)(pass + 8);
    uVar17 = *(uint *)(pass + 0x30) >> 7 & 1;
    if (uVar17 != 0) {
      iVar21 = IRInst__getOperandSource(iVar4,*(undefined4 *)(iVar4 + 0x84));
      puVar20 = *(uint **)(iVar21 + 0x10);
      uVar10 = puVar20[1];
      if (0 < (int)uVar10) {
        uVar18 = 0;
        do {
          if (uVar18 < *puVar20) {
            if (uVar10 <= uVar18) {
              _memset(uVar10 * 4 + puVar20[2],0,(uVar18 - uVar10) * 4 + 4);
              puVar20[1] = uVar18 + 1;
            }
            piVar11 = (int *)(uVar18 * 4 + puVar20[2]);
          }
          else {
            piVar11 = (int *)Vector__elementRefGrow(puVar20,uVar18);
          }
          if (iVar4 == *piVar11) {
            Vector__removeAt(puVar20,uVar18);
            iVar21 = IRInst__getOperandSource(iVar4,*(undefined4 *)(iVar4 + 0x84));
            *(int *)(iVar21 + 0x160) = *(int *)(iVar21 + 0x160) + -1;
            break;
          }
          uVar10 = puVar20[1];
          uVar18 = uVar18 + 1;
        } while ((int)uVar18 < (int)uVar10);
      }
    }
    IRInst__setOperandSource(iVar4,*(undefined4 *)(iVar4 + 0x84),0,uVar17,uVar16);
    *(int *)(iVar4 + 0x84) = *(int *)(iVar4 + 0x84) + -1;
    *(uint *)(iVar4 + 0x14) = *(uint *)(iVar4 + 0x14) & 0xfffffdff;
  }
  piVar11 = (int *)FUN_00103ebc(iVar4,node,*(undefined4 *)(pass + 8),0);
  Block__insertInstAfter(*(undefined4 *)(iVar19 + 0x158),iVar19,piVar11);
  iVar19 = piVar11[0x53];
  piVar11[0x27] = local_a8;
  iVar4 = IRInst__getOperandRecord(piVar11,0);
  *(int *)(iVar4 + 8) = iVar19;
  iVar4 = (**(code **)(*piVar8 + 0x60))(piVar8);
  if (iVar4 == 0) {
    piVar8 = (int *)FUN_0010a240(0xa2,*(undefined4 *)(pass + 8));
    Block__insertInstBefore(piVar11[0x56],piVar11,piVar8);
    piVar8[0x21] = 1;
    piVar8[0x25] = piVar8[0x53];
    piVar8[0x26] = 0x36;
    piVar8[0x27] = local_a8;
    iVar4 = IRInst__getOperandSource(piVar11,uVar14);
    IRInst__setOperandSource(piVar8,1,iVar4,0,*(undefined4 *)(pass + 8));
    if (*(int *)(pass + 0x478) < *(int *)(iVar4 + 0x160)) {
      *(int *)(iVar4 + 0x160) = *(int *)(iVar4 + 0x160) + 1;
    }
    else {
      *(int *)(iVar4 + 0x160) = *(int *)(pass + 0x478) + 1;
    }
    piVar8[0x21] = 2;
    iVar4 = 0;
    ((void (*)())FUN_000f79c4)(piVar8,pass,2,fparam_1,fparam_1,fparam_1,fparam_1);
    do {
      if (*(char *)((int)&local_b0 + iVar4) != '\x01') {
        (**(code **)(*piVar8 + 0x88))(piVar8,1,iVar4,*(undefined1 *)((int)&local_a0 + iVar4));
        (**(code **)(*piVar8 + 0x88))(piVar8,2,iVar4,4);
        (**(code **)(*piVar11 + 0x88))(piVar11,uVar14,iVar4,iVar4);
      }
      bVar1 = iVar4 != 3;
      iVar4 = iVar4 + 1;
    } while (bVar1);
    iVar4 = 0;
    do {
      if (*(char *)((int)&local_b4 + iVar4) != '\x01') {
        (**(code **)(*piVar8 + 0x88))(piVar8,1,iVar4,4);
        (**(code **)(*piVar8 + 0x88))(piVar8,2,iVar4,iVar4);
        (**(code **)(*piVar11 + 0x88))(piVar11,uVar14,iVar4,iVar4);
      }
      bVar1 = iVar4 != 3;
      iVar4 = iVar4 + 1;
    } while (bVar1);
    IRInst__setOperandSource(piVar11,uVar14,piVar8,0,*(undefined4 *)(pass + 8));
    piVar8[0x58] = *(int *)(pass + 0x478) + 1;
  }
  else {
    iVar4 = IRInst__hasSingleUse(piVar8,pass);
    if (iVar4 == 0) {
      piVar8[0x58] = piVar8[0x58] + -1;
      piVar8 = (int *)IRInst__clone(piVar8,*(undefined4 *)(pass + 8),0);
      Block__insertInstBefore(*(undefined4 *)(node + 0x158),node,piVar8);
      piVar8[0x58] = *(int *)(pass + 0x478) + 1;
    }
    iVar4 = piVar8[0x21];
    if (1 < iVar4) {
      bVar1 = false;
      iVar19 = 2;
      do {
        iVar4 = IRInst__getOperandRecord(piVar8,0);
        iVar4 = FUN_000f5cf0(piVar8,iVar19,*(undefined4 *)(iVar4 + 0x10),&local_84);
        if ((iVar4 != 0) && (fparam_1 == (double)local_80)) {
          iVar4 = -1;
          iVar21 = 0;
          do {
            iVar22 = IRInst__getOperandRecord(piVar8,iVar19);
            if (*(char *)(iVar21 + iVar22 + 0x10) != '\x04') {
              iVar4 = iVar21;
            }
            bVar2 = iVar21 != 3;
            iVar21 = iVar21 + 1;
          } while (bVar2);
          iVar21 = 0;
          do {
            if (*(char *)((int)&local_b8 + iVar21) != '\x04') {
              bVar1 = true;
              (**(code **)(*piVar11 + 0x88))(piVar11,uVar14,iVar21,iVar4);
            }
            bVar2 = iVar21 != 3;
            iVar21 = iVar21 + 1;
          } while (bVar2);
          if (bVar1) goto LAB_00164300;
        }
        iVar4 = piVar8[0x21];
        iVar19 = iVar19 + 1;
      } while (iVar19 <= iVar4);
      if (bVar1) goto LAB_00164300;
    }
    iVar4 = iVar4 + 1;
    piVar8[0x21] = iVar4;
    ((void (*)())FUN_000f79c4)(piVar8,pass,iVar4,fparam_1,fparam_1,fparam_1,fparam_1);
    iVar19 = IRInst__getOperandRecord(piVar8,iVar4);
    *(undefined4 *)(iVar19 + 0x10) = 0x4040404;
    iVar19 = 0;
    do {
      iVar21 = IRInst__getOperandRecord(piVar8,0);
      if (*(char *)(iVar19 + iVar21 + 0x10) != '\0') {
        (**(code **)(*piVar8 + 0x88))(piVar8,iVar4,iVar19,iVar19);
        *(undefined1 *)((int)piVar8 + iVar19 + 0x9c) = 0;
        goto LAB_001642bc;
      }
      bVar1 = iVar19 != 3;
      iVar19 = iVar19 + 1;
    } while (bVar1);
    iVar19 = -1;
LAB_001642bc:
    iVar4 = 0;
    do {
      if (*(char *)((int)&local_b8 + iVar4) != '\x04') {
        (**(code **)(*piVar11 + 0x88))(piVar11,uVar14,iVar4,iVar19);
      }
      bVar1 = iVar4 != 3;
      iVar4 = iVar4 + 1;
    } while (bVar1);
  }
LAB_00164300:
  iVar4 = (**(code **)(*piVar9 + 0x60))(piVar9);
  if (iVar4 == 0) {
    piVar8 = (int *)FUN_0010a240(0xa2,*(undefined4 *)(pass + 8));
    Block__insertInstBefore(piVar11[0x56],piVar11,piVar8);
    piVar8[0x21] = 1;
    piVar8[0x25] = piVar8[0x53];
    piVar8[0x26] = 0x36;
    piVar8[0x27] = local_a8;
    iVar4 = IRInst__getOperandSource(piVar11,uVar15);
    IRInst__setOperandSource(piVar8,1,iVar4,0,*(undefined4 *)(pass + 8));
    if (*(int *)(pass + 0x478) < *(int *)(iVar4 + 0x160)) {
      *(int *)(iVar4 + 0x160) = *(int *)(iVar4 + 0x160) + 1;
    }
    else {
      *(int *)(iVar4 + 0x160) = *(int *)(pass + 0x478) + 1;
    }
    piVar8[0x21] = 2;
    iVar4 = 0;
    ((void (*)())FUN_000f79c4)(piVar8,pass,2,0.0,0.0,0.0,0.0);
    do {
      if (*(char *)((int)&local_b0 + iVar4) != '\x01') {
        (**(code **)(*piVar8 + 0x88))(piVar8,1,iVar4,*(undefined1 *)((int)&local_ac + iVar4));
        (**(code **)(*piVar8 + 0x88))(piVar8,2,iVar4,4);
        (**(code **)(*piVar11 + 0x88))(piVar11,uVar15,iVar4,iVar4);
      }
      bVar1 = iVar4 != 3;
      iVar4 = iVar4 + 1;
    } while (bVar1);
    iVar4 = 0;
    do {
      if (*(char *)((int)&local_b4 + iVar4) != '\x01') {
        (**(code **)(*piVar8 + 0x88))(piVar8,1,iVar4,4);
        (**(code **)(*piVar8 + 0x88))(piVar8,2,iVar4,iVar4);
        (**(code **)(*piVar11 + 0x88))(piVar11,uVar15,iVar4,iVar4);
      }
      bVar1 = iVar4 != 3;
      iVar4 = iVar4 + 1;
    } while (bVar1);
    IRInst__setOperandSource(piVar11,uVar15,piVar8,0,*(undefined4 *)(pass + 8));
    piVar8[0x58] = *(int *)(pass + 0x478) + 1;
  }
  else {
    iVar4 = IRInst__hasSingleUse(piVar9,pass);
    if (iVar4 == 0) {
      piVar9[0x58] = piVar9[0x58] + -1;
      piVar9 = (int *)IRInst__clone(piVar9,*(undefined4 *)(pass + 8),0);
      Block__insertInstBefore(*(undefined4 *)(node + 0x158),node,piVar9);
      piVar9[0x58] = *(int *)(pass + 0x478) + 1;
    }
    iVar4 = piVar9[0x21];
    if (1 < iVar4) {
      bVar1 = false;
      iVar19 = 2;
      do {
        iVar4 = IRInst__getOperandRecord(piVar9,0);
        iVar4 = FUN_000f5cf0(piVar9,iVar19,*(undefined4 *)(iVar4 + 0x10),&local_84);
        if ((iVar4 != 0) && (local_80 == 0.0)) {
          iVar4 = -1;
          iVar21 = 0;
          do {
            iVar22 = IRInst__getOperandRecord(piVar9,iVar19);
            if (*(char *)(iVar21 + iVar22 + 0x10) != '\x04') {
              iVar4 = iVar21;
            }
            bVar2 = iVar21 != 3;
            iVar21 = iVar21 + 1;
          } while (bVar2);
          iVar21 = 0;
          do {
            if (*(char *)((int)&local_b8 + iVar21) != '\x04') {
              bVar1 = true;
              (**(code **)(*piVar11 + 0x88))(piVar11,uVar15,iVar21,iVar4);
            }
            bVar2 = iVar21 != 3;
            iVar21 = iVar21 + 1;
          } while (bVar2);
          if (bVar1) goto LAB_00164744;
        }
        iVar4 = piVar9[0x21];
        iVar19 = iVar19 + 1;
      } while (iVar19 <= iVar4);
      if (bVar1) goto LAB_00164744;
    }
    iVar4 = iVar4 + 1;
    piVar9[0x21] = iVar4;
    ((void (*)())FUN_000f79c4)(piVar9,pass,iVar4,0.0,0.0,0.0,0.0);
    iVar19 = IRInst__getOperandRecord(piVar9,iVar4);
    *(undefined4 *)(iVar19 + 0x10) = 0x4040404;
    iVar19 = 0;
    do {
      iVar21 = IRInst__getOperandRecord(piVar9,0);
      if (*(char *)(iVar19 + iVar21 + 0x10) != '\0') {
        (**(code **)(*piVar9 + 0x88))(piVar9,iVar4,iVar19,iVar19);
        *(undefined1 *)((int)piVar9 + iVar19 + 0x9c) = 0;
        goto LAB_00164700;
      }
      bVar1 = iVar19 != 3;
      iVar19 = iVar19 + 1;
    } while (bVar1);
    iVar19 = -1;
LAB_00164700:
    iVar4 = 0;
    do {
      if (*(char *)((int)&local_b8 + iVar4) != '\x04') {
        (**(code **)(*piVar11 + 0x88))(piVar11,uVar15,iVar4,iVar19);
      }
      bVar1 = iVar4 != 3;
      iVar4 = iVar4 + 1;
    } while (bVar1);
  }
LAB_00164744:
  iVar4 = 0;
  do {
    if (*(char *)((int)&local_b4 + iVar4) != '\x01') {
      iVar19 = (**(code **)(*operandVReg + 0x60))(operandVReg);
      if (iVar19 == 0) {
        (**(code **)(*piVar11 + 0x88))(piVar11,uVar13,iVar4,*(undefined1 *)((int)&local_a4 + iVar4))
        ;
      }
      else {
        iVar19 = IRInst__getOperandRecord(operandVReg,0);
        iVar19 = FUN_000f3108(*(undefined4 *)(iVar19 + 0x10));
        (**(code **)(*operandVReg + 0x88))(operandVReg,1,iVar19,*(undefined1 *)((int)&local_a4 + iVar4));
        (**(code **)(*piVar11 + 0x88))(piVar11,uVar13,iVar4,iVar19);
        *(undefined1 *)((int)operandVReg + iVar19 + 0x9c) = 0;
      }
    }
    bVar1 = iVar4 != 3;
    iVar4 = iVar4 + 1;
  } while (bVar1);
  if (*(int *)(pass + 0x478) < operandVReg[0x58]) {
    operandVReg[0x58] = operandVReg[0x58] + 1;
  }
  else {
    operandVReg[0x58] = *(int *)(pass + 0x478) + 1;
  }
  if (local_98 != 0) {
    FUN_00106b48(piVar11,&local_9c,0,*(undefined4 *)(pass + 8));
    if (*(int *)(pass + 0x478) < *(int *)(local_98 + 0x160)) {
      *(int *)(local_98 + 0x160) = *(int *)(local_98 + 0x160) + 1;
    }
    else {
      *(int *)(local_98 + 0x160) = *(int *)(pass + 0x478) + 1;
    }
  }
  piVar11[0x58] = iVar3 + *(int *)(pass + 0x478);
  return 0;
}

/* FUN_001648ac @ 0x1648ac (456 bytes) */
int FUN_001648ac(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  uint param_4;
{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x20) == 0) {
    if (*(int *)(param_1 + 0x24) == 0) {
      iVar1 = *(int *)(param_2 + 0x1c);
      if (iVar1 == *(int *)(param_3 + 0x1c)) {
        iVar1 = *(int *)(param_2 + 0x14) - *(int *)(param_3 + 0x14);
        if (iVar1 != 0) {
          return iVar1;
        }
        iVar1 = *(int *)(param_3 + 0x5c);
        if (*(int *)(param_2 + 0x5c) == iVar1) {
          iVar1 = param_3;
          iVar2 = (**(code **)(**(int **)(param_1 + 8) + 0x60))
                            (*(int **)(param_1 + 8),param_2,param_3,param_4);
          iVar1 = (**(code **)(**(int **)(param_1 + 8) + 0x60))
                            (*(int **)(param_1 + 8),param_3,iVar1,param_4);
          if (iVar2 - iVar1 != 0) {
            return iVar2 - iVar1;
          }
          iVar1 = *(int *)(param_2 + 0xc) - *(int *)(param_3 + 0xc);
          goto joined_r0x00164a48;
        }
      }
    }
    else {
      iVar1 = *(int *)(param_2 + 0x1c);
      if (iVar1 == *(int *)(param_3 + 0x1c)) {
        iVar1 = param_3;
        iVar2 = (**(code **)(**(int **)(param_1 + 8) + 100))
                          (*(int **)(param_1 + 8),param_2,param_3,param_4);
        iVar1 = (**(code **)(**(int **)(param_1 + 8) + 100))
                          (*(int **)(param_1 + 8),param_3,iVar1,param_4);
        if (iVar2 - iVar1 != 0) {
          return iVar2 - iVar1;
        }
        iVar1 = *(int *)(param_2 + 0xc) - *(int *)(param_3 + 0xc);
        if (iVar1 != 0) {
          return iVar1;
        }
        iVar1 = *(int *)(param_2 + 0x14) - *(int *)(param_3 + 0x14);
joined_r0x00164a48:
        if (iVar1 != 0) {
          return iVar1;
        }
        return *(int *)(param_3 + 0x10) - *(int *)(param_2 + 0x10);
      }
    }
  }
  else {
    iVar1 = *(int *)(param_2 + 0x10) - *(int *)(param_3 + 0x10);
    if (iVar1 != 0) {
      return -iVar1;
    }
    iVar1 = *(int *)(param_2 + 0xc) - *(int *)(param_3 + 0xc);
    if (iVar1 != 0) {
      return iVar1;
    }
    iVar1 = *(int *)(param_2 + 0x1c);
    if (iVar1 == *(int *)(param_3 + 0x1c)) {
      iVar1 = *(int *)(param_2 + 0x14) - *(int *)(param_3 + 0x14);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = *(int *)(param_3 + 0x5c);
      if (*(int *)(param_2 + 0x5c) == iVar1) {
        return 0;
      }
    }
  }
  iVar2 = -1;
  if (iVar1 != 0) {
    iVar2 = 1;
  }
  return iVar2;
}

/* FUN_00164a74 @ 0x164a74 (312 bytes) */
int FUN_00164a74(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  
  if (*(int *)(param_1 + 0x118) != 0) {
    iVar1 = FUN_00193f08(param_1 + 0x34);
    if (iVar1 == 0) {
      if ((*(int *)(param_1 + 0x28) <= *(int *)(param_1 + 300)) &&
         (iVar1 = FUN_00193f08(param_1 + 0x4c), iVar1 == 0)) {
        *(uint *)(param_1 + 0x118) = (uint)(*(int *)(param_1 + 0x110) <= param_3);
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x118) = 0;
    }
    if (*(int *)(param_1 + 0x118) != 0) {
      return;
    }
    *(undefined4 *)(param_1 + 0x124) = *(undefined4 *)(param_1 + 0x2c);
    return;
  }
  iVar1 = FUN_00193f08(param_1 + 0x4c);
  if (iVar1 == 0) {
    iVar1 = FUN_00193f08(param_1 + 0x34);
    if ((iVar1 != 0) ||
       ((*(int *)(param_1 + 0x120) < *(int *)(param_1 + 0x11c) &&
        (param_2 < *(int *)(param_1 + 0x28))))) goto LAB_00164b7c;
    iVar1 = *(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x124);
    if (iVar1 < 8) {
      *(uint *)(param_1 + 0x118) = (uint)(*(int *)(param_1 + 0x110) - iVar1 < param_3);
      goto LAB_00164b7c;
    }
  }
  *(undefined4 *)(param_1 + 0x118) = 1;
LAB_00164b7c:
  if (*(int *)(param_1 + 0x118) != 0) {
    *(undefined4 *)(param_1 + 300) = 0;
    *(undefined4 *)(param_1 + 0x128) = *(undefined4 *)(param_1 + 0x120);
  }
  return;
}

/* FUN_00164bac @ 0x164bac (44 bytes) */
int FUN_00164bac(param_1, param_2)
  int param_1;
  int param_2;
{
  if ((*(int *)(param_1 + 0x94) == *(int *)(param_2 + 0x94)) &&
     (*(int *)(param_1 + 0x98) == *(int *)(param_2 + 0x98))) {
    return 0;
  }
  return 0xffffffff;
}

/* FUN_00164bd8 @ 0x164bd8 (20 bytes) */
int FUN_00164bd8(param_1)
  int param_1;
{
  return *(int *)(param_1 + 0x98) * 0x10000 + *(int *)(param_1 + 0x94);
}

/* FUN_00164bec @ 0x164bec (520 bytes) */
int FUN_00164bec(param_1, param_2, param_3, param_4)
  int *param_1;
  undefined4 param_2;
  int param_3;
  int param_4;
{
  unsigned int ghidra_home[8] = { param_1, param_2, param_3, param_4, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  int *piVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  char *pcVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int local_28 [6];
  
  bVar2 = param_4 == 0;
  (*(unsigned int *)((unsigned char *)ghidra_home + 4)) = param_2;
  if (bVar2) {
    iVar13 = 4;
    iVar9 = 0;
    piVar4 = param_1;
    do {
      piVar1 = piVar4 + 0x54;
      piVar4 = piVar4 + 1;
      *(int *)((int)local_28 + iVar9) = *piVar1;
      iVar9 = iVar9 + 4;
      iVar13 = iVar13 + -1;
    } while (iVar13 != 0);
    uVar5 = param_1[0x51];
    iVar9 = param_1[0x68];
  }
  else {
    iVar13 = 4;
    iVar9 = 0;
    piVar4 = param_1;
    do {
      piVar1 = piVar4 + 0x58;
      piVar4 = piVar4 + 1;
      *(int *)((int)local_28 + iVar9) = *piVar1;
      iVar9 = iVar9 + 4;
      iVar13 = iVar13 + -1;
    } while (iVar13 != 0);
    piVar4 = *(int **)(*param_1 + 0x30c);
    uVar5 = (**(code **)(*piVar4 + 0x13c))(piVar4,*param_1);
    iVar9 = param_1[0x69];
  }
  uVar6 = 0xffffffff;
  if (0 < (int)uVar5) {
    iVar13 = 0x7fffffff;
    uVar7 = uVar6;
    uVar8 = 0;
    do {
      uVar6 = uVar8;
      if ((!bVar2) ||
         ((*(uint *)((uVar6 >> 3 & 0x1ffffffc) + param_1[0x4c] + 8) >> (uVar6 & 0x1f) & 1) != 0)) {
        if (iVar9 < (int)uVar6) {
          if (-1 < (int)uVar7) goto LAB_00164d6c;
          break;
        }
        iVar14 = 4;
        iVar11 = 0x7fffffff;
        pcVar10 = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 4));
        iVar12 = 0;
        do {
          if (*pcVar10 != '\0') {
            iVar3 = param_3 - *(int *)(*(int *)((int)local_28 + iVar12) + uVar6 * 4);
            if (iVar3 < iVar11) {
              iVar11 = iVar3;
            }
            if (iVar11 < 0) goto LAB_00164d58;
          }
          pcVar10 = pcVar10 + 1;
          iVar12 = iVar12 + 4;
          iVar14 = iVar14 + -1;
        } while (iVar14 != 0);
        if ((-1 < iVar11) && (iVar11 < iVar13)) {
          uVar7 = uVar6;
          iVar13 = iVar11;
        }
      }
LAB_00164d58:
      uVar8 = uVar6 + 1;
      uVar6 = uVar7;
    } while (uVar5 != uVar8);
    uVar7 = uVar6;
    if (-1 < (int)uVar6) {
LAB_00164d6c:
      uVar6 = uVar7;
      if (bVar2) {
        uVar5 = param_1[0x68];
        if (param_1[0x68] < (int)uVar6) {
          uVar5 = uVar6;
        }
        param_1[0x68] = uVar5;
      }
      else {
        uVar5 = param_1[0x69];
        if (param_1[0x69] < (int)uVar6) {
          uVar5 = uVar6;
        }
        param_1[0x69] = uVar5;
      }
      iVar13 = 4;
      pcVar10 = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 4));
      iVar9 = 0;
      do {
        if (*pcVar10 != '\0') {
          *(int *)(*(int *)((int)local_28 + iVar9) + uVar6 * 4) = param_1[0xb];
        }
        pcVar10 = pcVar10 + 1;
        iVar9 = iVar9 + 4;
        iVar13 = iVar13 + -1;
      } while (iVar13 != 0);
    }
  }
  return uVar6;
}

/* FUN_00164df4 @ 0x164df4 (136 bytes) */
int FUN_00164df4(param_1)
  int *param_1;
{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x7c))(param_1);
  if (iVar1 == 0) {
    if ((param_1[5] & 0x8000U) == 0) {
      iVar1 = param_1[0x22];
    }
    else {
      iVar1 = param_1[0x22];
      if ((*(int *)(iVar1 + 4) != 1) && (param_1[0x21] == 0)) {
        return 1;
      }
    }
    if (*(int *)(iVar1 + 8) != 0xa4) {
      return 0;
    }
  }
  return 1;
}

/* FUN_00164e7c @ 0x164e7c (324 bytes) */
int FUN_00164e7c(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int *param_2;
  int *param_3;
  undefined4 param_4;
  undefined4 param_5;
  int param_6;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_28 [6];
  
  if (param_6 == 0) {
    iVar1 = (**(code **)(**(int **)(param_1 + 8) + 0x54))
                      (*(int **)(param_1 + 8),param_2,param_3,local_28);
    if (iVar1 != 0) {
      return local_28[0];
    }
    if ((((*(int *)(param_2[0x22] + 4) != 1) &&
         ((iVar1 = (**(code **)(*param_3 + 0x54))(param_3), iVar1 == 0 ||
          (iVar1 = FUN_001045e4(param_3), iVar1 != 0)))) &&
        ((iVar1 = (**(code **)(*param_3 + 0x5c))(param_3), iVar1 == 0 ||
         (iVar1 = (**(code **)(*param_2 + 0x28))(param_2), iVar1 == 0)))) &&
       ((iVar1 = (**(code **)(*param_3 + 0x60))(param_3), iVar1 == 0 &&
        (iVar1 = FUN_00104644(param_2), iVar1 == 0)))) {
      uVar2 = (**(code **)(**(int **)(param_1 + 8) + 0x78))(*(int **)(param_1 + 8));
      return uVar2;
    }
  }
  else if (param_6 == 1) {
    return 1;
  }
  return 0;
}

/* FUN_00164fc0 @ 0x164fc0 (84 bytes) */
int FUN_00164fc0(param_1)
  int param_1;
{
  int iVar1;
  
  if ((0 < *(int *)(param_1 + 0x80)) &&
     ((((*(int *)(*(int *)(param_1 + 0x88) + 4) == 1 || ((*(uint *)(param_1 + 0x14) & 0x40) != 0))
       || (iVar1 = *(int *)(param_1 + 0x98), iVar1 == 0x20)) || ((iVar1 == 0x21 || (iVar1 == 0x22)))
      ))) {
    return 1;
  }
  return 0;
}

/* FUN_00165014 @ 0x165014 (1520 bytes) */
int FUN_00165014(param_1)
  int *param_1;
{
  uint *puVar1;
  uint *puVar2;
  bool bVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  undefined4 *allocation;
  int iVar8;
  int iVar9;
  int *piVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  undefined4 *puVar14;
  int *piVar15;
  int *piVar16;
  int iVar17;
  undefined4 arena;
  uint uVar19;
  
  iVar6 = param_1[1];
  iVar17 = *(int *)(iVar6 + 900);
  if (*(int *)(iVar17 + 8) != 0) {
    do {
      iVar6 = param_1[0x51];
      uVar19 = iVar6 + 0x1fU >> 5;
      arena = *(undefined4 *)(*param_1 + 0x378);
      allocation = (undefined4 *)Arena__alloc(arena,uVar19 * 4 + 0xc);
      puVar14 = allocation + 1;
      *allocation = arena;
      allocation[1] = uVar19;
      allocation[2] = iVar6;
      if (uVar19 != 0) {
        allocation = puVar14;
        if (uVar19 == 0) {
          uVar19 = 1;
        }
        do {
          allocation[2] = 0;
          allocation = allocation + 1;
          uVar19 = uVar19 - 1;
        } while (uVar19 != 0);
      }
      *(undefined4 **)(iVar17 + 0x104) = puVar14;
      iVar6 = param_1[0x51];
      uVar19 = iVar6 + 0x1fU >> 5;
      arena = *(undefined4 *)(*param_1 + 0x378);
      allocation = (undefined4 *)Arena__alloc(arena,uVar19 * 4 + 0xc);
      puVar14 = allocation + 1;
      *allocation = arena;
      allocation[1] = uVar19;
      allocation[2] = iVar6;
      if (uVar19 != 0) {
        allocation = puVar14;
        if (uVar19 == 0) {
          uVar19 = 1;
        }
        do {
          allocation[2] = 0;
          allocation = allocation + 1;
          uVar19 = uVar19 - 1;
        } while (uVar19 != 0);
      }
      *(undefined4 **)(iVar17 + 0x100) = puVar14;
      *(undefined4 *)(iVar17 + 0x118) = *(undefined4 *)(param_1[1] + 0x474);
      iVar17 = *(int *)(iVar17 + 8);
    } while (*(int *)(iVar17 + 8) != 0);
    iVar6 = param_1[1];
  }
  *(int *)(iVar6 + 0x474) = *(int *)(iVar6 + 0x474) + 1;
  iVar8 = param_1[1];
  iVar6 = *(int *)(*(int *)(iVar8 + 900) + 8);
  iVar17 = *(int *)(iVar8 + 900);
  if (iVar6 != 0) {
    do {
      iVar8 = iVar6;
      piVar5 = (int *)(*(int **)(iVar17 + 0x98))[2];
      piVar16 = *(int **)(iVar17 + 0x98);
      if (piVar5 != (int *)0x0) {
        do {
          piVar10 = piVar5;
          if (((piVar16[5] & 1U) != 0) && (0 < piVar16[0x21])) {
            iVar8 = 1;
            uVar19 = 0;
            iVar6 = 0;
            do {
              piVar5 = (int *)IRInst__getOperandSource(piVar16,iVar8);
              if (((piVar5[5] & 0x40U) == 0) || (iVar9 = FUN_00126760(piVar5[0x26]), iVar9 == 0)) {
                iVar9 = (**(code **)(*piVar5 + 0x5c))(piVar5);
                if (((iVar9 != 0) || (iVar9 = (**(code **)(*piVar5 + 0x60))(piVar5), iVar9 != 0)) &&
                   (0 < piVar5[0x21])) {
                  iVar9 = 1;
                  do {
                    piVar10 = (int *)IRInst__getOperandSource(piVar5,iVar9);
                    iVar11 = (**(code **)(*piVar10 + 0x5c))(piVar10);
                    if (iVar11 == 0) {
                      if (((piVar10[5] & 0x40U) != 0) &&
                         (iVar11 = FUN_00126760(piVar10[0x26]), iVar11 != 0)) {
                        iVar11 = (**(code **)(*piVar16 + 0x7c))(piVar16);
                        if (iVar11 == 0) {
                          uVar4 = piVar10[0x25];
                          iVar11 = (uVar4 >> 3 & 0x1ffffffc) + *(int *)(iVar17 + 0x100);
                        }
                        else {
                          piVar15 = (int *)0x0;
                          if (uVar19 < *(uint *)(*(int *)(iVar17 + 0xd4) + 4)) {
                            piVar15 = (int *)(iVar6 + *(int *)(*(int *)(iVar17 + 0xd4) + 8));
                          }
                          uVar4 = piVar10[0x25];
                          iVar11 = (uVar4 >> 3 & 0x1ffffffc) + *(int *)(*piVar15 + 0x104);
                        }
                        *(uint *)(iVar11 + 8) = 1 << (uVar4 & 0x1f) | *(uint *)(iVar11 + 8);
                      }
                    }
                    else if (0 < piVar10[0x21]) {
                      iVar11 = 1;
                      do {
                        iVar12 = IRInst__getOperandSource(piVar10,iVar11);
                        if (((*(uint *)(iVar12 + 0x14) & 0x40) != 0) &&
                           (iVar13 = FUN_00126760(*(undefined4 *)(iVar12 + 0x98)), iVar13 != 0)) {
                          iVar13 = (**(code **)(*piVar16 + 0x7c))(piVar16);
                          if (iVar13 == 0) {
                            uVar4 = *(uint *)(iVar12 + 0x94);
                            iVar12 = (uVar4 >> 3 & 0x1ffffffc) + *(int *)(iVar17 + 0x100);
                          }
                          else {
                            piVar15 = (int *)0x0;
                            if (uVar19 < *(uint *)(*(int *)(iVar17 + 0xd4) + 4)) {
                              piVar15 = (int *)(iVar6 + *(int *)(*(int *)(iVar17 + 0xd4) + 8));
                            }
                            uVar4 = *(uint *)(iVar12 + 0x94);
                            iVar12 = (uVar4 >> 3 & 0x1ffffffc) + *(int *)(*piVar15 + 0x104);
                          }
                          *(uint *)(iVar12 + 8) = 1 << (uVar4 & 0x1f) | *(uint *)(iVar12 + 8);
                        }
                        iVar11 = iVar11 + 1;
                      } while (iVar11 <= piVar10[0x21]);
                    }
                    iVar9 = iVar9 + 1;
                  } while (iVar9 <= piVar5[0x21]);
                }
              }
              else {
                iVar9 = (**(code **)(*piVar16 + 0x7c))(piVar16);
                if (iVar9 == 0) {
                  uVar4 = piVar5[0x25];
                  iVar9 = (uVar4 >> 3 & 0x1ffffffc) + *(int *)(iVar17 + 0x100);
                }
                else {
                  piVar10 = (int *)0x0;
                  if (uVar19 < *(uint *)(*(int *)(iVar17 + 0xd4) + 4)) {
                    piVar10 = (int *)(iVar6 + *(int *)(*(int *)(iVar17 + 0xd4) + 8));
                  }
                  uVar4 = piVar5[0x25];
                  iVar9 = (uVar4 >> 3 & 0x1ffffffc) + *(int *)(*piVar10 + 0x104);
                }
                *(uint *)(iVar9 + 8) = 1 << (uVar4 & 0x1f) | *(uint *)(iVar9 + 8);
              }
              iVar8 = iVar8 + 1;
              uVar19 = uVar19 + 1;
              iVar6 = iVar6 + 4;
            } while (iVar8 <= piVar16[0x21]);
            piVar10 = (int *)piVar16[2];
          }
          piVar5 = (int *)piVar10[2];
          piVar16 = piVar10;
        } while ((int *)piVar10[2] != (int *)0x0);
        iVar8 = *(int *)(iVar17 + 8);
      }
      iVar6 = *(int *)(iVar8 + 8);
      iVar17 = iVar8;
    } while (*(int *)(iVar8 + 8) != 0);
    iVar8 = param_1[1];
  }
  iVar6 = FUN_000ec5b8(iVar8);
  do {
    bVar3 = false;
    for (iVar17 = 1; iVar8 = DList__count(param_1[1] + 0x37c), iVar17 <= iVar8; iVar17 = iVar17 + 1)
    {
      piVar5 = *(int **)(iVar6 + iVar17 * 4);
      iVar8 = (**(code **)(*piVar5 + 0x20))(piVar5);
      if (iVar8 == 0) {
        iVar8 = 0;
        for (uVar19 = 1; uVar19 <= *(uint *)(piVar5[0x34] + 4); uVar19 = uVar19 + 1) {
          iVar9 = *(int *)(*(int *)(piVar5[0x34] + 8) + iVar8);
          if (iVar9 != 0) {
            piVar16 = (int *)piVar5[0x41];
            iVar11 = *(int *)(iVar9 + 0x100);
            iVar9 = *piVar16;
            if (iVar9 != 0) {
              if (iVar9 == 0) {
                iVar9 = 1;
              }
              do {
                puVar1 = (uint *)(iVar11 + 8);
                iVar11 = iVar11 + 4;
                piVar16[2] = piVar16[2] | *puVar1;
                piVar16 = piVar16 + 1;
                iVar9 = iVar9 + -1;
              } while (iVar9 != 0);
            }
          }
          iVar8 = iVar8 + 4;
        }
        piVar16 = (int *)piVar5[0x40];
        iVar8 = piVar5[0x41];
        iVar9 = *piVar16;
        if (iVar9 != 0) {
          iVar11 = iVar8;
          piVar5 = piVar16;
          iVar12 = iVar9;
          if ((piVar16[2] | *(uint *)(iVar8 + 8)) == piVar16[2]) {
            do {
              if (iVar12 + -1 == 0) goto LAB_001655a8;
              puVar1 = (uint *)(piVar5 + 3);
              puVar2 = (uint *)(iVar11 + 0xc);
              iVar11 = iVar11 + 4;
              piVar5 = piVar5 + 1;
              iVar12 = iVar12 + -1;
            } while ((*puVar1 | *puVar2) == *puVar1);
          }
          if (iVar9 != 0) {
            if (iVar9 == 0) {
              iVar9 = 1;
            }
            do {
              puVar1 = (uint *)(iVar8 + 8);
              iVar8 = iVar8 + 4;
              piVar16[2] = piVar16[2] | *puVar1;
              piVar16 = piVar16 + 1;
              iVar9 = iVar9 + -1;
            } while (iVar9 != 0);
          }
          bVar3 = true;
        }
      }
LAB_001655a8: ;
    }
    if (!bVar3) {
      return;
    }
  } while( true );
}

/* FUN_00165604 @ 0x165604 (388 bytes) */
int FUN_00165604(param_1, inst)
  int param_1;
  int *inst;
{
  int loopIndex;
  int iVar1;
  int iVar2;
  int loopIndex2;
  int iVar4;
  int *piVar5;
  
  loopIndex2 = 0;
  do {
    iVar1 = loopIndex2 * 4 + param_1;
    piVar5 = *(int **)(iVar1 + 0x10);
    if (piVar5 == (int *)0x0) {
      *(int **)(iVar1 + 0x10) = inst;
      return inst;
    }
    if (((*(int *)(piVar5[0x22] + 8) == *(int *)(inst[0x22] + 8)) &&
        (piVar5[0x48] == inst[0x48])) && (piVar5[0x49] == inst[0x49])) {
      iVar1 = IRInst__getOperandRecord(piVar5,0);
      iVar4 = *(int *)(iVar1 + 0x10);
      iVar1 = IRInst__getOperandRecord(inst,0);
      if (iVar4 == *(int *)(iVar1 + 0x10)) {
        loopIndex = 1;
        while( true ) {
          iVar4 = (**(code **)(*piVar5 + 0x14))(piVar5);
          if (iVar4 < loopIndex) {
            return piVar5;
          }
          iVar4 = IRInst__getOperandSource(piVar5,loopIndex);
          iVar2 = IRInst__getOperandSource(inst,loopIndex);
          if (iVar4 != iVar2) break;
          if (((piVar5[loopIndex * 6 + 0x28] & 1U) != (inst[loopIndex * 6 + 0x28] & 1U)) ||
             (((uint)piVar5[loopIndex * 6 + 0x28] >> 1 & 1) !=
              ((uint)inst[loopIndex * 6 + 0x28] >> 1 & 1))) break;
          iVar4 = IRInst__getOperandRecord(piVar5,loopIndex);
          iVar2 = *(int *)(iVar4 + 0x10);
          iVar4 = IRInst__getOperandRecord(inst,loopIndex);
          if (iVar2 != *(int *)(iVar4 + 0x10)) break;
          loopIndex = loopIndex + 1;
        }
      }
    }
    loopIndex2 = loopIndex2 + 1;
    if (0x1f < loopIndex2) {
      return inst;
    }
  } while( true );
}

/* FUN_00165788 @ 0x165788 (628 bytes) */
int FUN_00165788(inst, param_2)
  int *inst;
  undefined4 param_2;
{
  int *operandVReg;
  int *operandVReg2;
  undefined4 uVar3;
  int operandRecord;
  int iVar5;
  int loopIndex;
  int iVar7;
  undefined4 uVar8;
  
  loopIndex = 1;
  do {
    iVar5 = (**(code **)(*inst + 0x14))(inst);
    if (iVar5 < loopIndex) {
      return;
    }
    operandVReg = (int *)IRInst__getOperandSource(inst,loopIndex);
    iVar5 = (**(code **)(*inst + 0x60))(inst);
    if ((iVar5 == 0) && (iVar5 = (**(code **)(*operandVReg + 0x5c))(operandVReg), iVar5 != 0)) {
LAB_00165840:
      iVar7 = 1;
      iVar5 = (**(code **)(*operandVReg + 0x60))(operandVReg);
      if ((iVar5 != 0) || (iVar7 = (**(code **)(*operandVReg + 0x14))(operandVReg), 0 < iVar7)) {
        iVar5 = 1;
        do {
          uVar3 = IRInst__getOperandSource(operandVReg,iVar5);
          uVar3 = (**(code **)(*inst + 0x94))(inst,uVar3,param_2);
          operandRecord = IRInst__getOperandRecord(operandVReg,iVar5);
          iVar5 = iVar5 + 1;
          uVar8 = *(undefined4 *)(operandRecord + 0x10);
          operandRecord = IRInst__getOperandRecord(inst,uVar3);
          *(undefined4 *)(operandRecord + 0x10) = uVar8;
        } while (iVar5 <= iVar7);
      }
    }
    else {
      iVar5 = (**(code **)(*operandVReg + 0x60))(operandVReg);
      if (iVar5 != 0) {
        operandVReg2 = (int *)IRInst__getOperandSource(operandVReg,1);
        iVar5 = (**(code **)(*operandVReg2 + 0x5c))(operandVReg2);
        if (iVar5 == 0) goto LAB_00165840;
      }
      iVar5 = (**(code **)(*operandVReg + 0x60))(operandVReg);
      if (iVar5 != 0) {
        operandVReg2 = (int *)IRInst__getOperandSource(operandVReg,1);
        iVar5 = (**(code **)(*operandVReg2 + 0x5c))(operandVReg2);
        if (iVar5 != 0) {
          operandVReg = (int *)IRInst__getOperandSource(operandVReg,1);
          for (iVar5 = 1; iVar7 = (**(code **)(*operandVReg + 0x14))(operandVReg), iVar5 <= iVar7;
              iVar5 = iVar5 + 1) {
            uVar3 = IRInst__getOperandSource(operandVReg,iVar5);
            uVar3 = (**(code **)(*inst + 0x94))(inst,uVar3,param_2);
            iVar7 = IRInst__getOperandRecord(operandVReg,iVar5);
            uVar8 = *(undefined4 *)(iVar7 + 0x10);
            iVar7 = IRInst__getOperandRecord(inst,uVar3);
            *(undefined4 *)(iVar7 + 0x10) = uVar8;
          }
        }
      }
    }
    loopIndex = loopIndex + 1;
  } while( true );
}

/* FUN_001659fc @ 0x1659fc (384 bytes) */
int FUN_001659fc(param_1, param_2)
  int *param_1;
  int param_2;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  int *piVar7;
  int iVar8;
  
  piVar7 = *(int **)(param_2 + 0x38);
  if (((((piVar7[5] & 0x20U) == 0) && (piVar7[0x20] != 0)) &&
      (iVar3 = FUN_00126760(piVar7[0x26]), iVar3 != 0)) && ((piVar7[5] & 2U) == 0)) {
    (**(code **)(*piVar7 + 0x50))(piVar7);
  }
  pcVar4 = *(char **)(param_2 + 0x60);
  if (pcVar4 == (char *)0x0) {
    iVar2 = *(int *)(param_2 + 0x38);
    iVar8 = 4;
    iVar3 = param_2;
    do {
      if ((*(char *)(iVar2 + 0xc) != '\0') && (0 < *(int *)(iVar3 + 0x48))) {
        return;
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 4;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
    iVar3 = *(int *)(*param_1 + 0x3c4) + 1;
    *(int *)(*param_1 + 0x3c4) = iVar3;
    *(int *)(*(int *)(param_2 + 0x38) + 0x94) = iVar3;
    *(uint *)(*(int *)(param_2 + 0x38) + 0x14) =
         *(uint *)(*(int *)(param_2 + 0x38) + 0x14) & 0xffffffbf;
  }
  else {
    iVar2 = 4;
    iVar3 = 0;
    pcVar5 = pcVar4;
    pcVar6 = pcVar4;
    do {
      if (((*pcVar5 != '\0') && (*(int *)(pcVar6 + 0x18) != 0)) &&
         (0 < *(int *)(iVar3 * 4 + *(int *)(pcVar6 + 0x18) + 0x48))) {
        return;
      }
      iVar3 = iVar3 + 1;
      pcVar5 = pcVar5 + 1;
      pcVar6 = pcVar6 + 4;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    iVar2 = *(int *)(*param_1 + 0x3c4) + 1;
    *(int *)(*param_1 + 0x3c4) = iVar2;
    for (iVar3 = *(int *)(*(int *)(pcVar4 + 8) + 0x38); iVar3 != 0;
        iVar3 = IRInst__getOperandSource(iVar3,*(undefined4 *)(iVar3 + 0x84))) {
      uVar1 = *(uint *)(iVar3 + 0x14);
      *(int *)(iVar3 + 0x94) = iVar2;
      *(uint *)(iVar3 + 0x14) = uVar1 & 0xffffffbf;
      if ((uVar1 & 0x200) == 0) {
        return;
      }
    }
  }
  return;
}

/* FUN_00165b7c @ 0x165b7c (448 bytes) */
int FUN_00165b7c(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int *param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  uint param_7;
{
  unsigned int ghidra_home[8] = { param_1, param_2, param_3, param_4, param_5, param_6, param_7, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  undefined4 *allocation;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 a2;
  undefined4 a3;
  undefined4 a5;
  undefined4 a6;
  char *pcVar4;
  uint uVar5;
  uint *puVar6;
  undefined4 arena;
  int iVar8;
  
  arena = *(undefined4 *)(*param_1 + 0x378);
  (*(unsigned int *)((unsigned char *)ghidra_home + 20)) = param_6;
  allocation = (undefined4 *)Arena__alloc(arena,0x24);
  a6 = 0x1010101;
  *allocation = arena;
  allocation[4] = 1;
  a3 = 0;
  allocation[7] = 0x1010101;
  a5 = 0;
  allocation[1] = param_2;
  allocation[3] = 0;
  allocation[5] = 0;
  allocation[6] = 0;
  allocation[8] = 0;
  allocation[2] = param_3;
  a2 = *(undefined4 *)(param_3 + 0x38);
  arena = param_4;
  uVar2 = ((int (*)())FUN_00164e7c)(param_1,*(undefined4 *)(param_2 + 0x38),a2,0,param_4,0);
  allocation[5] = param_4;
  allocation[4] = uVar2;
  allocation[6] = param_5;
  arena = (**(code **)(*(int *)param_1[3] + 0x20))
                    ((int *)param_1[3],*(undefined4 *)(param_2 + 0x38),a2,a3,arena,a5,a6);
  allocation[8] = arena;
  allocation[7] = (*(unsigned int *)((unsigned char *)ghidra_home + 20));
  puVar6 = *(uint **)(param_2 + 0x40);
  uVar5 = puVar6[1];
  if (uVar5 < *puVar6) {
    _memset(uVar5 * 4 + puVar6[2],0,4);
    puVar3 = (undefined4 *)(uVar5 * 4 + puVar6[2]);
    puVar6[1] = uVar5 + 1;
  }
  else {
    puVar3 = (undefined4 *)Vector__elementRefGrow(puVar6,uVar5);
  }
  *puVar3 = allocation + 1;
  puVar6 = *(uint **)(param_3 + 0x44);
  uVar5 = puVar6[1];
  if (uVar5 < *puVar6) {
    _memset(uVar5 * 4 + puVar6[2],0,4);
    puVar3 = (undefined4 *)(uVar5 * 4 + puVar6[2]);
    puVar6[1] = uVar5 + 1;
  }
  else {
    puVar3 = (undefined4 *)Vector__elementRefGrow(puVar6,uVar5);
  }
  *puVar3 = allocation + 1;
  iVar8 = 4;
  pcVar4 = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 20));
  do {
    if (*pcVar4 != '\0') {
      *(int *)(param_2 + 0x48) = *(int *)(param_2 + 0x48) + 1;
    }
    pcVar4 = pcVar4 + 1;
    param_2 = param_2 + 4;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  *(int *)(param_3 + 0x34) = *(int *)(param_3 + 0x34) + 1;
  return;
}

/* FUN_00165d3c @ 0x165d3c (504 bytes) */
int FUN_00165d3c(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  undefined4 *param_3;
  undefined4 param_4;
{
  undefined4 arenaAt378;
  undefined4 *vectorAlloc;
  undefined *puVar1;
  undefined *puVar2;
  undefined4 *allocation;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uVar8;
  undefined4 uVar9;
  uint *puVar10;
  undefined4 arena;
  undefined4 *puVar12;
  int iVar13;
  
  uVar9 = *(undefined4 *)(param_1[6] + 4);
  *(undefined4 *)(param_2 + 0x150) = uVar9;
  arena = *(undefined4 *)(*param_1 + 0x378);
  allocation = (undefined4 *)Arena__alloc(arena,0x74);
  puVar1 = PTR_DAT_001e9138;
  puVar12 = allocation + 1;
  puVar2 = PTR_DAT_001e8b48 + 8;
  *allocation = arena;
  allocation[1] = puVar2;
  allocation[0xc] = 0xffffffff;
  allocation[1] = puVar1 + 8;
  allocation[0x10] = uVar9;
  iVar13 = 4;
  allocation[0x1c] = 0;
  allocation[2] = 0;
  allocation[3] = 0;
  allocation[0xd] = 0;
  allocation[0xe] = 0;
  allocation[0xf] = param_2;
  allocation[0x11] = 0;
  allocation[0x12] = 0;
  allocation[0x17] = 0;
  allocation[0x18] = 0;
  allocation[0x19] = 0;
  allocation[0x1a] = 0;
  allocation[0x1b] = 0;
  puVar4 = puVar12;
  do {
    puVar4[0x12] = 0;
    puVar4 = puVar4 + 1;
    iVar13 = iVar13 + -1;
  } while (iVar13 != 0);
  allocation[4] = 0;
  allocation[7] = 1;
  allocation[5] = 0;
  allocation[6] = 1;
  allocation[8] = 0;
  allocation[9] = 0;
  allocation[10] = 0;
  allocation[0xb] = 0;
  uVar9 = (**(code **)(*(int *)param_1[2] + 0x4c))((int *)param_1[2],param_2);
  allocation[0x17] = uVar9;
  arenaAt378 = *(undefined4 *)(*param_1 + 0x378);
  vectorAlloc = (undefined4 *)Arena__alloc(arenaAt378,0x14);
  *vectorAlloc = arenaAt378;
  vectorAlloc[1] = 2;
  vectorAlloc[4] = arenaAt378;
  vectorAlloc[2] = 0;
  uVar9 = Arena__alloc(arenaAt378,8);
  vectorAlloc[3] = uVar9;
  allocation[0x12] = vectorAlloc + 1;
  arenaAt378 = *(undefined4 *)(*param_1 + 0x378);
  vectorAlloc = (undefined4 *)Arena__alloc(arenaAt378,0x14);
  *vectorAlloc = arenaAt378;
  vectorAlloc[1] = 2;
  vectorAlloc[4] = arenaAt378;
  vectorAlloc[2] = 0;
  uVar9 = Arena__alloc(arenaAt378,8);
  vectorAlloc[3] = uVar9;
  allocation[0x11] = vectorAlloc + 1;
  allocation[0xc] = 0xffffffff;
  allocation[0xe] = 0;
  allocation[0xd] = param_4;
  arena = param_3[7];
  uVar9 = param_3[1];
  uVar5 = param_3[2];
  uVar7 = param_3[5];
  uVar6 = param_3[6];
  allocation[4] = *param_3;
  allocation[5] = uVar9;
  allocation[6] = uVar5;
  allocation[9] = uVar7;
  allocation[10] = uVar6;
  allocation[0xb] = arena;
  puVar10 = (uint *)param_1[6];
  uVar8 = puVar10[1];
  if (uVar8 < *puVar10) {
    _memset((void *)(uVar8 * 4 + puVar10[2]),0,4);
    puVar10[1] = uVar8 + 1;
    puVar4 = (undefined4 *)(uVar8 * 4 + puVar10[2]);
  }
  else {
    puVar4 = (undefined4 *)Vector__elementRefGrow(puVar10,uVar8);
  }
  *puVar4 = puVar12;
  FUN_00172078(param_1[2],puVar12);
  return puVar12;
}

/* FUN_00165fa8 @ 0x165fa8 (632 bytes) */
int FUN_00165fa8(param_1, param_2)
  int *param_1;
  int param_2;
{
  undefined4 *vectorAlloc;
  undefined *puVar1;
  undefined *puVar2;
  int *piVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *allocation;
  uint loopIndex;
  undefined4 *puVar8;
  uint *puVar9;
  undefined4 arena;
  uint uVar11;
  uint *puVar12;
  int iVar13;
  
  uVar11 = ((uint *)param_1[5])[1];
  uVar4 = 0;
  if (uVar11 != 0) {
    loopIndex = 0;
    puVar12 = (uint *)param_1[5];
    uVar4 = uVar11;
    do {
      if (loopIndex < *puVar12) {
        puVar9 = puVar12;
        if (uVar4 <= loopIndex) {
          _memset(uVar4 * 4 + puVar12[2],0,(loopIndex - uVar4) * 4 + 4);
          puVar12[1] = loopIndex + 1;
          puVar9 = (uint *)param_1[5];
        }
        piVar3 = (int *)(loopIndex * 4 + puVar12[2]);
      }
      else {
        piVar3 = (int *)Vector__elementRefGrow(puVar12,loopIndex);
        puVar9 = (uint *)param_1[5];
      }
      if (param_2 == *(int *)(*piVar3 + 0x38)) {
        if (loopIndex < *puVar9) {
          uVar4 = puVar9[1];
          if (uVar4 <= loopIndex) {
            _memset(uVar4 * 4 + puVar9[2],0,(loopIndex - uVar4) * 4 + 4);
            puVar9[1] = loopIndex + 1;
          }
          puVar5 = (undefined4 *)(loopIndex * 4 + puVar9[2]);
        }
        else {
          puVar5 = (undefined4 *)Vector__elementRefGrow(puVar9,loopIndex);
        }
        return (undefined4 *)*puVar5;
      }
      uVar4 = puVar9[1];
      loopIndex = loopIndex + 1;
      puVar12 = puVar9;
    } while (loopIndex < uVar4);
  }
  arena = *(undefined4 *)(*param_1 + 0x378);
  allocation = (undefined4 *)Arena__alloc(arena,0x74);
  puVar1 = PTR_DAT_001e9138;
  puVar8 = allocation + 1;
  puVar2 = PTR_DAT_001e8b48 + 8;
  *allocation = arena;
  allocation[1] = puVar2;
  allocation[0xc] = 0xffffffff;
  allocation[1] = puVar1 + 8;
  allocation[0xf] = param_2;
  iVar13 = 4;
  allocation[0x10] = uVar4;
  allocation[0x1c] = 0;
  allocation[2] = 0;
  allocation[3] = 0;
  allocation[0xd] = 0;
  allocation[0xe] = 0;
  allocation[0x11] = 0;
  allocation[0x12] = 0;
  allocation[0x17] = 0;
  allocation[0x18] = 0;
  allocation[0x19] = 0;
  allocation[0x1a] = 0;
  allocation[0x1b] = 0;
  puVar5 = puVar8;
  do {
    puVar5[0x12] = 0;
    puVar5 = puVar5 + 1;
    iVar13 = iVar13 + -1;
  } while (iVar13 != 0);
  allocation[4] = 0;
  allocation[7] = 1;
  allocation[5] = 0;
  allocation[6] = 1;
  allocation[8] = 0;
  allocation[9] = 0;
  allocation[10] = 0;
  allocation[0xb] = 0;
  arena = *(undefined4 *)(*param_1 + 0x378);
  vectorAlloc = (undefined4 *)Arena__alloc(arena,0x14);
  *vectorAlloc = arena;
  vectorAlloc[1] = 2;
  vectorAlloc[4] = arena;
  vectorAlloc[2] = 0;
  arena = Arena__alloc(arena,8);
  vectorAlloc[3] = arena;
  allocation[0x12] = vectorAlloc + 1;
  arena = *(undefined4 *)(*param_1 + 0x378);
  vectorAlloc = (undefined4 *)Arena__alloc(arena,0x14);
  *vectorAlloc = arena;
  vectorAlloc[1] = 2;
  vectorAlloc[4] = arena;
  vectorAlloc[2] = 0;
  arena = Arena__alloc(arena,8);
  vectorAlloc[3] = arena;
  allocation[0x11] = vectorAlloc + 1;
  allocation[0xc] = 0;
  puVar12 = (uint *)param_1[5];
  uVar4 = puVar12[1];
  if (uVar4 < *puVar12) {
    _memset(uVar4 * 4 + puVar12[2],0,4);
    piVar3 = (int *)(uVar4 * 4 + puVar12[2]);
    puVar12[1] = uVar4 + 1;
  }
  else {
    piVar3 = (int *)Vector__elementRefGrow(puVar12,uVar4);
  }
  *piVar3 = (int)puVar8;
  return puVar8;
}

/* FUN_0016629c @ 0x16629c (1448 bytes) */
int FUN_0016629c(param_1)
  undefined4 *param_1;
{
  uint loopIndex;
  uint loopIndex2;
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  uint uVar10;
  uint loopIndex3;
  uint uVar12;
  int iVar13;
  int *piVar14;
  uint uVar15;
  uint uVar16;
  uint *puVar17;
  int iVar18;
  int iVar19;
  int local_58 [4];
  int local_48 [4];
  
  piVar14 = (int *)0x0;
  iVar13 = param_1[0x27];
  do {
    while( true ) {
      if (*(int *)(iVar13 + 8) == 0) {
        if (piVar14 != (int *)0x0) {
          (**(code **)(*piVar14 + 4))(piVar14);
        }
        return 0;
      }
      iVar2 = (**(code **)(**(int **)(iVar13 + 0x38) + 0x14))(*(int **)(iVar13 + 0x38));
      if (1 < iVar2) break;
LAB_00166334:
      iVar2 = *(int *)(iVar13 + 8);
      DList__unlink(iVar13);
      iVar13 = iVar2;
    }
    iVar7 = 0;
    local_58[0] = 0x1010101;
    iVar18 = 4;
    iVar2 = iVar13;
    do {
      if (0 < *(int *)(iVar2 + 0x48)) {
        *(undefined1 *)((int)local_58 + iVar7) = 0;
      }
      iVar7 = iVar7 + 1;
      iVar2 = iVar2 + 4;
      iVar18 = iVar18 + -1;
    } while (iVar18 != 0);
    if (local_58[0] == 0x1010101) goto LAB_00166334;
    iVar2 = *(int *)(iVar13 + 0x38);
    if (piVar14 == (int *)0x0) {
      piVar14 = IRInst__create(0x12,*param_1);
    }
    iVar18 = piVar14[0x53];
    iVar7 = IRInst__getOperandRecord(piVar14,0);
    *(undefined4 *)(iVar7 + 0xc) = 0;
    *(int *)(iVar7 + 8) = iVar18;
    iVar7 = IRInst__getOperandRecord(iVar2,0);
    piVar14[0x27] = *(int *)(iVar7 + 0x10);
    iVar7 = IRInst__getOperandRecord(piVar14,0);
    FUN_000f3908(local_48,*(undefined4 *)(iVar7 + 0x10));
    piVar14[3] = local_48[0];
    uVar3 = IRInst__getOperandSource(iVar2,1);
    IRInst__setOperandSource(piVar14,1,uVar3,0,*param_1);
    iVar7 = IRInst__getOperandRecord(iVar2,1);
    uVar3 = *(undefined4 *)(iVar7 + 0x10);
    iVar7 = IRInst__getOperandRecord(piVar14,1);
    *(undefined4 *)(iVar7 + 0x10) = uVar3;
    uVar3 = IRInst__getOperandSource(iVar2,2);
    IRInst__setOperandSource(piVar14,2,uVar3,0,*param_1);
    iVar7 = IRInst__getOperandRecord(iVar2,2);
    uVar3 = *(undefined4 *)(iVar7 + 0x10);
    iVar7 = IRInst__getOperandRecord(piVar14,2);
    *(undefined4 *)(iVar7 + 0x10) = uVar3;
    IROperand__setModifierBits(piVar14 + 0x2f,1,(uint)(*(int *)(*(int *)(iVar2 + 0x88) + 8) == 0x9a));
    iVar2 = (**(code **)(*(int *)param_1[2] + 0xc))((int *)param_1[2],piVar14);
    if (iVar2 != 0) {
      *(int **)(iVar13 + 0x38) = piVar14;
      *(undefined4 *)(iVar13 + 0x2c) = 0xffffffff;
      uVar3 = (**(code **)(*(int *)param_1[2] + 0x4c))((int *)param_1[2],piVar14);
      *(undefined4 *)(iVar13 + 0x58) = uVar3;
      iVar2 = Compiler__isOptionEnabled(*param_1,0x28);
      if (iVar2 != 0) {
        iVar2 = (**(code **)(*(int *)param_1[2] + 0x34))((int *)param_1[2],iVar13);
        uVar3 = 1;
        if (iVar2 != 0) goto LAB_001664ec;
      }
      uVar3 = 0;
LAB_001664ec:
      *(undefined4 *)(iVar13 + 0x5c) = uVar3;
      loopIndex = 0;
      FUN_00172078(param_1[2],iVar13);
      puVar17 = *(uint **)(iVar13 + 0x44);
      uVar12 = puVar17[1];
      if (0 < (int)uVar12) {
        while( true ) {
          if (loopIndex < *puVar17) {
            uVar10 = puVar17[1];
            if (uVar10 <= loopIndex) {
              _memset(uVar10 * 4 + puVar17[2],0,(loopIndex - uVar10) * 4 + 4);
              puVar17[1] = loopIndex + 1;
            }
            puVar4 = (undefined4 *)(loopIndex * 4 + puVar17[2]);
          }
          else {
            puVar4 = (undefined4 *)Vector__elementRefGrow(puVar17,loopIndex);
          }
          loopIndex = loopIndex + 1;
          piVar14 = (int *)*puVar4;
          if (piVar14[2] == 0) {
            iVar7 = *piVar14;
            iVar18 = 4;
            iVar2 = iVar7;
            piVar9 = piVar14;
            do {
              if (*(char *)(piVar9 + 6) != '\0') {
                *(int *)(iVar2 + 0x48) = *(int *)(iVar2 + 0x48) + 1;
              }
              piVar9 = (int *)((int)piVar9 + 1);
              iVar2 = iVar2 + 4;
              iVar18 = iVar18 + -1;
            } while (iVar18 != 0);
            iVar2 = (**(code **)(*(int *)param_1[3] + 0x20))
                              ((int *)param_1[3],*(undefined4 *)(iVar7 + 0x38));
            piVar14[7] = iVar2;
          }
          if (uVar12 == loopIndex) break;
          puVar17 = *(uint **)(iVar13 + 0x44);
        }
      }
      puVar17 = *(uint **)(iVar13 + 0x40);
      uVar12 = puVar17[1];
      uVar15 = uVar12 - 1;
      if (-1 < (int)uVar15) {
        iVar2 = uVar15 * 4;
        loopIndex2 = 0;
        while( true ) {
          if (uVar15 < *puVar17) {
            uVar5 = puVar17[1];
            if (uVar5 <= uVar15) {
              _memset(uVar5 * 4 + puVar17[2],0,(uVar15 - uVar5) * 4 + 4);
              puVar17[1] = uVar15 + 1;
            }
            piVar14 = (int *)(iVar2 + puVar17[2]);
          }
          else {
            piVar14 = (int *)Vector__elementRefGrow(puVar17,uVar15);
          }
          iVar7 = *piVar14;
          iVar18 = *(int *)(iVar7 + 4);
          if (*(int *)(iVar18 + 0x2c) < 0) {
            if (*(int *)(iVar7 + 8) == 0) {
              IRInst__setOperandSource(*(undefined4 *)(iVar18 + 0x38),*(undefined4 *)(iVar7 + 0x10),
                           *(undefined4 *)(iVar13 + 0x38),0,*param_1);
              iVar1 = *(int *)(iVar18 + 0x34);
              if (iVar1 == 0) {
                DList__unlink(iVar18);
                iVar1 = *(int *)(iVar18 + 0x34);
              }
              puVar17 = *(uint **)(iVar18 + 0x44);
              *(int *)(iVar18 + 0x34) = iVar1 + 1;
              uVar5 = puVar17[1];
              uVar16 = uVar5 - 1;
              if (-1 < (int)uVar16) {
                iVar1 = uVar16 * 4;
                loopIndex3 = 0;
                while( true ) {
                  if (uVar16 < *puVar17) {
                    uVar6 = puVar17[1];
                    if (uVar6 <= uVar16) {
                      _memset(uVar6 * 4 + puVar17[2],0,(uVar16 - uVar6) * 4 + 4);
                      puVar17[1] = uVar16 + 1;
                    }
                    piVar14 = (int *)(iVar1 + puVar17[2]);
                  }
                  else {
                    piVar14 = (int *)Vector__elementRefGrow(puVar17,uVar16);
                  }
                  piVar14 = (int *)*piVar14;
                  if (((piVar14[2] == 0) && (piVar14[4] == *(int *)(iVar7 + 0x10))) &&
                     (0 < piVar14[5])) {
                    iVar8 = *piVar14;
                    iVar19 = 4;
                    do {
                      if (*(char *)(piVar14 + 6) != '\0') {
                        *(int *)(iVar8 + 0x48) = *(int *)(iVar8 + 0x48) + -1;
                      }
                      piVar14 = (int *)((int)piVar14 + 1);
                      iVar8 = iVar8 + 4;
                      iVar19 = iVar19 + -1;
                    } while (iVar19 != 0);
                    Vector__removeAt(*(undefined4 *)(iVar18 + 0x44),uVar16);
                  }
                  loopIndex3 = loopIndex3 + 1;
                  uVar16 = uVar16 - 1;
                  iVar1 = iVar1 + -4;
                  if (uVar5 == loopIndex3) break;
                  puVar17 = *(uint **)(iVar18 + 0x44);
                }
              }
            }
          }
          else {
            (**(code **)(**(int **)(iVar18 + 0x38) + 0x60))(*(int **)(iVar18 + 0x38));
            Vector__removeAt(*(undefined4 *)(iVar13 + 0x40),uVar15);
          }
          loopIndex2 = loopIndex2 + 1;
          uVar15 = uVar15 - 1;
          iVar2 = iVar2 + -4;
          if (uVar12 == loopIndex2) break;
          puVar17 = *(uint **)(iVar13 + 0x40);
        }
      }
      DList__unlink(iVar13);
      return iVar13;
    }
    iVar13 = *(int *)(iVar13 + 8);
  } while( true );
}

/* FUN_00166844 @ 0x166844 (456 bytes) */
int FUN_00166844(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined4 *allocation;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  uint uVar10;
  int *piVar11;
  uint *puVar12;
  undefined4 arena;
  uint loopIndex;
  int iVar15;
  
  loopIndex = 0;
  puVar12 = *(uint **)(param_2 + 0x44);
  uVar10 = puVar12[1];
  if (0 < (int)uVar10) {
    while( true ) {
      if (loopIndex < *puVar12) {
        uVar3 = puVar12[1];
        if (uVar3 <= loopIndex) {
          _memset(uVar3 * 4 + puVar12[2],0,(loopIndex - uVar3) * 4 + 4);
          puVar12[1] = loopIndex + 1;
        }
        allocation = (undefined4 *)(loopIndex * 4 + puVar12[2]);
      }
      else {
        allocation = (undefined4 *)Vector__elementRefGrow(puVar12,loopIndex);
      }
      piVar11 = (int *)*allocation;
      if (piVar11[7] == 1) {
        arena = *(undefined4 *)(*param_1 + 0x378);
        allocation = (undefined4 *)Arena__alloc(arena,0x24);
        uVar1 = DAT_001b0194;
        *allocation = arena;
        allocation[1] = 0;
        iVar7 = 0;
        allocation[7] = uVar1;
        allocation[4] = 1;
        iVar8 = piVar11[6];
        iVar2 = *piVar11;
        iVar6 = piVar11[3];
        allocation[3] = 0;
        allocation[5] = 0;
        allocation[6] = 0;
        allocation[8] = 0;
        iVar15 = 4;
        allocation[7] = iVar8;
        allocation[1] = iVar2;
        allocation[4] = iVar6;
        allocation[2] = param_3;
        piVar9 = piVar11;
        do {
          if (*(char *)(piVar9 + 6) != '\0') {
            iVar2 = iVar7 * 4 + *piVar11;
            *(int *)(iVar2 + 0x48) = *(int *)(iVar2 + 0x48) + 1;
          }
          iVar7 = iVar7 + 1;
          piVar9 = (int *)((int)piVar9 + 1);
          iVar15 = iVar15 + -1;
        } while (iVar15 != 0);
        allocation[8] = 1;
        puVar12 = *(uint **)(param_3 + 0x44);
        uVar10 = puVar12[1];
        if (uVar10 < *puVar12) {
          _memset(uVar10 * 4 + puVar12[2],0,4);
          puVar5 = (undefined4 *)(uVar10 * 4 + puVar12[2]);
          puVar12[1] = uVar10 + 1;
        }
        else {
          puVar5 = (undefined4 *)Vector__elementRefGrow(puVar12,uVar10);
        }
        *puVar5 = allocation + 1;
        return;
      }
      loopIndex = loopIndex + 1;
      if (uVar10 == loopIndex) break;
      puVar12 = *(uint **)(param_2 + 0x44);
    }
  }
  return;
}

/* FUN_00166a0c @ 0x166a0c (412 bytes) */
int FUN_00166a0c(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint loopIndex;
  int iVar7;
  uint loopIndex2;
  uint *puVar9;
  
  loopIndex = 0;
  puVar9 = *(uint **)(param_2 + 0x40);
  uVar4 = puVar9[1];
  if (0 < (int)uVar4) {
    while( true ) {
      if (loopIndex < *puVar9) {
        uVar1 = puVar9[1];
        if (uVar1 <= loopIndex) {
          _memset(uVar1 * 4 + puVar9[2],0,(loopIndex - uVar1) * 4 + 4);
          puVar9[1] = loopIndex + 1;
        }
        piVar2 = (int *)(loopIndex * 4 + puVar9[2]);
      }
      else {
        piVar2 = (int *)Vector__elementRefGrow(puVar9,loopIndex);
      }
      iVar7 = *piVar2;
      if (*(int *)(iVar7 + 8) == 0) {
        iVar5 = *(int *)(iVar7 + 4);
        loopIndex2 = 0;
        puVar9 = *(uint **)(iVar5 + 0x44);
        uVar1 = puVar9[1];
        if (0 < (int)uVar1) {
          while( true ) {
            if (loopIndex2 < *puVar9) {
              uVar3 = puVar9[1];
              if (uVar3 <= loopIndex2) {
                _memset(uVar3 * 4 + puVar9[2],0,(loopIndex2 - uVar3) * 4 + 4);
                puVar9[1] = loopIndex2 + 1;
              }
              piVar2 = (int *)(loopIndex2 * 4 + puVar9[2]);
            }
            else {
              piVar2 = (int *)Vector__elementRefGrow(puVar9,loopIndex2);
            }
            piVar2 = (int *)*piVar2;
            if ((((piVar2[2] == 0) && (param_2 != *piVar2)) && (piVar2[4] == *(int *)(iVar7 + 0x10))
                ) && ((piVar2[5] == *(int *)(iVar7 + 0x14) &&
                      ((*(uint *)(*(int *)(*piVar2 + 0x38) + 0x14) & 0x40) != 0)))) {
              return 1;
            }
            loopIndex2 = loopIndex2 + 1;
            if (uVar1 == loopIndex2) break;
            puVar9 = *(uint **)(iVar5 + 0x44);
          }
        }
      }
      loopIndex = loopIndex + 1;
      if (uVar4 == loopIndex) break;
      puVar9 = *(uint **)(param_2 + 0x40);
    }
  }
  return 0;
}

/* FUN_00166ba8 @ 0x166ba8 (340 bytes) */
int FUN_00166ba8(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uint loopIndex;
  uint *puVar8;
  int *piVar9;
  
  if (*(int *)(param_1 + 0x2c) < *(int *)(param_2 + 0x30)) {
LAB_00166ce4:
    uVar5 = 0;
  }
  else {
    iVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x20))
                      (*(int **)(param_1 + 0xc),*(undefined4 *)(param_2 + 0x38));
    if (iVar1 != 0) {
      puVar8 = *(uint **)(param_2 + 0x44);
      loopIndex = 0;
      uVar6 = puVar8[1];
      if (0 < (int)uVar6) {
        while( true ) {
          if (loopIndex < *puVar8) {
            uVar2 = puVar8[1];
            if (uVar2 <= loopIndex) {
              _memset(uVar2 * 4 + puVar8[2],0,(loopIndex - uVar2) * 4 + 4);
              puVar8[1] = loopIndex + 1;
            }
            puVar3 = (undefined4 *)(loopIndex * 4 + puVar8[2]);
          }
          else {
            puVar3 = (undefined4 *)Vector__elementRefGrow(puVar8,loopIndex);
          }
          piVar9 = (int *)*puVar3;
          if ((((piVar9[2] == 0) &&
               (iVar1 = *piVar9,
               *(int *)(*(int *)(iVar1 + 0x38) + 0x158) == *(int *)(param_1 + 0x10))) &&
              (iVar4 = (**(code **)(**(int **)(param_1 + 0xc) + 0x20))(*(int **)(param_1 + 0xc)),
              iVar4 != 0)) &&
             ((piVar9[7] != 0 && (*(int *)(param_1 + 0x124) <= *(int *)(iVar1 + 0x2c)))))
          goto LAB_00166ce4;
          loopIndex = loopIndex + 1;
          if (uVar6 == loopIndex) break;
          puVar8 = *(uint **)(param_2 + 0x44);
        }
      }
    }
    uVar5 = 1;
  }
  return uVar5;
}

/* FUN_00166cfc @ 0x166cfc (1024 bytes) */
int FUN_00166cfc(param_1)
  int param_1;
{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  uint loopIndex;
  uint loopIndex2;
  uint *puVar10;
  
  loopIndex = 0;
  FUN_00193f08(param_1 + 0x34);
  FUN_00193f08(param_1 + 0x4c);
  FUN_00193f08(param_1 + 100);
  FUN_00193f08(param_1 + 0x7c);
  FUN_00193fa4(param_1 + 0x94);
  puVar10 = *(uint **)(param_1 + 0x18);
  uVar6 = puVar10[1];
  if (0 < (int)uVar6) {
    while( true ) {
      if (loopIndex < *puVar10) {
        uVar1 = puVar10[1];
        if (uVar1 <= loopIndex) {
          _memset(uVar1 * 4 + puVar10[2],0,(loopIndex - uVar1) * 4 + 4);
          puVar10[1] = loopIndex + 1;
        }
        puVar2 = (undefined4 *)(loopIndex * 4 + puVar10[2]);
      }
      else {
        puVar2 = (undefined4 *)Vector__elementRefGrow(puVar10,loopIndex);
      }
      loopIndex = loopIndex + 1;
      piVar7 = (int *)*puVar2;
      /* issue #76: same shared param_1[0x18] array gap as elsewhere - skip a never-populated
       * slot instead of dereferencing it. */
      if (piVar7 == (int *)0x0) goto LAB_issue76_skip_166cfc;
      loopIndex2 = 0;
      *(undefined4 *)(piVar7[0xe] + 0x150) = 0;
      puVar10 = (uint *)piVar7[0x10];
      uVar1 = puVar10[1];
      if (0 < (int)uVar1) {
        while( true ) {
          if (loopIndex2 < *puVar10) {
            uVar3 = puVar10[1];
            if (uVar3 <= loopIndex2) {
              _memset(uVar3 * 4 + puVar10[2],0,(loopIndex2 - uVar3) * 4 + 4);
              puVar10[1] = loopIndex2 + 1;
            }
            piVar4 = (int *)(loopIndex2 * 4 + puVar10[2]);
          }
          else {
            piVar4 = (int *)Vector__elementRefGrow(puVar10,loopIndex2);
          }
          loopIndex2 = loopIndex2 + 1;
          iVar5 = *piVar4;
          if (iVar5 != 0) {
            Arena__free(*(undefined4 *)(iVar5 + -4),iVar5 + -4);
          }
          if (uVar1 == loopIndex2) break;
          puVar10 = (uint *)piVar7[0x10];
        }
      }
      iVar5 = piVar7[0x18];
      if (iVar5 != 0) {
        *(int *)(iVar5 + 0x10) = *(int *)(iVar5 + 0x10) + -1;
        iVar5 = piVar7[0x18];
        if ((*(int *)(iVar5 + 0x10) < 1) && (iVar5 != 0)) {
          Arena__free(*(undefined4 *)(iVar5 + -4),iVar5 + -4);
        }
      }
      iVar5 = piVar7[0x10];
      if (iVar5 != 0) {
        Arena__free(*(undefined4 *)(iVar5 + 0xc),*(undefined4 *)(iVar5 + 8));
        Arena__free(*(undefined4 *)(iVar5 + -4),iVar5 + -4);
      }
      iVar5 = piVar7[0x11];
      if (iVar5 != 0) {
        Arena__free(*(undefined4 *)(iVar5 + 0xc),*(undefined4 *)(iVar5 + 8));
        Arena__free(*(undefined4 *)(iVar5 + -4),iVar5 + -4);
      }
      (**(code **)(*piVar7 + 4))(piVar7);
LAB_issue76_skip_166cfc:
      if (uVar6 == loopIndex) break;
      puVar10 = *(uint **)(param_1 + 0x18);
    }
  }
  puVar10 = *(uint **)(param_1 + 0x14);
  loopIndex = 0;
  uVar6 = puVar10[1];
  if (0 < (int)uVar6) {
    while( true ) {
      if (loopIndex < *puVar10) {
        uVar1 = puVar10[1];
        if (uVar1 <= loopIndex) {
          _memset(uVar1 * 4 + puVar10[2],0,(loopIndex - uVar1) * 4 + 4);
          puVar10[1] = loopIndex + 1;
        }
        puVar2 = (undefined4 *)(loopIndex * 4 + puVar10[2]);
      }
      else {
        puVar2 = (undefined4 *)Vector__elementRefGrow(puVar10,loopIndex);
      }
      loopIndex = loopIndex + 1;
      piVar7 = (int *)*puVar2;
      loopIndex2 = 0;
      puVar10 = (uint *)piVar7[0x10];
      uVar1 = puVar10[1];
      if (0 < (int)uVar1) {
        while( true ) {
          if (loopIndex2 < *puVar10) {
            uVar3 = puVar10[1];
            if (uVar3 <= loopIndex2) {
              _memset(uVar3 * 4 + puVar10[2],0,(loopIndex2 - uVar3) * 4 + 4);
              puVar10[1] = loopIndex2 + 1;
            }
            piVar4 = (int *)(loopIndex2 * 4 + puVar10[2]);
          }
          else {
            piVar4 = (int *)Vector__elementRefGrow(puVar10,loopIndex2);
          }
          loopIndex2 = loopIndex2 + 1;
          iVar5 = *piVar4;
          if (iVar5 != 0) {
            Arena__free(*(undefined4 *)(iVar5 + -4),iVar5 + -4);
          }
          if (uVar1 == loopIndex2) break;
          puVar10 = (uint *)piVar7[0x10];
        }
      }
      iVar5 = piVar7[0x18];
      if (iVar5 != 0) {
        *(int *)(iVar5 + 0x10) = *(int *)(iVar5 + 0x10) + -1;
        iVar5 = piVar7[0x18];
        if ((*(int *)(iVar5 + 0x10) < 1) && (iVar5 != 0)) {
          Arena__free(*(undefined4 *)(iVar5 + -4),iVar5 + -4);
        }
      }
      iVar5 = piVar7[0x10];
      if (iVar5 != 0) {
        Arena__free(*(undefined4 *)(iVar5 + 0xc),*(undefined4 *)(iVar5 + 8));
        Arena__free(*(undefined4 *)(iVar5 + -4),iVar5 + -4);
      }
      iVar5 = piVar7[0x11];
      if (iVar5 != 0) {
        Arena__free(*(undefined4 *)(iVar5 + 0xc),*(undefined4 *)(iVar5 + 8));
        Arena__free(*(undefined4 *)(iVar5 + -4),iVar5 + -4);
      }
      (**(code **)(*piVar7 + 4))(piVar7);
      if (uVar6 == loopIndex) break;
      puVar10 = *(uint **)(param_1 + 0x14);
    }
  }
  *(undefined4 *)(*(int *)(param_1 + 0x18) + 4) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x14) + 4) = 0;
  return;
}

/* FUN_001670fc @ 0x1670fc (2424 bytes) */
int FUN_001670fc(compiler)
  int *compiler;
{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  undefined4 *allocation;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int *piVar13;
  uint uVar14;
  uint uVar15;
  uint *puVar16;
  uint uVar17;
  uint uVar18;
  undefined4 arena;
  uint *puVar20;
  int iVar21;
  int iVar22;
  uint local_68 [4];
  int local_58;
  uint local_54;
  
  arena = *(undefined4 *)(*compiler + 0x378);
  uVar18 = *(uint *)(compiler[6] + 4);
  allocation = (undefined4 *)Arena__alloc(arena,0x10);
  piVar13 = allocation + 1;
  allocation[1] = 1;
  *allocation = arena;
  allocation[2] = 0x20;
  iVar11 = 0;
  piVar4 = piVar13;
  do {
    bVar1 = iVar11 == -1;
    piVar4[2] = 0;
    iVar11 = iVar11 + 1;
    piVar4 = piVar4 + 1;
  } while (bVar1);
  iVar6 = Arena__alloc(*(undefined4 *)(*compiler + 0x378),uVar18 << 2);
  iVar11 = *piVar13;
  if (iVar11 != 0) {
    piVar4 = piVar13;
    if (iVar11 == 0) {
      iVar11 = 1;
    }
    do {
      piVar4[2] = 0;
      piVar4 = piVar4 + 1;
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
  }
  FUN_00172000(compiler[2]);
  iVar21 = 4;
  iVar11 = 0;
  do {
    *(undefined4 *)(iVar11 + (int)local_68) = 0;
    iVar11 = iVar11 + 4;
    iVar21 = iVar21 + -1;
  } while (iVar21 != 0);
  uVar15 = uVar18 - 1;
  if ((int)uVar15 < 0) {
    iVar21 = 0;
    bVar1 = false;
    local_58 = 0;
  }
  else {
    iVar11 = uVar15 * 4;
    iVar10 = iVar11 + 4;
    puVar16 = (uint *)(iVar6 + iVar11);
    iVar21 = 0;
    bVar1 = false;
    local_58 = 0;
    uVar14 = 0;
    local_54 = uVar18;
    do {
      puVar20 = (uint *)compiler[6];
      if (uVar15 < *puVar20) {
        uVar7 = puVar20[1];
        if (uVar7 <= uVar15) {
          _memset(uVar7 * 4 + puVar20[2],0,(uVar15 - uVar7) * 4 + 4);
          puVar20[1] = uVar18;
        }
        piVar4 = (int *)(iVar11 + puVar20[2]);
      }
      else {
        piVar4 = (int *)Vector__elementRefGrow(puVar20,uVar15);
      }
      iVar12 = *piVar4;
      /* issue #76: same shared-array gap as FUN_0016a568/FUN_0016bd70 - skip a never-populated
       * compiler[6] slot instead of dereferencing/passing it on as a live format object. */
      if (iVar12 == 0) goto LAB_issue76_skip_1670fc;
      iVar3 = Compiler__isOptionEnabled(*compiler,0x28);
      if (iVar3 == 0) {
LAB_001672b8:
        arena = 0;
      }
      else {
        iVar3 = (**(code **)(*(int *)compiler[2] + 0x34))((int *)compiler[2],iVar12);
        arena = 1;
        if (iVar3 == 0) goto LAB_001672b8;
      }
      *(undefined4 *)(iVar12 + 0x5c) = arena;
      uVar7 = 0;
      arena = (**(code **)(*(int *)compiler[2] + 0x4c))
                         ((int *)compiler[2],*(undefined4 *)(iVar12 + 0x38));
      *(undefined4 *)(iVar12 + 0x58) = arena;
      (**(code **)(*(int *)compiler[2] + 0x48))((int *)compiler[2],iVar12);
      (**(code **)(*(int *)compiler[2] + 0x44))((int *)compiler[2],iVar12);
      FUN_00172078(compiler[2],iVar12);
      *puVar16 = 0;
      puVar20 = *(uint **)(iVar12 + 0x40);
      uVar17 = puVar20[1];
      if (0 < (int)uVar17) {
        while( true ) {
          if (uVar7 < *puVar20) {
            uVar9 = puVar20[1];
            if (uVar9 <= uVar7) {
              _memset(uVar9 * 4 + puVar20[2],0,(uVar7 - uVar9) * 4 + 4);
              puVar20[1] = uVar7 + 1;
            }
            piVar4 = (int *)(uVar7 * 4 + puVar20[2]);
          }
          else {
            piVar4 = (int *)Vector__elementRefGrow(puVar20,uVar7);
          }
          uVar7 = uVar7 + 1;
          iVar8 = *piVar4;
          iVar3 = *(int *)(iVar12 + 0x14);
          iVar22 = *(int *)(iVar8 + 4);
          *(int *)(iVar22 + 0x34) = *(int *)(iVar22 + 0x34) + 1;
          iVar8 = *(int *)(iVar8 + 0xc) + *(int *)(iVar22 + 0x14);
          if (iVar3 < iVar8) {
            iVar3 = iVar8;
          }
          iVar8 = *(int *)(iVar22 + 0x3c);
          *(int *)(iVar12 + 0x14) = iVar3;
          if ((int)uVar15 < iVar8) {
            uVar9 = *(int *)(iVar6 + iVar8 * 4) << (iVar8 - uVar15 & 0x3f) | *puVar16;
            *puVar16 = uVar9;
            *puVar16 = uVar9 | 1 << ((*(int *)(iVar22 + 0x3c) - uVar15) - 1 & 0x3f);
          }
          if (uVar17 == uVar7) break;
          puVar20 = *(uint **)(iVar12 + 0x40);
        }
      }
      iVar3 = *(int *)(iVar12 + 0xc);
      if (iVar21 < iVar3) {
        iVar21 = iVar3;
      }
      if (*(int *)(*(int *)(*compiler + 0x30c) + 0x54) <= iVar21) {
        Compiler__fail(*compiler,0xf);
      }
      iVar8 = (**(code **)(*(int *)compiler[3] + 0x20))
                        ((int *)compiler[3],*(undefined4 *)(iVar12 + 0x38));
      if ((iVar8 != 0) ||
         (iVar8 = (**(code **)(*(int *)compiler[3] + 0x24))
                            ((int *)compiler[3],*(undefined4 *)(iVar12 + 0x38)), iVar8 != 0)) {
        if (iVar3 < 4) {
          local_68[iVar3] = local_68[iVar3] + 1;
        }
        if (0 < iVar3) {
          bVar1 = true;
        }
        compiler[0x65] = compiler[0x65] + 1;
        iVar3 = (**(code **)(**(int **)(iVar12 + 0x38) + 0x30))(*(int **)(iVar12 + 0x38));
        if (iVar3 != 0) {
          uVar7 = *(uint *)(*(int *)(iVar12 + 0x38) + 0x134);
          if ((int)uVar7 < 0x20) {
            if ((int)uVar7 < 0) goto LAB_0016753c;
          }
          else {
            Compiler__fail(*compiler,0xf);
          }
          uVar17 = uVar7 >> 3 & 0x1ffffffc;
          *(uint *)((int)piVar13 + uVar17 + 8) =
               1 << (uVar7 & 0x1f) | *(uint *)((int)piVar13 + uVar17 + 8);
        }
      }
LAB_0016753c:
      *(uint *)(iVar12 + 0x10) = uVar15;
      if (*(int *)(iVar12 + 0x1c) == 0) {
        iVar3 = (**(code **)(*(int *)compiler[2] + 0x28))
                          ((int *)compiler[2],*(undefined4 *)(iVar12 + 0x38));
        arena = 0;
        if (iVar3 != 0) goto LAB_00167574;
      }
      else {
LAB_00167574:
        arena = 1;
      }
      puVar20 = *(uint **)(iVar12 + 0x44);
      uVar17 = 0;
      *(undefined4 *)(iVar12 + 0x1c) = arena;
      uVar7 = puVar20[1];
      if (0 < (int)uVar7) {
        do {
          if (uVar17 < *puVar20) {
            uVar9 = puVar20[1];
            if (uVar9 <= uVar17) {
              _memset(uVar9 * 4 + puVar20[2],0,(uVar17 - uVar9) * 4 + 4);
              puVar20[1] = uVar17 + 1;
            }
            piVar4 = (int *)(uVar17 * 4 + puVar20[2]);
          }
          else {
            piVar4 = (int *)Vector__elementRefGrow(puVar20,uVar17);
          }
          uVar17 = uVar17 + 1;
          piVar4 = (int *)*piVar4;
          if (piVar4[2] == 0) {
            iVar8 = *piVar4;
            iVar22 = 4;
            iVar3 = iVar8;
            do {
              if (*(char *)(piVar4 + 6) != '\0') {
                *(int *)(iVar3 + 0x48) = *(int *)(iVar3 + 0x48) + 1;
              }
              piVar4 = (int *)((int)piVar4 + 1);
              iVar3 = iVar3 + 4;
              iVar22 = iVar22 + -1;
            } while (iVar22 != 0);
            if ((*(int *)(iVar8 + 0x1c) != 0) || (arena = 0, *(int *)(iVar12 + 0x1c) != 0)) {
              arena = 1;
            }
            *(undefined4 *)(iVar8 + 0x1c) = arena;
            iVar3 = (**(code **)(*(int *)compiler[3] + 0x20))
                              ((int *)compiler[3],*(undefined4 *)(iVar12 + 0x38));
            if ((iVar3 == 0) &&
               (iVar3 = (**(code **)(*(int *)compiler[3] + 0x24))
                                  ((int *)compiler[3],*(undefined4 *)(iVar12 + 0x38)), iVar3 == 0)) {
              iVar22 = *(int *)(iVar8 + 0xc);
              iVar3 = *(int *)(iVar12 + 0xc);
              if (iVar22 < *(int *)(iVar12 + 0xc)) {
LAB_001676d0:
                iVar22 = iVar3;
              }
            }
            else {
              iVar22 = *(int *)(iVar8 + 0xc);
              iVar3 = *(int *)(iVar12 + 0xc) + 1;
              if (iVar22 < iVar3) goto LAB_001676d0;
            }
            *(int *)(iVar8 + 0xc) = iVar22;
          }
          if (uVar7 == uVar17) break;
          puVar20 = *(uint **)(iVar12 + 0x44);
        } while( true );
      }
      uVar17 = 0;
      iVar3 = iVar10;
      uVar7 = uVar18;
      do {
        if ((1 << (uVar17 & 0x3f) & *puVar16) != 0) {
          puVar20 = (uint *)compiler[6];
          if (uVar7 < *puVar20) {
            uVar9 = puVar20[1];
            if (uVar9 <= uVar7) {
              _memset(uVar9 * 4 + puVar20[2],0,(uVar7 - uVar9) * 4 + 4);
              puVar20[1] = uVar7 + 1;
            }
            piVar4 = (int *)(iVar3 + puVar20[2]);
          }
          else {
            piVar4 = (int *)Vector__elementRefGrow(puVar20,uVar7);
          }
          /* issue #76: same shared-array gap as elsewhere in this function - *piVar4 (the
           * slot's own stored format pointer, not piVar4 itself) can legitimately still be an
           * unpopulated 0. */
          if (*piVar4 == 0) goto LAB_issue76_skip_1670fc_inner;
          if (*(int *)(*piVar4 + 0x5c) == 0) {
            iVar8 = *(int *)(*piVar4 + 0x58);
            if (iVar8 == 1) {
              *(int *)(iVar12 + 0x24) = *(int *)(iVar12 + 0x24) + 1;
            }
            else if (iVar8 == 2) {
              *(int *)(iVar12 + 0x28) = *(int *)(iVar12 + 0x28) + 1;
            }
          }
          else {
            *(int *)(iVar12 + 0x20) = *(int *)(iVar12 + 0x20) + 1;
          }
        }
LAB_issue76_skip_1670fc_inner:
        uVar7 = uVar7 + 1;
        bVar2 = uVar17 != 0x1f;
        iVar3 = iVar3 + 4;
        uVar17 = uVar17 + 1;
      } while (bVar2);
      if (local_58 < *(int *)(iVar12 + 0x14)) {
        local_58 = *(int *)(iVar12 + 0x14);
      }
LAB_issue76_skip_1670fc:
      uVar14 = uVar14 + 1;
      uVar15 = uVar15 - 1;
      uVar18 = uVar18 - 1;
      iVar10 = iVar10 + -4;
      puVar16 = puVar16 + -1;
      iVar11 = iVar11 + -4;
    } while (uVar14 != local_54);
  }
  iVar10 = (**(code **)(*(int *)compiler[2] + 0x5c))((int *)compiler[2]);
  compiler[0x44] = local_58;
  compiler[0x45] = iVar10;
  compiler[9] = (uint)(local_58 <= iVar10);
  iVar11 = *(int *)(*(int *)(*compiler + 0x30c) + 0x54);
  if (4 < iVar11) {
    iVar10 = 4;
    compiler[10] = 8;
    iVar11 = 0;
    iVar21 = 0;
    do {
      iVar3 = *(int *)(iVar21 + (int)local_68);
      if (iVar11 < iVar3) {
        iVar11 = iVar3;
      }
      iVar21 = iVar21 + 4;
      iVar10 = iVar10 + -1;
    } while (iVar10 != 0);
    iVar11 = (**(code **)(*(int *)compiler[2] + 0x58))((int *)compiler[2],iVar11,local_58);
    compiler[8] = iVar11;
    goto LAB_00167a18;
  }
  if (-1 < iVar21) {
    iVar3 = 0;
    puVar16 = local_68;
    do {
      iVar3 = iVar3 + 1;
      if (iVar3 <= iVar21) {
        puVar20 = local_68 + iVar3;
        iVar12 = iVar3;
        do {
          uVar18 = *puVar16;
          if ((int)uVar18 < (int)*puVar20) {
            *puVar16 = *puVar20;
            *puVar20 = uVar18;
          }
          iVar12 = iVar12 + 1;
          puVar20 = puVar20 + 1;
        } while (iVar12 <= iVar21);
      }
      puVar16 = puVar16 + 1;
    } while (iVar3 <= iVar21);
  }
  iVar11 = iVar11 - iVar21;
  if (iVar11 + -1 < 1) {
    compiler[10] = local_68[0];
  }
  else {
    uVar18 = local_68[1];
    if ((int)local_68[1] < (int)local_68[0] / iVar11) {
      uVar18 = (int)local_68[0] / iVar11;
    }
    compiler[10] = uVar18;
    if ((int)(iVar11 * uVar18) < (int)local_68[0]) {
      compiler[10] = uVar18 + 1;
    }
    if ((iVar11 + -1 == 2) && ((int)local_68[0] < (int)(local_68[1] << 1))) {
      iVar11 = ((int)local_68[0] >> 1) + (uint)((int)local_68[0] < 0 && (local_68[0] & 1) != 0);
      if ((int)local_68[2] < iVar11) {
        local_68[2] = iVar11;
      }
      if ((int)(local_68[2] << 1) < (int)local_68[0]) {
        local_68[2] = local_68[2] + 1;
      }
      if ((int)local_68[2] < compiler[10]) {
        compiler[10] = local_68[2];
      }
    }
  }
  iVar11 = (**(code **)(*(int *)compiler[2] + 0x58))((int *)compiler[2],local_68[0],local_58,iVar10);
  compiler[8] = iVar11;
  if (iVar11 == 0) {
    if ((bVar1) && (iVar11 = allocation[2], iVar11 != 0)) {
      uVar15 = 0;
      uVar18 = 0;
      do {
        if ((*(uint *)((int)piVar13 + (uVar15 >> 3 & 0x1ffffffc) + 8) >> (uVar15 & 0x1f) & 1) != 0)
        {
          uVar18 = uVar18 + 1;
        }
        uVar15 = uVar15 + 1;
        iVar11 = iVar11 + -1;
      } while (iVar11 != 0);
      if (6 < uVar18) goto LAB_00167a04;
    }
    iVar11 = compiler[10];
    if (iVar11 < 0x400) {
      iVar11 = 0x400;
    }
  }
  else {
LAB_00167a04:
    iVar11 = compiler[10];
    if (iVar11 < 1) {
      iVar11 = 1;
    }
  }
  compiler[10] = iVar11;
LAB_00167a18:
  if (piVar13 != (int *)0x0) {
    Arena__free(*allocation,allocation);
  }
  return Arena__free(*(undefined4 *)(*compiler + 0x378),iVar6);
}

/* FUN_00167a74 @ 0x167a74 (244 bytes) */
int FUN_00167a74(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint loopIndex;
  uint *puVar7;
  
  loopIndex = 0;
  puVar7 = *(uint **)(param_1 + 0x40);
  iVar5 = *(int *)(param_1 + 0x2c);
  uVar4 = puVar7[1];
  if (0 < (int)uVar4) {
    while( true ) {
      if (loopIndex < *puVar7) {
        uVar1 = puVar7[1];
        if (uVar1 <= loopIndex) {
          _memset(uVar1 * 4 + puVar7[2],0,(loopIndex - uVar1) * 4 + 4);
          puVar7[1] = loopIndex + 1;
        }
        piVar2 = (int *)(loopIndex * 4 + puVar7[2]);
      }
      else {
        piVar2 = (int *)Vector__elementRefGrow(puVar7,loopIndex);
      }
      loopIndex = loopIndex + 1;
      iVar3 = *piVar2;
      if (((*(int *)(iVar3 + 8) == 0) && (*(char *)(param_2 + iVar3 + 0x18) != '\0')) &&
         (iVar3 = *(int *)(*(int *)(iVar3 + 4) + 0x2c), iVar5 < iVar3)) {
        iVar5 = iVar3;
      }
      if (uVar4 == loopIndex) break;
      puVar7 = *(uint **)(param_1 + 0x40);
    }
  }
  return iVar5;
}

/* FUN_00167b68 @ 0x167b68 (692 bytes) */
int FUN_00167b68(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  undefined4 param_3;
{
  unsigned int ghidra_home[8] = { param_1, param_2, param_3, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  bool bVar1;
  char cVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  char *pcVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  uint local_58 [7];
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 8)) = param_3;
  if (param_2 != 1) {
    uVar4 = 0;
    piVar3 = *(int **)(*param_1 + 0x30c);
    uVar5 = (**(code **)(*piVar3 + 0x138))(piVar3,*param_1);
    iVar9 = param_1[0x66];
  }
  else {
    piVar3 = *(int **)(*param_1 + 0x30c);
    uVar4 = (**(code **)(*piVar3 + 0x138))(piVar3,*param_1);
    uVar5 = param_1[0x51];
    iVar9 = uVar4 + param_1[0x67];
  }
  uVar10 = 0xffffffff;
  if ((int)uVar4 < (int)uVar5) {
    iVar12 = uVar4 << 2;
    iVar8 = 4;
    uVar13 = uVar4;
    do {
      bVar1 = (*(uint *)((uVar13 >> 3 & 0x1ffffffc) + param_1[0x4c] + 8) >> (uVar13 & 0x1f) & 1) !=
              0;
      if ((bVar1) && (iVar9 < (int)uVar13)) {
        if ((int)uVar10 < 0) {
          uVar10 = uVar13;
        }
        break;
      }
      local_58[0] = 0;
      iVar7 = 0;
      iVar14 = 4;
      piVar3 = param_1;
      do {
        iVar6 = *(int *)(piVar3[0x4d] + iVar12);
        if (((iVar6 != 0) && (0 < *(int *)(iVar7 * 4 + iVar6 + 0x48))) &&
           (*(uint **)(iVar6 + 0x60) != (uint *)0x0)) {
          local_58[0] = local_58[0] | **(uint **)(iVar6 + 0x60);
        }
        iVar7 = iVar7 + 1;
        piVar3 = piVar3 + 1;
        iVar14 = iVar14 + -1;
      } while (iVar14 != 0);
      if (bVar1) {
        iVar14 = 0;
        iVar7 = 0;
        pcVar11 = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 8));
        piVar3 = param_1;
        do {
          if ((*(char *)((int)local_58 + iVar14) == '\0') &&
             ((*(int *)(piVar3[0x4d] + iVar12) == 0 ||
              (*(int *)(iVar14 * 4 + *(int *)(piVar3[0x4d] + iVar12) + 0x48) < 1)))) {
            cVar2 = *pcVar11;
            if (cVar2 == '\0') {
              iVar7 = iVar7 + 1;
            }
LAB_00167d14:
            if (((cVar2 != '\0') && (iVar6 = *(int *)(param_1[1] + 0x38), iVar6 != 0)) &&
               ((*(uint *)(iVar6 + 0x94) == uVar13 &&
                ((((iVar6 = FUN_000f313c(iVar6,iVar14), iVar6 != 0 &&
                   (iVar6 = *(int *)(piVar3[0x4d] + iVar12), iVar6 != 0)) &&
                  (*(int *)(iVar6 + 0x38) == *(int *)(param_1[1] + 0x38))) &&
                 (iVar6 = ((int (*)())FUN_00167a74)(iVar6,iVar14), iVar6 == param_1[0xb])))))) goto LAB_00167cf0;
            bVar1 = true;
          }
          else {
            cVar2 = '\0';
            if (*pcVar11 == '\0') goto LAB_00167d14;
LAB_00167cf0:
            bVar1 = false;
          }
          iVar14 = iVar14 + 1;
          if (!bVar1) goto LAB_00167db4;
          pcVar11 = pcVar11 + 1;
          piVar3 = piVar3 + 1;
        } while (iVar14 != 4);
        if (((int)uVar10 < 0) || (iVar7 < iVar8)) {
          iVar8 = iVar7;
          uVar10 = uVar13;
        }
      }
LAB_00167db4:
      uVar13 = uVar13 + 1;
      iVar12 = iVar12 + 4;
    } while (uVar13 != uVar5);
  }
  if (param_2 != 1) {
    iVar9 = param_1[0x66];
    if (param_1[0x66] < (int)(uVar10 - uVar4)) {
      iVar9 = uVar10 - uVar4;
    }
    param_1[0x66] = iVar9;
  }
  else {
    iVar9 = param_1[0x67];
    if (param_1[0x67] < (int)(uVar10 - uVar4)) {
      iVar9 = uVar10 - uVar4;
    }
    param_1[0x67] = iVar9;
  }
  return uVar10;
}

/* FUN_00167e1c @ 0x167e1c (216 bytes) */
int FUN_00167e1c(param_1, param_2, param_3, param_4, param_5)
  int *param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  uint uVar1;
  int inst;
  undefined4 callResult;
  int iVar4;
  undefined4 local_28 [2];
  
  iVar4 = *(int *)(*param_1 + 0x6c4);
  inst = IRInst__create(0x31,*param_1);
  *(undefined4 *)(inst + 0x98) = 0;
  *(undefined4 *)(inst + 0x94) = *(undefined4 *)(inst + 0x14c);
  *(undefined4 *)(inst + 0x9c) = param_3;
  IRInst__setOperandSource(inst,1,param_2,0,*param_1);
  FUN_000f3908(local_28,param_3);
  uVar1 = *(uint *)(param_2 + 0x14);
  *(undefined4 *)(inst + 0xc) = local_28[0];
  if ((uVar1 & 0x20) == 0) {
    *(uint *)(inst + 0x14) = *(uint *)(inst + 0x14) & 0xffffffdf;
  }
  else {
    *(uint *)(inst + 0x14) = *(uint *)(inst + 0x14) | 0x20;
  }
  FUN_000f35c4(inst);
  *(int *)(iVar4 + 0x23c) = *(int *)(iVar4 + 0x23c) + 1;
  callResult = ((int (*)())FUN_00165d3c)(param_1,inst,param_5,param_4);
  return callResult;
}

/* FUN_00167ef4 @ 0x167ef4 (1396 bytes) */
int FUN_00167ef4(param_1, param_2)
  int *param_1;
  int param_2;
{
  int loopIndex;
  int iVar1;
  int *operandVReg;
  undefined4 uVar3;
  int operandRecord;
  int iVar5;
  int iVar6;
  int iVar7;
  uint in_r9;
  uint uVar8;
  int *a0;
  int iVar9;
  int *piVar10;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c [3];
  
  a0 = *(int **)(param_2 + 0x38);
  iVar1 = (**(code **)(*a0 + 0x14))(a0,param_2);
  if ((iVar1 < 3) || (*(int *)(a0[0x22] + 8) == 0x14)) goto LAB_00168120;
  iVar1 = IRInst__getOperandSource(a0,1);
  if (*(int *)(iVar1 + 0x98) != 0) {
    operandVReg = (int *)IRInst__getOperandSource(a0,1);
    iVar1 = (**(code **)(*operandVReg + 0x60))(operandVReg);
    if (iVar1 == 0) goto LAB_00168120;
    uVar3 = IRInst__getOperandSource(a0,1);
    iVar1 = IRInst__getOperandSource(uVar3,1);
    if (*(int *)(iVar1 + 0x98) != 0) goto LAB_00168120;
  }
  iVar1 = IRInst__getOperandSource(a0,2);
  if (*(int *)(iVar1 + 0x98) != 0) {
    operandVReg = (int *)IRInst__getOperandSource(a0,2);
    iVar1 = (**(code **)(*operandVReg + 0x60))(operandVReg);
    if (iVar1 == 0) goto LAB_00168120;
    uVar3 = IRInst__getOperandSource(a0,2);
    iVar1 = IRInst__getOperandSource(uVar3,1);
    if (*(int *)(iVar1 + 0x98) != 0) goto LAB_00168120;
  }
  iVar1 = IRInst__getOperandSource(a0,3);
  if (*(int *)(iVar1 + 0x98) != 0) {
    operandVReg = (int *)IRInst__getOperandSource(a0,3);
    iVar1 = (**(code **)(*operandVReg + 0x60))(operandVReg);
    if (iVar1 != 0) {
      uVar3 = IRInst__getOperandSource(a0,3);
      iVar1 = IRInst__getOperandSource(uVar3,1);
      if (*(int *)(iVar1 + 0x98) == 0) goto LAB_00168060;
    }
LAB_00168120:
    iVar1 = -1;
    for (loopIndex = 1; iVar5 = (**(code **)(*a0 + 0x14))(a0), loopIndex <= iVar5; loopIndex = loopIndex + 1) {
      operandVReg = (int *)IRInst__getOperandSource(a0,loopIndex);
      iVar5 = (**(code **)(*operandVReg + 0x60))(operandVReg);
      if (iVar5 != 0) {
        operandVReg = (int *)IRInst__getOperandSource(operandVReg,1);
      }
      if (operandVReg[0x26] == 1) {
        iVar5 = operandVReg[0x25];
        if ((operandVReg[5] & 0x40U) == 0) {
          iVar9 = *param_1;
          piVar10 = *(int **)(iVar9 + 0x30c);
          iVar6 = (**(code **)(*piVar10 + 0x138))(piVar10,iVar9);
          iVar7 = (**(code **)(*piVar10 + 0x140))(piVar10,iVar9);
          iVar9 = (**(code **)(*piVar10 + 0x13c))(piVar10,iVar9);
          iVar5 = iVar5 + iVar6 + iVar7 + iVar9;
        }
        if (iVar1 < 0) {
          iVar1 = iVar5;
        }
        if (((*(int *)(operandVReg[0x22] + 8) != 0x8e) || ((operandVReg[5] & 0x40U) != 0)) &&
           ((operandVReg[0x56] == param_1[4] ||
            (*(int *)(param_1[1] + 0x474) == *(int *)(operandVReg[0x56] + 0x118))))) {
          iVar1 = iVar5;
        }
      }
    }
    loopIndex = 1;
    do {
      iVar5 = (**(code **)(*a0 + 0x14))(a0);
      if (iVar5 < loopIndex) {
        return 0;
      }
      operandVReg = (int *)IRInst__getOperandSource(a0,loopIndex);
      iVar5 = (**(code **)(*operandVReg + 0x60))(operandVReg);
      if (iVar5 != 0) {
        operandVReg = (int *)IRInst__getOperandSource(operandVReg,1);
      }
      if (operandVReg[0x26] == 1) {
        iVar5 = operandVReg[0x25];
        if ((operandVReg[5] & 0x40U) == 0) {
          iVar9 = *param_1;
          piVar10 = *(int **)(iVar9 + 0x30c);
          iVar6 = (**(code **)(*piVar10 + 0x138))(piVar10,iVar9);
          iVar7 = (**(code **)(*piVar10 + 0x140))(piVar10,iVar9);
          iVar9 = (**(code **)(*piVar10 + 0x13c))(piVar10,iVar9);
          iVar5 = iVar5 + iVar6 + iVar7 + iVar9;
        }
        if (iVar5 != iVar1) {
          if (((*(int *)(operandVReg[0x22] + 8) != 0x8e) || ((operandVReg[5] & 0x40U) != 0)) &&
             ((uVar8 = operandVReg[0x56], uVar8 == param_1[4] ||
              (uVar8 = *(uint *)(uVar8 + 0x118), *(uint *)(param_1[1] + 0x474) == uVar8)))) {
            iVar1 = IRInst__getOperandRecord(a0,loopIndex);
            FUN_000f32cc(&local_40,*(undefined4 *)(iVar1 + 0x10));
            uVar3 = IRInst__getOperandSource(a0,loopIndex);
            iVar1 = ((int (*)())FUN_00167e1c)(param_1,uVar3,local_40,param_1[0xb],param_2 + 0xc);
            IRInst__setOperandSource(a0,loopIndex,*(undefined4 *)(iVar1 + 0x38),0,*param_1);
            iVar5 = IRInst__getOperandRecord(a0,loopIndex);
            FUN_000f3398(local_3c,*(undefined4 *)(iVar5 + 0x10));
            ((int (*)())FUN_00165b7c)(param_1,iVar1,param_2,loopIndex,0,local_3c[0],uVar8);
            DList__unlink(param_2);
            return iVar1;
          }
          operandVReg[0x26] = 0;
        }
      }
      loopIndex = loopIndex + 1;
    } while( true );
  }
LAB_00168060:
  uVar3 = IRInst__getOperandSource(a0,1);
  iVar1 = IRInst__getOperandRecord(a0,1);
  FUN_000f32cc(&local_48,*(undefined4 *)(iVar1 + 0x10));
  iVar1 = ((int (*)())FUN_00167e1c)(param_1,uVar3,local_48,param_1[0xb],param_2 + 0xc);
  IRInst__setOperandSource(a0,1,*(undefined4 *)(iVar1 + 0x38),0,*param_1);
  operandRecord = IRInst__getOperandRecord(a0,1);
  FUN_000f3398(&local_44,*(undefined4 *)(operandRecord + 0x10));
  ((int (*)())FUN_00165b7c)(param_1,iVar1,param_2,1,0,local_44,in_r9);
  uVar3 = *(undefined4 *)(*(int *)(iVar1 + 0x38) + 0x94);
  operandRecord = IRInst__getOperandRecord(*(int *)(iVar1 + 0x38),0);
  *(undefined4 *)(operandRecord + 8) = uVar3;
  *(undefined4 *)(operandRecord + 0xc) = 1;
  *(undefined4 *)(iVar1 + 100) = 1;
  DList__unlink(param_2);
  return iVar1;
}

/* FUN_00168468 @ 0x168468 (2328 bytes) */
int FUN_00168468(param_1, param_2, inst, param_4, param_5)
  int *param_1;
  int param_2;
  int *inst;
  int param_4;
  int param_5;
{
  int *operandVReg2;
  int *operandVReg;
  bool bVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int *piVar7;
  undefined4 operandVReg3;
  undefined4 *allocation;
  int *piVar10;
  int iVar11;
  uint uVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  undefined4 arena;
  uint *puVar19;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80 [6];
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  uint local_58 [4];
  
  bVar1 = 0 < param_5;
  if (bVar1) {
    operandVReg = (int *)IRInst__getOperandSource(inst,param_5);
    iVar5 = param_5;
  }
  else {
    operandVReg = (int *)IRInst__getOperandSource(inst,param_4);
    iVar5 = param_4;
  }
  if ((operandVReg[0x56] == param_1[4]) && (iVar4 = ((int (*)())FUN_00164df4)(operandVReg), iVar4 == 0)) {
    puVar19 = (uint *)param_1[6];
    uVar17 = operandVReg[0x54];
    if (uVar17 < *puVar19) {
      uVar12 = puVar19[1];
      if (uVar12 <= uVar17) {
        _memset(uVar12 * 4 + puVar19[2],0,(uVar17 - uVar12) * 4 + 4);
        puVar19[1] = uVar17 + 1;
      }
      piVar7 = (int *)(uVar17 * 4 + puVar19[2]);
    }
    else {
      piVar7 = (int *)Vector__elementRefGrow(puVar19,uVar17);
    }
    iVar4 = *piVar7;
    iVar16 = 0;
  }
  else {
    iVar4 = ((int (*)())FUN_00165fa8)(param_1,operandVReg);
    iVar16 = 1;
  }
  if (((inst[5] & 0x200U) == 0) || (iVar5 != inst[0x21])) {
    iVar15 = (**(code **)(*inst + 0x14))(inst);
    if (iVar5 <= iVar15) {
      iVar15 = IRInst__getOperandRecord(inst,iVar5);
      arena = *(undefined4 *)(iVar15 + 0x10);
      if (bVar1) {
        iVar15 = IRInst__getOperandRecord(*(undefined4 *)(param_2 + 0x38),param_4);
        FUN_000f3398(&local_68,*(undefined4 *)(iVar15 + 0x10));
        operandVReg2 = (int *)IRInst__getOperandSource(*(undefined4 *)(param_2 + 0x38),param_4);
        if (inst != operandVReg2) {
          operandVReg2 = (int *)IRInst__getOperandSource(*(undefined4 *)(param_2 + 0x38),param_4);
          iVar15 = (**(code **)(*operandVReg2 + 0x60))(operandVReg2);
          if (iVar15 != 0) {
            operandVReg3 = IRInst__getOperandSource(*(undefined4 *)(param_2 + 0x38),param_4);
            IRInst__getOperandSource(operandVReg3,1);
          }
          operandVReg3 = IRInst__getOperandSource(*(undefined4 *)(param_2 + 0x38),param_4);
          iVar15 = IRInst__getOperandRecord(operandVReg3,1);
          FUN_000f3340(&local_64,*(undefined4 *)(iVar15 + 0x10),local_68);
          FUN_000f3398(&local_60,local_64);
          local_68 = local_60;
        }
        FUN_000f3340(&local_5c,arena,local_68);
        arena = local_5c;
      }
      FUN_000f3398(local_58,arena);
      bVar2 = iVar16 == 0;
      local_88 = local_58[0];
      iVar15 = 0;
      puVar6 = &local_88;
LAB_00168844:
      piVar7 = puVar6 + 2;
      do {
        local_84 = operandVReg[3] & local_88;
        if ((operandVReg[3] & local_88) != 0) {
          arena = *(undefined4 *)(*param_1 + 0x378);
          allocation = (undefined4 *)Arena__alloc(arena,0x24);
          puVar13 = allocation + 1;
          *allocation = arena;
          allocation[1] = iVar4;
          allocation[4] = 1;
          allocation[7] = 0x1010101;
          allocation[3] = 0;
          allocation[5] = 0;
          allocation[6] = 0;
          allocation[8] = 0;
          allocation[2] = param_2;
          arena = ((int (*)())FUN_00164e7c)(param_1,operandVReg,inst,0,param_4,0);
          allocation[4] = arena;
          allocation[5] = param_4;
          allocation[6] = param_5;
          allocation[7] = local_84;
          if (((iVar15 == 0) && (piVar10 = (int *)IRInst__getOperandSource(inst,iVar5), operandVReg != piVar10))
             && ((iVar11 = (**(code **)(*inst + 0x5c))(inst), iVar11 == 0 || (!bVar1)))) {
            IRInst__setOperandSource(inst,iVar5,operandVReg,0,*param_1);
          }
          if ((*(uint *)(*(int *)(param_2 + 0x38) + 0x14) & 0x8000) == 0) {
            iVar11 = (**(code **)(*operandVReg + 0x54))(operandVReg);
            piVar10 = operandVReg;
            if ((iVar11 != 0) && (operandVReg[0x21] != 0)) {
              piVar10 = (int *)IRInst__getOperandSource(operandVReg,1);
            }
            arena = (**(code **)(*(int *)param_1[3] + 0x20))((int *)param_1[3],piVar10);
            allocation[8] = arena;
          }
          puVar19 = *(uint **)(iVar4 + 0x40);
          uVar17 = puVar19[1];
          if (uVar17 < *puVar19) {
            _memset(uVar17 * 4 + puVar19[2],0,4);
            piVar10 = (int *)(uVar17 * 4 + puVar19[2]);
            puVar19[1] = uVar17 + 1;
          }
          else {
            piVar10 = (int *)Vector__elementRefGrow(puVar19,uVar17);
          }
          *piVar10 = (int)puVar13;
          puVar19 = *(uint **)(param_2 + 0x44);
          uVar17 = puVar19[1];
          if (uVar17 < *puVar19) {
            _memset(uVar17 * 4 + puVar19[2],0,4);
            piVar10 = (int *)(uVar17 * 4 + puVar19[2]);
            puVar19[1] = uVar17 + 1;
          }
          else {
            piVar10 = (int *)Vector__elementRefGrow(puVar19,uVar17);
          }
          *piVar10 = (int)puVar13;
          iVar15 = iVar15 + 1;
          *piVar7 = (int)puVar13;
          puVar6 = puVar6 + 1;
          piVar7 = piVar7 + 1;
        }
        if (bVar2) {
          uVar17 = ((uint)*(byte *)((int)&local_88 + iVar16 + 3) << 0x18 |
                    (uint)*(byte *)((int)&local_88 + iVar16 + 2) << 0x10 |
                    (uint)*(byte *)((int)&local_88 + iVar16 + 1) << 8 |
                   (uint)*(byte *)(iVar16 + (int)&local_88)) -
                   ((uint)*(byte *)((int)local_80 + iVar16 + -1) << 0x18 |
                    (uint)*(byte *)((int)local_80 + iVar16 + -2) << 0x10 |
                    (uint)*(byte *)((int)local_80 + iVar16 + -3) << 8 |
                   (uint)*(byte *)((int)local_80 + iVar16 + -4));
          local_88 = uVar17 * 0x1000000 | (uVar17 & 0xff00) << 8 | uVar17 >> 8 & 0xff00 |
                     uVar17 >> 0x18;
        }
        else {
          local_88 = 0;
        }
        if ((local_88 == 0) || ((operandVReg[5] & 0x200U) == 0)) {
LAB_00168ab0:
          if (iVar15 < 1) {
            return;
          }
          iVar5 = 0;
          puVar6 = local_80;
          do {
            iVar5 = iVar5 + 1;
            if (iVar5 < iVar15) {
              piVar3 = (int *)*puVar6;
              allocation = local_80 + iVar5;
              iVar4 = 0;
              do {
                piVar7 = (int *)*allocation;
                if ((*(uint *)(*(int *)(*piVar3 + 0x38) + 0xc) &
                    *(uint *)(*(int *)(*piVar7 + 0x38) + 0xc)) != 0) {
                  arena = *(undefined4 *)(*param_1 + 0x378);
                  puVar13 = (undefined4 *)Arena__alloc(arena,0x24);
                  *puVar13 = arena;
                  puVar13[1] = 0;
                  iVar11 = *piVar7;
                  puVar13[1] = iVar11;
                  iVar16 = *piVar3;
                  puVar13[4] = 1;
                  puVar13[7] = 0x1010101;
                  puVar13[3] = 3;
                  puVar13[2] = iVar16;
                  puVar13[5] = 0;
                  puVar13[6] = 0;
                  puVar13[8] = 0;
                  arena = ((int (*)())FUN_00164e7c)(param_1,*(undefined4 *)(iVar11 + 0x38),
                                        *(undefined4 *)(iVar16 + 0x38),0,0,3);
                  iVar11 = *piVar7;
                  iVar16 = *piVar3;
                  puVar13[4] = arena;
                  puVar13[7] = *(uint *)(*(int *)(iVar16 + 0x38) + 0xc) &
                               *(uint *)(*(int *)(iVar11 + 0x38) + 0xc);
                  puVar19 = *(uint **)(puVar13[1] + 0x40);
                  uVar17 = puVar19[1];
                  if (uVar17 < *puVar19) {
                    _memset(uVar17 * 4 + puVar19[2],0,4);
                    puVar14 = (undefined4 *)(uVar17 * 4 + puVar19[2]);
                    puVar19[1] = uVar17 + 1;
                  }
                  else {
                    puVar14 = (undefined4 *)Vector__elementRefGrow(puVar19,uVar17);
                  }
                  *puVar14 = puVar13 + 1;
                  puVar19 = *(uint **)(puVar13[2] + 0x44);
                  uVar17 = puVar19[1];
                  if (uVar17 < *puVar19) {
                    _memset(uVar17 * 4 + puVar19[2],0,4);
                    puVar14 = (undefined4 *)(uVar17 * 4 + puVar19[2]);
                    puVar19[1] = uVar17 + 1;
                  }
                  else {
                    puVar14 = (undefined4 *)Vector__elementRefGrow(puVar19,uVar17);
                  }
                  *puVar14 = puVar13 + 1;
                }
                iVar4 = iVar4 + 1;
                allocation = allocation + 1;
              } while (iVar15 - iVar5 != iVar4);
            }
            puVar6 = puVar6 + 1;
          } while (iVar5 != iVar15);
          return;
        }
        piVar10 = (int *)IRInst__getOperandSource(operandVReg,operandVReg[0x21]);
        iVar4 = (**(code **)(*piVar10 + 0x50))(piVar10);
        if (iVar4 != 0) goto LAB_00168ab0;
        operandVReg = (int *)IRInst__getOperandSource(operandVReg,operandVReg[0x21]);
        if ((operandVReg[0x56] == param_1[4]) && (iVar4 = ((int (*)())FUN_00164df4)(operandVReg), iVar4 == 0))
        goto LAB_00168b48;
        iVar16 = 1;
        bVar2 = false;
        iVar4 = ((int (*)())FUN_00165fa8)(param_1,operandVReg);
      } while( true );
    }
    arena = *(undefined4 *)(*param_1 + 0x378);
    puVar6 = (undefined4 *)Arena__alloc(arena,0x24);
    *puVar6 = arena;
    puVar6[4] = 1;
    puVar6[1] = iVar4;
    puVar6[7] = 0x1010101;
    puVar6[3] = 0;
    puVar6[5] = 0;
    puVar6[6] = 0;
    puVar6[8] = 0;
    puVar6[2] = param_2;
    arena = ((int (*)())FUN_00164e7c)(param_1,operandVReg,inst,0,param_4,0);
    puVar6[5] = param_4;
    puVar6[4] = arena;
    puVar6[6] = param_5;
    puVar6[7] = operandVReg[3];
  }
  else {
    IRInst__getOperandSource(inst,iVar5);
    iVar5 = Compiler__isOptionEnabled(*param_1,0x26);
    if (((iVar5 != 0) && (iVar5 = Compiler__isOptionEnabled(*param_1,0x25), iVar5 != 0)) &&
       ((inst[5] & 0x20U) == 0)) {
      return;
    }
    arena = *(undefined4 *)(*param_1 + 0x378);
    puVar6 = (undefined4 *)Arena__alloc(arena,0x24);
    *puVar6 = arena;
    puVar6[4] = 1;
    puVar6[1] = iVar4;
    puVar6[3] = 3;
    puVar6[7] = 0x1010101;
    puVar6[8] = 0;
    puVar6[5] = 0;
    puVar6[6] = 0;
    puVar6[2] = param_2;
    arena = ((int (*)())FUN_00164e7c)(param_1,operandVReg,inst,0,0,3);
    puVar6[4] = arena;
    puVar6[7] = inst[3];
  }
  puVar19 = *(uint **)(iVar4 + 0x40);
  uVar17 = puVar19[1];
  if (uVar17 < *puVar19) {
    _memset(uVar17 * 4 + puVar19[2],0,4);
    piVar3 = (int *)(uVar17 * 4 + puVar19[2]);
    puVar19[1] = uVar17 + 1;
  }
  else {
    piVar3 = (int *)Vector__elementRefGrow(puVar19,uVar17);
  }
  *piVar3 = (int)(puVar6 + 1);
  puVar19 = *(uint **)(param_2 + 0x44);
  uVar17 = puVar19[1];
  if (uVar17 < *puVar19) {
    _memset(uVar17 * 4 + puVar19[2],0,4);
    piVar3 = (int *)(uVar17 * 4 + puVar19[2]);
    puVar19[1] = uVar17 + 1;
  }
  else {
    piVar3 = (int *)Vector__elementRefGrow(puVar19,uVar17);
  }
  *piVar3 = (int)(puVar6 + 1);
  return;
LAB_00168b48:
  puVar19 = (uint *)param_1[6];
  uVar17 = operandVReg[0x54];
  if (uVar17 < *puVar19) {
    uVar12 = puVar19[1];
    if (uVar12 <= uVar17) {
      _memset(uVar12 * 4 + puVar19[2],0,(uVar17 - uVar12) * 4 + 4);
      puVar19[1] = uVar17 + 1;
    }
    piVar7 = (int *)(uVar17 * 4 + puVar19[2]);
  }
  else {
    piVar7 = (int *)Vector__elementRefGrow(puVar19,uVar17);
  }
  iVar4 = *piVar7;
  goto LAB_00168844;
}

/* FUN_00168d80 @ 0x168d80 (2668 bytes) */
int FUN_00168d80(param_1, param_2)
  int *param_1;
  int param_2;
{
  undefined1 uVar1;
  undefined *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 *allocation;
  undefined4 *puVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  int *piVar19;
  undefined1 *puVar20;
  undefined1 *puVar21;
  undefined4 arena;
  int iVar23;
  uint *puVar24;
  int *piVar25;
  undefined4 *puVar26;
  int local_88;
  int local_84;
  undefined4 local_80;
  undefined4 local_7c;
  int local_78;
  uint local_74;
  uint local_70;
  uint local_6c;
  uint local_68;
  undefined4 local_64;
  undefined4 local_60;
  
  piVar25 = *(int **)(param_2 + 0x38);
  iVar6 = (**(code **)(*(int *)param_1[2] + 0x40))((int *)param_1[2],piVar25,&local_88,&local_84);
  if (iVar6 == 0) {
    return 0;
  }
  param_1[0x6a] = param_1[0x6a] + 1;
  iVar7 = ((int (*)())FUN_00165d3c)(param_1,iVar6,param_2 + 0xc,*(undefined4 *)(param_2 + 0x30));
  local_60 = IRInst__getOperandSource(piVar25,1);
  local_64 = IRInst__getOperandSource(piVar25,2);
  iVar8 = IRInst__getOperandRecord(piVar25,1);
  local_80 = *(uint *)(iVar8 + 0x10);
  iVar8 = IRInst__getOperandRecord(piVar25,2);
  local_7c = *(uint *)(iVar8 + 0x10);
  iVar8 = IRInst__getOperandRecord(piVar25,0);
  uVar4 = piVar25[5];
  local_68 = piVar25[0x2e] & 1;
  local_70 = (uint)piVar25[0x2e] >> 1 & 1;
  local_6c = piVar25[0x34] & 1;
  local_74 = (uint)piVar25[0x34] >> 1 & 1;
  iVar18 = *(int *)(iVar8 + 0x10);
  uVar17 = uVar4 >> 1 & 1;
  uVar14 = uVar4 >> 5 & 1;
  iVar15 = piVar25[0x26];
  iVar16 = piVar25[0x25];
  iVar12 = piVar25[0x48];
  iVar13 = piVar25[0x49];
  iVar8 = piVar25[3];
  local_78 = 0;
  if ((uVar4 & 0x200) != 0) {
    local_78 = IRInst__getOperandSource(piVar25,piVar25[0x21]);
  }
  iVar5 = *(int *)(*(int *)(iVar6 + 0x88) + 8);
  piVar19 = piVar25;
  if (iVar5 == 0x13) {
    FUN_0017212c(param_1[2],param_2);
    if (*(int *)(piVar25[0x22] + 8) == 0x1c) {
      FUN_00108304(piVar25,0x1e,*param_1);
      IRInst__setOperandSource(piVar25,3,iVar6,0,*param_1);
      uVar9 = DAT_001b01a0;
      iVar5 = IRInst__getOperandRecord(piVar25,3);
      *(undefined4 *)(iVar5 + 0x10) = uVar9;
      (**(code **)(*piVar25 + 0x88))(piVar25,3,2,local_84);
      uVar4 = local_80;
      iVar5 = IRInst__getOperandRecord(piVar25,1);
      uVar3 = local_7c;
      *(uint *)(iVar5 + 0x10) = uVar4;
      iVar5 = IRInst__getOperandRecord(piVar25,2);
      *(uint *)(iVar5 + 0x10) = uVar3;
      if (local_88 < 2) {
        puVar20 = (undefined1 *)((int)&local_80 + local_88 + 1);
        puVar21 = (undefined1 *)((int)&local_7c + local_88 + 1);
        iVar5 = local_88;
        do {
          iVar23 = iVar5 + 1;
          uVar1 = *puVar20;
          puVar20 = puVar20 + 1;
          (**(code **)(*piVar25 + 0x88))(piVar25,1,iVar5,uVar1);
          uVar1 = *puVar21;
          puVar21 = puVar21 + 1;
          (**(code **)(*piVar25 + 0x88))(piVar25,2,iVar5,uVar1);
          iVar5 = iVar23;
        } while (iVar23 != 2);
      }
      (**(code **)(*piVar25 + 0x88))(piVar25,1,2,4);
      (**(code **)(*piVar25 + 0x88))(piVar25,2,2,4);
    }
    else {
      piVar19 = (int *)0x0;
      if (*(int *)(piVar25[0x22] + 8) == 0x1d) {
        FUN_00108304(piVar25,0xa3,*param_1);
        IRInst__setOperandSource(piVar25,3,iVar6,0,*param_1);
        uVar9 = DAT_001b01a0;
        iVar5 = IRInst__getOperandRecord(piVar25,3);
        *(undefined4 *)(iVar5 + 0x10) = uVar9;
        (**(code **)(*piVar25 + 0x88))(piVar25,3,3,local_84);
        uVar4 = local_80;
        iVar5 = IRInst__getOperandRecord(piVar25,1);
        uVar3 = local_7c;
        *(uint *)(iVar5 + 0x10) = uVar4;
        iVar5 = IRInst__getOperandRecord(piVar25,2);
        *(uint *)(iVar5 + 0x10) = uVar3;
        if (local_88 < 3) {
          puVar20 = (undefined1 *)((int)&local_80 + local_88 + 1);
          puVar21 = (undefined1 *)((int)&local_7c + local_88 + 1);
          iVar5 = local_88;
          do {
            iVar23 = iVar5 + 1;
            uVar1 = *puVar20;
            puVar20 = puVar20 + 1;
            (**(code **)(*piVar25 + 0x88))(piVar25,1,iVar5,uVar1);
            uVar1 = *puVar21;
            puVar21 = puVar21 + 1;
            (**(code **)(*piVar25 + 0x88))(piVar25,2,iVar5,uVar1);
            iVar5 = iVar23;
          } while (iVar23 != 3);
        }
        (**(code **)(*piVar25 + 0x88))(piVar25,1,3,4);
        (**(code **)(*piVar25 + 0x88))(piVar25,2,3,4);
        piVar19 = piVar25;
      }
    }
    if (uVar17 == 0) {
      piVar19[0x25] = iVar16;
      piVar19[0x26] = iVar15;
      if (uVar14 == 0) {
        piVar19[5] = piVar19[5] & 0xffffffdf;
      }
      else {
        piVar19[5] = piVar19[5] | 0x20;
      }
    }
    else {
      FUN_0010469c(piVar19,param_1[1],iVar15,iVar16);
    }
    piVar19[0x27] = iVar18;
    piVar19[0x48] = iVar12;
    piVar19[0x49] = iVar13;
    piVar19[3] = iVar8;
    IRInst__setOperandSource(piVar19,1,local_60,0,*param_1);
    IROperand__setModifierBits(piVar19 + 0x29,2,local_70);
    IROperand__setModifierBits(piVar19 + 0x29,1,local_68);
    IRInst__setOperandSource(piVar19,2,local_64,0,*param_1);
    IROperand__setModifierBits(piVar19 + 0x2f,2,local_74);
    IROperand__setModifierBits(piVar19 + 0x2f,1,local_6c);
  }
  else {
    if (iVar5 != 0x14) {
      if (iVar5 != 0x1c) {
        return iVar7;
      }
      FUN_0017212c(param_1[2],param_2);
      FUN_00108304(piVar25,0x14,*param_1);
      if (uVar17 == 0) {
        piVar25[0x25] = iVar16;
        piVar25[0x26] = iVar15;
        if (uVar14 == 0) {
          piVar25[5] = piVar25[5] & 0xffffffdf;
        }
        else {
          piVar25[5] = piVar25[5] | 0x20;
        }
      }
      else {
        FUN_0010469c(piVar25,param_1[1],iVar15,iVar16);
      }
      piVar25[0x48] = iVar12;
      piVar25[0x49] = iVar13;
      piVar25[3] = iVar8;
      IRInst__setOperandSource(piVar25,1,local_60,0,*param_1);
      IROperand__setModifierBits(piVar25 + 0x29,2,local_70);
      IROperand__setModifierBits(piVar25 + 0x29,1,local_68);
      IRInst__setOperandSource(piVar25,2,local_64,0,*param_1);
      IROperand__setModifierBits(piVar25 + 0x2f,2,local_74);
      IROperand__setModifierBits(piVar25 + 0x2f,1,local_6c);
      IRInst__setOperandSource(piVar25,3,iVar6,0,*param_1);
      piVar25[0x27] = iVar18;
      puVar2 = PTR_DAT_001e8b8c;
      uVar9 = *(undefined4 *)(PTR_DAT_001e8b8c + (local_80 & 0xff) * 4);
      iVar8 = IRInst__getOperandRecord(piVar25,1);
      *(undefined4 *)(iVar8 + 0x10) = uVar9;
      uVar9 = *(undefined4 *)(puVar2 + (local_7c & 0xff) * 4);
      iVar8 = IRInst__getOperandRecord(piVar25,2);
      *(undefined4 *)(iVar8 + 0x10) = uVar9;
      uVar9 = UNK_001b019c;
      iVar8 = IRInst__getOperandRecord(piVar25,3);
      *(undefined4 *)(iVar8 + 0x10) = uVar9;
      FUN_000f35c4(piVar25);
      if (local_78 != 0) {
        IRInst__setExtraOperandSource(piVar25,local_78,0,*param_1);
      }
      uVar9 = (**(code **)(*(int *)param_1[2] + 0x4c))((int *)param_1[2],piVar25);
      *(undefined4 *)(param_2 + 0x58) = uVar9;
      iVar8 = Compiler__isOptionEnabled(*param_1,0x28);
      if (iVar8 != 0) {
        iVar8 = (**(code **)(*(int *)param_1[2] + 0x34))((int *)param_1[2],param_2);
        uVar9 = 1;
        if (iVar8 != 0) goto code_r0x001699c4;
      }
      uVar9 = 0;
code_r0x001699c4:
      *(undefined4 *)(param_2 + 0x5c) = uVar9;
      (**(code **)(*(int *)param_1[2] + 0x48))((int *)param_1[2],param_2);
      FUN_00172078(param_1[2],param_2);
      arena = *(undefined4 *)(*param_1 + 0x378);
      allocation = (undefined4 *)Arena__alloc(arena,0x24);
      uVar9 = DAT_001b0194;
      *allocation = arena;
      allocation[1] = iVar7;
      allocation[7] = uVar9;
      allocation[3] = 0;
      allocation[4] = 1;
      allocation[5] = 0;
      allocation[6] = 0;
      allocation[8] = 0;
      allocation[2] = param_2;
      uVar9 = ((int (*)())FUN_00164e7c)(param_1,iVar6,piVar25,0,3,0);
      allocation[4] = uVar9;
      allocation[5] = 3;
      allocation[7] = 0;
      *(undefined1 *)(allocation + 7) = 1;
      puVar24 = *(uint **)(iVar7 + 0x40);
      uVar4 = puVar24[1];
      if (uVar4 < *puVar24) {
        _memset(uVar4 * 4 + puVar24[2],0,4);
        piVar25 = (int *)(uVar4 * 4 + puVar24[2]);
        puVar24[1] = uVar4 + 1;
      }
      else {
        piVar25 = (int *)Vector__elementRefGrow(puVar24,uVar4);
      }
      *piVar25 = (int)(allocation + 1);
      puVar24 = *(uint **)(param_2 + 0x44);
      uVar4 = puVar24[1];
      if (uVar4 < *puVar24) {
        _memset(uVar4 * 4 + puVar24[2],0,4);
        piVar25 = (int *)(uVar4 * 4 + puVar24[2]);
        puVar24[1] = uVar4 + 1;
      }
      else {
        piVar25 = (int *)Vector__elementRefGrow(puVar24,uVar4);
      }
      *piVar25 = (int)(allocation + 1);
      ((int (*)())FUN_00166844)(param_1,param_2,iVar7);
      iVar8 = *(int *)(param_2 + 0x34);
      iVar6 = *(int *)(param_2 + 0x30);
      *(undefined4 *)(iVar7 + 0x48) = 1;
      *(int *)(param_2 + 0x34) = iVar8 + 1;
      if (iVar6 < param_1[0xb] + allocation[4]) {
        iVar6 = param_1[0xb] + allocation[4];
      }
      *(int *)(param_2 + 0x30) = iVar6;
      return iVar7;
    }
    FUN_0017212c(param_1[2],param_2);
    if (*(int *)(piVar25[0x22] + 8) == 0x1e) {
      FUN_00108304(piVar25,0x14,*param_1);
      piVar25[0x27] = iVar18;
      puVar2 = PTR_DAT_001e8b8c;
      uVar9 = *(undefined4 *)
               (PTR_DAT_001e8b8c + (uint)*(byte *)((int)&local_80 + (1 - local_88)) * 4);
      iVar18 = IRInst__getOperandRecord(piVar25,1);
      *(undefined4 *)(iVar18 + 0x10) = uVar9;
      uVar9 = *(undefined4 *)(puVar2 + (uint)*(byte *)((int)&local_7c + (1 - local_88)) * 4);
      iVar18 = IRInst__getOperandRecord(piVar25,2);
      *(undefined4 *)(iVar18 + 0x10) = uVar9;
      uVar9 = *(undefined4 *)(puVar2 + local_84 * 4);
      iVar18 = IRInst__getOperandRecord(piVar25,3);
      *(undefined4 *)(iVar18 + 0x10) = uVar9;
      FUN_000f35c4(piVar25);
    }
    else {
      piVar19 = (int *)0x0;
      if (*(int *)(piVar25[0x22] + 8) == 0xa3) {
        FUN_00108304(piVar25,0x1e,*param_1);
        uVar4 = local_80;
        piVar25[0x27] = iVar18;
        iVar18 = IRInst__getOperandRecord(piVar25,1);
        uVar3 = local_7c;
        *(uint *)(iVar18 + 0x10) = uVar4;
        iVar18 = IRInst__getOperandRecord(piVar25,2);
        *(uint *)(iVar18 + 0x10) = uVar3;
        if (local_88 < 2) {
          puVar20 = (undefined1 *)((int)&local_80 + local_88 + 1);
          puVar21 = (undefined1 *)((int)&local_7c + local_88 + 1);
          iVar18 = local_88;
          do {
            iVar5 = iVar18 + 1;
            uVar1 = *puVar20;
            puVar20 = puVar20 + 1;
            (**(code **)(*piVar25 + 0x88))(piVar25,1,iVar18,uVar1);
            uVar1 = *puVar21;
            puVar21 = puVar21 + 1;
            (**(code **)(*piVar25 + 0x88))(piVar25,2,iVar18,uVar1);
            iVar18 = iVar5;
          } while (iVar5 != 2);
        }
        (**(code **)(*piVar25 + 0x88))(piVar25,1,2,4);
        (**(code **)(*piVar25 + 0x88))(piVar25,2,2,4);
        uVar9 = DAT_001b01a0;
        iVar18 = IRInst__getOperandRecord(piVar25,3);
        *(undefined4 *)(iVar18 + 0x10) = uVar9;
        (**(code **)(*piVar25 + 0x88))(piVar25,3,2,local_84);
        piVar19 = piVar25;
      }
    }
    if (uVar17 == 0) {
      piVar19[0x25] = iVar16;
      piVar19[0x26] = iVar15;
      if (uVar14 == 0) {
        piVar19[5] = piVar19[5] & 0xffffffdf;
      }
      else {
        piVar19[5] = piVar19[5] | 0x20;
      }
    }
    else {
      FUN_0010469c(piVar19,param_1[1],iVar15,iVar16);
    }
    piVar19[0x48] = iVar12;
    piVar19[0x49] = iVar13;
    piVar19[3] = iVar8;
    IRInst__setOperandSource(piVar19,1,local_60,0,*param_1);
    IROperand__setModifierBits(piVar19 + 0x29,2,local_70);
    IROperand__setModifierBits(piVar19 + 0x29,1,local_68);
    IRInst__setOperandSource(piVar19,2,local_64,0,*param_1);
    IROperand__setModifierBits(piVar19 + 0x2f,2,local_74);
    IROperand__setModifierBits(piVar19 + 0x2f,1,local_6c);
    IRInst__setOperandSource(piVar19,3,iVar6,0,*param_1);
  }
  if (local_78 != 0) {
    IRInst__setExtraOperandSource(piVar19,local_78,0,*param_1);
  }
  uVar9 = (**(code **)(*(int *)param_1[2] + 0x4c))((int *)param_1[2],piVar19);
  *(undefined4 *)(param_2 + 0x58) = uVar9;
  iVar8 = Compiler__isOptionEnabled(*param_1,0x28);
  if (iVar8 != 0) {
    iVar8 = (**(code **)(*(int *)param_1[2] + 0x34))((int *)param_1[2],param_2);
    uVar9 = 1;
    if (iVar8 != 0) goto LAB_00169620;
  }
  uVar9 = 0;
LAB_00169620:
  *(undefined4 *)(param_2 + 0x5c) = uVar9;
  (**(code **)(*(int *)param_1[2] + 0x48))((int *)param_1[2],param_2);
  FUN_00172078(param_1[2],param_2);
  arena = *(undefined4 *)(*param_1 + 0x378);
  allocation = (undefined4 *)Arena__alloc(arena,0x24);
  uVar9 = DAT_001b0194;
  puVar26 = allocation + 1;
  *allocation = arena;
  allocation[1] = iVar7;
  allocation[7] = uVar9;
  allocation[3] = 0;
  allocation[4] = 1;
  allocation[5] = 0;
  allocation[6] = 0;
  allocation[8] = 0;
  allocation[2] = param_2;
  uVar9 = ((int (*)())FUN_00164e7c)(param_1,iVar6,piVar19,0,3,0);
  allocation[4] = uVar9;
  allocation[5] = 3;
  allocation[7] = 0;
  *(undefined1 *)((int)puVar26 + local_84 + 0x18) = 1;
  puVar24 = *(uint **)(iVar7 + 0x40);
  uVar4 = puVar24[1];
  if (uVar4 < *puVar24) {
    _memset(uVar4 * 4 + puVar24[2],0,4);
    puVar11 = (undefined4 *)(uVar4 * 4 + puVar24[2]);
    puVar24[1] = uVar4 + 1;
  }
  else {
    puVar11 = (undefined4 *)Vector__elementRefGrow(puVar24,uVar4);
  }
  *puVar11 = puVar26;
  puVar24 = *(uint **)(param_2 + 0x44);
  uVar4 = puVar24[1];
  if (uVar4 < *puVar24) {
    _memset(uVar4 * 4 + puVar24[2],0,4);
    puVar11 = (undefined4 *)(uVar4 * 4 + puVar24[2]);
    puVar24[1] = uVar4 + 1;
  }
  else {
    puVar11 = (undefined4 *)Vector__elementRefGrow(puVar24,uVar4);
  }
  *puVar11 = puVar26;
  ((int (*)())FUN_00166844)(param_1,param_2,iVar7);
  *(int *)(param_2 + 0x34) = *(int *)(param_2 + 0x34) + 1;
  *(undefined4 *)(local_84 * 4 + iVar7 + 0x48) = 1;
  iVar6 = *(int *)(param_2 + 0x30);
  if (*(int *)(param_2 + 0x30) < param_1[0xb] + allocation[4]) {
    iVar6 = param_1[0xb] + allocation[4];
  }
  *(int *)(param_2 + 0x30) = iVar6;
  return iVar7;
}

/* FUN_00169b70 @ 0x169b70 (680 bytes) */
int FUN_00169b70(param_1)
  int param_1;
{
  uint loopIndex;
  int iVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint *puVar10;
  int iVar11;
  /* NOTE (issue #64): auStack_48 was declared 8 bytes, but FUN_001940a8's sentinel-list init writes through
   * +0x14 (6 words) - confirmed live/via stock disasm: it writes local_40 (frame+0x40, i.e. auStack_48+8) as
   * part of the SAME sentinel struct (the self-referential "list head" pointer), not a separately-initialized
   * local. -O0 doesn't lay declared locals contiguously, so the two must be one buffer (classic stack-split
   * artifact, same class as the FUN_00170e6c/FUN_00171e68 fixes already landed on this issue). */
  undefined4 auStack_48_vec169b70[6];
#define auStack_48 ((unsigned char *)auStack_48_vec169b70)
#define local_40 ((int)auStack_48_vec169b70[2])
  
  uVar8 = 0;
  FUN_001940a8(auStack_48);
  puVar10 = *(uint **)(param_1 + 0x18);
  uVar7 = puVar10[1];
  if (0 < (int)uVar7) {
    do {
      if (uVar8 < *puVar10) {
        uVar2 = puVar10[1];
        if (uVar2 <= uVar8) {
          _memset(uVar2 * 4 + puVar10[2],0,(uVar8 - uVar2) * 4 + 4);
          puVar10[1] = uVar8 + 1;
        }
        piVar3 = (int *)(uVar8 * 4 + puVar10[2]);
      }
      else {
        piVar3 = (int *)Vector__elementRefGrow(puVar10,uVar8);
      }
      iVar6 = *piVar3;
      /* issue #76: same shared-array gap as FUN_0016a568/FUN_0016bd70/FUN_001670fc - skip a
       * never-populated param_1[0x18]-array slot instead of dereferencing it. */
      if (iVar6 == 0) goto LAB_issue76_skip_169b70;
      loopIndex = 0;
      puVar10 = *(uint **)(iVar6 + 0x44);
      uVar9 = puVar10[1];
      if (0 < (int)uVar9) {
        while( true ) {
          if (loopIndex < *puVar10) {
            uVar4 = puVar10[1];
            if (uVar4 <= loopIndex) {
              _memset(uVar4 * 4 + puVar10[2],0,(loopIndex - uVar4) * 4 + 4);
              puVar10[1] = loopIndex + 1;
            }
            piVar3 = (int *)(loopIndex * 4 + puVar10[2]);
          }
          else {
            piVar3 = (int *)Vector__elementRefGrow(puVar10,loopIndex);
          }
          loopIndex = loopIndex + 1;
          iVar1 = *(int *)(*(int *)*piVar3 + 0x18) + ((int *)*piVar3)[3];
          iVar11 = *(int *)(iVar6 + 0x18);
          if (*(int *)(iVar6 + 0x18) < iVar1) {
            iVar11 = iVar1;
          }
          *(int *)(iVar6 + 0x18) = iVar11;
          if (uVar9 == loopIndex) break;
          puVar10 = *(uint **)(iVar6 + 0x44);
        }
      }
      iVar11 = local_40;
      if ((*(uint *)(*(int *)(iVar6 + 0x38) + 0x14) & 2) != 0) {
        do {
          iVar1 = iVar11;
          iVar11 = 0;
          if (*(int *)(iVar1 + 8) == 0) goto LAB_00169d08;
          iVar11 = *(int *)(iVar1 + 8);
        } while (*(int *)(iVar6 + 0x18) <= *(int *)(iVar1 + 0x18));
        DList__insertBefore(iVar6,iVar1);
        iVar11 = *(int *)(iVar1 + 8);
LAB_00169d08:
        if (iVar11 == 0) {
          DList__pushBack(auStack_48,iVar6);
        }
      }
LAB_issue76_skip_169b70:
      uVar8 = uVar8 + 1;
      if (uVar7 == uVar8) break;
      puVar10 = *(uint **)(param_1 + 0x18);
    } while( true );
  }
  *(undefined4 *)(param_1 + 0xf4) = 0;
  while (iVar6 = FUN_00193f08(auStack_48), iVar6 == 0) {
    (**(code **)(**(int **)(param_1 + 8) + 8))(*(int **)(param_1 + 8));
    iVar6 = local_40;
    (**(code **)(**(int **)(param_1 + 8) + 0x10))
              (*(int **)(param_1 + 8),*(undefined4 *)(local_40 + 0x38));
    iVar11 = *(int *)(iVar6 + 8);
    DList__unlink(iVar6);
    while (iVar1 = iVar11, iVar11 = *(int *)(iVar1 + 8), iVar11 != 0) {
      iVar5 = (**(code **)(**(int **)(param_1 + 8) + 0xc))
                        (*(int **)(param_1 + 8),*(undefined4 *)(iVar1 + 0x38));
      if (iVar5 != 0) {
        (**(code **)(**(int **)(param_1 + 8) + 0x10))
                  (*(int **)(param_1 + 8),*(undefined4 *)(iVar1 + 0x38));
        *(undefined4 *)(iVar1 + 0x68) = 1;
        *(int *)(param_1 + 0xf4) = *(int *)(param_1 + 0xf4) + 1;
        *(undefined4 *)(iVar6 + 0x68) = 1;
        DList__unlink(iVar1);
      }
    }
    if (*(int *)(iVar6 + 0x68) != 0) {
      *(int *)(param_1 + 0xf4) = *(int *)(param_1 + 0xf4) + 1;
    }
  }
  return;
}

/* FUN_00169e30 @ 0x169e30 (1848 bytes) */
int FUN_00169e30(compiler)
  int *compiler;
{
  int *operandVReg2;
  int *operandVReg;
  int loopIndex;
  uint uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int in_r7;
  undefined4 in_r8;
  int *piVar11;
  undefined4 in_r10;
  int *piVar12;
  undefined4 uVar13;
  int iVar14;
  int local_38 [3];
  
  iVar2 = *(int *)(*compiler + 0x324) << 2;
  iVar7 = Arena__alloc(*(undefined4 *)(*compiler + 0x378),iVar2);
  iVar8 = Arena__alloc(*(undefined4 *)(*compiler + 0x378),iVar2);
  iVar2 = compiler[1];
  piVar11 = (int *)(*(int **)(iVar2 + 900))[2];
  piVar12 = *(int **)(iVar2 + 900);
  if (piVar11 != (int *)0x0) {
    do {
      piVar4 = piVar11;
      piVar11 = (int *)((int *)piVar12[0x26])[2];
      piVar5 = (int *)piVar12[0x26];
      if (piVar11 != (int *)0x0) {
        do {
          piVar4 = piVar11;
          if ((piVar5[5] & 1U) != 0) {
            *(int *)(iVar7 + piVar5[0x53] * 4) = piVar5[0x53];
            *(undefined4 *)(piVar5[0x53] * 4 + iVar8) = 0;
            iVar2 = IRInst__getOperandRecord(piVar5,0);
            FUN_000f3908(local_38,*(undefined4 *)(iVar2 + 0x10));
            piVar5[3] = local_38[0];
            in_r7 = *compiler;
            IRInst__setOperandSource(piVar5,0,0,0,in_r7);
            iVar2 = (**(code **)(*piVar12 + 0x14))(piVar12);
            if (iVar2 != 0) {
              piVar5[5] = piVar5[5] | 0x20;
            }
            iVar2 = (**(code **)(*piVar5 + 0x7c))(piVar5);
            if (iVar2 == 0) {
              if ((*(int *)(piVar5[0x22] + 8) == 0x32) &&
                 (iVar2 = (**(code **)(**(int **)(*compiler + 0x30c) + 0xd0))
                                    (*(int **)(*compiler + 0x30c)), iVar2 == 0)) {
                piVar4 = (int *)piVar5[2];
                piVar5[5] = piVar5[5] | 0x20;
                goto LAB_0016a118;
              }
              if (0 < piVar5[0x21]) {
                iVar2 = 1;
                do {
                  operandVReg = (int *)IRInst__getOperandSource(piVar5,iVar2);
                  iVar3 = (**(code **)(*operandVReg + 0x5c))(operandVReg);
                  if ((iVar3 == 0) && (iVar3 = (**(code **)(*operandVReg + 0x60))(operandVReg), iVar3 == 0))
                  {
                    if (operandVReg[0x56] != piVar5[0x56]) {
                      operandVReg[5] = operandVReg[5] | 0x20;
                    }
                  }
                  else if (0 < operandVReg[0x21]) {
                    iVar3 = 1;
                    do {
                      operandVReg2 = (int *)IRInst__getOperandSource(operandVReg,iVar3);
                      iVar9 = (**(code **)(*operandVReg2 + 0x5c))(operandVReg2);
                      if (iVar9 == 0) {
                        if (operandVReg2[0x56] != piVar5[0x56]) {
                          operandVReg2[5] = operandVReg2[5] | 0x20;
                        }
                      }
                      else if (0 < operandVReg2[0x21]) {
                        loopIndex = 1;
                        do {
                          iVar10 = IRInst__getOperandSource(operandVReg2,loopIndex);
                          if (*(int *)(iVar10 + 0x158) != piVar5[0x56]) {
                            *(uint *)(iVar10 + 0x14) = *(uint *)(iVar10 + 0x14) | 0x20;
                          }
                          loopIndex = loopIndex + 1;
                        } while (loopIndex <= operandVReg2[0x21]);
                      }
                      iVar3 = iVar3 + 1;
                    } while (iVar3 <= operandVReg[0x21]);
                  }
                  iVar2 = iVar2 + 1;
                } while (iVar2 <= piVar5[0x21]);
              }
            }
            else {
              piVar5[5] = piVar5[5] | 0x20;
              if (0 < piVar5[0x21]) {
                iVar2 = 1;
                do {
                  iVar9 = IRInst__getOperandSource(piVar5,iVar2);
                  iVar3 = piVar5[0x21];
                  iVar2 = iVar2 + 1;
                  *(uint *)(iVar9 + 0x14) = *(uint *)(iVar9 + 0x14) | 0x20;
                } while (iVar2 <= iVar3);
              }
            }
            piVar4 = (int *)piVar5[2];
          }
LAB_0016a118:
          piVar11 = (int *)piVar4[2];
          piVar5 = piVar4;
        } while ((int *)piVar4[2] != (int *)0x0);
        piVar4 = (int *)piVar12[2];
      }
      piVar11 = (int *)piVar4[2];
      piVar12 = piVar4;
    } while ((int *)piVar4[2] != (int *)0x0);
    iVar2 = compiler[1];
  }
  iVar3 = *(int *)(*(int *)(iVar2 + 900) + 8);
  iVar9 = *(int *)(iVar2 + 900);
  if (iVar3 != 0) {
    do {
      iVar2 = iVar3;
      piVar11 = (int *)(*(int **)(iVar9 + 0x98))[2];
      piVar12 = *(int **)(iVar9 + 0x98);
      if (piVar11 != (int *)0x0) {
        do {
          piVar5 = piVar11;
          if ((piVar12[5] & 1U) != 0) {
            if ((piVar12[5] & 0x200U) == 0) {
              iVar2 = (**(code **)(*piVar12 + 100))(piVar12);
              if (iVar2 == 0) {
LAB_0016a1fc:
                uVar1 = piVar12[5];
LAB_0016a200:
                if ((uVar1 & 0x20) != 0) {
                  iVar2 = FUN_001952d8(piVar12[0x53],iVar7);
                  *(undefined4 *)(iVar2 * 4 + iVar8) = 1;
                }
                piVar5 = (int *)piVar12[2];
                goto LAB_0016a42c;
              }
              for (iVar2 = 1; iVar3 = (**(code **)(*piVar12 + 0x14))(piVar12), iVar2 <= iVar3;
                  iVar2 = iVar2 + 1) {
                if ((((piVar12[iVar2 * 6 + 0x28] & 1U) != 0) ||
                    ((piVar12[iVar2 * 6 + 0x28] & 2U) != 0)) ||
                   (iVar3 = FUN_000f31e8(piVar12,iVar2), iVar3 == 0)) goto LAB_0016a1fc;
              }
              if ((piVar12[0x48] != 0) || (piVar12[0x49] != 0)) goto LAB_0016a1fc;
              if (((piVar12[0x20] != 0) &&
                  ((iVar2 = FUN_00126760(piVar12[0x26]), iVar2 != 0 && ((piVar12[5] & 2U) == 0))))
                 && (iVar2 = (**(code **)(*piVar12 + 0x50))(piVar12), iVar2 == 0)) {
                iVar2 = 4;
                piVar11 = piVar12;
                do {
                  if ((uint)(*(byte *)(piVar11 + 0x27) - 2) < 2) goto LAB_0016a1fc;
                  piVar11 = (int *)((int)piVar11 + 1);
                  iVar2 = iVar2 + -1;
                } while (iVar2 != 0);
              }
              IRInst__getOperandRecord(piVar12,0);
              iVar2 = FUN_00105dbc(piVar12,0);
              if (iVar2 != 0) goto LAB_0016a1fc;
              uVar1 = piVar12[5];
              if (((uVar1 & 2) != 0) || ((uVar1 & 0x200) != 0)) goto LAB_0016a200;
              iVar3 = piVar12[0x53];
              iVar2 = IRInst__getOperandSource(piVar12,1);
              uVar13 = *(undefined4 *)(iVar2 + 0x14c);
              iVar3 = FUN_001952d8(iVar3,iVar7);
              iVar2 = FUN_001952d8(uVar13,iVar7);
              if (((*(int *)(iVar8 + iVar2 * 4) == 0) && (*(int *)(iVar8 + iVar3 * 4) == 0)) &&
                 ((piVar12[5] & 0x20U) == 0)) {
                iVar10 = IRInst__getOperandSource(piVar12,1);
                uVar13 = 0;
                if ((*(uint *)(iVar10 + 0x14) & 0x20) != 0) goto LAB_0016a3d8;
              }
              else {
LAB_0016a3d8:
                uVar13 = 1;
              }
              *(undefined4 *)(iVar8 + iVar2 * 4) = uVar13;
              *(undefined4 *)(iVar8 + iVar3 * 4) = uVar13;
              iVar10 = iVar3;
              if (iVar2 <= iVar3) goto LAB_0016a3ec;
            }
            else {
              iVar3 = piVar12[0x53];
              iVar2 = IRInst__getOperandSource(piVar12,piVar12[0x21]);
              uVar13 = *(undefined4 *)(iVar2 + 0x14c);
              iVar3 = FUN_001952d8(iVar3,iVar7);
              iVar2 = FUN_001952d8(uVar13,iVar7);
              if (((*(int *)(iVar8 + iVar2 * 4) == 0) && (*(int *)(iVar8 + iVar3 * 4) == 0)) &&
                 ((piVar12[5] & 0x20U) == 0)) {
                iVar10 = IRInst__getOperandSource(piVar12,piVar12[0x21]);
                uVar13 = 0;
                if ((*(uint *)(iVar10 + 0x14) & 0x20) != 0) goto LAB_0016a20c;
              }
              else {
LAB_0016a20c:
                uVar13 = 1;
              }
              *(undefined4 *)(iVar8 + iVar2 * 4) = uVar13;
              *(undefined4 *)(iVar8 + iVar3 * 4) = uVar13;
              iVar10 = iVar3;
              if (iVar2 <= iVar3) {
LAB_0016a3ec:
                iVar10 = iVar2;
                iVar2 = iVar3;
              }
            }
            FUN_00195330(iVar10,iVar2,iVar7);
            piVar5 = (int *)piVar12[2];
          }
LAB_0016a42c:
          piVar11 = (int *)piVar5[2];
          piVar12 = piVar5;
        } while ((int *)piVar5[2] != (int *)0x0);
        iVar2 = *(int *)(iVar9 + 8);
      }
      iVar3 = *(int *)(iVar2 + 8);
      iVar9 = iVar2;
    } while (*(int *)(iVar2 + 8) != 0);
    iVar2 = compiler[1];
  }
  iVar3 = *(int *)(*(int *)(iVar2 + 900) + 8);
  if (iVar3 == 0) {
    iVar10 = 0;
    iVar9 = 0;
  }
  else {
    iVar10 = 0;
    iVar9 = 0;
    iVar2 = *(int *)(iVar2 + 900);
    do {
      iVar6 = iVar3;
      iVar3 = *(int *)(*(int *)(iVar2 + 0x98) + 8);
      iVar14 = *(int *)(iVar2 + 0x98);
      if (iVar3 != 0) {
        do {
          iVar6 = iVar3;
          if ((*(uint *)(iVar14 + 0x14) & 1) != 0) {
            iVar3 = FUN_001952d8(*(undefined4 *)(iVar14 + 0x14c),iVar7);
            if (*(int *)(iVar3 * 4 + iVar8) == 0) {
              uVar1 = *(uint *)(iVar14 + 0x14) & 0xffffffdf;
              *(uint *)(iVar14 + 0x14) = uVar1;
            }
            else {
              uVar1 = *(uint *)(iVar14 + 0x14) | 0x20;
              *(uint *)(iVar14 + 0x14) = uVar1;
            }
            if ((uVar1 & 0x20) != 0) {
              iVar9 = iVar9 + 1;
            }
            iVar6 = *(int *)(iVar14 + 8);
            iVar10 = iVar10 + 1;
          }
          iVar3 = *(int *)(iVar6 + 8);
          iVar14 = iVar6;
        } while (*(int *)(iVar6 + 8) != 0);
        iVar6 = *(int *)(iVar2 + 8);
      }
      iVar3 = *(int *)(iVar6 + 8);
      iVar2 = iVar6;
    } while (*(int *)(iVar6 + 8) != 0);
  }
  FUN_000e0e0c(*compiler,"Scheduler : %d out of %d instructions are marked global\n",iVar9,iVar10,
               in_r7,in_r8,0,in_r10);
  Arena__free(*(undefined4 *)(*compiler + 0x378),iVar8);
  return Arena__free(*(undefined4 *)(*compiler + 0x378),iVar7);
}

/* FUN_0016a568 @ 0x16a568 (6052 bytes) */
int FUN_0016a568(compiler, param_2)
  int *compiler;
  int param_2;
{
  bool bVar1;
  bool bVar2;
  undefined *puVar3;
  int *piVar4;
  int *piVar5;
  undefined *puVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  int iVar12;
  uint uVar13;
  int *piVar14;
  undefined4 *allocation;
  int iVar16;
  int iVar17;
  int iVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  int iVar22;
  int iVar23;
  undefined4 *puVar24;
  uint *puVar25;
  undefined4 arena;
  uint *puVar27;
  /* issue #64 live-repro (crash #11, past the 0x275c dropped-arg fix): auStack_78 is declared
   * as only 8 bytes, but FUN_001940a8(auStack_78) - a sentinel-node doubly-linked-list
   * initializer - writes through it as `undefined4*` up to index 5 (`compiler[4] = compiler;
   * compiler[5] = 0;`), i.e. 24 bytes: the same undersized-local defect class already fixed for
   * local_c08c/local_2c/local_98. The overrun silently landed on whatever gcc placed next on
   * this rebuild's stack instead of the intended sentinel-node fields, so the list's "head"
   * self-pointer (meant to make the sentinel point to itself when empty, per
   * DList__insertBefore/DList__pushBack's insert logic) never actually got set. Live-verified on real
   * hardware: the very next list-insert call (DList__pushBack(auStack_78,puVar24), a few lines
   * below) crashed dereferencing that missing self-pointer as a wild address. `local_70`,
   * declared right after, is independently used later in this function (part_044.c:10810-
   * 10858) and must keep its own storage - so auStack_78 gets its own full-sized buffer here
   * rather than being merged with its neighbors. */
  undefined1 auStack_78 [24];
  int local_70;
  uint local_58;
  int local_54;

  iVar7 = Compiler__isOptionEnabled(*compiler,0x24);
  uVar19 = 0x7fffffff;
  if (iVar7 == 0) {
    uVar19 = 0;
  }
  compiler[4] = param_2;
  FUN_00172000(compiler[2]);
  FUN_001940a8(auStack_78);
  piVar4 = (int *)(*(int **)(compiler[4] + 0x98))[2];
  if (piVar4 != (int *)0x0) {
    uVar20 = 0;
    bVar2 = false;
    piVar14 = *(int **)(compiler[4] + 0x98);
    do {
      piVar5 = piVar4;
      if ((piVar14[5] & 1U) != 0) {
        piVar14[5] = piVar14[5] & 0xffffefff;
        piVar14[0x54] = 0;
        iVar7 = (**(code **)(*piVar14 + 0x34))(piVar14);
        if ((iVar7 == 0) && (iVar7 = (**(code **)(*piVar14 + 0x38))(piVar14), iVar7 == 0)) {
          iVar7 = ((int (*)())FUN_00164df4)(piVar14);
          if (iVar7 == 0) {
            iVar7 = ((int (*)())FUN_00164fc0)(piVar14);
            if (((iVar7 != 0) ||
                (iVar7 = (**(code **)(*(int *)compiler[3] + 0x2c))((int *)compiler[3],piVar14),
                iVar7 != 0)) ||
               (iVar7 = (**(code **)(*(int *)compiler[3] + 0x28))((int *)compiler[3],piVar14),
               iVar7 != 0)) {
              bVar2 = true;
            }
            piVar14[0x54] = uVar20;
            arena = *(undefined4 *)(*compiler + 0x378);
            allocation = (undefined4 *)Arena__alloc(arena,0x74);
            puVar3 = PTR_DAT_001e9138;
            puVar24 = allocation + 1;
            puVar6 = PTR_DAT_001e8b48 + 8;
            *allocation = arena;
            allocation[1] = puVar6;
            allocation[0xc] = 0xffffffff;
            allocation[1] = puVar3 + 8;
            allocation[0x11] = 0;
            allocation[0x1c] = 0;
            iVar7 = 4;
            allocation[2] = 0;
            allocation[3] = 0;
            allocation[0xd] = 0;
            allocation[0xe] = 0;
            allocation[0xf] = piVar14;
            allocation[0x10] = uVar20;
            allocation[0x12] = 0;
            allocation[0x17] = 0;
            allocation[0x18] = 0;
            allocation[0x19] = 0;
            allocation[0x1a] = 0;
            allocation[0x1b] = 0;
            puVar11 = puVar24;
            do {
              puVar11[0x12] = 0;
              puVar11 = puVar11 + 1;
              iVar7 = iVar7 + -1;
            } while (iVar7 != 0);
            allocation[4] = 0;
            allocation[7] = 1;
            allocation[5] = 0;
            allocation[6] = 1;
            allocation[8] = 0;
            allocation[9] = 0;
            allocation[10] = 0;
            allocation[0xb] = 0;
            arena = *(undefined4 *)(*compiler + 0x378);
            puVar11 = (undefined4 *)Arena__alloc(arena,0x14);
            *puVar11 = arena;
            puVar11[1] = 2;
            puVar11[4] = arena;
            puVar11[2] = 0;
            arena = Arena__alloc(arena,8);
            puVar11[3] = arena;
            allocation[0x12] = puVar11 + 1;
            arena = *(undefined4 *)(*compiler + 0x378);
            puVar11 = (undefined4 *)Arena__alloc(arena,0x14);
            *puVar11 = arena;
            puVar11[1] = 2;
            puVar11[2] = 0;
            puVar11[4] = arena;
            arena = Arena__alloc(arena,8);
            puVar11[3] = arena;
            allocation[0x11] = puVar11 + 1;
            if (0 < piVar14[0x21]) {
              iVar7 = 1;
              bVar1 = false;
              do {
                ((int (*)())FUN_00168468)(compiler,puVar24,piVar14,iVar7,0);
                piVar4 = (int *)IRInst__getOperandSource(piVar14,iVar7);
                iVar17 = (**(code **)(*piVar4 + 0x5c))(piVar4);
                if (iVar17 == 0) {
                  piVar4 = (int *)IRInst__getOperandSource(piVar14,iVar7);
                  iVar17 = (**(code **)(*piVar4 + 0x60))(piVar4);
                  if (iVar17 != 0) goto LAB_0016a958;
                  arena = IRInst__getOperandSource(piVar14,iVar7);
                  iVar17 = FUN_001045e4(arena);
                  if ((iVar17 != 0) &&
                     (iVar17 = (**(code **)(**(int **)(*compiler + 0x30c) + 0xd4))
                                         (*(int **)(*compiler + 0x30c)), iVar17 != 0))
                  goto LAB_0016a958;
                }
                else {
LAB_0016a958:
                  piVar4 = (int *)IRInst__getOperandSource(piVar14,iVar7);
                  iVar17 = (**(code **)(*piVar4 + 0x60))(piVar4);
                  if (iVar17 != 0) {
                    piVar5 = (int *)IRInst__getOperandSource(piVar4,1);
                    iVar17 = (**(code **)(*piVar5 + 0x5c))(piVar5);
                    if (iVar17 != 0) {
                      piVar4 = (int *)IRInst__getOperandSource(piVar4,1);
                    }
                  }
                  for (iVar17 = 1; iVar16 = (**(code **)(*piVar4 + 0x14))(piVar4), iVar17 <= iVar16;
                      iVar17 = iVar17 + 1) {
                    ((int (*)())FUN_00168468)(compiler,puVar24,piVar4,iVar7,iVar17);
                  }
                }
                arena = IRInst__getOperandSource(piVar14,iVar7);
                iVar17 = FUN_00104644(arena);
                if (iVar17 != 0) {
                  bVar1 = true;
                }
                iVar7 = iVar7 + 1;
              } while (iVar7 <= piVar14[0x21]);
              if (bVar1) {
                puVar25 = (uint *)allocation[0x12];
                uVar13 = 0;
                uVar21 = puVar25[1];
                if (0 < (int)uVar21) {
                  while( true ) {
                    if (uVar13 < *puVar25) {
                      uVar9 = puVar25[1];
                      if (uVar9 <= uVar13) {
                        _memset(uVar9 * 4 + puVar25[2],0,(uVar13 - uVar9) * 4 + 4);
                        puVar25[1] = uVar13 + 1;
                      }
                      puVar11 = (undefined4 *)(uVar13 * 4 + puVar25[2]);
                    }
                    else {
                      puVar11 = (undefined4 *)Vector__elementRefGrow(puVar25,uVar13);
                    }
                    iVar17 = *(int *)*puVar11;
                    iVar7 = FUN_00104644(*(undefined4 *)(iVar17 + 0x38));
                    if (iVar7 == 0) {
                      uVar9 = 0;
                      do {
                        puVar25 = (uint *)allocation[0x12];
                        if (uVar9 < *puVar25) {
                          uVar8 = puVar25[1];
                          if (uVar8 <= uVar9) {
                            _memset(uVar8 * 4 + puVar25[2],0,(uVar9 - uVar8) * 4 + 4);
                            puVar25[1] = uVar9 + 1;
                          }
                          puVar11 = (undefined4 *)(uVar9 * 4 + puVar25[2]);
                        }
                        else {
                          puVar11 = (undefined4 *)Vector__elementRefGrow(puVar25,uVar9);
                        }
                        iVar16 = *(int *)*puVar11;
                        iVar7 = FUN_00104644(*(undefined4 *)(iVar16 + 0x38));
                        if ((iVar7 != 0) && (*(int *)(iVar17 + 0x3c) < *(int *)(iVar16 + 0x3c))) {
                          arena = *(undefined4 *)(*compiler + 0x378);
                          puVar11 = (undefined4 *)Arena__alloc(arena,0x24);
                          *puVar11 = arena;
                          puVar11[4] = 1;
                          puVar11[1] = iVar17;
                          puVar11[7] = 0x1010101;
                          puVar11[3] = 5;
                          puVar11[5] = 0;
                          puVar11[6] = 0;
                          puVar11[8] = 0;
                          puVar11[2] = iVar16;
                          arena = ((int (*)())FUN_00164e7c)(compiler,*(undefined4 *)(iVar17 + 0x38),
                                                *(undefined4 *)(iVar16 + 0x38),0,0,5);
                          puVar11[4] = arena;
                          puVar25 = *(uint **)(iVar17 + 0x40);
                          uVar8 = puVar25[1];
                          if (uVar8 < *puVar25) {
                            _memset(uVar8 * 4 + puVar25[2],0,4);
                            piVar4 = (int *)(uVar8 * 4 + puVar25[2]);
                            puVar25[1] = uVar8 + 1;
                          }
                          else {
                            piVar4 = (int *)Vector__elementRefGrow(puVar25,uVar8);
                          }
                          *piVar4 = (int)(puVar11 + 1);
                          puVar25 = *(uint **)(iVar16 + 0x44);
                          uVar8 = puVar25[1];
                          if (uVar8 < *puVar25) {
                            _memset(uVar8 * 4 + puVar25[2],0,4);
                            piVar4 = (int *)(uVar8 * 4 + puVar25[2]);
                            puVar25[1] = uVar8 + 1;
                          }
                          else {
                            piVar4 = (int *)Vector__elementRefGrow(puVar25,uVar8);
                          }
                          *piVar4 = (int)(puVar11 + 1);
                        }
                        uVar9 = uVar9 + 1;
                      } while (uVar21 != uVar9);
                    }
                    uVar13 = uVar13 + 1;
                    if (uVar21 == uVar13) break;
                    puVar25 = (uint *)allocation[0x12];
                  }
                }
              }
            }
            if (*(int *)(piVar14[0x22] + 4) == 1) {
              DList__pushBack(auStack_78,puVar24);
            }
            if (uVar19 == uVar20) {
              uVar13 = uVar20 - 1;
              if (-1 < (int)uVar13) {
                iVar7 = uVar13 * 4;
                uVar21 = 0;
                do {
                  puVar25 = (uint *)compiler[6];
                  if (uVar13 < *puVar25) {
                    uVar9 = puVar25[1];
                    if (uVar9 <= uVar13) {
                      _memset(uVar9 * 4 + puVar25[2],0,(uVar13 - uVar9) * 4 + 4);
                      puVar25[1] = uVar13 + 1;
                    }
                    piVar4 = (int *)(iVar7 + puVar25[2]);
                  }
                  else {
                    piVar4 = (int *)Vector__elementRefGrow(puVar25,uVar13);
                  }
                  iVar17 = *piVar4;
                  iVar16 = *(int *)(iVar17 + 0x38);
                  if (((*(uint *)(iVar16 + 0x14) & 2) == 0) &&
                     (*(int *)(*(int *)(iVar16 + 0x88) + 4) != 1)) {
                    arena = *(undefined4 *)(*compiler + 0x378);
                    puVar11 = (undefined4 *)Arena__alloc(arena,0x24);
                    *puVar11 = arena;
                    puVar11[1] = iVar17;
                    puVar11[7] = 0x1010101;
                    puVar11[8] = 0;
                    puVar11[4] = 1;
                    puVar11[5] = 0;
                    puVar11[6] = 0;
                    puVar11[2] = puVar24;
                    puVar11[3] = 1;
                    arena = ((int (*)())FUN_00164e7c)(compiler,iVar16,piVar14,0,0,1);
                    puVar11[4] = arena;
                    puVar25 = *(uint **)(iVar17 + 0x40);
                    uVar9 = puVar25[1];
                    if (uVar9 < *puVar25) {
                      _memset(uVar9 * 4 + puVar25[2],0,4);
                      puVar10 = (undefined4 *)(uVar9 * 4 + puVar25[2]);
                      puVar25[1] = uVar9 + 1;
                    }
                    else {
                      puVar10 = (undefined4 *)Vector__elementRefGrow(puVar25,uVar9);
                    }
                    *puVar10 = puVar11 + 1;
                    puVar25 = (uint *)allocation[0x12];
                    uVar9 = puVar25[1];
                    if (uVar9 < *puVar25) {
                      _memset(uVar9 * 4 + puVar25[2],0,4);
                      puVar10 = (undefined4 *)(uVar9 * 4 + puVar25[2]);
                      puVar25[1] = uVar9 + 1;
                    }
                    else {
                      puVar10 = (undefined4 *)Vector__elementRefGrow(puVar25,uVar9);
                    }
                    *puVar10 = puVar11 + 1;
                  }
                  uVar21 = uVar21 + 1;
                  uVar13 = uVar13 - 1;
                  iVar7 = iVar7 + -4;
                } while (uVar21 != uVar20);
              }
            }
            else if ((int)uVar19 < (int)uVar20) {
              puVar25 = (uint *)compiler[6];
              uVar13 = uVar20 - 1;
              if (uVar13 < *puVar25) {
                uVar21 = puVar25[1];
                if (uVar21 <= uVar13) {
                  _memset(uVar21 * 4 + puVar25[2],0,(uVar13 - uVar21) * 4 + 4);
                  puVar25[1] = uVar20;
                }
                piVar4 = (int *)(uVar13 * 4 + puVar25[2]);
              }
              else {
                piVar4 = (int *)Vector__elementRefGrow(puVar25,uVar13);
              }
              iVar17 = *piVar4;
              iVar7 = *(int *)(iVar17 + 0x38);
              if (*(int *)(*(int *)(iVar7 + 0x88) + 4) != 1) {
                arena = *(undefined4 *)(*compiler + 0x378);
                puVar11 = (undefined4 *)Arena__alloc(arena,0x24);
                *puVar11 = arena;
                puVar11[1] = iVar17;
                puVar11[7] = 0x1010101;
                puVar11[8] = 0;
                puVar11[3] = 1;
                puVar11[4] = 1;
                puVar11[5] = 0;
                puVar11[6] = 0;
                puVar11[2] = puVar24;
                arena = ((int (*)())FUN_00164e7c)(compiler,iVar7,piVar14,0,0,1);
                puVar11[4] = arena;
                puVar25 = *(uint **)(iVar17 + 0x40);
                uVar13 = puVar25[1];
                if (uVar13 < *puVar25) {
                  _memset(uVar13 * 4 + puVar25[2],0,4);
                  piVar4 = (int *)(uVar13 * 4 + puVar25[2]);
                  puVar25[1] = uVar13 + 1;
                }
                else {
                  piVar4 = (int *)Vector__elementRefGrow(puVar25,uVar13);
                }
                *piVar4 = (int)(puVar11 + 1);
                puVar25 = (uint *)allocation[0x12];
                uVar13 = puVar25[1];
                if (uVar13 < *puVar25) {
                  _memset(uVar13 * 4 + puVar25[2],0,4);
                  piVar4 = (int *)(uVar13 * 4 + puVar25[2]);
                  puVar25[1] = uVar13 + 1;
                }
                else {
                  piVar4 = (int *)Vector__elementRefGrow(puVar25,uVar13);
                }
                *piVar4 = (int)(puVar11 + 1);
              }
            }
            puVar25 = (uint *)compiler[6];
            uVar13 = puVar25[1];
            if (uVar13 < *puVar25) {
              _memset(uVar13 * 4 + puVar25[2],0,4);
              piVar4 = (int *)(uVar13 * 4 + puVar25[2]);
              puVar25[1] = uVar13 + 1;
            }
            else {
              piVar4 = (int *)Vector__elementRefGrow(puVar25,uVar13);
            }
            *piVar4 = (int)puVar24;
            uVar20 = uVar20 + 1;
            piVar5 = (int *)piVar14[2];
          }
          else {
            if (((((piVar14[0x20] == 0) || (iVar7 = FUN_00126760(piVar14[0x26]), iVar7 == 0)) ||
                 ((piVar14[5] & 2U) != 0)) ||
                ((iVar7 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar7 != 0 ||
                 ((piVar14[5] & 0x40U) != 0)))) ||
               (((piVar14[5] & 0x20U) == 0 && (iVar7 = Compiler__isOptionEnabled(*compiler,0x25), iVar7 != 0))))
            goto LAB_0016b038;
            iVar7 = *(int *)(*compiler + 0x3c4) + 1;
            *(int *)(*compiler + 0x3c4) = iVar7;
            piVar5 = (int *)piVar14[2];
            piVar14[0x25] = iVar7;
          }
        }
        else {
LAB_0016b038:
          if ((piVar14[0x20] != 0) &&
             (iVar7 = FUN_00126760(piVar14[0x26]), iVar7 != 0) &&
             ((piVar14[5] & 2U) == 0) &&
             (iVar7 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar7 == 0) &&
             ((piVar14[5] & 0x40U) == 0) &&
             (((piVar14[5] & 0x20U) != 0) ||
              (iVar7 = Compiler__isOptionEnabled(*compiler,0x25), iVar7 == 0))) {
            iVar7 = *(int *)(*compiler + 0x3c4) + 1;
            *(int *)(*compiler + 0x3c4) = iVar7;
            piVar14[0x25] = iVar7;
          }
          piVar5 = (int *)piVar14[2];
        }
      }
      piVar4 = (int *)piVar5[2];
      piVar14 = piVar5;
    } while ((int *)piVar5[2] != (int *)0x0);
    if (bVar2) {
      arena = *(undefined4 *)(*compiler + 0x378);
      puVar11 = (undefined4 *)Arena__alloc(arena,0x1c);
      puVar25 = puVar11 + 1;
      *puVar11 = arena;
      uVar19 = 1;
      puVar11[4] = FUN_00164bac;
      puVar11[1] = 1;
      puVar11[5] = FUN_00164bd8;
      iVar7 = 0x20;
      puVar11[6] = arena;
      do {
        uVar19 = uVar19 << 1;
        if (0xf < uVar19) break;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      *puVar25 = uVar19;
      puVar11[2] = 0;
      arena = Arena__alloc(arena,*puVar25 << 2);
      puVar11[3] = arena;
      _memset(arena,0,*puVar25 << 2);
      uVar20 = uVar20 - 1;
      if (-1 < (int)uVar20) {
        iVar7 = uVar20 * 4;
        local_54 = 0;
        iVar17 = 0;
        iVar16 = 0;
        local_58 = uVar20;
        do {
          puVar27 = (uint *)compiler[6];
          if (uVar20 < *puVar27) {
            uVar19 = puVar27[1];
            if (uVar19 <= uVar20) {
              _memset(uVar19 * 4 + puVar27[2],0,(uVar20 - uVar19) * 4 + 4);
              puVar27[1] = uVar20 + 1;
            }
            piVar4 = (int *)(iVar7 + puVar27[2]);
          }
          else {
            piVar4 = (int *)Vector__elementRefGrow(puVar27,uVar20);
          }
          iVar22 = *piVar4;
          /* issue #76: iVar22 is read back from compiler[6]'s array at whatever index this
           * iteration's format was recorded under - but that recording can legitimately still
           * be an empty (never-populated) slot: a *different*, unrelated code path
           * (FUN_00168468, cross-referencing a format's own sub-component via that
           * component's OWN persistent [0x54] "registry index") can grow this SAME array ahead
           * of the official sequential writer, using an index that has nothing to do with how
           * many formats this loop has appended so far. Verified live on real hardware: the
           * component's [0x54] value was stable and pre-existing (set before this whole
           * CGLCreateContext call chain even began, not corrupted by anything traced this
           * session), and every instruction from this read through the FUN_00164fc0 call below
           * is a byte-for-byte accurate decompilation of the stock binary (checked against the
           * real disassembly) - so this is a real, stock-shared gap between two independent
           * writers of the same growable array, not a decompilation defect. The rest of this
           * loop iteration exists purely to detect and register cross-format rendering quirks
           * (building "allocation[7]=0x1010101"-tagged quirk records) for a real, populated
           * format pair - with nothing here to compare against, there is no quirk to register,
           * so skip straight to this iteration's own bookkeeping instead of dereferencing a
           * format that was never actually stored. */
          if (iVar22 == 0) {
            iVar12 = 0;
            iVar23 = 0;
            goto LAB_issue76_skip_pair;
          }
          piVar4 = *(int **)(iVar22 + 0x38);
          iVar12 = ((int (*)())FUN_00164fc0)(piVar4);
          if (iVar12 != 0) {
            iVar12 = FUN_00194834(puVar25,piVar4);
            if (iVar12 != 0) {
              puVar27 = (uint *)compiler[6];
              uVar19 = *(uint *)(iVar12 + 0x150);
              if (uVar19 < *puVar27) {
                uVar13 = puVar27[1];
                if (uVar13 <= uVar19) {
                  _memset(uVar13 * 4 + puVar27[2],0,(uVar19 - uVar13) * 4 + 4);
                  puVar27[1] = uVar19 + 1;
                }
                piVar14 = (int *)(uVar19 * 4 + puVar27[2]);
              }
              else {
                piVar14 = (int *)Vector__elementRefGrow(puVar27,uVar19);
              }
              iVar23 = *piVar14;
              arena = *(undefined4 *)(*compiler + 0x378);
              allocation = (undefined4 *)Arena__alloc(arena,0x24);
              *allocation = arena;
              allocation[1] = iVar22;
              allocation[7] = 0x1010101;
              allocation[4] = 1;
              allocation[5] = 0;
              allocation[6] = 0;
              allocation[8] = 0;
              allocation[2] = iVar23;
              allocation[3] = 1;
              arena = ((int (*)())FUN_00164e7c)(compiler,piVar4,iVar12,0,0,1);
              allocation[4] = arena;
              puVar27 = *(uint **)(iVar22 + 0x40);
              uVar19 = puVar27[1];
              if (uVar19 < *puVar27) {
                _memset(uVar19 * 4 + puVar27[2],0,4);
                piVar14 = (int *)(uVar19 * 4 + puVar27[2]);
                puVar27[1] = uVar19 + 1;
              }
              else {
                piVar14 = (int *)Vector__elementRefGrow(puVar27,uVar19);
              }
              *piVar14 = (int)(allocation + 1);
              puVar27 = *(uint **)(iVar23 + 0x44);
              uVar19 = puVar27[1];
              if (uVar19 < *puVar27) {
                _memset(uVar19 * 4 + puVar27[2],0,4);
                piVar14 = (int *)(uVar19 * 4 + puVar27[2]);
                puVar27[1] = uVar19 + 1;
              }
              else {
                piVar14 = (int *)Vector__elementRefGrow(puVar27,uVar19);
              }
              *piVar14 = (int)(allocation + 1);
              FUN_00194720(puVar25,iVar12);
            }
            FUN_00194d44(puVar25,piVar4);
          }
          iVar23 = (**(code **)(*(int *)compiler[3] + 0x28))((int *)compiler[3],piVar4);
          iVar12 = iVar17;
          if ((iVar23 != 0) && (iVar12 = iVar22, iVar17 != 0)) {
            arena = *(undefined4 *)(*compiler + 0x378);
            allocation = (undefined4 *)Arena__alloc(arena,0x24);
            *allocation = arena;
            allocation[7] = 0x1010101;
            allocation[1] = iVar22;
            allocation[4] = 1;
            allocation[5] = 0;
            allocation[6] = 0;
            allocation[8] = 0;
            allocation[2] = iVar17;
            allocation[3] = 4;
            arena = ((int (*)())FUN_00164e7c)(compiler,piVar4,*(undefined4 *)(iVar17 + 0x38),0,0,4);
            allocation[4] = arena;
            puVar27 = *(uint **)(iVar22 + 0x40);
            uVar19 = puVar27[1];
            if (uVar19 < *puVar27) {
              _memset(uVar19 * 4 + puVar27[2],0,4);
              piVar14 = (int *)(uVar19 * 4 + puVar27[2]);
              puVar27[1] = uVar19 + 1;
            }
            else {
              piVar14 = (int *)Vector__elementRefGrow(puVar27,uVar19);
            }
            *piVar14 = (int)(allocation + 1);
            puVar27 = *(uint **)(iVar17 + 0x44);
            uVar19 = puVar27[1];
            if (uVar19 < *puVar27) {
              _memset(uVar19 * 4 + puVar27[2],0,4);
              piVar14 = (int *)(uVar19 * 4 + puVar27[2]);
              puVar27[1] = uVar19 + 1;
            }
            else {
              piVar14 = (int *)Vector__elementRefGrow(puVar27,uVar19);
            }
            *piVar14 = (int)(allocation + 1);
          }
          iVar17 = (**(code **)(*(int *)compiler[3] + 0x2c))((int *)compiler[3],piVar4);
          iVar23 = iVar16;
          if ((iVar17 != 0) && (iVar23 = iVar22, iVar16 != 0)) {
            arena = *(undefined4 *)(*compiler + 0x378);
            allocation = (undefined4 *)Arena__alloc(arena,0x24);
            *allocation = arena;
            allocation[7] = 0x1010101;
            allocation[1] = iVar22;
            allocation[4] = 1;
            allocation[5] = 0;
            allocation[6] = 0;
            allocation[8] = 0;
            allocation[2] = iVar16;
            allocation[3] = 4;
            arena = ((int (*)())FUN_00164e7c)(compiler,piVar4,*(undefined4 *)(iVar16 + 0x38),0,0,4);
            allocation[4] = arena;
            puVar27 = *(uint **)(iVar22 + 0x40);
            uVar19 = puVar27[1];
            if (uVar19 < *puVar27) {
              _memset(uVar19 * 4 + puVar27[2],0,4);
              piVar14 = (int *)(uVar19 * 4 + puVar27[2]);
              puVar27[1] = uVar19 + 1;
            }
            else {
              piVar14 = (int *)Vector__elementRefGrow(puVar27,uVar19);
            }
            *piVar14 = (int)(allocation + 1);
            puVar27 = *(uint **)(iVar16 + 0x44);
            uVar19 = puVar27[1];
            if (uVar19 < *puVar27) {
              _memset(uVar19 * 4 + puVar27[2],0,4);
              piVar14 = (int *)(uVar19 * 4 + puVar27[2]);
              puVar27[1] = uVar19 + 1;
            }
            else {
              piVar14 = (int *)Vector__elementRefGrow(puVar27,uVar19);
            }
            *piVar14 = (int)(allocation + 1);
          }
          if (0 < piVar4[0x21]) {
            iVar17 = 1;
            do {
              arena = IRInst__getOperandSource(piVar4,iVar17);
              iVar16 = ((int (*)())FUN_00164fc0)(arena);
              if (iVar16 != 0) {
                arena = IRInst__getOperandSource(piVar4,iVar17);
                piVar14 = (int *)FUN_00194834(puVar25,arena);
                if ((piVar14 != (int *)0x0) && (piVar4 != piVar14)) {
                  puVar27 = (uint *)compiler[6];
                  uVar19 = piVar14[0x54];
                  if (uVar19 < *puVar27) {
                    uVar13 = puVar27[1];
                    if (uVar13 <= uVar19) {
                      _memset(uVar13 * 4 + puVar27[2],0,(uVar19 - uVar13) * 4 + 4);
                      puVar27[1] = uVar19 + 1;
                    }
                    piVar5 = (int *)(uVar19 * 4 + puVar27[2]);
                  }
                  else {
                    piVar5 = (int *)Vector__elementRefGrow(puVar27,uVar19);
                  }
                  iVar16 = *piVar5;
                  arena = *(undefined4 *)(*compiler + 0x378);
                  allocation = (undefined4 *)Arena__alloc(arena,0x24);
                  *allocation = arena;
                  allocation[7] = 0x1010101;
                  allocation[1] = iVar22;
                  allocation[3] = 2;
                  allocation[4] = 1;
                  allocation[5] = 0;
                  allocation[6] = 0;
                  allocation[8] = 0;
                  allocation[2] = iVar16;
                  arena = ((int (*)())FUN_00164e7c)(compiler,piVar4,piVar14,iVar17,0,2);
                  allocation[4] = arena;
                  puVar27 = *(uint **)(iVar22 + 0x40);
                  uVar19 = puVar27[1];
                  if (uVar19 < *puVar27) {
                    _memset(uVar19 * 4 + puVar27[2],0,4);
                    piVar14 = (int *)(uVar19 * 4 + puVar27[2]);
                    puVar27[1] = uVar19 + 1;
                  }
                  else {
                    piVar14 = (int *)Vector__elementRefGrow(puVar27,uVar19);
                  }
                  *piVar14 = (int)(allocation + 1);
                  puVar27 = *(uint **)(iVar16 + 0x44);
                  uVar19 = puVar27[1];
                  if (uVar19 < *puVar27) {
                    _memset(uVar19 * 4 + puVar27[2],0,4);
                    piVar14 = (int *)(uVar19 * 4 + puVar27[2]);
                    puVar27[1] = uVar19 + 1;
                  }
                  else {
                    piVar14 = (int *)Vector__elementRefGrow(puVar27,uVar19);
                  }
                  *piVar14 = (int)(allocation + 1);
                }
              }
              iVar17 = iVar17 + 1;
            } while (iVar17 <= piVar4[0x21]);
          }
          iVar17 = (**(code **)(*piVar4 + 0x28))(piVar4);
          if ((iVar17 != 0) && (iVar23 != 0)) {
            arena = *(undefined4 *)(*compiler + 0x378);
            allocation = (undefined4 *)Arena__alloc(arena,0x24);
            *allocation = arena;
            allocation[7] = 0x1010101;
            allocation[1] = iVar22;
            allocation[4] = 1;
            allocation[5] = 0;
            allocation[6] = 0;
            allocation[8] = 0;
            allocation[2] = iVar23;
            allocation[3] = 4;
            arena = ((int (*)())FUN_00164e7c)(compiler,piVar4,*(undefined4 *)(iVar23 + 0x38),0,0,4);
            allocation[4] = arena;
            puVar27 = *(uint **)(iVar22 + 0x40);
            uVar19 = puVar27[1];
            if (uVar19 < *puVar27) {
              _memset(uVar19 * 4 + puVar27[2],0,4);
              piVar14 = (int *)(uVar19 * 4 + puVar27[2]);
              puVar27[1] = uVar19 + 1;
            }
            else {
              piVar14 = (int *)Vector__elementRefGrow(puVar27,uVar19);
            }
            *piVar14 = (int)(allocation + 1);
            puVar27 = *(uint **)(iVar23 + 0x44);
            uVar19 = puVar27[1];
            if (uVar19 < *puVar27) {
              _memset(uVar19 * 4 + puVar27[2],0,4);
              piVar14 = (int *)(uVar19 * 4 + puVar27[2]);
              puVar27[1] = uVar19 + 1;
            }
            else {
              piVar14 = (int *)Vector__elementRefGrow(puVar27,uVar19);
            }
            *piVar14 = (int)(allocation + 1);
          }
          iVar17 = (**(code **)(*piVar4 + 0x24))(piVar4);
          if (((iVar17 != 0) && ((piVar4[5] & 2U) == 0)) && (iVar12 != 0)) {
            arena = *(undefined4 *)(*compiler + 0x378);
            allocation = (undefined4 *)Arena__alloc(arena,0x24);
            *allocation = arena;
            allocation[7] = 0x1010101;
            allocation[1] = iVar22;
            allocation[8] = 0;
            allocation[4] = 1;
            allocation[5] = 0;
            allocation[6] = 0;
            allocation[2] = iVar12;
            allocation[3] = 4;
            arena = ((int (*)())FUN_00164e7c)(compiler,piVar4,*(undefined4 *)(iVar12 + 0x38),0,0,4);
            allocation[4] = arena;
            puVar27 = *(uint **)(iVar22 + 0x40);
            uVar19 = puVar27[1];
            if (uVar19 < *puVar27) {
              _memset(uVar19 * 4 + puVar27[2],0,4);
              piVar14 = (int *)(uVar19 * 4 + puVar27[2]);
              puVar27[1] = uVar19 + 1;
            }
            else {
              piVar14 = (int *)Vector__elementRefGrow(puVar27,uVar19);
            }
            *piVar14 = (int)(allocation + 1);
            puVar27 = *(uint **)(iVar12 + 0x44);
            uVar19 = puVar27[1];
            if (uVar19 < *puVar27) {
              _memset(uVar19 * 4 + puVar27[2],0,4);
              piVar14 = (int *)(uVar19 * 4 + puVar27[2]);
              puVar27[1] = uVar19 + 1;
            }
            else {
              piVar14 = (int *)Vector__elementRefGrow(puVar27,uVar19);
            }
            *piVar14 = (int)(allocation + 1);
          }
          iVar17 = (**(code **)(*(int *)compiler[3] + 0x20))((int *)compiler[3],piVar4);
          if ((iVar17 != 0) && (iVar17 = FUN_00193f08(auStack_78), iVar17 == 0)) {
            iVar16 = *(int *)(local_70 + 8);
            iVar17 = local_70;
            while (iVar16 != 0) {
              arena = *(undefined4 *)(*compiler + 0x378);
              allocation = (undefined4 *)Arena__alloc(arena,0x24);
              *allocation = arena;
              allocation[7] = 0x1010101;
              allocation[1] = iVar22;
              allocation[4] = 1;
              allocation[5] = 0;
              allocation[6] = 0;
              allocation[8] = 0;
              allocation[2] = iVar17;
              allocation[3] = 4;
              arena = ((int (*)())FUN_00164e7c)(compiler,piVar4,*(undefined4 *)(iVar17 + 0x38),0,0,4);
              allocation[4] = arena;
              puVar27 = *(uint **)(iVar22 + 0x40);
              uVar19 = puVar27[1];
              if (uVar19 < *puVar27) {
                _memset(uVar19 * 4 + puVar27[2],0,4);
                piVar14 = (int *)(uVar19 * 4 + puVar27[2]);
                puVar27[1] = uVar19 + 1;
              }
              else {
                piVar14 = (int *)Vector__elementRefGrow(puVar27,uVar19);
              }
              *piVar14 = (int)(allocation + 1);
              puVar27 = *(uint **)(iVar17 + 0x44);
              uVar19 = puVar27[1];
              if (uVar19 < *puVar27) {
                _memset(uVar19 * 4 + puVar27[2],0,4);
                piVar14 = (int *)(uVar19 * 4 + puVar27[2]);
                puVar27[1] = uVar19 + 1;
              }
              else {
                piVar14 = (int *)Vector__elementRefGrow(puVar27,uVar19);
              }
              *piVar14 = (int)(allocation + 1);
              iVar17 = *(int *)(iVar17 + 8);
              iVar16 = *(int *)(iVar17 + 8);
            }
          }
          if (((*(int *)(compiler[1] + 0x33c) != 0) &&
              (*(int *)(*(int *)(*compiler + 0x30c) + 0x20) <
               *(int *)(*(int *)(compiler[1] + 0x33c) + 300))) &&
             (iVar17 = (**(code **)(*(int *)compiler[2] + 0x28))((int *)compiler[2],piVar4),
             iVar17 != 0)) {
            iVar16 = *(int *)(local_70 + 8);
            iVar17 = local_70;
            while (iVar18 = iVar16, iVar18 != 0) {
              if (*(int *)(iVar17 + 0x38) == *(int *)(compiler[1] + 0x33c)) {
                arena = *(undefined4 *)(*compiler + 0x378);
                allocation = (undefined4 *)Arena__alloc(arena,0x24);
                *allocation = arena;
                allocation[7] = 0x1010101;
                allocation[1] = iVar22;
                allocation[3] = 2;
                allocation[4] = 1;
                allocation[5] = 0;
                allocation[6] = 0;
                allocation[8] = 0;
                allocation[2] = iVar17;
                arena = ((int (*)())FUN_00164e7c)(compiler,piVar4,*(undefined4 *)(iVar17 + 0x38),0,0,2);
                allocation[4] = arena;
                puVar27 = *(uint **)(iVar22 + 0x40);
                uVar19 = puVar27[1];
                if (uVar19 < *puVar27) {
                  _memset(uVar19 * 4 + puVar27[2],0,4);
                  piVar14 = (int *)(uVar19 * 4 + puVar27[2]);
                  puVar27[1] = uVar19 + 1;
                }
                else {
                  piVar14 = (int *)Vector__elementRefGrow(puVar27,uVar19);
                }
                *piVar14 = (int)(allocation + 1);
                puVar27 = *(uint **)(iVar17 + 0x44);
                uVar19 = puVar27[1];
                if (uVar19 < *puVar27) {
                  _memset(uVar19 * 4 + puVar27[2],0,4);
                  piVar14 = (int *)(uVar19 * 4 + puVar27[2]);
                  puVar27[1] = uVar19 + 1;
                }
                else {
                  piVar14 = (int *)Vector__elementRefGrow(puVar27,uVar19);
                }
                *piVar14 = (int)(allocation + 1);
                iVar18 = *(int *)(iVar17 + 8);
              }
              iVar17 = iVar18;
              iVar16 = *(int *)(iVar18 + 8);
            }
          }
LAB_issue76_skip_pair:
          uVar20 = uVar20 - 1;
          iVar7 = iVar7 + -4;
          local_54 = local_54 + 1;
          iVar17 = iVar12;
          iVar16 = iVar23;
        } while (local_54 != local_58 + 1);
      }
      if (puVar25 != (uint *)0x0) {
        uVar19 = *puVar25;
        if (uVar19 == 0) {
          iVar7 = puVar11[3];
        }
        else {
          iVar7 = puVar11[3];
          uVar20 = 0;
          do {
            iVar17 = *(int *)(uVar20 * 4 + iVar7);
            if (iVar17 != 0) {
              Arena__free(puVar11[6],iVar17);
              uVar19 = *puVar25;
              iVar7 = puVar11[3];
            }
            uVar20 = uVar20 + 1;
          } while (uVar20 < uVar19);
        }
        Arena__free(puVar11[6],iVar7);
        Arena__free(*puVar11,puVar11);
      }
    }
  }
  return;
}

/* FUN_0016bd70 @ 0x16bd70 (1140 bytes) */
int FUN_0016bd70(param_1)
  int *param_1;
{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  undefined4 *allocation;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint *puVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  uint loopIndex;
  uint loopIndex2;
  int iVar16;
  uint *puVar17;
  undefined4 arena;
  uint loopIndex3;
  /* NOTE (issue #64): local_68/local_64/local_60 are passed by address (&local_68) to Arena__alloc/
   * Vector__removeAt/Vector__elementRefGrow as one contiguous 3-word vector struct (capacity, count, data-ptr).
   * Ghidra split it into 3 separate scalar locals, which -O0 does NOT lay out contiguously (confirmed
   * live: real stack deltas were 0x44/0x4 bytes, not 4/4) - forced into one array so the compiler
   * can't reorder/pad between them. */
  undefined4 local_68vec_16bd70[3];
#define local_68_vec local_68vec_16bd70[0]
#define local_64_vec local_68vec_16bd70[1]
#define local_60_vec local_68vec_16bd70[2]
  undefined4 local_5c;
  
  local_5c = *(undefined4 *)(*param_1 + 0x378);
  uVar11 = *(uint *)(param_1[6] + 4);
  local_64_vec = 0;
  local_68_vec = 2;
  local_60_vec = Arena__alloc(local_5c,8);
  if (0 < (int)uVar11) {
    loopIndex = 0;
    puVar10 = (uint *)0x0;
    do {
      puVar17 = (uint *)param_1[6];
      if (loopIndex < *puVar17) {
        uVar3 = puVar17[1];
        if (uVar3 <= loopIndex) {
          _memset(uVar3 * 4 + puVar17[2],0,(loopIndex - uVar3) * 4 + 4);
          puVar17[1] = loopIndex + 1;
        }
        piVar4 = (int *)(loopIndex * 4 + puVar17[2]);
      }
      else {
        piVar4 = (int *)Vector__elementRefGrow(puVar17,loopIndex);
      }
      iVar13 = *piVar4;
      /* issue #76: same shared-array gap as FUN_0016a568 - param_1[6] can have never-populated
       * slots left behind by an unrelated code path (FUN_00168468) that grows this same array
       * via a format's own persistent, pre-existing registry index, independent of how many
       * slots this function's own sequential scan has walked. Skip an empty slot instead of
       * dereferencing it. */
      if (iVar13 == 0) goto LAB_issue76_skip_16bd70;
      if (((((*(int *)(iVar13 + 0x60) == 0) &&
            (piVar4 = *(int **)(iVar13 + 0x38), piVar4[0x20] != 0)) &&
           (iVar5 = FUN_00126760(piVar4[0x26]), iVar5 != 0)) &&
          (((piVar4[5] & 2U) == 0 && (iVar5 = (**(code **)(*piVar4 + 0x50))(piVar4), iVar5 == 0))))
         && ((*(uint *)(*(int *)(iVar13 + 0x38) + 0x14) & 0x20) == 0)) {
        if (puVar10 == (uint *)0x0) {
          arena = *(undefined4 *)(*param_1 + 0x378);
          allocation = (undefined4 *)Arena__alloc(arena,0x2c);
          uVar3 = DAT_001b01a8;
          uVar2 = DAT_001b0198;
          puVar10 = allocation + 1;
          *allocation = arena;
          allocation[1] = uVar3;
          allocation[6] = 0x7fffffff;
          allocation[2] = 0xffffffff;
          iVar5 = 4;
          allocation[4] = uVar2;
          allocation[5] = 0;
          allocation[3] = 0;
          puVar17 = puVar10;
          do {
            puVar17[6] = 0;
            puVar17 = puVar17 + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
        }
        uVar3 = local_64_vec;
        *(uint **)(iVar13 + 0x60) = puVar10;
        puVar10[4] = 1;
        *puVar10 = *(uint *)(*(int *)(iVar13 + 0x38) + 0xc);
        if (local_64_vec < local_68_vec) {
          iVar5 = local_64_vec * 4;
          _memset(iVar5 + local_60_vec,0,4);
          local_64_vec = uVar3 + 1;
          piVar4 = (int *)(iVar5 + local_60_vec);
        }
        else {
          piVar4 = (int *)Vector__elementRefGrow(&local_68_vec,local_64_vec);
        }
        *piVar4 = iVar13;
        while (uVar3 = DAT_001b01a8, local_64_vec != 0) {
          uVar3 = local_64_vec - 1;
          piVar4 = (int *)0x0;
          if (uVar3 < local_64_vec) {
            piVar4 = (int *)(uVar3 * 4 + local_60_vec);
          }
          iVar5 = *piVar4;
          Vector__removeAt(&local_68_vec,uVar3);
          puVar17 = *(uint **)(iVar5 + 0x40);
          loopIndex2 = 0;
          uVar3 = puVar17[1];
          if (0 < (int)uVar3) {
            while( true ) {
              if (loopIndex2 < *puVar17) {
                uVar7 = puVar17[1];
                if (uVar7 <= loopIndex2) {
                  _memset(uVar7 * 4 + puVar17[2],0,(loopIndex2 - uVar7) * 4 + 4);
                  puVar17[1] = loopIndex2 + 1;
                }
                piVar4 = (int *)(loopIndex2 * 4 + puVar17[2]);
              }
              else {
                piVar4 = (int *)Vector__elementRefGrow(puVar17,loopIndex2);
              }
              iVar16 = *piVar4;
              if (*(int *)(iVar16 + 8) == 0) {
                iVar12 = *(int *)(iVar16 + 4);
                loopIndex3 = 0;
                puVar17 = *(uint **)(iVar12 + 0x44);
                uVar7 = puVar17[1];
                if (0 < (int)uVar7) {
                  while( true ) {
                    if (loopIndex3 < *puVar17) {
                      uVar8 = puVar17[1];
                      if (uVar8 <= loopIndex3) {
                        _memset(uVar8 * 4 + puVar17[2],0,(loopIndex3 - uVar8) * 4 + 4);
                        puVar17[1] = loopIndex3 + 1;
                      }
                      allocation = (undefined4 *)(loopIndex3 * 4 + puVar17[2]);
                    }
                    else {
                      allocation = (undefined4 *)Vector__elementRefGrow(puVar17,loopIndex3);
                    }
                    uVar8 = local_64_vec;
                    piVar4 = (int *)*allocation;
                    if (((piVar4[2] == 0) && (piVar4[4] == *(int *)(iVar16 + 0x10))) &&
                       ((piVar4[5] == *(int *)(iVar16 + 0x14) && (*(int *)(*piVar4 + 0x60) == 0))))
                    {
                      *(uint **)(*piVar4 + 0x60) = puVar10;
                      puVar10[4] = puVar10[4] + 1;
                      *puVar10 = *puVar10 | *(uint *)(*(int *)(*piVar4 + 0x38) + 0xc);
                      iVar9 = *piVar4;
                      if (local_64_vec < local_68_vec) {
                        iVar1 = local_64_vec * 4;
                        _memset(iVar1 + local_60_vec,0,4);
                        local_64_vec = uVar8 + 1;
                        piVar4 = (int *)(iVar1 + local_60_vec);
                      }
                      else {
                        piVar4 = (int *)Vector__elementRefGrow(&local_68_vec,local_64_vec);
                      }
                      *piVar4 = iVar9;
                    }
                    loopIndex3 = loopIndex3 + 1;
                    if (uVar7 == loopIndex3) break;
                    puVar17 = *(uint **)(iVar12 + 0x44);
                  }
                }
              }
              loopIndex2 = loopIndex2 + 1;
              if (uVar3 == loopIndex2) break;
              puVar17 = *(uint **)(iVar5 + 0x40);
            }
          }
        }
        if (puVar10[4] == 1) {
          *(undefined4 *)(iVar13 + 0x60) = 0;
          *puVar10 = uVar3;
          puVar10[4] = 0;
        }
        else {
          puVar10 = (uint *)0x0;
        }
      }
LAB_issue76_skip_16bd70:
      loopIndex = loopIndex + 1;
    } while (uVar11 != loopIndex);
    if (puVar10 != (uint *)0x0) {
      Arena__free(puVar10[-1],puVar10 + -1);
    }
  }
  return Arena__free(local_5c,local_60_vec);
}

/* FUN_0016c1fc @ 0x16c1fc (1092 bytes) */
int FUN_0016c1fc(compiler)
  int *compiler;
{
  int loopIndex;
  int *piVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  
  piVar8 = (int *)compiler[0xc];
  iVar4 = *piVar8;
  if (iVar4 == 0) {
    iVar4 = piVar8[1];
    if (iVar4 == 0) goto LAB_0016c27c;
  }
  else if (piVar8[1] != 0) goto LAB_0016c27c;
  if (((*(int *)(iVar4 + 100) == 0) && (*(int *)(iVar4 + 0x60) == 0)) &&
     (*(int *)(*(int *)(iVar4 + 0x38) + 0x98) == 1)) {
    *(undefined4 *)(*(int *)(iVar4 + 0x38) + 0x98) = 0;
    piVar8 = (int *)compiler[0xc];
  }
LAB_0016c27c:
  iVar4 = 0;
  while( true ) {
    iVar12 = piVar8[iVar4];
    if ((((iVar12 != 0) && (piVar8 = *(int **)(iVar12 + 0x38), piVar8[0x20] != 0)) &&
        ((iVar5 = FUN_00126760(piVar8[0x26]), iVar5 != 0 &&
         (((piVar8[5] & 2U) == 0 && (iVar5 = (**(code **)(*piVar8 + 0x50))(piVar8), iVar5 == 0))))))
       && ((piVar8[5] & 0x40U) != 0)) {
      iVar5 = piVar8[0x25];
      iVar10 = 0;
      piVar9 = compiler;
      do {
        iVar6 = IRInst__getOperandRecord(piVar8,0);
        if (*(char *)(iVar10 + iVar6 + 0x10) != '\x01') {
          *(int *)(piVar9[0x4d] + iVar5 * 4) = iVar12;
        }
        bVar2 = iVar10 != 3;
        piVar9 = piVar9 + 1;
        iVar10 = iVar10 + 1;
      } while (bVar2);
    }
    if (4 < iVar4 + 1) break;
    piVar8 = (int *)compiler[0xc];
    iVar4 = iVar4 + 1;
  }
  iVar4 = compiler[0xc];
  loopIndex = 0;
  do {
    iVar5 = loopIndex * 4;
    loopIndex = loopIndex + 1;
    iVar4 = *(int *)(iVar5 + iVar4);
    if (iVar4 != 0) {
      piVar8 = *(int **)(iVar4 + 0x38);
      iVar5 = Compiler__isOptionEnabled(*compiler,0x25);
      if (iVar5 == 0) {
LAB_0016c3e0:
        iVar5 = piVar8[0x20];
      }
      else {
        iVar5 = 0;
        if (piVar8[0x20] != 0) {
          iVar5 = FUN_00126760(piVar8[0x26]);
          if ((((iVar5 != 0) && ((piVar8[5] & 2U) == 0)) &&
              (iVar5 = (**(code **)(*piVar8 + 0x50))(piVar8), iVar5 == 0)) &&
             (((piVar8[5] & 0x40U) == 0 && ((piVar8[5] & 0x20U) == 0)))) {
            if ((*(int *)(iVar4 + 0x60) == 0) ||
               (iVar5 = *(int *)(*(int *)(iVar4 + 0x60) + 4), iVar5 < 0)) {
              iVar10 = (**(code **)(**(int **)(*compiler + 0x30c) + 0x7c))
                                 (*(int **)(*compiler + 0x30c),piVar8);
              iVar5 = DAT_001b0194;
              if (iVar10 != 0) {
                if (*(int **)(iVar4 + 0x60) == (int *)0x0) {
                  iVar5 = piVar8[3];
                }
                else {
                  iVar5 = **(int **)(iVar4 + 0x60);
                }
              }
              iVar5 = ((int (*)())FUN_00167b68)(compiler,piVar8[0x26],iVar5);
              if (iVar5 < 0) {
                iVar5 = compiler[0x52];
                iVar10 = compiler[0x53];
                compiler[0x52] = iVar5 + 1;
                if (iVar10 < iVar5 + 1) {
                  piVar9 = compiler;
                  do {
                    iVar11 = piVar9[0x4d];
                    iVar6 = Arena__alloc(*(undefined4 *)(*compiler + 0x378),iVar10 << 3);
                    iVar7 = compiler[0x53];
                    piVar9[0x4d] = iVar6;
                    piVar9 = piVar9 + 1;
                    _memcpy(iVar6,iVar11,iVar7 << 2);
                    Arena__free(*(undefined4 *)(*compiler + 0x378),iVar11);
                  } while (piVar9 != compiler + 4);
                  compiler[0x53] = iVar10 << 1;
                }
                iVar10 = iVar5 * 4;
                iVar6 = 4;
                piVar9 = compiler;
                do {
                  piVar1 = piVar9 + 0x4d;
                  piVar9 = piVar9 + 1;
                  *(undefined4 *)(iVar10 + *piVar1) = 0;
                  iVar6 = iVar6 + -1;
                } while (iVar6 != 0);
              }
              else {
                iVar10 = iVar5 << 2;
              }
              iVar6 = 0;
              piVar9 = compiler;
              do {
                iVar7 = IRInst__getOperandRecord(piVar8,0);
                if (*(char *)(iVar6 + iVar7 + 0x10) != '\x01') {
                  *(int *)(piVar9[0x4d] + iVar10) = iVar4;
                }
                bVar2 = iVar6 != 3;
                piVar9 = piVar9 + 1;
                iVar6 = iVar6 + 1;
              } while (bVar2);
              if (*(int *)(iVar4 + 0x60) != 0) {
                *(int *)(*(int *)(iVar4 + 0x60) + 4) = iVar5;
              }
            }
            else {
              iVar10 = 0;
              piVar9 = compiler;
              do {
                iVar6 = IRInst__getOperandRecord(piVar8,0);
                if (*(char *)(iVar10 + iVar6 + 0x10) != '\x01') {
                  *(int *)(piVar9[0x4d] + iVar5 * 4) = iVar4;
                }
                bVar2 = iVar10 != 3;
                piVar9 = piVar9 + 1;
                iVar10 = iVar10 + 1;
              } while (bVar2);
            }
            piVar8[0x25] = iVar5;
            piVar8[5] = piVar8[5] | 0x40;
            goto LAB_0016c620;
          }
          goto LAB_0016c3e0;
        }
      }
      if (((iVar5 != 0) && (iVar4 = FUN_00126760(piVar8[0x26]), iVar4 != 0)) &&
         (((piVar8[5] & 2U) == 0 && (iVar4 = (**(code **)(*piVar8 + 0x50))(piVar8), iVar4 == 0)))) {
        uVar3 = piVar8[5];
        if ((uVar3 & 0x20) == 0) {
          iVar4 = Compiler__isOptionEnabled(*compiler,0x25);
          if (iVar4 != 0) goto LAB_0016c620;
          uVar3 = piVar8[5];
        }
        if ((uVar3 & 0x40) == 0) {
          iVar4 = *(int *)(*compiler + 0x3c4) + 1;
          *(int *)(*compiler + 0x3c4) = iVar4;
          piVar8[0x25] = iVar4;
        }
      }
    }
LAB_0016c620:
    if (4 < loopIndex) {
      return;
    }
    iVar4 = compiler[0xc];
  } while( true );
}

/* FUN_0016c640 @ 0x16c640 (816 bytes) */
int FUN_0016c640(param_1)
  undefined4 *param_1;
{
  bool bVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint loopIndex;
  int iVar10;
  uint *puVar11;
  int *piVar12;
  
  iVar6 = 0;
  ((int (*)())FUN_0016c1fc)(param_1);
  iVar4 = param_1[0xc];
  iVar10 = 0;
  iVar5 = *(int *)(*(int *)(param_1[4] + 0xcc) + 4);
  do {
    iVar8 = *(int *)(iVar6 * 4 + iVar4);
    if (iVar8 != 0) {
      iVar10 = *(int *)(iVar8 + 0x38);
      loopIndex = 0;
      Block__appendInst(param_1[4],iVar10);
      ((int (*)())FUN_00165788)(iVar10,*param_1);
      *(uint *)(iVar10 + 0x14) = *(uint *)(iVar10 + 0x14) | 4;
      puVar11 = *(uint **)(iVar8 + 0x44);
      uVar7 = puVar11[1];
      if (0 < (int)uVar7) {
        while( true ) {
          if (loopIndex < *puVar11) {
            uVar2 = puVar11[1];
            if (uVar2 <= loopIndex) {
              _memset(uVar2 * 4 + puVar11[2],0,(loopIndex - uVar2) * 4 + 4);
              puVar11[1] = loopIndex + 1;
            }
            puVar3 = (undefined4 *)(loopIndex * 4 + puVar11[2]);
          }
          else {
            puVar3 = (undefined4 *)Vector__elementRefGrow(puVar11,loopIndex);
          }
          loopIndex = loopIndex + 1;
          piVar12 = (int *)*puVar3;
          if (((piVar12[2] == 0) &&
              (iVar4 = (**(code **)(**(int **)(*piVar12 + 0x38) + 0x5c))(*(int **)(*piVar12 + 0x38))
              , iVar4 != 0)) && (*(int *)(*(int *)(*piVar12 + 0x38) + 0x158) == 0)) {
            Block__insertInstAfter(param_1[4],iVar5,*(int *)(*piVar12 + 0x38));
            *(uint *)(*(int *)(*piVar12 + 0x38) + 0x14) =
                 *(uint *)(*(int *)(*piVar12 + 0x38) + 0x14) | 4;
            iVar5 = *(int *)(*piVar12 + 0x38);
          }
          if (uVar7 == loopIndex) break;
          puVar11 = *(uint **)(iVar8 + 0x44);
        }
      }
      iVar4 = param_1[0xc];
    }
    bVar1 = iVar6 != 4;
    iVar6 = iVar6 + 1;
  } while (bVar1);
  iVar6 = *(int *)(iVar4 + 0x1c);
  for (iVar4 = *(int *)(*(int *)(iVar4 + 0x1c) + 8); iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    iVar8 = *(int *)(iVar6 + 0x38);
    if ((*(int *)(iVar8 + 0x98) == 0x45) || (*(int *)(iVar8 + 0x98) == 0x44)) {
      Block__insertInstAfter(param_1[4],iVar5,iVar8);
      *(uint *)(iVar8 + 0x14) = *(uint *)(iVar8 + 0x14) | 4;
      iVar5 = iVar8;
      if (iVar10 == 0) {
        iVar10 = iVar8;
      }
    }
    else {
      loopIndex = 0;
      Block__appendInst(param_1[4],iVar8);
      ((int (*)())FUN_00165788)(iVar8,*param_1);
      *(uint *)(iVar8 + 0x14) = *(uint *)(iVar8 + 0x14) | 4;
      puVar11 = *(uint **)(iVar6 + 0x44);
      uVar7 = puVar11[1];
      iVar10 = iVar8;
      if (0 < (int)uVar7) {
        while( true ) {
          if (loopIndex < *puVar11) {
            uVar2 = puVar11[1];
            if (uVar2 <= loopIndex) {
              _memset(uVar2 * 4 + puVar11[2],0,(loopIndex - uVar2) * 4 + 4);
              puVar11[1] = loopIndex + 1;
            }
            puVar3 = (undefined4 *)(loopIndex * 4 + puVar11[2]);
          }
          else {
            puVar3 = (undefined4 *)Vector__elementRefGrow(puVar11,loopIndex);
          }
          loopIndex = loopIndex + 1;
          piVar12 = (int *)*puVar3;
          if (((piVar12[2] == 0) &&
              (iVar10 = (**(code **)(**(int **)(*piVar12 + 0x38) + 0x5c))
                                  (*(int **)(*piVar12 + 0x38)), iVar10 != 0)) &&
             (*(int *)(*(int *)(*piVar12 + 0x38) + 0x158) == 0)) {
            Block__insertInstAfter(param_1[4],iVar5,*(int *)(*piVar12 + 0x38));
            *(uint *)(*(int *)(*piVar12 + 0x38) + 0x14) =
                 *(uint *)(*(int *)(*piVar12 + 0x38) + 0x14) | 4;
            iVar5 = *(int *)(*piVar12 + 0x38);
          }
          iVar10 = iVar8;
          if (uVar7 == loopIndex) break;
          puVar11 = *(uint **)(iVar6 + 0x44);
        }
      }
    }
    iVar6 = iVar4;
  }
  if (iVar10 != 0) {
    *(uint *)(iVar10 + 0x14) = *(uint *)(iVar10 + 0x14) & 0xfffffffb;
  }
  return iVar10;
}

