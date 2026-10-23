#include "decls.h"

/* _ShGetInfoLog @ 0x97ba1c6c (244 bytes) */
int _ShGetInfoLog(handle)
  int *handle;
{
  undefined *terminalPtr;
  int iVar2;
  int *infoSink;
  int result;
  
  result = 0;
  if (handle != (int *)0x0) {
    iVar2 = (**(code **)(*handle + 8))(handle);
    if (iVar2 == 0) {
      iVar2 = (**(code **)(*handle + 0xc))(handle);
      if (iVar2 == 0) {
        return 0;
      }
      iVar2 = (**(code **)(*handle + 0xc))(handle);
      infoSink = *(int **)(iVar2 + 0x84);
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
int _ShGetUniformTypeInfo(handle, index, param_3, param_4, param_5)
  int *handle;
  long index;
  long *param_3;
  ulong *param_4;
  uchar *param_5;
{
  unsigned char * linkerObj;
  undefined4 result;
  
  result = 0;
  if ((handle != (int *)0x0) &&
     (linkerObj = (unsigned char *)(**(code **)(*handle + 0xc))(handle), linkerObj != (unsigned char *)0x0
     )) {
    result = TGenericLinker__getUniformTypeInfo(linkerObj,index,param_3,param_4,param_5);
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
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  if ((handle != (int *)0x0) && (linkerObj = (**(code **)(*handle + 0xc))(handle), linkerObj != 0)) {
    uVar2 = 0xffffffff;
    if (*(unsigned char **)(linkerObj + 4) != (unsigned char *)0x0) {
      uVar2 = BindingTable__FindAttribBindingLocationByName(*(unsigned char **)(linkerObj + 4),str);
    }
  }
  return uVar2;
}

/* _ShGetUniformLocation @ 0x97ba22d4 (112 bytes) */
int _ShGetUniformLocation(handle, str)
  int *handle;
  char *str;
{
  int linkerObj;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  if ((handle != (int *)0x0) && (linkerObj = (**(code **)(*handle + 0xc))(handle), linkerObj != 0)) {
    uVar2 = 0xffffffff;
    if (*(unsigned char **)(linkerObj + 4) != (unsigned char *)0x0) {
      uVar2 = BindingTable__FindClientUniformBindingLocationByName
                        (*(unsigned char **)(linkerObj + 4),str);
    }
  }
  return uVar2;
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
      goto LAB_97ba26e0;
    }
  }
  else {
    mangleChar = 0x6d;
LAB_97ba26e0:
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEmc(text,1,mangleChar);
  }
  switch(*(uint *)(this + 0x24) >> 0x13 & 0x3f) {
  default:
    goto switchD_97ba270c_caseD_0;
  case 1:
    mangleChar = 0x66;
    goto LAB_97ba2778;
  case 2:
    mangleChar = 0x69;
    goto LAB_97ba2778;
  case 3:
    mangleChar = 0x62;
LAB_97ba2778:
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEmc(text,1,mangleChar);
    goto switchD_97ba270c_caseD_0;
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
    goto switchD_97ba270c_caseD_0;
  }
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEPKcm(text,typeCode,length);
switchD_97ba270c_caseD_0:
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
  unsigned char * this_00;
  
  symbolName = *(int *)(this + 4);
  this_00 = infoSink + 8;
  nameData = *(int *)(symbolName + 4);
  *(undefined1 *)(nameData + *(int *)(nameData + -0xc)) = *DAT_a7b7ba80;
  __ZN13TInfoSinkBase6appendEPKc(this_00,*(char **)(symbolName + 4));
  __ZN13TInfoSinkBase6appendEPKc(this_00,": ");
  qualifierString = (char *)getQualifierString(*(uint *)(this + 0x30) >> 0x19);
  __ZN13TInfoSinkBase6appendEPKc(this_00,qualifierString);
  __ZN13TInfoSinkBase6appendEPKc(this_00," ");
  basicString = (char *)TType__getBasicString(*(uint *)(this + 0x30) >> 0x13 & 0x3f);
  __ZN13TInfoSinkBase6appendEPKc(this_00,basicString);
  if ((*(uint *)(this + 0x30) & 0x200) != 0) {
    __ZN13TInfoSinkBase6appendEPKc(this_00,"[0]");
  }
  return __ZN13TInfoSinkBase6appendEPKc(this_00,"\n");
}

/* TFunction__dump @ 0x97ba2a38 (216 bytes) */
int TFunction__dump(this, infoSink)
  unsigned char * this;
  unsigned char * infoSink;
{
  int mangledName;
  undefined1 *puVar1;
  int iVar2;
  char *basicString;
  int iVar4;
  unsigned char * this_00;
  
  puVar1 = DAT_a7b7ba80;
  iVar4 = *(int *)(this + 4);
  this_00 = infoSink + 8;
  iVar2 = *(int *)(iVar4 + 4);
  *(undefined1 *)(iVar2 + *(int *)(iVar2 + -0xc)) = *DAT_a7b7ba80;
  __ZN13TInfoSinkBase6appendEPKc(this_00,*(char **)(iVar4 + 4));
  __ZN13TInfoSinkBase6appendEPKc(this_00,": ");
  basicString = (char *)TType__getBasicString(*(uint *)(this + 0x40) >> 0x13 & 0x3f);
  __ZN13TInfoSinkBase6appendEPKc(this_00,basicString);
  __ZN13TInfoSinkBase6appendEPKc(this_00," ");
  mangledName = (**(code **)(*(int *)this + 8))(this);
  *(undefined1 *)(*(int *)(mangledName + 4) + *(int *)(*(int *)(mangledName + 4) + -0xc)) = *puVar1;
  __ZN13TInfoSinkBase6appendEPKc(this_00,*(char **)(mangledName + 4));
  return __ZN13TInfoSinkBase6appendEPKc(this_00,"\n");
}

/* TSymbolTableLevel__dump @ 0x97ba2b10 (112 bytes) */
int TSymbolTableLevel__dump(this, infoSink)
  unsigned char * this;
  unsigned char * infoSink;
{
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int a6;
  int local_20 [4];
  
  a6 = *(int *)(this + 4);
  local_20[0] = *(int *)(a6 + 8);
  while (local_20[0] != a6) {
    (**(code **)(**(int **)(local_20[0] + 0x18) + 0x14))
              (*(int **)(local_20[0] + 0x18),infoSink,in_r5,in_r6,in_r7,in_r8,a6);
    std___Rb_tree_base_iterator___M_increment((unsigned char *)local_20);
    a6 = *(int *)(this + 4);
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
  undefined4 local_20 [5];
  
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
  local_20[0] = *(undefined4 *)((int)this + 0x44);
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
              ((unsigned char *)(paramEnd + -0xc),local_20);
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
int __ZN17TSymbolTableLevelD4Ev(this, param_2)
  void *this;
  undefined4 param_2;
{
  int *symbol;
  undefined4 extraout_r4;
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
        (**(code **)(*symbol + 4))(symbol,param_2,staleR5,staleR6,staleR7,staleR8,treeEnd);
      }
      std___Rb_tree_base_iterator___M_increment((unsigned char *)iter);
      treeEnd = *(int *)((int)this + 4);
      param_2 = extraout_r4;
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
  int iVar1;
  int symbol;
  int iter [4];
  int treeEnd;
  
  treeEnd = *(int *)(this + 4);
  iter[0] = *(int *)(treeEnd + 8);
  if (iter[0] != treeEnd) {
    do {
      iVar1 = (**(code **)(**(int **)(iter[0] + 0x18) + 0xc))(*(int **)(iter[0] + 0x18));
      if (iVar1 != 0) {
        symbol = *(int *)(iter[0] + 0x18);
        iVar1 = __ZNKSbIcSt11char_traitsIcE14pool_allocatorIcEE7compareEPKc
                          (*(void **)(symbol + 4),str);
        if (iVar1 == 0) {
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
  undefined4 auStack_30 [7];
  
  srcName = *(int *)(symbol + 4);
  *(undefined ***)this = &PTR___ZN7TSymbolD1Ev_a7b7d568;
  srcNameData = *(int *)(srcName + 4);
  *(undefined1 *)(srcNameData + *(int *)(srcNameData + -0xc)) = *DAT_a7b7ba80;
  nameText = *(char **)(srcName + 4);
  poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
  nameMem = (void *)TPoolAllocator__allocate(poolAllocator,8);
  newName = (void *)0x0;
  if (nameMem != (void *)0x0) {
    auStack_30[0] = GetGlobalPoolAllocator();
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
              (nameMem,nameText,(unsigned char *)auStack_30);
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
  undefined4 auStack_30 [7];
  
  srcName = *(int *)(symbol + 4);
  *(undefined ***)this = &PTR___ZN7TSymbolD1Ev_a7b7d568;
  srcNameData = *(int *)(srcName + 4);
  *(undefined1 *)(srcNameData + *(int *)(srcNameData + -0xc)) = *DAT_a7b7ba80;
  nameText = *(char **)(srcName + 4);
  poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
  nameMem = (void *)TPoolAllocator__allocate(poolAllocator,8);
  newName = (void *)0x0;
  if (nameMem != (void *)0x0) {
    auStack_30[0] = GetGlobalPoolAllocator();
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
              (nameMem,nameText,(unsigned char *)auStack_30);
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
  *(undefined1 *)(srcNameData + *(int *)(srcNameData + -0xc)) = *DAT_a7b7ba80;
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
  uint uVar1;
  int iVar2;
  unsigned char * poolAllocator;
  undefined4 *unionArray;
  undefined4 assertLine;
  char *assertText;
  
  ((int (*)())__ZN7TSymbolC2ERKS_)(this,(unsigned char *)variable);
  *(int *)this = DAT_a7b7ba78 + 8;
  *(undefined ***)((int)this + 0xc) = &PTR___ZN5TTypeD1Ev_a7b7d590;
  TType__copyType((unsigned char *)((int)this + 0xc),(unsigned char *)(variable + 0xc),map);
  iVar2 = *(int *)(variable + 0x3c);
  uVar1 = *(uint *)(variable + 0x34);
  *(uint *)((int)this + 0x34) = uVar1;
  if (iVar2 == 0) {
    iVar2 = *(int *)(variable + 0x38);
    *(undefined4 *)((int)this + 0x3c) = 0;
    uVar1 = 0;
    if (iVar2 == 0) goto LAB_97ba314c;
    uVar1 = *(uint *)(variable + 0x14);
    if (uVar1 == 0) {
      uVar1 = *(uint *)(variable + 0x30);
      if ((uVar1 & 0x400) == 0) {
        uVar1 = (int)(uVar1 << 0xd | uVar1 >> 0x13) >> 0x18;
      }
      else {
        iVar2 = (int)(uVar1 << 0xd | uVar1 >> 0x13) >> 0x18;
        uVar1 = iVar2 * iVar2;
      }
      if (uVar1 == 1) {
        poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
        unionArray = (undefined4 *)TPoolAllocator__allocate(poolAllocator,4);
        *(undefined4 **)((int)this + 0x38) = unionArray;
        uVar1 = *(uint *)((int)this + 0x30) >> 0x13 & 0x3f;
        if (uVar1 == 2) {
LAB_97ba311c:
          *unionArray = **(undefined4 **)(variable + 0x38);
          return;
        }
        if (uVar1 < 3) {
          if (uVar1 == 1) {
            *unionArray = **(undefined4 **)(variable + 0x38);
            return;
          }
        }
        else if (uVar1 == 3) goto LAB_97ba311c;
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
LAB_97ba314c:
  *(uint *)((int)this + 0x38) = uVar1;
  return;
}

/* __ZN9TVariableC1ERKS_RSt3mapIP7TVectorI9TTypeLineES6_St4lessIS6_ESaISt4pairIKS6_S6_EEE @ 0x97ba2fb0 (4 bytes) */
int __ZN9TVariableC1ERKS_RSt3mapIP7TVectorI9TTypeLineES6_St4lessIS6_ESaISt4pairIKS6_S6_EEE(this, variable, map)
  void *this;
  unsigned char * variable;
  unsigned char * map;
{
  uint uVar1;
  int iVar2;
  unsigned char * poolAllocator;
  undefined4 *unionArray;
  undefined4 assertLine;
  char *assertText;
  
  ((int (*)())__ZN7TSymbolC2ERKS_)(this,(unsigned char *)variable);
  *(int *)this = DAT_a7b7ba78 + 8;
  *(undefined ***)((int)this + 0xc) = &PTR___ZN5TTypeD1Ev_a7b7d590;
  TType__copyType((unsigned char *)((int)this + 0xc),(unsigned char *)(variable + 0xc),map);
  iVar2 = *(int *)(variable + 0x3c);
  uVar1 = *(uint *)(variable + 0x34);
  *(uint *)((int)this + 0x34) = uVar1;
  if (iVar2 == 0) {
    iVar2 = *(int *)(variable + 0x38);
    *(undefined4 *)((int)this + 0x3c) = 0;
    uVar1 = 0;
    if (iVar2 == 0) goto LAB_97ba314c;
    uVar1 = *(uint *)(variable + 0x14);
    if (uVar1 == 0) {
      uVar1 = *(uint *)(variable + 0x30);
      if ((uVar1 & 0x400) == 0) {
        uVar1 = (int)(uVar1 << 0xd | uVar1 >> 0x13) >> 0x18;
      }
      else {
        iVar2 = (int)(uVar1 << 0xd | uVar1 >> 0x13) >> 0x18;
        uVar1 = iVar2 * iVar2;
      }
      if (uVar1 == 1) {
        poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
        unionArray = (undefined4 *)TPoolAllocator__allocate(poolAllocator,4);
        *(undefined4 **)((int)this + 0x38) = unionArray;
        uVar1 = *(uint *)((int)this + 0x30) >> 0x13 & 0x3f;
        if (uVar1 == 2) {
LAB_97ba311c:
          *unionArray = **(undefined4 **)(variable + 0x38);
          return;
        }
        if (uVar1 < 3) {
          if (uVar1 == 1) {
            *unionArray = **(undefined4 **)(variable + 0x38);
            return;
          }
        }
        else if (uVar1 == 3) goto LAB_97ba311c;
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
LAB_97ba314c:
  *(uint *)((int)this + 0x38) = uVar1;
  return;
}

/* __ZN9TVariableC4ERKS_RSt3mapIP7TVectorI9TTypeLineES6_St4lessIS6_ESaISt4pairIKS6_S6_EEE @ 0x97ba2fb4 (432 bytes) */
int __ZN9TVariableC4ERKS_RSt3mapIP7TVectorI9TTypeLineES6_St4lessIS6_ESaISt4pairIKS6_S6_EEE(this, variable, map)
  void *this;
  unsigned char * variable;
  unsigned char * map;
{
  uint uVar1;
  int iVar2;
  unsigned char * poolAllocator;
  undefined4 *unionArray;
  undefined4 assertLine;
  char *assertText;
  
  ((int (*)())__ZN7TSymbolC2ERKS_)(this,(unsigned char *)variable);
  *(int *)this = DAT_a7b7ba78 + 8;
  *(undefined ***)((int)this + 0xc) = &PTR___ZN5TTypeD1Ev_a7b7d590;
  TType__copyType((unsigned char *)((int)this + 0xc),(unsigned char *)(variable + 0xc),map);
  iVar2 = *(int *)(variable + 0x3c);
  uVar1 = *(uint *)(variable + 0x34);
  *(uint *)((int)this + 0x34) = uVar1;
  if (iVar2 == 0) {
    iVar2 = *(int *)(variable + 0x38);
    *(undefined4 *)((int)this + 0x3c) = 0;
    uVar1 = 0;
    if (iVar2 == 0) goto LAB_97ba314c;
    uVar1 = *(uint *)(variable + 0x14);
    if (uVar1 == 0) {
      uVar1 = *(uint *)(variable + 0x30);
      if ((uVar1 & 0x400) == 0) {
        uVar1 = (int)(uVar1 << 0xd | uVar1 >> 0x13) >> 0x18;
      }
      else {
        iVar2 = (int)(uVar1 << 0xd | uVar1 >> 0x13) >> 0x18;
        uVar1 = iVar2 * iVar2;
      }
      if (uVar1 == 1) {
        poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
        unionArray = (undefined4 *)TPoolAllocator__allocate(poolAllocator,4);
        *(undefined4 **)((int)this + 0x38) = unionArray;
        uVar1 = *(uint *)((int)this + 0x30) >> 0x13 & 0x3f;
        if (uVar1 == 2) {
LAB_97ba311c:
          *unionArray = **(undefined4 **)(variable + 0x38);
          return;
        }
        if (uVar1 < 3) {
          if (uVar1 == 1) {
            *unionArray = **(undefined4 **)(variable + 0x38);
            return;
          }
        }
        else if (uVar1 == 3) goto LAB_97ba311c;
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
LAB_97ba314c:
  *(uint *)((int)this + 0x38) = uVar1;
  return;
}

/* TVariable__clone @ 0x97ba3164 (76 bytes) */
int TVariable__clone(this, map)
  unsigned char * this;
  unsigned char * map;
{
  unsigned char * this_00;
  void *this_01;
  
  this_00 = (unsigned char *)GetGlobalPoolAllocator();
  this_01 = (void *)TPoolAllocator__allocate(this_00,0x40);
  ((int (*)())__ZN9TVariableC1ERKS_RSt3mapIP7TVectorI9TTypeLineES6_St4lessIS6_ESaISt4pairIKS6_S6_EEE)(this_01,this,map);
  return this_01;
}

/* __ZN9TFunctionC2ERKS_RSt3mapIP7TVectorI9TTypeLineES6_St4lessIS6_ESaISt4pairIKS6_S6_EEE @ 0x97ba31b0 (4 bytes) */
int __ZN9TFunctionC2ERKS_RSt3mapIP7TVectorI9TTypeLineES6_St4lessIS6_ESaISt4pairIKS6_S6_EEE(this, function, map)
  void *this;
  unsigned char * function;
  unsigned char * map;
{
  undefined4 poolAllocator2;
  undefined1 *nulCharPtr;
  int *emptyRepRefCount;
  void *nameString;
  undefined4 uVar4;
  unsigned char * poolAllocator;
  void *nameStrMem;
  unsigned char * paramType;
  int srcParams;
  undefined4 *paramFinish;
  int iVar8;
  int srcNameData;
  int srcParamName;
  uint paramIdx;
  char *nameText;
  unsigned char * srcParamType;
  char reservation;
  byte cr0Reg;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 auStack_50 [4];
  
  ((int (*)())__ZN7TSymbolC2ERKS_)(this,(unsigned char *)function);
  *(int *)this = DAT_a7b7ba7c + 8;
  poolAllocator2 = GetGlobalPoolAllocator();
  *(undefined4 *)((int)this + 0xc) = poolAllocator2;
  iVar8 = DAT_a7b7ba74;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  emptyRepRefCount = (int *)(iVar8 + 8);
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
  *(int *)((int)this + 0x48) = iVar8 + 0xc;
  nulCharPtr = DAT_a7b7ba80;
  for (paramIdx = 0; paramIdx < (uint)(*(int *)(function + 0x14) - *(int *)(function + 0x10) >> 3);
      paramIdx = paramIdx + 1) {
    paramFinish = *(undefined4 **)((int)this + 0x14);
    if (paramFinish == *(undefined4 **)((int)this + 0x18)) {
      std__vector_TParameter_pool_allocator_TParameter_____M_insert_aux
                ((int)this + 0xc,*(undefined4 *)((int)this + 0x14),&uStack_60);
    }
    else {
      iVar8 = 0;
      if (paramFinish != (undefined4 *)0x0) {
        paramFinish[1] = uStack_5c;
        *paramFinish = uStack_60;
        iVar8 = *(int *)((int)this + 0x14);
      }
      *(int *)((int)this + 0x14) = iVar8 + 8;
    }
    srcParams = *(int *)(function + 0x10);
    srcParamName = *(int *)(srcParams + paramIdx * 8);
    iVar8 = *(int *)((int)this + 0x14);
    srcNameData = *(int *)(srcParamName + 4);
    *(undefined1 *)(srcNameData + *(int *)(srcNameData + -0xc)) = *nulCharPtr;
    nameText = *(char **)(srcParamName + 4);
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    nameStrMem = (void *)TPoolAllocator__allocate(poolAllocator,8);
    nameString = (void *)0x0;
    if (nameStrMem != (void *)0x0) {
      auStack_50[0] = GetGlobalPoolAllocator();
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                (nameStrMem,nameText,(unsigned char *)auStack_50);
      nameString = nameStrMem;
    }
    *(void **)(iVar8 + -8) = nameString;
    srcParamType = *(unsigned char **)(srcParams + paramIdx * 8 + 4);
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    paramType = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x28);
    *(undefined ***)paramType = &PTR___ZN5TTypeD1Ev_a7b7d590;
    TType__copyType(paramType,srcParamType,map);
    *(unsigned char **)(iVar8 + -4) = paramType;
  }
  TType__copyType((unsigned char *)((int)this + 0x1c),(unsigned char *)(function + 0x1c),map);
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6assignERKS3_
            ((void *)((int)this + 0x44),(unsigned char *)(function + 0x44));
  uVar4 = *(undefined4 *)(function + 0x4c);
  *(undefined4 *)((int)this + 0x50) = *(undefined4 *)(function + 0x50);
  *(undefined4 *)((int)this + 0x4c) = uVar4;
  return;
}

/* __ZN9TFunctionC1ERKS_RSt3mapIP7TVectorI9TTypeLineES6_St4lessIS6_ESaISt4pairIKS6_S6_EEE @ 0x97ba31b4 (4 bytes) */
int __ZN9TFunctionC1ERKS_RSt3mapIP7TVectorI9TTypeLineES6_St4lessIS6_ESaISt4pairIKS6_S6_EEE(this, function, map)
  void *this;
  unsigned char * function;
  unsigned char * map;
{
  undefined4 poolAllocator2;
  undefined1 *nulCharPtr;
  int *emptyRepRefCount;
  void *nameString;
  undefined4 uVar4;
  unsigned char * poolAllocator;
  void *nameStrMem;
  unsigned char * paramType;
  int srcParams;
  undefined4 *paramFinish;
  int iVar8;
  int srcNameData;
  int srcParamName;
  uint paramIdx;
  char *nameText;
  unsigned char * srcParamType;
  char reservation;
  byte cr0Reg;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 auStack_50 [4];
  
  ((int (*)())__ZN7TSymbolC2ERKS_)(this,(unsigned char *)function);
  *(int *)this = DAT_a7b7ba7c + 8;
  poolAllocator2 = GetGlobalPoolAllocator();
  *(undefined4 *)((int)this + 0xc) = poolAllocator2;
  iVar8 = DAT_a7b7ba74;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  emptyRepRefCount = (int *)(iVar8 + 8);
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
  *(int *)((int)this + 0x48) = iVar8 + 0xc;
  nulCharPtr = DAT_a7b7ba80;
  for (paramIdx = 0; paramIdx < (uint)(*(int *)(function + 0x14) - *(int *)(function + 0x10) >> 3);
      paramIdx = paramIdx + 1) {
    paramFinish = *(undefined4 **)((int)this + 0x14);
    if (paramFinish == *(undefined4 **)((int)this + 0x18)) {
      std__vector_TParameter_pool_allocator_TParameter_____M_insert_aux
                ((int)this + 0xc,*(undefined4 *)((int)this + 0x14),&uStack_60);
    }
    else {
      iVar8 = 0;
      if (paramFinish != (undefined4 *)0x0) {
        paramFinish[1] = uStack_5c;
        *paramFinish = uStack_60;
        iVar8 = *(int *)((int)this + 0x14);
      }
      *(int *)((int)this + 0x14) = iVar8 + 8;
    }
    srcParams = *(int *)(function + 0x10);
    srcParamName = *(int *)(srcParams + paramIdx * 8);
    iVar8 = *(int *)((int)this + 0x14);
    srcNameData = *(int *)(srcParamName + 4);
    *(undefined1 *)(srcNameData + *(int *)(srcNameData + -0xc)) = *nulCharPtr;
    nameText = *(char **)(srcParamName + 4);
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    nameStrMem = (void *)TPoolAllocator__allocate(poolAllocator,8);
    nameString = (void *)0x0;
    if (nameStrMem != (void *)0x0) {
      auStack_50[0] = GetGlobalPoolAllocator();
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                (nameStrMem,nameText,(unsigned char *)auStack_50);
      nameString = nameStrMem;
    }
    *(void **)(iVar8 + -8) = nameString;
    srcParamType = *(unsigned char **)(srcParams + paramIdx * 8 + 4);
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    paramType = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x28);
    *(undefined ***)paramType = &PTR___ZN5TTypeD1Ev_a7b7d590;
    TType__copyType(paramType,srcParamType,map);
    *(unsigned char **)(iVar8 + -4) = paramType;
  }
  TType__copyType((unsigned char *)((int)this + 0x1c),(unsigned char *)(function + 0x1c),map);
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6assignERKS3_
            ((void *)((int)this + 0x44),(unsigned char *)(function + 0x44));
  uVar4 = *(undefined4 *)(function + 0x4c);
  *(undefined4 *)((int)this + 0x50) = *(undefined4 *)(function + 0x50);
  *(undefined4 *)((int)this + 0x4c) = uVar4;
  return;
}

/* __ZN9TFunctionC4ERKS_RSt3mapIP7TVectorI9TTypeLineES6_St4lessIS6_ESaISt4pairIKS6_S6_EEE @ 0x97ba31b8 (492 bytes) */
int __ZN9TFunctionC4ERKS_RSt3mapIP7TVectorI9TTypeLineES6_St4lessIS6_ESaISt4pairIKS6_S6_EEE(this, function, map)
  void *this;
  unsigned char * function;
  unsigned char * map;
{
  undefined4 poolAllocator2;
  undefined1 *nulCharPtr;
  int *emptyRepRefCount;
  void *nameString;
  undefined4 uVar4;
  unsigned char * poolAllocator;
  void *nameStrMem;
  unsigned char * paramType;
  int srcParams;
  undefined4 *paramFinish;
  int iVar8;
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
  iVar8 = DAT_a7b7ba74;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  emptyRepRefCount = (int *)(iVar8 + 8);
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
  *(int *)((int)this + 0x48) = iVar8 + 0xc;
  nulCharPtr = DAT_a7b7ba80;
  for (paramIdx = 0; paramIdx < (uint)(*(int *)(function + 0x14) - *(int *)(function + 0x10) >> 3);
      paramIdx = paramIdx + 1) {
    paramFinish = *(undefined4 **)((int)this + 0x14);
    if (paramFinish == *(undefined4 **)((int)this + 0x18)) {
      std__vector_TParameter_pool_allocator_TParameter_____M_insert_aux
                ((unsigned char *)((int)this + 0xc),
                 *(undefined4 *)((int)this + 0x14),&emptyParamName);
    }
    else {
      iVar8 = 0;
      if (paramFinish != (undefined4 *)0x0) {
        paramFinish[1] = emptyParamType;
        *paramFinish = emptyParamName;
        iVar8 = *(int *)((int)this + 0x14);
      }
      *(int *)((int)this + 0x14) = iVar8 + 8;
    }
    srcParams = *(int *)(function + 0x10);
    srcParamName = *(int *)(srcParams + paramIdx * 8);
    iVar8 = *(int *)((int)this + 0x14);
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
    *(void **)(iVar8 + -8) = nameString;
    srcParamType = *(unsigned char **)(srcParams + paramIdx * 8 + 4);
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    paramType = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x28);
    *(undefined ***)paramType = &PTR___ZN5TTypeD1Ev_a7b7d590;
    TType__copyType(paramType,srcParamType,map);
    *(unsigned char **)(iVar8 + -4) = paramType;
  }
  TType__copyType((unsigned char *)((int)this + 0x1c),(unsigned char *)(function + 0x1c),map);
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6assignERKS3_
            ((void *)((int)this + 0x44),(unsigned char *)(function + 0x44));
  uVar4 = *(undefined4 *)(function + 0x4c);
  *(undefined4 *)((int)this + 0x50) = *(undefined4 *)(function + 0x50);
  *(undefined4 *)((int)this + 0x4c) = uVar4;
  return;
}

/* TFunction__clone @ 0x97ba33a4 (76 bytes) */
int TFunction__clone(this, map)
  unsigned char * this;
  unsigned char * map;
{
  unsigned char * this_00;
  void *this_01;
  
  this_00 = (unsigned char *)GetGlobalPoolAllocator();
  this_01 = (void *)TPoolAllocator__allocate(this_00,0x54);
  ((int (*)())__ZN9TFunctionC1ERKS_RSt3mapIP7TVectorI9TTypeLineES6_St4lessIS6_ESaISt4pairIKS6_S6_EEE)(this_01,this,map);
  return this_01;
}

/* TSymbolTableLevel__clone @ 0x97ba33f0 (352 bytes) */
int TSymbolTableLevel__clone(this, map)
  unsigned char * this;
  unsigned char * map;
{
  int *refCountPtr;
  int atomicStore;
  int iVar2;
  unsigned char * poolAllocator;
  undefined4 *newLevel;
  undefined4 *headerNode;
  int *clonedSymbol;
  unsigned char * symbolName;
  undefined4 *in_r5;
  undefined4 staleR6;
  undefined4 staleR7;
  undefined4 staleR8;
  int a6;
  char reservation;
  byte cr0Reg;
  int iter [4];
  int treeEnd;
  undefined4 insertIter;
  undefined4 local_6c;
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
  a6 = newLevel[1];
  *(int *)(a6 + 0xc) = a6;
  treeEnd = *(int *)(this + 4);
  iter[0] = *(int *)(treeEnd + 8);
  if (iter[0] != treeEnd) {
    do {
      clonedSymbol = (int *)(**(code **)(**(int **)(iter[0] + 0x18) + 0x18))
                                (*(int **)(iter[0] + 0x18),map,in_r5,staleR6,staleR7,staleR8,a6);
      local_6c = 0;
      symbolName = (unsigned char *)(**(code **)(*clonedSymbol + 8))(clonedSymbol);
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&nameCopyAlloc,symbolName);
      in_r5 = &nameCopyAlloc;
      pairSymbol = clonedSymbol;
      std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&insertResultAlloc,newLevel,&nameCopyAlloc);
      insertIter = insertResultAlloc;
      refCountPtr = (int *)(nameCopyData + -4);
      local_6c = insertResultData;
      destroyAlloc[0] = nameCopyAlloc;
      do {
        iVar2 = *refCountPtr;
        a6 = iVar2 + -1;
        if (reservation != '\0') {
          atomicStore = storeWordConditionalIndexed(a6,0,refCountPtr);
          *refCountPtr = atomicStore;
          cr0Reg = 2;
        }
      } while (!(bool)(cr0Reg >> 1 & 1));
      if (iVar2 < 1) {
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
  int getenvResult;
  undefined4 atomicStore;
  undefined *puVar2;
  int iVar3;
  undefined4 *treeHeader;
  uint loopIndex;
  char reservation;
  byte cr0Reg;
  undefined4 *typeMap;
  int typeMapCount;
  undefined4 clonedLevel [5];
  
  puVar2 = PTR__S_force_new_a7b7c0e8;
  typeMap = (undefined4 *)0x0;
  if (*(int *)PTR__S_force_new_a7b7c0e8 == 0) {
    getenvResult = _getenv("GLIBCPP_FORCE_NEW");
    if (getenvResult == 0) {
      do {
        if (reservation != '\0') {
          atomicStore = storeWordConditionalIndexed(*(int *)puVar2 + -1,0,puVar2);
          *(undefined4 *)puVar2 = atomicStore;
          cr0Reg = 2;
        }
      } while (!(bool)(cr0Reg >> 1 & 1));
    }
    else {
      do {
        if (reservation != '\0') {
          atomicStore = storeWordConditionalIndexed(*(int *)puVar2 + 1,0,puVar2);
          *(undefined4 *)puVar2 = atomicStore;
          cr0Reg = 2;
        }
      } while (!(bool)(cr0Reg >> 1 & 1));
    }
  }
  puVar2 = PTR__S_free_list_a7b7c0e4;
  if (*(int *)PTR__S_force_new_a7b7c0e8 < 1) {
    _pthread_mutex_lock(PTR__S_node_allocator_lock_a7b7c0e0);
    treeHeader = *(undefined4 **)(puVar2 + 8);
    if (treeHeader == (undefined4 *)0x0) {
      treeHeader = (undefined4 *)std____default_alloc_template_true_0____S_refill(0x18);
    }
    else {
      *(undefined4 *)(puVar2 + 8) = *treeHeader;
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
      iVar3 = 0;
      if (treeHeader != (undefined4 *)0x0) {
        *treeHeader = clonedLevel[0];
        iVar3 = *(int *)(this + 4);
      }
      *(int *)(this + 4) = iVar3 + 4;
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
  uint functionPrototypeTypeOrFunction;
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
  uint typeQualifierQualifierOrParamType;
  unsigned char * typeSpecifierUserDef;
  unsigned char * typeSpecifierSize3;
  unsigned char * typeSpecifierTypeOrFunction;
  unsigned char * typeSpecifierTypeLine2;
  unsigned char * typeSpecifierQualifierOrParamType2;
  unsigned char * typeSpecifierTypeLine;
  unsigned char * typeSpecifierMatrix2;
  unsigned char * typeSpecifierSize2;
  unsigned char * typeSpecifierQualifierOrParamType;
  uint sizeBits;
  uint basicTypeBits2;
  uint qualifierBits2;
  unsigned char * typeSpecifierMatrix;
  unsigned char * typeSpecifierSize;
  unsigned char * newType;
  unsigned char * fullySpecifiedTypeTypeLine;
  unsigned char * parameterDeclarationQualifierOrParamType2;
  uint parameterDeclarationQualifierOrParamType;
  uint functionHeaderWithParametersTypeOrFunction;
  uint unaryOperatorOp;
  unsigned char * identifierString2;
  int reservedError;
  unsigned char * newRefCount3;
  unsigned char * oldRefCount3;
  uint constructorIdentifierUserDef;
  uint constructorIdentifierOp;
  unsigned char * newFunction;
  uint functionCallHeaderWithParametersTypeOrFunction;
  uint functionCallHeaderTypeOrFunction;
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
  uint uVar2;
  unsigned char * pTVar3;
  undefined4 *puVar4;
  undefined4 yy_outargs[0x14];
  undefined *puVar5;
  int iVar6;
  unsigned char * pTVar7;
  unsigned char * pTVar8;
  unsigned char * this;
  unsigned char * pcVar9;
  unsigned char * stackNode;
  unsigned char * newString;
  unsigned char * paVar11;
  unsigned char * pTVar12;
  void *pvVar13;
  unsigned char * pvVar14;
  unsigned char * pTVar15;
  undefined4 uVar16;
  unsigned char * poolAllocator;
  undefined4 *puVar18;
  undefined4 *puVar19;
  unsigned char * pTVar20;
  int *newNode;
  unsigned char * psVar21;
  unsigned char * pTVar22;
  void *pvVar23;
  unsigned char * this_00;
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
  unsigned char ** ppTVar24;
  undefined4 r4Out13;
  undefined4 r4Out14;
  undefined4 r4In9;
  undefined4 r4Out15;
  undefined4 r4Out16;
  undefined4 r4In10;
  undefined4 r4In11;
  undefined4 r4In12;
  uint *puVar25;
  undefined4 r4In13;
  int iVar26;
  undefined4 r4Out17;
  undefined4 r4Out18;
  undefined4 r4Out19;
  unsigned char * pTVar27;
  uint uVar28;
  char *pcVar29;
  int iVar30;
  int r6Pass;
  char *emptyText;
  unsigned char * pTVar31;
  int r7Pass;
  unsigned char * pTVar32;
  unsigned char * pTVar33;
  int r8Pass;
  unsigned char * pTVar34;
  undefined **ppuVar35;
  bool bVar37;
  int iVar36;
  int iVar38;
  int iVar39;
  code *pcVar40;
  unsigned char * yystacksize;
  unsigned char * yyvs;
  int yyerrstatus;
  int yychar;
  unsigned char * yyss;
  unsigned char * yyssp;
  unsigned char * constructorIdentifierOp2;
  int yystateOrYylen;
  undefined4 uVar49;
  int *piVar50;
  unsigned char * symbolTable3;
  unsigned char * structDeclarationListTypeOrFunction;
  uint uVar53;
  int iVar54;
  int iVar55;
  unsigned char * yyvsp;
  uint uVar57;
  uint uVar58;
  unsigned char * pTVar59;
  int iVar60;
  int *piVar61;
  char *pcVar62;
  char reservation;
  byte cr0;
  ulonglong yylexResult;
  undefined8 uVar64;
  unsigned char aTStack_2ca2 [2];
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
  unsigned char * local_850;
  unsigned char * local_84c;
  unsigned char * local_848;
  unsigned char * local_844;
  unsigned char * local_840;
  unsigned char * local_83c;
  unsigned char * local_838;
  unsigned char * local_834;
  unsigned char * local_830;
  unsigned char * local_82c;
  unsigned char * local_828;
  unsigned char * local_824;
  unsigned char * local_820;
  unsigned char * local_81c;
  unsigned char * local_818;
  unsigned char * local_814;
  unsigned char * local_810;
  unsigned char * local_80c;
  unsigned char * local_808;
  unsigned char * local_804;
  unsigned char * local_800;
  unsigned char * local_7fc;
  unsigned char * local_7f8;
  unsigned char * local_7f4;
  unsigned char * local_7f0;
  unsigned char * local_7ec;
  unsigned char * local_7e8;
  unsigned char * local_7e4;
  unsigned char * local_7e0;
  unsigned char * local_7dc;
  unsigned char * local_7d8;
  unsigned char * local_7d4;
  unsigned char * local_7d0;
  uint local_7cc;
  undefined4 local_7c0;
  uint local_7bc;
  unsigned char * local_7b0;
  char *local_7ac;
  unsigned char * local_780;
  int local_77c;
  int local_764;
  unsigned char * local_750 [4];
  unsigned char * local_740;
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
  unsigned char * local_660;
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
  int local_320 [4];
  unsigned char * local_310;
  int local_30c;
  unsigned char * local_308;
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
  undefined4 local_1e0;
  int local_1dc;
  int *local_1d8;
  undefined4 destroyAlloc64 [4];
  undefined4 ctorAlloc15 [4];
  undefined4 ctorAlloc16 [4];
  unsigned char * destroyAlloc65 [4];
  unsigned char * destroyAlloc66 [4];
  undefined4 allocatorArg5;
  unsigned char * local_170;
  undefined4 *destroyAlloc67 [4];
  unsigned char * local_150;
  unsigned char * local_140;
  unsigned char * local_130;
  undefined4 allocatorArg6;
  undefined4 allocatorArg7;
  undefined4 allocatorArg8;
  undefined4 local_f0;
  int local_ec;
  int *local_e8;
  undefined4 destroyAlloc68 [4];
  undefined4 ctorAlloc17 [4];
  unsigned char * destroyAlloc69 [4];
  undefined4 ctorAlloc18 [4];
  unsigned char * destroyAlloc70 [4];
  uint local_90;
  uint local_8c;
  int local_88;
  int local_84;
  unsigned char * local_80;
  unsigned char * local_7c;
  uint local_78;
  uint local_74;
  unsigned char * pTStack_70;
  int yyruleByteOffset;
  undefined *local_68;
  unsigned char * picBase;
  unsigned char * yyssBytes;
  unsigned char * picBase2;
  int *local_58;
  int local_54;
  
  puVar4 = yy_outargs;
  yyvsp = yyvsInit;
  yystacksize = (unsigned char *)0xc8;
  yystateOrYylen = 0;
  yyerrstatus = 0;
  yychar = -2;
  yyssp = aTStack_2ca2;
  yyssBytes = (unsigned char *)0x190;
  yyvs = yyvsp;
  yyss = yyssInit;
LAB_97ba3784:
  do {
    yyssp = yyssp + 2;
    *(short *)yyssp = (short)yystateOrYylen;
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
    yystateByteOffset = yystateOrYylen * 2;
    yypactEntry = (&_yypact)[yystateOrYylen];
    pTVar33 = yyssBytes;
    yyvs = yyvsBase;
    yyss = yyssBase;
    if (yypactEntry == -0x8000) {
LAB_97ba3958:
      yyn = (uint)*(short *)(&_yydefact + yystateByteOffset);
      if (yyn != 0) goto LAB_97ba3970;
LAB_97bac03c:
      if (yyerrstatus == 0) {
        yyerror("parse error",scratchR4,scratchR5,scratchR6,scratchR7,pTVar33,scratchR9,scratchR10);
        scratchR4 = r4Out18;
      }
LAB_97bac050:
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
          yystateOrYylen = (int)*(short *)(&_yytable + (int)scratchR9);
          if (yystateOrYylen < 0) {
            if (yystateOrYylen != -0x8000) goto LAB_97bac0d0;
          }
          else if (yystateOrYylen != 0) {
            if (yystateOrYylen == 0x14d) {
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
      yystateOrYylen = 0;
      yychar = 0;
    }
    else {
      yystateOrYylen = 0xa9;
      if (yylexResult < 0x15d00000000) {
        yystateOrYylen = (int)(char)(&_yytranslate)[yychar];
      }
    }
    yyn = yypactEntry + yystateOrYylen;
    if ((0x4ef < yyn) ||
       (scratchR9 = (undefined *)(yyn * 2), *(short *)(&_yycheck + (int)scratchR9) != yystateOrYylen))
    goto LAB_97ba3958;
    yystateOrYylen = (int)*(short *)(&_yytable + (int)scratchR9);
    if (yystateOrYylen < 0) {
      if (yystateOrYylen != -0x8000) break;
      goto LAB_97bac03c;
    }
    if (yystateOrYylen == 0) goto LAB_97bac03c;
    if (yystateOrYylen == 0x14d) {
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
LAB_97bac0d0:
  yyn = -yystateOrYylen;
LAB_97ba3970:
  yyruleByteOffset = yyn * 2;
  yystateOrYylen = (int)*(short *)(&_yyr2 + yyruleByteOffset);
  if (0 < yystateOrYylen) {
    scratchR5 = (char *)0x2c;
    _memcpy(&yyval,yyvsp + (1 - yystateOrYylen) * 0x2c,0x2c);
    scratchR4 = r4Out2;
  }
  pTVar3 = yyvalNode;
  pTVar31 = local_7f0;
  pTVar32 = local_750[0];
  if (0xd7 < yyn) goto switchD_97ba39c8_caseD_0;
  pTVar34 = (unsigned char *)(yyn * 4);
  pTVar59 = (unsigned char *)scratchR6;
  switch(yyn) {
  case 0:
    break;
  case 1:
    pTVar3 = *(unsigned char **)(yyvsp + 8);
    if (pTVar3 == (unsigned char *)0x0) {
      identifierString = *(uint *)(yyvsp + 4);
      picBase = (unsigned char *)0xa7b8374c;
      stringData = *(int *)(identifierString + 4);
      emptyText = "";
      pcVar62 = "undeclared identifier";
      *(unsigned char *)(stringData + *(int *)(stringData + -0xc)) = *DAT_a7b7ba88;
      pcVar29 = *(char **)(identifierString + 4);
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp,"undeclared identifier",pcVar29,"",pTVar33,stringData,
                 identifierString);
      TParseContext__recover(parseContext);
      picBase2 = (unsigned char *)0xa7b8374c;
      local_82c = (unsigned char *)((uint)local_82c & 0x1ff | 0x80800);
      local_850 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
      local_84c = pTVar3;
      local_848 = pTVar3;
      local_844 = pTVar3;
      local_840 = pTVar3;
      local_83c = pTVar3;
      local_838 = pTVar3;
      local_834 = pTVar3;
      local_830 = pTVar3;
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      uVar64 = TPoolAllocator__allocate(poolAllocator,0x40);
      pTVar7 = (unsigned char *)((ulonglong)uVar64 >> 0x20);
      identifierString = *(uint *)(yyvsp + 4);
      puVar5 = PTR_vtable_a7b7c0b4 + 8;
      *(undefined ***)(pTVar7 + 0xc) = &PTR___ZN5TTypeD1Ev_a7b7d640;
      *(uint *)(pTVar7 + 4) = identifierString;
      *(undefined **)pTVar7 = puVar5;
      *(unsigned char **)(pTVar7 + 0x10) = local_84c;
      *(unsigned char **)(pTVar7 + 0x14) = local_848;
      *(unsigned char **)(pTVar7 + 0x18) = local_844;
      *(unsigned char **)(pTVar7 + 0x1c) = local_840;
      *(unsigned char **)(pTVar7 + 0x20) = local_83c;
      *(unsigned char **)(pTVar7 + 0x24) = local_838;
      *(unsigned char **)(pTVar7 + 0x28) = local_834;
      *(unsigned char **)(pTVar7 + 0x2c) = local_830;
      uVar2 = *(uint *)(pTVar7 + 0x30);
      qualifierBits = (uint)local_82c & 0xfe000000;
      *(uint *)(pTVar7 + 0x30) = qualifierBits | uVar2 & 0x1ffffff;
      basicTypeBits = ((uint)local_82c >> 0x13 & 0x3f) << 0x13;
      *(uint *)(pTVar7 + 0x30) = basicTypeBits | qualifierBits | uVar2 & 0x7ffff;
      uVar57 = (uint)local_82c & 0x7f800;
      *(uint *)(pTVar7 + 0x30) = uVar57 | basicTypeBits | qualifierBits | uVar2 & 0x7ff;
      uVar58 = ((uint)local_82c >> 10 & 1) << 10;
      *(uint *)(pTVar7 + 0x30) = uVar58 | uVar57 | basicTypeBits | qualifierBits | uVar2 & 0x3ff;
      *(uint *)(pTVar7 + 0x30) =
           ((uint)local_82c >> 9 & 1) << 9 | uVar58 | uVar57 | basicTypeBits | qualifierBits | uVar2 & 0x1ff;
      *(uint *)(pTVar7 + 0x34) = 0;
      *(uint *)(pTVar7 + 0x38) = 0;
      *(uint *)(pTVar7 + 0x3c) = 0;
      symbolTable = *(int **)((int)parseContext + 4);
      nextUniqueId = symbolTable[3];
      symbolTable[3] = nextUniqueId + 1U;
      *(uint *)(pTVar7 + 8) = nextUniqueId + 1U;
      uVar16 = *(undefined4 *)(*symbolTable + ((symbolTable[1] - *symbolTable & 0xfffffffcU) - 4));
      local_81c = pTVar3;
      psVar21 = (unsigned char *)
                (**(code **)(*(uint *)pTVar7 + 8))
                          (pTVar7,(int)uVar64,pcVar62,pcVar29,emptyText,pTVar33,symbolTable);
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&local_800,psVar21);
      local_7f8 = pTVar7;
      std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&local_810,uVar16,&local_800);
      local_820 = local_810;
      refCountPtr = local_7fc + -4;
      local_81c = local_80c;
      local_7f0 = local_800;
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
                  ((unsigned char *)(local_7fc + -0xc),&local_7f0);
      }
      local_850 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
      pTVar3 = pTVar7;
    }
    else {
      iVar55 = (**(code **)(*(unsigned char **)pTVar3 + 0x10))(pTVar3);
      if (iVar55 == 0) {
        identifierString = *(uint *)(yyvsp + 4);
        picBase = (unsigned char *)0xa7b8374c;
        stringData = *(int *)(identifierString + 4);
        *(unsigned char *)(stringData + *(int *)(stringData + -0xc)) = *DAT_a7b7ba88;
        TParseContext__error
                  ((int)parseContext,*(char **)yyvsp,"variable expected",*(char **)(identifierString + 4),"",
                   pTVar33,stringData,identifierString);
        TParseContext__recover(parseContext);
      }
    }
    scratchR6 = (char *)(pTVar3 + 0xc);
    iVar55 = (**(code **)(*(uint *)(pTVar3 + 0xc) + 0x24))(scratchR6);
    if (iVar55 != 2) {
      scratchR7 = *(char **)yyvsp;
      pTVar3 = (unsigned char *)
               TIntermediate__addSymbol
                         (*(unsigned char **)parseContext,*(uint *)(pTVar3 + 8),*(unsigned char **)(pTVar3 + 4),
                          (unsigned char *)scratchR6,(int)scratchR7);
      pTVar31 = local_7f0;
      pTVar32 = local_750[0];
      break;
    }
    local_84c = *(unsigned char **)(pTVar3 + 0x10);
    local_844 = *(unsigned char **)(pTVar3 + 0x18);
    local_840 = *(unsigned char **)(pTVar3 + 0x1c);
    local_848 = *(unsigned char **)(pTVar3 + 0x14);
    local_83c = *(unsigned char **)(pTVar3 + 0x20);
    local_838 = *(unsigned char **)(pTVar3 + 0x24);
    scratchR7 = *(char **)(pTVar3 + 0x28);
    local_830 = *(unsigned char **)(pTVar3 + 0x2c);
    pcVar9 = *(unsigned char **)(pTVar3 + 0x38);
    local_82c = (unsigned char *)
                ((*(uint *)(pTVar3 + 0x30) >> 9 & 1) << 9 |
                (*(uint *)(pTVar3 + 0x30) >> 10 & 1) << 10 |
                *(uint *)(pTVar3 + 0x30) & 0x7f800 |
                (*(uint *)(pTVar3 + 0x30) >> 0x13 & 0x3f) << 0x13 |
                *(uint *)(pTVar3 + 0x30) & 0xfe000000 | (uint)local_82c & 0x1ff);
    local_834 = (unsigned char *)scratchR7;
LAB_97ba4158:
    local_850 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
    pTVar15 = *(unsigned char **)parseContext;
    scratchR6 = *(char **)yyvsp;
    goto LAB_97ba7d0c;
  default:
    goto switchD_97ba39c8_caseD_2;
  case 3:
    uVar57 = (int)*(uint *)(yyvsp + 4) >> 0x1f;
    iVar55 = (uVar57 ^ *(uint *)(yyvsp + 4)) - uVar57;
    if (0xffff < iVar55) {
      scratchR7 = "";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," integer constant overflow","","",uVar57,iVar55,
                 scratchR10);
      TParseContext__recover(parseContext);
    }
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    pcVar9 = (unsigned char *)TPoolAllocator__allocate(poolAllocator,4);
    *(uint *)pcVar9 = *(uint *)(yyvsp + 4);
    local_82c = (unsigned char *)((uint)local_82c & 0x9ff | 0x4100800);
    local_84c = (unsigned char *)0x0;
    local_848 = (unsigned char *)0x0;
    local_844 = (unsigned char *)0x0;
    local_840 = (unsigned char *)0x0;
    local_83c = (unsigned char *)0x0;
    local_838 = (unsigned char *)0x0;
    local_834 = (unsigned char *)0x0;
    local_830 = (unsigned char *)0x0;
    goto LAB_97ba4158;
  case 4:
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    pcVar9 = (unsigned char *)TPoolAllocator__allocate(poolAllocator,4);
    *(uint *)pcVar9 = *(uint *)(yyvsp + 4);
    uVar57 = (uint)local_82c & 0x7ff | 0x4080000;
    goto LAB_97ba41e8;
  case 5:
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    pcVar9 = (unsigned char *)TPoolAllocator__allocate(poolAllocator,4);
    *(uint *)pcVar9 = *(uint *)(yyvsp + 4);
    picBase2 = (unsigned char *)0xa7b8374c;
    uVar57 = (uint)local_82c & 0x1807ff | 0x4180000;
LAB_97ba41e8:
    local_82c = (unsigned char *)(uVar57 & 0xfffff9ff | 0x800);
    local_830 = (unsigned char *)0x0;
    local_84c = (unsigned char *)0x0;
    local_848 = (unsigned char *)0x0;
    local_844 = (unsigned char *)0x0;
    local_840 = (unsigned char *)0x0;
    local_83c = (unsigned char *)0x0;
    local_838 = (unsigned char *)0x0;
    local_834 = (unsigned char *)0x0;
    goto LAB_97ba4158;
  case 6:
  case 0xbb:
    goto switchD_97ba39c8_caseD_6;
  case 8:
    iVar55 = (**(code **)(**(int **)(yyvsp + -0x7c) + 0x54))
                       (*(int **)(yyvsp + -0x7c),scratchR4,scratchR5,scratchR6,scratchR7,pTVar33);
    if (((iVar55 == 0) &&
        (iVar55 = (**(code **)(**(int **)(yyvsp + -0x7c) + 0x50))(*(int **)(yyvsp + -0x7c)),
        iVar55 == 0)) &&
       (iVar55 = (**(code **)(**(int **)(yyvsp + -0x7c) + 0x58))(*(int **)(yyvsp + -0x7c)),
       iVar55 == 0)) {
      iVar55 = (**(code **)(**(int **)(yyvsp + -0x7c) + 0x28))(*(int **)(yyvsp + -0x7c));
      if (iVar55 == 0) {
        leftBracketLine = *(char **)(yyvsp + -0x58);
        scratchR6 = "expression";
      }
      else {
        picBase = (unsigned char *)0xa7b8374c;
        piVar61 = (int *)(**(code **)(**(int **)(yyvsp + -0x7c) + 0x28))
                                   (*(int **)(yyvsp + -0x7c));
        iVar55 = (**(code **)(*piVar61 + 0x60))(piVar61);
        pTVar34 = *(unsigned char **)(iVar55 + 4);
        pTVar34[*(uint *)(pTVar34 + -0xc)] = **(unsigned char **)(picBase + -0x7cc4);
        scratchR6 = *(char **)(iVar55 + 4);
        leftBracketLine = *(char **)(yyvsp + -0x58);
        pTVar33 = picBase;
      }
      scratchR5 = " left of \'[\' is not of type array, matrix, or vector ";
      scratchR7 = "";
      TParseContext__error
                ((int)parseContext,leftBracketLine," left of \'[\' is not of type array, matrix, or vector ",
                 scratchR6,"",pTVar33,pTVar34,scratchR10);
      TParseContext__recover(parseContext);
    }
    bVar37 = false;
    (**(code **)(**(int **)(yyvsp + -0x7c) + 0x38))(&local_850,*(int **)(yyvsp + -0x7c));
    if ((((uint)local_82c >> 0x19 == 2) &&
        (iVar55 = (**(code **)(**(int **)(yyvsp + -0x7c) + 0x54))(*(int **)(yyvsp + -0x7c)),
        iVar55 == 0)) &&
       (iVar55 = (**(code **)(**(int **)(yyvsp + -0x24) + 0x44))(*(int **)(yyvsp + -0x24)),
       iVar55 == 2)) {
      bVar37 = true;
    }
    picBase2 = (unsigned char *)0xa7b8374c;
    local_850 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
    if (bVar37) {
      isVector = (**(code **)(**(int **)(yyvsp + -0x7c) + 0x58))(*(int **)(yyvsp + -0x7c));
      if (isVector == 0) {
        isMatrix = (**(code **)(**(int **)(yyvsp + -0x7c) + 0x50))(*(int **)(yyvsp + -0x7c));
        uVar64 = CONCAT44(yyvalNode,r4Out3);
        if (isMatrix != 0) {
          constantUnion = (**(code **)(**(int **)(yyvsp + -0x24) + 0x18))(*(int **)(yyvsp + -0x24));
          scratchR5 = *(char **)(yyvsp + -0x7c);
          scratchR6 = *(char **)(yyvsp + -0x58);
          uVar64 = TParseContext__addConstMatrixNode
                             (parseContext,**(int **)(constantUnion + 0x30),(unsigned char *)scratchR5,(int)scratchR6
                             );
        }
      }
      else {
        local_810 = (unsigned char *)0x1;
        constantUnion = (**(code **)(**(int **)(yyvsp + -0x24) + 0x18))(*(int **)(yyvsp + -0x24));
        local_820 = (unsigned char *)**(uint **)(constantUnion + 0x30);
        scratchR5 = *(char **)(yyvsp + -0x7c);
        scratchR6 = *(char **)(yyvsp + -0x58);
        uVar64 = TParseContext__addConstVectorNode
                           (parseContext,(unsigned char *)&local_820,(unsigned char *)scratchR5,(int)scratchR6
                            ,scratchR7,pTVar33);
      }
    }
    else {
      qualifier = (**(code **)(**(int **)(yyvsp + -0x24) + 0x44))(*(int **)(yyvsp + -0x24));
      if (qualifier == 2) {
        bVar37 = false;
        iVar55 = (**(code **)(**(int **)(yyvsp + -0x7c) + 0x58))(*(int **)(yyvsp + -0x7c));
        if ((iVar55 != 0) ||
           (iVar55 = (**(code **)(**(int **)(yyvsp + -0x7c) + 0x50))(*(int **)(yyvsp + -0x7c)),
           iVar55 != 0)) {
          (**(code **)(**(int **)(yyvsp + -0x7c) + 0x38))(&local_7e0,*(int **)(yyvsp + -0x7c));
          uVar57 = local_7bc << 0xd;
          uVar28 = local_7bc >> 0x13;
          iVar55 = (**(code **)(**(int **)(yyvsp + -0x24) + 0x18))(*(int **)(yyvsp + -0x24));
          uVar16 = r4Out4;
          if (((int)(uVar57 | uVar28) >> 0x18 <= **(int **)(iVar55 + 0x30)) &&
             (iVar55 = (**(code **)(**(int **)(yyvsp + -0x7c) + 0x54))(*(int **)(yyvsp + -0x7c))
             , uVar16 = r4Out5, iVar55 == 0)) {
            bVar37 = true;
          }
          local_7e0 = picBase2 + -0x610c;
          pTVar33 = picBase2;
          if (bVar37) {
            iVar55 = (**(code **)(**(int **)(yyvsp + -0x24) + 0x18))
                               (*(int **)(yyvsp + -0x24),uVar16,scratchR5,scratchR6,scratchR7,picBase2);
            pTVar33 = (unsigned char *)**(uint **)(iVar55 + 0x30);
            scratchR5 = "";
            scratchR6 = "[";
            scratchR7 = "field selection out of range \'%d\'";
            TParseContext__error
                      ((int)parseContext,*(char **)(yyvsp + -0x58),"","[",
                       "field selection out of range \'%d\'",pTVar33,pTVar34,scratchR10);
            TParseContext__recover(parseContext);
            uVar64 = CONCAT44(yyvalNode,r4Out6);
            goto LAB_97ba47fc;
          }
        }
        isArray = (**(code **)(**(int **)(yyvsp + -0x7c) + 0x54))(*(int **)(yyvsp + -0x7c));
        if (isArray != 0) {
          (**(code **)(**(int **)(yyvsp + -0x7c) + 0x38))(&local_7b0,*(int **)(yyvsp + -0x7c));
          typeVtable = picBase2 + -0x610c;
          local_7b0 = typeVtable;
          if (local_7ac == (char *)0x0) {
            pTVar7 = picBase2;
            (**(code **)(**(int **)(yyvsp + -0x7c) + 0x38))
                      (&local_780,*(int **)(yyvsp + -0x7c),scratchR5,scratchR6,scratchR7,picBase2);
            iVar55 = local_764;
            constantUnion2 = (**(code **)(**(int **)(yyvsp + -0x24) + 0x18))(*(int **)(yyvsp + -0x24));
            pTVar34 = (unsigned char *)(uint)(iVar55 <= **(int **)(constantUnion2 + 0x30));
            bVar37 = pTVar34 == (unsigned char *)0x0;
            if (bVar37) {
              local_780 = typeVtable;
              pTVar8 = (unsigned char *)
                       (**(code **)(**(int **)(yyvsp + -0x7c) + 0x28))
                                 (*(int **)(yyvsp + -0x7c),r4In1,scratchR5,scratchR6,scratchR7,pTVar7);
              pTVar12 = (unsigned char *)(**(code **)(**(int **)(yyvsp + -0x7c) + 0x3c))
                                           (*(int **)(yyvsp + -0x7c));
              pTVar33 = *(unsigned char **)(yyvsp + -0x58);
              iVar55 = 0;
            }
            else {
              local_780 = typeVtable;
              iVar55 = (**(code **)(**(int **)(yyvsp + -0x24) + 0x18))
                                 (*(int **)(yyvsp + -0x24),r4In1,scratchR5,scratchR6,scratchR7,pTVar7,
                                  pTVar34);
              piVar61 = *(int **)(iVar55 + 0x30);
              pTVar34 = (unsigned char *)**(undefined4 **)(yyvsp + -0x7c);
              pTVar8 = (unsigned char *)
                       (**(code **)(pTVar34 + 0x28))
                                 (*(undefined4 **)(yyvsp + -0x7c),r4In2,scratchR5,scratchR6,scratchR7,
                                  pTVar7,pTVar34);
              pTVar12 = (unsigned char *)(**(code **)(**(int **)(yyvsp + -0x7c) + 0x3c))
                                           (*(int **)(yyvsp + -0x7c));
              iVar55 = *piVar61;
              pTVar33 = *(unsigned char **)(yyvsp + -0x58);
            }
            arraySetMaxSizeResult = TParseContext__arraySetMaxSize
                               (parseContext,pTVar8,pTVar12,iVar55,(uint)!bVar37,(int)pTVar33);
            if (arraySetMaxSizeResult != 0) {
LAB_97ba475c:
              TParseContext__recover(parseContext);
            }
          }
          else {
            pTVar33 = picBase2;
            iVar55 = (**(code **)(**(int **)(yyvsp + -0x24) + 0x18))(*(int **)(yyvsp + -0x24));
            piVar61 = *(int **)(iVar55 + 0x30);
            (**(code **)(**(int **)(yyvsp + -0x7c) + 0x38))(&local_780,*(int **)(yyvsp + -0x7c))
            ;
            pTVar34 = (unsigned char *)(uint)(local_77c <= *piVar61);
            local_780 = typeVtable;
            if (pTVar34 != (unsigned char *)0x0) {
              iVar55 = (**(code **)(**(int **)(yyvsp + -0x24) + 0x18))
                                 (*(int **)(yyvsp + -0x24),r4In3,scratchR5,scratchR6,scratchR7,pTVar33,
                                  pTVar34);
              pTVar33 = (unsigned char *)**(uint **)(iVar55 + 0x30);
              TParseContext__error
                        ((int)parseContext,*(char **)(yyvsp + -0x58),"","[",
                         "array index out of range \'%d\'",pTVar33,pTVar34,scratchR10);
              goto LAB_97ba475c;
            }
          }
        }
        pTVar15 = *(unsigned char **)parseContext;
        uVar16 = 0x2d;
      }
      else {
        iVar55 = (**(code **)(**(int **)(yyvsp + -0x7c) + 0x54))(*(int **)(yyvsp + -0x7c),r4In0);
        if (iVar55 != 0) {
          (**(code **)(**(int **)(yyvsp + -0x7c) + 0x38))(&local_820,*(int **)(yyvsp + -0x7c));
          local_820 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
          if (local_81c == (unsigned char *)0x0) {
            TParseContext__error
                      ((int)parseContext,*(char **)(yyvsp + -0x58),"","[",
                       "array must be redeclared with a size before being indexed with a variable",
                       pTVar33,pTVar34,scratchR10);
            TParseContext__recover(parseContext);
          }
        }
        pTVar15 = *(unsigned char **)parseContext;
        uVar16 = 0x2e;
      }
      scratchR5 = *(char **)(yyvsp + -0x7c);
      scratchR6 = *(char **)(yyvsp + -0x24);
      scratchR7 = *(char **)(yyvsp + -0x58);
      uVar64 = TIntermediate__addIndex(pTVar15,uVar16,scratchR5,scratchR6,scratchR7);
    }
LAB_97ba47fc:
    yyvalNode = (unsigned char *)((ulonglong)uVar64 >> 0x20);
    resultNode = yyvalNode;
    if (yyvalNode == (unsigned char *)0x0) {
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      pcVar9 = (unsigned char *)TPoolAllocator__allocate(poolAllocator,4);
      *(undefined4 *)pcVar9 = 0;
      local_850 = picBase2 + -0x610c;
      local_82c = (unsigned char *)((uint)local_82c & 0x1ff | 0x4080800);
      local_84c = resultNode;
      local_848 = resultNode;
      local_844 = resultNode;
      local_840 = resultNode;
      local_83c = resultNode;
      local_838 = resultNode;
      local_834 = resultNode;
      local_830 = resultNode;
      pTVar15 = *(unsigned char **)parseContext;
      scratchR6 = *(char **)(yyvsp + -0x58);
      goto LAB_97ba7d0c;
    }
    iVar55 = (**(code **)(**(int **)(yyvsp + -0x7c) + 0x54))
                       (*(int **)(yyvsp + -0x7c),(int)uVar64,scratchR5,scratchR6,scratchR7,pTVar33,
                        pTVar34);
    cr0 = (iVar55 == 0) << 1;
    if (iVar55 == 0) {
      iVar55 = (**(code **)(**(int **)(yyvsp + -0x7c) + 0x50))(*(int **)(yyvsp + -0x7c));
      if (iVar55 != 0) {
        (**(code **)(**(int **)(yyvsp + -0x7c) + 0x38))(&local_850,*(int **)(yyvsp + -0x7c));
        typeVtable2 = picBase2 + -0x610c;
        pTVar33 = picBase2;
        local_850 = typeVtable2;
        if ((uint)local_82c >> 0x19 == 2) {
          uVar57 = (**(code **)(**(int **)(yyvsp + -0x7c) + 0x40))
                             (*(int **)(yyvsp + -0x7c),r4In4,scratchR5,scratchR6,scratchR7,picBase2);
          uVar28 = (**(code **)(**(int **)(yyvsp + -0x7c) + 0x48))(*(int **)(yyvsp + -0x7c));
          local_7fc = (unsigned char *)
                      ((uVar28 & 0xff) << 0xb |
                      (uVar57 & 0x3f) << 0x13 | (uint)local_7fc & 0x1ff | 0x4000000);
          local_800 = (unsigned char *)0x0;
          goto LAB_97ba4bc0;
        }
      }
      pTVar3 = (unsigned char *)
               (**(code **)(**(int **)(yyvsp + -0x7c) + 0x50))(*(int **)(yyvsp + -0x7c));
      cr0 = (pTVar3 == (unsigned char *)0x0) << 1;
      if (pTVar3 != (unsigned char *)0x0) {
        uVar57 = (**(code **)(**(int **)(yyvsp + -0x7c) + 0x40))(*(int **)(yyvsp + -0x7c));
        uVar28 = (**(code **)(**(int **)(yyvsp + -0x7c) + 0x48))(*(int **)(yyvsp + -0x7c));
        local_800 = (unsigned char *)0x0;
        typeVtable2 = picBase2 + -0x610c;
        local_7fc = (unsigned char *)
                    ((uVar28 & 0xff) << 0xb | (uVar57 & 0x3f) << 0x13 | (uint)local_7fc & 0x1ff);
        local_81c = (unsigned char *)0x0;
        local_818 = (unsigned char *)0x0;
        local_814 = (unsigned char *)0x0;
        local_810 = (unsigned char *)0x0;
        local_80c = (unsigned char *)0x0;
        local_808 = (unsigned char *)0x0;
        local_804 = (unsigned char *)0x0;
        local_820 = typeVtable2;
        (**(code **)(*(unsigned char **)yyvalNode + 0x34))(yyvalNode,&local_820);
        pTVar3 = yyvalNode;
        local_820 = typeVtable2;
        pTVar31 = local_7f0;
        pTVar32 = local_750[0];
        break;
      }
      iVar55 = (**(code **)(**(int **)(yyvsp + -0x7c) + 0x58))(*(int **)(yyvsp + -0x7c));
      if (iVar55 != 0) {
        (**(code **)(**(int **)(yyvsp + -0x7c) + 0x38))(&local_820,*(int **)(yyvsp + -0x7c));
        pTVar31 = picBase2 + -0x610c;
        pTVar33 = picBase2;
        local_820 = pTVar31;
        if ((uint)local_7fc >> 0x19 == 2) {
          uVar57 = (**(code **)(**(int **)(yyvsp + -0x7c) + 0x40))
                             (*(int **)(yyvsp + -0x7c),r4In5,scratchR5,scratchR6,scratchR7,picBase2);
          local_7cc = (uVar57 & 0x3f) << 0x13 | local_7cc & 0x9ff | 0x4000000 | 0x800;
          local_7f0 = pTVar31;
          local_7ec = pTVar3;
          local_7e8 = pTVar3;
          local_7e4 = pTVar3;
          local_7e0 = pTVar3;
          local_7dc = pTVar3;
          local_7d8 = pTVar3;
          local_7d4 = pTVar3;
          local_7d0 = pTVar3;
          (**(code **)(*(unsigned char **)yyvalNode + 0x34))(yyvalNode,&local_7f0);
          pTVar3 = yyvalNode;
          pTVar32 = local_750[0];
          break;
        }
      }
      iVar55 = (**(code **)(**(int **)(yyvsp + -0x7c) + 0x58))(*(int **)(yyvsp + -0x7c));
      if (iVar55 == 0) {
        (**(code **)(**(int **)(yyvsp + -0x7c) + 0x38))(&local_7f0,*(int **)(yyvsp + -0x7c));
        (**(code **)(*(unsigned char **)yyvalNode + 0x34))(yyvalNode,&local_7f0);
        pTVar3 = yyvalNode;
        pTVar31 = picBase2 + -0x610c;
        pTVar32 = local_750[0];
      }
      else {
        uVar57 = (**(code **)(**(int **)(yyvsp + -0x7c) + 0x40))(*(int **)(yyvsp + -0x7c));
        pTVar31 = picBase2 + -0x610c;
        local_7cc = (uVar57 & 0x3f) << 0x13 | local_7cc & 0x9ff | 0x800;
        local_7ec = (unsigned char *)0x0;
        local_7e8 = (unsigned char *)0x0;
        local_7e4 = (unsigned char *)0x0;
        local_7e0 = (unsigned char *)0x0;
        local_7dc = (unsigned char *)0x0;
        local_7d8 = (unsigned char *)0x0;
        local_7d4 = (unsigned char *)0x0;
        local_7d0 = (unsigned char *)0x0;
        local_7f0 = pTVar31;
        (**(code **)(*(unsigned char **)yyvalNode + 0x34))
                  (yyvalNode,&local_7f0,scratchR5,scratchR6,scratchR7,pTVar33,*(unsigned char **)yyvalNode)
        ;
        pTVar3 = yyvalNode;
        pTVar32 = local_750[0];
      }
      break;
    }
    (**(code **)(**(int **)(yyvsp + -0x7c) + 0x38))(&local_850,*(int **)(yyvsp + -0x7c));
    pTVar3 = local_848;
    typeVtable2 = picBase2 + -0x610c;
    local_850 = typeVtable2;
    if (local_848 == (unsigned char *)0x0) {
      uVar57 = (**(code **)(**(int **)(yyvsp + -0x7c) + 0x40))(*(int **)(yyvsp + -0x7c));
      uVar28 = (**(code **)(**(int **)(yyvsp + -0x7c) + 0x48))(*(int **)(yyvsp + -0x7c));
      uVar53 = (**(code **)(**(int **)(yyvsp + -0x7c) + 0x50))(*(int **)(yyvsp + -0x7c));
      local_7fc = (unsigned char *)
                  ((uVar53 & 1) << 10 |
                  (uVar28 & 0xff) << 0xb | (uVar57 & 0x3f) << 0x13 | (uint)local_7fc & 0x1ff);
      local_800 = pTVar3;
LAB_97ba4bc0:
      local_820 = typeVtable2;
      local_81c = local_800;
      local_818 = local_800;
      local_814 = local_800;
      local_810 = local_800;
      local_80c = local_800;
      local_808 = local_800;
      local_804 = local_800;
      (**(code **)(*(unsigned char **)yyvalNode + 0x34))(yyvalNode,&local_820);
      pTVar3 = yyvalNode;
      local_820 = typeVtable2;
      pTVar31 = local_7f0;
      pTVar32 = local_750[0];
      break;
    }
    picBase = (unsigned char *)0xa7b8374c;
    (**(code **)(**(int **)(yyvsp + -0x7c) + 0x38))
              (&local_7f0,*(int **)(yyvsp + -0x7c),scratchR5,scratchR6,scratchR7,picBase2,0xa7b8374c);
    pTVar3 = local_7e8;
    (**(code **)(**(int **)(yyvsp + -0x7c) + 0x38))(local_750,*(int **)(yyvsp + -0x7c));
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_((unsigned char *)&local_7c0,local_740);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&local_7b0,(unsigned char *)&local_7c0);
    local_7fc = (unsigned char *)((uint)local_7fc & 0x9ff | 0x700800);
    local_800 = (unsigned char *)0x0;
    local_81c = (unsigned char *)0x0;
    local_818 = pTVar3;
    local_814 = (unsigned char *)0x0;
    local_80c = (unsigned char *)0x0;
    local_804 = (unsigned char *)0x0;
    local_820 = typeVtable2;
    setStructSizeResult = (unsigned char *)TType__setStructSize((unsigned char *)&local_820,(unsigned char *)pTVar3);
    pcVar62 = local_7ac;
    local_7ac[*(int *)(local_7ac + -0xc)] = **(char **)(picBase + -0x7cc4);
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    pTVar7 = (unsigned char *)TPoolAllocator__allocate(poolAllocator,8);
    cr0 = (pTVar7 == (unsigned char *)0x0) << 1;
    pTVar3 = (unsigned char *)0x0;
    if (pTVar7 != (unsigned char *)0x0) {
      ctorAlloc1[0] = GetGlobalPoolAllocator();
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                (pTVar7,pcVar62,(unsigned char *)ctorAlloc1);
      pTVar3 = pTVar7;
    }
    refCountPtr2 = (int *)(local_7ac + -4);
    destroyAlloc1[0] = local_7b0;
    do {
      oldRefCount4 = *refCountPtr2;
      if (reservation != '\0') {
        newRefCount4 = storeWordConditionalIndexed(oldRefCount4 + -1,0,refCountPtr2);
        *refCountPtr2 = newRefCount4;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    local_810 = pTVar3;
    if (oldRefCount4 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_7ac + -0xc),destroyAlloc1);
    }
    (**(code **)(*(unsigned char **)yyvalNode + 0x34))(yyvalNode,(unsigned char *)&local_820);
    pTVar31 = picBase2 + -0x610c;
    destroyAlloc2[0] = local_7c0;
    refCountPtr2 = (int *)(local_7bc - 4);
    do {
      oldRefCount4 = *refCountPtr2;
      if (reservation != '\0') {
        newRefCount4 = storeWordConditionalIndexed(oldRefCount4 + -1,0,refCountPtr2);
        *refCountPtr2 = newRefCount4;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    pTVar3 = yyvalNode;
    local_820 = pTVar31;
    pTVar32 = pTVar31;
    if (oldRefCount4 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_7bc - 0xc),destroyAlloc2);
      pTVar3 = yyvalNode;
    }
    break;
  case 10:
    iVar55 = (**(code **)(**(int **)(yyvsp + -0x50) + 0x54))
                       (*(int **)(yyvsp + -0x50),scratchR4,scratchR5,scratchR6,scratchR7,pTVar33);
    if (iVar55 != 0) {
      scratchR5 = "cannot apply dot operator to an array";
      scratchR6 = ".";
      scratchR7 = "";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp,"cannot apply dot operator to an array",".","",
                 pTVar33,pTVar34,scratchR10);
      TParseContext__recover(parseContext);
    }
    pTVar3 = (unsigned char *)
             (**(code **)(**(int **)(yyvsp + -0x50) + 0x58))(*(int **)(yyvsp + -0x50));
    cr0 = (pTVar3 == (unsigned char *)0x0) << 1;
    if (pTVar3 == (unsigned char *)0x0) {
      iVar55 = (**(code **)(**(int **)(yyvsp + -0x50) + 0x50))
                         (*(int **)(yyvsp + -0x50),r4In6,scratchR5,scratchR6,scratchR7,pTVar33,pTVar34);
      if (iVar55 == 0) {
        basicType = (**(code **)(**(int **)(yyvsp + -0x50) + 0x40))(*(int **)(yyvsp + -0x50));
        if (basicType != 0xe) {
          scratchR10 = *(uint *)(yyvsp + 4);
          pTVar34 = *(unsigned char **)(scratchR10 + 4);
          pcVar62 = " field selection requires structure, vector, or matrix on left hand side";
          goto LAB_97ba5784;
        }
        picBase2 = (unsigned char *)0xa7b8374c;
        (**(code **)(**(int **)(yyvsp + -0x50) + 0x38))(&local_850,*(int **)(yyvsp + -0x50));
        pTVar7 = local_848;
        local_850 = picBase2 + -0x610c;
        pTVar33 = picBase2;
        if (local_848 == (unsigned char *)0x0) {
          pcVar29 = *(char **)(yyvsp + -0x2c);
          pcVar62 = "structure has no fields";
          scratchR6 = "Internal Error";
          goto LAB_97ba5548;
        }
        loopIndex = 0;
        uVar16 = r4Out7;
        goto LAB_97ba55dc;
      }
      nominalSize = (**(code **)(**(int **)(yyvsp + -0x50) + 0x48))(*(int **)(yyvsp + -0x50));
      parseMatrixFieldsResult = TParseContext__parseMatrixFields
                         (parseContext,*(unsigned char **)(yyvsp + 4),nominalSize,(unsigned char *)&local_850,
                          *(uint *)yyvsp);
      if (parseMatrixFieldsResult == 0) {
        local_850 = pTVar3;
        local_84c = pTVar3;
        local_848 = pTVar3;
        local_844 = pTVar3;
        TParseContext__recover(parseContext);
      }
      pTVar7 = local_84c;
      if ((local_850 == (unsigned char *)0x0) && (local_84c == (unsigned char *)0x0)) {
        poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
        pcVar9 = (unsigned char *)TPoolAllocator__allocate(poolAllocator,4);
        picBase2 = (unsigned char *)0xa7b8374c;
        nominalSize = (**(code **)(**(int **)(yyvsp + -0x50) + 0x48))(*(int **)(yyvsp + -0x50));
        typeVtable3 = picBase2 + -0x610c;
        *(unsigned char **)pcVar9 = local_848 + (int)local_844 * nominalSize;
        local_81c = (unsigned char *)((uint)local_81c & 0x1ff | 0x4100800);
        local_83c = pTVar7;
        local_838 = pTVar7;
        local_834 = pTVar7;
        local_830 = pTVar7;
        local_82c = pTVar7;
        local_828 = pTVar7;
        local_824 = pTVar7;
        local_820 = pTVar7;
        local_840 = typeVtable3;
        scratchR6 = (char *)TIntermediate__addConstantUnion
                                    (*(unsigned char **)parseContext,pcVar9,(unsigned char *)&local_840,
                                     *(uint *)yyvsp);
        scratchR7 = *(char **)(yyvsp + -0x2c);
        local_840 = typeVtable3;
        yyvalNode = (unsigned char *)
                    TIntermediate__addIndex
                              (*(unsigned char **)parseContext,0x2d,*(uint *)(yyvsp + -0x50),scratchR6,
                               scratchR7);
        basicType2 = (**(code **)(**(int **)(yyvsp + -0x50) + 0x40))(*(int **)(yyvsp + -0x50));
        local_81c = (unsigned char *)((basicType2 & 0x3f) << 0x13 | (uint)local_81c & 0x1ff | 0x800);
        local_83c = pTVar7;
        local_838 = pTVar7;
        local_834 = pTVar7;
        local_830 = pTVar7;
        local_82c = pTVar7;
        local_828 = pTVar7;
        local_824 = pTVar7;
        local_820 = pTVar7;
        local_840 = typeVtable3;
        (**(code **)(*(uint *)yyvalNode + 0x34))(yyvalNode,(unsigned char *)&local_840);
        pTVar3 = yyvalNode;
        local_840 = typeVtable3;
        pTVar31 = local_7f0;
        pTVar32 = local_750[0];
      }
      else {
        TParseContext__error
                  ((int)parseContext,*(char **)(yyvsp + -0x2c)," non-scalar fields not implemented yet"
                   ,".","",pTVar33,pTVar34,scratchR10);
        TParseContext__recover(parseContext);
        poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
        pcVar9 = (unsigned char *)TPoolAllocator__allocate(poolAllocator,4);
        *(undefined4 *)pcVar9 = 0;
        local_81c = (unsigned char *)((uint)local_81c & 0x9ff | 0x4100800);
        local_840 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
        local_83c = pTVar3;
        local_838 = pTVar3;
        local_834 = pTVar3;
        local_830 = pTVar3;
        local_82c = pTVar3;
        local_828 = pTVar3;
        local_824 = pTVar3;
        local_820 = pTVar3;
        scratchR6 = (char *)TIntermediate__addConstantUnion
                                    (*(unsigned char **)parseContext,pcVar9,(unsigned char *)&local_840,
                                     *(uint *)yyvsp);
        local_840 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
        scratchR7 = *(char **)(yyvsp + -0x2c);
        yyvalNode = (unsigned char *)
                    TIntermediate__addIndex
                              (*(unsigned char **)parseContext,0x2d,*(uint *)(yyvsp + -0x50),scratchR6,
                               scratchR7);
        basicType2 = (**(code **)(**(int **)(yyvsp + -0x50) + 0x40))(*(int **)(yyvsp + -0x50));
        nominalSize2 = (**(code **)(**(int **)(yyvsp + -0x50) + 0x48))(*(int **)(yyvsp + -0x50));
        local_81c = (unsigned char *)
                    ((nominalSize2 & 0xff) << 0xb | (basicType2 & 0x3f) << 0x13 | (uint)local_81c & 0x1ff);
        local_840 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
        local_83c = pTVar3;
        local_838 = pTVar3;
        local_834 = pTVar3;
        local_830 = pTVar3;
        local_82c = pTVar3;
        local_828 = pTVar3;
        local_824 = pTVar3;
        local_820 = pTVar3;
        (**(code **)(*(uint *)yyvalNode + 0x34))(yyvalNode,(unsigned char *)&local_840);
        local_840 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
        pTVar3 = yyvalNode;
        pTVar31 = local_7f0;
        pTVar32 = local_750[0];
      }
      break;
    }
    nominalSize = (**(code **)(**(int **)(yyvsp + -0x50) + 0x48))(*(int **)(yyvsp + -0x50));
    scratchR7 = *(char **)yyvsp;
    parseVectorFieldsResult = (unsigned char *)
             TParseContext__parseVectorFields
                       (parseContext,*(unsigned char **)(yyvsp + 4),nominalSize,(unsigned char *)&local_850,
                        (int)scratchR7);
    cr0 = (parseVectorFieldsResult == (unsigned char *)0x0) << 1;
    if (parseVectorFieldsResult == (unsigned char *)0x0) {
      local_840 = (unsigned char *)0x1;
      local_850 = parseVectorFieldsResult;
      TParseContext__recover(parseContext);
    }
    picBase2 = (unsigned char *)0xa7b8374c;
    (**(code **)(**(int **)(yyvsp + -0x50) + 0x38))(&local_830,*(int **)(yyvsp + -0x50));
    typeVtable2 = picBase2 + -0x610c;
    pTVar3 = picBase2;
    local_830 = typeVtable2;
    if ((uint)local_80c >> 0x19 == 2) {
      pTVar33 = *(unsigned char **)(yyvsp + -0x50);
      scratchR6 = *(char **)yyvsp;
      yyvalNode = (unsigned char *)
                  TParseContext__addConstVectorNode
                            (parseContext,(unsigned char *)&local_850,pTVar33,(int)scratchR6,scratchR7,
                             picBase2);
      if (yyvalNode == (unsigned char *)0x0) goto LAB_97ba5554;
      basicType2 = (**(code **)(**(int **)(yyvsp + -0x50) + 0x40))(*(int **)(yyvsp + -0x50));
      local_7dc = (unsigned char *)
                  ((*(uint *)(*(int *)(*(uint *)(yyvsp + 4) + 4) + -0xc) & 0xff) << 0xb |
                  (basicType2 & 0x3f) << 0x13 | (uint)local_7dc & 0x1ff | 0x4000000);
      pTVar32 = *(unsigned char **)(*(unsigned char **)yyvalNode + 0x34);
      pTVar31 = *(unsigned char **)yyvalNode;
LAB_97ba50cc:
      local_7e0 = (unsigned char *)0x0;
      local_7e4 = (unsigned char *)0x0;
      local_7e8 = (unsigned char *)0x0;
      local_7ec = (unsigned char *)0x0;
      local_7f0 = (unsigned char *)0x0;
      local_7f4 = (unsigned char *)0x0;
      local_7f8 = (unsigned char *)0x0;
      local_7fc = (unsigned char *)0x0;
      local_800 = typeVtable2;
      (*(code *)pTVar32)(yyvalNode,&local_800,pTVar33,scratchR6,scratchR7,pTVar3,pTVar31);
      pTVar3 = yyvalNode;
      local_800 = typeVtable2;
      pTVar31 = local_7f0;
      pTVar32 = local_750[0];
      break;
    }
    if (local_840 == (unsigned char *)0x1) {
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      pcVar9 = (unsigned char *)TPoolAllocator__allocate(poolAllocator,4);
      *(unsigned char **)pcVar9 = local_850;
      local_7dc = (unsigned char *)((uint)local_7dc & 0x1ff | 0x4100800);
      local_7fc = (unsigned char *)0x0;
      local_7f8 = (unsigned char *)0x0;
      local_7f4 = (unsigned char *)0x0;
      local_7f0 = (unsigned char *)0x0;
      local_7ec = (unsigned char *)0x0;
      local_7e8 = (unsigned char *)0x0;
      local_7e4 = (unsigned char *)0x0;
      local_7e0 = (unsigned char *)0x0;
      local_800 = typeVtable2;
      scratchR6 = (char *)TIntermediate__addConstantUnion
                                  (*(unsigned char **)parseContext,pcVar9,(unsigned char *)&local_800,
                                   *(uint *)yyvsp);
      pTVar33 = *(unsigned char **)(yyvsp + -0x50);
      scratchR7 = *(char **)(yyvsp + -0x2c);
      local_800 = typeVtable2;
      yyvalNode = (unsigned char *)
                  TIntermediate__addIndex(*(unsigned char **)parseContext,0x2d,pTVar33,scratchR6,scratchR7);
      uVar57 = (**(code **)(**(int **)(yyvsp + -0x50) + 0x40))(*(int **)(yyvsp + -0x50));
      local_7dc = (unsigned char *)((uVar57 & 0x3f) << 0x13 | (uint)local_7dc & 0x1ff | 0x800);
      pTVar32 = *(unsigned char **)(*(unsigned char **)yyvalNode + 0x34);
      pTVar31 = yyvalNode;
      goto LAB_97ba50cc;
    }
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&local_800,*(unsigned char **)(yyvsp + 4));
    scratchR6 = (char *)TIntermediate__addSwizzle
                                (*(unsigned char **)parseContext,(unsigned char *)&local_850,
                                 *(uint *)yyvsp);
    uVar28 = *(uint *)(yyvsp + -0x50);
    scratchR7 = *(char **)(yyvsp + -0x2c);
    yyvalNode = (unsigned char *)
                TIntermediate__addIndex(*(unsigned char **)parseContext,0x30,uVar28,scratchR6,scratchR7);
    pTVar33 = *(unsigned char **)yyvalNode;
    uVar57 = (**(code **)(**(int **)(yyvsp + -0x50) + 0x40))(*(int **)(yyvsp + -0x50));
    local_7cc = (*(uint *)(local_7fc + -0xc) & 0xff) << 0xb |
                (uVar57 & 0x3f) << 0x13 | local_7cc & 0x1ff;
    local_7d0 = (unsigned char *)0x0;
    local_7ec = (unsigned char *)0x0;
    local_7e8 = (unsigned char *)0x0;
    local_7e4 = (unsigned char *)0x0;
    local_7e0 = (unsigned char *)0x0;
    local_7dc = (unsigned char *)0x0;
    local_7d8 = (unsigned char *)0x0;
    local_7d4 = (unsigned char *)0x0;
    local_7f0 = typeVtable2;
    (**(code **)(pTVar33 + 0x34))
              (yyvalNode,&local_7f0,uVar28,scratchR6,scratchR7,pTVar3,*(uint *)(local_7fc + -0xc));
    refCountPtr = local_7fc + -4;
    destroyAlloc3[0] = local_800;
    paVar11 = (unsigned char *)(local_7fc + -0xc);
    do {
      oldRefCount = *(uint *)refCountPtr;
      if (reservation != '\0') {
        newRefCount = storeWordConditionalIndexed(oldRefCount - 1,0,refCountPtr);
        *(uint *)refCountPtr = newRefCount;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    bVar37 = 0 < (int)oldRefCount;
    ppTVar24 = destroyAlloc3;
    local_7f0 = typeVtable2;
    goto LAB_97ba869c;
  case 0xb:
    lValueError = TParseContext__lValueErrorCheck
                       (parseContext,*(uint *)yyvsp,"++",*(unsigned char **)(yyvsp + -0x24),scratchR7,
                        pTVar33,pTVar34,scratchR10);
    if (lValueError != 0) {
      TParseContext__recover(parseContext);
    }
    scratchR6 = *(char **)yyvsp;
    scratchR7 = *(char **)((int)parseContext + 4);
    yyvalNode = (unsigned char *)
                TIntermediate__addUnaryMath
                          (*(unsigned char **)parseContext,9,*(uint *)(yyvsp + -0x24),scratchR6,scratchR7,
                           pTVar33,pTVar34);
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (yyvalNode != (unsigned char *)0x0) break;
    scratchR6 = (char *)&local_850;
    TType__getCompleteString(scratchR6,*(uint *)(yyvsp + -0x24) + 8);
    TParseContext__unaryOpError(parseContext,*(uint *)yyvsp,"++",scratchR6);
    refCountPtr = local_84c + -4;
    destroyAlloc4[0] = local_850;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    if ((int)oldRefCount2 < 1) {
      ppTVar24 = destroyAlloc4;
LAB_97ba5844:
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_84c + -0xc),ppTVar24);
    }
    goto LAB_97ba5848;
  case 0xc:
    lValueError = TParseContext__lValueErrorCheck
                       (parseContext,*(uint *)yyvsp,"--",*(unsigned char **)(yyvsp + -0x24),scratchR7,
                        pTVar33,pTVar34,scratchR10);
    if (lValueError != 0) {
      TParseContext__recover(parseContext);
    }
    scratchR6 = *(char **)yyvsp;
    scratchR7 = *(char **)((int)parseContext + 4);
    yyvalNode = (unsigned char *)
                TIntermediate__addUnaryMath
                          (*(unsigned char **)parseContext,10,*(uint *)(yyvsp + -0x24),scratchR6,scratchR7,
                           pTVar33,pTVar34);
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (yyvalNode != (unsigned char *)0x0) break;
    scratchR6 = (char *)&local_850;
    TType__getCompleteString(scratchR6,*(uint *)(yyvsp + -0x24) + 8);
    TParseContext__unaryOpError(parseContext,*(uint *)yyvsp,"--",scratchR6);
    refCountPtr = local_84c + -4;
    destroyAlloc5[0] = local_850;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    ppTVar24 = destroyAlloc5;
    if ((int)oldRefCount2 < 1) goto LAB_97ba5844;
LAB_97ba5848:
    TParseContext__recover(parseContext);
switchD_97ba39c8_caseD_6:
    pTVar3 = *(unsigned char **)(yyvsp + -0x24);
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0xd:
    iVar55 = TParseContext__integerErrorCheck(parseContext,*(unsigned char **)(yyvsp + 8),"[]");
    goto LAB_97ba82e8;
  case 0xe:
    stackNode = *(unsigned char **)(yyvsp + 0x10);
    pTVar3 = *(unsigned char **)(stackNode + 0x4c);
    if (pTVar3 != (unsigned char *)0x0) {
      picBase2 = (unsigned char *)0xa7b8374c;
      local_830 = (unsigned char *)0x0;
      local_82c = (unsigned char *)((uint)local_82c & 0x9ff | 0x800);
      cr0 = (local_82c == (unsigned char *)0x0) << 1;
      local_850 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
      local_84c = (unsigned char *)0x0;
      local_848 = (unsigned char *)0x0;
      local_844 = (unsigned char *)0x0;
      local_840 = (unsigned char *)0x0;
      local_83c = (unsigned char *)0x0;
      local_838 = (unsigned char *)0x0;
      local_834 = (unsigned char *)0x0;
      scratchR6 = (char *)stackNode;
      scratchR7 = (char *)pTVar3;
      constructorError = TParseContext__constructorErrorCheck
                         (parseContext,*(uint *)yyvsp,*(unsigned char **)(yyvsp + 8),stackNode,pTVar3,
                          (unsigned char *)&local_850);
      if (constructorError == 0) {
        scratchR6 = (char *)pTVar3;
        scratchR7 = (char *)stackNode;
        yyvalNode = (unsigned char *)
                    TParseContext__addConstructor
                              (parseContext,*(unsigned char **)(yyvsp + 8),(unsigned char *)&local_850,pTVar3,stackNode,
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
                              (*(unsigned char **)parseContext,(unsigned char *)0x0,pTVar3,scratchR6);
      }
      (**(code **)(*(unsigned char **)yyvalNode + 0x34))(yyvalNode,(unsigned char *)&local_850);
      local_850 = picBase2 + -0x610c;
      goto LAB_97ba5e28;
    }
    findFunctionResult = (unsigned char *)
             TParseContext__findFunction
                       (parseContext,*(uint *)yyvsp,stackNode,(bool *)&local_88,scratchR7,pTVar33);
    cr0 = (findFunctionResult == (unsigned char *)0x0) << 1;
    if (findFunctionResult == (unsigned char *)0x0) {
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      pcVar9 = (unsigned char *)TPoolAllocator__allocate(poolAllocator,4);
      *(undefined4 *)pcVar9 = 0;
      local_82c = (unsigned char *)((uint)local_82c & 0x1ff | 0x4080800);
      local_850 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
      scratchR6 = *(char **)yyvsp;
      local_84c = findFunctionResult;
      local_848 = findFunctionResult;
      local_844 = findFunctionResult;
      local_840 = findFunctionResult;
      local_83c = findFunctionResult;
      local_838 = findFunctionResult;
      local_834 = findFunctionResult;
      local_830 = findFunctionResult;
      yyvalNode = (unsigned char *)
                  TIntermediate__addConstantUnion
                            (*(unsigned char **)parseContext,pcVar9,(unsigned char *)&local_850,(int)scratchR6);
      local_850 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
      TParseContext__recover(parseContext);
      goto LAB_97ba5e28;
    }
    uVar57 = *(uint *)(findFunctionResult + 0x4c);
    if ((local_88 == 0) || (uVar57 == 0)) {
      pcVar62 = (char *)0x2;
      scratchR6 = *(char **)yyvsp;
      yyvalNode = (unsigned char *)
                  TIntermediate__setAggregateOperator
                            (*(unsigned char **)parseContext,*(unsigned char **)(yyvsp + 8),2,scratchR6);
      (**(code **)(*(unsigned char **)yyvalNode + 0x34))(yyvalNode,findFunctionResult + 0x1c);
      if (local_88 == 0) {
        piVar61 = (int *)(**(code **)(*(unsigned char **)yyvalNode + 0x1c))(yyvalNode);
        (**(code **)(*piVar61 + 0x70))(piVar61);
      }
      piVar61 = (int *)(**(code **)(*(unsigned char **)yyvalNode + 0x1c))(yyvalNode);
      iVar55 = *piVar61;
      uVar16 = (**(code **)(*(unsigned char **)findFunctionResult + 8))(findFunctionResult);
      (**(code **)(iVar55 + 0x68))(piVar61,uVar16);
      piVar61 = (int *)(**(code **)(*(unsigned char **)yyvalNode + 0x1c))(yyvalNode);
      this = (unsigned char *)(**(code **)(*piVar61 + 0x78))(piVar61);
      piVar61 = r4Out11;
      for (loopIndex2 = 0; loopIndex2 < (int)(*(uint *)(findFunctionResult + 0x14) - *(uint *)(findFunctionResult + 0x10)) >> 3;
          loopIndex2 = loopIndex2 + 1) {
        piVar50 = *(int **)(*(uint *)(findFunctionResult + 0x10) + loopIndex2 * 8 + 4);
        iVar54 = *piVar50;
        iVar54 = (**(code **)(iVar54 + 0x24))
                           (piVar50,piVar61,pcVar62,scratchR6,scratchR7,pTVar33,iVar54);
        if (iVar54 - 10U < 2) {
          piVar61 = (int *)(**(code **)(*(unsigned char **)yyvalNode + 0x1c))(yyvalNode);
          iVar60 = (**(code **)(*piVar61 + 100))(piVar61);
          iVar6 = *(int *)(iVar60 + 4);
          piVar61 = *(int **)(iVar6 + loopIndex2 * 4);
          scratchR6 = (char *)(**(code **)(*piVar61 + 0x14))
                                      (piVar61,r4In8,pcVar62,scratchR6,scratchR7,pTVar33,iVar6);
          iVar60 = (**(code **)*(unsigned char **)yyvalNode)(yyvalNode);
          pcVar62 = "assign";
          lValueError2 = TParseContext__lValueErrorCheck
                             (parseContext,iVar60,"assign",(unsigned char *)scratchR6,scratchR7,pTVar33,iVar6,
                              scratchR10);
          if (lValueError2 != 0) {
            pcVar29 = (char *)(**(code **)**(undefined4 **)(yyvsp + 8))
                                        (*(undefined4 **)(yyvsp + 8));
            pcVar62 = "Constant value cannot be passed for \'out\' or \'inout\' parameters.";
            scratchR6 = "Error";
            scratchR7 = "";
            TParseContext__error
                      ((int)parseContext,pcVar29,
                       "Constant value cannot be passed for \'out\' or \'inout\' parameters.",
                       "Error","",pTVar33,iVar6,scratchR10);
            TParseContext__recover(parseContext);
          }
        }
        piVar61 = *(int **)(this + 8);
        local_84 = iVar54;
        if (piVar61 == *(int **)(this + 0xc)) {
          pcVar62 = (char *)&local_84;
          std__vector_int_pool_allocator_int_____M_insert_aux(this,piVar61,pcVar62);
          piVar61 = r4Out12;
        }
        else {
          iVar60 = 0;
          if (piVar61 != (int *)0x0) {
            *piVar61 = iVar54;
            iVar60 = *(int *)(this + 8);
          }
          *(int *)(this + 8) = iVar60 + 4;
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
                              (*(unsigned char **)parseContext,uVar57,functionCallGenericNode,0,scratchR7,pTVar33,
                               *(uint *)(findFunctionResult + 0x10));
        if (yyvalNode != (unsigned char *)0x0) goto LAB_97ba5d80;
        picBase = (unsigned char *)0xa7b8374c;
        TType__getCompleteString(&local_850,*(uint *)(yyvsp + 8) + 8);
        pTVar33 = local_84c;
        local_84c[*(uint *)(local_84c + -0xc)] = **(unsigned char **)(picBase + -0x7cc4);
        pTVar3 = local_84c;
        pcVar62 = (char *)(**(code **)**(undefined4 **)(yyvsp + 8))
                                    (*(undefined4 **)(yyvsp + 8),r4In7,functionCallGenericNode,scratchR6,scratchR7,
                                     picBase,local_84c);
        scratchR5 = " wrong operand type";
        scratchR6 = "Internal Error";
        scratchR7 = "built in unary operator function.  Type: %s";
        TParseContext__error
                  ((int)parseContext,pcVar62," wrong operand type","Internal Error",
                   "built in unary operator function.  Type: %s",pTVar33,pTVar3,scratchR10);
        refCountPtr = local_84c + -4;
        destroyAlloc6[0] = local_850;
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
                    ((unsigned char *)(local_84c + -0xc),destroyAlloc6);
          scratchR4 = r4Out10;
        }
        goto LAB_97bac050;
      }
      scratchR6 = *(char **)yyvsp;
      yyvalNode = (unsigned char *)
                  TIntermediate__setAggregateOperator
                            (*(unsigned char **)parseContext,*(unsigned char **)(yyvsp + 8),uVar57,
                             scratchR6);
    }
LAB_97ba5d80:
    (**(code **)(*(unsigned char **)yyvalNode + 0x34))(yyvalNode,findFunctionResult + 0x1c);
LAB_97ba5e28:
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (stackNode != (unsigned char *)0x0) {
      iVar55 = *(int *)stackNode;
LAB_97ba86fc:
      (**(code **)(iVar55 + 4))(stackNode);
      pTVar3 = yyvalNode;
      pTVar31 = local_7f0;
      pTVar32 = local_750[0];
    }
    break;
  case 0xf:
  case 0x10:
    _memcpy(&yyval,yyvsp + -0x2c,0x2c);
    yyval = *(uint *)yyvsp;
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x11:
    yyvalTypeOrFunction = *(unsigned char **)(yyvsp + -0x1c);
    goto LAB_97ba5e64;
  case 0x12:
    yyvalTypeOrFunction = *(unsigned char **)(yyvsp + 0x10);
LAB_97ba5e64:
    pTVar3 = (unsigned char *)0x0;
    break;
  case 0x13:
    local_840 = (unsigned char *)0x0;
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    pTVar3 = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x28);
    (**(code **)(**(int **)(yyvsp + 8) + 0x38))(pTVar3,*(int **)(yyvsp + 8));
    local_850 = local_840;
    functionCallHeaderTypeOrFunction = *(uint *)(yyvsp + -0x1c);
    puVar18 = *(undefined4 **)(functionCallHeaderTypeOrFunction + 0x14);
    local_84c = pTVar3;
    local_83c = pTVar3;
    if (puVar18 == *(undefined4 **)(functionCallHeaderTypeOrFunction + 0x18)) {
      std__vector_TParameter_pool_allocator_TParameter_____M_insert_aux
                ((unsigned char *)(functionCallHeaderTypeOrFunction + 0xc),
                 *(undefined4 *)(functionCallHeaderTypeOrFunction + 0x14),&local_850);
    }
    else {
      iVar55 = 0;
      if (puVar18 != (undefined4 *)0x0) {
        puVar18[1] = pTVar3;
        *puVar18 = local_840;
        iVar55 = *(int *)(functionCallHeaderTypeOrFunction + 0x14);
      }
      *(int *)(functionCallHeaderTypeOrFunction + 0x14) = iVar55 + 8;
    }
    pTVar3 = local_84c;
    iVar55 = *(int *)(local_84c + 0x14);
    if (iVar55 == 0) {
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      newString = (unsigned char *)TPoolAllocator__allocate(poolAllocator,8);
      cr0 = (newString == (unsigned char *)0x0) << 1;
      psVar21 = (unsigned char *)0x0;
      if (newString != (unsigned char *)0x0) {
        ctorAlloc2[0] = GetGlobalPoolAllocator();
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_(newString,"",(unsigned char *)ctorAlloc2)
        ;
        psVar21 = newString;
      }
      *(unsigned char **)(pTVar3 + 0x14) = psVar21;
      ((int (*)())TType__buildMangledName)((unsigned char *)pTVar3,psVar21);
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEmc(*(void **)(pTVar3 + 0x14),1,0x3b);
      iVar55 = *(int *)(pTVar3 + 0x14);
    }
    __ZStplIcSt11char_traitsIcE14pool_allocatorIcEESbIT_T0_T1_ERKS7_S9_
              ((unsigned char *)&local_840,(unsigned char *)(functionCallHeaderTypeOrFunction + 0x44),iVar55);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6assignERKS3_
              ((unsigned char *)(functionCallHeaderTypeOrFunction + 0x44),(unsigned char *)&local_840);
    refCountPtr = local_83c + -4;
    destroyAlloc7[0] = local_840;
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
                ((unsigned char *)(local_83c + -0xc),destroyAlloc7);
    }
    yyvalTypeOrFunction = *(unsigned char **)(yyvsp + -0x1c);
    pTVar3 = *(unsigned char **)(yyvsp + 8);
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x14:
    local_840 = (unsigned char *)0x0;
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    pTVar3 = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x28);
    (**(code **)(**(int **)(yyvsp + 8) + 0x38))(pTVar3,*(int **)(yyvsp + 8));
    local_850 = local_840;
    functionCallHeaderWithParametersTypeOrFunction = *(uint *)(yyvsp + -0x48);
    puVar18 = *(undefined4 **)(functionCallHeaderWithParametersTypeOrFunction + 0x14);
    local_84c = pTVar3;
    local_83c = pTVar3;
    if (puVar18 == *(undefined4 **)(functionCallHeaderWithParametersTypeOrFunction + 0x18)) {
      std__vector_TParameter_pool_allocator_TParameter_____M_insert_aux
                ((unsigned char *)(functionCallHeaderWithParametersTypeOrFunction + 0xc),
                 *(undefined4 *)(functionCallHeaderWithParametersTypeOrFunction + 0x14),&local_850);
    }
    else {
      iVar55 = 0;
      if (puVar18 != (undefined4 *)0x0) {
        puVar18[1] = pTVar3;
        *puVar18 = local_840;
        iVar55 = *(int *)(functionCallHeaderWithParametersTypeOrFunction + 0x14);
      }
      *(int *)(functionCallHeaderWithParametersTypeOrFunction + 0x14) = iVar55 + 8;
    }
    pTVar3 = local_84c;
    iVar55 = *(int *)(local_84c + 0x14);
    if (iVar55 == 0) {
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      newString = (unsigned char *)TPoolAllocator__allocate(poolAllocator,8);
      cr0 = (newString == (unsigned char *)0x0) << 1;
      psVar21 = (unsigned char *)0x0;
      if (newString != (unsigned char *)0x0) {
        ctorAlloc3[0] = GetGlobalPoolAllocator();
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_(newString,"",(unsigned char *)ctorAlloc3)
        ;
        psVar21 = newString;
      }
      *(unsigned char **)(pTVar3 + 0x14) = psVar21;
      ((int (*)())TType__buildMangledName)((unsigned char *)pTVar3,psVar21);
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEmc(*(void **)(pTVar3 + 0x14),1,0x3b);
      iVar55 = *(int *)(pTVar3 + 0x14);
    }
    __ZStplIcSt11char_traitsIcE14pool_allocatorIcEESbIT_T0_T1_ERKS7_S9_
              ((unsigned char *)&local_840,(unsigned char *)(functionCallHeaderWithParametersTypeOrFunction + 0x44),iVar55);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6assignERKS3_
              ((unsigned char *)(functionCallHeaderWithParametersTypeOrFunction + 0x44),(unsigned char *)&local_840);
    refCountPtr = local_83c + -4;
    destroyAlloc8[0] = local_840;
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
                ((unsigned char *)(local_83c + -0xc),destroyAlloc8);
    }
    yyvalTypeOrFunction = *(unsigned char **)(yyvsp + -0x48);
    pTVar15 = *(unsigned char **)parseContext;
    pTVar22 = *(unsigned char **)(yyvsp + -0x50);
    pTVar20 = *(unsigned char **)(yyvsp + 8);
LAB_97ba97d4:
    scratchR6 = *(char **)(yyvsp + -0x2c);
LAB_97ba97d8:
    pTVar3 = (unsigned char *)TIntermediate__growAggregate(pTVar15,pTVar22,pTVar20,(int)scratchR6);
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x15:
    yyvalTypeOrFunction = *(unsigned char **)(yyvsp + -0x1c);
    break;
  case 0x16:
    if (*(uint *)(yyvsp + 4) != 0x75) {
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      newFunction = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x54);
      constructorIdentifierOp = *(uint *)(yyvsp + 4);
      puVar5 = PTR_vtable_a7b7c0f4 + 8;
      *(uint *)(newFunction + 4) = 0;
      *(undefined **)newFunction = puVar5;
      picBase2 = (unsigned char *)0xa7b8374c;
      allocatorArg1 = GetGlobalPoolAllocator();
      *(uint *)(newFunction + 0x18) = 0;
      *(uint *)(newFunction + 0x10) = 0;
      *(uint *)(newFunction + 0x14) = 0;
      *(unsigned char **)(newFunction + 0x1c) = picBase2 + -0x610c;
      *(uint *)(newFunction + 0xc) = allocatorArg1;
      iVar55 = DAT_a7b7ba84;
      *(uint *)(newFunction + 0x20) = 0;
      uVar57 = *(uint *)(newFunction + 0x40) & 0x9ff | 0x800;
      cr0 = (uVar57 == 0) << 1;
      *(uint *)(newFunction + 0x24) = 0;
      *(uint *)(newFunction + 0x40) = uVar57;
      piVar61 = (int *)(iVar55 + 8);
      *(uint *)(newFunction + 0x28) = 0;
      *(uint *)(newFunction + 0x2c) = 0;
      *(uint *)(newFunction + 0x30) = 0;
      *(uint *)(newFunction + 0x34) = 0;
      *(uint *)(newFunction + 0x38) = 0;
      *(uint *)(newFunction + 0x3c) = 0;
      do {
        if (reservation != '\0') {
          iVar54 = storeWordConditionalIndexed(*piVar61 + 1,0,piVar61);
          *piVar61 = iVar54;
          cr0 = 2;
        }
      } while (!(bool)(cr0 >> 1));
      allocatorArg2 = GetGlobalPoolAllocator();
      *(uint *)(newFunction + 0x48) = iVar55 + 0xc;
      *(uint *)(newFunction + 0x44) = allocatorArg2;
      *(uint *)(newFunction + 0x4c) = constructorIdentifierOp;
      *(uint *)(newFunction + 0x50) = 0;
      pTVar3 = yyvalNode;
      yyvalTypeOrFunction = newFunction;
      pTVar31 = local_7f0;
      pTVar32 = local_750[0];
      break;
    }
    ctorAlloc4[0] = GetGlobalPoolAllocator();
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
              ((unsigned char *)&local_850,"",(unsigned char *)ctorAlloc4);
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    newFunction = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x54);
    constructorIdentifierUserDef = *(uint *)(yyvsp + 0x24);
    constructorIdentifierOp2 = *(unsigned char **)(yyvsp + 4);
    *(unsigned char **)newFunction = (unsigned char *)(PTR_vtable_a7b7c0f4 + 8);
    *(unsigned char **)(newFunction + 4) = (unsigned char *)&local_850;
    local_660 = (unsigned char *)GetGlobalPoolAllocator();
    *(unsigned char **)(newFunction + 0x18) = (unsigned char *)0x0;
    *(unsigned char **)(newFunction + 0x10) = (unsigned char *)0x0;
    *(unsigned char **)(newFunction + 0x14) = (unsigned char *)0x0;
    picBase2 = (unsigned char *)0xa7b8374c;
    *(unsigned char **)(newFunction + 0xc) = local_660;
    pTVar59 = *(unsigned char **)(constructorIdentifierUserDef + 8);
    pTVar34 = *(unsigned char **)(constructorIdentifierUserDef + 0xc);
    pTVar32 = *(unsigned char **)(constructorIdentifierUserDef + 0x10);
    scratchR7 = *(char **)(constructorIdentifierUserDef + 0x14);
    scratchR6 = *(char **)(constructorIdentifierUserDef + 0x18);
    pTVar31 = *(unsigned char **)(constructorIdentifierUserDef + 0x1c);
    pTVar3 = *(unsigned char **)(constructorIdentifierUserDef + 4);
    pTVar33 = *(unsigned char **)(constructorIdentifierUserDef + 0x20);
    *(undefined ***)(newFunction + 0x1c) = &PTR___ZN5TTypeD1Ev_a7b7d640;
    *(unsigned char **)(newFunction + 0x20) = pTVar3;
    *(unsigned char **)(newFunction + 0x24) = pTVar59;
    *(unsigned char **)(newFunction + 0x28) = pTVar34;
    *(unsigned char **)(newFunction + 0x2c) = pTVar32;
    *(char **)(newFunction + 0x30) = scratchR7;
    *(char **)(newFunction + 0x34) = scratchR6;
    *(unsigned char **)(newFunction + 0x38) = pTVar31;
    *(unsigned char **)(newFunction + 0x3c) = pTVar33;
    pTVar3 = *(unsigned char **)(newFunction + 0x40);
    qualifierBits = *(uint *)(constructorIdentifierUserDef + 0x24) & 0xfe000000;
    *(unsigned char **)(newFunction + 0x40) = (unsigned char *)(qualifierBits | (uint)pTVar3 & 0x1ffffff);
    basicTypeBits = (*(uint *)(constructorIdentifierUserDef + 0x24) >> 0x13 & 0x3f) << 0x13;
    *(unsigned char **)(newFunction + 0x40) = (unsigned char *)(basicTypeBits | qualifierBits | (uint)pTVar3 & 0x7ffff);
    uVar57 = *(uint *)(constructorIdentifierUserDef + 0x24) & 0x7f800;
    *(unsigned char **)(newFunction + 0x40) =
         (unsigned char *)(uVar57 | basicTypeBits | qualifierBits | (uint)pTVar3 & 0x7ff);
    uVar58 = (*(uint *)(constructorIdentifierUserDef + 0x24) >> 10 & 1) << 10;
    *(unsigned char **)(newFunction + 0x40) =
         (unsigned char *)(uVar58 | uVar57 | basicTypeBits | qualifierBits | (uint)pTVar3 & 0x3ff);
    *(unsigned char **)(newFunction + 0x40) =
         (unsigned char *)
         ((*(uint *)(constructorIdentifierUserDef + 0x24) >> 9 & 1) << 9 |
         uVar58 | uVar57 | basicTypeBits | qualifierBits | (uint)pTVar3 & 0x1ff);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(newFunction + 0x44,(unsigned char *)&local_850);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEmc(newFunction + 0x44,1,0x28);
    *(unsigned char **)(newFunction + 0x4c) = constructorIdentifierOp2;
    *(unsigned char **)(newFunction + 0x50) = (unsigned char *)0x0;
    refCountPtr = local_84c + -4;
    destroyAlloc9[0] = local_850;
    paVar11 = (unsigned char *)(local_84c + -0xc);
    do {
      oldRefCount3 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount3 = (unsigned char *)storeWordConditionalIndexed(oldRefCount3 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount3;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    bVar37 = 0 < (int)oldRefCount3;
    ppTVar24 = destroyAlloc9;
    yyvalTypeOrFunction = newFunction;
    goto LAB_97ba869c;
  case 0x17:
    reservedError = TParseContext__reservedErrorCheck(parseContext,*(uint *)yyvsp,*(unsigned char **)(yyvsp + 4));
    if (reservedError != 0) {
      TParseContext__recover(parseContext);
    }
    local_82c = (unsigned char *)((uint)local_82c & 0x9ff | 0x800);
    cr0 = (local_82c == (unsigned char *)0x0) << 1;
    local_850 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
    local_84c = (unsigned char *)0x0;
    local_848 = (unsigned char *)0x0;
    local_844 = (unsigned char *)0x0;
    local_840 = (unsigned char *)0x0;
    local_83c = (unsigned char *)0x0;
    local_838 = (unsigned char *)0x0;
    local_834 = (unsigned char *)0x0;
    local_830 = (unsigned char *)0x0;
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
    *(unsigned char **)(newFunction + 0x20) = local_84c;
    *(unsigned char **)(newFunction + 0x24) = local_848;
    *(unsigned char **)(newFunction + 0x28) = local_844;
    *(unsigned char **)(newFunction + 0x2c) = local_840;
    *(unsigned char **)(newFunction + 0x30) = local_83c;
    *(unsigned char **)(newFunction + 0x34) = local_838;
    *(undefined ***)(newFunction + 0x1c) = &PTR___ZN5TTypeD1Ev_a7b7d640;
    *(unsigned char **)(newFunction + 0x38) = local_834;
    *(unsigned char **)(newFunction + 0x3c) = local_830;
    uVar2 = *(uint *)(newFunction + 0x40);
    qualifierBits = (uint)local_82c & 0xfe000000;
    *(uint *)(newFunction + 0x40) = qualifierBits | uVar2 & 0x1ffffff;
    basicTypeBits = ((uint)local_82c >> 0x13 & 0x3f) << 0x13;
    *(uint *)(newFunction + 0x40) = basicTypeBits | qualifierBits | uVar2 & 0x7ffff;
    uVar57 = (uint)local_82c & 0x7f800;
    *(uint *)(newFunction + 0x40) = uVar57 | basicTypeBits | qualifierBits | uVar2 & 0x7ff;
    uVar58 = ((uint)local_82c >> 10 & 1) << 10;
    *(uint *)(newFunction + 0x40) = uVar58 | uVar57 | basicTypeBits | qualifierBits | uVar2 & 0x3ff;
    *(uint *)(newFunction + 0x40) =
         ((uint)local_82c >> 9 & 1) << 9 | uVar58 | uVar57 | basicTypeBits | qualifierBits | uVar2 & 0x1ff;
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(newFunction + 0x44,identifierString2);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEmc(newFunction + 0x44,1,0x28);
    *(uint *)(newFunction + 0x50) = 0;
    *(uint *)(newFunction + 0x4c) = 0;
    pTVar3 = yyvalNode;
    yyvalTypeOrFunction = newFunction;
    local_850 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
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
                 "bvec2","","",pTVar34,scratchR10);
      TParseContext__recover(parseContext);
    }
    yyval = *(uint *)yyvsp;
    yyvalOp = 0x6c;
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x1f:
    if (1 < *(uint *)((int)parseContext + 0xc)) {
      scratchR7 = "";
      scratchR6 = "bvec3";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," supported in vertex/fragment shaders only ",
                 "bvec3","","",pTVar34,scratchR10);
      TParseContext__recover(parseContext);
    }
    yyval = *(uint *)yyvsp;
    yyvalOp = 0x6d;
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x20:
    if (1 < *(uint *)((int)parseContext + 0xc)) {
      scratchR7 = "";
      scratchR6 = "bvec4";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," supported in vertex/fragment shaders only ",
                 "bvec4","","",pTVar34,scratchR10);
      TParseContext__recover(parseContext);
    }
    yyval = *(uint *)yyvsp;
    yyvalOp = 0x6e;
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x21:
    if (1 < *(uint *)((int)parseContext + 0xc)) {
      scratchR7 = "";
      scratchR6 = "ivec2";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," supported in vertex/fragment shaders only ",
                 "ivec2","","",pTVar34,scratchR10);
      TParseContext__recover(parseContext);
    }
    yyval = *(uint *)yyvsp;
    yyvalOp = 0x6f;
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x22:
    if (1 < *(uint *)((int)parseContext + 0xc)) {
      scratchR7 = "";
      scratchR6 = "ivec3";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," supported in vertex/fragment shaders only ",
                 "ivec3","","",pTVar34,scratchR10);
      TParseContext__recover(parseContext);
    }
    yyval = *(uint *)yyvsp;
    yyvalOp = 0x70;
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x23:
    if (1 < *(uint *)((int)parseContext + 0xc)) {
      scratchR7 = "";
      scratchR6 = "ivec4";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," supported in vertex/fragment shaders only ",
                 "ivec4","","",pTVar34,scratchR10);
      TParseContext__recover(parseContext);
    }
    yyval = *(uint *)yyvsp;
    yyvalOp = 0x71;
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x24:
    if (1 < *(uint *)((int)parseContext + 0xc)) {
      scratchR7 = "";
      scratchR6 = "mat2";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," supported in vertex/fragment shaders only ","mat2"
                 ,"","",pTVar34,scratchR10);
      TParseContext__recover(parseContext);
    }
    yyval = *(uint *)yyvsp;
    yyvalOp = 0x72;
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x25:
    if (1 < *(uint *)((int)parseContext + 0xc)) {
      scratchR7 = "";
      scratchR6 = "mat3";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," supported in vertex/fragment shaders only ","mat3"
                 ,"","",pTVar34,scratchR10);
      TParseContext__recover(parseContext);
    }
    yyval = *(uint *)yyvsp;
    yyvalOp = 0x73;
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x26:
    if (1 < *(uint *)((int)parseContext + 0xc)) {
      scratchR7 = "";
      scratchR6 = "mat4";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," supported in vertex/fragment shaders only ","mat4"
                 ,"","",pTVar34,scratchR10);
      TParseContext__recover(parseContext);
    }
    yyval = *(uint *)yyvsp;
    yyvalOp = 0x74;
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x27:
    yyvalUserDef = (unsigned char *)(*(uint *)(yyvsp + 8) + 0xc);
    local_830 = (unsigned char *)0xe;
    local_824 = (unsigned char *)0x0;
    local_820 = (unsigned char *)0x0;
    yyvalQualifierOrParamType = (unsigned char *)
                (uint)((uint)((*(int **)((int)parseContext + 4))[1] - **(int **)((int)parseContext + 4) >> 2)
                      < 4);
    local_828 = (unsigned char *)0x1;
    yyvalTypeLine = *(unsigned char **)yyvsp;
    yyvalArray = (unsigned char *)0x0;
    local_844 = (unsigned char *)0x0;
    local_840 = (unsigned char *)0x0;
    yyvalMatrix = (unsigned char *)0x0;
    yyvalOp = 0x75;
    yyvalTypeOrFunction = (unsigned char *)0xe;
    yyvalSize = (unsigned char *)0x1;
    local_850 = (unsigned char *)0xe;
    local_848 = (unsigned char *)0x1;
    yyval = *(uint *)yyvsp;
    local_84c = yyvalQualifierOrParamType;
    local_83c = yyvalUserDef;
    local_838 = yyvalTypeLine;
    local_82c = yyvalQualifierOrParamType;
    local_81c = yyvalUserDef;
    local_818 = yyvalTypeLine;
    break;
  case 0x29:
    lValueError = TParseContext__lValueErrorCheck
                       (parseContext,*(uint *)(yyvsp + -0x2c),"++",*(unsigned char **)(yyvsp + 8),
                        scratchR7,pTVar33,pTVar34,scratchR10);
    if (lValueError != 0) {
      TParseContext__recover(parseContext);
    }
    scratchR6 = *(char **)(yyvsp + -0x2c);
    scratchR7 = *(char **)((int)parseContext + 4);
    yyvalNode = (unsigned char *)
                TIntermediate__addUnaryMath
                          (*(unsigned char **)parseContext,0xb,*(uint *)(yyvsp + 8),scratchR6,scratchR7,
                           pTVar33,pTVar34);
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (yyvalNode != (unsigned char *)0x0) break;
    scratchR6 = (char *)&local_850;
    TType__getCompleteString(scratchR6,*(uint *)(yyvsp + 8) + 8);
    TParseContext__unaryOpError(parseContext,*(uint *)(yyvsp + -0x2c),"++",scratchR6);
    refCountPtr = local_84c + -4;
    paVar11 = (unsigned char *)(local_84c + -0xc);
    destroyAlloc10[0] = local_850;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    bVar37 = 0 < (int)oldRefCount2;
    ppTVar24 = destroyAlloc10;
    goto LAB_97ba82d4;
  case 0x2a:
    lValueError = TParseContext__lValueErrorCheck
                       (parseContext,*(uint *)(yyvsp + -0x2c),"--",*(unsigned char **)(yyvsp + 8),
                        scratchR7,pTVar33,pTVar34,scratchR10);
    if (lValueError != 0) {
      TParseContext__recover(parseContext);
    }
    scratchR6 = *(char **)(yyvsp + -0x2c);
    scratchR7 = *(char **)((int)parseContext + 4);
    yyvalNode = (unsigned char *)
                TIntermediate__addUnaryMath
                          (*(unsigned char **)parseContext,0xc,*(uint *)(yyvsp + 8),scratchR6,scratchR7,
                           pTVar33,pTVar34);
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (yyvalNode != (unsigned char *)0x0) break;
    scratchR6 = (char *)&local_850;
    TType__getCompleteString(scratchR6,*(uint *)(yyvsp + 8) + 8);
    TParseContext__unaryOpError(parseContext,*(uint *)(yyvsp + -0x2c),"--",scratchR6);
    refCountPtr = local_84c + -4;
    paVar11 = (unsigned char *)(local_84c + -0xc);
    destroyAlloc11[0] = local_850;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    if ((int)oldRefCount2 < 1) {
      ppTVar24 = destroyAlloc11;
      goto LAB_97ba69a8;
    }
    goto LAB_97ba82f0;
  case 0x2b:
    if (*(uint *)(yyvsp + -0x28) == 0) goto switchD_97ba39c8_caseD_2;
    scratchR6 = *(char **)(yyvsp + -0x2c);
    scratchR7 = *(char **)((int)parseContext + 4);
    yyvalNode = (unsigned char *)
                TIntermediate__addUnaryMath
                          (*(unsigned char **)parseContext,*(uint *)(yyvsp + -0x28),
                           *(uint *)(yyvsp + 8),scratchR6,scratchR7,pTVar33,pTVar34);
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (yyvalNode != (unsigned char *)0x0) break;
    unaryOperatorOp = *(uint *)(yyvsp + -0x28);
    pcVar62 = "";
    if (unaryOperatorOp == 6) {
      pcVar62 = "!";
    }
    else if ((int)unaryOperatorOp < 7) {
      if (unaryOperatorOp == 5) {
        pcVar62 = "-";
      }
    }
    else if (unaryOperatorOp == 8) {
      pcVar62 = "~";
    }
    scratchR6 = (char *)&local_850;
    TType__getCompleteString(scratchR6,*(uint *)(yyvsp + 8) + 8);
    TParseContext__unaryOpError(parseContext,*(uint *)(yyvsp + -0x2c),pcVar62,scratchR6);
    refCountPtr = local_84c + -4;
    paVar11 = (unsigned char *)(local_84c + -0xc);
    destroyAlloc12[0] = local_850;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    bVar37 = 0 < (int)oldRefCount2;
    ppTVar24 = destroyAlloc12;
    goto LAB_97ba82d4;
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
                ((int)parseContext,*(char **)yyvsp," reserved for future use ","~","","",pTVar34,
                 scratchR10);
      TParseContext__recover(parseContext);
    }
    yyval = *(uint *)yyvsp;
    yyvalOp = 8;
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x31:
    if (1 < *(uint *)((int)parseContext + 0xc)) {
      TParseContext__error
                ((int)parseContext,*(char **)(yyvsp + -0x2c),
                 " supported in vertex/fragment shaders only ","*","","",pTVar34,scratchR10);
      TParseContext__recover(parseContext);
    }
    scratchR6 = *(char **)(yyvsp + 8);
    scratchR7 = *(char **)(yyvsp + -0x2c);
    yyvalNode = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(unsigned char **)parseContext,0x15,*(uint *)(yyvsp + -0x50),scratchR6,
                           scratchR7,*(undefined4 *)((int)parseContext + 4));
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (yyvalNode != (unsigned char *)0x0) break;
    scratchR7 = (char *)&local_850;
    scratchR6 = (char *)&local_840;
    TType__getCompleteString(scratchR7,*(uint *)(yyvsp + 8) + 8);
    TType__getCompleteString(scratchR6,*(uint *)(yyvsp + -0x50) + 8);
    TParseContext__binaryOpError(parseContext,*(uint *)(yyvsp + -0x2c),"*",scratchR6,scratchR7);
    refCountPtr = local_83c + -4;
    destroyAlloc13[0] = local_840;
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
                ((unsigned char *)(local_83c + -0xc),destroyAlloc13);
    }
    refCountPtr = local_84c + -4;
    paVar11 = (unsigned char *)(local_84c + -0xc);
    destroyAlloc14[0] = local_850;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    bVar37 = 0 < (int)oldRefCount2;
    ppTVar24 = destroyAlloc14;
    goto LAB_97ba7a00;
  case 0x32:
    if (1 < *(uint *)((int)parseContext + 0xc)) {
      TParseContext__error
                ((int)parseContext,*(char **)(yyvsp + -0x2c),
                 " supported in vertex/fragment shaders only ","/","","",pTVar34,scratchR10);
      TParseContext__recover(parseContext);
    }
    scratchR6 = *(char **)(yyvsp + 8);
    scratchR7 = *(char **)(yyvsp + -0x2c);
    yyvalNode = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(unsigned char **)parseContext,0x16,*(uint *)(yyvsp + -0x50),scratchR6,
                           scratchR7,*(undefined4 *)((int)parseContext + 4));
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (yyvalNode != (unsigned char *)0x0) break;
    scratchR7 = (char *)&local_850;
    scratchR6 = (char *)&local_840;
    TType__getCompleteString(scratchR7,*(uint *)(yyvsp + 8) + 8);
    TType__getCompleteString(scratchR6,*(uint *)(yyvsp + -0x50) + 8);
    TParseContext__binaryOpError(parseContext,*(uint *)(yyvsp + -0x2c),"/",scratchR6,scratchR7);
    refCountPtr = local_83c + -4;
    destroyAlloc15[0] = local_840;
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
                ((unsigned char *)(local_83c + -0xc),destroyAlloc15);
    }
    refCountPtr = local_84c + -4;
    paVar11 = (unsigned char *)(local_84c + -0xc);
    destroyAlloc16[0] = local_850;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    bVar37 = 0 < (int)oldRefCount2;
    ppTVar24 = destroyAlloc16;
    goto LAB_97ba7a00;
  case 0x33:
    if (1 < *(int *)((int)parseContext + 0xc) - 2U) {
      TParseContext__error
                ((int)parseContext,*(char **)(yyvsp + -0x2c)," reserved for future use ","%","","",
                 pTVar34,scratchR10);
      TParseContext__recover(parseContext);
    }
    scratchR6 = *(char **)(yyvsp + 8);
    scratchR7 = *(char **)(yyvsp + -0x2c);
    yyvalNode = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(unsigned char **)parseContext,0x17,*(uint *)(yyvsp + -0x50),scratchR6,
                           scratchR7,*(undefined4 *)((int)parseContext + 4));
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (yyvalNode != (unsigned char *)0x0) break;
    scratchR7 = (char *)&local_850;
    scratchR6 = (char *)&local_840;
    TType__getCompleteString(scratchR7,*(uint *)(yyvsp + 8) + 8);
    TType__getCompleteString(scratchR6,*(uint *)(yyvsp + -0x50) + 8);
    TParseContext__binaryOpError(parseContext,*(uint *)(yyvsp + -0x2c),"%",scratchR6,scratchR7);
    refCountPtr = local_83c + -4;
    destroyAlloc17[0] = local_840;
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
                ((unsigned char *)(local_83c + -0xc),destroyAlloc17);
    }
    refCountPtr = local_84c + -4;
    paVar11 = (unsigned char *)(local_84c + -0xc);
    destroyAlloc18[0] = local_850;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    bVar37 = 0 < (int)oldRefCount2;
    ppTVar24 = destroyAlloc18;
    goto LAB_97ba7a00;
  case 0x35:
    scratchR6 = *(char **)(yyvsp + 8);
    scratchR7 = *(char **)(yyvsp + -0x2c);
    yyvalNode = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(unsigned char **)parseContext,0x13,*(uint *)(yyvsp + -0x50),scratchR6,
                           scratchR7,*(undefined4 *)((int)parseContext + 4));
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (yyvalNode != (unsigned char *)0x0) break;
    scratchR7 = (char *)&local_850;
    scratchR6 = (char *)&local_840;
    TType__getCompleteString(scratchR7,*(uint *)(yyvsp + 8) + 8);
    TType__getCompleteString(scratchR6,*(uint *)(yyvsp + -0x50) + 8);
    TParseContext__binaryOpError(parseContext,*(uint *)(yyvsp + -0x2c),"+",scratchR6,scratchR7);
    refCountPtr = local_83c + -4;
    destroyAlloc19[0] = local_840;
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
                ((unsigned char *)(local_83c + -0xc),destroyAlloc19);
    }
    refCountPtr = local_84c + -4;
    paVar11 = (unsigned char *)(local_84c + -0xc);
    destroyAlloc20[0] = local_850;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    bVar37 = 0 < (int)oldRefCount2;
    ppTVar24 = destroyAlloc20;
    goto LAB_97ba7a00;
  case 0x36:
    scratchR6 = *(char **)(yyvsp + 8);
    scratchR7 = *(char **)(yyvsp + -0x2c);
    yyvalNode = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(unsigned char **)parseContext,0x14,*(uint *)(yyvsp + -0x50),scratchR6,
                           scratchR7,*(undefined4 *)((int)parseContext + 4));
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (yyvalNode != (unsigned char *)0x0) break;
    scratchR7 = (char *)&local_850;
    scratchR6 = (char *)&local_840;
    TType__getCompleteString(scratchR7,*(uint *)(yyvsp + 8) + 8);
    TType__getCompleteString(scratchR6,*(uint *)(yyvsp + -0x50) + 8);
    TParseContext__binaryOpError(parseContext,*(uint *)(yyvsp + -0x2c),"-",scratchR6,scratchR7);
    refCountPtr = local_83c + -4;
    destroyAlloc21[0] = local_840;
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
                ((unsigned char *)(local_83c + -0xc),destroyAlloc21);
    }
    refCountPtr = local_84c + -4;
    paVar11 = (unsigned char *)(local_84c + -0xc);
    destroyAlloc22[0] = local_850;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    bVar37 = 0 < (int)oldRefCount2;
    ppTVar24 = destroyAlloc22;
    goto LAB_97ba7a00;
  case 0x38:
    if (1 < *(int *)((int)parseContext + 0xc) - 2U) {
      TParseContext__error
                ((int)parseContext,*(char **)(yyvsp + -0x2c)," reserved for future use ","<<","","",
                 pTVar34,scratchR10);
      TParseContext__recover(parseContext);
    }
    scratchR6 = *(char **)(yyvsp + 8);
    scratchR7 = *(char **)(yyvsp + -0x2c);
    yyvalNode = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(unsigned char **)parseContext,0x19,*(uint *)(yyvsp + -0x50),scratchR6,
                           scratchR7,*(undefined4 *)((int)parseContext + 4));
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (yyvalNode != (unsigned char *)0x0) break;
    scratchR7 = (char *)&local_850;
    scratchR6 = (char *)&local_840;
    TType__getCompleteString(scratchR7,*(uint *)(yyvsp + 8) + 8);
    TType__getCompleteString(scratchR6,*(uint *)(yyvsp + -0x50) + 8);
    TParseContext__binaryOpError(parseContext,*(uint *)(yyvsp + -0x2c),"<<",scratchR6,scratchR7);
    refCountPtr = local_83c + -4;
    destroyAlloc23[0] = local_840;
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
                ((unsigned char *)(local_83c + -0xc),destroyAlloc23);
    }
    refCountPtr = local_84c + -4;
    paVar11 = (unsigned char *)(local_84c + -0xc);
    destroyAlloc24[0] = local_850;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    bVar37 = 0 < (int)oldRefCount2;
    ppTVar24 = destroyAlloc24;
    goto LAB_97ba7a00;
  case 0x39:
    if (1 < *(int *)((int)parseContext + 0xc) - 2U) {
      TParseContext__error
                ((int)parseContext,*(char **)(yyvsp + -0x2c)," reserved for future use ",">>","","",
                 pTVar34,scratchR10);
      TParseContext__recover(parseContext);
    }
    scratchR6 = *(char **)(yyvsp + 8);
    scratchR7 = *(char **)(yyvsp + -0x2c);
    yyvalNode = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(unsigned char **)parseContext,0x18,*(uint *)(yyvsp + -0x50),scratchR6,
                           scratchR7,*(undefined4 *)((int)parseContext + 4));
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (yyvalNode != (unsigned char *)0x0) break;
    scratchR7 = (char *)&local_850;
    scratchR6 = (char *)&local_840;
    TType__getCompleteString(scratchR7,*(uint *)(yyvsp + 8) + 8);
    TType__getCompleteString(scratchR6,*(uint *)(yyvsp + -0x50) + 8);
    TParseContext__binaryOpError(parseContext,*(uint *)(yyvsp + -0x2c),">>",scratchR6,scratchR7);
    refCountPtr = local_83c + -4;
    destroyAlloc25[0] = local_840;
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
                ((unsigned char *)(local_83c + -0xc),destroyAlloc25);
    }
    refCountPtr = local_84c + -4;
    paVar11 = (unsigned char *)(local_84c + -0xc);
    destroyAlloc26[0] = local_850;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    bVar37 = 0 < (int)oldRefCount2;
    ppTVar24 = destroyAlloc26;
    goto LAB_97ba7a00;
  case 0x3b:
    scratchR6 = *(char **)(yyvsp + 8);
    scratchR7 = *(char **)(yyvsp + -0x2c);
    yyvalNode = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(unsigned char **)parseContext,0x21,*(uint *)(yyvsp + -0x50),scratchR6,
                           scratchR7,*(undefined4 *)((int)parseContext + 4));
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (yyvalNode != (unsigned char *)0x0) break;
    scratchR7 = (char *)&local_850;
    TType__getCompleteString(scratchR7,*(uint *)(yyvsp + 8) + 8);
    TType__getCompleteString(&local_840,*(uint *)(yyvsp + -0x50) + 8);
    TParseContext__binaryOpError(parseContext,*(uint *)(yyvsp + -0x2c),"<",&local_840,scratchR7);
    refCountPtr = local_83c + -4;
    destroyAlloc27[0] = local_840;
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
                ((unsigned char *)(local_83c + -0xc),destroyAlloc27);
    }
    refCountPtr = local_84c + -4;
    paVar11 = (unsigned char *)(local_84c + -0xc);
    destroyAlloc28[0] = local_850;
    do {
      oldRefCount = *(uint *)refCountPtr;
      if (reservation != '\0') {
        newRefCount = storeWordConditionalIndexed(oldRefCount - 1,0,refCountPtr);
        *(uint *)refCountPtr = newRefCount;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    bVar37 = 0 < (int)oldRefCount;
    ppTVar24 = destroyAlloc28;
    goto LAB_97ba7bac;
  case 0x3c:
    scratchR6 = *(char **)(yyvsp + 8);
    scratchR7 = *(char **)(yyvsp + -0x2c);
    yyvalNode = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(unsigned char **)parseContext,0x22,*(uint *)(yyvsp + -0x50),scratchR6,
                           scratchR7,*(undefined4 *)((int)parseContext + 4));
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (yyvalNode != (unsigned char *)0x0) break;
    scratchR7 = (char *)&local_850;
    TType__getCompleteString(scratchR7,*(uint *)(yyvsp + 8) + 8);
    TType__getCompleteString(&local_840,*(uint *)(yyvsp + -0x50) + 8);
    TParseContext__binaryOpError(parseContext,*(uint *)(yyvsp + -0x2c),">",&local_840,scratchR7);
    refCountPtr = local_83c + -4;
    destroyAlloc29[0] = local_840;
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
                ((unsigned char *)(local_83c + -0xc),destroyAlloc29);
    }
    refCountPtr = local_84c + -4;
    paVar11 = (unsigned char *)(local_84c + -0xc);
    destroyAlloc30[0] = local_850;
    do {
      oldRefCount = *(uint *)refCountPtr;
      if (reservation != '\0') {
        newRefCount = storeWordConditionalIndexed(oldRefCount - 1,0,refCountPtr);
        *(uint *)refCountPtr = newRefCount;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    bVar37 = 0 < (int)oldRefCount;
    ppTVar24 = destroyAlloc30;
    goto LAB_97ba7bac;
  case 0x3d:
    scratchR6 = *(char **)(yyvsp + 8);
    scratchR7 = *(char **)(yyvsp + -0x2c);
    yyvalNode = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(unsigned char **)parseContext,0x23,*(uint *)(yyvsp + -0x50),scratchR6,
                           scratchR7,*(undefined4 *)((int)parseContext + 4));
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (yyvalNode != (unsigned char *)0x0) break;
    scratchR7 = (char *)&local_850;
    TType__getCompleteString(scratchR7,*(uint *)(yyvsp + 8) + 8);
    TType__getCompleteString(&local_840,*(uint *)(yyvsp + -0x50) + 8);
    TParseContext__binaryOpError(parseContext,*(uint *)(yyvsp + -0x2c),"<=",&local_840,scratchR7);
    refCountPtr = local_83c + -4;
    destroyAlloc31[0] = local_840;
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
                ((unsigned char *)(local_83c + -0xc),destroyAlloc31);
    }
    refCountPtr = local_84c + -4;
    paVar11 = (unsigned char *)(local_84c + -0xc);
    destroyAlloc32[0] = local_850;
    do {
      oldRefCount = *(uint *)refCountPtr;
      if (reservation != '\0') {
        newRefCount = storeWordConditionalIndexed(oldRefCount - 1,0,refCountPtr);
        *(uint *)refCountPtr = newRefCount;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    bVar37 = 0 < (int)oldRefCount;
    ppTVar24 = destroyAlloc32;
    goto LAB_97ba7bac;
  case 0x3e:
    scratchR6 = *(char **)(yyvsp + 8);
    scratchR7 = *(char **)(yyvsp + -0x2c);
    yyvalNode = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(unsigned char **)parseContext,0x24,*(uint *)(yyvsp + -0x50),scratchR6,
                           scratchR7,*(undefined4 *)((int)parseContext + 4));
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (yyvalNode != (unsigned char *)0x0) break;
    scratchR7 = (char *)&local_850;
    TType__getCompleteString(scratchR7,*(uint *)(yyvsp + 8) + 8);
    TType__getCompleteString(&local_840,*(uint *)(yyvsp + -0x50) + 8);
    TParseContext__binaryOpError(parseContext,*(uint *)(yyvsp + -0x2c),">=",&local_840,scratchR7);
    refCountPtr = local_83c + -4;
    destroyAlloc33[0] = local_840;
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
                ((unsigned char *)(local_83c + -0xc),destroyAlloc33);
    }
    refCountPtr = local_84c + -4;
    paVar11 = (unsigned char *)(local_84c + -0xc);
    destroyAlloc34[0] = local_850;
    do {
      oldRefCount = *(uint *)refCountPtr;
      if (reservation != '\0') {
        newRefCount = storeWordConditionalIndexed(oldRefCount - 1,0,refCountPtr);
        *(uint *)refCountPtr = newRefCount;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    bVar37 = 0 < (int)oldRefCount;
    ppTVar24 = destroyAlloc34;
    goto LAB_97ba7bac;
  case 0x40:
    scratchR6 = *(char **)(yyvsp + 8);
    scratchR7 = *(char **)(yyvsp + -0x2c);
    yyvalNode = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(unsigned char **)parseContext,0x1d,*(uint *)(yyvsp + -0x50),scratchR6,
                           scratchR7,*(undefined4 *)((int)parseContext + 4));
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (yyvalNode != (unsigned char *)0x0) break;
    scratchR7 = (char *)&local_850;
    TType__getCompleteString(scratchR7,*(uint *)(yyvsp + 8) + 8);
    TType__getCompleteString(&local_840,*(uint *)(yyvsp + -0x50) + 8);
    TParseContext__binaryOpError(parseContext,*(uint *)(yyvsp + -0x2c),"==",&local_840,scratchR7);
    refCountPtr = local_83c + -4;
    destroyAlloc35[0] = local_840;
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
                ((unsigned char *)(local_83c + -0xc),destroyAlloc35);
    }
    refCountPtr = local_84c + -4;
    paVar11 = (unsigned char *)(local_84c + -0xc);
    destroyAlloc36[0] = local_850;
    do {
      oldRefCount = *(uint *)refCountPtr;
      if (reservation != '\0') {
        newRefCount = storeWordConditionalIndexed(oldRefCount - 1,0,refCountPtr);
        *(uint *)refCountPtr = newRefCount;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    bVar37 = 0 < (int)oldRefCount;
    ppTVar24 = destroyAlloc36;
    goto LAB_97ba7bac;
  case 0x41:
    scratchR6 = *(char **)(yyvsp + 8);
    scratchR7 = *(char **)(yyvsp + -0x2c);
    yyvalNode = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(unsigned char **)parseContext,0x1e,*(uint *)(yyvsp + -0x50),scratchR6,
                           scratchR7,*(undefined4 *)((int)parseContext + 4));
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (yyvalNode != (unsigned char *)0x0) break;
    scratchR7 = (char *)&local_850;
    TType__getCompleteString(scratchR7,*(uint *)(yyvsp + 8) + 8);
    TType__getCompleteString(&local_840,*(uint *)(yyvsp + -0x50) + 8);
    TParseContext__binaryOpError(parseContext,*(uint *)(yyvsp + -0x2c),"!=",&local_840,scratchR7);
    refCountPtr = local_83c + -4;
    destroyAlloc37[0] = local_840;
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
                ((unsigned char *)(local_83c + -0xc),destroyAlloc37);
    }
    refCountPtr = local_84c + -4;
    paVar11 = (unsigned char *)(local_84c + -0xc);
    destroyAlloc38[0] = local_850;
    do {
      oldRefCount = *(uint *)refCountPtr;
      if (reservation != '\0') {
        newRefCount = storeWordConditionalIndexed(oldRefCount - 1,0,refCountPtr);
        *(uint *)refCountPtr = newRefCount;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    bVar37 = 0 < (int)oldRefCount;
    ppTVar24 = destroyAlloc38;
    goto LAB_97ba7bac;
  case 0x43:
    if (1 < *(int *)((int)parseContext + 0xc) - 2U) {
      TParseContext__error
                ((int)parseContext,*(char **)(yyvsp + -0x2c)," reserved for future use ","&","","",
                 pTVar34,scratchR10);
      TParseContext__recover(parseContext);
    }
    scratchR6 = *(char **)(yyvsp + 8);
    scratchR7 = *(char **)(yyvsp + -0x2c);
    yyvalNode = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(unsigned char **)parseContext,0x1a,*(uint *)(yyvsp + -0x50),scratchR6,
                           scratchR7,*(undefined4 *)((int)parseContext + 4));
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (yyvalNode != (unsigned char *)0x0) break;
    scratchR7 = (char *)&local_850;
    scratchR6 = (char *)&local_840;
    TType__getCompleteString(scratchR7,*(uint *)(yyvsp + 8) + 8);
    TType__getCompleteString(scratchR6,*(uint *)(yyvsp + -0x50) + 8);
    TParseContext__binaryOpError(parseContext,*(uint *)(yyvsp + -0x2c),"&",scratchR6,scratchR7);
    refCountPtr = local_83c + -4;
    destroyAlloc39[0] = local_840;
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
                ((unsigned char *)(local_83c + -0xc),destroyAlloc39);
    }
    refCountPtr = local_84c + -4;
    paVar11 = (unsigned char *)(local_84c + -0xc);
    destroyAlloc40[0] = local_850;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    bVar37 = 0 < (int)oldRefCount2;
    ppTVar24 = destroyAlloc40;
    goto LAB_97ba7a00;
  case 0x45:
    if (1 < *(int *)((int)parseContext + 0xc) - 2U) {
      TParseContext__error
                ((int)parseContext,*(char **)(yyvsp + -0x2c)," reserved for future use ","^","","",
                 pTVar34,scratchR10);
      TParseContext__recover(parseContext);
    }
    scratchR6 = *(char **)(yyvsp + 8);
    scratchR7 = *(char **)(yyvsp + -0x2c);
    yyvalNode = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(unsigned char **)parseContext,0x1c,*(uint *)(yyvsp + -0x50),scratchR6,
                           scratchR7,*(undefined4 *)((int)parseContext + 4));
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (yyvalNode != (unsigned char *)0x0) break;
    scratchR7 = (char *)&local_850;
    scratchR6 = (char *)&local_840;
    TType__getCompleteString(scratchR7,*(uint *)(yyvsp + 8) + 8);
    TType__getCompleteString(scratchR6,*(uint *)(yyvsp + -0x50) + 8);
    TParseContext__binaryOpError(parseContext,*(uint *)(yyvsp + -0x2c),"^",scratchR6,scratchR7);
    refCountPtr = local_83c + -4;
    destroyAlloc41[0] = local_840;
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
                ((unsigned char *)(local_83c + -0xc),destroyAlloc41);
    }
    refCountPtr = local_84c + -4;
    paVar11 = (unsigned char *)(local_84c + -0xc);
    destroyAlloc42[0] = local_850;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    bVar37 = 0 < (int)oldRefCount2;
    ppTVar24 = destroyAlloc42;
    goto LAB_97ba7a00;
  case 0x47:
    if (1 < *(int *)((int)parseContext + 0xc) - 2U) {
      TParseContext__error
                ((int)parseContext,*(char **)(yyvsp + -0x2c)," reserved for future use ","|","","",
                 pTVar34,scratchR10);
      TParseContext__recover(parseContext);
    }
    scratchR6 = *(char **)(yyvsp + 8);
    scratchR7 = *(char **)(yyvsp + -0x2c);
    yyvalNode = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(unsigned char **)parseContext,0x1b,*(uint *)(yyvsp + -0x50),scratchR6,
                           scratchR7,*(undefined4 *)((int)parseContext + 4));
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (yyvalNode != (unsigned char *)0x0) break;
    scratchR7 = (char *)&local_850;
    scratchR6 = (char *)&local_840;
    TType__getCompleteString(scratchR7,*(uint *)(yyvsp + 8) + 8);
    TType__getCompleteString(scratchR6,*(uint *)(yyvsp + -0x50) + 8);
    TParseContext__binaryOpError(parseContext,*(uint *)(yyvsp + -0x2c),"|",scratchR6,scratchR7);
    refCountPtr = local_83c + -4;
    destroyAlloc43[0] = local_840;
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
                ((unsigned char *)(local_83c + -0xc),destroyAlloc43);
    }
    refCountPtr = local_84c + -4;
    paVar11 = (unsigned char *)(local_84c + -0xc);
    destroyAlloc44[0] = local_850;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    bVar37 = 0 < (int)oldRefCount2;
    ppTVar24 = destroyAlloc44;
LAB_97ba7a00:
    if (!bVar37) {
LAB_97ba7f84:
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_(paVar11,ppTVar24);
    }
LAB_97ba5554:
    TParseContext__recover(parseContext);
    pTVar3 = *(unsigned char **)(yyvsp + -0x50);
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x49:
    scratchR6 = *(char **)(yyvsp + 8);
    scratchR7 = *(char **)(yyvsp + -0x2c);
    yyvalNode = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(unsigned char **)parseContext,0x2c,*(uint *)(yyvsp + -0x50),scratchR6,
                           scratchR7,*(undefined4 *)((int)parseContext + 4));
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (yyvalNode != (unsigned char *)0x0) break;
    scratchR7 = (char *)&local_850;
    TType__getCompleteString(scratchR7,*(uint *)(yyvsp + 8) + 8);
    TType__getCompleteString(&local_840,*(uint *)(yyvsp + -0x50) + 8);
    TParseContext__binaryOpError(parseContext,*(uint *)(yyvsp + -0x2c),"&&",&local_840,scratchR7);
    refCountPtr = local_83c + -4;
    destroyAlloc45[0] = local_840;
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
                ((unsigned char *)(local_83c + -0xc),destroyAlloc45);
    }
    refCountPtr = local_84c + -4;
    paVar11 = (unsigned char *)(local_84c + -0xc);
    destroyAlloc46[0] = local_850;
    do {
      oldRefCount = *(uint *)refCountPtr;
      if (reservation != '\0') {
        newRefCount = storeWordConditionalIndexed(oldRefCount - 1,0,refCountPtr);
        *(uint *)refCountPtr = newRefCount;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    bVar37 = 0 < (int)oldRefCount;
    ppTVar24 = destroyAlloc46;
    goto LAB_97ba7bac;
  case 0x4b:
    scratchR6 = *(char **)(yyvsp + 8);
    scratchR7 = *(char **)(yyvsp + -0x2c);
    yyvalNode = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(unsigned char **)parseContext,0x2b,*(uint *)(yyvsp + -0x50),scratchR6,
                           scratchR7,*(undefined4 *)((int)parseContext + 4));
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (yyvalNode != (unsigned char *)0x0) break;
    scratchR7 = (char *)&local_850;
    TType__getCompleteString(scratchR7,*(uint *)(yyvsp + 8) + 8);
    TType__getCompleteString(&local_840,*(uint *)(yyvsp + -0x50) + 8);
    TParseContext__binaryOpError(parseContext,*(uint *)(yyvsp + -0x2c),"^^",&local_840,scratchR7);
    refCountPtr = local_83c + -4;
    destroyAlloc47[0] = local_840;
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
                ((unsigned char *)(local_83c + -0xc),destroyAlloc47);
    }
    refCountPtr = local_84c + -4;
    paVar11 = (unsigned char *)(local_84c + -0xc);
    destroyAlloc48[0] = local_850;
    do {
      oldRefCount = *(uint *)refCountPtr;
      if (reservation != '\0') {
        newRefCount = storeWordConditionalIndexed(oldRefCount - 1,0,refCountPtr);
        *(uint *)refCountPtr = newRefCount;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    bVar37 = 0 < (int)oldRefCount;
    ppTVar24 = destroyAlloc48;
LAB_97ba7bac:
    if (!bVar37) {
LAB_97ba7c88:
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_(paVar11,ppTVar24);
    }
LAB_97ba7c8c:
    pTVar3 = (unsigned char *)0x0;
    TParseContext__recover(parseContext);
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    pcVar9 = (unsigned char *)TPoolAllocator__allocate(poolAllocator,4);
    *(undefined4 *)pcVar9 = 0;
    local_82c = (unsigned char *)((uint)local_82c & 0x1801ff | 0x4180800);
    local_850 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
    pTVar15 = *(unsigned char **)parseContext;
    scratchR6 = *(char **)(yyvsp + -0x2c);
    local_84c = pTVar3;
    local_848 = pTVar3;
    local_844 = pTVar3;
    local_840 = pTVar3;
    local_83c = pTVar3;
    local_838 = pTVar3;
    local_834 = pTVar3;
    local_830 = pTVar3;
LAB_97ba7d0c:
    pTVar7 = local_850;
    pTVar3 = (unsigned char *)
             TIntermediate__addConstantUnion(pTVar15,pcVar9,(unsigned char *)&local_850,(int)scratchR6);
    local_850 = pTVar7;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x4d:
    scratchR6 = *(char **)(yyvsp + 8);
    scratchR7 = *(char **)(yyvsp + -0x2c);
    yyvalNode = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(unsigned char **)parseContext,0x2a,*(uint *)(yyvsp + -0x50),scratchR6,
                           scratchR7,*(undefined4 *)((int)parseContext + 4));
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (yyvalNode != (unsigned char *)0x0) break;
    scratchR7 = (char *)&local_850;
    TType__getCompleteString(scratchR7,*(uint *)(yyvsp + 8) + 8);
    TType__getCompleteString(&local_840,*(uint *)(yyvsp + -0x50) + 8);
    TParseContext__binaryOpError(parseContext,*(uint *)(yyvsp + -0x2c),"||",&local_840,scratchR7);
    refCountPtr = local_83c + -4;
    destroyAlloc49[0] = local_840;
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
                ((unsigned char *)(local_83c + -0xc),destroyAlloc49);
    }
    refCountPtr = local_84c + -4;
    paVar11 = (unsigned char *)(local_84c + -0xc);
    destroyAlloc50[0] = local_850;
    do {
      oldRefCount = *(uint *)refCountPtr;
      if (reservation != '\0') {
        newRefCount = storeWordConditionalIndexed(oldRefCount - 1,0,refCountPtr);
        *(uint *)refCountPtr = newRefCount;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    if ((int)oldRefCount < 1) {
      ppTVar24 = destroyAlloc50;
      goto LAB_97ba7c88;
    }
    goto LAB_97ba7c8c;
  case 0x4f:
    boolError = __ZN13TParseContext14boolErrorCheckEiPK12TIntermTyped
                       (parseContext,*(uint *)(yyvsp + -0x84),*(unsigned char **)(yyvsp + -0xa8),
                        scratchR6,scratchR7,pTVar33);
    if (boolError != 0) {
      TParseContext__recover(parseContext);
    }
    pTVar7 = (unsigned char *)&local_850;
    scratchR6 = *(char **)(yyvsp + 8);
    scratchR7 = *(char **)(yyvsp + -0x84);
    yyvalNode = (unsigned char *)
                __ZN13TIntermediate12addSelectionEP12TIntermTypedS1_S1_i
                          (*(void **)parseContext,*(unsigned char **)(yyvsp + -0xa8),
                           *(unsigned char **)(yyvsp + -0x50),(unsigned char *)scratchR6,(int)scratchR7)
    ;
    (**(code **)(**(int **)(yyvsp + -0x50) + 0x38))(pTVar7,*(int **)(yyvsp + -0x50));
    (**(code **)(**(int **)(yyvsp + 8) + 0x38))(&local_820,*(int **)(yyvsp + 8));
    bVar37 = false;
    if ((((uint)local_82c & 0x1fffe00) == ((uint)local_7fc & 0x1fffe00)) && (local_848 == local_818)
       ) {
      bVar37 = true;
    }
    picBase2 = (unsigned char *)0xa7b8374c;
    local_850 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
    local_820 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
    if (!bVar37) {
      yyvalNode = (unsigned char *)0x0;
    }
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (yyvalNode != (unsigned char *)0x0) break;
    scratchR6 = (char *)&local_840;
    TType__getCompleteString(pTVar7,*(uint *)(yyvsp + 8) + 8);
    TType__getCompleteString(scratchR6,*(uint *)(yyvsp + -0x50) + 8);
    TParseContext__binaryOpError(parseContext,*(uint *)(yyvsp + -0x84),":",scratchR6,pTVar7);
    refCountPtr = local_83c + -4;
    destroyAlloc51[0] = local_840;
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
                ((unsigned char *)(local_83c + -0xc),destroyAlloc51);
    }
    refCountPtr = local_84c + -4;
    paVar11 = (unsigned char *)(local_84c + -0xc);
    destroyAlloc52[0] = local_850;
    do {
      oldRefCount3 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount3 = (unsigned char *)storeWordConditionalIndexed(oldRefCount3 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount3;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    bVar37 = 0 < (int)oldRefCount3;
    ppTVar24 = destroyAlloc52;
    scratchR7 = (char *)pTVar7;
    goto LAB_97ba82d4;
  case 0x51:
    lValueError = TParseContext__lValueErrorCheck
                       (parseContext,*(uint *)(yyvsp + -0x2c),"assign",
                        *(unsigned char **)(yyvsp + -0x50),scratchR7,pTVar33,pTVar34,scratchR10);
    if (lValueError != 0) {
      TParseContext__recover(parseContext);
    }
    scratchR6 = *(char **)(yyvsp + 8);
    scratchR7 = *(char **)(yyvsp + -0x2c);
    yyvalNode = (unsigned char *)
                TIntermediate__addAssign
                          (*(unsigned char **)parseContext,*(uint *)(yyvsp + -0x28),
                           *(uint *)(yyvsp + -0x50),scratchR6,scratchR7);
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (yyvalNode != (unsigned char *)0x0) break;
    scratchR7 = (char *)&local_850;
    scratchR6 = (char *)&local_840;
    TType__getCompleteString(scratchR7,*(uint *)(yyvsp + 8) + 8);
    TType__getCompleteString(scratchR6,*(uint *)(yyvsp + -0x50) + 8);
    TParseContext__assignError(parseContext,*(uint *)(yyvsp + -0x2c),"assign",scratchR6,scratchR7);
    refCountPtr = local_83c + -4;
    destroyAlloc53[0] = local_840;
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
                ((unsigned char *)(local_83c + -0xc),destroyAlloc53);
    }
    refCountPtr = local_84c + -4;
    paVar11 = (unsigned char *)(local_84c + -0xc);
    destroyAlloc54[0] = local_850;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    if (0 < (int)oldRefCount2) goto LAB_97ba5554;
    ppTVar24 = destroyAlloc54;
    goto LAB_97ba7f84;
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
                 "","",pTVar34,scratchR10);
      TParseContext__recover(parseContext);
    }
    yyval = *(uint *)yyvsp;
    yyvalOp = 0x79;
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x54:
    if (1 < *(uint *)((int)parseContext + 0xc)) {
      scratchR7 = "";
      scratchR6 = "/=";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," supported in vertex/fragment shaders only ","/=",
                 "","",pTVar34,scratchR10);
      TParseContext__recover(parseContext);
    }
    yyval = *(uint *)yyvsp;
    yyvalOp = 0x7e;
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x55:
    if (1 < *(int *)((int)parseContext + 0xc) - 2U) {
      scratchR7 = "";
      scratchR6 = "%=";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," reserved for future use ","%=","","",pTVar34,
                 scratchR10);
      TParseContext__recover(parseContext);
    }
    yyval = *(uint *)yyvsp;
    yyvalOp = 0x7f;
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
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
                ((int)parseContext,*(char **)yyvsp," reserved for future use ","<<=","","",pTVar34,
                 scratchR10);
      TParseContext__recover(parseContext);
    }
    yyval = *(uint *)yyvsp;
    yyvalOp = 0x83;
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x59:
    if (1 < *(int *)((int)parseContext + 0xc) - 2U) {
      scratchR7 = "";
      scratchR6 = "<<=";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," reserved for future use ","<<=","","",pTVar34,
                 scratchR10);
      TParseContext__recover(parseContext);
    }
    yyval = *(uint *)yyvsp;
    yyvalOp = 0x84;
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x5a:
    if (1 < *(int *)((int)parseContext + 0xc) - 2U) {
      scratchR7 = "";
      scratchR6 = "&=";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," reserved for future use ","&=","","",pTVar34,
                 scratchR10);
      TParseContext__recover(parseContext);
    }
    yyval = *(uint *)yyvsp;
    yyvalOp = 0x80;
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x5b:
    if (1 < *(int *)((int)parseContext + 0xc) - 2U) {
      scratchR7 = "";
      scratchR6 = "^=";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," reserved for future use ","^=","","",pTVar34,
                 scratchR10);
      TParseContext__recover(parseContext);
    }
    yyval = *(uint *)yyvsp;
    yyvalOp = 0x82;
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x5c:
    if (1 < *(int *)((int)parseContext + 0xc) - 2U) {
      scratchR7 = "";
      scratchR6 = "|=";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," reserved for future use ","|=","","",pTVar34,
                 scratchR10);
      TParseContext__recover(parseContext);
    }
    yyval = *(uint *)yyvsp;
    yyvalOp = 0x81;
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x5e:
    scratchR6 = *(char **)(yyvsp + -0x2c);
    yyvalNode = (unsigned char *)
                TIntermediate__addComma
                          (*(unsigned char **)parseContext,*(unsigned char **)(yyvsp + -0x50),
                           *(unsigned char **)(yyvsp + 8),(int)scratchR6);
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (yyvalNode != (unsigned char *)0x0) break;
    scratchR7 = (char *)&local_850;
    scratchR6 = (char *)&local_840;
    TType__getCompleteString(scratchR7,*(uint *)(yyvsp + 8) + 8);
    TType__getCompleteString(scratchR6,*(uint *)(yyvsp + -0x50) + 8);
    TParseContext__binaryOpError(parseContext,*(uint *)(yyvsp + -0x2c),",",scratchR6,scratchR7);
    refCountPtr = local_83c + -4;
    destroyAlloc55[0] = local_840;
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
                ((unsigned char *)(local_83c + -0xc),destroyAlloc55);
    }
    refCountPtr = local_84c + -4;
    paVar11 = (unsigned char *)(local_84c + -0xc);
    destroyAlloc56[0] = local_850;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    bVar37 = 0 < (int)oldRefCount2;
    ppTVar24 = destroyAlloc56;
LAB_97ba82d4:
    if (!bVar37) {
LAB_97ba69a8:
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_(paVar11,ppTVar24);
    }
LAB_97ba82f0:
    TParseContext__recover(parseContext);
switchD_97ba39c8_caseD_2:
    pTVar3 = *(unsigned char **)(yyvsp + 8);
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x5f:
    iVar55 = TParseContext__constErrorCheck(parseContext,*(unsigned char **)(yyvsp + 8));
LAB_97ba82e8:
    if (iVar55 != 0) goto LAB_97ba82f0;
    goto switchD_97ba39c8_caseD_2;
  case 0x60:
  case 0xb0:
  case 0xb6:
  case 0xba:
  case 0xca:
    goto switchD_97ba39c8_caseD_60;
  case 0x61:
  case 0xb7:
    piVar61 = *(int **)(yyvsp + -0x24);
    pTVar3 = (unsigned char *)0x0;
    if (piVar61 != (int *)0x0) {
      (**(code **)(*piVar61 + 0x60))(piVar61,1);
      pTVar3 = *(unsigned char **)(yyvsp + -0x24);
      pTVar31 = local_7f0;
      pTVar32 = local_750[0];
    }
    break;
  case 0x62:
    symbolTable = *(int **)((int)parseContext + 4);
    pcVar62 = (char *)(**(code **)(**(int **)(yyvsp + -0x1c) + 8))(*(int **)(yyvsp + -0x1c));
    iVar55 = *symbolTable;
    iVar54 = (symbolTable[1] - iVar55 >> 2) + -1;
    goto LAB_97ba8338;
  case 99:
  case 100:
  case 0xa0:
    yyvalTypeOrFunction = *(unsigned char **)(yyvsp + 0x10);
    break;
  case 0x65:
    yyvalTypeOrFunction = *(unsigned char **)(yyvsp + -0x1c);
    iVar55 = (**(code **)(**(int **)(yyvsp + 0x14) + 0x20))
                       (*(int **)(yyvsp + 0x14),scratchR4,scratchR5,scratchR6,scratchR7,pTVar33,pTVar34);
    if (iVar55 == 0) {
LAB_97ba86ec:
      stackNode = *(unsigned char **)(yyvsp + 0x14);
      pTVar3 = yyvalNode;
      pTVar31 = local_7f0;
      pTVar32 = local_750[0];
      if (stackNode == (unsigned char *)0x0) break;
      iVar55 = *(int *)stackNode;
      goto LAB_97ba86fc;
    }
    uVar57 = *(uint *)(yyvsp + -0x1c);
    puVar25 = *(uint **)(uVar57 + 0x14);
    if (puVar25 == *(uint **)(uVar57 + 0x18)) {
      std__vector_TParameter_pool_allocator_TParameter_____M_insert_aux
                ((unsigned char *)(uVar57 + 0xc),
                 *(undefined4 *)(uVar57 + 0x14),yyvsp + 0x10);
    }
    else {
      iVar55 = 0;
      if (puVar25 != (uint *)0x0) {
        uVar28 = *(uint *)(yyvsp + 0x14);
        *puVar25 = *(uint *)(yyvsp + 0x10);
        puVar25[1] = uVar28;
        iVar55 = *(int *)(uVar57 + 0x14);
      }
      *(int *)(uVar57 + 0x14) = iVar55 + 8;
    }
    pTVar12 = *(unsigned char **)(yyvsp + 0x14);
    iVar55 = *(int *)(pTVar12 + 0x14);
    if (iVar55 == 0) {
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      newString = (unsigned char *)TPoolAllocator__allocate(poolAllocator,8);
      cr0 = (newString == (unsigned char *)0x0) << 1;
      psVar21 = (unsigned char *)0x0;
      if (newString != (unsigned char *)0x0) {
        ctorAlloc5[0] = GetGlobalPoolAllocator();
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_(newString,"",(unsigned char *)ctorAlloc5)
        ;
        psVar21 = newString;
      }
      *(unsigned char **)(pTVar12 + 0x14) = psVar21;
      ((int (*)())TType__buildMangledName)(pTVar12,psVar21);
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEmc(*(void **)(pTVar12 + 0x14),1,0x3b);
      iVar55 = *(int *)(pTVar12 + 0x14);
    }
    __ZStplIcSt11char_traitsIcE14pool_allocatorIcEESbIT_T0_T1_ERKS7_S9_
              ((unsigned char *)&local_850,(unsigned char *)(uVar57 + 0x44),iVar55);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6assignERKS3_
              ((unsigned char *)(uVar57 + 0x44),(unsigned char *)&local_850);
    refCountPtr = local_84c + -4;
    paVar11 = (unsigned char *)(local_84c + -0xc);
    destroyAlloc58[0] = local_850;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    bVar37 = 0 < (int)oldRefCount2;
    ppTVar24 = destroyAlloc58;
LAB_97ba869c:
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (!bVar37) {
LAB_97ba8824:
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_(paVar11,ppTVar24);
      pTVar3 = yyvalNode;
      pTVar31 = local_7f0;
      pTVar32 = local_750[0];
    }
    break;
  case 0x66:
    iVar55 = (**(code **)(**(int **)(yyvsp + 0x14) + 0x20))(*(int **)(yyvsp + 0x14));
    if (iVar55 == 0) {
      scratchR6 = "void";
      scratchR7 = "";
      TParseContext__error
                ((int)parseContext,*(char **)(yyvsp + -0x2c),
                 "cannot be an argument type except for \'(void)\'","void","",pTVar33,pTVar34,
                 scratchR10);
      TParseContext__recover(parseContext);
      goto LAB_97ba86ec;
    }
    yyvalTypeOrFunction = *(unsigned char **)(yyvsp + -0x48);
    functionHeaderWithParametersTypeOrFunction = *(uint *)(yyvsp + -0x48);
    puVar25 = *(uint **)(functionHeaderWithParametersTypeOrFunction + 0x14);
    if (puVar25 == *(uint **)(functionHeaderWithParametersTypeOrFunction + 0x18)) {
      std__vector_TParameter_pool_allocator_TParameter_____M_insert_aux
                ((unsigned char *)(functionHeaderWithParametersTypeOrFunction + 0xc),
                 *(undefined4 *)(functionHeaderWithParametersTypeOrFunction + 0x14),yyvsp + 0x10);
    }
    else {
      iVar55 = 0;
      if (puVar25 != (uint *)0x0) {
        parameterDeclarationQualifierOrParamType = *(uint *)(yyvsp + 0x14);
        *puVar25 = *(uint *)(yyvsp + 0x10);
        puVar25[1] = parameterDeclarationQualifierOrParamType;
        iVar55 = *(int *)(functionHeaderWithParametersTypeOrFunction + 0x14);
      }
      *(int *)(functionHeaderWithParametersTypeOrFunction + 0x14) = iVar55 + 8;
    }
    parameterDeclarationQualifierOrParamType2 = *(unsigned char **)(yyvsp + 0x14);
    iVar55 = *(int *)(parameterDeclarationQualifierOrParamType2 + 0x14);
    if (iVar55 == 0) {
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      newString = (unsigned char *)TPoolAllocator__allocate(poolAllocator,8);
      cr0 = (newString == (unsigned char *)0x0) << 1;
      psVar21 = (unsigned char *)0x0;
      if (newString != (unsigned char *)0x0) {
        ctorAlloc6[0] = GetGlobalPoolAllocator();
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_(newString,"",(unsigned char *)ctorAlloc6)
        ;
        psVar21 = newString;
      }
      *(unsigned char **)(parameterDeclarationQualifierOrParamType2 + 0x14) = psVar21;
      ((int (*)())TType__buildMangledName)(parameterDeclarationQualifierOrParamType2,psVar21);
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEmc(*(void **)(parameterDeclarationQualifierOrParamType2 + 0x14),1,0x3b);
      iVar55 = *(int *)(parameterDeclarationQualifierOrParamType2 + 0x14);
    }
    __ZStplIcSt11char_traitsIcE14pool_allocatorIcEESbIT_T0_T1_ERKS7_S9_
              ((unsigned char *)&local_850,(unsigned char *)(functionHeaderWithParametersTypeOrFunction + 0x44),iVar55);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6assignERKS3_
              ((unsigned char *)(functionHeaderWithParametersTypeOrFunction + 0x44),(unsigned char *)&local_850);
    refCountPtr = local_84c + -4;
    paVar11 = (unsigned char *)(local_84c + -0xc);
    destroyAlloc59[0] = local_850;
    do {
      oldRefCount2 = *(unsigned char **)refCountPtr;
      if (reservation != '\0') {
        newRefCount2 = (unsigned char *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *(unsigned char **)refCountPtr = newRefCount2;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (0 < (int)oldRefCount2) break;
    ppTVar24 = destroyAlloc59;
    goto LAB_97ba8824;
  case 0x67:
    if (1 < *(uint *)(yyvsp + -0x44)) {
      scratchR6 = (char *)getQualifierString(*(uint *)(yyvsp + -0x44));
      scratchR7 = "";
      TParseContext__error
                ((int)parseContext,*(char **)(yyvsp + -0x2c),
                 "no qualifiers allowed for function return",scratchR6,"",pTVar33,pTVar34,scratchR10);
      TParseContext__recover(parseContext);
    }
    structQualifierError = TParseContext__structQualifierErrorCheck
                       (parseContext,*(uint *)(yyvsp + -0x2c),(unsigned char *)(yyvsp + -0x48),scratchR6,
                        scratchR7,pTVar33,pTVar34);
    if (structQualifierError != 0) {
      TParseContext__recover(parseContext);
    }
    local_820 = *(unsigned char **)(yyvsp + -0x48);
    local_81c = *(unsigned char **)(yyvsp + -0x44);
    scratchR7 = *(char **)(yyvsp + -0x40);
    scratchR6 = *(char **)(yyvsp + -0x3c);
    local_80c = *(unsigned char **)(yyvsp + -0x34);
    local_810 = *(unsigned char **)(yyvsp + -0x38);
    picBase2 = (unsigned char *)0xa7b8374c;
    fullySpecifiedTypeTypeLine = *(unsigned char **)(yyvsp + -0x30);
    local_82c = (unsigned char *)
                (((uint)local_810 & 1) << 9 |
                ((uint)scratchR6 & 1) << 10 |
                ((uint)scratchR7 & 0xff) << 0xb |
                ((uint)local_820 & 0x3f) << 0x13 | (int)local_81c << 0x19 | (uint)local_82c & 0x1ff)
    ;
    local_850 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
    local_830 = (unsigned char *)0x0;
    local_84c = (unsigned char *)0x0;
    local_848 = (unsigned char *)0x0;
    local_844 = (unsigned char *)0x0;
    local_840 = (unsigned char *)0x0;
    local_83c = (unsigned char *)0x0;
    local_838 = (unsigned char *)0x0;
    local_834 = (unsigned char *)0x0;
    pTVar3 = local_840;
    local_818 = (unsigned char *)scratchR7;
    local_814 = (unsigned char *)scratchR6;
    local_808 = fullySpecifiedTypeTypeLine;
    local_800 = local_820;
    local_7fc = local_81c;
    local_7f8 = (unsigned char *)scratchR7;
    local_7f4 = (unsigned char *)scratchR6;
    local_7f0 = local_810;
    local_7ec = local_80c;
    local_7e8 = fullySpecifiedTypeTypeLine;
    if (local_80c != (unsigned char *)0x0) {
      local_848 = *(unsigned char **)(local_80c + 8);
      uVar16 = 0xa7b8374c;
      picBase = (unsigned char *)0xa7b8374c;
      setStructSizeResult2 = TType__setStructSize((unsigned char *)&local_850,*(unsigned char **)(local_80c + 8));
      local_838 = (unsigned char *)((ulonglong)setStructSizeResult2 >> 0x20);
      iVar55 = (**(code **)(*(uint *)local_7ec + 0x18))
                         (local_7ec,(int)setStructSizeResult2,fullySpecifiedTypeTypeLine,scratchR6,scratchR7,uVar16,*(uint *)local_7ec);
      *(undefined1 *)(*(int *)(iVar55 + 4) + *(int *)(*(int *)(iVar55 + 4) + -0xc)) =
           **(undefined1 **)(picBase + -0x7cc4);
      pcVar62 = *(char **)(iVar55 + 4);
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      pTVar7 = (unsigned char *)TPoolAllocator__allocate(poolAllocator,8);
      cr0 = (pTVar7 == (unsigned char *)0x0) << 1;
      pTVar3 = (unsigned char *)0x0;
      if (pTVar7 != (unsigned char *)0x0) {
        ctorAlloc7[0] = GetGlobalPoolAllocator();
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                  (pTVar7,pcVar62,(unsigned char *)ctorAlloc7);
        pTVar3 = pTVar7;
      }
    }
    local_840 = pTVar3;
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
    *(unsigned char **)(newFunction + 0x20) = local_84c;
    typeVtable3 = picBase2 + -0x610c;
    *(unsigned char **)(newFunction + 0x24) = local_848;
    *(unsigned char **)(newFunction + 0x28) = local_844;
    *(unsigned char **)(newFunction + 0x2c) = local_840;
    *(unsigned char **)(newFunction + 0x30) = local_83c;
    *(unsigned char **)(newFunction + 0x34) = local_838;
    *(unsigned char **)(newFunction + 0x1c) = typeVtable3;
    *(unsigned char **)(newFunction + 0x38) = local_834;
    *(unsigned char **)(newFunction + 0x3c) = local_830;
    uVar2 = *(uint *)(newFunction + 0x40);
    qualifierBits = (uint)local_82c & 0xfe000000;
    *(uint *)(newFunction + 0x40) = qualifierBits | uVar2 & 0x1ffffff;
    basicTypeBits = ((uint)local_82c >> 0x13 & 0x3f) << 0x13;
    *(uint *)(newFunction + 0x40) = basicTypeBits | qualifierBits | uVar2 & 0x7ffff;
    uVar57 = (uint)local_82c & 0x7f800;
    *(uint *)(newFunction + 0x40) = uVar57 | basicTypeBits | qualifierBits | uVar2 & 0x7ff;
    uVar58 = ((uint)local_82c >> 10 & 1) << 10;
    *(uint *)(newFunction + 0x40) = uVar58 | uVar57 | basicTypeBits | qualifierBits | uVar2 & 0x3ff;
    *(uint *)(newFunction + 0x40) =
         ((uint)local_82c >> 9 & 1) << 9 | uVar58 | uVar57 | basicTypeBits | qualifierBits | uVar2 & 0x1ff;
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(newFunction + 0x44,identifierString2);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEmc(newFunction + 0x44,1,0x28);
    *(uint *)(newFunction + 0x50) = 0;
    *(uint *)(newFunction + 0x4c) = 0;
    pTVar3 = yyvalNode;
    yyvalTypeOrFunction = newFunction;
    local_850 = typeVtable3;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x68:
    if (*(uint *)(yyvsp + -0x1c) == 0) {
      identifierString = *(uint *)(yyvsp + 4);
      picBase = (unsigned char *)0xa7b8374c;
      stringData = *(int *)(identifierString + 4);
      *(unsigned char *)(stringData + *(int *)(stringData + -0xc)) = *DAT_a7b7ba88;
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp,"illegal use of type \'void\'",
                 *(char **)(identifierString + 4),"",pTVar33,stringData,identifierString);
      TParseContext__recover(parseContext);
    }
    reservedError = TParseContext__reservedErrorCheck(parseContext,*(uint *)yyvsp,*(unsigned char **)(yyvsp + 4));
    if (reservedError != 0) {
      TParseContext__recover(parseContext);
    }
    local_840 = *(unsigned char **)(yyvsp + 4);
    picBase2 = (unsigned char *)0xa7b8374c;
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    newType = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x28);
    local_830 = *(unsigned char **)(yyvsp + -0x1c);
    local_82c = *(unsigned char **)(yyvsp + -0x18);
    typeSpecifierSize = *(unsigned char **)(yyvsp + -0x14);
    typeSpecifierMatrix = *(unsigned char **)(yyvsp + -0x10);
    scratchR7 = *(char **)(yyvsp + -0xc);
    scratchR6 = *(char **)(yyvsp + -8);
    local_818 = *(unsigned char **)(yyvsp + -4);
    *(unsigned char **)newType = picBase2 + -0x610c;
    *(undefined4 *)(newType + 0x20) = 0;
    *(undefined4 *)(newType + 4) = 0;
    *(undefined4 *)(newType + 8) = 0;
    *(undefined4 *)(newType + 0xc) = 0;
    *(undefined4 *)(newType + 0x10) = 0;
    *(undefined4 *)(newType + 0x14) = 0;
    *(undefined4 *)(newType + 0x18) = 0;
    *(undefined4 *)(newType + 0x1c) = 0;
    uVar2 = *(uint *)(newType + 0x24);
    qualifierBits2 = (int)local_82c << 0x19;
    *(uint *)(newType + 0x24) = qualifierBits2 | uVar2 & 0x1ffffff;
    basicTypeBits2 = ((uint)local_830 & 0x3f) << 0x13;
    *(uint *)(newType + 0x24) = basicTypeBits2 | qualifierBits2 | uVar2 & 0x7ffff;
    sizeBits = ((uint)typeSpecifierSize & 0xff) << 0xb;
    *(uint *)(newType + 0x24) = sizeBits | basicTypeBits2 | qualifierBits2 | uVar2 & 0x7ff;
    uVar58 = ((uint)typeSpecifierMatrix & 1) << 10;
    *(uint *)(newType + 0x24) = uVar58 | sizeBits | basicTypeBits2 | qualifierBits2 | uVar2 & 0x3ff;
    *(uint *)(newType + 0x24) =
         ((uint)scratchR7 & 1) << 9 | uVar58 | sizeBits | basicTypeBits2 | qualifierBits2 | uVar2 & 0x1ff;
    local_820 = (unsigned char *)scratchR7;
    local_81c = (unsigned char *)scratchR6;
    local_810 = local_830;
    local_80c = local_82c;
    local_808 = typeSpecifierSize;
    local_804 = typeSpecifierMatrix;
    local_800 = (unsigned char *)scratchR7;
    local_7fc = (unsigned char *)scratchR6;
    local_7f8 = local_818;
    if ((unsigned char *)scratchR6 != (unsigned char *)0x0) {
      picBase = (unsigned char *)0xa7b8374c;
      *(uint *)(newType + 8) = *(uint *)(scratchR6 + 8);
      setStructSizeResult3 = TType__setStructSize(newType,*(unsigned char **)(scratchR6 + 8));
      *(undefined4 *)(newType + 0x18) = setStructSizeResult3;
      iVar55 = (**(code **)(*(uint *)local_7fc + 0x18))(local_7fc);
      *(undefined1 *)(*(int *)(iVar55 + 4) + *(int *)(*(int *)(iVar55 + 4) + -0xc)) =
           **(undefined1 **)(picBase + -0x7cc4);
      pcVar62 = *(char **)(iVar55 + 4);
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      pvVar13 = (void *)TPoolAllocator__allocate(poolAllocator,8);
      cr0 = (pvVar13 == (void *)0x0) << 1;
      pvVar23 = (void *)0x0;
      if (pvVar13 != (void *)0x0) {
        ctorAlloc8[0] = GetGlobalPoolAllocator();
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                  (pvVar13,pcVar62,(unsigned char *)ctorAlloc8);
        pvVar23 = pvVar13;
      }
      *(void **)(newType + 0x10) = pvVar23;
    }
    local_850 = local_840;
    yyval = *(uint *)yyvsp;
    pTVar3 = yyvalNode;
    yyvalTypeOrFunction = local_850;
    yyvalQualifierOrParamType = (unsigned char *)newType;
    local_84c = (unsigned char *)newType;
    local_83c = (unsigned char *)newType;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x69:
    picBase2 = (unsigned char *)0xa7b8374c;
    if (*(uint *)(yyvsp + -0x90) != 0) {
      local_810 = *(unsigned char **)(yyvsp + -0xa0);
      typeSpecifierQualifierOrParamType = *(unsigned char **)(yyvsp + -0x9c);
      typeSpecifierSize2 = *(unsigned char **)(yyvsp + -0x98);
      typeSpecifierMatrix2 = *(unsigned char **)(yyvsp + -0x94);
      local_7fc = *(unsigned char **)(yyvsp + -0x8c);
      local_800 = *(unsigned char **)(yyvsp + -0x90);
      typeSpecifierTypeLine = *(unsigned char **)(yyvsp + -0x88);
      uVar16 = 0xa7b8374c;
      local_81c = (unsigned char *)
                  (((uint)local_800 & 1) << 9 |
                  ((uint)typeSpecifierMatrix2 & 1) << 10 |
                  ((uint)typeSpecifierSize2 & 0xff) << 0xb |
                  ((uint)local_810 & 0x3f) << 0x13 | (int)typeSpecifierQualifierOrParamType << 0x19 | (uint)local_81c & 0x1ff)
      ;
      local_840 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
      local_820 = (unsigned char *)0x0;
      local_83c = (unsigned char *)0x0;
      local_838 = (unsigned char *)0x0;
      local_834 = (unsigned char *)0x0;
      local_830 = (unsigned char *)0x0;
      local_82c = (unsigned char *)0x0;
      local_828 = (unsigned char *)0x0;
      local_824 = (unsigned char *)0x0;
      picBase = (unsigned char *)0xa7b8374c;
      pTVar3 = local_830;
      local_80c = typeSpecifierQualifierOrParamType;
      local_808 = typeSpecifierSize2;
      local_804 = typeSpecifierMatrix2;
      local_7f8 = typeSpecifierTypeLine;
      local_7f0 = local_810;
      local_7ec = typeSpecifierQualifierOrParamType;
      local_7e8 = typeSpecifierSize2;
      local_7e4 = typeSpecifierMatrix2;
      local_7e0 = local_800;
      local_7dc = local_7fc;
      local_7d8 = typeSpecifierTypeLine;
      if (local_7fc != (unsigned char *)0x0) {
        local_838 = *(unsigned char **)(local_7fc + 8);
        setStructSizeResult2 = TType__setStructSize((unsigned char *)&local_840,*(unsigned char **)(local_7fc + 8));
        local_828 = (unsigned char *)((ulonglong)setStructSizeResult2 >> 0x20);
        iVar55 = (**(code **)(*(uint *)local_7dc + 0x18))
                           (local_7dc,(int)setStructSizeResult2,typeSpecifierTypeLine,typeSpecifierMatrix2,typeSpecifierSize2,typeSpecifierQualifierOrParamType,*(uint *)local_7dc)
        ;
        *(undefined1 *)(*(int *)(iVar55 + 4) + *(int *)(*(int *)(iVar55 + 4) + -0xc)) =
             **(undefined1 **)(picBase + -0x7cc4);
        pcVar62 = *(char **)(iVar55 + 4);
        poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
        pTVar7 = (unsigned char *)TPoolAllocator__allocate(poolAllocator,8);
        cr0 = (pTVar7 == (unsigned char *)0x0) << 1;
        pTVar3 = (unsigned char *)0x0;
        if (pTVar7 != (unsigned char *)0x0) {
          ctorAlloc9[0] = GetGlobalPoolAllocator();
          __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                    (pTVar7,pcVar62,(unsigned char *)ctorAlloc9);
          pTVar3 = pTVar7;
        }
      }
      local_830 = pTVar3;
      TType__getCompleteString(&local_850,(unsigned char *)&local_840);
      local_84c[*(uint *)(local_84c + -0xc)] = **(unsigned char **)(picBase + -0x7cc4);
      TParseContext__error
                ((int)parseContext,*(char **)(yyvsp + -0x58),"cannot declare arrays of this type",
                 (char *)local_84c,"",picBase,local_84c,uVar16);
      refCountPtr = local_84c + -4;
      destroyAlloc60[0] = local_850;
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
                  ((unsigned char *)(local_84c + -0xc),destroyAlloc60);
      }
      local_840 = picBase2 + -0x610c;
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
    local_850 = *(unsigned char **)(yyvsp + -0xa0);
    typeSpecifierQualifierOrParamType2 = *(unsigned char **)(yyvsp + -0x9c);
    local_848 = *(unsigned char **)(yyvsp + -0x98);
    local_844 = *(unsigned char **)(yyvsp + -0x94);
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
    uVar2 = *(uint *)(newType + 0x24);
    qualifierBits2 = (int)typeSpecifierQualifierOrParamType2 << 0x19;
    *(uint *)(newType + 0x24) = qualifierBits2 | uVar2 & 0x1ffffff;
    basicTypeBits2 = ((uint)local_850 & 0x3f) << 0x13;
    *(uint *)(newType + 0x24) = basicTypeBits2 | qualifierBits2 | uVar2 & 0x7ffff;
    sizeBits = ((uint)local_848 & 0xff) << 0xb;
    *(uint *)(newType + 0x24) = sizeBits | basicTypeBits2 | qualifierBits2 | uVar2 & 0x7ff;
    uVar58 = ((uint)local_844 & 1) << 10;
    *(uint *)(newType + 0x24) = uVar58 | sizeBits | basicTypeBits2 | qualifierBits2 | uVar2 & 0x3ff;
    *(uint *)(newType + 0x24) =
         ((uint)scratchR7 & 1) << 9 | uVar58 | sizeBits | basicTypeBits2 | qualifierBits2 | uVar2 & 0x1ff;
    local_840 = (unsigned char *)scratchR7;
    local_83c = (unsigned char *)scratchR6;
    local_830 = local_850;
    local_82c = typeSpecifierQualifierOrParamType2;
    local_828 = local_848;
    local_824 = local_844;
    local_820 = (unsigned char *)scratchR7;
    local_81c = (unsigned char *)scratchR6;
    local_818 = typeSpecifierTypeLine2;
    if ((unsigned char *)scratchR6 != (unsigned char *)0x0) {
      picBase = (unsigned char *)0xa7b8374c;
      *(uint *)(newType + 8) = *(uint *)(scratchR6 + 8);
      setStructSizeResult3 = TType__setStructSize(newType,*(unsigned char **)(scratchR6 + 8));
      *(undefined4 *)(newType + 0x18) = setStructSizeResult3;
      iVar55 = (**(code **)(*(uint *)local_81c + 0x18))(local_81c);
      *(undefined1 *)(*(int *)(iVar55 + 4) + *(int *)(*(int *)(iVar55 + 4) + -0xc)) =
           **(undefined1 **)(picBase + -0x7cc4);
      pcVar62 = *(char **)(iVar55 + 4);
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      pvVar13 = (void *)TPoolAllocator__allocate(poolAllocator,8);
      cr0 = (pvVar13 == (void *)0x0) << 1;
      pvVar23 = (void *)0x0;
      if (pvVar13 != (void *)0x0) {
        ctorAlloc10[0] = GetGlobalPoolAllocator();
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                  (pvVar13,pcVar62,(unsigned char *)ctorAlloc10);
        pvVar23 = pvVar13;
      }
      *(void **)(newType + 0x10) = pvVar23;
    }
    constantUnion = (**(code **)(**(int **)(yyvsp + -0x24) + 0x18))(*(int **)(yyvsp + -0x24));
    if (constantUnion != 0) {
      constantUnion = (**(code **)(**(int **)(yyvsp + -0x24) + 0x18))(*(int **)(yyvsp + -0x24));
      uVar16 = **(undefined4 **)(constantUnion + 0x30);
      *(uint *)(newType + 0x24) = *(uint *)(newType + 0x24) | 0x200;
      *(undefined4 *)(newType + 4) = uVar16;
    }
    local_840 = *(unsigned char **)(yyvsp + -0x80);
    yyval = *(uint *)(yyvsp + -0x84);
    pTVar3 = yyvalNode;
    yyvalTypeOrFunction = local_840;
    yyvalQualifierOrParamType = (unsigned char *)newType;
    local_850 = local_840;
    local_84c = (unsigned char *)newType;
    local_83c = (unsigned char *)newType;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x6a:
  case 0x6c:
    _memcpy(&yyval,yyvsp,0x2c);
    uVar57 = *(uint *)yyvsp;
    uVar28 = *(uint *)(yyvsp + -0x44);
    scratchR6 = *(char **)(yyvsp + -0x1c);
    goto LAB_97ba9130;
  case 0x6b:
  case 0x6d:
    _memcpy(&yyval,yyvsp,0x2c);
    parameterSamplerError = TParseContext__parameterSamplerErrorCheck
                       (parseContext,*(uint *)yyvsp,*(uint *)(yyvsp + -0x1c),
                        *(uint *)(yyvsp + 0x14));
    if (parameterSamplerError != 0) {
      TParseContext__recover(parseContext);
    }
    uVar57 = *(uint *)yyvsp;
    scratchR6 = *(char **)(yyvsp + -0x1c);
    uVar28 = 0;
LAB_97ba9130:
    scratchR7 = (char *)yyvalQualifierOrParamType;
    iVar55 = TParseContext__paramErrorCheck(parseContext,uVar57,uVar28,scratchR6,yyvalQualifierOrParamType);
LAB_97bab180:
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (iVar55 == 0) break;
LAB_97bab5f4:
    TParseContext__recover(parseContext);
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
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
    local_840 = (unsigned char *)0x0;
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    newType = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x28);
    local_830 = *(unsigned char **)(yyvsp + 0x10);
    local_82c = *(unsigned char **)(yyvsp + 0x14);
    typeSpecifierSize = *(unsigned char **)(yyvsp + 0x18);
    typeSpecifierMatrix = *(unsigned char **)(yyvsp + 0x1c);
    picBase2 = (unsigned char *)0xa7b8374c;
    local_820 = *(unsigned char **)(yyvsp + 0x20);
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
    uVar2 = *(uint *)(newType + 0x24);
    qualifierBits2 = (int)local_82c << 0x19;
    *(uint *)(newType + 0x24) = qualifierBits2 | uVar2 & 0x1ffffff;
    basicTypeBits2 = ((uint)local_830 & 0x3f) << 0x13;
    *(uint *)(newType + 0x24) = basicTypeBits2 | qualifierBits2 | uVar2 & 0x7ffff;
    sizeBits = ((uint)typeSpecifierSize & 0xff) << 0xb;
    *(uint *)(newType + 0x24) = sizeBits | basicTypeBits2 | qualifierBits2 | uVar2 & 0x7ff;
    uVar58 = ((uint)typeSpecifierMatrix & 1) << 10;
    *(uint *)(newType + 0x24) = uVar58 | sizeBits | basicTypeBits2 | qualifierBits2 | uVar2 & 0x3ff;
    *(uint *)(newType + 0x24) =
         ((uint)local_820 & 1) << 9 | uVar58 | sizeBits | basicTypeBits2 | qualifierBits2 | uVar2 & 0x1ff;
    local_81c = (unsigned char *)scratchR7;
    local_818 = (unsigned char *)scratchR6;
    local_810 = local_830;
    local_80c = local_82c;
    local_808 = typeSpecifierSize;
    local_804 = typeSpecifierMatrix;
    local_800 = local_820;
    local_7fc = (unsigned char *)scratchR7;
    local_7f8 = (unsigned char *)scratchR6;
    if ((unsigned char *)scratchR7 != (unsigned char *)0x0) {
      picBase = (unsigned char *)0xa7b8374c;
      *(uint *)(newType + 8) = *(uint *)(scratchR7 + 8);
      setStructSizeResult3 = TType__setStructSize(newType,*(unsigned char **)(scratchR7 + 8));
      *(undefined4 *)(newType + 0x18) = setStructSizeResult3;
      iVar55 = (**(code **)(*(uint *)local_7fc + 0x18))(local_7fc);
      *(undefined1 *)(*(int *)(iVar55 + 4) + *(int *)(*(int *)(iVar55 + 4) + -0xc)) =
           **(undefined1 **)(picBase + -0x7cc4);
      pcVar62 = *(char **)(iVar55 + 4);
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      pvVar13 = (void *)TPoolAllocator__allocate(poolAllocator,8);
      cr0 = (pvVar13 == (void *)0x0) << 1;
      pvVar23 = (void *)0x0;
      if (pvVar13 != (void *)0x0) {
        ctorAlloc11[0] = GetGlobalPoolAllocator();
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                  (pvVar13,pcVar62,(unsigned char *)ctorAlloc11);
        pvVar23 = pvVar13;
      }
      *(void **)(newType + 0x10) = pvVar23;
    }
    yyvalTypeOrFunction = local_840;
    local_850 = local_840;
    pTVar3 = yyvalNode;
    yyvalQualifierOrParamType = (unsigned char *)newType;
    local_84c = (unsigned char *)newType;
    local_83c = (unsigned char *)newType;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x73:
    picBase2 = (unsigned char *)0xa7b8374c;
    if (*(uint *)(yyvsp + -100) != 0) {
      local_810 = *(unsigned char **)(yyvsp + -0x74);
      typeSpecifierQualifierOrParamType = *(unsigned char **)(yyvsp + -0x70);
      typeSpecifierSize2 = *(unsigned char **)(yyvsp + -0x6c);
      typeSpecifierMatrix2 = *(unsigned char **)(yyvsp + -0x68);
      local_7fc = *(unsigned char **)(yyvsp + -0x60);
      local_800 = *(unsigned char **)(yyvsp + -100);
      typeSpecifierTypeLine = *(unsigned char **)(yyvsp + -0x5c);
      uVar16 = 0xa7b8374c;
      local_81c = (unsigned char *)
                  (((uint)local_800 & 1) << 9 |
                  ((uint)typeSpecifierMatrix2 & 1) << 10 |
                  ((uint)typeSpecifierSize2 & 0xff) << 0xb |
                  ((uint)local_810 & 0x3f) << 0x13 | (int)typeSpecifierQualifierOrParamType << 0x19 | (uint)local_81c & 0x1ff)
      ;
      local_840 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
      local_820 = (unsigned char *)0x0;
      local_83c = (unsigned char *)0x0;
      local_838 = (unsigned char *)0x0;
      local_834 = (unsigned char *)0x0;
      local_830 = (unsigned char *)0x0;
      local_82c = (unsigned char *)0x0;
      local_828 = (unsigned char *)0x0;
      local_824 = (unsigned char *)0x0;
      picBase = (unsigned char *)0xa7b8374c;
      pTVar3 = local_830;
      local_80c = typeSpecifierQualifierOrParamType;
      local_808 = typeSpecifierSize2;
      local_804 = typeSpecifierMatrix2;
      local_7f8 = typeSpecifierTypeLine;
      local_7f0 = local_810;
      local_7ec = typeSpecifierQualifierOrParamType;
      local_7e8 = typeSpecifierSize2;
      local_7e4 = typeSpecifierMatrix2;
      local_7e0 = local_800;
      local_7dc = local_7fc;
      local_7d8 = typeSpecifierTypeLine;
      if (local_7fc != (unsigned char *)0x0) {
        local_838 = *(unsigned char **)(local_7fc + 8);
        setStructSizeResult2 = TType__setStructSize((unsigned char *)&local_840,*(unsigned char **)(local_7fc + 8));
        local_828 = (unsigned char *)((ulonglong)setStructSizeResult2 >> 0x20);
        iVar55 = (**(code **)(*(uint *)local_7dc + 0x18))
                           (local_7dc,(int)setStructSizeResult2,typeSpecifierTypeLine,typeSpecifierMatrix2,typeSpecifierSize2,typeSpecifierQualifierOrParamType,*(uint *)local_7dc)
        ;
        *(undefined1 *)(*(int *)(iVar55 + 4) + *(int *)(*(int *)(iVar55 + 4) + -0xc)) =
             **(undefined1 **)(picBase + -0x7cc4);
        pcVar62 = *(char **)(iVar55 + 4);
        poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
        pTVar7 = (unsigned char *)TPoolAllocator__allocate(poolAllocator,8);
        cr0 = (pTVar7 == (unsigned char *)0x0) << 1;
        pTVar3 = (unsigned char *)0x0;
        if (pTVar7 != (unsigned char *)0x0) {
          ctorAlloc12[0] = GetGlobalPoolAllocator();
          __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                    (pTVar7,pcVar62,(unsigned char *)ctorAlloc12);
          pTVar3 = pTVar7;
        }
      }
      local_830 = pTVar3;
      TType__getCompleteString(&local_850,(unsigned char *)&local_840);
      local_84c[*(uint *)(local_84c + -0xc)] = **(unsigned char **)(picBase + -0x7cc4);
      TParseContext__error
                ((int)parseContext,*(char **)(yyvsp + -0x58),"cannot declare arrays of this type",
                 (char *)local_84c,"",picBase,local_84c,uVar16);
      refCountPtr = local_84c + -4;
      destroyAlloc61[0] = local_850;
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
                  ((unsigned char *)(local_84c + -0xc),destroyAlloc61);
      }
      local_840 = picBase2 + -0x610c;
      TParseContext__recover(parseContext);
    }
    *(uint *)(yyvsp + -100) = 1;
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    newType = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x28);
    local_850 = *(unsigned char **)(yyvsp + -0x74);
    typeSpecifierQualifierOrParamType2 = *(unsigned char **)(yyvsp + -0x70);
    local_848 = *(unsigned char **)(yyvsp + -0x6c);
    local_844 = *(unsigned char **)(yyvsp + -0x68);
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
    uVar2 = *(uint *)(newType + 0x24);
    qualifierBits2 = (int)typeSpecifierQualifierOrParamType2 << 0x19;
    *(uint *)(newType + 0x24) = qualifierBits2 | uVar2 & 0x1ffffff;
    basicTypeBits2 = ((uint)local_850 & 0x3f) << 0x13;
    *(uint *)(newType + 0x24) = basicTypeBits2 | qualifierBits2 | uVar2 & 0x7ffff;
    sizeBits = ((uint)local_848 & 0xff) << 0xb;
    *(uint *)(newType + 0x24) = sizeBits | basicTypeBits2 | qualifierBits2 | uVar2 & 0x7ff;
    uVar58 = ((uint)local_844 & 1) << 10;
    *(uint *)(newType + 0x24) = uVar58 | sizeBits | basicTypeBits2 | qualifierBits2 | uVar2 & 0x3ff;
    *(uint *)(newType + 0x24) =
         ((uint)scratchR7 & 1) << 9 | uVar58 | sizeBits | basicTypeBits2 | qualifierBits2 | uVar2 & 0x1ff;
    local_840 = (unsigned char *)scratchR7;
    local_83c = (unsigned char *)scratchR6;
    local_830 = local_850;
    local_82c = typeSpecifierQualifierOrParamType2;
    local_828 = local_848;
    local_824 = local_844;
    local_820 = (unsigned char *)scratchR7;
    local_81c = (unsigned char *)scratchR6;
    local_818 = typeSpecifierTypeLine2;
    if ((unsigned char *)scratchR6 != (unsigned char *)0x0) {
      picBase = (unsigned char *)0xa7b8374c;
      *(uint *)(newType + 8) = *(uint *)(scratchR6 + 8);
      setStructSizeResult3 = TType__setStructSize(newType,*(unsigned char **)(scratchR6 + 8));
      *(undefined4 *)(newType + 0x18) = setStructSizeResult3;
      iVar55 = (**(code **)(*(uint *)local_81c + 0x18))(local_81c);
      *(undefined1 *)(*(int *)(iVar55 + 4) + *(int *)(*(int *)(iVar55 + 4) + -0xc)) =
           **(undefined1 **)(picBase + -0x7cc4);
      pcVar62 = *(char **)(iVar55 + 4);
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      pvVar13 = (void *)TPoolAllocator__allocate(poolAllocator,8);
      cr0 = (pvVar13 == (void *)0x0) << 1;
      pvVar23 = (void *)0x0;
      if (pvVar13 != (void *)0x0) {
        ctorAlloc13[0] = GetGlobalPoolAllocator();
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                  (pvVar13,pcVar62,(unsigned char *)ctorAlloc13);
        pvVar23 = pvVar13;
      }
      *(void **)(newType + 0x10) = pvVar23;
    }
    constantUnion = (**(code **)(**(int **)(yyvsp + -0x24) + 0x18))(*(int **)(yyvsp + -0x24));
    if (constantUnion != 0) {
      constantUnion = (**(code **)(**(int **)(yyvsp + -0x24) + 0x18))(*(int **)(yyvsp + -0x24));
      uVar16 = **(undefined4 **)(constantUnion + 0x30);
      *(uint *)(newType + 0x24) = *(uint *)(newType + 0x24) | 0x200;
      *(undefined4 *)(newType + 4) = uVar16;
    }
    local_850 = (unsigned char *)0x0;
    yyval = *(uint *)(yyvsp + -0x58);
    pTVar3 = yyvalNode;
    yyvalTypeOrFunction = local_850;
    yyvalQualifierOrParamType = (unsigned char *)newType;
    local_84c = (unsigned char *)newType;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x74:
    _memcpy(&yyval,yyvsp,0x2c);
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x75:
    _memcpy(&yyval,yyvsp + -0x58,0x2c);
    uVar57 = *(uint *)yyvsp;
    pTVar27 = (unsigned char *)(yyvsp + -0x48);
    goto LAB_97ba9874;
  case 0x76:
    _memcpy(&yyval,yyvsp + -0xb0,0x2c);
    structQualifierError = TParseContext__structQualifierErrorCheck
                       (parseContext,*(uint *)(yyvsp + -0x58),(unsigned char *)(yyvsp + -0xa0),scratchR6,
                        scratchR7,pTVar33,pTVar34);
    if (structQualifierError != 0) {
      TParseContext__recover(parseContext);
    }
    psVar21 = *(unsigned char **)(yyvsp + -0x2c);
    uVar57 = *(uint *)(yyvsp + -0x54);
    uVar28 = 0;
    goto LAB_97ba99f8;
  case 0x77:
    _memcpy(&yyval,yyvsp + -0xdc,0x2c);
    uVar57 = *(uint *)(yyvsp + -0x84);
    pTVar27 = (unsigned char *)(yyvsp + -0xcc);
    goto LAB_97ba99a0;
  case 0x78:
    pTVar59 = yyvsp + -0xa0;
    _memcpy(&yyval,yyvsp + -0xb0,0x2c);
    structQualifierError = TParseContext__structQualifierErrorCheck
                       (parseContext,*(uint *)(yyvsp + -0x58),(unsigned char *)pTVar59,scratchR6,scratchR7,
                        pTVar33,pTVar34);
    if (structQualifierError != 0) {
      TParseContext__recover(parseContext);
    }
    scratchR7 = *(char **)(yyvsp + 8);
    executeInitializerResult = TParseContext__executeInitializer
                       (parseContext,*(uint *)(yyvsp + -0x58),*(unsigned char **)(yyvsp + -0x54),
                        (unsigned char *)pTVar59,(unsigned char *)scratchR7,&local_80);
    if (executeInitializerResult == 0) {
      if (local_80 != (unsigned char *)0x0) {
        pTVar15 = *(unsigned char **)parseContext;
        pTVar22 = *(unsigned char **)(yyvsp + -0xa8);
        pTVar20 = local_80;
        goto LAB_97ba97d4;
      }
      scratchR6 = (char *)pTVar59;
      pTVar3 = *(unsigned char **)(yyvsp + -0xa8);
      pTVar31 = local_7f0;
      pTVar32 = local_750[0];
      break;
    }
    goto LAB_97bab1f4;
  case 0x79:
    yyvalTypeOrFunction = *(unsigned char **)(yyvsp + 0x10);
    yyvalQualifierOrParamType = *(unsigned char **)(yyvsp + 0x14);
    yyvalSize = *(unsigned char **)(yyvsp + 0x18);
    yyvalMatrix = *(unsigned char **)(yyvsp + 0x1c);
    yyvalArray = *(unsigned char **)(yyvsp + 0x20);
    yyvalUserDef = *(unsigned char **)(yyvsp + 0x24);
    yyvalTypeLine = *(unsigned char **)(yyvsp + 0x28);
    pTVar3 = (unsigned char *)0x0;
    break;
  case 0x7a:
    yyvalNode = (unsigned char *)0x0;
    pTVar27 = (unsigned char *)(yyvsp + -0x1c);
    yyvalTypeOrFunction = *(unsigned char **)(yyvsp + -0x1c);
    yyvalQualifierOrParamType = *(unsigned char **)(yyvsp + -0x18);
    yyvalSize = *(unsigned char **)(yyvsp + -0x14);
    yyvalMatrix = *(unsigned char **)(yyvsp + -0x10);
    yyvalArray = *(unsigned char **)(yyvsp + -0xc);
    yyvalUserDef = *(unsigned char **)(yyvsp + -8);
    pTVar34 = *(unsigned char **)(yyvsp + -4);
    uVar57 = *(uint *)yyvsp;
    yyvalTypeLine = pTVar34;
LAB_97ba9874:
    structQualifierError = TParseContext__structQualifierErrorCheck
                       (parseContext,uVar57,pTVar27,scratchR6,scratchR7,pTVar33,pTVar34);
    if (structQualifierError != 0) {
      TParseContext__recover(parseContext);
    }
    scratchR6 = (char *)&yyvalTypeOrFunction;
    iVar55 = TParseContext__nonInitErrorCheck
                       (parseContext,*(uint *)yyvsp,*(unsigned char **)(yyvsp + 4),(unsigned char *)scratchR6);
    goto LAB_97bab180;
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
                        scratchR7,pTVar33,yyvalTypeLine);
    if (structQualifierError != 0) {
      TParseContext__recover(parseContext);
    }
    psVar21 = *(unsigned char **)(yyvsp + -0x2c);
    uVar57 = *(uint *)(yyvsp + -0x54);
    local_850 = yyvalTypeOrFunction;
    local_84c = yyvalQualifierOrParamType;
    local_848 = yyvalSize;
    local_844 = yyvalMatrix;
    local_840 = yyvalArray;
    local_83c = yyvalUserDef;
    local_838 = yyvalTypeLine;
    puVar4[0x10] = 0;
    puVar4[0xf] = yyvalTypeLine;
    goto LAB_97ba9a08;
  case 0x7c:
    yyvalNode = (unsigned char *)0x0;
    pTVar27 = (unsigned char *)(yyvsp + -0xa0);
    yyvalTypeOrFunction = *(unsigned char **)(yyvsp + -0xa0);
    yyvalQualifierOrParamType = *(unsigned char **)(yyvsp + -0x9c);
    yyvalSize = *(unsigned char **)(yyvsp + -0x98);
    yyvalMatrix = *(unsigned char **)(yyvsp + -0x94);
    yyvalArray = *(unsigned char **)(yyvsp + -0x90);
    yyvalUserDef = *(unsigned char **)(yyvsp + -0x8c);
    pTVar34 = *(unsigned char **)(yyvsp + -0x88);
    uVar57 = *(uint *)(yyvsp + -0x84);
    yyvalTypeLine = pTVar34;
LAB_97ba99a0:
    structQualifierError = TParseContext__structQualifierErrorCheck
                       (parseContext,uVar57,pTVar27,scratchR6,scratchR7,pTVar33,pTVar34);
    if (structQualifierError != 0) {
      TParseContext__recover(parseContext);
    }
    psVar21 = *(unsigned char **)(yyvsp + -0x58);
    uVar57 = *(uint *)(yyvsp + -0x80);
    uVar28 = *(uint *)(yyvsp + -0x24);
LAB_97ba99f8:
    puVar4[0x10] = uVar28;
    puVar4[0xf] = yyvalTypeLine;
    local_850 = yyvalTypeOrFunction;
    local_84c = yyvalQualifierOrParamType;
    local_848 = yyvalSize;
    local_844 = yyvalMatrix;
    local_840 = yyvalArray;
    local_83c = yyvalUserDef;
    local_838 = yyvalTypeLine;
LAB_97ba9a08:
    puVar4[0xe] = local_83c;
    scratchR6 = (char *)local_850;
    scratchR7 = (char *)local_84c;
    yyvalTypeOrFunction = local_850;
    yyvalQualifierOrParamType = local_84c;
    yyvalSize = local_848;
    yyvalMatrix = local_844;
    yyvalArray = local_840;
    yyvalUserDef = local_83c;
    yyvalTypeLine = local_838;
    iVar55 = TParseContext__arrayErrorCheck
                       ((int)parseContext,psVar21,uVar57,local_850,local_84c,local_848,local_844,
                        local_840,puVar4[0xe],puVar4[0xf],puVar4[0x10]);
    goto LAB_97bab180;
  case 0x7d:
    yyvalTypeOrFunction = *(unsigned char **)(yyvsp + -0x74);
    pTVar59 = yyvsp + -0x74;
    yyvalQualifierOrParamType = *(unsigned char **)(yyvsp + -0x70);
    yyvalSize = *(unsigned char **)(yyvsp + -0x6c);
    yyvalMatrix = *(unsigned char **)(yyvsp + -0x68);
    yyvalArray = *(unsigned char **)(yyvsp + -100);
    yyvalUserDef = *(unsigned char **)(yyvsp + -0x60);
    yyvalTypeLine = *(unsigned char **)(yyvsp + -0x5c);
    structQualifierError = TParseContext__structQualifierErrorCheck
                       (parseContext,*(uint *)(yyvsp + -0x58),(unsigned char *)pTVar59,scratchR6,scratchR7,
                        pTVar33,yyvalTypeLine);
    if (structQualifierError != 0) {
      TParseContext__recover(parseContext);
    }
    scratchR7 = *(char **)(yyvsp + 8);
    executeInitializerResult = TParseContext__executeInitializer
                       (parseContext,*(uint *)(yyvsp + -0x58),*(unsigned char **)(yyvsp + -0x54),
                        (unsigned char *)pTVar59,(unsigned char *)scratchR7,&local_7c);
    if (executeInitializerResult != 0) goto LAB_97bab1f4;
    if (local_7c != (unsigned char *)0x0) {
      pTVar15 = *(unsigned char **)parseContext;
      uVar57 = *(uint *)(yyvsp + -0x2c);
      pTVar20 = local_7c;
      scratchR6 = (char *)pTVar59;
      goto LAB_97bab0ec;
    }
    goto switchD_97ba39c8_caseD_60;
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
    typeSpecifierTypeOrFunction = *(unsigned char **)(yyvsp + 0x10);
    local_84c = *(unsigned char **)(yyvsp + -0x18);
    typeSpecifierSize3 = *(unsigned char **)(yyvsp + 0x18);
    local_844 = *(unsigned char **)(yyvsp + 0x1c);
    local_820 = (unsigned char *)0x0;
    typeSpecifierUserDef = *(unsigned char **)(yyvsp + 0x24);
    local_838 = (unsigned char *)0x0;
    local_818 = (unsigned char *)0x0;
    local_840 = (unsigned char *)0x0;
    typeQualifierQualifierOrParamType = *(uint *)(yyvsp + -0x18);
    local_850 = typeSpecifierTypeOrFunction;
    local_848 = typeSpecifierSize3;
    local_83c = typeSpecifierUserDef;
    local_830 = typeSpecifierTypeOrFunction;
    local_82c = local_84c;
    local_828 = typeSpecifierSize3;
    local_824 = local_844;
    local_81c = typeSpecifierUserDef;
    if ((typeQualifierQualifierOrParamType == 3) && (*(uint *)(yyvsp + 0x10) - 2 < 2)) {
      scratchR6 = (char *)getQualifierString(3);
      scratchR7 = "";
      TParseContext__error
                ((int)parseContext,*(char **)(yyvsp + 0x28),"cannot be bool or int",scratchR6,"",typeSpecifierTypeOrFunction,
                 typeSpecifierUserDef,typeSpecifierSize3);
      TParseContext__recover(parseContext);
      typeQualifierQualifierOrParamType = *(uint *)(yyvsp + -0x18);
    }
    if ((typeQualifierQualifierOrParamType - 4 < 2) && (*(uint *)(yyvsp + 0x10) - 2 < 2)) {
      scratchR6 = (char *)getQualifierString(typeQualifierQualifierOrParamType);
      scratchR7 = "";
      TParseContext__error
                ((int)parseContext,*(char **)(yyvsp + 0x28),"cannot be bool or int",scratchR6,"",typeSpecifierTypeOrFunction,
                 typeSpecifierUserDef,typeSpecifierSize3);
      TParseContext__recover(parseContext);
    }
    goto LAB_97ba9d1c;
  case 0x80:
    puVar25 = &DAT_97c356fc;
    goto LAB_97ba9da4;
  case 0x81:
    if (*(int *)((int)parseContext + 0xc) != 0) {
      scratchR7 = "";
      pTVar33 = (unsigned char *)scratchR7;
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," supported in vertex shaders only ","attribute","",
                 "",pTVar34,scratchR10);
      TParseContext__recover(parseContext);
    }
    globalError = TParseContext__globalErrorCheck
                       (parseContext,*(uint *)yyvsp,
                        (uint)((uint)((*(int **)((int)parseContext + 4))[1] -
                                      **(int **)((int)parseContext + 4) >> 2) < 4),"attribute",scratchR7,
                        pTVar33);
    if (globalError != 0) {
      TParseContext__recover(parseContext);
    }
    puVar25 = &DAT_97c35718;
    goto LAB_97ba9da4;
  case 0x82:
    globalError = TParseContext__globalErrorCheck
                       (parseContext,*(uint *)yyvsp,
                        (uint)((uint)((*(int **)((int)parseContext + 4))[1] -
                                      **(int **)((int)parseContext + 4) >> 2) < 4),"varying",scratchR7,
                        pTVar33);
    if (globalError != 0) {
      TParseContext__recover(parseContext);
    }
    scratchR6 = (char *)0x0;
    scratchR7 = (char *)0x0;
    local_850 = (unsigned char *)0x0;
    local_84c = (unsigned char *)0x4;
    local_848 = (unsigned char *)0x1;
    local_844 = (unsigned char *)0x0;
    local_840 = (unsigned char *)0x0;
    local_83c = (unsigned char *)0x0;
    local_838 = (unsigned char *)0x0;
    if (*(int *)((int)parseContext + 0xc) == 0) {
      local_84c = (unsigned char *)0x5;
    }
LAB_97ba9d1c:
    yyvalTypeOrFunction = local_850;
    yyvalQualifierOrParamType = local_84c;
    yyvalSize = local_848;
    yyvalMatrix = local_844;
    yyvalArray = local_840;
    yyvalUserDef = local_83c;
    yyvalTypeLine = local_838;
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x83:
    globalError = TParseContext__globalErrorCheck
                       (parseContext,*(uint *)yyvsp,
                        (uint)((uint)((*(int **)((int)parseContext + 4))[1] -
                                      **(int **)((int)parseContext + 4) >> 2) < 4),"uniform",scratchR7,
                        pTVar33);
    if (globalError != 0) {
      TParseContext__recover(parseContext);
    }
    puVar25 = &DAT_97c35750;
LAB_97ba9da4:
    yyvalTypeLine = (unsigned char *)puVar25[6];
    yyvalSize = (unsigned char *)puVar25[2];
    yyvalMatrix = (unsigned char *)puVar25[3];
    yyvalArray = (unsigned char *)puVar25[4];
    scratchR7 = (char *)puVar25[5];
    scratchR6 = (char *)yyvalTypeLine;
    pTVar3 = yyvalNode;
    yyvalTypeOrFunction = (unsigned char *)*puVar25;
    yyvalQualifierOrParamType = (unsigned char *)puVar25[1];
    yyvalUserDef = (unsigned char *)scratchR7;
    local_850 = (unsigned char *)*puVar25;
    local_84c = (unsigned char *)puVar25[1];
    local_848 = yyvalSize;
    local_844 = yyvalMatrix;
    local_840 = yyvalArray;
    local_83c = (unsigned char *)scratchR7;
    local_838 = yyvalTypeLine;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x84:
    local_830 = (unsigned char *)0x0;
    local_828 = (unsigned char *)0x1;
    local_824 = (unsigned char *)0x0;
    local_82c = (unsigned char *)
                (uint)((uint)((*(int **)((int)parseContext + 4))[1] - **(int **)((int)parseContext + 4) >> 2)
                      < 4);
    local_820 = (unsigned char *)0x0;
    local_81c = (unsigned char *)0x0;
    yyvalTypeLine = *(unsigned char **)yyvsp;
    yyvalSize = (unsigned char *)0x1;
    yyvalUserDef = (unsigned char *)0x0;
    local_850 = (unsigned char *)0x0;
    local_848 = (unsigned char *)0x1;
    local_844 = (unsigned char *)0x0;
    local_840 = (unsigned char *)0x0;
    local_83c = (unsigned char *)0x0;
    yyvalTypeOrFunction = (unsigned char *)0x0;
    yyvalMatrix = (unsigned char *)0x0;
    yyvalArray = (unsigned char *)0x0;
    yyvalQualifierOrParamType = local_82c;
    local_84c = local_82c;
    local_838 = yyvalTypeLine;
    local_818 = yyvalTypeLine;
    break;
  case 0x85:
    symbolTable = *(int **)((int)parseContext + 4);
    local_830 = (unsigned char *)0x1;
    goto LAB_97ba9f0c;
  case 0x86:
    symbolTable = *(int **)((int)parseContext + 4);
    local_830 = (unsigned char *)0x2;
    goto LAB_97baa3fc;
  case 0x87:
    symbolTable = *(int **)((int)parseContext + 4);
    local_830 = (unsigned char *)0x3;
    goto LAB_97baa3fc;
  case 0x88:
    symbolTable = *(int **)((int)parseContext + 4);
    local_830 = (unsigned char *)0x1;
    goto LAB_97ba9eec;
  case 0x89:
    symbolTable = *(int **)((int)parseContext + 4);
    local_830 = (unsigned char *)0x1;
    goto LAB_97ba9fa8;
  case 0x8a:
    symbolTable = *(int **)((int)parseContext + 4);
    local_830 = (unsigned char *)0x1;
    goto LAB_97ba9fc8;
  case 0x8b:
    symbolTable = *(int **)((int)parseContext + 4);
    local_830 = (unsigned char *)0x3;
LAB_97ba9eec:
    iVar55 = symbolTable[1] - *symbolTable;
    local_828 = (unsigned char *)0x2;
    goto LAB_97baa40c;
  case 0x8c:
    symbolTable = *(int **)((int)parseContext + 4);
    local_830 = (unsigned char *)0x3;
    goto LAB_97ba9f0c;
  case 0x8d:
    symbolTable = *(int **)((int)parseContext + 4);
    local_830 = (unsigned char *)0x3;
    goto LAB_97ba9fc8;
  case 0x8e:
    symbolTable = *(int **)((int)parseContext + 4);
    local_830 = (unsigned char *)0x2;
LAB_97ba9f0c:
    iVar55 = symbolTable[1] - *symbolTable;
    local_818 = *(unsigned char **)yyvsp;
    local_828 = local_830;
    goto LAB_97baa46c;
  case 0x8f:
    symbolTable = *(int **)((int)parseContext + 4);
    local_830 = (unsigned char *)0x2;
LAB_97ba9fa8:
    iVar55 = symbolTable[1] - *symbolTable;
    local_828 = (unsigned char *)0x3;
    goto LAB_97baa40c;
  case 0x90:
    symbolTable = *(int **)((int)parseContext + 4);
    local_830 = (unsigned char *)0x2;
LAB_97ba9fc8:
    iVar55 = symbolTable[1] - *symbolTable;
    local_828 = (unsigned char *)0x4;
    goto LAB_97baa40c;
  case 0x91:
    if (1 < *(uint *)((int)parseContext + 0xc)) {
      scratchR7 = "";
      scratchR6 = "mat2";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," supported in vertex/fragment shaders only ","mat2"
                 ,"","",pTVar34,scratchR10);
      TParseContext__recover(parseContext);
    }
    iVar55 = (*(int **)((int)parseContext + 4))[1] - **(int **)((int)parseContext + 4);
    yyvalSize = (unsigned char *)0x2;
    goto LAB_97baa0ec;
  case 0x92:
    if (1 < *(uint *)((int)parseContext + 0xc)) {
      scratchR7 = "";
      scratchR6 = "mat3";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," supported in vertex/fragment shaders only ","mat3"
                 ,"","",pTVar34,scratchR10);
      TParseContext__recover(parseContext);
    }
    iVar55 = (*(int **)((int)parseContext + 4))[1] - **(int **)((int)parseContext + 4);
    yyvalSize = (unsigned char *)0x3;
    goto LAB_97baa0ec;
  case 0x93:
    if (1 < *(uint *)((int)parseContext + 0xc)) {
      scratchR7 = "";
      scratchR6 = "mat4";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," supported in vertex/fragment shaders only ","mat4"
                 ,"","",pTVar34,scratchR10);
      TParseContext__recover(parseContext);
    }
    iVar55 = (*(int **)((int)parseContext + 4))[1] - **(int **)((int)parseContext + 4);
    yyvalSize = (unsigned char *)0x4;
LAB_97baa0ec:
    local_82c = (unsigned char *)(uint)((uint)(iVar55 >> 2) < 4);
    local_830 = (unsigned char *)0x1;
    local_824 = (unsigned char *)0x1;
    local_820 = (unsigned char *)0x0;
    local_81c = (unsigned char *)0x0;
    yyvalTypeLine = *(unsigned char **)yyvsp;
    yyvalMatrix = (unsigned char *)0x1;
    yyvalUserDef = (unsigned char *)0x0;
    local_850 = (unsigned char *)0x1;
    local_844 = (unsigned char *)0x1;
    local_840 = (unsigned char *)0x0;
    local_83c = (unsigned char *)0x0;
    yyvalTypeOrFunction = (unsigned char *)0x1;
    yyvalArray = (unsigned char *)0x0;
    pTVar3 = yyvalNode;
    yyvalQualifierOrParamType = local_82c;
    local_84c = local_82c;
    local_848 = yyvalSize;
    local_838 = yyvalTypeLine;
    local_828 = yyvalSize;
    local_818 = yyvalTypeLine;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x94:
    if (1 < *(uint *)((int)parseContext + 0xc)) {
      scratchR7 = "";
      scratchR6 = "sampler1D";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," supported in vertex/fragment shaders only ",
                 "sampler1D","","",pTVar34,scratchR10);
      TParseContext__recover(parseContext);
    }
    symbolTable = *(int **)((int)parseContext + 4);
    local_830 = (unsigned char *)0x5;
    goto LAB_97baa3fc;
  case 0x95:
    if (1 < *(uint *)((int)parseContext + 0xc)) {
      scratchR7 = "";
      scratchR6 = "sampler2D";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," supported in vertex/fragment shaders only ",
                 "sampler2D","","",pTVar34,scratchR10);
      TParseContext__recover(parseContext);
    }
    symbolTable = *(int **)((int)parseContext + 4);
    local_830 = (unsigned char *)0x6;
    goto LAB_97baa3fc;
  case 0x96:
    if (1 < *(uint *)((int)parseContext + 0xc)) {
      scratchR7 = "";
      scratchR6 = "sampler3D";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," supported in vertex/fragment shaders only ",
                 "sampler3D","","",pTVar34,scratchR10);
      TParseContext__recover(parseContext);
    }
    symbolTable = *(int **)((int)parseContext + 4);
    local_830 = (unsigned char *)0x7;
    goto LAB_97baa3fc;
  case 0x97:
    if (1 < *(uint *)((int)parseContext + 0xc)) {
      scratchR7 = "";
      scratchR6 = "samplerCube";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," supported in vertex/fragment shaders only ",
                 "samplerCube","","",pTVar34,scratchR10);
      TParseContext__recover(parseContext);
    }
    symbolTable = *(int **)((int)parseContext + 4);
    local_830 = (unsigned char *)0x8;
    goto LAB_97baa3fc;
  case 0x98:
    if (1 < *(uint *)((int)parseContext + 0xc)) {
      scratchR7 = "";
      scratchR6 = "sampler1DShadow";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," supported in vertex/fragment shaders only ",
                 "sampler1DShadow","","",pTVar34,scratchR10);
      TParseContext__recover(parseContext);
    }
    symbolTable = *(int **)((int)parseContext + 4);
    local_830 = (unsigned char *)0x9;
    goto LAB_97baa3fc;
  case 0x99:
    if (1 < *(uint *)((int)parseContext + 0xc)) {
      scratchR7 = "";
      scratchR6 = "sampler2DShadow";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," supported in vertex/fragment shaders only ",
                 "sampler2DShadow","","",pTVar34,scratchR10);
      TParseContext__recover(parseContext);
    }
    symbolTable = *(int **)((int)parseContext + 4);
    local_830 = (unsigned char *)0xa;
    goto LAB_97baa3fc;
  case 0x9a:
    if (1 < *(uint *)((int)parseContext + 0xc)) {
      scratchR7 = "";
      scratchR6 = "sampler2DRect";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," supported in vertex/fragment shaders only ",
                 "sampler2DRect","","",pTVar34,scratchR10);
      TParseContext__recover(parseContext);
    }
    extensionError = TParseContext__extensionErrorCheck(parseContext,*(uint *)yyvsp,"GL_ARB_texture_rectangle")
    ;
    if (extensionError != 0) {
      TParseContext__recover(parseContext);
    }
    symbolTable = *(int **)((int)parseContext + 4);
    local_830 = (unsigned char *)0xb;
    goto LAB_97baa3fc;
  case 0x9b:
    if (1 < *(uint *)((int)parseContext + 0xc)) {
      scratchR7 = "";
      scratchR6 = "sampler2DRectShadow";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp," supported in vertex/fragment shaders only ",
                 "sampler2DRectShadow","","",pTVar34,scratchR10);
      TParseContext__recover(parseContext);
    }
    extensionError = TParseContext__extensionErrorCheck(parseContext,*(uint *)yyvsp,"GL_ARB_texture_rectangle")
    ;
    if (extensionError != 0) {
      TParseContext__recover(parseContext);
    }
    symbolTable = *(int **)((int)parseContext + 4);
    local_830 = (unsigned char *)0xc;
LAB_97baa3fc:
    iVar55 = symbolTable[1] - *symbolTable;
    local_828 = (unsigned char *)0x1;
LAB_97baa40c:
    local_818 = *(unsigned char **)yyvsp;
LAB_97baa46c:
    local_82c = (unsigned char *)(uint)((uint)(iVar55 >> 2) < 4);
    local_81c = (unsigned char *)0x0;
    local_820 = (unsigned char *)0x0;
    local_824 = (unsigned char *)0x0;
    local_83c = (unsigned char *)0x0;
    local_840 = (unsigned char *)0x0;
    local_844 = (unsigned char *)0x0;
    yyvalUserDef = (unsigned char *)0x0;
    yyvalMatrix = (unsigned char *)0x0;
    yyvalArray = (unsigned char *)0x0;
    pTVar3 = yyvalNode;
    yyvalTypeOrFunction = local_830;
    yyvalQualifierOrParamType = local_82c;
    yyvalSize = local_828;
    yyvalTypeLine = local_818;
    local_850 = local_830;
    local_84c = local_82c;
    local_848 = local_828;
    local_838 = local_818;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x9c:
    if (1 < *(uint *)((int)parseContext + 0xc)) {
      scratchR7 = "";
      scratchR6 = "struct";
      TParseContext__error
                ((int)parseContext,*(char **)(yyvsp + 0x28),
                 " supported in vertex/fragment shaders only ","struct","","",pTVar34,scratchR10);
      TParseContext__recover(parseContext);
    }
    yyvalSize = *(unsigned char **)(yyvsp + 0x18);
    yyvalMatrix = *(unsigned char **)(yyvsp + 0x1c);
    yyvalArray = *(unsigned char **)(yyvsp + 0x20);
    yyvalUserDef = *(unsigned char **)(yyvsp + 0x24);
    yyvalTypeLine = *(unsigned char **)(yyvsp + 0x28);
    pTVar3 = yyvalNode;
    yyvalTypeOrFunction = *(unsigned char **)(yyvsp + 0x10);
    yyvalQualifierOrParamType = (unsigned char *)
                (uint)((uint)((*(int **)((int)parseContext + 4))[1] - **(int **)((int)parseContext + 4) >> 2)
                      < 4);
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x9d:
    yyvalUserDef = (unsigned char *)(*(uint *)(yyvsp + 8) + 0xc);
    local_830 = (unsigned char *)0xe;
    local_828 = (unsigned char *)0x1;
    local_824 = (unsigned char *)0x0;
    local_82c = (unsigned char *)
                (uint)((uint)((*(int **)((int)parseContext + 4))[1] - **(int **)((int)parseContext + 4) >> 2)
                      < 4);
    local_820 = (unsigned char *)0x0;
    yyvalTypeLine = *(unsigned char **)yyvsp;
    yyvalTypeOrFunction = (unsigned char *)0xe;
    yyvalSize = (unsigned char *)0x1;
    yyvalArray = (unsigned char *)0x0;
    local_850 = (unsigned char *)0xe;
    local_848 = (unsigned char *)0x1;
    local_844 = (unsigned char *)0x0;
    local_840 = (unsigned char *)0x0;
    yyvalMatrix = (unsigned char *)0x0;
    yyvalQualifierOrParamType = local_82c;
    local_84c = local_82c;
    local_83c = yyvalUserDef;
    local_838 = yyvalTypeLine;
    local_81c = yyvalUserDef;
    local_818 = yyvalTypeLine;
    break;
  case 0x9e:
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    newType = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x28);
    structDeclarationListTypeOrFunction = *(unsigned char **)(yyvsp + -0x1c);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_
              ((unsigned char *)&local_850,*(unsigned char **)(yyvsp + -0x80));
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_((unsigned char *)&local_840,(unsigned char *)&local_850);
    picBase2 = (unsigned char *)0xa7b8374c;
    *(undefined ***)newType = &PTR___ZN5TTypeD1Ev_a7b7d640;
    *(undefined4 *)(newType + 0x20) = 0;
    *(uint *)(newType + 0x24) = *(uint *)(newType + 0x24) & 0x9ff | 0x700800;
    *(undefined4 *)(newType + 4) = 0;
    *(unsigned char **)(newType + 8) = structDeclarationListTypeOrFunction;
    *(undefined4 *)(newType + 0xc) = 0;
    *(undefined4 *)(newType + 0x14) = 0;
    *(undefined4 *)(newType + 0x1c) = 0;
    setStructSizeResult3 = TType__setStructSize(newType,structDeclarationListTypeOrFunction);
    pTVar3 = local_83c;
    picBase = (unsigned char *)0xa7b8374c;
    *(undefined4 *)(newType + 0x18) = setStructSizeResult3;
    local_83c[(int)*(unsigned char **)(local_83c + -0xc)] = *DAT_a7b7ba88;
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    pvVar13 = (void *)TPoolAllocator__allocate(poolAllocator,8);
    cr0 = (pvVar13 == (void *)0x0) << 1;
    pvVar23 = (void *)0x0;
    if (pvVar13 != (void *)0x0) {
      ctorAlloc14[0] = GetGlobalPoolAllocator();
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                (pvVar13,(char *)pTVar3,(unsigned char *)ctorAlloc14);
      pvVar23 = pvVar13;
    }
    *(void **)(newType + 0x10) = pvVar23;
    refCountPtr = local_83c + -4;
    destroyAlloc62[0] = local_840;
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
                ((unsigned char *)(local_83c + -0xc),destroyAlloc62);
    }
    refCountPtr = local_84c + -4;
    destroyAlloc63[0] = local_850;
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
                ((unsigned char *)(local_84c + -0xc),destroyAlloc63);
    }
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    newVariable = (int *)TPoolAllocator__allocate(poolAllocator,0x40);
    puVar5 = PTR_vtable_a7b7c0b4 + 8;
    newVariable[1] = *(uint *)(yyvsp + -0x80);
    *newVariable = (int)puVar5;
    iVar30 = *(int *)(newType + 0xc);
    iVar26 = *(int *)(newType + 0x10);
    scratchR7 = *(char **)(newType + 0x14);
    scratchR6 = *(char **)(newType + 0x18);
    iVar6 = *(int *)(newType + 0x1c);
    iVar60 = *(int *)(newType + 0x20);
    iVar55 = *(int *)(newType + 4);
    iVar54 = *(int *)(newType + 8);
    newVariable[3] = (int)(picBase2 + -0x610c);
    newVariable[6] = iVar30;
    newVariable[7] = iVar26;
    newVariable[8] = (int)scratchR7;
    newVariable[9] = (int)scratchR6;
    newVariable[10] = iVar6;
    newVariable[0xb] = iVar60;
    newVariable[4] = iVar55;
    newVariable[5] = iVar54;
    uVar2 = newVariable[0xc];
    qualifierBits = *(uint *)(newType + 0x24) & 0xfe000000;
    newVariable[0xc] = qualifierBits | uVar2 & 0x1ffffff;
    basicTypeBits = (*(uint *)(newType + 0x24) >> 0x13 & 0x3f) << 0x13;
    newVariable[0xc] = basicTypeBits | qualifierBits | uVar2 & 0x7ffff;
    uVar57 = *(uint *)(newType + 0x24) & 0x7f800;
    newVariable[0xc] = uVar57 | basicTypeBits | qualifierBits | uVar2 & 0x7ff;
    uVar58 = (*(uint *)(newType + 0x24) >> 10 & 1) << 10;
    newVariable[0xc] = uVar58 | uVar57 | basicTypeBits | qualifierBits | uVar2 & 0x3ff;
    newVariable[0xc] = (*(uint *)(newType + 0x24) >> 9 & 1) << 9 |
                   uVar58 | uVar57 | basicTypeBits | qualifierBits | uVar2 & 0x1ff;
    newVariable[0xd] = 1;
    newVariable[0xe] = 0;
    newVariable[0xf] = 0;
    symbolTable2 = *(int **)((int)parseContext + 4);
    nextUniqueId = symbolTable2[3];
    symbolTable2[3] = nextUniqueId + 1;
    newVariable[2] = nextUniqueId + 1;
    uVar16 = *(undefined4 *)(*symbolTable2 + ((symbolTable2[1] - *symbolTable2 & 0xfffffffcU) - 4));
    local_84c = (unsigned char *)0x0;
    psVar21 = (unsigned char *)
              (**(code **)(*newVariable + 8))(newVariable,iVar60,iVar6,scratchR6,scratchR7,iVar26,symbolTable2);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&local_1e0,psVar21);
    local_1d8 = newVariable;
    std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&local_840,uVar16,&local_1e0);
    local_850 = local_840;
    refCountPtr2 = (int *)(local_1dc + -4);
    local_84c = local_83c;
    destroyAlloc64[0] = local_1e0;
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
                ((unsigned char *)(local_1dc + -0xc),destroyAlloc64);
    }
    if (local_84c == (unsigned char *)0x0) {
      identifierString = *(uint *)(yyvsp + -0x80);
      stringData = *(int *)(identifierString + 4);
      scratchR7 = "struct";
      *(unsigned char *)(stringData + *(int *)(stringData + -0xc)) = *DAT_a7b7ba88;
      scratchR6 = *(char **)(identifierString + 4);
      TParseContext__error
                ((int)parseContext,*(char **)(yyvsp + -0x84),"redefinition",scratchR6,"struct",iVar26,
                 stringData,identifierString);
      TParseContext__recover(parseContext);
    }
    local_82c = (unsigned char *)0x0;
    local_830 = (unsigned char *)0xe;
    local_828 = (unsigned char *)0x1;
    local_824 = (unsigned char *)0x0;
    local_820 = (unsigned char *)0x0;
    yyvalTypeLine = *(unsigned char **)(yyvsp + -0xb0);
    yyvalTypeOrFunction = (unsigned char *)0xe;
    yyvalSize = (unsigned char *)0x1;
    yyvalArray = (unsigned char *)0x0;
    local_850 = (unsigned char *)0xe;
    local_84c = (unsigned char *)0x0;
    local_848 = (unsigned char *)0x1;
    local_844 = (unsigned char *)0x0;
    local_840 = (unsigned char *)0x0;
    yyvalQualifierOrParamType = (unsigned char *)0x0;
    yyvalMatrix = (unsigned char *)0x0;
    pTVar3 = yyvalNode;
    yyvalUserDef = (unsigned char *)newType;
    local_83c = (unsigned char *)newType;
    local_838 = yyvalTypeLine;
    local_81c = (unsigned char *)newType;
    local_818 = yyvalTypeLine;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x9f:
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    newType = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x28);
    structDeclarationListTypeOrFunction = *(unsigned char **)(yyvsp + -0x1c);
    ctorAlloc15[0] = GetGlobalPoolAllocator();
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
              ((unsigned char *)&local_850,"",(unsigned char *)ctorAlloc15);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&local_840,(unsigned char *)&local_850);
    picBase2 = (unsigned char *)0xa7b8374c;
    *(undefined ***)newType = &PTR___ZN5TTypeD1Ev_a7b7d640;
    *(undefined4 *)(newType + 0x20) = 0;
    *(uint *)(newType + 0x24) = *(uint *)(newType + 0x24) & 0x9ff | 0x700800;
    *(undefined4 *)(newType + 4) = 0;
    *(unsigned char **)(newType + 8) = structDeclarationListTypeOrFunction;
    *(undefined4 *)(newType + 0xc) = 0;
    *(undefined4 *)(newType + 0x14) = 0;
    *(undefined4 *)(newType + 0x1c) = 0;
    setStructSizeResult3 = TType__setStructSize(newType,structDeclarationListTypeOrFunction);
    pTVar3 = local_83c;
    *(undefined4 *)(newType + 0x18) = setStructSizeResult3;
    picBase = (unsigned char *)0xa7b8374c;
    local_83c[(int)*(unsigned char **)(local_83c + -0xc)] = *DAT_a7b7ba88;
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    pvVar13 = (void *)TPoolAllocator__allocate(poolAllocator,8);
    cr0 = (pvVar13 == (void *)0x0) << 1;
    pvVar23 = (void *)0x0;
    if (pvVar13 != (void *)0x0) {
      ctorAlloc16[0] = GetGlobalPoolAllocator();
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                (pvVar13,(char *)pTVar3,(unsigned char *)ctorAlloc16);
      pvVar23 = pvVar13;
    }
    *(void **)(newType + 0x10) = pvVar23;
    refCountPtr = local_83c + -4;
    destroyAlloc65[0] = local_840;
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
                ((unsigned char *)(local_83c + -0xc),destroyAlloc65);
    }
    refCountPtr = local_84c + -4;
    destroyAlloc66[0] = local_850;
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
                ((unsigned char *)(local_84c + -0xc),destroyAlloc66);
    }
    local_830 = (unsigned char *)0xe;
    local_82c = (unsigned char *)0x0;
    local_828 = (unsigned char *)0x1;
    local_824 = (unsigned char *)0x0;
    local_820 = (unsigned char *)0x0;
    yyvalTypeLine = *(unsigned char **)(yyvsp + -0x84);
    yyvalTypeOrFunction = (unsigned char *)0xe;
    yyvalSize = (unsigned char *)0x1;
    yyvalArray = (unsigned char *)0x0;
    local_850 = (unsigned char *)0xe;
    local_84c = (unsigned char *)0x0;
    local_848 = (unsigned char *)0x1;
    local_844 = (unsigned char *)0x0;
    local_840 = (unsigned char *)0x0;
    yyvalQualifierOrParamType = (unsigned char *)0x0;
    yyvalMatrix = (unsigned char *)0x0;
    pTVar3 = yyvalNode;
    yyvalUserDef = (unsigned char *)newType;
    local_83c = (unsigned char *)newType;
    local_838 = yyvalTypeLine;
    local_81c = (unsigned char *)newType;
    local_818 = yyvalTypeLine;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0xa1:
    yyvalTypeOrFunction = *(unsigned char **)(yyvsp + -0x1c);
    for (loopIndex = 0; yyssBase = DAT_a7b7ba88, pTVar3 = yyvalNode, pTVar31 = local_7f0,
        pTVar32 = local_750[0],
        loopIndex < (uint)(*(int *)(*(uint *)(yyvsp + 0x10) + 8) -
                        *(int *)(*(uint *)(yyvsp + 0x10) + 4) >> 3); loopIndex = loopIndex + 1) {
      loopIndex3 = 0;
      iVar55 = loopIndex * 8;
      while( true ) {
        puVar18 = *(undefined4 **)(yyvalTypeOrFunction + 8);
        if ((uint)((int)puVar18 - *(int *)(yyvalTypeOrFunction + 4) >> 3) <= loopIndex3) break;
        piVar61 = *(int **)(*(int *)(yyvalTypeOrFunction + 4) + loopIndex3 * 8);
        iVar54 = *piVar61;
        iVar54 = (**(code **)(iVar54 + 0x1c))
                           (piVar61,puVar18,scratchR5,scratchR6,scratchR7,pTVar33,iVar54);
        piVar61 = *(int **)(*(int *)(*(uint *)(yyvsp + 0x10) + 4) + iVar55);
        iVar60 = (**(code **)(*piVar61 + 0x1c))
                           (piVar61,r4In10,scratchR5,scratchR6,scratchR7,pTVar33,
                            *(int *)(*(uint *)(yyvsp + 0x10) + 4));
        uVar53 = *(uint *)(*(int *)(iVar54 + 4) + -0xc);
        local_78 = uVar53;
        uVar58 = *(uint *)(*(int *)(iVar60 + 4) + -0xc);
        local_74 = uVar58;
        puVar25 = &local_74;
        if (uVar53 <= uVar58) {
          puVar25 = &local_78;
        }
        scratchR5 = (char *)*puVar25;
        iVar54 = _memcmp(*(undefined4 *)(iVar54 + 4),*(undefined4 *)(iVar60 + 4),scratchR5);
        cr0 = (iVar54 == 0) << 1;
        if (iVar54 == 0) {
          iVar54 = uVar53 - uVar58;
        }
        if (iVar54 == 0) {
          piVar61 = *(int **)(*(int *)(*(uint *)(yyvsp + 0x10) + 4) + iVar55);
          iVar54 = *piVar61;
          iVar54 = (**(code **)(iVar54 + 0x1c))
                             (piVar61,r4In11,scratchR5,scratchR6,scratchR7,pTVar33,iVar54);
          scratchR5 = "duplicate field name in structure:";
          scratchR6 = "struct";
          *(unsigned char *)(*(int *)(iVar54 + 4) + *(int *)(*(int *)(iVar54 + 4) + -0xc)) = *yyssBase;
          scratchR7 = *(char **)(iVar54 + 4);
          TParseContext__error
                    ((int)parseContext,*(char **)(*(int *)(*(uint *)(yyvsp + 0x10) + 4) + iVar55 + 4),
                     "duplicate field name in structure:","struct",scratchR7,pTVar33,
                     *(uint *)(yyvsp + 0x10),scratchR10);
          TParseContext__recover(parseContext);
        }
        loopIndex3 = loopIndex3 + 1;
      }
      scratchR5 = (char *)(*(int *)(*(uint *)(yyvsp + 0x10) + 4) + iVar55);
      if (puVar18 == *(undefined4 **)(yyvalTypeOrFunction + 0xc)) {
        std__vector_TTypeLine_pool_allocator_TTypeLine_____M_insert_aux
                  ((unsigned char *)yyvalTypeOrFunction,puVar18,scratchR5);
      }
      else {
        if (puVar18 != (undefined4 *)0x0) {
          uVar16 = *(undefined4 *)(scratchR5 + 4);
          *puVar18 = *(undefined4 *)(*(int *)(*(uint *)(yyvsp + 0x10) + 4) + iVar55);
          puVar18[1] = uVar16;
        }
        *(int *)(yyvalTypeOrFunction + 8) = *(int *)(yyvalTypeOrFunction + 8) + 8;
      }
    }
    break;
  case 0xa2:
    yyvalTypeOrFunction = *(unsigned char **)(yyvsp + -0x1c);
    piVar61 = (int *)**(undefined4 **)(*(uint *)(yyvsp + -0x1c) + 4);
    psVar21 = (unsigned char *)
              (**(code **)(*piVar61 + 0x1c))
                        (piVar61,scratchR4,scratchR5,scratchR6,scratchR7,pTVar33,
                         *(undefined4 **)(*(uint *)(yyvsp + -0x1c) + 4));
    scratchR6 = (char *)(yyvsp + -0x48);
    voidError = TParseContext__voidErrorCheck
                       (parseContext,*(uint *)(yyvsp + -0x30),psVar21,(unsigned char *)scratchR6);
    if (voidError != 0) {
      TParseContext__recover(parseContext);
    }
    for (loopIndex = 0; pTVar3 = yyvalNode, pTVar31 = local_7f0, pTVar32 = local_750[0],
        loopIndex < (uint)((int)(*(uint *)(yyvalTypeOrFunction + 8) - *(uint *)(yyvalTypeOrFunction + 4)) >> 3);
        loopIndex = loopIndex + 1) {
      piVar61 = *(int **)(*(uint *)(yyvalTypeOrFunction + 4) + loopIndex * 8);
      typeSpecifierSize4 = *(uint *)(yyvsp + -0x40);
      scratchR6 = *(char **)(yyvsp + -0x3c);
      scratchR7 = *(char **)(yyvsp + -0x34);
      (**(code **)(*piVar61 + 0xc))(piVar61,*(uint *)(yyvsp + -0x48),typeSpecifierSize4,scratchR6,scratchR7);
      typeSpecifierUserDef2 = *(int **)(yyvsp + -0x34);
      if (typeSpecifierUserDef2 != (int *)0x0) {
        piVar50 = *(int **)(*(uint *)(yyvalTypeOrFunction + 4) + loopIndex * 8);
        iVar55 = *piVar50;
        uVar16 = (**(code **)(*typeSpecifierUserDef2 + 0x18))
                           (typeSpecifierUserDef2,r4In12,typeSpecifierSize4,scratchR6,scratchR7,pTVar33,*typeSpecifierUserDef2);
        (**(code **)(iVar55 + 0x10))(piVar50,uVar16);
      }
    }
    break;
  case 0xa3:
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    pvVar14 = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x10);
    cr0 = (pvVar14 == (unsigned char *)0x0) << 1;
    pTVar3 = (unsigned char *)(unsigned char *)0x0;
    if (pvVar14 != (unsigned char *)0x0) {
      allocatorArg5 = GetGlobalPoolAllocator();
      *(undefined4 *)(pvVar14 + 0xc) = 0;
      *(undefined4 *)pvVar14 = allocatorArg5;
      *(undefined4 *)(pvVar14 + 4) = 0;
      *(undefined4 *)(pvVar14 + 8) = 0;
      pTVar3 = (unsigned char *)pvVar14;
    }
    goto LAB_97baadbc;
  case 0xa4:
    pTVar3 = yyvalTypeOrFunction;
LAB_97baadbc:
    yyvalTypeOrFunction = pTVar3;
    puVar25 = *(uint **)(yyvalTypeOrFunction + 8);
    if (puVar25 == *(uint **)(yyvalTypeOrFunction + 0xc)) {
      std__vector_TTypeLine_pool_allocator_TTypeLine_____M_insert_aux
                ((unsigned char *)yyvalTypeOrFunction,puVar25,yyvsp + 0x10);
      pTVar3 = yyvalNode;
      pTVar31 = local_7f0;
      pTVar32 = local_750[0];
    }
    else {
      iVar55 = 0;
      if (puVar25 != (uint *)0x0) {
        uVar57 = *(uint *)(yyvsp + 0x14);
        *puVar25 = *(uint *)(yyvsp + 0x10);
        puVar25[1] = uVar57;
        iVar55 = *(int *)(yyvalTypeOrFunction + 8);
      }
      *(int *)(yyvalTypeOrFunction + 8) = iVar55 + 8;
      pTVar3 = yyvalNode;
      pTVar31 = local_7f0;
      pTVar32 = local_750[0];
    }
    break;
  case 0xa5:
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    pTVar33 = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x28);
    pTVar3 = (unsigned char *)0xa7b8374c;
    ppuVar35 = &PTR___ZN5TTypeD1Ev_a7b7d640;
    *(undefined ***)pTVar33 = &PTR___ZN5TTypeD1Ev_a7b7d640;
    pTVar7 = (unsigned char *)((uint)*(unsigned char **)(pTVar33 + 0x24) & 0x9ff | 0x800);
    cr0 = (pTVar7 == (unsigned char *)0x0) << 1;
    *(unsigned char **)(pTVar33 + 0x20) = (unsigned char *)0x0;
    *(unsigned char **)(pTVar33 + 0x24) = pTVar7;
    *(unsigned char **)(pTVar33 + 4) = (unsigned char *)0x0;
    *(unsigned char **)(pTVar33 + 8) = (unsigned char *)0x0;
    *(unsigned char **)(pTVar33 + 0xc) = (unsigned char *)0x0;
    *(unsigned char **)(pTVar33 + 0x10) = (unsigned char *)0x0;
    *(unsigned char **)(pTVar33 + 0x14) = (unsigned char *)0x0;
    *(unsigned char **)(pTVar33 + 0x18) = (unsigned char *)0x0;
    *(unsigned char **)(pTVar33 + 0x1c) = (unsigned char *)0x0;
    yyvalQualifierOrParamType = *(unsigned char **)yyvsp;
    puVar5 = *(undefined **)(yyvsp + 4);
    pcVar40 = *(code **)(*(unsigned char **)pTVar33 + 0x14);
    yyvalTypeOrFunction = pTVar33;
    goto LAB_97baae6c;
  case 0xa6:
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    yyvalTypeOrFunction = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x28);
    pTVar33 = (unsigned char *)0xa7b8374c;
    ppuVar35 = &PTR___ZN5TTypeD1Ev_a7b7d640;
    *(undefined ***)yyvalTypeOrFunction = &PTR___ZN5TTypeD1Ev_a7b7d640;
    pTVar3 = (unsigned char *)((uint)*(unsigned char **)(yyvalTypeOrFunction + 0x24) & 0x9ff | 0x800);
    cr0 = (pTVar3 == (unsigned char *)0x0) << 1;
    *(unsigned char **)(yyvalTypeOrFunction + 0x20) = (unsigned char *)0x0;
    *(unsigned char **)(yyvalTypeOrFunction + 0x24) = pTVar3;
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
      piVar61 = (int *)(**(code **)(**(int **)(yyvsp + -0x24) + 0x18))(*(int **)(yyvsp + -0x24))
      ;
      iVar55 = (**(code **)(*piVar61 + 0x40))(piVar61);
      if ((iVar55 == 2) &&
         (iVar55 = (**(code **)(**(int **)(yyvsp + -0x24) + 0x18))(*(int **)(yyvsp + -0x24)),
         pTVar3 = yyvalTypeOrFunction, 0 < **(int **)(iVar55 + 0x30))) {
        iVar55 = (**(code **)(**(int **)(yyvsp + -0x24) + 0x18))
                           (*(int **)(yyvsp + -0x24),r4In13,scratchR5,scratchR6,scratchR7,pTVar33,
                            ppuVar35,scratchR10);
        pTVar7 = (unsigned char *)**(uint **)(iVar55 + 0x30);
        *(unsigned char **)(pTVar3 + 0x24) =
             (unsigned char *)((uint)*(unsigned char **)(pTVar3 + 0x24) | 0x200);
        *(unsigned char **)(pTVar3 + 4) = pTVar7;
        pTVar3 = yyvalNode;
        pTVar31 = local_7f0;
        pTVar32 = local_750[0];
        break;
      }
    }
    scratchR10 = *(uint *)(yyvsp + -0x80);
    picBase = (unsigned char *)0xa7b8374c;
    piVar61 = *(int **)(scratchR10 + 4);
    pcVar29 = "structure field array size must be a positive integer";
    *(unsigned char *)((int)piVar61 + piVar61[-3]) = *DAT_a7b7ba88;
    scratchR6 = *(char **)(scratchR10 + 4);
    pcVar62 = *(char **)(yyvsp + -0x58);
    goto LAB_97bab5e8;
  case 0xb1:
    symbolTable3 = *(unsigned char **)((int)parseContext + 4);
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    puVar18 = (undefined4 *)TPoolAllocator__allocate(poolAllocator,0x10);
    local_170 = (unsigned char *)GetGlobalPoolAllocator();
    *puVar18 = local_170;
    puVar18[1] = 0;
    puVar19 = (undefined4 *)TPoolAllocator__allocate(local_170,0x1c);
    puVar18[2] = 0;
    puVar18[1] = puVar19;
    *puVar19 = 0;
    *(undefined4 *)(puVar18[1] + 4) = 0;
    *(undefined4 *)(puVar18[1] + 8) = puVar18[1];
    *(undefined4 *)(puVar18[1] + 0xc) = puVar18[1];
    piVar61 = *(int **)(symbolTable3 + 4);
    destroyAlloc67[0] = puVar18;
    if (piVar61 == *(int **)(symbolTable3 + 8)) {
      std__vector_TSymbolTableLevel__std__allocator_TSymbolTableLevel______M_insert_aux
                (symbolTable3,piVar61,destroyAlloc67);
      pTVar3 = yyvalNode;
      pTVar31 = local_7f0;
      pTVar32 = local_750[0];
    }
    else {
      iVar55 = 0;
      if (piVar61 != (int *)0x0) {
        *piVar61 = (int)puVar18;
        iVar55 = *(int *)(symbolTable3 + 4);
      }
      *(int *)(symbolTable3 + 4) = iVar55 + 4;
      pTVar3 = yyvalNode;
      pTVar31 = local_7f0;
      pTVar32 = local_750[0];
    }
    break;
  case 0xb2:
    symbolTable = *(int **)((int)parseContext + 4);
    levelsEnd = symbolTable[1];
    pvVar23 = *(void **)(*symbolTable + ((levelsEnd - *symbolTable & 0xfffffffcU) - 4));
    if (pvVar23 != (void *)0x0) {
      ((int (*)())__ZN17TSymbolTableLevelD1Ev)(pvVar23);
      levelsEnd = symbolTable[1];
    }
    symbolTable[1] = levelsEnd + -4;
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0xb3:
    statementListNode = *(int **)(yyvsp + -0x50);
    pTVar3 = (unsigned char *)0x0;
    if (statementListNode != (int *)0x0) {
      (**(code **)(*statementListNode + 0x60))(statementListNode,1);
      pTVar3 = *(unsigned char **)(yyvsp + -0x50);
      pTVar31 = local_7f0;
      pTVar32 = local_750[0];
    }
    break;
  case 0xb8:
    pTVar15 = *(unsigned char **)parseContext;
    uVar57 = 0;
    pTVar20 = *(unsigned char **)(yyvsp + 8);
LAB_97bab0ec:
    pTVar3 = (unsigned char *)TIntermediate__makeAggregate(pTVar15,pTVar20,uVar57);
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0xb9:
    pTVar15 = *(unsigned char **)parseContext;
    scratchR6 = (char *)0x0;
    pTVar22 = *(unsigned char **)(yyvsp + -0x24);
    pTVar20 = *(unsigned char **)(yyvsp + 8);
    goto LAB_97ba97d8;
  case 0xbc:
    boolError = __ZN13TParseContext14boolErrorCheckEiPK12TIntermTyped
                       (parseContext,*(uint *)(yyvsp + -0xb0),*(unsigned char **)(yyvsp + -0x50),
                        scratchR6,scratchR7,pTVar33);
    if (boolError != 0) {
      TParseContext__recover(parseContext);
    }
    local_850 = *(unsigned char **)(yyvsp + 8);
    scratchR6 = *(char **)(yyvsp + 0xc);
    scratchR7 = *(char **)(yyvsp + -0xb0);
    local_84c = (unsigned char *)scratchR6;
    pTVar3 = (unsigned char *)
             __ZN13TIntermediate12addSelectionEP12TIntermTyped15TIntermNodePairi
                       (*(unsigned char **)parseContext,*(uint *)(yyvsp + -0x50),local_850,scratchR6,
                        scratchR7);
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0xbd:
  case 0xcc:
    yyvalNode2 = *(uint *)(yyvsp + 8);
    pTVar3 = *(unsigned char **)(yyvsp + -0x50);
    break;
  case 0xbe:
    pTVar3 = *(unsigned char **)(yyvsp + 8);
    goto LAB_97bab424;
  case 0xbf:
    yyvalNode = *(unsigned char **)(yyvsp + 8);
    iVar55 = (**(code **)**(undefined4 **)(yyvsp + 8))(*(undefined4 **)(yyvsp + 8));
    iVar55 = __ZN13TParseContext14boolErrorCheckEiPK12TIntermTyped
                       (parseContext,iVar55,*(unsigned char **)(yyvsp + 8),scratchR6,scratchR7,pTVar33);
    goto LAB_97bab180;
  case 0xc0:
    pTVar59 = yyvsp + -0x74;
    structQualifierError = TParseContext__structQualifierErrorCheck
                       (parseContext,*(uint *)(yyvsp + -0x58),(unsigned char *)pTVar59,scratchR6,scratchR7,
                        pTVar33,pTVar34);
    if (structQualifierError != 0) {
      TParseContext__recover(parseContext);
    }
    boolError = __ZN13TParseContext14boolErrorCheckEiRK11TPublicType
                       (parseContext,*(uint *)(yyvsp + -0x58),(unsigned char *)pTVar59);
    if (boolError != 0) {
      TParseContext__recover(parseContext);
    }
    scratchR7 = *(char **)(yyvsp + 8);
    executeInitializerResult = TParseContext__executeInitializer
                       (parseContext,*(uint *)(yyvsp + -0x58),*(unsigned char **)(yyvsp + -0x54),
                        (unsigned char *)pTVar59,(unsigned char *)scratchR7,&pTStack_70);
    scratchR6 = (char *)pTVar59;
    if (executeInitializerResult == 0) goto switchD_97ba39c8_caseD_2;
LAB_97bab1f4:
    TParseContext__recover(parseContext);
    scratchR6 = (char *)pTVar59;
    pTVar3 = (unsigned char *)0x0;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0xc1:
    symbolTable3 = *(unsigned char **)((int)parseContext + 4);
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    puVar18 = (undefined4 *)TPoolAllocator__allocate(poolAllocator,0x10);
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    local_150 = poolAllocator;
    goto LAB_97bab2e8;
  case 0xc2:
    symbolTable = *(int **)((int)parseContext + 4);
    levelsEnd = symbolTable[1];
    pvVar23 = *(void **)(*symbolTable + ((levelsEnd - *symbolTable & 0xfffffffcU) - 4));
    if (pvVar23 != (void *)0x0) {
      ((int (*)())__ZN17TSymbolTableLevelD1Ev)(pvVar23);
      levelsEnd = symbolTable[1];
    }
    symbolTable[1] = levelsEnd + -4;
    scratchR7 = (char *)0x1;
    pTVar15 = *(unsigned char **)parseContext;
    pTVar20 = *(unsigned char **)(yyvsp + 8);
    pTVar3 = *(unsigned char **)(yyvsp + -0x50);
    uVar57 = *(uint *)(yyvsp + -0xdc);
    goto LAB_97bab2b4;
  case 0xc3:
    goto switchD_97ba39c8_caseD_c3;
  case 0xc4:
    boolError = __ZN13TParseContext14boolErrorCheckEiPK12TIntermTyped
                       (parseContext,*(uint *)yyvsp,*(unsigned char **)(yyvsp + -0x50),scratchR6,scratchR7
                        ,pTVar33);
    if (boolError != 0) {
      TParseContext__recover(parseContext);
    }
    pTVar15 = *(unsigned char **)parseContext;
    pTVar20 = *(unsigned char **)(yyvsp + -0xd4);
    scratchR7 = (char *)0x0;
    pTVar3 = *(unsigned char **)(yyvsp + -0x50);
    uVar57 = *(uint *)(yyvsp + -0xb0);
LAB_97bab2b4:
    scratchR6 = (char *)0x0;
    yyvalNode = (unsigned char *)
                TIntermediate__addLoop(pTVar15,pTVar20,pTVar3,(unsigned char *)0x0,scratchR7,uVar57);
    iVar55 = *(int *)((int)parseContext + 0x20);
LAB_97bab40c:
    iVar55 = iVar55 + -1;
    goto LAB_97bab410;
  case 0xc5:
    symbolTable3 = *(unsigned char **)((int)parseContext + 4);
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    puVar18 = (undefined4 *)TPoolAllocator__allocate(poolAllocator,0x10);
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    local_140 = poolAllocator;
LAB_97bab2e8:
    *puVar18 = poolAllocator;
    puVar18[1] = 0;
    puVar19 = (undefined4 *)TPoolAllocator__allocate(poolAllocator,0x1c);
    puVar18[2] = 0;
    puVar18[1] = puVar19;
    *puVar19 = 0;
    *(undefined4 *)(puVar18[1] + 4) = 0;
    *(undefined4 *)(puVar18[1] + 8) = puVar18[1];
    *(undefined4 *)(puVar18[1] + 0xc) = puVar18[1];
    puVar19 = *(undefined4 **)(symbolTable3 + 4);
    destroyAlloc67[0] = puVar18;
    if (puVar19 == *(undefined4 **)(symbolTable3 + 8)) {
      std__vector_TSymbolTableLevel__std__allocator_TSymbolTableLevel______M_insert_aux
                (symbolTable3,puVar19,destroyAlloc67);
    }
    else {
      iVar55 = 0;
      if (puVar19 != (undefined4 *)0x0) {
        *puVar19 = puVar18;
        iVar55 = *(int *)(symbolTable3 + 4);
      }
      *(int *)(symbolTable3 + 4) = iVar55 + 4;
    }
switchD_97ba39c8_caseD_c3:
    iVar55 = *(int *)((int)parseContext + 0x20) + 1;
LAB_97bab410:
    *(int *)((int)parseContext + 0x20) = iVar55;
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0xc6:
    symbolTable = *(int **)((int)parseContext + 4);
    levelsEnd = symbolTable[1];
    pvVar23 = *(void **)(*symbolTable + ((levelsEnd - *symbolTable & 0xfffffffcU) - 4));
    if (pvVar23 != (void *)0x0) {
      ((int (*)())__ZN17TSymbolTableLevelD1Ev)(pvVar23);
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
    piVar61 = (int *)(**(code **)(*(unsigned char **)yyvalNode + 0x1c))(yyvalNode);
    (**(code **)(*piVar61 + 0x60))(piVar61,1);
    iVar55 = *(int *)((int)parseContext + 0x20);
    goto LAB_97bab40c;
  case 0xcb:
    pTVar3 = *(unsigned char **)(yyvsp + -0x24);
LAB_97bab424:
    yyvalNode2 = 0;
    break;
  case 0xcd:
    if (*(int *)((int)parseContext + 0x20) < 1) {
      scratchR6 = "";
      scratchR7 = scratchR6;
      TParseContext__error
                ((int)parseContext,*(char **)(yyvsp + -0x2c),"continue statement only allowed in loops"
                 ,"","",pTVar33,pTVar34,scratchR10);
      TParseContext__recover(parseContext);
    }
    pvVar23 = *(void **)parseContext;
    uVar16 = 0x65;
    goto LAB_97bab644;
  case 0xce:
    if (*(int *)((int)parseContext + 0x20) < 1) {
      scratchR6 = "";
      scratchR7 = scratchR6;
      TParseContext__error
                ((int)parseContext,*(char **)(yyvsp + -0x2c),"break statement only allowed in loops",""
                 ,"",pTVar33,pTVar34,scratchR10);
      TParseContext__recover(parseContext);
    }
    pvVar23 = *(void **)parseContext;
    uVar16 = 100;
    goto LAB_97bab644;
  case 0xcf:
    returnLine = *(uint *)(yyvsp + -0x2c);
    addBranchResult = __ZN13TIntermediate9addBranchE9TOperatori(*(void **)parseContext,99,returnLine);
    yyvalNode = (unsigned char *)((ulonglong)addBranchResult >> 0x20);
    piVar61 = (int *)**(undefined4 **)((int)parseContext + 0x28);
    iVar55 = (*(code *)piVar61[8])
                       (*(undefined4 **)((int)parseContext + 0x28),(int)addBranchResult,returnLine,scratchR6,scratchR7,
                        pTVar33,piVar61);
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (iVar55 == 0) break;
    pcVar62 = *(char **)(yyvsp + -0x2c);
    pcVar29 = "non-void function must return a value";
    goto LAB_97bab5e4;
  case 0xd0:
    expressionNode = *(uint *)(yyvsp + -0x24);
    scratchR6 = *(char **)(yyvsp + -0x58);
    addBranchResult = __ZN13TIntermediate9addBranchE9TOperatorP12TIntermTypedi
                       (*(void **)parseContext,99,expressionNode,scratchR6);
    yyvalNode = (unsigned char *)((ulonglong)addBranchResult >> 0x20);
    piVar61 = *(int **)((int)parseContext + 0x28);
    *(undefined4 *)((int)parseContext + 0x2c) = 1;
    iVar55 = (**(code **)(*piVar61 + 0x20))
                       (piVar61,(int)addBranchResult,expressionNode,scratchR6,scratchR7,pTVar33,piVar61);
    if (iVar55 == 0) {
      pcVar62 = *(char **)(yyvsp + -0x58);
      pcVar29 = "void function cannot return a value";
    }
    else {
      iVar55 = *(int *)((int)parseContext + 0x28);
      (**(code **)(**(int **)(yyvsp + -0x24) + 0x38))
                (&local_850,*(int **)(yyvsp + -0x24),expressionNode,scratchR6,scratchR7);
      bVar37 = false;
      if (((*(uint *)(iVar55 + 0x24) & 0x1fffe00) == ((uint)local_82c & 0x1fffe00)) &&
         (*(unsigned char **)(iVar55 + 8) == local_848)) {
        bVar37 = true;
      }
      picBase2 = (unsigned char *)0xa7b8374c;
      local_850 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
      pTVar3 = yyvalNode;
      pTVar31 = local_7f0;
      pTVar32 = local_750[0];
      if (bVar37) break;
      pcVar62 = *(char **)(yyvsp + -0x58);
      pcVar29 = "function return is not matching type:";
      piVar61 = (int *)0x0;
    }
LAB_97bab5e4:
    scratchR6 = "return";
LAB_97bab5e8:
    scratchR7 = "";
    TParseContext__error((int)parseContext,pcVar62,pcVar29,scratchR6,"",pTVar33,piVar61,scratchR10);
    goto LAB_97bab5f4;
  case 0xd1:
    if (*(int *)((int)parseContext + 0xc) != 1) {
      scratchR7 = "";
      scratchR6 = "discard";
      TParseContext__error
                ((int)parseContext,*(char **)(yyvsp + -0x2c)," supported in fragment shaders only ",
                 "discard","","",pTVar34,scratchR10);
      TParseContext__recover(parseContext);
    }
    pvVar23 = *(void **)parseContext;
    uVar16 = 0x62;
LAB_97bab644:
    pTVar3 = (unsigned char *)
             __ZN13TIntermediate9addBranchE9TOperatori(pvVar23,uVar16,*(uint *)(yyvsp + -0x2c));
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0xd2:
    pTVar3 = *(unsigned char **)(yyvsp + 8);
    goto LAB_97bab674;
  case 0xd3:
    scratchR6 = (char *)0x0;
    pTVar3 = (unsigned char *)
             TIntermediate__growAggregate
                       (*(unsigned char **)parseContext,*(unsigned char **)(yyvsp + -0x24),
                        *(unsigned char **)(yyvsp + 8),0);
LAB_97bab674:
    *(unsigned char **)((int)parseContext + 0x10) = pTVar3;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0xd6:
    piVar61 = *(int **)(yyvsp + 0x10);
    symbolTable2 = *(int **)((int)parseContext + 4);
    uVar16 = (**(code **)(*piVar61 + 8))(piVar61);
    iVar55 = *symbolTable2;
    iVar54 = (symbolTable2[1] - iVar55 >> 2) + -1;
    while( true ) {
      iVar60 = *(int *)(iVar55 + iVar54 * 4);
      iVar55 = 0;
      std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______find((unsigned char *)local_320,iVar60,uVar16);
      if (local_320[0] != *(int *)(iVar60 + 4)) {
        iVar55 = *(int *)(local_320[0] + 0x18);
      }
      iVar54 = iVar54 + -1;
      if ((iVar55 != 0) || (iVar54 < 0)) break;
      iVar55 = *symbolTable2;
    }
    if (*(int *)(iVar55 + 0x50) != 0) {
      iVar60 = piVar61[1];
      picBase = (unsigned char *)0xa7b8374c;
      stringData2 = *(int *)(iVar60 + 4);
      scratchR7 = "";
      *(unsigned char *)(stringData2 + *(int *)(stringData2 + -0xc)) = *DAT_a7b7ba88;
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp,"function already has a body",*(char **)(iVar60 + 4)
                 ,"",pTVar33,stringData2,iVar60);
      TParseContext__recover(parseContext);
    }
    *(undefined4 *)(iVar55 + 0x50) = 1;
    iVar54 = __ZNKSbIcSt11char_traitsIcE14pool_allocatorIcEE7compareEPKc((void *)piVar61[1],"main");
    local_58 = piVar61 + 3;
    if (iVar54 == 0) {
      iVar54 = piVar61[5] - piVar61[4] >> 3;
      cr0 = (iVar54 == 0) << 1;
      if (0 < iVar54) {
        iVar60 = piVar61[1];
        stringData2 = *(int *)(iVar60 + 4);
        scratchR7 = "";
        *(unsigned char *)(stringData2 + *(int *)(stringData2 + -0xc)) = *DAT_a7b7ba88;
        TParseContext__error
                  ((int)parseContext,*(char **)yyvsp,"function cannot take any parameter(s)",
                   *(char **)(iVar60 + 4),"",pTVar33,stringData2,iVar60);
        TParseContext__recover(parseContext);
      }
      iVar54 = (**(code **)(piVar61[7] + 0x20))(piVar61 + 7);
      if (iVar54 != 0) {
        iVar60 = piVar61[1];
        picBase = (unsigned char *)0xa7b8374c;
        stringData2 = *(int *)(iVar60 + 4);
        scratchR7 = "";
        *(unsigned char *)(stringData2 + *(int *)(stringData2 + -0xc)) = *DAT_a7b7ba88;
        TParseContext__error
                  ((int)parseContext,*(char **)yyvsp,"function cannot return a value",
                   *(char **)(iVar60 + 4),"",pTVar33,stringData2,iVar60);
        TParseContext__recover(parseContext);
      }
    }
    symbolTable3 = *(unsigned char **)((int)parseContext + 4);
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    puVar18 = (undefined4 *)TPoolAllocator__allocate(poolAllocator,0x10);
    local_130 = (unsigned char *)GetGlobalPoolAllocator();
    *puVar18 = local_130;
    puVar18[1] = 0;
    puVar19 = (undefined4 *)TPoolAllocator__allocate(local_130,0x1c);
    puVar18[2] = 0;
    puVar18[1] = puVar19;
    *puVar19 = 0;
    *(undefined4 *)(puVar18[1] + 4) = 0;
    *(undefined4 *)(puVar18[1] + 8) = puVar18[1];
    *(undefined4 *)(puVar18[1] + 0xc) = puVar18[1];
    puVar19 = *(undefined4 **)(symbolTable3 + 4);
    destroyAlloc67[0] = puVar18;
    if (puVar19 == *(undefined4 **)(symbolTable3 + 8)) {
      std__vector_TSymbolTableLevel__std__allocator_TSymbolTableLevel______M_insert_aux
                (symbolTable3,puVar19,destroyAlloc67);
    }
    else {
      iVar54 = 0;
      if (puVar19 != (undefined4 *)0x0) {
        *puVar19 = puVar18;
        iVar54 = *(int *)(symbolTable3 + 4);
      }
      *(int *)(symbolTable3 + 4) = iVar54 + 4;
    }
    *(int *)((int)parseContext + 0x28) = iVar55 + 0x1c;
    *(undefined4 *)((int)parseContext + 0x2c) = 0;
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    pTVar20 = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x6c);
    picBase2 = (unsigned char *)0xa7b8374c;
    local_850 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
    local_82c = (unsigned char *)((uint)local_82c & 0x1ff | 0x80800);
    local_84c = (unsigned char *)0x0;
    local_848 = (unsigned char *)0x0;
    local_844 = (unsigned char *)0x0;
    local_840 = (unsigned char *)0x0;
    local_83c = (unsigned char *)0x0;
    local_838 = (unsigned char *)0x0;
    local_834 = (unsigned char *)0x0;
    local_830 = (unsigned char *)0x0;
    *(undefined4 *)(pTVar20 + 4) = 0;
    *(undefined ***)pTVar20 = &PTR_getLine_a7b7d5d8;
    *(undefined4 *)(pTVar20 + 0xc) = 0;
    *(undefined4 *)(pTVar20 + 0x10) = 0;
    *(undefined4 *)(pTVar20 + 0x14) = 0;
    *(undefined4 *)(pTVar20 + 0x18) = 0;
    *(undefined4 *)(pTVar20 + 0x1c) = 0;
    *(undefined4 *)(pTVar20 + 0x20) = 0;
    *(undefined4 *)(pTVar20 + 0x24) = 0;
    *(undefined ***)(pTVar20 + 8) = &PTR___ZN5TTypeD1Ev_a7b7d640;
    *(undefined4 *)(pTVar20 + 0x28) = 0;
    uVar57 = *(uint *)(pTVar20 + 0x2c);
    *(uint *)(pTVar20 + 0x2c) = uVar57 & 0x1ffffff;
    *(uint *)(pTVar20 + 0x2c) = uVar57 & 0x7ffff | 0x80000;
    *(uint *)(pTVar20 + 0x2c) = uVar57 & 0x7ff | 0x80800;
    *(uint *)(pTVar20 + 0x2c) = uVar57 & 0x3ff | 0x80800;
    puVar5 = PTR_vtable_a7b7c0d0;
    *(uint *)(pTVar20 + 0x2c) = uVar57 & 0x1ff | 0x80800;
    *(undefined **)pTVar20 = puVar5 + 8;
    *(undefined4 *)(pTVar20 + 0x30) = 0;
    allocatorArg6 = GetGlobalPoolAllocator();
    *(undefined4 *)(pTVar20 + 0x40) = 0;
    *(undefined4 *)(pTVar20 + 0x38) = 0;
    *(undefined4 *)(pTVar20 + 0x3c) = 0;
    *(undefined4 *)(pTVar20 + 0x34) = allocatorArg6;
    allocatorArg7 = GetGlobalPoolAllocator();
    *(undefined4 *)(pTVar20 + 0x44) = allocatorArg7;
    iVar55 = DAT_a7b7ba84;
    *(undefined4 *)(pTVar20 + 0x50) = 0;
    *(undefined4 *)(pTVar20 + 0x48) = 0;
    piVar50 = (int *)(iVar55 + 8);
    *(undefined4 *)(pTVar20 + 0x4c) = 0;
    do {
      if (reservation != '\0') {
        iVar54 = storeWordConditionalIndexed(*piVar50 + 1,0,piVar50);
        *piVar50 = iVar54;
        cr0 = 2;
      }
    } while (!(bool)(cr0 >> 1 & 1));
    allocatorArg8 = GetGlobalPoolAllocator();
    *(int *)(pTVar20 + 0x58) = iVar55 + 0xc;
    *(undefined4 *)(pTVar20 + 0x68) = 0;
    *(undefined4 *)(pTVar20 + 0x5c) = 0;
    *(undefined4 *)(pTVar20 + 0x54) = allocatorArg8;
    local_54 = -0x5847c8b4;
    local_68 = &TType__vtable;
    for (iVar55 = 0; iVar55 < local_58[2] - local_58[1] >> 3; iVar55 = iVar55 + 1) {
      iVar60 = piVar61[4];
      iVar54 = iVar55 * 8;
      if (*(int *)(iVar60 + iVar54) == 0) {
        ctorAlloc17[0] = GetGlobalPoolAllocator();
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                  (&local_850,"",(unsigned char *)ctorAlloc17);
        scratchR7 = *(char **)yyvsp;
        addSymbolResult = (unsigned char *)
                  TIntermediate__addSymbol
                            (*(unsigned char **)parseContext,0,(unsigned char *)&local_850,
                             *(unsigned char **)(iVar60 + iVar54 + 4),(int)scratchR7);
        pTVar20 = (unsigned char *)
                  TIntermediate__growAggregate
                            (*(unsigned char **)parseContext,pTVar20,addSymbolResult,*(uint *)yyvsp);
        refCountPtr = local_84c + -4;
        destroyAlloc69[0] = local_850;
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
                    ((unsigned char *)(local_84c + -0xc),destroyAlloc69);
        }
      }
      else {
        poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
        newNode = (int *)TPoolAllocator__allocate(poolAllocator,0x40);
        puVar5 = PTR_vtable_a7b7c0b4 + 8;
        iVar36 = *(int *)(iVar60 + iVar54 + 4);
        newNode[1] = *(int *)(iVar60 + iVar54);
        *newNode = (int)puVar5;
        iVar38 = *(int *)(iVar36 + 0xc);
        r8Pass = *(int *)(iVar36 + 0x10);
        r7Pass = *(int *)(iVar36 + 0x14);
        r6Pass = *(int *)(iVar36 + 0x18);
        iVar30 = *(int *)(iVar36 + 0x1c);
        iVar26 = *(int *)(iVar36 + 0x20);
        iVar6 = *(int *)(iVar36 + 4);
        iVar39 = *(int *)(iVar36 + 8);
        newNode[3] = (int)(local_68 + 8);
        newNode[6] = iVar38;
        newNode[7] = r8Pass;
        newNode[8] = r7Pass;
        newNode[9] = r6Pass;
        newNode[10] = iVar30;
        newNode[0xb] = iVar26;
        newNode[5] = iVar39;
        newNode[4] = iVar6;
        uVar2 = newNode[0xc];
        qualifierBits = *(uint *)(iVar36 + 0x24) & 0xfe000000;
        newNode[0xc] = qualifierBits | uVar2 & 0x1ffffff;
        basicTypeBits = (*(uint *)(iVar36 + 0x24) >> 0x13 & 0x3f) << 0x13;
        newNode[0xc] = basicTypeBits | qualifierBits | uVar2 & 0x7ffff;
        uVar57 = *(uint *)(iVar36 + 0x24) & 0x7f800;
        newNode[0xc] = uVar57 | basicTypeBits | qualifierBits | uVar2 & 0x7ff;
        uVar58 = (*(uint *)(iVar36 + 0x24) >> 10 & 1) << 10;
        newNode[0xc] = uVar58 | uVar57 | basicTypeBits | qualifierBits | uVar2 & 0x3ff;
        newNode[0xc] = (*(uint *)(iVar36 + 0x24) >> 9 & 1) << 9 |
                     uVar58 | uVar57 | basicTypeBits | qualifierBits | uVar2 & 0x1ff;
        newNode[0xd] = 0;
        newNode[0xe] = 0;
        newNode[0xf] = 0;
        symbolTable2 = *(int **)((int)parseContext + 4);
        nextUniqueId2 = symbolTable2[3];
        symbolTable2[3] = nextUniqueId2 + 1;
        newNode[2] = nextUniqueId2 + 1;
        uVar16 = *(undefined4 *)(*symbolTable2 + ((symbolTable2[1] - *symbolTable2 & 0xfffffffcU) - 4));
        local_84c = (unsigned char *)0x0;
        psVar21 = (unsigned char *)(**(code **)(*newNode + 8))(newNode,iVar26,iVar30,r6Pass,r7Pass,r8Pass,symbolTable2);
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&local_f0,psVar21);
        local_e8 = newNode;
        std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&local_840,uVar16,&local_f0);
        local_850 = local_840;
        refCountPtr3 = (int *)(local_ec + -4);
        local_84c = local_83c;
        destroyAlloc68[0] = local_f0;
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
                    ((unsigned char *)(local_ec + -0xc),destroyAlloc68);
        }
        if (local_84c == (unsigned char *)0x0) {
          iVar26 = newNode[1];
          stringData3 = *(int *)(iVar26 + 4);
          *(undefined1 *)(stringData3 + *(int *)(stringData3 + -0xc)) = **(undefined1 **)(local_54 + -0x7cc4);
          TParseContext__error
                    ((int)parseContext,*(char **)yyvsp,"redefinition",*(char **)(iVar26 + 4),"",
                     local_54,stringData3,iVar26);
          TParseContext__recover(parseContext);
          (**(code **)(*newNode + 4))(newNode);
        }
        *(undefined4 *)(iVar60 + iVar54) = 0;
        scratchR7 = *(char **)yyvsp;
        addSymbolResult = (unsigned char *)
                  TIntermediate__addSymbol
                            (*(unsigned char **)parseContext,newNode[2],(unsigned char *)newNode[1],
                             (unsigned char *)(newNode + 3),(int)scratchR7);
        pTVar20 = (unsigned char *)
                  TIntermediate__growAggregate
                            (*(unsigned char **)parseContext,pTVar20,addSymbolResult,*(uint *)yyvsp);
      }
    }
    scratchR6 = *(char **)yyvsp;
    TIntermediate__setAggregateOperator(*(unsigned char **)parseContext,pTVar20,4,scratchR6);
    *(unsigned char **)(yyvsp + 8) = pTVar20;
    *(undefined4 *)((int)parseContext + 0x20) = 0;
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0xd7:
    picBase = (unsigned char *)0xa7b8374c;
    iVar55 = (**(code **)(**(int **)((int)parseContext + 0x28) + 0x20))(*(int **)((int)parseContext + 0x28));
    pTVar3 = DAT_a7b7ba88;
    if ((iVar55 != 0) && (picBase = (unsigned char *)0xa7b8374c, *(int *)((int)parseContext + 0x2c) == 0)
       ) {
      iVar55 = *(int *)(*(uint *)(yyvsp + -0x48) + 4);
      scratchR7 = "";
      *(unsigned char *)(*(int *)(iVar55 + 4) + *(int *)(*(int *)(iVar55 + 4) + -0xc)) =
           *DAT_a7b7ba88;
      TParseContext__error
                ((int)parseContext,*(char **)(yyvsp + -0x58),"function does not return a value",
                 *(char **)(iVar55 + 4),"",0xa7b8374c,pTVar3,iVar55);
      TParseContext__recover(parseContext);
    }
    symbolTable = *(int **)((int)parseContext + 4);
    levelsEnd = symbolTable[1];
    pvVar23 = *(void **)(*symbolTable + ((levelsEnd - *symbolTable & 0xfffffffcU) - 4));
    if (pvVar23 != (void *)0x0) {
      ((int (*)())__ZN17TSymbolTableLevelD1Ev)(pvVar23);
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
    iVar55 = (**(code **)(**(int **)(yyvsp + -0x48) + 8))(*(int **)(yyvsp + -0x48));
    *(undefined1 *)(*(int *)(iVar55 + 4) + *(int *)(*(int *)(iVar55 + 4) + -0xc)) =
         **(undefined1 **)(picBase + -0x7cc4);
    pcVar62 = *(char **)(iVar55 + 4);
    ctorAlloc18[0] = GetGlobalPoolAllocator();
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
              (&local_850,pcVar62,(unsigned char *)ctorAlloc18);
    piVar61 = (int *)(**(code **)(*(uint *)yyvalNode + 0x1c))(yyvalNode);
    (**(code **)(*piVar61 + 0x68))(piVar61,&local_850);
    refCountPtr = local_84c + -4;
    destroyAlloc70[0] = local_850;
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
                ((unsigned char *)(local_84c + -0xc),destroyAlloc70);
    }
    functionPrototypeTypeOrFunction = *(uint *)(yyvsp + -0x48);
    piVar61 = (int *)(**(code **)(*(uint *)yyvalNode + 0x1c))(yyvalNode);
    (**(code **)(*piVar61 + 0x34))(piVar61,functionPrototypeTypeOrFunction + 0x1c);
    iVar55 = (**(code **)(*(uint *)yyvalNode + 0x1c))(yyvalNode);
    *(undefined4 *)(iVar55 + 0x60) = *(undefined4 *)((int)parseContext + 0x40);
    iVar55 = (**(code **)(*(uint *)yyvalNode + 0x1c))(yyvalNode);
    *(undefined4 *)(iVar55 + 100) = *(undefined4 *)((int)parseContext + 0x44);
    this_00 = (unsigned char *)(**(code **)(*(uint *)yyvalNode + 0x1c))(yyvalNode);
    TIntermAggregate__addToPragmaTable(this_00,(unsigned char *)((int)parseContext + 0x48));
    pTVar3 = yyvalNode;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
  }
switchD_97ba39c8_caseD_0:
  local_750[0] = pTVar32;
  local_7f0 = pTVar31;
  yyvalNode = pTVar3;
  scratchR5 = (char *)0x2c;
  yyssp = yyssp + yystateOrYylen * -2;
  yyvsp = yyvsp + yystateOrYylen * -0x2c + 0x2c;
  _memcpy(yyvsp,&yyval,0x2c);
  scratchR10 = *(short *)(" !\"#$%&\'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^" +
                      yyruleByteOffset + 0x40) * 2;
  scratchR9 = &_yypgoto + scratchR10;
  uVar57 = (int)*(short *)(&DAT_97c36138 + scratchR10) + (int)*(short *)yyssp;
  scratchR4 = r4Out17;
  if ((uVar57 < 0x4f0) &&
     (scratchR9 = (undefined *)(uVar57 * 2),
     (int)*(short *)(&_yycheck + (int)scratchR9) == (int)*(short *)yyssp)) {
    yystateOrYylen = (int)*(short *)(&_yytable + (int)scratchR9);
  }
  else {
    yystateOrYylen = (int)*(short *)(&DAT_97c35e08 + scratchR10);
  }
  goto LAB_97ba3784;
LAB_97ba8338:
  iVar60 = *(int *)(iVar55 + iVar54 * 4);
  iVar55 = 0;
  pcVar29 = pcVar62;
  std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______find((unsigned char *)local_320,iVar60,pcVar62);
  if (local_320[0] != *(int *)(iVar60 + 4)) {
    iVar55 = *(int *)(local_320[0] + 0x18);
  }
  iVar54 = iVar54 + -1;
  uVar16 = r4Out13;
  if (iVar55 == 0) {
    if (-1 < iVar54) goto LAB_97ba8334;
  }
  else {
    uVar57 = *(uint *)(yyvsp + -0x1c);
    iVar54 = iVar55 + 0x1c;
    pTVar33 = (unsigned char *)0x0;
    if (((*(uint *)(iVar55 + 0x40) & 0x1fffe00) == (*(uint *)(uVar57 + 0x40) & 0x1fffe00)) &&
       (*(int *)(iVar55 + 0x24) == *(int *)(uVar57 + 0x24))) {
      pTVar33 = (unsigned char *)0x1;
    }
    if (pTVar33 == (unsigned char *)0x0) {
      scratchR6 = (char *)TType__getBasicString(*(uint *)(uVar57 + 0x40) >> 0x13 & 0x3f);
      pcVar29 = "overloaded functions must have the same return type";
      scratchR7 = "";
      TParseContext__error
                ((int)parseContext,*(char **)yyvsp,
                 "overloaded functions must have the same return type",scratchR6,"",pTVar33,iVar54,
                 uVar57);
      TParseContext__recover(parseContext);
      uVar16 = r4Out14;
    }
    for (loopIndex4 = 0; loopIndex4 < *(int *)(iVar55 + 0x14) - *(int *)(iVar55 + 0x10) >> 3;
        loopIndex4 = loopIndex4 + 1) {
      iVar60 = loopIndex4 * 8;
      piVar61 = *(int **)(*(int *)(iVar55 + 0x10) + iVar60 + 4);
      iVar6 = *piVar61;
      iVar6 = (**(code **)(iVar6 + 0x24))(piVar61,uVar16,pcVar29,scratchR6,scratchR7,pTVar33,iVar6);
      piVar61 = *(int **)(*(int *)(*(uint *)(yyvsp + -0x1c) + 0x10) + iVar60 + 4);
      iVar26 = *piVar61;
      iVar26 = (**(code **)(iVar26 + 0x24))(piVar61,r4In9,pcVar29,scratchR6,scratchR7,pTVar33,iVar26);
      uVar16 = r4Out15;
      if (iVar6 != iVar26) {
        iVar60 = *(int *)(*(int *)(*(uint *)(yyvsp + -0x1c) + 0x10) + iVar60 + 4);
        scratchR6 = (char *)getQualifierString(*(uint *)(iVar60 + 0x24) >> 0x19);
        pcVar29 = "overloaded functions must have the same parameter qualifiers";
        scratchR7 = "";
        TParseContext__error
                  ((int)parseContext,*(char **)yyvsp,
                   "overloaded functions must have the same parameter qualifiers",scratchR6,"",pTVar33
                   ,iVar60,uVar57);
        TParseContext__recover(parseContext);
        uVar16 = r4Out16;
      }
    }
  }
  goto LAB_97ba84b0;
LAB_97ba8334:
  iVar55 = *symbolTable;
  goto LAB_97ba8338;
LAB_97ba84b0:
  pTVar3 = *(unsigned char **)(yyvsp + -0x1c);
  symbolTable = *(int **)((int)parseContext + 4);
  yyval = *(uint *)yyvsp;
  nextUniqueId = symbolTable[3];
  symbolTable[3] = (int)(nextUniqueId + 1U);
  *(unsigned char **)(pTVar3 + 8) = (unsigned char *)(nextUniqueId + 1U);
  uVar49 = *(undefined4 *)(*symbolTable + ((symbolTable[1] - *symbolTable & 0xfffffffcU) - 4));
  local_84c = (unsigned char *)0x0;
  yyvalTypeOrFunction = pTVar3;
  psVar21 = (unsigned char *)
            (**(code **)(*(unsigned char **)pTVar3 + 8))
                      (pTVar3,uVar16,pcVar29,scratchR6,scratchR7,pTVar33,symbolTable);
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&local_310,psVar21);
  local_308 = pTVar3;
  std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&local_840,uVar49,&local_310);
  paVar11 = (unsigned char *)(local_30c + -0xc);
  local_850 = local_840;
  refCountPtr2 = (int *)(local_30c + -4);
  local_84c = local_83c;
  destroyAlloc57[0] = local_310;
  do {
    oldRefCount4 = *refCountPtr2;
    if (reservation != '\0') {
      newRefCount4 = storeWordConditionalIndexed(oldRefCount4 + -1,0,refCountPtr2);
      *refCountPtr2 = newRefCount4;
      cr0 = 2;
    }
  } while (!(bool)(cr0 >> 1 & 1));
  bVar37 = 0 < oldRefCount4;
  ppTVar24 = destroyAlloc57;
  goto LAB_97ba869c;
switchD_97ba39c8_caseD_60:
  scratchR6 = (char *)pTVar59;
  pTVar3 = (unsigned char *)0x0;
  pTVar31 = local_7f0;
  pTVar32 = local_750[0];
  goto switchD_97ba39c8_caseD_0;
LAB_97ba55dc:
  if ((uint)((int)(*(uint *)(pTVar7 + 8) - *(uint *)(pTVar7 + 4)) >> 3) <= loopIndex)
  goto LAB_97ba5740;
  piVar61 = *(int **)(*(uint *)(pTVar7 + 4) + loopIndex * 8);
  iVar55 = *piVar61;
  iVar55 = (**(code **)(iVar55 + 0x1c))(piVar61,uVar16,scratchR5,scratchR6,scratchR7,pTVar33,iVar55);
  uVar28 = *(uint *)(*(int *)(iVar55 + 4) + -0xc);
  local_90 = uVar28;
  uVar53 = *(uint *)(*(int *)(*(uint *)(yyvsp + 4) + 4) + -0xc);
  local_8c = uVar53;
  puVar25 = &local_8c;
  if (uVar28 <= uVar53) {
    puVar25 = &local_90;
  }
  scratchR5 = (char *)*puVar25;
  iVar55 = _memcmp(*(undefined4 *)(iVar55 + 4),*(undefined4 *)(*(uint *)(yyvsp + 4) + 4),scratchR5);
  cr0 = (iVar55 == 0) << 1;
  if (iVar55 == 0) {
    iVar55 = uVar28 - uVar53;
  }
  if (iVar55 != 0) {
    loopIndex = loopIndex + 1;
    uVar16 = r4Out8;
    goto LAB_97ba55dc;
  }
  (**(code **)(**(int **)(yyvsp + -0x50) + 0x38))(&local_850,*(int **)(yyvsp + -0x50));
  typeVtable3 = picBase2 + -0x610c;
  pTVar3 = picBase2;
  local_850 = typeVtable3;
  if ((uint)local_82c >> 0x19 == 2) {
    scratchR5 = *(char **)(yyvsp + -0x50);
    scratchR6 = *(char **)(yyvsp + -0x2c);
    yyvalNode = (unsigned char *)
                TParseContext__addConstStruct
                          (parseContext,*(unsigned char **)(yyvsp + 4),(unsigned char *)scratchR5,(int)scratchR6,
                           scratchR7,picBase2);
    if (yyvalNode == (unsigned char *)0x0) goto LAB_97ba5554;
    ppuVar35 = *(undefined ***)(pTVar7 + 4);
    (**(code **)(*(int *)yyvalNode + 0x34))
              (yyvalNode,ppuVar35[loopIndex * 2],scratchR5,scratchR6,scratchR7,pTVar3,ppuVar35);
    pTVar33 = (unsigned char *)(**(code **)(*(uint *)yyvalNode + 0x3c))(yyvalNode);
    puVar5 = (undefined *)0x2;
    pcVar40 = *(code **)(*(unsigned char **)pTVar33 + 0x28);
  }
  else {
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    pcVar9 = (unsigned char *)TPoolAllocator__allocate(poolAllocator,4);
    *(uint *)pcVar9 = loopIndex;
    local_81c = (unsigned char *)0x0;
    local_818 = (unsigned char *)0x0;
    local_7fc = (unsigned char *)((uint)local_7fc & 0x9ff | 0x4100800);
    local_814 = (unsigned char *)0x0;
    local_810 = (unsigned char *)0x0;
    local_80c = (unsigned char *)0x0;
    local_808 = (unsigned char *)0x0;
    local_804 = (unsigned char *)0x0;
    local_800 = (unsigned char *)0x0;
    local_820 = typeVtable3;
    scratchR6 = (char *)TIntermediate__addConstantUnion
                                (*(unsigned char **)parseContext,pcVar9,(unsigned char *)&local_820,
                                 *(uint *)yyvsp);
    scratchR5 = *(char **)(yyvsp + -0x50);
    scratchR7 = *(char **)(yyvsp + -0x2c);
    local_820 = typeVtable3;
    pTVar33 = (unsigned char *)
              TIntermediate__addIndex(*(unsigned char **)parseContext,0x2f,scratchR5,scratchR6,scratchR7);
    ppuVar35 = *(undefined ***)(pTVar7 + 4);
    puVar5 = ppuVar35[loopIndex * 2];
    pcVar40 = *(code **)(*(unsigned char **)pTVar33 + 0x34);
    yyvalNode = pTVar33;
  }
LAB_97baae6c:
  (*pcVar40)(pTVar33,puVar5,scratchR5,scratchR6,scratchR7,pTVar3,ppuVar35);
  pTVar3 = yyvalNode;
  pTVar31 = local_7f0;
  pTVar32 = local_750[0];
  goto switchD_97ba39c8_caseD_0;
LAB_97ba5740:
  scratchR10 = *(uint *)(yyvsp + 4);
  pTVar34 = *(unsigned char **)(scratchR10 + 4);
  pcVar62 = " no such field in structure";
LAB_97ba5784:
  picBase = (unsigned char *)0xa7b8374c;
  pTVar34[*(uint *)(pTVar34 + -0xc)] = *DAT_a7b7ba88;
  scratchR6 = *(char **)(scratchR10 + 4);
  pcVar29 = *(char **)(yyvsp + -0x2c);
LAB_97ba5548:
  scratchR7 = "";
  TParseContext__error((int)parseContext,pcVar29,pcVar62,scratchR6,"",pTVar33,pTVar34,scratchR10);
  goto LAB_97ba5554;
}

/* yylex @ 0x97bac120 (4128 bytes) */
int yylex(yYSTYPE, parseContext)
  unsigned char * yYSTYPE;
  void *parseContext;
{
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
  uint uVar9;
  undefined *yyDefPtr;
  byte *yyBp;
  int iVar12;
  void *pvVar13;
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
switchD_97bac34c_caseD_1:
  *_yy_c_buf_p = _yy_hold_char;
  yyBp = _yy_c_buf_p;
  iVar12 = _yy_start;
LAB_97bac214:
  yyDefPtr = &_yy_def;
  stateOffset = iVar12 << 1;
  do {
    uVar9 = (uint)(byte)(DAT_97c37983)[(uint)*_yy_c_buf_p * 4];
    if (*(short *)(&_yy_accept + stateOffset) != 0) {
      _yy_last_accepting_cpos = _yy_c_buf_p;
      _yy_last_accepting_state = iVar12;
    }
    while (nxtIndex = ((int)*(short *)(&_yy_base + stateOffset) + uVar9) * 2,
          *(short *)(&_yy_chk + nxtIndex) != iVar12) {
      iVar12 = (int)*(short *)(&_yy_def + stateOffset);
      stateOffset = iVar12 << 1;
      if (0x199 < iVar12) {
        uVar9 = (uint)(byte)(DAT_97c37d83)[uVar9 * 4];
      }
    }
    iVar12 = (int)*(short *)(&_yy_nxt + nxtIndex);
    _yy_c_buf_p = _yy_c_buf_p + 1;
    stateOffset = iVar12 * 2;
  } while (*(short *)(&_yy_base + stateOffset) != 0x260);
LAB_97bac2e4:
  uVar9 = (uint)*(short *)(&_yy_accept + stateOffset);
  yyCp = _yy_c_buf_p;
  if (uVar9 == 0) {
    uVar9 = (uint)*(short *)(&_yy_accept + _yy_last_accepting_state * 2);
    yyCp = _yy_last_accepting_cpos;
  }
  _yyleng = (int)yyCp - (int)yyBp;
  _yy_hold_char = *yyCp;
  _yytext = yyBp;
  *yyCp = 0;
  _yy_c_buf_p = yyCp;
LAB_97bac330:
  tokenLine = _yylineno;
  matchStart = _yytext;
  if (0x93 < uVar9) {
    yy_fatal_error("fatal flex scanner internal error--no action found");
    goto switchD_97bac34c_caseD_1;
  }
  switch(uVar9) {
  case 0:
    *yyCp = _yy_hold_char;
    _yytext = yyBp;
    stateOffset = _yy_last_accepting_state;
    _yy_c_buf_p = _yy_last_accepting_cpos;
LAB_97bad2c8:
    stateOffset = stateOffset << 1;
    yyBp = _yytext;
    goto LAB_97bac2e4;
  default:
    goto switchD_97bac34c_caseD_1;
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
              ((int)parseContext,_yylineno,"Invalid Octal number.",(char *)_yytext,"","",uVar9 * 4,
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
    iVar12 = PaParseComment((int *)yYSTYPE,parseContext);
    token = 0;
    if (iVar12 != 0) goto switchD_97bac34c_caseD_1;
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
    pvVar13 = (void *)0x0;
    if (stringMem != (void *)0x0) {
      stringCtorAlloc[0] = GetGlobalPoolAllocator();
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                (stringMem,(char *)yyBp,(unsigned char *)stringCtorAlloc);
      pvVar13 = stringMem;
    }
    *(void **)(yYSTYPE + 4) = pvVar13;
    token = 0x12f;
    break;
  case 0x8f:
    pvVar13 = *(void **)((int)parseContext + 8);
    __ZN13TInfoSinkBase6appendEPKc(pvVar13,"FLEX: Unknown char ");
    __ZN13TInfoSinkBase6appendEPKc(pvVar13,(char *)_yytext);
    __ZN13TInfoSinkBase6appendEPKc(pvVar13,"\n");
    token = 0;
    break;
  case 0x90:
    _fwrite(_yytext,_yyleng,1,_yyout);
    goto switchD_97bac34c_caseD_1;
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
      iVar12 = ((int (*)())yy_try_NUL_trans)(stateOffset);
      if (iVar12 == 0) goto LAB_97bad2c8;
      _yy_c_buf_p = _yy_c_buf_p + 1;
      yyBp = _yytext;
      goto LAB_97bac214;
    }
    iVar12 = ((int (*)())yy_get_next_buffer)();
    if (iVar12 == 1) goto LAB_97bad2f8;
    if (1 < iVar12) {
      if (iVar12 == 2) goto LAB_97bad344;
      goto switchD_97bac34c_caseD_1;
    }
    if (iVar12 != 0) goto switchD_97bac34c_caseD_1;
    _yy_c_buf_p = _yytext + (int)(yyCp + (-1 - (int)matchStart));
    iVar12 = ((int (*)())yy_get_previous_state)();
    yyBp = _yytext;
    goto LAB_97bac214;
  case 0x92:
  case 0x93:
    *(undefined4 *)((int)parseContext + 0x60) = 1;
    yy_delete_buffer(_yy_current_buffer);
    token = 0;
  }
  return token;
LAB_97bad2f8:
  uVar9 = _yy_start - 1;
  _yy_did_buffer_switch_on_eof = 0;
  _yy_c_buf_p = _yytext;
  uVar9 = ((int)uVar9 >> 1) + (uint)((int)uVar9 < 0 && (uVar9 & 1) != 0) + 0x92;
  goto LAB_97bac330;
LAB_97bad344:
  _yy_c_buf_p = (byte *)(*(int *)(_yy_current_buffer + 4) + _yy_n_chars);
  stateOffset = ((int (*)())yy_get_previous_state)();
  stateOffset = stateOffset << 1;
  yyBp = _yytext;
  goto LAB_97bac2e4;
}

/* yy_get_next_buffer @ 0x97bad390 (656 bytes) */
int yy_get_next_buffer()
{
  undefined1 ch;
  int b;
  int iVar3;
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
    iVar3 = 2 - (uint)((int)_yy_c_buf_p - (int)_yytext == 1);
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
      iVar3 = *(int *)(_yy_current_buffer + 0xc) - (int)numberToMove;
      b = _yy_current_buffer;
      source = _yy_c_buf_p;
      while (iVar3 = iVar3 + -1, _yy_current_buffer = b, _yy_c_buf_p = source, iVar3 < 1) {
        oldChBuf = *(void **)(b + 4);
        if (*(int *)(b + 0x14) == 0) {
          *(undefined4 *)(b + 4) = 0;
        }
        else {
          oldSize = *(uint *)(b + 0xc);
          iVar3 = oldSize << 1;
          if (iVar3 < 1) {
            iVar3 = oldSize + (oldSize >> 3);
          }
          *(int *)(b + 0xc) = iVar3;
          yy_flex_reallocResult = yy_flex_realloc(oldChBuf,*(int *)(b + 0xc) + 2);
          *(undefined4 *)(b + 4) = yy_flex_reallocResult;
        }
        iVar3 = *(int *)(b + 4);
        if (iVar3 == 0) {
          yy_fatal_error("fatal error - scanner input buffer overflow");
          iVar3 = *(int *)(b + 4);
        }
        source = source + (iVar3 - (int)oldChBuf);
        b = _yy_current_buffer;
        iVar3 = *(int *)(_yy_current_buffer + 0xc) - (int)numberToMove;
      }
      if (0x2000 < iVar3) {
        iVar3 = 0x2000;
      }
      _yy_n_chars = (undefined1 *)_yylex_CPP(numberToMove + *(int *)(b + 4),iVar3);
      if (_yy_n_chars != (undefined1 *)0x0) {
        if (iVar3 <= (int)_yy_n_chars) {
          yy_fatal_error("input buffer overflow, can\'t enlarge buffer because scanner uses REJECT")
          ;
        }
        numberToMove[(int)_yy_n_chars + *(int *)(_yy_current_buffer + 4)] = 0x20;
        _yy_n_chars = (undefined1 *)((int)_yy_n_chars + 1);
      }
    }
    *(undefined1 **)(_yy_current_buffer + 0x10) = _yy_n_chars;
    iVar3 = 0;
    if (_yy_n_chars == (undefined1 *)0x0) {
      if (numberToMove == (undefined1 *)0x0) {
        iVar3 = 1;
        ((int (*)())yyrestart)(_yyin);
      }
      else {
        iVar3 = 2;
        *(undefined4 *)(_yy_current_buffer + 0x24) = 2;
      }
    }
    _yy_n_chars = numberToMove + (int)_yy_n_chars;
    _yy_n_chars[*(int *)(_yy_current_buffer + 4)] = 0;
    _yy_n_chars[*(int *)(_yy_current_buffer + 4) + 1] = 0;
    _yytext = *(undefined1 **)(_yy_current_buffer + 4);
  }
  return iVar3;
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
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  int yy_get_next_bufferResult;
  
  *_yy_c_buf_p = _yy_hold_char;
  pbVar1 = _yy_c_buf_p;
  iVar3 = _yytext;
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
          _yy_c_buf_p = pbVar1 + (_yytext - iVar3);
        }
      }
      else if (yy_get_next_bufferResult == 2) {
        ((int (*)())yyrestart)(_yyin);
        return 0xffffffff;
      }
    }
  }
  bVar2 = *_yy_c_buf_p;
  *_yy_c_buf_p = 0;
  pbVar1 = _yy_c_buf_p + 1;
  _yy_c_buf_p = _yy_c_buf_p + 1;
  _yy_hold_char = *pbVar1;
  return (uint)bVar2;
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

