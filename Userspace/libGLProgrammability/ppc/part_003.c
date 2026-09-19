#include "decls.h"

/* _ReadFromTokenStream @ 0x97b8ac04 (172 bytes) */
int _ReadFromTokenStream(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 uVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  
  puVar4 = _malloc(0x20);
  puVar2 = PTR__cpp_a7b7c0a4;
  iVar3 = *(int *)PTR__cpp_a7b7c0a4;
  puVar4[7] = 0;
  *puVar4 = 0;
  puVar4[1] = 0;
  puVar4[5] = 0;
  puVar4[6] = 0;
  puVar4[2] = 0;
  puVar4[3] = 0;
  puVar4[4] = param_2;
  uVar1 = DAT_a7b7b050;
  uVar5 = *(undefined4 *)(iVar3 + 0x20);
  puVar4[5] = 1;
  puVar4[1] = uVar1;
  *puVar4 = uVar5;
  puVar4[7] = param_3;
  puVar4[6] = param_1;
  _RewindTokenStream(param_1);
  *(undefined4 **)(*(int *)puVar2 + 0x20) = puVar4;
  return 1;
}

/* _UngetToken @ 0x97b8ad14 (156 bytes) */
int _UngetToken(param_1, param_2)
  undefined4 param_1;
  void *param_2;
{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = _malloc(0xac);
  _memset(puVar1,0,0xac);
  puVar1[6] = param_1;
  _memcpy(puVar1 + 7,param_2,0x90);
  iVar2 = *(int *)PTR__cpp_a7b7c0a4;
  puVar1[1] = DAT_a7b7b04c;
  *puVar1 = *(undefined4 *)(iVar2 + 0x20);
  puVar1[4] = *(undefined4 *)(*(int *)(iVar2 + 0x20) + 0x10);
  puVar1[5] = *(undefined4 *)(*(int *)(iVar2 + 0x20) + 0x14);
  *(undefined4 **)(iVar2 + 0x20) = puVar1;
  return;
}

/* _DumpTokenStream @ 0x97b8adb0 (240 bytes) */
int _DumpTokenStream(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
{
  int iVar1;
  char *pcVar2;
  char acStack_80 [116];
  
  _RewindTokenStream(param_2);
  do {
    iVar1 = _ReadToken(param_2,param_3);
    if (iVar1 < 1) {
      return;
    }
    switch(iVar1) {
    case 0x10b:
    case 0x10f:
      goto switchD_97b8ae00_caseD_10b;
    default:
      if (0x7e < iVar1) goto LAB_97b8ae70;
      pcVar2 = "%c";
      break;
    case 0x10e:
    case 0x117:
      iVar1 = *(int *)(param_3 + 8);
LAB_97b8ae70:
      iVar1 = _GetAtomString(*(undefined4 *)PTR__atable_a7b7c0ac,iVar1);
      pcVar2 = "%s ";
      break;
    case 0x116:
      iVar1 = _GetAtomString(*(undefined4 *)PTR__atable_a7b7c0ac,*(undefined4 *)(param_3 + 8));
      pcVar2 = "\"%s\"";
    }
    _sprintf(acStack_80,pcVar2,iVar1);
switchD_97b8ae00_caseD_10b:
    _CPPDebugLogMsg(acStack_80);
  } while( true );
}

/* TBuiltIns__getNumStringArrays @ 0x97b8aed4 (20 bytes) */
int TBuiltIns__getNumStringArrays(this, param_1)
  unsigned char *this;
  int param_1;
{
  return 6 - (uint)(param_1 == 1);
}

/* TBuiltIns__getStringArray @ 0x97b8aee8 (204 bytes) */
int TBuiltIns__getStringArray(this, param_1, param_2)
  unsigned char *this;
  int param_1;
  uint param_2;
{
  undefined *puVar1;
  
  puVar1 = (undefined *)0x0;
  if (param_1 == 1) {
    if (param_2 == 0) {
      puVar1 = &_strBuiltInFunctions;
    }
    if (param_2 == 1) {
      puVar1 = &_strBuiltInFunctionsFragment;
    }
    if (param_2 == 2) {
      puVar1 = &_strStandardFragmentVaryings;
    }
    if (param_2 == 3) {
      puVar1 = &_strStandardUniformConstants;
    }
    if (param_2 != 4) {
      return puVar1;
    }
  }
  else {
    if (param_2 == 0) {
      puVar1 = &_strBuiltInFunctions;
    }
    if (param_2 == 1) {
      puVar1 = &_strBuiltInFunctionsVertex;
    }
    if (param_2 == 2) {
      puVar1 = &_strStandardVertexVaryings;
    }
    if (param_2 == 3) {
      puVar1 = &_strStandardVertexAttributes;
    }
    if (param_2 == 4) {
      puVar1 = &_strStandardUniformConstants;
    }
    if (param_2 != 5) {
      return puVar1;
    }
  }
  return &_strStandardUniforms;
}

/* TBuiltIns__getStringSizeArray @ 0x97b8afb4 (204 bytes) */
int TBuiltIns__getStringSizeArray(this, param_1, param_2)
  unsigned char *this;
  int param_1;
  uint param_2;
{
  undefined *puVar1;
  
  puVar1 = (undefined *)0x0;
  if (param_1 == 1) {
    if (param_2 == 0) {
      puVar1 = &_sizeBuiltInFunctions;
    }
    if (param_2 == 1) {
      puVar1 = &_sizeBuiltInFunctionsFragment;
    }
    if (param_2 == 2) {
      puVar1 = &_sizeStandardFragmentVaryings;
    }
    if (param_2 == 3) {
      puVar1 = &_sizeStandardUniformConstants;
    }
    if (param_2 != 4) {
      return puVar1;
    }
  }
  else {
    if (param_2 == 0) {
      puVar1 = &_sizeBuiltInFunctions;
    }
    if (param_2 == 1) {
      puVar1 = &_sizeBuiltInFunctionsVertex;
    }
    if (param_2 == 2) {
      puVar1 = &_sizeStandardVertexVaryings;
    }
    if (param_2 == 3) {
      puVar1 = &_sizeStandardVertexAttributes;
    }
    if (param_2 == 4) {
      puVar1 = &_sizeStandardUniformConstants;
    }
    if (param_2 != 5) {
      return puVar1;
    }
  }
  return &_sizeStandardUniforms;
}

/* TBuiltIns__getNumStrings @ 0x97b8b080 (148 bytes) */
int TBuiltIns__getNumStrings(this, param_1, param_2)
  unsigned char *this;
  int param_1;
  uint param_2;
{
  bool bVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (param_1 == 1) {
    if (param_2 == 0) {
      uVar2 = 0x454;
    }
    if (param_2 == 1) {
      uVar2 = 0x34;
    }
    if (param_2 == 2) {
      uVar2 = 0x14;
    }
    if (param_2 == 3) {
      uVar2 = 0x34;
    }
    bVar1 = param_2 == 4;
  }
  else {
    if (param_2 == 0) {
      uVar2 = 0x454;
    }
    if (param_2 == 1) {
      uVar2 = 8;
    }
    if (param_2 == 2) {
      uVar2 = 0x1c;
    }
    if (param_2 == 3) {
      uVar2 = 0x38;
    }
    if (param_2 == 4) {
      uVar2 = 0x34;
    }
    bVar1 = param_2 == 5;
  }
  if (bVar1) {
    uVar2 = 0x174;
  }
  return uVar2 >> 2;
}

/* TBuiltIns__initialize @ 0x97b8b114 (4 bytes) */
int TBuiltIns__initialize()
{
  return;
}

/* TBuiltIns__initialize_97b8b118 @ 0x97b8b118 (4 bytes) */
int TBuiltIns__initialize_97b8b118(param_1)
  unsigned char *param_1;
{
  return;
}

/* IdentifyBuiltIns @ 0x97b8b11c (5284 bytes) */
void IdentifyBuiltIns_97b8c5c0(int param_1,undefined4 *param_2)

{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  ulong uVar6;
  int *piVar7;
  string *psVar8;
  string *psVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined *puVar12;
  char in_RESERVE;
  byte bVar13;
  undefined4 local_3b0 [4];
  undefined **local_3a0;
  undefined4 local_39c;
  undefined4 local_398;
  undefined4 local_394;
  undefined4 local_390;
  undefined4 local_38c;
  undefined4 local_388;
  undefined4 local_384;
  undefined4 local_380;
  uint local_37c;
  undefined4 local_370;
  undefined4 local_36c;
  undefined4 local_360;
  undefined4 local_35c;
  undefined4 local_350;
  int local_34c;
  int *local_348;
  undefined4 local_340;
  undefined4 local_330 [4];
  undefined **local_320;
  undefined4 local_31c;
  undefined4 local_318;
  undefined4 local_314;
  undefined4 local_310;
  undefined4 local_30c;
  undefined4 local_308;
  undefined4 local_304;
  undefined4 local_300;
  uint local_2fc;
  undefined4 local_2f0;
  undefined4 local_2ec;
  undefined4 local_2e0;
  undefined4 local_2dc;
  undefined4 local_2d0;
  int local_2cc;
  int *local_2c8;
  undefined4 local_2c0;
  undefined4 local_2b0 [4];
  undefined **local_2a0;
  undefined4 local_29c;
  undefined4 local_298;
  undefined4 local_294;
  undefined4 local_290;
  undefined4 local_28c;
  undefined4 local_288;
  undefined4 local_284;
  undefined4 local_280;
  uint local_27c;
  undefined4 local_270;
  undefined4 local_26c;
  undefined4 local_260;
  undefined4 local_25c;
  undefined4 local_250;
  int local_24c;
  int *local_248;
  undefined4 local_240;
  undefined4 local_230 [4];
  undefined **local_220;
  undefined4 local_21c;
  undefined4 local_218;
  undefined4 local_214;
  undefined4 local_210;
  undefined4 local_20c;
  undefined4 local_208;
  undefined4 local_204;
  undefined4 local_200;
  uint local_1fc;
  undefined4 local_1f0;
  undefined4 local_1ec;
  undefined4 local_1e0;
  undefined4 local_1dc;
  undefined4 local_1d0;
  int local_1cc;
  int *local_1c8;
  undefined4 local_1c0;
  undefined4 local_1b0 [4];
  undefined **local_1a0;
  undefined4 local_19c;
  undefined4 local_198;
  undefined4 local_194;
  undefined4 local_190;
  undefined4 local_18c;
  undefined4 local_188;
  undefined4 local_184;
  undefined4 local_180;
  uint local_17c;
  undefined4 local_170;
  undefined4 local_16c;
  undefined4 local_160;
  undefined4 local_15c;
  undefined4 local_150;
  int local_14c;
  int *local_148;
  undefined4 local_140;
  undefined4 local_130 [4];
  undefined **local_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  uint local_fc;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d0;
  int local_cc;
  int *local_c8;
  undefined4 local_c0;
  undefined4 local_b0 [4];
  undefined **local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  uint local_7c;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_50;
  int local_4c;
  int *local_48;
  undefined4 local_40;
  
  if (param_1 == 0) {
    uVar6 = GetGlobalPoolAllocator();
    piVar7 = (int *)TPoolAllocator__allocate(uVar6);
    pcVar2 = DAT_a7b7b708;
    uVar6 = GetGlobalPoolAllocator();
    psVar8 = (unsigned char *)TPoolAllocator__allocate(uVar6);
    bVar13 = (psVar8 == (unsigned char *)0x0) << 1;
    psVar9 = (unsigned char *)0x0;
    if (psVar8 != (unsigned char *)0x0) {
      local_1b0[0] = GetGlobalPoolAllocator();
      std__string__string(psVar8,pcVar2,(unsigned char *)local_1b0);
      psVar9 = psVar8;
    }
    puVar12 = PTR_vtable_a7b7c0b4 + 8;
    local_17c = local_17c & 0x801ff | 0x1a082000;
    local_19c = 0;
    local_198 = 0;
    local_194 = 0;
    local_190 = 0;
    local_18c = 0;
    local_188 = 0;
    local_184 = 0;
    local_180 = 0;
    local_1a0 = &PTR__TType_a7b7cf48;
    piVar7[1] = (int)psVar9;
    *piVar7 = (int)puVar12;
    piVar7[4] = 0;
    piVar7[5] = 0;
    piVar7[6] = 0;
    piVar7[7] = 0;
    piVar7[8] = 0;
    piVar7[9] = 0;
    piVar7[10] = 0;
    piVar7[3] = (int)&PTR__TType_a7b7cf48;
    piVar7[0xb] = 0;
    uVar3 = piVar7[0xc];
    piVar7[0xc] = uVar3 & 0x1ffffff | 0x1a000000;
    uVar4 = (local_17c >> 0x13 & 0x3f) << 0x13;
    piVar7[0xc] = uVar4 | uVar3 & 0x7ffff | 0x1a000000;
    piVar7[0xc] = uVar4 | uVar3 & 0x7ff | 0x1a000000 | 0x2000;
    piVar7[0xc] = uVar4 | uVar3 & 0x3ff | 0x1a000000 | 0x2000;
    piVar7[0xc] = uVar4 | uVar3 & 0x1ff | 0x1a000000 | 0x2000;
    piVar7[0xd] = 0;
    piVar7[0xe] = 0;
    piVar7[0xf] = 0;
    iVar5 = param_2[3];
    param_2[3] = iVar5 + 1;
    piVar7[2] = iVar5 + 1;
    local_16c = 0;
    psVar9 = (unsigned char *)(**(code **)(*piVar7 + 8))(piVar7);
    std__string__string((unsigned char *)&local_150,psVar9);
    local_148 = piVar7;
    std::
    _Rb_tree<std::string,std::pair<std::string_const,TSymbol*>,std::_Select1st<std::pair<std::string_const,TSymbol*>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,TSymbol*>>>
    ::insert_unique((unsigned char *)&local_160);
    local_170 = local_160;
    piVar7 = (int *)(local_14c + -4);
    local_16c = local_15c;
    local_140 = local_150;
    do {
      iVar5 = *piVar7;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar5 + -1,0,piVar7);
        *piVar7 = iVar1;
        bVar13 = 2;
      }
    } while (!(bool)(bVar13 >> 1 & 1));
    if (iVar5 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_14c + -0xc));
    }
    local_1a0 = &PTR__TType_a7b7cf48;
    uVar6 = GetGlobalPoolAllocator();
    piVar7 = (int *)TPoolAllocator__allocate(uVar6);
    pcVar2 = DAT_a7b7b70c;
    uVar6 = GetGlobalPoolAllocator();
    psVar8 = (unsigned char *)TPoolAllocator__allocate(uVar6);
    bVar13 = (psVar8 == (unsigned char *)0x0) << 1;
    psVar9 = (unsigned char *)0x0;
    if (psVar8 != (unsigned char *)0x0) {
      local_130[0] = GetGlobalPoolAllocator();
      std__string__string(psVar8,pcVar2,(unsigned char *)local_130);
      psVar9 = psVar8;
    }
    puVar12 = PTR_vtable_a7b7c0b4 + 8;
    local_fc = local_fc & 0x1ff | 0x1c080800;
    local_11c = 0;
    local_118 = 0;
    local_114 = 0;
    local_110 = 0;
    local_10c = 0;
    local_108 = 0;
    local_104 = 0;
    local_100 = 0;
    local_120 = &PTR__TType_a7b7cf48;
    piVar7[1] = (int)psVar9;
    *piVar7 = (int)puVar12;
    piVar7[4] = 0;
    piVar7[5] = 0;
    piVar7[6] = 0;
    piVar7[7] = 0;
    piVar7[8] = 0;
    piVar7[9] = 0;
    piVar7[10] = 0;
    piVar7[3] = (int)&PTR__TType_a7b7cf48;
    piVar7[0xb] = 0;
    uVar4 = piVar7[0xc];
    piVar7[0xc] = uVar4 & 0x1ffffff | 0x1c000000;
    piVar7[0xc] = uVar4 & 0x7ffff | 0x1c080000;
    piVar7[0xc] = uVar4 & 0x7ff | 0x1c080800;
    piVar7[0xc] = uVar4 & 0x3ff | 0x1c080800;
    piVar7[0xc] = uVar4 & 0x1ff | 0x1c080800;
    piVar7[0xd] = 0;
    piVar7[0xe] = 0;
    piVar7[0xf] = 0;
    iVar5 = param_2[3];
    param_2[3] = iVar5 + 1;
    piVar7[2] = iVar5 + 1;
    local_ec = 0;
    psVar9 = (unsigned char *)(**(code **)(*piVar7 + 8))(piVar7);
    std__string__string((unsigned char *)&local_d0,psVar9);
    local_c8 = piVar7;
    std::
    _Rb_tree<std::string,std::pair<std::string_const,TSymbol*>,std::_Select1st<std::pair<std::string_const,TSymbol*>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,TSymbol*>>>
    ::insert_unique((unsigned char *)&local_e0);
    local_f0 = local_e0;
    piVar7 = (int *)(local_cc + -4);
    local_ec = local_dc;
    local_c0 = local_d0;
    do {
      iVar5 = *piVar7;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar5 + -1,0,piVar7);
        *piVar7 = iVar1;
        bVar13 = 2;
      }
    } while (!(bool)(bVar13 >> 1 & 1));
    if (iVar5 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_cc + -0xc));
    }
    local_120 = &PTR__TType_a7b7cf48;
    uVar6 = GetGlobalPoolAllocator();
    piVar7 = (int *)TPoolAllocator__allocate(uVar6);
    pcVar2 = DAT_a7b7b710;
    uVar6 = GetGlobalPoolAllocator();
    psVar8 = (unsigned char *)TPoolAllocator__allocate(uVar6);
    bVar13 = (psVar8 == (unsigned char *)0x0) << 1;
    psVar9 = (unsigned char *)0x0;
    if (psVar8 != (unsigned char *)0x0) {
      local_b0[0] = GetGlobalPoolAllocator();
      std__string__string(psVar8,pcVar2,(unsigned char *)local_b0);
      psVar9 = psVar8;
    }
    puVar12 = PTR_vtable_a7b7c0b4 + 8;
    local_7c = local_7c & 0x801ff | 0x1e082000;
    local_9c = 0;
    local_98 = 0;
    local_94 = 0;
    local_90 = 0;
    local_8c = 0;
    local_88 = 0;
    local_84 = 0;
    local_80 = 0;
    local_a0 = &PTR__TType_a7b7cf48;
    piVar7[1] = (int)psVar9;
    *piVar7 = (int)puVar12;
    piVar7[4] = 0;
    piVar7[5] = 0;
    piVar7[6] = 0;
    piVar7[7] = 0;
    piVar7[8] = 0;
    piVar7[9] = 0;
    piVar7[10] = 0;
    piVar7[3] = (int)&PTR__TType_a7b7cf48;
    piVar7[0xb] = 0;
    uVar3 = piVar7[0xc];
    piVar7[0xc] = uVar3 & 0x1ffffff | 0x1e000000;
    uVar4 = (local_7c >> 0x13 & 0x3f) << 0x13;
    piVar7[0xc] = uVar4 | uVar3 & 0x7ffff | 0x1e000000;
    piVar7[0xc] = uVar4 | uVar3 & 0x7ff | 0x1e000000 | 0x2000;
    piVar7[0xc] = uVar4 | uVar3 & 0x3ff | 0x1e000000 | 0x2000;
    piVar7[0xc] = uVar4 | uVar3 & 0x1ff | 0x1e000000 | 0x2000;
    piVar7[0xd] = 0;
    piVar7[0xe] = 0;
    piVar7[0xf] = 0;
    iVar5 = param_2[3];
    param_2[3] = iVar5 + 1;
    piVar7[2] = iVar5 + 1;
    local_6c = 0;
    psVar9 = (unsigned char *)(**(code **)(*piVar7 + 8))(piVar7);
    std__string__string((unsigned char *)&local_50,psVar9);
    local_48 = piVar7;
    std::
    _Rb_tree<std::string,std::pair<std::string_const,TSymbol*>,std::_Select1st<std::pair<std::string_const,TSymbol*>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,TSymbol*>>>
    ::insert_unique((unsigned char *)&local_60);
    local_70 = local_60;
    piVar7 = (int *)(local_4c + -4);
    local_6c = local_5c;
    local_40 = local_50;
    do {
      iVar5 = *piVar7;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar5 + -1,0,piVar7);
        *piVar7 = iVar1;
        bVar13 = 2;
      }
    } while (!(bool)(bVar13 >> 1 & 1));
    if (iVar5 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_4c + -0xc));
    }
    local_a0 = &PTR__TType_a7b7cf48;
  }
  else if (param_1 == 1) {
    uVar6 = GetGlobalPoolAllocator();
    piVar7 = (int *)TPoolAllocator__allocate(uVar6);
    pcVar2 = _strSpecialBuiltIn;
    uVar6 = GetGlobalPoolAllocator();
    psVar8 = (unsigned char *)TPoolAllocator__allocate(uVar6);
    bVar13 = (psVar8 == (unsigned char *)0x0) << 1;
    psVar9 = (unsigned char *)0x0;
    if (psVar8 != (unsigned char *)0x0) {
      local_3b0[0] = GetGlobalPoolAllocator();
      std__string__string(psVar8,pcVar2,(unsigned char *)local_3b0);
      psVar9 = psVar8;
    }
    puVar12 = PTR_vtable_a7b7c0b4 + 8;
    local_37c = local_37c & 0x1801ff | 0x20180800;
    local_39c = 0;
    local_398 = 0;
    local_394 = 0;
    local_390 = 0;
    local_38c = 0;
    local_388 = 0;
    local_384 = 0;
    local_380 = 0;
    local_3a0 = &PTR__TType_a7b7cf48;
    piVar7[1] = (int)psVar9;
    *piVar7 = (int)puVar12;
    piVar7[4] = 0;
    piVar7[5] = 0;
    piVar7[6] = 0;
    piVar7[7] = 0;
    piVar7[8] = 0;
    piVar7[9] = 0;
    piVar7[10] = 0;
    piVar7[3] = (int)&PTR__TType_a7b7cf48;
    piVar7[0xb] = 0;
    uVar3 = piVar7[0xc];
    piVar7[0xc] = uVar3 & 0x1ffffff | 0x20000000;
    uVar4 = (local_37c >> 0x13 & 0x3f) << 0x13;
    piVar7[0xc] = uVar4 | uVar3 & 0x7ffff | 0x20000000;
    piVar7[0xc] = uVar4 | uVar3 & 0x7ff | 0x20000000 | 0x800;
    piVar7[0xc] = uVar4 | uVar3 & 0x3ff | 0x20000000 | 0x800;
    piVar7[0xc] = uVar4 | uVar3 & 0x1ff | 0x20000000 | 0x800;
    piVar7[0xd] = 0;
    piVar7[0xe] = 0;
    piVar7[0xf] = 0;
    iVar5 = param_2[3];
    param_2[3] = iVar5 + 1;
    piVar7[2] = iVar5 + 1;
    local_36c = 0;
    psVar9 = (unsigned char *)(**(code **)(*piVar7 + 8))(piVar7);
    std__string__string((unsigned char *)&local_350,psVar9);
    local_348 = piVar7;
    std::
    _Rb_tree<std::string,std::pair<std::string_const,TSymbol*>,std::_Select1st<std::pair<std::string_const,TSymbol*>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,TSymbol*>>>
    ::insert_unique((unsigned char *)&local_360);
    local_370 = local_360;
    piVar7 = (int *)(local_34c + -4);
    local_36c = local_35c;
    local_340 = local_350;
    do {
      iVar5 = *piVar7;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar5 + -1,0,piVar7);
        *piVar7 = iVar1;
        bVar13 = 2;
      }
    } while (!(bool)(bVar13 >> 1 & 1));
    if (iVar5 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_34c + -0xc));
    }
    local_3a0 = &PTR__TType_a7b7cf48;
    uVar6 = GetGlobalPoolAllocator();
    piVar7 = (int *)TPoolAllocator__allocate(uVar6);
    pcVar2 = DAT_a7b7b6f8;
    uVar6 = GetGlobalPoolAllocator();
    psVar8 = (unsigned char *)TPoolAllocator__allocate(uVar6);
    bVar13 = (psVar8 == (unsigned char *)0x0) << 1;
    psVar9 = (unsigned char *)0x0;
    if (psVar8 != (unsigned char *)0x0) {
      local_330[0] = GetGlobalPoolAllocator();
      std__string__string(psVar8,pcVar2,(unsigned char *)local_330);
      psVar9 = psVar8;
    }
    puVar12 = PTR_vtable_a7b7c0b4 + 8;
    local_2fc = local_2fc & 0x801ff | 0x22082000;
    local_31c = 0;
    local_318 = 0;
    local_314 = 0;
    local_310 = 0;
    local_30c = 0;
    local_308 = 0;
    local_304 = 0;
    local_300 = 0;
    local_320 = &PTR__TType_a7b7cf48;
    piVar7[1] = (int)psVar9;
    *piVar7 = (int)puVar12;
    piVar7[4] = 0;
    piVar7[5] = 0;
    piVar7[6] = 0;
    piVar7[7] = 0;
    piVar7[8] = 0;
    piVar7[9] = 0;
    piVar7[10] = 0;
    piVar7[3] = (int)&PTR__TType_a7b7cf48;
    piVar7[0xb] = 0;
    uVar3 = piVar7[0xc];
    piVar7[0xc] = uVar3 & 0x1ffffff | 0x22000000;
    uVar4 = (local_2fc >> 0x13 & 0x3f) << 0x13;
    piVar7[0xc] = uVar4 | uVar3 & 0x7ffff | 0x22000000;
    piVar7[0xc] = uVar4 | uVar3 & 0x7ff | 0x22000000 | 0x2000;
    piVar7[0xc] = uVar4 | uVar3 & 0x3ff | 0x22000000 | 0x2000;
    piVar7[0xc] = uVar4 | uVar3 & 0x1ff | 0x22000000 | 0x2000;
    piVar7[0xd] = 0;
    piVar7[0xe] = 0;
    piVar7[0xf] = 0;
    iVar5 = param_2[3];
    param_2[3] = iVar5 + 1;
    piVar7[2] = iVar5 + 1;
    local_2ec = 0;
    psVar9 = (unsigned char *)(**(code **)(*piVar7 + 8))(piVar7);
    std__string__string((unsigned char *)&local_2d0,psVar9);
    local_2c8 = piVar7;
    std::
    _Rb_tree<std::string,std::pair<std::string_const,TSymbol*>,std::_Select1st<std::pair<std::string_const,TSymbol*>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,TSymbol*>>>
    ::insert_unique((unsigned char *)&local_2e0);
    local_2f0 = local_2e0;
    piVar7 = (int *)(local_2cc + -4);
    local_2ec = local_2dc;
    local_2c0 = local_2d0;
    do {
      iVar5 = *piVar7;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar5 + -1,0,piVar7);
        *piVar7 = iVar1;
        bVar13 = 2;
      }
    } while (!(bool)(bVar13 >> 1 & 1));
    if (iVar5 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_2cc + -0xc));
    }
    local_320 = &PTR__TType_a7b7cf48;
    uVar6 = GetGlobalPoolAllocator();
    piVar7 = (int *)TPoolAllocator__allocate(uVar6);
    pcVar2 = DAT_a7b7b6fc;
    uVar6 = GetGlobalPoolAllocator();
    psVar8 = (unsigned char *)TPoolAllocator__allocate(uVar6);
    bVar13 = (psVar8 == (unsigned char *)0x0) << 1;
    psVar9 = (unsigned char *)0x0;
    if (psVar8 != (unsigned char *)0x0) {
      local_2b0[0] = GetGlobalPoolAllocator();
      std__string__string(psVar8,pcVar2,(unsigned char *)local_2b0);
      psVar9 = psVar8;
    }
    puVar12 = PTR_vtable_a7b7c0b4 + 8;
    local_27c = local_27c & 0x801ff | 0x24082000;
    local_29c = 0;
    local_298 = 0;
    local_294 = 0;
    local_290 = 0;
    local_28c = 0;
    local_288 = 0;
    local_284 = 0;
    local_280 = 0;
    local_2a0 = &PTR__TType_a7b7cf48;
    piVar7[1] = (int)psVar9;
    *piVar7 = (int)puVar12;
    piVar7[4] = 0;
    piVar7[5] = 0;
    piVar7[6] = 0;
    piVar7[7] = 0;
    piVar7[8] = 0;
    piVar7[9] = 0;
    piVar7[10] = 0;
    piVar7[3] = (int)&PTR__TType_a7b7cf48;
    piVar7[0xb] = 0;
    uVar3 = piVar7[0xc];
    piVar7[0xc] = uVar3 & 0x1ffffff | 0x24000000;
    uVar4 = (local_27c >> 0x13 & 0x3f) << 0x13;
    piVar7[0xc] = uVar4 | uVar3 & 0x7ffff | 0x24000000;
    piVar7[0xc] = uVar4 | uVar3 & 0x7ff | 0x24000000 | 0x2000;
    piVar7[0xc] = uVar4 | uVar3 & 0x3ff | 0x24000000 | 0x2000;
    piVar7[0xc] = uVar4 | uVar3 & 0x1ff | 0x24000000 | 0x2000;
    piVar7[0xd] = 0;
    piVar7[0xe] = 0;
    piVar7[0xf] = 0;
    iVar5 = param_2[3];
    param_2[3] = iVar5 + 1;
    piVar7[2] = iVar5 + 1;
    local_26c = 0;
    psVar9 = (unsigned char *)(**(code **)(*piVar7 + 8))(piVar7);
    std__string__string((unsigned char *)&local_250,psVar9);
    local_248 = piVar7;
    std::
    _Rb_tree<std::string,std::pair<std::string_const,TSymbol*>,std::_Select1st<std::pair<std::string_const,TSymbol*>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,TSymbol*>>>
    ::insert_unique((unsigned char *)&local_260);
    local_270 = local_260;
    piVar7 = (int *)(local_24c + -4);
    local_26c = local_25c;
    local_240 = local_250;
    do {
      iVar5 = *piVar7;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar5 + -1,0,piVar7);
        *piVar7 = iVar1;
        bVar13 = 2;
      }
    } while (!(bool)(bVar13 >> 1 & 1));
    if (iVar5 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_24c + -0xc));
    }
    local_2a0 = &PTR__TType_a7b7cf48;
    uVar6 = GetGlobalPoolAllocator();
    piVar7 = (int *)TPoolAllocator__allocate(uVar6);
    pcVar2 = DAT_a7b7b700;
    uVar6 = GetGlobalPoolAllocator();
    psVar8 = (unsigned char *)TPoolAllocator__allocate(uVar6);
    bVar13 = (psVar8 == (unsigned char *)0x0) << 1;
    psVar9 = (unsigned char *)0x0;
    if (psVar8 != (unsigned char *)0x0) {
      local_230[0] = GetGlobalPoolAllocator();
      std__string__string(psVar8,pcVar2,(unsigned char *)local_230);
      psVar9 = psVar8;
    }
    puVar12 = PTR_vtable_a7b7c0b4 + 8;
    local_1fc = local_1fc & 0x1ff | 0x26080800;
    local_21c = 0;
    local_218 = 0;
    local_214 = 0;
    local_210 = 0;
    local_20c = 0;
    local_208 = 0;
    local_204 = 0;
    local_200 = 0;
    local_220 = &PTR__TType_a7b7cf48;
    piVar7[1] = (int)psVar9;
    *piVar7 = (int)puVar12;
    piVar7[4] = 0;
    piVar7[5] = 0;
    piVar7[6] = 0;
    piVar7[7] = 0;
    piVar7[8] = 0;
    piVar7[9] = 0;
    piVar7[10] = 0;
    piVar7[3] = (int)&PTR__TType_a7b7cf48;
    piVar7[0xb] = 0;
    uVar4 = piVar7[0xc];
    piVar7[0xc] = uVar4 & 0x1ffffff | 0x26000000;
    piVar7[0xc] = uVar4 & 0x7ffff | 0x26080000;
    piVar7[0xc] = uVar4 & 0x7ff | 0x26080800;
    piVar7[0xc] = uVar4 & 0x3ff | 0x26080800;
    piVar7[0xc] = uVar4 & 0x1ff | 0x26080800;
    piVar7[0xd] = 0;
    piVar7[0xe] = 0;
    piVar7[0xf] = 0;
    iVar5 = param_2[3];
    param_2[3] = iVar5 + 1;
    piVar7[2] = iVar5 + 1;
    local_1ec = 0;
    psVar9 = (unsigned char *)(**(code **)(*piVar7 + 8))(piVar7);
    std__string__string((unsigned char *)&local_1d0,psVar9);
    local_1c8 = piVar7;
    std::
    _Rb_tree<std::string,std::pair<std::string_const,TSymbol*>,std::_Select1st<std::pair<std::string_const,TSymbol*>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,TSymbol*>>>
    ::insert_unique((unsigned char *)&local_1e0);
    local_1f0 = local_1e0;
    piVar7 = (int *)(local_1cc + -4);
    local_1ec = local_1dc;
    local_1c0 = local_1d0;
    do {
      iVar5 = *piVar7;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar5 + -1,0,piVar7);
        *piVar7 = iVar1;
        bVar13 = 2;
      }
    } while (!(bool)(bVar13 >> 1 & 1));
    if (iVar5 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_1cc + -0xc));
    }
    local_220 = &PTR__TType_a7b7cf48;
  }
  puVar12 = PTR__operatorStrings_a7b7c0b0;
  TSymbolTableLevel__relateToOperator
            (*(undefined4 *)*param_2,*(undefined4 *)(PTR__operatorStrings_a7b7c0b0 + 0x1c),7);
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x54),0x15);
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x5c),0x17);
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x7c),0x1f);
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x80),0x20);
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x84),0x21);
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x88),0x22);
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x8c),0x23);
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x90),0x24);
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0xc4),0x31);
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 200),0x32);
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0xcc),0x33);
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0xd0),0x34);
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0xd4),0x35);
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0xd8),0x36);
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0xdc),0x37);
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0xe0),0x38);
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0xe4),0x39);
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0xf0),0x3c);
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0xec),0x3b);
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0xe8),0x3a);
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0xf4),0x3d);
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0xf8),0x3e);
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0xfc),0x3f);
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x100),0x40)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x104),0x41)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x108),0x42)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x10c),0x43)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x110),0x44)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x114),0x45)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x118),0x46)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x11c),0x47)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x120),0x48)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x124),0x49)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x128),0x4a)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 300),0x4b);
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x130),0x4c)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x134),0x4d)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x138),0x4e)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x13c),0x4f)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x140),0x50)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x144),0x51)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x148),0x52)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x15c),0x57)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x160),0x58)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x218),0x86)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x21c),0x87)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x220),0x88)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x224),0x89)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x228),0x8a)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x22c),0x8b)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x230),0x8c)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x234),0x8d)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x238),0x8e)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x23c),0x8f)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x240),0x90)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x244),0x91)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x248),0x92)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x24c),0x93)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x250),0x94)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x254),0x95)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 600),0x96);
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x25c),0x97)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x260),0x98)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x264),0x99)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x268),0x9a)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x26c),0x9b)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x270),0x9c)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x274),0x9d)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x278),0x9e)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x27c),0x9f)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x280),0xa0)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x284),0xa1)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x288),0xa2)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x28c),0xa3)
  ;
  if (param_1 == 0) {
    param_2 = (undefined4 *)*param_2;
    uVar11 = 0x85;
    uVar10 = *(undefined4 *)(puVar12 + 0x214);
  }
  else {
    if (param_1 != 1) {
      return;
    }
    TSymbolTableLevel__relateToOperator
              (*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x14c),0x53);
    TSymbolTableLevel__relateToOperator
              (*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x150),0x54);
    param_2 = (undefined4 *)*param_2;
    uVar10 = *(undefined4 *)(puVar12 + 0x154);
    uVar11 = 0x55;
  }
  TSymbolTableLevel__relateToOperator(*param_2,uVar10,uVar11);
  return;
}

/* IdentifyBuiltIns_97b8c5c0 @ 0x97b8c5c0 (600 bytes) */
void IdentifyBuiltIns_97b8c5c0_97b8c5c0(int param_1,int param_2,int param_3)

{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  ulong uVar4;
  int *piVar5;
  string *this;
  string *psVar6;
  int iVar7;
  char in_RESERVE;
  byte bVar8;
  undefined4 local_70 [4];
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_40;
  int local_3c;
  int *local_38;
  undefined4 local_30;
  
  if (param_1 == 1) {
    iVar7 = *(int *)(param_3 + 0x2c);
    uVar4 = GetGlobalPoolAllocator();
    piVar5 = (int *)TPoolAllocator__allocate(uVar4);
    pcVar2 = DAT_a7b7b704;
    uVar4 = GetGlobalPoolAllocator();
    this = (unsigned char *)TPoolAllocator__allocate(uVar4);
    bVar8 = (this == (unsigned char *)0x0) << 1;
    psVar6 = (unsigned char *)0x0;
    if (this != (unsigned char *)0x0) {
      local_70[0] = GetGlobalPoolAllocator();
      std__string__string(this,pcVar2,(unsigned char *)local_70);
      psVar6 = this;
    }
    piVar5[1] = (int)psVar6;
    *piVar5 = (int)(PTR_vtable_a7b7c0b4 + 8);
    piVar5[4] = iVar7;
    piVar5[5] = 0;
    piVar5[6] = 0;
    piVar5[7] = 0;
    piVar5[8] = 0;
    piVar5[9] = 0;
    piVar5[3] = (int)&PTR__TType_a7b7cf48;
    piVar5[10] = 0;
    piVar5[0xb] = 0;
    uVar3 = piVar5[0xc];
    piVar5[0xc] = uVar3 & 0x1ffffff | 0x24000000;
    piVar5[0xc] = uVar3 & 0x7ffff | 0x24080000;
    piVar5[0xc] = uVar3 & 0x7ff | 0x24082000;
    piVar5[0xc] = uVar3 & 0x3ff | 0x24082000;
    piVar5[0xc] = uVar3 & 0x1ff | 0x24082200;
    piVar5[0xd] = 0;
    piVar5[0xe] = 0;
    piVar5[0xf] = 0;
    iVar7 = *(int *)(param_2 + 0xc) + 1;
    *(int *)(param_2 + 0xc) = iVar7;
    piVar5[2] = iVar7;
    local_5c = 0;
    psVar6 = (unsigned char *)(**(code **)(*piVar5 + 8))(piVar5);
    std__string__string((unsigned char *)&local_40,psVar6);
    local_38 = piVar5;
    std::
    _Rb_tree<std::string,std::pair<std::string_const,TSymbol*>,std::_Select1st<std::pair<std::string_const,TSymbol*>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,TSymbol*>>>
    ::insert_unique((unsigned char *)&local_50);
    local_60 = local_50;
    piVar5 = (int *)(local_3c + -4);
    local_5c = local_4c;
    local_30 = local_40;
    do {
      iVar7 = *piVar5;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar7 + -1,0,piVar5);
        *piVar5 = iVar1;
        bVar8 = 2;
      }
    } while (!(bool)(bVar8 >> 1 & 1));
    if (iVar7 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_3c + -0xc));
    }
  }
  return;
}

/* GetPreprocessorBuiltinString @ 0x97b8c818 (28 bytes) */
int GetPreprocessorBuiltinString()
{
  return ((int (*)())GetPreprocessorBuiltinString)()::PreprocessorBuiltinString;
}

/* TInfoSinkBase__append @ 0x97b8c834 (196 bytes) */
int TInfoSinkBase__append(this, param_1)
  unsigned char *this;
  char *param_1;
{
  uint uVar1;
  size_t sVar2;
  
  uVar1 = *(uint *)(this + 4);
  if ((uVar1 & 4) != 0) {
    sVar2 = _strlen(param_1);
    if (*(uint *)(*(int *)this + -8) < *(int *)(*(int *)this + -0xc) + sVar2 + 2) {
      std__string__reserve((ulong)this);
    }
    _strlen(param_1);
    std__string__append((char *)this,(ulong)param_1);
    uVar1 = *(uint *)(this + 4);
  }
  if ((uVar1 & 2) != 0) {
    _fprintf((FILE *)(PTR_DAT_a7b7c0bc + 0x58),"%s",param_1);
    return;
  }
  return;
}

/* TInfoSinkBase__append_97b8c8f8 @ 0x97b8c8f8 (180 bytes) */
int TInfoSinkBase__append_97b8c8f8(this, param_1, param_2)
  unsigned char *this;
  int param_1;
  int param_2;
{
  uint uVar1;
  undefined3 in_register_00000014;
  
  uVar1 = *(uint *)(this + 4);
  if ((uVar1 & 4) != 0) {
    if (*(uint *)(*(int *)this + -8) < *(int *)(*(int *)this + -0xc) + param_1 + 2U) {
      std__string__reserve((ulong)this);
    }
    std__string__append((ulong)this,(char)param_1);
    uVar1 = *(uint *)(this + 4);
  }
  if ((uVar1 & 2) != 0) {
    _fprintf((FILE *)(PTR_DAT_a7b7c0bc + 0x58),"%c",CONCAT31(in_register_00000014,param_2));
    return;
  }
  return;
}

/* TInfoSinkBase__append_97b8c9ac @ 0x97b8c9ac (204 bytes) */
int TInfoSinkBase__append_97b8c9ac(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  undefined *puVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(this + 4);
  if ((uVar2 & 4) != 0) {
    if (*(uint *)(*(int *)this + -8) <
        *(int *)(*(int *)this + -0xc) + *(int *)(*(int *)param_1 + -0xc) + 2U) {
      std__string__reserve((ulong)this);
    }
    std__string__append((unsigned char *)this);
    uVar2 = *(uint *)(this + 4);
  }
  puVar1 = PTR_DAT_a7b7c0bc;
  if ((uVar2 & 2) != 0) {
    *(undefined *)(*(int *)param_1 + *(int *)(*(int *)param_1 + -0xc)) = *PTR__S_terminal_a7b7c0b8;
    _fprintf((FILE *)(puVar1 + 0x58),"%s",*(undefined4 *)param_1);
    return;
  }
  return;
}

/* TInfoSinkBase__append_97b8ca78 @ 0x97b8ca78 (244 bytes) */
int TInfoSinkBase__append_97b8ca78(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  
  uVar2 = *(uint *)(this + 4);
  if ((uVar2 & 4) != 0) {
    iVar3 = *(int *)(param_1 + 4);
    if (*(uint *)(*(int *)this + -8) < *(int *)(*(int *)this + -0xc) + *(int *)(iVar3 + -0xc) + 2U)
    {
      std__string__reserve((ulong)this);
      iVar3 = *(int *)(param_1 + 4);
    }
    *(undefined1 *)(iVar3 + *(int *)(iVar3 + -0xc)) = *DAT_a7b7b720;
    pcVar4 = *(char **)(param_1 + 4);
    _strlen(pcVar4);
    std__string__append((char *)this,(ulong)pcVar4);
    uVar2 = *(uint *)(this + 4);
  }
  puVar1 = PTR_DAT_a7b7c0bc;
  if ((uVar2 & 2) != 0) {
    *(undefined1 *)(*(int *)(param_1 + 4) + *(int *)(*(int *)(param_1 + 4) + -0xc)) = *DAT_a7b7b720;
    _fprintf((FILE *)(puVar1 + 0x58),"%s",*(undefined4 *)(param_1 + 4));
    return;
  }
  return;
}

/* TIntermediate__addSymbol @ 0x97b8cb6c (376 bytes) */
int TIntermediate__addSymbol(this, param_1, param_2, param_3, param_4)
  unsigned char *this;
  int param_1;
  unsigned char *param_2;
  unsigned char *param_3;
  int param_4;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined *puVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  ulong uVar9;
  int *piVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  char in_RESERVE;
  byte in_cr0;
  
  uVar9 = GetGlobalPoolAllocator();
  piVar10 = (int *)TPoolAllocator__allocate(uVar9);
  piVar10[1] = 0;
  *piVar10 = (int)&PTR_getLine_a7b7cf90;
  iVar6 = *(int *)(param_3 + 4);
  iVar17 = *(int *)(param_3 + 8);
  iVar16 = *(int *)(param_3 + 0xc);
  iVar15 = *(int *)(param_3 + 0x10);
  iVar14 = *(int *)(param_3 + 0x14);
  iVar13 = *(int *)(param_3 + 0x18);
  iVar12 = *(int *)(param_3 + 0x1c);
  iVar11 = *(int *)(param_3 + 0x20);
  piVar10[2] = (int)&PTR__TType_a7b7cff8;
  piVar10[3] = iVar6;
  piVar10[4] = iVar17;
  piVar10[5] = iVar16;
  piVar10[6] = iVar15;
  piVar10[7] = iVar14;
  piVar10[8] = iVar13;
  piVar10[9] = iVar12;
  piVar10[10] = iVar11;
  uVar7 = piVar10[0xb];
  uVar2 = *(uint *)(param_3 + 0x24) & 0xfe000000;
  piVar10[0xb] = uVar2 | uVar7 & 0x1ffffff;
  uVar3 = (*(uint *)(param_3 + 0x24) >> 0x13 & 0x3f) << 0x13;
  piVar10[0xb] = uVar3 | uVar2 | uVar7 & 0x7ffff;
  uVar1 = *(uint *)(param_3 + 0x24) & 0x7f800;
  piVar10[0xb] = uVar1 | uVar3 | uVar2 | uVar7 & 0x7ff;
  uVar4 = (*(uint *)(param_3 + 0x24) >> 10 & 1) << 10;
  piVar10[0xb] = uVar4 | uVar1 | uVar3 | uVar2 | uVar7 & 0x3ff;
  puVar5 = PTR_vtable_a7b7c0dc;
  iVar6 = DAT_a7b7b9b8;
  piVar10[0xb] = (*(uint *)(param_3 + 0x24) >> 9 & 1) << 9 |
                 uVar4 | uVar1 | uVar3 | uVar2 | uVar7 & 0x1ff;
  piVar8 = (int *)(iVar6 + 8);
  *piVar10 = (int)(puVar5 + 8);
  piVar10[0xc] = param_1;
  do {
    if (in_RESERVE != '\0') {
      iVar11 = storeWordConditionalIndexed(*piVar8 + 1,0,piVar8);
      *piVar8 = iVar11;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  iVar11 = GetGlobalPoolAllocator();
  piVar10[0xd] = iVar11;
  piVar10[0xe] = iVar6 + 0xc;
  std__string__assign((unsigned char *)(piVar10 + 0xd));
  (**(code **)(*piVar10 + 4))(piVar10,param_4);
  return piVar10;
}

/* TIntermediate__addBinaryMath @ 0x97b8cce4 (2288 bytes) */
int TIntermediate__addBinaryMath(this, param_2, param_3, param_4, param_5, param_6)
  unsigned char *this;
  int param_2;
  int *param_3;
  int *param_4;
  int param_5;
  unsigned char *param_6;
{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  undefined *puVar5;
  uint uVar6;
  int *piVar7;
  ulong uVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  TIntermConstantUnion *pTVar12;
  int *piVar13;
  TIntermConstantUnion *pTVar14;
  TIntermAggregate *pTVar15;
  TIntermConstantUnion *pTVar16;
  TIntermConstantUnion *pTVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  code *pcVar20;
  undefined **local_120;
  undefined4 local_11c;
  int local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  uint local_fc;
  undefined **local_f0 [2];
  int local_e8;
  uint local_cc;
  undefined **local_c0 [2];
  int local_b8;
  uint local_9c;
  undefined **local_90 [2];
  int local_88;
  uint local_6c;
  undefined **local_60 [9];
  uint local_3c;
  
  switch(param_2) {
  case 0x13:
  case 0x14:
  case 0x15:
  case 0x16:
    bVar4 = false;
    (**(code **)(*param_3 + 0x38))(&local_120,param_3);
    bVar1 = false;
    if ((local_fc >> 0x13 & 0x3f) == 0xe) {
LAB_97b8cff8:
      bVar4 = true;
      if (bVar1) goto LAB_97b8d008;
    }
    else {
      (**(code **)(*param_3 + 0x38))(local_f0,param_3);
      bVar1 = true;
      if ((local_cc >> 0x13 & 0x3f) == 3) goto LAB_97b8cff8;
LAB_97b8d008:
      local_f0[0] = &PTR__TType_a7b7cff8;
    }
    goto LAB_97b8d01c;
  case 0x17:
  case 0x18:
  case 0x19:
  case 0x1a:
  case 0x1b:
  case 0x1c:
  case 0x1d:
  case 0x1e:
  case 0x1f:
  case 0x20:
  case 0x25:
  case 0x26:
  case 0x27:
  case 0x28:
  case 0x29:
    break;
  case 0x21:
  case 0x22:
  case 0x23:
  case 0x24:
    bVar4 = false;
    bVar3 = false;
    bVar2 = false;
    (**(code **)(*param_3 + 0x38))(&local_120,param_3);
    bVar1 = false;
    if ((local_fc & 0x400) == 0) {
      bVar3 = true;
      (**(code **)(*param_3 + 0x38))(local_f0,param_3);
      if ((local_cc & 0x200) != 0) goto LAB_97b8ce68;
      bVar2 = true;
      (**(code **)(*param_3 + 0x38))(local_c0,param_3);
      if ((1 < (int)(local_9c << 0xd | local_9c >> 0x13) >> 0x18) && ((local_9c & 0x400) == 0))
      goto LAB_97b8ce68;
      bVar1 = true;
      (**(code **)(*param_3 + 0x38))(local_90,param_3);
      if ((local_6c >> 0x13 & 0x3f) == 0xe) goto LAB_97b8ce68;
    }
    else {
LAB_97b8ce68:
      bVar4 = true;
      if (!bVar1) goto LAB_97b8cf6c;
    }
    local_90[0] = &PTR__TType_a7b7cff8;
    goto LAB_97b8cf6c;
  case 0x2a:
  case 0x2b:
  case 0x2c:
    bVar4 = false;
    bVar3 = false;
    bVar2 = false;
    (**(code **)(*param_3 + 0x38))(&local_120,param_3);
    bVar1 = false;
    if ((local_fc >> 0x13 & 0x3f) == 3) {
      bVar3 = true;
      (**(code **)(*param_3 + 0x38))(local_f0,param_3);
      if ((local_cc & 0x400) != 0) goto LAB_97b8cf4c;
      bVar2 = true;
      (**(code **)(*param_3 + 0x38))(local_c0,param_3);
      if ((local_9c & 0x200) != 0) goto LAB_97b8cf4c;
      bVar1 = true;
      (**(code **)(*param_3 + 0x38))(local_60,param_3);
      if ((1 < (int)(local_3c << 0xd | local_3c >> 0x13) >> 0x18) && ((local_3c & 0x400) == 0))
      goto LAB_97b8cf4c;
LAB_97b8cf5c:
      local_60[0] = &PTR__TType_a7b7cff8;
    }
    else {
LAB_97b8cf4c:
      bVar4 = true;
      if (bVar1) goto LAB_97b8cf5c;
    }
LAB_97b8cf6c:
    if (bVar2) {
      local_c0[0] = &PTR__TType_a7b7cff8;
    }
    if (bVar3) {
      local_f0[0] = &PTR__TType_a7b7cff8;
    }
LAB_97b8d01c:
    local_120 = &PTR__TType_a7b7cff8;
    if (bVar4) {
      return (int *)0x0;
    }
  }
  bVar2 = false;
  (**(code **)(*param_3 + 0x38))(&local_120,param_3);
  bVar1 = false;
  if (local_118 == 0) {
LAB_97b8d08c:
    bVar2 = true;
    if (bVar1) goto LAB_97b8d098;
  }
  else {
    (**(code **)(*param_4 + 0x38))(local_f0,param_4);
    bVar1 = true;
    if (local_e8 == 0) goto LAB_97b8d08c;
LAB_97b8d098:
    local_f0[0] = &PTR__TType_a7b7cff8;
  }
  local_120 = &PTR__TType_a7b7cff8;
  if (bVar2) {
    (**(code **)(*param_3 + 0x38))(local_c0,param_3);
    piVar7 = (int *)((int (*)())TIntermediate__addConversion)(this,param_2,local_c0,param_4);
    local_c0[0] = &PTR__TType_a7b7cff8;
    if (piVar7 == (int *)0x0) {
      (**(code **)(*param_4 + 0x38))(local_c0,param_4);
      param_3 = (int *)((int (*)())TIntermediate__addConversion)(this,param_2,local_c0,param_3);
      piVar7 = param_4;
      if (param_3 == (int *)0x0) {
        return (int *)0x0;
      }
    }
  }
  else {
    (**(code **)(*param_3 + 0x38))(local_c0,param_3);
    (**(code **)(*param_4 + 0x38))(local_90,param_4);
    bVar1 = false;
    if (((local_9c & 0x1fffe00) == (local_6c & 0x1fffe00)) && (local_b8 == local_88)) {
      bVar1 = true;
    }
    local_90[0] = &PTR__TType_a7b7cff8;
    piVar7 = param_4;
    if (!bVar1) {
      return (int *)0x0;
    }
  }
  local_c0[0] = &PTR__TType_a7b7cff8;
  uVar8 = GetGlobalPoolAllocator();
  piVar9 = (int *)TPoolAllocator__allocate(uVar8);
  local_fc = local_fc & 0x1ff | 0x80800;
  local_11c = 0;
  local_114 = 0;
  local_110 = 0;
  local_10c = 0;
  local_108 = 0;
  local_104 = 0;
  local_100 = 0;
  local_118 = 0;
  piVar9[1] = 0;
  *piVar9 = (int)&PTR_getLine_a7b7cf90;
  piVar9[3] = 0;
  piVar9[4] = 0;
  piVar9[5] = 0;
  piVar9[6] = 0;
  piVar9[7] = 0;
  piVar9[8] = 0;
  piVar9[2] = (int)&PTR__TType_a7b7cff8;
  piVar9[9] = 0;
  piVar9[10] = 0;
  uVar6 = piVar9[0xb];
  piVar9[0xb] = uVar6 & 0x1ffffff;
  piVar9[0xb] = uVar6 & 0x7ffff | 0x80000;
  piVar9[0xb] = uVar6 & 0x7ff | 0x80800;
  piVar9[0xb] = uVar6 & 0x3ff | 0x80800;
  puVar5 = PTR_vtable_a7b7c0d8;
  piVar9[0xb] = uVar6 & 0x1ff | 0x80800;
  local_120 = &PTR__TType_a7b7cff8;
  piVar9[0xc] = param_2;
  *piVar9 = (int)(puVar5 + 8);
  if (param_5 == 0) {
    param_5 = (**(code **)*piVar7)(piVar7);
  }
  (**(code **)(*piVar9 + 4))(piVar9,param_5);
  (**(code **)(*piVar9 + 0x60))(piVar9,param_3);
  (**(code **)(*piVar9 + 100))(piVar9,piVar7);
  iVar10 = (**(code **)(*piVar9 + 0x5c))(piVar9,*(undefined4 *)this);
  if (iVar10 == 0) {
    return (int *)0x0;
  }
  iVar10 = (**(code **)(*param_3 + 0x18))(param_3);
  iVar11 = (**(code **)(*piVar7 + 0x18))(piVar7);
  pTVar12 = (unsigned char *)0x0;
  if (iVar10 != 0) {
    pTVar12 = (unsigned char *)(**(code **)(*param_3 + 0x18))(param_3);
    piVar13 = (int *)((int (*)())TIntermediate__copyConstUnion)(this,pTVar12);
    pTVar12 = (unsigned char *)(**(code **)(*piVar13 + 0x18))();
  }
  pTVar14 = (unsigned char *)0x0;
  if (iVar11 != 0) {
    pTVar14 = (unsigned char *)(**(code **)(*piVar7 + 0x18))(piVar7);
    piVar13 = (int *)((int (*)())TIntermediate__copyConstUnion)(this,pTVar14);
    pTVar14 = (unsigned char *)(**(code **)(*piVar13 + 0x18))();
  }
  bVar1 = false;
  (**(code **)(*piVar7 + 0x38))(&local_120,piVar7);
  if (local_fc >> 0x19 == 2) {
    (**(code **)(*param_3 + 0x38))(local_f0,param_3);
    bVar1 = local_cc >> 0x19 == 2;
    local_f0[0] = &PTR__TType_a7b7cff8;
  }
  local_120 = &PTR__TType_a7b7cff8;
  if (bVar1) {
    iVar10 = (**(code **)(*piVar7 + 0x1c))(piVar7);
    if (iVar10 != 0) {
      pTVar15 = (unsigned char *)(**(code **)(*piVar7 + 0x1c))(piVar7);
      pTVar14 = (unsigned char *)((int (*)())TIntermediate__changeAggrToTempConst)(this,pTVar15,param_6,param_5);
      if (*(int *)(pTVar14 + 0x30) == 0) {
        return (int *)0x0;
      }
    }
    iVar10 = (**(code **)(*param_3 + 0x1c))(param_3);
    if (iVar10 != 0) {
      pTVar15 = (unsigned char *)(**(code **)(*param_3 + 0x1c))(param_3);
      pTVar12 = (unsigned char *)((int (*)())TIntermediate__changeAggrToTempConst)(this,pTVar15,param_6,param_5);
      if (*(int *)(pTVar12 + 0x30) == 0) {
        return (int *)0x0;
      }
    }
  }
  if (pTVar12 == (unsigned char *)0x0) {
    if (pTVar14 == (unsigned char *)0x0) {
      return piVar9;
    }
  }
  else {
    if (pTVar14 == (unsigned char *)0x0) {
      iVar10 = *piVar9;
      pTVar14 = (unsigned char *)((int (*)())TIntermediate__copyConstUnion)(this,pTVar12);
      pcVar20 = *(code **)(iVar10 + 0x60);
      goto LAB_97b8d618;
    }
    iVar10 = (**(code **)(*(int *)pTVar12 + 0x4c))(pTVar12);
    if ((iVar10 == 1) && (iVar10 = (**(code **)(*(int *)pTVar14 + 0x4c))(pTVar14), 1 < iVar10)) {
      uVar18 = *(undefined4 *)this;
      pcVar20 = *(code **)(*(int *)pTVar14 + 0x5c);
      uVar19 = 0;
      pTVar16 = pTVar14;
      pTVar17 = pTVar12;
    }
    else {
      uVar18 = *(undefined4 *)this;
      pcVar20 = *(code **)(*(int *)pTVar12 + 0x5c);
      uVar19 = 1;
      pTVar16 = pTVar12;
      pTVar17 = pTVar14;
    }
    piVar7 = (int *)(*pcVar20)(pTVar16,piVar9[0xc],pTVar17,uVar18,uVar19);
    if (piVar7 != (int *)0x0) {
      return piVar7;
    }
    (**(code **)(*piVar9 + 0x60))(piVar9,pTVar12);
  }
  pcVar20 = *(code **)(*piVar9 + 100);
LAB_97b8d618:
  (*pcVar20)(piVar9,pTVar14);
  return piVar9;
}

/* TIntermediate__addAssign @ 0x97b8d63c (640 bytes) */
int TIntermediate__addAssign(this, param_2, param_3, param_4, param_5)
  unsigned char *this;
  int param_2;
  int *param_3;
  int *param_4;
  int param_5;
{
  undefined *puVar1;
  uint uVar2;
  ulong uVar3;
  int *piVar4;
  int iVar5;
  TIntermConstantUnion *pTVar6;
  int *piVar7;
  undefined **local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  uint local_2c;
  
  uVar3 = GetGlobalPoolAllocator();
  piVar4 = (int *)TPoolAllocator__allocate(uVar3);
  local_2c = local_2c & 0x1ff | 0x80800;
  local_4c = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_48 = 0;
  piVar4[1] = 0;
  *piVar4 = (int)&PTR_getLine_a7b7cf90;
  piVar4[3] = 0;
  piVar4[4] = 0;
  piVar4[5] = 0;
  piVar4[6] = 0;
  piVar4[7] = 0;
  piVar4[8] = 0;
  piVar4[2] = (int)&PTR__TType_a7b7cff8;
  piVar4[9] = 0;
  piVar4[10] = 0;
  uVar2 = piVar4[0xb];
  piVar4[0xb] = uVar2 & 0x1ffffff;
  piVar4[0xb] = uVar2 & 0x7ffff | 0x80000;
  piVar4[0xb] = uVar2 & 0x7ff | 0x80800;
  piVar4[0xb] = uVar2 & 0x3ff | 0x80800;
  puVar1 = PTR_vtable_a7b7c0d8;
  piVar4[0xb] = uVar2 & 0x1ff | 0x80800;
  local_50 = &PTR__TType_a7b7cff8;
  *piVar4 = (int)(puVar1 + 8);
  piVar4[0xc] = param_2;
  if (param_5 == 0) {
    param_5 = (**(code **)*param_3)(param_3);
  }
  (**(code **)(*piVar4 + 4))(piVar4,param_5);
  iVar5 = (**(code **)(*param_4 + 0x18))(param_4);
  if (iVar5 != 0) {
    pTVar6 = (unsigned char *)(**(code **)(*param_4 + 0x18))(param_4);
    param_4 = (int *)((int (*)())TIntermediate__copyConstUnion)(this,pTVar6);
    if (param_4 == (int *)0x0) {
      return (int *)0x0;
    }
  }
  (**(code **)(*param_3 + 0x38))(&local_50,param_3);
  iVar5 = ((int (*)())TIntermediate__addConversion)(this,param_2,&local_50,param_4);
  local_50 = &PTR__TType_a7b7cff8;
  piVar7 = (int *)0x0;
  if (iVar5 != 0) {
    (**(code **)(*piVar4 + 0x60))(piVar4,param_3);
    (**(code **)(*piVar4 + 100))(piVar4,iVar5);
    iVar5 = (**(code **)(*piVar4 + 0x5c))(piVar4,*(undefined4 *)this);
    piVar7 = (int *)0x0;
    if (iVar5 != 0) {
      piVar7 = piVar4;
    }
  }
  return piVar7;
}

/* TIntermediate__addIndex @ 0x97b8d8bc (460 bytes) */
int TIntermediate__addIndex(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  undefined4 *param_4;
  int param_5;
{
  undefined *puVar1;
  uint uVar2;
  ulong uVar3;
  int *piVar4;
  
  uVar3 = GetGlobalPoolAllocator();
  piVar4 = (int *)TPoolAllocator__allocate(uVar3);
  piVar4[1] = 0;
  *piVar4 = (int)&PTR_getLine_a7b7cf90;
  piVar4[3] = 0;
  piVar4[4] = 0;
  piVar4[5] = 0;
  piVar4[6] = 0;
  piVar4[7] = 0;
  piVar4[8] = 0;
  piVar4[2] = (int)&PTR__TType_a7b7cff8;
  piVar4[9] = 0;
  piVar4[10] = 0;
  uVar2 = piVar4[0xb];
  piVar4[0xb] = uVar2 & 0x1ffffff;
  piVar4[0xb] = uVar2 & 0x7ffff | 0x80000;
  piVar4[0xb] = uVar2 & 0x7ff | 0x80800;
  piVar4[0xb] = uVar2 & 0x3ff | 0x80800;
  puVar1 = PTR_vtable_a7b7c0d8;
  piVar4[0xb] = uVar2 & 0x1ff | 0x80800;
  piVar4[0xc] = param_2;
  *piVar4 = (int)(puVar1 + 8);
  if (param_5 == 0) {
    param_5 = (**(code **)*param_4)(param_4);
  }
  (**(code **)(*piVar4 + 4))(piVar4,param_5);
  (**(code **)(*piVar4 + 0x60))(piVar4,param_3);
  (**(code **)(*piVar4 + 100))(piVar4,param_4);
  return piVar4;
}

/* TIntermediate__addUnaryMath @ 0x97b8da88 (1548 bytes) */
int TIntermediate__addUnaryMath(this, param_2, param_3, param_4, param_5)
  unsigned char *this;
  int param_2;
  int *param_3;
  int param_4;
  unsigned char *param_5;
{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  undefined *puVar5;
  uint uVar6;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  TIntermConstantUnion *pTVar11;
  TIntermAggregate *pTVar12;
  int *piVar13;
  ulong uVar14;
  int *piVar15;
  undefined **local_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  uint local_fc;
  undefined **local_f0 [9];
  uint local_cc;
  undefined **local_c0 [9];
  uint local_9c;
  undefined **local_90 [9];
  uint local_6c;
  undefined **local_60 [9];
  uint local_3c;
  
  piVar7 = (int *)(**(code **)(*param_3 + 0x14))(param_3);
  if (piVar7 == (int *)0x0) {
                    
                    
    piVar7 = (int *)(*(code *)(((unsigned char *)0x97b8daf0) + (*(unsigned char *)0x97b8dafc)))();
    return piVar7;
  }
  if (param_2 == 6) {
    bVar4 = false;
    bVar3 = false;
    bVar2 = false;
    bVar1 = false;
    (**(code **)(*piVar7 + 0x38))(&local_120,piVar7);
    if ((local_fc >> 0x13 & 0x3f) == 3) {
      bVar3 = true;
      (**(code **)(*piVar7 + 0x38))(local_c0,piVar7);
      if ((local_9c & 0x400) != 0) goto LAB_97b8dcfc;
      bVar2 = true;
      (**(code **)(*piVar7 + 0x38))(local_90,piVar7);
      if ((local_6c & 0x200) != 0) goto LAB_97b8dcfc;
      bVar1 = true;
      (**(code **)(*piVar7 + 0x38))(local_60,piVar7);
      if ((1 < (int)(local_3c << 0xd | local_3c >> 0x13) >> 0x18) && ((local_3c & 0x400) == 0))
      goto LAB_97b8dcfc;
LAB_97b8dd0c:
      local_60[0] = &PTR__TType_a7b7cff8;
    }
    else {
LAB_97b8dcfc:
      bVar4 = true;
      if (bVar1) goto LAB_97b8dd0c;
    }
    if (bVar2) {
      local_90[0] = &PTR__TType_a7b7cff8;
    }
    if (bVar3) {
      local_c0[0] = &PTR__TType_a7b7cff8;
    }
LAB_97b8ddc8:
    local_120 = &PTR__TType_a7b7cff8;
    if (bVar4) {
      return (int *)0x0;
    }
  }
  else if (param_2 < 7) {
    if (param_2 == 5) {
LAB_97b8dd4c:
      bVar4 = false;
      (**(code **)(*piVar7 + 0x38))(&local_120,piVar7);
      bVar1 = false;
      if ((local_fc >> 0x13 & 0x3f) == 0xe) {
LAB_97b8dda4:
        bVar4 = true;
        if (bVar1) goto LAB_97b8ddb4;
      }
      else {
        (**(code **)(*piVar7 + 0x38))(local_f0,piVar7);
        bVar1 = true;
        if ((local_cc & 0x200) != 0) goto LAB_97b8dda4;
LAB_97b8ddb4:
        local_f0[0] = &PTR__TType_a7b7cff8;
      }
      goto LAB_97b8ddc8;
    }
  }
  else if (param_2 - 9U < 4) goto LAB_97b8dd4c;
  if (param_2 == 0x67) {
    iVar10 = 3;
  }
  else if (param_2 < 0x68) {
    if (param_2 != 0x66) goto LAB_97b8decc;
    iVar10 = 2;
  }
  else {
    if (param_2 != 0x68) goto LAB_97b8decc;
    iVar10 = 1;
  }
  uVar6 = (**(code **)(*piVar7 + 0x48))(piVar7);
  uVar8 = (**(code **)(*piVar7 + 0x50))(piVar7);
  uVar9 = (**(code **)(*piVar7 + 0x54))(piVar7);
  local_fc = (uVar9 & 1) << 9 |
             (uVar8 & 1) << 10 | (uVar6 & 0xff) << 0xb | iVar10 << 0x13 | local_fc & 0x1ff;
  local_100 = 0;
  local_120 = &PTR__TType_a7b7cff8;
  local_11c = 0;
  local_118 = 0;
  local_114 = 0;
  local_110 = 0;
  local_10c = 0;
  local_108 = 0;
  local_104 = 0;
  piVar7 = (int *)((int (*)())TIntermediate__addConversion)(this,param_2,&local_120,piVar7);
  local_120 = &PTR__TType_a7b7cff8;
  if (piVar7 == (int *)0x0) {
    return (int *)0x0;
  }
LAB_97b8decc:
  if (2 < param_2 - 0x66U) {
    iVar10 = (**(code **)(*piVar7 + 0x18))(piVar7);
    if (iVar10 != 0) {
      pTVar11 = (unsigned char *)(**(code **)(*piVar7 + 0x18))(piVar7);
      piVar7 = (int *)((int (*)())TIntermediate__copyConstUnion)(this,pTVar11);
    }
    iVar10 = (**(code **)(*piVar7 + 0x1c))(piVar7);
    if (iVar10 != 0) {
      (**(code **)(*piVar7 + 0x38))(&local_120,piVar7);
      local_120 = &PTR__TType_a7b7cff8;
      if (local_fc >> 0x19 == 2) {
        pTVar12 = (unsigned char *)(**(code **)(*piVar7 + 0x1c))(piVar7);
        piVar7 = (int *)((int (*)())TIntermediate__changeAggrToTempConst)(this,pTVar12,param_5,param_4);
        iVar10 = (**(code **)(*piVar7 + 0x18))();
        if (*(int *)(iVar10 + 0x30) == 0) {
          return (int *)0x0;
        }
      }
    }
    piVar13 = (int *)(**(code **)(*piVar7 + 0x18))(piVar7);
    uVar14 = GetGlobalPoolAllocator();
    piVar15 = (int *)TPoolAllocator__allocate(uVar14);
    local_fc = local_fc & 0x1ff | 0x80800;
    local_11c = 0;
    local_118 = 0;
    local_114 = 0;
    local_110 = 0;
    local_10c = 0;
    local_108 = 0;
    local_104 = 0;
    local_100 = 0;
    *piVar15 = (int)&PTR_getLine_a7b7cf90;
    piVar15[1] = 0;
    piVar15[3] = 0;
    piVar15[4] = 0;
    piVar15[5] = 0;
    piVar15[6] = 0;
    piVar15[7] = 0;
    piVar15[8] = 0;
    piVar15[2] = (int)&PTR__TType_a7b7cff8;
    piVar15[9] = 0;
    piVar15[10] = 0;
    uVar6 = piVar15[0xb];
    piVar15[0xb] = uVar6 & 0x1ffffff;
    piVar15[0xb] = uVar6 & 0x7ffff | 0x80000;
    piVar15[0xb] = uVar6 & 0x7ff | 0x80800;
    piVar15[0xb] = uVar6 & 0x3ff | 0x80800;
    puVar5 = PTR_vtable_a7b7c0d4;
    piVar15[0xb] = uVar6 & 0x1ff | 0x80800;
    local_120 = &PTR__TType_a7b7cff8;
    *piVar15 = (int)(puVar5 + 8);
    piVar15[0xd] = 0;
    piVar15[0xc] = param_2;
    if (param_4 == 0) {
      param_4 = (**(code **)*piVar7)(piVar7);
    }
    (**(code **)(*piVar15 + 4))(piVar15,param_4);
    (**(code **)(*piVar15 + 0x60))(piVar15,piVar7);
    iVar10 = (**(code **)(*piVar15 + 0x5c))(piVar15,*(undefined4 *)this);
    piVar7 = (int *)0x0;
    if ((iVar10 != 0) &&
       ((piVar13 == (int *)0x0 ||
        (piVar7 = (int *)(**(code **)(*piVar13 + 0x5c))(piVar13,param_2,0,*(undefined4 *)this,1),
        piVar7 == (int *)0x0)))) {
      piVar7 = piVar15;
    }
  }
  return piVar7;
}

/* TIntermediate__setAggregateOperator @ 0x97b8e1b8 (1132 bytes) */
int TIntermediate__setAggregateOperator(param_1_00, param_1, param_3, param_4)
  undefined4 param_1_00;
  int *param_1;
  undefined4 param_3;
  int param_4;
{
  bool bVar1;
  undefined *puVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  ulong uVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  code *pcVar10;
  char in_RESERVE;
  byte bVar11;
  int *piStack0000001c;
  
  bVar11 = (param_1 == (int *)0x0) << 1;
  piStack0000001c = param_1;
  if (param_1 == (int *)0x0) {
    uVar6 = GetGlobalPoolAllocator();
    piVar5 = (int *)TPoolAllocator__allocate(uVar6);
    piVar5[1] = 0;
    *piVar5 = (int)&PTR_getLine_a7b7cf90;
    piVar5[3] = 0;
    piVar5[4] = 0;
    piVar5[5] = 0;
    piVar5[6] = 0;
    piVar5[7] = 0;
    piVar5[8] = 0;
    piVar5[2] = (int)&PTR__TType_a7b7cff8;
    piVar5[9] = 0;
    piVar5[10] = 0;
    uVar3 = piVar5[0xb];
    piVar5[0xb] = uVar3 & 0x1ffffff;
    piVar5[0xb] = uVar3 & 0x7ffff | 0x80000;
    piVar5[0xb] = uVar3 & 0x7ff | 0x80800;
    piVar5[0xb] = uVar3 & 0x3ff | 0x80800;
    puVar2 = PTR_vtable_a7b7c0d0;
    piVar5[0xb] = uVar3 & 0x1ff | 0x80800;
    *piVar5 = (int)(puVar2 + 8);
    piVar5[0xc] = 0;
    iVar7 = GetGlobalPoolAllocator();
    piVar5[0x10] = 0;
    piVar5[0xe] = 0;
    piVar5[0xf] = 0;
    piVar5[0xd] = iVar7;
    iVar7 = GetGlobalPoolAllocator();
    piVar5[0x11] = iVar7;
    iVar7 = DAT_a7b7b9b8;
    piVar5[0x14] = 0;
    piVar5[0x12] = 0;
    piVar4 = (int *)(iVar7 + 8);
    piVar5[0x13] = 0;
    do {
      if (in_RESERVE != '\0') {
        iVar8 = storeWordConditionalIndexed(*piVar4 + 1,0,piVar4);
        *piVar4 = iVar8;
        bVar11 = 2;
      }
    } while (!(bool)(bVar11 >> 1 & 1));
    iVar8 = GetGlobalPoolAllocator();
    piVar5[0x16] = iVar7 + 0xc;
    bVar1 = param_4 == 0;
    piVar5[0x1a] = 0;
    piVar5[0x15] = iVar8;
    piVar5[0x17] = 0;
  }
  else {
    piVar5 = (int *)(**(code **)(*param_1 + 0x1c))(param_1);
    bVar11 = (piVar5 == (int *)0x0) << 1;
    if ((piVar5 == (int *)0x0) || (bVar1 = param_4 == 0, piVar5[0xc] != 0)) {
      uVar6 = GetGlobalPoolAllocator();
      piVar5 = (int *)TPoolAllocator__allocate(uVar6);
      piVar5[1] = 0;
      *piVar5 = (int)&PTR_getLine_a7b7cf90;
      piVar5[3] = 0;
      piVar5[4] = 0;
      piVar5[5] = 0;
      piVar5[6] = 0;
      piVar5[7] = 0;
      piVar5[8] = 0;
      piVar5[2] = (int)&PTR__TType_a7b7cff8;
      piVar5[9] = 0;
      piVar5[10] = 0;
      uVar3 = piVar5[0xb];
      piVar5[0xb] = uVar3 & 0x1ffffff;
      piVar5[0xb] = uVar3 & 0x7ffff | 0x80000;
      piVar5[0xb] = uVar3 & 0x7ff | 0x80800;
      piVar5[0xb] = uVar3 & 0x3ff | 0x80800;
      puVar2 = PTR_vtable_a7b7c0d0;
      piVar5[0xb] = uVar3 & 0x1ff | 0x80800;
      *piVar5 = (int)(puVar2 + 8);
      piVar5[0xc] = 0;
      iVar7 = GetGlobalPoolAllocator();
      piVar5[0x10] = 0;
      piVar5[0xe] = 0;
      piVar5[0xf] = 0;
      piVar5[0xd] = iVar7;
      iVar7 = GetGlobalPoolAllocator();
      piVar5[0x11] = iVar7;
      iVar7 = DAT_a7b7b9b8;
      piVar5[0x14] = 0;
      piVar5[0x12] = 0;
      piVar4 = (int *)(iVar7 + 8);
      piVar5[0x13] = 0;
      do {
        if (in_RESERVE != '\0') {
          iVar8 = storeWordConditionalIndexed(*piVar4 + 1,0,piVar4);
          *piVar4 = iVar8;
          bVar11 = 2;
        }
      } while (!(bool)(bVar11 >> 1 & 1));
      iVar8 = GetGlobalPoolAllocator();
      piVar5[0x16] = iVar7 + 0xc;
      piVar5[0x15] = iVar8;
      pcVar10 = *(code **)(*piVar5 + 100);
      piVar5[0x1a] = 0;
      piVar5[0x17] = 0;
      iVar7 = (*pcVar10)(piVar5);
      puVar9 = *(undefined4 **)(iVar7 + 8);
      if (puVar9 == *(undefined4 **)(iVar7 + 0xc)) {
        std__vector_TIntermNode__pool_allocator_TIntermNode______M_insert_aux
                  (iVar7,puVar9,&STACKARG(0x1c));
      }
      else {
        iVar8 = 0;
        if (puVar9 != (undefined4 *)0x0) {
          *puVar9 = piStack0000001c;
          iVar8 = *(int *)(iVar7 + 8);
        }
        *(int *)(iVar7 + 8) = iVar8 + 4;
      }
      bVar1 = false;
      if (param_4 == 0) {
        param_4 = (**(code **)*piStack0000001c)();
        bVar1 = param_4 == 0;
      }
    }
  }
  (**(code **)(*piVar5 + 0x60))(piVar5,param_3);
  if (!bVar1) {
    (**(code **)(*piVar5 + 4))(piVar5,param_4);
  }
  return piVar5;
}

/* TIntermediate__addConversion @ 0x97b8e624 (2944 bytes) */
int TIntermediate__addConversion(this, param_2, param_3, param_4)
  unsigned char *this;
  int param_2;
  int *param_3;
  int *param_4;
{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  ulong uVar6;
  constUnion *pcVar7;
  int iVar8;
  undefined4 uVar9;
  uint uVar10;
  uint uVar11;
  bool bVar12;
  undefined4 *puVar13;
  uint uVar14;
  undefined **local_c0;
  int local_bc;
  int local_b8;
  int local_b4;
  int local_b0;
  int local_ac;
  int local_a8;
  int local_a4;
  int local_a0;
  uint local_9c;
  undefined4 local_90;
  uint uStack_8c;
  longlong local_40;
  undefined1 auStack_38 [4];
  int local_34;
  
  iVar3 = (**(code **)(*param_4 + 0x40))(param_4);
  if ((iVar3 == 0) || ((-1 < iVar3 && (iVar3 - 5U < 8)))) {
    return (int *)0x0;
  }
  (**(code **)(*param_4 + 0x38))(&local_c0,param_4);
  bVar12 = false;
  if (((param_3[9] & 0x1fffe00U) == (local_9c & 0x1fffe00)) && (param_3[2] == local_b8)) {
    bVar12 = true;
  }
  local_c0 = &PTR__TType_a7b7cff8;
  if (bVar12) {
    return param_4;
  }
  if (param_3[2] != 0) {
    return (int *)0x0;
  }
  (**(code **)(*param_4 + 0x38))((unsigned char *)&local_c0,param_4);
  local_c0 = &PTR__TType_a7b7cff8;
  if (local_b8 != 0) {
    return (int *)0x0;
  }
  iVar3 = (**(code **)(*param_3 + 0x38))(param_3);
  if (iVar3 != 0) {
    return (int *)0x0;
  }
  (**(code **)(*param_4 + 0x38))((unsigned char *)&local_c0,param_4);
  local_c0 = &PTR__TType_a7b7cff8;
  if ((local_9c & 0x200) != 0) {
    return (int *)0x0;
  }
  if (param_2 == 0x67) {
    uVar4 = 3;
  }
  else if (param_2 < 0x68) {
    if (param_2 != 0x66) {
LAB_97b8e794:
      uVar4 = (**(code **)(*param_3 + 0x20))(param_3);
      (**(code **)(*param_4 + 0x38))(&local_c0,param_4);
      if (uVar4 == (local_9c >> 0x13 & 0x3f)) {
        return param_4;
      }
      return (int *)0x0;
    }
    uVar4 = 2;
  }
  else {
    if (param_2 != 0x68) goto LAB_97b8e794;
    uVar4 = 1;
  }
  bVar12 = true;
  iVar3 = (**(code **)(*param_4 + 0x1c))(param_4);
  if (iVar3 == 0) {
LAB_97b8e8ac:
    iVar3 = (**(code **)(*param_4 + 0x1c))(param_4);
    if (iVar3 != 0) {
      piVar5 = (int *)(**(code **)(*param_4 + 0x1c))(param_4);
      iVar3 = (**(code **)(*piVar5 + 100))();
      puVar13 = *(undefined4 **)(iVar3 + 4);
      do {
        if (puVar13 == *(undefined4 **)(iVar3 + 8)) {
          piVar5 = (int *)(**(code **)(*param_4 + 0x1c))(param_4);
          return piVar5;
        }
        uVar6 = GetGlobalPoolAllocator();
        pcVar7 = (unsigned char *)TPoolAllocator__allocate(uVar6);
        if (uVar4 == 2) {
          piVar5 = (int *)(**(code **)(*(int *)*puVar13 + 0x14))();
          (**(code **)(*piVar5 + 0x38))(&local_c0,piVar5);
          uVar14 = local_9c >> 0x13 & 0x3f;
          local_c0 = &PTR__TType_a7b7cff8;
          if (uVar14 != 1) {
            if (uVar14 != 3) {
              (**(code **)*param_4)(param_4);
                    
                    
              piVar5 = (int *)(*(code *)(((unsigned char *)0x97b8ebc4) + (*(unsigned char *)0x97b8ebd0)))();
              return piVar5;
            }
            piVar5 = (int *)(**(code **)(*(int *)*puVar13 + 0x14))();
            iVar8 = (**(code **)(*piVar5 + 0x18))();
            *(undefined4 *)pcVar7 = **(undefined4 **)(iVar8 + 0x30);
            goto LAB_97b8ecd8;
          }
          piVar5 = (int *)(**(code **)(*(int *)*puVar13 + 0x14))();
          iVar8 = (**(code **)(*piVar5 + 0x18))();
          local_40 = (longlong)(int)**(float **)(iVar8 + 0x30);
          *(int *)pcVar7 = (int)**(float **)(iVar8 + 0x30);
LAB_97b8ec88:
          local_9c = uVar4 << 0x13 | local_9c & 0x7ff | 0x4000000 | 0x800;
        }
        else if (uVar4 < 3) {
          if (uVar4 != 1) {
LAB_97b8ed3c:
            (**(code **)*param_4)(param_4);
                    
                    
            piVar5 = (int *)(*(code *)(((unsigned char *)0x97b8ed78) + (*(unsigned char *)0x97b8ed84)))();
            return piVar5;
          }
          piVar5 = (int *)(**(code **)(*(int *)*puVar13 + 0x14))();
          (**(code **)(*piVar5 + 0x38))(&local_c0,piVar5);
          uVar14 = local_9c >> 0x13 & 0x3f;
          local_c0 = &PTR__TType_a7b7cff8;
          if (uVar14 == 2) {
            piVar5 = (int *)(**(code **)(*(int *)*puVar13 + 0x14))();
            iVar8 = (**(code **)(*piVar5 + 0x18))();
            uStack_8c = **(uint **)(iVar8 + 0x30) ^ 0x80000000;
            *(float *)pcVar7 = (float)((double)CONCAT44(0x43300000,uStack_8c) - DOUBLE_97c30a58);
          }
          else {
            if (uVar14 != 3) {
              (**(code **)*param_4)(param_4);
                    
                    
              piVar5 = (int *)(*(code *)(((unsigned char *)0x97b8ea90) + (*(unsigned char *)0x97b8ea9c)))();
              return piVar5;
            }
            piVar5 = (int *)(**(code **)(*(int *)*puVar13 + 0x14))();
            iVar8 = (**(code **)(*piVar5 + 0x18))();
            uStack_8c = **(uint **)(iVar8 + 0x30);
            *(float *)pcVar7 = (float)((double)CONCAT44(0x43300000,uStack_8c) - DOUBLE_97c30a68);
          }
          local_90 = 0x43300000;
          local_9c = local_9c & 0x7ff | 0x4080800;
        }
        else {
          if (uVar4 != 3) goto LAB_97b8ed3c;
          piVar5 = (int *)(**(code **)(*(int *)*puVar13 + 0x14))();
          (**(code **)(*piVar5 + 0x38))(&local_c0,piVar5);
          uVar14 = local_9c >> 0x13 & 0x3f;
          local_c0 = &PTR__TType_a7b7cff8;
          if (uVar14 == 1) {
            piVar5 = (int *)(**(code **)(*(int *)*puVar13 + 0x14))();
            iVar8 = (**(code **)(*piVar5 + 0x18))();
            *(uint *)pcVar7 = (uint)((double)**(float **)(iVar8 + 0x30) != DOUBLE_97c30a48);
            goto LAB_97b8ec88;
          }
          if (uVar14 != 2) {
            (**(code **)*param_4)(param_4);
                    
                    
            piVar5 = (int *)(*(code *)(((unsigned char *)0x97b8ed24) + (*(unsigned char *)0x97b8ed30)))();
            return piVar5;
          }
          piVar5 = (int *)(**(code **)(*(int *)*puVar13 + 0x14))();
          iVar8 = (**(code **)(*piVar5 + 0x18))();
          *(uint *)pcVar7 = (uint)(**(int **)(iVar8 + 0x30) != 0);
LAB_97b8ecd8:
          local_9c = uVar4 << 0x13 | local_9c & 0xfff | 0x4000000 | 0x800;
        }
        local_9c = local_9c & 0xfffff9ff;
        local_bc = 0;
        local_b8 = 0;
        local_b4 = 0;
        local_b0 = 0;
        local_ac = 0;
        local_a8 = 0;
        local_a4 = 0;
        local_a0 = 0;
        local_c0 = &PTR__TType_a7b7cff8;
        iVar8 = (**(code **)*param_4)(param_4);
        iVar8 = ((int (*)())TIntermediate__addConstantUnion)(this,pcVar7,(unsigned char *)&local_c0,iVar8);
        local_c0 = &PTR__TType_a7b7cff8;
        if (iVar8 != 0) {
          std__vector_TIntermNode__pool_allocator_TIntermNode_____erase(auStack_38,iVar3,puVar13);
          local_34 = iVar8;
          std__vector_TIntermNode__pool_allocator_TIntermNode_____insert
                    (auStack_38,iVar3,puVar13,&local_34);
        }
        puVar13 = puVar13 + 1;
      } while( true );
    }
  }
  else {
    iVar3 = (**(code **)(*param_4 + 0x1c))(param_4);
    if (*(int *)(iVar3 + 0x30) == 2) {
      bVar12 = false;
    }
    else {
      piVar5 = (int *)(**(code **)(*param_4 + 0x1c))(param_4);
      iVar3 = (**(code **)(*piVar5 + 100))();
      for (puVar13 = *(undefined4 **)(iVar3 + 4); puVar13 != *(undefined4 **)(iVar3 + 8);
          puVar13 = puVar13 + 1) {
        piVar5 = (int *)(**(code **)(*(int *)*puVar13 + 0x14))();
        iVar8 = (**(code **)(*piVar5 + 0x18))();
        if (iVar8 == 0) {
          bVar12 = false;
        }
      }
    }
    if (bVar12) goto LAB_97b8e8ac;
  }
  iVar3 = (**(code **)(*param_4 + 0x18))(param_4);
  if (iVar3 != 0) {
    uVar9 = (**(code **)(*param_4 + 0x18))(param_4);
    piVar5 = (int *)((int (*)())TIntermediate__promoteConstantUnion)(this,uVar4,uVar9);
    return piVar5;
  }
  if (uVar4 == 2) {
    iVar3 = (**(code **)(*param_4 + 0x40))(param_4);
    if (iVar3 == 1) {
      iVar8 = 0x11;
    }
    else {
      iVar8 = 0x12;
      if (iVar3 != 3) {
        (**(code **)*param_4)(param_4);
                    
                    
        piVar5 = (int *)(*(code *)(((unsigned char *)0x97b8f030) + (*(unsigned char *)0x97b8f03c)))();
        return piVar5;
      }
    }
  }
  else if (uVar4 < 3) {
    if (uVar4 != 1) {
LAB_97b8f048:
      (**(code **)*param_4)(param_4);
                    
                    
      piVar5 = (int *)(*(code *)(((unsigned char *)0x97b8f084) + (*(unsigned char *)0x97b8f090)))();
      return piVar5;
    }
    iVar3 = (**(code **)(*param_4 + 0x40))(param_4);
    if (iVar3 == 2) {
      iVar8 = 0x10;
    }
    else {
      iVar8 = 0xf;
      if (iVar3 != 3) {
        (**(code **)*param_4)(param_4);
                    
                    
        piVar5 = (int *)(*(code *)(((unsigned char *)0x97b8ef20) + (*(unsigned char *)0x97b8ef2c)))();
        return piVar5;
      }
    }
  }
  else {
    if (uVar4 != 3) goto LAB_97b8f048;
    iVar3 = (**(code **)(*param_4 + 0x40))(param_4);
    if (iVar3 == 1) {
      iVar8 = 0xe;
    }
    else {
      iVar8 = 0xd;
      if (iVar3 != 2) {
        (**(code **)*param_4)(param_4);
                    
                    
        piVar5 = (int *)(*(code *)(((unsigned char *)0x97b8efa8) + (*(unsigned char *)0x97b8efb4)))();
        return piVar5;
      }
    }
  }
  uVar14 = (**(code **)(*param_4 + 0x48))(param_4);
  uVar10 = (**(code **)(*param_4 + 0x50))(param_4);
  uVar11 = (**(code **)(*param_4 + 0x54))(param_4);
  local_c0 = &PTR__TType_a7b7cff8;
  local_9c = (uVar11 & 1) << 9 |
             (uVar10 & 1) << 10 | (uVar14 & 0xff) << 0xb | uVar4 << 0x13 | local_9c & 0x1ff;
  local_bc = 0;
  local_b8 = 0;
  local_b4 = 0;
  local_b0 = 0;
  local_ac = 0;
  local_a8 = 0;
  local_a4 = 0;
  local_a0 = 0;
  uVar6 = GetGlobalPoolAllocator();
  piVar5 = (int *)TPoolAllocator__allocate(uVar6);
  piVar5[1] = 0;
  *piVar5 = (int)&PTR_getLine_a7b7cf90;
  piVar5[3] = local_bc;
  piVar5[4] = local_b8;
  piVar5[5] = local_b4;
  piVar5[6] = local_b0;
  piVar5[7] = local_ac;
  piVar5[8] = local_a8;
  piVar5[2] = (int)&PTR__TType_a7b7cff8;
  piVar5[10] = local_a0;
  piVar5[9] = local_a4;
  puVar1 = PTR_vtable_a7b7c0d4;
  uVar2 = piVar5[0xb];
  uVar14 = local_9c & 0xfe000000;
  piVar5[0xb] = uVar14 | uVar2 & 0x1ffffff;
  uVar10 = (local_9c >> 0x13 & 0x3f) << 0x13;
  piVar5[0xb] = uVar10 | uVar14 | uVar2 & 0x7ffff;
  uVar4 = local_9c & 0x7f800;
  piVar5[0xb] = uVar4 | uVar10 | uVar14 | uVar2 & 0x7ff;
  uVar11 = (local_9c >> 10 & 1) << 10;
  piVar5[0xb] = uVar11 | uVar4 | uVar10 | uVar14 | uVar2 & 0x3ff;
  piVar5[0xb] = (local_9c >> 9 & 1) << 9 | uVar11 | uVar4 | uVar10 | uVar14 | uVar2 & 0x1ff;
  piVar5[0xc] = iVar8;
  *piVar5 = (int)(puVar1 + 8);
  piVar5[0xd] = 0;
  uVar9 = (**(code **)*param_4)(param_4);
  (**(code **)(puVar1 + 0xc))(piVar5,uVar9);
  (**(code **)(*piVar5 + 0x60))(piVar5,param_4);
  return piVar5;
}

/* TIntermediate__growAggregate @ 0x97b8f36c (760 bytes) */
int TIntermediate__growAggregate(this, param_1, param_2, param_3)
  unsigned char *this;
  unsigned char *param_1;
  unsigned char *param_2;
  int param_3;
{
  undefined *puVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  ulong uVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  char in_RESERVE;
  byte in_cr0;
  TIntermNode *pTStack0000001c;
  TIntermNode *pTStack00000020;
  
  if ((param_1 == (unsigned char *)0x0) && (param_2 == (unsigned char *)0x0)) {
    return (int *)0x0;
  }
  pTStack0000001c = param_1;
  pTStack00000020 = param_2;
  if (param_1 != (unsigned char *)0x0) {
    piVar4 = (int *)(**(code **)(*(int *)param_1 + 0x1c))();
    in_cr0 = (piVar4 == (int *)0x0) << 1;
    if ((piVar4 != (int *)0x0) && (piVar4[0xc] == 0)) goto LAB_97b8f5cc;
  }
  uVar5 = GetGlobalPoolAllocator();
  piVar4 = (int *)TPoolAllocator__allocate(uVar5);
  piVar4[1] = 0;
  *piVar4 = (int)&PTR_getLine_a7b7cf90;
  piVar4[3] = 0;
  piVar4[4] = 0;
  piVar4[5] = 0;
  piVar4[6] = 0;
  piVar4[7] = 0;
  piVar4[8] = 0;
  piVar4[2] = (int)&PTR__TType_a7b7cff8;
  piVar4[9] = 0;
  piVar4[10] = 0;
  uVar2 = piVar4[0xb];
  piVar4[0xb] = uVar2 & 0x1ffffff;
  piVar4[0xb] = uVar2 & 0x7ffff | 0x80000;
  piVar4[0xb] = uVar2 & 0x7ff | 0x80800;
  piVar4[0xb] = uVar2 & 0x3ff | 0x80800;
  puVar1 = PTR_vtable_a7b7c0d0;
  piVar4[0xb] = uVar2 & 0x1ff | 0x80800;
  *piVar4 = (int)(puVar1 + 8);
  piVar4[0xc] = 0;
  iVar6 = GetGlobalPoolAllocator();
  piVar4[0x10] = 0;
  piVar4[0xe] = 0;
  piVar4[0xf] = 0;
  piVar4[0xd] = iVar6;
  iVar6 = GetGlobalPoolAllocator();
  piVar4[0x11] = iVar6;
  iVar6 = DAT_a7b7b9b8;
  piVar4[0x14] = 0;
  piVar4[0x12] = 0;
  piVar3 = (int *)(iVar6 + 8);
  piVar4[0x13] = 0;
  do {
    if (in_RESERVE != '\0') {
      iVar7 = storeWordConditionalIndexed(*piVar3 + 1,0,piVar3);
      *piVar3 = iVar7;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  iVar7 = GetGlobalPoolAllocator();
  piVar4[0x16] = iVar6 + 0xc;
  piVar4[0x15] = iVar7;
  piVar4[0x1a] = 0;
  piVar4[0x17] = 0;
  if (pTStack0000001c != (unsigned char *)0x0) {
    iVar6 = (**(code **)(*piVar4 + 100))(piVar4);
    puVar8 = *(undefined4 **)(iVar6 + 8);
    if (puVar8 == *(undefined4 **)(iVar6 + 0xc)) {
      std__vector_TIntermNode__pool_allocator_TIntermNode______M_insert_aux
                (iVar6,puVar8,&STACKARG(0x1c));
    }
    else {
      iVar7 = 0;
      if (puVar8 != (undefined4 *)0x0) {
        *puVar8 = pTStack0000001c;
        iVar7 = *(int *)(iVar6 + 8);
      }
      *(int *)(iVar6 + 8) = iVar7 + 4;
    }
  }
LAB_97b8f5cc:
  if (pTStack00000020 != (unsigned char *)0x0) {
    iVar6 = (**(code **)(*piVar4 + 100))(piVar4);
    puVar8 = *(undefined4 **)(iVar6 + 8);
    if (puVar8 == *(undefined4 **)(iVar6 + 0xc)) {
      std__vector_TIntermNode__pool_allocator_TIntermNode______M_insert_aux
                (iVar6,puVar8,&STACKARG(0x20));
    }
    else {
      iVar7 = 0;
      if (puVar8 != (undefined4 *)0x0) {
        *puVar8 = pTStack00000020;
        iVar7 = *(int *)(iVar6 + 8);
      }
      *(int *)(iVar6 + 8) = iVar7 + 4;
    }
  }
  if (param_3 != 0) {
    (**(code **)(*piVar4 + 4))(piVar4,param_3);
  }
  return piVar4;
}

/* TIntermediate__makeAggregate @ 0x97b8f664 (632 bytes) */
int TIntermediate__makeAggregate(this, param_1, param_2)
  unsigned char *this;
  unsigned char *param_1;
  int param_2;
{
  undefined *puVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  ulong uVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  code *pcVar9;
  char in_RESERVE;
  byte in_cr0;
  TIntermNode *pTStack0000001c;
  
  piVar4 = (int *)0x0;
  if (param_1 != (unsigned char *)0x0) {
    pTStack0000001c = param_1;
    uVar5 = GetGlobalPoolAllocator();
    piVar4 = (int *)TPoolAllocator__allocate(uVar5);
    piVar4[1] = 0;
    *piVar4 = (int)&PTR_getLine_a7b7cf90;
    piVar4[3] = 0;
    piVar4[4] = 0;
    piVar4[5] = 0;
    piVar4[6] = 0;
    piVar4[7] = 0;
    piVar4[8] = 0;
    piVar4[2] = (int)&PTR__TType_a7b7cff8;
    piVar4[9] = 0;
    piVar4[10] = 0;
    uVar2 = piVar4[0xb];
    piVar4[0xb] = uVar2 & 0x1ffffff;
    piVar4[0xb] = uVar2 & 0x7ffff | 0x80000;
    piVar4[0xb] = uVar2 & 0x7ff | 0x80800;
    piVar4[0xb] = uVar2 & 0x3ff | 0x80800;
    puVar1 = PTR_vtable_a7b7c0d0;
    piVar4[0xb] = uVar2 & 0x1ff | 0x80800;
    *piVar4 = (int)(puVar1 + 8);
    piVar4[0xc] = 0;
    iVar6 = GetGlobalPoolAllocator();
    piVar4[0x10] = 0;
    piVar4[0xe] = 0;
    piVar4[0xf] = 0;
    piVar4[0xd] = iVar6;
    iVar6 = GetGlobalPoolAllocator();
    piVar4[0x11] = iVar6;
    iVar6 = DAT_a7b7b9b8;
    piVar4[0x14] = 0;
    piVar4[0x12] = 0;
    piVar3 = (int *)(iVar6 + 8);
    piVar4[0x13] = 0;
    do {
      if (in_RESERVE != '\0') {
        iVar7 = storeWordConditionalIndexed(*piVar3 + 1,0,piVar3);
        *piVar3 = iVar7;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    iVar7 = GetGlobalPoolAllocator();
    piVar4[0x16] = iVar6 + 0xc;
    piVar4[0x15] = iVar7;
    pcVar9 = *(code **)(*piVar4 + 100);
    piVar4[0x1a] = 0;
    piVar4[0x17] = 0;
    iVar6 = (*pcVar9)(piVar4);
    puVar8 = *(undefined4 **)(iVar6 + 8);
    if (puVar8 == *(undefined4 **)(iVar6 + 0xc)) {
      std__vector_TIntermNode__pool_allocator_TIntermNode______M_insert_aux
                (iVar6,puVar8,&STACKARG(0x1c));
    }
    else {
      iVar7 = 0;
      if (puVar8 != (undefined4 *)0x0) {
        *puVar8 = pTStack0000001c;
        iVar7 = *(int *)(iVar6 + 8);
      }
      *(int *)(iVar6 + 8) = iVar7 + 4;
    }
    if (param_2 == 0) {
      iVar6 = *piVar4;
      param_2 = (*(code *)**(undefined4 **)pTStack0000001c)();
      pcVar9 = *(code **)(iVar6 + 4);
    }
    else {
      pcVar9 = *(code **)(*piVar4 + 4);
    }
    (*pcVar9)(piVar4,param_2);
  }
  return piVar4;
}

/* TIntermediate__addSelection @ 0x97b8f8dc (516 bytes) */
int TIntermediate__addSelection(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int *param_2;
  undefined4 *param_3;
  undefined4 *param_4;
  undefined4 param_5;
{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  ulong uVar5;
  undefined4 *puVar6;
  undefined *puVar7;
  code *pcVar8;
  undefined4 *puStack00000020;
  undefined4 *puStack00000024;
  
  puStack00000020 = param_3;
  puStack00000024 = param_4;
  iVar3 = (**(code **)(*param_2 + 0x14))(param_2);
  if (iVar3 != 0) {
    piVar4 = (int *)(**(code **)(*param_2 + 0x14))(param_2);
    iVar3 = (**(code **)(*piVar4 + 0x18))();
    if (iVar3 != 0) {
      piVar4 = (int *)(**(code **)(*param_2 + 0x14))(param_2);
      iVar3 = (**(code **)(*piVar4 + 0x18))();
      if (**(int **)(iVar3 + 0x30) == 0) {
        return puStack00000024;
      }
      return puStack00000020;
    }
  }
  uVar5 = GetGlobalPoolAllocator();
  puVar6 = (undefined4 *)TPoolAllocator__allocate(uVar5);
  *puVar6 = &PTR_getLine_a7b7cf90;
  puVar6[1] = 0;
  puVar6[3] = 0;
  puVar6[4] = 0;
  puVar6[5] = 0;
  puVar6[6] = 0;
  puVar6[7] = 0;
  puVar6[8] = 0;
  puVar6[2] = &PTR__TType_a7b7cff8;
  puVar6[10] = 0;
  puVar6[9] = 0;
  uVar2 = puVar6[0xb];
  puVar6[0xb] = uVar2 & 0x1ffffff;
  puVar1 = PTR_vtable_a7b7c0cc;
  puVar7 = PTR_vtable_a7b7c0cc + 8;
  puVar6[0xb] = uVar2 & 0x7ffff;
  pcVar8 = *(code **)(puVar1 + 0xc);
  puVar6[0xb] = uVar2 & 0x7ff | 0x800;
  puVar6[0xb] = uVar2 & 0x3ff | 0x800;
  puVar6[0xb] = uVar2 & 0x1ff | 0x800;
  puVar6[0xc] = param_2;
  puVar6[0xd] = puStack00000020;
  puVar6[0xe] = puStack00000024;
  *puVar6 = puVar7;
  (*pcVar8)(puVar6,param_5);
  return puVar6;
}

/* TIntermediate__addComma @ 0x97b8fae0 (348 bytes) */
int TIntermediate__addComma(this, param_1, param_2, param_3)
  unsigned char *this;
  unsigned char *param_1;
  unsigned char *param_2;
  int param_3;
{
  bool bVar1;
  TIntermTyped *pTVar2;
  int *piVar3;
  undefined **local_b0 [9];
  uint local_8c;
  undefined **local_80 [9];
  uint local_5c;
  undefined **local_50 [13];
  
  bVar1 = false;
  (**(code **)(*(int *)param_1 + 0x38))(local_b0);
  if (local_8c >> 0x19 == 2) {
    (**(code **)(*(int *)param_2 + 0x38))(local_80,param_2);
    bVar1 = local_5c >> 0x19 == 2;
    local_80[0] = &PTR__TType_a7b7cff8;
  }
  local_b0[0] = &PTR__TType_a7b7cff8;
  pTVar2 = param_2;
  if (!bVar1) {
    pTVar2 = (unsigned char *)
             ((int (*)())TIntermediate__growAggregate)(this,(unsigned char *)param_1,(unsigned char *)param_2,param_3);
    piVar3 = (int *)(**(code **)(*(int *)pTVar2 + 0x1c))();
    (**(code **)(*piVar3 + 0x60))(piVar3,0x25);
    (**(code **)(*(int *)param_2 + 0x38))(local_50,param_2);
    (**(code **)(*(int *)pTVar2 + 0x34))(pTVar2,local_50);
    local_50[0] = &PTR__TType_a7b7cff8;
    piVar3 = (int *)(**(code **)(*(int *)pTVar2 + 0x3c))(pTVar2);
    (**(code **)(*piVar3 + 0x28))(piVar3,0);
  }
  return pTVar2;
}

/* TIntermediate__addSelection_97b8fc3c @ 0x97b8fc3c (628 bytes) */
int TIntermediate__addSelection_97b8fc3c(this, param_1, param_2, param_3, param_4)
  unsigned char *this;
  unsigned char *param_1;
  unsigned char *param_2;
  unsigned char *param_3;
  int param_4;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined *puVar5;
  uint uVar6;
  TIntermTyped *pTVar7;
  int iVar8;
  ulong uVar9;
  TIntermTyped *pTVar10;
  undefined **local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  uint local_3c;
  
  (**(code **)(*(int *)param_2 + 0x38))(&local_60,param_2);
  pTVar7 = (unsigned char *)((int (*)())TIntermediate__addConversion)(this,1,&local_60,param_3);
  local_60 = &PTR__TType_a7b7cff8;
  if (pTVar7 == (unsigned char *)0x0) {
    (**(code **)(*(int *)param_3 + 0x38))(&local_60,param_3);
    param_2 = (unsigned char *)((int (*)())TIntermediate__addConversion)(this,1,&local_60,param_2);
    pTVar7 = param_3;
    if (param_2 == (unsigned char *)0x0) {
      return (unsigned char *)0x0;
    }
  }
  local_60 = &PTR__TType_a7b7cff8;
  iVar8 = (**(code **)(*(int *)param_1 + 0x18))(param_1);
  if (((iVar8 == 0) || (iVar8 = (**(code **)(*(int *)param_2 + 0x18))(param_2), iVar8 == 0)) ||
     (iVar8 = (**(code **)(*(int *)pTVar7 + 0x18))(pTVar7), iVar8 == 0)) {
    uVar9 = GetGlobalPoolAllocator();
    pTVar10 = (unsigned char *)TPoolAllocator__allocate(uVar9);
    (**(code **)(*(int *)param_2 + 0x38))(&local_60,param_2);
    *(int *)(pTVar10 + 4) = 0;
    *(undefined ***)pTVar10 = &PTR_getLine_a7b7cf90;
    *(int *)(pTVar10 + 0xc) = local_5c;
    *(int *)(pTVar10 + 0x10) = local_58;
    *(int *)(pTVar10 + 0x14) = local_54;
    *(int *)(pTVar10 + 0x18) = local_50;
    *(int *)(pTVar10 + 0x1c) = local_4c;
    *(int *)(pTVar10 + 0x20) = local_48;
    *(undefined ***)(pTVar10 + 8) = &PTR__TType_a7b7cff8;
    *(int *)(pTVar10 + 0x24) = local_44;
    *(int *)(pTVar10 + 0x28) = local_40;
    uVar6 = *(uint *)(pTVar10 + 0x2c);
    uVar2 = local_3c & 0xfe000000;
    *(uint *)(pTVar10 + 0x2c) = uVar2 | uVar6 & 0x1ffffff;
    uVar3 = (local_3c >> 0x13 & 0x3f) << 0x13;
    *(uint *)(pTVar10 + 0x2c) = uVar3 | uVar2 | uVar6 & 0x7ffff;
    uVar1 = local_3c & 0x7f800;
    *(uint *)(pTVar10 + 0x2c) = uVar1 | uVar3 | uVar2 | uVar6 & 0x7ff;
    uVar4 = (local_3c >> 10 & 1) << 10;
    *(uint *)(pTVar10 + 0x2c) = uVar4 | uVar1 | uVar3 | uVar2 | uVar6 & 0x3ff;
    puVar5 = PTR_vtable_a7b7c0cc;
    *(uint *)(pTVar10 + 0x2c) =
         (local_3c >> 9 & 1) << 9 | uVar4 | uVar1 | uVar3 | uVar2 | uVar6 & 0x1ff;
    *(TIntermTyped **)(pTVar10 + 0x30) = param_1;
    *(undefined **)pTVar10 = puVar5 + 8;
    *(TIntermTyped **)(pTVar10 + 0x34) = param_2;
    *(TIntermTyped **)(pTVar10 + 0x38) = pTVar7;
    local_60 = &PTR__TType_a7b7cff8;
    (**(code **)(*(int *)pTVar10 + 4))(pTVar10,param_4);
  }
  else {
    iVar8 = (**(code **)(*(int *)param_1 + 0x18))(param_1);
    pTVar10 = param_2;
    if (**(int **)(iVar8 + 0x30) == 0) {
      pTVar10 = pTVar7;
    }
  }
  return pTVar10;
}

/* TIntermediate__addConstantUnion @ 0x97b8feb0 (300 bytes) */
int TIntermediate__addConstantUnion(this, param_1, param_2, param_3)
  unsigned char *this;
  unsigned char *param_1;
  unsigned char *param_2;
  int param_3;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined *puVar7;
  ulong uVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  code *pcVar17;
  
  uVar8 = GetGlobalPoolAllocator();
  puVar9 = (undefined4 *)TPoolAllocator__allocate(uVar8);
  puVar9[1] = 0;
  *puVar9 = &PTR_getLine_a7b7cf90;
  uVar5 = *(undefined4 *)(param_2 + 4);
  uVar15 = *(undefined4 *)(param_2 + 8);
  uVar10 = *(undefined4 *)(param_2 + 0x20);
  uVar16 = *(undefined4 *)(param_2 + 0xc);
  uVar14 = *(undefined4 *)(param_2 + 0x10);
  uVar13 = *(undefined4 *)(param_2 + 0x14);
  uVar12 = *(undefined4 *)(param_2 + 0x18);
  uVar11 = *(undefined4 *)(param_2 + 0x1c);
  puVar9[2] = &PTR__TType_a7b7cff8;
  puVar9[3] = uVar5;
  puVar9[10] = uVar10;
  puVar9[4] = uVar15;
  puVar9[5] = uVar16;
  puVar9[6] = uVar14;
  puVar9[7] = uVar13;
  puVar9[8] = uVar12;
  puVar9[9] = uVar11;
  uVar6 = puVar9[0xb];
  uVar2 = *(uint *)(param_2 + 0x24) & 0xfe000000;
  puVar9[0xb] = uVar2 | uVar6 & 0x1ffffff;
  uVar3 = (*(uint *)(param_2 + 0x24) >> 0x13 & 0x3f) << 0x13;
  puVar9[0xb] = uVar3 | uVar2 | uVar6 & 0x7ffff;
  uVar1 = *(uint *)(param_2 + 0x24) & 0x7f800;
  puVar9[0xb] = uVar1 | uVar3 | uVar2 | uVar6 & 0x7ff;
  uVar4 = (*(uint *)(param_2 + 0x24) >> 10 & 1) << 10;
  puVar9[0xb] = uVar4 | uVar1 | uVar3 | uVar2 | uVar6 & 0x3ff;
  puVar7 = PTR_vtable_a7b7c0c8 + 8;
  pcVar17 = *(code **)(PTR_vtable_a7b7c0c8 + 0xc);
  puVar9[0xb] = (*(uint *)(param_2 + 0x24) >> 9 & 1) << 9 |
                uVar4 | uVar1 | uVar3 | uVar2 | uVar6 & 0x1ff;
  puVar9[0xc] = param_1;
  *puVar9 = puVar7;
  (*pcVar17)(puVar9,param_3);
  return puVar9;
}

/* TIntermediate__addSwizzle @ 0x97b8ffdc (744 bytes) */
int TIntermediate__addSwizzle(this, param_1, param_2)
  unsigned char *this;
  unsigned char *param_1;
  int param_2;
{
  undefined *puVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  ulong uVar5;
  int *piVar6;
  int iVar7;
  constUnion *pcVar8;
  undefined4 *puVar9;
  code *pcVar10;
  int iVar11;
  TVectorFields *pTVar12;
  char in_RESERVE;
  byte in_cr0;
  undefined **local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  uint local_8c;
  int local_80;
  int local_70;
  int local_60;
  undefined4 local_50 [6];
  
  uVar5 = GetGlobalPoolAllocator();
  piVar6 = (int *)TPoolAllocator__allocate(uVar5);
  local_8c = local_8c & 0x1ff | 0x80800;
  local_ac = 0;
  local_a8 = 0;
  local_a4 = 0;
  local_a0 = 0;
  local_9c = 0;
  local_98 = 0;
  local_94 = 0;
  local_90 = 0;
  *piVar6 = (int)&PTR_getLine_a7b7cf90;
  piVar6[1] = 0;
  piVar6[3] = 0;
  piVar6[4] = 0;
  piVar6[5] = 0;
  piVar6[6] = 0;
  piVar6[7] = 0;
  piVar6[8] = 0;
  piVar6[9] = 0;
  piVar6[2] = (int)&PTR__TType_a7b7cff8;
  piVar6[10] = 0;
  uVar2 = piVar6[0xb];
  piVar6[0xb] = uVar2 & 0x1ffffff;
  piVar6[0xb] = uVar2 & 0x7ffff | 0x80000;
  piVar6[0xb] = uVar2 & 0x7ff | 0x80800;
  piVar6[0xb] = uVar2 & 0x3ff | 0x80800;
  puVar1 = PTR_vtable_a7b7c0d0;
  piVar6[0xb] = uVar2 & 0x1ff | 0x80800;
  local_b0 = &PTR__TType_a7b7cff8;
  piVar6[0xc] = 1;
  *piVar6 = (int)(puVar1 + 8);
  local_80 = GetGlobalPoolAllocator();
  piVar6[0x10] = 0;
  piVar6[0xe] = 0;
  piVar6[0xf] = 0;
  piVar6[0xd] = local_80;
  local_70 = GetGlobalPoolAllocator();
  piVar6[0x11] = local_70;
  iVar7 = DAT_a7b7b9b8;
  piVar6[0x14] = 0;
  piVar6[0x12] = 0;
  piVar3 = (int *)(iVar7 + 8);
  piVar6[0x13] = 0;
  do {
    if (in_RESERVE != '\0') {
      iVar11 = storeWordConditionalIndexed(*piVar3 + 1,0,piVar3);
      *piVar3 = iVar11;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  local_60 = GetGlobalPoolAllocator();
  piVar6[0x16] = iVar7 + 0xc;
  iVar11 = 0;
  piVar6[0x15] = local_60;
  pcVar10 = *(code **)(*piVar6 + 4);
  piVar6[0x1a] = 0;
  (*pcVar10)(piVar6,param_2);
  iVar7 = (**(code **)(*piVar6 + 100))(piVar6);
  if (0 < *(int *)(param_1 + 0x10)) {
    pTVar12 = param_1;
    do {
      uVar5 = GetGlobalPoolAllocator();
      pcVar8 = (unsigned char *)TPoolAllocator__allocate(uVar5);
      *(undefined4 *)pcVar8 = *(undefined4 *)pTVar12;
      local_8c = local_8c & 0x1ff | 0x4100800;
      pTVar12 = pTVar12 + 4;
      local_b0 = &PTR__TType_a7b7cff8;
      local_ac = 0;
      local_a8 = 0;
      local_a4 = 0;
      local_a0 = 0;
      local_9c = 0;
      local_98 = 0;
      local_94 = 0;
      local_90 = 0;
      local_50[0] = ((int (*)())TIntermediate__addConstantUnion)(this,pcVar8,(unsigned char *)&local_b0,param_2);
      local_b0 = &PTR__TType_a7b7cff8;
      puVar9 = *(undefined4 **)(iVar7 + 8);
      if (puVar9 == *(undefined4 **)(iVar7 + 0xc)) {
        std__vector_TIntermNode__pool_allocator_TIntermNode______M_insert_aux(iVar7,puVar9,local_50)
        ;
      }
      else {
        iVar4 = 0;
        if (puVar9 != (undefined4 *)0x0) {
          *puVar9 = local_50[0];
          iVar4 = *(int *)(iVar7 + 8);
        }
        *(int *)(iVar7 + 8) = iVar4 + 4;
      }
      iVar11 = iVar11 + 1;
    } while (iVar11 < *(int *)(param_1 + 0x10));
  }
  return piVar6;
}

/* TIntermediate__addLoop @ 0x97b902c4 (140 bytes) */
int TIntermediate__addLoop(this, param_1, param_2, param_3, param_4, param_5)
  unsigned char *this;
  unsigned char *param_1;
  unsigned char *param_2;
  unsigned char *param_3;
  int param_4;
  int param_5;
{
  undefined *puVar1;
  ulong uVar2;
  undefined4 *puVar3;
  undefined3 in_register_0000001c;
  code *pcVar4;
  
  uVar2 = GetGlobalPoolAllocator();
  puVar3 = (undefined4 *)TPoolAllocator__allocate(uVar2);
  puVar1 = PTR_vtable_a7b7c0c4;
  puVar3[1] = 0;
  puVar3[2] = param_1;
  pcVar4 = *(code **)(puVar1 + 0xc);
  puVar3[3] = param_2;
  puVar3[4] = param_3;
  puVar3[5] = CONCAT31(in_register_0000001c,param_4);
  *puVar3 = puVar1 + 8;
  (*pcVar4)(puVar3,param_5);
  return puVar3;
}

/* TIntermediate__addBranch @ 0x97b90350 (12 bytes) */
int TIntermediate__addBranch(this, param_2, param_3)
  unsigned char *this;
  undefined4 param_2;
  undefined4 param_3;
{
  addBranch(this,param_2,0,param_3);
  return;
}

/* TIntermediate__addBranch_97b9035c @ 0x97b9035c (124 bytes) */
int TIntermediate__addBranch_97b9035c(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined *puVar1;
  ulong uVar2;
  undefined4 *puVar3;
  code *pcVar4;
  
  uVar2 = GetGlobalPoolAllocator();
  puVar3 = (undefined4 *)TPoolAllocator__allocate(uVar2);
  puVar1 = PTR_vtable_a7b7c0c0;
  puVar3[1] = 0;
  puVar3[2] = param_2;
  pcVar4 = *(code **)(puVar1 + 0xc);
  puVar3[3] = param_3;
  *puVar3 = puVar1 + 8;
  (*pcVar4)(puVar3,param_4);
  return puVar3;
}

/* TIntermediate__postProcess @ 0x97b903d8 (96 bytes) */
int TIntermediate__postProcess(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  int *piVar1;
  
  if (((param_2 != (int *)0x0) &&
      (piVar1 = (int *)(**(code **)(*param_2 + 0x1c))(), piVar1 != (int *)0x0)) &&
     (piVar1[0xc] == 0)) {
    (**(code **)(*piVar1 + 0x60))(piVar1,1);
  }
  return 1;
}

/* TIntermediate__remove @ 0x97b90438 (12 bytes) */
int TIntermediate__remove(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  if (param_1 == (unsigned char *)0x0) {
    return;
  }
  RemoveAllTreeNodes(param_1);
  return;
}

/* TIntermOperator__modifiesState @ 0x97b90444 (48 bytes) */
int TIntermOperator__modifiesState(this)
  unsigned char *this;
{
  int iVar1;
  
  iVar1 = *(int *)(this + 0x30);
  if ((8 < iVar1) && ((iVar1 < 0xd || (iVar1 - 0x76U < 0xf)))) {
    return 1;
  }
  return 0;
}

/* TIntermOperator__isConstructor @ 0x97b90474 (24 bytes) */
int TIntermOperator__isConstructor(this)
  unsigned char *this;
{
  return *(int *)(this + 0x30) - 0x66U < 0x10;
}

/* TIntermUnary__promote @ 0x97b9048c (304 bytes) */
int TIntermUnary__promote(param_1)
  unsigned char *param_1;
{
  bool bVar1;
  int iVar2;
  undefined1 local_40 [56];
  
  iVar2 = *(int *)(param_1 + 0x30);
  if (iVar2 == 8) {
    iVar2 = (**(code **)(**(int **)(param_1 + 0x34) + 0x40))();
    bVar1 = iVar2 == 2;
LAB_97b9055c:
    if (!bVar1) {
      return 0;
    }
  }
  else {
    if (iVar2 < 9) {
      if (iVar2 == 6) {
        iVar2 = (**(code **)(**(int **)(param_1 + 0x34) + 0x40))();
        bVar1 = iVar2 == 3;
        goto LAB_97b9055c;
      }
      if (6 < iVar2) {
        return 1;
      }
      if (iVar2 != 5) goto LAB_97b90544;
    }
    else if (0xc < iVar2) {
      if (iVar2 - 0x57U < 2) {
        return 1;
      }
LAB_97b90544:
      iVar2 = (**(code **)(**(int **)(param_1 + 0x34) + 0x40))();
      bVar1 = iVar2 == 1;
      goto LAB_97b9055c;
    }
    iVar2 = (**(code **)(**(int **)(param_1 + 0x34) + 0x40))();
    if (iVar2 == 3) {
      return 0;
    }
  }
  (**(code **)(**(int **)(param_1 + 0x34) + 0x38))(local_40);
  (**(code **)(*(int *)param_1 + 0x34))(param_1,local_40);
  return 1;
}

/* TIntermBinary__promote @ 0x97b905bc (3124 bytes) */
int TIntermBinary__promote(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  code *pcVar9;
  undefined **local_a0;
  int local_9c;
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  int local_80;
  uint local_7c;
  undefined1 local_70 [8];
  int local_68;
  uint local_4c;
  
  uVar3 = (**(code **)(**(int **)(this + 0x34) + 0x48))();
  iVar4 = (**(code **)(**(int **)(this + 0x38) + 0x48))();
  if ((int)uVar3 < iVar4) {
    uVar3 = (**(code **)(**(int **)(this + 0x38) + 0x48))();
  }
  uVar5 = (**(code **)(**(int **)(this + 0x34) + 0x40))();
  iVar4 = (**(code **)(**(int **)(this + 0x34) + 0x54))();
  if (iVar4 != 0) {
    return 0;
  }
  local_9c = (**(code **)(**(int **)(this + 0x38) + 0x54))();
  if (local_9c != 0) {
    return 0;
  }
  uVar6 = (**(code **)(**(int **)(this + 0x34) + 0x48))();
  uVar7 = (**(code **)(**(int **)(this + 0x34) + 0x50))();
  local_7c = (uVar7 & 1) << 10 | (uVar6 & 0xff) << 0xb | (uVar5 & 0x3f) << 0x13 | local_7c & 0x1ff;
  local_a0 = &PTR__TType_a7b7cff8;
  local_98 = local_9c;
  local_94 = local_9c;
  local_90 = local_9c;
  local_8c = local_9c;
  local_88 = local_9c;
  local_84 = local_9c;
  local_80 = local_9c;
  (**(code **)(*(int *)this + 0x34))(this,&local_a0);
  local_a0 = &PTR__TType_a7b7cff8;
  if (uVar3 == 1) {
    iVar4 = *(int *)(this + 0x30);
    if (iVar4 < 0x25) {
      if (0x20 < iVar4) {
LAB_97b90770:
        iVar4 = *(int *)this;
        local_7c = local_7c & 0x1801ff;
        goto LAB_97b90850;
      }
      if (0x16 < iVar4) {
        if (iVar4 < 0x1d) {
          iVar4 = (**(code **)(**(int **)(this + 0x34) + 0x40))();
          if (iVar4 != 2) {
            return 0;
          }
          iVar4 = (**(code **)(**(int **)(this + 0x38) + 0x40))();
          bVar1 = iVar4 == 2;
          goto LAB_97b90940;
        }
        if (iVar4 < 0x1f) goto LAB_97b90770;
      }
    }
    else {
      if (iVar4 == 0x2c) {
LAB_97b907c4:
        iVar4 = (**(code **)(**(int **)(this + 0x34) + 0x40))();
        if (iVar4 != 3) {
          return 0;
        }
        iVar4 = (**(code **)(**(int **)(this + 0x38) + 0x40))();
        if (iVar4 != 3) {
          return 0;
        }
        iVar4 = *(int *)this;
        local_7c = local_7c & 0x9ff;
LAB_97b90850:
        local_7c = local_7c | 0x180800;
        local_80 = 0;
        local_84 = 0;
        local_88 = 0;
        local_8c = 0;
        local_90 = 0;
        local_94 = 0;
        local_98 = 0;
        local_9c = 0;
        local_a0 = &PTR__TType_a7b7cff8;
        (**(code **)(iVar4 + 0x34))(this,&local_a0);
        return 1;
      }
      if (iVar4 < 0x2d) {
        if (iVar4 == 0x2a) goto LAB_97b907c4;
      }
      else if (iVar4 - 0x7fU < 6) {
        iVar4 = (**(code **)(**(int **)(this + 0x34) + 0x40))();
        if (iVar4 != 2) {
          return 0;
        }
        iVar4 = (**(code **)(**(int **)(this + 0x38) + 0x40))();
        if (iVar4 != 2) {
          return 0;
        }
      }
    }
    iVar4 = (**(code **)(**(int **)(this + 0x34) + 0x40))();
    iVar8 = (**(code **)(**(int **)(this + 0x38) + 0x40))();
    if (iVar4 != iVar8) {
      return 0;
    }
    iVar4 = (**(code **)(**(int **)(this + 0x34) + 0x50))();
    iVar8 = (**(code **)(**(int **)(this + 0x38) + 0x50))();
    bVar1 = iVar4 == iVar8;
LAB_97b90940:
    if (!bVar1) {
      return 0;
    }
    return 1;
  }
  uVar6 = (**(code **)(**(int **)(this + 0x34) + 0x48))();
  if ((uVar6 != uVar3) && (iVar4 = (**(code **)(**(int **)(this + 0x34) + 0x48))(), iVar4 != 1)) {
    return 0;
  }
  uVar6 = (**(code **)(**(int **)(this + 0x38) + 0x48))();
  if ((uVar6 != uVar3) && (iVar4 = (**(code **)(**(int **)(this + 0x38) + 0x48))(), iVar4 != 1)) {
    return 0;
  }
  switch(*(undefined4 *)(this + 0x30)) {
  case 0x13:
  case 0x14:
  case 0x16:
  case 0x17:
  case 0x77:
  case 0x78:
  case 0x7e:
  case 0x7f:
    goto switchD_97b909e0_caseD_13;
  case 0x15:
    iVar4 = (**(code **)(**(int **)(this + 0x34) + 0x50))();
    if ((iVar4 == 0) && (iVar4 = (**(code **)(**(int **)(this + 0x38) + 0x50))(), iVar4 != 0)) {
      iVar4 = (**(code **)(**(int **)(this + 0x34) + 0x58))();
      if (iVar4 != 0) {
        uVar2 = 0x27;
        goto LAB_97b9100c;
      }
      local_7c = (uVar3 & 0xff) << 0xb | (uVar5 & 0x3f) << 0x13 | local_7c & 0x5ff | 0x400;
      iVar4 = *(int *)this;
      *(undefined4 *)(this + 0x30) = 0x29;
    }
    else {
      iVar4 = (**(code **)(**(int **)(this + 0x34) + 0x50))();
      if ((iVar4 == 0) || (iVar4 = (**(code **)(**(int **)(this + 0x38) + 0x50))(), iVar4 != 0)) {
        iVar4 = (**(code **)(**(int **)(this + 0x34) + 0x50))();
        if (iVar4 != 0) {
          iVar4 = (**(code **)(**(int **)(this + 0x38) + 0x50))();
          uVar2 = 0x56;
          if (iVar4 != 0) goto LAB_97b9100c;
        }
        iVar4 = (**(code **)(**(int **)(this + 0x34) + 0x50))();
        if ((iVar4 != 0) || (iVar4 = (**(code **)(**(int **)(this + 0x38) + 0x50))(), iVar4 != 0)) {
          (*(code *)**(undefined4 **)this)(this);
                    
                    
          uVar2 = (*(code *)(((unsigned char *)0x97b90e00) + (*(unsigned char *)0x97b90e0c)))();
          return uVar2;
        }
        iVar4 = (**(code **)(**(int **)(this + 0x34) + 0x58))();
        if (((iVar4 != 0) && (iVar4 = (**(code **)(**(int **)(this + 0x38) + 0x58))(), iVar4 != 0))
           || ((iVar4 = (**(code **)(**(int **)(this + 0x34) + 0x58))(), iVar4 == 0 &&
               (iVar4 = (**(code **)(**(int **)(this + 0x38) + 0x58))(), iVar4 == 0))))
        goto LAB_97b91520;
        iVar4 = *(int *)this;
        uVar5 = (uVar5 & 0x3f) << 0x13 | local_7c & 0x7ffff;
        uVar2 = 0x26;
      }
      else {
        iVar4 = (**(code **)(**(int **)(this + 0x38) + 0x58))();
        uVar2 = 0x29;
        if (iVar4 == 0) goto LAB_97b9100c;
        iVar4 = *(int *)this;
        uVar5 = (uVar5 & 0x3f) << 0x13 | local_7c & 0x7ffff;
        uVar2 = 0x28;
      }
LAB_97b910f8:
      local_7c = (uVar3 & 0xff) << 0xb | uVar5 & 0xfff801ff;
      *(undefined4 *)(this + 0x30) = uVar2;
    }
    goto LAB_97b914fc;
  default:
    goto switchD_97b909e0_caseD_18;
  case 0x1d:
  case 0x1e:
  case 0x21:
  case 0x22:
  case 0x23:
  case 0x24:
    iVar4 = (**(code **)(**(int **)(this + 0x34) + 0x50))();
    if ((iVar4 != 0) && (iVar4 = (**(code **)(**(int **)(this + 0x38) + 0x58))(), iVar4 != 0)) {
      return 0;
    }
    iVar4 = (**(code **)(**(int **)(this + 0x34) + 0x58))();
    if ((iVar4 != 0) && (iVar4 = (**(code **)(**(int **)(this + 0x38) + 0x50))(), iVar4 != 0)) {
      return 0;
    }
    iVar4 = (**(code **)(**(int **)(this + 0x34) + 0x40))();
    iVar8 = (**(code **)(**(int **)(this + 0x38) + 0x40))();
    if (iVar4 != iVar8) {
      return 0;
    }
    iVar4 = *(int *)this;
    local_7c = local_7c & 0x1801ff | 0x180800;
LAB_97b914fc:
    pcVar9 = *(code **)(iVar4 + 0x34);
    goto LAB_97b91508;
  case 0x76:
    break;
  case 0x79:
    iVar4 = (**(code **)(**(int **)(this + 0x34) + 0x50))();
    if ((iVar4 == 0) && (iVar4 = (**(code **)(**(int **)(this + 0x38) + 0x50))(), iVar4 != 0)) {
      iVar4 = (**(code **)(**(int **)(this + 0x34) + 0x58))();
      if (iVar4 == 0) {
        return 0;
      }
      uVar2 = 0x7a;
    }
    else {
      iVar4 = (**(code **)(**(int **)(this + 0x34) + 0x50))();
      if ((iVar4 == 0) || (iVar4 = (**(code **)(**(int **)(this + 0x38) + 0x50))(), iVar4 != 0)) {
        iVar4 = (**(code **)(**(int **)(this + 0x34) + 0x50))();
        if ((iVar4 == 0) || (iVar4 = (**(code **)(**(int **)(this + 0x38) + 0x50))(), iVar4 == 0)) {
          iVar4 = (**(code **)(**(int **)(this + 0x34) + 0x50))();
          if ((iVar4 != 0) || (iVar4 = (**(code **)(**(int **)(this + 0x38) + 0x50))(), iVar4 != 0))
          {
            (*(code *)**(undefined4 **)this)(this);
                    
                    
            uVar2 = (*(code *)(((unsigned char *)0x97b9116c) + (*(unsigned char *)0x97b91178)))();
            return uVar2;
          }
          iVar4 = (**(code **)(**(int **)(this + 0x34) + 0x58))();
          if (((iVar4 != 0) && (iVar4 = (**(code **)(**(int **)(this + 0x38) + 0x58))(), iVar4 != 0)
              ) || ((iVar4 = (**(code **)(**(int **)(this + 0x34) + 0x58))(), iVar4 == 0 &&
                    (iVar4 = (**(code **)(**(int **)(this + 0x38) + 0x58))(), iVar4 == 0))))
          goto LAB_97b91520;
          iVar4 = (**(code **)(**(int **)(this + 0x34) + 0x58))();
          if (iVar4 == 0) {
            return 0;
          }
          iVar4 = *(int *)this;
          uVar2 = 0x7b;
          uVar5 = (uVar5 & 0x3f) << 0x13 | local_7c & 0x7ffff;
          goto LAB_97b910f8;
        }
        uVar2 = 0x7d;
      }
      else {
        iVar4 = (**(code **)(**(int **)(this + 0x38) + 0x58))();
        if (iVar4 != 0) {
          return 0;
        }
        uVar2 = 0x7c;
      }
    }
LAB_97b9100c:
    *(undefined4 *)(this + 0x30) = uVar2;
    goto LAB_97b91520;
  }
  iVar4 = (**(code **)(**(int **)(this + 0x34) + 0x48))();
  iVar8 = (**(code **)(**(int **)(this + 0x38) + 0x48))();
  if (iVar4 != iVar8) {
    return 0;
  }
switchD_97b909e0_caseD_13:
  iVar4 = (**(code **)(**(int **)(this + 0x34) + 0x50))();
  if (((iVar4 == 0) || (iVar4 = (**(code **)(**(int **)(this + 0x38) + 0x58))(), iVar4 == 0)) &&
     ((iVar4 = (**(code **)(**(int **)(this + 0x34) + 0x58))(), iVar4 == 0 ||
      (iVar4 = (**(code **)(**(int **)(this + 0x38) + 0x50))(), iVar4 == 0)))) {
    iVar4 = (**(code **)(**(int **)(this + 0x34) + 0x40))();
    iVar8 = (**(code **)(**(int **)(this + 0x38) + 0x40))();
    if (iVar4 == iVar8) {
      iVar8 = 0;
      iVar4 = (**(code **)(**(int **)(this + 0x34) + 0x50))();
      if ((iVar4 != 0) || (iVar4 = (**(code **)(**(int **)(this + 0x38) + 0x50))(), iVar4 != 0)) {
        iVar8 = 1;
      }
      local_7c = iVar8 << 10 | (uVar3 & 0xff) << 0xb | (uVar5 & 0x3f) << 0x13 | local_7c & 0x1ff;
      pcVar9 = *(code **)(*(int *)this + 0x34);
LAB_97b91508:
      local_80 = 0;
      local_a0 = &PTR__TType_a7b7cff8;
      local_9c = local_80;
      local_98 = local_80;
      local_94 = local_80;
      local_90 = local_80;
      local_8c = local_80;
      local_88 = local_80;
      local_84 = local_80;
      (*pcVar9)(this,&local_a0);
      local_a0 = &PTR__TType_a7b7cff8;
LAB_97b91520:
      iVar4 = *(int *)(this + 0x30);
      if ((0x75 < iVar4) && ((iVar4 < 0x7a || (iVar4 - 0x7eU < 7)))) {
        (**(code **)(*(int *)this + 0x38))(&local_a0,this);
        (**(code **)(**(int **)(this + 0x34) + 0x38))(local_70);
        bVar1 = false;
        if (((local_7c & 0x1fffe00) == (local_4c & 0x1fffe00)) && (local_98 == local_68)) {
          bVar1 = true;
        }
        if (!bVar1) {
          return 0;
        }
      }
      return 1;
    }
  }
switchD_97b909e0_caseD_18:
  return 0;
}

/* compareStructure @ 0x97b915d4 (336 bytes) */
int compareStructure(param_1, param_2, param_3, param_4)
  unsigned char *param_1;
  unsigned char *param_2;
  unsigned char *param_3;
  int *param_4;
{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  uVar5 = 0;
  iVar6 = *(int *)(param_1 + 8);
  iVar2 = *(int *)(iVar6 + 4);
  uVar4 = *(int *)(iVar6 + 8) - iVar2 >> 3;
  if (uVar4 == 0) {
    return 1;
  }
  do {
    iVar1 = uVar5 * 8;
    iVar7 = 0;
    iVar2 = (**(code **)(**(int **)(iVar2 + iVar1) + 0x30))();
    if (0 < iVar2) {
      do {
        iVar3 = (**(code **)(**(int **)(*(int *)(iVar6 + 4) + iVar1) + 0x20))();
        if (iVar3 == 2) {
LAB_97b916a8:
          iVar3 = *param_4;
          if (*(int *)(param_3 + iVar3 * 4) != *(int *)(param_2 + iVar3 * 4)) {
            return 0;
          }
LAB_97b916c8:
          *param_4 = iVar3 + 1;
        }
        else if (iVar3 < 3) {
          if (iVar3 == 1) {
            iVar3 = *param_4;
            if (*(float *)(param_3 + iVar3 * 4) != *(float *)(param_2 + iVar3 * 4)) {
              return 0;
            }
            goto LAB_97b916c8;
          }
        }
        else {
          if (iVar3 == 3) goto LAB_97b916a8;
          if ((iVar3 == 0xe) &&
             (iVar3 = ((int (*)())compareStructure)(*(TType **)(*(int *)(iVar6 + 4) + iVar1),param_2,param_3,
                                       param_4), iVar3 == 0)) {
            return 0;
          }
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < iVar2);
    }
    uVar5 = uVar5 + 1;
    if (uVar4 <= uVar5) {
      return 1;
    }
    iVar2 = *(int *)(iVar6 + 4);
  } while( true );
}

/* TIntermConstantUnion__fold @ 0x97b91724 (11632 bytes) */
int TIntermConstantUnion__fold(this, param_2, param_3, param_4, param_5)
  unsigned char *this;
  int param_2;
  unsigned char *param_3;
  undefined4 param_4;
  int param_5;
{
  bool bVar1;
  uint uVar2;
  float fVar3;
  uint uVar4;
  float fVar5;
  uint uVar6;
  uint uVar7;
  constUnion *pcVar8;
  uint uVar9;
  undefined4 *puVar10;
  int iVar11;
  int iVar12;
  TIntermConstantUnion *pTVar13;
  int *piVar14;
  uint *puVar15;
  ulong uVar16;
  undefined4 uVar17;
  int iVar18;
  float *pfVar19;
  int iVar20;
  undefined *puVar21;
  float *pfVar22;
  constUnion *pcVar23;
  int iVar24;
  undefined **ppuVar25;
  int iVar26;
  bool bVar27;
  int iVar28;
  double dVar29;
  double dVar30;
  undefined **local_1d0;
  int local_1cc;
  int local_1c8;
  int local_1c4;
  int local_1c0;
  int local_1bc;
  int local_1b8;
  int local_1b4;
  int local_1b0;
  uint local_1ac;
  int local_1a0;
  int local_19c;
  int local_198;
  int local_194;
  int local_190;
  int local_18c;
  int local_188;
  int local_184;
  int local_180;
  uint local_17c;
  undefined **local_170;
  int local_16c;
  int local_168;
  int local_164;
  int local_160;
  int local_15c;
  int local_158;
  int local_154;
  int local_150;
  uint local_14c;
  undefined **local_140 [9];
  uint local_11c;
  undefined **local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  uint local_ec;
  int local_50;
  int local_4c;
  
  pcVar23 = *(constUnion **)(this + 0x30);
  if (param_3 == (unsigned char *)0x0) {
    iVar26 = 0;
    (**(code **)(*(int *)this + 0x4c))();
    uVar16 = GetGlobalPoolAllocator();
    pfVar22 = (float *)TPoolAllocator__allocate(uVar16);
    iVar11 = (**(code **)(*(int *)this + 0x4c))(this);
    if (1 < iVar11) {
      for (; iVar11 = (**(code **)(*(int *)this + 0x4c))(this), iVar26 < iVar11; iVar26 = iVar26 + 1
          ) {
        if (param_2 == 5) {
          (**(code **)(*(int *)this + 0x38))(&local_1d0,this);
          uVar4 = local_1ac >> 0x13 & 0x3f;
          local_1d0 = &PTR__TType_a7b7cff8;
          if (uVar4 != 1) {
            if (uVar4 != 2) {
              (*(code *)**(undefined4 **)this)(this);
                    
                    
              pTVar13 = (unsigned char *)(*(code *)(((unsigned char *)0x97b95644) + (*(unsigned char *)0x97b95650)))();
              return pTVar13;
            }
            fVar5 = (float)-*(int *)(pcVar23 + iVar26 * 4);
            goto LAB_97b956a0;
          }
          pfVar22[iVar26] = -*(float *)(pcVar23 + iVar26 * 4);
        }
        else {
          if (param_2 != 6) {
            return (unsigned char *)0x0;
          }
          (**(code **)(*(int *)this + 0x38))(&local_1d0,this);
          local_1d0 = &PTR__TType_a7b7cff8;
          if ((local_1ac >> 0x13 & 0x3f) != 3) {
            (*(code *)**(undefined4 **)this)(this);
                    
                    
            pTVar13 = (unsigned char *)(*(code *)(((unsigned char *)0x97b956e0) + (*(unsigned char *)0x97b956ec)))();
            return pTVar13;
          }
          fVar5 = (float)(*(uint *)(pcVar23 + iVar26 * 4) ^ 1);
LAB_97b956a0:
          pfVar22[iVar26] = fVar5;
        }
        local_1d0 = &PTR__TType_a7b7cff8;
      }
      uVar16 = GetGlobalPoolAllocator();
      pTVar13 = (unsigned char *)TPoolAllocator__allocate(uVar16);
      (**(code **)(*(int *)this + 0x38))(&local_1d0,this);
      *(int *)(pTVar13 + 4) = 0;
      *(undefined ***)pTVar13 = &PTR_getLine_a7b7cf90;
      *(int *)(pTVar13 + 0xc) = local_1cc;
      *(int *)(pTVar13 + 0x10) = local_1c8;
      *(int *)(pTVar13 + 0x14) = local_1c4;
      *(int *)(pTVar13 + 0x18) = local_1c0;
      *(int *)(pTVar13 + 0x1c) = local_1bc;
      *(int *)(pTVar13 + 0x20) = local_1b8;
      *(undefined ***)(pTVar13 + 8) = &PTR__TType_a7b7cff8;
      *(int *)(pTVar13 + 0x24) = local_1b4;
      *(int *)(pTVar13 + 0x28) = local_1b0;
      uVar6 = *(uint *)(pTVar13 + 0x2c);
      uVar9 = local_1ac & 0xfe000000;
      *(uint *)(pTVar13 + 0x2c) = uVar9 | uVar6 & 0x1ffffff;
      uVar7 = (local_1ac >> 0x13 & 0x3f) << 0x13;
      *(uint *)(pTVar13 + 0x2c) = uVar7 | uVar9 | uVar6 & 0x7ffff;
      uVar4 = local_1ac & 0x7f800;
      *(uint *)(pTVar13 + 0x2c) = uVar4 | uVar7 | uVar9 | uVar6 & 0x7ff;
      uVar2 = (local_1ac >> 10 & 1) << 10;
      *(uint *)(pTVar13 + 0x2c) = uVar2 | uVar4 | uVar7 | uVar9 | uVar6 & 0x3ff;
      puVar21 = PTR_vtable_a7b7c0c8;
      *(uint *)(pTVar13 + 0x2c) =
           (local_1ac >> 9 & 1) << 9 | uVar2 | uVar4 | uVar7 | uVar9 | uVar6 & 0x1ff;
      *(float **)(pTVar13 + 0x30) = pfVar22;
      *(undefined **)pTVar13 = puVar21 + 8;
      goto LAB_97b95bbc;
    }
    if (param_2 == 5) {
      (**(code **)(*(int *)this + 0x38))(&local_1d0,this);
      uVar4 = local_1ac >> 0x13 & 0x3f;
      local_1d0 = &PTR__TType_a7b7cff8;
      if (uVar4 != 1) {
        if (uVar4 != 2) {
                    
                    
          pTVar13 = (unsigned char *)(*(code *)(((unsigned char *)0x97b958f4) + (*(unsigned char *)0x97b95900)))();
          return pTVar13;
        }
        *pfVar22 = (float)-**(int **)(this + 0x30);
        uVar16 = GetGlobalPoolAllocator();
        pTVar13 = (unsigned char *)TPoolAllocator__allocate(uVar16);
        iVar11 = 2;
        goto LAB_97b9596c;
      }
      *pfVar22 = -**(float **)(this + 0x30);
      uVar16 = GetGlobalPoolAllocator();
      pTVar13 = (unsigned char *)TPoolAllocator__allocate(uVar16);
      uVar4 = local_1ac & 0x7ff | 0x4080000;
    }
    else {
      if (param_2 != 6) {
        return (unsigned char *)0x0;
      }
      (**(code **)(*(int *)this + 0x38))(&local_1d0,this);
      local_1d0 = &PTR__TType_a7b7cff8;
      if ((local_1ac >> 0x13 & 0x3f) != 3) {
                    
                    
        pTVar13 = (unsigned char *)(*(code *)(((unsigned char *)0x97b95a98) + (*(unsigned char *)0x97b95aa4)))();
        return pTVar13;
      }
      *pfVar22 = (float)(**(uint **)(this + 0x30) ^ 1);
      uVar16 = GetGlobalPoolAllocator();
      pTVar13 = (unsigned char *)TPoolAllocator__allocate(uVar16);
      iVar11 = 3;
LAB_97b9596c:
      uVar4 = iVar11 << 0x13 | local_1ac & 0xfff | 0x4000000;
    }
    local_1ac = uVar4 & 0xfffff9ff | 0x800;
    local_1cc = 0;
    local_1c8 = 0;
    local_1c4 = 0;
    local_1c0 = 0;
    local_1bc = 0;
    local_1b8 = 0;
    local_1b4 = 0;
    local_1b0 = 0;
    *(int *)(pTVar13 + 4) = 0;
    *(undefined ***)pTVar13 = &PTR_getLine_a7b7cf90;
    *(int *)(pTVar13 + 0xc) = 0;
    *(int *)(pTVar13 + 0x10) = 0;
    *(int *)(pTVar13 + 0x14) = 0;
    *(int *)(pTVar13 + 0x18) = 0;
    *(int *)(pTVar13 + 0x1c) = 0;
    *(int *)(pTVar13 + 0x20) = 0;
    *(undefined ***)(pTVar13 + 8) = &PTR__TType_a7b7cff8;
    *(int *)(pTVar13 + 0x24) = 0;
    *(int *)(pTVar13 + 0x28) = 0;
    uVar7 = *(uint *)(pTVar13 + 0x2c);
    uVar9 = uVar4 & 0xfe000000;
    *(uint *)(pTVar13 + 0x2c) = uVar9 | uVar7 & 0x1ffffff;
    uVar4 = (uVar4 >> 0x13 & 0x3f) << 0x13;
    *(uint *)(pTVar13 + 0x2c) = uVar4 | uVar9 | uVar7 & 0x7ffff;
    *(uint *)(pTVar13 + 0x2c) = uVar4 | uVar9 | uVar7 & 0x7ff | 0x800;
    *(uint *)(pTVar13 + 0x2c) = uVar4 | uVar9 | uVar7 & 0x3ff | 0x800;
    puVar21 = PTR_vtable_a7b7c0c8;
    *(uint *)(pTVar13 + 0x2c) = uVar4 | uVar9 | uVar7 & 0x1ff | 0x800;
    *(float **)(pTVar13 + 0x30) = pfVar22;
    *(undefined **)pTVar13 = puVar21 + 8;
LAB_97b95bbc:
    local_1d0 = &PTR__TType_a7b7cff8;
    iVar11 = *(int *)pTVar13;
    uVar17 = (*(code *)**(undefined4 **)this)(this);
    (**(code **)(iVar11 + 4))(pTVar13,uVar17);
    return pTVar13;
  }
  bVar27 = false;
  iVar11 = (**(code **)(*(int *)param_3 + 0x18))(param_3);
  if ((iVar11 != 0) && (iVar11 = (**(code **)(*(int *)param_3 + 0x4c))(param_3), iVar11 == 1)) {
    (**(code **)(*(int *)param_3 + 0x38))(&local_1d0,param_3);
    if (((local_1ac >> 0x13 & 0x3f) != 0xe) &&
       (iVar11 = (**(code **)(*(int *)this + 0x4c))(this), 1 < iVar11)) {
      bVar27 = true;
    }
    local_4c = -0x5847e8cc;
    local_1d0 = &PTR__TType_a7b7cff8;
    if (bVar27) {
      iVar11 = (**(code **)(*(int *)param_3 + 0x18))(param_3);
      switch(param_2) {
      case 0x13:
        local_4c = -0x5847e8cc;
        (**(code **)(*(int *)this + 0x4c))(this);
        uVar16 = GetGlobalPoolAllocator();
        iVar26 = TPoolAllocator__allocate(uVar16);
        for (iVar24 = 0; iVar12 = (**(code **)(*(int *)this + 0x4c))(this), iVar24 < iVar12;
            iVar24 = iVar24 + 1) {
          (**(code **)(*(int *)this + 0x38))(&local_1a0,this);
          uVar4 = local_17c >> 0x13 & 0x3f;
          local_1a0 = local_4c + -0x473c;
          if (uVar4 == 1) {
            *(float *)(iVar26 + iVar24 * 4) =
                 *(float *)(pcVar23 + iVar24 * 4) + **(float **)(iVar11 + 0x30);
          }
          else {
            if (uVar4 != 2) {
              (*(code *)**(undefined4 **)this)(this);
                    
                    
              pTVar13 = (unsigned char *)(*(code *)(((unsigned char *)0x97b91990) + (*(unsigned char *)0x97b9199c)))();
              return pTVar13;
            }
            *(int *)(iVar24 * 4 + iVar26) =
                 *(int *)(pcVar23 + iVar24 * 4) + **(int **)(iVar11 + 0x30);
          }
        }
        break;
      case 0x14:
        local_4c = -0x5847e8cc;
        (**(code **)(*(int *)this + 0x4c))(this);
        uVar16 = GetGlobalPoolAllocator();
        iVar26 = TPoolAllocator__allocate(uVar16);
        for (iVar24 = 0; iVar12 = (**(code **)(*(int *)this + 0x4c))(this), iVar24 < iVar12;
            iVar24 = iVar24 + 1) {
          (**(code **)(*(int *)this + 0x38))(&local_1a0,this);
          uVar4 = local_17c >> 0x13 & 0x3f;
          local_1a0 = local_4c + -0x473c;
          if (uVar4 == 1) {
            if (param_5 == 0) {
              fVar5 = *(float *)(pcVar23 + iVar24 * 4);
              fVar3 = **(float **)(iVar11 + 0x30);
            }
            else {
              fVar3 = *(float *)(pcVar23 + iVar24 * 4);
              fVar5 = **(float **)(iVar11 + 0x30);
            }
            *(float *)(iVar26 + iVar24 * 4) = fVar3 - fVar5;
          }
          else {
            if (uVar4 != 2) {
              (*(code *)**(undefined4 **)this)(this);
                    
                    
              pTVar13 = (unsigned char *)(*(code *)(((unsigned char *)0x97b91cdc) + (*(unsigned char *)0x97b91ce8)))();
              return pTVar13;
            }
            if (param_5 == 0) {
              iVar12 = **(int **)(iVar11 + 0x30) - *(int *)(pcVar23 + iVar24 * 4);
            }
            else {
              iVar12 = *(int *)(pcVar23 + iVar24 * 4) - **(int **)(iVar11 + 0x30);
            }
            *(int *)(iVar24 * 4 + iVar26) = iVar12;
          }
        }
        break;
      default:
        (*(code *)**(undefined4 **)this)(this);
                    
                    
        pTVar13 = (unsigned char *)(*(code *)(((unsigned char *)0x97b92890) + (*(unsigned char *)0x97b9289c)))();
        return pTVar13;
      case 0x16:
        local_4c = -0x5847e8cc;
        (**(code **)(*(int *)this + 0x4c))(this);
        uVar16 = GetGlobalPoolAllocator();
        iVar26 = TPoolAllocator__allocate(uVar16);
        for (iVar24 = 0; iVar12 = (**(code **)(*(int *)this + 0x4c))(this), iVar24 < iVar12;
            iVar24 = iVar24 + 1) {
          (**(code **)(*(int *)this + 0x38))(&local_1a0,this);
          uVar4 = local_17c >> 0x13 & 0x3f;
          local_1a0 = local_4c + -0x473c;
          if (uVar4 == 1) {
            if (param_5 == 0) {
              if ((double)*(float *)(pcVar23 + iVar24 * 4) == DOUBLE_97c30a48) {
                (*(code *)**(undefined4 **)this)(this);
                    
                    
                pTVar13 = (unsigned char *)(*(code *)(((unsigned char *)0x97b91f80) + (*(unsigned char *)0x97b91f84)))();
                return pTVar13;
              }
              *(float *)(iVar24 * 4 + iVar26) =
                   (float)((double)**(float **)(iVar11 + 0x30) /
                          (double)*(float *)(pcVar23 + iVar24 * 4));
            }
            else {
              if ((double)**(float **)(iVar11 + 0x30) == DOUBLE_97c30a48) {
                (*(code *)**(undefined4 **)this)(this);
                    
                    
                pTVar13 = (unsigned char *)(*(code *)(((unsigned char *)0x97b91df0) + (*(unsigned char *)0x97b91df4)))();
                return pTVar13;
              }
              *(float *)(iVar26 + iVar24 * 4) =
                   (float)((double)*(float *)(pcVar23 + iVar24 * 4) /
                          (double)**(float **)(iVar11 + 0x30));
            }
          }
          else {
            if (uVar4 != 2) {
              (*(code *)**(undefined4 **)this)(this);
                    
                    
              pTVar13 = (unsigned char *)(*(code *)(((unsigned char *)0x97b92408) + (*(unsigned char *)0x97b92414)))();
              return pTVar13;
            }
            if (param_5 == 0) {
              if (*(int *)(pcVar23 + iVar24 * 4) == 0) {
                (*(code *)**(undefined4 **)this)(this);
                    
                    
                pTVar13 = (unsigned char *)(*(code *)(((unsigned char *)0x97b92294) + (*(unsigned char *)0x97b92298)))();
                return pTVar13;
              }
              *(int *)(iVar24 * 4 + iVar26) =
                   **(int **)(iVar11 + 0x30) / *(int *)(pcVar23 + iVar24 * 4);
            }
            else {
              if (**(int **)(iVar11 + 0x30) == 0) {
                (*(code *)**(undefined4 **)this)(this);
                    
                    
                pTVar13 = (unsigned char *)(*(code *)(((unsigned char *)0x97b9210c) + (*(unsigned char *)0x97b92110)))();
                return pTVar13;
              }
              *(int *)(iVar24 * 4 + iVar26) =
                   *(int *)(pcVar23 + iVar24 * 4) / **(int **)(iVar11 + 0x30);
            }
          }
        }
        break;
      case 0x26:
      case 0x29:
        local_4c = -0x5847e8cc;
        (**(code **)(*(int *)this + 0x4c))(this);
        uVar16 = GetGlobalPoolAllocator();
        iVar26 = TPoolAllocator__allocate(uVar16);
        for (iVar24 = 0; iVar12 = (**(code **)(*(int *)this + 0x4c))(this), iVar24 < iVar12;
            iVar24 = iVar24 + 1) {
          (**(code **)(*(int *)this + 0x38))(&local_1a0,this);
          uVar4 = local_17c >> 0x13 & 0x3f;
          local_1a0 = local_4c + -0x473c;
          if (uVar4 == 1) {
            *(float *)(iVar26 + iVar24 * 4) =
                 *(float *)(pcVar23 + iVar24 * 4) * **(float **)(iVar11 + 0x30);
          }
          else {
            if (uVar4 != 2) {
              (*(code *)**(undefined4 **)this)(this);
                    
                    
              pTVar13 = (unsigned char *)(*(code *)(((unsigned char *)0x97b91abc) + (*(unsigned char *)0x97b91ac8)))();
              return pTVar13;
            }
            *(int *)(iVar24 * 4 + iVar26) =
                 *(int *)(pcVar23 + iVar24 * 4) * **(int **)(iVar11 + 0x30);
          }
        }
        break;
      case 0x2a:
        local_4c = -0x5847e8cc;
        (**(code **)(*(int *)this + 0x4c))(this);
        uVar16 = GetGlobalPoolAllocator();
        iVar26 = TPoolAllocator__allocate(uVar16);
        for (iVar24 = 0; iVar12 = (**(code **)(*(int *)this + 0x4c))(this), iVar24 < iVar12;
            iVar24 = iVar24 + 1) {
          (**(code **)(*(int *)this + 0x38))(&local_1a0,this);
          local_1a0 = local_4c + -0x473c;
          if ((local_17c >> 0x13 & 0x3f) != 3) {
            (*(code *)**(undefined4 **)this)(this);
                    
                    
            pTVar13 = (unsigned char *)(*(code *)(((unsigned char *)0x97b92744) + (*(unsigned char *)0x97b92750)))();
            return pTVar13;
          }
          uVar17 = 0;
          if ((*(int *)(pcVar23 + iVar24 * 4) != 0) || (**(int **)(iVar11 + 0x30) != 0)) {
            uVar17 = 1;
          }
          *(undefined4 *)(iVar24 * 4 + iVar26) = uVar17;
        }
        break;
      case 0x2b:
        local_4c = -0x5847e8cc;
        (**(code **)(*(int *)this + 0x4c))(this);
        uVar16 = GetGlobalPoolAllocator();
        iVar26 = TPoolAllocator__allocate(uVar16);
        for (iVar24 = 0; iVar12 = (**(code **)(*(int *)this + 0x4c))(this), iVar24 < iVar12;
            iVar24 = iVar24 + 1) {
          (**(code **)(*(int *)this + 0x38))(&local_1a0,this);
          local_1a0 = local_4c + -0x473c;
          if ((local_17c >> 0x13 & 0x3f) != 3) {
            (*(code *)**(undefined4 **)this)(this);
                    
                    
            pTVar13 = (unsigned char *)(*(code *)(((unsigned char *)0x97b9260c) + (*(unsigned char *)0x97b92618)))();
            return pTVar13;
          }
          *(uint *)(iVar24 * 4 + iVar26) =
               (uint)(*(int *)(pcVar23 + iVar24 * 4) != **(int **)(iVar11 + 0x30));
        }
        break;
      case 0x2c:
        local_4c = -0x5847e8cc;
        (**(code **)(*(int *)this + 0x4c))(this);
        uVar16 = GetGlobalPoolAllocator();
        iVar26 = TPoolAllocator__allocate(uVar16);
        for (iVar24 = 0; iVar12 = (**(code **)(*(int *)this + 0x4c))(this), iVar24 < iVar12;
            iVar24 = iVar24 + 1) {
          (**(code **)(*(int *)this + 0x38))(&local_1a0,this);
          local_1a0 = local_4c + -0x473c;
          if ((local_17c >> 0x13 & 0x3f) != 3) {
            (*(code *)**(undefined4 **)this)(this);
                    
                    
            pTVar13 = (unsigned char *)(*(code *)(((unsigned char *)0x97b92520) + (*(unsigned char *)0x97b9252c)))();
            return pTVar13;
          }
          uVar17 = 0;
          if ((*(int *)(pcVar23 + iVar24 * 4) != 0) && (**(int **)(iVar11 + 0x30) != 0)) {
            uVar17 = 1;
          }
          *(undefined4 *)(iVar24 * 4 + iVar26) = uVar17;
        }
      }
      uVar16 = GetGlobalPoolAllocator();
      pTVar13 = (unsigned char *)TPoolAllocator__allocate(uVar16);
      (**(code **)(*(int *)this + 0x38))(&local_1a0,this);
      *(int *)(pTVar13 + 4) = 0;
      *(undefined ***)pTVar13 = &PTR_getLine_a7b7cf90;
      *(int *)(pTVar13 + 0xc) = local_19c;
      local_1a0 = local_4c + -0x473c;
      *(int *)(pTVar13 + 0x10) = local_198;
      *(int *)(pTVar13 + 0x14) = local_194;
      *(int *)(pTVar13 + 0x18) = local_190;
      *(int *)(pTVar13 + 0x1c) = local_18c;
      *(int *)(pTVar13 + 0x20) = local_188;
      *(int *)(pTVar13 + 8) = local_1a0;
      *(int *)(pTVar13 + 0x24) = local_184;
      *(int *)(pTVar13 + 0x28) = local_180;
      uVar6 = *(uint *)(pTVar13 + 0x2c);
      uVar9 = local_17c & 0xfe000000;
      *(uint *)(pTVar13 + 0x2c) = uVar9 | uVar6 & 0x1ffffff;
      uVar7 = (local_17c >> 0x13 & 0x3f) << 0x13;
      *(uint *)(pTVar13 + 0x2c) = uVar7 | uVar9 | uVar6 & 0x7ffff;
      uVar4 = local_17c & 0x7f800;
      *(uint *)(pTVar13 + 0x2c) = uVar4 | uVar7 | uVar9 | uVar6 & 0x7ff;
      uVar2 = (local_17c >> 10 & 1) << 10;
      *(uint *)(pTVar13 + 0x2c) = uVar2 | uVar4 | uVar7 | uVar9 | uVar6 & 0x3ff;
      puVar21 = PTR_vtable_a7b7c0c8;
      *(uint *)(pTVar13 + 0x2c) =
           (local_17c >> 9 & 1) << 9 | uVar2 | uVar4 | uVar7 | uVar9 | uVar6 & 0x1ff;
      *(undefined **)pTVar13 = puVar21 + 8;
      *(int *)(pTVar13 + 0x30) = iVar26;
      goto LAB_97b94758;
    }
  }
  iVar11 = (**(code **)(*(int *)param_3 + 0x18))(param_3);
  if (iVar11 != 0) {
    iVar11 = (**(code **)(*(int *)this + 0x4c))(this);
    if (iVar11 < 2) {
      local_4c = -0x5847e8cc;
      (**(code **)(*(int *)this + 0x38))(&local_1a0,this);
      local_1a0 = local_4c + -0x473c;
      if ((local_17c >> 0x13 & 0x3f) != 0xe) goto LAB_97b9478c;
    }
    iVar11 = 0;
    bVar27 = false;
    piVar14 = (int *)(**(code **)(*(int *)param_3 + 0x18))(param_3);
    pfVar22 = (float *)piVar14[0xc];
    local_50 = 0;
    switch(param_2) {
    case 0x13:
      local_4c = -0x5847e8cc;
      (**(code **)(*(int *)this + 0x4c))(this);
      uVar16 = GetGlobalPoolAllocator();
      iVar11 = TPoolAllocator__allocate(uVar16);
      for (iVar26 = 0; iVar24 = (**(code **)(*(int *)this + 0x4c))(this), iVar26 < iVar24;
          iVar26 = iVar26 + 1) {
        (**(code **)(*(int *)this + 0x38))(&local_170,this);
        uVar4 = local_14c >> 0x13 & 0x3f;
        local_170 = (undefined **)(local_4c + -0x473c);
        if (uVar4 == 1) {
          *(float *)(iVar11 + iVar26 * 4) = *(float *)(pcVar23 + iVar26 * 4) + pfVar22[iVar26];
        }
        else {
          if (uVar4 != 2) {
            (*(code *)**(undefined4 **)this)(this);
                    
                    
            pTVar13 = (unsigned char *)(*(code *)(((unsigned char *)0x97b92d3c) + (*(unsigned char *)0x97b92d48)))();
            return pTVar13;
          }
          *(int *)(iVar11 + iVar26 * 4) = *(int *)(pcVar23 + iVar26 * 4) + (int)pfVar22[iVar26];
        }
      }
      break;
    case 0x14:
      local_4c = -0x5847e8cc;
      (**(code **)(*(int *)this + 0x4c))(this);
      uVar16 = GetGlobalPoolAllocator();
      iVar11 = TPoolAllocator__allocate(uVar16);
      for (iVar26 = 0; iVar24 = (**(code **)(*(int *)this + 0x4c))(this), iVar26 < iVar24;
          iVar26 = iVar26 + 1) {
        (**(code **)(*(int *)this + 0x38))(&local_170,this);
        uVar4 = local_14c >> 0x13 & 0x3f;
        local_170 = (undefined **)(local_4c + -0x473c);
        if (uVar4 == 1) {
          if (param_5 == 0) {
            fVar5 = pfVar22[iVar26];
            fVar3 = *(float *)(pcVar23 + iVar26 * 4);
          }
          else {
            fVar5 = *(float *)(pcVar23 + iVar26 * 4);
            fVar3 = pfVar22[iVar26];
          }
          *(float *)(iVar11 + iVar26 * 4) = fVar5 - fVar3;
        }
        else {
          if (uVar4 != 2) {
            (*(code *)**(undefined4 **)this)(this);
                    
                    
            pTVar13 = (unsigned char *)(*(code *)(((unsigned char *)0x97b92f10) + (*(unsigned char *)0x97b92f1c)))();
            return pTVar13;
          }
          if (param_5 == 0) {
            fVar5 = pfVar22[iVar26];
            fVar3 = *(float *)(pcVar23 + iVar26 * 4);
          }
          else {
            fVar5 = *(float *)(pcVar23 + iVar26 * 4);
            fVar3 = pfVar22[iVar26];
          }
          *(int *)(iVar11 + iVar26 * 4) = (int)fVar5 - (int)fVar3;
        }
      }
      break;
    case 0x15:
      iVar26 = (**(code **)(*(int *)this + 0x58))(this);
      if (iVar26 != 0) {
        iVar24 = 0;
        iVar26 = (**(code **)(*(int *)this + 0x4c))(this);
        uVar16 = GetGlobalPoolAllocator();
        iVar11 = TPoolAllocator__allocate(uVar16);
        if (0 < iVar26) {
          local_4c = -0x5847e8cc;
          do {
            (**(code **)(*(int *)this + 0x38))(&local_170,this);
            uVar4 = local_14c >> 0x13 & 0x3f;
            local_170 = (undefined **)(local_4c + -0x473c);
            if (uVar4 == 1) {
              *(float *)(iVar11 + iVar24 * 4) = *(float *)(pcVar23 + iVar24 * 4) * pfVar22[iVar24];
            }
            else {
              if (uVar4 != 2) {
                (*(code *)**(undefined4 **)this)(this);
                    
                    
                pTVar13 = (unsigned char *)(*(code *)(((unsigned char *)0x97b930d8) + (*(unsigned char *)0x97b930e4)))();
                return pTVar13;
              }
              *(int *)(iVar11 + iVar24 * 4) = *(int *)(pcVar23 + iVar24 * 4) * (int)pfVar22[iVar24];
            }
            iVar24 = iVar24 + 1;
          } while (iVar24 < iVar26);
          break;
        }
      }
      local_4c = -0x5847e8cc;
      break;
    case 0x16:
      local_4c = -0x5847e8cc;
      (**(code **)(*(int *)this + 0x4c))(this);
      uVar16 = GetGlobalPoolAllocator();
      iVar11 = TPoolAllocator__allocate(uVar16);
      for (iVar26 = 0; iVar24 = (**(code **)(*(int *)this + 0x4c))(this), iVar26 < iVar24;
          iVar26 = iVar26 + 1) {
        (**(code **)(*(int *)this + 0x38))(&local_170,this);
        uVar4 = local_14c >> 0x13 & 0x3f;
        local_170 = (undefined **)(local_4c + -0x473c);
        if (uVar4 == 1) {
          if (param_5 == 0) {
            dVar29 = (double)*(float *)(pcVar23 + iVar26 * 4);
            if (dVar29 == DOUBLE_97c30a48) {
              (*(code *)**(undefined4 **)this)(this);
                    
                    
              pTVar13 = (unsigned char *)(*(code *)(((unsigned char *)0x97b9351c) + (*(unsigned char *)0x97b93520)))();
              return pTVar13;
            }
            fVar5 = pfVar22[iVar26];
          }
          else {
            dVar29 = (double)pfVar22[iVar26];
            if (dVar29 == DOUBLE_97c30a48) {
              (*(code *)**(undefined4 **)this)(this);
                    
                    
              pTVar13 = (unsigned char *)(*(code *)(((unsigned char *)0x97b934ac) + (*(unsigned char *)0x97b934b0)))();
              return pTVar13;
            }
            fVar5 = *(float *)(pcVar23 + iVar26 * 4);
          }
          *(float *)(iVar26 * 4 + iVar11) = (float)((double)fVar5 / dVar29);
        }
        else {
          if (uVar4 != 2) {
            (*(code *)**(undefined4 **)this)(this);
                    
                    
            pTVar13 = (unsigned char *)(*(code *)(((unsigned char *)0x97b9386c) + (*(unsigned char *)0x97b93878)))();
            return pTVar13;
          }
          if (param_5 == 0) {
            fVar5 = *(float *)(pcVar23 + iVar26 * 4);
            if (fVar5 == 0.0) {
              (*(code *)**(undefined4 **)this)(this);
                    
                    
              pTVar13 = (unsigned char *)(*(code *)(((unsigned char *)0x97b93704) + (*(unsigned char *)0x97b93708)))();
              return pTVar13;
            }
            fVar3 = pfVar22[iVar26];
          }
          else {
            fVar5 = pfVar22[iVar26];
            if (fVar5 == 0.0) {
              (*(code *)**(undefined4 **)this)(this);
                    
                    
              pTVar13 = (unsigned char *)(*(code *)(((unsigned char *)0x97b9369c) + (*(unsigned char *)0x97b936a0)))();
              return pTVar13;
            }
            fVar3 = *(float *)(pcVar23 + iVar26 * 4);
          }
          *(int *)(iVar26 * 4 + iVar11) = (int)fVar3 / (int)fVar5;
        }
      }
      break;
    default:
      (*(code *)**(undefined4 **)this)(this);
                    
                    
      pTVar13 = (unsigned char *)(*(code *)(((unsigned char *)0x97b94568) + (*(unsigned char *)0x97b94574)))();
      return pTVar13;
    case 0x1d:
      local_4c = -0x5847e8cc;
      (**(code **)(*(int *)this + 0x38))((unsigned char *)&local_170,this);
      uVar4 = local_14c >> 0x13 & 0x3f;
      ppuVar25 = (undefined **)(local_4c + -0x473c);
      local_170 = ppuVar25;
      if (uVar4 == 2) {
        for (iVar11 = 0; iVar26 = (**(code **)(*(int *)this + 0x4c))(this), iVar11 < iVar26;
            iVar11 = iVar11 + 1) {
          if (*(float *)(pcVar23 + iVar11 * 4) != pfVar22[iVar11]) goto LAB_97b94304;
        }
      }
      else if (uVar4 < 3) {
        if (uVar4 != 1) {
LAB_97b9414c:
          (*(code *)**(undefined4 **)this)(this);
                    
                    
          pTVar13 = (unsigned char *)(*(code *)(((unsigned char *)0x97b94184) + (*(unsigned char *)0x97b94190)))();
          return pTVar13;
        }
        for (iVar11 = 0; iVar26 = (**(code **)(*(int *)this + 0x4c))(this), iVar11 < iVar26;
            iVar11 = iVar11 + 1) {
          if (*(float *)(pcVar23 + iVar11 * 4) != pfVar22[iVar11]) goto LAB_97b94304;
        }
      }
      else if (uVar4 == 3) {
        for (iVar11 = 0; iVar26 = (**(code **)(*(int *)this + 0x4c))(this), iVar11 < iVar26;
            iVar11 = iVar11 + 1) {
          if (*(float *)(pcVar23 + iVar11 * 4) != pfVar22[iVar11]) goto LAB_97b94304;
        }
      }
      else {
        if (uVar4 != 0xe) goto LAB_97b9414c;
        pcVar8 = (unsigned char *)piVar14[0xc];
        (**(code **)(*piVar14 + 0x38))((unsigned char *)&local_170,piVar14);
        iVar11 = ((int (*)())compareStructure)((unsigned char *)&local_170,pcVar8,pcVar23,&local_50);
        bVar1 = iVar11 == 1;
LAB_97b942fc:
        local_170 = ppuVar25;
        if (!bVar1) {
LAB_97b94304:
          bVar27 = true;
        }
      }
      goto LAB_97b943d4;
    case 0x1e:
      local_4c = -0x5847e8cc;
      (**(code **)(*(int *)this + 0x38))((unsigned char *)&local_170,this);
      uVar4 = local_14c >> 0x13 & 0x3f;
      ppuVar25 = (undefined **)(local_4c + -0x473c);
      local_170 = ppuVar25;
      if (uVar4 == 2) {
        for (iVar11 = 0; iVar26 = (**(code **)(*(int *)this + 0x4c))(this), iVar11 < iVar26;
            iVar11 = iVar11 + 1) {
          if (*(float *)(pcVar23 + iVar11 * 4) == pfVar22[iVar11]) goto LAB_97b94304;
        }
      }
      else if (uVar4 < 3) {
        if (uVar4 != 1) {
LAB_97b9430c:
          (*(code *)**(undefined4 **)this)(this);
                    
                    
          pTVar13 = (unsigned char *)(*(code *)(((unsigned char *)0x97b94344) + (*(unsigned char *)0x97b94350)))();
          return pTVar13;
        }
        for (iVar11 = 0; iVar26 = (**(code **)(*(int *)this + 0x4c))(this), iVar11 < iVar26;
            iVar11 = iVar11 + 1) {
          if (*(float *)(pcVar23 + iVar11 * 4) == pfVar22[iVar11]) goto LAB_97b94304;
        }
      }
      else {
        if (uVar4 != 3) {
          if (uVar4 != 0xe) goto LAB_97b9430c;
          pcVar8 = (unsigned char *)piVar14[0xc];
          (**(code **)(*piVar14 + 0x38))((unsigned char *)&local_170,piVar14);
          iVar11 = ((int (*)())compareStructure)((unsigned char *)&local_170,pcVar8,pcVar23,&local_50);
          bVar1 = iVar11 == 0;
          goto LAB_97b942fc;
        }
        for (iVar11 = 0; iVar26 = (**(code **)(*(int *)this + 0x4c))(this), iVar11 < iVar26;
            iVar11 = iVar11 + 1) {
          if (*(float *)(pcVar23 + iVar11 * 4) == pfVar22[iVar11]) goto LAB_97b94304;
        }
      }
LAB_97b943d4:
      uVar16 = GetGlobalPoolAllocator();
      puVar15 = (uint *)TPoolAllocator__allocate(uVar16);
      *puVar15 = (uint)!bVar27;
      uVar16 = GetGlobalPoolAllocator();
      pTVar13 = (unsigned char *)TPoolAllocator__allocate(uVar16);
      local_14c = local_14c & 0x1801ff | 0x4180800;
      local_170 = (undefined **)(local_4c + -0x473c);
      local_16c = 0;
      local_164 = 0;
      local_160 = 0;
      local_15c = 0;
      local_158 = 0;
      local_154 = 0;
      local_150 = 0;
      local_168 = 0;
      *(int *)(pTVar13 + 4) = 0;
      *(undefined ***)pTVar13 = &PTR_getLine_a7b7cf90;
      *(int *)(pTVar13 + 0xc) = 0;
      *(int *)(pTVar13 + 0x10) = 0;
      *(int *)(pTVar13 + 0x14) = 0;
      *(int *)(pTVar13 + 0x18) = 0;
      *(int *)(pTVar13 + 0x1c) = 0;
      *(int *)(pTVar13 + 0x20) = 0;
      *(undefined ***)(pTVar13 + 8) = local_170;
      *(int *)(pTVar13 + 0x24) = 0;
      *(int *)(pTVar13 + 0x28) = 0;
      uVar9 = *(uint *)(pTVar13 + 0x2c);
      *(uint *)(pTVar13 + 0x2c) = uVar9 & 0x1ffffff | 0x4000000;
      uVar4 = (local_14c >> 0x13 & 0x3f) << 0x13;
      *(uint *)(pTVar13 + 0x2c) = uVar4 | uVar9 & 0x7ffff | 0x4000000;
      *(uint *)(pTVar13 + 0x2c) = uVar4 | uVar9 & 0x7ff | 0x4000000 | 0x800;
      *(uint *)(pTVar13 + 0x2c) = uVar4 | uVar9 & 0x3ff | 0x4000000 | 0x800;
      puVar21 = PTR_vtable_a7b7c0c8;
      *(uint *)(pTVar13 + 0x2c) = uVar4 | uVar9 & 0x1ff | 0x4000000 | 0x800;
      *(uint **)(pTVar13 + 0x30) = puVar15;
      *(undefined **)pTVar13 = puVar21 + 8;
      puVar10 = *(undefined4 **)this;
LAB_97b953d4:
      iVar11 = *(int *)pTVar13;
      uVar17 = (*(code *)*puVar10)(this);
      (**(code **)(iVar11 + 4))(pTVar13,uVar17);
      return pTVar13;
    case 0x27:
      local_4c = -0x5847e8cc;
      (**(code **)(*(int *)this + 0x38))(&local_170,this);
      local_170 = (undefined **)(local_4c + -0x473c);
      if ((local_14c >> 0x13 & 0x3f) != 1) {
        (*(code *)**(undefined4 **)this)(this);
                    
                    
        pTVar13 = (unsigned char *)(*(code *)(((unsigned char *)0x97b93a74) + (*(unsigned char *)0x97b93a80)))();
        return pTVar13;
      }
      (**(code **)(*(int *)this + 0x48))(this);
      uVar16 = GetGlobalPoolAllocator();
      iVar11 = TPoolAllocator__allocate(uVar16);
      iVar26 = (**(code **)(*(int *)this + 0x48))(this);
      iVar24 = 0;
      if (0 < iVar26) {
        iVar12 = 0;
        do {
          iVar20 = iVar24 * 4;
          *(undefined4 *)(iVar20 + iVar11) = 0;
          if (0 < iVar26) {
            pfVar19 = pfVar22 + iVar12;
            pcVar8 = pcVar23;
            iVar18 = iVar26;
            do {
              fVar5 = *(float *)pcVar8;
              pcVar8 = pcVar8 + 4;
              fVar3 = *pfVar19;
              pfVar19 = pfVar19 + 1;
              *(float *)(iVar20 + iVar11) = fVar5 * fVar3 + *(float *)(iVar20 + iVar11);
              iVar18 = iVar18 + -1;
            } while (iVar18 != 0);
          }
          iVar24 = iVar24 + 1;
          iVar12 = iVar12 + iVar26;
        } while (iVar24 < iVar26);
      }
      break;
    case 0x28:
      iVar11 = (**(code **)(*piVar14 + 0x40))();
      if (iVar11 != 1) {
        (*(code *)**(undefined4 **)this)(this);
                    
                    
        pTVar13 = (unsigned char *)(*(code *)(((unsigned char *)0x97b938f8) + (*(unsigned char *)0x97b93904)))();
        return pTVar13;
      }
      (**(code **)(*(int *)this + 0x48))(this);
      uVar16 = GetGlobalPoolAllocator();
      iVar11 = TPoolAllocator__allocate(uVar16);
      iVar26 = (**(code **)(*(int *)this + 0x48))(this);
      iVar24 = 0;
      if (0 < iVar26) {
        iVar12 = 0;
        do {
          *(undefined4 *)(iVar12 + iVar11) = 0;
          if (0 < iVar26) {
            pcVar8 = pcVar23 + iVar12;
            pfVar19 = pfVar22;
            iVar20 = iVar26;
            do {
              fVar5 = *(float *)pcVar8;
              pcVar8 = pcVar8 + iVar26 * 4;
              fVar3 = *pfVar19;
              pfVar19 = pfVar19 + 1;
              *(float *)(iVar12 + iVar11) = fVar5 * fVar3 + *(float *)(iVar12 + iVar11);
              iVar20 = iVar20 + -1;
            } while (iVar20 != 0);
          }
          iVar24 = iVar24 + 1;
          iVar12 = iVar12 + 4;
        } while (iVar24 < iVar26);
      }
      uVar16 = GetGlobalPoolAllocator();
      pTVar13 = (unsigned char *)TPoolAllocator__allocate(uVar16);
      (**(code **)(*piVar14 + 0x38))(&local_170,piVar14);
      *(undefined ***)pTVar13 = &PTR_getLine_a7b7cf90;
      puVar21 = &TType::vtable;
      *(int *)(pTVar13 + 4) = 0;
      goto LAB_97b946a4;
    case 0x2a:
      local_4c = -0x5847e8cc;
      (**(code **)(*(int *)this + 0x4c))(this);
      uVar16 = GetGlobalPoolAllocator();
      iVar11 = TPoolAllocator__allocate(uVar16);
      for (iVar26 = 0; iVar24 = (**(code **)(*(int *)this + 0x4c))(this), iVar26 < iVar24;
          iVar26 = iVar26 + 1) {
        (**(code **)(*(int *)this + 0x38))(&local_170,this);
        local_170 = (undefined **)(local_4c + -0x473c);
        if ((local_14c >> 0x13 & 0x3f) != 3) {
          (*(code *)**(undefined4 **)this)(this);
                    
                    
          pTVar13 = (unsigned char *)(*(code *)(((unsigned char *)0x97b93ed8) + (*(unsigned char *)0x97b93ee4)))();
          return pTVar13;
        }
        uVar17 = 0;
        if ((*(int *)(pcVar23 + iVar26 * 4) != 0) || (pfVar22[iVar26] != 0.0)) {
          uVar17 = 1;
        }
        *(undefined4 *)(iVar26 * 4 + iVar11) = uVar17;
      }
      break;
    case 0x2b:
      local_4c = -0x5847e8cc;
      (**(code **)(*(int *)this + 0x4c))(this);
      uVar16 = GetGlobalPoolAllocator();
      iVar11 = TPoolAllocator__allocate(uVar16);
      for (iVar26 = 0; iVar24 = (**(code **)(*(int *)this + 0x4c))(this), iVar26 < iVar24;
          iVar26 = iVar26 + 1) {
        (**(code **)(*(int *)this + 0x38))(&local_170,this);
        local_170 = (undefined **)(local_4c + -0x473c);
        if ((local_14c >> 0x13 & 0x3f) != 3) {
          (*(code *)**(undefined4 **)this)(this);
                    
                    
          pTVar13 = (unsigned char *)(*(code *)(((unsigned char *)0x97b93da8) + (*(unsigned char *)0x97b93db4)))();
          return pTVar13;
        }
        *(uint *)(iVar26 * 4 + iVar11) = (uint)(*(float *)(pcVar23 + iVar26 * 4) != pfVar22[iVar26])
        ;
      }
      break;
    case 0x2c:
      local_4c = -0x5847e8cc;
      (**(code **)(*(int *)this + 0x4c))(this);
      uVar16 = GetGlobalPoolAllocator();
      iVar11 = TPoolAllocator__allocate(uVar16);
      for (iVar26 = 0; iVar24 = (**(code **)(*(int *)this + 0x4c))(this), iVar26 < iVar24;
          iVar26 = iVar26 + 1) {
        (**(code **)(*(int *)this + 0x38))(&local_170,this);
        local_170 = (undefined **)(local_4c + -0x473c);
        if ((local_14c >> 0x13 & 0x3f) != 3) {
          (*(code *)**(undefined4 **)this)(this);
                    
                    
          pTVar13 = (unsigned char *)(*(code *)(((unsigned char *)0x97b93cbc) + (*(unsigned char *)0x97b93cc8)))();
          return pTVar13;
        }
        uVar17 = 0;
        if ((*(int *)(pcVar23 + iVar26 * 4) != 0) && (pfVar22[iVar26] != 0.0)) {
          uVar17 = 1;
        }
        *(undefined4 *)(iVar26 * 4 + iVar11) = uVar17;
      }
      break;
    case 0x56:
      bVar27 = false;
      (**(code **)(*(int *)this + 0x38))(&local_170,this);
      if (((local_14c >> 0x13 & 0x3f) != 1) ||
         (iVar11 = (**(code **)(*piVar14 + 0x40))(piVar14), iVar11 != 1)) {
        bVar27 = true;
      }
      local_4c = -0x5847e8cc;
      local_170 = &PTR__TType_a7b7cff8;
      if (bVar27) {
        (*(code *)**(undefined4 **)this)(this);
                    
                    
        pTVar13 = (unsigned char *)(*(code *)(((unsigned char *)0x97b93224) + (*(unsigned char *)0x97b93230)))();
        return pTVar13;
      }
      iVar26 = (**(code **)(*(int *)this + 0x48))(this);
      uVar16 = GetGlobalPoolAllocator();
      iVar11 = TPoolAllocator__allocate(uVar16);
      iVar24 = 0;
      if (0 < iVar26) {
        do {
          if (0 < iVar26) {
            iVar18 = 0;
            iVar12 = iVar24 * 4;
            iVar20 = iVar26;
            do {
              *(undefined4 *)(iVar12 + iVar11) = 0;
              if (0 < iVar26) {
                pfVar19 = pfVar22 + iVar18;
                pcVar8 = pcVar23 + iVar24 * 4;
                iVar28 = iVar26;
                do {
                  fVar5 = *(float *)pcVar8;
                  pcVar8 = pcVar8 + iVar26 * 4;
                  fVar3 = *pfVar19;
                  pfVar19 = pfVar19 + 1;
                  *(float *)(iVar11 + iVar12) = fVar5 * fVar3 + *(float *)(iVar11 + iVar12);
                  iVar28 = iVar28 + -1;
                } while (iVar28 != 0);
              }
              iVar20 = iVar20 + -1;
              iVar18 = iVar18 + iVar26;
              iVar12 = iVar12 + iVar26 * 4;
            } while (iVar20 != 0);
          }
          iVar24 = iVar24 + 1;
        } while (iVar24 < iVar26);
      }
    }
    uVar16 = GetGlobalPoolAllocator();
    pTVar13 = (unsigned char *)TPoolAllocator__allocate(uVar16);
    (**(code **)(*(int *)this + 0x38))(&local_170,this);
    *(int *)(pTVar13 + 4) = 0;
    *(undefined ***)pTVar13 = &PTR_getLine_a7b7cf90;
    puVar21 = (undefined *)(local_4c + -0x4744);
LAB_97b946a4:
    local_170 = (undefined **)(puVar21 + 8);
    *(int *)(pTVar13 + 0xc) = local_16c;
    *(int *)(pTVar13 + 0x10) = local_168;
    *(int *)(pTVar13 + 0x14) = local_164;
    *(int *)(pTVar13 + 0x18) = local_160;
    *(int *)(pTVar13 + 0x1c) = local_15c;
    *(int *)(pTVar13 + 0x20) = local_158;
    *(undefined ***)(pTVar13 + 8) = local_170;
    *(int *)(pTVar13 + 0x24) = local_154;
    *(int *)(pTVar13 + 0x28) = local_150;
    uVar6 = *(uint *)(pTVar13 + 0x2c);
    uVar9 = local_14c & 0xfe000000;
    *(uint *)(pTVar13 + 0x2c) = uVar9 | uVar6 & 0x1ffffff;
    uVar7 = (local_14c >> 0x13 & 0x3f) << 0x13;
    *(uint *)(pTVar13 + 0x2c) = uVar7 | uVar9 | uVar6 & 0x7ffff;
    uVar4 = local_14c & 0x7f800;
    *(uint *)(pTVar13 + 0x2c) = uVar4 | uVar7 | uVar9 | uVar6 & 0x7ff;
    uVar2 = (local_14c >> 10 & 1) << 10;
    *(uint *)(pTVar13 + 0x2c) = uVar2 | uVar4 | uVar7 | uVar9 | uVar6 & 0x3ff;
    puVar21 = PTR_vtable_a7b7c0c8;
    *(uint *)(pTVar13 + 0x2c) =
         (local_14c >> 9 & 1) << 9 | uVar2 | uVar4 | uVar7 | uVar9 | uVar6 & 0x1ff;
    *(int *)(pTVar13 + 0x30) = iVar11;
    *(undefined **)pTVar13 = puVar21 + 8;
LAB_97b94758:
    iVar11 = *(int *)pTVar13;
    uVar17 = (*(code *)**(undefined4 **)this)(this);
    (**(code **)(iVar11 + 4))(pTVar13,uVar17);
    return pTVar13;
  }
LAB_97b9478c:
  bVar27 = false;
  iVar11 = (**(code **)(*(int *)this + 0x4c))(this);
  if (iVar11 != 1) {
    return this;
  }
  (**(code **)(*(int *)this + 0x38))(&local_170,this);
  if (((local_14c >> 0x13 & 0x3f) != 0xe) &&
     (iVar11 = (**(code **)(*(int *)param_3 + 0x4c))(param_3), iVar11 == 1)) {
    (**(code **)(*(int *)param_3 + 0x38))(local_140,param_3);
    bVar27 = (local_11c >> 0x13 & 0x3f) != 0xe;
    local_140[0] = &PTR__TType_a7b7cff8;
  }
  local_170 = &PTR__TType_a7b7cff8;
  if (!bVar27) {
    return this;
  }
  uVar16 = GetGlobalPoolAllocator();
  pfVar22 = (float *)TPoolAllocator__allocate(uVar16);
  local_4c = -0x5847e8cc;
  (**(code **)(*(int *)this + 0x38))(&local_110,this);
  local_110 = &PTR__TType_a7b7cff8;
  uVar4 = local_ec >> 0x13 & 0x3f;
  if (uVar4 != 2) {
    if (2 < uVar4) {
      if (uVar4 != 3) goto LAB_97b95400;
      iVar11 = (**(code **)(*(int *)param_3 + 0x18))(param_3);
      uVar9 = **(uint **)(iVar11 + 0x30);
      uVar4 = **(uint **)(this + 0x30);
      if (param_2 == 0x2b) {
        bVar27 = uVar4 == uVar9;
      }
      else {
        if (param_2 < 0x2c) {
          if (param_2 != 0x2a) {
LAB_97b95260:
                    
                    
            pTVar13 = (unsigned char *)(*(code *)(((unsigned char *)0x97b95284) + (*(unsigned char *)0x97b95290)))();
            return pTVar13;
          }
          uVar4 = uVar4 | uVar9;
        }
        else {
          uVar4 = uVar4 & uVar9;
          if (param_2 != 0x2c) goto LAB_97b95260;
        }
        bVar27 = uVar4 == 0;
      }
      *pfVar22 = (float)(1 - bVar27);
      uVar16 = GetGlobalPoolAllocator();
      pTVar13 = (unsigned char *)TPoolAllocator__allocate(uVar16);
      local_ec = local_ec & 0x1801ff | 0x4180800;
      local_110 = (undefined **)(local_4c + -0x473c);
      local_10c = 0;
      local_104 = 0;
      local_100 = 0;
      local_fc = 0;
      local_f8 = 0;
      local_f4 = 0;
      local_f0 = 0;
      local_108 = 0;
      *(int *)(pTVar13 + 4) = 0;
      *(undefined ***)pTVar13 = &PTR_getLine_a7b7cf90;
      *(int *)(pTVar13 + 0xc) = 0;
      *(int *)(pTVar13 + 0x10) = 0;
      *(int *)(pTVar13 + 0x14) = 0;
      *(int *)(pTVar13 + 0x18) = 0;
      *(int *)(pTVar13 + 0x1c) = 0;
      *(int *)(pTVar13 + 0x20) = 0;
      *(undefined ***)(pTVar13 + 8) = local_110;
      *(int *)(pTVar13 + 0x24) = 0;
      *(int *)(pTVar13 + 0x28) = 0;
      uVar9 = *(uint *)(pTVar13 + 0x2c);
      *(uint *)(pTVar13 + 0x2c) = uVar9 & 0x1ffffff | 0x4000000;
      uVar4 = (local_ec >> 0x13 & 0x3f) << 0x13;
      *(uint *)(pTVar13 + 0x2c) = uVar4 | uVar9 & 0x7ffff | 0x4000000;
      *(uint *)(pTVar13 + 0x2c) = uVar4 | uVar9 & 0x7ff | 0x4000000 | 0x800;
      *(uint *)(pTVar13 + 0x2c) = uVar4 | uVar9 & 0x3ff | 0x4000000 | 0x800;
      puVar21 = PTR_vtable_a7b7c0c8;
      *(uint *)(pTVar13 + 0x2c) = uVar4 | uVar9 & 0x1ff | 0x4000000 | 0x800;
      *(float **)(pTVar13 + 0x30) = pfVar22;
      *(undefined **)pTVar13 = puVar21 + 8;
      puVar10 = *(undefined4 **)param_3;
      this = param_3;
      goto LAB_97b953d4;
    }
    if (uVar4 != 1) {
LAB_97b95400:
      (*(code *)**(undefined4 **)this)(this);
                    
                    
      pTVar13 = (unsigned char *)(*(code *)(((unsigned char *)0x97b95438) + (*(unsigned char *)0x97b95444)))();
      return pTVar13;
    }
    iVar11 = (**(code **)(*(int *)param_3 + 0x18))(param_3);
    dVar30 = (double)**(float **)(iVar11 + 0x30);
    dVar29 = (double)**(float **)(this + 0x30);
    switch(param_2) {
    case 0x13:
      fVar5 = (float)(dVar29 + dVar30);
      goto LAB_97b94ef8;
    case 0x14:
      fVar5 = (float)(dVar29 - dVar30);
      goto LAB_97b94ef8;
    case 0x15:
      fVar5 = (float)(dVar29 * dVar30);
      goto LAB_97b94ef8;
    case 0x16:
      if (dVar30 == DOUBLE_97c30a48) {
        (*(code *)**(undefined4 **)this)(this);
                    
                    
        pTVar13 = (unsigned char *)(*(code *)(((unsigned char *)0x97b94dcc) + (*(unsigned char *)0x97b94dd0)))();
        return pTVar13;
      }
      fVar5 = (float)(dVar29 / dVar30);
LAB_97b94ef8:
      *pfVar22 = fVar5;
      goto LAB_97b95098;
    default:
      goto switchD_97b94d20_caseD_17;
    case 0x1d:
      fVar5 = (float)(uint)(dVar29 == dVar30);
      break;
    case 0x1e:
      fVar5 = (float)(uint)(dVar29 != dVar30);
      break;
    case 0x21:
      fVar5 = (float)(uint)(dVar29 < dVar30);
      break;
    case 0x22:
      fVar5 = (float)(uint)(dVar30 < dVar29);
      break;
    case 0x23:
      bVar27 = dVar29 <= dVar30;
      goto LAB_97b94f58;
    case 0x24:
      bVar27 = dVar30 <= dVar29;
LAB_97b94f58:
      fVar5 = (float)(uint)bVar27;
    }
    *pfVar22 = fVar5;
    uVar16 = GetGlobalPoolAllocator();
    pTVar13 = (unsigned char *)TPoolAllocator__allocate(uVar16);
    local_ec = local_ec & 0x1801ff | 0x4180800;
    local_110 = (undefined **)(local_4c + -0x473c);
    local_10c = 0;
    local_104 = 0;
    local_100 = 0;
    local_fc = 0;
    local_f8 = 0;
    local_f4 = 0;
    local_f0 = 0;
    local_108 = 0;
    *(int *)(pTVar13 + 4) = 0;
    *(undefined ***)pTVar13 = &PTR_getLine_a7b7cf90;
    *(int *)(pTVar13 + 0xc) = 0;
    *(int *)(pTVar13 + 0x10) = 0;
    *(int *)(pTVar13 + 0x14) = 0;
    *(int *)(pTVar13 + 0x18) = 0;
    *(int *)(pTVar13 + 0x1c) = 0;
    *(int *)(pTVar13 + 0x20) = 0;
    *(int *)(pTVar13 + 0x24) = 0;
    *(undefined ***)(pTVar13 + 8) = local_110;
    *(int *)(pTVar13 + 0x28) = 0;
    uVar9 = *(uint *)(pTVar13 + 0x2c);
    *(uint *)(pTVar13 + 0x2c) = uVar9 & 0x1ffffff | 0x4000000;
    uVar4 = (local_ec >> 0x13 & 0x3f) << 0x13;
    *(uint *)(pTVar13 + 0x2c) = uVar4 | uVar9 & 0x7ffff | 0x4000000;
    *(uint *)(pTVar13 + 0x2c) = uVar4 | uVar9 & 0x7ff | 0x4000000 | 0x800;
    *(uint *)(pTVar13 + 0x2c) = uVar4 | uVar9 & 0x3ff | 0x4000000 | 0x800;
    puVar21 = PTR_vtable_a7b7c0c8;
    *(uint *)(pTVar13 + 0x2c) = uVar4 | uVar9 & 0x1ff | 0x4000000 | 0x800;
    *(float **)(pTVar13 + 0x30) = pfVar22;
    *(undefined **)pTVar13 = puVar21 + 8;
    if (pTVar13 != (unsigned char *)0x0) goto LAB_97b951c0;
LAB_97b95098:
    uVar16 = GetGlobalPoolAllocator();
    pTVar13 = (unsigned char *)TPoolAllocator__allocate(uVar16);
    uVar4 = local_ec & 0x7ff | 0x4080000;
    goto LAB_97b950c8;
  }
  iVar11 = (**(code **)(*(int *)param_3 + 0x18))(param_3);
  uVar9 = **(uint **)(iVar11 + 0x30);
  uVar4 = **(uint **)(this + 0x30);
  switch(param_2) {
  case 0x13:
    fVar5 = (float)(uVar4 + uVar9);
    break;
  case 0x14:
    fVar5 = (float)(uVar4 - uVar9);
    break;
  case 0x15:
    fVar5 = (float)(uVar4 * uVar9);
    break;
  case 0x16:
    if (uVar9 == 0) {
      (*(code *)**(undefined4 **)this)(this);
                    
                    
      pTVar13 = (unsigned char *)(*(code *)(((unsigned char *)0x97b94998) + (*(unsigned char *)0x97b9499c)))();
      return pTVar13;
    }
    fVar5 = (float)((int)uVar4 / (int)uVar9);
    break;
  case 0x17:
    fVar5 = (float)(uVar4 - ((int)uVar4 / (int)uVar9) * uVar9);
    break;
  case 0x18:
    fVar5 = (float)((int)uVar4 >> (uVar9 & 0x3f));
    break;
  case 0x19:
    fVar5 = (float)(uVar4 << (uVar9 & 0x3f));
    break;
  case 0x1a:
    fVar5 = (float)(uVar4 & uVar9);
    break;
  case 0x1b:
    fVar5 = (float)(uVar4 | uVar9);
    break;
  case 0x1c:
    fVar5 = (float)(uVar4 ^ uVar9);
    break;
  case 0x1d:
    fVar5 = (float)(uint)(uVar4 == uVar9);
    goto LAB_97b94b6c;
  case 0x1e:
    *pfVar22 = (float)(uint)(uVar4 != uVar9);
    goto LAB_97b94b70;
  default:
switchD_97b94d20_caseD_17:
    return (unsigned char *)0x0;
  case 0x21:
    fVar5 = 1.4013e-45;
    if ((int)uVar9 <= (int)uVar4) {
LAB_97b94b68:
      fVar5 = 0.0;
    }
    goto LAB_97b94b6c;
  case 0x22:
    fVar5 = 1.4013e-45;
    if ((int)uVar4 <= (int)uVar9) goto LAB_97b94b68;
    goto LAB_97b94b6c;
  case 0x23:
    fVar5 = 1.4013e-45;
    if ((int)uVar9 < (int)uVar4) goto LAB_97b94b68;
    goto LAB_97b94b6c;
  case 0x24:
    fVar5 = 1.4013e-45;
    if ((int)uVar4 < (int)uVar9) goto LAB_97b94b68;
LAB_97b94b6c:
    *pfVar22 = fVar5;
LAB_97b94b70:
    uVar16 = GetGlobalPoolAllocator();
    pTVar13 = (unsigned char *)TPoolAllocator__allocate(uVar16);
    local_ec = local_ec & 0x1801ff | 0x4180800;
    local_110 = (undefined **)(local_4c + -0x473c);
    local_10c = 0;
    local_104 = 0;
    local_100 = 0;
    local_fc = 0;
    local_f8 = 0;
    local_f4 = 0;
    local_f0 = 0;
    local_108 = 0;
    *(int *)(pTVar13 + 4) = 0;
    *(undefined ***)pTVar13 = &PTR_getLine_a7b7cf90;
    *(int *)(pTVar13 + 0xc) = 0;
    *(int *)(pTVar13 + 0x10) = 0;
    *(int *)(pTVar13 + 0x14) = 0;
    *(int *)(pTVar13 + 0x18) = 0;
    *(int *)(pTVar13 + 0x1c) = 0;
    *(int *)(pTVar13 + 0x20) = 0;
    *(int *)(pTVar13 + 0x24) = 0;
    *(undefined ***)(pTVar13 + 8) = local_110;
    *(int *)(pTVar13 + 0x28) = 0;
    uVar9 = *(uint *)(pTVar13 + 0x2c);
    *(uint *)(pTVar13 + 0x2c) = uVar9 & 0x1ffffff | 0x4000000;
    uVar4 = (local_ec >> 0x13 & 0x3f) << 0x13;
    *(uint *)(pTVar13 + 0x2c) = uVar4 | uVar9 & 0x7ffff | 0x4000000;
    *(uint *)(pTVar13 + 0x2c) = uVar4 | uVar9 & 0x7ff | 0x4000000 | 0x800;
    *(uint *)(pTVar13 + 0x2c) = uVar4 | uVar9 & 0x3ff | 0x4000000 | 0x800;
    puVar21 = PTR_vtable_a7b7c0c8;
    *(uint *)(pTVar13 + 0x2c) = uVar4 | uVar9 & 0x1ff | 0x4000000 | 0x800;
    *(float **)(pTVar13 + 0x30) = pfVar22;
    *(undefined **)pTVar13 = puVar21 + 8;
    if (pTVar13 != (unsigned char *)0x0) goto LAB_97b951c0;
    goto LAB_97b94ca4;
  }
  *pfVar22 = fVar5;
LAB_97b94ca4:
  uVar16 = GetGlobalPoolAllocator();
  pTVar13 = (unsigned char *)TPoolAllocator__allocate(uVar16);
  uVar4 = local_ec & 0xfff | 0x4100000;
LAB_97b950c8:
  local_110 = (undefined **)(local_4c + -0x473c);
  local_ec = uVar4 & 0xfffff9ff | 0x800;
  *(int *)(pTVar13 + 4) = 0;
  *(undefined ***)pTVar13 = &PTR_getLine_a7b7cf90;
  *(int *)(pTVar13 + 0xc) = 0;
  *(int *)(pTVar13 + 0x10) = 0;
  *(int *)(pTVar13 + 0x14) = 0;
  *(int *)(pTVar13 + 0x18) = 0;
  *(int *)(pTVar13 + 0x1c) = 0;
  *(int *)(pTVar13 + 0x20) = 0;
  *(undefined ***)(pTVar13 + 8) = local_110;
  *(int *)(pTVar13 + 0x24) = 0;
  *(int *)(pTVar13 + 0x28) = 0;
  uVar7 = *(uint *)(pTVar13 + 0x2c);
  uVar9 = uVar4 & 0xfe000000;
  *(uint *)(pTVar13 + 0x2c) = uVar9 | uVar7 & 0x1ffffff;
  uVar4 = uVar4 & 0x1f80000;
  *(uint *)(pTVar13 + 0x2c) = uVar4 | uVar9 | uVar7 & 0x7ffff;
  *(uint *)(pTVar13 + 0x2c) = uVar4 | uVar9 | uVar7 & 0x7ff | 0x800;
  *(uint *)(pTVar13 + 0x2c) = uVar4 | uVar9 | uVar7 & 0x3ff | 0x800;
  puVar21 = PTR_vtable_a7b7c0c8;
  *(uint *)(pTVar13 + 0x2c) = uVar4 | uVar9 | uVar7 & 0x1ff | 0x800;
  *(float **)(pTVar13 + 0x30) = pfVar22;
  *(undefined **)pTVar13 = puVar21 + 8;
LAB_97b951c0:
  local_f0 = 0;
  iVar11 = *(int *)pTVar13;
  local_10c = local_f0;
  local_108 = local_f0;
  local_104 = local_f0;
  local_100 = local_f0;
  local_fc = local_f0;
  local_f8 = local_f0;
  local_f4 = local_f0;
  uVar17 = (*(code *)**(undefined4 **)param_3)(param_3);
  (**(code **)(iVar11 + 4))(pTVar13,uVar17);
  return pTVar13;
}

/* TIntermediate__changeAggrToTempConst @ 0x97b95c0c (484 bytes) */
int TIntermediate__changeAggrToTempConst(this, param_1, param_2, param_3)
  unsigned char *this;
  unsigned char *param_1;
  unsigned char *param_2;
  int param_3;
{
  ulong uVar1;
  constUnion *pcVar2;
  int iVar3;
  int *piVar4;
  undefined **local_60 [15];
  
  (**(code **)(*(int *)param_1 + 0x38))(local_60);
  uVar1 = GetGlobalPoolAllocator();
  pcVar2 = (unsigned char *)TPoolAllocator__allocate(uVar1);
  local_60[0] = &PTR__TType_a7b7cff8;
  iVar3 = (**(code **)(*(int *)param_1 + 100))(param_1);
  if (*(int *)(iVar3 + 8) - *(int *)(iVar3 + 4) >> 2 == 1) {
    iVar3 = (**(code **)(*(int *)param_1 + 100))(param_1);
    piVar4 = (int *)(**(code **)(*(int *)**(undefined4 **)(iVar3 + 4) + 0x14))();
    iVar3 = (**(code **)(*piVar4 + 0x18))();
    if (iVar3 != 0) {
      (**(code **)(*(int *)param_1 + 0x38))(local_60,param_1);
      iVar3 = TIntermediate__parseConstTree
                        (this,param_3,param_1,pcVar2,*(undefined4 *)(param_1 + 0x30),param_2,
                         local_60,1);
      goto LAB_97b95d90;
    }
  }
  (**(code **)(*(int *)param_1 + 0x38))(local_60,param_1);
  iVar3 = TIntermediate__parseConstTree
                    (this,param_3,param_1,pcVar2,*(undefined4 *)(param_1 + 0x30),param_2,local_60,0)
  ;
LAB_97b95d90:
  local_60[0] = &PTR__TType_a7b7cff8;
  if (iVar3 != 0) {
    pcVar2 = (unsigned char *)0x0;
  }
  (**(code **)(*(int *)param_1 + 0x38))(local_60,param_1);
  iVar3 = (*(code *)**(undefined4 **)param_1)(param_1);
  ((int (*)())TIntermediate__addConstantUnion)(this,pcVar2,(unsigned char *)local_60,iVar3);
  return;
}

/* TIntermediate__copyConstUnion @ 0x97b95df0 (336 bytes) */
int TIntermediate__copyConstUnion(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  int iVar1;
  int iVar2;
  ulong uVar3;
  int iVar4;
  TIntermConstantUnion *pTVar5;
  int iVar6;
  int iVar7;
  undefined **local_b0 [9];
  uint local_8c;
  undefined **local_80 [9];
  uint local_5c;
  undefined **local_50 [14];
  
  iVar7 = *(int *)(param_1 + 0x30);
  pTVar5 = (unsigned char *)0x0;
  if (iVar7 != 0) {
    (**(code **)(*(int *)param_1 + 0x38))(local_b0);
    local_b0[0] = &PTR__TType_a7b7cff8;
    if ((local_8c >> 0x13 & 0x3f) == 0xe) {
      (**(code **)(*(int *)param_1 + 0x38))(local_80,param_1);
      (**(code **)(*(int *)param_1 + 0x38))((unsigned char *)local_50,param_1);
      iVar2 = TType__setStructSize((unsigned char *)local_50);
      local_50[0] = &PTR__TType_a7b7cff8;
    }
    else {
      (**(code **)(*(int *)param_1 + 0x38))(local_80,param_1);
      if ((local_5c & 0x400) == 0) {
        iVar2 = (int)(local_5c << 0xd | local_5c >> 0x13) >> 0x18;
      }
      else {
        iVar2 = (int)(local_5c << 0xd | local_5c >> 0x13) >> 0x18;
        iVar2 = iVar2 * iVar2;
      }
    }
    local_80[0] = &PTR__TType_a7b7cff8;
    uVar3 = GetGlobalPoolAllocator();
    iVar4 = TPoolAllocator__allocate(uVar3);
    iVar6 = 0;
    if (0 < iVar2) {
      do {
        iVar1 = iVar6 * 4;
        iVar6 = iVar6 + 1;
        *(undefined4 *)(iVar4 + iVar1) = *(undefined4 *)(iVar7 + iVar1);
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    *(int *)(param_1 + 0x30) = iVar4;
    pTVar5 = param_1;
  }
  return pTVar5;
}

/* TIntermediate__promoteConstantUnion @ 0x97b95f40 (1080 bytes) */
int TIntermediate__promoteConstantUnion(this, param_2, param_3)
  unsigned char *this;
  uint param_2;
  int *param_3;
{
  int iVar1;
  uint uVar2;
  ulong uVar3;
  constUnion *pcVar4;
  int iVar5;
  int iVar6;
  double dVar7;
  undefined **local_c0 [9];
  uint local_9c;
  undefined4 local_90;
  uint uStack_8c;
  undefined **local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  uint local_5c;
  longlong local_40;
  
  iVar5 = param_3[0xc];
  (**(code **)(*param_3 + 0x38))(local_c0,param_3);
  if ((local_9c & 0x400) == 0) {
    iVar1 = (int)(local_9c << 0xd | local_9c >> 0x13) >> 0x18;
  }
  else {
    iVar1 = (int)(local_9c << 0xd | local_9c >> 0x13) >> 0x18;
    iVar1 = iVar1 * iVar1;
  }
  local_c0[0] = &PTR__TType_a7b7cff8;
  uVar3 = GetGlobalPoolAllocator();
  iVar6 = 0;
  pcVar4 = (unsigned char *)TPoolAllocator__allocate(uVar3);
  if (0 < iVar1) {
    do {
      if (param_2 == 2) {
        (**(code **)(*param_3 + 0x38))(local_c0,param_3);
        uVar2 = local_9c >> 0x13 & 0x3f;
        local_c0[0] = &PTR__TType_a7b7cff8;
        if (uVar2 == 2) {
LAB_97b96230:
          uVar2 = *(uint *)(iVar6 * 4 + iVar5);
        }
        else {
          if (2 < uVar2) {
            if (uVar2 != 3) goto LAB_97b96174;
            goto LAB_97b96230;
          }
          if (uVar2 != 1) {
LAB_97b96174:
            (**(code **)*param_3)(param_3);
                    
                    
            (*(code *)(((unsigned char *)0x97b961b0) + (*(unsigned char *)0x97b961bc)))();
            return;
          }
          uVar2 = (uint)*(float *)(iVar6 * 4 + iVar5);
          local_40 = (longlong)(int)uVar2;
        }
LAB_97b9625c:
        *(uint *)(pcVar4 + iVar6 * 4) = uVar2;
      }
      else if ((int)param_2 < 3) {
        if (param_2 != 1) {
LAB_97b962b8:
          (**(code **)*param_3)(param_3);
                    
                    
          (*(code *)(((unsigned char *)0x97b962f4) + (*(unsigned char *)0x97b96300)))();
          return;
        }
        (**(code **)(*param_3 + 0x38))(local_c0,param_3);
        uVar2 = local_9c >> 0x13 & 0x3f;
        local_c0[0] = &PTR__TType_a7b7cff8;
        if (uVar2 == 2) {
          uStack_8c = *(uint *)(iVar6 * 4 + iVar5) ^ 0x80000000;
          dVar7 = DOUBLE_97c30a58;
        }
        else {
          if (uVar2 < 3) {
            if (uVar2 != 1) goto LAB_97b960b8;
            *(undefined4 *)(pcVar4 + iVar6 * 4) = *(undefined4 *)(iVar5 + iVar6 * 4);
            goto LAB_97b9641c;
          }
          if (uVar2 != 3) {
LAB_97b960b8:
            (**(code **)*param_3)(param_3);
                    
                    
            (*(code *)(((unsigned char *)0x97b960f4) + (*(unsigned char *)0x97b96100)))();
            return;
          }
          uStack_8c = *(uint *)(iVar6 * 4 + iVar5);
          dVar7 = DOUBLE_97c30a68;
        }
        local_90 = 0x43300000;
        *(float *)(pcVar4 + iVar6 * 4) = (float)((double)CONCAT44(0x43300000,uStack_8c) - dVar7);
      }
      else {
        if (param_2 != 3) goto LAB_97b962b8;
        (**(code **)(*param_3 + 0x38))(local_c0,param_3);
        uVar2 = local_9c >> 0x13 & 0x3f;
        local_c0[0] = &PTR__TType_a7b7cff8;
        if (uVar2 != 2) {
          if (uVar2 < 3) {
            if (uVar2 != 1) goto LAB_97b96264;
            uVar2 = (uint)((double)*(float *)(iVar6 * 4 + iVar5) != DOUBLE_97c30a48);
            goto LAB_97b9625c;
          }
          if (uVar2 != 3) {
LAB_97b96264:
            (**(code **)*param_3)(param_3);
                    
                    
            (*(code *)(((unsigned char *)0x97b962a0) + (*(unsigned char *)0x97b962ac)))();
            return;
          }
          goto LAB_97b96230;
        }
        *(uint *)(pcVar4 + iVar6 * 4) = (uint)(*(int *)(iVar5 + iVar6 * 4) != 0);
      }
LAB_97b9641c:
      local_c0[0] = &PTR__TType_a7b7cff8;
      iVar6 = iVar6 + 1;
    } while (iVar6 < iVar1);
  }
  (**(code **)(*param_3 + 0x38))(local_c0,param_3);
  local_5c = (local_9c >> 9 & 1) << 9 |
             (local_9c >> 10 & 1) << 10 |
             local_9c & 0x7f800 |
             (param_2 & 0x3f) << 0x13 | local_9c & 0xfe000000 | local_5c & 0x1ff;
  local_60 = 0;
  local_7c = 0;
  local_78 = 0;
  local_74 = 0;
  local_70 = 0;
  local_6c = 0;
  local_68 = 0;
  local_64 = 0;
  local_80 = &PTR__TType_a7b7cff8;
  iVar5 = (**(code **)*param_3)(param_3);
  ((int (*)())TIntermediate__addConstantUnion)(this,pcVar4,(unsigned char *)&local_80,iVar5);
  return;
}

/* TIntermediate__removeChildNode @ 0x97b964e8 (824 bytes) */
int TIntermediate__removeChildNode(this, param_1, param_2, param_3, param_4, param_5)
  unsigned char *this;
  unsigned char *param_1;
  unsigned char *param_2;
  int *param_3;
  unsigned char *param_4;
  unsigned char *param_5;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  ulong uVar10;
  undefined4 *puVar11;
  int *piVar12;
  int *piVar13;
  undefined4 uVar14;
  int iVar15;
  undefined *puVar16;
  undefined **local_b0 [9];
  uint local_8c;
  undefined **local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  uint local_5c;
  undefined4 local_50;
  int *local_4c [3];
  
  if (param_5 != (unsigned char *)0x0) {
    *(int *)param_4 = *(int *)(param_1 + 4) + *param_3 * 4;
    iVar8 = (**(code **)(*(int *)param_5 + 100))(param_5);
    iVar15 = *(int *)(param_1 + 8);
    iVar7 = *(int *)(param_1 + 4);
    if (*(int *)(iVar8 + 8) - *(int *)(iVar8 + 4) >> 2 == 1) {
      iVar9 = ((int (*)())TIntermediate__removeMatrixConstNode)(this,param_1,param_2,param_5,*param_3);
      if (iVar9 == 0) {
        iVar9 = 0;
        puVar16 = PTR_vtable_a7b7c0c8 + 8;
        while( true ) {
          (**(code **)(*(int *)param_5 + 0x38))(local_b0,param_5);
          if ((local_8c & 0x400) == 0) {
            iVar6 = (int)(local_8c << 0xd | local_8c >> 0x13) >> 0x18;
          }
          else {
            iVar6 = (int)(local_8c << 0xd | local_8c >> 0x13) >> 0x18;
            iVar6 = iVar6 * iVar6;
          }
          local_b0[0] = &PTR__TType_a7b7cff8;
          if (iVar6 <= iVar9) break;
          uVar10 = GetGlobalPoolAllocator();
          puVar11 = (undefined4 *)TPoolAllocator__allocate(uVar10);
          iVar9 = iVar9 + 1;
          iVar6 = (**(code **)(*(int *)**(undefined4 **)(iVar8 + 4) + 0x18))();
          *puVar11 = **(undefined4 **)(iVar6 + 0x30);
          uVar10 = GetGlobalPoolAllocator();
          piVar12 = (int *)TPoolAllocator__allocate(uVar10);
          piVar13 = (int *)(**(code **)(*(int *)**(undefined4 **)(iVar8 + 4) + 0x18))();
          (**(code **)(*piVar13 + 0x38))(&local_80,piVar13);
          *piVar12 = (int)&PTR_getLine_a7b7cf90;
          piVar12[1] = 0;
          piVar12[3] = local_7c;
          piVar12[4] = local_78;
          piVar12[5] = local_74;
          piVar12[6] = local_70;
          piVar12[7] = local_6c;
          piVar12[8] = local_68;
          piVar12[2] = (int)&PTR__TType_a7b7cff8;
          piVar12[9] = local_64;
          piVar12[10] = local_60;
          uVar5 = piVar12[0xb];
          uVar2 = local_5c & 0xfe000000;
          piVar12[0xb] = uVar2 | uVar5 & 0x1ffffff;
          uVar3 = (local_5c >> 0x13 & 0x3f) << 0x13;
          piVar12[0xb] = uVar3 | uVar2 | uVar5 & 0x7ffff;
          uVar1 = local_5c & 0x7f800;
          piVar12[0xb] = uVar1 | uVar3 | uVar2 | uVar5 & 0x7ff;
          uVar4 = (local_5c >> 10 & 1) << 10;
          piVar12[0xb] = uVar4 | uVar1 | uVar3 | uVar2 | uVar5 & 0x3ff;
          piVar12[0xb] = (local_5c >> 9 & 1) << 9 | uVar4 | uVar1 | uVar3 | uVar2 | uVar5 & 0x1ff;
          piVar12[0xc] = (int)puVar11;
          *piVar12 = (int)puVar16;
          local_80 = &PTR__TType_a7b7cff8;
          iVar6 = *piVar12;
          uVar14 = (*(code *)**(undefined4 **)param_5)(param_5);
          (**(code **)(iVar6 + 4))(piVar12,uVar14);
          iVar6 = *(int *)(param_1 + 4) + *param_3 * 4;
          *(int *)param_4 = iVar6;
          local_4c[0] = piVar12;
          std__vector_TIntermNode__pool_allocator_TIntermNode_____insert
                    (&local_50,param_1,iVar6,local_4c);
        }
      }
    }
    else {
      std::vector<TIntermNode*,pool_allocator<TIntermNode*>>::
      _M_range_insert<__gnu_cxx::__normal_iterator<TIntermNode**,std::vector<TIntermNode*,pool_allocator<TIntermNode*>>>>
                (param_1,*(undefined4 *)param_4,*(int *)(iVar8 + 4),*(int *)(iVar8 + 8),0);
    }
    iVar7 = (*param_3 + (*(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2)) -
            (iVar15 - iVar7 >> 2);
    *param_3 = iVar7;
    *(int *)param_4 = *(int *)(param_1 + 4) + iVar7 * 4;
    std__vector_TIntermNode__pool_allocator_TIntermNode_____erase(&local_50,param_1);
    *(undefined4 *)param_4 = local_50;
    *param_3 = *param_3 + -1;
    *(int *)param_4 = *(int *)param_4 + -4;
  }
  return;
}

/* TIntermediate__removeChildNode_97b96820 @ 0x97b96820 (496 bytes) */
int TIntermediate__removeChildNode_97b96820(this, param_1, param_2, param_3)
  unsigned char *this;
  unsigned char *param_1;
  unsigned char *param_2;
  unsigned char *param_3;
{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  TVector *pTVar5;
  int iVar6;
  int iVar7;
  undefined1 auStack_30 [20];
  
  iVar3 = (**(code **)(*(int *)param_2 + 0x30))(param_2);
  if (iVar3 == 1) {
    iVar3 = (**(code **)(*(int *)param_3 + 100))(param_3);
    param_1 = (unsigned char *)(**(code **)(*(int *)**(undefined4 **)(iVar3 + 4) + 0x14))();
  }
  else {
    iVar3 = (**(code **)(*(int *)param_2 + 0x30))(param_2);
    piVar4 = (int *)(**(code **)(*(int *)param_1 + 0x1c))(param_1);
    pTVar5 = (unsigned char *)(**(code **)(*piVar4 + 100))();
    iVar6 = (**(code **)(*(int *)param_3 + 100))(param_3);
    if (*(int *)(iVar6 + 8) - *(int *)(iVar6 + 4) >> 2 == 1) {
      iVar3 = ((int (*)())TIntermediate__removeMatrixConstNode)(this,pTVar5,param_2,param_3,1);
      if (iVar3 == 0) {
        iVar3 = (**(code **)(*(int *)param_3 + 100))(param_3);
        puVar1 = *(undefined4 **)(pTVar5 + 8);
        if (puVar1 == *(undefined4 **)(pTVar5 + 0xc)) {
          std__vector_TIntermNode__pool_allocator_TIntermNode______M_insert_aux(pTVar5,puVar1);
        }
        else {
          iVar6 = 0;
          if (puVar1 != (undefined4 *)0x0) {
            *puVar1 = **(undefined4 **)(iVar3 + 4);
            iVar6 = *(int *)(pTVar5 + 8);
          }
          *(int *)(pTVar5 + 8) = iVar6 + 4;
        }
      }
    }
    else {
      iVar6 = 0;
      if (0 < iVar3) {
        do {
          iVar7 = (**(code **)(*(int *)param_3 + 100))(param_3);
          puVar1 = *(undefined4 **)(pTVar5 + 8);
          if (puVar1 == *(undefined4 **)(pTVar5 + 0xc)) {
            std__vector_TIntermNode__pool_allocator_TIntermNode______M_insert_aux
                      (pTVar5,puVar1,*(int *)(iVar7 + 4) + iVar6 * 4);
          }
          else {
            iVar2 = 0;
            if (puVar1 != (undefined4 *)0x0) {
              *puVar1 = *(undefined4 *)(*(int *)(iVar7 + 4) + iVar6 * 4);
              iVar2 = *(int *)(pTVar5 + 8);
            }
            *(int *)(pTVar5 + 8) = iVar2 + 4;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < iVar3);
      }
    }
    std__vector_TIntermNode__pool_allocator_TIntermNode_____erase
              (auStack_30,pTVar5,*(undefined4 *)(pTVar5 + 4));
  }
  return param_1;
}

/* TIntermediate__removeMatrixConstNode @ 0x97b96a10 (776 bytes) */
int TIntermediate__removeMatrixConstNode(this, param_1, param_2, param_3, param_4)
  unsigned char *this;
  unsigned char *param_1;
  unsigned char *param_2;
  unsigned char *param_3;
  int param_4;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  ulong uVar9;
  undefined4 *puVar10;
  int *piVar11;
  int *piVar12;
  undefined *puVar13;
  int iVar14;
  undefined **local_b0 [9];
  uint local_8c;
  undefined **local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  uint local_5c;
  undefined1 auStack_50 [4];
  int *local_4c [3];
  
  uVar7 = 0;
  if (param_3 != (unsigned char *)0x0) {
    iVar8 = (**(code **)(*(int *)param_3 + 100))(param_3);
    uVar7 = 0;
    if (*(int *)(param_3 + 0x30) - 0x72U < 3) {
      iVar14 = 0;
      puVar13 = PTR_vtable_a7b7c0c8 + 8;
      while( true ) {
        (**(code **)(*(int *)param_3 + 0x38))(local_b0,param_3);
        if ((local_8c & 0x400) == 0) {
          iVar6 = (int)(local_8c << 0xd | local_8c >> 0x13) >> 0x18;
        }
        else {
          iVar6 = (int)(local_8c << 0xd | local_8c >> 0x13) >> 0x18;
          iVar6 = iVar6 * iVar6;
        }
        local_b0[0] = &PTR__TType_a7b7cff8;
        uVar7 = 1;
        if (iVar6 <= iVar14) break;
        uVar9 = GetGlobalPoolAllocator();
        puVar10 = (undefined4 *)TPoolAllocator__allocate(uVar9);
        (**(code **)(*(int *)param_3 + 0x38))(&local_80,param_3);
        local_80 = &PTR__TType_a7b7cff8;
        iVar6 = ((int)(local_5c << 0xd | local_5c >> 0x13) >> 0x18) + 1;
        if (iVar14 == (iVar14 / iVar6) * iVar6) {
          iVar6 = (**(code **)(*(int *)**(undefined4 **)(iVar8 + 4) + 0x18))();
          *puVar10 = **(undefined4 **)(iVar6 + 0x30);
        }
        else {
          iVar6 = (**(code **)(*(int *)param_2 + 0x20))(param_2);
          if (iVar6 == 2) {
LAB_97b96b5c:
            *puVar10 = 0;
          }
          else if (iVar6 < 3) {
            if (iVar6 == 1) {
              *puVar10 = 0;
            }
          }
          else if (iVar6 == 3) goto LAB_97b96b5c;
        }
        uVar9 = GetGlobalPoolAllocator();
        piVar11 = (int *)TPoolAllocator__allocate(uVar9);
        piVar12 = (int *)(**(code **)(*(int *)**(undefined4 **)(iVar8 + 4) + 0x18))();
        (**(code **)(*piVar12 + 0x38))(&local_80,piVar12);
        *piVar11 = (int)&PTR_getLine_a7b7cf90;
        piVar11[1] = 0;
        piVar11[3] = local_7c;
        piVar11[4] = local_78;
        piVar11[5] = local_74;
        piVar11[6] = local_70;
        piVar11[7] = local_6c;
        piVar11[8] = local_68;
        piVar11[2] = (int)&PTR__TType_a7b7cff8;
        piVar11[9] = local_64;
        piVar11[10] = local_60;
        uVar5 = piVar11[0xb];
        uVar2 = local_5c & 0xfe000000;
        piVar11[0xb] = uVar2 | uVar5 & 0x1ffffff;
        uVar3 = (local_5c >> 0x13 & 0x3f) << 0x13;
        piVar11[0xb] = uVar3 | uVar2 | uVar5 & 0x7ffff;
        uVar1 = local_5c & 0x7f800;
        piVar11[0xb] = uVar1 | uVar3 | uVar2 | uVar5 & 0x7ff;
        uVar4 = (local_5c >> 10 & 1) << 10;
        piVar11[0xb] = uVar4 | uVar1 | uVar3 | uVar2 | uVar5 & 0x3ff;
        piVar11[0xb] = (local_5c >> 9 & 1) << 9 | uVar4 | uVar1 | uVar3 | uVar2 | uVar5 & 0x1ff;
        piVar11[0xc] = (int)puVar10;
        *piVar11 = (int)puVar13;
        local_80 = &PTR__TType_a7b7cff8;
        iVar6 = *piVar11;
        uVar7 = (*(code *)**(undefined4 **)param_3)(param_3);
        (**(code **)(iVar6 + 4))(piVar11,uVar7);
        iVar6 = iVar14 * 4;
        iVar14 = iVar14 + 1;
        local_4c[0] = piVar11;
        std__vector_TIntermNode__pool_allocator_TIntermNode_____insert
                  (auStack_50,param_1,*(int *)(param_1 + 4) + param_4 * 4 + iVar6,local_4c);
      }
    }
  }
  return uVar7;
}

/* TIntermAggregate__addToPragmaTable @ 0x97b96d18 (184 bytes) */
int TIntermAggregate__addToPragmaTable(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  _Rb_tree<std::string,std::pair<std::string_const,std::string>,std::_Select1st<std::pair<std::string_const,std::string>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,std::string>>>
  *this_00;
  ulong uVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = *(int *)(this + 0x68);
  if (iVar3 != 0) {
    ___eprintf("%s:%u: failed assertion `%s\'\n",
               "/SourceCache/OpenGL/OpenGL-4.7.14/GLProgrammability/glslang/MachineIndependent/Intermediate.cpp"
               ,0x865,"!pragmaTable");
  }
  this_00 = operator_new(0x10);
  uVar1 = GetGlobalPoolAllocator();
  *(ulong *)this_00 = uVar1;
  *(int *)(this_00 + 4) = iVar3;
  piVar2 = (int *)TPoolAllocator__allocate(uVar1);
  *(int *)(this_00 + 8) = iVar3;
  *(int **)(this_00 + 4) = piVar2;
  *piVar2 = iVar3;
  *(int *)(*(int *)(this_00 + 4) + 4) = iVar3;
  *(int *)(*(int *)(this_00 + 4) + 8) = *(int *)(this_00 + 4);
  *(int *)(*(int *)(this_00 + 4) + 0xc) = *(int *)(this_00 + 4);
  *(_Rb_tree<std::string,std::pair<std::string_const,std::string>,std::_Select1st<std::pair<std::string_const,std::string>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,std::string>>>
    **)(this + 0x68) = this_00;
  std::
  _Rb_tree<std::string,std::pair<std::string_const,std::string>,std::_Select1st<std::pair<std::string_const,std::string>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,std::string>>>
  ::operator=(this_00,(unsigned char *)param_1);
  return;
}

/* TType__getCompleteString @ 0x97b96dd0 (276 bytes) */
int TType__getCompleteString()
{
  string *in_r3;
  undefined4 uVar1;
  int iVar2;
  int in_r4;
  uint uVar3;
  char *pcVar4;
  char acStack_90 [112];
  undefined4 local_20 [4];
  
  uVar3 = *(uint *)(in_r4 + 0x24);
  pcVar4 = acStack_90;
  if (1 < uVar3 >> 0x19) {
    uVar1 = getQualifierString();
    iVar2 = _sprintf(pcVar4,"%s ",uVar1);
    uVar3 = *(uint *)(in_r4 + 0x24);
    pcVar4 = pcVar4 + iVar2;
  }
  if ((uVar3 & 0x200) != 0) {
    iVar2 = _sprintf(pcVar4,"array of ");
    uVar3 = *(uint *)(in_r4 + 0x24);
    pcVar4 = pcVar4 + iVar2;
  }
  if ((uVar3 & 0x400) == 0) {
    iVar2 = (int)(uVar3 << 0xd | uVar3 >> 0x13) >> 0x18;
    if (iVar2 < 2) goto LAB_97b96e98;
    iVar2 = _sprintf(pcVar4,"%d-component vector of ",iVar2);
  }
  else {
    iVar2 = (int)(uVar3 << 0xd | uVar3 >> 0x13) >> 0x18;
    iVar2 = _sprintf(pcVar4,"%dX%d matrix of ",iVar2,iVar2);
  }
  uVar3 = *(uint *)(in_r4 + 0x24);
  pcVar4 = pcVar4 + iVar2;
LAB_97b96e98:
  uVar1 = TType__getBasicString(uVar3 >> 0x13 & 0x3f);
  _sprintf(pcVar4,"%s",uVar1);
  local_20[0] = GetGlobalPoolAllocator();
  std__string__string(in_r3,acStack_90,(unsigned char *)local_20);
  return in_r3;
}

/* OutputTreeText @ 0x97b96ee4 (240 bytes) */
int OutputTreeText(param_1, param_2, param_3)
  unsigned char *param_1;
  unsigned char *param_2;
  int param_3;
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  char in_RESERVE;
  byte bVar6;
  int local_80 [4];
  char acStack_70 [64];
  allocator aaStack_30 [28];
  
  uVar5 = (*(code *)**(undefined4 **)param_2)(param_2);
  bVar1 = (uVar5 & 0xffff) == 0;
  bVar6 = bVar1 << 1;
  if (bVar1) {
    _sprintf(acStack_70,"%d:? ",(int)uVar5 >> 0x10);
  }
  else {
    _sprintf(acStack_70,"%d:%d",(int)uVar5 >> 0x10);
  }
  std__string__string((unsigned char *)local_80,acStack_70,aaStack_30);
  ((int (*)())TInfoSinkBase__append)((unsigned char *)(param_1 + 8));
  piVar3 = (int *)(local_80[0] + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar6 = 2;
    }
  } while (!(bool)(bVar6 >> 1 & 1));
  if (iVar4 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(local_80[0] + -0xc));
  }
  if (0 < param_3) {
    do {
      ((int (*)())TInfoSinkBase__append)((char *)(param_1 + 8));
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}

/* OutputSymbol @ 0x97b96fd4 (268 bytes) */
int OutputSymbol(param_1, param_2)
  unsigned char *param_1;
  unsigned char *param_2;
{
  undefined1 *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  char in_RESERVE;
  byte in_cr0;
  char acStack_b0 [112];
  undefined4 local_40;
  int local_3c;
  undefined4 local_30;
  
  ((int (*)())OutputTreeText)(*(TInfoSink **)(param_2 + 0x30),(unsigned char *)param_1,*(int *)(param_2 + 0x20));
  ((int (*)())TType__getCompleteString)();
  iVar3 = local_3c;
  puVar1 = DAT_a7b7b9e0;
  *(undefined1 *)(local_3c + *(int *)(local_3c + -0xc)) = *DAT_a7b7b9e0;
  iVar4 = (**(code **)(*(int *)param_1 + 0x60))(param_1);
  *(undefined1 *)(*(int *)(iVar4 + 4) + *(int *)(*(int *)(iVar4 + 4) + -0xc)) = *puVar1;
  uVar6 = *(undefined4 *)(iVar4 + 4);
  uVar5 = (**(code **)(*(int *)param_1 + 0x5c))(param_1);
  _sprintf(acStack_b0,"\'%s\' (%s) id: %d\n",uVar6,iVar3,uVar5);
  piVar2 = (int *)(local_3c + -4);
  local_30 = local_40;
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      iVar4 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = iVar4;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar3 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(local_3c + -0xc));
  }
  ((int (*)())TInfoSinkBase__append)((char *)(*(int *)(param_2 + 0x30) + 8));
  return;
}

/* OutputBinary @ 0x97b970e0 (248 bytes) */
int OutputBinary(param_1, param_2, param_3)
  int param_1;
  unsigned char *param_2;
  unsigned char *param_3;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  TInfoSink *pTVar4;
  string *psVar5;
  char in_RESERVE;
  byte in_cr0;
  int local_2c;
  
  pTVar4 = *(TInfoSink **)(param_3 + 0x30);
  ((int (*)())OutputTreeText)(pTVar4,(unsigned char *)param_2,*(int *)(param_3 + 0x20));
  psVar5 = (unsigned char *)(pTVar4 + 8);
  ((int (*)())TInfoSinkBase__append)((char *)psVar5);
  ((int (*)())TInfoSinkBase__append)((char *)psVar5);
  ((int (*)())TType__getCompleteString)();
  ((int (*)())TInfoSinkBase__append)(psVar5);
  ((int (*)())TInfoSinkBase__append)((char *)psVar5);
  piVar2 = (int *)(local_2c + -4);
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar3 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(local_2c + -0xc));
  }
  ((int (*)())TInfoSinkBase__append)((char *)psVar5);
  return 1;
}

/* OutputUnary @ 0x97b971d8 (224 bytes) */
int OutputUnary(param_1, param_2, param_3)
  int param_1;
  unsigned char *param_2;
  unsigned char *param_3;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  string *psVar4;
  char in_RESERVE;
  byte in_cr0;
  int local_2c;
  
  psVar4 = (unsigned char *)(*(TInfoSink **)(param_3 + 0x30) + 8);
  ((int (*)())OutputTreeText)(*(TInfoSink **)(param_3 + 0x30),(unsigned char *)param_2,*(int *)(param_3 + 0x20));
  ((int (*)())TInfoSinkBase__append)((char *)psVar4);
  ((int (*)())TInfoSinkBase__append)((char *)psVar4);
  ((int (*)())TType__getCompleteString)();
  ((int (*)())TInfoSinkBase__append)(psVar4);
  ((int (*)())TInfoSinkBase__append)((char *)psVar4);
  piVar2 = (int *)(local_2c + -4);
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar3 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(local_2c + -0xc));
  }
  ((int (*)())TInfoSinkBase__append)((char *)psVar4);
  return 1;
}

/* OutputAggregate @ 0x97b972b8 (292 bytes) */
int OutputAggregate(param_1, param_2, param_3)
  int param_1;
  unsigned char *param_2;
  unsigned char *param_3;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined3 in_register_0000000c;
  undefined4 uVar4;
  TInfoSink *pTVar5;
  string *psVar6;
  char in_RESERVE;
  byte in_cr0;
  int local_2c;
  
  pTVar5 = *(TInfoSink **)(param_3 + 0x30);
  if (*(int *)(param_2 + 0x30) == 0) {
                    
                    
    uVar4 = (*(code *)(((unsigned char *)0x97b97308) + (*(unsigned char *)0x97b97310)))(CONCAT31(in_register_0000000c,param_1));
    return uVar4;
  }
  ((int (*)())OutputTreeText)(pTVar5,(unsigned char *)param_2,*(int *)(param_3 + 0x20));
  psVar6 = (unsigned char *)(pTVar5 + 8);
  ((int (*)())TInfoSinkBase__append)((char *)psVar6);
  if ((*(int *)(param_2 + 0x30) != 1) && (*(int *)(param_2 + 0x30) != 4)) {
    ((int (*)())TInfoSinkBase__append)((char *)psVar6);
    ((int (*)())TType__getCompleteString)();
    ((int (*)())TInfoSinkBase__append)(psVar6);
    ((int (*)())TInfoSinkBase__append)((char *)psVar6);
    piVar2 = (int *)(local_2c + -4);
    do {
      iVar3 = *piVar2;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
        *piVar2 = iVar1;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar3 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_2c + -0xc));
    }
  }
  ((int (*)())TInfoSinkBase__append)((char *)psVar6);
  return 1;
}

/* OutputSelection @ 0x97b97450 (516 bytes) */
int OutputSelection(param_1, param_2, param_3)
  int param_1;
  unsigned char *param_2;
  unsigned char *param_3;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  string *psVar4;
  char in_RESERVE;
  byte in_cr0;
  int local_2c;
  
  psVar4 = (unsigned char *)(*(TInfoSink **)(param_3 + 0x30) + 8);
  ((int (*)())OutputTreeText)(*(TInfoSink **)(param_3 + 0x30),(unsigned char *)param_2,*(int *)(param_3 + 0x20));
  ((int (*)())TInfoSinkBase__append)((char *)psVar4);
  ((int (*)())TInfoSinkBase__append)((char *)psVar4);
  ((int (*)())TType__getCompleteString)();
  ((int (*)())TInfoSinkBase__append)(psVar4);
  ((int (*)())TInfoSinkBase__append)((char *)psVar4);
  piVar2 = (int *)(local_2c + -4);
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar3 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(local_2c + -0xc));
  }
  iVar3 = *(int *)(param_3 + 0x20);
  *(int *)(param_3 + 0x20) = iVar3 + 1;
  ((int (*)())OutputTreeText)(*(TInfoSink **)(param_3 + 0x30),(unsigned char *)param_2,iVar3 + 1);
  ((int (*)())TInfoSinkBase__append)((char *)psVar4);
  piVar2 = (int *)(**(code **)(*(int *)param_2 + 0x5c))(param_2);
  (**(code **)(*piVar2 + 8))(piVar2,param_3);
  ((int (*)())OutputTreeText)(*(TInfoSink **)(param_3 + 0x30),(unsigned char *)param_2,*(int *)(param_3 + 0x20));
  iVar3 = (**(code **)(*(int *)param_2 + 0x60))(param_2);
  if (iVar3 == 0) {
    ((int (*)())TInfoSinkBase__append)((char *)psVar4);
  }
  else {
    ((int (*)())TInfoSinkBase__append)((char *)psVar4);
    piVar2 = (int *)(**(code **)(*(int *)param_2 + 0x60))(param_2);
    (**(code **)(*piVar2 + 8))(piVar2,param_3);
  }
  iVar3 = (**(code **)(*(int *)param_2 + 100))(param_2);
  if (iVar3 != 0) {
    ((int (*)())OutputTreeText)(*(TInfoSink **)(param_3 + 0x30),(unsigned char *)param_2,*(int *)(param_3 + 0x20));
    ((int (*)())TInfoSinkBase__append)((char *)psVar4);
    piVar2 = (int *)(**(code **)(*(int *)param_2 + 100))(param_2);
    (**(code **)(*piVar2 + 8))(piVar2,param_3);
  }
  *(int *)(param_3 + 0x20) = *(int *)(param_3 + 0x20) + -1;
  return 0;
}

/* OutputConstantUnion @ 0x97b97654 (664 bytes) */
int OutputConstantUnion(param_1, param_2)
  unsigned char *param_1;
  unsigned char *param_2;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  TInfoSink *pTVar4;
  TInfoSink *pTVar5;
  undefined8 uVar6;
  undefined **local_1c0 [9];
  uint local_19c;
  undefined **local_190 [6];
  int local_178;
  uint local_16c;
  char acStack_160 [312];
  
  pTVar5 = *(TInfoSink **)(param_2 + 0x30);
  (**(code **)(*(int *)param_1 + 0x38))(local_1c0,param_1);
  local_1c0[0] = &PTR__TType_a7b7d080;
  if ((local_19c >> 0x13 & 0x3f) == 0xe) {
    (**(code **)(*(int *)param_1 + 0x38))(local_190,param_1);
    iVar1 = local_178;
  }
  else {
    (**(code **)(*(int *)param_1 + 0x38))(local_190,param_1);
    if ((local_16c & 0x400) == 0) {
      iVar1 = (int)(local_16c << 0xd | local_16c >> 0x13) >> 0x18;
    }
    else {
      iVar1 = (int)(local_16c << 0xd | local_16c >> 0x13) >> 0x18;
      iVar1 = iVar1 * iVar1;
    }
  }
  local_190[0] = &PTR__TType_a7b7d080;
  iVar3 = 0;
  if (0 < iVar1) {
    do {
      ((int (*)())OutputTreeText)(pTVar5,(unsigned char *)param_1,*(int *)(param_2 + 0x20));
      uVar6 = (**(code **)(*(int *)param_1 + 0x38))(local_1c0,param_1);
      uVar2 = local_19c >> 0x13 & 0x3f;
      local_1c0[0] = &PTR__TType_a7b7d080;
      if (uVar2 == 2) {
        _sprintf((char *)local_1c0,"%d (%s)",*(undefined4 *)(*(int *)(param_1 + 0x30) + iVar3 * 4),
                 "const int");
LAB_97b977f0:
        ((int (*)())TInfoSinkBase__append)((char *)(pTVar5 + 8));
      }
      else {
        if (2 < uVar2) {
          if (uVar2 != 3) goto LAB_97b97890;
          pTVar4 = pTVar5 + 8;
          ((int (*)())TInfoSinkBase__append)((char *)pTVar4);
          ((int (*)())TInfoSinkBase__append)((char *)pTVar4);
          ((int (*)())TInfoSinkBase__append)((char *)pTVar4);
          goto LAB_97b977f0;
        }
        if (uVar2 != 1) {
LAB_97b97890:
          (*(code *)**(undefined4 **)param_1)(param_1);
                    
                    
          (*(code *)(((unsigned char *)0x97b978c8) + (*(unsigned char *)0x97b978d4)))();
          return;
        }
        ((char * (*)())_glp_dtostr)((double)*(float *)(*(int *)(param_1 + 0x30) + iVar3 * 4),DOUBLE_97c30a70,
                    (int)((ulonglong)uVar6 >> 0x20),(int)uVar6,acStack_160,300);
        _sprintf(acStack_160,"%s (%s)",acStack_160,"const float");
        ((int (*)())TInfoSinkBase__append)((char *)(pTVar5 + 8));
      }
      iVar3 = iVar3 + 1;
      ((int (*)())TInfoSinkBase__append)((char *)(pTVar5 + 8));
    } while (iVar3 < iVar1);
  }
  return;
}

/* OutputLoop @ 0x97b97a04 (400 bytes) */
int OutputLoop(param_1, param_2, param_3)
  int param_1;
  unsigned char *param_2;
  unsigned char *param_3;
{
  int iVar1;
  TInfoSink *pTVar2;
  
  pTVar2 = *(TInfoSink **)(param_3 + 0x30) + 8;
  ((int (*)())OutputTreeText)(*(TInfoSink **)(param_3 + 0x30),(unsigned char *)param_2,*(int *)(param_3 + 0x20));
  ((int (*)())TInfoSinkBase__append)((char *)pTVar2);
  if (*(int *)(param_2 + 0x14) == 0) {
    ((int (*)())TInfoSinkBase__append)((char *)pTVar2);
  }
  ((int (*)())TInfoSinkBase__append)((char *)pTVar2);
  iVar1 = *(int *)(param_3 + 0x20);
  *(int *)(param_3 + 0x20) = iVar1 + 1;
  ((int (*)())OutputTreeText)(*(TInfoSink **)(param_3 + 0x30),(unsigned char *)param_2,iVar1 + 1);
  if (*(int *)(param_2 + 0xc) == 0) {
    ((int (*)())TInfoSinkBase__append)((char *)pTVar2);
  }
  else {
    ((int (*)())TInfoSinkBase__append)((char *)pTVar2);
    (**(code **)(**(int **)(param_2 + 0xc) + 8))(*(int **)(param_2 + 0xc),param_3);
  }
  ((int (*)())OutputTreeText)(*(TInfoSink **)(param_3 + 0x30),(unsigned char *)param_2,*(int *)(param_3 + 0x20));
  if (*(int *)(param_2 + 8) == 0) {
    ((int (*)())TInfoSinkBase__append)((char *)pTVar2);
  }
  else {
    ((int (*)())TInfoSinkBase__append)((char *)pTVar2);
    (**(code **)(**(int **)(param_2 + 8) + 8))(*(int **)(param_2 + 8),param_3);
  }
  if (*(int *)(param_2 + 0x10) != 0) {
    ((int (*)())OutputTreeText)(*(TInfoSink **)(param_3 + 0x30),(unsigned char *)param_2,*(int *)(param_3 + 0x20));
    ((int (*)())TInfoSinkBase__append)((char *)pTVar2);
    (**(code **)(**(int **)(param_2 + 0x10) + 8))(*(int **)(param_2 + 0x10),param_3);
  }
  *(int *)(param_3 + 0x20) = *(int *)(param_3 + 0x20) + -1;
  return 0;
}

/* OutputBranch @ 0x97b97b94 (200 bytes) */
int OutputBranch(param_1, param_2, param_3)
  int param_1;
  unsigned char *param_2;
  unsigned char *param_3;
{
  TInfoSink *pTVar1;
  
  pTVar1 = *(TInfoSink **)(param_3 + 0x30) + 8;
  ((int (*)())OutputTreeText)(*(TInfoSink **)(param_3 + 0x30),(unsigned char *)param_2,*(int *)(param_3 + 0x20));
  ((int (*)())TInfoSinkBase__append)((char *)pTVar1);
  if (*(int *)(param_2 + 0xc) == 0) {
    ((int (*)())TInfoSinkBase__append)((char *)pTVar1);
  }
  else {
    ((int (*)())TInfoSinkBase__append)((char *)pTVar1);
    *(int *)(param_3 + 0x20) = *(int *)(param_3 + 0x20) + 1;
    (**(code **)(**(int **)(param_2 + 0xc) + 8))(*(int **)(param_2 + 0xc),param_3);
    *(int *)(param_3 + 0x20) = *(int *)(param_3 + 0x20) + -1;
  }
  return 0;
}

/* TIntermediate__outputTree @ 0x97b97c5c (228 bytes) */
int TIntermediate__outputTree(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
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
  int local_20;
  
  if (param_1 != (unsigned char *)0x0) {
    local_20 = *(int *)this;
    local_3c = DAT_a7b7b9dc;
    local_48 = DAT_a7b7b9d8;
    local_4c = DAT_a7b7b9d4;
    local_40 = DAT_a7b7b9d0;
    local_50 = DAT_a7b7b9cc;
    local_44 = DAT_a7b7b9c8;
    local_38 = DAT_a7b7b9c4;
    local_24 = 0;
    local_34 = DAT_a7b7b9c0;
    local_30 = 0;
    local_2c = 1;
    local_28 = 0;
    ((int (*)())TInfoSinkBase__append)((char *)(local_20 + 8));
    local_28 = 1;
    local_2c = 1;
    (**(code **)(*(int *)param_1 + 8))(param_1,&local_50);
  }
  return;
}

/* TIntermSymbol__traverse @ 0x97b97d40 (20 bytes) */
int TIntermSymbol__traverse(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  if (*(code **)param_1 == (code *)0x0) {
    return;
  }
                    
                    
  (**(code **)param_1)();
  return;
}

