#include "decls.h"

/* __ZNK10__cxxabiv120__si_class_type_info12__do_dyncastEiNS_17__class_type_info10__sub_kindEPKS1_PKvS4_S6_RNS1_16__dyncast_resultE @ 0x97c185fc (244 bytes) */
int __ZNK10__cxxabiv120__si_class_type_info12__do_dyncastEiNS_17__class_type_info10__sub_kindEPKS1_PKvS4_S6_RNS1_16__dyncast_resultE(this, param_2, __sub_kind, __class_type_info1, param_5, __class_type_info2, param_7, __dyncast_result)
  void *this;
  int param_2;
  int __sub_kind;
  unsigned char * __class_type_info1;
  int param_5;
  unsigned char * __class_type_info2;
  int param_7;
  int *__dyncast_result;
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = __ZNKSt9type_infoeqERKS_(this,__class_type_info1);
  if (iVar1 == 0) {
    if ((param_5 == param_7) && (iVar1 = __ZNKSt9type_infoeqERKS_(this,__class_type_info2), iVar1 != 0)) {
      __dyncast_result[2] = __sub_kind;
      return 0;
    }
                    
                    
    uVar2 = (**(code **)(**(int **)((int)this + 8) + 0x1c))
                      (*(int **)((int)this + 8),param_2,__sub_kind,__class_type_info1,param_5,__class_type_info2,param_7,
                       __dyncast_result);
    return uVar2;
  }
  __dyncast_result[1] = __sub_kind;
  *__dyncast_result = param_5;
  if (param_2 < 0) {
    if (param_2 != -2) {
      return 0;
    }
  }
  else {
    iVar1 = 6;
    if (param_5 + param_2 == param_7) goto LAB_97c1866c;
  }
  iVar1 = 1;
LAB_97c1866c:
  __dyncast_result[3] = iVar1;
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
int __ZNK10__cxxabiv117__class_type_info11__do_upcastEPKS0_PKvRNS0_15__upcast_resultE(this, __class_type_info, param_3, __upcast_result)
  void *this;
  unsigned char * __class_type_info;
  void *param_3;
  unsigned char * __upcast_result;
{
  int iVar1;
  
  iVar1 = __ZNKSt9type_infoeqERKS_(this,(unsigned char *)__class_type_info);
  if (iVar1 != 0) {
    *(void **)__upcast_result = param_3;
    *(undefined4 *)(__upcast_result + 4) = 6;
    *(undefined4 *)(__upcast_result + 0xc) = 8;
  }
  return iVar1 != 0;
}

/* __ZNK10__cxxabiv120__si_class_type_info11__do_upcastEPKNS_17__class_type_infoEPKvRNS1_15__upcast_resultE @ 0x97c18b88 (116 bytes) */
int __ZNK10__cxxabiv120__si_class_type_info11__do_upcastEPKNS_17__class_type_infoEPKvRNS1_15__upcast_resultE(this, __class_type_info, param_3, __upcast_result)
  void *this;
  unsigned char * __class_type_info;
  void *param_3;
  unsigned char * __upcast_result;
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = ((int (*)())__ZNK10__cxxabiv117__class_type_info11__do_upcastEPKS0_PKvRNS0_15__upcast_resultE)(this,__class_type_info,param_3,__upcast_result);
  if (iVar1 == 0) {
                    
                    
    uVar2 = (**(code **)(**(int **)((int)this + 8) + 0x18))
                      (*(int **)((int)this + 8),__class_type_info,param_3,__upcast_result);
    return uVar2;
  }
  return 1;
}

/* __cxxabiv1____vmi_class_type_info____do_upcast @ 0x97c18bfc (556 bytes) */
int __cxxabiv1____vmi_class_type_info____do_upcast(this, __class_type_info, param_3, __upcast_result)
  unsigned char * this;
  unsigned char * __class_type_info;
  void *param_3;
  unsigned char * __upcast_result;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  unsigned char * ptVar4;
  void *r5In0;
  uint uVar5;
  unsigned char * p_Var6;
  bool bVar7;
  int local_40;
  uint local_3c;
  uint local_38;
  void *local_34;
  
  iVar3 = ((int (*)())__ZNK10__cxxabiv117__class_type_info11__do_upcastEPKS0_PKvRNS0_15__upcast_resultE)(this,__class_type_info,param_3,__upcast_result);
  bVar7 = true;
  if (iVar3 == 0) {
    uVar5 = *(uint *)(__upcast_result + 8);
    if ((uVar5 & 0x10) != 0) {
      uVar5 = *(uint *)(this + 8);
    }
    iVar3 = *(int *)(this + 0xc) + -1;
    if (*(int *)(this + 0xc) != 0) {
      p_Var6 = this + iVar3 * 8;
      do {
        uVar1 = *(uint *)(p_Var6 + 0x14);
        local_40 = 0;
        bVar7 = (uVar1 >> 1 & 1) != 0;
        local_3c = 0;
        iVar2 = (int)uVar1 >> 8;
        local_34 = (void *)0x0;
        if ((bVar7) || (((uVar5 ^ 1) & 1) == 0)) {
          r5In0 = param_3;
          if (param_3 != (void *)0x0) {
            if ((uVar1 & 1) != 0) {
              iVar2 = *(int *)(*(int *)param_3 + iVar2);
            }
            r5In0 = (void *)((int)param_3 + iVar2);
          }
          local_38 = uVar5;
          iVar2 = (**(code **)(**(int **)(p_Var6 + 0x10) + 0x18))
                            (*(int **)(p_Var6 + 0x10),__class_type_info,r5In0,&local_40);
          if (iVar2 != 0) {
            if ((local_34 == (void *)0x8) && ((uVar1 & 1) != 0)) {
              local_34 = *(void **)(p_Var6 + 0x10);
            }
            if ((3 < (int)local_3c) && (!bVar7)) {
              local_3c = local_3c & 0xfffffffd;
            }
            ptVar4 = *(unsigned char **)(__upcast_result + 0xc);
            if (ptVar4 == (unsigned char *)0x0) {
              *(uint *)(__upcast_result + 8) = local_38;
              *(int *)__upcast_result = local_40;
              *(void **)(__upcast_result + 0xc) = local_34;
              *(uint *)(__upcast_result + 4) = local_3c;
              if ((int)local_3c < 4) {
                return true;
              }
              if ((local_3c & 2) == 0) {
                if ((local_3c & 1) == 0) {
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
              if (*(int *)__upcast_result != local_40) {
                *(undefined4 *)(__upcast_result + 4) = 2;
                *(undefined4 *)__upcast_result = 0;
                return true;
              }
              if ((*(int *)__upcast_result == 0) &&
                 (((local_34 == (void *)0x8 || (ptVar4 == (unsigned char *)0x8)) ||
                  (iVar2 = __ZNKSt9type_infoeqERKS_(local_34,ptVar4), iVar2 == 0)))) {
                *(undefined4 *)(__upcast_result + 4) = 2;
                return true;
              }
              *(uint *)(__upcast_result + 4) = *(uint *)(__upcast_result + 4) | local_3c;
            }
          }
        }
        bVar7 = iVar3 != 0;
        p_Var6 = p_Var6 + -8;
        iVar3 = iVar3 + -1;
      } while (bVar7);
    }
    bVar7 = *(int *)(__upcast_result + 4) != 0;
  }
  return bVar7;
}

/* ___dynamic_cast @ 0x97c18e28 (328 bytes) */
int ___dynamic_cast(param_1, param_2, param_3, param_4)
  int *param_1;
  undefined4 param_2;
  int *param_3;
  int param_4;
{
  int *r3In0;
  uint uVar1;
  int iVar2;
  int local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  undefined4 local_30;
  
  r3In0 = *(int **)(*param_1 + -4);
  local_38 = 0;
  local_34 = 0;
  local_30 = 0x10;
  local_40 = 0;
  local_3c = 0;
  (**(code **)(*r3In0 + 0x1c))
            (r3In0,param_4,6,param_3,(int)param_1 + *(int *)(*param_1 + -8),param_2,param_1,&local_40);
  iVar2 = 0;
  if ((((local_40 != 0) && (iVar2 = local_40, (local_34 & 6) != 6)) &&
      ((local_38 & local_3c & 6) != 6)) && (iVar2 = 0, (local_38 & 5) != 4)) {
    uVar1 = local_34;
    if (local_34 == 0) {
      if (param_4 < 0) {
        uVar1 = 0;
        if (param_4 != -2) {
          uVar1 = (**(code **)(*param_3 + 0x20))(param_3,param_4,local_40,param_2,param_1);
        }
      }
      else {
        uVar1 = 6;
        if ((int *)(local_40 + param_4) != param_1) {
          uVar1 = 0;
        }
      }
    }
    iVar2 = 0;
    if ((uVar1 & 6) == 6) {
      iVar2 = local_40;
    }
  }
  return iVar2;
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
int __ZNSt9exceptionD4Ev(this, param_2)
  void *this;
  uint param_2;
{
  *(int *)this = DAT_a7b7c034 + 8;
  if ((param_2 & 1) != 0) {
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
int __ZNSt13bad_exceptionD4Ev(this, param_2)
  void *this;
  uint param_2;
{
  *(int *)this = DAT_a7b7c030 + 8;
  ((int (*)())__ZNSt9exceptionD2Ev)(this);
  if ((param_2 & 1) != 0) {
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
int std__set_new_handler(param_1)
  unsigned char * param_1;
{
  int iVar1;
  
  iVar1 = __keymgr_get_per_thread_data(2);
  if (iVar1 == 0) {
    iVar1 = (int)___new_handler;
  }
  __keymgr_set_per_thread_data(2,param_1);
  ___new_handler = param_1;
  return iVar1;
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
int __ZNSt9bad_allocD4Ev(this, param_2)
  void *this;
  uint param_2;
{
  *(int *)this = DAT_a7b7c03c + 8;
  ((int (*)())__ZNSt9exceptionD2Ev)(this);
  if ((param_2 & 1) != 0) {
    __ZdlPv(this);
  }
  return;
}

/* FUN_97c1913c @ 0x97c1913c (220 bytes) */
int FUN_97c1913c(param_1)
  int param_1;
{
  bool bVar1;
  uint uVar2;
  undefined *puVar3;
  uint loopIndex;
  
  puVar3 = (undefined *)_malloc(param_1 + 0x50U);
  if (puVar3 == (undefined *)0x0) {
    _pthread_mutex_lock(&_emergency_mutex);
    loopIndex = 0;
    bVar1 = true;
    uVar2 = _emergency_used;
    if (param_1 + 0x50U < 0x101) {
      do {
        if ((uVar2 & 1) == 0) {
          _emergency_used = _emergency_used | 1 << (loopIndex & 0x3f);
          puVar3 = &_emergency_buffer + loopIndex * 0x100;
          bVar1 = puVar3 == (undefined *)0x0;
          break;
        }
        loopIndex = loopIndex + 1;
        uVar2 = uVar2 >> 1;
      } while (loopIndex < 2);
    }
    _pthread_mutex_unlock(&_emergency_mutex);
    if (bVar1) {
      ((int (*)())std__terminate)();
    }
  }
  _memset(puVar3,0,0x50);
  return puVar3 + 0x50;
}

/* ___cxa_free_exception @ 0x97c19218 (152 bytes) */
int ___cxa_free_exception(param_1)
  undefined4 *param_1;
{
  uint uVar1;
  
  if (((undefined4 *)0xa7b7e86f < param_1) && (param_1 < &_emergency_used)) {
    _pthread_mutex_lock(&_emergency_mutex);
    uVar1 = (uint)(param_1 + 0x161205e4) >> 8 & 0x1f;
    _emergency_used = _emergency_used & (-2 << uVar1 | 0xfffffffeU >> 0x20 - uVar1);
    _pthread_mutex_unlock(&_emergency_mutex);
    return;
  }
  return _free(param_1 + -0x14);
}

/* __gxx_exception_cleanup @ 0x97c192b0 (88 bytes) */
int __gxx_exception_cleanup(_Unwind_Reason_Code, param_2)
  unsigned char _Unwind_Reason_Code;
  _Unwind_Exception *param_2;
{
  _Unwind_Exception *r4Out0;
  unsigned char * puVar1;
  
  puVar1 = &param_2[-2].private_2;
  if (_URC_FOREIGN_EXCEPTION_CAUGHT < _Unwind_Reason_Code) {
    ((int (*)())__cxxabiv1____terminate)((unsigned char *)param_2[-2].reserved[2]);
    param_2 = r4Out0;
  }
  if ((code *)puVar1[1] != (code *)0x0) {
    (*(code *)puVar1[1])(param_2 + 1);
  }
  return ((int (*)())___cxa_free_exception)(param_2 + 1);
}

/* ___cxa_throw @ 0x97c19308 (216 bytes) */
int ___cxa_throw(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  uint terminateResult;
  int cxa_get_globalsResult;
  undefined *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int *cxa_get_globalsResult2;
  uint uVar7;
  
  puVar2 = PTR___unexpected_handler_a7b7c18c;
  *(undefined4 *)(param_1 + -0x50) = param_2;
  *(undefined4 *)(param_1 + -0x4c) = param_3;
  puVar1 = PTR___terminate_handler_a7b7c188;
  *(undefined4 *)(param_1 + -0x48) = *(undefined4 *)puVar2;
  uVar4 = DAT_a7b7c06c;
  uVar3 = *(undefined4 *)puVar1;
  *(undefined4 *)(param_1 + -0x20) = 0x474e5543;
  *(undefined4 *)(param_1 + -0x1c) = 0x432b2b00;
  *(undefined4 *)(param_1 + -0x18) = uVar4;
  *(undefined4 *)(param_1 + -0x44) = uVar3;
  cxa_get_globalsResult = ((int (*)())___cxa_get_globals)();
  *(int *)(cxa_get_globalsResult + 4) = *(int *)(cxa_get_globalsResult + 4) + 1;
  __Unwind_RaiseException((_Unwind_Exception *)(param_1 + -0x20));
  ((int (*)())___cxa_begin_catch)((_Unwind_Exception *)(param_1 + -0x20));
  ((int (*)())std__terminate)();
  cxa_get_globalsResult2 = (int *)((int (*)())___cxa_get_globals)();
  iVar5 = *cxa_get_globalsResult2;
  if (iVar5 != 0) {
    *(int *)(iVar5 + 0x14) = -*(int *)(iVar5 + 0x14);
    __Unwind_RaiseException((_Unwind_Exception *)(iVar5 + 0x30));
    ((int (*)())___cxa_begin_catch)((_Unwind_Exception *)(iVar5 + 0x30));
  }
  terminateResult = ((int (*)())std__terminate)();
  uVar4 = 0;
  if (terminateResult != 0xff) {
    uVar7 = terminateResult & 7;
    uVar4 = 2;
    if (uVar7 != 2) {
      if (uVar7 < 3) {
        if (uVar7 != 0) {
LAB_97c19440:
                    
          _abort();
        }
        uVar4 = 4;
      }
      else {
        uVar4 = 4;
        if (uVar7 != 3) {
          if (uVar7 != 4) goto LAB_97c19440;
          uVar4 = 8;
        }
      }
    }
  }
  return uVar4;
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
  byte bVar1;
  uint shiftForByte;
  uint shift;
  uint result;
  
  shift = 0;
  result = 0;
  do {
    bVar1 = *p;
    p = p + 1;
    shiftForByte = shift & 0x3f;
    shift = shift + 7;
    result = result | (bVar1 & 0x7f) << shiftForByte;
  } while ((bVar1 & 0x80) != 0);
  *val = result;
  return p;
}

/* __Z12read_sleb128PKhPi @ 0x97c19534 (76 bytes) */
int __Z12read_sleb128PKhPi(p, val)
  uchar *p;
  int *val;
{
  byte bVar1;
  uint shiftForByte;
  uint shift;
  uint result;
  
  shift = 0;
  result = 0;
  do {
    bVar1 = *p;
    p = p + 1;
    shiftForByte = shift & 0x3f;
    shift = shift + 7;
    result = result | (bVar1 & 0x7f) << shiftForByte;
  } while ((bVar1 & 0x80) != 0);
  if ((shift < 0x20) && ((bVar1 & 0x40) != 0)) {
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
int parse_lsda_header(_Unwind_Context, param_2, lsda_header_info)
  unsigned char * _Unwind_Context;
  uchar *param_2;
  unsigned char * lsda_header_info;
{
  unsigned char uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  unsigned char * plVar5;
  unsigned char * plVar6;
  uint local_30 [7];
  
  if (_Unwind_Context == (unsigned char *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = ((int (*)())__Unwind_GetRegionStart)(_Unwind_Context);
  }
  *(unsigned char *)lsda_header_info = uVar1;
  uVar4 = (uint)*param_2;
  plVar5 = (unsigned char *)(param_2 + 1);
  if (uVar4 == 0xff) {
    *(unsigned char *)(lsda_header_info + 4) = uVar1;
  }
  else {
    uVar2 = ((int (*)())__Z21base_of_encoded_valuehP15_Unwind_Context)(uVar4,_Unwind_Context);
    plVar5 = (unsigned char *)
             ((int (*)())__Z28read_encoded_value_with_basehjPKhPj)(uVar4,uVar2,(uchar *)plVar5,(uint *)(lsda_header_info + 4));
  }
  plVar6 = plVar5 + 1;
  lsda_header_info[0x14] = *plVar5;
  plVar5 = (unsigned char *)0x0;
  if (lsda_header_info[0x14] != 0xff) {
    plVar6 = (unsigned char *)((int (*)())__Z12read_uleb128PKhPj)((uchar *)plVar6,local_30);
    plVar5 = plVar6 + local_30[0];
  }
  *(unsigned char **)(lsda_header_info + 0xc) = plVar5;
  lsda_header_info[0x15] = *plVar6;
  iVar3 = ((int (*)())__Z12read_uleb128PKhPj)((uchar *)(plVar6 + 1),local_30);
  *(uint *)(lsda_header_info + 0x10) = iVar3 + local_30[0];
  return iVar3;
}

/* __Z15get_ttype_entryP16lsda_header_infoj @ 0x97c197c4 (84 bytes) */
int __Z15get_ttype_entryP16lsda_header_infoj(lsda_header_info, param_2)
  unsigned char * lsda_header_info;
  uint param_2;
{
  int iVar1;
  uint local_20 [4];
  
  iVar1 = ((int (*)())__Z21size_of_encoded_valueh)((uint)(byte)lsda_header_info[0x14]);
  ((int (*)())__Z28read_encoded_value_with_basehjPKhPj)((uint)(byte)lsda_header_info[0x14],*(uint *)(lsda_header_info + 8),
             (uchar *)(*(int *)(lsda_header_info + 0xc) - param_2 * iVar1),local_20);
  return local_20[0];
}

/* get_adjusted_ptr @ 0x97c19818 (152 bytes) */
int get_adjusted_ptr(type_info1, type_info2, param_3)
  unsigned char * type_info1;
  unsigned char * type_info2;
  void **param_3;
{
  int iVar1;
  undefined4 *local_20 [4];
  
  local_20[0] = *param_3;
  iVar1 = (**(code **)(*(int *)type_info2 + 8))(type_info2,type_info2,param_3);
  if (iVar1 != 0) {
    local_20[0] = (undefined4 *)*local_20[0];
  }
  iVar1 = (**(code **)(*(int *)type_info1 + 0x10))(type_info1,type_info2,local_20,1);
  if (iVar1 != 0) {
    *param_3 = local_20[0];
  }
  return iVar1 != 0;
}

/* check_exception_spec @ 0x97c198b0 (124 bytes) */
int check_exception_spec(lsda_header_info, type_info, param_3, param_4)
  unsigned char * lsda_header_info;
  unsigned char * type_info;
  void *param_3;
  int param_4;
{
  unsigned int ghidra_home[8] = { lsda_header_info, type_info, param_3, param_4, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  unsigned char * ptVar1;
  int iVar2;
  uchar *puVar3;
  uint local_20 [4];
  
  puVar3 = (uchar *)((*(int *)(lsda_header_info + 0xc) - param_4) + -1);
  (*(void * *)((unsigned char *)ghidra_home + 8)) = param_3;
  do {
    puVar3 = (uchar *)((int (*)())__Z12read_uleb128PKhPj)(puVar3,local_20);
    if (local_20[0] == 0) {
      return 0;
    }
    ptVar1 = (unsigned char *)((int (*)())__Z15get_ttype_entryP16lsda_header_infoj)(lsda_header_info,local_20[0]);
    iVar2 = ((int (*)())get_adjusted_ptr)(ptVar1,type_info,&(*(unsigned int *)((unsigned char *)ghidra_home + 8)));
  } while (iVar2 == 0);
  return 1;
}

/* ___gxx_personality_v0 @ 0x97c1992c (976 bytes) */
int ___gxx_personality_v0(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  uint param_2;
  int param_3;
  int param_4;
  unsigned char param_5;
  unsigned char * param_6;
{
  bool bVar1;
  uchar *unwind_GetLanguageSpecificDataResult;
  uchar *puVar3;
  unsigned char iP;
  uint uVar5;
  uchar *puVar6;
  unsigned char * ptVar7;
  int iVar8;
  undefined4 uVar9;
  unsigned char new_value;
  unsigned char new_value_00;
  uchar *puVar10;
  unsigned char * ptVar11;
  uint uVar12;
  int iStack_80;
  int iStack_7c;
  undefined4 uStack_78;
  uchar *puStack_70;
  byte bStack_6c;
  byte bStack_6b;
  uint uStack_60;
  uint uStack_5c;
  uint uStack_58;
  uint uStack_54;
  uint uStack_50;
  int iStack_4c;
  void *apvStack_48 [2];
  
  apvStack_48[0] = (void *)(param_5 + 0x20);
  if (param_1 != 1) {
    return 3;
  }
  if (((param_2 == 6) && (param_3 == 0x474e5543)) && (param_4 == 0x432b2b00)) {
    new_value = *(unsigned char *)(param_5 - 0xc);
    new_value_00 = *(unsigned char *)(param_5 - 0x18);
    bVar1 = new_value == 0;
    goto LAB_97c19c74;
  }
  unwind_GetLanguageSpecificDataResult = (uchar *)((int (*)())__Unwind_GetLanguageSpecificData)(param_6);
  if (unwind_GetLanguageSpecificDataResult == (uchar *)0x0) {
    return 8;
  }
  new_value = 0;
  puVar3 = (uchar *)((int (*)())parse_lsda_header)(param_6,unwind_GetLanguageSpecificDataResult,(unsigned char *)&iStack_80);
  puVar10 = (uchar *)0x0;
  new_value_00 = 0;
  uStack_78 = ((int (*)())__Z21base_of_encoded_valuehP15_Unwind_Context)((uint)bStack_6c,param_6);
  iP = __Unwind_GetIP(param_6);
  if (puVar3 < puStack_70) {
    do {
      uVar12 = (uint)bStack_6b;
      uVar5 = ((int (*)())__Z21base_of_encoded_valuehP15_Unwind_Context)(uVar12,(unsigned char *)0x0);
      puVar3 = (uchar *)((int (*)())__Z28read_encoded_value_with_basehjPKhPj)(uVar12,uVar5,puVar3,&uStack_60);
      uVar12 = (uint)bStack_6b;
      uVar5 = ((int (*)())__Z21base_of_encoded_valuehP15_Unwind_Context)(uVar12,(unsigned char *)0x0);
      puVar3 = (uchar *)((int (*)())__Z28read_encoded_value_with_basehjPKhPj)(uVar12,uVar5,puVar3,&uStack_5c);
      uVar12 = (uint)bStack_6b;
      uVar5 = ((int (*)())__Z21base_of_encoded_valuehP15_Unwind_Context)(uVar12,(unsigned char *)0x0);
      puVar3 = (uchar *)((int (*)())__Z28read_encoded_value_with_basehjPKhPj)(uVar12,uVar5,puVar3,&uStack_58);
      puVar6 = (uchar *)((int (*)())__Z12read_uleb128PKhPj)(puVar3,&uStack_54);
      puVar3 = puStack_70;
      if ((iStack_80 + uStack_60 <= iP - 1) &&
         (puVar3 = puVar6, iP - 1 < iStack_80 + uStack_60 + uStack_5c)) {
        if (uStack_58 != 0) {
          new_value = iStack_7c + uStack_58;
        }
        if (uStack_54 != 0) {
          puVar10 = puStack_70 + (uStack_54 - 1);
        }
        if (new_value == 0) {
          return 8;
        }
        uVar5 = 2;
        if (puVar10 == (uchar *)0x0) goto LAB_97c19c1c;
        bVar1 = false;
        if ((((param_2 & 8) == 0) && (param_3 == 0x474e5543)) && (param_4 == 0x432b2b00)) {
          ptVar11 = *(unsigned char **)(param_5 - 0x30);
        }
        else {
          ptVar11 = (unsigned char *)0x0;
        }
        goto LAB_97c19b58;
      }
    } while (puVar3 < puStack_70);
  }
  uVar5 = (param_2 ^ 8) >> 3 & 1;
LAB_97c19c0c:
  if (uVar5 == 0) {
    return 8;
  }
LAB_97c19c1c:
  bVar1 = uVar5 == 1;
  if ((param_2 & 1) != 0) {
    if (uVar5 != 2) {
      if ((param_3 == 0x474e5543) && (param_4 == 0x432b2b00)) {
        *(unsigned char *)(param_5 - 0xc) = new_value;
        *(unsigned char *)(param_5 - 0x18) = new_value_00;
        *(uchar **)(param_5 - 0x14) = puVar10;
        *(uchar **)(param_5 - 0x10) = unwind_GetLanguageSpecificDataResult;
        *(void **)(param_5 - 8) = apvStack_48[0];
      }
      return 6;
    }
    return 8;
  }
LAB_97c19c74:
  if (bVar1) {
    ((int (*)())___cxa_begin_catch)(param_5);
    ((int (*)())__cxxabiv1____terminate)(*(unsigned char **)(param_5 - 0x24));
  }
  if ((int)new_value_00 < 0) {
    ((int (*)())parse_lsda_header)(param_6,*(uchar **)(param_5 - 0x10),(unsigned char *)&iStack_80);
    uVar9 = ((int (*)())__Z21base_of_encoded_valuehP15_Unwind_Context)((uint)bStack_6c,param_6);
    *(undefined4 *)(param_5 - 0xc) = uVar9;
  }
  __Unwind_SetGR(param_6,3,param_5);
  __Unwind_SetGR(param_6,4,new_value_00);
  __Unwind_SetIP(param_6,new_value);
  return 7;
LAB_97c19b58:
  puVar3 = (uchar *)((int (*)())__Z12read_sleb128PKhPi)(puVar10,(int *)&uStack_50);
  ((int (*)())__Z12read_sleb128PKhPi)(puVar3,&iStack_4c);
  if (uStack_50 == 0) {
    bVar1 = true;
  }
  else {
    if (0 < (int)uStack_50) {
      ptVar7 = (unsigned char *)
               ((int (*)())__Z15get_ttype_entryP16lsda_header_infoj)((unsigned char *)&iStack_80,uStack_50);
      uVar5 = param_2 & 8;
      if (ptVar7 == (unsigned char *)0x0) goto joined_r0x97c19bd8;
      if ((ptVar11 == (unsigned char *)0x0) ||
         (iVar8 = ((int (*)())get_adjusted_ptr)(ptVar7,ptVar11,apvStack_48), iVar8 == 0)) goto LAB_97c19bdc;
LAB_97c19bf0:
      uVar5 = 3;
      new_value_00 = uStack_50;
      goto LAB_97c19c1c;
    }
    if (ptVar11 != (unsigned char *)0x0) {
      uVar5 = ((int (*)())check_exception_spec)((unsigned char *)&iStack_80,ptVar11,apvStack_48[0],uStack_50);
joined_r0x97c19bd8:
      if (uVar5 == 0) goto LAB_97c19bf0;
    }
  }
LAB_97c19bdc:
  if (iStack_4c == 0) goto LAB_97c19bfc;
  puVar10 = puVar3 + iStack_4c;
  goto LAB_97c19b58;
LAB_97c19bfc:
  uVar5 = 2;
  if (!bVar1) {
    uVar5 = 0;
    goto LAB_97c19c0c;
  }
  goto LAB_97c19c1c;
}

/* FUN_97c19d00 @ 0x97c19d00 (232 bytes) */
int FUN_97c19d00(param_1)
  int param_1;
{
  undefined4 __terminateResult;
  undefined4 *cxa_get_globals_fastResult;
  undefined *puVar1;
  undefined *puVar2;
  undefined4 __unexpectedResult;
  undefined4 *puVar4;
  int check_exception_specResult;
  code *r3Out0;
  unsigned char * p_Var6;
  int iVar7;
  uchar *puVar8;
  unsigned char alStack_40 [8];
  undefined4 uStack_38;
  
  ((int (*)())___cxa_begin_catch)(param_1);
  uStack_38 = *(undefined4 *)(param_1 + -0xc);
  puVar8 = *(uchar **)(param_1 + -0x10);
  iVar7 = *(int *)(param_1 + -0x18);
  p_Var6 = *(unsigned char **)(param_1 + -0x24);
  __unexpectedResult = ((int (*)())__cxxabiv1____unexpected)(*(unsigned char **)(param_1 + -0x28));
  ((int (*)())___cxa_begin_catch)(__unexpectedResult);
  cxa_get_globals_fastResult = (undefined4 *)((int (*)())___cxa_get_globals_fast)();
  puVar4 = (undefined4 *)*cxa_get_globals_fastResult;
  ((int (*)())parse_lsda_header)((unsigned char *)0x0,puVar8,alStack_40);
  check_exception_specResult = ((int (*)())check_exception_spec)(alStack_40,(unsigned char *)*puVar4,puVar4 + 0x14,iVar7);
  if (check_exception_specResult != 0) {
    ___cxa_rethrow();
  }
  puVar2 = PTR_typeinfo_a7b7c180;
  check_exception_specResult = ((int (*)())check_exception_spec)(alStack_40,(unsigned char *)PTR_typeinfo_a7b7c180,(void *)0x0,iVar7);
  if (check_exception_specResult != 0) {
    puVar4 = (undefined4 *)___cxa_allocate_exception(4);
    puVar1 = PTR___ZNSt13bad_exceptionD1Ev_a7b7c17c;
    *puVar4 = PTR_vtable_a7b7c184 + 8;
                    
    ((int (*)())___cxa_throw)(puVar4,puVar2,puVar1);
  }
  __terminateResult = ((int (*)())__cxxabiv1____terminate)(p_Var6);
  ((int (*)())___cxa_end_catch)();
  ((int (*)())___cxa_end_catch)();
  __Unwind_Resume(__terminateResult);
  (*r3Out0)();
                    
  _abort();
}

/* __cxxabiv1____terminate @ 0x97c19de8 (28 bytes) */
int __cxxabiv1____terminate(param_1)
  unsigned char * param_1;
{
  ((int (*)())param_1)(param_1);
                    
  _abort();
}

/* std__terminate @ 0x97c19e0c (56 bytes) */
int std__terminate()
{
  unsigned char * p_Var1;
  
  p_Var1 = (unsigned char *)__keymgr_get_per_thread_data(4);
  if (p_Var1 != (unsigned char *)0x0) {
    __cxxabiv1____terminate_handler = p_Var1;
  }
                    
  ((int (*)())__cxxabiv1____terminate)(__cxxabiv1____terminate_handler);
}

/* __cxxabiv1____unexpected @ 0x97c19e44 (28 bytes) */
int __cxxabiv1____unexpected(param_1)
  unsigned char * param_1;
{
  unsigned char * p_Var1;
  undefined4 uVar2;
  int iVar3;
  
  ((int (*)())param_1)(param_1);
  ((int (*)())std__terminate)();
  p_Var1 = (unsigned char *)__keymgr_get_per_thread_data(3);
  if (p_Var1 != (unsigned char *)0x0) {
    __unexpected_handler = p_Var1;
  }
  uVar2 = ((int (*)())__cxxabiv1____unexpected)(__unexpected_handler);
  iVar3 = __keymgr_get_per_thread_data(4);
  __keymgr_set_per_thread_data(4,uVar2);
  if (iVar3 == 0) {
    iVar3 = __terminate_handler;
  }
  __terminate_handler = uVar2;
  return iVar3;
}

/* std__unexpected @ 0x97c19e60 (56 bytes) */
int std__unexpected()
{
  unsigned char * p_Var1;
  undefined4 uVar2;
  int iVar3;
  
  p_Var1 = (unsigned char *)__keymgr_get_per_thread_data(3);
  if (p_Var1 != (unsigned char *)0x0) {
    __cxxabiv1____unexpected_handler = p_Var1;
  }
  uVar2 = ((int (*)())__cxxabiv1____unexpected)(__cxxabiv1____unexpected_handler);
  iVar3 = __keymgr_get_per_thread_data(4);
  __keymgr_set_per_thread_data(4,uVar2);
  if (iVar3 == 0) {
    iVar3 = __cxxabiv1____terminate_handler;
  }
  __cxxabiv1____terminate_handler = uVar2;
  return iVar3;
}

/* std__set_terminate @ 0x97c19e98 (72 bytes) */
int std__set_terminate(param_1)
  unsigned char * param_1;
{
  int iVar1;
  
  iVar1 = __keymgr_get_per_thread_data(4);
  __keymgr_set_per_thread_data(4,param_1);
  if (iVar1 == 0) {
    iVar1 = (int)__cxxabiv1____terminate_handler;
  }
  __cxxabiv1____terminate_handler = param_1;
  return iVar1;
}

/* std__set_unexpected @ 0x97c19f0c (72 bytes) */
int std__set_unexpected(param_1)
  unsigned char * param_1;
{
  int iVar1;
  
  iVar1 = __keymgr_get_per_thread_data(3);
  __keymgr_set_per_thread_data(3,param_1);
  if (iVar1 == 0) {
    iVar1 = (int)__cxxabiv1____unexpected_handler;
  }
  __cxxabiv1____unexpected_handler = param_1;
  return iVar1;
}

/* ___cxa_begin_catch @ 0x97c19f80 (108 bytes) */
int ___cxa_begin_catch(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int *cxa_get_globalsResult;
  
  cxa_get_globalsResult = (int *)((int (*)())___cxa_get_globals)();
  iVar2 = *(int *)(param_1 + -0x1c);
  iVar1 = *cxa_get_globalsResult;
  if (iVar2 < 0) {
    iVar2 = -iVar2;
  }
  *(int *)(param_1 + -0x1c) = iVar2 + 1;
  cxa_get_globalsResult[1] = cxa_get_globalsResult[1] + -1;
  if (param_1 + -0x30 != iVar1) {
    *(int *)(param_1 + -0x20) = iVar1;
    *cxa_get_globalsResult = param_1 + -0x30;
  }
  return *(undefined4 *)(param_1 + -8);
}

/* ___cxa_end_catch @ 0x97c19fec (144 bytes) */
int ___cxa_end_catch()
{
  int *cxa_get_globals_fastResult;
  int iVar2;
  undefined4 r3Out0;
  int iVar3;
  
  cxa_get_globals_fastResult = (int *)((int (*)())___cxa_get_globals_fast)();
  iVar2 = *cxa_get_globals_fastResult;
  iVar3 = *(int *)(iVar2 + 0x14);
  if (iVar3 < 0) {
    iVar3 = iVar3 + 1;
    if (iVar3 == 0) {
      cxa_get_globals_fastResult[1] = cxa_get_globals_fastResult[1] + 1;
      *cxa_get_globals_fastResult = *(int *)(iVar2 + 0x10);
    }
  }
  else {
    iVar3 = iVar3 + -1;
    if (iVar3 == 0) {
      *cxa_get_globals_fastResult = *(int *)(iVar2 + 0x10);
      __Unwind_DeleteException((_Unwind_Exception *)(iVar2 + 0x30));
      return r3Out0;
    }
    if (iVar3 < 0) {
                    
      _abort();
    }
  }
  *(int *)(iVar2 + 0x14) = iVar3;
  return iVar2;
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
int ___eprintf(param_1, param_2, param_3, param_4)
  char *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_a7b7c0bc;
  _fprintf((FILE *)(PTR_DAT_a7b7c0bc + 0xb0),param_1,param_2,param_3,param_4);
  _fflush(puVar1 + 0xb0);
                    
  _abort();
}

/* FUN_97c1a23c @ 0x97c1a23c (16 bytes) */
int FUN_97c1a23c()
{
  undefined4 in_r3;
  
  return in_r3;
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
  undefined4 in_r3;
  
  return in_r3;
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
  byte bVar1;
  uint shiftForByte;
  uint shift;
  uint result;
  
  shift = 0;
  result = 0;
  do {
    bVar1 = *p;
    p = p + 1;
    shiftForByte = shift & 0x3f;
    shift = shift + 7;
    result = result | (bVar1 & 0x7f) << shiftForByte;
  } while ((bVar1 & 0x80) != 0);
  *val = result;
  return p;
}

/* _read_sleb128_97c1a41c @ 0x97c1a41c (76 bytes) */
int _read_sleb128_97c1a41c(p, val)
  byte *p;
  uint *val;
{
  byte bVar1;
  uint shiftForByte;
  uint shift;
  uint result;
  
  shift = 0;
  result = 0;
  do {
    bVar1 = *p;
    p = p + 1;
    shiftForByte = shift & 0x3f;
    shift = shift + 7;
    result = result | (bVar1 & 0x7f) << shiftForByte;
  } while ((bVar1 & 0x80) != 0);
  if ((shift < 0x20) && ((bVar1 & 0x40) != 0)) {
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

