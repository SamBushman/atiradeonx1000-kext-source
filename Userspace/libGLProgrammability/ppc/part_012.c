#include "decls.h"

/* fetch @ 0x97bc3a44 (100 bytes) */
int fetch(q)
  unsigned char * q;
{
  int newCount;
  undefined4 *headNode;
  undefined4 value;
  
  value = 0;
  headNode = *(undefined4 **)q;
  if (*(int *)(q + 8) != 0) {
    newCount = *(int *)(q + 8) + -1;
    *(int *)(q + 8) = newCount;
    *(undefined4 *)q = headNode[1];
    if (newCount == 0) {
      *(undefined4 *)(q + 4) = 0;
    }
    value = *headNode;
    _free(headNode);
  }
  return value;
}

/* __ZN19ParseWhileLoopStackC2Ev @ 0x97bc3aa8 (4 bytes) */
int __ZN19ParseWhileLoopStackC2Ev(this)
  void *this;
{
  *(undefined4 *)this = 0;
  return;
}

/* __ZN19ParseWhileLoopStackC1Ev @ 0x97bc3aac (4 bytes) */
int __ZN19ParseWhileLoopStackC1Ev(this)
  void *this;
{
  *(undefined4 *)this = 0;
  return;
}

/* __ZN19ParseWhileLoopStackC4Ev @ 0x97bc3ab0 (12 bytes) */
int __ZN19ParseWhileLoopStackC4Ev(this)
  void *this;
{
  *(undefined4 *)this = 0;
  return;
}

/* ParseWhileLoopStack__empty @ 0x97bc3abc (16 bytes) */
int ParseWhileLoopStack__empty(this)
  unsigned char * this;
{
  return *(int *)this == 0;
}

/* ParseWhileLoopStack__push @ 0x97bc3acc (76 bytes) */
int ParseWhileLoopStack__push(this, continueLabel, breakLabel)
  unsigned char * this;
  char *continueLabel;
  char *breakLabel;
{
  undefined4 previousTop;
  undefined4 *allocation;
  
  allocation = operator_new(0xc);
  previousTop = *(undefined4 *)this;
  *allocation = continueLabel;
  allocation[1] = breakLabel;
  allocation[2] = previousTop;
  *(undefined4 **)this = allocation;
  return;
}

/* ParseWhileLoopStack__pop @ 0x97bc3b18 (64 bytes) */
int ParseWhileLoopStack__pop(this)
  unsigned char * this;
{
  void *topNode;
  undefined4 nextNode;
  
  topNode = *(void **)this;
  if (topNode != (void *)0x0) {
    nextNode = *(undefined4 *)((int)topNode + 8);
    __ZdlPv(topNode);
    *(undefined4 *)this = nextNode;
  }
  return;
}

/* ParseWhileLoopStack__continueLabel @ 0x97bc3b58 (28 bytes) */
int ParseWhileLoopStack__continueLabel(this)
  unsigned char * this;
{
  undefined4 label;
  
  label = 0;
  if (*(undefined4 **)this != (undefined4 *)0x0) {
    label = **(undefined4 **)this;
  }
  return label;
}

/* ParseWhileLoopStack__breakLabel @ 0x97bc3b74 (28 bytes) */
int ParseWhileLoopStack__breakLabel(this)
  unsigned char * this;
{
  undefined4 label;
  
  label = 0;
  if (*(int *)this != 0) {
    label = *(undefined4 *)(*(int *)this + 4);
  }
  return label;
}

/* __ZN18ParseFunctionStackC2Ev @ 0x97bc3b90 (4 bytes) */
int __ZN18ParseFunctionStackC2Ev(this)
  void *this;
{
  *(undefined4 *)this = 0;
  return;
}

/* __ZN18ParseFunctionStackC1Ev @ 0x97bc3b94 (4 bytes) */
int __ZN18ParseFunctionStackC1Ev(this)
  void *this;
{
  *(undefined4 *)this = 0;
  return;
}

/* __ZN18ParseFunctionStackC4Ev @ 0x97bc3b98 (12 bytes) */
int __ZN18ParseFunctionStackC4Ev(this)
  void *this;
{
  *(undefined4 *)this = 0;
  return;
}

/* ParseFunctionStack__empty @ 0x97bc3ba4 (16 bytes) */
int ParseFunctionStack__empty(this)
  unsigned char * this;
{
  return *(int *)this == 0;
}

/* ParseFunctionStack__push @ 0x97bc3bb4 (88 bytes) */
int ParseFunctionStack__push(this, functionName)
  unsigned char * this;
  char *functionName;
{
  undefined4 *allocation;
  undefined4 previousTop;
  
  allocation = operator_new(0x14);
  previousTop = *(undefined4 *)this;
  *allocation = functionName;
  allocation[2] = 0xffffffff;
  allocation[4] = previousTop;
  allocation[3] = 0;
  allocation[1] = 0;
  *(undefined4 **)this = allocation;
  return;
}

/* ParseFunctionStack__pop @ 0x97bc3c0c (80 bytes) */
int ParseFunctionStack__pop(this)
  unsigned char * this;
{
  undefined4 *topNode;
  undefined4 nextNode;
  undefined4 functionName;
  
  functionName = 0;
  topNode = *(undefined4 **)this;
  if (topNode != (undefined4 *)0x0) {
    nextNode = topNode[4];
    functionName = *topNode;
    __ZdlPv(topNode);
    *(undefined4 *)this = nextNode;
  }
  return functionName;
}

/* ParseFunctionStack__current @ 0x97bc3c5c (28 bytes) */
int ParseFunctionStack__current(this)
  unsigned char * this;
{
  undefined4 functionName;
  
  functionName = 0;
  if (*(undefined4 **)this != (undefined4 *)0x0) {
    functionName = **(undefined4 **)this;
  }
  return functionName;
}

/* ParseFunctionStack__getCurrentNumParams @ 0x97bc3c78 (28 bytes) */
int ParseFunctionStack__getCurrentNumParams(this)
  unsigned char * this;
{
  undefined4 numParams;
  
  numParams = 0;
  if (*(int *)this != 0) {
    numParams = *(undefined4 *)(*(int *)this + 4);
  }
  return numParams;
}

/* ParseFunctionStack__setCurrentNumParams @ 0x97bc3c94 (20 bytes) */
int ParseFunctionStack__setCurrentNumParams(this, numParams)
  unsigned char * this;
  int numParams;
{
  if (*(int *)this == 0) {
    return;
  }
  *(int *)(*(int *)this + 4) = numParams;
  return;
}

/* ParseFunctionStack__getLastParamOpIndex @ 0x97bc3ca8 (28 bytes) */
int ParseFunctionStack__getLastParamOpIndex(this)
  unsigned char * this;
{
  undefined4 lastParamOpIndex;
  
  lastParamOpIndex = 0;
  if (*(int *)this != 0) {
    lastParamOpIndex = *(undefined4 *)(*(int *)this + 8);
  }
  return lastParamOpIndex;
}

/* ParseFunctionStack__setLastParamOpIndex @ 0x97bc3cc4 (20 bytes) */
int ParseFunctionStack__setLastParamOpIndex(this, lastParamOpIndex)
  unsigned char * this;
  int lastParamOpIndex;
{
  if (*(int *)this == 0) {
    return;
  }
  *(int *)(*(int *)this + 8) = lastParamOpIndex;
  return;
}

/* ParseFunctionStack__getCurrentParamList @ 0x97bc3cd8 (28 bytes) */
int ParseFunctionStack__getCurrentParamList(this)
  unsigned char * this;
{
  undefined4 paramList;
  
  paramList = 0;
  if (*(int *)this != 0) {
    paramList = *(undefined4 *)(*(int *)this + 0xc);
  }
  return paramList;
}

/* ParseFunctionStack__setCurrentParamList @ 0x97bc3cf4 (20 bytes) */
int ParseFunctionStack__setCurrentParamList(this, paramList)
  unsigned char * this;
  unsigned char ** paramList;
{
  if (*(int *)this == 0) {
    return;
  }
  *(unsigned char ***)(*(int *)this + 0xc) = paramList;
  return;
}

/* TPPStreamCompiler__getVertex @ 0x97bc3d08 (244 bytes) */
int TPPStreamCompiler__getVertex(this)
  unsigned char * this;
{
  unsigned char * poolAllocator;
  unsigned char * vertexType;
  unsigned char * operand;
  unsigned char * symbol;
  
  poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
  vertexType = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x28);
  *(undefined ***)vertexType = &PTR___ZN5TTypeD1Ev_a7b7d808;
  *(undefined4 *)(vertexType + 0x20) = 0;
  *(uint *)(vertexType + 0x24) = *(uint *)(vertexType + 0x24) & 0x801ff | 0x6082000;
  *(undefined4 *)(vertexType + 4) = 0;
  *(undefined4 *)(vertexType + 8) = 0;
  *(undefined4 *)(vertexType + 0xc) = 0;
  *(undefined4 *)(vertexType + 0x10) = 0;
  *(undefined4 *)(vertexType + 0x14) = 0;
  *(undefined4 *)(vertexType + 0x18) = 0;
  *(undefined4 *)(vertexType + 0x1c) = 0;
  operand = operator_new(0x38);
  __ZN12ParseOperandC1Ev(operand);
  symbol = operator_new(100);
  __ZN11ParseSymbolC1Ev(symbol);
  *(undefined4 *)(symbol + 0x28) = 0xffffffff;
  ParseSymbol__SetName(symbol,DAT_a7b7bd4c);
  ParseSymbol__SetParseTreeType(symbol,vertexType);
  *(unsigned char **)operand = symbol;
  ParseSymbolTable__processOperand(*(unsigned char **)(this + 0x68),operand);
  return operand;
}

/* TPPStreamCompiler__getPosition @ 0x97bc3dfc (240 bytes) */
int TPPStreamCompiler__getPosition(this)
  unsigned char * this;
{
  unsigned char * poolAllocator;
  unsigned char * positionType;
  unsigned char * operand;
  unsigned char * symbol;
  
  poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
  positionType = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x28);
  *(undefined ***)positionType = &PTR___ZN5TTypeD1Ev_a7b7d808;
  *(undefined4 *)(positionType + 0x20) = 0;
  *(undefined4 *)(positionType + 4) = 0;
  *(undefined4 *)(positionType + 8) = 0;
  *(undefined4 *)(positionType + 0xc) = 0;
  *(undefined4 *)(positionType + 0x10) = 0;
  *(undefined4 *)(positionType + 0x14) = 0;
  *(undefined4 *)(positionType + 0x18) = 0;
  *(undefined4 *)(positionType + 0x1c) = 0;
  *(uint *)(positionType + 0x24) = *(uint *)(positionType + 0x24) & 0x801ff | 0x1a082000;
  operand = operator_new(0x38);
  __ZN12ParseOperandC1Ev(operand);
  symbol = operator_new(100);
  __ZN11ParseSymbolC1Ev(symbol);
  *(undefined4 *)(symbol + 0x28) = 0xffffffff;
  ParseSymbol__SetName(symbol,_compileUtilString);
  ParseSymbol__SetParseTreeType(symbol,positionType);
  *(unsigned char **)operand = symbol;
  ParseSymbolTable__processOperand(*(unsigned char **)(this + 0x68),operand);
  return operand;
}

/* TPPStreamCompiler__getMVP @ 0x97bc3eec (248 bytes) */
int TPPStreamCompiler__getMVP(this)
  unsigned char * this;
{
  unsigned char * poolAllocator;
  unsigned char * mvpType;
  unsigned char * operand;
  unsigned char * symbol;
  
  poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
  mvpType = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x28);
  *(undefined ***)mvpType = &PTR___ZN5TTypeD1Ev_a7b7d808;
  *(undefined4 *)(mvpType + 0x20) = 0;
  *(uint *)(mvpType + 0x24) = *(uint *)(mvpType + 0x24) & 0x1ff | 0xc082400;
  *(undefined4 *)(mvpType + 4) = 0;
  *(undefined4 *)(mvpType + 8) = 0;
  *(undefined4 *)(mvpType + 0xc) = 0;
  *(undefined4 *)(mvpType + 0x10) = 0;
  *(undefined4 *)(mvpType + 0x14) = 0;
  *(undefined4 *)(mvpType + 0x18) = 0;
  *(undefined4 *)(mvpType + 0x1c) = 0;
  operand = operator_new(0x38);
  __ZN12ParseOperandC1Ev(operand);
  symbol = operator_new(100);
  __ZN11ParseSymbolC1Ev(symbol);
  *(undefined4 *)(symbol + 0x28) = 0xffffffff;
  ParseSymbol__SetName(symbol,DAT_a7b7bd48);
  ParseSymbol__SetParseTreeType(symbol,mvpType);
  *(unsigned char **)operand = symbol;
  ParseSymbolTable__processOperand(*(unsigned char **)(this + 0x68),operand);
  return operand;
}

/* TPPStreamCompiler__newNodeFromOperand @ 0x97bc3fe4 (460 bytes) */
int TPPStreamCompiler__newNodeFromOperand(this, parseOperand)
  unsigned char * this;
  unsigned char * parseOperand;
{
  int indexedDimCount;
  uint srcNominalSizeBits;
  uint srcQualifierBits;
  uint srcBasicTypeBits;
  uint srcIsMatrixBit;
  uint dstTypeBits;
  undefined4 basicType;
  undefined4 nominalSize;
  int isMatrix;
  undefined4 isArray;
  unsigned char * poolAllocator;
  int *newType;
  int srcField20;
  int srcField1c;
  int srcStructureSize;
  int srcField14;
  int srcStructure;
  int srcTypeName;
  int srcFieldName;
  int arraySize;
  int *srcType;
  
  if (*(int *)parseOperand == 0) {
    return (int *)0x0;
  }
  srcType = *(int **)(*(int *)parseOperand + 0xc);
  basicType = (**(code **)(*srcType + 0x20))(srcType);
  nominalSize = (**(code **)(*srcType + 0x2c))(srcType);
  isMatrix = (**(code **)(*srcType + 0x34))(srcType);
  isArray = (**(code **)(*srcType + 0x38))(srcType);
  arraySize = srcType[1];
  poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
  newType = (int *)TPoolAllocator__allocate(poolAllocator,0x28);
  srcStructure = srcType[2];
  srcFieldName = srcType[3];
  srcTypeName = srcType[4];
  srcField14 = srcType[5];
  srcStructureSize = srcType[6];
  srcField1c = srcType[7];
  srcField20 = srcType[8];
  newType[1] = srcType[1];
  *newType = (int)&PTR___ZN5TTypeD1Ev_a7b7d808;
  newType[2] = srcStructure;
  newType[3] = srcFieldName;
  newType[4] = srcTypeName;
  newType[5] = srcField14;
  newType[6] = srcStructureSize;
  newType[7] = srcField1c;
  newType[8] = srcField20;
  dstTypeBits = newType[9];
  srcQualifierBits = srcType[9] & 0xfe000000;
  newType[9] = srcQualifierBits | dstTypeBits & 0x1ffffff;
  srcBasicTypeBits = ((uint)srcType[9] >> 0x13 & 0x3f) << 0x13;
  newType[9] = srcBasicTypeBits | srcQualifierBits | dstTypeBits & 0x7ffff;
  srcNominalSizeBits = srcType[9] & 0x7f800;
  newType[9] = srcNominalSizeBits | srcBasicTypeBits | srcQualifierBits | dstTypeBits & 0x7ff;
  srcIsMatrixBit = ((uint)srcType[9] >> 10 & 1) << 10;
  newType[9] = srcIsMatrixBit | srcNominalSizeBits | srcBasicTypeBits | srcQualifierBits | dstTypeBits & 0x3ff;
  newType[9] = ((uint)srcType[9] >> 9 & 1) << 9 | srcIsMatrixBit | srcNominalSizeBits | srcBasicTypeBits | srcQualifierBits | dstTypeBits & 0x1ff;
  if (*(int *)(*(int *)parseOperand + 0x48) != 0) {
    isArray = 0;
    arraySize = 0;
  }
  if (isMatrix == 0) {
    indexedDimCount = *(int *)(parseOperand + 0x20);
loopCheckIndexedDimCount:
    if (indexedDimCount == 0) goto LAB_97bc4174;
  }
  else {
    indexedDimCount = 0;
    if (*(uint *)(parseOperand + 0x20) == 0) goto loopCheckIndexedDimCount;
    isMatrix = 0;
    if (*(uint *)(parseOperand + 0x20) < 2) goto LAB_97bc4174;
  }
  nominalSize = 1;
LAB_97bc4174:
  (**(code **)(*newType + 8))(newType,basicType,nominalSize,isMatrix,isArray,arraySize);
  return newType;
}

/* TPPStreamCompiler__newTemporary @ 0x97bc41b0 (400 bytes) */
int TPPStreamCompiler__newTemporary(this, type)
  unsigned char * this;
  unsigned char * type;
{
  undefined4 temporaryIndex;
  undefined4 glTypeString;
  uint srcNominalSizeBits;
  uint srcQualifierBits;
  uint srcBasicTypeBits;
  uint srcIsMatrixBit;
  undefined4 srcArraySize;
  uint dstTypeBits;
  unsigned char * poolAllocator;
  unsigned char * newType;
  unsigned char * operand;
  unsigned char * symbol;
  undefined4 srcField20;
  undefined4 srcField1c;
  undefined4 srcStructureSize;
  undefined4 srcField14;
  undefined4 srcStructure;
  undefined4 srcTypeName;
  char symbolNameBuffer [264];
  
  poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
  newType = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x28);
  srcTypeName = *(undefined4 *)(type + 0x10);
  srcField14 = *(undefined4 *)(type + 0x14);
  srcStructureSize = *(undefined4 *)(type + 0x18);
  srcField1c = *(undefined4 *)(type + 0x1c);
  srcField20 = *(undefined4 *)(type + 0x20);
  srcStructure = *(undefined4 *)(type + 8);
  srcArraySize = *(undefined4 *)(type + 4);
  *(undefined4 *)(newType + 0xc) = *(undefined4 *)(type + 0xc);
  *(undefined4 *)(newType + 0x10) = srcTypeName;
  *(undefined4 *)(newType + 0x14) = srcField14;
  *(undefined4 *)(newType + 0x18) = srcStructureSize;
  *(undefined4 *)(newType + 0x1c) = srcField1c;
  *(undefined4 *)(newType + 0x20) = srcField20;
  *(undefined4 *)(newType + 8) = srcStructure;
  *(undefined4 *)(newType + 4) = srcArraySize;
  *(undefined ***)newType = &PTR___ZN5TTypeD1Ev_a7b7d808;
  dstTypeBits = *(uint *)(newType + 0x24);
  srcQualifierBits = *(uint *)(type + 0x24) & 0xfe000000;
  *(uint *)(newType + 0x24) = srcQualifierBits | dstTypeBits & 0x1ffffff;
  srcBasicTypeBits = (*(uint *)(type + 0x24) >> 0x13 & 0x3f) << 0x13;
  *(uint *)(newType + 0x24) = srcBasicTypeBits | srcQualifierBits | dstTypeBits & 0x7ffff;
  srcNominalSizeBits = *(uint *)(type + 0x24) & 0x7f800;
  *(uint *)(newType + 0x24) = srcNominalSizeBits | srcBasicTypeBits | srcQualifierBits | dstTypeBits & 0x7ff;
  srcIsMatrixBit = (*(uint *)(type + 0x24) >> 10 & 1) << 10;
  *(uint *)(newType + 0x24) = srcIsMatrixBit | srcNominalSizeBits | srcBasicTypeBits | srcQualifierBits | dstTypeBits & 0x3ff;
  *(uint *)(newType + 0x24) =
       (*(uint *)(type + 0x24) >> 9 & 1) << 9 | srcIsMatrixBit | srcNominalSizeBits | srcBasicTypeBits | srcQualifierBits | dstTypeBits & 0x1ff;
  operand = operator_new(0x38);
  __ZN12ParseOperandC1Ev(operand);
  symbol = operator_new(100);
  __ZN11ParseSymbolC1Ev(symbol);
  *(undefined4 *)(symbol + 0x34) = 0;
  *(undefined4 *)(symbol + 0x3c) = 1;
  (**(code **)(*(int *)newType + 0x28))(newType,0,srcField20,srcField1c,srcStructureSize,srcField14,*(int *)newType);
  ParseSymbol__SetParseTreeType(symbol,newType);
  temporaryIndex = TemporaryAllocator__getTemporary
                    (*(unsigned char **)(this + 0x60),(uint)*(ushort *)(symbol + 0x2c));
  glTypeString = GetGLStringForType((uint)*(ushort *)(symbol + 0x2c));
  _sprintf(symbolNameBuffer,DAT_a7b7bd50,temporaryIndex,glTypeString);
  *(undefined4 *)(symbol + 0x28) = temporaryIndex;
  ParseSymbol__SetName(symbol,symbolNameBuffer);
  *(unsigned char **)operand = symbol;
  ParseSymbolTable__processOperand(*(unsigned char **)(this + 0x68),operand);
  return operand;
}

/* TPPStreamCompiler__newAddressTemp @ 0x97bc4340 (272 bytes) */
int TPPStreamCompiler__newAddressTemp(this)
  unsigned char * this;
{
  unsigned char * poolAllocator;
  unsigned char * addressType;
  unsigned char * operand;
  unsigned char * symbol;
  undefined4 addressTempIndex;
  char symbolNameBuffer [256];
  
  poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
  addressType = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x28);
  *(undefined4 *)(addressType + 4) = 0;
  *(uint *)(addressType + 0x24) = *(uint *)(addressType + 0x24) & 0x1ff | 0x100800;
  *(undefined ***)addressType = &PTR___ZN5TTypeD1Ev_a7b7d808;
  *(undefined4 *)(addressType + 8) = 0;
  *(undefined4 *)(addressType + 0xc) = 0;
  *(undefined4 *)(addressType + 0x10) = 0;
  *(undefined4 *)(addressType + 0x14) = 0;
  *(undefined4 *)(addressType + 0x18) = 0;
  *(undefined4 *)(addressType + 0x1c) = 0;
  *(undefined4 *)(addressType + 0x20) = 0;
  operand = operator_new(0x38);
  __ZN12ParseOperandC1Ev(operand);
  symbol = operator_new(100);
  __ZN11ParseSymbolC1Ev(symbol);
  *(undefined4 *)(symbol + 0x34) = 0;
  *(undefined4 *)(symbol + 0x58) = 1;
  ParseSymbol__SetParseTreeType(symbol,addressType);
  addressTempIndex = AddressTempAllocator__getTemporary(*(unsigned char **)(this + 100));
  _sprintf(symbolNameBuffer,DAT_a7b7bd54,addressTempIndex);
  *(undefined4 *)(symbol + 0x28) = addressTempIndex;
  ParseSymbol__SetName(symbol,symbolNameBuffer);
  *(unsigned char **)operand = symbol;
  ParseSymbolTable__processOperand(*(unsigned char **)(this + 0x68),operand);
  return operand;
}

/* TPPStreamCompiler__newReturnValue @ 0x97bc4450 (352 bytes) */
int TPPStreamCompiler__newReturnValue(compiler, type, str)
  unsigned char * compiler;
  char *type;
  char *str;
{
  uint srcNominalSizeBits;
  uint srcQualifierBits;
  uint srcBasicTypeBits;
  uint srcIsMatrixBit;
  undefined4 srcArraySize;
  uint dstTypeBits;
  unsigned char * poolAllocator;
  unsigned char * newType;
  unsigned char * operand;
  unsigned char * symbol;
  undefined4 srcField20;
  undefined4 srcField1c;
  undefined4 srcStructureSize;
  undefined4 srcField14;
  undefined4 srcTypeName;
  undefined4 srcFieldName;
  
  poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
  newType = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x28);
  srcFieldName = *(undefined4 *)(type + 0xc);
  srcTypeName = *(undefined4 *)(type + 0x10);
  srcField14 = *(undefined4 *)(type + 0x14);
  srcStructureSize = *(undefined4 *)(type + 0x18);
  srcField1c = *(undefined4 *)(type + 0x1c);
  srcField20 = *(undefined4 *)(type + 0x20);
  srcArraySize = *(undefined4 *)(type + 4);
  *(undefined4 *)(newType + 8) = *(undefined4 *)(type + 8);
  *(undefined4 *)(newType + 0xc) = srcFieldName;
  *(undefined4 *)(newType + 0x10) = srcTypeName;
  *(undefined4 *)(newType + 0x14) = srcField14;
  *(undefined4 *)(newType + 0x18) = srcStructureSize;
  *(undefined4 *)(newType + 0x1c) = srcField1c;
  *(undefined4 *)(newType + 0x20) = srcField20;
  *(undefined4 *)(newType + 4) = srcArraySize;
  *(undefined ***)newType = &PTR___ZN5TTypeD1Ev_a7b7d808;
  dstTypeBits = *(uint *)(newType + 0x24);
  srcQualifierBits = *(uint *)(type + 0x24) & 0xfe000000;
  *(uint *)(newType + 0x24) = srcQualifierBits | dstTypeBits & 0x1ffffff;
  srcBasicTypeBits = (*(uint *)(type + 0x24) >> 0x13 & 0x3f) << 0x13;
  *(uint *)(newType + 0x24) = srcBasicTypeBits | srcQualifierBits | dstTypeBits & 0x7ffff;
  srcNominalSizeBits = *(uint *)(type + 0x24) & 0x7f800;
  *(uint *)(newType + 0x24) = srcNominalSizeBits | srcBasicTypeBits | srcQualifierBits | dstTypeBits & 0x7ff;
  srcIsMatrixBit = (*(uint *)(type + 0x24) >> 10 & 1) << 10;
  *(uint *)(newType + 0x24) = srcIsMatrixBit | srcNominalSizeBits | srcBasicTypeBits | srcQualifierBits | dstTypeBits & 0x3ff;
  *(uint *)(newType + 0x24) =
       (*(uint *)(type + 0x24) >> 9 & 1) << 9 | srcIsMatrixBit | srcNominalSizeBits | srcBasicTypeBits | srcQualifierBits | dstTypeBits & 0x1ff;
  operand = operator_new(0x38);
  __ZN12ParseOperandC1Ev(operand);
  symbol = operator_new(100);
  __ZN11ParseSymbolC1Ev(symbol);
  *(undefined4 *)(symbol + 0x38) = 1;
  *(undefined4 *)(symbol + 0x3c) = 0;
  *(undefined4 *)(symbol + 0x34) = 0;
  ParseSymbol__SetName(symbol,str);
  (**(code **)(*(int *)newType + 0x28))(newType,0);
  ParseSymbol__SetParseTreeType(symbol,newType);
  *(unsigned char **)operand = symbol;
  ParseSymbolTable__processOperand(*(unsigned char **)(compiler + 0x68),operand);
  return operand;
}

/* TPPStreamCompiler__newParam @ 0x97bc45b0 (408 bytes) */
int TPPStreamCompiler__newParam(this, type, str, paramIndex)
  unsigned char * this;
  unsigned char * type;
  char *str;
  int paramIndex;
{
  uint srcNominalSizeBits;
  uint srcQualifierBits;
  uint srcBasicTypeBits;
  uint srcIsMatrixBit;
  undefined4 srcArraySize;
  uint dstTypeBits;
  unsigned char * poolAllocator;
  unsigned char * newType;
  unsigned char * operand;
  unsigned char * symbol;
  int nameLength;
  char *paramName;
  undefined4 srcField20;
  undefined4 srcField1c;
  undefined4 srcStructureSize;
  undefined4 srcField14;
  undefined4 srcTypeName;
  undefined4 srcFieldName;
  
  poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
  newType = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x28);
  srcFieldName = *(undefined4 *)(type + 0xc);
  srcTypeName = *(undefined4 *)(type + 0x10);
  srcField14 = *(undefined4 *)(type + 0x14);
  srcStructureSize = *(undefined4 *)(type + 0x18);
  srcField1c = *(undefined4 *)(type + 0x1c);
  srcField20 = *(undefined4 *)(type + 0x20);
  srcArraySize = *(undefined4 *)(type + 4);
  *(undefined4 *)(newType + 8) = *(undefined4 *)(type + 8);
  *(undefined4 *)(newType + 0xc) = srcFieldName;
  *(undefined4 *)(newType + 0x10) = srcTypeName;
  *(undefined4 *)(newType + 0x14) = srcField14;
  *(undefined4 *)(newType + 0x18) = srcStructureSize;
  *(undefined4 *)(newType + 0x1c) = srcField1c;
  *(undefined4 *)(newType + 0x20) = srcField20;
  *(undefined4 *)(newType + 4) = srcArraySize;
  *(undefined ***)newType = &PTR___ZN5TTypeD1Ev_a7b7d808;
  dstTypeBits = *(uint *)(newType + 0x24);
  srcQualifierBits = *(uint *)(type + 0x24) & 0xfe000000;
  *(uint *)(newType + 0x24) = srcQualifierBits | dstTypeBits & 0x1ffffff;
  srcBasicTypeBits = (*(uint *)(type + 0x24) >> 0x13 & 0x3f) << 0x13;
  *(uint *)(newType + 0x24) = srcBasicTypeBits | srcQualifierBits | dstTypeBits & 0x7ffff;
  srcNominalSizeBits = *(uint *)(type + 0x24) & 0x7f800;
  *(uint *)(newType + 0x24) = srcNominalSizeBits | srcBasicTypeBits | srcQualifierBits | dstTypeBits & 0x7ff;
  srcIsMatrixBit = (*(uint *)(type + 0x24) >> 10 & 1) << 10;
  *(uint *)(newType + 0x24) = srcIsMatrixBit | srcNominalSizeBits | srcBasicTypeBits | srcQualifierBits | dstTypeBits & 0x3ff;
  *(uint *)(newType + 0x24) =
       (*(uint *)(type + 0x24) >> 9 & 1) << 9 | srcIsMatrixBit | srcNominalSizeBits | srcBasicTypeBits | srcQualifierBits | dstTypeBits & 0x1ff;
  operand = operator_new(0x38);
  __ZN12ParseOperandC1Ev(operand);
  symbol = operator_new(100);
  __ZN11ParseSymbolC1Ev(symbol);
  nameLength = _strlen(str);
  paramName = (char *)_malloc(nameLength + 10);
  _sprintf(paramName,DAT_a7b7bd58,str,paramIndex);
  *(undefined4 *)(symbol + 0x38) = 1;
  *(undefined4 *)(symbol + 0x3c) = 0;
  *(undefined4 *)(symbol + 0x34) = 0;
  ParseSymbol__SetName(symbol,paramName);
  (**(code **)(*(int *)newType + 0x28))(newType,0);
  ParseSymbol__SetParseTreeType(symbol,newType);
  *(unsigned char **)operand = symbol;
  ParseSymbolTable__processOperand(*(unsigned char **)(this + 0x68),operand);
  _free(paramName);
  return operand;
}

/* TPPStreamCompiler__newIndirectOperandFromConstant @ 0x97bc4748 (2092 bytes) */
int TPPStreamCompiler__newIndirectOperandFromConstant(this, parseOperand, type)
  unsigned char * this;
  unsigned char * parseOperand;
  unsigned char * type;
{
  int operandValueCountRecheck;
  int innerChunkCursor;
  int outerCandidateChunk;
  int valueIndex;
  int lastParamBinding;
  int typeQualifier;
  uint constantIndex;
  uint operandGlTypeWord;
  uint lanesLeft;
  uint chunkClassBits;
  undefined4 constantWord;
  ushort operandGlType;
  bool fullMatchFound;
  bool keepSearching;
  byte crSizeVs2Byte;
  double usedLaneCountD;
  unsigned char * constantAllocList;
  undefined4 *laneCursor;
  unsigned char * newSymbol;
  uint typeNominalSize;
  int operandValueCount;
  int innerCandidateChunk;
  uint typeGlType;
  uint ppStreamType;
  unsigned char * newChunk;
  undefined4 leftoverR4;
  undefined4 leftoverR4b;
  undefined4 leftoverR6;
  int slotMatched;
  int leftoverR8;
  undefined4 *valueCursor;
  int constantList;
  int slotIndex;
  int chunkCursor;
  byte xerSummaryOverflow = 0;
  unsigned char * typeSaved;
  undefined4 chunkWord0;
  uint chunkWord1;
  char symbolNameText [256];
  ushort usageGlTypes [8];
  int constantValues [8];
  bool laneUsedFlags [16];
  uint paramBindingArrayRecord [4];
  int *constantChunkList;
  int matchedChunk;
  unsigned char * resultOperand;
  int constantSlotCount;
  int crSizeVs1;
  int crSizeVs3;
  int crSizeVs4;
  int crSizeVs2;
  unsigned char * savedConstantAllocList;
  int crSizeVs2Saved;
  
  slotIndex = 0;
  fullMatchFound = false;
  constantChunkList = *(int **)(*(int *)(this + 0x70) + 0x10);
  chunkCursor = *constantChunkList;
  constantList = *(int *)(*(int *)(this + 0x70) + 0x2c);
  typeSaved = type;
  resultOperand = operator_new(0x38);
  __ZN12ParseOperandC1Ev(resultOperand);
  newSymbol = operator_new(100);
  __ZN11ParseSymbolC1Ev(newSymbol);
  matchedChunk = 0;
  typeNominalSize = (**(code **)(*(int *)typeSaved + 0x2c))
                    (typeSaved,leftoverR4,type,leftoverR6,slotMatched,leftoverR8,typeSaved);
  operandValueCount = ParseOperand__GetBaseSize(parseOperand);
  constantSlotCount = (operandValueCount - 1U) / typeNominalSize + 1;
  if (chunkCursor == 0) {
    keepSearching = true;
loopCheckKeepSearching:
    if (keepSearching) {
      valueIndex = 0;
      slotIndex = 0;
      if (constantSlotCount < 1) {
        return resultOperand;
      }
      do {
        constantValues[0] = 0;
        constantValues[1] = 0;
        constantValues[2] = 0;
        constantValues[3] = 0;
        laneUsedFlags[0] = false;
        laneUsedFlags[1] = false;
        laneUsedFlags[2] = false;
        laneUsedFlags[3] = false;
        laneUsedFlags[4] = false;
        laneUsedFlags[5] = false;
        laneUsedFlags[6] = false;
        laneUsedFlags[7] = false;
        laneUsedFlags[8] = false;
        laneUsedFlags[9] = false;
        laneUsedFlags[10] = false;
        laneUsedFlags[0xb] = false;
        laneUsedFlags[0xc] = false;
        laneUsedFlags[0xd] = false;
        laneUsedFlags[0xe] = false;
        laneUsedFlags[0xf] = false;
        chunkWord1 = *(uint *)(*(int *)(this + 0x68) + 0x24);
        *(uint *)(*(int *)(this + 0x68) + 0x24) = chunkWord1 + 1;
        chunkWord0 = 0x110000;
        chunkWord1 = chunkWord1 & 0xffff;
        typeGlType = getOpenGLTypeFromTType(typeSaved);
        ppStreamType = GetPPStreamTypeForGLType(typeGlType & 0xffff);
        chunkClassBits = chunkWord0 >> 0x10;
        chunkWord0 = CONCAT22((ushort)((typeNominalSize - 1) * 0x1000000 >> 0x10) & 0x300 |
                             (ushort)(((ppStreamType & 7) << 0x1a) >> 0x10) | (ushort)chunkClassBits & 0xff,
                             *(undefined2 *)(constantList + 10));
        if (0 < (int)typeNominalSize) {
          valueCursor = (undefined4 *)(valueIndex * 4 + *(int *)(parseOperand + 4));
          laneCursor = &chunkWord0;
          lanesLeft = typeNominalSize;
          do {
            laneCursor[0x50] = 1;
            valueIndex = valueIndex + 1;
            constantWord = *valueCursor;
            valueCursor = valueCursor + 1;
            laneCursor[0x48] = constantWord;
            laneCursor = laneCursor + 1;
            lanesLeft = lanesLeft - 1;
          } while (lanesLeft != 0);
        }
        if (*(int *)parseOperand == 0) {
          operandGlType = *(ushort *)(parseOperand + 0x18);
        }
        else {
          operandGlType = *(ushort *)(*(int *)parseOperand + 0x2c);
        }
        operandGlTypeWord = (uint)operandGlType;
        ConstantAllocationList__addConstant
                  ((unsigned char *)(this + 0x44),chunkWord1 & 0xffff,laneUsedFlags,operandGlType);
        _PPStreamAddConstant(*(undefined4 *)(this + 0x70),constantValues);
        newChunk = (unsigned char *)_calloc(0x1c,1);
        *newChunk = 0x3;
        *(uint *)(newChunk + 0xc) = chunkWord0;
        *(uint *)(newChunk + 0x10) = chunkWord1;
        *(undefined4 *)(newChunk + 0x14) = 0;
        _PPStreamChunkListAddChunk(constantChunkList,newChunk);
        if (slotIndex == 0) {
          ParseSymbol__SetParseTreeType(newSymbol,typeSaved);
          constantIndex = chunkWord0 & 0xffff;
          _sprintf(symbolNameText,DAT_a7b7bd5c,constantIndex);
          *(uint *)(newSymbol + 0x28) = chunkWord0 & 0xffff;
          ParseSymbol__SetName(newSymbol,symbolNameText);
          typeQualifier = (**(code **)(*(int *)typeSaved + 0x24))
                             (typeSaved,leftoverR4b,constantIndex,operandGlTypeWord,slotMatched,leftoverR8,typeSaved);
          *(uint *)(newSymbol + 0x38) = (uint)(typeQualifier != 0);
          ParseSymbol__SetChunk(newSymbol,newChunk);
          *(undefined4 *)(newSymbol + 0x44) = 0;
          *(unsigned char **)resultOperand = newSymbol;
          *(undefined4 *)(newSymbol + 0x50) = 1;
          ParseSymbolTable__AddSymbol(*(unsigned char **)(this + 0x68),newSymbol);
          paramBindingArrayRecord[1] = 0;
          paramBindingArrayRecord[0] = chunkWord0 & 0xffff;
          _PPStreamAddParamBindingArray(*(undefined4 *)(this + 0x70),paramBindingArrayRecord);
        }
        else if ((slotIndex == constantSlotCount + -1) &&
                (lastParamBinding = *(int *)(*(int *)(*(int *)(this + 0x70) + 0x14) + 4),
                *(short *)(lastParamBinding + 0x12) == 0)) {
          *(undefined2 *)(lastParamBinding + 0x12) = (*(unsigned short *)((unsigned char *)&(chunkWord0) + 2));
        }
        slotIndex = slotIndex + 1;
      } while (slotIndex < constantSlotCount);
      return resultOperand;
    }
  }
  else {
    savedConstantAllocList = this + 0x44;
    crSizeVs2 = (uint)(byte)(((int)typeNominalSize < 2) << 3 | (2 < (int)typeNominalSize) << 2 | (typeNominalSize == 2) << 1 |
                           xerSummaryOverflow & 1) << 0x1c;
    crSizeVs1 = (uint)(byte)(((int)typeNominalSize < 1) << 3 | (1 < (int)typeNominalSize) << 2 | (typeNominalSize == 1) << 1 |
                           xerSummaryOverflow & 1) << 0x1c;
    crSizeVs3 = (uint)(byte)(((int)typeNominalSize < 3) << 3 | (3 < (int)typeNominalSize) << 2 | (typeNominalSize == 3) << 1 |
                           xerSummaryOverflow & 1) << 0x1c;
    crSizeVs4 = (uint)(byte)(((int)typeNominalSize < 4) << 3 | (4 < (int)typeNominalSize) << 2 | (typeNominalSize == 4) << 1 |
                           xerSummaryOverflow & 1) << 0x1c;
    crSizeVs2Saved = crSizeVs2;
    do {
      constantValues[0] = 1;
      constantValues[1] = 1;
      constantValues[2] = 1;
      constantValues[3] = 1;
      chunkWord0 = *(uint *)(chunkCursor + 0xc);
      chunkWord1 = *(uint *)(chunkCursor + 0x10);
      if ((chunkWord0 & 0x1f0000) == 0x110000) {
        outerCandidateChunk = _PPStreamChunkListChunkAtIndex(constantList,chunkWord0 & 0xffff);
        ConstantAllocationList__getConstantUsage
                  ((unsigned char *)(this + 0x44),chunkWord1 & 0xffff,(bool *)constantValues,
                   usageGlTypes);
        constantValues[5] = constantValues[0] + constantValues[1] + constantValues[2] + constantValues[3] ^ 0x80000000;
        constantValues[4] = 0x43300000;
        usedLaneCountD = (double)CONCAT44(0x43300000,constantValues[5]);
        if (*(int *)parseOperand == 0) {
          operandGlType = *(ushort *)(parseOperand + 0x18);
        }
        else {
          operandGlType = *(ushort *)(*(int *)parseOperand + 0x2c);
        }
        leftoverR8 = constantValues[0];
        if (usageGlTypes[0] == operandGlType) {
          constantValues[5] = typeNominalSize ^ 0x80000000;
          constantValues[4] = 0x43300000;
          if ((float)(usedLaneCountD - 4503601774854144.0) ==
              (float)((double)CONCAT44(0x43300000,constantValues[5]) - 4503601774854144.0)) {
            slotMatched = 1;
            crSizeVs2Byte = (byte)((uint)crSizeVs2 >> 0x18);
            if ((bool)(crSizeVs2Byte >> 5 & 1)) {
loopCheckConstantValues:
              if ((constantValues[1] != 0) &&
                 (*(float *)(slotIndex * 4 + *(int *)(parseOperand + 4) + 4) == *(float *)(outerCandidateChunk + 0x10))) {
loopCheckConstantValues2:
                if ((constantValues[0] != 0) &&
                   (*(float *)(*(int *)(parseOperand + 4) + slotIndex * 4) == *(float *)(outerCandidateChunk + 0xc)))
                goto setSlotIndex;
              }
loopSetSlotMatched:
              slotMatched = 0;
            }
            else {
              if ((bool)(crSizeVs2Byte >> 6 & 1)) {
                if ((bool)((byte)((uint)crSizeVs3 >> 0x1d) & 1)) {
loopCheckConstantValues3:
                  if ((constantValues[2] != 0) &&
                     (*(float *)(slotIndex * 4 + *(int *)(parseOperand + 4) + 8) == *(float *)(outerCandidateChunk + 0x14)
                     )) goto loopCheckConstantValues;
                }
                else {
                  if (!(bool)((byte)((uint)crSizeVs4 >> 0x1d) & 1)) goto setSlotIndex;
                  if ((constantValues[3] != 0) &&
                     (*(float *)(slotIndex * 4 + *(int *)(parseOperand + 4) + 0xc) ==
                      *(float *)(outerCandidateChunk + 0x18))) goto loopCheckConstantValues3;
                }
                goto loopSetSlotMatched;
              }
              if ((bool)((byte)((uint)crSizeVs1 >> 0x1d) & 1)) goto loopCheckConstantValues2;
            }
setSlotIndex:
            slotIndex = slotIndex + typeNominalSize;
            if ((slotMatched != 0) && (matchedChunk = chunkCursor, constantSlotCount == 1)) {
              fullMatchFound = true;
            }
          }
        }
      }
      constantAllocList = savedConstantAllocList;
      chunkCursor = *(int *)(chunkCursor + 8);
      if (matchedChunk == 0) {
        keepSearching = !fullMatchFound;
      }
      else {
        keepSearching = !fullMatchFound;
        if (keepSearching) {
          if (chunkCursor != 0) {
            crSizeVs2Byte = (byte)((uint)crSizeVs2Saved >> 0x18);
            innerChunkCursor = chunkCursor;
            do {
              chunkWord0 = *(uint *)(innerChunkCursor + 0xc);
              chunkWord1 = *(uint *)(innerChunkCursor + 0x10);
              if ((chunkWord0 & 0x1f0000) == 0x110000) {
                innerCandidateChunk = _PPStreamChunkListChunkAtIndex(constantList,chunkWord0 & 0xffff);
                ConstantAllocationList__getConstantUsage
                          ((unsigned char *)constantAllocList,chunkWord1 & 0xffff,(bool *)constantValues,
                           usageGlTypes);
                constantValues[4] = 0x43300000;
                constantValues[5] = constantValues[0] + constantValues[1] + constantValues[2] + constantValues[3] ^ 0x80000000;
                usedLaneCountD = (double)CONCAT44(0x43300000,constantValues[5]);
                if (*(int *)parseOperand == 0) {
                  operandGlType = *(ushort *)(parseOperand + 0x18);
                }
                else {
                  operandGlType = *(ushort *)(*(int *)parseOperand + 0x2c);
                }
                leftoverR8 = constantValues[0];
                if (usageGlTypes[0] == operandGlType) {
                  constantValues[5] = typeNominalSize ^ 0x80000000;
                  constantValues[4] = 0x43300000;
                  if ((float)(usedLaneCountD - 4503601774854144.0) ==
                      (float)((double)CONCAT44(0x43300000,constantValues[5]) - 4503601774854144.0)) {
                    slotMatched = 1;
                    if ((bool)(crSizeVs2Byte >> 5 & 1)) {
loopCheckConstantValues4:
                      if ((constantValues[1] != 0) &&
                         (*(float *)(slotIndex * 4 + *(int *)(parseOperand + 4) + 4) ==
                          *(float *)(innerCandidateChunk + 0x10))) {
loopCheckConstantValues5:
                        if ((constantValues[0] != 0) &&
                           (*(float *)(*(int *)(parseOperand + 4) + slotIndex * 4) ==
                            *(float *)(innerCandidateChunk + 0xc))) goto setSlotIndex2;
                      }
loopSetSlotMatched2:
                      slotMatched = 0;
                    }
                    else {
                      if ((bool)(crSizeVs2Byte >> 6 & 1)) {
                        if ((bool)((byte)((uint)crSizeVs3 >> 0x1d) & 1)) {
loopCheckConstantValues6:
                          if ((constantValues[2] != 0) &&
                             (*(float *)(slotIndex * 4 + *(int *)(parseOperand + 4) + 8) ==
                              *(float *)(innerCandidateChunk + 0x14))) goto loopCheckConstantValues4;
                        }
                        else {
                          if (!(bool)((byte)((uint)crSizeVs4 >> 0x1d) & 1)) goto setSlotIndex2;
                          if ((constantValues[3] != 0) &&
                             (*(float *)(slotIndex * 4 + *(int *)(parseOperand + 4) + 0xc) ==
                              *(float *)(innerCandidateChunk + 0x18))) goto loopCheckConstantValues6;
                        }
                        goto loopSetSlotMatched2;
                      }
                      if ((bool)((byte)((uint)crSizeVs1 >> 0x1d) & 1)) goto loopCheckConstantValues5;
                    }
setSlotIndex2:
                    slotIndex = slotIndex + typeNominalSize;
                    if (slotMatched == 0) {
                      slotIndex = 0;
                      matchedChunk = 0;
                      goto checkChunkCursor;
                    }
                  }
                }
              }
              operandValueCountRecheck = ParseOperand__GetBaseSize(parseOperand);
              if (operandValueCountRecheck <= slotIndex) {
                fullMatchFound = true;
                keepSearching = false;
              }
              innerChunkCursor = *(int *)(innerChunkCursor + 8);
              if ((innerChunkCursor == 0) || (!keepSearching)) goto checkChunkCursor;
            } while( true );
          }
          goto loopCheckKeepSearching;
        }
      }
checkChunkCursor:
      if (chunkCursor == 0) goto loopCheckKeepSearching;
    } while (keepSearching);
  }
  chunkWord1 = *(undefined4 *)(matchedChunk + 0x10);
  chunkWord0 = *(uint *)(matchedChunk + 0xc);
  ParseSymbol__SetParseTreeType(newSymbol,typeSaved);
  _sprintf(symbolNameText,DAT_a7b7bd5c,chunkWord0 & 0xffff);
  *(uint *)(newSymbol + 0x28) = chunkWord0 & 0xffff;
  ParseSymbol__SetName(newSymbol,symbolNameText);
  *(unsigned char **)resultOperand = newSymbol;
  ParseSymbolTable__processOperand(*(unsigned char **)(this + 0x68),resultOperand);
  return resultOperand;
}

/* TPPStreamCompiler__equalOperands @ 0x97bc4f74 (2416 bytes) */
int TPPStreamCompiler__equalOperands(this, type, parseOperand1, parseOperand2, isEqualTest)
  unsigned char * this;
  unsigned char * type;
  unsigned char ** parseOperand1;
  unsigned char ** parseOperand2;
  int isEqualTest;
{
  undefined4 structCombinedResultOperand;
  int arrayCombineLogicalSize;
  int sideCountdown;
  int resultLogicalSize;
  int compareOpcode;
  int nameBufferSize;
  int fieldNameString;
  int fieldsBegin;
  int structFieldList;
  int operandSlotOffset;
  uint structStreamType;
  uint elementIndex;
  int generateAddressLoadResult2;
  int generateAddressLoadResult;
  int logicalSize;
  int length;
  short symbolGlType;
  ushort glTypeCode;
  bool addressLoaded;
  int operandASymbol;
  int elementSourceSymbol;
  int *fieldType;
  int length2;
  char *p0;
  unsigned char * elementResultOperand;
  unsigned char * elementSymbol;
  undefined4 leftoverArgTmp;
  uint streamType;
  void *elementOperand;
  unsigned char * combinedResultOperand;
  uint combineStreamType;
  undefined4 leftoverR4;
  undefined4 leftoverR4_00;
  undefined4 leftoverR4_01;
  undefined4 leftoverR4_02;
  undefined4 leftoverR4_03;
  undefined4 leftoverR4_04;
  unsigned char ** operandAArg;
  unsigned char ** operandBArg;
  undefined4 leftoverR8;
  undefined4 leftoverArg7;
  unsigned char * leftoverR10;
  undefined4 leftoverArg8;
  int fieldIndex;
  int operandSide;
  int isEqualTestArg;
  unsigned char ** parentName;
  unsigned char ** fieldNameChars;
  undefined8 callResultPair;
  uint opHeader;
  uint opFlags;
  uint opDest0;
  undefined4 opDest1;
  uint opSrc0A;
  undefined4 opSrc0B;
  uint opSrc1A;
  undefined4 opSrc1B;
  undefined4 opSrc2A;
  undefined4 opSrc2B;
  undefined4 opAuxA;
  undefined4 opAuxB;
  undefined4 opLine;
  undefined4 opWord13;
  uint fieldDescA;
  undefined4 fieldDescB;
  uint elemDescA;
  undefined4 elemDescB;
  uint srcDescA;
  undefined4 srcDescB;
  unsigned char * resultOperand [2];
  unsigned char * operandSlots [9];
  
  resultOperand[0] = (unsigned char *)0x0;
  operandAArg = parseOperand1;
  operandBArg = parseOperand2;
  isEqualTestArg = isEqualTest;
  ((int (*)())__ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_S2_)(this,resultOperand,parseOperand1,parseOperand2);
  operandSlots[0] = *parseOperand1;
  addressLoaded = false;
  operandSlots[1] = *parseOperand2;
  if ((*(int *)operandSlots[0] != 0) &&
     ((symbolGlType = *(short *)(*(int *)operandSlots[0] + 0x2c), symbolGlType == 0x7ffe || (symbolGlType == 0x7fff)))) {
    generateAddressLoadResult = ((int (*)())TPPStreamCompiler__generateAddressLoad)(this,operandSlots[0]);
    if (generateAddressLoadResult != 0) {
      TPPStreamCompiler__equalOperands__source0Indirect = 1;
    }
    generateAddressLoadResult2 = ((int (*)())TPPStreamCompiler__generateAddressLoad)(this,operandSlots[1]);
    if (generateAddressLoadResult2 != 0) {
      TPPStreamCompiler__equalOperands__source1Indirect = 1;
    }
    addressLoaded = generateAddressLoadResult2 != 0 || generateAddressLoadResult != 0;
  }
  callResultPair = CONCAT44(resultOperand[0],operandSlots[0]);
  operandASymbol = *(int *)operandSlots[0];
  if ((operandASymbol == 0) || (*(short *)(operandASymbol + 0x2c) != 0x7ffe)) {
    operandASymbol = *(int *)operandSlots[0];
    if ((operandASymbol == 0) || (*(short *)(operandASymbol + 0x2c) != 0x7fff)) {
      leftoverArgTmp = 0;
      opFlags = 0;
      opLine = *(undefined4 *)(this + 0x90);
      opAuxA = 0;
      opAuxB = 0;
      opHeader = 0x40000000;
      opDest0 = 0;
      opDest1 = 0;
      opSrc0A = 0;
      opSrc0B = 0;
      opSrc1A = 0;
      opSrc1B = 0;
      opSrc2A = 0;
      opSrc2B = 0;
      opWord13 = 0;
      ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&srcDescA,this,operandSlots[0],operandBArg,isEqualTestArg,leftoverR8,0,0);
      opSrc0A = srcDescA;
      opSrc0B = srcDescB;
      if (TPPStreamCompiler__equalOperands__source0Indirect != 0) {
        opSrc0A = srcDescA & 0x8fffff00 | 0x80000000;
      }
      ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&srcDescA,this,operandSlots[1],operandBArg,isEqualTestArg,leftoverR8,srcDescA,leftoverArgTmp);
      opSrc1A = srcDescA;
      opSrc1B = srcDescB;
      if (TPPStreamCompiler__equalOperands__source1Indirect != 0) {
        opSrc1A = srcDescA & 0x8fffff00 | 0x80000000;
      }
      resultOperand[0] = (unsigned char *)((int (*)())TPPStreamCompiler__newTemporary)(this,type);
      ((int (*)())TPPStreamCompiler__getOperandAsDestVar)((unsigned char *)&srcDescA,this,resultOperand[0],operandBArg,isEqualTestArg,leftoverR8);
      opDest1 = srcDescB;
      compareOpcode = 0x31;
      opDest0 = srcDescA;
      if (isEqualTest == 0) {
        compareOpcode = 0x36;
      }
      opHeader = compareOpcode << 0x12 | opHeader & 0xfc03ffff;
      opFlags = (srcDescA >> 0xc & 1) << 0x1c | opFlags & 0xefffffff;
      if (*(int *)resultOperand[0] == 0) {
        glTypeCode = *(ushort *)(resultOperand[0] + 0x18);
      }
      else {
        glTypeCode = *(ushort *)(*(int *)resultOperand[0] + 0x2c);
      }
      streamType = GetPPStreamTypeForGLType((uint)glTypeCode);
      opFlags = (streamType & 7) << 0x17 | opFlags & 0xfc7fffff;
      resultLogicalSize = ParseOperand__GetLogicalSize(resultOperand[0]);
      opFlags = (resultLogicalSize + -1) * 0x4000000 & 0xc000000U | opFlags & 0xf3f3ffff;
      _PPStreamAddOperation(*(undefined4 *)(this + 0x70),&opHeader,0,0);
    }
    else {
      elementIndex = (int)*(short *)(operandASymbol + 0x2e) - 1;
      if (-1 < (int)elementIndex) {
        do {
          operandSlotOffset = 0;
          sideCountdown = 1;
          do {
            elementOperand = operator_new(0x38);
            __ZN12ParseOperandC1Ev(elementOperand);
            *(void **)((int)operandSlots + operandSlotOffset + 8) = elementOperand;
            elementSymbol = operator_new(100);
            __ZN11ParseSymbolC1Ev(elementSymbol);
            ParseSymbol__SetName(elementSymbol,*(char **)(**(int **)((int)operandSlots + operandSlotOffset) + 0x14));
            ParseSymbol__AddDirectIndex(elementSymbol,elementIndex);
            _sprintf((char *)&opHeader,DAT_a7b7bd90,elementIndex);
            ParseSymbol__CatName(elementSymbol,(char *)&opHeader);
            *(undefined4 *)(elementSymbol + 0x40) =
                 *(undefined4 *)(**(int **)((int)operandSlots + operandSlotOffset) + 0x40);
            *(undefined4 *)(elementSymbol + 0x3c) =
                 *(undefined4 *)(**(int **)((int)operandSlots + operandSlotOffset) + 0x3c);
            ParseSymbol__SetParseTreeType
                      (elementSymbol,*(unsigned char **)(**(int **)((int)operandSlots + operandSlotOffset) + 0xc));
            elementSourceSymbol = **(int **)((int)operandSlots + operandSlotOffset);
            *(undefined4 *)(elementSymbol + 0x48) = 1;
            *(undefined4 *)(elementSymbol + 0x28) = *(undefined4 *)(elementSourceSymbol + 0x28);
            ParseSymbol__ResolveOpenGLType(elementSymbol);
            **(undefined4 **)((int)operandSlots + operandSlotOffset + 8) = elementSymbol;
            if ((*(short *)(elementSymbol + 0x2c) != 0x7ffe) && (*(short *)(elementSymbol + 0x2c) != 0x7fff)) {
              ParseSymbolTable__processOperand
                        (*(unsigned char **)(this + 0x68),
                         *(unsigned char **)((int)operandSlots + operandSlotOffset + 8));
            }
            elementResultOperand = resultOperand[0];
            sideCountdown = sideCountdown + -1;
            operandSlotOffset = operandSlotOffset + 4;
          } while (-1 < sideCountdown);
          operandAArg = operandSlots + 3;
          isEqualTestArg = isEqualTest;
          resultOperand[0] = (unsigned char *)((int (*)())TPPStreamCompiler__equalOperands)(this,type,operandSlots + 2,operandAArg,isEqualTest);
          combinedResultOperand = operandSlots[2];
          if (operandSlots[2] != (void *)0x0) {
            __ZN12ParseOperandD1Ev(operandSlots[2]);
            __ZdlPv(combinedResultOperand);
          }
          combinedResultOperand = operandSlots[3];
          if (operandSlots[3] != (void *)0x0) {
            __ZN12ParseOperandD1Ev(operandSlots[3]);
            __ZdlPv(combinedResultOperand);
          }
          combinedResultOperand = resultOperand[0];
          if ((elementResultOperand != (unsigned char *)0x0) && (resultOperand[0] != (unsigned char *)0x0)) {
            combinedResultOperand = (unsigned char *)((int (*)())TPPStreamCompiler__newTemporary)(this,type);
            opFlags = 0;
            opLine = *(undefined4 *)(this + 0x90);
            opHeader = 0x40000000;
            opDest0 = 0;
            opDest1 = 0;
            opSrc0A = 0;
            opSrc0B = 0;
            opSrc1A = 0;
            opSrc1B = 0;
            opSrc2A = 0;
            opSrc2B = 0;
            opAuxA = 0;
            opAuxB = 0;
            opWord13 = 0;
            ((int (*)())TPPStreamCompiler__getOperandAsDestVar)((unsigned char *)&elemDescA,this,combinedResultOperand,operandAArg,isEqualTestArg,leftoverR8);
            opDest0 = elemDescA;
            opDest1 = elemDescB;
            ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&elemDescA,this,elementResultOperand,operandAArg,isEqualTestArg,leftoverR8,elementSourceSymbol,leftoverR10);
            opSrc0A = elemDescA;
            opSrc0B = elemDescB;
            ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&elemDescA,this,resultOperand[0],operandAArg,isEqualTestArg,leftoverR8,elementSourceSymbol,leftoverR10
                      );
            opHeader = ((isEqualTest == 0) + 0x24) * 0x40000 | opHeader & 0xfc03ffff;
            opFlags = (opDest0 >> 0xc & 1) << 0x1c | opFlags & 0xefffffff;
            opSrc1A = elemDescA;
            opSrc1B = elemDescB;
            if (*(int *)resultOperand[0] == 0) {
              glTypeCode = *(ushort *)(resultOperand[0] + 0x18);
            }
            else {
              glTypeCode = *(ushort *)(*(int *)resultOperand[0] + 0x2c);
            }
            leftoverR10 = resultOperand[0];
            combineStreamType = GetPPStreamTypeForGLType((uint)glTypeCode);
            opFlags = (combineStreamType & 7) << 0x17 | opFlags & 0xfc7fffff;
            arrayCombineLogicalSize = ParseOperand__GetLogicalSize(resultOperand[0]);
            opFlags = (arrayCombineLogicalSize + -1) * 0x4000000 & 0xc000000U | opFlags & 0xf3f3ffff;
            _PPStreamAddOperation(*(undefined4 *)(this + 0x70),&opHeader,0,0);
            __ZN12ParseOperandD1Ev(elementResultOperand);
            __ZdlPv(elementResultOperand);
            elementResultOperand = resultOperand[0];
            if (resultOperand[0] != (unsigned char *)0x0) {
              __ZN12ParseOperandD1Ev(resultOperand[0]);
              __ZdlPv(elementResultOperand);
            }
          }
          resultOperand[0] = combinedResultOperand;
          elementIndex = elementIndex - 1;
        } while (-1 < (int)elementIndex);
      }
    }
  }
  else {
    structFieldList = *(int *)(*(int *)(operandASymbol + 0xc) + 8);
    if (structFieldList != 0) {
      fieldsBegin = *(int *)(structFieldList + 4);
      fieldIndex = (*(int *)(structFieldList + 8) - fieldsBegin >> 3) + -1;
      if (-1 < fieldIndex) {
        while( true ) {
          operandSide = 0;
          while( true ) {
            resultOperand[0] = (unsigned char *)((ulonglong)callResultPair >> 0x20);
            fieldType = *(int **)(fieldsBegin + fieldIndex * 8);
            parentName = *(unsigned char ***)(*(int *)operandSlots[operandSide] + 0x14);
            fieldNameString = (**(code **)(*fieldType + 0x1c))
                              (fieldType,(int)callResultPair,operandAArg,operandBArg,isEqualTestArg,leftoverR8,operandSlots[operandSide]);
            *(undefined1 *)(*(int *)(fieldNameString + 4) + *(int *)(*(int *)(fieldNameString + 4) + -0xc)) =
                 *DAT_a7b7bd9c;
            fieldNameChars = *(unsigned char ***)(fieldNameString + 4);
            length = _strlen(fieldNameChars);
            nameBufferSize = length + 1;
            if (parentName != (unsigned char **)0x0) {
              length2 = _strlen(parentName);
              nameBufferSize = nameBufferSize + length2 + 1;
            }
            p0 = (char *)_malloc(nameBufferSize);
            if (parentName == (unsigned char **)0x0) {
              _strcpy(p0,fieldNameChars);
            }
            else {
              _sprintf(p0,DAT_a7b7bd8c,(int)parentName,(int)fieldNameChars);
              operandAArg = parentName;
              operandBArg = fieldNameChars;
            }
            elementResultOperand = operator_new(0x38);
            __ZN12ParseOperandC1Ev(elementResultOperand);
            operandSlots[operandSide + 2] = elementResultOperand;
            elementSymbol = operator_new(100);
            __ZN11ParseSymbolC1Ev(elementSymbol);
            ParseSymbol__SetName(elementSymbol,p0);
            _free(p0);
            *(undefined4 *)(elementSymbol + 0x40) = *(undefined4 *)(*(int *)operandSlots[operandSide] + 0x40);
            *(undefined4 *)(elementSymbol + 0x3c) = *(undefined4 *)(*(int *)operandSlots[operandSide] + 0x3c);
            ParseSymbol__SetParseTreeType(elementSymbol,*(unsigned char **)(*(int *)(structFieldList + 4) + fieldIndex * 8));
            *(undefined4 *)(elementSymbol + 0x28) = *(undefined4 *)(*(int *)operandSlots[operandSide] + 0x28);
            *(unsigned char **)operandSlots[operandSide + 2] = elementSymbol;
            leftoverArgTmp = leftoverR4;
            if ((*(short *)(elementSymbol + 0x2c) != 0x7ffe) && (*(short *)(elementSymbol + 0x2c) != 0x7fff)) {
              ParseSymbolTable__processOperand
                        (*(unsigned char **)(this + 0x68),operandSlots[operandSide + 2]);
              leftoverArgTmp = leftoverR4_00;
            }
            elementResultOperand = resultOperand[0];
            callResultPair = CONCAT44(resultOperand[0],leftoverArgTmp);
            operandSide = operandSide + 1;
            if (1 < operandSide) break;
            fieldsBegin = *(int *)(structFieldList + 4);
          }
          operandAArg = operandSlots + 2;
          operandBArg = operandSlots + 3;
          isEqualTestArg = isEqualTest;
          callResultPair = ((int (*)())TPPStreamCompiler__equalOperands)(this,type,operandAArg,operandBArg,isEqualTest);
          combinedResultOperand = operandSlots[2];
          resultOperand[0] = (unsigned char *)((ulonglong)callResultPair >> 0x20);
          if (operandSlots[2] != (void *)0x0) {
            __ZN12ParseOperandD1Ev(operandSlots[2]);
            __ZdlPv(combinedResultOperand);
            callResultPair = CONCAT44(resultOperand[0],leftoverR4_01);
          }
          combinedResultOperand = operandSlots[3];
          resultOperand[0] = (unsigned char *)((ulonglong)callResultPair >> 0x20);
          if (operandSlots[3] != (void *)0x0) {
            __ZN12ParseOperandD1Ev(operandSlots[3]);
            __ZdlPv(combinedResultOperand);
            callResultPair = CONCAT44(resultOperand[0],leftoverR4_02);
          }
          resultOperand[0] = (unsigned char *)((ulonglong)callResultPair >> 0x20);
          if ((elementResultOperand != (unsigned char *)0x0) && (resultOperand[0] != (unsigned char *)0x0)) {
            structCombinedResultOperand = ((int (*)())TPPStreamCompiler__newTemporary)(this,type);
            leftoverArg7 = 0;
            leftoverArg8 = 0;
            opFlags = 0;
            opLine = *(undefined4 *)(this + 0x90);
            opAuxA = 0;
            opAuxB = 0;
            opDest0 = 0;
            opDest1 = 0;
            opSrc0A = 0;
            opSrc0B = 0;
            opSrc1A = 0;
            opSrc1B = 0;
            opSrc2A = 0;
            opSrc2B = 0;
            opWord13 = 0;
            opHeader = 0x40000000;
            ((int (*)())TPPStreamCompiler__getOperandAsDestVar)((unsigned char *)&fieldDescA,this,structCombinedResultOperand,operandBArg,isEqualTestArg,leftoverR8);
            opDest0 = fieldDescA;
            opDest1 = fieldDescB;
            ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&fieldDescA,this,elementResultOperand,operandBArg,isEqualTestArg,leftoverR8,leftoverArg7,leftoverArg8);
            opSrc0A = fieldDescA;
            opSrc0B = fieldDescB;
            ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&fieldDescA,this,resultOperand[0],operandBArg,isEqualTestArg,leftoverR8,leftoverArg7,leftoverArg8);
            opHeader = ((isEqualTest == 0) + 0x24) * 0x40000 | opHeader & 0xfc03ffff;
            opFlags = (opDest0 >> 0xc & 1) << 0x1c | opFlags & 0xefffffff;
            opSrc1A = fieldDescA;
            opSrc1B = fieldDescB;
            if (*(int *)resultOperand[0] == 0) {
              glTypeCode = *(ushort *)(resultOperand[0] + 0x18);
            }
            else {
              glTypeCode = *(ushort *)(*(int *)resultOperand[0] + 0x2c);
            }
            structStreamType = GetPPStreamTypeForGLType((uint)glTypeCode);
            opFlags = (structStreamType & 7) << 0x17 | opFlags & 0xfc7fffff;
            logicalSize = ParseOperand__GetLogicalSize(resultOperand[0]);
            opFlags = (logicalSize + -1) * 0x4000000 & 0xc000000U | opFlags & 0xf3f3ffff;
            operandAArg = (unsigned char **)0x0;
            operandBArg = (unsigned char **)0x0;
            _PPStreamAddOperation(*(undefined4 *)(this + 0x70),&opHeader,0,0);
            __ZN12ParseOperandD1Ev(elementResultOperand);
            __ZdlPv(elementResultOperand);
            elementResultOperand = resultOperand[0];
            callResultPair = CONCAT44(structCombinedResultOperand,leftoverR4_03);
            if (resultOperand[0] != (unsigned char *)0x0) {
              __ZN12ParseOperandD1Ev(resultOperand[0]);
              __ZdlPv(elementResultOperand);
              callResultPair = CONCAT44(structCombinedResultOperand,leftoverR4_04);
            }
          }
          resultOperand[0] = (unsigned char *)((ulonglong)callResultPair >> 0x20);
          fieldIndex = fieldIndex + -1;
          if (fieldIndex < 0) break;
          fieldsBegin = *(int *)(structFieldList + 4);
        }
      }
    }
  }
  if (addressLoaded) {
    TPPStreamCompiler__equalOperands__source1Indirect = 0;
    TPPStreamCompiler__equalOperands__source0Indirect = 0;
  }
  return resultOperand[0];
}

/* TPPStreamCompiler__duplicateDestinationSource @ 0x97bc58e4 (636 bytes) */
int TPPStreamCompiler__duplicateDestinationSource(compiler, destDescA, destDescB, srcDescA, srcDescB)
  undefined4 compiler;
  uint destDescA;
  uint destDescB;
  uint srcDescA;
  uint srcDescB;
{
  bool swizzleMatches;
  uint componentSelector;
  uint expectedSourceBits;
  undefined4 destEqualsSource;
  
  destEqualsSource = 1;
  if ((destDescA >> 0x11 & 7) != (srcDescA >> 0x17 & 7)) {
    return 0;
  }
  if ((destDescB & 0xffff) != (srcDescB & 0xffff)) {
    return 0;
  }
  if ((destDescA >> 0xc & 1) != (srcDescA >> 0xe & 1)) {
    return 0;
  }
  if ((srcDescA & 0x8000000) != 0) {
    return 0;
  }
  if ((destDescB & 0xf0000000) != (srcDescA & 0xf0000000)) {
    return 0;
  }
  if ((int)(destDescB << 4 | destDescB >> 0x1c) >> 0x18 != (int)(char)srcDescA) {
    return 0;
  }
  if ((destDescA & 0x7ff00000) != 0) {
    return 0;
  }
  componentSelector = destDescA >> 10 & 3;
  if (componentSelector != 1) {
    if (componentSelector == 0) goto checkDestDescA3;
    if (componentSelector != 2) {
      if (componentSelector != 3) {
        return destEqualsSource;
      }
      if ((destDescA & 0x10000) != 0) {
        componentSelector = destDescA >> 2 & 3;
        if (componentSelector == 1) {
          componentSelector = srcDescA & 0x180000;
          expectedSourceBits = 0x180000;
loopSetSwizzleMatches:
          swizzleMatches = componentSelector == expectedSourceBits;
loopCheckSwizzleMatches:
          if (swizzleMatches) goto checkDestDescA;
        }
        else {
          if (componentSelector == 0) {
            componentSelector = srcDescA & 0x600000;
            expectedSourceBits = 0x600000;
            goto loopSetSwizzleMatches;
          }
          if (componentSelector == 2) {
            componentSelector = srcDescA & 0x60000;
            expectedSourceBits = 0x60000;
            goto loopSetSwizzleMatches;
          }
          if (componentSelector == 3) {
            swizzleMatches = (srcDescA & 0x18000) == 0x18000;
            goto loopCheckSwizzleMatches;
          }
        }
        destEqualsSource = 0;
      }
    }
checkDestDescA:
    if ((destDescA & 0x8000) != 0) {
      componentSelector = destDescA >> 4 & 3;
      if (componentSelector == 1) {
        expectedSourceBits = 0x100000;
        componentSelector = srcDescA & 0x180000;
loopCheckComponentSelector:
        if (componentSelector == expectedSourceBits) goto checkDestDescA2;
      }
      else {
        if (componentSelector == 0) {
          expectedSourceBits = 0x400000;
          componentSelector = srcDescA & 0x600000;
          goto loopCheckComponentSelector;
        }
        if (componentSelector == 2) {
          expectedSourceBits = 0x40000;
          componentSelector = srcDescA & 0x60000;
          goto loopCheckComponentSelector;
        }
        if (componentSelector == 3) {
          expectedSourceBits = 0x10000;
          componentSelector = srcDescA & 0x18000;
          goto loopCheckComponentSelector;
        }
      }
      destEqualsSource = 0;
    }
  }
checkDestDescA2:
  if ((destDescA & 0x4000) == 0) goto checkDestDescA3;
  componentSelector = destDescA >> 6 & 3;
  if (componentSelector == 1) {
    expectedSourceBits = 0x80000;
    componentSelector = srcDescA & 0x180000;
loopSetSwizzleMatches2:
    swizzleMatches = componentSelector == expectedSourceBits;
loopCheckSwizzleMatches2:
    if (swizzleMatches) goto checkDestDescA3;
  }
  else {
    if (componentSelector == 0) {
      expectedSourceBits = 0x200000;
      componentSelector = srcDescA & 0x600000;
      goto loopSetSwizzleMatches2;
    }
    if (componentSelector == 2) {
      expectedSourceBits = 0x20000;
      componentSelector = srcDescA & 0x60000;
      goto loopSetSwizzleMatches2;
    }
    if (componentSelector == 3) {
      swizzleMatches = (srcDescA & 0x18000) == 0x8000;
      goto loopCheckSwizzleMatches2;
    }
  }
  destEqualsSource = 0;
checkDestDescA3:
  if ((destDescA & 0x2000) == 0) {
    return destEqualsSource;
  }
  componentSelector = destDescA >> 8 & 3;
  if (componentSelector == 1) {
    if ((srcDescA & 0x180000) == 0) {
      return destEqualsSource;
    }
  }
  else if (componentSelector == 0) {
    if ((srcDescA & 0x600000) == 0) {
      return destEqualsSource;
    }
  }
  else if (componentSelector == 2) {
    if ((srcDescA & 0x60000) == 0) {
      return destEqualsSource;
    }
  }
  else if ((componentSelector == 3) && ((srcDescA & 0x18000) == 0)) {
    return destEqualsSource;
  }
  return 0;
}

/* TPPStreamCompiler__assignOperands @ 0x97bc5b60 (1892 bytes) */
int TPPStreamCompiler__assignOperands(this, parseOperand1, parseOperand2, allowCopyPropagation)
  unsigned char * this;
  unsigned char ** parseOperand1;
  unsigned char ** parseOperand2;
  int allowCopyPropagation;
{
  int destEqualsSourceResult;
  int operandByteOffset;
  int structFieldList;
  int elemSourceSymbol;
  int destSymbol;
  uint elemCountdown;
  int fieldCountdown;
  int generateAddressLoadResult2;
  int generateAddressLoadResult;
  uint streamType;
  ushort destGlType;
  bool addressLoadsEmitted;
  int *fieldType;
  int length;
  char *fullName;
  unsigned char *pendingOperand;
  unsigned char *indexOperandToFree;
  unsigned char *elemOperandToFree2;
  unsigned char *elemOperandToFree1;
  unsigned char *operandSlot0Arg;
  unsigned char *childOperand;
  unsigned char * childSymbol;
  void *elemOperand;
  unsigned char * leftoverR4;
  unsigned char * leftoverR4_00;
  unsigned char * leftoverR4_01;
  unsigned char * leftoverR4_02;
  unsigned char * leftoverR4_03;
  unsigned char ** operandPtrArg;
  undefined4 leftoverR7;
  undefined4 leftoverR8;
  undefined4 leftoverR9;
  int nameBufferSize;
  int fieldNameString;
  int fieldsBegin;
  undefined4 leftoverR10;
  int operandSide;
  int sideCountdown;
  int destLogicalSize;
  int destSymbolForType;
  int allowCopyPropagationArg;
  unsigned char ** parentName;
  int fieldNameChars;
  unsigned char * operandToFree;
  uint scratchDescA;
  uint scratchDescB;
  uint opHeader;
  uint opFlags;
  uint opDest0;
  uint opDest1;
  uint opSrc0A;
  uint opSrc0B;
  uint opSrc1A;
  uint opSrc1B;
  undefined4 opSrc2A;
  undefined4 opSrc2B;
  undefined4 opAuxA;
  undefined4 opAuxB;
  undefined4 opLine;
  undefined4 opWord13;
  uint savedDestA;
  uint savedDestB;
  unsigned char * operandSlots [4];
  unsigned char * operandSlotsHigh [4];
  
  operandPtrArg = parseOperand2;
  allowCopyPropagationArg = allowCopyPropagation;
  ((int (*)())__ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_)(this,parseOperand1,parseOperand2);
  operandSlots[0] = *parseOperand1;
  addressLoadsEmitted = false;
  operandSlots[1] = *parseOperand2;
  if ((*(short *)(*(int *)operandSlots[0] + 0x2c) == 0x7ffe) ||
     (*(short *)(*(int *)operandSlots[0] + 0x2c) == 0x7fff)) {
    generateAddressLoadResult = ((int (*)())TPPStreamCompiler__generateAddressLoad)(this,operandSlots[0]);
    if (generateAddressLoadResult != 0) {
      TPPStreamCompiler__assignOperands__destIndirect = 1;
    }
    generateAddressLoadResult2 = ((int (*)())TPPStreamCompiler__generateAddressLoad)(this,operandSlots[1]);
    if (generateAddressLoadResult2 != 0) {
      TPPStreamCompiler__assignOperands__sourceIndirect = 1;
    }
    addressLoadsEmitted = generateAddressLoadResult2 != 0 || generateAddressLoadResult != 0;
  }
  destSymbol = *(int *)operandSlots[0];
  if (*(short *)(destSymbol + 0x2c) == 0x7ffe) {
    structFieldList = *(int *)(*(int *)(destSymbol + 0xc) + 8);
    if (structFieldList != 0) {
      fieldsBegin = *(int *)(structFieldList + 4);
      fieldCountdown = *(int *)(structFieldList + 8) - fieldsBegin >> 3;
      operandSlot0Arg = operandSlots[0];
      if (fieldCountdown != 0) {
        while( true ) {
          fieldCountdown = fieldCountdown + -1;
          operandSide = 0;
          while( true ) {
            fieldType = *(int **)(fieldsBegin + fieldCountdown * 8);
            parentName = *(unsigned char ***)(*(int *)operandSlots[operandSide] + 0x14);
            fieldNameString = (**(code **)(*fieldType + 0x1c))
                               (fieldType,operandSlot0Arg,operandPtrArg,allowCopyPropagationArg,leftoverR7,leftoverR8,operandSlots[operandSide]);
            *(undefined1 *)(*(int *)(fieldNameString + 4) + *(int *)(*(int *)(fieldNameString + 4) + -0xc)) =
                 *DAT_a7b7bd9c;
            fieldNameChars = *(int *)(fieldNameString + 4);
            nameBufferSize = _strlen(fieldNameChars);
            nameBufferSize = nameBufferSize + 1;
            if (parentName != (unsigned char **)0x0) {
              length = _strlen(parentName);
              nameBufferSize = nameBufferSize + length + 1;
            }
            fullName = (char *)_malloc(nameBufferSize);
            if (parentName == (unsigned char **)0x0) {
              _strcpy(fullName,fieldNameChars);
            }
            else {
              _sprintf(fullName,DAT_a7b7bd8c,(int)parentName,fieldNameChars);
              operandPtrArg = parentName;
              allowCopyPropagationArg = fieldNameChars;
            }
            childOperand = operator_new(0x38);
            __ZN12ParseOperandC1Ev(childOperand);
            operandSlots[operandSide + 2] = childOperand;
            childSymbol = operator_new(100);
            __ZN11ParseSymbolC1Ev(childSymbol);
            ParseSymbol__SetName(childSymbol,fullName);
            _free(fullName);
            *(undefined4 *)(childSymbol + 0x3c) = 0;
            *(undefined4 *)(childSymbol + 0x40) = 0;
            ParseSymbol__SetParseTreeType(childSymbol,*(unsigned char **)(*(int *)(structFieldList + 4) + fieldCountdown * 8));
            *(undefined4 *)(childSymbol + 0x28) = *(undefined4 *)(*(int *)operandSlots[operandSide] + 0x28);
            *(unsigned char **)operandSlots[operandSide + 2] = childSymbol;
            operandSlot0Arg = leftoverR4;
            if ((*(short *)(childSymbol + 0x2c) != 0x7ffe) && (*(short *)(childSymbol + 0x2c) != 0x7fff)) {
              ParseSymbolTable__processOperand
                        (*(unsigned char **)(this + 0x68),operandSlots[operandSide + 2]);
              operandSlot0Arg = leftoverR4_00;
            }
            operandSide = operandSide + 1;
            if (1 < operandSide) break;
            fieldsBegin = *(int *)(structFieldList + 4);
          }
          operandPtrArg = operandSlots + 3;
          allowCopyPropagationArg = allowCopyPropagation;
          ((int (*)())TPPStreamCompiler__assignOperands)(this,operandSlots + 2,operandPtrArg,allowCopyPropagation);
          operandToFree = operandSlots[2];
          operandSlot0Arg = leftoverR4_01;
          if (operandSlots[2] != (void *)0x0) {
            __ZN12ParseOperandD1Ev(operandSlots[2]);
            __ZdlPv(operandToFree);
            operandSlot0Arg = leftoverR4_02;
          }
          operandToFree = operandSlots[3];
          if (operandSlots[3] != (void *)0x0) {
            __ZN12ParseOperandD1Ev(operandSlots[3]);
            __ZdlPv(operandToFree);
            operandSlot0Arg = leftoverR4_03;
          }
          if (fieldCountdown == 0) break;
          fieldsBegin = *(int *)(structFieldList + 4);
        }
      }
    }
  }
  else if (*(short *)(destSymbol + 0x2c) == 0x7fff) {
    elemCountdown = (uint)*(short *)(destSymbol + 0x2e);
    while (elemCountdown != 0) {
      elemCountdown = elemCountdown - 1;
      operandByteOffset = 0;
      sideCountdown = 1;
      do {
        elemOperand = operator_new(0x38);
        __ZN12ParseOperandC1Ev(elemOperand);
        *(void **)((int)operandSlots + operandByteOffset + 0x10) = elemOperand;
        childSymbol = operator_new(100);
        __ZN11ParseSymbolC1Ev(childSymbol);
        ParseSymbol__SetName(childSymbol,*(char **)(**(int **)((int)operandSlots + operandByteOffset) + 0x14));
        ParseSymbol__AddDirectIndex(childSymbol,elemCountdown);
        _sprintf((char *)&scratchDescA,DAT_a7b7bd90,elemCountdown);
        ParseSymbol__CatName(childSymbol,(char *)&scratchDescA);
        *(undefined4 *)(childSymbol + 0x40) = 0;
        *(undefined4 *)(childSymbol + 0x3c) = 0;
        ParseSymbol__SetParseTreeType(childSymbol,*(unsigned char **)(**(int **)((int)operandSlots + operandByteOffset) + 0xc));
        elemSourceSymbol = **(int **)((int)operandSlots + operandByteOffset);
        *(undefined4 *)(childSymbol + 0x48) = 1;
        *(undefined4 *)(childSymbol + 0x28) = *(undefined4 *)(elemSourceSymbol + 0x28);
        ParseSymbol__ResolveOpenGLType(childSymbol);
        **(undefined4 **)((int)operandSlots + operandByteOffset + 0x10) = childSymbol;
        if ((*(short *)(childSymbol + 0x2c) != 0x7ffe) && (*(short *)(childSymbol + 0x2c) != 0x7fff)) {
          ParseSymbolTable__processOperand
                    (*(unsigned char **)(this + 0x68),
                     *(unsigned char **)((int)operandSlots + operandByteOffset + 0x10));
        }
        sideCountdown = sideCountdown + -1;
        operandByteOffset = operandByteOffset + 4;
      } while (-1 < sideCountdown);
      ((int (*)())TPPStreamCompiler__assignOperands)(this,operandSlots + 4,operandSlots + 5,allowCopyPropagation);
      elemOperandToFree1 = operandSlotsHigh[0];
      if (operandSlotsHigh[0] != (void *)0x0) {
        __ZN12ParseOperandD1Ev(operandSlotsHigh[0]);
        __ZdlPv(elemOperandToFree1);
      }
      elemOperandToFree2 = operandSlotsHigh[1];
      if (operandSlotsHigh[1] != (void *)0x0) {
        __ZN12ParseOperandD1Ev(operandSlotsHigh[1]);
        __ZdlPv(elemOperandToFree2);
      }
    }
  }
  else {
    pendingOperand = *(unsigned char **)(this + 0x88);
    opLine = *(undefined4 *)(this + 0x90);
    opAuxA = 0;
    opAuxB = 0;
    opHeader = 0;
    opFlags = 0;
    opDest0 = 0;
    opDest1 = 0;
    opSrc0A = 0;
    opSrc0B = 0;
    opSrc1A = 0;
    opSrc1B = 0;
    opSrc2A = 0;
    opSrc2B = 0;
    opWord13 = 0;
    if (pendingOperand == (unsigned char *)0x0) {
      opHeader = 0x20000000;
      ((int (*)())TPPStreamCompiler__getOperandAsDestVar)((unsigned char *)&scratchDescA,this,*parseOperand1,allowCopyPropagationArg,leftoverR7,leftoverR8);
      opDest0 = scratchDescA;
      opDest1 = scratchDescB;
      if (TPPStreamCompiler__assignOperands__destIndirect != 0) {
        opDest1 = scratchDescB & 0x800fffff | 0x80000000;
      }
      ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&scratchDescA,this,*parseOperand2,allowCopyPropagationArg,leftoverR7,leftoverR8,leftoverR9,leftoverR10)
      ;
      opSrc0A = scratchDescA;
      opSrc0B = scratchDescB;
      if (TPPStreamCompiler__assignOperands__sourceIndirect != 0) {
        (*(unsigned int *)((unsigned char *)&(opSrc0A) + 0)) = (uint3)(scratchDescA >> 8) & 0x8fffff | 0x800000;
        opSrc0A = (uint)(*(unsigned int *)((unsigned char *)&(opSrc0A) + 0)) << 8;
      }
      opFlags = (opDest0 >> 0xc & 1) << 0x1c | opFlags & 0xefffffff;
      destSymbolForType = *(int *)*parseOperand1;
      if (destSymbolForType == 0) {
        destGlType = *(ushort *)(*parseOperand1 + 0x18);
      }
      else {
        destGlType = *(ushort *)(destSymbolForType + 0x2c);
      }
      streamType = GetPPStreamTypeForGLType((uint)destGlType);
      opFlags = (streamType & 7) << 0x17 | opFlags & 0xfc7fffff;
      destLogicalSize = ParseOperand__GetLogicalSize(*parseOperand1);
      opFlags = (destLogicalSize + -1) * 0x4000000 & 0xc000000U | opFlags & 0xf3f3ffff;
      savedDestA = opDest0;
      savedDestB = opDest1;
      scratchDescA = opSrc0A;
      scratchDescB = opSrc0B;
      destEqualsSourceResult = ((int (*)())TPPStreamCompiler__duplicateDestinationSource)(this,opDest0,opDest1,opSrc0A,opSrc0B);
      if ((destEqualsSourceResult == 0) &&
         (((allowCopyPropagation == 0 || (*(int *)(this + 0xc4) < 2)) ||
          (destEqualsSourceResult = ((int (*)())TPPStreamCompiler__copyPropagateCompilerTemp)(this,(unsigned char *)&opHeader,*parseOperand2),
          destEqualsSourceResult == 0)))) {
        _PPStreamAddOperation(*(undefined4 *)(this + 0x70),&opHeader,0,0);
      }
    }
    else {
      operandToFree = *parseOperand1;
      operandSlotsHigh[2] = *(unsigned char **)(pendingOperand + 0xc);
      if (operandToFree != (unsigned char *)0x0) {
        __ZN12ParseOperandD1Ev(operandToFree);
        __ZdlPv(operandToFree);
        pendingOperand = *(unsigned char **)(this + 0x88);
      }
      *parseOperand1 = pendingOperand;
      operandPtrArg = operandSlots + 6;
      *(undefined4 *)(this + 0x88) = 0;
      *(undefined4 *)(*parseOperand1 + 0xc) = 0;
      opHeader = opHeader & 0x1c03ffff | 0x41b40000;
      ((int (*)())__ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_S2_)(this,parseOperand1,parseOperand2,operandPtrArg);
      ParseOperand__RemoveDirectIndex(*parseOperand1);
      ((int (*)())TPPStreamCompiler__getOperandAsDestVar)((unsigned char *)&scratchDescA,this,*parseOperand1,operandPtrArg,leftoverR7,leftoverR8);
      opDest0 = scratchDescA;
      opDest1 = scratchDescB;
      ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&scratchDescA,this,*parseOperand2,operandPtrArg,leftoverR7,leftoverR8,leftoverR9,leftoverR10);
      opSrc0A = scratchDescA;
      opSrc0B = scratchDescB;
      ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&scratchDescA,this,operandSlotsHigh[2],operandPtrArg,leftoverR7,leftoverR8,leftoverR9,leftoverR10);
      opFlags = (opDest0 >> 0xc & 1) << 0x1c | opFlags & 0xefffffff;
      opSrc1A = scratchDescA;
      opSrc1B = scratchDescB;
      destSymbolForType = *(int *)*parseOperand1;
      if (destSymbolForType == 0) {
        destGlType = *(ushort *)(*parseOperand1 + 0x18);
      }
      else {
        destGlType = *(ushort *)(destSymbolForType + 0x2c);
      }
      streamType = GetPPStreamTypeForGLType((uint)destGlType);
      opFlags = (streamType & 7) << 0x17 | opFlags & 0xfc7fffff;
      destLogicalSize = ParseOperand__GetLogicalSize(*parseOperand1);
      opFlags = (destLogicalSize + -1) * 0x4000000 & 0xc000000U | opFlags & 0xf3f3ffff;
      _PPStreamAddOperation(*(undefined4 *)(this + 0x70),&opHeader,0,0);
      indexOperandToFree = operandSlotsHigh[2];
      if (operandSlotsHigh[2] != (void *)0x0) {
        __ZN12ParseOperandD1Ev(operandSlotsHigh[2]);
        __ZdlPv(indexOperandToFree);
      }
    }
  }
  if (addressLoadsEmitted) {
    TPPStreamCompiler__assignOperands__sourceIndirect = 0;
    TPPStreamCompiler__assignOperands__destIndirect = 0;
  }
  return;
}

/* TPPStreamCompiler__getArrayOffset @ 0x97bc62c4 (404 bytes) */
int TPPStreamCompiler__getArrayOffset(this, arrayOperand)
  unsigned char * this;
  unsigned char * arrayOperand;
{
  bool isRegisterChunk;
  byte chunkKind;
  undefined4 *foundSymbol;
  unsigned char * elementSymbol;
  undefined4 leftoverR7;
  undefined4 leftoverR8;
  undefined4 leftoverR10;
  uint baseRegister;
  uint elementRegister;
  char indexSuffix [20];
  
  baseRegister = 0;
  foundSymbol = (undefined4 *)
           ParseSymbolTable__FindFirstElement
                     (*(unsigned char **)(this + 0x68),*(unsigned char **)arrayOperand);
  if (foundSymbol != (undefined4 *)0x0) {
    chunkKind = *(byte *)*foundSymbol;
    if (chunkKind != 2) {
      if (chunkKind < 3) {
        isRegisterChunk = chunkKind == 0;
      }
      else {
        if (chunkKind == 3) goto setBaseRegister;
        isRegisterChunk = chunkKind == 4;
      }
      if (!isRegisterChunk) goto setElementSymbol;
    }
setBaseRegister:
    baseRegister = (uint)*(ushort *)((byte *)*foundSymbol + 0x12);
  }
setElementSymbol:
  elementSymbol = operator_new(100);
  __ZN11ParseSymbolC1Ev(elementSymbol);
  ParseSymbol__SetName(elementSymbol,*(char **)(*(int *)arrayOperand + 0x14));
  ParseSymbol__RemoveArrayIndex(elementSymbol);
  ParseSymbol__AddDirectIndex(elementSymbol,1);
  _sprintf(indexSuffix,DAT_a7b7bd90,1);
  ParseSymbol__CatName(elementSymbol,indexSuffix);
  *(undefined4 *)(elementSymbol + 0x28) = *(undefined4 *)(*(int *)arrayOperand + 0x28);
  ParseSymbol__SetParseTreeType(elementSymbol,*(unsigned char **)(*(int *)arrayOperand + 0xc));
  *(undefined4 *)(elementSymbol + 0x48) = *(undefined4 *)(*(int *)arrayOperand + 0x48);
  ParseSymbol__ResolveOpenGLType(elementSymbol);
  foundSymbol = (undefined4 *)
           ParseSymbolTable__FindFirstElement(*(unsigned char **)(this + 0x68),elementSymbol);
  if (elementSymbol != (unsigned char *)0x0) {
    __ZN11ParseSymbolD1Ev(elementSymbol);
    __ZdlPv(elementSymbol);
  }
  if (foundSymbol == (undefined4 *)0x0) {
    TPPStreamCompiler__warning(this,(char *)0x0,*(char **)(*(int *)arrayOperand + 0x14),DAT_a7b7bd3c,leftoverR7,leftoverR8,
            *(int *)arrayOperand,leftoverR10);
    elementRegister = baseRegister;
    goto returnElementRegister;
  }
  chunkKind = *(byte *)*foundSymbol;
  if (chunkKind != 2) {
    if (chunkKind < 3) {
      isRegisterChunk = chunkKind == 0;
    }
    else {
      if (chunkKind == 3) goto setElementRegister;
      isRegisterChunk = chunkKind == 4;
    }
    elementRegister = 0;
    if (!isRegisterChunk) goto returnElementRegister;
  }
setElementRegister:
  elementRegister = (uint)*(ushort *)((byte *)*foundSymbol + 0x12);
returnElementRegister:
  return elementRegister - baseRegister;
}

/* TPPStreamCompiler__constructReplicate @ 0x97bc6458 (640 bytes) */
int TPPStreamCompiler__constructReplicate(this, parseOperand1, parseOperand2, forwardedArg4)
  unsigned char ** this;
  unsigned char ** parseOperand1;
  int parseOperand2;
  undefined4 forwardedArg4;
{
  int destSymbol;
  int logicalSize;
  bool isScalarValueType;
  ushort sourceGlType;
  int destLogicalSize;
  uint streamType;
  int *sourceOperand;
  undefined4 leftoverR7;
  undefined4 leftoverR8;
  undefined4 unusedArg7;
  undefined4 unusedArg8;
  int componentIndex;
  undefined4 opHeader;
  uint opFlags;
  uint opDest0;
  undefined4 opDest1;
  uint opSrc0A;
  undefined4 opSrc0B;
  undefined4 opSrc1A;
  undefined4 opSrc1B;
  undefined4 opSrc2A;
  undefined4 opSrc2B;
  undefined4 opAuxA;
  undefined4 opAuxB;
  unsigned char * opLine;
  undefined4 opWord13;
  uint operandDescA;
  undefined4 operandDescB;
  undefined4 constantWords [6];
  
  constantWords[0] = 0;
  ((int (*)())__ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_)(this,parseOperand1,(unsigned char **)parseOperand2);
  unusedArg7 = 0;
  unusedArg8 = 0;
  opFlags = 0;
  opLine = this[0x24];
  opWord13 = 0;
  opHeader = 0x20000000;
  opAuxA = 0;
  opAuxB = 0;
  opDest0 = 0;
  opDest1 = 0;
  opSrc0A = 0;
  opSrc0B = 0;
  opSrc1A = 0;
  opSrc1B = 0;
  opSrc2A = 0;
  opSrc2B = 0;
  ((int (*)())TPPStreamCompiler__getOperandAsDestVar)((unsigned char *)&operandDescA,this,*parseOperand1,forwardedArg4,leftoverR7,leftoverR8);
  sourceOperand = *(int **)parseOperand2;
  opDest0 = operandDescA & 0xfffe1c2f | 0x6c;
  opDest1 = operandDescB;
  if (*sourceOperand == 0) {
    sourceGlType = *(ushort *)(sourceOperand + 6);
    if (sourceGlType == 0x1406) {
      constantWords[0] = *(undefined4 *)sourceOperand[1];
    }
    else {
      if (sourceGlType < 0x1407) {
        isScalarValueType = sourceGlType == 0x1404;
      }
      else {
        isScalarValueType = sourceGlType == 0x8b56;
      }
      if (isScalarValueType) {
        constantWords[0] = *(undefined4 *)sourceOperand[1];
      }
    }
    if (*sourceOperand == 0) {
      sourceGlType = *(ushort *)(sourceOperand + 6);
    }
    else {
      sourceGlType = *(ushort *)(*sourceOperand + 0x2c);
    }
    ((int (*)())TPPStreamCompiler__getConstantAsSourceVar)((unsigned char *)&operandDescA,(uint)this,constantWords,1,(uint)sourceGlType);
  }
  else {
    ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&operandDescA,this,sourceOperand,forwardedArg4,leftoverR7,leftoverR8,unusedArg7,unusedArg8);
  }
  opSrc0A = operandDescA;
  opSrc0B = operandDescB;
  for (componentIndex = 0; destLogicalSize = ParseOperand__GetLogicalSize(*parseOperand1), componentIndex < destLogicalSize; componentIndex = componentIndex + 1)
  {
    if (componentIndex == 1) {
      opDest0 = opDest0 & 0xffffff3f | 0x4000;
    }
    else if (componentIndex < 2) {
      if (componentIndex == 0) {
        opDest0 = opDest0 & 0xfffffcff | 0x2000;
      }
    }
    else if (componentIndex == 2) {
      opDest0 = opDest0 & 0xffffffcf | 0x8000;
    }
    else if (componentIndex == 3) {
      opDest0 = opDest0 & 0xfffffff3 | 0x10000;
    }
  }
  opFlags = (opDest0 >> 0xc & 1) << 0x1c | opFlags & 0xefffffff;
  destSymbol = *(int *)*parseOperand1;
  if (destSymbol == 0) {
    sourceGlType = *(ushort *)(*parseOperand1 + 0x18);
  }
  else {
    sourceGlType = *(ushort *)(destSymbol + 0x2c);
  }
  streamType = GetPPStreamTypeForGLType((uint)sourceGlType);
  opFlags = (streamType & 7) << 0x17 | opFlags & 0xfc7fffff;
  logicalSize = ParseOperand__GetLogicalSize(*parseOperand1);
  opFlags = (logicalSize + -1) * 0x4000000 & 0xc000000U | opFlags & 0xf3f3ffff;
  ((int (*)())TPPStreamCompiler__AddOperation)((unsigned char *)this,parseOperand1,(unsigned char *)&opHeader,(char *)0x0,0);
  return 1;
}

/* TPPStreamCompiler__constructDiagonal @ 0x97bc66d8 (1452 bytes) */
int TPPStreamCompiler__constructDiagonal(this, parseOperand1, parseOperand2, forwardedArg4)
  unsigned char ** this;
  unsigned char ** parseOperand1;
  int parseOperand2;
  undefined4 forwardedArg4;
{
  int destSymbol;
  uint fillDescBits;
  uint streamType;
  int logicalSize2;
  int isMatrix;
  bool sizeIsNot4;
  bool isFirstColumn;
  bool isScalarValueType;
  ushort sourceGlType;
  undefined4 *zeroCursor;
  int logicalSize;
  int zeroCountdown;
  uint destDescMasked;
  undefined4 leftoverR7;
  undefined4 leftoverR8;
  uint destDescWithOpcode;
  undefined4 unusedArg8;
  int *sourceOperand;
  int columnCount;
  undefined4 *diagonalCell;
  int loopIndex;
  undefined4 diagheader;
  uint diagflags;
  uint diagdest0;
  undefined4 diagdest1;
  uint diagsrc0A;
  undefined4 diagsrc0B;
  undefined4 diagsrc1A;
  undefined4 diagsrc1B;
  undefined4 diagsrc2A;
  undefined4 diagsrc2B;
  undefined4 diagauxA;
  undefined4 diagauxB;
  unsigned char * diagline;
  undefined4 diagword13;
  undefined4 fillheader;
  uint fillflags;
  uint filldest0;
  undefined4 filldest1;
  uint fillsrc0A;
  undefined4 fillsrc0B;
  undefined4 fillsrc1A;
  undefined4 fillsrc1B;
  undefined4 fillsrc2A;
  undefined4 fillsrc2B;
  undefined4 fillauxA;
  undefined4 fillauxB;
  unsigned char * fillline;
  undefined4 fillword13;
  undefined4 constantCells [4];
  uint operandDescA;
  undefined4 operandDescB;
  
  ((int (*)())__ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_)(this,parseOperand1,(unsigned char **)parseOperand2);
  loopIndex = 0;
  logicalSize = ParseOperand__GetLogicalSize(*parseOperand1);
  isMatrix = ParseOperand__IsMatrix(*parseOperand1);
  columnCount = logicalSize;
  if (isMatrix == 0) {
    columnCount = 1;
  }
  if (columnCount != 0) {
    sizeIsNot4 = logicalSize != 4;
    diagonalCell = constantCells;
    do {
      zeroCursor = constantCells;
      zeroCountdown = 4;
      do {
        *zeroCursor = 0;
        zeroCursor = zeroCursor + 1;
        zeroCountdown = zeroCountdown + -1;
      } while (zeroCountdown != 0);
      isFirstColumn = loopIndex == 0;
      if (isFirstColumn) {
        ParseOperand__AddDirectIndex(*parseOperand1,0);
      }
      else {
        *(int *)(*(int *)(*parseOperand1 + 0x20) * 4 + *(int *)(*parseOperand1 + 0x1c) + -4) = loopIndex;
      }
      fillline = this[0x24];
      fillword13 = 0;
      fillheader = 0x20000000;
      filldest0 = 0;
      filldest1 = 0;
      fillsrc0A = 0;
      fillsrc0B = 0;
      fillsrc1A = 0;
      fillsrc1B = 0;
      fillsrc2A = 0;
      fillsrc2B = 0;
      fillauxA = 0;
      fillauxB = 0;
      fillflags = 0;
      ((int (*)())TPPStreamCompiler__getOperandAsDestVar)((unsigned char *)&operandDescA,this,*parseOperand1,forwardedArg4,leftoverR7,leftoverR8);
      sourceOperand = *(int **)parseOperand2;
      destDescMasked = operandDescA & 0xfffe1c0f;
      destDescWithOpcode = destDescMasked | 0x6c;
      filldest1 = operandDescB;
      filldest0 = destDescWithOpcode;
      if (*sourceOperand == 0) {
        sourceGlType = *(ushort *)(sourceOperand + 6);
        if (sourceGlType == 0x1406) {
          *diagonalCell = *(undefined4 *)sourceOperand[1];
        }
        else {
          if (sourceGlType < 0x1407) {
            isScalarValueType = sourceGlType == 0x1404;
          }
          else {
            isScalarValueType = sourceGlType == 0x8b56;
          }
          if (isScalarValueType) {
            *diagonalCell = *(undefined4 *)sourceOperand[1];
          }
        }
        if (loopIndex == 1) {
          filldest0 = destDescMasked | 0x406c;
        }
        else if (loopIndex < 2) {
          if (isFirstColumn) {
            filldest0 = destDescMasked | 0x206c;
          }
        }
        else if (loopIndex == 2) {
          filldest0 = destDescMasked | 0x806c;
        }
        else if (loopIndex == 3) {
          filldest0 = destDescWithOpcode & 0xfffffff3 | 0x1000c;
        }
      }
      else {
        diagflags = 0;
        diagline = this[0x24];
        diagheader = 0x20000000;
        diagword13 = 0;
        diagdest0 = 0;
        diagdest1 = 0;
        diagsrc0A = 0;
        diagsrc0B = 0;
        diagsrc1A = 0;
        diagsrc1B = 0;
        diagsrc2A = 0;
        diagsrc2B = 0;
        diagauxA = 0;
        diagauxB = 0;
        ((int (*)())TPPStreamCompiler__getOperandAsDestVar)((unsigned char *)&operandDescA,this,*parseOperand1,forwardedArg4,leftoverR7,leftoverR8);
        diagdest0 = operandDescA & 0xfffe1c03 | 0x6c;
        diagdest1 = operandDescB;
        ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&operandDescA,this,*(undefined4 *)parseOperand2,forwardedArg4,leftoverR7,leftoverR8,
                   destDescWithOpcode,unusedArg8);
        diagsrc0A = operandDescA;
        diagsrc0B = operandDescB;
        if (loopIndex == 1) {
          diagdest0 = diagdest0 & 0xffffff3f | 0x4000;
        }
        else if (loopIndex < 2) {
          if (isFirstColumn) {
            diagdest0 = diagdest0 & 0xfffffcff | 0x2000;
          }
        }
        else if (loopIndex == 2) {
          diagdest0 = diagdest0 & 0xffffffcf | 0x8000;
        }
        else if (loopIndex == 3) {
          diagdest0 = diagdest0 & 0xfffffff3 | 0x10000;
        }
        diagflags = (diagdest0 >> 0xc & 1) << 0x1c | diagflags & 0xefffffff;
        destSymbol = *(int *)*parseOperand1;
        if (destSymbol == 0) {
          sourceGlType = *(ushort *)(*parseOperand1 + 0x18);
        }
        else {
          sourceGlType = *(ushort *)(destSymbol + 0x2c);
        }
        streamType = GetPPStreamTypeForGLType((uint)sourceGlType);
        diagflags = (streamType & 7) << 0x17 | diagflags & 0xfc7fffff;
        logicalSize2 = ParseOperand__GetLogicalSize(*parseOperand1);
        diagflags = (logicalSize2 + -1) * 0x4000000 & 0xc000000U | diagflags & 0xf3f3ffff;
        ((int (*)())TPPStreamCompiler__AddOperation)((unsigned char *)this,parseOperand1,(unsigned char *)&diagheader,
                     (char *)0x0,0);
        sourceOperand = *(int **)parseOperand2;
      }
      if (loopIndex == 1) {
        fillDescBits = filldest0 & 0xfffffcff | 0x2000;
        if (logicalSize != 3) {
          if (sizeIsNot4) goto setFilldest0;
          fillDescBits = filldest0 & 0xfffffcf3 | 0x1200c;
        }
loopSetFillDescBits:
        fillDescBits = fillDescBits & 0xffffffcf | 0x8020;
      }
      else {
        fillDescBits = filldest0;
        if (loopIndex < 2) {
          if (isFirstColumn) {
            if (logicalSize == 3) {
loopSetFilldest0:
              filldest0 = filldest0 & 0xffffffcf | 0x8020;
loopSetFillDescBits2:
              fillDescBits = filldest0 & 0xffffff3f | 0x4040;
            }
            else if (logicalSize < 4) {
              if (logicalSize == 2) goto loopSetFillDescBits2;
            }
            else if (!sizeIsNot4) {
              filldest0 = filldest0 & 0xfffffff3 | 0x1000c;
              goto loopSetFilldest0;
            }
          }
        }
        else if (loopIndex == 2) {
          fillDescBits = filldest0 & 0xfffffc3f | 0x6040;
          if (!sizeIsNot4) {
            fillDescBits = filldest0 & 0xfffffc33 | 0x1604c;
          }
        }
        else if (loopIndex == 3) {
          fillDescBits = filldest0 & 0xfffffc3f | 0x6040;
          goto loopSetFillDescBits;
        }
      }
setFilldest0:
      filldest0 = fillDescBits;
      if (*sourceOperand == 0) {
        sourceGlType = *(ushort *)(sourceOperand + 6);
      }
      else {
        sourceGlType = *(ushort *)(*sourceOperand + 0x2c);
      }
      ((int (*)())TPPStreamCompiler__getConstantAsSourceVar)((unsigned char *)&operandDescA,(uint)this,constantCells,logicalSize,(uint)sourceGlType);
      fillflags = (filldest0 >> 0xc & 1) << 0x1c | fillflags & 0xefffffff;
      fillsrc0A = operandDescA;
      fillsrc0B = operandDescB;
      destSymbol = *(int *)*parseOperand1;
      if (destSymbol == 0) {
        sourceGlType = *(ushort *)(*parseOperand1 + 0x18);
      }
      else {
        sourceGlType = *(ushort *)(destSymbol + 0x2c);
      }
      streamType = GetPPStreamTypeForGLType((uint)sourceGlType);
      fillflags = (streamType & 7) << 0x17 | fillflags & 0xfc7fffff;
      loopIndex = loopIndex + 1;
      logicalSize2 = ParseOperand__GetLogicalSize(*parseOperand1);
      fillflags = (logicalSize2 + -1) * 0x4000000 & 0xc000000U | fillflags & 0xf3f3ffff;
      forwardedArg4 = 0;
      leftoverR7 = 0;
      ((int (*)())TPPStreamCompiler__AddOperation)((unsigned char *)this,parseOperand1,(unsigned char *)&fillheader,(char *)0x0,
                   0);
      diagonalCell = diagonalCell + 1;
    } while (loopIndex != columnCount);
  }
  ParseOperand__RemoveDirectIndex(*parseOperand1);
  return 1;
}

/* TPPStreamCompiler__constructElement @ 0x97bc6c84 (1744 bytes) */
int TPPStreamCompiler__constructElement(this, parseOperand1, parseOperand2, argCountThenLeftover)
  unsigned char * this;
  unsigned char ** parseOperand1;
  unsigned char ** parseOperand2;
  int argCountThenLeftover;
{
  int argSymbol;
  int destSymbol;
  int argByteOffsetOrCopyResult;
  int destIsMatrixNow;
  int elemByteOffset;
  undefined4 *laneStorePtr;
  bool destFilled;
  int moveLaneCount;
  int moveElemsLeft;
  int zeroCountdown;
  int columnCount;
  uint streamType;
  int isMatrix3;
  int isMatrix2;
  int isMatrix;
  bool isFirstColumn;
  ushort argGlType;
  undefined4 *zeroCursor;
  int logicalSize;
  int argIndex;
  int constElemsLeft;
  uint leftoverCopy;
  uint argElemsUsedWork;
  undefined4 leftoverArg7;
  uint argColumnSize;
  uint pendingConstLanes;
  undefined1 *laneStackAddr;
  uint argElemsUsed;
  int argsLeft;
  int argSymbolRef;
  unsigned char ** argCursor;
  int destLane;
  undefined4 movOpHeader;
  uint movOpFlags;
  uint movOpDest0;
  undefined4 movOpDest1;
  uint movOpSrc0A;
  undefined4 movOpSrc0B;
  undefined4 movOpSrc1A;
  undefined4 movOpSrc1B;
  undefined4 movOpSrc2A;
  undefined4 movOpSrc2B;
  undefined4 movOpAuxA;
  undefined4 movOpAuxB;
  undefined4 movOpLine;
  undefined4 movOpWord13;
  undefined4 constOpHeader;
  uint constOpFlags;
  uint constOpDest0;
  undefined4 constOpDest1;
  uint constOpSrc0A;
  undefined4 constOpSrc0B;
  undefined4 constOpSrc1A;
  undefined4 constOpSrc1B;
  undefined4 constOpSrc2A;
  undefined4 constOpSrc2B;
  undefined4 constOpAuxA;
  undefined4 constOpAuxB;
  undefined4 constOpLine;
  undefined4 constOpWord13;
  undefined4 constantLanes [4];
  uint operandDescA;
  undefined4 operandDescB;
  int argsConsumed;
  int columnIndex;
  uint argColumnIndex;
  uint argColumnCount;
  
  argsLeft = argCountThenLeftover;
  argCursor = parseOperand2;
  if (0 < argCountThenLeftover) {
    do {
      ((int (*)())__ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_)(this,parseOperand1,argCursor);
      argsLeft = argsLeft + -1;
      argCursor = argCursor + 1;
    } while (argsLeft != 0);
  }
  argsConsumed = 0;
  argColumnSize = 0;
  logicalSize = ParseOperand__GetLogicalSize(*parseOperand1);
  argElemsUsed = 0;
  isMatrix2 = ParseOperand__IsMatrix(*parseOperand1);
  columnIndex = 0;
  columnCount = logicalSize;
  if (isMatrix2 == 0) {
    columnCount = 1;
  }
  argColumnIndex = 0xffffffff;
  argColumnCount = 0;
  pendingConstLanes = 0;
  argIndex = -1;
  if (columnCount != 0) {
    do {
      isFirstColumn = columnIndex == 0;
      if ((isFirstColumn) || (pendingConstLanes != 0)) {
        zeroCountdown = 4;
        zeroCursor = constantLanes;
        do {
          *zeroCursor = 0;
          zeroCursor = zeroCursor + 1;
          zeroCountdown = zeroCountdown + -1;
        } while (zeroCountdown != 0);
        pendingConstLanes = 0;
      }
      destLane = 0;
      destIsMatrixNow = ParseOperand__IsMatrix(*parseOperand1);
      if (destIsMatrixNow != 0) {
        if (isFirstColumn) {
          ParseOperand__AddDirectIndex(*parseOperand1,0);
        }
        else {
          *(int *)(*(int *)(*parseOperand1 + 0x20) * 4 + *(int *)(*parseOperand1 + 0x1c) + -4) = columnIndex;
        }
      }
      constOpFlags = 0;
      constOpLine = *(undefined4 *)(this + 0x90);
      constOpHeader = 0x20000000;
      destFilled = logicalSize == 0;
      constOpDest0 = 0;
      constOpDest1 = 0;
      constOpSrc0A = 0;
      constOpSrc0B = 0;
      constOpSrc1A = 0;
      constOpSrc1B = 0;
      constOpSrc2A = 0;
      constOpSrc2B = 0;
      constOpAuxA = 0;
      constOpAuxB = 0;
      constOpWord13 = 0;
      ((int (*)())TPPStreamCompiler__getOperandAsDestVar)((unsigned char *)&operandDescA,this,*parseOperand1,argCountThenLeftover,laneStorePtr,argElemsUsedWork);
      constOpDest0 = operandDescA & 0xfffe1c2f | 0x6c;
      constOpDest1 = operandDescB;
      if (!destFilled) {
        laneStackAddr = &STACKARG(0xfffffec0) + pendingConstLanes * 4;
        leftoverCopy = argElemsUsedWork;
        do {
          argByteOffsetOrCopyResult = argIndex << 2;
          argElemsUsedWork = argElemsUsed;
          if (argElemsUsed == argColumnSize) {
            argColumnIndex = argColumnIndex + 1;
            if (argColumnIndex == argColumnCount) {
              argIndex = argIndex + 1;
              argByteOffsetOrCopyResult = argIndex * 4;
              argsConsumed = argsConsumed + 1;
              argColumnSize = ParseOperand__GetLogicalSize(parseOperand2[argIndex]);
              isMatrix3 = ParseOperand__IsMatrix(parseOperand2[argIndex]);
              if ((isMatrix3 == 0) || (argColumnCount = argColumnSize, *(int *)(parseOperand2[argIndex] + 0x20) != 0)) {
                argColumnCount = 1;
              }
              argColumnIndex = 0;
            }
            argElemsUsedWork = 0;
            if (1 < (int)argColumnCount) {
              if (argColumnIndex == 0) {
                ParseOperand__AddDirectIndex(*(unsigned char **)(argByteOffsetOrCopyResult + (int)parseOperand2),0);
              }
              else {
                *(uint *)(*(int *)(*(int *)(argByteOffsetOrCopyResult + (int)parseOperand2) + 0x20) * 4 +
                          *(int *)(*(int *)(argByteOffsetOrCopyResult + (int)parseOperand2) + 0x1c) + -4) = argColumnIndex;
              }
            }
          }
          argElemsUsed = argElemsUsedWork;
          if (**(int **)(argByteOffsetOrCopyResult + (int)parseOperand2) == 0) {
            constElemsLeft = argColumnSize - argElemsUsedWork;
            if (logicalSize - destLane < (int)(argColumnSize - argElemsUsedWork)) {
              constElemsLeft = logicalSize - destLane;
            }
            if ((int)argElemsUsedWork < (int)(argElemsUsedWork + constElemsLeft)) {
              constElemsLeft = (argElemsUsedWork + constElemsLeft) - argElemsUsedWork;
              argCountThenLeftover = 0x8b56;
              laneStorePtr = (undefined4 *)(laneStackAddr + 0xc0);
              do {
                argSymbolRef = **(int **)(argByteOffsetOrCopyResult + (int)parseOperand2);
                if (argSymbolRef == 0) {
                  argGlType = *(ushort *)(*(int **)(argByteOffsetOrCopyResult + (int)parseOperand2) + 6);
                }
                else {
                  argGlType = *(ushort *)(argSymbolRef + 0x2c);
                }
                if (argGlType == 0x1406) {
                  constantLanes[pendingConstLanes] =
                       *(undefined4 *)(argElemsUsedWork * 4 + *(int *)(*(int *)(argByteOffsetOrCopyResult + (int)parseOperand2) + 4));
                }
                else if (argGlType < 0x1407) {
                  if (argGlType == 0x1404) {
                    elemByteOffset = argElemsUsedWork * 4;
                    constantLanes[pendingConstLanes] =
                         *(undefined4 *)(elemByteOffset + *(int *)(*(int *)(argByteOffsetOrCopyResult + (int)parseOperand2) + 4));
                  }
                }
                else if (argGlType == 0x8b56) {
                  *laneStorePtr = *(undefined4 *)
                            (argElemsUsedWork * 4 + *(int *)(*(int *)(argByteOffsetOrCopyResult + (int)parseOperand2) + 4));
                }
                if (destLane == 1) {
                  constOpDest0 = (pendingConstLanes & 3) << 6 | constOpDest0 & 0xffffff3f | 0x4000;
                }
                else if (destLane < 2) {
                  if (destLane == 0) {
                    constOpDest0 = (pendingConstLanes & 3) << 8 | constOpDest0 & 0xfffffcff | 0x2000;
                  }
                }
                else if (destLane == 2) {
                  constOpDest0 = (pendingConstLanes & 3) << 4 | constOpDest0 & 0xffffffcf | 0x8000;
                }
                else if (destLane == 3) {
                  constOpDest0 = (pendingConstLanes & 3) << 2 | constOpDest0 & 0xfffffff3 | 0x10000;
                }
                destLane = destLane + 1;
                pendingConstLanes = pendingConstLanes + 1;
                laneStackAddr = laneStackAddr + 4;
                laneStorePtr = laneStorePtr + 1;
                argElemsUsed = argElemsUsed + 1;
                argElemsUsedWork = argElemsUsedWork + 1;
                constElemsLeft = constElemsLeft + -1;
              } while (constElemsLeft != 0);
              destFilled = destLane == logicalSize;
            }
          }
          else {
            movOpFlags = 0;
            leftoverArg7 = 1;
            movOpLine = *(undefined4 *)(this + 0x90);
            moveLaneCount = 0;
            movOpHeader = 0x20000000;
            movOpDest0 = 0;
            movOpDest1 = 0;
            movOpSrc0A = 0;
            movOpSrc0B = 0;
            movOpSrc1A = 0;
            movOpSrc1B = 0;
            movOpSrc2A = 0;
            movOpSrc2B = 0;
            movOpAuxA = 0;
            movOpAuxB = 0;
            movOpWord13 = 0;
            ((int (*)())TPPStreamCompiler__getOperandAsDestVar)((unsigned char *)&operandDescA,this,*parseOperand1,argCountThenLeftover,laneStorePtr,leftoverCopy);
            movOpDest0 = operandDescA & 0xfffe1c2f | 0x6c;
            movOpDest1 = operandDescB;
            ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&operandDescA,this,*(undefined4 *)(argByteOffsetOrCopyResult + (int)parseOperand2),argCountThenLeftover
                       ,laneStorePtr,leftoverCopy,leftoverArg7,elemByteOffset);
            movOpSrc0A = operandDescA;
            movOpSrc0B = operandDescB;
            moveElemsLeft = argColumnSize - argElemsUsedWork;
            if (logicalSize - destLane < (int)(argColumnSize - argElemsUsedWork)) {
              moveElemsLeft = logicalSize - destLane;
            }
            if (0 < moveElemsLeft) {
              do {
                if (destLane == 1) {
                  movOpDest0 = (argElemsUsedWork & 3) << 6 | movOpDest0 & 0xffffff3f | 0x4000;
loopSetMoveLaneCount:
                  moveLaneCount = moveLaneCount + 1;
                }
                else {
                  if (1 < destLane) {
                    if (destLane == 2) {
                      movOpDest0 = (argElemsUsedWork & 3) << 4 | movOpDest0 & 0xffffffcf | 0x8000;
                    }
                    else {
                      if (destLane != 3) goto setArgElemsUsedWork;
                      movOpDest0 = (argElemsUsedWork & 3) << 2 | movOpDest0 & 0xfffffff3 | 0x10000;
                    }
                    goto loopSetMoveLaneCount;
                  }
                  if (destLane == 0) {
                    movOpDest0 = (argElemsUsedWork & 3) << 8 | movOpDest0 & 0xfffffcff | 0x2000;
                    goto loopSetMoveLaneCount;
                  }
                }
setArgElemsUsedWork:
                argElemsUsedWork = argElemsUsedWork + 1;
                destLane = destLane + 1;
                moveElemsLeft = moveElemsLeft + -1;
              } while (moveElemsLeft != 0);
              destFilled = destLane == logicalSize;
              argElemsUsed = argElemsUsedWork;
            }
            argElemsUsedWork = leftoverCopy;
            if (((1 < columnCount) || (*(int *)(this + 0xc4) < 2)) ||
               (argByteOffsetOrCopyResult = ((int (*)())TPPStreamCompiler__copyPropagateCompilerTemp)(this,(unsigned char *)&movOpHeader,
                                    *(unsigned char **)(argByteOffsetOrCopyResult + (int)parseOperand2)), argElemsUsedWork = leftoverCopy,
               argByteOffsetOrCopyResult == 0)) {
              movOpFlags = (movOpDest0 >> 0xc & 1) << 0x1c | movOpFlags & 0xefffffff;
              destSymbol = *(int *)*parseOperand1;
              if (destSymbol == 0) {
                argGlType = *(ushort *)(*parseOperand1 + 0x18);
              }
              else {
                argGlType = *(ushort *)(destSymbol + 0x2c);
              }
              streamType = GetPPStreamTypeForGLType((uint)argGlType);
              movOpFlags = (moveLaneCount + -1) * 0x4000000 & 0xc000000U |
                         (streamType & 7) << 0x17 | movOpFlags & 0xf073ffff;
              argCountThenLeftover = 0;
              laneStorePtr = (undefined4 *)0x0;
              ((int (*)())TPPStreamCompiler__AddOperation)(this,parseOperand1,(unsigned char *)&movOpHeader,(char *)0x0,0);
            }
          }
          leftoverCopy = argElemsUsedWork;
        } while (!destFilled);
      }
      if (pendingConstLanes != 0) {
        argSymbol = *(int *)parseOperand2[argIndex];
        if (argSymbol == 0) {
          argGlType = *(ushort *)(parseOperand2[argIndex] + 0x18);
        }
        else {
          argGlType = *(ushort *)(argSymbol + 0x2c);
        }
        ((int (*)())TPPStreamCompiler__getConstantAsSourceVar)((unsigned char *)&operandDescA,(uint)this,constantLanes,pendingConstLanes,(uint)argGlType);
        constOpFlags = (constOpDest0 >> 0xc & 1) << 0x1c | constOpFlags & 0xefffffff;
        constOpSrc0A = operandDescA;
        constOpSrc0B = operandDescB;
        destSymbol = *(int *)*parseOperand1;
        if (destSymbol == 0) {
          argGlType = *(ushort *)(*parseOperand1 + 0x18);
        }
        else {
          argGlType = *(ushort *)(destSymbol + 0x2c);
        }
        streamType = GetPPStreamTypeForGLType((uint)argGlType);
        constOpFlags = (pendingConstLanes - 1) * 0x4000000 & 0xc000000 |
                   (streamType & 7) << 0x17 | constOpFlags & 0xf073ffff;
        argCountThenLeftover = 0;
        laneStorePtr = (undefined4 *)0x0;
        ((int (*)())TPPStreamCompiler__AddOperation)(this,parseOperand1,(unsigned char *)&constOpHeader,(char *)0x0,0);
      }
      columnIndex = columnIndex + 1;
    } while (columnIndex != columnCount);
  }
  isMatrix = ParseOperand__IsMatrix(*parseOperand1);
  if (isMatrix != 0) {
    ParseOperand__RemoveDirectIndex(*parseOperand1);
  }
  return argsConsumed;
}

/* TPPStreamCompiler__constructFromOperand @ 0x97bc7354 (1620 bytes) */
int TPPStreamCompiler__constructFromOperand(this, destOperandPtr, argOperands, argCount)
  unsigned char * this;
  unsigned char ** destOperandPtr;
  unsigned char ** argOperands;
  int argCount;
{
  uint argFieldIndex;
  int argNameBufferSize;
  unsigned char *elemOperand;
  unsigned char *operandToFree;
  unsigned char *argFieldOperand;
  unsigned char *childOperand;
  int argStructFieldList;
  int argSymbol;
  int nameBufferSize;
  int fieldNameString;
  int fieldsBegin;
  uint argFieldCount;
  uint elemIndex;
  int destSymbol;
  int structFieldList;
  int length2;
  int length;
  bool noParentName;
  short symbolGlType;
  int *fieldType;
  int argParentName;
  char *allocation;
  unsigned char * childSymbol;
  unsigned char ** argFieldOperands;
  int argFieldNameString;
  int parentNameLength;
  unsigned char * argFieldSymbol;
  unsigned char ** leftoverR4;
  unsigned char ** leftoverR4_00;
  unsigned char ** leftoverR4_01;
  unsigned char ** leftoverR4_02;
  unsigned char ** argCursor;
  uint remainingArgs;
  undefined4 leftoverR7;
  undefined4 leftoverR8;
  unsigned char *destOperand;
  uint scratchR9;
  uint fieldCount;
  uint fieldIndex;
  int argIndex;
  int consumedArgs;
  uint cleanupIndex;
  void *fieldSymbolToFree;
  uint fieldNameChars;
  undefined4 argFieldNameChars;
  undefined8 callResult;
  char indexSuffix [16];
  unsigned char * childOperandSlot;
  unsigned char * elemOperandSlot;
  int parentName;
  int terminatorGlobalBase;
  
  destOperand = *destOperandPtr;
  argIndex = 0;
  consumedArgs = 0;
  if (destOperand != (unsigned char *)0x0) {
    destSymbol = *(int *)destOperand;
    symbolGlType = *(short *)(destSymbol + 0x2c);
    consumedArgs = argIndex;
    if (symbolGlType == 0x7ffe) {
      parentName = *(int *)(destSymbol + 0x14);
      structFieldList = *(int *)(*(int *)(destSymbol + 0xc) + 8);
      if (structFieldList != 0) {
        fieldIndex = 0;
        fieldsBegin = *(int *)(structFieldList + 4);
        fieldCount = *(int *)(structFieldList + 8) - fieldsBegin >> 3;
        if (fieldCount != 0) {
          scratchR9 = 0xa7b7736c;
          noParentName = parentName == 0;
          terminatorGlobalBase = -0x58488c94;
          argCursor = argOperands;
          remainingArgs = argCount;
          while( true ) {
            fieldType = *(int **)(fieldsBegin + fieldIndex * 8);
            fieldNameString = (**(code **)(*fieldType + 0x1c))(fieldType,destOperandPtr,argCursor,remainingArgs,leftoverR7,leftoverR8,scratchR9);
            scratchR9 = *(uint *)(*(int *)(fieldNameString + 4) + -0xc);
            *(undefined1 *)(*(int *)(fieldNameString + 4) + scratchR9) = **(undefined1 **)(terminatorGlobalBase + 0x4a30);
            fieldNameChars = *(uint *)(fieldNameString + 4);
            length = _strlen(fieldNameChars);
            nameBufferSize = length + 1;
            if (!noParentName) {
              length2 = _strlen(parentName);
              nameBufferSize = nameBufferSize + length2 + 1;
            }
            allocation = (char *)_malloc(nameBufferSize);
            if (noParentName) {
              _strcpy(allocation,fieldNameChars);
            }
            else {
              _sprintf(allocation,DAT_a7b7bd8c,parentName,fieldNameChars);
              remainingArgs = fieldNameChars;
            }
            childOperand = operator_new(0x38);
            __ZN12ParseOperandC1Ev(childOperand);
            childOperandSlot = childOperand;
            childSymbol = operator_new(100);
            __ZN11ParseSymbolC1Ev(childSymbol);
            ParseSymbol__SetName(childSymbol,allocation);
            _free(allocation);
            ParseSymbol__SetParseTreeType(childSymbol,*(unsigned char **)(*(int *)(structFieldList + 4) + fieldIndex * 8));
            *(unsigned char **)childOperandSlot = childSymbol;
            if ((*(short *)(childSymbol + 0x2c) == 0x7ffe) || (*(short *)(childSymbol + 0x2c) == 0x7fff)) {
              argCursor = argOperands + consumedArgs;
              argSymbol = *(int *)argOperands[consumedArgs];
              if (*(short *)(argSymbol + 0x2c) == 0x7ffe) {
                argParentName = *(int *)(argSymbol + 0x14);
                argStructFieldList = *(int *)(*(int *)(argSymbol + 0xc) + 8);
                destOperandPtr = leftoverR4;
                if (argStructFieldList != 0) {
                  argFieldIndex = 0;
                  argFieldCount = *(int *)(argStructFieldList + 8) - *(int *)(argStructFieldList + 4) >> 3;
                  argFieldOperands = (unsigned char **)_malloc(fieldCount << 2);
                  if (argFieldCount != 0) {
                    do {
                      fieldType = *(int **)(*(int *)(argStructFieldList + 4) + argFieldIndex * 8);
                      argFieldNameString = (**(code **)(*fieldType + 0x1c))(fieldType);
                      scratchR9 = (uint)*DAT_a7b7bd9c;
                      *(byte *)(*(int *)(argFieldNameString + 4) + *(int *)(*(int *)(argFieldNameString + 4) + -0xc)) =
                           *DAT_a7b7bd9c;
                      argFieldNameChars = *(undefined4 *)(argFieldNameString + 4);
                      argNameBufferSize = _strlen(argFieldNameChars);
                      argNameBufferSize = argNameBufferSize + 1;
                      if (argParentName != 0) {
                        parentNameLength = _strlen(argParentName);
                        argNameBufferSize = argNameBufferSize + parentNameLength + 1;
                      }
                      allocation = (char *)_malloc(argNameBufferSize);
                      if (argParentName == 0) {
                        _strcpy(allocation,argFieldNameChars);
                      }
                      else {
                        _sprintf(allocation,DAT_a7b7bd8c,argParentName,argFieldNameChars);
                      }
                      argFieldOperand = operator_new(0x38);
                      __ZN12ParseOperandC1Ev(argFieldOperand);
                      argFieldOperands[argFieldIndex] = argFieldOperand;
                      argFieldSymbol = operator_new(100);
                      __ZN11ParseSymbolC1Ev(argFieldSymbol);
                      ParseSymbol__SetName(argFieldSymbol,allocation);
                      _free(allocation);
                      ParseSymbol__SetParseTreeType
                                (argFieldSymbol,*(unsigned char **)(*(int *)(argStructFieldList + 4) + argFieldIndex * 8));
                      *(unsigned char **)argFieldOperands[argFieldIndex] = argFieldSymbol;
                      if ((*(short *)(argFieldSymbol + 0x2c) != 0x7ffe) &&
                         (*(short *)(argFieldSymbol + 0x2c) != 0x7fff)) {
                        ParseSymbolTable__processOperand
                                  (*(unsigned char **)(this + 0x68),argFieldOperands[argFieldIndex]);
                      }
                      argFieldIndex = argFieldIndex + 1;
                    } while (argFieldIndex < argFieldCount);
                  }
                  cleanupIndex = 0;
                  argCursor = argFieldOperands;
                  remainingArgs = argFieldCount;
                  ((int (*)())TPPStreamCompiler__constructFromOperand)(this,&childOperandSlot,argFieldOperands,argFieldCount);
                  consumedArgs = consumedArgs + 1;
                  if (argFieldCount != 0) {
                    do {
                      fieldSymbolToFree = *(void **)argFieldOperands[cleanupIndex];
                      if (((*(short *)((int)fieldSymbolToFree + 0x2c) == 0x7ffe) ||
                          (*(short *)((int)fieldSymbolToFree + 0x2c) == 0x7fff)) && (fieldSymbolToFree != (void *)0x0))
                      {
                        __ZN11ParseSymbolD1Ev(fieldSymbolToFree);
                        __ZdlPv(fieldSymbolToFree);
                      }
                      operandToFree = argFieldOperands[cleanupIndex];
                      if (operandToFree != (unsigned char *)0x0) {
                        __ZN12ParseOperandD1Ev(operandToFree);
                        __ZdlPv(operandToFree);
                      }
                      cleanupIndex = cleanupIndex + 1;
                    } while (cleanupIndex < argFieldCount);
                  }
                  _free(argFieldOperands);
                  destOperandPtr = leftoverR4_00;
                }
              }
              else {
                remainingArgs = argCount - consumedArgs;
                callResult = ((int (*)())TPPStreamCompiler__constructFromOperand)(this,&childOperandSlot,argCursor,remainingArgs);
                destOperandPtr = (unsigned char **)callResult;
                consumedArgs = consumedArgs + (int)((ulonglong)callResult >> 0x20);
              }
              if (childSymbol != (unsigned char *)0x0) {
                __ZN11ParseSymbolD1Ev(childSymbol);
                __ZdlPv(childSymbol);
                destOperandPtr = leftoverR4_01;
              }
              *(undefined4 *)childOperandSlot = 0;
            }
            else {
              ParseSymbolTable__processOperand(*(unsigned char **)(this + 0x68),childOperandSlot);
              remainingArgs = argCount - consumedArgs;
              argCursor = argOperands + consumedArgs;
              callResult = ((int (*)())TPPStreamCompiler__constructFromOperand)(this,&childOperandSlot,argCursor,remainingArgs);
              destOperandPtr = (unsigned char **)callResult;
              consumedArgs = consumedArgs + (int)((ulonglong)callResult >> 0x20);
            }
            operandToFree = childOperandSlot;
            if (childOperandSlot != (unsigned char *)0x0) {
              __ZN12ParseOperandD1Ev(childOperandSlot);
              __ZdlPv(operandToFree);
              destOperandPtr = leftoverR4_02;
            }
            fieldIndex = fieldIndex + 1;
            if (fieldCount <= fieldIndex) break;
            fieldsBegin = *(int *)(structFieldList + 4);
          }
        }
      }
    }
    else if (symbolGlType == 0x7fff) {
      elemIndex = 0;
      if (0 < *(short *)(destSymbol + 0x2e)) {
        do {
          elemOperand = operator_new(0x38);
          __ZN12ParseOperandC1Ev(elemOperand);
          elemOperandSlot = elemOperand;
          childSymbol = operator_new(100);
          __ZN11ParseSymbolC1Ev(childSymbol);
          ParseSymbol__SetName(childSymbol,*(char **)(*(int *)*destOperandPtr + 0x14));
          ParseSymbol__AddDirectIndex(childSymbol,elemIndex);
          _sprintf(indexSuffix,DAT_a7b7bd90,elemIndex);
          ParseSymbol__CatName(childSymbol,indexSuffix);
          ParseSymbol__SetParseTreeType(childSymbol,*(unsigned char **)(*(int *)*destOperandPtr + 0xc));
          *(undefined4 *)(childSymbol + 0x48) = 1;
          ParseSymbol__ResolveOpenGLType(childSymbol);
          *(unsigned char **)elemOperandSlot = childSymbol;
          if ((*(short *)(childSymbol + 0x2c) == 0x7ffe) || (*(short *)(childSymbol + 0x2c) == 0x7fff)) {
            consumedArgs = ((int (*)())TPPStreamCompiler__constructFromOperand)(this,&elemOperandSlot,argOperands + argIndex,argCount - argIndex);
            if (childSymbol != (unsigned char *)0x0) {
              __ZN11ParseSymbolD1Ev(childSymbol);
              __ZdlPv(childSymbol);
            }
            *(undefined4 *)elemOperandSlot = 0;
          }
          else {
            ParseSymbolTable__processOperand(*(unsigned char **)(this + 0x68),elemOperandSlot);
            consumedArgs = ((int (*)())TPPStreamCompiler__constructFromOperand)(this,&elemOperandSlot,argOperands + argIndex,argCount - argIndex);
          }
          operandToFree = elemOperandSlot;
          consumedArgs = argIndex + consumedArgs;
          if (elemOperandSlot != (unsigned char *)0x0) {
            __ZN12ParseOperandD1Ev(elemOperandSlot);
            __ZdlPv(operandToFree);
          }
          elemIndex = elemIndex + 1;
          argIndex = consumedArgs;
        } while ((int)elemIndex < (int)*(short *)(*(int *)*destOperandPtr + 0x2e));
      }
    }
    else {
      if (destSymbol == 0) {
        symbolGlType = *(short *)(destOperand + 0x18);
      }
      switch(symbolGlType) {
      case -0x74b0:
      case -0x74af:
      case -0x74ae:
      case -0x74ad:
      case -0x74ac:
      case -0x74ab:
      case -0x74a9:
      case -0x74a8:
      case -0x74a7:
        if ((argCount == 1) && (consumedArgs = ParseOperand__GetLogicalSize(*argOperands), consumedArgs == 1)) {
          consumedArgs = ((int (*)())TPPStreamCompiler__constructReplicate)((unsigned char **)this,destOperandPtr,(int)argOperands,1);
          return consumedArgs;
        }
        break;
      case -0x74a6:
      case -0x74a5:
      case -0x74a4:
        if ((argCount == 1) && (consumedArgs = ParseOperand__GetLogicalSize(*argOperands), consumedArgs == 1)) {
          consumedArgs = ((int (*)())TPPStreamCompiler__constructDiagonal)((unsigned char **)this,destOperandPtr,(int)argOperands,1);
          return consumedArgs;
        }
      }
      consumedArgs = ((int (*)())TPPStreamCompiler__constructElement)(this,destOperandPtr,argOperands,argCount);
    }
  }
  return consumedArgs;
}

/* TPPStreamCompiler__construct @ 0x97bc79dc (296 bytes) */
int TPPStreamCompiler__construct(this, type, argOperands, argCount)
  unsigned char * this;
  unsigned char * type;
  unsigned char ** argOperands;
  int argCount;
{
  int resultColumnCount;
  int argLogicalSize;
  int argIsMatrix;
  int resultIsMatrix;
  int resultLogicalSize;
  bool argMatchesResult;
  short resultGlType;
  short argGlType;
  unsigned char * discardedTemp;
  int argSymbol;
  int argLogicalSizeCheck;
  unsigned char * resultOperandSlots [7];
  
  resultOperandSlots[0] = (unsigned char *)((int (*)())TPPStreamCompiler__newTemporary)(this,type);
  if (argCount == 1) {
    if (*(int *)resultOperandSlots[0] == 0) {
      resultGlType = *(short *)(resultOperandSlots[0] + 0x18);
    }
    else {
      resultGlType = *(short *)(*(int *)resultOperandSlots[0] + 0x2c);
    }
    argSymbol = *(int *)*argOperands;
    if (argSymbol == 0) {
      argGlType = *(short *)(*argOperands + 0x18);
    }
    else {
      argGlType = *(short *)(argSymbol + 0x2c);
    }
    if (resultGlType == argGlType) {
      resultLogicalSize = ParseOperand__GetLogicalSize(resultOperandSlots[0]);
      argLogicalSizeCheck = ParseOperand__GetLogicalSize(*argOperands);
      if (resultLogicalSize == argLogicalSizeCheck) {
        resultColumnCount = 1;
        resultIsMatrix = ParseOperand__IsMatrix(resultOperandSlots[0]);
        if (resultIsMatrix != 0) {
          resultColumnCount = ParseOperand__GetLogicalSize(resultOperandSlots[0]);
        }
        argIsMatrix = ParseOperand__IsMatrix(*argOperands);
        if ((argIsMatrix == 0) || (*(int *)(*argOperands + 0x20) != 0)) {
          argMatchesResult = resultColumnCount == 1;
        }
        else {
          argLogicalSize = ParseOperand__GetLogicalSize(*argOperands);
          argMatchesResult = resultColumnCount == argLogicalSize;
        }
        discardedTemp = resultOperandSlots[0];
        if (argMatchesResult) {
          if (resultOperandSlots[0] != (unsigned char *)0x0) {
            __ZN12ParseOperandD1Ev(resultOperandSlots[0]);
            __ZdlPv(discardedTemp);
          }
          return *argOperands;
        }
      }
    }
  }
  ((int (*)())TPPStreamCompiler__constructFromOperand)(this,resultOperandSlots,argOperands,argCount);
  return resultOperandSlots[0];
}

/* TPPStreamCompiler__FinishScalerSelect @ 0x97bc7b04 (464 bytes) */
int TPPStreamCompiler__FinishScalerSelect(this, destOperandPtr)
  unsigned char * this;
  unsigned char ** destOperandPtr;
{
  int pendingLogicalSize;
  int pendingSymbol;
  ushort pendingGlType;
  uint streamType;
  unsigned char ** pendingIndexSlotPtr;
  undefined4 leftoverR7;
  undefined4 leftoverR8;
  int pendingOperand;
  undefined4 recordLine;
  undefined4 leftoverR10;
  unsigned char * operandToFree;
  uint opHeader;
  uint opFlags;
  uint opDest0;
  undefined4 opDest1;
  uint opSrc0A;
  undefined4 opSrc0B;
  uint opSrc1A;
  undefined4 opSrc1B;
  undefined4 opSrc2A;
  undefined4 opSrc2B;
  undefined4 opAuxA;
  undefined4 opAuxB;
  undefined4 opLine;
  undefined4 opWord13;
  uint operandDescA;
  undefined4 operandDescB;
  unsigned char * pendingIndexSlots [4];
  
  pendingOperand = *(int *)(this + 0x88);
  if (pendingOperand != 0) {
    pendingIndexSlots[0] = *(unsigned char **)(pendingOperand + 0xc);
    *(undefined4 *)(pendingOperand + 0xc) = 0;
    pendingIndexSlotPtr = pendingIndexSlots;
    recordLine = *(undefined4 *)(this + 0x90);
    opWord13 = 0;
    opHeader = 0x40000000;
    opFlags = 0;
    opDest0 = 0;
    opDest1 = 0;
    opSrc0A = 0;
    opSrc0B = 0;
    opSrc1A = 0;
    opSrc1B = 0;
    opSrc2A = 0;
    opSrc2B = 0;
    opAuxA = 0;
    opAuxB = 0;
    opLine = recordLine;
    ((int (*)())__ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_S2_)(this,(unsigned char **)(this + 0x88),destOperandPtr,pendingIndexSlotPtr);
    opHeader = opHeader & 0xfc03ffff | 0x1b40000;
    ParseOperand__RemoveDirectIndex(*(unsigned char **)(this + 0x88));
    ((int (*)())TPPStreamCompiler__getOperandAsDestVar)((unsigned char *)&operandDescA,this,*(undefined4 *)(this + 0x88),pendingIndexSlotPtr,leftoverR7,
                        leftoverR8);
    opDest0 = operandDescA;
    opDest1 = operandDescB;
    ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&operandDescA,this,*destOperandPtr,pendingIndexSlotPtr,leftoverR7,leftoverR8,recordLine,leftoverR10);
    opSrc0A = operandDescA;
    opSrc0B = operandDescB;
    ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&operandDescA,this,pendingIndexSlots[0],pendingIndexSlotPtr,leftoverR7,leftoverR8,recordLine,leftoverR10);
    opFlags = (opDest0 >> 0xc & 1) << 0x1c | opFlags & 0xefffffff;
    opSrc1A = operandDescA;
    opSrc1B = operandDescB;
    pendingSymbol = **(int **)(this + 0x88);
    if (pendingSymbol == 0) {
      pendingGlType = *(ushort *)(*(int **)(this + 0x88) + 6);
    }
    else {
      pendingGlType = *(ushort *)(pendingSymbol + 0x2c);
    }
    streamType = GetPPStreamTypeForGLType((uint)pendingGlType);
    opFlags = (streamType & 7) << 0x17 | opFlags & 0xfc7fffff;
    pendingLogicalSize = ParseOperand__GetLogicalSize(*(unsigned char **)(this + 0x88));
    opFlags = (pendingLogicalSize + -1) * 0x4000000 & 0xc000000U | opFlags & 0xf3f3ffff;
    _PPStreamAddOperation(*(undefined4 *)(this + 0x70),&opHeader,0,0);
    operandToFree = *destOperandPtr;
    if (operandToFree != (unsigned char *)0x0) {
      __ZN12ParseOperandD1Ev(operandToFree);
      __ZdlPv(operandToFree);
    }
    operandToFree = pendingIndexSlots[0];
    if (pendingIndexSlots[0] != (unsigned char *)0x0) {
      __ZN12ParseOperandD1Ev(pendingIndexSlots[0]);
      __ZdlPv(operandToFree);
    }
    *destOperandPtr = *(unsigned char **)(this + 0x88);
    *(undefined4 *)(this + 0x88) = 0;
  }
  return;
}

/* TPPStreamCompiler__LastOperationIndex @ 0x97bc7cd4 (36 bytes) */
int TPPStreamCompiler__LastOperationIndex(this)
  unsigned char * this;
{
  int lastOperationChunk;
  
  lastOperationChunk = *(int *)(*(int *)(*(int *)(this + 0x70) + 0x20) + 4);
  if (lastOperationChunk == 0) {
    return 0xffffffff;
  }
  return *(uint *)(lastOperationChunk + 0xc) & 0x3ffff;
}

/* TPPStreamCompiler__AddOperation @ 0x97bc7cf8 (100 bytes) */
int TPPStreamCompiler__AddOperation(this, destOperandPtr, operation, labelText, labelLength)
  unsigned char * this;
  unsigned char ** destOperandPtr;
  unsigned char * operation;
  char *labelText;
  uint labelLength;
{
  _PPStreamAddOperation(*(undefined4 *)(this + 0x70),operation,labelText,labelLength);
  if (destOperandPtr != (unsigned char **)0x0) {
    ((int (*)())TPPStreamCompiler__FinishScalerSelect)(this,destOperandPtr);
    return;
  }
  return;
}

/* __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandi @ 0x97bc7d5c (952 bytes) */
int __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandi(this, operands, operandCount)
  void *this;
  unsigned char ** operands;
  int operandCount;
{
  int aliasScanRemaining;
  int firstIndirectScanIndex;
  int aliasScanIndex;
  int indirectOperandIndex;
  unsigned char ** firstIndirectScanCursor;
  unsigned char ** aliasScanCursor;
  unsigned char * operandToFree;
  unsigned char * offsetOperandOrig;
  unsigned char * firstOperandTemp;
  ushort tempGlType;
  bool operandAliased;
  unsigned char * firstOperand;
  unsigned char ** offsetOperandSlotPtr;
  unsigned char * operandType;
  uint tempStreamType;
  int tempLogicalSize;
  undefined4 leftoverR7;
  undefined4 leftoverR8;
  undefined4 recordLine;
  undefined4 leftoverR10;
  int aliasScanIndex2;
  int operandIndex;
  uint opHeader;
  uint opFlags;
  uint opDest0;
  undefined4 opDest1;
  uint opSrc0A;
  undefined4 opSrc0B;
  uint opSrc1A;
  undefined4 opSrc1B;
  undefined4 opSrc2A;
  undefined4 opSrc2B;
  undefined4 opAuxA;
  undefined4 opAuxB;
  undefined4 opLine;
  undefined4 opWord13;
  uint operandDescA;
  undefined4 operandDescB;
  unsigned char * tempOperand;
  unsigned char * offsetOperand;
  unsigned char * tempOperandSlot [5];
  
  firstOperand = *operands;
  if ((firstOperand != (unsigned char *)0x0) && (*(int *)(firstOperand + 0xc) != 0)) {
    *(unsigned char **)((int)this + 0x88) = firstOperand;
    operandType = (unsigned char *)((int (*)())TPPStreamCompiler__newNodeFromOperand)(this,*operands);
    firstOperandTemp = (unsigned char *)((int (*)())TPPStreamCompiler__newTemporary)(this,operandType);
    *operands = firstOperandTemp;
  }
  operandIndex = 1;
  if (1 < operandCount) {
    do {
      offsetOperandOrig = *(unsigned char **)(operands[operandIndex] + 0xc);
      if (offsetOperandOrig != (unsigned char *)0x0) {
        *(undefined4 *)(operands[operandIndex] + 0xc) = 0;
        opFlags = 0;
        recordLine = *(undefined4 *)((int)this + 0x90);
        opHeader = 0x40000000;
        opDest0 = 0;
        opDest1 = 0;
        opSrc0A = 0;
        opSrc0B = 0;
        opSrc1A = 0;
        opSrc1B = 0;
        opSrc2A = 0;
        opSrc2B = 0;
        opAuxA = 0;
        opAuxB = 0;
        opWord13 = 0;
        opLine = recordLine;
        offsetOperand = offsetOperandOrig;
        operandType = (unsigned char *)((int (*)())TPPStreamCompiler__newNodeFromOperand)(this,operands[operandIndex]);
        tempOperand = (unsigned char *)((int (*)())TPPStreamCompiler__newTemporary)(this,operandType);
        offsetOperandSlotPtr = &offsetOperand;
        ((int (*)())__ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_S2_)(this,&tempOperand,operands + operandIndex,offsetOperandSlotPtr);
        opHeader = opHeader & 0xfc03ffff | 0xe40000;
        ((int (*)())TPPStreamCompiler__getOperandAsDestVar)((unsigned char *)&operandDescA,this,tempOperand,offsetOperandSlotPtr,leftoverR7,leftoverR8);
        opDest0 = operandDescA;
        opDest1 = operandDescB;
        ParseOperand__RemoveDirectIndex(operands[operandIndex]);
        ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&operandDescA,this,operands[operandIndex],offsetOperandSlotPtr,leftoverR7,leftoverR8,recordLine,leftoverR10);
        opSrc0A = operandDescA;
        opSrc0B = operandDescB;
        ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&operandDescA,this,offsetOperand,offsetOperandSlotPtr,leftoverR7,leftoverR8,recordLine,leftoverR10);
        opFlags = (opDest0 >> 0xc & 1) << 0x1c | opFlags & 0xefffffff;
        opSrc1A = operandDescA;
        opSrc1B = operandDescB;
        if (*(int *)tempOperand == 0) {
          tempGlType = *(ushort *)(tempOperand + 0x18);
        }
        else {
          tempGlType = *(ushort *)(*(int *)tempOperand + 0x2c);
        }
        tempStreamType = GetPPStreamTypeForGLType((uint)tempGlType);
        opFlags = (tempStreamType & 7) << 0x17 | opFlags & 0xfc7fffff;
        tempLogicalSize = ParseOperand__GetLogicalSize(tempOperand);
        opFlags = (tempLogicalSize + -1) * 0x4000000 & 0xc000000U | opFlags & 0xf3f3ffff;
        _PPStreamAddOperation(*(undefined4 *)((int)this + 0x70),&opHeader,0,0);
        aliasScanIndex = 0;
        aliasScanCursor = operands;
        if (0 < operandCount) {
          do {
            if ((aliasScanIndex != operandIndex) && (operands[operandIndex] == *aliasScanCursor)) {
              *(unsigned char **)(operands[operandIndex] + 0xc) = offsetOperand;
              goto storeOperands;
            }
            aliasScanIndex = aliasScanIndex + 1;
            aliasScanCursor = aliasScanCursor + 1;
          } while (aliasScanIndex < operandCount);
        }
        operandToFree = operands[operandIndex];
        if (operandToFree != (unsigned char *)0x0) {
          __ZN12ParseOperandD1Ev(operandToFree);
          __ZdlPv(operandToFree);
        }
        operandToFree = offsetOperand;
        if (offsetOperand != (unsigned char *)0x0) {
          __ZN12ParseOperandD1Ev(offsetOperand);
          __ZdlPv(operandToFree);
        }
storeOperands:
        operands[operandIndex] = tempOperand;
      }
      operandIndex = operandIndex + 1;
    } while (operandIndex < operandCount);
  }
  firstIndirectScanCursor = operands;
  indirectOperandIndex = operandCount;
  firstIndirectScanIndex = 0;
  if (0 < operandCount) {
    do {
      indirectOperandIndex = firstIndirectScanIndex;
      if ((*firstIndirectScanCursor != (unsigned char *)0x0) && (*(int *)(*firstIndirectScanCursor + 8) != 0)) break;
      firstIndirectScanIndex = indirectOperandIndex + 1;
      firstIndirectScanCursor = firstIndirectScanCursor + 1;
      indirectOperandIndex = operandCount;
    } while (firstIndirectScanIndex < operandCount);
  }
  indirectOperandIndex = indirectOperandIndex + *(int *)((int)this + 0x9c);
  do {
    if (operandCount <= indirectOperandIndex) {
      return;
    }
    if (*(int *)(operands[indirectOperandIndex] + 8) != 0) {
      operandType = (unsigned char *)((int (*)())TPPStreamCompiler__newNodeFromOperand)(this,operands[indirectOperandIndex]);
      tempOperandSlot[0] = (unsigned char *)((int (*)())TPPStreamCompiler__newTemporary)(this,operandType);
      operandAliased = false;
      ((int (*)())TPPStreamCompiler__assignOperands)(this,tempOperandSlot,operands + indirectOperandIndex,0);
      aliasScanIndex2 = 0;
      aliasScanCursor = operands;
      aliasScanRemaining = operandCount;
      if (operandCount < 1) {
loopSetOperandToFree:
        operandToFree = operands[indirectOperandIndex];
        if (operandToFree != (unsigned char *)0x0) {
          __ZN12ParseOperandD1Ev(operandToFree);
          __ZdlPv(operandToFree);
        }
      }
      else {
        do {
          if ((aliasScanIndex2 != indirectOperandIndex) && (operands[indirectOperandIndex] == *aliasScanCursor)) {
            operandAliased = true;
          }
          aliasScanIndex2 = aliasScanIndex2 + 1;
          aliasScanRemaining = aliasScanRemaining + -1;
          aliasScanCursor = aliasScanCursor + 1;
        } while (aliasScanRemaining != 0);
        if (!operandAliased) goto loopSetOperandToFree;
      }
      operands[indirectOperandIndex] = tempOperandSlot[0];
    }
    indirectOperandIndex = indirectOperandIndex + 1;
  } while( true );
}

/* __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_ @ 0x97bc8114 (88 bytes) */
int __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_(this, operandAPtr, operandBPtr)
  void *this;
  unsigned char ** operandAPtr;
  unsigned char ** operandBPtr;
{
  unsigned char * operandCopy0;
  unsigned char * operandCopy1;
  
  operandCopy0 = *operandAPtr;
  operandCopy1 = *operandBPtr;
  ((int (*)())__ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandi)(this,&operandCopy0,2);
  *operandAPtr = operandCopy0;
  *operandBPtr = operandCopy1;
  return;
}

/* __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_S2_ @ 0x97bc816c (108 bytes) */
int __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_S2_(this, parseOperand1, parseOperand2, parseOperand3)
  void *this;
  unsigned char ** parseOperand1;
  unsigned char ** parseOperand2;
  unsigned char ** parseOperand3;
{
  unsigned char * operandCopy0;
  unsigned char * operandCopy1;
  unsigned char * operandCopy2;
  
  operandCopy0 = *parseOperand1;
  operandCopy1 = *parseOperand2;
  operandCopy2 = *parseOperand3;
  ((int (*)())__ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandi)(this,&operandCopy0,3);
  *parseOperand1 = operandCopy0;
  *parseOperand2 = operandCopy1;
  *parseOperand3 = operandCopy2;
  return;
}

/* __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_S2_S2_ @ 0x97bc81d8 (128 bytes) */
int __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_S2_S2_(this, parseOperand1, parseOperand2, parseOperand3, parseOperand4)
  void *this;
  unsigned char ** parseOperand1;
  unsigned char ** parseOperand2;
  unsigned char ** parseOperand3;
  unsigned char ** parseOperand4;
{
  unsigned char * operandCopy0;
  unsigned char * operandCopy1;
  unsigned char * operandCopy2;
  unsigned char * operandCopy3;
  
  operandCopy0 = *parseOperand1;
  operandCopy1 = *parseOperand2;
  operandCopy2 = *parseOperand3;
  operandCopy3 = *parseOperand4;
  ((int (*)())__ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandi)(this,&operandCopy0,4);
  *parseOperand1 = operandCopy0;
  *parseOperand2 = operandCopy1;
  *parseOperand3 = operandCopy2;
  *parseOperand4 = operandCopy3;
  return;
}

/* __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_i @ 0x97bc8258 (188 bytes) */
int __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_i(this, parseOperand1, parseOperand2, extraOperandCount)
  void *this;
  unsigned char ** parseOperand1;
  unsigned char ** parseOperand2;
  int extraOperandCount;
{
  int remainingCount;
  unsigned char ** copyCursor;
  int allocaAdjust;
  unsigned char ** extraOperandCursor;
  unsigned char ** operandCopies;
  unsigned char * allocaBase [2];
  
  allocaAdjust = -(extraOperandCount * 4 + 0x22U & 0xfffffff0);
  *(unsigned char **)(&STACKARG(0xffffffa0) + allocaAdjust) = ((unsigned int)__builtin_frame_address(0));
  operandCopies = (unsigned char **)((int)allocaBase + allocaAdjust);
  *operandCopies = *parseOperand1;
  extraOperandCursor = parseOperand2;
  remainingCount = extraOperandCount;
  copyCursor = operandCopies;
  if (0 < extraOperandCount) {
    do {
      copyCursor[1] = *extraOperandCursor;
      remainingCount = remainingCount + -1;
      extraOperandCursor = extraOperandCursor + 1;
      copyCursor = copyCursor + 1;
    } while (remainingCount != 0);
  }
  ((int (*)())__ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandi)(this,operandCopies,extraOperandCount + 1);
  *parseOperand1 = *operandCopies;
  if (0 < extraOperandCount) {
    do {
      operandCopies = operandCopies + 1;
      *parseOperand2 = *operandCopies;
      parseOperand2 = parseOperand2 + 1;
      extraOperandCount = extraOperandCount + -1;
    } while (extraOperandCount != 0);
  }
  return;
}

/* TPPStreamCompiler__getNewConstantSourceVar @ 0x97bc8314 (472 bytes) */
int TPPStreamCompiler__getNewConstantSourceVar(outDesc, compiler, values, valueCount, glType)
  unsigned char * outDesc;
  uint compiler;
  int values;
  int valueCount;
  undefined4 glType;
{
  int valueIndex;
  undefined4 constantWord;
  undefined2 newConstantIndex;
  uint chunkClassBits;
  uint constantIndex;
  uint streamType;
  undefined1 *allocation;
  undefined4 *laneFlagCursor;
  undefined4 constantChunkList;
  int constantList;
  undefined4 constantValues [4];
  undefined4 chunkWord0;
  uint chunkWord1;
  undefined4 laneUsedFlags [5];
  
  constantList = *(int *)(*(int *)(compiler + 0x70) + 0x2c);
  constantChunkList = *(undefined4 *)(*(int *)(compiler + 0x70) + 0x10);
  constantValues[0] = 0;
  constantValues[1] = 0;
  constantValues[2] = 0;
  constantValues[3] = 0;
  chunkWord1 = *(uint *)(*(int *)(compiler + 0x68) + 0x24);
  *(uint *)(*(int *)(compiler + 0x68) + 0x24) = chunkWord1 + 1;
  chunkWord0 = 0x110000;
  chunkWord1 = chunkWord1 & 0xffff;
  streamType = GetPPStreamTypeForGLType(glType);
  constantIndex = chunkWord1;
  chunkClassBits = (uint)chunkWord0 >> 0x10;
  newConstantIndex = *(undefined2 *)(constantList + 10);
  *(undefined4 *)outDesc = 0;
  *(undefined4 *)(outDesc + 4) = 0;
  *(short *)(outDesc + 6) = (short)chunkWord1;
  *(uint *)outDesc = (valueCount + -1) * 0x1000 & 0x3000U | *(uint *)outDesc & 0xf409cfff | 0x10d8000;
  chunkWord0 = CONCAT22((ushort)((uint)((valueCount + -1) * 0x1000000) >> 0x10) & 0x300 |
                      (ushort)(((streamType & 7) << 0x1a) >> 0x10) | (ushort)chunkClassBits & 0xff,newConstantIndex);
  if (*(int *)(compiler + 0xc4) == 3) {
    laneUsedFlags[3] = 0;
    laneUsedFlags[0] = 0;
    laneUsedFlags[1] = 0;
    laneUsedFlags[2] = 0;
    if (valueCount != 0) {
      laneFlagCursor = laneUsedFlags;
      valueIndex = 0;
      do {
        constantWord = *(undefined4 *)(values + valueIndex * 4);
        *laneFlagCursor = 1;
        laneFlagCursor = laneFlagCursor + 1;
        constantValues[valueIndex] = constantWord;
        valueCount = valueCount + -1;
        valueIndex = valueIndex + 1;
      } while (valueCount != 0);
    }
    ConstantAllocationList__addConstant
              ((unsigned char *)(compiler + 0x44),constantIndex & 0xffff,(bool *)laneUsedFlags,
               (ushort)glType);
  }
  else {
    valueIndex = 0;
    for (; valueCount != 0; valueCount = valueCount + -1) {
      constantValues[valueIndex] = *(undefined4 *)(values + valueIndex * 4);
      valueIndex = valueIndex + 1;
    }
  }
  _PPStreamAddConstant(*(undefined4 *)(compiler + 0x70),constantValues);
  allocation = (undefined1 *)_calloc(0x1c,1);
  *allocation = 3;
  *(undefined4 *)(allocation + 0xc) = chunkWord0;
  *(undefined4 *)(allocation + 0x14) = 0;
  *(uint *)(allocation + 0x10) = chunkWord1;
  _PPStreamChunkListAddChunk(constantChunkList,allocation);
  return outDesc;
}

/* TPPStreamCompiler__getConstantAsSourceVar @ 0x97bc84ec (1296 bytes) */
int TPPStreamCompiler__getConstantAsSourceVar(outDesc, compiler, values, valueCount, glType)
  unsigned char * outDesc;
  uint compiler;
  float *values;
  uint valueCount;
  uint glType;
{
  bool exactMatchFound;
  uint xSelector;
  uint lanesLeft;
  int *flagCursor;
  bool noExactMatch;
  int chunk;
  uint loopIndex;
  bool chunkCompatible;
  int laneFilled;
  undefined4 constantList;
  int *chunkList;
  int chunkCursor;
  uint scratchWord0;
  undefined4 scratchWord1;
  int laneUsed [4];
  ushort usageGlTypes [8];
  int mergedLaneFlags [5];
  
  if (*(int *)(compiler + 0xc4) != 1) {
    exactMatchFound = false;
    laneUsed[1] = DAT_97c39254;
    laneUsed[0] = DAT_97c39250;
    laneUsed[2] = DAT_97c39258;
    laneUsed[3] = DAT_97c3925c;
    chunkList = *(int **)(*(int *)(compiler + 0x70) + 0x10);
    constantList = *(undefined4 *)(*(int *)(compiler + 0x70) + 0x2c);
    chunkCursor = *chunkList;
    *(undefined4 *)outDesc = 0;
    *(undefined4 *)(outDesc + 4) = 0;
    *(uint *)outDesc = (valueCount - 1) * 0x1000 & 0x3000 | *(uint *)outDesc & 0xfc09cfff | 0x10d8000;
    if (chunkCursor != 0) {
      do {
        scratchWord0 = *(uint *)(chunkCursor + 0xc);
        scratchWord1 = *(uint *)(chunkCursor + 0x10);
        if ((scratchWord0 & 0x1f0000) == 0x110000) {
          chunk = _PPStreamChunkListChunkAtIndex(constantList,scratchWord0 & 0xffff);
          if (*(int *)(compiler + 0xc4) == 3) {
            ConstantAllocationList__getConstantUsage
                      ((unsigned char *)(compiler + 0x44),scratchWord1 & 0xffff,(bool *)laneUsed
                       ,usageGlTypes);
          }
          if (usageGlTypes[0] == glType) {
            if (valueCount == 2) {
loopCheckLaneUsed:
              if ((laneUsed[1] != 0) && (values[1] == *(float *)(chunk + 0x10))) {
loopCheckLaneUsed2:
                if ((laneUsed[0] != 0) && (*values == *(float *)(chunk + 0xc))) goto setExactMatchFound;
              }
            }
            else {
              if (2 < valueCount) {
                if (valueCount != 3) {
                  if (valueCount != 4) goto setExactMatchFound;
                  if ((laneUsed[3] == 0) || (values[3] != *(float *)(chunk + 0x18)))
                  goto setChunkCursor;
                }
                if ((laneUsed[2] == 0) || (values[2] != *(float *)(chunk + 0x14)))
                goto setChunkCursor;
                goto loopCheckLaneUsed;
              }
              if (valueCount == 1) goto loopCheckLaneUsed2;
setExactMatchFound:
              exactMatchFound = true;
              *(undefined2 *)(outDesc + 6) = (*(unsigned short *)((unsigned char *)&(scratchWord1) + 2));
            }
          }
        }
setChunkCursor:
        chunkCursor = *(int *)(chunkCursor + 8);
        if (chunkCursor == 0) {
          noExactMatch = !exactMatchFound;
          goto checkNoExactMatch;
        }
      } while (!exactMatchFound);
      goto checkValueCount;
    }
    noExactMatch = true;
checkNoExactMatch:
    if (!noExactMatch) goto checkValueCount;
    if (*(int *)(compiler + 0xc4) != 2) {
      chunkCursor = *chunkList;
      if (chunkCursor != 0) {
        do {
          mergedLaneFlags[0] = 0;
          mergedLaneFlags[1] = 0;
          mergedLaneFlags[2] = 0;
          mergedLaneFlags[3] = 0;
          scratchWord0 = *(uint *)(chunkCursor + 0xc);
          scratchWord1 = *(uint *)(chunkCursor + 0x10);
          if ((scratchWord0 & 0x1f0000) == 0x110000) {
            chunk = _PPStreamChunkListChunkAtIndex(constantList,scratchWord0 & 0xffff);
            if (*(int *)(compiler + 0xc4) == 3) {
              ConstantAllocationList__getConstantUsage
                        ((unsigned char *)(compiler + 0x44),scratchWord1 & 0xffff,
                         (bool *)laneUsed,usageGlTypes);
            }
            if (usageGlTypes[0] == glType) {
              chunkCompatible = true;
              if (valueCount == 2) {
loopCheckLaneUsed3:
                if ((laneUsed[1] == 1) && (values[1] == *(float *)(chunk + 0x10))) {
                  mergedLaneFlags[1] = laneUsed[1];
                }
                else if (laneUsed[1] != 0) {
                  chunkCompatible = false;
                }
loopCheckLaneUsed4:
                if ((laneUsed[0] == 1) && (*values == *(float *)(chunk + 0xc))) {
                  mergedLaneFlags[0] = laneUsed[0];
                }
                else if (laneUsed[0] != 0) {
                  chunkCompatible = false;
                }
                if (!chunkCompatible) goto setChunkCursor2;
              }
              else {
                if (2 < valueCount) {
                  if (valueCount != 3) {
                    if (valueCount != 4) goto setLoopIndex;
                    if ((laneUsed[3] == 1) && (values[3] == *(float *)(chunk + 0x18))) {
                      mergedLaneFlags[3] = 1;
                    }
                    else if (laneUsed[3] != 0) {
                      chunkCompatible = false;
                    }
                  }
                  if ((laneUsed[2] == 1) && (values[2] == *(float *)(chunk + 0x14))) {
                    mergedLaneFlags[2] = laneUsed[2];
                  }
                  else if (laneUsed[2] != 0) {
                    chunkCompatible = false;
                  }
                  goto loopCheckLaneUsed3;
                }
                if (valueCount == 1) goto loopCheckLaneUsed4;
              }
setLoopIndex:
              loopIndex = 0;
              if (valueCount != 0) {
                do {
                  if (mergedLaneFlags[loopIndex] == 0) {
                    if (laneUsed[loopIndex] != 0) {
                      chunkCompatible = false;
                      break;
                    }
                    ((float *)(chunk + 0xc))[loopIndex] = values[loopIndex];
                    mergedLaneFlags[loopIndex] = 1;
                    laneUsed[loopIndex] = 1;
                  }
                  loopIndex = loopIndex + 1;
                } while (loopIndex < valueCount);
              }
              if (valueCount != 0) {
                flagCursor = mergedLaneFlags;
                lanesLeft = valueCount;
                do {
                  laneFilled = *flagCursor;
                  flagCursor = flagCursor + 1;
                  if (laneFilled == 0) {
                    chunkCompatible = false;
                  }
                  lanesLeft = lanesLeft - 1;
                } while (lanesLeft != 0);
              }
              if (chunkCompatible) {
                *(undefined2 *)(outDesc + 6) = (*(unsigned short *)((unsigned char *)&(scratchWord1) + 2));
                *(uint *)(chunkCursor + 0xc) =
                     (laneUsed[0] + laneUsed[1] + laneUsed[2] + laneUsed[3] + -1) * 0x1000000 &
                     0x3000000U | *(uint *)(chunkCursor + 0xc) & 0xfcffffff;
                noExactMatch = false;
                ConstantAllocationList__updateConstant
                          ((unsigned char *)(compiler + 0x44),scratchWord1 & 0xffff,
                           (bool *)laneUsed,glType);
              }
            }
          }
setChunkCursor2:
          chunkCursor = *(int *)(chunkCursor + 8);
          if (chunkCursor == 0) goto checkNoExactMatch2;
        } while (noExactMatch);
        goto checkValueCount;
      }
checkNoExactMatch2:
      if (!noExactMatch) goto checkValueCount;
    }
  }
  ((int (*)())TPPStreamCompiler__getNewConstantSourceVar)((unsigned char *)&scratchWord0,compiler,values,valueCount,glType);
  *(uint *)(outDesc + 4) = scratchWord1;
  *(uint *)outDesc = scratchWord0;
checkValueCount:
  if (valueCount == 1) {
    xSelector = *(uint *)outDesc >> 0x15 & 3;
    *(uint *)outDesc = xSelector << 0xf | xSelector << 0x11 | xSelector << 0x13 | *(uint *)outDesc & 0xffe07fff;
  }
  return outDesc;
}

/* TPPStreamCompiler__generateAddressLoad @ 0x97bc89fc (256 bytes) */
int TPPStreamCompiler__generateAddressLoad(this, operand)
  unsigned char * this;
  unsigned char * operand;
{
  undefined4 leftoverR6;
  undefined4 leftoverR7;
  undefined4 leftoverR8;
  void *indexOperand;
  undefined4 opHeader;
  undefined4 opFlags;
  uint opDest0;
  uint opDest1;
  undefined4 opSrc0A;
  undefined4 opSrc0B;
  undefined4 opSrc1A;
  undefined4 opSrc1B;
  undefined4 opSrc2A;
  undefined4 opSrc2B;
  undefined4 opAuxA;
  undefined4 opAuxB;
  undefined4 opLine;
  undefined4 opWord13;
  undefined4 indexDescA;
  undefined4 indexDescB;
  
  indexOperand = *(void **)(operand + 8);
  if (indexOperand != (void *)0x0) {
    opFlags = 0;
    opLine = *(undefined4 *)(this + 0x90);
    opAuxA = 0;
    opAuxB = 0;
    opDest0 = 0;
    opDest1 = 0;
    opSrc0A = 0;
    opSrc0B = 0;
    opSrc1A = 0;
    opSrc1B = 0;
    opSrc2A = 0;
    opSrc2B = 0;
    opHeader = 0x21200000;
    opWord13 = 0;
    ((int (*)())TPPStreamCompiler__getOperandAsSourceVar)((unsigned char *)&indexDescA,this,indexOperand,leftoverR6,leftoverR7,leftoverR8,0,0);
    opDest0 = opDest0 & 0xfff1ffff | 0x82000;
    opSrc0A = indexDescA;
    opSrc0B = indexDescB;
    opDest1 = opDest1 & 0xffff0000;
    _PPStreamAddOperation(*(undefined4 *)(this + 0x70),&opHeader,0,0);
    __ZN12ParseOperandD1Ev(indexOperand);
    __ZdlPv(indexOperand);
    *(undefined4 *)(operand + 8) = 0;
  }
  return indexOperand != (void *)0x0;
}

/* TPPStreamCompiler__getOperandAsDestVar @ 0x97bc8afc (76 bytes) */
int TPPStreamCompiler__getOperandAsDestVar(outDesc, compiler, operand, unusedArg4, unusedArg5, unusedArg6)
  unsigned char * outDesc;
  unsigned char * compiler;
  unsigned char * operand;
  undefined4 unusedArg4;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
{
  undefined4 generateAddressLoadResult;
  
  generateAddressLoadResult = ((int (*)())TPPStreamCompiler__generateAddressLoad)(compiler,operand);
  ParseOperand__GetAsDestVar(outDesc,operand,generateAddressLoadResult);
  return outDesc;
}

/* TPPStreamCompiler__getOperandAsSourceVar @ 0x97bc8b48 (420 bytes) */
int TPPStreamCompiler__getOperandAsSourceVar(outDesc, compiler, operand, unusedArg4, unusedArg5, unusedArg6, unusedArg7, unusedArg8)
  unsigned char * outDesc;
  unsigned char * compiler;
  unsigned char * operand;
  undefined4 unusedArg4;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
  undefined4 unusedArg7;
  undefined4 unusedArg8;
{
  int valueByteOffset;
  undefined4 generateAddressLoadResult;
  undefined4 logicalSize;
  bool isScalarValueType;
  ushort operandGlType;
  undefined4 *zeroCursor;
  uint operandLogicalSize;
  undefined4 leftoverArg7;
  uint laneIndex;
  int zeroCountdown;
  undefined4 constantWords [4];
  undefined4 descA;
  undefined4 descB;
  
  if (*(int *)operand == 0) {
    if (*(int *)(operand + 8) != 0) {
      error(compiler,(char *)0x1,(char *)0x0,_compileErrorString,unusedArg5,unusedArg6,unusedArg7,unusedArg8);
    }
    leftoverArg7 = 4;
    zeroCountdown = 4;
    zeroCursor = constantWords;
    do {
      *zeroCursor = 0;
      zeroCursor = zeroCursor + 1;
      zeroCountdown = zeroCountdown + -1;
    } while (zeroCountdown != 0);
    valueByteOffset = 0;
    for (laneIndex = 0; operandLogicalSize = ParseOperand__GetLogicalSize(operand), laneIndex < operandLogicalSize; laneIndex = laneIndex + 1)
    {
      if (laneIndex < 4) {
        if (*(int *)operand == 0) {
          operandGlType = *(ushort *)(operand + 0x18);
        }
        else {
          operandGlType = *(ushort *)(*(int *)operand + 0x2c);
        }
        if (operandGlType == 0x1406) {
          *(undefined4 *)(valueByteOffset + (int)constantWords) = *(undefined4 *)(valueByteOffset + *(int *)(operand + 4));
        }
        else {
          if (operandGlType < 0x1407) {
            isScalarValueType = operandGlType == 0x1404;
          }
          else {
            isScalarValueType = operandGlType == 0x8b56;
          }
          if (isScalarValueType) {
            *(undefined4 *)(valueByteOffset + (int)constantWords) = *(undefined4 *)(valueByteOffset + *(int *)(operand + 4));
          }
        }
      }
      else {
        error(compiler,(char *)0x1,(char *)0x0,DAT_a7b7bd14,unusedArg5,unusedArg6,leftoverArg7,unusedArg8);
      }
      valueByteOffset = valueByteOffset + 4;
    }
    logicalSize = ParseOperand__GetLogicalSize(operand);
    if (*(int *)operand == 0) {
      operandGlType = *(ushort *)(operand + 0x18);
    }
    else {
      operandGlType = *(ushort *)(*(int *)operand + 0x2c);
    }
    ((int (*)())TPPStreamCompiler__getConstantAsSourceVar)((unsigned char *)&descA,(uint)compiler,constantWords,logicalSize,(uint)operandGlType);
  }
  else {
    generateAddressLoadResult = ((int (*)())TPPStreamCompiler__generateAddressLoad)(compiler,operand);
    ParseOperand__GetAsSourceVar(constantWords,operand,generateAddressLoadResult);
    descA = constantWords[0];
    descB = constantWords[1];
  }
  *(undefined4 *)outDesc = descA;
  *(undefined4 *)(outDesc + 4) = descB;
  return outDesc;
}

/* TPPStreamCompiler__removeOrphanedCompilerTemp @ 0x97bc8cec (544 bytes) */
int TPPStreamCompiler__removeOrphanedCompilerTemp(this, operation, tempOperand)
  unsigned char * this;
  unsigned char * operation;
  unsigned char * tempOperand;
{
  uint removedCount;
  uint chunkCount;
  int chunkList;
  int removeResult;
  byte chunkKind;
  ushort symbolGlType;
  bool stillReferenced;
  ushort matrixBaseGlType;
  uint srcStreamType;
  int opChunkCursor;
  int srcSlotCursor;
  byte *chunk;
  undefined4 *symbol;
  byte *nextChunk;
  uint srcOperandCount;
  
  stillReferenced = false;
  opChunkCursor = **(int **)(*(int *)(this + 0x70) + 0x20);
  if (opChunkCursor != 0) {
    srcStreamType = *(uint *)(operation + 0x10) >> 0x17 & 7;
    while( true ) {
      srcOperandCount = *(uint *)(opChunkCursor + 0xc) >> 0x1d;
      if (srcOperandCount != 0) {
        srcSlotCursor = opChunkCursor + 0x10;
        do {
          if (((*(uint *)(srcSlotCursor + 0xc) >> 0x17 & 7) == srcStreamType) &&
             (*(short *)(srcSlotCursor + 0x12) == *(short *)(operation + 0x16))) {
            stillReferenced = true;
          }
          srcSlotCursor = srcSlotCursor + 8;
          srcOperandCount = srcOperandCount - 1;
        } while (srcOperandCount != 0);
      }
      if (((*(uint *)(opChunkCursor + 0x14) >> 0x11 & 7) == srcStreamType) &&
         (*(short *)(opChunkCursor + 0x1a) == *(short *)(operation + 0x16))) {
        stillReferenced = true;
      }
      opChunkCursor = *(int *)(opChunkCursor + 8);
      if (opChunkCursor == 0) break;
      if (stillReferenced) {
        return;
      }
    }
  }
  if (stillReferenced) {
    return;
  }
  removeResult = ParseSymbolTable__RemoveEndSymbol
                    (*(unsigned char **)(this + 0x68),*(unsigned char **)tempOperand);
  if (removeResult == 0) {
    return;
  }
  symbol = *(undefined4 **)tempOperand;
  chunkCount = 3;
  symbolGlType = *(ushort *)(symbol + 0xb);
  chunk = (byte *)*symbol;
  if (symbolGlType != 0x8b5b) {
    if (symbolGlType < 0x8b5c) {
      chunkCount = 2;
      matrixBaseGlType = 0x8b5a;
    }
    else {
      chunkCount = 4;
      matrixBaseGlType = 0x8b5c;
    }
    if (symbolGlType != matrixBaseGlType) {
      chunkCount = 1;
    }
  }
  if (symbol[0xf] != 0) {
    TemporaryAllocator__releaseTemporary
              (*(unsigned char **)(this + 0x60),(uint)*(ushort *)(symbol + 0xb),symbol[10]);
    symbol = *(undefined4 **)tempOperand;
  }
  if (symbol != (undefined4 *)0x0) {
    __ZN11ParseSymbolD1Ev(symbol);
    __ZdlPv(symbol);
  }
  *(undefined4 *)tempOperand = 0;
  chunkKind = *chunk;
  if (chunkKind == 2) {
    chunkList = *(int *)(*(int *)(this + 0x70) + 0x18);
    goto checkChunkList;
  }
  if (chunkKind < 3) {
    if (chunkKind == 0) {
      chunkList = *(int *)(*(int *)(this + 0x70) + 4);
      goto checkChunkList;
    }
  }
  else {
    if (chunkKind == 3) {
      chunkList = *(int *)(*(int *)(this + 0x70) + 0x10);
      goto checkChunkList;
    }
    if (chunkKind == 4) {
      chunkList = *(int *)(*(int *)(this + 0x70) + 0x1c);
      goto checkChunkList;
    }
  }
  chunkList = 0;
checkChunkList:
  if ((chunkList != 0) && (removedCount = 0, chunkCount != 0)) {
    do {
      nextChunk = *(byte **)(chunk + 8);
      if (chunk == (byte *)0x0) {
        return;
      }
      removedCount = removedCount + 1;
      _PPStreamChunkListRemoveChunk(chunkList,chunk);
      chunk = nextChunk;
    } while (removedCount < chunkCount);
  }
  return;
}

/* TPPStreamCompiler__copyPropagateCompilerTemp @ 0x97bc8f0c (1476 bytes) */
int TPPStreamCompiler__copyPropagateCompilerTemp(this, moveOperation, tempOperand)
  unsigned char * this;
  unsigned char * moveOperation;
  unsigned char * tempOperand;
{
  uint maskBitX;
  uint newLaneSel;
  uint srcLane;
  uint movDestA;
  uint defOpcodeBits;
  uint defSrcCount;
  uint defHeader;
  uint *scratchPtrOrWord;
  uint pendingMaskAny;
  uint streamOrLeftover;
  int lanesLeft;
  int defSrcCursor;
  int srcWord;
  int lastLabelChunk;
  int defChunk;
  bool moveUsesRelativeAddressing;
  bool searchEnded;
  uint maskBitY;
  uint maskBitZ;
  uint maskBitW;
  uint laneSelBitsX;
  uint laneSelBitsY;
  uint laneSelBitsZ;
  bool tempReadElsewhere;
  bool rewroteDefinition;
  bool barrierReached;
  int opScanCursor;
  uint movDestAWord;
  int labelScanCursor;
  uint defSrcIndex;
  int tempSymbol;
  unsigned char * srcCursor;
  undefined4 movDestB;
  uint movSrcSwizzleX;
  undefined4 propagated;
  uint movSrcCount;
  uint pendingMaskXYZ [3];
  uint *pendingMaskW;
  uint mergedMaskXYZ [3];
  uint *mergedMaskW;
  uint mergedLaneSel [4];
  uint defLaneSel [4];
  uint defWriteMask [4];
  uint movSrcSwizzle [4];
  uint movDestLaneSel [7];
  
  tempSymbol = *(int *)tempOperand;
  propagated = 0;
  rewroteDefinition = false;
  tempReadElsewhere = false;
  if ((tempSymbol != 0) && ((*(int *)(tempSymbol + 0x3c) != 0 || (*(int *)(tempSymbol + 0x40) != 0)))) {
    movDestAWord = *(uint *)(moveOperation + 8);
    streamOrLeftover = *(uint *)(this + 0x70);
    scratchPtrOrWord = (uint *)(movDestAWord >> 0x10 & 1);
    mergedMaskXYZ[0] = movDestAWord >> 0xd & 1;
    mergedMaskXYZ[1] = movDestAWord >> 0xe & 1;
    mergedMaskXYZ[2] = movDestAWord >> 0xf & 1;
    pendingMaskXYZ[0] = mergedMaskXYZ[0];
    pendingMaskAny = mergedMaskXYZ[0] | mergedMaskXYZ[1] | mergedMaskXYZ[2] | (uint)scratchPtrOrWord;
    pendingMaskXYZ[1] = mergedMaskXYZ[1];
    pendingMaskXYZ[2] = mergedMaskXYZ[2];
    pendingMaskW = scratchPtrOrWord;
    defChunk = 0;
    for (opScanCursor = **(int **)(streamOrLeftover + 0x20); opScanCursor != 0; opScanCursor = *(int *)(opScanCursor + 8)) {
      defChunk = opScanCursor;
    }
    lastLabelChunk = 0;
    for (labelScanCursor = **(int **)(streamOrLeftover + 0x24); labelScanCursor != 0; labelScanCursor = *(int *)(labelScanCursor + 8)) {
      lastLabelChunk = labelScanCursor;
    }
    moveUsesRelativeAddressing = *(int *)(moveOperation + 0xc) < 0;
    movSrcCount = *(uint *)moveOperation >> 0x1d;
    if (movSrcCount != 0) {
      srcCursor = moveOperation + 0x10;
      do {
        srcWord = *(int *)srcCursor;
        srcCursor = srcCursor + 8;
        if (srcWord < 0) {
          moveUsesRelativeAddressing = true;
        }
        movSrcCount = movSrcCount - 1;
      } while (movSrcCount != 0);
    }
    searchEnded = pendingMaskAny == 0;
    mergedMaskW = scratchPtrOrWord;
    if ((!searchEnded) && (defChunk != 0)) {
      barrierReached = searchEnded;
      do {
        if (lastLabelChunk == 0) {
          defHeader = *(uint *)(defChunk + 0xc);
loopCheckDefHeader:
          if (((defHeader & 0x3fc0000) == 0x1300000) ||
             ((moveUsesRelativeAddressing && ((defHeader & 0x3fc0000) == 0x1200000)))) goto setPendingMaskAny;
          defSrcCount = defHeader >> 0x1d;
          defSrcIndex = 0;
          if (defSrcCount != 0) {
            defSrcCursor = defChunk + 0x10;
            scratchPtrOrWord = (uint *)(*(uint *)(moveOperation + 0x10) >> 0x17 & 7);
            do {
              streamOrLeftover = defSrcCount;
              if (((uint *)(*(uint *)(defSrcCursor + 0xc) >> 0x17 & 7) == scratchPtrOrWord) &&
                 (*(short *)(defSrcCursor + 0x12) == *(short *)(moveOperation + 0x16))) {
                tempReadElsewhere = true;
                break;
              }
              defSrcIndex = defSrcIndex + 1;
              defSrcCursor = defSrcCursor + 8;
            } while (defSrcIndex < defSrcCount);
          }
        }
        else {
          defHeader = *(uint *)(defChunk + 0xc);
          if (*(uint *)(lastLabelChunk + 0xc) <= (defHeader & 0x3ffff)) goto loopCheckDefHeader;
setPendingMaskAny:
          pendingMaskAny = 0;
          barrierReached = true;
        }
        searchEnded = true;
        if (barrierReached) break;
        scratchPtrOrWord = *(uint **)(moveOperation + 0x10);
        if ((((((uint)scratchPtrOrWord & 0x8000000) == 0) &&
             ((*(uint *)(defChunk + 0x14) >> 0x11 & 7) == ((uint)scratchPtrOrWord >> 0x17 & 7))) &&
            (*(short *)(defChunk + 0x1a) == *(short *)(moveOperation + 0x16))) &&
           ((*(uint *)(defChunk + 0x14) >> 0xc & 1) == ((uint)scratchPtrOrWord >> 0xe & 1))) {
          searchEnded = false;
          mergedLaneSel[0] = DAT_97c39260;
          mergedLaneSel[1] = DAT_97c39264;
          mergedLaneSel[2] = DAT_97c39268;
          mergedLaneSel[3] = DAT_97c3926c;
          mergedMaskXYZ[0] = 0;
          mergedMaskXYZ[1] = 0;
          mergedMaskXYZ[2] = 0;
          mergedMaskW = (uint *)0x0;
          defOpcodeBits = *(uint *)(defChunk + 0xc) & 0x3fc0000;
          if (((((((defOpcodeBits == 0xb80000) || (defOpcodeBits == 0x1080000)) ||
                 ((defOpcodeBits == 0x10c0000 || ((defOpcodeBits == 0x1100000 || (defOpcodeBits == 0x1140000)))))) ||
                (defOpcodeBits == 0x1180000)) || ((defOpcodeBits == 0x11c0000 || (defOpcodeBits == 0x2c0000)))) &&
              ((*(uint *)(defChunk + 0x10) >> 0x1a & 3) == (*(uint *)(moveOperation + 4) >> 0x1a & 3))) ||
             ((((defOpcodeBits = *(uint *)(defChunk + 0xc) & 0x3fc0000, defOpcodeBits == 0x9c0000 ||
                (defOpcodeBits == 0xac0000)) || (defOpcodeBits == 0x480000)) ||
              (((defOpcodeBits == 0x200000 || (defOpcodeBits == 0x240000)) ||
               ((*(uint *)(defChunk + 0x10) >> 0x1a & 3) <= (*(uint *)(moveOperation + 4) >> 0x1a & 3)))))))
          {
            movDestA = *(uint *)(moveOperation + 8);
            movSrcSwizzleX = (uint)scratchPtrOrWord >> 0x15 & 3;
            defLaneSel[0] = *(uint *)(defChunk + 0x14) >> 8 & 3;
            defLaneSel[1] = *(uint *)(defChunk + 0x14) >> 6 & 3;
            defLaneSel[2] = *(uint *)(defChunk + 0x14) >> 4 & 3;
            defLaneSel[3] = *(uint *)(defChunk + 0x14) >> 2 & 3;
            defWriteMask[0] = *(uint *)(defChunk + 0x14) >> 0xd & 1;
            defWriteMask[1] = *(uint *)(defChunk + 0x14) >> 0xe & 1;
            defWriteMask[2] = *(uint *)(defChunk + 0x14) >> 0xf & 1;
            movSrcSwizzle[2] = (uint)scratchPtrOrWord >> 0x11 & 3;
            movDestLaneSel[0] = movDestA >> 8 & 3;
            defWriteMask[3] = *(uint *)(defChunk + 0x14) >> 0x10 & 1;
            lanesLeft = 4;
            movSrcSwizzle[0] = movSrcSwizzleX;
            movSrcSwizzle[1] = (uint)scratchPtrOrWord >> 0x13 & 3;
            streamOrLeftover = 0;
            movSrcSwizzle[3] = (uint)scratchPtrOrWord >> 0xf & 3;
            movDestLaneSel[1] = movDestA >> 6 & 3;
            movDestLaneSel[2] = movDestA >> 4 & 3;
            movDestLaneSel[3] = movDestA >> 2 & 3;
            scratchPtrOrWord = pendingMaskXYZ;
            do {
              if ((*scratchPtrOrWord != 0) && (srcLane = movSrcSwizzle[scratchPtrOrWord[0x18]], defWriteMask[srcLane] != 0)) {
                *scratchPtrOrWord = 0;
                searchEnded = true;
                newLaneSel = defLaneSel[srcLane];
                scratchPtrOrWord[4] = 1;
                pendingMaskAny = (uint)(((pendingMaskXYZ[0] != 0 || pendingMaskXYZ[1] != 0) || pendingMaskXYZ[2] != 0) ||
                               pendingMaskW != (uint *)0x0);
                scratchPtrOrWord[8] = newLaneSel;
              }
              scratchPtrOrWord = scratchPtrOrWord + 1;
              lanesLeft = lanesLeft + -1;
            } while (lanesLeft != 0);
            if (searchEnded) {
              movDestB = *(undefined4 *)(moveOperation + 0xc);
              *(uint *)(defChunk + 0x14) = movDestA;
              rewroteDefinition = true;
              *(undefined4 *)(defChunk + 0x18) = movDestB;
              maskBitX = (mergedMaskXYZ[0] & 1) << 0xd;
              *(uint *)(defChunk + 0x14) = maskBitX | movDestA & 0xffffdfff;
              maskBitY = (mergedMaskXYZ[1] & 1) << 0xe;
              *(uint *)(defChunk + 0x14) = maskBitY | maskBitX | movDestA & 0xffff9fff;
              maskBitZ = (mergedMaskXYZ[2] & 1) << 0xf;
              *(uint *)(defChunk + 0x14) = maskBitZ | maskBitY | maskBitX | movDestA & 0xffff1fff;
              maskBitW = ((uint)mergedMaskW & 1) << 0x10;
              *(uint *)(defChunk + 0x14) = maskBitW | maskBitZ | maskBitY | maskBitX | movDestA & 0xfffe1fff;
              laneSelBitsX = (mergedLaneSel[0] & 3) << 8;
              *(uint *)(defChunk + 0x14) =
                   laneSelBitsX | maskBitW | maskBitZ | maskBitY | maskBitX | movDestA & 0xfffe1cff;
              laneSelBitsY = (mergedLaneSel[1] & 3) << 6;
              *(uint *)(defChunk + 0x14) =
                   laneSelBitsY | laneSelBitsX | maskBitW | maskBitZ | maskBitY | maskBitX | movDestA & 0xfffe1c3f;
              laneSelBitsZ = (mergedLaneSel[2] & 3) << 4;
              *(uint *)(defChunk + 0x14) =
                   laneSelBitsZ | laneSelBitsY | laneSelBitsX | maskBitW | maskBitZ | maskBitY | maskBitX | movDestA & 0xfffe1c0f;
              *(uint *)(defChunk + 0x14) =
                   (mergedLaneSel[3] & 3) << 2 |
                   laneSelBitsZ | laneSelBitsY | laneSelBitsX | maskBitW | maskBitZ | maskBitY | maskBitX | movDestA & 0xfffe1c03;
            }
          }
          else {
            pendingMaskAny = 0;
          }
        }
        defChunk = *(int *)(defChunk + 4);
        searchEnded = pendingMaskAny == 0;
        if (tempReadElsewhere) {
          pendingMaskAny = 0;
        }
        searchEnded = tempReadElsewhere || searchEnded;
        if ((searchEnded) || (barrierReached = false, defChunk == 0)) break;
      } while( true );
    }
    pendingMaskAny = pendingMaskXYZ[0] | pendingMaskXYZ[1] | pendingMaskXYZ[2] | (uint)pendingMaskW;
    if ((pendingMaskAny != 0) && (rewroteDefinition)) {
      TPPStreamCompiler__warning(this,(char *)0x0,(char *)0x0,DAT_a7b7bd40,movSrcSwizzleX,streamOrLeftover,pendingMaskAny,scratchPtrOrWord);
    }
    if (searchEnded) {
      if (rewroteDefinition) {
        propagated = 1;
        ((int (*)())TPPStreamCompiler__removeOrphanedCompilerTemp)(this,moveOperation,tempOperand);
      }
    }
    else if (rewroteDefinition) {
      *(uint *)(moveOperation + 8) =
           ((uint)pendingMaskW & 1) << 0x10 |
           (pendingMaskXYZ[2] & 1) << 0xf |
           (pendingMaskXYZ[1] & 1) << 0xe | (pendingMaskXYZ[0] & 1) << 0xd | *(uint *)(moveOperation + 8) & 0xfffe1fff
      ;
    }
  }
  return propagated;
}

/* TPPStreamCompiler__parseIntermediateTree @ 0x97bc94d0 (480 bytes) */
int TPPStreamCompiler__parseIntermediateTree(this, root)
  unsigned char * this;
  unsigned char * root;
{
  int functionStackEmpty;
  void *rootOperand;
  void *oldAddressTempAllocator;
  void *position;
  void *allocation;
  int labelQueueSize;
  undefined4 leftoverR5;
  undefined4 leftoverR6;
  undefined4 leftoverR7;
  undefined4 leftoverR8;
  void *oldTemporaryAllocator;
  unsigned char * labelQueue;
  bool succeeded;
  undefined4 addressUsageRecord [7];
  
  succeeded = false;
  if (root != (unsigned char *)0x0) {
    oldTemporaryAllocator = *(void **)(this + 0x60);
    *(undefined4 *)(this + 0xac) = 0;
    *(undefined4 *)(this + 0x8c) = 0;
    *(undefined4 *)(this + 0x94) = 0;
    *(undefined4 *)(this + 0xa0) = 0;
    *(undefined4 *)(this + 0xa8) = 0;
    if (oldTemporaryAllocator != (void *)0x0) {
      __ZN18TemporaryAllocatorD1Ev(oldTemporaryAllocator);
      __ZdlPv(oldTemporaryAllocator);
    }
    allocation = operator_new(200);
    __ZN18TemporaryAllocatorC1Ev(allocation);
    *(void **)(this + 0x60) = allocation;
    *(void **)PTR_temporaryAllocator_a7b7c0fc = allocation;
    oldAddressTempAllocator = *(void **)(this + 100);
    if (oldAddressTempAllocator != (void *)0x0) {
      __ZN20AddressTempAllocatorD1Ev(oldAddressTempAllocator);
      __ZdlPv(oldAddressTempAllocator);
    }
    allocation = operator_new(8);
    __ZN20AddressTempAllocatorC1Ev(allocation);
    *(void **)(this + 100) = allocation;
    *(void **)PTR_addressTempAllocator_a7b7c0f8 = allocation;
    labelQueue = (unsigned char *)(this + 0x4c);
    while( true ) {
      labelQueueSize = size(labelQueue);
      if (labelQueueSize == 0) break;
      ((int (*)())fetch)(labelQueue);
    }
    newQueue(labelQueue);
    *(undefined4 *)(this + 0x98) = 0;
    ConstantAllocationList__clear((unsigned char *)(this + 0x44));
    while (functionStackEmpty = ((int (*)())ParseFunctionStack__empty)((unsigned char *)(this + 0x58)), functionStackEmpty == 0) {
      ((int (*)())ParseFunctionStack__pop)((unsigned char *)(this + 0x58));
    }
    if (*(int *)(this + 8) == 0) {
      position = (void *)((int (*)())TPPStreamCompiler__getPosition)(this);
      if (position != (void *)0x0) {
        __ZN12ParseOperandD1Ev(position);
        __ZdlPv(position);
      }
    }
    *(undefined4 *)(*(int *)(this + 0x68) + 0x50) = 1;
    (**(code **)(*(int *)root + 0x10))(root,this,leftoverR5,leftoverR6,leftoverR7,leftoverR8,*(int *)root);
    *(undefined4 *)(*(int *)(this + 0x68) + 0x50) = 0;
    if (*(int *)(this + 0xa8) == 1) {
      addressUsageRecord[0] = 0;
      _PPStreamAddAddressUsage(*(undefined4 *)(this + 0x70),addressUsageRecord);
    }
    *(undefined4 *)(this + 0x94) = 0;
    *(undefined4 *)(this + 0x8c) = 0;
    rootOperand = (void *)(**(code **)(*(int *)root + 0xc))(root,this);
    if (rootOperand != (void *)0x0) {
      __ZN12ParseOperandD1Ev(rootOperand);
      __ZdlPv(rootOperand);
    }
    ParseSymbolTable__ClearCompilerTempData(*(unsigned char **)(this + 0x68));
    succeeded = *(int *)(this + 0xa0) != 1;
  }
  return succeeded;
}

/* __ZN17TPPStreamCompilerC2E11EShLanguagei @ 0x97bc96b0 (4 bytes) */
int __ZN17TPPStreamCompilerC2E11EShLanguagei(this, language, debugOptions)
  void *this;
  undefined4 language;
  undefined4 debugOptions;
{
  int atomicStore;
  undefined *emptyRepStorage;
  int *emptyRepRefcount;
  char reservation;
  byte cr0Reg;
  
  *(undefined4 *)((int)this + 8) = language;
  *(undefined ***)this = &PTR___ZN9TCompilerD1Ev_a7b7d850;
  *(int *)((int)this + 4) = (int)this + 0xb0;
  *(undefined4 *)((int)this + 0xc) = 0;
  __ZN14TPoolAllocatorC1Ebii((void *)((int)this + 0x10),false,0x2000,0x10);
  *(int *)this = DAT_a7b7bd98 + 8;
  __ZN22ConstantAllocationListC1Ev((void *)((int)this + 0x44));
  ((int (*)())__ZN18ParseFunctionStackC1Ev)((void *)((int)this + 0x58));
  ((int (*)())__ZN19ParseWhileLoopStackC1Ev)((void *)((int)this + 0x5c));
  emptyRepStorage = PTR__S_empty_rep_storage_a7b7c0f0;
  emptyRepRefcount = (int *)(PTR__S_empty_rep_storage_a7b7c0f0 + 8);
  do {
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(*emptyRepRefcount + 1,0,emptyRepRefcount);
      *emptyRepRefcount = atomicStore;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  *(undefined4 *)((int)this + 0xb4) = 4;
  *(undefined **)((int)this + 0xb0) = emptyRepStorage + 0xc;
  do {
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(*emptyRepRefcount + 1,0,emptyRepRefcount);
      *emptyRepRefcount = atomicStore;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  *(undefined4 *)((int)this + 0xbc) = 4;
  *(undefined **)((int)this + 0xb8) = emptyRepStorage + 0xc;
  *(undefined4 *)((int)this + 0xc0) = debugOptions;
  newQueue((unsigned char *)((int)this + 0x4c));
  *(undefined4 *)((int)this + 0x88) = 0;
  *(undefined4 *)((int)this + 0x9c) = 1;
  *(undefined4 *)((int)this + 0x68) = 0;
  *(undefined4 *)((int)this + 0x6c) = 0;
  *(undefined4 *)((int)this + 0x74) = 0;
  *(undefined4 *)((int)this + 0x70) = 0;
  *(undefined4 *)((int)this + 0x7c) = 0;
  *(undefined4 *)((int)this + 0x80) = 0;
  *(undefined4 *)((int)this + 0x78) = 0;
  *(undefined4 *)((int)this + 0x84) = 0;
  *(undefined4 *)((int)this + 0x60) = 0;
  *(undefined4 *)((int)this + 100) = 0;
  return;
}

/* __ZN17TPPStreamCompilerC1E11EShLanguagei @ 0x97bc96b4 (4 bytes) */
int __ZN17TPPStreamCompilerC1E11EShLanguagei(this, language, debugOptions)
  void *this;
  undefined4 language;
  undefined4 debugOptions;
{
  int atomicStore;
  undefined *emptyRepStorage;
  int *emptyRepRefcount;
  char reservation;
  byte cr0Reg;
  
  *(undefined4 *)((int)this + 8) = language;
  *(undefined ***)this = &PTR___ZN9TCompilerD1Ev_a7b7d850;
  *(int *)((int)this + 4) = (int)this + 0xb0;
  *(undefined4 *)((int)this + 0xc) = 0;
  __ZN14TPoolAllocatorC1Ebii((void *)((int)this + 0x10),false,0x2000,0x10);
  *(int *)this = DAT_a7b7bd98 + 8;
  __ZN22ConstantAllocationListC1Ev((void *)((int)this + 0x44));
  ((int (*)())__ZN18ParseFunctionStackC1Ev)((void *)((int)this + 0x58));
  ((int (*)())__ZN19ParseWhileLoopStackC1Ev)((void *)((int)this + 0x5c));
  emptyRepStorage = PTR__S_empty_rep_storage_a7b7c0f0;
  emptyRepRefcount = (int *)(PTR__S_empty_rep_storage_a7b7c0f0 + 8);
  do {
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(*emptyRepRefcount + 1,0,emptyRepRefcount);
      *emptyRepRefcount = atomicStore;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  *(undefined4 *)((int)this + 0xb4) = 4;
  *(undefined **)((int)this + 0xb0) = emptyRepStorage + 0xc;
  do {
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(*emptyRepRefcount + 1,0,emptyRepRefcount);
      *emptyRepRefcount = atomicStore;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  *(undefined4 *)((int)this + 0xbc) = 4;
  *(undefined **)((int)this + 0xb8) = emptyRepStorage + 0xc;
  *(undefined4 *)((int)this + 0xc0) = debugOptions;
  newQueue((unsigned char *)((int)this + 0x4c));
  *(undefined4 *)((int)this + 0x88) = 0;
  *(undefined4 *)((int)this + 0x9c) = 1;
  *(undefined4 *)((int)this + 0x68) = 0;
  *(undefined4 *)((int)this + 0x6c) = 0;
  *(undefined4 *)((int)this + 0x74) = 0;
  *(undefined4 *)((int)this + 0x70) = 0;
  *(undefined4 *)((int)this + 0x7c) = 0;
  *(undefined4 *)((int)this + 0x80) = 0;
  *(undefined4 *)((int)this + 0x78) = 0;
  *(undefined4 *)((int)this + 0x84) = 0;
  *(undefined4 *)((int)this + 0x60) = 0;
  *(undefined4 *)((int)this + 100) = 0;
  return;
}

/* __ZN17TPPStreamCompilerC4E11EShLanguagei @ 0x97bc96b8 (284 bytes) */
int __ZN17TPPStreamCompilerC4E11EShLanguagei(this, language, debugOptions)
  void *this;
  undefined4 language;
  undefined4 debugOptions;
{
  int atomicStore;
  undefined *emptyRepStorage;
  int *emptyRepRefcount;
  char reservation;
  byte cr0Reg;
  
  *(undefined4 *)((int)this + 8) = language;
  *(undefined ***)this = &PTR___ZN9TCompilerD1Ev_a7b7d850;
  *(int *)((int)this + 4) = (int)this + 0xb0;
  *(undefined4 *)((int)this + 0xc) = 0;
  __ZN14TPoolAllocatorC1Ebii((void *)((int)this + 0x10),0,0x2000,0x10);
  *(int *)this = DAT_a7b7bd98 + 8;
  __ZN22ConstantAllocationListC1Ev((void *)((int)this + 0x44));
  ((int (*)())__ZN18ParseFunctionStackC1Ev)((void *)((int)this + 0x58));
  ((int (*)())__ZN19ParseWhileLoopStackC1Ev)((void *)((int)this + 0x5c));
  emptyRepStorage = PTR__S_empty_rep_storage_a7b7c0f0;
  emptyRepRefcount = (int *)(PTR__S_empty_rep_storage_a7b7c0f0 + 8);
  do {
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(*emptyRepRefcount + 1,0,emptyRepRefcount);
      *emptyRepRefcount = atomicStore;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  *(undefined4 *)((int)this + 0xb4) = 4;
  *(undefined **)((int)this + 0xb0) = emptyRepStorage + 0xc;
  do {
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(*emptyRepRefcount + 1,0,emptyRepRefcount);
      *emptyRepRefcount = atomicStore;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  *(undefined4 *)((int)this + 0xbc) = 4;
  *(undefined **)((int)this + 0xb8) = emptyRepStorage + 0xc;
  *(undefined4 *)((int)this + 0xc0) = debugOptions;
  newQueue((unsigned char *)((int)this + 0x4c));
  *(undefined4 *)((int)this + 0x88) = 0;
  *(undefined4 *)((int)this + 0x9c) = 1;
  *(undefined4 *)((int)this + 0x68) = 0;
  *(undefined4 *)((int)this + 0x6c) = 0;
  *(undefined4 *)((int)this + 0x74) = 0;
  *(undefined4 *)((int)this + 0x70) = 0;
  *(undefined4 *)((int)this + 0x7c) = 0;
  *(undefined4 *)((int)this + 0x80) = 0;
  *(undefined4 *)((int)this + 0x78) = 0;
  *(undefined4 *)((int)this + 0x84) = 0;
  *(undefined4 *)((int)this + 0x60) = 0;
  *(undefined4 *)((int)this + 100) = 0;
  return;
}

/* __ZN17TPPStreamCompilerD2Ev @ 0x97bc97d4 (8 bytes) */
int __ZN17TPPStreamCompilerD2Ev(this)
  void *this;
{
  return __ZN17TPPStreamCompilerD4Ev(this,0);
}

