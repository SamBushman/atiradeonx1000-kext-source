#include "decls.h"

/* _ShGetInfoLog @ 0x97ba1c6c (244 bytes) */
int _ShGetInfoLog(handle)
  int *handle;
{
  int linkerObj;
  undefined *terminalPtr;
  int compilerObj;
  int *infoSink;
  int result;
  
  result = 0;
  if (handle != (int *)0x0) {
    compilerObj = (**(code **)(*handle + 8))(handle);
    if (compilerObj == 0) {
      linkerObj = (**(code **)(*handle + 0xc))(handle);
      if (linkerObj == 0) {
        return 0;
      }
      linkerObj = (**(code **)(*handle + 0xc))(handle);
      infoSink = *(int **)(linkerObj + 0x84);
    }
    else {
      infoSink = (int *)(**(code **)(*handle + 8))(handle);
      infoSink = (int *)(**(code **)(*infoSink + 0x10))(infoSink);
    }
    terminalPtr = PTR__S_terminal_a7b7c0b8;
    if (infoSink != (int *)0x0) {
      *(undefined *)(infoSink[2] + *(int *)(infoSink[2] + -0xc)) = *PTR__S_terminal_a7b7c0b8;
      __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)infoSink[2]);
      *(undefined *)(*infoSink + *(int *)(*infoSink + -0xc)) = *terminalPtr;
      result = *infoSink;
    }
  }
  return result;
}

/* _ShGetPPStream @ 0x97ba1d60 (96 bytes) */
int _ShGetPPStream(handle)
  int *handle;
{
  int *compilerObj;
  undefined4 result;
  
  result = 0;
  if ((handle != (int *)0x0) &&
     (compilerObj = (int *)(**(code **)(*handle + 8))(handle), compilerObj != (int *)0x0)) {
    result = (**(code **)(*compilerObj + 0x1c))(compilerObj);
  }
  return result;
}

/* _ShGetShaderLocalParamRemapTable @ 0x97ba1dc0 (92 bytes) */
int _ShGetShaderLocalParamRemapTable(handle, language)
  int *handle;
  undefined4 language;
{
  unsigned char * linkerObj;
  undefined4 result;
  
  result = 0;
  if ((handle != (int *)0x0) &&
     (linkerObj = (unsigned char *)(**(code **)(*handle + 0xc))(handle), linkerObj != (unsigned char *)0x0
     )) {
    result = TGenericLinker__getShaderLocalParamRemapTable(linkerObj,language);
  }
  return result;
}

/* _ShGetNumShaderLocalParams @ 0x97ba1e1c (92 bytes) */
int _ShGetNumShaderLocalParams(handle, language)
  int *handle;
  undefined4 language;
{
  unsigned char * linkerObj;
  undefined4 result;
  
  result = 0;
  if ((handle != (int *)0x0) &&
     (linkerObj = (unsigned char *)(**(code **)(*handle + 0xc))(handle), linkerObj != (unsigned char *)0x0
     )) {
    result = TGenericLinker__getNumShaderLocalParams(linkerObj,language);
  }
  return result;
}

/* _ShAttributeBindingRequest @ 0x97ba1e78 (104 bytes) */
int _ShAttributeBindingRequest(handle, index, str)
  int *handle;
  ulong index;
  char *str;
{
  unsigned char * linkerObj;
  
  if ((handle != (int *)0x0) &&
     (linkerObj = (unsigned char *)(**(code **)(*handle + 0xc))(handle), linkerObj != (unsigned char *)0x0
     )) {
    TGenericLinker__attributeBindingRequest(linkerObj,index,str);
    return;
  }
  return;
}

/* _ShGetNumActiveAttributes @ 0x97ba1ee0 (104 bytes) */
int _ShGetNumActiveAttributes(handle)
  int *handle;
{
  int linkerObj;
  undefined4 result;
  
  result = 0;
  if ((handle != (int *)0x0) && (linkerObj = (**(code **)(*handle + 0xc))(handle), linkerObj != 0)) {
    result = 0;
    if (*(unsigned char **)(linkerObj + 4) != (unsigned char *)0x0) {
      result = BindingTable__GetNumActiveAttributeBindings(*(unsigned char **)(linkerObj + 4));
    }
  }
  return result;
}

/* _ShGetNumActiveUniforms @ 0x97ba1f48 (104 bytes) */
int _ShGetNumActiveUniforms(handle)
  int *handle;
{
  int linkerObj;
  undefined4 result;
  
  result = 0;
  if ((handle != (int *)0x0) && (linkerObj = (**(code **)(*handle + 0xc))(handle), linkerObj != 0)) {
    result = 0;
    if (*(unsigned char **)(linkerObj + 4) != (unsigned char *)0x0) {
      result = BindingTable__GetNumActiveUniformBindings(*(unsigned char **)(linkerObj + 4));
    }
  }
  return result;
}

/* _ShGetActiveUserUniformsSize @ 0x97ba1fb0 (104 bytes) */
int _ShGetActiveUserUniformsSize(handle)
  int *handle;
{
  int linkerObj;
  undefined4 result;
  
  result = 0;
  if ((handle != (int *)0x0) && (linkerObj = (**(code **)(*handle + 0xc))(handle), linkerObj != 0)) {
    result = 0;
    if (*(unsigned char **)(linkerObj + 4) != (unsigned char *)0x0) {
      result = BindingTable__GetSizeActiveUserUniforms(*(unsigned char **)(linkerObj + 4));
    }
  }
  return result;
}

/* _ShGetMaxAttributeLength @ 0x97ba2018 (104 bytes) */
int _ShGetMaxAttributeLength(handle)
  int *handle;
{
  int linkerObj;
  undefined4 result;
  
  result = 0;
  if ((handle != (int *)0x0) && (linkerObj = (**(code **)(*handle + 0xc))(handle), linkerObj != 0)) {
    result = 0;
    if (*(unsigned char **)(linkerObj + 4) != (unsigned char *)0x0) {
      result = BindingTable__GetMaxAttributeLength(*(unsigned char **)(linkerObj + 4));
    }
  }
  return result;
}

/* _ShGetMaxUniformLength @ 0x97ba2080 (104 bytes) */
int _ShGetMaxUniformLength(handle)
  int *handle;
{
  int linkerObj;
  undefined4 result;
  
  result = 0;
  if ((handle != (int *)0x0) && (linkerObj = (**(code **)(*handle + 0xc))(handle), linkerObj != 0)) {
    result = 0;
    if (*(unsigned char **)(linkerObj + 4) != (unsigned char *)0x0) {
      result = BindingTable__GetMaxUniformLength(*(unsigned char **)(linkerObj + 4));
    }
  }
  return result;
}

/* _ShGetActiveUniform @ 0x97ba20e8 (132 bytes) */
int _ShGetActiveUniform(handle, index, maxLength, lengthOut, sizeOut, typeOut, str)
  int *handle;
  ulong index;
  long maxLength;
  long *lengthOut;
  long *sizeOut;
  ulong *typeOut;
  char *str;
{
  unsigned char * linkerObj;
  undefined4 result;
  
  result = 0;
  if ((handle != (int *)0x0) &&
     (linkerObj = (unsigned char *)(**(code **)(*handle + 0xc))(handle), linkerObj != (unsigned char *)0x0
     )) {
    result = TGenericLinker__getActiveUniform(linkerObj,index,maxLength,lengthOut,sizeOut,typeOut,str);
  }
  return result;
}

/* _ShGetUniformTypeInfo @ 0x97ba216c (116 bytes) */
int _ShGetUniformTypeInfo(handle, index, sizeOut, typeOut, stageUseOut)
  int *handle;
  long index;
  long *sizeOut;
  ulong *typeOut;
  uchar *stageUseOut;
{
  unsigned char * linkerObj;
  undefined4 result;
  
  result = 0;
  if ((handle != (int *)0x0) &&
     (linkerObj = (unsigned char *)(**(code **)(*handle + 0xc))(handle), linkerObj != (unsigned char *)0x0
     )) {
    result = TGenericLinker__getUniformTypeInfo(linkerObj,index,sizeOut,typeOut,stageUseOut);
  }
  return result;
}

/* _ShGetActiveAttrib @ 0x97ba21e0 (132 bytes) */
int _ShGetActiveAttrib(handle, index, maxLength, lengthOut, sizeOut, typeOut, str)
  int *handle;
  ulong index;
  long maxLength;
  long *lengthOut;
  long *sizeOut;
  ulong *typeOut;
  char *str;
{
  unsigned char * linkerObj;
  undefined4 result;
  
  result = 0;
  if ((handle != (int *)0x0) &&
     (linkerObj = (unsigned char *)(**(code **)(*handle + 0xc))(handle), linkerObj != (unsigned char *)0x0
     )) {
    result = TGenericLinker__getActiveAttrib(linkerObj,index,maxLength,lengthOut,sizeOut,typeOut,str);
  }
  return result;
}

/* _ShGetAttribLocation @ 0x97ba2264 (112 bytes) */
int _ShGetAttribLocation(handle, str)
  int *handle;
  char *str;
{
  int linkerObj;
  undefined4 location;
  
  location = 0xffffffff;
  if ((handle != (int *)0x0) && (linkerObj = (**(code **)(*handle + 0xc))(handle), linkerObj != 0)) {
    location = 0xffffffff;
    if (*(unsigned char **)(linkerObj + 4) != (unsigned char *)0x0) {
      location = BindingTable__FindAttribBindingLocationByName(*(unsigned char **)(linkerObj + 4),str);
    }
  }
  return location;
}

/* _ShGetUniformLocation @ 0x97ba22d4 (112 bytes) */
int _ShGetUniformLocation(handle, str)
  int *handle;
  char *str;
{
  int linkerObj;
  undefined4 location;
  
  location = 0xffffffff;
  if ((handle != (int *)0x0) && (linkerObj = (**(code **)(*handle + 0xc))(handle), linkerObj != 0)) {
    location = 0xffffffff;
    if (*(unsigned char **)(linkerObj + 4) != (unsigned char *)0x0) {
      location = BindingTable__FindClientUniformBindingLocationByName
                        (*(unsigned char **)(linkerObj + 4),str);
    }
  }
  return location;
}

/* _ShGetPPStreamManager @ 0x97ba2344 (92 bytes) */
int _ShGetPPStreamManager(handle, language)
  int *handle;
  undefined4 language;
{
  unsigned char * linkerObj;
  undefined4 result;
  
  result = 0;
  if ((handle != (int *)0x0) &&
     (linkerObj = (unsigned char *)(**(code **)(*handle + 0xc))(handle), linkerObj != (unsigned char *)0x0
     )) {
    result = TGenericLinker__getPPStreamManager(linkerObj,language);
  }
  return result;
}

/* _ShGetLinkerStats @ 0x97ba23a0 (84 bytes) */
int _ShGetLinkerStats(handle)
  int *handle;
{
  unsigned char * linkerObj;
  undefined4 result;
  
  result = 0;
  if ((handle != (int *)0x0) &&
     (linkerObj = (unsigned char *)(**(code **)(*handle + 0xc))(handle), linkerObj != (unsigned char *)0x0
     )) {
    result = TGenericLinker__getStatsString(linkerObj);
  }
  return result;
}

/* _ShGetCompilerStats @ 0x97ba23f4 (96 bytes) */
int _ShGetCompilerStats(handle)
  int *handle;
{
  int *compiler;
  undefined4 result;
  
  result = 0;
  if ((handle != (int *)0x0) &&
     (compiler = (int *)(**(code **)(*handle + 8))(handle), compiler != (int *)0x0)) {
    result = (**(code **)(*compiler + 0x24))(compiler);
  }
  return result;
}

/* _ShGetLinkerPPStream @ 0x97ba2454 (84 bytes) */
int _ShGetLinkerPPStream(handle)
  int *handle;
{
  unsigned char * linkerObj;
  undefined4 result;
  
  result = 0;
  if ((handle != (int *)0x0) &&
     (linkerObj = (unsigned char *)(**(code **)(*handle + 0xc))(handle), linkerObj != (unsigned char *)0x0
     )) {
    result = TGenericLinker__getPPStreamString(linkerObj);
  }
  return result;
}

/* _ShGetCompilerPPStream @ 0x97ba24a8 (96 bytes) */
int _ShGetCompilerPPStream(handle)
  int *handle;
{
  int *compilerObj;
  undefined4 result;
  
  result = 0;
  if ((handle != (int *)0x0) &&
     (compilerObj = (int *)(**(code **)(*handle + 8))(handle), compilerObj != (int *)0x0)) {
    result = (**(code **)(*compilerObj + 0x28))(compilerObj);
  }
  return result;
}

/* _ShGetLinkerShaderToProgramString @ 0x97ba2508 (84 bytes) */
int _ShGetLinkerShaderToProgramString(handle)
  int *handle;
{
  unsigned char * linkerObj;
  undefined4 result;
  
  result = 0;
  if ((handle != (int *)0x0) &&
     (linkerObj = (unsigned char *)(**(code **)(*handle + 0xc))(handle), linkerObj != (unsigned char *)0x0
     )) {
    result = TGenericLinker__getShaderToProgramString(linkerObj);
  }
  return result;
}

/* _ShGetCompilerShaderToProgramString @ 0x97ba255c (96 bytes) */
int _ShGetCompilerShaderToProgramString(handle)
  int *handle;
{
  int *compilerObj;
  undefined4 result;
  
  result = 0;
  if ((handle != (int *)0x0) &&
     (compilerObj = (int *)(**(code **)(*handle + 8))(handle), compilerObj != (int *)0x0)) {
    result = (**(code **)(*compilerObj + 0x2c))(compilerObj);
  }
  return result;
}

/* _ShGetLinkerBindingTable @ 0x97ba25bc (84 bytes) */
int _ShGetLinkerBindingTable(handle)
  int *handle;
{
  unsigned char * linkerObj;
  undefined4 result;
  
  result = 0;
  if ((handle != (int *)0x0) &&
     (linkerObj = (unsigned char *)(**(code **)(*handle + 0xc))(handle), linkerObj != (unsigned char *)0x0
     )) {
    result = TGenericLinker__getTableString(linkerObj);
  }
  return result;
}

/* _ShGetCompilerSymbolTable @ 0x97ba2610 (96 bytes) */
int _ShGetCompilerSymbolTable(handle)
  int *handle;
{
  int *compilerObj;
  undefined4 result;
  
  result = 0;
  if ((handle != (int *)0x0) &&
     (compilerObj = (int *)(**(code **)(*handle + 8))(handle), compilerObj != (int *)0x0)) {
    result = (**(code **)(*compilerObj + 0x30))(compilerObj);
  }
  return result;
}

/* TType__buildMangledName @ 0x97ba2670 (688 bytes) */
int TType__buildMangledName(this, text)
  unsigned char * this;
  unsigned char * text;
{
  undefined4 nominalSize;
  int isArrayResult;
  int isVectorResult;
  int isMatrixResult;
  ulong length;
  undefined4 staleR4;
  undefined4 mangleChar;
  char *typeCode;
  uint fieldIdx;
  char sizeText [16];
  
  isMatrixResult = (**(code **)(*(int *)this + 0x34))(this);
  if (isMatrixResult == 0) {
    isVectorResult = (**(code **)(*(int *)this + 0x3c))(this,staleR4);
    if (isVectorResult != 0) {
      mangleChar = 0x76;
      goto callZNSbIcSt11charTraitsIcE14poolAllocatorIcEE6appendEmc;
    }
  }
  else {
    mangleChar = 0x6d;
callZNSbIcSt11charTraitsIcE14poolAllocatorIcEE6appendEmc:
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEmc(text,1,mangleChar);
  }
  switch(*(uint *)(this + 0x24) >> 0x13 & 0x3f) {
  default:
    goto thisCase0;
  case 1:
    mangleChar = 0x66;
    goto callZNSbIcSt11charTraitsIcE14poolAllocatorIcEE6appendEmc2;
  case 2:
    mangleChar = 0x69;
    goto callZNSbIcSt11charTraitsIcE14poolAllocatorIcEE6appendEmc2;
  case 3:
    mangleChar = 0x62;
callZNSbIcSt11charTraitsIcE14poolAllocatorIcEE6appendEmc2:
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEmc(text,1,mangleChar);
    goto thisCase0;
  case 5:
    typeCode = "s1";
    length = _strlen("s1");
    break;
  case 6:
    typeCode = "s2";
    length = _strlen("s2");
    break;
  case 7:
    typeCode = "s3";
    length = _strlen("s3");
    break;
  case 8:
    typeCode = "sC";
    length = _strlen("sC");
    break;
  case 9:
    typeCode = "sS1";
    length = _strlen("sS1");
    break;
  case 10:
    typeCode = "sS2";
    length = _strlen("sS2");
    break;
  case 0xb:
    typeCode = "sR2";
    length = _strlen("sR2");
    break;
  case 0xc:
    typeCode = "sSR2";
    length = _strlen("sSR2");
    break;
  case 0xe:
    length = _strlen("struct-");
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEPKcm(text,"struct-",length);
    if (*(unsigned char **)(this + 0x10) != (unsigned char *)0x0) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendERKS3_(text,*(unsigned char **)(this + 0x10))
      ;
    }
    for (fieldIdx = 0;
        fieldIdx < (uint)(*(int *)(*(int *)(this + 8) + 8) - *(int *)(*(int *)(this + 8) + 4) >> 3);
        fieldIdx = fieldIdx + 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEmc(text,1,0x2d);
      ((int (*)())TType__buildMangledName)(*(unsigned char **)(*(int *)(*(int *)(this + 8) + 4) + fieldIdx * 8),text);
    }
    goto thisCase0;
  }
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEPKcm(text,typeCode,length);
thisCase0:
  nominalSize = (**(code **)(*(int *)this + 0x2c))(this);
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEmc(text,1,(int)(char)((char)nominalSize + '0'))
  ;
  isArrayResult = (**(code **)(*(int *)this + 0x38))(this);
  if (isArrayResult != 0) {
    _sprintf(sizeText,"%d",*(undefined4 *)(this + 4));
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEmc(text,1,0x5b);
    length = _strlen(sizeText);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEPKcm(text,sizeText,length);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEmc(text,1,0x5d);
  }
  return;
}

/* TVariable__dump @ 0x97ba295c (220 bytes) */
int TVariable__dump(this, infoSink)
  unsigned char * this;
  unsigned char * infoSink;
{
  char *basicString;
  char *qualifierString;
  int symbolName;
  int nameData;
  unsigned char *sinkBase;
  
  symbolName = *(int *)(this + 4);
  sinkBase = infoSink + 8;
  nameData = *(int *)(symbolName + 4);
  *(undefined1 *)(nameData + *(int *)(nameData + -0xc)) = *stringTerminalPtr_a7b7ba80;
  __ZN13TInfoSinkBase6appendEPKc(sinkBase,*(char **)(symbolName + 4));
  __ZN13TInfoSinkBase6appendEPKc(sinkBase,": ");
  qualifierString = (char *)getQualifierString(*(uint *)(this + 0x30) >> 0x19);
  __ZN13TInfoSinkBase6appendEPKc(sinkBase,qualifierString);
  __ZN13TInfoSinkBase6appendEPKc(sinkBase," ");
  basicString = (char *)TType__getBasicString(*(uint *)(this + 0x30) >> 0x13 & 0x3f);
  __ZN13TInfoSinkBase6appendEPKc(sinkBase,basicString);
  if ((*(uint *)(this + 0x30) & 0x200) != 0) {
    __ZN13TInfoSinkBase6appendEPKc(sinkBase,"[0]");
  }
  return __ZN13TInfoSinkBase6appendEPKc(sinkBase,"\n");
}

/* TFunction__dump @ 0x97ba2a38 (216 bytes) */
int TFunction__dump(this, infoSink)
  unsigned char * this;
  unsigned char * infoSink;
{
  int mangledName;
  undefined1 *terminalPtr;
  int nameData;
  char *basicString;
  int symbolName;
  unsigned char *sinkBase;
  
  terminalPtr = stringTerminalPtr_a7b7ba80;
  symbolName = *(int *)(this + 4);
  sinkBase = infoSink + 8;
  nameData = *(int *)(symbolName + 4);
  *(undefined1 *)(nameData + *(int *)(nameData + -0xc)) = *stringTerminalPtr_a7b7ba80;
  __ZN13TInfoSinkBase6appendEPKc(sinkBase,*(char **)(symbolName + 4));
  __ZN13TInfoSinkBase6appendEPKc(sinkBase,": ");
  basicString = (char *)TType__getBasicString(*(uint *)(this + 0x40) >> 0x13 & 0x3f);
  __ZN13TInfoSinkBase6appendEPKc(sinkBase,basicString);
  __ZN13TInfoSinkBase6appendEPKc(sinkBase," ");
  mangledName = (**(code **)(*(int *)this + 8))(this);
  *(undefined1 *)(*(int *)(mangledName + 4) + *(int *)(*(int *)(mangledName + 4) + -0xc)) = *terminalPtr;
  __ZN13TInfoSinkBase6appendEPKc(sinkBase,*(char **)(mangledName + 4));
  return __ZN13TInfoSinkBase6appendEPKc(sinkBase,"\n");
}

/* TSymbolTableLevel__dump @ 0x97ba2b10 (112 bytes) */
int TSymbolTableLevel__dump(this, infoSink)
  unsigned char * this;
  unsigned char * infoSink;
{
  undefined4 staleR5;
  undefined4 staleR6;
  undefined4 staleR7;
  undefined4 staleR8;
  int treeEnd;
  int iter [4];
  
  treeEnd = *(int *)(this + 4);
  iter[0] = *(int *)(treeEnd + 8);
  while (iter[0] != treeEnd) {
    (**(code **)(**(int **)(iter[0] + 0x18) + 0x14))
              (*(int **)(iter[0] + 0x18),infoSink,staleR5,staleR6,staleR7,staleR8,treeEnd);
    std___Rb_tree_base_iterator___M_increment((unsigned char *)iter);
    treeEnd = *(int *)(this + 4);
  }
  return;
}

/* TSymbolTable__dump @ 0x97ba2b80 (268 bytes) */
int TSymbolTable__dump(this, infoSink)
  unsigned char * this;
  unsigned char * infoSink;
{
  int atomicStore;
  int *refCountPtr;
  int oldRefCount;
  unsigned char * sinkBase;
  int levelIdx;
  char reservation;
  byte cr0Flags;
  undefined4 levelNumStrAlloc;
  int levelNumStrData;
  char levelText [16];
  undefined4 ctorAlloc [4];
  undefined4 destroyAlloc [6];
  
  levelIdx = (*(int *)(this + 4) - *(int *)this >> 2) + -1;
  if (-1 < levelIdx) {
    sinkBase = infoSink + 8;
    do {
      cr0Flags = (levelIdx == 0) << 1;
      __ZN13TInfoSinkBase6appendEPKc(sinkBase,"LEVEL ");
      _sprintf(levelText,"%d",levelIdx);
      ctorAlloc[0] = GetGlobalPoolAllocator();
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                (&levelNumStrAlloc,levelText,(unsigned char *)ctorAlloc);
      __ZN13TInfoSinkBase6appendERKSbIcSt11char_traitsIcE14pool_allocatorIcEE
                (sinkBase,(unsigned char *)&levelNumStrAlloc);
      refCountPtr = (int *)(levelNumStrData + -4);
      destroyAlloc[0] = levelNumStrAlloc;
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
                  ((unsigned char *)(levelNumStrData + -0xc),destroyAlloc);
      }
      __ZN13TInfoSinkBase6appendEPKc(sinkBase,"\n");
      ((int (*)())TSymbolTableLevel__dump)(*(unsigned char **)(*(int *)this + levelIdx * 4),infoSink);
      levelIdx = levelIdx + -1;
    } while (-1 < levelIdx);
  }
  return;
}

/* __ZN9TFunctionD2Ev @ 0x97ba2c8c (8 bytes) */
int __ZN9TFunctionD2Ev(this)
  void *this;
{
  return ((int (*)())__ZN9TFunctionD4Ev)(this);
}

/* __ZN9TFunctionD1Ev @ 0x97ba2c94 (8 bytes) */
int __ZN9TFunctionD1Ev(this)
  void *this;
{
  return ((int (*)())__ZN9TFunctionD4Ev)(this);
}

/* __ZN9TFunctionD0Ev @ 0x97ba2c9c (8 bytes) */
int __ZN9TFunctionD0Ev(this)
  void *this;
{
  return ((int (*)())__ZN9TFunctionD4Ev)(this);
}

/* __ZN9TFunctionD4Ev @ 0x97ba2ca4 (236 bytes) */
int __ZN9TFunctionD4Ev(this)
  void *this;
{
  int *refCountPtr;
  int oldRefCount;
  int atomicStore;
  int paramEnd;
  int *paramType;
  int paramPtr;
  char reservation;
  byte cr0Reg;
  undefined4 destroyAlloc [5];
  
  paramPtr = *(int *)((int)this + 0x10);
  *(int *)this = DAT_a7b7ba7c + 8;
  paramEnd = *(int *)((int)this + 0x14);
  for (; paramPtr != paramEnd; paramPtr = paramPtr + 8) {
    paramType = *(int **)(paramPtr + 4);
    if (paramType != (int *)0x0) {
      (**(code **)(*paramType + 4))(paramType);
      paramEnd = *(int *)((int)this + 0x14);
    }
  }
  paramEnd = *(int *)((int)this + 0x48);
  destroyAlloc[0] = *(undefined4 *)((int)this + 0x44);
  refCountPtr = (int *)(paramEnd + -4);
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
              ((unsigned char *)(paramEnd + -0xc),destroyAlloc);
  }
  paramEnd = *(int *)((int)this + 0x10);
  *(undefined ***)((int)this + 0x1c) = &PTR___ZN5TTypeD1Ev_a7b7d590;
  for (; paramEnd != *(int *)((int)this + 0x14); paramEnd = paramEnd + 8) {
  }
  *(undefined ***)this = &PTR___ZN7TSymbolD1Ev_a7b7d568;
  return;
}

/* __ZN17TSymbolTableLevelD2Ev @ 0x97ba2d90 (8 bytes) */
int __ZN17TSymbolTableLevelD2Ev(this)
  void *this;
{
  return ((int (*)())__ZN17TSymbolTableLevelD4Ev)(this,0);
}

/* __ZN17TSymbolTableLevelD1Ev @ 0x97ba2d98 (8 bytes) */
int __ZN17TSymbolTableLevelD1Ev(this)
  void *this;
{
  return ((int (*)())__ZN17TSymbolTableLevelD4Ev)(this,2);
}

/* __ZN17TSymbolTableLevelD4Ev @ 0x97ba2da0 (184 bytes) */
int __ZN17TSymbolTableLevelD4Ev(this, staleR4)
  void *this;
  undefined4 staleR4;
{
  int *symbol;
  undefined4 r4Out0;
  undefined4 staleR5;
  undefined4 staleR6;
  undefined4 staleR7;
  undefined4 staleR8;
  int iter [4];
  int treeEnd;
  
  treeEnd = *(int *)((int)this + 4);
  iter[0] = *(int *)(treeEnd + 8);
  if (iter[0] != treeEnd) {
    do {
      symbol = *(int **)(iter[0] + 0x18);
      if (symbol != (int *)0x0) {
        (**(code **)(*symbol + 4))(symbol,staleR4,staleR5,staleR6,staleR7,staleR8,treeEnd);
      }
      std___Rb_tree_base_iterator___M_increment((unsigned char *)iter);
      treeEnd = *(int *)((int)this + 4);
      staleR4 = r4Out0;
    } while (iter[0] != treeEnd);
  }
  if (*(int *)((int)this + 8) != 0) {
    std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol_______M_erase(this,*(unsigned char **)(treeEnd + 4));
    *(int *)(*(int *)((int)this + 4) + 8) = *(int *)((int)this + 4);
    *(undefined4 *)(*(int *)((int)this + 4) + 4) = 0;
    *(int *)(*(int *)((int)this + 4) + 0xc) = *(int *)((int)this + 4);
    *(undefined4 *)((int)this + 8) = 0;
  }
  return;
}

/* TSymbolTableLevel__relateToOperator @ 0x97ba2e58 (168 bytes) */
int TSymbolTableLevel__relateToOperator(this, str, op)
  unsigned char * this;
  char *str;
  undefined4 op;
{
  int nameCompare;
  int isFunction;
  int symbol;
  int iter [4];
  int treeEnd;
  
  treeEnd = *(int *)(this + 4);
  iter[0] = *(int *)(treeEnd + 8);
  if (iter[0] != treeEnd) {
    do {
      isFunction = (**(code **)(**(int **)(iter[0] + 0x18) + 0xc))(*(int **)(iter[0] + 0x18));
      if (isFunction != 0) {
        symbol = *(int *)(iter[0] + 0x18);
        nameCompare = __ZNKSbIcSt11char_traitsIcE14pool_allocatorIcEE7compareEPKc
                          (*(void **)(symbol + 4),str);
        if (nameCompare == 0) {
          *(undefined4 *)(symbol + 0x4c) = op;
        }
      }
      std___Rb_tree_base_iterator___M_increment((unsigned char *)iter);
      treeEnd = *(int *)(this + 4);
    } while (iter[0] != treeEnd);
  }
  return;
}

/* __ZN7TSymbolC2ERKS_ @ 0x97ba2f00 (4 bytes) */
int __ZN7TSymbolC2ERKS_(this, symbol)
  void *this;
  unsigned char * symbol;
{
  undefined4 uniqueId;
  void *newName;
  unsigned char * poolAllocator;
  void *nameMem;
  int srcName;
  int srcNameData;
  char *nameText;
  undefined4 stringAllocator [7];
  
  srcName = *(int *)(symbol + 4);
  *(undefined ***)this = &PTR___ZN7TSymbolD1Ev_a7b7d568;
  srcNameData = *(int *)(srcName + 4);
  *(undefined1 *)(srcNameData + *(int *)(srcNameData + -0xc)) = *stringTerminalPtr_a7b7ba80;
  nameText = *(char **)(srcName + 4);
  poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
  nameMem = (void *)TPoolAllocator__allocate(poolAllocator,8);
  newName = (void *)0x0;
  if (nameMem != (void *)0x0) {
    stringAllocator[0] = GetGlobalPoolAllocator();
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
              (nameMem,nameText,(unsigned char *)stringAllocator);
    newName = nameMem;
  }
  uniqueId = *(undefined4 *)(symbol + 8);
  *(void **)((int)this + 4) = newName;
  *(undefined4 *)((int)this + 8) = uniqueId;
  return;
}

/* __ZN7TSymbolC1ERKS_ @ 0x97ba2f04 (4 bytes) */
int __ZN7TSymbolC1ERKS_(this, symbol)
  void *this;
  unsigned char * symbol;
{
  undefined4 uniqueId;
  void *newName;
  unsigned char * poolAllocator;
  void *nameMem;
  int srcName;
  int srcNameData;
  char *nameText;
  undefined4 stringAllocator [7];
  
  srcName = *(int *)(symbol + 4);
  *(undefined ***)this = &PTR___ZN7TSymbolD1Ev_a7b7d568;
  srcNameData = *(int *)(srcName + 4);
  *(undefined1 *)(srcNameData + *(int *)(srcNameData + -0xc)) = *stringTerminalPtr_a7b7ba80;
  nameText = *(char **)(srcName + 4);
  poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
  nameMem = (void *)TPoolAllocator__allocate(poolAllocator,8);
  newName = (void *)0x0;
  if (nameMem != (void *)0x0) {
    stringAllocator[0] = GetGlobalPoolAllocator();
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
              (nameMem,nameText,(unsigned char *)stringAllocator);
    newName = nameMem;
  }
  uniqueId = *(undefined4 *)(symbol + 8);
  *(void **)((int)this + 4) = newName;
  *(undefined4 *)((int)this + 8) = uniqueId;
  return;
}

/* __ZN7TSymbolC4ERKS_ @ 0x97ba2f08 (164 bytes) */
int __ZN7TSymbolC4ERKS_(this, symbol)
  void *this;
  unsigned char * symbol;
{
  undefined4 uniqueId;
  void *newName;
  unsigned char * poolAllocator;
  void *nameMem;
  int srcName;
  int srcNameData;
  char *nameText;
  undefined4 ctorAlloc [7];
  
  srcName = *(int *)(symbol + 4);
  *(undefined ***)this = &PTR___ZN7TSymbolD1Ev_a7b7d568;
  srcNameData = *(int *)(srcName + 4);
  *(undefined1 *)(srcNameData + *(int *)(srcNameData + -0xc)) = *stringTerminalPtr_a7b7ba80;
  nameText = *(char **)(srcName + 4);
  poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
  nameMem = (void *)TPoolAllocator__allocate(poolAllocator,8);
  newName = (void *)0x0;
  if (nameMem != (void *)0x0) {
    ctorAlloc[0] = GetGlobalPoolAllocator();
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_(nameMem,nameText,(unsigned char *)ctorAlloc);
    newName = nameMem;
  }
  uniqueId = *(undefined4 *)(symbol + 8);
  *(void **)((int)this + 4) = newName;
  *(undefined4 *)((int)this + 8) = uniqueId;
  return;
}

/* __ZN9TVariableC2ERKS_RSt3mapIP7TVectorI9TTypeLineES6_St4lessIS6_ESaISt4pairIKS6_S6_EEE @ 0x97ba2fac (4 bytes) */
int __ZN9TVariableC2ERKS_RSt3mapIP7TVectorI9TTypeLineES6_St4lessIS6_ESaISt4pairIKS6_S6_EEE(this, variable, map)
  void *this;
  unsigned char * variable;
  unsigned char * map;
{
  int nominalSize;
  int srcUnionArray;
  uint copyScratch;
  int arrayInformationType;
  unsigned char * poolAllocator;
  undefined4 *unionArray;
  undefined4 assertLine;
  char *assertText;
  
  ((int (*)())__ZN7TSymbolC2ERKS_)(this,(unsigned char *)variable);
  *(int *)this = DAT_a7b7ba78 + 8;
  *(undefined ***)((int)this + 0xc) = &PTR___ZN5TTypeD1Ev_a7b7d590;
  TType__copyType((unsigned char *)((int)this + 0xc),(unsigned char *)(variable + 0xc),map);
  arrayInformationType = *(int *)(variable + 0x3c);
  copyScratch = *(uint *)(variable + 0x34);
  *(uint *)((int)this + 0x34) = copyScratch;
  if (arrayInformationType == 0) {
    srcUnionArray = *(int *)(variable + 0x38);
    *(undefined4 *)((int)this + 0x3c) = 0;
    copyScratch = 0;
    if (srcUnionArray == 0) goto storeThis;
    copyScratch = *(uint *)(variable + 0x14);
    if (copyScratch == 0) {
      copyScratch = *(uint *)(variable + 0x30);
      if ((copyScratch & 0x400) == 0) {
        copyScratch = (int)(copyScratch << 0xd | copyScratch >> 0x13) >> 0x18;
      }
      else {
        nominalSize = (int)(copyScratch << 0xd | copyScratch >> 0x13) >> 0x18;
        copyScratch = nominalSize * nominalSize;
      }
      if (copyScratch == 1) {
        poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
        unionArray = (undefined4 *)TPoolAllocator__allocate(poolAllocator,4);
        *(undefined4 **)((int)this + 0x38) = unionArray;
        copyScratch = *(uint *)((int)this + 0x30) >> 0x13 & 0x3f;
        if (copyScratch == 2) {
loopStoreUnionArray:
          *unionArray = **(undefined4 **)(variable + 0x38);
          return;
        }
        if (copyScratch < 3) {
          if (copyScratch == 1) {
            *unionArray = **(undefined4 **)(variable + 0x38);
            return;
          }
        }
        else if (copyScratch == 3) goto loopStoreUnionArray;
        assertText = "false && \"Unknown type\"";
        assertLine = 0xb9;
      }
      else {
        assertText = "copyOf.type.getInstanceSize() == 1";
        assertLine = 0xb2;
      }
    }
    else {
      assertText = "!copyOf.type.getStruct()";
      assertLine = 0xb1;
    }
  }
  else {
    assertText = "copyOf.arrayInformationType == 0";
    assertLine = 0xad;
  }
  ___eprintf("%s:%u: failed assertion `%s\'\n",
             "/SourceCache/OpenGL/OpenGL-4.7.14/GLProgrammability/glslang/MachineIndependent/SymbolTable.cpp"
             ,assertLine,assertText);
storeThis:
  *(uint *)((int)this + 0x38) = copyScratch;
  return;
}

/* __ZN9TVariableC1ERKS_RSt3mapIP7TVectorI9TTypeLineES6_St4lessIS6_ESaISt4pairIKS6_S6_EEE @ 0x97ba2fb0 (4 bytes) */
int __ZN9TVariableC1ERKS_RSt3mapIP7TVectorI9TTypeLineES6_St4lessIS6_ESaISt4pairIKS6_S6_EEE(this, variable, map)
  void *this;
  unsigned char * variable;
  unsigned char * map;
{
  int nominalSize;
  int srcUnionArray;
  uint copyScratch;
  int arrayInformationType;
  unsigned char * poolAllocator;
  undefined4 *unionArray;
  undefined4 assertLine;
  char *assertText;
  
  ((int (*)())__ZN7TSymbolC2ERKS_)(this,(unsigned char *)variable);
  *(int *)this = DAT_a7b7ba78 + 8;
  *(undefined ***)((int)this + 0xc) = &PTR___ZN5TTypeD1Ev_a7b7d590;
  TType__copyType((unsigned char *)((int)this + 0xc),(unsigned char *)(variable + 0xc),map);
  arrayInformationType = *(int *)(variable + 0x3c);
  copyScratch = *(uint *)(variable + 0x34);
  *(uint *)((int)this + 0x34) = copyScratch;
  if (arrayInformationType == 0) {
    srcUnionArray = *(int *)(variable + 0x38);
    *(undefined4 *)((int)this + 0x3c) = 0;
    copyScratch = 0;
    if (srcUnionArray == 0) goto storeThis;
    copyScratch = *(uint *)(variable + 0x14);
    if (copyScratch == 0) {
      copyScratch = *(uint *)(variable + 0x30);
      if ((copyScratch & 0x400) == 0) {
        copyScratch = (int)(copyScratch << 0xd | copyScratch >> 0x13) >> 0x18;
      }
      else {
        nominalSize = (int)(copyScratch << 0xd | copyScratch >> 0x13) >> 0x18;
        copyScratch = nominalSize * nominalSize;
      }
      if (copyScratch == 1) {
        poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
        unionArray = (undefined4 *)TPoolAllocator__allocate(poolAllocator,4);
        *(undefined4 **)((int)this + 0x38) = unionArray;
        copyScratch = *(uint *)((int)this + 0x30) >> 0x13 & 0x3f;
        if (copyScratch == 2) {
loopStoreUnionArray:
          *unionArray = **(undefined4 **)(variable + 0x38);
          return;
        }
        if (copyScratch < 3) {
          if (copyScratch == 1) {
            *unionArray = **(undefined4 **)(variable + 0x38);
            return;
          }
        }
        else if (copyScratch == 3) goto loopStoreUnionArray;
        assertText = "false && \"Unknown type\"";
        assertLine = 0xb9;
      }
      else {
        assertText = "copyOf.type.getInstanceSize() == 1";
        assertLine = 0xb2;
      }
    }
    else {
      assertText = "!copyOf.type.getStruct()";
      assertLine = 0xb1;
    }
  }
  else {
    assertText = "copyOf.arrayInformationType == 0";
    assertLine = 0xad;
  }
  ___eprintf("%s:%u: failed assertion `%s\'\n",
             "/SourceCache/OpenGL/OpenGL-4.7.14/GLProgrammability/glslang/MachineIndependent/SymbolTable.cpp"
             ,assertLine,assertText);
storeThis:
  *(uint *)((int)this + 0x38) = copyScratch;
  return;
}

/* __ZN9TVariableC4ERKS_RSt3mapIP7TVectorI9TTypeLineES6_St4lessIS6_ESaISt4pairIKS6_S6_EEE @ 0x97ba2fb4 (432 bytes) */
int __ZN9TVariableC4ERKS_RSt3mapIP7TVectorI9TTypeLineES6_St4lessIS6_ESaISt4pairIKS6_S6_EEE(this, variable, map)
  void *this;
  unsigned char * variable;
  unsigned char * map;
{
  int nominalSize;
  int srcUnionArray;
  uint copyScratch;
  int arrayInformationType;
  unsigned char * poolAllocator;
  undefined4 *unionArray;
  undefined4 assertLine;
  char *assertText;
  
  ((int (*)())__ZN7TSymbolC2ERKS_)(this,(unsigned char *)variable);
  *(int *)this = DAT_a7b7ba78 + 8;
  *(undefined ***)((int)this + 0xc) = &PTR___ZN5TTypeD1Ev_a7b7d590;
  TType__copyType((unsigned char *)((int)this + 0xc),(unsigned char *)(variable + 0xc),map);
  arrayInformationType = *(int *)(variable + 0x3c);
  copyScratch = *(uint *)(variable + 0x34);
  *(uint *)((int)this + 0x34) = copyScratch;
  if (arrayInformationType == 0) {
    srcUnionArray = *(int *)(variable + 0x38);
    *(undefined4 *)((int)this + 0x3c) = 0;
    copyScratch = 0;
    if (srcUnionArray == 0) goto storeThis;
    copyScratch = *(uint *)(variable + 0x14);
    if (copyScratch == 0) {
      copyScratch = *(uint *)(variable + 0x30);
      if ((copyScratch & 0x400) == 0) {
        copyScratch = (int)(copyScratch << 0xd | copyScratch >> 0x13) >> 0x18;
      }
      else {
        nominalSize = (int)(copyScratch << 0xd | copyScratch >> 0x13) >> 0x18;
        copyScratch = nominalSize * nominalSize;
      }
      if (copyScratch == 1) {
        poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
        unionArray = (undefined4 *)TPoolAllocator__allocate(poolAllocator,4);
        *(undefined4 **)((int)this + 0x38) = unionArray;
        copyScratch = *(uint *)((int)this + 0x30) >> 0x13 & 0x3f;
        if (copyScratch == 2) {
loopStoreUnionArray:
          *unionArray = **(undefined4 **)(variable + 0x38);
          return;
        }
        if (copyScratch < 3) {
          if (copyScratch == 1) {
            *unionArray = **(undefined4 **)(variable + 0x38);
            return;
          }
        }
        else if (copyScratch == 3) goto loopStoreUnionArray;
        assertText = "false && \"Unknown type\"";
        assertLine = 0xb9;
      }
      else {
        assertText = "copyOf.type.getInstanceSize() == 1";
        assertLine = 0xb2;
      }
    }
    else {
      assertText = "!copyOf.type.getStruct()";
      assertLine = 0xb1;
    }
  }
  else {
    assertText = "copyOf.arrayInformationType == 0";
    assertLine = 0xad;
  }
  ___eprintf("%s:%u: failed assertion `%s\'\n",
             "/SourceCache/OpenGL/OpenGL-4.7.14/GLProgrammability/glslang/MachineIndependent/SymbolTable.cpp"
             ,assertLine,assertText);
storeThis:
  *(uint *)((int)this + 0x38) = copyScratch;
  return;
}

/* TVariable__clone @ 0x97ba3164 (76 bytes) */
int TVariable__clone(this, map)
  unsigned char * this;
  unsigned char * map;
{
  unsigned char *poolAllocator;
  void *clone;
  
  poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
  clone = (void *)TPoolAllocator__allocate(poolAllocator,0x40);
  ((int (*)())__ZN9TVariableC1ERKS_RSt3mapIP7TVectorI9TTypeLineES6_St4lessIS6_ESaISt4pairIKS6_S6_EEE)(clone,this,map);
  return clone;
}

/* __ZN9TFunctionC2ERKS_RSt3mapIP7TVectorI9TTypeLineES6_St4lessIS6_ESaISt4pairIKS6_S6_EEE @ 0x97ba31b0 (4 bytes) */
int __ZN9TFunctionC2ERKS_RSt3mapIP7TVectorI9TTypeLineES6_St4lessIS6_ESaISt4pairIKS6_S6_EEE(this, function, map)
  void *this;
  unsigned char * function;
  unsigned char * map;
{
  int finishPtr;
  int newFinish;
  undefined4 poolAllocator2;
  undefined1 *nulCharPtr;
  int *emptyRepRefCount;
  void *nameString;
  undefined4 field4c;
  unsigned char * poolAllocator;
  void *nameStrMem;
  unsigned char * paramType;
  int srcParams;
  undefined4 *paramFinish;
  int emptyRep;
  int srcNameData;
  int srcParamName;
  uint paramIdx;
  char *nameText;
  unsigned char * srcParamType;
  char reservation;
  byte cr0Reg;
  undefined4 emptyParamName;
  undefined4 emptyParamType;
  undefined4 stringAllocator [4];
  
  ((int (*)())__ZN7TSymbolC2ERKS_)(this,(unsigned char *)function);
  *(int *)this = DAT_a7b7ba7c + 8;
  poolAllocator2 = GetGlobalPoolAllocator();
  *(undefined4 *)((int)this + 0xc) = poolAllocator2;
  emptyRep = DAT_a7b7ba74;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  emptyRepRefCount = (int *)(emptyRep + 8);
  *(undefined ***)((int)this + 0x1c) = &PTR___ZN5TTypeD1Ev_a7b7d590;
  do {
    if (reservation != '\0') {
      srcParams = storeWordConditionalIndexed(*emptyRepRefCount + 1,0,emptyRepRefCount);
      *emptyRepRefCount = srcParams;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  poolAllocator2 = GetGlobalPoolAllocator();
  *(undefined4 *)((int)this + 0x44) = poolAllocator2;
  *(int *)((int)this + 0x48) = emptyRep + 0xc;
  nulCharPtr = stringTerminalPtr_a7b7ba80;
  for (paramIdx = 0; paramIdx < (uint)(*(int *)(function + 0x14) - *(int *)(function + 0x10) >> 3);
      paramIdx = paramIdx + 1) {
    paramFinish = *(undefined4 **)((int)this + 0x14);
    if (paramFinish == *(undefined4 **)((int)this + 0x18)) {
      std__vector_TParameter_pool_allocator_TParameter_____M_insert_aux
                ((int)this + 0xc,*(undefined4 *)((int)this + 0x14),&emptyParamName);
    }
    else {
      newFinish = 0;
      if (paramFinish != (undefined4 *)0x0) {
        paramFinish[1] = emptyParamType;
        *paramFinish = emptyParamName;
        newFinish = *(int *)((int)this + 0x14);
      }
      *(int *)((int)this + 0x14) = newFinish + 8;
    }
    srcParams = *(int *)(function + 0x10);
    srcParamName = *(int *)(srcParams + paramIdx * 8);
    finishPtr = *(int *)((int)this + 0x14);
    srcNameData = *(int *)(srcParamName + 4);
    *(undefined1 *)(srcNameData + *(int *)(srcNameData + -0xc)) = *nulCharPtr;
    nameText = *(char **)(srcParamName + 4);
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    nameStrMem = (void *)TPoolAllocator__allocate(poolAllocator,8);
    nameString = (void *)0x0;
    if (nameStrMem != (void *)0x0) {
      stringAllocator[0] = GetGlobalPoolAllocator();
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                (nameStrMem,nameText,(unsigned char *)stringAllocator);
      nameString = nameStrMem;
    }
    *(void **)(finishPtr + -8) = nameString;
    srcParamType = *(unsigned char **)(srcParams + paramIdx * 8 + 4);
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    paramType = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x28);
    *(undefined ***)paramType = &PTR___ZN5TTypeD1Ev_a7b7d590;
    TType__copyType(paramType,srcParamType,map);
    *(unsigned char **)(finishPtr + -4) = paramType;
  }
  TType__copyType((unsigned char *)((int)this + 0x1c),(unsigned char *)(function + 0x1c),map);
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6assignERKS3_
            ((void *)((int)this + 0x44),(unsigned char *)(function + 0x44));
  field4c = *(undefined4 *)(function + 0x4c);
  *(undefined4 *)((int)this + 0x50) = *(undefined4 *)(function + 0x50);
  *(undefined4 *)((int)this + 0x4c) = field4c;
  return;
}

/* __ZN9TFunctionC1ERKS_RSt3mapIP7TVectorI9TTypeLineES6_St4lessIS6_ESaISt4pairIKS6_S6_EEE @ 0x97ba31b4 (4 bytes) */
int __ZN9TFunctionC1ERKS_RSt3mapIP7TVectorI9TTypeLineES6_St4lessIS6_ESaISt4pairIKS6_S6_EEE(this, function, map)
  void *this;
  unsigned char * function;
  unsigned char * map;
{
  int finishPtr;
  int newFinish;
  undefined4 poolAllocator2;
  undefined1 *nulCharPtr;
  int *emptyRepRefCount;
  void *nameString;
  undefined4 field4c;
  unsigned char * poolAllocator;
  void *nameStrMem;
  unsigned char * paramType;
  int srcParams;
  undefined4 *paramFinish;
  int emptyRep;
  int srcNameData;
  int srcParamName;
  uint paramIdx;
  char *nameText;
  unsigned char * srcParamType;
  char reservation;
  byte cr0Reg;
  undefined4 emptyParamName;
  undefined4 emptyParamType;
  undefined4 stringAllocator [4];
  
  ((int (*)())__ZN7TSymbolC2ERKS_)(this,(unsigned char *)function);
  *(int *)this = DAT_a7b7ba7c + 8;
  poolAllocator2 = GetGlobalPoolAllocator();
  *(undefined4 *)((int)this + 0xc) = poolAllocator2;
  emptyRep = DAT_a7b7ba74;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  emptyRepRefCount = (int *)(emptyRep + 8);
  *(undefined ***)((int)this + 0x1c) = &PTR___ZN5TTypeD1Ev_a7b7d590;
  do {
    if (reservation != '\0') {
      srcParams = storeWordConditionalIndexed(*emptyRepRefCount + 1,0,emptyRepRefCount);
      *emptyRepRefCount = srcParams;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  poolAllocator2 = GetGlobalPoolAllocator();
  *(undefined4 *)((int)this + 0x44) = poolAllocator2;
  *(int *)((int)this + 0x48) = emptyRep + 0xc;
  nulCharPtr = stringTerminalPtr_a7b7ba80;
  for (paramIdx = 0; paramIdx < (uint)(*(int *)(function + 0x14) - *(int *)(function + 0x10) >> 3);
      paramIdx = paramIdx + 1) {
    paramFinish = *(undefined4 **)((int)this + 0x14);
    if (paramFinish == *(undefined4 **)((int)this + 0x18)) {
      std__vector_TParameter_pool_allocator_TParameter_____M_insert_aux
                ((int)this + 0xc,*(undefined4 *)((int)this + 0x14),&emptyParamName);
    }
    else {
      newFinish = 0;
      if (paramFinish != (undefined4 *)0x0) {
        paramFinish[1] = emptyParamType;
        *paramFinish = emptyParamName;
        newFinish = *(int *)((int)this + 0x14);
      }
      *(int *)((int)this + 0x14) = newFinish + 8;
    }
    srcParams = *(int *)(function + 0x10);
    srcParamName = *(int *)(srcParams + paramIdx * 8);
    finishPtr = *(int *)((int)this + 0x14);
    srcNameData = *(int *)(srcParamName + 4);
    *(undefined1 *)(srcNameData + *(int *)(srcNameData + -0xc)) = *nulCharPtr;
    nameText = *(char **)(srcParamName + 4);
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    nameStrMem = (void *)TPoolAllocator__allocate(poolAllocator,8);
    nameString = (void *)0x0;
    if (nameStrMem != (void *)0x0) {
      stringAllocator[0] = GetGlobalPoolAllocator();
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                (nameStrMem,nameText,(unsigned char *)stringAllocator);
      nameString = nameStrMem;
    }
    *(void **)(finishPtr + -8) = nameString;
    srcParamType = *(unsigned char **)(srcParams + paramIdx * 8 + 4);
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    paramType = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x28);
    *(undefined ***)paramType = &PTR___ZN5TTypeD1Ev_a7b7d590;
    TType__copyType(paramType,srcParamType,map);
    *(unsigned char **)(finishPtr + -4) = paramType;
  }
  TType__copyType((unsigned char *)((int)this + 0x1c),(unsigned char *)(function + 0x1c),map);
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6assignERKS3_
            ((void *)((int)this + 0x44),(unsigned char *)(function + 0x44));
  field4c = *(undefined4 *)(function + 0x4c);
  *(undefined4 *)((int)this + 0x50) = *(undefined4 *)(function + 0x50);
  *(undefined4 *)((int)this + 0x4c) = field4c;
  return;
}

/* __ZN9TFunctionC4ERKS_RSt3mapIP7TVectorI9TTypeLineES6_St4lessIS6_ESaISt4pairIKS6_S6_EEE @ 0x97ba31b8 (492 bytes) */
int __ZN9TFunctionC4ERKS_RSt3mapIP7TVectorI9TTypeLineES6_St4lessIS6_ESaISt4pairIKS6_S6_EEE(this, function, map)
  void *this;
  unsigned char * function;
  unsigned char * map;
{
  int finishPtr;
  int newFinish;
  undefined4 poolAllocator2;
  undefined1 *nulCharPtr;
  int *emptyRepRefCount;
  void *nameString;
  undefined4 field4c;
  unsigned char * poolAllocator;
  void *nameStrMem;
  unsigned char * paramType;
  int srcParams;
  undefined4 *paramFinish;
  int emptyRep;
  int srcNameData;
  int srcParamName;
  uint paramIdx;
  char *nameText;
  unsigned char * srcParamType;
  char reservation;
  byte cr0Reg;
  undefined4 emptyParamName;
  undefined4 emptyParamType;
  undefined4 nameCtorAlloc [4];
  
  ((int (*)())__ZN7TSymbolC2ERKS_)(this,(unsigned char *)function);
  *(int *)this = DAT_a7b7ba7c + 8;
  poolAllocator2 = GetGlobalPoolAllocator();
  *(undefined4 *)((int)this + 0xc) = poolAllocator2;
  emptyRep = DAT_a7b7ba74;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  emptyRepRefCount = (int *)(emptyRep + 8);
  *(undefined ***)((int)this + 0x1c) = &PTR___ZN5TTypeD1Ev_a7b7d590;
  do {
    if (reservation != '\0') {
      srcParams = storeWordConditionalIndexed(*emptyRepRefCount + 1,0,emptyRepRefCount);
      *emptyRepRefCount = srcParams;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  poolAllocator2 = GetGlobalPoolAllocator();
  *(undefined4 *)((int)this + 0x44) = poolAllocator2;
  *(int *)((int)this + 0x48) = emptyRep + 0xc;
  nulCharPtr = stringTerminalPtr_a7b7ba80;
  for (paramIdx = 0; paramIdx < (uint)(*(int *)(function + 0x14) - *(int *)(function + 0x10) >> 3);
      paramIdx = paramIdx + 1) {
    paramFinish = *(undefined4 **)((int)this + 0x14);
    if (paramFinish == *(undefined4 **)((int)this + 0x18)) {
      std__vector_TParameter_pool_allocator_TParameter_____M_insert_aux
                ((unsigned char *)((int)this + 0xc),
                 *(undefined4 *)((int)this + 0x14),&emptyParamName);
    }
    else {
      newFinish = 0;
      if (paramFinish != (undefined4 *)0x0) {
        paramFinish[1] = emptyParamType;
        *paramFinish = emptyParamName;
        newFinish = *(int *)((int)this + 0x14);
      }
      *(int *)((int)this + 0x14) = newFinish + 8;
    }
    srcParams = *(int *)(function + 0x10);
    srcParamName = *(int *)(srcParams + paramIdx * 8);
    finishPtr = *(int *)((int)this + 0x14);
    srcNameData = *(int *)(srcParamName + 4);
    *(undefined1 *)(srcNameData + *(int *)(srcNameData + -0xc)) = *nulCharPtr;
    nameText = *(char **)(srcParamName + 4);
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    nameStrMem = (void *)TPoolAllocator__allocate(poolAllocator,8);
    nameString = (void *)0x0;
    if (nameStrMem != (void *)0x0) {
      nameCtorAlloc[0] = GetGlobalPoolAllocator();
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                (nameStrMem,nameText,(unsigned char *)nameCtorAlloc);
      nameString = nameStrMem;
    }
    *(void **)(finishPtr + -8) = nameString;
    srcParamType = *(unsigned char **)(srcParams + paramIdx * 8 + 4);
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    paramType = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x28);
    *(undefined ***)paramType = &PTR___ZN5TTypeD1Ev_a7b7d590;
    TType__copyType(paramType,srcParamType,map);
    *(unsigned char **)(finishPtr + -4) = paramType;
  }
  TType__copyType((unsigned char *)((int)this + 0x1c),(unsigned char *)(function + 0x1c),map);
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6assignERKS3_
            ((void *)((int)this + 0x44),(unsigned char *)(function + 0x44));
  field4c = *(undefined4 *)(function + 0x4c);
  *(undefined4 *)((int)this + 0x50) = *(undefined4 *)(function + 0x50);
  *(undefined4 *)((int)this + 0x4c) = field4c;
  return;
}

/* TFunction__clone @ 0x97ba33a4 (76 bytes) */
int TFunction__clone(this, map)
  unsigned char * this;
  unsigned char * map;
{
  unsigned char *poolAllocator;
  void *clone;
  
  poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
  clone = (void *)TPoolAllocator__allocate(poolAllocator,0x54);
  ((int (*)())__ZN9TFunctionC1ERKS_RSt3mapIP7TVectorI9TTypeLineES6_St4lessIS6_ESaISt4pairIKS6_S6_EEE)(clone,this,map);
  return clone;
}

/* TSymbolTableLevel__clone @ 0x97ba33f0 (352 bytes) */
int TSymbolTableLevel__clone(this, map)
  unsigned char * this;
  unsigned char * map;
{
  int headerOrNewRefCount;
  int *refCountPtr;
  int atomicStore;
  int oldRefCount;
  unsigned char * poolAllocator;
  undefined4 *newLevel;
  undefined4 *headerNode;
  int *clonedSymbol;
  unsigned char * symbolName;
  undefined4 *insertKeyPtr;
  undefined4 staleR6;
  undefined4 staleR7;
  undefined4 staleR8;
  char reservation;
  byte cr0Reg;
  int iter [4];
  int treeEnd;
  undefined4 insertIter;
  undefined4 unusedInsertWord;
  undefined4 insertResultAlloc;
  undefined4 insertResultData;
  undefined4 nameCopyAlloc;
  int nameCopyData;
  int *pairSymbol;
  undefined4 destroyAlloc [6];
  
  poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
  newLevel = (undefined4 *)TPoolAllocator__allocate(poolAllocator,0x10);
  poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
  newLevel[1] = 0;
  *newLevel = poolAllocator;
  headerNode = (undefined4 *)TPoolAllocator__allocate(poolAllocator,0x1c);
  newLevel[2] = 0;
  newLevel[1] = headerNode;
  *headerNode = 0;
  *(undefined4 *)(newLevel[1] + 4) = 0;
  *(undefined4 *)(newLevel[1] + 8) = newLevel[1];
  headerOrNewRefCount = newLevel[1];
  *(int *)(headerOrNewRefCount + 0xc) = headerOrNewRefCount;
  treeEnd = *(int *)(this + 4);
  iter[0] = *(int *)(treeEnd + 8);
  if (iter[0] != treeEnd) {
    do {
      clonedSymbol = (int *)(**(code **)(**(int **)(iter[0] + 0x18) + 0x18))
                                (*(int **)(iter[0] + 0x18),map,insertKeyPtr,staleR6,staleR7,staleR8,headerOrNewRefCount);
      unusedInsertWord = 0;
      symbolName = (unsigned char *)(**(code **)(*clonedSymbol + 8))(clonedSymbol);
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&nameCopyAlloc,symbolName);
      insertKeyPtr = &nameCopyAlloc;
      pairSymbol = clonedSymbol;
      std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&insertResultAlloc,newLevel,&nameCopyAlloc);
      insertIter = insertResultAlloc;
      refCountPtr = (int *)(nameCopyData + -4);
      unusedInsertWord = insertResultData;
      destroyAlloc[0] = nameCopyAlloc;
      do {
        oldRefCount = *refCountPtr;
        headerOrNewRefCount = oldRefCount + -1;
        if (reservation != '\0') {
          atomicStore = storeWordConditionalIndexed(headerOrNewRefCount,0,refCountPtr);
          *refCountPtr = atomicStore;
          cr0Reg = 2;
        }
      } while (!(bool)(cr0Reg >> 1 & 1));
      if (oldRefCount < 1) {
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                  ((unsigned char *)(nameCopyData + -0xc),destroyAlloc);
      }
      std___Rb_tree_base_iterator___M_increment((unsigned char *)iter);
      treeEnd = *(int *)(this + 4);
    } while (iter[0] != treeEnd);
  }
  return newLevel;
}

/* TSymbolTable__copyTable @ 0x97ba3550 (492 bytes) */
int TSymbolTable__copyTable(this, symbolTable)
  unsigned char * this;
  unsigned char * symbolTable;
{
  undefined *freeListPtr;
  int getenvResult;
  undefined4 atomicStore;
  undefined *forceNewPtr;
  int vecFinish;
  undefined4 *treeHeader;
  uint loopIndex;
  char reservation;
  byte cr0Reg;
  undefined4 *typeMap;
  int typeMapCount;
  undefined4 clonedLevel [5];
  
  forceNewPtr = PTR__S_force_new_a7b7c0e8;
  typeMap = (undefined4 *)0x0;
  if (*(int *)PTR__S_force_new_a7b7c0e8 == 0) {
    getenvResult = _getenv("GLIBCPP_FORCE_NEW");
    if (getenvResult == 0) {
      do {
        if (reservation != '\0') {
          atomicStore = storeWordConditionalIndexed(*(int *)forceNewPtr + -1,0,forceNewPtr);
          *(undefined4 *)forceNewPtr = atomicStore;
          cr0Reg = 2;
        }
      } while (!(bool)(cr0Reg >> 1 & 1));
    }
    else {
      do {
        if (reservation != '\0') {
          atomicStore = storeWordConditionalIndexed(*(int *)forceNewPtr + 1,0,forceNewPtr);
          *(undefined4 *)forceNewPtr = atomicStore;
          cr0Reg = 2;
        }
      } while (!(bool)(cr0Reg >> 1 & 1));
    }
  }
  freeListPtr = PTR__S_free_list_a7b7c0e4;
  if (*(int *)PTR__S_force_new_a7b7c0e8 < 1) {
    _pthread_mutex_lock(PTR__S_node_allocator_lock_a7b7c0e0);
    treeHeader = *(undefined4 **)(freeListPtr + 8);
    if (treeHeader == (undefined4 *)0x0) {
      treeHeader = (undefined4 *)std____default_alloc_template_true_0____S_refill(0x18);
    }
    else {
      *(undefined4 *)(freeListPtr + 8) = *treeHeader;
    }
    if (treeHeader == (undefined4 *)0x0) {
      std____throw_bad_alloc();
    }
    _pthread_mutex_unlock(PTR__S_node_allocator_lock_a7b7c0e0);
  }
  else {
    treeHeader = operator_new(0x18);
  }
  typeMapCount = 0;
  *treeHeader = 0;
  treeHeader[1] = 0;
  treeHeader[2] = treeHeader;
  treeHeader[3] = treeHeader;
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(symbolTable + 0xc);
  typeMap = treeHeader;
  for (loopIndex = 0; loopIndex < (uint)(*(int *)(symbolTable + 4) - *(int *)symbolTable >> 2); loopIndex = loopIndex + 1) {
    clonedLevel[0] = ((int (*)())TSymbolTableLevel__clone)(*(unsigned char **)(*(int *)symbolTable + loopIndex * 4),(unsigned char *)&typeMap);
    treeHeader = *(undefined4 **)(this + 4);
    if (treeHeader == *(undefined4 **)(this + 8)) {
      std__vector_TSymbolTableLevel__std__allocator_TSymbolTableLevel______M_insert_aux
                ((unsigned char *)this,treeHeader,
                 clonedLevel);
    }
    else {
      vecFinish = 0;
      if (treeHeader != (undefined4 *)0x0) {
        *treeHeader = clonedLevel[0];
        vecFinish = *(int *)(this + 4);
      }
      *(int *)(this + 4) = vecFinish + 4;
    }
  }
  if (typeMapCount != 0) {
    std___Rb_tree_TVector_TTypeLine___std__pair_TVector_TTypeLine__const_TVector_TTypeLine____std___Select1st_std__pair_TVector_TTypeLine__const_TVector_TTypeLine_____std__less_TVector_TTypeLine____std__allocator_std__pair_TVector_TTypeLine__const_TVector_TTypeLine________M_erase((unsigned char
                *)&typeMap,(unsigned char *)typeMap[1]);
    typeMap[2] = typeMap;
    typeMap[1] = 0;
    typeMap[3] = typeMap;
    typeMapCount = 0;
  }
  return std____default_alloc_template_true_0___deallocate(typeMap,0x18);
}

/* yyparse @ 0x97ba373c (34436 bytes) */
int yyparse(parseContext, scratchR4, scratchR5, scratchR6, scratchR7, scratchR8, scratchR9, scratchR10)
  void *parseContext;
  undefined4 scratchR4;
  char *scratchR5;
  char *scratchR6;
  char *scratchR7;
  undefined4 scratchR8;
  undefined *scratchR9;
  uint scratchR10;
{
  unsigned char *typeAt840Structure;
  unsigned char *pubCopy850Line;
  unsigned char *typeAt850Word18;
  unsigned char *typeAt840Word14;
  unsigned char *typeTmp1Word18OrPubLine;
  unsigned char *typeAt840ArraySize;
  int yylen;
  int yytoken;
  int fieldNameStr2;
  int foundSymbol;
  int aggregateNode3;
  int mangledNameStr;
  int nameString2;
  int paramIdx;
  int currentFunctionType;
  int loopDepth;
  int nodeLine2;
  int fieldByteOffset2;
  int newTypeArraySize;
  int levelsBytes;
  int typeNameStr2;
  int binaryNode;
  int levelsBegin;
  int emptyRep;
  int paramFinish;
  int levelsFinish;
  int finishPtr2;
  int stackNodeVtable;
  int objVtable;
  int errorCheckResult;
  int newMaxArraySize;
  int oldMaxArraySize;
  int constantUnionNode;
  int queryResult;
  int absConstant;
  int symbolQualifier;
  int srcEntryWord04;
  int *treeFinish2;
  int *currentFunctionObj;
  uint declaredFunction;
  int returnTypePtr;
  int paramByteOffset;
  int levelsFinish2;
  int bodyQuery;
  int paramCount;
  int mainNameCompare;
  int fieldNameStr3;
  int levelIdx;
  int *refCountPtr4;
  char *errorText;
  char *messageSource;
  uint declaredNameLen2;
  uint nodeOpArg;
  uint paramQualifierArg;
  uint *shorterLenPtr;
  uint *typeSpecifierInit;
  void *intermediateForBranch;
  void *poppedLevel;
  unsigned char *identifierString3;
  unsigned char *keyString;
  unsigned char *newDeclNode;
  unsigned char *loopBodyNode;
  undefined4 *treeFinish;
  undefined4 branchOp;
  undefined4 userTypeName;
  undefined4 indexValue;
  undefined4 picBaseArg;
  undefined4 mangledName;
  undefined4 staleR4Value;
  undefined4 indexOpCode;
  undefined4 lastLevel;
  unsigned char *indexConstant;
  unsigned char *typeBitsWord2;
  int paramQualifier2;
  int paramQualifier1;
  unsigned char *functionHeader;
  unsigned char *newTypeMem;
  unsigned char *staleR8Value;
  unsigned char *nodeSetTypeFunc;
  unsigned char *nodeVtable;
  undefined *aggregateVtable;
  undefined *functionVtable;
  undefined *variableVtable;
  unsigned char *terminalCharPtr;
  unsigned char *typeBitsWord;
  unsigned char *picBaseValue;
  unsigned char *typeList;
  unsigned char *typeWord20Value;
  unsigned char *typeNameStr;
  unsigned char *nullWord;
  unsigned char *functionTypeBitsWord;
  unsigned char *constructorIdentifierUserDefWord4;
  unsigned char *stackNodeWord4c;
  unsigned char *typeNameString;
  unsigned char *symbol;
  unsigned char *yyvalNodeReg;
  uint oldNodeTypeBits;
  uint oldTypeBits;
  uint oldFunctionTypeBits;
  undefined8 variableMem;
  char *typeTmp5ArraySizeCopy;
  char *msgText2;
  int *constantUnionNode2;
  int *statementListNode2;
  int newTypeWord20;
  unsigned char *constructorIdentifierUserDefWord8;
  uint whileLine;
  uint structDeclaratorWord14;
  uint identifierValue;
  uint identifierLine;
  uint parameterTypeSpecifierLine;
  uint functionHeaderWord10;
  uint findFunctionResultWord4c;
  uint basicType3;
  int newTypeWord8;
  int storeWordConditionalIndexedResult;
  uint isMatrix22;
  unsigned char *constructorIdentifierUserDefWordc;
  unsigned char *constructorIdentifierUserDefWord20;
  unsigned char *postfixExpressionNode2;
  unsigned char *constructorIdentifierUserDefWord10;
  unsigned char *constructorIdentifierUserDefWord1c;
  int newTypeWordc;
  char *msgText;
  char *identifierStringWord4;
  uint parameterDeclarationWord142;
  uint postfixExpressionNode;
  uint nominalSize3;
  int newNodeWord4;
  int newTypeWord10;
  unsigned char *leftBracketLine2;
  undefined4 scratchR5Word4;
  unsigned char *parameterDeclarationWord14;
  unsigned char *typeTmp1VtableAddr;
  unsigned char *typeTmp1VtableCopy;
  unsigned char *typeTmp1ArraySizeCopy2;
  unsigned char *typeTmp1StructureCopy2;
  unsigned char *stringMem;
  unsigned char *picBase2Copy2;
  int newTypeWord1c;
  unsigned char *yyvalTypeCopy;
  unsigned char *typeTmp1Word14Copy;
  unsigned char *typeMem;
  unsigned char *typeTmp1ArraySizeCopy;
  unsigned char *picBase2Copy;
  unsigned char *isVector2;
  unsigned char *typeTmp3StructureCopy;
  unsigned char *typeTmp1StructureCopy;
  unsigned char *isMatrix2;
  bool stillShared;
  bool isNullSize;
  char *errorLine;
  char *typeNameData;
  char *functionNameText;
  char *typeNameText;
  int *paramType;
  int *functionSymbol;
  int *fieldType;
  int *emptyRepRefCount;
  int *argType;
  int *aggregateNode;
  int *constUnionArray;
  int *symbolNode;
  int fieldByteOffset;
  int paramArray;
  int nameString;
  int levelEntry;
  int fieldNameStr;
  int finishPtr;
  int nodeLine;
  uint secondNameLen;
  uint yytableIndex;
  uint symbolTypeBits;
  uint aggregateLine;
  uint clearedTypeBits;
  uint shiftedTypeBits;
  uint constTypeBits;
  uint signMask;
  uint sizeFieldBits;
  int *refCountPtr2;
  int *refCountPtr3;
  int oldRefCount5;
  int oldRefCount4;
  int newRefCount4;
  int newRefCount5;
  int nextUniqueId2;
  unsigned char * addSymbolResult;
  undefined8 addBranchResult;
  unsigned char * addLoopResult;
  int levelsEnd;
  int voidError;
  int globalError;
  int executeInitializerResult;
  int parameterSamplerError;
  int reservedError2;
  undefined4 setStructSizeResult3;
  undefined8 setStructSizeResult2;
  int structQualifierError;
  int boolError;
  int lValueError2;
  unsigned char * findFunctionResult;
  int constructorError;
  int lValueError;
  unsigned char * parseVectorFieldsResult;
  int parseMatrixFieldsResult;
  unsigned char * setStructSizeResult;
  int arraySetMaxSizeResult;
  int nextUniqueId;
  int loopIndex4;
  uint functionPrototypeFunction;
  int stringData3;
  int stringData2;
  uint expressionNode;
  uint returnLine;
  int *statementListNode;
  int *typeSpecifierUserDef2;
  uint typeSpecifierSize4;
  uint loopIndex3;
  int *symbolTable2;
  int *newVariable;
  int extensionError;
  uint typeQualifierQualifier;
  unsigned char * typeSpecifierUserDef;
  unsigned char * typeSpecifierSize3;
  unsigned char * typeSpecifierType;
  unsigned char * typeSpecifierTypeLine2;
  unsigned char * typeSpecifierQualifier2;
  unsigned char * typeSpecifierTypeLine;
  unsigned char * typeSpecifierMatrix2;
  unsigned char * typeSpecifierSize2;
  unsigned char * typeSpecifierQualifier;
  uint sizeBits;
  uint basicTypeBits2;
  uint qualifierBits2;
  unsigned char * typeSpecifierMatrix;
  unsigned char * typeSpecifierSize;
  unsigned char * newType;
  unsigned char * fullySpecifiedTypeTypeLine;
  unsigned char * parameterDeclarationParamType2;
  uint parameterDeclarationParamType;
  uint functionHeaderWithParametersFunction;
  uint unaryOperatorOp;
  unsigned char * identifierString2;
  int reservedError;
  unsigned char * newRefCount3;
  unsigned char * oldRefCount3;
  uint constructorIdentifierUserDef;
  uint constructorIdentifierOp;
  unsigned char * newFunction;
  uint functionCallHeaderWithParametersFunction;
  uint functionCallHeaderFunction;
  uint functionCallGenericNode;
  int loopIndex2;
  unsigned char * newRefCount2;
  unsigned char * oldRefCount2;
  uint nominalSize2;
  uint basicType2;
  unsigned char * typeVtable3;
  int nominalSize;
  uint loopIndex;
  int basicType;
  unsigned char * typeVtable2;
  unsigned char * resultNode;
  int constantUnion2;
  unsigned char * typeVtable;
  int isArray;
  int qualifier;
  int constantUnion;
  int isMatrix;
  int isVector;
  char *leftBracketLine;
  uint newRefCount;
  uint oldRefCount;
  unsigned char * refCountPtr;
  int *symbolTable;
  uint basicTypeBits;
  uint qualifierBits;
  int stringData;
  uint identifierString;
  uint yyn;
  int yystateByteOffset;
  int yyssCopyBytes;
  int yysize;
  unsigned char * yyssBase;
  unsigned char * yyvsBase;
  short yypactEntry;
  uint oldVariableTypeBits;
  unsigned char *conditionNode;
  undefined4 *yyOutArgs;
  undefined4 yy_outargs[0x14];
  undefined *methodArg;
  int paramArrayBegin;
  unsigned char *newVariableNode;
  unsigned char *arrayOperand;
  unsigned char * this;
  unsigned char *constArray;
  unsigned char * stackNode;
  unsigned char * newString;
  unsigned char *destroyRep;
  unsigned char *operandTypePtr;
  void *stringMem2;
  unsigned char *typeListMem;
  unsigned char *intermediate;
  undefined4 staleR4Pass;
  unsigned char * poolAllocator;
  undefined4 *elementPtr;
  undefined4 *treeNodeMem;
  unsigned char *operandNode;
  int *newNode;
  unsigned char *mangledString;
  unsigned char *leftNode;
  void *fieldTypeName;
  unsigned char *aggregateNode2;
  undefined4 r4Out0;
  undefined4 r4Out1;
  undefined4 r4Out2;
  undefined4 r4Out3;
  undefined4 r4In0;
  undefined4 r4Out4;
  undefined4 r4Out5;
  undefined4 r4Out6;
  undefined4 r4In1;
  undefined4 r4In2;
  undefined4 r4In3;
  undefined4 r4In4;
  undefined4 r4In5;
  undefined4 r4In6;
  undefined4 r4Out7;
  undefined4 r4Out8;
  undefined4 r4In7;
  undefined4 r4Out9;
  undefined4 r4Out10;
  int *r4Out11;
  undefined4 r4In8;
  int *r4Out12;
  unsigned char ** destroyAllocArg;
  undefined4 r4Out13;
  undefined4 r4Out14;
  undefined4 r4In9;
  undefined4 r4Out15;
  undefined4 r4Out16;
  undefined4 r4In10;
  undefined4 r4In11;
  undefined4 r4In12;
  uint *elementEnd;
  undefined4 r4In13;
  int srcEntryWord20;
  undefined4 r4Out17;
  undefined4 r4Out18;
  undefined4 r4Out19;
  unsigned char *valueSlot;
  uint basicTypeBits3;
  char *errorLine2;
  int srcEntryWord1c;
  int r6Pass;
  char *emptyText;
  unsigned char *typeTmp3VtableReg;
  int r7Pass;
  unsigned char *typeTmp7VtableReg;
  unsigned char *nodeVtableWord;
  int r8Pass;
  unsigned char *staleR9Value;
  undefined **typeVtablePtr;
  bool foundMatch;
  int srcEntry;
  int srcEntryWord0c;
  int srcEntryWord08;
  code *nodeMethod;
  unsigned char * yystacksize;
  unsigned char * yyvs;
  int yyerrstatus;
  int yychar;
  unsigned char * yyss;
  unsigned char * yyssp;
  unsigned char * constructorIdentifierOp2;
  int yystate;
  undefined4 lastLevel2;
  int *paramEntry;
  unsigned char * symbolTable3;
  unsigned char * structDeclarationListTypeList;
  uint nameLenB;
  int qualifier1;
  int isVariable;
  unsigned char * yyvsp;
  uint basicTypeValue;
  uint matrixBit;
  unsigned char *slotArg;
  int paramList;
  int *callTarget;
  char *opName;
  char reservation;
  byte cr0;
  ulonglong yylexResult;
  undefined8 nodePair;
  unsigned char yyssBeforeInit [2];
  unsigned char yyssInit [400];
  unsigned char yyvsInit [8800];
  unsigned char yylval [48];
  uint yyval;
  undefined4 yyvalOp;
  unsigned char * yyvalNode;
  uint yyvalNode2;
  unsigned char * yyvalTypeOrFunction;
  unsigned char * yyvalQualifierOrParamType;
  unsigned char * yyvalSize;
  unsigned char * yyvalMatrix;
  unsigned char * yyvalArray;
  unsigned char * yyvalUserDef;
  unsigned char * yyvalTypeLine;
  unsigned char * typeTmp1VtableOrStr1Alloc;
  unsigned char * typeTmp1ArraySizeOrStr1Data;
  unsigned char * typeTmp1StructureOrPubSize;
  unsigned char * typeTmp1Word0cOrPubMatrix;
  unsigned char * typeTmp1TypeNameOrStr2Alloc;
  unsigned char * typeTmp1Word14OrStr2Data;
  unsigned char * typeTmp1MaxArraySize;
  unsigned char * typeTmp1Word20OrPubType;
  unsigned char * typeTmp1BitsOrPubQualifier;
  unsigned char * pubSize;
  unsigned char * pubMatrix;
  unsigned char * typeTmp2VtableOrPubArray;
  unsigned char * typeTmp2ArraySizeOrPubUserDef;
  unsigned char * typeTmp2StructureOrPubLine;
  unsigned char * typeTmp2Word0cOrPubMatrix2;
  unsigned char * typeTmp2TypeNameOrPubArray2;
  unsigned char * typeTmp2Word14OrPubUserDef2;
  unsigned char * typeTmp2Word18OrPubLine2;
  unsigned char * typeTmp2MaxArraySize;
  unsigned char * typeTmp2Word20OrPub3Type;
  unsigned char * typeTmp2BitsOrPub3Qualifier;
  unsigned char * pub3Size;
  unsigned char * pub3Matrix;
  unsigned char * typeTmp3VtableOrPub3Array;
  unsigned char * typeTmp3ArraySizeOrPub3UserDef;
  unsigned char * typeTmp3StructureOrPub3Line;
  unsigned char * typeTmp3Word0c;
  unsigned char * typeTmp3TypeNameOrTypeTmp4Vtable;
  unsigned char * typeTmp3Word14OrTypeTmp4ArraySize;
  unsigned char * typeTmp3Word18OrTypeTmp4Structure;
  unsigned char * typeTmp3MaxArraySizeOrTypeTmp4Word0c;
  unsigned char * typeTmp3Word20OrTypeTmp4TypeName;
  uint typeTmp3BitsOrTypeTmp4Word14;
  undefined4 typeStr3Alloc;
  uint typeTmp4BitsOrStr3Data;
  unsigned char * typeTmp5VtableOrStr4Alloc;
  char *typeTmp5ArraySizeOrStr4Data;
  unsigned char * typeTmp6Vtable;
  int typeTmp6ArraySize;
  int typeTmp6MaxArraySize;
  unsigned char * typeTmp7Vtable [4];
  unsigned char * typeTmp7TypeName;
  undefined4 ctorAlloc1 [4];
  unsigned char * destroyAlloc1 [4];
  undefined4 destroyAlloc2 [4];
  unsigned char * destroyAlloc3 [4];
  unsigned char * destroyAlloc4 [4];
  unsigned char * destroyAlloc5 [4];
  unsigned char * destroyAlloc6 [4];
  undefined4 ctorAlloc2 [4];
  unsigned char * destroyAlloc7 [4];
  undefined4 ctorAlloc3 [4];
  unsigned char * destroyAlloc8 [4];
  undefined4 ctorAlloc4 [4];
  unsigned char * functionPool;
  unsigned char * destroyAlloc9 [4];
  uint allocatorArg1;
  uint allocatorArg2;
  uint allocatorArg3;
  unsigned char * destroyAlloc10 [4];
  unsigned char * destroyAlloc11 [4];
  unsigned char * destroyAlloc12 [4];
  unsigned char * destroyAlloc13 [4];
  unsigned char * destroyAlloc14 [4];
  unsigned char * destroyAlloc15 [4];
  unsigned char * destroyAlloc16 [4];
  unsigned char * destroyAlloc17 [4];
  unsigned char * destroyAlloc18 [4];
  unsigned char * destroyAlloc19 [4];
  unsigned char * destroyAlloc20 [4];
  unsigned char * destroyAlloc21 [4];
  unsigned char * destroyAlloc22 [4];
  unsigned char * destroyAlloc23 [4];
  unsigned char * destroyAlloc24 [4];
  unsigned char * destroyAlloc25 [4];
  unsigned char * destroyAlloc26 [4];
  unsigned char * destroyAlloc27 [4];
  unsigned char * destroyAlloc28 [4];
  unsigned char * destroyAlloc29 [4];
  unsigned char * destroyAlloc30 [4];
  unsigned char * destroyAlloc31 [4];
  unsigned char * destroyAlloc32 [4];
  unsigned char * destroyAlloc33 [4];
  unsigned char * destroyAlloc34 [4];
  unsigned char * destroyAlloc35 [4];
  unsigned char * destroyAlloc36 [4];
  unsigned char * destroyAlloc37 [4];
  unsigned char * destroyAlloc38 [4];
  unsigned char * destroyAlloc39 [4];
  unsigned char * destroyAlloc40 [4];
  unsigned char * destroyAlloc41 [4];
  unsigned char * destroyAlloc42 [4];
  unsigned char * destroyAlloc43 [4];
  unsigned char * destroyAlloc44 [4];
  unsigned char * destroyAlloc45 [4];
  unsigned char * destroyAlloc46 [4];
  unsigned char * destroyAlloc47 [4];
  unsigned char * destroyAlloc48 [4];
  unsigned char * destroyAlloc49 [4];
  unsigned char * destroyAlloc50 [4];
  unsigned char * destroyAlloc51 [4];
  unsigned char * destroyAlloc52 [4];
  unsigned char * destroyAlloc53 [4];
  unsigned char * destroyAlloc54 [4];
  unsigned char * destroyAlloc55 [4];
  unsigned char * destroyAlloc56 [4];
  int levelFindIter [4];
  unsigned char * symbolKeyStrAlloc;
  int symbolKeyStrData;
  unsigned char * symbolValue;
  unsigned char * destroyAlloc57 [4];
  undefined4 ctorAlloc5 [4];
  unsigned char * destroyAlloc58 [4];
  undefined4 ctorAlloc6 [4];
  unsigned char * destroyAlloc59 [4];
  undefined4 ctorAlloc7 [4];
  uint allocatorArg4;
  undefined4 ctorAlloc8 [4];
  undefined4 ctorAlloc9 [4];
  unsigned char * destroyAlloc60 [4];
  undefined4 ctorAlloc10 [4];
  undefined4 ctorAlloc11 [4];
  undefined4 ctorAlloc12 [4];
  unsigned char * destroyAlloc61 [4];
  undefined4 ctorAlloc13 [4];
  undefined4 ctorAlloc14 [4];
  unsigned char * destroyAlloc62 [4];
  unsigned char * destroyAlloc63 [4];
  undefined4 variableKeyStrAlloc;
  int variableKeyStrData;
  int *variableValue;
  undefined4 destroyAlloc64 [4];
  undefined4 ctorAlloc15 [4];
  undefined4 ctorAlloc16 [4];
  unsigned char * destroyAlloc65 [4];
  unsigned char * destroyAlloc66 [4];
  undefined4 allocatorArg5;
  unsigned char * levelPool;
  undefined4 *destroyAlloc67 [4];
  unsigned char * loopPoolCopy;
  unsigned char * switchPoolCopy;
  unsigned char * nodePool;
  undefined4 allocatorArg6;
  undefined4 allocatorArg7;
  undefined4 allocatorArg8;
  undefined4 nodeKeyStrAlloc;
  int nodeKeyStrData;
  int *nodeValue;
  undefined4 destroyAlloc68 [4];
  undefined4 ctorAlloc17 [4];
  unsigned char * destroyAlloc69 [4];
  undefined4 ctorAlloc18 [4];
  unsigned char * destroyAlloc70 [4];
  uint declaredNameLen;
  uint existingNameLen;
  int outFlag;
  int callArgSlot;
  unsigned char * operandOut1;
  unsigned char * operandOut2;
  uint leftTextLen;
  uint rightTextLen;
  unsigned char * initializerNodeOut;
  int yyruleByteOffset;
  undefined *typeVtableAddr;
  unsigned char * picBase;
  unsigned char * yyssBytes;
  unsigned char * picBase2;
  int *paramVectorPtr;
  int picBaseConst;
  
  yyOutArgs = yy_outargs;
  yyvsp = yyvsInit;
  yystacksize = (unsigned char *)0xc8;
  yystate = 0;
  yyerrstatus = 0;
  yychar = -2;
  yyssp = yyssBeforeInit;
  yyssBytes = (unsigned char *)0x190;
  yyvs = yyvsp;
  yyss = yyssInit;
LAB_97ba3784:
  do {
    yyssp = yyssp + 2;
    *(short *)yyssp = (short)yystate;
    yyvsBase = yyvs;
    yyssBase = yyss;
    if (yyss + (int)yyssBytes + -2 <= yyssp) {
      yysize = ((int)yyssp - (int)yyss >> 1) + 1;
      if (9999 < (int)yystacksize) {
        yyerror("parser stack overflow",yyss,scratchR5,scratchR6,scratchR7,yyssBytes,scratchR9,scratchR10);
        return 2;
      }
      yystacksize = yyssBytes;
      if (10000 < (int)yyssBytes) {
        yystacksize = (unsigned char *)0x2710;
      }
      yyssBytes = (unsigned char *)((int)yystacksize * 2);
      yyssCopyBytes = yysize * 2;
      scratchR5 = (char *)(yysize * 0x2c);
      yyssBase = (unsigned char *)__builtin_alloca((uint)yyssBytes + 0x40);
      _memcpy(yyssBase,yyss,yyssCopyBytes);
      yyssp = yyssBase + yyssCopyBytes + -2;
      yyvsBase = (unsigned char *)__builtin_alloca((int)yystacksize * 0x2c + 0x40);
      yyvsp = yyvsBase + (int)scratchR5;
      _memcpy(yyvsBase,yyvs,scratchR5);
      yyvsp = yyvsp + -0x2c;
      scratchR4 = r4Out0;
      if (yyssBase + (int)yyssBytes + -2 <= yyssp) {
        return 1;
      }
    }
    yylexResult = CONCAT44(yychar,scratchR4);
    yystateByteOffset = yystate * 2;
    yypactEntry = (&_yypact)[yystate];
    staleR8Value = yyssBytes;
    yyvs = yyvsBase;
    yyss = yyssBase;
    if (yypactEntry == -0x8000) {
loopSetYyn:
      yyn = (uint)*(short *)(&_yydefact + yystateByteOffset);
      if (yyn != 0) goto setYyruleByteOffset;
loopCheckYyerrstatus:
      if (yyerrstatus == 0) {
        yyerror("parse error",scratchR4,scratchR5,scratchR6,scratchR7,staleR8Value,scratchR9,scratchR10);
        scratchR4 = r4Out18;
      }
loopCheckYyerrstatus2:
      if (yyerrstatus == 3) {
        if (yychar == 0) {
          return 1;
        }
        yychar = -2;
      }
      yyerrstatus = 3;
      do {
        if (((*(short *)((int)&_yypact + yystateByteOffset) != -0x8000) &&
            (yyn = (int)*(short *)((int)&_yypact + yystateByteOffset) + 1, yyn < 0x4f0)) &&
           (scratchR9 = (undefined *)(yyn * 2), *(short *)(&_yycheck + (int)scratchR9) == 1)) {
          yystate = (int)*(short *)(&_yytable + (int)scratchR9);
          if (yystate < 0) {
            if (yystate != -0x8000) goto setYyn;
          }
          else if (yystate != 0) {
            if (yystate == 0x14d) {
              return 0;
            }
            yyvsp = yyvsp + 0x2c;
            scratchR5 = (char *)0x2c;
            _memcpy(yyvsp,yylval,0x2c);
            scratchR4 = r4Out19;
            goto LAB_97ba3784;
          }
        }
        if (yyssp == yyssBase) {
          return 1;
        }
        yyssp = yyssp + -2;
        yyvsp = yyvsp + -0x2c;
        yystateByteOffset = (int)*(short *)yyssp << 1;
      } while( true );
    }
    if (yychar == -2) {
      yylexResult = ((int (*)())yylex)(yylval,parseContext);
    }
    yychar = (int)(yylexResult >> 0x20);
    scratchR4 = (undefined4)yylexResult;
    if ((longlong)yylexResult < 0x100000000) {
      yytoken = 0;
      yychar = 0;
    }
    else {
      yytoken = 0xa9;
      if (yylexResult < 0x15d00000000) {
        yytoken = (int)(char)(&_yytranslate)[yychar];
      }
    }
    yyn = yypactEntry + yytoken;
    if ((0x4ef < yyn) ||
       (scratchR9 = (undefined *)(yyn * 2), *(short *)(&_yycheck + (int)scratchR9) != yytoken))
    goto loopSetYyn;
    yystate = (int)*(short *)(&_yytable + (int)scratchR9);
    if (yystate < 0) {
      if (yystate != -0x8000) break;
      goto loopCheckYyerrstatus;
    }
    if (yystate == 0) goto loopCheckYyerrstatus;
    if (yystate == 0x14d) {
      return 0;
    }
    if (yychar != 0) {
      yychar = -2;
    }
    yyvsp = yyvsp + 0x2c;
    scratchR5 = (char *)0x2c;
    _memcpy(yyvsp,yylval,0x2c);
    scratchR4 = r4Out1;
    if (yyerrstatus != 0) {
      yyerrstatus = yyerrstatus + -1;
    }
  } while( true );
setYyn:
  yyn = -yystate;
setYyruleByteOffset:
  yyruleByteOffset = yyn * 2;
  yylen = (int)*(short *)(&_yyr2 + yyruleByteOffset);
  if (0 < yylen) {
    scratchR5 = (char *)0x2c;
    _memcpy(&yyval,yyvsp + (1 - yylen) * 0x2c,0x2c);
    scratchR4 = r4Out2;
  }
  yyvalNodeReg = yyvalNode;
  typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
  typeTmp7VtableReg = typeTmp7Vtable[0];
  if (0xd7 < yyn) goto switchD_97ba39c8_caseD_0;
  staleR9Value = (unsigned char *)(yyn * 4);
  slotArg = (unsigned char *)scratchR6;
  switch(yyn) {
  case 0:
    break;
  case 1:
    symbol = *(unsigned char **)(yyvsp + 8);
    if (symbol == (unsigned char *)0x0) {
      identifierString = *(uint *)(yyvsp + 4);
      picBase = (unsigned char *)0xa7b8374c;
      stringData = *(int *)(identifierString + 4);
      emptyText = "";
      msgText2 = "undeclared identifier";
      *(unsigned char *)(stringData + *(int *)(stringData + -0xc)) = *stringTerminalPtr_a7b7ba88;
      identifierStringWord4 = *(char **)(identifierString + 4);
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp,"undeclared identifier",identifierStringWord4,"",staleR8Value,stringData,
                 identifierString);
      TParseContext__recover(parseContext);
      picBase2 = (unsigned char *)0xa7b8374c;
      typeTmp1BitsOrPubQualifier = (unsigned char *)((uint)typeTmp1BitsOrPubQualifier & 0x1ff | 0x80800);
      typeTmp1VtableOrStr1Alloc = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
      typeTmp1ArraySizeOrStr1Data = symbol;
      typeTmp1StructureOrPubSize = symbol;
      typeTmp1Word0cOrPubMatrix = symbol;
      typeTmp1TypeNameOrStr2Alloc = symbol;
      typeTmp1Word14OrStr2Data = symbol;
      typeTmp1Word18OrPubLine = symbol;
      typeTmp1MaxArraySize = symbol;
      typeTmp1Word20OrPubType = symbol;
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      variableMem = TPoolAllocator__allocate(poolAllocator,0x40);
      newVariableNode = (unsigned char *)((ulonglong)variableMem >> 0x20);
      identifierString = *(uint *)(yyvsp + 4);
      variableVtable = PTR_vtable_a7b7c0b4 + 8;
      *(undefined ***)(newVariableNode + 0xc) = &PTR___ZN5TTypeD1Ev_a7b7d640;
      *(uint *)(newVariableNode + 4) = identifierString;
      *(undefined **)newVariableNode = variableVtable;
      *(unsigned char **)(newVariableNode + 0x10) = typeTmp1ArraySizeOrStr1Data;
      *(unsigned char **)(newVariableNode + 0x14) = typeTmp1StructureOrPubSize;
      *(unsigned char **)(newVariableNode + 0x18) = typeTmp1Word0cOrPubMatrix;
      *(unsigned char **)(newVariableNode + 0x1c) = typeTmp1TypeNameOrStr2Alloc;
      *(unsigned char **)(newVariableNode + 0x20) = typeTmp1Word14OrStr2Data;
      *(unsigned char **)(newVariableNode + 0x24) = typeTmp1Word18OrPubLine;
      *(unsigned char **)(newVariableNode + 0x28) = typeTmp1MaxArraySize;
      *(unsigned char **)(newVariableNode + 0x2c) = typeTmp1Word20OrPubType;
      oldVariableTypeBits = *(uint *)(newVariableNode + 0x30);
      qualifierBits = (uint)typeTmp1BitsOrPubQualifier & 0xfe000000;
      *(uint *)(newVariableNode + 0x30) = qualifierBits | oldVariableTypeBits & 0x1ffffff;
      basicTypeBits = ((uint)typeTmp1BitsOrPubQualifier >> 0x13 & 0x3f) << 0x13;
      *(uint *)(newVariableNode + 0x30) = basicTypeBits | qualifierBits | oldVariableTypeBits & 0x7ffff;
      sizeFieldBits = (uint)typeTmp1BitsOrPubQualifier & 0x7f800;
      *(uint *)(newVariableNode + 0x30) = sizeFieldBits | basicTypeBits | qualifierBits | oldVariableTypeBits & 0x7ff;
      matrixBit = ((uint)typeTmp1BitsOrPubQualifier >> 10 & 1) << 10;
      *(uint *)(newVariableNode + 0x30) = matrixBit | sizeFieldBits | basicTypeBits | qualifierBits | oldVariableTypeBits & 0x3ff;
      *(uint *)(newVariableNode + 0x30) =
           ((uint)typeTmp1BitsOrPubQualifier >> 9 & 1) << 9 | matrixBit | sizeFieldBits | basicTypeBits | qualifierBits | oldVariableTypeBits & 0x1ff;
      *(uint *)(newVariableNode + 0x34) = 0;
      *(uint *)(newVariableNode + 0x38) = 0;
      *(uint *)(newVariableNode + 0x3c) = 0;
      symbolTable = *(int **)((int)parseContext + 4);
      nextUniqueId = symbolTable[3];
      symbolTable[3] = nextUniqueId + 1U;
      *(uint *)(newVariableNode + 8) = nextUniqueId + 1U;
      lastLevel = *(undefined4 *)(*symbolTable + ((symbolTable[1] - *symbolTable & 0xfffffffcU) - 4));
      typeTmp2ArraySizeOrPubUserDef = symbol;
      keyString = (unsigned char *)
                (**(code **)(*(uint *)newVariableNode + 8))
                          (newVariableNode,(int)variableMem,msgText2,identifierStringWord4,emptyText,staleR8Value,symbolTable);
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&typeTmp2Word20OrPub3Type,keyString);
      pub3Size = newVariableNode;
      std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&typeTmp2TypeNameOrPubArray2,lastLevel,&typeTmp2Word20OrPub3Type);
      typeTmp2VtableOrPubArray = typeTmp2TypeNameOrPubArray2;
      refCountPtr = typeTmp2BitsOrPub3Qualifier + -4;
      typeTmp2ArraySizeOrPubUserDef = typeTmp2Word14OrPubUserDef2;
      typeTmp3VtableOrPub3Array = typeTmp2Word20OrPub3Type;
      do {
        oldRefCount = *(uint *)refCountPtr;
        if (reservation != '\0') {
          newRefCount = storeWordConditionalIndexed(oldRefCount - 1,0,refCountPtr);
          *(uint *)refCountPtr = newRefCount;
          cr0 = 2;
        }
      } while (!(bool)(cr0 >> 1 & 1));
      if ((int)oldRefCount < 1) {
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                  ((unsigned char *)(typeTmp2BitsOrPub3Qualifier + -0xc),&typeTmp3VtableOrPub3Array);
      }
      typeTmp1VtableOrStr1Alloc = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
      symbol = newVariableNode;
    }
    else {
      isVariable = (**(code **)(*(unsigned char **)symbol + 0x10))(symbol);
      if (isVariable == 0) {
        identifierString = *(uint *)(yyvsp + 4);
        picBase = (unsigned char *)0xa7b8374c;
        stringData = *(int *)(identifierString + 4);
        *(unsigned char *)(stringData + *(int *)(stringData + -0xc)) = *stringTerminalPtr_a7b7ba88;
        TParseContext__error
                  ((int)parseContext,*(char **)yyvsp,"variable expected",*(char **)(identifierString + 4),"",
                   staleR8Value,stringData,identifierString);
        TParseContext__recover(parseContext);
      }
    }
    scratchR6 = (char *)(symbol + 0xc);
    symbolQualifier = (**(code **)(*(uint *)(symbol + 0xc) + 0x24))(scratchR6);
    if (symbolQualifier != 2) {
      scratchR7 = *(char **)yyvsp;
      yyvalNodeReg = (unsigned char *)
               TIntermediate__addSymbol
                         (*(unsigned char **)parseContext,*(uint *)(symbol + 8),*(unsigned char **)(symbol + 4),
                          (unsigned char *)scratchR6,(int)scratchR7);
      typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
      typeTmp7VtableReg = typeTmp7Vtable[0];
      break;
    }
    typeTmp1ArraySizeOrStr1Data = *(unsigned char **)(symbol + 0x10);
    typeTmp1Word0cOrPubMatrix = *(unsigned char **)(symbol + 0x18);
    typeTmp1TypeNameOrStr2Alloc = *(unsigned char **)(symbol + 0x1c);
    typeTmp1StructureOrPubSize = *(unsigned char **)(symbol + 0x14);
    typeTmp1Word14OrStr2Data = *(unsigned char **)(symbol + 0x20);
    typeTmp1Word18OrPubLine = *(unsigned char **)(symbol + 0x24);
    scratchR7 = *(char **)(symbol + 0x28);
    typeTmp1Word20OrPubType = *(unsigned char **)(symbol + 0x2c);
    constArray = *(unsigned char **)(symbol + 0x38);
    typeTmp1BitsOrPubQualifier = (unsigned char *)
                ((*(uint *)(symbol + 0x30) >> 9 & 1) << 9 |
                (*(uint *)(symbol + 0x30) >> 10 & 1) << 10 |
                *(uint *)(symbol + 0x30) & 0x7f800 |
                (*(uint *)(symbol + 0x30) >> 0x13 & 0x3f) << 0x13 |
                *(uint *)(symbol + 0x30) & 0xfe000000 | (uint)typeTmp1BitsOrPubQualifier & 0x1ff);
    typeTmp1MaxArraySize = (unsigned char *)scratchR7;
loopSetTypeTmp1VtableOrStr1Alloc:
    typeTmp1VtableOrStr1Alloc = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
    intermediate = *(unsigned char **)parseContext;
    scratchR6 = *(char **)yyvsp;
    goto setTypeTmp1VtableCopy;
  default:
    goto yynCase2;
  case 3:
    signMask = (int)*(uint *)(yyvsp + 4) >> 0x1f;
    absConstant = (signMask ^ *(uint *)(yyvsp + 4)) - signMask;
    if (0xffff < absConstant) {
      scratchR7 = "";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," integer constant overflow","","",signMask,absConstant,
                 scratchR10);
      TParseContext__recover(parseContext);
    }
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    constArray = (unsigned char *)TPoolAllocator__allocate(poolAllocator,4);
    *(uint *)constArray = *(uint *)(yyvsp + 4);
    typeTmp1BitsOrPubQualifier = (unsigned char *)((uint)typeTmp1BitsOrPubQualifier & 0x9ff | 0x4100800);
    typeTmp1ArraySizeOrStr1Data = (unsigned char *)0x0;
    typeTmp1StructureOrPubSize = (unsigned char *)0x0;
    typeTmp1Word0cOrPubMatrix = (unsigned char *)0x0;
    typeTmp1TypeNameOrStr2Alloc = (unsigned char *)0x0;
    typeTmp1Word14OrStr2Data = (unsigned char *)0x0;
    typeTmp1Word18OrPubLine = (unsigned char *)0x0;
    typeTmp1MaxArraySize = (unsigned char *)0x0;
    typeTmp1Word20OrPubType = (unsigned char *)0x0;
    goto loopSetTypeTmp1VtableOrStr1Alloc;
  case 4:
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    constArray = (unsigned char *)TPoolAllocator__allocate(poolAllocator,4);
    *(uint *)constArray = *(uint *)(yyvsp + 4);
    constTypeBits = (uint)typeTmp1BitsOrPubQualifier & 0x7ff | 0x4080000;
    goto setTypeTmp1BitsOrPubQualifier;
  case 5:
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    constArray = (unsigned char *)TPoolAllocator__allocate(poolAllocator,4);
    *(uint *)constArray = *(uint *)(yyvsp + 4);
    picBase2 = (unsigned char *)0xa7b8374c;
    constTypeBits = (uint)typeTmp1BitsOrPubQualifier & 0x1807ff | 0x4180000;
setTypeTmp1BitsOrPubQualifier:
    typeTmp1BitsOrPubQualifier = (unsigned char *)(constTypeBits & 0xfffff9ff | 0x800);
    typeTmp1Word20OrPubType = (unsigned char *)0x0;
    typeTmp1ArraySizeOrStr1Data = (unsigned char *)0x0;
    typeTmp1StructureOrPubSize = (unsigned char *)0x0;
    typeTmp1Word0cOrPubMatrix = (unsigned char *)0x0;
    typeTmp1TypeNameOrStr2Alloc = (unsigned char *)0x0;
    typeTmp1Word14OrStr2Data = (unsigned char *)0x0;
    typeTmp1Word18OrPubLine = (unsigned char *)0x0;
    typeTmp1MaxArraySize = (unsigned char *)0x0;
    goto loopSetTypeTmp1VtableOrStr1Alloc;
  case 6:
  case 0xbb:
    goto yynCase6;
  case 8:
    queryResult = (**(code **)(**(int **)(yyvsp + -0x7c) + 0x54))
                       (*(int **)(yyvsp + -0x7c),scratchR4,scratchR5,scratchR6,scratchR7,staleR8Value);
    if (((queryResult == 0) &&
        (queryResult = (**(code **)(**(int **)(yyvsp + -0x7c) + 0x50))(*(int **)(yyvsp + -0x7c)),
        queryResult == 0)) &&
       (queryResult = (**(code **)(**(int **)(yyvsp + -0x7c) + 0x58))(*(int **)(yyvsp + -0x7c)),
       queryResult == 0)) {
      queryResult = (**(code **)(**(int **)(yyvsp + -0x7c) + 0x28))(*(int **)(yyvsp + -0x7c));
      if (queryResult == 0) {
        leftBracketLine = *(char **)(yyvsp + -0x58);
        scratchR6 = "expression";
      }
      else {
        picBase = (unsigned char *)0xa7b8374c;
        symbolNode = (int *)(**(code **)(**(int **)(yyvsp + -0x7c) + 0x28))
                                   (*(int **)(yyvsp + -0x7c));
        queryResult = (**(code **)(*symbolNode + 0x60))(symbolNode);
        staleR9Value = *(unsigned char **)(queryResult + 4);
        staleR9Value[*(uint *)(staleR9Value + -0xc)] = **(unsigned char **)(picBase + -0x7cc4);
        scratchR6 = *(char **)(queryResult + 4);
        leftBracketLine = *(char **)(yyvsp + -0x58);
        staleR8Value = picBase;
      }
      scratchR5 = " left of \'[\' is not of type array, matrix, or vector ";
      scratchR7 = "";
      TParseContext__error
                ((int)parseContext,leftBracketLine," left of \'[\' is not of type array, matrix, or vector ",
                 scratchR6,"",staleR8Value,staleR9Value,scratchR10);
      TParseContext__recover(parseContext);
    }
    foundMatch = false;
    (**(code **)(**(int **)(yyvsp + -0x7c) + 0x38))(&typeTmp1VtableOrStr1Alloc,*(int **)(yyvsp + -0x7c));
    if ((((uint)typeTmp1BitsOrPubQualifier >> 0x19 == 2) &&
        (queryResult = (**(code **)(**(int **)(yyvsp + -0x7c) + 0x54))(*(int **)(yyvsp + -0x7c)),
        queryResult == 0)) &&
       (queryResult = (**(code **)(**(int **)(yyvsp + -0x24) + 0x44))(*(int **)(yyvsp + -0x24)),
       queryResult == 2)) {
      foundMatch = true;
    }
    picBase2 = (unsigned char *)0xa7b8374c;
    typeTmp1VtableOrStr1Alloc = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
    if (foundMatch) {
      isVector = (**(code **)(**(int **)(yyvsp + -0x7c) + 0x58))(*(int **)(yyvsp + -0x7c));
      if (isVector == 0) {
        isMatrix = (**(code **)(**(int **)(yyvsp + -0x7c) + 0x50))(*(int **)(yyvsp + -0x7c));
        nodePair = CONCAT44(yyvalNode,r4Out3);
        if (isMatrix != 0) {
          constantUnion = (**(code **)(**(int **)(yyvsp + -0x24) + 0x18))(*(int **)(yyvsp + -0x24));
          scratchR5 = *(char **)(yyvsp + -0x7c);
          scratchR6 = *(char **)(yyvsp + -0x58);
          nodePair = TParseContext__addConstMatrixNode
                             (parseContext,**(int **)(constantUnion + 0x30),(unsigned char *)scratchR5,(int)scratchR6
                             );
        }
      }
      else {
        typeTmp2TypeNameOrPubArray2 = (unsigned char *)0x1;
        constantUnion = (**(code **)(**(int **)(yyvsp + -0x24) + 0x18))(*(int **)(yyvsp + -0x24));
        typeTmp2VtableOrPubArray = (unsigned char *)**(uint **)(constantUnion + 0x30);
        scratchR5 = *(char **)(yyvsp + -0x7c);
        scratchR6 = *(char **)(yyvsp + -0x58);
        nodePair = TParseContext__addConstVectorNode
                           (parseContext,(unsigned char *)&typeTmp2VtableOrPubArray,(unsigned char *)scratchR5,(int)scratchR6
                            ,scratchR7,staleR8Value);
      }
    }
    else {
      qualifier = (**(code **)(**(int **)(yyvsp + -0x24) + 0x44))(*(int **)(yyvsp + -0x24));
      if (qualifier == 2) {
        foundMatch = false;
        queryResult = (**(code **)(**(int **)(yyvsp + -0x7c) + 0x58))(*(int **)(yyvsp + -0x7c));
        if ((queryResult != 0) ||
           (queryResult = (**(code **)(**(int **)(yyvsp + -0x7c) + 0x50))(*(int **)(yyvsp + -0x7c)),
           queryResult != 0)) {
          (**(code **)(**(int **)(yyvsp + -0x7c) + 0x38))(&typeTmp3TypeNameOrTypeTmp4Vtable,*(int **)(yyvsp + -0x7c));
          shiftedTypeBits = typeTmp4BitsOrStr3Data << 0xd;
          basicTypeBits3 = typeTmp4BitsOrStr3Data >> 0x13;
          queryResult = (**(code **)(**(int **)(yyvsp + -0x24) + 0x18))(*(int **)(yyvsp + -0x24));
          staleR4Pass = r4Out4;
          if (((int)(shiftedTypeBits | basicTypeBits3) >> 0x18 <= **(int **)(queryResult + 0x30)) &&
             (queryResult = (**(code **)(**(int **)(yyvsp + -0x7c) + 0x54))(*(int **)(yyvsp + -0x7c))
             , staleR4Pass = r4Out5, queryResult == 0)) {
            foundMatch = true;
          }
          typeTmp3TypeNameOrTypeTmp4Vtable = picBase2 + -0x610c;
          staleR8Value = picBase2;
          if (foundMatch) {
            constantUnionNode = (**(code **)(**(int **)(yyvsp + -0x24) + 0x18))
                               (*(int **)(yyvsp + -0x24),staleR4Pass,scratchR5,scratchR6,scratchR7,picBase2);
            staleR8Value = (unsigned char *)**(uint **)(constantUnionNode + 0x30);
            scratchR5 = "";
            scratchR6 = "[";
            scratchR7 = "field selection out of range \'%d\'";
            TParseContext__error
                      ((int)parseContext,*(char **)(yyvsp + -0x58),"","[",
                       "field selection out of range \'%d\'",staleR8Value,staleR9Value,scratchR10);
            TParseContext__recover(parseContext);
            nodePair = CONCAT44(yyvalNode,r4Out6);
            goto setYyvalNode;
          }
        }
        isArray = (**(code **)(**(int **)(yyvsp + -0x7c) + 0x54))(*(int **)(yyvsp + -0x7c));
        if (isArray != 0) {
          (**(code **)(**(int **)(yyvsp + -0x7c) + 0x38))(&typeTmp5VtableOrStr4Alloc,*(int **)(yyvsp + -0x7c));
          typeVtable = picBase2 + -0x610c;
          typeTmp5VtableOrStr4Alloc = typeVtable;
          if (typeTmp5ArraySizeOrStr4Data == (char *)0x0) {
            picBase2Copy2 = picBase2;
            (**(code **)(**(int **)(yyvsp + -0x7c) + 0x38))
                      (&typeTmp6Vtable,*(int **)(yyvsp + -0x7c),scratchR5,scratchR6,scratchR7,picBase2);
            oldMaxArraySize = typeTmp6MaxArraySize;
            constantUnion2 = (**(code **)(**(int **)(yyvsp + -0x24) + 0x18))(*(int **)(yyvsp + -0x24));
            staleR9Value = (unsigned char *)(uint)(oldMaxArraySize <= **(int **)(constantUnion2 + 0x30));
            isNullSize = staleR9Value == (unsigned char *)0x0;
            if (isNullSize) {
              typeTmp6Vtable = typeVtable;
              arrayOperand = (unsigned char *)
                       (**(code **)(**(int **)(yyvsp + -0x7c) + 0x28))
                                 (*(int **)(yyvsp + -0x7c),r4In1,scratchR5,scratchR6,scratchR7,picBase2Copy2);
              operandTypePtr = (unsigned char *)(**(code **)(**(int **)(yyvsp + -0x7c) + 0x3c))
                                           (*(int **)(yyvsp + -0x7c));
              staleR8Value = *(unsigned char **)(yyvsp + -0x58);
              newMaxArraySize = 0;
            }
            else {
              typeTmp6Vtable = typeVtable;
              constantUnionNode = (**(code **)(**(int **)(yyvsp + -0x24) + 0x18))
                                 (*(int **)(yyvsp + -0x24),r4In1,scratchR5,scratchR6,scratchR7,picBase2Copy2,
                                  staleR9Value);
              constUnionArray = *(int **)(constantUnionNode + 0x30);
              staleR9Value = (unsigned char *)**(undefined4 **)(yyvsp + -0x7c);
              arrayOperand = (unsigned char *)
                       (**(code **)(staleR9Value + 0x28))
                                 (*(undefined4 **)(yyvsp + -0x7c),r4In2,scratchR5,scratchR6,scratchR7,
                                  picBase2Copy2,staleR9Value);
              operandTypePtr = (unsigned char *)(**(code **)(**(int **)(yyvsp + -0x7c) + 0x3c))
                                           (*(int **)(yyvsp + -0x7c));
              newMaxArraySize = *constUnionArray;
              staleR8Value = *(unsigned char **)(yyvsp + -0x58);
            }
            arraySetMaxSizeResult = TParseContext__arraySetMaxSize
                               (parseContext,arrayOperand,operandTypePtr,newMaxArraySize,(uint)!isNullSize,(int)staleR8Value);
            if (arraySetMaxSizeResult != 0) {
loopCallTParseContext_recover:
              TParseContext__recover(parseContext);
            }
          }
          else {
            staleR8Value = picBase2;
            constantUnionNode = (**(code **)(**(int **)(yyvsp + -0x24) + 0x18))(*(int **)(yyvsp + -0x24));
            constUnionArray = *(int **)(constantUnionNode + 0x30);
            (**(code **)(**(int **)(yyvsp + -0x7c) + 0x38))(&typeTmp6Vtable,*(int **)(yyvsp + -0x7c))
            ;
            staleR9Value = (unsigned char *)(uint)(typeTmp6ArraySize <= *constUnionArray);
            typeTmp6Vtable = typeVtable;
            if (staleR9Value != (unsigned char *)0x0) {
              constantUnionNode = (**(code **)(**(int **)(yyvsp + -0x24) + 0x18))
                                 (*(int **)(yyvsp + -0x24),r4In3,scratchR5,scratchR6,scratchR7,staleR8Value,
                                  staleR9Value);
              staleR8Value = (unsigned char *)**(uint **)(constantUnionNode + 0x30);
              TParseContext__error
                        ((int)parseContext,*(char **)(yyvsp + -0x58),"","[",
                         "array index out of range \'%d\'",staleR8Value,staleR9Value,scratchR10);
              goto loopCallTParseContext_recover;
            }
          }
        }
        intermediate = *(unsigned char **)parseContext;
        indexOpCode = 0x2d;
      }
      else {
        queryResult = (**(code **)(**(int **)(yyvsp + -0x7c) + 0x54))(*(int **)(yyvsp + -0x7c),r4In0);
        if (queryResult != 0) {
          (**(code **)(**(int **)(yyvsp + -0x7c) + 0x38))(&typeTmp2VtableOrPubArray,*(int **)(yyvsp + -0x7c));
          typeTmp2VtableOrPubArray = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
          if (typeTmp2ArraySizeOrPubUserDef == (unsigned char *)0x0) {
            TParseContext__error
                      ((int)parseContext,*(char **)(yyvsp + -0x58),"","[",
                       "array must be redeclared with a size before being indexed with a variable",
                       staleR8Value,staleR9Value,scratchR10);
            TParseContext__recover(parseContext);
          }
        }
        intermediate = *(unsigned char **)parseContext;
        indexOpCode = 0x2e;
      }
      scratchR5 = *(char **)(yyvsp + -0x7c);
      scratchR6 = *(char **)(yyvsp + -0x24);
      scratchR7 = *(char **)(yyvsp + -0x58);
      nodePair = TIntermediate__addIndex(intermediate,indexOpCode,scratchR5,scratchR6,scratchR7);
    }
setYyvalNode:
    yyvalNode = (unsigned char *)((ulonglong)nodePair >> 0x20);
    resultNode = yyvalNode;
    if (yyvalNode == (unsigned char *)0x0) {
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      constArray = (unsigned char *)TPoolAllocator__allocate(poolAllocator,4);
      *(undefined4 *)constArray = 0;
      typeTmp1VtableOrStr1Alloc = picBase2 + -0x610c;
      typeTmp1BitsOrPubQualifier = (unsigned char *)((uint)typeTmp1BitsOrPubQualifier & 0x1ff | 0x4080800);
      typeTmp1ArraySizeOrStr1Data = resultNode;
      typeTmp1StructureOrPubSize = resultNode;
      typeTmp1Word0cOrPubMatrix = resultNode;
      typeTmp1TypeNameOrStr2Alloc = resultNode;
      typeTmp1Word14OrStr2Data = resultNode;
      typeTmp1Word18OrPubLine = resultNode;
      typeTmp1MaxArraySize = resultNode;
      typeTmp1Word20OrPubType = resultNode;
      intermediate = *(unsigned char **)parseContext;
      scratchR6 = *(char **)(yyvsp + -0x58);
      goto setTypeTmp1VtableCopy;
    }
    queryResult = (**(code **)(**(int **)(yyvsp + -0x7c) + 0x54))
                       (*(int **)(yyvsp + -0x7c),(int)nodePair,scratchR5,scratchR6,scratchR7,staleR8Value,
                        staleR9Value);
    cr0 = (queryResult == 0) << 1;
    if (queryResult == 0) {
      queryResult = (**(code **)(**(int **)(yyvsp + -0x7c) + 0x50))(*(int **)(yyvsp + -0x7c));
      if (queryResult != 0) {
        (**(code **)(**(int **)(yyvsp + -0x7c) + 0x38))(&typeTmp1VtableOrStr1Alloc,*(int **)(yyvsp + -0x7c));
        typeVtable2 = picBase2 + -0x610c;
        staleR8Value = picBase2;
        typeTmp1VtableOrStr1Alloc = typeVtable2;
        if ((uint)typeTmp1BitsOrPubQualifier >> 0x19 == 2) {
          basicTypeValue = (**(code **)(**(int **)(yyvsp + -0x7c) + 0x40))
                             (*(int **)(yyvsp + -0x7c),r4In4,scratchR5,scratchR6,scratchR7,picBase2);
          nominalSize3 = (**(code **)(**(int **)(yyvsp + -0x7c) + 0x48))(*(int **)(yyvsp + -0x7c));
          typeTmp2BitsOrPub3Qualifier = (unsigned char *)
                      ((nominalSize3 & 0xff) << 0xb |
                      (basicTypeValue & 0x3f) << 0x13 | (uint)typeTmp2BitsOrPub3Qualifier & 0x1ff | 0x4000000);
          typeTmp2Word20OrPub3Type = (unsigned char *)0x0;
          goto setTypeTmp2VtableOrPubArray;
        }
      }
      isMatrix2 = (unsigned char *)
               (**(code **)(**(int **)(yyvsp + -0x7c) + 0x50))(*(int **)(yyvsp + -0x7c));
      cr0 = (isMatrix2 == (unsigned char *)0x0) << 1;
      if (isMatrix2 != (unsigned char *)0x0) {
        basicType3 = (**(code **)(**(int **)(yyvsp + -0x7c) + 0x40))(*(int **)(yyvsp + -0x7c));
        nominalSize3 = (**(code **)(**(int **)(yyvsp + -0x7c) + 0x48))(*(int **)(yyvsp + -0x7c));
        typeTmp2Word20OrPub3Type = (unsigned char *)0x0;
        typeVtable2 = picBase2 + -0x610c;
        typeTmp2BitsOrPub3Qualifier = (unsigned char *)
                    ((nominalSize3 & 0xff) << 0xb | (basicType3 & 0x3f) << 0x13 | (uint)typeTmp2BitsOrPub3Qualifier & 0x1ff);
        typeTmp2ArraySizeOrPubUserDef = (unsigned char *)0x0;
        typeTmp2StructureOrPubLine = (unsigned char *)0x0;
        typeTmp2Word0cOrPubMatrix2 = (unsigned char *)0x0;
        typeTmp2TypeNameOrPubArray2 = (unsigned char *)0x0;
        typeTmp2Word14OrPubUserDef2 = (unsigned char *)0x0;
        typeTmp2Word18OrPubLine2 = (unsigned char *)0x0;
        typeTmp2MaxArraySize = (unsigned char *)0x0;
        typeTmp2VtableOrPubArray = typeVtable2;
        (**(code **)(*(unsigned char **)yyvalNode + 0x34))(yyvalNode,&typeTmp2VtableOrPubArray);
        yyvalNodeReg = yyvalNode;
        typeTmp2VtableOrPubArray = typeVtable2;
        typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
        typeTmp7VtableReg = typeTmp7Vtable[0];
        break;
      }
      queryResult = (**(code **)(**(int **)(yyvsp + -0x7c) + 0x58))(*(int **)(yyvsp + -0x7c));
      if (queryResult != 0) {
        (**(code **)(**(int **)(yyvsp + -0x7c) + 0x38))(&typeTmp2VtableOrPubArray,*(int **)(yyvsp + -0x7c));
        typeTmp3VtableReg = picBase2 + -0x610c;
        staleR8Value = picBase2;
        typeTmp2VtableOrPubArray = typeTmp3VtableReg;
        if ((uint)typeTmp2BitsOrPub3Qualifier >> 0x19 == 2) {
          basicTypeValue = (**(code **)(**(int **)(yyvsp + -0x7c) + 0x40))
                             (*(int **)(yyvsp + -0x7c),r4In5,scratchR5,scratchR6,scratchR7,picBase2);
          typeTmp3BitsOrTypeTmp4Word14 = (basicTypeValue & 0x3f) << 0x13 | typeTmp3BitsOrTypeTmp4Word14 & 0x9ff | 0x4000000 | 0x800;
          typeTmp3VtableOrPub3Array = typeTmp3VtableReg;
          typeTmp3ArraySizeOrPub3UserDef = isMatrix2;
          typeTmp3StructureOrPub3Line = isMatrix2;
          typeTmp3Word0c = isMatrix2;
          typeTmp3TypeNameOrTypeTmp4Vtable = isMatrix2;
          typeTmp3Word14OrTypeTmp4ArraySize = isMatrix2;
          typeTmp3Word18OrTypeTmp4Structure = isMatrix2;
          typeTmp3MaxArraySizeOrTypeTmp4Word0c = isMatrix2;
          typeTmp3Word20OrTypeTmp4TypeName = isMatrix2;
          (**(code **)(*(unsigned char **)yyvalNode + 0x34))(yyvalNode,&typeTmp3VtableOrPub3Array);
          yyvalNodeReg = yyvalNode;
          typeTmp7VtableReg = typeTmp7Vtable[0];
          break;
        }
      }
      queryResult = (**(code **)(**(int **)(yyvsp + -0x7c) + 0x58))(*(int **)(yyvsp + -0x7c));
      if (queryResult == 0) {
        (**(code **)(**(int **)(yyvsp + -0x7c) + 0x38))(&typeTmp3VtableOrPub3Array,*(int **)(yyvsp + -0x7c));
        (**(code **)(*(unsigned char **)yyvalNode + 0x34))(yyvalNode,&typeTmp3VtableOrPub3Array);
        yyvalNodeReg = yyvalNode;
        typeTmp3VtableReg = picBase2 + -0x610c;
        typeTmp7VtableReg = typeTmp7Vtable[0];
      }
      else {
        basicType3 = (**(code **)(**(int **)(yyvsp + -0x7c) + 0x40))(*(int **)(yyvsp + -0x7c));
        typeTmp3VtableReg = picBase2 + -0x610c;
        typeTmp3BitsOrTypeTmp4Word14 = (basicType3 & 0x3f) << 0x13 | typeTmp3BitsOrTypeTmp4Word14 & 0x9ff | 0x800;
        typeTmp3ArraySizeOrPub3UserDef = (unsigned char *)0x0;
        typeTmp3StructureOrPub3Line = (unsigned char *)0x0;
        typeTmp3Word0c = (unsigned char *)0x0;
        typeTmp3TypeNameOrTypeTmp4Vtable = (unsigned char *)0x0;
        typeTmp3Word14OrTypeTmp4ArraySize = (unsigned char *)0x0;
        typeTmp3Word18OrTypeTmp4Structure = (unsigned char *)0x0;
        typeTmp3MaxArraySizeOrTypeTmp4Word0c = (unsigned char *)0x0;
        typeTmp3Word20OrTypeTmp4TypeName = (unsigned char *)0x0;
        typeTmp3VtableOrPub3Array = typeTmp3VtableReg;
        (**(code **)(*(unsigned char **)yyvalNode + 0x34))
                  (yyvalNode,&typeTmp3VtableOrPub3Array,scratchR5,scratchR6,scratchR7,staleR8Value,*(unsigned char **)yyvalNode)
        ;
        yyvalNodeReg = yyvalNode;
        typeTmp7VtableReg = typeTmp7Vtable[0];
      }
      break;
    }
    (**(code **)(**(int **)(yyvsp + -0x7c) + 0x38))(&typeTmp1VtableOrStr1Alloc,*(int **)(yyvsp + -0x7c));
    typeTmp1StructureCopy = typeTmp1StructureOrPubSize;
    typeVtable2 = picBase2 + -0x610c;
    typeTmp1VtableOrStr1Alloc = typeVtable2;
    if (typeTmp1StructureOrPubSize == (unsigned char *)0x0) {
      basicType3 = (**(code **)(**(int **)(yyvsp + -0x7c) + 0x40))(*(int **)(yyvsp + -0x7c));
      nominalSize3 = (**(code **)(**(int **)(yyvsp + -0x7c) + 0x48))(*(int **)(yyvsp + -0x7c));
      isMatrix22 = (**(code **)(**(int **)(yyvsp + -0x7c) + 0x50))(*(int **)(yyvsp + -0x7c));
      typeTmp2BitsOrPub3Qualifier = (unsigned char *)
                  ((isMatrix22 & 1) << 10 |
                  (nominalSize3 & 0xff) << 0xb | (basicType3 & 0x3f) << 0x13 | (uint)typeTmp2BitsOrPub3Qualifier & 0x1ff);
      typeTmp2Word20OrPub3Type = typeTmp1StructureCopy;
setTypeTmp2VtableOrPubArray:
      typeTmp2VtableOrPubArray = typeVtable2;
      typeTmp2ArraySizeOrPubUserDef = typeTmp2Word20OrPub3Type;
      typeTmp2StructureOrPubLine = typeTmp2Word20OrPub3Type;
      typeTmp2Word0cOrPubMatrix2 = typeTmp2Word20OrPub3Type;
      typeTmp2TypeNameOrPubArray2 = typeTmp2Word20OrPub3Type;
      typeTmp2Word14OrPubUserDef2 = typeTmp2Word20OrPub3Type;
      typeTmp2Word18OrPubLine2 = typeTmp2Word20OrPub3Type;
      typeTmp2MaxArraySize = typeTmp2Word20OrPub3Type;
      (**(code **)(*(unsigned char **)yyvalNode + 0x34))(yyvalNode,&typeTmp2VtableOrPubArray);
      yyvalNodeReg = yyvalNode;
      typeTmp2VtableOrPubArray = typeVtable2;
      typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
      typeTmp7VtableReg = typeTmp7Vtable[0];
      break;
    }
    picBase = (unsigned char *)0xa7b8374c;
    (**(code **)(**(int **)(yyvsp + -0x7c) + 0x38))
              (&typeTmp3VtableOrPub3Array,*(int **)(yyvsp + -0x7c),scratchR5,scratchR6,scratchR7,picBase2,0xa7b8374c);
    typeTmp3StructureCopy = typeTmp3StructureOrPub3Line;
    (**(code **)(**(int **)(yyvsp + -0x7c) + 0x38))(typeTmp7Vtable,*(int **)(yyvsp + -0x7c));
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_((unsigned char *)&typeStr3Alloc,typeTmp7TypeName);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&typeTmp5VtableOrStr4Alloc,(unsigned char *)&typeStr3Alloc);
    typeTmp2BitsOrPub3Qualifier = (unsigned char *)((uint)typeTmp2BitsOrPub3Qualifier & 0x9ff | 0x700800);
    typeTmp2Word20OrPub3Type = (unsigned char *)0x0;
    typeTmp2ArraySizeOrPubUserDef = (unsigned char *)0x0;
    typeTmp2StructureOrPubLine = typeTmp3StructureCopy;
    typeTmp2Word0cOrPubMatrix2 = (unsigned char *)0x0;
    typeTmp2Word14OrPubUserDef2 = (unsigned char *)0x0;
    typeTmp2MaxArraySize = (unsigned char *)0x0;
    typeTmp2VtableOrPubArray = typeVtable2;
    setStructSizeResult = (unsigned char *)TType__setStructSize((unsigned char *)&typeTmp2VtableOrPubArray,(unsigned char *)typeTmp3StructureCopy);
    typeTmp5ArraySizeCopy = typeTmp5ArraySizeOrStr4Data;
    typeTmp5ArraySizeOrStr4Data[*(int *)(typeTmp5ArraySizeOrStr4Data + -0xc)] = **(char **)(picBase + -0x7cc4);
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    stringMem = (unsigned char *)TPoolAllocator__allocate(poolAllocator,8);
    cr0 = (stringMem == (unsigned char *)0x0) << 1;
    typeNameString = (unsigned char *)0x0;
    if (stringMem != (unsigned char *)0x0) {
      ctorAlloc1[0] = GetGlobalPoolAllocator();
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                (stringMem,typeTmp5ArraySizeCopy,(unsigned char *)ctorAlloc1);
      typeNameString = stringMem;
    }
    refCountPtr2 = (int *)(typeTmp5ArraySizeOrStr4Data + -4);
    destroyAlloc1[0] = typeTmp5VtableOrStr4Alloc;
    do {
      oldRefCount4 = *refCountPtr2;
      if (reservation != '\0') {
        newRefCount4 = storeWordConditionalIndexed(oldRefCount4 + -1,0,refCountPtr2);
        *refCountPtr2 = newRefCount4;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    typeTmp2TypeNameOrPubArray2 = typeNameString;
    if (oldRefCount4 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(typeTmp5ArraySizeOrStr4Data + -0xc),destroyAlloc1);
    }
    (**(code **)(*(unsigned char **)yyvalNode + 0x34))(yyvalNode,(unsigned char *)&typeTmp2VtableOrPubArray);
    typeTmp3VtableReg = picBase2 + -0x610c;
    destroyAlloc2[0] = typeStr3Alloc;
    refCountPtr2 = (int *)(typeTmp4BitsOrStr3Data - 4);
    do {
      oldRefCount4 = *refCountPtr2;
      if (reservation != '\0') {
        newRefCount4 = storeWordConditionalIndexed(oldRefCount4 + -1,0,refCountPtr2);
        *refCountPtr2 = newRefCount4;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    yyvalNodeReg = yyvalNode;
    typeTmp2VtableOrPubArray = typeTmp3VtableReg;
    typeTmp7VtableReg = typeTmp3VtableReg;
    if (oldRefCount4 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(typeTmp4BitsOrStr3Data - 0xc),destroyAlloc2);
      yyvalNodeReg = yyvalNode;
    }
    break;
  case 10:
    queryResult = (**(code **)(**(int **)(yyvsp + -0x50) + 0x54))
                       (*(int **)(yyvsp + -0x50),scratchR4,scratchR5,scratchR6,scratchR7,staleR8Value);
    if (queryResult != 0) {
      scratchR5 = "cannot apply dot operator to an array";
      scratchR6 = ".";
      scratchR7 = "";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp,"cannot apply dot operator to an array",".","",
                 staleR8Value,staleR9Value,scratchR10);
      TParseContext__recover(parseContext);
    }
    isVector2 = (unsigned char *)
             (**(code **)(**(int **)(yyvsp + -0x50) + 0x58))(*(int **)(yyvsp + -0x50));
    cr0 = (isVector2 == (unsigned char *)0x0) << 1;
    if (isVector2 == (unsigned char *)0x0) {
      queryResult = (**(code **)(**(int **)(yyvsp + -0x50) + 0x50))
                         (*(int **)(yyvsp + -0x50),r4In6,scratchR5,scratchR6,scratchR7,staleR8Value,staleR9Value);
      if (queryResult == 0) {
        basicType = (**(code **)(**(int **)(yyvsp + -0x50) + 0x40))(*(int **)(yyvsp + -0x50));
        if (basicType != 0xe) {
          scratchR10 = *(uint *)(yyvsp + 4);
          staleR9Value = *(unsigned char **)(scratchR10 + 4);
          msgText2 = " field selection requires structure, vector, or matrix on left hand side";
          goto setPicBase;
        }
        picBase2 = (unsigned char *)0xa7b8374c;
        (**(code **)(**(int **)(yyvsp + -0x50) + 0x38))(&typeTmp1VtableOrStr1Alloc,*(int **)(yyvsp + -0x50));
        typeTmp1StructureCopy2 = typeTmp1StructureOrPubSize;
        typeTmp1VtableOrStr1Alloc = picBase2 + -0x610c;
        staleR8Value = picBase2;
        if (typeTmp1StructureOrPubSize == (unsigned char *)0x0) {
          errorLine2 = *(char **)(yyvsp + -0x2c);
          msgText2 = "structure has no fields";
          scratchR6 = "Internal Error";
          goto setScratchR73;
        }
        loopIndex = 0;
        staleR4Value = r4Out7;
        goto loopCheckTypeTmp1StructureCopy2;
      }
      nominalSize = (**(code **)(**(int **)(yyvsp + -0x50) + 0x48))(*(int **)(yyvsp + -0x50));
      parseMatrixFieldsResult = TParseContext__parseMatrixFields
                         (parseContext,*(unsigned char **)(yyvsp + 4),nominalSize,(unsigned char *)&typeTmp1VtableOrStr1Alloc,
                          *(uint *)yyvsp);
      if (parseMatrixFieldsResult == 0) {
        typeTmp1VtableOrStr1Alloc = isVector2;
        typeTmp1ArraySizeOrStr1Data = isVector2;
        typeTmp1StructureOrPubSize = isVector2;
        typeTmp1Word0cOrPubMatrix = isVector2;
        TParseContext__recover(parseContext);
      }
      typeTmp1ArraySizeCopy2 = typeTmp1ArraySizeOrStr1Data;
      if ((typeTmp1VtableOrStr1Alloc == (unsigned char *)0x0) && (typeTmp1ArraySizeOrStr1Data == (unsigned char *)0x0)) {
        poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
        constArray = (unsigned char *)TPoolAllocator__allocate(poolAllocator,4);
        picBase2 = (unsigned char *)0xa7b8374c;
        nominalSize = (**(code **)(**(int **)(yyvsp + -0x50) + 0x48))(*(int **)(yyvsp + -0x50));
        typeVtable3 = picBase2 + -0x610c;
        *(unsigned char **)constArray = typeTmp1StructureOrPubSize + (int)typeTmp1Word0cOrPubMatrix * nominalSize;
        typeTmp2ArraySizeOrPubUserDef = (unsigned char *)((uint)typeTmp2ArraySizeOrPubUserDef & 0x1ff | 0x4100800);
        typeTmp1Word14OrStr2Data = typeTmp1ArraySizeCopy2;
        typeTmp1Word18OrPubLine = typeTmp1ArraySizeCopy2;
        typeTmp1MaxArraySize = typeTmp1ArraySizeCopy2;
        typeTmp1Word20OrPubType = typeTmp1ArraySizeCopy2;
        typeTmp1BitsOrPubQualifier = typeTmp1ArraySizeCopy2;
        pubSize = typeTmp1ArraySizeCopy2;
        pubMatrix = typeTmp1ArraySizeCopy2;
        typeTmp2VtableOrPubArray = typeTmp1ArraySizeCopy2;
        typeTmp1TypeNameOrStr2Alloc = typeVtable3;
        scratchR6 = (char *)TIntermediate__addConstantUnion
                                    (*(unsigned char **)parseContext,constArray,(unsigned char *)&typeTmp1TypeNameOrStr2Alloc,
                                     *(uint *)yyvsp);
        scratchR7 = *(char **)(yyvsp + -0x2c);
        typeTmp1TypeNameOrStr2Alloc = typeVtable3;
        yyvalNode = (unsigned char *)
                    TIntermediate__addIndex
                              (*(unsigned char **)parseContext,0x2d,*(uint *)(yyvsp + -0x50),scratchR6,
                               scratchR7);
        basicType2 = (**(code **)(**(int **)(yyvsp + -0x50) + 0x40))(*(int **)(yyvsp + -0x50));
        typeTmp2ArraySizeOrPubUserDef = (unsigned char *)((basicType2 & 0x3f) << 0x13 | (uint)typeTmp2ArraySizeOrPubUserDef & 0x1ff | 0x800);
        typeTmp1Word14OrStr2Data = typeTmp1ArraySizeCopy2;
        typeTmp1Word18OrPubLine = typeTmp1ArraySizeCopy2;
        typeTmp1MaxArraySize = typeTmp1ArraySizeCopy2;
        typeTmp1Word20OrPubType = typeTmp1ArraySizeCopy2;
        typeTmp1BitsOrPubQualifier = typeTmp1ArraySizeCopy2;
        pubSize = typeTmp1ArraySizeCopy2;
        pubMatrix = typeTmp1ArraySizeCopy2;
        typeTmp2VtableOrPubArray = typeTmp1ArraySizeCopy2;
        typeTmp1TypeNameOrStr2Alloc = typeVtable3;
        (**(code **)(*(uint *)yyvalNode + 0x34))(yyvalNode,(unsigned char *)&typeTmp1TypeNameOrStr2Alloc);
        yyvalNodeReg = yyvalNode;
        typeTmp1TypeNameOrStr2Alloc = typeVtable3;
        typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
        typeTmp7VtableReg = typeTmp7Vtable[0];
      }
      else {
        TParseContext__error
                  ((int)parseContext,*(char **)(yyvsp + -0x2c)," non-scalar fields not implemented yet"
                   ,".","",staleR8Value,staleR9Value,scratchR10);
        TParseContext__recover(parseContext);
        poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
        constArray = (unsigned char *)TPoolAllocator__allocate(poolAllocator,4);
        *(undefined4 *)constArray = 0;
        typeTmp2ArraySizeOrPubUserDef = (unsigned char *)((uint)typeTmp2ArraySizeOrPubUserDef & 0x9ff | 0x4100800);
        typeTmp1TypeNameOrStr2Alloc = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
        typeTmp1Word14OrStr2Data = isVector2;
        typeTmp1Word18OrPubLine = isVector2;
        typeTmp1MaxArraySize = isVector2;
        typeTmp1Word20OrPubType = isVector2;
        typeTmp1BitsOrPubQualifier = isVector2;
        pubSize = isVector2;
        pubMatrix = isVector2;
        typeTmp2VtableOrPubArray = isVector2;
        scratchR6 = (char *)TIntermediate__addConstantUnion
                                    (*(unsigned char **)parseContext,constArray,(unsigned char *)&typeTmp1TypeNameOrStr2Alloc,
                                     *(uint *)yyvsp);
        typeTmp1TypeNameOrStr2Alloc = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
        scratchR7 = *(char **)(yyvsp + -0x2c);
        yyvalNode = (unsigned char *)
                    TIntermediate__addIndex
                              (*(unsigned char **)parseContext,0x2d,*(uint *)(yyvsp + -0x50),scratchR6,
                               scratchR7);
        basicType2 = (**(code **)(**(int **)(yyvsp + -0x50) + 0x40))(*(int **)(yyvsp + -0x50));
        nominalSize2 = (**(code **)(**(int **)(yyvsp + -0x50) + 0x48))(*(int **)(yyvsp + -0x50));
        typeTmp2ArraySizeOrPubUserDef = (unsigned char *)
                    ((nominalSize2 & 0xff) << 0xb | (basicType2 & 0x3f) << 0x13 | (uint)typeTmp2ArraySizeOrPubUserDef & 0x1ff);
        typeTmp1TypeNameOrStr2Alloc = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
        typeTmp1Word14OrStr2Data = isVector2;
        typeTmp1Word18OrPubLine = isVector2;
        typeTmp1MaxArraySize = isVector2;
        typeTmp1Word20OrPubType = isVector2;
        typeTmp1BitsOrPubQualifier = isVector2;
        pubSize = isVector2;
        pubMatrix = isVector2;
        typeTmp2VtableOrPubArray = isVector2;
        (**(code **)(*(uint *)yyvalNode + 0x34))(yyvalNode,(unsigned char *)&typeTmp1TypeNameOrStr2Alloc);
        typeTmp1TypeNameOrStr2Alloc = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
        yyvalNodeReg = yyvalNode;
        typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
        typeTmp7VtableReg = typeTmp7Vtable[0];
      }
      break;
    }
    nominalSize = (**(code **)(**(int **)(yyvsp + -0x50) + 0x48))(*(int **)(yyvsp + -0x50));
    scratchR7 = *(char **)yyvsp;
    parseVectorFieldsResult = (unsigned char *)
             TParseContext__parseVectorFields
                       (parseContext,*(unsigned char **)(yyvsp + 4),nominalSize,(unsigned char *)&typeTmp1VtableOrStr1Alloc,
                        (int)scratchR7);
    cr0 = (parseVectorFieldsResult == (unsigned char *)0x0) << 1;
    if (parseVectorFieldsResult == (unsigned char *)0x0) {
      typeTmp1TypeNameOrStr2Alloc = (unsigned char *)0x1;
      typeTmp1VtableOrStr1Alloc = parseVectorFieldsResult;
      TParseContext__recover(parseContext);
    }
    picBase2 = (unsigned char *)0xa7b8374c;
    (**(code **)(**(int **)(yyvsp + -0x50) + 0x38))(&typeTmp1Word20OrPubType,*(int **)(yyvsp + -0x50));
    typeVtable2 = picBase2 + -0x610c;
    picBase2Copy = picBase2;
    typeTmp1Word20OrPubType = typeVtable2;
    if ((uint)typeTmp2Word14OrPubUserDef2 >> 0x19 == 2) {
      postfixExpressionNode2 = *(unsigned char **)(yyvsp + -0x50);
      scratchR6 = *(char **)yyvsp;
      yyvalNode = (unsigned char *)
                  TParseContext__addConstVectorNode
                            (parseContext,(unsigned char *)&typeTmp1VtableOrStr1Alloc,postfixExpressionNode2,(int)scratchR6,scratchR7,
                             picBase2);
      if (yyvalNode == (unsigned char *)0x0) goto loopCallTParseContext_recover2;
      basicType2 = (**(code **)(**(int **)(yyvsp + -0x50) + 0x40))(*(int **)(yyvsp + -0x50));
      typeTmp3Word14OrTypeTmp4ArraySize = (unsigned char *)
                  ((*(uint *)(*(int *)(*(uint *)(yyvsp + 4) + 4) + -0xc) & 0xff) << 0xb |
                  (basicType2 & 0x3f) << 0x13 | (uint)typeTmp3Word14OrTypeTmp4ArraySize & 0x1ff | 0x4000000);
      nodeSetTypeFunc = *(unsigned char **)(*(unsigned char **)yyvalNode + 0x34);
      nodeVtable = *(unsigned char **)yyvalNode;
loopSetTypeTmp3TypeNameOrTypeTmp4Vtable:
      typeTmp3TypeNameOrTypeTmp4Vtable = (unsigned char *)0x0;
      typeTmp3Word0c = (unsigned char *)0x0;
      typeTmp3StructureOrPub3Line = (unsigned char *)0x0;
      typeTmp3ArraySizeOrPub3UserDef = (unsigned char *)0x0;
      typeTmp3VtableOrPub3Array = (unsigned char *)0x0;
      pub3Matrix = (unsigned char *)0x0;
      pub3Size = (unsigned char *)0x0;
      typeTmp2BitsOrPub3Qualifier = (unsigned char *)0x0;
      typeTmp2Word20OrPub3Type = typeVtable2;
      (*(code *)nodeSetTypeFunc)(yyvalNode,&typeTmp2Word20OrPub3Type,postfixExpressionNode2,scratchR6,scratchR7,picBase2Copy,nodeVtable);
      yyvalNodeReg = yyvalNode;
      typeTmp2Word20OrPub3Type = typeVtable2;
      typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
      typeTmp7VtableReg = typeTmp7Vtable[0];
      break;
    }
    if (typeTmp1TypeNameOrStr2Alloc == (unsigned char *)0x1) {
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      constArray = (unsigned char *)TPoolAllocator__allocate(poolAllocator,4);
      *(unsigned char **)constArray = typeTmp1VtableOrStr1Alloc;
      typeTmp3Word14OrTypeTmp4ArraySize = (unsigned char *)((uint)typeTmp3Word14OrTypeTmp4ArraySize & 0x1ff | 0x4100800);
      typeTmp2BitsOrPub3Qualifier = (unsigned char *)0x0;
      pub3Size = (unsigned char *)0x0;
      pub3Matrix = (unsigned char *)0x0;
      typeTmp3VtableOrPub3Array = (unsigned char *)0x0;
      typeTmp3ArraySizeOrPub3UserDef = (unsigned char *)0x0;
      typeTmp3StructureOrPub3Line = (unsigned char *)0x0;
      typeTmp3Word0c = (unsigned char *)0x0;
      typeTmp3TypeNameOrTypeTmp4Vtable = (unsigned char *)0x0;
      typeTmp2Word20OrPub3Type = typeVtable2;
      scratchR6 = (char *)TIntermediate__addConstantUnion
                                  (*(unsigned char **)parseContext,constArray,(unsigned char *)&typeTmp2Word20OrPub3Type,
                                   *(uint *)yyvsp);
      postfixExpressionNode2 = *(unsigned char **)(yyvsp + -0x50);
      scratchR7 = *(char **)(yyvsp + -0x2c);
      typeTmp2Word20OrPub3Type = typeVtable2;
      yyvalNode = (unsigned char *)
                  TIntermediate__addIndex(*(unsigned char **)parseContext,0x2d,postfixExpressionNode2,scratchR6,scratchR7);
      basicType3 = (**(code **)(**(int **)(yyvsp + -0x50) + 0x40))(*(int **)(yyvsp + -0x50));
      typeTmp3Word14OrTypeTmp4ArraySize = (unsigned char *)((basicType3 & 0x3f) << 0x13 | (uint)typeTmp3Word14OrTypeTmp4ArraySize & 0x1ff | 0x800);
      nodeSetTypeFunc = *(unsigned char **)(*(unsigned char **)yyvalNode + 0x34);
      nodeVtable = yyvalNode;
      goto loopSetTypeTmp3TypeNameOrTypeTmp4Vtable;
    }
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&typeTmp2Word20OrPub3Type,*(unsigned char **)(yyvsp + 4));
    scratchR6 = (char *)TIntermediate__addSwizzle
                                (*(unsigned char **)parseContext,(unsigned char *)&typeTmp1VtableOrStr1Alloc,
                                 *(uint *)yyvsp);
    postfixExpressionNode = *(uint *)(yyvsp + -0x50);
    scratchR7 = *(char **)(yyvsp + -0x2c);
    yyvalNode = (unsigned char *)
                TIntermediate__addIndex(*(unsigned char **)parseContext,0x30,postfixExpressionNode,scratchR6,scratchR7);
    nodeVtableWord = *(unsigned char **)yyvalNode;
    basicType3 = (**(code **)(**(int **)(yyvsp + -0x50) + 0x40))(*(int **)(yyvsp + -0x50));
    typeTmp3BitsOrTypeTmp4Word14 = (*(uint *)(typeTmp2BitsOrPub3Qualifier + -0xc) & 0xff) << 0xb |
                (basicType3 & 0x3f) << 0x13 | typeTmp3BitsOrTypeTmp4Word14 & 0x1ff;
    typeTmp3Word20OrTypeTmp4TypeName = (unsigned char *)0x0;
    typeTmp3ArraySizeOrPub3UserDef = (unsigned char *)0x0;
    typeTmp3StructureOrPub3Line = (unsigned char *)0x0;
    typeTmp3Word0c = (unsigned char *)0x0;
    typeTmp3TypeNameOrTypeTmp4Vtable = (unsigned char *)0x0;
    typeTmp3Word14OrTypeTmp4ArraySize = (unsigned char *)0x0;
    typeTmp3Word18OrTypeTmp4Structure = (unsigned char *)0x0;
    typeTmp3MaxArraySizeOrTypeTmp4Word0c = (unsigned char *)0x0;
    typeTmp3VtableOrPub3Array = typeVtable2;
    (**(code **)(nodeVtableWord + 0x34))
              (yyvalNode,&typeTmp3VtableOrPub3Array,postfixExpressionNode,scratchR6,scratchR7,picBase2Copy,*(uint *)(typeTmp2BitsOrPub3Qualifier + -0xc));
    refCountPtr = typeTmp2BitsOrPub3Qualifier + -4;
    destroyAlloc3[0] = typeTmp2Word20OrPub3Type;
    destroyRep = (unsigned char *)(typeTmp2BitsOrPub3Qualifier + -0xc);
    do {
      oldRefCount = *(uint *)refCountPtr;
      if (reservation != '\0') {
        newRefCount = storeWordConditionalIndexed(oldRefCount - 1,0,refCountPtr);
        *(uint *)refCountPtr = newRefCount;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    stillShared = 0 < (int)oldRefCount;
    destroyAllocArg = destroyAlloc3;
    typeTmp3VtableOrPub3Array = typeVtable2;
    goto loopSetYyvalNodeReg2;
  case 0xb:
    lValueError = TParseContext__lValueErrorCheck
                       (parseContext,*(uint *)yyvsp,"++",*(unsigned char **)(yyvsp + -0x24),scratchR7,
                        staleR8Value,staleR9Value,scratchR10);
    if (lValueError != 0) {
      TParseContext__recover(parseContext);
    }
    scratchR6 = *(char **)yyvsp;
    scratchR7 = *(char **)((int)parseContext + 4);
    yyvalNode = (unsigned char *)
                TIntermediate__addUnaryMath
                          (*(unsigned char **)parseContext,9,*(uint *)(yyvsp + -0x24),scratchR6,scratchR7,
                           staleR8Value,staleR9Value);
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    if (yyvalNode != (unsigned char *)0x0) break;
    scratchR6 = (char *)&typeTmp1VtableOrStr1Alloc;
    TType__getCompleteString(scratchR6,*(uint *)(yyvsp + -0x24) + 8);
    TParseContext__unaryOpError(parseContext,*(uint *)yyvsp,"++",scratchR6);
    refCountPtr = typeTmp1ArraySizeOrStr1Data + -4;
    destroyAlloc4[0] = typeTmp1VtableOrStr1Alloc;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    if ((int)oldRefCount2 < 1) {
      destroyAllocArg = destroyAlloc4;
LAB_97ba5844:
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(typeTmp1ArraySizeOrStr1Data + -0xc),destroyAllocArg);
    }
    goto callTParseContext_recover;
  case 0xc:
    lValueError = TParseContext__lValueErrorCheck
                       (parseContext,*(uint *)yyvsp,"--",*(unsigned char **)(yyvsp + -0x24),scratchR7,
                        staleR8Value,staleR9Value,scratchR10);
    if (lValueError != 0) {
      TParseContext__recover(parseContext);
    }
    scratchR6 = *(char **)yyvsp;
    scratchR7 = *(char **)((int)parseContext + 4);
    yyvalNode = (unsigned char *)
                TIntermediate__addUnaryMath
                          (*(unsigned char **)parseContext,10,*(uint *)(yyvsp + -0x24),scratchR6,scratchR7,
                           staleR8Value,staleR9Value);
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    if (yyvalNode != (unsigned char *)0x0) break;
    scratchR6 = (char *)&typeTmp1VtableOrStr1Alloc;
    TType__getCompleteString(scratchR6,*(uint *)(yyvsp + -0x24) + 8);
    TParseContext__unaryOpError(parseContext,*(uint *)yyvsp,"--",scratchR6);
    refCountPtr = typeTmp1ArraySizeOrStr1Data + -4;
    destroyAlloc5[0] = typeTmp1VtableOrStr1Alloc;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    destroyAllocArg = destroyAlloc5;
    if ((int)oldRefCount2 < 1) goto LAB_97ba5844;
callTParseContext_recover:
    TParseContext__recover(parseContext);
yynCase6:
    yyvalNodeReg = *(unsigned char **)(yyvsp + -0x24);
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    break;
  case 0xd:
    errorCheckResult = TParseContext__integerErrorCheck(parseContext,*(unsigned char **)(yyvsp + 8),"[]");
    goto checkErrorCheckResult;
  case 0xe:
    stackNode = *(unsigned char **)(yyvsp + 0x10);
    stackNodeWord4c = *(unsigned char **)(stackNode + 0x4c);
    if (stackNodeWord4c != (unsigned char *)0x0) {
      picBase2 = (unsigned char *)0xa7b8374c;
      typeTmp1Word20OrPubType = (unsigned char *)0x0;
      typeTmp1BitsOrPubQualifier = (unsigned char *)((uint)typeTmp1BitsOrPubQualifier & 0x9ff | 0x800);
      cr0 = (typeTmp1BitsOrPubQualifier == (unsigned char *)0x0) << 1;
      typeTmp1VtableOrStr1Alloc = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
      typeTmp1ArraySizeOrStr1Data = (unsigned char *)0x0;
      typeTmp1StructureOrPubSize = (unsigned char *)0x0;
      typeTmp1Word0cOrPubMatrix = (unsigned char *)0x0;
      typeTmp1TypeNameOrStr2Alloc = (unsigned char *)0x0;
      typeTmp1Word14OrStr2Data = (unsigned char *)0x0;
      typeAt850Word18 = (unsigned char *)0x0;
      typeTmp1MaxArraySize = (unsigned char *)0x0;
      scratchR6 = (char *)stackNode;
      scratchR7 = (char *)stackNodeWord4c;
      constructorError = TParseContext__constructorErrorCheck
                         (parseContext,*(uint *)yyvsp,*(unsigned char **)(yyvsp + 8),stackNode,stackNodeWord4c,
                          (unsigned char *)&typeTmp1VtableOrStr1Alloc);
      if (constructorError == 0) {
        scratchR6 = (char *)stackNodeWord4c;
        scratchR7 = (char *)stackNode;
        yyvalNode = (unsigned char *)
                    TParseContext__addConstructor
                              (parseContext,*(unsigned char **)(yyvsp + 8),(unsigned char *)&typeTmp1VtableOrStr1Alloc,stackNodeWord4c,stackNode,
                               *(uint *)yyvsp);
      }
      else {
        yyvalNode = (unsigned char *)0x0;
      }
      if (yyvalNode == (unsigned char *)0x0) {
        TParseContext__recover(parseContext);
        scratchR6 = *(char **)yyvsp;
        yyvalNode = (unsigned char *)
                    TIntermediate__setAggregateOperator
                              (*(unsigned char **)parseContext,(unsigned char *)0x0,stackNodeWord4c,scratchR6);
      }
      (**(code **)(*(unsigned char **)yyvalNode + 0x34))(yyvalNode,(unsigned char *)&typeTmp1VtableOrStr1Alloc);
      typeTmp1VtableOrStr1Alloc = picBase2 + -0x610c;
      goto setYyvalNodeReg;
    }
    findFunctionResult = (unsigned char *)
             TParseContext__findFunction
                       (parseContext,*(uint *)yyvsp,stackNode,(bool *)&outFlag,scratchR7,staleR8Value);
    cr0 = (findFunctionResult == (unsigned char *)0x0) << 1;
    if (findFunctionResult == (unsigned char *)0x0) {
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      constArray = (unsigned char *)TPoolAllocator__allocate(poolAllocator,4);
      *(undefined4 *)constArray = 0;
      typeTmp1BitsOrPubQualifier = (unsigned char *)((uint)typeTmp1BitsOrPubQualifier & 0x1ff | 0x4080800);
      typeTmp1VtableOrStr1Alloc = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
      scratchR6 = *(char **)yyvsp;
      typeTmp1ArraySizeOrStr1Data = findFunctionResult;
      typeTmp1StructureOrPubSize = findFunctionResult;
      typeTmp1Word0cOrPubMatrix = findFunctionResult;
      typeTmp1TypeNameOrStr2Alloc = findFunctionResult;
      typeTmp1Word14OrStr2Data = findFunctionResult;
      typeTmp1Word18OrPubLine = findFunctionResult;
      typeTmp1MaxArraySize = findFunctionResult;
      typeTmp1Word20OrPubType = findFunctionResult;
      yyvalNode = (unsigned char *)
                  TIntermediate__addConstantUnion
                            (*(unsigned char **)parseContext,constArray,(unsigned char *)&typeTmp1VtableOrStr1Alloc,(int)scratchR6);
      typeTmp1VtableOrStr1Alloc = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
      TParseContext__recover(parseContext);
      goto setYyvalNodeReg;
    }
    findFunctionResultWord4c = *(uint *)(findFunctionResult + 0x4c);
    if ((outFlag == 0) || (findFunctionResultWord4c == 0)) {
      opName = (char *)0x2;
      scratchR6 = *(char **)yyvsp;
      yyvalNode = (unsigned char *)
                  TIntermediate__setAggregateOperator
                            (*(unsigned char **)parseContext,*(unsigned char **)(yyvsp + 8),2,scratchR6);
      (**(code **)(*(unsigned char **)yyvalNode + 0x34))(yyvalNode,findFunctionResult + 0x1c);
      if (outFlag == 0) {
        aggregateNode = (int *)(**(code **)(*(unsigned char **)yyvalNode + 0x1c))(yyvalNode);
        (**(code **)(*aggregateNode + 0x70))(aggregateNode);
      }
      aggregateNode = (int *)(**(code **)(*(unsigned char **)yyvalNode + 0x1c))(yyvalNode);
      objVtable = *aggregateNode;
      mangledName = (**(code **)(*(unsigned char **)findFunctionResult + 8))(findFunctionResult);
      (**(code **)(objVtable + 0x68))(aggregateNode,mangledName);
      aggregateNode = (int *)(**(code **)(*(unsigned char **)yyvalNode + 0x1c))(yyvalNode);
      this = (unsigned char *)(**(code **)(*aggregateNode + 0x78))(aggregateNode);
      callTarget = r4Out11;
      for (loopIndex2 = 0; loopIndex2 < (int)(*(uint *)(findFunctionResult + 0x14) - *(uint *)(findFunctionResult + 0x10)) >> 3;
          loopIndex2 = loopIndex2 + 1) {
        paramEntry = *(int **)(*(uint *)(findFunctionResult + 0x10) + loopIndex2 * 8 + 4);
        qualifier1 = *paramEntry;
        qualifier1 = (**(code **)(qualifier1 + 0x24))
                           (paramEntry,callTarget,opName,scratchR6,scratchR7,staleR8Value,qualifier1);
        if (qualifier1 - 10U < 2) {
          aggregateNode = (int *)(**(code **)(*(unsigned char **)yyvalNode + 0x1c))(yyvalNode);
          paramList = (**(code **)(*aggregateNode + 100))(aggregateNode);
          paramArrayBegin = *(int *)(paramList + 4);
          argType = *(int **)(paramArrayBegin + loopIndex2 * 4);
          scratchR6 = (char *)(**(code **)(*argType + 0x14))
                                      (argType,r4In8,opName,scratchR6,scratchR7,staleR8Value,paramArrayBegin);
          nodeLine = (**(code **)*(unsigned char **)yyvalNode)(yyvalNode);
          opName = "assign";
          lValueError2 = TParseContext__lValueErrorCheck
                             (parseContext,nodeLine,"assign",(unsigned char *)scratchR6,scratchR7,staleR8Value,paramArrayBegin,
                              scratchR10);
          if (lValueError2 != 0) {
            messageSource = (char *)(**(code **)**(undefined4 **)(yyvsp + 8))
                                        (*(undefined4 **)(yyvsp + 8));
            opName = "Constant value cannot be passed for \'out\' or \'inout\' parameters.";
            scratchR6 = "Error";
            scratchR7 = "";
            TParseContext__error
                      ((int)parseContext,messageSource,
                       "Constant value cannot be passed for \'out\' or \'inout\' parameters.",
                       "Error","",staleR8Value,paramArrayBegin,scratchR10);
            TParseContext__recover(parseContext);
          }
        }
        callTarget = *(int **)(this + 8);
        callArgSlot = qualifier1;
        if (callTarget == *(int **)(this + 0xc)) {
          opName = (char *)&callArgSlot;
          std__vector_int_pool_allocator_int_____M_insert_aux(this,callTarget,opName);
          callTarget = r4Out12;
        }
        else {
          finishPtr = 0;
          if (callTarget != (int *)0x0) {
            *callTarget = qualifier1;
            finishPtr = *(int *)(this + 8);
          }
          *(int *)(this + 8) = finishPtr + 4;
        }
      }
    }
    else {
      if ((int)(*(uint *)(findFunctionResult + 0x14) - *(uint *)(findFunctionResult + 0x10)) >> 3 == 1) {
        functionCallGenericNode = *(uint *)(yyvsp + 8);
        scratchR6 = (char *)0x0;
        scratchR7 = *(char **)((int)parseContext + 4);
        yyvalNode = (unsigned char *)
                    TIntermediate__addUnaryMath
                              (*(unsigned char **)parseContext,findFunctionResultWord4c,functionCallGenericNode,0,scratchR7,staleR8Value,
                               *(uint *)(findFunctionResult + 0x10));
        if (yyvalNode != (unsigned char *)0x0) goto LAB_97ba5d80;
        picBase = (unsigned char *)0xa7b8374c;
        TType__getCompleteString(&typeTmp1VtableOrStr1Alloc,*(uint *)(yyvsp + 8) + 8);
        staleR8Value = typeTmp1ArraySizeOrStr1Data;
        typeTmp1ArraySizeOrStr1Data[*(uint *)(typeTmp1ArraySizeOrStr1Data + -0xc)] = **(unsigned char **)(picBase + -0x7cc4);
        typeTmp1ArraySizeCopy = typeTmp1ArraySizeOrStr1Data;
        typeNameText = (char *)(**(code **)**(undefined4 **)(yyvsp + 8))
                                    (*(undefined4 **)(yyvsp + 8),r4In7,functionCallGenericNode,scratchR6,scratchR7,
                                     picBase,typeTmp1ArraySizeOrStr1Data);
        scratchR5 = " wrong operand type";
        scratchR6 = "Internal Error";
        scratchR7 = "built in unary operator function.  Type: %s";
        TParseContext__error
                  ((int)parseContext,typeNameText," wrong operand type","Internal Error",
                   "built in unary operator function.  Type: %s",staleR8Value,typeTmp1ArraySizeCopy,scratchR10);
        refCountPtr = typeTmp1ArraySizeOrStr1Data + -4;
        destroyAlloc6[0] = typeTmp1VtableOrStr1Alloc;
        do {
          yyn = *(uint *)refCountPtr;
          if (reservation != '\0') {
            newRefCount = storeWordConditionalIndexed(yyn - 1,0,refCountPtr);
            *(uint *)refCountPtr = newRefCount;
            cr0 = 2;
          }
        } while (!(bool)(cr0 >> 1 & 1));
        scratchR4 = r4Out9;
        if ((int)yyn < 1) {
          __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                    ((unsigned char *)(typeTmp1ArraySizeOrStr1Data + -0xc),destroyAlloc6);
          scratchR4 = r4Out10;
        }
        goto loopCheckYyerrstatus2;
      }
      scratchR6 = *(char **)yyvsp;
      yyvalNode = (unsigned char *)
                  TIntermediate__setAggregateOperator
                            (*(unsigned char **)parseContext,*(unsigned char **)(yyvsp + 8),findFunctionResultWord4c,
                             scratchR6);
    }
LAB_97ba5d80:
    (**(code **)(*(unsigned char **)yyvalNode + 0x34))(yyvalNode,findFunctionResult + 0x1c);
setYyvalNodeReg:
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    if (stackNode != (unsigned char *)0x0) {
      stackNodeVtable = *(int *)stackNode;
LAB_97ba86fc:
      (**(code **)(stackNodeVtable + 4))(stackNode);
      yyvalNodeReg = yyvalNode;
      typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
      typeTmp7VtableReg = typeTmp7Vtable[0];
    }
    break;
  case 0xf:
  case 0x10:
    _memcpy(&yyval,yyvsp + -0x2c,0x2c);
    yyval = *(uint *)yyvsp;
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    break;
  case 0x11:
    yyvalTypeOrFunction = *(unsigned char **)(yyvsp + -0x1c);
    goto setYyvalNodeReg2;
  case 0x12:
    yyvalTypeOrFunction = *(unsigned char **)(yyvsp + 0x10);
setYyvalNodeReg2:
    yyvalNodeReg = (unsigned char *)0x0;
    break;
  case 0x13:
    typeTmp1TypeNameOrStr2Alloc = (unsigned char *)0x0;
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    typeMem = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x28);
    (**(code **)(**(int **)(yyvsp + 8) + 0x38))(typeMem,*(int **)(yyvsp + 8));
    typeTmp1VtableOrStr1Alloc = typeTmp1TypeNameOrStr2Alloc;
    functionCallHeaderFunction = *(uint *)(yyvsp + -0x1c);
    elementPtr = *(undefined4 **)(functionCallHeaderFunction + 0x14);
    typeTmp1ArraySizeOrStr1Data = typeMem;
    typeTmp1Word14OrStr2Data = typeMem;
    if (elementPtr == *(undefined4 **)(functionCallHeaderFunction + 0x18)) {
      std__vector_TParameter_pool_allocator_TParameter_____M_insert_aux
                ((unsigned char *)(functionCallHeaderFunction + 0xc),
                 *(undefined4 *)(functionCallHeaderFunction + 0x14),&typeTmp1VtableOrStr1Alloc);
    }
    else {
      finishPtr2 = 0;
      if (elementPtr != (undefined4 *)0x0) {
        elementPtr[1] = typeMem;
        *elementPtr = typeTmp1TypeNameOrStr2Alloc;
        finishPtr2 = *(int *)(functionCallHeaderFunction + 0x14);
      }
      *(int *)(functionCallHeaderFunction + 0x14) = finishPtr2 + 8;
    }
    typeTmp1ArraySizeCopy = typeTmp1ArraySizeOrStr1Data;
    paramFinish = *(int *)(typeTmp1ArraySizeOrStr1Data + 0x14);
    if (paramFinish == 0) {
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      newString = (unsigned char *)TPoolAllocator__allocate(poolAllocator,8);
      cr0 = (newString == (unsigned char *)0x0) << 1;
      mangledString = (unsigned char *)0x0;
      if (newString != (unsigned char *)0x0) {
        ctorAlloc2[0] = GetGlobalPoolAllocator();
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_(newString,"",(unsigned char *)ctorAlloc2)
        ;
        mangledString = newString;
      }
      *(unsigned char **)(typeTmp1ArraySizeCopy + 0x14) = mangledString;
      ((int (*)())TType__buildMangledName)((unsigned char *)typeTmp1ArraySizeCopy,mangledString);
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEmc(*(void **)(typeTmp1ArraySizeCopy + 0x14),1,0x3b);
      paramFinish = *(int *)(typeTmp1ArraySizeCopy + 0x14);
    }
    __ZStplIcSt11char_traitsIcE14pool_allocatorIcEESbIT_T0_T1_ERKS7_S9_
              ((unsigned char *)&typeTmp1TypeNameOrStr2Alloc,(unsigned char *)(functionCallHeaderFunction + 0x44),paramFinish);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6assignERKS3_
              ((unsigned char *)(functionCallHeaderFunction + 0x44),(unsigned char *)&typeTmp1TypeNameOrStr2Alloc);
    refCountPtr = typeTmp1Word14OrStr2Data + -4;
    destroyAlloc7[0] = typeTmp1TypeNameOrStr2Alloc;
    do {
      oldRefCount = *(uint *)refCountPtr;
      if (reservation != '\0') {
        newRefCount = storeWordConditionalIndexed(oldRefCount - 1,0,refCountPtr);
        *(uint *)refCountPtr = newRefCount;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    if ((int)oldRefCount < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(typeTmp1Word14OrStr2Data + -0xc),destroyAlloc7);
    }
    yyvalTypeOrFunction = *(unsigned char **)(yyvsp + -0x1c);
    yyvalNodeReg = *(unsigned char **)(yyvsp + 8);
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    break;
  case 0x14:
    typeTmp1TypeNameOrStr2Alloc = (unsigned char *)0x0;
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    typeMem = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x28);
    (**(code **)(**(int **)(yyvsp + 8) + 0x38))(typeMem,*(int **)(yyvsp + 8));
    typeTmp1VtableOrStr1Alloc = typeTmp1TypeNameOrStr2Alloc;
    functionCallHeaderWithParametersFunction = *(uint *)(yyvsp + -0x48);
    elementPtr = *(undefined4 **)(functionCallHeaderWithParametersFunction + 0x14);
    typeTmp1ArraySizeOrStr1Data = typeMem;
    typeTmp1Word14OrStr2Data = typeMem;
    if (elementPtr == *(undefined4 **)(functionCallHeaderWithParametersFunction + 0x18)) {
      std__vector_TParameter_pool_allocator_TParameter_____M_insert_aux
                ((unsigned char *)(functionCallHeaderWithParametersFunction + 0xc),
                 *(undefined4 *)(functionCallHeaderWithParametersFunction + 0x14),&typeTmp1VtableOrStr1Alloc);
    }
    else {
      finishPtr2 = 0;
      if (elementPtr != (undefined4 *)0x0) {
        elementPtr[1] = typeMem;
        *elementPtr = typeTmp1TypeNameOrStr2Alloc;
        finishPtr2 = *(int *)(functionCallHeaderWithParametersFunction + 0x14);
      }
      *(int *)(functionCallHeaderWithParametersFunction + 0x14) = finishPtr2 + 8;
    }
    typeTmp1ArraySizeCopy = typeTmp1ArraySizeOrStr1Data;
    paramFinish = *(int *)(typeTmp1ArraySizeOrStr1Data + 0x14);
    if (paramFinish == 0) {
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      newString = (unsigned char *)TPoolAllocator__allocate(poolAllocator,8);
      cr0 = (newString == (unsigned char *)0x0) << 1;
      mangledString = (unsigned char *)0x0;
      if (newString != (unsigned char *)0x0) {
        ctorAlloc3[0] = GetGlobalPoolAllocator();
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_(newString,"",(unsigned char *)ctorAlloc3)
        ;
        mangledString = newString;
      }
      *(unsigned char **)(typeTmp1ArraySizeCopy + 0x14) = mangledString;
      ((int (*)())TType__buildMangledName)((unsigned char *)typeTmp1ArraySizeCopy,mangledString);
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEmc(*(void **)(typeTmp1ArraySizeCopy + 0x14),1,0x3b);
      paramFinish = *(int *)(typeTmp1ArraySizeCopy + 0x14);
    }
    __ZStplIcSt11char_traitsIcE14pool_allocatorIcEESbIT_T0_T1_ERKS7_S9_
              ((unsigned char *)&typeTmp1TypeNameOrStr2Alloc,(unsigned char *)(functionCallHeaderWithParametersFunction + 0x44),paramFinish);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6assignERKS3_
              ((unsigned char *)(functionCallHeaderWithParametersFunction + 0x44),(unsigned char *)&typeTmp1TypeNameOrStr2Alloc);
    refCountPtr = typeTmp1Word14OrStr2Data + -4;
    destroyAlloc8[0] = typeTmp1TypeNameOrStr2Alloc;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    if ((int)oldRefCount2 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(typeTmp1Word14OrStr2Data + -0xc),destroyAlloc8);
    }
    yyvalTypeOrFunction = *(unsigned char **)(yyvsp + -0x48);
    intermediate = *(unsigned char **)parseContext;
    leftNode = *(unsigned char **)(yyvsp + -0x50);
    operandNode = *(unsigned char **)(yyvsp + 8);
loopSetScratchR6:
    scratchR6 = *(char **)(yyvsp + -0x2c);
loopSetYyvalNodeReg:
    yyvalNodeReg = (unsigned char *)TIntermediate__growAggregate(intermediate,leftNode,operandNode,(int)scratchR6);
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    break;
  case 0x15:
    yyvalTypeOrFunction = *(unsigned char **)(yyvsp + -0x1c);
    break;
  case 0x16:
    if (*(uint *)(yyvsp + 4) != 0x75) {
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      newFunction = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x54);
      constructorIdentifierOp = *(uint *)(yyvsp + 4);
      functionVtable = PTR_vtable_a7b7c0f4 + 8;
      *(uint *)(newFunction + 4) = 0;
      *(undefined **)newFunction = functionVtable;
      picBase2 = (unsigned char *)0xa7b8374c;
      allocatorArg1 = GetGlobalPoolAllocator();
      *(uint *)(newFunction + 0x18) = 0;
      *(uint *)(newFunction + 0x10) = 0;
      *(uint *)(newFunction + 0x14) = 0;
      *(unsigned char **)(newFunction + 0x1c) = picBase2 + -0x610c;
      *(uint *)(newFunction + 0xc) = allocatorArg1;
      emptyRep = DAT_a7b7ba84;
      *(uint *)(newFunction + 0x20) = 0;
      clearedTypeBits = *(uint *)(newFunction + 0x40) & 0x9ff | 0x800;
      cr0 = (clearedTypeBits == 0) << 1;
      *(uint *)(newFunction + 0x24) = 0;
      *(uint *)(newFunction + 0x40) = clearedTypeBits;
      emptyRepRefCount = (int *)(emptyRep + 8);
      *(uint *)(newFunction + 0x28) = 0;
      *(uint *)(newFunction + 0x2c) = 0;
      *(uint *)(newFunction + 0x30) = 0;
      *(uint *)(newFunction + 0x34) = 0;
      *(uint *)(newFunction + 0x38) = 0;
      *(uint *)(newFunction + 0x3c) = 0;
      do {
        if (reservation != '\0') {
          storeWordConditionalIndexedResult = storeWordConditionalIndexed(*emptyRepRefCount + 1,0,emptyRepRefCount);
          *emptyRepRefCount = storeWordConditionalIndexedResult;
          cr0 = 2;
        }
      } while (!(bool)(cr0 >> 1));
      allocatorArg2 = GetGlobalPoolAllocator();
      *(uint *)(newFunction + 0x48) = emptyRep + 0xc;
      *(uint *)(newFunction + 0x44) = allocatorArg2;
      *(uint *)(newFunction + 0x4c) = constructorIdentifierOp;
      *(uint *)(newFunction + 0x50) = 0;
      yyvalNodeReg = yyvalNode;
      yyvalTypeOrFunction = newFunction;
      typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
      typeTmp7VtableReg = typeTmp7Vtable[0];
      break;
    }
    ctorAlloc4[0] = GetGlobalPoolAllocator();
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
              ((unsigned char *)&typeTmp1VtableOrStr1Alloc,"",(unsigned char *)ctorAlloc4);
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    newFunction = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x54);
    constructorIdentifierUserDef = *(uint *)(yyvsp + 0x24);
    constructorIdentifierOp2 = *(unsigned char **)(yyvsp + 4);
    *(unsigned char **)newFunction = (unsigned char *)(PTR_vtable_a7b7c0f4 + 8);
    *(unsigned char **)(newFunction + 4) = (unsigned char *)&typeTmp1VtableOrStr1Alloc;
    functionPool = (unsigned char *)GetGlobalPoolAllocator();
    *(unsigned char **)(newFunction + 0x18) = (unsigned char *)0x0;
    *(unsigned char **)(newFunction + 0x10) = (unsigned char *)0x0;
    *(unsigned char **)(newFunction + 0x14) = (unsigned char *)0x0;
    picBase2 = (unsigned char *)0xa7b8374c;
    *(unsigned char **)(newFunction + 0xc) = functionPool;
    constructorIdentifierUserDefWord8 = *(unsigned char **)(constructorIdentifierUserDef + 8);
    constructorIdentifierUserDefWordc = *(unsigned char **)(constructorIdentifierUserDef + 0xc);
    constructorIdentifierUserDefWord10 = *(unsigned char **)(constructorIdentifierUserDef + 0x10);
    scratchR7 = *(char **)(constructorIdentifierUserDef + 0x14);
    scratchR6 = *(char **)(constructorIdentifierUserDef + 0x18);
    constructorIdentifierUserDefWord1c = *(unsigned char **)(constructorIdentifierUserDef + 0x1c);
    constructorIdentifierUserDefWord4 = *(unsigned char **)(constructorIdentifierUserDef + 4);
    constructorIdentifierUserDefWord20 = *(unsigned char **)(constructorIdentifierUserDef + 0x20);
    *(undefined ***)(newFunction + 0x1c) = &PTR___ZN5TTypeD1Ev_a7b7d640;
    *(unsigned char **)(newFunction + 0x20) = constructorIdentifierUserDefWord4;
    *(unsigned char **)(newFunction + 0x24) = constructorIdentifierUserDefWord8;
    *(unsigned char **)(newFunction + 0x28) = constructorIdentifierUserDefWordc;
    *(unsigned char **)(newFunction + 0x2c) = constructorIdentifierUserDefWord10;
    *(char **)(newFunction + 0x30) = scratchR7;
    *(char **)(newFunction + 0x34) = scratchR6;
    *(unsigned char **)(newFunction + 0x38) = constructorIdentifierUserDefWord1c;
    *(unsigned char **)(newFunction + 0x3c) = constructorIdentifierUserDefWord20;
    functionTypeBitsWord = *(unsigned char **)(newFunction + 0x40);
    qualifierBits = *(uint *)(constructorIdentifierUserDef + 0x24) & 0xfe000000;
    *(unsigned char **)(newFunction + 0x40) = (unsigned char *)(qualifierBits | (uint)functionTypeBitsWord & 0x1ffffff);
    basicTypeBits = (*(uint *)(constructorIdentifierUserDef + 0x24) >> 0x13 & 0x3f) << 0x13;
    *(unsigned char **)(newFunction + 0x40) = (unsigned char *)(basicTypeBits | qualifierBits | (uint)functionTypeBitsWord & 0x7ffff);
    sizeFieldBits = *(uint *)(constructorIdentifierUserDef + 0x24) & 0x7f800;
    *(unsigned char **)(newFunction + 0x40) =
         (unsigned char *)(sizeFieldBits | basicTypeBits | qualifierBits | (uint)functionTypeBitsWord & 0x7ff);
    matrixBit = (*(uint *)(constructorIdentifierUserDef + 0x24) >> 10 & 1) << 10;
    *(unsigned char **)(newFunction + 0x40) =
         (unsigned char *)(matrixBit | sizeFieldBits | basicTypeBits | qualifierBits | (uint)functionTypeBitsWord & 0x3ff);
    *(unsigned char **)(newFunction + 0x40) =
         (unsigned char *)
         ((*(uint *)(constructorIdentifierUserDef + 0x24) >> 9 & 1) << 9 |
         matrixBit | sizeFieldBits | basicTypeBits | qualifierBits | (uint)functionTypeBitsWord & 0x1ff);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(newFunction + 0x44,(unsigned char *)&typeTmp1VtableOrStr1Alloc);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEmc(newFunction + 0x44,1,0x28);
    *(unsigned char **)(newFunction + 0x4c) = constructorIdentifierOp2;
    *(unsigned char **)(newFunction + 0x50) = (unsigned char *)0x0;
    refCountPtr = typeTmp1ArraySizeOrStr1Data + -4;
    destroyAlloc9[0] = typeTmp1VtableOrStr1Alloc;
    destroyRep = (unsigned char *)(typeTmp1ArraySizeOrStr1Data + -0xc);
    do {
      oldRefCount3 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount3 = (unsigned char *)storeWordConditionalIndexed(oldRefCount3 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount3;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    stillShared = 0 < (int)oldRefCount3;
    destroyAllocArg = destroyAlloc9;
    yyvalTypeOrFunction = newFunction;
    goto loopSetYyvalNodeReg2;
  case 0x17:
    reservedError = TParseContext__reservedErrorCheck(parseContext,*(uint *)yyvsp,*(unsigned char **)(yyvsp + 4));
    if (reservedError != 0) {
      TParseContext__recover(parseContext);
    }
    typeTmp1BitsOrPubQualifier = (unsigned char *)((uint)typeTmp1BitsOrPubQualifier & 0x9ff | 0x800);
    cr0 = (typeTmp1BitsOrPubQualifier == (unsigned char *)0x0) << 1;
    typeTmp1VtableOrStr1Alloc = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
    typeTmp1ArraySizeOrStr1Data = (unsigned char *)0x0;
    typeTmp1StructureOrPubSize = (unsigned char *)0x0;
    typeTmp1Word0cOrPubMatrix = (unsigned char *)0x0;
    typeTmp1TypeNameOrStr2Alloc = (unsigned char *)0x0;
    typeTmp1Word14OrStr2Data = (unsigned char *)0x0;
    typeAt850Word18 = (unsigned char *)0x0;
    typeTmp1MaxArraySize = (unsigned char *)0x0;
    typeTmp1Word20OrPubType = (unsigned char *)0x0;
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    newFunction = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x54);
    identifierString2 = *(unsigned char **)(yyvsp + 4);
    *(undefined **)newFunction = PTR_vtable_a7b7c0f4 + 8;
    *(unsigned char **)(newFunction + 4) = identifierString2;
    allocatorArg3 = GetGlobalPoolAllocator();
    *(uint *)(newFunction + 0x18) = 0;
    *(uint *)(newFunction + 0x10) = 0;
    *(uint *)(newFunction + 0x14) = 0;
    *(uint *)(newFunction + 0xc) = allocatorArg3;
    *(unsigned char **)(newFunction + 0x20) = typeTmp1ArraySizeOrStr1Data;
    *(unsigned char **)(newFunction + 0x24) = typeTmp1StructureOrPubSize;
    *(unsigned char **)(newFunction + 0x28) = typeTmp1Word0cOrPubMatrix;
    *(unsigned char **)(newFunction + 0x2c) = typeTmp1TypeNameOrStr2Alloc;
    *(unsigned char **)(newFunction + 0x30) = typeTmp1Word14OrStr2Data;
    *(unsigned char **)(newFunction + 0x34) = typeAt850Word18;
    *(undefined ***)(newFunction + 0x1c) = &PTR___ZN5TTypeD1Ev_a7b7d640;
    *(unsigned char **)(newFunction + 0x38) = typeTmp1MaxArraySize;
    *(unsigned char **)(newFunction + 0x3c) = typeTmp1Word20OrPubType;
    oldFunctionTypeBits = *(uint *)(newFunction + 0x40);
    qualifierBits = (uint)typeTmp1BitsOrPubQualifier & 0xfe000000;
    *(uint *)(newFunction + 0x40) = qualifierBits | oldFunctionTypeBits & 0x1ffffff;
    basicTypeBits = ((uint)typeTmp1BitsOrPubQualifier >> 0x13 & 0x3f) << 0x13;
    *(uint *)(newFunction + 0x40) = basicTypeBits | qualifierBits | oldFunctionTypeBits & 0x7ffff;
    sizeFieldBits = (uint)typeTmp1BitsOrPubQualifier & 0x7f800;
    *(uint *)(newFunction + 0x40) = sizeFieldBits | basicTypeBits | qualifierBits | oldFunctionTypeBits & 0x7ff;
    matrixBit = ((uint)typeTmp1BitsOrPubQualifier >> 10 & 1) << 10;
    *(uint *)(newFunction + 0x40) = matrixBit | sizeFieldBits | basicTypeBits | qualifierBits | oldFunctionTypeBits & 0x3ff;
    *(uint *)(newFunction + 0x40) =
         ((uint)typeTmp1BitsOrPubQualifier >> 9 & 1) << 9 | matrixBit | sizeFieldBits | basicTypeBits | qualifierBits | oldFunctionTypeBits & 0x1ff;
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(newFunction + 0x44,identifierString2);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEmc(newFunction + 0x44,1,0x28);
    *(uint *)(newFunction + 0x50) = 0;
    *(uint *)(newFunction + 0x4c) = 0;
    yyvalNodeReg = yyvalNode;
    yyvalTypeOrFunction = newFunction;
    typeTmp1VtableOrStr1Alloc = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    break;
  case 0x18:
    yyval = *(uint *)yyvsp;
    yyvalOp = 0x68;
    break;
  case 0x19:
    yyval = *(uint *)yyvsp;
    yyvalOp = 0x66;
    break;
  case 0x1a:
    yyval = *(uint *)yyvsp;
    yyvalOp = 0x67;
    break;
  case 0x1b:
    yyval = *(uint *)yyvsp;
    yyvalOp = 0x69;
    break;
  case 0x1c:
    yyval = *(uint *)yyvsp;
    yyvalOp = 0x6a;
    break;
  case 0x1d:
    yyval = *(uint *)yyvsp;
    yyvalOp = 0x6b;
    break;
  case 0x1e:
    if (1 < *(uint *)((int)parseContext + 0xc)) {
      scratchR7 = "";
      scratchR6 = "bvec2";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," supported in vertex/fragment shaders only ",
                 "bvec2","","",staleR9Value,scratchR10);
      TParseContext__recover(parseContext);
    }
    yyval = *(uint *)yyvsp;
    yyvalOp = 0x6c;
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    break;
  case 0x1f:
    if (1 < *(uint *)((int)parseContext + 0xc)) {
      scratchR7 = "";
      scratchR6 = "bvec3";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," supported in vertex/fragment shaders only ",
                 "bvec3","","",staleR9Value,scratchR10);
      TParseContext__recover(parseContext);
    }
    yyval = *(uint *)yyvsp;
    yyvalOp = 0x6d;
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    break;
  case 0x20:
    if (1 < *(uint *)((int)parseContext + 0xc)) {
      scratchR7 = "";
      scratchR6 = "bvec4";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," supported in vertex/fragment shaders only ",
                 "bvec4","","",staleR9Value,scratchR10);
      TParseContext__recover(parseContext);
    }
    yyval = *(uint *)yyvsp;
    yyvalOp = 0x6e;
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    break;
  case 0x21:
    if (1 < *(uint *)((int)parseContext + 0xc)) {
      scratchR7 = "";
      scratchR6 = "ivec2";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," supported in vertex/fragment shaders only ",
                 "ivec2","","",staleR9Value,scratchR10);
      TParseContext__recover(parseContext);
    }
    yyval = *(uint *)yyvsp;
    yyvalOp = 0x6f;
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    break;
  case 0x22:
    if (1 < *(uint *)((int)parseContext + 0xc)) {
      scratchR7 = "";
      scratchR6 = "ivec3";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," supported in vertex/fragment shaders only ",
                 "ivec3","","",staleR9Value,scratchR10);
      TParseContext__recover(parseContext);
    }
    yyval = *(uint *)yyvsp;
    yyvalOp = 0x70;
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    break;
  case 0x23:
    if (1 < *(uint *)((int)parseContext + 0xc)) {
      scratchR7 = "";
      scratchR6 = "ivec4";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," supported in vertex/fragment shaders only ",
                 "ivec4","","",staleR9Value,scratchR10);
      TParseContext__recover(parseContext);
    }
    yyval = *(uint *)yyvsp;
    yyvalOp = 0x71;
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    break;
  case 0x24:
    if (1 < *(uint *)((int)parseContext + 0xc)) {
      scratchR7 = "";
      scratchR6 = "mat2";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," supported in vertex/fragment shaders only ","mat2"
                 ,"","",staleR9Value,scratchR10);
      TParseContext__recover(parseContext);
    }
    yyval = *(uint *)yyvsp;
    yyvalOp = 0x72;
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    break;
  case 0x25:
    if (1 < *(uint *)((int)parseContext + 0xc)) {
      scratchR7 = "";
      scratchR6 = "mat3";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," supported in vertex/fragment shaders only ","mat3"
                 ,"","",staleR9Value,scratchR10);
      TParseContext__recover(parseContext);
    }
    yyval = *(uint *)yyvsp;
    yyvalOp = 0x73;
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    break;
  case 0x26:
    if (1 < *(uint *)((int)parseContext + 0xc)) {
      scratchR7 = "";
      scratchR6 = "mat4";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," supported in vertex/fragment shaders only ","mat4"
                 ,"","",staleR9Value,scratchR10);
      TParseContext__recover(parseContext);
    }
    yyval = *(uint *)yyvsp;
    yyvalOp = 0x74;
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    break;
  case 0x27:
    yyvalUserDef = (unsigned char *)(*(uint *)(yyvsp + 8) + 0xc);
    typeTmp1Word20OrPubType = (unsigned char *)0xe;
    pubMatrix = (unsigned char *)0x0;
    typeTmp2VtableOrPubArray = (unsigned char *)0x0;
    yyvalQualifierOrParamType = (unsigned char *)
                (uint)((uint)((*(int **)((int)parseContext + 4))[1] - **(int **)((int)parseContext + 4) >> 2)
                      < 4);
    pubSize = (unsigned char *)0x1;
    yyvalTypeLine = *(unsigned char **)yyvsp;
    yyvalArray = (unsigned char *)0x0;
    typeTmp1Word0cOrPubMatrix = (unsigned char *)0x0;
    typeTmp1TypeNameOrStr2Alloc = (unsigned char *)0x0;
    yyvalMatrix = (unsigned char *)0x0;
    yyvalOp = 0x75;
    yyvalTypeOrFunction = (unsigned char *)0xe;
    yyvalSize = (unsigned char *)0x1;
    typeTmp1VtableOrStr1Alloc = (unsigned char *)0xe;
    typeTmp1StructureOrPubSize = (unsigned char *)0x1;
    yyval = *(uint *)yyvsp;
    typeTmp1ArraySizeOrStr1Data = yyvalQualifierOrParamType;
    typeTmp1Word14OrStr2Data = yyvalUserDef;
    pubCopy850Line = yyvalTypeLine;
    typeTmp1BitsOrPubQualifier = yyvalQualifierOrParamType;
    typeTmp2ArraySizeOrPubUserDef = yyvalUserDef;
    typeTmp2StructureOrPubLine = yyvalTypeLine;
    break;
  case 0x29:
    lValueError = TParseContext__lValueErrorCheck
                       (parseContext,*(uint *)(yyvsp + -0x2c),"++",*(unsigned char **)(yyvsp + 8),
                        scratchR7,staleR8Value,staleR9Value,scratchR10);
    if (lValueError != 0) {
      TParseContext__recover(parseContext);
    }
    scratchR6 = *(char **)(yyvsp + -0x2c);
    scratchR7 = *(char **)((int)parseContext + 4);
    yyvalNode = (unsigned char *)
                TIntermediate__addUnaryMath
                          (*(unsigned char **)parseContext,0xb,*(uint *)(yyvsp + 8),scratchR6,scratchR7,
                           staleR8Value,staleR9Value);
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    if (yyvalNode != (unsigned char *)0x0) break;
    scratchR6 = (char *)&typeTmp1VtableOrStr1Alloc;
    TType__getCompleteString(scratchR6,*(uint *)(yyvsp + 8) + 8);
    TParseContext__unaryOpError(parseContext,*(uint *)(yyvsp + -0x2c),"++",scratchR6);
    refCountPtr = typeTmp1ArraySizeOrStr1Data + -4;
    destroyRep = (unsigned char *)(typeTmp1ArraySizeOrStr1Data + -0xc);
    destroyAlloc10[0] = typeTmp1VtableOrStr1Alloc;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    stillShared = 0 < (int)oldRefCount2;
    destroyAllocArg = destroyAlloc10;
    goto checkStillShared3;
  case 0x2a:
    lValueError = TParseContext__lValueErrorCheck
                       (parseContext,*(uint *)(yyvsp + -0x2c),"--",*(unsigned char **)(yyvsp + 8),
                        scratchR7,staleR8Value,staleR9Value,scratchR10);
    if (lValueError != 0) {
      TParseContext__recover(parseContext);
    }
    scratchR6 = *(char **)(yyvsp + -0x2c);
    scratchR7 = *(char **)((int)parseContext + 4);
    yyvalNode = (unsigned char *)
                TIntermediate__addUnaryMath
                          (*(unsigned char **)parseContext,0xc,*(uint *)(yyvsp + 8),scratchR6,scratchR7,
                           staleR8Value,staleR9Value);
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    if (yyvalNode != (unsigned char *)0x0) break;
    scratchR6 = (char *)&typeTmp1VtableOrStr1Alloc;
    TType__getCompleteString(scratchR6,*(uint *)(yyvsp + 8) + 8);
    TParseContext__unaryOpError(parseContext,*(uint *)(yyvsp + -0x2c),"--",scratchR6);
    refCountPtr = typeTmp1ArraySizeOrStr1Data + -4;
    destroyRep = (unsigned char *)(typeTmp1ArraySizeOrStr1Data + -0xc);
    destroyAlloc11[0] = typeTmp1VtableOrStr1Alloc;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    if ((int)oldRefCount2 < 1) {
      destroyAllocArg = destroyAlloc11;
      goto callZNSbIcSt11charTraitsIcE14poolAllocatorIcEE4Rep10MDestroyERKS2;
    }
    goto loopCallTParseContext_recover3;
  case 0x2b:
    if (*(uint *)(yyvsp + -0x28) == 0) goto yynCase2;
    scratchR6 = *(char **)(yyvsp + -0x2c);
    scratchR7 = *(char **)((int)parseContext + 4);
    yyvalNode = (unsigned char *)
                TIntermediate__addUnaryMath
                          (*(unsigned char **)parseContext,*(uint *)(yyvsp + -0x28),
                           *(uint *)(yyvsp + 8),scratchR6,scratchR7,staleR8Value,staleR9Value);
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    if (yyvalNode != (unsigned char *)0x0) break;
    unaryOperatorOp = *(uint *)(yyvsp + -0x28);
    msgText2 = "";
    if (unaryOperatorOp == 6) {
      msgText2 = "!";
    }
    else if ((int)unaryOperatorOp < 7) {
      if (unaryOperatorOp == 5) {
        msgText2 = "-";
      }
    }
    else if (unaryOperatorOp == 8) {
      msgText2 = "~";
    }
    scratchR6 = (char *)&typeTmp1VtableOrStr1Alloc;
    TType__getCompleteString(scratchR6,*(uint *)(yyvsp + 8) + 8);
    TParseContext__unaryOpError(parseContext,*(uint *)(yyvsp + -0x2c),msgText2,scratchR6);
    refCountPtr = typeTmp1ArraySizeOrStr1Data + -4;
    destroyRep = (unsigned char *)(typeTmp1ArraySizeOrStr1Data + -0xc);
    destroyAlloc12[0] = typeTmp1VtableOrStr1Alloc;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    stillShared = 0 < (int)oldRefCount2;
    destroyAllocArg = destroyAlloc12;
    goto checkStillShared3;
  case 0x2c:
    yyval = *(uint *)yyvsp;
    yyvalOp = 0;
    break;
  case 0x2d:
    yyval = *(uint *)yyvsp;
    yyvalOp = 5;
    break;
  case 0x2e:
    yyval = *(uint *)yyvsp;
    yyvalOp = 6;
    break;
  case 0x2f:
    if (1 < *(int *)((int)parseContext + 0xc) - 2U) {
      scratchR7 = "";
      scratchR6 = "~";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," reserved for future use ","~","","",staleR9Value,
                 scratchR10);
      TParseContext__recover(parseContext);
    }
    yyval = *(uint *)yyvsp;
    yyvalOp = 8;
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    break;
  case 0x31:
    if (1 < *(uint *)((int)parseContext + 0xc)) {
      TParseContext__error
                ((int)parseContext,*(char **)(yyvsp + -0x2c),
                 " supported in vertex/fragment shaders only ","*","","",staleR9Value,scratchR10);
      TParseContext__recover(parseContext);
    }
    scratchR6 = *(char **)(yyvsp + 8);
    scratchR7 = *(char **)(yyvsp + -0x2c);
    yyvalNode = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(unsigned char **)parseContext,0x15,*(uint *)(yyvsp + -0x50),scratchR6,
                           scratchR7,*(undefined4 *)((int)parseContext + 4));
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    if (yyvalNode != (unsigned char *)0x0) break;
    scratchR7 = (char *)&typeTmp1VtableOrStr1Alloc;
    scratchR6 = (char *)&typeTmp1TypeNameOrStr2Alloc;
    TType__getCompleteString(scratchR7,*(uint *)(yyvsp + 8) + 8);
    TType__getCompleteString(scratchR6,*(uint *)(yyvsp + -0x50) + 8);
    TParseContext__binaryOpError(parseContext,*(uint *)(yyvsp + -0x2c),"*",scratchR6,scratchR7);
    refCountPtr = typeTmp1Word14OrStr2Data + -4;
    destroyAlloc13[0] = typeTmp1TypeNameOrStr2Alloc;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    if ((int)oldRefCount2 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(typeTmp1Word14OrStr2Data + -0xc),destroyAlloc13);
    }
    refCountPtr = typeTmp1ArraySizeOrStr1Data + -4;
    destroyRep = (unsigned char *)(typeTmp1ArraySizeOrStr1Data + -0xc);
    destroyAlloc14[0] = typeTmp1VtableOrStr1Alloc;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    stillShared = 0 < (int)oldRefCount2;
    destroyAllocArg = destroyAlloc14;
    goto checkStillShared;
  case 0x32:
    if (1 < *(uint *)((int)parseContext + 0xc)) {
      TParseContext__error
                ((int)parseContext,*(char **)(yyvsp + -0x2c),
                 " supported in vertex/fragment shaders only ","/","","",staleR9Value,scratchR10);
      TParseContext__recover(parseContext);
    }
    scratchR6 = *(char **)(yyvsp + 8);
    scratchR7 = *(char **)(yyvsp + -0x2c);
    yyvalNode = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(unsigned char **)parseContext,0x16,*(uint *)(yyvsp + -0x50),scratchR6,
                           scratchR7,*(undefined4 *)((int)parseContext + 4));
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    if (yyvalNode != (unsigned char *)0x0) break;
    scratchR7 = (char *)&typeTmp1VtableOrStr1Alloc;
    scratchR6 = (char *)&typeTmp1TypeNameOrStr2Alloc;
    TType__getCompleteString(scratchR7,*(uint *)(yyvsp + 8) + 8);
    TType__getCompleteString(scratchR6,*(uint *)(yyvsp + -0x50) + 8);
    TParseContext__binaryOpError(parseContext,*(uint *)(yyvsp + -0x2c),"/",scratchR6,scratchR7);
    refCountPtr = typeTmp1Word14OrStr2Data + -4;
    destroyAlloc15[0] = typeTmp1TypeNameOrStr2Alloc;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    if ((int)oldRefCount2 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(typeTmp1Word14OrStr2Data + -0xc),destroyAlloc15);
    }
    refCountPtr = typeTmp1ArraySizeOrStr1Data + -4;
    destroyRep = (unsigned char *)(typeTmp1ArraySizeOrStr1Data + -0xc);
    destroyAlloc16[0] = typeTmp1VtableOrStr1Alloc;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    stillShared = 0 < (int)oldRefCount2;
    destroyAllocArg = destroyAlloc16;
    goto checkStillShared;
  case 0x33:
    if (1 < *(int *)((int)parseContext + 0xc) - 2U) {
      TParseContext__error
                ((int)parseContext,*(char **)(yyvsp + -0x2c)," reserved for future use ","%","","",
                 staleR9Value,scratchR10);
      TParseContext__recover(parseContext);
    }
    scratchR6 = *(char **)(yyvsp + 8);
    scratchR7 = *(char **)(yyvsp + -0x2c);
    yyvalNode = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(unsigned char **)parseContext,0x17,*(uint *)(yyvsp + -0x50),scratchR6,
                           scratchR7,*(undefined4 *)((int)parseContext + 4));
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    if (yyvalNode != (unsigned char *)0x0) break;
    scratchR7 = (char *)&typeTmp1VtableOrStr1Alloc;
    scratchR6 = (char *)&typeTmp1TypeNameOrStr2Alloc;
    TType__getCompleteString(scratchR7,*(uint *)(yyvsp + 8) + 8);
    TType__getCompleteString(scratchR6,*(uint *)(yyvsp + -0x50) + 8);
    TParseContext__binaryOpError(parseContext,*(uint *)(yyvsp + -0x2c),"%",scratchR6,scratchR7);
    refCountPtr = typeTmp1Word14OrStr2Data + -4;
    destroyAlloc17[0] = typeTmp1TypeNameOrStr2Alloc;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    if ((int)oldRefCount2 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(typeTmp1Word14OrStr2Data + -0xc),destroyAlloc17);
    }
    refCountPtr = typeTmp1ArraySizeOrStr1Data + -4;
    destroyRep = (unsigned char *)(typeTmp1ArraySizeOrStr1Data + -0xc);
    destroyAlloc18[0] = typeTmp1VtableOrStr1Alloc;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    stillShared = 0 < (int)oldRefCount2;
    destroyAllocArg = destroyAlloc18;
    goto checkStillShared;
  case 0x35:
    scratchR6 = *(char **)(yyvsp + 8);
    scratchR7 = *(char **)(yyvsp + -0x2c);
    yyvalNode = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(unsigned char **)parseContext,0x13,*(uint *)(yyvsp + -0x50),scratchR6,
                           scratchR7,*(undefined4 *)((int)parseContext + 4));
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    if (yyvalNode != (unsigned char *)0x0) break;
    scratchR7 = (char *)&typeTmp1VtableOrStr1Alloc;
    scratchR6 = (char *)&typeTmp1TypeNameOrStr2Alloc;
    TType__getCompleteString(scratchR7,*(uint *)(yyvsp + 8) + 8);
    TType__getCompleteString(scratchR6,*(uint *)(yyvsp + -0x50) + 8);
    TParseContext__binaryOpError(parseContext,*(uint *)(yyvsp + -0x2c),"+",scratchR6,scratchR7);
    refCountPtr = typeTmp1Word14OrStr2Data + -4;
    destroyAlloc19[0] = typeTmp1TypeNameOrStr2Alloc;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    if ((int)oldRefCount2 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(typeTmp1Word14OrStr2Data + -0xc),destroyAlloc19);
    }
    refCountPtr = typeTmp1ArraySizeOrStr1Data + -4;
    destroyRep = (unsigned char *)(typeTmp1ArraySizeOrStr1Data + -0xc);
    destroyAlloc20[0] = typeTmp1VtableOrStr1Alloc;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    stillShared = 0 < (int)oldRefCount2;
    destroyAllocArg = destroyAlloc20;
    goto checkStillShared;
  case 0x36:
    scratchR6 = *(char **)(yyvsp + 8);
    scratchR7 = *(char **)(yyvsp + -0x2c);
    yyvalNode = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(unsigned char **)parseContext,0x14,*(uint *)(yyvsp + -0x50),scratchR6,
                           scratchR7,*(undefined4 *)((int)parseContext + 4));
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    if (yyvalNode != (unsigned char *)0x0) break;
    scratchR7 = (char *)&typeTmp1VtableOrStr1Alloc;
    scratchR6 = (char *)&typeTmp1TypeNameOrStr2Alloc;
    TType__getCompleteString(scratchR7,*(uint *)(yyvsp + 8) + 8);
    TType__getCompleteString(scratchR6,*(uint *)(yyvsp + -0x50) + 8);
    TParseContext__binaryOpError(parseContext,*(uint *)(yyvsp + -0x2c),"-",scratchR6,scratchR7);
    refCountPtr = typeTmp1Word14OrStr2Data + -4;
    destroyAlloc21[0] = typeTmp1TypeNameOrStr2Alloc;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    if ((int)oldRefCount2 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(typeTmp1Word14OrStr2Data + -0xc),destroyAlloc21);
    }
    refCountPtr = typeTmp1ArraySizeOrStr1Data + -4;
    destroyRep = (unsigned char *)(typeTmp1ArraySizeOrStr1Data + -0xc);
    destroyAlloc22[0] = typeTmp1VtableOrStr1Alloc;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    stillShared = 0 < (int)oldRefCount2;
    destroyAllocArg = destroyAlloc22;
    goto checkStillShared;
  case 0x38:
    if (1 < *(int *)((int)parseContext + 0xc) - 2U) {
      TParseContext__error
                ((int)parseContext,*(char **)(yyvsp + -0x2c)," reserved for future use ","<<","","",
                 staleR9Value,scratchR10);
      TParseContext__recover(parseContext);
    }
    scratchR6 = *(char **)(yyvsp + 8);
    scratchR7 = *(char **)(yyvsp + -0x2c);
    yyvalNode = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(unsigned char **)parseContext,0x19,*(uint *)(yyvsp + -0x50),scratchR6,
                           scratchR7,*(undefined4 *)((int)parseContext + 4));
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    if (yyvalNode != (unsigned char *)0x0) break;
    scratchR7 = (char *)&typeTmp1VtableOrStr1Alloc;
    scratchR6 = (char *)&typeTmp1TypeNameOrStr2Alloc;
    TType__getCompleteString(scratchR7,*(uint *)(yyvsp + 8) + 8);
    TType__getCompleteString(scratchR6,*(uint *)(yyvsp + -0x50) + 8);
    TParseContext__binaryOpError(parseContext,*(uint *)(yyvsp + -0x2c),"<<",scratchR6,scratchR7);
    refCountPtr = typeTmp1Word14OrStr2Data + -4;
    destroyAlloc23[0] = typeTmp1TypeNameOrStr2Alloc;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    if ((int)oldRefCount2 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(typeTmp1Word14OrStr2Data + -0xc),destroyAlloc23);
    }
    refCountPtr = typeTmp1ArraySizeOrStr1Data + -4;
    destroyRep = (unsigned char *)(typeTmp1ArraySizeOrStr1Data + -0xc);
    destroyAlloc24[0] = typeTmp1VtableOrStr1Alloc;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    stillShared = 0 < (int)oldRefCount2;
    destroyAllocArg = destroyAlloc24;
    goto checkStillShared;
  case 0x39:
    if (1 < *(int *)((int)parseContext + 0xc) - 2U) {
      TParseContext__error
                ((int)parseContext,*(char **)(yyvsp + -0x2c)," reserved for future use ",">>","","",
                 staleR9Value,scratchR10);
      TParseContext__recover(parseContext);
    }
    scratchR6 = *(char **)(yyvsp + 8);
    scratchR7 = *(char **)(yyvsp + -0x2c);
    yyvalNode = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(unsigned char **)parseContext,0x18,*(uint *)(yyvsp + -0x50),scratchR6,
                           scratchR7,*(undefined4 *)((int)parseContext + 4));
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    if (yyvalNode != (unsigned char *)0x0) break;
    scratchR7 = (char *)&typeTmp1VtableOrStr1Alloc;
    scratchR6 = (char *)&typeTmp1TypeNameOrStr2Alloc;
    TType__getCompleteString(scratchR7,*(uint *)(yyvsp + 8) + 8);
    TType__getCompleteString(scratchR6,*(uint *)(yyvsp + -0x50) + 8);
    TParseContext__binaryOpError(parseContext,*(uint *)(yyvsp + -0x2c),">>",scratchR6,scratchR7);
    refCountPtr = typeTmp1Word14OrStr2Data + -4;
    destroyAlloc25[0] = typeTmp1TypeNameOrStr2Alloc;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    if ((int)oldRefCount2 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(typeTmp1Word14OrStr2Data + -0xc),destroyAlloc25);
    }
    refCountPtr = typeTmp1ArraySizeOrStr1Data + -4;
    destroyRep = (unsigned char *)(typeTmp1ArraySizeOrStr1Data + -0xc);
    destroyAlloc26[0] = typeTmp1VtableOrStr1Alloc;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    stillShared = 0 < (int)oldRefCount2;
    destroyAllocArg = destroyAlloc26;
    goto checkStillShared;
  case 0x3b:
    scratchR6 = *(char **)(yyvsp + 8);
    scratchR7 = *(char **)(yyvsp + -0x2c);
    yyvalNode = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(unsigned char **)parseContext,0x21,*(uint *)(yyvsp + -0x50),scratchR6,
                           scratchR7,*(undefined4 *)((int)parseContext + 4));
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    if (yyvalNode != (unsigned char *)0x0) break;
    scratchR7 = (char *)&typeTmp1VtableOrStr1Alloc;
    TType__getCompleteString(scratchR7,*(uint *)(yyvsp + 8) + 8);
    TType__getCompleteString(&typeTmp1TypeNameOrStr2Alloc,*(uint *)(yyvsp + -0x50) + 8);
    TParseContext__binaryOpError(parseContext,*(uint *)(yyvsp + -0x2c),"<",&typeTmp1TypeNameOrStr2Alloc,scratchR7);
    refCountPtr = typeTmp1Word14OrStr2Data + -4;
    destroyAlloc27[0] = typeTmp1TypeNameOrStr2Alloc;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    if ((int)oldRefCount2 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(typeTmp1Word14OrStr2Data + -0xc),destroyAlloc27);
    }
    refCountPtr = typeTmp1ArraySizeOrStr1Data + -4;
    destroyRep = (unsigned char *)(typeTmp1ArraySizeOrStr1Data + -0xc);
    destroyAlloc28[0] = typeTmp1VtableOrStr1Alloc;
    do {
      oldRefCount = *(uint *)refCountPtr;
      if (reservation != '\0') {
        newRefCount = storeWordConditionalIndexed(oldRefCount - 1,0,refCountPtr);
        *(uint *)refCountPtr = newRefCount;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    stillShared = 0 < (int)oldRefCount;
    destroyAllocArg = destroyAlloc28;
    goto checkStillShared2;
  case 0x3c:
    scratchR6 = *(char **)(yyvsp + 8);
    scratchR7 = *(char **)(yyvsp + -0x2c);
    yyvalNode = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(unsigned char **)parseContext,0x22,*(uint *)(yyvsp + -0x50),scratchR6,
                           scratchR7,*(undefined4 *)((int)parseContext + 4));
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    if (yyvalNode != (unsigned char *)0x0) break;
    scratchR7 = (char *)&typeTmp1VtableOrStr1Alloc;
    TType__getCompleteString(scratchR7,*(uint *)(yyvsp + 8) + 8);
    TType__getCompleteString(&typeTmp1TypeNameOrStr2Alloc,*(uint *)(yyvsp + -0x50) + 8);
    TParseContext__binaryOpError(parseContext,*(uint *)(yyvsp + -0x2c),">",&typeTmp1TypeNameOrStr2Alloc,scratchR7);
    refCountPtr = typeTmp1Word14OrStr2Data + -4;
    destroyAlloc29[0] = typeTmp1TypeNameOrStr2Alloc;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    if ((int)oldRefCount2 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(typeTmp1Word14OrStr2Data + -0xc),destroyAlloc29);
    }
    refCountPtr = typeTmp1ArraySizeOrStr1Data + -4;
    destroyRep = (unsigned char *)(typeTmp1ArraySizeOrStr1Data + -0xc);
    destroyAlloc30[0] = typeTmp1VtableOrStr1Alloc;
    do {
      oldRefCount = *(uint *)refCountPtr;
      if (reservation != '\0') {
        newRefCount = storeWordConditionalIndexed(oldRefCount - 1,0,refCountPtr);
        *(uint *)refCountPtr = newRefCount;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    stillShared = 0 < (int)oldRefCount;
    destroyAllocArg = destroyAlloc30;
    goto checkStillShared2;
  case 0x3d:
    scratchR6 = *(char **)(yyvsp + 8);
    scratchR7 = *(char **)(yyvsp + -0x2c);
    yyvalNode = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(unsigned char **)parseContext,0x23,*(uint *)(yyvsp + -0x50),scratchR6,
                           scratchR7,*(undefined4 *)((int)parseContext + 4));
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    if (yyvalNode != (unsigned char *)0x0) break;
    scratchR7 = (char *)&typeTmp1VtableOrStr1Alloc;
    TType__getCompleteString(scratchR7,*(uint *)(yyvsp + 8) + 8);
    TType__getCompleteString(&typeTmp1TypeNameOrStr2Alloc,*(uint *)(yyvsp + -0x50) + 8);
    TParseContext__binaryOpError(parseContext,*(uint *)(yyvsp + -0x2c),"<=",&typeTmp1TypeNameOrStr2Alloc,scratchR7);
    refCountPtr = typeTmp1Word14OrStr2Data + -4;
    destroyAlloc31[0] = typeTmp1TypeNameOrStr2Alloc;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    if ((int)oldRefCount2 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(typeTmp1Word14OrStr2Data + -0xc),destroyAlloc31);
    }
    refCountPtr = typeTmp1ArraySizeOrStr1Data + -4;
    destroyRep = (unsigned char *)(typeTmp1ArraySizeOrStr1Data + -0xc);
    destroyAlloc32[0] = typeTmp1VtableOrStr1Alloc;
    do {
      oldRefCount = *(uint *)refCountPtr;
      if (reservation != '\0') {
        newRefCount = storeWordConditionalIndexed(oldRefCount - 1,0,refCountPtr);
        *(uint *)refCountPtr = newRefCount;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    stillShared = 0 < (int)oldRefCount;
    destroyAllocArg = destroyAlloc32;
    goto checkStillShared2;
  case 0x3e:
    scratchR6 = *(char **)(yyvsp + 8);
    scratchR7 = *(char **)(yyvsp + -0x2c);
    yyvalNode = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(unsigned char **)parseContext,0x24,*(uint *)(yyvsp + -0x50),scratchR6,
                           scratchR7,*(undefined4 *)((int)parseContext + 4));
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    if (yyvalNode != (unsigned char *)0x0) break;
    scratchR7 = (char *)&typeTmp1VtableOrStr1Alloc;
    TType__getCompleteString(scratchR7,*(uint *)(yyvsp + 8) + 8);
    TType__getCompleteString(&typeTmp1TypeNameOrStr2Alloc,*(uint *)(yyvsp + -0x50) + 8);
    TParseContext__binaryOpError(parseContext,*(uint *)(yyvsp + -0x2c),">=",&typeTmp1TypeNameOrStr2Alloc,scratchR7);
    refCountPtr = typeTmp1Word14OrStr2Data + -4;
    destroyAlloc33[0] = typeTmp1TypeNameOrStr2Alloc;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    if ((int)oldRefCount2 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(typeTmp1Word14OrStr2Data + -0xc),destroyAlloc33);
    }
    refCountPtr = typeTmp1ArraySizeOrStr1Data + -4;
    destroyRep = (unsigned char *)(typeTmp1ArraySizeOrStr1Data + -0xc);
    destroyAlloc34[0] = typeTmp1VtableOrStr1Alloc;
    do {
      oldRefCount = *(uint *)refCountPtr;
      if (reservation != '\0') {
        newRefCount = storeWordConditionalIndexed(oldRefCount - 1,0,refCountPtr);
        *(uint *)refCountPtr = newRefCount;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    stillShared = 0 < (int)oldRefCount;
    destroyAllocArg = destroyAlloc34;
    goto checkStillShared2;
  case 0x40:
    scratchR6 = *(char **)(yyvsp + 8);
    scratchR7 = *(char **)(yyvsp + -0x2c);
    yyvalNode = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(unsigned char **)parseContext,0x1d,*(uint *)(yyvsp + -0x50),scratchR6,
                           scratchR7,*(undefined4 *)((int)parseContext + 4));
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    if (yyvalNode != (unsigned char *)0x0) break;
    scratchR7 = (char *)&typeTmp1VtableOrStr1Alloc;
    TType__getCompleteString(scratchR7,*(uint *)(yyvsp + 8) + 8);
    TType__getCompleteString(&typeTmp1TypeNameOrStr2Alloc,*(uint *)(yyvsp + -0x50) + 8);
    TParseContext__binaryOpError(parseContext,*(uint *)(yyvsp + -0x2c),"==",&typeTmp1TypeNameOrStr2Alloc,scratchR7);
    refCountPtr = typeTmp1Word14OrStr2Data + -4;
    destroyAlloc35[0] = typeTmp1TypeNameOrStr2Alloc;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    if ((int)oldRefCount2 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(typeTmp1Word14OrStr2Data + -0xc),destroyAlloc35);
    }
    refCountPtr = typeTmp1ArraySizeOrStr1Data + -4;
    destroyRep = (unsigned char *)(typeTmp1ArraySizeOrStr1Data + -0xc);
    destroyAlloc36[0] = typeTmp1VtableOrStr1Alloc;
    do {
      oldRefCount = *(uint *)refCountPtr;
      if (reservation != '\0') {
        newRefCount = storeWordConditionalIndexed(oldRefCount - 1,0,refCountPtr);
        *(uint *)refCountPtr = newRefCount;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    stillShared = 0 < (int)oldRefCount;
    destroyAllocArg = destroyAlloc36;
    goto checkStillShared2;
  case 0x41:
    scratchR6 = *(char **)(yyvsp + 8);
    scratchR7 = *(char **)(yyvsp + -0x2c);
    yyvalNode = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(unsigned char **)parseContext,0x1e,*(uint *)(yyvsp + -0x50),scratchR6,
                           scratchR7,*(undefined4 *)((int)parseContext + 4));
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    if (yyvalNode != (unsigned char *)0x0) break;
    scratchR7 = (char *)&typeTmp1VtableOrStr1Alloc;
    TType__getCompleteString(scratchR7,*(uint *)(yyvsp + 8) + 8);
    TType__getCompleteString(&typeTmp1TypeNameOrStr2Alloc,*(uint *)(yyvsp + -0x50) + 8);
    TParseContext__binaryOpError(parseContext,*(uint *)(yyvsp + -0x2c),"!=",&typeTmp1TypeNameOrStr2Alloc,scratchR7);
    refCountPtr = typeTmp1Word14OrStr2Data + -4;
    destroyAlloc37[0] = typeTmp1TypeNameOrStr2Alloc;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    if ((int)oldRefCount2 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(typeTmp1Word14OrStr2Data + -0xc),destroyAlloc37);
    }
    refCountPtr = typeTmp1ArraySizeOrStr1Data + -4;
    destroyRep = (unsigned char *)(typeTmp1ArraySizeOrStr1Data + -0xc);
    destroyAlloc38[0] = typeTmp1VtableOrStr1Alloc;
    do {
      oldRefCount = *(uint *)refCountPtr;
      if (reservation != '\0') {
        newRefCount = storeWordConditionalIndexed(oldRefCount - 1,0,refCountPtr);
        *(uint *)refCountPtr = newRefCount;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    stillShared = 0 < (int)oldRefCount;
    destroyAllocArg = destroyAlloc38;
    goto checkStillShared2;
  case 0x43:
    if (1 < *(int *)((int)parseContext + 0xc) - 2U) {
      TParseContext__error
                ((int)parseContext,*(char **)(yyvsp + -0x2c)," reserved for future use ","&","","",
                 staleR9Value,scratchR10);
      TParseContext__recover(parseContext);
    }
    scratchR6 = *(char **)(yyvsp + 8);
    scratchR7 = *(char **)(yyvsp + -0x2c);
    yyvalNode = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(unsigned char **)parseContext,0x1a,*(uint *)(yyvsp + -0x50),scratchR6,
                           scratchR7,*(undefined4 *)((int)parseContext + 4));
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    if (yyvalNode != (unsigned char *)0x0) break;
    scratchR7 = (char *)&typeTmp1VtableOrStr1Alloc;
    scratchR6 = (char *)&typeTmp1TypeNameOrStr2Alloc;
    TType__getCompleteString(scratchR7,*(uint *)(yyvsp + 8) + 8);
    TType__getCompleteString(scratchR6,*(uint *)(yyvsp + -0x50) + 8);
    TParseContext__binaryOpError(parseContext,*(uint *)(yyvsp + -0x2c),"&",scratchR6,scratchR7);
    refCountPtr = typeTmp1Word14OrStr2Data + -4;
    destroyAlloc39[0] = typeTmp1TypeNameOrStr2Alloc;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    if ((int)oldRefCount2 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(typeTmp1Word14OrStr2Data + -0xc),destroyAlloc39);
    }
    refCountPtr = typeTmp1ArraySizeOrStr1Data + -4;
    destroyRep = (unsigned char *)(typeTmp1ArraySizeOrStr1Data + -0xc);
    destroyAlloc40[0] = typeTmp1VtableOrStr1Alloc;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    stillShared = 0 < (int)oldRefCount2;
    destroyAllocArg = destroyAlloc40;
    goto checkStillShared;
  case 0x45:
    if (1 < *(int *)((int)parseContext + 0xc) - 2U) {
      TParseContext__error
                ((int)parseContext,*(char **)(yyvsp + -0x2c)," reserved for future use ","^","","",
                 staleR9Value,scratchR10);
      TParseContext__recover(parseContext);
    }
    scratchR6 = *(char **)(yyvsp + 8);
    scratchR7 = *(char **)(yyvsp + -0x2c);
    yyvalNode = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(unsigned char **)parseContext,0x1c,*(uint *)(yyvsp + -0x50),scratchR6,
                           scratchR7,*(undefined4 *)((int)parseContext + 4));
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    if (yyvalNode != (unsigned char *)0x0) break;
    scratchR7 = (char *)&typeTmp1VtableOrStr1Alloc;
    scratchR6 = (char *)&typeTmp1TypeNameOrStr2Alloc;
    TType__getCompleteString(scratchR7,*(uint *)(yyvsp + 8) + 8);
    TType__getCompleteString(scratchR6,*(uint *)(yyvsp + -0x50) + 8);
    TParseContext__binaryOpError(parseContext,*(uint *)(yyvsp + -0x2c),"^",scratchR6,scratchR7);
    refCountPtr = typeTmp1Word14OrStr2Data + -4;
    destroyAlloc41[0] = typeTmp1TypeNameOrStr2Alloc;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    if ((int)oldRefCount2 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(typeTmp1Word14OrStr2Data + -0xc),destroyAlloc41);
    }
    refCountPtr = typeTmp1ArraySizeOrStr1Data + -4;
    destroyRep = (unsigned char *)(typeTmp1ArraySizeOrStr1Data + -0xc);
    destroyAlloc42[0] = typeTmp1VtableOrStr1Alloc;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    stillShared = 0 < (int)oldRefCount2;
    destroyAllocArg = destroyAlloc42;
    goto checkStillShared;
  case 0x47:
    if (1 < *(int *)((int)parseContext + 0xc) - 2U) {
      TParseContext__error
                ((int)parseContext,*(char **)(yyvsp + -0x2c)," reserved for future use ","|","","",
                 staleR9Value,scratchR10);
      TParseContext__recover(parseContext);
    }
    scratchR6 = *(char **)(yyvsp + 8);
    scratchR7 = *(char **)(yyvsp + -0x2c);
    yyvalNode = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(unsigned char **)parseContext,0x1b,*(uint *)(yyvsp + -0x50),scratchR6,
                           scratchR7,*(undefined4 *)((int)parseContext + 4));
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    if (yyvalNode != (unsigned char *)0x0) break;
    scratchR7 = (char *)&typeTmp1VtableOrStr1Alloc;
    scratchR6 = (char *)&typeTmp1TypeNameOrStr2Alloc;
    TType__getCompleteString(scratchR7,*(uint *)(yyvsp + 8) + 8);
    TType__getCompleteString(scratchR6,*(uint *)(yyvsp + -0x50) + 8);
    TParseContext__binaryOpError(parseContext,*(uint *)(yyvsp + -0x2c),"|",scratchR6,scratchR7);
    refCountPtr = typeTmp1Word14OrStr2Data + -4;
    destroyAlloc43[0] = typeTmp1TypeNameOrStr2Alloc;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    if ((int)oldRefCount2 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(typeTmp1Word14OrStr2Data + -0xc),destroyAlloc43);
    }
    refCountPtr = typeTmp1ArraySizeOrStr1Data + -4;
    destroyRep = (unsigned char *)(typeTmp1ArraySizeOrStr1Data + -0xc);
    destroyAlloc44[0] = typeTmp1VtableOrStr1Alloc;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    stillShared = 0 < (int)oldRefCount2;
    destroyAllocArg = destroyAlloc44;
checkStillShared:
    if (!stillShared) {
loopCallZNSbIcSt11charTraitsIcE14poolAllocatorIcEE4Rep10MDestroyERKS2:
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_(destroyRep,destroyAllocArg);
    }
loopCallTParseContext_recover2:
    TParseContext__recover(parseContext);
    yyvalNodeReg = *(unsigned char **)(yyvsp + -0x50);
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    break;
  case 0x49:
    scratchR6 = *(char **)(yyvsp + 8);
    scratchR7 = *(char **)(yyvsp + -0x2c);
    yyvalNode = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(unsigned char **)parseContext,0x2c,*(uint *)(yyvsp + -0x50),scratchR6,
                           scratchR7,*(undefined4 *)((int)parseContext + 4));
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    if (yyvalNode != (unsigned char *)0x0) break;
    scratchR7 = (char *)&typeTmp1VtableOrStr1Alloc;
    TType__getCompleteString(scratchR7,*(uint *)(yyvsp + 8) + 8);
    TType__getCompleteString(&typeTmp1TypeNameOrStr2Alloc,*(uint *)(yyvsp + -0x50) + 8);
    TParseContext__binaryOpError(parseContext,*(uint *)(yyvsp + -0x2c),"&&",&typeTmp1TypeNameOrStr2Alloc,scratchR7);
    refCountPtr = typeTmp1Word14OrStr2Data + -4;
    destroyAlloc45[0] = typeTmp1TypeNameOrStr2Alloc;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    if ((int)oldRefCount2 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(typeTmp1Word14OrStr2Data + -0xc),destroyAlloc45);
    }
    refCountPtr = typeTmp1ArraySizeOrStr1Data + -4;
    destroyRep = (unsigned char *)(typeTmp1ArraySizeOrStr1Data + -0xc);
    destroyAlloc46[0] = typeTmp1VtableOrStr1Alloc;
    do {
      oldRefCount = *(uint *)refCountPtr;
      if (reservation != '\0') {
        newRefCount = storeWordConditionalIndexed(oldRefCount - 1,0,refCountPtr);
        *(uint *)refCountPtr = newRefCount;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    stillShared = 0 < (int)oldRefCount;
    destroyAllocArg = destroyAlloc46;
    goto checkStillShared2;
  case 0x4b:
    scratchR6 = *(char **)(yyvsp + 8);
    scratchR7 = *(char **)(yyvsp + -0x2c);
    yyvalNode = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(unsigned char **)parseContext,0x2b,*(uint *)(yyvsp + -0x50),scratchR6,
                           scratchR7,*(undefined4 *)((int)parseContext + 4));
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    if (yyvalNode != (unsigned char *)0x0) break;
    scratchR7 = (char *)&typeTmp1VtableOrStr1Alloc;
    TType__getCompleteString(scratchR7,*(uint *)(yyvsp + 8) + 8);
    TType__getCompleteString(&typeTmp1TypeNameOrStr2Alloc,*(uint *)(yyvsp + -0x50) + 8);
    TParseContext__binaryOpError(parseContext,*(uint *)(yyvsp + -0x2c),"^^",&typeTmp1TypeNameOrStr2Alloc,scratchR7);
    refCountPtr = typeTmp1Word14OrStr2Data + -4;
    destroyAlloc47[0] = typeTmp1TypeNameOrStr2Alloc;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    if ((int)oldRefCount2 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(typeTmp1Word14OrStr2Data + -0xc),destroyAlloc47);
    }
    refCountPtr = typeTmp1ArraySizeOrStr1Data + -4;
    destroyRep = (unsigned char *)(typeTmp1ArraySizeOrStr1Data + -0xc);
    destroyAlloc48[0] = typeTmp1VtableOrStr1Alloc;
    do {
      oldRefCount = *(uint *)refCountPtr;
      if (reservation != '\0') {
        newRefCount = storeWordConditionalIndexed(oldRefCount - 1,0,refCountPtr);
        *(uint *)refCountPtr = newRefCount;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    stillShared = 0 < (int)oldRefCount;
    destroyAllocArg = destroyAlloc48;
checkStillShared2:
    if (!stillShared) {
loopCallZNSbIcSt11charTraitsIcE14poolAllocatorIcEE4Rep10MDestroyERKS22:
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_(destroyRep,destroyAllocArg);
    }
loopSetNullWord:
    nullWord = (unsigned char *)0x0;
    TParseContext__recover(parseContext);
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    constArray = (unsigned char *)TPoolAllocator__allocate(poolAllocator,4);
    *(undefined4 *)constArray = 0;
    typeTmp1BitsOrPubQualifier = (unsigned char *)((uint)typeTmp1BitsOrPubQualifier & 0x1801ff | 0x4180800);
    typeTmp1VtableOrStr1Alloc = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
    intermediate = *(unsigned char **)parseContext;
    scratchR6 = *(char **)(yyvsp + -0x2c);
    typeTmp1ArraySizeOrStr1Data = nullWord;
    typeTmp1StructureOrPubSize = nullWord;
    typeTmp1Word0cOrPubMatrix = nullWord;
    typeTmp1TypeNameOrStr2Alloc = nullWord;
    typeTmp1Word14OrStr2Data = nullWord;
    typeTmp1Word18OrPubLine = nullWord;
    typeTmp1MaxArraySize = nullWord;
    typeTmp1Word20OrPubType = nullWord;
setTypeTmp1VtableCopy:
    typeTmp1VtableCopy = typeTmp1VtableOrStr1Alloc;
    yyvalNodeReg = (unsigned char *)
             TIntermediate__addConstantUnion(intermediate,constArray,(unsigned char *)&typeTmp1VtableOrStr1Alloc,(int)scratchR6);
    typeTmp1VtableOrStr1Alloc = typeTmp1VtableCopy;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    break;
  case 0x4d:
    scratchR6 = *(char **)(yyvsp + 8);
    scratchR7 = *(char **)(yyvsp + -0x2c);
    yyvalNode = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(unsigned char **)parseContext,0x2a,*(uint *)(yyvsp + -0x50),scratchR6,
                           scratchR7,*(undefined4 *)((int)parseContext + 4));
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    if (yyvalNode != (unsigned char *)0x0) break;
    scratchR7 = (char *)&typeTmp1VtableOrStr1Alloc;
    TType__getCompleteString(scratchR7,*(uint *)(yyvsp + 8) + 8);
    TType__getCompleteString(&typeTmp1TypeNameOrStr2Alloc,*(uint *)(yyvsp + -0x50) + 8);
    TParseContext__binaryOpError(parseContext,*(uint *)(yyvsp + -0x2c),"||",&typeTmp1TypeNameOrStr2Alloc,scratchR7);
    refCountPtr = typeTmp1Word14OrStr2Data + -4;
    destroyAlloc49[0] = typeTmp1TypeNameOrStr2Alloc;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    if ((int)oldRefCount2 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(typeTmp1Word14OrStr2Data + -0xc),destroyAlloc49);
    }
    refCountPtr = typeTmp1ArraySizeOrStr1Data + -4;
    destroyRep = (unsigned char *)(typeTmp1ArraySizeOrStr1Data + -0xc);
    destroyAlloc50[0] = typeTmp1VtableOrStr1Alloc;
    do {
      oldRefCount = *(uint *)refCountPtr;
      if (reservation != '\0') {
        newRefCount = storeWordConditionalIndexed(oldRefCount - 1,0,refCountPtr);
        *(uint *)refCountPtr = newRefCount;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    if ((int)oldRefCount < 1) {
      destroyAllocArg = destroyAlloc50;
      goto loopCallZNSbIcSt11charTraitsIcE14poolAllocatorIcEE4Rep10MDestroyERKS22;
    }
    goto loopSetNullWord;
  case 0x4f:
    boolError = __ZN13TParseContext14boolErrorCheckEiPK12TIntermTyped
                       (parseContext,*(uint *)(yyvsp + -0x84),*(unsigned char **)(yyvsp + -0xa8),
                        scratchR6,scratchR7,staleR8Value);
    if (boolError != 0) {
      TParseContext__recover(parseContext);
    }
    typeTmp1VtableAddr = (unsigned char *)&typeTmp1VtableOrStr1Alloc;
    scratchR6 = *(char **)(yyvsp + 8);
    scratchR7 = *(char **)(yyvsp + -0x84);
    yyvalNode = (unsigned char *)
                __ZN13TIntermediate12addSelectionEP12TIntermTypedS1_S1_i
                          (*(void **)parseContext,*(unsigned char **)(yyvsp + -0xa8),
                           *(unsigned char **)(yyvsp + -0x50),(unsigned char *)scratchR6,(int)scratchR7)
    ;
    (**(code **)(**(int **)(yyvsp + -0x50) + 0x38))(typeTmp1VtableAddr,*(int **)(yyvsp + -0x50));
    (**(code **)(**(int **)(yyvsp + 8) + 0x38))(&typeTmp2VtableOrPubArray,*(int **)(yyvsp + 8));
    foundMatch = false;
    if ((((uint)typeTmp1BitsOrPubQualifier & 0x1fffe00) == ((uint)typeTmp2BitsOrPub3Qualifier & 0x1fffe00)) && (typeTmp1StructureOrPubSize == typeTmp2StructureOrPubLine)
       ) {
      foundMatch = true;
    }
    picBase2 = (unsigned char *)0xa7b8374c;
    typeTmp1VtableOrStr1Alloc = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
    typeTmp2VtableOrPubArray = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
    if (!foundMatch) {
      yyvalNode = (unsigned char *)0x0;
    }
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    if (yyvalNode != (unsigned char *)0x0) break;
    scratchR6 = (char *)&typeTmp1TypeNameOrStr2Alloc;
    TType__getCompleteString(typeTmp1VtableAddr,*(uint *)(yyvsp + 8) + 8);
    TType__getCompleteString(scratchR6,*(uint *)(yyvsp + -0x50) + 8);
    TParseContext__binaryOpError(parseContext,*(uint *)(yyvsp + -0x84),":",scratchR6,typeTmp1VtableAddr);
    refCountPtr = typeTmp1Word14OrStr2Data + -4;
    destroyAlloc51[0] = typeTmp1TypeNameOrStr2Alloc;
    do {
      oldRefCount3 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount3 = (unsigned char *)storeWordConditionalIndexed(oldRefCount3 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount3;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    if ((int)oldRefCount3 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(typeTmp1Word14OrStr2Data + -0xc),destroyAlloc51);
    }
    refCountPtr = typeTmp1ArraySizeOrStr1Data + -4;
    destroyRep = (unsigned char *)(typeTmp1ArraySizeOrStr1Data + -0xc);
    destroyAlloc52[0] = typeTmp1VtableOrStr1Alloc;
    do {
      oldRefCount3 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount3 = (unsigned char *)storeWordConditionalIndexed(oldRefCount3 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount3;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    stillShared = 0 < (int)oldRefCount3;
    destroyAllocArg = destroyAlloc52;
    scratchR7 = (char *)typeTmp1VtableAddr;
    goto checkStillShared3;
  case 0x51:
    lValueError = TParseContext__lValueErrorCheck
                       (parseContext,*(uint *)(yyvsp + -0x2c),"assign",
                        *(unsigned char **)(yyvsp + -0x50),scratchR7,staleR8Value,staleR9Value,scratchR10);
    if (lValueError != 0) {
      TParseContext__recover(parseContext);
    }
    scratchR6 = *(char **)(yyvsp + 8);
    scratchR7 = *(char **)(yyvsp + -0x2c);
    yyvalNode = (unsigned char *)
                TIntermediate__addAssign
                          (*(unsigned char **)parseContext,*(uint *)(yyvsp + -0x28),
                           *(uint *)(yyvsp + -0x50),scratchR6,scratchR7);
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    if (yyvalNode != (unsigned char *)0x0) break;
    scratchR7 = (char *)&typeTmp1VtableOrStr1Alloc;
    scratchR6 = (char *)&typeTmp1TypeNameOrStr2Alloc;
    TType__getCompleteString(scratchR7,*(uint *)(yyvsp + 8) + 8);
    TType__getCompleteString(scratchR6,*(uint *)(yyvsp + -0x50) + 8);
    TParseContext__assignError(parseContext,*(uint *)(yyvsp + -0x2c),"assign",scratchR6,scratchR7);
    refCountPtr = typeTmp1Word14OrStr2Data + -4;
    destroyAlloc53[0] = typeTmp1TypeNameOrStr2Alloc;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    if ((int)oldRefCount2 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(typeTmp1Word14OrStr2Data + -0xc),destroyAlloc53);
    }
    refCountPtr = typeTmp1ArraySizeOrStr1Data + -4;
    destroyRep = (unsigned char *)(typeTmp1ArraySizeOrStr1Data + -0xc);
    destroyAlloc54[0] = typeTmp1VtableOrStr1Alloc;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    if (0 < (int)oldRefCount2) goto loopCallTParseContext_recover2;
    destroyAllocArg = destroyAlloc54;
    goto loopCallZNSbIcSt11charTraitsIcE14poolAllocatorIcEE4Rep10MDestroyERKS2;
  case 0x52:
    yyval = *(uint *)yyvsp;
    yyvalOp = 0x76;
    break;
  case 0x53:
    if (1 < *(uint *)((int)parseContext + 0xc)) {
      scratchR7 = "";
      scratchR6 = "*=";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," supported in vertex/fragment shaders only ","*=",
                 "","",staleR9Value,scratchR10);
      TParseContext__recover(parseContext);
    }
    yyval = *(uint *)yyvsp;
    yyvalOp = 0x79;
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    break;
  case 0x54:
    if (1 < *(uint *)((int)parseContext + 0xc)) {
      scratchR7 = "";
      scratchR6 = "/=";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," supported in vertex/fragment shaders only ","/=",
                 "","",staleR9Value,scratchR10);
      TParseContext__recover(parseContext);
    }
    yyval = *(uint *)yyvsp;
    yyvalOp = 0x7e;
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    break;
  case 0x55:
    if (1 < *(int *)((int)parseContext + 0xc) - 2U) {
      scratchR7 = "";
      scratchR6 = "%=";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," reserved for future use ","%=","","",staleR9Value,
                 scratchR10);
      TParseContext__recover(parseContext);
    }
    yyval = *(uint *)yyvsp;
    yyvalOp = 0x7f;
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    break;
  case 0x56:
    yyval = *(uint *)yyvsp;
    yyvalOp = 0x77;
    break;
  case 0x57:
    yyval = *(uint *)yyvsp;
    yyvalOp = 0x78;
    break;
  case 0x58:
    if (1 < *(int *)((int)parseContext + 0xc) - 2U) {
      scratchR7 = "";
      scratchR6 = "<<=";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," reserved for future use ","<<=","","",staleR9Value,
                 scratchR10);
      TParseContext__recover(parseContext);
    }
    yyval = *(uint *)yyvsp;
    yyvalOp = 0x83;
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    break;
  case 0x59:
    if (1 < *(int *)((int)parseContext + 0xc) - 2U) {
      scratchR7 = "";
      scratchR6 = "<<=";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," reserved for future use ","<<=","","",staleR9Value,
                 scratchR10);
      TParseContext__recover(parseContext);
    }
    yyval = *(uint *)yyvsp;
    yyvalOp = 0x84;
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    break;
  case 0x5a:
    if (1 < *(int *)((int)parseContext + 0xc) - 2U) {
      scratchR7 = "";
      scratchR6 = "&=";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," reserved for future use ","&=","","",staleR9Value,
                 scratchR10);
      TParseContext__recover(parseContext);
    }
    yyval = *(uint *)yyvsp;
    yyvalOp = 0x80;
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    break;
  case 0x5b:
    if (1 < *(int *)((int)parseContext + 0xc) - 2U) {
      scratchR7 = "";
      scratchR6 = "^=";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," reserved for future use ","^=","","",staleR9Value,
                 scratchR10);
      TParseContext__recover(parseContext);
    }
    yyval = *(uint *)yyvsp;
    yyvalOp = 0x82;
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    break;
  case 0x5c:
    if (1 < *(int *)((int)parseContext + 0xc) - 2U) {
      scratchR7 = "";
      scratchR6 = "|=";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," reserved for future use ","|=","","",staleR9Value,
                 scratchR10);
      TParseContext__recover(parseContext);
    }
    yyval = *(uint *)yyvsp;
    yyvalOp = 0x81;
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    break;
  case 0x5e:
    scratchR6 = *(char **)(yyvsp + -0x2c);
    yyvalNode = (unsigned char *)
                TIntermediate__addComma
                          (*(unsigned char **)parseContext,*(unsigned char **)(yyvsp + -0x50),
                           *(unsigned char **)(yyvsp + 8),(int)scratchR6);
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    if (yyvalNode != (unsigned char *)0x0) break;
    scratchR7 = (char *)&typeTmp1VtableOrStr1Alloc;
    scratchR6 = (char *)&typeTmp1TypeNameOrStr2Alloc;
    TType__getCompleteString(scratchR7,*(uint *)(yyvsp + 8) + 8);
    TType__getCompleteString(scratchR6,*(uint *)(yyvsp + -0x50) + 8);
    TParseContext__binaryOpError(parseContext,*(uint *)(yyvsp + -0x2c),",",scratchR6,scratchR7);
    refCountPtr = typeTmp1Word14OrStr2Data + -4;
    destroyAlloc55[0] = typeTmp1TypeNameOrStr2Alloc;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    if ((int)oldRefCount2 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(typeTmp1Word14OrStr2Data + -0xc),destroyAlloc55);
    }
    refCountPtr = typeTmp1ArraySizeOrStr1Data + -4;
    destroyRep = (unsigned char *)(typeTmp1ArraySizeOrStr1Data + -0xc);
    destroyAlloc56[0] = typeTmp1VtableOrStr1Alloc;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    stillShared = 0 < (int)oldRefCount2;
    destroyAllocArg = destroyAlloc56;
checkStillShared3:
    if (!stillShared) {
callZNSbIcSt11charTraitsIcE14poolAllocatorIcEE4Rep10MDestroyERKS2:
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_(destroyRep,destroyAllocArg);
    }
loopCallTParseContext_recover3:
    TParseContext__recover(parseContext);
yynCase2:
    yyvalNodeReg = *(unsigned char **)(yyvsp + 8);
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    break;
  case 0x5f:
    errorCheckResult = TParseContext__constErrorCheck(parseContext,*(unsigned char **)(yyvsp + 8));
checkErrorCheckResult:
    if (errorCheckResult != 0) goto loopCallTParseContext_recover3;
    goto yynCase2;
  case 0x60:
  case 0xb0:
  case 0xb6:
  case 0xba:
  case 0xca:
    goto yynCase60;
  case 0x61:
  case 0xb7:
    statementListNode2 = *(int **)(yyvsp + -0x24);
    yyvalNodeReg = (unsigned char *)0x0;
    if (statementListNode2 != (int *)0x0) {
      (**(code **)(*statementListNode2 + 0x60))(statementListNode2,1);
      yyvalNodeReg = *(unsigned char **)(yyvsp + -0x24);
      typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
      typeTmp7VtableReg = typeTmp7Vtable[0];
    }
    break;
  case 0x62:
    symbolTable = *(int **)((int)parseContext + 4);
    functionNameText = (char *)(**(code **)(**(int **)(yyvsp + -0x1c) + 8))(*(int **)(yyvsp + -0x1c));
    levelsBegin = *symbolTable;
    levelIdx = (symbolTable[1] - levelsBegin >> 2) + -1;
    goto loopSetLevelEntry;
  case 99:
  case 100:
  case 0xa0:
    yyvalTypeOrFunction = *(unsigned char **)(yyvsp + 0x10);
    break;
  case 0x65:
    yyvalTypeOrFunction = *(unsigned char **)(yyvsp + -0x1c);
    binaryNode = (**(code **)(**(int **)(yyvsp + 0x14) + 0x20))
                       (*(int **)(yyvsp + 0x14),scratchR4,scratchR5,scratchR6,scratchR7,staleR8Value,staleR9Value);
    if (binaryNode == 0) {
loopSetStackNode:
      stackNode = *(unsigned char **)(yyvsp + 0x14);
      yyvalNodeReg = yyvalNode;
      typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
      typeTmp7VtableReg = typeTmp7Vtable[0];
      if (stackNode == (unsigned char *)0x0) break;
      stackNodeVtable = *(int *)stackNode;
      goto LAB_97ba86fc;
    }
    functionHeaderWord10 = *(uint *)(yyvsp + -0x1c);
    elementEnd = *(uint **)(functionHeaderWord10 + 0x14);
    if (elementEnd == *(uint **)(functionHeaderWord10 + 0x18)) {
      std__vector_TParameter_pool_allocator_TParameter_____M_insert_aux
                ((unsigned char *)(functionHeaderWord10 + 0xc),
                 *(undefined4 *)(functionHeaderWord10 + 0x14),yyvsp + 0x10);
    }
    else {
      finishPtr2 = 0;
      if (elementEnd != (uint *)0x0) {
        parameterDeclarationWord142 = *(uint *)(yyvsp + 0x14);
        *elementEnd = *(uint *)(yyvsp + 0x10);
        elementEnd[1] = parameterDeclarationWord142;
        finishPtr2 = *(int *)(functionHeaderWord10 + 0x14);
      }
      *(int *)(functionHeaderWord10 + 0x14) = finishPtr2 + 8;
    }
    parameterDeclarationWord14 = *(unsigned char **)(yyvsp + 0x14);
    paramFinish = *(int *)(parameterDeclarationWord14 + 0x14);
    if (paramFinish == 0) {
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      newString = (unsigned char *)TPoolAllocator__allocate(poolAllocator,8);
      cr0 = (newString == (unsigned char *)0x0) << 1;
      mangledString = (unsigned char *)0x0;
      if (newString != (unsigned char *)0x0) {
        ctorAlloc5[0] = GetGlobalPoolAllocator();
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_(newString,"",(unsigned char *)ctorAlloc5)
        ;
        mangledString = newString;
      }
      *(unsigned char **)(parameterDeclarationWord14 + 0x14) = mangledString;
      ((int (*)())TType__buildMangledName)(parameterDeclarationWord14,mangledString);
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEmc(*(void **)(parameterDeclarationWord14 + 0x14),1,0x3b);
      paramFinish = *(int *)(parameterDeclarationWord14 + 0x14);
    }
    __ZStplIcSt11char_traitsIcE14pool_allocatorIcEESbIT_T0_T1_ERKS7_S9_
              ((unsigned char *)&typeTmp1VtableOrStr1Alloc,(unsigned char *)(functionHeaderWord10 + 0x44),paramFinish);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6assignERKS3_
              ((unsigned char *)(functionHeaderWord10 + 0x44),(unsigned char *)&typeTmp1VtableOrStr1Alloc);
    refCountPtr = typeTmp1ArraySizeOrStr1Data + -4;
    destroyRep = (unsigned char *)(typeTmp1ArraySizeOrStr1Data + -0xc);
    destroyAlloc58[0] = typeTmp1VtableOrStr1Alloc;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    stillShared = 0 < (int)oldRefCount2;
    destroyAllocArg = destroyAlloc58;
loopSetYyvalNodeReg2:
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    if (!stillShared) {
loopCallZNSbIcSt11charTraitsIcE14poolAllocatorIcEE4Rep10MDestroyERKS23:
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_(destroyRep,destroyAllocArg);
      yyvalNodeReg = yyvalNode;
      typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
      typeTmp7VtableReg = typeTmp7Vtable[0];
    }
    break;
  case 0x66:
    binaryNode = (**(code **)(**(int **)(yyvsp + 0x14) + 0x20))(*(int **)(yyvsp + 0x14));
    if (binaryNode == 0) {
      scratchR6 = "void";
      scratchR7 = "";
      TParseContext__error
                ((int)parseContext,*(char **)(yyvsp + -0x2c),
                 "cannot be an argument type except for \'(void)\'","void","",staleR8Value,staleR9Value,
                 scratchR10);
      TParseContext__recover(parseContext);
      goto loopSetStackNode;
    }
    yyvalTypeOrFunction = *(unsigned char **)(yyvsp + -0x48);
    functionHeaderWithParametersFunction = *(uint *)(yyvsp + -0x48);
    elementEnd = *(uint **)(functionHeaderWithParametersFunction + 0x14);
    if (elementEnd == *(uint **)(functionHeaderWithParametersFunction + 0x18)) {
      std__vector_TParameter_pool_allocator_TParameter_____M_insert_aux
                ((unsigned char *)(functionHeaderWithParametersFunction + 0xc),
                 *(undefined4 *)(functionHeaderWithParametersFunction + 0x14),yyvsp + 0x10);
    }
    else {
      finishPtr2 = 0;
      if (elementEnd != (uint *)0x0) {
        parameterDeclarationParamType = *(uint *)(yyvsp + 0x14);
        *elementEnd = *(uint *)(yyvsp + 0x10);
        elementEnd[1] = parameterDeclarationParamType;
        finishPtr2 = *(int *)(functionHeaderWithParametersFunction + 0x14);
      }
      *(int *)(functionHeaderWithParametersFunction + 0x14) = finishPtr2 + 8;
    }
    parameterDeclarationParamType2 = *(unsigned char **)(yyvsp + 0x14);
    paramFinish = *(int *)(parameterDeclarationParamType2 + 0x14);
    if (paramFinish == 0) {
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      newString = (unsigned char *)TPoolAllocator__allocate(poolAllocator,8);
      cr0 = (newString == (unsigned char *)0x0) << 1;
      mangledString = (unsigned char *)0x0;
      if (newString != (unsigned char *)0x0) {
        ctorAlloc6[0] = GetGlobalPoolAllocator();
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_(newString,"",(unsigned char *)ctorAlloc6)
        ;
        mangledString = newString;
      }
      *(unsigned char **)(parameterDeclarationParamType2 + 0x14) = mangledString;
      ((int (*)())TType__buildMangledName)(parameterDeclarationParamType2,mangledString);
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEmc(*(void **)(parameterDeclarationParamType2 + 0x14),1,0x3b);
      paramFinish = *(int *)(parameterDeclarationParamType2 + 0x14);
    }
    __ZStplIcSt11char_traitsIcE14pool_allocatorIcEESbIT_T0_T1_ERKS7_S9_
              ((unsigned char *)&typeTmp1VtableOrStr1Alloc,(unsigned char *)(functionHeaderWithParametersFunction + 0x44),paramFinish);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6assignERKS3_
              ((unsigned char *)(functionHeaderWithParametersFunction + 0x44),(unsigned char *)&typeTmp1VtableOrStr1Alloc);
    refCountPtr = typeTmp1ArraySizeOrStr1Data + -4;
    destroyRep = (unsigned char *)(typeTmp1ArraySizeOrStr1Data + -0xc);
    destroyAlloc59[0] = typeTmp1VtableOrStr1Alloc;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    if (0 < (int)oldRefCount2) break;
    destroyAllocArg = destroyAlloc59;
    goto loopCallZNSbIcSt11charTraitsIcE14poolAllocatorIcEE4Rep10MDestroyERKS23;
  case 0x67:
    if (1 < *(uint *)(yyvsp + -0x44)) {
      scratchR6 = (char *)getQualifierString(*(uint *)(yyvsp + -0x44));
      scratchR7 = "";
      TParseContext__error
                ((int)parseContext,*(char **)(yyvsp + -0x2c),
                 "no qualifiers allowed for function return",scratchR6,"",staleR8Value,staleR9Value,scratchR10);
      TParseContext__recover(parseContext);
    }
    structQualifierError = TParseContext__structQualifierErrorCheck
                       (parseContext,*(uint *)(yyvsp + -0x2c),(unsigned char *)(yyvsp + -0x48),scratchR6,
                        scratchR7,staleR8Value,staleR9Value);
    if (structQualifierError != 0) {
      TParseContext__recover(parseContext);
    }
    typeTmp2VtableOrPubArray = *(unsigned char **)(yyvsp + -0x48);
    typeTmp2ArraySizeOrPubUserDef = *(unsigned char **)(yyvsp + -0x44);
    scratchR7 = *(char **)(yyvsp + -0x40);
    scratchR6 = *(char **)(yyvsp + -0x3c);
    typeTmp2Word14OrPubUserDef2 = *(unsigned char **)(yyvsp + -0x34);
    typeTmp2TypeNameOrPubArray2 = *(unsigned char **)(yyvsp + -0x38);
    picBase2 = (unsigned char *)0xa7b8374c;
    fullySpecifiedTypeTypeLine = *(unsigned char **)(yyvsp + -0x30);
    typeTmp1BitsOrPubQualifier = (unsigned char *)
                (((uint)typeTmp2TypeNameOrPubArray2 & 1) << 9 |
                ((uint)scratchR6 & 1) << 10 |
                ((uint)scratchR7 & 0xff) << 0xb |
                ((uint)typeTmp2VtableOrPubArray & 0x3f) << 0x13 | (int)typeTmp2ArraySizeOrPubUserDef << 0x19 | (uint)typeTmp1BitsOrPubQualifier & 0x1ff)
    ;
    typeTmp1VtableOrStr1Alloc = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
    typeTmp1Word20OrPubType = (unsigned char *)0x0;
    typeTmp1ArraySizeOrStr1Data = (unsigned char *)0x0;
    typeTmp1StructureOrPubSize = (unsigned char *)0x0;
    typeTmp1Word0cOrPubMatrix = (unsigned char *)0x0;
    typeTmp1TypeNameOrStr2Alloc = (unsigned char *)0x0;
    typeTmp1Word14OrStr2Data = (unsigned char *)0x0;
    typeAt850Word18 = (unsigned char *)0x0;
    typeTmp1MaxArraySize = (unsigned char *)0x0;
    typeNameStr = typeTmp1TypeNameOrStr2Alloc;
    typeTmp2StructureOrPubLine = (unsigned char *)scratchR7;
    typeTmp2Word0cOrPubMatrix2 = (unsigned char *)scratchR6;
    typeTmp2Word18OrPubLine2 = fullySpecifiedTypeTypeLine;
    typeTmp2Word20OrPub3Type = typeTmp2VtableOrPubArray;
    typeTmp2BitsOrPub3Qualifier = typeTmp2ArraySizeOrPubUserDef;
    pub3Size = (unsigned char *)scratchR7;
    pub3Matrix = (unsigned char *)scratchR6;
    typeTmp3VtableOrPub3Array = typeTmp2TypeNameOrPubArray2;
    typeTmp3ArraySizeOrPub3UserDef = typeTmp2Word14OrPubUserDef2;
    typeTmp3StructureOrPub3Line = fullySpecifiedTypeTypeLine;
    if (typeTmp2Word14OrPubUserDef2 != (unsigned char *)0x0) {
      typeTmp1StructureOrPubSize = *(unsigned char **)(typeTmp2Word14OrPubUserDef2 + 8);
      picBaseArg = 0xa7b8374c;
      picBase = (unsigned char *)0xa7b8374c;
      setStructSizeResult2 = TType__setStructSize((unsigned char *)&typeTmp1VtableOrStr1Alloc,*(unsigned char **)(typeTmp2Word14OrPubUserDef2 + 8));
      typeAt850Word18 = (unsigned char *)((ulonglong)setStructSizeResult2 >> 0x20);
      typeNameStr2 = (**(code **)(*(uint *)typeTmp3ArraySizeOrPub3UserDef + 0x18))
                         (typeTmp3ArraySizeOrPub3UserDef,(int)setStructSizeResult2,fullySpecifiedTypeTypeLine,scratchR6,scratchR7,picBaseArg,*(uint *)typeTmp3ArraySizeOrPub3UserDef);
      *(undefined1 *)(*(int *)(typeNameStr2 + 4) + *(int *)(*(int *)(typeNameStr2 + 4) + -0xc)) =
           **(undefined1 **)(picBase + -0x7cc4);
      typeNameData = *(char **)(typeNameStr2 + 4);
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      stringMem = (unsigned char *)TPoolAllocator__allocate(poolAllocator,8);
      cr0 = (stringMem == (unsigned char *)0x0) << 1;
      typeNameStr = (unsigned char *)0x0;
      if (stringMem != (unsigned char *)0x0) {
        ctorAlloc7[0] = GetGlobalPoolAllocator();
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                  (stringMem,typeNameData,(unsigned char *)ctorAlloc7);
        typeNameStr = stringMem;
      }
    }
    typeTmp1TypeNameOrStr2Alloc = typeNameStr;
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    newFunction = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x54);
    identifierString2 = *(unsigned char **)(yyvsp + -0x28);
    *(undefined **)newFunction = PTR_vtable_a7b7c0f4 + 8;
    *(unsigned char **)(newFunction + 4) = identifierString2;
    allocatorArg4 = GetGlobalPoolAllocator();
    *(uint *)(newFunction + 0x18) = 0;
    *(uint *)(newFunction + 0x10) = 0;
    *(uint *)(newFunction + 0x14) = 0;
    *(uint *)(newFunction + 0xc) = allocatorArg4;
    *(unsigned char **)(newFunction + 0x20) = typeTmp1ArraySizeOrStr1Data;
    typeVtable3 = picBase2 + -0x610c;
    *(unsigned char **)(newFunction + 0x24) = typeTmp1StructureOrPubSize;
    *(unsigned char **)(newFunction + 0x28) = typeTmp1Word0cOrPubMatrix;
    *(unsigned char **)(newFunction + 0x2c) = typeTmp1TypeNameOrStr2Alloc;
    *(unsigned char **)(newFunction + 0x30) = typeTmp1Word14OrStr2Data;
    *(unsigned char **)(newFunction + 0x34) = typeAt850Word18;
    *(unsigned char **)(newFunction + 0x1c) = typeVtable3;
    *(unsigned char **)(newFunction + 0x38) = typeTmp1MaxArraySize;
    *(unsigned char **)(newFunction + 0x3c) = typeTmp1Word20OrPubType;
    oldFunctionTypeBits = *(uint *)(newFunction + 0x40);
    qualifierBits = (uint)typeTmp1BitsOrPubQualifier & 0xfe000000;
    *(uint *)(newFunction + 0x40) = qualifierBits | oldFunctionTypeBits & 0x1ffffff;
    basicTypeBits = ((uint)typeTmp1BitsOrPubQualifier >> 0x13 & 0x3f) << 0x13;
    *(uint *)(newFunction + 0x40) = basicTypeBits | qualifierBits | oldFunctionTypeBits & 0x7ffff;
    sizeFieldBits = (uint)typeTmp1BitsOrPubQualifier & 0x7f800;
    *(uint *)(newFunction + 0x40) = sizeFieldBits | basicTypeBits | qualifierBits | oldFunctionTypeBits & 0x7ff;
    matrixBit = ((uint)typeTmp1BitsOrPubQualifier >> 10 & 1) << 10;
    *(uint *)(newFunction + 0x40) = matrixBit | sizeFieldBits | basicTypeBits | qualifierBits | oldFunctionTypeBits & 0x3ff;
    *(uint *)(newFunction + 0x40) =
         ((uint)typeTmp1BitsOrPubQualifier >> 9 & 1) << 9 | matrixBit | sizeFieldBits | basicTypeBits | qualifierBits | oldFunctionTypeBits & 0x1ff;
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(newFunction + 0x44,identifierString2);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEmc(newFunction + 0x44,1,0x28);
    *(uint *)(newFunction + 0x50) = 0;
    *(uint *)(newFunction + 0x4c) = 0;
    yyvalNodeReg = yyvalNode;
    yyvalTypeOrFunction = newFunction;
    typeTmp1VtableOrStr1Alloc = typeVtable3;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    break;
  case 0x68:
    if (*(uint *)(yyvsp + -0x1c) == 0) {
      identifierString = *(uint *)(yyvsp + 4);
      picBase = (unsigned char *)0xa7b8374c;
      stringData = *(int *)(identifierString + 4);
      *(unsigned char *)(stringData + *(int *)(stringData + -0xc)) = *stringTerminalPtr_a7b7ba88;
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp,"illegal use of type \'void\'",
                 *(char **)(identifierString + 4),"",staleR8Value,stringData,identifierString);
      TParseContext__recover(parseContext);
    }
    reservedError = TParseContext__reservedErrorCheck(parseContext,*(uint *)yyvsp,*(unsigned char **)(yyvsp + 4));
    if (reservedError != 0) {
      TParseContext__recover(parseContext);
    }
    typeTmp1TypeNameOrStr2Alloc = *(unsigned char **)(yyvsp + 4);
    picBase2 = (unsigned char *)0xa7b8374c;
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    newType = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x28);
    typeTmp1Word20OrPubType = *(unsigned char **)(yyvsp + -0x1c);
    typeTmp1BitsOrPubQualifier = *(unsigned char **)(yyvsp + -0x18);
    typeSpecifierSize = *(unsigned char **)(yyvsp + -0x14);
    typeSpecifierMatrix = *(unsigned char **)(yyvsp + -0x10);
    scratchR7 = *(char **)(yyvsp + -0xc);
    scratchR6 = *(char **)(yyvsp + -8);
    typeTmp2StructureOrPubLine = *(unsigned char **)(yyvsp + -4);
    *(unsigned char **)newType = picBase2 + -0x610c;
    *(undefined4 *)(newType + 0x20) = 0;
    *(undefined4 *)(newType + 4) = 0;
    *(undefined4 *)(newType + 8) = 0;
    *(undefined4 *)(newType + 0xc) = 0;
    *(undefined4 *)(newType + 0x10) = 0;
    *(undefined4 *)(newType + 0x14) = 0;
    *(undefined4 *)(newType + 0x18) = 0;
    *(undefined4 *)(newType + 0x1c) = 0;
    oldTypeBits = *(uint *)(newType + 0x24);
    qualifierBits2 = (int)typeTmp1BitsOrPubQualifier << 0x19;
    *(uint *)(newType + 0x24) = qualifierBits2 | oldTypeBits & 0x1ffffff;
    basicTypeBits2 = ((uint)typeTmp1Word20OrPubType & 0x3f) << 0x13;
    *(uint *)(newType + 0x24) = basicTypeBits2 | qualifierBits2 | oldTypeBits & 0x7ffff;
    sizeBits = ((uint)typeSpecifierSize & 0xff) << 0xb;
    *(uint *)(newType + 0x24) = sizeBits | basicTypeBits2 | qualifierBits2 | oldTypeBits & 0x7ff;
    matrixBit = ((uint)typeSpecifierMatrix & 1) << 10;
    *(uint *)(newType + 0x24) = matrixBit | sizeBits | basicTypeBits2 | qualifierBits2 | oldTypeBits & 0x3ff;
    *(uint *)(newType + 0x24) =
         ((uint)scratchR7 & 1) << 9 | matrixBit | sizeBits | basicTypeBits2 | qualifierBits2 | oldTypeBits & 0x1ff;
    typeTmp2VtableOrPubArray = (unsigned char *)scratchR7;
    typeTmp2ArraySizeOrPubUserDef = (unsigned char *)scratchR6;
    typeTmp2TypeNameOrPubArray2 = typeTmp1Word20OrPubType;
    typeTmp2Word14OrPubUserDef2 = typeTmp1BitsOrPubQualifier;
    typeTmp2Word18OrPubLine2 = typeSpecifierSize;
    typeTmp2MaxArraySize = typeSpecifierMatrix;
    typeTmp2Word20OrPub3Type = (unsigned char *)scratchR7;
    typeTmp2BitsOrPub3Qualifier = (unsigned char *)scratchR6;
    pub3Size = typeTmp2StructureOrPubLine;
    if ((unsigned char *)scratchR6 != (unsigned char *)0x0) {
      picBase = (unsigned char *)0xa7b8374c;
      *(uint *)(newType + 8) = *(uint *)(scratchR6 + 8);
      setStructSizeResult3 = TType__setStructSize(newType,*(unsigned char **)(scratchR6 + 8));
      *(undefined4 *)(newType + 0x18) = setStructSizeResult3;
      typeNameStr2 = (**(code **)(*(uint *)typeTmp2BitsOrPub3Qualifier + 0x18))(typeTmp2BitsOrPub3Qualifier);
      *(undefined1 *)(*(int *)(typeNameStr2 + 4) + *(int *)(*(int *)(typeNameStr2 + 4) + -0xc)) =
           **(undefined1 **)(picBase + -0x7cc4);
      typeNameData = *(char **)(typeNameStr2 + 4);
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      stringMem2 = (void *)TPoolAllocator__allocate(poolAllocator,8);
      cr0 = (stringMem2 == (void *)0x0) << 1;
      fieldTypeName = (void *)0x0;
      if (stringMem2 != (void *)0x0) {
        ctorAlloc8[0] = GetGlobalPoolAllocator();
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                  (stringMem2,typeNameData,(unsigned char *)ctorAlloc8);
        fieldTypeName = stringMem2;
      }
      *(void **)(newType + 0x10) = fieldTypeName;
    }
    typeTmp1VtableOrStr1Alloc = typeTmp1TypeNameOrStr2Alloc;
    yyval = *(uint *)yyvsp;
    yyvalNodeReg = yyvalNode;
    yyvalTypeOrFunction = typeTmp1VtableOrStr1Alloc;
    yyvalQualifierOrParamType = (unsigned char *)newType;
    typeTmp1ArraySizeOrStr1Data = (unsigned char *)newType;
    typeTmp1Word14OrStr2Data = (unsigned char *)newType;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    break;
  case 0x69:
    picBase2 = (unsigned char *)0xa7b8374c;
    if (*(uint *)(yyvsp + -0x90) != 0) {
      typeTmp2TypeNameOrPubArray2 = *(unsigned char **)(yyvsp + -0xa0);
      typeSpecifierQualifier = *(unsigned char **)(yyvsp + -0x9c);
      typeSpecifierSize2 = *(unsigned char **)(yyvsp + -0x98);
      typeSpecifierMatrix2 = *(unsigned char **)(yyvsp + -0x94);
      typeTmp2BitsOrPub3Qualifier = *(unsigned char **)(yyvsp + -0x8c);
      typeTmp2Word20OrPub3Type = *(unsigned char **)(yyvsp + -0x90);
      typeSpecifierTypeLine = *(unsigned char **)(yyvsp + -0x88);
      picBaseArg = 0xa7b8374c;
      typeTmp2ArraySizeOrPubUserDef = (unsigned char *)
                  (((uint)typeTmp2Word20OrPub3Type & 1) << 9 |
                  ((uint)typeSpecifierMatrix2 & 1) << 10 |
                  ((uint)typeSpecifierSize2 & 0xff) << 0xb |
                  ((uint)typeTmp2TypeNameOrPubArray2 & 0x3f) << 0x13 | (int)typeSpecifierQualifier << 0x19 | (uint)typeTmp2ArraySizeOrPubUserDef & 0x1ff)
      ;
      typeTmp1TypeNameOrStr2Alloc = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
      typeTmp2VtableOrPubArray = (unsigned char *)0x0;
      typeAt840ArraySize = (unsigned char *)0x0;
      typeAt840Structure = (unsigned char *)0x0;
      typeTmp1MaxArraySize = (unsigned char *)0x0;
      typeTmp1Word20OrPubType = (unsigned char *)0x0;
      typeAt840Word14 = (unsigned char *)0x0;
      pubSize = (unsigned char *)0x0;
      pubMatrix = (unsigned char *)0x0;
      picBase = (unsigned char *)0xa7b8374c;
      typeWord20Value = typeTmp1Word20OrPubType;
      typeTmp2Word14OrPubUserDef2 = typeSpecifierQualifier;
      typeTmp2Word18OrPubLine2 = typeSpecifierSize2;
      typeTmp2MaxArraySize = typeSpecifierMatrix2;
      pub3Size = typeSpecifierTypeLine;
      typeTmp3VtableOrPub3Array = typeTmp2TypeNameOrPubArray2;
      typeTmp3ArraySizeOrPub3UserDef = typeSpecifierQualifier;
      typeTmp3StructureOrPub3Line = typeSpecifierSize2;
      typeTmp3Word0c = typeSpecifierMatrix2;
      typeTmp3TypeNameOrTypeTmp4Vtable = typeTmp2Word20OrPub3Type;
      typeTmp3Word14OrTypeTmp4ArraySize = typeTmp2BitsOrPub3Qualifier;
      typeTmp3Word18OrTypeTmp4Structure = typeSpecifierTypeLine;
      if (typeTmp2BitsOrPub3Qualifier != (unsigned char *)0x0) {
        typeTmp1Word18OrPubLine = *(unsigned char **)(typeTmp2BitsOrPub3Qualifier + 8);
        setStructSizeResult2 = TType__setStructSize((unsigned char *)&typeTmp1TypeNameOrStr2Alloc,*(unsigned char **)(typeTmp2BitsOrPub3Qualifier + 8));
        pubSize = (unsigned char *)((ulonglong)setStructSizeResult2 >> 0x20);
        typeNameStr2 = (**(code **)(*(uint *)typeTmp3Word14OrTypeTmp4ArraySize + 0x18))
                           (typeTmp3Word14OrTypeTmp4ArraySize,(int)setStructSizeResult2,typeSpecifierTypeLine,typeSpecifierMatrix2,typeSpecifierSize2,typeSpecifierQualifier,*(uint *)typeTmp3Word14OrTypeTmp4ArraySize)
        ;
        *(undefined1 *)(*(int *)(typeNameStr2 + 4) + *(int *)(*(int *)(typeNameStr2 + 4) + -0xc)) =
             **(undefined1 **)(picBase + -0x7cc4);
        typeNameData = *(char **)(typeNameStr2 + 4);
        poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
        stringMem = (unsigned char *)TPoolAllocator__allocate(poolAllocator,8);
        cr0 = (stringMem == (unsigned char *)0x0) << 1;
        typeWord20Value = (unsigned char *)0x0;
        if (stringMem != (unsigned char *)0x0) {
          ctorAlloc9[0] = GetGlobalPoolAllocator();
          __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                    (stringMem,typeNameData,(unsigned char *)ctorAlloc9);
          typeWord20Value = stringMem;
        }
      }
      typeTmp1Word20OrPubType = typeWord20Value;
      TType__getCompleteString(&typeTmp1VtableOrStr1Alloc,(unsigned char *)&typeTmp1TypeNameOrStr2Alloc);
      typeTmp1ArraySizeOrStr1Data[*(uint *)(typeTmp1ArraySizeOrStr1Data + -0xc)] = **(unsigned char **)(picBase + -0x7cc4);
      TParseContext__error
                ((int)parseContext,*(char **)(yyvsp + -0x58),"cannot declare arrays of this type",
                 (char *)typeTmp1ArraySizeOrStr1Data,"",picBase,typeTmp1ArraySizeOrStr1Data,picBaseArg);
      refCountPtr = typeTmp1ArraySizeOrStr1Data + -4;
      destroyAlloc60[0] = typeTmp1VtableOrStr1Alloc;
      do {
        oldRefCount = *(uint *)refCountPtr;
        if (reservation != '\0') {
          newRefCount = storeWordConditionalIndexed(oldRefCount - 1,0,refCountPtr);
          *(uint *)refCountPtr = newRefCount;
          cr0 = 2;
        }
      } while (!(bool)(cr0 >> 1 & 1));
      if ((int)oldRefCount < 1) {
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                  ((unsigned char *)(typeTmp1ArraySizeOrStr1Data + -0xc),destroyAlloc60);
      }
      typeTmp1TypeNameOrStr2Alloc = picBase2 + -0x610c;
      TParseContext__recover(parseContext);
    }
    reservedError2 = TParseContext__reservedErrorCheck
                       (parseContext,*(uint *)(yyvsp + -0x84),*(unsigned char **)(yyvsp + -0x80));
    if (reservedError2 != 0) {
      TParseContext__recover(parseContext);
    }
    *(uint *)(yyvsp + -0x90) = 1;
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    newType = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x28);
    typeTmp1VtableOrStr1Alloc = *(unsigned char **)(yyvsp + -0xa0);
    typeSpecifierQualifier2 = *(unsigned char **)(yyvsp + -0x9c);
    typeTmp1StructureOrPubSize = *(unsigned char **)(yyvsp + -0x98);
    typeTmp1Word0cOrPubMatrix = *(unsigned char **)(yyvsp + -0x94);
    scratchR7 = *(char **)(yyvsp + -0x90);
    scratchR6 = *(char **)(yyvsp + -0x8c);
    typeSpecifierTypeLine2 = *(unsigned char **)(yyvsp + -0x88);
    *(unsigned char **)newType = picBase2 + -0x610c;
    *(undefined4 *)(newType + 0x20) = 0;
    *(undefined4 *)(newType + 4) = 0;
    *(undefined4 *)(newType + 8) = 0;
    *(undefined4 *)(newType + 0xc) = 0;
    *(undefined4 *)(newType + 0x10) = 0;
    *(undefined4 *)(newType + 0x14) = 0;
    *(undefined4 *)(newType + 0x18) = 0;
    *(undefined4 *)(newType + 0x1c) = 0;
    oldTypeBits = *(uint *)(newType + 0x24);
    qualifierBits2 = (int)typeSpecifierQualifier2 << 0x19;
    *(uint *)(newType + 0x24) = qualifierBits2 | oldTypeBits & 0x1ffffff;
    basicTypeBits2 = ((uint)typeTmp1VtableOrStr1Alloc & 0x3f) << 0x13;
    *(uint *)(newType + 0x24) = basicTypeBits2 | qualifierBits2 | oldTypeBits & 0x7ffff;
    sizeBits = ((uint)typeTmp1StructureOrPubSize & 0xff) << 0xb;
    *(uint *)(newType + 0x24) = sizeBits | basicTypeBits2 | qualifierBits2 | oldTypeBits & 0x7ff;
    matrixBit = ((uint)typeTmp1Word0cOrPubMatrix & 1) << 10;
    *(uint *)(newType + 0x24) = matrixBit | sizeBits | basicTypeBits2 | qualifierBits2 | oldTypeBits & 0x3ff;
    *(uint *)(newType + 0x24) =
         ((uint)scratchR7 & 1) << 9 | matrixBit | sizeBits | basicTypeBits2 | qualifierBits2 | oldTypeBits & 0x1ff;
    typeTmp1TypeNameOrStr2Alloc = (unsigned char *)scratchR7;
    typeTmp1Word14OrStr2Data = (unsigned char *)scratchR6;
    typeTmp1Word20OrPubType = typeTmp1VtableOrStr1Alloc;
    typeTmp1BitsOrPubQualifier = typeSpecifierQualifier2;
    pubSize = typeTmp1StructureOrPubSize;
    pubMatrix = typeTmp1Word0cOrPubMatrix;
    typeTmp2VtableOrPubArray = (unsigned char *)scratchR7;
    typeTmp2ArraySizeOrPubUserDef = (unsigned char *)scratchR6;
    typeTmp2StructureOrPubLine = typeSpecifierTypeLine2;
    if ((unsigned char *)scratchR6 != (unsigned char *)0x0) {
      picBase = (unsigned char *)0xa7b8374c;
      *(uint *)(newType + 8) = *(uint *)(scratchR6 + 8);
      setStructSizeResult3 = TType__setStructSize(newType,*(unsigned char **)(scratchR6 + 8));
      *(undefined4 *)(newType + 0x18) = setStructSizeResult3;
      typeNameStr2 = (**(code **)(*(uint *)typeTmp2ArraySizeOrPubUserDef + 0x18))(typeTmp2ArraySizeOrPubUserDef);
      *(undefined1 *)(*(int *)(typeNameStr2 + 4) + *(int *)(*(int *)(typeNameStr2 + 4) + -0xc)) =
           **(undefined1 **)(picBase + -0x7cc4);
      typeNameData = *(char **)(typeNameStr2 + 4);
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      stringMem2 = (void *)TPoolAllocator__allocate(poolAllocator,8);
      cr0 = (stringMem2 == (void *)0x0) << 1;
      fieldTypeName = (void *)0x0;
      if (stringMem2 != (void *)0x0) {
        ctorAlloc10[0] = GetGlobalPoolAllocator();
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                  (stringMem2,typeNameData,(unsigned char *)ctorAlloc10);
        fieldTypeName = stringMem2;
      }
      *(void **)(newType + 0x10) = fieldTypeName;
    }
    constantUnion = (**(code **)(**(int **)(yyvsp + -0x24) + 0x18))(*(int **)(yyvsp + -0x24));
    if (constantUnion != 0) {
      constantUnion = (**(code **)(**(int **)(yyvsp + -0x24) + 0x18))(*(int **)(yyvsp + -0x24));
      indexValue = **(undefined4 **)(constantUnion + 0x30);
      *(uint *)(newType + 0x24) = *(uint *)(newType + 0x24) | 0x200;
      *(undefined4 *)(newType + 4) = indexValue;
    }
    typeTmp1TypeNameOrStr2Alloc = *(unsigned char **)(yyvsp + -0x80);
    yyval = *(uint *)(yyvsp + -0x84);
    yyvalNodeReg = yyvalNode;
    yyvalTypeOrFunction = typeTmp1TypeNameOrStr2Alloc;
    yyvalQualifierOrParamType = (unsigned char *)newType;
    typeTmp1VtableOrStr1Alloc = typeTmp1TypeNameOrStr2Alloc;
    typeTmp1ArraySizeOrStr1Data = (unsigned char *)newType;
    typeTmp1Word14OrStr2Data = (unsigned char *)newType;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    break;
  case 0x6a:
  case 0x6c:
    _memcpy(&yyval,yyvsp,0x2c);
    parameterTypeSpecifierLine = *(uint *)yyvsp;
    paramQualifierArg = *(uint *)(yyvsp + -0x44);
    scratchR6 = *(char **)(yyvsp + -0x1c);
    goto setScratchR7;
  case 0x6b:
  case 0x6d:
    _memcpy(&yyval,yyvsp,0x2c);
    parameterSamplerError = TParseContext__parameterSamplerErrorCheck
                       (parseContext,*(uint *)yyvsp,*(uint *)(yyvsp + -0x1c),
                        *(uint *)(yyvsp + 0x14));
    if (parameterSamplerError != 0) {
      TParseContext__recover(parseContext);
    }
    parameterTypeSpecifierLine = *(uint *)yyvsp;
    scratchR6 = *(char **)(yyvsp + -0x1c);
    paramQualifierArg = 0;
setScratchR7:
    scratchR7 = (char *)yyvalQualifierOrParamType;
    errorCheckResult = TParseContext__paramErrorCheck(parseContext,parameterTypeSpecifierLine,paramQualifierArg,scratchR6,yyvalQualifierOrParamType);
loopSetYyvalNodeReg3:
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    if (errorCheckResult == 0) break;
loopCallTParseContext_recover4:
    TParseContext__recover(parseContext);
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    break;
  case 0x6e:
  case 0x6f:
    yyvalTypeOrFunction = (unsigned char *)0x9;
    break;
  case 0x70:
    yyvalTypeOrFunction = (unsigned char *)0xa;
    break;
  case 0x71:
    yyvalTypeOrFunction = (unsigned char *)0xb;
    break;
  case 0x72:
    typeTmp1TypeNameOrStr2Alloc = (unsigned char *)0x0;
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    newType = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x28);
    typeTmp1Word20OrPubType = *(unsigned char **)(yyvsp + 0x10);
    typeTmp1BitsOrPubQualifier = *(unsigned char **)(yyvsp + 0x14);
    typeSpecifierSize = *(unsigned char **)(yyvsp + 0x18);
    typeSpecifierMatrix = *(unsigned char **)(yyvsp + 0x1c);
    picBase2 = (unsigned char *)0xa7b8374c;
    typeTmp2VtableOrPubArray = *(unsigned char **)(yyvsp + 0x20);
    scratchR7 = *(char **)(yyvsp + 0x24);
    scratchR6 = *(char **)(yyvsp + 0x28);
    *(undefined ***)newType = &PTR___ZN5TTypeD1Ev_a7b7d640;
    *(undefined4 *)(newType + 0x20) = 0;
    *(undefined4 *)(newType + 4) = 0;
    *(undefined4 *)(newType + 8) = 0;
    *(undefined4 *)(newType + 0xc) = 0;
    *(undefined4 *)(newType + 0x10) = 0;
    *(undefined4 *)(newType + 0x14) = 0;
    *(undefined4 *)(newType + 0x18) = 0;
    *(undefined4 *)(newType + 0x1c) = 0;
    oldTypeBits = *(uint *)(newType + 0x24);
    qualifierBits2 = (int)typeTmp1BitsOrPubQualifier << 0x19;
    *(uint *)(newType + 0x24) = qualifierBits2 | oldTypeBits & 0x1ffffff;
    basicTypeBits2 = ((uint)typeTmp1Word20OrPubType & 0x3f) << 0x13;
    *(uint *)(newType + 0x24) = basicTypeBits2 | qualifierBits2 | oldTypeBits & 0x7ffff;
    sizeBits = ((uint)typeSpecifierSize & 0xff) << 0xb;
    *(uint *)(newType + 0x24) = sizeBits | basicTypeBits2 | qualifierBits2 | oldTypeBits & 0x7ff;
    matrixBit = ((uint)typeSpecifierMatrix & 1) << 10;
    *(uint *)(newType + 0x24) = matrixBit | sizeBits | basicTypeBits2 | qualifierBits2 | oldTypeBits & 0x3ff;
    *(uint *)(newType + 0x24) =
         ((uint)typeTmp2VtableOrPubArray & 1) << 9 | matrixBit | sizeBits | basicTypeBits2 | qualifierBits2 | oldTypeBits & 0x1ff;
    typeTmp2ArraySizeOrPubUserDef = (unsigned char *)scratchR7;
    typeTmp2StructureOrPubLine = (unsigned char *)scratchR6;
    typeTmp2TypeNameOrPubArray2 = typeTmp1Word20OrPubType;
    typeTmp2Word14OrPubUserDef2 = typeTmp1BitsOrPubQualifier;
    typeTmp2Word18OrPubLine2 = typeSpecifierSize;
    typeTmp2MaxArraySize = typeSpecifierMatrix;
    typeTmp2Word20OrPub3Type = typeTmp2VtableOrPubArray;
    typeTmp2BitsOrPub3Qualifier = (unsigned char *)scratchR7;
    pub3Size = (unsigned char *)scratchR6;
    if ((unsigned char *)scratchR7 != (unsigned char *)0x0) {
      picBase = (unsigned char *)0xa7b8374c;
      *(uint *)(newType + 8) = *(uint *)(scratchR7 + 8);
      setStructSizeResult3 = TType__setStructSize(newType,*(unsigned char **)(scratchR7 + 8));
      *(undefined4 *)(newType + 0x18) = setStructSizeResult3;
      typeNameStr2 = (**(code **)(*(uint *)typeTmp2BitsOrPub3Qualifier + 0x18))(typeTmp2BitsOrPub3Qualifier);
      *(undefined1 *)(*(int *)(typeNameStr2 + 4) + *(int *)(*(int *)(typeNameStr2 + 4) + -0xc)) =
           **(undefined1 **)(picBase + -0x7cc4);
      typeNameData = *(char **)(typeNameStr2 + 4);
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      stringMem2 = (void *)TPoolAllocator__allocate(poolAllocator,8);
      cr0 = (stringMem2 == (void *)0x0) << 1;
      fieldTypeName = (void *)0x0;
      if (stringMem2 != (void *)0x0) {
        ctorAlloc11[0] = GetGlobalPoolAllocator();
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                  (stringMem2,typeNameData,(unsigned char *)ctorAlloc11);
        fieldTypeName = stringMem2;
      }
      *(void **)(newType + 0x10) = fieldTypeName;
    }
    yyvalTypeOrFunction = typeTmp1TypeNameOrStr2Alloc;
    typeTmp1VtableOrStr1Alloc = typeTmp1TypeNameOrStr2Alloc;
    yyvalNodeReg = yyvalNode;
    yyvalQualifierOrParamType = (unsigned char *)newType;
    typeTmp1ArraySizeOrStr1Data = (unsigned char *)newType;
    typeTmp1Word14OrStr2Data = (unsigned char *)newType;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    break;
  case 0x73:
    picBase2 = (unsigned char *)0xa7b8374c;
    if (*(uint *)(yyvsp + -100) != 0) {
      typeTmp2TypeNameOrPubArray2 = *(unsigned char **)(yyvsp + -0x74);
      typeSpecifierQualifier = *(unsigned char **)(yyvsp + -0x70);
      typeSpecifierSize2 = *(unsigned char **)(yyvsp + -0x6c);
      typeSpecifierMatrix2 = *(unsigned char **)(yyvsp + -0x68);
      typeTmp2BitsOrPub3Qualifier = *(unsigned char **)(yyvsp + -0x60);
      typeTmp2Word20OrPub3Type = *(unsigned char **)(yyvsp + -100);
      typeSpecifierTypeLine = *(unsigned char **)(yyvsp + -0x5c);
      picBaseArg = 0xa7b8374c;
      typeTmp2ArraySizeOrPubUserDef = (unsigned char *)
                  (((uint)typeTmp2Word20OrPub3Type & 1) << 9 |
                  ((uint)typeSpecifierMatrix2 & 1) << 10 |
                  ((uint)typeSpecifierSize2 & 0xff) << 0xb |
                  ((uint)typeTmp2TypeNameOrPubArray2 & 0x3f) << 0x13 | (int)typeSpecifierQualifier << 0x19 | (uint)typeTmp2ArraySizeOrPubUserDef & 0x1ff)
      ;
      typeTmp1TypeNameOrStr2Alloc = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
      typeTmp2VtableOrPubArray = (unsigned char *)0x0;
      typeAt840ArraySize = (unsigned char *)0x0;
      typeAt840Structure = (unsigned char *)0x0;
      typeTmp1MaxArraySize = (unsigned char *)0x0;
      typeTmp1Word20OrPubType = (unsigned char *)0x0;
      typeAt840Word14 = (unsigned char *)0x0;
      pubSize = (unsigned char *)0x0;
      pubMatrix = (unsigned char *)0x0;
      picBase = (unsigned char *)0xa7b8374c;
      typeWord20Value = typeTmp1Word20OrPubType;
      typeTmp2Word14OrPubUserDef2 = typeSpecifierQualifier;
      typeTmp2Word18OrPubLine2 = typeSpecifierSize2;
      typeTmp2MaxArraySize = typeSpecifierMatrix2;
      pub3Size = typeSpecifierTypeLine;
      typeTmp3VtableOrPub3Array = typeTmp2TypeNameOrPubArray2;
      typeTmp3ArraySizeOrPub3UserDef = typeSpecifierQualifier;
      typeTmp3StructureOrPub3Line = typeSpecifierSize2;
      typeTmp3Word0c = typeSpecifierMatrix2;
      typeTmp3TypeNameOrTypeTmp4Vtable = typeTmp2Word20OrPub3Type;
      typeTmp3Word14OrTypeTmp4ArraySize = typeTmp2BitsOrPub3Qualifier;
      typeTmp3Word18OrTypeTmp4Structure = typeSpecifierTypeLine;
      if (typeTmp2BitsOrPub3Qualifier != (unsigned char *)0x0) {
        typeTmp1Word18OrPubLine = *(unsigned char **)(typeTmp2BitsOrPub3Qualifier + 8);
        setStructSizeResult2 = TType__setStructSize((unsigned char *)&typeTmp1TypeNameOrStr2Alloc,*(unsigned char **)(typeTmp2BitsOrPub3Qualifier + 8));
        pubSize = (unsigned char *)((ulonglong)setStructSizeResult2 >> 0x20);
        typeNameStr2 = (**(code **)(*(uint *)typeTmp3Word14OrTypeTmp4ArraySize + 0x18))
                           (typeTmp3Word14OrTypeTmp4ArraySize,(int)setStructSizeResult2,typeSpecifierTypeLine,typeSpecifierMatrix2,typeSpecifierSize2,typeSpecifierQualifier,*(uint *)typeTmp3Word14OrTypeTmp4ArraySize)
        ;
        *(undefined1 *)(*(int *)(typeNameStr2 + 4) + *(int *)(*(int *)(typeNameStr2 + 4) + -0xc)) =
             **(undefined1 **)(picBase + -0x7cc4);
        typeNameData = *(char **)(typeNameStr2 + 4);
        poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
        stringMem = (unsigned char *)TPoolAllocator__allocate(poolAllocator,8);
        cr0 = (stringMem == (unsigned char *)0x0) << 1;
        typeWord20Value = (unsigned char *)0x0;
        if (stringMem != (unsigned char *)0x0) {
          ctorAlloc12[0] = GetGlobalPoolAllocator();
          __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                    (stringMem,typeNameData,(unsigned char *)ctorAlloc12);
          typeWord20Value = stringMem;
        }
      }
      typeTmp1Word20OrPubType = typeWord20Value;
      TType__getCompleteString(&typeTmp1VtableOrStr1Alloc,(unsigned char *)&typeTmp1TypeNameOrStr2Alloc);
      typeTmp1ArraySizeOrStr1Data[*(uint *)(typeTmp1ArraySizeOrStr1Data + -0xc)] = **(unsigned char **)(picBase + -0x7cc4);
      TParseContext__error
                ((int)parseContext,*(char **)(yyvsp + -0x58),"cannot declare arrays of this type",
                 (char *)typeTmp1ArraySizeOrStr1Data,"",picBase,typeTmp1ArraySizeOrStr1Data,picBaseArg);
      refCountPtr = typeTmp1ArraySizeOrStr1Data + -4;
      destroyAlloc61[0] = typeTmp1VtableOrStr1Alloc;
      do {
        oldRefCount = *(uint *)refCountPtr;
        if (reservation != '\0') {
          newRefCount = storeWordConditionalIndexed(oldRefCount - 1,0,refCountPtr);
          *(uint *)refCountPtr = newRefCount;
          cr0 = 2;
        }
      } while (!(bool)(cr0 >> 1 & 1));
      if ((int)oldRefCount < 1) {
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                  ((unsigned char *)(typeTmp1ArraySizeOrStr1Data + -0xc),destroyAlloc61);
      }
      typeTmp1TypeNameOrStr2Alloc = picBase2 + -0x610c;
      TParseContext__recover(parseContext);
    }
    *(uint *)(yyvsp + -100) = 1;
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    newType = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x28);
    typeTmp1VtableOrStr1Alloc = *(unsigned char **)(yyvsp + -0x74);
    typeSpecifierQualifier2 = *(unsigned char **)(yyvsp + -0x70);
    typeTmp1StructureOrPubSize = *(unsigned char **)(yyvsp + -0x6c);
    typeTmp1Word0cOrPubMatrix = *(unsigned char **)(yyvsp + -0x68);
    scratchR7 = *(char **)(yyvsp + -100);
    scratchR6 = *(char **)(yyvsp + -0x60);
    typeSpecifierTypeLine2 = *(unsigned char **)(yyvsp + -0x5c);
    *(unsigned char **)newType = picBase2 + -0x610c;
    *(undefined4 *)(newType + 0x20) = 0;
    *(undefined4 *)(newType + 4) = 0;
    *(undefined4 *)(newType + 8) = 0;
    *(undefined4 *)(newType + 0xc) = 0;
    *(undefined4 *)(newType + 0x10) = 0;
    *(undefined4 *)(newType + 0x14) = 0;
    *(undefined4 *)(newType + 0x18) = 0;
    *(undefined4 *)(newType + 0x1c) = 0;
    oldTypeBits = *(uint *)(newType + 0x24);
    qualifierBits2 = (int)typeSpecifierQualifier2 << 0x19;
    *(uint *)(newType + 0x24) = qualifierBits2 | oldTypeBits & 0x1ffffff;
    basicTypeBits2 = ((uint)typeTmp1VtableOrStr1Alloc & 0x3f) << 0x13;
    *(uint *)(newType + 0x24) = basicTypeBits2 | qualifierBits2 | oldTypeBits & 0x7ffff;
    sizeBits = ((uint)typeTmp1StructureOrPubSize & 0xff) << 0xb;
    *(uint *)(newType + 0x24) = sizeBits | basicTypeBits2 | qualifierBits2 | oldTypeBits & 0x7ff;
    matrixBit = ((uint)typeTmp1Word0cOrPubMatrix & 1) << 10;
    *(uint *)(newType + 0x24) = matrixBit | sizeBits | basicTypeBits2 | qualifierBits2 | oldTypeBits & 0x3ff;
    *(uint *)(newType + 0x24) =
         ((uint)scratchR7 & 1) << 9 | matrixBit | sizeBits | basicTypeBits2 | qualifierBits2 | oldTypeBits & 0x1ff;
    typeTmp1TypeNameOrStr2Alloc = (unsigned char *)scratchR7;
    typeTmp1Word14OrStr2Data = (unsigned char *)scratchR6;
    typeTmp1Word20OrPubType = typeTmp1VtableOrStr1Alloc;
    typeTmp1BitsOrPubQualifier = typeSpecifierQualifier2;
    pubSize = typeTmp1StructureOrPubSize;
    pubMatrix = typeTmp1Word0cOrPubMatrix;
    typeTmp2VtableOrPubArray = (unsigned char *)scratchR7;
    typeTmp2ArraySizeOrPubUserDef = (unsigned char *)scratchR6;
    typeTmp2StructureOrPubLine = typeSpecifierTypeLine2;
    if ((unsigned char *)scratchR6 != (unsigned char *)0x0) {
      picBase = (unsigned char *)0xa7b8374c;
      *(uint *)(newType + 8) = *(uint *)(scratchR6 + 8);
      setStructSizeResult3 = TType__setStructSize(newType,*(unsigned char **)(scratchR6 + 8));
      *(undefined4 *)(newType + 0x18) = setStructSizeResult3;
      typeNameStr2 = (**(code **)(*(uint *)typeTmp2ArraySizeOrPubUserDef + 0x18))(typeTmp2ArraySizeOrPubUserDef);
      *(undefined1 *)(*(int *)(typeNameStr2 + 4) + *(int *)(*(int *)(typeNameStr2 + 4) + -0xc)) =
           **(undefined1 **)(picBase + -0x7cc4);
      typeNameData = *(char **)(typeNameStr2 + 4);
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      stringMem2 = (void *)TPoolAllocator__allocate(poolAllocator,8);
      cr0 = (stringMem2 == (void *)0x0) << 1;
      fieldTypeName = (void *)0x0;
      if (stringMem2 != (void *)0x0) {
        ctorAlloc13[0] = GetGlobalPoolAllocator();
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                  (stringMem2,typeNameData,(unsigned char *)ctorAlloc13);
        fieldTypeName = stringMem2;
      }
      *(void **)(newType + 0x10) = fieldTypeName;
    }
    constantUnion = (**(code **)(**(int **)(yyvsp + -0x24) + 0x18))(*(int **)(yyvsp + -0x24));
    if (constantUnion != 0) {
      constantUnion = (**(code **)(**(int **)(yyvsp + -0x24) + 0x18))(*(int **)(yyvsp + -0x24));
      indexValue = **(undefined4 **)(constantUnion + 0x30);
      *(uint *)(newType + 0x24) = *(uint *)(newType + 0x24) | 0x200;
      *(undefined4 *)(newType + 4) = indexValue;
    }
    typeTmp1VtableOrStr1Alloc = (unsigned char *)0x0;
    yyval = *(uint *)(yyvsp + -0x58);
    yyvalNodeReg = yyvalNode;
    yyvalTypeOrFunction = typeTmp1VtableOrStr1Alloc;
    yyvalQualifierOrParamType = (unsigned char *)newType;
    typeTmp1ArraySizeOrStr1Data = (unsigned char *)newType;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    break;
  case 0x74:
    _memcpy(&yyval,yyvsp,0x2c);
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    break;
  case 0x75:
    _memcpy(&yyval,yyvsp + -0x58,0x2c);
    identifierLine = *(uint *)yyvsp;
    valueSlot = (unsigned char *)(yyvsp + -0x48);
    goto setStructQualifierError;
  case 0x76:
    _memcpy(&yyval,yyvsp + -0xb0,0x2c);
    structQualifierError = TParseContext__structQualifierErrorCheck
                       (parseContext,*(uint *)(yyvsp + -0x58),(unsigned char *)(yyvsp + -0xa0),scratchR6,
                        scratchR7,staleR8Value,staleR9Value);
    if (structQualifierError != 0) {
      TParseContext__recover(parseContext);
    }
    leftBracketLine2 = *(unsigned char **)(yyvsp + -0x2c);
    identifierValue = *(uint *)(yyvsp + -0x54);
    nodeOpArg = 0;
    goto storeYyOutArgs;
  case 0x77:
    _memcpy(&yyval,yyvsp + -0xdc,0x2c);
    identifierLine = *(uint *)(yyvsp + -0x84);
    valueSlot = (unsigned char *)(yyvsp + -0xcc);
    goto setStructQualifierError2;
  case 0x78:
    slotArg = yyvsp + -0xa0;
    _memcpy(&yyval,yyvsp + -0xb0,0x2c);
    structQualifierError = TParseContext__structQualifierErrorCheck
                       (parseContext,*(uint *)(yyvsp + -0x58),(unsigned char *)slotArg,scratchR6,scratchR7,
                        staleR8Value,staleR9Value);
    if (structQualifierError != 0) {
      TParseContext__recover(parseContext);
    }
    scratchR7 = *(char **)(yyvsp + 8);
    executeInitializerResult = TParseContext__executeInitializer
                       (parseContext,*(uint *)(yyvsp + -0x58),*(unsigned char **)(yyvsp + -0x54),
                        (unsigned char *)slotArg,(unsigned char *)scratchR7,&operandOut1);
    if (executeInitializerResult == 0) {
      if (operandOut1 != (unsigned char *)0x0) {
        intermediate = *(unsigned char **)parseContext;
        leftNode = *(unsigned char **)(yyvsp + -0xa8);
        operandNode = operandOut1;
        goto loopSetScratchR6;
      }
      scratchR6 = (char *)slotArg;
      yyvalNodeReg = *(unsigned char **)(yyvsp + -0xa8);
      typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
      typeTmp7VtableReg = typeTmp7Vtable[0];
      break;
    }
    goto callTParseContext_recover2;
  case 0x79:
    yyvalTypeOrFunction = *(unsigned char **)(yyvsp + 0x10);
    yyvalQualifierOrParamType = *(unsigned char **)(yyvsp + 0x14);
    yyvalSize = *(unsigned char **)(yyvsp + 0x18);
    yyvalMatrix = *(unsigned char **)(yyvsp + 0x1c);
    yyvalArray = *(unsigned char **)(yyvsp + 0x20);
    yyvalUserDef = *(unsigned char **)(yyvsp + 0x24);
    yyvalTypeLine = *(unsigned char **)(yyvsp + 0x28);
    yyvalNodeReg = (unsigned char *)0x0;
    break;
  case 0x7a:
    yyvalNode = (unsigned char *)0x0;
    valueSlot = (unsigned char *)(yyvsp + -0x1c);
    yyvalTypeOrFunction = *(unsigned char **)(yyvsp + -0x1c);
    yyvalQualifierOrParamType = *(unsigned char **)(yyvsp + -0x18);
    yyvalSize = *(unsigned char **)(yyvsp + -0x14);
    yyvalMatrix = *(unsigned char **)(yyvsp + -0x10);
    yyvalArray = *(unsigned char **)(yyvsp + -0xc);
    yyvalUserDef = *(unsigned char **)(yyvsp + -8);
    staleR9Value = *(unsigned char **)(yyvsp + -4);
    identifierLine = *(uint *)yyvsp;
    yyvalTypeLine = staleR9Value;
setStructQualifierError:
    structQualifierError = TParseContext__structQualifierErrorCheck
                       (parseContext,identifierLine,valueSlot,scratchR6,scratchR7,staleR8Value,staleR9Value);
    if (structQualifierError != 0) {
      TParseContext__recover(parseContext);
    }
    scratchR6 = (char *)&yyvalTypeOrFunction;
    errorCheckResult = TParseContext__nonInitErrorCheck
                       (parseContext,*(uint *)yyvsp,*(unsigned char **)(yyvsp + 4),(unsigned char *)scratchR6);
    goto loopSetYyvalNodeReg3;
  case 0x7b:
    yyvalNode = (unsigned char *)0x0;
    yyvalTypeOrFunction = *(unsigned char **)(yyvsp + -0x74);
    yyvalQualifierOrParamType = *(unsigned char **)(yyvsp + -0x70);
    yyvalSize = *(unsigned char **)(yyvsp + -0x6c);
    yyvalMatrix = *(unsigned char **)(yyvsp + -0x68);
    yyvalArray = *(unsigned char **)(yyvsp + -100);
    yyvalUserDef = *(unsigned char **)(yyvsp + -0x60);
    yyvalTypeLine = *(unsigned char **)(yyvsp + -0x5c);
    structQualifierError = TParseContext__structQualifierErrorCheck
                       (parseContext,*(uint *)(yyvsp + -0x58),(unsigned char *)(yyvsp + -0x74),scratchR6,
                        scratchR7,staleR8Value,yyvalTypeLine);
    if (structQualifierError != 0) {
      TParseContext__recover(parseContext);
    }
    leftBracketLine2 = *(unsigned char **)(yyvsp + -0x2c);
    identifierValue = *(uint *)(yyvsp + -0x54);
    typeTmp1VtableOrStr1Alloc = yyvalTypeOrFunction;
    typeTmp1ArraySizeOrStr1Data = yyvalQualifierOrParamType;
    typeTmp1StructureOrPubSize = yyvalSize;
    typeTmp1Word0cOrPubMatrix = yyvalMatrix;
    typeTmp1TypeNameOrStr2Alloc = yyvalArray;
    typeTmp1Word14OrStr2Data = yyvalUserDef;
    pubCopy850Line = yyvalTypeLine;
    yyOutArgs[0x10] = 0;
    yyOutArgs[0xf] = yyvalTypeLine;
    goto storeYyOutArgs2;
  case 0x7c:
    yyvalNode = (unsigned char *)0x0;
    valueSlot = (unsigned char *)(yyvsp + -0xa0);
    yyvalTypeOrFunction = *(unsigned char **)(yyvsp + -0xa0);
    yyvalQualifierOrParamType = *(unsigned char **)(yyvsp + -0x9c);
    yyvalSize = *(unsigned char **)(yyvsp + -0x98);
    yyvalMatrix = *(unsigned char **)(yyvsp + -0x94);
    yyvalArray = *(unsigned char **)(yyvsp + -0x90);
    yyvalUserDef = *(unsigned char **)(yyvsp + -0x8c);
    staleR9Value = *(unsigned char **)(yyvsp + -0x88);
    identifierLine = *(uint *)(yyvsp + -0x84);
    yyvalTypeLine = staleR9Value;
setStructQualifierError2:
    structQualifierError = TParseContext__structQualifierErrorCheck
                       (parseContext,identifierLine,valueSlot,scratchR6,scratchR7,staleR8Value,staleR9Value);
    if (structQualifierError != 0) {
      TParseContext__recover(parseContext);
    }
    leftBracketLine2 = *(unsigned char **)(yyvsp + -0x58);
    identifierValue = *(uint *)(yyvsp + -0x80);
    nodeOpArg = *(uint *)(yyvsp + -0x24);
storeYyOutArgs:
    yyOutArgs[0x10] = nodeOpArg;
    yyOutArgs[0xf] = yyvalTypeLine;
    typeTmp1VtableOrStr1Alloc = yyvalTypeOrFunction;
    typeTmp1ArraySizeOrStr1Data = yyvalQualifierOrParamType;
    typeTmp1StructureOrPubSize = yyvalSize;
    typeTmp1Word0cOrPubMatrix = yyvalMatrix;
    typeTmp1TypeNameOrStr2Alloc = yyvalArray;
    typeTmp1Word14OrStr2Data = yyvalUserDef;
    pubCopy850Line = yyvalTypeLine;
storeYyOutArgs2:
    yyOutArgs[0xe] = typeTmp1Word14OrStr2Data;
    scratchR6 = (char *)typeTmp1VtableOrStr1Alloc;
    scratchR7 = (char *)typeTmp1ArraySizeOrStr1Data;
    yyvalTypeOrFunction = typeTmp1VtableOrStr1Alloc;
    yyvalQualifierOrParamType = typeTmp1ArraySizeOrStr1Data;
    yyvalSize = typeTmp1StructureOrPubSize;
    yyvalMatrix = typeTmp1Word0cOrPubMatrix;
    yyvalArray = typeTmp1TypeNameOrStr2Alloc;
    yyvalUserDef = typeTmp1Word14OrStr2Data;
    yyvalTypeLine = pubCopy850Line;
    errorCheckResult = TParseContext__arrayErrorCheck
                       ((int)parseContext,leftBracketLine2,identifierValue,typeTmp1VtableOrStr1Alloc,typeTmp1ArraySizeOrStr1Data,typeTmp1StructureOrPubSize,typeTmp1Word0cOrPubMatrix,
                        typeTmp1TypeNameOrStr2Alloc,yyOutArgs[0xe],yyOutArgs[0xf],yyOutArgs[0x10]);
    goto loopSetYyvalNodeReg3;
  case 0x7d:
    yyvalTypeOrFunction = *(unsigned char **)(yyvsp + -0x74);
    slotArg = yyvsp + -0x74;
    yyvalQualifierOrParamType = *(unsigned char **)(yyvsp + -0x70);
    yyvalSize = *(unsigned char **)(yyvsp + -0x6c);
    yyvalMatrix = *(unsigned char **)(yyvsp + -0x68);
    yyvalArray = *(unsigned char **)(yyvsp + -100);
    yyvalUserDef = *(unsigned char **)(yyvsp + -0x60);
    yyvalTypeLine = *(unsigned char **)(yyvsp + -0x5c);
    structQualifierError = TParseContext__structQualifierErrorCheck
                       (parseContext,*(uint *)(yyvsp + -0x58),(unsigned char *)slotArg,scratchR6,scratchR7,
                        staleR8Value,yyvalTypeLine);
    if (structQualifierError != 0) {
      TParseContext__recover(parseContext);
    }
    scratchR7 = *(char **)(yyvsp + 8);
    executeInitializerResult = TParseContext__executeInitializer
                       (parseContext,*(uint *)(yyvsp + -0x58),*(unsigned char **)(yyvsp + -0x54),
                        (unsigned char *)slotArg,(unsigned char *)scratchR7,&operandOut2);
    if (executeInitializerResult != 0) goto callTParseContext_recover2;
    if (operandOut2 != (unsigned char *)0x0) {
      intermediate = *(unsigned char **)parseContext;
      aggregateLine = *(uint *)(yyvsp + -0x2c);
      operandNode = operandOut2;
      scratchR6 = (char *)slotArg;
      goto setYyvalNodeReg3;
    }
    goto yynCase60;
  case 0x7e:
    yyvalSize = *(unsigned char **)(yyvsp + 0x18);
    yyvalMatrix = *(unsigned char **)(yyvsp + 0x1c);
    yyvalArray = *(unsigned char **)(yyvsp + 0x20);
    yyvalUserDef = *(unsigned char **)(yyvsp + 0x24);
    yyvalTypeLine = *(unsigned char **)(yyvsp + 0x28);
    yyvalTypeOrFunction = *(unsigned char **)(yyvsp + 0x10);
    yyvalQualifierOrParamType = *(unsigned char **)(yyvsp + 0x14);
    break;
  case 0x7f:
    typeSpecifierType = *(unsigned char **)(yyvsp + 0x10);
    typeTmp1ArraySizeOrStr1Data = *(unsigned char **)(yyvsp + -0x18);
    typeSpecifierSize3 = *(unsigned char **)(yyvsp + 0x18);
    typeTmp1Word0cOrPubMatrix = *(unsigned char **)(yyvsp + 0x1c);
    typeTmp2VtableOrPubArray = (unsigned char *)0x0;
    typeSpecifierUserDef = *(unsigned char **)(yyvsp + 0x24);
    typeTmp1Word18OrPubLine = (unsigned char *)0x0;
    typeTmp2StructureOrPubLine = (unsigned char *)0x0;
    typeTmp1TypeNameOrStr2Alloc = (unsigned char *)0x0;
    typeQualifierQualifier = *(uint *)(yyvsp + -0x18);
    typeTmp1VtableOrStr1Alloc = typeSpecifierType;
    typeTmp1StructureOrPubSize = typeSpecifierSize3;
    typeTmp1Word14OrStr2Data = typeSpecifierUserDef;
    typeTmp1Word20OrPubType = typeSpecifierType;
    typeTmp1BitsOrPubQualifier = typeTmp1ArraySizeOrStr1Data;
    pubSize = typeSpecifierSize3;
    pubMatrix = typeTmp1Word0cOrPubMatrix;
    typeTmp2ArraySizeOrPubUserDef = typeSpecifierUserDef;
    if ((typeQualifierQualifier == 3) && (*(uint *)(yyvsp + 0x10) - 2 < 2)) {
      scratchR6 = (char *)getQualifierString(3);
      scratchR7 = "";
      TParseContext__error
                ((int)parseContext,*(char **)(yyvsp + 0x28),"cannot be bool or int",scratchR6,"",typeSpecifierType,
                 typeSpecifierUserDef,typeSpecifierSize3);
      TParseContext__recover(parseContext);
      typeQualifierQualifier = *(uint *)(yyvsp + -0x18);
    }
    if ((typeQualifierQualifier - 4 < 2) && (*(uint *)(yyvsp + 0x10) - 2 < 2)) {
      scratchR6 = (char *)getQualifierString(typeQualifierQualifier);
      scratchR7 = "";
      TParseContext__error
                ((int)parseContext,*(char **)(yyvsp + 0x28),"cannot be bool or int",scratchR6,"",typeSpecifierType,
                 typeSpecifierUserDef,typeSpecifierSize3);
      TParseContext__recover(parseContext);
    }
    goto setYyvalTypeOrFunction;
  case 0x80:
    typeSpecifierInit = &DAT_97c356fc;
    goto setYyvalTypeLine;
  case 0x81:
    if (*(int *)((int)parseContext + 0xc) != 0) {
      scratchR7 = "";
      staleR8Value = (unsigned char *)scratchR7;
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," supported in vertex shaders only ","attribute","",
                 "",staleR9Value,scratchR10);
      TParseContext__recover(parseContext);
    }
    globalError = TParseContext__globalErrorCheck
                       (parseContext,*(uint *)yyvsp,
                        (uint)((uint)((*(int **)((int)parseContext + 4))[1] -
                                      **(int **)((int)parseContext + 4) >> 2) < 4),"attribute",scratchR7,
                        staleR8Value);
    if (globalError != 0) {
      TParseContext__recover(parseContext);
    }
    typeSpecifierInit = &DAT_97c35718;
    goto setYyvalTypeLine;
  case 0x82:
    globalError = TParseContext__globalErrorCheck
                       (parseContext,*(uint *)yyvsp,
                        (uint)((uint)((*(int **)((int)parseContext + 4))[1] -
                                      **(int **)((int)parseContext + 4) >> 2) < 4),"varying",scratchR7,
                        staleR8Value);
    if (globalError != 0) {
      TParseContext__recover(parseContext);
    }
    scratchR6 = (char *)0x0;
    scratchR7 = (char *)0x0;
    typeTmp1VtableOrStr1Alloc = (unsigned char *)0x0;
    typeTmp1ArraySizeOrStr1Data = (unsigned char *)0x4;
    typeTmp1StructureOrPubSize = (unsigned char *)0x1;
    typeTmp1Word0cOrPubMatrix = (unsigned char *)0x0;
    typeTmp1TypeNameOrStr2Alloc = (unsigned char *)0x0;
    typeTmp1Word14OrStr2Data = (unsigned char *)0x0;
    typeTmp1Word18OrPubLine = (unsigned char *)0x0;
    if (*(int *)((int)parseContext + 0xc) == 0) {
      typeTmp1ArraySizeOrStr1Data = (unsigned char *)0x5;
    }
setYyvalTypeOrFunction:
    yyvalTypeOrFunction = typeTmp1VtableOrStr1Alloc;
    yyvalQualifierOrParamType = typeTmp1ArraySizeOrStr1Data;
    yyvalSize = typeTmp1StructureOrPubSize;
    yyvalMatrix = typeTmp1Word0cOrPubMatrix;
    yyvalArray = typeTmp1TypeNameOrStr2Alloc;
    yyvalUserDef = typeTmp1Word14OrStr2Data;
    yyvalTypeLine = typeTmp1Word18OrPubLine;
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    break;
  case 0x83:
    globalError = TParseContext__globalErrorCheck
                       (parseContext,*(uint *)yyvsp,
                        (uint)((uint)((*(int **)((int)parseContext + 4))[1] -
                                      **(int **)((int)parseContext + 4) >> 2) < 4),"uniform",scratchR7,
                        staleR8Value);
    if (globalError != 0) {
      TParseContext__recover(parseContext);
    }
    typeSpecifierInit = &DAT_97c35750;
setYyvalTypeLine:
    yyvalTypeLine = (unsigned char *)typeSpecifierInit[6];
    yyvalSize = (unsigned char *)typeSpecifierInit[2];
    yyvalMatrix = (unsigned char *)typeSpecifierInit[3];
    yyvalArray = (unsigned char *)typeSpecifierInit[4];
    scratchR7 = (char *)typeSpecifierInit[5];
    scratchR6 = (char *)yyvalTypeLine;
    yyvalNodeReg = yyvalNode;
    yyvalTypeOrFunction = (unsigned char *)*typeSpecifierInit;
    yyvalQualifierOrParamType = (unsigned char *)typeSpecifierInit[1];
    yyvalUserDef = (unsigned char *)scratchR7;
    typeTmp1VtableOrStr1Alloc = (unsigned char *)*typeSpecifierInit;
    typeTmp1ArraySizeOrStr1Data = (unsigned char *)typeSpecifierInit[1];
    typeTmp1StructureOrPubSize = yyvalSize;
    typeTmp1Word0cOrPubMatrix = yyvalMatrix;
    typeTmp1TypeNameOrStr2Alloc = yyvalArray;
    typeTmp1Word14OrStr2Data = (unsigned char *)scratchR7;
    pubCopy850Line = yyvalTypeLine;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    break;
  case 0x84:
    typeTmp1Word20OrPubType = (unsigned char *)0x0;
    pubSize = (unsigned char *)0x1;
    pubMatrix = (unsigned char *)0x0;
    typeTmp1BitsOrPubQualifier = (unsigned char *)
                (uint)((uint)((*(int **)((int)parseContext + 4))[1] - **(int **)((int)parseContext + 4) >> 2)
                      < 4);
    typeTmp2VtableOrPubArray = (unsigned char *)0x0;
    typeTmp2ArraySizeOrPubUserDef = (unsigned char *)0x0;
    yyvalTypeLine = *(unsigned char **)yyvsp;
    yyvalSize = (unsigned char *)0x1;
    yyvalUserDef = (unsigned char *)0x0;
    typeTmp1VtableOrStr1Alloc = (unsigned char *)0x0;
    typeTmp1StructureOrPubSize = (unsigned char *)0x1;
    typeTmp1Word0cOrPubMatrix = (unsigned char *)0x0;
    typeTmp1TypeNameOrStr2Alloc = (unsigned char *)0x0;
    typeTmp1Word14OrStr2Data = (unsigned char *)0x0;
    yyvalTypeOrFunction = (unsigned char *)0x0;
    yyvalMatrix = (unsigned char *)0x0;
    yyvalArray = (unsigned char *)0x0;
    yyvalQualifierOrParamType = typeTmp1BitsOrPubQualifier;
    typeTmp1ArraySizeOrStr1Data = typeTmp1BitsOrPubQualifier;
    pubCopy850Line = yyvalTypeLine;
    typeTmp2StructureOrPubLine = yyvalTypeLine;
    break;
  case 0x85:
    symbolTable = *(int **)((int)parseContext + 4);
    typeTmp1Word20OrPubType = (unsigned char *)0x1;
    goto setLevelsBytes2;
  case 0x86:
    symbolTable = *(int **)((int)parseContext + 4);
    typeTmp1Word20OrPubType = (unsigned char *)0x2;
    goto setLevelsBytes5;
  case 0x87:
    symbolTable = *(int **)((int)parseContext + 4);
    typeTmp1Word20OrPubType = (unsigned char *)0x3;
    goto setLevelsBytes5;
  case 0x88:
    symbolTable = *(int **)((int)parseContext + 4);
    typeTmp1Word20OrPubType = (unsigned char *)0x1;
    goto setLevelsBytes;
  case 0x89:
    symbolTable = *(int **)((int)parseContext + 4);
    typeTmp1Word20OrPubType = (unsigned char *)0x1;
    goto setLevelsBytes3;
  case 0x8a:
    symbolTable = *(int **)((int)parseContext + 4);
    typeTmp1Word20OrPubType = (unsigned char *)0x1;
    goto setLevelsBytes4;
  case 0x8b:
    symbolTable = *(int **)((int)parseContext + 4);
    typeTmp1Word20OrPubType = (unsigned char *)0x3;
setLevelsBytes:
    levelsBytes = symbolTable[1] - *symbolTable;
    pubSize = (unsigned char *)0x2;
    goto setTypeTmp2StructureOrPubLine;
  case 0x8c:
    symbolTable = *(int **)((int)parseContext + 4);
    typeTmp1Word20OrPubType = (unsigned char *)0x3;
    goto setLevelsBytes2;
  case 0x8d:
    symbolTable = *(int **)((int)parseContext + 4);
    typeTmp1Word20OrPubType = (unsigned char *)0x3;
    goto setLevelsBytes4;
  case 0x8e:
    symbolTable = *(int **)((int)parseContext + 4);
    typeTmp1Word20OrPubType = (unsigned char *)0x2;
setLevelsBytes2:
    levelsBytes = symbolTable[1] - *symbolTable;
    typeTmp2StructureOrPubLine = *(unsigned char **)yyvsp;
    pubSize = typeTmp1Word20OrPubType;
    goto setTypeTmp1BitsOrPubQualifier3;
  case 0x8f:
    symbolTable = *(int **)((int)parseContext + 4);
    typeTmp1Word20OrPubType = (unsigned char *)0x2;
setLevelsBytes3:
    levelsBytes = symbolTable[1] - *symbolTable;
    pubSize = (unsigned char *)0x3;
    goto setTypeTmp2StructureOrPubLine;
  case 0x90:
    symbolTable = *(int **)((int)parseContext + 4);
    typeTmp1Word20OrPubType = (unsigned char *)0x2;
setLevelsBytes4:
    levelsBytes = symbolTable[1] - *symbolTable;
    pubSize = (unsigned char *)0x4;
    goto setTypeTmp2StructureOrPubLine;
  case 0x91:
    if (1 < *(uint *)((int)parseContext + 0xc)) {
      scratchR7 = "";
      scratchR6 = "mat2";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," supported in vertex/fragment shaders only ","mat2"
                 ,"","",staleR9Value,scratchR10);
      TParseContext__recover(parseContext);
    }
    levelsBytes = (*(int **)((int)parseContext + 4))[1] - **(int **)((int)parseContext + 4);
    yyvalSize = (unsigned char *)0x2;
    goto setTypeTmp1BitsOrPubQualifier2;
  case 0x92:
    if (1 < *(uint *)((int)parseContext + 0xc)) {
      scratchR7 = "";
      scratchR6 = "mat3";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," supported in vertex/fragment shaders only ","mat3"
                 ,"","",staleR9Value,scratchR10);
      TParseContext__recover(parseContext);
    }
    levelsBytes = (*(int **)((int)parseContext + 4))[1] - **(int **)((int)parseContext + 4);
    yyvalSize = (unsigned char *)0x3;
    goto setTypeTmp1BitsOrPubQualifier2;
  case 0x93:
    if (1 < *(uint *)((int)parseContext + 0xc)) {
      scratchR7 = "";
      scratchR6 = "mat4";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," supported in vertex/fragment shaders only ","mat4"
                 ,"","",staleR9Value,scratchR10);
      TParseContext__recover(parseContext);
    }
    levelsBytes = (*(int **)((int)parseContext + 4))[1] - **(int **)((int)parseContext + 4);
    yyvalSize = (unsigned char *)0x4;
setTypeTmp1BitsOrPubQualifier2:
    typeTmp1BitsOrPubQualifier = (unsigned char *)(uint)((uint)(levelsBytes >> 2) < 4);
    typeTmp1Word20OrPubType = (unsigned char *)0x1;
    pubMatrix = (unsigned char *)0x1;
    typeTmp2VtableOrPubArray = (unsigned char *)0x0;
    typeTmp2ArraySizeOrPubUserDef = (unsigned char *)0x0;
    yyvalTypeLine = *(unsigned char **)yyvsp;
    yyvalMatrix = (unsigned char *)0x1;
    yyvalUserDef = (unsigned char *)0x0;
    typeTmp1VtableOrStr1Alloc = (unsigned char *)0x1;
    typeTmp1Word0cOrPubMatrix = (unsigned char *)0x1;
    typeTmp1TypeNameOrStr2Alloc = (unsigned char *)0x0;
    typeTmp1Word14OrStr2Data = (unsigned char *)0x0;
    yyvalTypeOrFunction = (unsigned char *)0x1;
    yyvalArray = (unsigned char *)0x0;
    yyvalNodeReg = yyvalNode;
    yyvalQualifierOrParamType = typeTmp1BitsOrPubQualifier;
    typeTmp1ArraySizeOrStr1Data = typeTmp1BitsOrPubQualifier;
    typeTmp1StructureOrPubSize = yyvalSize;
    pubCopy850Line = yyvalTypeLine;
    pubSize = yyvalSize;
    typeTmp2StructureOrPubLine = yyvalTypeLine;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    break;
  case 0x94:
    if (1 < *(uint *)((int)parseContext + 0xc)) {
      scratchR7 = "";
      scratchR6 = "sampler1D";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," supported in vertex/fragment shaders only ",
                 "sampler1D","","",staleR9Value,scratchR10);
      TParseContext__recover(parseContext);
    }
    symbolTable = *(int **)((int)parseContext + 4);
    typeTmp1Word20OrPubType = (unsigned char *)0x5;
    goto setLevelsBytes5;
  case 0x95:
    if (1 < *(uint *)((int)parseContext + 0xc)) {
      scratchR7 = "";
      scratchR6 = "sampler2D";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," supported in vertex/fragment shaders only ",
                 "sampler2D","","",staleR9Value,scratchR10);
      TParseContext__recover(parseContext);
    }
    symbolTable = *(int **)((int)parseContext + 4);
    typeTmp1Word20OrPubType = (unsigned char *)0x6;
    goto setLevelsBytes5;
  case 0x96:
    if (1 < *(uint *)((int)parseContext + 0xc)) {
      scratchR7 = "";
      scratchR6 = "sampler3D";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," supported in vertex/fragment shaders only ",
                 "sampler3D","","",staleR9Value,scratchR10);
      TParseContext__recover(parseContext);
    }
    symbolTable = *(int **)((int)parseContext + 4);
    typeTmp1Word20OrPubType = (unsigned char *)0x7;
    goto setLevelsBytes5;
  case 0x97:
    if (1 < *(uint *)((int)parseContext + 0xc)) {
      scratchR7 = "";
      scratchR6 = "samplerCube";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," supported in vertex/fragment shaders only ",
                 "samplerCube","","",staleR9Value,scratchR10);
      TParseContext__recover(parseContext);
    }
    symbolTable = *(int **)((int)parseContext + 4);
    typeTmp1Word20OrPubType = (unsigned char *)0x8;
    goto setLevelsBytes5;
  case 0x98:
    if (1 < *(uint *)((int)parseContext + 0xc)) {
      scratchR7 = "";
      scratchR6 = "sampler1DShadow";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," supported in vertex/fragment shaders only ",
                 "sampler1DShadow","","",staleR9Value,scratchR10);
      TParseContext__recover(parseContext);
    }
    symbolTable = *(int **)((int)parseContext + 4);
    typeTmp1Word20OrPubType = (unsigned char *)0x9;
    goto setLevelsBytes5;
  case 0x99:
    if (1 < *(uint *)((int)parseContext + 0xc)) {
      scratchR7 = "";
      scratchR6 = "sampler2DShadow";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," supported in vertex/fragment shaders only ",
                 "sampler2DShadow","","",staleR9Value,scratchR10);
      TParseContext__recover(parseContext);
    }
    symbolTable = *(int **)((int)parseContext + 4);
    typeTmp1Word20OrPubType = (unsigned char *)0xa;
    goto setLevelsBytes5;
  case 0x9a:
    if (1 < *(uint *)((int)parseContext + 0xc)) {
      scratchR7 = "";
      scratchR6 = "sampler2DRect";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," supported in vertex/fragment shaders only ",
                 "sampler2DRect","","",staleR9Value,scratchR10);
      TParseContext__recover(parseContext);
    }
    extensionError = TParseContext__extensionErrorCheck(parseContext,*(uint *)yyvsp,"GL_ARB_texture_rectangle")
    ;
    if (extensionError != 0) {
      TParseContext__recover(parseContext);
    }
    symbolTable = *(int **)((int)parseContext + 4);
    typeTmp1Word20OrPubType = (unsigned char *)0xb;
    goto setLevelsBytes5;
  case 0x9b:
    if (1 < *(uint *)((int)parseContext + 0xc)) {
      scratchR7 = "";
      scratchR6 = "sampler2DRectShadow";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," supported in vertex/fragment shaders only ",
                 "sampler2DRectShadow","","",staleR9Value,scratchR10);
      TParseContext__recover(parseContext);
    }
    extensionError = TParseContext__extensionErrorCheck(parseContext,*(uint *)yyvsp,"GL_ARB_texture_rectangle")
    ;
    if (extensionError != 0) {
      TParseContext__recover(parseContext);
    }
    symbolTable = *(int **)((int)parseContext + 4);
    typeTmp1Word20OrPubType = (unsigned char *)0xc;
setLevelsBytes5:
    levelsBytes = symbolTable[1] - *symbolTable;
    pubSize = (unsigned char *)0x1;
setTypeTmp2StructureOrPubLine:
    typeTmp2StructureOrPubLine = *(unsigned char **)yyvsp;
setTypeTmp1BitsOrPubQualifier3:
    typeTmp1BitsOrPubQualifier = (unsigned char *)(uint)((uint)(levelsBytes >> 2) < 4);
    typeTmp2ArraySizeOrPubUserDef = (unsigned char *)0x0;
    typeTmp2VtableOrPubArray = (unsigned char *)0x0;
    pubMatrix = (unsigned char *)0x0;
    typeTmp1Word14OrStr2Data = (unsigned char *)0x0;
    typeTmp1TypeNameOrStr2Alloc = (unsigned char *)0x0;
    typeTmp1Word0cOrPubMatrix = (unsigned char *)0x0;
    yyvalUserDef = (unsigned char *)0x0;
    yyvalMatrix = (unsigned char *)0x0;
    yyvalArray = (unsigned char *)0x0;
    yyvalNodeReg = yyvalNode;
    yyvalTypeOrFunction = typeTmp1Word20OrPubType;
    yyvalQualifierOrParamType = typeTmp1BitsOrPubQualifier;
    yyvalSize = pubSize;
    yyvalTypeLine = typeTmp2StructureOrPubLine;
    typeTmp1VtableOrStr1Alloc = typeTmp1Word20OrPubType;
    typeTmp1ArraySizeOrStr1Data = typeTmp1BitsOrPubQualifier;
    typeTmp1StructureOrPubSize = pubSize;
    typeTmp1Word18OrPubLine = typeTmp2StructureOrPubLine;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    break;
  case 0x9c:
    if (1 < *(uint *)((int)parseContext + 0xc)) {
      scratchR7 = "";
      scratchR6 = "struct";
      TParseContext__error
                ((int)parseContext,*(char **)(yyvsp + 0x28),
                 " supported in vertex/fragment shaders only ","struct","","",staleR9Value,scratchR10);
      TParseContext__recover(parseContext);
    }
    yyvalSize = *(unsigned char **)(yyvsp + 0x18);
    yyvalMatrix = *(unsigned char **)(yyvsp + 0x1c);
    yyvalArray = *(unsigned char **)(yyvsp + 0x20);
    yyvalUserDef = *(unsigned char **)(yyvsp + 0x24);
    yyvalTypeLine = *(unsigned char **)(yyvsp + 0x28);
    yyvalNodeReg = yyvalNode;
    yyvalTypeOrFunction = *(unsigned char **)(yyvsp + 0x10);
    yyvalQualifierOrParamType = (unsigned char *)
                (uint)((uint)((*(int **)((int)parseContext + 4))[1] - **(int **)((int)parseContext + 4) >> 2)
                      < 4);
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    break;
  case 0x9d:
    yyvalUserDef = (unsigned char *)(*(uint *)(yyvsp + 8) + 0xc);
    typeTmp1Word20OrPubType = (unsigned char *)0xe;
    pubSize = (unsigned char *)0x1;
    pubMatrix = (unsigned char *)0x0;
    typeTmp1BitsOrPubQualifier = (unsigned char *)
                (uint)((uint)((*(int **)((int)parseContext + 4))[1] - **(int **)((int)parseContext + 4) >> 2)
                      < 4);
    typeTmp2VtableOrPubArray = (unsigned char *)0x0;
    yyvalTypeLine = *(unsigned char **)yyvsp;
    yyvalTypeOrFunction = (unsigned char *)0xe;
    yyvalSize = (unsigned char *)0x1;
    yyvalArray = (unsigned char *)0x0;
    typeTmp1VtableOrStr1Alloc = (unsigned char *)0xe;
    typeTmp1StructureOrPubSize = (unsigned char *)0x1;
    typeTmp1Word0cOrPubMatrix = (unsigned char *)0x0;
    typeTmp1TypeNameOrStr2Alloc = (unsigned char *)0x0;
    yyvalMatrix = (unsigned char *)0x0;
    yyvalQualifierOrParamType = typeTmp1BitsOrPubQualifier;
    typeTmp1ArraySizeOrStr1Data = typeTmp1BitsOrPubQualifier;
    typeTmp1Word14OrStr2Data = yyvalUserDef;
    pubCopy850Line = yyvalTypeLine;
    typeTmp2ArraySizeOrPubUserDef = yyvalUserDef;
    typeTmp2StructureOrPubLine = yyvalTypeLine;
    break;
  case 0x9e:
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    newType = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x28);
    structDeclarationListTypeList = *(unsigned char **)(yyvsp + -0x1c);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_
              ((unsigned char *)&typeTmp1VtableOrStr1Alloc,*(unsigned char **)(yyvsp + -0x80));
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_((unsigned char *)&typeTmp1TypeNameOrStr2Alloc,(unsigned char *)&typeTmp1VtableOrStr1Alloc);
    picBase2 = (unsigned char *)0xa7b8374c;
    *(undefined ***)newType = &PTR___ZN5TTypeD1Ev_a7b7d640;
    *(undefined4 *)(newType + 0x20) = 0;
    *(uint *)(newType + 0x24) = *(uint *)(newType + 0x24) & 0x9ff | 0x700800;
    *(undefined4 *)(newType + 4) = 0;
    *(unsigned char **)(newType + 8) = structDeclarationListTypeList;
    *(undefined4 *)(newType + 0xc) = 0;
    *(undefined4 *)(newType + 0x14) = 0;
    *(undefined4 *)(newType + 0x1c) = 0;
    setStructSizeResult3 = TType__setStructSize(newType,structDeclarationListTypeList);
    typeTmp1Word14Copy = typeTmp1Word14OrStr2Data;
    picBase = (unsigned char *)0xa7b8374c;
    *(undefined4 *)(newType + 0x18) = setStructSizeResult3;
    typeTmp1Word14OrStr2Data[(int)*(unsigned char **)(typeTmp1Word14OrStr2Data + -0xc)] = *stringTerminalPtr_a7b7ba88;
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    stringMem2 = (void *)TPoolAllocator__allocate(poolAllocator,8);
    cr0 = (stringMem2 == (void *)0x0) << 1;
    fieldTypeName = (void *)0x0;
    if (stringMem2 != (void *)0x0) {
      ctorAlloc14[0] = GetGlobalPoolAllocator();
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                (stringMem2,(char *)typeTmp1Word14Copy,(unsigned char *)ctorAlloc14);
      fieldTypeName = stringMem2;
    }
    *(void **)(newType + 0x10) = fieldTypeName;
    refCountPtr = typeTmp1Word14OrStr2Data + -4;
    destroyAlloc62[0] = typeTmp1TypeNameOrStr2Alloc;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    if ((int)oldRefCount2 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(typeTmp1Word14OrStr2Data + -0xc),destroyAlloc62);
    }
    refCountPtr = typeTmp1ArraySizeOrStr1Data + -4;
    destroyAlloc63[0] = typeTmp1VtableOrStr1Alloc;
    do {
      oldRefCount = *(uint *)refCountPtr;
      if (reservation != '\0') {
        newRefCount = storeWordConditionalIndexed(oldRefCount - 1,0,refCountPtr);
        *(uint *)refCountPtr = newRefCount;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    if ((int)oldRefCount < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(typeTmp1ArraySizeOrStr1Data + -0xc),destroyAlloc63);
    }
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    newVariable = (int *)TPoolAllocator__allocate(poolAllocator,0x40);
    variableVtable = PTR_vtable_a7b7c0b4 + 8;
    newVariable[1] = *(uint *)(yyvsp + -0x80);
    *newVariable = (int)variableVtable;
    newTypeWordc = *(int *)(newType + 0xc);
    newTypeWord10 = *(int *)(newType + 0x10);
    scratchR7 = *(char **)(newType + 0x14);
    scratchR6 = *(char **)(newType + 0x18);
    newTypeWord1c = *(int *)(newType + 0x1c);
    newTypeWord20 = *(int *)(newType + 0x20);
    newTypeArraySize = *(int *)(newType + 4);
    newTypeWord8 = *(int *)(newType + 8);
    newVariable[3] = (int)(picBase2 + -0x610c);
    newVariable[6] = newTypeWordc;
    newVariable[7] = newTypeWord10;
    newVariable[8] = (int)scratchR7;
    newVariable[9] = (int)scratchR6;
    newVariable[10] = newTypeWord1c;
    newVariable[0xb] = newTypeWord20;
    newVariable[4] = newTypeArraySize;
    newVariable[5] = newTypeWord8;
    oldVariableTypeBits = newVariable[0xc];
    qualifierBits = *(uint *)(newType + 0x24) & 0xfe000000;
    newVariable[0xc] = qualifierBits | oldVariableTypeBits & 0x1ffffff;
    basicTypeBits = (*(uint *)(newType + 0x24) >> 0x13 & 0x3f) << 0x13;
    newVariable[0xc] = basicTypeBits | qualifierBits | oldVariableTypeBits & 0x7ffff;
    sizeFieldBits = *(uint *)(newType + 0x24) & 0x7f800;
    newVariable[0xc] = sizeFieldBits | basicTypeBits | qualifierBits | oldVariableTypeBits & 0x7ff;
    matrixBit = (*(uint *)(newType + 0x24) >> 10 & 1) << 10;
    newVariable[0xc] = matrixBit | sizeFieldBits | basicTypeBits | qualifierBits | oldVariableTypeBits & 0x3ff;
    newVariable[0xc] = (*(uint *)(newType + 0x24) >> 9 & 1) << 9 |
                   matrixBit | sizeFieldBits | basicTypeBits | qualifierBits | oldVariableTypeBits & 0x1ff;
    newVariable[0xd] = 1;
    newVariable[0xe] = 0;
    newVariable[0xf] = 0;
    symbolTable2 = *(int **)((int)parseContext + 4);
    nextUniqueId = symbolTable2[3];
    symbolTable2[3] = nextUniqueId + 1;
    newVariable[2] = nextUniqueId + 1;
    lastLevel = *(undefined4 *)(*symbolTable2 + ((symbolTable2[1] - *symbolTable2 & 0xfffffffcU) - 4));
    typeTmp1ArraySizeOrStr1Data = (unsigned char *)0x0;
    keyString = (unsigned char *)
              (**(code **)(*newVariable + 8))(newVariable,newTypeWord20,newTypeWord1c,scratchR6,scratchR7,newTypeWord10,symbolTable2);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&variableKeyStrAlloc,keyString);
    variableValue = newVariable;
    std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&typeTmp1TypeNameOrStr2Alloc,lastLevel,&variableKeyStrAlloc);
    typeTmp1VtableOrStr1Alloc = typeTmp1TypeNameOrStr2Alloc;
    refCountPtr2 = (int *)(variableKeyStrData + -4);
    typeTmp1ArraySizeOrStr1Data = typeTmp1Word14OrStr2Data;
    destroyAlloc64[0] = variableKeyStrAlloc;
    do {
      oldRefCount4 = *refCountPtr2;
      if (reservation != '\0') {
        newRefCount4 = storeWordConditionalIndexed(oldRefCount4 + -1,0,refCountPtr2);
        *refCountPtr2 = newRefCount4;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    if (oldRefCount4 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(variableKeyStrData + -0xc),destroyAlloc64);
    }
    if (typeTmp1ArraySizeOrStr1Data == (unsigned char *)0x0) {
      identifierString = *(uint *)(yyvsp + -0x80);
      stringData = *(int *)(identifierString + 4);
      scratchR7 = "struct";
      *(unsigned char *)(stringData + *(int *)(stringData + -0xc)) = *stringTerminalPtr_a7b7ba88;
      scratchR6 = *(char **)(identifierString + 4);
      TParseContext__error
                ((int)parseContext,*(char **)(yyvsp + -0x84),"redefinition",scratchR6,"struct",newTypeWord10,
                 stringData,identifierString);
      TParseContext__recover(parseContext);
    }
    typeTmp1BitsOrPubQualifier = (unsigned char *)0x0;
    typeTmp1Word20OrPubType = (unsigned char *)0xe;
    pubSize = (unsigned char *)0x1;
    pubMatrix = (unsigned char *)0x0;
    typeTmp2VtableOrPubArray = (unsigned char *)0x0;
    yyvalTypeLine = *(unsigned char **)(yyvsp + -0xb0);
    yyvalTypeOrFunction = (unsigned char *)0xe;
    yyvalSize = (unsigned char *)0x1;
    yyvalArray = (unsigned char *)0x0;
    typeTmp1VtableOrStr1Alloc = (unsigned char *)0xe;
    typeTmp1ArraySizeOrStr1Data = (unsigned char *)0x0;
    typeTmp1StructureOrPubSize = (unsigned char *)0x1;
    typeTmp1Word0cOrPubMatrix = (unsigned char *)0x0;
    typeTmp1TypeNameOrStr2Alloc = (unsigned char *)0x0;
    yyvalQualifierOrParamType = (unsigned char *)0x0;
    yyvalMatrix = (unsigned char *)0x0;
    yyvalNodeReg = yyvalNode;
    yyvalUserDef = (unsigned char *)newType;
    typeTmp1Word14OrStr2Data = (unsigned char *)newType;
    pubCopy850Line = yyvalTypeLine;
    typeTmp2ArraySizeOrPubUserDef = (unsigned char *)newType;
    typeTmp2StructureOrPubLine = yyvalTypeLine;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    break;
  case 0x9f:
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    newType = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x28);
    structDeclarationListTypeList = *(unsigned char **)(yyvsp + -0x1c);
    ctorAlloc15[0] = GetGlobalPoolAllocator();
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
              ((unsigned char *)&typeTmp1VtableOrStr1Alloc,"",(unsigned char *)ctorAlloc15);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&typeTmp1TypeNameOrStr2Alloc,(unsigned char *)&typeTmp1VtableOrStr1Alloc);
    picBase2 = (unsigned char *)0xa7b8374c;
    *(undefined ***)newType = &PTR___ZN5TTypeD1Ev_a7b7d640;
    *(undefined4 *)(newType + 0x20) = 0;
    *(uint *)(newType + 0x24) = *(uint *)(newType + 0x24) & 0x9ff | 0x700800;
    *(undefined4 *)(newType + 4) = 0;
    *(unsigned char **)(newType + 8) = structDeclarationListTypeList;
    *(undefined4 *)(newType + 0xc) = 0;
    *(undefined4 *)(newType + 0x14) = 0;
    *(undefined4 *)(newType + 0x1c) = 0;
    setStructSizeResult3 = TType__setStructSize(newType,structDeclarationListTypeList);
    typeTmp1Word14Copy = typeTmp1Word14OrStr2Data;
    *(undefined4 *)(newType + 0x18) = setStructSizeResult3;
    picBase = (unsigned char *)0xa7b8374c;
    typeTmp1Word14OrStr2Data[(int)*(unsigned char **)(typeTmp1Word14OrStr2Data + -0xc)] = *stringTerminalPtr_a7b7ba88;
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    stringMem2 = (void *)TPoolAllocator__allocate(poolAllocator,8);
    cr0 = (stringMem2 == (void *)0x0) << 1;
    fieldTypeName = (void *)0x0;
    if (stringMem2 != (void *)0x0) {
      ctorAlloc16[0] = GetGlobalPoolAllocator();
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                (stringMem2,(char *)typeTmp1Word14Copy,(unsigned char *)ctorAlloc16);
      fieldTypeName = stringMem2;
    }
    *(void **)(newType + 0x10) = fieldTypeName;
    refCountPtr = typeTmp1Word14OrStr2Data + -4;
    destroyAlloc65[0] = typeTmp1TypeNameOrStr2Alloc;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    if ((int)oldRefCount2 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(typeTmp1Word14OrStr2Data + -0xc),destroyAlloc65);
    }
    refCountPtr = typeTmp1ArraySizeOrStr1Data + -4;
    destroyAlloc66[0] = typeTmp1VtableOrStr1Alloc;
    do {
      oldRefCount = *(uint *)refCountPtr;
      if (reservation != '\0') {
        newRefCount = storeWordConditionalIndexed(oldRefCount - 1,0,refCountPtr);
        *(uint *)refCountPtr = newRefCount;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    if ((int)oldRefCount < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(typeTmp1ArraySizeOrStr1Data + -0xc),destroyAlloc66);
    }
    typeTmp1Word20OrPubType = (unsigned char *)0xe;
    typeTmp1BitsOrPubQualifier = (unsigned char *)0x0;
    pubSize = (unsigned char *)0x1;
    pubMatrix = (unsigned char *)0x0;
    typeTmp2VtableOrPubArray = (unsigned char *)0x0;
    yyvalTypeLine = *(unsigned char **)(yyvsp + -0x84);
    yyvalTypeOrFunction = (unsigned char *)0xe;
    yyvalSize = (unsigned char *)0x1;
    yyvalArray = (unsigned char *)0x0;
    typeTmp1VtableOrStr1Alloc = (unsigned char *)0xe;
    typeTmp1ArraySizeOrStr1Data = (unsigned char *)0x0;
    typeTmp1StructureOrPubSize = (unsigned char *)0x1;
    typeTmp1Word0cOrPubMatrix = (unsigned char *)0x0;
    typeTmp1TypeNameOrStr2Alloc = (unsigned char *)0x0;
    yyvalQualifierOrParamType = (unsigned char *)0x0;
    yyvalMatrix = (unsigned char *)0x0;
    yyvalNodeReg = yyvalNode;
    yyvalUserDef = (unsigned char *)newType;
    typeTmp1Word14OrStr2Data = (unsigned char *)newType;
    pubCopy850Line = yyvalTypeLine;
    typeTmp2ArraySizeOrPubUserDef = (unsigned char *)newType;
    typeTmp2StructureOrPubLine = yyvalTypeLine;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    break;
  case 0xa1:
    yyvalTypeOrFunction = *(unsigned char **)(yyvsp + -0x1c);
    for (loopIndex = 0; yyssBase = stringTerminalPtr_a7b7ba88, yyvalNodeReg = yyvalNode, typeTmp3VtableReg = typeTmp3VtableOrPub3Array,
        typeTmp7VtableReg = typeTmp7Vtable[0],
        loopIndex < (uint)(*(int *)(*(uint *)(yyvsp + 0x10) + 8) -
                        *(int *)(*(uint *)(yyvsp + 0x10) + 4) >> 3); loopIndex = loopIndex + 1) {
      loopIndex3 = 0;
      fieldByteOffset2 = loopIndex * 8;
      while( true ) {
        elementPtr = *(undefined4 **)(yyvalTypeOrFunction + 8);
        if ((uint)((int)elementPtr - *(int *)(yyvalTypeOrFunction + 4) >> 3) <= loopIndex3) break;
        fieldType = *(int **)(*(int *)(yyvalTypeOrFunction + 4) + loopIndex3 * 8);
        fieldNameStr3 = *fieldType;
        fieldNameStr3 = (**(code **)(fieldNameStr3 + 0x1c))
                           (fieldType,elementPtr,scratchR5,scratchR6,scratchR7,staleR8Value,fieldNameStr3);
        fieldType = *(int **)(*(int *)(*(uint *)(yyvsp + 0x10) + 4) + fieldByteOffset2);
        fieldNameStr = (**(code **)(*fieldType + 0x1c))
                           (fieldType,r4In10,scratchR5,scratchR6,scratchR7,staleR8Value,
                            *(int *)(*(uint *)(yyvsp + 0x10) + 4));
        nameLenB = *(uint *)(*(int *)(fieldNameStr3 + 4) + -0xc);
        leftTextLen = nameLenB;
        secondNameLen = *(uint *)(*(int *)(fieldNameStr + 4) + -0xc);
        rightTextLen = secondNameLen;
        shorterLenPtr = &rightTextLen;
        if (nameLenB <= secondNameLen) {
          shorterLenPtr = &leftTextLen;
        }
        scratchR5 = (char *)*shorterLenPtr;
        fieldNameStr3 = _memcmp(*(undefined4 *)(fieldNameStr3 + 4),*(undefined4 *)(fieldNameStr + 4),scratchR5);
        cr0 = (fieldNameStr3 == 0) << 1;
        if (fieldNameStr3 == 0) {
          fieldNameStr3 = nameLenB - secondNameLen;
        }
        if (fieldNameStr3 == 0) {
          fieldType = *(int **)(*(int *)(*(uint *)(yyvsp + 0x10) + 4) + fieldByteOffset2);
          fieldNameStr3 = *fieldType;
          fieldNameStr3 = (**(code **)(fieldNameStr3 + 0x1c))
                             (fieldType,r4In11,scratchR5,scratchR6,scratchR7,staleR8Value,fieldNameStr3);
          scratchR5 = "duplicate field name in structure:";
          scratchR6 = "struct";
          *(unsigned char *)(*(int *)(fieldNameStr3 + 4) + *(int *)(*(int *)(fieldNameStr3 + 4) + -0xc)) = *yyssBase;
          scratchR7 = *(char **)(fieldNameStr3 + 4);
          TParseContext__error
                    ((int)parseContext,*(char **)(*(int *)(*(uint *)(yyvsp + 0x10) + 4) + fieldByteOffset2 + 4),
                     "duplicate field name in structure:","struct",scratchR7,staleR8Value,
                     *(uint *)(yyvsp + 0x10),scratchR10);
          TParseContext__recover(parseContext);
        }
        loopIndex3 = loopIndex3 + 1;
      }
      scratchR5 = (char *)(*(int *)(*(uint *)(yyvsp + 0x10) + 4) + fieldByteOffset2);
      if (elementPtr == *(undefined4 **)(yyvalTypeOrFunction + 0xc)) {
        std__vector_TTypeLine_pool_allocator_TTypeLine_____M_insert_aux
                  ((unsigned char *)yyvalTypeOrFunction,elementPtr,scratchR5);
      }
      else {
        if (elementPtr != (undefined4 *)0x0) {
          scratchR5Word4 = *(undefined4 *)(scratchR5 + 4);
          *elementPtr = *(undefined4 *)(*(int *)(*(uint *)(yyvsp + 0x10) + 4) + fieldByteOffset2);
          elementPtr[1] = scratchR5Word4;
        }
        *(int *)(yyvalTypeOrFunction + 8) = *(int *)(yyvalTypeOrFunction + 8) + 8;
      }
    }
    break;
  case 0xa2:
    yyvalTypeOrFunction = *(unsigned char **)(yyvsp + -0x1c);
    fieldType = (int *)**(undefined4 **)(*(uint *)(yyvsp + -0x1c) + 4);
    identifierString3 = (unsigned char *)
              (**(code **)(*fieldType + 0x1c))
                        (fieldType,scratchR4,scratchR5,scratchR6,scratchR7,staleR8Value,
                         *(undefined4 **)(*(uint *)(yyvsp + -0x1c) + 4));
    scratchR6 = (char *)(yyvsp + -0x48);
    voidError = TParseContext__voidErrorCheck
                       (parseContext,*(uint *)(yyvsp + -0x30),identifierString3,(unsigned char *)scratchR6);
    if (voidError != 0) {
      TParseContext__recover(parseContext);
    }
    for (loopIndex = 0; yyvalNodeReg = yyvalNode, typeTmp3VtableReg = typeTmp3VtableOrPub3Array, typeTmp7VtableReg = typeTmp7Vtable[0],
        loopIndex < (uint)((int)(*(uint *)(yyvalTypeOrFunction + 8) - *(uint *)(yyvalTypeOrFunction + 4)) >> 3);
        loopIndex = loopIndex + 1) {
      fieldType = *(int **)(*(uint *)(yyvalTypeOrFunction + 4) + loopIndex * 8);
      typeSpecifierSize4 = *(uint *)(yyvsp + -0x40);
      scratchR6 = *(char **)(yyvsp + -0x3c);
      scratchR7 = *(char **)(yyvsp + -0x34);
      (**(code **)(*fieldType + 0xc))(fieldType,*(uint *)(yyvsp + -0x48),typeSpecifierSize4,scratchR6,scratchR7);
      typeSpecifierUserDef2 = *(int **)(yyvsp + -0x34);
      if (typeSpecifierUserDef2 != (int *)0x0) {
        paramEntry = *(int **)(*(uint *)(yyvalTypeOrFunction + 4) + loopIndex * 8);
        objVtable = *paramEntry;
        userTypeName = (**(code **)(*typeSpecifierUserDef2 + 0x18))
                           (typeSpecifierUserDef2,r4In12,typeSpecifierSize4,scratchR6,scratchR7,staleR8Value,*typeSpecifierUserDef2);
        (**(code **)(objVtable + 0x10))(paramEntry,userTypeName);
      }
    }
    break;
  case 0xa3:
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    typeListMem = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x10);
    cr0 = (typeListMem == (unsigned char *)0x0) << 1;
    typeList = (unsigned char *)(unsigned char *)0x0;
    if (typeListMem != (unsigned char *)0x0) {
      allocatorArg5 = GetGlobalPoolAllocator();
      *(undefined4 *)(typeListMem + 0xc) = 0;
      *(undefined4 *)typeListMem = allocatorArg5;
      *(undefined4 *)(typeListMem + 4) = 0;
      *(undefined4 *)(typeListMem + 8) = 0;
      typeList = (unsigned char *)typeListMem;
    }
    goto setYyvalTypeOrFunction2;
  case 0xa4:
    typeList = yyvalTypeOrFunction;
setYyvalTypeOrFunction2:
    yyvalTypeOrFunction = typeList;
    elementEnd = *(uint **)(yyvalTypeOrFunction + 8);
    if (elementEnd == *(uint **)(yyvalTypeOrFunction + 0xc)) {
      std__vector_TTypeLine_pool_allocator_TTypeLine_____M_insert_aux
                ((unsigned char *)yyvalTypeOrFunction,elementEnd,yyvsp + 0x10);
      yyvalNodeReg = yyvalNode;
      typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
      typeTmp7VtableReg = typeTmp7Vtable[0];
    }
    else {
      finishPtr2 = 0;
      if (elementEnd != (uint *)0x0) {
        structDeclaratorWord14 = *(uint *)(yyvsp + 0x14);
        *elementEnd = *(uint *)(yyvsp + 0x10);
        elementEnd[1] = structDeclaratorWord14;
        finishPtr2 = *(int *)(yyvalTypeOrFunction + 8);
      }
      *(int *)(yyvalTypeOrFunction + 8) = finishPtr2 + 8;
      yyvalNodeReg = yyvalNode;
      typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
      typeTmp7VtableReg = typeTmp7Vtable[0];
    }
    break;
  case 0xa5:
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    newTypeMem = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x28);
    picBaseValue = (unsigned char *)0xa7b8374c;
    typeVtablePtr = &PTR___ZN5TTypeD1Ev_a7b7d640;
    *(undefined ***)newTypeMem = &PTR___ZN5TTypeD1Ev_a7b7d640;
    typeBitsWord2 = (unsigned char *)((uint)*(unsigned char **)(newTypeMem + 0x24) & 0x9ff | 0x800);
    cr0 = (typeBitsWord2 == (unsigned char *)0x0) << 1;
    *(unsigned char **)(newTypeMem + 0x20) = (unsigned char *)0x0;
    *(unsigned char **)(newTypeMem + 0x24) = typeBitsWord2;
    *(unsigned char **)(newTypeMem + 4) = (unsigned char *)0x0;
    *(unsigned char **)(newTypeMem + 8) = (unsigned char *)0x0;
    *(unsigned char **)(newTypeMem + 0xc) = (unsigned char *)0x0;
    *(unsigned char **)(newTypeMem + 0x10) = (unsigned char *)0x0;
    *(unsigned char **)(newTypeMem + 0x14) = (unsigned char *)0x0;
    *(unsigned char **)(newTypeMem + 0x18) = (unsigned char *)0x0;
    *(unsigned char **)(newTypeMem + 0x1c) = (unsigned char *)0x0;
    yyvalQualifierOrParamType = *(unsigned char **)yyvsp;
    methodArg = *(undefined **)(yyvsp + 4);
    nodeMethod = *(code **)(*(unsigned char **)newTypeMem + 0x14);
    yyvalTypeOrFunction = newTypeMem;
    goto LAB_97baae6c;
  case 0xa6:
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    yyvalTypeOrFunction = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x28);
    staleR8Value = (unsigned char *)0xa7b8374c;
    typeVtablePtr = &PTR___ZN5TTypeD1Ev_a7b7d640;
    *(undefined ***)yyvalTypeOrFunction = &PTR___ZN5TTypeD1Ev_a7b7d640;
    typeBitsWord = (unsigned char *)((uint)*(unsigned char **)(yyvalTypeOrFunction + 0x24) & 0x9ff | 0x800);
    cr0 = (typeBitsWord == (unsigned char *)0x0) << 1;
    *(unsigned char **)(yyvalTypeOrFunction + 0x20) = (unsigned char *)0x0;
    *(unsigned char **)(yyvalTypeOrFunction + 0x24) = typeBitsWord;
    *(unsigned char **)(yyvalTypeOrFunction + 4) = (unsigned char *)0x0;
    *(unsigned char **)(yyvalTypeOrFunction + 8) = (unsigned char *)0x0;
    *(unsigned char **)(yyvalTypeOrFunction + 0xc) = (unsigned char *)0x0;
    *(unsigned char **)(yyvalTypeOrFunction + 0x10) = (unsigned char *)0x0;
    *(unsigned char **)(yyvalTypeOrFunction + 0x14) = (unsigned char *)0x0;
    *(unsigned char **)(yyvalTypeOrFunction + 0x18) = (unsigned char *)0x0;
    *(unsigned char **)(yyvalTypeOrFunction + 0x1c) = (unsigned char *)0x0;
    yyvalQualifierOrParamType = *(unsigned char **)(yyvsp + -0x84);
    (**(code **)(*(unsigned char **)yyvalTypeOrFunction + 0x14))
              (yyvalTypeOrFunction,*(uint *)(yyvsp + -0x80),scratchR5,scratchR6,scratchR7,0xa7b8374c,
               &PTR___ZN5TTypeD1Ev_a7b7d640);
    constantUnion = (**(code **)(**(int **)(yyvsp + -0x24) + 0x18))(*(int **)(yyvsp + -0x24));
    if (constantUnion != 0) {
      constantUnionNode2 = (int *)(**(code **)(**(int **)(yyvsp + -0x24) + 0x18))(*(int **)(yyvsp + -0x24))
      ;
      queryResult = (**(code **)(*constantUnionNode2 + 0x40))(constantUnionNode2);
      if ((queryResult == 2) &&
         (queryResult = (**(code **)(**(int **)(yyvsp + -0x24) + 0x18))(*(int **)(yyvsp + -0x24)),
         yyvalTypeCopy = yyvalTypeOrFunction, 0 < **(int **)(queryResult + 0x30))) {
        constantUnionNode = (**(code **)(**(int **)(yyvsp + -0x24) + 0x18))
                           (*(int **)(yyvsp + -0x24),r4In13,scratchR5,scratchR6,scratchR7,staleR8Value,
                            typeVtablePtr,scratchR10);
        indexConstant = (unsigned char *)**(uint **)(constantUnionNode + 0x30);
        *(unsigned char **)(yyvalTypeCopy + 0x24) =
             (unsigned char *)((uint)*(unsigned char **)(yyvalTypeCopy + 0x24) | 0x200);
        *(unsigned char **)(yyvalTypeCopy + 4) = indexConstant;
        yyvalNodeReg = yyvalNode;
        typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
        typeTmp7VtableReg = typeTmp7Vtable[0];
        break;
      }
    }
    scratchR10 = *(uint *)(yyvsp + -0x80);
    picBase = (unsigned char *)0xa7b8374c;
    currentFunctionObj = *(int **)(scratchR10 + 4);
    msgText = "structure field array size must be a positive integer";
    *(unsigned char *)((int)currentFunctionObj + currentFunctionObj[-3]) = *stringTerminalPtr_a7b7ba88;
    scratchR6 = *(char **)(scratchR10 + 4);
    errorLine = *(char **)(yyvsp + -0x58);
    goto setScratchR72;
  case 0xb1:
    symbolTable3 = *(unsigned char **)((int)parseContext + 4);
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    elementPtr = (undefined4 *)TPoolAllocator__allocate(poolAllocator,0x10);
    levelPool = (unsigned char *)GetGlobalPoolAllocator();
    *elementPtr = levelPool;
    elementPtr[1] = 0;
    treeNodeMem = (undefined4 *)TPoolAllocator__allocate(levelPool,0x1c);
    elementPtr[2] = 0;
    elementPtr[1] = treeNodeMem;
    *treeNodeMem = 0;
    *(undefined4 *)(elementPtr[1] + 4) = 0;
    *(undefined4 *)(elementPtr[1] + 8) = elementPtr[1];
    *(undefined4 *)(elementPtr[1] + 0xc) = elementPtr[1];
    treeFinish2 = *(int **)(symbolTable3 + 4);
    destroyAlloc67[0] = elementPtr;
    if (treeFinish2 == *(int **)(symbolTable3 + 8)) {
      std__vector_TSymbolTableLevel__std__allocator_TSymbolTableLevel______M_insert_aux
                (symbolTable3,treeFinish2,destroyAlloc67);
      yyvalNodeReg = yyvalNode;
      typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
      typeTmp7VtableReg = typeTmp7Vtable[0];
    }
    else {
      levelsFinish = 0;
      if (treeFinish2 != (int *)0x0) {
        *treeFinish2 = (int)elementPtr;
        levelsFinish = *(int *)(symbolTable3 + 4);
      }
      *(int *)(symbolTable3 + 4) = levelsFinish + 4;
      yyvalNodeReg = yyvalNode;
      typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
      typeTmp7VtableReg = typeTmp7Vtable[0];
    }
    break;
  case 0xb2:
    symbolTable = *(int **)((int)parseContext + 4);
    levelsEnd = symbolTable[1];
    poppedLevel = *(void **)(*symbolTable + ((levelsEnd - *symbolTable & 0xfffffffcU) - 4));
    if (poppedLevel != (void *)0x0) {
      ((int (*)())__ZN17TSymbolTableLevelD1Ev)(poppedLevel);
      levelsEnd = symbolTable[1];
    }
    symbolTable[1] = levelsEnd + -4;
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    break;
  case 0xb3:
    statementListNode = *(int **)(yyvsp + -0x50);
    yyvalNodeReg = (unsigned char *)0x0;
    if (statementListNode != (int *)0x0) {
      (**(code **)(*statementListNode + 0x60))(statementListNode,1);
      yyvalNodeReg = *(unsigned char **)(yyvsp + -0x50);
      typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
      typeTmp7VtableReg = typeTmp7Vtable[0];
    }
    break;
  case 0xb8:
    intermediate = *(unsigned char **)parseContext;
    aggregateLine = 0;
    operandNode = *(unsigned char **)(yyvsp + 8);
setYyvalNodeReg3:
    yyvalNodeReg = (unsigned char *)TIntermediate__makeAggregate(intermediate,operandNode,aggregateLine);
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    break;
  case 0xb9:
    intermediate = *(unsigned char **)parseContext;
    scratchR6 = (char *)0x0;
    leftNode = *(unsigned char **)(yyvsp + -0x24);
    operandNode = *(unsigned char **)(yyvsp + 8);
    goto loopSetYyvalNodeReg;
  case 0xbc:
    boolError = __ZN13TParseContext14boolErrorCheckEiPK12TIntermTyped
                       (parseContext,*(uint *)(yyvsp + -0xb0),*(unsigned char **)(yyvsp + -0x50),
                        scratchR6,scratchR7,staleR8Value);
    if (boolError != 0) {
      TParseContext__recover(parseContext);
    }
    typeTmp1VtableOrStr1Alloc = *(unsigned char **)(yyvsp + 8);
    scratchR6 = *(char **)(yyvsp + 0xc);
    scratchR7 = *(char **)(yyvsp + -0xb0);
    typeTmp1ArraySizeOrStr1Data = (unsigned char *)scratchR6;
    yyvalNodeReg = (unsigned char *)
             __ZN13TIntermediate12addSelectionEP12TIntermTyped15TIntermNodePairi
                       (*(unsigned char **)parseContext,*(uint *)(yyvsp + -0x50),typeTmp1VtableOrStr1Alloc,scratchR6,
                        scratchR7);
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    break;
  case 0xbd:
  case 0xcc:
    yyvalNode2 = *(uint *)(yyvsp + 8);
    yyvalNodeReg = *(unsigned char **)(yyvsp + -0x50);
    break;
  case 0xbe:
    yyvalNodeReg = *(unsigned char **)(yyvsp + 8);
    goto setYyvalNode2;
  case 0xbf:
    yyvalNode = *(unsigned char **)(yyvsp + 8);
    nodeLine2 = (**(code **)**(undefined4 **)(yyvsp + 8))(*(undefined4 **)(yyvsp + 8));
    errorCheckResult = __ZN13TParseContext14boolErrorCheckEiPK12TIntermTyped
                       (parseContext,nodeLine2,*(unsigned char **)(yyvsp + 8),scratchR6,scratchR7,staleR8Value);
    goto loopSetYyvalNodeReg3;
  case 0xc0:
    slotArg = yyvsp + -0x74;
    structQualifierError = TParseContext__structQualifierErrorCheck
                       (parseContext,*(uint *)(yyvsp + -0x58),(unsigned char *)slotArg,scratchR6,scratchR7,
                        staleR8Value,staleR9Value);
    if (structQualifierError != 0) {
      TParseContext__recover(parseContext);
    }
    boolError = __ZN13TParseContext14boolErrorCheckEiRK11TPublicType
                       (parseContext,*(uint *)(yyvsp + -0x58),(unsigned char *)slotArg);
    if (boolError != 0) {
      TParseContext__recover(parseContext);
    }
    scratchR7 = *(char **)(yyvsp + 8);
    executeInitializerResult = TParseContext__executeInitializer
                       (parseContext,*(uint *)(yyvsp + -0x58),*(unsigned char **)(yyvsp + -0x54),
                        (unsigned char *)slotArg,(unsigned char *)scratchR7,&initializerNodeOut);
    scratchR6 = (char *)slotArg;
    if (executeInitializerResult == 0) goto yynCase2;
callTParseContext_recover2:
    TParseContext__recover(parseContext);
    scratchR6 = (char *)slotArg;
    yyvalNodeReg = (unsigned char *)0x0;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    break;
  case 0xc1:
    symbolTable3 = *(unsigned char **)((int)parseContext + 4);
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    elementPtr = (undefined4 *)TPoolAllocator__allocate(poolAllocator,0x10);
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    loopPoolCopy = poolAllocator;
    goto storeElementPtr;
  case 0xc2:
    symbolTable = *(int **)((int)parseContext + 4);
    levelsEnd = symbolTable[1];
    poppedLevel = *(void **)(*symbolTable + ((levelsEnd - *symbolTable & 0xfffffffcU) - 4));
    if (poppedLevel != (void *)0x0) {
      ((int (*)())__ZN17TSymbolTableLevelD1Ev)(poppedLevel);
      levelsEnd = symbolTable[1];
    }
    symbolTable[1] = levelsEnd + -4;
    scratchR7 = (char *)0x1;
    intermediate = *(unsigned char **)parseContext;
    loopBodyNode = *(unsigned char **)(yyvsp + 8);
    conditionNode = *(unsigned char **)(yyvsp + -0x50);
    whileLine = *(uint *)(yyvsp + -0xdc);
    goto setScratchR6;
  case 0xc3:
    goto yynCasec3;
  case 0xc4:
    boolError = __ZN13TParseContext14boolErrorCheckEiPK12TIntermTyped
                       (parseContext,*(uint *)yyvsp,*(unsigned char **)(yyvsp + -0x50),scratchR6,scratchR7
                        ,staleR8Value);
    if (boolError != 0) {
      TParseContext__recover(parseContext);
    }
    intermediate = *(unsigned char **)parseContext;
    loopBodyNode = *(unsigned char **)(yyvsp + -0xd4);
    scratchR7 = (char *)0x0;
    conditionNode = *(unsigned char **)(yyvsp + -0x50);
    whileLine = *(uint *)(yyvsp + -0xb0);
setScratchR6:
    scratchR6 = (char *)0x0;
    yyvalNode = (unsigned char *)
                TIntermediate__addLoop(intermediate,loopBodyNode,conditionNode,(unsigned char *)0x0,scratchR7,whileLine);
    loopDepth = *(int *)((int)parseContext + 0x20);
loopSetLoopDepth:
    loopDepth = loopDepth + -1;
    goto storeParseContext;
  case 0xc5:
    symbolTable3 = *(unsigned char **)((int)parseContext + 4);
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    elementPtr = (undefined4 *)TPoolAllocator__allocate(poolAllocator,0x10);
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    switchPoolCopy = poolAllocator;
storeElementPtr:
    *elementPtr = poolAllocator;
    elementPtr[1] = 0;
    treeNodeMem = (undefined4 *)TPoolAllocator__allocate(poolAllocator,0x1c);
    elementPtr[2] = 0;
    elementPtr[1] = treeNodeMem;
    *treeNodeMem = 0;
    *(undefined4 *)(elementPtr[1] + 4) = 0;
    *(undefined4 *)(elementPtr[1] + 8) = elementPtr[1];
    *(undefined4 *)(elementPtr[1] + 0xc) = elementPtr[1];
    treeFinish = *(undefined4 **)(symbolTable3 + 4);
    destroyAlloc67[0] = elementPtr;
    if (treeFinish == *(undefined4 **)(symbolTable3 + 8)) {
      std__vector_TSymbolTableLevel__std__allocator_TSymbolTableLevel______M_insert_aux
                (symbolTable3,treeFinish,destroyAlloc67);
    }
    else {
      levelsFinish = 0;
      if (treeFinish != (undefined4 *)0x0) {
        *treeFinish = elementPtr;
        levelsFinish = *(int *)(symbolTable3 + 4);
      }
      *(int *)(symbolTable3 + 4) = levelsFinish + 4;
    }
yynCasec3:
    loopDepth = *(int *)((int)parseContext + 0x20) + 1;
storeParseContext:
    *(int *)((int)parseContext + 0x20) = loopDepth;
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    break;
  case 0xc6:
    symbolTable = *(int **)((int)parseContext + 4);
    levelsEnd = symbolTable[1];
    poppedLevel = *(void **)(*symbolTable + ((levelsEnd - *symbolTable & 0xfffffffcU) - 4));
    if (poppedLevel != (void *)0x0) {
      ((int (*)())__ZN17TSymbolTableLevelD1Ev)(poppedLevel);
      levelsEnd = symbolTable[1];
    }
    symbolTable[1] = levelsEnd + -4;
    yyvalNode = (unsigned char *)
                TIntermediate__makeAggregate
                          (*(unsigned char **)parseContext,*(unsigned char **)(yyvsp + -0x7c),
                           *(uint *)(yyvsp + -0xdc));
    scratchR7 = (char *)0x1;
    addLoopResult = (unsigned char *)
              TIntermediate__addLoop
                        (*(unsigned char **)parseContext,*(unsigned char **)(yyvsp + 8),
                         *(unsigned char **)(yyvsp + -0x50),*(unsigned char **)(yyvsp + -0x4c),1,
                         *(uint *)(yyvsp + -0x108));
    scratchR6 = *(char **)(yyvsp + -0x108);
    yyvalNode = (unsigned char *)
                TIntermediate__growAggregate
                          (*(unsigned char **)parseContext,(unsigned char *)yyvalNode,addLoopResult,(int)scratchR6)
    ;
    aggregateNode = (int *)(**(code **)(*(unsigned char **)yyvalNode + 0x1c))(yyvalNode);
    (**(code **)(*aggregateNode + 0x60))(aggregateNode,1);
    loopDepth = *(int *)((int)parseContext + 0x20);
    goto loopSetLoopDepth;
  case 0xcb:
    yyvalNodeReg = *(unsigned char **)(yyvsp + -0x24);
setYyvalNode2:
    yyvalNode2 = 0;
    break;
  case 0xcd:
    if (*(int *)((int)parseContext + 0x20) < 1) {
      scratchR6 = "";
      scratchR7 = scratchR6;
      TParseContext__error
                ((int)parseContext,*(char **)(yyvsp + -0x2c),"continue statement only allowed in loops"
                 ,"","",staleR8Value,staleR9Value,scratchR10);
      TParseContext__recover(parseContext);
    }
    intermediateForBranch = *(void **)parseContext;
    branchOp = 0x65;
    goto setYyvalNodeReg4;
  case 0xce:
    if (*(int *)((int)parseContext + 0x20) < 1) {
      scratchR6 = "";
      scratchR7 = scratchR6;
      TParseContext__error
                ((int)parseContext,*(char **)(yyvsp + -0x2c),"break statement only allowed in loops",""
                 ,"",staleR8Value,staleR9Value,scratchR10);
      TParseContext__recover(parseContext);
    }
    intermediateForBranch = *(void **)parseContext;
    branchOp = 100;
    goto setYyvalNodeReg4;
  case 0xcf:
    returnLine = *(uint *)(yyvsp + -0x2c);
    addBranchResult = __ZN13TIntermediate9addBranchE9TOperatori(*(void **)parseContext,99,returnLine);
    yyvalNode = (unsigned char *)((ulonglong)addBranchResult >> 0x20);
    currentFunctionObj = (int *)**(undefined4 **)((int)parseContext + 0x28);
    queryResult = (*(code *)currentFunctionObj[8])
                       (*(undefined4 **)((int)parseContext + 0x28),(int)addBranchResult,returnLine,scratchR6,scratchR7,
                        staleR8Value,currentFunctionObj);
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    if (queryResult == 0) break;
    errorLine = *(char **)(yyvsp + -0x2c);
    msgText = "non-void function must return a value";
    goto setScratchR62;
  case 0xd0:
    expressionNode = *(uint *)(yyvsp + -0x24);
    scratchR6 = *(char **)(yyvsp + -0x58);
    addBranchResult = __ZN13TIntermediate9addBranchE9TOperatorP12TIntermTypedi
                       (*(void **)parseContext,99,expressionNode,scratchR6);
    yyvalNode = (unsigned char *)((ulonglong)addBranchResult >> 0x20);
    currentFunctionObj = *(int **)((int)parseContext + 0x28);
    *(undefined4 *)((int)parseContext + 0x2c) = 1;
    queryResult = (**(code **)(*currentFunctionObj + 0x20))
                       (currentFunctionObj,(int)addBranchResult,expressionNode,scratchR6,scratchR7,staleR8Value,currentFunctionObj);
    if (queryResult == 0) {
      errorLine = *(char **)(yyvsp + -0x58);
      msgText = "void function cannot return a value";
    }
    else {
      currentFunctionType = *(int *)((int)parseContext + 0x28);
      (**(code **)(**(int **)(yyvsp + -0x24) + 0x38))
                (&typeTmp1VtableOrStr1Alloc,*(int **)(yyvsp + -0x24),expressionNode,scratchR6,scratchR7);
      foundMatch = false;
      if (((*(uint *)(currentFunctionType + 0x24) & 0x1fffe00) == ((uint)typeTmp1BitsOrPubQualifier & 0x1fffe00)) &&
         (*(unsigned char **)(currentFunctionType + 8) == typeTmp1StructureOrPubSize)) {
        foundMatch = true;
      }
      picBase2 = (unsigned char *)0xa7b8374c;
      typeTmp1VtableOrStr1Alloc = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
      yyvalNodeReg = yyvalNode;
      typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
      typeTmp7VtableReg = typeTmp7Vtable[0];
      if (foundMatch) break;
      errorLine = *(char **)(yyvsp + -0x58);
      msgText = "function return is not matching type:";
      currentFunctionObj = (int *)0x0;
    }
setScratchR62:
    scratchR6 = "return";
setScratchR72:
    scratchR7 = "";
    TParseContext__error((int)parseContext,errorLine,msgText,scratchR6,"",staleR8Value,currentFunctionObj,scratchR10);
    goto loopCallTParseContext_recover4;
  case 0xd1:
    if (*(int *)((int)parseContext + 0xc) != 1) {
      scratchR7 = "";
      scratchR6 = "discard";
      TParseContext__error
                ((int)parseContext,*(char **)(yyvsp + -0x2c)," supported in fragment shaders only ",
                 "discard","","",staleR9Value,scratchR10);
      TParseContext__recover(parseContext);
    }
    intermediateForBranch = *(void **)parseContext;
    branchOp = 0x62;
setYyvalNodeReg4:
    yyvalNodeReg = (unsigned char *)
             __ZN13TIntermediate9addBranchE9TOperatori(intermediateForBranch,branchOp,*(uint *)(yyvsp + -0x2c));
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    break;
  case 0xd2:
    yyvalNodeReg = *(unsigned char **)(yyvsp + 8);
    goto storeParseContext2;
  case 0xd3:
    scratchR6 = (char *)0x0;
    yyvalNodeReg = (unsigned char *)
             TIntermediate__growAggregate
                       (*(unsigned char **)parseContext,*(unsigned char **)(yyvsp + -0x24),
                        *(unsigned char **)(yyvsp + 8),0);
storeParseContext2:
    *(unsigned char **)((int)parseContext + 0x10) = yyvalNodeReg;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    break;
  case 0xd6:
    functionSymbol = *(int **)(yyvsp + 0x10);
    symbolTable2 = *(int **)((int)parseContext + 4);
    mangledName = (**(code **)(*functionSymbol + 8))(functionSymbol);
    levelsBegin = *symbolTable2;
    levelIdx = (symbolTable2[1] - levelsBegin >> 2) + -1;
    while( true ) {
      levelEntry = *(int *)(levelsBegin + levelIdx * 4);
      levelsBegin = 0;
      std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______find((unsigned char *)levelFindIter,levelEntry,mangledName);
      if (levelFindIter[0] != *(int *)(levelEntry + 4)) {
        levelsBegin = *(int *)(levelFindIter[0] + 0x18);
      }
      levelIdx = levelIdx + -1;
      if ((levelsBegin != 0) || (levelIdx < 0)) break;
      levelsBegin = *symbolTable2;
    }
    if (*(int *)(levelsBegin + 0x50) != 0) {
      nameString = functionSymbol[1];
      picBase = (unsigned char *)0xa7b8374c;
      stringData2 = *(int *)(nameString + 4);
      scratchR7 = "";
      *(unsigned char *)(stringData2 + *(int *)(stringData2 + -0xc)) = *stringTerminalPtr_a7b7ba88;
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp,"function already has a body",*(char **)(nameString + 4)
                 ,"",staleR8Value,stringData2,nameString);
      TParseContext__recover(parseContext);
    }
    *(undefined4 *)(levelsBegin + 0x50) = 1;
    mainNameCompare = __ZNKSbIcSt11char_traitsIcE14pool_allocatorIcEE7compareEPKc((void *)functionSymbol[1],"main");
    paramVectorPtr = functionSymbol + 3;
    if (mainNameCompare == 0) {
      paramCount = functionSymbol[5] - functionSymbol[4] >> 3;
      cr0 = (paramCount == 0) << 1;
      if (0 < paramCount) {
        nameString = functionSymbol[1];
        stringData2 = *(int *)(nameString + 4);
        scratchR7 = "";
        *(unsigned char *)(stringData2 + *(int *)(stringData2 + -0xc)) = *stringTerminalPtr_a7b7ba88;
        TParseContext__error
                  ((int)parseContext,*(char **)yyvsp,"function cannot take any parameter(s)",
                   *(char **)(nameString + 4),"",staleR8Value,stringData2,nameString);
        TParseContext__recover(parseContext);
      }
      bodyQuery = (**(code **)(functionSymbol[7] + 0x20))(functionSymbol + 7);
      if (bodyQuery != 0) {
        nameString = functionSymbol[1];
        picBase = (unsigned char *)0xa7b8374c;
        stringData2 = *(int *)(nameString + 4);
        scratchR7 = "";
        *(unsigned char *)(stringData2 + *(int *)(stringData2 + -0xc)) = *stringTerminalPtr_a7b7ba88;
        TParseContext__error
                  ((int)parseContext,*(char **)yyvsp,"function cannot return a value",
                   *(char **)(nameString + 4),"",staleR8Value,stringData2,nameString);
        TParseContext__recover(parseContext);
      }
    }
    symbolTable3 = *(unsigned char **)((int)parseContext + 4);
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    elementPtr = (undefined4 *)TPoolAllocator__allocate(poolAllocator,0x10);
    nodePool = (unsigned char *)GetGlobalPoolAllocator();
    *elementPtr = nodePool;
    elementPtr[1] = 0;
    treeNodeMem = (undefined4 *)TPoolAllocator__allocate(nodePool,0x1c);
    elementPtr[2] = 0;
    elementPtr[1] = treeNodeMem;
    *treeNodeMem = 0;
    *(undefined4 *)(elementPtr[1] + 4) = 0;
    *(undefined4 *)(elementPtr[1] + 8) = elementPtr[1];
    *(undefined4 *)(elementPtr[1] + 0xc) = elementPtr[1];
    treeFinish = *(undefined4 **)(symbolTable3 + 4);
    destroyAlloc67[0] = elementPtr;
    if (treeFinish == *(undefined4 **)(symbolTable3 + 8)) {
      std__vector_TSymbolTableLevel__std__allocator_TSymbolTableLevel______M_insert_aux
                (symbolTable3,treeFinish,destroyAlloc67);
    }
    else {
      levelsFinish2 = 0;
      if (treeFinish != (undefined4 *)0x0) {
        *treeFinish = elementPtr;
        levelsFinish2 = *(int *)(symbolTable3 + 4);
      }
      *(int *)(symbolTable3 + 4) = levelsFinish2 + 4;
    }
    *(int *)((int)parseContext + 0x28) = levelsBegin + 0x1c;
    *(undefined4 *)((int)parseContext + 0x2c) = 0;
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    newDeclNode = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x6c);
    picBase2 = (unsigned char *)0xa7b8374c;
    typeTmp1VtableOrStr1Alloc = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
    typeTmp1BitsOrPubQualifier = (unsigned char *)((uint)typeTmp1BitsOrPubQualifier & 0x1ff | 0x80800);
    typeTmp1ArraySizeOrStr1Data = (unsigned char *)0x0;
    typeTmp1StructureOrPubSize = (unsigned char *)0x0;
    typeTmp1Word0cOrPubMatrix = (unsigned char *)0x0;
    typeTmp1TypeNameOrStr2Alloc = (unsigned char *)0x0;
    typeTmp1Word14OrStr2Data = (unsigned char *)0x0;
    typeTmp1Word18OrPubLine = (unsigned char *)0x0;
    typeTmp1MaxArraySize = (unsigned char *)0x0;
    typeTmp1Word20OrPubType = (unsigned char *)0x0;
    *(undefined4 *)(newDeclNode + 4) = 0;
    *(undefined ***)newDeclNode = &PTR_getLine_a7b7d5d8;
    *(undefined4 *)(newDeclNode + 0xc) = 0;
    *(undefined4 *)(newDeclNode + 0x10) = 0;
    *(undefined4 *)(newDeclNode + 0x14) = 0;
    *(undefined4 *)(newDeclNode + 0x18) = 0;
    *(undefined4 *)(newDeclNode + 0x1c) = 0;
    *(undefined4 *)(newDeclNode + 0x20) = 0;
    *(undefined4 *)(newDeclNode + 0x24) = 0;
    *(undefined ***)(newDeclNode + 8) = &PTR___ZN5TTypeD1Ev_a7b7d640;
    *(undefined4 *)(newDeclNode + 0x28) = 0;
    symbolTypeBits = *(uint *)(newDeclNode + 0x2c);
    *(uint *)(newDeclNode + 0x2c) = symbolTypeBits & 0x1ffffff;
    *(uint *)(newDeclNode + 0x2c) = symbolTypeBits & 0x7ffff | 0x80000;
    *(uint *)(newDeclNode + 0x2c) = symbolTypeBits & 0x7ff | 0x80800;
    *(uint *)(newDeclNode + 0x2c) = symbolTypeBits & 0x3ff | 0x80800;
    aggregateVtable = PTR_vtable_a7b7c0d0;
    *(uint *)(newDeclNode + 0x2c) = symbolTypeBits & 0x1ff | 0x80800;
    *(undefined **)newDeclNode = aggregateVtable + 8;
    *(undefined4 *)(newDeclNode + 0x30) = 0;
    allocatorArg6 = GetGlobalPoolAllocator();
    *(undefined4 *)(newDeclNode + 0x40) = 0;
    *(undefined4 *)(newDeclNode + 0x38) = 0;
    *(undefined4 *)(newDeclNode + 0x3c) = 0;
    *(undefined4 *)(newDeclNode + 0x34) = allocatorArg6;
    allocatorArg7 = GetGlobalPoolAllocator();
    *(undefined4 *)(newDeclNode + 0x44) = allocatorArg7;
    emptyRep = DAT_a7b7ba84;
    *(undefined4 *)(newDeclNode + 0x50) = 0;
    *(undefined4 *)(newDeclNode + 0x48) = 0;
    refCountPtr4 = (int *)(emptyRep + 8);
    *(undefined4 *)(newDeclNode + 0x4c) = 0;
    do {
      if (reservation != '\0') {
        storeWordConditionalIndexedResult = storeWordConditionalIndexed(*refCountPtr4 + 1,0,refCountPtr4);
        *refCountPtr4 = storeWordConditionalIndexedResult;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    allocatorArg8 = GetGlobalPoolAllocator();
    *(int *)(newDeclNode + 0x58) = emptyRep + 0xc;
    *(undefined4 *)(newDeclNode + 0x68) = 0;
    *(undefined4 *)(newDeclNode + 0x5c) = 0;
    *(undefined4 *)(newDeclNode + 0x54) = allocatorArg8;
    picBaseConst = -0x5847c8b4;
    typeVtableAddr = &TType__vtable;
    for (paramIdx = 0; paramIdx < paramVectorPtr[2] - paramVectorPtr[1] >> 3; paramIdx = paramIdx + 1) {
      paramArray = functionSymbol[4];
      paramByteOffset = paramIdx * 8;
      if (*(int *)(paramArray + paramByteOffset) == 0) {
        ctorAlloc17[0] = GetGlobalPoolAllocator();
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                  (&typeTmp1VtableOrStr1Alloc,"",(unsigned char *)ctorAlloc17);
        scratchR7 = *(char **)yyvsp;
        addSymbolResult = (unsigned char *)
                  TIntermediate__addSymbol
                            (*(unsigned char **)parseContext,0,(unsigned char *)&typeTmp1VtableOrStr1Alloc,
                             *(unsigned char **)(paramArray + paramByteOffset + 4),(int)scratchR7);
        newDeclNode = (unsigned char *)
                  TIntermediate__growAggregate
                            (*(unsigned char **)parseContext,newDeclNode,addSymbolResult,*(uint *)yyvsp);
        refCountPtr = typeTmp1ArraySizeOrStr1Data + -4;
        destroyAlloc69[0] = typeTmp1VtableOrStr1Alloc;
        do {
          oldRefCount = *(uint *)refCountPtr;
          if (reservation != '\0') {
            newRefCount = storeWordConditionalIndexed(oldRefCount - 1,0,refCountPtr);
            *(uint *)refCountPtr = newRefCount;
            cr0 = 2;
          }
        } while (!(bool)(cr0 >> 1 & 1));
        if ((int)oldRefCount < 1) {
          __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                    ((unsigned char *)(typeTmp1ArraySizeOrStr1Data + -0xc),destroyAlloc69);
        }
      }
      else {
        poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
        newNode = (int *)TPoolAllocator__allocate(poolAllocator,0x40);
        variableVtable = PTR_vtable_a7b7c0b4 + 8;
        srcEntry = *(int *)(paramArray + paramByteOffset + 4);
        newNode[1] = *(int *)(paramArray + paramByteOffset);
        *newNode = (int)variableVtable;
        srcEntryWord0c = *(int *)(srcEntry + 0xc);
        r8Pass = *(int *)(srcEntry + 0x10);
        r7Pass = *(int *)(srcEntry + 0x14);
        r6Pass = *(int *)(srcEntry + 0x18);
        srcEntryWord1c = *(int *)(srcEntry + 0x1c);
        srcEntryWord20 = *(int *)(srcEntry + 0x20);
        srcEntryWord04 = *(int *)(srcEntry + 4);
        srcEntryWord08 = *(int *)(srcEntry + 8);
        newNode[3] = (int)(typeVtableAddr + 8);
        newNode[6] = srcEntryWord0c;
        newNode[7] = r8Pass;
        newNode[8] = r7Pass;
        newNode[9] = r6Pass;
        newNode[10] = srcEntryWord1c;
        newNode[0xb] = srcEntryWord20;
        newNode[5] = srcEntryWord08;
        newNode[4] = srcEntryWord04;
        oldNodeTypeBits = newNode[0xc];
        qualifierBits = *(uint *)(srcEntry + 0x24) & 0xfe000000;
        newNode[0xc] = qualifierBits | oldNodeTypeBits & 0x1ffffff;
        basicTypeBits = (*(uint *)(srcEntry + 0x24) >> 0x13 & 0x3f) << 0x13;
        newNode[0xc] = basicTypeBits | qualifierBits | oldNodeTypeBits & 0x7ffff;
        sizeFieldBits = *(uint *)(srcEntry + 0x24) & 0x7f800;
        newNode[0xc] = sizeFieldBits | basicTypeBits | qualifierBits | oldNodeTypeBits & 0x7ff;
        matrixBit = (*(uint *)(srcEntry + 0x24) >> 10 & 1) << 10;
        newNode[0xc] = matrixBit | sizeFieldBits | basicTypeBits | qualifierBits | oldNodeTypeBits & 0x3ff;
        newNode[0xc] = (*(uint *)(srcEntry + 0x24) >> 9 & 1) << 9 |
                     matrixBit | sizeFieldBits | basicTypeBits | qualifierBits | oldNodeTypeBits & 0x1ff;
        newNode[0xd] = 0;
        newNode[0xe] = 0;
        newNode[0xf] = 0;
        symbolTable2 = *(int **)((int)parseContext + 4);
        nextUniqueId2 = symbolTable2[3];
        symbolTable2[3] = nextUniqueId2 + 1;
        newNode[2] = nextUniqueId2 + 1;
        lastLevel = *(undefined4 *)(*symbolTable2 + ((symbolTable2[1] - *symbolTable2 & 0xfffffffcU) - 4));
        typeTmp1ArraySizeOrStr1Data = (unsigned char *)0x0;
        keyString = (unsigned char *)(**(code **)(*newNode + 8))(newNode,srcEntryWord20,srcEntryWord1c,r6Pass,r7Pass,r8Pass,symbolTable2);
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&nodeKeyStrAlloc,keyString);
        nodeValue = newNode;
        std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&typeTmp1TypeNameOrStr2Alloc,lastLevel,&nodeKeyStrAlloc);
        typeTmp1VtableOrStr1Alloc = typeTmp1TypeNameOrStr2Alloc;
        refCountPtr3 = (int *)(nodeKeyStrData + -4);
        typeTmp1ArraySizeOrStr1Data = typeTmp1Word14OrStr2Data;
        destroyAlloc68[0] = nodeKeyStrAlloc;
        do {
          oldRefCount5 = *refCountPtr3;
          if (reservation != '\0') {
            newRefCount5 = storeWordConditionalIndexed(oldRefCount5 + -1,0,refCountPtr3);
            *refCountPtr3 = newRefCount5;
            cr0 = 2;
          }
        } while (!(bool)(cr0 >> 1 & 1));
        if (oldRefCount5 < 1) {
          __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                    ((unsigned char *)(nodeKeyStrData + -0xc),destroyAlloc68);
        }
        if (typeTmp1ArraySizeOrStr1Data == (unsigned char *)0x0) {
          newNodeWord4 = newNode[1];
          stringData3 = *(int *)(newNodeWord4 + 4);
          *(undefined1 *)(stringData3 + *(int *)(stringData3 + -0xc)) = **(undefined1 **)(picBaseConst + -0x7cc4);
          TParseContext__error
                    ((int)parseContext,*(char **)yyvsp,"redefinition",*(char **)(newNodeWord4 + 4),"",
                     picBaseConst,stringData3,newNodeWord4);
          TParseContext__recover(parseContext);
          (**(code **)(*newNode + 4))(newNode);
        }
        *(undefined4 *)(paramArray + paramByteOffset) = 0;
        scratchR7 = *(char **)yyvsp;
        addSymbolResult = (unsigned char *)
                  TIntermediate__addSymbol
                            (*(unsigned char **)parseContext,newNode[2],(unsigned char *)newNode[1],
                             (unsigned char *)(newNode + 3),(int)scratchR7);
        newDeclNode = (unsigned char *)
                  TIntermediate__growAggregate
                            (*(unsigned char **)parseContext,newDeclNode,addSymbolResult,*(uint *)yyvsp);
      }
    }
    scratchR6 = *(char **)yyvsp;
    TIntermediate__setAggregateOperator(*(unsigned char **)parseContext,newDeclNode,4,scratchR6);
    *(unsigned char **)(yyvsp + 8) = newDeclNode;
    *(undefined4 *)((int)parseContext + 0x20) = 0;
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
    break;
  case 0xd7:
    picBase = (unsigned char *)0xa7b8374c;
    queryResult = (**(code **)(**(int **)((int)parseContext + 0x28) + 0x20))(*(int **)((int)parseContext + 0x28));
    terminalCharPtr = stringTerminalPtr_a7b7ba88;
    if ((queryResult != 0) && (picBase = (unsigned char *)0xa7b8374c, *(int *)((int)parseContext + 0x2c) == 0)
       ) {
      nameString2 = *(int *)(*(uint *)(yyvsp + -0x48) + 4);
      scratchR7 = "";
      *(unsigned char *)(*(int *)(nameString2 + 4) + *(int *)(*(int *)(nameString2 + 4) + -0xc)) =
           *stringTerminalPtr_a7b7ba88;
      TParseContext__error
                ((int)parseContext,*(char **)(yyvsp + -0x58),"function does not return a value",
                 *(char **)(nameString2 + 4),"",0xa7b8374c,terminalCharPtr,nameString2);
      TParseContext__recover(parseContext);
    }
    symbolTable = *(int **)((int)parseContext + 4);
    levelsEnd = symbolTable[1];
    poppedLevel = *(void **)(*symbolTable + ((levelsEnd - *symbolTable & 0xfffffffcU) - 4));
    if (poppedLevel != (void *)0x0) {
      ((int (*)())__ZN17TSymbolTableLevelD1Ev)(poppedLevel);
      levelsEnd = symbolTable[1];
    }
    symbolTable[1] = levelsEnd + -4;
    yyvalNode = (unsigned char *)
                TIntermediate__growAggregate
                          (*(unsigned char **)parseContext,*(unsigned char **)(yyvsp + -0x50),
                           *(unsigned char **)(yyvsp + 8),0);
    scratchR6 = *(char **)(yyvsp + -0x58);
    TIntermediate__setAggregateOperator
              (*(unsigned char **)parseContext,(unsigned char *)yyvalNode,3,scratchR6);
    mangledNameStr = (**(code **)(**(int **)(yyvsp + -0x48) + 8))(*(int **)(yyvsp + -0x48));
    *(undefined1 *)(*(int *)(mangledNameStr + 4) + *(int *)(*(int *)(mangledNameStr + 4) + -0xc)) =
         **(undefined1 **)(picBase + -0x7cc4);
    typeNameData = *(char **)(mangledNameStr + 4);
    ctorAlloc18[0] = GetGlobalPoolAllocator();
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
              (&typeTmp1VtableOrStr1Alloc,typeNameData,(unsigned char *)ctorAlloc18);
    aggregateNode = (int *)(**(code **)(*(uint *)yyvalNode + 0x1c))(yyvalNode);
    (**(code **)(*aggregateNode + 0x68))(aggregateNode,&typeTmp1VtableOrStr1Alloc);
    refCountPtr = typeTmp1ArraySizeOrStr1Data + -4;
    destroyAlloc70[0] = typeTmp1VtableOrStr1Alloc;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    if ((int)oldRefCount2 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(typeTmp1ArraySizeOrStr1Data + -0xc),destroyAlloc70);
    }
    functionPrototypeFunction = *(uint *)(yyvsp + -0x48);
    aggregateNode = (int *)(**(code **)(*(uint *)yyvalNode + 0x1c))(yyvalNode);
    (**(code **)(*aggregateNode + 0x34))(aggregateNode,functionPrototypeFunction + 0x1c);
    aggregateNode3 = (**(code **)(*(uint *)yyvalNode + 0x1c))(yyvalNode);
    *(undefined4 *)(aggregateNode3 + 0x60) = *(undefined4 *)((int)parseContext + 0x40);
    aggregateNode3 = (**(code **)(*(uint *)yyvalNode + 0x1c))(yyvalNode);
    *(undefined4 *)(aggregateNode3 + 100) = *(undefined4 *)((int)parseContext + 0x44);
    aggregateNode2 = (unsigned char *)(**(code **)(*(uint *)yyvalNode + 0x1c))(yyvalNode);
    TIntermAggregate__addToPragmaTable(aggregateNode2,(unsigned char *)((int)parseContext + 0x48));
    yyvalNodeReg = yyvalNode;
    typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
    typeTmp7VtableReg = typeTmp7Vtable[0];
  }
switchD_97ba39c8_caseD_0:
  typeTmp7Vtable[0] = typeTmp7VtableReg;
  typeTmp3VtableOrPub3Array = typeTmp3VtableReg;
  yyvalNode = yyvalNodeReg;
  scratchR5 = (char *)0x2c;
  yyssp = yyssp + yylen * -2;
  yyvsp = yyvsp + yylen * -0x2c + 0x2c;
  _memcpy(yyvsp,&yyval,0x2c);
  scratchR10 = *(short *)(" !\"#$%&\'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^" +
                      yyruleByteOffset + 0x40) * 2;
  scratchR9 = &_yypgoto + scratchR10;
  yytableIndex = (int)*(short *)(&DAT_97c36138 + scratchR10) + (int)*(short *)yyssp;
  scratchR4 = r4Out17;
  if ((yytableIndex < 0x4f0) &&
     (scratchR9 = (undefined *)(yytableIndex * 2),
     (int)*(short *)(&_yycheck + (int)scratchR9) == (int)*(short *)yyssp)) {
    yystate = (int)*(short *)(&_yytable + (int)scratchR9);
  }
  else {
    yystate = (int)*(short *)(&DAT_97c35e08 + scratchR10);
  }
  goto LAB_97ba3784;
loopSetLevelEntry:
  levelEntry = *(int *)(levelsBegin + levelIdx * 4);
  foundSymbol = 0;
  errorText = functionNameText;
  std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______find((unsigned char *)levelFindIter,levelEntry,functionNameText);
  if (levelFindIter[0] != *(int *)(levelEntry + 4)) {
    foundSymbol = *(int *)(levelFindIter[0] + 0x18);
  }
  levelIdx = levelIdx + -1;
  staleR4Value = r4Out13;
  if (foundSymbol == 0) {
    if (-1 < levelIdx) goto setLevelsBegin;
  }
  else {
    declaredFunction = *(uint *)(yyvsp + -0x1c);
    returnTypePtr = foundSymbol + 0x1c;
    staleR8Value = (unsigned char *)0x0;
    if (((*(uint *)(foundSymbol + 0x40) & 0x1fffe00) == (*(uint *)(declaredFunction + 0x40) & 0x1fffe00)) &&
       (*(int *)(foundSymbol + 0x24) == *(int *)(declaredFunction + 0x24))) {
      staleR8Value = (unsigned char *)0x1;
    }
    if (staleR8Value == (unsigned char *)0x0) {
      scratchR6 = (char *)TType__getBasicString(*(uint *)(declaredFunction + 0x40) >> 0x13 & 0x3f);
      errorText = "overloaded functions must have the same return type";
      scratchR7 = "";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp,
                 "overloaded functions must have the same return type",scratchR6,"",staleR8Value,returnTypePtr,
                 declaredFunction);
      TParseContext__recover(parseContext);
      staleR4Value = r4Out14;
    }
    for (loopIndex4 = 0; loopIndex4 < *(int *)(foundSymbol + 0x14) - *(int *)(foundSymbol + 0x10) >> 3;
        loopIndex4 = loopIndex4 + 1) {
      fieldByteOffset = loopIndex4 * 8;
      paramType = *(int **)(*(int *)(foundSymbol + 0x10) + fieldByteOffset + 4);
      paramQualifier1 = *paramType;
      paramQualifier1 = (**(code **)(paramQualifier1 + 0x24))(paramType,staleR4Value,errorText,scratchR6,scratchR7,staleR8Value,paramQualifier1);
      paramType = *(int **)(*(int *)(*(uint *)(yyvsp + -0x1c) + 0x10) + fieldByteOffset + 4);
      paramQualifier2 = *paramType;
      paramQualifier2 = (**(code **)(paramQualifier2 + 0x24))(paramType,r4In9,errorText,scratchR6,scratchR7,staleR8Value,paramQualifier2);
      staleR4Value = r4Out15;
      if (paramQualifier1 != paramQualifier2) {
        fieldByteOffset = *(int *)(*(int *)(*(uint *)(yyvsp + -0x1c) + 0x10) + fieldByteOffset + 4);
        scratchR6 = (char *)getQualifierString(*(uint *)(fieldByteOffset + 0x24) >> 0x19);
        errorText = "overloaded functions must have the same parameter qualifiers";
        scratchR7 = "";
        TParseContext__error
                  ((int)parseContext,*(char **)yyvsp,
                   "overloaded functions must have the same parameter qualifiers",scratchR6,"",staleR8Value
                   ,fieldByteOffset,declaredFunction);
        TParseContext__recover(parseContext);
        staleR4Value = r4Out16;
      }
    }
  }
  goto setFunctionHeader;
setLevelsBegin:
  levelsBegin = *symbolTable;
  goto loopSetLevelEntry;
setFunctionHeader:
  functionHeader = *(unsigned char **)(yyvsp + -0x1c);
  symbolTable = *(int **)((int)parseContext + 4);
  yyval = *(uint *)yyvsp;
  nextUniqueId = symbolTable[3];
  symbolTable[3] = (int)(nextUniqueId + 1U);
  *(unsigned char **)(functionHeader + 8) = (unsigned char *)(nextUniqueId + 1U);
  lastLevel2 = *(undefined4 *)(*symbolTable + ((symbolTable[1] - *symbolTable & 0xfffffffcU) - 4));
  typeTmp1ArraySizeOrStr1Data = (unsigned char *)0x0;
  yyvalTypeOrFunction = functionHeader;
  keyString = (unsigned char *)
            (**(code **)(*(unsigned char **)functionHeader + 8))
                      (functionHeader,staleR4Value,errorText,scratchR6,scratchR7,staleR8Value,symbolTable);
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&symbolKeyStrAlloc,keyString);
  symbolValue = functionHeader;
  std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&typeTmp1TypeNameOrStr2Alloc,lastLevel2,&symbolKeyStrAlloc);
  destroyRep = (unsigned char *)(symbolKeyStrData + -0xc);
  typeTmp1VtableOrStr1Alloc = typeTmp1TypeNameOrStr2Alloc;
  refCountPtr2 = (int *)(symbolKeyStrData + -4);
  typeTmp1ArraySizeOrStr1Data = typeTmp1Word14OrStr2Data;
  destroyAlloc57[0] = symbolKeyStrAlloc;
  do {
    oldRefCount4 = *refCountPtr2;
    if (reservation != '\0') {
      newRefCount4 = storeWordConditionalIndexed(oldRefCount4 + -1,0,refCountPtr2);
      *refCountPtr2 = newRefCount4;
      cr0 = 2;
    }
  } while (!(bool)(cr0 >> 1 & 1));
  stillShared = 0 < oldRefCount4;
  destroyAllocArg = destroyAlloc57;
  goto loopSetYyvalNodeReg2;
yynCase60:
  scratchR6 = (char *)slotArg;
  yyvalNodeReg = (unsigned char *)0x0;
  typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
  typeTmp7VtableReg = typeTmp7Vtable[0];
  goto switchD_97ba39c8_caseD_0;
loopCheckTypeTmp1StructureCopy2:
  if ((uint)((int)(*(uint *)(typeTmp1StructureCopy2 + 8) - *(uint *)(typeTmp1StructureCopy2 + 4)) >> 3) <= loopIndex)
  goto setScratchR10;
  fieldType = *(int **)(*(uint *)(typeTmp1StructureCopy2 + 4) + loopIndex * 8);
  fieldNameStr2 = *fieldType;
  fieldNameStr2 = (**(code **)(fieldNameStr2 + 0x1c))(fieldType,staleR4Value,scratchR5,scratchR6,scratchR7,staleR8Value,fieldNameStr2);
  declaredNameLen2 = *(uint *)(*(int *)(fieldNameStr2 + 4) + -0xc);
  declaredNameLen = declaredNameLen2;
  nameLenB = *(uint *)(*(int *)(*(uint *)(yyvsp + 4) + 4) + -0xc);
  existingNameLen = nameLenB;
  shorterLenPtr = &existingNameLen;
  if (declaredNameLen2 <= nameLenB) {
    shorterLenPtr = &declaredNameLen;
  }
  scratchR5 = (char *)*shorterLenPtr;
  fieldNameStr2 = _memcmp(*(undefined4 *)(fieldNameStr2 + 4),*(undefined4 *)(*(uint *)(yyvsp + 4) + 4),scratchR5);
  cr0 = (fieldNameStr2 == 0) << 1;
  if (fieldNameStr2 == 0) {
    fieldNameStr2 = declaredNameLen2 - nameLenB;
  }
  if (fieldNameStr2 != 0) {
    loopIndex = loopIndex + 1;
    staleR4Value = r4Out8;
    goto loopCheckTypeTmp1StructureCopy2;
  }
  (**(code **)(**(int **)(yyvsp + -0x50) + 0x38))(&typeTmp1VtableOrStr1Alloc,*(int **)(yyvsp + -0x50));
  typeVtable3 = picBase2 + -0x610c;
  picBaseValue = picBase2;
  typeTmp1VtableOrStr1Alloc = typeVtable3;
  if ((uint)typeTmp1BitsOrPubQualifier >> 0x19 == 2) {
    scratchR5 = *(char **)(yyvsp + -0x50);
    scratchR6 = *(char **)(yyvsp + -0x2c);
    yyvalNode = (unsigned char *)
                TParseContext__addConstStruct
                          (parseContext,*(unsigned char **)(yyvsp + 4),(unsigned char *)scratchR5,(int)scratchR6,
                           scratchR7,picBase2);
    if (yyvalNode == (unsigned char *)0x0) goto loopCallTParseContext_recover2;
    typeVtablePtr = *(undefined ***)(typeTmp1StructureCopy2 + 4);
    (**(code **)(*(int *)yyvalNode + 0x34))
              (yyvalNode,typeVtablePtr[loopIndex * 2],scratchR5,scratchR6,scratchR7,picBaseValue,typeVtablePtr);
    newTypeMem = (unsigned char *)(**(code **)(*(uint *)yyvalNode + 0x3c))(yyvalNode);
    methodArg = (undefined *)0x2;
    nodeMethod = *(code **)(*(unsigned char **)newTypeMem + 0x28);
  }
  else {
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    constArray = (unsigned char *)TPoolAllocator__allocate(poolAllocator,4);
    *(uint *)constArray = loopIndex;
    typeTmp2ArraySizeOrPubUserDef = (unsigned char *)0x0;
    typeTmp2StructureOrPubLine = (unsigned char *)0x0;
    typeTmp2BitsOrPub3Qualifier = (unsigned char *)((uint)typeTmp2BitsOrPub3Qualifier & 0x9ff | 0x4100800);
    typeTmp2Word0cOrPubMatrix2 = (unsigned char *)0x0;
    typeTmp2TypeNameOrPubArray2 = (unsigned char *)0x0;
    typeTmp2Word14OrPubUserDef2 = (unsigned char *)0x0;
    typeTmp2Word18OrPubLine2 = (unsigned char *)0x0;
    typeTmp2MaxArraySize = (unsigned char *)0x0;
    typeTmp2Word20OrPub3Type = (unsigned char *)0x0;
    typeTmp2VtableOrPubArray = typeVtable3;
    scratchR6 = (char *)TIntermediate__addConstantUnion
                                (*(unsigned char **)parseContext,constArray,(unsigned char *)&typeTmp2VtableOrPubArray,
                                 *(uint *)yyvsp);
    scratchR5 = *(char **)(yyvsp + -0x50);
    scratchR7 = *(char **)(yyvsp + -0x2c);
    typeTmp2VtableOrPubArray = typeVtable3;
    newTypeMem = (unsigned char *)
              TIntermediate__addIndex(*(unsigned char **)parseContext,0x2f,scratchR5,scratchR6,scratchR7);
    typeVtablePtr = *(undefined ***)(typeTmp1StructureCopy2 + 4);
    methodArg = typeVtablePtr[loopIndex * 2];
    nodeMethod = *(code **)(*(unsigned char **)newTypeMem + 0x34);
    yyvalNode = newTypeMem;
  }
LAB_97baae6c:
  (*nodeMethod)(newTypeMem,methodArg,scratchR5,scratchR6,scratchR7,picBaseValue,typeVtablePtr);
  yyvalNodeReg = yyvalNode;
  typeTmp3VtableReg = typeTmp3VtableOrPub3Array;
  typeTmp7VtableReg = typeTmp7Vtable[0];
  goto switchD_97ba39c8_caseD_0;
setScratchR10:
  scratchR10 = *(uint *)(yyvsp + 4);
  staleR9Value = *(unsigned char **)(scratchR10 + 4);
  msgText2 = " no such field in structure";
setPicBase:
  picBase = (unsigned char *)0xa7b8374c;
  staleR9Value[*(uint *)(staleR9Value + -0xc)] = *stringTerminalPtr_a7b7ba88;
  scratchR6 = *(char **)(scratchR10 + 4);
  errorLine2 = *(char **)(yyvsp + -0x2c);
setScratchR73:
  scratchR7 = "";
  TParseContext__error((int)parseContext,errorLine2,msgText2,scratchR6,"",staleR8Value,staleR9Value,scratchR10);
  goto loopCallTParseContext_recover2;
}

/* yylex @ 0x97bac120 (4128 bytes) */
int yylex(yYSTYPE, parseContext)
  unsigned char * yYSTYPE;
  void *parseContext;
{
  void *infoSinkBase;
  int nextBufferAction;
  int commentResult;
  uint yyAct;
  int nxtIndex;
  byte *matchStart;
  char *tokenLine;
  unsigned char * identMem;
  unsigned char * identString;
  long intValue;
  unsigned char * poolAllocator;
  void *stringMem;
  undefined4 token;
  int stateOffset;
  uint yyC;
  undefined *yyDefPtr;
  byte *yyBp;
  int yyCurrentState;
  void *tokenString;
  byte *yyCp;
  double floatValue;
  undefined4 identCtorAlloc [4];
  undefined4 stringCtorAlloc [6];
  
  if (_yy_init != 0) {
    _yy_init = 0;
    if (_yy_start == 0) {
      _yy_start = 1;
    }
    if (_yyin == (unsigned char *)0x0) {
      _yyin = (unsigned char *)PTR_DAT_a7b7c0bc;
    }
    if (_yyout == (undefined *)0x0) {
      _yyout = PTR_DAT_a7b7c0bc + 0x58;
    }
    if (_yy_current_buffer == (unsigned char *)0x0) {
      _yy_current_buffer = (unsigned char *)((int (*)())yy_create_buffer)(_yyin,0x4000);
    }
    ((int (*)())yy_load_buffer_state)();
  }
yyActCase1:
  *_yy_c_buf_p = _yy_hold_char;
  yyBp = _yy_c_buf_p;
  yyCurrentState = _yy_start;
loopSetYyDefPtr:
  yyDefPtr = &_yy_def;
  stateOffset = yyCurrentState << 1;
  do {
    yyC = (uint)(byte)(DAT_97c37983)[(uint)*_yy_c_buf_p * 4];
    if (*(short *)(&_yy_accept + stateOffset) != 0) {
      _yy_last_accepting_cpos = _yy_c_buf_p;
      _yy_last_accepting_state = yyCurrentState;
    }
    while (nxtIndex = ((int)*(short *)(&_yy_base + stateOffset) + yyC) * 2,
          *(short *)(&_yy_chk + nxtIndex) != yyCurrentState) {
      yyCurrentState = (int)*(short *)(&_yy_def + stateOffset);
      stateOffset = yyCurrentState << 1;
      if (0x199 < yyCurrentState) {
        yyC = (uint)(byte)(DAT_97c37d83)[yyC * 4];
      }
    }
    yyCurrentState = (int)*(short *)(&_yy_nxt + nxtIndex);
    _yy_c_buf_p = _yy_c_buf_p + 1;
    stateOffset = yyCurrentState * 2;
  } while (*(short *)(&_yy_base + stateOffset) != 0x260);
loopSetYyAct:
  yyAct = (uint)*(short *)(&_yy_accept + stateOffset);
  yyCp = _yy_c_buf_p;
  if (yyAct == 0) {
    yyAct = (uint)*(short *)(&_yy_accept + _yy_last_accepting_state * 2);
    yyCp = _yy_last_accepting_cpos;
  }
  _yyleng = (int)yyCp - (int)yyBp;
  _yy_hold_char = *yyCp;
  _yytext = yyBp;
  *yyCp = 0;
  _yy_c_buf_p = yyCp;
loopSetTokenLine:
  tokenLine = _yylineno;
  matchStart = _yytext;
  if (0x93 < yyAct) {
    yy_fatal_error("fatal flex scanner internal error--no action found");
    goto yyActCase1;
  }
  switch(yyAct) {
  case 0:
    *yyCp = _yy_hold_char;
    _yytext = yyBp;
    stateOffset = _yy_last_accepting_state;
    _yy_c_buf_p = _yy_last_accepting_cpos;
loopSetStateOffset:
    stateOffset = stateOffset << 1;
    yyBp = _yytext;
    goto loopSetYyAct;
  default:
    goto yyActCase1;
  case 2:
    token = 0x101;
    *(char **)yYSTYPE = _yylineno;
    break;
  case 3:
    token = 0x102;
    *(char **)yYSTYPE = _yylineno;
    break;
  case 4:
    token = 0x11d;
    *(char **)yYSTYPE = _yylineno;
    break;
  case 5:
    token = 0x11e;
    *(char **)yYSTYPE = _yylineno;
    break;
  case 6:
    token = 0x106;
    *(char **)yYSTYPE = _yylineno;
    break;
  case 7:
    token = 0x107;
    *(char **)yYSTYPE = _yylineno;
    break;
  case 8:
    token = 0x108;
    *(char **)yYSTYPE = _yylineno;
    break;
  case 9:
    token = 0x10a;
    *(char **)yYSTYPE = _yylineno;
    break;
  case 10:
    token = 0x121;
    *(char **)yYSTYPE = _yylineno;
    break;
  case 0xb:
    token = 0x10b;
    *(char **)yYSTYPE = _yylineno;
    break;
  case 0xc:
    token = 0x109;
    *(char **)yYSTYPE = _yylineno;
    break;
  case 0xd:
    token = 0x11a;
    *(char **)yYSTYPE = _yylineno;
    break;
  case 0xe:
    token = 0x11b;
    *(char **)yYSTYPE = _yylineno;
    break;
  case 0xf:
    token = 0x11c;
    *(char **)yYSTYPE = _yylineno;
    break;
  case 0x10:
    token = 0x104;
    *(char **)yYSTYPE = _yylineno;
    *(undefined4 *)((int)parseContext + 0x1c) = 1;
    break;
  case 0x11:
    token = 0x105;
    *(char **)yYSTYPE = _yylineno;
    *(undefined4 *)((int)parseContext + 0x1c) = 1;
    break;
  case 0x12:
    token = 0x120;
    *(char **)yYSTYPE = _yylineno;
    *(undefined4 *)((int)parseContext + 0x1c) = 1;
    break;
  case 0x13:
    token = 0x103;
    *(char **)yYSTYPE = _yylineno;
    *(undefined4 *)((int)parseContext + 0x1c) = 1;
    break;
  case 0x14:
    token = 0x12e;
    *(undefined4 *)(yYSTYPE + 4) = 1;
    *(char **)yYSTYPE = tokenLine;
    break;
  case 0x15:
    token = 0x12e;
    *(undefined4 *)(yYSTYPE + 4) = 0;
    *(char **)yYSTYPE = tokenLine;
    break;
  case 0x16:
    token = 0x10c;
    *(char **)yYSTYPE = _yylineno;
    break;
  case 0x17:
    token = 0x10d;
    *(char **)yYSTYPE = _yylineno;
    break;
  case 0x18:
    token = 0x117;
    *(char **)yYSTYPE = _yylineno;
    *(undefined4 *)((int)parseContext + 0x1c) = 1;
    break;
  case 0x19:
    token = 0x118;
    *(char **)yYSTYPE = _yylineno;
    *(undefined4 *)((int)parseContext + 0x1c) = 1;
    break;
  case 0x1a:
    token = 0x119;
    *(char **)yYSTYPE = _yylineno;
    *(undefined4 *)((int)parseContext + 0x1c) = 1;
    break;
  case 0x1b:
    token = 0x114;
    *(char **)yYSTYPE = _yylineno;
    *(undefined4 *)((int)parseContext + 0x1c) = 1;
    break;
  case 0x1c:
    token = 0x115;
    *(char **)yYSTYPE = _yylineno;
    *(undefined4 *)((int)parseContext + 0x1c) = 1;
    break;
  case 0x1d:
    token = 0x116;
    *(char **)yYSTYPE = _yylineno;
    *(undefined4 *)((int)parseContext + 0x1c) = 1;
    break;
  case 0x1e:
    token = 0x111;
    *(char **)yYSTYPE = _yylineno;
    *(undefined4 *)((int)parseContext + 0x1c) = 1;
    break;
  case 0x1f:
    token = 0x112;
    *(char **)yYSTYPE = _yylineno;
    *(undefined4 *)((int)parseContext + 0x1c) = 1;
    break;
  case 0x20:
    token = 0x113;
    *(char **)yYSTYPE = _yylineno;
    *(undefined4 *)((int)parseContext + 0x1c) = 1;
    break;
  case 0x21:
    token = 0x10e;
    *(char **)yYSTYPE = _yylineno;
    *(undefined4 *)((int)parseContext + 0x1c) = 1;
    break;
  case 0x22:
    token = 0x10f;
    *(char **)yYSTYPE = _yylineno;
    *(undefined4 *)((int)parseContext + 0x1c) = 1;
    break;
  case 0x23:
    token = 0x110;
    *(char **)yYSTYPE = _yylineno;
    *(undefined4 *)((int)parseContext + 0x1c) = 1;
    break;
  case 0x24:
    token = 0x122;
    *(char **)yYSTYPE = _yylineno;
    *(undefined4 *)((int)parseContext + 0x1c) = 1;
    break;
  case 0x25:
    token = 0x123;
    *(char **)yYSTYPE = _yylineno;
    *(undefined4 *)((int)parseContext + 0x1c) = 1;
    break;
  case 0x26:
    token = 0x124;
    *(char **)yYSTYPE = _yylineno;
    *(undefined4 *)((int)parseContext + 0x1c) = 1;
    break;
  case 0x27:
    token = 0x125;
    *(char **)yYSTYPE = _yylineno;
    *(undefined4 *)((int)parseContext + 0x1c) = 1;
    break;
  case 0x28:
    token = 0x126;
    *(char **)yYSTYPE = _yylineno;
    *(undefined4 *)((int)parseContext + 0x1c) = 1;
    break;
  case 0x29:
    token = 0x127;
    *(char **)yYSTYPE = _yylineno;
    *(undefined4 *)((int)parseContext + 0x1c) = 1;
    break;
  case 0x2a:
    token = 0x128;
    *(char **)yYSTYPE = _yylineno;
    *(undefined4 *)((int)parseContext + 0x1c) = 1;
    break;
  case 0x2b:
    token = 0x129;
    *(char **)yYSTYPE = _yylineno;
    *(undefined4 *)((int)parseContext + 0x1c) = 1;
    break;
  case 0x2c:
    token = 0x11f;
    *(char **)yYSTYPE = _yylineno;
    break;
  case 0x2d:
    PaReservedWord();
    token = 0;
    break;
  case 0x2e:
    PaReservedWord();
    token = 0;
    break;
  case 0x2f:
    PaReservedWord();
    token = 0;
    break;
  case 0x30:
    PaReservedWord();
    token = 0;
    break;
  case 0x31:
    PaReservedWord();
    token = 0;
    break;
  case 0x32:
    PaReservedWord();
    token = 0;
    break;
  case 0x33:
    PaReservedWord();
    token = 0;
    break;
  case 0x34:
    PaReservedWord();
    token = 0;
    break;
  case 0x35:
    PaReservedWord();
    token = 0;
    break;
  case 0x36:
    PaReservedWord();
    token = 0;
    break;
  case 0x37:
    PaReservedWord();
    token = 0;
    break;
  case 0x38:
    PaReservedWord();
    token = 0;
    break;
  case 0x39:
    PaReservedWord();
    token = 0;
    break;
  case 0x3a:
    PaReservedWord();
    token = 0;
    break;
  case 0x3b:
    PaReservedWord();
    token = 0;
    break;
  case 0x3c:
    PaReservedWord();
    token = 0;
    break;
  case 0x3d:
    PaReservedWord();
    token = 0;
    break;
  case 0x3e:
    PaReservedWord();
    token = 0;
    break;
  case 0x3f:
    PaReservedWord();
    token = 0;
    break;
  case 0x40:
    PaReservedWord();
    token = 0;
    break;
  case 0x41:
    PaReservedWord();
    token = 0;
    break;
  case 0x42:
    PaReservedWord();
    token = 0;
    break;
  case 0x43:
    PaReservedWord();
    token = 0;
    break;
  case 0x44:
    PaReservedWord();
    token = 0;
    break;
  case 0x45:
    PaReservedWord();
    token = 0;
    break;
  case 0x46:
    PaReservedWord();
    token = 0;
    break;
  case 0x47:
    PaReservedWord();
    token = 0;
    break;
  case 0x48:
    PaReservedWord();
    token = 0;
    break;
  case 0x49:
    PaReservedWord();
    token = 0;
    break;
  case 0x4a:
    PaReservedWord();
    token = 0;
    break;
  case 0x4b:
    PaReservedWord();
    token = 0;
    break;
  case 0x4c:
    PaReservedWord();
    token = 0;
    break;
  case 0x4d:
    PaReservedWord();
    token = 0;
    break;
  case 0x4e:
    PaReservedWord();
    token = 0;
    break;
  case 0x4f:
    PaReservedWord();
    token = 0;
    break;
  case 0x50:
    PaReservedWord();
    token = 0;
    break;
  case 0x51:
    PaReservedWord();
    token = 0;
    break;
  case 0x52:
    PaReservedWord();
    token = 0;
    break;
  case 0x53:
    PaReservedWord();
    token = 0;
    break;
  case 0x54:
    PaReservedWord();
    token = 0;
    break;
  case 0x55:
    PaReservedWord();
    token = 0;
    break;
  case 0x56:
    *(char **)yYSTYPE = _yylineno;
    yyBp = _yytext;
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    identMem = (unsigned char *)TPoolAllocator__allocate(poolAllocator,8);
    identString = (unsigned char *)0x0;
    if (identMem != (unsigned char *)0x0) {
      identCtorAlloc[0] = GetGlobalPoolAllocator();
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                (identMem,(char *)yyBp,(unsigned char *)identCtorAlloc);
      identString = identMem;
    }
    *(unsigned char **)(yYSTYPE + 4) = identString;
    token = PaIdentOrType(identString,parseContext,(unsigned char **)(yYSTYPE + 8));
    break;
  case 0x57:
    *(char **)yYSTYPE = _yylineno;
    intValue = _strtol((char *)_yytext,(char **)0x0,0);
    *(long *)(yYSTYPE + 4) = intValue;
    token = 0x12d;
    break;
  case 0x58:
    *(char **)yYSTYPE = _yylineno;
    intValue = _strtol((char *)_yytext,(char **)0x0,0);
    *(long *)(yYSTYPE + 4) = intValue;
    token = 0x12d;
    break;
  case 0x59:
    *(char **)yYSTYPE = _yylineno;
    TParseContext__error
              ((int)parseContext,_yylineno,"Invalid Octal number.",(char *)_yytext,"","",yyAct * 4,
               yyDefPtr);
    TParseContext__recover(parseContext);
    token = 0;
    break;
  case 0x5a:
    *(char **)yYSTYPE = _yylineno;
    intValue = _strtol((char *)_yytext,(char **)0x0,0);
    *(long *)(yYSTYPE + 4) = intValue;
    token = 0x12d;
    break;
  case 0x5b:
    *(char **)yYSTYPE = _yylineno;
    floatValue = (double)((double (*)())_glp_strtod)(_yytext,0);
    token = 300;
    *(float *)(yYSTYPE + 4) = (float)floatValue;
    break;
  case 0x5c:
    *(char **)yYSTYPE = _yylineno;
    floatValue = (double)((double (*)())_glp_strtod)(_yytext,0);
    token = 300;
    *(float *)(yYSTYPE + 4) = (float)floatValue;
    break;
  case 0x5d:
    *(char **)yYSTYPE = _yylineno;
    floatValue = (double)((double (*)())_glp_strtod)(_yytext,0);
    token = 300;
    *(float *)(yYSTYPE + 4) = (float)floatValue;
    break;
  case 0x5e:
    commentResult = PaParseComment((int *)yYSTYPE,parseContext);
    token = 0;
    if (commentResult != 0) goto yyActCase1;
    break;
  case 0x5f:
    token = 0x13d;
    *(char **)yYSTYPE = _yylineno;
    break;
  case 0x60:
    token = 0x144;
    *(char **)yYSTYPE = _yylineno;
    break;
  case 0x61:
    token = 0x13b;
    *(char **)yYSTYPE = _yylineno;
    break;
  case 0x62:
    token = 0x13c;
    *(char **)yYSTYPE = _yylineno;
    break;
  case 99:
    token = 0x13e;
    *(char **)yYSTYPE = _yylineno;
    break;
  case 100:
    token = 0x13f;
    *(char **)yYSTYPE = _yylineno;
    break;
  case 0x65:
    token = 0x140;
    *(char **)yYSTYPE = _yylineno;
    break;
  case 0x66:
    token = 0x141;
    *(char **)yYSTYPE = _yylineno;
    break;
  case 0x67:
    token = 0x142;
    *(char **)yYSTYPE = _yylineno;
    break;
  case 0x68:
    token = 0x143;
    *(char **)yYSTYPE = _yylineno;
    break;
  case 0x69:
    token = 0x132;
    *(char **)yYSTYPE = _yylineno;
    break;
  case 0x6a:
    token = 0x133;
    *(char **)yYSTYPE = _yylineno;
    break;
  case 0x6b:
    token = 0x138;
    *(char **)yYSTYPE = _yylineno;
    break;
  case 0x6c:
    token = 0x139;
    *(char **)yYSTYPE = _yylineno;
    break;
  case 0x6d:
    token = 0x13a;
    *(char **)yYSTYPE = _yylineno;
    break;
  case 0x6e:
    token = 0x134;
    *(char **)yYSTYPE = _yylineno;
    break;
  case 0x6f:
    token = 0x135;
    *(char **)yYSTYPE = _yylineno;
    break;
  case 0x70:
    token = 0x136;
    *(char **)yYSTYPE = _yylineno;
    break;
  case 0x71:
    token = 0x137;
    *(char **)yYSTYPE = _yylineno;
    break;
  case 0x72:
    token = 0x130;
    *(char **)yYSTYPE = _yylineno;
    break;
  case 0x73:
    token = 0x131;
    *(char **)yYSTYPE = _yylineno;
    break;
  case 0x74:
    token = 0x14f;
    *(char **)yYSTYPE = _yylineno;
    *(undefined4 *)((int)parseContext + 0x1c) = 0;
    break;
  case 0x75:
    token = 0x149;
    *(char **)yYSTYPE = _yylineno;
    *(undefined4 *)((int)parseContext + 0x1c) = 0;
    break;
  case 0x76:
    token = 0x14a;
    *(char **)yYSTYPE = _yylineno;
    break;
  case 0x77:
    *(char **)yYSTYPE = _yylineno;
    if (*(int *)((int)parseContext + 0x24) != 0) {
      *(undefined4 *)((int)parseContext + 0x1c) = 0;
    }
    token = 0x14c;
    break;
  case 0x78:
    token = 0x14d;
    *(char **)yYSTYPE = _yylineno;
    break;
  case 0x79:
    token = 0x14e;
    *(char **)yYSTYPE = _yylineno;
    *(undefined4 *)((int)parseContext + 0x1c) = 0;
    break;
  case 0x7a:
    token = 0x145;
    *(char **)yYSTYPE = _yylineno;
    *(undefined4 *)((int)parseContext + 0x24) = 1;
    *(undefined4 *)((int)parseContext + 0x1c) = 0;
    break;
  case 0x7b:
    token = 0x146;
    *(char **)yYSTYPE = _yylineno;
    *(undefined4 *)((int)parseContext + 0x24) = 0;
    break;
  case 0x7c:
    token = 0x147;
    *(char **)yYSTYPE = _yylineno;
    break;
  case 0x7d:
    token = 0x148;
    *(char **)yYSTYPE = _yylineno;
    break;
  case 0x7e:
    token = 0x14b;
    _yy_start = 3;
    break;
  case 0x7f:
    token = 0x150;
    *(char **)yYSTYPE = _yylineno;
    break;
  case 0x80:
    token = 0x151;
    *(char **)yYSTYPE = _yylineno;
    break;
  case 0x81:
    token = 0x152;
    *(char **)yYSTYPE = _yylineno;
    break;
  case 0x82:
    token = 0x153;
    *(char **)yYSTYPE = _yylineno;
    break;
  case 0x83:
    token = 0x154;
    *(char **)yYSTYPE = _yylineno;
    break;
  case 0x84:
    token = 0x155;
    *(char **)yYSTYPE = _yylineno;
    break;
  case 0x85:
    token = 0x156;
    *(char **)yYSTYPE = _yylineno;
    break;
  case 0x86:
    token = 0x157;
    *(char **)yYSTYPE = _yylineno;
    break;
  case 0x87:
    token = 0x158;
    *(char **)yYSTYPE = _yylineno;
    break;
  case 0x88:
    token = 0x159;
    *(char **)yYSTYPE = _yylineno;
    break;
  case 0x89:
    token = 0x15a;
    *(char **)yYSTYPE = _yylineno;
    break;
  case 0x8a:
    token = 0x15b;
    *(char **)yYSTYPE = _yylineno;
    break;
  case 0x8b:
    token = 0x15c;
    *(char **)yYSTYPE = _yylineno;
    break;
  case 0x8c:
    _yy_start = 1;
    *(char **)yYSTYPE = _yylineno;
    yyBp = _yytext;
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    stringMem = (void *)TPoolAllocator__allocate(poolAllocator,8);
    tokenString = (void *)0x0;
    if (stringMem != (void *)0x0) {
      stringCtorAlloc[0] = GetGlobalPoolAllocator();
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                (stringMem,(char *)yyBp,(unsigned char *)stringCtorAlloc);
      tokenString = stringMem;
    }
    *(void **)(yYSTYPE + 4) = tokenString;
    token = 0x12f;
    break;
  case 0x8f:
    infoSinkBase = *(void **)((int)parseContext + 8);
    __ZN13TInfoSinkBase6appendEPKc(infoSinkBase,"FLEX: Unknown char ");
    __ZN13TInfoSinkBase6appendEPKc(infoSinkBase,(char *)_yytext);
    __ZN13TInfoSinkBase6appendEPKc(infoSinkBase,"\n");
    token = 0;
    break;
  case 0x90:
    _fwrite(_yytext,_yyleng,1,_yyout);
    goto yyActCase1;
  case 0x91:
    *yyCp = _yy_hold_char;
    if (*(int *)(_yy_current_buffer + 0x24) == 0) {
      _yy_n_chars = *(int *)(_yy_current_buffer + 0x10);
      *(unsigned char **)_yy_current_buffer = _yyin;
      *(int *)(_yy_current_buffer + 0x24) = 1;
    }
    if (_yy_c_buf_p <= (byte *)(*(int *)(_yy_current_buffer + 4) + _yy_n_chars)) {
      _yy_c_buf_p = _yytext + (int)(yyCp + (-1 - (int)matchStart));
      stateOffset = ((int (*)())yy_get_previous_state)();
      yyCurrentState = ((int (*)())yy_try_NUL_trans)(stateOffset);
      if (yyCurrentState == 0) goto loopSetStateOffset;
      _yy_c_buf_p = _yy_c_buf_p + 1;
      yyBp = _yytext;
      goto loopSetYyDefPtr;
    }
    nextBufferAction = ((int (*)())yy_get_next_buffer)();
    if (nextBufferAction == 1) goto setYyAct;
    if (1 < nextBufferAction) {
      if (nextBufferAction == 2) goto setYyCBufP;
      goto yyActCase1;
    }
    if (nextBufferAction != 0) goto yyActCase1;
    _yy_c_buf_p = _yytext + (int)(yyCp + (-1 - (int)matchStart));
    yyCurrentState = ((int (*)())yy_get_previous_state)();
    yyBp = _yytext;
    goto loopSetYyDefPtr;
  case 0x92:
  case 0x93:
    *(undefined4 *)((int)parseContext + 0x60) = 1;
    yy_delete_buffer(_yy_current_buffer);
    token = 0;
  }
  return token;
setYyAct:
  yyAct = _yy_start - 1;
  _yy_did_buffer_switch_on_eof = 0;
  _yy_c_buf_p = _yytext;
  yyAct = ((int)yyAct >> 1) + (uint)((int)yyAct < 0 && (yyAct & 1) != 0) + 0x92;
  goto loopSetTokenLine;
setYyCBufP:
  _yy_c_buf_p = (byte *)(*(int *)(_yy_current_buffer + 4) + _yy_n_chars);
  stateOffset = ((int (*)())yy_get_previous_state)();
  stateOffset = stateOffset << 1;
  yyBp = _yytext;
  goto loopSetYyAct;
}

/* yy_get_next_buffer @ 0x97bad390 (656 bytes) */
int yy_get_next_buffer()
{
  int newChBuf;
  int newSize;
  int numToRead;
  undefined1 ch;
  int b;
  int retVal;
  void *oldChBuf;
  undefined4 yy_flex_reallocResult;
  uint oldSize;
  undefined1 *numberToMove;
  undefined1 *dest;
  undefined1 *source;
  undefined1 *moveRemaining;
  
  source = _yytext;
  dest = *(undefined1 **)(_yy_current_buffer + 4);
  if (dest + (int)(_yy_n_chars + 1) < _yy_c_buf_p) {
    yy_fatal_error("fatal flex scanner internal error--end of buffer missed");
  }
  if (*(int *)(_yy_current_buffer + 0x20) == 0) {
    retVal = 2 - (uint)((int)_yy_c_buf_p - (int)_yytext == 1);
  }
  else {
    numberToMove = _yy_c_buf_p + (-1 - (int)_yytext);
    moveRemaining = numberToMove;
    if (0 < (int)numberToMove) {
      do {
        ch = *source;
        source = source + 1;
        *dest = ch;
        dest = dest + 1;
        moveRemaining = moveRemaining + -1;
      } while (moveRemaining != (undefined1 *)0x0);
    }
    if (*(int *)(_yy_current_buffer + 0x24) == 2) {
      _yy_n_chars = (undefined1 *)0x0;
    }
    else {
      numToRead = *(int *)(_yy_current_buffer + 0xc) - (int)numberToMove;
      b = _yy_current_buffer;
      source = _yy_c_buf_p;
      while (numToRead = numToRead + -1, _yy_current_buffer = b, _yy_c_buf_p = source, numToRead < 1) {
        oldChBuf = *(void **)(b + 4);
        if (*(int *)(b + 0x14) == 0) {
          *(undefined4 *)(b + 4) = 0;
        }
        else {
          oldSize = *(uint *)(b + 0xc);
          newSize = oldSize << 1;
          if (newSize < 1) {
            newSize = oldSize + (oldSize >> 3);
          }
          *(int *)(b + 0xc) = newSize;
          yy_flex_reallocResult = yy_flex_realloc(oldChBuf,*(int *)(b + 0xc) + 2);
          *(undefined4 *)(b + 4) = yy_flex_reallocResult;
        }
        newChBuf = *(int *)(b + 4);
        if (newChBuf == 0) {
          yy_fatal_error("fatal error - scanner input buffer overflow");
          newChBuf = *(int *)(b + 4);
        }
        source = source + (newChBuf - (int)oldChBuf);
        b = _yy_current_buffer;
        numToRead = *(int *)(_yy_current_buffer + 0xc) - (int)numberToMove;
      }
      if (0x2000 < numToRead) {
        numToRead = 0x2000;
      }
      _yy_n_chars = (undefined1 *)_yylex_CPP(numberToMove + *(int *)(b + 4),numToRead);
      if (_yy_n_chars != (undefined1 *)0x0) {
        if (numToRead <= (int)_yy_n_chars) {
          yy_fatal_error("input buffer overflow, can\'t enlarge buffer because scanner uses REJECT")
          ;
        }
        numberToMove[(int)_yy_n_chars + *(int *)(_yy_current_buffer + 4)] = 0x20;
        _yy_n_chars = (undefined1 *)((int)_yy_n_chars + 1);
      }
    }
    *(undefined1 **)(_yy_current_buffer + 0x10) = _yy_n_chars;
    retVal = 0;
    if (_yy_n_chars == (undefined1 *)0x0) {
      if (numberToMove == (undefined1 *)0x0) {
        retVal = 1;
        ((int (*)())yyrestart)(_yyin);
      }
      else {
        retVal = 2;
        *(undefined4 *)(_yy_current_buffer + 0x24) = 2;
      }
    }
    _yy_n_chars = numberToMove + (int)_yy_n_chars;
    _yy_n_chars[*(int *)(_yy_current_buffer + 4)] = 0;
    _yy_n_chars[*(int *)(_yy_current_buffer + 4) + 1] = 0;
    _yytext = *(undefined1 **)(_yy_current_buffer + 4);
  }
  return retVal;
}

/* yy_get_previous_state @ 0x97bad620 (280 bytes) */
int yy_get_previous_state()
{
  int nxtIndex;
  int yyCurrentState;
  byte *yyCp;
  int stateOffset;
  uint yyC;
  
  yyCurrentState = _yy_start;
  for (yyCp = _yytext; yyCp < _yy_c_buf_p; yyCp = yyCp + 1) {
    yyC = 1;
    if (*yyCp != 0) {
      yyC = (uint)(byte)(DAT_97c37983)[(uint)*yyCp * 4];
    }
    stateOffset = yyCurrentState * 2;
    if (*(short *)(&_yy_accept + stateOffset) != 0) {
      _yy_last_accepting_cpos = yyCp;
      _yy_last_accepting_state = yyCurrentState;
    }
    while (nxtIndex = ((int)*(short *)(&_yy_base + stateOffset) + yyC) * 2,
          *(short *)(&_yy_chk + nxtIndex) != yyCurrentState) {
      yyCurrentState = (int)*(short *)(&_yy_def + stateOffset);
      stateOffset = yyCurrentState << 1;
      if (0x199 < yyCurrentState) {
        yyC = (uint)(byte)(DAT_97c37d83)[yyC * 4];
      }
    }
    yyCurrentState = (int)*(short *)(&_yy_nxt + nxtIndex);
  }
  return yyCurrentState;
}

/* yy_try_NUL_trans @ 0x97bad738 (184 bytes) */
int yy_try_NUL_trans(yyCurrentState)
  int yyCurrentState;
{
  int nxtIndex;
  uint yyC;
  int stateOffset;
  
  stateOffset = yyCurrentState * 2;
  yyC = 1;
  if (*(short *)(&_yy_accept + stateOffset) != 0) {
    _yy_last_accepting_cpos = _yy_c_buf_p;
    _yy_last_accepting_state = yyCurrentState;
  }
  while (nxtIndex = ((int)*(short *)(&_yy_base + stateOffset) + yyC) * 2,
        *(short *)(&_yy_chk + nxtIndex) != yyCurrentState) {
    yyCurrentState = (int)*(short *)(&_yy_def + stateOffset);
    stateOffset = yyCurrentState << 1;
    if (0x199 < yyCurrentState) {
      yyC = (uint)(byte)(DAT_97c37d83)[yyC * 4];
    }
  }
  if (*(short *)(&_yy_nxt + nxtIndex) == 0x199) {
    return 0;
  }
  return (int)*(short *)(&_yy_nxt + nxtIndex);
}

/* yyinput @ 0x97bad7f0 (272 bytes) */
int yyinput()
{
  byte *savedCp;
  byte ch;
  int savedText;
  int yy_get_next_bufferResult;
  
  *_yy_c_buf_p = _yy_hold_char;
  savedCp = _yy_c_buf_p;
  savedText = _yytext;
  if (*_yy_c_buf_p == 0) {
    if (_yy_c_buf_p < (byte *)(*(int *)(_yy_current_buffer + 4) + _yy_n_chars)) {
      *_yy_c_buf_p = 0;
    }
    else {
      _yy_c_buf_p = _yy_c_buf_p + 1;
      yy_get_next_bufferResult = ((int (*)())yy_get_next_buffer)();
      if (yy_get_next_bufferResult == 1) {
        return 0xffffffff;
      }
      if (yy_get_next_bufferResult < 2) {
        if (yy_get_next_bufferResult == 0) {
          _yy_c_buf_p = savedCp + (_yytext - savedText);
        }
      }
      else if (yy_get_next_bufferResult == 2) {
        ((int (*)())yyrestart)(_yyin);
        return 0xffffffff;
      }
    }
  }
  ch = *_yy_c_buf_p;
  *_yy_c_buf_p = 0;
  savedCp = _yy_c_buf_p + 1;
  _yy_c_buf_p = _yy_c_buf_p + 1;
  _yy_hold_char = *savedCp;
  return (uint)ch;
}

/* yyrestart @ 0x97bad900 (104 bytes) */
int yyrestart(inputFile)
  unsigned char * inputFile;
{
  if (_yy_current_buffer == (unsigned char *)0x0) {
    _yy_current_buffer = (unsigned char *)((int (*)())yy_create_buffer)(_yyin,0x4000);
  }
  yy_init_buffer(_yy_current_buffer,inputFile);
  return ((int (*)())yy_load_buffer_state)();
}

/* yy_switch_to_buffer @ 0x97bad968 (148 bytes) */
int yy_switch_to_buffer(yy_buffer_state)
  unsigned char * yy_buffer_state;
{
  if (_yy_current_buffer != yy_buffer_state) {
    if (_yy_current_buffer != (unsigned char *)0x0) {
      *_yy_c_buf_p = _yy_hold_char;
      *(undefined1 **)(_yy_current_buffer + 8) = _yy_c_buf_p;
      *(undefined4 *)(_yy_current_buffer + 0x10) = _yy_n_chars;
    }
    _yy_current_buffer = yy_buffer_state;
    ((int (*)())yy_load_buffer_state)();
    _yy_did_buffer_switch_on_eof = 1;
  }
  return;
}

/* yy_load_buffer_state @ 0x97bad9fc (88 bytes) */
int yy_load_buffer_state()
{
  _yy_n_chars = (unsigned char *)*(unsigned int *)(_yy_current_buffer + 0x10);
  _yy_c_buf_p = (undefined1 *)*(unsigned int *)(_yy_current_buffer + 8);
  _yytext = _yy_c_buf_p;
  _yyin = *(void **)_yy_current_buffer;
  _yy_hold_char = *_yy_c_buf_p;
  return;
}

/* yy_create_buffer @ 0x97bada54 (140 bytes) */
int yy_create_buffer(file, bufSize)
  unsigned char * file;
  int bufSize;
{
  unsigned char * b;
  int chBuf;
  
  b = (unsigned char *)yy_flex_alloc(0x28);
  if (b == (unsigned char *)0x0) {
    yy_fatal_error("out of dynamic memory in yy_create_buffer()");
  }
  *(int *)(b + 0xc) = bufSize;
  chBuf = yy_flex_alloc(bufSize + 2);
  *(int *)(b + 4) = chBuf;
  if (chBuf == 0) {
    yy_fatal_error("out of dynamic memory in yy_create_buffer()");
  }
  *(undefined4 *)(b + 0x14) = 1;
  yy_init_buffer(b,file);
  return b;
}

