#include "decls.h"

/* _GetRegisterTypeInfo @ 0x97c0b704 (544 bytes) */
int _GetRegisterTypeInfo(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  
  switch(param_2[1]) {
  case 0:
    iVar3 = _PPStreamChunkListChunkAtIndex(*(undefined4 *)(param_1 + 0x18),*param_2);
    if (iVar3 != 0) {
      param_2[2] = *(uint *)(iVar3 + 0xc) >> 0x1d;
      param_2[3] = *(uint *)(iVar3 + 0xc) >> 0x1a & 7;
      param_2[4] = *(uint *)(iVar3 + 0xc) >> 0x18 & 3;
    }
    param_2[5] = 0;
    break;
  case 1:
    uVar2 = *(undefined4 *)(param_1 + 4);
    goto LAB_97c0b8d4;
  case 2:
    iVar3 = _PPStreamChunkListChunkAtIndex(*(undefined4 *)(param_1 + 0x10),*param_2);
    param_2[2] = *(uint *)(iVar3 + 0xc) >> 0x1d;
    param_2[3] = *(uint *)(iVar3 + 0xc) >> 0x1a & 7;
    uVar1 = *(uint *)(iVar3 + 0xc);
    param_2[5] = 0;
    param_2[4] = uVar1 >> 0x18 & 3;
    if ((*(uint *)(iVar3 + 0xc) >> 0x10 & 0x1f) == 0x11) {
      param_2[5] = 1;
      iVar3 = _PPStreamChunkListChunkAtIndex
                        (*(undefined4 *)(param_1 + 0x2c),(uint)*(ushort *)(iVar3 + 0xe));
      uVar5 = *(uint *)(iVar3 + 0x10);
      uVar1 = *(uint *)(iVar3 + 0xc);
      uVar4 = *(uint *)(iVar3 + 0x14);
      if (param_2[3] == 1) {
        param_2[9] = *(uint *)(iVar3 + 0x18);
        param_2[6] = uVar1;
        param_2[7] = uVar5;
        param_2[8] = uVar4;
      }
      else {
        dVar8 = (double)CONCAT44(0x43300000,*(uint *)(iVar3 + 0x18) ^ 0x80000000) - DOUBLE_97c30a58;
        dVar6 = (double)CONCAT44(0x43300000,uVar5 ^ 0x80000000) - DOUBLE_97c30a58;
        dVar7 = (double)CONCAT44(0x43300000,uVar4 ^ 0x80000000) - DOUBLE_97c30a58;
        param_2[6] = (float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) - DOUBLE_97c30a58);
        param_2[7] = (float)dVar6;
        param_2[8] = (float)dVar7;
        param_2[9] = (float)dVar8;
      }
    }
    break;
  case 3:
    uVar2 = *(undefined4 *)(param_1 + 0x1c);
LAB_97c0b8d4:
    iVar3 = _PPStreamChunkListChunkAtIndex(uVar2,*param_2);
    param_2[2] = *(uint *)(iVar3 + 0xc) >> 0x1d;
    param_2[3] = *(uint *)(iVar3 + 0xc) >> 0x1a & 7;
    uVar1 = *(uint *)(iVar3 + 0xc);
    param_2[5] = 0;
    param_2[4] = uVar1 >> 0x18 & 3;
    break;
  case 4:
    param_2[5] = 0;
    param_2[3] = 3;
    param_2[2] = 0;
    param_2[4] = 0;
  }
  return;
}

/* _FlattenIf @ 0x97c0b938 (3384 bytes) */
int _FlattenIf(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  undefined2 uVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  undefined1 *puVar5;
  uint uVar6;
  uint uVar7;
  undefined2 uVar14;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  undefined4 *puVar11;
  void *pvVar12;
  int *piVar13;
  undefined2 *puVar15;
  uint uVar16;
  undefined1 *puVar17;
  undefined4 uVar18;
  uint uVar19;
  uint uVar20;
  int iVar21;
  undefined4 uVar22;
  int iVar23;
  int iStack00000024;
  undefined1 local_240 [8];
  undefined1 local_238 [40];
  undefined1 auStack_210 [48];
  uint local_1e0;
  uint local_1dc;
  uint local_1d8;
  undefined4 local_1d4;
  uint local_1d0;
  undefined4 local_1cc;
  undefined4 local_1c8;
  undefined4 local_1c4;
  undefined4 local_1c0;
  undefined4 local_1bc;
  undefined4 local_1b8;
  undefined4 local_1b4;
  undefined4 local_1b0;
  undefined4 local_1ac;
  uint local_1a0;
  uint local_19c;
  undefined4 local_198;
  undefined4 local_194;
  undefined4 local_190;
  uint local_18c;
  uint local_188;
  uint local_184;
  uint local_180;
  uint local_17c;
  undefined4 local_178;
  undefined4 local_174;
  undefined4 local_170;
  uint local_16c;
  uint local_168;
  undefined4 local_164;
  uint local_160;
  undefined4 local_15c;
  undefined2 uStack_15a;
  undefined4 local_158;
  undefined4 local_154;
  undefined4 local_150;
  undefined4 local_14c;
  undefined4 local_148;
  undefined4 local_144;
  undefined4 local_140;
  undefined4 local_13c;
  undefined4 local_130;
  uint local_12c;
  uint local_128;
  uint local_124;
  uint local_120;
  undefined4 local_11c;
  undefined2 uStack_11a;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined4 local_fc;
  undefined1 *local_f0;
  int local_ec;
  int local_e8;
  uint local_e0 [4];
  uint local_d0 [4];
  undefined1 *local_c0 [2];
  undefined8 local_b8;
  int local_b0 [10];
  uint local_88;
  undefined4 local_84;
  uint local_80;
  undefined4 local_7c;
  uint local_78;
  undefined4 local_74;
  int local_70 [3];
  int *local_64;
  uint *local_60;
  uint *local_5c;
  uint *local_58;
  undefined1 *local_54;
  
  uVar20 = *(uint *)(param_2 + 0x1c) >> 0x15 & 3;
  local_b8 = DAT_97c3aa2c;
  local_c0[1] = auStack_210;
  local_c0[0] = local_240;
  uVar19 = 0;
  iVar21 = 0;
  iStack00000024 = param_4;
  do {
    local_1b0 = *(undefined4 *)(param_2 + 0x3c);
    local_1d4 = 0;
    uVar6 = *(uint *)(param_2 + 0x10) >> 0x12 & 3;
    local_1d0 = 0;
    local_1cc = 0;
    uVar16 = *(uint *)(param_2 + 0x10) >> 0x17 & 7;
    local_1c8 = 0;
    local_1c4 = 0;
    local_1c0 = 0;
    local_1bc = 0;
    local_1b8 = 0;
    local_1b4 = 0;
    local_1ac = 0;
    uVar7 = uVar20 << 10;
    local_1dc = uVar16 << 0x17 | uVar6 << 0x12;
    local_1e0 = (*(uint *)((int)local_b0 + iVar21 + -8) & 0xff) << 0x12 | 0x20000000;
    if (uVar20 == 1) {
      uVar7 = 0x4400;
    }
    else if (1 < uVar20) {
      if (uVar20 == 2) {
        uVar7 = 0x8800;
      }
      else if (uVar20 == 3) {
        uVar7 = 0x10c00;
      }
    }
    else if (uVar20 == 0) {
      uVar7 = 0x2000;
    }
    local_1d8 = uVar7 | 0x20000;
    uVar14 = _AddTempRegister(param_1,uVar6,uVar16,(uVar7 & 0xc00) >> 10);
    local_1d0 = (*(uint *)(param_2 + 0x1c) >> 0x1b & 1) << 0x1b |
                (*(uint *)(param_2 + 0x1c) >> 0x17 & 7) << 0x17 |
                uVar20 << 0x15 | local_1d0 & 0xf41fcfff;
    local_1d4 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_1d4) + 0)),uVar14);
    local_1cc = CONCAT22((*(unsigned short *)((unsigned char *)&(local_1cc) + 0)),*(undefined2 *)(param_2 + 0x22));
    _PPStreamInsertOperationBeforeChunk(param_1,&local_1e0,0,0,param_2);
    uVar19 = uVar19 + 1;
    *(uint *)(*(int *)((int)local_c0 + iVar21) + 4) = local_1d8 >> 0x11 & 7;
    **(uint **)((int)local_c0 + iVar21) = local_1d4 & 0xffff;
    *(uint *)(*(int *)((int)local_c0 + iVar21) + 8) = local_1dc >> 0x12 & 3;
    *(uint *)(*(int *)((int)local_c0 + iVar21) + 0xc) = local_1dc >> 0x17 & 7;
    piVar13 = (int *)((int)local_c0 + iVar21);
    iVar21 = iVar21 + 4;
    *(uint *)(*piVar13 + 0x10) = local_1d8 >> 10 & 3;
  } while (uVar19 < 2);
  uVar18 = 0;
  uVar22 = 0;
  iVar21 = _HashTableNew((*(uint *)(*(int *)(param_1 + 4) + 8) >> 5) + 1,DAT_a7b7bf80,DAT_a7b7bf7c);
  uVar8 = _HashTableNew((*(uint *)(*(int *)(param_1 + 4) + 8) >> 5) + 1,DAT_a7b7bf80,DAT_a7b7bf7c);
  if (param_3 != 0) {
    uVar18 = _HashTableNew((*(uint *)(*(int *)(param_1 + 4) + 8) >> 5) + 1,DAT_a7b7bf80,DAT_a7b7bf7c
                          );
    uVar22 = _HashTableNew((*(uint *)(*(int *)(param_1 + 4) + 8) >> 5) + 1,DAT_a7b7bf80,DAT_a7b7bf7c
                          );
  }
  local_70[2] = _HashSetNew((*(uint *)(*(int *)(param_1 + 4) + 8) >> 5) + 1,DAT_a7b7bf80,
                            DAT_a7b7bf7c);
  local_b0[0] = iVar21;
  local_b0[1] = uVar18;
  local_b0[2] = uVar8;
  local_b0[3] = uVar22;
  local_b0[4] = param_2;
  local_b0[5] = param_3;
  if (param_3 == 0) {
    param_3 = iStack00000024;
  }
  uVar19 = 0;
  local_b0[6] = param_3;
  iVar21 = 0;
  local_b0[7] = iStack00000024;
  do {
    iVar9 = *(int *)((int)local_b0 + iVar21 + 0x10);
    if ((iVar9 != 0) &&
       (iVar9 = *(int *)(iVar9 + 8), iVar9 != *(int *)((int)local_b0 + iVar21 + 0x18))) {
      local_64 = local_b0 + 8;
      local_60 = &local_88;
      local_5c = &local_80;
      local_58 = &local_78;
      local_54 = local_238;
      do {
        iVar10 = _GetValidArgs(iVar9);
        if (0 < iVar10) {
          iVar23 = iVar9;
          do {
            local_19c = *(uint *)(iVar23 + 0x1c) >> 0x17 & 7;
            local_1a0 = (uint)*(ushort *)(iVar23 + 0x22);
            puVar11 = (undefined4 *)
                      _HashTableGet(*(undefined4 *)((int)local_b0 + iVar21),&local_1a0);
            if (puVar11 == (undefined4 *)0x0) {
              ((int (*)())_GetRegisterTypeInfo)(param_1,&local_1a0);
              pvVar12 = _malloc(0x28);
              _memcpy(pvVar12,&local_1a0,0x28);
              puVar11 = _malloc(0x28);
              _memcpy(puVar11,&local_1a0,0x28);
              puVar11[1] = 1;
              uVar8 = _AddTempRegister(param_1,local_198,local_194,local_190);
              *puVar11 = uVar8;
              _HashTableAdd(*(undefined4 *)((int)local_b0 + iVar21),pvVar12,puVar11);
              _HashTableAdd(*(undefined4 *)((int)local_b0 + iVar21 + 8),puVar11,pvVar12);
            }
            else {
              _HashTableGet(*(undefined4 *)((int)local_b0 + iVar21 + 8),puVar11);
            }
            iVar10 = iVar10 + -1;
            *(uint *)(iVar23 + 0x1c) =
                 (puVar11[1] & 7) << 0x17 | *(uint *)(iVar23 + 0x1c) & 0xfc7fffff;
            *(undefined2 *)(iVar23 + 0x22) = *(undefined2 *)((int)puVar11 + 2);
            iVar23 = iVar23 + 8;
          } while (iVar10 != 0);
        }
        if ((*(uint *)(iVar9 + 0x14) & 0x1e000) != 0) {
          local_19c = *(uint *)(iVar9 + 0x14) >> 0x11 & 7;
          local_1a0 = (uint)*(ushort *)(iVar9 + 0x1a);
          puVar11 = (undefined4 *)_HashTableGet(*(undefined4 *)((int)local_b0 + iVar21),&local_1a0);
          if (puVar11 == (undefined4 *)0x0) {
            ((int (*)())_GetRegisterTypeInfo)(param_1,&local_1a0);
            pvVar12 = _malloc(0x28);
            _memcpy(pvVar12,&local_1a0,0x28);
            puVar11 = _malloc(0x28);
            _memcpy(puVar11,&local_1a0,0x28);
            puVar11[1] = 1;
            uVar8 = _AddTempRegister(param_1,local_198,local_194,local_190);
            *puVar11 = uVar8;
            _HashTableAdd(*(undefined4 *)((int)local_b0 + iVar21),pvVar12,puVar11);
            _HashTableAdd(*(undefined4 *)((int)local_b0 + iVar21 + 8),puVar11,pvVar12);
          }
          else {
            pvVar12 = (void *)_HashTableGet(*(undefined4 *)((int)local_b0 + iVar21 + 8),puVar11);
          }
          if (local_70[2] != 0) {
            _HashSetAdd(local_70[2],pvVar12);
          }
          *(uint *)(iVar9 + 0x14) = (puVar11[1] & 7) << 0x11 | *(uint *)(iVar9 + 0x14) & 0xfff1ffff;
          *(undefined2 *)(iVar9 + 0x1a) = *(undefined2 *)((int)puVar11 + 2);
        }
        if ((*(uint *)(iVar9 + 0xc) >> 0x12 & 0xff) == 0x4f) {
          local_160 = 0;
          local_15c = 0;
          local_158 = 0;
          local_154 = 0;
          local_150 = 0;
          local_14c = 0;
          local_148 = 0;
          local_144 = 0;
          local_140 = *(undefined4 *)(iVar9 + 0x3c);
          local_164 = 0;
          local_170 = 0x40900000;
          local_13c = 0;
          uVar6 = *(uint *)(iVar9 + 0x10) >> 0x12 & 3;
          uVar7 = uVar20 << 10;
          uVar16 = *(uint *)(iVar9 + 0x10) >> 0x17 & 7;
          local_16c = uVar16 << 0x17 | uVar6 << 0x12;
          if (uVar20 == 1) {
            uVar7 = 0x4400;
          }
          else if (1 < uVar20) {
            if (uVar20 == 2) {
              uVar7 = 0x8800;
            }
            else if (uVar20 == 3) {
              uVar7 = 0x10c00;
            }
          }
          else if (uVar20 == 0) {
            uVar7 = 0x2000;
          }
          local_168 = uVar7 | 0x20000;
          uVar14 = _AddTempRegister(param_1,uVar6,uVar16,(uVar7 & 0xc00) >> 10);
          puVar5 = local_54;
          puVar4 = local_58;
          puVar3 = local_60;
          piVar13 = local_64;
          local_164 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_164) + 0)),uVar14);
          iVar10 = 0;
          local_b0[8] = *(uint *)(iVar9 + 0x1c) >> 0x15 & 3;
          local_b0[9] = uVar20;
          local_88 = *(uint *)(iVar9 + 0x1c) >> 0x17 & 7;
          local_84 = *(undefined4 *)(*(int *)((int)local_c0 + iVar21) + 4);
          local_80 = (uint)*(ushort *)(iVar9 + 0x22);
          local_7c = **(undefined4 **)((int)local_c0 + iVar21);
          puVar15 = (undefined2 *)((int)local_5c + 2);
          local_78 = (uint)((*(uint *)(iVar9 + 0x1c) & 0x8000000) == 0);
          local_74 = 0;
          puVar17 = local_240;
          do {
            uVar16 = *(uint *)(puVar17 + 0xe0);
            *(uint *)(puVar17 + 0xe0) = uVar16 & 0xffffcfff;
            uVar7 = (*(uint *)(iVar10 + (int)piVar13) & 3) << 0x15;
            *(uint *)(puVar17 + 0xe0) = uVar7 | uVar16 & 0xff9fcfff;
            uVar6 = (*(uint *)(iVar10 + (int)puVar3) & 7) << 0x17;
            *(uint *)(puVar17 + 0xe0) = uVar6 | uVar7 | uVar16 & 0xfc1fcfff;
            uVar1 = *puVar15;
            puVar15 = puVar15 + 2;
            *(undefined2 *)(puVar17 + 0xe6) = uVar1;
            puVar2 = (uint *)(iVar10 + (int)puVar4);
            iVar10 = iVar10 + 4;
            *(uint *)(puVar17 + 0xe0) = (*puVar2 & 1) << 0x1b | uVar6 | uVar7 | uVar16 & 0xf41fcfff;
            puVar17 = puVar17 + 8;
          } while (puVar17 <= puVar5);
          uVar6 = *(uint *)(iVar9 + 0x1c);
          uVar7 = (local_168 >> 0x11 & 7) << 0x17;
          *(uint *)(iVar9 + 0x1c) = uVar7 | uVar6 & 0xfc7fffff;
          *(uint *)(iVar9 + 0x1c) = uVar20 << 0x15 | uVar7 | uVar6 & 0xfc1fffff | 0x8000000;
          *(undefined2 *)(iVar9 + 0x22) = uVar14;
          _PPStreamInsertOperationBeforeChunk(param_1,&local_170,0,0,iVar9);
        }
        iVar9 = *(int *)(iVar9 + 8);
      } while (iVar9 != *(int *)((int)local_b0 + iVar21 + 0x18));
    }
    uVar19 = uVar19 + 1;
    iVar21 = iVar21 + 4;
  } while (uVar19 < 2);
  uVar19 = 0;
  iVar21 = 0;
  do {
    if (*(int *)((int)local_b0 + iVar21 + 0x10) != 0) {
      _HashSetIteratorSetup(**(undefined4 **)((int)local_b0 + iVar21),&local_1a0);
      piVar13 = (int *)_HashSetIteratorNext(&local_1a0);
      while (piVar13 != (int *)0x0) {
        iVar9 = piVar13[1];
        local_160 = 0;
        local_178 = 0;
        local_174 = 0;
        local_170 = 0;
        local_16c = 0;
        local_168 = 0;
        local_164 = 0;
        local_15c = 0;
        local_190 = 0x20000000;
        local_160 = *(undefined4 *)(*(int *)((int)local_b0 + iVar21 + 0x10) + 0x3c);
        uVar7 = (*(uint *)(iVar9 + 0x10) & 3) << 10;
        uVar16 = uVar7 | 0x6c;
        uVar6 = *(uint *)(iVar9 + 0x10) & 3;
        if (uVar6 == 1) {
LAB_97c0c1d8:
          uVar16 = uVar16 | 0x4000;
LAB_97c0c1e0:
          uVar16 = uVar16 | 0x2000;
        }
        else {
          if (1 < uVar6) {
            if (uVar6 != 2) {
              if (uVar6 != 3) goto LAB_97c0c1e8;
              uVar16 = uVar7 | 0x1006c;
            }
            uVar16 = uVar16 | 0x8000;
            goto LAB_97c0c1d8;
          }
          if (uVar6 == 0) goto LAB_97c0c1e0;
        }
LAB_97c0c1e8:
        local_188 = (*(uint *)(iVar9 + 4) & 7) << 0x11 | uVar16;
        local_184 = (uint)*(ushort *)(iVar9 + 2);
        local_180 = (*(uint *)(*piVar13 + 4) & 7) << 0x17 |
                    ((uVar16 & 0xc00) >> 10) << 0xc | 0xd8000;
        local_17c = (uint)*(ushort *)(*piVar13 + 2);
        local_18c = (*(uint *)(iVar9 + 0x10) & 3) << 0x1a |
                    (*(uint *)(iVar9 + 0xc) & 7) << 0x17 | (*(uint *)(iVar9 + 8) & 3) << 0x12;
        _PPStreamInsertOperationAfterChunk
                  (param_1,&local_190,0,0,*(undefined4 *)((int)local_b0 + iVar21 + 0x10));
        piVar13 = (int *)_HashSetIteratorNext(&local_1a0);
      }
      _PPStreamRemoveOperation(param_1,*(undefined4 *)((int)local_b0 + iVar21 + 0x10));
    }
    uVar19 = uVar19 + 1;
    iVar21 = iVar21 + 4;
  } while (uVar19 < 2);
  _HashSetIteratorSetup(local_70[2],&local_150);
  iVar21 = _HashSetIteratorNext(&local_150);
  do {
    if (iVar21 == 0) {
      uVar19 = 0;
      iVar21 = 0;
      _PPStreamRemoveOperation(param_1,iStack00000024);
      do {
        if (*(undefined4 **)((int)local_b0 + iVar21) != (undefined4 *)0x0) {
          _HashSetIteratorSetup(**(undefined4 **)((int)local_b0 + iVar21),&local_130);
          puVar11 = (undefined4 *)_HashSetIteratorNext(&local_130);
          while (puVar11 != (undefined4 *)0x0) {
            _free((void *)*puVar11);
            _free((void *)puVar11[1]);
            puVar11 = (undefined4 *)_HashSetIteratorNext(&local_130);
          }
          _HashTableFree(*(undefined4 *)((int)local_b0 + iVar21));
          _HashTableFree(*(undefined4 *)((int)local_b0 + iVar21 + 8));
        }
        uVar19 = uVar19 + 1;
        iVar21 = iVar21 + 4;
      } while (uVar19 < 2);
      _HashSetFree(local_70[2]);
      return;
    }
    local_70[0] = 0;
    local_70[1] = 0;
    uVar19 = 0;
    iVar9 = 0;
    do {
      if (*(int *)((int)local_b0 + iVar9) != 0) {
        uVar8 = _HashTableGet(*(int *)((int)local_b0 + iVar9),iVar21);
        *(undefined4 *)((int)local_70 + iVar9) = uVar8;
      }
      uVar19 = uVar19 + 1;
      iVar9 = iVar9 + 4;
    } while (uVar19 < 2);
    uVar19 = 0;
    iVar9 = 0;
    do {
      iVar10 = *(int *)((int)local_70 + iVar9);
      if (*(int *)((int)local_70 + iVar9) == 0) {
        iVar10 = iVar21;
      }
      uVar19 = uVar19 + 1;
      *(int *)((int)local_70 + iVar9) = iVar10;
      iVar9 = iVar9 + 4;
    } while (uVar19 < 2);
    if (local_70[0] != local_70[1]) {
      local_12c = 0;
      local_fc = 0;
      local_130 = 0x60f80000;
      local_100 = *(undefined4 *)(iStack00000024 + 0x3c);
      local_120 = 0;
      local_11c = 0;
      local_118 = 0;
      local_114 = 0;
      local_110 = 0;
      local_10c = 0;
      local_108 = 0;
      local_104 = 0;
      uVar19 = (*(uint *)(iVar21 + 0x10) & 3) << 10;
      local_128 = uVar19 | 0x6c;
      uVar7 = *(uint *)(iVar21 + 0x10) & 3;
      if (uVar7 == 1) {
LAB_97c0c404:
        local_128 = local_128 | 0x4000;
LAB_97c0c40c:
        local_128 = local_128 | 0x2000;
      }
      else {
        if (1 < uVar7) {
          if (uVar7 != 2) {
            if (uVar7 != 3) goto LAB_97c0c414;
            local_128 = uVar19 | 0x1006c;
          }
          local_128 = local_128 | 0x8000;
          goto LAB_97c0c404;
        }
        if (uVar7 == 0) goto LAB_97c0c40c;
      }
LAB_97c0c414:
      local_128 = (*(uint *)(iVar21 + 4) & 7) << 0x11 | local_128;
      local_d0[2] = DAT_97c3aa3c;
      local_e0[2] = DAT_97c3aa3c;
      local_124 = (uint)*(ushort *)(iVar21 + 2);
      local_f0 = local_c0[0];
      local_ec = local_70[0];
      local_e8 = local_70[1];
      local_d0[0] = DAT_97c3aa34;
      local_d0[1] = DAT_97c3aa38;
      local_e0[0] = DAT_97c3aa34;
      local_e0[1] = DAT_97c3aa38;
      uVar19 = local_128;
      uVar7 = 0;
      do {
        (&local_120)[uVar7 * 2] = (uVar19 >> 10 & 3) << 0xc | (&local_120)[uVar7 * 2] & 0xffffcfff;
        uVar19 = uVar20;
        if (local_d0[uVar7] == 0) {
          uVar19 = 0;
        }
        (&local_120)[uVar7 * 2] = uVar19 << 0x15 | (&local_120)[uVar7 * 2] & 0xff9fffff;
        uVar19 = uVar20;
        if (local_d0[uVar7] == 0) {
          uVar19 = 1;
        }
        (&local_120)[uVar7 * 2] = uVar19 << 0x13 | (&local_120)[uVar7 * 2] & 0xffe7ffff;
        uVar19 = uVar20;
        if (local_d0[uVar7] == 0) {
          uVar19 = 2;
        }
        (&local_120)[uVar7 * 2] = uVar19 << 0x11 | (&local_120)[uVar7 * 2] & 0xfff9ffff;
        uVar19 = uVar20;
        if (local_d0[uVar7] == 0) {
          uVar19 = 3;
        }
        (&local_120)[uVar7 * 2] = uVar19 << 0xf | (&local_120)[uVar7 * 2] & 0xfffe7fff;
        uVar6 = uVar7 + 1;
        (&local_120)[uVar7 * 2] =
             (*(uint *)((&local_f0)[uVar7] + 4) & 7) << 0x17 | (&local_120)[uVar7 * 2] & 0xfc7fffff;
        (&uStack_11a)[uVar7 * 4] = *(undefined2 *)((&local_f0)[uVar7] + 2);
        (&local_120)[uVar7 * 2] =
             (local_e0[uVar7] & 1) << 0x1b | (&local_120)[uVar7 * 2] & 0xf7ffffff;
        uVar19 = local_128;
        uVar7 = uVar6;
      } while (uVar6 < 3);
      local_12c = (*(uint *)(iVar21 + 0x10) & 3) << 0x1a |
                  (*(uint *)(iVar21 + 0xc) & 7) << 0x17 | (*(uint *)(iVar21 + 8) & 3) << 0x12;
      _PPStreamInsertOperationAfterChunk(param_1,&local_130,0,0,iStack00000024);
    }
    iVar21 = _HashSetIteratorNext(&local_150);
  } while( true );
}

/* _IsBadUsage @ 0x97c0c670 (208 bytes) */
int _IsBadUsage(param_1)
  int param_1;
{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = _GetValidArgs(param_1);
  uVar4 = 0;
  if (0 < iVar1) {
    puVar2 = (uint *)(param_1 + 0x1c);
    do {
      uVar3 = *puVar2;
      puVar2 = puVar2 + 2;
      uVar4 = uVar4 | -(uVar3 >> 0x15 & 3) >> 0x1f | uVar3 >> 0x1b & 1 | uVar3 >> 0x1f |
              uVar3 >> 0xe & 1 | -(uVar3 >> 0xc & 3) >> 0x1f;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  uVar3 = *(uint *)(param_1 + 0x14);
  return uVar4 | *(uint *)(param_1 + 0x18) >> 0x1f | uVar3 >> 0xc & 1 |
         *(uint *)(param_1 + 0x10) >> 0x14 & 1 | -(uVar3 & 0x1c000) >> 0x1f |
         -(uVar3 >> 10 & 3) >> 0x1f;
}

/* _ClearDestedOpRegisters @ 0x97c0c740 (220 bytes) */
int _ClearDestedOpRegisters(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
  int param_4;
{
  void *pvVar1;
  uint uVar2;
  int iVar3;
  int local_60;
  uint local_5c;
  int local_30;
  int local_2c [5];
  
  if ((*(uint *)(param_3 + 0x14) & 0x1e000) != 0) {
    uVar2 = *(uint *)(param_3 + 0x14);
    _GetRegisterIndicies
              (param_1,&local_30,local_2c,uVar2 >> 0x11 & 7,*(uint *)(param_3 + 0x18) & 0xffff,
               *(uint *)(param_3 + 0x18) >> 0x1f,uVar2 >> 0xc & 1,uVar2 >> 10 & 3);
    if (local_30 <= local_2c[0]) {
      iVar3 = local_30;
      do {
        local_5c = *(uint *)(param_3 + 0x14) >> 0x11 & 7;
        local_60 = iVar3;
        pvVar1 = (void *)_HashSetGet(param_2,&local_60);
        if (pvVar1 != (void *)0x0) {
          if (param_4 == 0) {
            *(undefined4 *)((int)pvVar1 + 0x14) = 0;
          }
          else {
            _HashSetRemove(param_2,pvVar1);
            _free(pvVar1);
          }
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 <= local_2c[0]);
    }
  }
  return;
}

/* _ClearDestedRegisters @ 0x97c0c81c (92 bytes) */
int _ClearDestedRegisters(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
  int param_4;
{
  for (; param_3 != param_4; param_3 = *(int *)(param_3 + 8)) {
    ((int (*)())_ClearDestedOpRegisters)(param_1,param_2,param_3,1);
  }
  return;
}

/* _ClearRegisterState @ 0x97c0c878 (100 bytes) */
int _ClearRegisterState(param_1)
  undefined4 param_1;
{
  void *pvVar1;
  undefined1 auStack_20 [20];
  
  _HashSetIteratorSetup(param_1,auStack_20);
  pvVar1 = (void *)_HashSetIteratorNext(auStack_20);
  while (pvVar1 != (void *)0x0) {
    _HashSetRemove(param_1,pvVar1);
    _free(pvVar1);
    pvVar1 = (void *)_HashSetIteratorNext(auStack_20);
  }
  return;
}

/* _EmulateOp @ 0x97c0c8dc (8892 bytes) */
int _EmulateOp(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  undefined4 param_3;
{
  bool bVar1;
  bool bVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  bool bVar6;
  float fVar7;
  undefined4 uVar8;
  uint uVar9;
  float *pfVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  void *pvVar14;
  float *pfVar15;
  uint *puVar16;
  int *piVar17;
  int iVar18;
  float *pfVar19;
  uint *puVar20;
  float *pfVar21;
  float *pfVar22;
  double dVar23;
  double dVar24;
  double dVar25;
  int local_d0 [5];
  uint local_bc;
  undefined4 local_90;
  uint uStack_8c;
  longlong local_88;
  longlong local_80;
  longlong local_78;
  longlong local_70;
  float local_60;
  
  local_d0[3] = 0;
  local_d0[0] = 0;
  local_d0[1] = 0;
  local_d0[2] = 0;
  iVar18 = 0;
  iVar12 = _GetValidArgs(param_2);
  puVar16 = (uint *)(param_2 + 0xc);
  if (0 < iVar12) {
    piVar17 = local_d0 + 4;
    puVar20 = puVar16;
    do {
      local_d0[4] = (int)*(ushort *)((int)puVar20 + 0x16);
      local_bc = puVar20[4] >> 0x17 & 7;
      iVar13 = _HashSetGet(param_3,piVar17);
      local_d0[iVar18] = iVar13;
      if (iVar13 == 0) {
        ((int (*)())_GetRegisterTypeInfo)(param_1,piVar17);
        pvVar14 = _malloc(0x28);
        local_d0[iVar18] = (int)pvVar14;
        _memcpy(pvVar14,piVar17,0x28);
        _HashSetAdd(param_3,local_d0[iVar18]);
      }
      iVar18 = iVar18 + 1;
      puVar20 = puVar20 + 2;
    } while (iVar18 < iVar12);
  }
  pvVar14 = (void *)0x0;
  bVar1 = true;
  if ((*(uint *)(param_2 + 0x14) & 0x1e000) != 0) {
    local_d0[4] = (int)*(ushort *)(param_2 + 0x1a);
    piVar17 = local_d0 + 4;
    local_bc = *(uint *)(param_2 + 0x14) >> 0x11 & 7;
    pvVar14 = (void *)_HashSetGet(param_3,piVar17);
    bVar1 = false;
    if (pvVar14 == (void *)0x0) {
      ((int (*)())_GetRegisterTypeInfo)(param_1,piVar17);
      pvVar14 = _malloc(0x28);
      _memcpy(pvVar14,piVar17,0x28);
      _HashSetAdd(param_3,pvVar14);
      bVar1 = pvVar14 == (void *)0x0;
    }
  }
  if ((local_d0[0] == 0) ||
     (pfVar22 = (float *)(local_d0[0] + 0x18), *(int *)(local_d0[0] + 0x14) == 0)) {
    pfVar22 = (float *)0x0;
  }
  if ((local_d0[1] == 0) ||
     (pfVar19 = (float *)(local_d0[1] + 0x18), *(int *)(local_d0[1] + 0x14) == 0)) {
    pfVar19 = (float *)0x0;
  }
  if ((local_d0[2] == 0) ||
     (pfVar15 = (float *)(local_d0[2] + 0x18), *(int *)(local_d0[2] + 0x14) == 0)) {
    pfVar15 = (float *)0x0;
  }
  bVar6 = true;
  iVar18 = ((int (*)())_IsBadUsage)(param_2);
  dVar25 = DOUBLE_97c30a60;
  pfVar21 = (float *)((int)pvVar14 + 0x18);
  bVar2 = false;
  if (iVar18 != 0) goto LAB_97c0ee84;
  if (((iVar12 != 1) || (bVar1)) || (pfVar22 == (float *)0x0)) goto LAB_97c0d82c;
  bVar6 = false;
  switch(*puVar16 >> 0x12 & 0xff) {
  case 0:
    goto switchD_97c0cae8_caseD_0;
  case 1:
    *pfVar21 = 1.0;
    fVar7 = *pfVar22;
    fVar3 = fVar7;
    if (fVar7 <= TAllocation__guardBlockSize) {
      fVar7 = 0.0;
      fVar3 = local_60;
    }
    local_60 = fVar3;
    *(float *)((int)pvVar14 + 0x1c) = fVar7;
    fVar7 = TAllocation__guardBlockSize;
    if (TAllocation__guardBlockSize < *pfVar22) {
      dVar25 = _pow((double)pfVar22[1],(double)pfVar22[3]);
      fVar7 = (float)dVar25;
    }
    *(float *)((int)pvVar14 + 0x20) = fVar7;
LAB_97c0d000:
    uVar8 = 0x3f800000;
    goto LAB_97c0d128;
  case 2:
    *pfVar21 = ABS(*pfVar22);
    *(float *)((int)pvVar14 + 0x1c) = ABS(pfVar22[1]);
    *(float *)((int)pvVar14 + 0x20) = ABS(pfVar22[2]);
    fVar7 = ABS(pfVar22[3]);
    goto LAB_97c0ce78;
  case 3:
    dVar25 = _ceil((double)*pfVar22);
    *pfVar21 = (float)dVar25;
    dVar25 = _ceil((double)pfVar22[1]);
    *(float *)((int)pvVar14 + 0x1c) = (float)dVar25;
    dVar25 = _ceil((double)pfVar22[2]);
    *(float *)((int)pvVar14 + 0x20) = (float)dVar25;
    dVar25 = _ceil((double)pfVar22[3]);
    break;
  case 4:
    fVar7 = *pfVar22;
    dVar25 = _floor((double)fVar7);
    *pfVar21 = (float)((double)fVar7 - dVar25);
    fVar7 = pfVar22[1];
    dVar25 = _floor((double)fVar7);
    *(float *)((int)pvVar14 + 0x1c) = (float)((double)fVar7 - dVar25);
    fVar7 = pfVar22[2];
    dVar25 = _floor((double)fVar7);
    *(float *)((int)pvVar14 + 0x20) = (float)((double)fVar7 - dVar25);
    fVar7 = pfVar22[3];
    dVar25 = _floor((double)fVar7);
    *(float *)((int)pvVar14 + 0x24) = (float)((double)fVar7 - dVar25);
    goto LAB_97c0d82c;
  case 5:
    dVar25 = _floor((double)*pfVar22);
    *pfVar21 = (float)dVar25;
    dVar25 = _floor((double)pfVar22[1]);
    *(float *)((int)pvVar14 + 0x1c) = (float)dVar25;
    dVar25 = _floor((double)pfVar22[2]);
    *(float *)((int)pvVar14 + 0x20) = (float)dVar25;
    dVar25 = _floor((double)pfVar22[3]);
    break;
  default:
    bVar6 = true;
    goto LAB_97c0d82c;
  case 7:
    if (*pfVar22 <= TAllocation__guardBlockSize) {
      if (TAllocation__guardBlockSize <= *pfVar22) {
        fVar7 = 0.0;
      }
      else {
        fVar7 = -1.0;
      }
    }
    else {
      fVar7 = 1.0;
    }
    *pfVar21 = fVar7;
    if (pfVar22[1] <= TAllocation__guardBlockSize) {
      if (TAllocation__guardBlockSize <= pfVar22[1]) {
        uVar8 = 0;
      }
      else {
        uVar8 = 0xbf800000;
      }
    }
    else {
      uVar8 = 0x3f800000;
    }
    *(undefined4 *)((int)pvVar14 + 0x1c) = uVar8;
    if (pfVar22[2] <= TAllocation__guardBlockSize) {
      if (TAllocation__guardBlockSize <= pfVar22[2]) {
        uVar8 = 0;
      }
      else {
        uVar8 = 0xbf800000;
      }
    }
    else {
      uVar8 = 0x3f800000;
    }
    *(undefined4 *)((int)pvVar14 + 0x20) = uVar8;
    if (TAllocation__guardBlockSize < pfVar22[3]) goto LAB_97c0d000;
    if (TAllocation__guardBlockSize <= pfVar22[3]) goto LAB_97c0d124;
    uVar8 = 0xbf800000;
    goto LAB_97c0d128;
  case 8:
    if (((*pfVar22 == TAllocation__guardBlockSize) && (pfVar22[1] == TAllocation__guardBlockSize))
       && (pfVar22[2] == TAllocation__guardBlockSize)) {
LAB_97c0d078:
      uStack_8c = 0;
      if (pfVar22[3] == TAllocation__guardBlockSize) goto LAB_97c0d088;
    }
    uStack_8c = 1;
    goto LAB_97c0d088;
  case 9:
    uStack_8c = 0;
    if (((*pfVar22 != TAllocation__guardBlockSize) && (pfVar22[1] != TAllocation__guardBlockSize))
       && (pfVar22[2] != TAllocation__guardBlockSize)) goto LAB_97c0d078;
LAB_97c0d088:
    uStack_8c = uStack_8c ^ 0x80000000;
    local_90 = 0x43300000;
    dVar25 = (double)CONCAT44(0x43300000,uStack_8c) - DOUBLE_97c30a58;
LAB_97c0d214:
    fVar7 = (float)dVar25;
    goto LAB_97c0d71c;
  case 10:
    fVar7 = 1.0;
    if (*pfVar22 != TAllocation__guardBlockSize) {
      fVar7 = 0.0;
    }
    *pfVar21 = fVar7;
    uVar8 = 0x3f800000;
    if (pfVar22[1] != TAllocation__guardBlockSize) {
      uVar8 = 0;
    }
    *(undefined4 *)((int)pvVar14 + 0x1c) = uVar8;
    uVar8 = 0x3f800000;
    if (pfVar22[2] != TAllocation__guardBlockSize) {
      uVar8 = 0;
    }
    *(undefined4 *)((int)pvVar14 + 0x20) = uVar8;
    uVar8 = 0x3f800000;
    if (pfVar22[3] != TAllocation__guardBlockSize) {
LAB_97c0d124:
      uVar8 = 0;
    }
LAB_97c0d128:
    *(undefined4 *)((int)pvVar14 + 0x24) = uVar8;
    goto LAB_97c0d82c;
  case 0xc:
    dVar25 = _sqrt(ABS((double)*pfVar22));
    *pfVar21 = (float)dVar25;
    dVar25 = _sqrt(ABS((double)pfVar22[1]));
    *(float *)((int)pvVar14 + 0x1c) = (float)dVar25;
    dVar25 = _sqrt(ABS((double)pfVar22[2]));
    *(float *)((int)pvVar14 + 0x20) = (float)dVar25;
    dVar25 = _sqrt(ABS((double)pfVar22[3]));
    break;
  case 0xd:
    if (*param_1 - 0x8b30U < 2) {
      dVar23 = _sqrt(ABS((double)*pfVar22));
      *pfVar21 = (float)(dVar25 / dVar23);
      dVar23 = _sqrt(ABS((double)pfVar22[1]));
      *(float *)((int)pvVar14 + 0x1c) = (float)(dVar25 / dVar23);
      dVar23 = _sqrt(ABS((double)pfVar22[2]));
      *(float *)((int)pvVar14 + 0x20) = (float)(dVar25 / dVar23);
      dVar23 = _sqrt(ABS((double)pfVar22[3]));
      *(float *)((int)pvVar14 + 0x24) = (float)(dVar25 / dVar23);
      goto LAB_97c0d82c;
    }
    dVar25 = _sqrt(ABS((double)pfVar22[3]));
    dVar25 = DOUBLE_97c30a60 / dVar25;
    goto LAB_97c0d214;
  case 0xe:
    fVar7 = FLOAT_97c3acd8 / pfVar22[3];
    goto LAB_97c0d71c;
  case 0xf:
    fVar3 = pfVar22[3];
    fVar7 = FLOAT_97c3ace0;
    if ((fVar3 <= FLOAT_97c3acdc) &&
       ((FLOAT_97c3ace0 <= fVar3 ||
        (((fVar7 = FLOAT_97c3acdc, fVar3 < TAllocation__guardBlockSize &&
          (fVar7 = FLOAT_97c3ace8, fVar3 <= FLOAT_97c3ace4)) &&
         (fVar7 = FLOAT_97c3ace4, FLOAT_97c3ace8 <= fVar3)))))) {
      fVar7 = FLOAT_97c3acd8 / fVar3;
    }
    goto LAB_97c0d71c;
  case 0x10:
    if (1 < *param_1 - 0x8b30U) {
      dVar25 = _exp2((double)pfVar22[3]);
      goto LAB_97c0d718;
    }
    dVar25 = _exp2((double)*pfVar22);
    *pfVar21 = (float)dVar25;
    dVar25 = _exp2((double)pfVar22[1]);
    *(float *)((int)pvVar14 + 0x1c) = (float)dVar25;
    dVar25 = _exp2((double)pfVar22[2]);
    *(float *)((int)pvVar14 + 0x20) = (float)dVar25;
    dVar25 = _exp2((double)pfVar22[3]);
    break;
  case 0x11:
    dVar25 = _floor((double)pfVar22[3]);
    dVar23 = _exp2((double)(float)dVar25);
    *pfVar21 = (float)dVar23;
    *(float *)((int)pvVar14 + 0x1c) = (float)((double)pfVar22[3] - (double)(float)dVar25);
    dVar25 = _exp2((double)pfVar22[3]);
    goto LAB_97c0d51c;
  case 0x12:
    dVar25 = (double)TAllocation__guardBlockSize;
    uVar9 = *(uint *)(param_2 + 0x10) >> 0x1a & 3;
    if (uVar9 != 0xffffffff) {
      iVar18 = uVar9 + 1;
      pfVar10 = pfVar22;
      do {
        fVar7 = *pfVar10;
        pfVar10 = pfVar10 + 1;
        dVar25 = (double)(float)((double)fVar7 * (double)fVar7 + dVar25);
        iVar18 = iVar18 + -1;
      } while (iVar18 != 0);
    }
    dVar25 = _sqrt(dVar25);
LAB_97c0d718:
    fVar7 = (float)dVar25;
LAB_97c0d71c:
    *(float *)((int)pvVar14 + 0x24) = fVar7;
    *pfVar21 = fVar7;
    *(float *)((int)pvVar14 + 0x1c) = fVar7;
    *(float *)((int)pvVar14 + 0x20) = fVar7;
    goto LAB_97c0d82c;
  case 0x13:
    if (1 < *param_1 - 0x8b30U) {
      dVar25 = (double)pfVar22[3];
      if ((double)pfVar22[3] < (double)TAllocation__guardBlockSize) {
        dVar25 = DOUBLE_97c30a48;
      }
      dVar25 = _log2(dVar25);
      goto LAB_97c0d718;
    }
    dVar25 = (double)*pfVar22;
    if ((double)*pfVar22 < (double)TAllocation__guardBlockSize) {
      dVar25 = DOUBLE_97c30a48;
    }
    dVar25 = _log2(dVar25);
    dVar23 = (double)TAllocation__guardBlockSize;
    *pfVar21 = (float)dVar25;
    dVar25 = (double)pfVar22[1];
    if ((double)pfVar22[1] < dVar23) {
      dVar25 = DOUBLE_97c30a48;
    }
    dVar25 = _log2(dVar25);
    dVar23 = (double)TAllocation__guardBlockSize;
    *(float *)((int)pvVar14 + 0x1c) = (float)dVar25;
    dVar25 = (double)pfVar22[2];
    if ((double)pfVar22[2] < dVar23) {
      dVar25 = DOUBLE_97c30a48;
    }
    dVar25 = _log2(dVar25);
    dVar23 = (double)TAllocation__guardBlockSize;
    *(float *)((int)pvVar14 + 0x20) = (float)dVar25;
    dVar25 = (double)pfVar22[3];
    if ((double)pfVar22[3] < dVar23) {
      dVar25 = DOUBLE_97c30a48;
    }
    dVar25 = _log2(dVar25);
    break;
  case 0x14:
    dVar25 = ABS((double)pfVar22[3]);
    dVar23 = _log2(dVar25);
    dVar23 = _floor(dVar23);
    *pfVar21 = (float)dVar23;
    dVar24 = _exp2((double)(float)dVar23);
    dVar23 = (double)TAllocation__guardBlockSize;
    *(float *)((int)pvVar14 + 0x1c) = (float)(dVar25 / dVar24);
    if (dVar25 < dVar23) {
      dVar25 = DOUBLE_97c30a48;
    }
    dVar25 = _log2(dVar25);
LAB_97c0d51c:
    *(undefined4 *)((int)pvVar14 + 0x24) = 0x3f800000;
    *(float *)((int)pvVar14 + 0x20) = (float)dVar25;
    goto LAB_97c0d82c;
  case 0x15:
    dVar25 = (double)TAllocation__guardBlockSize;
    uVar9 = *(uint *)(param_2 + 0x10) >> 0x1a & 3;
    if (uVar9 != 0xffffffff) {
      iVar18 = uVar9 + 1;
      pfVar10 = pfVar22;
      do {
        fVar7 = *pfVar10;
        pfVar10 = pfVar10 + 1;
        dVar25 = (double)(float)((double)fVar7 * (double)fVar7 + dVar25);
        iVar18 = iVar18 + -1;
      } while (iVar18 != 0);
    }
    dVar25 = _sqrt(dVar25);
    iVar18 = 0;
    if ((*(uint *)(param_2 + 0x10) >> 0x1a & 3) != 0xffffffff) {
      do {
        iVar13 = iVar18 + 1;
        pfVar21[iVar18] = pfVar22[iVar18] / (float)dVar25;
        iVar18 = iVar13;
      } while (iVar13 < (int)((*(uint *)(param_2 + 0x10) >> 0x1a & 3) + 1));
    }
    goto LAB_97c0d82c;
  case 0x16:
    fVar7 = FLOAT_97c3acd0;
    goto LAB_97c0d600;
  case 0x17:
    fVar7 = FLOAT_97c3acd4;
LAB_97c0d600:
    *pfVar21 = *pfVar22 * fVar7;
    *(float *)((int)pvVar14 + 0x1c) = pfVar22[1] * fVar7;
    *(float *)((int)pvVar14 + 0x20) = pfVar22[2] * fVar7;
    *(float *)((int)pvVar14 + 0x24) = pfVar22[3] * fVar7;
    goto LAB_97c0d82c;
  case 0x18:
    dVar25 = _cos((double)*pfVar22);
    *pfVar21 = (float)dVar25;
    dVar25 = _sin((double)*pfVar22);
    *(undefined4 *)((int)pvVar14 + 0x24) = 0;
    *(undefined4 *)((int)pvVar14 + 0x20) = 0;
    *(float *)((int)pvVar14 + 0x1c) = (float)dVar25;
    goto LAB_97c0d82c;
  case 0x19:
    if (1 < *param_1 - 0x8b30U) {
      dVar25 = _sin((double)pfVar22[3]);
      goto LAB_97c0d718;
    }
    dVar25 = _sin((double)*pfVar22);
    *pfVar21 = (float)dVar25;
    dVar25 = _sin((double)pfVar22[1]);
    *(float *)((int)pvVar14 + 0x1c) = (float)dVar25;
    dVar25 = _sin((double)pfVar22[2]);
    *(float *)((int)pvVar14 + 0x20) = (float)dVar25;
    dVar25 = _sin((double)pfVar22[3]);
    break;
  case 0x1a:
    if (1 < *param_1 - 0x8b30U) {
      dVar25 = _cos((double)pfVar22[3]);
      goto LAB_97c0d718;
    }
    dVar25 = _cos((double)*pfVar22);
    *pfVar21 = (float)dVar25;
    dVar25 = _cos((double)pfVar22[1]);
    *(float *)((int)pvVar14 + 0x1c) = (float)dVar25;
    dVar25 = _cos((double)pfVar22[2]);
    *(float *)((int)pvVar14 + 0x20) = (float)dVar25;
    dVar25 = _cos((double)pfVar22[3]);
    break;
  case 0x1b:
    dVar25 = _tan((double)*pfVar22);
    *pfVar21 = (float)dVar25;
    dVar25 = _tan((double)pfVar22[1]);
    *(float *)((int)pvVar14 + 0x1c) = (float)dVar25;
    dVar25 = _tan((double)pfVar22[2]);
    *(float *)((int)pvVar14 + 0x20) = (float)dVar25;
    dVar25 = _tan((double)pfVar22[3]);
    break;
  case 0x1c:
    dVar25 = _asin((double)*pfVar22);
    *pfVar21 = (float)dVar25;
    dVar25 = _asin((double)pfVar22[1]);
    *(float *)((int)pvVar14 + 0x1c) = (float)dVar25;
    dVar25 = _asin((double)pfVar22[2]);
    *(float *)((int)pvVar14 + 0x20) = (float)dVar25;
    dVar25 = _asin((double)pfVar22[3]);
    break;
  case 0x1d:
    dVar25 = _acos((double)*pfVar22);
    *pfVar21 = (float)dVar25;
    dVar25 = _acos((double)pfVar22[1]);
    *(float *)((int)pvVar14 + 0x1c) = (float)dVar25;
    dVar25 = _acos((double)pfVar22[2]);
    *(float *)((int)pvVar14 + 0x20) = (float)dVar25;
    dVar25 = _acos((double)pfVar22[3]);
    break;
  case 0x1e:
    dVar25 = _atan((double)*pfVar22);
    *pfVar21 = (float)dVar25;
    dVar25 = _atan((double)pfVar22[1]);
    *(float *)((int)pvVar14 + 0x1c) = (float)dVar25;
    dVar25 = _atan((double)pfVar22[2]);
    *(float *)((int)pvVar14 + 0x20) = (float)dVar25;
    dVar25 = _atan((double)pfVar22[3]);
    break;
  case 0x48:
    *pfVar21 = *pfVar22;
    *(float *)((int)pvVar14 + 0x1c) = *pfVar22;
    *(float *)((int)pvVar14 + 0x20) = *pfVar22;
    fVar7 = *pfVar22;
    goto LAB_97c0ce78;
  case 0x6c:
    if ((*(int *)((int)pvVar14 + 0xc) == 3) && (*(int *)(local_d0[0] + 0xc) == 1)) {
      dVar25 = _trunc((double)*pfVar22);
      *pfVar21 = (float)dVar25;
      dVar25 = _trunc((double)pfVar22[1]);
      *(float *)((int)pvVar14 + 0x1c) = (float)dVar25;
      dVar25 = _trunc((double)pfVar22[2]);
      *(float *)((int)pvVar14 + 0x20) = (float)dVar25;
      dVar25 = _trunc((double)pfVar22[3]);
      break;
    }
    if ((*(int *)((int)pvVar14 + 0xc) == 4) &&
       ((*(int *)(local_d0[0] + 0xc) == 1 || (*(int *)(local_d0[0] + 0xc) == 3)))) {
      fVar7 = 1.0;
      if (*pfVar22 == TAllocation__guardBlockSize) {
        fVar7 = 0.0;
      }
      *pfVar21 = fVar7;
      uVar8 = 0x3f800000;
      if (pfVar22[1] == TAllocation__guardBlockSize) {
        uVar8 = 0;
      }
      *(undefined4 *)((int)pvVar14 + 0x1c) = uVar8;
      uVar8 = 0x3f800000;
      if (pfVar22[2] == TAllocation__guardBlockSize) {
        uVar8 = 0;
      }
      *(undefined4 *)((int)pvVar14 + 0x20) = uVar8;
      uVar8 = 0x3f800000;
      if (pfVar22[3] == TAllocation__guardBlockSize) goto LAB_97c0d124;
      goto LAB_97c0d128;
    }
    goto switchD_97c0cae8_caseD_0;
  case 0x6f:
    dVar25 = _exp((double)*pfVar22);
    *pfVar21 = (float)dVar25;
    dVar25 = _exp((double)pfVar22[1]);
    *(float *)((int)pvVar14 + 0x1c) = (float)dVar25;
    dVar25 = _exp((double)pfVar22[2]);
    *(float *)((int)pvVar14 + 0x20) = (float)dVar25;
    dVar25 = _exp((double)pfVar22[3]);
    break;
  case 0x70:
    dVar25 = _log((double)*pfVar22);
    *pfVar21 = (float)dVar25;
    dVar25 = _log((double)pfVar22[1]);
    *(float *)((int)pvVar14 + 0x1c) = (float)dVar25;
    dVar25 = _log((double)pfVar22[2]);
    *(float *)((int)pvVar14 + 0x20) = (float)dVar25;
    dVar25 = _log((double)pfVar22[3]);
  }
  *(float *)((int)pvVar14 + 0x24) = (float)dVar25;
LAB_97c0d82c:
  fVar7 = TAllocation__guardBlockSize;
  dVar25 = DOUBLE_97c30a78;
  if (!bVar6) goto LAB_97c0eea8;
  bVar6 = false;
  if ((((iVar12 != 2) || (bVar1)) || (pfVar22 == (float *)0x0)) || (pfVar19 == (float *)0x0))
  goto LAB_97c0e77c;
  bVar6 = false;
  switch(*puVar16 >> 0x12 & 0xff) {
  case 0x1e:
    fVar7 = _atan2f(*pfVar22,*pfVar19);
    *pfVar21 = fVar7;
    fVar7 = _atan2f(pfVar22[1],pfVar19[1]);
    *(float *)((int)pvVar14 + 0x1c) = fVar7;
    fVar7 = _atan2f(pfVar22[2],pfVar19[2]);
    *(float *)((int)pvVar14 + 0x20) = fVar7;
    fVar7 = _atan2f(pfVar22[3],pfVar19[3]);
    *(float *)((int)pvVar14 + 0x24) = fVar7;
    goto LAB_97c0e778;
  case 0x1f:
    *pfVar21 = *pfVar22 + *pfVar19;
    *(float *)((int)pvVar14 + 0x1c) = pfVar22[1] + pfVar19[1];
    *(float *)((int)pvVar14 + 0x20) = pfVar22[2] + pfVar19[2];
    fVar7 = pfVar22[3] + pfVar19[3];
    goto LAB_97c0e6f8;
  case 0x20:
    *pfVar21 = *pfVar22 - *pfVar19;
    *(float *)((int)pvVar14 + 0x1c) = pfVar22[1] - pfVar19[1];
    *(float *)((int)pvVar14 + 0x20) = pfVar22[2] - pfVar19[2];
    fVar7 = pfVar22[3] - pfVar19[3];
    goto LAB_97c0e6f8;
  default:
    bVar6 = true;
    goto LAB_97c0e778;
  case 0x22:
  case 0x23:
    *pfVar21 = *pfVar22 * *pfVar19;
    *(float *)((int)pvVar14 + 0x1c) = pfVar22[1] * pfVar19[1];
    *(float *)((int)pvVar14 + 0x20) = pfVar22[2] * pfVar19[2];
    fVar7 = pfVar22[3] * pfVar19[3];
    goto LAB_97c0e6f8;
  case 0x24:
    uVar9 = 0;
    if ((*pfVar22 != TAllocation__guardBlockSize) && (*pfVar19 != TAllocation__guardBlockSize)) {
      uVar9 = 1;
    }
    uVar11 = 0;
    *pfVar21 = (float)((double)CONCAT44(0x43300000,uVar9 ^ 0x80000000) - DOUBLE_97c30a58);
    fVar3 = TAllocation__guardBlockSize;
    if ((pfVar22[1] != fVar7) && (pfVar19[1] != fVar7)) {
      uVar11 = 1;
    }
    uVar9 = 0;
    *(float *)((int)pvVar14 + 0x1c) =
         (float)((double)CONCAT44(0x43300000,uVar11 ^ 0x80000000) - DOUBLE_97c30a58);
    fVar7 = TAllocation__guardBlockSize;
    if ((pfVar22[2] != fVar3) && (pfVar19[2] != fVar3)) {
      uVar9 = 1;
    }
    uStack_8c = 0;
    *(float *)((int)pvVar14 + 0x20) =
         (float)((double)CONCAT44(0x43300000,uVar9 ^ 0x80000000) - DOUBLE_97c30a58);
    if (pfVar22[3] != fVar7) {
LAB_97c0de28:
      uStack_8c = 0;
      if (pfVar19[3] != fVar7) goto LAB_97c0de44;
    }
    goto LAB_97c0de48;
  case 0x25:
    uVar9 = 0;
    if ((*pfVar22 != TAllocation__guardBlockSize) || (*pfVar19 != TAllocation__guardBlockSize)) {
      uVar9 = 1;
    }
    uVar11 = 0;
    *pfVar21 = (float)((double)CONCAT44(0x43300000,uVar9 ^ 0x80000000) - DOUBLE_97c30a58);
    fVar3 = TAllocation__guardBlockSize;
    if ((pfVar22[1] != fVar7) || (pfVar19[1] != fVar7)) {
      uVar11 = 1;
    }
    uVar9 = 0;
    *(float *)((int)pvVar14 + 0x1c) =
         (float)((double)CONCAT44(0x43300000,uVar11 ^ 0x80000000) - DOUBLE_97c30a58);
    fVar7 = TAllocation__guardBlockSize;
    if ((pfVar22[2] != fVar3) || (pfVar19[2] != fVar3)) {
      uVar9 = 1;
    }
    *(float *)((int)pvVar14 + 0x20) =
         (float)((double)CONCAT44(0x43300000,uVar9 ^ 0x80000000) - DOUBLE_97c30a58);
    if (pfVar22[3] == fVar7) goto LAB_97c0de28;
LAB_97c0de44:
    uStack_8c = 1;
    goto LAB_97c0de48;
  case 0x26:
    uVar9 = 0;
    if (*pfVar22 == TAllocation__guardBlockSize) {
      if (*pfVar19 != TAllocation__guardBlockSize) {
LAB_97c0dd24:
        uVar9 = 1;
      }
    }
    else if (*pfVar19 == TAllocation__guardBlockSize) goto LAB_97c0dd24;
    uVar11 = 0;
    *pfVar21 = (float)((double)CONCAT44(0x43300000,uVar9 ^ 0x80000000) - DOUBLE_97c30a58);
    fVar3 = TAllocation__guardBlockSize;
    if (pfVar22[1] == fVar7) {
      if (pfVar19[1] != fVar7) {
LAB_97c0dd84:
        uVar11 = 1;
      }
    }
    else if (pfVar19[1] == fVar7) goto LAB_97c0dd84;
    uVar9 = 0;
    *(float *)((int)pvVar14 + 0x1c) =
         (float)((double)CONCAT44(0x43300000,uVar11 ^ 0x80000000) - DOUBLE_97c30a58);
    fVar7 = TAllocation__guardBlockSize;
    if (pfVar22[2] == fVar3) {
      if (pfVar19[2] != fVar3) {
LAB_97c0dde4:
        uVar9 = 1;
      }
    }
    else if (pfVar19[2] == fVar3) goto LAB_97c0dde4;
    uStack_8c = 0;
    *(float *)((int)pvVar14 + 0x20) =
         (float)((double)CONCAT44(0x43300000,uVar9 ^ 0x80000000) - DOUBLE_97c30a58);
    if (pfVar22[3] == fVar7) goto LAB_97c0de28;
    if (pfVar19[3] == fVar7) goto LAB_97c0de44;
LAB_97c0de48:
    uStack_8c = uStack_8c ^ 0x80000000;
    local_90 = 0x43300000;
    fVar7 = (float)((double)CONCAT44(0x43300000,uStack_8c) - DOUBLE_97c30a58);
    goto LAB_97c0e6f8;
  case 0x27:
    iVar18 = 0;
    for (iVar13 = (*(uint *)(param_2 + 0x10) >> 0x1a & 3) + 1; iVar13 != 0; iVar13 = iVar13 + -1) {
      fVar7 = pfVar22[iVar18] * pfVar19[iVar18] + fVar7;
      iVar18 = iVar18 + 1;
    }
    goto LAB_97c0e18c;
  case 0x28:
    fVar7 = pfVar22[2] * pfVar19[2] + *pfVar22 * *pfVar19 + pfVar22[1] * pfVar19[1];
    goto LAB_97c0e4e0;
  case 0x29:
    fVar7 = pfVar22[3] * pfVar19[3] +
            pfVar22[2] * pfVar19[2] + *pfVar22 * *pfVar19 + pfVar22[1] * pfVar19[1];
    goto LAB_97c0e4e0;
  case 0x2a:
    fVar7 = pfVar22[2] * pfVar19[2] + *pfVar22 * *pfVar19 + pfVar22[1] * pfVar19[1] + pfVar19[3];
LAB_97c0e4e0:
    bVar6 = true;
    *(float *)((int)pvVar14 + 0x24) = fVar7;
    *pfVar21 = fVar7;
    *(float *)((int)pvVar14 + 0x1c) = fVar7;
    *(float *)((int)pvVar14 + 0x20) = fVar7;
    break;
  case 0x2b:
    if (*param_1 - 0x8b30U < 2) {
      iVar18 = 0;
      fVar7 = TAllocation__guardBlockSize;
      for (iVar13 = (*(uint *)(param_2 + 0x10) >> 0x1a & 3) + 1; iVar13 != 0; iVar13 = iVar13 + -1)
      {
        fVar7 = (float)((double)(pfVar22[iVar18] - pfVar19[iVar18]) *
                        (double)(pfVar22[iVar18] - pfVar19[iVar18]) + (double)fVar7);
        iVar18 = iVar18 + 1;
      }
      dVar25 = _sqrt((double)fVar7);
LAB_97c0e4d8:
      fVar7 = (float)dVar25;
      goto LAB_97c0e4e0;
    }
    *pfVar21 = 1.0;
    *(float *)((int)pvVar14 + 0x1c) = pfVar22[1] * pfVar19[1];
    *(float *)((int)pvVar14 + 0x20) = pfVar22[2];
    fVar7 = pfVar19[3];
    goto LAB_97c0e6f8;
  case 0x2c:
    fVar7 = *pfVar19;
    if (*pfVar22 < *pfVar19) {
      fVar7 = *pfVar22;
    }
    *pfVar21 = fVar7;
    fVar7 = pfVar19[1];
    if (pfVar22[1] < pfVar19[1]) {
      fVar7 = pfVar22[1];
    }
    *(float *)((int)pvVar14 + 0x1c) = fVar7;
    fVar7 = pfVar19[2];
    if (pfVar22[2] < pfVar19[2]) {
      fVar7 = pfVar22[2];
    }
    *(float *)((int)pvVar14 + 0x20) = fVar7;
    fVar3 = pfVar22[3];
    fVar7 = pfVar19[3];
    if (fVar3 < fVar7) {
LAB_97c0e08c:
      fVar7 = fVar3;
    }
    goto LAB_97c0e090;
  case 0x2d:
    fVar7 = *pfVar19;
    if (*pfVar19 < *pfVar22) {
      fVar7 = *pfVar22;
    }
    *pfVar21 = fVar7;
    fVar7 = pfVar19[1];
    if (pfVar19[1] < pfVar22[1]) {
      fVar7 = pfVar22[1];
    }
    *(float *)((int)pvVar14 + 0x1c) = fVar7;
    fVar7 = pfVar19[2];
    if (pfVar19[2] < pfVar22[2]) {
      fVar7 = pfVar22[2];
    }
    *(float *)((int)pvVar14 + 0x20) = fVar7;
    fVar3 = pfVar22[3];
    fVar7 = pfVar19[3];
    if (pfVar19[3] < fVar3) goto LAB_97c0e08c;
LAB_97c0e090:
    *(float *)((int)pvVar14 + 0x24) = fVar7;
    goto LAB_97c0e778;
  case 0x2e:
    bVar6 = true;
    *pfVar21 = pfVar22[1] * pfVar19[2] - pfVar19[1] * pfVar22[2];
    *(float *)((int)pvVar14 + 0x1c) = pfVar22[2] * *pfVar19 - pfVar19[2] * *pfVar22;
    fVar7 = *pfVar19;
    fVar3 = pfVar22[1];
    fVar4 = *pfVar22;
    fVar5 = pfVar19[1];
    *(undefined4 *)((int)pvVar14 + 0x24) = 0;
    *(float *)((int)pvVar14 + 0x20) = fVar4 * fVar5 - fVar7 * fVar3;
    break;
  case 0x2f:
    iVar18 = 0;
    fVar7 = TAllocation__guardBlockSize;
    for (iVar13 = (*(uint *)(param_2 + 0x10) >> 0x1a & 3) + 1; iVar13 != 0; iVar13 = iVar13 + -1) {
      fVar7 = pfVar22[iVar18] * pfVar19[iVar18] + fVar7;
      iVar18 = iVar18 + 1;
    }
    fVar7 = fVar7 + fVar7;
    bVar6 = true;
    *pfVar21 = -(fVar7 * *pfVar19 - *pfVar22);
    *(float *)((int)pvVar14 + 0x1c) = -(fVar7 * pfVar19[1] - pfVar22[1]);
    *(float *)((int)pvVar14 + 0x20) = -(fVar7 * pfVar19[2] - pfVar22[2]);
    *(float *)((int)pvVar14 + 0x24) = -(fVar7 * pfVar19[3] - pfVar22[3]);
    break;
  case 0x30:
    fVar7 = FLOAT_97c3acd8;
    goto LAB_97c0e18c;
  case 0x31:
    fVar7 = 1.0;
    if (*pfVar22 != *pfVar19) {
      fVar7 = 0.0;
    }
    *pfVar21 = fVar7;
    uVar8 = 0x3f800000;
    if (pfVar22[1] != pfVar19[1]) {
      uVar8 = 0;
    }
    *(undefined4 *)((int)pvVar14 + 0x1c) = uVar8;
    uVar8 = 0x3f800000;
    if (pfVar22[2] != pfVar19[2]) {
      uVar8 = 0;
    }
    *(undefined4 *)((int)pvVar14 + 0x20) = uVar8;
    uVar8 = 0x3f800000;
    if (pfVar22[3] != pfVar19[3]) goto LAB_97c0e454;
    goto LAB_97c0e458;
  case 0x32:
    fVar7 = 1.0;
    if (*pfVar22 < *pfVar19) {
      fVar7 = 0.0;
    }
    *pfVar21 = fVar7;
    uVar8 = 0x3f800000;
    if (pfVar22[1] < pfVar19[1]) {
      uVar8 = 0;
    }
    *(undefined4 *)((int)pvVar14 + 0x1c) = uVar8;
    uVar8 = 0x3f800000;
    if (pfVar22[2] < pfVar19[2]) {
      uVar8 = 0;
    }
    *(undefined4 *)((int)pvVar14 + 0x20) = uVar8;
    bVar2 = pfVar19[3] <= pfVar22[3];
    goto LAB_97c0e36c;
  case 0x33:
    if (*pfVar22 <= *pfVar19) {
      fVar7 = 0.0;
    }
    else {
      fVar7 = 1.0;
    }
    *pfVar21 = fVar7;
    if (pfVar22[1] <= pfVar19[1]) {
      uVar8 = 0;
    }
    else {
      uVar8 = 0x3f800000;
    }
    *(undefined4 *)((int)pvVar14 + 0x1c) = uVar8;
    if (pfVar22[2] <= pfVar19[2]) {
      uVar8 = 0;
    }
    else {
      uVar8 = 0x3f800000;
    }
    *(undefined4 *)((int)pvVar14 + 0x20) = uVar8;
    if (pfVar19[3] < pfVar22[3]) {
LAB_97c0e3e4:
      uVar8 = 0x3f800000;
      goto LAB_97c0e458;
    }
    goto LAB_97c0e454;
  case 0x34:
    fVar7 = 1.0;
    if (*pfVar19 < *pfVar22) {
      fVar7 = 0.0;
    }
    *pfVar21 = fVar7;
    uVar8 = 0x3f800000;
    if (pfVar19[1] < pfVar22[1]) {
      uVar8 = 0;
    }
    *(undefined4 *)((int)pvVar14 + 0x1c) = uVar8;
    uVar8 = 0x3f800000;
    if (pfVar19[2] < pfVar22[2]) {
      uVar8 = 0;
    }
    *(undefined4 *)((int)pvVar14 + 0x20) = uVar8;
    bVar2 = pfVar22[3] <= pfVar19[3];
LAB_97c0e36c:
    uVar8 = 0x3f800000;
    if (!bVar2) goto LAB_97c0e454;
    goto LAB_97c0e458;
  case 0x35:
    if (*pfVar19 <= *pfVar22) {
      fVar7 = 0.0;
    }
    else {
      fVar7 = 1.0;
    }
    *pfVar21 = fVar7;
    if (pfVar19[1] <= pfVar22[1]) {
      uVar8 = 0;
    }
    else {
      uVar8 = 0x3f800000;
    }
    *(undefined4 *)((int)pvVar14 + 0x1c) = uVar8;
    if (pfVar19[2] <= pfVar22[2]) {
      uVar8 = 0;
    }
    else {
      uVar8 = 0x3f800000;
    }
    *(undefined4 *)((int)pvVar14 + 0x20) = uVar8;
    if (pfVar22[3] < pfVar19[3]) goto LAB_97c0e3e4;
    goto LAB_97c0e454;
  case 0x36:
    fVar7 = 1.0;
    if (*pfVar22 == *pfVar19) {
      fVar7 = 0.0;
    }
    *pfVar21 = fVar7;
    uVar8 = 0x3f800000;
    if (pfVar22[1] == pfVar19[1]) {
      uVar8 = 0;
    }
    *(undefined4 *)((int)pvVar14 + 0x1c) = uVar8;
    uVar8 = 0x3f800000;
    if (pfVar22[2] == pfVar19[2]) {
      uVar8 = 0;
    }
    *(undefined4 *)((int)pvVar14 + 0x20) = uVar8;
    uVar8 = 0x3f800000;
    if (pfVar22[3] != pfVar19[3]) goto LAB_97c0e458;
LAB_97c0e454:
    uVar8 = 0;
LAB_97c0e458:
    *(undefined4 *)((int)pvVar14 + 0x24) = uVar8;
    goto LAB_97c0e778;
  case 0x37:
LAB_97c0e18c:
    *(float *)((int)pvVar14 + 0x24) = fVar7;
    *pfVar21 = fVar7;
    *(float *)((int)pvVar14 + 0x1c) = fVar7;
    *(float *)((int)pvVar14 + 0x20) = fVar7;
LAB_97c0e778:
    bVar6 = !bVar6;
    break;
  case 0x38:
    if (1 < *param_1 - 0x8b30U) {
      dVar25 = _pow((double)pfVar22[3],(double)pfVar19[3]);
      goto LAB_97c0e4d8;
    }
    dVar25 = _pow((double)*pfVar22,(double)*pfVar19);
    *pfVar21 = (float)dVar25;
    dVar25 = _pow((double)pfVar22[1],(double)pfVar19[1]);
    *(float *)((int)pvVar14 + 0x1c) = (float)dVar25;
    dVar25 = _pow((double)pfVar22[2],(double)pfVar19[2]);
    *(float *)((int)pvVar14 + 0x20) = (float)dVar25;
    dVar25 = _pow((double)pfVar22[3],(double)pfVar19[3]);
LAB_97c0e764:
    bVar6 = true;
    *(float *)((int)pvVar14 + 0x24) = (float)dVar25;
    break;
  case 0x39:
    dVar23 = (double)*pfVar19;
    if (DOUBLE_97c30a78 <= dVar23) {
      iVar18 = (int)(dVar23 - DOUBLE_97c30a78);
      local_80 = (longlong)iVar18;
    }
    else {
      iVar18 = (int)*pfVar19;
      local_88 = (longlong)iVar18;
    }
    *pfVar21 = pfVar22[iVar18];
    dVar23 = DOUBLE_97c30a78;
    dVar24 = (double)*pfVar19;
    if (dVar25 <= dVar24) {
      iVar18 = (int)(dVar24 - dVar25);
      local_88 = (longlong)iVar18;
    }
    else {
      iVar18 = (int)*pfVar19;
      local_80 = (longlong)iVar18;
    }
    *(float *)((int)pvVar14 + 0x1c) = pfVar22[iVar18];
    dVar25 = DOUBLE_97c30a78;
    dVar24 = (double)*pfVar19;
    if (dVar23 <= dVar24) {
      iVar18 = (int)(dVar24 - dVar23);
      local_88 = (longlong)iVar18;
    }
    else {
      iVar18 = (int)*pfVar19;
      local_80 = (longlong)iVar18;
    }
    *(float *)((int)pvVar14 + 0x20) = pfVar22[iVar18];
    dVar23 = (double)*pfVar19;
    if (dVar25 <= dVar23) {
      iVar18 = (int)(dVar23 - dVar25);
      local_88 = (longlong)iVar18;
    }
    else {
      iVar18 = (int)*pfVar19;
      local_80 = (longlong)iVar18;
    }
    fVar7 = pfVar22[iVar18];
LAB_97c0e6f8:
    bVar6 = true;
    *(float *)((int)pvVar14 + 0x24) = fVar7;
    break;
  case 0x3a:
    if (*(int *)((int)pvVar14 + 0xc) == 1) {
      *pfVar21 = *pfVar22 / *pfVar19;
      *(float *)((int)pvVar14 + 0x1c) = pfVar22[1] / pfVar19[1];
      *(float *)((int)pvVar14 + 0x20) = pfVar22[2] / pfVar19[2];
      fVar7 = pfVar22[3] / pfVar19[3];
      goto LAB_97c0e6f8;
    }
    bVar6 = true;
    if (*(int *)((int)pvVar14 + 0xc) == 3) {
      dVar25 = _trunc((double)(*pfVar22 / *pfVar19));
      *pfVar21 = (float)dVar25;
      dVar25 = _trunc((double)(pfVar22[1] / pfVar19[1]));
      *(float *)((int)pvVar14 + 0x1c) = (float)dVar25;
      dVar25 = _trunc((double)(pfVar22[2] / pfVar19[2]));
      *(float *)((int)pvVar14 + 0x20) = (float)dVar25;
      dVar25 = _trunc((double)(pfVar22[3] / pfVar19[3]));
      goto LAB_97c0e764;
    }
    break;
  case 0x6d:
    dVar25 = (double)*pfVar19;
    if (DOUBLE_97c30a78 <= dVar25) {
      iVar18 = (int)(dVar25 - DOUBLE_97c30a78);
      local_88 = (longlong)iVar18;
    }
    else {
      iVar18 = (int)*pfVar19;
      local_80 = (longlong)iVar18;
    }
    dVar25 = (double)*pfVar19;
    if (DOUBLE_97c30a78 <= dVar25) {
      iVar13 = (int)(dVar25 - DOUBLE_97c30a78);
      local_70 = (longlong)iVar13;
    }
    else {
      iVar13 = (int)*pfVar19;
      local_78 = (longlong)iVar13;
    }
    bVar6 = true;
    pfVar21[iVar18] = pfVar22[iVar13];
  }
LAB_97c0e77c:
  fVar3 = FLOAT_97c3acd8;
  fVar7 = TAllocation__guardBlockSize;
  if (bVar6) goto LAB_97c0eea8;
  bVar2 = false;
  if ((((iVar12 != 3) || (bVar1)) || (pfVar22 == (float *)0x0)) ||
     ((pfVar19 == (float *)0x0 || (pfVar15 == (float *)0x0)))) goto LAB_97c0ee84;
  bVar2 = false;
  switch(*puVar16 >> 0x12 & 0xff) {
  case 0x3b:
    iVar12 = 0;
    for (iVar18 = (*(uint *)(param_2 + 0x10) >> 0x1a & 3) + 1; iVar18 != 0; iVar18 = iVar18 + -1) {
      fVar7 = pfVar15[iVar12] * pfVar19[iVar12] + fVar7;
      iVar12 = iVar12 + 1;
    }
    if (TAllocation__guardBlockSize <= fVar7) {
      *pfVar21 = -*pfVar22;
      *(float *)((int)pvVar14 + 0x1c) = -pfVar22[1];
      *(float *)((int)pvVar14 + 0x20) = -pfVar22[2];
      fVar7 = -pfVar22[3];
    }
    else {
      *pfVar21 = *pfVar22;
      *(float *)((int)pvVar14 + 0x1c) = pfVar22[1];
      *(float *)((int)pvVar14 + 0x20) = pfVar22[2];
      fVar7 = pfVar22[3];
    }
    break;
  case 0x3c:
    *pfVar21 = *pfVar22 * *pfVar19 + (FLOAT_97c3acd8 - *pfVar22) * *pfVar15;
    *(float *)((int)pvVar14 + 0x1c) = pfVar22[1] * pfVar19[1] + (fVar3 - pfVar22[1]) * pfVar15[1];
    *(float *)((int)pvVar14 + 0x20) = pfVar22[2] * pfVar19[2] + (fVar3 - pfVar22[2]) * pfVar15[2];
    fVar7 = pfVar22[3] * pfVar19[3] + (fVar3 - pfVar22[3]) * pfVar15[3];
    break;
  case 0x3d:
    fVar7 = *pfVar22;
    fVar3 = *pfVar19;
    fVar4 = *pfVar15;
    fVar5 = fVar3;
    if (fVar3 < fVar7) {
      fVar5 = fVar7;
    }
    if ((fVar5 < fVar4) && (fVar4 = fVar3, fVar3 < fVar7)) {
      fVar4 = fVar7;
    }
    *pfVar21 = fVar4;
    fVar7 = pfVar22[1];
    fVar3 = pfVar19[1];
    fVar4 = pfVar15[1];
    fVar5 = fVar3;
    if (fVar3 < fVar7) {
      fVar5 = fVar7;
    }
    if ((fVar5 < fVar4) && (fVar4 = fVar3, fVar3 < fVar7)) {
      fVar4 = fVar7;
    }
    *(float *)((int)pvVar14 + 0x1c) = fVar4;
    fVar7 = pfVar22[2];
    fVar3 = pfVar19[2];
    fVar4 = pfVar15[2];
    fVar5 = fVar3;
    if (fVar3 < fVar7) {
      fVar5 = fVar7;
    }
    if ((fVar5 < fVar4) && (fVar4 = fVar3, fVar3 < fVar7)) {
      fVar4 = fVar7;
    }
    *(float *)((int)pvVar14 + 0x20) = fVar4;
    fVar3 = pfVar22[3];
    fVar4 = pfVar19[3];
    fVar7 = pfVar15[3];
    fVar5 = fVar4;
    if (fVar4 < fVar3) {
      fVar5 = fVar3;
    }
    if ((fVar5 < fVar7) && (fVar7 = fVar4, fVar4 < fVar3)) {
      fVar7 = fVar3;
    }
    goto LAB_97c0eb30;
  case 0x3e:
    if (DOUBLE_97c30a48 <= (double)*pfVar22) {
      fVar7 = *pfVar15;
    }
    else {
      fVar7 = *pfVar19;
    }
    *pfVar21 = fVar7;
    if (DOUBLE_97c30a48 <= (double)pfVar22[1]) {
      fVar7 = pfVar15[1];
    }
    else {
      fVar7 = pfVar19[1];
    }
    *(float *)((int)pvVar14 + 0x1c) = fVar7;
    if (DOUBLE_97c30a48 <= (double)pfVar22[2]) {
      fVar7 = pfVar15[2];
    }
    else {
      fVar7 = pfVar19[2];
    }
    *(float *)((int)pvVar14 + 0x20) = fVar7;
    if (DOUBLE_97c30a48 <= (double)pfVar22[3]) {
      fVar7 = pfVar15[3];
    }
    else {
      fVar7 = pfVar19[3];
    }
LAB_97c0eb30:
    *(float *)((int)pvVar14 + 0x24) = fVar7;
    goto LAB_97c0ee80;
  case 0x3f:
    *pfVar21 = *pfVar22 * *pfVar19 + *pfVar15;
    *(float *)((int)pvVar14 + 0x1c) = pfVar22[1] * pfVar19[1] + pfVar15[1];
    *(float *)((int)pvVar14 + 0x20) = pfVar22[2] * pfVar19[2] + pfVar15[2];
    fVar7 = pfVar22[3] * pfVar19[3] + pfVar15[3];
    break;
  case 0x40:
    dVar25 = (double)((*pfVar15 - *pfVar22) / (*pfVar19 - *pfVar22));
    if ((dVar25 <= DOUBLE_97c30a48) || (dVar25 < DOUBLE_97c30a60)) {
      if (dVar25 <= DOUBLE_97c30a48) {
        dVar25 = (double)TAllocation__guardBlockSize;
      }
    }
    else {
      dVar25 = (double)FLOAT_97c3acd8;
    }
    *pfVar21 = (float)((double)(float)(dVar25 * dVar25) * (DOUBLE_97c30a80 - (dVar25 + dVar25)));
    dVar25 = (double)((pfVar15[1] - pfVar22[1]) / (pfVar19[1] - pfVar22[1]));
    if ((dVar25 <= DOUBLE_97c30a48) || (dVar25 < DOUBLE_97c30a60)) {
      if (dVar25 <= DOUBLE_97c30a48) {
        dVar25 = (double)TAllocation__guardBlockSize;
      }
    }
    else {
      dVar25 = (double)FLOAT_97c3acd8;
    }
    *(float *)((int)pvVar14 + 0x1c) =
         (float)((double)(float)(dVar25 * dVar25) * (DOUBLE_97c30a80 - (dVar25 + dVar25)));
    dVar25 = (double)((pfVar15[2] - pfVar22[2]) / (pfVar19[2] - pfVar22[2]));
    if ((dVar25 <= DOUBLE_97c30a48) || (dVar25 < DOUBLE_97c30a60)) {
      if (dVar25 <= DOUBLE_97c30a48) {
        dVar25 = (double)TAllocation__guardBlockSize;
      }
    }
    else {
      dVar25 = (double)FLOAT_97c3acd8;
    }
    *(float *)((int)pvVar14 + 0x20) =
         (float)((double)(float)(dVar25 * dVar25) * (DOUBLE_97c30a80 - (dVar25 + dVar25)));
    dVar25 = (double)((pfVar15[3] - pfVar22[3]) / (pfVar19[3] - pfVar22[3]));
    if ((dVar25 <= DOUBLE_97c30a48) || (dVar25 < DOUBLE_97c30a60)) {
      if (dVar25 <= DOUBLE_97c30a48) {
        dVar25 = (double)TAllocation__guardBlockSize;
      }
    }
    else {
      dVar25 = (double)FLOAT_97c3acd8;
    }
    fVar7 = (float)((double)(float)(dVar25 * dVar25) * (DOUBLE_97c30a80 - (dVar25 + dVar25)));
LAB_97c0ee74:
    bVar2 = true;
    *(float *)((int)pvVar14 + 0x24) = fVar7;
    goto LAB_97c0ee84;
  default:
    bVar2 = true;
    goto LAB_97c0ee80;
  case 0x68:
    iVar12 = 0;
    fVar3 = TAllocation__guardBlockSize;
    for (iVar18 = (*(uint *)(param_2 + 0x10) >> 0x1a & 3) + 1; iVar18 != 0; iVar18 = iVar18 + -1) {
      fVar3 = pfVar22[iVar12] * pfVar19[iVar12] + fVar3;
      iVar12 = iVar12 + 1;
    }
    fVar4 = *pfVar15;
    dVar25 = (double)(float)-((double)(fVar4 * fVar4) * (DOUBLE_97c30a60 - (double)(fVar3 * fVar3))
                             - DOUBLE_97c30a60);
    if ((double)TAllocation__guardBlockSize <= dVar25) {
      dVar25 = _sqrt(dVar25);
      fVar7 = (float)((double)(fVar4 * fVar3) + dVar25);
      *pfVar21 = *pfVar15 * *pfVar22 - fVar7 * *pfVar19;
      *(float *)((int)pvVar14 + 0x1c) = *pfVar15 * pfVar22[1] - fVar7 * pfVar19[1];
      *(float *)((int)pvVar14 + 0x20) = *pfVar15 * pfVar22[2] - fVar7 * pfVar19[2];
      fVar7 = *pfVar15 * pfVar22[3] - fVar7 * pfVar19[3];
      goto LAB_97c0ee74;
    }
    *(float *)((int)pvVar14 + 0x24) = TAllocation__guardBlockSize;
    *pfVar21 = fVar7;
    *(float *)((int)pvVar14 + 0x1c) = fVar7;
    *(float *)((int)pvVar14 + 0x20) = fVar7;
LAB_97c0ee80:
    bVar2 = !bVar2;
    goto LAB_97c0ee84;
  }
  bVar2 = true;
  *(float *)((int)pvVar14 + 0x24) = fVar7;
LAB_97c0ee84:
  if (bVar2) {
LAB_97c0eea8:
    if (!bVar1) {
      *(undefined4 *)((int)pvVar14 + 0x14) = 1;
    }
  }
  else if (!bVar1) {
    ((int (*)())_ClearDestedOpRegisters)(param_1,param_3,param_2,0);
  }
  switch(*puVar16 >> 0x12 & 0xff) {
  case 0x4b:
  case 0x4c:
  case 0x4d:
  case 0x54:
  case 0x55:
  case 0x58:
  case 0x59:
  case 0x69:
    ((int (*)())_ClearRegisterState)(param_3);
    return;
  default:
    goto switchD_97c0eee4_caseD_4e;
  case 0x56:
  case 0x57:
  case 0x6a:
    iVar12 = _PPStreamChunkListChunkAtIndex(param_1[8],*(uint *)(param_2 + 0x10) & 0x3ffff);
    iVar18 = *(int *)(iVar12 + 4);
    iVar12 = param_2;
    break;
  case 0x5a:
  case 0x5b:
  case 0x6b:
    iVar12 = _PPStreamChunkListChunkAtIndex(param_1[8],*(uint *)(param_2 + 0x10) & 0x3ffff);
    iVar12 = *(int *)(iVar12 + 4);
    iVar18 = param_2;
  }
  ((int (*)())_ClearDestedRegisters)(param_1,param_3,iVar12,iVar18);
switchD_97c0eee4_caseD_4e:
  return;
switchD_97c0cae8_caseD_0:
  *pfVar21 = *pfVar22;
  *(float *)((int)pvVar14 + 0x1c) = pfVar22[1];
  *(float *)((int)pvVar14 + 0x20) = pfVar22[2];
  fVar7 = pfVar22[3];
LAB_97c0ce78:
  *(float *)((int)pvVar14 + 0x24) = fVar7;
  goto LAB_97c0d82c;
}

/* _UpdateScope @ 0x97c0efd8 (96 bytes) */
int _UpdateScope(param_1, param_2)
  int param_1;
  int *param_2;
{
  switch(*(uint *)(param_1 + 0xc) >> 0x12 & 0xff) {
  case 0x55:
  case 0x56:
  case 0x57:
  case 0x6a:
    *param_2 = *param_2 + 1;
    return;
  case 0x58:
  case 0x5c:
  case 0x5d:
  case 0x5e:
  case 0x5f:
  case 0x60:
  case 0x61:
  case 0x62:
  case 99:
  case 100:
  case 0x65:
  case 0x66:
  case 0x67:
  case 0x68:
  case 0x69:
    goto switchD_97c0f014_caseD_58;
  case 0x59:
  case 0x5a:
  case 0x5b:
  case 0x6b:
    *param_2 = *param_2 + -1;
switchD_97c0f014_caseD_58:
    return;
  default:
    return;
  }
}

/* _GetOpRegs @ 0x97c0f094 (240 bytes) */
int _GetOpRegs(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  uint *param_3;
  uint *param_4;
{
  ushort *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint *puVar6;
  
  iVar3 = param_2 + 0xc;
  iVar2 = _GetValidArgs(param_2);
  iVar5 = 0;
  iVar4 = iVar2;
  puVar6 = param_3;
  if (0 < iVar2) {
    do {
      puVar6[1] = *(uint *)(iVar3 + 0x10) >> 0x17 & 7;
      puVar1 = (ushort *)(iVar3 + 0x16);
      iVar3 = iVar3 + 8;
      *puVar6 = (uint)*puVar1;
      ((int (*)())_GetRegisterTypeInfo)(param_1,puVar6);
      iVar4 = iVar4 + -1;
      puVar6 = puVar6 + 10;
    } while (iVar4 != 0);
    iVar5 = iVar2;
    if (3 < iVar2) goto LAB_97c0f130;
  }
  do {
    iVar4 = iVar5 + 1;
    param_3[iVar5 * 10 + 1] = 500;
    iVar5 = iVar4;
  } while (iVar4 < 4);
LAB_97c0f130:
  if ((*(uint *)(param_2 + 0x14) & 0x1e000) == 0) {
    param_4[1] = 500;
    return;
  }
  param_4[1] = *(uint *)(param_2 + 0x14) >> 0x11 & 7;
  *param_4 = (uint)*(ushort *)(param_2 + 0x1a);
  ((int (*)())_GetRegisterTypeInfo)(param_1,param_4);
  return;
}

/* _DetectConstantLoopsSimple @ 0x97c0f184 (2520 bytes) */
int _DetectConstantLoopsSimple(param_1)
  int param_1;
{
  bool bVar1;
  undefined2 uVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  undefined1 *puVar18;
  int iVar19;
  undefined1 auStack_490 [40];
  undefined1 auStack_468 [120];
  undefined1 auStack_3f0 [48];
  undefined1 auStack_3c0 [12];
  int local_3b4;
  int local_3b0;
  int local_3ac;
  int local_3a8;
  undefined1 auStack_390 [12];
  int local_384;
  int local_380;
  undefined1 auStack_360 [12];
  int local_354;
  int local_350;
  undefined1 auStack_330 [12];
  int local_324;
  int local_320;
  undefined4 local_300;
  uint local_2fc;
  uint local_2f8;
  uint local_2f4;
  uint local_2f0;
  undefined4 local_2d0 [2];
  undefined4 local_2c8;
  undefined4 local_2c4;
  undefined4 local_2c0;
  undefined4 local_2a0 [2];
  undefined4 local_298;
  undefined4 local_294;
  undefined4 local_290;
  undefined4 local_270 [2];
  undefined4 local_268;
  undefined4 local_264;
  undefined4 local_260;
  undefined4 local_240 [2];
  undefined4 local_238;
  undefined4 local_234;
  undefined4 local_230;
  undefined4 local_210 [2];
  undefined4 local_208;
  undefined4 local_204;
  undefined4 local_200;
  undefined4 local_1e0 [2];
  undefined4 local_1d8;
  undefined4 local_1d4;
  undefined4 local_1d0;
  uint local_1b0 [12];
  int local_180 [7];
  int local_164;
  int local_160;
  uint local_150 [12];
  undefined1 *local_120;
  uint local_11c;
  undefined1 *local_118;
  uint local_114;
  undefined1 *local_110;
  uint local_10c;
  undefined4 *local_108;
  undefined4 *local_104;
  undefined4 *local_100;
  undefined4 *local_fc;
  undefined4 *local_f8;
  undefined4 local_f4;
  undefined4 *local_f0;
  undefined4 *local_ec;
  undefined4 *local_e8;
  undefined4 *local_e4;
  undefined4 *local_e0;
  undefined4 *local_dc;
  undefined4 *local_d0 [4];
  undefined4 *local_c0;
  undefined4 *local_bc;
  undefined4 *local_b8;
  undefined4 *local_b4;
  undefined4 *local_b0;
  uint local_a0;
  uint local_9c;
  uint local_98;
  uint local_94;
  uint local_90;
  undefined4 local_8c;
  undefined2 uStack_8a;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  int local_60;
  int local_5c;
  
  iVar14 = **(int **)(param_1 + 0x20);
  do {
    if (iVar14 == 0) {
      return;
    }
    if ((*(uint *)(iVar14 + 0xc) >> 0x12 & 0xff) == 0x6a) {
      iVar15 = *(int *)(iVar14 + 4);
      local_5c = 0;
      bVar6 = true;
      bVar5 = false;
      bVar4 = false;
      if ((iVar15 == 0) || ((*(uint *)(iVar15 + 0xc) >> 0x12 & 0xff) != 0)) {
        uVar8 = 1;
      }
      else {
        ((int (*)())_GetOpRegs)(param_1,iVar15,auStack_490,auStack_3f0);
        uVar8 = ((int (*)())_IsBadUsage)(iVar15);
        _memcpy(auStack_390,auStack_3f0,0x28);
        _memcpy(auStack_360,auStack_490,0x28);
      }
      iVar19 = *(int *)(iVar14 + 8);
      iVar16 = *(int *)(iVar19 + 8);
      iVar11 = 0;
      bVar1 = false;
      iVar15 = *(int *)(iVar16 + 8);
      ((int (*)())_GetOpRegs)(param_1,iVar19,auStack_490,auStack_3f0);
      uVar13 = 0;
      uVar9 = ((int (*)())_IsBadUsage)(iVar19);
      uVar8 = uVar8 | uVar9;
      iVar10 = _regEqualsFunction(auStack_390,auStack_490);
      bVar3 = false;
      iVar12 = 0;
      if (iVar10 == 0) {
        puVar18 = auStack_468;
LAB_97c0f2e0:
        _memcpy(auStack_330,puVar18,0x28);
      }
      else {
        iVar10 = _regEqualsFunction(auStack_390,auStack_468);
        if (iVar10 == 0) {
          puVar18 = auStack_490;
          bVar1 = true;
          goto LAB_97c0f2e0;
        }
        uVar8 = 1;
      }
      uVar9 = *(uint *)(iVar19 + 0xc) >> 0x12 & 0xff;
      if (uVar9 == 0x33) {
        bVar3 = true;
      }
      else if (uVar9 < 0x34) {
        if (uVar9 == 0x32) {
          bVar3 = true;
LAB_97c0f324:
          iVar12 = 1;
        }
        else {
LAB_97c0f33c:
          uVar8 = 1;
        }
      }
      else {
        if (uVar9 == 0x34) goto LAB_97c0f324;
        if (uVar9 != 0x35) goto LAB_97c0f33c;
      }
      if (bVar1) {
        bVar3 = (bool)(bVar3 ^ 1);
      }
      uVar9 = 0;
      if ((iVar16 == 0) || ((*(uint *)(iVar16 + 0xc) >> 0x12 & 0xff) != 10)) {
        uVar9 = 1;
      }
      uVar7 = 0;
      if ((iVar15 == 0) || ((*(uint *)(iVar15 + 0xc) >> 0x12 & 0xff) != 0x55)) {
        uVar7 = 1;
      }
      uVar7 = uVar8 | uVar9 | uVar7;
      local_60 = 0;
      uVar8 = *(uint *)(iVar14 + 0x10);
      iVar10 = local_5c;
      if (uVar7 == 0) {
        iVar16 = 0;
        iVar19 = iVar14;
        while ((((*(uint *)(iVar19 + 0xc) & 0x3ffff) != (uVar8 & 0x3ffff) || (iVar16 == 0)) ||
               (iVar10 = iVar16, (*(uint *)(iVar16 + 0xc) >> 0x12 & 0xff) != 0x6b))) {
          ((int (*)())_UpdateScope)(iVar19,&local_60);
          ((int (*)())_GetOpRegs)(param_1,iVar19,auStack_490,auStack_3f0);
          uVar9 = ((int (*)())_IsBadUsage)(iVar19);
          iVar10 = _regEqualsFunction(auStack_390,auStack_3f0);
          if (iVar10 == 0) {
            uVar7 = uVar7 | uVar9 | (uint)(1 < local_60);
            if (bVar4) {
              uVar7 = 1;
              goto LAB_97c0f4cc;
            }
            uVar17 = *(uint *)(iVar19 + 0xc);
            bVar4 = true;
            uVar9 = uVar17 >> 0x12 & 0xff;
            if (uVar9 != 0x1f) {
              if (uVar9 == 0x20) {
                uVar13 = 1;
              }
              else {
                uVar7 = 1;
              }
            }
            iVar10 = _regEqualsFunction(auStack_390,auStack_490);
            puVar18 = auStack_468;
            if (iVar10 == 0) {
LAB_97c0f4b8:
              _memcpy(auStack_3c0,puVar18,0x28);
              goto LAB_97c0f4cc;
            }
            iVar10 = _regEqualsFunction(auStack_390,auStack_468);
            if (iVar10 == 0) {
              uVar7 = uVar7 | uVar13;
              puVar18 = auStack_490;
              goto LAB_97c0f4b8;
            }
            uVar7 = 1;
          }
          else {
LAB_97c0f4cc:
            uVar17 = *(uint *)(iVar19 + 0xc);
          }
          iVar10 = _regEqualsFunction(auStack_330,auStack_3f0);
          uVar9 = uVar17 >> 0x12 & 0xff;
          uVar7 = uVar7 | iVar10 == 0;
          if (uVar9 == 0x4d) {
LAB_97c0f508:
            bVar6 = false;
          }
          else {
            if (uVar9 < 0x4e) {
              bVar1 = uVar9 == 0x4b;
            }
            else {
              bVar1 = uVar9 == 0x69;
            }
            if (bVar1) goto LAB_97c0f508;
          }
          if (!bVar5) {
            uVar9 = uVar17 >> 0x12 & 0xff;
            if (uVar9 == 0x55) {
              if (iVar15 != iVar19) {
                bVar6 = false;
              }
            }
            else if (uVar9 == 0x59) {
              bVar5 = true;
              iVar11 = iVar19;
            }
          }
          iVar10 = local_5c;
          if (((*(int *)(iVar19 + 8) == 0) || (uVar7 != 0)) ||
             (iVar16 = iVar19, iVar19 = *(int *)(iVar19 + 8), !bVar6)) break;
        }
      }
      local_5c = iVar10;
      if (((local_384 != 3) || (local_354 != 3)) || ((local_324 != 3 || (local_3b4 != 3)))) {
        uVar7 = 1;
      }
      if ((((local_380 != 0) || (local_350 != 0)) || (local_320 != 0)) || (local_3b0 != 0)) {
        uVar7 = 1;
      }
      uVar7 = uVar7 | local_3ac == 0;
      if (local_3a8 < 0) {
        uVar13 = uVar13 ^ 1;
      }
      if (bVar3) {
        if (uVar13 == 0) goto LAB_97c0f608;
      }
      else if (uVar13 != 0) {
LAB_97c0f608:
        uVar7 = 1;
      }
      if (((uVar7 == 0) && (bVar4)) && (((bVar5 && ((iVar15 != 0 && (iVar11 != 0)))) && (bVar6)))) {
        local_2fc = 1;
        local_2f4 = 1;
        local_2f8 = uVar7;
        local_2f0 = uVar7;
        local_300 = _AddTempRegister(param_1,0,1,0);
        _memcpy(local_2d0,&local_300,0x28);
        local_2d0[0] = _AddTempRegister(param_1,local_2c8,local_2c4,local_2c0);
        _memcpy(local_2a0,&local_300,0x28);
        local_2a0[0] = _AddTempRegister(param_1,local_298,local_294,local_290);
        _memcpy(local_270,&local_300,0x28);
        local_270[0] = _AddTempRegister(param_1,local_268,local_264,local_260);
        _memcpy(local_240,&local_300,0x28);
        local_240[0] = _AddTempRegister(param_1,local_238,local_234,local_230);
        if (iVar12 != 0) {
          _memcpy(local_210,&local_300,0x28);
          local_210[0] = _AddTempRegister(param_1,local_208,local_204,local_200);
          _memcpy(local_1e0,&local_300,0x28);
          local_1e0[0] = _AddTempRegister(param_1,local_1d8,local_1d4,local_1d0);
        }
        _memcpy(local_1b0,&DAT_97c3aa40,0x24);
        local_180[5] = 1;
        local_180[0] = 1;
        local_180[1] = 1;
        local_180[2] = 1;
        local_180[3] = 1;
        local_180[4] = 1;
        local_180[6] = iVar12;
        local_164 = iVar12;
        local_160 = iVar12;
        _memcpy(local_150,&DAT_97c3aa64,0x24);
        local_120 = auStack_330;
        local_118 = auStack_360;
        local_110 = auStack_3c0;
        local_10c = uVar7;
        local_11c = uVar7;
        local_114 = uVar7;
        local_108 = local_2a0;
        if (uVar13 != 0) {
          local_108 = local_270;
        }
        local_104 = local_270;
        if (uVar13 != 0) {
          local_104 = local_2a0;
        }
        puVar18 = auStack_490;
        local_d0[0] = local_2a0;
        local_d0[1] = local_270;
        uVar8 = 0;
        local_d0[2] = local_240;
        local_d0[3] = local_2d0;
        local_b0 = &local_300;
        local_100 = local_2d0;
        local_fc = local_240;
        local_f8 = &local_300;
        local_f0 = &local_300;
        local_ec = local_240;
        local_e4 = local_2d0;
        local_e0 = &local_300;
        local_c0 = &local_300;
        local_bc = &local_300;
        local_b8 = local_210;
        local_b4 = local_1e0;
        local_f4 = 0;
        local_e8 = local_210;
        local_dc = local_1e0;
        do {
          if (*(int *)(puVar18 + 0x310) != 0) {
            local_90 = 0;
            local_8c = 0;
            local_88 = 0;
            local_84 = 0;
            local_80 = 0;
            local_7c = 0;
            local_78 = 0;
            local_74 = 0;
            local_9c = 0;
            local_70 = 0;
            local_a0 = (*(uint *)(puVar18 + 0x2e0) & 0xff) << 0x12;
            uVar7 = *(uint *)(puVar18 + 0x340);
            local_98 = 0;
            local_94 = 0;
            local_70 = *(undefined4 *)(iVar14 + 0x3c);
            local_a0 = uVar7 << 0x1d | local_a0;
            local_6c = 0;
            uVar9 = (*(uint *)(*(int *)(puVar18 + 0x3c0) + 0x10) & 3) << 10;
            local_98 = uVar9 | 0x6c;
            uVar13 = *(uint *)(*(int *)(puVar18 + 0x3c0) + 0x10) & 3;
            if (uVar13 == 1) {
LAB_97c0f960:
              local_98 = local_98 | 0x4000;
LAB_97c0f968:
              local_98 = local_98 | 0x2000;
            }
            else {
              if (1 < uVar13) {
                if (uVar13 != 2) {
                  if (uVar13 != 3) goto LAB_97c0f970;
                  local_98 = uVar9 | 0x1006c;
                }
                local_98 = local_98 | 0x8000;
                goto LAB_97c0f960;
              }
              if (uVar13 == 0) goto LAB_97c0f968;
            }
LAB_97c0f970:
            local_98 = (*(uint *)(*(int *)(puVar18 + 0x3c0) + 4) & 7) << 0x11 | local_98;
            local_94 = (uint)*(ushort *)(*(int *)(puVar18 + 0x3c0) + 2);
            iVar10 = 0;
            uVar9 = local_98;
            if ((uVar7 & 7) != 0) {
              do {
                uVar17 = (&local_90)[iVar10 * 2];
                uVar13 = (uVar9 >> 10 & 3) << 0xc;
                iVar12 = uVar8 * 2 + iVar10;
                (&local_90)[iVar10 * 2] = uVar13 | uVar17 & 0xff804fff | 0xd8000;
                iVar16 = iVar10 + 1;
                uVar9 = (*(uint *)((&local_120)[iVar12] + 4) & 7) << 0x17;
                (&local_90)[iVar10 * 2] = uVar9 | uVar13 | uVar17 & 0xfc004fff | 0xd8000;
                uVar2 = *(undefined2 *)((&local_120)[iVar12] + 2);
                (&local_90)[iVar10 * 2] = uVar9 | uVar13 | uVar17 & 0xf4004fff | 0xd8000;
                (&uStack_8a)[iVar10 * 4] = uVar2;
                iVar10 = iVar16;
                uVar9 = local_98;
              } while (iVar16 < (int)(uVar7 & 7));
            }
            uVar9 = (*(uint *)(*(int *)(puVar18 + 0x3c0) + 8) & 3) << 0x12;
            local_9c = uVar9;
            uVar13 = (*(uint *)(*(int *)(puVar18 + 0x3c0) + 0xc) & 7) << 0x17;
            local_9c = uVar13 | uVar9;
            local_9c = (*(uint *)(*(int *)(puVar18 + 0x3c0) + 0x10) & 3) << 0x1a | uVar13 | uVar9;
            _PPStreamInsertOperationBeforeChunk(param_1,&local_a0,0,0,iVar14);
          }
          uVar8 = uVar8 + 1;
          puVar18 = puVar18 + 4;
        } while (uVar8 < 9);
        iVar11 = *(int *)(iVar11 + 8);
        while (iVar15 != iVar11) {
          iVar10 = *(int *)(iVar15 + 8);
          _PPStreamRemoveOperation(param_1,iVar15);
          iVar15 = iVar10;
        }
        uVar13 = *(uint *)(iVar14 + 0x1c);
        *(uint *)(iVar14 + 0xc) = *(uint *)(iVar14 + 0xc) & 0x1c03ffff | 0x215c0000;
        uVar8 = (local_2f0 & 3) << 0xc;
        *(uint *)(iVar14 + 0x1c) = uVar8 | uVar13 & 0xff85cfff | 0xd8000;
        uVar9 = (local_2fc & 7) << 0x17;
        *(uint *)(iVar14 + 0x1c) = uVar9 | uVar8 | uVar13 & 0xfc05cfff | 0xd8000;
        *(uint *)(iVar14 + 0x1c) = uVar9 | uVar8 | uVar13 & 0xf405cfff | 0xd8000;
        *(undefined2 *)(iVar14 + 0x22) = (*(unsigned short *)((unsigned char *)&(local_300) + 2));
        uVar13 = *(uint *)(iVar14 + 0x10);
        uVar8 = (local_2f8 & 3) << 0x12;
        *(uint *)(iVar14 + 0x10) = uVar8 | uVar13 & 0xfff3ffff;
        uVar9 = (local_2f4 & 7) << 0x17;
        *(uint *)(iVar14 + 0x10) = uVar9 | uVar8 | uVar13 & 0xfc73ffff;
        *(uint *)(iVar14 + 0x10) = (local_2f0 & 3) << 0x1a | uVar9 | uVar8 | uVar13 & 0xf073ffff;
        *(uint *)(local_5c + 0xc) = *(uint *)(local_5c + 0xc) & 0xfc03ffff | 0x16c0000;
      }
    }
    iVar14 = *(int *)(iVar14 + 8);
  } while( true );
}

/* _UnrollConstantLoopsSimple @ 0x97c0fb5c (1808 bytes) */
int _UnrollConstantLoopsSimple(param_1, param_2)
  int param_1;
  int param_2;
{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  uint uVar9;
  bool bVar10;
  uint *puVar11;
  int iVar12;
  int iVar13;
  uint local_280;
  uint local_27c;
  int local_26c;
  uint local_250;
  uint local_24c;
  longlong local_220;
  uint local_210;
  uint local_20c;
  undefined4 local_208;
  undefined4 local_204;
  undefined4 local_1e0;
  undefined4 local_1dc;
  undefined4 local_1c8;
  undefined4 local_1c4;
  undefined4 local_1c0;
  undefined4 local_1bc;
  undefined4 local_1b0;
  undefined4 local_1ac;
  undefined4 local_1a8;
  undefined4 local_1a4;
  undefined4 local_1a0;
  uint local_180 [8];
  int *local_160 [4];
  undefined4 local_150;
  uint local_140 [4];
  int *local_130;
  uint local_120 [4];
  undefined4 local_110;
  uint local_100 [4];
  undefined4 local_f0;
  uint *local_e0 [9];
  undefined4 *local_bc;
  uint *local_b0 [8];
  uint local_90 [5];
  undefined4 local_7c;
  undefined2 uStack_7a;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  uint local_6c;
  uint local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  int local_50;
  int local_4c [5];
  
  uVar4 = _HashSetNew((*(uint *)(*(int *)(param_1 + 4) + 8) >> 5) + 1,DAT_a7b7bf80,DAT_a7b7bf7c);
  iVar13 = **(int **)(param_1 + 0x20);
  do {
    while( true ) {
      if (iVar13 == 0) {
        ((int (*)())_ClearRegisterState)(uVar4);
        _HashSetFree(uVar4);
        return;
      }
      if ((*(uint *)(iVar13 + 0xc) >> 0x12 & 0xff) == 0x57) break;
LAB_97c102a8:
      ((int (*)())_EmulateOp)(param_1,iVar13,uVar4);
LAB_97c102ac:
      iVar13 = *(int *)(iVar13 + 8);
    }
    bVar2 = false;
    if (param_2 != 0) {
      local_27c = *(uint *)(iVar13 + 0x1c) >> 0x17 & 7;
      local_280 = (uint)*(ushort *)(iVar13 + 0x22);
      ((int (*)())_GetRegisterTypeInfo)(param_1,&local_280);
      bVar2 = local_26c != 0;
    }
    if (bVar2) goto LAB_97c102a8;
    local_4c[0] = 0;
    bVar10 = true;
    uVar9 = *(uint *)(iVar13 + 0x10) & 0x3ffff;
    bVar2 = true;
    iVar12 = 0;
    iVar5 = iVar13;
    while ((iVar3 = local_4c[0], bVar2 &&
           ((((*(uint *)(iVar5 + 0xc) & 0x3ffff) != uVar9 || (iVar12 == 0)) ||
            (iVar3 = iVar12, (*(uint *)(iVar12 + 0xc) >> 0x12 & 0xff) != 0x5b))))) {
      switch(*(uint *)(iVar5 + 0xc) >> 0x12 & 0xff) {
      case 0x4b:
      case 0x54:
      case 0x69:
        if (uVar9 < (*(uint *)(iVar5 + 0x10) & 0x3ffff)) goto switchD_97c0fc88_caseD_4c;
        break;
      case 0x4c:
      case 0x4d:
switchD_97c0fc88_caseD_4c:
        bVar10 = false;
      }
      bVar2 = *(int *)(iVar5 + 8) != 0;
      iVar12 = iVar5;
      iVar5 = *(int *)(iVar5 + 8);
    }
    local_4c[0] = iVar3;
    iVar12 = -1;
    local_24c = *(uint *)(iVar13 + 0x1c) >> 0x17 & 7;
    local_250 = (uint)*(ushort *)(iVar13 + 0x22);
    local_50 = iVar13;
    iVar5 = _HashSetGet(uVar4,&local_250);
    if (iVar5 == 0) {
LAB_97c0fe04:
      puVar8 = &local_280;
      uVar9 = 0;
      local_20c = *(uint *)(local_50 + 0x1c) >> 0x17 & 7;
      local_210 = (uint)*(ushort *)(local_50 + 0x22);
      ((int (*)())_GetRegisterTypeInfo)(param_1,&local_210);
      local_1c8 = 0x3f800000;
      local_1bc = 0;
      local_1c4 = 0;
      local_1c0 = 0;
      local_1dc = 2;
      local_1e0 = ((undefined2 (*)())_AddConstantParam)(param_1,local_208,local_204,0,0x3f800000,0,0,0);
      local_1ac = 1;
      local_1a4 = 4;
      local_1a8 = 0;
      local_1a0 = 0;
      local_1b0 = _AddTempRegister(param_1,0,4,0);
      local_160[0] = &local_50;
      local_160[1] = (int *)local_180;
      local_160[2] = (int *)(local_180 + 1);
      local_160[3] = (int *)(local_180 + 2);
      local_130 = local_4c;
      local_110 = DAT_97c3aa98;
      local_180[0] = 0;
      local_180[1] = 0;
      local_180[2] = 0;
      local_180[3] = 0;
      local_180[4] = 0;
      local_150 = 0;
      local_140[0] = 0;
      local_140[1] = 0;
      local_140[2] = 0;
      local_140[3] = 0;
      local_120[0] = DAT_97c3aa88;
      local_120[1] = DAT_97c3aa8c;
      local_120[2] = DAT_97c3aa90;
      local_120[3] = DAT_97c3aa94;
      local_100[0] = DAT_97c3aa9c;
      local_100[1] = DAT_97c3aaa0;
      local_100[2] = DAT_97c3aaa4;
      local_100[3] = DAT_97c3aaa8;
      local_b0[3] = (uint *)0x0;
      local_b0[4] = &local_210;
      local_e0[0] = &local_210;
      local_e0[3] = (uint *)0x0;
      local_e0[4] = (uint *)0x0;
      local_e0[5] = (uint *)0x0;
      local_e0[6] = (uint *)0x0;
      local_e0[7] = (uint *)0x0;
      local_e0[8] = &local_210;
      local_b0[1] = (uint *)0x0;
      local_b0[2] = (uint *)0x0;
      iVar12 = 0;
      local_f0 = DAT_97c3aaac;
      local_bc = &local_1e0;
      local_b0[0] = &local_1b0;
      local_e0[1] = &local_1e0;
      local_e0[2] = &local_1b0;
      puVar11 = puVar8;
      do {
        local_90[4] = 0;
        local_7c = 0;
        local_78 = 0;
        local_74 = 0;
        local_70 = 0;
        local_6c = 0;
        local_68 = 0;
        local_64 = 0;
        local_90[0] = 0;
        local_90[1] = 0;
        local_90[2] = 0;
        local_90[3] = 0;
        local_60 = 0;
        local_5c = 0;
        if ((int *)puVar11[0x48] == (int *)0x0) {
          iVar5 = *(int *)puVar11[0x50];
        }
        else {
          iVar5 = *(int *)puVar11[0x48];
        }
        local_90[0] = (puVar11[0x58] & 0xff) << 0x12;
        local_60 = *(undefined4 *)(iVar5 + 0x3c);
        local_90[0] = puVar11[0x60] << 0x1d | local_90[0];
        local_90[1] = 0x1800000;
        if (puVar11[0x74] != 0) {
          local_90[2] = 0x6c;
          local_90[2] = 0x206c;
          local_90[2] = (*(uint *)(puVar11[0x74] + 4) & 7) << 0x11 | 0x206c;
          local_90[3] = (uint)*(ushort *)(puVar11[0x74] + 2);
        }
        iVar5 = 0;
        if (0 < (int)puVar11[0x60]) {
          do {
            uVar6 = local_90[iVar5 * 2 + 4];
            iVar3 = uVar9 * 2 + iVar5;
            local_90[iVar5 * 2 + 4] = uVar6 & 0xff81cfff | 0xd8000;
            iVar7 = iVar5 + 1;
            local_90[iVar5 * 2 + 4] =
                 (local_e0[iVar3][1] & 7) << 0x17 | uVar6 & 0xfc01cfff | 0xd8000;
            (&uStack_7a)[iVar5 * 4] = (short)*local_e0[iVar3];
            iVar5 = iVar7;
          } while (iVar7 < *(int *)((int)local_100 + iVar12));
        }
        if ((undefined4 *)puVar11[0x48] == (undefined4 *)0x0) {
          uVar6 = _PPStreamInsertOperationBeforeChunk
                            (param_1,local_90,0,0,*(undefined4 *)puVar11[0x50]);
        }
        else {
          uVar6 = _PPStreamInsertOperationAfterChunk
                            (param_1,local_90,0,0,*(undefined4 *)puVar11[0x48]);
        }
        uVar9 = uVar9 + 1;
        puVar11[0x40] = uVar6;
        iVar12 = iVar12 + 4;
        puVar11 = puVar11 + 1;
      } while (uVar9 < 5);
      local_70 = 0;
      local_6c = *(uint *)(*(int *)(local_180[3] + 8) + 0xc) & 0x3ffff;
      local_90[1] = local_6c;
      local_90[2] = *(uint *)(local_50 + 0x10) & 0x3ffff;
      local_90[4] = 0;
      local_68 = local_90[2];
      iVar12 = 5;
      local_64 = 0;
      local_60 = 0;
      local_90[0] = 0;
      local_90[3] = 0;
      do {
        puVar11 = puVar8 + 0x40;
        puVar1 = puVar8 + 0x7c;
        puVar8 = puVar8 + 1;
        *(uint *)(*puVar11 + 0x10) = *puVar1 & 0x3ffff | *(uint *)(*puVar11 + 0x10) & 0xfffc0000;
        iVar12 = iVar12 + -1;
      } while (iVar12 != 0);
      *(uint *)(local_50 + 0xc) = *(uint *)(local_50 + 0xc) & 0xfc03ffff | 0x1a80000;
      *(uint *)(local_50 + 0xc) = *(uint *)(local_50 + 0xc) & 0x1fffffff;
      *(uint *)(local_4c[0] + 0xc) = *(uint *)(local_4c[0] + 0xc) & 0xfc03ffff | 0x1ac0000;
      *(uint *)(local_4c[0] + 0x10) =
           *(uint *)(*(int *)(local_50 + 8) + 0xc) & 0x3ffff |
           *(uint *)(local_4c[0] + 0x10) & 0xfffc0000;
      goto LAB_97c102a8;
    }
    if (((*(int *)(iVar5 + 0x14) == 0) || (*(int *)(iVar5 + 0x10) != 0)) ||
       (*(int *)(iVar5 + 0xc) != 1)) {
      bVar10 = false;
    }
    else {
      iVar12 = (int)*(float *)(iVar5 + 0x18);
      local_220 = (longlong)iVar12;
    }
    if (!bVar10) goto LAB_97c0fe04;
    iVar13 = *(int *)(local_50 + 4);
    if (((param_2 == 0) || (iVar12 < 1)) ||
       (iVar5 = ((int (*)())_RepifyConstantLoopSimple)(param_1,local_50,local_4c[0],iVar12), iVar5 == 0)) {
      ((int (*)())_UnrollConstantLoopSimple)(param_1,local_50,local_4c[0],iVar12);
    }
    if (iVar13 != 0) goto LAB_97c102ac;
    iVar13 = **(int **)(param_1 + 0x20);
  } while( true );
}

/* _instructionIndexHashFunction @ 0x97c102e8 (4 bytes) */
int _instructionIndexHashFunction()
{
  return;
}

/* _UnrollConstantLoopSimple @ 0x97c102f4 (596 bytes) */
int _UnrollConstantLoopSimple(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  
  iVar4 = param_3;
  if (0 < param_4) {
    uVar3 = _HashTableNew((*(uint *)(*(int *)(param_1 + 0x20) + 8) >> 5) + 1,DAT_a7b7bf78,
                          DAT_a7b7bf74);
    do {
      iVar5 = 0;
      bVar1 = true;
      for (iVar6 = *(int *)(param_2 + 8); (iVar6 != 0 && (iVar6 != param_3));
          iVar6 = *(int *)(iVar6 + 8)) {
        iVar4 = _PPStreamInsertOperationAfterChunk(param_1,iVar6 + 0xc,0,0,iVar4);
        if (bVar1) {
          iVar5 = iVar4;
        }
        bVar1 = bVar1 && iVar4 == 0;
        _HashTableAdd(uVar3,(*(uint *)(iVar6 + 0xc) & 0x3ffff) + 1,
                      (*(uint *)(iVar4 + 0xc) & 0x3ffff) + 1);
      }
      local_7c = 0;
      local_80 = 0x1b80000;
      local_78 = 0;
      local_74 = 0;
      local_70 = 0;
      local_6c = 0;
      local_68 = 0;
      local_64 = 0;
      local_60 = 0;
      local_5c = 0;
      local_58 = 0;
      local_54 = 0;
      local_50 = 0;
      local_4c = 0;
      iVar4 = _PPStreamInsertOperationAfterChunk(param_1,&local_80,0,0,iVar4);
      _HashTableAdd(uVar3,(*(uint *)(param_3 + 0xc) & 0x3ffff) + 1,
                    (*(uint *)(iVar4 + 0xc) & 0x3ffff) + 1);
      if (bVar1) {
        iVar5 = iVar4;
      }
      if (!bVar1 || iVar4 != 0) {
        do {
          if (iVar5 == iVar4) break;
          iVar6 = _HashTableGet(uVar3,(*(uint *)(iVar5 + 0x10) & 0x3ffff) + 1);
          if (iVar6 != 0) {
            *(uint *)(iVar5 + 0x10) = iVar6 - 1U & 0x3ffff | *(uint *)(iVar5 + 0x10) & 0xfffc0000;
          }
          iVar5 = *(int *)(iVar5 + 8);
        } while (iVar5 != 0);
      }
      param_4 = param_4 + -1;
    } while (0 < param_4);
    _HashTableFree(uVar3);
  }
  iVar5 = *(int *)(param_3 + 8);
  iVar6 = *(int *)(iVar4 + 8);
  iVar4 = iVar5;
  while (iVar2 = iVar4, iVar2 != iVar6) {
    iVar4 = *(int *)(iVar2 + 8);
    if ((*(uint *)(iVar2 + 0xc) >> 0x12 & 0xff) == 0x6e) {
      _PPStreamRemoveOperation(param_1,iVar2);
    }
  }
  while (param_2 != iVar5) {
    iVar4 = *(int *)(param_2 + 8);
    _PPStreamRemoveOperation(param_1,param_2);
    param_2 = iVar4;
  }
  return;
}

/* _RepifyConstantLoopSimple @ 0x97c10548 (384 bytes) */
int _RepifyConstantLoopSimple(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  uint param_4;
{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  uint local_70;
  uint local_6c;
  float local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  uint uStack_2c;
  
  uVar2 = _HashSetNew((*(uint *)(*(int *)(param_1 + 4) + 8) >> 5) + 1,DAT_a7b7bf80,DAT_a7b7bf7c);
  iVar6 = *(int *)(param_2 + 8);
  iVar5 = 1;
  do {
    if ((iVar6 == 0) || (iVar6 == param_3)) goto LAB_97c10628;
    uVar1 = *(uint *)(iVar6 + 0xc) >> 0x12 & 0xff;
    if ((uVar1 == 0x57) || (uVar1 == 0x48)) {
      local_6c = *(uint *)(iVar6 + 0x1c) >> 0x17 & 7;
      local_70 = (uint)*(ushort *)(iVar6 + 0x22);
      iVar3 = _HashSetGet(uVar2,&local_70);
      if ((iVar3 == 0) || (*(int *)(iVar3 + 0x14) == 0)) {
        iVar5 = 0;
LAB_97c10628:
        ((int (*)())_ClearRegisterState)(uVar2);
        _HashSetFree(uVar2);
        if (iVar5 != 0) {
          uStack_2c = param_4 ^ 0x80000000;
          local_30 = 0x43300000;
          local_34 = 0;
          local_3c = 0;
          local_38 = 0;
          local_40 = (float)((double)CONCAT44(0x43300000,uStack_2c) - DOUBLE_97c30a58);
          *(uint *)(param_2 + 0x1c) = *(uint *)(param_2 + 0x1c) & 0xfc7fffff | 0x1000000;
          uVar4 = ((undefined2 (*)())_AddConstantParam)(param_1,0,1,0,local_40,0,0,0);
          *(undefined2 *)(param_2 + 0x22) = uVar4;
        }
        return iVar5;
      }
    }
    ((int (*)())_EmulateOp)(param_1,iVar6,uVar2);
    iVar6 = *(int *)(iVar6 + 8);
  } while( true );
}

/* _ConstantPropagateFold @ 0x97c106c8 (536 bytes) */
int _ConstantPropagateFold(param_1)
  int param_1;
{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined2 uVar5;
  int iVar6;
  int iVar7;
  uint local_70;
  uint local_6c;
  longlong local_40;
  
  uVar2 = _HashSetNew((*(uint *)(*(int *)(param_1 + 4) + 8) >> 5) + 1,DAT_a7b7bf80,DAT_a7b7bf7c);
  for (iVar7 = **(int **)(param_1 + 0x20); iVar7 != 0; iVar7 = *(int *)(iVar7 + 8)) {
    iVar6 = iVar7 + 0xc;
    iVar3 = _GetValidArgs(iVar7);
    if (0 < iVar3) {
      do {
        if (*(int *)(iVar6 + 0x10) < 0) {
          local_6c = 4;
          local_70 = 0;
          iVar4 = _HashSetGet(uVar2,&local_70);
          if ((iVar4 != 0) && (*(int *)(iVar4 + 0x14) != 0)) {
            *(uint *)(iVar6 + 0x10) = *(uint *)(iVar6 + 0x10) & 0x7fffffff;
            local_40 = (longlong)(int)*(float *)(iVar4 + 0x18);
            *(short *)(iVar6 + 0x16) =
                 *(short *)(iVar6 + 0x16) + (short)(int)*(float *)(iVar4 + 0x18);
          }
        }
        uVar1 = *(uint *)(iVar6 + 0x10);
        if (((((uVar1 & 0x600000) == 0) && ((uVar1 & 0x8000000) == 0)) && (-1 < (int)uVar1)) &&
           (((uVar1 & 0x4000) == 0 && ((uVar1 & 0x3000) == 0)))) {
          local_6c = uVar1 >> 0x17 & 7;
          local_70 = (uint)*(ushort *)(iVar6 + 0x16);
          iVar4 = _HashSetGet(uVar2,&local_70);
          if ((iVar4 != 0) && (*(int *)(iVar4 + 0x14) != 0)) {
            *(uint *)(iVar6 + 0x10) = *(uint *)(iVar6 + 0x10) & 0xfc7fffff | 0x1000000;
            uVar5 = ((undefined2 (*)())_AddConstantParam)(param_1,*(undefined4 *)(iVar4 + 8),
                                      *(undefined4 *)(iVar4 + 0xc),*(undefined4 *)(iVar4 + 0x10),
                                      *(undefined4 *)(iVar4 + 0x18),*(undefined4 *)(iVar4 + 0x1c),
                                      *(undefined4 *)(iVar4 + 0x20),*(undefined4 *)(iVar4 + 0x24));
            *(undefined2 *)(iVar6 + 0x16) = uVar5;
          }
        }
        iVar3 = iVar3 + -1;
        iVar6 = iVar6 + 8;
      } while (iVar3 != 0);
    }
    if (*(int *)(iVar7 + 0x18) < 0) {
      local_6c = 4;
      local_70 = 0;
      iVar3 = _HashSetGet(uVar2,&local_70);
      if ((iVar3 != 0) && (*(int *)(iVar3 + 0x14) != 0)) {
        *(uint *)(iVar7 + 0x18) = *(uint *)(iVar7 + 0x18) & 0x7fffffff;
        local_40 = (longlong)(int)*(float *)(iVar3 + 0x18);
        *(short *)(iVar7 + 0x1a) = *(short *)(iVar7 + 0x1a) + (short)(int)*(float *)(iVar3 + 0x18);
      }
    }
    ((int (*)())_EmulateOp)(param_1,iVar7,uVar2);
  }
  ((int (*)())_ClearRegisterState)(uVar2);
  _HashSetFree(uVar2);
  return;
}

/* _glpDCBAlloc @ 0x97c108e0 (68 bytes) */
int _glpDCBAlloc(param_1)
  int param_1;
{
  void *pvVar1;
  uint uVar2;
  
  pvVar1 = _malloc(param_1 + 0x3fU & 0xffffffe0);
  uVar2 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = (int)pvVar1 + 0x20U & 0xffffffe0;
    *(char *)(uVar2 - 1) = (char)uVar2 - (char)pvVar1;
  }
  return uVar2;
}

/* FUN_97c1092c @ 0x97c1092c (248 bytes) */
int FUN_97c1092c(param_1)
  int param_1;
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  void *pvVar5;
  int iVar6;
  int unaff_r29;
  uint uVar7;
  byte in_cr0;
  
  if ((bool)(in_cr0 >> 2 & 1)) {
    if (param_1 == 0) {
      uVar3 = ((int (*)())_glpDCBAlloc)(unaff_r29);
      return uVar3;
    }
    uVar7 = (uint)*(byte *)(param_1 + -1);
    pvVar5 = _realloc((void *)(param_1 - uVar7),unaff_r29 + 0x3fU & 0xffffffe0);
    uVar3 = 0;
    if (pvVar5 != (void *)0x0) {
      uVar3 = (int)pvVar5 + 0x20U & 0xffffffe0;
      uVar2 = uVar3 - (int)pvVar5 & 0xff;
      if (uVar2 != uVar7) {
        iVar4 = unaff_r29 + 3 >> 2;
        if (uVar2 < uVar7) {
          iVar6 = 0;
          if (0 < iVar4) {
            do {
              iVar1 = iVar6 * 4;
              iVar6 = iVar6 + 1;
              *(undefined4 *)(iVar1 + uVar3) = *(undefined4 *)((int)pvVar5 + iVar1 + uVar7);
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
          }
        }
        else {
          iVar6 = iVar4 + -1;
          if (-1 < iVar6) {
            do {
              iVar1 = iVar6 * 4;
              iVar6 = iVar6 + -1;
              *(undefined4 *)(iVar1 + uVar3) = *(undefined4 *)((int)pvVar5 + iVar1 + uVar7);
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
          }
        }
        *(char *)(uVar3 - 1) = (char)(uVar3 - (int)pvVar5);
      }
    }
  }
  else {
    if (param_1 != 0) {
      ((int (*)())_glpDCBFree)(param_1);
    }
    uVar3 = 0;
  }
  return uVar3;
}

/* _glpDCBFree @ 0x97c10a24 (12 bytes) */
int _glpDCBFree(param_1)
  int param_1;
{
  undefined4 extraout_r3;
  
  _free((void *)(param_1 - (uint)*(byte *)(param_1 + -1)));
  return extraout_r3;
}

/* _PPParserMacroCreateFromMacro @ 0x97c10a30 (200 bytes) */
int _PPParserMacroCreateFromMacro(param_1)
  undefined4 *param_1;
{
  undefined4 *puVar1;
  size_t sVar2;
  void *pvVar3;
  uint uVar4;
  
  puVar1 = (undefined4 *)_PPParserMacroCreate();
  uVar4 = 0;
  sVar2 = _strlen((char *)*param_1);
  pvVar3 = _calloc(sVar2 + 1,1);
  *puVar1 = pvVar3;
  _memmove(pvVar3,(void *)*param_1,sVar2);
  sVar2 = _strlen((char *)param_1[1]);
  pvVar3 = _calloc(sVar2 + 1,1);
  puVar1[1] = pvVar3;
  _memmove(pvVar3,(void *)param_1[1],sVar2);
  _PPParserMacroSetParamStringsCount(puVar1,param_1[2]);
  if (param_1[2] != 0) {
    do {
      _PPParserMacroSetParamString(puVar1,uVar4,*(undefined4 *)(uVar4 * 4 + param_1[3]));
      uVar4 = uVar4 + 1;
    } while (uVar4 < (uint)param_1[2]);
  }
  return puVar1;
}

/* _PPParserIdentifierCreateFromIdentifier @ 0x97c10af8 (100 bytes) */
int _PPParserIdentifierCreateFromIdentifier(param_1)
  undefined4 *param_1;
{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  iVar3 = _PPParserIdentifierCreate();
  _PPParserIdentifierSetName(iVar3,*param_1);
  uVar5 = param_1[6];
  uVar2 = param_1[1];
  uVar4 = param_1[3];
  uVar1 = *(undefined1 *)(param_1 + 4);
  *(undefined4 *)(iVar3 + 8) = param_1[2];
  *(undefined4 *)(iVar3 + 4) = uVar2;
  *(undefined4 *)(iVar3 + 0xc) = uVar4;
  *(undefined1 *)(iVar3 + 0x10) = uVar1;
  *(undefined4 *)(iVar3 + 0x18) = uVar5;
  return iVar3;
}

/* _PPParserScopeCreateFromScope @ 0x97c10b5c (172 bytes) */
int _PPParserScopeCreateFromScope(param_1)
  int *param_1;
{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = *param_1;
  iVar5 = param_1[2];
  pvVar2 = _calloc(0x24,1);
  iVar4 = param_1[6];
  iVar1 = param_1[4];
  *(int *)((int)pvVar2 + 0x14) = param_1[5];
  *(int *)((int)pvVar2 + 0x10) = iVar1;
  *(int *)((int)pvVar2 + 0x18) = iVar4;
  for (; iVar6 != 0; iVar6 = *(int *)(iVar6 + 0x20)) {
    uVar3 = ((int (*)())_PPParserIdentifierCreateFromIdentifier)(iVar6);
    _PPParserScopeAddIdentifier(pvVar2,uVar3);
  }
  for (; iVar5 != 0; iVar5 = *(int *)(iVar5 + 0x1c)) {
    uVar3 = ((int (*)())_PPParserMacroCreateFromMacro)(iVar5);
    _PPParserScopeAddMacro(pvVar2,uVar3);
  }
  return pvVar2;
}

/* _PPParserInitFromParent @ 0x97c10c08 (16 bytes) */
int _PPParserInitFromParent(param_1, param_2)
  int param_1;
  int param_2;
{
  _memcpy((void *)(param_1 + 0x450),(void *)(param_2 + 0x450),0x3c);
  return;
}

/* _PPParserInherit @ 0x97c10c18 (44 bytes) */
int _PPParserInherit(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar1 = *(undefined4 *)(param_2 + 0x30);
  uVar2 = *(undefined4 *)(param_2 + 0x20);
  uVar4 = *(undefined4 *)(param_2 + 0x24);
  uVar3 = *(undefined4 *)(param_2 + 0x28);
  *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_2 + 0x2c);
  *(undefined4 *)(param_1 + 0x30) = uVar1;
  *(undefined4 *)(param_1 + 0x20) = uVar2;
  *(undefined4 *)(param_1 + 0x24) = uVar4;
  *(undefined4 *)(param_1 + 0x28) = uVar3;
  return;
}

/* _PPParserDeclareNVAddressRegisters @ 0x97c10c44 (92 bytes) */
int _PPParserDeclareNVAddressRegisters(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = _PPParserIdentifierCreate();
  _PPParserIdentifierSetName(iVar1,"a0");
  *(undefined4 *)(iVar1 + 0xc) = 0xffffffff;
  *(undefined4 *)(iVar1 + 8) = 0;
  _PPParserScopeAddIdentifier(*(undefined4 *)(param_1 + 0x44c),iVar1);
  return;
}

/* _PPParserParseBlock @ 0x97c10ca0 (236 bytes) */
int _PPParserParseBlock(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char local_110 [260];
  
  iVar1 = _PPParserGetPart(param_1,local_110,0);
  iVar2 = 0x2d;
  if (iVar1 != 0) {
    iVar1 = _memcmp(local_110,"START",6);
    iVar2 = 7;
    if (iVar1 == 0) {
      uVar3 = _PPParserScopeCreate(param_1);
      _PPParserAddScope(param_1,uVar3);
      iVar2 = 0;
    }
    iVar1 = _memcmp(local_110,"END",4);
    if (iVar1 == 0) {
      _PPParserRemoveScope(param_1,*(undefined4 *)(param_1 + 0x44c));
      iVar2 = 0;
    }
    if (iVar2 == 0) {
      iVar1 = _PPParserGetPart(param_1,local_110,0);
      iVar2 = 0x2d;
      if ((iVar1 != 0) && (iVar2 = 0x1e, local_110[0] == ';')) {
        iVar2 = 0;
      }
    }
  }
  return iVar2;
}

/* _PPParserParseDefaultArray @ 0x97c10d8c (240 bytes) */
int _PPParserParseDefaultArray(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  char local_110 [260];
  
  iVar1 = _PPParserGetPart(param_1,local_110,0);
  iVar2 = 0x2d;
  if ((iVar1 != 0) && (iVar2 = 0xb, local_110[0] == '[')) {
    iVar1 = _PPParserGetPart(param_1,local_110,0);
    iVar2 = 0x2d;
    if (iVar1 != 0) {
      if (local_110[0] == ']') {
        *param_2 = 0;
      }
      else {
        _PPParserReturnPart(param_1);
        iVar1 = _PPParserGetInteger(param_1,param_2);
        if (iVar1 != 0) {
          return iVar1;
        }
        if (*param_2 < 0) {
          return 0x23;
        }
        iVar1 = _PPParserGetPart(param_1,local_110,0);
        if (iVar1 == 0) {
          return 0x2d;
        }
        if (local_110[0] != ']') {
          return 0xb;
        }
      }
      iVar2 = 0;
    }
  }
  return iVar2;
}

/* _PPParserParseRangeArray @ 0x97c10e7c (320 bytes) */
int _PPParserParseRangeArray(param_1, param_2, param_3)
  undefined4 param_1;
  int *param_2;
  int *param_3;
{
  int iVar1;
  int iVar2;
  char local_110 [256];
  
  iVar1 = _PPParserGetPart(param_1,local_110,0);
  iVar2 = 0x2d;
  if ((iVar1 != 0) && (iVar2 = 0xb, local_110[0] == '[')) {
    iVar2 = _PPParserGetInteger(param_1,param_2);
    if ((iVar2 == 0) && (iVar2 = 0x23, -1 < *param_2)) {
      iVar1 = _PPParserGetPart(param_1,local_110,0);
      iVar2 = 0x2d;
      if (iVar1 != 0) {
        if (local_110[0] == ']') {
          iVar2 = 0;
          *param_3 = *param_2;
        }
        else {
          iVar1 = _memcmp(local_110,"..",3);
          iVar2 = 0xb;
          if (((iVar1 == 0) && (iVar2 = _PPParserGetInteger(param_1,param_3), iVar2 == 0)) &&
             (iVar2 = 0x23, *param_2 <= *param_3)) {
            iVar1 = _PPParserGetPart(param_1,local_110,0);
            iVar2 = 0x2d;
            if ((iVar1 != 0) && (iVar2 = 0xb, local_110[0] == ']')) {
              iVar2 = 0;
            }
          }
        }
      }
    }
  }
  return iVar2;
}

/* _PPParserParseIndirectArray @ 0x97c10fbc (620 bytes) */
int _PPParserParseIndirectArray(param_1, param_2, param_3)
  int param_1;
  uint *param_2;
  int *param_3;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  char local_120 [256];
  undefined4 local_20;
  
  iVar3 = _PPParserGetPart(param_1,local_120,0);
  if (iVar3 == 0) {
    return 0x2d;
  }
  if (local_120[0] != '[') {
    return 0xb;
  }
  iVar3 = _PPParserGetInteger(param_1,param_3);
  if (iVar3 == 0) {
    if (*param_3 < 0) {
      return 0x23;
    }
  }
  else {
    _PPParserReturnPart(param_1);
    iVar3 = _PPParserGetPart(param_1,local_120,0);
    if (iVar3 == 0) {
      return 0x2d;
    }
    iVar3 = _PPParserScopeFindIdentifier(*(undefined4 *)(param_1 + 0x44c),local_120);
    if (iVar3 == 0) {
      return 0x1a;
    }
    if (*(int *)(iVar3 + 0xc) != -1) {
      return 0x16;
    }
    iVar4 = _PPParserGetPart(param_1,local_120,0);
    if (iVar4 == 0) {
      return 0x2d;
    }
    if (local_120[0] != '.') {
      return 0xd;
    }
    if (iVar4 != 1) {
      return 0xd;
    }
    iVar4 = _PPParserGetPart(param_1,local_120,0);
    if (iVar4 == 0) {
      return 0x2d;
    }
    if (iVar4 != 1) {
      return 0xd;
    }
    if ((*(uint *)(param_1 + 0x48c) & 0x10) == 0) {
      if (local_120[0] != 'x') {
        return 0xd;
      }
      uVar2 = *param_2 & 0xcfffffff;
    }
    else if (local_120[0] == 'x') {
      uVar2 = *param_2 & 0xcfffffff;
    }
    else if (local_120[0] < 'y') {
      if (local_120[0] != 'w') {
        return 0xd;
      }
      uVar2 = *param_2 | 0x30000000;
    }
    else {
      if (local_120[0] == 'y') {
        uVar2 = *param_2;
        iVar4 = 1;
      }
      else {
        if (local_120[0] != 'z') {
          return 0xd;
        }
        uVar2 = *param_2;
        iVar4 = 2;
      }
      uVar2 = iVar4 << 0x1c | uVar2 & 0xcfffffff;
    }
    *param_2 = uVar2;
    iVar4 = _PPParserGetInteger(param_1,&local_20);
    if (iVar4 != 0) {
      _PPParserReturnPart(param_1);
      local_20 = 0;
    }
    if ((*(uint *)(param_1 + 0x48c) & 0x10) == 0) {
      bVar1 = 0x7f < local_20 + 0x40U;
    }
    else {
      bVar1 = 0x1ff < local_20 + 0x100U;
    }
    if (bVar1) {
      return 0x24;
    }
    *(undefined1 *)((int)param_2 + 3) = (undefined1)local_20;
    *param_2 = (*(uint *)(iVar3 + 8) & 1) << 0x1e | *param_2 & 0xbfffffff | 0x80000000;
  }
  iVar3 = _PPParserGetPart(param_1,local_120,0);
  uVar5 = 0x2d;
  if ((iVar3 != 0) && (uVar5 = 0xb, local_120[0] == ']')) {
    uVar5 = 0;
  }
  return uVar5;
}

/* _PPParserParseAddressDeclaration @ 0x97c11228 (340 bytes) */
int _PPParserParseAddressDeclaration(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char local_130 [256];
  undefined4 local_30 [7];
  
  uVar3 = 0;
  while( true ) {
    iVar1 = _PPParserGetPart(param_1,local_130,0);
    if (iVar1 == 0) {
      return 0x2d;
    }
    iVar1 = _PPParserValidateName(param_1,local_130);
    if (iVar1 != 0) {
      return 0x12;
    }
    iVar1 = _PPParserIdentifierCreate();
    _PPParserIdentifierSetName(iVar1,local_130);
    *(undefined4 *)(iVar1 + 0xc) = 0xffffffff;
    *(uint *)(iVar1 + 8) = *(int *)(*(int *)(param_1 + 0x44c) + 0x10) + uVar3;
    iVar2 = _PPParserScopeAddIdentifier(*(undefined4 *)(param_1 + 0x44c),iVar1);
    if (iVar2 != 0) {
      _PPParserIdentifierFree(iVar1);
      return 0x1c;
    }
    uVar3 = uVar3 + 1;
    iVar1 = _PPParserGetPart(param_1,local_130,0);
    if (iVar1 == 0) break;
    if (local_130[0] == ';') {
      iVar1 = *(int *)(param_1 + 0x44c);
      if (*(uint *)(param_1 + 0x46c) < *(int *)(iVar1 + 0x10) + uVar3) {
        return 0x37;
      }
      uVar4 = 0;
      if (uVar3 != 0) {
        while( true ) {
          local_30[0] = *(undefined4 *)(iVar1 + 0x10);
          _PPStreamAddAddressUsage(*(undefined4 *)(param_1 + 0x1c),local_30);
          uVar4 = uVar4 + 1;
          *(int *)(*(int *)(param_1 + 0x44c) + 0x10) =
               *(int *)(*(int *)(param_1 + 0x44c) + 0x10) + 1;
          if (uVar3 <= uVar4) break;
          iVar1 = *(int *)(param_1 + 0x44c);
        }
      }
      return 0;
    }
    if (local_130[0] != ',') {
      return 0x1f;
    }
  }
  return 0x2d;
}

/* _PPParserParseBranchLabel @ 0x97c1137c (68 bytes) */
int _PPParserParseBranchLabel(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  int *param_3;
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _PPParserGetPart(param_1,param_2,0);
  *param_3 = iVar1;
  uVar2 = 0x2d;
  if (iVar1 != 0) {
    uVar2 = 0;
  }
  return uVar2;
}

/* _PPParserParseLabel @ 0x97c113c0 (256 bytes) */
int _PPParserParseLabel(param_1, param_2, param_3)
  int param_1;
  char *param_2;
  size_t param_3;
{
  int iVar1;
  undefined4 uVar2;
  size_t sVar3;
  int iVar4;
  char local_120 [264];
  
  iVar1 = _PPParserGetPart(param_1,local_120,0);
  uVar2 = 3;
  if (iVar1 != 0) {
    if (local_120[0] == ':') {
      iVar1 = *(int *)(param_1 + 0x1c);
      iVar4 = **(int **)(iVar1 + 0x24);
      if (iVar4 != 0) {
        do {
          if ((param_3 == *(size_t *)(iVar4 + 0x10)) &&
             (iVar1 = _strncmp(param_2,(char *)(iVar4 + 0x14),param_3), iVar1 == 0)) {
            return 0x1d;
          }
          iVar4 = *(int *)(iVar4 + 8);
        } while (iVar4 != 0);
        iVar1 = *(int *)(param_1 + 0x1c);
      }
      sVar3 = param_3;
      if (6 < (int)param_3) {
        sVar3 = 6;
      }
      iVar4 = _memcmp(param_2,"start",sVar3);
      if (iVar4 == 0) {
        *(undefined1 *)(param_1 + 0x440) = 1;
      }
      _PPStreamAddLabel(iVar1,param_2,param_3);
      uVar2 = 0;
    }
    else {
      _PPParserReturnPart(param_1);
      uVar2 = 3;
    }
  }
  return uVar2;
}

/* _PPParserParseAddressDestination @ 0x97c114c0 (348 bytes) */
int _PPParserParseAddressDestination(param_1, param_2)
  int param_1;
  uint *param_2;
{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  char local_110 [256];
  
  iVar2 = _PPParserGetPart(param_1,local_110,0);
  iVar3 = 0x2d;
  if (iVar2 != 0) {
    iVar2 = _PPParserScopeFindIdentifier(*(undefined4 *)(param_1 + 0x44c),local_110);
    iVar3 = 0x19;
    if ((iVar2 != 0) && (iVar3 = 0x16, *(int *)(iVar2 + 0xc) == -1)) {
      uVar5 = *param_2;
      *param_2 = uVar5 | 0x2000;
      if ((*(uint *)(param_1 + 0x48c) & 0x10) == 0) {
        uVar5 = uVar5 & 0xfffe3fff | 0x2000;
      }
      else {
        uVar5 = uVar5 | 0x1e000;
      }
      *param_2 = uVar5;
      iVar4 = _PPParserGetPart(param_1,local_110,0);
      iVar3 = 0x2d;
      if (iVar4 != 0) {
        if ((local_110[0] == '.') && (iVar4 == 1)) {
          iVar3 = _PPParserParseDestinationMask(param_1,param_2);
          if (iVar3 != 0) {
            return iVar3;
          }
          uVar5 = *(uint *)(param_1 + 0x48c);
          if (((uVar5 & 0x10) == 0) && ((*param_2 & 0x1e000) != 0x2000)) {
            return 0xc;
          }
        }
        else {
          if ((*(uint *)(param_1 + 0x48c) & 0x10) == 0) {
            return 0xc;
          }
          _PPParserReturnPart(param_1);
          uVar5 = *(uint *)(param_1 + 0x48c);
        }
        if (((uVar5 & 0x10) == 0) ||
           (iVar3 = ((int (*)())_PPParserParseBranchCondition)(param_1,param_2,0), iVar3 == 0)) {
          uVar1 = *(undefined2 *)(iVar2 + 10);
          *param_2 = *param_2 & 0xfff1ffff | 0x80000;
          iVar3 = 0;
          *(undefined2 *)((int)param_2 + 6) = uVar1;
        }
      }
    }
  }
  return iVar3;
}

/* _PPParserParseBranchCondition @ 0x97c1161c (972 bytes) */
int _PPParserParseBranchCondition(param_1, param_2, param_3)
  int param_1;
  uint *param_2;
  int param_3;
{
  bool bVar1;
  bool bVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  char local_110 [256];
  
  bVar1 = param_3 != 0x55;
  if (bVar1) {
    iVar6 = _PPParserGetPart(param_1,local_110,0);
    if (iVar6 == 0) {
      return 0x2d;
    }
    if (local_110[0] != '(') {
      _PPParserReturnPart(param_1);
      return 0;
    }
  }
  iVar6 = _PPParserGetPart(param_1,local_110,0);
  if (iVar6 == 0) {
    return 0x2d;
  }
  if (*(int *)(param_1 + 0x48c) == 0x34) {
    if (1 < iVar6 - 2U) {
      return 0x10;
    }
  }
  else if (iVar6 != 2) {
    return 0x10;
  }
  iVar7 = _memcmp(local_110,"TR",2);
  if (iVar7 == 0) {
    uVar5 = *param_2 & 0x8fffffff;
  }
  else {
    iVar7 = _memcmp(local_110,"EQ",2);
    if (iVar7 == 0) {
      uVar5 = *param_2;
      iVar7 = 1;
    }
    else {
      iVar7 = _memcmp(local_110,"GE",2);
      if (iVar7 == 0) {
        uVar5 = *param_2;
        iVar7 = 2;
      }
      else {
        iVar7 = _memcmp(local_110,"GT",2);
        if (iVar7 == 0) {
          uVar5 = *param_2;
          iVar7 = 3;
        }
        else {
          iVar7 = _memcmp(local_110,"LE",2);
          if (iVar7 == 0) {
            uVar5 = *param_2;
            iVar7 = 4;
          }
          else {
            iVar7 = _memcmp(local_110,"LT",2);
            if (iVar7 == 0) {
              uVar5 = *param_2;
              iVar7 = 5;
            }
            else {
              iVar7 = _memcmp(local_110,"NE",2);
              if (iVar7 != 0) {
                iVar7 = _memcmp(local_110,"FL",2);
                if (iVar7 != 0) {
                  return 0x10;
                }
                uVar5 = *param_2 | 0x70000000;
                goto LAB_97c1180c;
              }
              uVar5 = *param_2;
              iVar7 = 6;
            }
          }
        }
      }
    }
    uVar5 = iVar7 << 0x1c | uVar5 & 0x8fffffff;
  }
LAB_97c1180c:
  *param_2 = uVar5;
  if ((*(int *)(param_1 + 0x48c) == 0x34) && (iVar6 == 3)) {
    if (local_110[2] == '0') {
      uVar5 = *param_2 & 0x7fffffff;
    }
    else {
      if (local_110[2] != '1') goto LAB_97c11858;
      uVar5 = *param_2 | 0x80000000;
    }
    *param_2 = uVar5;
  }
LAB_97c11858:
  iVar6 = _PPParserGetPart(param_1,local_110,0);
  if (iVar6 == 0) {
    return 0x2d;
  }
  if ((bVar1) && (local_110[0] == ')')) {
    return 0;
  }
  if ((local_110[0] != '.') || (iVar6 != 1)) {
    return 0x10;
  }
  iVar6 = _PPParserGetPart(param_1,local_110,0);
  if (iVar6 == 0) {
    return 0x2d;
  }
  if ((iVar6 != 1) && (iVar6 != 4)) {
    return 0x10;
  }
  uVar5 = 0;
  pcVar8 = local_110;
  do {
    cVar3 = *pcVar8;
    if (cVar3 == 'x') {
      iVar7 = 0;
    }
    else {
      if (cVar3 < 'y') {
        bVar2 = cVar3 == 'w';
        iVar7 = 3;
      }
      else {
        if (cVar3 == 'y') {
          iVar7 = 1;
          goto LAB_97c1192c;
        }
        bVar2 = cVar3 == 'z';
        iVar7 = 2;
      }
      if (!bVar2) {
        return 0x10;
      }
    }
LAB_97c1192c:
    if (uVar5 == 1) {
      uVar4 = iVar7 << 0x18 | *param_2 & 0xfcffffff;
LAB_97c1197c:
      *param_2 = uVar4;
    }
    else {
      if (uVar5 == 0) {
        uVar4 = iVar7 << 0x1a | *param_2 & 0xf3ffffff;
        goto LAB_97c1197c;
      }
      if (uVar5 == 2) {
        uVar4 = iVar7 << 0x16 | *param_2 & 0xff3fffff;
        goto LAB_97c1197c;
      }
      if (uVar5 == 3) {
        uVar4 = iVar7 << 0x14 | *param_2 & 0xffcfffff;
        goto LAB_97c1197c;
      }
    }
    if (iVar6 == 4) {
      pcVar8 = pcVar8 + 1;
    }
    uVar5 = uVar5 + 1;
    if (3 < uVar5) {
      if (bVar1) {
        iVar6 = _PPParserGetPart(param_1,local_110,0);
        if (iVar6 == 0) {
          return 0x2d;
        }
        if (local_110[0] != ')') {
          return 0x10;
        }
      }
      return 0;
    }
  } while( true );
}

/* _PPParserParseAddressSourceVar @ 0x97c119e8 (140 bytes) */
int _PPParserParseAddressSourceVar(param_1, param_2)
  int param_1;
  uint *param_2;
{
  undefined2 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 auStack_110 [260];
  
  iVar3 = _PPParserGetPart(param_1,auStack_110,0);
  uVar2 = 0x2d;
  if (iVar3 != 0) {
    iVar3 = _PPParserScopeFindIdentifier(*(undefined4 *)(param_1 + 0x44c),auStack_110);
    uVar2 = 0x1a;
    if ((iVar3 != 0) && (uVar2 = 0x16, *(int *)(iVar3 + 0xc) == -1)) {
      uVar1 = *(undefined2 *)(iVar3 + 10);
      *param_2 = *param_2 & 0xfc7fffff | 0x2000000;
      uVar2 = 0;
      *(undefined2 *)((int)param_2 + 6) = uVar1;
    }
  }
  return uVar2;
}

/* _PPParserParseMacroDeclaration @ 0x97c11a74 (720 bytes) */
int _PPParserParseMacroDeclaration(param_1)
  int *param_1;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  void *pvVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  size_t sVar8;
  char local_130 [256];
  int local_30;
  int local_2c;
  
  iVar1 = _PPParserGetPart(param_1,local_130,0);
  uVar2 = 0x2d;
  if ((iVar1 != 0) && (uVar2 = 10, local_130[0] == '{')) {
    iVar1 = _PPParserGetPart(param_1,local_130,0);
    uVar2 = 0x2d;
    if (iVar1 != 0) {
      iVar3 = _PPParserMacroCreate();
      _PPParserMacroSetSearchString(param_1,iVar3,local_130,iVar1);
      local_30 = param_1[3];
      local_2c = param_1[4];
      uVar5 = 0;
      while( true ) {
        iVar1 = _PPParserGetPart(param_1,local_130,0);
        if (iVar1 == 0) {
          return 0x2d;
        }
        uVar6 = uVar5 + 1;
        iVar1 = _PPParserGetPart(param_1,local_130,0);
        if (iVar1 == 0) {
          return 0x2d;
        }
        if (local_130[0] == '}') break;
        uVar5 = uVar6;
        if (local_130[0] != ',') {
          return 0x1f;
        }
      }
      uVar7 = 0;
      _PPParserMacroSetParamStringsCount(iVar3,uVar6);
      param_1[4] = local_2c;
      param_1[3] = local_30;
      if (uVar6 != 0) {
        do {
          _PPParserGetPart(param_1,local_130,0);
          _PPParserMacroSetParamString(iVar3,uVar7,local_130);
          if (uVar7 != uVar5) {
            _PPParserGetPart(param_1,local_130,0);
          }
          uVar7 = uVar7 + 1;
        } while (uVar7 < uVar6);
      }
      iVar1 = _PPParserGetPart(param_1,local_130,0);
      uVar2 = 0x2d;
      if ((iVar1 != 0) && (uVar2 = 10, local_130[0] == '}')) {
        iVar1 = _PPParserGetPart(param_1,local_130,0);
        uVar2 = 0x2d;
        if ((iVar1 != 0) && (uVar2 = 10, local_130[0] == '=')) {
          iVar1 = _PPParserGetPart(param_1,local_130,0);
          uVar2 = 0x2d;
          if ((iVar1 != 0) && (uVar2 = 10, local_130[0] == '{')) {
            iVar1 = param_1[4];
            *(int *)(iVar3 + 0x10) = param_1[3];
            *(int *)(iVar3 + 0x14) = iVar1;
            local_30 = param_1[3];
            local_2c = param_1[4];
            while( true ) {
              iVar1 = _PPParserGetPart(param_1,local_130,0);
              uVar2 = 0x2d;
              if (iVar1 == 0) break;
              if (local_130[0] == '}') {
                sVar8 = (param_1[3] - local_30) - 2;
                pvVar4 = _malloc((param_1[3] - local_30) - 1);
                _memmove(pvVar4,(void *)(*param_1 + local_30),sVar8);
                *(undefined1 *)((int)pvVar4 + sVar8) = 0;
                _PPParserMacroSetReplaceString(param_1,iVar3,pvVar4);
                iVar1 = _PPParserGetPart(param_1,local_130,0);
                if (iVar1 == 0) {
                  return 0x2d;
                }
                if (local_130[0] != ';') {
                  return 0x1e;
                }
                _PPParserScopeAddMacro(param_1[0x113],iVar3);
                return 0;
              }
            }
          }
        }
      }
    }
  }
  return uVar2;
}

/* _PPParserExpandMacro @ 0x97c11d44 (664 bytes) */
int _PPParserExpandMacro(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  void *pvVar4;
  undefined4 uVar5;
  int iVar6;
  size_t sVar7;
  uint uVar8;
  undefined4 *puVar9;
  char local_130 [256];
  undefined4 local_30;
  undefined4 local_2c;
  
  local_30 = *(undefined4 *)(param_1 + 0xc);
  local_2c = *(undefined4 *)(param_1 + 0x10);
  iVar6 = 0;
  do {
    iVar1 = _PPParserGetPart(param_1,local_130,0);
    if (iVar1 == 0) {
      return 0x2d;
    }
    if (local_130[0] == ',') {
      iVar6 = iVar6 + 1;
    }
  } while (local_130[0] != ';');
  sVar7 = iVar6 + 1;
  uVar2 = 0x26;
  if (sVar7 == param_2[2]) {
    uVar8 = 0;
    puVar3 = _calloc(4,sVar7);
    *(undefined4 *)(param_1 + 0x10) = local_2c;
    *(undefined4 *)(param_1 + 0xc) = local_30;
    if (sVar7 != 0) {
      do {
        pvVar4 = _calloc(0x100,1);
        puVar3[uVar8] = pvVar4;
        _PPParserGetPart(param_1,local_130,0);
        if ((local_130[0] != ',') && (local_130[0] != ';')) {
          while( true ) {
            _strcat((char *)puVar3[uVar8],local_130);
            _PPParserGetPart(param_1,local_130,0);
            if ((local_130[0] == ',') || (local_130[0] == ';')) break;
            _strcat((char *)puVar3[uVar8]," ");
          }
        }
        uVar8 = uVar8 + 1;
      } while (uVar8 < sVar7);
    }
    iVar6 = _PPParserMacroGetReplaceString(param_2,*(undefined4 *)(param_1 + 0x48c),puVar3,0);
    uVar8 = 0;
    pvVar4 = _malloc(iVar6 + 1);
    _PPParserMacroGetReplaceString(param_2,*(undefined4 *)(param_1 + 0x48c),puVar3,pvVar4);
    puVar9 = puVar3;
    if (sVar7 != 0) {
      do {
        uVar8 = uVar8 + 1;
        _free((void *)*puVar9);
        puVar9 = puVar9 + 1;
      } while (uVar8 < sVar7);
    }
    _free(puVar3);
    iVar6 = _PPParserCreate(*(undefined4 *)(param_1 + 0x48c));
    ((int (*)())_PPParserInitFromParent)(iVar6,param_1);
    ((int (*)())_PPParserInherit)(iVar6,param_1);
    uVar2 = ((int (*)())_PPParserScopeCreateFromScope)(*(undefined4 *)(param_1 + 0x44c));
    _PPParserAddScope(iVar6,uVar2);
    _PPParserAttachString(iVar6,pvVar4,0);
    _PPParserAttachStream(iVar6,*(undefined4 *)(param_1 + 0x1c));
    uVar5 = *(undefined4 *)(param_1 + 0xc);
    *(byte *)(iVar6 + 0x441) = *(byte *)(iVar6 + 0x441) | 1;
    uVar2 = *(undefined4 *)(param_1 + 0x10);
    *(undefined4 *)(iVar6 + 0x14) = uVar5;
    *(undefined4 *)(iVar6 + 0x18) = uVar2;
    *(byte *)(iVar6 + 0x441) = *(byte *)(iVar6 + 0x441) | 2;
    iVar1 = _PPParserParse(iVar6);
    if (iVar1 == 0) {
      ((int (*)())_PPParserInherit)(param_1,iVar6);
      _PPParserFree(iVar6);
      _free(pvVar4);
      uVar2 = 0;
    }
    else {
      ((int (*)())_PPParserBuildErrorString)(iVar6,iVar1,*param_2);
      sVar7 = _strlen((char *)(iVar6 + 0x3c));
      _memmove((void *)(param_1 + 0x3c),(char *)(iVar6 + 0x3c),sVar7);
      _PPParserFree(iVar6);
      uVar2 = 2;
    }
  }
  return uVar2;
}

/* _PPParserBuildErrorString @ 0x97c11fdc (912 bytes) */
int _PPParserBuildErrorString(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  char *pcVar1;
  int iVar2;
  undefined1 auStack_130 [16];
  undefined1 auStack_120 [264];
  
  switch(param_2) {
  default:
    pcVar1 = "";
    break;
  case 4:
    pcVar1 = "missing or invalid version";
    break;
  case 5:
    pcVar1 = "unrecognised option";
    break;
  case 6:
    pcVar1 = "unrecognised statement";
    break;
  case 7:
    pcVar1 = "unrecognised block parameter";
    break;
  case 8:
    pcVar1 = "unexpected option";
    break;
  case 9:
    pcVar1 = "unexpected statement";
    break;
  case 10:
    pcVar1 = "malformed declaration";
    break;
  case 0xb:
    pcVar1 = "malformed array specifier";
    break;
  case 0xc:
    pcVar1 = "malformed destination mask";
    break;
  case 0xd:
    pcVar1 = "malformed source swizzle";
    break;
  case 0xe:
    pcVar1 = "malformed source texture";
    break;
  case 0xf:
    pcVar1 = "malformed extended swizzle code";
    break;
  case 0x10:
    pcVar1 = "invalid condition mask";
    break;
  case 0x11:
    pcVar1 = "invalid texture coordinate plane";
    break;
  case 0x12:
    pcVar1 = "invalid identifier name";
    break;
  case 0x13:
    pcVar1 = "invalid attribute pair";
    break;
  case 0x14:
    pcVar1 = "invalid swizzle for scalar op";
    break;
  case 0x15:
    pcVar1 = "invalid number";
    break;
  case 0x16:
    pcVar1 = "invalid address identifier";
    break;
  case 0x17:
    pcVar1 = "invalid source identifier";
    break;
  case 0x18:
    pcVar1 = "invalid dest identifier";
    break;
  case 0x19:
    pcVar1 = "undefined destination identifier";
    break;
  case 0x1a:
    pcVar1 = "undefined source identifier";
    break;
  case 0x1b:
    pcVar1 = "undefined branch label";
    break;
  case 0x1c:
    pcVar1 = "an identifier with this name already exists";
    break;
  case 0x1d:
    pcVar1 = "duplicate branch label";
    break;
  case 0x1e:
    pcVar1 = "missing semicolon";
    break;
  case 0x1f:
    pcVar1 = "missing comma";
    break;
  case 0x20:
    pcVar1 = "identifier is not an array";
    break;
  case 0x21:
    pcVar1 = "identifier is an array";
    break;
  case 0x22:
    pcVar1 = "use of result.position illegal with ARB_position_invariant";
    break;
  case 0x23:
    pcVar1 = "out of range array index";
    break;
  case 0x24:
    pcVar1 = "out of range indirect offset";
    break;
  case 0x25:
    pcVar1 = "incorrect array component count";
    break;
  case 0x26:
    pcVar1 = "incorrect argument count for macro";
    break;
  case 0x27:
    pcVar1 = "conflicting option specification";
    break;
  case 0x28:
    pcVar1 = "conflicting texture target";
    break;
  case 0x29:
    pcVar1 = "impossible array";
    break;
  case 0x2a:
    pcVar1 = "precision qualifier only allowed for temporaries or outputs";
    break;
  case 0x2b:
    pcVar1 = "unpack instructions cannot take SHORT source";
    break;
  case 0x2c:
    pcVar1 = "pack instructions cannot take SHORT destination";
    break;
  case 0x2d:
    pcVar1 = "unexpected end of program";
    break;
  case 0x2e:
    pcVar1 = "program env limit exceeded";
    break;
  case 0x2f:
    pcVar1 = "program local limit exceeded";
    break;
  case 0x30:
    pcVar1 = "program matrices limit exceeded";
    break;
  case 0x31:
    pcVar1 = "program matrix stack depth exceeded";
    break;
  case 0x32:
    pcVar1 = "program instruction count exceeded";
    break;
  case 0x33:
    pcVar1 = "program temporary count exceeded";
    break;
  case 0x34:
    pcVar1 = "program parameter count exceeded";
    break;
  case 0x35:
  case 0x36:
    pcVar1 = "program attribute count exceeded";
    break;
  case 0x37:
    pcVar1 = "program address registers limit exceeded";
    break;
  case 0x38:
    pcVar1 = "texture unit limit exceeded";
    break;
  case 0x39:
    pcVar1 = "vertex unit limit exceeded";
    break;
  case 0x3a:
    pcVar1 = "palette matrix limit exceeded";
    break;
  case 0x3b:
    pcVar1 = "clip plane limit exceeded";
    break;
  case 0x3c:
    pcVar1 = "light limit exceeded";
    break;
  case 0x3d:
    pcVar1 = "vertex attribute limit exceeded";
  }
  _PPParserReturnPart(param_1);
  _PPParserGetPart(param_1,auStack_120,0);
  _PPParserReturnCharacter(param_1,auStack_130);
  iVar2 = *(int *)(param_1 + 0x10) + 1;
  _PPParserGetCharacter(param_1,auStack_130);
  if (param_3 == 0) {
    _sprintf((char *)(param_1 + 0x3c),"Error on line %u: %s (hint: \'%s\')",iVar2,pcVar1,auStack_120
            );
  }
  else {
    _sprintf((char *)(param_1 + 0x3c),"Error in macro %s on line %u: %s (hint: \'%s\')",param_3,
             iVar2,pcVar1,auStack_120);
  }
  return;
}

/* _pow_10 @ 0x97c12464 (156 bytes) */
double _pow_10(int param_1)
{
  undefined *puVar1;
  double dVar2;
  
  dVar2 = DOUBLE_97c30a60;
  if (param_1 < 1) {
    if (-1 < param_1) {
      return DOUBLE_97c30a60;
    }
    for (; param_1 < -0x20; param_1 = param_1 + 0x20) {
      dVar2 = dVar2 * DOUBLE_97c30aa8;
    }
    puVar1 = &_down_1 + param_1 * -8;
  }
  else {
    for (; 0x20 < param_1; param_1 = param_1 + -0x20) {
      dVar2 = dVar2 * DOUBLE_97c30ab0;
    }
    puVar1 = &_up_0 + param_1 * 8;
  }
  return dVar2 * *(double *)(puVar1 + -8);
}

/* _glp_strtod @ 0x97c12500 (824 bytes) */
double _glp_strtod(byte *param_1,undefined4 *param_2)
{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  byte bVar6;
  byte *pbVar7;
  byte *pbVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  byte *pbStack00000018;
  
  bVar4 = false;
  bVar3 = false;
  bVar2 = false;
  if (*param_1 == 0x2b) {
LAB_97c12560:
    param_1 = param_1 + 1;
  }
  else if (*param_1 == 0x2d) {
    bVar4 = true;
    goto LAB_97c12560;
  }
  bVar6 = *param_1;
  bVar1 = bVar6 == 0x2e;
  pbStack00000018 = param_1;
  dVar9 = DOUBLE_97c30a48;
  if (bVar6 == 0) {
LAB_97c12644:
    if (bVar1) goto LAB_97c12648;
  }
  else {
    if (!bVar1) {
      if ((bVar6 != 0x65) && (pbVar7 = param_1, bVar6 != 0x45)) {
        while (bVar6 - 0x30 < 10) {
          bVar6 = pbVar7[1];
          pbVar7 = pbVar7 + 1;
        }
        if (&STACKARG(0x0) != (undefined1 *)0xffffffe8) {
          pbStack00000018 = pbVar7;
        }
        pbVar7 = pbVar7 + -1;
        if (param_1 <= pbVar7) {
          iVar5 = (int)pbVar7 - (int)(param_1 + -1);
          dVar10 = DOUBLE_97c30a60;
          do {
            bVar6 = *pbVar7;
            pbVar7 = pbVar7 + -1;
            dVar9 = ((double)CONCAT44(0x43300000,(int)(char)bVar6 - 0x30U ^ 0x80000000) -
                    DOUBLE_97c30a58) * dVar10 + dVar9;
            dVar10 = dVar10 * DOUBLE_97c30a50;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
        }
        bVar6 = *pbStack00000018;
        bVar2 = true;
        bVar1 = bVar6 == 0x2e;
      }
      goto LAB_97c12644;
    }
LAB_97c12648:
    pbVar8 = pbStack00000018 + 1;
    bVar6 = pbStack00000018[1];
    pbVar7 = pbVar8;
    while (bVar6 - 0x30 < 10) {
      pbVar7 = pbVar7 + 1;
      bVar6 = *pbVar7;
    }
    dVar10 = DOUBLE_97c30a48;
    if (&STACKARG(0x0) != (undefined1 *)0xffffffe8) {
      pbStack00000018 = pbVar7;
    }
    while (pbVar7 = pbVar7 + -1, pbVar8 <= pbVar7) {
      dVar10 = dVar10 * DOUBLE_97c30ab8 +
               ((double)CONCAT44(0x43300000,(int)(char)*pbVar7 - 0x30U ^ 0x80000000) -
               DOUBLE_97c30a58);
    }
    bVar2 = true;
    bVar6 = *pbStack00000018;
    dVar9 = dVar10 * DOUBLE_97c30ab8 + dVar9;
  }
  if ((!bVar2) || ((bVar6 != 0x65 && (bVar6 != 0x45)))) goto LAB_97c12804;
  pbVar7 = pbStack00000018 + 1;
  if (*pbVar7 == 0x2b) {
LAB_97c12738:
    pbVar7 = pbStack00000018 + 2;
  }
  else if (*pbVar7 == 0x2d) {
    bVar3 = true;
    goto LAB_97c12738;
  }
  bVar6 = *pbVar7;
  pbVar8 = pbVar7;
  while (bVar6 - 0x30 < 10) {
    pbVar8 = pbVar8 + 1;
    bVar6 = *pbVar8;
  }
  pbStack00000018 = pbVar7;
  if (&STACKARG(0x0) != (undefined1 *)0xffffffe8) {
    pbStack00000018 = pbVar8;
  }
  pbVar8 = pbVar8 + -1;
  dVar10 = DOUBLE_97c30a48;
  if (pbVar7 <= pbVar8) {
    iVar5 = (int)pbVar8 - (int)(pbVar7 + -1);
    dVar11 = DOUBLE_97c30a60;
    do {
      bVar6 = *pbVar8;
      pbVar8 = pbVar8 + -1;
      dVar10 = ((double)CONCAT44(0x43300000,(int)(char)bVar6 - 0x30U ^ 0x80000000) - DOUBLE_97c30a58
               ) * dVar11 + dVar10;
      dVar11 = dVar11 * DOUBLE_97c30a50;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  if (bVar3) {
    dVar10 = -dVar10;
  }
  dVar10 = (double)((double (*)())_pow_10)((int)dVar10);
  dVar9 = dVar9 * dVar10;
LAB_97c12804:
  if (bVar4) {
    dVar9 = -dVar9;
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = pbStack00000018;
  }
  return dVar9;
}

/* _glp_dtostr @ 0x97c12838 (1096 bytes) */
char * _glp_dtostr(undefined4 param_1,undefined4 param_2,char *param_3,uint param_4,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  char *pcVar1;
  char cVar2;
  double dVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  uint local_50 [6];
  
  dVar8 = DOUBLE_97c30a48;
  pcVar5 = param_3 + param_4;
  if (fparam_2 <= DOUBLE_97c30a48) {
    fparam_2 = DOUBLE_97c30ac0;
  }
  if (param_4 < 2) {
    return (char *)0x0;
  }
  if (fparam_1 < DOUBLE_97c30a48) {
    fparam_1 = -fparam_1;
    *param_3 = '-';
    param_3 = param_3 + 1;
  }
  dVar10 = fparam_2;
  if (dVar8 < fparam_1) {
    if ((fparam_1 < DOUBLE_97c30ac8) || (DOUBLE_97c30ad8 < fparam_1)) {
      _frexp(fparam_1,local_50);
      dVar8 = _round(((double)CONCAT44(0x43300000,local_50[0] ^ 0x80000000) - DOUBLE_97c30a58) *
                     DOUBLE_97c30ad0);
      local_50[0] = (uint)dVar8;
      dVar8 = (double)((double (*)())_pow_10)(local_50[0]);
      dVar9 = (double)((double (*)())_pow_10)(-local_50[0]);
      dVar10 = fparam_2 * dVar8;
      dVar8 = fparam_1 * dVar9;
    }
    else {
      local_50[0] = 0;
      dVar8 = fparam_1;
    }
    for (; DOUBLE_97c30a50 <= dVar8 + fparam_2 * DOUBLE_97c30a88; dVar8 = dVar8 * DOUBLE_97c30ab8) {
      local_50[0] = local_50[0] + 1;
      dVar10 = dVar10 * DOUBLE_97c30a50;
    }
    for (; dVar8 + fparam_2 * DOUBLE_97c30a88 < DOUBLE_97c30a60; dVar8 = dVar8 * DOUBLE_97c30a50) {
      local_50[0] = local_50[0] - 1;
      dVar10 = dVar10 * DOUBLE_97c30ab8;
    }
    if (3 < (int)(((int)local_50[0] >> 0x1f ^ local_50[0]) - ((int)local_50[0] >> 0x1f)))
    goto LAB_97c12a28;
  }
  local_50[0] = 0;
  dVar8 = fparam_1;
  fparam_2 = dVar10;
LAB_97c12a28:
  dVar8 = fparam_2 * DOUBLE_97c30a88 + dVar8;
  dVar10 = _floor(dVar8);
  dVar3 = DOUBLE_97c30ab8;
  dVar9 = DOUBLE_97c30a50;
  pcVar6 = param_3;
  while (fparam_2 < dVar10) {
    if (pcVar6 == pcVar5) {
      return (char *)0x0;
    }
    dVar11 = dVar10 * dVar3;
    dVar10 = _floor(dVar11);
    *pcVar6 = (char)(int)((dVar11 - dVar10) * dVar9) + '0';
    pcVar6 = pcVar6 + 1;
  }
  if (param_3 < pcVar6) {
    iVar4 = (int)pcVar6 - (int)param_3;
    pcVar7 = pcVar6;
    while (1 < iVar4) {
      pcVar7 = pcVar7 + -1;
      cVar2 = *pcVar7;
      *pcVar7 = *param_3;
      *param_3 = cVar2;
      param_3 = param_3 + 1;
      iVar4 = (int)pcVar7 - (int)param_3;
    }
  }
  else {
    *pcVar6 = '0';
    pcVar6 = pcVar6 + 1;
  }
  dVar9 = _floor(dVar8);
  dVar10 = DOUBLE_97c30a50;
  dVar8 = dVar8 - dVar9;
  if (dVar8 <= fparam_2) {
    if (local_50[0] == 0) {
      if ((int)pcVar5 - (int)pcVar6 < 2) {
        return (char *)0x0;
      }
      *pcVar6 = '.';
      pcVar6[1] = '0';
      pcVar6 = pcVar6 + 2;
    }
  }
  else {
    if (pcVar6 == pcVar5) {
      return (char *)0x0;
    }
    *pcVar6 = '.';
    pcVar6 = pcVar6 + 1;
    do {
      if (pcVar6 == pcVar5) {
        return (char *)0x0;
      }
      dVar8 = dVar8 * dVar10;
      fparam_2 = fparam_2 * dVar10;
      dVar9 = _floor(dVar8);
      dVar8 = dVar8 - dVar9;
      *pcVar6 = (char)(int)dVar9 + '0';
      pcVar6 = pcVar6 + 1;
    } while (fparam_2 < dVar8);
  }
  if (local_50[0] != 0) {
    if ((int)pcVar5 - (int)pcVar6 < 3) {
      return (char *)0x0;
    }
    *pcVar6 = 'e';
    pcVar7 = pcVar6 + 1;
    pcVar1 = pcVar7;
    if ((int)local_50[0] < 0) {
      local_50[0] = -local_50[0];
      *pcVar7 = '-';
      pcVar7 = pcVar6 + 2;
      pcVar1 = pcVar7;
    }
    while (pcVar6 = pcVar1, 0 < (int)local_50[0]) {
      if (pcVar6 == pcVar5) {
        return (char *)0x0;
      }
      *pcVar6 = (char)local_50[0] + (char)((int)local_50[0] / 10) * -10 + '0';
      local_50[0] = (int)local_50[0] / 10;
      pcVar1 = pcVar6 + 1;
    }
    iVar4 = (int)pcVar6 - (int)pcVar7;
    pcVar1 = pcVar6;
    while (1 < iVar4) {
      pcVar1 = pcVar1 + -1;
      cVar2 = *pcVar1;
      *pcVar1 = *pcVar7;
      *pcVar7 = cVar2;
      pcVar7 = pcVar7 + 1;
      iVar4 = (int)pcVar1 - (int)pcVar7;
    }
  }
  pcVar7 = (char *)0x0;
  if (pcVar6 != pcVar5) {
    *pcVar6 = '\0';
    pcVar7 = pcVar6;
  }
  return pcVar7;
}

/* std____throw_bad_exception @ 0x97c12c80 (68 bytes) */
int std____throw_bad_exception()
{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)___cxa_allocate_exception(4);
  puVar2 = PTR_typeinfo_a7b7c180;
  puVar1 = PTR___ZNSt13bad_exceptionD1Ev_a7b7c17c;
  *puVar3 = PTR_vtable_a7b7c184 + 8;
                    
  ___cxa_throw(puVar3,puVar2,puVar1);
}

/* std____throw_bad_alloc @ 0x97c12cc4 (68 bytes) */
int std____throw_bad_alloc()
{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)___cxa_allocate_exception(4);
  puVar2 = PTR_typeinfo_a7b7c174;
  puVar1 = PTR___ZNSt9bad_allocD1Ev_a7b7c170;
  *puVar3 = PTR_vtable_a7b7c178 + 8;
                    
  ___cxa_throw(puVar3,puVar2,puVar1);
}

/* std____throw_bad_cast @ 0x97c12d08 (68 bytes) */
int std____throw_bad_cast()
{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)___cxa_allocate_exception(4);
  puVar2 = PTR_typeinfo_a7b7c168;
  puVar1 = PTR___ZNSt8bad_castD1Ev_a7b7c164;
  *puVar3 = PTR_vtable_a7b7c16c + 8;
                    
  ___cxa_throw(puVar3,puVar2,puVar1);
}

/* std____throw_bad_typeid @ 0x97c12d4c (68 bytes) */
int std____throw_bad_typeid()
{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)___cxa_allocate_exception(4);
  puVar2 = PTR_typeinfo_a7b7c15c;
  puVar1 = PTR___ZNSt10bad_typeidD1Ev_a7b7c158;
  *puVar3 = PTR_vtable_a7b7c160 + 8;
                    
  ___cxa_throw(puVar3,puVar2,puVar1);
}

/* std____throw_logic_error @ 0x97c12d90 (108 bytes) */
int std____throw_logic_error(param_1)
  char *param_1;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  void *this;
  char in_RESERVE;
  byte in_cr0;
  int local_40 [4];
  unsigned char aaStack_30 [40];
  
  __ZNSsC1EPKcRKSaIcE(local_40,param_1,aaStack_30);
  this = (void *)___cxa_allocate_exception(8);
  __ZNSt11logic_errorC1ERKSs(this,(unsigned char *)local_40);
  piVar2 = (int *)(local_40[0] + -4);
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar3 < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(local_40[0] + -0xc));
  }
                    
  ___cxa_throw(this,PTR_typeinfo_a7b7c154,PTR___ZNSt11logic_errorD1Ev_a7b7c150);
}

/* std____throw_domain_error @ 0x97c12e18 (108 bytes) */
int std____throw_domain_error(param_1)
  char *param_1;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  void *this;
  char in_RESERVE;
  byte in_cr0;
  int local_40 [4];
  unsigned char aaStack_30 [40];
  
  __ZNSsC1EPKcRKSaIcE(local_40,param_1,aaStack_30);
  this = (void *)___cxa_allocate_exception(8);
  __ZNSt12domain_errorC1ERKSs(this,(unsigned char *)local_40);
  piVar2 = (int *)(local_40[0] + -4);
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar3 < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(local_40[0] + -0xc));
  }
                    
  ___cxa_throw(this,PTR_typeinfo_a7b7c14c,PTR___ZNSt12domain_errorD1Ev_a7b7c148);
}

/* std____throw_invalid_argument @ 0x97c12ea0 (108 bytes) */
int std____throw_invalid_argument(param_1)
  char *param_1;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  void *this;
  char in_RESERVE;
  byte in_cr0;
  int local_40 [4];
  unsigned char aaStack_30 [40];
  
  __ZNSsC1EPKcRKSaIcE(local_40,param_1,aaStack_30);
  this = (void *)___cxa_allocate_exception(8);
  __ZNSt16invalid_argumentC1ERKSs(this,(unsigned char *)local_40);
  piVar2 = (int *)(local_40[0] + -4);
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar3 < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(local_40[0] + -0xc));
  }
                    
  ___cxa_throw(this,PTR_typeinfo_a7b7c144,PTR___ZNSt16invalid_argumentD1Ev_a7b7c140);
}

/* std____throw_length_error @ 0x97c12f28 (108 bytes) */
int std____throw_length_error(param_1)
  char *param_1;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  void *this;
  char in_RESERVE;
  byte in_cr0;
  int local_40 [4];
  unsigned char aaStack_30 [40];
  
  __ZNSsC1EPKcRKSaIcE(local_40,param_1,aaStack_30);
  this = (void *)___cxa_allocate_exception(8);
  __ZNSt12length_errorC1ERKSs(this,(unsigned char *)local_40);
  piVar2 = (int *)(local_40[0] + -4);
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar3 < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(local_40[0] + -0xc));
  }
                    
  ___cxa_throw(this,PTR_typeinfo_a7b7c13c,PTR___ZNSt12length_errorD1Ev_a7b7c138);
}

/* std____throw_out_of_range @ 0x97c12fb0 (108 bytes) */
int std____throw_out_of_range(param_1)
  char *param_1;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  void *this;
  char in_RESERVE;
  byte in_cr0;
  int local_40 [4];
  unsigned char aaStack_30 [40];
  
  __ZNSsC1EPKcRKSaIcE(local_40,param_1,aaStack_30);
  this = (void *)___cxa_allocate_exception(8);
  __ZNSt12out_of_rangeC1ERKSs(this,(unsigned char *)local_40);
  piVar2 = (int *)(local_40[0] + -4);
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar3 < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(local_40[0] + -0xc));
  }
                    
  ___cxa_throw(this,PTR_typeinfo_a7b7c134,PTR___ZNSt12out_of_rangeD1Ev_a7b7c130);
}

/* std____throw_runtime_error @ 0x97c13038 (108 bytes) */
int std____throw_runtime_error(param_1)
  char *param_1;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  void *this;
  char in_RESERVE;
  byte in_cr0;
  int local_40 [4];
  unsigned char aaStack_30 [40];
  
  __ZNSsC1EPKcRKSaIcE(local_40,param_1,aaStack_30);
  this = (void *)___cxa_allocate_exception(8);
  __ZNSt13runtime_errorC1ERKSs(this,(unsigned char *)local_40);
  piVar2 = (int *)(local_40[0] + -4);
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar3 < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(local_40[0] + -0xc));
  }
                    
  ___cxa_throw(this,PTR_typeinfo_a7b7c12c,PTR___ZNSt13runtime_errorD1Ev_a7b7c128);
}

/* std____throw_range_error @ 0x97c130c0 (108 bytes) */
int std____throw_range_error(param_1)
  char *param_1;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  void *this;
  char in_RESERVE;
  byte in_cr0;
  int local_40 [4];
  unsigned char aaStack_30 [40];
  
  __ZNSsC1EPKcRKSaIcE(local_40,param_1,aaStack_30);
  this = (void *)___cxa_allocate_exception(8);
  __ZNSt11range_errorC1ERKSs(this,(unsigned char *)local_40);
  piVar2 = (int *)(local_40[0] + -4);
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar3 < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(local_40[0] + -0xc));
  }
                    
  ___cxa_throw(this,PTR_typeinfo_a7b7c124,PTR___ZNSt11range_errorD1Ev_a7b7c120);
}

/* std____throw_overflow_error @ 0x97c13148 (108 bytes) */
int std____throw_overflow_error(param_1)
  char *param_1;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  void *this;
  char in_RESERVE;
  byte in_cr0;
  int local_40 [4];
  unsigned char aaStack_30 [40];
  
  __ZNSsC1EPKcRKSaIcE(local_40,param_1,aaStack_30);
  this = (void *)___cxa_allocate_exception(8);
  __ZNSt14overflow_errorC1ERKSs(this,(unsigned char *)local_40);
  piVar2 = (int *)(local_40[0] + -4);
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar3 < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(local_40[0] + -0xc));
  }
                    
  ___cxa_throw(this,PTR_typeinfo_a7b7c11c,PTR___ZNSt14overflow_errorD1Ev_a7b7c118);
}

/* std____throw_underflow_error @ 0x97c131d0 (108 bytes) */
int std____throw_underflow_error(param_1)
  char *param_1;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  void *this;
  char in_RESERVE;
  byte in_cr0;
  int local_40 [4];
  unsigned char aaStack_30 [40];
  
  __ZNSsC1EPKcRKSaIcE(local_40,param_1,aaStack_30);
  this = (void *)___cxa_allocate_exception(8);
  __ZNSt15underflow_errorC1ERKSs(this,(unsigned char *)local_40);
  piVar2 = (int *)(local_40[0] + -4);
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar3 < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(local_40[0] + -0xc));
  }
                    
  ___cxa_throw(this,PTR_typeinfo_a7b7c114,PTR___ZNSt15underflow_errorD1Ev_a7b7c110);
}

/* __ZNKSs7_M_dataEv @ 0x97c13258 (8 bytes) */
int __ZNKSs7_M_dataEv(this)
  void *this;
{
  return *(undefined4 *)this;
}

/* __ZNSs7_M_dataEPc @ 0x97c13260 (12 bytes) */
int __ZNSs7_M_dataEPc(this, param_2)
  void *this;
  char *param_2;
{
  *(char **)this = param_2;
  return param_2;
}

/* __ZNKSs6_M_repEv @ 0x97c1326c (12 bytes) */
int __ZNKSs6_M_repEv(this)
  void *this;
{
  return *(int *)this + -0xc;
}

/* __ZNKSs9_M_ibeginEv @ 0x97c13278 (12 bytes) */
int __ZNKSs9_M_ibeginEv(param_1, param_2)
  undefined4 *param_1;
  undefined4 *param_2;
{
  *param_1 = *param_2;
  return;
}

/* __ZNKSs4sizeEv @ 0x97c13284 (12 bytes) */
int __ZNKSs4sizeEv(this)
  void *this;
{
  return *(undefined4 *)(*(int *)this + -0xc);
}

/* __ZNKSs7_M_iendEv @ 0x97c13290 (20 bytes) */
int __ZNKSs7_M_iendEv(param_1, param_2)
  int *param_1;
  int *param_2;
{
  *param_1 = *param_2 + *(int *)(*param_2 + -0xc);
  return;
}

/* __ZNKSs4_Rep12_M_is_leakedEv @ 0x97c132a4 (12 bytes) */
int __ZNKSs4_Rep12_M_is_leakedEv(this)
  void *this;
{
  return *(uint *)((int)this + 8) >> 0x1f;
}

