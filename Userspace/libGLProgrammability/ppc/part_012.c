#include "decls.h"

/* TPPStreamCompiler__newIndirectOperandFromConstant @ 0x97bc4748 (2092 bytes) */
#if 0   /* compile-failing as plain C: Ghidra text kept verbatim, see ledger status */
int TPPStreamCompiler__newIndirectOperandFromConstant(this, param_1, param_2)
  unsigned char * this;
  unsigned char * param_1;
  unsigned char * param_2;
{
  undefined4 uVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  byte bVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  int iVar9;
  unsigned char * this_00;
  undefined4 *puVar10;
  unsigned char * this_01;
  uint uVar11;
  int iVar12;
  int iVar13;
  ushort uVar17;
  uint uVar14;
  undefined1 *puVar15;
  int iVar16;
  undefined4 *puVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  byte in_xer_so;
  uint uVar24;
  unsigned char * pTStack00000020;
  undefined4 local_1f0;
  uint local_1ec;
  char acStack_1e0 [256];
  ushort local_e0 [8];
  int local_d0 [8];
  bool local_b0 [16];
  uint local_a0 [4];
  int *local_90;
  int local_8c;
  unsigned char * local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  unsigned char * local_70;
  int local_6c;
  
  iVar20 = 0;
  bVar4 = false;
  local_90 = *(int **)(*(int *)(this + 0x70) + 0x10);
  iVar23 = *local_90;
  iVar19 = *(int *)(*(int *)(this + 0x70) + 0x2c);
  pTStack00000020 = param_2;
  local_88 = operator_new(0x38);
  ParseOperand__ParseOperand(local_88);
  this_01 = operator_new(100);
  ParseSymbol__ParseSymbol(this_01);
  local_8c = 0;
  uVar11 = (**(code **)(*(int *)pTStack00000020 + 0x2c))(pTStack00000020);
  iVar12 = ParseOperand__GetBaseSize();
  iVar9 = DAT_97c3925c;
  iVar16 = DAT_97c39258;
  iVar22 = DAT_97c39254;
  iVar21 = DAT_97c39250;
  dVar8 = DOUBLE_97c30a58;
  local_84 = (iVar12 - 1U) / uVar11 + 1;
  if (iVar23 == 0) {
    bVar2 = true;
LAB_97bc4c8c:
    if (bVar2) {
      iVar21 = 0;
      iVar22 = 0;
      if (local_84 < 1) {
        return local_88;
      }
      do {
        local_d0[0] = 0;
        local_d0[1] = 0;
        local_d0[2] = 0;
        local_d0[3] = 0;
        local_b0[0] = false;
        local_b0[1] = false;
        local_b0[2] = false;
        local_b0[3] = false;
        local_b0[4] = false;
        local_b0[5] = false;
        local_b0[6] = false;
        local_b0[7] = false;
        local_b0[8] = false;
        local_b0[9] = false;
        local_b0[10] = false;
        local_b0[0xb] = false;
        local_b0[0xc] = false;
        local_b0[0xd] = false;
        local_b0[0xe] = false;
        local_b0[0xf] = false;
        local_1ec = *(uint *)(*(int *)(this + 0x68) + 0x24);
        *(uint *)(*(int *)(this + 0x68) + 0x24) = local_1ec + 1;
        local_1f0 = 0x110000;
        local_1ec = local_1ec & 0xffff;
        uVar17 = getOpenGLTypeFromTType(pTStack00000020);
        uVar14 = GetPPStreamTypeForGLType(uVar17);
        uVar24 = local_1f0 >> 0x10;
        local_1f0 = CONCAT22((ushort)((uVar11 - 1) * 0x1000000 >> 0x10) & 0x300 |
                             (ushort)(((uVar14 & 7) << 0x1a) >> 0x10) | (ushort)uVar24 & 0xff,
                             *(undefined2 *)(iVar19 + 10));
        if (0 < (int)uVar11) {
          puVar18 = (undefined4 *)(iVar21 * 4 + *(int *)(param_1 + 4));
          puVar10 = &local_1f0;
          uVar24 = uVar11;
          do {
            puVar10[0x50] = 1;
            iVar21 = iVar21 + 1;
            uVar1 = *puVar18;
            puVar18 = puVar18 + 1;
            puVar10[0x48] = uVar1;
            puVar10 = puVar10 + 1;
            uVar24 = uVar24 - 1;
          } while (uVar24 != 0);
        }
        if (*(int *)param_1 == 0) {
          uVar17 = *(ushort *)(param_1 + 0x18);
        }
        else {
          uVar17 = *(ushort *)(*(int *)param_1 + 0x2c);
        }
        ConstantAllocationList__addConstant
                  ((unsigned char *)(this + 0x44),local_1ec & 0xffff,local_b0,uVar17);
        _PPStreamAddConstant(*(undefined4 *)(this + 0x70),local_d0);
        puVar15 = _calloc(0x1c,1);
        *puVar15 = 3;
        *(uint *)(puVar15 + 0xc) = local_1f0;
        *(uint *)(puVar15 + 0x10) = local_1ec;
        *(undefined4 *)(puVar15 + 0x14) = 0;
        _PPStreamChunkListAddChunk(local_90,puVar15);
        if (iVar22 == 0) {
          ParseSymbol__SetParseTreeType((unsigned char *)this_01);
          _sprintf(acStack_1e0,DAT_a7b7bd5c,local_1f0 & 0xffff);
          *(uint *)(this_01 + 0x28) = local_1f0 & 0xffff;
          ParseSymbol__SetName((char *)this_01);
          iVar16 = (**(code **)(*(int *)pTStack00000020 + 0x24))(pTStack00000020);
          *(uint *)(this_01 + 0x38) = (uint)(iVar16 != 0);
          ParseSymbol__SetChunk((unsigned char *)this_01);
          *(undefined4 *)(this_01 + 0x44) = 0;
          *(unsigned char **)local_88 = this_01;
          *(undefined4 *)(this_01 + 0x50) = 1;
          ParseSymbolTable__AddSymbol(*(unsigned char **)(this + 0x68));
          local_a0[1] = 0;
          local_a0[0] = local_1f0 & 0xffff;
          _PPStreamAddParamBindingArray(*(undefined4 *)(this + 0x70),local_a0);
        }
        else if ((iVar22 == local_84 + -1) &&
                (iVar16 = *(int *)(*(int *)(*(int *)(this + 0x70) + 0x14) + 4),
                *(short *)(iVar16 + 0x12) == 0)) {
          *(undefined2 *)(iVar16 + 0x12) = (*(unsigned short *)((unsigned char *)&(local_1f0) + 2));
        }
        iVar22 = iVar22 + 1;
      } while (iVar22 < local_84);
      return local_88;
    }
  }
  else {
    local_70 = this + 0x44;
    local_74 = (uint)(byte)(((int)uVar11 < 2) << 3 | (2 < (int)uVar11) << 2 | (uVar11 == 2) << 1 |
                           in_xer_so & 1) << 0x1c;
    local_80 = (uint)(byte)(((int)uVar11 < 1) << 3 | (1 < (int)uVar11) << 2 | (uVar11 == 1) << 1 |
                           in_xer_so & 1) << 0x1c;
    local_7c = (uint)(byte)(((int)uVar11 < 3) << 3 | (3 < (int)uVar11) << 2 | (uVar11 == 3) << 1 |
                           in_xer_so & 1) << 0x1c;
    local_78 = (uint)(byte)(((int)uVar11 < 4) << 3 | (4 < (int)uVar11) << 2 | (uVar11 == 4) << 1 |
                           in_xer_so & 1) << 0x1c;
    local_6c = local_74;
    do {
      local_d0[0] = iVar21;
      local_d0[1] = iVar22;
      local_d0[2] = iVar16;
      local_d0[3] = iVar9;
      local_1f0 = *(uint *)(iVar23 + 0xc);
      local_1ec = *(uint *)(iVar23 + 0x10);
      if ((local_1f0 & 0x1f0000) == 0x110000) {
        iVar12 = _PPStreamChunkListChunkAtIndex(iVar19,local_1f0 & 0xffff);
        ConstantAllocationList__getConstantUsage
                  ((unsigned char *)(this + 0x44),local_1ec & 0xffff,(bool *)local_d0,
                   local_e0);
        local_d0[5] = local_d0[0] + local_d0[1] + local_d0[2] + local_d0[3] ^ 0x80000000;
        local_d0[4] = 0x43300000;
        dVar6 = (double)CONCAT44(0x43300000,local_d0[5]);
        if (*(int *)param_1 == 0) {
          uVar17 = *(ushort *)(param_1 + 0x18);
        }
        else {
          uVar17 = *(ushort *)(*(int *)param_1 + 0x2c);
        }
        if (local_e0[0] == uVar17) {
          local_d0[5] = uVar11 ^ 0x80000000;
          local_d0[4] = 0x43300000;
          if ((float)(dVar6 - dVar8) == (float)((double)CONCAT44(0x43300000,local_d0[5]) - dVar8)) {
            bVar2 = true;
            bVar5 = (byte)((uint)local_74 >> 0x18);
            if ((bool)(bVar5 >> 5 & 1)) {
LAB_97bc49e0:
              if ((local_d0[1] != 0) &&
                 (*(float *)(iVar20 * 4 + *(int *)(param_1 + 4) + 4) == *(float *)(iVar12 + 0x10)))
              {
LAB_97bc4a14:
                if ((local_d0[0] != 0) &&
                   (*(float *)(*(int *)(param_1 + 4) + iVar20 * 4) == *(float *)(iVar12 + 0xc)))
                goto LAB_97bc4a38;
              }
LAB_97bc4a34:
              bVar2 = false;
            }
            else {
              if ((bool)(bVar5 >> 6 & 1)) {
                if ((bool)((byte)((uint)local_7c >> 0x1d) & 1)) {
LAB_97bc49bc:
                  if ((local_d0[2] != 0) &&
                     (*(float *)(iVar20 * 4 + *(int *)(param_1 + 4) + 8) ==
                      *(float *)(iVar12 + 0x14))) goto LAB_97bc49e0;
                }
                else {
                  if (!(bool)((byte)((uint)local_78 >> 0x1d) & 1)) goto LAB_97bc4a38;
                  if ((local_d0[3] != 0) &&
                     (*(float *)(iVar20 * 4 + *(int *)(param_1 + 4) + 0xc) ==
                      *(float *)(iVar12 + 0x18))) goto LAB_97bc49bc;
                }
                goto LAB_97bc4a34;
              }
              if ((bool)((byte)((uint)local_80 >> 0x1d) & 1)) goto LAB_97bc4a14;
            }
LAB_97bc4a38:
            iVar20 = iVar20 + uVar11;
            if ((bVar2) && (local_8c = iVar23, local_84 == 1)) {
              bVar4 = true;
            }
          }
        }
      }
      this_00 = local_70;
      dVar6 = DOUBLE_97c30a58;
      iVar23 = *(int *)(iVar23 + 8);
      if (local_8c == 0) {
        bVar2 = !bVar4;
      }
      else {
        bVar2 = !bVar4;
        if (bVar2) {
          if (iVar23 != 0) {
            bVar5 = (byte)((uint)local_6c >> 0x18);
            iVar12 = iVar23;
            do {
              local_1f0 = *(uint *)(iVar12 + 0xc);
              local_1ec = *(uint *)(iVar12 + 0x10);
              if ((local_1f0 & 0x1f0000) == 0x110000) {
                iVar13 = _PPStreamChunkListChunkAtIndex(iVar19,local_1f0 & 0xffff);
                ConstantAllocationList__getConstantUsage
                          ((unsigned char *)this_00,local_1ec & 0xffff,(bool *)local_d0,
                           local_e0);
                local_d0[4] = 0x43300000;
                local_d0[5] = local_d0[0] + local_d0[1] + local_d0[2] + local_d0[3] ^ 0x80000000;
                dVar7 = (double)CONCAT44(0x43300000,local_d0[5]);
                if (*(int *)param_1 == 0) {
                  uVar17 = *(ushort *)(param_1 + 0x18);
                }
                else {
                  uVar17 = *(ushort *)(*(int *)param_1 + 0x2c);
                }
                if (local_e0[0] == uVar17) {
                  local_d0[5] = uVar11 ^ 0x80000000;
                  local_d0[4] = 0x43300000;
                  if ((float)(dVar7 - dVar6) ==
                      (float)((double)CONCAT44(0x43300000,local_d0[5]) - dVar6)) {
                    bVar3 = true;
                    if ((bool)(bVar5 >> 5 & 1)) {
LAB_97bc4bec:
                      if ((local_d0[1] != 0) &&
                         (*(float *)(iVar20 * 4 + *(int *)(param_1 + 4) + 4) ==
                          *(float *)(iVar13 + 0x10))) {
LAB_97bc4c10:
                        if ((local_d0[0] != 0) &&
                           (*(float *)(*(int *)(param_1 + 4) + iVar20 * 4) ==
                            *(float *)(iVar13 + 0xc))) goto LAB_97bc4c34;
                      }
LAB_97bc4c30:
                      bVar3 = false;
                    }
                    else {
                      if ((bool)(bVar5 >> 6 & 1)) {
                        if ((bool)((byte)((uint)local_7c >> 0x1d) & 1)) {
LAB_97bc4bc8:
                          if ((local_d0[2] != 0) &&
                             (*(float *)(iVar20 * 4 + *(int *)(param_1 + 4) + 8) ==
                              *(float *)(iVar13 + 0x14))) goto LAB_97bc4bec;
                        }
                        else {
                          if (!(bool)((byte)((uint)local_78 >> 0x1d) & 1)) goto LAB_97bc4c34;
                          if ((local_d0[3] != 0) &&
                             (*(float *)(iVar20 * 4 + *(int *)(param_1 + 4) + 0xc) ==
                              *(float *)(iVar13 + 0x18))) goto LAB_97bc4bc8;
                        }
                        goto LAB_97bc4c30;
                      }
                      if ((bool)((byte)((uint)local_80 >> 0x1d) & 1)) goto LAB_97bc4c10;
                    }
LAB_97bc4c34:
                    iVar20 = iVar20 + uVar11;
                    if (!bVar3) {
                      iVar20 = 0;
                      local_8c = 0;
                      goto LAB_97bc4c7c;
                    }
                  }
                }
              }
              iVar13 = ParseOperand__GetBaseSize();
              if (iVar13 <= iVar20) {
                bVar4 = true;
                bVar2 = false;
              }
              iVar12 = *(int *)(iVar12 + 8);
              if ((iVar12 == 0) || (!bVar2)) goto LAB_97bc4c7c;
            } while( true );
          }
          goto LAB_97bc4c8c;
        }
      }
LAB_97bc4c7c:
      if (iVar23 == 0) goto LAB_97bc4c8c;
    } while (bVar2);
  }
  local_1ec = *(undefined4 *)(local_8c + 0x10);
  local_1f0 = *(uint *)(local_8c + 0xc);
  ParseSymbol__SetParseTreeType((unsigned char *)this_01);
  _sprintf(acStack_1e0,DAT_a7b7bd5c,local_1f0 & 0xffff);
  *(uint *)(this_01 + 0x28) = local_1f0 & 0xffff;
  ParseSymbol__SetName((char *)this_01);
  *(unsigned char **)local_88 = this_01;
  ParseSymbolTable__processOperand(*(unsigned char **)(this + 0x68));
  return local_88;
}
#endif

/* TPPStreamCompiler__equalOperands @ 0x97bc4f74 (2416 bytes) */
#if 0   /* compile-failing as plain C: Ghidra text kept verbatim, see ledger status */
int TPPStreamCompiler__equalOperands(this, param_1, param_2, param_3, param_4)
  unsigned char * this;
  unsigned char * param_1;
  unsigned char ** param_2;
  unsigned char ** param_3;
  int param_4;
{
  short sVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  size_t sVar5;
  size_t sVar6;
  char *pcVar7;
  unsigned char * pPVar8;
  unsigned char * pPVar9;
  unsigned char * pPVar10;
  uint uVar11;
  int iVar12;
  undefined3 in_register_0000001c;
  int iVar14;
  int iVar15;
  char *pcVar16;
  char *pcVar17;
  uint local_e0;
  uint local_dc;
  uint local_d8;
  undefined4 local_d4;
  uint local_d0;
  undefined4 local_cc;
  uint local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  uint local_a0;
  undefined4 local_9c;
  uint local_90;
  undefined4 local_8c;
  uint local_80;
  undefined4 local_7c;
  unsigned char * local_70 [2];
  unsigned char * local_68 [9];
  ushort uVar13;
  
  iVar12 = CONCAT31(in_register_0000001c,param_4);
  local_70[0] = (unsigned char *)0x0;
  IndirectAddressHandler(this,local_70,param_2,param_3);
  local_68[0] = *param_2;
  bVar2 = false;
  local_68[1] = *param_3;
  if ((*(int *)local_68[0] != 0) &&
     ((sVar1 = *(short *)(*(int *)local_68[0] + 0x2c), sVar1 == 0x7ffe || (sVar1 == 0x7fff)))) {
    iVar3 = ((int (*)())TPPStreamCompiler__generateAddressLoad)(this,local_68[0]);
    if (iVar3 != 0) {
      ((int (*)())TPPStreamCompiler__equalOperands)(TType*,ParseOperand**,ParseOperand**,bool)source0Indirect = 1;
    }
    iVar4 = ((int (*)())TPPStreamCompiler__generateAddressLoad)(this,local_68[1]);
    if (iVar4 != 0) {
      ((int (*)())TPPStreamCompiler__equalOperands)(TType*,ParseOperand**,ParseOperand**,bool)source1Indirect = 1;
    }
    bVar2 = iVar4 != 0 || iVar3 != 0;
  }
  iVar3 = *(int *)local_68[0];
  if ((iVar3 == 0) || (*(short *)(iVar3 + 0x2c) != 0x7ffe)) {
    iVar3 = *(int *)local_68[0];
    if ((iVar3 == 0) || (*(short *)(iVar3 + 0x2c) != 0x7fff)) {
      local_dc = 0;
      local_b0 = *(undefined4 *)(this + 0x90);
      local_b8 = 0;
      local_b4 = 0;
      local_e0 = 0x40000000;
      local_d8 = 0;
      local_d4 = 0;
      local_d0 = 0;
      local_cc = 0;
      local_c8 = 0;
      local_c4 = 0;
      local_c0 = 0;
      local_bc = 0;
      local_ac = 0;
      ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&local_80);
      local_d0 = local_80;
      local_cc = local_7c;
      if (((int (*)())TPPStreamCompiler__equalOperands)(TType*,ParseOperand**,ParseOperand**,bool)source0Indirect != 0) {
        local_d0 = local_80 & 0x8fffff00 | 0x80000000;
      }
      ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&local_80);
      local_c8 = local_80;
      local_c4 = local_7c;
      if (((int (*)())TPPStreamCompiler__equalOperands)(TType*,ParseOperand**,ParseOperand**,bool)source1Indirect != 0) {
        local_c8 = local_80 & 0x8fffff00 | 0x80000000;
      }
      local_70[0] = (unsigned char *)TPPStreamCompiler__newTemporary(this,param_1);
      ((int (*)())TPPStreamCompiler__getOperandAsDestVar)((unsigned char *)&local_80);
      local_d4 = local_7c;
      iVar3 = 0x31;
      local_d8 = local_80;
      if (iVar12 == 0) {
        iVar3 = 0x36;
      }
      local_e0 = iVar3 << 0x12 | local_e0 & 0xfc03ffff;
      local_dc = (local_80 >> 0xc & 1) << 0x1c | local_dc & 0xefffffff;
      if (*(int *)local_70[0] == 0) {
        uVar13 = *(ushort *)(local_70[0] + 0x18);
      }
      else {
        uVar13 = *(ushort *)(*(int *)local_70[0] + 0x2c);
      }
      uVar11 = GetPPStreamTypeForGLType(uVar13);
      local_dc = (uVar11 & 7) << 0x17 | local_dc & 0xfc7fffff;
      iVar12 = ParseOperand__GetLogicalSize();
      local_dc = (iVar12 + -1) * 0x4000000 & 0xc000000U | local_dc & 0xf3f3ffff;
      _PPStreamAddOperation(*(undefined4 *)(this + 0x70),&local_e0,0,0);
    }
    else {
      iVar3 = *(short *)(iVar3 + 0x2e) + -1;
      if (-1 < iVar3) {
        do {
          iVar14 = 0;
          iVar4 = 1;
          do {
            pPVar8 = operator_new(0x38);
            ParseOperand__ParseOperand(pPVar8);
            *(unsigned char **)((int)local_68 + iVar14 + 8) = pPVar8;
            pPVar9 = operator_new(100);
            ParseSymbol__ParseSymbol(pPVar9);
            ParseSymbol__SetName((char *)pPVar9);
            ParseSymbol__AddDirectIndex((uint)pPVar9);
            _sprintf((char *)&local_e0,DAT_a7b7bd90,iVar3);
            ParseSymbol__CatName((char *)pPVar9);
            *(undefined4 *)(pPVar9 + 0x40) =
                 *(undefined4 *)(**(int **)((int)local_68 + iVar14) + 0x40);
            *(undefined4 *)(pPVar9 + 0x3c) =
                 *(undefined4 *)(**(int **)((int)local_68 + iVar14) + 0x3c);
            ParseSymbol__SetParseTreeType((unsigned char *)pPVar9);
            iVar15 = **(int **)((int)local_68 + iVar14);
            *(undefined4 *)(pPVar9 + 0x48) = 1;
            *(undefined4 *)(pPVar9 + 0x28) = *(undefined4 *)(iVar15 + 0x28);
            ParseSymbol__ResolveOpenGLType();
            **(undefined4 **)((int)local_68 + iVar14 + 8) = pPVar9;
            if ((*(short *)(pPVar9 + 0x2c) != 0x7ffe) && (*(short *)(pPVar9 + 0x2c) != 0x7fff)) {
              ParseSymbolTable__processOperand(*(unsigned char **)(this + 0x68));
            }
            pPVar8 = local_70;
            iVar4 = iVar4 + -1;
            iVar14 = iVar14 + 4;
          } while (-1 < iVar4);
          local_70[0] = (unsigned char *)
                        ((int (*)())TPPStreamCompiler__equalOperands)(this,param_1,local_68 + 2,local_68 + 3,param_4);
          pPVar10 = local_68[2];
          if (local_68[2] != (unsigned char *)0x0) {
            ParseOperand___ParseOperand(local_68[2]);
            operator_delete(pPVar10);
          }
          pPVar10 = local_68[3];
          if (local_68[3] != (unsigned char *)0x0) {
            ParseOperand___ParseOperand(local_68[3]);
            operator_delete(pPVar10);
          }
          pPVar10 = local_70;
          if ((pPVar8 != (unsigned char *)0x0) && (local_70[0] != (unsigned char *)0x0)) {
            pPVar10 = (unsigned char *)TPPStreamCompiler__newTemporary(this,param_1);
            local_dc = 0;
            local_b0 = *(undefined4 *)(this + 0x90);
            local_e0 = 0x40000000;
            local_d8 = 0;
            local_d4 = 0;
            local_d0 = 0;
            local_cc = 0;
            local_c8 = 0;
            local_c4 = 0;
            local_c0 = 0;
            local_bc = 0;
            local_b8 = 0;
            local_b4 = 0;
            local_ac = 0;
            ((int (*)())TPPStreamCompiler__getOperandAsDestVar)((unsigned char *)&local_90);
            local_d8 = local_90;
            local_d4 = local_8c;
            ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&local_90);
            local_d0 = local_90;
            local_cc = local_8c;
            ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&local_90);
            local_e0 = ((iVar12 == 0) + 0x24) * 0x40000 | local_e0 & 0xfc03ffff;
            local_dc = (local_d8 >> 0xc & 1) << 0x1c | local_dc & 0xefffffff;
            local_c8 = local_90;
            local_c4 = local_8c;
            if (*(int *)local_70[0] == 0) {
              uVar13 = *(ushort *)(local_70[0] + 0x18);
            }
            else {
              uVar13 = *(ushort *)(*(int *)local_70[0] + 0x2c);
            }
            uVar11 = GetPPStreamTypeForGLType(uVar13);
            local_dc = (uVar11 & 7) << 0x17 | local_dc & 0xfc7fffff;
            iVar4 = ParseOperand__GetLogicalSize();
            local_dc = (iVar4 + -1) * 0x4000000 & 0xc000000U | local_dc & 0xf3f3ffff;
            _PPStreamAddOperation(*(undefined4 *)(this + 0x70),&local_e0,0,0);
            ParseOperand___ParseOperand(pPVar8);
            operator_delete(pPVar8);
            pPVar8 = local_70;
            if (local_70[0] != (unsigned char *)0x0) {
              ParseOperand___ParseOperand(local_70[0]);
              operator_delete(pPVar8);
            }
          }
          local_70[0] = pPVar10;
          iVar3 = iVar3 + -1;
        } while (-1 < iVar3);
      }
    }
  }
  else {
    iVar3 = *(int *)(*(int *)(iVar3 + 0xc) + 8);
    if (iVar3 != 0) {
      iVar4 = *(int *)(iVar3 + 4);
      iVar14 = (*(int *)(iVar3 + 8) - iVar4 >> 3) + -1;
      if (-1 < iVar14) {
        while( true ) {
          iVar15 = 0;
          while( true ) {
            pcVar16 = *(char **)(*(int *)local_68[iVar15] + 0x14);
            iVar4 = (**(code **)(**(int **)(iVar4 + iVar14 * 8) + 0x1c))();
            *(undefined1 *)(*(int *)(iVar4 + 4) + *(int *)(*(int *)(iVar4 + 4) + -0xc)) =
                 *DAT_a7b7bd9c;
            pcVar17 = *(char **)(iVar4 + 4);
            sVar5 = _strlen(pcVar17);
            sVar5 = sVar5 + 1;
            if (pcVar16 != (char *)0x0) {
              sVar6 = _strlen(pcVar16);
              sVar5 = sVar5 + sVar6 + 1;
            }
            pcVar7 = _malloc(sVar5);
            if (pcVar16 == (char *)0x0) {
              _strcpy(pcVar7,pcVar17);
            }
            else {
              _sprintf(pcVar7,DAT_a7b7bd8c,pcVar16,pcVar17);
            }
            pPVar8 = operator_new(0x38);
            ParseOperand__ParseOperand(pPVar8);
            local_68[iVar15 + 2] = pPVar8;
            pPVar9 = operator_new(100);
            ParseSymbol__ParseSymbol(pPVar9);
            ParseSymbol__SetName((char *)pPVar9);
            _free(pcVar7);
            *(undefined4 *)(pPVar9 + 0x40) = *(undefined4 *)(*(int *)local_68[iVar15] + 0x40);
            *(undefined4 *)(pPVar9 + 0x3c) = *(undefined4 *)(*(int *)local_68[iVar15] + 0x3c);
            ParseSymbol__SetParseTreeType((unsigned char *)pPVar9);
            *(undefined4 *)(pPVar9 + 0x28) = *(undefined4 *)(*(int *)local_68[iVar15] + 0x28);
            *(unsigned char **)local_68[iVar15 + 2] = pPVar9;
            if ((*(short *)(pPVar9 + 0x2c) != 0x7ffe) && (*(short *)(pPVar9 + 0x2c) != 0x7fff)) {
              ParseSymbolTable__processOperand(*(unsigned char **)(this + 0x68));
            }
            pPVar8 = local_70;
            iVar15 = iVar15 + 1;
            if (1 < iVar15) break;
            iVar4 = *(int *)(iVar3 + 4);
          }
          local_70[0] = (unsigned char *)
                        ((int (*)())TPPStreamCompiler__equalOperands)(this,param_1,local_68 + 2,local_68 + 3,param_4);
          pPVar10 = local_68[2];
          if (local_68[2] != (unsigned char *)0x0) {
            ParseOperand___ParseOperand(local_68[2]);
            operator_delete(pPVar10);
          }
          pPVar10 = local_68[3];
          if (local_68[3] != (unsigned char *)0x0) {
            ParseOperand___ParseOperand(local_68[3]);
            operator_delete(pPVar10);
          }
          pPVar10 = local_70;
          if ((pPVar8 != (unsigned char *)0x0) && (local_70[0] != (unsigned char *)0x0)) {
            pPVar10 = (unsigned char *)TPPStreamCompiler__newTemporary(this,param_1);
            local_dc = 0;
            local_b0 = *(undefined4 *)(this + 0x90);
            local_b8 = 0;
            local_b4 = 0;
            local_d8 = 0;
            local_d4 = 0;
            local_d0 = 0;
            local_cc = 0;
            local_c8 = 0;
            local_c4 = 0;
            local_c0 = 0;
            local_bc = 0;
            local_ac = 0;
            local_e0 = 0x40000000;
            ((int (*)())TPPStreamCompiler__getOperandAsDestVar)((unsigned char *)&local_a0);
            local_d8 = local_a0;
            local_d4 = local_9c;
            ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&local_a0);
            local_d0 = local_a0;
            local_cc = local_9c;
            ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&local_a0);
            local_e0 = ((iVar12 == 0) + 0x24) * 0x40000 | local_e0 & 0xfc03ffff;
            local_dc = (local_d8 >> 0xc & 1) << 0x1c | local_dc & 0xefffffff;
            local_c8 = local_a0;
            local_c4 = local_9c;
            if (*(int *)local_70[0] == 0) {
              uVar13 = *(ushort *)(local_70[0] + 0x18);
            }
            else {
              uVar13 = *(ushort *)(*(int *)local_70[0] + 0x2c);
            }
            uVar11 = GetPPStreamTypeForGLType(uVar13);
            local_dc = (uVar11 & 7) << 0x17 | local_dc & 0xfc7fffff;
            iVar4 = ParseOperand__GetLogicalSize();
            local_dc = (iVar4 + -1) * 0x4000000 & 0xc000000U | local_dc & 0xf3f3ffff;
            _PPStreamAddOperation(*(undefined4 *)(this + 0x70),&local_e0,0,0);
            ParseOperand___ParseOperand(pPVar8);
            operator_delete(pPVar8);
            pPVar8 = local_70;
            if (local_70[0] != (unsigned char *)0x0) {
              ParseOperand___ParseOperand(local_70[0]);
              operator_delete(pPVar8);
            }
          }
          local_70[0] = pPVar10;
          iVar14 = iVar14 + -1;
          if (iVar14 < 0) break;
          iVar4 = *(int *)(iVar3 + 4);
        }
      }
    }
  }
  if (bVar2) {
    ((int (*)())TPPStreamCompiler__equalOperands)(TType*,ParseOperand**,ParseOperand**,bool)source1Indirect = 0;
    ((int (*)())TPPStreamCompiler__equalOperands)(TType*,ParseOperand**,ParseOperand**,bool)source0Indirect = 0;
  }
  return local_70[0];
}
#endif

/* TPPStreamCompiler__duplicateDestinationSource @ 0x97bc58e4 (636 bytes) */
#if 0   /* compile-failing as plain C: Ghidra text kept verbatim, see ledger status */
int TPPStreamCompiler__duplicateDestinationSource(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  uint param_2;
  uint param_3;
  uint param_4;
  uint param_5;
{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar4 = 1;
  if ((param_2 >> 0x11 & 7) != (param_4 >> 0x17 & 7)) {
    return 0;
  }
  if ((param_3 & 0xffff) != (param_5 & 0xffff)) {
    return 0;
  }
  if ((param_2 >> 0xc & 1) != (param_4 >> 0xe & 1)) {
    return 0;
  }
  if ((param_4 & 0x8000000) != 0) {
    return 0;
  }
  if ((param_3 & 0xf0000000) != (param_4 & 0xf0000000)) {
    return 0;
  }
  if ((int)(param_3 << 4 | param_3 >> 0x1c) >> 0x18 != (int)(char)param_4) {
    return 0;
  }
  if ((param_2 & 0x7ff00000) != 0) {
    return 0;
  }
  uVar2 = param_2 >> 10 & 3;
  if (uVar2 != 1) {
    if (uVar2 == 0) goto LAB_97bc5aec;
    if (uVar2 != 2) {
      if (uVar2 != 3) {
        return uVar4;
      }
      if ((param_2 & 0x10000) != 0) {
        uVar2 = param_2 >> 2 & 3;
        if (uVar2 == 1) {
          uVar2 = param_4 & 0x180000;
          uVar3 = 0x180000;
LAB_97bc59d0:
          bVar1 = uVar2 == uVar3;
LAB_97bc59e8:
          if (bVar1) goto LAB_97bc59f0;
        }
        else {
          if (uVar2 == 0) {
            uVar2 = param_4 & 0x600000;
            uVar3 = 0x600000;
            goto LAB_97bc59d0;
          }
          if (uVar2 == 2) {
            uVar2 = param_4 & 0x60000;
            uVar3 = 0x60000;
            goto LAB_97bc59d0;
          }
          if (uVar2 == 3) {
            bVar1 = (param_4 & 0x18000) == 0x18000;
            goto LAB_97bc59e8;
          }
        }
        uVar4 = 0;
      }
    }
LAB_97bc59f0:
    if ((param_2 & 0x8000) != 0) {
      uVar2 = param_2 >> 4 & 3;
      if (uVar2 == 1) {
        uVar3 = 0x100000;
        uVar2 = param_4 & 0x180000;
LAB_97bc5a60:
        if (uVar2 == uVar3) goto LAB_97bc5a6c;
      }
      else {
        if (uVar2 == 0) {
          uVar3 = 0x400000;
          uVar2 = param_4 & 0x600000;
          goto LAB_97bc5a60;
        }
        if (uVar2 == 2) {
          uVar3 = 0x40000;
          uVar2 = param_4 & 0x60000;
          goto LAB_97bc5a60;
        }
        if (uVar2 == 3) {
          uVar3 = 0x10000;
          uVar2 = param_4 & 0x18000;
          goto LAB_97bc5a60;
        }
      }
      uVar4 = 0;
    }
  }
LAB_97bc5a6c:
  if ((param_2 & 0x4000) == 0) goto LAB_97bc5aec;
  uVar2 = param_2 >> 6 & 3;
  if (uVar2 == 1) {
    uVar3 = 0x80000;
    uVar2 = param_4 & 0x180000;
LAB_97bc5ac8:
    bVar1 = uVar2 == uVar3;
LAB_97bc5ae4:
    if (bVar1) goto LAB_97bc5aec;
  }
  else {
    if (uVar2 == 0) {
      uVar3 = 0x200000;
      uVar2 = param_4 & 0x600000;
      goto LAB_97bc5ac8;
    }
    if (uVar2 == 2) {
      uVar3 = 0x20000;
      uVar2 = param_4 & 0x60000;
      goto LAB_97bc5ac8;
    }
    if (uVar2 == 3) {
      bVar1 = (param_4 & 0x18000) == 0x8000;
      goto LAB_97bc5ae4;
    }
  }
  uVar4 = 0;
LAB_97bc5aec:
  if ((param_2 & 0x2000) == 0) {
    return uVar4;
  }
  uVar2 = param_2 >> 8 & 3;
  if (uVar2 == 1) {
    if ((param_4 & 0x180000) == 0) {
      return uVar4;
    }
  }
  else if (uVar2 == 0) {
    if ((param_4 & 0x600000) == 0) {
      return uVar4;
    }
  }
  else if (uVar2 == 2) {
    if ((param_4 & 0x60000) == 0) {
      return uVar4;
    }
  }
  else if ((uVar2 == 3) && ((param_4 & 0x18000) == 0)) {
    return uVar4;
  }
  return 0;
}
#endif

/* TPPStreamCompiler__assignOperands @ 0x97bc5b60 (1892 bytes) */
#if 0   /* compile-failing as plain C: Ghidra text kept verbatim, see ledger status */
int TPPStreamCompiler__assignOperands(this, param_1, param_2, param_3)
  unsigned char * this;
  unsigned char ** param_1;
  unsigned char ** param_2;
  int param_3;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  size_t sVar4;
  size_t sVar5;
  char *pcVar6;
  unsigned char * pPVar7;
  unsigned char * pPVar8;
  uint uVar9;
  undefined3 in_register_00000018;
  int iVar11;
  int iVar12;
  char *pcVar13;
  char *pcVar14;
  unsigned char * this_00;
  uint local_c0;
  uint local_bc;
  uint local_b0;
  uint local_ac;
  uint local_a8;
  uint local_a4;
  uint local_a0;
  uint local_9c;
  uint local_98;
  uint local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  uint local_70;
  uint local_6c;
  unsigned char * local_60 [4];
  unsigned char * local_50 [4];
  ushort uVar10;
  
  IndirectAddressHandler(this,param_1,param_2);
  local_60[0] = *param_1;
  bVar1 = false;
  local_60[1] = *param_2;
  if ((*(short *)(*(int *)local_60[0] + 0x2c) == 0x7ffe) ||
     (*(short *)(*(int *)local_60[0] + 0x2c) == 0x7fff)) {
    iVar2 = ((int (*)())TPPStreamCompiler__generateAddressLoad)(this,local_60[0]);
    if (iVar2 != 0) {
      ((int (*)())TPPStreamCompiler__assignOperands)(ParseOperand**,ParseOperand**,bool)destIndirect = 1;
    }
    iVar3 = ((int (*)())TPPStreamCompiler__generateAddressLoad)(this,local_60[1]);
    if (iVar3 != 0) {
      ((int (*)())TPPStreamCompiler__assignOperands)(ParseOperand**,ParseOperand**,bool)sourceIndirect = 1;
    }
    bVar1 = iVar3 != 0 || iVar2 != 0;
  }
  iVar2 = *(int *)local_60[0];
  if (*(short *)(iVar2 + 0x2c) == 0x7ffe) {
    iVar2 = *(int *)(*(int *)(iVar2 + 0xc) + 8);
    if (iVar2 != 0) {
      iVar11 = *(int *)(iVar2 + 4);
      iVar3 = *(int *)(iVar2 + 8) - iVar11 >> 3;
      if (iVar3 != 0) {
        while( true ) {
          iVar3 = iVar3 + -1;
          iVar12 = 0;
          while( true ) {
            pcVar13 = *(char **)(*(int *)local_60[iVar12] + 0x14);
            iVar11 = (**(code **)(**(int **)(iVar11 + iVar3 * 8) + 0x1c))();
            *(undefined1 *)(*(int *)(iVar11 + 4) + *(int *)(*(int *)(iVar11 + 4) + -0xc)) =
                 *DAT_a7b7bd9c;
            pcVar14 = *(char **)(iVar11 + 4);
            sVar4 = _strlen(pcVar14);
            sVar4 = sVar4 + 1;
            if (pcVar13 != (char *)0x0) {
              sVar5 = _strlen(pcVar13);
              sVar4 = sVar4 + sVar5 + 1;
            }
            pcVar6 = _malloc(sVar4);
            if (pcVar13 == (char *)0x0) {
              _strcpy(pcVar6,pcVar14);
            }
            else {
              _sprintf(pcVar6,DAT_a7b7bd8c,pcVar13,pcVar14);
            }
            pPVar7 = operator_new(0x38);
            ParseOperand__ParseOperand(pPVar7);
            local_60[iVar12 + 2] = pPVar7;
            pPVar8 = operator_new(100);
            ParseSymbol__ParseSymbol(pPVar8);
            ParseSymbol__SetName((char *)pPVar8);
            _free(pcVar6);
            *(undefined4 *)(pPVar8 + 0x3c) = 0;
            *(undefined4 *)(pPVar8 + 0x40) = 0;
            ParseSymbol__SetParseTreeType((unsigned char *)pPVar8);
            *(undefined4 *)(pPVar8 + 0x28) = *(undefined4 *)(*(int *)local_60[iVar12] + 0x28);
            *(unsigned char **)local_60[iVar12 + 2] = pPVar8;
            if ((*(short *)(pPVar8 + 0x2c) != 0x7ffe) && (*(short *)(pPVar8 + 0x2c) != 0x7fff)) {
              ParseSymbolTable__processOperand(*(unsigned char **)(this + 0x68));
            }
            iVar12 = iVar12 + 1;
            if (1 < iVar12) break;
            iVar11 = *(int *)(iVar2 + 4);
          }
          ((int (*)())TPPStreamCompiler__assignOperands)(this,local_60 + 2,local_60 + 3,param_3);
          pPVar7 = local_60[2];
          if (local_60[2] != (unsigned char *)0x0) {
            ParseOperand___ParseOperand(local_60[2]);
            operator_delete(pPVar7);
          }
          pPVar7 = local_60[3];
          if (local_60[3] != (unsigned char *)0x0) {
            ParseOperand___ParseOperand(local_60[3]);
            operator_delete(pPVar7);
          }
          if (iVar3 == 0) break;
          iVar11 = *(int *)(iVar2 + 4);
        }
      }
    }
  }
  else if (*(short *)(iVar2 + 0x2c) == 0x7fff) {
    iVar2 = (int)*(short *)(iVar2 + 0x2e);
    while (iVar2 != 0) {
      iVar2 = iVar2 + -1;
      iVar11 = 0;
      iVar3 = 1;
      do {
        pPVar7 = operator_new(0x38);
        ParseOperand__ParseOperand(pPVar7);
        *(unsigned char **)((int)local_60 + iVar11 + 0x10) = pPVar7;
        pPVar8 = operator_new(100);
        ParseSymbol__ParseSymbol(pPVar8);
        ParseSymbol__SetName((char *)pPVar8);
        ParseSymbol__AddDirectIndex((uint)pPVar8);
        _sprintf((char *)&local_c0,DAT_a7b7bd90,iVar2);
        ParseSymbol__CatName((char *)pPVar8);
        *(undefined4 *)(pPVar8 + 0x40) = 0;
        *(undefined4 *)(pPVar8 + 0x3c) = 0;
        ParseSymbol__SetParseTreeType((unsigned char *)pPVar8);
        iVar12 = **(int **)((int)local_60 + iVar11);
        *(undefined4 *)(pPVar8 + 0x48) = 1;
        *(undefined4 *)(pPVar8 + 0x28) = *(undefined4 *)(iVar12 + 0x28);
        ParseSymbol__ResolveOpenGLType();
        **(undefined4 **)((int)local_60 + iVar11 + 0x10) = pPVar8;
        if ((*(short *)(pPVar8 + 0x2c) != 0x7ffe) && (*(short *)(pPVar8 + 0x2c) != 0x7fff)) {
          ParseSymbolTable__processOperand(*(unsigned char **)(this + 0x68));
        }
        iVar3 = iVar3 + -1;
        iVar11 = iVar11 + 4;
      } while (-1 < iVar3);
      ((int (*)())TPPStreamCompiler__assignOperands)(this,local_60 + 4,local_60 + 5,param_3);
      pPVar7 = local_50;
      if (local_50[0] != (unsigned char *)0x0) {
        ParseOperand___ParseOperand(local_50[0]);
        operator_delete(pPVar7);
      }
      pPVar7 = local_50[1];
      if (local_50[1] != (unsigned char *)0x0) {
        ParseOperand___ParseOperand(local_50[1]);
        operator_delete(pPVar7);
      }
    }
  }
  else {
    pPVar7 = *(unsigned char **)(this + 0x88);
    local_80 = *(undefined4 *)(this + 0x90);
    local_88 = 0;
    local_84 = 0;
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
    local_7c = 0;
    if (pPVar7 == (unsigned char *)0x0) {
      local_b0 = 0x20000000;
      ((int (*)())TPPStreamCompiler__getOperandAsDestVar)((unsigned char *)&local_c0);
      local_a8 = local_c0;
      local_a4 = local_bc;
      if (((int (*)())TPPStreamCompiler__assignOperands)(ParseOperand**,ParseOperand**,bool)destIndirect != 0) {
        local_a4 = local_bc & 0x800fffff | 0x80000000;
      }
      ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&local_c0);
      local_a0 = local_c0;
      local_9c = local_bc;
      if (((int (*)())TPPStreamCompiler__assignOperands)(ParseOperand**,ParseOperand**,bool)sourceIndirect != 0) {
        (*(unsigned int *)((unsigned char *)&(local_a0) + 0)) = (uint3)(local_c0 >> 8) & 0x8fffff | 0x800000;
        local_a0 = (uint)(*(unsigned int *)((unsigned char *)&(local_a0) + 0)) << 8;
      }
      local_ac = (local_a8 >> 0xc & 1) << 0x1c | local_ac & 0xefffffff;
      iVar2 = *(int *)*param_1;
      if (iVar2 == 0) {
        uVar10 = *(ushort *)(*param_1 + 0x18);
      }
      else {
        uVar10 = *(ushort *)(iVar2 + 0x2c);
      }
      uVar9 = GetPPStreamTypeForGLType(uVar10);
      local_ac = (uVar9 & 7) << 0x17 | local_ac & 0xfc7fffff;
      iVar2 = ParseOperand__GetLogicalSize();
      local_ac = (iVar2 + -1) * 0x4000000 & 0xc000000U | local_ac & 0xf3f3ffff;
      local_70 = local_a8;
      local_6c = local_a4;
      local_c0 = local_a0;
      local_bc = local_9c;
      iVar2 = ((int (*)())TPPStreamCompiler__duplicateDestinationSource)(this,local_a8,local_a4,local_a0,local_9c);
      if ((iVar2 == 0) &&
         (((CONCAT31(in_register_00000018,param_3) == 0 || (*(int *)(this + 0xc4) < 2)) ||
          (iVar2 = ((int (*)())TPPStreamCompiler__copyPropagateCompilerTemp)(this,(unsigned char *)&local_b0,*param_2),
          iVar2 == 0)))) {
        _PPStreamAddOperation(*(undefined4 *)(this + 0x70),&local_b0,0,0);
      }
    }
    else {
      this_00 = *param_1;
      local_50[2] = *(unsigned char **)(pPVar7 + 0xc);
      if (this_00 != (unsigned char *)0x0) {
        ParseOperand___ParseOperand(this_00);
        operator_delete(this_00);
        pPVar7 = *(unsigned char **)(this + 0x88);
      }
      *param_1 = pPVar7;
      *(undefined4 *)(this + 0x88) = 0;
      *(undefined4 *)(*param_1 + 0xc) = 0;
      local_b0 = local_b0 & 0x1c03ffff | 0x41b40000;
      IndirectAddressHandler(this,param_1,param_2,local_60 + 6);
      ParseOperand__RemoveDirectIndex();
      ((int (*)())TPPStreamCompiler__getOperandAsDestVar)((unsigned char *)&local_c0);
      local_a8 = local_c0;
      local_a4 = local_bc;
      ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&local_c0);
      local_a0 = local_c0;
      local_9c = local_bc;
      ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&local_c0);
      local_ac = (local_a8 >> 0xc & 1) << 0x1c | local_ac & 0xefffffff;
      local_98 = local_c0;
      local_94 = local_bc;
      iVar2 = *(int *)*param_1;
      if (iVar2 == 0) {
        uVar10 = *(ushort *)(*param_1 + 0x18);
      }
      else {
        uVar10 = *(ushort *)(iVar2 + 0x2c);
      }
      uVar9 = GetPPStreamTypeForGLType(uVar10);
      local_ac = (uVar9 & 7) << 0x17 | local_ac & 0xfc7fffff;
      iVar2 = ParseOperand__GetLogicalSize();
      local_ac = (iVar2 + -1) * 0x4000000 & 0xc000000U | local_ac & 0xf3f3ffff;
      _PPStreamAddOperation(*(undefined4 *)(this + 0x70),&local_b0,0,0);
      pPVar7 = local_50[2];
      if (local_50[2] != (unsigned char *)0x0) {
        ParseOperand___ParseOperand(local_50[2]);
        operator_delete(pPVar7);
      }
    }
  }
  if (bVar1) {
    ((int (*)())TPPStreamCompiler__assignOperands)(ParseOperand**,ParseOperand**,bool)sourceIndirect = 0;
    ((int (*)())TPPStreamCompiler__assignOperands)(ParseOperand**,ParseOperand**,bool)destIndirect = 0;
  }
  return;
}
#endif

/* TPPStreamCompiler__getArrayOffset @ 0x97bc62c4 (404 bytes) */
#if 0   /* compile-failing as plain C: Ghidra text kept verbatim, see ledger status */
int TPPStreamCompiler__getArrayOffset(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  bool bVar1;
  byte bVar2;
  undefined4 *puVar3;
  unsigned char * this_00;
  uint uVar4;
  uint uVar5;
  char acStack_30 [20];
  
  uVar4 = 0;
  puVar3 = (undefined4 *)ParseSymbolTable__FindFirstElement(*(unsigned char **)(this + 0x68));
  if (puVar3 != (undefined4 *)0x0) {
    bVar2 = *(byte *)*puVar3;
    if (bVar2 != 2) {
      if (bVar2 < 3) {
        bVar1 = bVar2 == 0;
      }
      else {
        if (bVar2 == 3) goto LAB_97bc632c;
        bVar1 = bVar2 == 4;
      }
      if (!bVar1) goto LAB_97bc6330;
    }
LAB_97bc632c:
    uVar4 = (uint)*(ushort *)((byte *)*puVar3 + 0x12);
  }
LAB_97bc6330:
  this_00 = operator_new(100);
  ParseSymbol__ParseSymbol(this_00);
  ParseSymbol__SetName((char *)this_00);
  ParseSymbol__RemoveArrayIndex();
  ParseSymbol__AddDirectIndex((uint)this_00);
  _sprintf(acStack_30,DAT_a7b7bd90,1);
  ParseSymbol__CatName((char *)this_00);
  *(undefined4 *)(this_00 + 0x28) = *(undefined4 *)(*(int *)param_1 + 0x28);
  ParseSymbol__SetParseTreeType((unsigned char *)this_00);
  *(undefined4 *)(this_00 + 0x48) = *(undefined4 *)(*(int *)param_1 + 0x48);
  ParseSymbol__ResolveOpenGLType();
  puVar3 = (undefined4 *)ParseSymbolTable__FindFirstElement(*(unsigned char **)(this + 0x68));
  if (this_00 != (unsigned char *)0x0) {
    ParseSymbol___ParseSymbol(this_00);
    operator_delete(this_00);
  }
  if (puVar3 == (undefined4 *)0x0) {
    ((int (*)())TPPStreamCompiler__warning)(SUB41(this,0),(char *)0x0,*(char **)(*(int *)param_1 + 0x14),DAT_a7b7bd3c);
    uVar5 = uVar4;
    goto LAB_97bc6440;
  }
  bVar2 = *(byte *)*puVar3;
  if (bVar2 != 2) {
    if (bVar2 < 3) {
      bVar1 = bVar2 == 0;
    }
    else {
      if (bVar2 == 3) goto LAB_97bc6414;
      bVar1 = bVar2 == 4;
    }
    uVar5 = 0;
    if (!bVar1) goto LAB_97bc6440;
  }
LAB_97bc6414:
  uVar5 = (uint)*(ushort *)((byte *)*puVar3 + 0x12);
LAB_97bc6440:
  return uVar5 - uVar4;
}
#endif

/* TPPStreamCompiler__constructReplicate @ 0x97bc6458 (640 bytes) */
int TPPStreamCompiler__constructReplicate(param_1, param_2, param_3)
  unsigned char ** param_1;
  unsigned char ** param_2;
  int param_3;
{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int *piVar5;
  int iVar6;
  undefined4 local_80;
  uint local_7c;
  uint local_78;
  undefined4 local_74;
  uint local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  unsigned char * local_50;
  undefined4 local_4c;
  uint local_40;
  undefined4 local_3c;
  undefined4 local_30;
  ushort uVar4;
  
  local_30 = 0;
  IndirectAddressHandler((unsigned char *)param_1,param_2,(unsigned char **)param_3);
  local_7c = 0;
  local_50 = param_1[0x24];
  local_4c = 0;
  local_80 = 0x20000000;
  local_58 = 0;
  local_54 = 0;
  local_78 = 0;
  local_74 = 0;
  local_70 = 0;
  local_6c = 0;
  local_68 = 0;
  local_64 = 0;
  local_60 = 0;
  local_5c = 0;
  ((int (*)())TPPStreamCompiler__getOperandAsDestVar)((unsigned char *)&local_40);
  piVar5 = *(int **)param_3;
  local_78 = local_40 & 0xfffe1c2f | 0x6c;
  local_74 = local_3c;
  if (*piVar5 == 0) {
    uVar4 = *(ushort *)(piVar5 + 6);
    if (uVar4 == 0x1406) {
      local_30 = *(undefined4 *)piVar5[1];
    }
    else {
      if (uVar4 < 0x1407) {
        bVar1 = uVar4 == 0x1404;
      }
      else {
        bVar1 = uVar4 == 0x8b56;
      }
      if (bVar1) {
        local_30 = *(undefined4 *)piVar5[1];
      }
    }
    ((int (*)())TPPStreamCompiler__getConstantAsSourceVar)((unsigned char *)&local_40,(uint)param_1,(short)&STACKARG(0xffffff40) + 0x90);
  }
  else {
    ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&local_40);
  }
  local_70 = local_40;
  local_6c = local_3c;
  for (iVar6 = 0; iVar2 = ParseOperand__GetLogicalSize(), iVar6 < iVar2; iVar6 = iVar6 + 1) {
    if (iVar6 == 1) {
      local_78 = local_78 & 0xffffff3f | 0x4000;
    }
    else if (iVar6 < 2) {
      if (iVar6 == 0) {
        local_78 = local_78 & 0xfffffcff | 0x2000;
      }
    }
    else if (iVar6 == 2) {
      local_78 = local_78 & 0xffffffcf | 0x8000;
    }
    else if (iVar6 == 3) {
      local_78 = local_78 & 0xfffffff3 | 0x10000;
    }
  }
  local_7c = (local_78 >> 0xc & 1) << 0x1c | local_7c & 0xefffffff;
  iVar6 = *(int *)*param_2;
  if (iVar6 == 0) {
    uVar4 = *(ushort *)(*param_2 + 0x18);
  }
  else {
    uVar4 = *(ushort *)(iVar6 + 0x2c);
  }
  uVar3 = GetPPStreamTypeForGLType(uVar4);
  local_7c = (uVar3 & 7) << 0x17 | local_7c & 0xfc7fffff;
  iVar6 = ParseOperand__GetLogicalSize();
  local_7c = (iVar6 + -1) * 0x4000000 & 0xc000000U | local_7c & 0xf3f3ffff;
  ((int (*)())TPPStreamCompiler__AddOperation)((unsigned char *)param_1,param_2,(unsigned char *)&local_80,(char *)0x0,0);
  return 1;
}

/* TPPStreamCompiler__constructDiagonal @ 0x97bc66d8 (1452 bytes) */
int TPPStreamCompiler__constructDiagonal(param_1, param_2, param_3)
  unsigned char ** param_1;
  unsigned char ** param_2;
  int param_3;
{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int *piVar9;
  int iVar10;
  undefined4 *puVar11;
  int iVar12;
  undefined4 local_f0;
  uint local_ec;
  uint local_e8;
  undefined4 local_e4;
  uint local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  unsigned char * local_c0;
  undefined4 local_bc;
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
  unsigned char * local_80;
  undefined4 local_7c;
  undefined4 local_70 [4];
  uint local_60;
  undefined4 local_5c;
  ushort uVar8;
  
  IndirectAddressHandler((unsigned char *)param_1,param_2,(unsigned char **)param_3);
  iVar12 = 0;
  iVar5 = ParseOperand__GetLogicalSize();
  iVar6 = ParseOperand__IsMatrix();
  iVar10 = iVar5;
  if (iVar6 == 0) {
    iVar10 = 1;
  }
  if (iVar10 != 0) {
    bVar1 = iVar5 != 4;
    puVar11 = local_70;
    do {
      puVar4 = local_70;
      iVar6 = 4;
      do {
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      bVar2 = iVar12 == 0;
      if (bVar2) {
        ParseOperand__AddDirectIndex((uint)*param_2);
      }
      else {
        *(int *)(*(int *)(*param_2 + 0x20) * 4 + *(int *)(*param_2 + 0x1c) + -4) = iVar12;
      }
      local_80 = param_1[0x24];
      local_7c = 0;
      local_b0 = 0x20000000;
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
      local_ac = 0;
      ((int (*)())TPPStreamCompiler__getOperandAsDestVar)((unsigned char *)&local_60);
      piVar9 = *(int **)param_3;
      uVar7 = local_60 & 0xfffe1c0f;
      local_a8 = uVar7 | 0x6c;
      local_a4 = local_5c;
      if (*piVar9 == 0) {
        uVar8 = *(ushort *)(piVar9 + 6);
        if (uVar8 == 0x1406) {
          *puVar11 = *(undefined4 *)piVar9[1];
        }
        else {
          if (uVar8 < 0x1407) {
            bVar3 = uVar8 == 0x1404;
          }
          else {
            bVar3 = uVar8 == 0x8b56;
          }
          if (bVar3) {
            *puVar11 = *(undefined4 *)piVar9[1];
          }
        }
        if (iVar12 == 1) {
          local_a8 = uVar7 | 0x406c;
        }
        else if (iVar12 < 2) {
          if (bVar2) {
            local_a8 = uVar7 | 0x206c;
          }
        }
        else if (iVar12 == 2) {
          local_a8 = uVar7 | 0x806c;
        }
        else if (iVar12 == 3) {
          local_a8 = local_a8 & 0xfffffff3 | 0x1000c;
        }
      }
      else {
        local_ec = 0;
        local_c0 = param_1[0x24];
        local_f0 = 0x20000000;
        local_bc = 0;
        local_e8 = 0;
        local_e4 = 0;
        local_e0 = 0;
        local_dc = 0;
        local_d8 = 0;
        local_d4 = 0;
        local_d0 = 0;
        local_cc = 0;
        local_c8 = 0;
        local_c4 = 0;
        ((int (*)())TPPStreamCompiler__getOperandAsDestVar)((unsigned char *)&local_60);
        local_e8 = local_60 & 0xfffe1c03 | 0x6c;
        local_e4 = local_5c;
        ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&local_60);
        local_e0 = local_60;
        local_dc = local_5c;
        if (iVar12 == 1) {
          local_e8 = local_e8 & 0xffffff3f | 0x4000;
        }
        else if (iVar12 < 2) {
          if (bVar2) {
            local_e8 = local_e8 & 0xfffffcff | 0x2000;
          }
        }
        else if (iVar12 == 2) {
          local_e8 = local_e8 & 0xffffffcf | 0x8000;
        }
        else if (iVar12 == 3) {
          local_e8 = local_e8 & 0xfffffff3 | 0x10000;
        }
        local_ec = (local_e8 >> 0xc & 1) << 0x1c | local_ec & 0xefffffff;
        iVar6 = *(int *)*param_2;
        if (iVar6 == 0) {
          uVar8 = *(ushort *)(*param_2 + 0x18);
        }
        else {
          uVar8 = *(ushort *)(iVar6 + 0x2c);
        }
        uVar7 = GetPPStreamTypeForGLType(uVar8);
        local_ec = (uVar7 & 7) << 0x17 | local_ec & 0xfc7fffff;
        iVar6 = ParseOperand__GetLogicalSize();
        local_ec = (iVar6 + -1) * 0x4000000 & 0xc000000U | local_ec & 0xf3f3ffff;
        ((int (*)())TPPStreamCompiler__AddOperation)((unsigned char *)param_1,param_2,(unsigned char *)&local_f0,
                     (char *)0x0,0);
      }
      if (iVar12 == 1) {
        uVar7 = local_a8 & 0xfffffcff | 0x2000;
        if (iVar5 != 3) {
          if (bVar1) goto LAB_97bc6b98;
          uVar7 = local_a8 & 0xfffffcf3 | 0x1200c;
        }
LAB_97bc6b90:
        uVar7 = uVar7 & 0xffffffcf | 0x8020;
      }
      else {
        uVar7 = local_a8;
        if (iVar12 < 2) {
          if (bVar2) {
            if (iVar5 == 3) {
LAB_97bc6ae0:
              local_a8 = local_a8 & 0xffffffcf | 0x8020;
LAB_97bc6af8:
              uVar7 = local_a8 & 0xffffff3f | 0x4040;
            }
            else if (iVar5 < 4) {
              if (iVar5 == 2) goto LAB_97bc6af8;
            }
            else if (!bVar1) {
              local_a8 = local_a8 & 0xfffffff3 | 0x1000c;
              goto LAB_97bc6ae0;
            }
          }
        }
        else if (iVar12 == 2) {
          uVar7 = local_a8 & 0xfffffc3f | 0x6040;
          if (!bVar1) {
            uVar7 = local_a8 & 0xfffffc33 | 0x1604c;
          }
        }
        else if (iVar12 == 3) {
          uVar7 = local_a8 & 0xfffffc3f | 0x6040;
          goto LAB_97bc6b90;
        }
      }
LAB_97bc6b98:
      local_a8 = uVar7;
      ((int (*)())TPPStreamCompiler__getConstantAsSourceVar)((unsigned char *)&local_60,(uint)param_1,(ushort)local_70);
      local_ac = (local_a8 >> 0xc & 1) << 0x1c | local_ac & 0xefffffff;
      local_a0 = local_60;
      local_9c = local_5c;
      iVar6 = *(int *)*param_2;
      if (iVar6 == 0) {
        uVar8 = *(ushort *)(*param_2 + 0x18);
      }
      else {
        uVar8 = *(ushort *)(iVar6 + 0x2c);
      }
      uVar7 = GetPPStreamTypeForGLType(uVar8);
      local_ac = (uVar7 & 7) << 0x17 | local_ac & 0xfc7fffff;
      iVar12 = iVar12 + 1;
      iVar6 = ParseOperand__GetLogicalSize();
      local_ac = (iVar6 + -1) * 0x4000000 & 0xc000000U | local_ac & 0xf3f3ffff;
      ((int (*)())TPPStreamCompiler__AddOperation)((unsigned char *)param_1,param_2,(unsigned char *)&local_b0,(char *)0x0,
                   0);
      puVar11 = puVar11 + 1;
    } while (iVar12 != iVar10);
  }
  ParseOperand__RemoveDirectIndex();
  return 1;
}

/* TPPStreamCompiler__constructElement @ 0x97bc6c84 (1744 bytes) */
int TPPStreamCompiler__constructElement(this, param_1, param_2, param_3)
  unsigned char * this;
  unsigned char ** param_1;
  unsigned char ** param_2;
  int param_3;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  ushort uVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  undefined1 *puVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  unsigned char ** ppPVar14;
  int iVar15;
  int iVar16;
  undefined4 local_100;
  uint local_fc;
  uint local_f8;
  undefined4 local_f4;
  uint local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c0;
  uint local_bc;
  uint local_b8;
  undefined4 local_b4;
  uint local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_80 [4];
  uint local_70;
  undefined4 local_6c;
  int local_60;
  int local_5c;
  uint local_58;
  uint local_54;
  
  ppPVar14 = param_2;
  if (0 < param_3) {
    do {
      IndirectAddressHandler(this,param_1,ppPVar14);
      param_3 = param_3 + -1;
      ppPVar14 = ppPVar14 + 1;
    } while (param_3 != 0);
  }
  local_60 = 0;
  uVar8 = 0;
  iVar2 = ParseOperand__GetLogicalSize();
  uVar11 = 0;
  iVar3 = ParseOperand__IsMatrix();
  local_5c = 0;
  iVar7 = iVar2;
  if (iVar3 == 0) {
    iVar7 = 1;
  }
  local_58 = 0xffffffff;
  local_54 = 0;
  uVar9 = 0;
  iVar3 = -1;
  if (iVar7 != 0) {
    do {
      bVar1 = local_5c == 0;
      if ((bVar1) || (uVar9 != 0)) {
        iVar16 = 4;
        puVar6 = local_80;
        do {
          *puVar6 = 0;
          puVar6 = puVar6 + 1;
          iVar16 = iVar16 + -1;
        } while (iVar16 != 0);
        uVar9 = 0;
      }
      iVar15 = 0;
      iVar16 = ParseOperand__IsMatrix();
      if (iVar16 != 0) {
        if (bVar1) {
          ParseOperand__AddDirectIndex((uint)*param_1);
        }
        else {
          *(int *)(*(int *)(*param_1 + 0x20) * 4 + *(int *)(*param_1 + 0x1c) + -4) = local_5c;
        }
      }
      local_bc = 0;
      local_90 = *(undefined4 *)(this + 0x90);
      local_c0 = 0x20000000;
      bVar1 = iVar2 == 0;
      local_b8 = 0;
      local_b4 = 0;
      local_b0 = 0;
      local_ac = 0;
      local_a8 = 0;
      local_a4 = 0;
      local_a0 = 0;
      local_9c = 0;
      local_98 = 0;
      local_94 = 0;
      local_8c = 0;
      ((int (*)())TPPStreamCompiler__getOperandAsDestVar)((unsigned char *)&local_70);
      local_b8 = local_70 & 0xfffe1c2f | 0x6c;
      local_b4 = local_6c;
      if (!bVar1) {
        puVar10 = &STACKARG(0xfffffec0) + uVar9 * 4;
        do {
          iVar16 = iVar3 << 2;
          uVar12 = uVar11;
          if (uVar11 == uVar8) {
            local_58 = local_58 + 1;
            if (local_58 == local_54) {
              iVar3 = iVar3 + 1;
              iVar16 = iVar3 * 4;
              local_60 = local_60 + 1;
              uVar8 = ParseOperand__GetLogicalSize();
              iVar4 = ParseOperand__IsMatrix();
              if ((iVar4 == 0) || (local_54 = uVar8, *(int *)(param_2[iVar3] + 0x20) != 0)) {
                local_54 = 1;
              }
              local_58 = 0;
            }
            uVar12 = 0;
            if (1 < (int)local_54) {
              if (local_58 == 0) {
                ParseOperand__AddDirectIndex(*(uint *)(iVar16 + (int)param_2));
              }
              else {
                *(uint *)(*(int *)(*(int *)(iVar16 + (int)param_2) + 0x20) * 4 +
                          *(int *)(*(int *)(iVar16 + (int)param_2) + 0x1c) + -4) = local_58;
              }
            }
          }
          if (**(int **)(iVar16 + (int)param_2) == 0) {
            iVar4 = uVar8 - uVar12;
            if (iVar2 - iVar15 < (int)(uVar8 - uVar12)) {
              iVar4 = iVar2 - iVar15;
            }
            uVar11 = uVar12;
            if ((int)uVar12 < (int)(uVar12 + iVar4)) {
              iVar4 = (uVar12 + iVar4) - uVar12;
              puVar6 = (undefined4 *)(puVar10 + 0xc0);
              do {
                iVar13 = **(int **)(iVar16 + (int)param_2);
                if (iVar13 == 0) {
                  uVar5 = *(ushort *)(*(int **)(iVar16 + (int)param_2) + 6);
                }
                else {
                  uVar5 = *(ushort *)(iVar13 + 0x2c);
                }
                if (uVar5 == 0x1406) {
                  local_80[uVar9] =
                       *(undefined4 *)(uVar12 * 4 + *(int *)(*(int *)(iVar16 + (int)param_2) + 4));
                }
                else if (uVar5 < 0x1407) {
                  if (uVar5 == 0x1404) {
                    local_80[uVar9] =
                         *(undefined4 *)(uVar12 * 4 + *(int *)(*(int *)(iVar16 + (int)param_2) + 4))
                    ;
                  }
                }
                else if (uVar5 == 0x8b56) {
                  *puVar6 = *(undefined4 *)
                             (uVar12 * 4 + *(int *)(*(int *)(iVar16 + (int)param_2) + 4));
                }
                if (iVar15 == 1) {
                  local_b8 = (uVar9 & 3) << 6 | local_b8 & 0xffffff3f | 0x4000;
                }
                else if (iVar15 < 2) {
                  if (iVar15 == 0) {
                    local_b8 = (uVar9 & 3) << 8 | local_b8 & 0xfffffcff | 0x2000;
                  }
                }
                else if (iVar15 == 2) {
                  local_b8 = (uVar9 & 3) << 4 | local_b8 & 0xffffffcf | 0x8000;
                }
                else if (iVar15 == 3) {
                  local_b8 = (uVar9 & 3) << 2 | local_b8 & 0xfffffff3 | 0x10000;
                }
                iVar15 = iVar15 + 1;
                uVar9 = uVar9 + 1;
                puVar10 = puVar10 + 4;
                puVar6 = puVar6 + 1;
                uVar11 = uVar11 + 1;
                uVar12 = uVar12 + 1;
                iVar4 = iVar4 + -1;
              } while (iVar4 != 0);
              bVar1 = iVar15 == iVar2;
            }
          }
          else {
            local_fc = 0;
            local_d0 = *(undefined4 *)(this + 0x90);
            iVar13 = 0;
            local_100 = 0x20000000;
            local_f8 = 0;
            local_f4 = 0;
            local_f0 = 0;
            local_ec = 0;
            local_e8 = 0;
            local_e4 = 0;
            local_e0 = 0;
            local_dc = 0;
            local_d8 = 0;
            local_d4 = 0;
            local_cc = 0;
            ((int (*)())TPPStreamCompiler__getOperandAsDestVar)((unsigned char *)&local_70);
            local_f8 = local_70 & 0xfffe1c2f | 0x6c;
            local_f4 = local_6c;
            ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&local_70);
            local_f0 = local_70;
            local_ec = local_6c;
            iVar4 = uVar8 - uVar12;
            if (iVar2 - iVar15 < (int)(uVar8 - uVar12)) {
              iVar4 = iVar2 - iVar15;
            }
            if (0 < iVar4) {
              do {
                if (iVar15 == 1) {
                  local_f8 = (uVar12 & 3) << 6 | local_f8 & 0xffffff3f | 0x4000;
LAB_97bc704c:
                  iVar13 = iVar13 + 1;
                }
                else {
                  if (1 < iVar15) {
                    if (iVar15 == 2) {
                      local_f8 = (uVar12 & 3) << 4 | local_f8 & 0xffffffcf | 0x8000;
                    }
                    else {
                      if (iVar15 != 3) goto LAB_97bc7050;
                      local_f8 = (uVar12 & 3) << 2 | local_f8 & 0xfffffff3 | 0x10000;
                    }
                    goto LAB_97bc704c;
                  }
                  if (iVar15 == 0) {
                    local_f8 = (uVar12 & 3) << 8 | local_f8 & 0xfffffcff | 0x2000;
                    goto LAB_97bc704c;
                  }
                }
LAB_97bc7050:
                uVar12 = uVar12 + 1;
                iVar15 = iVar15 + 1;
                iVar4 = iVar4 + -1;
              } while (iVar4 != 0);
              bVar1 = iVar15 == iVar2;
            }
            uVar11 = uVar12;
            if (((1 < iVar7) || (*(int *)(this + 0xc4) < 2)) ||
               (iVar16 = ((int (*)())TPPStreamCompiler__copyPropagateCompilerTemp)(this,(unsigned char *)&local_100,
                                    *(unsigned char **)(iVar16 + (int)param_2)), iVar16 == 0)) {
              local_fc = (local_f8 >> 0xc & 1) << 0x1c | local_fc & 0xefffffff;
              iVar16 = *(int *)*param_1;
              if (iVar16 == 0) {
                uVar5 = *(ushort *)(*param_1 + 0x18);
              }
              else {
                uVar5 = *(ushort *)(iVar16 + 0x2c);
              }
              uVar12 = GetPPStreamTypeForGLType(uVar5);
              local_fc = (iVar13 + -1) * 0x4000000 & 0xc000000U |
                         (uVar12 & 7) << 0x17 | local_fc & 0xf073ffff;
              ((int (*)())TPPStreamCompiler__AddOperation)(this,param_1,(unsigned char *)&local_100,(char *)0x0,0);
            }
          }
        } while (!bVar1);
      }
      if (uVar9 != 0) {
        ((int (*)())TPPStreamCompiler__getConstantAsSourceVar)((unsigned char *)&local_70,(uint)this,(short)&STACKARG(0xfffffec0) + 0xc0);
        local_bc = (local_b8 >> 0xc & 1) << 0x1c | local_bc & 0xefffffff;
        local_b0 = local_70;
        local_ac = local_6c;
        iVar16 = *(int *)*param_1;
        if (iVar16 == 0) {
          uVar5 = *(ushort *)(*param_1 + 0x18);
        }
        else {
          uVar5 = *(ushort *)(iVar16 + 0x2c);
        }
        uVar12 = GetPPStreamTypeForGLType(uVar5);
        local_bc = (uVar9 - 1) * 0x4000000 & 0xc000000 |
                   (uVar12 & 7) << 0x17 | local_bc & 0xf073ffff;
        ((int (*)())TPPStreamCompiler__AddOperation)(this,param_1,(unsigned char *)&local_c0,(char *)0x0,0);
      }
      local_5c = local_5c + 1;
    } while (local_5c != iVar7);
  }
  iVar7 = ParseOperand__IsMatrix();
  if (iVar7 != 0) {
    ParseOperand__RemoveDirectIndex();
  }
  return local_60;
}

/* TPPStreamCompiler__constructFromOperand @ 0x97bc7354 (1620 bytes) */
int TPPStreamCompiler__constructFromOperand(this, param_1, param_2, param_3)
  unsigned char * this;
  unsigned char ** param_1;
  unsigned char ** param_2;
  int param_3;
{
  bool bVar1;
  short sVar2;
  int iVar3;
  size_t sVar4;
  size_t sVar5;
  char *pcVar6;
  unsigned char * pPVar7;
  unsigned char ** ppPVar8;
  int iVar9;
  char *pcVar10;
  unsigned char * pPVar11;
  unsigned char * pPVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  char *pcVar19;
  char acStack_70 [16];
  unsigned char * local_60;
  unsigned char * local_5c;
  char *local_58;
  int local_54;
  
  pPVar12 = *param_1;
  iVar15 = 0;
  iVar16 = 0;
  if (pPVar12 != (unsigned char *)0x0) {
    iVar3 = *(int *)pPVar12;
    sVar2 = *(short *)(iVar3 + 0x2c);
    iVar16 = iVar15;
    if (sVar2 == 0x7ffe) {
      local_58 = *(char **)(iVar3 + 0x14);
      iVar15 = *(int *)(*(int *)(iVar3 + 0xc) + 8);
      if (iVar15 != 0) {
        uVar14 = 0;
        iVar3 = *(int *)(iVar15 + 4);
        uVar13 = *(int *)(iVar15 + 8) - iVar3 >> 3;
        if (uVar13 != 0) {
          bVar1 = local_58 == (char *)0x0;
          local_54 = -0x58488c94;
          while( true ) {
            iVar3 = (**(code **)(**(int **)(iVar3 + uVar14 * 8) + 0x1c))();
            *(undefined1 *)(*(int *)(iVar3 + 4) + *(int *)(*(int *)(iVar3 + 4) + -0xc)) =
                 **(undefined1 **)(local_54 + 0x4a30);
            pcVar19 = *(char **)(iVar3 + 4);
            sVar4 = _strlen(pcVar19);
            sVar4 = sVar4 + 1;
            if (!bVar1) {
              sVar5 = _strlen(local_58);
              sVar4 = sVar4 + sVar5 + 1;
            }
            pcVar6 = _malloc(sVar4);
            if (bVar1) {
              _strcpy(pcVar6,pcVar19);
            }
            else {
              _sprintf(pcVar6,DAT_a7b7bd8c,local_58,pcVar19);
            }
            pPVar12 = operator_new(0x38);
            ParseOperand__ParseOperand(pPVar12);
            local_60 = pPVar12;
            pPVar7 = operator_new(100);
            ParseSymbol__ParseSymbol(pPVar7);
            ParseSymbol__SetName((char *)pPVar7);
            _free(pcVar6);
            ParseSymbol__SetParseTreeType((unsigned char *)pPVar7);
            *(unsigned char **)local_60 = pPVar7;
            if ((*(short *)(pPVar7 + 0x2c) == 0x7ffe) || (*(short *)(pPVar7 + 0x2c) == 0x7fff)) {
              iVar3 = *(int *)param_2[iVar16];
              if (*(short *)(iVar3 + 0x2c) == 0x7ffe) {
                pcVar19 = *(char **)(iVar3 + 0x14);
                iVar3 = *(int *)(*(int *)(iVar3 + 0xc) + 8);
                if (iVar3 != 0) {
                  uVar18 = 0;
                  uVar17 = *(int *)(iVar3 + 8) - *(int *)(iVar3 + 4) >> 3;
                  ppPVar8 = _malloc(uVar13 << 2);
                  if (uVar17 != 0) {
                    do {
                      iVar9 = (**(code **)(**(int **)(*(int *)(iVar3 + 4) + uVar18 * 8) + 0x1c))();
                      *(undefined1 *)(*(int *)(iVar9 + 4) + *(int *)(*(int *)(iVar9 + 4) + -0xc)) =
                           *DAT_a7b7bd9c;
                      pcVar6 = *(char **)(iVar9 + 4);
                      sVar4 = _strlen(pcVar6);
                      sVar4 = sVar4 + 1;
                      if (pcVar19 != (char *)0x0) {
                        sVar5 = _strlen(pcVar19);
                        sVar4 = sVar4 + sVar5 + 1;
                      }
                      pcVar10 = _malloc(sVar4);
                      if (pcVar19 == (char *)0x0) {
                        _strcpy(pcVar10,pcVar6);
                      }
                      else {
                        _sprintf(pcVar10,DAT_a7b7bd8c,pcVar19,pcVar6);
                      }
                      pPVar12 = operator_new(0x38);
                      ParseOperand__ParseOperand(pPVar12);
                      ppPVar8[uVar18] = pPVar12;
                      pPVar11 = operator_new(100);
                      ParseSymbol__ParseSymbol(pPVar11);
                      ParseSymbol__SetName((char *)pPVar11);
                      _free(pcVar10);
                      ParseSymbol__SetParseTreeType((unsigned char *)pPVar11);
                      *(unsigned char **)ppPVar8[uVar18] = pPVar11;
                      if ((*(short *)(pPVar11 + 0x2c) != 0x7ffe) &&
                         (*(short *)(pPVar11 + 0x2c) != 0x7fff)) {
                        ParseSymbolTable__processOperand(*(unsigned char **)(this + 0x68));
                      }
                      uVar18 = uVar18 + 1;
                    } while (uVar18 < uVar17);
                  }
                  uVar18 = 0;
                  ((int (*)())TPPStreamCompiler__constructFromOperand)(this,&local_60,ppPVar8,uVar17);
                  iVar16 = iVar16 + 1;
                  if (uVar17 != 0) {
                    do {
                      pPVar11 = *(unsigned char **)ppPVar8[uVar18];
                      if (((*(short *)(pPVar11 + 0x2c) == 0x7ffe) ||
                          (*(short *)(pPVar11 + 0x2c) == 0x7fff)) && (pPVar11 != (unsigned char *)0x0)
                         ) {
                        ParseSymbol___ParseSymbol(pPVar11);
                        operator_delete(pPVar11);
                      }
                      pPVar12 = ppPVar8[uVar18];
                      if (pPVar12 != (unsigned char *)0x0) {
                        ParseOperand___ParseOperand(pPVar12);
                        operator_delete(pPVar12);
                      }
                      uVar18 = uVar18 + 1;
                    } while (uVar18 < uVar17);
                  }
                  _free(ppPVar8);
                }
              }
              else {
                iVar3 = ((int (*)())TPPStreamCompiler__constructFromOperand)(this,&local_60,param_2 + iVar16,param_3 - iVar16);
                iVar16 = iVar16 + iVar3;
              }
              if (pPVar7 != (unsigned char *)0x0) {
                ParseSymbol___ParseSymbol(pPVar7);
                operator_delete(pPVar7);
              }
              *(undefined4 *)local_60 = 0;
            }
            else {
              ParseSymbolTable__processOperand(*(unsigned char **)(this + 0x68));
              iVar3 = ((int (*)())TPPStreamCompiler__constructFromOperand)(this,&local_60,param_2 + iVar16,param_3 - iVar16);
              iVar16 = iVar16 + iVar3;
            }
            pPVar12 = local_60;
            if (local_60 != (unsigned char *)0x0) {
              ParseOperand___ParseOperand(local_60);
              operator_delete(pPVar12);
            }
            uVar14 = uVar14 + 1;
            if (uVar13 <= uVar14) break;
            iVar3 = *(int *)(iVar15 + 4);
          }
        }
      }
    }
    else if (sVar2 == 0x7fff) {
      iVar9 = 0;
      if (0 < *(short *)(iVar3 + 0x2e)) {
        do {
          pPVar12 = operator_new(0x38);
          ParseOperand__ParseOperand(pPVar12);
          local_5c = pPVar12;
          pPVar7 = operator_new(100);
          ParseSymbol__ParseSymbol(pPVar7);
          ParseSymbol__SetName((char *)pPVar7);
          ParseSymbol__AddDirectIndex((uint)pPVar7);
          _sprintf(acStack_70,DAT_a7b7bd90,iVar9);
          ParseSymbol__CatName((char *)pPVar7);
          ParseSymbol__SetParseTreeType((unsigned char *)pPVar7);
          *(undefined4 *)(pPVar7 + 0x48) = 1;
          ParseSymbol__ResolveOpenGLType();
          *(unsigned char **)local_5c = pPVar7;
          if ((*(short *)(pPVar7 + 0x2c) == 0x7ffe) || (*(short *)(pPVar7 + 0x2c) == 0x7fff)) {
            iVar16 = ((int (*)())TPPStreamCompiler__constructFromOperand)(this,&local_5c,param_2 + iVar15,param_3 - iVar15);
            if (pPVar7 != (unsigned char *)0x0) {
              ParseSymbol___ParseSymbol(pPVar7);
              operator_delete(pPVar7);
            }
            *(undefined4 *)local_5c = 0;
          }
          else {
            ParseSymbolTable__processOperand(*(unsigned char **)(this + 0x68));
            iVar16 = ((int (*)())TPPStreamCompiler__constructFromOperand)(this,&local_5c,param_2 + iVar15,param_3 - iVar15);
          }
          pPVar12 = local_5c;
          iVar16 = iVar15 + iVar16;
          if (local_5c != (unsigned char *)0x0) {
            ParseOperand___ParseOperand(local_5c);
            operator_delete(pPVar12);
          }
          iVar9 = iVar9 + 1;
          iVar15 = iVar16;
        } while (iVar9 < *(short *)(*(int *)*param_1 + 0x2e));
      }
    }
    else {
      if (iVar3 == 0) {
        sVar2 = *(short *)(pPVar12 + 0x18);
      }
      switch(sVar2) {
      case -0x74b0:
      case -0x74af:
      case -0x74ae:
      case -0x74ad:
      case -0x74ac:
      case -0x74ab:
      case -0x74a9:
      case -0x74a8:
      case -0x74a7:
        if ((param_3 == 1) && (iVar16 = ParseOperand__GetLogicalSize(), iVar16 == 1)) {
          iVar16 = ((int (*)())TPPStreamCompiler__constructReplicate)((unsigned char **)this,param_1,(int)param_2);
          return iVar16;
        }
        break;
      case -0x74a6:
      case -0x74a5:
      case -0x74a4:
        if ((param_3 == 1) && (iVar16 = ParseOperand__GetLogicalSize(), iVar16 == 1)) {
          iVar16 = ((int (*)())TPPStreamCompiler__constructDiagonal)((unsigned char **)this,param_1,(int)param_2);
          return iVar16;
        }
      }
      iVar16 = ((int (*)())TPPStreamCompiler__constructElement)(this,param_1,param_2,param_3);
    }
  }
  return iVar16;
}

/* TPPStreamCompiler__construct @ 0x97bc79dc (296 bytes) */
int TPPStreamCompiler__construct(this, param_1, param_2, param_3)
  unsigned char * this;
  unsigned char * param_1;
  unsigned char ** param_2;
  int param_3;
{
  bool bVar1;
  short sVar2;
  short sVar3;
  unsigned char * pPVar4;
  int iVar5;
  int iVar6;
  unsigned char * local_30 [7];
  
  local_30[0] = (unsigned char *)TPPStreamCompiler__newTemporary(this,param_1);
  if (param_3 == 1) {
    if (*(int *)local_30[0] == 0) {
      sVar2 = *(short *)(local_30[0] + 0x18);
    }
    else {
      sVar2 = *(short *)(*(int *)local_30[0] + 0x2c);
    }
    iVar5 = *(int *)*param_2;
    if (iVar5 == 0) {
      sVar3 = *(short *)(*param_2 + 0x18);
    }
    else {
      sVar3 = *(short *)(iVar5 + 0x2c);
    }
    if (sVar2 == sVar3) {
      iVar5 = ParseOperand__GetLogicalSize();
      iVar6 = ParseOperand__GetLogicalSize();
      if (iVar5 == iVar6) {
        iVar6 = 1;
        iVar5 = ParseOperand__IsMatrix();
        if (iVar5 != 0) {
          iVar6 = ParseOperand__GetLogicalSize();
        }
        iVar5 = ParseOperand__IsMatrix();
        if ((iVar5 == 0) || (*(int *)(*param_2 + 0x20) != 0)) {
          bVar1 = iVar6 == 1;
        }
        else {
          iVar5 = ParseOperand__GetLogicalSize();
          bVar1 = iVar6 == iVar5;
        }
        pPVar4 = local_30;
        if (bVar1) {
          if (local_30[0] != (unsigned char *)0x0) {
            ParseOperand___ParseOperand(local_30[0]);
            operator_delete(pPVar4);
          }
          return *param_2;
        }
      }
    }
  }
  ((int (*)())TPPStreamCompiler__constructFromOperand)(this,local_30,param_2,param_3);
  return local_30[0];
}

/* TPPStreamCompiler__FinishScalerSelect @ 0x97bc7b04 (464 bytes) */
int TPPStreamCompiler__FinishScalerSelect(this, param_1)
  unsigned char * this;
  unsigned char ** param_1;
{
  uint uVar1;
  int iVar3;
  unsigned char * pPVar4;
  uint local_70;
  uint local_6c;
  uint local_68;
  undefined4 local_64;
  uint local_60;
  undefined4 local_5c;
  uint local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  uint local_30;
  undefined4 local_2c;
  unsigned char * local_20 [4];
  ushort uVar2;
  
  iVar3 = *(int *)(this + 0x88);
  if (iVar3 != 0) {
    local_20[0] = *(unsigned char **)(iVar3 + 0xc);
    *(undefined4 *)(iVar3 + 0xc) = 0;
    local_40 = *(undefined4 *)(this + 0x90);
    local_3c = 0;
    local_70 = 0x40000000;
    local_6c = 0;
    local_68 = 0;
    local_64 = 0;
    local_60 = 0;
    local_5c = 0;
    local_58 = 0;
    local_54 = 0;
    local_50 = 0;
    local_4c = 0;
    local_48 = 0;
    local_44 = 0;
    IndirectAddressHandler(this,(unsigned char **)(this + 0x88),param_1,local_20);
    local_70 = local_70 & 0xfc03ffff | 0x1b40000;
    ParseOperand__RemoveDirectIndex();
    ((int (*)())TPPStreamCompiler__getOperandAsDestVar)((unsigned char *)&local_30);
    local_68 = local_30;
    local_64 = local_2c;
    ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&local_30);
    local_60 = local_30;
    local_5c = local_2c;
    ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&local_30);
    local_6c = (local_68 >> 0xc & 1) << 0x1c | local_6c & 0xefffffff;
    local_58 = local_30;
    local_54 = local_2c;
    iVar3 = **(int **)(this + 0x88);
    if (iVar3 == 0) {
      uVar2 = *(ushort *)(*(int **)(this + 0x88) + 6);
    }
    else {
      uVar2 = *(ushort *)(iVar3 + 0x2c);
    }
    uVar1 = GetPPStreamTypeForGLType(uVar2);
    local_6c = (uVar1 & 7) << 0x17 | local_6c & 0xfc7fffff;
    iVar3 = ParseOperand__GetLogicalSize();
    local_6c = (iVar3 + -1) * 0x4000000 & 0xc000000U | local_6c & 0xf3f3ffff;
    _PPStreamAddOperation(*(undefined4 *)(this + 0x70),&local_70,0,0);
    pPVar4 = *param_1;
    if (pPVar4 != (unsigned char *)0x0) {
      ParseOperand___ParseOperand(pPVar4);
      operator_delete(pPVar4);
    }
    pPVar4 = local_20;
    if (local_20[0] != (unsigned char *)0x0) {
      ParseOperand___ParseOperand(local_20[0]);
      operator_delete(pPVar4);
    }
    *param_1 = *(unsigned char **)(this + 0x88);
    *(undefined4 *)(this + 0x88) = 0;
  }
  return;
}

/* TPPStreamCompiler__LastOperationIndex @ 0x97bc7cd4 (36 bytes) */
int TPPStreamCompiler__LastOperationIndex(this)
  unsigned char * this;
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(*(int *)(this + 0x70) + 0x20) + 4);
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  return *(uint *)(iVar1 + 0xc) & 0x3ffff;
}

/* TPPStreamCompiler__AddOperation @ 0x97bc7cf8 (100 bytes) */
int TPPStreamCompiler__AddOperation(this, param_1, param_2, param_3, param_4)
  unsigned char * this;
  unsigned char ** param_1;
  unsigned char * param_2;
  char *param_3;
  uint param_4;
{
  _PPStreamAddOperation(*(undefined4 *)(this + 0x70),param_2,param_3,param_4);
  if (param_1 != (unsigned char **)0x0) {
    ((int (*)())TPPStreamCompiler__FinishScalerSelect)(this,param_1);
    return;
  }
  return;
}

/* TPPStreamCompiler__IndirectAddressHandler @ 0x97bc7d5c (952 bytes) */
int TPPStreamCompiler__IndirectAddressHandler(this, param_1, param_2)
  unsigned char * this;
  unsigned char ** param_1;
  int param_2;
{
  bool bVar1;
  unsigned char * pPVar2;
  unsigned char ** ppPVar3;
  unsigned char * pTVar4;
  uint uVar5;
  int iVar6;
  int iVar8;
  int iVar9;
  uint local_a0;
  uint local_9c;
  uint local_98;
  undefined4 local_94;
  uint local_90;
  undefined4 local_8c;
  uint local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  uint local_60;
  undefined4 local_5c;
  unsigned char * local_50;
  unsigned char * local_4c;
  unsigned char * local_48 [5];
  ushort uVar7;
  
  pPVar2 = *param_1;
  if ((pPVar2 != (unsigned char *)0x0) && (*(int *)(pPVar2 + 0xc) != 0)) {
    *(unsigned char **)(this + 0x88) = pPVar2;
    pTVar4 = (unsigned char *)TPPStreamCompiler__newNodeFromOperand(this,*param_1);
    pPVar2 = (unsigned char *)TPPStreamCompiler__newTemporary(this,pTVar4);
    *param_1 = pPVar2;
  }
  iVar9 = 1;
  if (1 < param_2) {
    do {
      pPVar2 = *(unsigned char **)(param_1[iVar9] + 0xc);
      if (pPVar2 != (unsigned char *)0x0) {
        *(undefined4 *)(param_1[iVar9] + 0xc) = 0;
        local_9c = 0;
        local_70 = *(undefined4 *)(this + 0x90);
        local_a0 = 0x40000000;
        local_98 = 0;
        local_94 = 0;
        local_90 = 0;
        local_8c = 0;
        local_88 = 0;
        local_84 = 0;
        local_80 = 0;
        local_7c = 0;
        local_78 = 0;
        local_74 = 0;
        local_6c = 0;
        local_4c = pPVar2;
        pTVar4 = (unsigned char *)TPPStreamCompiler__newNodeFromOperand(this,param_1[iVar9]);
        local_50 = (unsigned char *)TPPStreamCompiler__newTemporary(this,pTVar4);
        IndirectAddressHandler(this,&local_50,param_1 + iVar9,&local_4c);
        local_a0 = local_a0 & 0xfc03ffff | 0xe40000;
        ((int (*)())TPPStreamCompiler__getOperandAsDestVar)((unsigned char *)&local_60);
        local_98 = local_60;
        local_94 = local_5c;
        ParseOperand__RemoveDirectIndex();
        ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&local_60);
        local_90 = local_60;
        local_8c = local_5c;
        ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&local_60);
        local_9c = (local_98 >> 0xc & 1) << 0x1c | local_9c & 0xefffffff;
        local_88 = local_60;
        local_84 = local_5c;
        if (*(int *)local_50 == 0) {
          uVar7 = *(ushort *)(local_50 + 0x18);
        }
        else {
          uVar7 = *(ushort *)(*(int *)local_50 + 0x2c);
        }
        uVar5 = GetPPStreamTypeForGLType(uVar7);
        local_9c = (uVar5 & 7) << 0x17 | local_9c & 0xfc7fffff;
        iVar6 = ParseOperand__GetLogicalSize();
        local_9c = (iVar6 + -1) * 0x4000000 & 0xc000000U | local_9c & 0xf3f3ffff;
        _PPStreamAddOperation(*(undefined4 *)(this + 0x70),&local_a0,0,0);
        iVar6 = 0;
        ppPVar3 = param_1;
        if (0 < param_2) {
          do {
            if ((iVar6 != iVar9) && (param_1[iVar9] == *ppPVar3)) {
              *(unsigned char **)(param_1[iVar9] + 0xc) = local_4c;
              goto LAB_97bc7fe0;
            }
            iVar6 = iVar6 + 1;
            ppPVar3 = ppPVar3 + 1;
          } while (iVar6 < param_2);
        }
        pPVar2 = param_1[iVar9];
        if (pPVar2 != (unsigned char *)0x0) {
          ParseOperand___ParseOperand(pPVar2);
          operator_delete(pPVar2);
        }
        pPVar2 = local_4c;
        if (local_4c != (unsigned char *)0x0) {
          ParseOperand___ParseOperand(local_4c);
          operator_delete(pPVar2);
        }
LAB_97bc7fe0:
        param_1[iVar9] = local_50;
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < param_2);
  }
  ppPVar3 = param_1;
  iVar9 = param_2;
  iVar6 = 0;
  if (0 < param_2) {
    do {
      iVar9 = iVar6;
      if ((*ppPVar3 != (unsigned char *)0x0) && (*(int *)(*ppPVar3 + 8) != 0)) break;
      iVar6 = iVar9 + 1;
      ppPVar3 = ppPVar3 + 1;
      iVar9 = param_2;
    } while (iVar6 < param_2);
  }
  iVar9 = iVar9 + *(int *)(this + 0x9c);
  do {
    if (param_2 <= iVar9) {
      return;
    }
    if (*(int *)(param_1[iVar9] + 8) != 0) {
      pTVar4 = (unsigned char *)TPPStreamCompiler__newNodeFromOperand(this,param_1[iVar9]);
      local_48[0] = (unsigned char *)TPPStreamCompiler__newTemporary(this,pTVar4);
      bVar1 = false;
      ((int (*)())TPPStreamCompiler__assignOperands)(this,local_48,param_1 + iVar9,false);
      iVar8 = 0;
      ppPVar3 = param_1;
      iVar6 = param_2;
      if (param_2 < 1) {
LAB_97bc80d0:
        pPVar2 = param_1[iVar9];
        if (pPVar2 != (unsigned char *)0x0) {
          ParseOperand___ParseOperand(pPVar2);
          operator_delete(pPVar2);
        }
      }
      else {
        do {
          if ((iVar8 != iVar9) && (param_1[iVar9] == *ppPVar3)) {
            bVar1 = true;
          }
          iVar8 = iVar8 + 1;
          iVar6 = iVar6 + -1;
          ppPVar3 = ppPVar3 + 1;
        } while (iVar6 != 0);
        if (!bVar1) goto LAB_97bc80d0;
      }
      param_1[iVar9] = local_48[0];
    }
    iVar9 = iVar9 + 1;
  } while( true );
}

/* TPPStreamCompiler__IndirectAddressHandler_97bc8114 @ 0x97bc8114 (88 bytes) */
int TPPStreamCompiler__IndirectAddressHandler_97bc8114(this, param_1, param_2)
  unsigned char * this;
  unsigned char ** param_1;
  unsigned char ** param_2;
{
  unsigned char * local_20;
  unsigned char * local_1c;
  
  local_20 = *param_1;
  local_1c = *param_2;
  IndirectAddressHandler(this,&local_20,2);
  *param_1 = local_20;
  *param_2 = local_1c;
  return;
}

/* TPPStreamCompiler__IndirectAddressHandler_97bc816c @ 0x97bc816c (108 bytes) */
int TPPStreamCompiler__IndirectAddressHandler_97bc816c(this, param_1, param_2, param_3)
  unsigned char * this;
  unsigned char ** param_1;
  unsigned char ** param_2;
  unsigned char ** param_3;
{
  unsigned char * local_30;
  unsigned char * local_2c;
  unsigned char * local_28;
  
  local_30 = *param_1;
  local_2c = *param_2;
  local_28 = *param_3;
  IndirectAddressHandler(this,&local_30,3);
  *param_1 = local_30;
  *param_2 = local_2c;
  *param_3 = local_28;
  return;
}

/* TPPStreamCompiler__IndirectAddressHandler_97bc81d8 @ 0x97bc81d8 (128 bytes) */
int TPPStreamCompiler__IndirectAddressHandler_97bc81d8(this, param_1, param_2, param_3, param_4)
  unsigned char * this;
  unsigned char ** param_1;
  unsigned char ** param_2;
  unsigned char ** param_3;
  unsigned char ** param_4;
{
  unsigned char * local_30;
  unsigned char * local_2c;
  unsigned char * local_28;
  unsigned char * local_24;
  
  local_30 = *param_1;
  local_2c = *param_2;
  local_28 = *param_3;
  local_24 = *param_4;
  IndirectAddressHandler(this,&local_30,4);
  *param_1 = local_30;
  *param_2 = local_2c;
  *param_3 = local_28;
  *param_4 = local_24;
  return;
}

/* TPPStreamCompiler__IndirectAddressHandler_97bc8258 @ 0x97bc8258 (188 bytes) */
int TPPStreamCompiler__IndirectAddressHandler_97bc8258(this, param_1, param_2, param_3)
  unsigned char * this;
  unsigned char ** param_1;
  unsigned char ** param_2;
  int param_3;
{
  unsigned char ** ppPVar1;
  int iVar2;
  unsigned char ** ppPVar3;
  unsigned char ** ppPVar4;
  unsigned char * apPStack_20 [2];
  
  iVar2 = -(param_3 * 4 + 0x22U & 0xfffffff0);
  *(unsigned char **)(&STACKARG(0xffffffa0) + iVar2) = ((unsigned int)__builtin_frame_address(0));
  ppPVar4 = (unsigned char **)((int)apPStack_20 + iVar2);
  *ppPVar4 = *param_1;
  ppPVar3 = param_2;
  iVar2 = param_3;
  ppPVar1 = ppPVar4;
  if (0 < param_3) {
    do {
      ppPVar1[1] = *ppPVar3;
      iVar2 = iVar2 + -1;
      ppPVar3 = ppPVar3 + 1;
      ppPVar1 = ppPVar1 + 1;
    } while (iVar2 != 0);
  }
  IndirectAddressHandler(this,ppPVar4,param_3 + 1);
  *param_1 = *ppPVar4;
  if (0 < param_3) {
    do {
      ppPVar4 = ppPVar4 + 1;
      *param_2 = *ppPVar4;
      param_2 = param_2 + 1;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}

/* TPPStreamCompiler__getNewConstantSourceVar @ 0x97bc8314 (472 bytes) */
int TPPStreamCompiler__getNewConstantSourceVar(param_1, param_2, param_3)
  unsigned char * param_1;
  uint param_2;
  int param_3;
{
  undefined4 uVar1;
  undefined2 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined1 *puVar6;
  undefined2 in_register_00000014;
  int in_r6;
  ushort in_r7;
  undefined4 *puVar7;
  undefined4 uVar8;
  int iVar9;
  undefined4 local_60 [4];
  undefined4 local_50;
  uint local_4c;
  undefined4 local_40 [5];
  
  iVar9 = *(int *)(*(int *)(param_2 + 0x70) + 0x2c);
  uVar8 = *(undefined4 *)(*(int *)(param_2 + 0x70) + 0x10);
  local_60[0] = 0;
  local_60[1] = 0;
  local_60[2] = 0;
  local_60[3] = 0;
  local_4c = *(uint *)(*(int *)(param_2 + 0x68) + 0x24);
  *(uint *)(*(int *)(param_2 + 0x68) + 0x24) = local_4c + 1;
  local_50 = 0x110000;
  local_4c = local_4c & 0xffff;
  uVar5 = GetPPStreamTypeForGLType(in_r7);
  uVar4 = local_4c;
  uVar3 = (uint)local_50 >> 0x10;
  uVar2 = *(undefined2 *)(iVar9 + 10);
  *(undefined4 *)param_1 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(short *)(param_1 + 6) = (short)local_4c;
  *(uint *)param_1 = (in_r6 + -1) * 0x1000 & 0x3000U | *(uint *)param_1 & 0xf409cfff | 0x10d8000;
  local_50 = CONCAT22((ushort)((uint)((in_r6 + -1) * 0x1000000) >> 0x10) & 0x300 |
                      (ushort)(((uVar5 & 7) << 0x1a) >> 0x10) | (ushort)uVar3 & 0xff,uVar2);
  if (*(int *)(param_2 + 0xc4) == 3) {
    local_40[3] = 0;
    local_40[0] = 0;
    local_40[1] = 0;
    local_40[2] = 0;
    if (in_r6 != 0) {
      puVar7 = local_40;
      iVar9 = 0;
      do {
        uVar1 = *(undefined4 *)(CONCAT22(in_register_00000014,param_3) + iVar9 * 4);
        *puVar7 = 1;
        puVar7 = puVar7 + 1;
        local_60[iVar9] = uVar1;
        in_r6 = in_r6 + -1;
        iVar9 = iVar9 + 1;
      } while (in_r6 != 0);
    }
    ConstantAllocationList__addConstant
              ((unsigned char *)(param_2 + 0x44),uVar4 & 0xffff,(bool *)local_40,in_r7);
  }
  else {
    iVar9 = 0;
    for (; in_r6 != 0; in_r6 = in_r6 + -1) {
      local_60[iVar9] = *(undefined4 *)(CONCAT22(in_register_00000014,param_3) + iVar9 * 4);
      iVar9 = iVar9 + 1;
    }
  }
  _PPStreamAddConstant(*(undefined4 *)(param_2 + 0x70),local_60);
  puVar6 = _calloc(0x1c,1);
  *puVar6 = 3;
  *(undefined4 *)(puVar6 + 0xc) = local_50;
  *(undefined4 *)(puVar6 + 0x14) = 0;
  *(uint *)(puVar6 + 0x10) = local_4c;
  _PPStreamChunkListAddChunk(uVar8,puVar6);
  return param_1;
}

/* TPPStreamCompiler__getConstantAsSourceVar @ 0x97bc84ec (1296 bytes) */
int TPPStreamCompiler__getConstantAsSourceVar(param_1, param_2, param_3)
  unsigned char * param_1;
  uint param_2;
  int param_3;
{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  undefined2 in_register_00000014;
  float *pfVar5;
  uint in_r6;
  uint in_r7;
  undefined4 uVar6;
  int *piVar7;
  int iVar8;
  uint local_80;
  undefined4 local_7c;
  int local_70 [4];
  ushort local_60 [8];
  int local_50 [5];
  
  pfVar5 = (float *)CONCAT22(in_register_00000014,param_3);
  if (*(int *)(param_2 + 0xc4) != 1) {
    bVar1 = false;
    local_70[1] = DAT_97c39254;
    local_70[0] = DAT_97c39250;
    local_70[2] = DAT_97c39258;
    local_70[3] = DAT_97c3925c;
    piVar7 = *(int **)(*(int *)(param_2 + 0x70) + 0x10);
    uVar6 = *(undefined4 *)(*(int *)(param_2 + 0x70) + 0x2c);
    iVar8 = *piVar7;
    *(undefined4 *)param_1 = 0;
    *(undefined4 *)(param_1 + 4) = 0;
    *(uint *)param_1 = (in_r6 - 1) * 0x1000 & 0x3000 | *(uint *)param_1 & 0xfc09cfff | 0x10d8000;
    if (iVar8 != 0) {
      do {
        local_80 = *(uint *)(iVar8 + 0xc);
        local_7c = *(uint *)(iVar8 + 0x10);
        if ((local_80 & 0x1f0000) == 0x110000) {
          iVar4 = _PPStreamChunkListChunkAtIndex(uVar6,local_80 & 0xffff);
          if (*(int *)(param_2 + 0xc4) == 3) {
            ConstantAllocationList__getConstantUsage
                      ((unsigned char *)(param_2 + 0x44),local_7c & 0xffff,(bool *)local_70
                       ,local_60);
          }
          if (local_60[0] == in_r7) {
            if (in_r6 == 2) {
LAB_97bc86b4:
              if ((local_70[1] != 0) && (pfVar5[1] == *(float *)(iVar4 + 0x10))) {
LAB_97bc86d0:
                if ((local_70[0] != 0) && (*pfVar5 == *(float *)(iVar4 + 0xc))) goto LAB_97bc86ec;
              }
            }
            else {
              if (2 < in_r6) {
                if (in_r6 != 3) {
                  if (in_r6 != 4) goto LAB_97bc86ec;
                  if ((local_70[3] == 0) || (pfVar5[3] != *(float *)(iVar4 + 0x18)))
                  goto LAB_97bc86f8;
                }
                if ((local_70[2] == 0) || (pfVar5[2] != *(float *)(iVar4 + 0x14)))
                goto LAB_97bc86f8;
                goto LAB_97bc86b4;
              }
              if (in_r6 == 1) goto LAB_97bc86d0;
LAB_97bc86ec:
              bVar1 = true;
              *(undefined2 *)(param_1 + 6) = (*(unsigned short *)((unsigned char *)&(local_7c) + 2));
            }
          }
        }
LAB_97bc86f8:
        iVar8 = *(int *)(iVar8 + 8);
        if (iVar8 == 0) {
          bVar1 = !bVar1;
          goto LAB_97bc8720;
        }
      } while (!bVar1);
      goto LAB_97bc89bc;
    }
    bVar1 = true;
LAB_97bc8720:
    if (!bVar1) goto LAB_97bc89bc;
    if (*(int *)(param_2 + 0xc4) != 2) {
      iVar8 = *piVar7;
      if (iVar8 != 0) {
        do {
          local_50[0] = 0;
          local_50[1] = 0;
          local_50[2] = 0;
          local_50[3] = 0;
          local_80 = *(uint *)(iVar8 + 0xc);
          local_7c = *(uint *)(iVar8 + 0x10);
          if ((local_80 & 0x1f0000) == 0x110000) {
            iVar4 = _PPStreamChunkListChunkAtIndex(uVar6,local_80 & 0xffff);
            if (*(int *)(param_2 + 0xc4) == 3) {
              ConstantAllocationList__getConstantUsage
                        ((unsigned char *)(param_2 + 0x44),local_7c & 0xffff,
                         (bool *)local_70,local_60);
            }
            if (local_60[0] == in_r7) {
              bVar2 = true;
              if (in_r6 == 2) {
LAB_97bc8838:
                if ((local_70[1] == 1) && (pfVar5[1] == *(float *)(iVar4 + 0x10))) {
                  local_50[1] = local_70[1];
                }
                else if (local_70[1] != 0) {
                  bVar2 = false;
                }
LAB_97bc8868:
                if ((local_70[0] == 1) && (*pfVar5 == *(float *)(iVar4 + 0xc))) {
                  local_50[0] = local_70[0];
                }
                else if (local_70[0] != 0) {
                  bVar2 = false;
                }
                if (!bVar2) goto LAB_97bc897c;
              }
              else {
                if (2 < in_r6) {
                  if (in_r6 != 3) {
                    if (in_r6 != 4) goto LAB_97bc88a0;
                    if ((local_70[3] == 1) && (pfVar5[3] == *(float *)(iVar4 + 0x18))) {
                      local_50[3] = 1;
                    }
                    else if (local_70[3] != 0) {
                      bVar2 = false;
                    }
                  }
                  if ((local_70[2] == 1) && (pfVar5[2] == *(float *)(iVar4 + 0x14))) {
                    local_50[2] = local_70[2];
                  }
                  else if (local_70[2] != 0) {
                    bVar2 = false;
                  }
                  goto LAB_97bc8838;
                }
                if (in_r6 == 1) goto LAB_97bc8868;
              }
LAB_97bc88a0:
              uVar3 = 0;
              if (in_r6 != 0) {
                do {
                  if (local_50[uVar3] == 0) {
                    if (local_70[uVar3] != 0) {
                      bVar2 = false;
                      break;
                    }
                    ((float *)(iVar4 + 0xc))[uVar3] = pfVar5[uVar3];
                    local_50[uVar3] = 1;
                    local_70[uVar3] = 1;
                  }
                  uVar3 = uVar3 + 1;
                } while (uVar3 < in_r6);
              }
              if (in_r6 != 0) {
                piVar7 = local_50;
                uVar3 = in_r6;
                do {
                  iVar4 = *piVar7;
                  piVar7 = piVar7 + 1;
                  if (iVar4 == 0) {
                    bVar2 = false;
                  }
                  uVar3 = uVar3 - 1;
                } while (uVar3 != 0);
              }
              if (bVar2) {
                *(undefined2 *)(param_1 + 6) = (*(unsigned short *)((unsigned char *)&(local_7c) + 2));
                *(uint *)(iVar8 + 0xc) =
                     (local_70[0] + local_70[1] + local_70[2] + local_70[3] + -1) * 0x1000000 &
                     0x3000000U | *(uint *)(iVar8 + 0xc) & 0xfcffffff;
                bVar1 = false;
                ConstantAllocationList__updateConstant
                          ((unsigned char *)(param_2 + 0x44),local_7c & 0xffff,
                           (bool *)local_70,(ushort)in_r7);
              }
            }
          }
LAB_97bc897c:
          iVar8 = *(int *)(iVar8 + 8);
          if (iVar8 == 0) goto LAB_97bc8990;
        } while (bVar1);
        goto LAB_97bc89bc;
      }
LAB_97bc8990:
      if (!bVar1) goto LAB_97bc89bc;
    }
  }
  ((int (*)())TPPStreamCompiler__getNewConstantSourceVar)((unsigned char *)&local_80,param_2,param_3);
  *(uint *)(param_1 + 4) = local_7c;
  *(uint *)param_1 = local_80;
LAB_97bc89bc:
  if (in_r6 == 1) {
    uVar3 = *(uint *)param_1 >> 0x15 & 3;
    *(uint *)param_1 = uVar3 << 0xf | uVar3 << 0x11 | uVar3 << 0x13 | *(uint *)param_1 & 0xffe07fff;
  }
  return param_1;
}

/* TPPStreamCompiler__generateAddressLoad @ 0x97bc89fc (256 bytes) */
int TPPStreamCompiler__generateAddressLoad(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  unsigned char * this_00;
  undefined4 local_70;
  undefined4 local_6c;
  uint local_68;
  uint local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_30;
  undefined4 local_2c;
  
  this_00 = *(unsigned char **)(param_1 + 8);
  if (this_00 != (unsigned char *)0x0) {
    local_6c = 0;
    local_40 = *(undefined4 *)(this + 0x90);
    local_48 = 0;
    local_44 = 0;
    local_68 = 0;
    local_64 = 0;
    local_60 = 0;
    local_5c = 0;
    local_58 = 0;
    local_54 = 0;
    local_50 = 0;
    local_4c = 0;
    local_70 = 0x21200000;
    local_3c = 0;
    ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&local_30);
    local_68 = local_68 & 0xfff1ffff | 0x82000;
    local_60 = local_30;
    local_5c = local_2c;
    local_64 = local_64 & 0xffff0000;
    _PPStreamAddOperation(*(undefined4 *)(this + 0x70),&local_70,0,0);
    ParseOperand___ParseOperand(this_00);
    operator_delete(this_00);
    *(undefined4 *)(param_1 + 8) = 0;
  }
  return this_00 != (unsigned char *)0x0;
}

/* TPPStreamCompiler__getOperandAsDestVar @ 0x97bc8afc (76 bytes) */
#if 0   /* compile-failing as plain C: Ghidra text kept verbatim, see ledger status */
int TPPStreamCompiler__getOperandAsDestVar(param_1)
  unsigned char * param_1;
{
  unsigned char * in_r4;
  unsigned char * in_r5;
  
  ((int (*)())TPPStreamCompiler__generateAddressLoad)(in_r4,in_r5);
  ParseOperand__GetAsDestVar(SUB41(param_1,0));
  return param_1;
}
#endif

/* TPPStreamCompiler__getOperandAsSourceVar @ 0x97bc8b48 (420 bytes) */
#if 0   /* compile-failing as plain C: Ghidra text kept verbatim, see ledger status */
int TPPStreamCompiler__getOperandAsSourceVar(param_1)
  unsigned char * param_1;
{
  bool bVar1;
  ushort uVar2;
  undefined4 *puVar3;
  uint uVar4;
  unsigned char * in_r4;
  unsigned char * in_r5;
  uint uVar5;
  int iVar6;
  undefined4 local_50 [4];
  undefined4 local_40;
  undefined4 local_3c;
  
  if (*(int *)in_r5 == 0) {
    if (*(int *)(in_r5 + 8) != 0) {
      error(SUB41(in_r4,0),(char *)0x1,(char *)0x0,_compileErrorString);
    }
    iVar6 = 4;
    puVar3 = local_50;
    do {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    iVar6 = 0;
    for (uVar5 = 0; uVar4 = ParseOperand__GetLogicalSize(), uVar5 < uVar4; uVar5 = uVar5 + 1) {
      if (uVar5 < 4) {
        if (*(int *)in_r5 == 0) {
          uVar2 = *(ushort *)(in_r5 + 0x18);
        }
        else {
          uVar2 = *(ushort *)(*(int *)in_r5 + 0x2c);
        }
        if (uVar2 == 0x1406) {
          *(undefined4 *)(iVar6 + (int)local_50) = *(undefined4 *)(iVar6 + *(int *)(in_r5 + 4));
        }
        else {
          if (uVar2 < 0x1407) {
            bVar1 = uVar2 == 0x1404;
          }
          else {
            bVar1 = uVar2 == 0x8b56;
          }
          if (bVar1) {
            *(undefined4 *)(iVar6 + (int)local_50) = *(undefined4 *)(iVar6 + *(int *)(in_r5 + 4));
          }
        }
      }
      else {
        error(SUB41(in_r4,0),(char *)0x1,(char *)0x0,DAT_a7b7bd14);
      }
      iVar6 = iVar6 + 4;
    }
    ParseOperand__GetLogicalSize();
    ((int (*)())TPPStreamCompiler__getConstantAsSourceVar)((unsigned char *)&local_40,(uint)in_r4,(short)&STACKARG(0xffffff70) + 0x40);
  }
  else {
    ((int (*)())TPPStreamCompiler__generateAddressLoad)(in_r4,in_r5);
    ParseOperand__GetAsSourceVar((bool)((char)&STACKARG(0xffffff70) + '@'));
    local_40 = local_50[0];
    local_3c = local_50[1];
  }
  *(undefined4 *)param_1 = local_40;
  *(undefined4 *)(param_1 + 4) = local_3c;
  return param_1;
}
#endif

/* TPPStreamCompiler__removeOrphanedCompilerTemp @ 0x97bc8cec (544 bytes) */
int TPPStreamCompiler__removeOrphanedCompilerTemp(this, param_1, param_2)
  unsigned char * this;
  unsigned char * param_1;
  unsigned char * param_2;
{
  byte bVar1;
  ushort uVar2;
  bool bVar3;
  ushort uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  byte *pbVar8;
  unsigned char * this_00;
  byte *pbVar9;
  uint uVar10;
  
  bVar3 = false;
  iVar6 = **(int **)(*(int *)(this + 0x70) + 0x20);
  if (iVar6 != 0) {
    uVar5 = *(uint *)(param_1 + 0x10) >> 0x17 & 7;
    while( true ) {
      uVar10 = *(uint *)(iVar6 + 0xc) >> 0x1d;
      if (uVar10 != 0) {
        iVar7 = iVar6 + 0x10;
        do {
          if (((*(uint *)(iVar7 + 0xc) >> 0x17 & 7) == uVar5) &&
             (*(short *)(iVar7 + 0x12) == *(short *)(param_1 + 0x16))) {
            bVar3 = true;
          }
          iVar7 = iVar7 + 8;
          uVar10 = uVar10 - 1;
        } while (uVar10 != 0);
      }
      if (((*(uint *)(iVar6 + 0x14) >> 0x11 & 7) == uVar5) &&
         (*(short *)(iVar6 + 0x1a) == *(short *)(param_1 + 0x16))) {
        bVar3 = true;
      }
      iVar6 = *(int *)(iVar6 + 8);
      if (iVar6 == 0) break;
      if (bVar3) {
        return;
      }
    }
  }
  if (bVar3) {
    return;
  }
  iVar6 = ParseSymbolTable__RemoveEndSymbol(*(unsigned char **)(this + 0x68));
  if (iVar6 == 0) {
    return;
  }
  this_00 = *(unsigned char **)param_2;
  uVar5 = 3;
  uVar2 = *(ushort *)(this_00 + 0x2c);
  pbVar8 = *(byte **)this_00;
  if (uVar2 != 0x8b5b) {
    if (uVar2 < 0x8b5c) {
      uVar5 = 2;
      uVar4 = 0x8b5a;
    }
    else {
      uVar5 = 4;
      uVar4 = 0x8b5c;
    }
    if (uVar2 != uVar4) {
      uVar5 = 1;
    }
  }
  if (*(int *)(this_00 + 0x3c) != 0) {
    TemporaryAllocator__releaseTemporary
              ((ushort)*(undefined4 *)(this + 0x60),(uint)*(ushort *)(this_00 + 0x2c));
    this_00 = *(unsigned char **)param_2;
  }
  if (this_00 != (unsigned char *)0x0) {
    ParseSymbol___ParseSymbol(this_00);
    operator_delete(this_00);
  }
  *(undefined4 *)param_2 = 0;
  bVar1 = *pbVar8;
  if (bVar1 == 2) {
    iVar6 = *(int *)(*(int *)(this + 0x70) + 0x18);
    goto LAB_97bc8ebc;
  }
  if (bVar1 < 3) {
    if (bVar1 == 0) {
      iVar6 = *(int *)(*(int *)(this + 0x70) + 4);
      goto LAB_97bc8ebc;
    }
  }
  else {
    if (bVar1 == 3) {
      iVar6 = *(int *)(*(int *)(this + 0x70) + 0x10);
      goto LAB_97bc8ebc;
    }
    if (bVar1 == 4) {
      iVar6 = *(int *)(*(int *)(this + 0x70) + 0x1c);
      goto LAB_97bc8ebc;
    }
  }
  iVar6 = 0;
LAB_97bc8ebc:
  if ((iVar6 != 0) && (uVar10 = 0, uVar5 != 0)) {
    do {
      pbVar9 = *(byte **)(pbVar8 + 8);
      if (pbVar8 == (byte *)0x0) {
        return;
      }
      uVar10 = uVar10 + 1;
      _PPStreamChunkListRemoveChunk(iVar6,pbVar8);
      pbVar8 = pbVar9;
    } while (uVar10 < uVar5);
  }
  return;
}

/* TPPStreamCompiler__copyPropagateCompilerTemp @ 0x97bc8f0c (1476 bytes) */
#if 0   /* compile-failing as plain C: Ghidra text kept verbatim, see ledger status */
int TPPStreamCompiler__copyPropagateCompilerTemp(this, param_1, param_2)
  unsigned char * this;
  unsigned char * param_1;
  unsigned char * param_2;
{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  unsigned char * p_Var16;
  undefined4 uVar17;
  uint *puVar18;
  undefined4 uVar19;
  uint uVar20;
  uint uVar21;
  uint local_b0 [4];
  uint local_a0 [8];
  uint local_80 [4];
  uint local_70 [4];
  uint local_60 [4];
  uint local_50 [7];
  
  iVar15 = *(int *)param_2;
  uVar19 = 0;
  bVar10 = false;
  bVar9 = false;
  if ((iVar15 != 0) && ((*(int *)(iVar15 + 0x3c) != 0 || (*(int *)(iVar15 + 0x40) != 0)))) {
    uVar13 = *(uint *)(param_1 + 8);
    local_a0[3] = uVar13 >> 0x10 & 1;
    local_a0[0] = uVar13 >> 0xd & 1;
    local_a0[1] = uVar13 >> 0xe & 1;
    local_a0[2] = uVar13 >> 0xf & 1;
    local_b0[0] = local_a0[0];
    uVar13 = local_a0[0] | local_a0[1] | local_a0[2] | local_a0[3];
    local_b0[1] = local_a0[1];
    local_b0[2] = local_a0[2];
    local_b0[3] = local_a0[3];
    iVar15 = 0;
    for (iVar12 = **(int **)(*(int *)(this + 0x70) + 0x20); iVar12 != 0;
        iVar12 = *(int *)(iVar12 + 8)) {
      iVar15 = iVar12;
    }
    iVar12 = 0;
    for (iVar14 = **(int **)(*(int *)(this + 0x70) + 0x24); iVar14 != 0;
        iVar14 = *(int *)(iVar14 + 8)) {
      iVar12 = iVar14;
    }
    bVar1 = *(int *)(param_1 + 0xc) < 0;
    uVar21 = *(uint *)param_1 >> 0x1d;
    if (uVar21 != 0) {
      p_Var16 = param_1 + 0x10;
      do {
        iVar14 = *(int *)p_Var16;
        p_Var16 = p_Var16 + 8;
        if (iVar14 < 0) {
          bVar1 = true;
        }
        uVar21 = uVar21 - 1;
      } while (uVar21 != 0);
    }
    bVar2 = uVar13 == 0;
    if ((!bVar2) && (iVar15 != 0)) {
      bVar11 = bVar2;
      do {
        if (iVar12 == 0) {
          uVar21 = *(uint *)(iVar15 + 0xc);
LAB_97bc9078:
          if (((uVar21 & 0x3fc0000) == 0x1300000) ||
             ((bVar1 && ((uVar21 & 0x3fc0000) == 0x1200000)))) goto LAB_97bc909c;
          uVar20 = 0;
          if (uVar21 >> 0x1d != 0) {
            iVar14 = iVar15 + 0x10;
            do {
              if (((*(uint *)(iVar14 + 0xc) >> 0x17 & 7) == (*(uint *)(param_1 + 0x10) >> 0x17 & 7))
                 && (*(short *)(iVar14 + 0x12) == *(short *)(param_1 + 0x16))) {
                bVar9 = true;
                break;
              }
              uVar20 = uVar20 + 1;
              iVar14 = iVar14 + 8;
            } while (uVar20 < uVar21 >> 0x1d);
          }
        }
        else {
          uVar21 = *(uint *)(iVar15 + 0xc);
          if (*(uint *)(iVar12 + 0xc) <= (uVar21 & 0x3ffff)) goto LAB_97bc9078;
LAB_97bc909c:
          uVar13 = 0;
          bVar11 = true;
        }
        bVar2 = true;
        if (bVar11) break;
        uVar21 = *(uint *)(param_1 + 0x10);
        if (((((uVar21 & 0x8000000) == 0) &&
             ((*(uint *)(iVar15 + 0x14) >> 0x11 & 7) == (uVar21 >> 0x17 & 7))) &&
            (*(short *)(iVar15 + 0x1a) == *(short *)(param_1 + 0x16))) &&
           ((*(uint *)(iVar15 + 0x14) >> 0xc & 1) == (uVar21 >> 0xe & 1))) {
          bVar2 = false;
          local_a0[4] = DAT_97c39260;
          local_a0[5] = DAT_97c39264;
          local_a0[6] = DAT_97c39268;
          local_a0[7] = DAT_97c3926c;
          local_a0[0] = 0;
          local_a0[1] = 0;
          local_a0[2] = 0;
          local_a0[3] = 0;
          uVar20 = *(uint *)(iVar15 + 0xc) & 0x3fc0000;
          if (((((((uVar20 == 0xb80000) || (uVar20 == 0x1080000)) ||
                 ((uVar20 == 0x10c0000 || ((uVar20 == 0x1100000 || (uVar20 == 0x1140000)))))) ||
                (uVar20 == 0x1180000)) || ((uVar20 == 0x11c0000 || (uVar20 == 0x2c0000)))) &&
              ((*(uint *)(iVar15 + 0x10) >> 0x1a & 3) == (*(uint *)(param_1 + 4) >> 0x1a & 3))) ||
             ((((uVar20 = *(uint *)(iVar15 + 0xc) & 0x3fc0000, uVar20 == 0x9c0000 ||
                (uVar20 == 0xac0000)) || (uVar20 == 0x480000)) ||
              (((uVar20 == 0x200000 || (uVar20 == 0x240000)) ||
               ((*(uint *)(iVar15 + 0x10) >> 0x1a & 3) <= (*(uint *)(param_1 + 4) >> 0x1a & 3)))))))
          {
            uVar20 = *(uint *)(param_1 + 8);
            local_80[0] = *(uint *)(iVar15 + 0x14) >> 8 & 3;
            local_80[1] = *(uint *)(iVar15 + 0x14) >> 6 & 3;
            local_80[2] = *(uint *)(iVar15 + 0x14) >> 4 & 3;
            local_80[3] = *(uint *)(iVar15 + 0x14) >> 2 & 3;
            local_70[0] = *(uint *)(iVar15 + 0x14) >> 0xd & 1;
            local_70[1] = *(uint *)(iVar15 + 0x14) >> 0xe & 1;
            local_70[2] = *(uint *)(iVar15 + 0x14) >> 0xf & 1;
            local_60[2] = uVar21 >> 0x11 & 3;
            local_50[0] = uVar20 >> 8 & 3;
            local_70[3] = *(uint *)(iVar15 + 0x14) >> 0x10 & 1;
            iVar14 = 4;
            local_60[0] = uVar21 >> 0x15 & 3;
            local_60[1] = uVar21 >> 0x13 & 3;
            local_60[3] = uVar21 >> 0xf & 3;
            local_50[1] = uVar20 >> 6 & 3;
            local_50[2] = uVar20 >> 4 & 3;
            local_50[3] = uVar20 >> 2 & 3;
            puVar18 = local_b0;
            do {
              if ((*puVar18 != 0) && (uVar21 = local_60[puVar18[0x18]], local_70[uVar21] != 0)) {
                *puVar18 = 0;
                bVar2 = true;
                uVar21 = local_80[uVar21];
                puVar18[4] = 1;
                uVar13 = (uint)(((local_b0[0] != 0 || local_b0[1] != 0) || local_b0[2] != 0) ||
                               local_b0[3] != 0);
                puVar18[8] = uVar21;
              }
              puVar18 = puVar18 + 1;
              iVar14 = iVar14 + -1;
            } while (iVar14 != 0);
            if (bVar2) {
              uVar17 = *(undefined4 *)(param_1 + 0xc);
              *(uint *)(iVar15 + 0x14) = uVar20;
              bVar10 = true;
              *(undefined4 *)(iVar15 + 0x18) = uVar17;
              uVar21 = (local_a0[0] & 1) << 0xd;
              *(uint *)(iVar15 + 0x14) = uVar21 | uVar20 & 0xffffdfff;
              uVar3 = (local_a0[1] & 1) << 0xe;
              *(uint *)(iVar15 + 0x14) = uVar3 | uVar21 | uVar20 & 0xffff9fff;
              uVar4 = (local_a0[2] & 1) << 0xf;
              *(uint *)(iVar15 + 0x14) = uVar4 | uVar3 | uVar21 | uVar20 & 0xffff1fff;
              uVar5 = (local_a0[3] & 1) << 0x10;
              *(uint *)(iVar15 + 0x14) = uVar5 | uVar4 | uVar3 | uVar21 | uVar20 & 0xfffe1fff;
              uVar6 = (local_a0[4] & 3) << 8;
              *(uint *)(iVar15 + 0x14) =
                   uVar6 | uVar5 | uVar4 | uVar3 | uVar21 | uVar20 & 0xfffe1cff;
              uVar7 = (local_a0[5] & 3) << 6;
              *(uint *)(iVar15 + 0x14) =
                   uVar7 | uVar6 | uVar5 | uVar4 | uVar3 | uVar21 | uVar20 & 0xfffe1c3f;
              uVar8 = (local_a0[6] & 3) << 4;
              *(uint *)(iVar15 + 0x14) =
                   uVar8 | uVar7 | uVar6 | uVar5 | uVar4 | uVar3 | uVar21 | uVar20 & 0xfffe1c0f;
              *(uint *)(iVar15 + 0x14) =
                   (local_a0[7] & 3) << 2 |
                   uVar8 | uVar7 | uVar6 | uVar5 | uVar4 | uVar3 | uVar21 | uVar20 & 0xfffe1c03;
            }
          }
          else {
            uVar13 = 0;
          }
        }
        iVar15 = *(int *)(iVar15 + 4);
        bVar2 = uVar13 == 0;
        if (bVar9) {
          uVar13 = 0;
        }
        bVar2 = bVar9 || bVar2;
        if ((bVar2) || (bVar11 = false, iVar15 == 0)) break;
      } while( true );
    }
    if ((((local_b0[0] != 0 || local_b0[1] != 0) || local_b0[2] != 0) || local_b0[3] != 0) &&
       (bVar10)) {
      ((int (*)())TPPStreamCompiler__warning)(SUB41(this,0),(char *)0x0,(char *)0x0,DAT_a7b7bd40);
    }
    if (bVar2) {
      if (bVar10) {
        uVar19 = 1;
        ((int (*)())TPPStreamCompiler__removeOrphanedCompilerTemp)(this,param_1,param_2);
      }
    }
    else if (bVar10) {
      *(uint *)(param_1 + 8) =
           (local_b0[3] & 1) << 0x10 |
           (local_b0[2] & 1) << 0xf |
           (local_b0[1] & 1) << 0xe | (local_b0[0] & 1) << 0xd | *(uint *)(param_1 + 8) & 0xfffe1fff
      ;
    }
  }
  return uVar19;
}
#endif

/* TPPStreamCompiler__parseIntermediateTree @ 0x97bc94d0 (480 bytes) */
int TPPStreamCompiler__parseIntermediateTree(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  int iVar1;
  unsigned char * pPVar2;
  unsigned char * pTVar3;
  unsigned char * pQVar4;
  unsigned char * pAVar5;
  bool bVar6;
  undefined4 local_30 [7];
  
  bVar6 = false;
  if (param_1 != (unsigned char *)0x0) {
    pTVar3 = *(unsigned char **)(this + 0x60);
    *(undefined4 *)(this + 0xac) = 0;
    *(undefined4 *)(this + 0x8c) = 0;
    *(undefined4 *)(this + 0x94) = 0;
    *(undefined4 *)(this + 0xa0) = 0;
    *(undefined4 *)(this + 0xa8) = 0;
    if (pTVar3 != (unsigned char *)0x0) {
      TemporaryAllocator___TemporaryAllocator(pTVar3);
      operator_delete(pTVar3);
    }
    pTVar3 = operator_new(200);
    TemporaryAllocator__TemporaryAllocator(pTVar3);
    *(unsigned char **)(this + 0x60) = pTVar3;
    *(unsigned char **)PTR_temporaryAllocator_a7b7c0fc = pTVar3;
    pAVar5 = *(unsigned char **)(this + 100);
    if (pAVar5 != (unsigned char *)0x0) {
      AddressTempAllocator___AddressTempAllocator(pAVar5);
      operator_delete(pAVar5);
    }
    pAVar5 = operator_new(8);
    AddressTempAllocator__AddressTempAllocator(pAVar5);
    *(unsigned char **)(this + 100) = pAVar5;
    *(unsigned char **)PTR_addressTempAllocator_a7b7c0f8 = pAVar5;
    pQVar4 = (unsigned char *)(this + 0x4c);
    while( true ) {
      iVar1 = size(pQVar4);
      if (iVar1 == 0) break;
      fetch(pQVar4);
    }
    newQueue(pQVar4);
    *(undefined4 *)(this + 0x98) = 0;
    ConstantAllocationList__clear((unsigned char *)(this + 0x44));
    while (iVar1 = ParseFunctionStack__empty((unsigned char *)(this + 0x58)), iVar1 == 0) {
      ParseFunctionStack__pop((unsigned char *)(this + 0x58));
    }
    if (*(int *)(this + 8) == 0) {
      pPVar2 = (unsigned char *)TPPStreamCompiler__getPosition(this);
      if (pPVar2 != (unsigned char *)0x0) {
        ParseOperand___ParseOperand(pPVar2);
        operator_delete(pPVar2);
      }
    }
    *(undefined4 *)(*(int *)(this + 0x68) + 0x50) = 1;
    (**(code **)(*(int *)param_1 + 0x10))(param_1,this);
    *(undefined4 *)(*(int *)(this + 0x68) + 0x50) = 0;
    if (*(int *)(this + 0xa8) == 1) {
      local_30[0] = 0;
      _PPStreamAddAddressUsage(*(undefined4 *)(this + 0x70),local_30);
    }
    *(undefined4 *)(this + 0x94) = 0;
    *(undefined4 *)(this + 0x8c) = 0;
    pPVar2 = (unsigned char *)(**(code **)(*(int *)param_1 + 0xc))(param_1,this);
    if (pPVar2 != (unsigned char *)0x0) {
      ParseOperand___ParseOperand(pPVar2);
      operator_delete(pPVar2);
    }
    ParseSymbolTable__ClearCompilerTempData();
    bVar6 = *(int *)(this + 0xa0) != 1;
  }
  return bVar6;
}

/* TPPStreamCompiler__TPPStreamCompiler @ 0x97bc96b0 (4 bytes) */
int TPPStreamCompiler__TPPStreamCompiler(this, param_2, param_3)
  unsigned char * this;
  undefined4 param_2;
  undefined4 param_3;
{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  char in_RESERVE;
  byte in_cr0;
  
  *(undefined4 *)(this + 8) = param_2;
  *(undefined ***)this = &PTR__TCompiler_a7b7d850;
  *(unsigned char **)(this + 4) = this + 0xb0;
  *(undefined4 *)(this + 0xc) = 0;
  TPoolAllocator__TPoolAllocator((unsigned char *)(this + 0x10),false,0x2000,0x10);
  *(int *)this = DAT_a7b7bd98 + 8;
  ConstantAllocationList__ConstantAllocationList((unsigned char *)(this + 0x44));
  ParseFunctionStack__ParseFunctionStack((unsigned char *)(this + 0x58));
  ParseWhileLoopStack__ParseWhileLoopStack((unsigned char *)(this + 0x5c));
  puVar2 = PTR__S_empty_rep_storage_a7b7c0f0;
  piVar3 = (int *)(PTR__S_empty_rep_storage_a7b7c0f0 + 8);
  do {
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(*piVar3 + 1,0,piVar3);
      *piVar3 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  *(undefined4 *)(this + 0xb4) = 4;
  *(undefined **)(this + 0xb0) = puVar2 + 0xc;
  do {
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(*piVar3 + 1,0,piVar3);
      *piVar3 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  *(undefined4 *)(this + 0xbc) = 4;
  *(undefined **)(this + 0xb8) = puVar2 + 0xc;
  *(undefined4 *)(this + 0xc0) = param_3;
  newQueue((unsigned char *)(this + 0x4c));
  *(undefined4 *)(this + 0x88) = 0;
  *(undefined4 *)(this + 0x9c) = 1;
  *(undefined4 *)(this + 0x68) = 0;
  *(undefined4 *)(this + 0x6c) = 0;
  *(undefined4 *)(this + 0x74) = 0;
  *(undefined4 *)(this + 0x70) = 0;
  *(undefined4 *)(this + 0x7c) = 0;
  *(undefined4 *)(this + 0x80) = 0;
  *(undefined4 *)(this + 0x78) = 0;
  *(undefined4 *)(this + 0x84) = 0;
  *(undefined4 *)(this + 0x60) = 0;
  *(undefined4 *)(this + 100) = 0;
  return;
}

/* TPPStreamCompiler__TPPStreamCompiler_97bc96b4 @ 0x97bc96b4 (4 bytes) */
int TPPStreamCompiler__TPPStreamCompiler_97bc96b4(this, param_2, param_3)
  unsigned char * this;
  undefined4 param_2;
  undefined4 param_3;
{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  char in_RESERVE;
  byte in_cr0;
  
  *(undefined4 *)(this + 8) = param_2;
  *(undefined ***)this = &PTR__TCompiler_a7b7d850;
  *(unsigned char **)(this + 4) = this + 0xb0;
  *(undefined4 *)(this + 0xc) = 0;
  TPoolAllocator__TPoolAllocator((unsigned char *)(this + 0x10),false,0x2000,0x10);
  *(int *)this = DAT_a7b7bd98 + 8;
  ConstantAllocationList__ConstantAllocationList((unsigned char *)(this + 0x44));
  ParseFunctionStack__ParseFunctionStack((unsigned char *)(this + 0x58));
  ParseWhileLoopStack__ParseWhileLoopStack((unsigned char *)(this + 0x5c));
  puVar2 = PTR__S_empty_rep_storage_a7b7c0f0;
  piVar3 = (int *)(PTR__S_empty_rep_storage_a7b7c0f0 + 8);
  do {
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(*piVar3 + 1,0,piVar3);
      *piVar3 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  *(undefined4 *)(this + 0xb4) = 4;
  *(undefined **)(this + 0xb0) = puVar2 + 0xc;
  do {
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(*piVar3 + 1,0,piVar3);
      *piVar3 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  *(undefined4 *)(this + 0xbc) = 4;
  *(undefined **)(this + 0xb8) = puVar2 + 0xc;
  *(undefined4 *)(this + 0xc0) = param_3;
  newQueue((unsigned char *)(this + 0x4c));
  *(undefined4 *)(this + 0x88) = 0;
  *(undefined4 *)(this + 0x9c) = 1;
  *(undefined4 *)(this + 0x68) = 0;
  *(undefined4 *)(this + 0x6c) = 0;
  *(undefined4 *)(this + 0x74) = 0;
  *(undefined4 *)(this + 0x70) = 0;
  *(undefined4 *)(this + 0x7c) = 0;
  *(undefined4 *)(this + 0x80) = 0;
  *(undefined4 *)(this + 0x78) = 0;
  *(undefined4 *)(this + 0x84) = 0;
  *(undefined4 *)(this + 0x60) = 0;
  *(undefined4 *)(this + 100) = 0;
  return;
}

/* TPPStreamCompiler__TPPStreamCompiler_97bc96b8 @ 0x97bc96b8 (284 bytes) */
int TPPStreamCompiler__TPPStreamCompiler_97bc96b8(this, param_2, param_3)
  unsigned char * this;
  undefined4 param_2;
  undefined4 param_3;
{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  char in_RESERVE;
  byte in_cr0;
  
  *(undefined4 *)(this + 8) = param_2;
  *(undefined ***)this = &PTR__TCompiler_a7b7d850;
  *(unsigned char **)(this + 4) = this + 0xb0;
  *(undefined4 *)(this + 0xc) = 0;
  TPoolAllocator__TPoolAllocator((unsigned char *)(this + 0x10),false,0x2000,0x10);
  *(int *)this = DAT_a7b7bd98 + 8;
  ConstantAllocationList__ConstantAllocationList((unsigned char *)(this + 0x44));
  ParseFunctionStack__ParseFunctionStack((unsigned char *)(this + 0x58));
  ParseWhileLoopStack__ParseWhileLoopStack((unsigned char *)(this + 0x5c));
  puVar2 = PTR__S_empty_rep_storage_a7b7c0f0;
  piVar3 = (int *)(PTR__S_empty_rep_storage_a7b7c0f0 + 8);
  do {
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(*piVar3 + 1,0,piVar3);
      *piVar3 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  *(undefined4 *)(this + 0xb4) = 4;
  *(undefined **)(this + 0xb0) = puVar2 + 0xc;
  do {
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(*piVar3 + 1,0,piVar3);
      *piVar3 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  *(undefined4 *)(this + 0xbc) = 4;
  *(undefined **)(this + 0xb8) = puVar2 + 0xc;
  *(undefined4 *)(this + 0xc0) = param_3;
  newQueue((unsigned char *)(this + 0x4c));
  *(undefined4 *)(this + 0x88) = 0;
  *(undefined4 *)(this + 0x9c) = 1;
  *(undefined4 *)(this + 0x68) = 0;
  *(undefined4 *)(this + 0x6c) = 0;
  *(undefined4 *)(this + 0x74) = 0;
  *(undefined4 *)(this + 0x70) = 0;
  *(undefined4 *)(this + 0x7c) = 0;
  *(undefined4 *)(this + 0x80) = 0;
  *(undefined4 *)(this + 0x78) = 0;
  *(undefined4 *)(this + 0x84) = 0;
  *(undefined4 *)(this + 0x60) = 0;
  *(undefined4 *)(this + 100) = 0;
  return;
}

/* TPPStreamCompiler___TPPStreamCompiler @ 0x97bc97d4 (8 bytes) */
int TPPStreamCompiler___TPPStreamCompiler(this)
  unsigned char * this;
{
  ~TPPStreamCompiler(this);
  return;
}

/* TPPStreamCompiler___TPPStreamCompiler_97bc97dc @ 0x97bc97dc (8 bytes) */
int TPPStreamCompiler___TPPStreamCompiler_97bc97dc(this)
  unsigned char * this;
{
  ~TPPStreamCompiler(this);
  return;
}

/* TPPStreamCompiler___TPPStreamCompiler_97bc97e4 @ 0x97bc97e4 (8 bytes) */
int TPPStreamCompiler___TPPStreamCompiler_97bc97e4(this)
  unsigned char * this;
{
  ~TPPStreamCompiler(this);
  return;
}

/* TPPStreamCompiler___TPPStreamCompiler_97bc97ec @ 0x97bc97ec (536 bytes) */
int TPPStreamCompiler___TPPStreamCompiler_97bc97ec(this)
  unsigned char * this;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint in_r4;
  unsigned char * this_00;
  unsigned char * this_01;
  unsigned char * this_02;
  unsigned char * this_03;
  char in_RESERVE;
  byte in_cr0;
  
  *(int *)this = DAT_a7b7bd98 + 8;
  ConstantAllocationList__clear((unsigned char *)(this + 0x44));
  while( true ) {
    iVar4 = size((unsigned char *)(this + 0x4c));
    if (iVar4 == 0) break;
    fetch((unsigned char *)(this + 0x4c));
  }
  while (iVar4 = ParseFunctionStack__empty((unsigned char *)(this + 0x58)), iVar4 == 0) {
    ParseFunctionStack__pop((unsigned char *)(this + 0x58));
  }
  this_00 = *(unsigned char **)(this + 0x6c);
  if (this_00 != (unsigned char *)0x0) {
    ((int (*)())FunctionTable___FunctionTable)(this_00);
    operator_delete(this_00);
  }
  this_01 = *(unsigned char **)(this + 0x68);
  if (this_01 != (unsigned char *)0x0) {
    ParseSymbolTable___ParseSymbolTable(this_01);
    operator_delete(this_01);
  }
  if (*(int *)(this + 0x70) != 0) {
    _PPStreamFree();
  }
  if (*(void **)(this + 0x78) != (void *)0x0) {
    _free(*(void **)(this + 0x78));
  }
  if (*(void **)(this + 0x7c) != (void *)0x0) {
    _free(*(void **)(this + 0x7c));
  }
  if (*(void **)(this + 0x80) != (void *)0x0) {
    _free(*(void **)(this + 0x80));
  }
  if (*(void **)(this + 0x84) != (void *)0x0) {
    _free(*(void **)(this + 0x84));
  }
  this_02 = *(unsigned char **)(this + 0x60);
  if (this_02 != (unsigned char *)0x0) {
    TemporaryAllocator___TemporaryAllocator(this_02);
    operator_delete(this_02);
  }
  *(undefined4 *)PTR_temporaryAllocator_a7b7c0fc = 0;
  this_03 = *(unsigned char **)(this + 100);
  if (this_03 != (unsigned char *)0x0) {
    AddressTempAllocator___AddressTempAllocator(this_03);
    operator_delete(this_03);
  }
  *(undefined4 *)PTR_addressTempAllocator_a7b7c0f8 = 0;
  if (*(void **)(this + 0x74) != (void *)0x0) {
    _free(*(void **)(this + 0x74));
  }
  iVar4 = *(int *)(this + 0xb8);
  piVar2 = (int *)(iVar4 + -4);
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar3 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(iVar4 + -0xc));
  }
  iVar4 = *(int *)(this + 0xb0);
  piVar2 = (int *)(iVar4 + -4);
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar3 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(iVar4 + -0xc));
  }
  ConstantAllocationList___ConstantAllocationList((unsigned char *)(this + 0x44));
  *(undefined ***)this = &PTR__TCompiler_a7b7d850;
  TPoolAllocator___TPoolAllocator((unsigned char *)(this + 0x10));
  *(undefined ***)this = &PTR__TShHandleBase_a7b7d898;
  if ((in_r4 & 1) != 0) {
    operator_delete(this);
  }
  return;
}

/* TPPStreamCompiler__error @ 0x97bc9a04 (304 bytes) */
#if 0   /* compile-failing as plain C: Ghidra text kept verbatim, see ledger status */
int TPPStreamCompiler__error(int param_1,char *param_2,char *param_3,...)

{
  char *pcVar1;
  char *pcVar2;
  int in_r3;
  size_t sVar3;
  char *pcVar4;
  char *in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 in_r9;
  undefined4 in_r10;
  size_t sVar5;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  char acStack_120 [264];
  
  sVar5 = 0;
  uStack00000028 = in_r7;
  uStack0000002c = in_r8;
  uStack00000030 = in_r9;
  uStack00000034 = in_r10;
  _vsprintf(acStack_120,in_r6,&STACKARG(0x28));
  if (param_3 != (char *)0x0) {
    sVar5 = _strlen(param_3);
  }
  sVar3 = _strlen(acStack_120);
  pcVar4 = _malloc(sVar3 + sVar5 + 0x28);
  pcVar1 = DAT_a7b7bd20;
  pcVar2 = DAT_a7b7bd24;
  if (param_2 != (char *)0x0) {
    pcVar1 = DAT_a7b7bd18;
    pcVar2 = DAT_a7b7bd1c;
  }
  if (param_3 == (char *)0x0) {
    _sprintf(pcVar4,pcVar2,*(undefined4 *)(in_r3 + 0x90),acStack_120);
  }
  else {
    _sprintf(pcVar4,pcVar1,*(undefined4 *)(in_r3 + 0x90),param_3,acStack_120);
  }
  TInfoSinkBase__append((char *)(in_r3 + 0xb0));
  TInfoSinkBase__append((char *)(in_r3 + 0xb0));
  _free(pcVar4);
  *(undefined4 *)(in_r3 + 0xa0) = 1;
  return;
}
#endif

/* TPPStreamCompiler__warning @ 0x97bc9b34 (296 bytes) */
#if 0   /* compile-failing as plain C: Ghidra text kept verbatim, see ledger status */
int TPPStreamCompiler__warning(int param_1,char *param_2,char *param_3,...)

{
  char *pcVar1;
  char *pcVar2;
  int in_r3;
  size_t sVar3;
  char *pcVar4;
  char *in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 in_r9;
  undefined4 in_r10;
  size_t sVar5;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  char acStack_120 [268];
  
  uStack00000028 = in_r7;
  uStack0000002c = in_r8;
  uStack00000030 = in_r9;
  uStack00000034 = in_r10;
  _vsprintf(acStack_120,in_r6,&STACKARG(0x28));
  sVar5 = 0;
  if (param_3 != (char *)0x0) {
    sVar5 = _strlen(param_3);
  }
  sVar3 = _strlen(acStack_120);
  pcVar4 = _malloc(sVar3 + sVar5 + 0x28);
  pcVar1 = DAT_a7b7bd34;
  pcVar2 = DAT_a7b7bd38;
  if (param_2 != (char *)0x0) {
    pcVar1 = DAT_a7b7bd2c;
    pcVar2 = DAT_a7b7bd30;
  }
  if (param_3 == (char *)0x0) {
    _sprintf(pcVar4,pcVar2,*(undefined4 *)(in_r3 + 0x90),acStack_120);
  }
  else {
    _sprintf(pcVar4,pcVar1,*(undefined4 *)(in_r3 + 0x90),param_3,acStack_120);
  }
  TInfoSinkBase__append((char *)(in_r3 + 0xb0));
  TInfoSinkBase__append((char *)(in_r3 + 0xb0));
  _free(pcVar4);
  return;
}
#endif

/* TPPStreamCompiler__getSymbolTableString @ 0x97bc9c5c (196 bytes) */
int TPPStreamCompiler__getSymbolTableString(this, param_1)
  unsigned char * this;
  int param_1;
{
  char *pcVar1;
  size_t sVar2;
  char *pcVar3;
  char *pcVar4;
  
  if (*(int *)(this + 0x68) == 0) {
    return (char *)0x0;
  }
  pcVar1 = (char *)ParseSymbolTable__GetString(*(int *)(this + 0x68));
  sVar2 = _strlen(pcVar1);
  pcVar3 = _malloc(sVar2 + 0x17);
  *pcVar3 = '\0';
  pcVar4 = DAT_a7b7bd64;
  if (param_1 != 1) {
    if (param_1 < 2) {
      pcVar4 = DAT_a7b7bd60;
      if (param_1 != 0) goto LAB_97bc9d00;
    }
    else {
      pcVar4 = DAT_a7b7bd68;
      if (param_1 != 2) goto LAB_97bc9d00;
    }
  }
  _sprintf(pcVar3,pcVar4,pcVar1);
LAB_97bc9d00:
  _free(pcVar1);
  return pcVar3;
}

/* TPPStreamCompiler__dumpSymbolTableInfo @ 0x97bc9d20 (220 bytes) */
int TPPStreamCompiler__dumpSymbolTableInfo(this, param_1)
  unsigned char * this;
  int param_1;
{
  void *pvVar1;
  
  if (param_1 != 1) {
    if (param_1 < 2) {
      if (param_1 != 0) goto LAB_97bc9d98;
    }
    else if (param_1 != 2) goto LAB_97bc9d98;
  }
  TInfoSinkBase__append((char *)(this + 0xb0));
LAB_97bc9d98:
  pvVar1 = (void *)ParseSymbolTable__GetString(*(int *)(this + 0x68));
  if (pvVar1 == (void *)0x0) {
    return;
  }
  TInfoSinkBase__append((char *)(this + 0xb0));
  TInfoSinkBase__append((char *)(this + 0xb0));
  _free(pvVar1);
  return;
}

/* TPPStreamCompiler__reportStats @ 0x97bc9dfc (4 bytes) */
int TPPStreamCompiler__reportStats()
{
  return;
}

/* TPPStreamCompiler__reset @ 0x97bc9e00 (324 bytes) */
int TPPStreamCompiler__reset(this)
  unsigned char * this;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  unsigned char * pPVar4;
  unsigned char * pFVar5;
  
  *(undefined4 *)(this + 0xc) = 0;
  if (*(void **)(this + 0x78) != (void *)0x0) {
    _free(*(void **)(this + 0x78));
  }
  *(undefined4 *)(this + 0x78) = 0;
  if (*(void **)(this + 0x7c) != (void *)0x0) {
    _free(*(void **)(this + 0x7c));
  }
  *(undefined4 *)(this + 0x7c) = 0;
  if (*(void **)(this + 0x80) != (void *)0x0) {
    _free(*(void **)(this + 0x80));
  }
  *(undefined4 *)(this + 0x80) = 0;
  if (*(void **)(this + 0x84) != (void *)0x0) {
    _free(*(void **)(this + 0x84));
  }
  pPVar4 = *(unsigned char **)(this + 0x68);
  *(undefined4 *)(this + 0x84) = 0;
  if (pPVar4 != (unsigned char *)0x0) {
    ParseSymbolTable___ParseSymbolTable(pPVar4);
    operator_delete(pPVar4);
  }
  pPVar4 = operator_new(0x54);
  ParseSymbolTable__ParseSymbolTable(pPVar4,0x80);
  *(unsigned char **)(this + 0x68) = pPVar4;
  *(undefined4 *)(pPVar4 + 0x3c) = *(undefined4 *)(this + 8);
  pFVar5 = *(unsigned char **)(this + 0x6c);
  if (pFVar5 != (unsigned char *)0x0) {
    ((int (*)())FunctionTable___FunctionTable)(pFVar5);
    operator_delete(pFVar5);
  }
  pFVar5 = operator_new(8);
  ((int (*)())FunctionTable__FunctionTable)(pFVar5);
  *(unsigned char **)(this + 0x6c) = pFVar5;
  if (*(int *)(this + 0x70) != 0) {
    _PPStreamFree();
  }
  uVar2 = _PPStreamCreate();
  *(undefined4 *)(this + 0x70) = uVar2;
  *(undefined4 *)(*(int *)(this + 0x68) + 0xc) = uVar2;
  iVar3 = *(int *)(this + 8);
  if (iVar3 == 0) {
    puVar1 = *(undefined4 **)(this + 0x70);
    uVar2 = 0x8b31;
  }
  else {
    if (iVar3 != 1) {
      return;
    }
    puVar1 = *(undefined4 **)(this + 0x70);
    uVar2 = 0x8b30;
  }
  *puVar1 = uVar2;
  *(int *)(this + 0xa4) = iVar3;
  return;
}

/* TPPStreamCompiler__compile @ 0x97bc9f44 (332 bytes) */
int TPPStreamCompiler__compile(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  uint uVar5;
  int local_20 [5];
  
  iVar2 = ((int (*)())TPPStreamCompiler__parseIntermediateTree)(this,param_1);
  *(int *)(this + 0xc) = iVar2;
  if (iVar2 != 0) {
    iVar3 = *(int *)(this + 0x70);
    uVar5 = 0;
    iVar2 = **(int **)(iVar3 + 0x20);
    if (iVar2 != 0) {
      do {
        uVar1 = *(uint *)(iVar2 + 0xc);
        *(uint *)(iVar2 + 0xc) = uVar5 << 0x1a | uVar1 & 0xe3ffffff;
        uVar5 = uVar1 >> 0x1d;
        iVar2 = *(int *)(iVar2 + 8);
      } while (iVar2 != 0);
      iVar3 = *(int *)(this + 0x70);
    }
    _PPStreamResolveBranches(iVar3);
    if (*(void **)(this + 0x74) != (void *)0x0) {
      _free(*(void **)(this + 0x74));
    }
    *(undefined4 *)(this + 0x74) = 0;
    _PPStreamGetStream(*(undefined4 *)(this + 0x70),0,local_20);
    if (local_20[0] != 0) {
      pvVar4 = _malloc(local_20[0] * 8 + 0xfU & 0xfffffff0);
      *(void **)(this + 0x74) = pvVar4;
      _PPStreamGetStream(*(undefined4 *)(this + 0x70),pvVar4,local_20);
    }
  }
  iVar2 = *(int *)(this + 0xc);
  if ((iVar2 != 0) && ((*(uint *)(this + 0xc0) & 0x10) != 0)) {
    ((int (*)())TPPStreamCompiler__dumpSymbolTableInfo)(this,2);
    iVar2 = *(int *)(this + 0xc);
  }
  if ((iVar2 != 0) && ((*(uint *)(this + 0xc0) & 2) != 0)) {
    TInfoSinkBase__append((char *)(this + 0xb0));
    (**(code **)(*(int *)this + 0x28))(this);
    TInfoSinkBase__append((char *)(this + 0xb0));
    iVar2 = *(int *)(this + 0xc);
  }
  return iVar2;
}

/* TPPStreamCompiler__getStatsString @ 0x97bca090 (108 bytes) */
int TPPStreamCompiler__getStatsString(this)
  unsigned char * this;
{
  char *pcVar1;
  int iVar2;
  size_t sVar3;
  char *pcVar4;
  
  pcVar1 = DAT_a7b7bd84;
  iVar2 = *(int *)(this + 0x78);
  if (iVar2 == 0) {
    sVar3 = _strlen(DAT_a7b7bd84);
    pcVar4 = _malloc(sVar3 * 4 + 4);
    *(char **)(this + 0x78) = pcVar4;
    _strcpy(pcVar4,pcVar1);
    iVar2 = *(int *)(this + 0x78);
  }
  return iVar2;
}

/* TPPStreamCompiler__getPPStreamString @ 0x97bca0fc (144 bytes) */
int TPPStreamCompiler__getPPStreamString(this)
  unsigned char * this;
{
  char *pcVar1;
  int iVar2;
  size_t sVar3;
  char *pcVar4;
  
  pcVar1 = DAT_a7b7bd88;
  iVar2 = *(int *)(this + 0x7c);
  if (iVar2 == 0) {
    if ((*(int *)(this + 0xc) == 0) || (*(int *)(this + 0x74) == 0)) {
      sVar3 = _strlen(DAT_a7b7bd88);
      pcVar4 = _malloc(sVar3 * 4 + 4);
      *(char **)(this + 0x7c) = pcVar4;
      _strcpy(pcVar4,pcVar1);
      iVar2 = *(int *)(this + 0x7c);
    }
    else {
      iVar2 = _glpPPDisassemble();
      *(int *)(this + 0x7c) = iVar2;
    }
  }
  return iVar2;
}

/* TPPStreamCompiler__getShaderToProgramString @ 0x97bca18c (148 bytes) */
int TPPStreamCompiler__getShaderToProgramString(this)
  unsigned char * this;
{
  int iVar1;
  size_t sVar2;
  char *pcVar3;
  
  iVar1 = *(int *)(this + 0x80);
  if (iVar1 == 0) {
    if ((*(int *)(this + 0xc) == 0) || (*(int *)(this + 0x74) == 0)) {
      sVar2 = _strlen("No Shader Program generated.");
      pcVar3 = _malloc(sVar2 * 4 + 4);
      *(char **)(this + 0x80) = pcVar3;
      _strcpy(pcVar3,"No Shader Program generated.");
      iVar1 = *(int *)(this + 0x80);
    }
    else {
      iVar1 = _glpPPShaderToProgramString(*(int *)(this + 0x74),0,0);
      *(int *)(this + 0x80) = iVar1;
    }
  }
  return iVar1;
}

/* TPPStreamCompiler__getTableString @ 0x97bca220 (72 bytes) */
int TPPStreamCompiler__getTableString(this)
  unsigned char * this;
{
  int iVar1;
  
  iVar1 = *(int *)(this + 0x84);
  if (iVar1 == 0) {
    iVar1 = ((int (*)())TPPStreamCompiler__getSymbolTableString)(this,2);
    *(int *)(this + 0x84) = iVar1;
  }
  return iVar1;
}

/* ConstructCompiler @ 0x97bca268 (72 bytes) */
int ConstructCompiler(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  unsigned char * pTVar1;
  
  pTVar1 = operator_new(200);
  ((int (*)())TPPStreamCompiler__TPPStreamCompiler)(pTVar1,param_1,param_2);
  return pTVar1;
}

/* DeleteCompiler @ 0x97bca2b0 (24 bytes) */
int DeleteCompiler(param_1)
  unsigned char * param_1;
{
  if (param_1 == (unsigned char *)0x0) {
    return;
  }
                    
                    
  (**(code **)(*(int *)param_1 + 4))();
  return;
}

/* GetBuiltInInitialSwizzle @ 0x97bca2c8 (748 bytes) */
int GetBuiltInInitialSwizzle(param_1)
  unsigned char * param_1;
{
  bool bVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar3 = *(int *)(param_1 + 0x20);
  iVar7 = 0;
  iVar6 = 0;
  if (0 < iVar3) {
    iVar5 = 3;
    do {
      pcVar2 = (char *)(*(int *)(param_1 + 0x14) + iVar6);
      iVar6 = iVar6 + 1;
      iVar4 = *pcVar2 * iVar5;
      iVar5 = iVar5 + 2;
      iVar7 = iVar7 + iVar4;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  if (iVar7 == 0x18ec7) {
    return 3;
  }
  if (iVar7 < 0x18ec8) {
    if (iVar7 == 0x17e27) {
      return 3;
    }
    if (0x17e27 < iVar7) {
      if (iVar7 == 0x17ecc) {
        return 3;
      }
      if (iVar7 < 0x17ecd) {
        if (iVar7 == 0x17e69) {
          return 3;
        }
        if (iVar7 < 0x17e6a) {
          iVar3 = 0x17e48;
        }
        else {
          if (iVar7 == 0x17e8a) {
            return 3;
          }
          iVar3 = 0x17eab;
        }
      }
      else {
        if (iVar7 == 0x18e64) {
          return 3;
        }
        if (iVar7 < 0x18e65) {
          if (iVar7 == 0x17eed) {
            return 3;
          }
          iVar3 = 0x18e43;
        }
        else {
          if (iVar7 == 0x18e85) {
            return 3;
          }
          iVar3 = 0x18ea6;
        }
      }
LAB_97bca478:
      if (iVar7 == iVar3) {
        return 3;
      }
      return 0;
    }
    if (iVar7 == 0x71c3) {
      return 2;
    }
    if (iVar7 < 0x71c4) {
      if (iVar7 == 0x3f94) {
        return 3;
      }
      if (0x3f94 < iVar7) {
        if (iVar7 == 0x42d8) {
          return 1;
        }
        bVar1 = iVar7 == 0x7171;
        goto LAB_97bca520;
      }
      bVar1 = iVar7 == 0x2c25;
      goto LAB_97bca590;
    }
    if (iVar7 == 0x8837) {
      return 2;
    }
    if (0x8837 < iVar7) {
      if (iVar7 == 0x12304) {
        return 3;
      }
      iVar3 = 0x17e06;
      goto LAB_97bca478;
    }
    bVar1 = iVar7 == 0x7a53;
    goto LAB_97bca520;
  }
  if (iVar7 == 0x2043a) {
    return 1;
  }
  if (iVar7 < 0x2043b) {
    if (iVar7 == 0x20374) {
      return 1;
    }
    if (iVar7 < 0x20375) {
      if (iVar7 == 0x18f09) {
        return 3;
      }
      if (iVar7 < 0x18f0a) {
        iVar3 = 0x18ee8;
        goto LAB_97bca478;
      }
      if (iVar7 == 0x18f2a) {
        return 3;
      }
      iVar3 = 0x1f1a8;
    }
    else {
      if (iVar7 == 0x203d7) {
        return 1;
      }
      if (iVar7 < 0x203d8) {
        if (iVar7 == 0x20395) {
          return 1;
        }
        iVar3 = 0x203b6;
      }
      else {
        if (iVar7 == 0x203f8) {
          return 1;
        }
        iVar3 = 0x20419;
      }
    }
LAB_97bca51c:
    bVar1 = iVar7 == iVar3;
LAB_97bca520:
    if (bVar1) {
      return 1;
    }
    return 0;
  }
  if (iVar7 == 0x2614d) {
    return 2;
  }
  if (iVar7 < 0x2614e) {
    if (iVar7 == 0x24cb9) {
      return 2;
    }
    if (iVar7 < 0x24cba) {
      iVar3 = 0x2045b;
      goto LAB_97bca51c;
    }
    if (iVar7 == 0x2610b) {
      return 2;
    }
    iVar3 = 0x2612c;
  }
  else {
    if (iVar7 == 0x261b0) {
      return 2;
    }
    if (iVar7 < 0x261b1) {
      if (iVar7 == 0x2616e) {
        return 2;
      }
      iVar3 = 0x2618f;
    }
    else {
      if (iVar7 == 0x261d1) {
        return 2;
      }
      iVar3 = 0x261f2;
    }
  }
  bVar1 = iVar7 == iVar3;
LAB_97bca590:
  if (bVar1) {
    return 2;
  }
  return 0;
}

/* GetBuiltInChunkForSymbol @ 0x97bca5b4 (8452 bytes) */
int GetBuiltInChunkForSymbol(param_1, param_2)
  unsigned char * param_1;
  int param_2;
{
  bool bVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  undefined1 uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  
  iVar12 = 0;
  iVar3 = *(int *)(param_1 + 0x20);
  iVar11 = 0;
  iVar10 = 0;
  if (0 < iVar3) {
    iVar7 = 3;
    do {
      pcVar2 = (char *)(*(int *)(param_1 + 0x14) + iVar10);
      iVar10 = iVar10 + 1;
      iVar4 = *pcVar2 * iVar7;
      iVar7 = iVar7 + 2;
      iVar11 = iVar11 + iVar4;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  if (iVar11 == 0x10f9c) {
    iVar12 = _PPStreamChunkCreateWithType(3,0);
    uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0fff9 | 0x50009;
    goto LAB_97bcc694;
  }
  if (iVar11 < 0x10f9d) {
    if (iVar11 == 0x81d5) goto LAB_97bcc54c;
    if (iVar11 < 0x81d6) {
      if (iVar11 == 0x5a70) {
LAB_97bcc4ac:
        iVar12 = _PPStreamChunkCreateWithType(3,0);
        iVar3 = 7;
        uVar6 = *(uint *)(iVar12 + 0xc);
LAB_97bcc53c:
        uVar6 = iVar3 << 0x10 | uVar6 & 0xffe0ff3f | 0x20;
LAB_97bcbb78:
        *(uint *)(iVar12 + 0xc) = uVar6;
        uVar6 = ParseSymbol__GetDirectIndex((uint)param_1);
        uVar6 = uVar6 & 0x1f | *(uint *)(iVar12 + 0xc) & 0xffffffe0;
      }
      else if (iVar11 < 0x5a71) {
        if (iVar11 == 0x504e) {
          iVar12 = _PPStreamChunkCreateWithType(4,0);
          iVar3 = 9;
          uVar6 = *(uint *)(iVar12 + 0xc);
        }
        else {
          if (iVar11 < 0x504f) {
            if (iVar11 == 0x4209) {
LAB_97bcc5e0:
              uVar8 = 2;
LAB_97bcc64c:
              iVar12 = _PPStreamChunkCreateWithType(uVar8,0);
              iVar3 = 1;
            }
            else if (iVar11 < 0x420a) {
              if (iVar11 != 0x383f) {
                if (iVar11 < 0x3840) {
                  if (iVar11 == 0x280f) {
                    uVar8 = 2;
LAB_97bcc5ec:
                    iVar12 = _PPStreamChunkCreateWithType(uVar8,0);
                    iVar3 = 4;
                    goto LAB_97bcc658;
                  }
                  if (iVar11 < 0x2810) {
                    if (iVar11 != 0x2099) goto LAB_97bcc698;
                    uVar8 = 2;
                    goto LAB_97bcbba8;
                  }
                  if (iVar11 == 0x297a) goto LAB_97bcc5e0;
                  if (iVar11 != 0x2c25) goto LAB_97bcc698;
                }
                else if (iVar11 != 0x3f94) {
                  if (iVar11 < 0x3f95) {
                    if (iVar11 != 0x3bf9) goto LAB_97bcc698;
                    uVar8 = 4;
                    goto LAB_97bcc64c;
                  }
                  if (iVar11 == 0x41d9) {
                    iVar12 = _PPStreamChunkCreateWithType(3,0);
                    iVar3 = 0xb;
                    goto LAB_97bcc5c0;
                  }
                  if (iVar11 != 0x4203) goto LAB_97bcc698;
                  iVar12 = _PPStreamChunkCreateWithType(4,0);
                  iVar3 = 7;
                  goto LAB_97bcc658;
                }
LAB_97bcc5b0:
                iVar12 = _PPStreamChunkCreateWithType(3,0);
                iVar3 = 0xc;
                goto LAB_97bcc5c0;
              }
LAB_97bcbce8:
              iVar12 = _PPStreamChunkCreateWithType(2,0);
              iVar3 = 5;
            }
            else {
              if (iVar11 == 0x4dd3) goto LAB_97bcc034;
              if (0x4dd3 < iVar11) {
                if (iVar11 != 0x4ee0) {
                  if (iVar11 < 0x4ee1) {
                    if ((iVar11 != 0x4eaa) && (iVar11 != 0x4ec5)) goto LAB_97bcc698;
                  }
                  else if (iVar11 != 0x4efb) {
                    if (iVar11 != 0x4fb4) goto LAB_97bcc698;
                    iVar12 = _PPStreamChunkCreateWithType(4,0);
                    iVar3 = 4;
                    uVar6 = *(uint *)(iVar12 + 0xc);
LAB_97bcbb08:
                    uVar6 = iVar3 << 0x10 | uVar6 & 0xfff0fffe;
                    goto LAB_97bcc694;
                  }
                }
                iVar12 = _PPStreamChunkCreateWithType(4,0);
                *(uint *)(iVar12 + 0xc) = *(uint *)(iVar12 + 0xc) & 0xfff0ffff | 0x40000;
                uVar6 = ParseSymbol__GetDirectIndex((uint)param_1);
                uVar6 = (uVar6 & 7) << 1 | *(uint *)(iVar12 + 0xc) & 0xfffffff1;
                goto LAB_97bcc694;
              }
              if (iVar11 == 0x42d8) goto LAB_97bcc5b0;
              if (iVar11 < 0x42d9) {
                if (iVar11 != 0x425a) goto LAB_97bcc698;
                iVar12 = _PPStreamChunkCreateWithType(4,0);
                iVar3 = 4;
                uVar6 = *(uint *)(iVar12 + 0xc);
                goto LAB_97bcbb2c;
              }
              if (iVar11 == 0x42e3) {
                uVar8 = 4;
                goto LAB_97bcc5ec;
              }
              if (iVar11 != 0x4493) goto LAB_97bcc698;
              uVar8 = 4;
LAB_97bcc668:
              iVar12 = _PPStreamChunkCreateWithType(uVar8,0);
              iVar3 = 3;
            }
          }
          else {
            if (iVar11 != 0x58a1) {
              if (0x58a1 < iVar11) {
                if (iVar11 != 0x5a3e) {
                  if (iVar11 < 0x5a3f) {
                    if (iVar11 != 0x5a21) {
                      if (iVar11 < 0x5a22) {
                        bVar1 = iVar11 == 0x5a08;
LAB_97bca874:
                        if (!bVar1) goto LAB_97bcc698;
                      }
                      else if (iVar11 != 0x5a25) {
                        bVar1 = iVar11 == 0x5a3a;
                        goto LAB_97bca888;
                      }
                      goto LAB_97bcc4e4;
                    }
                  }
                  else {
                    if (iVar11 == 0x5a57) goto LAB_97bcc490;
                    if (iVar11 < 0x5a58) {
                      if (iVar11 != 0x5a42) {
                        bVar1 = iVar11 == 0x5a53;
                        goto LAB_97bca8e4;
                      }
                      goto LAB_97bcc4e4;
                    }
                    if (iVar11 != 0x5a5b) {
                      bVar1 = iVar11 == 0x5a5f;
                      goto LAB_97bca874;
                    }
                  }
                }
                goto LAB_97bcc4c8;
              }
              if (iVar11 != 0x5214) {
                if (iVar11 < 0x5215) {
                  if (iVar11 != 0x51c3) {
                    if (iVar11 < 0x51c4) {
                      bVar1 = iVar11 == 0x51a8;
                    }
                    else {
                      if (iVar11 == 0x51de) goto LAB_97bcbb38;
                      bVar1 = iVar11 == 0x51f9;
                    }
LAB_97bca770:
                    if (!bVar1) goto LAB_97bcc698;
                  }
                }
                else if (iVar11 != 0x524a) {
                  if (iVar11 < 0x524b) {
                    bVar1 = iVar11 == 0x522f;
                    goto LAB_97bca770;
                  }
                  if (iVar11 != 0x5265) {
                    if (iVar11 != 0x5811) goto LAB_97bcc698;
                    iVar12 = _PPStreamChunkCreateWithType(3,0);
                    iVar3 = 0x12;
                    goto LAB_97bcc5c0;
                  }
                }
              }
LAB_97bcbb38:
              if (param_2 == 0) {
                iVar12 = _PPStreamChunkCreateWithType(4,0);
                iVar3 = 6;
                uVar6 = *(uint *)(iVar12 + 0xc);
              }
              else {
                iVar12 = _PPStreamChunkCreateWithType(2,0);
                iVar3 = 7;
                uVar6 = *(uint *)(iVar12 + 0xc);
              }
              uVar6 = iVar3 << 0x10 | uVar6 & 0xfff0ffff;
              goto LAB_97bcbb78;
            }
            iVar12 = _PPStreamChunkCreateWithType(2,0);
            iVar3 = 0xb;
          }
LAB_97bcc658:
          uVar6 = *(uint *)(iVar12 + 0xc);
        }
        uVar6 = iVar3 << 0x10 | uVar6 & 0xfff0ffff;
      }
      else {
        if (iVar11 == 0x5b05) goto LAB_97bcc490;
        if (iVar11 < 0x5b06) {
          if (iVar11 != 0x5ab2) {
            if (iVar11 < 0x5ab3) {
              if (iVar11 == 0x5a91) {
LAB_97bcc490:
                iVar12 = _PPStreamChunkCreateWithType(3,0);
                iVar3 = 7;
                uVar6 = *(uint *)(iVar12 + 0xc);
LAB_97bcc518:
                uVar6 = iVar3 << 0x10 | uVar6 & 0xffe0ff1f;
                goto LAB_97bcbb78;
              }
              if (iVar11 < 0x5a92) {
                if (iVar11 != 0x5a78) {
                  if (0x5a78 < iVar11) {
                    if (iVar11 != 0x5a7c) {
                      bVar1 = iVar11 == 0x5a8d;
                      goto LAB_97bca8e4;
                    }
                    goto LAB_97bcc4e4;
                  }
                  bVar1 = iVar11 == 0x5a74;
LAB_97bca888:
                  if (!bVar1) goto LAB_97bcc698;
                  goto LAB_97bcc490;
                }
              }
              else {
                if (iVar11 == 0x5a99) {
LAB_97bcc4e4:
                  iVar12 = _PPStreamChunkCreateWithType(3,0);
                  iVar3 = 7;
                  uVar6 = *(uint *)(iVar12 + 0xc);
                  goto LAB_97bcc58c;
                }
                if (0x5a99 < iVar11) {
                  if (iVar11 == 0x5aaa) goto LAB_97bcc4ac;
                  bVar1 = iVar11 == 0x5aae;
                  goto LAB_97bca888;
                }
                if (iVar11 != 0x5a95) goto LAB_97bcc698;
              }
            }
            else if (iVar11 != 0x5acf) {
              if (iVar11 < 0x5ad0) {
                if (iVar11 == 0x5ac2) goto LAB_97bcc5b0;
                if (iVar11 < 0x5ac3) {
                  bVar1 = iVar11 == 0x5ab6;
                  goto LAB_97bca874;
                }
                if (iVar11 == 0x5ac7) goto LAB_97bcc4ac;
                bVar1 = iVar11 == 0x5acb;
                goto LAB_97bca888;
              }
              if (iVar11 != 0x5ae8) {
                if (iVar11 < 0x5ae9) {
                  if (iVar11 == 0x5ad3) goto LAB_97bcc4e4;
                  bVar1 = iVar11 == 0x5ae4;
                }
                else {
                  if (iVar11 == 0x5aec) goto LAB_97bcc4c8;
                  bVar1 = iVar11 == 0x5b01;
                }
LAB_97bca8e4:
                if (!bVar1) goto LAB_97bcc698;
                goto LAB_97bcc4ac;
              }
              goto LAB_97bcc490;
            }
          }
LAB_97bcc4c8:
          iVar12 = _PPStreamChunkCreateWithType(3,0);
          iVar3 = 7;
          uVar6 = *(uint *)(iVar12 + 0xc);
          goto LAB_97bcc564;
        }
        if (iVar11 != 0x71c3) {
          if (0x71c3 < iVar11) {
            if (iVar11 == 0x7ab2) {
              iVar12 = _PPStreamChunkCreateWithType(2,0);
              uVar6 = *(uint *)(iVar12 + 0xc) & 0xfff0ffe3 | 0x70000;
              goto LAB_97bcc190;
            }
            if (iVar11 < 0x7ab3) {
              if (iVar11 == 0x7a53) goto LAB_97bcbff4;
              if (iVar11 < 0x7a54) {
                if (iVar11 != 0x7a49) goto LAB_97bcc698;
                iVar12 = _PPStreamChunkCreateWithType(2,0);
                uVar6 = *(uint *)(iVar12 + 0xc) & 0xfff0ffe0 | 0x70000;
                goto LAB_97bcc694;
              }
              if (iVar11 == 0x7a6c) {
                iVar12 = _PPStreamChunkCreateWithType(2,0);
                uVar6 = *(uint *)(iVar12 + 0xc) & 0xfff0ffe1 | 0x70000;
                goto LAB_97bcbb30;
              }
              if (iVar11 != 0x7a8f) goto LAB_97bcc698;
              iVar12 = _PPStreamChunkCreateWithType(2,0);
              uVar5 = *(uint *)(iVar12 + 0xc) & 0xfff0ffff | 0x70000;
              uVar6 = 2;
            }
            else if (iVar11 == 0x7b1b) {
              iVar12 = _PPStreamChunkCreateWithType(2,0);
              uVar5 = *(uint *)(iVar12 + 0xc) & 0xfff0ffff | 0x70000;
              uVar6 = 6;
            }
            else if (iVar11 < 0x7b1c) {
              if (iVar11 == 0x7ad5) {
                iVar12 = _PPStreamChunkCreateWithType(2,0);
                uVar5 = *(uint *)(iVar12 + 0xc) & 0xfff0ffff | 0x70000;
                uVar6 = 4;
              }
              else {
                if (iVar11 != 0x7af8) goto LAB_97bcc698;
                iVar12 = _PPStreamChunkCreateWithType(2,0);
                uVar5 = *(uint *)(iVar12 + 0xc) & 0xfff0ffff | 0x70000;
                uVar6 = 5;
              }
            }
            else {
              if (iVar11 != 0x7b3e) {
                iVar3 = 0x81b6;
                goto LAB_97bcab00;
              }
              iVar12 = _PPStreamChunkCreateWithType(2,0);
              uVar6 = 7;
              uVar5 = *(uint *)(iVar12 + 0xc) & 0xfff0ffff | 0x70000;
            }
            uVar6 = uVar6 | uVar5 & 0xffffffe0;
            goto LAB_97bcc694;
          }
          if (iVar11 != 0x5c79) {
            if (iVar11 < 0x5c7a) {
              if (iVar11 != 0x5c22) {
                if (iVar11 < 0x5c23) {
                  bVar1 = iVar11 == 0x5b1e;
                  goto LAB_97bca8e4;
                }
                if (iVar11 != 0x5c3f) {
                  bVar1 = iVar11 == 0x5c5c;
LAB_97bca914:
                  if (!bVar1) goto LAB_97bcc698;
                }
              }
            }
            else {
              if (iVar11 == 0x6349) {
                uVar8 = 4;
                if (param_2 != 0) goto LAB_97bcbce8;
LAB_97bcbba8:
                iVar12 = _PPStreamChunkCreateWithType(uVar8,0);
                iVar3 = 2;
                goto LAB_97bcc658;
              }
              if (0x6349 < iVar11) {
                if (iVar11 != 0x68de) {
                  bVar1 = iVar11 == 0x7171;
                  goto LAB_97bcb178;
                }
                iVar12 = _PPStreamChunkCreateWithType(3,0);
                uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe08fff | 0x108000;
                iVar3 = 3;
                goto LAB_97bcbe2c;
              }
              if (iVar11 != 0x5c96) {
                bVar1 = iVar11 == 0x5cb3;
                goto LAB_97bca914;
              }
            }
          }
          iVar12 = _PPStreamChunkCreateWithType(3,0);
          uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0ffff | 0xa0000;
          goto LAB_97bcc458;
        }
LAB_97bcc034:
        iVar12 = _PPStreamChunkCreateWithType(3,0);
        iVar3 = 0xd;
LAB_97bcc5c0:
        uVar6 = *(uint *)(iVar12 + 0xc);
LAB_97bcc00c:
        uVar6 = iVar3 << 0x10 | uVar6 & 0xffe0ffff;
      }
    }
    else if (iVar11 == 0xa562) {
      iVar12 = _PPStreamChunkCreateWithType(3,0);
      uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe008ff | 0x104100;
    }
    else {
      if (iVar11 < 0xa563) {
        if (iVar11 == 0x829f) {
LAB_97bcc524:
          iVar12 = _PPStreamChunkCreateWithType(3,0);
          iVar3 = 8;
          uVar6 = *(uint *)(iVar12 + 0xc);
          goto LAB_97bcc53c;
        }
        if (iVar11 < 0x82a0) {
          if (iVar11 != 0x823a) {
            if (0x823a < iVar11) {
              if (iVar11 != 0x8261) {
                if (iVar11 < 0x8262) {
                  if (iVar11 != 0x8242) {
                    if (0x8242 < iVar11) {
                      if (iVar11 != 0x8259) {
                        iVar3 = 0x825d;
                        goto LAB_97bcab50;
                      }
                      goto LAB_97bcc524;
                    }
                    if (iVar11 != 0x823e) goto LAB_97bcc698;
                    goto LAB_97bcc54c;
                  }
                }
                else {
                  if (iVar11 == 0x8280) goto LAB_97bcc500;
                  if (0x8280 < iVar11) {
                    if (iVar11 != 0x8284) {
                      iVar3 = 0x8288;
                      goto LAB_97bcab00;
                    }
                    goto LAB_97bcc54c;
                  }
                  if (iVar11 != 0x8265) {
                    iVar3 = 0x827c;
                    goto LAB_97bcaba4;
                  }
                }
LAB_97bcc574:
                iVar12 = _PPStreamChunkCreateWithType(3,0);
                iVar3 = 8;
                uVar6 = *(uint *)(iVar12 + 0xc);
LAB_97bcc58c:
                uVar6 = iVar3 << 0x10 | uVar6 & 0xffe0ff7f | 0x60;
                goto LAB_97bcbb78;
              }
              goto LAB_97bcc54c;
            }
            if (iVar11 == 0x8213) goto LAB_97bcc524;
            if (iVar11 < 0x8214) {
              if (iVar11 != 0x81f4) {
                if (iVar11 < 0x81f5) {
                  iVar3 = 0x81d9;
                }
                else {
                  if (iVar11 == 0x81f8) goto LAB_97bcc54c;
                  iVar3 = 0x81fc;
                }
LAB_97bcab00:
                if (iVar11 != iVar3) goto LAB_97bcc698;
                goto LAB_97bcc574;
              }
            }
            else {
              if (iVar11 == 0x821b) goto LAB_97bcc54c;
              if (0x821b < iVar11) {
                if (iVar11 != 0x821f) {
                  iVar3 = 0x8236;
                  goto LAB_97bcaba4;
                }
                goto LAB_97bcc574;
              }
              iVar3 = 0x8217;
LAB_97bcab50:
              if (iVar11 != iVar3) goto LAB_97bcc698;
            }
          }
          goto LAB_97bcc500;
        }
        if (iVar11 == 0x8837) {
LAB_97bcbff4:
          iVar12 = _PPStreamChunkCreateWithType(3,0);
          iVar3 = 0xf;
          uVar6 = *(uint *)(iVar12 + 0xc);
          goto LAB_97bcc00c;
        }
        if (0x8837 < iVar11) {
          if (iVar11 != 0x9a2c) {
            if (iVar11 < 0x9a2d) {
              if (iVar11 == 0x92cd) {
                iVar12 = _PPStreamChunkCreateWithType(3,0);
                uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe07fff | 0x104000;
LAB_97bcbdf0:
                uVar6 = uVar6 & 0xffffcfff;
                goto LAB_97bcbdf4;
              }
              if (iVar11 < 0x92ce) {
                if (iVar11 != 0x89f6) goto LAB_97bcc698;
                goto LAB_97bcbff4;
              }
              if (iVar11 != 0x99e2) {
                iVar3 = 0x9a07;
                goto LAB_97bcac74;
              }
            }
            else if (iVar11 != 0x9a9b) {
              if (iVar11 < 0x9a9c) {
                if (iVar11 != 0x9a51) {
                  iVar3 = 0x9a76;
LAB_97bcac74:
                  if (iVar11 != iVar3) goto LAB_97bcc698;
                }
              }
              else if (iVar11 != 0x9ac0) {
                iVar3 = 0x9ae5;
                goto LAB_97bcac74;
              }
            }
          }
          iVar12 = _PPStreamChunkCreateWithType(3,0);
          uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe07fff | 0x104000;
LAB_97bcbe80:
          uVar6 = uVar6 & 0xffffcfff;
          goto LAB_97bcbe84;
        }
        if (iVar11 == 0x82c6) {
LAB_97bcc500:
          iVar12 = _PPStreamChunkCreateWithType(3,0);
          iVar3 = 8;
          uVar6 = *(uint *)(iVar12 + 0xc);
          goto LAB_97bcc518;
        }
        if (iVar11 < 0x82c7) {
          if (iVar11 != 0x82a7) {
            if (iVar11 < 0x82a8) {
              iVar3 = 0x82a3;
              goto LAB_97bcab50;
            }
            if (iVar11 == 0x82ab) goto LAB_97bcc574;
            iVar3 = 0x82c2;
LAB_97bcaba4:
            if (iVar11 != iVar3) goto LAB_97bcc698;
            goto LAB_97bcc524;
          }
        }
        else {
          if (iVar11 == 0x82e9) goto LAB_97bcc500;
          if (0x82e9 < iVar11) {
            if (iVar11 != 0x8308) {
              if (iVar11 != 0x840f) goto LAB_97bcc698;
              uVar8 = 2;
              goto LAB_97bcc668;
            }
            goto LAB_97bcc524;
          }
          if (iVar11 != 0x82ca) {
            iVar3 = 0x82e5;
            goto LAB_97bcaba4;
          }
        }
LAB_97bcc54c:
        iVar12 = _PPStreamChunkCreateWithType(3,0);
        iVar3 = 8;
        uVar6 = *(uint *)(iVar12 + 0xc);
LAB_97bcc564:
        uVar6 = iVar3 << 0x10 | uVar6 & 0xffe0ff1f | 0x40;
        goto LAB_97bcbb78;
      }
      if (iVar11 != 0xe1f0) {
        if (0xe1f0 < iVar11) {
          if (iVar11 != 0x1021f) {
            if (0x1021f < iVar11) {
              if (iVar11 != 0x1029a) {
                if (iVar11 < 0x1029b) {
                  if (iVar11 == 0x10240) goto LAB_97bcc1e8;
                  if (iVar11 < 0x10241) {
                    iVar3 = 0x10237;
                  }
                  else {
                    if (iVar11 == 0x10258) goto LAB_97bcc20c;
                    iVar3 = 0x10279;
                  }
LAB_97bcaf2c:
                  if (iVar11 != iVar3) goto LAB_97bcc698;
                }
                else if (iVar11 != 0x102fd) {
                  if (iVar11 < 0x102fe) {
                    if (iVar11 != 0x102bb) {
                      iVar3 = 0x102dc;
                      goto LAB_97bcaf2c;
                    }
                  }
                  else if (iVar11 != 0x1031e) {
                    if (iVar11 != 0x10f0d) goto LAB_97bcc698;
                    iVar12 = _PPStreamChunkCreateWithType(3,0);
                    uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0fffe | 0x50000;
                    goto LAB_97bcc1b8;
                  }
                }
              }
LAB_97bcc20c:
              iVar12 = _PPStreamChunkCreateWithType(3,0);
              uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0f1ff | 0x30100;
              goto LAB_97bcc458;
            }
            if (iVar11 != 0x10159) {
              if (iVar11 < 0x1015a) {
                if (iVar11 == 0xf7d2) {
                  iVar12 = _PPStreamChunkCreateWithType(3,0);
                  uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0fffe | 0x50000;
                  iVar3 = 1;
                  goto LAB_97bcc0cc;
                }
                if (iVar11 < 0xf7d3) {
                  if (iVar11 != 0xf700) goto LAB_97bcc698;
                  iVar12 = _PPStreamChunkCreateWithType(3,0);
                  uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0fff0 | 0x50000;
                }
                else {
                  if (iVar11 == 0xf839) {
                    iVar12 = _PPStreamChunkCreateWithType(3,0);
                    uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0ffff | 0x50001;
LAB_97bcc1b8:
                    iVar3 = 2;
                    goto LAB_97bcc0cc;
                  }
                  if (iVar11 != 0xf9fd) goto LAB_97bcc698;
                  iVar12 = _PPStreamChunkCreateWithType(3,0);
                  uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0fff7 | 0x50007;
                }
                goto LAB_97bcc694;
              }
              if (iVar11 != 0x101bc) {
                if (iVar11 < 0x101bd) {
                  if (iVar11 != 0x1017a) {
                    iVar3 = 0x1019b;
LAB_97bcaea4:
                    if (iVar11 != iVar3) goto LAB_97bcc698;
                  }
                }
                else if (iVar11 != 0x101dd) {
                  iVar3 = 0x101fe;
                  goto LAB_97bcaea4;
                }
              }
            }
          }
LAB_97bcc1e8:
          iVar12 = _PPStreamChunkCreateWithType(3,0);
          uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0f0ff | 0x30000;
          goto LAB_97bcc458;
        }
        if (iVar11 != 0xb938) {
          if (iVar11 < 0xb939) {
            if (iVar11 != 0xb86b) {
              if (iVar11 < 0xb86c) {
                if (iVar11 != 0xb7f0) {
                  if (iVar11 < 0xb7f1) {
                    iVar3 = 0xb7c7;
                  }
                  else {
                    if (iVar11 == 0xb819) goto LAB_97bcc470;
                    iVar3 = 0xb842;
                  }
LAB_97bcadb8:
                  if (iVar11 != iVar3) goto LAB_97bcc698;
                }
              }
              else if (iVar11 != 0xb8bd) {
                if (iVar11 < 0xb8be) {
                  iVar3 = 0xb894;
                }
                else {
                  if (iVar11 == 0xb8e6) goto LAB_97bcc470;
                  iVar3 = 0xb90f;
                }
                goto LAB_97bcadb8;
              }
            }
          }
          else if (iVar11 != 0xc13b) {
            if (0xc13b < iVar11) {
              if (iVar11 == 0xc310) {
                iVar12 = _PPStreamChunkCreateWithType(4,0);
                iVar3 = 5;
                uVar6 = *(uint *)(iVar12 + 0xc);
LAB_97bcbb2c:
                uVar6 = iVar3 << 0x10 | uVar6 & 0xfff0ffff;
LAB_97bcbb30:
                uVar6 = uVar6 | 1;
              }
              else {
                if (iVar11 < 0xc311) {
                  if (iVar11 != 0xc166) {
                    iVar3 = 0xc191;
                    goto LAB_97bcadb8;
                  }
                  goto LAB_97bcc470;
                }
                if (iVar11 == 0xd7ba) {
                  iVar12 = _PPStreamChunkCreateWithType(4,0);
                  iVar3 = 5;
                  uVar6 = *(uint *)(iVar12 + 0xc);
                  goto LAB_97bcbb08;
                }
                if (iVar11 != 0xe12a) goto LAB_97bcc698;
                iVar12 = _PPStreamChunkCreateWithType(3,0);
                uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0fff1 | 0x50001;
              }
              goto LAB_97bcc694;
            }
            if (iVar11 != 0xc0ba) {
              if (iVar11 < 0xc0bb) {
                if (iVar11 != 0xbd41) goto LAB_97bcc698;
                iVar12 = _PPStreamChunkCreateWithType(3,0);
                iVar3 = 6;
                goto LAB_97bcc5c0;
              }
              if (iVar11 != 0xc0e5) {
                iVar3 = 0xc110;
                goto LAB_97bcadb8;
              }
            }
          }
        }
LAB_97bcc470:
        iVar12 = _PPStreamChunkCreateWithType(3,0);
        uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0ffff | 0x90000;
        goto LAB_97bcbb78;
      }
      iVar12 = _PPStreamChunkCreateWithType(3,0);
      uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0fff3 | 0x50000;
LAB_97bcc190:
      uVar6 = uVar6 | 3;
    }
LAB_97bcc694:
    *(uint *)(iVar12 + 0xc) = uVar6;
    goto LAB_97bcc698;
  }
  if (iVar11 == 0x18b0a) goto LAB_97bcc36c;
  if (iVar11 < 0x18b0b) {
    if (iVar11 == 0x147c7) goto LAB_97bcc2a0;
    if (0x147c7 < iVar11) {
      if (iVar11 == 0x1705e) goto LAB_97bcc3e4;
      if (0x1705e < iVar11) {
        if (iVar11 != 0x17e27) {
          if (iVar11 < 0x17e28) {
            if (iVar11 != 0x170f7) {
              if (iVar11 < 0x170f8) {
                if (iVar11 == 0x17089) goto LAB_97bcc3e4;
                if (iVar11 < 0x1708a) {
                  iVar3 = 0x17076;
                }
                else {
                  if (iVar11 == 0x170a1) goto LAB_97bcc40c;
                  iVar3 = 0x170cc;
                }
LAB_97bcb448:
                if (iVar11 != iVar3) goto LAB_97bcc698;
              }
              else if (iVar11 != 0x17178) {
                if (iVar11 < 0x17179) {
                  if (iVar11 != 0x17122) {
                    iVar3 = 0x1714d;
                    goto LAB_97bcb448;
                  }
                }
                else if (iVar11 != 0x171a3) {
                  iVar3 = 0x17e06;
                  goto LAB_97bcba88;
                }
              }
            }
LAB_97bcc40c:
            iVar12 = _PPStreamChunkCreateWithType(3,0);
            uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0fbff | 0x40300;
            goto LAB_97bcc458;
          }
          if (iVar11 != 0x17ecc) {
            if (0x17ecc < iVar11) {
              if (iVar11 != 0x18a83) {
                if (iVar11 < 0x18a84) {
                  if (iVar11 == 0x17eed) goto LAB_97bcc2ec;
                  iVar3 = 0x18a56;
                }
                else {
                  if (iVar11 == 0x18ab0) goto LAB_97bcc36c;
                  iVar3 = 0x18add;
                }
LAB_97bcb594:
                if (iVar11 != iVar3) goto LAB_97bcc698;
              }
LAB_97bcc36c:
              iVar12 = _PPStreamChunkCreateWithType(3,0);
              uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0f8ff | 0x40000;
              goto LAB_97bcc458;
            }
            if (iVar11 != 0x17e69) {
              if (iVar11 < 0x17e6a) {
                iVar3 = 0x17e48;
              }
              else {
                if (iVar11 == 0x17e8a) goto LAB_97bcc2ec;
                iVar3 = 0x17eab;
              }
LAB_97bcba88:
              if (iVar11 != iVar3) goto LAB_97bcc698;
            }
          }
        }
        goto LAB_97bcc2ec;
      }
      if (iVar11 != 0x14d24) {
        if (0x14d24 < iVar11) {
          if (iVar11 != 0x16f5c) {
            if (iVar11 < 0x16f5d) {
              if (iVar11 != 0x14d92) {
                if (0x14d92 < iVar11) {
                  if (iVar11 == 0x158fc) {
                    iVar12 = _PPStreamChunkCreateWithType(3,0);
                    uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe07fff | 0x104000;
LAB_97bcbe54:
                    uVar6 = uVar6 & 0xffffcfff;
LAB_97bcbfa8:
                    uVar6 = uVar6 & 0xfffff8ff;
                    goto LAB_97bcbfac;
                  }
                  if (iVar11 != 0x15dbb) goto LAB_97bcc698;
                  iVar12 = _PPStreamChunkCreateWithType(3,0);
                  uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe00fff | 0x100000;
                  goto LAB_97bcbe28;
                }
                iVar3 = 0x14d5b;
                goto LAB_97bcb334;
              }
              goto LAB_97bcbf0c;
            }
            if (iVar11 != 0x16fdd) {
              if (iVar11 < 0x16fde) {
                if (iVar11 != 0x16f87) {
                  iVar3 = 0x16fb2;
LAB_97bcb3ac:
                  if (iVar11 != iVar3) goto LAB_97bcc698;
                }
              }
              else if (iVar11 != 0x17008) {
                iVar3 = 0x17033;
                goto LAB_97bcb3ac;
              }
            }
          }
LAB_97bcc3e4:
          iVar12 = _PPStreamChunkCreateWithType(3,0);
          uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0f9ff | 0x40100;
          goto LAB_97bcc458;
        }
        if (iVar11 != 0x14c11) {
          if (iVar11 < 0x14c12) {
            if (iVar11 != 0x14809) {
              if (iVar11 < 0x1480a) {
                iVar3 = 0x147e8;
              }
              else {
                if (iVar11 == 0x1482a) goto LAB_97bcc2a0;
                iVar3 = 0x1484b;
              }
LAB_97bcb2bc:
              if (iVar11 != iVar3) goto LAB_97bcc698;
            }
            goto LAB_97bcc2a0;
          }
          if (iVar11 != 0x14c7f) {
            if (iVar11 < 0x14c80) {
              iVar3 = 0x14c48;
            }
            else {
              if (iVar11 == 0x14cb6) goto LAB_97bcbf0c;
              iVar3 = 0x14ced;
            }
LAB_97bcb334:
            if (iVar11 != iVar3) goto LAB_97bcc698;
          }
        }
      }
LAB_97bcbf0c:
      iVar12 = _PPStreamChunkCreateWithType(3,0);
      uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe00fff | 0x100000;
LAB_97bcbe84:
      uVar6 = uVar6 & 0xfffff8ff | 0x400;
      goto LAB_97bcc458;
    }
    if (iVar11 == 0x11ea4) goto LAB_97bcc258;
    if (iVar11 < 0x11ea5) {
      if (iVar11 != 0x11b4b) {
        if (0x11b4b < iVar11) {
          if (iVar11 != 0x11d4e) {
            if (iVar11 < 0x11d4f) {
              if (iVar11 != 0x11cb5) {
                if (iVar11 < 0x11cb6) {
                  iVar3 = 0x11c82;
                }
                else {
                  if (iVar11 == 0x11ce8) goto LAB_97bcbe60;
                  iVar3 = 0x11d1b;
                }
LAB_97bcb0c4:
                if (iVar11 != iVar3) goto LAB_97bcc698;
              }
            }
            else if (iVar11 != 0x11de7) {
              if (0x11de7 < iVar11) {
                if (iVar11 != 0x11e62) {
                  iVar3 = 0x11e83;
                  goto LAB_97bcb14c;
                }
                goto LAB_97bcc258;
              }
              if (iVar11 != 0x11d81) {
                iVar3 = 0x11db4;
                goto LAB_97bcb0c4;
              }
            }
          }
LAB_97bcbe60:
          iVar12 = _PPStreamChunkCreateWithType(3,0);
          uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0ffff | 0x10c000;
          goto LAB_97bcbe80;
        }
        if (iVar11 != 0x11aa6) {
          if (iVar11 < 0x11aa7) {
            if (iVar11 == 0x1142d) {
              iVar12 = _PPStreamChunkCreateWithType(3,0);
              uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0ffff | 0x10c000;
              goto LAB_97bcbdf0;
            }
            if (iVar11 < 0x1142e) {
              if (iVar11 != 0x110e1) goto LAB_97bcc698;
              iVar12 = _PPStreamChunkCreateWithType(3,0);
              uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0fffe | 0x50000;
              iVar3 = 3;
              goto LAB_97bcc0cc;
            }
            if (iVar11 != 0x11a64) {
              iVar3 = 0x11a85;
              goto LAB_97bcb03c;
            }
          }
          else if (iVar11 != 0x11ae8) {
            if (iVar11 < 0x11ae9) {
              iVar3 = 0x11ac7;
            }
            else {
              if (iVar11 == 0x11b09) goto LAB_97bcc234;
              iVar3 = 0x11b2a;
            }
LAB_97bcb03c:
            if (iVar11 != iVar3) goto LAB_97bcc698;
          }
        }
      }
LAB_97bcc234:
      iVar12 = _PPStreamChunkCreateWithType(3,0);
      uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0ffff | 0x30000;
      iVar3 = 2;
    }
    else {
      if (iVar11 != 0x14328) {
        if (iVar11 < 0x14329) {
          if (iVar11 != 0x11f49) {
            if (0x11f49 < iVar11) {
              if (iVar11 == 0x1275a) {
                iVar12 = _PPStreamChunkCreateWithType(3,0);
                uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0fff8 | 0x50008;
                goto LAB_97bcc694;
              }
              if (iVar11 < 0x1275b) {
                bVar1 = iVar11 == 0x12304;
LAB_97bcb178:
                if (!bVar1) goto LAB_97bcc698;
                goto LAB_97bcc034;
              }
              if (iVar11 == 0x12c7a) {
                iVar12 = _PPStreamChunkCreateWithType(3,0);
                uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0cfff | 0x10c000;
                goto LAB_97bcbe28;
              }
              iVar3 = 0x14307;
              goto LAB_97bcb220;
            }
            if (iVar11 != 0x11ee6) {
              if (iVar11 < 0x11ee7) {
                iVar3 = 0x11ec5;
              }
              else {
                if (iVar11 == 0x11f07) goto LAB_97bcc258;
                iVar3 = 0x11f28;
              }
LAB_97bcb14c:
              if (iVar11 != iVar3) goto LAB_97bcc698;
            }
          }
LAB_97bcc258:
          iVar12 = _PPStreamChunkCreateWithType(3,0);
          iVar3 = 3;
          uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0ffff | 0x30000;
          goto LAB_97bcc274;
        }
        if (iVar11 != 0x143ac) {
          if (0x143ac < iVar11) {
            if (iVar11 != 0x14764) {
              if (iVar11 < 0x14765) {
                if (iVar11 != 0x143cd) {
                  iVar3 = 0x143ee;
                  goto LAB_97bcb220;
                }
                goto LAB_97bcc27c;
              }
              if (iVar11 != 0x14785) {
                iVar3 = 0x147a6;
                goto LAB_97bcb2bc;
              }
            }
LAB_97bcc2a0:
            iVar12 = _PPStreamChunkCreateWithType(3,0);
            uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0f7ff | 0x30700;
            goto LAB_97bcc458;
          }
          if (iVar11 != 0x1436a) {
            if (iVar11 < 0x1436b) {
              iVar3 = 0x14349;
LAB_97bcb220:
              if (iVar11 != iVar3) goto LAB_97bcc698;
            }
            else if (iVar11 != 0x1438b) {
              if (iVar11 != 0x143a8) goto LAB_97bcc698;
              iVar12 = _PPStreamChunkCreateWithType(3,0);
              uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe00fff | 0x100000;
              goto LAB_97bcbdf4;
            }
          }
        }
      }
LAB_97bcc27c:
      iVar12 = _PPStreamChunkCreateWithType(3,0);
      uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0ffff | 0x30000;
      iVar3 = 6;
    }
LAB_97bcc274:
    uVar6 = iVar3 << 8 | uVar6 & 0xfffff0ff;
  }
  else {
    if (iVar11 == 0x1aa90) goto LAB_97bcc3bc;
    if (0x1aa90 < iVar11) {
      if (iVar11 == 0x21945) {
        iVar12 = _PPStreamChunkCreateWithType(3,0);
        uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe08fff | 0x108000;
LAB_97bcbe28:
        iVar3 = 1;
LAB_97bcbe2c:
        uVar6 = iVar3 << 8 | uVar6 & 0xfffff8ff;
        goto LAB_97bcc694;
      }
      if (iVar11 < 0x21946) {
        if (iVar11 != 0x203d7) {
          if (iVar11 < 0x203d8) {
            if (iVar11 == 0x20368) goto LAB_97bcbfb8;
            if (iVar11 < 0x20369) {
              if (iVar11 == 0x1f97a) {
                iVar12 = _PPStreamChunkCreateWithType(3,0);
                uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe08fff | 0x108000;
LAB_97bcbdf4:
                uVar6 = uVar6 & 0xfffff8ff | 0x300;
LAB_97bcbfac:
                *(uint *)(iVar12 + 0xc) = uVar6;
                *(undefined1 *)(iVar12 + 0xf) = 0;
                goto LAB_97bcc698;
              }
              if (0x1f97a < iVar11) {
                if (iVar11 == 0x1ff52) {
                  iVar12 = _PPStreamChunkCreateWithType(3,0);
                  iVar3 = 5;
                  uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0ffff | 0x50001;
                  goto LAB_97bcc0cc;
                }
                iVar3 = 0x20323;
                goto LAB_97bcb91c;
              }
              if (iVar11 != 0x1f1a8) goto LAB_97bcc698;
              goto LAB_97bcc048;
            }
            if (iVar11 != 0x20395) {
              if (iVar11 < 0x20396) {
                iVar3 = 0x20374;
              }
              else {
                if (iVar11 == 0x203ad) goto LAB_97bcbfb8;
                iVar3 = 0x203b6;
              }
              goto LAB_97bcba88;
            }
          }
          else if (iVar11 != 0x2043a) {
            if (iVar11 < 0x2043b) {
              if (iVar11 == 0x203f8) goto LAB_97bcc2ec;
              if (iVar11 < 0x203f9) {
                iVar3 = 0x203f2;
              }
              else {
                if (iVar11 == 0x20419) goto LAB_97bcc2ec;
                iVar3 = 0x20437;
              }
LAB_97bcb91c:
              if (iVar11 != iVar3) goto LAB_97bcc698;
            }
            else if (iVar11 != 0x204c1) {
              if (iVar11 < 0x204c2) {
                if (iVar11 != 0x2045b) {
                  iVar3 = 0x2047c;
                  goto LAB_97bcb91c;
                }
                goto LAB_97bcc2ec;
              }
              if (iVar11 != 0x20506) {
                if (iVar11 != 0x2138c) goto LAB_97bcc698;
                iVar12 = _PPStreamChunkCreateWithType(3,0);
                uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0ffff | 0x10c000;
                goto LAB_97bcbe54;
              }
            }
LAB_97bcbfb8:
            iVar12 = _PPStreamChunkCreateWithType(3,0);
            uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe08fff | 0x108000;
            goto LAB_97bcbe84;
          }
        }
      }
      else {
        if (iVar11 == 0x24cb9) {
LAB_97bcc048:
          iVar12 = _PPStreamChunkCreateWithType(3,0);
          iVar3 = 0xe;
          goto LAB_97bcc5c0;
        }
        if (iVar11 < 0x24cba) {
          if (iVar11 != 0x2461d) {
            if (iVar11 < 0x2461e) {
              if (iVar11 == 0x23231) goto LAB_97bcc048;
              if (iVar11 < 0x23232) {
                if (iVar11 != 0x21eb8) goto LAB_97bcc698;
                iVar12 = _PPStreamChunkCreateWithType(3,0);
                iVar3 = 5;
                uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0fffe | 0x50000;
LAB_97bcc0cc:
                uVar6 = iVar3 << 1 | uVar6 & 0xfffffff1;
                goto LAB_97bcc694;
              }
              if (iVar11 != 0x245db) {
                iVar3 = 0x245fc;
                goto LAB_97bcba88;
              }
            }
            else if (iVar11 != 0x24680) {
              if (iVar11 < 0x24681) {
                if (iVar11 != 0x2463e) {
                  iVar3 = 0x2465f;
                  goto LAB_97bcba88;
                }
              }
              else if (iVar11 != 0x246a1) {
                iVar3 = 0x246c2;
                goto LAB_97bcba88;
              }
            }
          }
        }
        else if (iVar11 != 0x2616e) {
          if (iVar11 < 0x2616f) {
            if (iVar11 != 0x2610b) {
              if (iVar11 < 0x2610c) {
                if (iVar11 == 0x254c3) {
                  iVar12 = _PPStreamChunkCreateWithType(3,0);
                  *(uint *)(iVar12 + 0xc) = *(uint *)(iVar12 + 0xc) & 0xffe008ff | 0x100000;
                  *(undefined1 *)(iVar12 + 0xf) = 0;
                }
                goto LAB_97bcc698;
              }
              if (iVar11 != 0x2612c) {
                iVar3 = 0x2614d;
                goto LAB_97bcba88;
              }
            }
          }
          else if (iVar11 != 0x261d1) {
            if (iVar11 < 0x261d2) {
              if (iVar11 != 0x2618f) {
                iVar3 = 0x261b0;
                goto LAB_97bcba88;
              }
            }
            else if (iVar11 != 0x261f2) {
              if (iVar11 != 0x343c5) goto LAB_97bcc698;
              iVar12 = _PPStreamChunkCreateWithType(3,0);
              uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe08fff | 0x108000;
              goto LAB_97bcbfa8;
            }
          }
        }
      }
LAB_97bcc2ec:
      iVar12 = _PPStreamChunkCreateWithType(3,0);
      uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0ffff | 0x30000;
      iVar3 = 5;
      goto LAB_97bcc274;
    }
    if (iVar11 == 0x18e85) {
LAB_97bcc2c8:
      iVar12 = _PPStreamChunkCreateWithType(3,0);
      uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0ffff | 0x30000;
      iVar3 = 4;
      goto LAB_97bcc274;
    }
    if (0x18e85 < iVar11) {
      if (iVar11 != 0x19384) {
        if (0x19384 < iVar11) {
          if (iVar11 != 0x1a982) {
            if (iVar11 < 0x1a983) {
              if (iVar11 != 0x193c6) {
                if (iVar11 < 0x193c7) {
                  iVar3 = 0x193a5;
                  goto LAB_97bcb768;
                }
                if (iVar11 != 0x193e7) {
                  iVar3 = 0x1a955;
                  goto LAB_97bcb7d8;
                }
              }
              goto LAB_97bcc2c8;
            }
            if (iVar11 != 0x1aa09) {
              if (iVar11 < 0x1aa0a) {
                if (iVar11 != 0x1a9af) {
                  iVar3 = 0x1a9dc;
LAB_97bcb7d8:
                  if (iVar11 != iVar3) goto LAB_97bcc698;
                }
              }
              else if (iVar11 != 0x1aa36) {
                iVar3 = 0x1aa63;
                goto LAB_97bcb7d8;
              }
            }
          }
LAB_97bcc3bc:
          iVar12 = _PPStreamChunkCreateWithType(3,0);
          uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0fcff | 0x40400;
          goto LAB_97bcc458;
        }
        if (iVar11 != 0x18f09) {
          if (iVar11 < 0x18f0a) {
            if (iVar11 != 0x18ea6) {
              if (iVar11 < 0x18ea7) {
                iVar3 = 0x18e8a;
                goto LAB_97bcb6c4;
              }
              if (iVar11 != 0x18ec7) {
                iVar3 = 0x18ee8;
                goto LAB_97bcb768;
              }
            }
          }
          else if (iVar11 != 0x19321) {
            if (iVar11 < 0x19322) {
              if (iVar11 != 0x18f2a) {
                iVar3 = 0x19300;
LAB_97bcb768:
                if (iVar11 != iVar3) goto LAB_97bcc698;
              }
            }
            else if (iVar11 != 0x19342) {
              iVar3 = 0x19363;
              goto LAB_97bcb768;
            }
          }
        }
      }
      goto LAB_97bcc2c8;
    }
    if (iVar11 != 0x18c8a) {
      if (0x18c8a < iVar11) {
        if (iVar11 != 0x18dde) {
          if (iVar11 < 0x18ddf) {
            if (iVar11 != 0x18d5d) {
              if (iVar11 < 0x18d5e) {
                iVar3 = 0x18cb7;
                goto LAB_97bcb60c;
              }
              if (iVar11 != 0x18d88) {
                iVar3 = 0x18db3;
LAB_97bcb6c4:
                if (iVar11 != iVar3) goto LAB_97bcc698;
              }
            }
          }
          else {
            if (iVar11 == 0x18e43) goto LAB_97bcc2c8;
            if (iVar11 < 0x18e44) {
              if (iVar11 != 0x18e09) {
                iVar3 = 0x18e34;
                goto LAB_97bcb6c4;
              }
            }
            else if (iVar11 != 0x18e5f) {
              iVar3 = 0x18e64;
              goto LAB_97bcb768;
            }
          }
        }
        iVar12 = _PPStreamChunkCreateWithType(3,0);
        uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0fdff | 0x40500;
        goto LAB_97bcc458;
      }
      if (iVar11 != 0x18ba9) {
        if (iVar11 < 0x18baa) {
          if (iVar11 == 0x18b64) goto LAB_97bcc36c;
          if (iVar11 < 0x18b65) {
            iVar3 = 0x18b37;
          }
          else {
            if (iVar11 == 0x18b7c) goto LAB_97bcc390;
            iVar3 = 0x18b91;
          }
          goto LAB_97bcb594;
        }
        if (iVar11 != 0x18c03) {
          if (iVar11 < 0x18c04) {
            iVar3 = 0x18bd6;
          }
          else {
            if (iVar11 == 0x18c30) goto LAB_97bcc390;
            iVar3 = 0x18c5d;
          }
LAB_97bcb60c:
          if (iVar11 != iVar3) goto LAB_97bcc698;
        }
      }
    }
LAB_97bcc390:
    iVar12 = _PPStreamChunkCreateWithType(3,0);
    uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0f8ff | 0x40200;
  }
LAB_97bcc458:
  *(uint *)(iVar12 + 0xc) = uVar6;
  uVar9 = ParseSymbol__GetDirectIndex((uint)param_1);
  *(undefined1 *)(iVar12 + 0xf) = uVar9;
LAB_97bcc698:
  *(undefined4 *)(param_1 + 0x34) = 1;
  return iVar12;
}

/* GetChunkForSymbol @ 0x97bcc6b8 (592 bytes) */
int GetChunkForSymbol(param_1, param_2)
  unsigned char * param_1;
  int param_2;
{
  bool bVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  undefined4 uVar6;
  uint uVar7;
  void *pvVar8;
  
  pvVar8 = *(void **)(param_1 + 0x14);
  if (((pvVar8 == (void *)0x0) || (iVar4 = _memcmp(pvVar8,"gl_",3), iVar4 != 0)) ||
     (*(char *)((int)pvVar8 + 3) == '_')) {
    uVar6 = (**(code **)(**(int **)(param_1 + 0xc) + 0x24))();
    switch(uVar6) {
    case 0:
    case 1:
    case 2:
    case 4:
    case 5:
    case 9:
    case 10:
    case 0xb:
    case 0xc:
      pbVar5 = (byte *)_PPStreamChunkCreateWithType(0,0);
      break;
    case 3:
      pbVar5 = (byte *)_PPStreamChunkCreateWithType(2,0);
      *(uint *)(pbVar5 + 0xc) = *(uint *)(pbVar5 + 0xc) & 0xfff0ffff | 0x90000;
      break;
    case 6:
      pbVar5 = (byte *)_PPStreamChunkCreateWithType(3,0);
      *(uint *)(pbVar5 + 0xc) = *(uint *)(pbVar5 + 0xc) & 0xffe0ffff | 0x10000;
      iVar4 = (**(code **)(**(int **)(param_1 + 0xc) + 0x20))();
      *(uint *)(pbVar5 + 0x10) =
           (uint)(iVar4 - 5U < 8) << 0x1f | *(uint *)(pbVar5 + 0x10) & 0x7fffffff;
      break;
    default:
      pbVar5 = (byte *)0x0;
    }
  }
  else {
    pbVar5 = (byte *)((int (*)())GetBuiltInChunkForSymbol)(param_1,param_2);
    *(undefined4 *)(param_1 + 0x38) = 1;
    *(undefined4 *)(param_1 + 0x28) = 0xffffffff;
  }
  if (pbVar5 == (byte *)0x0) goto LAB_97bcc8c4;
  bVar2 = *pbVar5;
  if (bVar2 == 2) {
LAB_97bcc864:
    uVar7 = GetPPStreamTypeForGLType(*(ushort *)(param_1 + 0x2c));
    *(uint *)(pbVar5 + 0xc) = (uVar7 & 7) << 0x1a | *(uint *)(pbVar5 + 0xc) & 0xe3ffffff;
    iVar4 = GetScalerWidthForType(*(ushort *)(param_1 + 0x2c));
    uVar7 = (iVar4 + -1) * 0x1000000 & 0x3000000U | *(uint *)(pbVar5 + 0xc) & 0x1cffffff;
LAB_97bcc8c0:
    *(uint *)(pbVar5 + 0xc) = uVar7;
  }
  else if (bVar2 < 3) {
    if (bVar2 == 0) {
      uVar7 = GetPPStreamTypeForGLType(*(ushort *)(param_1 + 0x2c));
      *(uint *)(pbVar5 + 0xc) = (uVar7 & 7) << 0x1a | *(uint *)(pbVar5 + 0xc) & 0xe3ffffff;
      iVar4 = GetScalerWidthForType(*(ushort *)(param_1 + 0x2c));
      uVar7 = (iVar4 + -1) * 0x1000000 & 0x3000000U | *(uint *)(pbVar5 + 0xc) & 0x1cffffff;
      goto LAB_97bcc8c0;
    }
  }
  else if ((bVar2 == 3) || (bVar2 == 4)) goto LAB_97bcc864;
LAB_97bcc8c4:
  if (*(int *)(param_1 + 0x34) == 0) {
    return pbVar5;
  }
  uVar7 = ((int (*)())GetBuiltInInitialSwizzle)(param_1);
  if (uVar7 == 0) {
    return pbVar5;
  }
  bVar2 = *pbVar5;
  if (bVar2 != 2) {
    if (bVar2 < 3) {
      bVar1 = bVar2 == 0;
    }
    else {
      if (bVar2 == 3) goto LAB_97bcc908;
      bVar1 = bVar2 == 4;
    }
    if (!bVar1) {
      return pbVar5;
    }
  }
LAB_97bcc908:
  uVar3 = *(uint *)(pbVar5 + 0xc) >> 0x18 & 3;
  if (uVar3 < uVar7) {
    uVar3 = uVar7;
  }
  *(uint *)(pbVar5 + 0xc) = (uVar3 & 3) << 0x18 | *(uint *)(pbVar5 + 0xc) & 0xfcffffff;
  return pbVar5;
}

/* FunctionTable__FunctionTable @ 0x97bcc93c (4 bytes) */
int FunctionTable__FunctionTable(this)
  unsigned char * this;
{
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)this = 0;
  return;
}

/* FunctionTable__FunctionTable_97bcc940 @ 0x97bcc940 (4 bytes) */
int FunctionTable__FunctionTable_97bcc940(this)
  unsigned char * this;
{
  FunctionTable(this);
  return;
}

/* FunctionTable__FunctionTable_97bcc944 @ 0x97bcc944 (16 bytes) */
int FunctionTable__FunctionTable_97bcc944(this)
  unsigned char * this;
{
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)this = 0;
  return;
}

/* FunctionTable___FunctionTable @ 0x97bcc954 (8 bytes) */
int FunctionTable___FunctionTable(this)
  unsigned char * this;
{
  ~FunctionTable(this);
  return;
}

/* FunctionTable___FunctionTable_97bcc95c @ 0x97bcc95c (8 bytes) */
int FunctionTable___FunctionTable_97bcc95c(this)
  unsigned char * this;
{
  ~FunctionTable(this);
  return;
}

/* FunctionTable___FunctionTable_97bcc964 @ 0x97bcc964 (4 bytes) */
int FunctionTable___FunctionTable_97bcc964(this)
  unsigned char * this;
{
  clear(this);
  return;
}

/* FunctionTable__clear @ 0x97bcc968 (120 bytes) */
int FunctionTable__clear(this)
  unsigned char * this;
{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (0 < *(int *)(this + 4)) {
    iVar3 = 0;
    do {
      iVar2 = iVar2 + 1;
      puVar1 = (undefined4 *)(iVar3 + *(int *)this);
      iVar3 = iVar3 + 0x18;
      _free((void *)*puVar1);
    } while (iVar2 < *(int *)(this + 4));
  }
  if (*(void **)this != (void *)0x0) {
    _free(*(void **)this);
  }
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)this = 0;
  return;
}

/* FunctionTable__addFunction @ 0x97bcc9e0 (284 bytes) */
int FunctionTable__addFunction(this, param_1)
  unsigned char * this;
  char *param_1;
{
  void *pvVar1;
  void *pvVar2;
  size_t sVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  uint uVar9;
  
  uVar9 = *(uint *)(this + 4);
  if ((uVar9 & 0xf) == 0) {
    pvVar1 = _malloc(uVar9 * 0x18 + 0x180);
    _memset(pvVar1,0,*(int *)(this + 4) * 0x18 + 0x180);
    uVar9 = *(uint *)(this + 4);
    iVar4 = 0;
    if ((int)uVar9 < 1) {
      pvVar2 = *(void **)this;
    }
    else {
      pvVar2 = *(void **)this;
      iVar5 = 0;
      do {
        uVar7 = *(undefined4 *)((int)pvVar2 + iVar5 + 4);
        iVar4 = iVar4 + 1;
        uVar8 = *(undefined4 *)((int)pvVar2 + iVar5 + 8);
        uVar6 = *(undefined4 *)((int)pvVar2 + iVar5 + 0xc);
        *(undefined4 *)(iVar5 + (int)pvVar1) = *(undefined4 *)(iVar5 + (int)pvVar2);
        *(undefined4 *)((int)pvVar1 + iVar5 + 4) = uVar7;
        *(undefined4 *)((int)pvVar1 + iVar5 + 8) = uVar8;
        *(undefined4 *)((int)pvVar1 + iVar5 + 0xc) = uVar6;
        uVar6 = *(undefined4 *)((int)pvVar2 + iVar5 + 0x10);
        *(undefined4 *)((int)pvVar1 + iVar5 + 0x14) = *(undefined4 *)((int)pvVar2 + iVar5 + 0x14);
        *(undefined4 *)((int)pvVar1 + iVar5 + 0x10) = uVar6;
        iVar5 = iVar5 + 0x18;
      } while (iVar4 < (int)uVar9);
    }
    if (pvVar2 != (void *)0x0) {
      _free(pvVar2);
      uVar9 = *(uint *)(this + 4);
    }
    *(void **)this = pvVar1;
  }
  iVar4 = *(int *)this;
  sVar3 = _strlen(param_1);
  pvVar1 = _malloc(sVar3 + 1);
  *(void **)(uVar9 * 0x18 + iVar4) = pvVar1;
  _strcpy(*(char **)(*(int *)(this + 4) * 0x18 + *(int *)this),param_1);
  *(int *)(this + 4) = *(int *)(this + 4) + 1;
  return;
}

/* FunctionTable__removeFunction @ 0x97bccafc (168 bytes) */
int FunctionTable__removeFunction(this, param_1)
  unsigned char * this;
  int param_1;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar5 = param_1 * 0x18;
  _free(*(void **)(iVar5 + *(int *)this));
  iVar1 = *(int *)(this + 4);
  if (param_1 < iVar1) {
    do {
      param_1 = param_1 + 1;
      iVar1 = iVar5 + *(int *)this;
      uVar4 = *(undefined4 *)(iVar1 + 0x1c);
      uVar3 = *(undefined4 *)(iVar1 + 0x20);
      uVar2 = *(undefined4 *)(iVar1 + 0x24);
      *(undefined4 *)(iVar5 + *(int *)this) = *(undefined4 *)(iVar1 + 0x18);
      iVar5 = iVar5 + 0x18;
      *(undefined4 *)(iVar1 + 4) = uVar4;
      *(undefined4 *)(iVar1 + 8) = uVar3;
      *(undefined4 *)(iVar1 + 0xc) = uVar2;
      *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(iVar1 + 0x2c);
      *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(iVar1 + 0x28);
      iVar1 = *(int *)(this + 4);
    } while (param_1 < iVar1);
  }
  *(int *)(this + 4) = iVar1 + -1;
  return;
}

/* FunctionTable__setReturnVal @ 0x97bccba4 (20 bytes) */
int FunctionTable__setReturnVal(this, param_1, param_2)
  unsigned char * this;
  int param_1;
  int param_2;
{
  undefined3 in_register_00000014;
  
  *(uint *)(param_1 * 0x18 + *(int *)this + 4) = CONCAT31(in_register_00000014,param_2);
  return;
}

/* FunctionTable__setEmpty @ 0x97bccbb8 (20 bytes) */
int FunctionTable__setEmpty(this, param_1, param_2)
  unsigned char * this;
  int param_1;
  int param_2;
{
  undefined3 in_register_00000014;
  
  *(uint *)(param_1 * 0x18 + *(int *)this + 8) = CONCAT31(in_register_00000014,param_2);
  return;
}

