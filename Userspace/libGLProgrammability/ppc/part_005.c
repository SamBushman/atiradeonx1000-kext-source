#include "decls.h"

/* __ZN13TParseContext14boolErrorCheckEiPK12TIntermTyped @ 0x97b9ba78 (208 bytes) */
int __ZN13TParseContext14boolErrorCheckEiPK12TIntermTyped(this, param_2, intermTyped, param_4, param_5, param_6)
  void *this;
  int param_2;
  unsigned char * intermTyped;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  int iVar1;
  undefined4 in_r9;
  undefined4 in_r10;
  
  iVar1 = (**(code **)(*(int *)intermTyped + 0x40))(intermTyped,param_2,intermTyped,param_4,param_5,param_6);
  if ((((iVar1 == 3) && (iVar1 = (**(code **)(*(int *)intermTyped + 0x54))(intermTyped), iVar1 == 0)) &&
      (iVar1 = (**(code **)(*(int *)intermTyped + 0x50))(intermTyped), iVar1 == 0)) &&
     (iVar1 = (**(code **)(*(int *)intermTyped + 0x58))(intermTyped), iVar1 == 0)) {
    return 0;
  }
  TParseContext__error
            ((int)this,(char *)param_2,"boolean expression expected","","",param_6,in_r9,in_r10);
  return 1;
}

/* __ZN13TParseContext14boolErrorCheckEiRK11TPublicType @ 0x97b9bb48 (132 bytes) */
int __ZN13TParseContext14boolErrorCheckEiRK11TPublicType(this, param_2, publicType)
  void *this;
  int param_2;
  unsigned char * publicType;
{
  undefined4 uVar1;
  undefined4 in_r8;
  undefined4 in_r9;
  undefined4 in_r10;
  
  if ((((*(int *)publicType != 3) || (*(int *)(publicType + 0x10) != 0)) || (*(int *)(publicType + 0xc) != 0)
      ) || (uVar1 = 0, 1 < *(int *)(publicType + 8))) {
    TParseContext__error
              ((int)this,(char *)param_2,"boolean expression expected","","",in_r8,in_r9,in_r10);
    uVar1 = 1;
  }
  return uVar1;
}

/* TParseContext__samplerErrorCheck @ 0x97b9bbcc (184 bytes) */
int TParseContext__samplerErrorCheck(this, param_2, publicType, str)
  unsigned char * this;
  int param_2;
  unsigned char * publicType;
  char *str;
{
  int containsSamplerResult;
  int iVar1;
  char *basicString;
  char *pcVar3;
  undefined4 in_r8;
  undefined4 in_r9;
  undefined4 in_r10;
  
  iVar1 = *(int *)publicType;
  if (iVar1 == 0xe) {
    containsSamplerResult = ((int (*)())TParseContext__containsSampler)(this,*(unsigned char **)(publicType + 0x14));
    if (containsSamplerResult == 0) {
      return 0;
    }
    basicString = (char *)TType__getBasicString(*(undefined4 *)publicType);
    pcVar3 = "(structure contains a sampler)";
  }
  else {
    if (7 < iVar1 - 5U) {
      return 0;
    }
    basicString = (char *)TType__getBasicString(iVar1);
    pcVar3 = "";
  }
  error((int)this,(char *)param_2,str,basicString,pcVar3,in_r8,in_r9,in_r10);
  return 1;
}

/* TParseContext__structQualifierErrorCheck @ 0x97b9bc84 (172 bytes) */
int TParseContext__structQualifierErrorCheck(this, param_2, publicType, param_4, param_5, param_6, param_7)
  unsigned char * this;
  int param_2;
  unsigned char * publicType;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  int iVar1;
  char *qualifierString;
  undefined4 uVar3;
  undefined4 in_r10;
  
  iVar1 = *(int *)(publicType + 4);
  if ((iVar1 - 3U < 3) && (*(int *)publicType == 0xe)) {
    qualifierString = (char *)getQualifierString(iVar1);
    error((int)this,(char *)param_2,"cannot be used with a structure",qualifierString,"",param_6,param_7,
          in_r10);
    uVar3 = 1;
  }
  else {
    if ((iVar1 != 6) &&
       (iVar1 = ((int (*)())TParseContext__samplerErrorCheck)(this,param_2,publicType,"samplers must be uniform"), iVar1 != 0)) {
      return 1;
    }
    uVar3 = 0;
  }
  return uVar3;
}

/* TParseContext__parameterSamplerErrorCheck @ 0x97b9bd30 (184 bytes) */
int TParseContext__parameterSamplerErrorCheck(this, param_2, qualifier, type)
  unsigned char * this;
  int param_2;
  int qualifier;
  int *type;
{
  int iVar1;
  char *basicString;
  undefined4 uVar3;
  undefined4 in_r8;
  undefined4 in_r9;
  undefined4 in_r10;
  
  if (((qualifier - 10U < 2) && (iVar1 = (**(code **)(*type + 0x20))(type), iVar1 != 0xe)) &&
     (iVar1 = (**(code **)(*type + 0x20))(type), iVar1 - 5U < 8)) {
    basicString = (char *)TType__getBasicString((uint)type[9] >> 0x13 & 0x3f);
    error((int)this,(char *)param_2,"samplers cannot be output parameters",basicString,"",in_r8,in_r9,
          in_r10);
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}

/* TParseContext__containsSampler @ 0x97b9bde8 (180 bytes) */
int TParseContext__containsSampler(this, type)
  unsigned char * this;
  unsigned char * type;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  iVar1 = (**(code **)(*(int *)type + 0x20))(type,type);
  uVar2 = 1;
  if (7 < iVar1 - 5U) {
    iVar1 = (**(code **)(*(int *)type + 0x20))(type);
    if (iVar1 == 0xe) {
      iVar1 = *(int *)(type + 8);
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
  int *refCountPtr;
  int newRefCount;
  int oldRefCount;
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
  char reservation;
  byte cr0Flags;
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
  cr0Flags = (this_00 == (void *)0x0) << 1;
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
      cr0Flags = *DAT_a7b7ba18;
      pcVar9 = "INTERNAL ERROR finding symbol";
LAB_97b9c154:
      *(byte *)(iVar13 + iVar10) = cr0Flags;
      error((int)this,(char *)0x0,pcVar9,*(char **)((int)pvVar12 + 4),"",in_r8,(uint)cr0Flags,in_r10);
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
  refCountPtr = (int *)(local_3c + -4);
  local_5c = local_4c;
  local_30[0] = local_40;
  do {
    oldRefCount = *refCountPtr;
    if (reservation != '\0') {
      newRefCount = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
      *refCountPtr = newRefCount;
      cr0Flags = 2;
    }
  } while (!(bool)(cr0Flags >> 1 & 1));
  if (oldRefCount < 1) {
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
              ((unsigned char *)(local_3c + -0xc),local_30);
  }
  if (local_5c != 0) {
    return 0;
  }
  (**(code **)(*a0 + 4))(a0);
  iVar13 = *(int *)((int)pvVar12 + 4);
  iVar10 = *(int *)(iVar13 + -0xc);
  cr0Flags = *DAT_a7b7ba18;
  pcVar9 = "INTERNAL ERROR inserting new symbol";
  goto LAB_97b9c154;
}

/* TParseContext__arrayErrorCheck @ 0x97b9c180 (2552 bytes) */
int TParseContext__arrayErrorCheck(parseContext, line, text, publicType, intermTyped, ptSize, ptMatrix, ptArray, ptUserDef, ptLine, arraySizeNode)
  int parseContext;
  unsigned char * line;
  unsigned char * text;
  uint publicType;
  uint intermTyped;
  uint ptSize;
  uint ptMatrix;
  uint ptArray;
  unsigned char * ptUserDef;
  undefined4 ptLine;
  int *arraySizeNode;
{
  uint ptCopyQualifier;
  uint ptCopyType;
  uint pt2CopyLine;
  unsigned char * pt2CopyUserDef;
  uint pt2CopyArray;
  uint pt2CopySize;
  unsigned char * pt2CopyQualifier;
  uint pt2CopyType;
  uint ptCopyLine;
  unsigned char * ptCopyUserDef;
  uint ptCopyArray;
  unsigned char * variableNameString;
  undefined8 typeNameAllocation;
  undefined8 structSizeResult;
  uint stringTerminator;
  char *errorReason;
  char *structTypeNameChars;
  int identifierChars;
  int levelsBegin;
  int *newVariable;
  int redeclaredArrayNode;
  int isArray;
  int isVariable;
  int identifierLength;
  int voidErrorResult;
  int uniqueId;
  int structTypeNameStringRef;
  int levelIndex;
  int *symbolTable;
  int *arraySizeUnion;
  uint sizeField;
  unsigned int ghidra_home[8] = { parseContext, line, text, publicType, intermTyped, ptSize, ptMatrix, ptArray };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  bool noArraySizeNode;
  bool typesMatch;
  uint qualifierField;
  uint basicTypeField;
  uint matrixField;
  undefined **structTypeName;
  int *piVar7;
  uint oldVariableBits;
  int iVar9;
  unsigned char * poolAllocator;
  void *this;
  unsigned char * psVar11;
  undefined **structTypeNameString;
  undefined4 a1;
  undefined4 extraout_r4;
  undefined4 passThroughR4;
  undefined4 a1_00;
  char *pcVar14;
  unsigned char * a2;
  undefined4 a3;
  uint uVar15;
  uint uVar16;
  int iVar17;
  char *structTypeNameChars2;
  int currentLevel;
  int *a0;
  undefined4 symbolTableLevel;
  int *symbolTableLevels;
  char reservation;
  byte cr0Reg;
  byte cr0Flags;
  undefined8 variableAllocation;
  undefined **stackType;
  char *stackTypeArraySize;
  int stackTypeStructure;
  char *stackTypeFieldName;
  undefined **stackTypeTypeNameOrStackTypeB;
  char *stackTypeWord14OrStackTypeBArraySize;
  char *stackTypeStructureSizeOrStackTypeBStructure;
  char *stackTypeWord1cOrStackTypeBFieldName;
  char *stackTypeWord20OrStackTypeBTypeName;
  uint stackTypeBitsOrStackTypeBWord14;
  undefined4 stackTypeBStructureSize;
  undefined4 stackTypeBWord1c;
  uint local_100;
  uint local_fc;
  uint ptCopySize;
  uint ptCopyMatrix;
  uint local_f0;
  unsigned char * local_ec;
  uint local_e8;
  uint local_e4;
  uint local_e0;
  unsigned char * local_dc;
  uint local_d8;
  uint pt2CopyMatrix;
  uint local_d0;
  unsigned char * local_cc;
  uint local_c8;
  uint local_c4;
  uint local_c0;
  unsigned char * local_bc;
  undefined4 local_b8;
  undefined4 destroyAllocator2 [4];
  undefined **destroyAllocator3 [4];
  int levelFindResult [4];
  undefined4 poolAllocatorArg1 [4];
  undefined4 nameCopy;
  int nameCopyChars;
  int *variableForInsert;
  undefined4 destroyAllocator1 [4];
  undefined4 poolAllocatorArg2 [4];
  uint builtIn;
  uint sameScope;
  
  (*(uint *)((unsigned char *)ghidra_home + 12)) = publicType;
  (*(uint *)((unsigned char *)ghidra_home + 16)) = intermTyped;
  (*(uint *)((unsigned char *)ghidra_home + 20)) = ptSize;
  (*(uint *)((unsigned char *)ghidra_home + 24)) = ptMatrix;
  if (((ptArray == 0) && (intermTyped != 3)) && (intermTyped != 2)) {
    noArraySizeNode = arraySizeNode == (int *)0x0;
    (*(uint *)((unsigned char *)ghidra_home + 28)) = 1;
    arraySizeUnion = (int *)0x0;
    if ((noArraySizeNode) ||
       (((arraySizeUnion = (int *)(**(code **)(*arraySizeNode + 0x18))(arraySizeNode), arraySizeUnion != (int *)0x0 &&
         (iVar9 = (**(code **)(*arraySizeUnion + 0x40))(arraySizeUnion), iVar9 == 2)) && (0 < *(int *)arraySizeUnion[0xc])))
       ) {
      symbolTableLevels = *(int **)(parseContext + 4);
      sameScope = 0;
      builtIn = 0;
      levelsBegin = *symbolTableLevels;
      levelIndex = (symbolTableLevels[1] - levelsBegin >> 2) + -1;
      while( true ) {
        currentLevel = *(int *)(levelsBegin + levelIndex * 4);
        psVar11 = text;
        std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______find((unsigned char *)levelFindResult,currentLevel,text);
        a0 = (int *)0x0;
        if (levelFindResult[0] != *(int *)(currentLevel + 4)) {
          a0 = *(int **)(levelFindResult[0] + 0x18);
        }
        if ((a0 != (int *)0x0) || (levelIndex + -1 < 0)) break;
        levelsBegin = *symbolTableLevels;
        levelIndex = levelIndex + -1;
      }
      if (&STACKARG(0x0) != (undefined1 *)0x40) {
        builtIn = (uint)(levelIndex == 0);
      }
      if (&STACKARG(0x0) != (undefined1 *)0x3c) {
        sameScope = (uint)(levelIndex == (symbolTableLevels[1] - *symbolTableLevels >> 2) + -1);
      }
      if ((a0 == (int *)0x0) || (sameScope == 0)) {
        stackTypeArraySize = (char *)TParseContext__reservedErrorCheck((unsigned char *)parseContext,(int)line,text);
        cr0Flags = (stackTypeArraySize == (char *)0x0) << 1;
        if (stackTypeArraySize != (char *)0x0) {
          return 1;
        }
        poolAllocator = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
        variableAllocation = ((int (*)())TPoolAllocator__allocate)(poolAllocator,0x40);
        newVariable = (int *)((ulonglong)variableAllocation >> 0x20);
        passThroughR4 = (undefined4)variableAllocation;
        stackTypeBitsOrStackTypeBWord14 = ((*(uint *)((unsigned char *)ghidra_home + 28)) & 1) << 9 |
                    ((*(uint *)((unsigned char *)ghidra_home + 24)) & 1) << 10 |
                    ((*(uint *)((unsigned char *)ghidra_home + 20)) & 0xff) << 0xb |
                    ((*(uint *)((unsigned char *)ghidra_home + 12)) & 0x3f) << 0x13 | (*(uint *)((unsigned char *)ghidra_home + 16)) << 0x19 | stackTypeBitsOrStackTypeBWord14 & 0x1ff;
        pt2CopyLine = ptLine;
        stackType = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
        ptCopyType = (*(uint *)((unsigned char *)ghidra_home + 12));
        ptCopyQualifier = (*(uint *)((unsigned char *)ghidra_home + 16));
        ptCopySize = (*(uint *)((unsigned char *)ghidra_home + 20));
        ptCopyMatrix = (*(uint *)((unsigned char *)ghidra_home + 24));
        ptCopyArray = (*(uint *)((unsigned char *)ghidra_home + 28));
        ptCopyUserDef = ptUserDef;
        ptCopyLine = ptLine;
        pt2CopyType = (*(uint *)((unsigned char *)ghidra_home + 12));
        pt2CopyQualifier = (unsigned char *)(*(uint *)((unsigned char *)ghidra_home + 16));
        pt2CopySize = (*(uint *)((unsigned char *)ghidra_home + 20));
        pt2CopyMatrix = (*(uint *)((unsigned char *)ghidra_home + 24));
        pt2CopyArray = (*(uint *)((unsigned char *)ghidra_home + 28));
        pt2CopyUserDef = ptUserDef;
        stackTypeStructure = 0;
        stackTypeStructureSizeOrStackTypeBStructure = (char *)0x0;
        a2 = ptUserDef;
        a3 = ptLine;
        uVar16 = (*(uint *)((unsigned char *)ghidra_home + 16));
        ptSize = (*(uint *)((unsigned char *)ghidra_home + 20));
        stackTypeFieldName = stackTypeArraySize;
        structTypeName = (undefined **)0x0;
        stackTypeWord14OrStackTypeBArraySize = stackTypeArraySize;
        stackTypeWord1cOrStackTypeBFieldName = stackTypeArraySize;
        stackTypeWord20OrStackTypeBTypeName = stackTypeArraySize;
        if (ptUserDef != (unsigned char *)0x0) {
          stackTypeStructure = *(int *)(ptUserDef + 8);
          stackTypeTypeNameOrStackTypeB = (undefined **)stackTypeArraySize;
          stackTypeStructureSizeOrStackTypeBStructure = stackTypeArraySize;
          structSizeResult = TType__setStructSize((unsigned char *)&stackType,*(unsigned char **)(ptUserDef + 8));
          stackTypeStructureSizeOrStackTypeBStructure = (char *)((ulonglong)structSizeResult >> 0x20);
          structTypeNameStringRef = (**(code **)(*(int *)pt2CopyUserDef + 0x18))
                            (pt2CopyUserDef,(int)structSizeResult,a2,a3,uVar16,ptSize,*(int *)pt2CopyUserDef);
          *(byte *)(*(int *)(structTypeNameStringRef + 4) + *(int *)(*(int *)(structTypeNameStringRef + 4) + -0xc)) = *DAT_a7b7ba18;
          structTypeNameChars = *(char **)(structTypeNameStringRef + 4);
          poolAllocator = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
          typeNameAllocation = ((int (*)())TPoolAllocator__allocate)(poolAllocator,8);
          structTypeNameString = (undefined **)((ulonglong)typeNameAllocation >> 0x20);
          passThroughR4 = (undefined4)typeNameAllocation;
          cr0Flags = (structTypeNameString == (undefined **)0x0) << 1;
          structTypeName = (undefined **)0x0;
          if (structTypeNameString != (undefined **)0x0) {
            poolAllocatorArg1[0] = ((int (*)())GetGlobalPoolAllocator)();
            a2 = (unsigned char *)poolAllocatorArg1;
            __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_(structTypeNameString,structTypeNameChars,a2);
            passThroughR4 = extraout_r4;
            structTypeName = structTypeNameString;
          }
        }
        stackTypeTypeNameOrStackTypeB = structTypeName;
        newVariable[1] = (int)text;
        ptArray = 0;
        *newVariable = (int)(PTR_vtable_a7b7c0b4 + 8);
        newVariable[4] = (int)stackTypeArraySize;
        newVariable[5] = stackTypeStructure;
        newVariable[6] = (int)stackTypeFieldName;
        newVariable[7] = (int)stackTypeTypeNameOrStackTypeB;
        newVariable[8] = (int)stackTypeWord14OrStackTypeBArraySize;
        newVariable[9] = (int)stackTypeStructureSizeOrStackTypeBStructure;
        newVariable[3] = (int)&PTR___ZN5TTypeD1Ev_a7b7d4d0;
        newVariable[10] = (int)stackTypeWord1cOrStackTypeBFieldName;
        newVariable[0xb] = (int)stackTypeWord20OrStackTypeBTypeName;
        oldVariableBits = newVariable[0xc];
        qualifierField = stackTypeBitsOrStackTypeBWord14 & 0xfe000000;
        newVariable[0xc] = qualifierField | oldVariableBits & 0x1ffffff;
        basicTypeField = (stackTypeBitsOrStackTypeBWord14 >> 0x13 & 0x3f) << 0x13;
        newVariable[0xc] = basicTypeField | qualifierField | oldVariableBits & 0x7ffff;
        sizeField = stackTypeBitsOrStackTypeBWord14 & 0x7f800;
        newVariable[0xc] = sizeField | basicTypeField | qualifierField | oldVariableBits & 0x7ff;
        matrixField = (stackTypeBitsOrStackTypeBWord14 >> 10 & 1) << 10;
        newVariable[0xc] = matrixField | sizeField | basicTypeField | qualifierField | oldVariableBits & 0x3ff;
        newVariable[0xc] = (stackTypeBitsOrStackTypeBWord14 >> 9 & 1) << 9 | matrixField | sizeField | basicTypeField | qualifierField | oldVariableBits & 0x1ff;
        newVariable[0xd] = 0;
        newVariable[0xe] = 0;
        newVariable[0xf] = 0;
        stackType = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
        if (!noArraySizeNode) {
          newVariable[4] = *(int *)arraySizeUnion[0xc];
          newVariable[0xc] = newVariable[0xc] | 0x200;
        }
        symbolTable = *(int **)(parseContext + 4);
        uniqueId = symbolTable[3];
        symbolTable[3] = uniqueId + 1;
        newVariable[2] = uniqueId + 1;
        symbolTableLevel = *(undefined4 *)(*symbolTable + ((symbolTable[1] - *symbolTable & 0xfffffffcU) - 4));
        stackTypeArraySize = (char *)0x0;
        variableNameString = (unsigned char *)(**(code **)(*newVariable + 8))(newVariable,passThroughR4,a2,a3,uVar16,ptSize,symbolTable);
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&nameCopy,variableNameString);
        variableForInsert = newVariable;
        std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&stackTypeTypeNameOrStackTypeB,symbolTableLevel,&nameCopy);
        stackType = stackTypeTypeNameOrStackTypeB;
        piVar7 = (int *)(nameCopyChars + -4);
        stackTypeArraySize = stackTypeWord14OrStackTypeBArraySize;
        destroyAllocator1[0] = nameCopy;
        do {
          iVar9 = *piVar7;
          if (reservation != '\0') {
            iVar17 = storeWordConditionalIndexed(iVar9 + -1,0,piVar7);
            *piVar7 = iVar17;
            cr0Flags = 2;
          }
        } while (!(bool)(cr0Flags >> 1 & 1));
        if (iVar9 < 1) {
          __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                    ((unsigned char *)(nameCopyChars + -0xc),destroyAllocator1);
        }
        if (stackTypeArraySize != (char *)0x0) {
LAB_97b9caf4:
          voidErrorResult = TParseContext__voidErrorCheck((unsigned char *)parseContext,(int)line,text,
                                 (unsigned char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 12)));
          if (voidErrorResult != 0) {
            return 1;
          }
          return 0;
        }
        if (newVariable != (int *)0x0) {
          (**(code **)(*newVariable + 4))(newVariable);
        }
        identifierChars = *(int *)(text + 4);
        identifierLength = *(int *)(identifierChars + -0xc);
        stringTerminator = (uint)*DAT_a7b7ba18;
        errorReason = "INTERNAL ERROR inserting new symbol";
      }
      else {
        isVariable = (**(code **)(*a0 + 0x10))(a0,a1,psVar11,publicType,intermTyped,ptSize,levelsBegin);
        if (isVariable == 0) {
          identifierChars = *(int *)(text + 4);
          identifierLength = *(int *)(identifierChars + -0xc);
          stringTerminator = (uint)*DAT_a7b7ba18;
          errorReason = "variable expected";
        }
        else {
          isArray = (**(code **)(a0[3] + 0x38))(a0 + 3,a1_00,psVar11,publicType,intermTyped,ptSize,levelsBegin);
          if (isArray == 0) {
            identifierChars = *(int *)(text + 4);
            identifierLength = *(int *)(identifierChars + -0xc);
            stringTerminator = (uint)*DAT_a7b7ba18;
            errorReason = "redeclaring non-array as array";
          }
          else if (a0[4] < 1) {
            stackTypeBitsOrStackTypeBWord14 = ((*(uint *)((unsigned char *)ghidra_home + 28)) & 1) << 9 |
                        ((*(uint *)((unsigned char *)ghidra_home + 24)) & 1) << 10 |
                        ((*(uint *)((unsigned char *)ghidra_home + 20)) & 0xff) << 0xb |
                        ((*(uint *)((unsigned char *)ghidra_home + 12)) & 0x3f) << 0x13 | (*(uint *)((unsigned char *)ghidra_home + 16)) << 0x19 | stackTypeBitsOrStackTypeBWord14 & 0x1ff
            ;
            pt2CopyLine = ptLine;
            stackType = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
            stackTypeWord20OrStackTypeBTypeName = (char *)0x0;
            ptCopyType = (*(uint *)((unsigned char *)ghidra_home + 12));
            ptCopyQualifier = (*(uint *)((unsigned char *)ghidra_home + 16));
            ptCopySize = (*(uint *)((unsigned char *)ghidra_home + 20));
            ptCopyMatrix = (*(uint *)((unsigned char *)ghidra_home + 24));
            ptCopyArray = (*(uint *)((unsigned char *)ghidra_home + 28));
            ptCopyUserDef = ptUserDef;
            ptCopyLine = ptLine;
            pt2CopyType = (*(uint *)((unsigned char *)ghidra_home + 12));
            pt2CopyQualifier = (unsigned char *)(*(uint *)((unsigned char *)ghidra_home + 16));
            pt2CopySize = (*(uint *)((unsigned char *)ghidra_home + 20));
            pt2CopyMatrix = (*(uint *)((unsigned char *)ghidra_home + 24));
            pt2CopyArray = (*(uint *)((unsigned char *)ghidra_home + 28));
            pt2CopyUserDef = ptUserDef;
            stackTypeArraySize = (char *)0x0;
            stackTypeStructure = 0;
            stackTypeFieldName = (char *)0x0;
            stackTypeTypeNameOrStackTypeB = (undefined **)0x0;
            stackTypeWord14OrStackTypeBArraySize = (char *)0x0;
            stackTypeStructureSizeOrStackTypeBStructure = (char *)0x0;
            stackTypeWord1cOrStackTypeBFieldName = (char *)0x0;
            ptSize = (*(uint *)((unsigned char *)ghidra_home + 24));
            ptArray = (*(uint *)((unsigned char *)ghidra_home + 12));
            structTypeName = stackTypeTypeNameOrStackTypeB;
            if (ptUserDef != (unsigned char *)0x0) {
              stackTypeStructure = *(int *)(ptUserDef + 8);
              passThroughR4 = ptLine;
              uVar16 = (*(uint *)((unsigned char *)ghidra_home + 20));
              uVar15 = (*(uint *)((unsigned char *)ghidra_home + 16));
              structSizeResult = TType__setStructSize((unsigned char *)&stackType,*(unsigned char **)(ptUserDef + 8));
              stackTypeStructureSizeOrStackTypeBStructure = (char *)((ulonglong)structSizeResult >> 0x20);
              structTypeNameStringRef = (**(code **)(*(int *)pt2CopyUserDef + 0x18))
                                (pt2CopyUserDef,(int)structSizeResult,passThroughR4,uVar16,uVar15,ptSize,*(int *)pt2CopyUserDef)
              ;
              *(byte *)(*(int *)(structTypeNameStringRef + 4) + *(int *)(*(int *)(structTypeNameStringRef + 4) + -0xc)) = *DAT_a7b7ba18;
              structTypeNameChars = *(char **)(structTypeNameStringRef + 4);
              poolAllocator = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
              structTypeNameString = (undefined **)((int (*)())TPoolAllocator__allocate)(poolAllocator,8);
              structTypeName = (undefined **)0x0;
              if (structTypeNameString != (undefined **)0x0) {
                poolAllocatorArg2[0] = ((int (*)())GetGlobalPoolAllocator)();
                __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                          (structTypeNameString,structTypeNameChars,(unsigned char *)poolAllocatorArg2);
                structTypeName = structTypeNameString;
              }
            }
            stackTypeTypeNameOrStackTypeB = structTypeName;
            typesMatch = false;
            if (((a0[0xc] & 0x1fffe00U) == (stackTypeBitsOrStackTypeBWord14 & 0x1fffe00)) && (a0[5] == stackTypeStructure)) {
              typesMatch = true;
            }
            stackType = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
            if (typesMatch) {
              for (redeclaredArrayNode = a0[0xf]; redeclaredArrayNode != 0; redeclaredArrayNode = *(int *)(redeclaredArrayNode + 0x20)) {
                if (*(int *)arraySizeUnion[0xc] < *(int *)(redeclaredArrayNode + 0x1c)) {
                  identifierChars = *(int *)(text + 4);
                  identifierLength = *(int *)(identifierChars + -0xc);
                  stringTerminator = (uint)*DAT_a7b7ba18;
                  errorReason = "higher index value already used for the array";
                  goto LAB_97b9cb40;
                }
                *(int *)(redeclaredArrayNode + 4) = *(int *)arraySizeUnion[0xc];
                *(uint *)(redeclaredArrayNode + 0x24) = *(uint *)(redeclaredArrayNode + 0x24) | 0x200;
              }
              if (!noArraySizeNode) {
                a0[4] = *(int *)arraySizeUnion[0xc];
                a0[0xc] = a0[0xc] | 0x200;
              }
              goto LAB_97b9caf4;
            }
            identifierChars = *(int *)(text + 4);
            identifierLength = *(int *)(identifierChars + -0xc);
            stringTerminator = (uint)*DAT_a7b7ba18;
            errorReason = "redeclaration of array with a different type";
          }
          else {
            identifierChars = *(int *)(text + 4);
            identifierLength = *(int *)(identifierChars + -0xc);
            stringTerminator = (uint)*DAT_a7b7ba18;
            errorReason = "redeclaration of array with size";
          }
        }
      }
    }
    else {
      identifierChars = *(int *)(text + 4);
      identifierLength = *(int *)(identifierChars + -0xc);
      stringTerminator = (uint)*DAT_a7b7ba18;
      errorReason = "array size must be a positive integer";
    }
LAB_97b9cb40:
    *(char *)(identifierChars + identifierLength) = (char)stringTerminator;
    error(parseContext,(char *)line,errorReason,*(char **)(text + 4),"",ptSize,stringTerminator,ptArray);
  }
  else {
    local_fc = (ptArray & 1) << 9 |
               (ptMatrix & 1) << 10 |
               (ptSize & 0xff) << 0xb |
               (publicType & 0x3f) << 0x13 | intermTyped << 0x19 | local_fc & 0x1ff;
    local_b8 = ptLine;
    stackTypeTypeNameOrStackTypeB = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
    stackTypeWord20OrStackTypeBTypeName = (void *)0x0;
    local_100 = 0;
    local_dc = ptUserDef;
    local_d8 = ptLine;
    local_bc = ptUserDef;
    stackTypeWord14OrStackTypeBArraySize = (char *)0x0;
    stackTypeStructureSizeOrStackTypeBStructure = (char *)0x0;
    stackTypeWord1cOrStackTypeBFieldName = (char *)0x0;
    stackTypeBitsOrStackTypeBWord14 = 0;
    stackTypeBStructureSize = 0;
    stackTypeBWord1c = 0;
    (*(uint *)((unsigned char *)ghidra_home + 28)) = ptArray;
    pcVar14 = stackTypeWord20OrStackTypeBTypeName;
    local_f0 = publicType;
    local_ec = (unsigned char *)intermTyped;
    local_e8 = ptSize;
    local_e4 = ptMatrix;
    local_e0 = ptArray;
    local_d0 = publicType;
    local_cc = (unsigned char *)intermTyped;
    local_c8 = ptSize;
    local_c4 = ptMatrix;
    local_c0 = ptArray;
    if (ptUserDef != (unsigned char *)0x0) {
      stackTypeStructureSizeOrStackTypeBStructure = *(char **)(ptUserDef + 8);
      passThroughR4 = ptLine;
      structSizeResult = TType__setStructSize((unsigned char *)&stackTypeTypeNameOrStackTypeB,*(unsigned char **)(ptUserDef + 8));
      stackTypeBStructureSize = (undefined4)((ulonglong)structSizeResult >> 0x20);
      structTypeNameStringRef = (**(code **)(*(int *)local_bc + 0x18))
                        (local_bc,(int)structSizeResult,passThroughR4,intermTyped,ptSize,publicType,*(int *)local_bc);
      *(byte *)(*(int *)(structTypeNameStringRef + 4) + *(int *)(*(int *)(structTypeNameStringRef + 4) + -0xc)) = *DAT_a7b7ba18;
      structTypeNameChars2 = *(char **)(structTypeNameStringRef + 4);
      poolAllocator = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
      this = (void *)((int (*)())TPoolAllocator__allocate)(poolAllocator,8);
      cr0Reg = (this == (void *)0x0) << 1;
      pcVar14 = (void *)0x0;
      if (this != (void *)0x0) {
        destroyAllocator2[0] = ((int (*)())GetGlobalPoolAllocator)();
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                  (this,structTypeNameChars2,(unsigned char *)destroyAllocator2);
        pcVar14 = this;
      }
    }
    stackTypeWord20OrStackTypeBTypeName = pcVar14;
    TType__getCompleteString(&stackType,(unsigned char *)&stackTypeTypeNameOrStackTypeB);
    stackTypeArraySize[*(int *)(stackTypeArraySize + -0xc)] = *DAT_a7b7ba18;
    error(parseContext,(char *)line,"cannot declare arrays of this type",stackTypeArraySize,"",publicType,
          stackTypeArraySize,ptMatrix);
    piVar7 = (int *)(stackTypeArraySize + -4);
    destroyAllocator3[0] = stackType;
    do {
      iVar9 = *piVar7;
      if (reservation != '\0') {
        iVar17 = storeWordConditionalIndexed(iVar9 + -1,0,piVar7);
        *piVar7 = iVar17;
        cr0Reg = 2;
      }
    } while (!(bool)(cr0Reg >> 1 & 1));
    if (iVar9 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(stackTypeArraySize + -0xc),destroyAllocator3);
    }
  }
  return 1;
}

/* TParseContext__arraySetMaxSize @ 0x97b9cb78 (600 bytes) */
int TParseContext__arraySetMaxSize(this, intermSymbol, type, param_4, param_5, param_6)
  unsigned char * this;
  unsigned char * intermSymbol;
  unsigned char * type;
  int param_4;
  int param_5;
  int param_6;
{
  int *refCountPtr;
  int newRefCount;
  int oldRefCount;
  int atomicStore;
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
  char reservation;
  byte cr0Reg;
  byte cr0Flags;
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
  uVar2 = (**(code **)(*(int *)intermSymbol + 0x60))(intermSymbol,intermSymbol,type,param_4,param_5,param_6);
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
    *(undefined4 *)(type + 0x20) = *(undefined4 *)(iVar6 + 0x3c);
    *(unsigned char **)(iVar6 + 0x3c) = type;
    pvVar4 = (void *)(**(code **)(*(int *)intermSymbol + 0x60))(intermSymbol);
    iVar5 = __ZNKSbIcSt11char_traitsIcE14pool_allocatorIcEE7compareEPKc(pvVar4,"gl_TexCoord");
    if (iVar5 != 0) {
LAB_97b9cf8c:
      if (param_5 == 0) {
        return 0;
      }
      iVar5 = *(int *)(type + 0x20);
      iVar3 = param_4 + 1;
      *(int *)(iVar6 + 0x28) = iVar3;
      *(int *)(type + 0x1c) = iVar3;
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
    refCountPtr = (int *)(local_cc + -4);
    local_b0[0] = local_d0;
    do {
      oldRefCount = *refCountPtr;
      if (reservation != '\0') {
        newRefCount = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
        *refCountPtr = newRefCount;
        cr0Reg = 2;
      }
    } while (!(bool)(cr0Reg >> 1 & 1));
    if (oldRefCount < 1) {
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
      cr0Flags = (uVar1 == 0) << 1;
      if (uVar1 == 0) {
        _sprintf(acStack_a0,"%d:? ",param_6 >> 0x10);
      }
      else {
        _sprintf(acStack_a0,"%d:%d",param_6 >> 0x10,uVar1);
      }
      __ZNSsC1EPKcRKSaIcE(&local_d0,acStack_a0,aaStack_60);
      local_d0[*(int *)(local_d0 + -0xc)] = *PTR__S_terminal_a7b7c0b8;
      __ZN13TInfoSinkBase6appendEPKc(pvVar4,local_d0);
      refCountPtr = (int *)(local_d0 + -4);
      do {
        oldRefCount = *refCountPtr;
        if (reservation != '\0') {
          atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
          *refCountPtr = atomicStore;
          cr0Flags = 2;
        }
      } while (!(bool)(cr0Flags >> 1 & 1));
      if (oldRefCount < 1) {
        __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(local_d0 + -0xc),acStack_a0);
      }
      __ZN13TInfoSinkBase6appendEPKc(pvVar4,": ");
      __ZN13TInfoSinkBase6appendEPKc(pvVar4,"gl_MaxTextureCoords not defined");
      __ZN13TInfoSinkBase6appendEPKc(pvVar4,"\n");
    }
  }
  else {
    iVar3 = (**(code **)(*(int *)intermSymbol + 0x60))(intermSymbol);
    cr0Flags = *DAT_a7b7ba18;
    *(byte *)(*(int *)(iVar3 + 4) + *(int *)(*(int *)(iVar3 + 4) + -0xc)) = cr0Flags;
    error((int)this,(char *)param_6," undeclared identifier",*(char **)(iVar3 + 4),"",iVar5,
          (uint)cr0Flags,in_r10);
  }
  return 1;
}

/* TParseContext__nonInitErrorCheck @ 0x97b9cfe8 (1008 bytes) */
int TParseContext__nonInitErrorCheck(this, param_2, text, publicType)
  unsigned char * this;
  int param_2;
  unsigned char * text;
  unsigned char * publicType;
{
  int *refCountPtr;
  int oldRefCount;
  int voidErrorCheckResult;
  int reservedErrorCheckResult;
  byte bVar1;
  int atomicStore;
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
  char reservation;
  byte cr0Reg;
  undefined8 uVar17;
  undefined **stackType;
  int stackTypeArraySize;
  int stackTypeStructure;
  int stackTypeFieldName;
  void *stackTypeTypeName;
  int stackTypeWord14;
  int stackTypeStructureSize;
  int stackTypeWord1c;
  int stackTypeWord20;
  uint stackTypeBits;
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
  
  reservedErrorCheckResult = TParseContext__reservedErrorCheck(this,param_2,text);
  if (reservedErrorCheckResult != 0) {
    TParseContext__recover(this);
  }
  iVar9 = *(int *)(publicType + 4);
  if (iVar9 == 2) {
    *(undefined4 *)(publicType + 4) = 0;
  }
  pTVar10 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
  a0 = (int *)((int (*)())TPoolAllocator__allocate)(pTVar10,0x40);
  local_8c = *(int **)(publicType + 0x14);
  iVar13 = *(int *)(publicType + 4);
  a5 = *(uint *)publicType;
  a4 = *(uint *)(publicType + 8);
  local_94 = *(uint *)(publicType + 0xc);
  local_90 = *(uint *)(publicType + 0x10);
  a2 = *(unsigned char **)(publicType + 0x18);
  stackTypeBits = (local_90 & 1) << 9 |
             (local_94 & 1) << 10 |
             (a4 & 0xff) << 0xb | (a5 & 0x3f) << 0x13 | iVar13 << 0x19 | stackTypeBits & 0x1ff;
  stackType = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  stackTypeWord20 = 0;
  stackTypeArraySize = 0;
  stackTypeStructure = 0;
  stackTypeFieldName = 0;
  stackTypeTypeName = (void *)0x0;
  stackTypeWord14 = 0;
  stackTypeStructureSize = 0;
  stackTypeWord1c = 0;
  a1 = 0;
  pvVar7 = stackTypeTypeName;
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
    stackTypeStructure = local_8c[2];
    uVar17 = TType__setStructSize((unsigned char *)&stackType,(unsigned char *)local_8c[2]);
    stackTypeStructureSize = (int)((ulonglong)uVar17 >> 0x20);
    iVar11 = (**(code **)(*local_6c + 0x18))(local_6c,(int)uVar17,a2,iVar13,a4,a5,*local_6c);
    *(byte *)(*(int *)(iVar11 + 4) + *(int *)(*(int *)(iVar11 + 4) + -0xc)) = *DAT_a7b7ba18;
    pcVar15 = *(char **)(iVar11 + 4);
    pTVar10 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
    uVar17 = ((int (*)())TPoolAllocator__allocate)(pTVar10,8);
    this_00 = (void *)((ulonglong)uVar17 >> 0x20);
    a1 = (undefined4)uVar17;
    cr0Reg = (this_00 == (void *)0x0) << 1;
    pvVar7 = (void *)0x0;
    if (this_00 != (void *)0x0) {
      local_60[0] = ((int (*)())GetGlobalPoolAllocator)();
      a2 = (unsigned char *)local_60;
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_(this_00,pcVar15,a2);
      a1 = extraout_r4;
      pvVar7 = this_00;
    }
  }
  stackTypeTypeName = pvVar7;
  a0[1] = (int)text;
  *a0 = (int)(PTR_vtable_a7b7c0b4 + 8);
  a0[4] = stackTypeArraySize;
  a0[5] = stackTypeStructure;
  a0[6] = stackTypeFieldName;
  a0[7] = (int)stackTypeTypeName;
  a0[8] = stackTypeWord14;
  a0[9] = stackTypeStructureSize;
  a0[3] = (int)&PTR___ZN5TTypeD1Ev_a7b7d4d0;
  a0[10] = stackTypeWord1c;
  a0[0xb] = stackTypeWord20;
  uVar8 = a0[0xc];
  uVar4 = stackTypeBits & 0xfe000000;
  a0[0xc] = uVar4 | uVar8 & 0x1ffffff;
  uVar5 = (stackTypeBits >> 0x13 & 0x3f) << 0x13;
  a0[0xc] = uVar5 | uVar4 | uVar8 & 0x7ffff;
  uVar3 = stackTypeBits & 0x7f800;
  a0[0xc] = uVar3 | uVar5 | uVar4 | uVar8 & 0x7ff;
  uVar6 = (stackTypeBits >> 10 & 1) << 10;
  a0[0xc] = uVar6 | uVar3 | uVar5 | uVar4 | uVar8 & 0x3ff;
  a0[0xc] = (stackTypeBits >> 9 & 1) << 9 | uVar6 | uVar3 | uVar5 | uVar4 | uVar8 & 0x1ff;
  a0[0xd] = 0;
  a0[0xe] = 0;
  a0[0xf] = 0;
  piVar14 = *(int **)(this + 4);
  stackType = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  iVar11 = piVar14[3];
  piVar14[3] = iVar11 + 1;
  a0[2] = iVar11 + 1;
  iVar11 = *piVar14;
  uVar16 = *(undefined4 *)(iVar11 + ((piVar14[1] - iVar11 & 0xfffffffcU) - 4));
  stackTypeArraySize = 0;
  psVar12 = (unsigned char *)(**(code **)(*a0 + 8))(a0,a1,a2,iVar13,a4,a5,piVar14,iVar11);
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&local_50,psVar12);
  local_48 = a0;
  std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&stackTypeTypeName,uVar16,&local_50);
  stackType = stackTypeTypeName;
  refCountPtr = (int *)(local_4c + -4);
  stackTypeArraySize = stackTypeWord14;
  local_40[0] = local_50;
  do {
    oldRefCount = *refCountPtr;
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
      *refCountPtr = atomicStore;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  if (oldRefCount < 1) {
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
              ((unsigned char *)(local_4c + -0xc),local_40);
  }
  if (stackTypeArraySize == 0) {
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
      voidErrorCheckResult = TParseContext__voidErrorCheck(this,param_2,text,publicType);
      return voidErrorCheckResult != 0;
    }
    bVar1 = *DAT_a7b7ba18;
    *(byte *)(*(int *)(text + 4) + *(int *)(*(int *)(text + 4) + -0xc)) = bVar1;
    error((int)this,(char *)param_2,"variables with qualifier \'const\' must be initialized",
          *(char **)(text + 4),"",a5,(uint)bVar1,iVar11);
  }
  return true;
}

/* TParseContext__paramErrorCheck @ 0x97b9d3d8 (216 bytes) */
int TParseContext__paramErrorCheck(this, param_2, qualifier1, qualifier2, type)
  unsigned char * this;
  int param_2;
  int qualifier1;
  int qualifier2;
  int *type;
{
  int iVar1;
  char *qualifierString;
  char *pcVar3;
  char *pcVar4;
  undefined4 in_r8;
  undefined4 in_r9;
  undefined4 in_r10;
  
  if (qualifier1 == 2) {
    if (qualifier2 == 9) {
      iVar1 = *type;
      qualifier2 = 0xc;
      goto LAB_97b9d48c;
    }
    qualifierString = (char *)getQualifierString(2);
    pcVar4 = (char *)getQualifierString(qualifier2);
    pcVar3 = "qualifier not allowed with ";
  }
  else {
    if (qualifier1 == 0) {
      iVar1 = *type;
LAB_97b9d48c:
      (**(code **)(iVar1 + 0x28))(type,qualifier2);
      return 0;
    }
    qualifierString = (char *)getQualifierString(qualifier1);
    pcVar3 = "qualifier not allowed on function parameter";
    pcVar4 = "";
  }
  error((int)this,(char *)param_2,pcVar3,qualifierString,pcVar4,in_r8,in_r9,in_r10);
  return 1;
}

/* TParseContext__extensionErrorCheck @ 0x97b9d4b0 (532 bytes) */
int TParseContext__extensionErrorCheck(this, param_2, str)
  unsigned char * this;
  int param_2;
  char *str;
{
  int oldRefCount2;
  int oldRefCount;
  int newRefCount;
  int atomicStore;
  bool bVar1;
  int atomicStore2;
  char *pcVar3;
  int *refCountPtr;
  int iVar5;
  ulong length;
  uint *puVar7;
  undefined4 in_r8;
  undefined4 in_r10;
  unsigned char * pTVar8;
  void *this_00;
  uint uVar9;
  int iVar10;
  uint uVar11;
  char reservation;
  byte cr0Reg;
  byte cr0Flags;
  undefined4 local_1d0;
  int local_1cc;
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
            ((unsigned char *)&local_1d0,str,(unsigned char *)local_1c0);
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
    refCountPtr = (int *)(local_16c + -4);
    local_1b0 = local_190[0];
    local_150[0] = local_170;
    do {
      oldRefCount2 = *refCountPtr;
      if (reservation != '\0') {
        newRefCount = storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *refCountPtr = newRefCount;
        cr0Reg = 2;
      }
    } while (!(bool)(cr0Reg >> 1 & 1));
    iVar10 = local_190[0];
    if (oldRefCount2 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_16c + -0xc),local_150);
      iVar10 = local_1b0;
    }
  }
  else {
    puVar7 = &local_3c;
    uVar11 = *(uint *)(local_1cc + -0xc);
    local_40 = uVar11;
    uVar9 = *(uint *)(*(int *)(local_1b0 + 0x14) + -0xc);
    local_3c = uVar9;
    if (uVar11 <= uVar9) {
      puVar7 = &local_40;
    }
    iVar5 = _memcmp(local_1cc,*(undefined4 *)(local_1b0 + 0x14),*puVar7);
    cr0Reg = (iVar5 == 0) << 1;
    if (iVar5 == 0) {
      iVar5 = uVar11 - uVar9;
    }
    if (iVar5 < 0) goto LAB_97b9d574;
  }
  iVar10 = *(int *)(iVar10 + 0x18);
  refCountPtr = (int *)(local_1cc + -4);
  local_140[0] = local_1d0;
  do {
    oldRefCount2 = *refCountPtr;
    if (reservation != '\0') {
      atomicStore2 = storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
      *refCountPtr = atomicStore2;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  if (oldRefCount2 < 1) {
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
              ((unsigned char *)(local_1cc + -0xc),local_140);
  }
  if (iVar10 == 2) {
    this_00 = *(void **)(this + 8);
    local_120[0] = ((int (*)())GetGlobalPoolAllocator)();
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
              (&uStack_130,str,(unsigned char *)local_120);
    __ZStplIcSt11char_traitsIcE14pool_allocatorIcEESbIT_T0_T1_EPKS4_RKS7_
              ((char *)&local_1a0,(unsigned char *)"extension ",&uStack_130);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_
              ((unsigned char *)&local_1b0,(unsigned char *)&local_1a0);
    length = _strlen(" is being used");
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEPKcm
              ((unsigned char *)&local_1b0," is being used",length);
    pcVar3 = local_1ac;
    local_1ac[*(int *)(local_1ac + -0xc)] = *DAT_a7b7ba18;
                    
    __ZN13TInfoSinkBase6appendEPKc(this_00,"WARNING: ");
    uVar9 = param_2 & 0xffff;
    cr0Flags = (uVar9 == 0) << 1;
    if (uVar9 == 0) {
      _sprintf(acStack_100,"%d:? ",param_2 >> 0x10);
    }
    else {
      _sprintf(acStack_100,"%d:%d",param_2 >> 0x10,uVar9);
    }
    __ZNSsC1EPKcRKSaIcE(apcStack_110,acStack_100,aaStack_c0);
    apcStack_110[0][*(int *)(apcStack_110[0] + -0xc)] = *PTR__S_terminal_a7b7c0b8;
    __ZN13TInfoSinkBase6appendEPKc(this_00,apcStack_110[0]);
    refCountPtr = (int *)(apcStack_110[0] + -4);
    do {
      oldRefCount = *refCountPtr;
      if (reservation != '\0') {
        atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
        *refCountPtr = atomicStore;
        cr0Flags = 2;
      }
    } while (!(bool)(cr0Flags >> 1 & 1));
    if (oldRefCount < 1) {
      __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(apcStack_110[0] + -0xc));
    }
    __ZN13TInfoSinkBase6appendEPKc(this_00,": ");
    __ZN13TInfoSinkBase6appendEPKc(this_00,pcVar3);
    __ZN13TInfoSinkBase6appendEPKc(this_00,"\n");
    refCountPtr = (int *)(local_1ac + -4);
    aiStack_b0[0] = local_1b0;
    do {
      oldRefCount = *refCountPtr;
      if (reservation != '\0') {
        atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
        *refCountPtr = atomicStore;
        cr0Flags = 2;
      }
    } while (!(bool)(cr0Flags >> 1 & 1));
    if (oldRefCount < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_1ac + -0xc),aiStack_b0);
    }
    refCountPtr = (int *)(iStack_19c + -4);
    aiStack_a0[0] = local_1a0;
    do {
      oldRefCount = *refCountPtr;
      if (reservation != '\0') {
        atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
        *refCountPtr = atomicStore;
        cr0Flags = 2;
      }
    } while (!(bool)(cr0Flags >> 1 & 1));
    if (oldRefCount < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(iStack_19c + -0xc),aiStack_a0);
    }
    refCountPtr = (int *)(iStack_12c + -4);
    auStack_90[0] = uStack_130;
    do {
      oldRefCount = *refCountPtr;
      if (reservation != '\0') {
        atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
        *refCountPtr = atomicStore;
        cr0Flags = 2;
      }
    } while (!(bool)(cr0Flags >> 1 & 1));
    if (oldRefCount < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(iStack_12c + -0xc),auStack_90);
    }
    return false;
  }
  local_80[0] = ((int (*)())GetGlobalPoolAllocator)();
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
            ((unsigned char *)&local_1d0,str,(unsigned char *)local_80);
  std___Rb_tree_std__string_std__pair_std__string_const_TBehavior__std___Select1st_std__pair_std__string_const_TBehavior___std__less_std__string__pool_allocator_std__pair_std__string_const_TBehavior_____lower_bound((unsigned char *)local_1c0,pTVar8,(unsigned char *)&local_1d0);
  iVar10 = local_1c0[0];
  local_1b0 = *(int *)(this + 0x34);
  if (local_1c0[0] != local_1b0) {
    puVar7 = &local_34;
    uVar11 = *(uint *)(local_1cc + -0xc);
    local_38 = uVar11;
    uVar9 = *(uint *)(*(int *)(local_1c0[0] + 0x14) + -0xc);
    local_34 = uVar9;
    if (uVar11 <= uVar9) {
      puVar7 = &local_38;
    }
    iVar5 = _memcmp(local_1cc,*(undefined4 *)(local_1c0[0] + 0x14),*puVar7);
    cr0Reg = (iVar5 == 0) << 1;
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
  refCountPtr = (int *)(local_6c + -4);
  local_1c0[0] = local_1a0;
  local_60[0] = local_70;
  do {
    oldRefCount2 = *refCountPtr;
    if (reservation != '\0') {
      newRefCount = storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
      *refCountPtr = newRefCount;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  iVar10 = local_1a0;
  if (oldRefCount2 < 1) {
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
              ((unsigned char *)(local_6c + -0xc),local_60);
    iVar10 = local_1c0[0];
  }
LAB_97b9d98c:
  iVar10 = *(int *)(iVar10 + 0x18);
  refCountPtr = (int *)(local_1cc + -4);
  local_50[0] = local_1d0;
  do {
    oldRefCount2 = *refCountPtr;
    if (reservation != '\0') {
      atomicStore2 = storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
      *refCountPtr = atomicStore2;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  if (oldRefCount2 < 1) {
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
              ((unsigned char *)(local_1cc + -0xc),local_50);
  }
  bVar1 = iVar10 == 3;
  if (bVar1) {
    error((int)this,(char *)param_2,"extension",str,"is disabled",in_r8,local_1cc,in_r10);
  }
  return bVar1;
}

/* TParseContext__findFunction @ 0x97b9da08 (356 bytes) */
int TParseContext__findFunction(this, param_2, function, param_4, param_5, param_6)
  unsigned char * this;
  int param_2;
  unsigned char * function;
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
  uVar3 = (**(code **)(*(int *)function + 8))(function,param_2,function,param_4,param_5,param_6);
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
    iVar5 = *(int *)(function + 4);
    iVar7 = *(int *)(iVar5 + 4);
    bVar1 = *DAT_a7b7ba18;
    iVar2 = *(int *)(iVar7 + -0xc);
    pcVar4 = "function name expected";
  }
  else {
    iVar5 = *(int *)(function + 4);
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
int TParseContext__executeInitializer(this, line, identifier, publicType, initializer, intermNode)
  unsigned char * this;
  int line;
  unsigned char * identifier;
  unsigned char * publicType;
  unsigned char * initializer;
  unsigned char ** intermNode;
{
  int *refCountPtr;
  int oldRefCount;
  int newRefCount;
  undefined4 *variableConstArray;
  int constantUnionNodeArray;
  int ptBasicType;
  int symbolNodeResult;
  int parseResult;
  int constantArrayPtr;
  int childConstantUnionResult;
  int sequence;
  int typeSize;
  int aggregateNodeResult;
  int constantUnionNode;
  int typesMatch;
  int variableSymbol;
  int structTypeNameStringRef;
  int levelIndex;
  int *symbolNode;
  int *childConstantUnion;
  char *qualifierString;
  char *nameChars;
  unsigned char * stackTypeBitsCopy;
  uint variableBitsCopy;
  uint decrementedRefCount;
  uint stackTypeLowBits;
  uint typeStringData;
  uint qualifierIsNotConst;
  uint variableBits;
  uint variableMatrixBits;
  uint ptQualifierCopy;
  uint levelsBegin;
  uint uniqueId;
  uint variableBasicTypeBits;
  uint ptLine;
  undefined **ptType;
  undefined **ptSizeCopy;
  undefined4 symbolTableArg;
  undefined8 typeNameAllocation;
  undefined8 structSizeResult;
  int reservedErrorCheckResult;
  byte stringTerminator;
  uint basicTypeField;
  uint matrixField;
  uint oldVariableBits;
  int *aggregateNode;
  int *newNode;
  uint typeSizeBits;
  int iVar8;
  unsigned char * poolAllocator;
  unsigned char * variableNameString;
  undefined **structTypeNameString;
  undefined **this_00;
  unsigned char * this_01;
  unsigned char * assignNode;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  undefined **structTypeName;
  undefined **extraout_r4_02;
  undefined4 extraout_r4_03;
  undefined4 a1;
  undefined4 a1_00;
  undefined ***destroyAllocatorArg;
  unsigned char * ptUserDef;
  char *errorReason;
  uint ptLineCopy;
  uint ptQualifier;
  undefined4 passThroughR4;
  undefined **ptSize;
  uint *a6;
  uint qualifierBits;
  int childVtable;
  undefined4 singleConstantParam;
  undefined4 *tempName;
  unsigned char * variableConstPointer;
  int *symbolTable;
  undefined4 symbolTableLevel;
  int currentLevel;
  char *typeNameChars;
  unsigned char * a0;
  char reservation;
  byte cr0Flags;
  undefined8 variableAllocation;
  undefined **stackType;
  uint local_14c;
  undefined **stackTypeStructure;
  uint stackTypeFieldName;
  undefined **stackTypeTypeName;
  uint stackTypeWord14;
  uint stackTypeStructureSize;
  uint stackTypeWord1c;
  uint stackTypeWord20;
  unsigned char * stackTypeBits;
  undefined **ptCopyType;
  uint ptCopyQualifier;
  undefined **ptCopySize;
  uint ptCopyMatrix;
  uint ptCopyArray;
  unsigned char * ptCopyUserDef;
  uint ptCopyLine;
  undefined **pt2CopyType;
  uint pt2CopyQualifier;
  undefined **pt2CopySize;
  uint pt2CopyMatrix;
  uint pt2CopyArray;
  unsigned char * pt2CopyUserDef;
  uint pt2CopyLine;
  undefined4 poolAllocatorArg1 [4];
  undefined4 nameCopy;
  int nameCopyChars;
  int *variableForInsert;
  undefined4 destroyAllocator1 [4];
  undefined **destroyAllocator2 [4];
  undefined4 poolAllocatorArg2 [4];
  undefined4 poolAllocatorArg3 [4];
  int levelFindResult [4];
  undefined **destroyAllocator3 [4];
  undefined **destroyAllocator4 [4];
  undefined **destroyAllocator5 [6];
  
  reservedErrorCheckResult = TParseContext__reservedErrorCheck(this,line,identifier);
  if (reservedErrorCheckResult != 0) {
    return 1;
  }
  local_14c = TParseContext__voidErrorCheck(this,line,identifier,publicType);
  cr0Flags = (local_14c == 0) << 1;
  if (local_14c != 0) {
    return 1;
  }
  poolAllocator = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
  variableAllocation = ((int (*)())TPoolAllocator__allocate)(poolAllocator,0x40);
  newNode = (int *)((ulonglong)variableAllocation >> 0x20);
  passThroughR4 = (undefined4)variableAllocation;
  ptUserDef = *(unsigned char **)(publicType + 0x14);
  ptQualifier = *(uint *)(publicType + 4);
  ptCopyType = *(undefined ***)publicType;
  ptSize = *(undefined ***)(publicType + 8);
  ptCopyMatrix = *(uint *)(publicType + 0xc);
  ptCopyArray = *(uint *)(publicType + 0x10);
  ptLineCopy = *(uint *)(publicType + 0x18);
  stackTypeBits = (unsigned char *)
              ((ptCopyArray & 1) << 9 |
              (ptCopyMatrix & 1) << 10 |
              ((uint)ptSize & 0xff) << 0xb |
              ((uint)ptCopyType & 0x3f) << 0x13 | ptQualifier << 0x19 | (uint)stackTypeBits & 0x1ff);
  stackType = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  stackTypeStructure = (undefined **)0x0;
  stackTypeStructureSize = 0;
  stackTypeFieldName = local_14c;
  structTypeName = (undefined **)0x0;
  stackTypeWord14 = local_14c;
  stackTypeWord1c = local_14c;
  stackTypeWord20 = local_14c;
  ptCopyQualifier = ptQualifier;
  ptCopySize = ptSize;
  ptCopyUserDef = ptUserDef;
  ptCopyLine = ptLineCopy;
  pt2CopyType = ptCopyType;
  pt2CopyQualifier = ptQualifier;
  pt2CopySize = ptSize;
  pt2CopyMatrix = ptCopyMatrix;
  pt2CopyArray = ptCopyArray;
  pt2CopyUserDef = ptUserDef;
  pt2CopyLine = ptLineCopy;
  if (ptUserDef != (unsigned char *)0x0) {
    stackTypeStructure = *(undefined ***)(ptUserDef + 8);
    stackTypeTypeName = (undefined **)local_14c;
    stackTypeStructureSize = local_14c;
    structSizeResult = TType__setStructSize((unsigned char *)&stackType,*(unsigned char **)(ptUserDef + 8));
    stackTypeStructureSize = (uint)((ulonglong)structSizeResult >> 0x20);
    structTypeNameStringRef = (**(code **)(*(int *)pt2CopyUserDef + 0x18))
                      (pt2CopyUserDef,(int)structSizeResult,ptUserDef,ptLineCopy,ptQualifier,ptSize,*(int *)pt2CopyUserDef);
    *(byte *)(*(int *)(structTypeNameStringRef + 4) + *(int *)(*(int *)(structTypeNameStringRef + 4) + -0xc)) = *DAT_a7b7ba18;
    typeNameChars = *(char **)(structTypeNameStringRef + 4);
    poolAllocator = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
    typeNameAllocation = ((int (*)())TPoolAllocator__allocate)(poolAllocator,8);
    structTypeNameString = (undefined **)((ulonglong)typeNameAllocation >> 0x20);
    passThroughR4 = (undefined4)typeNameAllocation;
    cr0Flags = (structTypeNameString == (undefined **)0x0) << 1;
    structTypeName = (undefined **)0x0;
    if (structTypeNameString != (undefined **)0x0) {
      poolAllocatorArg1[0] = ((int (*)())GetGlobalPoolAllocator)();
      ptUserDef = (unsigned char *)poolAllocatorArg1;
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_(structTypeNameString,typeNameChars,ptUserDef);
      passThroughR4 = extraout_r4;
      structTypeName = structTypeNameString;
    }
  }
  stackTypeTypeName = structTypeName;
  newNode[1] = (int)identifier;
  a0 = (unsigned char *)(newNode + 3);
  *newNode = (int)(PTR_vtable_a7b7c0b4 + 8);
  tempName = &nameCopy;
  newNode[4] = local_14c;
  newNode[5] = (int)stackTypeStructure;
  newNode[6] = stackTypeFieldName;
  newNode[7] = (int)stackTypeTypeName;
  newNode[8] = stackTypeWord14;
  newNode[9] = stackTypeStructureSize;
  newNode[3] = (int)&PTR___ZN5TTypeD1Ev_a7b7d4d0;
  newNode[10] = stackTypeWord1c;
  newNode[0xb] = stackTypeWord20;
  oldVariableBits = newNode[0xc];
  qualifierBits = (uint)stackTypeBits & 0xfe000000;
  newNode[0xc] = qualifierBits | oldVariableBits & 0x1ffffff;
  basicTypeField = ((uint)stackTypeBits >> 0x13 & 0x3f) << 0x13;
  newNode[0xc] = basicTypeField | qualifierBits | oldVariableBits & 0x7ffff;
  typeSizeBits = (uint)stackTypeBits & 0x7f800;
  newNode[0xc] = typeSizeBits | basicTypeField | qualifierBits | oldVariableBits & 0x7ff;
  matrixField = ((uint)stackTypeBits >> 10 & 1) << 10;
  newNode[0xc] = matrixField | typeSizeBits | basicTypeField | qualifierBits | oldVariableBits & 0x3ff;
  newNode[0xc] = ((uint)stackTypeBits >> 9 & 1) << 9 | matrixField | typeSizeBits | basicTypeField | qualifierBits | oldVariableBits & 0x1ff;
  newNode[0xd] = 0;
  newNode[0xe] = 0;
  newNode[0xf] = 0;
  a6 = *(uint **)(this + 4);
  stackType = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  uniqueId = a6[3];
  a6[3] = uniqueId + 1;
  newNode[2] = uniqueId + 1;
  levelsBegin = *a6;
  symbolTableLevel = *(undefined4 *)(levelsBegin + ((a6[1] - levelsBegin & 0xfffffffc) - 4));
  local_14c = 0;
  variableNameString = (unsigned char *)
            (**(code **)(*newNode + 8))(newNode,passThroughR4,ptUserDef,ptLineCopy,ptQualifier,ptSize,a6,levelsBegin);
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(tempName,variableNameString);
  variableForInsert = newNode;
  std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&stackTypeTypeName,symbolTableLevel,tempName);
  stackType = stackTypeTypeName;
  refCountPtr = (int *)(nameCopyChars + -4);
  local_14c = stackTypeWord14;
  destroyAllocator1[0] = nameCopy;
  do {
    oldRefCount = *refCountPtr;
    decrementedRefCount = oldRefCount - 1;
    if (reservation != '\0') {
      newRefCount = storeWordConditionalIndexed(decrementedRefCount,0,refCountPtr);
      *refCountPtr = newRefCount;
      cr0Flags = 2;
    }
  } while (!(bool)(cr0Flags >> 1 & 1));
  passThroughR4 = extraout_r4_00;
  if (oldRefCount < 1) {
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
              ((unsigned char *)(nameCopyChars + -0xc),destroyAllocator1);
    passThroughR4 = extraout_r4_01;
  }
  if (local_14c == 0) {
    levelsBegin = newNode[1];
    decrementedRefCount = (uint)*DAT_a7b7ba18;
    errorReason = "redefinition";
    *(byte *)(*(int *)(levelsBegin + 4) + *(int *)(*(int *)(levelsBegin + 4) + -0xc)) = *DAT_a7b7ba18;
    nameChars = *(char **)(levelsBegin + 4);
    goto LAB_97b9df14;
  }
  ptLineCopy = (**(code **)(newNode[3] + 0x24))(a0,passThroughR4,tempName,ptLineCopy,ptQualifier,ptSize,decrementedRefCount,levelsBegin);
  if (2 < ptLineCopy) {
    nameChars = (char *)getQualifierString((uint)newNode[0xc] >> 0x19);
    errorReason = " cannot initialize this type of qualifier ";
    goto LAB_97b9df14;
  }
  if (ptLineCopy != 2) {
    variableSymbol = TIntermediate__addSymbol
                      (*(unsigned char **)this,newNode[2],(unsigned char *)newNode[1],a0,line);
    assignNode = (unsigned char *)
              TIntermediate__addAssign(*(unsigned char **)this,0x76,variableSymbol,initializer,line);
    *intermNode = assignNode;
    if (assignNode != (unsigned char *)0x0) {
      return 0;
    }
    TType__getCompleteString(&stackType,initializer + 8);
    TType__getCompleteString((unsigned char *)&stackTypeTypeName,variableSymbol + 8);
    TParseContext__assignError(this,line,"=",(unsigned char *)&stackTypeTypeName,&stackType);
    newNode = (int *)(stackTypeWord14 - 4);
    destroyAllocator4[0] = stackTypeTypeName;
    do {
      oldRefCount = *newNode;
      if (reservation != '\0') {
        newRefCount = storeWordConditionalIndexed(oldRefCount + -1,0,newNode);
        *newNode = newRefCount;
        cr0Flags = 2;
      }
    } while (!(bool)(cr0Flags >> 1 & 1));
    if (oldRefCount < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(stackTypeWord14 - 0xc),destroyAllocator4);
    }
    newNode = (int *)(local_14c - 4);
    destroyAllocator5[0] = stackType;
    do {
      oldRefCount = *newNode;
      if (reservation != '\0') {
        newRefCount = storeWordConditionalIndexed(oldRefCount + -1,0,newNode);
        *newNode = newRefCount;
        cr0Flags = 2;
      }
    } while (!(bool)(cr0Flags >> 1 & 1));
    if (0 < oldRefCount) {
      return 1;
    }
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
              ((unsigned char *)(local_14c - 0xc),destroyAllocator5);
    return 1;
  }
  (**(code **)(*(int *)initializer + 0x38))((unsigned char *)&stackType,initializer);
  stackType = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  qualifierIsNotConst = -((int)-((uint)stackTypeBits >> 0x19 ^ 2) >> 0x1f);
  cr0Flags = (qualifierIsNotConst == 0) << 1;
  if (qualifierIsNotConst != 0) {
    TType__getCompleteString(&ptCopyType,a0);
    stringTerminator = *DAT_a7b7ba18;
    *(byte *)(ptCopyQualifier + *(int *)(ptCopyQualifier - 0xc)) = stringTerminator;
    error((int)this,(char *)line," assigning non-constant to","=","\'%s\'",ptCopyQualifier,(uint)stringTerminator,
          levelsBegin);
    refCountPtr = (int *)(ptCopyQualifier - 4);
    destroyAllocator2[0] = ptCopyType;
    do {
      oldRefCount = *refCountPtr;
      if (reservation != '\0') {
        newRefCount = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
        *refCountPtr = newRefCount;
        cr0Flags = 2;
      }
    } while (!(bool)(cr0Flags >> 1 & 1));
    destroyAllocatorArg = destroyAllocator2;
    typeStringData = ptCopyQualifier;
    if (0 < oldRefCount) goto LAB_97b9e184;
LAB_97b9e848:
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
              ((unsigned char *)(typeStringData - 0xc),destroyAllocatorArg);
LAB_97b9e184:
    (**(code **)(newNode[3] + 0x28))(a0,0);
    return 1;
  }
  ptUserDef = *(unsigned char **)(publicType + 0x14);
  ptQualifierCopy = *(uint *)(publicType + 4);
  ptType = *(undefined ***)publicType;
  ptCopySize = *(undefined ***)(publicType + 8);
  ptCopyMatrix = *(uint *)(publicType + 0xc);
  ptCopyArray = *(uint *)(publicType + 0x10);
  ptLine = *(uint *)(publicType + 0x18);
  stackTypeBits = (unsigned char *)
              ((ptCopyArray & 1) << 9 |
              (ptCopyMatrix & 1) << 10 |
              ((uint)ptCopySize & 0xff) << 0xb |
              ((uint)ptType & 0x3f) << 0x13 | ptQualifierCopy << 0x19 | (uint)stackTypeBits & 0x1ff);
  stackType = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  stackTypeStructure = (undefined **)0x0;
  stackTypeStructureSize = 0;
  cr0Flags = 2;
  local_14c = qualifierIsNotConst;
  stackTypeFieldName = qualifierIsNotConst;
  structTypeName = (undefined **)0x0;
  stackTypeWord14 = qualifierIsNotConst;
  stackTypeWord1c = qualifierIsNotConst;
  stackTypeWord20 = qualifierIsNotConst;
  ptCopyType = ptType;
  ptCopyQualifier = ptQualifierCopy;
  ptCopyUserDef = ptUserDef;
  ptCopyLine = ptLine;
  pt2CopyType = ptType;
  pt2CopyQualifier = ptQualifierCopy;
  pt2CopySize = ptCopySize;
  pt2CopyMatrix = ptCopyMatrix;
  pt2CopyArray = ptCopyArray;
  pt2CopyUserDef = ptUserDef;
  pt2CopyLine = ptLine;
  if (ptUserDef != (unsigned char *)0x0) {
    stackTypeStructure = *(undefined ***)(ptUserDef + 8);
    stackTypeTypeName = (undefined **)qualifierIsNotConst;
    stackTypeStructureSize = qualifierIsNotConst;
    structSizeResult = TType__setStructSize((unsigned char *)&stackType,*(unsigned char **)(ptUserDef + 8));
    stackTypeStructureSize = (uint)((ulonglong)structSizeResult >> 0x20);
    structTypeNameStringRef = (**(code **)(*(int *)pt2CopyUserDef + 0x18))
                      (pt2CopyUserDef,(int)structSizeResult,ptUserDef,qualifierIsNotConst,ptLine,ptQualifierCopy,*(int *)pt2CopyUserDef);
    *(byte *)(*(int *)(structTypeNameStringRef + 4) + *(int *)(*(int *)(structTypeNameStringRef + 4) + -0xc)) = *DAT_a7b7ba18;
    typeNameChars = *(char **)(structTypeNameStringRef + 4);
    poolAllocator = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
    structTypeNameString = (undefined **)((int (*)())TPoolAllocator__allocate)(poolAllocator,8);
    cr0Flags = (structTypeNameString == (undefined **)0x0) << 1;
    structTypeName = (undefined **)0x0;
    if (structTypeNameString != (undefined **)0x0) {
      poolAllocatorArg2[0] = ((int (*)())GetGlobalPoolAllocator)();
      ptUserDef = (unsigned char *)poolAllocatorArg2;
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_(structTypeNameString,typeNameChars,ptUserDef);
      structTypeName = structTypeNameString;
    }
  }
  stackTypeTypeName = structTypeName;
  (**(code **)(*(int *)initializer + 0x38))(&ptCopyType,initializer);
  typesMatch = 0;
  if ((((uint)stackTypeBits & 0x1fffe00) == (pt2CopyQualifier & 0x1fffe00)) && (stackTypeStructure == ptCopySize)) {
    typesMatch = 1;
  }
  stackType = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  ptCopyType = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  if (typesMatch == 0) {
    qualifierString = (char *)getQualifierString((uint)newNode[0xc] >> 0x19);
    error((int)this,(char *)line," non-matching types for const initializer ",qualifierString,"",ptQualifierCopy,
          typesMatch,ptType);
    goto LAB_97b9e184;
  }
  constantUnionNode = (**(code **)(*(int *)initializer + 0x18))(initializer);
  if (constantUnionNode == 0) {
    aggregateNodeResult = (**(code **)(*(int *)initializer + 0x1c))(initializer);
    if (aggregateNodeResult != 0) {
      variableConstPointer = (unsigned char *)newNode[0xe];
      if (variableConstPointer == (unsigned char *)0x0) {
        if (newNode[5] == 0) {
          variableBitsCopy = newNode[0xc];
          if ((variableBitsCopy & 0x400) == 0) {
            typeSize = (int)(variableBitsCopy << 0xd | variableBitsCopy >> 0x13) >> 0x18;
          }
          else {
            typeSize = (int)(variableBitsCopy << 0xd | variableBitsCopy >> 0x13) >> 0x18;
            typeSize = typeSize * typeSize;
          }
        }
        else {
          typeSize = newNode[9];
        }
        poolAllocator = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
        variableConstPointer = (unsigned char *)((int (*)())TPoolAllocator__allocate)(poolAllocator,typeSize << 2);
        newNode[0xe] = (int)variableConstPointer;
      }
      aggregateNode = (int *)(**(code **)(*(int *)initializer + 0x1c))(initializer);
      sequence = (**(code **)(*aggregateNode + 100))(aggregateNode);
      passThroughR4 = extraout_r4_03;
      if (*(int *)(sequence + 8) - *(int *)(sequence + 4) >> 2 == 1) {
        aggregateNode = (int *)(**(code **)(*(int *)initializer + 0x1c))(initializer);
        sequence = (**(code **)(*aggregateNode + 100))(aggregateNode);
        childVtable = *(int *)**(undefined4 **)(sequence + 4);
        childConstantUnion = (int *)(**(code **)(childVtable + 0x14))
                                  ((int *)**(undefined4 **)(sequence + 4),a1,ptUserDef,qualifierIsNotConst,ptLine,
                                   ptQualifierCopy,childVtable);
        childConstantUnionResult = (**(code **)(*childConstantUnion + 0x18))(childConstantUnion);
        passThroughR4 = a1_00;
        if (childConstantUnionResult != 0) {
          local_14c = newNode[4];
          stackTypeStructure = (undefined **)newNode[5];
          stackTypeFieldName = newNode[6];
          stackTypeWord14 = newNode[8];
          stackTypeStructureSize = newNode[9];
          stackTypeWord1c = newNode[10];
          stackTypeWord20 = newNode[0xb];
          stackTypeTypeName = (undefined **)newNode[7];
          stackType = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
          stackTypeBits = (unsigned char *)
                      (((uint)newNode[0xc] >> 9 & 1) << 9 |
                      ((uint)newNode[0xc] >> 10 & 1) << 10 |
                      newNode[0xc] & 0x7f800U |
                      ((uint)newNode[0xc] >> 0x13 & 0x3f) << 0x13 |
                      newNode[0xc] & 0xfe000000U | (uint)stackTypeBits & 0x1ff);
          constantArrayPtr = (**(code **)(*(int *)initializer + 0x1c))
                            (initializer,a1_00,stackTypeBits,stackTypeWord20,stackTypeWord1c,stackTypeStructureSize,stackTypeFieldName,
                             stackTypeWord14);
          symbolTableArg = *(undefined4 *)(this + 4);
          passThroughR4 = *(undefined4 *)(constantArrayPtr + 0x30);
          this_01 = *(unsigned char **)this;
          singleConstantParam = 1;
          goto LAB_97b9e6d8;
        }
      }
      local_14c = newNode[4];
      stackTypeStructure = (undefined **)newNode[5];
      stackTypeFieldName = newNode[6];
      stackTypeWord14 = newNode[8];
      stackTypeStructureSize = newNode[9];
      stackTypeWord1c = newNode[10];
      stackTypeWord20 = newNode[0xb];
      stackTypeTypeName = (undefined **)newNode[7];
      stackType = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
      variableBasicTypeBits = ((uint)newNode[0xc] >> 0x13 & 0x3f) << 0x13;
      variableMatrixBits = ((uint)newNode[0xc] >> 10 & 1) << 10;
      stackTypeLowBits = (uint)stackTypeBits & 0x3ff;
      stackTypeBits = (unsigned char *)
                  (((uint)newNode[0xc] >> 9 & 1) << 9 |
                  variableMatrixBits | newNode[0xc] & 0x7f800U |
                          variableBasicTypeBits | newNode[0xc] & 0xfe000000U | (uint)stackTypeBits & 0x1ff);
      constantArrayPtr = (**(code **)(*(int *)initializer + 0x1c))
                        (initializer,passThroughR4,
                         variableMatrixBits | newNode[0xc] & 0x7f800U |
                                 variableBasicTypeBits | newNode[0xc] & 0xfe000000U | stackTypeLowBits,stackTypeWord20,stackTypeWord1c,
                         stackTypeStructureSize,stackTypeFieldName,stackTypeWord14);
      symbolTableArg = *(undefined4 *)(this + 4);
      passThroughR4 = *(undefined4 *)(constantArrayPtr + 0x30);
      this_01 = *(unsigned char **)this;
      singleConstantParam = 0;
LAB_97b9e6d8:
      parseResult = TIntermediate__parseConstTree
                        (this_01,line,(unsigned char *)initializer,variableConstPointer,passThroughR4,symbolTableArg,
                         (unsigned char *)&stackType,singleConstantParam);
      stackType = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
      *intermNode = (unsigned char *)0x0;
      if (parseResult != 0) {
        (**(code **)(newNode[3] + 0x28))(a0,0);
        return parseResult;
      }
      return 0;
    }
    symbolNodeResult = (**(code **)(*(int *)initializer + 0x28))(initializer);
    if (symbolNodeResult == 0) {
      TType__getCompleteString((unsigned char *)&stackType,a0);
      stringTerminator = *DAT_a7b7ba18;
      *(byte *)(local_14c + *(int *)(local_14c - 0xc)) = stringTerminator;
      error((int)this,(char *)line," assigning non-constant to","=","\'%s\'",local_14c,
            (uint)stringTerminator,ptType);
      refCountPtr = (int *)(local_14c - 4);
      destroyAllocator3[0] = stackType;
      do {
        oldRefCount = *refCountPtr;
        if (reservation != '\0') {
          newRefCount = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
          *refCountPtr = newRefCount;
          cr0Flags = 2;
        }
      } while (!(bool)(cr0Flags >> 1 & 1));
      if (0 < oldRefCount) goto LAB_97b9e184;
      destroyAllocatorArg = destroyAllocator3;
      typeStringData = local_14c;
      goto LAB_97b9e848;
    }
    symbolTable = *(int **)(this + 4);
    symbolNode = (int *)(**(code **)(*(int *)initializer + 0x28))(initializer);
    passThroughR4 = (**(code **)(*symbolNode + 0x60))(symbolNode);
    iVar8 = *symbolTable;
    levelIndex = (symbolTable[1] - iVar8 >> 2) + -1;
    while( true ) {
      currentLevel = *(int *)(iVar8 + levelIndex * 4);
      std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______find((unsigned char *)levelFindResult,currentLevel,passThroughR4);
      iVar8 = 0;
      if (levelFindResult[0] != *(int *)(currentLevel + 4)) {
        iVar8 = *(int *)(levelFindResult[0] + 0x18);
      }
      levelIndex = levelIndex + -1;
      if ((iVar8 != 0) || (levelIndex < 0)) break;
      iVar8 = *symbolTable;
    }
    iVar8 = *(int *)(iVar8 + 0x38);
  }
  else {
    variableConstArray = (undefined4 *)newNode[0xe];
    if (variableConstArray == (undefined4 *)0x0) {
      if (newNode[5] == 0) {
        variableBits = newNode[0xc];
        if ((variableBits & 0x400) == 0) {
          typeSize = (int)(variableBits << 0xd | variableBits >> 0x13) >> 0x18;
        }
        else {
          typeSize = (int)(variableBits << 0xd | variableBits >> 0x13) >> 0x18;
          typeSize = typeSize * typeSize;
        }
      }
      else {
        typeSize = newNode[9];
      }
      poolAllocator = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
      variableConstArray = (undefined4 *)((int (*)())TPoolAllocator__allocate)(poolAllocator,typeSize << 2);
      newNode[0xe] = (int)variableConstArray;
    }
    ptSizeCopy = *(undefined ***)(publicType + 8);
    if (ptSizeCopy == (undefined **)0x1) {
      ptCopyUserDef = *(unsigned char **)(publicType + 0x14);
      levelsBegin = *(uint *)(publicType + 4);
      decrementedRefCount = 0;
      ptSize = *(undefined ***)publicType;
      ptLine = *(uint *)(publicType + 0xc);
      ptCopyArray = *(uint *)(publicType + 0x10);
      qualifierIsNotConst = *(uint *)(publicType + 0x18);
      stackTypeBitsCopy = (unsigned char *)
                ((ptCopyArray & 1) << 9 |
                (ptLine & 1) << 10 |
                ((uint)ptSize & 0x3f) << 0x13 | levelsBegin << 0x19 | (uint)stackTypeBits & 0x1ff | 0x800);
      stackType = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
      stackTypeWord20 = 0;
      local_14c = 0;
      stackTypeStructure = (undefined **)0x0;
      stackTypeFieldName = 0;
      stackTypeTypeName = (undefined **)0x0;
      stackTypeWord14 = 0;
      stackTypeStructureSize = 0;
      stackTypeWord1c = 0;
      structTypeNameString = stackTypeTypeName;
      stackTypeBits = stackTypeBitsCopy;
      ptCopyType = ptSize;
      ptCopyQualifier = levelsBegin;
      ptCopySize = ptSizeCopy;
      ptCopyMatrix = ptLine;
      ptCopyLine = qualifierIsNotConst;
      pt2CopyType = ptSize;
      pt2CopyQualifier = levelsBegin;
      pt2CopySize = ptSizeCopy;
      pt2CopyMatrix = ptLine;
      pt2CopyArray = ptCopyArray;
      pt2CopyUserDef = ptCopyUserDef;
      pt2CopyLine = qualifierIsNotConst;
      if (ptCopyUserDef != (unsigned char *)0x0) {
        stackTypeStructure = *(undefined ***)(ptCopyUserDef + 8);
        structSizeResult = TType__setStructSize((unsigned char *)&stackType,*(unsigned char **)(ptCopyUserDef + 8));
        stackTypeStructureSize = (uint)((ulonglong)structSizeResult >> 0x20);
        structTypeNameStringRef = (**(code **)(*(int *)pt2CopyUserDef + 0x18))
                          (pt2CopyUserDef,(int)structSizeResult,stackTypeBitsCopy,qualifierIsNotConst,ptLine,ptSize,*(int *)pt2CopyUserDef);
        decrementedRefCount = (uint)*DAT_a7b7ba18;
        *(byte *)(*(int *)(structTypeNameStringRef + 4) + *(int *)(*(int *)(structTypeNameStringRef + 4) + -0xc)) = *DAT_a7b7ba18;
        typeNameChars = *(char **)(structTypeNameStringRef + 4);
        poolAllocator = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
        typeNameAllocation = ((int (*)())TPoolAllocator__allocate)(poolAllocator,8);
        this_00 = (undefined **)((ulonglong)typeNameAllocation >> 0x20);
        ptSizeCopy = (undefined **)typeNameAllocation;
        structTypeNameString = (undefined **)0x0;
        if (this_00 != (undefined **)0x0) {
          poolAllocatorArg3[0] = ((int (*)())GetGlobalPoolAllocator)();
          __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                    (this_00,typeNameChars,(unsigned char *)poolAllocatorArg3);
          ptSizeCopy = extraout_r4_02;
          structTypeNameString = this_00;
        }
      }
      stackTypeTypeName = structTypeNameString;
      stackType = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
      ptUserDef = stackTypeBits;
      if (((uint)stackTypeBits >> 0x13 & 0x3f) != 0xe) {
        ptBasicType = *(int *)publicType;
        if (ptBasicType != 2) {
          if (ptBasicType < 3) {
            if (ptBasicType == 1) {
              constantUnionNodeArray = (**(code **)(*(int *)initializer + 0x18))(initializer,ptSizeCopy,stackTypeBits,1);
              *variableConstArray = **(undefined4 **)(constantUnionNodeArray + 0x30);
              goto LAB_97b9e850;
            }
          }
          else if (ptBasicType == 3) goto LAB_97b9e3bc;
          nameChars = "";
          errorReason = " cannot initialize constant of this type";
LAB_97b9df14:
          error((int)this,(char *)line,errorReason,nameChars,"",ptSize,decrementedRefCount,levelsBegin);
          return 1;
        }
LAB_97b9e3bc:
        constantUnionNodeArray = (**(code **)(*(int *)initializer + 0x18))(initializer);
        *variableConstArray = **(undefined4 **)(constantUnionNodeArray + 0x30);
        goto LAB_97b9e850;
      }
    }
    iVar8 = (**(code **)(*(int *)initializer + 0x18))(initializer,ptSizeCopy,ptUserDef,qualifierIsNotConst,ptLine);
    iVar8 = *(int *)(iVar8 + 0x30);
  }
  newNode[0xe] = iVar8;
LAB_97b9e850:
  *intermNode = (unsigned char *)0x0;
  return 0;
}

/* TParseContext__canNodeBeRemoved @ 0x97b9e960 (204 bytes) */
int TParseContext__canNodeBeRemoved(this, intermNode)
  unsigned char * this;
  unsigned char * intermNode;
{
  undefined4 uVar1;
  unsigned char * this_00;
  int iVar2;
  int *a0;
  int iVar3;
  undefined4 *puVar4;
  
  this_00 = (unsigned char *)(**(code **)(*(int *)intermNode + 0x1c))(intermNode,intermNode);
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
int TParseContext__addConstructor(this, intermNode, type, op, function, param_6)
  unsigned char * this;
  unsigned char * intermNode;
  unsigned char * type;
  int op;
  int function;
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
  
  if (intermNode == (unsigned char *)0x0) {
    return (unsigned char *)0x0;
  }
  iVar10 = 0;
  bVar1 = op != 0x75;
  puVar9 = (undefined4 *)0x0;
  pcVar8 = param_6;
  a0 = (unsigned char *)(**(code **)(*(int *)intermNode + 0x1c))(intermNode);
  if (!bVar1) {
    iVar10 = *(int *)(function + 0x24);
    puVar9 = *(undefined4 **)(iVar10 + 4);
  }
  if (((a0 == (unsigned char *)0x0) || (*(int *)(a0 + 0x30) != 0)) ||
     (iVar2 = (**(code **)(*(int *)a0 + 100))(a0),
     *(int *)(iVar2 + 8) - *(int *)(iVar2 + 4) >> 2 == 1)) {
    if (bVar1) {
      uVar4 = (*(code *)**(undefined4 **)intermNode)(intermNode);
      a5 = 0;
      pTVar3 = (unsigned char *)((int (*)())TParseContext__constructBuiltIn)(this,type,op,intermNode,uVar4,0);
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
                         ((int *)**(undefined4 **)(iVar10 + 4),a1,op,intermNode,uVar4,a5,iVar2);
      pTVar3 = (unsigned char *)
               __ZN13TIntermediate15removeChildNodeEP12TIntermTypedP5TTypeP16TIntermAggregate
                         (*(void **)this,pTVar3,type,pTVar6);
      return pTVar3;
    }
    if (*(int *)(iVar10 + 8) - *(int *)(iVar10 + 4) >> 3 == 1) {
      iVar10 = (*(code *)**(undefined4 **)intermNode)(intermNode);
      pTVar3 = (unsigned char *)((int (*)())TParseContext__constructStruct)(this,intermNode,(unsigned char *)*puVar9,1,iVar10,0);
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
                   TIntermediate__setAggregateOperator(*(unsigned char **)this,a0,op,param_6);
          return pTVar3;
        }
        if (bVar1) {
          uVar4 = (*(code *)**(undefined4 **)intermNode)(intermNode);
          a0_00 = (unsigned char *)((int (*)())TParseContext__constructBuiltIn)(this,type,op,*puVar11,uVar4,1);
          if (a0_00 != (unsigned char *)0x0) {
            iVar10 = ((int (*)())TParseContext__canNodeBeRemoved)(this,a0_00);
            if (iVar10 == 0) goto LAB_97b9ed60;
            pTVar6 = (unsigned char *)(**(code **)(*(int *)a0_00 + 0x1c))(a0_00);
            __ZN13TIntermediate15removeChildNodeER7TVectorIP11TIntermNodeER5TTypeRiRN9__gnu_cxx17__normal_iteratorIPS2_St6vectorIS2_14pool_allocatorIS2_EEEEP16TIntermAggregate
                      (*(void **)this,pTVar7,type,&local_3c,(unsigned char *)&local_38,pTVar6
                      );
          }
        }
        else {
          iVar2 = (*(code *)**(undefined4 **)intermNode)(intermNode);
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
int TParseContext__constructBuiltIn(this, type, op, intermNode, param_5, param_6)
  unsigned char * this;
  unsigned char * type;
  int op;
  unsigned char * intermNode;
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
  
  uVar5 = op - 0x66;
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
    uVar2 = (*(code *)**(undefined4 **)intermNode)(intermNode);
    pTVar3 = (unsigned char *)
             TIntermediate__addUnaryMath
                       (*(unsigned char **)this,uVar7,intermNode,uVar2,*(undefined4 *)(this + 4),iVar4,
                        iVar6);
    if (pTVar3 != (unsigned char *)0x0) {
      if (param_6 != 0) {
        return pTVar3;
      }
      if (pTVar3 != intermNode) {
        (**(code **)(*(int *)pTVar3 + 0x38))(local_50,pTVar3);
        bVar1 = false;
        if (((local_2c & 0x1fffe00) == (*(uint *)(type + 0x24) & 0x1fffe00)) &&
           (local_48 == *(int *)(type + 8))) {
          bVar1 = true;
        }
        local_50[0] = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
        if (bVar1) {
          return pTVar3;
        }
      }
      pTVar3 = (unsigned char *)
               TIntermediate__setAggregateOperator(*(unsigned char **)this,pTVar3,op,param_5);
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
int TParseContext__constructStruct(this, intermNode, type, param_4, param_5, param_6)
  unsigned char * this;
  unsigned char * intermNode;
  unsigned char * type;
  int param_4;
  int param_5;
  int param_6;
{
  undefined4 basicString;
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
  
  a2 = type;
  a3 = param_4;
  a4 = param_5;
  a5 = param_6;
  piVar1 = (int *)(**(code **)(*(int *)intermNode + 0x14))
                            (intermNode,intermNode,type,param_4,param_5,param_6);
  (**(code **)(*piVar1 + 0x38))(local_80,piVar1);
  a6 = 0;
  if (((*(uint *)(type + 0x24) & 0x1fffe00) == (local_5c & 0x1fffe00)) &&
     (*(int *)(type + 8) == local_78)) {
    a6 = 1;
  }
  local_80[0] = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  if (a6 == 0) {
    basicString = TType__getBasicString(*(uint *)(type + 0x24) >> 0x13 & 0x3f);
    piVar1 = (int *)(**(code **)(*(int *)intermNode + 0x14))(intermNode);
    (**(code **)(*piVar1 + 0x38))(local_50,piVar1);
    uVar4 = TType__getBasicString(local_2c >> 0x13 & 0x3f);
    error((int)this,(char *)param_5,"","constructor",
          "cannot convert parameter %d from \'%s\' to \'%s\'",param_4,uVar4,basicString);
    local_50[0] = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
    TParseContext__recover(this);
    uVar2 = 0;
  }
  else if (param_6 == 0) {
    pTVar3 = (unsigned char *)(**(code **)(*(int *)intermNode + 0x14))(intermNode);
    uVar2 = TIntermediate__setAggregateOperator(*(unsigned char **)this,pTVar3,0x75,param_5);
  }
  else {
    uVar2 = (**(code **)(*(int *)intermNode + 0x14))(intermNode,a1,a2,a3,a4,a5,a6);
  }
  return uVar2;
}

/* TParseContext__addConstVectorNode @ 0x97b9f138 (148 bytes) */
int TParseContext__addConstVectorNode(this, vectorFields, intermTyped, param_4, param_5, param_6)
  unsigned char * this;
  unsigned char * vectorFields;
  unsigned char * intermTyped;
  int param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  undefined *atomicStore;
  undefined **ppuVar2;
  int iVar3;
  undefined *oldRefCount;
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
  char reservation;
  byte cr0Flags;
  undefined **local_90 [4];
  char acStack_80 [20];
  uint local_6c;
  unsigned char aaStack_40 [16];
  
  pTVar9 = intermTyped;
  iVar11 = param_4;
  iVar5 = (**(code **)(*(int *)intermTyped + 0x18))(intermTyped,vectorFields,intermTyped,param_4,param_5,param_6);
  a1 = (unsigned char *)(**(code **)(*(int *)intermTyped + 0x1c))(intermTyped);
  if (iVar5 != 0) {
    pcVar10 = *(unsigned char **)(iVar5 + 0x30);
    if (pcVar10 == (unsigned char *)0x0) {
      this_00 = *(void **)(this + 8);
                    
      __ZN13TInfoSinkBase6appendEPKc(this_00,"INTERNAL ERROR: ");
      a1_01 = param_4 & 0xffff;
      cr0Flags = (a1_01 == 0) << 1;
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
        oldRefCount = *ppuVar2;
        if (reservation != '\0') {
          atomicStore = (undefined *)storeWordConditionalIndexed(oldRefCount + -1,0,ppuVar2);
          *ppuVar2 = atomicStore;
          cr0Flags = 2;
        }
      } while (!(bool)(cr0Flags >> 1 & 1));
      if ((int)oldRefCount < 1) {
        __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(local_90[0] + -3),acStack_80);
      }
      __ZN13TInfoSinkBase6appendEPKc(this_00,": ");
      __ZN13TInfoSinkBase6appendEPKc
                (this_00,"constUnion not initialized in addConstVectorNode function");
      __ZN13TInfoSinkBase6appendEPKc(this_00,"\n");
      TParseContext__recover(this);
      return intermTyped;
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
  iVar11 = *(int *)(vectorFields + 0x10);
  iVar5 = 0;
  pTVar7 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
  pcVar8 = (unsigned char *)((int (*)())TPoolAllocator__allocate)(pTVar7,iVar11 << 2);
  if (0 < *(int *)(vectorFields + 0x10)) {
    iVar11 = 0;
    do {
      (**(code **)(*(int *)intermTyped + 0x38))(local_90,intermTyped);
      if ((local_6c & 0x400) == 0) {
        iVar3 = (int)(local_6c << 0xd | local_6c >> 0x13) >> 0x18;
      }
      else {
        iVar3 = (int)(local_6c << 0xd | local_6c >> 0x13) >> 0x18;
        iVar3 = iVar3 * iVar3;
      }
      local_90[0] = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
      if (iVar3 <= *(int *)(vectorFields + iVar11) != 0) {
        error((int)this,(char *)param_4,"","[","vector field selection out of range \'%d\'",
              *(undefined4 *)(vectorFields + iVar11),(uint)(iVar3 <= *(int *)(vectorFields + iVar11)),in_r10);
        TParseContext__recover(this);
        *(undefined4 *)(vectorFields + iVar11) = 0;
      }
      iVar5 = iVar5 + 1;
      *(undefined4 *)(pcVar8 + iVar11) = *(undefined4 *)(pcVar10 + *(int *)(vectorFields + iVar11) * 4);
      iVar11 = iVar11 + 4;
    } while (iVar5 < *(int *)(vectorFields + 0x10));
  }
  (**(code **)(*(int *)intermTyped + 0x38))(local_90,intermTyped);
  pTVar9 = (unsigned char *)
           TIntermediate__addConstantUnion(*(unsigned char **)this,pcVar8,(unsigned char *)local_90,param_4)
  ;
  return pTVar9;
}

/* TParseContext__addConstMatrixNode @ 0x97b9f600 (904 bytes) */
int TParseContext__addConstMatrixNode(this, param_2, intermTyped, param_4)
  unsigned char * this;
  int param_2;
  unsigned char * intermTyped;
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
  
  a2 = (char *)intermTyped;
  a3 = (char *)param_4;
  piVar1 = (int *)(**(code **)(*(int *)intermTyped + 0x18))(intermTyped,param_2,intermTyped,param_4);
  a1 = (unsigned char *)(**(code **)(*(int *)intermTyped + 0x1c))(intermTyped);
  (**(code **)(*(int *)intermTyped + 0x38))(local_60,intermTyped);
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
int TParseContext__addConstStruct(this, text, intermTyped, param_4, param_5, param_6)
  unsigned char * this;
  unsigned char * text;
  unsigned char * intermTyped;
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
  a2 = intermTyped;
  iVar1 = param_4;
  (**(code **)(*(int *)intermTyped + 0x38))(local_80,intermTyped,intermTyped,param_4,param_5,param_6);
  iVar6 = *(int *)intermTyped;
  local_80[0] = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  pTVar2 = (unsigned char *)(**(code **)(iVar6 + 0x18))(intermTyped,a1_00,a2,iVar1,param_5,param_6,iVar6);
  a1 = (unsigned char *)(**(code **)(*(int *)intermTyped + 0x1c))(intermTyped);
  for (uVar9 = 0; uVar9 < (uint)(*(int *)(local_78 + 8) - *(int *)(local_78 + 4) >> 3);
      uVar9 = uVar9 + 1) {
    piVar3 = *(int **)(*(int *)(local_78 + 4) + uVar9 * 8);
    iVar7 = (**(code **)(*piVar3 + 0x1c))(piVar3);
    uVar12 = *(uint *)(*(int *)(iVar7 + 4) + -0xc);
    local_50 = uVar12;
    uVar10 = *(uint *)(*(int *)(text + 4) + -0xc);
    local_4c[0] = uVar10;
    puVar5 = local_4c;
    if (uVar12 <= uVar10) {
      puVar5 = &local_50;
    }
    a2 = (unsigned char *)*puVar5;
    iVar7 = _memcmp(*(undefined4 *)(iVar7 + 4),*(int *)(text + 4),a2);
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
  int oldRefCount2;
  int oldRefCount;
  int atomicStore2;
  int atomicStore;
  int *refCountPtr;
  int iVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  char reservation;
  byte cr0Reg;
  undefined4 local_d0;
  int local_cc;
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
    uVar5 = *(uint *)(local_cc + -0xc);
    local_30 = uVar5;
    uVar6 = *(uint *)(*(int *)(local_b0[0] + 0x14) + -0xc);
    local_2c[0] = uVar6;
    if (uVar5 <= uVar6) {
      puVar4 = &local_30;
    }
    iVar3 = _memcmp(local_cc,*(undefined4 *)(local_b0[0] + 0x14),*puVar4);
    cr0Reg = (iVar3 == 0) << 1;
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
  refCountPtr = (int *)(local_6c + -4);
  local_b0[0] = local_90[0];
  local_50[0] = local_70;
  do {
    oldRefCount2 = *refCountPtr;
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
      *refCountPtr = atomicStore;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  iVar2 = local_90[0];
  if (oldRefCount2 < 1) {
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
              ((unsigned char *)(local_6c + -0xc),local_50);
    iVar2 = local_b0[0];
  }
LAB_97b9fe04:
  *(undefined4 *)(iVar2 + 0x18) = 1;
  refCountPtr = (int *)(local_cc + -4);
  local_40[0] = local_d0;
  do {
    oldRefCount = *refCountPtr;
    if (reservation != '\0') {
      atomicStore2 = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
      *refCountPtr = atomicStore2;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  if (oldRefCount < 1) {
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
              ((unsigned char *)(local_cc + -0xc),local_40);
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
int SetGlobalPoolAllocatorPtr(poolAllocator)
  unsigned char * poolAllocator;
{
  *_gPollAllocThreadData = poolAllocator;
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
  return ((int (*)())__ZN14TPoolAllocatorD4Ev)(this);
}

/* __ZN14TPoolAllocatorD1Ev @ 0x97ba005c (8 bytes) */
int __ZN14TPoolAllocatorD1Ev(this)
  void *this;
{
  return ((int (*)())__ZN14TPoolAllocatorD4Ev)(this);
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
int TAllocation__checkGuardBlock(this, param_2, param_3)
  uchar *this;
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
  undefined4 *allocation;
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
      allocation = operator_new__(uVar8);
      iVar6 = 0;
      if (allocation != (undefined4 *)0x0) {
        uVar5 = *(uint *)(this + 4);
        *allocation = *(undefined4 *)(this + 0x1c);
        allocation[1] = ((uVar8 + uVar5) - 1) / uVar5;
        iVar6 = (int)allocation + *(int *)(this + 0x10);
        *(undefined4 **)(this + 0x1c) = allocation;
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
    iVar6 = *(int *)(this + 0x1c) + iVar6 + (int)GH_F2U(fVar1);
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
int QualifierWritten(intermNode, qualifier, param_3, param_4, param_5, param_6, param_7, param_8)
  unsigned char * intermNode;
  undefined4 qualifier;
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
  if (intermNode != (unsigned char *)0x0) {
    local_1c = qualifier;
    (**(code **)(*(int *)intermNode + 8))
              (intermNode,&local_50,param_3,param_4,param_5,param_6,DAT_a7b7ba20,intermNode);
  }
  return local_20;
}

/* AliveSymbol @ 0x97ba0514 (76 bytes) */
int AliveSymbol(intermSymbol, intermTraverser)
  unsigned char * intermSymbol;
  unsigned char * intermTraverser;
{
  int iVar1;
  
  iVar1 = (**(code **)(*(int *)intermSymbol + 0x44))(intermSymbol);
  if (iVar1 == *(int *)(intermTraverser + 0x34)) {
    *(undefined4 *)(intermTraverser + 0x30) = 1;
  }
  return;
}

/* AliveSelection @ 0x97ba0560 (16 bytes) */
int AliveSelection(param_1, intermSelection, intermTraverser)
  int param_1;
  unsigned char * intermSelection;
  unsigned char * intermTraverser;
{
  return *(int *)(intermTraverser + 0x30) == 0;
}

/* RemoveSymbol @ 0x97ba0570 (24 bytes) */
int RemoveSymbol(intermSymbol, intermTraverser)
  unsigned char * intermSymbol;
  unsigned char * intermTraverser;
{
  if (intermSymbol == (unsigned char *)0x0) {
    return;
  }
                    
                    
  (**(code **)(*(int *)intermSymbol + 0x30))(intermSymbol);
  return;
}

/* RemoveBinary @ 0x97ba0588 (56 bytes) */
int RemoveBinary(param_1, intermBinary, intermTraverser)
  int param_1;
  unsigned char * intermBinary;
  unsigned char * intermTraverser;
{
  if (intermBinary != (unsigned char *)0x0) {
    (**(code **)(*(int *)intermBinary + 0x30))(intermBinary);
  }
  return 1;
}

/* RemoveUnary @ 0x97ba05c0 (56 bytes) */
int RemoveUnary(param_1, intermUnary, intermTraverser)
  int param_1;
  unsigned char * intermUnary;
  unsigned char * intermTraverser;
{
  if (intermUnary != (unsigned char *)0x0) {
    (**(code **)(*(int *)intermUnary + 0x30))(intermUnary);
  }
  return 1;
}

/* RemoveAggregate @ 0x97ba05f8 (56 bytes) */
int RemoveAggregate(param_1, intermAggregate, intermTraverser)
  int param_1;
  unsigned char * intermAggregate;
  unsigned char * intermTraverser;
{
  if (intermAggregate != (unsigned char *)0x0) {
    (**(code **)(*(int *)intermAggregate + 0x30))(intermAggregate);
  }
  return 1;
}

/* RemoveSelection @ 0x97ba0630 (56 bytes) */
int RemoveSelection(param_1, intermSelection, intermTraverser)
  int param_1;
  unsigned char * intermSelection;
  unsigned char * intermTraverser;
{
  if (intermSelection != (unsigned char *)0x0) {
    (**(code **)(*(int *)intermSelection + 0x30))(intermSelection);
  }
  return 1;
}

/* RemoveConstantUnion @ 0x97ba0668 (24 bytes) */
int RemoveConstantUnion(intermConstantUnion, intermTraverser)
  unsigned char * intermConstantUnion;
  unsigned char * intermTraverser;
{
  if (intermConstantUnion == (unsigned char *)0x0) {
    return;
  }
                    
                    
  (**(code **)(*(int *)intermConstantUnion + 0x30))(intermConstantUnion);
  return;
}

/* RemoveAllTreeNodes @ 0x97ba0680 (168 bytes) */
int RemoveAllTreeNodes(intermNode)
  unsigned char * intermNode;
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
  return (**(code **)(*(int *)intermNode + 8))
            (intermNode,&local_40,in_r5,in_r6,in_r7,in_r8,DAT_a7b7ba28,*(int *)intermNode);
}

/* GetSymbolTable @ 0x97ba0728 (132 bytes) */
int GetSymbolTable(param_1)
  int param_1;
{
  undefined4 *puVar1;
  undefined4 *allocation;
  
  puVar1 = &GetSymbolTable__SymbolTables;
  if (GetSymbolTable__SymbolTables == 0) {
    do {
      allocation = operator_new(0x10);
      *allocation = 0;
      allocation[1] = 0;
      allocation[2] = 0;
      allocation[3] = 0;
      *puVar1 = allocation;
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
  int *refCountPtr;
  int initProcessResult;
  int atomicStore;
  int atomicStore2;
  int *piVar2;
  int oldRefCount;
  unsigned char * pTVar4;
  unsigned char * this;
  unsigned char * pTVar5;
  undefined4 uVar6;
  char reservation;
  byte cr0Reg;
  undefined *local_40;
  undefined4 local_3c;
  undefined *local_38;
  undefined4 local_34;
  undefined1 auStack_30 [28];
  
  local_40 = PTR__S_empty_rep_storage_a7b7c0f0;
  piVar2 = (int *)(PTR__S_empty_rep_storage_a7b7c0f0 + 8);
  do {
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(*piVar2 + 1,0,piVar2);
      *piVar2 = atomicStore;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  local_40 = local_40 + 0xc;
  local_3c = 4;
  do {
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(*piVar2 + 1,0,piVar2);
      *piVar2 = atomicStore;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  local_34 = 4;
  local_38 = local_40;
  _pthread_mutex_lock(&_glsl_allocator_lock);
  initProcessResult = InitProcess();
  uVar6 = 1;
  if (initProcessResult == 0) {
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
  _pthread_mutex_unlock(&_glsl_allocator_lock);
  refCountPtr = (int *)(local_38 + -4);
  do {
    oldRefCount = *refCountPtr;
    if (reservation != '\0') {
      atomicStore2 = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
      *refCountPtr = atomicStore2;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  if (oldRefCount < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(local_38 + -0xc),auStack_30);
  }
  refCountPtr = (int *)(local_40 + -4);
  do {
    oldRefCount = *refCountPtr;
    if (reservation != '\0') {
      atomicStore2 = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
      *refCountPtr = atomicStore2;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  if (oldRefCount < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(local_40 + -0xc),auStack_30);
  }
  return uVar6;
}

/* _ShConstructCompiler @ 0x97ba0980 (32 bytes) */
int _ShConstructCompiler(language, param_2)
  undefined4 language;
  undefined4 param_2;
{
  return ConstructCompiler(language,param_2);
}

/* _ShDestruct @ 0x97ba09a4 (200 bytes) */
int _ShDestruct(param_1)
  int *param_1;
{
  int iVar1;
  unsigned char * pTVar2;
  unsigned char * pTVar3;
  
  if (param_1 != (int *)0x0) {
    _pthread_mutex_lock(&_glsl_allocator_lock);
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
    _pthread_mutex_unlock(&_glsl_allocator_lock);
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
int generateBuiltInSymbolTable(builtInResource, infoSink, symbolTable, language)
  unsigned char * builtInResource;
  unsigned char * infoSink;
  unsigned char * symbolTable;
  undefined4 language;
{
  unsigned char aTStack_30 [28];
  
  __ZN9TBuiltIns10initializeERK16TBuiltInResource(aTStack_30,builtInResource);
  ((int (*)())initializeSymbolTable)((unsigned char *)aTStack_30,0,infoSink,builtInResource,symbolTable);
  ((int (*)())initializeSymbolTable)((unsigned char *)aTStack_30,1,infoSink,builtInResource,symbolTable);
  return 1;
}

/* initializeSymbolTable @ 0x97ba0b4c (548 bytes) */
int initializeSymbolTable(builtIns, language, infoSink, builtInResource, symbolTable)
  unsigned char * builtIns;
  int language;
  void *infoSink;
  undefined4 builtInResource;
  undefined4 symbolTable;
{
  int *refCountPtr;
  int oldRefCount;
  int paParseStringsResult;
  int initPreprocessorResult;
  int atomicStore2;
  int *stringSizeArray;
  int numStrings;
  int atomicStore;
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
  char reservation;
  byte cr0Reg;
  byte cr0Flags;
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
  
  local_40[0] = infoSink;
  this = (unsigned char *)((int (*)())GetSymbolTable)(language);
  local_130 = local_40;
  local_120 = 0;
  local_11c = 0;
  local_118 = 0;
  local_114 = 0;
  local_110 = 0;
  local_10c = 0;
  local_12c = this;
  local_128 = infoSink;
  local_124 = language;
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
    if (reservation != '\0') {
      atomicStore2 = storeWordConditionalIndexed(*piVar2 + 1,0,piVar2);
      *piVar2 = atomicStore2;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  local_d8 = ((int (*)())GetGlobalPoolAllocator)();
  local_d4 = local_d4 + 0xc;
  local_a0 = local_d8;
  setInitialState();
  iVar3 = *(int *)(this + 4) - *(int *)this >> 2;
  cr0Flags = (iVar3 != 0) << 1;
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
  initPreprocessorResult = _InitPreprocessor();
  if (initPreprocessorResult == 0) {
    uVar6 = TBuiltIns__getNumStringArrays(builtIns,local_124);
    uVar9 = 0;
    if (uVar6 != 0) {
LAB_97ba0e34:
      ppcVar7 = (char **)TBuiltIns__getStringArray(builtIns,local_124,uVar9);
      stringSizeArray = (int *)TBuiltIns__getStringSizeArray(builtIns,local_124,uVar9);
      numStrings = TBuiltIns__getNumStrings(builtIns,local_124,uVar9);
      paParseStringsResult = PaParseStrings(ppcVar7,stringSizeArray,numStrings,0,(unsigned char *)&local_130);
      if (paParseStringsResult == 0) goto LAB_97ba0fd8;
                    
      __ZN13TInfoSinkBase6appendEPKc(infoSink,"INTERNAL ERROR: ");
      __ZN13TInfoSinkBase6appendEPKc(infoSink,"Unable to parse built-ins");
      __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
      _FinalizePreprocessor();
      refCountPtr = (int *)(local_d4 + -4);
      auStack_60[0] = local_d8;
      do {
        oldRefCount = *refCountPtr;
        if (reservation != '\0') {
          atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
          *refCountPtr = atomicStore;
          cr0Flags = 2;
        }
      } while (!(bool)(cr0Flags >> 1 & 1));
      if (oldRefCount < 1) {
        puVar4 = auStack_60;
        goto code_r0x97ba0f54;
      }
      goto code_r0x97ba0f58;
    }
LAB_97ba0fe4:
    __Z16IdentifyBuiltIns11EShLanguageR12TSymbolTableRK16TBuiltInResource(local_124,this,builtInResource);
    __Z16IdentifyBuiltIns11EShLanguageR12TSymbolTable(local_124,this);
    _FinalizePreprocessor();
    refCountPtr = (int *)(local_d4 + -4);
    local_70[0] = local_d8;
    do {
      oldRefCount = *refCountPtr;
      if (reservation != '\0') {
        atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
        *refCountPtr = atomicStore;
        cr0Flags = 2;
      }
    } while (!(bool)(cr0Flags >> 1 & 1));
    if (oldRefCount < 1) {
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
                    
    __ZN13TInfoSinkBase6appendEPKc(infoSink,"INTERNAL ERROR: ");
    __ZN13TInfoSinkBase6appendEPKc(infoSink,"Unable to intialize the Preprocessor");
    __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
    refCountPtr = (int *)(local_d4 + -4);
    auStack_50[0] = local_d8;
    do {
      oldRefCount = *refCountPtr;
      if (reservation != '\0') {
        atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
        *refCountPtr = atomicStore;
        cr0Flags = 2;
      }
    } while (!(bool)(cr0Flags >> 1 & 1));
    puVar4 = auStack_50;
    if (oldRefCount < 1) {
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
int _ShCompile(handle, str, numStrings, optLevel, debugOptions)
  int *handle;
  char **str;
  int numStrings;
  int optLevel;
  uint debugOptions;
{
  int *refCountPtr;
  int oldRefCount;
  int paParseStringsResult;
  int insertBuiltInArrayAtGlobalLevelResult;
  bool bVar1;
  int atomicStore;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int *compiler;
  unsigned char * pTVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  void *pvVar10;
  void *pvVar11;
  char *pcVar12;
  uint success;
  char *stringRepData;
  uint *this;
  char reservation;
  byte cr0Flags;
  void *symbolTableLevelsBegin;
  int *symbolTableLevelsEnd;
  int *symbolTableLevelsCapacityEnd;
  undefined4 symbolTableNextId;
  unsigned char * local_160;
  undefined4 *newLevelSlot [4];
  int *parseContextIntermediate;
  unsigned char * symbolTableLevelsPtr;
  void *infoSink;
  int language;
  unsigned char * treeRoot;
  int errorFlag;
  undefined4 numErrors;
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_11c;
  unsigned char * extensionBehaviorAllocator;
  undefined4 *extensionBehaviorHeader;
  int extensionBehaviorCount;
  undefined4 local_100;
  undefined4 local_fc;
  unsigned char * stringMapAllocator;
  undefined4 *stringMapHeader;
  int stringMapCount;
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
  int intermediate;
  char *preprocessorBuiltinStrings [3];
  
  preprocessorBuiltinStrings[0] = (char *)GetPreprocessorBuiltinString();
  if (handle == (int *)0x0) {
    return 0;
  }
  compiler = (int *)(**(code **)(*handle + 8))(handle);
  cr0Flags = (compiler == (int *)0x0) << 1;
  if (compiler == (int *)0x0) {
    return 0;
  }
  _pthread_mutex_lock(&_glsl_allocator_lock);
  pTVar7 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
  ((int (*)())TPoolAllocator__push)(pTVar7);
  (**(code **)(*compiler + 0x18))(compiler);
  this = (uint *)compiler[1];
  stringRepData = (char *)*this;
  iVar3 = *(int *)(stringRepData + -0xc);
  pcVar12 = (char *)*this;
  if (((*(int *)(pcVar12 + -4) < 1) && (pcVar12 <= stringRepData)) && (stringRepData <= pcVar12 + iVar3)) {
    __ZNSs10_M_replaceIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_St18input_iterator_tag
              (this,pcVar12,pcVar12 + iVar3,stringRepData,stringRepData,0);
  }
  else {
    __ZNSs15_M_replace_safeIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_
              (this,pcVar12,pcVar12 + iVar3,stringRepData,stringRepData);
  }
  pcVar12 = *(char **)(compiler[1] + 8);
  __ZNSs7replaceEmmPKcm((void *)(compiler[1] + 8),0,*(ulong *)(pcVar12 + -0xc),pcVar12,0);
  if (numStrings == 0) {
    _pthread_mutex_unlock(&_glsl_allocator_lock);
    return 1;
  }
  intermediate = compiler[1];
  puVar8 = (undefined4 *)((int (*)())GetSymbolTable)(compiler[2]);
  symbolTableLevelsBegin = (void *)0x0;
  symbolTableLevelsEnd = (int *)0x0;
  symbolTableLevelsCapacityEnd = (int *)0x0;
  std__vector_TSymbolTableLevel__std__allocator_TSymbolTableLevel______M_insert_aux
            ((unsigned char *)&symbolTableLevelsBegin,0,*puVar8);
  symbolTableNextId = puVar8[3];
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
  newLevelSlot[0] = puVar8;
  if (symbolTableLevelsEnd == symbolTableLevelsCapacityEnd) {
    std__vector_TSymbolTableLevel__std__allocator_TSymbolTableLevel______M_insert_aux
              ((unsigned char *)&symbolTableLevelsBegin,symbolTableLevelsEnd
               ,newLevelSlot);
  }
  else {
    if (symbolTableLevelsEnd != (int *)0x0) {
      *symbolTableLevelsEnd = (int)puVar8;
    }
    symbolTableLevelsEnd = symbolTableLevelsEnd + 1;
  }
  infoSink = (void *)compiler[1];
  language = compiler[2];
  parseContextIntermediate = &intermediate;
  treeRoot = (unsigned char *)0x0;
  errorFlag = 0;
  numErrors = 0;
  local_124 = 0;
  local_120 = 0;
  local_11c = 0;
  symbolTableLevelsPtr = (unsigned char *)&symbolTableLevelsBegin;
  extensionBehaviorAllocator = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
  extensionBehaviorHeader = (undefined4 *)0x0;
  local_d0 = extensionBehaviorAllocator;
  extensionBehaviorHeader = (undefined4 *)((int (*)())TPoolAllocator__allocate)(extensionBehaviorAllocator,0x1c);
  extensionBehaviorCount = 0;
  *extensionBehaviorHeader = 0;
  extensionBehaviorHeader[1] = 0;
  extensionBehaviorHeader[2] = extensionBehaviorHeader;
  extensionBehaviorHeader[3] = extensionBehaviorHeader;
  local_100 = 1;
  local_fc = 0;
  stringMapAllocator = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
  stringMapHeader = (undefined4 *)0x0;
  local_c0 = stringMapAllocator;
  stringMapHeader = (undefined4 *)((int (*)())TPoolAllocator__allocate)(stringMapAllocator,0x20);
  stringMapCount = 0;
  *stringMapHeader = 0;
  local_e4 = DAT_a7b7ba70;
  stringMapHeader[1] = 0;
  piVar4 = (int *)(local_e4 + 8);
  stringMapHeader[2] = stringMapHeader;
  stringMapHeader[3] = stringMapHeader;
  do {
    if (reservation != '\0') {
      iVar3 = storeWordConditionalIndexed(*piVar4 + 1,0,piVar4);
      *piVar4 = iVar3;
      cr0Flags = 2;
    }
  } while (!(bool)(cr0Flags >> 1 & 1));
  local_e8 = ((int (*)())GetGlobalPoolAllocator)();
  local_e4 = local_e4 + 0xc;
  local_b0 = local_e8;
  ((int (*)())TParseContext__initializeExtensionBehavior)((unsigned char *)&parseContextIntermediate);
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
  newLevelSlot[0] = puVar8;
  if (symbolTableLevelsEnd == symbolTableLevelsCapacityEnd) {
    std__vector_TSymbolTableLevel__std__allocator_TSymbolTableLevel______M_insert_aux
              ((unsigned char *)&symbolTableLevelsBegin,symbolTableLevelsEnd
               ,newLevelSlot);
  }
  else {
    if (symbolTableLevelsEnd != (int *)0x0) {
      *symbolTableLevelsEnd = (int)puVar8;
    }
    symbolTableLevelsEnd = symbolTableLevelsEnd + 1;
  }
  pvVar10 = infoSink;
  bVar1 = 3 < (uint)((int)symbolTableLevelsEnd - (int)symbolTableLevelsBegin >> 2);
  if (bVar1) {
    __ZN13TInfoSinkBase6appendEPKc(infoSink,"INTERNAL ERROR: ");
    __ZN13TInfoSinkBase6appendEPKc(pvVar10,"Wrong symbol table level. No code generated.");
    __ZN13TInfoSinkBase6appendEPKc(pvVar10,"\n");
  }
  success = (uint)!bVar1;
  if (success == 1) {
    insertBuiltInArrayAtGlobalLevelResult = ((int (*)())TParseContext__insertBuiltInArrayAtGlobalLevel)((unsigned char *)&parseContextIntermediate);
    if (insertBuiltInArrayAtGlobalLevelResult == 0) {
      paParseStringsResult = PaParseStrings(preprocessorBuiltinStrings,(int *)0x0,1,0,(unsigned char *)&parseContextIntermediate);
      if (paParseStringsResult != 0) {
        success = 0;
      }
    }
    else {
      success = 0;
    }
  }
  iVar3 = PaParseStrings(str,(int *)0x0,numStrings,0,(unsigned char *)&parseContextIntermediate);
  pvVar10 = infoSink;
  if (iVar3 != 0) {
    success = 0;
  }
  if ((success == 1) && (treeRoot != (unsigned char *)0x0)) {
    if (errorFlag == 0) {
      success = TIntermediate__postProcess((unsigned char *)&intermediate,treeRoot);
      pvVar10 = infoSink;
      if (success != 1) {
        __ZN13TInfoSinkBase6appendEPKc(infoSink,"INTERNAL ERROR: ");
        __ZN13TInfoSinkBase6appendEPKc
                  (pvVar10,"Parse tree post-processing failure. No code generated.");
        __ZN13TInfoSinkBase6appendEPKc(pvVar10,"\n");
        goto LAB_97ba18d4;
      }
      if (optLevel != 0) {
        bVar1 = (debugOptions & 1) == 0;
        cr0Flags = bVar1 << 1;
        if (!bVar1) {
          TIntermediate__outputTree((unsigned char *)&intermediate,treeRoot);
        }
        (**(code **)(*compiler + 0x34))(compiler,optLevel);
        (**(code **)(*compiler + 0x38))(compiler,debugOptions);
        iVar3 = (**(code **)(*compiler + 0x14))(compiler,treeRoot);
        if (iVar3 != 0) goto LAB_97ba18d4;
        goto LAB_97ba18cc;
      }
      __ZN13TInfoSinkBase6appendEPKc
                (infoSink,"No errors.  No code generation or linking was requested.");
      pcVar12 = "\n";
    }
    else {
      __ZN13TInfoSinkBase6appendEPKc(infoSink,"ERROR: ");
      pvVar10 = infoSink;
      _sprintf(acStack_80,"%d",numErrors);
      auStack_70[0] = ((int (*)())GetGlobalPoolAllocator)();
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                ((unsigned char *)&uStack_90,acStack_80,(unsigned char *)auStack_70);
      __ZN13TInfoSinkBase6appendERKSbIcSt11char_traitsIcE14pool_allocatorIcEE
                (pvVar10,(unsigned char *)&uStack_90);
      refCountPtr = (int *)(iStack_8c + -4);
      auStack_60[0] = uStack_90;
      do {
        iVar3 = *refCountPtr;
        if (reservation != '\0') {
          atomicStore = storeWordConditionalIndexed(iVar3 + -1,0,refCountPtr);
          *refCountPtr = atomicStore;
          cr0Flags = 2;
        }
      } while (!(bool)(cr0Flags >> 1 & 1));
      if (iVar3 < 1) {
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                  ((unsigned char *)(iStack_8c + -0xc),auStack_60);
      }
      pcVar12 = " compilation errors. No code generated.";
      success = 0;
    }
    __ZN13TInfoSinkBase6appendEPKc(pvVar10,pcVar12);
    bVar1 = (debugOptions & 1) == 0;
    cr0Flags = bVar1 << 1;
    if (!bVar1) {
      TIntermediate__outputTree((unsigned char *)&intermediate,treeRoot);
    }
  }
  else {
    if (treeRoot != (unsigned char *)0x0) goto LAB_97ba18d4;
    __ZN13TInfoSinkBase6appendEPKc(infoSink,"ERROR: ");
    __ZN13TInfoSinkBase6appendEPKc(pvVar10,"Parser found no code to compile in source strings.");
    __ZN13TInfoSinkBase6appendEPKc(pvVar10,"\n");
LAB_97ba18cc:
    success = 0;
  }
LAB_97ba18d4:
  TIntermediate__remove((unsigned char *)&intermediate,treeRoot);
  pvVar10 = symbolTableLevelsBegin;
  for (; iVar3 = (int)symbolTableLevelsEnd - (int)pvVar10 >> 2, iVar3 != 1; symbolTableLevelsEnd = symbolTableLevelsEnd + -1) {
    pvVar11 = *(void **)((int)pvVar10 + (iVar3 + -1) * 4);
    if (pvVar11 != (void *)0x0) {
      __ZN17TSymbolTableLevelD1Ev(pvVar11);
      pvVar10 = symbolTableLevelsBegin;
    }
  }
  _FinalizePreprocessor();
  pTVar7 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
  ((int (*)())TPoolAllocator__pop)(pTVar7);
  _pthread_mutex_unlock(&_glsl_allocator_lock);
  refCountPtr = (int *)(local_e4 + -4);
  local_50[0] = local_e8;
  do {
    oldRefCount = *refCountPtr;
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
      *refCountPtr = atomicStore;
      cr0Flags = 2;
    }
  } while (!(bool)(cr0Flags >> 1 & 1));
  if (oldRefCount < 1) {
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
              ((unsigned char *)(local_e4 + -0xc),local_50);
  }
  if (stringMapCount != 0) {
    std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string______M_erase((unsigned char
                *)&stringMapAllocator,(unsigned char *)stringMapHeader[1]);
    stringMapHeader[2] = stringMapHeader;
    stringMapHeader[1] = 0;
    stringMapHeader[3] = stringMapHeader;
    stringMapCount = 0;
  }
  pvVar10 = symbolTableLevelsBegin;
  if (extensionBehaviorCount != 0) {
    std___Rb_tree_std__string_std__pair_std__string_const_TBehavior__std___Select1st_std__pair_std__string_const_TBehavior___std__less_std__string__pool_allocator_std__pair_std__string_const_TBehavior______M_erase((unsigned char
                *)&extensionBehaviorAllocator,(unsigned char *)extensionBehaviorHeader[1]);
    extensionBehaviorHeader[2] = extensionBehaviorHeader;
    extensionBehaviorHeader[1] = 0;
    extensionBehaviorHeader[3] = extensionBehaviorHeader;
    extensionBehaviorCount = 0;
    pvVar10 = symbolTableLevelsBegin;
  }
  for (; uVar5 = (int)symbolTableLevelsEnd - (int)pvVar10 >> 2, 1 < uVar5; symbolTableLevelsEnd = symbolTableLevelsEnd + -1) {
    pvVar11 = *(void **)((int)pvVar10 + (uVar5 - 1) * 4);
    if (pvVar11 != (void *)0x0) {
      __ZN17TSymbolTableLevelD1Ev(pvVar11);
      pvVar10 = symbolTableLevelsBegin;
    }
  }
  iVar3 = (int)symbolTableLevelsCapacityEnd - (int)pvVar10 >> 2;
  if (iVar3 != 0) {
    std____default_alloc_template_true_0___deallocate(pvVar10,iVar3 << 2);
  }
  return success;
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

