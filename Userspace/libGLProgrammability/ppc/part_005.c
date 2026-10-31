#include "decls.h"

/* __ZN13TParseContext14boolErrorCheckEiPK12TIntermTyped @ 0x97b9ba78 (208 bytes) */
int __ZN13TParseContext14boolErrorCheckEiPK12TIntermTyped(this, sourceLoc, intermTyped, scratchR6, scratchR7, scratchR8)
  void *this;
  int sourceLoc;
  unsigned char * intermTyped;
  undefined4 scratchR6;
  undefined4 scratchR7;
  undefined4 scratchR8;
{
  int typeQueryResult;
  undefined4 scratchR9;
  undefined4 scratchR10;
  
  typeQueryResult = (**(code **)(*(int *)intermTyped + 0x40))(intermTyped,sourceLoc,intermTyped,scratchR6,scratchR7,scratchR8);
  if ((((typeQueryResult == 3) && (typeQueryResult = (**(code **)(*(int *)intermTyped + 0x54))(intermTyped), typeQueryResult == 0)) &&
      (typeQueryResult = (**(code **)(*(int *)intermTyped + 0x50))(intermTyped), typeQueryResult == 0)) &&
     (typeQueryResult = (**(code **)(*(int *)intermTyped + 0x58))(intermTyped), typeQueryResult == 0)) {
    return 0;
  }
  TParseContext__error
            ((int)this,(char *)sourceLoc,"boolean expression expected","","",scratchR8,scratchR9,scratchR10);
  return 1;
}

/* __ZN13TParseContext14boolErrorCheckEiRK11TPublicType @ 0x97b9bb48 (132 bytes) */
int __ZN13TParseContext14boolErrorCheckEiRK11TPublicType(this, sourceLoc, publicType)
  void *this;
  int sourceLoc;
  unsigned char * publicType;
{
  undefined4 result;
  undefined4 scratchR8;
  undefined4 scratchR9;
  undefined4 scratchR10;
  
  if ((((*(int *)publicType != 3) || (*(int *)(publicType + 0x10) != 0)) || (*(int *)(publicType + 0xc) != 0)
      ) || (result = 0, 1 < *(int *)(publicType + 8))) {
    TParseContext__error
              ((int)this,(char *)sourceLoc,"boolean expression expected","","",scratchR8,scratchR9,scratchR10);
    result = 1;
  }
  return result;
}

/* TParseContext__samplerErrorCheck @ 0x97b9bbcc (184 bytes) */
int TParseContext__samplerErrorCheck(this, sourceLoc, publicType, str)
  unsigned char * this;
  int sourceLoc;
  unsigned char * publicType;
  char *str;
{
  int containsSamplerResult;
  int basicType;
  char *basicString;
  char *extraInfo;
  undefined4 scratchR8;
  undefined4 scratchR9;
  undefined4 scratchR10;
  
  basicType = *(int *)publicType;
  if (basicType == 0xe) {
    containsSamplerResult = ((int (*)())TParseContext__containsSampler)(this,*(unsigned char **)(publicType + 0x14));
    if (containsSamplerResult == 0) {
      return 0;
    }
    basicString = (char *)TType__getBasicString(*(undefined4 *)publicType);
    extraInfo = "(structure contains a sampler)";
  }
  else {
    if (7 < basicType - 5U) {
      return 0;
    }
    basicString = (char *)TType__getBasicString(basicType);
    extraInfo = "";
  }
  error((int)this,(char *)sourceLoc,str,basicString,extraInfo,scratchR8,scratchR9,scratchR10);
  return 1;
}

/* TParseContext__structQualifierErrorCheck @ 0x97b9bc84 (172 bytes) */
int TParseContext__structQualifierErrorCheck(this, sourceLoc, publicType, scratchR6, scratchR7, scratchR8, scratchR9)
  unsigned char * this;
  int sourceLoc;
  unsigned char * publicType;
  undefined4 scratchR6;
  undefined4 scratchR7;
  undefined4 scratchR8;
  undefined4 scratchR9;
{
  int samplerErrorCheckResult;
  int qualifier;
  char *qualifierString;
  undefined4 result;
  undefined4 scratchR10;
  
  qualifier = *(int *)(publicType + 4);
  if ((qualifier - 3U < 3) && (*(int *)publicType == 0xe)) {
    qualifierString = (char *)getQualifierString(qualifier);
    error((int)this,(char *)sourceLoc,"cannot be used with a structure",qualifierString,"",scratchR8,scratchR9,
          scratchR10);
    result = 1;
  }
  else {
    if ((qualifier != 6) &&
       (samplerErrorCheckResult = ((int (*)())TParseContext__samplerErrorCheck)(this,sourceLoc,publicType,"samplers must be uniform"), samplerErrorCheckResult != 0)) {
      return 1;
    }
    result = 0;
  }
  return result;
}

/* TParseContext__parameterSamplerErrorCheck @ 0x97b9bd30 (184 bytes) */
int TParseContext__parameterSamplerErrorCheck(this, sourceLoc, qualifier, type)
  unsigned char * this;
  int sourceLoc;
  int qualifier;
  int *type;
{
  int basicType;
  char *basicString;
  undefined4 result;
  undefined4 scratchR8;
  undefined4 scratchR9;
  undefined4 scratchR10;
  
  if (((qualifier - 10U < 2) && (basicType = (**(code **)(*type + 0x20))(type), basicType != 0xe)) &&
     (basicType = (**(code **)(*type + 0x20))(type), basicType - 5U < 8)) {
    basicString = (char *)TType__getBasicString((uint)type[9] >> 0x13 & 0x3f);
    error((int)this,(char *)sourceLoc,"samplers cannot be output parameters",basicString,"",scratchR8,scratchR9,
          scratchR10);
    result = 1;
  }
  else {
    result = 0;
  }
  return result;
}

/* TParseContext__containsSampler @ 0x97b9bde8 (180 bytes) */
int TParseContext__containsSampler(this, type)
  unsigned char * this;
  unsigned char * type;
{
  int typeList;
  int basicType;
  undefined4 result;
  int fieldsBegin;
  uint fieldIndex;
  
  basicType = (**(code **)(*(int *)type + 0x20))(type,type);
  result = 1;
  if (7 < basicType - 5U) {
    basicType = (**(code **)(*(int *)type + 0x20))(type);
    if (basicType == 0xe) {
      typeList = *(int *)(type + 8);
      for (fieldIndex = 0; fieldsBegin = *(int *)(typeList + 4), fieldIndex < (uint)(*(int *)(typeList + 8) - fieldsBegin >> 3);
          fieldIndex = fieldIndex + 1) {
        fieldsBegin = ((int (*)())TParseContext__containsSampler)(this,*(unsigned char **)(fieldsBegin + fieldIndex * 8));
        if (fieldsBegin != 0) {
          return 1;
        }
      }
    }
    result = 0;
  }
  return result;
}

/* TParseContext__insertBuiltInArrayAtGlobalLevel @ 0x97b9be9c (740 bytes) */
int TParseContext__insertBuiltInArrayAtGlobalLevel(this)
  unsigned char * this;
{
  int typeWord1c;
  int nameChars;
  int uniqueId;
  int typeArraySize;
  int nameLength;
  int *refCountPtr;
  int newRefCount;
  int oldRefCount;
  uint typeSizeBits;
  uint typeQualifierBits;
  uint typeBasicTypeBits;
  uint typeMatrixBit;
  undefined *variableVtable;
  uint oldTypeBits;
  unsigned char * poolAllocator;
  void *newNameString;
  int *newVariable;
  unsigned char * variableNameRef;
  char *errorMessage;
  int foundTypeWord24;
  int foundTypeWord20;
  int foundTypeWord1c;
  int scratchR8;
  int levelsBegin;
  undefined4 scratchR10;
  int typeStructure;
  void *nameString;
  int levelIndex;
  int foundVariable;
  int typeWord20;
  undefined4 symbolTableLevel;
  int *symbolTable;
  char reservation;
  byte cr0Flags;
  undefined4 allocatorArg [4];
  int findResult [4];
  undefined4 insertResultFirst;
  int insertResultSecond;
  undefined4 mapInsertFirst;
  int mapInsertSecond;
  undefined4 nameCopy;
  int nameCopyChars;
  int *mapEntryVariable;
  undefined4 destroyAllocatorArg [5];
  
  poolAllocator = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
  newNameString = (void *)((int (*)())TPoolAllocator__allocate)(poolAllocator,8);
  cr0Flags = (newNameString == (void *)0x0) << 1;
  nameString = (void *)0x0;
  if (newNameString != (void *)0x0) {
    allocatorArg[0] = ((int (*)())GetGlobalPoolAllocator)();
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
              (newNameString,"gl_TexCoord",(unsigned char *)allocatorArg);
    nameString = newNameString;
  }
  symbolTable = *(int **)(this + 4);
  levelsBegin = *symbolTable;
  levelIndex = (symbolTable[1] - levelsBegin >> 2) + -1;
  while( true ) {
    levelsBegin = *(int *)(levelsBegin + levelIndex * 4);
    std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______find((unsigned char *)findResult,levelsBegin,nameString);
    foundVariable = 0;
    if (findResult[0] != *(int *)(levelsBegin + 4)) {
      foundVariable = *(int *)(findResult[0] + 0x18);
    }
    levelIndex = levelIndex + -1;
    if (foundVariable != 0) break;
    if (levelIndex < 0) {
      nameChars = *(int *)((int)nameString + 4);
      nameLength = *(int *)(nameChars + -0xc);
      cr0Flags = *stringTerminalPtr_a7b7ba18;
      errorMessage = "INTERNAL ERROR finding symbol";
loopStoreNameChars:
      *(byte *)(nameChars + nameLength) = cr0Flags;
      error((int)this,(char *)0x0,errorMessage,*(char **)((int)nameString + 4),"",scratchR8,(uint)cr0Flags,scratchR10);
      return 1;
    }
    levelsBegin = *symbolTable;
  }
  poolAllocator = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
  newVariable = (int *)((int (*)())TPoolAllocator__allocate)(poolAllocator,0x40);
  variableVtable = PTR_vtable_a7b7c0b4;
  newVariable[1] = (int)nameString;
  *newVariable = (int)(variableVtable + 8);
  scratchR8 = *(int *)(foundVariable + 0x18);
  foundTypeWord1c = *(int *)(foundVariable + 0x1c);
  foundTypeWord20 = *(int *)(foundVariable + 0x20);
  foundTypeWord24 = *(int *)(foundVariable + 0x24);
  typeWord1c = *(int *)(foundVariable + 0x28);
  typeArraySize = *(int *)(foundVariable + 0x10);
  typeStructure = *(int *)(foundVariable + 0x14);
  typeWord20 = *(int *)(foundVariable + 0x2c);
  newVariable[3] = (int)&PTR___ZN5TTypeD1Ev_a7b7d4d0;
  newVariable[6] = scratchR8;
  newVariable[7] = foundTypeWord1c;
  newVariable[8] = foundTypeWord20;
  newVariable[9] = foundTypeWord24;
  newVariable[10] = typeWord1c;
  newVariable[4] = typeArraySize;
  newVariable[5] = typeStructure;
  scratchR10 = 0;
  newVariable[0xb] = typeWord20;
  oldTypeBits = newVariable[0xc];
  typeQualifierBits = *(uint *)(foundVariable + 0x30) & 0xfe000000;
  newVariable[0xc] = typeQualifierBits | oldTypeBits & 0x1ffffff;
  typeBasicTypeBits = (*(uint *)(foundVariable + 0x30) >> 0x13 & 0x3f) << 0x13;
  newVariable[0xc] = typeBasicTypeBits | typeQualifierBits | oldTypeBits & 0x7ffff;
  typeSizeBits = *(uint *)(foundVariable + 0x30) & 0x7f800;
  newVariable[0xc] = typeSizeBits | typeBasicTypeBits | typeQualifierBits | oldTypeBits & 0x7ff;
  typeMatrixBit = (*(uint *)(foundVariable + 0x30) >> 10 & 1) << 10;
  newVariable[0xc] = typeMatrixBit | typeSizeBits | typeBasicTypeBits | typeQualifierBits | oldTypeBits & 0x3ff;
  newVariable[0xc] = (*(uint *)(foundVariable + 0x30) >> 9 & 1) << 9 | typeMatrixBit | typeSizeBits | typeBasicTypeBits | typeQualifierBits | oldTypeBits & 0x1ff
  ;
  newVariable[0xd] = 0;
  newVariable[0xe] = 0;
  newVariable[0xf] = 0;
  symbolTable = *(int **)(this + 4);
  uniqueId = symbolTable[3];
  symbolTable[3] = uniqueId + 1;
  newVariable[2] = uniqueId + 1;
  symbolTableLevel = *(undefined4 *)(*symbolTable + ((symbolTable[1] - *symbolTable & 0xfffffffcU) - 4));
  insertResultSecond = 0;
  variableNameRef = (unsigned char *)(**(code **)(*newVariable + 8))(newVariable,typeWord1c,foundTypeWord24,foundTypeWord20,foundTypeWord1c,scratchR8,symbolTable,0);
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&nameCopy,variableNameRef);
  mapEntryVariable = newVariable;
  std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&mapInsertFirst,symbolTableLevel,&nameCopy);
  insertResultFirst = mapInsertFirst;
  refCountPtr = (int *)(nameCopyChars + -4);
  insertResultSecond = mapInsertSecond;
  destroyAllocatorArg[0] = nameCopy;
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
              ((unsigned char *)(nameCopyChars + -0xc),destroyAllocatorArg);
  }
  if (insertResultSecond != 0) {
    return 0;
  }
  (**(code **)(*newVariable + 4))(newVariable);
  nameChars = *(int *)((int)nameString + 4);
  nameLength = *(int *)(nameChars + -0xc);
  cr0Flags = *stringTerminalPtr_a7b7ba18;
  errorMessage = "INTERNAL ERROR inserting new symbol";
  goto loopStoreNameChars;
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
  uint stackTypeBWord14;
  char *stackTypeBTypeName;
  char *stackTypeBFieldName;
  char *stackTypeBStructure;
  char *stackTypeBArraySize;
  undefined **stackTypeTypeNameOverlay;
  int arraySizeBasicType;
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
  int *refCountPtr;
  uint oldVariableBits;
  int oldRefCount;
  unsigned char * poolAllocator;
  void *this;
  unsigned char * nameStringRef;
  undefined **structTypeNameString;
  undefined4 lineCopy;
  undefined4 r4Out0;
  undefined4 passThroughR4;
  undefined4 lineCopy2;
  char *typeNameString;
  unsigned char * fwdR5;
  undefined4 fwdR6;
  uint scratchR7;
  uint scratchR8;
  int atomicStore;
  char *structTypeNameChars2;
  int currentLevel;
  int *existingSymbol;
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
  char *stackTypeWord14;
  char *stackTypeStructureSize;
  char *stackTypeWord1c;
  char *stackTypeWord20;
  uint stackTypeBits;
  undefined4 stackTypeBStructureSize;
  undefined4 stackTypeBWord1c;
  uint stackTypeBWord20;
  uint stackTypeBBits;
  uint ptCopySize;
  uint ptCopyMatrix;
  uint pt3CopyType;
  unsigned char * pt3CopyQualifier;
  uint pt3CopySize;
  uint pt3CopyMatrix;
  uint pt3CopyArray;
  unsigned char * pt3CopyUserDef;
  uint pt3CopyLine;
  uint pt2CopyMatrix;
  uint pt4CopyType;
  unsigned char * pt4CopyQualifier;
  uint pt4CopySize;
  uint pt4CopyMatrix;
  uint pt4CopyArray;
  unsigned char * pt4CopyUserDef;
  undefined4 pt4CopyLine;
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
         (arraySizeBasicType = (**(code **)(*arraySizeUnion + 0x40))(arraySizeUnion), arraySizeBasicType == 2)) && (0 < *(int *)arraySizeUnion[0xc])))
       ) {
      symbolTableLevels = *(int **)(parseContext + 4);
      sameScope = 0;
      builtIn = 0;
      levelsBegin = *symbolTableLevels;
      levelIndex = (symbolTableLevels[1] - levelsBegin >> 2) + -1;
      while( true ) {
        currentLevel = *(int *)(levelsBegin + levelIndex * 4);
        nameStringRef = text;
        std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______find((unsigned char *)levelFindResult,currentLevel,text);
        existingSymbol = (int *)0x0;
        if (levelFindResult[0] != *(int *)(currentLevel + 4)) {
          existingSymbol = *(int **)(levelFindResult[0] + 0x18);
        }
        if ((existingSymbol != (int *)0x0) || (levelIndex + -1 < 0)) break;
        levelsBegin = *symbolTableLevels;
        levelIndex = levelIndex + -1;
      }
      if (&STACKARG(0x0) != (undefined1 *)0x40) {
        builtIn = (uint)(levelIndex == 0);
      }
      if (&STACKARG(0x0) != (undefined1 *)0x3c) {
        sameScope = (uint)(levelIndex == (symbolTableLevels[1] - *symbolTableLevels >> 2) + -1);
      }
      if ((existingSymbol == (int *)0x0) || (sameScope == 0)) {
        stackTypeArraySize = (char *)TParseContext__reservedErrorCheck((unsigned char *)parseContext,(int)line,text);
        cr0Flags = (stackTypeArraySize == (char *)0x0) << 1;
        if (stackTypeArraySize != (char *)0x0) {
          return 1;
        }
        poolAllocator = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
        variableAllocation = ((int (*)())TPoolAllocator__allocate)(poolAllocator,0x40);
        newVariable = (int *)((ulonglong)variableAllocation >> 0x20);
        passThroughR4 = (undefined4)variableAllocation;
        stackTypeBits = ((*(uint *)((unsigned char *)ghidra_home + 28)) & 1) << 9 |
                    ((*(uint *)((unsigned char *)ghidra_home + 24)) & 1) << 10 |
                    ((*(uint *)((unsigned char *)ghidra_home + 20)) & 0xff) << 0xb |
                    ((*(uint *)((unsigned char *)ghidra_home + 12)) & 0x3f) << 0x13 | (*(uint *)((unsigned char *)ghidra_home + 16)) << 0x19 | stackTypeBits & 0x1ff;
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
        stackTypeStructureSize = (char *)0x0;
        fwdR5 = ptUserDef;
        fwdR6 = ptLine;
        scratchR8 = (*(uint *)((unsigned char *)ghidra_home + 16));
        ptSize = (*(uint *)((unsigned char *)ghidra_home + 20));
        stackTypeFieldName = stackTypeArraySize;
        structTypeName = (undefined **)0x0;
        stackTypeWord14 = stackTypeArraySize;
        stackTypeWord1c = stackTypeArraySize;
        stackTypeWord20 = stackTypeArraySize;
        if (ptUserDef != (unsigned char *)0x0) {
          stackTypeStructure = *(int *)(ptUserDef + 8);
          stackTypeTypeNameOverlay = (undefined **)stackTypeArraySize;
          stackTypeStructureSize = stackTypeArraySize;
          structSizeResult = TType__setStructSize((unsigned char *)&stackType,*(unsigned char **)(ptUserDef + 8));
          stackTypeStructureSize = (char *)((ulonglong)structSizeResult >> 0x20);
          structTypeNameStringRef = (**(code **)(*(int *)pt2CopyUserDef + 0x18))
                            (pt2CopyUserDef,(int)structSizeResult,fwdR5,fwdR6,scratchR8,ptSize,*(int *)pt2CopyUserDef);
          *(byte *)(*(int *)(structTypeNameStringRef + 4) + *(int *)(*(int *)(structTypeNameStringRef + 4) + -0xc)) = *stringTerminalPtr_a7b7ba18;
          structTypeNameChars = *(char **)(structTypeNameStringRef + 4);
          poolAllocator = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
          typeNameAllocation = ((int (*)())TPoolAllocator__allocate)(poolAllocator,8);
          structTypeNameString = (undefined **)((ulonglong)typeNameAllocation >> 0x20);
          passThroughR4 = (undefined4)typeNameAllocation;
          cr0Flags = (structTypeNameString == (undefined **)0x0) << 1;
          structTypeName = (undefined **)0x0;
          if (structTypeNameString != (undefined **)0x0) {
            poolAllocatorArg1[0] = ((int (*)())GetGlobalPoolAllocator)();
            fwdR5 = (unsigned char *)poolAllocatorArg1;
            __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_(structTypeNameString,structTypeNameChars,fwdR5);
            passThroughR4 = r4Out0;
            structTypeName = structTypeNameString;
          }
        }
        stackTypeTypeNameOverlay = structTypeName;
        newVariable[1] = (int)text;
        ptArray = 0;
        *newVariable = (int)(PTR_vtable_a7b7c0b4 + 8);
        newVariable[4] = (int)stackTypeArraySize;
        newVariable[5] = stackTypeStructure;
        newVariable[6] = (int)stackTypeFieldName;
        newVariable[7] = (int)stackTypeTypeNameOverlay;
        newVariable[8] = (int)stackTypeWord14;
        newVariable[9] = (int)stackTypeStructureSize;
        newVariable[3] = (int)&PTR___ZN5TTypeD1Ev_a7b7d4d0;
        newVariable[10] = (int)stackTypeWord1c;
        newVariable[0xb] = (int)stackTypeWord20;
        oldVariableBits = newVariable[0xc];
        qualifierField = stackTypeBits & 0xfe000000;
        newVariable[0xc] = qualifierField | oldVariableBits & 0x1ffffff;
        basicTypeField = (stackTypeBits >> 0x13 & 0x3f) << 0x13;
        newVariable[0xc] = basicTypeField | qualifierField | oldVariableBits & 0x7ffff;
        sizeField = stackTypeBits & 0x7f800;
        newVariable[0xc] = sizeField | basicTypeField | qualifierField | oldVariableBits & 0x7ff;
        matrixField = (stackTypeBits >> 10 & 1) << 10;
        newVariable[0xc] = matrixField | sizeField | basicTypeField | qualifierField | oldVariableBits & 0x3ff;
        newVariable[0xc] = (stackTypeBits >> 9 & 1) << 9 | matrixField | sizeField | basicTypeField | qualifierField | oldVariableBits & 0x1ff;
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
        variableNameString = (unsigned char *)(**(code **)(*newVariable + 8))(newVariable,passThroughR4,fwdR5,fwdR6,scratchR8,ptSize,symbolTable);
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&nameCopy,variableNameString);
        variableForInsert = newVariable;
        std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&stackTypeTypeNameOverlay,symbolTableLevel,&nameCopy);
        stackType = stackTypeTypeNameOverlay;
        refCountPtr = (int *)(nameCopyChars + -4);
        stackTypeArraySize = stackTypeWord14;
        destroyAllocator1[0] = nameCopy;
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
                    ((unsigned char *)(nameCopyChars + -0xc),destroyAllocator1);
        }
        if (stackTypeArraySize != (char *)0x0) {
loopSetVoidErrorResult:
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
        stringTerminator = (uint)*stringTerminalPtr_a7b7ba18;
        errorReason = "INTERNAL ERROR inserting new symbol";
      }
      else {
        isVariable = (**(code **)(*existingSymbol + 0x10))(existingSymbol,lineCopy,nameStringRef,publicType,intermTyped,ptSize,levelsBegin);
        if (isVariable == 0) {
          identifierChars = *(int *)(text + 4);
          identifierLength = *(int *)(identifierChars + -0xc);
          stringTerminator = (uint)*stringTerminalPtr_a7b7ba18;
          errorReason = "variable expected";
        }
        else {
          isArray = (**(code **)(existingSymbol[3] + 0x38))(existingSymbol + 3,lineCopy2,nameStringRef,publicType,intermTyped,ptSize,levelsBegin);
          if (isArray == 0) {
            identifierChars = *(int *)(text + 4);
            identifierLength = *(int *)(identifierChars + -0xc);
            stringTerminator = (uint)*stringTerminalPtr_a7b7ba18;
            errorReason = "redeclaring non-array as array";
          }
          else if (existingSymbol[4] < 1) {
            stackTypeBits = ((*(uint *)((unsigned char *)ghidra_home + 28)) & 1) << 9 |
                        ((*(uint *)((unsigned char *)ghidra_home + 24)) & 1) << 10 |
                        ((*(uint *)((unsigned char *)ghidra_home + 20)) & 0xff) << 0xb |
                        ((*(uint *)((unsigned char *)ghidra_home + 12)) & 0x3f) << 0x13 | (*(uint *)((unsigned char *)ghidra_home + 16)) << 0x19 | stackTypeBits & 0x1ff
            ;
            pt2CopyLine = ptLine;
            stackType = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
            stackTypeWord20 = (char *)0x0;
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
            stackTypeTypeNameOverlay = (undefined **)0x0;
            stackTypeWord14 = (char *)0x0;
            stackTypeStructureSize = (char *)0x0;
            stackTypeWord1c = (char *)0x0;
            ptSize = (*(uint *)((unsigned char *)ghidra_home + 24));
            ptArray = (*(uint *)((unsigned char *)ghidra_home + 12));
            structTypeName = stackTypeTypeNameOverlay;
            if (ptUserDef != (unsigned char *)0x0) {
              stackTypeStructure = *(int *)(ptUserDef + 8);
              passThroughR4 = ptLine;
              scratchR8 = (*(uint *)((unsigned char *)ghidra_home + 20));
              scratchR7 = (*(uint *)((unsigned char *)ghidra_home + 16));
              structSizeResult = TType__setStructSize((unsigned char *)&stackType,*(unsigned char **)(ptUserDef + 8));
              stackTypeStructureSize = (char *)((ulonglong)structSizeResult >> 0x20);
              structTypeNameStringRef = (**(code **)(*(int *)pt2CopyUserDef + 0x18))
                                (pt2CopyUserDef,(int)structSizeResult,passThroughR4,scratchR8,scratchR7,ptSize,*(int *)pt2CopyUserDef)
              ;
              *(byte *)(*(int *)(structTypeNameStringRef + 4) + *(int *)(*(int *)(structTypeNameStringRef + 4) + -0xc)) = *stringTerminalPtr_a7b7ba18;
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
            stackTypeTypeNameOverlay = structTypeName;
            typesMatch = false;
            if (((existingSymbol[0xc] & 0x1fffe00U) == (stackTypeBits & 0x1fffe00)) && (existingSymbol[5] == stackTypeStructure)) {
              typesMatch = true;
            }
            stackType = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
            if (typesMatch) {
              for (redeclaredArrayNode = existingSymbol[0xf]; redeclaredArrayNode != 0; redeclaredArrayNode = *(int *)(redeclaredArrayNode + 0x20)) {
                if (*(int *)arraySizeUnion[0xc] < *(int *)(redeclaredArrayNode + 0x1c)) {
                  identifierChars = *(int *)(text + 4);
                  identifierLength = *(int *)(identifierChars + -0xc);
                  stringTerminator = (uint)*stringTerminalPtr_a7b7ba18;
                  errorReason = "higher index value already used for the array";
                  goto storeIdentifierChars;
                }
                *(int *)(redeclaredArrayNode + 4) = *(int *)arraySizeUnion[0xc];
                *(uint *)(redeclaredArrayNode + 0x24) = *(uint *)(redeclaredArrayNode + 0x24) | 0x200;
              }
              if (!noArraySizeNode) {
                existingSymbol[4] = *(int *)arraySizeUnion[0xc];
                existingSymbol[0xc] = existingSymbol[0xc] | 0x200;
              }
              goto loopSetVoidErrorResult;
            }
            identifierChars = *(int *)(text + 4);
            identifierLength = *(int *)(identifierChars + -0xc);
            stringTerminator = (uint)*stringTerminalPtr_a7b7ba18;
            errorReason = "redeclaration of array with a different type";
          }
          else {
            identifierChars = *(int *)(text + 4);
            identifierLength = *(int *)(identifierChars + -0xc);
            stringTerminator = (uint)*stringTerminalPtr_a7b7ba18;
            errorReason = "redeclaration of array with size";
          }
        }
      }
    }
    else {
      identifierChars = *(int *)(text + 4);
      identifierLength = *(int *)(identifierChars + -0xc);
      stringTerminator = (uint)*stringTerminalPtr_a7b7ba18;
      errorReason = "array size must be a positive integer";
    }
storeIdentifierChars:
    *(char *)(identifierChars + identifierLength) = (char)stringTerminator;
    error(parseContext,(char *)line,errorReason,*(char **)(text + 4),"",ptSize,stringTerminator,ptArray);
  }
  else {
    stackTypeBBits = (ptArray & 1) << 9 |
               (ptMatrix & 1) << 10 |
               (ptSize & 0xff) << 0xb |
               (publicType & 0x3f) << 0x13 | intermTyped << 0x19 | stackTypeBBits & 0x1ff;
    pt4CopyLine = ptLine;
    stackTypeTypeNameOverlay = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
    stackTypeBTypeName = (void *)0x0;
    stackTypeBWord20 = 0;
    pt3CopyUserDef = ptUserDef;
    pt3CopyLine = ptLine;
    pt4CopyUserDef = ptUserDef;
    stackTypeBArraySize = (char *)0x0;
    stackTypeBStructure = (char *)0x0;
    stackTypeBFieldName = (char *)0x0;
    stackTypeBWord14 = 0;
    stackTypeBStructureSize = 0;
    stackTypeBWord1c = 0;
    (*(uint *)((unsigned char *)ghidra_home + 28)) = ptArray;
    typeNameString = stackTypeBTypeName;
    pt3CopyType = publicType;
    pt3CopyQualifier = (unsigned char *)intermTyped;
    pt3CopySize = ptSize;
    pt3CopyMatrix = ptMatrix;
    pt3CopyArray = ptArray;
    pt4CopyType = publicType;
    pt4CopyQualifier = (unsigned char *)intermTyped;
    pt4CopySize = ptSize;
    pt4CopyMatrix = ptMatrix;
    pt4CopyArray = ptArray;
    if (ptUserDef != (unsigned char *)0x0) {
      stackTypeBStructure = *(char **)(ptUserDef + 8);
      passThroughR4 = ptLine;
      structSizeResult = TType__setStructSize((unsigned char *)&stackTypeTypeNameOverlay,*(unsigned char **)(ptUserDef + 8));
      stackTypeBStructureSize = (undefined4)((ulonglong)structSizeResult >> 0x20);
      structTypeNameStringRef = (**(code **)(*(int *)pt4CopyUserDef + 0x18))
                        (pt4CopyUserDef,(int)structSizeResult,passThroughR4,intermTyped,ptSize,publicType,*(int *)pt4CopyUserDef);
      *(byte *)(*(int *)(structTypeNameStringRef + 4) + *(int *)(*(int *)(structTypeNameStringRef + 4) + -0xc)) = *stringTerminalPtr_a7b7ba18;
      structTypeNameChars2 = *(char **)(structTypeNameStringRef + 4);
      poolAllocator = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
      this = (void *)((int (*)())TPoolAllocator__allocate)(poolAllocator,8);
      cr0Reg = (this == (void *)0x0) << 1;
      typeNameString = (void *)0x0;
      if (this != (void *)0x0) {
        destroyAllocator2[0] = ((int (*)())GetGlobalPoolAllocator)();
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                  (this,structTypeNameChars2,(unsigned char *)destroyAllocator2);
        typeNameString = this;
      }
    }
    stackTypeBTypeName = typeNameString;
    TType__getCompleteString(&stackType,(unsigned char *)&stackTypeTypeNameOverlay);
    stackTypeArraySize[*(int *)(stackTypeArraySize + -0xc)] = *stringTerminalPtr_a7b7ba18;
    error(parseContext,(char *)line,"cannot declare arrays of this type",stackTypeArraySize,"",publicType,
          stackTypeArraySize,ptMatrix);
    refCountPtr = (int *)(stackTypeArraySize + -4);
    destroyAllocator3[0] = stackType;
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
                ((unsigned char *)(stackTypeArraySize + -0xc),destroyAllocator3);
    }
  }
  return 1;
}

/* TParseContext__arraySetMaxSize @ 0x97b9cb78 (600 bytes) */
int TParseContext__arraySetMaxSize(this, intermSymbol, type, maxSize, updateFlag, line)
  unsigned char * this;
  unsigned char * intermSymbol;
  unsigned char * type;
  int maxSize;
  int updateFlag;
  int line;
{
  int undeclaredNameRef;
  int atomicStore;
  int lookedUpVariable;
  int levelsBegin2;
  int newArraySize;
  int foundVariable;
  uint lineInString;
  void *infoSink;
  int *constArray;
  int componentCount;
  int levelIndex2;
  int nextType;
  int compareResult;
  int levelIndex;
  int *refCountPtr;
  int newRefCount;
  int oldRefCount;
  uint variableTypeBits;
  undefined4 firstSymbolNameRef;
  void *symbolNameString;
  int lineCopy;
  unsigned char * poolAllocator;
  int levelsBegin;
  undefined4 scratchR10;
  int *symbolTable;
  int level;
  char reservation;
  byte cr0Reg;
  byte cr0Flags;
  int findResult [4];
  char *maxTexCoordsName;
  int maxTexCoordsNameChars;
  undefined4 allocatorArg [4];
  char *destroyAllocatorArg [4];
  char locTextBuf [64];
  unsigned char allocatorDummy [16];
  uint builtIn;
  
  builtIn = 0;
  symbolTable = *(int **)(this + 4);
  lineCopy = line;
  firstSymbolNameRef = (**(code **)(*(int *)intermSymbol + 0x60))(intermSymbol,intermSymbol,type,maxSize,updateFlag,line);
  levelsBegin = *symbolTable;
  levelIndex = (symbolTable[1] - levelsBegin >> 2) + -1;
  while( true ) {
    level = *(int *)(levelsBegin + levelIndex * 4);
    foundVariable = 0;
    std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______find((unsigned char *)findResult,level,firstSymbolNameRef);
    if (findResult[0] != *(int *)(level + 4)) {
      foundVariable = *(int *)(findResult[0] + 0x18);
    }
    if ((foundVariable != 0) || (levelIndex + -1 < 0)) break;
    levelsBegin = *symbolTable;
    levelIndex = levelIndex + -1;
  }
  if (&STACKARG(0x0) != (undefined1 *)0x50) {
    builtIn = (uint)(levelIndex == 0);
  }
  if (foundVariable != 0) {
    *(undefined4 *)(type + 0x20) = *(undefined4 *)(foundVariable + 0x3c);
    *(unsigned char **)(foundVariable + 0x3c) = type;
    symbolNameString = (void *)(**(code **)(*(int *)intermSymbol + 0x60))(intermSymbol);
    compareResult = __ZNKSbIcSt11char_traitsIcE14pool_allocatorIcEE7compareEPKc(symbolNameString,"gl_TexCoord");
    if (compareResult != 0) {
loopCheckUpdateFlag:
      if (updateFlag == 0) {
        return 0;
      }
      nextType = *(int *)(type + 0x20);
      newArraySize = maxSize + 1;
      *(int *)(foundVariable + 0x28) = newArraySize;
      *(int *)(type + 0x1c) = newArraySize;
      while (nextType != 0) {
        *(int *)(nextType + 0x1c) = newArraySize;
        nextType = *(int *)(nextType + 0x20);
      }
      return 0;
    }
    symbolTable = *(int **)(this + 4);
    allocatorArg[0] = ((int (*)())GetGlobalPoolAllocator)();
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
              (&maxTexCoordsName,"gl_MaxTextureCoords",(unsigned char *)allocatorArg);
    levelsBegin2 = *symbolTable;
    levelIndex2 = (symbolTable[1] - levelsBegin2 >> 2) + -1;
    while( true ) {
      level = *(int *)(levelsBegin2 + levelIndex2 * 4);
      lookedUpVariable = 0;
      std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______find((unsigned char *)findResult,level,&maxTexCoordsName);
      if (findResult[0] != *(int *)(level + 4)) {
        lookedUpVariable = *(int *)(findResult[0] + 0x18);
      }
      if ((lookedUpVariable != 0) || (levelIndex2 + -1 < 0)) break;
      levelsBegin2 = *symbolTable;
      levelIndex2 = levelIndex2 + -1;
    }
    if (&STACKARG(0x0) != (undefined1 *)0x50) {
      builtIn = (uint)(levelIndex2 == 0);
    }
    refCountPtr = (int *)(maxTexCoordsNameChars + -4);
    destroyAllocatorArg[0] = maxTexCoordsName;
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
                ((unsigned char *)(maxTexCoordsNameChars + -0xc),destroyAllocatorArg);
    }
    if (lookedUpVariable != 0) {
      constArray = *(int **)(lookedUpVariable + 0x38);
      if (constArray == (int *)0x0) {
        if (*(int *)(lookedUpVariable + 0x14) == 0) {
          variableTypeBits = *(uint *)(lookedUpVariable + 0x30);
          if ((variableTypeBits & 0x400) == 0) {
            componentCount = (int)(variableTypeBits << 0xd | variableTypeBits >> 0x13) >> 0x18;
          }
          else {
            componentCount = (int)(variableTypeBits << 0xd | variableTypeBits >> 0x13) >> 0x18;
            componentCount = componentCount * componentCount;
          }
        }
        else {
          componentCount = *(int *)(lookedUpVariable + 0x24);
        }
        poolAllocator = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
        constArray = (int *)((int (*)())TPoolAllocator__allocate)(poolAllocator,componentCount << 2);
        *(int **)(lookedUpVariable + 0x38) = constArray;
      }
      if (maxSize < *constArray) goto loopCheckUpdateFlag;
      error((int)this,(char *)line,"","[",
            "gl_TexCoord can only have a max array size of up to gl_MaxTextureCoords","",maxTexCoordsNameChars,
            scratchR10);
    }
    else {
      infoSink = *(void **)(this + 8);
                    
      __ZN13TInfoSinkBase6appendEPKc(infoSink,"INTERNAL ERROR: ");
      lineInString = line & 0xffff;
      cr0Flags = (lineInString == 0) << 1;
      if (lineInString == 0) {
        _sprintf(locTextBuf,"%d:? ",line >> 0x10);
      }
      else {
        _sprintf(locTextBuf,"%d:%d",line >> 0x10,lineInString);
      }
      __ZNSsC1EPKcRKSaIcE(&maxTexCoordsName,locTextBuf,allocatorDummy);
      maxTexCoordsName[*(int *)(maxTexCoordsName + -0xc)] = *PTR__S_terminal_a7b7c0b8;
      __ZN13TInfoSinkBase6appendEPKc(infoSink,maxTexCoordsName);
      refCountPtr = (int *)(maxTexCoordsName + -4);
      do {
        oldRefCount = *refCountPtr;
        if (reservation != '\0') {
          atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
          *refCountPtr = atomicStore;
          cr0Flags = 2;
        }
      } while (!(bool)(cr0Flags >> 1 & 1));
      if (oldRefCount < 1) {
        __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(maxTexCoordsName + -0xc),locTextBuf);
      }
      __ZN13TInfoSinkBase6appendEPKc(infoSink,": ");
      __ZN13TInfoSinkBase6appendEPKc(infoSink,"gl_MaxTextureCoords not defined");
      __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
    }
  }
  else {
    undeclaredNameRef = (**(code **)(*(int *)intermSymbol + 0x60))(intermSymbol);
    cr0Flags = *stringTerminalPtr_a7b7ba18;
    *(byte *)(*(int *)(undeclaredNameRef + 4) + *(int *)(*(int *)(undeclaredNameRef + 4) + -0xc)) = cr0Flags;
    error((int)this,(char *)line," undeclared identifier",*(char **)(undeclaredNameRef + 4),"",lineCopy,
          (uint)cr0Flags,scratchR10);
  }
  return 1;
}

/* TParseContext__nonInitErrorCheck @ 0x97b9cfe8 (1008 bytes) */
int TParseContext__nonInitErrorCheck(this, sourceLoc, text, publicType)
  unsigned char * this;
  int sourceLoc;
  unsigned char * text;
  unsigned char * publicType;
{
  undefined8 typeNameAllocation;
  int existingNameRef;
  int levelsBegin;
  int uniqueId;
  int *refCountPtr;
  int oldRefCount;
  int voidErrorCheckResult;
  int reservedErrorCheckResult;
  byte terminalChar;
  int atomicStore;
  uint typeSizeBits;
  uint typeQualifierBits;
  uint typeBasicTypeBits;
  uint typeMatrixBit;
  void *typeNameString;
  uint oldTypeBits;
  int declQualifier;
  unsigned char * poolAllocator;
  int *newVariable;
  int structTypeNameRef;
  void *newTypeNameString;
  unsigned char * variableNameRef;
  undefined4 r4Out0;
  undefined4 staleR4;
  unsigned char * fwdR5;
  int ptQualifier;
  uint ptSize;
  uint ptType;
  int *symbolTable;
  char *structTypeNameChars;
  undefined4 symbolTableLevel;
  char reservation;
  byte cr0Reg;
  undefined8 structSizeResult;
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
  uint ptCopy1Type;
  int ptCopy1Qualifier;
  uint ptCopy1Size;
  uint ptCopy1Matrix;
  uint ptCopy1Array;
  int *ptCopy1UserDef;
  unsigned char * ptCopy1Line;
  uint ptCopy2Type;
  int ptCopy2Qualifier;
  uint ptCopy2Size;
  uint ptCopy2Matrix;
  uint ptCopy2Array;
  int *ptCopy2UserDef;
  unsigned char * ptCopy2Line;
  undefined4 allocatorArg [4];
  undefined4 nameCopy;
  int nameCopyChars;
  int *mapEntryVariable;
  undefined4 destroyAllocatorArg [5];
  
  reservedErrorCheckResult = TParseContext__reservedErrorCheck(this,sourceLoc,text);
  if (reservedErrorCheckResult != 0) {
    TParseContext__recover(this);
  }
  declQualifier = *(int *)(publicType + 4);
  if (declQualifier == 2) {
    *(undefined4 *)(publicType + 4) = 0;
  }
  poolAllocator = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
  newVariable = (int *)((int (*)())TPoolAllocator__allocate)(poolAllocator,0x40);
  ptCopy1UserDef = *(int **)(publicType + 0x14);
  ptQualifier = *(int *)(publicType + 4);
  ptType = *(uint *)publicType;
  ptSize = *(uint *)(publicType + 8);
  ptCopy1Matrix = *(uint *)(publicType + 0xc);
  ptCopy1Array = *(uint *)(publicType + 0x10);
  fwdR5 = *(unsigned char **)(publicType + 0x18);
  stackTypeBits = (ptCopy1Array & 1) << 9 |
             (ptCopy1Matrix & 1) << 10 |
             (ptSize & 0xff) << 0xb | (ptType & 0x3f) << 0x13 | ptQualifier << 0x19 | stackTypeBits & 0x1ff;
  stackType = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  stackTypeWord20 = 0;
  stackTypeArraySize = 0;
  stackTypeStructure = 0;
  stackTypeFieldName = 0;
  stackTypeTypeName = (void *)0x0;
  stackTypeWord14 = 0;
  stackTypeStructureSize = 0;
  stackTypeWord1c = 0;
  staleR4 = 0;
  typeNameString = stackTypeTypeName;
  ptCopy1Type = ptType;
  ptCopy1Qualifier = ptQualifier;
  ptCopy1Size = ptSize;
  ptCopy1Line = fwdR5;
  ptCopy2Type = ptType;
  ptCopy2Qualifier = ptQualifier;
  ptCopy2Size = ptSize;
  ptCopy2Matrix = ptCopy1Matrix;
  ptCopy2Array = ptCopy1Array;
  ptCopy2UserDef = ptCopy1UserDef;
  ptCopy2Line = fwdR5;
  if (ptCopy1UserDef != (int *)0x0) {
    stackTypeStructure = ptCopy1UserDef[2];
    structSizeResult = TType__setStructSize((unsigned char *)&stackType,(unsigned char *)ptCopy1UserDef[2]);
    stackTypeStructureSize = (int)((ulonglong)structSizeResult >> 0x20);
    structTypeNameRef = (**(code **)(*ptCopy2UserDef + 0x18))(ptCopy2UserDef,(int)structSizeResult,fwdR5,ptQualifier,ptSize,ptType,*ptCopy2UserDef);
    *(byte *)(*(int *)(structTypeNameRef + 4) + *(int *)(*(int *)(structTypeNameRef + 4) + -0xc)) = *stringTerminalPtr_a7b7ba18;
    structTypeNameChars = *(char **)(structTypeNameRef + 4);
    poolAllocator = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
    typeNameAllocation = ((int (*)())TPoolAllocator__allocate)(poolAllocator,8);
    newTypeNameString = (void *)((ulonglong)typeNameAllocation >> 0x20);
    staleR4 = (undefined4)typeNameAllocation;
    cr0Reg = (newTypeNameString == (void *)0x0) << 1;
    typeNameString = (void *)0x0;
    if (newTypeNameString != (void *)0x0) {
      allocatorArg[0] = ((int (*)())GetGlobalPoolAllocator)();
      fwdR5 = (unsigned char *)allocatorArg;
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_(newTypeNameString,structTypeNameChars,fwdR5);
      staleR4 = r4Out0;
      typeNameString = newTypeNameString;
    }
  }
  stackTypeTypeName = typeNameString;
  newVariable[1] = (int)text;
  *newVariable = (int)(PTR_vtable_a7b7c0b4 + 8);
  newVariable[4] = stackTypeArraySize;
  newVariable[5] = stackTypeStructure;
  newVariable[6] = stackTypeFieldName;
  newVariable[7] = (int)stackTypeTypeName;
  newVariable[8] = stackTypeWord14;
  newVariable[9] = stackTypeStructureSize;
  newVariable[3] = (int)&PTR___ZN5TTypeD1Ev_a7b7d4d0;
  newVariable[10] = stackTypeWord1c;
  newVariable[0xb] = stackTypeWord20;
  oldTypeBits = newVariable[0xc];
  typeQualifierBits = stackTypeBits & 0xfe000000;
  newVariable[0xc] = typeQualifierBits | oldTypeBits & 0x1ffffff;
  typeBasicTypeBits = (stackTypeBits >> 0x13 & 0x3f) << 0x13;
  newVariable[0xc] = typeBasicTypeBits | typeQualifierBits | oldTypeBits & 0x7ffff;
  typeSizeBits = stackTypeBits & 0x7f800;
  newVariable[0xc] = typeSizeBits | typeBasicTypeBits | typeQualifierBits | oldTypeBits & 0x7ff;
  typeMatrixBit = (stackTypeBits >> 10 & 1) << 10;
  newVariable[0xc] = typeMatrixBit | typeSizeBits | typeBasicTypeBits | typeQualifierBits | oldTypeBits & 0x3ff;
  newVariable[0xc] = (stackTypeBits >> 9 & 1) << 9 | typeMatrixBit | typeSizeBits | typeBasicTypeBits | typeQualifierBits | oldTypeBits & 0x1ff;
  newVariable[0xd] = 0;
  newVariable[0xe] = 0;
  newVariable[0xf] = 0;
  symbolTable = *(int **)(this + 4);
  stackType = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  uniqueId = symbolTable[3];
  symbolTable[3] = uniqueId + 1;
  newVariable[2] = uniqueId + 1;
  levelsBegin = *symbolTable;
  symbolTableLevel = *(undefined4 *)(levelsBegin + ((symbolTable[1] - levelsBegin & 0xfffffffcU) - 4));
  stackTypeArraySize = 0;
  variableNameRef = (unsigned char *)(**(code **)(*newVariable + 8))(newVariable,staleR4,fwdR5,ptQualifier,ptSize,ptType,symbolTable,levelsBegin);
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&nameCopy,variableNameRef);
  mapEntryVariable = newVariable;
  std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&stackTypeTypeName,symbolTableLevel,&nameCopy);
  stackType = stackTypeTypeName;
  refCountPtr = (int *)(nameCopyChars + -4);
  stackTypeArraySize = stackTypeWord14;
  destroyAllocatorArg[0] = nameCopy;
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
              ((unsigned char *)(nameCopyChars + -0xc),destroyAllocatorArg);
  }
  if (stackTypeArraySize == 0) {
    existingNameRef = newVariable[1];
    terminalChar = *stringTerminalPtr_a7b7ba18;
    *(byte *)(*(int *)(existingNameRef + 4) + *(int *)(*(int *)(existingNameRef + 4) + -0xc)) = terminalChar;
    error((int)this,(char *)sourceLoc,"redefinition",*(char **)(existingNameRef + 4),"",ptType,(uint)terminalChar,existingNameRef);
    if (newVariable != (int *)0x0) {
      (**(code **)(*newVariable + 4))(newVariable);
    }
  }
  else {
    if (declQualifier != 2) {
      voidErrorCheckResult = TParseContext__voidErrorCheck(this,sourceLoc,text,publicType);
      return voidErrorCheckResult != 0;
    }
    terminalChar = *stringTerminalPtr_a7b7ba18;
    *(byte *)(*(int *)(text + 4) + *(int *)(*(int *)(text + 4) + -0xc)) = terminalChar;
    error((int)this,(char *)sourceLoc,"variables with qualifier \'const\' must be initialized",
          *(char **)(text + 4),"",ptType,(uint)terminalChar,levelsBegin);
  }
  return true;
}

/* TParseContext__paramErrorCheck @ 0x97b9d3d8 (216 bytes) */
int TParseContext__paramErrorCheck(this, sourceLoc, qualifier1, qualifier2, type)
  unsigned char * this;
  int sourceLoc;
  int qualifier1;
  int qualifier2;
  int *type;
{
  int typeVtable;
  char *qualifierString;
  char *errorReason;
  char *qualifier2String;
  undefined4 scratchR8;
  undefined4 scratchR9;
  undefined4 scratchR10;
  
  if (qualifier1 == 2) {
    if (qualifier2 == 9) {
      typeVtable = *type;
      qualifier2 = 0xc;
      goto callTypeVirtual28;
    }
    qualifierString = (char *)getQualifierString(2);
    qualifier2String = (char *)getQualifierString(qualifier2);
    errorReason = "qualifier not allowed with ";
  }
  else {
    if (qualifier1 == 0) {
      typeVtable = *type;
callTypeVirtual28:
      (**(code **)(typeVtable + 0x28))(type,qualifier2);
      return 0;
    }
    qualifierString = (char *)getQualifierString(qualifier1);
    errorReason = "qualifier not allowed on function parameter";
    qualifier2String = "";
  }
  error((int)this,(char *)sourceLoc,errorReason,qualifierString,qualifier2String,scratchR8,scratchR9,scratchR10);
  return 1;
}

/* TParseContext__extensionErrorCheck @ 0x97b9d4b0 (532 bytes) */
int TParseContext__extensionErrorCheck(this, sourceLoc, str)
  unsigned char * this;
  int sourceLoc;
  char *str;
{
  int oldRefCount;
  int newRefCount;
  int extBehavior;
  uint lineInString;
  int oldRefCount2;
  int mapNode;
  int atomicStore;
  bool isDisabled;
  int atomicStore2;
  char *messageChars;
  int *refCountPtr;
  int compareResult;
  ulong length;
  uint *minLengthPtr;
  undefined4 scratchR8;
  undefined4 scratchR10;
  unsigned char * behaviorMap;
  void *infoSink;
  uint nodeKeyLength;
  uint keyLength;
  char reservation;
  byte cr0Reg;
  byte cr0Flags;
  undefined4 extensionKey;
  int extensionKeyChars;
  int allocatorOverlay [4];
  int mapIterOverlay;
  char *msgChars;
  int mapEndOverlay;
  int msgPrefixChars;
  int insertIterator [4];
  int insertHintCopy [4];
  undefined4 entryKey;
  int entryKeyChars;
  undefined4 entryBehavior;
  int insertHint [4];
  undefined4 entryKeyDestroyArg [4];
  undefined4 keyDestroyArg [4];
  undefined4 strCopy;
  int strCopyChars;
  undefined4 allocatorArg2 [4];
  char *locString [4];
  char locTextBuf [64];
  unsigned char allocatorDummy [16];
  int msgDestroyArg [4];
  int msgPrefixDestroyArg [4];
  undefined4 strCopyDestroyArg [4];
  undefined4 allocatorArg3 [4];
  undefined4 entryKey2;
  int entryKey2Chars;
  undefined4 entryBehavior2;
  undefined4 entryKey2DestroyArg [4];
  undefined4 keyDestroyArg2 [4];
  uint lenKeyA;
  uint lenNodeA;
  uint lenKeyB;
  uint lenNodeB;
  
  allocatorOverlay[0] = ((int (*)())GetGlobalPoolAllocator)();
  behaviorMap = this + 0x30;
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
            ((unsigned char *)&extensionKey,str,(unsigned char *)allocatorOverlay);
  std___Rb_tree_std__string_std__pair_std__string_const_TBehavior__std___Select1st_std__pair_std__string_const_TBehavior___std__less_std__string__pool_allocator_std__pair_std__string_const_TBehavior_____lower_bound((unsigned char *)&mapIterOverlay,behaviorMap,(unsigned char *)&extensionKey);
  mapNode = mapIterOverlay;
  mapEndOverlay = *(int *)(this + 0x34);
  if (mapIterOverlay == mapEndOverlay) {
loopStoreInsertHintCopy:
    insertHintCopy[0] = mapNode;
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&entryKey,(unsigned char *)&extensionKey);
    entryBehavior = 0;
    insertHint[0] = insertHintCopy[0];
    __ZNSt8_Rb_treeISbIcSt11char_traitsIcE14pool_allocatorIcEESt4pairIKS4_9TBehaviorESt10_Select1stIS8_ESt4lessIS4_ES2_IS8_EE13insert_uniqueESt17_Rb_tree_iteratorIS8_RS8_PS8_ERKS8_
              (insertIterator,behaviorMap,insertHint,&entryKey);
    refCountPtr = (int *)(entryKeyChars + -4);
    mapIterOverlay = insertIterator[0];
    entryKeyDestroyArg[0] = entryKey;
    do {
      oldRefCount2 = *refCountPtr;
      if (reservation != '\0') {
        newRefCount = storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *refCountPtr = newRefCount;
        cr0Reg = 2;
      }
    } while (!(bool)(cr0Reg >> 1 & 1));
    mapNode = insertIterator[0];
    if (oldRefCount2 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(entryKeyChars + -0xc),entryKeyDestroyArg);
      mapNode = mapIterOverlay;
    }
  }
  else {
    minLengthPtr = &lenNodeA;
    keyLength = *(uint *)(extensionKeyChars + -0xc);
    lenKeyA = keyLength;
    nodeKeyLength = *(uint *)(*(int *)(mapIterOverlay + 0x14) + -0xc);
    lenNodeA = nodeKeyLength;
    if (keyLength <= nodeKeyLength) {
      minLengthPtr = &lenKeyA;
    }
    compareResult = _memcmp(extensionKeyChars,*(undefined4 *)(mapIterOverlay + 0x14),*minLengthPtr);
    cr0Reg = (compareResult == 0) << 1;
    if (compareResult == 0) {
      compareResult = keyLength - nodeKeyLength;
    }
    if (compareResult < 0) goto loopStoreInsertHintCopy;
  }
  extBehavior = *(int *)(mapNode + 0x18);
  refCountPtr = (int *)(extensionKeyChars + -4);
  keyDestroyArg[0] = extensionKey;
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
              ((unsigned char *)(extensionKeyChars + -0xc),keyDestroyArg);
  }
  if (extBehavior == 2) {
    infoSink = *(void **)(this + 8);
    allocatorArg2[0] = ((int (*)())GetGlobalPoolAllocator)();
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
              (&strCopy,str,(unsigned char *)allocatorArg2);
    __ZStplIcSt11char_traitsIcE14pool_allocatorIcEESbIT_T0_T1_EPKS4_RKS7_
              ((char *)&mapEndOverlay,(unsigned char *)"extension ",&strCopy);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_
              ((unsigned char *)&mapIterOverlay,(unsigned char *)&mapEndOverlay);
    length = _strlen(" is being used");
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEPKcm
              ((unsigned char *)&mapIterOverlay," is being used",length);
    messageChars = msgChars;
    msgChars[*(int *)(msgChars + -0xc)] = *stringTerminalPtr_a7b7ba18;
                    
    __ZN13TInfoSinkBase6appendEPKc(infoSink,"WARNING: ");
    lineInString = sourceLoc & 0xffff;
    cr0Flags = (lineInString == 0) << 1;
    if (lineInString == 0) {
      _sprintf(locTextBuf,"%d:? ",sourceLoc >> 0x10);
    }
    else {
      _sprintf(locTextBuf,"%d:%d",sourceLoc >> 0x10,lineInString);
    }
    __ZNSsC1EPKcRKSaIcE(locString,locTextBuf,allocatorDummy);
    locString[0][*(int *)(locString[0] + -0xc)] = *PTR__S_terminal_a7b7c0b8;
    __ZN13TInfoSinkBase6appendEPKc(infoSink,locString[0]);
    refCountPtr = (int *)(locString[0] + -4);
    do {
      oldRefCount = *refCountPtr;
      if (reservation != '\0') {
        atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
        *refCountPtr = atomicStore;
        cr0Flags = 2;
      }
    } while (!(bool)(cr0Flags >> 1 & 1));
    if (oldRefCount < 1) {
      __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(locString[0] + -0xc));
    }
    __ZN13TInfoSinkBase6appendEPKc(infoSink,": ");
    __ZN13TInfoSinkBase6appendEPKc(infoSink,messageChars);
    __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
    refCountPtr = (int *)(msgChars + -4);
    msgDestroyArg[0] = mapIterOverlay;
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
                ((unsigned char *)(msgChars + -0xc),msgDestroyArg);
    }
    refCountPtr = (int *)(msgPrefixChars + -4);
    msgPrefixDestroyArg[0] = mapEndOverlay;
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
                ((unsigned char *)(msgPrefixChars + -0xc),msgPrefixDestroyArg);
    }
    refCountPtr = (int *)(strCopyChars + -4);
    strCopyDestroyArg[0] = strCopy;
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
                ((unsigned char *)(strCopyChars + -0xc),strCopyDestroyArg);
    }
    return false;
  }
  allocatorArg3[0] = ((int (*)())GetGlobalPoolAllocator)();
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
            ((unsigned char *)&extensionKey,str,(unsigned char *)allocatorArg3);
  std___Rb_tree_std__string_std__pair_std__string_const_TBehavior__std___Select1st_std__pair_std__string_const_TBehavior___std__less_std__string__pool_allocator_std__pair_std__string_const_TBehavior_____lower_bound((unsigned char *)allocatorOverlay,behaviorMap,(unsigned char *)&extensionKey);
  mapNode = allocatorOverlay[0];
  mapIterOverlay = *(int *)(this + 0x34);
  if (allocatorOverlay[0] != mapIterOverlay) {
    minLengthPtr = &lenNodeB;
    keyLength = *(uint *)(extensionKeyChars + -0xc);
    lenKeyB = keyLength;
    nodeKeyLength = *(uint *)(*(int *)(allocatorOverlay[0] + 0x14) + -0xc);
    lenNodeB = nodeKeyLength;
    if (keyLength <= nodeKeyLength) {
      minLengthPtr = &lenKeyB;
    }
    compareResult = _memcmp(extensionKeyChars,*(undefined4 *)(allocatorOverlay[0] + 0x14),*minLengthPtr);
    cr0Reg = (compareResult == 0) << 1;
    if (compareResult == 0) {
      compareResult = keyLength - nodeKeyLength;
    }
    if (-1 < compareResult) goto setExtBehavior;
  }
  insertIterator[0] = mapNode;
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&entryKey2,(unsigned char *)&extensionKey);
  entryBehavior2 = 0;
  insertHintCopy[0] = insertIterator[0];
  __ZNSt8_Rb_treeISbIcSt11char_traitsIcE14pool_allocatorIcEESt4pairIKS4_9TBehaviorESt10_Select1stIS8_ESt4lessIS4_ES2_IS8_EE13insert_uniqueESt17_Rb_tree_iteratorIS8_RS8_PS8_ERKS8_
            (&mapEndOverlay,behaviorMap,insertHintCopy,&entryKey2);
  refCountPtr = (int *)(entryKey2Chars + -4);
  allocatorOverlay[0] = mapEndOverlay;
  entryKey2DestroyArg[0] = entryKey2;
  do {
    oldRefCount2 = *refCountPtr;
    if (reservation != '\0') {
      newRefCount = storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
      *refCountPtr = newRefCount;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  mapNode = mapEndOverlay;
  if (oldRefCount2 < 1) {
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
              ((unsigned char *)(entryKey2Chars + -0xc),entryKey2DestroyArg);
    mapNode = allocatorOverlay[0];
  }
setExtBehavior:
  extBehavior = *(int *)(mapNode + 0x18);
  refCountPtr = (int *)(extensionKeyChars + -4);
  keyDestroyArg2[0] = extensionKey;
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
              ((unsigned char *)(extensionKeyChars + -0xc),keyDestroyArg2);
  }
  isDisabled = extBehavior == 3;
  if (isDisabled) {
    error((int)this,(char *)sourceLoc,"extension",str,"is disabled",scratchR8,extensionKeyChars,scratchR10);
  }
  return isDisabled;
}

/* TParseContext__findFunction @ 0x97b9da08 (356 bytes) */
int TParseContext__findFunction(this, sourceLoc, function, builtInOut, scratchR8, scratchR9)
  unsigned char * this;
  int sourceLoc;
  unsigned char * function;
  bool *builtInOut;
  undefined4 scratchR8;
  undefined4 scratchR9;
{
  int nameChars;
  int nameStringRef;
  int nameLength;
  int isFunctionResult;
  byte terminalChar;
  int levelIndex;
  undefined4 mangledName;
  undefined4 sourceLocCopy;
  undefined4 mangledNameCopy;
  char *errorReason;
  bool *builtInOutCopy;
  int levelsBegin;
  int *symbolTable;
  int level;
  int *foundSymbol;
  int findResult [7];
  
  symbolTable = *(int **)(this + 4);
  builtInOutCopy = builtInOut;
  mangledName = (**(code **)(*(int *)function + 8))(function,sourceLoc,function,builtInOut,scratchR8,scratchR9);
  levelsBegin = *symbolTable;
  levelIndex = (symbolTable[1] - levelsBegin >> 2) + -1;
  while( true ) {
    level = *(int *)(levelsBegin + levelIndex * 4);
    mangledNameCopy = mangledName;
    std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______find((unsigned char *)findResult,level,mangledName);
    foundSymbol = (int *)0x0;
    if (findResult[0] != *(int *)(level + 4)) {
      foundSymbol = *(int **)(findResult[0] + 0x18);
    }
    if ((foundSymbol != (int *)0x0) || (levelIndex + -1 < 0)) break;
    levelsBegin = *symbolTable;
    levelIndex = levelIndex + -1;
  }
  if (builtInOut != (bool *)0x0) {
    *(uint *)builtInOut = (uint)(levelIndex == 0);
  }
  if (foundSymbol != (int *)0x0) {
    isFunctionResult = (**(code **)(*foundSymbol + 0xc))(foundSymbol,sourceLocCopy,mangledNameCopy,builtInOutCopy,scratchR8,scratchR9,levelsBegin);
    if (isFunctionResult != 0) {
      return foundSymbol;
    }
    nameStringRef = *(int *)(function + 4);
    nameChars = *(int *)(nameStringRef + 4);
    terminalChar = *stringTerminalPtr_a7b7ba18;
    nameLength = *(int *)(nameChars + -0xc);
    errorReason = "function name expected";
  }
  else {
    nameStringRef = *(int *)(function + 4);
    nameChars = *(int *)(nameStringRef + 4);
    terminalChar = *stringTerminalPtr_a7b7ba18;
    nameLength = *(int *)(nameChars + -0xc);
    errorReason = "no matching overloaded function found";
  }
  *(byte *)(nameChars + nameLength) = terminalChar;
  error((int)this,(char *)sourceLoc,errorReason,*(char **)(nameStringRef + 4),"",scratchR9,(uint)terminalChar,nameStringRef);
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
  int initializerUnion;
  int constArray;
  int foundVariable;
  int levelsBegin2;
  uint existingTypeWord;
  uint typeStringChars;
  uint nameStringChars;
  uint zeroWord;
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
  unsigned char * poolAllocator;
  unsigned char * variableNameString;
  undefined **structTypeNameString;
  undefined **newStructTypeName;
  unsigned char * intermediate;
  unsigned char * assignNode;
  undefined4 r4Out0;
  undefined4 r4Out1;
  undefined4 r4Out2;
  undefined **structTypeName;
  undefined **r4Out3;
  undefined4 r4Out4;
  undefined4 lineCopy;
  undefined4 lineCopy2;
  undefined ***destroyAllocatorArg;
  unsigned char * ptUserDef;
  char *errorReason;
  uint ptLineCopy;
  uint ptQualifier;
  undefined4 passThroughR4;
  undefined **ptSize;
  uint *parseSymbolTable;
  uint qualifierBits;
  int childVtable;
  undefined4 singleConstantParam;
  undefined4 *tempName;
  unsigned char * variableConstPointer;
  int *symbolTable;
  undefined4 symbolTableLevel;
  int currentLevel;
  char *typeNameChars;
  unsigned char * newNodeType;
  char reservation;
  byte cr0Flags;
  undefined8 variableAllocation;
  undefined **stackType;
  uint voidErrorResult;
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
  voidErrorResult = TParseContext__voidErrorCheck(this,line,identifier,publicType);
  cr0Flags = (voidErrorResult == 0) << 1;
  if (voidErrorResult != 0) {
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
  stackTypeFieldName = voidErrorResult;
  structTypeName = (undefined **)0x0;
  stackTypeWord14 = voidErrorResult;
  stackTypeWord1c = voidErrorResult;
  stackTypeWord20 = voidErrorResult;
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
    stackTypeTypeName = (undefined **)voidErrorResult;
    stackTypeStructureSize = voidErrorResult;
    structSizeResult = TType__setStructSize((unsigned char *)&stackType,*(unsigned char **)(ptUserDef + 8));
    stackTypeStructureSize = (uint)((ulonglong)structSizeResult >> 0x20);
    structTypeNameStringRef = (**(code **)(*(int *)pt2CopyUserDef + 0x18))
                      (pt2CopyUserDef,(int)structSizeResult,ptUserDef,ptLineCopy,ptQualifier,ptSize,*(int *)pt2CopyUserDef);
    *(byte *)(*(int *)(structTypeNameStringRef + 4) + *(int *)(*(int *)(structTypeNameStringRef + 4) + -0xc)) = *stringTerminalPtr_a7b7ba18;
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
      passThroughR4 = r4Out0;
      structTypeName = structTypeNameString;
    }
  }
  stackTypeTypeName = structTypeName;
  newNode[1] = (int)identifier;
  newNodeType = (unsigned char *)(newNode + 3);
  *newNode = (int)(PTR_vtable_a7b7c0b4 + 8);
  tempName = &nameCopy;
  newNode[4] = voidErrorResult;
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
  parseSymbolTable = *(uint **)(this + 4);
  stackType = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  uniqueId = parseSymbolTable[3];
  parseSymbolTable[3] = uniqueId + 1;
  newNode[2] = uniqueId + 1;
  levelsBegin = *parseSymbolTable;
  symbolTableLevel = *(undefined4 *)(levelsBegin + ((parseSymbolTable[1] - levelsBegin & 0xfffffffc) - 4));
  zeroWord = 0;
  variableNameString = (unsigned char *)
            (**(code **)(*newNode + 8))(newNode,passThroughR4,ptUserDef,ptLineCopy,ptQualifier,ptSize,parseSymbolTable,levelsBegin);
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(tempName,variableNameString);
  variableForInsert = newNode;
  std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&stackTypeTypeName,symbolTableLevel,tempName);
  stackType = stackTypeTypeName;
  refCountPtr = (int *)(nameCopyChars + -4);
  nameStringChars = stackTypeWord14;
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
  passThroughR4 = r4Out1;
  if (oldRefCount < 1) {
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
              ((unsigned char *)(nameCopyChars + -0xc),destroyAllocator1);
    passThroughR4 = r4Out2;
  }
  if (nameStringChars == 0) {
    levelsBegin = newNode[1];
    decrementedRefCount = (uint)*stringTerminalPtr_a7b7ba18;
    errorReason = "redefinition";
    *(byte *)(*(int *)(levelsBegin + 4) + *(int *)(*(int *)(levelsBegin + 4) + -0xc)) = *stringTerminalPtr_a7b7ba18;
    nameChars = *(char **)(levelsBegin + 4);
    goto callError;
  }
  ptLineCopy = (**(code **)(newNode[3] + 0x24))(newNodeType,passThroughR4,tempName,ptLineCopy,ptQualifier,ptSize,decrementedRefCount,levelsBegin);
  if (2 < ptLineCopy) {
    nameChars = (char *)getQualifierString((uint)newNode[0xc] >> 0x19);
    errorReason = " cannot initialize this type of qualifier ";
    goto callError;
  }
  if (ptLineCopy != 2) {
    variableSymbol = TIntermediate__addSymbol
                      (*(unsigned char **)this,newNode[2],(unsigned char *)newNode[1],newNodeType,line);
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
    newNode = (int *)(nameStringChars - 4);
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
              ((unsigned char *)(nameStringChars - 0xc),destroyAllocator5);
    return 1;
  }
  (**(code **)(*(int *)initializer + 0x38))((unsigned char *)&stackType,initializer);
  stackType = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  qualifierIsNotConst = -((int)-((uint)stackTypeBits >> 0x19 ^ 2) >> 0x1f);
  cr0Flags = (qualifierIsNotConst == 0) << 1;
  if (qualifierIsNotConst != 0) {
    TType__getCompleteString(&ptCopyType,newNodeType);
    stringTerminator = *stringTerminalPtr_a7b7ba18;
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
    if (0 < oldRefCount) goto loopCallNewNodeVirtual28;
loopDestroyTypeStringRep:
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
              ((unsigned char *)(typeStringData - 0xc),destroyAllocatorArg);
loopCallNewNodeVirtual28:
    (**(code **)(newNode[3] + 0x28))(newNodeType,0);
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
  typeStringChars = qualifierIsNotConst;
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
    *(byte *)(*(int *)(structTypeNameStringRef + 4) + *(int *)(*(int *)(structTypeNameStringRef + 4) + -0xc)) = *stringTerminalPtr_a7b7ba18;
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
    goto loopCallNewNodeVirtual28;
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
      passThroughR4 = r4Out4;
      if (*(int *)(sequence + 8) - *(int *)(sequence + 4) >> 2 == 1) {
        aggregateNode = (int *)(**(code **)(*(int *)initializer + 0x1c))(initializer);
        sequence = (**(code **)(*aggregateNode + 100))(aggregateNode);
        childVtable = *(int *)**(undefined4 **)(sequence + 4);
        childConstantUnion = (int *)(**(code **)(childVtable + 0x14))
                                  ((int *)**(undefined4 **)(sequence + 4),lineCopy,ptUserDef,qualifierIsNotConst,ptLine,
                                   ptQualifierCopy,childVtable);
        childConstantUnionResult = (**(code **)(*childConstantUnion + 0x18))(childConstantUnion);
        passThroughR4 = lineCopy2;
        if (childConstantUnionResult != 0) {
          existingTypeWord = newNode[4];
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
                            (initializer,lineCopy2,stackTypeBits,stackTypeWord20,stackTypeWord1c,stackTypeStructureSize,stackTypeFieldName,
                             stackTypeWord14);
          symbolTableArg = *(undefined4 *)(this + 4);
          passThroughR4 = *(undefined4 *)(constantArrayPtr + 0x30);
          intermediate = *(unsigned char **)this;
          singleConstantParam = 1;
          goto setParseResult;
        }
      }
      existingTypeWord = newNode[4];
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
      intermediate = *(unsigned char **)this;
      singleConstantParam = 0;
setParseResult:
      parseResult = TIntermediate__parseConstTree
                        (intermediate,line,(unsigned char *)initializer,variableConstPointer,passThroughR4,symbolTableArg,
                         (unsigned char *)&stackType,singleConstantParam);
      stackType = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
      *intermNode = (unsigned char *)0x0;
      if (parseResult != 0) {
        (**(code **)(newNode[3] + 0x28))(newNodeType,0);
        return parseResult;
      }
      return 0;
    }
    symbolNodeResult = (**(code **)(*(int *)initializer + 0x28))(initializer);
    if (symbolNodeResult == 0) {
      TType__getCompleteString((unsigned char *)&stackType,newNodeType);
      stringTerminator = *stringTerminalPtr_a7b7ba18;
      *(byte *)(typeStringChars + *(int *)(typeStringChars - 0xc)) = stringTerminator;
      error((int)this,(char *)line," assigning non-constant to","=","\'%s\'",typeStringChars,
            (uint)stringTerminator,ptType);
      refCountPtr = (int *)(typeStringChars - 4);
      destroyAllocator3[0] = stackType;
      do {
        oldRefCount = *refCountPtr;
        if (reservation != '\0') {
          newRefCount = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
          *refCountPtr = newRefCount;
          cr0Flags = 2;
        }
      } while (!(bool)(cr0Flags >> 1 & 1));
      if (0 < oldRefCount) goto loopCallNewNodeVirtual28;
      destroyAllocatorArg = destroyAllocator3;
      typeStringData = typeStringChars;
      goto loopDestroyTypeStringRep;
    }
    symbolTable = *(int **)(this + 4);
    symbolNode = (int *)(**(code **)(*(int *)initializer + 0x28))(initializer);
    passThroughR4 = (**(code **)(*symbolNode + 0x60))(symbolNode);
    levelsBegin2 = *symbolTable;
    levelIndex = (symbolTable[1] - levelsBegin2 >> 2) + -1;
    while( true ) {
      currentLevel = *(int *)(levelsBegin2 + levelIndex * 4);
      std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______find((unsigned char *)levelFindResult,currentLevel,passThroughR4);
      foundVariable = 0;
      if (levelFindResult[0] != *(int *)(currentLevel + 4)) {
        foundVariable = *(int *)(levelFindResult[0] + 0x18);
      }
      levelIndex = levelIndex + -1;
      if ((foundVariable != 0) || (levelIndex < 0)) break;
      levelsBegin2 = *symbolTable;
    }
    constArray = *(int *)(foundVariable + 0x38);
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
      zeroWord = 0;
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
        decrementedRefCount = (uint)*stringTerminalPtr_a7b7ba18;
        *(byte *)(*(int *)(structTypeNameStringRef + 4) + *(int *)(*(int *)(structTypeNameStringRef + 4) + -0xc)) = *stringTerminalPtr_a7b7ba18;
        typeNameChars = *(char **)(structTypeNameStringRef + 4);
        poolAllocator = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
        typeNameAllocation = ((int (*)())TPoolAllocator__allocate)(poolAllocator,8);
        newStructTypeName = (undefined **)((ulonglong)typeNameAllocation >> 0x20);
        ptSizeCopy = (undefined **)typeNameAllocation;
        structTypeNameString = (undefined **)0x0;
        if (newStructTypeName != (undefined **)0x0) {
          poolAllocatorArg3[0] = ((int (*)())GetGlobalPoolAllocator)();
          __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                    (newStructTypeName,typeNameChars,(unsigned char *)poolAllocatorArg3);
          ptSizeCopy = r4Out3;
          structTypeNameString = newStructTypeName;
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
              goto storeIntermNode;
            }
          }
          else if (ptBasicType == 3) goto setConstantUnionNodeArray;
          nameChars = "";
          errorReason = " cannot initialize constant of this type";
callError:
          error((int)this,(char *)line,errorReason,nameChars,"",ptSize,decrementedRefCount,levelsBegin);
          return 1;
        }
setConstantUnionNodeArray:
        constantUnionNodeArray = (**(code **)(*(int *)initializer + 0x18))(initializer);
        *variableConstArray = **(undefined4 **)(constantUnionNodeArray + 0x30);
        goto storeIntermNode;
      }
    }
    initializerUnion = (**(code **)(*(int *)initializer + 0x18))(initializer,ptSizeCopy,ptUserDef,qualifierIsNotConst,ptLine);
    constArray = *(int *)(initializerUnion + 0x30);
  }
  newNode[0xe] = constArray;
storeIntermNode:
  *intermNode = (unsigned char *)0x0;
  return 0;
}


/* TParseContext__canNodeBeRemoved @ 0x97b9e960 (204 bytes) */
int TParseContext__canNodeBeRemoved(this, intermNode)
  unsigned char * this;
  unsigned char * intermNode;
{
  int sequence;
  undefined4 result;
  unsigned char * operatorNode;
  int isConstructorResult;
  int *childTyped;
  int constUnionTest;
  undefined4 *childCursor;
  
  operatorNode = (unsigned char *)(**(code **)(*(int *)intermNode + 0x1c))(intermNode,intermNode);
  result = 0;
  if (operatorNode != (unsigned char *)0x0) {
    isConstructorResult = TIntermOperator__isConstructor(operatorNode);
    if ((isConstructorResult == 0) || (*(int *)(operatorNode + 0x30) == 0x75)) {
      result = 0;
    }
    else {
      sequence = (**(code **)(*(int *)operatorNode + 100))(operatorNode);
      for (childCursor = *(undefined4 **)(sequence + 4); childCursor != *(undefined4 **)(sequence + 8);
          childCursor = childCursor + 1) {
        childTyped = (int *)(**(code **)(*(int *)*childCursor + 0x14))((int *)*childCursor);
        constUnionTest = (**(code **)(*childTyped + 0x18))(childTyped);
        if (constUnionTest == 0) {
          return 0;
        }
      }
      result = 1;
    }
  }
  return result;
}

/* TParseContext__addConstructor @ 0x97b9ea2c (944 bytes) */
int TParseContext__addConstructor(this, intermNode, type, op, function, line)
  unsigned char * this;
  unsigned char * intermNode;
  unsigned char * type;
  int op;
  int function;
  char *line;
{
  unsigned char *builtInAggregate;
  int nodeSequence;
  int nodeLineB;
  int canBeRemoved;
  int argIndexCopy;
  int nodeLine;
  int convertedSequence;
  int nodeAggregate;
  bool isNotStruct;
  unsigned char * intermAggregate;
  int firstChildVtable;
  unsigned char * resultNode;
  undefined4 nodeLineC;
  int *convertedAggregate;
  unsigned char *firstChildAggregate;
  unsigned char * argSequence;
  unsigned char * builtInNode;
  undefined4 intermNodeCopy;
  char *lineArg;
  undefined4 fwdR8;
  int scratchR9;
  undefined4 scratchR10;
  undefined4 *structFieldBegin;
  int structFieldList;
  undefined4 *childCursor;
  undefined1 eraseResultSlot [4];
  int argIndex;
  undefined4 *iteratorSlot;
  unsigned char * replacementNode;
  
  if (intermNode == (unsigned char *)0x0) {
    return (unsigned char *)0x0;
  }
  structFieldList = 0;
  isNotStruct = op != 0x75;
  structFieldBegin = (undefined4 *)0x0;
  lineArg = line;
  intermAggregate = (unsigned char *)(**(code **)(*(int *)intermNode + 0x1c))(intermNode);
  if (!isNotStruct) {
    structFieldList = *(int *)(function + 0x24);
    structFieldBegin = *(undefined4 **)(structFieldList + 4);
  }
  if (((intermAggregate == (unsigned char *)0x0) || (*(int *)(intermAggregate + 0x30) != 0)) ||
     (nodeSequence = (**(code **)(*(int *)intermAggregate + 100))(intermAggregate),
     *(int *)(nodeSequence + 8) - *(int *)(nodeSequence + 4) >> 2 == 1)) {
    if (isNotStruct) {
      nodeLineC = (*(code *)**(undefined4 **)intermNode)(intermNode);
      fwdR8 = 0;
      resultNode = (unsigned char *)((int (*)())TParseContext__constructBuiltIn)(this,type,op,intermNode,nodeLineC,0);
      if (resultNode == (unsigned char *)0x0) {
        return (unsigned char *)0x0;
      }
      nodeAggregate = (**(code **)(*(int *)resultNode + 0x1c))(resultNode);
      if (nodeAggregate == 0) {
        return resultNode;
      }
      convertedAggregate = (int *)(**(code **)(*(int *)resultNode + 0x1c))(resultNode);
      convertedSequence = (**(code **)(*convertedAggregate + 100))(convertedAggregate);
      convertedSequence = ((int (*)())TParseContext__canNodeBeRemoved)(this,(unsigned char *)**(undefined4 **)(convertedSequence + 4));
      if (convertedSequence == 0) {
        return resultNode;
      }
      convertedAggregate = (int *)(**(code **)(*(int *)resultNode + 0x1c))(resultNode);
      convertedSequence = (**(code **)(*convertedAggregate + 100))(convertedAggregate);
      firstChildVtable = *(int *)**(undefined4 **)(convertedSequence + 4);
      firstChildAggregate = (unsigned char *)
               (**(code **)(firstChildVtable + 0x1c))
                         ((int *)**(undefined4 **)(convertedSequence + 4),intermNodeCopy,op,intermNode,nodeLineC,fwdR8,firstChildVtable);
      resultNode = (unsigned char *)
               __ZN13TIntermediate15removeChildNodeEP12TIntermTypedP5TTypeP16TIntermAggregate
                         (*(void **)this,resultNode,type,firstChildAggregate);
      return resultNode;
    }
    if (*(int *)(structFieldList + 8) - *(int *)(structFieldList + 4) >> 3 == 1) {
      nodeLine = (*(code *)**(undefined4 **)intermNode)(intermNode);
      resultNode = (unsigned char *)((int (*)())TParseContext__constructStruct)(this,intermNode,(unsigned char *)*structFieldBegin,1,nodeLine,0);
      return resultNode;
    }
  }
  else {
    argSequence = (unsigned char *)(**(code **)(*(int *)intermAggregate + 100))(intermAggregate);
    if ((isNotStruct) ||
       (scratchR9 = *(int *)(argSequence + 4),
       *(int *)(structFieldList + 8) - *(int *)(structFieldList + 4) >> 3 == *(int *)(argSequence + 8) - scratchR9 >> 2)) {
      argIndex = 0;
      childCursor = *(undefined4 **)(argSequence + 4);
      do {
        argIndexCopy = argIndex;
        iteratorSlot = childCursor;
        if (childCursor == *(undefined4 **)(argSequence + 8)) {
          resultNode = (unsigned char *)
                   TIntermediate__setAggregateOperator(*(unsigned char **)this,intermAggregate,op,line);
          return resultNode;
        }
        if (isNotStruct) {
          nodeLineC = (*(code *)**(undefined4 **)intermNode)(intermNode);
          builtInNode = (unsigned char *)((int (*)())TParseContext__constructBuiltIn)(this,type,op,*childCursor,nodeLineC,1);
          if (builtInNode != (unsigned char *)0x0) {
            canBeRemoved = ((int (*)())TParseContext__canNodeBeRemoved)(this,builtInNode);
            if (canBeRemoved == 0) goto eraseArgSequence;
            builtInAggregate = (unsigned char *)(**(code **)(*(int *)builtInNode + 0x1c))(builtInNode);
            __ZN13TIntermediate15removeChildNodeER7TVectorIP11TIntermNodeER5TTypeRiRN9__gnu_cxx17__normal_iteratorIPS2_St6vectorIS2_14pool_allocatorIS2_EEEEP16TIntermAggregate
                      (*(void **)this,argSequence,type,&argIndex,(unsigned char *)&iteratorSlot,builtInAggregate
                      );
          }
        }
        else {
          nodeLineB = (*(code *)**(undefined4 **)intermNode)(intermNode);
          builtInNode = (unsigned char *)
                  ((int (*)())TParseContext__constructStruct)(this,(unsigned char *)*childCursor,(unsigned char *)structFieldBegin[argIndexCopy * 2],
                                  argIndex + 1,nodeLineB,1);
          if (builtInNode != (unsigned char *)0x0) {
eraseArgSequence:
            std__vector_TIntermNode__pool_allocator_TIntermNode_____erase
                      (eraseResultSlot,argSequence,iteratorSlot);
            replacementNode = builtInNode;
            std__vector_TIntermNode__pool_allocator_TIntermNode_____insert
                      (eraseResultSlot,argSequence,iteratorSlot,&replacementNode);
          }
        }
        argIndex = argIndex + 1;
        childCursor = iteratorSlot + 1;
      } while( true );
    }
  }
  error((int)this,line,
        "Number of constructor parameters does not match the number of structure fields",
        "constructor","",lineArg,scratchR9,scratchR10);
  return (unsigned char *)0x0;
}

/* TParseContext__constructBuiltIn @ 0x97b9eddc (408 bytes) */
int TParseContext__constructBuiltIn(this, type, op, intermNode, line, subset)
  unsigned char * this;
  unsigned char * type;
  int op;
  unsigned char * intermNode;
  char *line;
  int subset;
{
  bool sameType;
  undefined4 nodeLine;
  unsigned char * constructedNode;
  int subsetCopy;
  uint ctorIndex;
  int switchOffset;
  undefined4 scratchR10;
  undefined4 convertOp;
  undefined **typeTemp [2];
  int typeTempStructure;
  uint typeTempBits;
  
  ctorIndex = op - 0x66;
  if (ctorIndex < 0xf) {
    switchOffset = ctorIndex * 4;
    switch(ctorIndex) {
    case 0:
    case 9:
    case 10:
    case 0xb:
      convertOp = 0x66;
      break;
    case 1:
    case 6:
    case 7:
    case 8:
      convertOp = 0x67;
      break;
    default:
      convertOp = 0x68;
    }
    subsetCopy = subset;
    nodeLine = (*(code *)**(undefined4 **)intermNode)(intermNode);
    constructedNode = (unsigned char *)
             TIntermediate__addUnaryMath
                       (*(unsigned char **)this,convertOp,intermNode,nodeLine,*(undefined4 *)(this + 4),subsetCopy,
                        switchOffset);
    if (constructedNode != (unsigned char *)0x0) {
      if (subset != 0) {
        return constructedNode;
      }
      if (constructedNode != intermNode) {
        (**(code **)(*(int *)constructedNode + 0x38))(typeTemp,constructedNode);
        sameType = false;
        if (((typeTempBits & 0x1fffe00) == (*(uint *)(type + 0x24) & 0x1fffe00)) &&
           (typeTempStructure == *(int *)(type + 8))) {
          sameType = true;
        }
        typeTemp[0] = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
        if (sameType) {
          return constructedNode;
        }
      }
      constructedNode = (unsigned char *)
               TIntermediate__setAggregateOperator(*(unsigned char **)this,constructedNode,op,line);
      return constructedNode;
    }
    error((int)this,line,"can\'t convert","constructor","",subsetCopy,switchOffset,scratchR10);
  }
  else {
    error((int)this,line,"unsupported construction","","",subset,ctorIndex,scratchR10);
    TParseContext__recover(this);
  }
  return (unsigned char *)0x0;
}

/* TParseContext__constructStruct @ 0x97b9efb0 (392 bytes) */
int TParseContext__constructStruct(this, intermNode, type, paramCount, line, subset)
  unsigned char * this;
  unsigned char * intermNode;
  unsigned char * type;
  int paramCount;
  int line;
  int subset;
{
  undefined4 basicString;
  int *nodeTyped;
  undefined4 result;
  unsigned char * intermTyped;
  undefined4 fromTypeName;
  undefined4 intermNodeCopy;
  unsigned char * typeCopy;
  int paramCountCopy;
  int lineCopy;
  int subsetCopy;
  int typesMatch;
  undefined **typeTemp [2];
  int typeTempStructure;
  uint typeTempBits;
  undefined **typeTemp2 [9];
  uint typeTemp2Bits;
  
  typeCopy = type;
  paramCountCopy = paramCount;
  lineCopy = line;
  subsetCopy = subset;
  nodeTyped = (int *)(**(code **)(*(int *)intermNode + 0x14))
                            (intermNode,intermNode,type,paramCount,line,subset);
  (**(code **)(*nodeTyped + 0x38))(typeTemp,nodeTyped);
  typesMatch = 0;
  if (((*(uint *)(type + 0x24) & 0x1fffe00) == (typeTempBits & 0x1fffe00)) &&
     (*(int *)(type + 8) == typeTempStructure)) {
    typesMatch = 1;
  }
  typeTemp[0] = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  if (typesMatch == 0) {
    basicString = TType__getBasicString(*(uint *)(type + 0x24) >> 0x13 & 0x3f);
    nodeTyped = (int *)(**(code **)(*(int *)intermNode + 0x14))(intermNode);
    (**(code **)(*nodeTyped + 0x38))(typeTemp2,nodeTyped);
    fromTypeName = TType__getBasicString(typeTemp2Bits >> 0x13 & 0x3f);
    error((int)this,(char *)line,"","constructor",
          "cannot convert parameter %d from \'%s\' to \'%s\'",paramCount,fromTypeName,basicString);
    typeTemp2[0] = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
    TParseContext__recover(this);
    result = 0;
  }
  else if (subset == 0) {
    intermTyped = (unsigned char *)(**(code **)(*(int *)intermNode + 0x14))(intermNode);
    result = TIntermediate__setAggregateOperator(*(unsigned char **)this,intermTyped,0x75,line);
  }
  else {
    result = (**(code **)(*(int *)intermNode + 0x14))(intermNode,intermNodeCopy,typeCopy,paramCountCopy,lineCopy,subsetCopy,typesMatch);
  }
  return result;
}

/* TParseContext__addConstVectorNode @ 0x97b9f138 (148 bytes) */
int TParseContext__addConstVectorNode(this, vectorFields, intermTyped, line, scratchR7, scratchR8)
  unsigned char * this;
  unsigned char * vectorFields;
  unsigned char * intermTyped;
  int line;
  undefined4 scratchR7;
  undefined4 scratchR8;
{
  unsigned char *constantNode;
  int *firstChildTyped;
  int fieldIndex;
  int sequence;
  int objectSize;
  int nodeComponentCount;
  int fieldByteOffset;
  int fieldCount;
  int parseResult;
  int constUnionTest;
  undefined *atomicStore;
  undefined **refCountPtr;
  int firstChildVtable;
  undefined *oldRefCount;
  int constUnionNode;
  unsigned char * intermAggregate;
  int *nodeAggregate;
  unsigned char * poolAllocator;
  unsigned char * resultArray;
  unsigned char *intermTypedCopy;
  undefined4 vectorFieldsCopy;
  uint sourceLine;
  undefined4 scratchR9;
  undefined4 scratchR10;
  unsigned char * constArray;
  void *infoSink;
  int lineCopy;
  char reservation;
  byte cr0Flags;
  undefined **typeTempOverlay [4];
  char locTextBuf [20];
  uint typeTempBits;
  unsigned char allocatorDummy [16];
  
  intermTypedCopy = intermTyped;
  lineCopy = line;
  constUnionNode = (**(code **)(*(int *)intermTyped + 0x18))(intermTyped,vectorFields,intermTyped,line,scratchR7,scratchR8);
  intermAggregate = (unsigned char *)(**(code **)(*(int *)intermTyped + 0x1c))(intermTyped);
  if (constUnionNode != 0) {
    constArray = *(unsigned char **)(constUnionNode + 0x30);
    if (constArray == (unsigned char *)0x0) {
      infoSink = *(void **)(this + 8);
                    
      __ZN13TInfoSinkBase6appendEPKc(infoSink,"INTERNAL ERROR: ");
      sourceLine = line & 0xffff;
      cr0Flags = (sourceLine == 0) << 1;
      if (sourceLine == 0) {
        _sprintf(locTextBuf,"%d:? ",line >> 0x10);
      }
      else {
        _sprintf(locTextBuf,"%d:%d",line >> 0x10,sourceLine);
      }
      __ZNSsC1EPKcRKSaIcE(typeTempOverlay,locTextBuf,allocatorDummy);
      *(undefined *)((int)typeTempOverlay[0] + (int)typeTempOverlay[0][-3]) = *PTR__S_terminal_a7b7c0b8;
      __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)typeTempOverlay[0]);
      refCountPtr = typeTempOverlay[0] + -1;
      do {
        oldRefCount = *refCountPtr;
        if (reservation != '\0') {
          atomicStore = (undefined *)storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
          *refCountPtr = atomicStore;
          cr0Flags = 2;
        }
      } while (!(bool)(cr0Flags >> 1 & 1));
      if ((int)oldRefCount < 1) {
        __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(typeTempOverlay[0] + -3),locTextBuf);
      }
      __ZN13TInfoSinkBase6appendEPKc(infoSink,": ");
      __ZN13TInfoSinkBase6appendEPKc
                (infoSink,"constUnion not initialized in addConstVectorNode function");
      __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
      TParseContext__recover(this);
      return intermTyped;
    }
    goto setFieldCount;
  }
  if (intermAggregate == (unsigned char *)0x0) {
    error((int)this,(char *)line,"No aggregate or constant union node available","Internal Error"
          ,"",scratchR8,scratchR9,scratchR10);
    TParseContext__recover(this);
    return (unsigned char *)0x0;
  }
  (**(code **)(*(int *)intermAggregate + 0x38))(typeTempOverlay,intermAggregate);
  if ((typeTempBits & 0x400) == 0) {
    objectSize = (int)(typeTempBits << 0xd | typeTempBits >> 0x13) >> 0x18;
  }
  else {
    objectSize = (int)(typeTempBits << 0xd | typeTempBits >> 0x13) >> 0x18;
    objectSize = objectSize * objectSize;
  }
  poolAllocator = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
  constArray = (unsigned char *)((int (*)())TPoolAllocator__allocate)(poolAllocator,objectSize << 2);
  typeTempOverlay[0] = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  nodeAggregate = (int *)(**(code **)(*(int *)intermAggregate + 0x1c))(intermAggregate);
  sequence = (**(code **)(*nodeAggregate + 100))(nodeAggregate);
  if (*(int *)(sequence + 8) - *(int *)(sequence + 4) >> 2 == 1) {
    nodeAggregate = (int *)(**(code **)(*(int *)intermAggregate + 0x1c))(intermAggregate);
    sequence = (**(code **)(*nodeAggregate + 100))(nodeAggregate);
    firstChildVtable = *(int *)**(undefined4 **)(sequence + 4);
    firstChildTyped = (int *)(**(code **)(firstChildVtable + 0x14))
                              ((int *)**(undefined4 **)(sequence + 4),vectorFieldsCopy,intermTypedCopy,lineCopy,scratchR7,
                               scratchR8,firstChildVtable);
    constUnionTest = (**(code **)(*firstChildTyped + 0x18))(firstChildTyped);
    if (constUnionTest == 0) goto callIntermAggregateVirtual38;
    (**(code **)(*(int *)intermAggregate + 0x38))(typeTempOverlay,intermAggregate);
    scratchR10 = 1;
    parseResult = TIntermediate__parseConstTree
                       (*(unsigned char **)this,line,intermAggregate,constArray,*(undefined4 *)(intermAggregate + 0x30),
                        *(undefined4 *)(this + 4),typeTempOverlay,1);
  }
  else {
callIntermAggregateVirtual38:
    (**(code **)(*(int *)intermAggregate + 0x38))(typeTempOverlay,intermAggregate);
    scratchR10 = 0;
    parseResult = TIntermediate__parseConstTree
                       (*(unsigned char **)this,line,intermAggregate,constArray,*(undefined4 *)(intermAggregate + 0x30),
                        *(undefined4 *)(this + 4),typeTempOverlay,0);
  }
  typeTempOverlay[0] = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  if (parseResult != 0) {
    return (unsigned char *)0x0;
  }
setFieldCount:
  fieldCount = *(int *)(vectorFields + 0x10);
  fieldIndex = 0;
  poolAllocator = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
  resultArray = (unsigned char *)((int (*)())TPoolAllocator__allocate)(poolAllocator,fieldCount << 2);
  if (0 < *(int *)(vectorFields + 0x10)) {
    fieldByteOffset = 0;
    do {
      (**(code **)(*(int *)intermTyped + 0x38))(typeTempOverlay,intermTyped);
      if ((typeTempBits & 0x400) == 0) {
        nodeComponentCount = (int)(typeTempBits << 0xd | typeTempBits >> 0x13) >> 0x18;
      }
      else {
        nodeComponentCount = (int)(typeTempBits << 0xd | typeTempBits >> 0x13) >> 0x18;
        nodeComponentCount = nodeComponentCount * nodeComponentCount;
      }
      typeTempOverlay[0] = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
      if (nodeComponentCount <= *(int *)(vectorFields + fieldByteOffset) != 0) {
        error((int)this,(char *)line,"","[","vector field selection out of range \'%d\'",
              *(undefined4 *)(vectorFields + fieldByteOffset),(uint)(nodeComponentCount <= *(int *)(vectorFields + fieldByteOffset)),scratchR10);
        TParseContext__recover(this);
        *(undefined4 *)(vectorFields + fieldByteOffset) = 0;
      }
      fieldIndex = fieldIndex + 1;
      *(undefined4 *)(resultArray + fieldByteOffset) = *(undefined4 *)(constArray + *(int *)(vectorFields + fieldByteOffset) * 4);
      fieldByteOffset = fieldByteOffset + 4;
    } while (fieldIndex < *(int *)(vectorFields + 0x10));
  }
  (**(code **)(*(int *)intermTyped + 0x38))(typeTempOverlay,intermTyped);
  constantNode = (unsigned char *)
           TIntermediate__addConstantUnion(*(unsigned char **)this,resultArray,(unsigned char *)typeTempOverlay,line)
  ;
  return constantNode;
}

/* TParseContext__addConstMatrixNode @ 0x97b9f600 (904 bytes) */
int TParseContext__addConstMatrixNode(this, columnIndex, intermTyped, line)
  unsigned char * this;
  int columnIndex;
  unsigned char * intermTyped;
  int line;
{
  int *firstChildTyped;
  int *nodeAggregate;
  int parseResult;
  int constUnionTest;
  int sequence;
  int objectSize;
  int *constUnionNode;
  unsigned char * intermAggregate;
  undefined4 resultNode;
  unsigned char * poolAllocator;
  unsigned char * newConstArray;
  undefined4 columnIndexCopy;
  char *fwdR5;
  char *fwdR6;
  char *scratchR7;
  int scratchR8;
  undefined4 scratchR9;
  int firstChildVtable;
  undefined4 scratchR10;
  int columnOffset;
  int constArray;
  undefined **typeTemp [9];
  uint typeTempBits;
  
  fwdR5 = (char *)intermTyped;
  fwdR6 = (char *)line;
  constUnionNode = (int *)(**(code **)(*(int *)intermTyped + 0x18))(intermTyped,columnIndex,intermTyped,line);
  intermAggregate = (unsigned char *)(**(code **)(*(int *)intermTyped + 0x1c))(intermTyped);
  (**(code **)(*(int *)intermTyped + 0x38))(typeTemp,intermTyped);
  typeTemp[0] = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  columnOffset = columnIndex;
  if ((int)(typeTempBits << 0xd | typeTempBits >> 0x13) >> 0x18 <= columnIndex) {
    fwdR5 = "";
    fwdR6 = "[";
    scratchR7 = "matrix field selection out of range \'%d\'";
    columnOffset = 0;
    error((int)this,(char *)line,"","[","matrix field selection out of range \'%d\'",columnIndex,
          scratchR9,scratchR10);
    TParseContext__recover(this);
    scratchR8 = columnIndex;
  }
  if (constUnionNode != (int *)0x0) {
    constArray = constUnionNode[0xc];
    (**(code **)(*constUnionNode + 0x38))((unsigned char *)typeTemp,constUnionNode);
    typeTemp[0] = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
    (**(code **)(*constUnionNode + 0x38))((unsigned char *)typeTemp,constUnionNode);
    resultNode = TIntermediate__addConstantUnion
                      (*(unsigned char **)this,
                       (unsigned char *)
                       (constArray + ((int)(typeTempBits << 0xd | typeTempBits >> 0x13) >> 0x18) * columnOffset * 4),
                       (unsigned char *)typeTemp,line);
    return resultNode;
  }
  if (intermAggregate == (unsigned char *)0x0) {
    error((int)this,(char *)line,"No Aggregate or Constant Union node available","Internal Error"
          ,"",scratchR8,scratchR9,scratchR10);
    TParseContext__recover(this);
    return 0;
  }
  (**(code **)(*(int *)intermAggregate + 0x38))((unsigned char *)typeTemp,intermAggregate);
  if ((typeTempBits & 0x400) == 0) {
    objectSize = (int)(typeTempBits << 0xd | typeTempBits >> 0x13) >> 0x18;
  }
  else {
    objectSize = (int)(typeTempBits << 0xd | typeTempBits >> 0x13) >> 0x18;
    objectSize = objectSize * objectSize;
  }
  poolAllocator = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
  newConstArray = (unsigned char *)((int (*)())TPoolAllocator__allocate)(poolAllocator,objectSize << 2);
  typeTemp[0] = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  (**(code **)(*(int *)intermAggregate + 0x38))((unsigned char *)typeTemp,intermAggregate);
  typeTemp[0] = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  nodeAggregate = (int *)(**(code **)(*(int *)intermAggregate + 0x1c))(intermAggregate);
  sequence = (**(code **)(*nodeAggregate + 100))(nodeAggregate);
  if (*(int *)(sequence + 8) - *(int *)(sequence + 4) >> 2 == 1) {
    nodeAggregate = (int *)(**(code **)(*(int *)intermAggregate + 0x1c))(intermAggregate);
    sequence = (**(code **)(*nodeAggregate + 100))(nodeAggregate);
    firstChildVtable = *(int *)**(undefined4 **)(sequence + 4);
    firstChildTyped = (int *)(**(code **)(firstChildVtable + 0x14))
                              ((int *)**(undefined4 **)(sequence + 4),columnIndexCopy,fwdR5,fwdR6,scratchR7,scratchR8,firstChildVtable);
    constUnionTest = (**(code **)(*firstChildTyped + 0x18))(firstChildTyped);
    if (constUnionTest != 0) {
      (**(code **)(*(int *)intermAggregate + 0x38))((unsigned char *)typeTemp,intermAggregate);
      parseResult = TIntermediate__parseConstTree
                        (*(unsigned char **)this,line,intermAggregate,newConstArray,*(undefined4 *)(intermAggregate + 0x30),
                         *(undefined4 *)(this + 4),(unsigned char *)typeTemp,1);
      goto storeTypeTemp;
    }
  }
  (**(code **)(*(int *)intermAggregate + 0x38))(typeTemp,intermAggregate);
  parseResult = TIntermediate__parseConstTree
                    (*(unsigned char **)this,line,intermAggregate,newConstArray,*(undefined4 *)(intermAggregate + 0x30),
                     *(undefined4 *)(this + 4),typeTemp,0);
storeTypeTemp:
  typeTemp[0] = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  resultNode = 0;
  if (parseResult == 0) {
    (**(code **)(*(int *)intermAggregate + 0x38))(typeTemp,intermAggregate);
    resultNode = TIntermediate__addConstantUnion
                      (*(unsigned char **)this,
                       newConstArray + ((int)(typeTempBits << 0xd | typeTempBits >> 0x13) >> 0x18) * columnOffset * 4,
                       (unsigned char *)typeTemp,line);
  }
  return resultNode;
}

/* TParseContext__addConstStruct @ 0x97b9f988 (848 bytes) */
int TParseContext__addConstStruct(this, text, intermTyped, line, scratchR7, scratchR8)
  unsigned char * this;
  unsigned char * text;
  unsigned char * intermTyped;
  int line;
  undefined4 scratchR7;
  undefined4 scratchR8;
{
  int *firstChildTyped;
  int *nodeAggregate;
  int firstChildVtable;
  int fieldSize;
  int sequence;
  int parseResult;
  int constUnionTest;
  int nodeVtable;
  int lineCopy;
  unsigned char * intermConstantUnion;
  unsigned char * intermAggregate;
  unsigned char * structFieldType;
  unsigned char * poolAllocator;
  int *fieldType;
  undefined4 resultNode;
  undefined4 textCopy;
  undefined4 textCopy2;
  uint *minLengthPtr;
  unsigned char * fwdR5;
  int nodeVtableB;
  int fieldTypeBegin;
  undefined4 scratchR10;
  int componentOffset;
  uint fieldIndex;
  uint nameLength;
  unsigned char * constArray;
  uint fieldNameLen;
  undefined **typeTemp [2];
  int typeTempStructure;
  int typeTempStructureSize;
  uint fieldNameLength;
  uint nameLengths [5];
  
  componentOffset = 0;
  fwdR5 = intermTyped;
  lineCopy = line;
  (**(code **)(*(int *)intermTyped + 0x38))(typeTemp,intermTyped,intermTyped,line,scratchR7,scratchR8);
  nodeVtableB = *(int *)intermTyped;
  typeTemp[0] = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  intermConstantUnion = (unsigned char *)(**(code **)(nodeVtableB + 0x18))(intermTyped,textCopy,fwdR5,lineCopy,scratchR7,scratchR8,nodeVtableB);
  intermAggregate = (unsigned char *)(**(code **)(*(int *)intermTyped + 0x1c))(intermTyped);
  for (fieldIndex = 0; fieldIndex < (uint)(*(int *)(typeTempStructure + 8) - *(int *)(typeTempStructure + 4) >> 3);
      fieldIndex = fieldIndex + 1) {
    fieldType = *(int **)(*(int *)(typeTempStructure + 4) + fieldIndex * 8);
    fieldTypeBegin = (**(code **)(*fieldType + 0x1c))(fieldType);
    fieldNameLen = *(uint *)(*(int *)(fieldTypeBegin + 4) + -0xc);
    fieldNameLength = fieldNameLen;
    nameLength = *(uint *)(*(int *)(text + 4) + -0xc);
    nameLengths[0] = nameLength;
    minLengthPtr = nameLengths;
    if (fieldNameLen <= nameLength) {
      minLengthPtr = &fieldNameLength;
    }
    fwdR5 = (unsigned char *)*minLengthPtr;
    fieldTypeBegin = _memcmp(*(undefined4 *)(fieldTypeBegin + 4),*(int *)(text + 4),fwdR5);
    if (fieldTypeBegin == 0) {
      fieldTypeBegin = fieldNameLen - nameLength;
    }
    if (fieldTypeBegin == 0) break;
    structFieldType = *(unsigned char **)(*(int *)(typeTempStructure + 4) + fieldIndex * 8);
    if (*(unsigned char **)(structFieldType + 8) == (unsigned char *)0x0) {
      fieldSize = (**(code **)(*(int *)structFieldType + 0x30))(structFieldType);
    }
    else {
      fieldSize = TType__setStructSize(structFieldType,*(unsigned char **)(structFieldType + 8));
    }
    componentOffset = componentOffset + fieldSize;
  }
  if (intermConstantUnion != (unsigned char *)0x0) {
    nodeVtable = *(int *)intermConstantUnion;
    constArray = *(unsigned char **)(intermConstantUnion + 0x30);
    intermAggregate = intermConstantUnion;
    goto callNodeVirtual38;
  }
  if (intermAggregate == (unsigned char *)0x0) {
    error((int)this,(char *)line,"No Aggregate or Constant Union node available","Internal Error"
          ,"",scratchR8,nodeVtableB,scratchR10);
    TParseContext__recover(this);
    return 0;
  }
  (**(code **)(*(int *)intermAggregate + 0x38))(typeTemp,intermAggregate);
  poolAllocator = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
  constArray = (unsigned char *)((int (*)())TPoolAllocator__allocate)(poolAllocator,typeTempStructureSize << 2);
  typeTemp[0] = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  nodeAggregate = (int *)(**(code **)(*(int *)intermAggregate + 0x1c))(intermAggregate);
  sequence = (**(code **)(*nodeAggregate + 100))(nodeAggregate);
  if (*(int *)(sequence + 8) - *(int *)(sequence + 4) >> 2 == 1) {
    nodeAggregate = (int *)(**(code **)(*(int *)intermAggregate + 0x1c))(intermAggregate);
    sequence = (**(code **)(*nodeAggregate + 100))(nodeAggregate);
    firstChildVtable = *(int *)**(undefined4 **)(sequence + 4);
    firstChildTyped = (int *)(**(code **)(firstChildVtable + 0x14))
                              ((int *)**(undefined4 **)(sequence + 4),textCopy2,fwdR5,lineCopy,scratchR7,scratchR8,
                               firstChildVtable);
    constUnionTest = (**(code **)(*firstChildTyped + 0x18))(firstChildTyped);
    if (constUnionTest == 0) goto callIntermAggregateVirtual38;
    (**(code **)(*(int *)intermAggregate + 0x38))(typeTemp,intermAggregate);
    parseResult = TIntermediate__parseConstTree
                      (*(unsigned char **)this,line,intermAggregate,constArray,*(undefined4 *)(intermAggregate + 0x30),
                       *(undefined4 *)(this + 4),typeTemp,1);
  }
  else {
callIntermAggregateVirtual38:
    (**(code **)(*(int *)intermAggregate + 0x38))(typeTemp,intermAggregate);
    parseResult = TIntermediate__parseConstTree
                      (*(unsigned char **)this,line,intermAggregate,constArray,*(undefined4 *)(intermAggregate + 0x30),
                       *(undefined4 *)(this + 4),typeTemp,0);
  }
  typeTemp[0] = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  if (parseResult != 0) {
    return 0;
  }
  nodeVtable = *(int *)intermAggregate;
callNodeVirtual38:
  (**(code **)(nodeVtable + 0x38))(typeTemp,intermAggregate);
  resultNode = TIntermediate__addConstantUnion
                    (*(unsigned char **)this,constArray + componentOffset * 4,(unsigned char *)typeTemp,line);
  return resultNode;
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
  int mapNode;
  int compareResult;
  uint *minLengthPtr;
  uint keyLength;
  uint nodeKeyLength;
  char reservation;
  byte cr0Reg;
  undefined4 extensionKey;
  int extensionKeyChars;
  undefined4 allocatorArg [4];
  int lowerBound [4];
  int mapEnd;
  int insertIterator [4];
  int insertHint;
  undefined4 entryKey;
  int entryKeyChars;
  undefined4 entryBehavior;
  int insertHintCopy [4];
  undefined4 entryKeyDestroyArg [4];
  undefined4 keyDestroyArg [4];
  uint lenKey;
  uint lenNode [4];
  
  allocatorArg[0] = ((int (*)())GetGlobalPoolAllocator)();
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
            ((unsigned char *)&extensionKey,"GL_ARB_texture_rectangle",(unsigned char *)allocatorArg);
  std___Rb_tree_std__string_std__pair_std__string_const_TBehavior__std___Select1st_std__pair_std__string_const_TBehavior___std__less_std__string__pool_allocator_std__pair_std__string_const_TBehavior_____lower_bound((unsigned char *)lowerBound,this + 0x30,(unsigned char *)&extensionKey);
  mapNode = lowerBound[0];
  mapEnd = *(int *)(this + 0x34);
  if (lowerBound[0] != mapEnd) {
    minLengthPtr = lenNode;
    keyLength = *(uint *)(extensionKeyChars + -0xc);
    lenKey = keyLength;
    nodeKeyLength = *(uint *)(*(int *)(lowerBound[0] + 0x14) + -0xc);
    lenNode[0] = nodeKeyLength;
    if (keyLength <= nodeKeyLength) {
      minLengthPtr = &lenKey;
    }
    compareResult = _memcmp(extensionKeyChars,*(undefined4 *)(lowerBound[0] + 0x14),*minLengthPtr);
    cr0Reg = (compareResult == 0) << 1;
    if (compareResult == 0) {
      compareResult = keyLength - nodeKeyLength;
    }
    if (-1 < compareResult) goto storeMapNode;
  }
  insertHint = mapNode;
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&entryKey,(unsigned char *)&extensionKey);
  entryBehavior = 0;
  insertHintCopy[0] = insertHint;
  __ZNSt8_Rb_treeISbIcSt11char_traitsIcE14pool_allocatorIcEESt4pairIKS4_9TBehaviorESt10_Select1stIS8_ESt4lessIS4_ES2_IS8_EE13insert_uniqueESt17_Rb_tree_iteratorIS8_RS8_PS8_ERKS8_
            (insertIterator,this + 0x30,insertHintCopy,&entryKey);
  refCountPtr = (int *)(entryKeyChars + -4);
  lowerBound[0] = insertIterator[0];
  entryKeyDestroyArg[0] = entryKey;
  do {
    oldRefCount2 = *refCountPtr;
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
      *refCountPtr = atomicStore;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  mapNode = insertIterator[0];
  if (oldRefCount2 < 1) {
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
              ((unsigned char *)(entryKeyChars + -0xc),entryKeyDestroyArg);
    mapNode = lowerBound[0];
  }
storeMapNode:
  *(undefined4 *)(mapNode + 0x18) = 1;
  refCountPtr = (int *)(extensionKeyChars + -4);
  keyDestroyArg[0] = extensionKey;
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
              ((unsigned char *)(extensionKeyChars + -0xc),keyDestroyArg);
  }
  return;
}

/* InitializeGlobalPools @ 0x97b9fe54 (144 bytes) */
int InitializeGlobalPools()
{
  undefined4 scratchR3;
  unsigned char * this;
  undefined4 pushResult;
  
  if (_gPollAllocThreadData == (undefined4 *)0x0) {
    this = operator_new(0x34);
    ((int (*)())__ZN14TPoolAllocatorC1Ebii)(this,1,0x2000,0x10);
    _gPollAllocThreadData = operator_new(8);
    _gPollAllocThreadData[1] = 0;
    *_gPollAllocThreadData = this;
    _gPollAllocThreadData[1] = 0;
    pushResult = ((int (*)())TPoolAllocator__push)(this);
    return pushResult;
  }
  return scratchR3;
}

/* FreeGlobalPools @ 0x97b9fee4 (112 bytes) */
int FreeGlobalPools()
{
  undefined4 scratchR3;
  unsigned char * this;
  void *globalPoolAllocator;
  
  if (_gPollAllocThreadData != (void *)0x0) {
    this = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
    ((int (*)())TPoolAllocator__popAll)(this);
    globalPoolAllocator = (void *)((int (*)())GetGlobalPoolAllocator)();
    if (globalPoolAllocator != (void *)0x0) {
      ((int (*)())__ZN14TPoolAllocatorD1Ev)(globalPoolAllocator);
      __ZdlPv(globalPoolAllocator);
    }
    scratchR3 = __ZdlPv(_gPollAllocThreadData);
    _gPollAllocThreadData = (void *)0x0;
  }
  return scratchR3;
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
int __ZN14TPoolAllocatorC2Ebii(this, global, growthIncrement, allocationAlignment)
  void *this;
  undefined4 global;
  int growthIncrement;
  int allocationAlignment;
{
  uint alignment;
  
  *(undefined4 *)this = global;
  *(int *)((int)this + 8) = allocationAlignment;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x28) = 0;
  *(undefined4 *)((int)this + 0x2c) = 0;
  *(int *)((int)this + 4) = growthIncrement;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  if ((uint)growthIncrement < 0x1000) {
    *(undefined4 *)((int)this + 4) = 0x1000;
  }
  alignment = *(uint *)((int)this + 8) & 0xfffffffc;
  *(undefined4 *)((int)this + 0x14) = *(undefined4 *)((int)this + 4);
  *(uint *)((int)this + 8) = alignment;
  if (alignment < 4) {
    *(undefined4 *)((int)this + 8) = 4;
  }
  alignment = 1;
  if (1 < *(uint *)((int)this + 8)) {
    do {
      alignment = alignment << 1;
    } while (alignment < *(uint *)((int)this + 8));
  }
  *(uint *)((int)this + 8) = alignment;
  *(uint *)((int)this + 0x10) = alignment + 7 & ~(alignment - 1);
  *(uint *)((int)this + 0xc) = alignment - 1;
  return;
}

/* __ZN14TPoolAllocatorC1Ebii @ 0x97b9ffb8 (4 bytes) */
int __ZN14TPoolAllocatorC1Ebii(this, global, growthIncrement, allocationAlignment)
  void *this;
  undefined4 global;
  int growthIncrement;
  int allocationAlignment;
{
  uint alignment;
  
  *(undefined4 *)this = global;
  *(int *)((int)this + 8) = allocationAlignment;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x28) = 0;
  *(undefined4 *)((int)this + 0x2c) = 0;
  *(int *)((int)this + 4) = growthIncrement;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  if ((uint)growthIncrement < 0x1000) {
    *(undefined4 *)((int)this + 4) = 0x1000;
  }
  alignment = *(uint *)((int)this + 8) & 0xfffffffc;
  *(undefined4 *)((int)this + 0x14) = *(undefined4 *)((int)this + 4);
  *(uint *)((int)this + 8) = alignment;
  if (alignment < 4) {
    *(undefined4 *)((int)this + 8) = 4;
  }
  alignment = 1;
  if (1 < *(uint *)((int)this + 8)) {
    do {
      alignment = alignment << 1;
    } while (alignment < *(uint *)((int)this + 8));
  }
  *(uint *)((int)this + 8) = alignment;
  *(uint *)((int)this + 0x10) = alignment + 7 & ~(alignment - 1);
  *(uint *)((int)this + 0xc) = alignment - 1;
  return;
}

/* __ZN14TPoolAllocatorC4Ebii @ 0x97b9ffbc (152 bytes) */
int __ZN14TPoolAllocatorC4Ebii(this, global, growthIncrement, allocationAlignment)
  void *this;
  undefined4 global;
  int growthIncrement;
  int allocationAlignment;
{
  uint alignment;
  
  *(undefined4 *)this = global;
  *(int *)((int)this + 8) = allocationAlignment;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x28) = 0;
  *(undefined4 *)((int)this + 0x2c) = 0;
  *(int *)((int)this + 4) = growthIncrement;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  if ((uint)growthIncrement < 0x1000) {
    *(undefined4 *)((int)this + 4) = 0x1000;
  }
  alignment = *(uint *)((int)this + 8) & 0xfffffffc;
  *(undefined4 *)((int)this + 0x14) = *(undefined4 *)((int)this + 4);
  *(uint *)((int)this + 8) = alignment;
  if (alignment < 4) {
    *(undefined4 *)((int)this + 8) = 4;
  }
  alignment = 1;
  if (1 < *(uint *)((int)this + 8)) {
    do {
      alignment = alignment << 1;
    } while (alignment < *(uint *)((int)this + 8));
  }
  *(uint *)((int)this + 8) = alignment;
  *(uint *)((int)this + 0x10) = alignment + 7 & ~(alignment - 1);
  *(uint *)((int)this + 0xc) = alignment - 1;
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
  int stackCapacityEntries;
  undefined4 *page;
  int stackEntry;
  void *nextPage;
  
  if (*(int *)this == 0) {
    page = *(void **)((int)this + 0x1c);
    while (page != (void *)0x0) {
      nextPage = (void *)*page;
      __ZdaPv(page);
      *(void **)((int)this + 0x1c) = nextPage;
      page = nextPage;
    }
  }
  page = *(void **)((int)this + 0x18);
  while (page != (void *)0x0) {
    nextPage = (void *)*page;
    __ZdaPv(page);
    *(void **)((int)this + 0x18) = nextPage;
    page = nextPage;
  }
  for (stackEntry = *(int *)((int)this + 0x20); stackEntry != *(int *)((int)this + 0x24); stackEntry = stackEntry + 8) {
  }
  stackCapacityEntries = *(int *)((int)this + 0x28) - (int)*(void **)((int)this + 0x20) >> 3;
  if (stackCapacityEntries != 0) {
    std____default_alloc_template_true_0___deallocate(*(void **)((int)this + 0x20),stackCapacityEntries << 3);
  }
  return;
}

/* TAllocation__checkGuardBlock @ 0x97ba011c (4 bytes) */
int TAllocation__checkGuardBlock(this, offset, expectedValue)
  uchar *this;
  int offset;
  char *expectedValue;
{
  return;
}

/* TPoolAllocator__push @ 0x97ba0120 (136 bytes) */
int TPoolAllocator__push(this)
  unsigned char * this;
{
  undefined4 *stackEnd;
  int newStackEnd;
  undefined4 savedOffset;
  undefined4 savedPage;
  undefined4 savedOffsetCopy;
  undefined4 savedPageCopy;
  
  stackEnd = *(undefined4 **)(this + 0x24);
  savedOffset = *(undefined4 *)(this + 0x14);
  savedPage = *(undefined4 *)(this + 0x1c);
  if (stackEnd == *(undefined4 **)(this + 0x28)) {
    savedOffsetCopy = savedOffset;
    savedPageCopy = savedPage;
    std__vector_TPoolAllocator__tAllocState_std__allocator_TPoolAllocator__tAllocState_____M_insert_aux((unsigned char *)(this + 0x20),*(undefined4 *)(this + 0x24),&savedOffset);
  }
  else {
    newStackEnd = 0;
    if (stackEnd != (undefined4 *)0x0) {
      stackEnd[1] = savedPage;
      *stackEnd = savedOffset;
      newStackEnd = *(int *)(this + 0x24);
    }
    *(int *)(this + 0x24) = newStackEnd + 8;
  }
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(this + 4);
  return;
}

/* TPoolAllocator__pop @ 0x97ba01a8 (160 bytes) */
int TPoolAllocator__pop(this)
  unsigned char * this;
{
  undefined4 *page;
  void *savedPage;
  void *nextPage;
  
  if ((uint)(*(int *)(this + 0x24) - *(int *)(this + 0x20)) >> 3 != 0) {
    savedPage = *(void **)(*(int *)(this + 0x24) + -4);
    *(undefined4 *)(this + 0x14) = *(undefined4 *)(*(int *)(this + 0x24) + -8);
    page = *(void **)(this + 0x1c);
    while (page != savedPage) {
      nextPage = (void *)*page;
      if ((uint)page[1] < 2) {
        *page = *(undefined4 *)(this + 0x18);
        *(undefined4 *)(this + 0x18) = *(undefined4 *)(this + 0x1c);
      }
      else {
        __ZdaPv(page);
      }
      *(void **)(this + 0x1c) = nextPage;
      page = nextPage;
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
int TPoolAllocator__allocate(this, numBytes)
  unsigned char * this;
  ulong numBytes;
{
  int allocationResult;
  uint pageSizeReload;
  undefined4 *allocation;
  float guardBlockSizeF;
  undefined4 prevPage;
  ulong pageSize;
  undefined4 *page;
  uint endOffset;
  int allocationSize;
  ulong multiPageSize;
  
  guardBlockSizeF = TAllocation__guardBlockSize;
  allocationResult = *(int *)(this + 0x14);
  allocationSize = numBytes + (int)TAllocation__guardBlockSize * 2;
  pageSize = *(ulong *)(this + 4);
  endOffset = allocationResult + allocationSize;
  *(int *)(this + 0x2c) = *(int *)(this + 0x2c) + 1;
  *(ulong *)(this + 0x30) = *(int *)(this + 0x30) + numBytes;
  if (pageSize < endOffset) {
    multiPageSize = allocationSize + *(int *)(this + 0x10);
    if (pageSize < multiPageSize) {
      allocation = operator_new__(multiPageSize);
      allocationResult = 0;
      if (allocation != (undefined4 *)0x0) {
        pageSizeReload = *(uint *)(this + 4);
        *allocation = *(undefined4 *)(this + 0x1c);
        allocation[1] = ((multiPageSize + pageSizeReload) - 1) / pageSizeReload;
        allocationResult = (int)allocation + *(int *)(this + 0x10);
        *(undefined4 **)(this + 0x1c) = allocation;
        *(undefined4 *)(this + 0x14) = *(undefined4 *)(this + 4);
      }
    }
    else {
      page = *(undefined4 **)(this + 0x18);
      if (page == (undefined4 *)0x0) {
        page = operator_new__(pageSize);
        if (page == (undefined4 *)0x0) {
          return 0;
        }
      }
      else {
        *(undefined4 *)(this + 0x18) = *page;
      }
      prevPage = *(undefined4 *)(this + 0x1c);
      page[1] = 1;
      *page = prevPage;
      allocationResult = (int)page + (int)TAllocation__guardBlockSize + *(int *)(this + 0x10);
      *(uint *)(this + 0x14) =
           *(int *)(this + 0x10) + allocationSize + *(uint *)(this + 0xc) & ~*(uint *)(this + 0xc);
      *(undefined4 **)(this + 0x1c) = page;
    }
  }
  else {
    *(uint *)(this + 0x14) = endOffset + *(uint *)(this + 0xc) & ~*(uint *)(this + 0xc);
    allocationResult = *(int *)(this + 0x1c) + allocationResult + (int)GH_F2U(guardBlockSizeF);
  }
  return allocationResult;
}

/* TAllocation__checkAllocList @ 0x97ba03dc (156 bytes) */
int TAllocation__checkAllocList(this)
  unsigned char * this;
{
  byte beginVal;
  byte endVal;
  float guardBlockSizeF;
  undefined4 allocationSize;
  
  guardBlockSizeF = guardBlockSize;
  endVal = guardBlockEndVal;
  beginVal = guardBlockBeginVal;
  for (; this != (unsigned char *)0x0; this = *(unsigned char **)(this + 8)) {
    allocationSize = *(undefined4 *)(this + 4);
    ((int (*)())TAllocation__checkGuardBlock)((uchar *)this,(uchar)allocationSize,(char *)(uint)beginVal);
    ((int (*)())TAllocation__checkGuardBlock)((uchar *)this,(uchar)allocationSize + SUB41(guardBlockSizeF,0) + (char)*(undefined4 *)this,
                    (char *)(uint)endVal);
  }
  return;
}

/* QualifierWritten @ 0x97ba0478 (156 bytes) */
int QualifierWritten(intermNode, qualifier, scratchR5, scratchR6, scratchR7, scratchR8, scratchR9, scratchR10)
  unsigned char * intermNode;
  undefined4 qualifier;
  undefined4 scratchR5;
  undefined4 scratchR6;
  undefined4 scratchR7;
  undefined4 scratchR8;
  undefined4 scratchR9;
  undefined4 scratchR10;
{
  undefined4 visitSymbolFn;
  undefined4 visitConstantUnionFn;
  undefined4 visitBinaryFn;
  undefined4 visitUnaryFn;
  undefined4 visitSelectionFn;
  undefined4 visitAggregateFn;
  undefined4 visitLoopFn;
  undefined4 visitBranchFn;
  undefined4 depth;
  undefined4 preVisit;
  undefined4 postVisit;
  undefined4 rightToLeft;
  undefined4 found;
  undefined4 wantedQualifier;
  
  found = 0;
  visitSymbolFn = ptrTo_AliveSymbol_a7b7ba24;
  visitSelectionFn = ptrTo_AliveSelection_a7b7ba20;
  rightToLeft = 1;
  visitConstantUnionFn = 0;
  visitBinaryFn = 0;
  visitUnaryFn = 0;
  visitAggregateFn = 0;
  visitLoopFn = 0;
  visitBranchFn = 0;
  depth = 0;
  preVisit = 1;
  postVisit = 0;
  if (intermNode != (unsigned char *)0x0) {
    wantedQualifier = qualifier;
    (**(code **)(*(int *)intermNode + 8))
              (intermNode,&visitSymbolFn,scratchR5,scratchR6,scratchR7,scratchR8,ptrTo_AliveSelection_a7b7ba20,intermNode);
  }
  return found;
}

/* AliveSymbol @ 0x97ba0514 (76 bytes) */
int AliveSymbol(intermSymbol, intermTraverser)
  unsigned char * intermSymbol;
  unsigned char * intermTraverser;
{
  int symbolQualifier;
  
  symbolQualifier = (**(code **)(*(int *)intermSymbol + 0x44))(intermSymbol);
  if (symbolQualifier == *(int *)(intermTraverser + 0x34)) {
    *(undefined4 *)(intermTraverser + 0x30) = 1;
  }
  return;
}

/* AliveSelection @ 0x97ba0560 (16 bytes) */
int AliveSelection(preVisit, intermSelection, intermTraverser)
  int preVisit;
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
int RemoveBinary(preVisit, intermBinary, intermTraverser)
  int preVisit;
  unsigned char * intermBinary;
  unsigned char * intermTraverser;
{
  if (intermBinary != (unsigned char *)0x0) {
    (**(code **)(*(int *)intermBinary + 0x30))(intermBinary);
  }
  return 1;
}

/* RemoveUnary @ 0x97ba05c0 (56 bytes) */
int RemoveUnary(preVisit, intermUnary, intermTraverser)
  int preVisit;
  unsigned char * intermUnary;
  unsigned char * intermTraverser;
{
  if (intermUnary != (unsigned char *)0x0) {
    (**(code **)(*(int *)intermUnary + 0x30))(intermUnary);
  }
  return 1;
}

/* RemoveAggregate @ 0x97ba05f8 (56 bytes) */
int RemoveAggregate(preVisit, intermAggregate, intermTraverser)
  int preVisit;
  unsigned char * intermAggregate;
  unsigned char * intermTraverser;
{
  if (intermAggregate != (unsigned char *)0x0) {
    (**(code **)(*(int *)intermAggregate + 0x30))(intermAggregate);
  }
  return 1;
}

/* RemoveSelection @ 0x97ba0630 (56 bytes) */
int RemoveSelection(preVisit, intermSelection, intermTraverser)
  int preVisit;
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
  undefined4 scratchR5;
  undefined4 scratchR6;
  undefined4 scratchR7;
  undefined4 scratchR8;
  undefined4 visitSymbolFn;
  undefined4 visitConstantUnionFn;
  undefined4 visitBinaryFn;
  undefined4 visitUnaryFn;
  undefined4 visitSelectionFn;
  undefined4 visitAggregateFn;
  undefined4 visitLoopFn;
  undefined4 visitBranchFn;
  undefined4 depth;
  undefined4 preVisit;
  undefined4 postVisit;
  undefined4 rightToLeft;
  
  visitAggregateFn = ptrTo_RemoveAggregate_a7b7ba3c;
  visitBinaryFn = ptrTo_RemoveBinary_a7b7ba38;
  visitConstantUnionFn = ptrTo_RemoveConstantUnion_a7b7ba34;
  visitSelectionFn = ptrTo_RemoveSelection_a7b7ba30;
  postVisit = 1;
  visitSymbolFn = ptrTo_RemoveSymbol_a7b7ba2c;
  visitUnaryFn = ptrTo_RemoveUnary_a7b7ba28;
  preVisit = 0;
  visitLoopFn = 0;
  visitBranchFn = 0;
  depth = 0;
  rightToLeft = 0;
  return (**(code **)(*(int *)intermNode + 8))
            (intermNode,&visitSymbolFn,scratchR5,scratchR6,scratchR7,scratchR8,ptrTo_RemoveUnary_a7b7ba28,*(int *)intermNode);
}

/* GetSymbolTable @ 0x97ba0728 (132 bytes) */
int GetSymbolTable(languageIndex)
  int languageIndex;
{
  undefined4 *slotCursor;
  undefined4 *allocation;
  
  slotCursor = &GetSymbolTable__SymbolTables;
  if (GetSymbolTable__SymbolTables == 0) {
    do {
      allocation = operator_new(0x10);
      *allocation = 0;
      allocation[1] = 0;
      allocation[2] = 0;
      allocation[3] = 0;
      *slotCursor = allocation;
      slotCursor = slotCursor + 1;
    } while ((int)slotCursor < -0x584817f7);
  }
  return (&GetSymbolTable__SymbolTables)[languageIndex];
}

/* GetResources @ 0x97ba07ac (108 bytes) */
int GetResources()
{
  builtInResourceMaxDrawBuffers_a7b7e838 = 4;
  builtInResourceMaxClipPlanes_a7b7e810 = 6;
  builtInResourceMaxTextureCoords_a7b7e818 = 8;
  builtInResourceMaxVaryingFloats_a7b7e824 = 0x20;
  builtInResourceMaxVertexTextureImageUnits_a7b7e828 = 0;
  builtInResourceMaxTextureImageUnits_a7b7e830 = 0x10;
  builtInResourceMaxFragmentUniformComponents_a7b7e834 = 0x200;
  GetResources__Resources = 8;
  builtInResourceMaxTextureUnits_a7b7e814 = 8;
  builtInResourceMaxVertexAttribs_a7b7e81c = 0x10;
  builtInResourceMaxVertexUniformComponents_a7b7e820 = 0x200;
  builtInResourceMaxCombinedTextureImageUnits_a7b7e82c = 0x10;
  return &GetResources__Resources;
}

/* _ShInitialize @ 0x97ba0818 (360 bytes) */
int _ShInitialize()
{
  int *refCountPtr;
  int initProcessResult;
  int atomicStore;
  int atomicStore2;
  int *emptyRepRefCount;
  int oldRefCount;
  unsigned char * savedPoolAllocator;
  unsigned char * perProcessAllocator;
  unsigned char * builtInResources;
  undefined4 result;
  char reservation;
  byte cr0Reg;
  undefined *emptyStringData1;
  undefined4 emptyStringAllocator1;
  undefined *emptyStringData2;
  undefined4 emptyStringAllocator2;
  undefined1 destroyAllocatorArg [28];
  
  emptyStringData1 = PTR__S_empty_rep_storage_a7b7c0f0;
  emptyRepRefCount = (int *)(PTR__S_empty_rep_storage_a7b7c0f0 + 8);
  do {
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(*emptyRepRefCount + 1,0,emptyRepRefCount);
      *emptyRepRefCount = atomicStore;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  emptyStringData1 = emptyStringData1 + 0xc;
  emptyStringAllocator1 = 4;
  do {
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(*emptyRepRefCount + 1,0,emptyRepRefCount);
      *emptyRepRefCount = atomicStore;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  emptyStringAllocator2 = 4;
  emptyStringData2 = emptyStringData1;
  _pthread_mutex_lock(&_glsl_allocator_lock);
  initProcessResult = InitProcess();
  result = 1;
  if (initProcessResult == 0) {
    result = 0;
  }
  else if (_PerProcessGPA == (unsigned char *)0x0) {
    savedPoolAllocator = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
    perProcessAllocator = operator_new(0x34);
    ((int (*)())__ZN14TPoolAllocatorC1Ebii)(perProcessAllocator,1,0x2000,0x10);
    _PerProcessGPA = perProcessAllocator;
    ((int (*)())TPoolAllocator__push)(perProcessAllocator);
    ((int (*)())SetGlobalPoolAllocatorPtr)(_PerProcessGPA);
    builtInResources = (unsigned char *)((int (*)())GetResources)();
    ((int (*)())generateBuiltInSymbolTable)(builtInResources,(unsigned char *)&emptyStringData1,(unsigned char *)0x0,4);
    ((int (*)())SetGlobalPoolAllocatorPtr)(savedPoolAllocator);
  }
  _pthread_mutex_unlock(&_glsl_allocator_lock);
  refCountPtr = (int *)(emptyStringData2 + -4);
  do {
    oldRefCount = *refCountPtr;
    if (reservation != '\0') {
      atomicStore2 = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
      *refCountPtr = atomicStore2;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  if (oldRefCount < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(emptyStringData2 + -0xc),destroyAllocatorArg);
  }
  refCountPtr = (int *)(emptyStringData1 + -4);
  do {
    oldRefCount = *refCountPtr;
    if (reservation != '\0') {
      atomicStore2 = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
      *refCountPtr = atomicStore2;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  if (oldRefCount < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(emptyStringData1 + -0xc),destroyAllocatorArg);
  }
  return result;
}

/* _ShConstructCompiler @ 0x97ba0980 (32 bytes) */
int _ShConstructCompiler(language, debugOptions)
  undefined4 language;
  undefined4 debugOptions;
{
  return ConstructCompiler(language,debugOptions);
}

/* _ShDestruct @ 0x97ba09a4 (200 bytes) */
int _ShDestruct(handle)
  int *handle;
{
  int linkerObj;
  int compilerObj;
  unsigned char * compilerToDelete;
  unsigned char * linkerToDelete;
  
  if (handle != (int *)0x0) {
    _pthread_mutex_lock(&_glsl_allocator_lock);
    compilerObj = (**(code **)(*handle + 8))(handle);
    if (compilerObj == 0) {
      linkerObj = (**(code **)(*handle + 0xc))(handle);
      if (linkerObj != 0) {
        linkerToDelete = (unsigned char *)(**(code **)(*handle + 0xc))(handle);
        DeleteLinker(linkerToDelete);
      }
    }
    else {
      compilerToDelete = (unsigned char *)(**(code **)(*handle + 8))(handle);
      DeleteCompiler(compilerToDelete);
    }
    _pthread_mutex_unlock(&_glsl_allocator_lock);
    return;
  }
  return;
}

/* _ShFinalize @ 0x97ba0a6c (112 bytes) */
int _ShFinalize()
{
  unsigned char * perProcessAllocator;
  
  if (_PerProcessGPA != (unsigned char *)0x0) {
    ((int (*)())TPoolAllocator__popAll)(_PerProcessGPA);
    perProcessAllocator = _PerProcessGPA;
    if (_PerProcessGPA != (unsigned char *)0x0) {
      ((int (*)())__ZN14TPoolAllocatorD1Ev)(_PerProcessGPA);
      __ZdlPv(perProcessAllocator);
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
  unsigned char builtIns [28];
  
  __ZN9TBuiltIns10initializeERK16TBuiltInResource(builtIns,builtInResource);
  ((int (*)())initializeSymbolTable)((unsigned char *)builtIns,0,infoSink,builtInResource,symbolTable);
  ((int (*)())initializeSymbolTable)((unsigned char *)builtIns,1,infoSink,builtInResource,symbolTable);
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
  undefined4 *destroyArg;
  int *levelsFinish;
  int finishValue;
  int *refCountPtr;
  int oldRefCount;
  int paParseStringsResult;
  int initPreprocessorResult;
  int atomicStore2;
  int *stringSizeArray;
  int numStrings;
  int atomicStore;
  int *emptyRepRefCount;
  int levelCount;
  unsigned char * this;
  unsigned char * poolAllocator;
  undefined4 *newLevel;
  undefined4 *levelRoot;
  uint numStringArrays;
  char **stringArray;
  undefined4 result;
  uint arrayIndex;
  char reservation;
  byte cr0Reg;
  byte cr0Flags;
  void **pcIntermediate;
  unsigned char * pcSymbolTable;
  void *pcInfoSink;
  int pcLanguage;
  undefined4 pcTreeRoot;
  undefined4 pcRecoveredFromError;
  undefined4 pcNumErrors;
  undefined4 pcWord14;
  undefined4 pcWord18;
  undefined4 pcWord1c;
  unsigned char * extBehaviorAllocator;
  undefined4 *extBehaviorHeader;
  int extBehaviorCount;
  undefined4 pcFlagOne;
  undefined4 pcFlagZero;
  unsigned char * pragmaMapAllocator;
  undefined4 *pragmaMapHeader;
  int pragmaMapCount;
  undefined4 emptyStringAllocator;
  int emptyStringChars;
  unsigned char * extBehaviorAllocatorCopy;
  unsigned char * pragmaMapAllocatorCopy;
  undefined4 emptyStringAllocatorCopy;
  unsigned char * levelAllocator;
  undefined4 *levelSlot [4];
  undefined4 destroyArgA [4];
  undefined4 destroyArgB [4];
  undefined4 destroyArgC [4];
  void *intermediateStorage [7];
  
  intermediateStorage[0] = infoSink;
  this = (unsigned char *)((int (*)())GetSymbolTable)(language);
  pcIntermediate = intermediateStorage;
  pcTreeRoot = 0;
  pcRecoveredFromError = 0;
  pcNumErrors = 0;
  pcWord14 = 0;
  pcWord18 = 0;
  pcWord1c = 0;
  pcSymbolTable = this;
  pcInfoSink = infoSink;
  pcLanguage = language;
  extBehaviorAllocator = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
  extBehaviorHeader = (undefined4 *)0x0;
  extBehaviorAllocatorCopy = extBehaviorAllocator;
  extBehaviorHeader = (undefined4 *)((int (*)())TPoolAllocator__allocate)(extBehaviorAllocator,0x1c);
  extBehaviorCount = 0;
  *extBehaviorHeader = 0;
  extBehaviorHeader[1] = 0;
  extBehaviorHeader[2] = extBehaviorHeader;
  extBehaviorHeader[3] = extBehaviorHeader;
  pcFlagOne = 1;
  pcFlagZero = 0;
  pragmaMapAllocator = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
  pragmaMapHeader = (undefined4 *)0x0;
  pragmaMapAllocatorCopy = pragmaMapAllocator;
  pragmaMapHeader = (undefined4 *)((int (*)())TPoolAllocator__allocate)(pragmaMapAllocator,0x20);
  pragmaMapCount = 0;
  *pragmaMapHeader = 0;
  pragmaMapHeader[1] = 0;
  emptyStringChars = emptyStringRepPtr_a7b7ba70;
  pragmaMapHeader[2] = pragmaMapHeader;
  emptyRepRefCount = (int *)(emptyStringChars + 8);
  pragmaMapHeader[3] = pragmaMapHeader;
  do {
    if (reservation != '\0') {
      atomicStore2 = storeWordConditionalIndexed(*emptyRepRefCount + 1,0,emptyRepRefCount);
      *emptyRepRefCount = atomicStore2;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  emptyStringAllocator = ((int (*)())GetGlobalPoolAllocator)();
  emptyStringChars = emptyStringChars + 0xc;
  emptyStringAllocatorCopy = emptyStringAllocator;
  setInitialState();
  levelCount = *(int *)(this + 4) - *(int *)this >> 2;
  cr0Flags = (levelCount != 0) << 1;
  if ((levelCount != 0) && (levelCount != 1)) {
    ___eprintf("%s:%u: failed assertion `%s\'\n",
               "/SourceCache/OpenGL/OpenGL-4.7.14/GLProgrammability/glslang/MachineIndependent/ShaderLang.cpp"
               ,0x110,"symbolTable->isEmpty() || symbolTable->atSharedBuiltInLevel()");
  }
  poolAllocator = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
  newLevel = (undefined4 *)((int (*)())TPoolAllocator__allocate)(poolAllocator,0x10);
  levelAllocator = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
  *newLevel = levelAllocator;
  newLevel[1] = 0;
  levelRoot = (undefined4 *)((int (*)())TPoolAllocator__allocate)(levelAllocator,0x1c);
  newLevel[2] = 0;
  newLevel[1] = levelRoot;
  *levelRoot = 0;
  *(undefined4 *)(newLevel[1] + 4) = 0;
  *(undefined4 *)(newLevel[1] + 8) = newLevel[1];
  *(undefined4 *)(newLevel[1] + 0xc) = newLevel[1];
  levelsFinish = *(int **)(this + 4);
  levelSlot[0] = newLevel;
  if (levelsFinish == *(int **)(this + 8)) {
    std__vector_TSymbolTableLevel__std__allocator_TSymbolTableLevel______M_insert_aux
              (this,levelsFinish,levelSlot);
  }
  else {
    finishValue = 0;
    if (levelsFinish != (int *)0x0) {
      *levelsFinish = (int)newLevel;
      finishValue = *(int *)(this + 4);
    }
    *(int *)(this + 4) = finishValue + 4;
  }
  initPreprocessorResult = _InitPreprocessor();
  if (initPreprocessorResult == 0) {
    numStringArrays = TBuiltIns__getNumStringArrays(builtIns,pcLanguage);
    arrayIndex = 0;
    if (numStringArrays != 0) {
loopSetStringArray:
      stringArray = (char **)TBuiltIns__getStringArray(builtIns,pcLanguage,arrayIndex);
      stringSizeArray = (int *)TBuiltIns__getStringSizeArray(builtIns,pcLanguage,arrayIndex);
      numStrings = TBuiltIns__getNumStrings(builtIns,pcLanguage,arrayIndex);
      paParseStringsResult = PaParseStrings(stringArray,stringSizeArray,numStrings,0,(unsigned char *)&pcIntermediate);
      if (paParseStringsResult == 0) goto setArrayIndex;
                    
      __ZN13TInfoSinkBase6appendEPKc(infoSink,"INTERNAL ERROR: ");
      __ZN13TInfoSinkBase6appendEPKc(infoSink,"Unable to parse built-ins");
      __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
      _FinalizePreprocessor();
      refCountPtr = (int *)(emptyStringChars + -4);
      destroyArgB[0] = emptyStringAllocator;
      do {
        oldRefCount = *refCountPtr;
        if (reservation != '\0') {
          atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
          *refCountPtr = atomicStore;
          cr0Flags = 2;
        }
      } while (!(bool)(cr0Flags >> 1 & 1));
      if (oldRefCount < 1) {
        destroyArg = destroyArgB;
        goto code_r0x97ba0f54;
      }
      goto code_r0x97ba0f58;
    }
loopCallZ16IdentifyBuiltIns11EShLanguageR12TSymbolTableRK16TBuiltInResource:
    __Z16IdentifyBuiltIns11EShLanguageR12TSymbolTableRK16TBuiltInResource(pcLanguage,this,builtInResource);
    __Z16IdentifyBuiltIns11EShLanguageR12TSymbolTable(pcLanguage,this);
    _FinalizePreprocessor();
    refCountPtr = (int *)(emptyStringChars + -4);
    destroyArgA[0] = emptyStringAllocator;
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
                ((unsigned char *)(emptyStringChars + -0xc),destroyArgA);
    }
    if (pragmaMapCount != 0) {
      std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string______M_erase((unsigned char
                  *)&pragmaMapAllocator,(unsigned char *)pragmaMapHeader[1]);
      pragmaMapHeader[2] = pragmaMapHeader;
      pragmaMapHeader[1] = 0;
      pragmaMapHeader[3] = pragmaMapHeader;
      pragmaMapCount = 0;
    }
    if (extBehaviorCount != 0) {
      std___Rb_tree_std__string_std__pair_std__string_const_TBehavior__std___Select1st_std__pair_std__string_const_TBehavior___std__less_std__string__pool_allocator_std__pair_std__string_const_TBehavior______M_erase((unsigned char
                  *)&extBehaviorAllocator,(unsigned char *)extBehaviorHeader[1]);
      extBehaviorHeader[2] = extBehaviorHeader;
      extBehaviorHeader[1] = 0;
      extBehaviorHeader[3] = extBehaviorHeader;
    }
    result = 1;
  }
  else {
                    
    __ZN13TInfoSinkBase6appendEPKc(infoSink,"INTERNAL ERROR: ");
    __ZN13TInfoSinkBase6appendEPKc(infoSink,"Unable to intialize the Preprocessor");
    __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
    refCountPtr = (int *)(emptyStringChars + -4);
    destroyArgC[0] = emptyStringAllocator;
    do {
      oldRefCount = *refCountPtr;
      if (reservation != '\0') {
        atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
        *refCountPtr = atomicStore;
        cr0Flags = 2;
      }
    } while (!(bool)(cr0Flags >> 1 & 1));
    destroyArg = destroyArgC;
    if (oldRefCount < 1) {
code_r0x97ba0f54:
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(emptyStringChars + -0xc),destroyArg);
    }
code_r0x97ba0f58:
    if (pragmaMapCount != 0) {
      std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string______M_erase((unsigned char
                  *)&pragmaMapAllocator,(unsigned char *)pragmaMapHeader[1]);
      pragmaMapHeader[2] = pragmaMapHeader;
      pragmaMapHeader[1] = 0;
      pragmaMapHeader[3] = pragmaMapHeader;
      pragmaMapCount = 0;
    }
    if (extBehaviorCount != 0) {
      std___Rb_tree_std__string_std__pair_std__string_const_TBehavior__std___Select1st_std__pair_std__string_const_TBehavior___std__less_std__string__pool_allocator_std__pair_std__string_const_TBehavior______M_erase((unsigned char
                  *)&extBehaviorAllocator,(unsigned char *)extBehaviorHeader[1]);
      extBehaviorHeader[2] = extBehaviorHeader;
      extBehaviorHeader[1] = 0;
      extBehaviorHeader[3] = extBehaviorHeader;
    }
    result = 0;
  }
  return result;
setArrayIndex:
  arrayIndex = arrayIndex + 1;
  if (numStringArrays <= arrayIndex) goto loopCallZ16IdentifyBuiltIns11EShLanguageR12TSymbolTableRK16TBuiltInResource;
  goto loopSetStringArray;
}

/* _ShCompile @ 0x97ba10c8 (1888 bytes) */
int _ShCompile(handle, str, numStrings, optLevel, debugOptions)
  int *handle;
  char **str;
  int numStrings;
  int optLevel;
  uint debugOptions;
{
  void *levelsBase;
  undefined4 *newLevel2;
  undefined4 *newLevel1;
  char *messageText;
  char *infoLogChars;
  int levelCount;
  int parseResult;
  int atomicStoreB;
  bool noDebugOutput;
  int *refCountPtr;
  int oldRefCount;
  int paParseStringsResult;
  int insertBuiltInArrayAtGlobalLevelResult;
  bool levelCountTooBig;
  int atomicStore;
  int stringRepLength;
  int *emptyRepRefCount;
  uint levelCount2;
  int *compiler;
  unsigned char * poolAllocator;
  undefined4 *symbolTableForLanguage;
  undefined4 *levelRoot;
  void *infoSinkRef;
  void *levelToDestroy;
  char *infoSinkChars;
  uint success;
  char *stringRepData;
  uint *this;
  char reservation;
  byte cr0Flags;
  void *symbolTableLevelsBegin;
  int *symbolTableLevelsEnd;
  int *symbolTableLevelsCapacityEnd;
  undefined4 symbolTableNextId;
  unsigned char * levelAllocator1;
  undefined4 *newLevelSlot [4];
  int *parseContextIntermediate;
  unsigned char * symbolTableLevelsPtr;
  void *infoSink;
  int language;
  unsigned char * treeRoot;
  int errorFlag;
  undefined4 numErrors;
  undefined4 pcWord14;
  undefined4 pcWord18;
  undefined4 pcWord1c;
  unsigned char * extensionBehaviorAllocator;
  undefined4 *extensionBehaviorHeader;
  int extensionBehaviorCount;
  undefined4 extBehaviorFlagOne;
  undefined4 extBehaviorFlagZero;
  unsigned char * stringMapAllocator;
  undefined4 *stringMapHeader;
  int stringMapCount;
  undefined4 emptyStringAllocator;
  int emptyStringChars;
  unsigned char * extBehaviorAllocatorCopy;
  unsigned char * stringMapAllocatorCopy;
  undefined4 emptyStringAllocatorCopy;
  unsigned char * levelAllocator2;
  undefined4 numErrorsString;
  int numErrorsStringChars;
  char numErrorsTextBuf [16];
  undefined4 allocatorArgN [4];
  undefined4 numErrorsDestroyArg [4];
  undefined4 destroyArg [4];
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
  poolAllocator = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
  ((int (*)())TPoolAllocator__push)(poolAllocator);
  (**(code **)(*compiler + 0x18))(compiler);
  this = (uint *)compiler[1];
  stringRepData = (char *)*this;
  stringRepLength = *(int *)(stringRepData + -0xc);
  infoSinkChars = (char *)*this;
  if (((*(int *)(infoSinkChars + -4) < 1) && (infoSinkChars <= stringRepData)) && (stringRepData <= infoSinkChars + stringRepLength)) {
    __ZNSs10_M_replaceIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_St18input_iterator_tag
              (this,infoSinkChars,infoSinkChars + stringRepLength,stringRepData,stringRepData,0);
  }
  else {
    __ZNSs15_M_replace_safeIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_
              (this,infoSinkChars,infoSinkChars + stringRepLength,stringRepData,stringRepData);
  }
  infoLogChars = *(char **)(compiler[1] + 8);
  __ZNSs7replaceEmmPKcm((void *)(compiler[1] + 8),0,*(ulong *)(infoLogChars + -0xc),infoLogChars,0);
  if (numStrings == 0) {
    _pthread_mutex_unlock(&_glsl_allocator_lock);
    return 1;
  }
  intermediate = compiler[1];
  symbolTableForLanguage = (undefined4 *)((int (*)())GetSymbolTable)(compiler[2]);
  symbolTableLevelsBegin = (void *)0x0;
  symbolTableLevelsEnd = (int *)0x0;
  symbolTableLevelsCapacityEnd = (int *)0x0;
  std__vector_TSymbolTableLevel__std__allocator_TSymbolTableLevel______M_insert_aux
            ((unsigned char *)&symbolTableLevelsBegin,0,*symbolTableForLanguage);
  symbolTableNextId = symbolTableForLanguage[3];
  poolAllocator = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
  newLevel1 = (undefined4 *)((int (*)())TPoolAllocator__allocate)(poolAllocator,0x10);
  levelAllocator1 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
  *newLevel1 = levelAllocator1;
  newLevel1[1] = 0;
  levelRoot = (undefined4 *)((int (*)())TPoolAllocator__allocate)(levelAllocator1,0x1c);
  newLevel1[2] = 0;
  newLevel1[1] = levelRoot;
  *levelRoot = 0;
  *(undefined4 *)(newLevel1[1] + 4) = 0;
  *(undefined4 *)(newLevel1[1] + 8) = newLevel1[1];
  *(undefined4 *)(newLevel1[1] + 0xc) = newLevel1[1];
  newLevelSlot[0] = newLevel1;
  if (symbolTableLevelsEnd == symbolTableLevelsCapacityEnd) {
    std__vector_TSymbolTableLevel__std__allocator_TSymbolTableLevel______M_insert_aux
              ((unsigned char *)&symbolTableLevelsBegin,symbolTableLevelsEnd
               ,newLevelSlot);
  }
  else {
    if (symbolTableLevelsEnd != (int *)0x0) {
      *symbolTableLevelsEnd = (int)newLevel1;
    }
    symbolTableLevelsEnd = symbolTableLevelsEnd + 1;
  }
  infoSink = (void *)compiler[1];
  language = compiler[2];
  parseContextIntermediate = &intermediate;
  treeRoot = (unsigned char *)0x0;
  errorFlag = 0;
  numErrors = 0;
  pcWord14 = 0;
  pcWord18 = 0;
  pcWord1c = 0;
  symbolTableLevelsPtr = (unsigned char *)&symbolTableLevelsBegin;
  extensionBehaviorAllocator = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
  extensionBehaviorHeader = (undefined4 *)0x0;
  extBehaviorAllocatorCopy = extensionBehaviorAllocator;
  extensionBehaviorHeader = (undefined4 *)((int (*)())TPoolAllocator__allocate)(extensionBehaviorAllocator,0x1c);
  extensionBehaviorCount = 0;
  *extensionBehaviorHeader = 0;
  extensionBehaviorHeader[1] = 0;
  extensionBehaviorHeader[2] = extensionBehaviorHeader;
  extensionBehaviorHeader[3] = extensionBehaviorHeader;
  extBehaviorFlagOne = 1;
  extBehaviorFlagZero = 0;
  stringMapAllocator = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
  stringMapHeader = (undefined4 *)0x0;
  stringMapAllocatorCopy = stringMapAllocator;
  stringMapHeader = (undefined4 *)((int (*)())TPoolAllocator__allocate)(stringMapAllocator,0x20);
  stringMapCount = 0;
  *stringMapHeader = 0;
  emptyStringChars = emptyStringRepPtr_a7b7ba70;
  stringMapHeader[1] = 0;
  emptyRepRefCount = (int *)(emptyStringChars + 8);
  stringMapHeader[2] = stringMapHeader;
  stringMapHeader[3] = stringMapHeader;
  do {
    if (reservation != '\0') {
      atomicStoreB = storeWordConditionalIndexed(*emptyRepRefCount + 1,0,emptyRepRefCount);
      *emptyRepRefCount = atomicStoreB;
      cr0Flags = 2;
    }
  } while (!(bool)(cr0Flags >> 1 & 1));
  emptyStringAllocator = ((int (*)())GetGlobalPoolAllocator)();
  emptyStringChars = emptyStringChars + 0xc;
  emptyStringAllocatorCopy = emptyStringAllocator;
  ((int (*)())TParseContext__initializeExtensionBehavior)((unsigned char *)&parseContextIntermediate);
  setInitialState();
  _InitPreprocessor();
  poolAllocator = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
  newLevel2 = (undefined4 *)((int (*)())TPoolAllocator__allocate)(poolAllocator,0x10);
  levelAllocator2 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
  *newLevel2 = levelAllocator2;
  newLevel2[1] = 0;
  levelRoot = (undefined4 *)((int (*)())TPoolAllocator__allocate)(levelAllocator2,0x1c);
  newLevel2[2] = 0;
  newLevel2[1] = levelRoot;
  *levelRoot = 0;
  *(undefined4 *)(newLevel2[1] + 4) = 0;
  *(undefined4 *)(newLevel2[1] + 8) = newLevel2[1];
  *(undefined4 *)(newLevel2[1] + 0xc) = newLevel2[1];
  newLevelSlot[0] = newLevel2;
  if (symbolTableLevelsEnd == symbolTableLevelsCapacityEnd) {
    std__vector_TSymbolTableLevel__std__allocator_TSymbolTableLevel______M_insert_aux
              ((unsigned char *)&symbolTableLevelsBegin,symbolTableLevelsEnd
               ,newLevelSlot);
  }
  else {
    if (symbolTableLevelsEnd != (int *)0x0) {
      *symbolTableLevelsEnd = (int)newLevel2;
    }
    symbolTableLevelsEnd = symbolTableLevelsEnd + 1;
  }
  infoSinkRef = infoSink;
  levelCountTooBig = 3 < (uint)((int)symbolTableLevelsEnd - (int)symbolTableLevelsBegin >> 2);
  if (levelCountTooBig) {
    __ZN13TInfoSinkBase6appendEPKc(infoSink,"INTERNAL ERROR: ");
    __ZN13TInfoSinkBase6appendEPKc(infoSinkRef,"Wrong symbol table level. No code generated.");
    __ZN13TInfoSinkBase6appendEPKc(infoSinkRef,"\n");
  }
  success = (uint)!levelCountTooBig;
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
  parseResult = PaParseStrings(str,(int *)0x0,numStrings,0,(unsigned char *)&parseContextIntermediate);
  infoSinkRef = infoSink;
  if (parseResult != 0) {
    success = 0;
  }
  if ((success == 1) && (treeRoot != (unsigned char *)0x0)) {
    if (errorFlag == 0) {
      success = TIntermediate__postProcess((unsigned char *)&intermediate,treeRoot);
      infoSinkRef = infoSink;
      if (success != 1) {
        __ZN13TInfoSinkBase6appendEPKc(infoSink,"INTERNAL ERROR: ");
        __ZN13TInfoSinkBase6appendEPKc
                  (infoSinkRef,"Parse tree post-processing failure. No code generated.");
        __ZN13TInfoSinkBase6appendEPKc(infoSinkRef,"\n");
        goto callTIntermediate_remove;
      }
      if (optLevel != 0) {
        noDebugOutput = (debugOptions & 1) == 0;
        cr0Flags = noDebugOutput << 1;
        if (!noDebugOutput) {
          TIntermediate__outputTree((unsigned char *)&intermediate,treeRoot);
        }
        (**(code **)(*compiler + 0x34))(compiler,optLevel);
        (**(code **)(*compiler + 0x38))(compiler,debugOptions);
        parseResult = (**(code **)(*compiler + 0x14))(compiler,treeRoot);
        if (parseResult != 0) goto callTIntermediate_remove;
        goto setSuccess;
      }
      __ZN13TInfoSinkBase6appendEPKc
                (infoSink,"No errors.  No code generation or linking was requested.");
      messageText = "\n";
    }
    else {
      __ZN13TInfoSinkBase6appendEPKc(infoSink,"ERROR: ");
      infoSinkRef = infoSink;
      _sprintf(numErrorsTextBuf,"%d",numErrors);
      allocatorArgN[0] = ((int (*)())GetGlobalPoolAllocator)();
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                ((unsigned char *)&numErrorsString,numErrorsTextBuf,(unsigned char *)allocatorArgN);
      __ZN13TInfoSinkBase6appendERKSbIcSt11char_traitsIcE14pool_allocatorIcEE
                (infoSinkRef,(unsigned char *)&numErrorsString);
      refCountPtr = (int *)(numErrorsStringChars + -4);
      numErrorsDestroyArg[0] = numErrorsString;
      do {
        parseResult = *refCountPtr;
        if (reservation != '\0') {
          atomicStore = storeWordConditionalIndexed(parseResult + -1,0,refCountPtr);
          *refCountPtr = atomicStore;
          cr0Flags = 2;
        }
      } while (!(bool)(cr0Flags >> 1 & 1));
      if (parseResult < 1) {
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                  ((unsigned char *)(numErrorsStringChars + -0xc),numErrorsDestroyArg);
      }
      messageText = " compilation errors. No code generated.";
      success = 0;
    }
    __ZN13TInfoSinkBase6appendEPKc(infoSinkRef,messageText);
    noDebugOutput = (debugOptions & 1) == 0;
    cr0Flags = noDebugOutput << 1;
    if (!noDebugOutput) {
      TIntermediate__outputTree((unsigned char *)&intermediate,treeRoot);
    }
  }
  else {
    if (treeRoot != (unsigned char *)0x0) goto callTIntermediate_remove;
    __ZN13TInfoSinkBase6appendEPKc(infoSink,"ERROR: ");
    __ZN13TInfoSinkBase6appendEPKc(infoSinkRef,"Parser found no code to compile in source strings.");
    __ZN13TInfoSinkBase6appendEPKc(infoSinkRef,"\n");
setSuccess:
    success = 0;
  }
callTIntermediate_remove:
  TIntermediate__remove((unsigned char *)&intermediate,treeRoot);
  levelsBase = symbolTableLevelsBegin;
  for (; parseResult = (int)symbolTableLevelsEnd - (int)levelsBase >> 2, parseResult != 1; symbolTableLevelsEnd = symbolTableLevelsEnd + -1) {
    levelToDestroy = *(void **)((int)levelsBase + (parseResult + -1) * 4);
    if (levelToDestroy != (void *)0x0) {
      __ZN17TSymbolTableLevelD1Ev(levelToDestroy);
      levelsBase = symbolTableLevelsBegin;
    }
  }
  _FinalizePreprocessor();
  poolAllocator = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
  ((int (*)())TPoolAllocator__pop)(poolAllocator);
  _pthread_mutex_unlock(&_glsl_allocator_lock);
  refCountPtr = (int *)(emptyStringChars + -4);
  destroyArg[0] = emptyStringAllocator;
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
              ((unsigned char *)(emptyStringChars + -0xc),destroyArg);
  }
  if (stringMapCount != 0) {
    std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string______M_erase((unsigned char
                *)&stringMapAllocator,(unsigned char *)stringMapHeader[1]);
    stringMapHeader[2] = stringMapHeader;
    stringMapHeader[1] = 0;
    stringMapHeader[3] = stringMapHeader;
    stringMapCount = 0;
  }
  levelsBase = symbolTableLevelsBegin;
  if (extensionBehaviorCount != 0) {
    std___Rb_tree_std__string_std__pair_std__string_const_TBehavior__std___Select1st_std__pair_std__string_const_TBehavior___std__less_std__string__pool_allocator_std__pair_std__string_const_TBehavior______M_erase((unsigned char
                *)&extensionBehaviorAllocator,(unsigned char *)extensionBehaviorHeader[1]);
    extensionBehaviorHeader[2] = extensionBehaviorHeader;
    extensionBehaviorHeader[1] = 0;
    extensionBehaviorHeader[3] = extensionBehaviorHeader;
    extensionBehaviorCount = 0;
    levelsBase = symbolTableLevelsBegin;
  }
  for (; levelCount2 = (int)symbolTableLevelsEnd - (int)levelsBase >> 2, 1 < levelCount2; symbolTableLevelsEnd = symbolTableLevelsEnd + -1) {
    levelToDestroy = *(void **)((int)levelsBase + (levelCount2 - 1) * 4);
    if (levelToDestroy != (void *)0x0) {
      __ZN17TSymbolTableLevelD1Ev(levelToDestroy);
      levelsBase = symbolTableLevelsBegin;
    }
  }
  levelCount = (int)symbolTableLevelsCapacityEnd - (int)levelsBase >> 2;
  if (levelCount != 0) {
    std____default_alloc_template_true_0___deallocate(levelsBase,levelCount << 2);
  }
  return success;
}

/* _ShLink @ 0x97ba1a6c (284 bytes) */
int _ShLink(handle, shaderHandles, numShaders, linkerWord80, linkerWord7c)
  int *handle;
  void **shaderHandles;
  int numShaders;
  undefined4 linkerWord80;
  undefined4 linkerWord7c;
{
  int linkResult;
  int *shaderCompiler;
  unsigned char * this;
  int *shaderHandle;
  int hasObjectCode;
  char *messagePrefix;
  char *messageText;
  int shaderIndex;
  void *infoSink;
  
  if ((handle != (int *)0x0) &&
     (this = (unsigned char *)(**(code **)(*handle + 0xc))(handle), this != (unsigned char *)0x0
     )) {
    messagePrefix = (char *)**(undefined4 **)(this + 0x84);
    __ZNSs7replaceEmmPKcm(*(undefined4 **)(this + 0x84),0,*(ulong *)(messagePrefix + -0xc),messagePrefix,0);
    messagePrefix = *(char **)(*(int *)(this + 0x84) + 8);
    __ZNSs7replaceEmmPKcm((void *)(*(int *)(this + 0x84) + 8),0,*(ulong *)(messagePrefix + -0xc),messagePrefix,0);
    shaderIndex = 0;
    TGenericLinker__reset(this);
    if (0 < numShaders) {
      do {
        shaderHandle = shaderHandles[shaderIndex];
        if (shaderHandle == (int *)0x0) {
          infoSink = *(void **)(this + 0x84);
          messageText = "Invalid shader passed to linker (internal error).";
          messagePrefix = "INTERNAL ERROR: ";
                    
loopCallZN13TInfoSinkBase6appendEPKc:
          __ZN13TInfoSinkBase6appendEPKc(infoSink,messagePrefix);
          __ZN13TInfoSinkBase6appendEPKc(infoSink,messageText);
          __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
          return 0;
        }
        shaderCompiler = (int *)(**(code **)(*shaderHandle + 8))(shaderHandle);
        if ((shaderCompiler != (int *)0x0) && (hasObjectCode = (**(code **)(*shaderCompiler + 0x20))(shaderCompiler), hasObjectCode == 0)) {
          infoSink = *(void **)(this + 0x84);
          messageText = "Not all shaders have valid object code.";
                    
          messagePrefix = "ERROR: ";
          goto loopCallZN13TInfoSinkBase6appendEPKc;
        }
        shaderIndex = shaderIndex + 1;
      } while (shaderIndex < numShaders);
    }
    *(undefined4 *)(this + 0x80) = linkerWord80;
    *(undefined4 *)(this + 0x7c) = linkerWord7c;
    linkResult = TGenericLinker__link(this,shaderHandles,numShaders);
    if (linkResult != 0) {
      return 1;
    }
  }
  return 0;
}

/* ShSetEncryptionMethod @ 0x97ba1c68 (4 bytes) */
int ShSetEncryptionMethod(unusedArg1)
  void *unusedArg1;
{
  return;
}

