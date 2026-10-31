#include "decls.h"

/* __ZNSs6rbeginEv @ 0x97c13f18 (60 bytes) */
int __ZNSs6rbeginEv(result, self)
  void *result;
  undefined4 self;
{
  undefined4 endIter [5];
  
  __ZNSs3endEv(endIter,self);
  *(undefined4 *)((int)result + 4) = endIter[0];
  return result;
}

/* __ZNKSs6rbeginEv @ 0x97c13f54 (60 bytes) */
int __ZNKSs6rbeginEv(result, self)
  void *result;
  undefined4 self;
{
  undefined4 endIter [5];
  
  __ZNKSs3endEv(endIter,self);
  *(undefined4 *)((int)result + 4) = endIter[0];
  return result;
}

/* __ZNSs4rendEv @ 0x97c13f90 (60 bytes) */
int __ZNSs4rendEv(result, self)
  void *result;
  undefined4 self;
{
  undefined4 beginIter [5];
  
  __ZNSs5beginEv(beginIter,self);
  *(undefined4 *)((int)result + 4) = beginIter[0];
  return result;
}

/* __ZNKSs4rendEv @ 0x97c13fcc (60 bytes) */
int __ZNKSs4rendEv(result, self)
  void *result;
  undefined4 self;
{
  undefined4 beginIter [5];
  
  __ZNKSs5beginEv(beginIter,self);
  *(undefined4 *)((int)result + 4) = beginIter[0];
  return result;
}

/* __ZNKSs6lengthEv @ 0x97c14008 (12 bytes) */
int __ZNKSs6lengthEv(this)
  void *this;
{
  return *(undefined4 *)(*(int *)this + -0xc);
}

/* __ZNSs7replaceEmmPKcm @ 0x97c14014 (316 bytes) */
int __ZNSs7replaceEmmPKcm(this, pos1, n1, str, n2)
  void *this;
  ulong pos1;
  ulong n1;
  char *str;
  ulong n2;
{
  char *data;
  uint strSize;
  int ibeginIterA;
  int ibeginIterB [4];
  
  strSize = *(uint *)(*(int *)this + -0xc);
  if (strSize < pos1) {
    std____throw_out_of_range("basic_string::replace");
  }
  if (strSize - pos1 <= n1) {
    n1 = strSize - pos1;
  }
  if (0x3ffffffc - n2 < strSize - n1) {
    std____throw_length_error("basic_string::replace");
  }
  data = *(char **)this;
  if (((*(int *)(data + -4) < 1) && (data <= str)) && (str <= data + strSize)) {
    __ZNKSs9_M_ibeginEv(ibeginIterB,this);
    __ZNKSs9_M_ibeginEv(&ibeginIterA,this);
    __ZNSs10_M_replaceIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_St18input_iterator_tag
              (this,ibeginIterA + pos1,(char *)(ibeginIterB[0] + pos1 + n1),str,
               str + n2,0);
  }
  else {
    __ZNKSs9_M_ibeginEv(&ibeginIterA,this);
    __ZNKSs9_M_ibeginEv(ibeginIterB,this);
    __ZNSs15_M_replace_safeIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_
              (this,ibeginIterB[0] + pos1,ibeginIterA + pos1 + n1,str,str + n2);
  }
  return;
}

/* __ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_S1_S1_ @ 0x97c14150 (344 bytes) */
int __ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_S1_S1_(this, i1, i2, k1, k2)
  void *this;
  int i1;
  int i2;
  char *k1;
  int k2;
{
  char *data;
  uint startOff;
  uint len1;
  int len2;
  uint strSize;
  int ibeginIter;
  int ibeginIterA;
  int ibeginIterB [2];
  
  __ZNKSs9_M_ibeginEv(&ibeginIter,this);
  len2 = k2 - (int)k1;
  strSize = *(uint *)(*(int *)this + -0xc);
  startOff = i1 - ibeginIter;
  if (strSize < startOff) {
    std____throw_out_of_range("basic_string::replace");
  }
  len1 = i2 - i1;
  if (strSize - startOff <= (uint)(i2 - i1)) {
    len1 = strSize - startOff;
  }
  if (0x3ffffffcU - len2 < strSize - len1) {
    std____throw_length_error("basic_string::replace");
  }
  data = *(char **)this;
  if (((*(int *)(data + -4) < 1) && (data <= k1)) && (k1 <= data + strSize)) {
    __ZNKSs9_M_ibeginEv(ibeginIterB,this);
    __ZNKSs9_M_ibeginEv(&ibeginIterA,this);
    __ZNSs10_M_replaceIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_St18input_iterator_tag
              (this,ibeginIterA + startOff,(char *)(ibeginIterB[0] + startOff + len1),k1,k1 + len2,0
              );
  }
  else {
    __ZNKSs9_M_ibeginEv(&ibeginIterA,this);
    __ZNKSs9_M_ibeginEv(ibeginIterB,this);
    __ZNSs15_M_replace_safeIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_
              (this,ibeginIterB[0] + startOff,ibeginIterA + startOff + len1,k1,k1 + len2);
  }
  return;
}

/* __ZNSs5eraseEmm @ 0x97c142a8 (376 bytes) */
int __ZNSs5eraseEmm(this, pos, n)
  ulong this;
  ulong pos;
  undefined4 n;
{
  char *curData;
  char *data;
  uint startOff;
  uint eraseLen;
  uint strSize;
  int posIter;
  int endIter;
  int ibeginIter;
  int ibeginIterA;
  int ibeginIterB [5];
  
  std__string___M_check((ulong)&posIter,this,pos);
  __ZNKSs7_M_foldEmm((ulong)&endIter,this,pos,n);
  data = *(char **)this;
  __ZNKSs9_M_ibeginEv(&ibeginIter,this);
  strSize = *(uint *)(*(int *)this + -0xc);
  startOff = posIter - ibeginIter;
  if (strSize < startOff) {
    std____throw_out_of_range("basic_string::replace");
  }
  eraseLen = endIter - posIter;
  if (strSize - startOff <= (uint)(endIter - posIter)) {
    eraseLen = strSize - startOff;
  }
  if (0x3ffffffc < strSize - eraseLen) {
    std____throw_length_error("basic_string::replace");
  }
  curData = *(char **)this;
  if (((*(int *)(curData + -4) < 1) && (curData <= data)) && (data <= curData + strSize)) {
    __ZNKSs9_M_ibeginEv(ibeginIterB,this);
    __ZNKSs9_M_ibeginEv(&ibeginIterA,this);
    __ZNSs10_M_replaceIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_St18input_iterator_tag
              (this,ibeginIterA + startOff,(char *)(ibeginIterB[0] + startOff + eraseLen),data,data,0);
  }
  else {
    __ZNKSs9_M_ibeginEv(&ibeginIterA,this);
    __ZNKSs9_M_ibeginEv(ibeginIterB,this);
    __ZNSs15_M_replace_safeIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_
              ((void *)this,ibeginIterB[0] + startOff,ibeginIterA + startOff + eraseLen,data,data);
  }
  return;
}

/* __ZNSs6resizeEmc @ 0x97c14420 (448 bytes) */
int __ZNSs6resizeEmc(this, n, c)
  void *this;
  ulong n;
  int c;
{
  uint startOff;
  uint origSize;
  char *data2;
  undefined3 cHigh24;
  char *data;
  uint strSize;
  uint eraseLen;
  int posIter;
  int endIter;
  int ibeginIter;
  int ibeginIterA;
  int ibeginIterB [5];
  
  if (0x3ffffffc < n) {
    std____throw_length_error("basic_string::resize");
  }
  origSize = *(uint *)(*(int *)this + -0xc);
  if (origSize < n) {
    ((int (*)())__ZNSs6appendEmc)(this,n - origSize,CONCAT31(cHigh24,c));
  }
  else if (n < origSize) {
    std__string___M_check((ulong)&posIter,this,n);
    __ZNKSs7_M_foldEmm((ulong)&endIter,(ulong)this,n,0xffffffff);
    data = *(char **)this;
    __ZNKSs9_M_ibeginEv(&ibeginIter,this);
    strSize = *(uint *)(*(int *)this + -0xc);
    startOff = posIter - ibeginIter;
    if (strSize < startOff) {
      std____throw_out_of_range("basic_string::replace");
    }
    eraseLen = endIter - posIter;
    if (strSize - startOff <= (uint)(endIter - posIter)) {
      eraseLen = strSize - startOff;
    }
    if (0x3ffffffc < strSize - eraseLen) {
      std____throw_length_error("basic_string::replace");
    }
    data2 = *(char **)this;
    if (((*(int *)(data2 + -4) < 1) && (data2 <= data)) && (data <= data2 + strSize)) {
      __ZNKSs9_M_ibeginEv(ibeginIterB,this);
      __ZNKSs9_M_ibeginEv(&ibeginIterA,this);
      __ZNSs10_M_replaceIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_St18input_iterator_tag
                (this,ibeginIterA + startOff,(char *)(ibeginIterB[0] + startOff + eraseLen),data,data,0);
    }
    else {
      __ZNKSs9_M_ibeginEv(&ibeginIterA,this);
      __ZNKSs9_M_ibeginEv(ibeginIterB,this);
      __ZNSs15_M_replace_safeIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_
                (this,ibeginIterB[0] + startOff,ibeginIterA + startOff + eraseLen,data,data);
    }
  }
  return;
}

/* __ZNSs6resizeEm @ 0x97c145e0 (8 bytes) */
int __ZNSs6resizeEm(this, n)
  void *this;
  ulong n;
{
  return ((int (*)())__ZNSs6resizeEmc)(this,n,'\0');
}

/* __ZNSs7reserveEm @ 0x97c145e8 (204 bytes) */
int __ZNSs7reserveEm(this, res)
  void *this;
  ulong res;
{
  int atomicStore;
  int *refCountPtr;
  int oldRefCount;
  undefined4 newData;
  int data;
  char reservation;
  byte cr0Reg;
  unsigned char allocatorTmp [20];
  
  data = *(int *)this;
  if ((*(uint *)(data + -8) < res) || (0 < *(int *)(data + -4))) {
    if (0x3ffffffc < res) {
      std____throw_length_error("basic_string::reserve");
      data = *(int *)this;
    }
    if (res < *(uint *)(data + -0xc)) {
      res = *(uint *)(data + -0xc);
    }
    __ZNKSs13get_allocatorEv();
    newData = __ZNSs4_Rep8_M_cloneERKSaIcEm
                      ((void *)(*(int *)this + -0xc),allocatorTmp,
                       res - *(int *)(*(int *)this + -0xc));
    data = *(int *)this;
    refCountPtr = (int *)(data + -4);
    do {
      oldRefCount = *refCountPtr;
      if (reservation != '\0') {
        atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
        *refCountPtr = atomicStore;
        cr0Reg = 2;
      }
    } while (!(bool)(cr0Reg >> 1 & 1));
    if (oldRefCount < 1) {
      __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(data + -0xc),(uint)allocatorTmp);
    }
    *(undefined4 *)this = newData;
  }
  return;
}

/* __ZNSs5clearEv @ 0x97c146cc (20 bytes) */
int __ZNSs5clearEv(this)
  void *this;
{
  return __ZNSs9_M_mutateEmmm(this,0,*(ulong *)(*(int *)this + -0xc),0);
}

/* __ZNKSs5emptyEv @ 0x97c146e0 (20 bytes) */
int __ZNKSs5emptyEv(this)
  void *this;
{
  return *(int *)(*(int *)this + -0xc) == 0;
}

/* __ZNKSsixEm @ 0x97c146f4 (12 bytes) */
int __ZNKSsixEm(this, pos)
  void *this;
  ulong pos;
{
  return *(int *)this + pos;
}

/* __ZNSsixEm @ 0x97c14700 (56 bytes) */
int __ZNSsixEm(this, pos)
  void *this;
  ulong pos;
{
  __ZNSs7_M_leakEv(this);
  return *(int *)this + pos;
}

/* __ZNKSs2atEm @ 0x97c14738 (88 bytes) */
int __ZNKSs2atEm(this, pos)
  void *this;
  ulong pos;
{
  int data;
  
  data = *(int *)this;
  if (*(uint *)(data + -0xc) <= pos) {
    std____throw_out_of_range("basic_string::at");
    data = *(int *)this;
  }
  return data + pos;
}

/* __ZNSs2atEm @ 0x97c14790 (96 bytes) */
int __ZNSs2atEm(this, pos)
  void *this;
  ulong pos;
{
  if (*(uint *)(*(int *)this + -0xc) <= pos) {
    std____throw_out_of_range("basic_string::at");
  }
  __ZNSs7_M_leakEv(this);
  return *(int *)this + pos;
}

/* __ZNSspLERKSs @ 0x97c147f0 (4 bytes) */
int __ZNSspLERKSs(this, text)
  void *this;
  unsigned char * text;
{
  return ((int (*)())__ZNSs6appendERKSs)(this,text);
}

/* __ZNSs6appendEPKc @ 0x97c147f4 (64 bytes) */
int __ZNSs6appendEPKc(this, str)
  void *this;
  char *str;
{
  ulong length;
  
  length = _strlen(str);
  return ((int (*)())__ZNSs6appendEPKcm)(this,str,length);
}

/* __ZNSspLEPKc @ 0x97c14834 (64 bytes) */
int __ZNSspLEPKc(this, str)
  void *this;
  char *str;
{
  ulong length;
  
  length = _strlen(str);
  return ((int (*)())__ZNSs6appendEPKcm)(this,str,length);
}

/* __ZNSspLEc @ 0x97c14874 (12 bytes) */
int __ZNSspLEc(this, c)
  void *this;
  int c;
{
  undefined3 cHigh24;
  
  return ((int (*)())__ZNSs6appendEmc)(this,1,CONCAT31(cHigh24,c));
}

/* __ZNSs6appendERKSs @ 0x97c14880 (164 bytes) */
int __ZNSs6appendERKSs(this, text)
  void *this;
  unsigned char * text;
{
  ulong newLen;
  undefined4 iendIterA;
  undefined4 iendIterB;
  undefined4 textBeginIter;
  undefined4 textEndIter [4];
  
  newLen = *(int *)(*(int *)text + -0xc) + *(int *)(*(int *)this + -0xc);
  if (*(uint *)(*(int *)this + -8) < newLen) {
    ((int (*)())__ZNSs7reserveEm)(this,newLen);
  }
  __ZNKSs7_M_iendEv(&iendIterA,this);
  __ZNKSs7_M_iendEv(&iendIterB,this);
  __ZNKSs9_M_ibeginEv(&textBeginIter,text);
  __ZNKSs7_M_iendEv(textEndIter,text);
  return __ZNSs15_M_replace_safeIN9__gnu_cxx17__normal_iteratorIPcSsEEEERSsS3_S3_T_S5_
            (this,iendIterA,iendIterB,textBeginIter,textEndIter[0]);
}

/* __ZNSs6appendERKSsmm @ 0x97c14924 (216 bytes) */
int __ZNSs6appendERKSsmm(this, text, pos, n)
  void *this;
  unsigned char * text;
  ulong pos;
  ulong n;
{
  unsigned int ghidra_home[8] = { this, text, pos, n, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  ulong newLen;
  uint *copyLenPtr;
  undefined4 iendIterA;
  undefined4 iendIterB;
  undefined4 textPosIter;
  undefined4 textEndIter;
  uint textRemaining [6];
  
  copyLenPtr = &(*(unsigned int *)((unsigned char *)ghidra_home + 12));
  textRemaining[0] = *(int *)(*(int *)text + -0xc) - pos;
  if (textRemaining[0] <= n) {
    copyLenPtr = textRemaining;
  }
  newLen = *copyLenPtr + *(int *)(*(int *)this + -0xc);
  (*(ulong *)((unsigned char *)ghidra_home + 12)) = n;
  if (*(uint *)(*(int *)this + -8) < newLen) {
    ((int (*)())__ZNSs7reserveEm)(this,newLen);
  }
  __ZNKSs7_M_iendEv(&iendIterA,this);
  __ZNKSs7_M_iendEv(&iendIterB,this);
  std__string___M_check((ulong)&textPosIter,text,pos);
  __ZNKSs7_M_foldEmm((ulong)&textEndIter,(ulong)text,pos,(*(ulong *)((unsigned char *)ghidra_home + 12)));
  return __ZNSs15_M_replace_safeIN9__gnu_cxx17__normal_iteratorIPcSsEEEERSsS3_S3_T_S5_
            (this,iendIterA,iendIterB,textPosIter,textEndIter);
}

/* __ZNSs6appendEPKcm @ 0x97c149fc (132 bytes) */
int __ZNSs6appendEPKcm(this, str, n)
  void *this;
  char *str;
  ulong n;
{
  ulong newLen;
  undefined4 iendIterA;
  undefined4 iendIterB [6];
  
  newLen = n + *(int *)(*(int *)this + -0xc);
  if (*(uint *)(*(int *)this + -8) < newLen) {
    ((int (*)())__ZNSs7reserveEm)(this,newLen);
  }
  __ZNKSs7_M_iendEv(&iendIterA,this);
  __ZNKSs7_M_iendEv(iendIterB,this);
  return __ZNSs15_M_replace_safeIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_
            (this,iendIterA,iendIterB[0],str,str + n);
}

/* __ZNSs6appendEmc @ 0x97c14a80 (128 bytes) */
int __ZNSs6appendEmc(this, n, c)
  void *this;
  ulong n;
  undefined4 c;
{
  ulong newLen;
  undefined4 iendIterA;
  undefined4 iendIterB [6];
  
  newLen = n + *(int *)(*(int *)this + -0xc);
  if (*(uint *)(*(int *)this + -8) < newLen) {
    ((int (*)())__ZNSs7reserveEm)(this,newLen);
  }
  __ZNKSs7_M_iendEv(&iendIterA,this);
  __ZNKSs7_M_iendEv(iendIterB,this);
  return ((int (*)())__ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_mc)(this,iendIterA,iendIterB[0],n,c);
}

/* std__string__push_back @ 0x97c14b00 (96 bytes) */
int std__string__push_back(this, c)
  unsigned char * this;
  undefined4 c;
{
  undefined4 iendIterA;
  undefined4 iendIterB [6];
  
  __ZNKSs7_M_iendEv(&iendIterA,this);
  __ZNKSs7_M_iendEv(iendIterB,this);
  return ((int (*)())__ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_mc)(this,iendIterA,iendIterB[0],1,c);
}

/* __ZNSs6assignERKSs @ 0x97c14b60 (104 bytes) */
int __ZNSs6assignERKSs(this, text)
  void *this;
  unsigned char * text;
{
  int data;
  int atomicStore;
  int *refCountPtr;
  int oldRefCount;
  undefined4 newData;
  int textData;
  char reservation;
  byte cr0Reg;
  unsigned char allocatorTmp [44];
  
  if (*(int *)this + -0xc != *(int *)text + -0xc) {
    __ZNKSs13get_allocatorEv();
    textData = *(int *)text;
    __ZNKSs13get_allocatorEv();
    newData = __ZNSs4_Rep7_M_grabERKSaIcES2_((unsigned char *)(textData + -0xc),allocatorTmp);
    data = *(int *)this;
    refCountPtr = (int *)(data + -4);
    do {
      oldRefCount = *refCountPtr;
      if (reservation != '\0') {
        atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
        *refCountPtr = atomicStore;
        cr0Reg = 2;
      }
    } while (!(bool)(cr0Reg >> 1 & 1));
    if (oldRefCount < 1) {
      __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(data + -0xc));
    }
    *(undefined4 *)this = newData;
  }
  return this;
}

/* __ZNSs6assignERKSsmm @ 0x97c14c18 (120 bytes) */
int __ZNSs6assignERKSsmm(this, text, pos, n)
  void *this;
  unsigned char * text;
  ulong pos;
  ulong n;
{
  uint repLength;
  int textData;
  uint textRemaining;
  
  textData = *(int *)text;
  repLength = *(uint *)(textData + -0xc);
  if (repLength < pos) {
    std____throw_out_of_range("basic_string::assign");
    textData = *(int *)text;
  }
  textRemaining = repLength - pos;
  if (textRemaining <= n) {
    n = textRemaining;
  }
  return __ZNSs6assignEPKcm(this,(char *)(textData + pos),n);
}

/* __ZNSs6insertEN9__gnu_cxx17__normal_iteratorIPcSsEEmc @ 0x97c14c90 (16 bytes) */
int __ZNSs6insertEN9__gnu_cxx17__normal_iteratorIPcSsEEmc(this, p, n, c)
  void *this;
  undefined4 p;
  undefined4 n;
  undefined4 c;
{
  return ((int (*)())__ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_mc)(this,p,p,n,c);
}

/* __ZNSs6insertEmPKcm @ 0x97c14ca0 (332 bytes) */
int __ZNSs6insertEmPKcm(this, pos1, str, n)
  void *this;
  ulong pos1;
  char *str;
  ulong n;
{
  char *data;
  char *srcAdj;
  char *srcRest;
  int nLeft;
  uint strSize;
  char *dstPtr;
  int ibeginIterA;
  int ibeginIterB [4];
  
  strSize = *(uint *)(*(int *)this + -0xc);
  if (strSize < pos1) {
    std____throw_out_of_range("basic_string::insert");
  }
  if (0x3ffffffc - n < strSize) {
    std____throw_length_error("basic_string::insert");
  }
  data = *(char **)this;
  if (((*(int *)(data + -4) < 1) && (data <= str)) && (str <= data + strSize)) {
    __ZNSs9_M_mutateEmmm(this,pos1,0,n);
    srcAdj = str + (*(int *)this - (int)data);
    dstPtr = (char *)(*(int *)this + pos1);
    srcRest = srcAdj;
    if ((dstPtr < srcAdj + n) && (srcRest = srcAdj + n, srcAdj < dstPtr)) {
      nLeft = (int)dstPtr - (int)srcAdj;
      _memcpy(dstPtr,srcAdj,nLeft);
      srcRest = dstPtr + n;
      dstPtr = dstPtr + nLeft;
      n = n - nLeft;
    }
    _memcpy(dstPtr,srcRest,n);
  }
  else {
    __ZNKSs9_M_ibeginEv(&ibeginIterA,this);
    __ZNKSs9_M_ibeginEv(ibeginIterB,this);
    this = __ZNSs15_M_replace_safeIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_
                     (this,ibeginIterB[0] + pos1,ibeginIterA + pos1,str,str + n);
  }
  return this;
}

/* __ZNSs6insertEmRKSsmm @ 0x97c14dec (388 bytes) */
int __ZNSs6insertEmRKSsmm(this, pos1, text, pos2, n)
  void *this;
  ulong pos1;
  unsigned char * text;
  ulong pos2;
  ulong n;
{
  uint strSize;
  int nLeft;
  uint repLength;
  char *data;
  char *srcAdj;
  int textData;
  char *srcRest;
  uint textRemaining;
  char *dstPtr;
  int ibeginIterA;
  int ibeginIterB [3];
  
  textData = *(int *)text;
  repLength = *(uint *)(textData + -0xc);
  if (repLength < pos2) {
    std____throw_out_of_range("basic_string::insert");
    textData = *(int *)text;
  }
  textRemaining = repLength - pos2;
  if (textRemaining <= n) {
    n = textRemaining;
  }
  srcAdj = (char *)(textData + pos2);
  strSize = *(uint *)(*(int *)this + -0xc);
  if (strSize < pos1) {
    std____throw_out_of_range("basic_string::insert");
  }
  if (0x3ffffffc - n < strSize) {
    std____throw_length_error("basic_string::insert");
  }
  data = *(char **)this;
  if (((*(int *)(data + -4) < 1) && (data <= srcAdj)) && (srcAdj <= data + strSize)) {
    __ZNSs9_M_mutateEmmm(this,pos1,0,n);
    srcAdj = srcAdj + (*(int *)this - (int)data);
    dstPtr = (char *)(*(int *)this + pos1);
    srcRest = srcAdj;
    if ((dstPtr < srcAdj + n) && (srcRest = srcAdj + n, srcAdj < dstPtr)) {
      nLeft = (int)dstPtr - (int)srcAdj;
      _memcpy(dstPtr,srcAdj,nLeft);
      srcRest = dstPtr + n;
      dstPtr = dstPtr + nLeft;
      n = n - nLeft;
    }
    _memcpy(dstPtr,srcRest,n);
  }
  else {
    __ZNKSs9_M_ibeginEv(&ibeginIterA,this);
    __ZNKSs9_M_ibeginEv(ibeginIterB,this);
    this = __ZNSs15_M_replace_safeIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_
                     (this,ibeginIterB[0] + pos1,ibeginIterA + pos1,srcAdj,srcAdj + n);
  }
  return this;
}

/* __ZNSs6insertEmRKSs @ 0x97c14f70 (332 bytes) */
int __ZNSs6insertEmRKSs(this, pos1, text)
  void *this;
  ulong pos1;
  unsigned char * text;
{
  char *data;
  ulong textLen;
  char *srcAdj;
  char *srcRest;
  int nLeft;
  uint strSize;
  char *dstPtr;
  int ibeginIterA;
  int ibeginIterB [4];
  
  srcAdj = *(char **)text;
  strSize = *(uint *)(*(int *)this + -0xc);
  textLen = *(ulong *)(srcAdj + -0xc);
  if (strSize < pos1) {
    std____throw_out_of_range("basic_string::insert");
  }
  if (0x3ffffffc - textLen < strSize) {
    std____throw_length_error("basic_string::insert");
  }
  data = *(char **)this;
  if (((*(int *)(data + -4) < 1) && (data <= srcAdj)) && (srcAdj <= data + strSize)) {
    __ZNSs9_M_mutateEmmm(this,pos1,0,textLen);
    srcAdj = srcAdj + (*(int *)this - (int)data);
    dstPtr = (char *)(*(int *)this + pos1);
    srcRest = srcAdj;
    if ((dstPtr < srcAdj + textLen) && (srcRest = srcAdj + textLen, srcAdj < dstPtr)) {
      nLeft = (int)dstPtr - (int)srcAdj;
      _memcpy(dstPtr,srcAdj,nLeft);
      srcRest = dstPtr + textLen;
      dstPtr = dstPtr + nLeft;
      textLen = textLen - nLeft;
    }
    _memcpy(dstPtr,srcRest,textLen);
  }
  else {
    __ZNKSs9_M_ibeginEv(&ibeginIterA,this);
    __ZNKSs9_M_ibeginEv(ibeginIterB,this);
    this = __ZNSs15_M_replace_safeIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_
                     (this,ibeginIterB[0] + pos1,ibeginIterA + pos1,srcAdj,srcAdj + textLen);
  }
  return this;
}

/* __ZNSs6insertEmPKc @ 0x97c150bc (72 bytes) */
int __ZNSs6insertEmPKc(this, pos1, str)
  void *this;
  ulong pos1;
  char *str;
{
  ulong length;
  
  length = _strlen(str);
  return ((int (*)())__ZNSs6insertEmPKcm)(this,pos1,str,length);
}

/* __ZNSs6insertEmmc @ 0x97c15104 (92 bytes) */
int __ZNSs6insertEmmc(this, pos, n, c)
  void *this;
  ulong pos;
  ulong n;
  undefined4 c;
{
  undefined4 posIter [7];
  
  std__string___M_check((ulong)posIter,this,pos);
  ((int (*)())__ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_mc)(this,posIter[0],posIter[0],n,c);
  return this;
}

/* __ZNSs6insertEN9__gnu_cxx17__normal_iteratorIPcSsEEc @ 0x97c15160 (148 bytes) */
int __ZNSs6insertEN9__gnu_cxx17__normal_iteratorIPcSsEEc(result, this, p, c)
  int *result;
  int *this;
  int p;
  undefined4 c;
{
  int posOffset;
  int iterTmp [6];
  
  __ZNKSs9_M_ibeginEv(iterTmp,this);
  posOffset = p - iterTmp[0];
  std__string___M_check((ulong)iterTmp,this,posOffset);
  ((int (*)())__ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_mc)(this,iterTmp[0],iterTmp[0],1,c);
  *(undefined4 *)(*this + -4) = 0xffffffff;
  __ZNKSs9_M_ibeginEv(iterTmp,this);
  *result = iterTmp[0] + posOffset;
  return result;
}

/* __ZNSs5eraseEN9__gnu_cxx17__normal_iteratorIPcSsEE @ 0x97c151f4 (128 bytes) */
int __ZNSs5eraseEN9__gnu_cxx17__normal_iteratorIPcSsEE(result, this, p)
  int *result;
  int *this;
  int p;
{
  int posOffset;
  int iterTmp [7];
  
  __ZNKSs9_M_ibeginEv(iterTmp,this);
  posOffset = p - iterTmp[0];
  ((int (*)())__ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_S1_S1_)(this,p,p + 1,*this,*this);
  *(undefined4 *)(*this + -4) = 0xffffffff;
  __ZNKSs9_M_ibeginEv(iterTmp,this);
  *result = iterTmp[0] + posOffset;
  return result;
}

/* __ZNSs5eraseEN9__gnu_cxx17__normal_iteratorIPcSsEES2_ @ 0x97c15274 (132 bytes) */
int __ZNSs5eraseEN9__gnu_cxx17__normal_iteratorIPcSsEES2_(result, this, first, last)
  int *result;
  int *this;
  int first;
  undefined4 last;
{
  int posOffset;
  int iterTmp [6];
  
  __ZNKSs9_M_ibeginEv(iterTmp,this);
  posOffset = first - iterTmp[0];
  ((int (*)())__ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_S1_S1_)(this,first,last,*this,*this);
  *(undefined4 *)(*this + -4) = 0xffffffff;
  __ZNKSs9_M_ibeginEv(iterTmp,this);
  *result = iterTmp[0] + posOffset;
  return result;
}

/* __ZNSs7replaceEmmRKSs @ 0x97c152f8 (12 bytes) */
int __ZNSs7replaceEmmRKSs(this, pos1, n1, text)
  void *this;
  ulong pos1;
  ulong n1;
  unsigned char * text;
{
  ((int (*)())__ZNSs7replaceEmmPKcm)(this,pos1,n1,*(char **)text,*(ulong *)(*(char **)text + -0xc))
  ;
  return;
}

/* __ZNSs7replaceEmmRKSsmm @ 0x97c15304 (136 bytes) */
int __ZNSs7replaceEmmRKSsmm(this, pos1, n1, text, pos2, n2)
  void *this;
  ulong pos1;
  ulong n1;
  unsigned char * text;
  ulong pos2;
  ulong n2;
{
  uint repLength;
  int textData;
  uint textRemaining;
  
  textData = *(int *)text;
  repLength = *(uint *)(textData + -0xc);
  if (repLength < pos2) {
    std____throw_out_of_range("basic_string::replace");
    textData = *(int *)text;
  }
  textRemaining = repLength - pos2;
  if (textRemaining <= n2) {
    n2 = textRemaining;
  }
  return ((int (*)())__ZNSs7replaceEmmPKcm)(this,pos1,n1,(char *)(textData + pos2),n2);
}

/* __ZNSs7replaceEmmPKc @ 0x97c1538c (80 bytes) */
int __ZNSs7replaceEmmPKc(this, pos1, n1, str)
  void *this;
  ulong pos1;
  ulong n1;
  char *str;
{
  ulong length;
  
  length = _strlen(str);
  return ((int (*)())__ZNSs7replaceEmmPKcm)(this,pos1,n1,str,length);
}

/* __ZNSs7replaceEmmmc @ 0x97c153dc (120 bytes) */
int __ZNSs7replaceEmmmc(this, pos1, n1, n2, c)
  void *this;
  ulong pos1;
  ulong n1;
  ulong n2;
  undefined4 c;
{
  undefined4 posIter;
  undefined4 endIter [4];
  
  std__string___M_check((ulong)&posIter,this,pos1);
  __ZNKSs7_M_foldEmm((ulong)endIter,(ulong)this,pos1,n1);
  return ((int (*)())__ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_mc)(this,posIter,endIter[0],n2,c);
}

/* __ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_PKcm @ 0x97c15454 (96 bytes) */
int __ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_PKcm(this, i1, i2, str, n)
  void *this;
  int i1;
  int i2;
  char *str;
  ulong n;
{
  int ibeginIter [5];
  
  __ZNKSs9_M_ibeginEv(ibeginIter,this);
  return ((int (*)())__ZNSs7replaceEmmPKcm)(this,i1 - ibeginIter[0],i2 - i1,str,n);
}

/* __ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_RKSs @ 0x97c154b4 (96 bytes) */
int __ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_RKSs(this, i1, i2, text)
  void *this;
  int i1;
  int i2;
  undefined4 *text;
{
  char *textData;
  ulong repLength;
  int ibeginIter [5];
  
  textData = (char *)*text;
  repLength = *(ulong *)(textData + -0xc);
  __ZNKSs9_M_ibeginEv(ibeginIter,this);
  return ((int (*)())__ZNSs7replaceEmmPKcm)(this,i1 - ibeginIter[0],i2 - i1,textData,repLength);
}

/* __ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_PKc @ 0x97c15514 (80 bytes) */
int __ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_PKc(this, i1, i2, str)
  void *this;
  undefined4 i1;
  undefined4 i2;
  undefined4 str;
{
  undefined4 length;
  
  length = _strlen(str);
  return ((int (*)())__ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_PKcm)(this,i1,i2,str,length);
}

/* __ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_mc @ 0x97c15564 (180 bytes) */
int __ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_mc(this, i1, i2, n, c)
  void *this;
  int i1;
  int i2;
  uint n;
  undefined4 c;
{
  int ibeginIter [6];
  
  __ZNKSs9_M_ibeginEv(ibeginIter,this);
  if (0x3ffffffcU - (*(int *)(*(int *)this + -0xc) - (i2 - i1)) <= n) {
    std____throw_length_error("basic_string::replace");
  }
  __ZNSs9_M_mutateEmmm(this,i1 - ibeginIter[0],i2 - i1,n);
  if (n != 0) {
    _memset(*(int *)this + (i1 - ibeginIter[0]),c,n);
  }
  return this;
}

/* __ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_PKcS4_ @ 0x97c15618 (96 bytes) */
int __ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_PKcS4_(this, i1, i2, k1, k2)
  void *this;
  int i1;
  int i2;
  char *k1;
  int k2;
{
  int ibeginIter [5];
  
  __ZNKSs9_M_ibeginEv(ibeginIter,this);
  ((int (*)())__ZNSs7replaceEmmPKcm)(this,i1 - ibeginIter[0],i2 - i1,k1,k2 - (int)k1)
  ;
  return;
}

/* __ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_S2_S2_ @ 0x97c15678 (96 bytes) */
int __ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_S2_S2_(this, i1, i2, k1, k2)
  void *this;
  int i1;
  int i2;
  char *k1;
  int k2;
{
  int ibeginIter [5];
  
  __ZNKSs9_M_ibeginEv(ibeginIter,this);
  ((int (*)())__ZNSs7replaceEmmPKcm)(this,i1 - ibeginIter[0],i2 - i1,k1,k2 - (int)k1)
  ;
  return;
}

/* __ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_NS0_IPKcSsEES5_ @ 0x97c156d8 (96 bytes) */
int __ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_NS0_IPKcSsEES5_(this, i1, i2, k1, k2)
  void *this;
  int i1;
  int i2;
  char *k1;
  int k2;
{
  int ibeginIter [5];
  
  __ZNKSs9_M_ibeginEv(ibeginIter,this);
  ((int (*)())__ZNSs7replaceEmmPKcm)(this,i1 - ibeginIter[0],i2 - i1,k1,k2 - (int)k1)
  ;
  return;
}

/* std__string___S_construct @ 0x97c15738 (140 bytes) */
int std__string___S_construct(n, c, alloc)
  ulong n;
  undefined4 c;
  unsigned char * alloc;
{
  ulong *resultData;
  ulong *rep;
  char reservation;
  
  if (n == 0) {
    if (reservation != '\0') {
      emptyStringRepRefcount_a7b7bf8c = storeWordConditionalIndexed(emptyStringRepRefcount_a7b7bf8c + 1,0,0xa7b7bf8c);
    }
    resultData = (ulong *)&emptyStringRepData_freeListBase_a7b7bf90;
  }
  else {
    rep = (ulong *)__ZNSs4_Rep9_S_createEmRKSaIcE(n,alloc);
    resultData = rep + 3;
    _memset(resultData,c,n);
    *rep = n;
    *(undefined1 *)((int)resultData + n) = 0;
  }
  return resultData;
}

/* std__string__copy @ 0x97c157c4 (132 bytes) */
int std__string__copy(this, str, n, pos)
  unsigned char * this;
  char *str;
  ulong n;
  ulong pos;
{
  uint remaining;
  int data;
  
  data = *(int *)this;
  if (*(uint *)(data + -0xc) < pos) {
    std____throw_out_of_range("basic_string::copy");
    data = *(int *)this;
  }
  remaining = *(int *)(data + -0xc) - pos;
  if (remaining < n) {
    n = remaining;
  }
  _memcpy(str,data + pos,n);
  return n;
}

/* __ZNSs4swapERSs @ 0x97c15848 (140 bytes) */
int __ZNSs4swapERSs(this, text)
  void *this;
  unsigned char * text;
{
  undefined4 data;
  
  if (*(int *)(*(int *)this + -4) < 0) {
    *(undefined4 *)(*(int *)this + -4) = 0;
  }
  if (*(int *)(*(int *)text + -4) < 0) {
    *(undefined4 *)(*(int *)text + -4) = 0;
  }
  __ZNKSs13get_allocatorEv();
  __ZNKSs13get_allocatorEv();
  data = *(undefined4 *)this;
  *(undefined4 *)this = *(undefined4 *)text;
  *(undefined4 *)text = data;
  return;
}

/* __ZNKSs5c_strEv @ 0x97c158d4 (48 bytes) */
int __ZNKSs5c_strEv(this)
  void *this;
{
  *(undefined1 *)(*(int *)this + *(int *)(*(int *)this + -0xc)) = std__string___Rep___S_terminal;
  return *(undefined4 *)this;
}

/* __ZNKSs4dataEv @ 0x97c15904 (8 bytes) */
int __ZNKSs4dataEv(this)
  void *this;
{
  return *(undefined4 *)this;
}

/* __ZNKSs4findEPKcmm @ 0x97c1590c (128 bytes) */
int __ZNKSs4findEPKcmm(this, str, pos, n)
  void *this;
  char *str;
  ulong pos;
  ulong n;
{
  uint endPos;
  int compareResult;
  uint strSize;
  int cur;
  
  endPos = pos + n;
  strSize = *(uint *)(*(int *)this + -0xc);
  if (endPos <= strSize) {
    cur = pos + *(int *)this;
    do {
      compareResult = _memcmp(cur,str,n);
      if (compareResult == 0) {
        return pos;
      }
      endPos = endPos + 1;
      pos = pos + 1;
      cur = cur + 1;
    } while (endPos <= strSize);
  }
  return 0xffffffff;
}

/* __ZNKSs4findERKSsm @ 0x97c1598c (12 bytes) */
int __ZNKSs4findERKSsm(this, text, pos)
  void *this;
  unsigned char * text;
  ulong pos;
{
  return ((int (*)())__ZNKSs4findEPKcmm)(this,*(char **)text,pos,*(ulong *)(*(char **)text + -0xc));
}

/* __ZNKSs4findEPKcm @ 0x97c15998 (72 bytes) */
int __ZNKSs4findEPKcm(this, str, pos)
  void *this;
  char *str;
  ulong pos;
{
  ulong length;
  
  length = _strlen(str);
  return ((int (*)())__ZNKSs4findEPKcmm)(this,str,pos,length);
}

/* __ZNKSs4findEcm @ 0x97c159e0 (96 bytes) */
int __ZNKSs4findEcm(this, c, pos)
  void *this;
  int c;
  ulong pos;
{
  void *memchrResult;
  int result;
  int data;
  char cSpill;
  
  result = -1;
  data = *(int *)this;
  if ((pos < *(uint *)(data + -0xc)) &&
     (cSpill = c,
     memchrResult = _memchr((void *)(data + pos),(int)c,*(uint *)(data + -0xc) - pos),
     memchrResult != (void *)0x0)) {
    result = (int)memchrResult - data;
  }
  return result;
}

/* __ZNKSs5rfindERKSsm @ 0x97c15a40 (12 bytes) */
int __ZNKSs5rfindERKSsm(this, text, pos)
  void *this;
  unsigned char * text;
  ulong pos;
{
  return ((int (*)())__ZNKSs5rfindEPKcmm)(this,*(char **)text,pos,*(ulong *)(*(char **)text + -0xc));
}

/* __ZNKSs5rfindEPKcmm @ 0x97c15a4c (148 bytes) */
int __ZNKSs5rfindEPKcmm(this, str, pos, n)
  void *this;
  char *str;
  ulong pos;
  ulong n;
{
  unsigned int ghidra_home[8] = { this, str, pos, n, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  uint curPos;
  uint *startPtr;
  int cmpResult;
  int data;
  uint maxPos [7];
  
  data = *(int *)this;
  maxPos[0] = *(uint *)(data + -0xc);
  if (n <= maxPos[0]) {
    maxPos[0] = maxPos[0] - n;
    startPtr = &(*(unsigned int *)((unsigned char *)ghidra_home + 8));
    if (maxPos[0] <= pos) {
      startPtr = maxPos;
    }
    (*(uint *)((unsigned char *)ghidra_home + 8)) = *startPtr;
    do {
      curPos = (*(uint *)((unsigned char *)ghidra_home + 8));
      cmpResult = _memcmp(data + (*(uint *)((unsigned char *)ghidra_home + 8)),str,n);
      if (cmpResult == 0) {
        return curPos;
      }
      (*(uint *)((unsigned char *)ghidra_home + 8)) = curPos - 1;
    } while ((*(uint *)((unsigned char *)ghidra_home + 8)) != 0xffffffff);
  }
  return 0xffffffff;
}

/* __ZNKSs5rfindEPKcm @ 0x97c15ae0 (72 bytes) */
int __ZNKSs5rfindEPKcm(this, str, pos)
  void *this;
  char *str;
  ulong pos;
{
  ulong length;
  
  length = _strlen(str);
  return ((int (*)())__ZNKSs5rfindEPKcmm)(this,str,pos,length);
}

