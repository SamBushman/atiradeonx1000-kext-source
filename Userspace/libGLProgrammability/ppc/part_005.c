#include "decls.h"

/* __ZN13TParseContext14boolErrorCheckEiPK12TIntermTyped @ 0x97b9ba78 (208 bytes) */
int __ZN13TParseContext14boolErrorCheckEiPK12TIntermTyped(this, param_2, param_3)
  void *this;
  int param_2;
  unsigned char * param_3;
{
  int iVar1;
  undefined4 in_r8;
  undefined4 in_r9;
  undefined4 in_r10;
  
  iVar1 = (**(code **)(*(int *)param_3 + 0x40))(param_3);
  if ((((iVar1 == 3) && (iVar1 = (**(code **)(*(int *)param_3 + 0x54))(param_3), iVar1 == 0)) &&
      (iVar1 = (**(code **)(*(int *)param_3 + 0x50))(param_3), iVar1 == 0)) &&
     (iVar1 = (**(code **)(*(int *)param_3 + 0x58))(param_3), iVar1 == 0)) {
    return 0;
  }
  TParseContext__error
            ((int)this,(char *)param_2,"boolean expression expected","","",in_r8,in_r9,in_r10);
  return 1;
}

/* __ZN13TParseContext14boolErrorCheckEiRK11TPublicType @ 0x97b9bb48 (132 bytes) */
int __ZN13TParseContext14boolErrorCheckEiRK11TPublicType(this, param_2, param_3)
  void *this;
  int param_2;
  unsigned char * param_3;
{
  undefined4 uVar1;
  undefined4 in_r8;
  undefined4 in_r9;
  undefined4 in_r10;
  
  if ((((*(int *)param_3 != 3) || (*(int *)(param_3 + 0x10) != 0)) || (*(int *)(param_3 + 0xc) != 0)
      ) || (uVar1 = 0, 1 < *(int *)(param_3 + 8))) {
    TParseContext__error
              ((int)this,(char *)param_2,"boolean expression expected","","",in_r8,in_r9,in_r10);
    uVar1 = 1;
  }
  return uVar1;
}

/* TParseContext__samplerErrorCheck @ 0x97b9bbcc (184 bytes) */
int TParseContext__samplerErrorCheck(this, param_2, param_3, param_4)
  unsigned char * this;
  int param_2;
  unsigned char * param_3;
  char *param_4;
{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  undefined4 in_r8;
  undefined4 in_r9;
  undefined4 in_r10;
  
  iVar1 = *(int *)param_3;
  if (iVar1 == 0xe) {
    iVar1 = ((int (*)())TParseContext__containsSampler)(this,*(unsigned char **)(param_3 + 0x14));
    if (iVar1 == 0) {
      return 0;
    }
    pcVar2 = (char *)TType__getBasicString(*(undefined4 *)param_3);
    pcVar3 = "(structure contains a sampler)";
  }
  else {
    if (7 < iVar1 - 5U) {
      return 0;
    }
    pcVar2 = (char *)TType__getBasicString(iVar1);
    pcVar3 = "";
  }
  error((int)this,(char *)param_2,param_4,pcVar2,pcVar3,in_r8,in_r9,in_r10);
  return 1;
}

/* TParseContext__structQualifierErrorCheck @ 0x97b9bc84 (172 bytes) */
int TParseContext__structQualifierErrorCheck(this, param_2, param_3)
  unsigned char * this;
  int param_2;
  unsigned char * param_3;
{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined4 in_r8;
  undefined4 in_r9;
  undefined4 in_r10;
  
  iVar1 = *(int *)(param_3 + 4);
  if ((iVar1 - 3U < 3) && (*(int *)param_3 == 0xe)) {
    pcVar2 = (char *)getQualifierString(iVar1);
    error((int)this,(char *)param_2,"cannot be used with a structure",pcVar2,"",in_r8,in_r9,in_r10);
    uVar3 = 1;
  }
  else {
    if ((iVar1 != 6) &&
       (iVar1 = ((int (*)())TParseContext__samplerErrorCheck)(this,param_2,param_3,"samplers must be uniform"), iVar1 != 0)) {
      return 1;
    }
    uVar3 = 0;
  }
  return uVar3;
}

/* TParseContext__parameterSamplerErrorCheck @ 0x97b9bd30 (184 bytes) */
int TParseContext__parameterSamplerErrorCheck(this, param_2, param_3, param_4)
  unsigned char * this;
  int param_2;
  int param_3;
  int *param_4;
{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined4 in_r8;
  undefined4 in_r9;
  undefined4 in_r10;
  
  if (((param_3 - 10U < 2) && (iVar1 = (**(code **)(*param_4 + 0x20))(param_4), iVar1 != 0xe)) &&
     (iVar1 = (**(code **)(*param_4 + 0x20))(param_4), iVar1 - 5U < 8)) {
    pcVar2 = (char *)TType__getBasicString((uint)param_4[9] >> 0x13 & 0x3f);
    error((int)this,(char *)param_2,"samplers cannot be output parameters",pcVar2,"",in_r8,in_r9,
          in_r10);
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}

/* TParseContext__containsSampler @ 0x97b9bde8 (180 bytes) */
int TParseContext__containsSampler(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  iVar1 = (**(code **)(*(int *)param_2 + 0x20))(param_2);
  uVar2 = 1;
  if (7 < iVar1 - 5U) {
    iVar1 = (**(code **)(*(int *)param_2 + 0x20))(param_2);
    if (iVar1 == 0xe) {
      iVar1 = *(int *)(param_2 + 8);
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
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined *puVar5;
  uint uVar6;
  unsigned char * pTVar7;
  void *this_00;
  int *piVar8;
  unsigned char * psVar9;
  char *pcVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int in_r8;
  int iVar14;
  undefined4 in_r10;
  int iVar15;
  void *pvVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  undefined4 uVar20;
  int *piVar21;
  char in_RESERVE;
  byte bVar22;
  undefined4 local_80 [4];
  int local_70 [4];
  undefined4 local_60;
  int local_5c;
  undefined4 local_50;
  int local_4c;
  undefined4 local_40;
  int local_3c;
  int *local_38;
  undefined4 local_30 [5];
  
  pTVar7 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
  this_00 = (void *)((int (*)())TPoolAllocator__allocate)(pTVar7,8);
  bVar22 = (this_00 == (void *)0x0) << 1;
  pvVar16 = (void *)0x0;
  if (this_00 != (void *)0x0) {
    local_80[0] = ((int (*)())GetGlobalPoolAllocator)();
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
              (this_00,"gl_TexCoord",(unsigned char *)local_80);
    pvVar16 = this_00;
  }
  piVar21 = *(int **)(this + 4);
  iVar14 = *piVar21;
  iVar17 = (piVar21[1] - iVar14 >> 2) + -1;
  while( true ) {
    iVar14 = *(int *)(iVar14 + iVar17 * 4);
    std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______find((unsigned char *)local_70,iVar14,pvVar16);
    iVar18 = 0;
    if (local_70[0] != *(int *)(iVar14 + 4)) {
      iVar18 = *(int *)(local_70[0] + 0x18);
    }
    iVar17 = iVar17 + -1;
    if (iVar18 != 0) break;
    if (iVar17 < 0) {
      iVar17 = *(int *)((int)pvVar16 + 4);
      iVar14 = *(int *)(iVar17 + -0xc);
      bVar22 = *DAT_a7b7ba18;
      pcVar10 = "INTERNAL ERROR finding symbol";
LAB_97b9c154:
      *(byte *)(iVar17 + iVar14) = bVar22;
      error((int)this,(char *)0x0,pcVar10,*(char **)((int)pvVar16 + 4),"",in_r8,(uint)bVar22,in_r10)
      ;
      return 1;
    }
    iVar14 = *piVar21;
  }
  pTVar7 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
  piVar8 = (int *)((int (*)())TPoolAllocator__allocate)(pTVar7,0x40);
  puVar5 = PTR_vtable_a7b7c0b4;
  piVar8[1] = (int)pvVar16;
  *piVar8 = (int)(puVar5 + 8);
  in_r8 = *(int *)(iVar18 + 0x18);
  iVar13 = *(int *)(iVar18 + 0x1c);
  iVar12 = *(int *)(iVar18 + 0x20);
  iVar11 = *(int *)(iVar18 + 0x24);
  iVar17 = *(int *)(iVar18 + 0x28);
  iVar14 = *(int *)(iVar18 + 0x10);
  iVar15 = *(int *)(iVar18 + 0x14);
  iVar19 = *(int *)(iVar18 + 0x2c);
  piVar8[3] = (int)&PTR___ZN5TTypeD1Ev_a7b7d4d0;
  piVar8[6] = in_r8;
  piVar8[7] = iVar13;
  piVar8[8] = iVar12;
  piVar8[9] = iVar11;
  piVar8[10] = iVar17;
  piVar8[4] = iVar14;
  piVar8[5] = iVar15;
  in_r10 = 0;
  piVar8[0xb] = iVar19;
  uVar6 = piVar8[0xc];
  uVar2 = *(uint *)(iVar18 + 0x30) & 0xfe000000;
  piVar8[0xc] = uVar2 | uVar6 & 0x1ffffff;
  uVar3 = (*(uint *)(iVar18 + 0x30) >> 0x13 & 0x3f) << 0x13;
  piVar8[0xc] = uVar3 | uVar2 | uVar6 & 0x7ffff;
  uVar1 = *(uint *)(iVar18 + 0x30) & 0x7f800;
  piVar8[0xc] = uVar1 | uVar3 | uVar2 | uVar6 & 0x7ff;
  uVar4 = (*(uint *)(iVar18 + 0x30) >> 10 & 1) << 10;
  piVar8[0xc] = uVar4 | uVar1 | uVar3 | uVar2 | uVar6 & 0x3ff;
  piVar8[0xc] = (*(uint *)(iVar18 + 0x30) >> 9 & 1) << 9 |
                uVar4 | uVar1 | uVar3 | uVar2 | uVar6 & 0x1ff;
  piVar8[0xd] = 0;
  piVar8[0xe] = 0;
  piVar8[0xf] = 0;
  piVar21 = *(int **)(this + 4);
  iVar14 = piVar21[3];
  piVar21[3] = iVar14 + 1;
  piVar8[2] = iVar14 + 1;
  uVar20 = *(undefined4 *)(*piVar21 + ((piVar21[1] - *piVar21 & 0xfffffffcU) - 4));
  local_5c = 0;
  psVar9 = (unsigned char *)(**(code **)(*piVar8 + 8))();
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&local_40,psVar9);
  local_38 = piVar8;
  std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&local_50,uVar20,&local_40);
  local_60 = local_50;
  piVar21 = (int *)(local_3c + -4);
  local_5c = local_4c;
  local_30[0] = local_40;
  do {
    iVar14 = *piVar21;
    if (in_RESERVE != '\0') {
      iVar17 = storeWordConditionalIndexed(iVar14 + -1,0,piVar21);
      *piVar21 = iVar17;
      bVar22 = 2;
    }
  } while (!(bool)(bVar22 >> 1 & 1));
  if (iVar14 < 1) {
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
              ((unsigned char *)(local_3c + -0xc),local_30);
  }
  if (local_5c != 0) {
    return 0;
  }
  (**(code **)(*piVar8 + 4))(piVar8);
  iVar17 = *(int *)((int)pvVar16 + 4);
  iVar14 = *(int *)(iVar17 + -0xc);
  bVar22 = *DAT_a7b7ba18;
  pcVar10 = "INTERNAL ERROR inserting new symbol";
  goto LAB_97b9c154;
}

/* TParseContext__arrayErrorCheck @ 0x97b9c180 (2552 bytes) */
int TParseContext__arrayErrorCheck(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  unsigned char * param_2;
  unsigned char * param_3;
  uint param_4;
  uint param_5;
  uint param_6;
  uint param_7;
  uint param_8;
{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined **ppuVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  unsigned char * pTVar10;
  void *this;
  undefined **ppuVar11;
  unsigned char * psVar12;
  char *pcVar13;
  uint uVar14;
  int iVar15;
  char *pcVar16;
  int *piVar17;
  undefined4 uVar18;
  int *piVar19;
  char in_RESERVE;
  byte in_cr0;
  byte bVar20;
  uint uStack00000024;
  uint uStack00000028;
  uint uStack0000002c;
  uint uStack00000030;
  uint uStack00000034;
  int *in_stack_00000038;
  undefined4 in_stack_0000003c;
  int *in_stack_00000040;
  undefined **local_130;
  char *local_12c;
  int local_128;
  char *local_124;
  undefined **local_120;
  char *local_11c;
  char *local_118;
  char *local_114;
  char *local_110;
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
  uint local_dc;
  uint local_d8;
  uint local_d4;
  uint local_d0;
  int *local_cc;
  uint local_c8;
  uint local_c4;
  uint local_c0;
  int *local_bc;
  undefined4 local_b0 [4];
  undefined **local_a0 [4];
  int local_90 [4];
  undefined4 local_80 [4];
  undefined4 local_70;
  int local_6c;
  int *local_68;
  undefined4 local_60 [4];
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
      piVar19 = *(int **)(param_1 + 4);
      local_3c = 0;
      local_40 = 0;
      iVar15 = *piVar19;
      iVar9 = (piVar19[1] - iVar15 >> 2) + -1;
      while( true ) {
        iVar15 = *(int *)(iVar15 + iVar9 * 4);
        std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______find((unsigned char *)local_90,iVar15,param_3);
        piVar17 = (int *)0x0;
        if (local_90[0] != *(int *)(iVar15 + 4)) {
          piVar17 = *(int **)(local_90[0] + 0x18);
        }
        if ((piVar17 != (int *)0x0) || (iVar9 + -1 < 0)) break;
        iVar15 = *piVar19;
        iVar9 = iVar9 + -1;
      }
      if (&STACKARG(0x0) != (undefined1 *)0x40) {
        local_40 = (uint)(iVar9 == 0);
      }
      if (&STACKARG(0x0) != (undefined1 *)0x3c) {
        local_3c = (uint)(iVar9 == (piVar19[1] - *piVar19 >> 2) + -1);
      }
      if ((piVar17 == (int *)0x0) || (local_3c == 0)) {
        local_12c = (char *)TParseContext__reservedErrorCheck((unsigned char *)param_1,(int)param_2,param_3);
        bVar20 = (local_12c == (char *)0x0) << 1;
        if (local_12c != (char *)0x0) {
          return 1;
        }
        pTVar10 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
        piVar19 = (int *)((int (*)())TPoolAllocator__allocate)(pTVar10,0x40);
        local_10c = (uStack00000034 & 1) << 9 |
                    (uStack00000030 & 1) << 10 |
                    (uStack0000002c & 0xff) << 0xb |
                    (uStack00000024 & 0x3f) << 0x13 | uStack00000028 << 0x19 | local_10c & 0x1ff;
        local_c8 = in_stack_0000003c;
        local_130 = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
        local_100 = uStack00000024;
        local_fc = uStack00000028;
        local_f8 = uStack0000002c;
        local_f4 = uStack00000030;
        local_f0 = uStack00000034;
        local_ec = in_stack_00000038;
        local_e8 = in_stack_0000003c;
        local_e0 = uStack00000024;
        local_dc = uStack00000028;
        local_d8 = uStack0000002c;
        local_d4 = uStack00000030;
        local_d0 = uStack00000034;
        local_cc = in_stack_00000038;
        local_128 = 0;
        local_118 = (char *)0x0;
        param_6 = uStack0000002c;
        local_124 = local_12c;
        ppuVar6 = (undefined **)0x0;
        local_11c = local_12c;
        local_114 = local_12c;
        local_110 = local_12c;
        if (in_stack_00000038 != (int *)0x0) {
          local_128 = in_stack_00000038[2];
          local_120 = (undefined **)local_12c;
          local_118 = local_12c;
          local_118 = (char *)TType__setStructSize
                                        ((unsigned char *)&local_130,(unsigned char *)in_stack_00000038[2]);
          iVar9 = (**(code **)(*local_cc + 0x18))(local_cc);
          *(byte *)(*(int *)(iVar9 + 4) + *(int *)(*(int *)(iVar9 + 4) + -0xc)) = *DAT_a7b7ba18;
          pcVar13 = *(char **)(iVar9 + 4);
          pTVar10 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
          ppuVar11 = (undefined **)((int (*)())TPoolAllocator__allocate)(pTVar10,8);
          bVar20 = (ppuVar11 == (undefined **)0x0) << 1;
          ppuVar6 = (undefined **)0x0;
          if (ppuVar11 != (undefined **)0x0) {
            local_80[0] = ((int (*)())GetGlobalPoolAllocator)();
            __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                      (ppuVar11,pcVar13,(unsigned char *)local_80);
            ppuVar6 = ppuVar11;
          }
        }
        local_120 = ppuVar6;
        piVar19[1] = (int)param_3;
        param_8 = 0;
        *piVar19 = (int)(PTR_vtable_a7b7c0b4 + 8);
        piVar19[4] = (int)local_12c;
        piVar19[5] = local_128;
        piVar19[6] = (int)local_124;
        piVar19[7] = (int)local_120;
        piVar19[8] = (int)local_11c;
        piVar19[9] = (int)local_118;
        piVar19[3] = (int)&PTR___ZN5TTypeD1Ev_a7b7d4d0;
        piVar19[10] = (int)local_114;
        piVar19[0xb] = (int)local_110;
        uVar8 = piVar19[0xc];
        uVar3 = local_10c & 0xfe000000;
        piVar19[0xc] = uVar3 | uVar8 & 0x1ffffff;
        uVar4 = (local_10c >> 0x13 & 0x3f) << 0x13;
        piVar19[0xc] = uVar4 | uVar3 | uVar8 & 0x7ffff;
        uVar14 = local_10c & 0x7f800;
        piVar19[0xc] = uVar14 | uVar4 | uVar3 | uVar8 & 0x7ff;
        uVar5 = (local_10c >> 10 & 1) << 10;
        piVar19[0xc] = uVar5 | uVar14 | uVar4 | uVar3 | uVar8 & 0x3ff;
        piVar19[0xc] = (local_10c >> 9 & 1) << 9 | uVar5 | uVar14 | uVar4 | uVar3 | uVar8 & 0x1ff;
        piVar19[0xd] = 0;
        piVar19[0xe] = 0;
        piVar19[0xf] = 0;
        local_130 = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
        if (!bVar1) {
          piVar19[4] = *(int *)piVar7[0xc];
          piVar19[0xc] = piVar19[0xc] | 0x200;
        }
        piVar7 = *(int **)(param_1 + 4);
        iVar9 = piVar7[3];
        piVar7[3] = iVar9 + 1;
        piVar19[2] = iVar9 + 1;
        uVar18 = *(undefined4 *)(*piVar7 + ((piVar7[1] - *piVar7 & 0xfffffffcU) - 4));
        local_12c = (char *)0x0;
        psVar12 = (unsigned char *)(**(code **)(*piVar19 + 8))(piVar19);
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&local_70,psVar12);
        local_68 = piVar19;
        std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&local_120,uVar18,&local_70);
        local_130 = local_120;
        piVar7 = (int *)(local_6c + -4);
        local_12c = local_11c;
        local_60[0] = local_70;
        do {
          iVar9 = *piVar7;
          if (in_RESERVE != '\0') {
            iVar15 = storeWordConditionalIndexed(iVar9 + -1,0,piVar7);
            *piVar7 = iVar15;
            bVar20 = 2;
          }
        } while (!(bool)(bVar20 >> 1 & 1));
        if (iVar9 < 1) {
          __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                    ((unsigned char *)(local_6c + -0xc),local_60);
        }
        if (local_12c != (char *)0x0) {
LAB_97b9caf4:
          iVar9 = TParseContext__voidErrorCheck((unsigned char *)param_1,(int)param_2,param_3,
                                 (unsigned char *)&STACKARG(0x24));
          if (iVar9 != 0) {
            return 1;
          }
          return 0;
        }
        if (piVar19 != (int *)0x0) {
          (**(code **)(*piVar19 + 4))(piVar19);
        }
        iVar15 = *(int *)(param_3 + 4);
        iVar9 = *(int *)(iVar15 + -0xc);
        uVar14 = (uint)*DAT_a7b7ba18;
        pcVar13 = "INTERNAL ERROR inserting new symbol";
      }
      else {
        iVar9 = (**(code **)(*piVar17 + 0x10))(piVar17);
        if (iVar9 == 0) {
          iVar15 = *(int *)(param_3 + 4);
          iVar9 = *(int *)(iVar15 + -0xc);
          uVar14 = (uint)*DAT_a7b7ba18;
          pcVar13 = "variable expected";
        }
        else {
          iVar9 = (**(code **)(piVar17[3] + 0x38))(piVar17 + 3);
          if (iVar9 == 0) {
            iVar15 = *(int *)(param_3 + 4);
            iVar9 = *(int *)(iVar15 + -0xc);
            uVar14 = (uint)*DAT_a7b7ba18;
            pcVar13 = "redeclaring non-array as array";
          }
          else if (piVar17[4] < 1) {
            local_10c = (uStack00000034 & 1) << 9 |
                        (uStack00000030 & 1) << 10 |
                        (uStack0000002c & 0xff) << 0xb |
                        (uStack00000024 & 0x3f) << 0x13 | uStack00000028 << 0x19 | local_10c & 0x1ff
            ;
            local_c8 = in_stack_0000003c;
            local_130 = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
            local_110 = (char *)0x0;
            local_100 = uStack00000024;
            local_fc = uStack00000028;
            local_f8 = uStack0000002c;
            local_f4 = uStack00000030;
            local_f0 = uStack00000034;
            local_ec = in_stack_00000038;
            local_e8 = in_stack_0000003c;
            local_e0 = uStack00000024;
            local_dc = uStack00000028;
            local_d8 = uStack0000002c;
            local_d4 = uStack00000030;
            local_d0 = uStack00000034;
            local_cc = in_stack_00000038;
            local_12c = (char *)0x0;
            local_128 = 0;
            local_124 = (char *)0x0;
            local_120 = (undefined **)0x0;
            local_11c = (char *)0x0;
            local_118 = (char *)0x0;
            local_114 = (char *)0x0;
            param_6 = uStack00000030;
            param_8 = uStack00000024;
            ppuVar6 = local_120;
            if (in_stack_00000038 != (int *)0x0) {
              local_128 = in_stack_00000038[2];
              local_118 = (char *)TType__setStructSize
                                            ((unsigned char *)&local_130,(unsigned char *)in_stack_00000038[2]);
              iVar9 = (**(code **)(*local_cc + 0x18))(local_cc);
              *(byte *)(*(int *)(iVar9 + 4) + *(int *)(*(int *)(iVar9 + 4) + -0xc)) = *DAT_a7b7ba18;
              pcVar13 = *(char **)(iVar9 + 4);
              pTVar10 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
              ppuVar11 = (undefined **)((int (*)())TPoolAllocator__allocate)(pTVar10,8);
              ppuVar6 = (undefined **)0x0;
              if (ppuVar11 != (undefined **)0x0) {
                local_50[0] = ((int (*)())GetGlobalPoolAllocator)();
                __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                          (ppuVar11,pcVar13,(unsigned char *)local_50);
                ppuVar6 = ppuVar11;
              }
            }
            local_120 = ppuVar6;
            bVar2 = false;
            if (((piVar17[0xc] & 0x1fffe00U) == (local_10c & 0x1fffe00)) &&
               (piVar17[5] == local_128)) {
              bVar2 = true;
            }
            local_130 = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
            if (bVar2) {
              for (iVar9 = piVar17[0xf]; iVar9 != 0; iVar9 = *(int *)(iVar9 + 0x20)) {
                if (*(int *)piVar7[0xc] < *(int *)(iVar9 + 0x1c)) {
                  iVar15 = *(int *)(param_3 + 4);
                  iVar9 = *(int *)(iVar15 + -0xc);
                  uVar14 = (uint)*DAT_a7b7ba18;
                  pcVar13 = "higher index value already used for the array";
                  goto LAB_97b9cb40;
                }
                *(int *)(iVar9 + 4) = *(int *)piVar7[0xc];
                *(uint *)(iVar9 + 0x24) = *(uint *)(iVar9 + 0x24) | 0x200;
              }
              if (!bVar1) {
                piVar17[4] = *(int *)piVar7[0xc];
                piVar17[0xc] = piVar17[0xc] | 0x200;
              }
              goto LAB_97b9caf4;
            }
            iVar15 = *(int *)(param_3 + 4);
            iVar9 = *(int *)(iVar15 + -0xc);
            uVar14 = (uint)*DAT_a7b7ba18;
            pcVar13 = "redeclaration of array with a different type";
          }
          else {
            iVar15 = *(int *)(param_3 + 4);
            iVar9 = *(int *)(iVar15 + -0xc);
            uVar14 = (uint)*DAT_a7b7ba18;
            pcVar13 = "redeclaration of array with size";
          }
        }
      }
    }
    else {
      iVar15 = *(int *)(param_3 + 4);
      iVar9 = *(int *)(iVar15 + -0xc);
      uVar14 = (uint)*DAT_a7b7ba18;
      pcVar13 = "array size must be a positive integer";
    }
LAB_97b9cb40:
    *(char *)(iVar15 + iVar9) = (char)uVar14;
    error(param_1,(char *)param_2,pcVar13,*(char **)(param_3 + 4),"",param_6,uVar14,param_8);
  }
  else {
    local_fc = (param_8 & 1) << 9 |
               (param_7 & 1) << 10 |
               (param_6 & 0xff) << 0xb |
               (param_4 & 0x3f) << 0x13 | param_5 << 0x19 | local_fc & 0x1ff;
    local_120 = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
    local_110 = (void *)0x0;
    local_100 = 0;
    local_bc = in_stack_00000038;
    local_11c = (char *)0x0;
    local_118 = (char *)0x0;
    local_114 = (char *)0x0;
    local_10c = 0;
    local_108 = 0;
    local_104 = 0;
    uStack00000034 = param_8;
    pcVar13 = local_110;
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
      local_108 = TType__setStructSize((unsigned char *)&local_120,(unsigned char *)in_stack_00000038[2]);
      iVar9 = (**(code **)(*local_bc + 0x18))(local_bc);
      *(byte *)(*(int *)(iVar9 + 4) + *(int *)(*(int *)(iVar9 + 4) + -0xc)) = *DAT_a7b7ba18;
      pcVar16 = *(char **)(iVar9 + 4);
      pTVar10 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
      this = (void *)((int (*)())TPoolAllocator__allocate)(pTVar10,8);
      in_cr0 = (this == (void *)0x0) << 1;
      pcVar13 = (void *)0x0;
      if (this != (void *)0x0) {
        local_b0[0] = ((int (*)())GetGlobalPoolAllocator)();
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                  (this,pcVar16,(unsigned char *)local_b0);
        pcVar13 = this;
      }
    }
    local_110 = pcVar13;
    TType__getCompleteString(&local_130,(unsigned char *)&local_120);
    local_12c[*(int *)(local_12c + -0xc)] = *DAT_a7b7ba18;
    error(param_1,(char *)param_2,"cannot declare arrays of this type",local_12c,"",param_4,
          local_12c,param_7);
    piVar7 = (int *)(local_12c + -4);
    local_a0[0] = local_130;
    do {
      iVar9 = *piVar7;
      if (in_RESERVE != '\0') {
        iVar15 = storeWordConditionalIndexed(iVar9 + -1,0,piVar7);
        *piVar7 = iVar15;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar9 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_12c + -0xc),local_a0);
    }
  }
  return 1;
}

/* TParseContext__arraySetMaxSize @ 0x97b9cb78 (600 bytes) */
int TParseContext__arraySetMaxSize(this, param_2, param_3, param_4, param_5, param_6)
  unsigned char * this;
  unsigned char * param_2;
  unsigned char * param_3;
  int param_4;
  int param_5;
  int param_6;
{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  void *pvVar4;
  int iVar5;
  unsigned char * this_00;
  undefined3 in_register_0000001c;
  int iVar6;
  undefined4 in_r10;
  int *piVar7;
  int iVar8;
  char in_RESERVE;
  byte in_cr0;
  byte bVar9;
  int local_e0 [4];
  char *local_d0;
  int local_cc;
  undefined4 local_c0 [4];
  char *local_b0 [4];
  char acStack_a0 [64];
  unsigned char aaStack_60 [16];
  uint local_50;
  
  local_50 = 0;
  piVar7 = *(int **)(this + 4);
  iVar5 = param_6;
  uVar2 = (**(code **)(*(int *)param_2 + 0x60))(param_2);
  iVar6 = *piVar7;
  iVar3 = (piVar7[1] - iVar6 >> 2) + -1;
  while( true ) {
    iVar8 = *(int *)(iVar6 + iVar3 * 4);
    iVar6 = 0;
    std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______find((unsigned char *)local_e0,iVar8,uVar2);
    if (local_e0[0] != *(int *)(iVar8 + 4)) {
      iVar6 = *(int *)(local_e0[0] + 0x18);
    }
    if ((iVar6 != 0) || (iVar3 + -1 < 0)) break;
    iVar6 = *piVar7;
    iVar3 = iVar3 + -1;
  }
  if (&STACKARG(0x0) != (undefined1 *)0x50) {
    local_50 = (uint)(iVar3 == 0);
  }
  if (iVar6 != 0) {
    *(undefined4 *)(param_3 + 0x20) = *(undefined4 *)(iVar6 + 0x3c);
    *(unsigned char **)(iVar6 + 0x3c) = param_3;
    pvVar4 = (void *)(**(code **)(*(int *)param_2 + 0x60))(param_2);
    iVar5 = __ZNKSbIcSt11char_traitsIcE14pool_allocatorIcEE7compareEPKc(pvVar4,"gl_TexCoord");
    if (iVar5 != 0) {
LAB_97b9cf8c:
      if (CONCAT31(in_register_0000001c,param_5) == 0) {
        return 0;
      }
      iVar5 = *(int *)(param_3 + 0x20);
      iVar3 = param_4 + 1;
      *(int *)(iVar6 + 0x28) = iVar3;
      *(int *)(param_3 + 0x1c) = iVar3;
      while (iVar5 != 0) {
        *(int *)(iVar5 + 0x1c) = iVar3;
        iVar5 = *(int *)(iVar5 + 0x20);
      }
      return 0;
    }
    piVar7 = *(int **)(this + 4);
    local_c0[0] = ((int (*)())GetGlobalPoolAllocator)();
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
              (&local_d0,"gl_MaxTextureCoords",(unsigned char *)local_c0);
    iVar3 = *piVar7;
    iVar5 = (piVar7[1] - iVar3 >> 2) + -1;
    while( true ) {
      iVar8 = *(int *)(iVar3 + iVar5 * 4);
      iVar3 = 0;
      std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______find((unsigned char *)local_e0,iVar8,&local_d0);
      if (local_e0[0] != *(int *)(iVar8 + 4)) {
        iVar3 = *(int *)(local_e0[0] + 0x18);
      }
      if ((iVar3 != 0) || (iVar5 + -1 < 0)) break;
      iVar3 = *piVar7;
      iVar5 = iVar5 + -1;
    }
    if (&STACKARG(0x0) != (undefined1 *)0x50) {
      local_50 = (uint)(iVar5 == 0);
    }
    piVar7 = (int *)(local_cc + -4);
    local_b0[0] = local_d0;
    do {
      iVar5 = *piVar7;
      if (in_RESERVE != '\0') {
        iVar8 = storeWordConditionalIndexed(iVar5 + -1,0,piVar7);
        *piVar7 = iVar8;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar5 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_cc + -0xc),local_b0);
    }
    if (iVar3 != 0) {
      piVar7 = *(int **)(iVar3 + 0x38);
      if (piVar7 == (int *)0x0) {
        if (*(int *)(iVar3 + 0x14) == 0) {
          uVar1 = *(uint *)(iVar3 + 0x30);
          if ((uVar1 & 0x400) == 0) {
            iVar5 = (int)(uVar1 << 0xd | uVar1 >> 0x13) >> 0x18;
          }
          else {
            iVar5 = (int)(uVar1 << 0xd | uVar1 >> 0x13) >> 0x18;
            iVar5 = iVar5 * iVar5;
          }
        }
        else {
          iVar5 = *(int *)(iVar3 + 0x24);
        }
        this_00 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
        piVar7 = (int *)((int (*)())TPoolAllocator__allocate)(this_00,iVar5 << 2);
        *(int **)(iVar3 + 0x38) = piVar7;
      }
      if (param_4 < *piVar7) goto LAB_97b9cf8c;
      error((int)this,(char *)param_6,"","[",
            "gl_TexCoord can only have a max array size of up to gl_MaxTextureCoords","",local_cc,
            in_r10);
    }
    else {
      pvVar4 = *(void **)(this + 8);
                    
      __ZN13TInfoSinkBase6appendEPKc(pvVar4,"INTERNAL ERROR: ");
      uVar1 = param_6 & 0xffff;
      bVar9 = (uVar1 == 0) << 1;
      if (uVar1 == 0) {
        _sprintf(acStack_a0,"%d:? ",param_6 >> 0x10);
      }
      else {
        _sprintf(acStack_a0,"%d:%d",param_6 >> 0x10,uVar1);
      }
      __ZNSsC1EPKcRKSaIcE(&local_d0,acStack_a0,aaStack_60);
      local_d0[*(int *)(local_d0 + -0xc)] = *PTR__S_terminal_a7b7c0b8;
      __ZN13TInfoSinkBase6appendEPKc(pvVar4,local_d0);
      piVar7 = (int *)(local_d0 + -4);
      do {
        iVar5 = *piVar7;
        if (in_RESERVE != '\0') {
          iVar3 = storeWordConditionalIndexed(iVar5 + -1,0,piVar7);
          *piVar7 = iVar3;
          bVar9 = 2;
        }
      } while (!(bool)(bVar9 >> 1 & 1));
      if (iVar5 < 1) {
        __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(local_d0 + -0xc));
      }
      __ZN13TInfoSinkBase6appendEPKc(pvVar4,": ");
      __ZN13TInfoSinkBase6appendEPKc(pvVar4,"gl_MaxTextureCoords not defined");
      __ZN13TInfoSinkBase6appendEPKc(pvVar4,"\n");
    }
  }
  else {
    iVar3 = (**(code **)(*(int *)param_2 + 0x60))(param_2);
    bVar9 = *DAT_a7b7ba18;
    *(byte *)(*(int *)(iVar3 + 4) + *(int *)(*(int *)(iVar3 + 4) + -0xc)) = bVar9;
    error((int)this,(char *)param_6," undeclared identifier",*(char **)(iVar3 + 4),"",iVar5,
          (uint)bVar9,in_r10);
  }
  return 1;
}

/* TParseContext__nonInitErrorCheck @ 0x97b9cfe8 (1008 bytes) */
int TParseContext__nonInitErrorCheck(this, param_2, param_3, param_4)
  unsigned char * this;
  int param_2;
  unsigned char * param_3;
  unsigned char * param_4;
{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  void *pvVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  unsigned char * pTVar11;
  int *piVar12;
  int iVar13;
  void *this_00;
  unsigned char * psVar14;
  uint uVar15;
  int *piVar16;
  char *pcVar17;
  undefined4 uVar18;
  char in_RESERVE;
  byte in_cr0;
  undefined **local_d0;
  int local_cc;
  int local_c8;
  int local_c4;
  void *local_c0;
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
  undefined4 local_40 [5];
  
  iVar10 = TParseContext__reservedErrorCheck(this,param_2,param_3);
  if (iVar10 != 0) {
    TParseContext__recover(this);
  }
  iVar10 = *(int *)(param_4 + 4);
  if (iVar10 == 2) {
    *(undefined4 *)(param_4 + 4) = 0;
  }
  pTVar11 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
  piVar12 = (int *)((int (*)())TPoolAllocator__allocate)(pTVar11,0x40);
  local_8c = *(int **)(param_4 + 0x14);
  local_9c = *(int *)(param_4 + 4);
  uVar15 = *(uint *)param_4;
  local_98 = *(uint *)(param_4 + 8);
  local_94 = *(uint *)(param_4 + 0xc);
  local_90 = *(uint *)(param_4 + 0x10);
  local_88 = *(undefined4 *)(param_4 + 0x18);
  local_ac = (local_90 & 1) << 9 |
             (local_94 & 1) << 10 |
             (local_98 & 0xff) << 0xb |
             (uVar15 & 0x3f) << 0x13 | local_9c << 0x19 | local_ac & 0x1ff;
  local_d0 = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  local_b0 = 0;
  local_cc = 0;
  local_c8 = 0;
  local_c4 = 0;
  local_c0 = (void *)0x0;
  local_bc = 0;
  local_b8 = 0;
  local_b4 = 0;
  pvVar7 = local_c0;
  local_a0 = uVar15;
  local_80 = uVar15;
  local_7c = local_9c;
  local_78 = local_98;
  local_74 = local_94;
  local_70 = local_90;
  local_6c = local_8c;
  local_68 = local_88;
  if (local_8c != (int *)0x0) {
    local_c8 = local_8c[2];
    local_b8 = TType__setStructSize((unsigned char *)&local_d0,(unsigned char *)local_8c[2]);
    iVar13 = (**(code **)(*local_6c + 0x18))(local_6c);
    *(byte *)(*(int *)(iVar13 + 4) + *(int *)(*(int *)(iVar13 + 4) + -0xc)) = *DAT_a7b7ba18;
    pcVar17 = *(char **)(iVar13 + 4);
    pTVar11 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
    this_00 = (void *)((int (*)())TPoolAllocator__allocate)(pTVar11,8);
    in_cr0 = (this_00 == (void *)0x0) << 1;
    pvVar7 = (void *)0x0;
    if (this_00 != (void *)0x0) {
      local_60[0] = ((int (*)())GetGlobalPoolAllocator)();
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                (this_00,pcVar17,(unsigned char *)local_60);
      pvVar7 = this_00;
    }
  }
  local_c0 = pvVar7;
  piVar12[1] = (int)param_3;
  *piVar12 = (int)(PTR_vtable_a7b7c0b4 + 8);
  piVar12[4] = local_cc;
  piVar12[5] = local_c8;
  piVar12[6] = local_c4;
  piVar12[7] = (int)local_c0;
  piVar12[8] = local_bc;
  piVar12[9] = local_b8;
  piVar12[3] = (int)&PTR___ZN5TTypeD1Ev_a7b7d4d0;
  piVar12[10] = local_b4;
  piVar12[0xb] = local_b0;
  uVar8 = piVar12[0xc];
  uVar4 = local_ac & 0xfe000000;
  piVar12[0xc] = uVar4 | uVar8 & 0x1ffffff;
  uVar5 = (local_ac >> 0x13 & 0x3f) << 0x13;
  piVar12[0xc] = uVar5 | uVar4 | uVar8 & 0x7ffff;
  uVar3 = local_ac & 0x7f800;
  piVar12[0xc] = uVar3 | uVar5 | uVar4 | uVar8 & 0x7ff;
  uVar6 = (local_ac >> 10 & 1) << 10;
  piVar12[0xc] = uVar6 | uVar3 | uVar5 | uVar4 | uVar8 & 0x3ff;
  piVar12[0xc] = (local_ac >> 9 & 1) << 9 | uVar6 | uVar3 | uVar5 | uVar4 | uVar8 & 0x1ff;
  piVar12[0xd] = 0;
  piVar12[0xe] = 0;
  piVar12[0xf] = 0;
  piVar16 = *(int **)(this + 4);
  local_d0 = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  iVar13 = piVar16[3];
  piVar16[3] = iVar13 + 1;
  piVar12[2] = iVar13 + 1;
  iVar13 = *piVar16;
  uVar18 = *(undefined4 *)(iVar13 + ((piVar16[1] - iVar13 & 0xfffffffcU) - 4));
  local_cc = 0;
  psVar14 = (unsigned char *)(**(code **)(*piVar12 + 8))(piVar12);
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&local_50,psVar14);
  local_48 = piVar12;
  std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&local_c0,uVar18,&local_50);
  local_d0 = local_c0;
  piVar16 = (int *)(local_4c + -4);
  local_cc = local_bc;
  local_40[0] = local_50;
  do {
    iVar9 = *piVar16;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar9 + -1,0,piVar16);
      *piVar16 = iVar2;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar9 < 1) {
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
              ((unsigned char *)(local_4c + -0xc),local_40);
  }
  if (local_cc == 0) {
    iVar10 = piVar12[1];
    bVar1 = *DAT_a7b7ba18;
    *(byte *)(*(int *)(iVar10 + 4) + *(int *)(*(int *)(iVar10 + 4) + -0xc)) = bVar1;
    error((int)this,(char *)param_2,"redefinition",*(char **)(iVar10 + 4),"",uVar15,(uint)bVar1,
          iVar10);
    if (piVar12 != (int *)0x0) {
      (**(code **)(*piVar12 + 4))(piVar12);
    }
  }
  else {
    if (iVar10 != 2) {
      iVar10 = TParseContext__voidErrorCheck(this,param_2,param_3,param_4);
      return iVar10 != 0;
    }
    bVar1 = *DAT_a7b7ba18;
    *(byte *)(*(int *)(param_3 + 4) + *(int *)(*(int *)(param_3 + 4) + -0xc)) = bVar1;
    error((int)this,(char *)param_2,"variables with qualifier \'const\' must be initialized",
          *(char **)(param_3 + 4),"",uVar15,(uint)bVar1,iVar13);
  }
  return true;
}

/* TParseContext__paramErrorCheck @ 0x97b9d3d8 (216 bytes) */
int TParseContext__paramErrorCheck(this, param_2, param_3, param_4, param_5)
  unsigned char * this;
  int param_2;
  int param_3;
  int param_4;
  int *param_5;
{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  undefined4 in_r8;
  undefined4 in_r9;
  undefined4 in_r10;
  
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
  error((int)this,(char *)param_2,pcVar3,pcVar2,pcVar4,in_r8,in_r9,in_r10);
  return 1;
}

/* TParseContext__extensionErrorCheck @ 0x97b9d4b0 (532 bytes) */
int TParseContext__extensionErrorCheck(this, param_2, param_3)
  unsigned char * this;
  int param_2;
  char *param_3;
{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  int *piVar4;
  int iVar5;
  size_t sVar6;
  uint *puVar7;
  undefined4 in_r8;
  undefined4 in_r10;
  unsigned char * pTVar8;
  void *this_00;
  uint uVar9;
  int iVar10;
  uint uVar11;
  char in_RESERVE;
  byte in_cr0;
  byte bVar12;
  undefined4 local_1d0;
  void *local_1cc;
  int local_1c0 [4];
  int local_1b0;
  char *local_1ac;
  int local_1a0;
  int iStack_19c;
  int local_190 [4];
  int local_180 [4];
  undefined4 local_170;
  int local_16c;
  undefined4 local_168;
  int local_160 [4];
  undefined4 local_150 [4];
  undefined4 local_140 [4];
  undefined4 uStack_130;
  int iStack_12c;
  undefined4 local_120 [4];
  char *apcStack_110 [4];
  char acStack_100 [64];
  unsigned char aaStack_c0 [16];
  int aiStack_b0 [4];
  int aiStack_a0 [4];
  undefined4 auStack_90 [4];
  undefined4 local_80 [4];
  undefined4 local_70;
  int local_6c;
  undefined4 local_68;
  undefined4 local_60 [4];
  undefined4 local_50 [4];
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  
  local_1c0[0] = ((int (*)())GetGlobalPoolAllocator)();
  pTVar8 = this + 0x30;
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
            ((unsigned char *)&local_1d0,param_3,(unsigned char *)local_1c0);
  std___Rb_tree_std__string_std__pair_std__string_const_TBehavior__std___Select1st_std__pair_std__string_const_TBehavior___std__less_std__string__pool_allocator_std__pair_std__string_const_TBehavior_____lower_bound((unsigned char *)&local_1b0,pTVar8,(unsigned char *)&local_1d0);
  iVar10 = local_1b0;
  local_1a0 = *(int *)(this + 0x34);
  if (local_1b0 == local_1a0) {
LAB_97b9d574:
    local_180[0] = iVar10;
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&local_170,(unsigned char *)&local_1d0);
    local_168 = 0;
    local_160[0] = local_180[0];
    __ZNSt8_Rb_treeISbIcSt11char_traitsIcE14pool_allocatorIcEESt4pairIKS4_9TBehaviorESt10_Select1stIS8_ESt4lessIS4_ES2_IS8_EE13insert_uniqueESt17_Rb_tree_iteratorIS8_RS8_PS8_ERKS8_
              (local_190,pTVar8,local_160,&local_170);
    piVar4 = (int *)(local_16c + -4);
    local_1b0 = local_190[0];
    local_150[0] = local_170;
    do {
      iVar5 = *piVar4;
      if (in_RESERVE != '\0') {
        iVar10 = storeWordConditionalIndexed(iVar5 + -1,0,piVar4);
        *piVar4 = iVar10;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    iVar10 = local_190[0];
    if (iVar5 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_16c + -0xc),local_150);
      iVar10 = local_1b0;
    }
  }
  else {
    puVar7 = &local_3c;
    uVar11 = *(uint *)((int)local_1cc + -0xc);
    local_40 = uVar11;
    uVar9 = *(uint *)(*(int *)(local_1b0 + 0x14) + -0xc);
    local_3c = uVar9;
    if (uVar11 <= uVar9) {
      puVar7 = &local_40;
    }
    iVar5 = _memcmp(local_1cc,*(void **)(local_1b0 + 0x14),*puVar7);
    in_cr0 = (iVar5 == 0) << 1;
    if (iVar5 == 0) {
      iVar5 = uVar11 - uVar9;
    }
    if (iVar5 < 0) goto LAB_97b9d574;
  }
  iVar10 = *(int *)(iVar10 + 0x18);
  piVar4 = (int *)((int)local_1cc + -4);
  local_140[0] = local_1d0;
  do {
    iVar5 = *piVar4;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar5 + -1,0,piVar4);
      *piVar4 = iVar2;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar5 < 1) {
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
              ((unsigned char *)((int)local_1cc + -0xc),local_140);
  }
  if (iVar10 == 2) {
    this_00 = *(void **)(this + 8);
    local_120[0] = ((int (*)())GetGlobalPoolAllocator)();
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
              (&uStack_130,param_3,(unsigned char *)local_120);
    __ZStplIcSt11char_traitsIcE14pool_allocatorIcEESbIT_T0_T1_EPKS4_RKS7_
              ((char *)&local_1a0,(unsigned char *)"extension ",&uStack_130);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_
              ((unsigned char *)&local_1b0,(unsigned char *)&local_1a0);
    sVar6 = _strlen(" is being used");
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEPKcm
              ((unsigned char *)&local_1b0," is being used",sVar6);
    pcVar3 = local_1ac;
    local_1ac[*(int *)(local_1ac + -0xc)] = *DAT_a7b7ba18;
                    
    __ZN13TInfoSinkBase6appendEPKc(this_00,"WARNING: ");
    uVar9 = param_2 & 0xffff;
    bVar12 = (uVar9 == 0) << 1;
    if (uVar9 == 0) {
      _sprintf(acStack_100,"%d:? ",param_2 >> 0x10);
    }
    else {
      _sprintf(acStack_100,"%d:%d",param_2 >> 0x10,uVar9);
    }
    __ZNSsC1EPKcRKSaIcE(apcStack_110,acStack_100,aaStack_c0);
    apcStack_110[0][*(int *)(apcStack_110[0] + -0xc)] = *PTR__S_terminal_a7b7c0b8;
    __ZN13TInfoSinkBase6appendEPKc(this_00,apcStack_110[0]);
    piVar4 = (int *)(apcStack_110[0] + -4);
    do {
      iVar10 = *piVar4;
      if (in_RESERVE != '\0') {
        iVar5 = storeWordConditionalIndexed(iVar10 + -1,0,piVar4);
        *piVar4 = iVar5;
        bVar12 = 2;
      }
    } while (!(bool)(bVar12 >> 1 & 1));
    if (iVar10 < 1) {
      __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(apcStack_110[0] + -0xc));
    }
    __ZN13TInfoSinkBase6appendEPKc(this_00,": ");
    __ZN13TInfoSinkBase6appendEPKc(this_00,pcVar3);
    __ZN13TInfoSinkBase6appendEPKc(this_00,"\n");
    piVar4 = (int *)(local_1ac + -4);
    aiStack_b0[0] = local_1b0;
    do {
      iVar10 = *piVar4;
      if (in_RESERVE != '\0') {
        iVar5 = storeWordConditionalIndexed(iVar10 + -1,0,piVar4);
        *piVar4 = iVar5;
        bVar12 = 2;
      }
    } while (!(bool)(bVar12 >> 1 & 1));
    if (iVar10 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_1ac + -0xc),aiStack_b0);
    }
    piVar4 = (int *)(iStack_19c + -4);
    aiStack_a0[0] = local_1a0;
    do {
      iVar10 = *piVar4;
      if (in_RESERVE != '\0') {
        iVar5 = storeWordConditionalIndexed(iVar10 + -1,0,piVar4);
        *piVar4 = iVar5;
        bVar12 = 2;
      }
    } while (!(bool)(bVar12 >> 1 & 1));
    if (iVar10 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(iStack_19c + -0xc),aiStack_a0);
    }
    piVar4 = (int *)(iStack_12c + -4);
    auStack_90[0] = uStack_130;
    do {
      iVar10 = *piVar4;
      if (in_RESERVE != '\0') {
        iVar5 = storeWordConditionalIndexed(iVar10 + -1,0,piVar4);
        *piVar4 = iVar5;
        bVar12 = 2;
      }
    } while (!(bool)(bVar12 >> 1 & 1));
    if (iVar10 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(iStack_12c + -0xc),auStack_90);
    }
    return false;
  }
  local_80[0] = ((int (*)())GetGlobalPoolAllocator)();
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
            ((unsigned char *)&local_1d0,param_3,(unsigned char *)local_80);
  std___Rb_tree_std__string_std__pair_std__string_const_TBehavior__std___Select1st_std__pair_std__string_const_TBehavior___std__less_std__string__pool_allocator_std__pair_std__string_const_TBehavior_____lower_bound((unsigned char *)local_1c0,pTVar8,(unsigned char *)&local_1d0);
  iVar10 = local_1c0[0];
  local_1b0 = *(int *)(this + 0x34);
  if (local_1c0[0] != local_1b0) {
    puVar7 = &local_34;
    uVar11 = *(uint *)((int)local_1cc + -0xc);
    local_38 = uVar11;
    uVar9 = *(uint *)(*(int *)(local_1c0[0] + 0x14) + -0xc);
    local_34 = uVar9;
    if (uVar11 <= uVar9) {
      puVar7 = &local_38;
    }
    iVar5 = _memcmp(local_1cc,*(void **)(local_1c0[0] + 0x14),*puVar7);
    in_cr0 = (iVar5 == 0) << 1;
    if (iVar5 == 0) {
      iVar5 = uVar11 - uVar9;
    }
    if (-1 < iVar5) goto LAB_97b9d98c;
  }
  local_190[0] = iVar10;
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&local_70,(unsigned char *)&local_1d0);
  local_68 = 0;
  local_180[0] = local_190[0];
  __ZNSt8_Rb_treeISbIcSt11char_traitsIcE14pool_allocatorIcEESt4pairIKS4_9TBehaviorESt10_Select1stIS8_ESt4lessIS4_ES2_IS8_EE13insert_uniqueESt17_Rb_tree_iteratorIS8_RS8_PS8_ERKS8_
            (&local_1a0,pTVar8,local_180,&local_70);
  piVar4 = (int *)(local_6c + -4);
  local_1c0[0] = local_1a0;
  local_60[0] = local_70;
  do {
    iVar5 = *piVar4;
    if (in_RESERVE != '\0') {
      iVar10 = storeWordConditionalIndexed(iVar5 + -1,0,piVar4);
      *piVar4 = iVar10;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  iVar10 = local_1a0;
  if (iVar5 < 1) {
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
              ((unsigned char *)(local_6c + -0xc),local_60);
    iVar10 = local_1c0[0];
  }
LAB_97b9d98c:
  iVar10 = *(int *)(iVar10 + 0x18);
  piVar4 = (int *)((int)local_1cc + -4);
  local_50[0] = local_1d0;
  do {
    iVar5 = *piVar4;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar5 + -1,0,piVar4);
      *piVar4 = iVar2;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar5 < 1) {
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
              ((unsigned char *)((int)local_1cc + -0xc),local_50);
  }
  bVar1 = iVar10 == 3;
  if (bVar1) {
    error((int)this,(char *)param_2,"extension",param_3,"is disabled",in_r8,local_1cc,in_r10);
  }
  return bVar1;
}

/* TParseContext__findFunction @ 0x97b9da08 (356 bytes) */
int TParseContext__findFunction(this, param_2, param_3, param_4)
  unsigned char * this;
  int param_2;
  unsigned char * param_3;
  bool *param_4;
{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  undefined4 in_r8;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  int local_40 [7];
  
  piVar7 = *(int **)(this + 4);
  uVar3 = (**(code **)(*(int *)param_3 + 8))(param_3);
  iVar5 = *piVar7;
  iVar2 = (piVar7[1] - iVar5 >> 2) + -1;
  while( true ) {
    iVar5 = *(int *)(iVar5 + iVar2 * 4);
    std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______find((unsigned char *)local_40,iVar5,uVar3);
    piVar8 = (int *)0x0;
    if (local_40[0] != *(int *)(iVar5 + 4)) {
      piVar8 = *(int **)(local_40[0] + 0x18);
    }
    if ((piVar8 != (int *)0x0) || (iVar2 + -1 < 0)) break;
    iVar5 = *piVar7;
    iVar2 = iVar2 + -1;
  }
  if (param_4 != (bool *)0x0) {
    *(uint *)param_4 = (uint)(iVar2 == 0);
  }
  if (piVar8 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar8 + 0xc))(piVar8);
    if (iVar2 != 0) {
      return piVar8;
    }
    iVar5 = *(int *)(param_3 + 4);
    iVar6 = *(int *)(iVar5 + 4);
    bVar1 = *DAT_a7b7ba18;
    iVar2 = *(int *)(iVar6 + -0xc);
    pcVar4 = "function name expected";
  }
  else {
    iVar5 = *(int *)(param_3 + 4);
    iVar6 = *(int *)(iVar5 + 4);
    bVar1 = *DAT_a7b7ba18;
    iVar2 = *(int *)(iVar6 + -0xc);
    pcVar4 = "no matching overloaded function found";
  }
  *(byte *)(iVar6 + iVar2) = bVar1;
  error((int)this,(char *)param_2,pcVar4,*(char **)(iVar5 + 4),"",in_r8,(uint)bVar1,iVar5);
  return (int *)0x0;
}

/* TParseContext__executeInitializer @ 0x97b9db6c (3572 bytes) */
int TParseContext__executeInitializer(this, param_2, param_3, param_4, param_5, param_6)
  unsigned char * this;
  int param_2;
  unsigned char * param_3;
  unsigned char * param_4;
  unsigned char * param_5;
  unsigned char ** param_6;
{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  unsigned char * pTVar7;
  int *piVar8;
  undefined **ppuVar9;
  unsigned char * psVar10;
  uint uVar11;
  unsigned char * this_00;
  unsigned char * pTVar12;
  undefined **ppuVar13;
  undefined ***pppuVar14;
  char *pcVar15;
  undefined **ppuVar16;
  undefined4 uVar17;
  uint *puVar18;
  uint uVar19;
  undefined4 uVar20;
  undefined4 *puVar21;
  unsigned char * pcVar22;
  int *piVar23;
  undefined4 uVar24;
  int iVar25;
  int iVar26;
  char *pcVar27;
  unsigned char * pTVar28;
  char in_RESERVE;
  byte bVar29;
  undefined **local_150;
  uint local_14c;
  undefined **local_148;
  uint local_144;
  undefined **local_140;
  uint local_13c;
  uint local_138;
  uint local_134;
  uint local_130;
  uint local_12c;
  undefined **local_120;
  uint local_11c;
  undefined **local_118;
  uint local_114;
  uint local_110;
  int *local_10c;
  undefined4 local_108;
  undefined **local_100;
  uint local_fc;
  undefined **local_f8;
  uint local_f4;
  uint local_f0;
  int *local_ec;
  undefined4 local_e8;
  undefined4 local_e0 [4];
  undefined4 local_d0;
  int local_cc;
  int *local_c8;
  undefined4 local_c0 [4];
  undefined **local_b0 [4];
  undefined4 local_a0 [4];
  undefined4 local_90 [4];
  int local_80 [4];
  undefined **local_70 [4];
  undefined **local_60 [4];
  undefined **local_50 [6];
  
  iVar6 = TParseContext__reservedErrorCheck(this,param_2,param_3);
  if (iVar6 != 0) {
    return 1;
  }
  local_14c = TParseContext__voidErrorCheck(this,param_2,param_3,param_4);
  bVar29 = (local_14c == 0) << 1;
  if (local_14c != 0) {
    return 1;
  }
  pTVar7 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
  piVar8 = (int *)((int (*)())TPoolAllocator__allocate)(pTVar7,0x40);
  local_10c = *(int **)(param_4 + 0x14);
  local_11c = *(uint *)(param_4 + 4);
  local_120 = *(undefined ***)param_4;
  ppuVar16 = *(undefined ***)(param_4 + 8);
  local_114 = *(uint *)(param_4 + 0xc);
  local_110 = *(uint *)(param_4 + 0x10);
  local_108 = *(undefined4 *)(param_4 + 0x18);
  local_12c = (local_110 & 1) << 9 |
              (local_114 & 1) << 10 |
              ((uint)ppuVar16 & 0xff) << 0xb |
              ((uint)local_120 & 0x3f) << 0x13 | local_11c << 0x19 | local_12c & 0x1ff;
  local_150 = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  local_148 = (undefined **)0x0;
  local_138 = 0;
  local_144 = local_14c;
  ppuVar13 = (undefined **)0x0;
  local_13c = local_14c;
  local_134 = local_14c;
  local_130 = local_14c;
  local_118 = ppuVar16;
  local_100 = local_120;
  local_fc = local_11c;
  local_f8 = ppuVar16;
  local_f4 = local_114;
  local_f0 = local_110;
  local_ec = local_10c;
  local_e8 = local_108;
  if (local_10c != (int *)0x0) {
    local_148 = (undefined **)local_10c[2];
    local_140 = (undefined **)local_14c;
    local_138 = local_14c;
    local_138 = TType__setStructSize((unsigned char *)&local_150,(unsigned char *)local_10c[2]);
    iVar6 = (**(code **)(*local_ec + 0x18))(local_ec);
    *(byte *)(*(int *)(iVar6 + 4) + *(int *)(*(int *)(iVar6 + 4) + -0xc)) = *DAT_a7b7ba18;
    pcVar27 = *(char **)(iVar6 + 4);
    pTVar7 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
    ppuVar9 = (undefined **)((int (*)())TPoolAllocator__allocate)(pTVar7,8);
    bVar29 = (ppuVar9 == (undefined **)0x0) << 1;
    ppuVar13 = (undefined **)0x0;
    if (ppuVar9 != (undefined **)0x0) {
      local_e0[0] = ((int (*)())GetGlobalPoolAllocator)();
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                (ppuVar9,pcVar27,(unsigned char *)local_e0);
      ppuVar13 = ppuVar9;
    }
  }
  local_140 = ppuVar13;
  piVar8[1] = (int)param_3;
  pTVar28 = (unsigned char *)(piVar8 + 3);
  *piVar8 = (int)(PTR_vtable_a7b7c0b4 + 8);
  piVar8[4] = local_14c;
  piVar8[5] = (int)local_148;
  piVar8[6] = local_144;
  piVar8[7] = (int)local_140;
  piVar8[8] = local_13c;
  piVar8[9] = local_138;
  piVar8[3] = (int)&PTR___ZN5TTypeD1Ev_a7b7d4d0;
  piVar8[10] = local_134;
  piVar8[0xb] = local_130;
  uVar3 = piVar8[0xc];
  uVar19 = local_12c & 0xfe000000;
  piVar8[0xc] = uVar19 | uVar3 & 0x1ffffff;
  uVar11 = (local_12c >> 0x13 & 0x3f) << 0x13;
  piVar8[0xc] = uVar11 | uVar19 | uVar3 & 0x7ffff;
  uVar5 = local_12c & 0x7f800;
  piVar8[0xc] = uVar5 | uVar11 | uVar19 | uVar3 & 0x7ff;
  uVar2 = (local_12c >> 10 & 1) << 10;
  piVar8[0xc] = uVar2 | uVar5 | uVar11 | uVar19 | uVar3 & 0x3ff;
  piVar8[0xc] = (local_12c >> 9 & 1) << 9 | uVar2 | uVar5 | uVar11 | uVar19 | uVar3 & 0x1ff;
  piVar8[0xd] = 0;
  piVar8[0xe] = 0;
  piVar8[0xf] = 0;
  puVar18 = *(uint **)(this + 4);
  local_150 = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  uVar5 = puVar18[3];
  puVar18[3] = uVar5 + 1;
  piVar8[2] = uVar5 + 1;
  uVar5 = *puVar18;
  uVar24 = *(undefined4 *)(uVar5 + ((puVar18[1] - uVar5 & 0xfffffffc) - 4));
  local_14c = 0;
  psVar10 = (unsigned char *)(**(code **)(*piVar8 + 8))(piVar8);
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&local_d0,psVar10);
  local_c8 = piVar8;
  std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&local_140,uVar24,&local_d0);
  local_150 = local_140;
  piVar4 = (int *)(local_cc + -4);
  local_14c = local_13c;
  local_c0[0] = local_d0;
  do {
    iVar6 = *piVar4;
    uVar19 = iVar6 - 1;
    if (in_RESERVE != '\0') {
      iVar25 = storeWordConditionalIndexed(uVar19,0,piVar4);
      *piVar4 = iVar25;
      bVar29 = 2;
    }
  } while (!(bool)(bVar29 >> 1 & 1));
  if (iVar6 < 1) {
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
              ((unsigned char *)(local_cc + -0xc),local_c0);
  }
  if (local_14c == 0) {
    uVar5 = piVar8[1];
    uVar19 = (uint)*DAT_a7b7ba18;
    pcVar15 = "redefinition";
    *(byte *)(*(int *)(uVar5 + 4) + *(int *)(*(int *)(uVar5 + 4) + -0xc)) = *DAT_a7b7ba18;
    pcVar27 = *(char **)(uVar5 + 4);
    goto LAB_97b9df14;
  }
  uVar11 = (**(code **)(piVar8[3] + 0x24))(pTVar28);
  if (2 < uVar11) {
    pcVar27 = (char *)getQualifierString((uint)piVar8[0xc] >> 0x19);
    pcVar15 = " cannot initialize this type of qualifier ";
    goto LAB_97b9df14;
  }
  if (uVar11 != 2) {
    iVar6 = TIntermediate__addSymbol
                      (*(unsigned char **)this,piVar8[2],(unsigned char *)piVar8[1],pTVar28,param_2);
    pTVar12 = (unsigned char *)
              TIntermediate__addAssign(*(unsigned char **)this,0x76,iVar6,param_5,param_2);
    *param_6 = pTVar12;
    if (pTVar12 != (unsigned char *)0x0) {
      return 0;
    }
    TType__getCompleteString(&local_150,param_5 + 8);
    TType__getCompleteString((unsigned char *)&local_140,iVar6 + 8);
    TParseContext__assignError(this,param_2,"=",(unsigned char *)&local_140,&local_150);
    piVar8 = (int *)(local_13c - 4);
    local_60[0] = local_140;
    do {
      iVar6 = *piVar8;
      if (in_RESERVE != '\0') {
        iVar25 = storeWordConditionalIndexed(iVar6 + -1,0,piVar8);
        *piVar8 = iVar25;
        bVar29 = 2;
      }
    } while (!(bool)(bVar29 >> 1 & 1));
    if (iVar6 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_13c - 0xc),local_60);
    }
    piVar8 = (int *)(local_14c - 4);
    local_50[0] = local_150;
    do {
      iVar6 = *piVar8;
      if (in_RESERVE != '\0') {
        iVar25 = storeWordConditionalIndexed(iVar6 + -1,0,piVar8);
        *piVar8 = iVar25;
        bVar29 = 2;
      }
    } while (!(bool)(bVar29 >> 1 & 1));
    if (0 < iVar6) {
      return 1;
    }
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
              ((unsigned char *)(local_14c - 0xc),local_50);
    return 1;
  }
  (**(code **)(*(int *)param_5 + 0x38))((unsigned char *)&local_150,param_5);
  local_150 = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  uVar19 = -((int)-(local_12c >> 0x19 ^ 2) >> 0x1f);
  bVar29 = (uVar19 == 0) << 1;
  if (uVar19 != 0) {
    TType__getCompleteString(&local_120,pTVar28);
    bVar1 = *DAT_a7b7ba18;
    *(byte *)(local_11c + *(int *)(local_11c - 0xc)) = bVar1;
    error((int)this,(char *)param_2," assigning non-constant to","=","\'%s\'",local_11c,(uint)bVar1,
          uVar5);
    piVar4 = (int *)(local_11c - 4);
    local_b0[0] = local_120;
    do {
      iVar6 = *piVar4;
      if (in_RESERVE != '\0') {
        iVar25 = storeWordConditionalIndexed(iVar6 + -1,0,piVar4);
        *piVar4 = iVar25;
        bVar29 = 2;
      }
    } while (!(bool)(bVar29 >> 1 & 1));
    pppuVar14 = local_b0;
    uVar5 = local_11c;
    if (0 < iVar6) goto LAB_97b9e184;
LAB_97b9e848:
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
              ((unsigned char *)(uVar5 - 0xc),pppuVar14);
LAB_97b9e184:
    (**(code **)(piVar8[3] + 0x28))(pTVar28,0);
    return 1;
  }
  local_10c = *(int **)(param_4 + 0x14);
  uVar5 = *(uint *)(param_4 + 4);
  ppuVar16 = *(undefined ***)param_4;
  local_118 = *(undefined ***)(param_4 + 8);
  local_114 = *(uint *)(param_4 + 0xc);
  local_110 = *(uint *)(param_4 + 0x10);
  local_108 = *(undefined4 *)(param_4 + 0x18);
  local_12c = (local_110 & 1) << 9 |
              (local_114 & 1) << 10 |
              ((uint)local_118 & 0xff) << 0xb |
              ((uint)ppuVar16 & 0x3f) << 0x13 | uVar5 << 0x19 | local_12c & 0x1ff;
  local_150 = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  local_148 = (undefined **)0x0;
  local_138 = 0;
  bVar29 = 2;
  local_14c = uVar19;
  local_144 = uVar19;
  ppuVar13 = (undefined **)0x0;
  local_13c = uVar19;
  local_134 = uVar19;
  local_130 = uVar19;
  local_120 = ppuVar16;
  local_11c = uVar5;
  local_100 = ppuVar16;
  local_fc = uVar5;
  local_f8 = local_118;
  local_f4 = local_114;
  local_f0 = local_110;
  local_ec = local_10c;
  local_e8 = local_108;
  if (local_10c != (int *)0x0) {
    local_148 = (undefined **)local_10c[2];
    local_140 = (undefined **)uVar19;
    local_138 = uVar19;
    local_138 = TType__setStructSize((unsigned char *)&local_150,(unsigned char *)local_10c[2]);
    iVar6 = (**(code **)(*local_ec + 0x18))(local_ec);
    *(byte *)(*(int *)(iVar6 + 4) + *(int *)(*(int *)(iVar6 + 4) + -0xc)) = *DAT_a7b7ba18;
    pcVar27 = *(char **)(iVar6 + 4);
    pTVar7 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
    ppuVar9 = (undefined **)((int (*)())TPoolAllocator__allocate)(pTVar7,8);
    bVar29 = (ppuVar9 == (undefined **)0x0) << 1;
    ppuVar13 = (undefined **)0x0;
    if (ppuVar9 != (undefined **)0x0) {
      local_a0[0] = ((int (*)())GetGlobalPoolAllocator)();
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                (ppuVar9,pcVar27,(unsigned char *)local_a0);
      ppuVar13 = ppuVar9;
    }
  }
  local_140 = ppuVar13;
  (**(code **)(*(int *)param_5 + 0x38))(&local_120,param_5);
  iVar6 = 0;
  if (((local_12c & 0x1fffe00) == (local_fc & 0x1fffe00)) && (local_148 == local_118)) {
    iVar6 = 1;
  }
  local_150 = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  local_120 = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  if (iVar6 == 0) {
    pcVar27 = (char *)getQualifierString((uint)piVar8[0xc] >> 0x19);
    error((int)this,(char *)param_2," non-matching types for const initializer ",pcVar27,"",uVar5,
          iVar6,ppuVar16);
    goto LAB_97b9e184;
  }
  iVar6 = (**(code **)(*(int *)param_5 + 0x18))(param_5);
  if (iVar6 == 0) {
    iVar6 = (**(code **)(*(int *)param_5 + 0x1c))(param_5);
    if (iVar6 != 0) {
      pcVar22 = (unsigned char *)piVar8[0xe];
      if (pcVar22 == (unsigned char *)0x0) {
        if (piVar8[5] == 0) {
          uVar5 = piVar8[0xc];
          if ((uVar5 & 0x400) == 0) {
            iVar6 = (int)(uVar5 << 0xd | uVar5 >> 0x13) >> 0x18;
          }
          else {
            iVar6 = (int)(uVar5 << 0xd | uVar5 >> 0x13) >> 0x18;
            iVar6 = iVar6 * iVar6;
          }
        }
        else {
          iVar6 = piVar8[9];
        }
        pTVar7 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
        pcVar22 = (unsigned char *)((int (*)())TPoolAllocator__allocate)(pTVar7,iVar6 << 2);
        piVar8[0xe] = (int)pcVar22;
      }
      piVar4 = (int *)(**(code **)(*(int *)param_5 + 0x1c))(param_5);
      iVar6 = (**(code **)(*piVar4 + 100))();
      if (*(int *)(iVar6 + 8) - *(int *)(iVar6 + 4) >> 2 == 1) {
        piVar4 = (int *)(**(code **)(*(int *)param_5 + 0x1c))(param_5);
        iVar6 = (**(code **)(*piVar4 + 100))();
        piVar4 = (int *)(**(code **)(*(int *)**(undefined4 **)(iVar6 + 4) + 0x14))();
        iVar6 = (**(code **)(*piVar4 + 0x18))();
        if (iVar6 != 0) {
          local_14c = piVar8[4];
          local_148 = (undefined **)piVar8[5];
          local_144 = piVar8[6];
          local_13c = piVar8[8];
          local_138 = piVar8[9];
          local_134 = piVar8[10];
          local_130 = piVar8[0xb];
          local_140 = (undefined **)piVar8[7];
          local_150 = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
          local_12c = ((uint)piVar8[0xc] >> 9 & 1) << 9 |
                      ((uint)piVar8[0xc] >> 10 & 1) << 10 |
                      piVar8[0xc] & 0x7f800U |
                      ((uint)piVar8[0xc] >> 0x13 & 0x3f) << 0x13 |
                      piVar8[0xc] & 0xfe000000U | local_12c & 0x1ff;
          iVar6 = (**(code **)(*(int *)param_5 + 0x1c))(param_5);
          uVar17 = *(undefined4 *)(this + 4);
          uVar24 = *(undefined4 *)(iVar6 + 0x30);
          this_00 = *(unsigned char **)this;
          uVar20 = 1;
          goto LAB_97b9e6d8;
        }
      }
      local_14c = piVar8[4];
      local_148 = (undefined **)piVar8[5];
      local_144 = piVar8[6];
      local_13c = piVar8[8];
      local_138 = piVar8[9];
      local_134 = piVar8[10];
      local_130 = piVar8[0xb];
      local_140 = (undefined **)piVar8[7];
      local_150 = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
      local_12c = ((uint)piVar8[0xc] >> 9 & 1) << 9 |
                  ((uint)piVar8[0xc] >> 10 & 1) << 10 |
                  piVar8[0xc] & 0x7f800U |
                  ((uint)piVar8[0xc] >> 0x13 & 0x3f) << 0x13 |
                  piVar8[0xc] & 0xfe000000U | local_12c & 0x1ff;
      iVar6 = (**(code **)(*(int *)param_5 + 0x1c))(param_5);
      uVar17 = *(undefined4 *)(this + 4);
      uVar24 = *(undefined4 *)(iVar6 + 0x30);
      this_00 = *(unsigned char **)this;
      uVar20 = 0;
LAB_97b9e6d8:
      iVar6 = TIntermediate__parseConstTree
                        (this_00,param_2,(unsigned char *)param_5,pcVar22,uVar24,uVar17,
                         (unsigned char *)&local_150,uVar20);
      local_150 = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
      *param_6 = (unsigned char *)0x0;
      if (iVar6 != 0) {
        (**(code **)(piVar8[3] + 0x28))(pTVar28,0);
        return iVar6;
      }
      return 0;
    }
    iVar6 = (**(code **)(*(int *)param_5 + 0x28))(param_5);
    if (iVar6 == 0) {
      TType__getCompleteString((unsigned char *)&local_150,pTVar28);
      bVar1 = *DAT_a7b7ba18;
      *(byte *)(local_14c + *(int *)(local_14c - 0xc)) = bVar1;
      error((int)this,(char *)param_2," assigning non-constant to","=","\'%s\'",local_14c,
            (uint)bVar1,ppuVar16);
      piVar4 = (int *)(local_14c - 4);
      local_70[0] = local_150;
      do {
        iVar6 = *piVar4;
        if (in_RESERVE != '\0') {
          iVar25 = storeWordConditionalIndexed(iVar6 + -1,0,piVar4);
          *piVar4 = iVar25;
          bVar29 = 2;
        }
      } while (!(bool)(bVar29 >> 1 & 1));
      if (0 < iVar6) goto LAB_97b9e184;
      pppuVar14 = local_70;
      uVar5 = local_14c;
      goto LAB_97b9e848;
    }
    piVar23 = *(int **)(this + 4);
    piVar4 = (int *)(**(code **)(*(int *)param_5 + 0x28))(param_5);
    uVar24 = (**(code **)(*piVar4 + 0x60))();
    iVar6 = *piVar23;
    iVar25 = (piVar23[1] - iVar6 >> 2) + -1;
    while( true ) {
      iVar26 = *(int *)(iVar6 + iVar25 * 4);
      std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______find((unsigned char *)local_80,iVar26,uVar24);
      iVar6 = 0;
      if (local_80[0] != *(int *)(iVar26 + 4)) {
        iVar6 = *(int *)(local_80[0] + 0x18);
      }
      iVar25 = iVar25 + -1;
      if ((iVar6 != 0) || (iVar25 < 0)) break;
      iVar6 = *piVar23;
    }
    iVar6 = *(int *)(iVar6 + 0x38);
  }
  else {
    puVar21 = (undefined4 *)piVar8[0xe];
    if (puVar21 == (undefined4 *)0x0) {
      if (piVar8[5] == 0) {
        uVar5 = piVar8[0xc];
        if ((uVar5 & 0x400) == 0) {
          iVar6 = (int)(uVar5 << 0xd | uVar5 >> 0x13) >> 0x18;
        }
        else {
          iVar6 = (int)(uVar5 << 0xd | uVar5 >> 0x13) >> 0x18;
          iVar6 = iVar6 * iVar6;
        }
      }
      else {
        iVar6 = piVar8[9];
      }
      pTVar7 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
      puVar21 = (undefined4 *)((int (*)())TPoolAllocator__allocate)(pTVar7,iVar6 << 2);
      piVar8[0xe] = (int)puVar21;
    }
    ppuVar13 = *(undefined ***)(param_4 + 8);
    if (ppuVar13 == (undefined **)0x1) {
      local_10c = *(int **)(param_4 + 0x14);
      uVar5 = *(uint *)(param_4 + 4);
      uVar19 = 0;
      ppuVar16 = *(undefined ***)param_4;
      local_114 = *(uint *)(param_4 + 0xc);
      local_110 = *(uint *)(param_4 + 0x10);
      local_108 = *(undefined4 *)(param_4 + 0x18);
      local_12c = (local_110 & 1) << 9 |
                  (local_114 & 1) << 10 |
                  ((uint)ppuVar16 & 0x3f) << 0x13 | uVar5 << 0x19 | local_12c & 0x1ff | 0x800;
      local_150 = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
      local_130 = 0;
      local_14c = 0;
      local_148 = (undefined **)0x0;
      local_144 = 0;
      local_140 = (undefined **)0x0;
      local_13c = 0;
      local_138 = 0;
      local_134 = 0;
      ppuVar9 = local_140;
      local_120 = ppuVar16;
      local_11c = uVar5;
      local_118 = ppuVar13;
      local_100 = ppuVar16;
      local_fc = uVar5;
      local_f8 = ppuVar13;
      local_f4 = local_114;
      local_f0 = local_110;
      local_ec = local_10c;
      local_e8 = local_108;
      if (local_10c != (int *)0x0) {
        local_148 = (undefined **)local_10c[2];
        local_138 = TType__setStructSize((unsigned char *)&local_150,(unsigned char *)local_10c[2]);
        iVar6 = (**(code **)(*local_ec + 0x18))(local_ec);
        uVar19 = (uint)*DAT_a7b7ba18;
        *(byte *)(*(int *)(iVar6 + 4) + *(int *)(*(int *)(iVar6 + 4) + -0xc)) = *DAT_a7b7ba18;
        pcVar27 = *(char **)(iVar6 + 4);
        pTVar7 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
        ppuVar13 = (undefined **)((int (*)())TPoolAllocator__allocate)(pTVar7,8);
        ppuVar9 = (undefined **)0x0;
        if (ppuVar13 != (undefined **)0x0) {
          local_90[0] = ((int (*)())GetGlobalPoolAllocator)();
          __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                    (ppuVar13,pcVar27,(unsigned char *)local_90);
          ppuVar9 = ppuVar13;
        }
      }
      local_140 = ppuVar9;
      local_150 = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
      if ((local_12c >> 0x13 & 0x3f) != 0xe) {
        iVar6 = *(int *)param_4;
        if (iVar6 != 2) {
          if (iVar6 < 3) {
            if (iVar6 == 1) {
              iVar6 = (**(code **)(*(int *)param_5 + 0x18))(param_5);
              *puVar21 = **(undefined4 **)(iVar6 + 0x30);
              goto LAB_97b9e850;
            }
          }
          else if (iVar6 == 3) goto LAB_97b9e3bc;
          pcVar27 = "";
          pcVar15 = " cannot initialize constant of this type";
LAB_97b9df14:
          error((int)this,(char *)param_2,pcVar15,pcVar27,"",ppuVar16,uVar19,uVar5);
          return 1;
        }
LAB_97b9e3bc:
        iVar6 = (**(code **)(*(int *)param_5 + 0x18))(param_5);
        *puVar21 = **(undefined4 **)(iVar6 + 0x30);
        goto LAB_97b9e850;
      }
    }
    iVar6 = (**(code **)(*(int *)param_5 + 0x18))(param_5);
    iVar6 = *(int *)(iVar6 + 0x30);
  }
  piVar8[0xe] = iVar6;
LAB_97b9e850:
  *param_6 = (unsigned char *)0x0;
  return 0;
}

/* TParseContext__canNodeBeRemoved @ 0x97b9e960 (204 bytes) */
int TParseContext__canNodeBeRemoved(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  undefined4 uVar1;
  unsigned char * this_00;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  
  this_00 = (unsigned char *)(**(code **)(*(int *)param_2 + 0x1c))(param_2);
  uVar1 = 0;
  if (this_00 != (unsigned char *)0x0) {
    iVar2 = TIntermOperator__isConstructor(this_00);
    if ((iVar2 == 0) || (*(int *)(this_00 + 0x30) == 0x75)) {
      uVar1 = 0;
    }
    else {
      iVar2 = (**(code **)(*(int *)this_00 + 100))(this_00);
      for (puVar5 = *(undefined4 **)(iVar2 + 4); puVar5 != *(undefined4 **)(iVar2 + 8);
          puVar5 = puVar5 + 1) {
        piVar3 = (int *)(**(code **)(*(int *)*puVar5 + 0x14))();
        iVar4 = (**(code **)(*piVar3 + 0x18))();
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
int TParseContext__addConstructor(this, param_2, param_3, param_4, param_5, param_6)
  unsigned char * this;
  unsigned char * param_2;
  unsigned char * param_3;
  int param_4;
  int param_5;
  char *param_6;
{
  bool bVar1;
  unsigned char * pTVar2;
  int iVar3;
  unsigned char * pTVar4;
  undefined4 uVar5;
  int *piVar6;
  unsigned char * pTVar7;
  unsigned char * pTVar8;
  unsigned char * pTVar9;
  char *pcVar10;
  int in_r9;
  undefined4 in_r10;
  undefined4 *puVar11;
  int iVar12;
  undefined4 *puVar13;
  undefined1 auStack_40 [4];
  int local_3c;
  undefined4 *local_38;
  unsigned char * local_34;
  
  if (param_2 == (unsigned char *)0x0) {
    return (unsigned char *)0x0;
  }
  iVar12 = 0;
  bVar1 = param_4 != 0x75;
  puVar11 = (undefined4 *)0x0;
  pcVar10 = param_6;
  pTVar2 = (unsigned char *)(**(code **)(*(int *)param_2 + 0x1c))(param_2);
  if (!bVar1) {
    iVar12 = *(int *)(param_5 + 0x24);
    puVar11 = *(undefined4 **)(iVar12 + 4);
  }
  if (((pTVar2 == (unsigned char *)0x0) || (*(int *)(pTVar2 + 0x30) != 0)) ||
     (iVar3 = (**(code **)(*(int *)pTVar2 + 100))(),
     *(int *)(iVar3 + 8) - *(int *)(iVar3 + 4) >> 2 == 1)) {
    if (bVar1) {
      uVar5 = (*(code *)**(undefined4 **)param_2)(param_2);
      pTVar4 = (unsigned char *)((int (*)())TParseContext__constructBuiltIn)(this,param_3,param_4,param_2,uVar5,0);
      if (pTVar4 == (unsigned char *)0x0) {
        return (unsigned char *)0x0;
      }
      iVar12 = (**(code **)(*(int *)pTVar4 + 0x1c))();
      if (iVar12 == 0) {
        return pTVar4;
      }
      piVar6 = (int *)(**(code **)(*(int *)pTVar4 + 0x1c))(pTVar4);
      iVar12 = (**(code **)(*piVar6 + 100))();
      iVar12 = ((int (*)())TParseContext__canNodeBeRemoved)(this,(unsigned char *)**(undefined4 **)(iVar12 + 4));
      if (iVar12 == 0) {
        return pTVar4;
      }
      piVar6 = (int *)(**(code **)(*(int *)pTVar4 + 0x1c))(pTVar4);
      iVar12 = (**(code **)(*piVar6 + 100))();
      pTVar7 = (unsigned char *)(**(code **)(*(int *)**(undefined4 **)(iVar12 + 4) + 0x1c))();
      pTVar4 = (unsigned char *)
               __ZN13TIntermediate15removeChildNodeEP12TIntermTypedP5TTypeP16TIntermAggregate
                         (*(void **)this,pTVar4,param_3,pTVar7);
      return pTVar4;
    }
    if (*(int *)(iVar12 + 8) - *(int *)(iVar12 + 4) >> 3 == 1) {
      iVar12 = (*(code *)**(undefined4 **)param_2)(param_2);
      pTVar4 = (unsigned char *)((int (*)())TParseContext__constructStruct)(this,param_2,(unsigned char *)*puVar11,1,iVar12,false);
      return pTVar4;
    }
  }
  else {
    pTVar8 = (unsigned char *)(**(code **)(*(int *)pTVar2 + 100))(pTVar2);
    if ((bVar1) ||
       (in_r9 = *(int *)(pTVar8 + 4),
       *(int *)(iVar12 + 8) - *(int *)(iVar12 + 4) >> 3 == *(int *)(pTVar8 + 8) - in_r9 >> 2)) {
      local_3c = 0;
      puVar13 = *(undefined4 **)(pTVar8 + 4);
      do {
        iVar12 = local_3c;
        local_38 = puVar13;
        if (puVar13 == *(undefined4 **)(pTVar8 + 8)) {
          pTVar4 = (unsigned char *)
                   TIntermediate__setAggregateOperator
                             (*(unsigned char **)this,pTVar2,param_4,param_6);
          return pTVar4;
        }
        if (bVar1) {
          uVar5 = (*(code *)**(undefined4 **)param_2)(param_2);
          pTVar9 = (unsigned char *)((int (*)())TParseContext__constructBuiltIn)(this,param_3,param_4,*puVar13,uVar5,1);
          if (pTVar9 != (unsigned char *)0x0) {
            iVar12 = ((int (*)())TParseContext__canNodeBeRemoved)(this,pTVar9);
            if (iVar12 == 0) goto LAB_97b9ed60;
            pTVar7 = (unsigned char *)(**(code **)(*(int *)pTVar9 + 0x1c))(pTVar9);
            __ZN13TIntermediate15removeChildNodeER7TVectorIP11TIntermNodeER5TTypeRiRN9__gnu_cxx17__normal_iteratorIPS2_St6vectorIS2_14pool_allocatorIS2_EEEEP16TIntermAggregate
                      (*(void **)this,pTVar8,param_3,&local_3c,(unsigned char *)&local_38,pTVar7
                      );
          }
        }
        else {
          iVar3 = (*(code *)**(undefined4 **)param_2)(param_2);
          pTVar9 = (unsigned char *)
                   ((int (*)())TParseContext__constructStruct)(this,(unsigned char *)*puVar13,(unsigned char *)puVar11[iVar12 * 2],
                                   local_3c + 1,iVar3,true);
          if (pTVar9 != (unsigned char *)0x0) {
LAB_97b9ed60:
            std__vector_TIntermNode__pool_allocator_TIntermNode_____erase
                      (auStack_40,pTVar8,local_38);
            local_34 = pTVar9;
            std__vector_TIntermNode__pool_allocator_TIntermNode_____insert
                      (auStack_40,pTVar8,local_38,&local_34);
          }
        }
        local_3c = local_3c + 1;
        puVar13 = local_38 + 1;
      } while( true );
    }
  }
  error((int)this,param_6,
        "Number of constructor parameters does not match the number of structure fields",
        "constructor","",pcVar10,in_r9,in_r10);
  return (unsigned char *)0x0;
}

/* TParseContext__constructBuiltIn @ 0x97b9eddc (408 bytes) */
int TParseContext__constructBuiltIn(this, param_2, param_3, param_4, param_5, param_6)
  unsigned char * this;
  unsigned char * param_2;
  int param_3;
  unsigned char * param_4;
  char *param_5;
  int param_6;
{
  bool bVar1;
  undefined4 uVar2;
  unsigned char * pTVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 in_r10;
  undefined4 uVar7;
  undefined **local_50 [2];
  int local_48;
  uint local_2c;
  
  uVar5 = param_3 - 0x66;
  if (uVar5 < 0xf) {
    iVar6 = uVar5 * 4;
    switch(uVar5) {
    case 0:
    case 9:
    case 10:
    case 0xb:
      uVar7 = 0x66;
      break;
    case 1:
    case 6:
    case 7:
    case 8:
      uVar7 = 0x67;
      break;
    default:
      uVar7 = 0x68;
    }
    iVar4 = param_6;
    uVar2 = (*(code *)**(undefined4 **)param_4)(param_4);
    pTVar3 = (unsigned char *)
             TIntermediate__addUnaryMath
                       (*(unsigned char **)this,uVar7,param_4,uVar2,*(undefined4 *)(this + 4));
    if (pTVar3 != (unsigned char *)0x0) {
      if (param_6 != 0) {
        return pTVar3;
      }
      if (pTVar3 != param_4) {
        (**(code **)(*(int *)pTVar3 + 0x38))(local_50,pTVar3);
        bVar1 = false;
        if (((local_2c & 0x1fffe00) == (*(uint *)(param_2 + 0x24) & 0x1fffe00)) &&
           (local_48 == *(int *)(param_2 + 8))) {
          bVar1 = true;
        }
        local_50[0] = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
        if (bVar1) {
          return pTVar3;
        }
      }
      pTVar3 = (unsigned char *)
               TIntermediate__setAggregateOperator(*(unsigned char **)this,pTVar3,param_3,param_5);
      return pTVar3;
    }
    error((int)this,param_5,"can\'t convert","constructor","",iVar4,iVar6,in_r10);
  }
  else {
    error((int)this,param_5,"unsupported construction","","",param_6,uVar5,in_r10);
    TParseContext__recover(this);
  }
  return (unsigned char *)0x0;
}

/* TParseContext__constructStruct @ 0x97b9efb0 (392 bytes) */
int TParseContext__constructStruct(this, param_2, param_3, param_4, param_5, param_6)
  unsigned char * this;
  unsigned char * param_2;
  unsigned char * param_3;
  int param_4;
  int param_5;
  int param_6;
{
  int *piVar1;
  undefined4 uVar2;
  unsigned char * pTVar3;
  undefined4 uVar4;
  undefined3 in_register_00000020;
  bool bVar5;
  undefined **local_80 [2];
  int local_78;
  uint local_5c;
  undefined **local_50 [9];
  uint local_2c;
  
  piVar1 = (int *)(**(code **)(*(int *)param_2 + 0x14))(param_2);
  (**(code **)(*piVar1 + 0x38))(local_80,piVar1);
  bVar5 = false;
  if (((*(uint *)(param_3 + 0x24) & 0x1fffe00) == (local_5c & 0x1fffe00)) &&
     (*(int *)(param_3 + 8) == local_78)) {
    bVar5 = true;
  }
  local_80[0] = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  if (bVar5) {
    if (CONCAT31(in_register_00000020,param_6) == 0) {
      pTVar3 = (unsigned char *)(**(code **)(*(int *)param_2 + 0x14))(param_2);
      uVar2 = TIntermediate__setAggregateOperator(*(unsigned char **)this,pTVar3,0x75,param_5);
    }
    else {
      uVar2 = (**(code **)(*(int *)param_2 + 0x14))(param_2);
    }
  }
  else {
    uVar2 = TType__getBasicString(*(uint *)(param_3 + 0x24) >> 0x13 & 0x3f);
    piVar1 = (int *)(**(code **)(*(int *)param_2 + 0x14))(param_2);
    (**(code **)(*piVar1 + 0x38))(local_50,piVar1);
    uVar4 = TType__getBasicString(local_2c >> 0x13 & 0x3f);
    error((int)this,(char *)param_5,"","constructor",
          "cannot convert parameter %d from \'%s\' to \'%s\'",param_4,uVar4,uVar2);
    local_50[0] = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
    TParseContext__recover(this);
    uVar2 = 0;
  }
  return uVar2;
}

/* TParseContext__addConstVectorNode @ 0x97b9f138 (148 bytes) */
int TParseContext__addConstVectorNode(this, param_2, param_3, param_4)
  unsigned char * this;
  unsigned char * param_2;
  unsigned char * param_3;
  int param_4;
{
  undefined *puVar1;
  undefined **ppuVar2;
  int iVar3;
  undefined *puVar4;
  int iVar5;
  unsigned char * pTVar6;
  int *piVar7;
  unsigned char * pTVar8;
  unsigned char * pcVar9;
  unsigned char * pTVar10;
  uint a1;
  undefined4 in_r8;
  undefined4 in_r9;
  undefined4 in_r10;
  unsigned char * pcVar11;
  void *this_00;
  int iVar12;
  char in_RESERVE;
  byte bVar13;
  undefined **local_90 [4];
  char acStack_80 [20];
  uint local_6c;
  unsigned char aaStack_40 [16];
  
  iVar5 = (**(code **)(*(int *)param_3 + 0x18))(param_3);
  pTVar6 = (unsigned char *)(**(code **)(*(int *)param_3 + 0x1c))(param_3);
  if (iVar5 != 0) {
    pcVar11 = *(unsigned char **)(iVar5 + 0x30);
    if (pcVar11 == (unsigned char *)0x0) {
      this_00 = *(void **)(this + 8);
                    
      __ZN13TInfoSinkBase6appendEPKc(this_00,"INTERNAL ERROR: ");
      a1 = param_4 & 0xffff;
      bVar13 = (a1 == 0) << 1;
      if (a1 == 0) {
        _sprintf(acStack_80,"%d:? ",param_4 >> 0x10);
      }
      else {
        _sprintf(acStack_80,"%d:%d",param_4 >> 0x10,a1);
      }
      __ZNSsC1EPKcRKSaIcE(local_90,acStack_80,aaStack_40);
      *(undefined *)((int)local_90[0] + (int)local_90[0][-3]) = *PTR__S_terminal_a7b7c0b8;
      __ZN13TInfoSinkBase6appendEPKc(this_00,(char *)local_90[0]);
      ppuVar2 = local_90[0] + -1;
      do {
        puVar4 = *ppuVar2;
        if (in_RESERVE != '\0') {
          puVar1 = (undefined *)storeWordConditionalIndexed(puVar4 + -1,0,ppuVar2);
          *ppuVar2 = puVar1;
          bVar13 = 2;
        }
      } while (!(bool)(bVar13 >> 1 & 1));
      if ((int)puVar4 < 1) {
        __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(local_90[0] + -3));
      }
      __ZN13TInfoSinkBase6appendEPKc(this_00,": ");
      __ZN13TInfoSinkBase6appendEPKc
                (this_00,"constUnion not initialized in addConstVectorNode function");
      __ZN13TInfoSinkBase6appendEPKc(this_00,"\n");
      TParseContext__recover(this);
      return param_3;
    }
    goto LAB_97b9f4c4;
  }
  if (pTVar6 == (unsigned char *)0x0) {
    error((int)this,(char *)param_4,"No aggregate or constant union node available","Internal Error"
          ,"",in_r8,in_r9,in_r10);
    TParseContext__recover(this);
    return (unsigned char *)0x0;
  }
  (**(code **)(*(int *)pTVar6 + 0x38))(local_90,pTVar6);
  if ((local_6c & 0x400) == 0) {
    iVar5 = (int)(local_6c << 0xd | local_6c >> 0x13) >> 0x18;
  }
  else {
    iVar5 = (int)(local_6c << 0xd | local_6c >> 0x13) >> 0x18;
    iVar5 = iVar5 * iVar5;
  }
  pTVar8 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
  pcVar11 = (unsigned char *)((int (*)())TPoolAllocator__allocate)(pTVar8,iVar5 << 2);
  local_90[0] = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  piVar7 = (int *)(**(code **)(*(int *)pTVar6 + 0x1c))(pTVar6);
  iVar5 = (**(code **)(*piVar7 + 100))();
  if (*(int *)(iVar5 + 8) - *(int *)(iVar5 + 4) >> 2 == 1) {
    piVar7 = (int *)(**(code **)(*(int *)pTVar6 + 0x1c))(pTVar6);
    iVar5 = (**(code **)(*piVar7 + 100))();
    piVar7 = (int *)(**(code **)(*(int *)**(undefined4 **)(iVar5 + 4) + 0x14))();
    iVar5 = (**(code **)(*piVar7 + 0x18))();
    if (iVar5 == 0) goto LAB_97b9f438;
    (**(code **)(*(int *)pTVar6 + 0x38))(local_90,pTVar6);
    in_r10 = 1;
    iVar5 = TIntermediate__parseConstTree
                      (*(unsigned char **)this,param_4,pTVar6,pcVar11,*(undefined4 *)(pTVar6 + 0x30)
                       ,*(undefined4 *)(this + 4),local_90,1);
  }
  else {
LAB_97b9f438:
    (**(code **)(*(int *)pTVar6 + 0x38))(local_90,pTVar6);
    in_r10 = 0;
    iVar5 = TIntermediate__parseConstTree
                      (*(unsigned char **)this,param_4,pTVar6,pcVar11,*(undefined4 *)(pTVar6 + 0x30)
                       ,*(undefined4 *)(this + 4),local_90,0);
  }
  local_90[0] = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  if (iVar5 != 0) {
    return (unsigned char *)0x0;
  }
LAB_97b9f4c4:
  iVar5 = *(int *)(param_2 + 0x10);
  iVar12 = 0;
  pTVar8 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
  pcVar9 = (unsigned char *)((int (*)())TPoolAllocator__allocate)(pTVar8,iVar5 << 2);
  if (0 < *(int *)(param_2 + 0x10)) {
    iVar5 = 0;
    do {
      (**(code **)(*(int *)param_3 + 0x38))(local_90,param_3);
      if ((local_6c & 0x400) == 0) {
        iVar3 = (int)(local_6c << 0xd | local_6c >> 0x13) >> 0x18;
      }
      else {
        iVar3 = (int)(local_6c << 0xd | local_6c >> 0x13) >> 0x18;
        iVar3 = iVar3 * iVar3;
      }
      local_90[0] = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
      if (iVar3 <= *(int *)(param_2 + iVar5) != 0) {
        error((int)this,(char *)param_4,"","[","vector field selection out of range \'%d\'",
              *(undefined4 *)(param_2 + iVar5),(uint)(iVar3 <= *(int *)(param_2 + iVar5)),in_r10);
        TParseContext__recover(this);
        *(undefined4 *)(param_2 + iVar5) = 0;
      }
      iVar12 = iVar12 + 1;
      *(undefined4 *)(pcVar9 + iVar5) = *(undefined4 *)(pcVar11 + *(int *)(param_2 + iVar5) * 4);
      iVar5 = iVar5 + 4;
    } while (iVar12 < *(int *)(param_2 + 0x10));
  }
  (**(code **)(*(int *)param_3 + 0x38))(local_90,param_3);
  pTVar10 = (unsigned char *)
            TIntermediate__addConstantUnion
                      (*(unsigned char **)this,pcVar9,(unsigned char *)local_90,param_4);
  return pTVar10;
}

/* TParseContext__addConstMatrixNode @ 0x97b9f600 (904 bytes) */
int TParseContext__addConstMatrixNode(this, param_2, param_3, param_4)
  unsigned char * this;
  int param_2;
  unsigned char * param_3;
  int param_4;
{
  int *piVar1;
  unsigned char * pTVar2;
  undefined4 uVar3;
  unsigned char * this_00;
  unsigned char * pcVar4;
  int in_r8;
  undefined4 in_r9;
  undefined4 in_r10;
  int iVar5;
  int iVar6;
  undefined **local_60 [9];
  uint local_3c;
  
  piVar1 = (int *)(**(code **)(*(int *)param_3 + 0x18))(param_3);
  pTVar2 = (unsigned char *)(**(code **)(*(int *)param_3 + 0x1c))(param_3);
  (**(code **)(*(int *)param_3 + 0x38))(local_60,param_3);
  local_60[0] = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  iVar5 = param_2;
  if ((int)(local_3c << 0xd | local_3c >> 0x13) >> 0x18 <= param_2) {
    iVar5 = 0;
    error((int)this,(char *)param_4,"","[","matrix field selection out of range \'%d\'",param_2,
          in_r9,in_r10);
    TParseContext__recover(this);
    in_r8 = param_2;
  }
  if (piVar1 != (int *)0x0) {
    iVar6 = piVar1[0xc];
    (**(code **)(*piVar1 + 0x38))((unsigned char *)local_60,piVar1);
    local_60[0] = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
    (**(code **)(*piVar1 + 0x38))((unsigned char *)local_60,piVar1);
    uVar3 = TIntermediate__addConstantUnion
                      (*(unsigned char **)this,
                       (unsigned char *)
                       (iVar6 + ((int)(local_3c << 0xd | local_3c >> 0x13) >> 0x18) * iVar5 * 4),
                       (unsigned char *)local_60,param_4);
    return uVar3;
  }
  if (pTVar2 == (unsigned char *)0x0) {
    error((int)this,(char *)param_4,"No Aggregate or Constant Union node available","Internal Error"
          ,"",in_r8,in_r9,in_r10);
    TParseContext__recover(this);
    return 0;
  }
  (**(code **)(*(int *)pTVar2 + 0x38))((unsigned char *)local_60,pTVar2);
  if ((local_3c & 0x400) == 0) {
    iVar6 = (int)(local_3c << 0xd | local_3c >> 0x13) >> 0x18;
  }
  else {
    iVar6 = (int)(local_3c << 0xd | local_3c >> 0x13) >> 0x18;
    iVar6 = iVar6 * iVar6;
  }
  this_00 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
  pcVar4 = (unsigned char *)((int (*)())TPoolAllocator__allocate)(this_00,iVar6 << 2);
  local_60[0] = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  (**(code **)(*(int *)pTVar2 + 0x38))((unsigned char *)local_60,pTVar2);
  local_60[0] = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  piVar1 = (int *)(**(code **)(*(int *)pTVar2 + 0x1c))(pTVar2);
  iVar6 = (**(code **)(*piVar1 + 100))();
  if (*(int *)(iVar6 + 8) - *(int *)(iVar6 + 4) >> 2 == 1) {
    piVar1 = (int *)(**(code **)(*(int *)pTVar2 + 0x1c))(pTVar2);
    iVar6 = (**(code **)(*piVar1 + 100))();
    piVar1 = (int *)(**(code **)(*(int *)**(undefined4 **)(iVar6 + 4) + 0x14))();
    iVar6 = (**(code **)(*piVar1 + 0x18))();
    if (iVar6 != 0) {
      (**(code **)(*(int *)pTVar2 + 0x38))((unsigned char *)local_60,pTVar2);
      iVar6 = TIntermediate__parseConstTree
                        (*(unsigned char **)this,param_4,pTVar2,pcVar4,
                         *(undefined4 *)(pTVar2 + 0x30),*(undefined4 *)(this + 4),(unsigned char *)local_60,
                         1);
      goto LAB_97b9f8f4;
    }
  }
  (**(code **)(*(int *)pTVar2 + 0x38))(local_60,pTVar2);
  iVar6 = TIntermediate__parseConstTree
                    (*(unsigned char **)this,param_4,pTVar2,pcVar4,*(undefined4 *)(pTVar2 + 0x30),
                     *(undefined4 *)(this + 4),local_60,0);
LAB_97b9f8f4:
  local_60[0] = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  uVar3 = 0;
  if (iVar6 == 0) {
    (**(code **)(*(int *)pTVar2 + 0x38))(local_60,pTVar2);
    uVar3 = TIntermediate__addConstantUnion
                      (*(unsigned char **)this,
                       pcVar4 + ((int)(local_3c << 0xd | local_3c >> 0x13) >> 0x18) * iVar5 * 4,
                       (unsigned char *)local_60,param_4);
  }
  return uVar3;
}

/* TParseContext__addConstStruct @ 0x97b9f988 (848 bytes) */
int TParseContext__addConstStruct(this, param_2, param_3, param_4)
  unsigned char * this;
  unsigned char * param_2;
  unsigned char * param_3;
  int param_4;
{
  unsigned char * pTVar1;
  unsigned char * pTVar2;
  int iVar3;
  unsigned char * this_00;
  unsigned char * this_01;
  int *piVar4;
  undefined4 uVar5;
  uint *puVar6;
  undefined4 in_r8;
  int iVar7;
  undefined4 in_r10;
  int iVar8;
  uint uVar9;
  uint uVar10;
  unsigned char * pcVar11;
  uint uVar12;
  undefined **local_80 [2];
  int local_78;
  int local_68;
  uint local_50;
  uint local_4c [5];
  
  iVar8 = 0;
  (**(code **)(*(int *)param_3 + 0x38))(local_80,param_3);
  iVar7 = *(int *)param_3;
  local_80[0] = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  pTVar1 = (unsigned char *)(**(code **)(iVar7 + 0x18))(param_3);
  pTVar2 = (unsigned char *)(**(code **)(*(int *)param_3 + 0x1c))(param_3);
  for (uVar9 = 0; uVar9 < (uint)(*(int *)(local_78 + 8) - *(int *)(local_78 + 4) >> 3);
      uVar9 = uVar9 + 1) {
    iVar3 = (**(code **)(**(int **)(*(int *)(local_78 + 4) + uVar9 * 8) + 0x1c))();
    uVar12 = *(uint *)(*(int *)(iVar3 + 4) + -0xc);
    local_50 = uVar12;
    uVar10 = *(uint *)((int)*(void **)(param_2 + 4) + -0xc);
    local_4c[0] = uVar10;
    puVar6 = local_4c;
    if (uVar12 <= uVar10) {
      puVar6 = &local_50;
    }
    iVar3 = _memcmp(*(void **)(iVar3 + 4),*(void **)(param_2 + 4),*puVar6);
    if (iVar3 == 0) {
      iVar3 = uVar12 - uVar10;
    }
    if (iVar3 == 0) break;
    this_00 = *(unsigned char **)(*(int *)(local_78 + 4) + uVar9 * 8);
    if (*(unsigned char **)(this_00 + 8) == (unsigned char *)0x0) {
      iVar3 = (**(code **)(*(int *)this_00 + 0x30))();
    }
    else {
      iVar3 = TType__setStructSize(this_00,*(unsigned char **)(this_00 + 8));
    }
    iVar8 = iVar8 + iVar3;
  }
  if (pTVar1 != (unsigned char *)0x0) {
    iVar7 = *(int *)pTVar1;
    pcVar11 = *(unsigned char **)(pTVar1 + 0x30);
    pTVar2 = pTVar1;
    goto LAB_97b9fc60;
  }
  if (pTVar2 == (unsigned char *)0x0) {
    error((int)this,(char *)param_4,"No Aggregate or Constant Union node available","Internal Error"
          ,"",in_r8,iVar7,in_r10);
    TParseContext__recover(this);
    return 0;
  }
  (**(code **)(*(int *)pTVar2 + 0x38))(local_80,pTVar2);
  this_01 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
  pcVar11 = (unsigned char *)((int (*)())TPoolAllocator__allocate)(this_01,local_68 << 2);
  local_80[0] = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  piVar4 = (int *)(**(code **)(*(int *)pTVar2 + 0x1c))(pTVar2);
  iVar7 = (**(code **)(*piVar4 + 100))();
  if (*(int *)(iVar7 + 8) - *(int *)(iVar7 + 4) >> 2 == 1) {
    piVar4 = (int *)(**(code **)(*(int *)pTVar2 + 0x1c))(pTVar2);
    iVar7 = (**(code **)(*piVar4 + 100))();
    piVar4 = (int *)(**(code **)(*(int *)**(undefined4 **)(iVar7 + 4) + 0x14))();
    iVar7 = (**(code **)(*piVar4 + 0x18))();
    if (iVar7 == 0) goto LAB_97b9fc00;
    (**(code **)(*(int *)pTVar2 + 0x38))(local_80,pTVar2);
    iVar7 = TIntermediate__parseConstTree
                      (*(unsigned char **)this,param_4,pTVar2,pcVar11,*(undefined4 *)(pTVar2 + 0x30)
                       ,*(undefined4 *)(this + 4),local_80,1);
  }
  else {
LAB_97b9fc00:
    (**(code **)(*(int *)pTVar2 + 0x38))(local_80,pTVar2);
    iVar7 = TIntermediate__parseConstTree
                      (*(unsigned char **)this,param_4,pTVar2,pcVar11,*(undefined4 *)(pTVar2 + 0x30)
                       ,*(undefined4 *)(this + 4),local_80,0);
  }
  local_80[0] = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  if (iVar7 != 0) {
    return 0;
  }
  iVar7 = *(int *)pTVar2;
LAB_97b9fc60:
  (**(code **)(iVar7 + 0x38))(local_80,pTVar2);
  uVar5 = TIntermediate__addConstantUnion
                    (*(unsigned char **)this,pcVar11 + iVar8 * 4,(unsigned char *)local_80,param_4);
  return uVar5;
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
  undefined4 local_50 [4];
  undefined4 local_40 [4];
  uint local_30;
  uint local_2c [4];
  
  local_c0[0] = ((int (*)())GetGlobalPoolAllocator)();
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
            ((unsigned char *)&local_d0,"GL_ARB_texture_rectangle",(unsigned char *)local_c0);
  std___Rb_tree_std__string_std__pair_std__string_const_TBehavior__std___Select1st_std__pair_std__string_const_TBehavior___std__less_std__string__pool_allocator_std__pair_std__string_const_TBehavior_____lower_bound((unsigned char *)local_b0,this + 0x30,(unsigned char *)&local_d0);
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
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&local_70,(unsigned char *)&local_d0);
  local_68 = 0;
  local_60[0] = local_80;
  __ZNSt8_Rb_treeISbIcSt11char_traitsIcE14pool_allocatorIcEESt4pairIKS4_9TBehaviorESt10_Select1stIS8_ESt4lessIS4_ES2_IS8_EE13insert_uniqueESt17_Rb_tree_iteratorIS8_RS8_PS8_ERKS8_
            (local_90,this + 0x30,local_60,&local_70);
  piVar1 = (int *)(local_6c + -4);
  local_b0[0] = local_90[0];
  local_50[0] = local_70;
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
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
              ((unsigned char *)(local_6c + -0xc),local_50);
    iVar2 = local_b0[0];
  }
LAB_97b9fe04:
  *(undefined4 *)(iVar2 + 0x18) = 1;
  piVar1 = (int *)((int)local_cc + -4);
  local_40[0] = local_d0;
  do {
    iVar2 = *piVar1;
    if (in_RESERVE != '\0') {
      iVar3 = storeWordConditionalIndexed(iVar2 + -1,0,piVar1);
      *piVar1 = iVar3;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar2 < 1) {
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
              ((unsigned char *)((int)local_cc + -0xc),local_40);
  }
  return;
}

/* InitializeGlobalPools @ 0x97b9fe54 (144 bytes) */
int InitializeGlobalPools()
{
  undefined4 in_r3;
  unsigned char * this;
  undefined4 uVar1;
  
  if (_gPollAllocThreadData == (undefined4 *)0x0) {
    this = operator_new(0x34);
    ((int (*)())__ZN14TPoolAllocatorC1Ebii)(this,true,0x2000,0x10);
    _gPollAllocThreadData = operator_new(8);
    _gPollAllocThreadData[1] = 0;
    *_gPollAllocThreadData = this;
    _gPollAllocThreadData[1] = 0;
    uVar1 = ((int (*)())TPoolAllocator__push)(this);
    return uVar1;
  }
  return in_r3;
}

/* FreeGlobalPools @ 0x97b9fee4 (112 bytes) */
int FreeGlobalPools()
{
  undefined4 in_r3;
  unsigned char * this;
  void *this_00;
  
  if (_gPollAllocThreadData != (void *)0x0) {
    this = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
    ((int (*)())TPoolAllocator__popAll)(this);
    this_00 = (void *)((int (*)())GetGlobalPoolAllocator)();
    if (this_00 != (void *)0x0) {
      ((int (*)())__ZN14TPoolAllocatorD1Ev)(this_00);
      __ZdlPv(this_00);
    }
    in_r3 = __ZdlPv(_gPollAllocThreadData);
    _gPollAllocThreadData = (void *)0x0;
  }
  return in_r3;
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
  return (int)((unsigned char *)_gPollAllocThreadData + 4);
}

/* __ZN14TPoolAllocatorC2Ebii @ 0x97b9ffb4 (4 bytes) */
int __ZN14TPoolAllocatorC2Ebii(this, param_2, param_3, param_4)
  void *this;
  int param_2;
  int param_3;
  int param_4;
{
  undefined3 in_register_00000010;
  uint uVar1;
  
  *(uint *)this = CONCAT31(in_register_00000010,param_2);
  *(int *)((int)this + 8) = param_4;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x28) = 0;
  *(undefined4 *)((int)this + 0x2c) = 0;
  *(int *)((int)this + 4) = param_3;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  if ((uint)param_3 < 0x1000) {
    *(undefined4 *)((int)this + 4) = 0x1000;
  }
  uVar1 = *(uint *)((int)this + 8) & 0xfffffffc;
  *(undefined4 *)((int)this + 0x14) = *(undefined4 *)((int)this + 4);
  *(uint *)((int)this + 8) = uVar1;
  if (uVar1 < 4) {
    *(undefined4 *)((int)this + 8) = 4;
  }
  uVar1 = 1;
  if (1 < *(uint *)((int)this + 8)) {
    do {
      uVar1 = uVar1 << 1;
    } while (uVar1 < *(uint *)((int)this + 8));
  }
  *(uint *)((int)this + 8) = uVar1;
  *(uint *)((int)this + 0x10) = uVar1 + 7 & ~(uVar1 - 1);
  *(uint *)((int)this + 0xc) = uVar1 - 1;
  return;
}

/* __ZN14TPoolAllocatorC1Ebii @ 0x97b9ffb8 (4 bytes) */
int __ZN14TPoolAllocatorC1Ebii(this, param_2, param_3, param_4)
  void *this;
  int param_2;
  int param_3;
  int param_4;
{
  undefined3 in_register_00000010;
  uint uVar1;
  
  *(uint *)this = CONCAT31(in_register_00000010,param_2);
  *(int *)((int)this + 8) = param_4;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x28) = 0;
  *(undefined4 *)((int)this + 0x2c) = 0;
  *(int *)((int)this + 4) = param_3;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  if ((uint)param_3 < 0x1000) {
    *(undefined4 *)((int)this + 4) = 0x1000;
  }
  uVar1 = *(uint *)((int)this + 8) & 0xfffffffc;
  *(undefined4 *)((int)this + 0x14) = *(undefined4 *)((int)this + 4);
  *(uint *)((int)this + 8) = uVar1;
  if (uVar1 < 4) {
    *(undefined4 *)((int)this + 8) = 4;
  }
  uVar1 = 1;
  if (1 < *(uint *)((int)this + 8)) {
    do {
      uVar1 = uVar1 << 1;
    } while (uVar1 < *(uint *)((int)this + 8));
  }
  *(uint *)((int)this + 8) = uVar1;
  *(uint *)((int)this + 0x10) = uVar1 + 7 & ~(uVar1 - 1);
  *(uint *)((int)this + 0xc) = uVar1 - 1;
  return;
}

/* __ZN14TPoolAllocatorC4Ebii @ 0x97b9ffbc (152 bytes) */
int __ZN14TPoolAllocatorC4Ebii(this, param_2, param_3, param_4)
  void *this;
  int param_2;
  int param_3;
  int param_4;
{
  undefined3 in_register_00000010;
  uint uVar1;
  
  *(uint *)this = CONCAT31(in_register_00000010,param_2);
  *(int *)((int)this + 8) = param_4;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x28) = 0;
  *(undefined4 *)((int)this + 0x2c) = 0;
  *(int *)((int)this + 4) = param_3;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  if ((uint)param_3 < 0x1000) {
    *(undefined4 *)((int)this + 4) = 0x1000;
  }
  uVar1 = *(uint *)((int)this + 8) & 0xfffffffc;
  *(undefined4 *)((int)this + 0x14) = *(undefined4 *)((int)this + 4);
  *(uint *)((int)this + 8) = uVar1;
  if (uVar1 < 4) {
    *(undefined4 *)((int)this + 8) = 4;
  }
  uVar1 = 1;
  if (1 < *(uint *)((int)this + 8)) {
    do {
      uVar1 = uVar1 << 1;
    } while (uVar1 < *(uint *)((int)this + 8));
  }
  *(uint *)((int)this + 8) = uVar1;
  *(uint *)((int)this + 0x10) = uVar1 + 7 & ~(uVar1 - 1);
  *(uint *)((int)this + 0xc) = uVar1 - 1;
  return;
}

/* __ZN14TPoolAllocatorD2Ev @ 0x97ba0054 (8 bytes) */
int __ZN14TPoolAllocatorD2Ev(this)
  void *this;
{
  ((int (*)())__ZN14TPoolAllocatorD4Ev)(this);
  return;
}

/* __ZN14TPoolAllocatorD1Ev @ 0x97ba005c (8 bytes) */
int __ZN14TPoolAllocatorD1Ev(this)
  void *this;
{
  ((int (*)())__ZN14TPoolAllocatorD4Ev)(this);
  return;
}

/* __ZN14TPoolAllocatorD4Ev @ 0x97ba0064 (184 bytes) */
int __ZN14TPoolAllocatorD4Ev(this)
  void *this;
{
  undefined4 *puVar1;
  int iVar2;
  void *pvVar3;
  
  if (*(int *)this == 0) {
    puVar1 = *(void **)((int)this + 0x1c);
    while (puVar1 != (void *)0x0) {
      pvVar3 = (void *)*puVar1;
      __ZdaPv(puVar1);
      *(void **)((int)this + 0x1c) = pvVar3;
      puVar1 = pvVar3;
    }
  }
  puVar1 = *(void **)((int)this + 0x18);
  while (puVar1 != (void *)0x0) {
    pvVar3 = (void *)*puVar1;
    __ZdaPv(puVar1);
    *(void **)((int)this + 0x18) = pvVar3;
    puVar1 = pvVar3;
  }
  for (iVar2 = *(int *)((int)this + 0x20); iVar2 != *(int *)((int)this + 0x24); iVar2 = iVar2 + 8) {
  }
  iVar2 = *(int *)((int)this + 0x28) - (int)*(void **)((int)this + 0x20) >> 3;
  if (iVar2 != 0) {
    std____default_alloc_template_true_0___deallocate(*(void **)((int)this + 0x20),iVar2 << 3);
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
    std__vector_TPoolAllocator__tAllocState_std__allocator_TPoolAllocator__tAllocState_____M_insert_aux((unsigned char *)(this + 0x20),*(undefined4 *)(this + 0x24),&local_30);
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
        __ZdaPv(puVar1);
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
int TPoolAllocator__allocate(this, param_2)
  unsigned char * this;
  ulong param_2;
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
  iVar7 = param_2 + (int)TAllocation__guardBlockSize * 2;
  uVar3 = *(ulong *)(this + 4);
  uVar5 = iVar6 + iVar7;
  *(int *)(this + 0x2c) = *(int *)(this + 0x2c) + 1;
  *(ulong *)(this + 0x30) = *(int *)(this + 0x30) + param_2;
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
int QualifierWritten(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  unsigned char * param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
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
  if (param_1 != (unsigned char *)0x0) {
    local_1c = param_2;
    (**(code **)(*(int *)param_1 + 8))(param_1,&local_50);
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
  unsigned char * pTVar5;
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
    ((int (*)())__ZN14TPoolAllocatorC1Ebii)(this,true,0x2000,0x10);
    _PerProcessGPA = this;
    ((int (*)())TPoolAllocator__push)(this);
    ((int (*)())SetGlobalPoolAllocatorPtr)(_PerProcessGPA);
    pTVar5 = (unsigned char *)((int (*)())GetResources)();
    ((int (*)())generateBuiltInSymbolTable)(pTVar5,(unsigned char *)&local_40,(unsigned char *)0x0,4);
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
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(local_38 + -0xc));
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
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(local_40 + -0xc));
  }
  return uVar6;
}

/* _ShConstructCompiler @ 0x97ba0980 (32 bytes) */
int _ShConstructCompiler(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ConstructCompiler(param_1,param_2);
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
    ((int (*)())TPoolAllocator__popAll)(_PerProcessGPA);
    pTVar1 = _PerProcessGPA;
    if (_PerProcessGPA != (unsigned char *)0x0) {
      ((int (*)())__ZN14TPoolAllocatorD1Ev)(_PerProcessGPA);
      __ZdlPv(pTVar1);
    }
    _PerProcessGPA = (unsigned char *)0x0;
  }
  DetachProcess();
  return 1;
}

/* generateBuiltInSymbolTable @ 0x97ba0adc (112 bytes) */
int generateBuiltInSymbolTable(param_1, param_2, param_3, param_4)
  unsigned char * param_1;
  unsigned char * param_2;
  unsigned char * param_3;
  undefined4 param_4;
{
  unsigned char aTStack_30 [28];
  
  __ZN9TBuiltIns10initializeERK16TBuiltInResource(aTStack_30);
  ((int (*)())initializeSymbolTable)((unsigned char *)aTStack_30,0,param_2,param_1,param_3);
  ((int (*)())initializeSymbolTable)((unsigned char *)aTStack_30,1,param_2,param_1,param_3);
  return 1;
}

/* initializeSymbolTable @ 0x97ba0b4c (548 bytes) */
int initializeSymbolTable(param_1, param_2, param_3, param_4, param_5)
  unsigned char * param_1;
  int param_2;
  void *param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  unsigned char * this;
  unsigned char * this_00;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  char **ppcVar7;
  undefined4 uVar8;
  uint uVar9;
  char in_RESERVE;
  byte in_cr0;
  byte bVar10;
  void **local_130;
  unsigned char * local_12c;
  void *local_128;
  int local_124;
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_10c;
  unsigned char * local_100;
  undefined4 *local_fc;
  int local_f8;
  undefined4 local_f0;
  undefined4 local_ec;
  unsigned char * local_e8;
  undefined4 *local_e4;
  int local_e0;
  undefined4 local_d8;
  int local_d4;
  unsigned char * local_c0;
  unsigned char * local_b0;
  undefined4 local_a0;
  unsigned char * local_90;
  undefined4 *local_80 [4];
  undefined4 local_70 [4];
  undefined4 auStack_60 [4];
  undefined4 auStack_50 [4];
  void *local_40 [7];
  
  local_40[0] = param_3;
  this = (unsigned char *)((int (*)())GetSymbolTable)(param_2);
  local_130 = local_40;
  local_120 = 0;
  local_11c = 0;
  local_118 = 0;
  local_114 = 0;
  local_110 = 0;
  local_10c = 0;
  local_12c = this;
  local_128 = param_3;
  local_124 = param_2;
  local_100 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
  local_fc = (undefined4 *)0x0;
  local_c0 = local_100;
  local_fc = (undefined4 *)((int (*)())TPoolAllocator__allocate)(local_100,0x1c);
  local_f8 = 0;
  *local_fc = 0;
  local_fc[1] = 0;
  local_fc[2] = local_fc;
  local_fc[3] = local_fc;
  local_f0 = 1;
  local_ec = 0;
  local_e8 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
  local_e4 = (undefined4 *)0x0;
  local_b0 = local_e8;
  local_e4 = (undefined4 *)((int (*)())TPoolAllocator__allocate)(local_e8,0x20);
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
  iVar3 = *(int *)(this + 4) - *(int *)this >> 2;
  bVar10 = (iVar3 != 0) << 1;
  if ((iVar3 != 0) && (iVar3 != 1)) {
    ___eprintf("%s:%u: failed assertion `%s\'\n",
               "/SourceCache/OpenGL/OpenGL-4.7.14/GLProgrammability/glslang/MachineIndependent/ShaderLang.cpp"
               ,0x110,"symbolTable->isEmpty() || symbolTable->atSharedBuiltInLevel()");
  }
  this_00 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
  puVar4 = (undefined4 *)((int (*)())TPoolAllocator__allocate)(this_00,0x10);
  local_90 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
  *puVar4 = local_90;
  puVar4[1] = 0;
  puVar5 = (undefined4 *)((int (*)())TPoolAllocator__allocate)(local_90,0x1c);
  puVar4[2] = 0;
  puVar4[1] = puVar5;
  *puVar5 = 0;
  *(undefined4 *)(puVar4[1] + 4) = 0;
  *(undefined4 *)(puVar4[1] + 8) = puVar4[1];
  *(undefined4 *)(puVar4[1] + 0xc) = puVar4[1];
  piVar2 = *(int **)(this + 4);
  local_80[0] = puVar4;
  if (piVar2 == *(int **)(this + 8)) {
    std__vector_TSymbolTableLevel__std__allocator_TSymbolTableLevel______M_insert_aux
              (this,piVar2,local_80);
  }
  else {
    iVar3 = 0;
    if (piVar2 != (int *)0x0) {
      *piVar2 = (int)puVar4;
      iVar3 = *(int *)(this + 4);
    }
    *(int *)(this + 4) = iVar3 + 4;
  }
  iVar3 = _InitPreprocessor();
  if (iVar3 == 0) {
    uVar6 = TBuiltIns__getNumStringArrays(param_1,local_124);
    uVar9 = 0;
    if (uVar6 != 0) {
LAB_97ba0e34:
      ppcVar7 = (char **)TBuiltIns__getStringArray(param_1,local_124,uVar9);
      piVar2 = (int *)TBuiltIns__getStringSizeArray(param_1,local_124,uVar9);
      iVar3 = TBuiltIns__getNumStrings(param_1,local_124,uVar9);
      iVar3 = PaParseStrings(ppcVar7,piVar2,iVar3,0,(unsigned char *)&local_130);
      if (iVar3 == 0) goto LAB_97ba0fd8;
                    
      __ZN13TInfoSinkBase6appendEPKc(param_3,"INTERNAL ERROR: ");
      __ZN13TInfoSinkBase6appendEPKc(param_3,"Unable to parse built-ins");
      __ZN13TInfoSinkBase6appendEPKc(param_3,"\n");
      _FinalizePreprocessor();
      piVar2 = (int *)(local_d4 + -4);
      auStack_60[0] = local_d8;
      do {
        iVar3 = *piVar2;
        if (in_RESERVE != '\0') {
          iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
          *piVar2 = iVar1;
          bVar10 = 2;
        }
      } while (!(bool)(bVar10 >> 1 & 1));
      if (iVar3 < 1) {
        puVar4 = auStack_60;
        goto code_r0x97ba0f54;
      }
      goto code_r0x97ba0f58;
    }
LAB_97ba0fe4:
    __Z16IdentifyBuiltIns11EShLanguageR12TSymbolTableRK16TBuiltInResource(local_124,this,param_4);
    __Z16IdentifyBuiltIns11EShLanguageR12TSymbolTable(local_124,this);
    _FinalizePreprocessor();
    piVar2 = (int *)(local_d4 + -4);
    local_70[0] = local_d8;
    do {
      iVar3 = *piVar2;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
        *piVar2 = iVar1;
        bVar10 = 2;
      }
    } while (!(bool)(bVar10 >> 1 & 1));
    if (iVar3 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_d4 + -0xc),local_70);
    }
    if (local_e0 != 0) {
      std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string______M_erase((unsigned char
                  *)&local_e8,(unsigned char *)local_e4[1]);
      local_e4[2] = local_e4;
      local_e4[1] = 0;
      local_e4[3] = local_e4;
      local_e0 = 0;
    }
    if (local_f8 != 0) {
      std___Rb_tree_std__string_std__pair_std__string_const_TBehavior__std___Select1st_std__pair_std__string_const_TBehavior___std__less_std__string__pool_allocator_std__pair_std__string_const_TBehavior______M_erase((unsigned char
                  *)&local_100,(unsigned char *)local_fc[1]);
      local_fc[2] = local_fc;
      local_fc[1] = 0;
      local_fc[3] = local_fc;
    }
    uVar8 = 1;
  }
  else {
                    
    __ZN13TInfoSinkBase6appendEPKc(param_3,"INTERNAL ERROR: ");
    __ZN13TInfoSinkBase6appendEPKc(param_3,"Unable to intialize the Preprocessor");
    __ZN13TInfoSinkBase6appendEPKc(param_3,"\n");
    piVar2 = (int *)(local_d4 + -4);
    auStack_50[0] = local_d8;
    do {
      iVar3 = *piVar2;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
        *piVar2 = iVar1;
        bVar10 = 2;
      }
    } while (!(bool)(bVar10 >> 1 & 1));
    puVar4 = auStack_50;
    if (iVar3 < 1) {
code_r0x97ba0f54:
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_d4 + -0xc),puVar4);
    }
code_r0x97ba0f58:
    if (local_e0 != 0) {
      std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string______M_erase((unsigned char
                  *)&local_e8,(unsigned char *)local_e4[1]);
      local_e4[2] = local_e4;
      local_e4[1] = 0;
      local_e4[3] = local_e4;
      local_e0 = 0;
    }
    if (local_f8 != 0) {
      std___Rb_tree_std__string_std__pair_std__string_const_TBehavior__std___Select1st_std__pair_std__string_const_TBehavior___std__less_std__string__pool_allocator_std__pair_std__string_const_TBehavior______M_erase((unsigned char
                  *)&local_100,(unsigned char *)local_fc[1]);
      local_fc[2] = local_fc;
      local_fc[1] = 0;
      local_fc[3] = local_fc;
    }
    uVar8 = 0;
  }
  return uVar8;
LAB_97ba0fd8:
  uVar9 = uVar9 + 1;
  if (uVar6 <= uVar9) goto LAB_97ba0fe4;
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
  uint uVar5;
  int *piVar6;
  unsigned char * pTVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  void *pvVar10;
  void *pvVar11;
  char *pcVar12;
  uint uVar13;
  char *pcVar14;
  uint *this;
  char in_RESERVE;
  byte bVar15;
  void *local_180;
  int *local_17c;
  int *local_178;
  undefined4 local_174;
  unsigned char * local_160;
  undefined4 *local_150 [4];
  int *local_140;
  unsigned char * local_13c;
  void *local_138;
  int local_134;
  unsigned char * local_130;
  int local_12c;
  undefined4 local_128;
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_11c;
  unsigned char * local_110;
  undefined4 *local_10c;
  int local_108;
  undefined4 local_100;
  undefined4 local_fc;
  unsigned char * local_f8;
  undefined4 *local_f4;
  int local_f0;
  undefined4 local_e8;
  int local_e4;
  unsigned char * local_d0;
  unsigned char * local_c0;
  undefined4 local_b0;
  unsigned char * local_a0;
  undefined4 uStack_90;
  int iStack_8c;
  char acStack_80 [16];
  undefined4 auStack_70 [4];
  undefined4 auStack_60 [4];
  undefined4 local_50 [4];
  int local_40;
  char *local_3c [3];
  
  local_3c[0] = (char *)GetPreprocessorBuiltinString();
  if (param_1 == (int *)0x0) {
    return 0;
  }
  piVar6 = (int *)(**(code **)(*param_1 + 8))(param_1);
  bVar15 = (piVar6 == (int *)0x0) << 1;
  if (piVar6 == (int *)0x0) {
    return 0;
  }
  _pthread_mutex_lock((pthread_mutex_t *)&_glsl_allocator_lock);
  pTVar7 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
  ((int (*)())TPoolAllocator__push)(pTVar7);
  (**(code **)(*piVar6 + 0x18))(piVar6);
  this = (uint *)piVar6[1];
  pcVar14 = (char *)*this;
  iVar3 = *(int *)(pcVar14 + -0xc);
  pcVar12 = (char *)*this;
  if (((*(int *)(pcVar12 + -4) < 1) && (pcVar12 <= pcVar14)) && (pcVar14 <= pcVar12 + iVar3)) {
    __ZNSs10_M_replaceIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_St18input_iterator_tag
              (this,pcVar12,pcVar12 + iVar3,pcVar14,pcVar14);
  }
  else {
    __ZNSs15_M_replace_safeIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_
              (this,pcVar12,pcVar12 + iVar3,pcVar14,pcVar14);
  }
  pcVar12 = *(char **)(piVar6[1] + 8);
  __ZNSs7replaceEmmPKcm((void *)(piVar6[1] + 8),0,*(ulong *)(pcVar12 + -0xc),pcVar12,0);
  if (param_3 == 0) {
    _pthread_mutex_unlock((pthread_mutex_t *)&_glsl_allocator_lock);
    return 1;
  }
  local_40 = piVar6[1];
  puVar8 = (undefined4 *)((int (*)())GetSymbolTable)(piVar6[2]);
  local_180 = (void *)0x0;
  local_17c = (int *)0x0;
  local_178 = (int *)0x0;
  std__vector_TSymbolTableLevel__std__allocator_TSymbolTableLevel______M_insert_aux
            ((unsigned char *)&local_180,0,*puVar8);
  local_174 = puVar8[3];
  pTVar7 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
  puVar8 = (undefined4 *)((int (*)())TPoolAllocator__allocate)(pTVar7,0x10);
  local_160 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
  *puVar8 = local_160;
  puVar8[1] = 0;
  puVar9 = (undefined4 *)((int (*)())TPoolAllocator__allocate)(local_160,0x1c);
  puVar8[2] = 0;
  puVar8[1] = puVar9;
  *puVar9 = 0;
  *(undefined4 *)(puVar8[1] + 4) = 0;
  *(undefined4 *)(puVar8[1] + 8) = puVar8[1];
  *(undefined4 *)(puVar8[1] + 0xc) = puVar8[1];
  local_150[0] = puVar8;
  if (local_17c == local_178) {
    std__vector_TSymbolTableLevel__std__allocator_TSymbolTableLevel______M_insert_aux
              ((unsigned char *)&local_180,local_17c
               ,local_150);
  }
  else {
    if (local_17c != (int *)0x0) {
      *local_17c = (int)puVar8;
    }
    local_17c = local_17c + 1;
  }
  local_138 = (void *)piVar6[1];
  local_134 = piVar6[2];
  local_140 = &local_40;
  local_130 = (unsigned char *)0x0;
  local_12c = 0;
  local_128 = 0;
  local_124 = 0;
  local_120 = 0;
  local_11c = 0;
  local_13c = (unsigned char *)&local_180;
  local_110 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
  local_10c = (undefined4 *)0x0;
  local_d0 = local_110;
  local_10c = (undefined4 *)((int (*)())TPoolAllocator__allocate)(local_110,0x1c);
  local_108 = 0;
  *local_10c = 0;
  local_10c[1] = 0;
  local_10c[2] = local_10c;
  local_10c[3] = local_10c;
  local_100 = 1;
  local_fc = 0;
  local_f8 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
  local_f4 = (undefined4 *)0x0;
  local_c0 = local_f8;
  local_f4 = (undefined4 *)((int (*)())TPoolAllocator__allocate)(local_f8,0x20);
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
      bVar15 = 2;
    }
  } while (!(bool)(bVar15 >> 1 & 1));
  local_e8 = ((int (*)())GetGlobalPoolAllocator)();
  local_e4 = local_e4 + 0xc;
  local_b0 = local_e8;
  ((int (*)())TParseContext__initializeExtensionBehavior)((unsigned char *)&local_140);
  setInitialState();
  _InitPreprocessor();
  pTVar7 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
  puVar8 = (undefined4 *)((int (*)())TPoolAllocator__allocate)(pTVar7,0x10);
  local_a0 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
  *puVar8 = local_a0;
  puVar8[1] = 0;
  puVar9 = (undefined4 *)((int (*)())TPoolAllocator__allocate)(local_a0,0x1c);
  puVar8[2] = 0;
  puVar8[1] = puVar9;
  *puVar9 = 0;
  *(undefined4 *)(puVar8[1] + 4) = 0;
  *(undefined4 *)(puVar8[1] + 8) = puVar8[1];
  *(undefined4 *)(puVar8[1] + 0xc) = puVar8[1];
  local_150[0] = puVar8;
  if (local_17c == local_178) {
    std__vector_TSymbolTableLevel__std__allocator_TSymbolTableLevel______M_insert_aux
              ((unsigned char *)&local_180,local_17c
               ,local_150);
  }
  else {
    if (local_17c != (int *)0x0) {
      *local_17c = (int)puVar8;
    }
    local_17c = local_17c + 1;
  }
  pvVar10 = local_138;
  bVar1 = 3 < (uint)((int)local_17c - (int)local_180 >> 2);
  if (bVar1) {
    __ZN13TInfoSinkBase6appendEPKc(local_138,"INTERNAL ERROR: ");
    __ZN13TInfoSinkBase6appendEPKc(pvVar10,"Wrong symbol table level. No code generated.");
    __ZN13TInfoSinkBase6appendEPKc(pvVar10,"\n");
  }
  uVar13 = (uint)!bVar1;
  if (uVar13 == 1) {
    iVar3 = ((int (*)())TParseContext__insertBuiltInArrayAtGlobalLevel)((unsigned char *)&local_140);
    if (iVar3 == 0) {
      iVar3 = PaParseStrings(local_3c,(int *)0x0,1,0,(unsigned char *)&local_140);
      if (iVar3 != 0) {
        uVar13 = 0;
      }
    }
    else {
      uVar13 = 0;
    }
  }
  iVar3 = PaParseStrings(param_2,(int *)0x0,param_3,0,(unsigned char *)&local_140);
  pvVar10 = local_138;
  if (iVar3 != 0) {
    uVar13 = 0;
  }
  if ((uVar13 == 1) && (local_130 != (unsigned char *)0x0)) {
    if (local_12c == 0) {
      uVar13 = TIntermediate__postProcess((unsigned char *)&local_40,local_130);
      pvVar10 = local_138;
      if (uVar13 != 1) {
        __ZN13TInfoSinkBase6appendEPKc(local_138,"INTERNAL ERROR: ");
        __ZN13TInfoSinkBase6appendEPKc
                  (pvVar10,"Parse tree post-processing failure. No code generated.");
        __ZN13TInfoSinkBase6appendEPKc(pvVar10,"\n");
        goto LAB_97ba18d4;
      }
      if (param_4 != 0) {
        bVar1 = (param_5 & 1) == 0;
        bVar15 = bVar1 << 1;
        if (!bVar1) {
          TIntermediate__outputTree((unsigned char *)&local_40,local_130);
        }
        (**(code **)(*piVar6 + 0x34))(piVar6,param_4);
        (**(code **)(*piVar6 + 0x38))(piVar6,param_5);
        iVar3 = (**(code **)(*piVar6 + 0x14))(piVar6,local_130);
        if (iVar3 != 0) goto LAB_97ba18d4;
        goto LAB_97ba18cc;
      }
      __ZN13TInfoSinkBase6appendEPKc
                (local_138,"No errors.  No code generation or linking was requested.");
      pcVar12 = "\n";
    }
    else {
      __ZN13TInfoSinkBase6appendEPKc(local_138,"ERROR: ");
      pvVar10 = local_138;
      _sprintf(acStack_80,"%d",local_128);
      auStack_70[0] = ((int (*)())GetGlobalPoolAllocator)();
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                ((unsigned char *)&uStack_90,acStack_80,(unsigned char *)auStack_70);
      __ZN13TInfoSinkBase6appendERKSbIcSt11char_traitsIcE14pool_allocatorIcEE
                (pvVar10,(unsigned char *)&uStack_90);
      piVar6 = (int *)(iStack_8c + -4);
      auStack_60[0] = uStack_90;
      do {
        iVar3 = *piVar6;
        if (in_RESERVE != '\0') {
          iVar2 = storeWordConditionalIndexed(iVar3 + -1,0,piVar6);
          *piVar6 = iVar2;
          bVar15 = 2;
        }
      } while (!(bool)(bVar15 >> 1 & 1));
      if (iVar3 < 1) {
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                  ((unsigned char *)(iStack_8c + -0xc),auStack_60);
      }
      pcVar12 = " compilation errors. No code generated.";
      uVar13 = 0;
    }
    __ZN13TInfoSinkBase6appendEPKc(pvVar10,pcVar12);
    bVar1 = (param_5 & 1) == 0;
    bVar15 = bVar1 << 1;
    if (!bVar1) {
      TIntermediate__outputTree((unsigned char *)&local_40,local_130);
    }
  }
  else {
    if (local_130 != (unsigned char *)0x0) goto LAB_97ba18d4;
    __ZN13TInfoSinkBase6appendEPKc(local_138,"ERROR: ");
    __ZN13TInfoSinkBase6appendEPKc(pvVar10,"Parser found no code to compile in source strings.");
    __ZN13TInfoSinkBase6appendEPKc(pvVar10,"\n");
LAB_97ba18cc:
    uVar13 = 0;
  }
LAB_97ba18d4:
  TIntermediate__remove((unsigned char *)&local_40,local_130);
  pvVar10 = local_180;
  for (; iVar3 = (int)local_17c - (int)pvVar10 >> 2, iVar3 != 1; local_17c = local_17c + -1) {
    pvVar11 = *(void **)((int)pvVar10 + (iVar3 + -1) * 4);
    if (pvVar11 != (void *)0x0) {
      __ZN17TSymbolTableLevelD1Ev(pvVar11);
      pvVar10 = local_180;
    }
  }
  _FinalizePreprocessor();
  pTVar7 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
  ((int (*)())TPoolAllocator__pop)(pTVar7);
  _pthread_mutex_unlock((pthread_mutex_t *)&_glsl_allocator_lock);
  piVar6 = (int *)(local_e4 + -4);
  local_50[0] = local_e8;
  do {
    iVar3 = *piVar6;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar3 + -1,0,piVar6);
      *piVar6 = iVar2;
      bVar15 = 2;
    }
  } while (!(bool)(bVar15 >> 1 & 1));
  if (iVar3 < 1) {
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
              ((unsigned char *)(local_e4 + -0xc),local_50);
  }
  if (local_f0 != 0) {
    std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string______M_erase((unsigned char
                *)&local_f8,(unsigned char *)local_f4[1]);
    local_f4[2] = local_f4;
    local_f4[1] = 0;
    local_f4[3] = local_f4;
    local_f0 = 0;
  }
  pvVar10 = local_180;
  if (local_108 != 0) {
    std___Rb_tree_std__string_std__pair_std__string_const_TBehavior__std___Select1st_std__pair_std__string_const_TBehavior___std__less_std__string__pool_allocator_std__pair_std__string_const_TBehavior______M_erase((unsigned char
                *)&local_110,(unsigned char *)local_10c[1]);
    local_10c[2] = local_10c;
    local_10c[1] = 0;
    local_10c[3] = local_10c;
    local_108 = 0;
    pvVar10 = local_180;
  }
  for (; uVar5 = (int)local_17c - (int)pvVar10 >> 2, 1 < uVar5; local_17c = local_17c + -1) {
    pvVar11 = *(void **)((int)pvVar10 + (uVar5 - 1) * 4);
    if (pvVar11 != (void *)0x0) {
      __ZN17TSymbolTableLevelD1Ev(pvVar11);
      pvVar10 = local_180;
    }
  }
  iVar3 = (int)local_178 - (int)pvVar10 >> 2;
  if (iVar3 != 0) {
    std____default_alloc_template_true_0___deallocate(pvVar10,iVar3 << 2);
  }
  return uVar13;
}

/* _ShLink @ 0x97ba1a6c (284 bytes) */
int _ShLink(param_1, param_2, param_3, param_4, param_5)
  int *param_1;
  void **param_2;
  int param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  unsigned char * this;
  int *piVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  void *this_00;
  
  if ((param_1 != (int *)0x0) &&
     (this = (unsigned char *)(**(code **)(*param_1 + 0xc))(), this != (unsigned char *)0x0)) {
    pcVar3 = (char *)**(undefined4 **)(this + 0x84);
    __ZNSs7replaceEmmPKcm(*(undefined4 **)(this + 0x84),0,*(ulong *)(pcVar3 + -0xc),pcVar3,0);
    pcVar3 = *(char **)(*(int *)(this + 0x84) + 8);
    __ZNSs7replaceEmmPKcm((void *)(*(int *)(this + 0x84) + 8),0,*(ulong *)(pcVar3 + -0xc),pcVar3,0);
    iVar5 = 0;
    TGenericLinker__reset(this);
    if (0 < param_3) {
      do {
        if (param_2[iVar5] == (int *)0x0) {
          this_00 = *(void **)(this + 0x84);
          pcVar4 = "Invalid shader passed to linker (internal error).";
          pcVar3 = "INTERNAL ERROR: ";
                    
LAB_97ba1bf0:
          __ZN13TInfoSinkBase6appendEPKc(this_00,pcVar3);
          __ZN13TInfoSinkBase6appendEPKc(this_00,pcVar4);
          __ZN13TInfoSinkBase6appendEPKc(this_00,"\n");
          return 0;
        }
        piVar1 = (int *)(**(code **)(*(int *)param_2[iVar5] + 8))();
        if ((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0x20))(), iVar2 == 0)) {
          this_00 = *(void **)(this + 0x84);
          pcVar4 = "Not all shaders have valid object code.";
                    
          pcVar3 = "ERROR: ";
          goto LAB_97ba1bf0;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < param_3);
    }
    *(undefined4 *)(this + 0x80) = param_4;
    *(undefined4 *)(this + 0x7c) = param_5;
    iVar5 = TGenericLinker__link(this,param_2,param_3);
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

