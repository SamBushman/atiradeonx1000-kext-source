#include "decls.h"

/* TParseContext__boolErrorCheck @ 0x97b9ba78 (208 bytes) */
int TParseContext__boolErrorCheck(this, param_1, param_2)
  unsigned char * this;
  int param_1;
  unsigned char * param_2;
{
  int iVar1;
  
  iVar1 = (**(code **)(*(int *)param_2 + 0x40))(param_2);
  if ((((iVar1 == 3) && (iVar1 = (**(code **)(*(int *)param_2 + 0x54))(param_2), iVar1 == 0)) &&
      (iVar1 = (**(code **)(*(int *)param_2 + 0x50))(param_2), iVar1 == 0)) &&
     (iVar1 = (**(code **)(*(int *)param_2 + 0x58))(param_2), iVar1 == 0)) {
    return 0;
  }
  error((int)this,(char *)param_1,"boolean expression expected","","");
  return 1;
}

/* TParseContext__boolErrorCheck_97b9bb48 @ 0x97b9bb48 (132 bytes) */
int TParseContext__boolErrorCheck_97b9bb48(this, param_1, param_2)
  unsigned char * this;
  int param_1;
  unsigned char * param_2;
{
  undefined4 uVar1;
  
  if ((((*(int *)param_2 != 3) || (*(int *)(param_2 + 0x10) != 0)) || (*(int *)(param_2 + 0xc) != 0)
      ) || (uVar1 = 0, 1 < *(int *)(param_2 + 8))) {
    error((int)this,(char *)param_1,"boolean expression expected","","");
    uVar1 = 1;
  }
  return uVar1;
}

/* TParseContext__samplerErrorCheck @ 0x97b9bbcc (184 bytes) */
int TParseContext__samplerErrorCheck(this, param_1, param_2, param_3)
  unsigned char * this;
  int param_1;
  unsigned char * param_2;
  char *param_3;
{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  
  iVar1 = *(int *)param_2;
  if (iVar1 == 0xe) {
    iVar1 = ((int (*)())TParseContext__containsSampler)(this,*(unsigned char **)(param_2 + 0x14));
    if (iVar1 == 0) {
      return 0;
    }
    pcVar2 = (char *)TType__getBasicString(*(undefined4 *)param_2);
    pcVar3 = "(structure contains a sampler)";
  }
  else {
    if (7 < iVar1 - 5U) {
      return 0;
    }
    pcVar2 = (char *)TType__getBasicString(iVar1);
    pcVar3 = "";
  }
  error((int)this,(char *)param_1,param_3,pcVar2,pcVar3);
  return 1;
}

/* TParseContext__structQualifierErrorCheck @ 0x97b9bc84 (172 bytes) */
int TParseContext__structQualifierErrorCheck(this, param_1, param_2)
  unsigned char * this;
  int param_1;
  unsigned char * param_2;
{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_2 + 4);
  if ((iVar1 - 3U < 3) && (*(int *)param_2 == 0xe)) {
    pcVar2 = (char *)getQualifierString(iVar1);
    error((int)this,(char *)param_1,"cannot be used with a structure",pcVar2,"");
    uVar3 = 1;
  }
  else {
    if ((iVar1 != 6) &&
       (iVar1 = ((int (*)())TParseContext__samplerErrorCheck)(this,param_1,param_2,"samplers must be uniform"), iVar1 != 0)) {
      return 1;
    }
    uVar3 = 0;
  }
  return uVar3;
}

/* TParseContext__parameterSamplerErrorCheck @ 0x97b9bd30 (184 bytes) */
int TParseContext__parameterSamplerErrorCheck(this, param_1, param_3, param_4)
  unsigned char * this;
  char *param_1;
  int param_3;
  int *param_4;
{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  
  if (((param_3 - 10U < 2) && (iVar1 = (**(code **)(*param_4 + 0x20))(param_4), iVar1 != 0xe)) &&
     (iVar1 = (**(code **)(*param_4 + 0x20))(param_4), iVar1 - 5U < 8)) {
    pcVar2 = (char *)TType__getBasicString((uint)param_4[9] >> 0x13 & 0x3f);
    error((int)this,param_1,"samplers cannot be output parameters",pcVar2,"");
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}

/* TParseContext__containsSampler @ 0x97b9bde8 (180 bytes) */
int TParseContext__containsSampler(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  iVar1 = (**(code **)(*(int *)param_1 + 0x20))(param_1);
  uVar2 = 1;
  if (7 < iVar1 - 5U) {
    iVar1 = (**(code **)(*(int *)param_1 + 0x20))(param_1);
    if (iVar1 == 0xe) {
      iVar1 = *(int *)(param_1 + 8);
      for (uVar4 = 0; iVar3 = *(int *)(iVar1 + 4), uVar4 < (uint)(*(int *)(iVar1 + 8) - iVar3 >> 3);
          uVar4 = uVar4 + 1) {
        iVar3 = ((int (*)())TParseContext__containsSampler)(this,*(unsigned char **)(iVar3 + uVar4 * 8));
        if (iVar3 != 0) {
          return 1;
        }
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}

/* TParseContext__insertBuiltInArrayAtGlobalLevel @ 0x97b9be9c (740 bytes) */
int TParseContext__insertBuiltInArrayAtGlobalLevel(this)
  unsigned char * this;
{
  undefined1 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined *puVar6;
  uint uVar7;
  ulong uVar8;
  unsigned char * psVar9;
  int *piVar10;
  char *pcVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  unsigned char * psVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  int *piVar22;
  char in_RESERVE;
  byte bVar23;
  undefined4 local_80 [4];
  int local_70 [4];
  undefined4 local_60;
  int local_5c;
  undefined4 local_50;
  int local_4c;
  undefined4 local_40;
  int local_3c;
  int *local_38;
  undefined4 local_30;
  
  uVar8 = ((int (*)())GetGlobalPoolAllocator)();
  psVar9 = (unsigned char *)((int (*)())TPoolAllocator__allocate)(uVar8);
  bVar23 = (psVar9 == (unsigned char *)0x0) << 1;
  psVar18 = (unsigned char *)0x0;
  if (psVar9 != (unsigned char *)0x0) {
    local_80[0] = ((int (*)())GetGlobalPoolAllocator)();
    std__string__string(psVar9,"gl_TexCoord",(unsigned char *)local_80);
    psVar18 = psVar9;
  }
  piVar22 = *(int **)(this + 4);
  iVar16 = *piVar22;
  iVar19 = (piVar22[1] - iVar16 >> 2) + -1;
  while( true ) {
    iVar16 = *(int *)(iVar16 + iVar19 * 4);
    std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______find((unsigned char *)local_70);
    iVar20 = 0;
    if (local_70[0] != *(int *)(iVar16 + 4)) {
      iVar20 = *(int *)(local_70[0] + 0x18);
    }
    iVar19 = iVar19 + -1;
    if (iVar20 != 0) break;
    if (iVar19 < 0) {
      iVar19 = *(int *)(psVar18 + 4);
      iVar16 = *(int *)(iVar19 + -0xc);
      uVar1 = *DAT_a7b7ba18;
      pcVar11 = "INTERNAL ERROR finding symbol";
LAB_97b9c154:
      *(undefined1 *)(iVar19 + iVar16) = uVar1;
      error((int)this,(char *)0x0,pcVar11,*(char **)(psVar18 + 4),"");
      return 1;
    }
    iVar16 = *piVar22;
  }
  uVar8 = ((int (*)())GetGlobalPoolAllocator)();
  piVar10 = (int *)((int (*)())TPoolAllocator__allocate)(uVar8);
  puVar6 = PTR_vtable_a7b7c0b4;
  piVar10[1] = (int)psVar18;
  *piVar10 = (int)(puVar6 + 8);
  iVar15 = *(int *)(iVar20 + 0x18);
  iVar14 = *(int *)(iVar20 + 0x1c);
  iVar13 = *(int *)(iVar20 + 0x20);
  iVar12 = *(int *)(iVar20 + 0x24);
  iVar19 = *(int *)(iVar20 + 0x28);
  iVar16 = *(int *)(iVar20 + 0x10);
  iVar17 = *(int *)(iVar20 + 0x14);
  iVar21 = *(int *)(iVar20 + 0x2c);
  piVar10[3] = (int)&PTR__TType_a7b7d4d0;
  piVar10[6] = iVar15;
  piVar10[7] = iVar14;
  piVar10[8] = iVar13;
  piVar10[9] = iVar12;
  piVar10[10] = iVar19;
  piVar10[4] = iVar16;
  piVar10[5] = iVar17;
  piVar10[0xb] = iVar21;
  uVar7 = piVar10[0xc];
  uVar3 = *(uint *)(iVar20 + 0x30) & 0xfe000000;
  piVar10[0xc] = uVar3 | uVar7 & 0x1ffffff;
  uVar4 = (*(uint *)(iVar20 + 0x30) >> 0x13 & 0x3f) << 0x13;
  piVar10[0xc] = uVar4 | uVar3 | uVar7 & 0x7ffff;
  uVar2 = *(uint *)(iVar20 + 0x30) & 0x7f800;
  piVar10[0xc] = uVar2 | uVar4 | uVar3 | uVar7 & 0x7ff;
  uVar5 = (*(uint *)(iVar20 + 0x30) >> 10 & 1) << 10;
  piVar10[0xc] = uVar5 | uVar2 | uVar4 | uVar3 | uVar7 & 0x3ff;
  piVar10[0xc] = (*(uint *)(iVar20 + 0x30) >> 9 & 1) << 9 |
                 uVar5 | uVar2 | uVar4 | uVar3 | uVar7 & 0x1ff;
  piVar10[0xd] = 0;
  piVar10[0xe] = 0;
  piVar10[0xf] = 0;
  iVar16 = *(int *)(*(int *)(this + 4) + 0xc) + 1;
  *(int *)(*(int *)(this + 4) + 0xc) = iVar16;
  piVar10[2] = iVar16;
  local_5c = 0;
  psVar9 = (unsigned char *)(**(code **)(*piVar10 + 8))();
  std__string__string((unsigned char *)&local_40,psVar9);
  local_38 = piVar10;
  std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&local_50);
  local_60 = local_50;
  piVar22 = (int *)(local_3c + -4);
  local_5c = local_4c;
  local_30 = local_40;
  do {
    iVar16 = *piVar22;
    if (in_RESERVE != '\0') {
      iVar19 = storeWordConditionalIndexed(iVar16 + -1,0,piVar22);
      *piVar22 = iVar19;
      bVar23 = 2;
    }
  } while (!(bool)(bVar23 >> 1 & 1));
  if (iVar16 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(local_3c + -0xc));
  }
  if (local_5c != 0) {
    return 0;
  }
  (**(code **)(*piVar10 + 4))(piVar10);
  iVar19 = *(int *)(psVar18 + 4);
  iVar16 = *(int *)(iVar19 + -0xc);
  uVar1 = *DAT_a7b7ba18;
  pcVar11 = "INTERNAL ERROR inserting new symbol";
  goto LAB_97b9c154;
}

/* TParseContext__arrayErrorCheck @ 0x97b9c180 (2552 bytes) */
int TParseContext__arrayErrorCheck(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  unsigned char * param_1;
  char *param_2;
  unsigned char * param_3;
  uint param_4;
  uint param_5;
  uint param_6;
  uint param_7;
  uint param_8;
{
  bool bVar1;
  uint uVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  ulong uVar10;
  unsigned char * psVar11;
  unsigned char * psVar12;
  char cVar13;
  int iVar14;
  char *pcVar15;
  int *piVar16;
  int *piVar17;
  char in_RESERVE;
  byte in_cr0;
  byte bVar18;
  uint uStack00000024;
  uint uStack00000028;
  uint uStack0000002c;
  uint uStack00000030;
  uint uStack00000034;
  int *in_stack_00000038;
  undefined4 in_stack_0000003c;
  int *in_stack_00000040;
  unsigned char * local_130;
  char *local_12c;
  int local_128;
  char *local_124;
  unsigned char * local_120;
  char *local_11c;
  char *local_118;
  char *local_114;
  unsigned char * local_110;
  uint local_10c;
  undefined4 local_108;
  undefined4 local_104;
  uint local_100;
  uint local_fc;
  uint local_f8;
  uint local_f4;
  uint local_f0;
  int *local_ec;
  uint local_e8;
  uint local_e4;
  uint local_e0;
  int *local_dc;
  uint local_d8;
  uint local_d4;
  uint local_d0;
  int *local_cc;
  uint local_c8;
  uint local_c4;
  uint local_c0;
  int *local_bc;
  undefined4 local_b8;
  undefined4 local_b0 [4];
  unsigned char * local_a0;
  int local_90 [4];
  undefined4 local_80 [4];
  undefined4 local_70;
  int local_6c;
  int *local_68;
  undefined4 local_60;
  undefined4 local_50 [4];
  uint local_40;
  uint local_3c;
  
  uStack00000024 = param_4;
  uStack00000028 = param_5;
  uStack0000002c = param_6;
  uStack00000030 = param_7;
  if (((param_8 == 0) && (param_5 != 3)) && (param_5 != 2)) {
    bVar1 = in_stack_00000040 == (int *)0x0;
    uStack00000034 = 1;
    piVar7 = (int *)0x0;
    if ((bVar1) ||
       (((piVar7 = (int *)(**(code **)(*in_stack_00000040 + 0x18))(), piVar7 != (int *)0x0 &&
         (iVar9 = (**(code **)(*piVar7 + 0x40))(), iVar9 == 2)) && (0 < *(int *)piVar7[0xc])))) {
      piVar17 = *(int **)(param_1 + 4);
      local_3c = 0;
      local_40 = 0;
      iVar14 = *piVar17;
      iVar9 = (piVar17[1] - iVar14 >> 2) + -1;
      while( true ) {
        iVar14 = *(int *)(iVar14 + iVar9 * 4);
        std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______find((unsigned char *)local_90);
        piVar16 = (int *)0x0;
        if (local_90[0] != *(int *)(iVar14 + 4)) {
          piVar16 = *(int **)(local_90[0] + 0x18);
        }
        if ((piVar16 != (int *)0x0) || (iVar9 + -1 < 0)) break;
        iVar14 = *piVar17;
        iVar9 = iVar9 + -1;
      }
      if (&STACKARG(0x0) != (undefined1 *)0x40) {
        local_40 = (uint)(iVar9 == 0);
      }
      if (&STACKARG(0x0) != (undefined1 *)0x3c) {
        local_3c = (uint)(iVar9 == (piVar17[1] - *piVar17 >> 2) + -1);
      }
      if ((piVar16 == (int *)0x0) || (local_3c == 0)) {
        local_12c = (char *)TParseContext__reservedErrorCheck(param_1,(int)param_2,param_3);
        bVar18 = (local_12c == (char *)0x0) << 1;
        if (local_12c != (char *)0x0) {
          return 1;
        }
        uVar10 = ((int (*)())GetGlobalPoolAllocator)();
        piVar17 = (int *)((int (*)())TPoolAllocator__allocate)(uVar10);
        local_10c = (uStack00000034 & 1) << 9 |
                    (uStack00000030 & 1) << 10 |
                    (uStack0000002c & 0xff) << 0xb |
                    (uStack00000024 & 0x3f) << 0x13 | uStack00000028 << 0x19 | local_10c & 0x1ff;
        local_c8 = in_stack_0000003c;
        local_130 = (unsigned char *)&PTR__TType_a7b7d4d0;
        local_100 = uStack00000024;
        local_fc = uStack00000028;
        local_f8 = uStack0000002c;
        local_f4 = uStack00000030;
        local_f0 = uStack00000034;
        local_ec = in_stack_00000038;
        local_e8 = in_stack_0000003c;
        local_e0 = uStack00000024;
        local_dc = (int *)uStack00000028;
        local_d8 = uStack0000002c;
        local_d4 = uStack00000030;
        local_d0 = uStack00000034;
        local_cc = in_stack_00000038;
        local_128 = 0;
        local_118 = (char *)0x0;
        local_124 = local_12c;
        psVar12 = (unsigned char *)0x0;
        local_11c = local_12c;
        local_114 = local_12c;
        local_110 = (unsigned char *)local_12c;
        if (in_stack_00000038 != (int *)0x0) {
          local_128 = in_stack_00000038[2];
          local_120 = (unsigned char *)local_12c;
          local_118 = local_12c;
          local_118 = (char *)TType__setStructSize((unsigned char *)&local_130);
          iVar9 = (**(code **)(*local_cc + 0x18))(local_cc);
          *(char *)(*(int *)(iVar9 + 4) + *(int *)(*(int *)(iVar9 + 4) + -0xc)) = *DAT_a7b7ba18;
          pcVar15 = *(char **)(iVar9 + 4);
          uVar10 = ((int (*)())GetGlobalPoolAllocator)();
          psVar11 = (unsigned char *)((int (*)())TPoolAllocator__allocate)(uVar10);
          bVar18 = (psVar11 == (unsigned char *)0x0) << 1;
          psVar12 = (unsigned char *)0x0;
          if (psVar11 != (unsigned char *)0x0) {
            local_80[0] = ((int (*)())GetGlobalPoolAllocator)();
            std__string__string(psVar11,pcVar15,(unsigned char *)local_80);
            psVar12 = psVar11;
          }
        }
        local_120 = psVar12;
        piVar17[1] = (int)param_3;
        *piVar17 = (int)(PTR_vtable_a7b7c0b4 + 8);
        piVar17[4] = (int)local_12c;
        piVar17[5] = local_128;
        piVar17[6] = (int)local_124;
        piVar17[7] = (int)local_120;
        piVar17[8] = (int)local_11c;
        piVar17[9] = (int)local_118;
        piVar17[3] = (int)&PTR__TType_a7b7d4d0;
        piVar17[10] = (int)local_114;
        piVar17[0xb] = (int)local_110;
        uVar8 = piVar17[0xc];
        uVar4 = local_10c & 0xfe000000;
        piVar17[0xc] = uVar4 | uVar8 & 0x1ffffff;
        uVar5 = (local_10c >> 0x13 & 0x3f) << 0x13;
        piVar17[0xc] = uVar5 | uVar4 | uVar8 & 0x7ffff;
        uVar2 = local_10c & 0x7f800;
        piVar17[0xc] = uVar2 | uVar5 | uVar4 | uVar8 & 0x7ff;
        uVar6 = (local_10c >> 10 & 1) << 10;
        piVar17[0xc] = uVar6 | uVar2 | uVar5 | uVar4 | uVar8 & 0x3ff;
        piVar17[0xc] = (local_10c >> 9 & 1) << 9 | uVar6 | uVar2 | uVar5 | uVar4 | uVar8 & 0x1ff;
        piVar17[0xd] = 0;
        piVar17[0xe] = 0;
        piVar17[0xf] = 0;
        local_130 = (unsigned char *)&PTR__TType_a7b7d4d0;
        if (!bVar1) {
          piVar17[4] = *(int *)piVar7[0xc];
          piVar17[0xc] = piVar17[0xc] | 0x200;
        }
        iVar9 = *(int *)(*(int *)(param_1 + 4) + 0xc) + 1;
        *(int *)(*(int *)(param_1 + 4) + 0xc) = iVar9;
        piVar17[2] = iVar9;
        local_12c = (char *)0x0;
        psVar12 = (unsigned char *)(**(code **)(*piVar17 + 8))(piVar17);
        std__string__string((unsigned char *)&local_70,psVar12);
        local_68 = piVar17;
        std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&local_120);
        local_130 = local_120;
        piVar7 = (int *)(local_6c + -4);
        local_12c = local_11c;
        local_60 = local_70;
        do {
          iVar9 = *piVar7;
          if (in_RESERVE != '\0') {
            iVar14 = storeWordConditionalIndexed(iVar9 + -1,0,piVar7);
            *piVar7 = iVar14;
            bVar18 = 2;
          }
        } while (!(bool)(bVar18 >> 1 & 1));
        if (iVar9 < 1) {
          std__string___Rep___M_destroy((unsigned char *)(local_6c + -0xc));
        }
        if (local_12c != (char *)0x0) {
LAB_97b9caf4:
          iVar9 = TParseContext__voidErrorCheck(param_1,(int)param_2,param_3,(unsigned char *)&STACKARG(0x24));
          if (iVar9 != 0) {
            return 1;
          }
          return 0;
        }
        if (piVar17 != (int *)0x0) {
          (**(code **)(*piVar17 + 4))(piVar17);
        }
        iVar14 = *(int *)(param_3 + 4);
        iVar9 = *(int *)(iVar14 + -0xc);
        cVar13 = *DAT_a7b7ba18;
        pcVar15 = "INTERNAL ERROR inserting new symbol";
      }
      else {
        iVar9 = (**(code **)(*piVar16 + 0x10))(piVar16);
        if (iVar9 == 0) {
          iVar14 = *(int *)(param_3 + 4);
          iVar9 = *(int *)(iVar14 + -0xc);
          cVar13 = *DAT_a7b7ba18;
          pcVar15 = "variable expected";
        }
        else {
          iVar9 = (**(code **)(piVar16[3] + 0x38))(piVar16 + 3);
          if (iVar9 == 0) {
            iVar14 = *(int *)(param_3 + 4);
            iVar9 = *(int *)(iVar14 + -0xc);
            cVar13 = *DAT_a7b7ba18;
            pcVar15 = "redeclaring non-array as array";
          }
          else if (piVar16[4] < 1) {
            local_10c = (uStack00000034 & 1) << 9 |
                        (uStack00000030 & 1) << 10 |
                        (uStack0000002c & 0xff) << 0xb |
                        (uStack00000024 & 0x3f) << 0x13 | uStack00000028 << 0x19 | local_10c & 0x1ff
            ;
            local_c8 = in_stack_0000003c;
            local_130 = (unsigned char *)&PTR__TType_a7b7d4d0;
            local_110 = (unsigned char *)0x0;
            local_100 = uStack00000024;
            local_fc = uStack00000028;
            local_f8 = uStack0000002c;
            local_f4 = uStack00000030;
            local_f0 = uStack00000034;
            local_ec = in_stack_00000038;
            local_e8 = in_stack_0000003c;
            local_e0 = uStack00000024;
            local_dc = (int *)uStack00000028;
            local_d8 = uStack0000002c;
            local_d4 = uStack00000030;
            local_d0 = uStack00000034;
            local_cc = in_stack_00000038;
            local_12c = (char *)0x0;
            local_128 = 0;
            local_124 = (char *)0x0;
            local_120 = (unsigned char *)0x0;
            local_11c = (char *)0x0;
            local_118 = (char *)0x0;
            local_114 = (char *)0x0;
            psVar12 = local_120;
            if (in_stack_00000038 != (int *)0x0) {
              local_128 = in_stack_00000038[2];
              local_118 = (char *)TType__setStructSize((unsigned char *)&local_130);
              iVar9 = (**(code **)(*local_cc + 0x18))(local_cc);
              *(char *)(*(int *)(iVar9 + 4) + *(int *)(*(int *)(iVar9 + 4) + -0xc)) = *DAT_a7b7ba18;
              pcVar15 = *(char **)(iVar9 + 4);
              uVar10 = ((int (*)())GetGlobalPoolAllocator)();
              psVar11 = (unsigned char *)((int (*)())TPoolAllocator__allocate)(uVar10);
              psVar12 = (unsigned char *)0x0;
              if (psVar11 != (unsigned char *)0x0) {
                local_50[0] = ((int (*)())GetGlobalPoolAllocator)();
                std__string__string(psVar11,pcVar15,(unsigned char *)local_50);
                psVar12 = psVar11;
              }
            }
            local_120 = psVar12;
            bVar3 = false;
            if (((piVar16[0xc] & 0x1fffe00U) == (local_10c & 0x1fffe00)) &&
               (piVar16[5] == local_128)) {
              bVar3 = true;
            }
            local_130 = (unsigned char *)&PTR__TType_a7b7d4d0;
            if (bVar3) {
              for (iVar9 = piVar16[0xf]; iVar9 != 0; iVar9 = *(int *)(iVar9 + 0x20)) {
                if (*(int *)piVar7[0xc] < *(int *)(iVar9 + 0x1c)) {
                  iVar14 = *(int *)(param_3 + 4);
                  iVar9 = *(int *)(iVar14 + -0xc);
                  cVar13 = *DAT_a7b7ba18;
                  pcVar15 = "higher index value already used for the array";
                  goto LAB_97b9cb40;
                }
                *(int *)(iVar9 + 4) = *(int *)piVar7[0xc];
                *(uint *)(iVar9 + 0x24) = *(uint *)(iVar9 + 0x24) | 0x200;
              }
              if (!bVar1) {
                piVar16[4] = *(int *)piVar7[0xc];
                piVar16[0xc] = piVar16[0xc] | 0x200;
              }
              goto LAB_97b9caf4;
            }
            iVar14 = *(int *)(param_3 + 4);
            iVar9 = *(int *)(iVar14 + -0xc);
            cVar13 = *DAT_a7b7ba18;
            pcVar15 = "redeclaration of array with a different type";
          }
          else {
            iVar14 = *(int *)(param_3 + 4);
            iVar9 = *(int *)(iVar14 + -0xc);
            cVar13 = *DAT_a7b7ba18;
            pcVar15 = "redeclaration of array with size";
          }
        }
      }
    }
    else {
      iVar14 = *(int *)(param_3 + 4);
      iVar9 = *(int *)(iVar14 + -0xc);
      cVar13 = *DAT_a7b7ba18;
      pcVar15 = "array size must be a positive integer";
    }
LAB_97b9cb40:
    *(char *)(iVar14 + iVar9) = cVar13;
    error((int)param_1,param_2,pcVar15,*(char **)(param_3 + 4),"");
  }
  else {
    local_fc = (param_8 & 1) << 9 |
               (param_7 & 1) << 10 |
               (param_6 & 0xff) << 0xb |
               (param_4 & 0x3f) << 0x13 | param_5 << 0x19 | local_fc & 0x1ff;
    local_b8 = in_stack_0000003c;
    local_120 = (unsigned char *)&PTR__TType_a7b7d4d0;
    local_110 = (unsigned char *)0x0;
    local_100 = 0;
    local_dc = in_stack_00000038;
    local_d8 = in_stack_0000003c;
    local_bc = in_stack_00000038;
    local_11c = (char *)0x0;
    local_118 = (char *)0x0;
    local_114 = (char *)0x0;
    local_10c = 0;
    local_108 = 0;
    local_104 = 0;
    uStack00000034 = param_8;
    psVar12 = local_110;
    local_f0 = param_4;
    local_ec = (int *)param_5;
    local_e8 = param_6;
    local_e4 = param_7;
    local_e0 = param_8;
    local_d0 = param_4;
    local_cc = (int *)param_5;
    local_c8 = param_6;
    local_c4 = param_7;
    local_c0 = param_8;
    if (in_stack_00000038 != (int *)0x0) {
      local_118 = (char *)in_stack_00000038[2];
      local_108 = TType__setStructSize((unsigned char *)&local_120);
      iVar9 = (**(code **)(*local_bc + 0x18))(local_bc);
      *(char *)(*(int *)(iVar9 + 4) + *(int *)(*(int *)(iVar9 + 4) + -0xc)) = *DAT_a7b7ba18;
      pcVar15 = *(char **)(iVar9 + 4);
      uVar10 = ((int (*)())GetGlobalPoolAllocator)();
      psVar11 = (unsigned char *)((int (*)())TPoolAllocator__allocate)(uVar10);
      in_cr0 = (psVar11 == (unsigned char *)0x0) << 1;
      psVar12 = (unsigned char *)0x0;
      if (psVar11 != (unsigned char *)0x0) {
        local_b0[0] = ((int (*)())GetGlobalPoolAllocator)();
        std__string__string(psVar11,pcVar15,(unsigned char *)local_b0);
        psVar12 = psVar11;
      }
    }
    local_110 = psVar12;
    TType__getCompleteString();
    local_12c[*(int *)(local_12c + -0xc)] = *DAT_a7b7ba18;
    error((int)param_1,param_2,"cannot declare arrays of this type",local_12c,"");
    piVar7 = (int *)(local_12c + -4);
    local_a0 = local_130;
    do {
      iVar9 = *piVar7;
      if (in_RESERVE != '\0') {
        iVar14 = storeWordConditionalIndexed(iVar9 + -1,0,piVar7);
        *piVar7 = iVar14;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar9 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_12c + -0xc));
    }
  }
  return 1;
}

/* TParseContext__arraySetMaxSize @ 0x97b9cb78 (848 bytes) */
int TParseContext__arraySetMaxSize(this, param_1, param_2, param_3, param_4, param_5)
  unsigned char * this;
  unsigned char * param_1;
  unsigned char * param_2;
  int param_3;
  int param_4;
  int param_5;
{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  ulong uVar4;
  undefined3 in_register_0000001c;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  char in_RESERVE;
  byte in_cr0;
  byte bVar9;
  int local_e0 [4];
  int local_d0;
  int local_cc;
  undefined4 local_c0 [4];
  int local_b0;
  char acStack_a0 [64];
  unsigned char aaStack_60 [16];
  uint local_50;
  
  local_50 = 0;
  piVar6 = *(int **)(this + 4);
  (**(code **)(*(int *)param_1 + 0x60))(param_1);
  iVar5 = *piVar6;
  iVar2 = (piVar6[1] - iVar5 >> 2) + -1;
  while( true ) {
    iVar7 = *(int *)(iVar5 + iVar2 * 4);
    iVar5 = 0;
    std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______find((unsigned char *)local_e0);
    if (local_e0[0] != *(int *)(iVar7 + 4)) {
      iVar5 = *(int *)(local_e0[0] + 0x18);
    }
    if ((iVar5 != 0) || (iVar2 + -1 < 0)) break;
    iVar5 = *piVar6;
    iVar2 = iVar2 + -1;
  }
  if (&STACKARG(0x0) != (undefined1 *)0x50) {
    local_50 = (uint)(iVar2 == 0);
  }
  if (iVar5 != 0) {
    *(undefined4 *)(param_2 + 0x20) = *(undefined4 *)(iVar5 + 0x3c);
    *(unsigned char **)(iVar5 + 0x3c) = param_2;
    pcVar3 = (char *)(**(code **)(*(int *)param_1 + 0x60))(param_1);
    iVar2 = std__string__compare(pcVar3);
    if (iVar2 != 0) {
LAB_97b9cf8c:
      if (CONCAT31(in_register_0000001c,param_4) == 0) {
        return 0;
      }
      iVar2 = *(int *)(param_2 + 0x20);
      iVar7 = param_3 + 1;
      *(int *)(iVar5 + 0x28) = iVar7;
      *(int *)(param_2 + 0x1c) = iVar7;
      while (iVar2 != 0) {
        *(int *)(iVar2 + 0x1c) = iVar7;
        iVar2 = *(int *)(iVar2 + 0x20);
      }
      return 0;
    }
    piVar6 = *(int **)(this + 4);
    local_c0[0] = ((int (*)())GetGlobalPoolAllocator)();
    std__string__string((unsigned char *)&local_d0,"gl_MaxTextureCoords",(unsigned char *)local_c0);
    iVar7 = *piVar6;
    iVar2 = (piVar6[1] - iVar7 >> 2) + -1;
    while( true ) {
      iVar8 = *(int *)(iVar7 + iVar2 * 4);
      iVar7 = 0;
      std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______find((unsigned char *)local_e0);
      if (local_e0[0] != *(int *)(iVar8 + 4)) {
        iVar7 = *(int *)(local_e0[0] + 0x18);
      }
      if ((iVar7 != 0) || (iVar2 + -1 < 0)) break;
      iVar7 = *piVar6;
      iVar2 = iVar2 + -1;
    }
    if (&STACKARG(0x0) != (undefined1 *)0x50) {
      local_50 = (uint)(iVar2 == 0);
    }
    piVar6 = (int *)(local_cc + -4);
    local_b0 = local_d0;
    do {
      iVar2 = *piVar6;
      if (in_RESERVE != '\0') {
        iVar8 = storeWordConditionalIndexed(iVar2 + -1,0,piVar6);
        *piVar6 = iVar8;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar2 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_cc + -0xc));
    }
    if (iVar7 != 0) {
      piVar6 = *(int **)(iVar7 + 0x38);
      if (piVar6 == (int *)0x0) {
        uVar4 = ((int (*)())GetGlobalPoolAllocator)();
        piVar6 = (int *)((int (*)())TPoolAllocator__allocate)(uVar4);
        *(int **)(iVar7 + 0x38) = piVar6;
      }
      if (param_3 < *piVar6) goto LAB_97b9cf8c;
      error((int)this,(char *)param_5,"","[",
            "gl_TexCoord can only have a max array size of up to gl_MaxTextureCoords","");
    }
    else {
      pcVar3 = *(char **)(this + 8);
                    
      TInfoSinkBase__append(pcVar3);
      bVar1 = (param_5 & 0xffffU) == 0;
      bVar9 = bVar1 << 1;
      if (bVar1) {
        _sprintf(acStack_a0,"%d:? ",param_5 >> 0x10);
      }
      else {
        _sprintf(acStack_a0,"%d:%d",param_5 >> 0x10);
      }
      std__string__string((unsigned char *)&local_d0,acStack_a0,aaStack_60);
      *(undefined *)(local_d0 + *(int *)(local_d0 + -0xc)) = *PTR__S_terminal_a7b7c0b8;
      TInfoSinkBase__append(pcVar3);
      piVar6 = (int *)(local_d0 + -4);
      do {
        iVar2 = *piVar6;
        if (in_RESERVE != '\0') {
          iVar5 = storeWordConditionalIndexed(iVar2 + -1,0,piVar6);
          *piVar6 = iVar5;
          bVar9 = 2;
        }
      } while (!(bool)(bVar9 >> 1 & 1));
      if (iVar2 < 1) {
        std__string___Rep___M_destroy((unsigned char *)(local_d0 + -0xc));
      }
      TInfoSinkBase__append(pcVar3);
      TInfoSinkBase__append(pcVar3);
      TInfoSinkBase__append(pcVar3);
    }
  }
  else {
    iVar2 = (**(code **)(*(int *)param_1 + 0x60))(param_1);
    *(undefined1 *)(*(int *)(iVar2 + 4) + *(int *)(*(int *)(iVar2 + 4) + -0xc)) = *DAT_a7b7ba18;
    error((int)this,(char *)param_5," undeclared identifier",*(char **)(iVar2 + 4),"");
  }
  return 1;
}

/* TParseContext__nonInitErrorCheck @ 0x97b9cfe8 (1008 bytes) */
int TParseContext__nonInitErrorCheck(this, param_1, param_2, param_3)
  unsigned char * this;
  int param_1;
  unsigned char * param_2;
  unsigned char * param_3;
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  ulong uVar9;
  int *piVar10;
  int iVar11;
  unsigned char * this_00;
  unsigned char * psVar12;
  char *pcVar13;
  char in_RESERVE;
  byte in_cr0;
  unsigned char * local_d0;
  int local_cc;
  int local_c8;
  int local_c4;
  unsigned char * local_c0;
  int local_bc;
  int local_b8;
  int local_b4;
  int local_b0;
  uint local_ac;
  uint local_a0;
  int local_9c;
  uint local_98;
  uint local_94;
  uint local_90;
  int *local_8c;
  undefined4 local_88;
  uint local_80;
  int local_7c;
  uint local_78;
  uint local_74;
  uint local_70;
  int *local_6c;
  undefined4 local_68;
  undefined4 local_60 [4];
  undefined4 local_50;
  int local_4c;
  int *local_48;
  undefined4 local_40;
  
  iVar8 = TParseContext__reservedErrorCheck(this,param_1,param_2);
  if (iVar8 != 0) {
    TParseContext__recover(this);
  }
  iVar8 = *(int *)(param_3 + 4);
  if (iVar8 == 2) {
    *(undefined4 *)(param_3 + 4) = 0;
  }
  uVar9 = ((int (*)())GetGlobalPoolAllocator)();
  piVar10 = (int *)((int (*)())TPoolAllocator__allocate)(uVar9);
  local_8c = *(int **)(param_3 + 0x14);
  local_9c = *(int *)(param_3 + 4);
  local_a0 = *(uint *)param_3;
  local_98 = *(uint *)(param_3 + 8);
  local_94 = *(uint *)(param_3 + 0xc);
  local_90 = *(uint *)(param_3 + 0x10);
  local_88 = *(undefined4 *)(param_3 + 0x18);
  local_ac = (local_90 & 1) << 9 |
             (local_94 & 1) << 10 |
             (local_98 & 0xff) << 0xb |
             (local_a0 & 0x3f) << 0x13 | local_9c << 0x19 | local_ac & 0x1ff;
  local_d0 = (unsigned char *)&PTR__TType_a7b7d4d0;
  local_b0 = 0;
  local_cc = 0;
  local_c8 = 0;
  local_c4 = 0;
  local_c0 = (unsigned char *)0x0;
  local_bc = 0;
  local_b8 = 0;
  local_b4 = 0;
  psVar12 = local_c0;
  local_80 = local_a0;
  local_7c = local_9c;
  local_78 = local_98;
  local_74 = local_94;
  local_70 = local_90;
  local_6c = local_8c;
  local_68 = local_88;
  if (local_8c != (int *)0x0) {
    local_c8 = local_8c[2];
    local_b8 = TType__setStructSize((unsigned char *)&local_d0);
    iVar11 = (**(code **)(*local_6c + 0x18))(local_6c);
    *(undefined1 *)(*(int *)(iVar11 + 4) + *(int *)(*(int *)(iVar11 + 4) + -0xc)) = *DAT_a7b7ba18;
    pcVar13 = *(char **)(iVar11 + 4);
    uVar9 = ((int (*)())GetGlobalPoolAllocator)();
    this_00 = (unsigned char *)((int (*)())TPoolAllocator__allocate)(uVar9);
    in_cr0 = (this_00 == (unsigned char *)0x0) << 1;
    psVar12 = (unsigned char *)0x0;
    if (this_00 != (unsigned char *)0x0) {
      local_60[0] = ((int (*)())GetGlobalPoolAllocator)();
      std__string__string(this_00,pcVar13,(unsigned char *)local_60);
      psVar12 = this_00;
    }
  }
  local_c0 = psVar12;
  piVar10[1] = (int)param_2;
  *piVar10 = (int)(PTR_vtable_a7b7c0b4 + 8);
  piVar10[4] = local_cc;
  piVar10[5] = local_c8;
  piVar10[6] = local_c4;
  piVar10[7] = (int)local_c0;
  piVar10[8] = local_bc;
  piVar10[9] = local_b8;
  piVar10[3] = (int)&PTR__TType_a7b7d4d0;
  piVar10[10] = local_b4;
  piVar10[0xb] = local_b0;
  uVar6 = piVar10[0xc];
  uVar3 = local_ac & 0xfe000000;
  piVar10[0xc] = uVar3 | uVar6 & 0x1ffffff;
  uVar4 = (local_ac >> 0x13 & 0x3f) << 0x13;
  piVar10[0xc] = uVar4 | uVar3 | uVar6 & 0x7ffff;
  uVar2 = local_ac & 0x7f800;
  piVar10[0xc] = uVar2 | uVar4 | uVar3 | uVar6 & 0x7ff;
  uVar5 = (local_ac >> 10 & 1) << 10;
  piVar10[0xc] = uVar5 | uVar2 | uVar4 | uVar3 | uVar6 & 0x3ff;
  piVar10[0xc] = (local_ac >> 9 & 1) << 9 | uVar5 | uVar2 | uVar4 | uVar3 | uVar6 & 0x1ff;
  piVar10[0xd] = 0;
  piVar10[0xe] = 0;
  piVar10[0xf] = 0;
  local_d0 = (unsigned char *)&PTR__TType_a7b7d4d0;
  iVar11 = *(int *)(*(int *)(this + 4) + 0xc) + 1;
  *(int *)(*(int *)(this + 4) + 0xc) = iVar11;
  piVar10[2] = iVar11;
  local_cc = 0;
  psVar12 = (unsigned char *)(**(code **)(*piVar10 + 8))(piVar10);
  std__string__string((unsigned char *)&local_50,psVar12);
  local_48 = piVar10;
  std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&local_c0);
  local_d0 = local_c0;
  piVar7 = (int *)(local_4c + -4);
  local_cc = local_bc;
  local_40 = local_50;
  do {
    iVar11 = *piVar7;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar11 + -1,0,piVar7);
      *piVar7 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar11 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(local_4c + -0xc));
  }
  if (local_cc == 0) {
    iVar8 = piVar10[1];
    iVar11 = *(int *)(iVar8 + 4);
    *(undefined1 *)(iVar11 + *(int *)(iVar11 + -0xc)) = *DAT_a7b7ba18;
    error((int)this,(char *)param_1,"redefinition",*(char **)(iVar8 + 4),"");
    if (piVar10 != (int *)0x0) {
      (**(code **)(*piVar10 + 4))(piVar10);
    }
  }
  else {
    if (iVar8 != 2) {
      iVar8 = TParseContext__voidErrorCheck(this,param_1,param_2,param_3);
      return iVar8 != 0;
    }
    *(undefined1 *)(*(int *)(param_2 + 4) + *(int *)(*(int *)(param_2 + 4) + -0xc)) = *DAT_a7b7ba18;
    error((int)this,(char *)param_1,"variables with qualifier \'const\' must be initialized",
          *(char **)(param_2 + 4),"");
  }
  return true;
}

/* TParseContext__paramErrorCheck @ 0x97b9d3d8 (216 bytes) */
int TParseContext__paramErrorCheck(this, param_1, param_3, param_4, param_5)
  unsigned char * this;
  char *param_1;
  int param_3;
  int param_4;
  int *param_5;
{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  
  if (param_3 == 2) {
    if (param_4 == 9) {
      iVar1 = *param_5;
      param_4 = 0xc;
      goto LAB_97b9d48c;
    }
    pcVar2 = (char *)getQualifierString(2);
    pcVar4 = (char *)getQualifierString(param_4);
    pcVar3 = "qualifier not allowed with ";
  }
  else {
    if (param_3 == 0) {
      iVar1 = *param_5;
LAB_97b9d48c:
      (**(code **)(iVar1 + 0x28))(param_5,param_4);
      return 0;
    }
    pcVar2 = (char *)getQualifierString(param_3);
    pcVar3 = "qualifier not allowed on function parameter";
    pcVar4 = "";
  }
  error((int)this,param_1,pcVar3,pcVar2,pcVar4);
  return 1;
}

/* TParseContext__extensionErrorCheck @ 0x97b9d4b0 (920 bytes) */
int TParseContext__extensionErrorCheck(this, param_1, param_2)
  unsigned char * this;
  int param_1;
  char *param_2;
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint *puVar5;
  char *pcVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  char in_RESERVE;
  byte in_cr0;
  byte bVar10;
  undefined4 local_1d0;
  void *local_1cc;
  int local_1c0 [4];
  int local_1b0;
  int local_1ac;
  int local_1a0;
  int iStack_19c;
  int local_190 [4];
  int local_180 [4];
  undefined4 local_170;
  int local_16c;
  undefined4 local_168;
  int local_160 [4];
  undefined4 local_150;
  undefined4 local_140;
  undefined4 uStack_130;
  int iStack_12c;
  undefined4 local_120 [4];
  int aiStack_110 [4];
  char acStack_100 [64];
  unsigned char aaStack_c0 [16];
  int iStack_b0;
  int iStack_a0;
  undefined4 uStack_90;
  undefined4 local_80 [4];
  undefined4 local_70;
  int local_6c;
  undefined4 local_68;
  undefined4 local_60;
  undefined4 local_50;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  
  local_1c0[0] = ((int (*)())GetGlobalPoolAllocator)();
  std__string__string((unsigned char *)&local_1d0,param_2,(unsigned char *)local_1c0);
  std___Rb_tree_std__string_std__pair_std__string_const_TBehavior__std___Select1st_std__pair_std__string_const_TBehavior___std__less_std__string__pool_allocator_std__pair_std__string_const_TBehavior_____lower_bound((unsigned char *)&local_1b0);
  iVar8 = local_1b0;
  local_1a0 = *(int *)(this + 0x34);
  if (local_1b0 == local_1a0) {
LAB_97b9d574:
    local_180[0] = iVar8;
    std__string__string((unsigned char *)&local_170,(unsigned char *)&local_1d0);
    local_168 = 0;
    local_160[0] = local_180[0];
    std___Rb_tree_std__string_std__pair_std__string_const_TBehavior__std___Select1st_std__pair_std__string_const_TBehavior___std__less_std__string__pool_allocator_std__pair_std__string_const_TBehavior_____insert_unique(local_190,this + 0x30,local_160,(unsigned char *)&local_170);
    piVar3 = (int *)(local_16c + -4);
    local_1b0 = local_190[0];
    local_150 = local_170;
    do {
      iVar4 = *piVar3;
      if (in_RESERVE != '\0') {
        iVar8 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
        *piVar3 = iVar8;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    iVar8 = local_190[0];
    if (iVar4 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_16c + -0xc));
      iVar8 = local_1b0;
    }
  }
  else {
    puVar5 = &local_3c;
    uVar9 = *(uint *)((int)local_1cc + -0xc);
    local_40 = uVar9;
    uVar7 = *(uint *)(*(int *)(local_1b0 + 0x14) + -0xc);
    local_3c = uVar7;
    if (uVar9 <= uVar7) {
      puVar5 = &local_40;
    }
    iVar4 = _memcmp(local_1cc,*(void **)(local_1b0 + 0x14),*puVar5);
    in_cr0 = (iVar4 == 0) << 1;
    if (iVar4 == 0) {
      iVar4 = uVar9 - uVar7;
    }
    if (iVar4 < 0) goto LAB_97b9d574;
  }
  iVar8 = *(int *)(iVar8 + 0x18);
  piVar3 = (int *)((int)local_1cc + -4);
  local_140 = local_1d0;
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar4 < 1) {
    std__string___Rep___M_destroy((unsigned char *)((int)local_1cc + -0xc));
  }
  if (iVar8 == 2) {
    pcVar6 = *(char **)(this + 8);
    local_120[0] = ((int (*)())GetGlobalPoolAllocator)();
    std__string__string((unsigned char *)&uStack_130,param_2,(unsigned char *)local_120);
    std__operator_((char *)&local_1a0,(unsigned char *)"extension ");
    std__string__string((unsigned char *)&local_1b0,(unsigned char *)&local_1a0);
    _strlen(" is being used");
    std__string__append((char *)&local_1b0,0x97c29948);
    *(undefined1 *)(local_1ac + *(int *)(local_1ac + -0xc)) = *DAT_a7b7ba18;
                    
    TInfoSinkBase__append(pcVar6);
    bVar1 = (param_1 & 0xffffU) == 0;
    bVar10 = bVar1 << 1;
    if (bVar1) {
      _sprintf(acStack_100,"%d:? ",param_1 >> 0x10);
    }
    else {
      _sprintf(acStack_100,"%d:%d",param_1 >> 0x10);
    }
    std__string__string((unsigned char *)aiStack_110,acStack_100,aaStack_c0);
    *(undefined *)(aiStack_110[0] + *(int *)(aiStack_110[0] + -0xc)) = *PTR__S_terminal_a7b7c0b8;
    TInfoSinkBase__append(pcVar6);
    piVar3 = (int *)(aiStack_110[0] + -4);
    do {
      iVar8 = *piVar3;
      if (in_RESERVE != '\0') {
        iVar4 = storeWordConditionalIndexed(iVar8 + -1,0,piVar3);
        *piVar3 = iVar4;
        bVar10 = 2;
      }
    } while (!(bool)(bVar10 >> 1 & 1));
    if (iVar8 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(aiStack_110[0] + -0xc));
    }
    TInfoSinkBase__append(pcVar6);
    TInfoSinkBase__append(pcVar6);
    TInfoSinkBase__append(pcVar6);
    piVar3 = (int *)(local_1ac + -4);
    iStack_b0 = local_1b0;
    do {
      iVar8 = *piVar3;
      if (in_RESERVE != '\0') {
        iVar4 = storeWordConditionalIndexed(iVar8 + -1,0,piVar3);
        *piVar3 = iVar4;
        bVar10 = 2;
      }
    } while (!(bool)(bVar10 >> 1 & 1));
    if (iVar8 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_1ac + -0xc));
    }
    piVar3 = (int *)(iStack_19c + -4);
    iStack_a0 = local_1a0;
    do {
      iVar8 = *piVar3;
      if (in_RESERVE != '\0') {
        iVar4 = storeWordConditionalIndexed(iVar8 + -1,0,piVar3);
        *piVar3 = iVar4;
        bVar10 = 2;
      }
    } while (!(bool)(bVar10 >> 1 & 1));
    if (iVar8 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(iStack_19c + -0xc));
    }
    piVar3 = (int *)(iStack_12c + -4);
    uStack_90 = uStack_130;
    do {
      iVar8 = *piVar3;
      if (in_RESERVE != '\0') {
        iVar4 = storeWordConditionalIndexed(iVar8 + -1,0,piVar3);
        *piVar3 = iVar4;
        bVar10 = 2;
      }
    } while (!(bool)(bVar10 >> 1 & 1));
    if (iVar8 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(iStack_12c + -0xc));
    }
    return false;
  }
  local_80[0] = ((int (*)())GetGlobalPoolAllocator)();
  std__string__string((unsigned char *)&local_1d0,param_2,(unsigned char *)local_80);
  std___Rb_tree_std__string_std__pair_std__string_const_TBehavior__std___Select1st_std__pair_std__string_const_TBehavior___std__less_std__string__pool_allocator_std__pair_std__string_const_TBehavior_____lower_bound((unsigned char *)local_1c0);
  iVar8 = local_1c0[0];
  local_1b0 = *(int *)(this + 0x34);
  if (local_1c0[0] != local_1b0) {
    puVar5 = &local_34;
    uVar9 = *(uint *)((int)local_1cc + -0xc);
    local_38 = uVar9;
    uVar7 = *(uint *)(*(int *)(local_1c0[0] + 0x14) + -0xc);
    local_34 = uVar7;
    if (uVar9 <= uVar7) {
      puVar5 = &local_38;
    }
    iVar4 = _memcmp(local_1cc,*(void **)(local_1c0[0] + 0x14),*puVar5);
    in_cr0 = (iVar4 == 0) << 1;
    if (iVar4 == 0) {
      iVar4 = uVar9 - uVar7;
    }
    if (-1 < iVar4) goto LAB_97b9d98c;
  }
  local_190[0] = iVar8;
  std__string__string((unsigned char *)&local_70,(unsigned char *)&local_1d0);
  local_68 = 0;
  local_180[0] = local_190[0];
  std___Rb_tree_std__string_std__pair_std__string_const_TBehavior__std___Select1st_std__pair_std__string_const_TBehavior___std__less_std__string__pool_allocator_std__pair_std__string_const_TBehavior_____insert_unique(&local_1a0,this + 0x30,local_180,(unsigned char *)&local_70);
  piVar3 = (int *)(local_6c + -4);
  local_1c0[0] = local_1a0;
  local_60 = local_70;
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar8 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar8;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  iVar8 = local_1a0;
  if (iVar4 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(local_6c + -0xc));
    iVar8 = local_1c0[0];
  }
LAB_97b9d98c:
  iVar8 = *(int *)(iVar8 + 0x18);
  piVar3 = (int *)((int)local_1cc + -4);
  local_50 = local_1d0;
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar4 < 1) {
    std__string___Rep___M_destroy((unsigned char *)((int)local_1cc + -0xc));
  }
  bVar1 = iVar8 == 3;
  if (bVar1) {
    error((int)this,(char *)param_1,"extension",param_2,"is disabled");
  }
  return bVar1;
}

/* TParseContext__findFunction @ 0x97b9da08 (356 bytes) */
int TParseContext__findFunction(this, param_1, param_2, param_3)
  unsigned char * this;
  int param_1;
  unsigned char * param_2;
  bool *param_3;
{
  undefined1 uVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int local_40 [7];
  
  piVar6 = *(int **)(this + 4);
  (**(code **)(*(int *)param_2 + 8))(param_2);
  iVar4 = *piVar6;
  iVar2 = (piVar6[1] - iVar4 >> 2) + -1;
  while( true ) {
    iVar4 = *(int *)(iVar4 + iVar2 * 4);
    std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______find((unsigned char *)local_40);
    piVar7 = (int *)0x0;
    if (local_40[0] != *(int *)(iVar4 + 4)) {
      piVar7 = *(int **)(local_40[0] + 0x18);
    }
    if ((piVar7 != (int *)0x0) || (iVar2 + -1 < 0)) break;
    iVar4 = *piVar6;
    iVar2 = iVar2 + -1;
  }
  if (param_3 != (bool *)0x0) {
    *(uint *)param_3 = (uint)(iVar2 == 0);
  }
  if (piVar7 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar7 + 0xc))(piVar7);
    if (iVar2 != 0) {
      return piVar7;
    }
    iVar4 = *(int *)(param_2 + 4);
    iVar5 = *(int *)(iVar4 + 4);
    uVar1 = *DAT_a7b7ba18;
    iVar2 = *(int *)(iVar5 + -0xc);
    pcVar3 = "function name expected";
  }
  else {
    iVar4 = *(int *)(param_2 + 4);
    iVar5 = *(int *)(iVar4 + 4);
    uVar1 = *DAT_a7b7ba18;
    iVar2 = *(int *)(iVar5 + -0xc);
    pcVar3 = "no matching overloaded function found";
  }
  *(undefined1 *)(iVar5 + iVar2) = uVar1;
  error((int)this,(char *)param_1,pcVar3,*(char **)(iVar4 + 4),"");
  return (int *)0x0;
}

/* TParseContext__executeInitializer @ 0x97b9db6c (3572 bytes) */
int TParseContext__executeInitializer(this, param_1, param_2, param_3, param_4, param_5)
  unsigned char * this;
  int param_1;
  unsigned char * param_2;
  unsigned char * param_3;
  unsigned char * param_4;
  unsigned char ** param_5;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  ulong uVar7;
  int *piVar8;
  unsigned char * psVar9;
  unsigned char * psVar10;
  uint uVar11;
  undefined4 uVar12;
  unsigned char * pTVar13;
  char *pcVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  bool bVar17;
  undefined4 uVar18;
  int iVar19;
  undefined4 *puVar20;
  int *piVar21;
  int iVar22;
  char *pcVar23;
  char in_RESERVE;
  byte bVar24;
  unsigned char * local_150;
  uint local_14c;
  uint local_148;
  uint local_144;
  unsigned char * local_140;
  uint local_13c;
  uint local_138;
  uint local_134;
  uint local_130;
  uint local_12c;
  undefined **local_120;
  uint local_11c;
  uint local_118;
  uint local_114;
  uint local_110;
  int *local_10c;
  undefined4 local_108;
  undefined **local_100;
  uint local_fc;
  uint local_f8;
  uint local_f4;
  uint local_f0;
  int *local_ec;
  undefined4 local_e8;
  undefined4 local_e0 [4];
  undefined4 local_d0;
  int local_cc;
  int *local_c8;
  undefined4 local_c0;
  undefined **local_b0;
  undefined4 local_a0 [4];
  undefined4 local_90 [4];
  int local_80 [4];
  unsigned char * local_70;
  unsigned char * local_60;
  unsigned char * local_50;
  
  iVar6 = TParseContext__reservedErrorCheck(this,param_1,param_2);
  if (iVar6 != 0) {
    return 1;
  }
  local_14c = TParseContext__voidErrorCheck(this,param_1,param_2,param_3);
  bVar24 = (local_14c == 0) << 1;
  if (local_14c != 0) {
    return 1;
  }
  uVar7 = ((int (*)())GetGlobalPoolAllocator)();
  piVar8 = (int *)((int (*)())TPoolAllocator__allocate)(uVar7);
  local_10c = *(int **)(param_3 + 0x14);
  local_11c = *(uint *)(param_3 + 4);
  local_120 = *(undefined ***)param_3;
  local_118 = *(uint *)(param_3 + 8);
  local_114 = *(uint *)(param_3 + 0xc);
  local_110 = *(uint *)(param_3 + 0x10);
  local_108 = *(undefined4 *)(param_3 + 0x18);
  local_12c = (local_110 & 1) << 9 |
              (local_114 & 1) << 10 |
              (local_118 & 0xff) << 0xb |
              ((uint)local_120 & 0x3f) << 0x13 | local_11c << 0x19 | local_12c & 0x1ff;
  local_150 = (unsigned char *)&PTR__TType_a7b7d4d0;
  local_148 = 0;
  local_138 = 0;
  local_144 = local_14c;
  psVar10 = (unsigned char *)0x0;
  local_13c = local_14c;
  local_134 = local_14c;
  local_130 = local_14c;
  local_100 = local_120;
  local_fc = local_11c;
  local_f8 = local_118;
  local_f4 = local_114;
  local_f0 = local_110;
  local_ec = local_10c;
  local_e8 = local_108;
  if (local_10c != (int *)0x0) {
    local_148 = local_10c[2];
    local_140 = (unsigned char *)local_14c;
    local_138 = local_14c;
    local_138 = TType__setStructSize((unsigned char *)&local_150);
    iVar6 = (**(code **)(*local_ec + 0x18))(local_ec);
    *(undefined1 *)(*(int *)(iVar6 + 4) + *(int *)(*(int *)(iVar6 + 4) + -0xc)) = *DAT_a7b7ba18;
    pcVar23 = *(char **)(iVar6 + 4);
    uVar7 = ((int (*)())GetGlobalPoolAllocator)();
    psVar9 = (unsigned char *)((int (*)())TPoolAllocator__allocate)(uVar7);
    bVar24 = (psVar9 == (unsigned char *)0x0) << 1;
    psVar10 = (unsigned char *)0x0;
    if (psVar9 != (unsigned char *)0x0) {
      local_e0[0] = ((int (*)())GetGlobalPoolAllocator)();
      std__string__string(psVar9,pcVar23,(unsigned char *)local_e0);
      psVar10 = psVar9;
    }
  }
  local_140 = psVar10;
  piVar8[1] = (int)param_2;
  piVar21 = piVar8 + 3;
  *piVar8 = (int)(PTR_vtable_a7b7c0b4 + 8);
  piVar8[4] = local_14c;
  piVar8[5] = local_148;
  piVar8[6] = local_144;
  piVar8[7] = (int)local_140;
  piVar8[8] = local_13c;
  piVar8[9] = local_138;
  piVar8[3] = (int)&PTR__TType_a7b7d4d0;
  piVar8[10] = local_134;
  piVar8[0xb] = local_130;
  uVar4 = piVar8[0xc];
  uVar1 = local_12c & 0xfe000000;
  piVar8[0xc] = uVar1 | uVar4 & 0x1ffffff;
  uVar2 = (local_12c >> 0x13 & 0x3f) << 0x13;
  piVar8[0xc] = uVar2 | uVar1 | uVar4 & 0x7ffff;
  uVar11 = local_12c & 0x7f800;
  piVar8[0xc] = uVar11 | uVar2 | uVar1 | uVar4 & 0x7ff;
  uVar3 = (local_12c >> 10 & 1) << 10;
  piVar8[0xc] = uVar3 | uVar11 | uVar2 | uVar1 | uVar4 & 0x3ff;
  piVar8[0xc] = (local_12c >> 9 & 1) << 9 | uVar3 | uVar11 | uVar2 | uVar1 | uVar4 & 0x1ff;
  piVar8[0xd] = 0;
  piVar8[0xe] = 0;
  piVar8[0xf] = 0;
  local_150 = (unsigned char *)&PTR__TType_a7b7d4d0;
  iVar6 = *(int *)(*(int *)(this + 4) + 0xc) + 1;
  *(int *)(*(int *)(this + 4) + 0xc) = iVar6;
  piVar8[2] = iVar6;
  local_14c = 0;
  psVar10 = (unsigned char *)(**(code **)(*piVar8 + 8))(piVar8);
  std__string__string((unsigned char *)&local_d0,psVar10);
  local_c8 = piVar8;
  std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&local_140);
  local_150 = local_140;
  piVar5 = (int *)(local_cc + -4);
  local_14c = local_13c;
  local_c0 = local_d0;
  do {
    iVar6 = *piVar5;
    if (in_RESERVE != '\0') {
      iVar19 = storeWordConditionalIndexed(iVar6 + -1,0,piVar5);
      *piVar5 = iVar19;
      bVar24 = 2;
    }
  } while (!(bool)(bVar24 >> 1 & 1));
  if (iVar6 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(local_cc + -0xc));
  }
  if (local_14c == 0) {
    iVar6 = piVar8[1];
    iVar19 = *(int *)(iVar6 + 4);
    pcVar14 = "redefinition";
    *(undefined1 *)(iVar19 + *(int *)(iVar19 + -0xc)) = *DAT_a7b7ba18;
    pcVar23 = *(char **)(iVar6 + 4);
    goto LAB_97b9df14;
  }
  uVar11 = (**(code **)(piVar8[3] + 0x24))(piVar21);
  if (2 < uVar11) {
    pcVar23 = (char *)getQualifierString((uint)piVar8[0xc] >> 0x19);
    pcVar14 = " cannot initialize this type of qualifier ";
    goto LAB_97b9df14;
  }
  if (uVar11 != 2) {
    uVar12 = TIntermediate__addSymbol
                       (*(int *)this,(unsigned char *)piVar8[2],(unsigned char *)piVar8[1],(int)piVar21);
    pTVar13 = (unsigned char *)
              TIntermediate__addAssign(*(undefined4 *)this,0x76,uVar12,param_4,param_1);
    *param_5 = pTVar13;
    if (pTVar13 != (unsigned char *)0x0) {
      return 0;
    }
    TType__getCompleteString();
    TType__getCompleteString();
    TParseContext__assignError(this,param_1,"=",(unsigned char *)&local_140,&local_150);
    piVar8 = (int *)(local_13c - 4);
    local_60 = local_140;
    do {
      iVar6 = *piVar8;
      if (in_RESERVE != '\0') {
        iVar19 = storeWordConditionalIndexed(iVar6 + -1,0,piVar8);
        *piVar8 = iVar19;
        bVar24 = 2;
      }
    } while (!(bool)(bVar24 >> 1 & 1));
    if (iVar6 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_13c - 0xc));
    }
    piVar8 = (int *)(local_14c - 4);
    local_50 = local_150;
    do {
      iVar6 = *piVar8;
      if (in_RESERVE != '\0') {
        iVar19 = storeWordConditionalIndexed(iVar6 + -1,0,piVar8);
        *piVar8 = iVar19;
        bVar24 = 2;
      }
    } while (!(bool)(bVar24 >> 1 & 1));
    if (0 < iVar6) {
      return 1;
    }
    std__string___Rep___M_destroy((unsigned char *)(local_14c - 0xc));
    return 1;
  }
  (**(code **)(*(int *)param_4 + 0x38))((unsigned char *)&local_150,param_4);
  local_150 = (unsigned char *)&PTR__TType_a7b7d4d0;
  uVar11 = -((int)-(local_12c >> 0x19 ^ 2) >> 0x1f);
  bVar24 = (uVar11 == 0) << 1;
  if (uVar11 != 0) {
    TType__getCompleteString();
    *(undefined1 *)(local_11c + *(int *)(local_11c - 0xc)) = *DAT_a7b7ba18;
    error((int)this,(char *)param_1," assigning non-constant to","=","\'%s\'",local_11c);
    piVar5 = (int *)(local_11c - 4);
    do {
      iVar6 = *piVar5;
      if (in_RESERVE != '\0') {
        iVar19 = storeWordConditionalIndexed(iVar6 + -1,0,piVar5);
        *piVar5 = iVar19;
        bVar24 = 2;
      }
      local_b0 = local_120;
      uVar11 = local_11c;
    } while (!(bool)(bVar24 >> 1 & 1));
joined_r0x97b9dfd0:
    if (iVar6 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(uVar11 - 0xc));
    }
LAB_97b9e184:
    (**(code **)(piVar8[3] + 0x28))(piVar21,0);
    return 1;
  }
  local_10c = *(int **)(param_3 + 0x14);
  local_11c = *(uint *)(param_3 + 4);
  local_120 = *(undefined ***)param_3;
  local_118 = *(uint *)(param_3 + 8);
  local_114 = *(uint *)(param_3 + 0xc);
  local_110 = *(uint *)(param_3 + 0x10);
  local_108 = *(undefined4 *)(param_3 + 0x18);
  local_12c = (local_110 & 1) << 9 |
              (local_114 & 1) << 10 |
              (local_118 & 0xff) << 0xb |
              ((uint)local_120 & 0x3f) << 0x13 | local_11c << 0x19 | local_12c & 0x1ff;
  local_150 = (unsigned char *)&PTR__TType_a7b7d4d0;
  local_148 = 0;
  local_138 = 0;
  bVar24 = 2;
  local_14c = uVar11;
  local_144 = uVar11;
  psVar10 = (unsigned char *)0x0;
  local_13c = uVar11;
  local_134 = uVar11;
  local_130 = uVar11;
  local_100 = local_120;
  local_fc = local_11c;
  local_f8 = local_118;
  local_f4 = local_114;
  local_f0 = local_110;
  local_ec = local_10c;
  local_e8 = local_108;
  if (local_10c != (int *)0x0) {
    local_148 = local_10c[2];
    local_140 = (unsigned char *)uVar11;
    local_138 = uVar11;
    local_138 = TType__setStructSize((unsigned char *)&local_150);
    iVar6 = (**(code **)(*local_ec + 0x18))(local_ec);
    *(undefined1 *)(*(int *)(iVar6 + 4) + *(int *)(*(int *)(iVar6 + 4) + -0xc)) = *DAT_a7b7ba18;
    pcVar23 = *(char **)(iVar6 + 4);
    uVar7 = ((int (*)())GetGlobalPoolAllocator)();
    psVar9 = (unsigned char *)((int (*)())TPoolAllocator__allocate)(uVar7);
    bVar24 = (psVar9 == (unsigned char *)0x0) << 1;
    psVar10 = (unsigned char *)0x0;
    if (psVar9 != (unsigned char *)0x0) {
      local_a0[0] = ((int (*)())GetGlobalPoolAllocator)();
      std__string__string(psVar9,pcVar23,(unsigned char *)local_a0);
      psVar10 = psVar9;
    }
  }
  local_140 = psVar10;
  (**(code **)(*(int *)param_4 + 0x38))(&local_120,param_4);
  bVar17 = false;
  if (((local_12c & 0x1fffe00) == (local_fc & 0x1fffe00)) && (local_148 == local_118)) {
    bVar17 = true;
  }
  local_150 = (unsigned char *)&PTR__TType_a7b7d4d0;
  local_120 = &PTR__TType_a7b7d4d0;
  if (!bVar17) {
    pcVar23 = (char *)getQualifierString((uint)piVar8[0xc] >> 0x19);
    error((int)this,(char *)param_1," non-matching types for const initializer ",pcVar23,"");
    goto LAB_97b9e184;
  }
  iVar6 = (**(code **)(*(int *)param_4 + 0x18))(param_4);
  if (iVar6 == 0) {
    iVar6 = (**(code **)(*(int *)param_4 + 0x1c))(param_4);
    if (iVar6 != 0) {
      iVar6 = piVar8[0xe];
      if (iVar6 == 0) {
        uVar7 = ((int (*)())GetGlobalPoolAllocator)();
        iVar6 = ((int (*)())TPoolAllocator__allocate)(uVar7);
        piVar8[0xe] = iVar6;
      }
      piVar5 = (int *)(**(code **)(*(int *)param_4 + 0x1c))(param_4);
      iVar19 = (**(code **)(*piVar5 + 100))();
      if (*(int *)(iVar19 + 8) - *(int *)(iVar19 + 4) >> 2 == 1) {
        piVar5 = (int *)(**(code **)(*(int *)param_4 + 0x1c))(param_4);
        iVar19 = (**(code **)(*piVar5 + 100))();
        piVar5 = (int *)(**(code **)(*(int *)**(undefined4 **)(iVar19 + 4) + 0x14))();
        iVar19 = (**(code **)(*piVar5 + 0x18))();
        if (iVar19 != 0) {
          local_14c = piVar8[4];
          local_148 = piVar8[5];
          local_144 = piVar8[6];
          local_13c = piVar8[8];
          local_138 = piVar8[9];
          local_134 = piVar8[10];
          local_130 = piVar8[0xb];
          local_140 = (unsigned char *)piVar8[7];
          local_150 = (unsigned char *)&PTR__TType_a7b7d4d0;
          local_12c = ((uint)piVar8[0xc] >> 9 & 1) << 9 |
                      ((uint)piVar8[0xc] >> 10 & 1) << 10 |
                      piVar8[0xc] & 0x7f800U |
                      ((uint)piVar8[0xc] >> 0x13 & 0x3f) << 0x13 |
                      piVar8[0xc] & 0xfe000000U | local_12c & 0x1ff;
          iVar19 = (**(code **)(*(int *)param_4 + 0x1c))(param_4);
          uVar16 = *(undefined4 *)(this + 4);
          uVar15 = *(undefined4 *)(iVar19 + 0x30);
          uVar12 = *(undefined4 *)this;
          uVar18 = 1;
          goto LAB_97b9e6d8;
        }
      }
      local_14c = piVar8[4];
      local_148 = piVar8[5];
      local_144 = piVar8[6];
      local_13c = piVar8[8];
      local_138 = piVar8[9];
      local_134 = piVar8[10];
      local_130 = piVar8[0xb];
      local_140 = (unsigned char *)piVar8[7];
      local_150 = (unsigned char *)&PTR__TType_a7b7d4d0;
      local_12c = ((uint)piVar8[0xc] >> 9 & 1) << 9 |
                  ((uint)piVar8[0xc] >> 10 & 1) << 10 |
                  piVar8[0xc] & 0x7f800U |
                  ((uint)piVar8[0xc] >> 0x13 & 0x3f) << 0x13 |
                  piVar8[0xc] & 0xfe000000U | local_12c & 0x1ff;
      iVar19 = (**(code **)(*(int *)param_4 + 0x1c))(param_4);
      uVar16 = *(undefined4 *)(this + 4);
      uVar15 = *(undefined4 *)(iVar19 + 0x30);
      uVar12 = *(undefined4 *)this;
      uVar18 = 0;
LAB_97b9e6d8:
      iVar6 = TIntermediate__parseConstTree
                        (uVar12,param_1,param_4,iVar6,uVar15,uVar16,(unsigned char *)&local_150,uVar18);
      local_150 = (unsigned char *)&PTR__TType_a7b7d4d0;
      *param_5 = (unsigned char *)0x0;
      if (iVar6 != 0) {
        (**(code **)(piVar8[3] + 0x28))(piVar21,0);
        return iVar6;
      }
      return 0;
    }
    iVar6 = (**(code **)(*(int *)param_4 + 0x28))(param_4);
    if (iVar6 == 0) {
      TType__getCompleteString();
      *(undefined1 *)(local_14c + *(int *)(local_14c - 0xc)) = *DAT_a7b7ba18;
      error((int)this,(char *)param_1," assigning non-constant to","=","\'%s\'",local_14c);
      piVar5 = (int *)(local_14c - 4);
      do {
        iVar6 = *piVar5;
        if (in_RESERVE != '\0') {
          iVar19 = storeWordConditionalIndexed(iVar6 + -1,0,piVar5);
          *piVar5 = iVar19;
          bVar24 = 2;
        }
        uVar11 = local_14c;
        local_70 = local_150;
      } while (!(bool)(bVar24 >> 1 & 1));
      goto joined_r0x97b9dfd0;
    }
    piVar21 = *(int **)(this + 4);
    piVar5 = (int *)(**(code **)(*(int *)param_4 + 0x28))(param_4);
    (**(code **)(*piVar5 + 0x60))();
    iVar6 = *piVar21;
    iVar19 = (piVar21[1] - iVar6 >> 2) + -1;
    while( true ) {
      iVar22 = *(int *)(iVar6 + iVar19 * 4);
      std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______find((unsigned char *)local_80);
      iVar6 = 0;
      if (local_80[0] != *(int *)(iVar22 + 4)) {
        iVar6 = *(int *)(local_80[0] + 0x18);
      }
      iVar19 = iVar19 + -1;
      if ((iVar6 != 0) || (iVar19 < 0)) break;
      iVar6 = *piVar21;
    }
    iVar6 = *(int *)(iVar6 + 0x38);
  }
  else {
    puVar20 = (undefined4 *)piVar8[0xe];
    if (puVar20 == (undefined4 *)0x0) {
      uVar7 = ((int (*)())GetGlobalPoolAllocator)();
      puVar20 = (undefined4 *)((int (*)())TPoolAllocator__allocate)(uVar7);
      piVar8[0xe] = (int)puVar20;
    }
    uVar11 = *(uint *)(param_3 + 8);
    if (uVar11 == 1) {
      local_10c = *(int **)(param_3 + 0x14);
      local_11c = *(uint *)(param_3 + 4);
      local_120 = *(undefined ***)param_3;
      local_114 = *(uint *)(param_3 + 0xc);
      local_110 = *(uint *)(param_3 + 0x10);
      local_108 = *(undefined4 *)(param_3 + 0x18);
      local_12c = (local_110 & 1) << 9 |
                  (local_114 & 1) << 10 |
                  ((uint)local_120 & 0x3f) << 0x13 | local_11c << 0x19 | local_12c & 0x1ff | 0x800;
      local_150 = (unsigned char *)&PTR__TType_a7b7d4d0;
      local_130 = 0;
      local_14c = 0;
      local_148 = 0;
      local_144 = 0;
      local_140 = (unsigned char *)0x0;
      local_13c = 0;
      local_138 = 0;
      local_134 = 0;
      psVar10 = local_140;
      local_118 = uVar11;
      local_100 = local_120;
      local_fc = local_11c;
      local_f8 = uVar11;
      local_f4 = local_114;
      local_f0 = local_110;
      local_ec = local_10c;
      local_e8 = local_108;
      if (local_10c != (int *)0x0) {
        local_148 = local_10c[2];
        local_138 = TType__setStructSize((unsigned char *)&local_150);
        iVar6 = (**(code **)(*local_ec + 0x18))(local_ec);
        *(undefined1 *)(*(int *)(iVar6 + 4) + *(int *)(*(int *)(iVar6 + 4) + -0xc)) = *DAT_a7b7ba18;
        pcVar23 = *(char **)(iVar6 + 4);
        uVar7 = ((int (*)())GetGlobalPoolAllocator)();
        psVar9 = (unsigned char *)((int (*)())TPoolAllocator__allocate)(uVar7);
        psVar10 = (unsigned char *)0x0;
        if (psVar9 != (unsigned char *)0x0) {
          local_90[0] = ((int (*)())GetGlobalPoolAllocator)();
          std__string__string(psVar9,pcVar23,(unsigned char *)local_90);
          psVar10 = psVar9;
        }
      }
      local_140 = psVar10;
      local_150 = (unsigned char *)&PTR__TType_a7b7d4d0;
      if ((local_12c >> 0x13 & 0x3f) != 0xe) {
        iVar6 = *(int *)param_3;
        if (iVar6 != 2) {
          if (iVar6 < 3) {
            if (iVar6 == 1) {
              iVar6 = (**(code **)(*(int *)param_4 + 0x18))(param_4);
              *puVar20 = **(undefined4 **)(iVar6 + 0x30);
              goto LAB_97b9e850;
            }
          }
          else if (iVar6 == 3) goto LAB_97b9e3bc;
          pcVar23 = "";
          pcVar14 = " cannot initialize constant of this type";
LAB_97b9df14:
          error((int)this,(char *)param_1,pcVar14,pcVar23,"");
          return 1;
        }
LAB_97b9e3bc:
        iVar6 = (**(code **)(*(int *)param_4 + 0x18))(param_4);
        *puVar20 = **(undefined4 **)(iVar6 + 0x30);
        goto LAB_97b9e850;
      }
    }
    iVar6 = (**(code **)(*(int *)param_4 + 0x18))(param_4);
    iVar6 = *(int *)(iVar6 + 0x30);
  }
  piVar8[0xe] = iVar6;
LAB_97b9e850:
  *param_5 = (unsigned char *)0x0;
  return 0;
}

/* TParseContext__canNodeBeRemoved @ 0x97b9e960 (204 bytes) */
int TParseContext__canNodeBeRemoved(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  
  piVar2 = (int *)(**(code **)(*(int *)param_1 + 0x1c))(param_1);
  uVar1 = 0;
  if (piVar2 != (int *)0x0) {
    iVar3 = TIntermOperator__isConstructor();
    if ((iVar3 == 0) || (piVar2[0xc] == 0x75)) {
      uVar1 = 0;
    }
    else {
      iVar3 = (**(code **)(*piVar2 + 100))(piVar2);
      for (puVar5 = *(undefined4 **)(iVar3 + 4); puVar5 != *(undefined4 **)(iVar3 + 8);
          puVar5 = puVar5 + 1) {
        piVar2 = (int *)(**(code **)(*(int *)*puVar5 + 0x14))();
        iVar4 = (**(code **)(*piVar2 + 0x18))();
        if (iVar4 == 0) {
          return 0;
        }
      }
      uVar1 = 1;
    }
  }
  return uVar1;
}

/* TParseContext__addConstructor @ 0x97b9ea2c (944 bytes) */
int TParseContext__addConstructor(this, param_1, param_2, param_4, param_5, param_6)
  unsigned char * this;
  unsigned char * param_1;
  unsigned char * param_2;
  int param_4;
  int param_5;
  char *param_6;
{
  bool bVar1;
  int *piVar2;
  int iVar3;
  unsigned char * pTVar4;
  undefined4 uVar5;
  unsigned char * pTVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined1 auStack_40 [4];
  int local_3c;
  undefined4 *local_38;
  unsigned char * local_34;
  
  if (param_1 == (unsigned char *)0x0) {
    return (unsigned char *)0x0;
  }
  iVar8 = 0;
  bVar1 = param_4 != 0x75;
  puVar7 = (undefined4 *)0x0;
  piVar2 = (int *)(**(code **)(*(int *)param_1 + 0x1c))(param_1);
  if (!bVar1) {
    iVar8 = *(int *)(param_5 + 0x24);
    puVar7 = *(undefined4 **)(iVar8 + 4);
  }
  if (((piVar2 == (int *)0x0) || (piVar2[0xc] != 0)) ||
     (iVar3 = (**(code **)(*piVar2 + 100))(), *(int *)(iVar3 + 8) - *(int *)(iVar3 + 4) >> 2 == 1))
  {
    if (bVar1) {
      uVar5 = (*(code *)**(undefined4 **)param_1)(param_1);
      pTVar4 = (unsigned char *)((int (*)())TParseContext__constructBuiltIn)(this,param_2,param_4,param_1,uVar5,0);
      if (pTVar4 == (unsigned char *)0x0) {
        return (unsigned char *)0x0;
      }
      iVar8 = (**(code **)(*(int *)pTVar4 + 0x1c))();
      if (iVar8 == 0) {
        return pTVar4;
      }
      piVar2 = (int *)(**(code **)(*(int *)pTVar4 + 0x1c))(pTVar4);
      iVar8 = (**(code **)(*piVar2 + 100))();
      iVar8 = ((int (*)())TParseContext__canNodeBeRemoved)(this,(unsigned char *)**(undefined4 **)(iVar8 + 4));
      if (iVar8 == 0) {
        return pTVar4;
      }
      piVar2 = (int *)(**(code **)(*(int *)pTVar4 + 0x1c))(pTVar4);
      iVar8 = (**(code **)(*piVar2 + 100))();
      (**(code **)(*(int *)**(undefined4 **)(iVar8 + 4) + 0x1c))();
      pTVar4 = (unsigned char *)TIntermediate__removeChildNode(*(unsigned char **)this,pTVar4,param_2);
      return pTVar4;
    }
    if (*(int *)(iVar8 + 8) - *(int *)(iVar8 + 4) >> 3 == 1) {
      iVar8 = (*(code *)**(undefined4 **)param_1)(param_1);
      pTVar4 = (unsigned char *)((int (*)())TParseContext__constructStruct)(this,param_1,(unsigned char *)*puVar7,1,iVar8,false);
      return pTVar4;
    }
  }
  else {
    pTVar4 = (unsigned char *)(**(code **)(*piVar2 + 100))(piVar2);
    if ((bVar1) ||
       (*(int *)(iVar8 + 8) - *(int *)(iVar8 + 4) >> 3 ==
        *(int *)(pTVar4 + 8) - *(int *)(pTVar4 + 4) >> 2)) {
      local_3c = 0;
      puVar9 = *(undefined4 **)(pTVar4 + 4);
      do {
        iVar8 = local_3c;
        local_38 = puVar9;
        if (puVar9 == *(undefined4 **)(pTVar4 + 8)) {
          pTVar4 = (unsigned char *)TIntermediate__setAggregateOperator
                                      (*(undefined4 *)this,piVar2,param_4,param_6);
          return pTVar4;
        }
        if (bVar1) {
          uVar5 = (*(code *)**(undefined4 **)param_1)(param_1);
          pTVar6 = (unsigned char *)((int (*)())TParseContext__constructBuiltIn)(this,param_2,param_4,*puVar9,uVar5,1);
          if (pTVar6 != (unsigned char *)0x0) {
            iVar8 = ((int (*)())TParseContext__canNodeBeRemoved)(this,pTVar6);
            if (iVar8 == 0) goto LAB_97b9ed60;
            (**(code **)(*(int *)pTVar6 + 0x1c))(pTVar6);
            TIntermediate__removeChildNode
                      (*(unsigned char **)this,pTVar4,(int *)param_2,(unsigned char *)&local_3c,
                       (unsigned char *)&local_38);
          }
        }
        else {
          iVar3 = (*(code *)**(undefined4 **)param_1)(param_1);
          pTVar6 = (unsigned char *)
                   ((int (*)())TParseContext__constructStruct)(this,(unsigned char *)*puVar9,(unsigned char *)puVar7[iVar8 * 2],
                                   local_3c + 1,iVar3,true);
          if (pTVar6 != (unsigned char *)0x0) {
LAB_97b9ed60:
            std__vector_TIntermNode__pool_allocator_TIntermNode_____erase
                      (auStack_40,pTVar4,local_38);
            local_34 = pTVar6;
            std__vector_TIntermNode__pool_allocator_TIntermNode_____insert
                      (auStack_40,pTVar4,local_38,&local_34);
          }
        }
        local_3c = local_3c + 1;
        puVar9 = local_38 + 1;
      } while( true );
    }
  }
  error((int)this,param_6,
        "Number of constructor parameters does not match the number of structure fields",
        "constructor","");
  return (unsigned char *)0x0;
}

/* TParseContext__constructBuiltIn @ 0x97b9eddc (408 bytes) */
int TParseContext__constructBuiltIn(this, param_1, param_3, param_4, param_5, param_6)
  unsigned char * this;
  int param_1;
  undefined4 param_3;
  int *param_4;
  char *param_5;
  int param_6;
{
  bool bVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined **local_50 [2];
  int local_48;
  uint local_2c;
  
  switch(param_3) {
  case 0x66:
  case 0x6f:
  case 0x70:
  case 0x71:
    uVar4 = 0x66;
    break;
  case 0x67:
  case 0x6c:
  case 0x6d:
  case 0x6e:
    uVar4 = 0x67;
    break;
  case 0x68:
  case 0x69:
  case 0x6a:
  case 0x6b:
  case 0x72:
  case 0x73:
  case 0x74:
    uVar4 = 0x68;
    break;
  default:
    error((int)this,param_5,"unsupported construction","","");
    TParseContext__recover(this);
    goto LAB_97b9ef08;
  }
  uVar2 = (**(code **)*param_4)(param_4);
  piVar3 = (int *)TIntermediate__addUnaryMath
                            (*(undefined4 *)this,uVar4,param_4,uVar2,*(undefined4 *)(this + 4));
  if (piVar3 == (int *)0x0) {
    error((int)this,param_5,"can\'t convert","constructor","");
LAB_97b9ef08:
    piVar3 = (int *)0x0;
  }
  else if (param_6 == 0) {
    if (piVar3 != param_4) {
      (**(code **)(*piVar3 + 0x38))(local_50,piVar3);
      bVar1 = false;
      if (((local_2c & 0x1fffe00) == (*(uint *)(param_1 + 0x24) & 0x1fffe00)) &&
         (local_48 == *(int *)(param_1 + 8))) {
        bVar1 = true;
      }
      local_50[0] = &PTR__TType_a7b7d4d0;
      if (bVar1) {
        return piVar3;
      }
    }
    piVar3 = (int *)TIntermediate__setAggregateOperator(*(undefined4 *)this,piVar3,param_3,param_5);
  }
  return piVar3;
}

/* TParseContext__constructStruct @ 0x97b9efb0 (392 bytes) */
int TParseContext__constructStruct(this, param_1, param_2, param_3, param_4, param_5)
  unsigned char * this;
  unsigned char * param_1;
  unsigned char * param_2;
  int param_3;
  int param_4;
  int param_5;
{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined3 in_register_00000020;
  bool bVar4;
  undefined **local_80 [2];
  int local_78;
  uint local_5c;
  undefined **local_50 [9];
  uint local_2c;
  
  piVar1 = (int *)(**(code **)(*(int *)param_1 + 0x14))(param_1);
  (**(code **)(*piVar1 + 0x38))(local_80,piVar1);
  bVar4 = false;
  if (((*(uint *)(param_2 + 0x24) & 0x1fffe00) == (local_5c & 0x1fffe00)) &&
     (*(int *)(param_2 + 8) == local_78)) {
    bVar4 = true;
  }
  local_80[0] = &PTR__TType_a7b7d4d0;
  if (bVar4) {
    if (CONCAT31(in_register_00000020,param_5) == 0) {
      uVar2 = (**(code **)(*(int *)param_1 + 0x14))(param_1);
      uVar2 = TIntermediate__setAggregateOperator(*(undefined4 *)this,uVar2,0x75,param_4);
    }
    else {
      uVar2 = (**(code **)(*(int *)param_1 + 0x14))(param_1);
    }
  }
  else {
    uVar2 = TType__getBasicString(*(uint *)(param_2 + 0x24) >> 0x13 & 0x3f);
    piVar1 = (int *)(**(code **)(*(int *)param_1 + 0x14))(param_1);
    (**(code **)(*piVar1 + 0x38))(local_50,piVar1);
    uVar3 = TType__getBasicString(local_2c >> 0x13 & 0x3f);
    error((int)this,(char *)param_4,"","constructor",
          "cannot convert parameter %d from \'%s\' to \'%s\'",param_3,uVar3,uVar2);
    local_50[0] = &PTR__TType_a7b7d4d0;
    TParseContext__recover(this);
    uVar2 = 0;
  }
  return uVar2;
}

/* TParseContext__addConstVectorNode @ 0x97b9f138 (924 bytes) */
int TParseContext__addConstVectorNode(this, param_1, param_2, param_3)
  unsigned char * this;
  unsigned char * param_1;
  unsigned char * param_2;
  int param_3;
{
  bool bVar1;
  undefined *puVar2;
  undefined **ppuVar3;
  int iVar4;
  undefined *puVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  ulong uVar9;
  unsigned char * pTVar10;
  unsigned char * pTVar11;
  char *pcVar12;
  int iVar13;
  int iVar14;
  char in_RESERVE;
  byte bVar15;
  undefined **local_90 [4];
  char acStack_80 [20];
  uint local_6c;
  unsigned char aaStack_40 [16];
  
  iVar6 = (**(code **)(*(int *)param_2 + 0x18))(param_2);
  piVar7 = (int *)(**(code **)(*(int *)param_2 + 0x1c))(param_2);
  if (iVar6 != 0) {
    iVar6 = *(int *)(iVar6 + 0x30);
    if (iVar6 == 0) {
      pcVar12 = *(char **)(this + 8);
                    
      TInfoSinkBase__append(pcVar12);
      bVar1 = (param_3 & 0xffffU) == 0;
      bVar15 = bVar1 << 1;
      if (bVar1) {
        _sprintf(acStack_80,"%d:? ",param_3 >> 0x10);
      }
      else {
        _sprintf(acStack_80,"%d:%d",param_3 >> 0x10);
      }
      std__string__string((unsigned char *)local_90,acStack_80,aaStack_40);
      *(undefined *)((int)local_90[0] + (int)local_90[0][-3]) = *PTR__S_terminal_a7b7c0b8;
      TInfoSinkBase__append(pcVar12);
      ppuVar3 = local_90[0] + -1;
      do {
        puVar5 = *ppuVar3;
        if (in_RESERVE != '\0') {
          puVar2 = (undefined *)storeWordConditionalIndexed(puVar5 + -1,0,ppuVar3);
          *ppuVar3 = puVar2;
          bVar15 = 2;
        }
      } while (!(bool)(bVar15 >> 1 & 1));
      if ((int)puVar5 < 1) {
        std__string___Rep___M_destroy((unsigned char *)(local_90[0] + -3));
      }
      TInfoSinkBase__append(pcVar12);
      TInfoSinkBase__append(pcVar12);
      TInfoSinkBase__append(pcVar12);
      TParseContext__recover(this);
      return param_2;
    }
    goto LAB_97b9f4c4;
  }
  if (piVar7 == (int *)0x0) {
    error((int)this,(char *)param_3,"No aggregate or constant union node available","Internal Error"
          ,"");
    TParseContext__recover(this);
    return (unsigned char *)0x0;
  }
  (**(code **)(*piVar7 + 0x38))(local_90,piVar7);
  uVar9 = ((int (*)())GetGlobalPoolAllocator)();
  iVar6 = ((int (*)())TPoolAllocator__allocate)(uVar9);
  local_90[0] = &PTR__TType_a7b7d4d0;
  piVar8 = (int *)(**(code **)(*piVar7 + 0x1c))(piVar7);
  iVar14 = (**(code **)(*piVar8 + 100))();
  if (*(int *)(iVar14 + 8) - *(int *)(iVar14 + 4) >> 2 == 1) {
    piVar8 = (int *)(**(code **)(*piVar7 + 0x1c))(piVar7);
    iVar14 = (**(code **)(*piVar8 + 100))();
    piVar8 = (int *)(**(code **)(*(int *)**(undefined4 **)(iVar14 + 4) + 0x14))();
    iVar14 = (**(code **)(*piVar8 + 0x18))();
    if (iVar14 == 0) goto LAB_97b9f438;
    (**(code **)(*piVar7 + 0x38))(local_90,piVar7);
    iVar14 = TIntermediate__parseConstTree
                       (*(undefined4 *)this,param_3,piVar7,iVar6,piVar7[0xc],
                        *(undefined4 *)(this + 4),local_90,1);
  }
  else {
LAB_97b9f438:
    (**(code **)(*piVar7 + 0x38))(local_90,piVar7);
    iVar14 = TIntermediate__parseConstTree
                       (*(undefined4 *)this,param_3,piVar7,iVar6,piVar7[0xc],
                        *(undefined4 *)(this + 4),local_90,0);
  }
  local_90[0] = &PTR__TType_a7b7d4d0;
  if (iVar14 != 0) {
    return (unsigned char *)0x0;
  }
LAB_97b9f4c4:
  iVar14 = 0;
  uVar9 = ((int (*)())GetGlobalPoolAllocator)();
  pTVar10 = (unsigned char *)((int (*)())TPoolAllocator__allocate)(uVar9);
  if (0 < *(int *)(param_1 + 0x10)) {
    iVar13 = 0;
    do {
      (**(code **)(*(int *)param_2 + 0x38))(local_90,param_2);
      if ((local_6c & 0x400) == 0) {
        iVar4 = (int)(local_6c << 0xd | local_6c >> 0x13) >> 0x18;
      }
      else {
        iVar4 = (int)(local_6c << 0xd | local_6c >> 0x13) >> 0x18;
        iVar4 = iVar4 * iVar4;
      }
      local_90[0] = &PTR__TType_a7b7d4d0;
      if (iVar4 <= *(int *)(param_1 + iVar13)) {
        error((int)this,(char *)param_3,"","[","vector field selection out of range \'%d\'",
              *(undefined4 *)(param_1 + iVar13));
        TParseContext__recover(this);
        *(undefined4 *)(param_1 + iVar13) = 0;
      }
      iVar14 = iVar14 + 1;
      *(undefined4 *)(pTVar10 + iVar13) = *(undefined4 *)(iVar6 + *(int *)(param_1 + iVar13) * 4);
      iVar13 = iVar13 + 4;
    } while (iVar14 < *(int *)(param_1 + 0x10));
  }
  (**(code **)(*(int *)param_2 + 0x38))(local_90,param_2);
  pTVar11 = (unsigned char *)
            TIntermediate__addConstantUnion(*(unsigned char **)this,pTVar10,(int)local_90);
  return pTVar11;
}

/* TParseContext__addConstMatrixNode @ 0x97b9f600 (904 bytes) */
int TParseContext__addConstMatrixNode(this, param_1, param_2, param_3)
  unsigned char * this;
  int param_1;
  unsigned char * param_2;
  int param_3;
{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  ulong uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined **local_60 [9];
  uint local_3c;
  
  piVar1 = (int *)(**(code **)(*(int *)param_2 + 0x18))(param_2);
  piVar2 = (int *)(**(code **)(*(int *)param_2 + 0x1c))(param_2);
  (**(code **)(*(int *)param_2 + 0x38))(local_60,param_2);
  local_60[0] = &PTR__TType_a7b7d4d0;
  iVar6 = param_1;
  if ((int)(local_3c << 0xd | local_3c >> 0x13) >> 0x18 <= param_1) {
    iVar6 = 0;
    error((int)this,(char *)param_3,"","[","matrix field selection out of range \'%d\'",param_1);
    TParseContext__recover(this);
  }
  if (piVar1 != (int *)0x0) {
    iVar7 = piVar1[0xc];
    (**(code **)(*piVar1 + 0x38))(local_60,piVar1);
    local_60[0] = &PTR__TType_a7b7d4d0;
    (**(code **)(*piVar1 + 0x38))(local_60,piVar1);
    uVar3 = TIntermediate__addConstantUnion
                      (*(unsigned char **)this,
                       (unsigned char *)(iVar7 + ((int)(local_3c << 0xd | local_3c >> 0x13) >> 0x18) * iVar6
                                         * 4),(int)local_60);
    return uVar3;
  }
  if (piVar2 == (int *)0x0) {
    error((int)this,(char *)param_3,"No Aggregate or Constant Union node available","Internal Error"
          ,"");
    TParseContext__recover(this);
    return 0;
  }
  (**(code **)(*piVar2 + 0x38))(local_60,piVar2);
  uVar4 = ((int (*)())GetGlobalPoolAllocator)();
  iVar7 = ((int (*)())TPoolAllocator__allocate)(uVar4);
  local_60[0] = &PTR__TType_a7b7d4d0;
  (**(code **)(*piVar2 + 0x38))(local_60,piVar2);
  local_60[0] = &PTR__TType_a7b7d4d0;
  piVar1 = (int *)(**(code **)(*piVar2 + 0x1c))(piVar2);
  iVar5 = (**(code **)(*piVar1 + 100))();
  if (*(int *)(iVar5 + 8) - *(int *)(iVar5 + 4) >> 2 == 1) {
    piVar1 = (int *)(**(code **)(*piVar2 + 0x1c))(piVar2);
    iVar5 = (**(code **)(*piVar1 + 100))();
    piVar1 = (int *)(**(code **)(*(int *)**(undefined4 **)(iVar5 + 4) + 0x14))();
    iVar5 = (**(code **)(*piVar1 + 0x18))();
    if (iVar5 != 0) {
      (**(code **)(*piVar2 + 0x38))(local_60,piVar2);
      iVar5 = TIntermediate__parseConstTree
                        (*(undefined4 *)this,param_3,piVar2,iVar7,piVar2[0xc],
                         *(undefined4 *)(this + 4),local_60,1);
      goto LAB_97b9f8f4;
    }
  }
  (**(code **)(*piVar2 + 0x38))(local_60,piVar2);
  iVar5 = TIntermediate__parseConstTree
                    (*(undefined4 *)this,param_3,piVar2,iVar7,piVar2[0xc],*(undefined4 *)(this + 4),
                     local_60,0);
LAB_97b9f8f4:
  local_60[0] = &PTR__TType_a7b7d4d0;
  uVar3 = 0;
  if (iVar5 == 0) {
    (**(code **)(*piVar2 + 0x38))(local_60,piVar2);
    uVar3 = TIntermediate__addConstantUnion
                      (*(unsigned char **)this,
                       (unsigned char *)(iVar7 + ((int)(local_3c << 0xd | local_3c >> 0x13) >> 0x18) * iVar6
                                         * 4),(int)local_60);
  }
  return uVar3;
}

/* TParseContext__addConstStruct @ 0x97b9f988 (848 bytes) */
int TParseContext__addConstStruct(this, param_1, param_2, param_3)
  unsigned char * this;
  unsigned char * param_1;
  unsigned char * param_2;
  int param_3;
{
  int iVar1;
  int *piVar2;
  int *piVar3;
  unsigned char * pTVar4;
  ulong uVar5;
  undefined4 uVar6;
  uint *puVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  undefined **local_80 [2];
  int local_78;
  uint local_50;
  uint local_4c [5];
  
  iVar8 = 0;
  (**(code **)(*(int *)param_2 + 0x38))(local_80,param_2);
  local_80[0] = &PTR__TType_a7b7d4d0;
  piVar2 = (int *)(**(code **)(*(int *)param_2 + 0x18))(param_2);
  piVar3 = (int *)(**(code **)(*(int *)param_2 + 0x1c))(param_2);
  for (uVar9 = 0; uVar9 < (uint)(*(int *)(local_78 + 8) - *(int *)(local_78 + 4) >> 3);
      uVar9 = uVar9 + 1) {
    iVar11 = (**(code **)(**(int **)(*(int *)(local_78 + 4) + uVar9 * 8) + 0x1c))();
    uVar12 = *(uint *)(*(int *)(iVar11 + 4) + -0xc);
    local_50 = uVar12;
    uVar10 = *(uint *)((int)*(void **)(param_1 + 4) + -0xc);
    local_4c[0] = uVar10;
    puVar7 = local_4c;
    if (uVar12 <= uVar10) {
      puVar7 = &local_50;
    }
    iVar11 = _memcmp(*(void **)(iVar11 + 4),*(void **)(param_1 + 4),*puVar7);
    if (iVar11 == 0) {
      iVar11 = uVar12 - uVar10;
    }
    if (iVar11 == 0) break;
    pTVar4 = *(unsigned char **)(*(int *)(local_78 + 4) + uVar9 * 8);
    if (*(int *)(pTVar4 + 8) == 0) {
      iVar11 = (**(code **)(*(int *)pTVar4 + 0x30))();
    }
    else {
      iVar11 = TType__setStructSize(pTVar4);
    }
    iVar8 = iVar8 + iVar11;
  }
  if (piVar2 != (int *)0x0) {
    iVar1 = *piVar2;
    iVar11 = piVar2[0xc];
    piVar3 = piVar2;
    goto LAB_97b9fc60;
  }
  if (piVar3 == (int *)0x0) {
    error((int)this,(char *)param_3,"No Aggregate or Constant Union node available","Internal Error"
          ,"");
    TParseContext__recover(this);
    return 0;
  }
  (**(code **)(*piVar3 + 0x38))(local_80,piVar3);
  uVar5 = ((int (*)())GetGlobalPoolAllocator)();
  iVar11 = ((int (*)())TPoolAllocator__allocate)(uVar5);
  local_80[0] = &PTR__TType_a7b7d4d0;
  piVar2 = (int *)(**(code **)(*piVar3 + 0x1c))(piVar3);
  iVar1 = (**(code **)(*piVar2 + 100))();
  if (*(int *)(iVar1 + 8) - *(int *)(iVar1 + 4) >> 2 == 1) {
    piVar2 = (int *)(**(code **)(*piVar3 + 0x1c))(piVar3);
    iVar1 = (**(code **)(*piVar2 + 100))();
    piVar2 = (int *)(**(code **)(*(int *)**(undefined4 **)(iVar1 + 4) + 0x14))();
    iVar1 = (**(code **)(*piVar2 + 0x18))();
    if (iVar1 == 0) goto LAB_97b9fc00;
    (**(code **)(*piVar3 + 0x38))(local_80,piVar3);
    iVar1 = TIntermediate__parseConstTree
                      (*(undefined4 *)this,param_3,piVar3,iVar11,piVar3[0xc],
                       *(undefined4 *)(this + 4),local_80,1);
  }
  else {
LAB_97b9fc00:
    (**(code **)(*piVar3 + 0x38))(local_80,piVar3);
    iVar1 = TIntermediate__parseConstTree
                      (*(undefined4 *)this,param_3,piVar3,iVar11,piVar3[0xc],
                       *(undefined4 *)(this + 4),local_80,0);
  }
  local_80[0] = &PTR__TType_a7b7d4d0;
  if (iVar1 != 0) {
    return 0;
  }
  iVar1 = *piVar3;
LAB_97b9fc60:
  (**(code **)(iVar1 + 0x38))(local_80,piVar3);
  uVar6 = TIntermediate__addConstantUnion
                    (*(unsigned char **)this,(unsigned char *)(iVar11 + iVar8 * 4),(int)local_80);
  return uVar6;
}

/* TParseContext__initializeExtensionBehavior @ 0x97b9fcd8 (380 bytes) */
int TParseContext__initializeExtensionBehavior(this)
  unsigned char * this;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  char in_RESERVE;
  byte in_cr0;
  undefined4 local_d0;
  void *local_cc;
  undefined4 local_c0 [4];
  int local_b0 [4];
  int local_a0;
  int local_90 [4];
  int local_80;
  undefined4 local_70;
  int local_6c;
  undefined4 local_68;
  int local_60 [4];
  undefined4 local_50;
  undefined4 local_40;
  uint local_30;
  uint local_2c [4];
  
  local_c0[0] = ((int (*)())GetGlobalPoolAllocator)();
  std__string__string((unsigned char *)&local_d0,"GL_ARB_texture_rectangle",(unsigned char *)local_c0);
  std___Rb_tree_std__string_std__pair_std__string_const_TBehavior__std___Select1st_std__pair_std__string_const_TBehavior___std__less_std__string__pool_allocator_std__pair_std__string_const_TBehavior_____lower_bound((unsigned char *)local_b0);
  iVar2 = local_b0[0];
  local_a0 = *(int *)(this + 0x34);
  if (local_b0[0] != local_a0) {
    puVar4 = local_2c;
    uVar5 = *(uint *)((int)local_cc + -0xc);
    local_30 = uVar5;
    uVar6 = *(uint *)(*(int *)(local_b0[0] + 0x14) + -0xc);
    local_2c[0] = uVar6;
    if (uVar5 <= uVar6) {
      puVar4 = &local_30;
    }
    iVar3 = _memcmp(local_cc,*(void **)(local_b0[0] + 0x14),*puVar4);
    in_cr0 = (iVar3 == 0) << 1;
    if (iVar3 == 0) {
      iVar3 = uVar5 - uVar6;
    }
    if (-1 < iVar3) goto LAB_97b9fe04;
  }
  local_80 = iVar2;
  std__string__string((unsigned char *)&local_70,(unsigned char *)&local_d0);
  local_68 = 0;
  local_60[0] = local_80;
  std___Rb_tree_std__string_std__pair_std__string_const_TBehavior__std___Select1st_std__pair_std__string_const_TBehavior___std__less_std__string__pool_allocator_std__pair_std__string_const_TBehavior_____insert_unique(local_90,this + 0x30,local_60,(unsigned char *)&local_70);
  piVar1 = (int *)(local_6c + -4);
  local_b0[0] = local_90[0];
  local_50 = local_70;
  do {
    iVar3 = *piVar1;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar3 + -1,0,piVar1);
      *piVar1 = iVar2;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  iVar2 = local_90[0];
  if (iVar3 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(local_6c + -0xc));
    iVar2 = local_b0[0];
  }
LAB_97b9fe04:
  *(undefined4 *)(iVar2 + 0x18) = 1;
  piVar1 = (int *)((int)local_cc + -4);
  local_40 = local_d0;
  do {
    iVar2 = *piVar1;
    if (in_RESERVE != '\0') {
      iVar3 = storeWordConditionalIndexed(iVar2 + -1,0,piVar1);
      *piVar1 = iVar3;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar2 < 1) {
    std__string___Rep___M_destroy((unsigned char *)((int)local_cc + -0xc));
  }
  return;
}

/* InitializeGlobalPools @ 0x97b9fe54 (144 bytes) */
int InitializeGlobalPools()
{
  unsigned char * this;
  
  if (_gPollAllocThreadData == (undefined4 *)0x0) {
    this = operator_new(0x34);
    ((int (*)())TPoolAllocator__TPoolAllocator)(this,true,0x2000,0x10);
    _gPollAllocThreadData = operator_new(8);
    _gPollAllocThreadData[1] = 0;
    *_gPollAllocThreadData = this;
    _gPollAllocThreadData[1] = 0;
    ((int (*)())TPoolAllocator__push)(this);
    return;
  }
  return;
}

/* FreeGlobalPools @ 0x97b9fee4 (112 bytes) */
int FreeGlobalPools()
{
  unsigned char * pTVar1;
  
  if (_gPollAllocThreadData != (void *)0x0) {
    pTVar1 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
    ((int (*)())TPoolAllocator__popAll)(pTVar1);
    pTVar1 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
    if (pTVar1 != (unsigned char *)0x0) {
      ((int (*)())TPoolAllocator___TPoolAllocator)(pTVar1);
      operator_delete(pTVar1);
    }
    operator_delete(_gPollAllocThreadData);
    _gPollAllocThreadData = (void *)0x0;
  }
  return;
}

/* GetGlobalPoolAllocator @ 0x97b9ff54 (32 bytes) */
int GetGlobalPoolAllocator()
{
  return *_gPollAllocThreadData;
}

/* SetGlobalPoolAllocatorPtr @ 0x97b9ff74 (32 bytes) */
int SetGlobalPoolAllocatorPtr(param_1)
  unsigned char * param_1;
{
  *_gPollAllocThreadData = param_1;
  return;
}

/* GetCompilerPoolAllocator @ 0x97b9ff94 (32 bytes) */
int GetCompilerPoolAllocator()
{
  return _gPollAllocThreadData + 4;
}

/* TPoolAllocator__TPoolAllocator @ 0x97b9ffb4 (4 bytes) */
int TPoolAllocator__TPoolAllocator(this, param_1, param_2, param_3)
  unsigned char * this;
  int param_1;
  int param_2;
  int param_3;
{
  uint uVar1;
  undefined3 in_register_00000010;
  
  *(uint *)this = CONCAT31(in_register_00000010,param_1);
  *(int *)(this + 8) = param_3;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  *(int *)(this + 4) = param_2;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  if ((uint)param_2 < 0x1000) {
    *(undefined4 *)(this + 4) = 0x1000;
  }
  uVar1 = *(uint *)(this + 8);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(this + 4);
  *(uint *)(this + 8) = uVar1 & 0xfffffffc;
  if ((uVar1 & 0xfffffffc) < 4) {
    *(undefined4 *)(this + 8) = 4;
  }
  uVar1 = 1;
  if (1 < *(uint *)(this + 8)) {
    do {
      uVar1 = uVar1 << 1;
    } while (uVar1 < *(uint *)(this + 8));
  }
  *(uint *)(this + 8) = uVar1;
  *(uint *)(this + 0x10) = uVar1 + 7 & ~(uVar1 - 1);
  *(uint *)(this + 0xc) = uVar1 - 1;
  return;
}

/* TPoolAllocator__TPoolAllocator_97b9ffb8 @ 0x97b9ffb8 (4 bytes) */
int TPoolAllocator__TPoolAllocator_97b9ffb8(this, param_1, param_2, param_3)
  unsigned char * this;
  int param_1;
  int param_2;
  int param_3;
{
  uint uVar1;
  undefined3 in_register_00000010;
  
  *(uint *)this = CONCAT31(in_register_00000010,param_1);
  *(int *)(this + 8) = param_3;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  *(int *)(this + 4) = param_2;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  if ((uint)param_2 < 0x1000) {
    *(undefined4 *)(this + 4) = 0x1000;
  }
  uVar1 = *(uint *)(this + 8);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(this + 4);
  *(uint *)(this + 8) = uVar1 & 0xfffffffc;
  if ((uVar1 & 0xfffffffc) < 4) {
    *(undefined4 *)(this + 8) = 4;
  }
  uVar1 = 1;
  if (1 < *(uint *)(this + 8)) {
    do {
      uVar1 = uVar1 << 1;
    } while (uVar1 < *(uint *)(this + 8));
  }
  *(uint *)(this + 8) = uVar1;
  *(uint *)(this + 0x10) = uVar1 + 7 & ~(uVar1 - 1);
  *(uint *)(this + 0xc) = uVar1 - 1;
  return;
}

/* TPoolAllocator__TPoolAllocator_97b9ffbc @ 0x97b9ffbc (152 bytes) */
int TPoolAllocator__TPoolAllocator_97b9ffbc(this, param_1, param_2, param_3)
  unsigned char * this;
  int param_1;
  int param_2;
  int param_3;
{
  uint uVar1;
  undefined3 in_register_00000010;
  
  *(uint *)this = CONCAT31(in_register_00000010,param_1);
  *(int *)(this + 8) = param_3;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  *(int *)(this + 4) = param_2;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  if ((uint)param_2 < 0x1000) {
    *(undefined4 *)(this + 4) = 0x1000;
  }
  uVar1 = *(uint *)(this + 8);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(this + 4);
  *(uint *)(this + 8) = uVar1 & 0xfffffffc;
  if ((uVar1 & 0xfffffffc) < 4) {
    *(undefined4 *)(this + 8) = 4;
  }
  uVar1 = 1;
  if (1 < *(uint *)(this + 8)) {
    do {
      uVar1 = uVar1 << 1;
    } while (uVar1 < *(uint *)(this + 8));
  }
  *(uint *)(this + 8) = uVar1;
  *(uint *)(this + 0x10) = uVar1 + 7 & ~(uVar1 - 1);
  *(uint *)(this + 0xc) = uVar1 - 1;
  return;
}

/* TPoolAllocator___TPoolAllocator @ 0x97ba0054 (8 bytes) */
int TPoolAllocator___TPoolAllocator(this)
  unsigned char * this;
{
  ~TPoolAllocator(this);
  return;
}

/* TPoolAllocator___TPoolAllocator_97ba005c @ 0x97ba005c (8 bytes) */
int TPoolAllocator___TPoolAllocator_97ba005c(this)
  unsigned char * this;
{
  ~TPoolAllocator(this);
  return;
}

/* TPoolAllocator___TPoolAllocator_97ba0064 @ 0x97ba0064 (184 bytes) */
int TPoolAllocator___TPoolAllocator_97ba0064(this)
  unsigned char * this;
{
  undefined4 *puVar1;
  int iVar2;
  void *pvVar3;
  
  if (*(int *)this == 0) {
    puVar1 = *(void **)(this + 0x1c);
    while (puVar1 != (void *)0x0) {
      pvVar3 = (void *)*puVar1;
      operator_delete__(puVar1);
      *(void **)(this + 0x1c) = pvVar3;
      puVar1 = pvVar3;
    }
  }
  puVar1 = *(void **)(this + 0x18);
  while (puVar1 != (void *)0x0) {
    pvVar3 = (void *)*puVar1;
    operator_delete__(puVar1);
    *(void **)(this + 0x18) = pvVar3;
    puVar1 = pvVar3;
  }
  for (iVar2 = *(int *)(this + 0x20); iVar2 != *(int *)(this + 0x24); iVar2 = iVar2 + 8) {
  }
  iVar2 = *(int *)(this + 0x28) - (int)*(void **)(this + 0x20) >> 3;
  if (iVar2 != 0) {
    std____default_alloc_template_true_0___deallocate(*(void **)(this + 0x20),iVar2 << 3);
  }
  return;
}

/* TAllocation__checkGuardBlock @ 0x97ba011c (4 bytes) */
int TAllocation__checkGuardBlock(param_1, param_2, param_3)
  uchar *param_1;
  int param_2;
  char *param_3;
{
  return;
}

/* TPoolAllocator__push @ 0x97ba0120 (136 bytes) */
int TPoolAllocator__push(this)
  unsigned char * this;
{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_20;
  undefined4 local_1c;
  
  puVar1 = *(undefined4 **)(this + 0x24);
  local_30 = *(undefined4 *)(this + 0x14);
  local_2c = *(undefined4 *)(this + 0x1c);
  if (puVar1 == *(undefined4 **)(this + 0x28)) {
    local_20 = local_30;
    local_1c = local_2c;
    std__vector_TPoolAllocator__tAllocState_std__allocator_TPoolAllocator__tAllocState_____M_insert_aux(this + 0x20,*(undefined4 *)(this + 0x24),&local_30);
  }
  else {
    iVar2 = 0;
    if (puVar1 != (undefined4 *)0x0) {
      puVar1[1] = local_2c;
      *puVar1 = local_30;
      iVar2 = *(int *)(this + 0x24);
    }
    *(int *)(this + 0x24) = iVar2 + 8;
  }
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(this + 4);
  return;
}

/* TPoolAllocator__pop @ 0x97ba01a8 (160 bytes) */
int TPoolAllocator__pop(this)
  unsigned char * this;
{
  undefined4 *puVar1;
  void *pvVar2;
  void *pvVar3;
  
  if ((uint)(*(int *)(this + 0x24) - *(int *)(this + 0x20)) >> 3 != 0) {
    pvVar2 = *(void **)(*(int *)(this + 0x24) + -4);
    *(undefined4 *)(this + 0x14) = *(undefined4 *)(*(int *)(this + 0x24) + -8);
    puVar1 = *(void **)(this + 0x1c);
    while (puVar1 != pvVar2) {
      pvVar3 = (void *)*puVar1;
      if ((uint)puVar1[1] < 2) {
        *puVar1 = *(undefined4 *)(this + 0x18);
        *(undefined4 *)(this + 0x18) = *(undefined4 *)(this + 0x1c);
      }
      else {
        operator_delete__(puVar1);
      }
      *(void **)(this + 0x1c) = pvVar3;
      puVar1 = pvVar3;
    }
    *(int *)(this + 0x24) = *(int *)(this + 0x24) + -8;
  }
  return;
}

/* TPoolAllocator__popAll @ 0x97ba0248 (76 bytes) */
int TPoolAllocator__popAll(this)
  unsigned char * this;
{
  while ((uint)(*(int *)(this + 0x24) - *(int *)(this + 0x20)) >> 3 != 0) {
    pop(this);
  }
  return;
}

/* TPoolAllocator__allocate @ 0x97ba0294 (328 bytes) */
int TPoolAllocator__allocate(this, param_1)
  unsigned char * this;
  ulong param_1;
{
  float fVar1;
  undefined4 uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  ulong uVar8;
  
  fVar1 = TAllocation__guardBlockSize;
  iVar6 = *(int *)(this + 0x14);
  iVar7 = param_1 + (int)TAllocation__guardBlockSize * 2;
  uVar3 = *(ulong *)(this + 4);
  uVar5 = iVar6 + iVar7;
  *(int *)(this + 0x2c) = *(int *)(this + 0x2c) + 1;
  *(ulong *)(this + 0x30) = *(int *)(this + 0x30) + param_1;
  if (uVar3 < uVar5) {
    uVar8 = iVar7 + *(int *)(this + 0x10);
    if (uVar3 < uVar8) {
      puVar4 = operator_new__(uVar8);
      iVar6 = 0;
      if (puVar4 != (undefined4 *)0x0) {
        uVar5 = *(uint *)(this + 4);
        *puVar4 = *(undefined4 *)(this + 0x1c);
        puVar4[1] = ((uVar8 + uVar5) - 1) / uVar5;
        iVar6 = (int)puVar4 + *(int *)(this + 0x10);
        *(undefined4 **)(this + 0x1c) = puVar4;
        *(undefined4 *)(this + 0x14) = *(undefined4 *)(this + 4);
      }
    }
    else {
      puVar4 = *(undefined4 **)(this + 0x18);
      if (puVar4 == (undefined4 *)0x0) {
        puVar4 = operator_new__(uVar3);
        if (puVar4 == (undefined4 *)0x0) {
          return 0;
        }
      }
      else {
        *(undefined4 *)(this + 0x18) = *puVar4;
      }
      uVar2 = *(undefined4 *)(this + 0x1c);
      puVar4[1] = 1;
      *puVar4 = uVar2;
      iVar6 = (int)puVar4 + (int)TAllocation__guardBlockSize + *(int *)(this + 0x10);
      *(uint *)(this + 0x14) =
           *(int *)(this + 0x10) + iVar7 + *(uint *)(this + 0xc) & ~*(uint *)(this + 0xc);
      *(undefined4 **)(this + 0x1c) = puVar4;
    }
  }
  else {
    *(uint *)(this + 0x14) = uVar5 + *(uint *)(this + 0xc) & ~*(uint *)(this + 0xc);
    iVar6 = *(int *)(this + 0x1c) + iVar6 + (int)fVar1;
  }
  return iVar6;
}

/* TAllocation__checkAllocList @ 0x97ba03dc (156 bytes) */
int TAllocation__checkAllocList(this)
  unsigned char * this;
{
  byte bVar1;
  byte bVar2;
  float fVar3;
  undefined4 uVar4;
  
  fVar3 = guardBlockSize;
  bVar2 = guardBlockEndVal;
  bVar1 = guardBlockBeginVal;
  for (; this != (unsigned char *)0x0; this = *(unsigned char **)(this + 8)) {
    uVar4 = *(undefined4 *)(this + 4);
    ((int (*)())TAllocation__checkGuardBlock)((uchar *)this,(uchar)uVar4,(char *)(uint)bVar1);
    ((int (*)())TAllocation__checkGuardBlock)((uchar *)this,(uchar)uVar4 + SUB41(fVar3,0) + (char)*(undefined4 *)this,
                    (char *)(uint)bVar2);
  }
  return;
}

/* QualifierWritten @ 0x97ba0478 (156 bytes) */
int QualifierWritten(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_20 = 0;
  local_50 = DAT_a7b7ba24;
  local_40 = DAT_a7b7ba20;
  local_24 = 1;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 1;
  local_28 = 0;
  if (param_1 != (int *)0x0) {
    local_1c = param_2;
    (**(code **)(*param_1 + 8))(param_1,&local_50);
  }
  return local_20;
}

/* AliveSymbol @ 0x97ba0514 (76 bytes) */
int AliveSymbol(param_1, param_2)
  unsigned char * param_1;
  unsigned char * param_2;
{
  int iVar1;
  
  iVar1 = (**(code **)(*(int *)param_1 + 0x44))();
  if (iVar1 == *(int *)(param_2 + 0x34)) {
    *(undefined4 *)(param_2 + 0x30) = 1;
  }
  return;
}

/* AliveSelection @ 0x97ba0560 (16 bytes) */
int AliveSelection(param_1, param_2, param_3)
  int param_1;
  unsigned char * param_2;
  unsigned char * param_3;
{
  return *(int *)(param_3 + 0x30) == 0;
}

/* RemoveSymbol @ 0x97ba0570 (24 bytes) */
int RemoveSymbol(param_1, param_2)
  unsigned char * param_1;
  unsigned char * param_2;
{
  if (param_1 == (unsigned char *)0x0) {
    return;
  }
                    
                    
  (**(code **)(*(int *)param_1 + 0x30))();
  return;
}

/* RemoveBinary @ 0x97ba0588 (56 bytes) */
int RemoveBinary(param_1, param_2, param_3)
  int param_1;
  unsigned char * param_2;
  unsigned char * param_3;
{
  if (param_2 != (unsigned char *)0x0) {
    (**(code **)(*(int *)param_2 + 0x30))();
  }
  return 1;
}

/* RemoveUnary @ 0x97ba05c0 (56 bytes) */
int RemoveUnary(param_1, param_2, param_3)
  int param_1;
  unsigned char * param_2;
  unsigned char * param_3;
{
  if (param_2 != (unsigned char *)0x0) {
    (**(code **)(*(int *)param_2 + 0x30))();
  }
  return 1;
}

/* RemoveAggregate @ 0x97ba05f8 (56 bytes) */
int RemoveAggregate(param_1, param_2, param_3)
  int param_1;
  unsigned char * param_2;
  unsigned char * param_3;
{
  if (param_2 != (unsigned char *)0x0) {
    (**(code **)(*(int *)param_2 + 0x30))();
  }
  return 1;
}

/* RemoveSelection @ 0x97ba0630 (56 bytes) */
int RemoveSelection(param_1, param_2, param_3)
  int param_1;
  unsigned char * param_2;
  unsigned char * param_3;
{
  if (param_2 != (unsigned char *)0x0) {
    (**(code **)(*(int *)param_2 + 0x30))();
  }
  return 1;
}

/* RemoveConstantUnion @ 0x97ba0668 (24 bytes) */
int RemoveConstantUnion(param_1, param_2)
  unsigned char * param_1;
  unsigned char * param_2;
{
  if (param_1 == (unsigned char *)0x0) {
    return;
  }
                    
                    
  (**(code **)(*(int *)param_1 + 0x30))();
  return;
}

/* RemoveAllTreeNodes @ 0x97ba0680 (168 bytes) */
int RemoveAllTreeNodes(param_1)
  unsigned char * param_1;
{
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  local_2c = DAT_a7b7ba3c;
  local_38 = DAT_a7b7ba38;
  local_3c = DAT_a7b7ba34;
  local_30 = DAT_a7b7ba30;
  local_18 = 1;
  local_40 = DAT_a7b7ba2c;
  local_34 = DAT_a7b7ba28;
  local_1c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_14 = 0;
  (**(code **)(*(int *)param_1 + 8))(param_1,&local_40);
  return;
}

/* GetSymbolTable @ 0x97ba0728 (132 bytes) */
int GetSymbolTable(param_1)
  int param_1;
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = &GetSymbolTable__SymbolTables;
  if (GetSymbolTable__SymbolTables == 0) {
    do {
      puVar2 = operator_new(0x10);
      *puVar2 = 0;
      puVar2[1] = 0;
      puVar2[2] = 0;
      puVar2[3] = 0;
      *puVar1 = puVar2;
      puVar1 = puVar1 + 1;
    } while ((int)puVar1 < -0x584817f7);
  }
  return (&GetSymbolTable__SymbolTables)[param_1];
}

/* GetResources @ 0x97ba07ac (108 bytes) */
int GetResources()
{
  DAT_a7b7e838 = 4;
  DAT_a7b7e810 = 6;
  DAT_a7b7e818 = 8;
  DAT_a7b7e824 = 0x20;
  DAT_a7b7e828 = 0;
  DAT_a7b7e830 = 0x10;
  DAT_a7b7e834 = 0x200;
  GetResources__Resources = 8;
  DAT_a7b7e814 = 8;
  DAT_a7b7e81c = 0x10;
  DAT_a7b7e820 = 0x200;
  DAT_a7b7e82c = 0x10;
  return &GetResources__Resources;
}

/* _ShInitialize @ 0x97ba0818 (360 bytes) */
int _ShInitialize()
{
  int iVar1;
  int *piVar2;
  int iVar3;
  unsigned char * pTVar4;
  unsigned char * this;
  undefined4 uVar5;
  undefined4 uVar6;
  char in_RESERVE;
  byte in_cr0;
  undefined *local_40;
  undefined4 local_3c;
  undefined *local_38;
  undefined4 local_34;
  
  local_40 = PTR__S_empty_rep_storage_a7b7c0f0;
  piVar2 = (int *)(PTR__S_empty_rep_storage_a7b7c0f0 + 8);
  do {
    if (in_RESERVE != '\0') {
      iVar3 = storeWordConditionalIndexed(*piVar2 + 1,0,piVar2);
      *piVar2 = iVar3;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  local_40 = local_40 + 0xc;
  local_3c = 4;
  do {
    if (in_RESERVE != '\0') {
      iVar3 = storeWordConditionalIndexed(*piVar2 + 1,0,piVar2);
      *piVar2 = iVar3;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  local_34 = 4;
  local_38 = local_40;
  _pthread_mutex_lock((pthread_mutex_t *)&_glsl_allocator_lock);
  iVar3 = InitProcess();
  uVar6 = 1;
  if (iVar3 == 0) {
    uVar6 = 0;
  }
  else if (_PerProcessGPA == (unsigned char *)0x0) {
    pTVar4 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
    this = operator_new(0x34);
    ((int (*)())TPoolAllocator__TPoolAllocator)(this,true,0x2000,0x10);
    _PerProcessGPA = this;
    ((int (*)())TPoolAllocator__push)();
    ((int (*)())SetGlobalPoolAllocatorPtr)(_PerProcessGPA);
    uVar5 = ((int (*)())GetResources)();
    ((int (*)())generateBuiltInSymbolTable)(uVar5,&local_40,0,4);
    ((int (*)())SetGlobalPoolAllocatorPtr)(pTVar4);
  }
  _pthread_mutex_unlock((pthread_mutex_t *)&_glsl_allocator_lock);
  piVar2 = (int *)(local_38 + -4);
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar3 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(local_38 + -0xc));
  }
  piVar2 = (int *)(local_40 + -4);
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar3 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(local_40 + -0xc));
  }
  return uVar6;
}

/* _ShConstructCompiler @ 0x97ba0980 (32 bytes) */
int _ShConstructCompiler()
{
  ConstructCompiler();
  return;
}

/* _ShDestruct @ 0x97ba09a4 (200 bytes) */
int _ShDestruct(param_1)
  int *param_1;
{
  int iVar1;
  unsigned char * pTVar2;
  unsigned char * pTVar3;
  
  if (param_1 != (int *)0x0) {
    _pthread_mutex_lock((pthread_mutex_t *)&_glsl_allocator_lock);
    iVar1 = (**(code **)(*param_1 + 8))(param_1);
    if (iVar1 == 0) {
      iVar1 = (**(code **)(*param_1 + 0xc))(param_1);
      if (iVar1 != 0) {
        pTVar3 = (unsigned char *)(**(code **)(*param_1 + 0xc))(param_1);
        DeleteLinker(pTVar3);
      }
    }
    else {
      pTVar2 = (unsigned char *)(**(code **)(*param_1 + 8))(param_1);
      DeleteCompiler(pTVar2);
    }
    _pthread_mutex_unlock((pthread_mutex_t *)&_glsl_allocator_lock);
    return;
  }
  return;
}

/* _ShFinalize @ 0x97ba0a6c (112 bytes) */
int _ShFinalize()
{
  unsigned char * pTVar1;
  
  if (_PerProcessGPA != (unsigned char *)0x0) {
    ((int (*)())TPoolAllocator__popAll)();
    pTVar1 = _PerProcessGPA;
    if (_PerProcessGPA != (unsigned char *)0x0) {
      ((int (*)())TPoolAllocator___TPoolAllocator)(_PerProcessGPA);
      operator_delete(pTVar1);
    }
    _PerProcessGPA = (unsigned char *)0x0;
  }
  DetachProcess();
  return 1;
}

/* generateBuiltInSymbolTable @ 0x97ba0adc (112 bytes) */
int generateBuiltInSymbolTable(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  unsigned char aTStack_30 [28];
  
  TBuiltIns__initialize(aTStack_30);
  ((int (*)())initializeSymbolTable)(aTStack_30,0,param_2,param_1,param_3);
  ((int (*)())initializeSymbolTable)(aTStack_30,1,param_2,param_1,param_3);
  return 1;
}

/* initializeSymbolTable @ 0x97ba0b4c (936 bytes) */
int initializeSymbolTable(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  char *param_3;
  undefined4 param_4;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  ulong uVar5;
  ulong *puVar6;
  undefined4 *puVar7;
  uint uVar8;
  char **ppcVar9;
  undefined4 uVar10;
  uint uVar11;
  char in_RESERVE;
  byte in_cr0;
  byte bVar12;
  char **local_130;
  int *local_12c;
  char *local_128;
  uint local_124;
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_10c;
  ulong local_100;
  undefined4 *local_fc;
  int local_f8;
  undefined4 local_f0;
  undefined4 local_ec;
  ulong local_e8;
  undefined4 *local_e4;
  int local_e0;
  undefined4 local_d8;
  int local_d4;
  ulong local_c0;
  ulong local_b0;
  undefined4 local_a0;
  ulong local_90;
  ulong *local_80 [4];
  undefined4 local_70;
  undefined4 uStack_60;
  undefined4 uStack_50;
  char *local_40 [7];
  
  local_40[0] = param_3;
  piVar4 = (int *)((int (*)())GetSymbolTable)(param_2);
  local_130 = local_40;
  local_120 = 0;
  local_11c = 0;
  local_118 = 0;
  local_114 = 0;
  local_110 = 0;
  local_10c = 0;
  local_12c = piVar4;
  local_128 = param_3;
  local_124 = param_2;
  local_100 = ((int (*)())GetGlobalPoolAllocator)();
  local_fc = (undefined4 *)0x0;
  local_c0 = local_100;
  local_fc = (undefined4 *)((int (*)())TPoolAllocator__allocate)(local_100);
  local_f8 = 0;
  *local_fc = 0;
  local_fc[1] = 0;
  local_fc[2] = local_fc;
  local_fc[3] = local_fc;
  local_f0 = 1;
  local_ec = 0;
  local_e8 = ((int (*)())GetGlobalPoolAllocator)();
  local_e4 = (undefined4 *)0x0;
  local_b0 = local_e8;
  local_e4 = (undefined4 *)((int (*)())TPoolAllocator__allocate)(local_e8);
  local_e0 = 0;
  *local_e4 = 0;
  local_e4[1] = 0;
  local_d4 = DAT_a7b7ba70;
  local_e4[2] = local_e4;
  piVar2 = (int *)(local_d4 + 8);
  local_e4[3] = local_e4;
  do {
    if (in_RESERVE != '\0') {
      iVar3 = storeWordConditionalIndexed(*piVar2 + 1,0,piVar2);
      *piVar2 = iVar3;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  local_d8 = ((int (*)())GetGlobalPoolAllocator)();
  local_d4 = local_d4 + 0xc;
  local_a0 = local_d8;
  setInitialState();
  iVar3 = piVar4[1] - *piVar4 >> 2;
  bVar12 = (iVar3 != 0) << 1;
  if ((iVar3 != 0) && (iVar3 != 1)) {
    ___eprintf("%s:%u: failed assertion `%s\'\n",
               "/SourceCache/OpenGL/OpenGL-4.7.14/GLProgrammability/glslang/MachineIndependent/ShaderLang.cpp"
               ,0x110,"symbolTable->isEmpty() || symbolTable->atSharedBuiltInLevel()");
  }
  uVar5 = ((int (*)())GetGlobalPoolAllocator)();
  puVar6 = (ulong *)((int (*)())TPoolAllocator__allocate)(uVar5);
  local_90 = ((int (*)())GetGlobalPoolAllocator)();
  *puVar6 = local_90;
  puVar6[1] = 0;
  puVar7 = (undefined4 *)((int (*)())TPoolAllocator__allocate)(local_90);
  puVar6[2] = 0;
  puVar6[1] = (ulong)puVar7;
  *puVar7 = 0;
  *(undefined4 *)(puVar6[1] + 4) = 0;
  *(ulong *)(puVar6[1] + 8) = puVar6[1];
  *(ulong *)(puVar6[1] + 0xc) = puVar6[1];
  piVar2 = (int *)piVar4[1];
  local_80[0] = puVar6;
  if (piVar2 == (int *)piVar4[2]) {
    std__vector_TSymbolTableLevel__std__allocator_TSymbolTableLevel______M_insert_aux
              (piVar4,piVar2,local_80);
  }
  else {
    iVar3 = 0;
    if (piVar2 != (int *)0x0) {
      *piVar2 = (int)puVar6;
      iVar3 = piVar4[1];
    }
    piVar4[1] = iVar3 + 4;
  }
  iVar3 = _InitPreprocessor();
  if (iVar3 == 0) {
    uVar8 = TBuiltIns__getNumStringArrays(param_1);
    uVar11 = 0;
    if (uVar8 != 0) {
LAB_97ba0e34:
      ppcVar9 = (char **)TBuiltIns__getStringArray(param_1,local_124);
      piVar2 = (int *)TBuiltIns__getStringSizeArray(param_1,local_124);
      iVar3 = TBuiltIns__getNumStrings(param_1,local_124);
      iVar3 = PaParseStrings(ppcVar9,piVar2,iVar3,0,(unsigned char *)&local_130);
      if (iVar3 == 0) goto LAB_97ba0fd8;
                    
      TInfoSinkBase__append(param_3);
      TInfoSinkBase__append(param_3);
      TInfoSinkBase__append(param_3);
      _FinalizePreprocessor();
      piVar2 = (int *)(local_d4 + -4);
      do {
        iVar3 = *piVar2;
        if (in_RESERVE != '\0') {
          iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
          *piVar2 = iVar1;
          bVar12 = 2;
        }
        uStack_60 = local_d8;
      } while (!(bool)(bVar12 >> 1 & 1));
      goto joined_r0x97ba0f4c;
    }
LAB_97ba0fe4:
    IdentifyBuiltIns(local_124,piVar4,param_4);
    IdentifyBuiltIns(local_124,piVar4);
    _FinalizePreprocessor();
    piVar2 = (int *)(local_d4 + -4);
    local_70 = local_d8;
    do {
      iVar3 = *piVar2;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
        *piVar2 = iVar1;
        bVar12 = 2;
      }
    } while (!(bool)(bVar12 >> 1 & 1));
    if (iVar3 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_d4 + -0xc));
    }
    if (local_e0 != 0) {
      std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string______M_erase((unsigned char *)&local_e8);
      local_e4[2] = local_e4;
      local_e4[1] = 0;
      local_e4[3] = local_e4;
      local_e0 = 0;
    }
    if (local_f8 != 0) {
      std___Rb_tree_std__string_std__pair_std__string_const_TBehavior__std___Select1st_std__pair_std__string_const_TBehavior___std__less_std__string__pool_allocator_std__pair_std__string_const_TBehavior______M_erase((unsigned char *)&local_100);
      local_fc[2] = local_fc;
      local_fc[1] = 0;
      local_fc[3] = local_fc;
    }
    uVar10 = 1;
  }
  else {
                    
    TInfoSinkBase__append(param_3);
    TInfoSinkBase__append(param_3);
    TInfoSinkBase__append(param_3);
    piVar2 = (int *)(local_d4 + -4);
    do {
      iVar3 = *piVar2;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
        *piVar2 = iVar1;
        bVar12 = 2;
      }
      uStack_50 = local_d8;
    } while (!(bool)(bVar12 >> 1 & 1));
joined_r0x97ba0f4c:
    if (iVar3 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_d4 + -0xc));
    }
    if (local_e0 != 0) {
      std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string______M_erase((unsigned char *)&local_e8);
      local_e4[2] = local_e4;
      local_e4[1] = 0;
      local_e4[3] = local_e4;
      local_e0 = 0;
    }
    if (local_f8 != 0) {
      std___Rb_tree_std__string_std__pair_std__string_const_TBehavior__std___Select1st_std__pair_std__string_const_TBehavior___std__less_std__string__pool_allocator_std__pair_std__string_const_TBehavior______M_erase((unsigned char *)&local_100);
      local_fc[2] = local_fc;
      local_fc[1] = 0;
      local_fc[3] = local_fc;
    }
    uVar10 = 0;
  }
  return uVar10;
LAB_97ba0fd8:
  uVar11 = uVar11 + 1;
  if (uVar8 <= uVar11) goto LAB_97ba0fe4;
  goto LAB_97ba0e34;
}

/* _ShCompile @ 0x97ba10c8 (1888 bytes) */
int _ShCompile(param_1, param_2, param_3, param_4, param_5)
  int *param_1;
  char **param_2;
  int param_3;
  int param_4;
  uint param_5;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  undefined4 *puVar6;
  ulong *puVar7;
  unsigned char * psVar8;
  unsigned char * pTVar9;
  uint uVar10;
  ulong uVar11;
  void *pvVar12;
  uint uVar13;
  char in_RESERVE;
  byte bVar14;
  void *local_180;
  int *local_17c;
  int *local_178;
  undefined4 local_174;
  ulong local_160;
  ulong *local_150 [4];
  int *local_140;
  void **local_13c;
  unsigned char * local_138;
  int local_134;
  int local_130;
  int local_12c;
  undefined4 local_128;
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_11c;
  ulong local_110;
  undefined4 *local_10c;
  int local_108;
  undefined4 local_100;
  undefined4 local_fc;
  ulong local_f8;
  undefined4 *local_f4;
  int local_f0;
  undefined4 local_e8;
  int local_e4;
  ulong local_d0;
  ulong local_c0;
  undefined4 local_b0;
  ulong local_a0;
  undefined4 uStack_90;
  int iStack_8c;
  char acStack_80 [16];
  undefined4 auStack_70 [4];
  undefined4 uStack_60;
  undefined4 local_50;
  int local_40;
  char *local_3c [3];
  
  local_3c[0] = (char *)GetPreprocessorBuiltinString();
  if (param_1 == (int *)0x0) {
    return 0;
  }
  piVar5 = (int *)(**(code **)(*param_1 + 8))(param_1);
  bVar14 = (piVar5 == (int *)0x0) << 1;
  if (piVar5 == (int *)0x0) {
    return 0;
  }
  _pthread_mutex_lock((pthread_mutex_t *)&_glsl_allocator_lock);
  ((int (*)())GetGlobalPoolAllocator)();
  ((int (*)())TPoolAllocator__push)();
  (**(code **)(*piVar5 + 0x18))(piVar5);
  uVar13 = *(uint *)piVar5[1];
  iVar3 = *(int *)(uVar13 - 0xc);
  uVar10 = *(uint *)piVar5[1];
  if (((*(int *)(uVar10 - 4) < 1) && (uVar10 <= uVar13)) && (uVar13 <= uVar10 + iVar3)) {
    std__string___M_replace_char_const__(0,uVar10,uVar10 + iVar3,uVar13,uVar13,0);
  }
  else {
    std__string___M_replace_safe_char_const__(0,uVar10,uVar10 + iVar3,uVar13,uVar13);
  }
  uVar11 = *(ulong *)(piVar5[1] + 8);
  std__string__replace(piVar5[1] + 8,0,*(char **)(uVar11 - 0xc),uVar11);
  if (param_3 == 0) {
    _pthread_mutex_unlock((pthread_mutex_t *)&_glsl_allocator_lock);
    return 1;
  }
  local_40 = piVar5[1];
  puVar6 = (undefined4 *)((int (*)())GetSymbolTable)(piVar5[2]);
  local_180 = (void *)0x0;
  local_17c = (int *)0x0;
  local_178 = (int *)0x0;
  std__vector_TSymbolTableLevel__std__allocator_TSymbolTableLevel______M_insert_aux
            (&local_180,0,*puVar6);
  local_174 = puVar6[3];
  uVar11 = ((int (*)())GetGlobalPoolAllocator)();
  puVar7 = (ulong *)((int (*)())TPoolAllocator__allocate)(uVar11);
  local_160 = ((int (*)())GetGlobalPoolAllocator)();
  *puVar7 = local_160;
  puVar7[1] = 0;
  puVar6 = (undefined4 *)((int (*)())TPoolAllocator__allocate)(local_160);
  puVar7[2] = 0;
  puVar7[1] = (ulong)puVar6;
  *puVar6 = 0;
  *(undefined4 *)(puVar7[1] + 4) = 0;
  *(ulong *)(puVar7[1] + 8) = puVar7[1];
  *(ulong *)(puVar7[1] + 0xc) = puVar7[1];
  local_150[0] = puVar7;
  if (local_17c == local_178) {
    std__vector_TSymbolTableLevel__std__allocator_TSymbolTableLevel______M_insert_aux
              (&local_180,local_17c,local_150);
  }
  else {
    if (local_17c != (int *)0x0) {
      *local_17c = (int)puVar7;
    }
    local_17c = local_17c + 1;
  }
  local_138 = (unsigned char *)piVar5[1];
  local_134 = piVar5[2];
  local_140 = &local_40;
  local_130 = 0;
  local_12c = 0;
  local_128 = 0;
  local_124 = 0;
  local_120 = 0;
  local_11c = 0;
  local_13c = &local_180;
  local_110 = ((int (*)())GetGlobalPoolAllocator)();
  local_10c = (undefined4 *)0x0;
  local_d0 = local_110;
  local_10c = (undefined4 *)((int (*)())TPoolAllocator__allocate)(local_110);
  local_108 = 0;
  *local_10c = 0;
  local_10c[1] = 0;
  local_10c[2] = local_10c;
  local_10c[3] = local_10c;
  local_100 = 1;
  local_fc = 0;
  local_f8 = ((int (*)())GetGlobalPoolAllocator)();
  local_f4 = (undefined4 *)0x0;
  local_c0 = local_f8;
  local_f4 = (undefined4 *)((int (*)())TPoolAllocator__allocate)(local_f8);
  local_f0 = 0;
  *local_f4 = 0;
  local_e4 = DAT_a7b7ba70;
  local_f4[1] = 0;
  piVar4 = (int *)(local_e4 + 8);
  local_f4[2] = local_f4;
  local_f4[3] = local_f4;
  do {
    if (in_RESERVE != '\0') {
      iVar3 = storeWordConditionalIndexed(*piVar4 + 1,0,piVar4);
      *piVar4 = iVar3;
      bVar14 = 2;
    }
  } while (!(bool)(bVar14 >> 1 & 1));
  local_e8 = ((int (*)())GetGlobalPoolAllocator)();
  local_e4 = local_e4 + 0xc;
  local_b0 = local_e8;
  ((int (*)())TParseContext__initializeExtensionBehavior)();
  setInitialState();
  _InitPreprocessor();
  uVar11 = ((int (*)())GetGlobalPoolAllocator)();
  puVar7 = (ulong *)((int (*)())TPoolAllocator__allocate)(uVar11);
  local_a0 = ((int (*)())GetGlobalPoolAllocator)();
  *puVar7 = local_a0;
  puVar7[1] = 0;
  puVar6 = (undefined4 *)((int (*)())TPoolAllocator__allocate)(local_a0);
  puVar7[2] = 0;
  puVar7[1] = (ulong)puVar6;
  *puVar6 = 0;
  *(undefined4 *)(puVar7[1] + 4) = 0;
  *(ulong *)(puVar7[1] + 8) = puVar7[1];
  *(ulong *)(puVar7[1] + 0xc) = puVar7[1];
  local_150[0] = puVar7;
  if (local_17c == local_178) {
    std__vector_TSymbolTableLevel__std__allocator_TSymbolTableLevel______M_insert_aux
              (&local_180,local_17c,local_150);
  }
  else {
    if (local_17c != (int *)0x0) {
      *local_17c = (int)puVar7;
    }
    local_17c = local_17c + 1;
  }
  psVar8 = local_138;
  bVar1 = 3 < (uint)((int)local_17c - (int)local_180 >> 2);
  if (bVar1) {
    TInfoSinkBase__append((char *)local_138);
    TInfoSinkBase__append((char *)psVar8);
    TInfoSinkBase__append((char *)psVar8);
  }
  uVar10 = (uint)!bVar1;
  if (uVar10 == 1) {
    iVar3 = ((int (*)())TParseContext__insertBuiltInArrayAtGlobalLevel)();
    if (iVar3 == 0) {
      iVar3 = PaParseStrings(local_3c,(int *)0x0,1,0,(unsigned char *)&local_140);
      if (iVar3 != 0) {
        uVar10 = 0;
      }
    }
    else {
      uVar10 = 0;
    }
  }
  iVar3 = PaParseStrings(param_2,(int *)0x0,param_3,0,(unsigned char *)&local_140);
  psVar8 = local_138;
  if (iVar3 != 0) {
    uVar10 = 0;
  }
  if ((uVar10 == 1) && (local_130 != 0)) {
    if (local_12c == 0) {
      uVar10 = TIntermediate__postProcess(&local_40,local_130,local_134);
      psVar8 = local_138;
      if (uVar10 != 1) {
        TInfoSinkBase__append((char *)local_138);
        TInfoSinkBase__append((char *)psVar8);
        TInfoSinkBase__append((char *)psVar8);
        goto LAB_97ba18d4;
      }
      if (param_4 != 0) {
        bVar1 = (param_5 & 1) == 0;
        bVar14 = bVar1 << 1;
        if (!bVar1) {
          TIntermediate__outputTree((unsigned char *)&local_40);
        }
        (**(code **)(*piVar5 + 0x34))(piVar5,param_4);
        (**(code **)(*piVar5 + 0x38))(piVar5,param_5);
        iVar3 = (**(code **)(*piVar5 + 0x14))(piVar5,local_130);
        if (iVar3 != 0) goto LAB_97ba18d4;
        goto LAB_97ba18cc;
      }
      TInfoSinkBase__append((char *)local_138);
    }
    else {
      TInfoSinkBase__append((char *)local_138);
      psVar8 = local_138;
      _sprintf(acStack_80,"%d",local_128);
      auStack_70[0] = ((int (*)())GetGlobalPoolAllocator)();
      std__string__string((unsigned char *)&uStack_90,acStack_80,(unsigned char *)auStack_70);
      TInfoSinkBase__append(psVar8);
      piVar5 = (int *)(iStack_8c + -4);
      uStack_60 = uStack_90;
      do {
        iVar3 = *piVar5;
        if (in_RESERVE != '\0') {
          iVar2 = storeWordConditionalIndexed(iVar3 + -1,0,piVar5);
          *piVar5 = iVar2;
          bVar14 = 2;
        }
      } while (!(bool)(bVar14 >> 1 & 1));
      if (iVar3 < 1) {
        std__string___Rep___M_destroy((unsigned char *)(iStack_8c + -0xc));
      }
      uVar10 = 0;
    }
    TInfoSinkBase__append((char *)psVar8);
    bVar1 = (param_5 & 1) == 0;
    bVar14 = bVar1 << 1;
    if (!bVar1) {
      TIntermediate__outputTree((unsigned char *)&local_40);
    }
  }
  else {
    if (local_130 != 0) goto LAB_97ba18d4;
    TInfoSinkBase__append((char *)local_138);
    TInfoSinkBase__append((char *)psVar8);
    TInfoSinkBase__append((char *)psVar8);
LAB_97ba18cc:
    uVar10 = 0;
  }
LAB_97ba18d4:
  TIntermediate__remove((unsigned char *)&local_40);
  pvVar12 = local_180;
  for (; iVar3 = (int)local_17c - (int)pvVar12 >> 2, iVar3 != 1; local_17c = local_17c + -1) {
    pTVar9 = *(unsigned char **)((int)pvVar12 + (iVar3 + -1) * 4);
    if (pTVar9 != (unsigned char *)0x0) {
      TSymbolTableLevel___TSymbolTableLevel(pTVar9);
      pvVar12 = local_180;
    }
  }
  _FinalizePreprocessor();
  ((int (*)())GetGlobalPoolAllocator)();
  ((int (*)())TPoolAllocator__pop)();
  _pthread_mutex_unlock((pthread_mutex_t *)&_glsl_allocator_lock);
  piVar5 = (int *)(local_e4 + -4);
  local_50 = local_e8;
  do {
    iVar3 = *piVar5;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar3 + -1,0,piVar5);
      *piVar5 = iVar2;
      bVar14 = 2;
    }
  } while (!(bool)(bVar14 >> 1 & 1));
  if (iVar3 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(local_e4 + -0xc));
  }
  if (local_f0 != 0) {
    std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string______M_erase((unsigned char *)&local_f8);
    local_f4[2] = local_f4;
    local_f4[1] = 0;
    local_f4[3] = local_f4;
    local_f0 = 0;
  }
  pvVar12 = local_180;
  if (local_108 != 0) {
    std___Rb_tree_std__string_std__pair_std__string_const_TBehavior__std___Select1st_std__pair_std__string_const_TBehavior___std__less_std__string__pool_allocator_std__pair_std__string_const_TBehavior______M_erase((unsigned char *)&local_110);
    local_10c[2] = local_10c;
    local_10c[1] = 0;
    local_10c[3] = local_10c;
    local_108 = 0;
    pvVar12 = local_180;
  }
  for (; uVar13 = (int)local_17c - (int)pvVar12 >> 2, 1 < uVar13; local_17c = local_17c + -1) {
    pTVar9 = *(unsigned char **)((int)pvVar12 + (uVar13 - 1) * 4);
    if (pTVar9 != (unsigned char *)0x0) {
      TSymbolTableLevel___TSymbolTableLevel(pTVar9);
      pvVar12 = local_180;
    }
  }
  iVar3 = (int)local_178 - (int)pvVar12 >> 2;
  if (iVar3 != 0) {
    std____default_alloc_template_true_0___deallocate(pvVar12,iVar3 << 2);
  }
  return uVar10;
}

/* _ShLink @ 0x97ba1a6c (364 bytes) */
int _ShLink(param_1, param_2, param_3, param_4, param_5)
  int *param_1;
  int param_2;
  int param_3;
  void *param_4;
  void *param_5;
{
  void **ppvVar1;
  int *piVar2;
  int iVar3;
  ulong uVar4;
  int iVar5;
  char *pcVar6;
  
  if ((param_1 != (int *)0x0) &&
     (ppvVar1 = (void **)(**(code **)(*param_1 + 0xc))(), ppvVar1 != (void **)0x0)) {
    uVar4 = *(ulong *)ppvVar1[0x21];
    std__string__replace((ulong)ppvVar1[0x21],0,*(char **)(uVar4 - 0xc),uVar4);
    uVar4 = *(ulong *)((int)ppvVar1[0x21] + 8);
    std__string__replace((int)ppvVar1[0x21] + 8,0,*(char **)(uVar4 - 0xc),uVar4);
    iVar5 = 0;
    TGenericLinker__reset();
    if (0 < param_3) {
      do {
        piVar2 = *(int **)(param_2 + iVar5 * 4);
        if (piVar2 == (int *)0x0) {
          pcVar6 = ppvVar1[0x21];
                    
LAB_97ba1bf0:
          TInfoSinkBase__append(pcVar6);
          TInfoSinkBase__append(pcVar6);
          TInfoSinkBase__append(pcVar6);
          return 0;
        }
        piVar2 = (int *)(**(code **)(*piVar2 + 8))();
        if ((piVar2 != (int *)0x0) && (iVar3 = (**(code **)(*piVar2 + 0x20))(), iVar3 == 0)) {
          pcVar6 = ppvVar1[0x21];
                    
          goto LAB_97ba1bf0;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < param_3);
    }
    ppvVar1[0x20] = param_4;
    ppvVar1[0x1f] = param_5;
    iVar5 = TGenericLinker__link(ppvVar1,param_2);
    if (iVar5 != 0) {
      return 1;
    }
  }
  return 0;
}

/* ShSetEncryptionMethod @ 0x97ba1c68 (4 bytes) */
int ShSetEncryptionMethod(param_1)
  void *param_1;
{
  return;
}

