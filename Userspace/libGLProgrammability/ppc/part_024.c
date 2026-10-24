#include "decls.h"

/* __ZNSt16invalid_argumentC1ERKSs @ 0x97c17cec (4 bytes) */
int __ZNSt16invalid_argumentC1ERKSs(this, text)
  void *this;
  unsigned char * text;
{
  return ((int (*)())__ZNSt16invalid_argumentC4ERKSs)(this,text);
}

/* __ZNSt16invalid_argumentC4ERKSs @ 0x97c17cf0 (68 bytes) */
int __ZNSt16invalid_argumentC4ERKSs(this, text)
  void *this;
  unsigned char * text;
{
  __ZNSt11logic_errorC2ERKSs(this,text);
  *(undefined ***)this = &PTR___ZNSt16invalid_argumentD1Ev_a7b7dec0;
  return;
}

/* __ZNSt12length_errorC2ERKSs @ 0x97c17d34 (4 bytes) */
int __ZNSt12length_errorC2ERKSs(this, text)
  void *this;
  unsigned char * text;
{
  return ((int (*)())__ZNSt12length_errorC4ERKSs)(this,text);
}

/* __ZNSt12length_errorC1ERKSs @ 0x97c17d38 (4 bytes) */
int __ZNSt12length_errorC1ERKSs(this, text)
  void *this;
  unsigned char * text;
{
  return ((int (*)())__ZNSt12length_errorC4ERKSs)(this,text);
}

/* __ZNSt12length_errorC4ERKSs @ 0x97c17d3c (68 bytes) */
int __ZNSt12length_errorC4ERKSs(this, text)
  void *this;
  unsigned char * text;
{
  __ZNSt11logic_errorC2ERKSs(this,text);
  *(undefined ***)this = &PTR___ZNSt12length_errorD1Ev_a7b7dea8;
  return;
}

/* __ZNSt12out_of_rangeC2ERKSs @ 0x97c17d80 (4 bytes) */
int __ZNSt12out_of_rangeC2ERKSs(this, text)
  void *this;
  unsigned char * text;
{
  return ((int (*)())__ZNSt12out_of_rangeC4ERKSs)(this,text);
}

/* __ZNSt12out_of_rangeC1ERKSs @ 0x97c17d84 (4 bytes) */
int __ZNSt12out_of_rangeC1ERKSs(this, text)
  void *this;
  unsigned char * text;
{
  return ((int (*)())__ZNSt12out_of_rangeC4ERKSs)(this,text);
}

/* __ZNSt12out_of_rangeC4ERKSs @ 0x97c17d88 (68 bytes) */
int __ZNSt12out_of_rangeC4ERKSs(this, text)
  void *this;
  unsigned char * text;
{
  __ZNSt11logic_errorC2ERKSs(this,text);
  *(undefined ***)this = &PTR___ZNSt12out_of_rangeD1Ev_a7b7de90;
  return;
}

/* __ZNSt13runtime_errorC2ERKSs @ 0x97c17dcc (4 bytes) */
int __ZNSt13runtime_errorC2ERKSs(this, text)
  void *this;
  unsigned char * text;
{
  *(int *)this = DAT_a7b7c010 + 8;
  return __ZNSsC1ERKSs((void *)((int)this + 4),text);
}

/* __ZNSt13runtime_errorC1ERKSs @ 0x97c17dd0 (4 bytes) */
int __ZNSt13runtime_errorC1ERKSs(this, text)
  void *this;
  unsigned char * text;
{
  return ((int (*)())__ZNSt13runtime_errorC4ERKSs)(this,text);
}

/* __ZNSt13runtime_errorC4ERKSs @ 0x97c17dd4 (56 bytes) */
int __ZNSt13runtime_errorC4ERKSs(this, text)
  void *this;
  unsigned char * text;
{
  *(int *)this = DAT_a7b7c010 + 8;
  return __ZNSsC1ERKSs((void *)((int)this + 4),text);
}

/* __ZNSt13runtime_errorD2Ev @ 0x97c17e34 (8 bytes) */
int __ZNSt13runtime_errorD2Ev(this)
  void *this;
{
  return ((int (*)())__ZNSt13runtime_errorD4Ev)(this,0);
}

/* __ZNSt13runtime_errorD1Ev @ 0x97c17e3c (8 bytes) */
int __ZNSt13runtime_errorD1Ev(this)
  void *this;
{
  return ((int (*)())__ZNSt13runtime_errorD4Ev)(this,2);
}

/* __ZNSt13runtime_errorD0Ev @ 0x97c17e44 (8 bytes) */
int __ZNSt13runtime_errorD0Ev(this)
  void *this;
{
  return ((int (*)())__ZNSt13runtime_errorD4Ev)(this,3);
}

/* __ZNSt13runtime_errorD4Ev @ 0x97c17e4c (136 bytes) */
int __ZNSt13runtime_errorD4Ev(this, deleteFlag)
  void *this;
  uint deleteFlag;
{
  int atomicStore;
  int *refCountPtr;
  int oldRefCount;
  int stringData;
  char reservation;
  byte cr0Reg;
  undefined1 allocScratch [20];
  
  stringData = *(int *)((int)this + 4);
  *(int *)this = DAT_a7b7c010 + 8;
  refCountPtr = (int *)(stringData + -4);
  do {
    oldRefCount = *refCountPtr;
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
      *refCountPtr = atomicStore;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  if (oldRefCount < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(stringData + -0xc),allocScratch);
  }
  __ZNSt9exceptionD2Ev(this);
  if ((deleteFlag & 1) != 0) {
    __ZdlPv(this);
  }
  return;
}

/* __ZNKSt13runtime_error4whatEv @ 0x97c17ed4 (48 bytes) */
int __ZNKSt13runtime_error4whatEv(this)
  void *this;
{
  *(undefined *)(*(int *)((int)this + 4) + *(int *)(*(int *)((int)this + 4) + -0xc)) =
       *PTR__S_terminal_a7b7c0b8;
  return *(undefined4 *)((int)this + 4);
}

/* __ZNSt11range_errorC2ERKSs @ 0x97c17f04 (4 bytes) */
int __ZNSt11range_errorC2ERKSs(this, text)
  void *this;
  unsigned char * text;
{
  return ((int (*)())__ZNSt11range_errorC4ERKSs)(this,text);
}

/* __ZNSt11range_errorC1ERKSs @ 0x97c17f08 (4 bytes) */
int __ZNSt11range_errorC1ERKSs(this, text)
  void *this;
  unsigned char * text;
{
  return ((int (*)())__ZNSt11range_errorC4ERKSs)(this,text);
}

/* __ZNSt11range_errorC4ERKSs @ 0x97c17f0c (68 bytes) */
int __ZNSt11range_errorC4ERKSs(this, text)
  void *this;
  unsigned char * text;
{
  ((int (*)())__ZNSt13runtime_errorC2ERKSs)(this,text);
  *(undefined ***)this = &PTR___ZNSt11range_errorD1Ev_a7b7de78;
  return;
}

/* __ZNSt14overflow_errorC2ERKSs @ 0x97c17f50 (4 bytes) */
int __ZNSt14overflow_errorC2ERKSs(this, text)
  void *this;
  unsigned char * text;
{
  return ((int (*)())__ZNSt14overflow_errorC4ERKSs)(this,text);
}

/* __ZNSt14overflow_errorC1ERKSs @ 0x97c17f54 (4 bytes) */
int __ZNSt14overflow_errorC1ERKSs(this, text)
  void *this;
  unsigned char * text;
{
  return ((int (*)())__ZNSt14overflow_errorC4ERKSs)(this,text);
}

/* __ZNSt14overflow_errorC4ERKSs @ 0x97c17f58 (68 bytes) */
int __ZNSt14overflow_errorC4ERKSs(this, text)
  void *this;
  unsigned char * text;
{
  ((int (*)())__ZNSt13runtime_errorC2ERKSs)(this,text);
  *(undefined ***)this = &PTR___ZNSt14overflow_errorD1Ev_a7b7de60;
  return;
}

/* __ZNSt15underflow_errorC2ERKSs @ 0x97c17f9c (4 bytes) */
int __ZNSt15underflow_errorC2ERKSs(this, text)
  void *this;
  unsigned char * text;
{
  return ((int (*)())__ZNSt15underflow_errorC4ERKSs)(this,text);
}

/* __ZNSt15underflow_errorC1ERKSs @ 0x97c17fa0 (4 bytes) */
int __ZNSt15underflow_errorC1ERKSs(this, text)
  void *this;
  unsigned char * text;
{
  return ((int (*)())__ZNSt15underflow_errorC4ERKSs)(this,text);
}

/* __ZNSt15underflow_errorC4ERKSs @ 0x97c17fa4 (68 bytes) */
int __ZNSt15underflow_errorC4ERKSs(this, text)
  void *this;
  unsigned char * text;
{
  ((int (*)())__ZNSt13runtime_errorC2ERKSs)(this,text);
  *(undefined ***)this = &PTR___ZNSt15underflow_errorD1Ev_a7b7de48;
  return;
}

/* __ZNSt9type_infoD2Ev @ 0x97c17fe8 (8 bytes) */
int __ZNSt9type_infoD2Ev(this)
  void *this;
{
  return ((int (*)())__ZNSt9type_infoD4Ev)(this,0);
}

/* __ZNSt9type_infoD1Ev @ 0x97c17ff0 (8 bytes) */
int __ZNSt9type_infoD1Ev(this)
  void *this;
{
  return ((int (*)())__ZNSt9type_infoD4Ev)(this,2);
}

/* __ZNSt9type_infoD0Ev @ 0x97c17ff8 (8 bytes) */
int __ZNSt9type_infoD0Ev(this)
  void *this;
{
  return ((int (*)())__ZNSt9type_infoD4Ev)(this,3);
}

/* __ZNSt9type_infoD4Ev @ 0x97c18000 (44 bytes) */
int __ZNSt9type_infoD4Ev(this, deleteFlag)
  void *this;
  uint deleteFlag;
{
  *(int *)this = DAT_a7b7c02c + 8;
  if ((deleteFlag & 1) == 0) {
    return;
  }
  return __ZdlPv(this);
}

/* __ZNSt8bad_castD2Ev @ 0x97c1802c (8 bytes) */
int __ZNSt8bad_castD2Ev(this)
  void *this;
{
  return ((int (*)())__ZNSt8bad_castD4Ev)(this,0);
}

/* __ZNSt8bad_castD1Ev @ 0x97c18034 (8 bytes) */
int __ZNSt8bad_castD1Ev(this)
  void *this;
{
  return ((int (*)())__ZNSt8bad_castD4Ev)(this,2);
}

/* __ZNSt8bad_castD0Ev @ 0x97c1803c (8 bytes) */
int __ZNSt8bad_castD0Ev(this)
  void *this;
{
  return ((int (*)())__ZNSt8bad_castD4Ev)(this,3);
}

/* __ZNSt8bad_castD4Ev @ 0x97c18044 (88 bytes) */
int __ZNSt8bad_castD4Ev(this, deleteFlag)
  void *this;
  uint deleteFlag;
{
  *(int *)this = DAT_a7b7c028 + 8;
  __ZNSt9exceptionD2Ev(this);
  if ((deleteFlag & 1) != 0) {
    __ZdlPv(this);
  }
  return;
}

/* __ZNSt10bad_typeidD2Ev @ 0x97c1809c (8 bytes) */
int __ZNSt10bad_typeidD2Ev(this)
  void *this;
{
  return ((int (*)())__ZNSt10bad_typeidD4Ev)(this,0);
}

/* __ZNSt10bad_typeidD1Ev @ 0x97c180a4 (8 bytes) */
int __ZNSt10bad_typeidD1Ev(this)
  void *this;
{
  return ((int (*)())__ZNSt10bad_typeidD4Ev)(this,2);
}

/* __ZNSt10bad_typeidD0Ev @ 0x97c180ac (8 bytes) */
int __ZNSt10bad_typeidD0Ev(this)
  void *this;
{
  return ((int (*)())__ZNSt10bad_typeidD4Ev)(this,3);
}

/* __ZNSt10bad_typeidD4Ev @ 0x97c180b4 (88 bytes) */
int __ZNSt10bad_typeidD4Ev(this, deleteFlag)
  void *this;
  uint deleteFlag;
{
  *(int *)this = DAT_a7b7c024 + 8;
  __ZNSt9exceptionD2Ev(this);
  if ((deleteFlag & 1) != 0) {
    __ZdlPv(this);
  }
  return;
}

/* __ZNKSt9type_infoeqERKS_ @ 0x97c1810c (76 bytes) */
int __ZNKSt9type_infoeqERKS_(this, other)
  void *this;
  unsigned char * other;
{
  int nameCompare;
  undefined4 equal;
  
  equal = 0;
  if ((other == this) ||
     (nameCompare = _strcmp(*(undefined4 *)((int)this + 4),*(undefined4 *)(other + 4)), nameCompare == 0)) {
    equal = 1;
  }
  return equal;
}

/* __ZNKSt9type_info14__is_pointer_pEv @ 0x97c18158 (8 bytes) */
int __ZNKSt9type_info14__is_pointer_pEv()
{
  return 0;
}

/* __ZNKSt9type_info15__is_function_pEv @ 0x97c18160 (8 bytes) */
int __ZNKSt9type_info15__is_function_pEv()
{
  return 0;
}

/* __ZNKSt9type_info10__do_catchEPKS_PPvj @ 0x97c18168 (4 bytes) */
int __ZNKSt9type_info10__do_catchEPKS_PPvj(this, thrType, outer)
  unsigned char * this;
  void **thrType;
  uint outer;
{
  return ((int (*)())__ZNKSt9type_infoeqERKS_)(this,(unsigned char *)thrType);
}

/* __ZNKSt9type_info11__do_upcastEPKN10__cxxabiv117__class_type_infoEPPv @ 0x97c1816c (8 bytes) */
int __ZNKSt9type_info11__do_upcastEPKN10__cxxabiv117__class_type_infoEPPv(this, target)
  unsigned char * this;
  void **target;
{
  return 0;
}

/* __ZN10__cxxabiv117__class_type_infoD2Ev @ 0x97c18174 (8 bytes) */
int __ZN10__cxxabiv117__class_type_infoD2Ev(this)
  void *this;
{
  return ((int (*)())__ZN10__cxxabiv117__class_type_infoD4Ev)(this,0);
}

/* __ZN10__cxxabiv117__class_type_infoD1Ev @ 0x97c1817c (8 bytes) */
int __ZN10__cxxabiv117__class_type_infoD1Ev(this)
  void *this;
{
  return ((int (*)())__ZN10__cxxabiv117__class_type_infoD4Ev)(this,2);
}

/* __ZN10__cxxabiv117__class_type_infoD0Ev @ 0x97c18184 (8 bytes) */
int __ZN10__cxxabiv117__class_type_infoD0Ev(this)
  void *this;
{
  return ((int (*)())__ZN10__cxxabiv117__class_type_infoD4Ev)(this,3);
}

/* __ZN10__cxxabiv117__class_type_infoD4Ev @ 0x97c1818c (104 bytes) */
int __ZN10__cxxabiv117__class_type_infoD4Ev(this, deleteFlag)
  void *this;
  uint deleteFlag;
{
  *(int *)this = DAT_a7b7c020 + 8;
  ((int (*)())__ZNSt9type_infoD2Ev)(this);
  if ((deleteFlag & 1) != 0) {
    __ZdlPv(this);
    return;
  }
  return;
}

/* __ZN10__cxxabiv120__si_class_type_infoD2Ev @ 0x97c181f4 (8 bytes) */
int __ZN10__cxxabiv120__si_class_type_infoD2Ev(this)
  void *this;
{
  return ((int (*)())__ZN10__cxxabiv120__si_class_type_infoD4Ev)(this,0);
}

/* __ZN10__cxxabiv120__si_class_type_infoD1Ev @ 0x97c181fc (8 bytes) */
int __ZN10__cxxabiv120__si_class_type_infoD1Ev(this)
  void *this;
{
  return ((int (*)())__ZN10__cxxabiv120__si_class_type_infoD4Ev)(this,2);
}

/* __ZN10__cxxabiv120__si_class_type_infoD0Ev @ 0x97c18204 (8 bytes) */
int __ZN10__cxxabiv120__si_class_type_infoD0Ev(this)
  void *this;
{
  return ((int (*)())__ZN10__cxxabiv120__si_class_type_infoD4Ev)(this,3);
}

/* __ZN10__cxxabiv120__si_class_type_infoD4Ev @ 0x97c1820c (104 bytes) */
int __ZN10__cxxabiv120__si_class_type_infoD4Ev(this, deleteFlag)
  void *this;
  uint deleteFlag;
{
  *(int *)this = DAT_a7b7c01c + 8;
  ((int (*)())__ZN10__cxxabiv117__class_type_infoD2Ev)(this);
  if ((deleteFlag & 1) != 0) {
    __ZdlPv(this);
    return;
  }
  return;
}

/* __ZN10__cxxabiv121__vmi_class_type_infoD2Ev @ 0x97c18274 (8 bytes) */
int __ZN10__cxxabiv121__vmi_class_type_infoD2Ev(this)
  void *this;
{
  return ((int (*)())__ZN10__cxxabiv121__vmi_class_type_infoD4Ev)(this,0);
}

/* __ZN10__cxxabiv121__vmi_class_type_infoD1Ev @ 0x97c1827c (8 bytes) */
int __ZN10__cxxabiv121__vmi_class_type_infoD1Ev(this)
  void *this;
{
  return ((int (*)())__ZN10__cxxabiv121__vmi_class_type_infoD4Ev)(this,2);
}

/* __ZN10__cxxabiv121__vmi_class_type_infoD0Ev @ 0x97c18284 (8 bytes) */
int __ZN10__cxxabiv121__vmi_class_type_infoD0Ev(this)
  void *this;
{
  return ((int (*)())__ZN10__cxxabiv121__vmi_class_type_infoD4Ev)(this,3);
}

/* __ZN10__cxxabiv121__vmi_class_type_infoD4Ev @ 0x97c1828c (104 bytes) */
int __ZN10__cxxabiv121__vmi_class_type_infoD4Ev(this, deleteFlag)
  void *this;
  uint deleteFlag;
{
  *(int *)this = DAT_a7b7c018 + 8;
  ((int (*)())__ZN10__cxxabiv117__class_type_infoD2Ev)(this);
  if ((deleteFlag & 1) != 0) {
    __ZdlPv(this);
    return;
  }
  return;
}

/* __ZNK10__cxxabiv117__class_type_info10__do_catchEPKSt9type_infoPPvj @ 0x97c182f4 (124 bytes) */
int __ZNK10__cxxabiv117__class_type_info10__do_catchEPKSt9type_infoPPvj(this, thrType, thrObj, outer)
  void *this;
  unsigned char * thrType;
  void **thrObj;
  uint outer;
{
  int isSameType;
  undefined4 caught;
  uint outerArg;
  
  outerArg = outer;
  isSameType = ((int (*)())__ZNKSt9type_infoeqERKS_)(this,thrType);
  caught = 1;
  if ((isSameType == 0) && (caught = 0, outer < 4)) {
                    
                    
    caught = (**(code **)(*(int *)thrType + 0x14))(thrType,this,thrObj,outerArg);
    return caught;
  }
  return caught;
}

/* __ZNK10__cxxabiv117__class_type_info11__do_upcastEPKS0_PPv @ 0x97c18370 (120 bytes) */
int __ZNK10__cxxabiv117__class_type_info11__do_upcastEPKS0_PPv(this, dstType, objPtr, unusedArg4, unusedArg5, unusedArg6)
  void *this;
  unsigned char * dstType;
  void **objPtr;
  undefined4 unusedArg4;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
{
  bool isPublic;
  void *resultDstPtr;
  uint resultPart2dst;
  undefined4 resultSrcDetails;
  undefined4 resultBaseType;
  
  resultSrcDetails = 0x10;
  resultBaseType = 0;
  resultDstPtr = (void *)0x0;
  resultPart2dst = 0;
  (**(code **)(*(int *)this + 0x18))(this,dstType,*objPtr,&resultDstPtr,unusedArg5,unusedArg6,*(int *)this);
  isPublic = (resultPart2dst & 6) == 6;
  if (isPublic) {
    *objPtr = resultDstPtr;
  }
  return isPublic;
}

/* __ZNK10__cxxabiv117__class_type_info20__do_find_public_srcEiPKvPKS0_S2_ @ 0x97c183e8 (20 bytes) */
int __ZNK10__cxxabiv117__class_type_info20__do_find_public_srcEiPKvPKS0_S2_(this, src2dst, objPtr, srcType, srcPtr)
  void *this;
  int src2dst;
  void *objPtr;
  unsigned char * srcType;
  void *srcPtr;
{
  if (srcPtr == objPtr) {
    return 6;
  }
  return 1;
}

/* __ZNK10__cxxabiv120__si_class_type_info20__do_find_public_srcEiPKvPKNS_17__class_type_infoES2_ @ 0x97c183fc (136 bytes) */
int __ZNK10__cxxabiv120__si_class_type_info20__do_find_public_srcEiPKvPKNS_17__class_type_infoES2_(this, src2dst, objPtr, srcType, srcPtr)
  void *this;
  int src2dst;
  void *objPtr;
  unsigned char * srcType;
  void *srcPtr;
{
  int isSrcType;
  undefined4 baseResult;
  
  if ((srcPtr == objPtr) &&
     (isSrcType = ((int (*)())__ZNKSt9type_infoeqERKS_)(this,(unsigned char *)srcType), isSrcType != 0)) {
    return 6;
  }
                    
                    
  baseResult = (**(code **)(**(int **)((int)this + 8) + 0x20))
                    (*(int **)((int)this + 8),src2dst,objPtr,srcType,srcPtr);
  return baseResult;
}

/* __cxxabiv1____vmi_class_type_info____do_find_public_src @ 0x97c18484 (248 bytes) */
int __cxxabiv1____vmi_class_type_info____do_find_public_src(this, src2dst, objPtr, srcType, srcPtr)
  unsigned char * this;
  int src2dst;
  void *objPtr;
  unsigned char * srcType;
  void *srcPtr;
{
  int baseOffset;
  uint baseResult;
  bool isNonVirtual;
  uint baseOffsetFlags;
  int isSrcType;
  unsigned char * baseInfo;
  
  if ((objPtr == srcPtr) &&
     (isSrcType = ((int (*)())__ZNKSt9type_infoeqERKS_)(this,(unsigned char *)srcType), isSrcType != 0)) {
    return 6;
  }
  if (*(int *)(this + 0xc) != 0) {
    baseInfo = this + (*(int *)(this + 0xc) + -1) * 8;
    do {
      baseOffsetFlags = *(uint *)(baseInfo + 0x14);
      if ((baseOffsetFlags & 2) != 0) {
        baseOffset = (int)baseOffsetFlags >> 8;
        isNonVirtual = (baseOffsetFlags & 1) == 0;
        if ((isNonVirtual) || (src2dst != -3)) {
          if (!isNonVirtual) {
            baseOffset = *(int *)(*(int *)objPtr + baseOffset);
          }
          baseResult = (**(code **)(**(int **)(baseInfo + 0x10) + 0x20))
                            (*(int **)(baseInfo + 0x10),src2dst,(int)objPtr + baseOffset,srcType,srcPtr);
          if (3 < (int)baseResult) {
            if (isNonVirtual) {
              return baseResult;
            }
            return baseResult | 1;
          }
        }
      }
      baseInfo = baseInfo + -8;
    } while (baseInfo != this + -8);
  }
  return 1;
}

/* __ZNK10__cxxabiv117__class_type_info12__do_dyncastEiNS0_10__sub_kindEPKS0_PKvS3_S5_RNS0_16__dyncast_resultE @ 0x97c1857c (128 bytes) */
int __ZNK10__cxxabiv117__class_type_info12__do_dyncastEiNS0_10__sub_kindEPKS0_PKvS3_S5_RNS0_16__dyncast_resultE(this, src2dst, accessPath, dstType, objPtr, srcType, srcPtr, result)
  void *this;
  int src2dst;
  int accessPath;
  unsigned char * dstType;
  int objPtr;
  unsigned char * srcType;
  int srcPtr;
  int *result;
{
  int thisIsDstType;
  int thisIsSrcType;
  
  if ((objPtr == srcPtr) && (thisIsSrcType = ((int (*)())__ZNKSt9type_infoeqERKS_)(this,srcType), thisIsSrcType != 0)) {
    result[2] = accessPath;
  }
  else {
    thisIsDstType = ((int (*)())__ZNKSt9type_infoeqERKS_)(this,dstType);
    if (thisIsDstType != 0) {
      *result = objPtr;
      result[3] = 1;
      result[1] = accessPath;
    }
  }
  return 0;
}

