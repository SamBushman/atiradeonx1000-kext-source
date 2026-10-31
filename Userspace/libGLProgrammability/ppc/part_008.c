#include "decls.h"

/* Binding__GetLocation @ 0x97bb0460 (8 bytes) */
int Binding__GetLocation(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 0x14);
}

/* Binding__SetLocation @ 0x97bb0468 (8 bytes) */
int Binding__SetLocation(this, location)
  unsigned char * this;
  int location;
{
  *(int *)(this + 0x14) = location;
  return;
}

/* Binding__GetActiveIndex @ 0x97bb0470 (8 bytes) */
int Binding__GetActiveIndex(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 0x20);
}

/* Binding__SetActiveIndex @ 0x97bb0478 (8 bytes) */
int Binding__SetActiveIndex(this, activeIndex)
  unsigned char * this;
  int activeIndex;
{
  *(int *)(this + 0x20) = activeIndex;
  return;
}

/* Binding__SetOpenGLType @ 0x97bb0480 (8 bytes) */
int Binding__SetOpenGLType(this, glType)
  unsigned char * this;
  int glType;
{
  *(ushort *)(this + 0x24) = glType;
  return;
}

/* Binding__GetOpenGLType @ 0x97bb0488 (8 bytes) */
int Binding__GetOpenGLType(this)
  unsigned char * this;
{
  return *(undefined2 *)(this + 0x24);
}

/* Binding__GetBindingBasicSize @ 0x97bb0490 (8 bytes) */
int Binding__GetBindingBasicSize(this)
  unsigned char * this;
{
  undefined4 vec4sForType;
  
  vec4sForType = GetVec4sForType((uint)*(ushort *)(this + 0x24));
  return vec4sForType;
}

/* Binding__GetBindingSlots @ 0x97bb0498 (8 bytes) */
int Binding__GetBindingSlots(this)
  unsigned char * this;
{
  undefined4 vec4sForType;
  
  vec4sForType = GetVec4sForType((uint)*(ushort *)(this + 0x24));
  return vec4sForType;
}

/* Binding__SetDecSize @ 0x97bb04a0 (8 bytes) */
int Binding__SetDecSize(this, decSize)
  unsigned char * this;
  ulong decSize;
{
  *(ulong *)(this + 0x18) = decSize;
  return;
}

/* Binding__SetActualSize @ 0x97bb04a8 (8 bytes) */
int Binding__SetActualSize(this, actualSize)
  unsigned char * this;
  ulong actualSize;
{
  *(ulong *)(this + 0x1c) = actualSize;
  return;
}

/* Binding__GetDecSize @ 0x97bb04b0 (8 bytes) */
int Binding__GetDecSize(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 0x18);
}

/* Binding__GetActualSize @ 0x97bb04b8 (8 bytes) */
int Binding__GetActualSize(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 0x1c);
}

/* Binding__GetNextBinding @ 0x97bb04c0 (8 bytes) */
int Binding__GetNextBinding(this)
  unsigned char * this;
{
  return *(undefined4 *)this;
}

/* Binding__GetNextBindingInHash @ 0x97bb04c8 (8 bytes) */
int Binding__GetNextBindingInHash(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 4);
}

/* Binding__SetNextBinding @ 0x97bb04d0 (8 bytes) */
int Binding__SetNextBinding(this, binding)
  unsigned char * this;
  unsigned char * binding;
{
  *(unsigned char **)this = binding;
  return;
}

/* Binding__SetNextBindingInHash @ 0x97bb04d8 (8 bytes) */
int Binding__SetNextBindingInHash(this, binding)
  unsigned char * this;
  unsigned char * binding;
{
  *(unsigned char **)(this + 4) = binding;
  return;
}

/* Binding__GetString @ 0x97bb04e0 (256 bytes) */
int Binding__GetString(this)
  unsigned char * this;
{
  undefined4 activeIndex;
  undefined4 gLStringForType2;
  undefined4 gLStringForType;
  int isClientRequest;
  int nameLength;
  int length;
  undefined4 glType;
  int length2;
  char *allocation;
  undefined4 location;
  undefined4 glType2;
  char *result;
  undefined4 vertexFlagChar;
  undefined4 fragmentFlagChar;
  undefined4 name;
  undefined8 formatStrings [2];
  
  formatStrings[0] = 0x97c2b3bc97c2b3dc;
  isClientRequest = Binding__IsClientRequest(this);
  length = _strlen(*(undefined4 *)((int)formatStrings + isClientRequest * 4));
  nameLength = *(int *)(this + 0x10);
  glType = ((int (*)())Binding__GetOpenGLType)(this);
  gLStringForType = GetGLStringForType(glType);
  length2 = _strlen(gLStringForType);
  allocation = (char *)_malloc(length + nameLength + length2 + 0x15);
  result = (char *)0x0;
  if (allocation != (char *)0x0) {
    isClientRequest = Binding__IsClientRequest(this);
    activeIndex = ((int (*)())Binding__GetActiveIndex)(this);
    location = ((int (*)())Binding__GetLocation)(this);
    glType2 = ((int (*)())Binding__GetOpenGLType)(this);
    name = *(undefined4 *)(this + 8);
    gLStringForType2 = GetGLStringForType(glType2);
    vertexFlagChar = 0x56;
    if (this[0x34] == 0x0) {
      vertexFlagChar = 0x20;
    }
    fragmentFlagChar = 0x46;
    if (this[0x35] == 0x0) {
      fragmentFlagChar = 0x20;
    }
    _sprintf(allocation,*(char **)((int)formatStrings + isClientRequest * 4),activeIndex,location,name,gLStringForType2,vertexFlagChar,fragmentFlagChar);
    result = allocation;
  }
  return result;
}

/* __ZN12BindingTableC2Ej @ 0x97bb05e0 (4 bytes) */
int __ZN12BindingTableC2Ej(this, numBuckets)
  void *this;
  uint numBuckets;
{
  uint loopIndex2;
  int byteOffset;
  uint bucketCount;
  void *allocation;
  uint loopIndex;
  
  *(uint *)this = numBuckets;
  allocation = operator_new__(numBuckets << 2);
  loopIndex = 0;
  *(void **)((int)this + 8) = allocation;
  *(undefined4 *)((int)this + 4) = 0;
  bucketCount = 0;
  if (*(int *)this != 0) {
    do {
      byteOffset = loopIndex * 4;
      loopIndex = loopIndex + 1;
      *(undefined4 *)(byteOffset + *(int *)((int)this + 8)) = 0;
      bucketCount = *(uint *)this;
    } while (loopIndex < bucketCount);
  }
  allocation = operator_new__(bucketCount << 2);
  loopIndex = 0;
  *(void **)((int)this + 0x10) = allocation;
  *(undefined4 *)((int)this + 0xc) = 0;
  bucketCount = 0;
  if (*(int *)this != 0) {
    do {
      byteOffset = loopIndex * 4;
      loopIndex = loopIndex + 1;
      *(undefined4 *)(byteOffset + *(int *)((int)this + 0x10)) = 0;
      bucketCount = *(uint *)this;
    } while (loopIndex < bucketCount);
  }
  allocation = operator_new__(bucketCount << 2);
  loopIndex2 = 0;
  *(void **)((int)this + 0x18) = allocation;
  *(undefined4 *)((int)this + 0x14) = 0;
  if (*(int *)this != 0) {
    do {
      byteOffset = loopIndex2 * 4;
      loopIndex2 = loopIndex2 + 1;
      *(undefined4 *)(byteOffset + *(int *)((int)this + 0x18)) = 0;
    } while (loopIndex2 < *(uint *)this);
  }
  *(undefined4 *)((int)this + 0x40) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  *(undefined4 *)((int)this + 0x28) = 0;
  *(undefined4 *)((int)this + 0x34) = 0;
  *(undefined4 *)((int)this + 0x2c) = 0;
  *(undefined4 *)((int)this + 0x30) = 0;
  *(undefined4 *)((int)this + 0x38) = 0;
  *(undefined4 *)((int)this + 0x3c) = 0;
  *(undefined4 *)((int)this + 0x44) = 0;
  return;
}

/* __ZN12BindingTableC1Ej @ 0x97bb05e4 (4 bytes) */
int __ZN12BindingTableC1Ej(this, numBuckets)
  void *this;
  uint numBuckets;
{
  return ((int (*)())__ZN12BindingTableC4Ej)(this,numBuckets);
}

/* __ZN12BindingTableC4Ej @ 0x97bb05e8 (288 bytes) */
int __ZN12BindingTableC4Ej(this, numBuckets)
  void *this;
  uint numBuckets;
{
  uint loopIndex2;
  int byteOffset;
  uint bucketCount;
  void *allocation;
  uint loopIndex;
  
  *(uint *)this = numBuckets;
  allocation = operator_new__(numBuckets << 2);
  loopIndex = 0;
  *(void **)((int)this + 8) = allocation;
  *(undefined4 *)((int)this + 4) = 0;
  bucketCount = 0;
  if (*(int *)this != 0) {
    do {
      byteOffset = loopIndex * 4;
      loopIndex = loopIndex + 1;
      *(undefined4 *)(byteOffset + *(int *)((int)this + 8)) = 0;
      bucketCount = *(uint *)this;
    } while (loopIndex < bucketCount);
  }
  allocation = operator_new__(bucketCount << 2);
  loopIndex = 0;
  *(void **)((int)this + 0x10) = allocation;
  *(undefined4 *)((int)this + 0xc) = 0;
  bucketCount = 0;
  if (*(int *)this != 0) {
    do {
      byteOffset = loopIndex * 4;
      loopIndex = loopIndex + 1;
      *(undefined4 *)(byteOffset + *(int *)((int)this + 0x10)) = 0;
      bucketCount = *(uint *)this;
    } while (loopIndex < bucketCount);
  }
  allocation = operator_new__(bucketCount << 2);
  loopIndex2 = 0;
  *(void **)((int)this + 0x18) = allocation;
  *(undefined4 *)((int)this + 0x14) = 0;
  if (*(int *)this != 0) {
    do {
      byteOffset = loopIndex2 * 4;
      loopIndex2 = loopIndex2 + 1;
      *(undefined4 *)(byteOffset + *(int *)((int)this + 0x18)) = 0;
    } while (loopIndex2 < *(uint *)this);
  }
  *(undefined4 *)((int)this + 0x40) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  *(undefined4 *)((int)this + 0x28) = 0;
  *(undefined4 *)((int)this + 0x34) = 0;
  *(undefined4 *)((int)this + 0x2c) = 0;
  *(undefined4 *)((int)this + 0x30) = 0;
  *(undefined4 *)((int)this + 0x38) = 0;
  *(undefined4 *)((int)this + 0x3c) = 0;
  *(undefined4 *)((int)this + 0x44) = 0;
  return;
}

/* __ZN12BindingTableD2Ev @ 0x97bb0708 (8 bytes) */
int __ZN12BindingTableD2Ev(this)
  void *this;
{
  return ((int (*)())__ZN12BindingTableD4Ev)(this);
}

/* __ZN12BindingTableD1Ev @ 0x97bb0710 (8 bytes) */
int __ZN12BindingTableD1Ev(this)
  void *this;
{
  return ((int (*)())__ZN12BindingTableD4Ev)(this);
}

/* __ZN12BindingTableD4Ev @ 0x97bb0718 (148 bytes) */
int __ZN12BindingTableD4Ev(this)
  void *this;
{
  bool nodeIsNull;
  unsigned char * nextBinding;
  unsigned char * binding;
  
  binding = *(unsigned char **)((int)this + 4);
  nodeIsNull = binding == (unsigned char *)0x0;
  if (!nodeIsNull) {
    while( true ) {
      nextBinding = (unsigned char *)((int (*)())Binding__GetNextBinding)(binding);
      if (!nodeIsNull) {
        __ZN7BindingD1Ev(binding);
        __ZdlPv(binding);
      }
      if (nextBinding == (unsigned char *)0x0) break;
      nodeIsNull = false;
      binding = nextBinding;
    }
  }
  ((int (*)())BindingTable__ClearInternalBindings)(this);
  __ZdlPv(*(void **)((int)this + 8));
  __ZdlPv(*(void **)((int)this + 0x10));
  return __ZdlPv(*(void **)((int)this + 0x18));
}

/* BindingTable__ClearInternalBindings @ 0x97bb07ac (336 bytes) */
int BindingTable__ClearInternalBindings(this)
  unsigned char * this;
{
  bool nodeIsNull;
  int byteOffset;
  uint bucketCount;
  unsigned char * nextBinding;
  uint bucketIdx;
  unsigned char * binding;
  
  binding = *(unsigned char **)(this + 0xc);
  *(undefined4 *)(this + 0x40) = 0;
  nodeIsNull = binding == (unsigned char *)0x0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x3c) = 0;
  *(undefined4 *)(this + 0x44) = 0;
  if (!nodeIsNull) {
    while( true ) {
      nextBinding = (unsigned char *)((int (*)())Binding__GetNextBinding)(binding);
      if (!nodeIsNull) {
        __ZN7BindingD1Ev(binding);
        __ZdlPv(binding);
      }
      if (nextBinding == (unsigned char *)0x0) break;
      nodeIsNull = false;
      binding = nextBinding;
    }
  }
  binding = *(unsigned char **)(this + 0x14);
  *(undefined4 *)(this + 0xc) = 0;
  nodeIsNull = binding == (unsigned char *)0x0;
  if (!nodeIsNull) {
    while( true ) {
      nextBinding = (unsigned char *)((int (*)())Binding__GetNextBinding)(binding);
      if (!nodeIsNull) {
        __ZN7BindingD1Ev(binding);
        __ZdlPv(binding);
      }
      if (nextBinding == (unsigned char *)0x0) break;
      nodeIsNull = false;
      binding = nextBinding;
    }
  }
  bucketIdx = 0;
  *(undefined4 *)(this + 0x14) = 0;
  bucketCount = 0;
  if (*(int *)this != 0) {
    do {
      byteOffset = bucketIdx * 4;
      bucketIdx = bucketIdx + 1;
      *(undefined4 *)(byteOffset + *(int *)(this + 0x10)) = 0;
      bucketCount = *(uint *)this;
    } while (bucketIdx < bucketCount);
  }
  bucketIdx = 0;
  if (bucketCount != 0) {
    do {
      byteOffset = bucketIdx * 4;
      bucketIdx = bucketIdx + 1;
      *(undefined4 *)(byteOffset + *(int *)(this + 0x18)) = 0;
    } while (bucketIdx < *(uint *)this);
  }
  return;
}

/* BindingTable__InsertAttribRequestBinding @ 0x97bb08fc (244 bytes) */
int BindingTable__InsertAttribRequestBinding(this, binding)
  unsigned char * this;
  unsigned char * binding;
{
  unsigned char *nextNode;
  int location;
  unsigned char *existing;
  int hashIdx;
  unsigned char * curNode;
  
  if (binding != (unsigned char *)0x0) {
    existing = (unsigned char *)((int (*)())BindingTable__FindAttribRequestBinding)(this,binding);
    if (existing == (unsigned char *)0x0) {
      nextNode = *(unsigned char **)(this + 4);
      if (*(unsigned char **)(this + 4) == (unsigned char *)0x0) {
        *(unsigned char **)(this + 4) = binding;
        hashIdx = Binding__GetHash(binding,*(uint *)this);
        *(unsigned char **)(hashIdx * 4 + *(int *)(this + 8)) = binding;
      }
      else {
        do {
          curNode = nextNode;
          nextNode = (unsigned char *)((int (*)())Binding__GetNextBinding)(curNode);
        } while (nextNode != (unsigned char *)0x0);
        ((int (*)())Binding__SetNextBinding)(curNode,binding);
        hashIdx = Binding__GetHash(binding,*(uint *)this);
        nextNode = *(unsigned char **)(hashIdx * 4 + *(int *)(this + 8));
        if (nextNode == (unsigned char *)0x0) {
          *(unsigned char **)(hashIdx * 4 + *(int *)(this + 8)) = binding;
        }
        else {
          do {
            curNode = nextNode;
            nextNode = (unsigned char *)((int (*)())Binding__GetNextBindingInHash)(curNode);
          } while (nextNode != (unsigned char *)0x0);
          ((int (*)())Binding__SetNextBindingInHash)(curNode,binding);
        }
      }
      return 1;
    }
    location = ((int (*)())Binding__GetLocation)(binding);
    ((int (*)())Binding__SetLocation)(existing,location);
  }
  return 0;
}

/* BindingTable__NextAttribRequestBinding @ 0x97bb09f0 (24 bytes) */
int BindingTable__NextAttribRequestBinding(this, binding)
  unsigned char * this;
  unsigned char * binding;
{
  undefined4 nextBinding;
  
  if (binding != (unsigned char *)0x0) {
    nextBinding = ((int (*)())Binding__GetNextBinding)(binding);
    return nextBinding;
  }
  return *(undefined4 *)(this + 4);
}

/* BindingTable__FindAttribRequestBinding @ 0x97bb0a08 (116 bytes) */
int BindingTable__FindAttribRequestBinding(this, binding)
  unsigned char * this;
  unsigned char * binding;
{
  int isEqual;
  int hashIdx;
  unsigned char *entry;
  
  hashIdx = Binding__GetHash(binding,*(uint *)this);
  entry = *(unsigned char **)(hashIdx * 4 + *(int *)(this + 8));
  while ((entry != (unsigned char *)0x0 && (isEqual = __ZeqRK7BindingS1_(entry,binding), isEqual != 1))) {
    entry = (unsigned char *)((int (*)())Binding__GetNextBindingInHash)(entry);
  }
  return entry;
}

/* BindingTable__FindAttribRequestBindingLocationByName @ 0x97bb0a7c (228 bytes) */
int BindingTable__FindAttribRequestBindingLocationByName(this, str)
  unsigned char * this;
  char *str;
{
  int isEqual;
  unsigned char * probe;
  int hashIdx;
  undefined4 location;
  unsigned char * found;
  
  if (str != (char *)0x0) {
    probe = operator_new(0x38);
    __ZN7BindingC1Ev(probe);
    if (probe != (unsigned char *)0x0) {
      Binding__SetName(probe,str);
      hashIdx = Binding__GetHash(probe,*(uint *)this);
      found = *(unsigned char **)(hashIdx * 4 + *(int *)(this + 8));
      while ((found != (unsigned char *)0x0 && (isEqual = __ZeqRK7BindingS1_(found,probe), isEqual != 1)
             )) {
        found = (unsigned char *)((int (*)())Binding__GetNextBindingInHash)(found);
      }
      __ZN7BindingD1Ev(probe);
      __ZdlPv(probe);
      if (found != (unsigned char *)0x0) {
        location = ((int (*)())Binding__GetLocation)(found);
        return location;
      }
    }
  }
  return 0xffffffff;
}

/* BindingTable__InsertClientAttribBinding @ 0x97bb0b60 (368 bytes) */
int BindingTable__InsertClientAttribBinding(this, binding)
  unsigned char * this;
  unsigned char * binding;
{
  unsigned char *nextNode;
  int bindingSlots;
  int isBuiltIn;
  int activeIndex;
  int hashIdx;
  unsigned char * newBinding;
  int newLocation;
  int curLocation;
  unsigned char * prev;
  unsigned char *nextBinding;
  unsigned char * cur;
  
  if (binding == (unsigned char *)0x0) {
    return 0;
  }
  newBinding = operator_new(0x38);
  __ZN7BindingC1ERKS_(newBinding,binding);
  nextBinding = *(unsigned char **)(this + 0xc);
  if (nextBinding != (unsigned char *)0x0) {
    newLocation = ((int (*)())Binding__GetLocation)(newBinding);
    prev = (unsigned char *)0x0;
    cur = nextBinding;
    do {
      curLocation = ((int (*)())Binding__GetLocation)(cur);
      nextBinding = cur;
      if (newLocation < curLocation) break;
      nextBinding = (unsigned char *)((int (*)())Binding__GetNextBinding)(cur);
      prev = cur;
      cur = nextBinding;
    } while (nextBinding != (unsigned char *)0x0);
    if (prev != (unsigned char *)0x0) {
      ((int (*)())Binding__SetNextBinding)(prev,newBinding);
      goto callBinding_SetNextBinding;
    }
  }
  *(unsigned char **)(this + 0xc) = newBinding;
callBinding_SetNextBinding:
  ((int (*)())Binding__SetNextBinding)(newBinding,nextBinding);
  hashIdx = Binding__GetHash(newBinding,*(uint *)this);
  nextNode = *(unsigned char **)(hashIdx * 4 + *(int *)(this + 0x10));
  if (nextNode == (unsigned char *)0x0) {
    *(unsigned char **)(hashIdx * 4 + *(int *)(this + 0x10)) = newBinding;
  }
  else {
    do {
      prev = nextNode;
      nextNode = (unsigned char *)((int (*)())Binding__GetNextBindingInHash)(prev);
    } while (nextNode != (unsigned char *)0x0);
    ((int (*)())Binding__SetNextBindingInHash)(prev,newBinding);
  }
  ((int (*)())Binding__SetNextBindingInHash)(newBinding,(unsigned char *)0x0);
  activeIndex = *(int *)(this + 0x1c);
  *(int *)(this + 0x1c) = activeIndex + 1;
  ((int (*)())Binding__SetActiveIndex)(newBinding,activeIndex);
  isBuiltIn = Binding__IsBuiltIn(newBinding);
  if (isBuiltIn == 0) {
    bindingSlots = ((int (*)())Binding__GetBindingSlots)(newBinding);
    *(int *)(this + 0x28) = *(int *)(this + 0x28) + bindingSlots;
  }
  bindingSlots = ((int (*)())Binding__GetBindingSlots)(newBinding);
  *(int *)(this + 0x34) = *(int *)(this + 0x34) + bindingSlots;
  if (*(int *)(this + 0x38) < *(int *)(newBinding + 0x10) + 1) {
    *(int *)(this + 0x38) = *(int *)(newBinding + 0x10) + 1;
  }
  return 1;
}

/* BindingTable__InsertAttribBinding @ 0x97bb0cd0 (508 bytes) */
int BindingTable__InsertAttribBinding(this, binding)
  unsigned char * this;
  unsigned char * binding;
{
  int bindingSlots;
  int isBuiltIn;
  int activeIndex;
  int hashIdx;
  int curLocation;
  int headLocation;
  unsigned char *nextNode;
  unsigned char *curNode;
  int builtInTestResult;
  int slotCount;
  undefined4 result;
  int prevLocation;
  int newLocation;
  unsigned char *prevBinding;
  unsigned char *nextBinding;
  unsigned char * curBinding;
  
  result = 0;
  if (binding != (unsigned char *)0x0) {
    prevLocation = 0;
    builtInTestResult = Binding__IsBuiltIn(binding);
    nextBinding = *(unsigned char **)(this + 0xc);
    newLocation = 1;
    if ((builtInTestResult != 0) && (builtInTestResult = _memcmp(*(undefined4 *)(binding + 8),"gl_Vertex",10), builtInTestResult == 0))
    {
      if ((nextBinding != (unsigned char *)0x0) && (headLocation = ((int (*)())Binding__GetLocation)(nextBinding), headLocation == 0)) {
        return 0;
      }
      newLocation = 0;
    }
    prevBinding = (unsigned char *)0x0;
    if (nextBinding != (unsigned char *)0x0) {
      do {
        curBinding = nextBinding;
        newLocation = prevLocation + newLocation;
        curLocation = ((int (*)())Binding__GetLocation)(curBinding);
        slotCount = ((int (*)())Binding__GetBindingSlots)(binding);
        nextBinding = curBinding;
        if (newLocation + slotCount <= curLocation) goto checkPrevBinding;
        prevLocation = ((int (*)())Binding__GetLocation)(curBinding);
        newLocation = ((int (*)())Binding__GetBindingSlots)(curBinding);
        nextBinding = (unsigned char *)((int (*)())Binding__GetNextBinding)(curBinding);
        prevBinding = curBinding;
      } while (nextBinding != (unsigned char *)0x0);
      newLocation = prevLocation + newLocation;
    }
checkPrevBinding:
    if (prevBinding == (unsigned char *)0x0) {
      *(unsigned char **)(this + 0xc) = binding;
    }
    else {
      ((int (*)())Binding__SetNextBinding)(prevBinding,binding);
    }
    ((int (*)())Binding__SetNextBinding)(binding,nextBinding);
    ((int (*)())Binding__SetLocation)(binding,newLocation);
    hashIdx = Binding__GetHash(binding,*(uint *)this);
    nextNode = *(unsigned char **)(hashIdx * 4 + *(int *)(this + 0x10));
    if (nextNode == (unsigned char *)0x0) {
      *(unsigned char **)(hashIdx * 4 + *(int *)(this + 0x10)) = binding;
    }
    else {
      do {
        curNode = nextNode;
        nextNode = (unsigned char *)((int (*)())Binding__GetNextBindingInHash)(curNode);
      } while (nextNode != (unsigned char *)0x0);
      ((int (*)())Binding__SetNextBindingInHash)(curNode,binding);
    }
    ((int (*)())Binding__SetNextBindingInHash)(binding,(unsigned char *)0x0);
    activeIndex = *(int *)(this + 0x1c);
    *(int *)(this + 0x1c) = activeIndex + 1;
    ((int (*)())Binding__SetActiveIndex)(binding,activeIndex);
    isBuiltIn = Binding__IsBuiltIn(binding);
    if (isBuiltIn == 0) {
      bindingSlots = ((int (*)())Binding__GetBindingSlots)(binding);
      *(int *)(this + 0x28) = *(int *)(this + 0x28) + bindingSlots;
    }
    bindingSlots = ((int (*)())Binding__GetBindingSlots)(binding);
    *(int *)(this + 0x34) = *(int *)(this + 0x34) + bindingSlots;
    if (*(int *)(this + 0x38) < *(int *)(binding + 0x10) + 1) {
      *(int *)(this + 0x38) = *(int *)(binding + 0x10) + 1;
    }
    result = 1;
    binding[0x34] = 0x1;
  }
  return result;
}

/* BindingTable__NextAttribBinding @ 0x97bb0ecc (24 bytes) */
int BindingTable__NextAttribBinding(this, binding)
  unsigned char * this;
  unsigned char * binding;
{
  undefined4 nextBinding;
  
  if (binding != (unsigned char *)0x0) {
    nextBinding = ((int (*)())Binding__GetNextBinding)(binding);
    return nextBinding;
  }
  return *(undefined4 *)(this + 0xc);
}

/* BindingTable__FindAttribBinding @ 0x97bb0ee4 (116 bytes) */
int BindingTable__FindAttribBinding(this, binding)
  unsigned char * this;
  unsigned char * binding;
{
  int isEqual;
  int hashIdx;
  unsigned char *entry;
  
  hashIdx = Binding__GetHash(binding,*(uint *)this);
  entry = *(unsigned char **)(hashIdx * 4 + *(int *)(this + 0x10));
  while ((entry != (unsigned char *)0x0 && (isEqual = __ZeqRK7BindingS1_(entry,binding), isEqual != 1))) {
    entry = (unsigned char *)((int (*)())Binding__GetNextBindingInHash)(entry);
  }
  return entry;
}

/* BindingTable__FindAttribBindingLocationByName @ 0x97bb0f58 (228 bytes) */
int BindingTable__FindAttribBindingLocationByName(this, str)
  unsigned char * this;
  char *str;
{
  int isEqual;
  unsigned char * probe;
  int hashIdx;
  undefined4 location;
  unsigned char * found;
  
  if (str != (char *)0x0) {
    probe = operator_new(0x38);
    __ZN7BindingC1Ev(probe);
    if (probe != (unsigned char *)0x0) {
      Binding__SetName(probe,str);
      hashIdx = Binding__GetHash(probe,*(uint *)this);
      found = *(unsigned char **)(hashIdx * 4 + *(int *)(this + 0x10));
      while ((found != (unsigned char *)0x0 && (isEqual = __ZeqRK7BindingS1_(found,probe), isEqual != 1)
             )) {
        found = (unsigned char *)((int (*)())Binding__GetNextBindingInHash)(found);
      }
      __ZN7BindingD1Ev(probe);
      __ZdlPv(probe);
      if (found != (unsigned char *)0x0) {
        location = ((int (*)())Binding__GetLocation)(found);
        return location;
      }
    }
  }
  return 0xffffffff;
}

/* BindingTable__GetAttribBindingNameByLocation @ 0x97bb103c (92 bytes) */
int BindingTable__GetAttribBindingNameByLocation(this, wantedLocation)
  unsigned char * this;
  long wantedLocation;
{
  int location;
  unsigned char * binding;
  
  binding = *(unsigned char **)(this + 0xc);
  while( true ) {
    if (binding == (unsigned char *)0x0) {
      return 0;
    }
    location = ((int (*)())Binding__GetLocation)(binding);
    if (location == wantedLocation) break;
    binding = (unsigned char *)((int (*)())Binding__GetNextBinding)(binding);
  }
  return *(undefined4 *)(binding + 8);
}

/* BindingTable__GetAttribBindingByIndex @ 0x97bb1098 (88 bytes) */
int BindingTable__GetAttribBindingByIndex(this, wantedIndex)
  unsigned char * this;
  long wantedIndex;
{
  int activeIndex;
  unsigned char * binding;
  
  binding = *(unsigned char **)(this + 0xc);
  while ((binding != (unsigned char *)0x0 && (activeIndex = ((int (*)())Binding__GetActiveIndex)(binding), activeIndex != wantedIndex))
        ) {
    binding = (unsigned char *)((int (*)())Binding__GetNextBinding)(binding);
  }
  return binding;
}

/* BindingTable__InsertSingleUniform @ 0x97bb10f0 (452 bytes) */
int BindingTable__InsertSingleUniform(this, binding, isFragment)
  unsigned char * this;
  unsigned char * binding;
  int isFragment;
{
  int bindingSlots;
  int isBuiltIn;
  int activeIndex;
  int hashIdx;
  undefined4 result;
  int location;
  unsigned char * nextNode;
  unsigned char * curNode;
  uint glType;
  int lastLocation;
  int lastSlots;
  
  result = 0;
  if (binding != (unsigned char *)0x0) {
    lastLocation = 0;
    lastSlots = 0;
    nextNode = *(unsigned char **)(this + 0x14);
    if (*(unsigned char **)(this + 0x14) == (unsigned char *)0x0) {
      *(unsigned char **)(this + 0x14) = binding;
    }
    else {
      do {
        curNode = nextNode;
        location = ((int (*)())Binding__GetLocation)(curNode);
        if (-1 < location) {
          lastSlots = ((int (*)())Binding__GetBindingSlots)(curNode);
          lastLocation = location;
        }
        nextNode = (unsigned char *)((int (*)())Binding__GetNextBinding)(curNode);
      } while (nextNode != (unsigned char *)0x0);
      ((int (*)())Binding__SetNextBinding)(curNode,binding);
    }
    ((int (*)())Binding__SetLocation)(binding,lastLocation + lastSlots);
    hashIdx = Binding__GetHash(binding,*(uint *)this);
    nextNode = *(unsigned char **)(hashIdx * 4 + *(int *)(this + 0x18));
    if (nextNode == (unsigned char *)0x0) {
      *(unsigned char **)(hashIdx * 4 + *(int *)(this + 0x18)) = binding;
    }
    else {
      do {
        curNode = nextNode;
        nextNode = (unsigned char *)((int (*)())Binding__GetNextBindingInHash)(curNode);
      } while (nextNode != (unsigned char *)0x0);
      ((int (*)())Binding__SetNextBindingInHash)(curNode,binding);
    }
    activeIndex = *(int *)(this + 0x20);
    *(int *)(this + 0x20) = activeIndex + 1;
    ((int (*)())Binding__SetActiveIndex)(binding,activeIndex);
    isBuiltIn = Binding__IsBuiltIn(binding);
    if (isBuiltIn == 0) {
      bindingSlots = ((int (*)())Binding__GetBindingSlots)(binding);
      *(int *)(this + 0x24) = *(int *)(this + 0x24) + bindingSlots;
    }
    if (isFragment != 0) {
      binding[0x35] = 0x1;
      bindingSlots = ((int (*)())Binding__GetBindingSlots)(binding);
      *(int *)(this + 0x30) = *(int *)(this + 0x30) + bindingSlots;
    }
    else {
      binding[0x34] = 0x1;
      bindingSlots = ((int (*)())Binding__GetBindingSlots)(binding);
      *(int *)(this + 0x2c) = *(int *)(this + 0x2c) + bindingSlots;
    }
    glType = ((int (*)())Binding__GetOpenGLType)(binding);
    if ((0x8b5c < glType) && (glType < 0x8b65)) {
      if (isFragment != 0) {
        *(int *)(this + 0x44) = *(int *)(this + 0x44) + 1;
      }
      else {
        *(int *)(this + 0x40) = *(int *)(this + 0x40) + 1;
      }
    }
    if (*(int *)(this + 0x3c) < *(int *)(binding + 0x10) + 1) {
      *(int *)(this + 0x3c) = *(int *)(binding + 0x10) + 1;
    }
    result = 1;
  }
  return result;
}

/* BindingTable__AddSingleUniformReference @ 0x97bb12b4 (184 bytes) */
int BindingTable__AddSingleUniformReference(this, binding, isFragment)
  unsigned char * this;
  unsigned char * binding;
  int isFragment;
{
  int slotCount;
  uint glType;
  
  if (isFragment != 0) {
    binding[0x35] = 0x1;
    slotCount = ((int (*)())Binding__GetBindingSlots)(binding);
    *(int *)(this + 0x30) = *(int *)(this + 0x30) + slotCount;
  }
  else {
    binding[0x34] = 0x1;
    slotCount = ((int (*)())Binding__GetBindingSlots)(binding);
    *(int *)(this + 0x2c) = *(int *)(this + 0x2c) + slotCount;
  }
  glType = ((int (*)())Binding__GetOpenGLType)(binding);
  if ((0x8b5c < glType) && (glType < 0x8b65)) {
    if (isFragment != 0) {
      *(int *)(this + 0x44) = *(int *)(this + 0x44) + 1;
    }
    else {
      *(int *)(this + 0x40) = *(int *)(this + 0x40) + 1;
    }
  }
  return;
}

/* BindingTable__InsertUniformArray @ 0x97bb136c (944 bytes) */
int BindingTable__InsertUniformArray(this, binding, unusedArg3, firstTable, endTable, parseSymbolTable)
  unsigned char * this;
  unsigned char * binding;
  int unusedArg3;
  int firstTable;
  int endTable;
  unsigned char ** parseSymbolTable;
{
  int lastBindingSlots;
  int elementIdx;
  int bindingSlots;
  int activeIndex;
  int hashIdx;
  int location;
  int probeIdx;
  int isBuiltIn;
  int lastIndex;
  bool keepElement;
  undefined4 result;
  int elementIdxDown;
  int symbolFound;
  unsigned char * elementBinding;
  unsigned char * symbolTable;
  int elementSymbolFound;
  int curLocation;
  unsigned char * nextNode;
  unsigned char * curNode;
  uint glType;
  ulong elementsLeft;
  int stageIdx;
  unsigned char ** tablePtr;
  char indexText [32];
  char indexText2 [32];
  undefined8 stageMaxIndex;
  
  result = 0;
  if (binding != (unsigned char *)0x0) {
    stageMaxIndex = stageMaxIndexInit_97c38f98;
    elementIdxDown = ((int (*)())Binding__GetDecSize)(binding);
    while (elementIdxDown = elementIdxDown + -1, -1 < elementIdxDown) {
      Binding__RemoveNameBackToChar(binding,0x5b);
      _sprintf(indexText,"[%d]",elementIdxDown);
      Binding__CatName(binding,indexText);
      for (stageIdx = firstTable; stageIdx < endTable; stageIdx = stageIdx + 1) {
        if (((parseSymbolTable[stageIdx] != (unsigned char *)0x0) &&
            (symbolFound = ParseSymbolTable__FindSymbolByName(parseSymbolTable[stageIdx],*(char **)(binding + 8)),
            symbolFound != 0)) && (*(int *)((int)&stageMaxIndex + stageIdx * 4) < elementIdxDown)) {
          *(int *)((int)&stageMaxIndex + stageIdx * 4) = elementIdxDown;
        }
      }
    }
    (*(unsigned int *)((unsigned char *)&(stageMaxIndex) + 0)) = (int)((ulonglong)stageMaxIndex >> 0x20);
    lastIndex = (*(unsigned int *)((unsigned char *)&(stageMaxIndex) + 4));
    if ((*(int *)((unsigned char *)&(stageMaxIndex) + 4)) < (*(int *)((unsigned char *)&(stageMaxIndex) + 0))) {
      lastIndex = (*(unsigned int *)((unsigned char *)&(stageMaxIndex) + 0));
    }
    elementIdx = 0;
    Binding__RemoveNameBackToChar(binding,0x5b);
    if (-1 < lastIndex) {
      elementsLeft = lastIndex + 1;
      do {
        keepElement = true;
        elementBinding = operator_new(0x38);
        __ZN7BindingC1ERKS_(elementBinding,binding);
        _sprintf(indexText2,"[%d]",elementIdx);
        Binding__CatName(elementBinding,indexText2);
        isBuiltIn = Binding__IsBuiltIn(binding);
        if (isBuiltIn != 0) {
          keepElement = false;
          if (firstTable < endTable) {
            tablePtr = parseSymbolTable + firstTable;
            probeIdx = firstTable;
            do {
              symbolTable = *tablePtr;
              tablePtr = tablePtr + 1;
              if ((symbolTable != (unsigned char *)0x0) &&
                 (elementSymbolFound = ParseSymbolTable__FindSymbolByName(symbolTable,*(char **)(elementBinding + 8)),
                 elementSymbolFound != 0)) goto setLocation;
              probeIdx = probeIdx + 1;
            } while (probeIdx < endTable);
          }
          if (elementBinding != (unsigned char *)0x0) {
            __ZN7BindingD1Ev(elementBinding);
            __ZdlPv(elementBinding);
          }
        }
        if (keepElement) {
setLocation:
          location = 0;
          lastBindingSlots = 0;
          nextNode = *(unsigned char **)(this + 0x14);
          if (*(unsigned char **)(this + 0x14) == (unsigned char *)0x0) {
            *(unsigned char **)(this + 0x14) = elementBinding;
          }
          else {
            do {
              curNode = nextNode;
              curLocation = ((int (*)())Binding__GetLocation)(curNode);
              if (-1 < curLocation) {
                lastBindingSlots = ((int (*)())Binding__GetBindingSlots)(curNode);
                location = curLocation;
              }
              nextNode = (unsigned char *)((int (*)())Binding__GetNextBinding)(curNode);
            } while (nextNode != (unsigned char *)0x0);
            ((int (*)())Binding__SetNextBinding)(curNode,elementBinding);
          }
          ((int (*)())Binding__SetLocation)(elementBinding,location + lastBindingSlots);
          hashIdx = Binding__GetHash(elementBinding,*(uint *)this);
          nextNode = *(unsigned char **)(hashIdx * 4 + *(int *)(this + 0x18));
          if (nextNode == (unsigned char *)0x0) {
            *(unsigned char **)(hashIdx * 4 + *(int *)(this + 0x18)) = elementBinding;
          }
          else {
            do {
              curNode = nextNode;
              nextNode = (unsigned char *)((int (*)())Binding__GetNextBindingInHash)(curNode);
            } while (nextNode != (unsigned char *)0x0);
            ((int (*)())Binding__SetNextBindingInHash)(curNode,elementBinding);
          }
          ((int (*)())Binding__SetActualSize)(elementBinding,elementsLeft);
          if (elementIdx == 0) {
            activeIndex = *(int *)(this + 0x20);
            *(int *)(this + 0x20) = activeIndex + 1;
            ((int (*)())Binding__SetActiveIndex)(elementBinding,activeIndex);
          }
          isBuiltIn = Binding__IsBuiltIn(elementBinding);
          if (isBuiltIn == 0) {
            bindingSlots = ((int (*)())Binding__GetBindingSlots)(elementBinding);
            *(int *)(this + 0x24) = *(int *)(this + 0x24) + bindingSlots;
          }
          if (elementIdx <= (*(int *)((unsigned char *)&(stageMaxIndex) + 0))) {
            elementBinding[0x34] = 0x1;
            bindingSlots = ((int (*)())Binding__GetBindingSlots)(elementBinding);
            *(int *)(this + 0x2c) = *(int *)(this + 0x2c) + bindingSlots;
            glType = ((int (*)())Binding__GetOpenGLType)(elementBinding);
            if ((0x8b5c < glType) && (glType < 0x8b65)) {
              *(int *)(this + 0x40) = *(int *)(this + 0x40) + 1;
            }
          }
          if (elementIdx <= (*(int *)((unsigned char *)&(stageMaxIndex) + 4))) {
            elementBinding[0x35] = 0x1;
            bindingSlots = ((int (*)())Binding__GetBindingSlots)(binding);
            *(int *)(this + 0x30) = *(int *)(this + 0x30) + bindingSlots;
            glType = ((int (*)())Binding__GetOpenGLType)(elementBinding);
            if ((0x8b5c < glType) && (glType < 0x8b65)) {
              *(int *)(this + 0x44) = *(int *)(this + 0x44) + 1;
            }
          }
          if (*(int *)(this + 0x3c) < *(int *)(elementBinding + 0x10) + 1) {
            *(int *)(this + 0x3c) = *(int *)(elementBinding + 0x10) + 1;
          }
        }
        elementIdx = elementIdx + 1;
        elementsLeft = elementsLeft - 1;
      } while (elementIdx <= lastIndex);
    }
    __ZN7BindingD1Ev(binding);
    __ZdlPv(binding);
    result = 1;
  }
  return result;
}

/* BindingTable__NextUniformBinding @ 0x97bb171c (24 bytes) */
int BindingTable__NextUniformBinding(this, binding)
  unsigned char * this;
  unsigned char * binding;
{
  undefined4 nextBinding;
  
  if (binding != (unsigned char *)0x0) {
    nextBinding = ((int (*)())Binding__GetNextBinding)(binding);
    return nextBinding;
  }
  return *(undefined4 *)(this + 0x14);
}

/* BindingTable__FindUniformBinding @ 0x97bb1734 (116 bytes) */
int BindingTable__FindUniformBinding(this, binding)
  unsigned char * this;
  unsigned char * binding;
{
  int isEqual;
  int hashIdx;
  unsigned char *entry;
  
  hashIdx = Binding__GetHash(binding,*(uint *)this);
  entry = *(unsigned char **)(hashIdx * 4 + *(int *)(this + 0x18));
  while ((entry != (unsigned char *)0x0 && (isEqual = __ZeqRK7BindingS1_(entry,binding), isEqual != 1))) {
    entry = (unsigned char *)((int (*)())Binding__GetNextBindingInHash)(entry);
  }
  return entry;
}

/* BindingTable__FindUniformBindingByName @ 0x97bb17a8 (116 bytes) */
int BindingTable__FindUniformBindingByName(this, str)
  unsigned char * this;
  char *str;
{
  unsigned char *probe;
  
  if (str != (char *)0x0) {
    probe = operator_new(0x38);
    __ZN7BindingC1Ev(probe);
    if (probe != (unsigned char *)0x0) {
      Binding__SetName(probe,str);
      ((int (*)())BindingTable__FindUniformBinding)(this,probe);
      __ZN7BindingD1Ev(probe);
      __ZdlPv(probe);
    }
  }
  return 0;
}

/* BindingTable__FindClientUniformBindingLocationByName @ 0x97bb181c (264 bytes) */
int BindingTable__FindClientUniformBindingLocationByName(this, str)
  unsigned char * this;
  char *str;
{
  int glPrefixCmp;
  unsigned char * probe;
  unsigned char * found;
  undefined4 location;
  
  location = 0xffffffff;
  if ((str != (char *)0x0) && (glPrefixCmp = _memcmp(str,"gl_",3), glPrefixCmp != 0)) {
    probe = operator_new(0x38);
    __ZN7BindingC1Ev(probe);
    if (probe != (unsigned char *)0x0) {
      Binding__SetName(probe,str);
      found = (unsigned char *)((int (*)())BindingTable__FindUniformBinding)(this,probe);
      if (found == (unsigned char *)0x0) {
        if (*(char *)(*(int *)(probe + 8) + *(int *)(probe + 0x10) + -1) != ']') {
          Binding__CatName(probe,"[0]");
          found = (unsigned char *)((int (*)())BindingTable__FindUniformBinding)(this,probe);
          if (found != (unsigned char *)0x0) {
            location = ((int (*)())Binding__GetLocation)(found);
          }
        }
      }
      else {
        location = ((int (*)())Binding__GetLocation)(found);
      }
      __ZN7BindingD1Ev(probe);
      __ZdlPv(probe);
    }
  }
  return location;
}

/* BindingTable__FindUniformBindingByLocation @ 0x97bb1924 (160 bytes) */
int BindingTable__FindUniformBindingByLocation(this, wantedLocation)
  unsigned char * this;
  long wantedLocation;
{
  int location;
  int bindingSlots;
  uint bindingBasicSize;
  unsigned char * binding;
  
  binding = *(unsigned char **)(this + 0x14);
  while( true ) {
    if (binding == (unsigned char *)0x0) {
      return (unsigned char *)0x0;
    }
    location = ((int (*)())Binding__GetLocation)(binding);
    if (location == wantedLocation) break;
    if ((location < wantedLocation) &&
       (bindingSlots = ((int (*)())Binding__GetBindingSlots)(binding), (uint)wantedLocation < (uint)(location + bindingSlots))) {
      bindingBasicSize = ((int (*)())Binding__GetBindingBasicSize)(binding);
      if (wantedLocation - location != ((uint)(wantedLocation - location) / bindingBasicSize) * bindingBasicSize) {
        return (unsigned char *)0x0;
      }
      return binding;
    }
    binding = (unsigned char *)((int (*)())Binding__GetNextBinding)(binding);
  }
  return binding;
}

/* BindingTable__FindUniformBindingByIndex @ 0x97bb19c4 (88 bytes) */
int BindingTable__FindUniformBindingByIndex(this, wantedIndex)
  unsigned char * this;
  long wantedIndex;
{
  int activeIndex;
  unsigned char * binding;
  
  binding = *(unsigned char **)(this + 0x14);
  while ((binding != (unsigned char *)0x0 && (activeIndex = ((int (*)())Binding__GetActiveIndex)(binding), activeIndex != wantedIndex))
        ) {
    binding = (unsigned char *)((int (*)())Binding__GetNextBinding)(binding);
  }
  return binding;
}

/* BindingTable__GetNumActiveAttributeBindings @ 0x97bb1a1c (8 bytes) */
int BindingTable__GetNumActiveAttributeBindings(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 0x1c);
}

/* BindingTable__GetNumActiveUniformBindings @ 0x97bb1a24 (8 bytes) */
int BindingTable__GetNumActiveUniformBindings(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 0x20);
}

/* BindingTable__GetSizeActiveUserUniforms @ 0x97bb1a2c (8 bytes) */
int BindingTable__GetSizeActiveUserUniforms(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 0x24);
}

/* BindingTable__GetSizeActiveUserAttributes @ 0x97bb1a34 (8 bytes) */
int BindingTable__GetSizeActiveUserAttributes(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 0x28);
}

/* BindingTable__GetSizeActiveVertexUniforms @ 0x97bb1a3c (8 bytes) */
int BindingTable__GetSizeActiveVertexUniforms(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 0x2c);
}

/* BindingTable__GetSizeActiveFragmentUniforms @ 0x97bb1a44 (8 bytes) */
int BindingTable__GetSizeActiveFragmentUniforms(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 0x30);
}

/* BindingTable__GetSizeActiveAttributes @ 0x97bb1a4c (8 bytes) */
int BindingTable__GetSizeActiveAttributes(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 0x34);
}

/* BindingTable__GetMaxAttributeLength @ 0x97bb1a54 (8 bytes) */
int BindingTable__GetMaxAttributeLength(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 0x38);
}

/* BindingTable__GetMaxUniformLength @ 0x97bb1a5c (8 bytes) */
int BindingTable__GetMaxUniformLength(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 0x3c);
}

/* BindingTable__GetNumActiveVertexSamplers @ 0x97bb1a64 (8 bytes) */
int BindingTable__GetNumActiveVertexSamplers(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 0x40);
}

/* BindingTable__GetNumActiveFragmentSamplers @ 0x97bb1a6c (8 bytes) */
int BindingTable__GetNumActiveFragmentSamplers(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 0x44);
}

/* BindingTable__GetString @ 0x97bb1a74 (1028 bytes) */
int BindingTable__GetString(this, kind)
  unsigned char * this;
  int kind;
{
  int bucketArray;
  int kindStr;
  int kindIdx;
  char *kindHeader;
  int stringValue;
  int string;
  bool listEmpty;
  char *result;
  int kindCounter;
  int length;
  int length2;
  char *header;
  char *buf;
  int usedLen;
  uint capacity;
  uint loopIndex;
  unsigned char * binding;
  
  binding = (unsigned char *)0x0;
  result = (char *)_malloc(0x800);
  capacity = 0x800;
  usedLen = 0;
  if (result == (char *)0x0) {
    return (char *)0x0;
  }
  *result = '\0';
  buf = result;
  if (2 < kind) {
    if (kind == 3) {
      kindIdx = 0;
      do {
        string = GetString(this,kindIdx);
        result = buf;
        if (string != 0) {
          length = _strlen(string);
          length2 = _strlen(buf);
          result = (char *)_realloc(buf,length + length2 + 1);
          if (result == (char *)0x0) goto callFree;
          _sprintf(result,"%s%s",result,string);
          _free(string);
        }
        kindIdx = kindIdx + 1;
        buf = result;
        if (2 < kindIdx) {
          return result;
        }
      } while( true );
    }
    kindCounter = 4;
    if (6 < kind) {
      do {
        kindStr = GetString(this,kindCounter);
        result = buf;
        if (kindStr != 0) {
          length = _strlen(kindStr);
          length2 = _strlen(buf);
          result = (char *)_realloc(buf,length + length2 + 1);
          if (result == (char *)0x0) goto callFree;
          _sprintf(result,"%s%s",result,kindStr);
          _free(kindStr);
        }
        kindCounter = kindCounter + 1;
        buf = result;
        if (6 < kindCounter) {
          return result;
        }
      } while( true );
    }
    if (kind == 5) {
      if (**(int **)(this + 0x10) == 0) {
        kindHeader = "\n No Attribute Bindings\n";
      }
      else {
        kindHeader = "\n Attribute Bindings: [Index: (Location) \'Name\'- Type Shader]\n";
      }
    }
    else if (5 < kind) {
      if (kind != 6) goto setLoopIndex;
      if (**(int **)(this + 0x18) == 0) {
        kindHeader = "\n No Uniform Bindings\n";
      }
      else {
        kindHeader = "\n Uniform Bindings: [Index: (Location) \'Name\'- Type Shader]\n";
      }
    }
    else {
      if (kind != 4) goto setLoopIndex;
      if (**(int **)(this + 8) == 0) {
        kindHeader = "\n No Client Attribute Requests\n";
      }
      else {
        kindHeader = "\n Client Attribute Requests: [Index: (Location) \'Name\'- Type Shader]\n";
      }
    }
    _sprintf(result,kindHeader);
setLoopIndex:
    loopIndex = 0;
    if (*(int *)this == 0) {
      return result;
    }
    do {
      if (kind == 5) {
        bucketArray = *(int *)(this + 0x10);
loopSetBinding:
        binding = *(unsigned char **)(loopIndex * 4 + bucketArray);
      }
      else if (5 < kind) {
        if (kind == 6) {
          bucketArray = *(int *)(this + 0x18);
          goto loopSetBinding;
        }
      }
      else if (kind == 4) {
        bucketArray = *(int *)(this + 8);
        goto loopSetBinding;
      }
      if (binding != (unsigned char *)0x0) {
        _sprintf(result,"%s  --- Hash %d ---\n",result,loopIndex);
        buf = result;
        do {
          stringValue = ((int (*)())Binding__GetString)(binding);
          if (stringValue != 0) {
            length = _strlen(stringValue);
            usedLen = usedLen + length;
            _sprintf(buf,"%s   %s",buf,stringValue);
            _free(stringValue);
          }
          result = buf;
          if (capacity < usedLen + 0x300U) {
            capacity = capacity << 1;
            result = (char *)_realloc(buf,capacity);
            if (result == (char *)0x0) goto callFree;
          }
          binding = (unsigned char *)((int (*)())Binding__GetNextBindingInHash)(binding);
          buf = result;
        } while (binding != (unsigned char *)0x0);
      }
      loopIndex = loopIndex + 1;
      if (*(uint *)this <= loopIndex) {
        return result;
      }
    } while( true );
  }
  if (kind == 1) {
    binding = *(unsigned char **)(this + 0xc);
    listEmpty = binding == (unsigned char *)0x0;
    if (listEmpty) {
      header = "\n No Attribute Bindings\n";
    }
    else {
      header = "\n Attribute Bindings: [Index: (Location) \'Name\'- Type Shader]\n";
    }
  }
  else if (kind < 2) {
    listEmpty = true;
    if (kind != 0) goto checkListEmpty;
    binding = *(unsigned char **)(this + 4);
    listEmpty = binding == (unsigned char *)0x0;
    if (listEmpty) {
      header = "\n No Client Attribute Requests\n";
    }
    else {
      header = "\n Client Attribute Requests: [Index: (Location) \'Name\'- Type Shader]\n";
    }
  }
  else {
    if (kind != 2) {
      listEmpty = true;
      goto checkListEmpty;
    }
    binding = *(unsigned char **)(this + 0x14);
    listEmpty = binding == (unsigned char *)0x0;
    if (listEmpty) {
      header = "\n No Uniform Bindings\n";
    }
    else {
      header = "\n Uniform Bindings: [Index: (Location) \'Name\'- Type Shader]\n";
    }
  }
  _sprintf(result,header);
checkListEmpty:
  if (!listEmpty) {
    do {
      stringValue = ((int (*)())Binding__GetString)(binding);
      if (stringValue != 0) {
        length = _strlen(stringValue);
        usedLen = usedLen + length;
        _sprintf(buf,"%s  %s",buf,stringValue);
        _free(stringValue);
      }
      result = buf;
      if (capacity < usedLen + 0x300U) {
        capacity = capacity << 1;
        result = (char *)_realloc(buf,capacity);
        if (result == (char *)0x0) {
callFree:
          _free(buf);
          return (char *)0x0;
        }
      }
      binding = (unsigned char *)((int (*)())Binding__GetNextBinding)(binding);
      buf = result;
    } while (binding != (unsigned char *)0x0);
  }
  return result;
}

/* ConstructLinker @ 0x97bb1e78 (64 bytes) */
int ConstructLinker(linkerArg)
  int linkerArg;
{
  void *this;
  
  this = operator_new(0x88);
  __ZN14TGenericLinkerC1Ei(this,linkerArg);
  return this;
}

/* DeleteLinker @ 0x97bb1eb8 (24 bytes) */
int DeleteLinker(shHandleBase)
  unsigned char * shHandleBase;
{
  if (shHandleBase == (unsigned char *)0x0) {
    return;
  }
                    
                    
  (**(code **)(*(int *)shHandleBase + 4))(shHandleBase);
  return;
}

/* UpdateOperations @ 0x97bb1ed0 (504 bytes) */
int UpdateOperations(_PPStreamChunk1, _PPStreamChunk2, unusedArg3, _PPStreamChunk3, numCopies, adjust)
  unsigned char * _PPStreamChunk1;
  unsigned char * _PPStreamChunk2;
  int unusedArg3;
  unsigned char * _PPStreamChunk3;
  int numCopies;
  int adjust;
{
  int operandIdx;
  bool matchesKind;
  int walkIdx;
  int newWalkIdx;
  unsigned char * chunk;
  int chunkIdx;
  unsigned char * target;
  unsigned char * operand;
  int walkIdxNext;
  uint chunkInfo;
  unsigned char kind;
  int copyIdx;
  
  copyIdx = 0;
  if (0 < numCopies) {
    do {
      chunkIdx = 0;
      walkIdx = 0;
      if (_PPStreamChunk2 != (unsigned char *)0x0) {
        kind = *_PPStreamChunk3;
        chunk = _PPStreamChunk2;
        target = _PPStreamChunk1;
        do {
          chunkInfo = *(uint *)(chunk + 0xc);
          operandIdx = 0;
          if (chunkInfo >> 0x1d != 0) {
            operand = chunk + 0x10;
            do {
              if (kind == 0x2) {
                if ((*(uint *)(operand + 0xc) & 0x3800000) == 0) goto checkOperand;
              }
              else {
                if ((byte)kind < 3) {
                  if (kind != 0x0) goto setOperandIdx;
                  matchesKind = (*(uint *)(operand + 0xc) >> 0x17 & 7) == 1;
                }
                else if (kind == 0x3) {
                  matchesKind = (*(uint *)(operand + 0xc) >> 0x17 & 7) == 2;
                }
                else {
                  if (kind != 0x4) goto setOperandIdx;
                  matchesKind = (*(uint *)(operand + 0xc) >> 0x17 & 7) == 3;
                }
                if (matchesKind) {
checkOperand:
                  if ((uint)*(ushort *)(operand + 0x12) == (uint)*(ushort *)(_PPStreamChunk3 + 0x12) + copyIdx
                     ) {
                    newWalkIdx = walkIdx;
                    if ((walkIdx != chunkIdx) && (newWalkIdx = chunkIdx, walkIdx < chunkIdx)) {
                      walkIdx = chunkIdx - walkIdx;
                      do {
                        target = *(unsigned char **)(target + 8);
                        walkIdx = walkIdx + -1;
                      } while (walkIdx != 0);
                    }
                    *(short *)(target + operandIdx * 8 + 0x22) =
                         *(short *)(target + operandIdx * 8 + 0x22) - (short)adjust;
                    chunkInfo = *(uint *)(chunk + 0xc);
                    kind = *_PPStreamChunk3;
                    walkIdx = newWalkIdx;
                  }
                }
              }
setOperandIdx:
              operandIdx = operandIdx + 1;
              operand = operand + 8;
            } while (operandIdx < (int)(chunkInfo >> 0x1d));
          }
          if (kind == 0x2) {
            if ((*(uint *)(chunk + 0x14) & 0xe0000) == 0) goto checkChunk;
          }
          else {
            if ((byte)kind < 3) {
              if (kind != 0x0) goto setChunk;
              matchesKind = (*(uint *)(chunk + 0x14) & 0xe0000) == 0x20000;
            }
            else if (kind == 0x3) {
              matchesKind = (*(uint *)(chunk + 0x14) & 0xe0000) == 0x40000;
            }
            else {
              if (kind != 0x4) goto setChunk;
              matchesKind = (*(uint *)(chunk + 0x14) & 0xe0000) == 0x60000;
            }
            if (matchesKind) {
checkChunk:
              if ((uint)*(ushort *)(chunk + 0x1a) == (uint)*(ushort *)(_PPStreamChunk3 + 0x12) + copyIdx) {
                walkIdxNext = walkIdx;
                if ((walkIdx != chunkIdx) && (walkIdxNext = chunkIdx, walkIdx < chunkIdx)) {
                  walkIdx = chunkIdx - walkIdx;
                  do {
                    target = *(unsigned char **)(target + 8);
                    walkIdx = walkIdx + -1;
                  } while (walkIdx != 0);
                }
                *(short *)(target + 0x1a) = *(short *)(target + 0x1a) - (short)adjust;
                walkIdx = walkIdxNext;
              }
            }
          }
setChunk:
          chunk = *(unsigned char **)(chunk + 8);
          chunkIdx = chunkIdx + 1;
        } while (chunk != (unsigned char *)0x0);
      }
      copyIdx = copyIdx + 1;
    } while (copyIdx < numCopies);
  }
  return;
}

/* TGenericLinker__FindChunkDelta @ 0x97bb20c8 (84 bytes) */
int TGenericLinker__FindChunkDelta(this, _PPStreamChunk1, _PPStreamChunk2)
  unsigned char * this;
  unsigned char * _PPStreamChunk1;
  unsigned char * _PPStreamChunk2;
{
  bool kindKnown;
  unsigned char kind;
  char *errorText;
  void *infoSink;
  
  errorText = chunkTypesDoMatchWhenStrPtr_a7b7bb8c;
  kind = *_PPStreamChunk1;
  if (kind != *_PPStreamChunk2) {
    infoSink = *(void **)(this + 0x84);
                    
    __ZN13TInfoSinkBase6appendEPKc(infoSink,"INTERNAL ERROR: ");
    __ZN13TInfoSinkBase6appendEPKc(infoSink,errorText);
    __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
    return 0;
  }
  if (kind != 0x2) {
    if ((byte)kind < 3) {
      kindKnown = kind == 0x0;
    }
    else {
      if (kind == 0x3) goto returnPPStreamChunk1;
      kindKnown = kind == 0x4;
    }
    if (!kindKnown) {
      return 0;
    }
  }
returnPPStreamChunk1:
  return (uint)*(ushort *)(_PPStreamChunk1 + 0x12) - (uint)*(ushort *)(_PPStreamChunk2 + 0x12);
}

