#include "decls.h"

/* std__invalid_argument__invalid_argument_97c17cec @ 0x97c17cec (4 bytes) */
int std__invalid_argument__invalid_argument_97c17cec(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  invalid_argument(this,param_1);
  return;
}

/* std__invalid_argument__invalid_argument_97c17cf0 @ 0x97c17cf0 (68 bytes) */
int std__invalid_argument__invalid_argument_97c17cf0(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  logic_error__logic_error((unsigned char *)this,param_1);
  *(undefined ***)this = &PTR__invalid_argument_a7b7dec0;
  return;
}

/* std__length_error__length_error @ 0x97c17d34 (4 bytes) */
int std__length_error__length_error(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  length_error(this,param_1);
  return;
}

/* std__length_error__length_error_97c17d38 @ 0x97c17d38 (4 bytes) */
int std__length_error__length_error_97c17d38(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  length_error(this,param_1);
  return;
}

/* std__length_error__length_error_97c17d3c @ 0x97c17d3c (68 bytes) */
int std__length_error__length_error_97c17d3c(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  logic_error__logic_error((unsigned char *)this,param_1);
  *(undefined ***)this = &PTR__length_error_a7b7dea8;
  return;
}

/* std__out_of_range__out_of_range @ 0x97c17d80 (4 bytes) */
int std__out_of_range__out_of_range(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  out_of_range(this,param_1);
  return;
}

/* std__out_of_range__out_of_range_97c17d84 @ 0x97c17d84 (4 bytes) */
int std__out_of_range__out_of_range_97c17d84(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  out_of_range(this,param_1);
  return;
}

/* std__out_of_range__out_of_range_97c17d88 @ 0x97c17d88 (68 bytes) */
int std__out_of_range__out_of_range_97c17d88(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  logic_error__logic_error((unsigned char *)this,param_1);
  *(undefined ***)this = &PTR__out_of_range_a7b7de90;
  return;
}

/* std__runtime_error__runtime_error @ 0x97c17dcc (4 bytes) */
int std__runtime_error__runtime_error(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  *(int *)this = DAT_a7b7c010 + 8;
  std__string__string((unsigned char *)(this + 4),param_1);
  return;
}

/* std__runtime_error__runtime_error_97c17dd0 @ 0x97c17dd0 (4 bytes) */
int std__runtime_error__runtime_error_97c17dd0(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  runtime_error(this,param_1);
  return;
}

/* std__runtime_error__runtime_error_97c17dd4 @ 0x97c17dd4 (76 bytes) */
int std__runtime_error__runtime_error_97c17dd4(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  *(int *)this = DAT_a7b7c010 + 8;
  std__string__string((unsigned char *)(this + 4),param_1);
  return;
}

/* std__runtime_error___runtime_error @ 0x97c17e34 (8 bytes) */
int std__runtime_error___runtime_error(this)
  unsigned char * this;
{
  ~runtime_error(this);
  return;
}

/* std__runtime_error___runtime_error_97c17e3c @ 0x97c17e3c (8 bytes) */
int std__runtime_error___runtime_error_97c17e3c(this)
  unsigned char * this;
{
  ~runtime_error(this);
  return;
}

/* std__runtime_error___runtime_error_97c17e44 @ 0x97c17e44 (8 bytes) */
int std__runtime_error___runtime_error_97c17e44(this)
  unsigned char * this;
{
  ~runtime_error(this);
  return;
}

/* std__runtime_error___runtime_error_97c17e4c @ 0x97c17e4c (136 bytes) */
int std__runtime_error___runtime_error_97c17e4c(this)
  unsigned char * this;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint in_r4;
  int iVar4;
  char in_RESERVE;
  byte in_cr0;
  
  iVar4 = *(int *)(this + 4);
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
    std__string___Rep___M_destroy((unsigned char *)(iVar4 + -0xc));
  }
  std__exception___exception((unsigned char *)this);
  if ((in_r4 & 1) != 0) {
    operator_delete(this);
  }
  return;
}

/* std__runtime_error__what @ 0x97c17ed4 (48 bytes) */
int std__runtime_error__what(this)
  unsigned char * this;
{
  *(undefined *)(*(int *)(this + 4) + *(int *)(*(int *)(this + 4) + -0xc)) =
       *PTR__S_terminal_a7b7c0b8;
  return *(undefined4 *)(this + 4);
}

/* std__range_error__range_error @ 0x97c17f04 (4 bytes) */
int std__range_error__range_error(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  range_error(this,param_1);
  return;
}

/* std__range_error__range_error_97c17f08 @ 0x97c17f08 (4 bytes) */
int std__range_error__range_error_97c17f08(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  range_error(this,param_1);
  return;
}

/* std__range_error__range_error_97c17f0c @ 0x97c17f0c (68 bytes) */
int std__range_error__range_error_97c17f0c(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  runtime_error__runtime_error((unsigned char *)this,param_1);
  *(undefined ***)this = &PTR__range_error_a7b7de78;
  return;
}

/* std__overflow_error__overflow_error @ 0x97c17f50 (4 bytes) */
int std__overflow_error__overflow_error(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  overflow_error(this,param_1);
  return;
}

/* std__overflow_error__overflow_error_97c17f54 @ 0x97c17f54 (4 bytes) */
int std__overflow_error__overflow_error_97c17f54(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  overflow_error(this,param_1);
  return;
}

/* std__overflow_error__overflow_error_97c17f58 @ 0x97c17f58 (68 bytes) */
int std__overflow_error__overflow_error_97c17f58(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  runtime_error__runtime_error((unsigned char *)this,param_1);
  *(undefined ***)this = &PTR__overflow_error_a7b7de60;
  return;
}

/* std__underflow_error__underflow_error @ 0x97c17f9c (4 bytes) */
int std__underflow_error__underflow_error(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  underflow_error(this,param_1);
  return;
}

/* std__underflow_error__underflow_error_97c17fa0 @ 0x97c17fa0 (4 bytes) */
int std__underflow_error__underflow_error_97c17fa0(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  underflow_error(this,param_1);
  return;
}

/* std__underflow_error__underflow_error_97c17fa4 @ 0x97c17fa4 (68 bytes) */
int std__underflow_error__underflow_error_97c17fa4(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  runtime_error__runtime_error((unsigned char *)this,param_1);
  *(undefined ***)this = &PTR__underflow_error_a7b7de48;
  return;
}

/* std__type_info___type_info @ 0x97c17fe8 (8 bytes) */
int std__type_info___type_info(this)
  unsigned char * this;
{
  ~type_info(this);
  return;
}

/* std__type_info___type_info_97c17ff0 @ 0x97c17ff0 (8 bytes) */
int std__type_info___type_info_97c17ff0(this)
  unsigned char * this;
{
  ~type_info(this);
  return;
}

/* std__type_info___type_info_97c17ff8 @ 0x97c17ff8 (8 bytes) */
int std__type_info___type_info_97c17ff8(this)
  unsigned char * this;
{
  ~type_info(this);
  return;
}

/* std__type_info___type_info_97c18000 @ 0x97c18000 (44 bytes) */
int std__type_info___type_info_97c18000(this)
  unsigned char * this;
{
  uint in_r4;
  
  *(int *)this = DAT_a7b7c02c + 8;
  if ((in_r4 & 1) == 0) {
    return;
  }
  operator_delete(this);
  return;
}

/* std__bad_cast___bad_cast @ 0x97c1802c (8 bytes) */
int std__bad_cast___bad_cast(this)
  unsigned char * this;
{
  ~bad_cast(this);
  return;
}

/* std__bad_cast___bad_cast_97c18034 @ 0x97c18034 (8 bytes) */
int std__bad_cast___bad_cast_97c18034(this)
  unsigned char * this;
{
  ~bad_cast(this);
  return;
}

/* std__bad_cast___bad_cast_97c1803c @ 0x97c1803c (8 bytes) */
int std__bad_cast___bad_cast_97c1803c(this)
  unsigned char * this;
{
  ~bad_cast(this);
  return;
}

/* std__bad_cast___bad_cast_97c18044 @ 0x97c18044 (88 bytes) */
int std__bad_cast___bad_cast_97c18044(this)
  unsigned char * this;
{
  uint in_r4;
  
  *(int *)this = DAT_a7b7c028 + 8;
  std__exception___exception((unsigned char *)this);
  if ((in_r4 & 1) != 0) {
    operator_delete(this);
  }
  return;
}

/* std__bad_typeid___bad_typeid @ 0x97c1809c (8 bytes) */
int std__bad_typeid___bad_typeid(this)
  unsigned char * this;
{
  ~bad_typeid(this);
  return;
}

/* std__bad_typeid___bad_typeid_97c180a4 @ 0x97c180a4 (8 bytes) */
int std__bad_typeid___bad_typeid_97c180a4(this)
  unsigned char * this;
{
  ~bad_typeid(this);
  return;
}

/* std__bad_typeid___bad_typeid_97c180ac @ 0x97c180ac (8 bytes) */
int std__bad_typeid___bad_typeid_97c180ac(this)
  unsigned char * this;
{
  ~bad_typeid(this);
  return;
}

/* std__bad_typeid___bad_typeid_97c180b4 @ 0x97c180b4 (88 bytes) */
int std__bad_typeid___bad_typeid_97c180b4(this)
  unsigned char * this;
{
  uint in_r4;
  
  *(int *)this = DAT_a7b7c024 + 8;
  std__exception___exception((unsigned char *)this);
  if ((in_r4 & 1) != 0) {
    operator_delete(this);
  }
  return;
}

/* std__type_info__operator__ @ 0x97c1810c (76 bytes) */
int std__type_info__operator__(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((param_1 == this) ||
     (iVar1 = _strcmp(*(char **)(this + 4),*(char **)(param_1 + 4)), iVar1 == 0)) {
    uVar2 = 1;
  }
  return uVar2;
}

/* std__type_info____is_pointer_p @ 0x97c18158 (8 bytes) */
int std__type_info____is_pointer_p()
{
  return 0;
}

/* std__type_info____is_function_p @ 0x97c18160 (8 bytes) */
int std__type_info____is_function_p()
{
  return 0;
}

/* std__type_info____do_catch @ 0x97c18168 (4 bytes) */
int std__type_info____do_catch(param_1, param_2, param_3)
  unsigned char * param_1;
  void **param_2;
  uint param_3;
{
  operator__(param_1,(unsigned char *)param_2);
  return;
}

/* std__type_info____do_upcast @ 0x97c1816c (8 bytes) */
int std__type_info____do_upcast(param_1, param_2)
  unsigned char * param_1;
  void **param_2;
{
  return 0;
}

/* __cxxabiv1____class_type_info_____class_type_info @ 0x97c18174 (8 bytes) */
int __cxxabiv1____class_type_info_____class_type_info(this)
  unsigned char * this;
{
  ~__class_type_info(this);
  return;
}

/* __cxxabiv1____class_type_info_____class_type_info_97c1817c @ 0x97c1817c (8 bytes) */
int __cxxabiv1____class_type_info_____class_type_info_97c1817c(this)
  unsigned char * this;
{
  ~__class_type_info(this);
  return;
}

/* __cxxabiv1____class_type_info_____class_type_info_97c18184 @ 0x97c18184 (8 bytes) */
int __cxxabiv1____class_type_info_____class_type_info_97c18184(this)
  unsigned char * this;
{
  ~__class_type_info(this);
  return;
}

/* __cxxabiv1____class_type_info_____class_type_info_97c1818c @ 0x97c1818c (104 bytes) */
int __cxxabiv1____class_type_info_____class_type_info_97c1818c(this)
  unsigned char * this;
{
  uint in_r4;
  
  *(int *)this = DAT_a7b7c020 + 8;
  ((int (*)())std__type_info___type_info)((unsigned char *)this);
  if ((in_r4 & 1) != 0) {
    operator_delete(this);
    return;
  }
  return;
}

/* __cxxabiv1____si_class_type_info_____si_class_type_info @ 0x97c181f4 (8 bytes) */
int __cxxabiv1____si_class_type_info_____si_class_type_info(this)
  unsigned char * this;
{
  ~__si_class_type_info(this);
  return;
}

/* __cxxabiv1____si_class_type_info_____si_class_type_info_97c181fc @ 0x97c181fc (8 bytes) */
int __cxxabiv1____si_class_type_info_____si_class_type_info_97c181fc(this)
  unsigned char * this;
{
  ~__si_class_type_info(this);
  return;
}

/* __cxxabiv1____si_class_type_info_____si_class_type_info_97c18204 @ 0x97c18204 (8 bytes) */
int __cxxabiv1____si_class_type_info_____si_class_type_info_97c18204(this)
  unsigned char * this;
{
  ~__si_class_type_info(this);
  return;
}

/* __cxxabiv1____si_class_type_info_____si_class_type_info_97c1820c @ 0x97c1820c (104 bytes) */
int __cxxabiv1____si_class_type_info_____si_class_type_info_97c1820c(this)
  unsigned char * this;
{
  uint in_r4;
  
  *(int *)this = DAT_a7b7c01c + 8;
  __class_type_info_____class_type_info((unsigned char *)this);
  if ((in_r4 & 1) != 0) {
    operator_delete(this);
    return;
  }
  return;
}

/* __cxxabiv1____vmi_class_type_info_____vmi_class_type_info @ 0x97c18274 (8 bytes) */
int __cxxabiv1____vmi_class_type_info_____vmi_class_type_info(this)
  unsigned char * this;
{
  ~__vmi_class_type_info(this);
  return;
}

/* __cxxabiv1____vmi_class_type_info_____vmi_class_type_info_97c1827c @ 0x97c1827c (8 bytes) */
int __cxxabiv1____vmi_class_type_info_____vmi_class_type_info_97c1827c(this)
  unsigned char * this;
{
  ~__vmi_class_type_info(this);
  return;
}

/* __cxxabiv1____vmi_class_type_info_____vmi_class_type_info_97c18284 @ 0x97c18284 (8 bytes) */
int __cxxabiv1____vmi_class_type_info_____vmi_class_type_info_97c18284(this)
  unsigned char * this;
{
  ~__vmi_class_type_info(this);
  return;
}

/* __cxxabiv1____vmi_class_type_info_____vmi_class_type_info_97c1828c @ 0x97c1828c (104 bytes) */
int __cxxabiv1____vmi_class_type_info_____vmi_class_type_info_97c1828c(this)
  unsigned char * this;
{
  uint in_r4;
  
  *(int *)this = DAT_a7b7c018 + 8;
  __class_type_info_____class_type_info((unsigned char *)this);
  if ((in_r4 & 1) != 0) {
    operator_delete(this);
    return;
  }
  return;
}

/* __cxxabiv1____class_type_info____do_catch @ 0x97c182f4 (124 bytes) */
int __cxxabiv1____class_type_info____do_catch(this, param_1, param_2, param_3)
  unsigned char * this;
  unsigned char * param_1;
  void **param_2;
  uint param_3;
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = ((int (*)())std__type_info__operator__)((unsigned char *)this,param_1);
  uVar2 = 1;
  if ((iVar1 == 0) && (uVar2 = 0, param_3 < 4)) {
                    
                    
    uVar2 = (**(code **)(*(int *)param_1 + 0x14))(param_1,this,param_2);
    return uVar2;
  }
  return uVar2;
}

/* __cxxabiv1____class_type_info____do_upcast @ 0x97c18370 (120 bytes) */
int __cxxabiv1____class_type_info____do_upcast(this, param_1, param_2)
  unsigned char * this;
  unsigned char * param_1;
  void **param_2;
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
  (**(code **)(*(int *)this + 0x18))(this,param_1,*param_2,&local_20);
  bVar1 = (local_1c & 6) == 6;
  if (bVar1) {
    *param_2 = local_20;
  }
  return bVar1;
}

/* __cxxabiv1____class_type_info____do_find_public_src @ 0x97c183e8 (20 bytes) */
int __cxxabiv1____class_type_info____do_find_public_src(this, param_1, param_2, param_3, param_4)
  unsigned char * this;
  int param_1;
  void *param_2;
  unsigned char * param_3;
  void *param_4;
{
  if (param_4 == param_2) {
    return 6;
  }
  return 1;
}

/* __cxxabiv1____si_class_type_info____do_find_public_src @ 0x97c183fc (136 bytes) */
int __cxxabiv1____si_class_type_info____do_find_public_src(this, param_1, param_2, param_3, param_4)
  unsigned char * this;
  int param_1;
  void *param_2;
  unsigned char * param_3;
  void *param_4;
{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_4 == param_2) &&
     (iVar1 = ((int (*)())std__type_info__operator__)((unsigned char *)this,(unsigned char *)param_3), iVar1 != 0)) {
    return 6;
  }
                    
                    
  uVar2 = (**(code **)(**(int **)(this + 8) + 0x20))
                    (*(int **)(this + 8),param_1,param_2,param_3,param_4);
  return uVar2;
}

/* __cxxabiv1____vmi_class_type_info____do_find_public_src @ 0x97c18484 (248 bytes) */
int __cxxabiv1____vmi_class_type_info____do_find_public_src(this, param_1, param_2, param_3, param_4)
  unsigned char * this;
  int param_1;
  void *param_2;
  unsigned char * param_3;
  void *param_4;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  unsigned char * p_Var4;
  
  if ((param_2 == param_4) &&
     (iVar3 = ((int (*)())std__type_info__operator__)((unsigned char *)this,(unsigned char *)param_3), iVar3 != 0)) {
    return 6;
  }
  if (*(int *)(this + 0xc) != 0) {
    p_Var4 = this + (*(int *)(this + 0xc) + -1) * 8;
    do {
      uVar2 = *(uint *)(p_Var4 + 0x14);
      if ((uVar2 & 2) != 0) {
        iVar3 = (int)uVar2 >> 8;
        bVar1 = (uVar2 & 1) == 0;
        if ((bVar1) || (param_1 != -3)) {
          if (!bVar1) {
            iVar3 = *(int *)(*(int *)param_2 + iVar3);
          }
          uVar2 = (**(code **)(**(int **)(p_Var4 + 0x10) + 0x20))
                            (*(int **)(p_Var4 + 0x10),param_1,(int)param_2 + iVar3,param_3,param_4);
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

/* __cxxabiv1____class_type_info____do_dyncast @ 0x97c1857c (128 bytes) */
int __cxxabiv1____class_type_info____do_dyncast(this, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  unsigned char * this;
  undefined4 param_2;
  int param_3;
  unsigned char * param_4;
  int param_5;
  unsigned char * param_6;
  int param_7;
  int *param_8;
{
  int iVar1;
  
  if ((param_5 == param_7) &&
     (iVar1 = ((int (*)())std__type_info__operator__)((unsigned char *)this,param_6), iVar1 != 0)) {
    param_8[2] = param_3;
  }
  else {
    iVar1 = ((int (*)())std__type_info__operator__)((unsigned char *)this,param_4);
    if (iVar1 != 0) {
      *param_8 = param_5;
      param_8[3] = 1;
      param_8[1] = param_3;
    }
  }
  return 0;
}

