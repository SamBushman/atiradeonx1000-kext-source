#include "decls.h"

/* __ZNK10__cxxabiv120__si_class_type_info12__do_dyncastEiNS_17__class_type_info10__sub_kindEPKS1_PKvS4_S6_RNS1_16__dyncast_resultE @ 0x97c185fc (244 bytes) */
int __ZNK10__cxxabiv120__si_class_type_info12__do_dyncastEiNS_17__class_type_info10__sub_kindEPKS1_PKvS4_S6_RNS1_16__dyncast_resultE(this, src2dst, accessPath, dstType, objPtr, srcType, srcPtr, result)
  void *this;
  int src2dst;
  int accessPath;
  unsigned char * dstType;
  int objPtr;
  unsigned char * srcType;
  int srcPtr;
  int *result;
{
  int dst2srcKind;
  int isSrcType;
  int isDstType;
  undefined4 baseDyncastResult;
  
  isDstType = __ZNKSt9type_infoeqERKS_(this,dstType);
  if (isDstType == 0) {
    if ((objPtr == srcPtr) && (isSrcType = __ZNKSt9type_infoeqERKS_(this,srcType), isSrcType != 0)) {
      result[2] = accessPath;
      return 0;
    }
                    
                    
    baseDyncastResult = (**(code **)(**(int **)((int)this + 8) + 0x1c))
                      (*(int **)((int)this + 8),src2dst,accessPath,dstType,objPtr,srcType,srcPtr,
                       result);
    return baseDyncastResult;
  }
  result[1] = accessPath;
  *result = objPtr;
  if (src2dst < 0) {
    if (src2dst != -2) {
      return 0;
    }
  }
  else {
    dst2srcKind = 6;
    if (objPtr + src2dst == srcPtr) goto LAB_97c1866c;
  }
  dst2srcKind = 1;
LAB_97c1866c:
  result[3] = dst2srcKind;
  return 0;
}

/* __cxxabiv1____vmi_class_type_info____do_dyncast @ 0x97c186f0 (1092 bytes) */
int __cxxabiv1____vmi_class_type_info____do_dyncast(this, src2dst, accessPath, dstType, objPtr, srcType, srcPtr, result)
  unsigned char * this;
  int src2dst;
  uint accessPath;
  unsigned char * dstType;
  int *objPtr;
  unsigned char * srcType;
  int *srcPtr;
  int *result;
{
  uint newDst2src;
  uint curDst2src;
  int dst2srcKind;
  int baseIndex;
  int isDstType;
  int curDstPtr;
  uint iterResultAmbig;
  bool src2dstNotNeg2;
  bool isLastBase;
  uint baseOffsetFlags;
  int baseOffset;
  uint oldWhole2src;
  int srcMatch;
  uint baseAccess;
  uint resultAmbig;
  unsigned char * baseInfo;
  int result2DstPtr;
  uint result2Whole2dst;
  uint result2Whole2src;
  uint result2Dst2src;
  uint result2WholeDetails;
  
  if ((result[4] & 0x10U) != 0) {
    result[4] = *(int *)(this + 8);
  }
  if ((objPtr == srcPtr) && (srcMatch = __ZNKSt9type_infoeqERKS_(this,srcType), srcMatch != 0)) {
    result[2] = accessPath;
    return 0;
  }
  isDstType = __ZNKSt9type_infoeqERKS_(this,dstType);
  if (isDstType == 0) {
    baseIndex = *(int *)(this + 0xc) + -1;
    if (*(int *)(this + 0xc) == 0) {
      return 0;
    }
    src2dstNotNeg2 = src2dst != -2;
    baseInfo = this + baseIndex * 8 + 0x10;
    resultAmbig = 0;
    do {
      result2WholeDetails = result[4];
      result2Dst2src = 0;
      result2DstPtr = 0;
      result2Whole2dst = 0;
      result2Whole2src = 0;
      baseOffsetFlags = *(uint *)(baseInfo + 4);
      baseOffset = (int)baseOffsetFlags >> 8;
      baseAccess = accessPath;
      if ((baseOffsetFlags & 1) != 0) {
        baseAccess = accessPath | 1;
        baseOffset = *(int *)(*objPtr + baseOffset);
      }
      if ((baseOffsetFlags & 2) == 0) {
        if ((src2dstNotNeg2) || (iterResultAmbig = resultAmbig, (result2WholeDetails & 3) != 0)) {
          baseAccess = baseAccess & 0xfffffffd;
          goto LAB_97c18848;
        }
      }
      else {
LAB_97c18848:
        iterResultAmbig = (**(code **)(**(int **)baseInfo + 0x1c))
                          (*(int **)baseInfo,src2dst,baseAccess,dstType,(int)objPtr + baseOffset,srcType,
                           srcPtr,&result2DstPtr);
        newDst2src = result2Dst2src;
        oldWhole2src = result[2];
        result[2] = oldWhole2src | result2Whole2src;
        if ((result2Dst2src == 6) || (result2Dst2src == 2)) {
          result[3] = result2Dst2src;
          *result = result2DstPtr;
          result[1] = result2Whole2dst;
          return iterResultAmbig;
        }
        if (resultAmbig == 0) {
          curDstPtr = *result;
          if (curDstPtr != 0) goto LAB_97c188fc;
          *result = result2DstPtr;
          result[1] = result2Whole2dst;
          if (((result2DstPtr != 0) && ((oldWhole2src | result2Whole2src) != 0)) &&
             (((*(uint *)(this + 8) ^ 1) & 1) != 0)) {
            return iterResultAmbig;
          }
        }
        else {
          curDstPtr = *result;
LAB_97c188fc:
          if ((curDstPtr == 0) || (curDstPtr != result2DstPtr)) {
            if (((curDstPtr != 0 && result2DstPtr != 0) || ((curDstPtr != 0 && ((iterResultAmbig & 1) != 0)))) ||
               ((iterResultAmbig = resultAmbig, result2DstPtr != 0 && ((resultAmbig & 1) != 0)))) {
              curDst2src = result[3];
              if ((result[2] < 4) || (((result[2] & 1U) != 0 && ((result[4] & 2U) != 0)))) {
                if ((int)curDst2src < 1) {
                  if (((int)result2Dst2src < 4) ||
                     (((result2Dst2src & 1) != 0 && ((*(uint *)(this + 8) & 2) != 0)))) {
                    if (src2dst < 0) {
                      if (!src2dstNotNeg2) goto LAB_97c189e8;
                      curDst2src = (**(code **)(*(int *)dstType + 0x20))
                                        (dstType,src2dst,curDstPtr,srcType,srcPtr);
                    }
                    else {
                      curDst2src = 6;
                      if ((int *)(curDstPtr + src2dst) != srcPtr) {
LAB_97c189e8:
                        curDst2src = 1;
                      }
                    }
                  }
                  else {
                    curDst2src = 1;
                  }
                }
                if ((int)newDst2src < 1) {
                  if ((3 < (int)curDst2src) && (((curDst2src & 1) == 0 || ((*(uint *)(this + 8) & 2) == 0))))
                  goto LAB_97c18a38;
                  if (src2dst < 0) {
                    if (!src2dstNotNeg2) goto LAB_97c18a60;
                    newDst2src = (**(code **)(*(int *)dstType + 0x20))
                                      (dstType,src2dst,result2DstPtr,srcType,srcPtr);
                  }
                  else {
                    newDst2src = 6;
                    if ((int *)(result2DstPtr + src2dst) != srcPtr) {
LAB_97c18a60:
                      newDst2src = 1;
                    }
                  }
                }
              }
              else {
                if (curDst2src == 0) {
                  curDst2src = 1;
                }
                if (result2Dst2src == 0) {
LAB_97c18a38:
                  newDst2src = 1;
                }
              }
              if ((int)(newDst2src ^ curDst2src) < 4) {
                if (3 < (int)(newDst2src & curDst2src)) {
                  *result = 0;
                  result[3] = 2;
                  return 1;
                }
                *result = 0;
                result[3] = 1;
                iterResultAmbig = 1;
              }
              else {
                iterResultAmbig = resultAmbig;
                if (3 < (int)newDst2src) {
                  iterResultAmbig = 0;
                  *result = result2DstPtr;
                  result[1] = result2Whole2dst;
                  curDst2src = newDst2src;
                }
                result[3] = curDst2src;
                if ((curDst2src & 2) != 0) {
                  return 0;
                }
                if ((curDst2src & 1) == 0) {
                  return 0;
                }
              }
            }
          }
          else {
            result[1] = result[1] | result2Whole2dst;
            iterResultAmbig = resultAmbig;
          }
        }
        if (result[2] == 4) {
          return iterResultAmbig;
        }
      }
      isLastBase = baseIndex == 0;
      baseInfo = baseInfo + -8;
      baseIndex = baseIndex + -1;
      resultAmbig = iterResultAmbig;
      if (isLastBase) {
        return iterResultAmbig;
      }
    } while( true );
  }
  result[1] = accessPath;
  *result = (int)objPtr;
  if (src2dst < 0) {
    if (src2dst != -2) {
      return 0;
    }
  }
  else {
    dst2srcKind = 6;
    if ((int *)((int)objPtr + src2dst) == srcPtr) goto LAB_97c187a0;
  }
  dst2srcKind = 1;
LAB_97c187a0:
  result[3] = dst2srcKind;
  return 0;
}

/* __ZNK10__cxxabiv117__class_type_info11__do_upcastEPKS0_PKvRNS0_15__upcast_resultE @ 0x97c18b34 (84 bytes) */
int __ZNK10__cxxabiv117__class_type_info11__do_upcastEPKS0_PKvRNS0_15__upcast_resultE(this, dstType, objPtr, result)
  void *this;
  unsigned char * dstType;
  void *objPtr;
  unsigned char * result;
{
  int isDstType;
  
  isDstType = __ZNKSt9type_infoeqERKS_(this,(unsigned char *)dstType);
  if (isDstType != 0) {
    *(void **)result = objPtr;
    *(undefined4 *)(result + 4) = 6;
    *(undefined4 *)(result + 0xc) = 8;
  }
  return isDstType != 0;
}

/* __ZNK10__cxxabiv120__si_class_type_info11__do_upcastEPKNS_17__class_type_infoEPKvRNS1_15__upcast_resultE @ 0x97c18b88 (116 bytes) */
int __ZNK10__cxxabiv120__si_class_type_info11__do_upcastEPKNS_17__class_type_infoEPKvRNS1_15__upcast_resultE(this, dstType, objPtr, result)
  void *this;
  unsigned char * dstType;
  void *objPtr;
  unsigned char * result;
{
  int classUpcastOk;
  undefined4 baseUpcastResult;
  
  classUpcastOk = ((int (*)())__ZNK10__cxxabiv117__class_type_info11__do_upcastEPKS0_PKvRNS0_15__upcast_resultE)(this,dstType,objPtr,result);
  if (classUpcastOk == 0) {
                    
                    
    baseUpcastResult = (**(code **)(**(int **)((int)this + 8) + 0x18))
                      (*(int **)((int)this + 8),dstType,objPtr,result);
    return baseUpcastResult;
  }
  return 1;
}

/* __cxxabiv1____vmi_class_type_info____do_upcast @ 0x97c18bfc (556 bytes) */
int __cxxabiv1____vmi_class_type_info____do_upcast(this, dstType, objPtr, result)
  unsigned char * this;
  unsigned char * dstType;
  void *objPtr;
  unsigned char * result;
{
  bool moreBases;
  bool isPublicBase;
  int sameBaseType;
  int baseUpcastOk;
  int baseIndex;
  uint baseOffsetFlags;
  int baseOffset;
  int classUpcastOk;
  unsigned char * resultBaseType;
  void *adjustedObjPtr;
  uint srcDetails;
  unsigned char * baseInfo;
  bool upcastResult;
  int result2DstPtr;
  uint result2Part2dst;
  uint result2SrcDetails;
  void *result2BaseType;
  
  classUpcastOk = ((int (*)())__ZNK10__cxxabiv117__class_type_info11__do_upcastEPKS0_PKvRNS0_15__upcast_resultE)(this,dstType,objPtr,result);
  upcastResult = true;
  if (classUpcastOk == 0) {
    srcDetails = *(uint *)(result + 8);
    if ((srcDetails & 0x10) != 0) {
      srcDetails = *(uint *)(this + 8);
    }
    baseIndex = *(int *)(this + 0xc) + -1;
    if (*(int *)(this + 0xc) != 0) {
      baseInfo = this + baseIndex * 8;
      do {
        baseOffsetFlags = *(uint *)(baseInfo + 0x14);
        result2DstPtr = 0;
        isPublicBase = (baseOffsetFlags >> 1 & 1) != 0;
        result2Part2dst = 0;
        baseOffset = (int)baseOffsetFlags >> 8;
        result2BaseType = (void *)0x0;
        if ((isPublicBase) || (((srcDetails ^ 1) & 1) == 0)) {
          adjustedObjPtr = objPtr;
          if (objPtr != (void *)0x0) {
            if ((baseOffsetFlags & 1) != 0) {
              baseOffset = *(int *)(*(int *)objPtr + baseOffset);
            }
            adjustedObjPtr = (void *)((int)objPtr + baseOffset);
          }
          result2SrcDetails = srcDetails;
          baseUpcastOk = (**(code **)(**(int **)(baseInfo + 0x10) + 0x18))
                            (*(int **)(baseInfo + 0x10),dstType,adjustedObjPtr,&result2DstPtr);
          if (baseUpcastOk != 0) {
            if ((result2BaseType == (void *)0x8) && ((baseOffsetFlags & 1) != 0)) {
              result2BaseType = *(void **)(baseInfo + 0x10);
            }
            if ((3 < (int)result2Part2dst) && (!isPublicBase)) {
              result2Part2dst = result2Part2dst & 0xfffffffd;
            }
            resultBaseType = *(unsigned char **)(result + 0xc);
            if (resultBaseType == (unsigned char *)0x0) {
              *(uint *)(result + 8) = result2SrcDetails;
              *(int *)result = result2DstPtr;
              *(void **)(result + 0xc) = result2BaseType;
              *(uint *)(result + 4) = result2Part2dst;
              if ((int)result2Part2dst < 4) {
                return true;
              }
              if ((result2Part2dst & 2) == 0) {
                if ((result2Part2dst & 1) == 0) {
                  return true;
                }
                if ((*(uint *)(this + 8) & 2) == 0) {
                  return true;
                }
              }
              else if (((*(uint *)(this + 8) ^ 1) & 1) != 0) {
                return true;
              }
            }
            else {
              if (*(int *)result != result2DstPtr) {
                *(undefined4 *)(result + 4) = 2;
                *(undefined4 *)result = 0;
                return true;
              }
              if ((*(int *)result == 0) &&
                 (((result2BaseType == (void *)0x8 || (resultBaseType == (unsigned char *)0x8)) ||
                  (sameBaseType = __ZNKSt9type_infoeqERKS_(result2BaseType,resultBaseType), sameBaseType == 0)))) {
                *(undefined4 *)(result + 4) = 2;
                return true;
              }
              *(uint *)(result + 4) = *(uint *)(result + 4) | result2Part2dst;
            }
          }
        }
        moreBases = baseIndex != 0;
        baseInfo = baseInfo + -8;
        baseIndex = baseIndex + -1;
      } while (moreBases);
    }
    upcastResult = *(int *)(result + 4) != 0;
  }
  return upcastResult;
}

/* ___dynamic_cast @ 0x97c18e28 (328 bytes) */
int ___dynamic_cast(srcPtr, srcType, dstType, src2dst)
  int *srcPtr;
  undefined4 srcType;
  int *dstType;
  int src2dst;
{
  int *whole;
  uint dst2srcKind;
  int castResult;
  int resultDstPtr;
  uint resultWhole2dst;
  uint resultWhole2src;
  uint resultDst2src;
  undefined4 resultWholeDetails;
  
  whole = *(int **)(*srcPtr + -4);
  resultWhole2src = 0;
  resultDst2src = 0;
  resultWholeDetails = 0x10;
  resultDstPtr = 0;
  resultWhole2dst = 0;
  (**(code **)(*whole + 0x1c))
            (whole,src2dst,6,dstType,(int)srcPtr + *(int *)(*srcPtr + -8),srcType,srcPtr,&resultDstPtr);
  castResult = 0;
  if ((((resultDstPtr != 0) && (castResult = resultDstPtr, (resultDst2src & 6) != 6)) &&
      ((resultWhole2src & resultWhole2dst & 6) != 6)) && (castResult = 0, (resultWhole2src & 5) != 4)) {
    dst2srcKind = resultDst2src;
    if (resultDst2src == 0) {
      if (src2dst < 0) {
        dst2srcKind = 0;
        if (src2dst != -2) {
          dst2srcKind = (**(code **)(*dstType + 0x20))(dstType,src2dst,resultDstPtr,srcType,srcPtr);
        }
      }
      else {
        dst2srcKind = 6;
        if ((int *)(resultDstPtr + src2dst) != srcPtr) {
          dst2srcKind = 0;
        }
      }
    }
    castResult = 0;
    if ((dst2srcKind & 6) == 6) {
      castResult = resultDstPtr;
    }
  }
  return castResult;
}

/* __ZNSt9exceptionD2Ev @ 0x97c18f70 (8 bytes) */
int __ZNSt9exceptionD2Ev(this)
  void *this;
{
  return ((int (*)())__ZNSt9exceptionD4Ev)(this,0);
}

/* __ZNSt9exceptionD1Ev @ 0x97c18f78 (8 bytes) */
int __ZNSt9exceptionD1Ev(this)
  void *this;
{
  return ((int (*)())__ZNSt9exceptionD4Ev)(this,2);
}

/* __ZNSt9exceptionD0Ev @ 0x97c18f80 (8 bytes) */
int __ZNSt9exceptionD0Ev(this)
  void *this;
{
  return ((int (*)())__ZNSt9exceptionD4Ev)(this,3);
}

/* __ZNSt9exceptionD4Ev @ 0x97c18f88 (72 bytes) */
int __ZNSt9exceptionD4Ev(this, deleteFlags)
  void *this;
  uint deleteFlags;
{
  *(int *)this = DAT_a7b7c034 + 8;
  if ((deleteFlags & 1) != 0) {
    __ZdlPv(this);
  }
  return;
}

/* __ZNSt13bad_exceptionD2Ev @ 0x97c18fd0 (8 bytes) */
int __ZNSt13bad_exceptionD2Ev(this)
  void *this;
{
  return ((int (*)())__ZNSt13bad_exceptionD4Ev)(this,0);
}

/* __ZNSt13bad_exceptionD1Ev @ 0x97c18fd8 (8 bytes) */
int __ZNSt13bad_exceptionD1Ev(this)
  void *this;
{
  return ((int (*)())__ZNSt13bad_exceptionD4Ev)(this,2);
}

/* __ZNSt13bad_exceptionD0Ev @ 0x97c18fe0 (8 bytes) */
int __ZNSt13bad_exceptionD0Ev(this)
  void *this;
{
  return ((int (*)())__ZNSt13bad_exceptionD4Ev)(this,3);
}

/* __ZNSt13bad_exceptionD4Ev @ 0x97c18fe8 (88 bytes) */
int __ZNSt13bad_exceptionD4Ev(this, deleteFlags)
  void *this;
  uint deleteFlags;
{
  *(int *)this = DAT_a7b7c030 + 8;
  ((int (*)())__ZNSt9exceptionD2Ev)(this);
  if ((deleteFlags & 1) != 0) {
    __ZdlPv(this);
  }
  return;
}

/* __ZNKSt9exception4whatEv @ 0x97c19040 (16 bytes) */
int __ZNKSt9exception4whatEv(this)
  void *this;
{
  return *(undefined4 *)(*(int *)(*(int *)this + -4) + 4);
}

/* std__set_new_handler @ 0x97c19050 (68 bytes) */
int std__set_new_handler(newHandler)
  unsigned char * newHandler;
{
  int oldHandler;
  
  oldHandler = __keymgr_get_per_thread_data(2);
  if (oldHandler == 0) {
    oldHandler = (int)___new_handler;
  }
  __keymgr_set_per_thread_data(2,newHandler);
  ___new_handler = newHandler;
  return oldHandler;
}

/* __ZNSt9bad_allocD2Ev @ 0x97c190c4 (8 bytes) */
int __ZNSt9bad_allocD2Ev(this)
  void *this;
{
  return ((int (*)())__ZNSt9bad_allocD4Ev)(this,0);
}

/* __ZNSt9bad_allocD1Ev @ 0x97c190cc (8 bytes) */
int __ZNSt9bad_allocD1Ev(this)
  void *this;
{
  return ((int (*)())__ZNSt9bad_allocD4Ev)(this,2);
}

/* __ZNSt9bad_allocD0Ev @ 0x97c190d4 (8 bytes) */
int __ZNSt9bad_allocD0Ev(this)
  void *this;
{
  return ((int (*)())__ZNSt9bad_allocD4Ev)(this,3);
}

/* __ZNSt9bad_allocD4Ev @ 0x97c190dc (88 bytes) */
int __ZNSt9bad_allocD4Ev(this, deleteFlags)
  void *this;
  uint deleteFlags;
{
  *(int *)this = DAT_a7b7c03c + 8;
  ((int (*)())__ZNSt9exceptionD2Ev)(this);
  if ((deleteFlags & 1) != 0) {
    __ZdlPv(this);
  }
  return;
}

/* ___cxa_allocate_exception_97c1913c @ 0x97c1913c (220 bytes) */
int ___cxa_allocate_exception_97c1913c(thrownSize)
  int thrownSize;
{
  bool allocFailed;
  uint emergencyBits;
  undefined *exceptionBlock;
  uint loopIndex;
  
  exceptionBlock = (undefined *)_malloc(thrownSize + 0x50U);
  if (exceptionBlock == (undefined *)0x0) {
    _pthread_mutex_lock(&_emergency_mutex);
    loopIndex = 0;
    allocFailed = true;
    emergencyBits = _emergency_used;
    if (thrownSize + 0x50U < 0x101) {
      do {
        if ((emergencyBits & 1) == 0) {
          _emergency_used = _emergency_used | 1 << (loopIndex & 0x3f);
          exceptionBlock = &_emergency_buffer + loopIndex * 0x100;
          allocFailed = exceptionBlock == (undefined *)0x0;
          break;
        }
        loopIndex = loopIndex + 1;
        emergencyBits = emergencyBits >> 1;
      } while (loopIndex < 2);
    }
    _pthread_mutex_unlock(&_emergency_mutex);
    if (allocFailed) {
      ((int (*)())std__terminate)();
    }
  }
  _memset(exceptionBlock,0,0x50);
  return exceptionBlock + 0x50;
}

/* ___cxa_free_exception @ 0x97c19218 (152 bytes) */
int ___cxa_free_exception(thrownObject)
  undefined4 *thrownObject;
{
  uint emergencySlot;
  
  if (((undefined4 *)0xa7b7e86f < thrownObject) && (thrownObject < &_emergency_used)) {
    _pthread_mutex_lock(&_emergency_mutex);
    emergencySlot = (uint)(thrownObject + 0x161205e4) >> 8 & 0x1f;
    _emergency_used = _emergency_used & (-2 << emergencySlot | 0xfffffffeU >> 0x20 - emergencySlot);
    _pthread_mutex_unlock(&_emergency_mutex);
    return;
  }
  return _free(thrownObject + -0x14);
}

/* __gxx_exception_cleanup @ 0x97c192b0 (88 bytes) */
int __gxx_exception_cleanup(_Unwind_Reason_Code, exception)
  unsigned char _Unwind_Reason_Code;
  _Unwind_Exception *exception;
{
  _Unwind_Exception *r4Out0;
  unsigned char * header;
  
  header = &exception[-2].private_2;
  if (_URC_FOREIGN_EXCEPTION_CAUGHT < _Unwind_Reason_Code) {
    ((int (*)())__cxxabiv1____terminate)((unsigned char *)exception[-2].reserved[2]);
    exception = r4Out0;
  }
  if ((code *)header[1] != (code *)0x0) {
    (*(code *)header[1])(exception + 1);
  }
  return ((int (*)())___cxa_free_exception)(exception + 1);
}

/* ___cxa_throw @ 0x97c19308 (216 bytes) */
int ___cxa_throw(thrownObject, tinfo, dest)
  int thrownObject;
  undefined4 tinfo;
  undefined4 dest;
{
  undefined4 valueSize;
  uint encodingR3;
  int cxa_get_globalsResult;
  undefined *terminateHandlerSlot;
  undefined *unexpectedHandlerSlot;
  undefined4 terminateHandler;
  undefined4 exceptionCleanup;
  int caughtException;
  int *cxa_get_globalsResult2;
  uint format;
  
  unexpectedHandlerSlot = PTR___unexpected_handler_a7b7c18c;
  *(undefined4 *)(thrownObject + -0x50) = tinfo;
  *(undefined4 *)(thrownObject + -0x4c) = dest;
  terminateHandlerSlot = PTR___terminate_handler_a7b7c188;
  *(undefined4 *)(thrownObject + -0x48) = *(undefined4 *)unexpectedHandlerSlot;
  exceptionCleanup = DAT_a7b7c06c;
  terminateHandler = *(undefined4 *)terminateHandlerSlot;
  *(undefined4 *)(thrownObject + -0x20) = 0x474e5543;
  *(undefined4 *)(thrownObject + -0x1c) = 0x432b2b00;
  *(undefined4 *)(thrownObject + -0x18) = exceptionCleanup;
  *(undefined4 *)(thrownObject + -0x44) = terminateHandler;
  cxa_get_globalsResult = ((int (*)())___cxa_get_globals)();
  *(int *)(cxa_get_globalsResult + 4) = *(int *)(cxa_get_globalsResult + 4) + 1;
  __Unwind_RaiseException((_Unwind_Exception *)(thrownObject + -0x20));
  ((int (*)())___cxa_begin_catch)((_Unwind_Exception *)(thrownObject + -0x20));
  ((int (*)())std__terminate)();
  cxa_get_globalsResult2 = (int *)((int (*)())___cxa_get_globals)();
  caughtException = *cxa_get_globalsResult2;
  if (caughtException != 0) {
    *(int *)(caughtException + 0x14) = -*(int *)(caughtException + 0x14);
    __Unwind_RaiseException((_Unwind_Exception *)(caughtException + 0x30));
    ((int (*)())___cxa_begin_catch)((_Unwind_Exception *)(caughtException + 0x30));
  }
  encodingR3 = ((int (*)())std__terminate)();
  valueSize = 0;
  if (encodingR3 != 0xff) {
    format = encodingR3 & 7;
    valueSize = 2;
    if (format != 2) {
      if (format < 3) {
        if (format != 0) {
LAB_97c19440:
                    
          _abort();
        }
        valueSize = 4;
      }
      else {
        valueSize = 4;
        if (format != 3) {
          if (format != 4) goto LAB_97c19440;
          valueSize = 8;
        }
      }
    }
  }
  return valueSize;
}

/* __Z21size_of_encoded_valueh @ 0x97c193e0 (120 bytes) */
int __Z21size_of_encoded_valueh(encoding)
  uint encoding;
{
  uint format;
  undefined4 valueSize;
  
  valueSize = 0;
  if (encoding != 0xff) {
    format = encoding & 7;
    valueSize = 2;
    if (format != 2) {
      if (format < 3) {
        if (format != 0) {
LAB_97c19440:
                    
          _abort();
        }
        valueSize = 4;
      }
      else {
        valueSize = 4;
        if (format != 3) {
          if (format != 4) goto LAB_97c19440;
          valueSize = 8;
        }
      }
    }
  }
  return valueSize;
}

/* __Z21base_of_encoded_valuehP15_Unwind_Context @ 0x97c19458 (172 bytes) */
int __Z21base_of_encoded_valuehP15_Unwind_Context(encoding, _Unwind_Context)
  uint encoding;
  unsigned char * _Unwind_Context;
{
  unsigned char dataRelBase;
  unsigned char textRelBase;
  bool isPcrelOrAligned;
  uint application;
  unsigned char regionStart;
  
  if (encoding != 0xff) {
    application = encoding & 0x70;
    if (application == 0x20) {
      textRelBase = __Unwind_GetTextRelBase(_Unwind_Context);
      return textRelBase;
    }
    if (application < 0x21) {
      if (application == 0) {
        return 0;
      }
      isPcrelOrAligned = application == 0x10;
    }
    else {
      if (application == 0x40) {
        regionStart = ((int (*)())__Unwind_GetRegionStart)(_Unwind_Context);
        return regionStart;
      }
      if (application < 0x41) {
        if (application == 0x30) {
          dataRelBase = __Unwind_GetDataRelBase(_Unwind_Context);
          return dataRelBase;
        }
        goto LAB_97c194ec;
      }
      isPcrelOrAligned = application == 0x50;
    }
    if (!isPcrelOrAligned) {
LAB_97c194ec:
                    
      _abort();
    }
  }
  return 0;
}

/* __Z12read_uleb128PKhPj @ 0x97c19504 (48 bytes) */
int __Z12read_uleb128PKhPj(p, val)
  uchar *p;
  uint *val;
{
  byte leb128Byte;
  uint shiftForByte;
  uint shift;
  uint result;
  
  shift = 0;
  result = 0;
  do {
    leb128Byte = *p;
    p = p + 1;
    shiftForByte = shift & 0x3f;
    shift = shift + 7;
    result = result | (leb128Byte & 0x7f) << shiftForByte;
  } while ((leb128Byte & 0x80) != 0);
  *val = result;
  return p;
}

/* __Z12read_sleb128PKhPi @ 0x97c19534 (76 bytes) */
int __Z12read_sleb128PKhPi(p, val)
  uchar *p;
  int *val;
{
  byte leb128Byte;
  uint shiftForByte;
  uint shift;
  uint result;
  
  shift = 0;
  result = 0;
  do {
    leb128Byte = *p;
    p = p + 1;
    shiftForByte = shift & 0x3f;
    shift = shift + 7;
    result = result | (leb128Byte & 0x7f) << shiftForByte;
  } while ((leb128Byte & 0x80) != 0);
  if ((shift < 0x20) && ((leb128Byte & 0x40) != 0)) {
    result = result | -1 << (shift & 0x3f);
  }
  *val = result;
  return p;
}

/* __Z28read_encoded_value_with_basehjPKhPj @ 0x97c19580 (312 bytes) */
int __Z28read_encoded_value_with_basehjPKhPj(encoding, base, p, val)
  uint encoding;
  uint base;
  uchar *p;
  uint *val;
{
  uint *next;
  uint *utmp;
  uint *result [6];
  
  if (encoding == 0x50) {
    result[0] = (uint *)((uint)(p + 3) & 0xfffffffc);
    next = result[0] + 1;
    goto LAB_97c196cc;
  }
  switch(encoding & 0xf) {
  case 0:
  case 3:
  case 0xb:
    result[0] = *(uint **)p;
    next = (uint *)(p + 4);
    break;
  case 1:
    next = (uint *)((int (*)())__Z12read_uleb128PKhPj)(p,(uint *)&utmp);
    result[0] = utmp;
    break;
  case 2:
    result[0] = (uint *)(uint)*(ushort *)p;
    goto LAB_97c19658;
  case 4:
  case 0xc:
    next = (uint *)(p + 8);
    result[0] = (uint *)((uint)p[7] |
                          (uint)p[6] << 8 |
                          (uint)p[5] << 0x10 | (uint)p[4] << 0x18);
    break;
  default:
                    
    _abort();
  case 9:
    next = (uint *)((int (*)())__Z12read_sleb128PKhPi)(p,(int *)result);
    break;
  case 10:
    result[0] = (uint *)(int)*(short *)p;
LAB_97c19658:
    next = (uint *)(p + 2);
  }
  if (result[0] != (uint *)0x0) {
    if ((encoding & 0x70) == 0x10) {
      base = (uint)p;
    }
    result[0] = (uint *)((int)result[0] + base);
    if ((encoding & 0x80) != 0) {
LAB_97c196cc:
      result[0] = (uint *)*result[0];
    }
  }
  *val = (uint)result[0];
  return next;
}

/* parse_lsda_header @ 0x97c196ec (216 bytes) */
int parse_lsda_header(context, p, info)
  unsigned char * context;
  uchar *p;
  unsigned char * info;
{
  unsigned char * ttypeTable;
  unsigned char regionStart;
  uint lpStartBase;
  int callSiteTable;
  uint lpStartEncoding;
  unsigned char * lsdaCursor;
  unsigned char * afterEncodingByte;
  uint tmp [7];
  
  if (context == (unsigned char *)0x0) {
    regionStart = 0;
  }
  else {
    regionStart = ((int (*)())__Unwind_GetRegionStart)(context);
  }
  *(unsigned char *)info = regionStart;
  lpStartEncoding = (uint)*p;
  lsdaCursor = (unsigned char *)(p + 1);
  if (lpStartEncoding == 0xff) {
    *(unsigned char *)(info + 4) = regionStart;
  }
  else {
    lpStartBase = ((int (*)())__Z21base_of_encoded_valuehP15_Unwind_Context)(lpStartEncoding,context);
    lsdaCursor = (unsigned char *)
             ((int (*)())__Z28read_encoded_value_with_basehjPKhPj)(lpStartEncoding,lpStartBase,(uchar *)lsdaCursor,(uint *)(info + 4));
  }
  afterEncodingByte = lsdaCursor + 1;
  info[0x14] = *lsdaCursor;
  ttypeTable = (unsigned char *)0x0;
  if (info[0x14] != 0xff) {
    afterEncodingByte = (unsigned char *)((int (*)())__Z12read_uleb128PKhPj)((uchar *)afterEncodingByte,tmp);
    ttypeTable = afterEncodingByte + tmp[0];
  }
  *(unsigned char **)(info + 0xc) = ttypeTable;
  info[0x15] = *afterEncodingByte;
  callSiteTable = ((int (*)())__Z12read_uleb128PKhPj)((uchar *)(afterEncodingByte + 1),tmp);
  *(uint *)(info + 0x10) = callSiteTable + tmp[0];
  return callSiteTable;
}

/* __Z15get_ttype_entryP16lsda_header_infoj @ 0x97c197c4 (84 bytes) */
int __Z15get_ttype_entryP16lsda_header_infoj(info, i)
  unsigned char * info;
  uint i;
{
  int entrySize;
  uint entry [4];
  
  entrySize = ((int (*)())__Z21size_of_encoded_valueh)((uint)(byte)info[0x14]);
  ((int (*)())__Z28read_encoded_value_with_basehjPKhPj)((uint)(byte)info[0x14],*(uint *)(info + 8),
             (uchar *)(*(int *)(info + 0xc) - i * entrySize),entry);
  return entry[0];
}

/* get_adjusted_ptr @ 0x97c19818 (152 bytes) */
int get_adjusted_ptr(catchType, throwType, thrownPtrP)
  unsigned char * catchType;
  unsigned char * throwType;
  void **thrownPtrP;
{
  int throwIsPointer;
  undefined4 *thrownPtr [4];
  
  thrownPtr[0] = *thrownPtrP;
  throwIsPointer = (**(code **)(*(int *)throwType + 8))(throwType,throwType,thrownPtrP);
  if (throwIsPointer != 0) {
    thrownPtr[0] = (undefined4 *)*thrownPtr[0];
  }
  throwIsPointer = (**(code **)(*(int *)catchType + 0x10))(catchType,throwType,thrownPtr,1);
  if (throwIsPointer != 0) {
    *thrownPtrP = thrownPtr[0];
  }
  return throwIsPointer != 0;
}

/* check_exception_spec @ 0x97c198b0 (124 bytes) */
int check_exception_spec(info, throwType, thrownPtr, filterValue)
  unsigned char * info;
  unsigned char * throwType;
  void *thrownPtr;
  int filterValue;
{
  unsigned int ghidra_home[8] = { info, throwType, thrownPtr, filterValue, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  unsigned char * catchType;
  int adjusted;
  uchar *specCursor;
  uint tmp [4];
  
  specCursor = (uchar *)((*(int *)(info + 0xc) - filterValue) + -1);
  (*(void * *)((unsigned char *)ghidra_home + 8)) = thrownPtr;
  do {
    specCursor = (uchar *)((int (*)())__Z12read_uleb128PKhPj)(specCursor,tmp);
    if (tmp[0] == 0) {
      return 0;
    }
    catchType = (unsigned char *)((int (*)())__Z15get_ttype_entryP16lsda_header_infoj)(info,tmp[0]);
    adjusted = ((int (*)())get_adjusted_ptr)(catchType,throwType,&(*(unsigned int *)((unsigned char *)ghidra_home + 8)));
  } while (adjusted == 0);
  return 1;
}

/* ___gxx_personality_v0 @ 0x97c1992c (976 bytes) */
int ___gxx_personality_v0(version, actions, exceptionClassLo, exceptionClassHi, ueHeader, context)
  int version;
  uint actions;
  int exceptionClassLo;
  int exceptionClassHi;
  unsigned char ueHeader;
  unsigned char * context;
{
  bool sawCleanup;
  uint handlerTest;
  uint foundType;
  bool foundTerminate;
  uchar *languageSpecificData;
  uchar *p;
  unsigned char iP;
  uint callSiteBase;
  uchar *pAfterCallSite;
  unsigned char * catchType;
  int adjustedOk;
  undefined4 reloadedTTypeBase;
  unsigned char landingPad;
  unsigned char handlerSwitchValue;
  uchar *actionRecord;
  unsigned char * throwType;
  uint callSiteEncoding;
  int infoStart;
  int infoLPStart;
  undefined4 infoTTypeBase;
  uchar *infoActionTable;
  byte infoTTypeEncoding;
  byte infoCallSiteEncoding;
  uint csStart;
  uint csLen;
  uint csLandingPad;
  uint csAction;
  uint arFilter;
  int arDisp;
  void *thrownPtr [2];
  
  thrownPtr[0] = (void *)(ueHeader + 0x20);
  if (version != 1) {
    return 3;
  }
  if (((actions == 6) && (exceptionClassLo == 0x474e5543)) && (exceptionClassHi == 0x432b2b00)) {
    landingPad = *(unsigned char *)(ueHeader - 0xc);
    handlerSwitchValue = *(unsigned char *)(ueHeader - 0x18);
    foundTerminate = landingPad == 0;
    goto LAB_97c19c74;
  }
  languageSpecificData = (uchar *)((int (*)())__Unwind_GetLanguageSpecificData)(context);
  if (languageSpecificData == (uchar *)0x0) {
    return 8;
  }
  landingPad = 0;
  p = (uchar *)((int (*)())parse_lsda_header)(context,languageSpecificData,(unsigned char *)&infoStart);
  actionRecord = (uchar *)0x0;
  handlerSwitchValue = 0;
  infoTTypeBase = ((int (*)())__Z21base_of_encoded_valuehP15_Unwind_Context)((uint)infoTTypeEncoding,context);
  iP = __Unwind_GetIP(context);
  if (p < infoActionTable) {
    do {
      callSiteEncoding = (uint)infoCallSiteEncoding;
      callSiteBase = ((int (*)())__Z21base_of_encoded_valuehP15_Unwind_Context)(callSiteEncoding,(unsigned char *)0x0);
      p = (uchar *)((int (*)())__Z28read_encoded_value_with_basehjPKhPj)(callSiteEncoding,callSiteBase,p,&csStart);
      callSiteEncoding = (uint)infoCallSiteEncoding;
      callSiteBase = ((int (*)())__Z21base_of_encoded_valuehP15_Unwind_Context)(callSiteEncoding,(unsigned char *)0x0);
      p = (uchar *)((int (*)())__Z28read_encoded_value_with_basehjPKhPj)(callSiteEncoding,callSiteBase,p,&csLen);
      callSiteEncoding = (uint)infoCallSiteEncoding;
      callSiteBase = ((int (*)())__Z21base_of_encoded_valuehP15_Unwind_Context)(callSiteEncoding,(unsigned char *)0x0);
      p = (uchar *)((int (*)())__Z28read_encoded_value_with_basehjPKhPj)(callSiteEncoding,callSiteBase,p,&csLandingPad);
      pAfterCallSite = (uchar *)((int (*)())__Z12read_uleb128PKhPj)(p,&csAction);
      p = infoActionTable;
      if ((infoStart + csStart <= iP - 1) &&
         (p = pAfterCallSite, iP - 1 < infoStart + csStart + csLen)) {
        if (csLandingPad != 0) {
          landingPad = infoLPStart + csLandingPad;
        }
        if (csAction != 0) {
          actionRecord = infoActionTable + (csAction - 1);
        }
        if (landingPad == 0) {
          return 8;
        }
        foundType = 2;
        if (actionRecord == (uchar *)0x0) goto LAB_97c19c1c;
        sawCleanup = false;
        if ((((actions & 8) == 0) && (exceptionClassLo == 0x474e5543)) && (exceptionClassHi == 0x432b2b00)) {
          throwType = *(unsigned char **)(ueHeader - 0x30);
        }
        else {
          throwType = (unsigned char *)0x0;
        }
        goto LAB_97c19b58;
      }
    } while (p < infoActionTable);
  }
  foundType = (actions ^ 8) >> 3 & 1;
LAB_97c19c0c:
  if (foundType == 0) {
    return 8;
  }
LAB_97c19c1c:
  foundTerminate = foundType == 1;
  if ((actions & 1) != 0) {
    if (foundType != 2) {
      if ((exceptionClassLo == 0x474e5543) && (exceptionClassHi == 0x432b2b00)) {
        *(unsigned char *)(ueHeader - 0xc) = landingPad;
        *(unsigned char *)(ueHeader - 0x18) = handlerSwitchValue;
        *(uchar **)(ueHeader - 0x14) = actionRecord;
        *(uchar **)(ueHeader - 0x10) = languageSpecificData;
        *(void **)(ueHeader - 8) = thrownPtr[0];
      }
      return 6;
    }
    return 8;
  }
LAB_97c19c74:
  if (foundTerminate) {
    ((int (*)())___cxa_begin_catch)(ueHeader);
    ((int (*)())__cxxabiv1____terminate)(*(unsigned char **)(ueHeader - 0x24));
  }
  if ((int)handlerSwitchValue < 0) {
    ((int (*)())parse_lsda_header)(context,*(uchar **)(ueHeader - 0x10),(unsigned char *)&infoStart);
    reloadedTTypeBase = ((int (*)())__Z21base_of_encoded_valuehP15_Unwind_Context)((uint)infoTTypeEncoding,context);
    *(undefined4 *)(ueHeader - 0xc) = reloadedTTypeBase;
  }
  __Unwind_SetGR(context,3,ueHeader);
  __Unwind_SetGR(context,4,handlerSwitchValue);
  __Unwind_SetIP(context,landingPad);
  return 7;
LAB_97c19b58:
  p = (uchar *)((int (*)())__Z12read_sleb128PKhPi)(actionRecord,(int *)&arFilter);
  ((int (*)())__Z12read_sleb128PKhPi)(p,&arDisp);
  if (arFilter == 0) {
    sawCleanup = true;
  }
  else {
    if (0 < (int)arFilter) {
      catchType = (unsigned char *)
               ((int (*)())__Z15get_ttype_entryP16lsda_header_infoj)((unsigned char *)&infoStart,arFilter);
      handlerTest = actions & 8;
      if (catchType == (unsigned char *)0x0) goto joined_r0x97c19bd8;
      if ((throwType == (unsigned char *)0x0) ||
         (adjustedOk = ((int (*)())get_adjusted_ptr)(catchType,throwType,thrownPtr), adjustedOk == 0)) goto LAB_97c19bdc;
LAB_97c19bf0:
      foundType = 3;
      handlerSwitchValue = arFilter;
      goto LAB_97c19c1c;
    }
    if (throwType != (unsigned char *)0x0) {
      handlerTest = ((int (*)())check_exception_spec)((unsigned char *)&infoStart,throwType,thrownPtr[0],arFilter);
joined_r0x97c19bd8:
      if (handlerTest == 0) goto LAB_97c19bf0;
    }
  }
LAB_97c19bdc:
  if (arDisp == 0) goto LAB_97c19bfc;
  actionRecord = p + arDisp;
  goto LAB_97c19b58;
LAB_97c19bfc:
  foundType = 2;
  if (!sawCleanup) {
    foundType = 0;
    goto LAB_97c19c0c;
  }
  goto LAB_97c19c1c;
}

/* ___cxa_call_unexpected_97c19d00 @ 0x97c19d00 (232 bytes) */
int ___cxa_call_unexpected_97c19d00(excObj)
  int excObj;
{
  undefined4 *badException;
  undefined4 __terminateResult;
  undefined4 *cxa_get_globals_fastResult;
  undefined *badExceptionDtor;
  undefined *badExceptionTypeinfo;
  undefined4 __unexpectedResult;
  undefined4 *currentException;
  int check_exception_specResult;
  code *r3Out0;
  unsigned char * terminateHandler;
  int handlerSwitchValue;
  uchar *languageSpecificData;
  unsigned char lsdaHeader [8];
  undefined4 savedTTypeBase;
  
  ((int (*)())___cxa_begin_catch)(excObj);
  savedTTypeBase = *(undefined4 *)(excObj + -0xc);
  languageSpecificData = *(uchar **)(excObj + -0x10);
  handlerSwitchValue = *(int *)(excObj + -0x18);
  terminateHandler = *(unsigned char **)(excObj + -0x24);
  __unexpectedResult = ((int (*)())__cxxabiv1____unexpected)(*(unsigned char **)(excObj + -0x28));
  ((int (*)())___cxa_begin_catch)(__unexpectedResult);
  cxa_get_globals_fastResult = (undefined4 *)((int (*)())___cxa_get_globals_fast)();
  currentException = (undefined4 *)*cxa_get_globals_fastResult;
  ((int (*)())parse_lsda_header)((unsigned char *)0x0,languageSpecificData,lsdaHeader);
  check_exception_specResult = ((int (*)())check_exception_spec)(lsdaHeader,(unsigned char *)*currentException,currentException + 0x14,handlerSwitchValue);
  if (check_exception_specResult != 0) {
    ___cxa_rethrow();
  }
  badExceptionTypeinfo = PTR_typeinfo_a7b7c180;
  check_exception_specResult = ((int (*)())check_exception_spec)(lsdaHeader,(unsigned char *)PTR_typeinfo_a7b7c180,(void *)0x0,handlerSwitchValue);
  if (check_exception_specResult != 0) {
    badException = (undefined4 *)___cxa_allocate_exception(4);
    badExceptionDtor = PTR___ZNSt13bad_exceptionD1Ev_a7b7c17c;
    *badException = PTR_vtable_a7b7c184 + 8;
                    
    ((int (*)())___cxa_throw)(badException,badExceptionTypeinfo,badExceptionDtor);
  }
  __terminateResult = ((int (*)())__cxxabiv1____terminate)(terminateHandler);
  ((int (*)())___cxa_end_catch)();
  ((int (*)())___cxa_end_catch)();
  __Unwind_Resume(__terminateResult);
  (*r3Out0)();
                    
  _abort();
}

/* __cxxabiv1____terminate @ 0x97c19de8 (28 bytes) */
int __cxxabiv1____terminate(handler)
  unsigned char * handler;
{
  ((int (*)())handler)(handler);
                    
  _abort();
}

/* std__terminate @ 0x97c19e0c (56 bytes) */
int std__terminate()
{
  unsigned char * threadTerminateHandler;
  
  threadTerminateHandler = (unsigned char *)__keymgr_get_per_thread_data(4);
  if (threadTerminateHandler != (unsigned char *)0x0) {
    __cxxabiv1____terminate_handler = threadTerminateHandler;
  }
                    
  ((int (*)())__cxxabiv1____terminate)(__cxxabiv1____terminate_handler);
}

/* __cxxabiv1____unexpected @ 0x97c19e44 (28 bytes) */
int __cxxabiv1____unexpected(handler)
  unsigned char * handler;
{
  unsigned char * threadUnexpectedHandler;
  undefined4 newTerminateHandler;
  int oldTerminateHandler;
  
  ((int (*)())handler)(handler);
  ((int (*)())std__terminate)();
  threadUnexpectedHandler = (unsigned char *)__keymgr_get_per_thread_data(3);
  if (threadUnexpectedHandler != (unsigned char *)0x0) {
    __unexpected_handler = threadUnexpectedHandler;
  }
  newTerminateHandler = ((int (*)())__cxxabiv1____unexpected)(__unexpected_handler);
  oldTerminateHandler = __keymgr_get_per_thread_data(4);
  __keymgr_set_per_thread_data(4,newTerminateHandler);
  if (oldTerminateHandler == 0) {
    oldTerminateHandler = __terminate_handler;
  }
  __terminate_handler = newTerminateHandler;
  return oldTerminateHandler;
}

/* std__unexpected @ 0x97c19e60 (56 bytes) */
int std__unexpected()
{
  unsigned char * threadUnexpectedHandler;
  undefined4 newTerminateHandler;
  int oldTerminateHandler;
  
  threadUnexpectedHandler = (unsigned char *)__keymgr_get_per_thread_data(3);
  if (threadUnexpectedHandler != (unsigned char *)0x0) {
    __cxxabiv1____unexpected_handler = threadUnexpectedHandler;
  }
  newTerminateHandler = ((int (*)())__cxxabiv1____unexpected)(__cxxabiv1____unexpected_handler);
  oldTerminateHandler = __keymgr_get_per_thread_data(4);
  __keymgr_set_per_thread_data(4,newTerminateHandler);
  if (oldTerminateHandler == 0) {
    oldTerminateHandler = __cxxabiv1____terminate_handler;
  }
  __cxxabiv1____terminate_handler = newTerminateHandler;
  return oldTerminateHandler;
}

/* std__set_terminate @ 0x97c19e98 (72 bytes) */
int std__set_terminate(newHandler)
  unsigned char * newHandler;
{
  int oldHandler;
  
  oldHandler = __keymgr_get_per_thread_data(4);
  __keymgr_set_per_thread_data(4,newHandler);
  if (oldHandler == 0) {
    oldHandler = (int)__cxxabiv1____terminate_handler;
  }
  __cxxabiv1____terminate_handler = newHandler;
  return oldHandler;
}

/* std__set_unexpected @ 0x97c19f0c (72 bytes) */
int std__set_unexpected(newHandler)
  unsigned char * newHandler;
{
  int oldHandler;
  
  oldHandler = __keymgr_get_per_thread_data(3);
  __keymgr_set_per_thread_data(3,newHandler);
  if (oldHandler == 0) {
    oldHandler = (int)__cxxabiv1____unexpected_handler;
  }
  __cxxabiv1____unexpected_handler = newHandler;
  return oldHandler;
}

/* ___cxa_begin_catch @ 0x97c19f80 (108 bytes) */
int ___cxa_begin_catch(exceptionObject)
  int exceptionObject;
{
  int oldCaughtExceptions;
  int handlerCount;
  int *cxa_get_globalsResult;
  
  cxa_get_globalsResult = (int *)((int (*)())___cxa_get_globals)();
  handlerCount = *(int *)(exceptionObject + -0x1c);
  oldCaughtExceptions = *cxa_get_globalsResult;
  if (handlerCount < 0) {
    handlerCount = -handlerCount;
  }
  *(int *)(exceptionObject + -0x1c) = handlerCount + 1;
  cxa_get_globalsResult[1] = cxa_get_globalsResult[1] + -1;
  if (exceptionObject + -0x30 != oldCaughtExceptions) {
    *(int *)(exceptionObject + -0x20) = oldCaughtExceptions;
    *cxa_get_globalsResult = exceptionObject + -0x30;
  }
  return *(undefined4 *)(exceptionObject + -8);
}

/* ___cxa_end_catch @ 0x97c19fec (144 bytes) */
int ___cxa_end_catch()
{
  int *cxa_get_globals_fastResult;
  int header;
  undefined4 r3AfterDelete;
  int handlerCount;
  
  cxa_get_globals_fastResult = (int *)((int (*)())___cxa_get_globals_fast)();
  header = *cxa_get_globals_fastResult;
  handlerCount = *(int *)(header + 0x14);
  if (handlerCount < 0) {
    handlerCount = handlerCount + 1;
    if (handlerCount == 0) {
      cxa_get_globals_fastResult[1] = cxa_get_globals_fastResult[1] + 1;
      *cxa_get_globals_fastResult = *(int *)(header + 0x10);
    }
  }
  else {
    handlerCount = handlerCount + -1;
    if (handlerCount == 0) {
      *cxa_get_globals_fastResult = *(int *)(header + 0x10);
      __Unwind_DeleteException((_Unwind_Exception *)(header + 0x30));
      return r3AfterDelete;
    }
    if (handlerCount < 0) {
                    
      _abort();
    }
  }
  *(int *)(header + 0x14) = handlerCount;
  return header;
}

/* __ZSt18uncaught_exceptionv @ 0x97c1a07c (44 bytes) */
int __ZSt18uncaught_exceptionv()
{
  int cxa_get_globalsResult;
  
  cxa_get_globalsResult = ((int (*)())___cxa_get_globals)();
  return *(int *)(cxa_get_globalsResult + 4) != 0;
}

/* __Z21get_globals_init_oncev @ 0x97c1a0a8 (32 bytes) */
int __Z21get_globals_init_oncev()
{
  _use_thread_key = 1;
  return;
}

/* ___cxa_get_globals_fast @ 0x97c1a0c8 (52 bytes) */
int ___cxa_get_globals_fast()
{
  undefined4 keymgr_get_per_thread_dataResult;
  
  if (_use_thread_key != 0) {
    keymgr_get_per_thread_dataResult = __keymgr_get_per_thread_data(0xd);
    return keymgr_get_per_thread_dataResult;
  }
  return &_globals_static;
}

/* ___cxa_get_globals @ 0x97c1a0fc (220 bytes) */
int ___cxa_get_globals()
{
  int keymgr_set_per_thread_dataResult;
  int keymgr_get_per_thread_dataResult;
  undefined4 *allocation;
  
  if ((_use_thread_key == 0) ||
     ((_use_thread_key < 0 && (((int (*)())__Z21get_globals_init_oncev)(), _use_thread_key == 0)))) {
    return (undefined4 *)&_globals_static;
  }
  keymgr_get_per_thread_dataResult = __keymgr_get_per_thread_data(0xd);
  if (keymgr_get_per_thread_dataResult != 0) {
    return (undefined4 *)keymgr_get_per_thread_dataResult;
  }
  allocation = (undefined4 *)_malloc(8);
  if (allocation != (undefined4 *)0x0) {
    if ((*(int *)(PTR_DAT_a7b7c190 + 8) == 0) ||
       (*(ushort *)(*(int *)(PTR_DAT_a7b7c190 + 8) + 4) < 4)) {
      __keymgr_set_per_thread_data(0xd,allocation);
      goto LAB_97c1a1b4;
    }
    keymgr_set_per_thread_dataResult = __keymgr_set_per_thread_data(0xd,allocation);
    if (keymgr_set_per_thread_dataResult == 0) goto LAB_97c1a1b4;
  }
  ((int (*)())std__terminate)();
LAB_97c1a1b4:
  allocation[1] = 0;
  *allocation = 0;
  return allocation;
}

/* ___eprintf @ 0x97c1a1d8 (76 bytes) */
int ___eprintf(format, arg1, arg2, arg3)
  char *format;
  undefined4 arg1;
  undefined4 arg2;
  undefined4 arg3;
{
  undefined *stderrBase;
  
  stderrBase = PTR_DAT_a7b7c0bc;
  _fprintf((FILE *)(PTR_DAT_a7b7c0bc + 0xb0),format,arg1,arg2,arg3);
  _fflush(stderrBase + 0xb0);
                    
  _abort();
}

/* FUN_97c1a23c @ 0x97c1a23c (16 bytes) */
int FUN_97c1a23c()
{
  undefined4 r3In;
  
  return r3In;
}

/* FUN_97c1a24c @ 0x97c1a24c (12 bytes) */
int FUN_97c1a24c()
{
  return;
}

/* FUN_97c1a258 @ 0x97c1a258 (4 bytes) */
int FUN_97c1a258()
{
  return;
}

/* FUN_97c1a25c @ 0x97c1a25c (24 bytes) */
int FUN_97c1a25c()
{
  undefined4 r3In;
  
  return r3In;
}

/* FUN_97c1a28c @ 0x97c1a28c (60 bytes) */
int FUN_97c1a28c()
{
  return;
}

/* _size_of_encoded_value_97c1a2c8 @ 0x97c1a2c8 (120 bytes) */
int _size_of_encoded_value_97c1a2c8(encoding)
  uint encoding;
{
  uint format;
  undefined4 valueSize;
  
  valueSize = 0;
  if (encoding != 0xff) {
    format = encoding & 7;
    valueSize = 2;
    if (format != 2) {
      if (format < 3) {
        if (format != 0) {
LAB_97c1a328:
                    
          _abort();
        }
        valueSize = 4;
      }
      else {
        valueSize = 4;
        if (format != 3) {
          if (format != 4) goto LAB_97c1a328;
          valueSize = 8;
        }
      }
    }
  }
  return valueSize;
}

/* _base_of_encoded_value @ 0x97c1a340 (172 bytes) */
int _base_of_encoded_value(encoding, context)
  uint encoding;
  unsigned char * context;
{
  unsigned char dataRelBase;
  unsigned char textRelBase;
  bool isPcrelOrAligned;
  uint application;
  unsigned char regionStart;
  
  if (encoding != 0xff) {
    application = encoding & 0x70;
    if (application == 0x20) {
      textRelBase = __Unwind_GetTextRelBase(context);
      return textRelBase;
    }
    if (application < 0x21) {
      if (application == 0) {
        return 0;
      }
      isPcrelOrAligned = application == 0x10;
    }
    else {
      if (application == 0x40) {
        regionStart = ((int (*)())__Unwind_GetRegionStart)(context);
        return regionStart;
      }
      if (application < 0x41) {
        if (application == 0x30) {
          dataRelBase = __Unwind_GetDataRelBase(context);
          return dataRelBase;
        }
        goto LAB_97c1a3d4;
      }
      isPcrelOrAligned = application == 0x50;
    }
    if (!isPcrelOrAligned) {
LAB_97c1a3d4:
                    
      _abort();
    }
  }
  return 0;
}

/* _read_uleb128_97c1a3ec @ 0x97c1a3ec (48 bytes) */
int _read_uleb128_97c1a3ec(p, val)
  byte *p;
  uint *val;
{
  byte leb128Byte;
  uint shiftForByte;
  uint shift;
  uint result;
  
  shift = 0;
  result = 0;
  do {
    leb128Byte = *p;
    p = p + 1;
    shiftForByte = shift & 0x3f;
    shift = shift + 7;
    result = result | (leb128Byte & 0x7f) << shiftForByte;
  } while ((leb128Byte & 0x80) != 0);
  *val = result;
  return p;
}

/* _read_sleb128_97c1a41c @ 0x97c1a41c (76 bytes) */
int _read_sleb128_97c1a41c(p, val)
  byte *p;
  uint *val;
{
  byte leb128Byte;
  uint shiftForByte;
  uint shift;
  uint result;
  
  shift = 0;
  result = 0;
  do {
    leb128Byte = *p;
    p = p + 1;
    shiftForByte = shift & 0x3f;
    shift = shift + 7;
    result = result | (leb128Byte & 0x7f) << shiftForByte;
  } while ((leb128Byte & 0x80) != 0);
  if ((shift < 0x20) && ((leb128Byte & 0x40) != 0)) {
    result = result | -1 << (shift & 0x3f);
  }
  *val = result;
  return p;
}

/* _read_encoded_value_with_base_97c1a468 @ 0x97c1a468 (312 bytes) */
int _read_encoded_value_with_base_97c1a468(encoding, base, p, val)
  uint encoding;
  uint *base;
  uint *p;
  uint *val;
{
  uint *next;
  uint *utmp;
  uint *result [6];
  
  if (encoding == 0x50) {
    result[0] = (uint *)((int)p + 3U & 0xfffffffc);
    next = result[0] + 1;
    goto LAB_97c1a5b4;
  }
  switch(encoding & 0xf) {
  case 0:
  case 3:
  case 0xb:
    result[0] = (uint *)*p;
    next = p + 1;
    break;
  case 1:
    next = (uint *)((int (*)())_read_uleb128_97c1a3ec)(p,&utmp);
    result[0] = utmp;
    break;
  case 2:
    result[0] = (uint *)(uint)*(ushort *)p;
    goto LAB_97c1a540;
  case 4:
  case 0xc:
    next = p + 2;
    result[0] = (uint *)((uint)*(byte *)((int)p + 7) |
                          (uint)*(byte *)((int)p + 6) << 8 |
                          (uint)*(byte *)((int)p + 5) << 0x10 |
                          (uint)*(byte *)(p + 1) << 0x18);
    break;
  default:
                    
    _abort();
  case 9:
    next = (uint *)((int (*)())_read_sleb128_97c1a41c)(p,result);
    break;
  case 10:
    result[0] = (uint *)(int)(short)*(ushort *)p;
LAB_97c1a540:
    next = (uint *)((int)p + 2);
  }
  if (result[0] != (uint *)0x0) {
    if ((encoding & 0x70) == 0x10) {
      base = p;
    }
    result[0] = (uint *)((int)result[0] + (int)base);
    if ((encoding & 0x80) != 0) {
LAB_97c1a5b4:
      result[0] = (uint *)*result[0];
    }
  }
  *val = (uint)result[0];
  return next;
}

/* __Unwind_GetLanguageSpecificData @ 0x97c1a5d4 (8 bytes) */
int __Unwind_GetLanguageSpecificData(context)
  unsigned char * context;
{
  return *(unsigned char *)(context + 0x1c4);
}

/* __Unwind_GetRegionStart @ 0x97c1a5dc (8 bytes) */
int __Unwind_GetRegionStart(context)
  unsigned char * context;
{
  return *(unsigned char *)(context + 0x1d0);
}

