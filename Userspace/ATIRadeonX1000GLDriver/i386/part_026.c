#include "decls.h"

/* FUN_000f6fb6 @ 0xf6fb6 (5 bytes) */
int FUN_000f6fb6()
{
  return;
}

/* FUN_000f6fbc @ 0xf6fbc (224 bytes) */
int FUN_000f6fbc(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  undefined4 uVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  undefined4 local_14;
  undefined4 local_10;
  
  local_10 = 0;
  iVar4 = 3;
  do {
    bVar3 = (byte)iVar4;
    if (((int)*(char *)(param_1 + 0x15c) >> (bVar3 & 0x1f) & 1U) == 0) {
      if (((int)*(char *)(param_2 + 0x15c) >> (bVar3 & 0x1f) & 1U) != 0) goto LAB_000f703e;
    }
    else {
      if (((int)*(char *)(param_2 + 0x15c) >> (bVar3 & 0x1f) & 1U) == 0) goto LAB_000f7085;
      local_10 = local_10 + 1;
    }
    iVar4 = iVar4 + -1;
  } while (iVar4 != -1);
  if (0 < local_10) {
    local_14 = 0;
    do {
      iVar4 = local_14 * 0x18 + 0x10;
      iVar5 = param_1 + iVar4;
      iVar4 = param_2 + iVar4;
      uVar1 = *(uint *)(iVar5 + 0xc);
      if ((uVar1 != *(uint *)(iVar4 + 0xc)) || (*(int *)(iVar5 + 0x10) != *(int *)(iVar4 + 0x10))) {
        bVar6 = uVar1 < *(uint *)(iVar4 + 0xc);
        if (uVar1 == *(uint *)(iVar4 + 0xc)) {
          if (uVar1 == 2) {
            bVar6 = *(float *)(iVar5 + 0x10) <= *(float *)(iVar4 + 0x10) &&
                    *(float *)(iVar4 + 0x10) != *(float *)(iVar5 + 0x10);
          }
          else {
            bVar6 = *(uint *)(iVar5 + 0x10) < *(uint *)(iVar4 + 0x10);
          }
        }
        if (bVar6) {
LAB_000f7085:
          uVar2 = 0xffffffff;
        }
        else {
LAB_000f703e:
          uVar2 = 1;
        }
        return uVar2;
      }
      local_14 = local_14 + 1;
    } while (local_14 != local_10);
  }
  return 0;
}

/* FUN_000f709c @ 0xf709c (35 bytes) */
int FUN_000f709c(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = 0;
  do {
    if (((int)*(char *)(param_1 + 0x15c) >> ((byte)iVar1 & 0x1f) & 1U) == 0) {
      return iVar1;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 != 4);
  return 4;
}

/* FUN_000f70c0 @ 0xf70c0 (84 bytes) */
int FUN_000f70c0(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = 0;
  do {
    if (((int)*(char *)(param_2 + 0x15c) >> ((byte)iVar1 & 0x1f) & 1U) == 0) break;
    iVar1 = iVar1 + 1;
  } while (iVar1 != 4);
  FUN_001a83e0();
  return;
}

/* FUN_000f7114 @ 0xf7114 (512 bytes) */
int FUN_000f7114(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined4 *puVar6;
  int local_1e0;
  int *local_1d0;
  int local_1c0;
  int local_1bc [75];
  undefined4 local_90 [24];
  undefined4 local_30 [4];
  byte local_20 [16];
  
  _memcpy(local_1bc,&DAT_001c6580,300);
  cVar1 = *(char *)(param_3 + 0x15c);
  iVar2 = 0;
  puVar6 = local_90;
  iVar3 = param_3;
  puVar4 = puVar6;
  do {
    *puVar4 = *(undefined4 *)(iVar3 + 0x1c);
    puVar4[1] = *(undefined4 *)(iVar3 + 0x20);
    local_20[iVar2] = (byte)((int)cVar1 >> ((byte)iVar2 & 0x1f)) & 1;
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 0x18;
    puVar4 = puVar4 + 6;
  } while (iVar2 != 4);
  local_30[0] = *(undefined4 *)(param_1 + 8);
  local_30[1] = *(undefined4 *)(param_1 + 0xc);
  local_30[2] = *(undefined4 *)(param_1 + 0x10);
  local_30[3] = *(undefined4 *)(param_1 + 0x14);
  local_1c0 = *(int *)(&DAT_001c656c + (4 - param_2) * 4);
  if (local_1c0 < 0xf) {
    local_1d0 = local_1bc + local_1c0 * 5;
    do {
      local_1e0 = param_3;
      iVar3 = 0;
      piVar5 = local_1d0;
      do {
        iVar2 = piVar5[1];
        if (iVar2 < 0) {
          *(undefined4 *)(local_1e0 + 0x1c) = 0;
          *(undefined4 *)(local_1e0 + 0x20) = 0;
          *(byte *)(param_3 + 0x15c) =
               *(byte *)(param_3 + 0x15c) & ~(byte)(1 << ((byte)iVar3 & 0x1f));
        }
        else {
          *(undefined4 *)(local_1e0 + 0x1c) = local_90[iVar2 * 6];
          *(undefined4 *)(local_1e0 + 0x20) = local_90[iVar2 * 6 + 1];
          *(byte *)(param_3 + 0x15c) =
               *(byte *)(param_3 + 0x15c) | (byte)(1 << ((byte)iVar3 & 0x1f));
        }
        iVar3 = iVar3 + 1;
        piVar5 = piVar5 + 1;
        local_1e0 = local_1e0 + 0x18;
      } while (iVar3 != 4);
      FUN_001a89d8(local_30[*local_1d0],param_3);
      local_1c0 = local_1c0 + 1;
      local_1d0 = local_1d0 + 5;
    } while (local_1c0 != 0xf);
  }
  iVar2 = 0;
  iVar3 = param_3;
  do {
    *(undefined4 *)(iVar3 + 0x1c) = *puVar6;
    *(undefined4 *)(iVar3 + 0x20) = puVar6[1];
    if (local_20[iVar2] == 0) {
      *(byte *)(param_3 + 0x15c) = *(byte *)(param_3 + 0x15c) & ~(byte)(1 << ((byte)iVar2 & 0x1f));
    }
    else {
      *(byte *)(param_3 + 0x15c) = *(byte *)(param_3 + 0x15c) | (byte)(1 << ((byte)iVar2 & 0x1f));
    }
    iVar2 = iVar2 + 1;
    puVar6 = puVar6 + 6;
    iVar3 = iVar3 + 0x18;
  } while (iVar2 != 4);
  return;
}

/* FUN_000f7314 @ 0xf7314 (470 bytes) */
int FUN_000f7314(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined4 in_stack_00000024;
  undefined4 in_stack_00000028;
  undefined4 in_stack_0000003c;
  undefined4 in_stack_00000040;
  undefined4 in_stack_00000054;
  undefined4 in_stack_00000058;
  undefined4 local_7c [6];
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_34;
  undefined4 local_30;
  int aiStack_20 [4];
  int local_10;
  
  aiStack_20[1] = param_1[2];
  aiStack_20[2] = param_1[3];
  aiStack_20[3] = param_1[4];
  local_10 = param_1[5];
  local_7c[0] = param_3;
  local_7c[1] = param_4;
  local_64 = in_stack_00000024;
  local_60 = in_stack_00000028;
  local_4c = in_stack_0000003c;
  local_48 = in_stack_00000040;
  local_34 = in_stack_00000054;
  local_30 = in_stack_00000058;
  iVar6 = 0;
  iVar7 = 0;
  do {
    if (iVar6 < param_2) {
      *(byte *)(param_1[10] + 0x15c) =
           *(byte *)(param_1[10] + 0x15c) | (byte)(1 << ((byte)iVar6 & 0x1f));
      iVar1 = iVar7 + 0x10 + param_1[10];
      *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)((int)local_7c + iVar7);
      *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)((int)local_7c + iVar7 + 4);
    }
    else {
      *(byte *)(param_1[10] + 0x15c) =
           *(byte *)(param_1[10] + 0x15c) & ~(byte)(1 << ((byte)iVar6 & 0x1f));
    }
    iVar6 = iVar6 + 1;
    iVar7 = iVar7 + 0x18;
  } while (iVar6 != 4);
  puVar3 = (undefined4 *)FUN_001a84b2(aiStack_20[param_2],param_1[10]);
  if (puVar3 != (undefined4 *)0x0) {
    return puVar3;
  }
  uVar5 = *(undefined4 *)(*param_1 + 0xb8);
  puVar4 = (undefined4 *)FUN_001a7bca(uVar5,0x168);
  *puVar4 = uVar5;
  puVar3 = puVar4 + 1;
  FUN_0010ee6a(puVar3,*param_1);
  if ((*(byte *)(*(int *)(*param_1 + 0x3f4) + 0x32) & 1) == 0) {
    uVar5 = FUN_000f6e1e(param_1);
    puVar4[0x26] = uVar5;
    puVar4[0x27] = 0xc;
  }
  else {
    uVar5 = FUN_000f6e40(param_1,local_7c[0],0);
    puVar4[0x26] = uVar5;
    puVar4[0x27] = 0xc;
  }
  iVar6 = 0;
  iVar7 = 0;
  do {
    if (iVar6 < param_2) {
      *(byte *)(puVar4 + 0x58) = *(byte *)(puVar4 + 0x58) | (byte)(1 << ((byte)iVar6 & 0x1f));
      *(undefined4 *)(iVar7 + 0x1c + (int)puVar3) = *(undefined4 *)((int)local_7c + iVar7);
      *(undefined4 *)(iVar7 + 0x20 + (int)puVar3) = *(undefined4 *)((int)local_7c + iVar7 + 4);
    }
    else {
      *(byte *)(puVar4 + 0x58) = *(byte *)(puVar4 + 0x58) & ~(byte)(1 << ((byte)iVar6 & 0x1f));
    }
    iVar6 = iVar6 + 1;
    iVar7 = iVar7 + 0x18;
  } while (iVar6 != 4);
  piVar2 = *(int **)(*(int *)(*param_1 + 0x3f4) + 0x394);
  (**(code **)(*piVar2 + 0xc))(piVar2,puVar3);
  ((int (*)())FUN_000f7114)(param_1,param_2,puVar3);
  return puVar3;
}

/* FUN_000f7508 @ 0xf7508 (340 bytes) */
int FUN_000f7508(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13, param_14, param_15, param_16, param_17, param_18, param_19, param_20, param_21, param_22, param_23, param_24, param_25)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
  undefined4 param_10;
  undefined4 param_11;
  undefined4 param_12;
  undefined4 param_13;
  undefined4 param_14;
  undefined4 param_15;
  undefined4 param_16;
  undefined4 param_17;
  undefined4 param_18;
  undefined4 param_19;
  undefined4 param_20;
  undefined4 param_21;
  undefined4 param_22;
  undefined4 param_23;
  undefined4 param_24;
  undefined4 param_25;
{
  ((int (*)())FUN_000f7314)(param_1,4,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,
               param_11,param_12,param_13,param_14,param_15,param_16,param_17,param_18,param_19,
               param_20,param_21,param_22,param_23,param_24,param_25);
  return;
}

/* FUN_000f765c @ 0xf765c (346 bytes) */
int FUN_000f765c(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13, param_14, param_15, param_16, param_17, param_18, param_19)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
  undefined4 param_10;
  undefined4 param_11;
  undefined4 param_12;
  undefined4 param_13;
  undefined4 param_14;
  undefined4 param_15;
  undefined4 param_16;
  undefined4 param_17;
  undefined4 param_18;
  undefined4 param_19;
{
  ((int (*)())FUN_000f7314)(param_1,3,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,
               param_11,param_12,param_13,param_14,param_15,param_16,param_17,param_18,param_19,
               *(undefined4 *)PTR_DAT_00213469,*(undefined4 *)(PTR_DAT_00213469 + 4),
               *(undefined4 *)(PTR_DAT_00213469 + 8),*(undefined4 *)(PTR_DAT_00213469 + 0xc),
               *(undefined4 *)(PTR_DAT_00213469 + 0x10),*(undefined4 *)(PTR_DAT_00213469 + 0x14));
  return;
}

/* FUN_000f77b6 @ 0xf77b6 (326 bytes) */
int FUN_000f77b6(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
  undefined4 param_10;
  undefined4 param_11;
  undefined4 param_12;
  undefined4 param_13;
{
  ((int (*)())FUN_000f7314)(param_1,2,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,
               param_11,param_12,param_13,*(undefined4 *)PTR_DAT_00213469,
               *(undefined4 *)(PTR_DAT_00213469 + 4),*(undefined4 *)(PTR_DAT_00213469 + 8),
               *(undefined4 *)(PTR_DAT_00213469 + 0xc),*(undefined4 *)(PTR_DAT_00213469 + 0x10),
               *(undefined4 *)(PTR_DAT_00213469 + 0x14),*(undefined4 *)PTR_DAT_00213469,
               *(undefined4 *)(PTR_DAT_00213469 + 4),*(undefined4 *)(PTR_DAT_00213469 + 8),
               *(undefined4 *)(PTR_DAT_00213469 + 0xc),*(undefined4 *)(PTR_DAT_00213469 + 0x10),
               *(undefined4 *)(PTR_DAT_00213469 + 0x14));
  return;
}

/* FUN_000f78fc @ 0xf78fc (306 bytes) */
int FUN_000f78fc(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  uVar1 = *(undefined4 *)PTR_DAT_00213469;
  uVar2 = *(undefined4 *)(PTR_DAT_00213469 + 4);
  uVar3 = *(undefined4 *)(PTR_DAT_00213469 + 8);
  uVar4 = *(undefined4 *)(PTR_DAT_00213469 + 0xc);
  uVar5 = *(undefined4 *)(PTR_DAT_00213469 + 0x10);
  uVar6 = *(undefined4 *)(PTR_DAT_00213469 + 0x14);
  ((int (*)())FUN_000f7314)(param_1,1,param_2,param_3,param_4,param_5,param_6,param_7,uVar1,uVar2,uVar3,uVar4,
               uVar5,uVar6,uVar1,uVar2,uVar3,uVar4,uVar5,uVar6,uVar1,uVar2,uVar3,uVar4,uVar5,uVar6);
  return;
}

/* FUN_000f7a2e @ 0xf7a2e (474 bytes) */
int FUN_000f7a2e(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  byte *param_3;
{
  float *pfVar1;
  float fVar2;
  byte bVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  char cVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  byte *pbVar12;
  byte *local_50;
  uint local_38;
  int local_30;
  byte bStack_21;
  undefined4 local_20;
  
  if (param_1[7] != 0) {
    local_38 = 0;
    do {
      puVar4 = (uint *)param_1[8];
      if (local_38 < *puVar4) {
        uVar5 = puVar4[1];
        if (uVar5 <= local_38) {
          _memset((void *)(puVar4[2] + uVar5 * 4),0,(local_38 - uVar5) * 4 + 4);
          puVar4[1] = local_38 + 1;
        }
        piVar8 = (int *)(puVar4[2] + local_38 * 4);
      }
      else {
        piVar8 = (int *)FUN_001a7f7c(puVar4,local_38);
      }
      iVar6 = *piVar8;
      local_50 = param_3;
      local_30 = 1;
      do {
        if (*local_50 != 4) {
          iVar9 = 0;
          iVar11 = iVar6;
          while ((((((int)*(char *)(iVar6 + 0x15c) >> ((byte)iVar9 & 0x1f) & 1U) == 0 ||
                   (*(int *)(iVar11 + 0x1c) != 2)) ||
                  (pfVar1 = (float *)(param_2 + -4 + local_30 * 4),
                  *(float *)(iVar11 + 0x20) != *pfVar1)) ||
                 (NAN(*(float *)(iVar11 + 0x20)) || NAN(*pfVar1)))) {
            iVar9 = iVar9 + 1;
            iVar11 = iVar11 + 0x18;
            if (iVar9 == 4) goto LAB_000f7ab4;
          }
        }
        local_30 = local_30 + 1;
        local_50 = local_50 + 1;
      } while (local_30 != 5);
      local_20 = *(undefined4 *)param_3;
      iVar11 = 1;
      pbVar12 = param_3;
      do {
        bVar3 = (&bStack_21)[iVar11];
        if (bVar3 != 4) {
          if ((((int)*(char *)(iVar6 + 0x15c) >> (bVar3 & 0x1f) & 1U) != 0) &&
             (fVar2 = *(float *)(param_2 + -4 + iVar11 * 4),
             fVar2 != *(float *)(iVar6 + 0x20 + (uint)bVar3 * 0x18))) {
            iVar10 = 0;
            iVar9 = iVar6;
            do {
              if ((((int)*(char *)(iVar6 + 0x15c) >> ((byte)iVar10 & 0x1f) & 1U) != 0) &&
                 (*(int *)(iVar9 + 0x1c) == 2)) {
                if ((fVar2 == *(float *)(iVar9 + 0x20)) &&
                   (!NAN(fVar2) && !NAN(*(float *)(iVar9 + 0x20)))) {
                  *pbVar12 = (byte)iVar10;
                  break;
                }
              }
              iVar10 = iVar10 + 1;
              iVar9 = iVar9 + 0x18;
            } while (iVar10 != 4);
          }
        }
        iVar11 = iVar11 + 1;
        pbVar12 = pbVar12 + 1;
      } while (iVar11 != 5);
      cVar7 = (**(code **)(**(int **)(*param_1 + 0x54) + 0x100))(*(int **)(*param_1 + 0x54),param_3)
      ;
      if (cVar7 != '\0') {
        *(undefined4 *)(iVar6 + 0x9c) = DAT_001c6560;
        return iVar6;
      }
LAB_000f7ab4:
      local_38 = local_38 + 1;
    } while (local_38 < (uint)param_1[7]);
  }
  return 0;
}

/* FUN_000f7c08 @ 0xf7c08 (465 bytes) */
int FUN_000f7c08(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  byte bVar1;
  int *piVar2;
  char cVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  
  cVar3 = FUN_001195a6(*(undefined4 *)(param_4 + 8),param_3);
  if (cVar3 == '\0') {
    return 0;
  }
  bVar4 = *(byte *)(param_1 + 0xa0 + param_2 * 0x18) & 1;
  FUN_0010b0f4(param_3,0);
  iVar5 = FUN_0010b180(param_1,param_2);
  iVar5 = *(int *)(iVar5 + 0x98);
  if (iVar5 != 0xc) {
    if (iVar5 == 0x33) {
      if (bVar4 != 0) {
        return 0;
      }
      iVar5 = FUN_0010b180(param_1,param_2);
      piVar2 = *(int **)(*(int *)(param_4 + 8) + 0x54);
      iVar8 = 0;
      do {
        iVar6 = FUN_0010b0f4(param_3,0);
        if (*(char *)(iVar8 + 0x10 + iVar6) != '\x01') {
          iVar6 = FUN_0010b0f4(param_1,param_2);
          bVar4 = *(byte *)(iVar8 + 0x10 + iVar6);
          if ((bVar4 != 4) &&
             (cVar3 = (**(code **)(*piVar2 + 0xf0))
                                (piVar2,*(undefined4 *)(iVar5 + 0x20 + (uint)bVar4 * 0x18)),
             cVar3 == '\0')) {
            return 0;
          }
        }
        iVar8 = iVar8 + 1;
        if (iVar8 == 4) {
          return 1;
        }
      } while( true );
    }
    if (iVar5 != 2) {
      return 0;
    }
  }
  iVar5 = FUN_0010b180(param_1,param_2);
  piVar2 = *(int **)(*(int *)(param_4 + 8) + 0x54);
  iVar8 = 0;
  do {
    iVar6 = FUN_0010b0f4(param_3,0);
    if (*(char *)(iVar8 + 0x10 + iVar6) != '\x01') {
      iVar6 = FUN_0010b0f4(param_1,param_2);
      bVar1 = *(byte *)(iVar8 + 0x10 + iVar6);
      if (bVar1 != 4) {
        if (((int)*(char *)(iVar5 + 0x15c) >> (bVar1 & 0x1f) & 1U) == 0) {
          return 0;
        }
        if (bVar4 == 0) {
          uVar7 = *(uint *)(iVar5 + 0x20 + (uint)bVar1 * 0x18);
        }
        else {
          uVar7 = *(uint *)(iVar5 + 0x20 + (uint)bVar1 * 0x18) ^ 0x80000000;
        }
        cVar3 = (**(code **)(*piVar2 + 0xf0))(piVar2,uVar7);
        if (cVar3 == '\0') {
          return 0;
        }
      }
    }
    iVar8 = iVar8 + 1;
    if (iVar8 == 4) {
      return 1;
    }
  } while( true );
}

/* FUN_000f7dda @ 0xf7dda (164 bytes) */
int FUN_000f7dda(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  int *param_4;
{
  byte bVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  char *pcVar5;
  byte abStack_11 [5];
  
  piVar3 = (int *)FUN_0010b180(param_1,param_2);
  cVar2 = (**(code **)(*piVar3 + 0x48))(piVar3);
  if (cVar2 == '\0') {
    return 0;
  }
  FUN_0010b0f4(param_1,param_2);
  iVar4 = 1;
  pcVar5 = (char *)&param_3;
  do {
    if (*pcVar5 == '\0') {
      bVar1 = abStack_11[iVar4];
      if (bVar1 < 4) {
        if (((int)(char)piVar3[0x57] >> (bVar1 & 0x1f) & 1U) == 0) {
          return 0;
        }
        if (piVar3[(uint)bVar1 * 6 + 8] != *param_4) {
          return 0;
        }
      }
    }
    iVar4 = iVar4 + 1;
    pcVar5 = pcVar5 + 1;
    param_4 = param_4 + 1;
    if (iVar4 == 5) {
      return 1;
    }
  } while( true );
}

/* FUN_000f7e7e @ 0xf7e7e (370 bytes) */
int FUN_000f7e7e(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  undefined4 param_3;
  int *param_4;
{
  float fVar1;
  int iVar2;
  bool bVar3;
  char cVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  char *local_40;
  byte abStack_21 [17];
  
  piVar5 = (int *)FUN_0010b180(param_1,param_2);
  cVar4 = (**(code **)(*piVar5 + 0x48))(piVar5);
  if (cVar4 != '\0') {
    FUN_0010b0f4(param_1,param_2);
    bVar3 = false;
    iVar7 = 1;
    local_40 = (char *)&param_3;
    do {
      if (*local_40 == '\0') {
        uVar6 = (uint)abStack_21[iVar7];
        if (uVar6 < 4) {
          iVar2 = piVar5[uVar6 * 6 + 8];
          if (piVar5[uVar6 * 6 + 7] != 2) {
            return 0;
          }
          if (((int)(char)piVar5[0x57] >> (abStack_21[iVar7] & 0x1f) & 1U) == 0) {
            return 0;
          }
          if (bVar3) {
            if (*param_4 != 2) {
              return 0;
            }
            if (iVar2 != param_4[1]) {
              return 0;
            }
            bVar3 = true;
          }
          else {
            *param_4 = 2;
            param_4[1] = iVar2;
            bVar3 = true;
          }
        }
      }
      iVar7 = iVar7 + 1;
      local_40 = local_40 + 1;
    } while (iVar7 != 5);
    if (bVar3) {
      if ((*(byte *)(param_1 + 0xa0 + param_2 * 0x18) & 2) != 0) {
        fVar1 = (float)param_4[1];
        if ((fVar1 < FLOAT_001c5b9c) && (!NAN(fVar1) && !NAN(FLOAT_001c5b9c))) {
          param_4[1] = (uint)fVar1 ^ _DAT_001c66b0;
        }
      }
      if ((*(byte *)(param_1 + 0xa0 + param_2 * 0x18) & 1) != 0) {
        param_4[1] = param_4[1] ^ 0x80000000;
      }
      return 1;
    }
  }
  return 0;
}

/* FUN_000f7ff0 @ 0xf7ff0 (189 bytes) */
int FUN_000f7ff0(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  char cVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  byte abStack_21 [17];
  
  piVar2 = (int *)FUN_0010b180(param_1,param_2);
  cVar1 = (**(code **)(*piVar2 + 0x48))(piVar2);
  if (cVar1 == '\0') {
    return 0;
  }
  FUN_0010b0f4(param_1,param_2);
  iVar4 = 1;
  do {
    uVar3 = (uint)abStack_21[iVar4];
    if (uVar3 < 4) {
      if (piVar2[uVar3 * 6 + 7] != 2) {
        return 0;
      }
      if (((int)(char)piVar2[0x57] >> (abStack_21[iVar4] & 0x1f) & 1U) == 0) {
        return 0;
      }
      if ((float)piVar2[uVar3 * 6 + 8] < 0.0) {
        return 0;
      }
    }
    iVar4 = iVar4 + 1;
    if (iVar4 == 5) {
      return 1;
    }
  } while( true );
}

/* FUN_000f80ae @ 0xf80ae (263 bytes) */
int FUN_000f80ae(param_1, param_2, param_3)
  int param_1;
  int param_2;
  byte *param_3;
{
  int iVar1;
  float *pfVar2;
  float fVar3;
  byte bVar4;
  uint *puVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  byte *pbVar9;
  int iVar10;
  uint local_20;
  
  if (*(int *)(param_1 + 0x1c) != 0) {
    local_20 = 0;
    do {
      puVar5 = *(uint **)(param_1 + 0x20);
      if (local_20 < *puVar5) {
        uVar6 = puVar5[1];
        if (uVar6 <= local_20) {
          _memset((void *)(puVar5[2] + uVar6 * 4),0,(local_20 - uVar6) * 4 + 4);
          puVar5[1] = local_20 + 1;
        }
        piVar8 = (int *)(puVar5[2] + local_20 * 4);
      }
      else {
        piVar8 = (int *)FUN_001a7f7c(puVar5,local_20);
      }
      iVar7 = *piVar8;
      iVar10 = 0;
      pbVar9 = param_3;
      while ((bVar4 = *pbVar9, bVar4 == 4 ||
             ((((((int)*(char *)(iVar7 + 0x15c) >> (bVar4 & 0x1f) & 1U) != 0 &&
                (iVar1 = iVar7 + (uint)bVar4 * 0x18, *(int *)(iVar1 + 0x1c) == 2)) &&
               (fVar3 = *(float *)(iVar1 + 0x20), pfVar2 = (float *)(param_2 + iVar10 * 4),
               fVar3 == *pfVar2)) && (!NAN(fVar3) && !NAN(*pfVar2)))))) {
        iVar10 = iVar10 + 1;
        pbVar9 = pbVar9 + 1;
        if (iVar10 == 4) {
          *(undefined4 *)(iVar7 + 0x9c) = DAT_001c6560;
          return iVar7;
        }
      }
      local_20 = local_20 + 1;
    } while (local_20 < *(uint *)(param_1 + 0x1c));
  }
  return 0;
}

/* FUN_000f81b6 @ 0xf81b6 (485 bytes) */
int FUN_000f81b6(param_1, param_2)
  int param_1;
  int param_2;
{
  uint *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  undefined1 *puVar7;
  char *pcVar8;
  uint local_b0;
  undefined1 local_94 [132];
  
  puVar1 = *(uint **)(param_1 + 0x3bc);
  if (puVar1[1] == 0) {
    return;
  }
  local_b0 = 0;
  if (*puVar1 == 0) goto LAB_000f823d;
LAB_000f81e9:
  uVar6 = puVar1[1];
  if (uVar6 <= local_b0) {
    _memset((void *)(puVar1[2] + uVar6 * 4),0,(local_b0 - uVar6) * 4 + 4);
    puVar1[1] = local_b0 + 1;
  }
  piVar3 = (int *)(puVar1[2] + local_b0 * 4);
  uVar6 = local_b0;
  do {
    local_b0 = uVar6 + 1;
    iVar2 = *piVar3;
    if ((((*(byte *)(iVar2 + 0x14) & 1) != 0) && ((*(byte *)(iVar2 + 0x15c) & 1) != 0)) &&
       (*(int *)(iVar2 + 0x98) == 0xc)) {
      uVar4 = (**(code **)(**(int **)(param_2 + 0x54) + 0x158))
                        (*(int **)(param_2 + 0x54),*(undefined4 *)(iVar2 + 0x94),
                         *(undefined4 *)(iVar2 + 0x1c),0,param_2);
      iVar5 = FUN_0010b0f4(iVar2,0);
      *(undefined4 *)(iVar5 + 8) = uVar4;
      uVar4 = *(undefined4 *)(iVar2 + 0x94);
      pcVar8 = "k";
      puVar7 = *(undefined1 **)(iVar2 + 0x14c);
      FUN_000e1c3e(param_2,"(%d)  %d, regnum = %s[%d]: ",puVar7,uVar6,"k",uVar4);
      iVar5 = 0;
      do {
        if (((int)*(char *)(iVar2 + 0x15c) >> ((byte)iVar5 & 0x1f) & 1U) == 0) break;
        puVar7 = local_94;
        FUN_000e1c3e(param_2,"  %s ",local_94,uVar6,pcVar8,uVar4);
        iVar5 = iVar5 + 1;
      } while (iVar5 != 4);
      FUN_000e1c3e(param_2,"\n",puVar7,uVar6,pcVar8,uVar4);
    }
    if (puVar1[1] <= local_b0) {
      return;
    }
    if (local_b0 < *puVar1) goto LAB_000f81e9;
LAB_000f823d:
    piVar3 = (int *)FUN_001a7f7c(puVar1,local_b0);
    uVar6 = local_b0;
  } while( true );
}

/* FUN_000f839c @ 0xf839c (484 bytes) */
int FUN_000f839c(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  byte *pbVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined4 in_stack_00000024;
  undefined4 in_stack_00000028;
  undefined4 in_stack_0000003c;
  undefined4 in_stack_00000040;
  undefined4 in_stack_00000054;
  undefined4 in_stack_00000058;
  int local_b0;
  int local_80;
  undefined4 local_7c [6];
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 auStack_20 [4];
  undefined4 local_10;
  
  auStack_20[1] = *(undefined4 *)(param_1 + 8);
  auStack_20[2] = *(undefined4 *)(param_1 + 0xc);
  auStack_20[3] = *(undefined4 *)(param_1 + 0x10);
  local_10 = *(undefined4 *)(param_1 + 0x14);
  local_7c[0] = param_3;
  local_7c[1] = param_4;
  local_64 = in_stack_00000024;
  local_60 = in_stack_00000028;
  local_4c = in_stack_0000003c;
  local_48 = in_stack_00000040;
  local_34 = in_stack_00000054;
  local_30 = in_stack_00000058;
  iVar5 = 0;
  iVar6 = 0;
  do {
    if (iVar5 < param_2) {
      pbVar1 = (byte *)(*(int *)(param_1 + 0x28) + 0x15c);
      *pbVar1 = *pbVar1 | (byte)(1 << ((byte)iVar5 & 0x1f));
      iVar2 = iVar6 + 0x10 + *(int *)(param_1 + 0x28);
      *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)((int)local_7c + iVar6);
      *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)((int)local_7c + iVar6 + 4);
    }
    else {
      pbVar1 = (byte *)(*(int *)(param_1 + 0x28) + 0x15c);
      *pbVar1 = *pbVar1 & ~(byte)(1 << ((byte)iVar5 & 0x1f));
    }
    iVar5 = iVar5 + 1;
    iVar6 = iVar6 + 0x18;
  } while (iVar5 != 4);
  iVar5 = FUN_001a84b2(auStack_20[param_2],*(undefined4 *)(param_1 + 0x28));
  if (iVar5 == 0) {
    uVar3 = FUN_000f6e1e(param_1);
    iVar5 = FUN_0012eb2a(param_1,0xc,uVar3,0);
    piVar4 = *(int **)(iVar5 + 0x18);
    if (*piVar4 == 0) {
      piVar4 = (int *)FUN_001a7f7c(piVar4,0);
    }
    else {
      if (piVar4[1] == 0) {
        *(undefined4 *)piVar4[2] = 0;
        piVar4[1] = 1;
      }
      piVar4 = (int *)piVar4[2];
    }
    iVar6 = *piVar4;
    local_b0 = 0;
    local_80 = 0;
    do {
      if (local_b0 < param_2) {
        *(byte *)(iVar6 + 0x15c) = *(byte *)(iVar6 + 0x15c) | (byte)(1 << ((byte)local_b0 & 0x1f));
        *(undefined4 *)(local_80 + 0x1c + iVar6) = *(undefined4 *)((int)local_7c + local_80);
        *(undefined4 *)(local_80 + 0x20 + iVar6) = *(undefined4 *)((int)local_7c + local_80 + 4);
      }
      else {
        *(byte *)(iVar6 + 0x15c) = *(byte *)(iVar6 + 0x15c) & ~(byte)(1 << ((byte)local_b0 & 0x1f));
      }
      local_b0 = local_b0 + 1;
      local_80 = local_80 + 0x18;
    } while (local_b0 != 4);
    ((int (*)())FUN_000f7114)(param_1,param_2,iVar6);
  }
  else {
    iVar5 = *(int *)(iVar5 + 0x8c);
  }
  return iVar5;
}

/* FUN_000f8580 @ 0xf8580 (340 bytes) */
int FUN_000f8580(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13, param_14, param_15, param_16, param_17, param_18, param_19, param_20, param_21, param_22, param_23, param_24, param_25)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
  undefined4 param_10;
  undefined4 param_11;
  undefined4 param_12;
  undefined4 param_13;
  undefined4 param_14;
  undefined4 param_15;
  undefined4 param_16;
  undefined4 param_17;
  undefined4 param_18;
  undefined4 param_19;
  undefined4 param_20;
  undefined4 param_21;
  undefined4 param_22;
  undefined4 param_23;
  undefined4 param_24;
  undefined4 param_25;
{
  ((int (*)())FUN_000f839c)(param_1,4,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,
               param_11,param_12,param_13,param_14,param_15,param_16,param_17,param_18,param_19,
               param_20,param_21,param_22,param_23,param_24,param_25);
  return;
}

/* FUN_000f86d4 @ 0xf86d4 (346 bytes) */
int FUN_000f86d4(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13, param_14, param_15, param_16, param_17, param_18, param_19)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
  undefined4 param_10;
  undefined4 param_11;
  undefined4 param_12;
  undefined4 param_13;
  undefined4 param_14;
  undefined4 param_15;
  undefined4 param_16;
  undefined4 param_17;
  undefined4 param_18;
  undefined4 param_19;
{
  ((int (*)())FUN_000f839c)(param_1,3,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,
               param_11,param_12,param_13,param_14,param_15,param_16,param_17,param_18,param_19,
               *(undefined4 *)PTR_DAT_00213469,*(undefined4 *)(PTR_DAT_00213469 + 4),
               *(undefined4 *)(PTR_DAT_00213469 + 8),*(undefined4 *)(PTR_DAT_00213469 + 0xc),
               *(undefined4 *)(PTR_DAT_00213469 + 0x10),*(undefined4 *)(PTR_DAT_00213469 + 0x14));
  return;
}

/* FUN_000f882e @ 0xf882e (326 bytes) */
int FUN_000f882e(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
  undefined4 param_10;
  undefined4 param_11;
  undefined4 param_12;
  undefined4 param_13;
{
  ((int (*)())FUN_000f839c)(param_1,2,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,
               param_11,param_12,param_13,*(undefined4 *)PTR_DAT_00213469,
               *(undefined4 *)(PTR_DAT_00213469 + 4),*(undefined4 *)(PTR_DAT_00213469 + 8),
               *(undefined4 *)(PTR_DAT_00213469 + 0xc),*(undefined4 *)(PTR_DAT_00213469 + 0x10),
               *(undefined4 *)(PTR_DAT_00213469 + 0x14),*(undefined4 *)PTR_DAT_00213469,
               *(undefined4 *)(PTR_DAT_00213469 + 4),*(undefined4 *)(PTR_DAT_00213469 + 8),
               *(undefined4 *)(PTR_DAT_00213469 + 0xc),*(undefined4 *)(PTR_DAT_00213469 + 0x10),
               *(undefined4 *)(PTR_DAT_00213469 + 0x14));
  return;
}

/* FUN_000f8974 @ 0xf8974 (306 bytes) */
int FUN_000f8974(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  uVar1 = *(undefined4 *)PTR_DAT_00213469;
  uVar2 = *(undefined4 *)(PTR_DAT_00213469 + 4);
  uVar3 = *(undefined4 *)(PTR_DAT_00213469 + 8);
  uVar4 = *(undefined4 *)(PTR_DAT_00213469 + 0xc);
  uVar5 = *(undefined4 *)(PTR_DAT_00213469 + 0x10);
  uVar6 = *(undefined4 *)(PTR_DAT_00213469 + 0x14);
  ((int (*)())FUN_000f839c)(param_1,1,param_2,param_3,param_4,param_5,param_6,param_7,uVar1,uVar2,uVar3,uVar4,
               uVar5,uVar6,uVar1,uVar2,uVar3,uVar4,uVar5,uVar6,uVar1,uVar2,uVar3,uVar4,uVar5,uVar6);
  return;
}

/* FUN_000f8aa6 @ 0xf8aa6 (811 bytes) */
int FUN_000f8aa6(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  uint uVar1;
  uint *puVar2;
  char cVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  char *local_a0;
  int local_88;
  uint *local_84;
  int local_70 [24];
  int local_10;
  
  iVar9 = *(int *)(param_1 + 8);
  cVar3 = (**(code **)(**(int **)(iVar9 + 0x54) + 0xe8))
                    (*(int **)(iVar9 + 0x54),param_2,&local_10,param_3,iVar9);
  if (cVar3 == '\0') {
    return (undefined4 *)0x0;
  }
  FUN_000f6de0(param_2,local_70);
  iVar8 = *(int *)(param_1 + 0x3a0);
  uVar10 = *(uint *)(*(int *)(iVar8 + 0x18) + 4);
  if (0 < (int)uVar10) {
    uVar11 = 0;
    do {
      puVar2 = *(uint **)(iVar8 + 0x18);
      if (uVar11 < *puVar2) {
        uVar1 = puVar2[1];
        if (uVar1 <= uVar11) {
          _memset((void *)(puVar2[2] + uVar1 * 4),0,(uVar11 - uVar1) * 4 + 4);
          puVar2[1] = uVar11 + 1;
        }
        puVar7 = *(undefined4 **)(puVar2[2] + uVar11 * 4);
        if (puVar7[0x4b] == local_10) goto LAB_000f8b8a;
      }
      else {
        piVar4 = (int *)FUN_001a7f7c(puVar2,uVar11);
        puVar7 = (undefined4 *)*piVar4;
        if (puVar7[0x4b] == local_10) {
LAB_000f8b8a:
          local_88 = 0;
          local_a0 = (char *)&param_3;
          iVar8 = 0;
          while ((*local_a0 == '\x04' ||
                 ((*(int *)(iVar8 + 0x1c + (int)puVar7) == *(int *)((int)local_70 + iVar8) &&
                  (*(int *)(iVar8 + 0x20 + (int)puVar7) == *(int *)((int)local_70 + iVar8 + 4))))))
          {
            local_88 = local_88 + 1;
            iVar8 = iVar8 + 0x18;
            local_a0 = local_a0 + 1;
            if (local_88 == 4) {
              if (puVar7 != (undefined4 *)0x0) {
                return puVar7;
              }
              goto LAB_000f8be8;
            }
          }
        }
      }
      uVar11 = uVar11 + 1;
      if (uVar10 == uVar11) break;
      iVar8 = *(int *)(param_1 + 0x3a0);
    } while( true );
  }
LAB_000f8be8:
  if ((*(byte *)(param_1 + 0x30) & 8) == 0) {
    uVar6 = FUN_000f6e1e(*(undefined4 *)(param_1 + 0x3a0));
    iVar9 = FUN_0012eb2a(*(undefined4 *)(param_1 + 0x3a0),0x33,uVar6,0);
    piVar4 = *(int **)(iVar9 + 0x18);
    if (*piVar4 == 0) {
      puVar7 = (undefined4 *)FUN_001a7f7c(piVar4,0);
      puVar7 = (undefined4 *)*puVar7;
    }
    else {
      if (piVar4[1] == 0) {
        *(undefined4 *)piVar4[2] = 0;
        piVar4[1] = 1;
        puVar7 = (undefined4 *)piVar4[2];
      }
      else {
        puVar7 = (undefined4 *)piVar4[2];
      }
      puVar7 = (undefined4 *)*puVar7;
    }
    puVar7[0x4b] = local_10;
    local_84 = *(uint **)(*(int *)(param_1 + 0x3a0) + 0x18);
    uVar10 = local_84[1];
    if (*local_84 <= uVar10) goto LAB_000f8d94;
  }
  else {
    uVar6 = *(undefined4 *)(iVar9 + 0xb8);
    puVar5 = (undefined4 *)FUN_001a7bca(uVar6,0x168);
    *puVar5 = uVar6;
    puVar7 = puVar5 + 1;
    FUN_0010ee6a(puVar7,*(undefined4 *)(param_1 + 8));
    uVar6 = FUN_000f6e1e(*(undefined4 *)(param_1 + 0x3a0));
    puVar5[0x26] = uVar6;
    puVar5[0x27] = 0x33;
    (**(code **)(**(int **)(param_1 + 0x394) + 0xc))(*(int **)(param_1 + 0x394),puVar7);
    puVar5[0x4c] = local_10;
    local_84 = *(uint **)(*(int *)(param_1 + 0x3a0) + 0x18);
    uVar10 = local_84[1];
    if (*local_84 <= uVar10) {
LAB_000f8d94:
      puVar5 = (undefined4 *)FUN_001a7f7c(local_84,uVar10);
      goto LAB_000f8cb7;
    }
  }
  _memset((void *)(local_84[2] + uVar10 * 4),0,4);
  local_84[1] = uVar10 + 1;
  puVar5 = (undefined4 *)(local_84[2] + uVar10 * 4);
LAB_000f8cb7:
  *puVar5 = puVar7;
  iVar9 = 0;
  iVar8 = 0;
  do {
    *(undefined4 *)(iVar8 + 0x1c + (int)puVar7) = *(undefined4 *)((int)local_70 + iVar8);
    *(undefined4 *)(iVar8 + 0x20 + (int)puVar7) = *(undefined4 *)((int)local_70 + iVar8 + 4);
    *(byte *)(puVar7 + 0x57) = *(byte *)(puVar7 + 0x57) | (byte)(1 << ((byte)iVar9 & 0x1f));
    iVar9 = iVar9 + 1;
    iVar8 = iVar8 + 0x18;
  } while (iVar9 != 4);
  return puVar7;
}

/* FUN_000f8df6 @ 0xf8df6 (3871 bytes) */
int FUN_000f8df6(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
  int *param_5;
{
  byte *pbVar1;
  undefined1 uVar2;
  byte bVar3;
  int iVar4;
  uint *puVar5;
  uint *puVar6;
  int *piVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int **ppiVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  bool bVar16;
  int in_stack_00000028;
  undefined4 in_stack_0000002c;
  int in_stack_00000040;
  undefined4 in_stack_00000044;
  int in_stack_00000058;
  undefined4 in_stack_0000005c;
  int local_258;
  int local_250;
  int *local_60 [4];
  int *local_50 [8];
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined1 auStack_24 [4];
  int local_20 [4];
  
  uVar9 = *(undefined4 *)(param_2 + 8);
  if ((((param_4 == 2) && (in_stack_00000028 == 2)) && (in_stack_00000040 == 2)) &&
     (in_stack_00000058 == 2)) {
    ppiVar10 = local_60;
    do {
      *ppiVar10 = (int *)0x7ffffffe;
      ppiVar10 = ppiVar10 + 1;
    } while (ppiVar10 != local_50);
    local_60[0] = param_5;
    local_60[1] = (int *)in_stack_0000002c;
    local_60[2] = (int *)in_stack_00000044;
    local_60[3] = (int *)in_stack_0000005c;
    iVar12 = ((int (*)())FUN_000f8aa6)(param_2,local_60,DAT_001c6568);
    if (iVar12 != 0) {
      if ((*(uint *)(param_2 + 0x30) & 8) == 0) {
        FUN_0010a3c2(param_1,param_3,*(undefined4 *)(iVar12 + 0x8c));
      }
      else {
        FUN_0010ba02(param_1,param_3,iVar12,*(uint *)(param_2 + 0x30) >> 7 & 1,uVar9);
      }
      iVar15 = FUN_0010b0f4(iVar12,0);
      local_20[0] = *(int *)(iVar15 + 0x10);
      if (local_20[0] != DAT_001c6560) {
        iVar15 = 0;
        do {
          iVar11 = FUN_0010b0f4(param_1,param_3);
          if (*(byte *)(iVar15 + 0x10 + iVar11) < 4) {
            iVar11 = FUN_0010b0f4(param_1,param_3);
            bVar3 = *(byte *)(iVar15 + 0x10 + iVar11);
            *(undefined1 *)((int)local_20 + (uint)bVar3) = 0;
            pbVar1 = (byte *)(iVar12 + 0xc + (uint)bVar3);
            *pbVar1 = *pbVar1 | (byte)(1 << (bVar3 & 0x1f));
          }
          iVar15 = iVar15 + 1;
        } while (iVar15 != 4);
        *(int *)(iVar12 + 0x9c) = local_20[0];
      }
      return;
    }
  }
  local_2c = DAT_001c6568;
  local_50[4] = &param_4;
  local_50[5] = &STACKARG(0x28);
  local_50[6] = &STACKARG(0x40);
  local_50[7] = &STACKARG(0x58);
  local_50[0] = (int *)PTR_DAT_00213469;
  local_50[1] = (int *)PTR_DAT_00213469;
  local_50[2] = (int *)PTR_DAT_00213469;
  local_50[3] = (int *)PTR_DAT_00213469;
  iVar12 = 1;
  local_258 = 0;
  iVar15 = local_258;
LAB_000f8e71:
  local_258 = iVar15;
  local_50[local_258] = local_50[iVar12 + 3];
  *(char *)((int)&local_30 + iVar12 + 3) = (char)local_258;
  iVar15 = local_258 + 1;
joined_r0x000f8ea0:
  do {
    do {
      iVar11 = iVar12;
      iVar12 = iVar11 + 1;
      if (iVar12 == 5) {
        local_30 = DAT_001c6568;
        if (0 < iVar15) {
          local_250 = local_258;
          do {
            iVar12 = 0;
            while (iVar11 = iVar12, iVar12 < local_250) {
              while( true ) {
                iVar12 = iVar11 + 1;
                puVar5 = (uint *)local_50[iVar12];
                puVar6 = (uint *)local_50[iVar11];
                uVar14 = *puVar6;
                bVar16 = uVar14 < *puVar5;
                if (uVar14 == *puVar5) {
                  if (uVar14 == 2) {
                    bVar16 = (float)puVar6[1] <= (float)puVar5[1] &&
                             (float)puVar5[1] != (float)puVar6[1];
                  }
                  else {
                    bVar16 = puVar6[1] < puVar5[1];
                  }
                }
                if (!bVar16) break;
                local_50[iVar12] = (int *)puVar6;
                local_50[iVar11] = (int *)puVar5;
                uVar2 = *(undefined1 *)((int)&local_30 + iVar11 + 1);
                *(undefined1 *)((int)&local_30 + iVar11 + 1) =
                     *(undefined1 *)((int)&local_30 + iVar11);
                *(undefined1 *)((int)&local_30 + iVar11) = uVar2;
                iVar11 = iVar12;
                if (local_250 <= iVar12) goto LAB_000f8f89;
              }
            }
LAB_000f8f89:
            bVar16 = 0 < local_250;
            local_250 = local_250 + -1;
          } while (bVar16);
          if (0 < iVar15) {
            iVar12 = 0;
            do {
              auStack_24[*(byte *)((int)&local_30 + iVar12)] = (char)iVar12;
              iVar12 = iVar12 + 1;
            } while (iVar12 != iVar15);
          }
        }
        iVar12 = 1;
        do {
          *(undefined1 *)((int)&local_2c + iVar12 + 3) =
               auStack_24[*(byte *)((int)&local_30 + iVar12 + 3)];
          iVar12 = iVar12 + 1;
        } while (iVar12 != 5);
        uVar14 = *(uint *)(param_2 + 0x30);
        if ((uVar14 & 8) == 0) {
          if (iVar15 == 2) {
            uVar9 = ((int (*)())FUN_000f882e)(*(undefined4 *)(param_2 + 0x3a0),*local_50[0],local_50[0][1],
                                 local_50[0][2],local_50[0][3],local_50[0][4],local_50[0][5],
                                 *local_50[1],local_50[1][1],local_50[1][2],local_50[1][3],
                                 local_50[1][4],local_50[1][5]);
          }
          else if (iVar15 < 3) {
            if (iVar15 == 1) {
              uVar9 = ((int (*)())FUN_000f8974)(*(undefined4 *)(param_2 + 0x3a0),*local_50[0],local_50[0][1],
                                   local_50[0][2],local_50[0][3],local_50[0][4],local_50[0][5]);
            }
            else {
LAB_000f9069:
              uVar9 = 0;
            }
          }
          else if (iVar15 == 3) {
            uVar9 = ((int (*)())FUN_000f86d4)(*(undefined4 *)(param_2 + 0x3a0),*local_50[0],local_50[0][1],
                                 local_50[0][2],local_50[0][3],local_50[0][4],local_50[0][5],
                                 *local_50[1],local_50[1][1],local_50[1][2],local_50[1][3],
                                 local_50[1][4],local_50[1][5],*local_50[2],local_50[2][1],
                                 local_50[2][2],local_50[2][3],local_50[2][4],local_50[2][5]);
          }
          else {
            if (iVar15 != 4) goto LAB_000f9069;
            uVar9 = ((int (*)())FUN_000f8580)(*(undefined4 *)(param_2 + 0x3a0),*local_50[0],local_50[0][1],
                                 local_50[0][2],local_50[0][3],local_50[0][4],local_50[0][5],
                                 *local_50[1],local_50[1][1],local_50[1][2],local_50[1][3],
                                 local_50[1][4],local_50[1][5],*local_50[2],local_50[2][1],
                                 local_50[2][2],local_50[2][3],local_50[2][4],local_50[2][5],
                                 *local_50[3],local_50[3][1],local_50[3][2],local_50[3][3],
                                 local_50[3][4],local_50[3][5]);
          }
          FUN_0010a3c2(param_1,param_3,uVar9);
          goto LAB_000f93d5;
        }
        if (iVar15 == 2) {
          uVar8 = ((int (*)())FUN_000f77b6)(*(undefined4 *)(param_2 + 0x3a0),*local_50[0],local_50[0][1],
                               local_50[0][2],local_50[0][3],local_50[0][4],local_50[0][5],
                               *local_50[1],local_50[1][1],local_50[1][2],local_50[1][3],
                               local_50[1][4],local_50[1][5]);
          uVar14 = *(uint *)(param_2 + 0x30);
        }
        else if (iVar15 < 3) {
          if (iVar15 == 1) {
            uVar8 = ((int (*)())FUN_000f78fc)(*(undefined4 *)(param_2 + 0x3a0),*local_50[0],local_50[0][1],
                                 local_50[0][2],local_50[0][3],local_50[0][4],local_50[0][5]);
            uVar14 = *(uint *)(param_2 + 0x30);
          }
          else {
LAB_000f9012:
            uVar8 = 0;
          }
        }
        else if (iVar15 == 3) {
          uVar8 = ((int (*)())FUN_000f765c)(*(undefined4 *)(param_2 + 0x3a0),*local_50[0],local_50[0][1],
                               local_50[0][2],local_50[0][3],local_50[0][4],local_50[0][5],
                               *local_50[1],local_50[1][1],local_50[1][2],local_50[1][3],
                               local_50[1][4],local_50[1][5],*local_50[2],local_50[2][1],
                               local_50[2][2],local_50[2][3],local_50[2][4],local_50[2][5]);
          uVar14 = *(uint *)(param_2 + 0x30);
        }
        else {
          if (iVar15 != 4) goto LAB_000f9012;
          uVar8 = ((int (*)())FUN_000f7508)(*(undefined4 *)(param_2 + 0x3a0),*local_50[0],local_50[0][1],
                               local_50[0][2],local_50[0][3],local_50[0][4],local_50[0][5],
                               *local_50[1],local_50[1][1],local_50[1][2],local_50[1][3],
                               local_50[1][4],local_50[1][5],*local_50[2],local_50[2][1],
                               local_50[2][2],local_50[2][3],local_50[2][4],local_50[2][5],
                               *local_50[3],local_50[3][1],local_50[3][2],local_50[3][3],
                               local_50[3][4],local_50[3][5]);
          uVar14 = *(uint *)(param_2 + 0x30);
        }
        FUN_0010ba02(param_1,param_3,uVar8,uVar14 >> 7 & 1,uVar9);
LAB_000f93d5:
        iVar12 = FUN_0010b0f4(param_1,param_3);
        *(undefined4 *)(iVar12 + 0x10) = local_28;
        return;
      }
    } while (iVar15 < 0);
    if (iVar15 == 0) goto LAB_000f8e71;
    iVar4 = *local_50[iVar11 + 4];
    iVar13 = 0;
    piVar7 = local_50;
    if (*local_50[0] == iVar4) goto LAB_000f8ed8;
    do {
      do {
        iVar13 = iVar13 + 1;
        if (iVar13 != iVar15 && iVar15 <= iVar13) goto joined_r0x000f8ea0;
        if (iVar13 == iVar15) goto LAB_000f8e71;
        piVar7 = local_50[iVar13];
      } while (*piVar7 != iVar4);
LAB_000f8ed8: ;
    } while (piVar7[1] != local_50[iVar11 + 4][1]);
    *(char *)((int)&local_2c + iVar11) = (char)iVar13;
  } while( true );
}

/* FUN_000f9d16 @ 0xf9d16 (478 bytes) */
int FUN_000f9d16(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())FUN_000f8df6)(param_1,param_2,param_3,1,param_4);
  return;
}

/* FUN_000f9ef4 @ 0xf9ef4 (478 bytes) */
int FUN_000f9ef4(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())FUN_000f8df6)(param_1,param_2,param_3,3,param_4);
  return;
}

/* FUN_000fa0d2 @ 0xfa0d2 (502 bytes) */
int FUN_000fa0d2(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())FUN_000f8df6)(param_1,param_2,param_3,2,param_4);
  return;
}

/* FUN_000fa2c8 @ 0xfa2c8 (161 bytes) */
int FUN_000fa2c8(param_1, param_2, param_3)
  uint *param_1;
  int param_2;
  int param_3;
{
  uint uVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  
  if (param_1[1] != 0) {
    uVar5 = 0;
    do {
      if (uVar5 < *param_1) {
        uVar1 = param_1[1];
        if (uVar1 <= uVar5) {
          _memset((void *)(param_1[2] + uVar1 * 4),0,(uVar5 - uVar1) * 4 + 4);
          param_1[1] = uVar5 + 1;
        }
        piVar2 = *(int **)(param_1[2] + uVar5 * 4);
        iVar3 = *piVar2;
      }
      else {
        puVar4 = (undefined4 *)FUN_001a7f7c(param_1,uVar5);
        piVar2 = (int *)*puVar4;
        iVar3 = *piVar2;
      }
      if ((iVar3 == param_2) && (piVar2[1] == param_3)) {
        return uVar5;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < param_1[1]);
  }
  return param_1[1];
}

/* FUN_000fa36a @ 0xfa36a (242 bytes) */
int FUN_000fa36a(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  param_1[8] = param_2;
  iVar2 = FUN_001a7d8a(param_2 + 0x370);
  param_1[7] = iVar2;
  iVar1 = *(int *)(param_1[8] + 8);
  param_1[9] = iVar1;
  iVar2 = iVar2 * 4 + 4;
  uVar3 = FUN_001a7bca(*(undefined4 *)(iVar1 + 0xbc),iVar2);
  param_1[2] = uVar3;
  uVar3 = FUN_001a7bca(*(undefined4 *)(param_1[9] + 0xbc),iVar2);
  param_1[1] = uVar3;
  uVar3 = FUN_001a7bca(*(undefined4 *)(param_1[9] + 0xbc),iVar2);
  param_1[4] = uVar3;
  uVar3 = FUN_001a7bca(*(undefined4 *)(param_1[9] + 0xbc),iVar2);
  param_1[3] = uVar3;
  uVar3 = FUN_001a7bca(*(undefined4 *)(param_1[9] + 0xbc),iVar2);
  *param_1 = uVar3;
  uVar3 = FUN_001a7bca(*(undefined4 *)(param_1[9] + 0xbc),param_1[7] * 4 + 4);
  param_1[6] = uVar3;
  uVar3 = FUN_001a7bca(*(undefined4 *)(param_1[9] + 0xbc),param_1[7] * 4 + 4);
  param_1[5] = uVar3;
  return;
}

/* FUN_000fa45c @ 0xfa45c (242 bytes) */
int FUN_000fa45c(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  param_1[8] = param_2;
  iVar2 = FUN_001a7d8a(param_2 + 0x370);
  param_1[7] = iVar2;
  iVar1 = *(int *)(param_1[8] + 8);
  param_1[9] = iVar1;
  iVar2 = iVar2 * 4 + 4;
  uVar3 = FUN_001a7bca(*(undefined4 *)(iVar1 + 0xbc),iVar2);
  param_1[2] = uVar3;
  uVar3 = FUN_001a7bca(*(undefined4 *)(param_1[9] + 0xbc),iVar2);
  param_1[1] = uVar3;
  uVar3 = FUN_001a7bca(*(undefined4 *)(param_1[9] + 0xbc),iVar2);
  param_1[4] = uVar3;
  uVar3 = FUN_001a7bca(*(undefined4 *)(param_1[9] + 0xbc),iVar2);
  param_1[3] = uVar3;
  uVar3 = FUN_001a7bca(*(undefined4 *)(param_1[9] + 0xbc),iVar2);
  *param_1 = uVar3;
  uVar3 = FUN_001a7bca(*(undefined4 *)(param_1[9] + 0xbc),param_1[7] * 4 + 4);
  param_1[6] = uVar3;
  uVar3 = FUN_001a7bca(*(undefined4 *)(param_1[9] + 0xbc),param_1[7] * 4 + 4);
  param_1[5] = uVar3;
  return;
}

/* FUN_000fa54e @ 0xfa54e (392 bytes) */
int FUN_000fa54e(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 local_3c;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  local_20 = FUN_000ede1c(*(undefined4 *)(param_1 + 0x20));
  if (*(int *)(param_1 + 0x1c) != 0) {
    local_3c = 1;
    do {
      iVar1 = *(int *)(local_20 + 4);
      iVar2 = *(int *)(iVar1 + 0xe0);
      uVar5 = 1;
      local_24 = 0;
      iVar3 = *(int *)(iVar1 + 0xd0);
      if (*(int *)(iVar3 + 4) != 0) {
        do {
          iVar3 = *(int *)(local_24 + *(int *)(iVar3 + 8));
          if ((iVar3 != 0) &&
             (iVar2 != *(int *)(*(int *)(param_1 + 8) + *(int *)(iVar3 + 0xe0) * 4))) {
            FUN_000eab9c(iVar1,iVar3);
          }
          uVar5 = uVar5 + 1;
          local_24 = local_24 + 4;
          iVar3 = *(int *)(iVar1 + 0xd0);
        } while (uVar5 <= *(uint *)(iVar3 + 4));
      }
      local_2c = 1;
      local_28 = 0;
      iVar3 = *(int *)(iVar1 + 0xf0);
      if (*(int *)(iVar3 + 4) != 0) {
        do {
          iVar3 = *(int *)(local_28 + *(int *)(iVar3 + 8));
          uVar5 = 1;
          local_30 = 0;
          iVar4 = *(int *)(iVar3 + 0xf4);
          if (*(int *)(iVar4 + 4) != 0) {
            do {
              iVar4 = *(int *)(local_30 + *(int *)(iVar4 + 8));
              if (iVar2 != *(int *)(*(int *)(param_1 + 8) + *(int *)(iVar4 + 0xe0) * 4)) {
                FUN_000eab9c(iVar1,iVar4);
              }
              uVar5 = uVar5 + 1;
              local_30 = local_30 + 4;
              iVar4 = *(int *)(iVar3 + 0xf4);
            } while (uVar5 <= *(uint *)(iVar4 + 4));
          }
          local_2c = local_2c + 1;
          local_28 = local_28 + 4;
          iVar3 = *(int *)(iVar1 + 0xf0);
        } while (local_2c <= *(uint *)(iVar3 + 4));
      }
      local_3c = local_3c + 1;
      local_20 = local_20 + 4;
    } while (local_3c <= *(uint *)(param_1 + 0x1c));
  }
  return;
}

/* FUN_000fa6d6 @ 0xfa6d6 (332 bytes) */
int FUN_000fa6d6(param_1)
  undefined4 *param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint local_10;
  
  local_10 = 0;
  iVar3 = param_1[5];
  do {
    iVar4 = local_10 * 4;
    iVar1 = *(int *)(iVar4 + iVar3);
    while (iVar1 != 0) {
      iVar2 = *(int *)(iVar1 + 4);
      if (iVar2 == 0) {
        if (iVar1 != 0) {
          FUN_001a7aba(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
          iVar3 = param_1[5];
        }
        break;
      }
      if (iVar1 != 0) {
        FUN_001a7aba(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
        iVar3 = param_1[5];
      }
      *(int *)(iVar4 + iVar3) = iVar2;
      iVar3 = param_1[5];
      iVar1 = *(int *)(iVar4 + iVar3);
    }
    local_10 = local_10 + 1;
    if ((uint)param_1[7] < local_10) {
      FUN_001a7aba(*(undefined4 *)(param_1[9] + 0xbc),iVar3);
      FUN_001a7aba(*(undefined4 *)(param_1[9] + 0xbc),param_1[6]);
      FUN_001a7aba(*(undefined4 *)(param_1[9] + 0xbc),*param_1);
      FUN_001a7aba(*(undefined4 *)(param_1[9] + 0xbc),param_1[3]);
      FUN_001a7aba(*(undefined4 *)(param_1[9] + 0xbc),param_1[4]);
      FUN_001a7aba(*(undefined4 *)(param_1[9] + 0xbc),param_1[1]);
      FUN_001a7aba(*(undefined4 *)(param_1[9] + 0xbc),param_1[2]);
      param_1[6] = 0;
      return;
    }
  } while( true );
}

/* FUN_000fa822 @ 0xfa822 (332 bytes) */
int FUN_000fa822(param_1)
  undefined4 *param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint local_10;
  
  local_10 = 0;
  iVar3 = param_1[5];
  do {
    iVar4 = local_10 * 4;
    iVar1 = *(int *)(iVar4 + iVar3);
    while (iVar1 != 0) {
      iVar2 = *(int *)(iVar1 + 4);
      if (iVar2 == 0) {
        if (iVar1 != 0) {
          FUN_001a7aba(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
          iVar3 = param_1[5];
        }
        break;
      }
      if (iVar1 != 0) {
        FUN_001a7aba(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
        iVar3 = param_1[5];
      }
      *(int *)(iVar4 + iVar3) = iVar2;
      iVar3 = param_1[5];
      iVar1 = *(int *)(iVar4 + iVar3);
    }
    local_10 = local_10 + 1;
    if ((uint)param_1[7] < local_10) {
      FUN_001a7aba(*(undefined4 *)(param_1[9] + 0xbc),iVar3);
      FUN_001a7aba(*(undefined4 *)(param_1[9] + 0xbc),param_1[6]);
      FUN_001a7aba(*(undefined4 *)(param_1[9] + 0xbc),*param_1);
      FUN_001a7aba(*(undefined4 *)(param_1[9] + 0xbc),param_1[3]);
      FUN_001a7aba(*(undefined4 *)(param_1[9] + 0xbc),param_1[4]);
      FUN_001a7aba(*(undefined4 *)(param_1[9] + 0xbc),param_1[1]);
      FUN_001a7aba(*(undefined4 *)(param_1[9] + 0xbc),param_1[2]);
      param_1[6] = 0;
      return;
    }
  } while( true );
}

/* FUN_000fa96e @ 0xfa96e (639 bytes) */
int FUN_000fa96e(param_1, param_2)
  int *param_1;
  int param_2;
{
  undefined4 *puVar1;
  uint *puVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  int local_20;
  int local_14;
  
  local_20 = param_2;
  *(int *)(param_1[8] + 0x468) = *(int *)(param_1[8] + 0x468) + 1;
  uVar3 = *(undefined4 *)(param_1[9] + 0xbc);
  puVar1 = (undefined4 *)FUN_001a7bca(uVar3,0x14);
  *puVar1 = uVar3;
  puVar2 = puVar1 + 1;
  puVar1[4] = uVar3;
  puVar1[2] = 0;
  puVar1[1] = 2;
  uVar3 = FUN_001a7bca(uVar3,8);
  puVar1[3] = uVar3;
  *(undefined4 *)(param_2 + 0xe0) = 1;
  *(undefined4 *)(*param_1 + 4) = 0;
  *(int *)(param_1[6] + *(int *)(param_2 + 0xe0) * 4) = param_2;
  uVar6 = puVar1[2];
  if (uVar6 < (uint)puVar1[1]) {
    _memset((void *)(uVar6 * 4 + puVar1[3]),0,4);
    puVar1[2] = uVar6 + 1;
    piVar4 = (int *)(uVar6 * 4 + puVar1[3]);
  }
  else {
    piVar4 = (int *)FUN_001a7f7c(puVar2,uVar6);
  }
  *piVar4 = param_2;
  *(int *)(param_1[1] + *(int *)(param_2 + 0xe0) * 4) = *(int *)(param_2 + 0xe0);
  *(int *)(param_1[4] + *(int *)(param_2 + 0xe0) * 4) = *(int *)(param_2 + 0xe0);
  local_14 = 2;
  while( true ) {
    while( true ) {
      iVar5 = FUN_000e9cb4(local_20,*(undefined4 *)(param_1[8] + 0x468));
      if (iVar5 == 0) break;
      uVar6 = puVar1[2];
      if (uVar6 < *puVar2) {
        _memset((void *)(uVar6 * 4 + puVar1[3]),0,4);
        puVar1[2] = uVar6 + 1;
        piVar4 = (int *)(uVar6 * 4 + puVar1[3]);
      }
      else {
        piVar4 = (int *)FUN_001a7f7c(puVar2,uVar6);
      }
      *piVar4 = iVar5;
      *(int *)(iVar5 + 0xe0) = local_14;
      *(undefined4 *)(*param_1 + local_14 * 4) = *(undefined4 *)(local_20 + 0xe0);
      *(int *)(param_1[6] + *(int *)(iVar5 + 0xe0) * 4) = iVar5;
      *(undefined4 *)(iVar5 + 0x110) = *(undefined4 *)(param_1[8] + 0x468);
      local_14 = local_14 + 1;
      *(int *)(param_1[1] + *(int *)(iVar5 + 0xe0) * 4) = *(int *)(iVar5 + 0xe0);
      *(int *)(param_1[4] + *(int *)(iVar5 + 0xe0) * 4) = *(int *)(iVar5 + 0xe0);
      local_20 = iVar5;
    }
    if (puVar1[2] == 0) break;
    uVar6 = puVar1[2] - 1;
    if (uVar6 < (uint)puVar1[2]) {
      piVar4 = (int *)(puVar1[3] + uVar6 * 4);
    }
    else {
      piVar4 = (int *)0x0;
    }
    local_20 = *piVar4;
    FUN_001a7f3c(puVar2,puVar1[2] + -1);
  }
  if (puVar2 != (uint *)0x0) {
    FUN_001a7aba(puVar1[4],puVar1[3]);
    FUN_001a7aba();
    return;
  }
  return;
}

/* FUN_000fac0e @ 0xfac0e (495 bytes) */
int FUN_000fac0e(param_1, param_2)
  int param_1;
  int param_2;
{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int local_1c;
  int local_18;
  
  uVar5 = *(undefined4 *)(*(int *)(param_1 + 0x24) + 0xbc);
  puVar4 = (undefined4 *)FUN_001a7bca(uVar5,0x14);
  *puVar4 = uVar5;
  puVar1 = puVar4 + 1;
  puVar4[4] = uVar5;
  puVar4[2] = 0;
  puVar4[1] = 2;
  uVar5 = FUN_001a7bca(uVar5,8);
  puVar4[3] = uVar5;
  local_18 = param_2 * 4;
  local_1c = param_2;
  for (iVar8 = *(int *)(*(int *)(param_1 + 0xc) + *(int *)(local_18 + *(int *)(param_1 + 0xc)) * 4);
      iVar8 != 0; iVar8 = *(int *)(iVar8 + *(int *)(local_18 + iVar8) * 4)) {
    while (uVar3 = puVar4[2], *puVar1 <= uVar3) {
      piVar6 = (int *)FUN_001a7f7c(puVar1,uVar3);
      *piVar6 = local_1c;
      iVar8 = *(int *)(param_1 + 0xc);
      local_1c = *(int *)(local_18 + iVar8);
      local_18 = local_1c * 4;
      if (*(int *)(iVar8 + *(int *)(local_18 + iVar8) * 4) == 0) goto LAB_000fad1a;
    }
    _memset((void *)(uVar3 * 4 + puVar4[3]),0,4);
    puVar4[2] = uVar3 + 1;
    *(int *)(uVar3 * 4 + puVar4[3]) = local_1c;
    iVar8 = *(int *)(param_1 + 0xc);
    local_1c = *(int *)(local_18 + iVar8);
    local_18 = local_1c * 4;
  }
LAB_000fad1a:
  iVar8 = puVar4[2];
  while (iVar8 != 0) {
    uVar3 = puVar4[2];
    if (uVar3 - 1 < uVar3) {
      piVar6 = (int *)(puVar4[3] + (uVar3 - 1) * 4);
    }
    else {
      piVar6 = (int *)0x0;
    }
    iVar8 = *piVar6;
    FUN_001a7f3c(puVar1,uVar3 - 1);
    iVar8 = iVar8 * 4;
    iVar9 = *(int *)(param_1 + 0xc);
    iVar7 = *(int *)(iVar9 + iVar8) * 4;
    iVar2 = *(int *)(*(int *)(param_1 + 0x10) + iVar7);
    piVar6 = (int *)(iVar8 + *(int *)(param_1 + 0x10));
    if (*(uint *)(*(int *)(param_1 + 4) + iVar2 * 4) <
        *(uint *)(*(int *)(param_1 + 4) + *piVar6 * 4)) {
      *piVar6 = iVar2;
      iVar9 = *(int *)(param_1 + 0xc);
    }
    *(undefined4 *)(iVar8 + iVar9) = *(undefined4 *)(iVar7 + iVar9);
    iVar8 = puVar4[2];
  }
  if (puVar1 != (uint *)0x0) {
    FUN_001a7aba(puVar4[4],puVar4[3]);
    FUN_001a7aba();
    return;
  }
  return;
}

/* FUN_000fae1e @ 0xfae1e (56 bytes) */
int FUN_000fae1e(param_1, param_2)
  int param_1;
  int param_2;
{
  if (*(int *)(*(int *)(param_1 + 0xc) + param_2 * 4) != 0) {
    ((int (*)())FUN_000fac0e)(param_1,param_2);
  }
  return *(undefined4 *)(param_2 * 4 + *(int *)(param_1 + 0x10));
}

/* FUN_000fae56 @ 0xfae56 (746 bytes) */
int FUN_000fae56(param_1)
  int *param_1;
{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  uint local_34;
  uint local_30;
  int local_24;
  int local_20;
  
  iVar1 = *(int *)(param_1[8] + 0x394);
  if (*(int *)(iVar1 + 0xe0) == 0) {
    iVar7 = *(int *)(param_1[8] + 0x378);
    iVar4 = *(int *)(iVar7 + 8);
    while (iVar4 != 0) {
      *(undefined4 *)(iVar7 + 0xe4) = *(undefined4 *)(iVar7 + 0xe0);
      iVar7 = *(int *)(iVar7 + 8);
      iVar4 = *(int *)(iVar7 + 8);
    }
  }
  ((int (*)())FUN_000fa96e)(param_1,iVar1);
  FUN_000edcd4(param_1[8],param_1[6],param_1[7]);
  local_30 = param_1[7];
  if (1 < local_30) {
    local_20 = local_30 << 2;
    do {
      iVar7 = *(int *)(param_1[6] + local_20);
      uVar8 = 1;
      local_24 = 0;
      iVar4 = *(int *)(iVar7 + 0xd4);
      if (*(int *)(iVar4 + 4) != 0) {
        do {
          iVar4 = *(int *)(local_24 + *(int *)(iVar4 + 8));
          if (iVar4 != 0) {
            iVar6 = param_1[1];
            iVar4 = ((int (*)())FUN_000fae1e)(param_1,*(undefined4 *)(iVar4 + 0xe0));
            uVar2 = *(uint *)(iVar6 + iVar4 * 4);
            if (uVar2 < *(uint *)(local_20 + param_1[1])) {
              *(uint *)(local_20 + param_1[1]) = uVar2;
            }
          }
          uVar8 = uVar8 + 1;
          local_24 = local_24 + 4;
          iVar4 = *(int *)(iVar7 + 0xd4);
        } while (uVar8 <= *(uint *)(iVar4 + 4));
      }
      uVar3 = *(undefined4 *)(param_1[9] + 0xbc);
      puVar5 = (undefined4 *)FUN_001a7bca(uVar3,0xc);
      *puVar5 = uVar3;
      puVar5[2] = 0;
      puVar5[1] = local_30;
      puVar5[2] = *(undefined4 *)(param_1[5] + *(int *)(local_20 + param_1[1]) * 4);
      *(undefined4 **)(param_1[5] + *(int *)(local_20 + param_1[1]) * 4) = puVar5 + 1;
      *(undefined4 *)(local_20 + param_1[3]) = *(undefined4 *)(local_20 + *param_1);
      for (piVar9 = *(int **)(param_1[5] + *(int *)(local_20 + *param_1) * 4); piVar9 != (int *)0x0;
          piVar9 = (int *)piVar9[1]) {
        while( true ) {
          iVar7 = *piVar9;
          iVar6 = ((int (*)())FUN_000fae1e)(param_1,iVar7);
          iVar7 = iVar7 * 4;
          iVar4 = *(int *)(param_1[1] + iVar7);
          if (iVar4 != *(int *)(param_1[1] + iVar6 * 4)) break;
          *(int *)(iVar7 + param_1[2]) = iVar4;
          piVar9 = (int *)piVar9[1];
          if (piVar9 == (int *)0x0) goto LAB_000fb025;
        }
        *(int *)(iVar7 + param_1[2]) = iVar6;
      }
LAB_000fb025:
      local_30 = local_30 - 1;
      local_20 = local_20 + -4;
    } while (1 < local_30);
  }
  *(undefined4 *)(param_1[2] + 4) = 0;
  if (1 < (uint)param_1[7]) {
    local_34 = 2;
    do {
      piVar9 = (int *)(local_34 * 4 + param_1[2]);
      iVar7 = *piVar9;
      if (iVar7 != *(int *)(local_34 * 4 + param_1[1])) {
        *piVar9 = *(int *)(param_1[2] + iVar7 * 4);
      }
      local_34 = local_34 + 1;
    } while (local_34 <= (uint)param_1[7]);
  }
  if (param_1[7] != 0) {
    uVar8 = 1;
    iVar7 = param_1[6];
LAB_000fb09b:
    *(undefined4 *)(*(int *)(iVar7 + uVar8 * 4) + 0xec) = 0;
    while (uVar8 = uVar8 + 1, uVar8 <= (uint)param_1[7]) {
      while( true ) {
        if (uVar8 == 1) {
          iVar7 = param_1[6];
          goto LAB_000fb09b;
        }
        iVar7 = *(int *)(param_1[6] + *(int *)(param_1[2] + uVar8 * 4) * 4);
        iVar4 = *(int *)(param_1[6] + uVar8 * 4);
        *(int *)(iVar4 + 0xec) = iVar7;
        if (iVar7 != 0) break;
        uVar8 = uVar8 + 1;
        if ((uint)param_1[7] < uVar8) goto LAB_000fb0eb;
      }
      FUN_000ea7cc(iVar7,iVar4);
    }
  }
LAB_000fb0eb:
  ((int (*)())FUN_000fa54e)(param_1);
  if (*(int *)(iVar1 + 0xe4) == 0) {
    iVar1 = *(int *)(param_1[8] + 0x378);
    iVar7 = *(int *)(iVar1 + 8);
    while (iVar7 != 0) {
      *(undefined4 *)(iVar1 + 0xe0) = *(undefined4 *)(iVar1 + 0xe4);
      iVar1 = *(int *)(iVar1 + 8);
      iVar7 = *(int *)(iVar1 + 8);
    }
  }
  return;
}

/* FUN_000fb140 @ 0xfb140 (106 bytes) */
int FUN_000fb140(param_1)
  int param_1;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  uVar2 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
  puVar3 = (undefined4 *)FUN_001a7bca(uVar2,0x2c);
  *puVar3 = uVar2;
  puVar1 = puVar3 + 1;
  ((int (*)())FUN_000fa45c)(puVar1,param_1);
  ((int (*)())FUN_000fae56)(puVar1);
  if (puVar1 != (undefined4 *)0x0) {
    ((int (*)())FUN_000fa822)(puVar1);
    FUN_001a7aba(*puVar3,puVar3);
  }
  return;
}

/* FUN_000fb1c8 @ 0xfb1c8 (18 bytes) */
int FUN_000fb1c8(param_1, param_2)
  int param_1;
  int param_2;
{
  return *(undefined4 *)(param_2 + 8 + param_1 * 0x24);
}

/* FUN_000fb1da @ 0xfb1da (18 bytes) */
int FUN_000fb1da(param_1, param_2)
  int param_1;
  int param_2;
{
  return *(undefined4 *)(param_2 + 4 + param_1 * 0x24);
}

/* FUN_000fb1ec @ 0xfb1ec (24 bytes) */
int FUN_000fb1ec(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  return *(undefined1 *)(param_1 * 0x24 + param_2 + param_3 + 0x1c);
}

/* FUN_000fb204 @ 0xfb204 (18 bytes) */
int FUN_000fb204(param_1, param_2)
  int param_1;
  int param_2;
{
  return *(undefined4 *)(param_2 + 0xc + param_1 * 0x24);
}

/* FUN_000fb216 @ 0xfb216 (18 bytes) */
int FUN_000fb216(param_1, param_2)
  int param_1;
  int param_2;
{
  return *(undefined4 *)(param_2 + 0x10 + param_1 * 0x24);
}

/* FUN_000fb228 @ 0xfb228 (34 bytes) */
int FUN_000fb228(param_1)
  uint param_1;
{
  if (5 < param_1) {
    return 8;
  }
  return *(undefined4 *)(PTR_DAT_0021347d + param_1 * 4);
}

/* FUN_000fb24a @ 0xfb24a (29 bytes) */
int FUN_000fb24a(param_1)
  int param_1;
{
  if (param_1 != 1) {
    return (param_1 != 2) + '\x01';
  }
  return '\0';
}

/* FUN_000fb268 @ 0xfb268 (30 bytes) */
int FUN_000fb268(param_1)
  int param_1;
{
  if (param_1 != 1) {
    return (param_1 != 2) * '\x02' + '\x01';
  }
  return '\0';
}

/* FUN_000fb286 @ 0xfb286 (77 bytes) */
int FUN_000fb286(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  if (param_1 == 4) {
    *(undefined1 *)(param_3 + param_2) = 0;
    return;
  }
  if (param_1 != 5) {
    *(undefined1 *)(param_3 + param_2) = 1;
    *(char *)(param_4 + param_2) = (char)*(undefined4 *)(PTR_DAT_002134b1 + param_1 * 4);
    return;
  }
  *(undefined1 *)(param_3 + param_2) = 0;
  return;
}

/* FUN_000fb2d4 @ 0xfb2d4 (471 bytes) */
int FUN_000fb2d4(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  uint *param_2;
  int param_3;
  int param_4;
  int *param_5;
{
  uint uVar1;
  byte bVar2;
  char local_20 [16];
  
  uVar1 = *param_2;
  local_20[0] = '\0';
  local_20[1] = 1;
  local_20[2] = 2;
  local_20[3] = 3;
  if (param_3 != 0) {
    bVar2 = *(byte *)(param_3 + 2);
    if (((bVar2 & 0x40) != 0) &&
       ((byte)(*(byte *)(param_3 + 4) >> 7 & *(byte *)(param_3 + 4) >> 3 &
               *(byte *)(param_3 + 5) >> 3 & *(byte *)(param_3 + 5) >> 7) != 0)) {
      FUN_00109c0e(param_5 + param_4 * 6 + 0x23,1,*(byte *)(param_5 + param_4 * 6 + 0x28) & 1 ^ 1);
      bVar2 = *(byte *)(param_3 + 2);
    }
    if (((bVar2 & 0x40) != 0) && ((*(byte *)(param_3 + 6) & 0x10) != 0)) {
      FUN_00109c0e(param_5 + param_4 * 6 + 0x23,2,1);
    }
    local_20[0] = FUN_001b2b8c(param_3,0);
    local_20[1] = FUN_001b2b8c(param_3,1);
    local_20[2] = FUN_001b2b8c(param_3,2);
    local_20[3] = FUN_001b2b8c(param_3,3);
  }
  (**(code **)(*param_5 + 0x88))(param_5,param_4,0,(int)local_20[uVar1 & 0xff]);
  (**(code **)(*param_5 + 0x88))(param_5,param_4,1,(int)local_20[uVar1 >> 8 & 0xff]);
  (**(code **)(*param_5 + 0x88))(param_5,param_4,2,(int)local_20[uVar1 >> 0x10 & 0xff]);
  (**(code **)(*param_5 + 0x88))(param_5,param_4,3,(int)local_20[uVar1 >> 0x18]);
  *param_2 = DAT_001c66c0;
  return;
}

/* FUN_000fb4ac @ 0xfb4ac (57 bytes) */
int FUN_000fb4ac(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = param_1 + -0x30;
  if (1 < iVar1) {
    if (param_1 == '_') {
      return DAT_001c6704;
    }
    iVar1 = param_1 + -0x74;
  }
  return *(undefined4 *)(&DAT_001c66fc + iVar1 * 4);
}

/* FUN_000fb4e6 @ 0xfb4e6 (5 bytes) */
int FUN_000fb4e6()
{
  return;
}

/* FUN_000fb4ec @ 0xfb4ec (90 bytes) */
int FUN_000fb4ec(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  char cVar1;
  
  cVar1 = (**(code **)(**(int **)(param_2 + 0x54) + 0xdc))(*(int **)(param_2 + 0x54));
  if (cVar1 == '\0') {
    return (PTR_DAT_001fc584)[param_1 * 3];
  }
  if (param_3 == '\0') {
    return (PTR_DAT_001fc588)[param_1 * 3];
  }
  return (PTR_DAT_001fc580)[param_1 * 3];
}

/* FUN_000fb546 @ 0xfb546 (597 bytes) */
int FUN_000fb546(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
  undefined4 param_5;
  int param_6;
  int param_7;
{
  code *pcVar1;
  undefined *puVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  undefined1 uVar6;
  char cVar7;
  int iVar8;
  undefined1 *local_34;
  char *local_30;
  char acStack_21 [17];
  
  cVar7 = param_7;
  iVar8 = param_4;
  acStack_21[1] = 0;
  acStack_21[2] = 0;
  acStack_21[3] = 0;
  acStack_21[4] = 0;
  uVar5 = *(undefined4 *)(param_6 + 0x98);
  if (param_4 != 0) {
    if ((*(ushort *)(param_4 + 2) & 0x180) == 0x80) {
      if (*(char *)(param_1 + 0x3d8) == '\0') {
        *(undefined1 *)(param_1 + 0x3d8) = 1;
        *(undefined4 *)(param_1 + 1000) = uVar5;
      }
      uVar5 = *(undefined4 *)(param_6 + 0x94);
      iVar4 = *(int *)(*(int *)(param_1 + 8) + 0x104) + 1;
      *(int *)(*(int *)(param_1 + 8) + 0x104) = iVar4;
      iVar4 = FUN_0012eb84(*(undefined4 *)(param_1 + 0x3a0),0x2a,iVar4,0);
      *(undefined4 *)(iVar4 + 0x30) = uVar5;
      FUN_0010a3c2(param_6,0,iVar4);
    }
    if (((*(byte *)(iVar8 + 2) & 0x40) != 0) && ((*(byte *)(iVar8 + 5) & 1) != 0)) {
      pcVar1 = *(code **)(**(int **)(*(int *)(param_1 + 8) + 0x54) + 0x78);
      uVar5 = FUN_000edadc(param_1,*(byte *)(iVar8 + 2) & 0x3f);
      cVar3 = (*pcVar1)(*(undefined4 *)(*(int *)(param_1 + 8) + 0x54),uVar5);
      if (cVar3 == '\0') {
        iVar4 = FUN_000edadc(param_1,*(byte *)(iVar8 + 2) & 0x3f);
        if (iVar4 != 9) {
          FUN_000edadc(param_1,*(byte *)(iVar8 + 2) & 0x3f);
        }
      }
      else {
        *(undefined1 *)(param_6 + 0x120) = 1;
      }
    }
    iVar4 = FUN_001b2b34(iVar8,0);
    puVar2 = PTR_DAT_002134c1;
    acStack_21[1] = (char)*(undefined4 *)(PTR_DAT_002134c1 + iVar4 * 4);
    iVar4 = FUN_001b2b34(iVar8,1);
    acStack_21[2] = (char)*(undefined4 *)(puVar2 + iVar4 * 4);
    iVar4 = FUN_001b2b34(iVar8,2);
    acStack_21[3] = (char)*(undefined4 *)(puVar2 + iVar4 * 4);
    FUN_001b2b34(iVar8,3);
  }
  if (cVar7 != '\0') {
    iVar8 = 1;
    local_34 = (undefined1 *)&param_3;
    do {
      uVar6 = 1;
      if (acStack_21[iVar8] != '\x01') {
        uVar6 = *local_34;
      }
      *(undefined1 *)(param_6 + 0x9c) = uVar6;
      iVar8 = iVar8 + 1;
      local_34 = local_34 + 1;
      param_6 = param_6 + 1;
    } while (iVar8 != 5);
    return;
  }
  iVar8 = 1;
  local_30 = (char *)&param_3;
  do {
    cVar7 = acStack_21[iVar8];
    if (*local_30 != '\0') {
      cVar7 = *local_30;
    }
    *(char *)(param_6 + 0x9c) = cVar7;
    iVar8 = iVar8 + 1;
    local_30 = local_30 + 1;
    param_6 = param_6 + 1;
  } while (iVar8 != 5);
  return;
}

/* FUN_000fb79c @ 0xfb79c (113 bytes) */
int FUN_000fb79c(param_1, param_2)
  int param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = FUN_001b2b8c(param_1,iVar2);
    (**(code **)(*param_2 + 0x88))(param_2,1,iVar2,*(undefined4 *)(PTR_DAT_002134b1 + iVar1 * 4));
    iVar2 = iVar2 + 1;
  } while (iVar2 != 4);
  if ((*(byte *)(param_1 + 2) & 0x40) != 0) {
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xffff8888 | 0x3210;
  }
  return;
}

/* FUN_000fb80e @ 0xfb80e (289 bytes) */
int FUN_000fb80e(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_0010a17a(0x17,*(undefined4 *)(param_1 + 8));
  iVar2 = FUN_0010b0f4(uVar1,0);
  *(undefined4 *)(iVar2 + 8) = param_2;
  *(undefined4 *)(iVar2 + 0xc) = 0;
  iVar2 = FUN_0010b0f4(uVar1,1);
  *(undefined4 *)(iVar2 + 8) = param_2;
  *(undefined4 *)(iVar2 + 0xc) = 0;
  ((int (*)())FUN_000fa0d2)(uVar1,param_1,2,0,0,0,0);
  FUN_001a7cd6(param_3,uVar1);
  uVar1 = FUN_0010a17a(0x19,*(undefined4 *)(param_1 + 8));
  iVar2 = FUN_0010b0f4(uVar1,0);
  *(undefined4 *)(iVar2 + 8) = param_2;
  *(undefined4 *)(iVar2 + 0xc) = 0;
  iVar2 = FUN_0010b0f4(uVar1,1);
  *(undefined4 *)(iVar2 + 8) = param_2;
  *(undefined4 *)(iVar2 + 0xc) = 0;
  ((int (*)())FUN_000fa0d2)(uVar1,param_1,2,0x3f800000,0x3f800000,0x3f800000,0x3f800000);
  FUN_001a7cd6(param_3,uVar1);
  return uVar1;
}

/* FUN_000fb930 @ 0xfb930 (247 bytes) */
int FUN_000fb930(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  undefined4 *puVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  
  puVar1 = (undefined4 *)(*(int *)(*(int *)(*(int *)(param_1 + 8) + 0x54) + 0xc) + param_2 * 0x24);
  iVar4 = (*(code *)puVar1[5])(*puVar1,*(int *)(param_1 + 8));
  if ((param_3 != 0) &&
     (piVar2 = *(int **)(*(int *)(param_1 + 8) + 0x54),
     cVar3 = (**(code **)(*piVar2 + 0xb0))(piVar2), cVar3 != '\0')) {
    switch(param_2) {
    case 0x22:
      uVar5 = FUN_00118f66(0xdf);
      *(undefined4 *)(iVar4 + 0x88) = uVar5;
      break;
    case 0x23:
      uVar5 = FUN_00118f66(0xde);
      *(undefined4 *)(iVar4 + 0x88) = uVar5;
      break;
    case 0x40:
      uVar5 = FUN_00118f66(0xf0);
      *(undefined4 *)(iVar4 + 0x88) = uVar5;
      break;
    case 0x41:
      uVar5 = FUN_00118f66(0xb7);
      *(undefined4 *)(iVar4 + 0x88) = uVar5;
      break;
    case 0x44:
      uVar5 = FUN_00118f66(0xb8);
      *(undefined4 *)(iVar4 + 0x88) = uVar5;
      break;
    case 0x49:
      uVar5 = FUN_00118f66(0xb6);
      *(undefined4 *)(iVar4 + 0x88) = uVar5;
    }
  }
  return iVar4;
}

/* FUN_000fbaca @ 0xfbaca (568 bytes) */
int FUN_000fbaca(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  undefined4 param_3;
{
  undefined2 uVar1;
  int *piVar2;
  int iVar3;
  char cVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 local_30;
  undefined4 local_2c;
  
  cVar4 = (**(code **)(*param_2 + 0x30))(param_2);
  if (cVar4 != '\0') {
    piVar2 = *(int **)(*(int *)(param_1 + 8) + 0x54);
    cVar4 = (**(code **)(*piVar2 + 0x168))(piVar2,param_1,param_2);
    if (cVar4 != '\0') {
      uVar5 = FUN_0010a17a(0x13,*(undefined4 *)(param_1 + 8));
      iVar9 = *(int *)(*(int *)(param_1 + 8) + 0xf0) + -1;
      *(int *)(*(int *)(param_1 + 8) + 0xf0) = iVar9;
      iVar6 = FUN_0010b0f4(uVar5,0);
      *(int *)(iVar6 + 8) = iVar9;
      *(undefined4 *)(iVar6 + 0xc) = 0;
      uVar1 = (undefined2)param_2[0x4d];
      local_30 = CONCAT22(uVar1,7);
      local_2c = CONCAT22(uVar1,6);
      ((int (*)())FUN_000f9d16)(uVar5,param_1,1,local_2c,local_30,CONCAT22(uVar1,7),CONCAT22(uVar1,7));
      iVar6 = param_2[0x2c];
      iVar3 = param_2[0x2b];
      iVar7 = FUN_0010b0f4(uVar5,2);
      *(int *)(iVar7 + 8) = iVar3;
      *(int *)(iVar7 + 0xc) = iVar6;
      ((int (*)())FUN_000fbaca)(param_1,uVar5,param_3);
      iVar7 = FUN_0010a17a(0x31,*(undefined4 *)(param_1 + 8));
      iVar6 = FUN_0010b0f4(iVar7,0);
      *(int *)(iVar6 + 8) = iVar9;
      *(undefined4 *)(iVar6 + 0xc) = 0;
      *(undefined4 *)(iVar7 + 0x9c) = DAT_001c6738;
      iVar6 = param_2[0x2c];
      iVar3 = param_2[0x2b];
      iVar8 = FUN_0010b0f4(iVar7,1);
      *(int *)(iVar8 + 8) = iVar3;
      *(int *)(iVar8 + 0xc) = iVar6;
      ((int (*)())FUN_000fbaca)(param_1,iVar7,param_3);
      iVar6 = FUN_0010b0f4(param_2,1);
      *(int *)(iVar6 + 8) = iVar9;
      *(undefined4 *)(iVar6 + 0xc) = 0;
    }
  }
  FUN_000e9512(param_3,param_2);
  FUN_000f0144(param_1,param_2);
  (**(code **)(*param_2 + 8))(param_2,*(undefined4 *)(param_1 + 8));
  return;
}

/* FUN_000fbd02 @ 0xfbd02 (1637 bytes) */
int FUN_000fbd02(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  undefined4 param_2;
  ushort *param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  ushort uVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  undefined4 *puVar10;
  int iVar11;
  uint local_4c;
  undefined4 *local_40;
  uint local_3c;
  int local_34;
  int local_30;
  undefined4 local_20 [4];
  
  if (*(int *)(param_1 + 0x368) == 0) {
    switch(param_7) {
    case 0:
      local_4c = 1;
      break;
    case 1:
      local_4c = 2;
      break;
    case 2:
      local_4c = 3;
      break;
    case 3:
      local_4c = 4;
      break;
    case 4:
      local_4c = 6;
      break;
    default:
      local_4c = 0;
    }
    FUN_000e97aa(*(undefined4 *)(param_1 + 0x394));
    uVar8 = FUN_000eac7c(*(undefined4 *)(param_1 + 0x394),0);
    uVar6 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
    puVar3 = (undefined4 *)FUN_001a7bca(uVar6,0x168);
    *puVar3 = uVar6;
    puVar4 = puVar3 + 1;
    FUN_0010f1ac(puVar4,0x83,*(undefined4 *)(param_1 + 8));
    iVar5 = FUN_0010b0f4(puVar4,0);
    *(undefined4 *)(iVar5 + 8) = 0;
    *(undefined4 *)(iVar5 + 0xc) = 0x39;
    uVar9 = local_4c;
    if (3 < local_4c) {
      uVar9 = 3;
    }
    puVar3[0x22] = uVar9;
    if (local_4c == 0) {
      local_40 = (undefined4 *)0x0;
    }
    else {
      local_3c = 0;
      local_40 = (undefined4 *)0x0;
      local_34 = 1;
      local_30 = -2;
      do {
        iVar5 = FUN_0010a17a(0x31,*(undefined4 *)(param_1 + 8));
        iVar7 = local_3c + 2;
        FUN_00137bae(param_1,iVar7);
        iVar11 = FUN_0010b0f4(iVar5,0);
        *(int *)(iVar11 + 8) = iVar7;
        *(undefined4 *)(iVar11 + 0xc) = 0x10;
        *(undefined4 *)(iVar5 + 0x9c) = DAT_001c66e8;
        FUN_00137b7e(param_1,iVar7);
        FUN_00138146(param_1,iVar7);
        piVar2 = *(int **)(*(int *)(param_1 + 8) + 0x54);
        uVar6 = (**(code **)(*piVar2 + 0x9c))(piVar2,local_3c,*(int *)(param_1 + 8));
        iVar11 = FUN_0010b0f4(iVar5,1);
        *(undefined4 *)(iVar11 + 8) = uVar6;
        *(undefined4 *)(iVar11 + 0xc) = 0x1f;
        piVar2 = *(int **)(*(int *)(param_1 + 8) + 0x54);
        uVar6 = (**(code **)(*piVar2 + 0xa0))(piVar2,local_3c,*(int *)(param_1 + 8));
        iVar11 = FUN_0010b0f4(iVar5,1);
        *(undefined4 *)(iVar11 + 0x10) = uVar6;
        ((int (*)())FUN_000fbaca)(param_1,iVar5,uVar8);
        if ((int)local_3c < 3) {
          FUN_0010a3c2(puVar4,local_34,*(undefined4 *)(iVar5 + 0x8c));
          uVar6 = DAT_001c66e4;
          if (local_34 == 0) {
            puVar3[0x28] = DAT_001c66e4;
          }
          else {
            iVar5 = FUN_0010b0f4(puVar4,local_34);
            *(undefined4 *)(iVar5 + 0x10) = uVar6;
          }
        }
        else {
          if (local_40 == (undefined4 *)0x0) {
            uVar6 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
            puVar10 = (undefined4 *)FUN_001a7bca(uVar6,0x168);
            *puVar10 = uVar6;
            local_40 = puVar10 + 1;
            FUN_0010f1ac(local_40,0x83,*(undefined4 *)(param_1 + 8));
            iVar11 = FUN_0010b0f4(local_40,0);
            *(undefined4 *)(iVar11 + 8) = 1;
            *(undefined4 *)(iVar11 + 0xc) = 0x39;
            if (local_4c == 4) {
              uVar6 = 2;
            }
            else {
              uVar6 = 4;
            }
            puVar10[0x22] = uVar6;
          }
          FUN_0010a3c2(local_40,local_30,*(undefined4 *)(iVar5 + 0x8c));
          uVar6 = DAT_001c66e4;
          if (local_30 == 0) {
            local_40[0x27] = DAT_001c66e4;
          }
          else {
            iVar5 = FUN_0010b0f4(local_40,local_30);
            *(undefined4 *)(iVar5 + 0x10) = uVar6;
          }
        }
        uVar6 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
        puVar10 = (undefined4 *)FUN_001a7bca(uVar6,0x168);
        *puVar10 = uVar6;
        puVar10 = puVar10 + 1;
        FUN_0010e9ea(puVar10,0x7a,*(undefined4 *)(param_1 + 8));
        iVar5 = FUN_0010b0f4(puVar10,0);
        *(int *)(iVar5 + 8) = iVar7;
        *(undefined4 *)(iVar5 + 0xc) = 0x10;
        ((int (*)())FUN_000fbaca)(param_1,puVar10,*(undefined4 *)(param_1 + 0x394));
        local_3c = local_3c + 1;
        local_34 = local_34 + 1;
        local_30 = local_30 + 1;
      } while (local_4c != local_3c);
    }
    ((int (*)())FUN_000fbaca)(param_1,puVar4,uVar8);
    if (local_40 == (undefined4 *)0x0) {
      *(undefined4 **)(param_1 + 0x368) = puVar4;
    }
    else {
      FUN_0010a3c2(local_40,(local_4c != 4) * '\x02' + '\x02',puVar3[0x24]);
      ((int (*)())FUN_000fbaca)(param_1,local_40,uVar8);
      *(undefined4 **)(param_1 + 0x368) = local_40;
    }
  }
  uVar6 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
  puVar3 = (undefined4 *)FUN_001a7bca(uVar6,0x168);
  *puVar3 = uVar6;
  puVar4 = puVar3 + 1;
  FUN_0010f2b4(puVar4,0x84,*(undefined4 *)(param_1 + 8));
  iVar11 = *(int *)(*(int *)(param_1 + 8) + 0xf8) + 1;
  *(int *)(*(int *)(param_1 + 8) + 0xf8) = iVar11;
  iVar5 = FUN_0012eb84(*(undefined4 *)(param_1 + 0x3a0),0x3a,iVar11,0);
  *(undefined4 *)(iVar5 + 0x30) = 2;
  FUN_0010a3c2(puVar4,0,iVar5);
  uVar6 = FUN_000edadc(param_1,(byte)param_3[1] & 0x3f);
  uVar1 = *param_3;
  iVar5 = FUN_0010b0f4(puVar4,1);
  *(uint *)(iVar5 + 8) = (uint)uVar1;
  *(undefined4 *)(iVar5 + 0xc) = uVar6;
  local_20[0] = DAT_001c66c0;
  ((int (*)())FUN_000fb2d4)(param_1,local_20,param_3,1,puVar4);
  *(undefined1 *)(puVar3 + 0x4d) = 1;
  FUN_001a7cd6(param_2,puVar4);
  iVar5 = FUN_0010a17a(0x31,*(undefined4 *)(param_1 + 8));
  uVar6 = FUN_000edadc(param_1,param_6);
  iVar7 = FUN_0010b0f4(iVar5,0);
  *(undefined4 *)(iVar7 + 8) = param_5;
  *(undefined4 *)(iVar7 + 0xc) = uVar6;
  *(undefined4 *)(iVar5 + 0x9c) = DAT_001c66e8;
  iVar7 = FUN_0010b0f4(iVar5,1);
  *(int *)(iVar7 + 8) = iVar11;
  *(undefined4 *)(iVar7 + 0xc) = 0x3a;
  FUN_0010a6a6(iVar5,*(undefined4 *)(*(int *)(param_1 + 0x368) + 0x8c),*(undefined4 *)(param_1 + 8))
  ;
  FUN_001a7cd6(param_2,iVar5);
  return;
}

/* FUN_000fc3f6 @ 0xfc3f6 (4675 bytes) */
int FUN_000fc3f6(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 param_2;
  uint *param_3;
  undefined4 param_4;
  int param_5;
{
  uint *puVar1;
  code *pcVar2;
  int *piVar3;
  bool bVar4;
  bool bVar5;
  uint uVar6;
  byte bVar7;
  char cVar8;
  ushort uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 *puVar15;
  byte bVar16;
  int iVar17;
  uint uVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  undefined4 local_88;
  int local_78;
  int local_74;
  undefined4 *local_6c;
  uint local_68;
  uint local_4c;
  undefined4 local_24;
  undefined4 local_20 [4];
  
  iVar10 = (int)(short)*param_3;
  bVar16 = *(byte *)((int)param_3 + 2) & 0x3f;
  if (((*param_3 & 0x400000) == 0) || (bVar7 = *(byte *)((int)param_3 + 5) >> 1, (bVar7 & 0xf) == 0)
     ) {
    local_78 = 0;
    local_74 = 0;
  }
  else {
    local_74 = *(int *)(*(int *)(param_1 + 8) + 0xf0) + -1;
    *(int *)(*(int *)(param_1 + 8) + 0xf0) = local_74;
    *(short *)param_3 = (short)local_74;
    *param_3 = *param_3 & 0xffc0ffff | 0x40000;
    local_78 = FUN_0010a17a(0x13,*(undefined4 *)(param_1 + 8));
    iVar11 = FUN_0010b0f4(local_78,0);
    *(int *)(iVar11 + 8) = local_74;
    *(undefined4 *)(iVar11 + 0xc) = 0;
    iVar11 = FUN_0010b0f4(local_78,1);
    *(int *)(iVar11 + 8) = local_74;
    *(undefined4 *)(iVar11 + 0xc) = 0;
    uVar13 = *(undefined4 *)(&DAT_001c6714 + (bVar7 & 0xf) * 4);
    ((int (*)())FUN_000fa0d2)(local_78,param_1,2,uVar13,uVar13,uVar13,uVar13);
    FUN_001a7cd6(param_2,local_78);
  }
  uVar18 = 0;
  iVar11 = 0;
  do {
    iVar12 = FUN_001b2b34(param_3,iVar11);
    uVar18 = uVar18 | (uint)(iVar12 == 2) << ((byte)iVar11 & 0x1f);
    iVar11 = iVar11 + 1;
  } while (iVar11 != 4);
  if (uVar18 != 0) {
    if (local_78 == 0) {
      local_74 = *(int *)(*(int *)(param_1 + 8) + 0xf0) + -1;
      *(int *)(*(int *)(param_1 + 8) + 0xf0) = local_74;
      *(short *)param_3 = (short)local_74;
      *param_3 = *param_3 & 0xffc0ffff | 0x40000;
    }
    local_78 = FUN_0010a17a(0x31,*(undefined4 *)(param_1 + 8));
    iVar11 = FUN_0010b0f4(local_78,0);
    *(int *)(iVar11 + 8) = local_74;
    *(undefined4 *)(iVar11 + 0xc) = 0;
    ((int (*)())FUN_000fa0d2)(local_78,param_1,1,0,0,0,0);
    iVar12 = 0;
    iVar11 = local_78;
    do {
      *(bool *)(iVar11 + 0x9c) = ((int)uVar18 >> ((byte)iVar12 & 0x1f) & 1U) == 0;
      iVar12 = iVar12 + 1;
      iVar11 = iVar11 + 1;
    } while (iVar12 != 4);
    FUN_001a7cd6(param_2,local_78);
  }
  uVar18 = 0;
  iVar11 = 0;
  do {
    iVar12 = FUN_001b2b34(param_3,iVar11);
    uVar18 = uVar18 | (uint)(iVar12 == 3) << ((byte)iVar11 & 0x1f);
    iVar11 = iVar11 + 1;
  } while (iVar11 != 4);
  if (uVar18 != 0) {
    if (local_78 == 0) {
      local_74 = *(int *)(*(int *)(param_1 + 8) + 0xf0) + -1;
      *(int *)(*(int *)(param_1 + 8) + 0xf0) = local_74;
      *(short *)param_3 = (short)local_74;
      *param_3 = *param_3 & 0xffc0ffff | 0x40000;
    }
    local_78 = FUN_0010a17a(0x31,*(undefined4 *)(param_1 + 8));
    iVar11 = FUN_0010b0f4(local_78,0);
    *(int *)(iVar11 + 8) = local_74;
    *(undefined4 *)(iVar11 + 0xc) = 0;
    ((int (*)())FUN_000fa0d2)(local_78,param_1,1,0x3f800000,0x3f800000,0x3f800000,0x3f800000);
    iVar12 = 0;
    iVar11 = local_78;
    do {
      *(bool *)(iVar11 + 0x9c) = ((int)uVar18 >> ((byte)iVar12 & 0x1f) & 1U) == 0;
      iVar12 = iVar12 + 1;
      iVar11 = iVar11 + 1;
    } while (iVar12 != 4);
    FUN_001a7cd6(param_2,local_78);
  }
  local_88 = DAT_001c66f4;
  if ((*param_3 & 0x400000) != 0) {
    uVar18 = param_3[1];
    local_88 = CONCAT13((uVar18 & 0xc0) == 0,
                        CONCAT12((uVar18 & 0x30) == 0,
                                 CONCAT11((uVar18 & 0xc) == 0,(uVar18 & 3) == 0)));
  }
  cVar8 = FUN_001b2c88(param_3);
  if (cVar8 != '\0') {
    local_78 = FUN_0010a17a(0x31,*(undefined4 *)(param_1 + 8));
    iVar11 = FUN_0010b0f4(local_78,0);
    *(int *)(iVar11 + 8) = local_74;
    *(undefined4 *)(iVar11 + 0xc) = 0;
    iVar11 = FUN_0010b0f4(local_78,1);
    *(int *)(iVar11 + 8) = local_74;
    *(undefined4 *)(iVar11 + 0xc) = 0;
    FUN_001a7cd6(param_2,local_78);
  }
  if (((*param_3 & 0x400000) == 0) || ((*(byte *)((int)param_3 + 5) & 1) == 0)) {
LAB_000fc7e0:
    bVar4 = false;
  }
  else {
    pcVar2 = *(code **)(**(int **)(*(int *)(param_1 + 8) + 0x54) + 0x78);
    uVar13 = FUN_000edadc(param_1,bVar16);
    cVar8 = (*pcVar2)(*(undefined4 *)(*(int *)(param_1 + 8) + 0x54),uVar13);
    if (cVar8 == '\0') {
      iVar11 = FUN_000edadc(param_1,*(byte *)((int)param_3 + 2) & 0x3f);
      if (iVar11 == 9) goto LAB_000fc7e0;
      FUN_000edadc(param_1,*(byte *)((int)param_3 + 2) & 0x3f);
      bVar4 = false;
    }
    else {
      piVar3 = *(int **)(*(int *)(param_1 + 8) + 0x54);
      cVar8 = (**(code **)(*piVar3 + 0x80))(piVar3);
      if (cVar8 == '\0') {
        if (local_78 == 0) {
          local_74 = *(int *)(*(int *)(param_1 + 8) + 0xf0) + -1;
          *(int *)(*(int *)(param_1 + 8) + 0xf0) = local_74;
          *(short *)param_3 = (short)local_74;
          *param_3 = *param_3 & 0xffc0ffff | 0x40000;
        }
        local_78 = ((int (*)())FUN_000fb80e)(param_1,local_74,param_2);
        if ((*param_3 & 0x400000) == 0) goto LAB_000fc7e0;
        *(byte *)((int)param_3 + 5) = *(byte *)((int)param_3 + 5) & 0xfe;
        bVar4 = false;
      }
      else {
        bVar4 = true;
      }
    }
  }
  if (local_78 == 0) {
    bVar7 = *(byte *)((int)param_3 + 2);
  }
  else {
    if ((*param_3 & 0x1800000) == 0x800000) {
      if (*(char *)(param_1 + 0x3d8) == '\0') {
        *(undefined1 *)(param_1 + 0x3d8) = 1;
        uVar13 = FUN_000edadc(param_1,bVar16);
        *(undefined4 *)(param_1 + 1000) = uVar13;
      }
      else {
        FUN_000edadc(param_1,bVar16);
      }
      iVar11 = *(int *)(*(int *)(param_1 + 8) + 0x104) + 1;
      *(int *)(*(int *)(param_1 + 8) + 0x104) = iVar11;
      iVar11 = FUN_0012eb84(*(undefined4 *)(param_1 + 0x3a0),0x2a,iVar11,0);
      *(int *)(iVar11 + 0x30) = iVar10;
      FUN_0010a3c2(local_78,0,iVar11);
      *param_3 = *param_3 & 0xfe7fffff;
    }
    else {
      uVar13 = FUN_000edadc(param_1,bVar16);
      iVar11 = FUN_0010b0f4(local_78,0);
      *(int *)(iVar11 + 8) = iVar10;
      *(undefined4 *)(iVar11 + 0xc) = uVar13;
    }
    if (bVar4) {
      *(undefined1 *)(local_78 + 0x120) = 1;
    }
    if ((*param_3 & 0x400000) != 0) {
      *(byte *)((int)param_3 + 5) = *(byte *)((int)param_3 + 5) & 0xfe;
    }
    iVar11 = 0;
    do {
      iVar12 = FUN_001b2b34(param_3,iVar11);
      *(bool *)(local_78 + 0x9c) = iVar12 == 0;
      iVar11 = iVar11 + 1;
      local_78 = local_78 + 1;
    } while (iVar11 != 4);
    bVar7 = *(byte *)((int)param_3 + 2);
    if ((bVar7 & 0x40) != 0) {
      *(undefined1 *)(param_3 + 1) = 0x55;
    }
  }
  if ((bVar16 == 0x1f) && ((*(byte *)(param_1 + 0x31) & 0x40) != 0)) {
    bVar4 = true;
    bVar5 = true;
  }
  else {
    bVar4 = false;
    bVar5 = false;
  }
  if (((bVar7 & 0x3f) == 0x1b) || (bVar4)) {
    iVar11 = *(int *)(*(int *)(param_1 + 8) + 0xf0) + -1;
    *(int *)(*(int *)(param_1 + 8) + 0xf0) = iVar11;
    local_68 = (uint)(ushort)*param_3;
    bVar7 = *(byte *)((int)param_3 + 2) & 0x3f;
    if ((char)*(byte *)((int)param_3 + 3) < '\0') {
      local_68 = local_68 | param_3[1] << 0x10;
      iVar12 = 3 - (uint)((*param_3 & 0x400000) == 0);
      uVar9 = *(ushort *)((int)param_3 + 2) & 0x180;
      if (uVar9 != 0x100) goto LAB_000fc906;
LAB_000fcc3e:
      puVar1 = param_3 + iVar12;
      if (bVar5) {
        uVar13 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
        puVar15 = (undefined4 *)FUN_001a7bca(uVar13,0x168);
        *puVar15 = uVar13;
        local_6c = puVar15 + 1;
        FUN_0010e0f6(local_6c,0xf9,*(undefined4 *)(param_1 + 8));
        puVar15[0x22] = 2;
        puVar15[0x28] = local_88;
        if ((*param_3 & 0x4000000) != 0) {
          local_68 = local_68 + param_3[iVar12 + 2];
        }
        puVar15[0x51] = local_68;
        puVar15[0x50] = 0x24;
        uVar13 = FUN_0012eb84(*(undefined4 *)(*(int *)(*(int *)(param_1 + 8) + 0x3f4) + 0x3a0),0x2c,
                              0,0);
        FUN_0010a3c2(local_6c,0,uVar13);
        iVar12 = FUN_0010b0f4(local_6c,1);
        *(int *)(iVar12 + 8) = iVar11;
        *(undefined4 *)(iVar12 + 0xc) = 0;
LAB_000fcd2b:
        uVar13 = FUN_000edadc(param_1,*(byte *)((int)puVar1 + 2) & 0x3f);
        uVar18 = *puVar1;
        iVar12 = FUN_0010b0f4(local_6c,2);
        *(uint *)(iVar12 + 8) = (uint)(ushort)uVar18;
        *(undefined4 *)(iVar12 + 0xc) = uVar13;
        if (bVar5) goto LAB_000fc916;
      }
      else {
        uVar13 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
        puVar15 = (undefined4 *)FUN_001a7bca(uVar13,0x168);
        *puVar15 = uVar13;
        local_6c = puVar15 + 1;
        FUN_0010cb26(local_6c,0xfc,*(undefined4 *)(param_1 + 8));
        uVar13 = FUN_000edadc(param_1,bVar7);
        iVar17 = FUN_0010b0f4(local_6c,0);
        *(uint *)(iVar17 + 8) = local_68;
        *(undefined4 *)(iVar17 + 0xc) = uVar13;
        uVar13 = FUN_000edadc(param_1,4);
        iVar17 = FUN_0010b0f4(local_6c,1);
        *(int *)(iVar17 + 8) = iVar11;
        *(undefined4 *)(iVar17 + 0xc) = uVar13;
        puVar15[0x28] = local_88;
        if ((*param_3 & 0x4000000) == 0) goto LAB_000fcd2b;
        iVar17 = *(int *)(*(int *)(param_1 + 8) + 0xf0) + -1;
        *(int *)(*(int *)(param_1 + 8) + 0xf0) = iVar17;
        uVar18 = param_3[iVar12 + 2];
        uVar13 = FUN_0010a17a(0xc6,*(undefined4 *)(param_1 + 8));
        uVar14 = FUN_000edadc(param_1,4);
        iVar12 = FUN_0010b0f4(uVar13,0);
        *(int *)(iVar12 + 8) = iVar17;
        *(undefined4 *)(iVar12 + 0xc) = uVar14;
        uVar14 = FUN_000edadc(param_1,*(byte *)((int)puVar1 + 2) & 0x3f);
        uVar6 = *puVar1;
        iVar12 = FUN_0010b0f4(uVar13,1);
        *(uint *)(iVar12 + 8) = (uint)(ushort)uVar6;
        *(undefined4 *)(iVar12 + 0xc) = uVar14;
        ((int (*)())FUN_000f9ef4)(uVar13,param_1,2,uVar18,uVar18,uVar18,uVar18);
        FUN_001a7cd6(param_2,uVar13);
        uVar13 = FUN_000edadc(param_1,4);
        iVar12 = FUN_0010b0f4(local_6c,2);
        *(int *)(iVar12 + 8) = iVar17;
        *(undefined4 *)(iVar12 + 0xc) = uVar13;
      }
      uVar13 = FUN_000edadc(param_1,bVar7);
      iVar12 = FUN_0010b0f4(local_6c,3);
      *(uint *)(iVar12 + 8) = local_68;
      *(undefined4 *)(iVar12 + 0xc) = uVar13;
      local_24 = DAT_001c66c0;
      ((int (*)())FUN_000fb2d4)(param_1,&local_24,puVar1,2,local_6c);
    }
    else {
      iVar12 = 2 - (uint)((*param_3 & 0x400000) == 0);
      uVar9 = *(ushort *)((int)param_3 + 2) & 0x180;
      if (uVar9 == 0x100) goto LAB_000fcc3e;
LAB_000fc906:
      if (uVar9 == 0) {
        if ((*(byte *)((int)param_3 + 3) & 4) == 0) {
          local_4c = 0;
        }
        else {
          local_4c = param_3[iVar12];
        }
        if (bVar5) {
          uVar13 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
          puVar15 = (undefined4 *)FUN_001a7bca(uVar13,0x168);
          *puVar15 = uVar13;
          local_6c = puVar15 + 1;
          FUN_0010de3c(local_6c,*(undefined4 *)(param_1 + 8));
          puVar15[0x28] = local_88;
          puVar15[0x51] = local_68;
          puVar15[0x50] = 0x24;
          uVar13 = FUN_0012eb84(*(undefined4 *)(*(int *)(*(int *)(param_1 + 8) + 0x3f4) + 0x3a0),
                                0x2c,0,0);
          FUN_0010a3c2(local_6c,0,uVar13);
          iVar12 = FUN_0010b0f4(local_6c,1);
          *(int *)(iVar12 + 8) = iVar11;
          *(undefined4 *)(iVar12 + 0xc) = 0;
        }
        else {
          uVar13 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
          puVar15 = (undefined4 *)FUN_001a7bca(uVar13,0x168);
          *puVar15 = uVar13;
          local_6c = puVar15 + 1;
          FUN_0010cb26(local_6c,0xfc,*(undefined4 *)(param_1 + 8));
          uVar13 = FUN_000edadc(param_1,bVar7);
          iVar12 = FUN_0010b0f4(local_6c,0);
          *(uint *)(iVar12 + 8) = local_68;
          *(undefined4 *)(iVar12 + 0xc) = uVar13;
          uVar13 = FUN_000edadc(param_1,4);
          iVar12 = FUN_0010b0f4(local_6c,1);
          *(int *)(iVar12 + 8) = iVar11;
          *(undefined4 *)(iVar12 + 0xc) = uVar13;
          ((int (*)())FUN_000f9ef4)(local_6c,param_1,2,local_4c,local_4c,local_4c,local_4c);
          puVar15[0x28] = local_88;
        }
      }
      else {
        local_6c = (undefined4 *)0x0;
      }
    }
LAB_000fc916:
    iVar12 = FUN_0010b0f4(local_6c,2);
    local_20[0] = *(undefined4 *)(iVar12 + 0x10);
    piVar3 = *(int **)(*(int *)(param_1 + 8) + 0x54);
    cVar8 = (**(code **)(*piVar3 + 0x104))(piVar3,local_6c,2,local_20,0);
    if (cVar8 == '\0') {
      iVar17 = *(int *)(*(int *)(param_1 + 8) + 0xf0) + -1;
      *(int *)(*(int *)(param_1 + 8) + 0xf0) = iVar17;
      uVar19 = FUN_0010a17a(0x31,*(undefined4 *)(param_1 + 8));
      uVar13 = local_6c[0x32];
      uVar14 = local_6c[0x31];
      iVar12 = FUN_0010b0f4(uVar19,1);
      *(undefined4 *)(iVar12 + 8) = uVar14;
      *(undefined4 *)(iVar12 + 0xc) = uVar13;
      uVar13 = FUN_000edadc(param_1,4);
      iVar12 = FUN_0010b0f4(uVar19,0);
      *(int *)(iVar12 + 8) = iVar17;
      *(undefined4 *)(iVar12 + 0xc) = uVar13;
      iVar12 = FUN_0010b0f4(local_6c,2);
      uVar13 = *(undefined4 *)(iVar12 + 0x10);
      iVar12 = FUN_0010b0f4(uVar19,1);
      *(undefined4 *)(iVar12 + 0x10) = uVar13;
      FUN_001a7cd6(param_2,uVar19);
      uVar13 = FUN_000edadc(param_1,4);
      iVar12 = FUN_0010b0f4(local_6c,2);
      *(int *)(iVar12 + 8) = iVar17;
      *(undefined4 *)(iVar12 + 0xc) = uVar13;
      iVar12 = FUN_0010b0f4(local_6c,2);
      *(undefined4 *)(iVar12 + 0x10) = DAT_001c66e4;
    }
    if ((!bVar5) &&
       (piVar3 = *(int **)(*(int *)(param_1 + 8) + 0x54),
       cVar8 = (**(code **)(*piVar3 + 0x104))(piVar3,local_6c,1,local_20,0), cVar8 == '\0')) {
      iVar17 = *(int *)(*(int *)(param_1 + 8) + 0xf0) + -1;
      *(int *)(*(int *)(param_1 + 8) + 0xf0) = iVar17;
      uVar19 = FUN_0010a17a(0x31,*(undefined4 *)(param_1 + 8));
      uVar13 = local_6c[0x2c];
      uVar14 = local_6c[0x2b];
      iVar12 = FUN_0010b0f4(uVar19,1);
      *(undefined4 *)(iVar12 + 8) = uVar14;
      *(undefined4 *)(iVar12 + 0xc) = uVar13;
      uVar13 = FUN_000edadc(param_1,4);
      iVar12 = FUN_0010b0f4(uVar19,0);
      *(int *)(iVar12 + 8) = iVar17;
      *(undefined4 *)(iVar12 + 0xc) = uVar13;
      iVar12 = FUN_0010b0f4(local_6c,1);
      uVar13 = *(undefined4 *)(iVar12 + 0x10);
      iVar12 = FUN_0010b0f4(uVar19,1);
      *(undefined4 *)(iVar12 + 0x10) = uVar13;
      FUN_001a7cd6(param_2,uVar19);
      uVar13 = FUN_000edadc(param_1,4);
      iVar12 = FUN_0010b0f4(local_6c,1);
      *(int *)(iVar12 + 8) = iVar17;
      *(undefined4 *)(iVar12 + 0xc) = uVar13;
      iVar12 = FUN_0010b0f4(local_6c,1);
      *(undefined4 *)(iVar12 + 0x10) = DAT_001c66c0;
    }
    FUN_001a7cd6(param_2,local_6c);
    *param_3 = *param_3 & 0xffc0ffff | 0x40000;
    *(short *)param_3 = (short)iVar11;
  }
  if ((bVar16 != 0x1f) || ((*(byte *)(param_1 + 0x32) & 0x20) == 0)) {
    return;
  }
  iVar12 = *(int *)(*(int *)(param_1 + 8) + 0xf0) + -1;
  *(int *)(*(int *)(param_1 + 8) + 0xf0) = iVar12;
  iVar17 = *(int *)(*(int *)(param_1 + 8) + 0xf0) + -1;
  *(int *)(*(int *)(param_1 + 8) + 0xf0) = iVar17;
  uVar13 = FUN_0010a17a(0xcc,*(undefined4 *)(param_1 + 8));
  iVar11 = FUN_0010b0f4(uVar13,0);
  *(int *)(iVar11 + 8) = iVar17;
  *(undefined4 *)(iVar11 + 0xc) = 0;
  iVar11 = FUN_0010b0f4(uVar13,1);
  *(undefined4 *)(iVar11 + 8) = 0;
  *(undefined4 *)(iVar11 + 0xc) = 0x1f;
  iVar11 = FUN_0010b0f4(uVar13,1);
  *(undefined4 *)(iVar11 + 0x10) = DAT_001c66c8;
  if (param_5 == 1) {
    ((int (*)())FUN_000f9ef4)(uVar13,param_1,2,1,1,1,1);
    goto LAB_000fcb0e;
  }
  if (param_5 < 2) {
    if (param_5 != 0) goto LAB_000fcb0e;
    uVar21 = 0;
    uVar20 = 0;
    uVar19 = 0;
    uVar14 = 0;
  }
  else {
    if (param_5 == 2) {
      ((int (*)())FUN_000f9ef4)(uVar13,param_1,2,2,2,2,2);
      goto LAB_000fcb0e;
    }
    if (param_5 != 3) goto LAB_000fcb0e;
    uVar21 = 3;
    uVar20 = 3;
    uVar19 = 3;
    uVar14 = 3;
  }
  ((int (*)())FUN_000f9ef4)(uVar13,param_1,2,uVar14,uVar19,uVar20,uVar21);
LAB_000fcb0e:
  FUN_001a7cd6(param_2,uVar13);
  uVar13 = FUN_0010a17a(0x24,*(undefined4 *)(param_1 + 8));
  uVar14 = FUN_000edadc(param_1,0x1f);
  iVar11 = FUN_0010b0f4(uVar13,0);
  *(int *)(iVar11 + 8) = iVar10;
  *(undefined4 *)(iVar11 + 0xc) = uVar14;
  iVar11 = FUN_0010b0f4(uVar13,1);
  *(int *)(iVar11 + 8) = iVar17;
  *(undefined4 *)(iVar11 + 0xc) = 0;
  uVar14 = FUN_000edadc(param_1,4);
  iVar11 = FUN_0010b0f4(uVar13,2);
  *(int *)(iVar11 + 8) = iVar12;
  *(undefined4 *)(iVar11 + 0xc) = uVar14;
  uVar14 = FUN_000edadc(param_1,0x1f);
  iVar11 = FUN_0010b0f4(uVar13,3);
  *(int *)(iVar11 + 8) = iVar10;
  *(undefined4 *)(iVar11 + 0xc) = uVar14;
  FUN_001a7cd6(param_2,uVar13);
  *param_3 = *param_3 & 0xffc0ffff | 0x40000;
  *(short *)param_3 = (short)iVar12;
  return;
}

/* FUN_000fd68a @ 0xfd68a (1322 bytes) */
int FUN_000fd68a(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
  int param_10;
  undefined4 param_11;
{
  uint *puVar1;
  uint uVar2;
  undefined2 *puVar3;
  short *psVar4;
  byte bVar5;
  char cVar6;
  short sVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  uint *puVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  byte bVar16;
  int local_40;
  int local_30;
  undefined4 local_24;
  undefined4 local_20 [4];
  
  uVar2 = *(uint *)(PTR_DAT_00213481 + param_2 * 4);
  if ((param_3 != 0) || ((uVar2 & 8) == 0)) {
    if ((uVar2 & 8) == 0) {
      puVar12 = *(uint **)(*(int *)(param_4 + 0x6c) + ((uVar2 >> 6 & 7) * 5 + (uVar2 & 7)) * 4);
      iVar9 = *(int *)(param_1 + 8);
      puVar1 = puVar12;
      uVar13 = local_24;
      bVar16 = *(byte *)((int)puVar12 + 2);
      bVar5 = *(byte *)((int)puVar12 + 2);
    }
    else {
      puVar3 = *(undefined2 **)(*(int *)(param_4 + 100) + ((uVar2 >> 6 & 7) * 5 + (uVar2 & 7)) * 4);
      local_24 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_24) + 2)),*puVar3);
      uVar13 = local_24 & 0xfe40ffff | (*(byte *)(puVar3 + 1) & 0x3f) << 0x10 |
               ((ushort)puVar3[1] >> 7 & 3) << 0x17;
      puVar12 = (uint *)0x0;
      puVar1 = &local_24;
      (*(unsigned char *)((unsigned char *)&(local_24) + 2)) = (byte)(uVar13 >> 0x10);
      iVar9 = *(int *)(param_1 + 8);
      bVar16 = (*(unsigned char *)((unsigned char *)&(local_24) + 2));
      bVar5 = (*(unsigned char *)((unsigned char *)&(local_24) + 2));
    }
    local_24 = uVar13;
    bVar16 = bVar16 & 0x3f;
    if ((((bVar5 & 0x3f) == 0x10) && (iVar9 != 0)) && (*(char *)(*(int *)(iVar9 + 0x54) + 8) < '\0')
       ) {
      sVar7 = 0xf;
    }
    else {
      sVar7 = (short)*puVar1;
    }
    local_40 = (int)sVar7;
    if ((bVar16 == 0x12) && ((uVar2 & 0x1c0) != 0)) {
      local_40 = 0;
      bVar16 = 0x13;
    }
    if (((uVar2 & 0x10) == 0) && ((bVar16 == 1 || (bVar16 == 0x22)))) {
      local_30 = *(int *)(iVar9 + 0xf0) + -1;
      *(int *)(iVar9 + 0xf0) = local_30;
      uVar8 = FUN_0010a17a(0x31,*(undefined4 *)(param_1 + 8));
      iVar9 = FUN_0010b0f4(uVar8,0);
      *(int *)(iVar9 + 8) = local_30;
      *(undefined4 *)(iVar9 + 0xc) = 0;
      uVar11 = FUN_000edadc(param_1,bVar16);
      iVar9 = FUN_0010b0f4(uVar8,1);
      *(int *)(iVar9 + 8) = local_40;
      *(undefined4 *)(iVar9 + 0xc) = uVar11;
      ((int (*)())FUN_000fb2d4)(param_1,param_8,puVar1,param_3,uVar8);
      ((int (*)())FUN_000fbaca)(param_1,uVar8,param_11);
      *(byte *)((int)puVar1 + 2) = *(byte *)((int)puVar1 + 2) & 0xbf;
      *puVar1 = *puVar1 & 0xfe7fffff;
      *(short *)puVar1 = (short)local_30;
      *puVar1 = *puVar1 & 0xffc0ffff | 0x40000;
      bVar16 = 4;
    }
    else {
      ((int (*)())FUN_000fb2d4)(param_1,param_8,puVar12,param_3,param_5);
      local_30 = local_40;
    }
    uVar8 = FUN_000edadc(param_1,bVar16);
    iVar9 = FUN_0010b0f4(param_5,param_3);
    *(int *)(iVar9 + 8) = local_30;
    *(undefined4 *)(iVar9 + 0xc) = uVar8;
    return 0;
  }
  psVar4 = *(short **)(*(int *)(param_4 + 100) + ((uVar2 >> 6 & 7) * 5 + (uVar2 & 7)) * 4);
  iVar14 = (int)*psVar4;
  bVar16 = *(byte *)(psVar4 + 1) & 0x3f;
  uVar8 = FUN_000edadc(param_1,bVar16);
  iVar9 = FUN_0010b0f4(param_5,0);
  *(int *)(iVar9 + 8) = iVar14;
  *(undefined4 *)(iVar9 + 0xc) = uVar8;
  ((int (*)())FUN_000fb546)(param_1,param_9,param_7,psVar4,0,param_5,param_10);
  cVar6 = FUN_00119562(*(undefined4 *)(param_1 + 8),param_5);
  if (cVar6 != '\0') {
    iVar9 = FUN_0010b0f4(param_5,0);
    local_20[0] = *(undefined4 *)(iVar9 + 0x10);
    iVar15 = 0;
    iVar9 = 0;
    iVar10 = 0;
    do {
      if (*(char *)((int)local_20 + iVar10) == '\0') {
        iVar15 = iVar15 + 1;
        iVar9 = iVar10;
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 != 4);
    if (1 < iVar15) {
      local_24 = DAT_001c66f8;
      *(undefined1 *)((int)local_20 + iVar9 + -4) = 0;
      uVar8 = *(undefined4 *)(iVar9 * 4 + 0x1ef560);
      iVar9 = FUN_0010a17a(0x31,*(undefined4 *)(param_1 + 8));
      uVar11 = FUN_000edadc(param_1,bVar16);
      iVar10 = FUN_0010b0f4(iVar9,0);
      *(int *)(iVar10 + 8) = iVar14;
      *(undefined4 *)(iVar10 + 0xc) = uVar11;
      *(undefined4 *)(iVar9 + 0x9c) = local_20[0];
      uVar11 = FUN_000edadc(param_1,bVar16);
      iVar10 = FUN_0010b0f4(iVar9,1);
      *(int *)(iVar10 + 8) = iVar14;
      *(undefined4 *)(iVar10 + 0xc) = uVar11;
      iVar10 = FUN_0010b0f4(iVar9,1);
      *(undefined4 *)(iVar10 + 0x10) = uVar8;
      *(uint *)(param_5 + 0x9c) = local_24;
      goto LAB_000fd8d3;
    }
  }
  iVar9 = 0;
LAB_000fd8d3:
  if ((uVar2 & 0x20) != 0) {
    return iVar9;
  }
  iVar10 = FUN_0010b0f4(param_5,0);
  if (*(int *)(iVar10 + 0x10) != DAT_001c66f4) {
    iVar9 = FUN_0010a17a(0x31,*(undefined4 *)(param_1 + 8));
    iVar15 = *(int *)(*(int *)(param_1 + 8) + 0xf0) + -1;
    *(int *)(*(int *)(param_1 + 8) + 0xf0) = iVar15;
    uVar8 = FUN_000edadc(param_1,bVar16);
    iVar10 = FUN_0010b0f4(iVar9,0);
    *(int *)(iVar10 + 8) = iVar14;
    *(undefined4 *)(iVar10 + 0xc) = uVar8;
    iVar14 = FUN_0010b0f4(iVar9,1);
    *(int *)(iVar14 + 8) = iVar15;
    *(undefined4 *)(iVar14 + 0xc) = 0;
    iVar14 = FUN_0010b0f4(param_5,0);
    *(int *)(iVar14 + 8) = iVar15;
    *(undefined4 *)(iVar14 + 0xc) = 0;
    iVar14 = FUN_0010b0f4(param_5,0);
    *(undefined4 *)(iVar9 + 0x9c) = *(undefined4 *)(iVar14 + 0x10);
    *(int *)(param_5 + 0x9c) = DAT_001c66f4;
    return iVar9;
  }
  return iVar9;
}

/* FUN_000fdbb4 @ 0xfdbb4 (444 bytes) */
int FUN_000fdbb4(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  uint *param_5;
  int param_6;
  undefined4 param_7;
{
  undefined4 uVar1;
  undefined1 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  undefined1 uStack_21;
  undefined4 local_20 [4];
  
  uVar1 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
  puVar3 = (undefined4 *)FUN_001a7bca(uVar1,0x150);
  *puVar3 = uVar1;
  puVar4 = puVar3 + 1;
  FUN_000ec126(puVar4,param_2,param_4,0,*(undefined4 *)(param_1 + 8));
  FUN_000e96a6(puVar4,param_3);
  local_20[0] = DAT_001c66c0;
  ((int (*)())FUN_000fd68a)(param_1,5,1,param_7,param_2,1,DAT_001c66f4,local_20,param_6,1,puVar4);
  iVar5 = FUN_0010b0f4(param_2,1);
  local_20[0] = *(undefined4 *)(iVar5 + 0x10);
  uVar2 = (undefined1)local_20[0];
  iVar5 = 1;
  do {
    *(undefined1 *)(iVar5 + -1 + (int)local_20) = uVar2;
    uVar1 = local_20[0];
    iVar5 = iVar5 + 1;
  } while (iVar5 != 5);
  iVar5 = FUN_0010b0f4(param_2,1);
  *(undefined4 *)(iVar5 + 0x10) = uVar1;
  FUN_000f0144(param_1,param_2);
  if (param_5[1] != 0) {
    *(undefined1 *)((int)puVar3 + 0x141) = 0;
  }
  uVar7 = param_5[1];
  if (uVar7 < *param_5) {
    _memset((void *)(uVar7 * 4 + param_5[2]),0,4);
    param_5[1] = uVar7 + 1;
    puVar3 = (undefined4 *)(uVar7 * 4 + param_5[2]);
  }
  else {
    puVar3 = (undefined4 *)FUN_001a7f7c(param_5,uVar7);
  }
  *puVar3 = puVar4;
  if (*(int *)(param_6 + 4) != 0) {
    uVar7 = *(int *)(param_6 + 4) - 1;
    if (uVar7 < *(uint *)(param_6 + 4)) {
      piVar6 = (int *)(*(int *)(param_6 + 8) + uVar7 * 4);
    }
    else {
      piVar6 = (int *)0x0;
    }
    *(int *)(*piVar6 + 0x124) = *(int *)(*piVar6 + 0x124) + 1;
  }
  return puVar4;
}

