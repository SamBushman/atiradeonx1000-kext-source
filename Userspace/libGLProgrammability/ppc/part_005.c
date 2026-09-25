#include "decls.h"

/* __ZN13TParseContext14boolErrorCheckEiPK12TIntermTyped @ 0x97b9ba78 (208 bytes) */
int __ZN13TParseContext14boolErrorCheckEiPK12TIntermTyped(this, param_2, param_3, param_4, param_5, param_6)
  void *this;
  int param_2;
  unsigned char * param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  int iVar1;
  undefined4 in_r9;
  undefined4 in_r10;
  
  iVar1 = (**(code **)(*(int *)param_3 + 0x40))(param_3);
  if ((((iVar1 == 3) && (iVar1 = (**(code **)(*(int *)param_3 + 0x54))(param_3), iVar1 == 0)) &&
      (iVar1 = (**(code **)(*(int *)param_3 + 0x50))(param_3), iVar1 == 0)) &&
     (iVar1 = (**(code **)(*(int *)param_3 + 0x58))(param_3), iVar1 == 0)) {
    return 0;
  }
  TParseContext__error
            ((int)this,(char *)param_2,"boolean expression expected","","",param_6,in_r9,in_r10);
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
int TParseContext__structQualifierErrorCheck(this, param_2, param_3, param_4, param_5, param_6, param_7)
  unsigned char * this;
  int param_2;
  unsigned char * param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined4 in_r10;
  
  iVar1 = *(int *)(param_3 + 4);
  if ((iVar1 - 3U < 3) && (*(int *)param_3 == 0xe)) {
    pcVar2 = (char *)getQualifierString(iVar1);
    error((int)this,(char *)param_2,"cannot be used with a structure",pcVar2,"",param_6,param_7,
          in_r10);
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
  int *a0;
  unsigned char * psVar8;
  char *pcVar9;
  int a2;
  int a3;
  int a4;
  int in_r8;
  int iVar10;
  undefined4 in_r10;
  int iVar11;
  void *pvVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  undefined4 uVar16;
  int *piVar17;
  char in_RESERVE;
  byte bVar18;
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
  bVar18 = (this_00 == (void *)0x0) << 1;
  pvVar12 = (void *)0x0;
  if (this_00 != (void *)0x0) {
    local_80[0] = ((int (*)())GetGlobalPoolAllocator)();
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
              (this_00,"gl_TexCoord",(unsigned char *)local_80);
    pvVar12 = this_00;
  }
  piVar17 = *(int **)(this + 4);
  iVar10 = *piVar17;
  iVar13 = (piVar17[1] - iVar10 >> 2) + -1;
  while( true ) {
    iVar10 = *(int *)(iVar10 + iVar13 * 4);
    std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______find((unsigned char *)local_70,iVar10,pvVar12);
    iVar14 = 0;
    if (local_70[0] != *(int *)(iVar10 + 4)) {
      iVar14 = *(int *)(local_70[0] + 0x18);
    }
    iVar13 = iVar13 + -1;
    if (iVar14 != 0) break;
    if (iVar13 < 0) {
      iVar13 = *(int *)((int)pvVar12 + 4);
      iVar10 = *(int *)(iVar13 + -0xc);
      bVar18 = *DAT_a7b7ba18;
      pcVar9 = "INTERNAL ERROR finding symbol";
LAB_97b9c154:
      *(byte *)(iVar13 + iVar10) = bVar18;
      error((int)this,(char *)0x0,pcVar9,*(char **)((int)pvVar12 + 4),"",in_r8,(uint)bVar18,in_r10);
      return 1;
    }
    iVar10 = *piVar17;
  }
  pTVar7 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
  a0 = (int *)((int (*)())TPoolAllocator__allocate)(pTVar7,0x40);
  puVar5 = PTR_vtable_a7b7c0b4;
  a0[1] = (int)pvVar12;
  *a0 = (int)(puVar5 + 8);
  in_r8 = *(int *)(iVar14 + 0x18);
  a4 = *(int *)(iVar14 + 0x1c);
  a3 = *(int *)(iVar14 + 0x20);
  a2 = *(int *)(iVar14 + 0x24);
  iVar13 = *(int *)(iVar14 + 0x28);
  iVar10 = *(int *)(iVar14 + 0x10);
  iVar11 = *(int *)(iVar14 + 0x14);
  iVar15 = *(int *)(iVar14 + 0x2c);
  a0[3] = (int)&PTR___ZN5TTypeD1Ev_a7b7d4d0;
  a0[6] = in_r8;
  a0[7] = a4;
  a0[8] = a3;
  a0[9] = a2;
  a0[10] = iVar13;
  a0[4] = iVar10;
  a0[5] = iVar11;
  in_r10 = 0;
  a0[0xb] = iVar15;
  uVar6 = a0[0xc];
  uVar2 = *(uint *)(iVar14 + 0x30) & 0xfe000000;
  a0[0xc] = uVar2 | uVar6 & 0x1ffffff;
  uVar3 = (*(uint *)(iVar14 + 0x30) >> 0x13 & 0x3f) << 0x13;
  a0[0xc] = uVar3 | uVar2 | uVar6 & 0x7ffff;
  uVar1 = *(uint *)(iVar14 + 0x30) & 0x7f800;
  a0[0xc] = uVar1 | uVar3 | uVar2 | uVar6 & 0x7ff;
  uVar4 = (*(uint *)(iVar14 + 0x30) >> 10 & 1) << 10;
  a0[0xc] = uVar4 | uVar1 | uVar3 | uVar2 | uVar6 & 0x3ff;
  a0[0xc] = (*(uint *)(iVar14 + 0x30) >> 9 & 1) << 9 | uVar4 | uVar1 | uVar3 | uVar2 | uVar6 & 0x1ff
  ;
  a0[0xd] = 0;
  a0[0xe] = 0;
  a0[0xf] = 0;
  piVar17 = *(int **)(this + 4);
  iVar10 = piVar17[3];
  piVar17[3] = iVar10 + 1;
  a0[2] = iVar10 + 1;
  uVar16 = *(undefined4 *)(*piVar17 + ((piVar17[1] - *piVar17 & 0xfffffffcU) - 4));
  local_5c = 0;
  psVar8 = (unsigned char *)(**(code **)(*a0 + 8))(a0,iVar13,a2,a3,a4,in_r8,piVar17,0);
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&local_40,psVar8);
  local_38 = a0;
  std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&local_50,uVar16,&local_40);
  local_60 = local_50;
  piVar17 = (int *)(local_3c + -4);
  local_5c = local_4c;
  local_30[0] = local_40;
  do {
    iVar10 = *piVar17;
    if (in_RESERVE != '\0') {
      iVar13 = storeWordConditionalIndexed(iVar10 + -1,0,piVar17);
      *piVar17 = iVar13;
      bVar18 = 2;
    }
  } while (!(bool)(bVar18 >> 1 & 1));
  if (iVar10 < 1) {
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
              ((unsigned char *)(local_3c + -0xc),local_30);
  }
  if (local_5c != 0) {
    return 0;
  }
  (**(code **)(*a0 + 4))(a0);
  iVar13 = *(int *)((int)pvVar12 + 4);
  iVar10 = *(int *)(iVar13 + -0xc);
  bVar18 = *DAT_a7b7ba18;
  pcVar9 = "INTERNAL ERROR inserting new symbol";
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
  unsigned char * psVar11;
  undefined **ppuVar12;
  undefined4 a1;
  undefined4 extraout_r4;
  undefined4 a1_00;
  undefined4 a1_01;
  char *pcVar13;
  unsigned char * a2;
  uint uVar14;
  uint uVar15;
  int iVar16;
  char *pcVar17;
  int iVar18;
  int *a0;
  undefined4 uVar19;
  int *piVar20;
  char in_RESERVE;
  byte in_cr0;
  byte bVar21;
  undefined8 uVar22;
  uint uStack00000024;
  uint uStack00000028;
  uint uStack0000002c;
  uint uStack00000030;
  uint uStack00000034;
  unsigned char * in_stack_00000038;
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
  unsigned char * local_ec;
  uint local_e8;
  uint local_e4;
  uint local_e0;
  uint local_dc;
  uint local_d8;
  uint local_d4;
  uint local_d0;
  unsigned char * local_cc;
  uint local_c8;
  uint local_c4;
  uint local_c0;
  unsigned char * local_bc;
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
       (((piVar7 = (int *)(**(code **)(*in_stack_00000040 + 0x18))(in_stack_00000040),
         piVar7 != (int *)0x0 && (iVar9 = (**(code **)(*piVar7 + 0x40))(piVar7), iVar9 == 2)) &&
        (0 < *(int *)piVar7[0xc])))) {
      piVar20 = *(int **)(param_1 + 4);
      local_3c = 0;
      local_40 = 0;
      iVar16 = *piVar20;
      iVar9 = (piVar20[1] - iVar16 >> 2) + -1;
      while( true ) {
        iVar18 = *(int *)(iVar16 + iVar9 * 4);
        psVar11 = param_3;
        std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______find((unsigned char *)local_90,iVar18,param_3);
        a0 = (int *)0x0;
        if (local_90[0] != *(int *)(iVar18 + 4)) {
          a0 = *(int **)(local_90[0] + 0x18);
        }
        if ((a0 != (int *)0x0) || (iVar9 + -1 < 0)) break;
        iVar16 = *piVar20;
        iVar9 = iVar9 + -1;
      }
      if (&STACKARG(0x0) != (undefined1 *)0x40) {
        local_40 = (uint)(iVar9 == 0);
      }
      if (&STACKARG(0x0) != (undefined1 *)0x3c) {
        local_3c = (uint)(iVar9 == (piVar20[1] - *piVar20 >> 2) + -1);
      }
      if ((a0 == (int *)0x0) || (local_3c == 0)) {
        local_12c = (char *)TParseContext__reservedErrorCheck((unsigned char *)param_1,(int)param_2,param_3);
        bVar21 = (local_12c == (char *)0x0) << 1;
        if (local_12c != (char *)0x0) {
          return 1;
        }
        pTVar10 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
        uVar22 = ((int (*)())TPoolAllocator__allocate)(pTVar10,0x40);
        piVar20 = (int *)((ulonglong)uVar22 >> 0x20);
        a1_00 = (undefined4)uVar22;
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
        a2 = in_stack_00000038;
        uVar15 = uStack00000028;
        param_6 = uStack0000002c;
        local_124 = local_12c;
        ppuVar6 = (undefined **)0x0;
        local_11c = local_12c;
        local_114 = local_12c;
        local_110 = local_12c;
        if (in_stack_00000038 != (unsigned char *)0x0) {
          local_128 = *(int *)(in_stack_00000038 + 8);
          local_120 = (undefined **)local_12c;
          local_118 = local_12c;
          uVar22 = TType__setStructSize((unsigned char *)&local_130,*(unsigned char **)(in_stack_00000038 + 8));
          local_118 = (char *)((ulonglong)uVar22 >> 0x20);
          iVar9 = (**(code **)(*(int *)local_cc + 0x18))
                            (local_cc,(int)uVar22,in_stack_00000038,in_stack_0000003c,uVar15,param_6
                             ,*(int *)local_cc);
          *(byte *)(*(int *)(iVar9 + 4) + *(int *)(*(int *)(iVar9 + 4) + -0xc)) = *DAT_a7b7ba18;
          pcVar13 = *(char **)(iVar9 + 4);
          pTVar10 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
          uVar22 = ((int (*)())TPoolAllocator__allocate)(pTVar10,8);
          ppuVar12 = (undefined **)((ulonglong)uVar22 >> 0x20);
          a1_00 = (undefined4)uVar22;
          bVar21 = (ppuVar12 == (undefined **)0x0) << 1;
          a2 = in_stack_00000038;
          ppuVar6 = (undefined **)0x0;
          if (ppuVar12 != (undefined **)0x0) {
            local_80[0] = ((int (*)())GetGlobalPoolAllocator)();
            a2 = (unsigned char *)local_80;
            __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_(ppuVar12,pcVar13,a2);
            a1_00 = extraout_r4;
            ppuVar6 = ppuVar12;
          }
        }
        local_120 = ppuVar6;
        piVar20[1] = (int)param_3;
        param_8 = 0;
        *piVar20 = (int)(PTR_vtable_a7b7c0b4 + 8);
        piVar20[4] = (int)local_12c;
        piVar20[5] = local_128;
        piVar20[6] = (int)local_124;
        piVar20[7] = (int)local_120;
        piVar20[8] = (int)local_11c;
        piVar20[9] = (int)local_118;
        piVar20[3] = (int)&PTR___ZN5TTypeD1Ev_a7b7d4d0;
        piVar20[10] = (int)local_114;
        piVar20[0xb] = (int)local_110;
        uVar8 = piVar20[0xc];
        uVar3 = local_10c & 0xfe000000;
        piVar20[0xc] = uVar3 | uVar8 & 0x1ffffff;
        uVar4 = (local_10c >> 0x13 & 0x3f) << 0x13;
        piVar20[0xc] = uVar4 | uVar3 | uVar8 & 0x7ffff;
        uVar14 = local_10c & 0x7f800;
        piVar20[0xc] = uVar14 | uVar4 | uVar3 | uVar8 & 0x7ff;
        uVar5 = (local_10c >> 10 & 1) << 10;
        piVar20[0xc] = uVar5 | uVar14 | uVar4 | uVar3 | uVar8 & 0x3ff;
        piVar20[0xc] = (local_10c >> 9 & 1) << 9 | uVar5 | uVar14 | uVar4 | uVar3 | uVar8 & 0x1ff;
        piVar20[0xd] = 0;
        piVar20[0xe] = 0;
        piVar20[0xf] = 0;
        local_130 = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
        if (!bVar1) {
          piVar20[4] = *(int *)piVar7[0xc];
          piVar20[0xc] = piVar20[0xc] | 0x200;
        }
        piVar7 = *(int **)(param_1 + 4);
        iVar9 = piVar7[3];
        piVar7[3] = iVar9 + 1;
        piVar20[2] = iVar9 + 1;
        uVar19 = *(undefined4 *)(*piVar7 + ((piVar7[1] - *piVar7 & 0xfffffffcU) - 4));
        local_12c = (char *)0x0;
        psVar11 = (unsigned char *)
                  (**(code **)(*piVar20 + 8))
                            (piVar20,a1_00,a2,in_stack_0000003c,uVar15,param_6,piVar7);
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&local_70,psVar11);
        local_68 = piVar20;
        std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&local_120,uVar19,&local_70);
        local_130 = local_120;
        piVar7 = (int *)(local_6c + -4);
        local_12c = local_11c;
        local_60[0] = local_70;
        do {
          iVar9 = *piVar7;
          if (in_RESERVE != '\0') {
            iVar16 = storeWordConditionalIndexed(iVar9 + -1,0,piVar7);
            *piVar7 = iVar16;
            bVar21 = 2;
          }
        } while (!(bool)(bVar21 >> 1 & 1));
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
        if (piVar20 != (int *)0x0) {
          (**(code **)(*piVar20 + 4))(piVar20);
        }
        iVar16 = *(int *)(param_3 + 4);
        iVar9 = *(int *)(iVar16 + -0xc);
        uVar15 = (uint)*DAT_a7b7ba18;
        pcVar13 = "INTERNAL ERROR inserting new symbol";
      }
      else {
        iVar9 = (**(code **)(*a0 + 0x10))(a0,a1,psVar11,param_4,param_5,param_6,iVar16);
        if (iVar9 == 0) {
          iVar16 = *(int *)(param_3 + 4);
          iVar9 = *(int *)(iVar16 + -0xc);
          uVar15 = (uint)*DAT_a7b7ba18;
          pcVar13 = "variable expected";
        }
        else {
          iVar9 = (**(code **)(a0[3] + 0x38))(a0 + 3,a1_01,psVar11,param_4,param_5,param_6,iVar16);
          if (iVar9 == 0) {
            iVar16 = *(int *)(param_3 + 4);
            iVar9 = *(int *)(iVar16 + -0xc);
            uVar15 = (uint)*DAT_a7b7ba18;
            pcVar13 = "redeclaring non-array as array";
          }
          else if (a0[4] < 1) {
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
            if (in_stack_00000038 != (unsigned char *)0x0) {
              local_128 = *(int *)(in_stack_00000038 + 8);
              uVar15 = uStack0000002c;
              uVar14 = uStack00000028;
              uVar22 = TType__setStructSize
                                 ((unsigned char *)&local_130,*(unsigned char **)(in_stack_00000038 + 8));
              local_118 = (char *)((ulonglong)uVar22 >> 0x20);
              iVar9 = (**(code **)(*(int *)local_cc + 0x18))
                                (local_cc,(int)uVar22,in_stack_0000003c,uVar15,uVar14,param_6,
                                 *(int *)local_cc);
              *(byte *)(*(int *)(iVar9 + 4) + *(int *)(*(int *)(iVar9 + 4) + -0xc)) = *DAT_a7b7ba18;
              pcVar13 = *(char **)(iVar9 + 4);
              pTVar10 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
              ppuVar12 = (undefined **)((int (*)())TPoolAllocator__allocate)(pTVar10,8);
              ppuVar6 = (undefined **)0x0;
              if (ppuVar12 != (undefined **)0x0) {
                local_50[0] = ((int (*)())GetGlobalPoolAllocator)();
                __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                          (ppuVar12,pcVar13,(unsigned char *)local_50);
                ppuVar6 = ppuVar12;
              }
            }
            local_120 = ppuVar6;
            bVar2 = false;
            if (((a0[0xc] & 0x1fffe00U) == (local_10c & 0x1fffe00)) && (a0[5] == local_128)) {
              bVar2 = true;
            }
            local_130 = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
            if (bVar2) {
              for (iVar9 = a0[0xf]; iVar9 != 0; iVar9 = *(int *)(iVar9 + 0x20)) {
                if (*(int *)piVar7[0xc] < *(int *)(iVar9 + 0x1c)) {
                  iVar16 = *(int *)(param_3 + 4);
                  iVar9 = *(int *)(iVar16 + -0xc);
                  uVar15 = (uint)*DAT_a7b7ba18;
                  pcVar13 = "higher index value already used for the array";
                  goto LAB_97b9cb40;
                }
                *(int *)(iVar9 + 4) = *(int *)piVar7[0xc];
                *(uint *)(iVar9 + 0x24) = *(uint *)(iVar9 + 0x24) | 0x200;
              }
              if (!bVar1) {
                a0[4] = *(int *)piVar7[0xc];
                a0[0xc] = a0[0xc] | 0x200;
              }
              goto LAB_97b9caf4;
            }
            iVar16 = *(int *)(param_3 + 4);
            iVar9 = *(int *)(iVar16 + -0xc);
            uVar15 = (uint)*DAT_a7b7ba18;
            pcVar13 = "redeclaration of array with a different type";
          }
          else {
            iVar16 = *(int *)(param_3 + 4);
            iVar9 = *(int *)(iVar16 + -0xc);
            uVar15 = (uint)*DAT_a7b7ba18;
            pcVar13 = "redeclaration of array with size";
          }
        }
      }
    }
    else {
      iVar16 = *(int *)(param_3 + 4);
      iVar9 = *(int *)(iVar16 + -0xc);
      uVar15 = (uint)*DAT_a7b7ba18;
      pcVar13 = "array size must be a positive integer";
    }
LAB_97b9cb40:
    *(char *)(iVar16 + iVar9) = (char)uVar15;
    error(param_1,(char *)param_2,pcVar13,*(char **)(param_3 + 4),"",param_6,uVar15,param_8);
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
    local_ec = (unsigned char *)param_5;
    local_e8 = param_6;
    local_e4 = param_7;
    local_e0 = param_8;
    local_d0 = param_4;
    local_cc = (unsigned char *)param_5;
    local_c8 = param_6;
    local_c4 = param_7;
    local_c0 = param_8;
    if (in_stack_00000038 != (unsigned char *)0x0) {
      local_118 = *(char **)(in_stack_00000038 + 8);
      uVar22 = TType__setStructSize((unsigned char *)&local_120,*(unsigned char **)(in_stack_00000038 + 8));
      local_108 = (undefined4)((ulonglong)uVar22 >> 0x20);
      iVar9 = (**(code **)(*(int *)local_bc + 0x18))
                        (local_bc,(int)uVar22,in_stack_0000003c,param_5,param_6,param_4,
                         *(int *)local_bc);
      *(byte *)(*(int *)(iVar9 + 4) + *(int *)(*(int *)(iVar9 + 4) + -0xc)) = *DAT_a7b7ba18;
      pcVar17 = *(char **)(iVar9 + 4);
      pTVar10 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
      this = (void *)((int (*)())TPoolAllocator__allocate)(pTVar10,8);
      in_cr0 = (this == (void *)0x0) << 1;
      pcVar13 = (void *)0x0;
      if (this != (void *)0x0) {
        local_b0[0] = ((int (*)())GetGlobalPoolAllocator)();
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                  (this,pcVar17,(unsigned char *)local_b0);
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
        iVar16 = storeWordConditionalIndexed(iVar9 + -1,0,piVar7);
        *piVar7 = iVar16;
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
      if (param_5 == 0) {
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
  unsigned char * pTVar10;
  int *a0;
  int iVar11;
  void *this_00;
  unsigned char * psVar12;
  undefined4 extraout_r4;
  undefined4 a1;
  unsigned char * a2;
  int iVar13;
  uint a4;
  uint a5;
  int *piVar14;
  char *pcVar15;
  undefined4 uVar16;
  char in_RESERVE;
  byte in_cr0;
  undefined8 uVar17;
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
  unsigned char * local_88;
  uint local_80;
  int local_7c;
  uint local_78;
  uint local_74;
  uint local_70;
  int *local_6c;
  unsigned char * local_68;
  undefined4 local_60 [4];
  undefined4 local_50;
  int local_4c;
  int *local_48;
  undefined4 local_40 [5];
  
  iVar9 = TParseContext__reservedErrorCheck(this,param_2,param_3);
  if (iVar9 != 0) {
    TParseContext__recover(this);
  }
  iVar9 = *(int *)(param_4 + 4);
  if (iVar9 == 2) {
    *(undefined4 *)(param_4 + 4) = 0;
  }
  pTVar10 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
  a0 = (int *)((int (*)())TPoolAllocator__allocate)(pTVar10,0x40);
  local_8c = *(int **)(param_4 + 0x14);
  iVar13 = *(int *)(param_4 + 4);
  a5 = *(uint *)param_4;
  a4 = *(uint *)(param_4 + 8);
  local_94 = *(uint *)(param_4 + 0xc);
  local_90 = *(uint *)(param_4 + 0x10);
  a2 = *(unsigned char **)(param_4 + 0x18);
  local_ac = (local_90 & 1) << 9 |
             (local_94 & 1) << 10 |
             (a4 & 0xff) << 0xb | (a5 & 0x3f) << 0x13 | iVar13 << 0x19 | local_ac & 0x1ff;
  local_d0 = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  local_b0 = 0;
  local_cc = 0;
  local_c8 = 0;
  local_c4 = 0;
  local_c0 = (void *)0x0;
  local_bc = 0;
  local_b8 = 0;
  local_b4 = 0;
  a1 = 0;
  pvVar7 = local_c0;
  local_a0 = a5;
  local_9c = iVar13;
  local_98 = a4;
  local_88 = a2;
  local_80 = a5;
  local_7c = iVar13;
  local_78 = a4;
  local_74 = local_94;
  local_70 = local_90;
  local_6c = local_8c;
  local_68 = a2;
  if (local_8c != (int *)0x0) {
    local_c8 = local_8c[2];
    uVar17 = TType__setStructSize((unsigned char *)&local_d0,(unsigned char *)local_8c[2]);
    local_b8 = (int)((ulonglong)uVar17 >> 0x20);
    iVar11 = (**(code **)(*local_6c + 0x18))(local_6c,(int)uVar17,a2,iVar13,a4,a5,*local_6c);
    *(byte *)(*(int *)(iVar11 + 4) + *(int *)(*(int *)(iVar11 + 4) + -0xc)) = *DAT_a7b7ba18;
    pcVar15 = *(char **)(iVar11 + 4);
    pTVar10 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
    uVar17 = ((int (*)())TPoolAllocator__allocate)(pTVar10,8);
    this_00 = (void *)((ulonglong)uVar17 >> 0x20);
    a1 = (undefined4)uVar17;
    in_cr0 = (this_00 == (void *)0x0) << 1;
    pvVar7 = (void *)0x0;
    if (this_00 != (void *)0x0) {
      local_60[0] = ((int (*)())GetGlobalPoolAllocator)();
      a2 = (unsigned char *)local_60;
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_(this_00,pcVar15,a2);
      a1 = extraout_r4;
      pvVar7 = this_00;
    }
  }
  local_c0 = pvVar7;
  a0[1] = (int)param_3;
  *a0 = (int)(PTR_vtable_a7b7c0b4 + 8);
  a0[4] = local_cc;
  a0[5] = local_c8;
  a0[6] = local_c4;
  a0[7] = (int)local_c0;
  a0[8] = local_bc;
  a0[9] = local_b8;
  a0[3] = (int)&PTR___ZN5TTypeD1Ev_a7b7d4d0;
  a0[10] = local_b4;
  a0[0xb] = local_b0;
  uVar8 = a0[0xc];
  uVar4 = local_ac & 0xfe000000;
  a0[0xc] = uVar4 | uVar8 & 0x1ffffff;
  uVar5 = (local_ac >> 0x13 & 0x3f) << 0x13;
  a0[0xc] = uVar5 | uVar4 | uVar8 & 0x7ffff;
  uVar3 = local_ac & 0x7f800;
  a0[0xc] = uVar3 | uVar5 | uVar4 | uVar8 & 0x7ff;
  uVar6 = (local_ac >> 10 & 1) << 10;
  a0[0xc] = uVar6 | uVar3 | uVar5 | uVar4 | uVar8 & 0x3ff;
  a0[0xc] = (local_ac >> 9 & 1) << 9 | uVar6 | uVar3 | uVar5 | uVar4 | uVar8 & 0x1ff;
  a0[0xd] = 0;
  a0[0xe] = 0;
  a0[0xf] = 0;
  piVar14 = *(int **)(this + 4);
  local_d0 = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  iVar11 = piVar14[3];
  piVar14[3] = iVar11 + 1;
  a0[2] = iVar11 + 1;
  iVar11 = *piVar14;
  uVar16 = *(undefined4 *)(iVar11 + ((piVar14[1] - iVar11 & 0xfffffffcU) - 4));
  local_cc = 0;
  psVar12 = (unsigned char *)(**(code **)(*a0 + 8))(a0,a1,a2,iVar13,a4,a5,piVar14,iVar11);
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&local_50,psVar12);
  local_48 = a0;
  std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&local_c0,uVar16,&local_50);
  local_d0 = local_c0;
  piVar14 = (int *)(local_4c + -4);
  local_cc = local_bc;
  local_40[0] = local_50;
  do {
    iVar13 = *piVar14;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar13 + -1,0,piVar14);
      *piVar14 = iVar2;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar13 < 1) {
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
              ((unsigned char *)(local_4c + -0xc),local_40);
  }
  if (local_cc == 0) {
    iVar9 = a0[1];
    bVar1 = *DAT_a7b7ba18;
    *(byte *)(*(int *)(iVar9 + 4) + *(int *)(*(int *)(iVar9 + 4) + -0xc)) = bVar1;
    error((int)this,(char *)param_2,"redefinition",*(char **)(iVar9 + 4),"",a5,(uint)bVar1,iVar9);
    if (a0 != (int *)0x0) {
      (**(code **)(*a0 + 4))(a0);
    }
  }
  else {
    if (iVar9 != 2) {
      iVar9 = TParseContext__voidErrorCheck(this,param_2,param_3,param_4);
      return iVar9 != 0;
    }
    bVar1 = *DAT_a7b7ba18;
    *(byte *)(*(int *)(param_3 + 4) + *(int *)(*(int *)(param_3 + 4) + -0xc)) = bVar1;
    error((int)this,(char *)param_2,"variables with qualifier \'const\' must be initialized",
          *(char **)(param_3 + 4),"",a5,(uint)bVar1,iVar11);
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
int TParseContext__findFunction(this, param_2, param_3, param_4, param_5, param_6)
  unsigned char * this;
  int param_2;
  unsigned char * param_3;
  bool *param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 a1;
  undefined4 a2;
  char *pcVar4;
  bool *a3;
  int iVar5;
  int *piVar6;
  int iVar7;
  int *a0;
  int local_40 [7];
  
  piVar6 = *(int **)(this + 4);
  a3 = param_4;
  uVar3 = (**(code **)(*(int *)param_3 + 8))(param_3);
  iVar5 = *piVar6;
  iVar2 = (piVar6[1] - iVar5 >> 2) + -1;
  while( true ) {
    iVar7 = *(int *)(iVar5 + iVar2 * 4);
    a2 = uVar3;
    std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______find((unsigned char *)local_40,iVar7,uVar3);
    a0 = (int *)0x0;
    if (local_40[0] != *(int *)(iVar7 + 4)) {
      a0 = *(int **)(local_40[0] + 0x18);
    }
    if ((a0 != (int *)0x0) || (iVar2 + -1 < 0)) break;
    iVar5 = *piVar6;
    iVar2 = iVar2 + -1;
  }
  if (param_4 != (bool *)0x0) {
    *(uint *)param_4 = (uint)(iVar2 == 0);
  }
  if (a0 != (int *)0x0) {
    iVar2 = (**(code **)(*a0 + 0xc))(a0,a1,a2,a3,param_5,param_6,iVar5);
    if (iVar2 != 0) {
      return a0;
    }
    iVar5 = *(int *)(param_3 + 4);
    iVar7 = *(int *)(iVar5 + 4);
    bVar1 = *DAT_a7b7ba18;
    iVar2 = *(int *)(iVar7 + -0xc);
    pcVar4 = "function name expected";
  }
  else {
    iVar5 = *(int *)(param_3 + 4);
    iVar7 = *(int *)(iVar5 + 4);
    bVar1 = *DAT_a7b7ba18;
    iVar2 = *(int *)(iVar7 + -0xc);
    pcVar4 = "no matching overloaded function found";
  }
  *(byte *)(iVar7 + iVar2) = bVar1;
  error((int)this,(char *)param_2,pcVar4,*(char **)(iVar5 + 4),"",param_6,(uint)bVar1,iVar5);
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
  uint uVar4;
  int *piVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  unsigned char * pTVar9;
  unsigned char * psVar10;
  undefined **ppuVar11;
  undefined **this_00;
  unsigned char * this_01;
  unsigned char * pTVar12;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  undefined **ppuVar13;
  undefined **extraout_r4_02;
  undefined4 extraout_r4_03;
  undefined4 a1;
  undefined4 a1_00;
  undefined ***pppuVar14;
  unsigned char * paVar15;
  char *pcVar16;
  uint uVar17;
  uint uVar18;
  undefined4 uVar19;
  undefined **ppuVar20;
  uint *a6;
  uint uVar21;
  int iVar22;
  undefined4 uVar23;
  undefined4 *puVar24;
  unsigned char * pcVar25;
  int *piVar26;
  undefined4 uVar27;
  int iVar28;
  char *pcVar29;
  unsigned char * a0;
  char in_RESERVE;
  byte bVar30;
  undefined8 uVar31;
  undefined **local_150;
  uint local_14c;
  undefined **local_148;
  uint local_144;
  undefined **local_140;
  uint local_13c;
  uint local_138;
  uint local_134;
  uint local_130;
  unsigned char * local_12c;
  undefined **local_120;
  uint local_11c;
  undefined **local_118;
  uint local_114;
  uint local_110;
  unsigned char * local_10c;
  uint local_108;
  undefined **local_100;
  uint local_fc;
  undefined **local_f8;
  uint local_f4;
  uint local_f0;
  unsigned char * local_ec;
  uint local_e8;
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
  
  iVar8 = TParseContext__reservedErrorCheck(this,param_2,param_3);
  if (iVar8 != 0) {
    return 1;
  }
  local_14c = TParseContext__voidErrorCheck(this,param_2,param_3,param_4);
  bVar30 = (local_14c == 0) << 1;
  if (local_14c != 0) {
    return 1;
  }
  pTVar9 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
  uVar31 = ((int (*)())TPoolAllocator__allocate)(pTVar9,0x40);
  piVar6 = (int *)((ulonglong)uVar31 >> 0x20);
  uVar19 = (undefined4)uVar31;
  paVar15 = *(unsigned char **)(param_4 + 0x14);
  uVar18 = *(uint *)(param_4 + 4);
  local_120 = *(undefined ***)param_4;
  ppuVar20 = *(undefined ***)(param_4 + 8);
  local_114 = *(uint *)(param_4 + 0xc);
  local_110 = *(uint *)(param_4 + 0x10);
  uVar17 = *(uint *)(param_4 + 0x18);
  local_12c = (unsigned char *)
              ((local_110 & 1) << 9 |
              (local_114 & 1) << 10 |
              ((uint)ppuVar20 & 0xff) << 0xb |
              ((uint)local_120 & 0x3f) << 0x13 | uVar18 << 0x19 | (uint)local_12c & 0x1ff);
  local_150 = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  local_148 = (undefined **)0x0;
  local_138 = 0;
  local_144 = local_14c;
  ppuVar13 = (undefined **)0x0;
  local_13c = local_14c;
  local_134 = local_14c;
  local_130 = local_14c;
  local_11c = uVar18;
  local_118 = ppuVar20;
  local_10c = paVar15;
  local_108 = uVar17;
  local_100 = local_120;
  local_fc = uVar18;
  local_f8 = ppuVar20;
  local_f4 = local_114;
  local_f0 = local_110;
  local_ec = paVar15;
  local_e8 = uVar17;
  if (paVar15 != (unsigned char *)0x0) {
    local_148 = *(undefined ***)(paVar15 + 8);
    local_140 = (undefined **)local_14c;
    local_138 = local_14c;
    uVar31 = TType__setStructSize((unsigned char *)&local_150,*(unsigned char **)(paVar15 + 8));
    local_138 = (uint)((ulonglong)uVar31 >> 0x20);
    iVar8 = (**(code **)(*(int *)local_ec + 0x18))
                      (local_ec,(int)uVar31,paVar15,uVar17,uVar18,ppuVar20,*(int *)local_ec);
    *(byte *)(*(int *)(iVar8 + 4) + *(int *)(*(int *)(iVar8 + 4) + -0xc)) = *DAT_a7b7ba18;
    pcVar29 = *(char **)(iVar8 + 4);
    pTVar9 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
    uVar31 = ((int (*)())TPoolAllocator__allocate)(pTVar9,8);
    ppuVar11 = (undefined **)((ulonglong)uVar31 >> 0x20);
    uVar19 = (undefined4)uVar31;
    bVar30 = (ppuVar11 == (undefined **)0x0) << 1;
    ppuVar13 = (undefined **)0x0;
    if (ppuVar11 != (undefined **)0x0) {
      local_e0[0] = ((int (*)())GetGlobalPoolAllocator)();
      paVar15 = (unsigned char *)local_e0;
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_(ppuVar11,pcVar29,paVar15);
      uVar19 = extraout_r4;
      ppuVar13 = ppuVar11;
    }
  }
  local_140 = ppuVar13;
  piVar6[1] = (int)param_3;
  a0 = (unsigned char *)(piVar6 + 3);
  *piVar6 = (int)(PTR_vtable_a7b7c0b4 + 8);
  puVar24 = &local_d0;
  piVar6[4] = local_14c;
  piVar6[5] = (int)local_148;
  piVar6[6] = local_144;
  piVar6[7] = (int)local_140;
  piVar6[8] = local_13c;
  piVar6[9] = local_138;
  piVar6[3] = (int)&PTR___ZN5TTypeD1Ev_a7b7d4d0;
  piVar6[10] = local_134;
  piVar6[0xb] = local_130;
  uVar4 = piVar6[0xc];
  uVar21 = (uint)local_12c & 0xfe000000;
  piVar6[0xc] = uVar21 | uVar4 & 0x1ffffff;
  uVar2 = ((uint)local_12c >> 0x13 & 0x3f) << 0x13;
  piVar6[0xc] = uVar2 | uVar21 | uVar4 & 0x7ffff;
  uVar7 = (uint)local_12c & 0x7f800;
  piVar6[0xc] = uVar7 | uVar2 | uVar21 | uVar4 & 0x7ff;
  uVar3 = ((uint)local_12c >> 10 & 1) << 10;
  piVar6[0xc] = uVar3 | uVar7 | uVar2 | uVar21 | uVar4 & 0x3ff;
  piVar6[0xc] = ((uint)local_12c >> 9 & 1) << 9 | uVar3 | uVar7 | uVar2 | uVar21 | uVar4 & 0x1ff;
  piVar6[0xd] = 0;
  piVar6[0xe] = 0;
  piVar6[0xf] = 0;
  a6 = *(uint **)(this + 4);
  local_150 = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  uVar7 = a6[3];
  a6[3] = uVar7 + 1;
  piVar6[2] = uVar7 + 1;
  uVar7 = *a6;
  uVar27 = *(undefined4 *)(uVar7 + ((a6[1] - uVar7 & 0xfffffffc) - 4));
  local_14c = 0;
  psVar10 = (unsigned char *)
            (**(code **)(*piVar6 + 8))(piVar6,uVar19,paVar15,uVar17,uVar18,ppuVar20,a6,uVar7);
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(puVar24,psVar10);
  local_c8 = piVar6;
  std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&local_140,uVar27,puVar24);
  local_150 = local_140;
  piVar5 = (int *)(local_cc + -4);
  local_14c = local_13c;
  local_c0[0] = local_d0;
  do {
    iVar8 = *piVar5;
    uVar21 = iVar8 - 1;
    if (in_RESERVE != '\0') {
      iVar22 = storeWordConditionalIndexed(uVar21,0,piVar5);
      *piVar5 = iVar22;
      bVar30 = 2;
    }
  } while (!(bool)(bVar30 >> 1 & 1));
  uVar19 = extraout_r4_00;
  if (iVar8 < 1) {
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
              ((unsigned char *)(local_cc + -0xc),local_c0);
    uVar19 = extraout_r4_01;
  }
  if (local_14c == 0) {
    uVar7 = piVar6[1];
    uVar21 = (uint)*DAT_a7b7ba18;
    pcVar16 = "redefinition";
    *(byte *)(*(int *)(uVar7 + 4) + *(int *)(*(int *)(uVar7 + 4) + -0xc)) = *DAT_a7b7ba18;
    pcVar29 = *(char **)(uVar7 + 4);
    goto LAB_97b9df14;
  }
  uVar17 = (**(code **)(piVar6[3] + 0x24))(a0,uVar19,puVar24,uVar17,uVar18,ppuVar20,uVar21,uVar7);
  if (2 < uVar17) {
    pcVar29 = (char *)getQualifierString((uint)piVar6[0xc] >> 0x19);
    pcVar16 = " cannot initialize this type of qualifier ";
    goto LAB_97b9df14;
  }
  if (uVar17 != 2) {
    iVar8 = TIntermediate__addSymbol
                      (*(unsigned char **)this,piVar6[2],(unsigned char *)piVar6[1],a0,param_2);
    pTVar12 = (unsigned char *)
              TIntermediate__addAssign(*(unsigned char **)this,0x76,iVar8,param_5,param_2);
    *param_6 = pTVar12;
    if (pTVar12 != (unsigned char *)0x0) {
      return 0;
    }
    TType__getCompleteString(&local_150,param_5 + 8);
    TType__getCompleteString((unsigned char *)&local_140,iVar8 + 8);
    TParseContext__assignError(this,param_2,"=",(unsigned char *)&local_140,&local_150);
    piVar6 = (int *)(local_13c - 4);
    local_60[0] = local_140;
    do {
      iVar8 = *piVar6;
      if (in_RESERVE != '\0') {
        iVar22 = storeWordConditionalIndexed(iVar8 + -1,0,piVar6);
        *piVar6 = iVar22;
        bVar30 = 2;
      }
    } while (!(bool)(bVar30 >> 1 & 1));
    if (iVar8 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_13c - 0xc),local_60);
    }
    piVar6 = (int *)(local_14c - 4);
    local_50[0] = local_150;
    do {
      iVar8 = *piVar6;
      if (in_RESERVE != '\0') {
        iVar22 = storeWordConditionalIndexed(iVar8 + -1,0,piVar6);
        *piVar6 = iVar22;
        bVar30 = 2;
      }
    } while (!(bool)(bVar30 >> 1 & 1));
    if (0 < iVar8) {
      return 1;
    }
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
              ((unsigned char *)(local_14c - 0xc),local_50);
    return 1;
  }
  (**(code **)(*(int *)param_5 + 0x38))((unsigned char *)&local_150,param_5);
  local_150 = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  uVar17 = -((int)-((uint)local_12c >> 0x19 ^ 2) >> 0x1f);
  bVar30 = (uVar17 == 0) << 1;
  if (uVar17 != 0) {
    TType__getCompleteString(&local_120,a0);
    bVar1 = *DAT_a7b7ba18;
    *(byte *)(local_11c + *(int *)(local_11c - 0xc)) = bVar1;
    error((int)this,(char *)param_2," assigning non-constant to","=","\'%s\'",local_11c,(uint)bVar1,
          uVar7);
    piVar5 = (int *)(local_11c - 4);
    local_b0[0] = local_120;
    do {
      iVar8 = *piVar5;
      if (in_RESERVE != '\0') {
        iVar22 = storeWordConditionalIndexed(iVar8 + -1,0,piVar5);
        *piVar5 = iVar22;
        bVar30 = 2;
      }
    } while (!(bool)(bVar30 >> 1 & 1));
    pppuVar14 = local_b0;
    uVar17 = local_11c;
    if (0 < iVar8) goto LAB_97b9e184;
LAB_97b9e848:
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
              ((unsigned char *)(uVar17 - 0xc),pppuVar14);
LAB_97b9e184:
    (**(code **)(piVar6[3] + 0x28))(a0,0);
    return 1;
  }
  paVar15 = *(unsigned char **)(param_4 + 0x14);
  uVar7 = *(uint *)(param_4 + 4);
  ppuVar20 = *(undefined ***)param_4;
  local_118 = *(undefined ***)(param_4 + 8);
  local_114 = *(uint *)(param_4 + 0xc);
  local_110 = *(uint *)(param_4 + 0x10);
  uVar18 = *(uint *)(param_4 + 0x18);
  local_12c = (unsigned char *)
              ((local_110 & 1) << 9 |
              (local_114 & 1) << 10 |
              ((uint)local_118 & 0xff) << 0xb |
              ((uint)ppuVar20 & 0x3f) << 0x13 | uVar7 << 0x19 | (uint)local_12c & 0x1ff);
  local_150 = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  local_148 = (undefined **)0x0;
  local_138 = 0;
  bVar30 = 2;
  local_14c = uVar17;
  local_144 = uVar17;
  ppuVar13 = (undefined **)0x0;
  local_13c = uVar17;
  local_134 = uVar17;
  local_130 = uVar17;
  local_120 = ppuVar20;
  local_11c = uVar7;
  local_10c = paVar15;
  local_108 = uVar18;
  local_100 = ppuVar20;
  local_fc = uVar7;
  local_f8 = local_118;
  local_f4 = local_114;
  local_f0 = local_110;
  local_ec = paVar15;
  local_e8 = uVar18;
  if (paVar15 != (unsigned char *)0x0) {
    local_148 = *(undefined ***)(paVar15 + 8);
    local_140 = (undefined **)uVar17;
    local_138 = uVar17;
    uVar31 = TType__setStructSize((unsigned char *)&local_150,*(unsigned char **)(paVar15 + 8));
    local_138 = (uint)((ulonglong)uVar31 >> 0x20);
    iVar8 = (**(code **)(*(int *)local_ec + 0x18))
                      (local_ec,(int)uVar31,paVar15,uVar17,uVar18,uVar7,*(int *)local_ec);
    *(byte *)(*(int *)(iVar8 + 4) + *(int *)(*(int *)(iVar8 + 4) + -0xc)) = *DAT_a7b7ba18;
    pcVar29 = *(char **)(iVar8 + 4);
    pTVar9 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
    ppuVar11 = (undefined **)((int (*)())TPoolAllocator__allocate)(pTVar9,8);
    bVar30 = (ppuVar11 == (undefined **)0x0) << 1;
    ppuVar13 = (undefined **)0x0;
    if (ppuVar11 != (undefined **)0x0) {
      local_a0[0] = ((int (*)())GetGlobalPoolAllocator)();
      paVar15 = (unsigned char *)local_a0;
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_(ppuVar11,pcVar29,paVar15);
      ppuVar13 = ppuVar11;
    }
  }
  local_140 = ppuVar13;
  (**(code **)(*(int *)param_5 + 0x38))(&local_120,param_5);
  iVar8 = 0;
  if ((((uint)local_12c & 0x1fffe00) == (local_fc & 0x1fffe00)) && (local_148 == local_118)) {
    iVar8 = 1;
  }
  local_150 = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  local_120 = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  if (iVar8 == 0) {
    pcVar29 = (char *)getQualifierString((uint)piVar6[0xc] >> 0x19);
    error((int)this,(char *)param_2," non-matching types for const initializer ",pcVar29,"",uVar7,
          iVar8,ppuVar20);
    goto LAB_97b9e184;
  }
  iVar8 = (**(code **)(*(int *)param_5 + 0x18))(param_5);
  if (iVar8 == 0) {
    iVar8 = (**(code **)(*(int *)param_5 + 0x1c))(param_5);
    if (iVar8 != 0) {
      pcVar25 = (unsigned char *)piVar6[0xe];
      if (pcVar25 == (unsigned char *)0x0) {
        if (piVar6[5] == 0) {
          uVar21 = piVar6[0xc];
          if ((uVar21 & 0x400) == 0) {
            iVar8 = (int)(uVar21 << 0xd | uVar21 >> 0x13) >> 0x18;
          }
          else {
            iVar8 = (int)(uVar21 << 0xd | uVar21 >> 0x13) >> 0x18;
            iVar8 = iVar8 * iVar8;
          }
        }
        else {
          iVar8 = piVar6[9];
        }
        pTVar9 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
        pcVar25 = (unsigned char *)((int (*)())TPoolAllocator__allocate)(pTVar9,iVar8 << 2);
        piVar6[0xe] = (int)pcVar25;
      }
      piVar5 = (int *)(**(code **)(*(int *)param_5 + 0x1c))(param_5);
      iVar8 = (**(code **)(*piVar5 + 100))(piVar5);
      uVar19 = extraout_r4_03;
      if (*(int *)(iVar8 + 8) - *(int *)(iVar8 + 4) >> 2 == 1) {
        piVar5 = (int *)(**(code **)(*(int *)param_5 + 0x1c))(param_5);
        iVar8 = (**(code **)(*piVar5 + 100))(piVar5);
        iVar22 = *(int *)**(undefined4 **)(iVar8 + 4);
        piVar5 = (int *)(**(code **)(iVar22 + 0x14))
                                  ((int *)**(undefined4 **)(iVar8 + 4),a1,paVar15,uVar17,uVar18,
                                   uVar7,iVar22);
        iVar8 = (**(code **)(*piVar5 + 0x18))(piVar5);
        uVar19 = a1_00;
        if (iVar8 != 0) {
          local_14c = piVar6[4];
          local_148 = (undefined **)piVar6[5];
          local_144 = piVar6[6];
          local_13c = piVar6[8];
          local_138 = piVar6[9];
          local_134 = piVar6[10];
          local_130 = piVar6[0xb];
          local_140 = (undefined **)piVar6[7];
          local_150 = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
          local_12c = (unsigned char *)
                      (((uint)piVar6[0xc] >> 9 & 1) << 9 |
                      ((uint)piVar6[0xc] >> 10 & 1) << 10 |
                      piVar6[0xc] & 0x7f800U |
                      ((uint)piVar6[0xc] >> 0x13 & 0x3f) << 0x13 |
                      piVar6[0xc] & 0xfe000000U | (uint)local_12c & 0x1ff);
          iVar8 = (**(code **)(*(int *)param_5 + 0x1c))
                            (param_5,a1_00,local_12c,local_130,local_134,local_138,local_144,
                             local_13c);
          uVar27 = *(undefined4 *)(this + 4);
          uVar19 = *(undefined4 *)(iVar8 + 0x30);
          this_01 = *(unsigned char **)this;
          uVar23 = 1;
          goto LAB_97b9e6d8;
        }
      }
      local_14c = piVar6[4];
      local_148 = (undefined **)piVar6[5];
      local_144 = piVar6[6];
      local_13c = piVar6[8];
      local_138 = piVar6[9];
      local_134 = piVar6[10];
      local_130 = piVar6[0xb];
      local_140 = (undefined **)piVar6[7];
      local_150 = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
      uVar18 = ((uint)piVar6[0xc] >> 0x13 & 0x3f) << 0x13;
      uVar7 = ((uint)piVar6[0xc] >> 10 & 1) << 10;
      uVar17 = (uint)local_12c & 0x3ff;
      local_12c = (unsigned char *)
                  (((uint)piVar6[0xc] >> 9 & 1) << 9 |
                  uVar7 | piVar6[0xc] & 0x7f800U |
                          uVar18 | piVar6[0xc] & 0xfe000000U | (uint)local_12c & 0x1ff);
      iVar8 = (**(code **)(*(int *)param_5 + 0x1c))
                        (param_5,uVar19,
                         uVar7 | piVar6[0xc] & 0x7f800U |
                                 uVar18 | piVar6[0xc] & 0xfe000000U | uVar17,local_130,local_134,
                         local_138,local_144,local_13c);
      uVar27 = *(undefined4 *)(this + 4);
      uVar19 = *(undefined4 *)(iVar8 + 0x30);
      this_01 = *(unsigned char **)this;
      uVar23 = 0;
LAB_97b9e6d8:
      iVar8 = TIntermediate__parseConstTree
                        (this_01,param_2,(unsigned char *)param_5,pcVar25,uVar19,uVar27,
                         (unsigned char *)&local_150,uVar23);
      local_150 = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
      *param_6 = (unsigned char *)0x0;
      if (iVar8 != 0) {
        (**(code **)(piVar6[3] + 0x28))(a0,0);
        return iVar8;
      }
      return 0;
    }
    iVar8 = (**(code **)(*(int *)param_5 + 0x28))(param_5);
    if (iVar8 == 0) {
      TType__getCompleteString((unsigned char *)&local_150,a0);
      bVar1 = *DAT_a7b7ba18;
      *(byte *)(local_14c + *(int *)(local_14c - 0xc)) = bVar1;
      error((int)this,(char *)param_2," assigning non-constant to","=","\'%s\'",local_14c,
            (uint)bVar1,ppuVar20);
      piVar5 = (int *)(local_14c - 4);
      local_70[0] = local_150;
      do {
        iVar8 = *piVar5;
        if (in_RESERVE != '\0') {
          iVar22 = storeWordConditionalIndexed(iVar8 + -1,0,piVar5);
          *piVar5 = iVar22;
          bVar30 = 2;
        }
      } while (!(bool)(bVar30 >> 1 & 1));
      if (0 < iVar8) goto LAB_97b9e184;
      pppuVar14 = local_70;
      uVar17 = local_14c;
      goto LAB_97b9e848;
    }
    piVar26 = *(int **)(this + 4);
    piVar5 = (int *)(**(code **)(*(int *)param_5 + 0x28))(param_5);
    uVar19 = (**(code **)(*piVar5 + 0x60))(piVar5);
    iVar8 = *piVar26;
    iVar22 = (piVar26[1] - iVar8 >> 2) + -1;
    while( true ) {
      iVar28 = *(int *)(iVar8 + iVar22 * 4);
      std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______find((unsigned char *)local_80,iVar28,uVar19);
      iVar8 = 0;
      if (local_80[0] != *(int *)(iVar28 + 4)) {
        iVar8 = *(int *)(local_80[0] + 0x18);
      }
      iVar22 = iVar22 + -1;
      if ((iVar8 != 0) || (iVar22 < 0)) break;
      iVar8 = *piVar26;
    }
    iVar8 = *(int *)(iVar8 + 0x38);
  }
  else {
    puVar24 = (undefined4 *)piVar6[0xe];
    if (puVar24 == (undefined4 *)0x0) {
      if (piVar6[5] == 0) {
        uVar7 = piVar6[0xc];
        if ((uVar7 & 0x400) == 0) {
          iVar8 = (int)(uVar7 << 0xd | uVar7 >> 0x13) >> 0x18;
        }
        else {
          iVar8 = (int)(uVar7 << 0xd | uVar7 >> 0x13) >> 0x18;
          iVar8 = iVar8 * iVar8;
        }
      }
      else {
        iVar8 = piVar6[9];
      }
      pTVar9 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
      puVar24 = (undefined4 *)((int (*)())TPoolAllocator__allocate)(pTVar9,iVar8 << 2);
      piVar6[0xe] = (int)puVar24;
    }
    ppuVar13 = *(undefined ***)(param_4 + 8);
    if (ppuVar13 == (undefined **)0x1) {
      local_10c = *(unsigned char **)(param_4 + 0x14);
      uVar7 = *(uint *)(param_4 + 4);
      uVar21 = 0;
      ppuVar20 = *(undefined ***)param_4;
      uVar18 = *(uint *)(param_4 + 0xc);
      local_110 = *(uint *)(param_4 + 0x10);
      uVar17 = *(uint *)(param_4 + 0x18);
      paVar15 = (unsigned char *)
                ((local_110 & 1) << 9 |
                (uVar18 & 1) << 10 |
                ((uint)ppuVar20 & 0x3f) << 0x13 | uVar7 << 0x19 | (uint)local_12c & 0x1ff | 0x800);
      local_150 = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
      local_130 = 0;
      local_14c = 0;
      local_148 = (undefined **)0x0;
      local_144 = 0;
      local_140 = (undefined **)0x0;
      local_13c = 0;
      local_138 = 0;
      local_134 = 0;
      ppuVar11 = local_140;
      local_12c = paVar15;
      local_120 = ppuVar20;
      local_11c = uVar7;
      local_118 = ppuVar13;
      local_114 = uVar18;
      local_108 = uVar17;
      local_100 = ppuVar20;
      local_fc = uVar7;
      local_f8 = ppuVar13;
      local_f4 = uVar18;
      local_f0 = local_110;
      local_ec = local_10c;
      local_e8 = uVar17;
      if (local_10c != (unsigned char *)0x0) {
        local_148 = *(undefined ***)(local_10c + 8);
        uVar31 = TType__setStructSize((unsigned char *)&local_150,*(unsigned char **)(local_10c + 8));
        local_138 = (uint)((ulonglong)uVar31 >> 0x20);
        iVar8 = (**(code **)(*(int *)local_ec + 0x18))
                          (local_ec,(int)uVar31,paVar15,uVar17,uVar18,ppuVar20,*(int *)local_ec);
        uVar21 = (uint)*DAT_a7b7ba18;
        *(byte *)(*(int *)(iVar8 + 4) + *(int *)(*(int *)(iVar8 + 4) + -0xc)) = *DAT_a7b7ba18;
        pcVar29 = *(char **)(iVar8 + 4);
        pTVar9 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
        uVar31 = ((int (*)())TPoolAllocator__allocate)(pTVar9,8);
        this_00 = (undefined **)((ulonglong)uVar31 >> 0x20);
        ppuVar13 = (undefined **)uVar31;
        ppuVar11 = (undefined **)0x0;
        if (this_00 != (undefined **)0x0) {
          local_90[0] = ((int (*)())GetGlobalPoolAllocator)();
          __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                    (this_00,pcVar29,(unsigned char *)local_90);
          ppuVar13 = extraout_r4_02;
          ppuVar11 = this_00;
        }
      }
      local_140 = ppuVar11;
      local_150 = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
      paVar15 = local_12c;
      if (((uint)local_12c >> 0x13 & 0x3f) != 0xe) {
        iVar8 = *(int *)param_4;
        if (iVar8 != 2) {
          if (iVar8 < 3) {
            if (iVar8 == 1) {
              iVar8 = (**(code **)(*(int *)param_5 + 0x18))(param_5,ppuVar13,local_12c,1);
              *puVar24 = **(undefined4 **)(iVar8 + 0x30);
              goto LAB_97b9e850;
            }
          }
          else if (iVar8 == 3) goto LAB_97b9e3bc;
          pcVar29 = "";
          pcVar16 = " cannot initialize constant of this type";
LAB_97b9df14:
          error((int)this,(char *)param_2,pcVar16,pcVar29,"",ppuVar20,uVar21,uVar7);
          return 1;
        }
LAB_97b9e3bc:
        iVar8 = (**(code **)(*(int *)param_5 + 0x18))(param_5);
        *puVar24 = **(undefined4 **)(iVar8 + 0x30);
        goto LAB_97b9e850;
      }
    }
    iVar8 = (**(code **)(*(int *)param_5 + 0x18))(param_5,ppuVar13,paVar15,uVar17,uVar18);
    iVar8 = *(int *)(iVar8 + 0x30);
  }
  piVar6[0xe] = iVar8;
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
  int *a0;
  int iVar3;
  undefined4 *puVar4;
  
  this_00 = (unsigned char *)(**(code **)(*(int *)param_2 + 0x1c))(param_2);
  uVar1 = 0;
  if (this_00 != (unsigned char *)0x0) {
    iVar2 = TIntermOperator__isConstructor(this_00);
    if ((iVar2 == 0) || (*(int *)(this_00 + 0x30) == 0x75)) {
      uVar1 = 0;
    }
    else {
      iVar2 = (**(code **)(*(int *)this_00 + 100))(this_00);
      for (puVar4 = *(undefined4 **)(iVar2 + 4); puVar4 != *(undefined4 **)(iVar2 + 8);
          puVar4 = puVar4 + 1) {
        a0 = (int *)(**(code **)(*(int *)*puVar4 + 0x14))((int *)*puVar4);
        iVar3 = (**(code **)(*a0 + 0x18))(a0);
        if (iVar3 == 0) {
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
  unsigned char * a0;
  int iVar2;
  unsigned char * pTVar3;
  undefined4 uVar4;
  int *piVar5;
  unsigned char * pTVar6;
  unsigned char * pTVar7;
  unsigned char * a0_00;
  undefined4 a1;
  char *pcVar8;
  undefined4 a5;
  int in_r9;
  undefined4 in_r10;
  undefined4 *puVar9;
  int iVar10;
  undefined4 *puVar11;
  undefined1 auStack_40 [4];
  int local_3c;
  undefined4 *local_38;
  unsigned char * local_34;
  
  if (param_2 == (unsigned char *)0x0) {
    return (unsigned char *)0x0;
  }
  iVar10 = 0;
  bVar1 = param_4 != 0x75;
  puVar9 = (undefined4 *)0x0;
  pcVar8 = param_6;
  a0 = (unsigned char *)(**(code **)(*(int *)param_2 + 0x1c))(param_2);
  if (!bVar1) {
    iVar10 = *(int *)(param_5 + 0x24);
    puVar9 = *(undefined4 **)(iVar10 + 4);
  }
  if (((a0 == (unsigned char *)0x0) || (*(int *)(a0 + 0x30) != 0)) ||
     (iVar2 = (**(code **)(*(int *)a0 + 100))(a0),
     *(int *)(iVar2 + 8) - *(int *)(iVar2 + 4) >> 2 == 1)) {
    if (bVar1) {
      uVar4 = (*(code *)**(undefined4 **)param_2)(param_2);
      a5 = 0;
      pTVar3 = (unsigned char *)((int (*)())TParseContext__constructBuiltIn)(this,param_3,param_4,param_2,uVar4,0);
      if (pTVar3 == (unsigned char *)0x0) {
        return (unsigned char *)0x0;
      }
      iVar10 = (**(code **)(*(int *)pTVar3 + 0x1c))(pTVar3);
      if (iVar10 == 0) {
        return pTVar3;
      }
      piVar5 = (int *)(**(code **)(*(int *)pTVar3 + 0x1c))(pTVar3);
      iVar10 = (**(code **)(*piVar5 + 100))(piVar5);
      iVar10 = ((int (*)())TParseContext__canNodeBeRemoved)(this,(unsigned char *)**(undefined4 **)(iVar10 + 4));
      if (iVar10 == 0) {
        return pTVar3;
      }
      piVar5 = (int *)(**(code **)(*(int *)pTVar3 + 0x1c))(pTVar3);
      iVar10 = (**(code **)(*piVar5 + 100))(piVar5);
      iVar2 = *(int *)**(undefined4 **)(iVar10 + 4);
      pTVar6 = (unsigned char *)
               (**(code **)(iVar2 + 0x1c))
                         ((int *)**(undefined4 **)(iVar10 + 4),a1,param_4,param_2,uVar4,a5,iVar2);
      pTVar3 = (unsigned char *)
               __ZN13TIntermediate15removeChildNodeEP12TIntermTypedP5TTypeP16TIntermAggregate
                         (*(void **)this,pTVar3,param_3,pTVar6);
      return pTVar3;
    }
    if (*(int *)(iVar10 + 8) - *(int *)(iVar10 + 4) >> 3 == 1) {
      iVar10 = (*(code *)**(undefined4 **)param_2)(param_2);
      pTVar3 = (unsigned char *)((int (*)())TParseContext__constructStruct)(this,param_2,(unsigned char *)*puVar9,1,iVar10,0);
      return pTVar3;
    }
  }
  else {
    pTVar7 = (unsigned char *)(**(code **)(*(int *)a0 + 100))(a0);
    if ((bVar1) ||
       (in_r9 = *(int *)(pTVar7 + 4),
       *(int *)(iVar10 + 8) - *(int *)(iVar10 + 4) >> 3 == *(int *)(pTVar7 + 8) - in_r9 >> 2)) {
      local_3c = 0;
      puVar11 = *(undefined4 **)(pTVar7 + 4);
      do {
        iVar10 = local_3c;
        local_38 = puVar11;
        if (puVar11 == *(undefined4 **)(pTVar7 + 8)) {
          pTVar3 = (unsigned char *)
                   TIntermediate__setAggregateOperator(*(unsigned char **)this,a0,param_4,param_6);
          return pTVar3;
        }
        if (bVar1) {
          uVar4 = (*(code *)**(undefined4 **)param_2)(param_2);
          a0_00 = (unsigned char *)((int (*)())TParseContext__constructBuiltIn)(this,param_3,param_4,*puVar11,uVar4,1);
          if (a0_00 != (unsigned char *)0x0) {
            iVar10 = ((int (*)())TParseContext__canNodeBeRemoved)(this,a0_00);
            if (iVar10 == 0) goto LAB_97b9ed60;
            pTVar6 = (unsigned char *)(**(code **)(*(int *)a0_00 + 0x1c))(a0_00);
            __ZN13TIntermediate15removeChildNodeER7TVectorIP11TIntermNodeER5TTypeRiRN9__gnu_cxx17__normal_iteratorIPS2_St6vectorIS2_14pool_allocatorIS2_EEEEP16TIntermAggregate
                      (*(void **)this,pTVar7,param_3,&local_3c,(unsigned char *)&local_38,pTVar6
                      );
          }
        }
        else {
          iVar2 = (*(code *)**(undefined4 **)param_2)(param_2);
          a0_00 = (unsigned char *)
                  ((int (*)())TParseContext__constructStruct)(this,(unsigned char *)*puVar11,(unsigned char *)puVar9[iVar10 * 2],
                                  local_3c + 1,iVar2,1);
          if (a0_00 != (unsigned char *)0x0) {
LAB_97b9ed60:
            std__vector_TIntermNode__pool_allocator_TIntermNode_____erase
                      (auStack_40,pTVar7,local_38);
            local_34 = a0_00;
            std__vector_TIntermNode__pool_allocator_TIntermNode_____insert
                      (auStack_40,pTVar7,local_38,&local_34);
          }
        }
        local_3c = local_3c + 1;
        puVar11 = local_38 + 1;
      } while( true );
    }
  }
  error((int)this,param_6,
        "Number of constructor parameters does not match the number of structure fields",
        "constructor","",pcVar8,in_r9,in_r10);
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
                       (*(unsigned char **)this,uVar7,param_4,uVar2,*(undefined4 *)(this + 4),iVar4,
                        iVar6);
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
  undefined4 a1;
  unsigned char * a2;
  int a3;
  int a4;
  int a5;
  int a6;
  undefined **local_80 [2];
  int local_78;
  uint local_5c;
  undefined **local_50 [9];
  uint local_2c;
  
  a2 = param_3;
  a3 = param_4;
  a4 = param_5;
  a5 = param_6;
  piVar1 = (int *)(**(code **)(*(int *)param_2 + 0x14))(param_2);
  (**(code **)(*piVar1 + 0x38))(local_80,piVar1);
  a6 = 0;
  if (((*(uint *)(param_3 + 0x24) & 0x1fffe00) == (local_5c & 0x1fffe00)) &&
     (*(int *)(param_3 + 8) == local_78)) {
    a6 = 1;
  }
  local_80[0] = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  if (a6 == 0) {
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
  else if (param_6 == 0) {
    pTVar3 = (unsigned char *)(**(code **)(*(int *)param_2 + 0x14))(param_2);
    uVar2 = TIntermediate__setAggregateOperator(*(unsigned char **)this,pTVar3,0x75,param_5);
  }
  else {
    uVar2 = (**(code **)(*(int *)param_2 + 0x14))(param_2,a1,a2,a3,a4,a5,a6);
  }
  return uVar2;
}

/* TParseContext__addConstVectorNode @ 0x97b9f138 (148 bytes) */
int TParseContext__addConstVectorNode(this, param_2, param_3, param_4, param_5, param_6)
  unsigned char * this;
  unsigned char * param_2;
  unsigned char * param_3;
  int param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  undefined *puVar1;
  undefined **ppuVar2;
  int iVar3;
  undefined *puVar4;
  int iVar5;
  unsigned char * a1;
  int *piVar6;
  unsigned char * pTVar7;
  unsigned char * pcVar8;
  unsigned char * pTVar9;
  undefined4 a1_00;
  uint a1_01;
  undefined4 in_r9;
  undefined4 in_r10;
  unsigned char * pcVar10;
  void *this_00;
  int iVar11;
  char in_RESERVE;
  byte bVar12;
  undefined **local_90 [4];
  char acStack_80 [20];
  uint local_6c;
  unsigned char aaStack_40 [16];
  
  pTVar9 = param_3;
  iVar11 = param_4;
  iVar5 = (**(code **)(*(int *)param_3 + 0x18))(param_3);
  a1 = (unsigned char *)(**(code **)(*(int *)param_3 + 0x1c))(param_3);
  if (iVar5 != 0) {
    pcVar10 = *(unsigned char **)(iVar5 + 0x30);
    if (pcVar10 == (unsigned char *)0x0) {
      this_00 = *(void **)(this + 8);
                    
      __ZN13TInfoSinkBase6appendEPKc(this_00,"INTERNAL ERROR: ");
      a1_01 = param_4 & 0xffff;
      bVar12 = (a1_01 == 0) << 1;
      if (a1_01 == 0) {
        _sprintf(acStack_80,"%d:? ",param_4 >> 0x10);
      }
      else {
        _sprintf(acStack_80,"%d:%d",param_4 >> 0x10,a1_01);
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
          bVar12 = 2;
        }
      } while (!(bool)(bVar12 >> 1 & 1));
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
  if (a1 == (unsigned char *)0x0) {
    error((int)this,(char *)param_4,"No aggregate or constant union node available","Internal Error"
          ,"",param_6,in_r9,in_r10);
    TParseContext__recover(this);
    return (unsigned char *)0x0;
  }
  (**(code **)(*(int *)a1 + 0x38))(local_90,a1);
  if ((local_6c & 0x400) == 0) {
    iVar5 = (int)(local_6c << 0xd | local_6c >> 0x13) >> 0x18;
  }
  else {
    iVar5 = (int)(local_6c << 0xd | local_6c >> 0x13) >> 0x18;
    iVar5 = iVar5 * iVar5;
  }
  pTVar7 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
  pcVar10 = (unsigned char *)((int (*)())TPoolAllocator__allocate)(pTVar7,iVar5 << 2);
  local_90[0] = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  piVar6 = (int *)(**(code **)(*(int *)a1 + 0x1c))(a1);
  iVar5 = (**(code **)(*piVar6 + 100))(piVar6);
  if (*(int *)(iVar5 + 8) - *(int *)(iVar5 + 4) >> 2 == 1) {
    piVar6 = (int *)(**(code **)(*(int *)a1 + 0x1c))(a1);
    iVar5 = (**(code **)(*piVar6 + 100))(piVar6);
    iVar3 = *(int *)**(undefined4 **)(iVar5 + 4);
    piVar6 = (int *)(**(code **)(iVar3 + 0x14))
                              ((int *)**(undefined4 **)(iVar5 + 4),a1_00,pTVar9,iVar11,param_5,
                               param_6,iVar3);
    iVar11 = (**(code **)(*piVar6 + 0x18))(piVar6);
    if (iVar11 == 0) goto LAB_97b9f438;
    (**(code **)(*(int *)a1 + 0x38))(local_90,a1);
    in_r10 = 1;
    iVar11 = TIntermediate__parseConstTree
                       (*(unsigned char **)this,param_4,a1,pcVar10,*(undefined4 *)(a1 + 0x30),
                        *(undefined4 *)(this + 4),local_90,1);
  }
  else {
LAB_97b9f438:
    (**(code **)(*(int *)a1 + 0x38))(local_90,a1);
    in_r10 = 0;
    iVar11 = TIntermediate__parseConstTree
                       (*(unsigned char **)this,param_4,a1,pcVar10,*(undefined4 *)(a1 + 0x30),
                        *(undefined4 *)(this + 4),local_90,0);
  }
  local_90[0] = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  if (iVar11 != 0) {
    return (unsigned char *)0x0;
  }
LAB_97b9f4c4:
  iVar11 = *(int *)(param_2 + 0x10);
  iVar5 = 0;
  pTVar7 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
  pcVar8 = (unsigned char *)((int (*)())TPoolAllocator__allocate)(pTVar7,iVar11 << 2);
  if (0 < *(int *)(param_2 + 0x10)) {
    iVar11 = 0;
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
      if (iVar3 <= *(int *)(param_2 + iVar11) != 0) {
        error((int)this,(char *)param_4,"","[","vector field selection out of range \'%d\'",
              *(undefined4 *)(param_2 + iVar11),(uint)(iVar3 <= *(int *)(param_2 + iVar11)),in_r10);
        TParseContext__recover(this);
        *(undefined4 *)(param_2 + iVar11) = 0;
      }
      iVar5 = iVar5 + 1;
      *(undefined4 *)(pcVar8 + iVar11) = *(undefined4 *)(pcVar10 + *(int *)(param_2 + iVar11) * 4);
      iVar11 = iVar11 + 4;
    } while (iVar5 < *(int *)(param_2 + 0x10));
  }
  (**(code **)(*(int *)param_3 + 0x38))(local_90,param_3);
  pTVar9 = (unsigned char *)
           TIntermediate__addConstantUnion(*(unsigned char **)this,pcVar8,(unsigned char *)local_90,param_4)
  ;
  return pTVar9;
}

/* TParseContext__addConstMatrixNode @ 0x97b9f600 (904 bytes) */
int TParseContext__addConstMatrixNode(this, param_2, param_3, param_4)
  unsigned char * this;
  int param_2;
  unsigned char * param_3;
  int param_4;
{
  int *piVar1;
  unsigned char * a1;
  undefined4 uVar2;
  unsigned char * this_00;
  unsigned char * pcVar3;
  undefined4 a1_00;
  char *a2;
  char *a3;
  char *in_r7;
  int in_r8;
  undefined4 in_r9;
  int a6;
  undefined4 in_r10;
  int iVar4;
  int iVar5;
  undefined **local_60 [9];
  uint local_3c;
  
  a2 = (char *)param_3;
  a3 = (char *)param_4;
  piVar1 = (int *)(**(code **)(*(int *)param_3 + 0x18))(param_3);
  a1 = (unsigned char *)(**(code **)(*(int *)param_3 + 0x1c))(param_3);
  (**(code **)(*(int *)param_3 + 0x38))(local_60,param_3);
  local_60[0] = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  iVar4 = param_2;
  if ((int)(local_3c << 0xd | local_3c >> 0x13) >> 0x18 <= param_2) {
    a2 = "";
    a3 = "[";
    in_r7 = "matrix field selection out of range \'%d\'";
    iVar4 = 0;
    error((int)this,(char *)param_4,"","[","matrix field selection out of range \'%d\'",param_2,
          in_r9,in_r10);
    TParseContext__recover(this);
    in_r8 = param_2;
  }
  if (piVar1 != (int *)0x0) {
    iVar5 = piVar1[0xc];
    (**(code **)(*piVar1 + 0x38))((unsigned char *)local_60,piVar1);
    local_60[0] = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
    (**(code **)(*piVar1 + 0x38))((unsigned char *)local_60,piVar1);
    uVar2 = TIntermediate__addConstantUnion
                      (*(unsigned char **)this,
                       (unsigned char *)
                       (iVar5 + ((int)(local_3c << 0xd | local_3c >> 0x13) >> 0x18) * iVar4 * 4),
                       (unsigned char *)local_60,param_4);
    return uVar2;
  }
  if (a1 == (unsigned char *)0x0) {
    error((int)this,(char *)param_4,"No Aggregate or Constant Union node available","Internal Error"
          ,"",in_r8,in_r9,in_r10);
    TParseContext__recover(this);
    return 0;
  }
  (**(code **)(*(int *)a1 + 0x38))((unsigned char *)local_60,a1);
  if ((local_3c & 0x400) == 0) {
    iVar5 = (int)(local_3c << 0xd | local_3c >> 0x13) >> 0x18;
  }
  else {
    iVar5 = (int)(local_3c << 0xd | local_3c >> 0x13) >> 0x18;
    iVar5 = iVar5 * iVar5;
  }
  this_00 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
  pcVar3 = (unsigned char *)((int (*)())TPoolAllocator__allocate)(this_00,iVar5 << 2);
  local_60[0] = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  (**(code **)(*(int *)a1 + 0x38))((unsigned char *)local_60,a1);
  local_60[0] = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  piVar1 = (int *)(**(code **)(*(int *)a1 + 0x1c))(a1);
  iVar5 = (**(code **)(*piVar1 + 100))(piVar1);
  if (*(int *)(iVar5 + 8) - *(int *)(iVar5 + 4) >> 2 == 1) {
    piVar1 = (int *)(**(code **)(*(int *)a1 + 0x1c))(a1);
    iVar5 = (**(code **)(*piVar1 + 100))(piVar1);
    a6 = *(int *)**(undefined4 **)(iVar5 + 4);
    piVar1 = (int *)(**(code **)(a6 + 0x14))
                              ((int *)**(undefined4 **)(iVar5 + 4),a1_00,a2,a3,in_r7,in_r8,a6);
    iVar5 = (**(code **)(*piVar1 + 0x18))(piVar1);
    if (iVar5 != 0) {
      (**(code **)(*(int *)a1 + 0x38))((unsigned char *)local_60,a1);
      iVar5 = TIntermediate__parseConstTree
                        (*(unsigned char **)this,param_4,a1,pcVar3,*(undefined4 *)(a1 + 0x30),
                         *(undefined4 *)(this + 4),(unsigned char *)local_60,1);
      goto LAB_97b9f8f4;
    }
  }
  (**(code **)(*(int *)a1 + 0x38))(local_60,a1);
  iVar5 = TIntermediate__parseConstTree
                    (*(unsigned char **)this,param_4,a1,pcVar3,*(undefined4 *)(a1 + 0x30),
                     *(undefined4 *)(this + 4),local_60,0);
LAB_97b9f8f4:
  local_60[0] = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  uVar2 = 0;
  if (iVar5 == 0) {
    (**(code **)(*(int *)a1 + 0x38))(local_60,a1);
    uVar2 = TIntermediate__addConstantUnion
                      (*(unsigned char **)this,
                       pcVar3 + ((int)(local_3c << 0xd | local_3c >> 0x13) >> 0x18) * iVar4 * 4,
                       (unsigned char *)local_60,param_4);
  }
  return uVar2;
}

/* TParseContext__addConstStruct @ 0x97b9f988 (848 bytes) */
int TParseContext__addConstStruct(this, param_2, param_3, param_4, param_5, param_6)
  unsigned char * this;
  unsigned char * param_2;
  unsigned char * param_3;
  int param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  int iVar1;
  unsigned char * pTVar2;
  unsigned char * a1;
  unsigned char * this_00;
  unsigned char * this_01;
  int *piVar3;
  undefined4 uVar4;
  undefined4 a1_00;
  undefined4 a1_01;
  uint *puVar5;
  unsigned char * a2;
  int iVar6;
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
  a2 = param_3;
  iVar1 = param_4;
  (**(code **)(*(int *)param_3 + 0x38))(local_80,param_3);
  iVar6 = *(int *)param_3;
  local_80[0] = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  pTVar2 = (unsigned char *)(**(code **)(iVar6 + 0x18))(param_3,a1_00,a2,iVar1,param_5,param_6,iVar6);
  a1 = (unsigned char *)(**(code **)(*(int *)param_3 + 0x1c))(param_3);
  for (uVar9 = 0; uVar9 < (uint)(*(int *)(local_78 + 8) - *(int *)(local_78 + 4) >> 3);
      uVar9 = uVar9 + 1) {
    piVar3 = *(int **)(*(int *)(local_78 + 4) + uVar9 * 8);
    iVar7 = (**(code **)(*piVar3 + 0x1c))(piVar3);
    uVar12 = *(uint *)(*(int *)(iVar7 + 4) + -0xc);
    local_50 = uVar12;
    uVar10 = *(uint *)((int)*(void **)(param_2 + 4) + -0xc);
    local_4c[0] = uVar10;
    puVar5 = local_4c;
    if (uVar12 <= uVar10) {
      puVar5 = &local_50;
    }
    a2 = (unsigned char *)*puVar5;
    iVar7 = _memcmp(*(void **)(iVar7 + 4),*(void **)(param_2 + 4),(size_t)a2);
    if (iVar7 == 0) {
      iVar7 = uVar12 - uVar10;
    }
    if (iVar7 == 0) break;
    this_00 = *(unsigned char **)(*(int *)(local_78 + 4) + uVar9 * 8);
    if (*(unsigned char **)(this_00 + 8) == (unsigned char *)0x0) {
      iVar7 = (**(code **)(*(int *)this_00 + 0x30))(this_00);
    }
    else {
      iVar7 = TType__setStructSize(this_00,*(unsigned char **)(this_00 + 8));
    }
    iVar8 = iVar8 + iVar7;
  }
  if (pTVar2 != (unsigned char *)0x0) {
    iVar1 = *(int *)pTVar2;
    pcVar11 = *(unsigned char **)(pTVar2 + 0x30);
    a1 = pTVar2;
    goto LAB_97b9fc60;
  }
  if (a1 == (unsigned char *)0x0) {
    error((int)this,(char *)param_4,"No Aggregate or Constant Union node available","Internal Error"
          ,"",param_6,iVar6,in_r10);
    TParseContext__recover(this);
    return 0;
  }
  (**(code **)(*(int *)a1 + 0x38))(local_80,a1);
  this_01 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
  pcVar11 = (unsigned char *)((int (*)())TPoolAllocator__allocate)(this_01,local_68 << 2);
  local_80[0] = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  piVar3 = (int *)(**(code **)(*(int *)a1 + 0x1c))(a1);
  iVar6 = (**(code **)(*piVar3 + 100))(piVar3);
  if (*(int *)(iVar6 + 8) - *(int *)(iVar6 + 4) >> 2 == 1) {
    piVar3 = (int *)(**(code **)(*(int *)a1 + 0x1c))(a1);
    iVar6 = (**(code **)(*piVar3 + 100))(piVar3);
    iVar7 = *(int *)**(undefined4 **)(iVar6 + 4);
    piVar3 = (int *)(**(code **)(iVar7 + 0x14))
                              ((int *)**(undefined4 **)(iVar6 + 4),a1_01,a2,iVar1,param_5,param_6,
                               iVar7);
    iVar1 = (**(code **)(*piVar3 + 0x18))(piVar3);
    if (iVar1 == 0) goto LAB_97b9fc00;
    (**(code **)(*(int *)a1 + 0x38))(local_80,a1);
    iVar1 = TIntermediate__parseConstTree
                      (*(unsigned char **)this,param_4,a1,pcVar11,*(undefined4 *)(a1 + 0x30),
                       *(undefined4 *)(this + 4),local_80,1);
  }
  else {
LAB_97b9fc00:
    (**(code **)(*(int *)a1 + 0x38))(local_80,a1);
    iVar1 = TIntermediate__parseConstTree
                      (*(unsigned char **)this,param_4,a1,pcVar11,*(undefined4 *)(a1 + 0x30),
                       *(undefined4 *)(this + 4),local_80,0);
  }
  local_80[0] = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  if (iVar1 != 0) {
    return 0;
  }
  iVar1 = *(int *)a1;
LAB_97b9fc60:
  (**(code **)(iVar1 + 0x38))(local_80,a1);
  uVar4 = TIntermediate__addConstantUnion
                    (*(unsigned char **)this,pcVar11 + iVar8 * 4,(unsigned char *)local_80,param_4);
  return uVar4;
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
    ((int (*)())__ZN14TPoolAllocatorC1Ebii)(this,1,0x2000,0x10);
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
  undefined4 param_2;
  int param_3;
  int param_4;
{
  uint uVar1;
  
  *(undefined4 *)this = param_2;
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
  undefined4 param_2;
  int param_3;
  int param_4;
{
  uint uVar1;
  
  *(undefined4 *)this = param_2;
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
  undefined4 param_2;
  int param_3;
  int param_4;
{
  uint uVar1;
  
  *(undefined4 *)this = param_2;
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
    (**(code **)(*(int *)param_1 + 8))
              (param_1,&local_50,param_3,param_4,param_5,param_6,DAT_a7b7ba20,param_1);
  }
  return local_20;
}

/* AliveSymbol @ 0x97ba0514 (76 bytes) */
int AliveSymbol(param_1, param_2)
  unsigned char * param_1;
  unsigned char * param_2;
{
  int iVar1;
  
  iVar1 = (**(code **)(*(int *)param_1 + 0x44))(param_1);
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
                    
                    
  (**(code **)(*(int *)param_1 + 0x30))(param_1);
  return;
}

/* RemoveBinary @ 0x97ba0588 (56 bytes) */
int RemoveBinary(param_1, param_2, param_3)
  int param_1;
  unsigned char * param_2;
  unsigned char * param_3;
{
  if (param_2 != (unsigned char *)0x0) {
    (**(code **)(*(int *)param_2 + 0x30))(param_2);
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
    (**(code **)(*(int *)param_2 + 0x30))(param_2);
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
    (**(code **)(*(int *)param_2 + 0x30))(param_2);
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
    (**(code **)(*(int *)param_2 + 0x30))(param_2);
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
                    
                    
  (**(code **)(*(int *)param_1 + 0x30))(param_1);
  return;
}

/* RemoveAllTreeNodes @ 0x97ba0680 (168 bytes) */
int RemoveAllTreeNodes(param_1)
  unsigned char * param_1;
{
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
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
  (**(code **)(*(int *)param_1 + 8))
            (param_1,&local_40,in_r5,in_r6,in_r7,in_r8,DAT_a7b7ba28,*(int *)param_1);
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
    ((int (*)())__ZN14TPoolAllocatorC1Ebii)(this,1,0x2000,0x10);
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
     (this = (unsigned char *)(**(code **)(*param_1 + 0xc))(param_1), this != (unsigned char *)0x0
     )) {
    pcVar3 = (char *)**(undefined4 **)(this + 0x84);
    __ZNSs7replaceEmmPKcm(*(undefined4 **)(this + 0x84),0,*(ulong *)(pcVar3 + -0xc),pcVar3,0);
    pcVar3 = *(char **)(*(int *)(this + 0x84) + 8);
    __ZNSs7replaceEmmPKcm((void *)(*(int *)(this + 0x84) + 8),0,*(ulong *)(pcVar3 + -0xc),pcVar3,0);
    iVar5 = 0;
    TGenericLinker__reset(this);
    if (0 < param_3) {
      do {
        piVar1 = param_2[iVar5];
        if (piVar1 == (int *)0x0) {
          this_00 = *(void **)(this + 0x84);
          pcVar4 = "Invalid shader passed to linker (internal error).";
          pcVar3 = "INTERNAL ERROR: ";
                    
LAB_97ba1bf0:
          __ZN13TInfoSinkBase6appendEPKc(this_00,pcVar3);
          __ZN13TInfoSinkBase6appendEPKc(this_00,pcVar4);
          __ZN13TInfoSinkBase6appendEPKc(this_00,"\n");
          return 0;
        }
        piVar1 = (int *)(**(code **)(*piVar1 + 8))(piVar1);
        if ((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0x20))(piVar1), iVar2 == 0)) {
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

