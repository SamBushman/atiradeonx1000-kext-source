#include "decls.h"

/* std__bad_cast___bad_cast_97c18044 @ 0x97c18044 (88 bytes) */
int std__bad_cast___bad_cast_97c18044(this)
  unsigned char * this;
{
  uint in_r4;
  
  *(int *)this = DAT_a7b7c028 + 8;
  ((int (*)())std__exception___exception)((unsigned char *)this);
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
  ((int (*)())std__exception___exception)((unsigned char *)this);
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
  std__type_info___type_info((unsigned char *)this);
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

/* __cxxabiv1____si_class_type_info____do_dyncast @ 0x97c185fc (244 bytes) */
int __cxxabiv1____si_class_type_info____do_dyncast(this, param_1, param_3, param_4, param_5, param_6, param_7, param_8)
  unsigned char * this;
  int param_1;
  int param_3;
  unsigned char * param_4;
  int param_5;
  unsigned char * param_6;
  int param_7;
  int *param_8;
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = ((int (*)())std__type_info__operator__)((unsigned char *)this,param_4);
  if (iVar1 == 0) {
    if ((param_5 == param_7) &&
       (iVar1 = ((int (*)())std__type_info__operator__)((unsigned char *)this,param_6), iVar1 != 0)) {
      param_8[2] = param_3;
      return 0;
    }
                    
                    
    uVar2 = (**(code **)(**(int **)(this + 8) + 0x1c))
                      (*(int **)(this + 8),param_1,param_3,param_4,param_5,param_6,param_7,param_8);
    return uVar2;
  }
  param_8[1] = param_3;
  *param_8 = param_5;
  if (param_1 < 0) {
    if (param_1 != -2) {
      return 0;
    }
  }
  else {
    iVar1 = 6;
    if (param_5 + param_1 == param_7) goto LAB_97c1866c;
  }
  iVar1 = 1;
LAB_97c1866c:
  param_8[3] = iVar1;
  return 0;
}

/* __cxxabiv1____vmi_class_type_info____do_dyncast @ 0x97c186f0 (1092 bytes) */
int __cxxabiv1____vmi_class_type_info____do_dyncast(this, param_1, param_3, param_4, param_5, param_6, param_7, param_8)
  unsigned char * this;
  int param_1;
  uint param_3;
  unsigned char * param_4;
  int *param_5;
  unsigned char * param_6;
  int *param_7;
  int *param_8;
{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  unsigned char * p_Var9;
  int local_60;
  uint local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  
  if ((param_8[4] & 0x10U) != 0) {
    param_8[4] = *(int *)(this + 8);
  }
  if ((param_5 == param_7) &&
     (iVar6 = ((int (*)())std__type_info__operator__)((unsigned char *)this,param_6), iVar6 != 0)) {
    param_8[2] = param_3;
    return 0;
  }
  iVar6 = ((int (*)())std__type_info__operator__)((unsigned char *)this,param_4);
  if (iVar6 == 0) {
    iVar6 = *(int *)(this + 0xc) + -1;
    if (*(int *)(this + 0xc) == 0) {
      return 0;
    }
    bVar1 = param_1 != -2;
    p_Var9 = this + iVar6 * 8 + 0x10;
    uVar8 = 0;
    do {
      local_50 = param_8[4];
      local_54 = 0;
      local_60 = 0;
      local_5c = 0;
      local_58 = 0;
      uVar3 = *(uint *)(p_Var9 + 4);
      iVar4 = (int)uVar3 >> 8;
      uVar7 = param_3;
      if ((uVar3 & 1) != 0) {
        uVar7 = param_3 | 1;
        iVar4 = *(int *)(*param_5 + iVar4);
      }
      if ((uVar3 & 2) == 0) {
        if ((bVar1) || (uVar3 = uVar8, (local_50 & 3) != 0)) {
          uVar7 = uVar7 & 0xfffffffd;
          goto LAB_97c18848;
        }
      }
      else {
LAB_97c18848:
        uVar3 = (**(code **)(**(int **)p_Var9 + 0x1c))
                          (*(int **)p_Var9,param_1,uVar7,param_4,(int)param_5 + iVar4,param_6,
                           param_7,&local_60);
        uVar7 = local_54;
        uVar5 = param_8[2];
        param_8[2] = uVar5 | local_58;
        if ((local_54 == 6) || (local_54 == 2)) {
          param_8[3] = local_54;
          *param_8 = local_60;
          param_8[1] = local_5c;
          return uVar3;
        }
        if (uVar8 == 0) {
          iVar4 = *param_8;
          if (iVar4 != 0) goto LAB_97c188fc;
          *param_8 = local_60;
          param_8[1] = local_5c;
          if (((local_60 != 0) && ((uVar5 | local_58) != 0)) &&
             (((*(uint *)(this + 8) ^ 1) & 1) != 0)) {
            return uVar3;
          }
        }
        else {
          iVar4 = *param_8;
LAB_97c188fc:
          if ((iVar4 == 0) || (iVar4 != local_60)) {
            if (((iVar4 != 0 && local_60 != 0) || ((iVar4 != 0 && ((uVar3 & 1) != 0)))) ||
               ((uVar3 = uVar8, local_60 != 0 && ((uVar8 & 1) != 0)))) {
              uVar5 = param_8[3];
              if ((param_8[2] < 4) || (((param_8[2] & 1U) != 0 && ((param_8[4] & 2U) != 0)))) {
                if ((int)uVar5 < 1) {
                  if (((int)local_54 < 4) ||
                     (((local_54 & 1) != 0 && ((*(uint *)(this + 8) & 2) != 0)))) {
                    if (param_1 < 0) {
                      if (!bVar1) goto LAB_97c189e8;
                      uVar5 = (**(code **)(*(int *)param_4 + 0x20))
                                        (param_4,param_1,iVar4,param_6,param_7);
                    }
                    else {
                      uVar5 = 6;
                      if ((int *)(iVar4 + param_1) != param_7) {
LAB_97c189e8:
                        uVar5 = 1;
                      }
                    }
                  }
                  else {
                    uVar5 = 1;
                  }
                }
                if ((int)uVar7 < 1) {
                  if ((3 < (int)uVar5) && (((uVar5 & 1) == 0 || ((*(uint *)(this + 8) & 2) == 0))))
                  goto LAB_97c18a38;
                  if (param_1 < 0) {
                    if (!bVar1) goto LAB_97c18a60;
                    uVar7 = (**(code **)(*(int *)param_4 + 0x20))
                                      (param_4,param_1,local_60,param_6,param_7);
                  }
                  else {
                    uVar7 = 6;
                    if ((int *)(local_60 + param_1) != param_7) {
LAB_97c18a60:
                      uVar7 = 1;
                    }
                  }
                }
              }
              else {
                if (uVar5 == 0) {
                  uVar5 = 1;
                }
                if (local_54 == 0) {
LAB_97c18a38:
                  uVar7 = 1;
                }
              }
              if ((int)(uVar7 ^ uVar5) < 4) {
                if (3 < (int)(uVar7 & uVar5)) {
                  *param_8 = 0;
                  param_8[3] = 2;
                  return 1;
                }
                *param_8 = 0;
                param_8[3] = 1;
                uVar3 = 1;
              }
              else {
                uVar3 = uVar8;
                if (3 < (int)uVar7) {
                  uVar3 = 0;
                  *param_8 = local_60;
                  param_8[1] = local_5c;
                  uVar5 = uVar7;
                }
                param_8[3] = uVar5;
                if ((uVar5 & 2) != 0) {
                  return 0;
                }
                if ((uVar5 & 1) == 0) {
                  return 0;
                }
              }
            }
          }
          else {
            param_8[1] = param_8[1] | local_5c;
            uVar3 = uVar8;
          }
        }
        if (param_8[2] == 4) {
          return uVar3;
        }
      }
      bVar2 = iVar6 == 0;
      p_Var9 = p_Var9 + -8;
      iVar6 = iVar6 + -1;
      uVar8 = uVar3;
      if (bVar2) {
        return uVar3;
      }
    } while( true );
  }
  param_8[1] = param_3;
  *param_8 = (int)param_5;
  if (param_1 < 0) {
    if (param_1 != -2) {
      return 0;
    }
  }
  else {
    iVar6 = 6;
    if ((int *)((int)param_5 + param_1) == param_7) goto LAB_97c187a0;
  }
  iVar6 = 1;
LAB_97c187a0:
  param_8[3] = iVar6;
  return 0;
}

/* __cxxabiv1____class_type_info____do_upcast_97c18b34 @ 0x97c18b34 (84 bytes) */
int __cxxabiv1____class_type_info____do_upcast_97c18b34(this, param_1, param_2, param_3)
  unsigned char * this;
  unsigned char * param_1;
  void *param_2;
  unsigned char * param_3;
{
  int iVar1;
  
  iVar1 = ((int (*)())std__type_info__operator__)((unsigned char *)this,(unsigned char *)param_1);
  if (iVar1 != 0) {
    *(void **)param_3 = param_2;
    *(undefined4 *)(param_3 + 4) = 6;
    *(undefined4 *)(param_3 + 0xc) = 8;
  }
  return iVar1 != 0;
}

/* __cxxabiv1____si_class_type_info____do_upcast @ 0x97c18b88 (116 bytes) */
int __cxxabiv1____si_class_type_info____do_upcast(this, param_1, param_2, param_3)
  unsigned char * this;
  unsigned char * param_1;
  void *param_2;
  unsigned char * param_3;
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = __class_type_info____do_upcast((unsigned char *)this,param_1,param_2,param_3);
  if (iVar1 == 0) {
                    
                    
    uVar2 = (**(code **)(**(int **)(this + 8) + 0x18))(*(int **)(this + 8),param_1,param_2,param_3);
    return uVar2;
  }
  return 1;
}

/* __cxxabiv1____vmi_class_type_info____do_upcast @ 0x97c18bfc (556 bytes) */
int __cxxabiv1____vmi_class_type_info____do_upcast(this, param_1, param_2, param_3)
  unsigned char * this;
  unsigned char * param_1;
  void *param_2;
  unsigned char * param_3;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  unsigned char * ptVar4;
  void *pvVar5;
  uint uVar6;
  unsigned char * p_Var7;
  bool bVar8;
  int local_40;
  uint local_3c;
  uint local_38;
  unsigned char * local_34;
  
  iVar3 = __class_type_info____do_upcast((unsigned char *)this,param_1,param_2,param_3);
  bVar8 = true;
  if (iVar3 == 0) {
    uVar6 = *(uint *)(param_3 + 8);
    if ((uVar6 & 0x10) != 0) {
      uVar6 = *(uint *)(this + 8);
    }
    iVar3 = *(int *)(this + 0xc) + -1;
    if (*(int *)(this + 0xc) != 0) {
      p_Var7 = this + iVar3 * 8;
      do {
        uVar1 = *(uint *)(p_Var7 + 0x14);
        local_40 = 0;
        bVar8 = (uVar1 >> 1 & 1) != 0;
        local_3c = 0;
        iVar2 = (int)uVar1 >> 8;
        local_34 = (unsigned char *)0x0;
        if ((bVar8) || (((uVar6 ^ 1) & 1) == 0)) {
          pvVar5 = param_2;
          if (param_2 != (void *)0x0) {
            if ((uVar1 & 1) != 0) {
              iVar2 = *(int *)(*(int *)param_2 + iVar2);
            }
            pvVar5 = (void *)((int)param_2 + iVar2);
          }
          local_38 = uVar6;
          iVar2 = (**(code **)(**(int **)(p_Var7 + 0x10) + 0x18))
                            (*(int **)(p_Var7 + 0x10),param_1,pvVar5,&local_40);
          if (iVar2 != 0) {
            if ((local_34 == (unsigned char *)0x8) && ((uVar1 & 1) != 0)) {
              local_34 = *(unsigned char **)(p_Var7 + 0x10);
            }
            if ((3 < (int)local_3c) && (!bVar8)) {
              local_3c = local_3c & 0xfffffffd;
            }
            ptVar4 = *(unsigned char **)(param_3 + 0xc);
            if (ptVar4 == (unsigned char *)0x0) {
              *(uint *)(param_3 + 8) = local_38;
              *(int *)param_3 = local_40;
              *(unsigned char **)(param_3 + 0xc) = local_34;
              *(uint *)(param_3 + 4) = local_3c;
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
              if (*(int *)param_3 != local_40) {
                *(undefined4 *)(param_3 + 4) = 2;
                *(undefined4 *)param_3 = 0;
                return true;
              }
              if ((*(int *)param_3 == 0) &&
                 (((local_34 == (unsigned char *)0x8 || (ptVar4 == (unsigned char *)0x8)) ||
                  (iVar2 = ((int (*)())std__type_info__operator__)(local_34,ptVar4), iVar2 == 0)))) {
                *(undefined4 *)(param_3 + 4) = 2;
                return true;
              }
              *(uint *)(param_3 + 4) = *(uint *)(param_3 + 4) | local_3c;
            }
          }
        }
        bVar8 = iVar3 != 0;
        p_Var7 = p_Var7 + -8;
        iVar3 = iVar3 + -1;
      } while (bVar8);
    }
    bVar8 = *(int *)(param_3 + 4) != 0;
  }
  return bVar8;
}

/* ___dynamic_cast @ 0x97c18e28 (328 bytes) */
int ___dynamic_cast(param_1, param_2, param_3, param_4)
  int *param_1;
  undefined4 param_2;
  int *param_3;
  int param_4;
{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  undefined4 local_30;
  
  piVar1 = *(int **)(*param_1 + -4);
  local_38 = 0;
  local_34 = 0;
  local_30 = 0x10;
  local_40 = 0;
  local_3c = 0;
  (**(code **)(*piVar1 + 0x1c))
            (piVar1,param_4,6,param_3,(int)param_1 + *(int *)(*param_1 + -8),param_2,param_1,
             &local_40);
  iVar3 = 0;
  if ((((local_40 != 0) && (iVar3 = local_40, (local_34 & 6) != 6)) &&
      ((local_38 & local_3c & 6) != 6)) && (iVar3 = 0, (local_38 & 5) != 4)) {
    uVar2 = local_34;
    if (local_34 == 0) {
      if (param_4 < 0) {
        uVar2 = 0;
        if (param_4 != -2) {
          uVar2 = (**(code **)(*param_3 + 0x20))(param_3,param_4,local_40,param_2,param_1);
        }
      }
      else {
        uVar2 = 6;
        if ((int *)(local_40 + param_4) != param_1) {
          uVar2 = 0;
        }
      }
    }
    iVar3 = 0;
    if ((uVar2 & 6) == 6) {
      iVar3 = local_40;
    }
  }
  return iVar3;
}

/* std__exception___exception @ 0x97c18f70 (8 bytes) */
int std__exception___exception(this)
  unsigned char * this;
{
  ~exception(this);
  return;
}

/* std__exception___exception_97c18f78 @ 0x97c18f78 (8 bytes) */
int std__exception___exception_97c18f78(this)
  unsigned char * this;
{
  ~exception(this);
  return;
}

/* std__exception___exception_97c18f80 @ 0x97c18f80 (8 bytes) */
int std__exception___exception_97c18f80(this)
  unsigned char * this;
{
  ~exception(this);
  return;
}

/* std__exception___exception_97c18f88 @ 0x97c18f88 (72 bytes) */
int std__exception___exception_97c18f88(this)
  unsigned char * this;
{
  uint in_r4;
  
  *(int *)this = DAT_a7b7c034 + 8;
  if ((in_r4 & 1) != 0) {
    operator_delete(this);
  }
  return;
}

/* std__bad_exception___bad_exception @ 0x97c18fd0 (8 bytes) */
int std__bad_exception___bad_exception(this)
  unsigned char * this;
{
  ~bad_exception(this);
  return;
}

/* std__bad_exception___bad_exception_97c18fd8 @ 0x97c18fd8 (8 bytes) */
int std__bad_exception___bad_exception_97c18fd8(this)
  unsigned char * this;
{
  ~bad_exception(this);
  return;
}

/* std__bad_exception___bad_exception_97c18fe0 @ 0x97c18fe0 (8 bytes) */
int std__bad_exception___bad_exception_97c18fe0(this)
  unsigned char * this;
{
  ~bad_exception(this);
  return;
}

/* std__bad_exception___bad_exception_97c18fe8 @ 0x97c18fe8 (88 bytes) */
int std__bad_exception___bad_exception_97c18fe8(this)
  unsigned char * this;
{
  uint in_r4;
  
  *(int *)this = DAT_a7b7c030 + 8;
  exception___exception((unsigned char *)this);
  if ((in_r4 & 1) != 0) {
    operator_delete(this);
  }
  return;
}

/* std__exception__what @ 0x97c19040 (16 bytes) */
int std__exception__what(this)
  unsigned char * this;
{
  return *(undefined4 *)(*(int *)(*(int *)this + -4) + 4);
}

/* std__set_new_handler @ 0x97c19050 (100 bytes) */
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

/* std__bad_alloc___bad_alloc @ 0x97c190c4 (8 bytes) */
int std__bad_alloc___bad_alloc(this)
  unsigned char * this;
{
  ~bad_alloc(this);
  return;
}

/* std__bad_alloc___bad_alloc_97c190cc @ 0x97c190cc (8 bytes) */
int std__bad_alloc___bad_alloc_97c190cc(this)
  unsigned char * this;
{
  ~bad_alloc(this);
  return;
}

/* std__bad_alloc___bad_alloc_97c190d4 @ 0x97c190d4 (8 bytes) */
int std__bad_alloc___bad_alloc_97c190d4(this)
  unsigned char * this;
{
  ~bad_alloc(this);
  return;
}

/* std__bad_alloc___bad_alloc_97c190dc @ 0x97c190dc (88 bytes) */
int std__bad_alloc___bad_alloc_97c190dc(this)
  unsigned char * this;
{
  uint in_r4;
  
  *(int *)this = DAT_a7b7c03c + 8;
  ((int (*)())std__exception___exception)((unsigned char *)this);
  if ((in_r4 & 1) != 0) {
    operator_delete(this);
  }
  return;
}

/* ___cxa_free_exception @ 0x97c19218 (152 bytes) */
int ___cxa_free_exception(param_1)
  undefined4 *param_1;
{
  uint uVar1;
  
  if (((undefined4 *)0xa7b7e86f < param_1) && (param_1 < &_emergency_used)) {
    _pthread_mutex_lock((pthread_mutex_t *)&_emergency_mutex);
    uVar1 = (uint)(param_1 + 0x161205e4) >> 8 & 0x1f;
    _emergency_used = _emergency_used & (-2 << uVar1 | 0xfffffffeU >> 0x20 - uVar1);
    _pthread_mutex_unlock((pthread_mutex_t *)&_emergency_mutex);
    return;
  }
  _free(param_1 + -0x14);
  return;
}

/* __gxx_exception_cleanup @ 0x97c192b0 (88 bytes) */
#if 0   /* compile-failing as plain C: Ghidra text kept verbatim, see ledger status */
int __gxx_exception_cleanup(param_1, param_2)
  unsigned char param_1;
  unsigned char * param_2;
{
  unsigned char * extraout_r4;
  unsigned char * puVar1;
  
  puVar1 = &param_2[-2].private_2;
  if (_URC_FOREIGN_EXCEPTION_CAUGHT < param_1) {
    __cxxabiv1____terminate((unsigned char *)param_2[-2].reserved[2]);
    param_2 = extraout_r4;
  }
  if ((code *)puVar1[1] != (code *)0x0) {
    (*(code *)puVar1[1])(param_2 + 1);
  }
  ((int (*)())___cxa_free_exception)(param_2 + 1);
  return;
}
#endif

/* ___cxa_throw @ 0x97c19308 (216 bytes) */
int ___cxa_throw(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
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
  iVar5 = ___cxa_get_globals();
  *(int *)(iVar5 + 4) = *(int *)(iVar5 + 4) + 1;
  __Unwind_RaiseException((unsigned char *)(param_1 + -0x20));
  ___cxa_begin_catch((unsigned char *)(param_1 + -0x20));
  std__terminate();
  piVar6 = (int *)___cxa_get_globals();
  iVar5 = *piVar6;
  if (iVar5 != 0) {
    *(int *)(iVar5 + 0x14) = -*(int *)(iVar5 + 0x14);
    __Unwind_RaiseException((unsigned char *)(iVar5 + 0x30));
    ___cxa_begin_catch((unsigned char *)(iVar5 + 0x30));
  }
  uVar7 = std__terminate();
  uVar4 = 0;
  if (uVar7 != 0xff) {
    uVar7 = uVar7 & 7;
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

/* size_of_encoded_value @ 0x97c193e0 (120 bytes) */
int size_of_encoded_value(param_1)
  int param_1;
{
  byte bVar1;
  undefined4 uVar2;
  undefined3 in_register_0000000c;
  
  uVar2 = 0;
  if (CONCAT31(in_register_0000000c,param_1) != 0xff) {
    bVar1 = param_1 & 7;
    uVar2 = 2;
    if (bVar1 != 2) {
      if (bVar1 < 3) {
        if ((param_1 & 7) != 0) {
LAB_97c19440:
                    
          _abort();
        }
        uVar2 = 4;
      }
      else {
        uVar2 = 4;
        if (bVar1 != 3) {
          if (bVar1 != 4) goto LAB_97c19440;
          uVar2 = 8;
        }
      }
    }
  }
  return uVar2;
}

/* base_of_encoded_value @ 0x97c19458 (172 bytes) */
int base_of_encoded_value(param_1, param_2)
  int param_1;
  unsigned char * param_2;
{
  bool bVar1;
  byte bVar2;
  undefined3 in_register_0000000c;
  unsigned char uVar3;
  
  if (CONCAT31(in_register_0000000c,param_1) != 0xff) {
    bVar2 = param_1 & 0x70;
    if (bVar2 == 0x20) {
      uVar3 = __Unwind_GetTextRelBase(param_2);
      return uVar3;
    }
    if (bVar2 < 0x21) {
      if ((param_1 & 0x70) == 0) {
        return 0;
      }
      bVar1 = bVar2 == 0x10;
    }
    else {
      if (bVar2 == 0x40) {
        uVar3 = __Unwind_GetRegionStart(param_2);
        return uVar3;
      }
      if (bVar2 < 0x41) {
        if (bVar2 == 0x30) {
          uVar3 = __Unwind_GetDataRelBase(param_2);
          return uVar3;
        }
        goto LAB_97c194ec;
      }
      bVar1 = bVar2 == 0x50;
    }
    if (!bVar1) {
LAB_97c194ec:
                    
      _abort();
    }
  }
  return 0;
}

/* read_uleb128 @ 0x97c19504 (48 bytes) */
int read_uleb128(param_1, param_2)
  uchar *param_1;
  uint *param_2;
{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = 0;
  uVar4 = 0;
  do {
    bVar1 = *param_1;
    param_1 = param_1 + 1;
    uVar2 = uVar3 & 0x3f;
    uVar3 = uVar3 + 7;
    uVar4 = uVar4 | (bVar1 & 0x7f) << uVar2;
  } while ((bVar1 & 0x80) != 0);
  *param_2 = uVar4;
  return;
}

/* read_sleb128 @ 0x97c19534 (76 bytes) */
int read_sleb128(param_1, param_2)
  uchar *param_1;
  int *param_2;
{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = 0;
  uVar4 = 0;
  do {
    bVar1 = *param_1;
    param_1 = param_1 + 1;
    uVar2 = uVar3 & 0x3f;
    uVar3 = uVar3 + 7;
    uVar4 = uVar4 | (bVar1 & 0x7f) << uVar2;
  } while ((bVar1 & 0x80) != 0);
  if ((uVar3 < 0x20) && ((bVar1 & 0x40) != 0)) {
    uVar4 = uVar4 | -1 << (uVar3 & 0x3f);
  }
  *param_2 = uVar4;
  return;
}

/* read_encoded_value_with_base @ 0x97c19580 (312 bytes) */
int read_encoded_value_with_base(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  uchar *param_3;
  uint *param_4;
{
  undefined3 in_register_0000000c;
  uint *puVar1;
  uint *local_30;
  uint *local_2c [6];
  
  if (CONCAT31(in_register_0000000c,param_1) == 0x50) {
    local_2c[0] = (uint *)((uint)(param_3 + 3) & 0xfffffffc);
    puVar1 = local_2c[0] + 1;
    goto LAB_97c196cc;
  }
  switch(param_1 & 0xf) {
  case 0:
  case 3:
  case 0xb:
    local_2c[0] = *(uint **)param_3;
    puVar1 = (uint *)(param_3 + 4);
    break;
  case 1:
    puVar1 = (uint *)((int (*)())read_uleb128)(param_3,(uint *)&local_30);
    local_2c[0] = local_30;
    break;
  case 2:
    local_2c[0] = (uint *)(uint)*(ushort *)param_3;
    goto LAB_97c19658;
  case 4:
  case 0xc:
    puVar1 = (uint *)(param_3 + 8);
    local_2c[0] = (uint *)((uint)param_3[7] |
                          (uint)param_3[6] << 8 |
                          (uint)param_3[5] << 0x10 | (uint)param_3[4] << 0x18);
    break;
  default:
                    
    _abort();
  case 9:
    puVar1 = (uint *)((int (*)())read_sleb128)(param_3,(int *)local_2c);
    break;
  case 10:
    local_2c[0] = (uint *)(int)*(short *)param_3;
LAB_97c19658:
    puVar1 = (uint *)(param_3 + 2);
  }
  if (local_2c[0] != (uint *)0x0) {
    if ((param_1 & 0x70) == 0x10) {
      param_2 = (uint)param_3;
    }
    local_2c[0] = (uint *)((int)local_2c[0] + param_2);
    if ((param_1 & 0x80) != 0) {
LAB_97c196cc:
      local_2c[0] = (uint *)*local_2c[0];
    }
  }
  *param_4 = (uint)local_2c[0];
  return puVar1;
}

/* parse_lsda_header @ 0x97c196ec (216 bytes) */
int parse_lsda_header(param_1, param_2, param_3)
  unsigned char * param_1;
  uchar *param_2;
  unsigned char * param_3;
{
  uchar uVar1;
  unsigned char uVar2;
  uint uVar3;
  int iVar4;
  unsigned char * plVar5;
  unsigned char * plVar6;
  uint local_30 [7];
  
  if (param_1 == (unsigned char *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = __Unwind_GetRegionStart(param_1);
  }
  *(unsigned char *)param_3 = uVar2;
  uVar1 = *param_2;
  plVar5 = (unsigned char *)(param_2 + 1);
  if (uVar1 == 0xff) {
    *(unsigned char *)(param_3 + 4) = uVar2;
  }
  else {
    uVar3 = ((int (*)())base_of_encoded_value)(uVar1,param_1);
    plVar5 = (unsigned char *)
             ((int (*)())read_encoded_value_with_base)(uVar1,uVar3,(uchar *)plVar5,(uint *)(param_3 + 4));
  }
  plVar6 = plVar5 + 1;
  param_3[0x14] = *plVar5;
  plVar5 = (unsigned char *)0x0;
  if (param_3[0x14] != 0xff) {
    plVar6 = (unsigned char *)((int (*)())read_uleb128)((uchar *)plVar6,local_30);
    plVar5 = plVar6 + local_30[0];
  }
  *(unsigned char **)(param_3 + 0xc) = plVar5;
  param_3[0x15] = *plVar6;
  iVar4 = ((int (*)())read_uleb128)((uchar *)(plVar6 + 1),local_30);
  *(uint *)(param_3 + 0x10) = iVar4 + local_30[0];
  return;
}

/* get_ttype_entry @ 0x97c197c4 (84 bytes) */
int get_ttype_entry(param_1, param_2)
  unsigned char * param_1;
  uint param_2;
{
  int iVar1;
  uint local_20 [4];
  
  iVar1 = ((int (*)())size_of_encoded_value)((uchar)param_1[0x14]);
  ((int (*)())read_encoded_value_with_base)((uchar)param_1[0x14],*(uint *)(param_1 + 8),
             (uchar *)(*(int *)(param_1 + 0xc) - param_2 * iVar1),local_20);
  return local_20[0];
}

/* get_adjusted_ptr @ 0x97c19818 (152 bytes) */
int get_adjusted_ptr(param_1, param_2, param_3)
  unsigned char * param_1;
  unsigned char * param_2;
  void **param_3;
{
  int iVar1;
  undefined4 *local_20 [4];
  
  local_20[0] = *param_3;
  iVar1 = (**(code **)(*(int *)param_2 + 8))(param_2);
  if (iVar1 != 0) {
    local_20[0] = (undefined4 *)*local_20[0];
  }
  iVar1 = (**(code **)(*(int *)param_1 + 0x10))(param_1,param_2,local_20,1);
  if (iVar1 != 0) {
    *param_3 = local_20[0];
  }
  return iVar1 != 0;
}

/* check_exception_spec @ 0x97c198b0 (124 bytes) */
int check_exception_spec(param_1, param_2, param_3, param_4)
  unsigned char * param_1;
  unsigned char * param_2;
  void *param_3;
  int param_4;
{
  unsigned char * ptVar1;
  int iVar2;
  uchar *puVar3;
  void *pvStack00000020;
  uint local_20 [4];
  
  puVar3 = (uchar *)((*(int *)(param_1 + 0xc) - param_4) + -1);
  pvStack00000020 = param_3;
  do {
    puVar3 = (uchar *)((int (*)())read_uleb128)(puVar3,local_20);
    if (local_20[0] == 0) {
      return 0;
    }
    ptVar1 = (unsigned char *)((int (*)())get_ttype_entry)(param_1,local_20[0]);
    iVar2 = ((int (*)())get_adjusted_ptr)(ptVar1,param_2,&STACKARG(0x20));
  } while (iVar2 == 0);
  return 1;
}

