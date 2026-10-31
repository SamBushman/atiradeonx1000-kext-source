#include "decls.h"

/* __ZN17TPPStreamCompilerD1Ev @ 0x97bc97dc (8 bytes) */
int __ZN17TPPStreamCompilerD1Ev(this)
  void *this;
{
  return ((int (*)())__ZN17TPPStreamCompilerD4Ev)(this,2);
}

/* __ZN17TPPStreamCompilerD0Ev @ 0x97bc97e4 (8 bytes) */
int __ZN17TPPStreamCompilerD0Ev(this)
  void *this;
{
  return ((int (*)())__ZN17TPPStreamCompilerD4Ev)(this,3);
}

/* __ZN17TPPStreamCompilerD4Ev @ 0x97bc97ec (536 bytes) */
int __ZN17TPPStreamCompilerD4Ev(this, deleteFlags)
  void *this;
  uint deleteFlags;
{
  int stringRep;
  int atomicStore;
  int *refCountPtr;
  int oldRefCount;
  int emptyTest;
  void *owned;
  char reservation;
  byte cr0Reg;
  undefined1 stringAllocator [24];
  
  *(int *)this = DAT_a7b7bd98 + 8;
  ConstantAllocationList__clear((unsigned char *)((int)this + 0x44));
  while( true ) {
    emptyTest = size((unsigned char *)((int)this + 0x4c));
    if (emptyTest == 0) break;
    fetch((unsigned char *)((int)this + 0x4c));
  }
  while (emptyTest = ParseFunctionStack__empty((unsigned char *)((int)this + 0x58)), emptyTest == 0) {
    ParseFunctionStack__pop((unsigned char *)((int)this + 0x58));
  }
  owned = *(void **)((int)this + 0x6c);
  if (owned != (void *)0x0) {
    ((int (*)())__ZN13FunctionTableD1Ev)(owned);
    __ZdlPv(owned);
  }
  owned = *(void **)((int)this + 0x68);
  if (owned != (void *)0x0) {
    __ZN16ParseSymbolTableD1Ev(owned);
    __ZdlPv(owned);
  }
  if (*(int *)((int)this + 0x70) != 0) {
    _PPStreamFree(*(int *)((int)this + 0x70));
  }
  if (*(int *)((int)this + 0x78) != 0) {
    _free(*(int *)((int)this + 0x78));
  }
  if (*(int *)((int)this + 0x7c) != 0) {
    _free(*(int *)((int)this + 0x7c));
  }
  if (*(int *)((int)this + 0x80) != 0) {
    _free(*(int *)((int)this + 0x80));
  }
  if (*(int *)((int)this + 0x84) != 0) {
    _free(*(int *)((int)this + 0x84));
  }
  owned = *(void **)((int)this + 0x60);
  if (owned != (void *)0x0) {
    __ZN18TemporaryAllocatorD1Ev(owned);
    __ZdlPv(owned);
  }
  *(undefined4 *)PTR_temporaryAllocator_a7b7c0fc = 0;
  owned = *(void **)((int)this + 100);
  if (owned != (void *)0x0) {
    __ZN20AddressTempAllocatorD1Ev(owned);
    __ZdlPv(owned);
  }
  *(undefined4 *)PTR_addressTempAllocator_a7b7c0f8 = 0;
  if (*(int *)((int)this + 0x74) != 0) {
    _free(*(int *)((int)this + 0x74));
  }
  stringRep = *(int *)((int)this + 0xb8);
  refCountPtr = (int *)(stringRep + -4);
  do {
    oldRefCount = *refCountPtr;
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
      *refCountPtr = atomicStore;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  if (oldRefCount < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(stringRep + -0xc),stringAllocator);
  }
  stringRep = *(int *)((int)this + 0xb0);
  refCountPtr = (int *)(stringRep + -4);
  do {
    oldRefCount = *refCountPtr;
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
      *refCountPtr = atomicStore;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  if (oldRefCount < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(stringRep + -0xc),stringAllocator);
  }
  __ZN22ConstantAllocationListD1Ev((unsigned char *)((int)this + 0x44));
  *(undefined ***)this = &PTR___ZN9TCompilerD1Ev_a7b7d850;
  __ZN14TPoolAllocatorD1Ev((void *)((int)this + 0x10));
  *(undefined ***)this = &PTR___ZN13TShHandleBaseD1Ev_a7b7d898;
  if ((deleteFlags & 1) != 0) {
    __ZdlPv(this);
  }
  return;
}

/* TPPStreamCompiler__error @ 0x97bc9a04 (304 bytes) */
int TPPStreamCompiler__error(this, formatSelect, locationText, format, vaArg1, vaArg2, vaArg3, vaArg4)
  int this;
  char *formatSelect;
  char *locationText;
  char *format;
  undefined4 vaArg1;
  undefined4 vaArg2;
  undefined4 vaArg3;
  undefined4 vaArg4;
{
  unsigned int ghidra_home[8] = { this, formatSelect, locationText, format, vaArg1, vaArg2, vaArg3, vaArg4 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  char *formatWithLocation;
  char *formatPlain;
  int messageLength;
  char *lineBuffer;
  int locationLength;
  char message [264];
  
  locationLength = 0;
  (*(unsigned int *)((unsigned char *)ghidra_home + 16)) = vaArg1;
  (*(unsigned int *)((unsigned char *)ghidra_home + 20)) = vaArg2;
  (*(unsigned int *)((unsigned char *)ghidra_home + 24)) = vaArg3;
  (*(unsigned int *)((unsigned char *)ghidra_home + 28)) = vaArg4;
  _vsprintf(message,format,&(*(unsigned int *)((unsigned char *)ghidra_home + 16)));
  if (locationText != (char *)0x0) {
    locationLength = _strlen(locationText);
  }
  messageLength = _strlen(message);
  lineBuffer = (char *)_malloc(messageLength + locationLength + 0x28);
  formatWithLocation = DAT_a7b7bd20;
  formatPlain = DAT_a7b7bd24;
  if (formatSelect != (char *)0x0) {
    formatWithLocation = DAT_a7b7bd18;
    formatPlain = DAT_a7b7bd1c;
  }
  if (locationText == (char *)0x0) {
    _sprintf(lineBuffer,formatPlain,*(undefined4 *)(this + 0x90),message);
  }
  else {
    _sprintf(lineBuffer,formatWithLocation,*(undefined4 *)(this + 0x90),locationText,message);
  }
  __ZN13TInfoSinkBase6appendEPKc((void *)(this + 0xb0),lineBuffer);
  __ZN13TInfoSinkBase6appendEPKc((void *)(this + 0xb0),"\n");
  _free(lineBuffer);
  *(undefined4 *)(this + 0xa0) = 1;
  return;
}

/* TPPStreamCompiler__warning @ 0x97bc9b34 (296 bytes) */
int TPPStreamCompiler__warning(this, formatSelect, locationText, format, vaArg1, vaArg2, vaArg3, vaArg4)
  int this;
  char *formatSelect;
  char *locationText;
  char *format;
  undefined4 vaArg1;
  undefined4 vaArg2;
  undefined4 vaArg3;
  undefined4 vaArg4;
{
  unsigned int ghidra_home[8] = { this, formatSelect, locationText, format, vaArg1, vaArg2, vaArg3, vaArg4 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  char *formatWithLocation;
  char *formatPlain;
  int messageLength;
  char *lineBuffer;
  int locationLength;
  char message [268];
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 16)) = vaArg1;
  (*(unsigned int *)((unsigned char *)ghidra_home + 20)) = vaArg2;
  (*(unsigned int *)((unsigned char *)ghidra_home + 24)) = vaArg3;
  (*(unsigned int *)((unsigned char *)ghidra_home + 28)) = vaArg4;
  _vsprintf(message,format,&(*(unsigned int *)((unsigned char *)ghidra_home + 16)));
  locationLength = 0;
  if (locationText != (char *)0x0) {
    locationLength = _strlen(locationText);
  }
  messageLength = _strlen(message);
  lineBuffer = (char *)_malloc(messageLength + locationLength + 0x28);
  formatWithLocation = DAT_a7b7bd34;
  formatPlain = DAT_a7b7bd38;
  if (formatSelect != (char *)0x0) {
    formatWithLocation = DAT_a7b7bd2c;
    formatPlain = DAT_a7b7bd30;
  }
  if (locationText == (char *)0x0) {
    _sprintf(lineBuffer,formatPlain,*(undefined4 *)(this + 0x90),message);
  }
  else {
    _sprintf(lineBuffer,formatWithLocation,*(undefined4 *)(this + 0x90),locationText,message);
  }
  __ZN13TInfoSinkBase6appendEPKc((void *)(this + 0xb0),lineBuffer);
  __ZN13TInfoSinkBase6appendEPKc((void *)(this + 0xb0),"\n");
  return _free(lineBuffer);
}

/* TPPStreamCompiler__getSymbolTableString @ 0x97bc9c5c (196 bytes) */
int TPPStreamCompiler__getSymbolTableString(this, style)
  unsigned char * this;
  int style;
{
  undefined4 string;
  int length;
  char *allocation;
  char *headerFormat;
  
  if (*(unsigned char **)(this + 0x68) == (unsigned char *)0x0) {
    return (char *)0x0;
  }
  string = ParseSymbolTable__GetString(*(unsigned char **)(this + 0x68),style);
  length = _strlen(string);
  allocation = (char *)_malloc(length + 0x17);
  *allocation = '\0';
  headerFormat = DAT_a7b7bd64;
  if (style != 1) {
    if (style < 2) {
      headerFormat = DAT_a7b7bd60;
      if (style != 0) goto callFree;
    }
    else {
      headerFormat = DAT_a7b7bd68;
      if (style != 2) goto callFree;
    }
  }
  _sprintf(allocation,headerFormat,string);
callFree:
  _free(string);
  return allocation;
}

/* TPPStreamCompiler__dumpSymbolTableInfo @ 0x97bc9d20 (220 bytes) */
int TPPStreamCompiler__dumpSymbolTableInfo(this, style)
  unsigned char * this;
  int style;
{
  char *string;
  char *headerFormat;
  
  headerFormat = DAT_a7b7bd70;
  if (style != 1) {
    if (style < 2) {
      headerFormat = DAT_a7b7bd6c;
      if (style != 0) goto setString;
    }
    else {
      headerFormat = DAT_a7b7bd74;
      if (style != 2) goto setString;
    }
  }
  __ZN13TInfoSinkBase6appendEPKc(this + 0xb0,headerFormat);
setString:
  string = (char *)ParseSymbolTable__GetString(*(unsigned char **)(this + 0x68),style);
  if (string == (char *)0x0) {
    return;
  }
  __ZN13TInfoSinkBase6appendEPKc(this + 0xb0,string);
  __ZN13TInfoSinkBase6appendEPKc(this + 0xb0,DAT_a7b7bd78);
  _free(string);
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
  undefined4 ppStreamCreateResult;
  void *allocation;
  undefined4 *ppStream;
  undefined4 shaderEnum;
  int stage;
  void *owned;
  
  *(undefined4 *)(this + 0xc) = 0;
  if (*(int *)(this + 0x78) != 0) {
    _free(*(int *)(this + 0x78));
  }
  *(undefined4 *)(this + 0x78) = 0;
  if (*(int *)(this + 0x7c) != 0) {
    _free(*(int *)(this + 0x7c));
  }
  *(undefined4 *)(this + 0x7c) = 0;
  if (*(int *)(this + 0x80) != 0) {
    _free(*(int *)(this + 0x80));
  }
  *(undefined4 *)(this + 0x80) = 0;
  if (*(int *)(this + 0x84) != 0) {
    _free(*(int *)(this + 0x84));
  }
  owned = *(void **)(this + 0x68);
  *(undefined4 *)(this + 0x84) = 0;
  if (owned != (void *)0x0) {
    __ZN16ParseSymbolTableD1Ev(owned);
    __ZdlPv(owned);
  }
  allocation = operator_new(0x54);
  __ZN16ParseSymbolTableC1Ej(allocation,0x80);
  *(void **)(this + 0x68) = allocation;
  *(undefined4 *)((int)allocation + 0x3c) = *(undefined4 *)(this + 8);
  owned = *(void **)(this + 0x6c);
  if (owned != (void *)0x0) {
    ((int (*)())__ZN13FunctionTableD1Ev)(owned);
    __ZdlPv(owned);
  }
  allocation = operator_new(8);
  ((int (*)())__ZN13FunctionTableC1Ev)(allocation);
  *(void **)(this + 0x6c) = allocation;
  if (*(int *)(this + 0x70) != 0) {
    _PPStreamFree(*(int *)(this + 0x70));
  }
  ppStreamCreateResult = _PPStreamCreate();
  *(undefined4 *)(this + 0x70) = ppStreamCreateResult;
  *(undefined4 *)(*(int *)(this + 0x68) + 0xc) = ppStreamCreateResult;
  stage = *(int *)(this + 8);
  if (stage == 0) {
    ppStream = *(undefined4 **)(this + 0x70);
    shaderEnum = 0x8b31;
  }
  else {
    if (stage != 1) {
      return;
    }
    ppStream = *(undefined4 **)(this + 0x70);
    shaderEnum = 0x8b30;
  }
  *ppStream = shaderEnum;
  *(int *)(this + 0xa4) = stage;
  return;
}

/* TPPStreamCompiler__compile @ 0x97bc9f44 (332 bytes) */
int TPPStreamCompiler__compile(this, intermNode)
  unsigned char * this;
  unsigned char * intermNode;
{
  int compileResult;
  int opChunk;
  int parseIntermediateTreeResult;
  uint opWord;
  int ppStream;
  undefined4 allocation;
  char *pPStreamString;
  uint carryBits;
  int streamEntryCount [5];
  
  parseIntermediateTreeResult = TPPStreamCompiler__parseIntermediateTree(this,intermNode);
  *(int *)(this + 0xc) = parseIntermediateTreeResult;
  if (parseIntermediateTreeResult != 0) {
    ppStream = *(int *)(this + 0x70);
    carryBits = 0;
    opChunk = **(int **)(ppStream + 0x20);
    if (opChunk != 0) {
      do {
        opWord = *(uint *)(opChunk + 0xc);
        *(uint *)(opChunk + 0xc) = carryBits << 0x1a | opWord & 0xe3ffffff;
        carryBits = opWord >> 0x1d;
        opChunk = *(int *)(opChunk + 8);
      } while (opChunk != 0);
      ppStream = *(int *)(this + 0x70);
    }
    _PPStreamResolveBranches(ppStream);
    if (*(int *)(this + 0x74) != 0) {
      _free(*(int *)(this + 0x74));
    }
    *(undefined4 *)(this + 0x74) = 0;
    _PPStreamGetStream(*(undefined4 *)(this + 0x70),0,streamEntryCount);
    if (streamEntryCount[0] != 0) {
      allocation = _malloc(streamEntryCount[0] * 8 + 0xfU & 0xfffffff0);
      *(undefined4 *)(this + 0x74) = allocation;
      _PPStreamGetStream(*(undefined4 *)(this + 0x70),allocation,streamEntryCount);
    }
  }
  compileResult = *(int *)(this + 0xc);
  if ((compileResult != 0) && ((*(uint *)(this + 0xc0) & 0x10) != 0)) {
    ((int (*)())TPPStreamCompiler__dumpSymbolTableInfo)(this,2);
    compileResult = *(int *)(this + 0xc);
  }
  if ((compileResult != 0) && ((*(uint *)(this + 0xc0) & 2) != 0)) {
    __ZN13TInfoSinkBase6appendEPKc(this + 0xb0,DAT_a7b7bd80);
    pPStreamString = (char *)(**(code **)(*(int *)this + 0x28))(this);
    __ZN13TInfoSinkBase6appendEPKc(this + 0xb0,pPStreamString);
    compileResult = *(int *)(this + 0xc);
  }
  return compileResult;
}

/* TPPStreamCompiler__getStatsString @ 0x97bca090 (108 bytes) */
int TPPStreamCompiler__getStatsString(this)
  unsigned char * this;
{
  int length;
  undefined4 placeholderText;
  int statsString;
  undefined4 allocation;
  
  placeholderText = DAT_a7b7bd84;
  statsString = *(int *)(this + 0x78);
  if (statsString == 0) {
    length = _strlen(DAT_a7b7bd84);
    allocation = _malloc(length * 4 + 4);
    *(undefined4 *)(this + 0x78) = allocation;
    _strcpy(allocation,placeholderText);
    statsString = *(int *)(this + 0x78);
  }
  return statsString;
}

/* TPPStreamCompiler__getPPStreamString @ 0x97bca0fc (144 bytes) */
int TPPStreamCompiler__getPPStreamString(this)
  unsigned char * this;
{
  undefined4 placeholderText;
  void *ppStreamString;
  int length;
  undefined4 allocation;
  
  placeholderText = DAT_a7b7bd88;
  ppStreamString = *(void **)(this + 0x7c);
  if (ppStreamString == (void *)0x0) {
    if ((*(int *)(this + 0xc) == 0) || (*(int *)(this + 0x74) == 0)) {
      length = _strlen(DAT_a7b7bd88);
      allocation = _malloc(length * 4 + 4);
      *(undefined4 *)(this + 0x7c) = allocation;
      _strcpy(allocation,placeholderText);
      ppStreamString = *(void **)(this + 0x7c);
    }
    else {
      ppStreamString = _glpPPDisassemble(*(int *)(this + 0x74));
      *(void **)(this + 0x7c) = ppStreamString;
    }
  }
  return ppStreamString;
}

/* TPPStreamCompiler__getShaderToProgramString @ 0x97bca18c (148 bytes) */
int TPPStreamCompiler__getShaderToProgramString(this)
  unsigned char * this;
{
  int length;
  int programString;
  undefined4 allocation;
  
  programString = *(int *)(this + 0x80);
  if (programString == 0) {
    if ((*(int *)(this + 0xc) == 0) || (*(int *)(this + 0x74) == 0)) {
      length = _strlen("No Shader Program generated.");
      allocation = _malloc(length * 4 + 4);
      *(undefined4 *)(this + 0x80) = allocation;
      _strcpy(allocation,"No Shader Program generated.");
      programString = *(int *)(this + 0x80);
    }
    else {
      programString = _glpPPShaderToProgramString(*(int *)(this + 0x74),0,0);
      *(int *)(this + 0x80) = programString;
    }
  }
  return programString;
}

/* TPPStreamCompiler__getTableString @ 0x97bca220 (72 bytes) */
int TPPStreamCompiler__getTableString(this)
  unsigned char * this;
{
  int tableString;
  
  tableString = *(int *)(this + 0x84);
  if (tableString == 0) {
    tableString = ((int (*)())TPPStreamCompiler__getSymbolTableString)(this,2);
    *(int *)(this + 0x84) = tableString;
  }
  return tableString;
}

/* ConstructCompiler @ 0x97bca268 (72 bytes) */
int ConstructCompiler(language, optionFlags)
  undefined4 language;
  undefined4 optionFlags;
{
  void *this;
  
  this = operator_new(200);
  __ZN17TPPStreamCompilerC1E11EShLanguagei(this,language,optionFlags);
  return this;
}

/* DeleteCompiler @ 0x97bca2b0 (24 bytes) */
int DeleteCompiler(compiler)
  unsigned char * compiler;
{
  if (compiler == (unsigned char *)0x0) {
    return;
  }
                    
                    
  (**(code **)(*(int *)compiler + 4))(compiler);
  return;
}

/* GetBuiltInInitialSwizzle @ 0x97bca2c8 (748 bytes) */
int GetBuiltInInitialSwizzle(parseSymbol)
  unsigned char * parseSymbol;
{
  int fieldValue;
  bool hashMatches;
  char *charPtr;
  int nameLength;
  int weightedChar;
  int charWeight;
  int charIndex;
  int nameHash;
  
  nameLength = *(int *)(parseSymbol + 0x20);
  nameHash = 0;
  charIndex = 0;
  if (0 < nameLength) {
    charWeight = 3;
    do {
      charPtr = (char *)(*(int *)(parseSymbol + 0x14) + charIndex);
      charIndex = charIndex + 1;
      weightedChar = *charPtr * charWeight;
      charWeight = charWeight + 2;
      nameHash = nameHash + weightedChar;
      nameLength = nameLength + -1;
    } while (nameLength != 0);
  }
  if (nameHash == 0x18ec7) {
    return 3;
  }
  if (nameHash < 0x18ec8) {
    if (nameHash == 0x17e27) {
      return 3;
    }
    if (0x17e27 < nameHash) {
      if (nameHash == 0x17ecc) {
        return 3;
      }
      if (nameHash < 0x17ecd) {
        if (nameHash == 0x17e69) {
          return 3;
        }
        if (nameHash < 0x17e6a) {
          fieldValue = 0x17e48;
        }
        else {
          if (nameHash == 0x17e8a) {
            return 3;
          }
          fieldValue = 0x17eab;
        }
      }
      else {
        if (nameHash == 0x18e64) {
          return 3;
        }
        if (nameHash < 0x18e65) {
          if (nameHash == 0x17eed) {
            return 3;
          }
          fieldValue = 0x18e43;
        }
        else {
          if (nameHash == 0x18e85) {
            return 3;
          }
          fieldValue = 0x18ea6;
        }
      }
loopCheckNameHash:
      if (nameHash == fieldValue) {
        return 3;
      }
      return 0;
    }
    if (nameHash == 0x71c3) {
      return 2;
    }
    if (nameHash < 0x71c4) {
      if (nameHash == 0x3f94) {
        return 3;
      }
      if (0x3f94 < nameHash) {
        if (nameHash == 0x42d8) {
          return 1;
        }
        hashMatches = nameHash == 0x7171;
        goto checkHashMatches;
      }
      hashMatches = nameHash == 0x2c25;
      goto checkHashMatches2;
    }
    if (nameHash == 0x8837) {
      return 2;
    }
    if (0x8837 < nameHash) {
      if (nameHash == 0x12304) {
        return 3;
      }
      fieldValue = 0x17e06;
      goto loopCheckNameHash;
    }
    hashMatches = nameHash == 0x7a53;
    goto checkHashMatches;
  }
  if (nameHash == 0x2043a) {
    return 1;
  }
  if (nameHash < 0x2043b) {
    if (nameHash == 0x20374) {
      return 1;
    }
    if (nameHash < 0x20375) {
      if (nameHash == 0x18f09) {
        return 3;
      }
      if (nameHash < 0x18f0a) {
        fieldValue = 0x18ee8;
        goto loopCheckNameHash;
      }
      if (nameHash == 0x18f2a) {
        return 3;
      }
      fieldValue = 0x1f1a8;
    }
    else {
      if (nameHash == 0x203d7) {
        return 1;
      }
      if (nameHash < 0x203d8) {
        if (nameHash == 0x20395) {
          return 1;
        }
        fieldValue = 0x203b6;
      }
      else {
        if (nameHash == 0x203f8) {
          return 1;
        }
        fieldValue = 0x20419;
      }
    }
loopSetHashMatches:
    hashMatches = nameHash == fieldValue;
checkHashMatches:
    if (hashMatches) {
      return 1;
    }
    return 0;
  }
  if (nameHash == 0x2614d) {
    return 2;
  }
  if (nameHash < 0x2614e) {
    if (nameHash == 0x24cb9) {
      return 2;
    }
    if (nameHash < 0x24cba) {
      fieldValue = 0x2045b;
      goto loopSetHashMatches;
    }
    if (nameHash == 0x2610b) {
      return 2;
    }
    fieldValue = 0x2612c;
  }
  else {
    if (nameHash == 0x261b0) {
      return 2;
    }
    if (nameHash < 0x261b1) {
      if (nameHash == 0x2616e) {
        return 2;
      }
      fieldValue = 0x2618f;
    }
    else {
      if (nameHash == 0x261d1) {
        return 2;
      }
      fieldValue = 0x261f2;
    }
  }
  hashMatches = nameHash == fieldValue;
checkHashMatches2:
  if (hashMatches) {
    return 2;
  }
  return 0;
}

/* GetBuiltInChunkForSymbol @ 0x97bca5b4 (8452 bytes) */
int GetBuiltInChunkForSymbol(parseSymbol, shaderStage)
  unsigned char * parseSymbol;
  int shaderStage;
{
  int fieldValue;
  uint directIndex;
  bool hashMatches;
  char *charPtr;
  int nameLength;
  int weightedChar;
  uint chunkWordTexcoord;
  uint chunkWord;
  int charWeight;
  undefined4 chunkType;
  undefined1 directIndex2;
  int charIndex;
  int nameHash;
  int chunk;
  
  chunk = 0;
  nameLength = *(int *)(parseSymbol + 0x20);
  nameHash = 0;
  charIndex = 0;
  if (0 < nameLength) {
    charWeight = 3;
    do {
      charPtr = (char *)(*(int *)(parseSymbol + 0x14) + charIndex);
      charIndex = charIndex + 1;
      weightedChar = *charPtr * charWeight;
      charWeight = charWeight + 2;
      nameHash = nameHash + weightedChar;
      nameLength = nameLength + -1;
    } while (nameLength != 0);
  }
  if (nameHash == 0x10f9c) {
    chunk = _PPStreamChunkCreateWithType(3,0);
    chunkWord = *(uint *)(chunk + 0xc) & 0xffe0fff9 | 0x50009;
    goto loopStoreChunk2;
  }
  if (nameHash < 0x10f9d) {
    if (nameHash == 0x81d5) goto setChunk3;
    if (nameHash < 0x81d6) {
      if (nameHash == 0x5a70) {
loopSetChunk:
        chunk = _PPStreamChunkCreateWithType(3,0);
        fieldValue = 7;
        chunkWord = *(uint *)(chunk + 0xc);
loopSetChunkWord:
        chunkWord = fieldValue << 0x10 | chunkWord & 0xffe0ff3f | 0x20;
loopStoreChunk:
        *(uint *)(chunk + 0xc) = chunkWord;
        directIndex = ParseSymbol__GetDirectIndex(parseSymbol,0);
        chunkWord = directIndex & 0x1f | *(uint *)(chunk + 0xc) & 0xffffffe0;
      }
      else if (nameHash < 0x5a71) {
        if (nameHash == 0x504e) {
          chunk = _PPStreamChunkCreateWithType(4,0);
          fieldValue = 9;
          chunkWord = *(uint *)(chunk + 0xc);
        }
        else {
          if (nameHash < 0x504f) {
            if (nameHash == 0x4209) {
loopSetChunkType:
              chunkType = 2;
loopSetChunk2:
              chunk = _PPStreamChunkCreateWithType(chunkType,0);
              fieldValue = 1;
            }
            else if (nameHash < 0x420a) {
              if (nameHash != 0x383f) {
                if (nameHash < 0x3840) {
                  if (nameHash == 0x280f) {
                    chunkType = 2;
loopSetChunk3:
                    chunk = _PPStreamChunkCreateWithType(chunkType,0);
                    fieldValue = 4;
                    goto loopSetChunkWord3;
                  }
                  if (nameHash < 0x2810) {
                    if (nameHash != 0x2099) goto storeParseSymbol;
                    chunkType = 2;
                    goto setChunk2;
                  }
                  if (nameHash == 0x297a) goto loopSetChunkType;
                  if (nameHash != 0x2c25) goto storeParseSymbol;
                }
                else if (nameHash != 0x3f94) {
                  if (nameHash < 0x3f95) {
                    if (nameHash != 0x3bf9) goto storeParseSymbol;
                    chunkType = 4;
                    goto loopSetChunk2;
                  }
                  if (nameHash == 0x41d9) {
                    chunk = _PPStreamChunkCreateWithType(3,0);
                    fieldValue = 0xb;
                    goto loopSetChunkWord5;
                  }
                  if (nameHash != 0x4203) goto storeParseSymbol;
                  chunk = _PPStreamChunkCreateWithType(4,0);
                  fieldValue = 7;
                  goto loopSetChunkWord3;
                }
loopSetChunk4:
                chunk = _PPStreamChunkCreateWithType(3,0);
                fieldValue = 0xc;
                goto loopSetChunkWord5;
              }
loopSetChunk5:
              chunk = _PPStreamChunkCreateWithType(2,0);
              fieldValue = 5;
            }
            else {
              if (nameHash == 0x4dd3) goto loopSetChunk9;
              if (0x4dd3 < nameHash) {
                if (nameHash != 0x4ee0) {
                  if (nameHash < 0x4ee1) {
                    if ((nameHash != 0x4eaa) && (nameHash != 0x4ec5)) goto storeParseSymbol;
                  }
                  else if (nameHash != 0x4efb) {
                    if (nameHash != 0x4fb4) goto storeParseSymbol;
                    chunk = _PPStreamChunkCreateWithType(4,0);
                    fieldValue = 4;
                    chunkWord = *(uint *)(chunk + 0xc);
loopSetChunkWord2:
                    chunkWord = fieldValue << 0x10 | chunkWord & 0xfff0fffe;
                    goto loopStoreChunk2;
                  }
                }
                chunk = _PPStreamChunkCreateWithType(4,0);
                *(uint *)(chunk + 0xc) = *(uint *)(chunk + 0xc) & 0xfff0ffff | 0x40000;
                directIndex = ParseSymbol__GetDirectIndex(parseSymbol,0);
                chunkWord = (directIndex & 7) << 1 | *(uint *)(chunk + 0xc) & 0xfffffff1;
                goto loopStoreChunk2;
              }
              if (nameHash == 0x42d8) goto loopSetChunk4;
              if (nameHash < 0x42d9) {
                if (nameHash != 0x425a) goto storeParseSymbol;
                chunk = _PPStreamChunkCreateWithType(4,0);
                fieldValue = 4;
                chunkWord = *(uint *)(chunk + 0xc);
                goto setChunkWord3;
              }
              if (nameHash == 0x42e3) {
                chunkType = 4;
                goto loopSetChunk3;
              }
              if (nameHash != 0x4493) goto storeParseSymbol;
              chunkType = 4;
loopSetChunk6:
              chunk = _PPStreamChunkCreateWithType(chunkType,0);
              fieldValue = 3;
            }
          }
          else {
            if (nameHash != 0x58a1) {
              if (0x58a1 < nameHash) {
                if (nameHash != 0x5a3e) {
                  if (nameHash < 0x5a3f) {
                    if (nameHash != 0x5a21) {
                      if (nameHash < 0x5a22) {
                        hashMatches = nameHash == 0x5a08;
loopCheckHashMatches:
                        if (!hashMatches) goto storeParseSymbol;
                      }
                      else if (nameHash != 0x5a25) {
                        hashMatches = nameHash == 0x5a3a;
                        goto loopCheckHashMatches3;
                      }
                      goto loopSetChunk8;
                    }
                  }
                  else {
                    if (nameHash == 0x5a57) goto loopSetChunk7;
                    if (nameHash < 0x5a58) {
                      if (nameHash != 0x5a42) {
                        hashMatches = nameHash == 0x5a53;
                        goto loopCheckHashMatches4;
                      }
                      goto loopSetChunk8;
                    }
                    if (nameHash != 0x5a5b) {
                      hashMatches = nameHash == 0x5a5f;
                      goto loopCheckHashMatches;
                    }
                  }
                }
                goto setChunk;
              }
              if (nameHash != 0x5214) {
                if (nameHash < 0x5215) {
                  if (nameHash != 0x51c3) {
                    if (nameHash < 0x51c4) {
                      hashMatches = nameHash == 0x51a8;
                    }
                    else {
                      if (nameHash == 0x51de) goto checkShaderStage;
                      hashMatches = nameHash == 0x51f9;
                    }
loopCheckHashMatches2:
                    if (!hashMatches) goto storeParseSymbol;
                  }
                }
                else if (nameHash != 0x524a) {
                  if (nameHash < 0x524b) {
                    hashMatches = nameHash == 0x522f;
                    goto loopCheckHashMatches2;
                  }
                  if (nameHash != 0x5265) {
                    if (nameHash != 0x5811) goto storeParseSymbol;
                    chunk = _PPStreamChunkCreateWithType(3,0);
                    fieldValue = 0x12;
                    goto loopSetChunkWord5;
                  }
                }
              }
checkShaderStage:
              if (shaderStage == 0) {
                chunk = _PPStreamChunkCreateWithType(4,0);
                fieldValue = 6;
                chunkWord = *(uint *)(chunk + 0xc);
              }
              else {
                chunk = _PPStreamChunkCreateWithType(2,0);
                fieldValue = 7;
                chunkWord = *(uint *)(chunk + 0xc);
              }
              chunkWord = fieldValue << 0x10 | chunkWord & 0xfff0ffff;
              goto loopStoreChunk;
            }
            chunk = _PPStreamChunkCreateWithType(2,0);
            fieldValue = 0xb;
          }
loopSetChunkWord3:
          chunkWord = *(uint *)(chunk + 0xc);
        }
        chunkWord = fieldValue << 0x10 | chunkWord & 0xfff0ffff;
      }
      else {
        if (nameHash == 0x5b05) goto loopSetChunk7;
        if (nameHash < 0x5b06) {
          if (nameHash != 0x5ab2) {
            if (nameHash < 0x5ab3) {
              if (nameHash == 0x5a91) {
loopSetChunk7:
                chunk = _PPStreamChunkCreateWithType(3,0);
                fieldValue = 7;
                chunkWord = *(uint *)(chunk + 0xc);
loopSetChunkWord4:
                chunkWord = fieldValue << 0x10 | chunkWord & 0xffe0ff1f;
                goto loopStoreChunk;
              }
              if (nameHash < 0x5a92) {
                if (nameHash != 0x5a78) {
                  if (0x5a78 < nameHash) {
                    if (nameHash != 0x5a7c) {
                      hashMatches = nameHash == 0x5a8d;
                      goto loopCheckHashMatches4;
                    }
                    goto loopSetChunk8;
                  }
                  hashMatches = nameHash == 0x5a74;
loopCheckHashMatches3:
                  if (!hashMatches) goto storeParseSymbol;
                  goto loopSetChunk7;
                }
              }
              else {
                if (nameHash == 0x5a99) {
loopSetChunk8:
                  chunk = _PPStreamChunkCreateWithType(3,0);
                  fieldValue = 7;
                  chunkWord = *(uint *)(chunk + 0xc);
                  goto setChunkWord;
                }
                if (0x5a99 < nameHash) {
                  if (nameHash == 0x5aaa) goto loopSetChunk;
                  hashMatches = nameHash == 0x5aae;
                  goto loopCheckHashMatches3;
                }
                if (nameHash != 0x5a95) goto storeParseSymbol;
              }
            }
            else if (nameHash != 0x5acf) {
              if (nameHash < 0x5ad0) {
                if (nameHash == 0x5ac2) goto loopSetChunk4;
                if (nameHash < 0x5ac3) {
                  hashMatches = nameHash == 0x5ab6;
                  goto loopCheckHashMatches;
                }
                if (nameHash == 0x5ac7) goto loopSetChunk;
                hashMatches = nameHash == 0x5acb;
                goto loopCheckHashMatches3;
              }
              if (nameHash != 0x5ae8) {
                if (nameHash < 0x5ae9) {
                  if (nameHash == 0x5ad3) goto loopSetChunk8;
                  hashMatches = nameHash == 0x5ae4;
                }
                else {
                  if (nameHash == 0x5aec) goto setChunk;
                  hashMatches = nameHash == 0x5b01;
                }
loopCheckHashMatches4:
                if (!hashMatches) goto storeParseSymbol;
                goto loopSetChunk;
              }
              goto loopSetChunk7;
            }
          }
setChunk:
          chunk = _PPStreamChunkCreateWithType(3,0);
          fieldValue = 7;
          chunkWord = *(uint *)(chunk + 0xc);
          goto setChunkWord2;
        }
        if (nameHash != 0x71c3) {
          if (0x71c3 < nameHash) {
            if (nameHash == 0x7ab2) {
              chunk = _PPStreamChunkCreateWithType(2,0);
              chunkWord = *(uint *)(chunk + 0xc) & 0xfff0ffe3 | 0x70000;
              goto setChunkWord5;
            }
            if (nameHash < 0x7ab3) {
              if (nameHash == 0x7a53) goto loopSetChunk12;
              if (nameHash < 0x7a54) {
                if (nameHash != 0x7a49) goto storeParseSymbol;
                chunk = _PPStreamChunkCreateWithType(2,0);
                chunkWord = *(uint *)(chunk + 0xc) & 0xfff0ffe0 | 0x70000;
                goto loopStoreChunk2;
              }
              if (nameHash == 0x7a6c) {
                chunk = _PPStreamChunkCreateWithType(2,0);
                chunkWord = *(uint *)(chunk + 0xc) & 0xfff0ffe1 | 0x70000;
                goto setChunkWord4;
              }
              if (nameHash != 0x7a8f) goto storeParseSymbol;
              chunk = _PPStreamChunkCreateWithType(2,0);
              chunkWordTexcoord = *(uint *)(chunk + 0xc) & 0xfff0ffff | 0x70000;
              chunkWord = 2;
            }
            else if (nameHash == 0x7b1b) {
              chunk = _PPStreamChunkCreateWithType(2,0);
              chunkWordTexcoord = *(uint *)(chunk + 0xc) & 0xfff0ffff | 0x70000;
              chunkWord = 6;
            }
            else if (nameHash < 0x7b1c) {
              if (nameHash == 0x7ad5) {
                chunk = _PPStreamChunkCreateWithType(2,0);
                chunkWordTexcoord = *(uint *)(chunk + 0xc) & 0xfff0ffff | 0x70000;
                chunkWord = 4;
              }
              else {
                if (nameHash != 0x7af8) goto storeParseSymbol;
                chunk = _PPStreamChunkCreateWithType(2,0);
                chunkWordTexcoord = *(uint *)(chunk + 0xc) & 0xfff0ffff | 0x70000;
                chunkWord = 5;
              }
            }
            else {
              if (nameHash != 0x7b3e) {
                fieldValue = 0x81b6;
                goto checkNameHash;
              }
              chunk = _PPStreamChunkCreateWithType(2,0);
              chunkWord = 7;
              chunkWordTexcoord = *(uint *)(chunk + 0xc) & 0xfff0ffff | 0x70000;
            }
            chunkWord = chunkWord | chunkWordTexcoord & 0xffffffe0;
            goto loopStoreChunk2;
          }
          if (nameHash != 0x5c79) {
            if (nameHash < 0x5c7a) {
              if (nameHash != 0x5c22) {
                if (nameHash < 0x5c23) {
                  hashMatches = nameHash == 0x5b1e;
                  goto loopCheckHashMatches4;
                }
                if (nameHash != 0x5c3f) {
                  hashMatches = nameHash == 0x5c5c;
loopCheckHashMatches5:
                  if (!hashMatches) goto storeParseSymbol;
                }
              }
            }
            else {
              if (nameHash == 0x6349) {
                chunkType = 4;
                if (shaderStage != 0) goto loopSetChunk5;
setChunk2:
                chunk = _PPStreamChunkCreateWithType(chunkType,0);
                fieldValue = 2;
                goto loopSetChunkWord3;
              }
              if (0x6349 < nameHash) {
                if (nameHash != 0x68de) {
                  hashMatches = nameHash == 0x7171;
                  goto checkHashMatches;
                }
                chunk = _PPStreamChunkCreateWithType(3,0);
                chunkWord = *(uint *)(chunk + 0xc) & 0xffe08fff | 0x108000;
                fieldValue = 3;
                goto setChunkWord6;
              }
              if (nameHash != 0x5c96) {
                hashMatches = nameHash == 0x5cb3;
                goto loopCheckHashMatches5;
              }
            }
          }
          chunk = _PPStreamChunkCreateWithType(3,0);
          chunkWord = *(uint *)(chunk + 0xc) & 0xffe0ffff | 0xa0000;
          goto storeChunk2;
        }
loopSetChunk9:
        chunk = _PPStreamChunkCreateWithType(3,0);
        fieldValue = 0xd;
loopSetChunkWord5:
        chunkWord = *(uint *)(chunk + 0xc);
loopSetChunkWord6:
        chunkWord = fieldValue << 0x10 | chunkWord & 0xffe0ffff;
      }
    }
    else if (nameHash == 0xa562) {
      chunk = _PPStreamChunkCreateWithType(3,0);
      chunkWord = *(uint *)(chunk + 0xc) & 0xffe008ff | 0x104100;
    }
    else {
      if (nameHash < 0xa563) {
        if (nameHash == 0x829f) {
loopSetChunk10:
          chunk = _PPStreamChunkCreateWithType(3,0);
          fieldValue = 8;
          chunkWord = *(uint *)(chunk + 0xc);
          goto loopSetChunkWord;
        }
        if (nameHash < 0x82a0) {
          if (nameHash != 0x823a) {
            if (0x823a < nameHash) {
              if (nameHash != 0x8261) {
                if (nameHash < 0x8262) {
                  if (nameHash != 0x8242) {
                    if (0x8242 < nameHash) {
                      if (nameHash != 0x8259) {
                        fieldValue = 0x825d;
                        goto loopCheckNameHash;
                      }
                      goto loopSetChunk10;
                    }
                    if (nameHash != 0x823e) goto storeParseSymbol;
                    goto setChunk3;
                  }
                }
                else {
                  if (nameHash == 0x8280) goto loopSetChunk13;
                  if (0x8280 < nameHash) {
                    if (nameHash != 0x8284) {
                      fieldValue = 0x8288;
                      goto checkNameHash;
                    }
                    goto setChunk3;
                  }
                  if (nameHash != 0x8265) {
                    fieldValue = 0x827c;
                    goto loopCheckNameHash3;
                  }
                }
loopSetChunk11:
                chunk = _PPStreamChunkCreateWithType(3,0);
                fieldValue = 8;
                chunkWord = *(uint *)(chunk + 0xc);
setChunkWord:
                chunkWord = fieldValue << 0x10 | chunkWord & 0xffe0ff7f | 0x60;
                goto loopStoreChunk;
              }
              goto setChunk3;
            }
            if (nameHash == 0x8213) goto loopSetChunk10;
            if (nameHash < 0x8214) {
              if (nameHash != 0x81f4) {
                if (nameHash < 0x81f5) {
                  fieldValue = 0x81d9;
                }
                else {
                  if (nameHash == 0x81f8) goto setChunk3;
                  fieldValue = 0x81fc;
                }
checkNameHash:
                if (nameHash != fieldValue) goto storeParseSymbol;
                goto loopSetChunk11;
              }
            }
            else {
              if (nameHash == 0x821b) goto setChunk3;
              if (0x821b < nameHash) {
                if (nameHash != 0x821f) {
                  fieldValue = 0x8236;
                  goto loopCheckNameHash3;
                }
                goto loopSetChunk11;
              }
              fieldValue = 0x8217;
loopCheckNameHash:
              if (nameHash != fieldValue) goto storeParseSymbol;
            }
          }
          goto loopSetChunk13;
        }
        if (nameHash == 0x8837) {
loopSetChunk12:
          chunk = _PPStreamChunkCreateWithType(3,0);
          fieldValue = 0xf;
          chunkWord = *(uint *)(chunk + 0xc);
          goto loopSetChunkWord6;
        }
        if (0x8837 < nameHash) {
          if (nameHash != 0x9a2c) {
            if (nameHash < 0x9a2d) {
              if (nameHash == 0x92cd) {
                chunk = _PPStreamChunkCreateWithType(3,0);
                chunkWord = *(uint *)(chunk + 0xc) & 0xffe07fff | 0x104000;
loopSetChunkWord7:
                chunkWord = chunkWord & 0xffffcfff;
                goto setChunkWord7;
              }
              if (nameHash < 0x92ce) {
                if (nameHash != 0x89f6) goto storeParseSymbol;
                goto loopSetChunk12;
              }
              if (nameHash != 0x99e2) {
                fieldValue = 0x9a07;
                goto loopCheckNameHash2;
              }
            }
            else if (nameHash != 0x9a9b) {
              if (nameHash < 0x9a9c) {
                if (nameHash != 0x9a51) {
                  fieldValue = 0x9a76;
loopCheckNameHash2:
                  if (nameHash != fieldValue) goto storeParseSymbol;
                }
              }
              else if (nameHash != 0x9ac0) {
                fieldValue = 0x9ae5;
                goto loopCheckNameHash2;
              }
            }
          }
          chunk = _PPStreamChunkCreateWithType(3,0);
          chunkWord = *(uint *)(chunk + 0xc) & 0xffe07fff | 0x104000;
loopSetChunkWord8:
          chunkWord = chunkWord & 0xffffcfff;
          goto loopSetChunkWord11;
        }
        if (nameHash == 0x82c6) {
loopSetChunk13:
          chunk = _PPStreamChunkCreateWithType(3,0);
          fieldValue = 8;
          chunkWord = *(uint *)(chunk + 0xc);
          goto loopSetChunkWord4;
        }
        if (nameHash < 0x82c7) {
          if (nameHash != 0x82a7) {
            if (nameHash < 0x82a8) {
              fieldValue = 0x82a3;
              goto loopCheckNameHash;
            }
            if (nameHash == 0x82ab) goto loopSetChunk11;
            fieldValue = 0x82c2;
loopCheckNameHash3:
            if (nameHash != fieldValue) goto storeParseSymbol;
            goto loopSetChunk10;
          }
        }
        else {
          if (nameHash == 0x82e9) goto loopSetChunk13;
          if (0x82e9 < nameHash) {
            if (nameHash != 0x8308) {
              if (nameHash != 0x840f) goto storeParseSymbol;
              chunkType = 2;
              goto loopSetChunk6;
            }
            goto loopSetChunk10;
          }
          if (nameHash != 0x82ca) {
            fieldValue = 0x82e5;
            goto loopCheckNameHash3;
          }
        }
setChunk3:
        chunk = _PPStreamChunkCreateWithType(3,0);
        fieldValue = 8;
        chunkWord = *(uint *)(chunk + 0xc);
setChunkWord2:
        chunkWord = fieldValue << 0x10 | chunkWord & 0xffe0ff1f | 0x40;
        goto loopStoreChunk;
      }
      if (nameHash != 0xe1f0) {
        if (0xe1f0 < nameHash) {
          if (nameHash != 0x1021f) {
            if (0x1021f < nameHash) {
              if (nameHash != 0x1029a) {
                if (nameHash < 0x1029b) {
                  if (nameHash == 0x10240) goto setChunk5;
                  if (nameHash < 0x10241) {
                    fieldValue = 0x10237;
                  }
                  else {
                    if (nameHash == 0x10258) goto setChunk4;
                    fieldValue = 0x10279;
                  }
loopCheckNameHash4:
                  if (nameHash != fieldValue) goto storeParseSymbol;
                }
                else if (nameHash != 0x102fd) {
                  if (nameHash < 0x102fe) {
                    if (nameHash != 0x102bb) {
                      fieldValue = 0x102dc;
                      goto loopCheckNameHash4;
                    }
                  }
                  else if (nameHash != 0x1031e) {
                    if (nameHash != 0x10f0d) goto storeParseSymbol;
                    chunk = _PPStreamChunkCreateWithType(3,0);
                    chunkWord = *(uint *)(chunk + 0xc) & 0xffe0fffe | 0x50000;
                    goto setFieldValue;
                  }
                }
              }
setChunk4:
              chunk = _PPStreamChunkCreateWithType(3,0);
              chunkWord = *(uint *)(chunk + 0xc) & 0xffe0f1ff | 0x30100;
              goto storeChunk2;
            }
            if (nameHash != 0x10159) {
              if (nameHash < 0x1015a) {
                if (nameHash == 0xf7d2) {
                  chunk = _PPStreamChunkCreateWithType(3,0);
                  chunkWord = *(uint *)(chunk + 0xc) & 0xffe0fffe | 0x50000;
                  fieldValue = 1;
                  goto setChunkWord8;
                }
                if (nameHash < 0xf7d3) {
                  if (nameHash != 0xf700) goto storeParseSymbol;
                  chunk = _PPStreamChunkCreateWithType(3,0);
                  chunkWord = *(uint *)(chunk + 0xc) & 0xffe0fff0 | 0x50000;
                }
                else {
                  if (nameHash == 0xf839) {
                    chunk = _PPStreamChunkCreateWithType(3,0);
                    chunkWord = *(uint *)(chunk + 0xc) & 0xffe0ffff | 0x50001;
setFieldValue:
                    fieldValue = 2;
                    goto setChunkWord8;
                  }
                  if (nameHash != 0xf9fd) goto storeParseSymbol;
                  chunk = _PPStreamChunkCreateWithType(3,0);
                  chunkWord = *(uint *)(chunk + 0xc) & 0xffe0fff7 | 0x50007;
                }
                goto loopStoreChunk2;
              }
              if (nameHash != 0x101bc) {
                if (nameHash < 0x101bd) {
                  if (nameHash != 0x1017a) {
                    fieldValue = 0x1019b;
loopCheckNameHash5:
                    if (nameHash != fieldValue) goto storeParseSymbol;
                  }
                }
                else if (nameHash != 0x101dd) {
                  fieldValue = 0x101fe;
                  goto loopCheckNameHash5;
                }
              }
            }
          }
setChunk5:
          chunk = _PPStreamChunkCreateWithType(3,0);
          chunkWord = *(uint *)(chunk + 0xc) & 0xffe0f0ff | 0x30000;
          goto storeChunk2;
        }
        if (nameHash != 0xb938) {
          if (nameHash < 0xb939) {
            if (nameHash != 0xb86b) {
              if (nameHash < 0xb86c) {
                if (nameHash != 0xb7f0) {
                  if (nameHash < 0xb7f1) {
                    fieldValue = 0xb7c7;
                  }
                  else {
                    if (nameHash == 0xb819) goto setChunk6;
                    fieldValue = 0xb842;
                  }
loopCheckNameHash6:
                  if (nameHash != fieldValue) goto storeParseSymbol;
                }
              }
              else if (nameHash != 0xb8bd) {
                if (nameHash < 0xb8be) {
                  fieldValue = 0xb894;
                }
                else {
                  if (nameHash == 0xb8e6) goto setChunk6;
                  fieldValue = 0xb90f;
                }
                goto loopCheckNameHash6;
              }
            }
          }
          else if (nameHash != 0xc13b) {
            if (0xc13b < nameHash) {
              if (nameHash == 0xc310) {
                chunk = _PPStreamChunkCreateWithType(4,0);
                fieldValue = 5;
                chunkWord = *(uint *)(chunk + 0xc);
setChunkWord3:
                chunkWord = fieldValue << 0x10 | chunkWord & 0xfff0ffff;
setChunkWord4:
                chunkWord = chunkWord | 1;
              }
              else {
                if (nameHash < 0xc311) {
                  if (nameHash != 0xc166) {
                    fieldValue = 0xc191;
                    goto loopCheckNameHash6;
                  }
                  goto setChunk6;
                }
                if (nameHash == 0xd7ba) {
                  chunk = _PPStreamChunkCreateWithType(4,0);
                  fieldValue = 5;
                  chunkWord = *(uint *)(chunk + 0xc);
                  goto loopSetChunkWord2;
                }
                if (nameHash != 0xe12a) goto storeParseSymbol;
                chunk = _PPStreamChunkCreateWithType(3,0);
                chunkWord = *(uint *)(chunk + 0xc) & 0xffe0fff1 | 0x50001;
              }
              goto loopStoreChunk2;
            }
            if (nameHash != 0xc0ba) {
              if (nameHash < 0xc0bb) {
                if (nameHash != 0xbd41) goto storeParseSymbol;
                chunk = _PPStreamChunkCreateWithType(3,0);
                fieldValue = 6;
                goto loopSetChunkWord5;
              }
              if (nameHash != 0xc0e5) {
                fieldValue = 0xc110;
                goto loopCheckNameHash6;
              }
            }
          }
        }
setChunk6:
        chunk = _PPStreamChunkCreateWithType(3,0);
        chunkWord = *(uint *)(chunk + 0xc) & 0xffe0ffff | 0x90000;
        goto loopStoreChunk;
      }
      chunk = _PPStreamChunkCreateWithType(3,0);
      chunkWord = *(uint *)(chunk + 0xc) & 0xffe0fff3 | 0x50000;
setChunkWord5:
      chunkWord = chunkWord | 3;
    }
loopStoreChunk2:
    *(uint *)(chunk + 0xc) = chunkWord;
    goto storeParseSymbol;
  }
  if (nameHash == 0x18b0a) goto loopSetChunk14;
  if (nameHash < 0x18b0b) {
    if (nameHash == 0x147c7) goto setChunk13;
    if (0x147c7 < nameHash) {
      if (nameHash == 0x1705e) goto setChunk8;
      if (0x1705e < nameHash) {
        if (nameHash != 0x17e27) {
          if (nameHash < 0x17e28) {
            if (nameHash != 0x170f7) {
              if (nameHash < 0x170f8) {
                if (nameHash == 0x17089) goto setChunk8;
                if (nameHash < 0x1708a) {
                  fieldValue = 0x17076;
                }
                else {
                  if (nameHash == 0x170a1) goto setChunk7;
                  fieldValue = 0x170cc;
                }
loopCheckNameHash7:
                if (nameHash != fieldValue) goto storeParseSymbol;
              }
              else if (nameHash != 0x17178) {
                if (nameHash < 0x17179) {
                  if (nameHash != 0x17122) {
                    fieldValue = 0x1714d;
                    goto loopCheckNameHash7;
                  }
                }
                else if (nameHash != 0x171a3) {
                  fieldValue = 0x17e06;
                  goto loopCheckNameHash9;
                }
              }
            }
setChunk7:
            chunk = _PPStreamChunkCreateWithType(3,0);
            chunkWord = *(uint *)(chunk + 0xc) & 0xffe0fbff | 0x40300;
            goto storeChunk2;
          }
          if (nameHash != 0x17ecc) {
            if (0x17ecc < nameHash) {
              if (nameHash != 0x18a83) {
                if (nameHash < 0x18a84) {
                  if (nameHash == 0x17eed) goto setChunk16;
                  fieldValue = 0x18a56;
                }
                else {
                  if (nameHash == 0x18ab0) goto loopSetChunk14;
                  fieldValue = 0x18add;
                }
loopCheckNameHash8:
                if (nameHash != fieldValue) goto storeParseSymbol;
              }
loopSetChunk14:
              chunk = _PPStreamChunkCreateWithType(3,0);
              chunkWord = *(uint *)(chunk + 0xc) & 0xffe0f8ff | 0x40000;
              goto storeChunk2;
            }
            if (nameHash != 0x17e69) {
              if (nameHash < 0x17e6a) {
                fieldValue = 0x17e48;
              }
              else {
                if (nameHash == 0x17e8a) goto setChunk16;
                fieldValue = 0x17eab;
              }
loopCheckNameHash9:
              if (nameHash != fieldValue) goto storeParseSymbol;
            }
          }
        }
        goto setChunk16;
      }
      if (nameHash != 0x14d24) {
        if (0x14d24 < nameHash) {
          if (nameHash != 0x16f5c) {
            if (nameHash < 0x16f5d) {
              if (nameHash != 0x14d92) {
                if (0x14d92 < nameHash) {
                  if (nameHash == 0x158fc) {
                    chunk = _PPStreamChunkCreateWithType(3,0);
                    chunkWord = *(uint *)(chunk + 0xc) & 0xffe07fff | 0x104000;
loopSetChunkWord9:
                    chunkWord = chunkWord & 0xffffcfff;
loopSetChunkWord10:
                    chunkWord = chunkWord & 0xfffff8ff;
                    goto storeChunk;
                  }
                  if (nameHash != 0x15dbb) goto storeParseSymbol;
                  chunk = _PPStreamChunkCreateWithType(3,0);
                  chunkWord = *(uint *)(chunk + 0xc) & 0xffe00fff | 0x100000;
                  goto setFieldValue2;
                }
                fieldValue = 0x14d5b;
                goto checkNameHash2;
              }
              goto setChunk9;
            }
            if (nameHash != 0x16fdd) {
              if (nameHash < 0x16fde) {
                if (nameHash != 0x16f87) {
                  fieldValue = 0x16fb2;
loopCheckNameHash10:
                  if (nameHash != fieldValue) goto storeParseSymbol;
                }
              }
              else if (nameHash != 0x17008) {
                fieldValue = 0x17033;
                goto loopCheckNameHash10;
              }
            }
          }
setChunk8:
          chunk = _PPStreamChunkCreateWithType(3,0);
          chunkWord = *(uint *)(chunk + 0xc) & 0xffe0f9ff | 0x40100;
          goto storeChunk2;
        }
        if (nameHash != 0x14c11) {
          if (nameHash < 0x14c12) {
            if (nameHash != 0x14809) {
              if (nameHash < 0x1480a) {
                fieldValue = 0x147e8;
              }
              else {
                if (nameHash == 0x1482a) goto setChunk13;
                fieldValue = 0x1484b;
              }
loopCheckNameHash11:
              if (nameHash != fieldValue) goto storeParseSymbol;
            }
            goto setChunk13;
          }
          if (nameHash != 0x14c7f) {
            if (nameHash < 0x14c80) {
              fieldValue = 0x14c48;
            }
            else {
              if (nameHash == 0x14cb6) goto setChunk9;
              fieldValue = 0x14ced;
            }
checkNameHash2:
            if (nameHash != fieldValue) goto storeParseSymbol;
          }
        }
      }
setChunk9:
      chunk = _PPStreamChunkCreateWithType(3,0);
      chunkWord = *(uint *)(chunk + 0xc) & 0xffe00fff | 0x100000;
loopSetChunkWord11:
      chunkWord = chunkWord & 0xfffff8ff | 0x400;
      goto storeChunk2;
    }
    if (nameHash == 0x11ea4) goto setChunk12;
    if (nameHash < 0x11ea5) {
      if (nameHash != 0x11b4b) {
        if (0x11b4b < nameHash) {
          if (nameHash != 0x11d4e) {
            if (nameHash < 0x11d4f) {
              if (nameHash != 0x11cb5) {
                if (nameHash < 0x11cb6) {
                  fieldValue = 0x11c82;
                }
                else {
                  if (nameHash == 0x11ce8) goto setChunk10;
                  fieldValue = 0x11d1b;
                }
loopCheckNameHash12:
                if (nameHash != fieldValue) goto storeParseSymbol;
              }
            }
            else if (nameHash != 0x11de7) {
              if (0x11de7 < nameHash) {
                if (nameHash != 0x11e62) {
                  fieldValue = 0x11e83;
                  goto checkNameHash4;
                }
                goto setChunk12;
              }
              if (nameHash != 0x11d81) {
                fieldValue = 0x11db4;
                goto loopCheckNameHash12;
              }
            }
          }
setChunk10:
          chunk = _PPStreamChunkCreateWithType(3,0);
          chunkWord = *(uint *)(chunk + 0xc) & 0xffe0ffff | 0x10c000;
          goto loopSetChunkWord8;
        }
        if (nameHash != 0x11aa6) {
          if (nameHash < 0x11aa7) {
            if (nameHash == 0x1142d) {
              chunk = _PPStreamChunkCreateWithType(3,0);
              chunkWord = *(uint *)(chunk + 0xc) & 0xffe0ffff | 0x10c000;
              goto loopSetChunkWord7;
            }
            if (nameHash < 0x1142e) {
              if (nameHash != 0x110e1) goto storeParseSymbol;
              chunk = _PPStreamChunkCreateWithType(3,0);
              chunkWord = *(uint *)(chunk + 0xc) & 0xffe0fffe | 0x50000;
              fieldValue = 3;
              goto setChunkWord8;
            }
            if (nameHash != 0x11a64) {
              fieldValue = 0x11a85;
              goto checkNameHash3;
            }
          }
          else if (nameHash != 0x11ae8) {
            if (nameHash < 0x11ae9) {
              fieldValue = 0x11ac7;
            }
            else {
              if (nameHash == 0x11b09) goto setChunk11;
              fieldValue = 0x11b2a;
            }
checkNameHash3:
            if (nameHash != fieldValue) goto storeParseSymbol;
          }
        }
      }
setChunk11:
      chunk = _PPStreamChunkCreateWithType(3,0);
      chunkWord = *(uint *)(chunk + 0xc) & 0xffe0ffff | 0x30000;
      fieldValue = 2;
    }
    else {
      if (nameHash != 0x14328) {
        if (nameHash < 0x14329) {
          if (nameHash != 0x11f49) {
            if (0x11f49 < nameHash) {
              if (nameHash == 0x1275a) {
                chunk = _PPStreamChunkCreateWithType(3,0);
                chunkWord = *(uint *)(chunk + 0xc) & 0xffe0fff8 | 0x50008;
                goto loopStoreChunk2;
              }
              if (nameHash < 0x1275b) {
                hashMatches = nameHash == 0x12304;
checkHashMatches:
                if (!hashMatches) goto storeParseSymbol;
                goto loopSetChunk9;
              }
              if (nameHash == 0x12c7a) {
                chunk = _PPStreamChunkCreateWithType(3,0);
                chunkWord = *(uint *)(chunk + 0xc) & 0xffe0cfff | 0x10c000;
                goto setFieldValue2;
              }
              fieldValue = 0x14307;
              goto checkNameHash5;
            }
            if (nameHash != 0x11ee6) {
              if (nameHash < 0x11ee7) {
                fieldValue = 0x11ec5;
              }
              else {
                if (nameHash == 0x11f07) goto setChunk12;
                fieldValue = 0x11f28;
              }
checkNameHash4:
              if (nameHash != fieldValue) goto storeParseSymbol;
            }
          }
setChunk12:
          chunk = _PPStreamChunkCreateWithType(3,0);
          fieldValue = 3;
          chunkWord = *(uint *)(chunk + 0xc) & 0xffe0ffff | 0x30000;
          goto loopSetChunkWord12;
        }
        if (nameHash != 0x143ac) {
          if (0x143ac < nameHash) {
            if (nameHash != 0x14764) {
              if (nameHash < 0x14765) {
                if (nameHash != 0x143cd) {
                  fieldValue = 0x143ee;
                  goto checkNameHash5;
                }
                goto setChunk14;
              }
              if (nameHash != 0x14785) {
                fieldValue = 0x147a6;
                goto loopCheckNameHash11;
              }
            }
setChunk13:
            chunk = _PPStreamChunkCreateWithType(3,0);
            chunkWord = *(uint *)(chunk + 0xc) & 0xffe0f7ff | 0x30700;
            goto storeChunk2;
          }
          if (nameHash != 0x1436a) {
            if (nameHash < 0x1436b) {
              fieldValue = 0x14349;
checkNameHash5:
              if (nameHash != fieldValue) goto storeParseSymbol;
            }
            else if (nameHash != 0x1438b) {
              if (nameHash != 0x143a8) goto storeParseSymbol;
              chunk = _PPStreamChunkCreateWithType(3,0);
              chunkWord = *(uint *)(chunk + 0xc) & 0xffe00fff | 0x100000;
              goto setChunkWord7;
            }
          }
        }
      }
setChunk14:
      chunk = _PPStreamChunkCreateWithType(3,0);
      chunkWord = *(uint *)(chunk + 0xc) & 0xffe0ffff | 0x30000;
      fieldValue = 6;
    }
loopSetChunkWord12:
    chunkWord = fieldValue << 8 | chunkWord & 0xfffff0ff;
  }
  else {
    if (nameHash == 0x1aa90) goto setChunk17;
    if (0x1aa90 < nameHash) {
      if (nameHash == 0x21945) {
        chunk = _PPStreamChunkCreateWithType(3,0);
        chunkWord = *(uint *)(chunk + 0xc) & 0xffe08fff | 0x108000;
setFieldValue2:
        fieldValue = 1;
setChunkWord6:
        chunkWord = fieldValue << 8 | chunkWord & 0xfffff8ff;
        goto loopStoreChunk2;
      }
      if (nameHash < 0x21946) {
        if (nameHash != 0x203d7) {
          if (nameHash < 0x203d8) {
            if (nameHash == 0x20368) goto setChunk15;
            if (nameHash < 0x20369) {
              if (nameHash == 0x1f97a) {
                chunk = _PPStreamChunkCreateWithType(3,0);
                chunkWord = *(uint *)(chunk + 0xc) & 0xffe08fff | 0x108000;
setChunkWord7:
                chunkWord = chunkWord & 0xfffff8ff | 0x300;
storeChunk:
                *(uint *)(chunk + 0xc) = chunkWord;
                *(undefined1 *)(chunk + 0xf) = 0;
                goto storeParseSymbol;
              }
              if (0x1f97a < nameHash) {
                if (nameHash == 0x1ff52) {
                  chunk = _PPStreamChunkCreateWithType(3,0);
                  fieldValue = 5;
                  chunkWord = *(uint *)(chunk + 0xc) & 0xffe0ffff | 0x50001;
                  goto setChunkWord8;
                }
                fieldValue = 0x20323;
                goto loopCheckNameHash13;
              }
              if (nameHash != 0x1f1a8) goto storeParseSymbol;
              goto loopSetChunk15;
            }
            if (nameHash != 0x20395) {
              if (nameHash < 0x20396) {
                fieldValue = 0x20374;
              }
              else {
                if (nameHash == 0x203ad) goto setChunk15;
                fieldValue = 0x203b6;
              }
              goto loopCheckNameHash9;
            }
          }
          else if (nameHash != 0x2043a) {
            if (nameHash < 0x2043b) {
              if (nameHash == 0x203f8) goto setChunk16;
              if (nameHash < 0x203f9) {
                fieldValue = 0x203f2;
              }
              else {
                if (nameHash == 0x20419) goto setChunk16;
                fieldValue = 0x20437;
              }
loopCheckNameHash13:
              if (nameHash != fieldValue) goto storeParseSymbol;
            }
            else if (nameHash != 0x204c1) {
              if (nameHash < 0x204c2) {
                if (nameHash != 0x2045b) {
                  fieldValue = 0x2047c;
                  goto loopCheckNameHash13;
                }
                goto setChunk16;
              }
              if (nameHash != 0x20506) {
                if (nameHash != 0x2138c) goto storeParseSymbol;
                chunk = _PPStreamChunkCreateWithType(3,0);
                chunkWord = *(uint *)(chunk + 0xc) & 0xffe0ffff | 0x10c000;
                goto loopSetChunkWord9;
              }
            }
setChunk15:
            chunk = _PPStreamChunkCreateWithType(3,0);
            chunkWord = *(uint *)(chunk + 0xc) & 0xffe08fff | 0x108000;
            goto loopSetChunkWord11;
          }
        }
      }
      else {
        if (nameHash == 0x24cb9) {
loopSetChunk15:
          chunk = _PPStreamChunkCreateWithType(3,0);
          fieldValue = 0xe;
          goto loopSetChunkWord5;
        }
        if (nameHash < 0x24cba) {
          if (nameHash != 0x2461d) {
            if (nameHash < 0x2461e) {
              if (nameHash == 0x23231) goto loopSetChunk15;
              if (nameHash < 0x23232) {
                if (nameHash != 0x21eb8) goto storeParseSymbol;
                chunk = _PPStreamChunkCreateWithType(3,0);
                fieldValue = 5;
                chunkWord = *(uint *)(chunk + 0xc) & 0xffe0fffe | 0x50000;
setChunkWord8:
                chunkWord = fieldValue << 1 | chunkWord & 0xfffffff1;
                goto loopStoreChunk2;
              }
              if (nameHash != 0x245db) {
                fieldValue = 0x245fc;
                goto loopCheckNameHash9;
              }
            }
            else if (nameHash != 0x24680) {
              if (nameHash < 0x24681) {
                if (nameHash != 0x2463e) {
                  fieldValue = 0x2465f;
                  goto loopCheckNameHash9;
                }
              }
              else if (nameHash != 0x246a1) {
                fieldValue = 0x246c2;
                goto loopCheckNameHash9;
              }
            }
          }
        }
        else if (nameHash != 0x2616e) {
          if (nameHash < 0x2616f) {
            if (nameHash != 0x2610b) {
              if (nameHash < 0x2610c) {
                if (nameHash == 0x254c3) {
                  chunk = _PPStreamChunkCreateWithType(3,0);
                  *(uint *)(chunk + 0xc) = *(uint *)(chunk + 0xc) & 0xffe008ff | 0x100000;
                  *(undefined1 *)(chunk + 0xf) = 0;
                }
                goto storeParseSymbol;
              }
              if (nameHash != 0x2612c) {
                fieldValue = 0x2614d;
                goto loopCheckNameHash9;
              }
            }
          }
          else if (nameHash != 0x261d1) {
            if (nameHash < 0x261d2) {
              if (nameHash != 0x2618f) {
                fieldValue = 0x261b0;
                goto loopCheckNameHash9;
              }
            }
            else if (nameHash != 0x261f2) {
              if (nameHash != 0x343c5) goto storeParseSymbol;
              chunk = _PPStreamChunkCreateWithType(3,0);
              chunkWord = *(uint *)(chunk + 0xc) & 0xffe08fff | 0x108000;
              goto loopSetChunkWord10;
            }
          }
        }
      }
setChunk16:
      chunk = _PPStreamChunkCreateWithType(3,0);
      chunkWord = *(uint *)(chunk + 0xc) & 0xffe0ffff | 0x30000;
      fieldValue = 5;
      goto loopSetChunkWord12;
    }
    if (nameHash == 0x18e85) {
loopSetChunk16:
      chunk = _PPStreamChunkCreateWithType(3,0);
      chunkWord = *(uint *)(chunk + 0xc) & 0xffe0ffff | 0x30000;
      fieldValue = 4;
      goto loopSetChunkWord12;
    }
    if (0x18e85 < nameHash) {
      if (nameHash != 0x19384) {
        if (0x19384 < nameHash) {
          if (nameHash != 0x1a982) {
            if (nameHash < 0x1a983) {
              if (nameHash != 0x193c6) {
                if (nameHash < 0x193c7) {
                  fieldValue = 0x193a5;
                  goto loopCheckNameHash15;
                }
                if (nameHash != 0x193e7) {
                  fieldValue = 0x1a955;
                  goto loopCheckNameHash14;
                }
              }
              goto loopSetChunk16;
            }
            if (nameHash != 0x1aa09) {
              if (nameHash < 0x1aa0a) {
                if (nameHash != 0x1a9af) {
                  fieldValue = 0x1a9dc;
loopCheckNameHash14:
                  if (nameHash != fieldValue) goto storeParseSymbol;
                }
              }
              else if (nameHash != 0x1aa36) {
                fieldValue = 0x1aa63;
                goto loopCheckNameHash14;
              }
            }
          }
setChunk17:
          chunk = _PPStreamChunkCreateWithType(3,0);
          chunkWord = *(uint *)(chunk + 0xc) & 0xffe0fcff | 0x40400;
          goto storeChunk2;
        }
        if (nameHash != 0x18f09) {
          if (nameHash < 0x18f0a) {
            if (nameHash != 0x18ea6) {
              if (nameHash < 0x18ea7) {
                fieldValue = 0x18e8a;
                goto loopCheckNameHash16;
              }
              if (nameHash != 0x18ec7) {
                fieldValue = 0x18ee8;
                goto loopCheckNameHash15;
              }
            }
          }
          else if (nameHash != 0x19321) {
            if (nameHash < 0x19322) {
              if (nameHash != 0x18f2a) {
                fieldValue = 0x19300;
loopCheckNameHash15:
                if (nameHash != fieldValue) goto storeParseSymbol;
              }
            }
            else if (nameHash != 0x19342) {
              fieldValue = 0x19363;
              goto loopCheckNameHash15;
            }
          }
        }
      }
      goto loopSetChunk16;
    }
    if (nameHash != 0x18c8a) {
      if (0x18c8a < nameHash) {
        if (nameHash != 0x18dde) {
          if (nameHash < 0x18ddf) {
            if (nameHash != 0x18d5d) {
              if (nameHash < 0x18d5e) {
                fieldValue = 0x18cb7;
                goto checkNameHash6;
              }
              if (nameHash != 0x18d88) {
                fieldValue = 0x18db3;
loopCheckNameHash16:
                if (nameHash != fieldValue) goto storeParseSymbol;
              }
            }
          }
          else {
            if (nameHash == 0x18e43) goto loopSetChunk16;
            if (nameHash < 0x18e44) {
              if (nameHash != 0x18e09) {
                fieldValue = 0x18e34;
                goto loopCheckNameHash16;
              }
            }
            else if (nameHash != 0x18e5f) {
              fieldValue = 0x18e64;
              goto loopCheckNameHash15;
            }
          }
        }
        chunk = _PPStreamChunkCreateWithType(3,0);
        chunkWord = *(uint *)(chunk + 0xc) & 0xffe0fdff | 0x40500;
        goto storeChunk2;
      }
      if (nameHash != 0x18ba9) {
        if (nameHash < 0x18baa) {
          if (nameHash == 0x18b64) goto loopSetChunk14;
          if (nameHash < 0x18b65) {
            fieldValue = 0x18b37;
          }
          else {
            if (nameHash == 0x18b7c) goto setChunk18;
            fieldValue = 0x18b91;
          }
          goto loopCheckNameHash8;
        }
        if (nameHash != 0x18c03) {
          if (nameHash < 0x18c04) {
            fieldValue = 0x18bd6;
          }
          else {
            if (nameHash == 0x18c30) goto setChunk18;
            fieldValue = 0x18c5d;
          }
checkNameHash6:
          if (nameHash != fieldValue) goto storeParseSymbol;
        }
      }
    }
setChunk18:
    chunk = _PPStreamChunkCreateWithType(3,0);
    chunkWord = *(uint *)(chunk + 0xc) & 0xffe0f8ff | 0x40200;
  }
storeChunk2:
  *(uint *)(chunk + 0xc) = chunkWord;
  directIndex2 = ParseSymbol__GetDirectIndex(parseSymbol,0);
  *(undefined1 *)(chunk + 0xf) = directIndex2;
storeParseSymbol:
  *(undefined4 *)(parseSymbol + 0x34) = 1;
  return chunk;
}

/* GetChunkForSymbol @ 0x97bcc6b8 (592 bytes) */
int GetChunkForSymbol(parseSymbol, shaderStage)
  unsigned char * parseSymbol;
  int shaderStage;
{
  int symbolName;
  uint builtInInitialSwizzle;
  uint streamType;
  int scalerWidthForType;
  bool isTypedKind;
  byte chunkKind;
  uint swizzleBits;
  int compareResult;
  byte *chunk;
  undefined4 typeKind;
  uint chunkWord;
  int basicTypeCode;
  
  symbolName = *(int *)(parseSymbol + 0x14);
  if (((symbolName == 0) || (compareResult = _memcmp(symbolName,"gl_",3), compareResult != 0)) ||
     (*(char *)(symbolName + 3) == '_')) {
    typeKind = (**(code **)(**(int **)(parseSymbol + 0xc) + 0x24))(*(int **)(parseSymbol + 0xc));
    switch(typeKind) {
    case 0:
    case 1:
    case 2:
    case 4:
    case 5:
    case 9:
    case 10:
    case 0xb:
    case 0xc:
      chunk = (byte *)_PPStreamChunkCreateWithType(0,0);
      break;
    case 3:
      chunk = (byte *)_PPStreamChunkCreateWithType(2,0);
      *(uint *)(chunk + 0xc) = *(uint *)(chunk + 0xc) & 0xfff0ffff | 0x90000;
      break;
    case 6:
      chunk = (byte *)_PPStreamChunkCreateWithType(3,0);
      *(uint *)(chunk + 0xc) = *(uint *)(chunk + 0xc) & 0xffe0ffff | 0x10000;
      basicTypeCode = (**(code **)(**(int **)(parseSymbol + 0xc) + 0x20))(*(int **)(parseSymbol + 0xc));
      *(uint *)(chunk + 0x10) =
           (uint)(basicTypeCode - 5U < 8) << 0x1f | *(uint *)(chunk + 0x10) & 0x7fffffff;
      break;
    default:
      chunk = (byte *)0x0;
    }
  }
  else {
    chunk = (byte *)((int (*)())GetBuiltInChunkForSymbol)(parseSymbol,shaderStage);
    *(undefined4 *)(parseSymbol + 0x38) = 1;
    *(undefined4 *)(parseSymbol + 0x28) = 0xffffffff;
  }
  if (chunk == (byte *)0x0) goto checkParseSymbol;
  chunkKind = *chunk;
  if (chunkKind == 2) {
loopSetStreamType:
    streamType = GetPPStreamTypeForGLType((uint)*(ushort *)(parseSymbol + 0x2c));
    *(uint *)(chunk + 0xc) = (streamType & 7) << 0x1a | *(uint *)(chunk + 0xc) & 0xe3ffffff;
    scalerWidthForType = GetScalerWidthForType((uint)*(ushort *)(parseSymbol + 0x2c));
    chunkWord = (scalerWidthForType + -1) * 0x1000000 & 0x3000000U | *(uint *)(chunk + 0xc) & 0x1cffffff;
loopStoreChunk:
    *(uint *)(chunk + 0xc) = chunkWord;
  }
  else if (chunkKind < 3) {
    if (chunkKind == 0) {
      streamType = GetPPStreamTypeForGLType((uint)*(ushort *)(parseSymbol + 0x2c));
      *(uint *)(chunk + 0xc) = (streamType & 7) << 0x1a | *(uint *)(chunk + 0xc) & 0xe3ffffff;
      scalerWidthForType = GetScalerWidthForType((uint)*(ushort *)(parseSymbol + 0x2c));
      chunkWord = (scalerWidthForType + -1) * 0x1000000 & 0x3000000U | *(uint *)(chunk + 0xc) & 0x1cffffff;
      goto loopStoreChunk;
    }
  }
  else if ((chunkKind == 3) || (chunkKind == 4)) goto loopSetStreamType;
checkParseSymbol:
  if (*(int *)(parseSymbol + 0x34) == 0) {
    return chunk;
  }
  builtInInitialSwizzle = ((int (*)())GetBuiltInInitialSwizzle)(parseSymbol);
  if (builtInInitialSwizzle == 0) {
    return chunk;
  }
  chunkKind = *chunk;
  if (chunkKind != 2) {
    if (chunkKind < 3) {
      isTypedKind = chunkKind == 0;
    }
    else {
      if (chunkKind == 3) goto setSwizzleBits;
      isTypedKind = chunkKind == 4;
    }
    if (!isTypedKind) {
      return chunk;
    }
  }
setSwizzleBits:
  swizzleBits = *(uint *)(chunk + 0xc) >> 0x18 & 3;
  if (swizzleBits < builtInInitialSwizzle) {
    swizzleBits = builtInInitialSwizzle;
  }
  *(uint *)(chunk + 0xc) = (swizzleBits & 3) << 0x18 | *(uint *)(chunk + 0xc) & 0xfcffffff;
  return chunk;
}

/* __ZN13FunctionTableC2Ev @ 0x97bcc93c (4 bytes) */
int __ZN13FunctionTableC2Ev(this)
  void *this;
{
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)this = 0;
  return;
}

/* __ZN13FunctionTableC1Ev @ 0x97bcc940 (4 bytes) */
int __ZN13FunctionTableC1Ev(this)
  void *this;
{
  return ((int (*)())__ZN13FunctionTableC4Ev)(this);
}

/* __ZN13FunctionTableC4Ev @ 0x97bcc944 (16 bytes) */
int __ZN13FunctionTableC4Ev(this)
  void *this;
{
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)this = 0;
  return;
}

/* __ZN13FunctionTableD2Ev @ 0x97bcc954 (8 bytes) */
int __ZN13FunctionTableD2Ev(this)
  void *this;
{
  return ((int (*)())__ZN13FunctionTableD4Ev)(this);
}

/* __ZN13FunctionTableD1Ev @ 0x97bcc95c (8 bytes) */
int __ZN13FunctionTableD1Ev(this)
  void *this;
{
  return ((int (*)())__ZN13FunctionTableD4Ev)(this);
}

/* __ZN13FunctionTableD4Ev @ 0x97bcc964 (4 bytes) */
int __ZN13FunctionTableD4Ev(this)
  void *this;
{
  return ((int (*)())FunctionTable__clear)(this);
}

/* FunctionTable__clear @ 0x97bcc968 (120 bytes) */
int FunctionTable__clear(this)
  unsigned char * this;
{
  undefined4 *entryName;
  int loopIndex;
  int entryOffset;
  
  loopIndex = 0;
  if (0 < *(int *)(this + 4)) {
    entryOffset = 0;
    do {
      loopIndex = loopIndex + 1;
      entryName = (undefined4 *)(entryOffset + *(int *)this);
      entryOffset = entryOffset + 0x18;
      _free(*entryName);
    } while (loopIndex < *(int *)(this + 4));
  }
  if (*(int *)this != 0) {
    _free(*(int *)this);
  }
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)this = 0;
  return;
}

/* FunctionTable__addFunction @ 0x97bcc9e0 (284 bytes) */
int FunctionTable__addFunction(this, str)
  unsigned char * this;
  char *str;
{
  int loopIndex;
  undefined4 allocation2;
  int length;
  int newEntries;
  int dstEntry;
  int newIndex;
  int oldEntries;
  int entries;
  int entryOffset;
  undefined4 entryWord3;
  undefined4 entryWord1;
  undefined4 entryWord2;
  int srcEntry;
  uint functionCount;
  
  functionCount = *(uint *)(this + 4);
  if ((functionCount & 0xf) == 0) {
    newEntries = _malloc(functionCount * 0x18 + 0x180);
    _memset(newEntries,0,*(int *)(this + 4) * 0x18 + 0x180);
    functionCount = *(uint *)(this + 4);
    loopIndex = 0;
    if ((int)functionCount < 1) {
      oldEntries = *(int *)this;
    }
    else {
      oldEntries = *(int *)this;
      entryOffset = 0;
      do {
        srcEntry = entryOffset + oldEntries;
        entryWord1 = *(undefined4 *)(srcEntry + 4);
        loopIndex = loopIndex + 1;
        entryWord2 = *(undefined4 *)(srcEntry + 8);
        dstEntry = entryOffset + newEntries;
        entryWord3 = *(undefined4 *)(srcEntry + 0xc);
        *(undefined4 *)(entryOffset + newEntries) = *(undefined4 *)(entryOffset + oldEntries);
        entryOffset = entryOffset + 0x18;
        *(undefined4 *)(dstEntry + 4) = entryWord1;
        *(undefined4 *)(dstEntry + 8) = entryWord2;
        *(undefined4 *)(dstEntry + 0xc) = entryWord3;
        entryWord3 = *(undefined4 *)(srcEntry + 0x10);
        *(undefined4 *)(dstEntry + 0x14) = *(undefined4 *)(srcEntry + 0x14);
        *(undefined4 *)(dstEntry + 0x10) = entryWord3;
      } while (loopIndex < (int)functionCount);
    }
    if (oldEntries != 0) {
      _free(oldEntries);
      functionCount = *(uint *)(this + 4);
    }
    *(int *)this = newEntries;
  }
  entries = *(int *)this;
  length = _strlen(str);
  allocation2 = _malloc(length + 1);
  *(undefined4 *)(functionCount * 0x18 + entries) = allocation2;
  _strcpy(*(undefined4 *)(*(int *)(this + 4) * 0x18 + *(int *)this),str);
  newIndex = *(int *)(this + 4);
  *(int *)(this + 4) = newIndex + 1;
  return newIndex;
}

/* FunctionTable__removeFunction @ 0x97bccafc (168 bytes) */
int FunctionTable__removeFunction(this, functionIndex)
  unsigned char * this;
  int functionIndex;
{
  int entry;
  undefined4 nextWord3;
  undefined4 nextWord2;
  undefined4 nextWord1;
  int entryOffset;
  
  entryOffset = functionIndex * 0x18;
  _free(*(undefined4 *)(entryOffset + *(int *)this));
  entry = *(int *)(this + 4);
  if (functionIndex < entry) {
    do {
      functionIndex = functionIndex + 1;
      entry = entryOffset + *(int *)this;
      nextWord1 = *(undefined4 *)(entry + 0x1c);
      nextWord2 = *(undefined4 *)(entry + 0x20);
      nextWord3 = *(undefined4 *)(entry + 0x24);
      *(undefined4 *)(entryOffset + *(int *)this) = *(undefined4 *)(entry + 0x18);
      entryOffset = entryOffset + 0x18;
      *(undefined4 *)(entry + 4) = nextWord1;
      *(undefined4 *)(entry + 8) = nextWord2;
      *(undefined4 *)(entry + 0xc) = nextWord3;
      *(undefined4 *)(entry + 0x14) = *(undefined4 *)(entry + 0x2c);
      *(undefined4 *)(entry + 0x10) = *(undefined4 *)(entry + 0x28);
      entry = *(int *)(this + 4);
    } while (functionIndex < entry);
  }
  *(int *)(this + 4) = entry + -1;
  return;
}

/* FunctionTable__setReturnVal @ 0x97bccba4 (20 bytes) */
int FunctionTable__setReturnVal(this, functionIndex, value)
  unsigned char * this;
  int functionIndex;
  undefined4 value;
{
  *(undefined4 *)(functionIndex * 0x18 + *(int *)this + 4) = value;
  return;
}

/* FunctionTable__setEmpty @ 0x97bccbb8 (20 bytes) */
int FunctionTable__setEmpty(this, functionIndex, value)
  unsigned char * this;
  int functionIndex;
  undefined4 value;
{
  *(undefined4 *)(functionIndex * 0x18 + *(int *)this + 8) = value;
  return;
}

/* FunctionTable__setNumParams @ 0x97bccbcc (20 bytes) */
int FunctionTable__setNumParams(this, functionIndex, value)
  unsigned char * this;
  int functionIndex;
  int value;
{
  *(int *)(functionIndex * 0x18 + *(int *)this + 0xc) = value;
  return;
}

/* FunctionTable__setFirstOp @ 0x97bccbe0 (20 bytes) */
int FunctionTable__setFirstOp(this, functionIndex, value)
  unsigned char * this;
  int functionIndex;
  uint value;
{
  *(uint *)(functionIndex * 0x18 + *(int *)this + 0x10) = value;
  return;
}

/* FunctionTable__setLastOp @ 0x97bccbf4 (20 bytes) */
int FunctionTable__setLastOp(this, functionIndex, value)
  unsigned char * this;
  int functionIndex;
  uint value;
{
  *(uint *)(functionIndex * 0x18 + *(int *)this + 0x14) = value;
  return;
}

/* FunctionTable__updateForRemovingChunk @ 0x97bccc08 (168 bytes) */
int FunctionTable__updateForRemovingChunk(this, _PPStreamChunk)
  unsigned char * this;
  unsigned char * _PPStreamChunk;
{
  int loopIndex;
  int entryOffset;
  int entries;
  int entry;
  uint chunkWord;
  
  loopIndex = 0;
  if (0 < *(int *)(this + 4)) {
    entryOffset = 0;
    do {
      entries = *(int *)this;
      chunkWord = *(uint *)(_PPStreamChunk + 0xc);
      entry = entryOffset + entries;
      if ((((chunkWord & 0x3ffff) == *(uint *)(entry + 0x14)) && (*(int *)(_PPStreamChunk + 4) != 0)) &&
         (*(int *)(entry + 0x10) != 0)) {
        *(uint *)(entry + 0x14) = *(uint *)(*(int *)(_PPStreamChunk + 4) + 0xc) & 0x3ffff;
        chunkWord = *(uint *)(_PPStreamChunk + 0xc);
        entries = *(int *)this;
      }
      if ((((chunkWord & 0x3ffff) == *(uint *)(entryOffset + entries + 0x10)) && (*(int *)(_PPStreamChunk + 8) != 0))
         && ((chunkWord & 0x3ffff) != 0)) {
        *(uint *)(entryOffset + entries + 0x10) = *(uint *)(*(int *)(_PPStreamChunk + 8) + 0xc) & 0x3ffff;
      }
      loopIndex = loopIndex + 1;
      entryOffset = entryOffset + 0x18;
    } while (loopIndex < *(int *)(this + 4));
    return;
  }
  return;
}

/* FunctionTable__findFunction @ 0x97bcccb0 (132 bytes) */
int FunctionTable__findFunction(this, str, unusedArg3, unusedArg4, unusedArg5, unusedArg6)
  unsigned char * this;
  char *str;
  undefined4 unusedArg3;
  undefined4 unusedArg4;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
{
  int compareResult;
  int functionCount;
  int entryOffset;
  int index;
  
  index = 0;
  functionCount = *(int *)(this + 4);
  if (0 < functionCount) {
    entryOffset = 0;
    do {
      compareResult = _strcmp(*(undefined4 *)(entryOffset + *(int *)this),str);
      if (compareResult == 0) {
        functionCount = *(int *)(this + 4);
        break;
      }
      functionCount = *(int *)(this + 4);
      index = index + 1;
      entryOffset = entryOffset + 0x18;
    } while (index < functionCount);
  }
  if (index == functionCount) {
    index = -1;
  }
  return index;
}

/* FunctionTable__getFunctionName @ 0x97bccd34 (16 bytes) */
int FunctionTable__getFunctionName(this, functionIndex)
  unsigned char * this;
  int functionIndex;
{
  return *(undefined4 *)(functionIndex * 0x18 + *(int *)this);
}

/* FunctionTable__getReturnVal @ 0x97bccd44 (20 bytes) */
int FunctionTable__getReturnVal(this, functionIndex)
  unsigned char * this;
  int functionIndex;
{
  return *(undefined4 *)(functionIndex * 0x18 + *(int *)this + 4);
}

/* FunctionTable__getEmpty @ 0x97bccd58 (20 bytes) */
int FunctionTable__getEmpty(this, functionIndex)
  unsigned char * this;
  int functionIndex;
{
  return *(undefined4 *)(functionIndex * 0x18 + *(int *)this + 8);
}

/* FunctionTable__getNumParams @ 0x97bccd6c (20 bytes) */
int FunctionTable__getNumParams(this, functionIndex)
  unsigned char * this;
  int functionIndex;
{
  return *(undefined4 *)(functionIndex * 0x18 + *(int *)this + 0xc);
}

/* FunctionTable__getFirstOp @ 0x97bccd80 (20 bytes) */
int FunctionTable__getFirstOp(this, functionIndex)
  unsigned char * this;
  int functionIndex;
{
  return *(undefined4 *)(functionIndex * 0x18 + *(int *)this + 0x10);
}

/* FunctionTable__getLastOp @ 0x97bccd94 (20 bytes) */
int FunctionTable__getLastOp(this, functionIndex)
  unsigned char * this;
  int functionIndex;
{
  return *(undefined4 *)(functionIndex * 0x18 + *(int *)this + 0x14);
}

/* FunctionTable__dump @ 0x97bccda8 (4 bytes) */
int FunctionTable__dump()
{
  return;
}

/* _InterpreterCreate @ 0x97bccdac (60 bytes) */
int _InterpreterCreate()
{
  undefined4 allocation;
  
  allocation = _calloc(0xa70,1);
  ((int (*)())_InterpreterInit)(allocation);
  return allocation;
}

/* _InterpreterFree @ 0x97bccde8 (48 bytes) */
int _InterpreterFree(machine)
  undefined4 machine;
{
  ((int (*)())_InterpreterShutdown)(machine);
  return _free(machine);
}

/* _InterpreterInit @ 0x97bcce18 (72 bytes) */
int _InterpreterInit(machine)
  int machine;
{
  undefined4 interpreterTextureSamplerCreateResult;
  
  _memset(machine,0,0xa70);
  interpreterTextureSamplerCreateResult = ((int (*)())_InterpreterTextureSamplerCreate)();
  *(undefined4 *)(machine + 0xa2c) = interpreterTextureSamplerCreateResult;
  _InterpreterNoiseGeneratorInitialise(machine + 4);
  return _InterpreterRasterOpMachineInitialise(machine + 0xa24);
}

/* _InterpreterShutdown @ 0x97bcce60 (8 bytes) */
int _InterpreterShutdown(machine)
  int machine;
{
  undefined4 interpreterTextureSamplerFreeResult;
  
  interpreterTextureSamplerFreeResult = _InterpreterTextureSamplerFree(*(undefined4 *)(machine + 0xa2c));
  return interpreterTextureSamplerFreeResult;
}

/* _InterpreterAttachEmulatorContext @ 0x97bcce68 (12 bytes) */
int _InterpreterAttachEmulatorContext(machine, emulator)
  undefined4 *machine;
  undefined4 emulator;
{
  *machine = emulator;
  return _InterpreterRasterOpMachineAttachEmulatorContext(machine + 0x289,emulator);
}

/* _InterpreterPackPixel @ 0x97bcce74 (1208 bytes) */
int _InterpreterPackPixel(machine, color, pixelOut)
  int *machine;
  float *color;
  float *pixelOut;
{
  float greenOut;
  float redOut;
  float blueOut;
  float alphaClamp8;
  float blueClamp8;
  float greenClamp8;
  float greenClamp5;
  float blueClamp;
  float zeroConstC;
  float zeroConstB;
  float zeroConstA;
  float scale31;
  float roundOffset5;
  double alphaDouble;
  double blueDouble;
  double greenDouble;
  uint framebufferFormat;
  float floatValue;
  float greenScaled;
  float scale255;
  uint alphaBit;
  uint redInt;
  float roundOffset8;
  uint greenInt;
  float redScaled;
  uint blueInt;
  int emulator;
  bool notBelowZero;
  double redDouble;
  double convertThreshold;
  
  emulator = *machine;
  if (*(int *)(emulator + 0xd9c) != 0) {
    framebufferFormat = _PPEmulatorFramebufferFormat(emulator);
    if ((framebufferFormat & 0x8000000) == 0) {
      framebufferFormat = _PPEmulatorFramebufferFormat(emulator);
      roundOffset8 = FLOAT_97c3acc0;
      scale255 = FLOAT_97c3acbc;
      if ((framebufferFormat & 0x8000) == 0) {
        framebufferFormat = _PPEmulatorFramebufferFormat(emulator);
        scale31 = FLOAT_97c3acc4;
        roundOffset5 = FLOAT_97c3acc0;
        if ((framebufferFormat & 0x400) == 0) {
          return;
        }
        redScaled = *color * FLOAT_97c3acc4 + FLOAT_97c3acc0;
        greenScaled = color[1] * FLOAT_97c3acc4 + FLOAT_97c3acc0;
        notBelowZero = TAllocation__guardBlockSize <= redScaled;
        *color = redScaled;
        color[1] = greenScaled;
        color[2] = color[2] * scale31 + roundOffset5;
        zeroConstA = TAllocation__guardBlockSize;
        if (notBelowZero) {
          if (scale31 < redScaled) {
            redScaled = 31.0;
          }
        }
        else {
          redScaled = 0.0;
        }
        greenClamp5 = color[1];
        *color = redScaled;
        zeroConstC = TAllocation__guardBlockSize;
        if (zeroConstA <= greenClamp5) {
          if (FLOAT_97c3acc4 < greenClamp5) {
            greenClamp5 = 31.0;
          }
        }
        else {
          greenClamp5 = 0.0;
        }
        blueClamp = color[2];
        color[1] = greenClamp5;
        convertThreshold = DOUBLE_97c30a78;
        if (zeroConstC <= blueClamp) {
          if (FLOAT_97c3acc4 < blueClamp) {
            blueClamp = 31.0;
          }
        }
        else {
          blueClamp = 0.0;
        }
        redDouble = (double)*color;
        color[2] = blueClamp;
        if (convertThreshold <= redDouble) {
          redInt = (uint)(int)(redDouble - convertThreshold);
        }
        else {
          redInt = (uint)(int)*color;
        }
        greenDouble = (double)color[1];
        if (DOUBLE_97c30a78 <= greenDouble) {
          greenInt = (uint)(int)(greenDouble - DOUBLE_97c30a78);
        }
        else {
          greenInt = (uint)(int)color[1];
        }
        blueDouble = (double)color[2];
        if (DOUBLE_97c30a78 <= blueDouble) {
          blueInt = (uint)(int)(blueDouble - DOUBLE_97c30a78);
        }
        else {
          blueInt = (uint)(int)color[2];
        }
        if (FLOAT_97c3acc0 <= color[3]) {
          alphaBit = 0x8000;
        }
        else {
          alphaBit = 0;
        }
        floatValue = GH_U2F((unsigned int)((alphaBit | (redInt & 0x1f) << 10 | (greenInt & 0x1f) << 5 | blueInt & 0x1f)));
      }
      else {
        redScaled = *color * FLOAT_97c3acbc + FLOAT_97c3acc0;
        greenScaled = color[1] * FLOAT_97c3acbc + FLOAT_97c3acc0;
        notBelowZero = TAllocation__guardBlockSize <= redScaled;
        *color = redScaled;
        color[1] = greenScaled;
        color[3] = color[3] * scale255 + roundOffset8;
        color[2] = color[2] * scale255 + roundOffset8;
        zeroConstB = TAllocation__guardBlockSize;
        if (notBelowZero) {
          if (scale255 < redScaled) {
            redScaled = 255.0;
          }
        }
        else {
          redScaled = 0.0;
        }
        greenClamp8 = color[1];
        *color = redScaled;
        zeroConstC = TAllocation__guardBlockSize;
        if (zeroConstB <= greenClamp8) {
          if (FLOAT_97c3acbc < greenClamp8) {
            greenClamp8 = 255.0;
          }
        }
        else {
          greenClamp8 = 0.0;
        }
        blueClamp8 = color[2];
        color[1] = greenClamp8;
        zeroConstA = TAllocation__guardBlockSize;
        if (zeroConstC <= blueClamp8) {
          if (FLOAT_97c3acbc < blueClamp8) {
            blueClamp8 = 255.0;
          }
        }
        else {
          blueClamp8 = 0.0;
        }
        alphaClamp8 = color[3];
        color[2] = blueClamp8;
        convertThreshold = DOUBLE_97c30a78;
        if (zeroConstA <= alphaClamp8) {
          if (FLOAT_97c3acbc < alphaClamp8) {
            alphaClamp8 = 255.0;
          }
        }
        else {
          alphaClamp8 = 0.0;
        }
        redDouble = (double)*color;
        color[3] = alphaClamp8;
        if (convertThreshold <= redDouble) {
          redInt = (uint)(int)(redDouble - convertThreshold);
        }
        else {
          redInt = (uint)(int)*color;
        }
        greenDouble = (double)color[1];
        if (DOUBLE_97c30a78 <= greenDouble) {
          greenInt = (uint)(int)(greenDouble - DOUBLE_97c30a78);
        }
        else {
          greenInt = (uint)(int)color[1];
        }
        blueDouble = (double)color[2];
        if (DOUBLE_97c30a78 <= blueDouble) {
          blueInt = (uint)(int)(blueDouble - DOUBLE_97c30a78);
        }
        else {
          blueInt = (uint)(int)color[2];
        }
        alphaDouble = (double)color[3];
        if (DOUBLE_97c30a78 <= alphaDouble) {
          emulator = (int)(alphaDouble - DOUBLE_97c30a78);
        }
        else {
          emulator = (int)color[3];
        }
        floatValue = GH_U2F((unsigned int)((emulator << 0x18 | (redInt & 0xff) << 0x10 | (greenInt & 0xff) << 8 | blueInt & 0xff)))
        ;
      }
      *pixelOut = floatValue;
    }
    else {
      redOut = *color;
      greenOut = color[1];
      blueOut = color[2];
      pixelOut[3] = color[3];
      *pixelOut = redOut;
      pixelOut[1] = greenOut;
      pixelOut[2] = blueOut;
    }
  }
  return;
}

/* _InterpreterUnpackPixel @ 0x97bcd32c (428 bytes) */
int _InterpreterUnpackPixel(machine, color, pixelIn)
  int *machine;
  float *color;
  float *pixelIn;
{
  float channelScale;
  float alpha;
  float red;
  uint framebufferFormat;
  float green;
  float blue;
  int emulator;
  
  emulator = *machine;
  if (*(int *)(emulator + 0xd9c) != 0) {
    framebufferFormat = _PPEmulatorFramebufferFormat(emulator);
    if ((framebufferFormat & 0x8000000) == 0) {
      framebufferFormat = _PPEmulatorFramebufferFormat(emulator);
      if ((framebufferFormat & 0x8000) == 0) {
        framebufferFormat = _PPEmulatorFramebufferFormat(emulator);
        if ((framebufferFormat & 0x400) == 0) {
          return;
        }
        blue = *pixelIn;
        red = (float)((double)CONCAT44(0x43300000,(uint)GH_F2U(blue) >> 10 & 0x1f) - DOUBLE_97c30a68) -
                FLOAT_97c3acc0;
        green = (float)((double)CONCAT44(0x43300000,(uint)GH_F2U(blue) >> 5 & 0x1f) - DOUBLE_97c30a68) -
                FLOAT_97c3acc0;
        alpha = (float)((double)CONCAT44(0x43300000,(uint)GH_F2U(blue) >> 0xf & 1) - DOUBLE_97c30a68) -
                FLOAT_97c3acc0;
        blue = (float)((double)CONCAT44(0x43300000,(uint)GH_F2U(blue) & 0x1f) - DOUBLE_97c30a68) -
                FLOAT_97c3acc0;
        channelScale = FLOAT_97c3accc;
      }
      else {
        alpha = *pixelIn;
        red = (float)((double)CONCAT44(0x43300000,(uint)GH_F2U(alpha) >> 0x10 & 0xff) - DOUBLE_97c30a68);
        green = (float)((double)CONCAT44(0x43300000,(uint)GH_F2U(alpha) >> 8 & 0xff) - DOUBLE_97c30a68);
        blue = (float)((double)CONCAT44(0x43300000,(uint)GH_F2U(alpha) & 0xff) - DOUBLE_97c30a68);
        alpha = (float)((double)CONCAT44(0x43300000,(uint)GH_F2U(alpha) >> 0x18) - DOUBLE_97c30a68);
        channelScale = FLOAT_97c3acc8;
      }
      color[3] = alpha * channelScale;
      *color = red * channelScale;
      color[1] = green * channelScale;
      color[2] = blue * channelScale;
    }
    else {
      red = *pixelIn;
      green = pixelIn[1];
      blue = pixelIn[2];
      color[3] = pixelIn[3];
      *color = red;
      color[1] = green;
      color[2] = blue;
    }
  }
  return;
}

/* _InterpreterWriteDestination @ 0x97bcd4d8 (1100 bytes) */
int _InterpreterWriteDestination(machine, componentOffsets, bankIndex, swizzle, indexInfo, storageFlags, operandWord5, operandWord6, writeMaskFlags, conditionSwizzleZW, element, value, updateConditionCode)
  int *machine;
  int componentOffsets;
  int bankIndex;
  uint swizzle;
  undefined4 indexInfo;
  undefined4 storageFlags;
  undefined4 operandWord5;
  undefined4 operandWord6;
  uint writeMaskFlags;
  undefined4 conditionSwizzleZW;
  int element;
  float *value;
  undefined4 updateConditionCode;
{
  unsigned int ghidra_home[8] = { machine, componentOffsets, bankIndex, swizzle, indexInfo, storageFlags, operandWord5, operandWord6 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  int emulator;
  int programInfo;
  float *targetZ;
  float *targetX;
  float *componentTarget;
  int *storageBase;
  float *targetY;
  int *componentSlot;
  undefined1 conditionCode;
  float scratch [4];
  float swizzledX;
  float swizzledY;
  float swizzledZ;
  float swizzledW;
  
  componentTarget = scratch;
  swizzledX = value[swizzle >> 0x18];
  swizzledY = value[swizzle >> 0x10 & 0xff];
  swizzledZ = value[swizzle >> 8 & 0xff];
  swizzledW = value[swizzle & 0xff];
  emulator = *machine;
  *value = swizzledX;
  value[1] = swizzledY;
  value[2] = swizzledZ;
  value[3] = swizzledW;
  programInfo = *(int *)(emulator + 0xd80);
  (*(ushort *)((unsigned char *)ghidra_home + 20)) = (ushort)((uint)storageFlags >> 0x10);
  if (((*(int *)(programInfo + 0x38) == 0x8804) || (*(int *)(programInfo + 0x38) == 0x8b30)) &&
     ((*(ushort *)((unsigned char *)ghidra_home + 20)) == 1)) {
    storageBase = machine + 0x292;
    componentSlot = (int *)(componentOffsets + element * 0x10);
  }
  else {
    if (((*(int *)(programInfo + 0x38) == 0x8804) || (*(int *)(programInfo + 0x38) == 0x8b30)) &&
       ((*(ushort *)((unsigned char *)ghidra_home + 20)) == 9)) {
      storageBase = machine + 0x28c;
    }
    else {
      (*(char *)((unsigned char *)ghidra_home + 23)) = (char)storageFlags;
      storageBase = *(int **)((uint)(*(ushort *)((unsigned char *)ghidra_home + 20)) * 4 + emulator + 0xd84);
      if ((*(char *)((unsigned char *)ghidra_home + 23)) != '\0') {
        programInfo = bankIndex * 0xc + programInfo;
        (*(short *)((unsigned char *)ghidra_home + 16)) = (short)((uint)indexInfo >> 0x10);
        emulator = *(int *)(programInfo + 0x80);
        componentSlot = (int *)(emulator + (((uint)((componentOffsets + element * 0x10) - emulator) >> 4) +
                                  machine[0x290] + (int)(*(short *)((unsigned char *)ghidra_home + 16)) & *(uint *)(programInfo + 0x88)) *
                                 0x10);
        goto setTargetX;
      }
    }
    componentSlot = (int *)(componentOffsets + element * 0x10);
  }
setTargetX:
  targetX = componentTarget;
  (*(int *)((unsigned char *)ghidra_home + 4)) = componentOffsets;
  (*(int *)((unsigned char *)ghidra_home + 8)) = bankIndex;
  (*(uint *)((unsigned char *)ghidra_home + 12)) = swizzle;
  (*(unsigned int *)((unsigned char *)ghidra_home + 16)) = indexInfo;
  (*(unsigned int *)((unsigned char *)ghidra_home + 20)) = storageFlags;
  (*(unsigned int *)((unsigned char *)ghidra_home + 24)) = operandWord5;
  (*(unsigned int *)((unsigned char *)ghidra_home + 28)) = operandWord6;
  if ((((writeMaskFlags & 0x1000000) != 0) &&
      (emulator = ((int (*)())_InterpreterTestCR)(machine,componentOffsets,bankIndex,swizzle,indexInfo,storageFlags,operandWord5,operandWord6,
                                  writeMaskFlags,conditionSwizzleZW,0), emulator != 0)) &&
     (targetX = (float *)((int)storageBase + *componentSlot), (char)updateConditionCode != '\0')) {
    emulator = ___isnanf(emulator);
    conditionCode = 3;
    if ((emulator == 0) && (conditionCode = 0.0 < *value, *value < 0.0)) {
      conditionCode = 2;
    }
    *(undefined1 *)(machine + 0x291) = conditionCode;
  }
  targetY = componentTarget;
  if ((((writeMaskFlags & 0x2000000) != 0) &&
      (emulator = ((int (*)())_InterpreterTestCR)(machine,(*(int *)((unsigned char *)ghidra_home + 4)),(*(int *)((unsigned char *)ghidra_home + 8)),(*(uint *)((unsigned char *)ghidra_home + 12)),
                                  (*(short *)((unsigned char *)ghidra_home + 16)),(*(unsigned int *)((unsigned char *)ghidra_home + 20)),(*(unsigned int *)((unsigned char *)ghidra_home + 24)),(*(unsigned int *)((unsigned char *)ghidra_home + 28)),
                                  writeMaskFlags,conditionSwizzleZW,1), emulator != 0)) &&
     (targetY = (float *)((int)storageBase + componentSlot[1]), (char)updateConditionCode != '\0')) {
    emulator = ___isnanf(emulator);
    conditionCode = 3;
    if ((emulator == 0) && (conditionCode = 0.0 < value[1], value[1] < 0.0)) {
      conditionCode = 2;
    }
    *(undefined1 *)((int)machine + 0xa45) = conditionCode;
  }
  targetZ = componentTarget;
  if ((((writeMaskFlags & 0x4000000) != 0) &&
      (emulator = ((int (*)())_InterpreterTestCR)(machine,(*(int *)((unsigned char *)ghidra_home + 4)),(*(int *)((unsigned char *)ghidra_home + 8)),(*(uint *)((unsigned char *)ghidra_home + 12)),
                                  (*(short *)((unsigned char *)ghidra_home + 16)),(*(unsigned int *)((unsigned char *)ghidra_home + 20)),(*(unsigned int *)((unsigned char *)ghidra_home + 24)),(*(unsigned int *)((unsigned char *)ghidra_home + 28)),
                                  writeMaskFlags,conditionSwizzleZW,2), emulator != 0)) &&
     (targetZ = (float *)((int)storageBase + componentSlot[2]), (char)updateConditionCode != '\0')) {
    emulator = ___isnanf(emulator);
    conditionCode = 3;
    if ((emulator == 0) && (conditionCode = 0.0 < value[2], value[2] < 0.0)) {
      conditionCode = 2;
    }
    *(undefined1 *)((int)machine + 0xa46) = conditionCode;
  }
  if ((((writeMaskFlags & 0x8000000) != 0) &&
      (emulator = ((int (*)())_InterpreterTestCR)(machine,(*(int *)((unsigned char *)ghidra_home + 4)),(*(int *)((unsigned char *)ghidra_home + 8)),(*(uint *)((unsigned char *)ghidra_home + 12)),
                                  (*(short *)((unsigned char *)ghidra_home + 16)),(*(unsigned int *)((unsigned char *)ghidra_home + 20)),(*(unsigned int *)((unsigned char *)ghidra_home + 24)),(*(unsigned int *)((unsigned char *)ghidra_home + 28)),
                                  writeMaskFlags,conditionSwizzleZW,3), emulator != 0)) &&
     (componentTarget = (float *)((int)storageBase + componentSlot[3]), (char)updateConditionCode != '\0')) {
    emulator = ___isnanf(emulator);
    conditionCode = 3;
    if ((emulator == 0) && (conditionCode = 0.0 < value[3], value[3] < 0.0)) {
      conditionCode = 2;
    }
    *(undefined1 *)((int)machine + 0xa47) = conditionCode;
  }
  *targetX = *value;
  *targetY = value[1];
  *targetZ = value[2];
  *componentTarget = value[3];
  return;
}

/* _InterpreterLoadSource @ 0x97bcd924 (796 bytes) */
int _InterpreterLoadSource(machine, componentOffsets, bankIndex, swizzle, indexInfo, storageFlags, operandWord5, valueType, operandWord7, operandWord8, element, result)
  int *machine;
  int *componentOffsets;
  int bankIndex;
  uint swizzle;
  undefined4 indexInfo;
  undefined4 storageFlags;
  undefined4 operandWord5;
  uint valueType;
  undefined4 operandWord7;
  undefined4 operandWord8;
  int element;
  float *result;
{
  float x;
  float y;
  float z;
  float w;
  double intToFloatBias;
  int workPtr;
  int *componentSlot;
  int bankInfo;
  int emulator;
  byte swizzleX;
  byte swizzleY;
  byte swizzleZ;
  short relativeOffset;
  ushort storageClass;
  char negate;
  char relativeAddressing;
  
  intToFloatBias = DOUBLE_97c30a58;
  emulator = *machine;
  workPtr = *(int *)(*(int *)(emulator + 0xd80) + 0x38);
  storageClass = (ushort)((uint)storageFlags >> 0x10);
  swizzleZ = (byte)(swizzle >> 8);
  swizzleY = (byte)(swizzle >> 0x10);
  swizzleX = (byte)(swizzle >> 0x18);
  if (((workPtr == 0x8804) || (workPtr == 0x8b30)) && (storageClass == 2)) {
    workPtr = *(int *)(emulator + 0xda4);
    emulator = *(int *)(emulator + 0xda0);
    x = *(float *)(workPtr + componentOffsets[element * 4 + (uint)swizzleX]) * GH_U2F((unsigned int)(machine[0x28c]))
            + *(float *)(emulator + componentOffsets[element * 4 + (uint)swizzleX]);
    *result = x;
    y = *(float *)(workPtr + componentOffsets[element * 4 + (uint)swizzleY]) * GH_U2F((unsigned int)(machine[0x28c]))
            + *(float *)(emulator + componentOffsets[element * 4 + (uint)swizzleY]);
    result[1] = y;
    z = *(float *)(workPtr + componentOffsets[element * 4 + (uint)swizzleZ]) * GH_U2F((unsigned int)(machine[0x28c]))
            + *(float *)(emulator + componentOffsets[element * 4 + (uint)swizzleZ]);
    result[2] = z;
    w = *(float *)(workPtr + componentOffsets[element * 4 + (swizzle & 0xff)]) * GH_U2F((unsigned int)(machine[0x28c])) +
            *(float *)(emulator + componentOffsets[element * 4 + (swizzle & 0xff)]);
    result[3] = w;
    if (*componentOffsets != 0) {
      *result = x * GH_U2F((unsigned int)(machine[0x28f]));
      result[1] = y * GH_U2F((unsigned int)(machine[0x28f]));
      result[2] = z * GH_U2F((unsigned int)(machine[0x28f]));
      result[3] = w * GH_U2F((unsigned int)(machine[0x28f]));
    }
  }
  else {
    relativeAddressing = (char)storageFlags;
    if (relativeAddressing == '\0') {
      componentSlot = componentOffsets + element * 4;
    }
    else {
      bankInfo = bankIndex * 0xc + *(int *)(emulator + 0xd80);
      relativeOffset = (short)((uint)indexInfo >> 0x10);
      workPtr = *(int *)(bankInfo + 0x80);
      componentSlot = (int *)(workPtr + (((uint)((int)componentOffsets + (element * 0x10 - workPtr)) >> 4) +
                                machine[0x290] + (int)relativeOffset & *(uint *)(bankInfo + 0x88)) *
                               0x10);
    }
    workPtr = *(int *)((uint)storageClass * 4 + emulator + 0xd84);
    if (valueType < 2) {
      *result = *(float *)(workPtr + componentSlot[swizzleX]);
      result[1] = *(float *)(workPtr + componentSlot[swizzleY]);
      result[2] = *(float *)(workPtr + componentSlot[swizzleZ]);
      x = *(float *)(workPtr + componentSlot[swizzle & 0xff]);
    }
    else {
      if (1 < valueType - 3) goto setNegate;
      *result = (float)((double)CONCAT44(0x43300000,
                                           *(uint *)(workPtr + componentSlot[swizzleX]) ^ 0x80000000) -
                         DOUBLE_97c30a58);
      result[1] = (float)((double)CONCAT44(0x43300000,
                                             *(uint *)(workPtr + componentSlot[swizzleY]) ^ 0x80000000)
                           - intToFloatBias);
      result[2] = (float)((double)CONCAT44(0x43300000,
                                             *(uint *)(workPtr + componentSlot[swizzleZ]) ^ 0x80000000)
                           - intToFloatBias);
      x = (float)((double)CONCAT44(0x43300000,
                                       *(uint *)(workPtr + componentSlot[swizzle & 0xff]) ^ 0x80000000) -
                     intToFloatBias);
    }
    result[3] = x;
  }
setNegate:
  negate = (char)((uint)storageFlags >> 8);
  if (negate != '\0') {
    *result = -*result;
    result[1] = -result[1];
    result[2] = -result[2];
    result[3] = -result[3];
  }
  return;
}

/* _InterpreterTestCR @ 0x97bcdc40 (240 bytes) */
int _InterpreterTestCR(machine, operandWord0, operandWord1, operandWord2, operandWord3, operandWord4, operandWord5, operandWord6, conditionWord, conditionSwizzleZW, component)
  int machine;
  undefined4 operandWord0;
  undefined4 operandWord1;
  undefined4 operandWord2;
  undefined4 operandWord3;
  undefined4 operandWord4;
  undefined4 operandWord5;
  undefined4 operandWord6;
  uint conditionWord;
  undefined4 conditionSwizzleZW;
  int component;
{
  uint passes;
  uint conditionCode;
  
  passes = 0;
  conditionCode = (uint)*(byte *)((uint)*(byte *)((int)&conditionWord + component + 2) + machine + 0xa44);
  switch(conditionWord >> 0x10 & 0xff) {
  case 0:
    passes = 1;
    break;
  case 1:
    passes = (uint)(conditionCode == 0);
    break;
  case 2:
    passes = (uint)(conditionCode < 2);
    break;
  case 3:
    passes = (uint)(conditionCode == 1);
    break;
  case 4:
    passes = 0;
    if ((conditionCode == 2) || (conditionCode == 0)) {
      passes = 1;
    }
    break;
  case 5:
    passes = (uint)(conditionCode == 2);
    break;
  case 6:
    passes = -conditionCode >> 0x1f;
    break;
  case 7:
    passes = 0;
  }
  return passes;
}

/* _InterpreterEmulateOp @ 0x97bcdd50 (20820 bytes) */
int * _InterpreterEmulateOp(int *machine,int *inst,double unusedFloatArg1,double scratchF2,double scratchF3,double scratchF4,double scratchF5,double scratchF6,double scratchF7,double scratchF8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float sourceComponentW;
  float smoothT;
  byte vectorDimension;
  uint textureTarget;
  float *srcElementPtr;
  uint destUpdatesCC;
  int sourceOffset;
  int destWriteMask;
  int intComponentI26;
  int destSwizzle;
  int destBankIndex;
  uint sourceElement2;
  int programInfo;
  int intComponentI14;
  int destOffsetTable;
  int sourceCount;
  double logValue;
  double expValue;
  double sqrtValue;
  double log2Value;
  double exp2Value;
  double mathAccumulator;
  double intAsDouble;
  double floorValue;
  double powValue;
  uint intComponent;
  uint dimension;
  uint boolBit;
  float *componentCursor;
  float degRadFactor;
  float squaredComponent;
  float operandComponent;
  int conditionResult;
  double exp2Result2;
  double floorResult2;
  double truncResult;
  double atanResult;
  double acosResult;
  double asinResult;
  double tanResult;
  double sinResult;
  double cosResult;
  double log2Result;
  double exp2Result;
  double sqrtResult;
  double floorResult;
  double ceilResult;
  double powResult;
  uint loopIndex;
  uint loopIndex2;
  float *srcBElement;
  bool cmpResult;
  char saturate;
  byte instUpdateCC;
  char swizzleSelect;
  float dotProduct;
  float logicComponent;
  uint boolBit8;
  byte *srcDimCursor;
  float *operandScratch;
  int *poppedStackTop;
  float *in_r5_artifact;
  int destIndexInfo;
  int destStorageFlags;
  int callStackTop;
  int destWord5;
  int destValueType;
  uint scalarSourceIndex;
  int *nextInst;
  int emulator;
  uint elementCount;
  int opcode;
  int destConditionSwizzleZW;
  float *srcAPtr;
  uint sourceElement;
  bool fallsThrough;
  int sourcesRemaining;
  double texLodBias;
  double mathTemp;
  double floorValue_29;
  double floorValue_30;
  double floorValue_31;
  double leftoverStackArg0;
  double leftoverStackArg1;
  double leftoverStackArg2;
  double leftoverStackArg3;
  double leftoverStackArg4;
  undefined4 destElement;
  float opVec [12];
  float srcC [4];
  float prodC0R0;
  float prodC0R1;
  float prodC0R2;
  float prodC0R3;
  float prodC1R0;
  float prodC1R1;
  float prodC1R2;
  float prodC1R3;
  float prodC2R0;
  float prodC2R1;
  float prodC2R2;
  float prodC2R3;
  float prodC3R0;
  float prodC3R1;
  float prodC3R2;
  float prodC3R3;
  undefined4 i2dHi;
  uint i2dLo;
  longlong d2iScratch1;
  longlong d2iScratch2;
  longlong d2iScratch3;
  longlong d2iScratch4;
  float texelX;
  float texelY;
  float texelZ;
  float texelW;
  float storedComponent;
  
  emulator = *machine;
  nextInst = inst + 0x47;
  if (inst == *(int **)(*(int *)(emulator + 0xd80) + 4)) {
    nextInst = (int *)0x0;
  }
  sourceCount = inst[0xc];
  opVec[3] = 0.0;
  elementCount = 1;
  opVec[0] = 0.0;
  opVec[1] = 0.0;
  fallsThrough = true;
  opVec[2] = 0.0;
  opcode = *inst;
  saturate = *(char *)(inst + 1);
  if (sourceCount != 0) {
    srcDimCursor = (byte *)((int)inst + 0x49);
    sourcesRemaining = sourceCount;
    do {
      if ((srcDimCursor[-1] != 0) && (elementCount < *srcDimCursor)) {
        elementCount = (uint)*srcDimCursor;
      }
      srcDimCursor = srcDimCursor + 0x24;
      sourcesRemaining = sourcesRemaining + -1;
    } while (sourcesRemaining != 0);
  }
  if (opcode == 0x22) {
    saturate = *(char *)(inst + 0x12);
    if ((saturate == '\0') && (*(char *)(inst + 0x1b) == '\0')) {
      ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                 inst[0x12],inst[0x13],inst[0x14],inst[0x15],0,opVec + 4);
      ((int (*)())_InterpreterLoadSource)(machine,inst[0x16],inst[0x17],inst[0x18],inst[0x19],inst[0x1a],
                 inst[0x1b],inst[0x1c],inst[0x1d],inst[0x1e],0,opVec + 8);
      operandScratch = opVec;
      opVec[0] = opVec[4] * opVec[8];
      opVec[1] = opVec[5] * opVec[9];
      opVec[2] = opVec[6] * opVec[10];
      destValueType = inst[9];
      opVec[3] = opVec[7] * opVec[0xb];
      destUpdatesCC = (uint)*(byte *)((int)inst + 6);
      destWriteMask = inst[10];
      destConditionSwizzleZW = inst[0xb];
      destOffsetTable = inst[3];
      destBankIndex = inst[4];
      destSwizzle = inst[5];
      destIndexInfo = inst[6];
      destStorageFlags = inst[7];
      destWord5 = inst[8];
      destElement = 0;
    }
    else if ((saturate == '\0') ||
            ((*(char *)(inst + 0x1b) == '\0' ||
             (*(char *)((int)inst + 0x49) != *(char *)((int)inst + 0x6d))))) {
      if ((saturate == '\0') || (*(byte *)((int)inst + 0x6d) < 2)) {
        if ((*(char *)(inst + 0x1b) == '\0') || (*(byte *)((int)inst + 0x49) < 2)) {
          scalarSourceIndex = (uint)(saturate == '\0');
          if (scalarSourceIndex == 0) {
            sourceOffset = 0x54;
          }
          else {
            sourceOffset = 0x30;
          }
          operandScratch = opVec + 8;
          ((int (*)())_InterpreterLoadSource)(machine,*(undefined4 *)((int)inst + sourceOffset + 4),
                     *(undefined4 *)((int)inst + sourceOffset + 8),
                     *(undefined4 *)((int)inst + sourceOffset + 0xc),
                     *(undefined4 *)((int)inst + sourceOffset + 0x10),
                     *(undefined4 *)((int)inst + sourceOffset + 0x14),
                     *(undefined4 *)((int)inst + sourceOffset + 0x18),
                     *(undefined4 *)((int)inst + sourceOffset + 0x1c),
                     *(undefined4 *)((int)inst + sourceOffset + 0x20),
                     *(undefined4 *)((int)inst + sourceOffset + 0x24),0,opVec + 4);
          ((int (*)())_InterpreterLoadSource)(machine,inst[scalarSourceIndex * 9 + 0xd],inst[scalarSourceIndex * 9 + 0xe],
                     inst[scalarSourceIndex * 9 + 0xf],inst[scalarSourceIndex * 9 + 0x10],inst[scalarSourceIndex * 9 + 0x11]
                     ,inst[scalarSourceIndex * 9 + 0x12],inst[scalarSourceIndex * 9 + 0x13],
                     inst[scalarSourceIndex * 9 + 0x14],inst[scalarSourceIndex * 9 + 0x15],0,operandScratch);
          if (elementCount == 2) {
            destElement = 1;
            opVec[0] = opVec[4] * opVec[8];
            opVec[1] = opVec[4] * opVec[9];
            ((int (*)())_InterpreterWriteDestination)(machine,inst[3],inst[4],inst[5],inst[6],inst[7],inst[8],
                       inst[9],inst[10],inst[0xb],0,opVec,
                       (uint)*(byte *)((int)inst + 6));
            ((int (*)())_InterpreterLoadSource)(machine,inst[scalarSourceIndex * 9 + 0xd],inst[scalarSourceIndex * 9 + 0xe],
                       inst[scalarSourceIndex * 9 + 0xf],inst[scalarSourceIndex * 9 + 0x10],
                       inst[scalarSourceIndex * 9 + 0x11],inst[scalarSourceIndex * 9 + 0x12],
                       inst[scalarSourceIndex * 9 + 0x13],inst[scalarSourceIndex * 9 + 0x14],
                       inst[scalarSourceIndex * 9 + 0x15],1,operandScratch);
            opVec[0] = opVec[4] * opVec[8];
            destValueType = inst[9];
            opVec[1] = opVec[4] * opVec[9];
            instUpdateCC = *(byte *)((int)inst + 6);
            destWriteMask = inst[10];
            destConditionSwizzleZW = inst[0xb];
            destOffsetTable = inst[3];
            destBankIndex = inst[4];
            destSwizzle = inst[5];
            destIndexInfo = inst[6];
            destStorageFlags = inst[7];
            destWord5 = inst[8];
          }
          else if (elementCount == 3) {
            opVec[0] = opVec[4] * opVec[8];
            opVec[2] = opVec[4] * opVec[10];
            opVec[1] = opVec[4] * opVec[9];
            ((int (*)())_InterpreterWriteDestination)(machine,inst[3],inst[4],inst[5],inst[6],inst[7],inst[8],
                       inst[9],inst[10],inst[0xb],0,opVec,
                       (uint)*(byte *)((int)inst + 6));
            ((int (*)())_InterpreterLoadSource)(machine,inst[scalarSourceIndex * 9 + 0xd],inst[scalarSourceIndex * 9 + 0xe],
                       inst[scalarSourceIndex * 9 + 0xf],inst[scalarSourceIndex * 9 + 0x10],
                       inst[scalarSourceIndex * 9 + 0x11],inst[scalarSourceIndex * 9 + 0x12],
                       inst[scalarSourceIndex * 9 + 0x13],inst[scalarSourceIndex * 9 + 0x14],
                       inst[scalarSourceIndex * 9 + 0x15],1,operandScratch);
            opVec[0] = opVec[4] * opVec[8];
            opVec[2] = opVec[4] * opVec[10];
            opVec[1] = opVec[4] * opVec[9];
            ((int (*)())_InterpreterWriteDestination)(machine,inst[3],inst[4],inst[5],inst[6],inst[7],inst[8],
                       inst[9],inst[10],inst[0xb],1,opVec,
                       (uint)*(byte *)((int)inst + 6));
            ((int (*)())_InterpreterLoadSource)(machine,inst[scalarSourceIndex * 9 + 0xd],inst[scalarSourceIndex * 9 + 0xe],
                       inst[scalarSourceIndex * 9 + 0xf],inst[scalarSourceIndex * 9 + 0x10],
                       inst[scalarSourceIndex * 9 + 0x11],inst[scalarSourceIndex * 9 + 0x12],
                       inst[scalarSourceIndex * 9 + 0x13],inst[scalarSourceIndex * 9 + 0x14],
                       inst[scalarSourceIndex * 9 + 0x15],2,operandScratch);
            opVec[0] = opVec[4] * opVec[8];
            opVec[2] = opVec[4] * opVec[10];
            destValueType = inst[9];
            opVec[1] = opVec[4] * opVec[9];
            instUpdateCC = *(byte *)((int)inst + 6);
            destWriteMask = inst[10];
            destConditionSwizzleZW = inst[0xb];
            destOffsetTable = inst[3];
            destBankIndex = inst[4];
            destSwizzle = inst[5];
            destIndexInfo = inst[6];
            destStorageFlags = inst[7];
            destWord5 = inst[8];
            destElement = 2;
          }
          else {
            if (elementCount != 4) {
              return nextInst;
            }
            opVec[0] = opVec[4] * opVec[8];
            opVec[3] = opVec[4] * opVec[0xb];
            opVec[1] = opVec[4] * opVec[9];
            opVec[2] = opVec[4] * opVec[10];
            ((int (*)())_InterpreterWriteDestination)(machine,inst[3],inst[4],inst[5],inst[6],inst[7],inst[8],
                       inst[9],inst[10],inst[0xb],0,opVec,
                       (uint)*(byte *)((int)inst + 6));
            ((int (*)())_InterpreterLoadSource)(machine,inst[scalarSourceIndex * 9 + 0xd],inst[scalarSourceIndex * 9 + 0xe],
                       inst[scalarSourceIndex * 9 + 0xf],inst[scalarSourceIndex * 9 + 0x10],
                       inst[scalarSourceIndex * 9 + 0x11],inst[scalarSourceIndex * 9 + 0x12],
                       inst[scalarSourceIndex * 9 + 0x13],inst[scalarSourceIndex * 9 + 0x14],
                       inst[scalarSourceIndex * 9 + 0x15],1,operandScratch);
            opVec[0] = opVec[4] * opVec[8];
            opVec[3] = opVec[4] * opVec[0xb];
            opVec[1] = opVec[4] * opVec[9];
            opVec[2] = opVec[4] * opVec[10];
            destElement = 3;
            ((int (*)())_InterpreterWriteDestination)(machine,inst[3],inst[4],inst[5],inst[6],inst[7],inst[8],
                       inst[9],inst[10],inst[0xb],1,opVec,
                       (uint)*(byte *)((int)inst + 6));
            ((int (*)())_InterpreterLoadSource)(machine,inst[scalarSourceIndex * 9 + 0xd],inst[scalarSourceIndex * 9 + 0xe],
                       inst[scalarSourceIndex * 9 + 0xf],inst[scalarSourceIndex * 9 + 0x10],
                       inst[scalarSourceIndex * 9 + 0x11],inst[scalarSourceIndex * 9 + 0x12],
                       inst[scalarSourceIndex * 9 + 0x13],inst[scalarSourceIndex * 9 + 0x14],
                       inst[scalarSourceIndex * 9 + 0x15],2,operandScratch);
            opVec[0] = opVec[4] * opVec[8];
            opVec[3] = opVec[4] * opVec[0xb];
            opVec[1] = opVec[4] * opVec[9];
            opVec[2] = opVec[4] * opVec[10];
            ((int (*)())_InterpreterWriteDestination)(machine,inst[3],inst[4],inst[5],inst[6],inst[7],inst[8],
                       inst[9],inst[10],inst[0xb],2,opVec,
                       (uint)*(byte *)((int)inst + 6));
            ((int (*)())_InterpreterLoadSource)(machine,inst[scalarSourceIndex * 9 + 0xd],inst[scalarSourceIndex * 9 + 0xe],
                       inst[scalarSourceIndex * 9 + 0xf],inst[scalarSourceIndex * 9 + 0x10],
                       inst[scalarSourceIndex * 9 + 0x11],inst[scalarSourceIndex * 9 + 0x12],
                       inst[scalarSourceIndex * 9 + 0x13],inst[scalarSourceIndex * 9 + 0x14],
                       inst[scalarSourceIndex * 9 + 0x15],3,operandScratch);
            opVec[0] = opVec[4] * opVec[8];
            opVec[3] = opVec[4] * opVec[0xb];
            opVec[1] = opVec[4] * opVec[9];
            destValueType = inst[9];
            opVec[2] = opVec[4] * opVec[10];
            instUpdateCC = *(byte *)((int)inst + 6);
            destWriteMask = inst[10];
            destConditionSwizzleZW = inst[0xb];
            destOffsetTable = inst[3];
            destBankIndex = inst[4];
            destSwizzle = inst[5];
            destIndexInfo = inst[6];
            destStorageFlags = inst[7];
            destWord5 = inst[8];
          }
          operandScratch = opVec;
          destUpdatesCC = (uint)instUpdateCC;
          goto callInterpreterWriteDestination;
        }
        operandScratch = opVec + 8;
        ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                   inst[0x12],inst[0x13],inst[0x14],inst[0x15],0,opVec + 4);
        ((int (*)())_InterpreterLoadSource)(machine,inst[0x16],inst[0x17],inst[0x18],inst[0x19],inst[0x1a],
                   inst[0x1b],inst[0x1c],inst[0x1d],inst[0x1e],0,operandScratch);
        if (elementCount == 2) {
          opVec[0] = opVec[4] * opVec[8] + opVec[5] * opVec[9];
          ((int (*)())_InterpreterLoadSource)(machine,inst[0x16],inst[0x17],inst[0x18],inst[0x19],inst[0x1a],
                     inst[0x1b],inst[0x1c],inst[0x1d],inst[0x1e],1,operandScratch);
          opVec[1] = opVec[4] * opVec[8] + opVec[5] * opVec[9];
        }
        else if (elementCount == 3) {
          opVec[0] = opVec[6] * opVec[10] +
                         opVec[4] * opVec[8] + opVec[5] * opVec[9];
          ((int (*)())_InterpreterLoadSource)(machine,inst[0x16],inst[0x17],inst[0x18],inst[0x19],inst[0x1a],
                     inst[0x1b],inst[0x1c],inst[0x1d],inst[0x1e],1,operandScratch);
          opVec[1] = opVec[6] * opVec[10] +
                         opVec[4] * opVec[8] + opVec[5] * opVec[9];
          ((int (*)())_InterpreterLoadSource)(machine,inst[0x16],inst[0x17],inst[0x18],inst[0x19],inst[0x1a],
                     inst[0x1b],inst[0x1c],inst[0x1d],inst[0x1e],2,operandScratch);
          opVec[2] = opVec[6] * opVec[10] +
                         opVec[4] * opVec[8] + opVec[5] * opVec[9];
        }
        else if (elementCount == 4) {
          opVec[0] = opVec[7] * opVec[0xb] +
                         opVec[6] * opVec[10] +
                         opVec[4] * opVec[8] + opVec[5] * opVec[9];
          ((int (*)())_InterpreterLoadSource)(machine,inst[0x16],inst[0x17],inst[0x18],inst[0x19],inst[0x1a],
                     inst[0x1b],inst[0x1c],inst[0x1d],inst[0x1e],1,operandScratch);
          opVec[1] = opVec[7] * opVec[0xb] +
                         opVec[6] * opVec[10] +
                         opVec[4] * opVec[8] + opVec[5] * opVec[9];
          ((int (*)())_InterpreterLoadSource)(machine,inst[0x16],inst[0x17],inst[0x18],inst[0x19],inst[0x1a],
                     inst[0x1b],inst[0x1c],inst[0x1d],inst[0x1e],2,operandScratch);
          opVec[2] = opVec[7] * opVec[0xb] +
                         opVec[6] * opVec[10] +
                         opVec[4] * opVec[8] + opVec[5] * opVec[9];
          ((int (*)())_InterpreterLoadSource)(machine,inst[0x16],inst[0x17],inst[0x18],inst[0x19],inst[0x1a],
                     inst[0x1b],inst[0x1c],inst[0x1d],inst[0x1e],3,operandScratch);
          opVec[3] = opVec[7] * opVec[0xb] +
                         opVec[6] * opVec[10] +
                         opVec[4] * opVec[8] + opVec[5] * opVec[9];
        }
      }
      else {
        operandScratch = opVec + 8;
        ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                   inst[0x12],inst[0x13],inst[0x14],inst[0x15],0,operandScratch);
        ((int (*)())_InterpreterLoadSource)(machine,inst[0x16],inst[0x17],inst[0x18],inst[0x19],inst[0x1a],
                   inst[0x1b],inst[0x1c],inst[0x1d],inst[0x1e],0,opVec + 4);
        if (elementCount == 2) {
          opVec[0] = opVec[4] * opVec[8];
          opVec[1] = opVec[4] * opVec[9];
          ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                     inst[0x12],inst[0x13],inst[0x14],inst[0x15],1,operandScratch);
          opVec[0] = opVec[5] * opVec[8] + opVec[0];
          opVec[1] = opVec[5] * opVec[9] + opVec[1];
        }
        else if (elementCount == 3) {
          opVec[0] = opVec[4] * opVec[8];
          opVec[2] = opVec[4] * opVec[10];
          opVec[1] = opVec[4] * opVec[9];
          ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                     inst[0x12],inst[0x13],inst[0x14],inst[0x15],1,operandScratch);
          opVec[0] = opVec[5] * opVec[8] + opVec[0];
          opVec[2] = opVec[5] * opVec[10] + opVec[2];
          opVec[1] = opVec[5] * opVec[9] + opVec[1];
          ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                     inst[0x12],inst[0x13],inst[0x14],inst[0x15],2,operandScratch);
          opVec[0] = opVec[6] * opVec[8] + opVec[0];
          opVec[2] = opVec[6] * opVec[10] + opVec[2];
          opVec[1] = opVec[6] * opVec[9] + opVec[1];
        }
        else if (elementCount == 4) {
          opVec[0] = opVec[4] * opVec[8];
          opVec[3] = opVec[4] * opVec[0xb];
          opVec[1] = opVec[4] * opVec[9];
          opVec[2] = opVec[4] * opVec[10];
          ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                     inst[0x12],inst[0x13],inst[0x14],inst[0x15],1,operandScratch);
          opVec[0] = opVec[5] * opVec[8] + opVec[0];
          opVec[3] = opVec[5] * opVec[0xb] + opVec[3];
          opVec[1] = opVec[5] * opVec[9] + opVec[1];
          opVec[2] = opVec[5] * opVec[10] + opVec[2];
          ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                     inst[0x12],inst[0x13],inst[0x14],inst[0x15],2,operandScratch);
          opVec[0] = opVec[6] * opVec[8] + opVec[0];
          opVec[3] = opVec[6] * opVec[0xb] + opVec[3];
          opVec[1] = opVec[6] * opVec[9] + opVec[1];
          opVec[2] = opVec[6] * opVec[10] + opVec[2];
          ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                     inst[0x12],inst[0x13],inst[0x14],inst[0x15],3,operandScratch);
          opVec[0] = opVec[7] * opVec[8] + opVec[0];
          opVec[3] = opVec[7] * opVec[0xb] + opVec[3];
          opVec[1] = opVec[7] * opVec[9] + opVec[1];
          opVec[2] = opVec[7] * opVec[10] + opVec[2];
        }
      }
      destUpdatesCC = (uint)*(byte *)((int)inst + 6);
      destWriteMask = inst[10];
      operandScratch = opVec;
      destConditionSwizzleZW = inst[0xb];
      destValueType = inst[9];
      destOffsetTable = inst[3];
      destBankIndex = inst[4];
      destSwizzle = inst[5];
      destIndexInfo = inst[6];
      destStorageFlags = inst[7];
      destWord5 = inst[8];
      destElement = 0;
    }
    else if (elementCount == 2) {
      operandScratch = opVec + 4;
      ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                 inst[0x12],inst[0x13],inst[0x14],inst[0x15],0,operandScratch);
      ((int (*)())_InterpreterLoadSource)(machine,inst[0x16],inst[0x17],inst[0x18],inst[0x19],inst[0x1a],
                 inst[0x1b],inst[0x1c],inst[0x1d],inst[0x1e],0,opVec + 8);
      prodC0R0 = opVec[4] * opVec[8];
      prodC0R1 = opVec[5] * opVec[8];
      ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                 inst[0x12],inst[0x13],inst[0x14],inst[0x15],1,operandScratch);
      prodC0R0 = opVec[4] * opVec[9] + prodC0R0;
      prodC0R1 = opVec[5] * opVec[9] + prodC0R1;
      ((int (*)())_InterpreterLoadSource)(machine,inst[0x16],inst[0x17],inst[0x18],inst[0x19],inst[0x1a],
                 inst[0x1b],inst[0x1c],inst[0x1d],inst[0x1e],1,opVec + 8);
      prodC1R0 = opVec[4] * opVec[9];
      prodC1R1 = opVec[5] * opVec[9];
      ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                 inst[0x12],inst[0x13],inst[0x14],inst[0x15],0,operandScratch);
      prodC1R0 = opVec[4] * opVec[8] + prodC1R0;
      prodC1R1 = opVec[5] * opVec[8] + prodC1R1;
      ((int (*)())_InterpreterWriteDestination)(machine,inst[3],inst[4],inst[5],inst[6],inst[7],inst[8],
                 inst[9],inst[10],inst[0xb],0,&prodC0R0,(uint)*(byte *)((int)inst + 6));
      destValueType = inst[9];
      destUpdatesCC = (uint)*(byte *)((int)inst + 6);
      operandScratch = &prodC1R0;
      destWriteMask = inst[10];
      destConditionSwizzleZW = inst[0xb];
      destOffsetTable = inst[3];
      destBankIndex = inst[4];
      destSwizzle = inst[5];
      destIndexInfo = inst[6];
      destStorageFlags = inst[7];
      destWord5 = inst[8];
      destElement = 1;
    }
    else if (elementCount == 3) {
      srcAPtr = opVec + 4;
      operandScratch = opVec + 8;
      ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                 inst[0x12],inst[0x13],inst[0x14],inst[0x15],0,srcAPtr);
      ((int (*)())_InterpreterLoadSource)(machine,inst[0x16],inst[0x17],inst[0x18],inst[0x19],inst[0x1a],
                 inst[0x1b],inst[0x1c],inst[0x1d],inst[0x1e],0,operandScratch);
      prodC0R0 = opVec[4] * opVec[8];
      prodC0R2 = opVec[6] * opVec[8];
      prodC0R1 = opVec[5] * opVec[8];
      ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                 inst[0x12],inst[0x13],inst[0x14],inst[0x15],1,srcAPtr);
      prodC0R0 = opVec[4] * opVec[9] + prodC0R0;
      prodC0R2 = opVec[6] * opVec[9] + prodC0R2;
      prodC0R1 = opVec[5] * opVec[9] + prodC0R1;
      ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                 inst[0x12],inst[0x13],inst[0x14],inst[0x15],2,srcAPtr);
      prodC0R0 = opVec[4] * opVec[10] + prodC0R0;
      prodC0R2 = opVec[6] * opVec[10] + prodC0R2;
      prodC0R1 = opVec[5] * opVec[10] + prodC0R1;
      ((int (*)())_InterpreterLoadSource)(machine,inst[0x16],inst[0x17],inst[0x18],inst[0x19],inst[0x1a],
                 inst[0x1b],inst[0x1c],inst[0x1d],inst[0x1e],1,operandScratch);
      prodC1R0 = opVec[4] * opVec[10];
      prodC1R2 = opVec[6] * opVec[10];
      prodC1R1 = opVec[5] * opVec[10];
      ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                 inst[0x12],inst[0x13],inst[0x14],inst[0x15],1,srcAPtr);
      prodC1R0 = opVec[4] * opVec[9] + prodC1R0;
      prodC1R2 = opVec[6] * opVec[9] + prodC1R2;
      prodC1R1 = opVec[5] * opVec[9] + prodC1R1;
      ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                 inst[0x12],inst[0x13],inst[0x14],inst[0x15],0,srcAPtr);
      prodC1R0 = opVec[4] * opVec[8] + prodC1R0;
      prodC1R2 = opVec[6] * opVec[8] + prodC1R2;
      prodC1R1 = opVec[5] * opVec[8] + prodC1R1;
      ((int (*)())_InterpreterLoadSource)(machine,inst[0x16],inst[0x17],inst[0x18],inst[0x19],inst[0x1a],
                 inst[0x1b],inst[0x1c],inst[0x1d],inst[0x1e],2,operandScratch);
      prodC2R0 = opVec[4] * opVec[8];
      prodC2R2 = opVec[6] * opVec[8];
      prodC2R1 = opVec[5] * opVec[8];
      ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                 inst[0x12],inst[0x13],inst[0x14],inst[0x15],1,srcAPtr);
      prodC2R0 = opVec[4] * opVec[9] + prodC2R0;
      prodC2R2 = opVec[6] * opVec[9] + prodC2R2;
      prodC2R1 = opVec[5] * opVec[9] + prodC2R1;
      ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                 inst[0x12],inst[0x13],inst[0x14],inst[0x15],2,srcAPtr);
      prodC2R0 = opVec[4] * opVec[10] + prodC2R0;
      prodC2R2 = opVec[6] * opVec[10] + prodC2R2;
      prodC2R1 = opVec[5] * opVec[10] + prodC2R1;
      ((int (*)())_InterpreterWriteDestination)(machine,inst[3],inst[4],inst[5],inst[6],inst[7],inst[8],
                 inst[9],inst[10],inst[0xb],0,&prodC0R0,(uint)*(byte *)((int)inst + 6));
      ((int (*)())_InterpreterWriteDestination)(machine,inst[3],inst[4],inst[5],inst[6],inst[7],inst[8],
                 inst[9],inst[10],inst[0xb],1,&prodC1R0,(uint)*(byte *)((int)inst + 6));
      destValueType = inst[9];
      destUpdatesCC = (uint)*(byte *)((int)inst + 6);
      operandScratch = &prodC2R0;
      destWriteMask = inst[10];
      destConditionSwizzleZW = inst[0xb];
      destOffsetTable = inst[3];
      destBankIndex = inst[4];
      destSwizzle = inst[5];
      destIndexInfo = inst[6];
      destStorageFlags = inst[7];
      destWord5 = inst[8];
      destElement = 2;
    }
    else {
      if (elementCount != 4) {
        return nextInst;
      }
      srcAPtr = opVec + 4;
      operandScratch = opVec + 8;
      ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                 inst[0x12],inst[0x13],inst[0x14],inst[0x15],0,srcAPtr);
      ((int (*)())_InterpreterLoadSource)(machine,inst[0x16],inst[0x17],inst[0x18],inst[0x19],inst[0x1a],
                 inst[0x1b],inst[0x1c],inst[0x1d],inst[0x1e],0,operandScratch);
      prodC0R0 = opVec[4] * opVec[8];
      prodC0R3 = opVec[7] * opVec[8];
      prodC0R1 = opVec[5] * opVec[8];
      prodC0R2 = opVec[6] * opVec[8];
      ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                 inst[0x12],inst[0x13],inst[0x14],inst[0x15],1,srcAPtr);
      prodC0R0 = opVec[4] * opVec[9] + prodC0R0;
      prodC0R3 = opVec[7] * opVec[9] + prodC0R3;
      prodC0R1 = opVec[5] * opVec[9] + prodC0R1;
      prodC0R2 = opVec[6] * opVec[9] + prodC0R2;
      ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                 inst[0x12],inst[0x13],inst[0x14],inst[0x15],2,srcAPtr);
      prodC0R0 = opVec[4] * opVec[10] + prodC0R0;
      prodC0R3 = opVec[7] * opVec[10] + prodC0R3;
      prodC0R1 = opVec[5] * opVec[10] + prodC0R1;
      prodC0R2 = opVec[6] * opVec[10] + prodC0R2;
      ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                 inst[0x12],inst[0x13],inst[0x14],inst[0x15],3,srcAPtr);
      prodC0R0 = opVec[4] * opVec[0xb] + prodC0R0;
      prodC0R3 = opVec[7] * opVec[0xb] + prodC0R3;
      prodC0R1 = opVec[5] * opVec[0xb] + prodC0R1;
      prodC0R2 = opVec[6] * opVec[0xb] + prodC0R2;
      ((int (*)())_InterpreterLoadSource)(machine,inst[0x16],inst[0x17],inst[0x18],inst[0x19],inst[0x1a],
                 inst[0x1b],inst[0x1c],inst[0x1d],inst[0x1e],1,operandScratch);
      prodC1R0 = opVec[4] * opVec[0xb];
      prodC1R3 = opVec[7] * opVec[0xb];
      prodC1R1 = opVec[5] * opVec[0xb];
      prodC1R2 = opVec[6] * opVec[0xb];
      ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                 inst[0x12],inst[0x13],inst[0x14],inst[0x15],2,srcAPtr);
      prodC1R0 = opVec[4] * opVec[10] + prodC1R0;
      prodC1R3 = opVec[7] * opVec[10] + prodC1R3;
      prodC1R1 = opVec[5] * opVec[10] + prodC1R1;
      prodC1R2 = opVec[6] * opVec[10] + prodC1R2;
      ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                 inst[0x12],inst[0x13],inst[0x14],inst[0x15],1,srcAPtr);
      prodC1R0 = opVec[4] * opVec[9] + prodC1R0;
      prodC1R3 = opVec[7] * opVec[9] + prodC1R3;
      prodC1R1 = opVec[5] * opVec[9] + prodC1R1;
      prodC1R2 = opVec[6] * opVec[9] + prodC1R2;
      ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                 inst[0x12],inst[0x13],inst[0x14],inst[0x15],0,srcAPtr);
      prodC1R0 = opVec[4] * opVec[8] + prodC1R0;
      prodC1R3 = opVec[7] * opVec[8] + prodC1R3;
      prodC1R1 = opVec[5] * opVec[8] + prodC1R1;
      prodC1R2 = opVec[6] * opVec[8] + prodC1R2;
      ((int (*)())_InterpreterLoadSource)(machine,inst[0x16],inst[0x17],inst[0x18],inst[0x19],inst[0x1a],
                 inst[0x1b],inst[0x1c],inst[0x1d],inst[0x1e],2,operandScratch);
      prodC2R0 = opVec[4] * opVec[8];
      prodC2R3 = opVec[7] * opVec[8];
      prodC2R1 = opVec[5] * opVec[8];
      prodC2R2 = opVec[6] * opVec[8];
      ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                 inst[0x12],inst[0x13],inst[0x14],inst[0x15],1,srcAPtr);
      prodC2R0 = opVec[4] * opVec[9] + prodC2R0;
      prodC2R3 = opVec[7] * opVec[9] + prodC2R3;
      prodC2R1 = opVec[5] * opVec[9] + prodC2R1;
      prodC2R2 = opVec[6] * opVec[9] + prodC2R2;
      ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                 inst[0x12],inst[0x13],inst[0x14],inst[0x15],2,srcAPtr);
      prodC2R0 = opVec[4] * opVec[10] + prodC2R0;
      prodC2R3 = opVec[7] * opVec[10] + prodC2R3;
      prodC2R1 = opVec[5] * opVec[10] + prodC2R1;
      prodC2R2 = opVec[6] * opVec[10] + prodC2R2;
      ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                 inst[0x12],inst[0x13],inst[0x14],inst[0x15],3,srcAPtr);
      prodC2R0 = opVec[4] * opVec[0xb] + prodC2R0;
      prodC2R3 = opVec[7] * opVec[0xb] + prodC2R3;
      prodC2R1 = opVec[5] * opVec[0xb] + prodC2R1;
      prodC2R2 = opVec[6] * opVec[0xb] + prodC2R2;
      ((int (*)())_InterpreterLoadSource)(machine,inst[0x16],inst[0x17],inst[0x18],inst[0x19],inst[0x1a],
                 inst[0x1b],inst[0x1c],inst[0x1d],inst[0x1e],3,operandScratch);
      prodC3R0 = opVec[4] * opVec[0xb];
      prodC3R3 = opVec[7] * opVec[0xb];
      prodC3R1 = opVec[5] * opVec[0xb];
      prodC3R2 = opVec[6] * opVec[0xb];
      ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                 inst[0x12],inst[0x13],inst[0x14],inst[0x15],2,srcAPtr);
      prodC3R0 = opVec[4] * opVec[10] + prodC3R0;
      prodC3R3 = opVec[7] * opVec[10] + prodC3R3;
      prodC3R1 = opVec[5] * opVec[10] + prodC3R1;
      prodC3R2 = opVec[6] * opVec[10] + prodC3R2;
      ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                 inst[0x12],inst[0x13],inst[0x14],inst[0x15],1,srcAPtr);
      prodC3R0 = opVec[4] * opVec[9] + prodC3R0;
      prodC3R3 = opVec[7] * opVec[9] + prodC3R3;
      prodC3R1 = opVec[5] * opVec[9] + prodC3R1;
      prodC3R2 = opVec[6] * opVec[9] + prodC3R2;
      ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                 inst[0x12],inst[0x13],inst[0x14],inst[0x15],0,srcAPtr);
      prodC3R0 = opVec[4] * opVec[8] + prodC3R0;
      prodC3R3 = opVec[7] * opVec[8] + prodC3R3;
      prodC3R1 = opVec[5] * opVec[8] + prodC3R1;
      prodC3R2 = opVec[6] * opVec[8] + prodC3R2;
      ((int (*)())_InterpreterWriteDestination)(machine,inst[3],inst[4],inst[5],inst[6],inst[7],inst[8],
                 inst[9],inst[10],inst[0xb],0,&prodC0R0,(uint)*(byte *)((int)inst + 6));
      ((int (*)())_InterpreterWriteDestination)(machine,inst[3],inst[4],inst[5],inst[6],inst[7],inst[8],
                 inst[9],inst[10],inst[0xb],1,&prodC1R0,(uint)*(byte *)((int)inst + 6));
      ((int (*)())_InterpreterWriteDestination)(machine,inst[3],inst[4],inst[5],inst[6],inst[7],inst[8],
                 inst[9],inst[10],inst[0xb],2,&prodC2R0,(uint)*(byte *)((int)inst + 6));
      destValueType = inst[9];
      destUpdatesCC = (uint)*(byte *)((int)inst + 6);
      operandScratch = &prodC3R0;
      destWriteMask = inst[10];
      destConditionSwizzleZW = inst[0xb];
      destOffsetTable = inst[3];
      destBankIndex = inst[4];
      destSwizzle = inst[5];
      destIndexInfo = inst[6];
      destStorageFlags = inst[7];
      destWord5 = inst[8];
      destElement = 3;
    }
    goto callInterpreterWriteDestination;
  }
  if ((opcode != 0x31) && (opcode != 0x36)) {
    loopIndex2 = 0;
    if (elementCount == 0) {
      return nextInst;
    }
    do {
      if (sourceCount != 0) {
        sourceElement = loopIndex2;
        if (*(char *)(inst + 0x12) == '\0') {
          sourceElement = 0;
        }
        in_r5_artifact = (float *)inst[0xe];
        ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],in_r5_artifact,inst[0xf],inst[0x10],inst[0x11],inst[0x12]
                   ,inst[0x13],inst[0x14],inst[0x15],sourceElement,opVec + 4);
        if (1 < (uint)inst[0xc]) {
          sourceElement = loopIndex2;
          if (*(char *)(inst + 0x1b) == '\0') {
            sourceElement = 0;
          }
          in_r5_artifact = (float *)inst[0x17];
          ((int (*)())_InterpreterLoadSource)(machine,inst[0x16],in_r5_artifact,inst[0x18],inst[0x19],inst[0x1a],
                     inst[0x1b],inst[0x1c],inst[0x1d],inst[0x1e],sourceElement,opVec + 8);
          if (2 < (uint)inst[0xc]) {
            sourceElement = loopIndex2;
            if (*(char *)(inst + 0x24) == '\0') {
              sourceElement = 0;
            }
            in_r5_artifact = (float *)inst[0x20];
            ((int (*)())_InterpreterLoadSource)(machine,inst[0x1f],in_r5_artifact,inst[0x21],inst[0x22],inst[0x23],
                       inst[0x24],inst[0x25],inst[0x26],inst[0x27],sourceElement,srcC);
          }
        }
      }
      operandComponent = opVec[7];
      switch(opcode) {
      case 0:
opcodeCase0:
        opVec[0] = opVec[4];
        opVec[1] = opVec[5];
        opVec[2] = opVec[6];
        opVec[3] = opVec[7];
        break;
      case 1:
        opVec[0] = 1.0;
        if (opVec[4] <= 0.0) {
          opVec[1] = 0.0;
          opVec[2] = 0.0;
        }
        else {
          storedComponent = opVec[4];
          scratchF2 = (double)opVec[7];
          opVec[1] = opVec[4];
          powResult = _pow((double)opVec[5],scratchF2);
          opVec[2] = (float)powResult;
        }
        goto storeOpVec6;
      case 2:
        opVec[0] = ABS(opVec[4]);
        opVec[1] = ABS(opVec[5]);
        opVec[2] = ABS(opVec[6]);
        opVec[3] = ABS(opVec[7]);
        break;
      case 3:
        ceilResult = _ceil((double)opVec[4]);
        opVec[0] = (float)ceilResult;
        ceilResult = _ceil((double)opVec[5]);
        opVec[1] = (float)ceilResult;
        ceilResult = _ceil((double)opVec[6]);
        opVec[2] = (float)ceilResult;
        powValue = _ceil((double)opVec[7]);
        goto storeOpVec8;
      case 4:
        floorValue_29 = (double)opVec[4];
        floorResult = _floor(floorValue_29);
        mathTemp = (double)opVec[5];
        opVec[0] = (float)(floorValue_29 - floorResult);
        floorResult = _floor(mathTemp);
        floorValue_29 = (double)opVec[6];
        opVec[1] = (float)(mathTemp - floorResult);
        floorResult2 = _floor(floorValue_29);
        floorValue = (double)opVec[7];
        opVec[2] = (float)(floorValue_29 - floorResult2);
        floorResult2 = _floor(floorValue);
        floorValue = floorValue - floorResult2;
        goto storeOpVec4;
      case 5:
        floorResult = _floor((double)opVec[4]);
        opVec[0] = (float)floorResult;
        floorResult = _floor((double)opVec[5]);
        opVec[1] = (float)floorResult;
        floorResult = _floor((double)opVec[6]);
        opVec[2] = (float)floorResult;
        powValue = _floor((double)opVec[7]);
        goto storeOpVec8;
      default:
        goto opcodeCase6;
      case 7:
        if (opVec[4] <= 0.0) {
          if (0.0 <= opVec[4]) {
            opVec[0] = 0.0;
          }
          else {
            opVec[0] = -1.0;
          }
        }
        else {
          opVec[0] = 1.0;
        }
        if (opVec[5] <= 0.0) {
          if (0.0 <= opVec[5]) {
            opVec[1] = 0.0;
          }
          else {
            opVec[1] = -1.0;
          }
        }
        else {
          opVec[1] = 1.0;
        }
        if (opVec[6] <= 0.0) {
          if (0.0 <= opVec[6]) {
            opVec[2] = 0.0;
          }
          else {
            opVec[2] = -1.0;
          }
        }
        else {
          opVec[2] = 1.0;
        }
        if (0.0 < opVec[7]) goto storeOpVec6;
        if (0.0 <= opVec[7]) goto loopStoreOpVec4;
        opVec[3] = -1.0;
        break;
      case 8:
        if (((opVec[4] == 0.0) && (opVec[5] == 0.0)) && (opVec[6] == 0.0)) {
loopSetBoolBit:
          boolBit = 0;
          if (opVec[7] == 0.0) goto setI2dLo;
        }
        boolBit = 1;
        goto setI2dLo;
      case 9:
        boolBit = 0;
        if (((opVec[4] != 0.0) && (opVec[5] != 0.0)) && (opVec[6] != 0.0))
        goto loopSetBoolBit;
setI2dLo:
        i2dLo = boolBit ^ 0x80000000;
        i2dHi = 0x43300000;
        intAsDouble = (double)CONCAT44(0x43300000,boolBit ^ 0x80000000) - 4503601774854144.0;
loopStoreOpVec:
        opVec[0] = (float)intAsDouble;
        opVec[1] = opVec[0];
        opVec[2] = opVec[0];
        opVec[3] = opVec[0];
        break;
      case 10:
        opVec[0] = 1.0;
        if (opVec[4] != 0.0) {
          opVec[0] = 0.0;
        }
        opVec[1] = 1.0;
        if (opVec[5] != 0.0) {
          opVec[1] = 0.0;
        }
        opVec[2] = 1.0;
        if (opVec[6] != 0.0) {
          opVec[2] = 0.0;
        }
        opVec[3] = 1.0;
        if (opVec[7] != 0.0) goto loopStoreOpVec4;
        break;
      case 0xb:
        vectorDimension = *(byte *)((int)inst + 5);
        if (vectorDimension == 2) {
          in_r5_artifact = opVec;
          _InterpreterNoiseGeneratorCalculate2D(machine + 1,opVec + 4,opVec);
        }
        else if (vectorDimension < 3) {
          if (vectorDimension == 1) {
            in_r5_artifact = opVec;
            _InterpreterNoiseGeneratorCalculate1D(machine + 1,opVec + 4,opVec);
          }
        }
        else if (vectorDimension == 3) {
          in_r5_artifact = opVec;
          _InterpreterNoiseGeneratorCalculate3D(machine + 1,opVec + 4,opVec);
        }
        else if (vectorDimension == 4) {
          in_r5_artifact = opVec;
          _InterpreterNoiseGeneratorCalculate4D(machine + 1,opVec + 4,opVec);
        }
        break;
      case 0xc:
        sqrtResult = _sqrt(ABS((double)opVec[4]));
        opVec[0] = (float)sqrtResult;
        sqrtResult = _sqrt(ABS((double)opVec[5]));
        opVec[1] = (float)sqrtResult;
        sqrtResult = _sqrt(ABS((double)opVec[6]));
        opVec[2] = (float)sqrtResult;
        powValue = _sqrt(ABS((double)opVec[7]));
        goto storeOpVec8;
      case 0xd:
        if (*(int *)(*(int *)(emulator + 0xd80) + 0x38) - 0x8b30U < 2) {
          sqrtResult = _sqrt(ABS((double)opVec[4]));
          opVec[0] = (float)(1.0 / sqrtResult);
          sqrtResult = _sqrt(ABS((double)opVec[5]));
          opVec[1] = (float)(1.0 / sqrtResult);
          sqrtResult = _sqrt(ABS((double)opVec[6]));
          opVec[2] = (float)(1.0 / sqrtResult);
          sqrtResult = _sqrt(ABS((double)opVec[7]));
          floorValue = 1.0 / sqrtResult;
          goto storeOpVec4;
        }
        sqrtResult = _sqrt(ABS((double)opVec[7]));
        intAsDouble = 1.0 / sqrtResult;
        goto loopStoreOpVec;
      case 0xe:
        opVec[0] = 1.0 / opVec[7];
        opVec[1] = opVec[0];
        opVec[2] = opVec[0];
        opVec[3] = opVec[0];
        break;
      case 0xf:
        if (opVec[7] <= 1.8446744e+19) {
          if (opVec[7] < 5.421011e-20) {
            opVec[0] = 1.8446744e+19;
            opVec[1] = opVec[0];
            opVec[2] = opVec[0];
            opVec[3] = opVec[0];
            if (opVec[7] < 0.0) {
              if (opVec[7] <= -5.421011e-20) {
                opVec[0] = -5.421011e-20;
                opVec[1] = opVec[0];
                opVec[2] = opVec[0];
                opVec[3] = opVec[0];
                if (-1.8446744e+19 <= opVec[7]) goto storeOpVec;
              }
              else {
                opVec[0] = -1.8446744e+19;
                opVec[1] = opVec[0];
                opVec[2] = opVec[0];
                opVec[3] = opVec[0];
              }
            }
          }
          else {
storeOpVec:
            opVec[0] = 1.0 / opVec[7];
            opVec[1] = opVec[0];
            opVec[2] = opVec[0];
            opVec[3] = opVec[0];
          }
        }
        else {
          opVec[0] = 5.421011e-20;
          opVec[1] = opVec[0];
          opVec[2] = opVec[0];
          opVec[3] = opVec[0];
        }
        break;
      case 0x10:
        if (1 < *(int *)(*(int *)(emulator + 0xd80) + 0x38) - 0x8b30U) {
          mathAccumulator = _exp2((double)opVec[7]);
          goto loopStoreOpVec2;
        }
        exp2Result = _exp2((double)opVec[4]);
        opVec[0] = (float)exp2Result;
        exp2Result = _exp2((double)opVec[5]);
        opVec[1] = (float)exp2Result;
        exp2Result = _exp2((double)opVec[6]);
        opVec[2] = (float)exp2Result;
        powValue = _exp2((double)opVec[7]);
        goto storeOpVec8;
      case 0x11:
        floorResult = _floor((double)opVec[7]);
        exp2Result2 = _exp2((double)(float)floorResult);
        opVec[0] = (float)exp2Result2;
        opVec[1] = (float)((double)opVec[7] - (double)(float)floorResult);
        exp2Value = _exp2((double)opVec[7]);
        goto storeOpVec2;
      case 0x12:
        dimension = (uint)*(byte *)((int)inst + 5);
        mathAccumulator = 0.0;
        if (dimension != 0) {
          componentCursor = opVec + 4;
          do {
            squaredComponent = *componentCursor;
            componentCursor = componentCursor + 1;
            mathAccumulator = (double)(float)((double)squaredComponent * (double)squaredComponent + mathAccumulator);
            dimension = dimension - 1;
          } while (dimension != 0);
        }
loopSetMathAccumulator:
        mathAccumulator = _sqrt(mathAccumulator);
loopStoreOpVec2:
        opVec[0] = (float)mathAccumulator;
        opVec[1] = opVec[0];
        opVec[2] = opVec[0];
        opVec[3] = opVec[0];
        break;
      case 0x13:
        if (1 < *(int *)(*(int *)(emulator + 0xd80) + 0x38) - 0x8b30U) {
          mathAccumulator = (double)opVec[7];
          if (mathAccumulator < 0.0) {
            mathAccumulator = 0.0;
          }
          mathAccumulator = _log2(mathAccumulator);
          goto loopStoreOpVec2;
        }
        log2Value = (double)opVec[4];
        if (log2Value < 0.0) {
          log2Value = 0.0;
        }
        log2Result = _log2(log2Value);
        mathTemp = (double)opVec[5];
        opVec[0] = (float)log2Result;
        if (mathTemp < 0.0) {
          mathTemp = 0.0;
        }
        log2Result = _log2(mathTemp);
        mathTemp = (double)opVec[6];
        opVec[1] = (float)log2Result;
        if (mathTemp < 0.0) {
          mathTemp = 0.0;
        }
        log2Result = _log2(mathTemp);
        mathTemp = (double)opVec[7];
        opVec[2] = (float)log2Result;
        if (mathTemp < 0.0) {
          mathTemp = 0.0;
        }
        powValue = _log2(mathTemp);
        goto storeOpVec8;
      case 0x14:
        mathTemp = ABS((double)opVec[7]);
        log2Result = _log2(mathTemp);
        floorResult = _floor(log2Result);
        opVec[0] = (float)floorResult;
        exp2Result = _exp2((double)opVec[0]);
        opVec[1] = (float)(mathTemp / exp2Result);
        if (mathTemp < 0.0) {
          mathTemp = 0.0;
        }
        exp2Value = _log2(mathTemp);
storeOpVec2:
        opVec[2] = (float)exp2Value;
        opVec[3] = 1.0;
        break;
      case 0x15:
        dimension = (uint)*(byte *)((int)inst + 5);
        sqrtValue = 0.0;
        if (dimension != 0) {
          componentCursor = opVec + 4;
          do {
            squaredComponent = *componentCursor;
            componentCursor = componentCursor + 1;
            sqrtValue = (double)(float)((double)squaredComponent * (double)squaredComponent + sqrtValue);
            dimension = dimension - 1;
          } while (dimension != 0);
        }
        sqrtResult = _sqrt(sqrtValue);
        dimension = (uint)*(byte *)((int)inst + 5);
        if (dimension != 0) {
          componentCursor = opVec;
          do {
            *componentCursor = componentCursor[4] / (float)sqrtResult;
            componentCursor = componentCursor + 1;
            dimension = dimension - 1;
          } while (dimension != 0);
        }
        break;
      case 0x16:
        degRadFactor = 0.017453292;
        goto storeOpVec3;
      case 0x17:
        degRadFactor = 57.29578;
storeOpVec3:
        opVec[0] = opVec[4] * degRadFactor;
        opVec[1] = opVec[5] * degRadFactor;
        opVec[2] = opVec[6] * degRadFactor;
        opVec[3] = opVec[7] * degRadFactor;
        break;
      case 0x18:
        cosResult = _cos((double)opVec[4]);
        opVec[0] = (float)cosResult;
        sinResult = _sin((double)opVec[4]);
        opVec[1] = (float)sinResult;
        opVec[3] = 0.0;
        opVec[2] = 0.0;
        break;
      case 0x19:
        if (1 < *(int *)(*(int *)(emulator + 0xd80) + 0x38) - 0x8b30U) {
          mathAccumulator = _sin((double)opVec[7]);
          goto loopStoreOpVec2;
        }
        sinResult = _sin((double)opVec[4]);
        opVec[0] = (float)sinResult;
        sinResult = _sin((double)opVec[5]);
        opVec[1] = (float)sinResult;
        sinResult = _sin((double)opVec[6]);
        opVec[2] = (float)sinResult;
        powValue = _sin((double)opVec[7]);
        goto storeOpVec8;
      case 0x1a:
        if (1 < *(int *)(*(int *)(emulator + 0xd80) + 0x38) - 0x8b30U) {
          mathAccumulator = _cos((double)opVec[7]);
          goto loopStoreOpVec2;
        }
        cosResult = _cos((double)opVec[4]);
        opVec[0] = (float)cosResult;
        cosResult = _cos((double)opVec[5]);
        opVec[1] = (float)cosResult;
        cosResult = _cos((double)opVec[6]);
        opVec[2] = (float)cosResult;
        powValue = _cos((double)opVec[7]);
        goto storeOpVec8;
      case 0x1b:
        tanResult = _tan((double)opVec[4]);
        opVec[0] = (float)tanResult;
        tanResult = _tan((double)opVec[5]);
        opVec[1] = (float)tanResult;
        tanResult = _tan((double)opVec[6]);
        opVec[2] = (float)tanResult;
        powValue = _tan((double)opVec[7]);
        goto storeOpVec8;
      case 0x1c:
        asinResult = _asin((double)opVec[4]);
        opVec[0] = (float)asinResult;
        asinResult = _asin((double)opVec[5]);
        opVec[1] = (float)asinResult;
        asinResult = _asin((double)opVec[6]);
        opVec[2] = (float)asinResult;
        powValue = _asin((double)opVec[7]);
        goto storeOpVec8;
      case 0x1d:
        acosResult = _acos((double)opVec[4]);
        opVec[0] = (float)acosResult;
        acosResult = _acos((double)opVec[5]);
        opVec[1] = (float)acosResult;
        acosResult = _acos((double)opVec[6]);
        opVec[2] = (float)acosResult;
        powValue = _acos((double)opVec[7]);
        goto storeOpVec8;
      case 0x1e:
        if (inst[0xc] == 1) {
          atanResult = _atan((double)opVec[4]);
          opVec[0] = (float)atanResult;
          atanResult = _atan((double)opVec[5]);
          opVec[1] = (float)atanResult;
          atanResult = _atan((double)opVec[6]);
          opVec[2] = (float)atanResult;
          powValue = _atan((double)opVec[7]);
          goto storeOpVec8;
        }
        opVec[0] = _atan2f(opVec[4],opVec[8]);
        opVec[1] = _atan2f(opVec[5],opVec[9]);
        opVec[2] = _atan2f(opVec[6],opVec[10]);
        scratchF2 = (double)opVec[0xb];
        opVec[3] = _atan2f(opVec[7],opVec[0xb]);
        break;
      case 0x1f:
        opVec[0] = opVec[4] + opVec[8];
        opVec[1] = opVec[5] + opVec[9];
        opVec[2] = opVec[6] + opVec[10];
        opVec[3] = opVec[7] + opVec[0xb];
        break;
      case 0x20:
        opVec[0] = opVec[4] - opVec[8];
        opVec[1] = opVec[5] - opVec[9];
        opVec[2] = opVec[6] - opVec[10];
        opVec[3] = opVec[7] - opVec[0xb];
        break;
      case 0x21:
        if (*(char *)((int)inst + 0x6d) == '\x01') {
          floorValue = (double)opVec[4];
          floorValue_31 = (double)opVec[8];
          floorResult2 = _floor((double)(float)(floorValue / floorValue_31));
          floorValue_29 = (double)opVec[5];
          floorValue_30 = (double)opVec[8];
          opVec[0] = (float)-(floorValue_31 * floorResult2 - floorValue);
          floorResult = _floor((double)(float)(floorValue_29 / floorValue_30));
          mathTemp = (double)opVec[6];
          floorValue_31 = (double)opVec[8];
          opVec[1] = (float)-(floorValue_30 * floorResult - floorValue_29);
          floorResult = _floor((double)(float)(mathTemp / floorValue_31));
          operandComponent = opVec[8];
        }
        else {
          floorValue = (double)opVec[4];
          floorValue_31 = (double)opVec[8];
          floorResult2 = _floor((double)(float)(floorValue / floorValue_31));
          floorValue_29 = (double)opVec[5];
          floorValue_30 = (double)opVec[9];
          opVec[0] = (float)-(floorValue_31 * floorResult2 - floorValue);
          floorResult = _floor((double)(float)(floorValue_29 / floorValue_30));
          mathTemp = (double)opVec[6];
          floorValue_31 = (double)opVec[10];
          opVec[1] = (float)-(floorValue_30 * floorResult - floorValue_29);
          floorResult = _floor((double)(float)(mathTemp / floorValue_31));
          operandComponent = opVec[0xb];
        }
        floorValue_29 = (double)opVec[7];
        opVec[2] = (float)-(floorValue_31 * floorResult - mathTemp);
        floorResult = _floor((double)(float)(floorValue_29 / (double)operandComponent));
        floorValue = -((double)operandComponent * floorResult - floorValue_29);
storeOpVec4:
        opVec[3] = (float)floorValue;
        break;
      case 0x22:
      case 0x31:
      case 0x36:
        break;
      case 0x23:
        opVec[0] = opVec[4] * opVec[8];
        opVec[1] = opVec[5] * opVec[9];
        opVec[2] = opVec[6] * opVec[10];
        opVec[3] = opVec[7] * opVec[0xb];
        break;
      case 0x24:
        boolBit = 0;
        if ((opVec[4] != 0.0) && (opVec[8] != 0.0)) {
          boolBit = 1;
        }
        boolBit8 = 0;
        opVec[0] = (float)((double)CONCAT44(0x43300000,boolBit ^ 0x80000000) - 4503601774854144.0
                              );
        if ((opVec[5] != 0.0) && (opVec[9] != 0.0)) {
          boolBit8 = 1;
        }
        boolBit = 0;
        opVec[1] = (float)((double)CONCAT44(0x43300000,boolBit8 ^ 0x80000000) - 4503601774854144.0)
        ;
        if ((opVec[6] != 0.0) && (opVec[10] != 0.0)) {
          boolBit = 1;
        }
        boolBit8 = 0;
        opVec[2] = (float)((double)CONCAT44(0x43300000,boolBit ^ 0x80000000) - 4503601774854144.0
                              );
        if (opVec[7] != 0.0) {
loopSetBoolBit8:
          boolBit8 = 0;
          if (opVec[0xb] != 0.0) goto loopSetBoolBit82;
        }
        goto setI2dLo2;
      case 0x25:
        boolBit = 0;
        if ((opVec[4] != 0.0) || (opVec[8] != 0.0)) {
          boolBit = 1;
        }
        boolBit8 = 0;
        opVec[0] = (float)((double)CONCAT44(0x43300000,boolBit ^ 0x80000000) - 4503601774854144.0
                              );
        if ((opVec[5] != 0.0) || (opVec[9] != 0.0)) {
          boolBit8 = 1;
        }
        boolBit = 0;
        opVec[1] = (float)((double)CONCAT44(0x43300000,boolBit8 ^ 0x80000000) - 4503601774854144.0)
        ;
        if ((opVec[6] != 0.0) || (opVec[10] != 0.0)) {
          boolBit = 1;
        }
        opVec[2] = (float)((double)CONCAT44(0x43300000,boolBit ^ 0x80000000) - 4503601774854144.0
                              );
        if (opVec[7] == 0.0) goto loopSetBoolBit8;
loopSetBoolBit82:
        boolBit8 = 1;
        goto setI2dLo2;
      case 0x26:
        boolBit = 0;
        if (opVec[4] == 0.0) {
          if (opVec[8] != 0.0) {
loopSetBoolBit2:
            boolBit = 1;
          }
        }
        else if (opVec[8] == 0.0) goto loopSetBoolBit2;
        boolBit8 = 0;
        opVec[0] = (float)((double)CONCAT44(0x43300000,boolBit ^ 0x80000000) - 4503601774854144.0
                              );
        if (opVec[5] == 0.0) {
          if (opVec[9] != 0.0) {
loopSetBoolBit83:
            boolBit8 = 1;
          }
        }
        else if (opVec[9] == 0.0) goto loopSetBoolBit83;
        boolBit = 0;
        opVec[1] = (float)((double)CONCAT44(0x43300000,boolBit8 ^ 0x80000000) - 4503601774854144.0)
        ;
        if (opVec[6] == 0.0) {
          if (opVec[10] != 0.0) {
loopSetBoolBit3:
            boolBit = 1;
          }
        }
        else if (opVec[10] == 0.0) goto loopSetBoolBit3;
        boolBit8 = 0;
        opVec[2] = (float)((double)CONCAT44(0x43300000,boolBit ^ 0x80000000) - 4503601774854144.0
                              );
        if (opVec[7] == 0.0) goto loopSetBoolBit8;
        if (opVec[0xb] == 0.0) goto loopSetBoolBit82;
setI2dLo2:
        i2dLo = boolBit8 ^ 0x80000000;
        i2dHi = 0x43300000;
        opVec[3] = (float)((double)CONCAT44(0x43300000,boolBit8 ^ 0x80000000) - 4503601774854144.0)
        ;
        break;
      case 0x27:
        dimension = (uint)*(byte *)((int)inst + 5);
        opVec[0] = 0.0;
        opVec[1] = opVec[0];
        opVec[2] = opVec[0];
        opVec[3] = opVec[0];
        if (dimension != 0) {
          componentCursor = opVec;
          do {
            srcElementPtr = componentCursor + 4;
            srcBElement = componentCursor + 8;
            componentCursor = componentCursor + 1;
            opVec[0] = *srcElementPtr * *srcBElement + opVec[0];
            dimension = dimension - 1;
            opVec[1] = opVec[0];
            opVec[2] = opVec[0];
            opVec[3] = opVec[0];
          } while (dimension != 0);
        }
        break;
      case 0x28:
        opVec[0] = opVec[6] * opVec[10] +
                       opVec[4] * opVec[8] + opVec[5] * opVec[9];
        opVec[1] = opVec[0];
        opVec[2] = opVec[0];
        opVec[3] = opVec[0];
        break;
      case 0x29:
        opVec[0] = opVec[7] * opVec[0xb] +
                       opVec[6] * opVec[10] +
                       opVec[4] * opVec[8] + opVec[5] * opVec[9];
        opVec[1] = opVec[0];
        opVec[2] = opVec[0];
        opVec[3] = opVec[0];
        break;
      case 0x2a:
        opVec[0] = opVec[6] * opVec[10] +
                       opVec[4] * opVec[8] + opVec[5] * opVec[9] + opVec[0xb];
        opVec[1] = opVec[0];
        opVec[2] = opVec[0];
        opVec[3] = opVec[0];
        break;
      case 0x2b:
        if (*(int *)(*(int *)(emulator + 0xd80) + 0x38) - 0x8b30U < 2) {
          dimension = (uint)*(byte *)((int)inst + 5);
          mathAccumulator = 0.0;
          if (dimension != 0) {
            componentCursor = opVec;
            do {
              srcElementPtr = componentCursor + 4;
              srcBElement = componentCursor + 8;
              componentCursor = componentCursor + 1;
              mathAccumulator = (double)(float)((double)(*srcElementPtr - *srcBElement) * (double)(*srcElementPtr - *srcBElement) +
                                      mathAccumulator);
              dimension = dimension - 1;
            } while (dimension != 0);
          }
          goto loopSetMathAccumulator;
        }
        opVec[0] = 1.0;
        opVec[1] = opVec[5] * opVec[9];
        opVec[2] = opVec[6];
        opVec[3] = opVec[0xb];
        break;
      case 0x2c:
        opVec[0] = opVec[8];
        if (opVec[4] < opVec[8]) {
          opVec[0] = opVec[4];
        }
        opVec[1] = opVec[9];
        if (opVec[5] < opVec[9]) {
          opVec[1] = opVec[5];
        }
        opVec[2] = opVec[10];
        if (opVec[6] < opVec[10]) {
          opVec[2] = opVec[6];
        }
        opVec[3] = opVec[0xb];
        if (opVec[7] < opVec[0xb]) {
loopStoreOpVec3:
          opVec[3] = operandComponent;
        }
        break;
      case 0x2d:
        opVec[0] = opVec[8];
        if (opVec[8] < opVec[4]) {
          opVec[0] = opVec[4];
        }
        opVec[1] = opVec[9];
        if (opVec[9] < opVec[5]) {
          opVec[1] = opVec[5];
        }
        opVec[2] = opVec[10];
        if (opVec[10] < opVec[6]) {
          opVec[2] = opVec[6];
        }
        opVec[3] = opVec[0xb];
        if (opVec[0xb] < opVec[7]) goto loopStoreOpVec3;
        break;
      case 0x2e:
        scratchF6 = (double)opVec[10];
        scratchF7 = (double)opVec[9];
        scratchF8 = (double)opVec[8];
        opVec[0] = (float)((double)opVec[5] * scratchF6 -
                              (double)(float)(scratchF7 * (double)opVec[6]));
        opVec[2] = (float)((double)opVec[4] * scratchF7 -
                              (double)(float)(scratchF8 * (double)opVec[5]));
        opVec[1] = (float)((double)opVec[6] * scratchF8 -
                              (double)(float)(scratchF6 * (double)opVec[4]));
        goto loopStoreOpVec4;
      case 0x2f:
        dimension = (uint)*(byte *)((int)inst + 5);
        dotProduct = 0.0;
        if (dimension != 0) {
          componentCursor = opVec;
          do {
            srcElementPtr = componentCursor + 4;
            srcBElement = componentCursor + 8;
            componentCursor = componentCursor + 1;
            dotProduct = *srcElementPtr * *srcBElement + dotProduct;
            dimension = dimension - 1;
          } while (dimension != 0);
        }
        dotProduct = dotProduct + dotProduct;
        opVec[0] = -(dotProduct * opVec[8] - opVec[4]);
        opVec[1] = -(dotProduct * opVec[9] - opVec[5]);
        opVec[2] = -(dotProduct * opVec[10] - opVec[6]);
        opVec[3] = -(dotProduct * opVec[0xb] - opVec[7]);
        break;
      case 0x30:
        opVec[0] = 1.0;
        opVec[1] = opVec[0];
        opVec[2] = opVec[0];
        opVec[3] = opVec[0];
        break;
      case 0x32:
        opVec[0] = 1.0;
        if (opVec[4] < opVec[8]) {
          opVec[0] = 0.0;
        }
        opVec[1] = 1.0;
        if (opVec[5] < opVec[9]) {
          opVec[1] = 0.0;
        }
        opVec[2] = 1.0;
        if (opVec[6] < opVec[10]) {
          opVec[2] = 0.0;
        }
        cmpResult = opVec[0xb] <= opVec[7];
        goto storeOpVec5;
      case 0x33:
        if (opVec[4] <= opVec[8]) {
          opVec[0] = 0.0;
        }
        else {
          opVec[0] = 1.0;
        }
        if (opVec[5] <= opVec[9]) {
          opVec[1] = 0.0;
        }
        else {
          opVec[1] = 1.0;
        }
        if (opVec[6] <= opVec[10]) {
          opVec[2] = 0.0;
        }
        else {
          opVec[2] = 1.0;
        }
        if (opVec[7] <= opVec[0xb]) goto loopStoreOpVec4;
        goto storeOpVec6;
      case 0x34:
        opVec[0] = 1.0;
        if (opVec[8] < opVec[4]) {
          opVec[0] = 0.0;
        }
        opVec[1] = 1.0;
        if (opVec[9] < opVec[5]) {
          opVec[1] = 0.0;
        }
        opVec[2] = 1.0;
        if (opVec[10] < opVec[6]) {
          opVec[2] = 0.0;
        }
        cmpResult = opVec[7] <= opVec[0xb];
storeOpVec5:
        opVec[3] = 1.0;
        if (!cmpResult) {
loopStoreOpVec4:
          opVec[3] = 0.0;
        }
        break;
      case 0x35:
        if (opVec[8] <= opVec[4]) {
          opVec[0] = 0.0;
        }
        else {
          opVec[0] = 1.0;
        }
        if (opVec[9] <= opVec[5]) {
          opVec[1] = 0.0;
        }
        else {
          opVec[1] = 1.0;
        }
        if (opVec[10] <= opVec[6]) {
          opVec[2] = 0.0;
        }
        else {
          opVec[2] = 1.0;
        }
        if (opVec[0xb] <= opVec[7]) goto loopStoreOpVec4;
storeOpVec6:
        opVec[3] = 1.0;
        break;
      case 0x37:
        opVec[0] = 0.0;
        opVec[1] = opVec[0];
        opVec[2] = opVec[0];
        opVec[3] = opVec[0];
        break;
      case 0x38:
        if (1 < *(int *)(*(int *)(emulator + 0xd80) + 0x38) - 0x8b30U) {
          scratchF2 = (double)opVec[0xb];
          mathAccumulator = _pow((double)opVec[7],scratchF2);
          goto loopStoreOpVec2;
        }
        powResult = _pow((double)opVec[4],(double)opVec[8]);
        opVec[0] = (float)powResult;
        powResult = _pow((double)opVec[5],(double)opVec[9]);
        opVec[1] = (float)powResult;
        powResult = _pow((double)opVec[6],(double)opVec[10]);
        scratchF2 = (double)opVec[0xb];
        opVec[2] = (float)powResult;
        powValue = _pow((double)opVec[7],scratchF2);
        goto storeOpVec8;
      case 0x39:
        if (2.1474836e+09 <= opVec[8]) {
          intComponentI14 = (int)(opVec[8] - 2.1474836e+09);
          d2iScratch2 = (longlong)intComponentI14;
        }
        else {
          intComponentI14 = (int)opVec[8];
          d2iScratch1 = (longlong)intComponentI14;
        }
        opVec[0] = opVec[intComponentI14 + 4];
        if (2.1474836e+09 <= opVec[8]) {
          intComponentI14 = (int)(opVec[8] - 2.1474836e+09);
          d2iScratch1 = (longlong)intComponentI14;
        }
        else {
          intComponentI14 = (int)opVec[8];
          d2iScratch2 = (longlong)intComponentI14;
        }
        opVec[1] = opVec[intComponentI14 + 4];
        if (2.1474836e+09 <= opVec[8]) {
          intComponentI14 = (int)(opVec[8] - 2.1474836e+09);
          d2iScratch1 = (longlong)intComponentI14;
        }
        else {
          intComponentI14 = (int)opVec[8];
          d2iScratch2 = (longlong)intComponentI14;
        }
        opVec[2] = opVec[intComponentI14 + 4];
        if (2.1474836e+09 <= opVec[8]) {
          intComponentI14 = (int)(opVec[8] - 2.1474836e+09);
          d2iScratch1 = (longlong)intComponentI14;
        }
        else {
          intComponentI14 = (int)opVec[8];
          d2iScratch2 = (longlong)intComponentI14;
        }
        opVec[3] = opVec[intComponentI14 + 4];
        break;
      case 0x3a:
        if (inst[9] == 1) {
          opVec[0] = opVec[4] / opVec[8];
          opVec[1] = opVec[5] / opVec[9];
          opVec[2] = opVec[6] / opVec[10];
          opVec[3] = opVec[7] / opVec[0xb];
        }
        else if (inst[9] == 3) {
          truncResult = _trunc((double)(opVec[4] / opVec[8]));
          opVec[0] = (float)truncResult;
          truncResult = _trunc((double)(opVec[5] / opVec[9]));
          opVec[1] = (float)truncResult;
          truncResult = _trunc((double)(opVec[6] / opVec[10]));
          operandComponent = opVec[7] / opVec[0xb];
          goto storeOpVec7;
        }
        break;
      case 0x3b:
        dimension = (uint)*(byte *)((int)inst + 5);
        dotProduct = 0.0;
        if (dimension != 0) {
          componentCursor = opVec;
          do {
            srcElementPtr = componentCursor + 0xc;
            srcBElement = componentCursor + 8;
            componentCursor = componentCursor + 1;
            dotProduct = *srcElementPtr * *srcBElement + dotProduct;
            dimension = dimension - 1;
          } while (dimension != 0);
        }
        if (dotProduct < 0.0) goto opcodeCase0;
        opVec[0] = -opVec[4];
        opVec[1] = -opVec[5];
        opVec[2] = -opVec[6];
        opVec[3] = -opVec[7];
        break;
      case 0x3c:
        scratchF5 = (double)((float)(1.0 - (double)opVec[7]) * srcC[3]);
        opVec[0] = opVec[4] * opVec[8] + (1.0 - opVec[4]) * srcC[0];
        opVec[1] = opVec[5] * opVec[9] + (1.0 - opVec[5]) * srcC[1];
        scratchF8 = (double)opVec[1];
        opVec[2] = opVec[6] * opVec[10] + (1.0 - opVec[6]) * srcC[2];
        scratchF7 = (double)opVec[2];
        opVec[3] = (float)((double)opVec[7] * (double)opVec[0xb] + scratchF5);
        scratchF6 = (double)opVec[3];
        break;
      case 0x3d:
        operandComponent = opVec[8];
        if (opVec[8] < opVec[4]) {
          operandComponent = opVec[4];
        }
        opVec[0] = srcC[0];
        if ((operandComponent < srcC[0]) && (opVec[0] = opVec[8], opVec[8] < opVec[4])) {
          opVec[0] = opVec[4];
        }
        operandComponent = opVec[9];
        if (opVec[9] < opVec[5]) {
          operandComponent = opVec[5];
        }
        opVec[1] = srcC[1];
        if ((operandComponent < srcC[1]) && (opVec[1] = opVec[9], opVec[9] < opVec[5])) {
          opVec[1] = opVec[5];
        }
        operandComponent = opVec[10];
        if (opVec[10] < opVec[6]) {
          operandComponent = opVec[6];
        }
        opVec[2] = srcC[2];
        if ((operandComponent < srcC[2]) && (opVec[2] = opVec[10], opVec[10] < opVec[6]))
        {
          opVec[2] = opVec[6];
        }
        operandComponent = opVec[0xb];
        if (opVec[0xb] < opVec[7]) {
          operandComponent = opVec[7];
        }
        opVec[3] = srcC[3];
        if ((operandComponent < srcC[3]) &&
           (operandComponent = opVec[0xb], opVec[3] = opVec[7], opVec[7] <= opVec[0xb]))
        goto loopStoreOpVec3;
        break;
      case 0x3e:
        opVec[0] = srcC[0];
        if (opVec[4] < 0.0) {
          opVec[0] = opVec[8];
        }
        opVec[1] = srcC[1];
        if (opVec[5] < 0.0) {
          opVec[1] = opVec[9];
        }
        opVec[2] = srcC[2];
        if (opVec[6] < 0.0) {
          opVec[2] = opVec[10];
        }
        opVec[3] = srcC[3];
        if (opVec[7] < 0.0) {
          opVec[3] = opVec[0xb];
        }
        break;
      case 0x3f:
        opVec[0] = opVec[4] * opVec[8] + srcC[0];
        opVec[1] = opVec[5] * opVec[9] + srcC[1];
        opVec[2] = opVec[6] * opVec[10] + srcC[2];
        opVec[3] = opVec[7] * opVec[0xb] + srcC[3];
        break;
      case 0x40:
        operandComponent = (srcC[0] - opVec[4]) / (opVec[8] - opVec[4]);
        if ((operandComponent <= 0.0) || (operandComponent < 1.0)) {
          if (operandComponent <= 0.0) {
            operandComponent = 0.0;
          }
        }
        else {
          operandComponent = 1.0;
        }
        smoothT = (srcC[1] - opVec[5]) / (opVec[9] - opVec[5]);
        opVec[0] = operandComponent * operandComponent * (3.0 - (operandComponent + operandComponent));
        if ((smoothT <= 0.0) || (smoothT < 1.0)) {
          if (smoothT <= 0.0) {
            smoothT = 0.0;
          }
        }
        else {
          smoothT = 1.0;
        }
        operandComponent = (srcC[2] - opVec[6]) / (opVec[10] - opVec[6]);
        opVec[1] = smoothT * smoothT * (3.0 - (smoothT + smoothT));
        if ((operandComponent <= 0.0) || (operandComponent < 1.0)) {
          if (operandComponent <= 0.0) {
            operandComponent = 0.0;
          }
        }
        else {
          operandComponent = 1.0;
        }
        smoothT = (srcC[3] - opVec[7]) / (opVec[0xb] - opVec[7]);
        opVec[2] = operandComponent * operandComponent * (3.0 - (operandComponent + operandComponent));
        if ((smoothT <= 0.0) || (smoothT < 1.0)) {
          if (smoothT <= 0.0) {
            smoothT = 0.0;
          }
        }
        else {
          smoothT = 1.0;
        }
        opVec[3] = smoothT * smoothT * (3.0 - (smoothT + smoothT));
        break;
      case 0x41:
        swizzleSelect = *(char *)(inst + 0x18);
        opVec[0] = opVec[4];
        if ((((swizzleSelect != '\0') && (opVec[0] = opVec[5], swizzleSelect != '\x01')) &&
            (opVec[0] = opVec[6], swizzleSelect != '\x02')) &&
           (opVec[0] = opVec[7], swizzleSelect != '\x03')) {
          operandComponent = opVec[4];
          if (((swizzleSelect == '\x04') || (operandComponent = opVec[5], swizzleSelect == '\x05')) ||
             ((operandComponent = opVec[6], swizzleSelect == '\x06' || (operandComponent = opVec[7], swizzleSelect == '\a')))) {
            opVec[0] = -operandComponent;
          }
          else {
            opVec[0] = 0.0;
            if (((swizzleSelect != '\t') && (opVec[0] = 1.0, swizzleSelect != '\b')) &&
               (opVec[0] = -1.0, swizzleSelect != '\n')) {
              opVec[0] = 0.0;
            }
          }
        }
        swizzleSelect = *(char *)((int)inst + 0x61);
        opVec[1] = opVec[4];
        if ((((swizzleSelect != '\0') && (opVec[1] = opVec[5], swizzleSelect != '\x01')) &&
            (opVec[1] = opVec[6], swizzleSelect != '\x02')) &&
           (opVec[1] = opVec[7], swizzleSelect != '\x03')) {
          operandComponent = opVec[4];
          if (((swizzleSelect == '\x04') || (operandComponent = opVec[5], swizzleSelect == '\x05')) ||
             ((operandComponent = opVec[6], swizzleSelect == '\x06' || (operandComponent = opVec[7], swizzleSelect == '\a')))) {
            opVec[1] = -operandComponent;
          }
          else {
            opVec[1] = 0.0;
            if (((swizzleSelect != '\t') && (opVec[1] = 1.0, swizzleSelect != '\b')) &&
               (opVec[1] = -1.0, swizzleSelect != '\n')) {
              opVec[1] = 0.0;
            }
          }
        }
        swizzleSelect = *(char *)((int)inst + 0x62);
        opVec[2] = opVec[4];
        if ((((swizzleSelect != '\0') && (opVec[2] = opVec[5], swizzleSelect != '\x01')) &&
            (opVec[2] = opVec[6], swizzleSelect != '\x02')) &&
           (opVec[2] = opVec[7], swizzleSelect != '\x03')) {
          operandComponent = opVec[4];
          if (((swizzleSelect == '\x04') || (operandComponent = opVec[5], swizzleSelect == '\x05')) ||
             ((operandComponent = opVec[6], swizzleSelect == '\x06' || (operandComponent = opVec[7], swizzleSelect == '\a')))) {
            opVec[2] = -operandComponent;
          }
          else {
            opVec[2] = 0.0;
            if (((swizzleSelect != '\t') && (opVec[2] = 1.0, swizzleSelect != '\b')) &&
               (opVec[2] = -1.0, swizzleSelect != '\n')) {
              opVec[2] = 0.0;
            }
          }
        }
        swizzleSelect = *(char *)((int)inst + 99);
        opVec[3] = opVec[4];
        if ((((swizzleSelect != '\0') && (opVec[3] = opVec[5], swizzleSelect != '\x01')) &&
            (opVec[3] = opVec[6], swizzleSelect != '\x02')) &&
           (opVec[3] = opVec[7], swizzleSelect != '\x03')) {
          operandComponent = opVec[4];
          if (((swizzleSelect == '\x04') || (operandComponent = opVec[5], swizzleSelect == '\x05')) ||
             ((operandComponent = opVec[6], swizzleSelect == '\x06' || (operandComponent = opVec[7], swizzleSelect == '\a')))) {
            opVec[3] = -operandComponent;
          }
          else {
            opVec[3] = 0.0;
            if (((swizzleSelect != '\t') && (opVec[3] = 1.0, swizzleSelect != '\b')) &&
               (opVec[3] = -1.0, swizzleSelect != '\n')) {
              opVec[3] = 0.0;
            }
          }
        }
        break;
      case 0x42:
      case 0x43:
      case 0x44:
      case 0x45:
        ((int (*)())_InterpreterTextureSamplerAttachGLDContext)(machine[0x28b],*(undefined4 *)(emulator + 0xd9c));
        destElement = 0;
        if ((opcode == 0x43) || (opcode == 0x45)) {
          destElement = 1;
        }
        ((int (*)())_InterpreterTextureSamplerSetProjectionEnabled)(machine[0x28b],destElement);
        ((int (*)())_InterpreterTextureSamplerSetLodBiasEnabled)(machine[0x28b],(uint)(opcode == 0x44 || opcode - 0x44U == 1));
        ((void (*)())_InterpreterTextureSamplerAttachDerivatives)(machine[0x28b],*(undefined4 *)(emulator + 0xda4),(double)GH_U2F((unsigned int)(machine[0x28f])));
        sourceComponentW = opVec[7];
        operandComponent = 0.0;
        if (opcode - 0x44U < 2) {
          programInfo = *(int *)(emulator + 0xd80);
          operandComponent = srcC[0];
          if (1 < *(int *)(programInfo + 0x38) - 0x8b30U) {
            opVec[7] = 1.0;
            operandComponent = sourceComponentW;
            goto setProgramInfo;
          }
        }
        else {
setProgramInfo:
          programInfo = *(int *)(emulator + 0xd80);
        }
        texLodBias = (double)operandComponent;
        if (*(int *)(programInfo + 0x38) - 0x8b30U < 2) {
          if (2.1474836e+09 <= opVec[8]) {
            d2iScratch3 = (longlong)(int)(opVec[8] - 2.1474836e+09);
            intComponent = (int)(opVec[8] - 2.1474836e+09) ^ 0x80000000;
          }
          else {
            intComponent = (uint)(int)opVec[8];
            d2iScratch4 = (longlong)(int)intComponent;
          }
        }
        else {
          intComponent = inst[0x43];
        }
        textureTarget = inst[0x44];
        if (textureTarget == 2) {
          _InterpreterTextureSamplerSampleTexelRECT
                    (machine[0x28b],intComponent,in_r5_artifact,opVec + 4,&texelX);
        }
        else if (textureTarget < 3) {
          if (textureTarget == 1) {
            ((void (*)())_InterpreterTextureSamplerSampleTexel3D)(machine[0x28b],intComponent,in_r5_artifact,opVec + 4,&texelX,texLodBias,scratchF2,scratchF3,
                       scratchF4,scratchF5,scratchF6,scratchF7,scratchF8,leftoverStackArg0,
                       leftoverStackArg1,leftoverStackArg2,leftoverStackArg3);
          }
        }
        else if (textureTarget == 3) {
          ((void (*)())_InterpreterTextureSamplerSampleTexel2D)(machine[0x28b],intComponent,in_r5_artifact,opVec + 4,&texelX,texLodBias,scratchF2,scratchF3,
                     scratchF4,scratchF5,scratchF6,scratchF7,scratchF8,leftoverStackArg0,
                     leftoverStackArg1,leftoverStackArg2,leftoverStackArg3,leftoverStackArg4);
        }
        else if (textureTarget == 4) {
          ((void (*)())_InterpreterTextureSamplerSampleTexel1D)(machine[0x28b],intComponent,in_r5_artifact,opVec + 4,&texelX,texLodBias,scratchF2,scratchF3,
                     scratchF4,scratchF5,scratchF6,scratchF7,scratchF8,leftoverStackArg0,
                     leftoverStackArg1,leftoverStackArg2,leftoverStackArg3);
        }
        opVec[0] = texelX;
        opVec[1] = texelY;
        opVec[2] = texelZ;
        opVec[3] = texelW;
        break;
      case 0x48:
      case 0x49:
        floorResult = _floor((double)opVec[4]);
        if (2147483648.0 <= floorResult) {
          d2iScratch3 = (longlong)(int)(floorResult - 2147483648.0);
          intComponent = (int)(floorResult - 2147483648.0) ^ 0x80000000;
        }
        else {
          intComponent = (uint)(int)floorResult;
          d2iScratch4 = (longlong)(int)intComponent;
        }
        machine[0x290] = intComponent;
        goto opcodeCase6;
      case 0x4b:
        in_r5_artifact = (float *)inst[4];
        conditionResult = ((int (*)())_InterpreterTestCR)(machine,inst[3],in_r5_artifact,inst[5],inst[6],inst[7],
                                    inst[8],inst[9],inst[10],inst[0xb],0);
        if (conditionResult == 0) {
          in_r5_artifact = (float *)inst[4];
          conditionResult = ((int (*)())_InterpreterTestCR)(machine,inst[3],in_r5_artifact,inst[5],inst[6],inst[7],
                                      inst[8],inst[9],inst[10],inst[0xb],1);
          if (conditionResult == 0) {
            in_r5_artifact = (float *)inst[4];
            conditionResult = ((int (*)())_InterpreterTestCR)(machine,inst[3],in_r5_artifact,inst[5],inst[6],inst[7],
                                        inst[8],inst[9],inst[10],inst[0xb],2);
            if (conditionResult == 0) {
              in_r5_artifact = (float *)inst[4];
              conditionResult = ((int (*)())_InterpreterTestCR)(machine,inst[3],in_r5_artifact,inst[5],inst[6],inst[7],
                                          inst[8],inst[9],inst[10],inst[0xb],3);
              if (conditionResult == 0) goto opcodeCase6;
            }
          }
        }
      case 0x54:
      case 0x58:
      case 0x6b:
opcodeCase54:
        nextInst = (int *)((**(int **)(emulator + 0xd80) + inst[2] * 0x11c) - 0x11c);
        if ((int *)(*(int **)(emulator + 0xd80))[1] < nextInst) {
          nextInst = (int *)0x0;
        }
opcodeCase6:
        fallsThrough = false;
        break;
      case 0x4c:
        in_r5_artifact = (float *)inst[4];
        conditionResult = ((int (*)())_InterpreterTestCR)(machine,inst[3],in_r5_artifact,inst[5],inst[6],inst[7],
                                    inst[8],inst[9],inst[10],inst[0xb],0);
        if (conditionResult == 0) {
          in_r5_artifact = (float *)inst[4];
          conditionResult = ((int (*)())_InterpreterTestCR)(machine,inst[3],in_r5_artifact,inst[5],inst[6],inst[7],
                                      inst[8],inst[9],inst[10],inst[0xb],1);
          if (conditionResult == 0) {
            in_r5_artifact = (float *)inst[4];
            conditionResult = ((int (*)())_InterpreterTestCR)(machine,inst[3],in_r5_artifact,inst[5],inst[6],inst[7],
                                        inst[8],inst[9],inst[10],inst[0xb],2);
            if (conditionResult == 0) {
              in_r5_artifact = (float *)inst[4];
              conditionResult = ((int (*)())_InterpreterTestCR)(machine,inst[3],in_r5_artifact,inst[5],inst[6],inst[7],
                                          inst[8],inst[9],inst[10],inst[0xb],3);
              if (conditionResult == 0) goto opcodeCase6;
            }
          }
        }
        if ((uint *)machine[0x29b] + 1 <= machine + 0x29b) {
          *(uint *)machine[0x29b] = (uint)nextInst;
          machine[0x29b] = machine[0x29b] + 4;
          goto opcodeCase54;
        }
        break;
      case 0x4d:
        in_r5_artifact = (float *)inst[4];
        conditionResult = ((int (*)())_InterpreterTestCR)(machine,inst[3],in_r5_artifact,inst[5],inst[6],inst[7],
                                    inst[8],inst[9],inst[10],inst[0xb],0);
        if (conditionResult == 0) {
          in_r5_artifact = (float *)inst[4];
          conditionResult = ((int (*)())_InterpreterTestCR)(machine,inst[3],in_r5_artifact,inst[5],inst[6],inst[7],
                                      inst[8],inst[9],inst[10],inst[0xb],1);
          if (conditionResult == 0) {
            in_r5_artifact = (float *)inst[4];
            conditionResult = ((int (*)())_InterpreterTestCR)(machine,inst[3],in_r5_artifact,inst[5],inst[6],inst[7],
                                        inst[8],inst[9],inst[10],inst[0xb],2);
            if (conditionResult == 0) {
              in_r5_artifact = (float *)inst[4];
              conditionResult = ((int (*)())_InterpreterTestCR)(machine,inst[3],in_r5_artifact,inst[5],inst[6],inst[7],
                                          inst[8],inst[9],inst[10],inst[0xb],3);
              if (conditionResult == 0) goto opcodeCase6;
            }
          }
        }
        callStackTop = machine[0x29b];
        nextInst = (int *)0x0;
        poppedStackTop = (int *)(callStackTop - 4);
        if (machine + 0x297 <= poppedStackTop) {
          machine[0x29b] = (int)poppedStackTop;
          nextInst = *(int **)(callStackTop + -4);
        }
        goto opcodeCase6;
      case 0x4f:
        if (((opVec[4] < 0.0) || (opVec[5] < 0.0)) ||
           ((opVec[6] < 0.0 || (opVec[7] < 0.0)))) {
          machine[0x296] = 1;
        }
        goto opcodeCase6;
      case 0x55:
        if ((((opVec[4] == 0.0) && (opVec[5] == 0.0)) && (opVec[6] == 0.0)) &&
           (opVec[7] == 0.0)) goto opcodeCase54;
        break;
      case 0x68:
        dimension = (uint)*(byte *)((int)inst + 5);
        operandComponent = 0.0;
        if (dimension != 0) {
          componentCursor = opVec;
          do {
            srcElementPtr = componentCursor + 4;
            srcBElement = componentCursor + 8;
            componentCursor = componentCursor + 1;
            operandComponent = *srcElementPtr * *srcBElement + operandComponent;
            dimension = dimension - 1;
          } while (dimension != 0);
        }
        sqrtValue = (double)-(srcC[0] * srcC[0] * (1.0 - operandComponent * operandComponent) - 1.0);
        if (0.0 <= sqrtValue) {
          operandComponent = srcC[0] * operandComponent;
          sqrtResult = _sqrt(sqrtValue);
          mathTemp = (double)srcC[0];
          operandComponent = (float)((double)operandComponent + sqrtResult);
          scratchF7 = (double)(operandComponent * opVec[0xb]);
          opVec[0] = (float)(mathTemp * (double)opVec[4] - (double)(operandComponent * opVec[8]));
          opVec[1] = (float)(mathTemp * (double)opVec[5] - (double)(operandComponent * opVec[9]));
          opVec[2] = (float)(mathTemp * (double)opVec[6] - (double)(operandComponent * opVec[10]));
          scratchF8 = (double)opVec[2];
          opVec[3] = (float)(mathTemp * (double)opVec[7] - scratchF7);
        }
        else {
          opVec[3] = 0.0;
          opVec[0] = 0.0;
          opVec[1] = 0.0;
          opVec[2] = 0.0;
        }
        break;
      case 0x6c:
        if ((inst[9] == 3) && (inst[0x13] == 1)) {
          truncResult = _trunc((double)opVec[4]);
          opVec[0] = (float)truncResult;
          truncResult = _trunc((double)opVec[5]);
          opVec[1] = (float)truncResult;
          truncResult = _trunc((double)opVec[6]);
          operandComponent = opVec[7];
storeOpVec7:
          opVec[2] = (float)truncResult;
          powValue = _trunc((double)operandComponent);
          goto storeOpVec8;
        }
        if ((inst[9] != 4) || ((inst[0x13] != 1 && (inst[0x13] != 3))))
        goto opcodeCase0;
        opVec[0] = 1.0;
        if (opVec[4] == 0.0) {
          opVec[0] = 0.0;
        }
        opVec[1] = 1.0;
        if (opVec[5] == 0.0) {
          opVec[1] = 0.0;
        }
        opVec[2] = 1.0;
        if (opVec[6] == 0.0) {
          opVec[2] = 0.0;
        }
        opVec[3] = 1.0;
        if (opVec[7] == 0.0) goto loopStoreOpVec4;
        break;
      case 0x6d:
        opVec[0] = srcC[0];
        opVec[1] = srcC[1];
        opVec[2] = srcC[2];
        opVec[3] = srcC[3];
        if (2.1474836e+09 <= opVec[8]) {
          intComponentI14 = (int)(opVec[8] - 2.1474836e+09);
          d2iScratch1 = (longlong)intComponentI14;
        }
        else {
          intComponentI14 = (int)opVec[8];
          d2iScratch2 = (longlong)intComponentI14;
        }
        if (2.1474836e+09 <= opVec[8]) {
          intComponentI26 = (int)(opVec[8] - 2.1474836e+09);
          d2iScratch4 = (longlong)intComponentI26;
        }
        else {
          intComponentI26 = (int)opVec[8];
          d2iScratch3 = (longlong)intComponentI26;
        }
        opVec[intComponentI14] = opVec[intComponentI26 + 4];
        break;
      case 0x6f:
        expValue = _exp((double)opVec[4]);
        opVec[0] = (float)expValue;
        expValue = _exp((double)opVec[5]);
        opVec[1] = (float)expValue;
        expValue = _exp((double)opVec[6]);
        opVec[2] = (float)expValue;
        powValue = _exp((double)opVec[7]);
        goto storeOpVec8;
      case 0x70:
        logValue = _log((double)opVec[4]);
        opVec[0] = (float)logValue;
        logValue = _log((double)opVec[5]);
        opVec[1] = (float)logValue;
        logValue = _log((double)opVec[6]);
        opVec[2] = (float)logValue;
        powValue = _log((double)opVec[7]);
storeOpVec8:
        opVec[3] = (float)powValue;
      }
      if (saturate != '\0') {
        if (0.0 <= opVec[0]) {
          if (opVec[0] <= 1.0) {
            storedComponent = opVec[0];
          }
          else {
            opVec[0] = 1.0;
          }
        }
        else {
          opVec[0] = 0.0;
        }
        if (0.0 <= opVec[1]) {
          if (opVec[1] <= 1.0) {
            storedComponent = opVec[1];
          }
          else {
            opVec[1] = 1.0;
          }
        }
        else {
          opVec[1] = 0.0;
        }
        if (0.0 <= opVec[2]) {
          if (opVec[2] <= 1.0) {
            storedComponent = opVec[2];
          }
          else {
            opVec[2] = 1.0;
          }
        }
        else {
          opVec[2] = 0.0;
        }
        if (0.0 <= opVec[3]) {
          if (opVec[3] <= 1.0) {
            storedComponent = opVec[3];
          }
          else {
            opVec[3] = 1.0;
          }
        }
        else {
          opVec[3] = 0.0;
        }
      }
      if (fallsThrough) {
        sourceElement = loopIndex2;
        if (*(char *)(inst + 8) == '\0') {
          sourceElement = 0;
        }
        in_r5_artifact = (float *)inst[4];
        ((int (*)())_InterpreterWriteDestination)(machine,inst[3],in_r5_artifact,inst[5],inst[6],inst[7],inst[8],inst[9],
                   inst[10],inst[0xb],sourceElement,opVec,(uint)*(byte *)((int)inst + 6));
      }
      loopIndex2 = loopIndex2 + 1;
      if (elementCount <= loopIndex2) {
        return nextInst;
      }
      sourceCount = inst[0xc];
    } while( true );
  }
  if (elementCount < 2) {
    ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
               inst[0x12],inst[0x13],inst[0x14],inst[0x15],0,opVec + 4);
    ((int (*)())_InterpreterLoadSource)(machine,inst[0x16],inst[0x17],inst[0x18],inst[0x19],inst[0x1a],
               inst[0x1b],inst[0x1c],inst[0x1d],inst[0x1e],0,opVec + 8);
    if (*(char *)((int)inst + 0x21) == '\x01') {
      saturate = *(char *)((int)inst + 5);
      if (saturate == '\x01') {
loopStoreOpVec5:
        opVec[0] = 1.0;
        if (opVec[5] == opVec[9]) goto storeOpVec9;
      }
      else if (saturate == '\x02') {
        if (opVec[4] == opVec[8]) goto loopStoreOpVec5;
      }
      else if (saturate == '\x03') {
        if ((opVec[4] == opVec[8]) &&
           (fallsThrough = opVec[5] == opVec[9], opVec[5] = opVec[6],
           opVec[9] = opVec[10], fallsThrough)) goto loopStoreOpVec5;
      }
      else {
        if (saturate != '\x04') goto storeOpVec9;
        if (((opVec[4] == opVec[8]) && (opVec[5] == opVec[9])) &&
           (opVec[5] = opVec[7], opVec[9] = opVec[0xb],
           opVec[6] == opVec[10])) goto loopStoreOpVec5;
      }
      opVec[0] = 0.0;
      goto storeOpVec9;
    }
    opVec[0] = 1.0;
    if (opVec[4] != opVec[8]) {
      opVec[0] = 0.0;
    }
    opVec[1] = 1.0;
    if (opVec[5] != opVec[9]) {
      opVec[1] = 0.0;
    }
    opVec[2] = 1.0;
    if (opVec[6] != opVec[10]) {
      opVec[2] = 0.0;
    }
    opVec[3] = 1.0;
    if (opVec[7] != opVec[0xb]) {
      opVec[3] = 0.0;
    }
  }
  else {
    if (elementCount == 3) {
      componentCursor = opVec;
      loopIndex = 0;
      do {
        sourceElement2 = loopIndex;
        if (*(char *)(inst + 0x12) == '\0') {
          sourceElement2 = 0;
        }
        ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                   inst[0x12],inst[0x13],inst[0x14],inst[0x15],sourceElement2,opVec + 4);
        sourceElement2 = loopIndex;
        if (*(char *)(inst + 0x1b) == '\0') {
          sourceElement2 = 0;
        }
        ((int (*)())_InterpreterLoadSource)(machine,inst[0x16],inst[0x17],inst[0x18],inst[0x19],inst[0x1a],
                   inst[0x1b],inst[0x1c],inst[0x1d],inst[0x1e],sourceElement2,opVec + 8);
        if (((opVec[4] != opVec[8]) || (opVec[5] != opVec[9])) ||
           (operandComponent = 1.0, opVec[6] != opVec[10])) {
          operandComponent = 0.0;
        }
        loopIndex = loopIndex + 1;
        *componentCursor = operandComponent;
        componentCursor = componentCursor + 1;
      } while (loopIndex < 3);
      i2dLo = 0;
      operandComponent = opVec[2];
      logicComponent = opVec[1];
      if (opVec[0] != 0.0) goto joined_r0x97bd003c;
loopSetI2dLo:
      i2dLo = i2dLo ^ 0x80000000;
      i2dHi = 0x43300000;
      opVec[0] = (float)((double)CONCAT44(0x43300000,i2dLo) - 4503601774854144.0);
    }
    else if (elementCount < 4) {
      if (elementCount == 2) {
        componentCursor = opVec;
        loopIndex = 0;
        do {
          sourceElement2 = loopIndex;
          if (*(char *)(inst + 0x12) == '\0') {
            sourceElement2 = 0;
          }
          ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                     inst[0x12],inst[0x13],inst[0x14],inst[0x15],sourceElement2,opVec + 4);
          sourceElement2 = loopIndex;
          if (*(char *)(inst + 0x1b) == '\0') {
            sourceElement2 = 0;
          }
          ((int (*)())_InterpreterLoadSource)(machine,inst[0x16],inst[0x17],inst[0x18],inst[0x19],inst[0x1a],
                     inst[0x1b],inst[0x1c],inst[0x1d],inst[0x1e],sourceElement2,opVec + 8);
          if ((opVec[4] != opVec[8]) || (operandComponent = 1.0, opVec[5] != opVec[9])) {
            operandComponent = 0.0;
          }
          loopIndex = loopIndex + 1;
          *componentCursor = operandComponent;
          componentCursor = componentCursor + 1;
          operandComponent = opVec[1];
          logicComponent = opVec[0];
        } while (loopIndex < 2);
joined_r0x97bd003c:
        i2dLo = 0;
        if ((logicComponent != 0.0) && (i2dLo = 0, operandComponent != 0.0)) {
          i2dLo = 1;
        }
        goto loopSetI2dLo;
      }
    }
    else if (elementCount == 4) {
      componentCursor = opVec;
      loopIndex = 0;
      do {
        sourceElement2 = loopIndex;
        if (*(char *)(inst + 0x12) == '\0') {
          sourceElement2 = 0;
        }
        ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                   inst[0x12],inst[0x13],inst[0x14],inst[0x15],sourceElement2,opVec + 4);
        sourceElement2 = loopIndex;
        if (*(char *)(inst + 0x1b) == '\0') {
          sourceElement2 = 0;
        }
        ((int (*)())_InterpreterLoadSource)(machine,inst[0x16],inst[0x17],inst[0x18],inst[0x19],inst[0x1a],
                   inst[0x1b],inst[0x1c],inst[0x1d],inst[0x1e],sourceElement2,opVec + 8);
        if (((opVec[4] != opVec[8]) || (opVec[5] != opVec[9])) ||
           ((opVec[6] != opVec[10] || (operandComponent = 1.0, opVec[7] != opVec[0xb])))) {
          operandComponent = 0.0;
        }
        loopIndex = loopIndex + 1;
        *componentCursor = operandComponent;
        componentCursor = componentCursor + 1;
      } while (loopIndex < 4);
      i2dLo = 0;
      if ((opVec[0] == 0.0) || (operandComponent = opVec[3], logicComponent = opVec[2], opVec[1] == 0.0)
         ) goto loopSetI2dLo;
      goto joined_r0x97bd003c;
    }
storeOpVec9:
    opVec[3] = opVec[0];
    opVec[1] = opVec[0];
    opVec[2] = opVec[0];
  }
  operandScratch = opVec;
  if (opcode == 0x36) {
    opVec[0] = 1.0 - opVec[0];
    opVec[1] = 1.0 - opVec[1];
    opVec[3] = 1.0 - opVec[3];
    opVec[2] = 1.0 - opVec[2];
  }
  destValueType = inst[9];
  destUpdatesCC = (uint)*(byte *)((int)inst + 6);
  destWriteMask = inst[10];
  destConditionSwizzleZW = inst[0xb];
  destOffsetTable = inst[3];
  destBankIndex = inst[4];
  destSwizzle = inst[5];
  destIndexInfo = inst[6];
  destStorageFlags = inst[7];
  destWord5 = inst[8];
  destElement = 0;
callInterpreterWriteDestination:
  ((int (*)())_InterpreterWriteDestination)(machine,destOffsetTable,destBankIndex,destSwizzle,destIndexInfo,destStorageFlags,destWord5,destValueType,destWriteMask,destConditionSwizzleZW,destElement,operandScratch,
             destUpdatesCC);
  return nextInst;
}

/* _InterpreterWriteFinalFragmentToBuffer @ 0x97bd3068 (376 bytes) */
int _InterpreterWriteFinalFragmentToBuffer(machine, operandWord1, operandWord2, operandWord3, operandWord4, operandWord5, viewportScaleBias)
  int *machine;
  undefined4 operandWord1;
  undefined4 operandWord2;
  undefined4 operandWord3;
  undefined4 operandWord4;
  undefined4 operandWord5;
  undefined4 viewportScaleBias;
{
  int programInfo;
  int emulator;
  int *fragmentColor;
  undefined1 destinationColor [16];
  int resultR;
  int resultG;
  int resultB;
  int resultA;
  
  fragmentColor = machine + 0x292;
  emulator = *machine;
  programInfo = *(int *)(emulator + 0xd80);
  if ((*(uint *)(programInfo + 0x3c) & 1) != 0) {
    programInfo = _InterpreterRasterOpMachine_AlphaTest(machine + 0x289,fragmentColor);
    if (programInfo != 0) {
      return;
    }
    programInfo = *(int *)(emulator + 0xd80);
  }
  if ((*(uint *)(programInfo + 0x3c) & 6) != 0) {
    programInfo = _InterpreterRasterOpMachine_DepthAndStencilTest(machine + 0x289);
    if (programInfo != 0) {
      return;
    }
    programInfo = *(int *)(emulator + 0xd80);
  }
  if ((*(uint *)(programInfo + 0x3c) & 0x68) != 0) {
    ((int (*)())_InterpreterUnpackPixel)(machine,destinationColor,*(undefined4 *)(emulator + 0xd88));
    programInfo = *(int *)(emulator + 0xd80);
  }
  if ((*(uint *)(programInfo + 0x3c) & 8) != 0) {
    _InterpreterRasterOpMachine_Blending(machine + 0x289,fragmentColor,destinationColor,&resultR);
    machine[0x292] = resultR;
    machine[0x293] = resultG;
    machine[0x294] = resultB;
    machine[0x295] = resultA;
    programInfo = *(int *)(emulator + 0xd80);
  }
  if ((*(uint *)(programInfo + 0x3c) & 0x20) != 0) {
    _InterpreterRasterOpMachine_LogicOp(machine + 0x289,fragmentColor,destinationColor,&resultR);
    machine[0x292] = resultR;
    machine[0x293] = resultG;
    machine[0x294] = resultB;
    machine[0x295] = resultA;
    programInfo = *(int *)(emulator + 0xd80);
  }
  if ((*(uint *)(programInfo + 0x3c) & 0x40) == 0) {
    resultA = machine[0x295];
    resultR = machine[0x292];
    resultG = machine[0x293];
    resultB = machine[0x294];
  }
  else {
    _InterpreterRasterOpMachine_BufferMask(machine + 0x289,fragmentColor,destinationColor,&resultR);
  }
  ((int (*)())_InterpreterPackPixel)(machine,&resultR,*(undefined4 *)(emulator + 0xd88));
  return;
}

/* _InterpreterRun @ 0x97bd31e0 (1020 bytes) */
void _InterpreterRun(int emulator,int elementCount,double scratchF1,double scratchF2,double scratchF3,double scratchF4,double scratchF5,double scratchF6,double scratchF7,double scratchF8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  int fragmentListHead;
  int currentProgramTarget;
  int programTarget;
  bool wSafeToDivide;
  float vertexW;
  float clipX;
  float clipY;
  float clipZ;
  float viewportZBias;
  float viewportZScale;
  float viewportXScale;
  float viewportXBias;
  float viewportYBias;
  float viewportYScale;
  float negW;
  double one;
  float zero;
  int viewportState;
  float *vertexOutput;
  uint testFlags;
  int inst;
  int extraOut1;
  int extraOut2;
  int extraOut3;
  undefined4 leftoverR5;
  undefined4 leftoverR6;
  undefined4 leftoverR7;
  undefined4 leftoverR8;
  int itemsLeft;
  int programInfo;
  uint clipCodeUnion;
  uint clipAndMask;
  int machine;
  double vertexWDouble;
  double extraOutF1;
  double extraOutF2;
  double xScale;
  double xBias;
  double invWScale;
  double invWBias;
  double leftoverStackArg0;
  double leftoverStackArg1;
  double leftoverStackArg2;
  double leftoverStackArg3;
  double leftoverStackArg4;
  
  one = DOUBLE_97c30a60;
  programTarget = *(int *)(*(int *)(emulator + 0xd80) + 0x38);
  machine = *(int *)(emulator + 0xdf0);
  viewportState = *(int *)(emulator + 0xd9c);
  clipAndMask = 0xff;
  clipCodeUnion = 0;
  if ((programTarget == 0x8804) || (programTarget == 0x8b30)) {
    invWBias = (double)*(float *)(*(int *)(emulator + 0xda0) + 0xc);
    xBias = (double)*(float *)(*(int *)(emulator + 0xda0) + 8);
    invWScale = (double)*(float *)(*(int *)(emulator + 0xda4) + 0xc);
    xScale = (double)*(float *)(*(int *)(emulator + 0xda4) + 8);
    viewportZBias = TAllocation__guardBlockSize;
    viewportZScale = TAllocation__guardBlockSize;
    viewportXScale = TAllocation__guardBlockSize;
    viewportXBias = TAllocation__guardBlockSize;
    viewportYBias = TAllocation__guardBlockSize;
    viewportYScale = TAllocation__guardBlockSize;
  }
  else {
    invWScale = (double)TAllocation__guardBlockSize;
    xScale = invWScale;
    xBias = invWScale;
    invWBias = invWScale;
    viewportZBias = *(float *)(viewportState + 0x1b88);
    viewportZScale = *(float *)(viewportState + 0x1b78);
    viewportXScale = *(float *)(viewportState + 0x1b70);
    viewportXBias = *(float *)(viewportState + 0x1b80);
    viewportYBias = *(float *)(viewportState + 0x1b84);
    viewportYScale = *(float *)(viewportState + 0x1b74);
  }
  currentProgramTarget = *(int *)(*(int *)(emulator + 0xd80) + 0x38);
  if ((currentProgramTarget == 0x8804) || (currentProgramTarget == 0x8b30)) {
    *(undefined4 *)(machine + 0xa30) = 0;
    *(float *)(machine + 0xa38) = (float)xBias;
    *(float *)(machine + 0xa3c) = (float)(one / invWBias);
  }
  fragmentListHead = machine + 0xa5c;
  *(undefined1 *)(machine + 0xa47) = 0;
  *(undefined4 *)(machine + 0xa68) = 0;
  *(int *)(machine + 0xa6c) = fragmentListHead;
  *(undefined1 *)(machine + 0xa44) = 0;
  *(undefined1 *)(machine + 0xa45) = 0;
  *(undefined1 *)(machine + 0xa46) = 0;
  *(undefined4 *)(machine + 0xa5c) = 0;
  *(undefined4 *)(machine + 0xa60) = 0;
  *(undefined4 *)(machine + 0xa64) = 0;
  zero = TAllocation__guardBlockSize;
  one = DOUBLE_97c30a60;
  itemsLeft = elementCount;
  do {
    if (itemsLeft == 0) {
      currentProgramTarget = *(int *)(*(int *)(emulator + 0xd80) + 0x38);
      if ((currentProgramTarget == 0x8804) || (currentProgramTarget == 0x8b30)) {
        clipCodeUnion = 0;
      }
      else {
        clipCodeUnion = clipAndMask << 8 | clipCodeUnion;
      }
      _restf20(clipCodeUnion);
      return;
    }
    itemsLeft = itemsLeft + -1;
    *(undefined4 *)(machine + 0xa58) = 0;
    programInfo = *(int *)(emulator + 0xd80);
    if (((*(uint *)(programInfo + 0x3c) & 6) == 4) && ((*(uint *)(programInfo + 0x34) & 0xa000) == 0)) {
      testFlags = _InterpreterRasterOpMachine_DepthTest(machine + 0xa24);
      *(uint *)(machine + 0xa58) = *(uint *)(machine + 0xa58) | testFlags;
      programInfo = *(int *)(emulator + 0xd80);
      elementCount = extraOut1;
      scratchF1 = extraOutF1;
    }
    inst = *(int *)(programInfo + 0x120);
    if ((inst != 0) && (*(int *)(machine + 0xa58) == 0)) {
      do {
        inst = ((int * (*)())_InterpreterEmulateOp)(machine,inst,scratchF1,scratchF2,scratchF3,scratchF4,scratchF5,scratchF6,
                            scratchF7,scratchF8,leftoverStackArg0,leftoverStackArg1,leftoverStackArg2,
                            leftoverStackArg3,leftoverStackArg4);
        scratchF1 = extraOutF2;
        if (inst == 0) break;
      } while (*(int *)(machine + 0xa58) == 0);
      programInfo = *(int *)(emulator + 0xd80);
      elementCount = extraOut2;
    }
    if ((*(int *)(programInfo + 0x38) == 0x8804) || (*(int *)(programInfo + 0x38) == 0x8b30)) {
      if (*(int *)(machine + 0xa58) == 0) {
        scratchF1 = (double)((int (*)())_InterpreterWriteFinalFragmentToBuffer)(machine,elementCount,leftoverR5,leftoverR6,leftoverR7,leftoverR8,fragmentListHead);
        programInfo = *(int *)(emulator + 0xd80);
        elementCount = extraOut3;
      }
    }
    else {
      vertexOutput = *(float **)(emulator + 0xd88);
      testFlags = 0;
      vertexW = vertexOutput[7];
      clipX = vertexOutput[4];
      negW = -vertexW;
      clipY = vertexOutput[5];
      clipZ = vertexOutput[6];
      if (clipX < negW) {
        testFlags = 0x10;
      }
      if (vertexW <= clipX) {
        testFlags = testFlags | 0x20;
      }
      if (clipY < negW) {
        testFlags = testFlags | 4;
      }
      if (vertexW <= clipY) {
        testFlags = testFlags | 8;
      }
      if (clipZ < negW) {
        testFlags = testFlags | 1;
      }
      if (vertexW < clipZ) {
        testFlags = testFlags | 2;
      }
      vertexOutput[0x1f] = GH_U2F((unsigned int)((testFlags | 0x1000000)));
      if (testFlags == 0) {
        if (vertexW < zero) {
          wSafeToDivide = vertexW <= FLOAT_97c3acf4;
        }
        else {
          wSafeToDivide = FLOAT_97c3acf0 <= vertexW;
        }
        if (wSafeToDivide) {
          negW = FLOAT_97c3acd8 / vertexW;
        }
        else {
          negW = FLOAT_97c3acfc;
          if (zero <= vertexW) {
            negW = FLOAT_97c3acf8;
          }
        }
        vertexOutput[3] = negW;
        *vertexOutput = clipX * negW * viewportXScale + viewportXBias;
        vertexOutput[1] = clipY * negW * viewportYScale + viewportYBias;
        vertexOutput[2] = clipZ * negW * viewportZScale + viewportZBias;
      }
      programInfo = *(int *)(emulator + 0xd80);
      clipAndMask = clipAndMask & testFlags;
      clipCodeUnion = clipCodeUnion | testFlags;
    }
    *(int *)(emulator + 0xd8c) = *(int *)(emulator + 0xd8c) + *(int *)(programInfo + 0xbc);
    *(int *)(emulator + 0xd88) = *(int *)(emulator + 0xd88) + *(int *)(programInfo + 0xb8);
    fragmentListHead = *(int *)(emulator + 0xda8) + *(int *)(programInfo + 0xd8);
    *(int *)(emulator + 0xda8) = fragmentListHead;
    *(int *)(emulator + 0xdac) = *(int *)(emulator + 0xdac) + *(int *)(programInfo + 0xdc);
    if ((*(int *)(programInfo + 0x38) == 0x8804) || (*(int *)(programInfo + 0x38) == 0x8b30)) {
      vertexW = (float)((double)*(float *)(machine + 0xa30) + one);
      vertexWDouble = (double)vertexW;
      *(float *)(machine + 0xa30) = vertexW;
      *(float *)(machine + 0xa38) = (float)(xScale * vertexWDouble + xBias);
      *(float *)(machine + 0xa3c) = (float)(one / (double)(float)(invWScale * vertexWDouble + invWBias));
    }
  } while( true );
}

/* _InterpreterTextureSamplerCreate @ 0x97bd35dc (12 bytes) */
int _InterpreterTextureSamplerCreate()
{
  undefined4 allocation;
  
  allocation = _calloc(0x2c,1);
  return allocation;
}

/* _InterpreterTextureSamplerInitialise @ 0x97bd35e8 (16 bytes) */
int _InterpreterTextureSamplerInitialise(sampler)
  int sampler;
{
  *(undefined4 *)(sampler + 0x18) = 0xffffffff;
  *(undefined4 *)(sampler + 0x14) = 0xffffffff;
  return;
}

/* _InterpreterTextureSamplerAttachGLDContext @ 0x97bd35fc (8 bytes) */
int _InterpreterTextureSamplerAttachGLDContext(sampler, gldContext)
  undefined4 *sampler;
  undefined4 gldContext;
{
  *sampler = gldContext;
  return;
}

/* _InterpreterTextureSamplerSetProjectionEnabled @ 0x97bd3604 (8 bytes) */
int _InterpreterTextureSamplerSetProjectionEnabled(sampler, enabled)
  int sampler;
  undefined4 enabled;
{
  *(undefined4 *)(sampler + 0x20) = enabled;
  return;
}

/* _InterpreterTextureSamplerSetLodBiasEnabled @ 0x97bd360c (8 bytes) */
int _InterpreterTextureSamplerSetLodBiasEnabled(sampler, enabled)
  int sampler;
  undefined4 enabled;
{
  *(undefined4 *)(sampler + 0x24) = enabled;
  return;
}

