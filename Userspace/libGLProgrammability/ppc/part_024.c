#include "decls.h"

/* __ZNSt16invalid_argumentC1ERKSs @ 0x97c17cec (4 bytes) */
int __ZNSt16invalid_argumentC1ERKSs(this, param_2)
  void *this;
  unsigned char * param_2;
{
  ((int (*)())__ZNSt16invalid_argumentC4ERKSs)(this,param_2);
  return;
}

/* __ZNSt16invalid_argumentC4ERKSs @ 0x97c17cf0 (68 bytes) */
int __ZNSt16invalid_argumentC4ERKSs(this, param_2)
  void *this;
  unsigned char * param_2;
{
  __ZNSt11logic_errorC2ERKSs(this,param_2);
  *(undefined ***)this = &PTR___ZNSt16invalid_argumentD1Ev_a7b7dec0;
  return;
}

/* __ZNSt12length_errorC2ERKSs @ 0x97c17d34 (4 bytes) */
int __ZNSt12length_errorC2ERKSs(this, param_2)
  void *this;
  unsigned char * param_2;
{
  ((int (*)())__ZNSt12length_errorC4ERKSs)(this,param_2);
  return;
}

/* __ZNSt12length_errorC1ERKSs @ 0x97c17d38 (4 bytes) */
int __ZNSt12length_errorC1ERKSs(this, param_2)
  void *this;
  unsigned char * param_2;
{
  ((int (*)())__ZNSt12length_errorC4ERKSs)(this,param_2);
  return;
}

/* __ZNSt12length_errorC4ERKSs @ 0x97c17d3c (68 bytes) */
int __ZNSt12length_errorC4ERKSs(this, param_2)
  void *this;
  unsigned char * param_2;
{
  __ZNSt11logic_errorC2ERKSs(this,param_2);
  *(undefined ***)this = &PTR___ZNSt12length_errorD1Ev_a7b7dea8;
  return;
}

/* __ZNSt12out_of_rangeC2ERKSs @ 0x97c17d80 (4 bytes) */
int __ZNSt12out_of_rangeC2ERKSs(this, param_2)
  void *this;
  unsigned char * param_2;
{
  ((int (*)())__ZNSt12out_of_rangeC4ERKSs)(this,param_2);
  return;
}

/* __ZNSt12out_of_rangeC1ERKSs @ 0x97c17d84 (4 bytes) */
int __ZNSt12out_of_rangeC1ERKSs(this, param_2)
  void *this;
  unsigned char * param_2;
{
  ((int (*)())__ZNSt12out_of_rangeC4ERKSs)(this,param_2);
  return;
}

/* __ZNSt12out_of_rangeC4ERKSs @ 0x97c17d88 (68 bytes) */
int __ZNSt12out_of_rangeC4ERKSs(this, param_2)
  void *this;
  unsigned char * param_2;
{
  __ZNSt11logic_errorC2ERKSs(this,param_2);
  *(undefined ***)this = &PTR___ZNSt12out_of_rangeD1Ev_a7b7de90;
  return;
}

/* __ZNSt13runtime_errorC2ERKSs @ 0x97c17dcc (4 bytes) */
int __ZNSt13runtime_errorC2ERKSs(this, param_2)
  void *this;
  unsigned char * param_2;
{
  *(int *)this = DAT_a7b7c010 + 8;
  __ZNSsC1ERKSs((void *)((int)this + 4),param_2);
  return;
}

/* __ZNSt13runtime_errorC1ERKSs @ 0x97c17dd0 (4 bytes) */
int __ZNSt13runtime_errorC1ERKSs(this, param_2)
  void *this;
  unsigned char * param_2;
{
  ((int (*)())__ZNSt13runtime_errorC4ERKSs)(this,param_2);
  return;
}

/* __ZNSt13runtime_errorC4ERKSs @ 0x97c17dd4 (56 bytes) */
int __ZNSt13runtime_errorC4ERKSs(this, param_2)
  void *this;
  unsigned char * param_2;
{
  *(int *)this = DAT_a7b7c010 + 8;
  __ZNSsC1ERKSs((void *)((int)this + 4),param_2);
  return;
}

/* __ZNSt13runtime_errorD2Ev @ 0x97c17e34 (8 bytes) */
int __ZNSt13runtime_errorD2Ev(this)
  void *this;
{
  ((int (*)())__ZNSt13runtime_errorD4Ev)(this);
  return;
}

/* __ZNSt13runtime_errorD1Ev @ 0x97c17e3c (8 bytes) */
int __ZNSt13runtime_errorD1Ev(this)
  void *this;
{
  ((int (*)())__ZNSt13runtime_errorD4Ev)(this);
  return;
}

/* __ZNSt13runtime_errorD0Ev @ 0x97c17e44 (8 bytes) */
int __ZNSt13runtime_errorD0Ev(this)
  void *this;
{
  ((int (*)())__ZNSt13runtime_errorD4Ev)(this);
  return;
}

/* __ZNSt13runtime_errorD4Ev @ 0x97c17e4c (136 bytes) */
int __ZNSt13runtime_errorD4Ev(this)
  void *this;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint in_r4;
  int iVar4;
  char in_RESERVE;
  byte in_cr0;
  
  iVar4 = *(int *)((int)this + 4);
  *(int *)this = DAT_a7b7c010 + 8;
  piVar2 = (int *)(iVar4 + -4);
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar3 < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(iVar4 + -0xc));
  }
  __ZNSt9exceptionD2Ev(this);
  if ((in_r4 & 1) != 0) {
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
int __ZNSt11range_errorC2ERKSs(this, param_2)
  void *this;
  unsigned char * param_2;
{
  ((int (*)())__ZNSt11range_errorC4ERKSs)(this,param_2);
  return;
}

/* __ZNSt11range_errorC1ERKSs @ 0x97c17f08 (4 bytes) */
int __ZNSt11range_errorC1ERKSs(this, param_2)
  void *this;
  unsigned char * param_2;
{
  ((int (*)())__ZNSt11range_errorC4ERKSs)(this,param_2);
  return;
}

/* __ZNSt11range_errorC4ERKSs @ 0x97c17f0c (68 bytes) */
int __ZNSt11range_errorC4ERKSs(this, param_2)
  void *this;
  unsigned char * param_2;
{
  ((int (*)())__ZNSt13runtime_errorC2ERKSs)(this,param_2);
  *(undefined ***)this = &PTR___ZNSt11range_errorD1Ev_a7b7de78;
  return;
}

/* __ZNSt14overflow_errorC2ERKSs @ 0x97c17f50 (4 bytes) */
int __ZNSt14overflow_errorC2ERKSs(this, param_2)
  void *this;
  unsigned char * param_2;
{
  ((int (*)())__ZNSt14overflow_errorC4ERKSs)(this,param_2);
  return;
}

/* __ZNSt14overflow_errorC1ERKSs @ 0x97c17f54 (4 bytes) */
int __ZNSt14overflow_errorC1ERKSs(this, param_2)
  void *this;
  unsigned char * param_2;
{
  ((int (*)())__ZNSt14overflow_errorC4ERKSs)(this,param_2);
  return;
}

/* __ZNSt14overflow_errorC4ERKSs @ 0x97c17f58 (68 bytes) */
int __ZNSt14overflow_errorC4ERKSs(this, param_2)
  void *this;
  unsigned char * param_2;
{
  ((int (*)())__ZNSt13runtime_errorC2ERKSs)(this,param_2);
  *(undefined ***)this = &PTR___ZNSt14overflow_errorD1Ev_a7b7de60;
  return;
}

/* __ZNSt15underflow_errorC2ERKSs @ 0x97c17f9c (4 bytes) */
int __ZNSt15underflow_errorC2ERKSs(this, param_2)
  void *this;
  unsigned char * param_2;
{
  ((int (*)())__ZNSt15underflow_errorC4ERKSs)(this,param_2);
  return;
}

/* __ZNSt15underflow_errorC1ERKSs @ 0x97c17fa0 (4 bytes) */
int __ZNSt15underflow_errorC1ERKSs(this, param_2)
  void *this;
  unsigned char * param_2;
{
  ((int (*)())__ZNSt15underflow_errorC4ERKSs)(this,param_2);
  return;
}

/* __ZNSt15underflow_errorC4ERKSs @ 0x97c17fa4 (68 bytes) */
int __ZNSt15underflow_errorC4ERKSs(this, param_2)
  void *this;
  unsigned char * param_2;
{
  ((int (*)())__ZNSt13runtime_errorC2ERKSs)(this,param_2);
  *(undefined ***)this = &PTR___ZNSt15underflow_errorD1Ev_a7b7de48;
  return;
}

/* __ZNSt9type_infoD2Ev @ 0x97c17fe8 (8 bytes) */
int __ZNSt9type_infoD2Ev(this)
  void *this;
{
  ((int (*)())__ZNSt9type_infoD4Ev)(this);
  return;
}

/* __ZNSt9type_infoD1Ev @ 0x97c17ff0 (8 bytes) */
int __ZNSt9type_infoD1Ev(this)
  void *this;
{
  ((int (*)())__ZNSt9type_infoD4Ev)(this);
  return;
}

/* __ZNSt9type_infoD0Ev @ 0x97c17ff8 (8 bytes) */
int __ZNSt9type_infoD0Ev(this)
  void *this;
{
  ((int (*)())__ZNSt9type_infoD4Ev)(this);
  return;
}

/* __ZNSt9type_infoD4Ev @ 0x97c18000 (44 bytes) */
int __ZNSt9type_infoD4Ev(this)
  void *this;
{
  uint in_r4;
  
  *(int *)this = DAT_a7b7c02c + 8;
  if ((in_r4 & 1) == 0) {
    return;
  }
  __ZdlPv(this);
  return;
}

/* __ZNSt8bad_castD2Ev @ 0x97c1802c (8 bytes) */
int __ZNSt8bad_castD2Ev(this)
  void *this;
{
  ((int (*)())__ZNSt8bad_castD4Ev)(this);
  return;
}

/* __ZNSt8bad_castD1Ev @ 0x97c18034 (8 bytes) */
int __ZNSt8bad_castD1Ev(this)
  void *this;
{
  ((int (*)())__ZNSt8bad_castD4Ev)(this);
  return;
}

/* __ZNSt8bad_castD0Ev @ 0x97c1803c (8 bytes) */
int __ZNSt8bad_castD0Ev(this)
  void *this;
{
  ((int (*)())__ZNSt8bad_castD4Ev)(this);
  return;
}

/* __ZNSt8bad_castD4Ev @ 0x97c18044 (88 bytes) */
int __ZNSt8bad_castD4Ev(this)
  void *this;
{
  uint in_r4;
  
  *(int *)this = DAT_a7b7c028 + 8;
  __ZNSt9exceptionD2Ev(this);
  if ((in_r4 & 1) != 0) {
    __ZdlPv(this);
  }
  return;
}

/* __ZNSt10bad_typeidD2Ev @ 0x97c1809c (8 bytes) */
int __ZNSt10bad_typeidD2Ev(this)
  void *this;
{
  ((int (*)())__ZNSt10bad_typeidD4Ev)(this);
  return;
}

/* __ZNSt10bad_typeidD1Ev @ 0x97c180a4 (8 bytes) */
int __ZNSt10bad_typeidD1Ev(this)
  void *this;
{
  ((int (*)())__ZNSt10bad_typeidD4Ev)(this);
  return;
}

/* __ZNSt10bad_typeidD0Ev @ 0x97c180ac (8 bytes) */
int __ZNSt10bad_typeidD0Ev(this)
  void *this;
{
  ((int (*)())__ZNSt10bad_typeidD4Ev)(this);
  return;
}

/* __ZNSt10bad_typeidD4Ev @ 0x97c180b4 (88 bytes) */
int __ZNSt10bad_typeidD4Ev(this)
  void *this;
{
  uint in_r4;
  
  *(int *)this = DAT_a7b7c024 + 8;
  __ZNSt9exceptionD2Ev(this);
  if ((in_r4 & 1) != 0) {
    __ZdlPv(this);
  }
  return;
}

/* __ZNKSt9type_infoeqERKS_ @ 0x97c1810c (76 bytes) */
int __ZNKSt9type_infoeqERKS_(this, param_2)
  void *this;
  unsigned char * param_2;
{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((param_2 == this) ||
     (iVar1 = _strcmp(*(char **)((int)this + 4),*(char **)(param_2 + 4)), iVar1 == 0)) {
    uVar2 = 1;
  }
  return uVar2;
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
int __ZNKSt9type_info10__do_catchEPKS_PPvj(param_1, param_2, param_3)
  unsigned char * param_1;
  void **param_2;
  uint param_3;
{
  ((int (*)())__ZNKSt9type_infoeqERKS_)(param_1,(unsigned char *)param_2);
  return;
}

/* __ZNKSt9type_info11__do_upcastEPKN10__cxxabiv117__class_type_infoEPPv @ 0x97c1816c (8 bytes) */
int __ZNKSt9type_info11__do_upcastEPKN10__cxxabiv117__class_type_infoEPPv(param_1, param_2)
  unsigned char * param_1;
  void **param_2;
{
  return 0;
}

/* __ZN10__cxxabiv117__class_type_infoD2Ev @ 0x97c18174 (8 bytes) */
int __ZN10__cxxabiv117__class_type_infoD2Ev(this)
  void *this;
{
  ((int (*)())__ZN10__cxxabiv117__class_type_infoD4Ev)(this);
  return;
}

/* __ZN10__cxxabiv117__class_type_infoD1Ev @ 0x97c1817c (8 bytes) */
int __ZN10__cxxabiv117__class_type_infoD1Ev(this)
  void *this;
{
  ((int (*)())__ZN10__cxxabiv117__class_type_infoD4Ev)(this);
  return;
}

/* __ZN10__cxxabiv117__class_type_infoD0Ev @ 0x97c18184 (8 bytes) */
int __ZN10__cxxabiv117__class_type_infoD0Ev(this)
  void *this;
{
  ((int (*)())__ZN10__cxxabiv117__class_type_infoD4Ev)(this);
  return;
}

/* __ZN10__cxxabiv117__class_type_infoD4Ev @ 0x97c1818c (104 bytes) */
int __ZN10__cxxabiv117__class_type_infoD4Ev(this)
  void *this;
{
  uint in_r4;
  
  *(int *)this = DAT_a7b7c020 + 8;
  ((int (*)())__ZNSt9type_infoD2Ev)(this);
  if ((in_r4 & 1) != 0) {
    __ZdlPv(this);
    return;
  }
  return;
}

/* __ZN10__cxxabiv120__si_class_type_infoD2Ev @ 0x97c181f4 (8 bytes) */
int __ZN10__cxxabiv120__si_class_type_infoD2Ev(this)
  void *this;
{
  ((int (*)())__ZN10__cxxabiv120__si_class_type_infoD4Ev)(this);
  return;
}

/* __ZN10__cxxabiv120__si_class_type_infoD1Ev @ 0x97c181fc (8 bytes) */
int __ZN10__cxxabiv120__si_class_type_infoD1Ev(this)
  void *this;
{
  ((int (*)())__ZN10__cxxabiv120__si_class_type_infoD4Ev)(this);
  return;
}

/* __ZN10__cxxabiv120__si_class_type_infoD0Ev @ 0x97c18204 (8 bytes) */
int __ZN10__cxxabiv120__si_class_type_infoD0Ev(this)
  void *this;
{
  ((int (*)())__ZN10__cxxabiv120__si_class_type_infoD4Ev)(this);
  return;
}

/* __ZN10__cxxabiv120__si_class_type_infoD4Ev @ 0x97c1820c (104 bytes) */
int __ZN10__cxxabiv120__si_class_type_infoD4Ev(this)
  void *this;
{
  uint in_r4;
  
  *(int *)this = DAT_a7b7c01c + 8;
  ((int (*)())__ZN10__cxxabiv117__class_type_infoD2Ev)(this);
  if ((in_r4 & 1) != 0) {
    __ZdlPv(this);
    return;
  }
  return;
}

/* __ZN10__cxxabiv121__vmi_class_type_infoD2Ev @ 0x97c18274 (8 bytes) */
int __ZN10__cxxabiv121__vmi_class_type_infoD2Ev(this)
  void *this;
{
  ((int (*)())__ZN10__cxxabiv121__vmi_class_type_infoD4Ev)(this);
  return;
}

/* __ZN10__cxxabiv121__vmi_class_type_infoD1Ev @ 0x97c1827c (8 bytes) */
int __ZN10__cxxabiv121__vmi_class_type_infoD1Ev(this)
  void *this;
{
  ((int (*)())__ZN10__cxxabiv121__vmi_class_type_infoD4Ev)(this);
  return;
}

/* __ZN10__cxxabiv121__vmi_class_type_infoD0Ev @ 0x97c18284 (8 bytes) */
int __ZN10__cxxabiv121__vmi_class_type_infoD0Ev(this)
  void *this;
{
  ((int (*)())__ZN10__cxxabiv121__vmi_class_type_infoD4Ev)(this);
  return;
}

/* __ZN10__cxxabiv121__vmi_class_type_infoD4Ev @ 0x97c1828c (104 bytes) */
int __ZN10__cxxabiv121__vmi_class_type_infoD4Ev(this)
  void *this;
{
  uint in_r4;
  
  *(int *)this = DAT_a7b7c018 + 8;
  ((int (*)())__ZN10__cxxabiv117__class_type_infoD2Ev)(this);
  if ((in_r4 & 1) != 0) {
    __ZdlPv(this);
    return;
  }
  return;
}

/* __ZNK10__cxxabiv117__class_type_info10__do_catchEPKSt9type_infoPPvj @ 0x97c182f4 (124 bytes) */
int __ZNK10__cxxabiv117__class_type_info10__do_catchEPKSt9type_infoPPvj(this, param_2, param_3, param_4)
  void *this;
  unsigned char * param_2;
  void **param_3;
  uint param_4;
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = ((int (*)())__ZNKSt9type_infoeqERKS_)(this,param_2);
  uVar2 = 1;
  if ((iVar1 == 0) && (uVar2 = 0, param_4 < 4)) {
                    
                    
    uVar2 = (**(code **)(*(int *)param_2 + 0x14))(param_2,this,param_3);
    return uVar2;
  }
  return uVar2;
}

/* __ZNK10__cxxabiv117__class_type_info11__do_upcastEPKS0_PPv @ 0x97c18370 (120 bytes) */
int __ZNK10__cxxabiv117__class_type_info11__do_upcastEPKS0_PPv(this, param_2, param_3)
  void *this;
  unsigned char * param_2;
  void **param_3;
{
  bool bVar1;
  void *local_20;
  uint local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  local_18 = 0x10;
  local_14 = 0;
  local_20 = (void *)0x0;
  local_1c = 0;
  (**(code **)(*(int *)this + 0x18))(this,param_2,*param_3,&local_20);
  bVar1 = (local_1c & 6) == 6;
  if (bVar1) {
    *param_3 = local_20;
  }
  return bVar1;
}

/* __ZNK10__cxxabiv117__class_type_info20__do_find_public_srcEiPKvPKS0_S2_ @ 0x97c183e8 (20 bytes) */
int __ZNK10__cxxabiv117__class_type_info20__do_find_public_srcEiPKvPKS0_S2_(this, param_2, param_3, param_4, param_5)
  void *this;
  int param_2;
  void *param_3;
  unsigned char * param_4;
  void *param_5;
{
  if (param_5 == param_3) {
    return 6;
  }
  return 1;
}

/* __ZNK10__cxxabiv120__si_class_type_info20__do_find_public_srcEiPKvPKNS_17__class_type_infoES2_ @ 0x97c183fc (136 bytes) */
int __ZNK10__cxxabiv120__si_class_type_info20__do_find_public_srcEiPKvPKNS_17__class_type_infoES2_(this, param_2, param_3, param_4, param_5)
  void *this;
  int param_2;
  void *param_3;
  unsigned char * param_4;
  void *param_5;
{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_5 == param_3) &&
     (iVar1 = ((int (*)())__ZNKSt9type_infoeqERKS_)(this,(unsigned char *)param_4), iVar1 != 0)) {
    return 6;
  }
                    
                    
  uVar2 = (**(code **)(**(int **)((int)this + 8) + 0x20))
                    (*(int **)((int)this + 8),param_2,param_3,param_4,param_5);
  return uVar2;
}

/* __cxxabiv1____vmi_class_type_info____do_find_public_src @ 0x97c18484 (248 bytes) */
int __cxxabiv1____vmi_class_type_info____do_find_public_src(this, param_2, param_3, param_4, param_5)
  unsigned char * this;
  int param_2;
  void *param_3;
  unsigned char * param_4;
  void *param_5;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  unsigned char * p_Var4;
  
  if ((param_3 == param_5) &&
     (iVar3 = ((int (*)())__ZNKSt9type_infoeqERKS_)(this,(unsigned char *)param_4), iVar3 != 0)) {
    return 6;
  }
  if (*(int *)(this + 0xc) != 0) {
    p_Var4 = this + (*(int *)(this + 0xc) + -1) * 8;
    do {
      uVar2 = *(uint *)(p_Var4 + 0x14);
      if ((uVar2 & 2) != 0) {
        iVar3 = (int)uVar2 >> 8;
        bVar1 = (uVar2 & 1) == 0;
        if ((bVar1) || (param_2 != -3)) {
          if (!bVar1) {
            iVar3 = *(int *)(*(int *)param_3 + iVar3);
          }
          uVar2 = (**(code **)(**(int **)(p_Var4 + 0x10) + 0x20))
                            (*(int **)(p_Var4 + 0x10),param_2,(int)param_3 + iVar3,param_4,param_5);
          if (3 < (int)uVar2) {
            if (bVar1) {
              return uVar2;
            }
            return uVar2 | 1;
          }
        }
      }
      p_Var4 = p_Var4 + -8;
    } while (p_Var4 != this + -8);
  }
  return 1;
}

/* __ZNK10__cxxabiv117__class_type_info12__do_dyncastEiNS0_10__sub_kindEPKS0_PKvS3_S5_RNS0_16__dyncast_resultE @ 0x97c1857c (128 bytes) */
int __ZNK10__cxxabiv117__class_type_info12__do_dyncastEiNS0_10__sub_kindEPKS0_PKvS3_S5_RNS0_16__dyncast_resultE(this, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  void *this;
  undefined4 param_2;
  int param_3;
  unsigned char * param_4;
  int param_5;
  unsigned char * param_6;
  int param_7;
  int *param_8;
{
  int iVar1;
  
  if ((param_5 == param_7) && (iVar1 = ((int (*)())__ZNKSt9type_infoeqERKS_)(this,param_6), iVar1 != 0)) {
    param_8[2] = param_3;
  }
  else {
    iVar1 = ((int (*)())__ZNKSt9type_infoeqERKS_)(this,param_4);
    if (iVar1 != 0) {
      *param_8 = param_5;
      param_8[3] = 1;
      param_8[1] = param_3;
    }
  }
  return 0;
}

