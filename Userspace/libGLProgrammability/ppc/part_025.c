#include "decls.h"

/* __ZNK10__cxxabiv120__si_class_type_info12__do_dyncastEiNS_17__class_type_info10__sub_kindEPKS1_PKvS4_S6_RNS1_16__dyncast_resultE @ 0x97c185fc (244 bytes) */
int __ZNK10__cxxabiv120__si_class_type_info12__do_dyncastEiNS_17__class_type_info10__sub_kindEPKS1_PKvS4_S6_RNS1_16__dyncast_resultE(this, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  void *this;
  int param_2;
  int param_3;
  unsigned char * param_4;
  int param_5;
  unsigned char * param_6;
  int param_7;
  int *param_8;
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = __ZNKSt9type_infoeqERKS_(this,param_4);
  if (iVar1 == 0) {
    if ((param_5 == param_7) && (iVar1 = __ZNKSt9type_infoeqERKS_(this,param_6), iVar1 != 0)) {
      param_8[2] = param_3;
      return 0;
    }
                    
                    
    uVar2 = (**(code **)(**(int **)((int)this + 8) + 0x1c))
                      (*(int **)((int)this + 8),param_2,param_3,param_4,param_5,param_6,param_7,
                       param_8);
    return uVar2;
  }
  param_8[1] = param_3;
  *param_8 = param_5;
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
  param_8[3] = iVar1;
  return 0;
}

/* __cxxabiv1____vmi_class_type_info____do_dyncast @ 0x97c186f0 (1092 bytes) */
int __cxxabiv1____vmi_class_type_info____do_dyncast(this, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  unsigned char * this;
  int param_2;
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
  if ((param_5 == param_7) && (iVar6 = __ZNKSt9type_infoeqERKS_(this,param_6), iVar6 != 0)) {
    param_8[2] = param_3;
    return 0;
  }
  iVar6 = __ZNKSt9type_infoeqERKS_(this,param_4);
  if (iVar6 == 0) {
    iVar6 = *(int *)(this + 0xc) + -1;
    if (*(int *)(this + 0xc) == 0) {
      return 0;
    }
    bVar1 = param_2 != -2;
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
                          (*(int **)p_Var9,param_2,uVar7,param_4,(int)param_5 + iVar4,param_6,
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
                    if (param_2 < 0) {
                      if (!bVar1) goto LAB_97c189e8;
                      uVar5 = (**(code **)(*(int *)param_4 + 0x20))
                                        (param_4,param_2,iVar4,param_6,param_7);
                    }
                    else {
                      uVar5 = 6;
                      if ((int *)(iVar4 + param_2) != param_7) {
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
                  if (param_2 < 0) {
                    if (!bVar1) goto LAB_97c18a60;
                    uVar7 = (**(code **)(*(int *)param_4 + 0x20))
                                      (param_4,param_2,local_60,param_6,param_7);
                  }
                  else {
                    uVar7 = 6;
                    if ((int *)(local_60 + param_2) != param_7) {
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
  if (param_2 < 0) {
    if (param_2 != -2) {
      return 0;
    }
  }
  else {
    iVar6 = 6;
    if ((int *)((int)param_5 + param_2) == param_7) goto LAB_97c187a0;
  }
  iVar6 = 1;
LAB_97c187a0:
  param_8[3] = iVar6;
  return 0;
}

/* __ZNK10__cxxabiv117__class_type_info11__do_upcastEPKS0_PKvRNS0_15__upcast_resultE @ 0x97c18b34 (84 bytes) */
int __ZNK10__cxxabiv117__class_type_info11__do_upcastEPKS0_PKvRNS0_15__upcast_resultE(this, param_2, param_3, param_4)
  void *this;
  unsigned char * param_2;
  void *param_3;
  unsigned char * param_4;
{
  int iVar1;
  
  iVar1 = __ZNKSt9type_infoeqERKS_(this,(unsigned char *)param_2);
  if (iVar1 != 0) {
    *(void **)param_4 = param_3;
    *(undefined4 *)(param_4 + 4) = 6;
    *(undefined4 *)(param_4 + 0xc) = 8;
  }
  return iVar1 != 0;
}

/* __ZNK10__cxxabiv120__si_class_type_info11__do_upcastEPKNS_17__class_type_infoEPKvRNS1_15__upcast_resultE @ 0x97c18b88 (116 bytes) */
int __ZNK10__cxxabiv120__si_class_type_info11__do_upcastEPKNS_17__class_type_infoEPKvRNS1_15__upcast_resultE(this, param_2, param_3, param_4)
  void *this;
  unsigned char * param_2;
  void *param_3;
  unsigned char * param_4;
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = ((int (*)())__ZNK10__cxxabiv117__class_type_info11__do_upcastEPKS0_PKvRNS0_15__upcast_resultE)(this,param_2,param_3,param_4);
  if (iVar1 == 0) {
                    
                    
    uVar2 = (**(code **)(**(int **)((int)this + 8) + 0x18))
                      (*(int **)((int)this + 8),param_2,param_3,param_4);
    return uVar2;
  }
  return 1;
}

/* __cxxabiv1____vmi_class_type_info____do_upcast @ 0x97c18bfc (556 bytes) */
int __cxxabiv1____vmi_class_type_info____do_upcast(this, param_2, param_3, param_4)
  unsigned char * this;
  unsigned char * param_2;
  void *param_3;
  unsigned char * param_4;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  unsigned char * ptVar4;
  void *a2;
  uint uVar5;
  unsigned char * p_Var6;
  bool bVar7;
  int local_40;
  uint local_3c;
  uint local_38;
  void *local_34;
  
  iVar3 = ((int (*)())__ZNK10__cxxabiv117__class_type_info11__do_upcastEPKS0_PKvRNS0_15__upcast_resultE)(this,param_2,param_3,param_4);
  bVar7 = true;
  if (iVar3 == 0) {
    uVar5 = *(uint *)(param_4 + 8);
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
          a2 = param_3;
          if (param_3 != (void *)0x0) {
            if ((uVar1 & 1) != 0) {
              iVar2 = *(int *)(*(int *)param_3 + iVar2);
            }
            a2 = (void *)((int)param_3 + iVar2);
          }
          local_38 = uVar5;
          iVar2 = (**(code **)(**(int **)(p_Var6 + 0x10) + 0x18))
                            (*(int **)(p_Var6 + 0x10),param_2,a2,&local_40);
          if (iVar2 != 0) {
            if ((local_34 == (void *)0x8) && ((uVar1 & 1) != 0)) {
              local_34 = *(void **)(p_Var6 + 0x10);
            }
            if ((3 < (int)local_3c) && (!bVar7)) {
              local_3c = local_3c & 0xfffffffd;
            }
            ptVar4 = *(unsigned char **)(param_4 + 0xc);
            if (ptVar4 == (unsigned char *)0x0) {
              *(uint *)(param_4 + 8) = local_38;
              *(int *)param_4 = local_40;
              *(void **)(param_4 + 0xc) = local_34;
              *(uint *)(param_4 + 4) = local_3c;
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
              if (*(int *)param_4 != local_40) {
                *(undefined4 *)(param_4 + 4) = 2;
                *(undefined4 *)param_4 = 0;
                return true;
              }
              if ((*(int *)param_4 == 0) &&
                 (((local_34 == (void *)0x8 || (ptVar4 == (unsigned char *)0x8)) ||
                  (iVar2 = __ZNKSt9type_infoeqERKS_(local_34,ptVar4), iVar2 == 0)))) {
                *(undefined4 *)(param_4 + 4) = 2;
                return true;
              }
              *(uint *)(param_4 + 4) = *(uint *)(param_4 + 4) | local_3c;
            }
          }
        }
        bVar7 = iVar3 != 0;
        p_Var6 = p_Var6 + -8;
        iVar3 = iVar3 + -1;
      } while (bVar7);
    }
    bVar7 = *(int *)(param_4 + 4) != 0;
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
  int *a0;
  uint uVar1;
  int iVar2;
  int local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  undefined4 local_30;
  
  a0 = *(int **)(*param_1 + -4);
  local_38 = 0;
  local_34 = 0;
  local_30 = 0x10;
  local_40 = 0;
  local_3c = 0;
  (**(code **)(*a0 + 0x1c))
            (a0,param_4,6,param_3,(int)param_1 + *(int *)(*param_1 + -8),param_2,param_1,&local_40);
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
  ((int (*)())__ZNSt9exceptionD4Ev)(this,0);
  return;
}

/* __ZNSt9exceptionD1Ev @ 0x97c18f78 (8 bytes) */
int __ZNSt9exceptionD1Ev(this)
  void *this;
{
  ((int (*)())__ZNSt9exceptionD4Ev)(this,2);
  return;
}

/* __ZNSt9exceptionD0Ev @ 0x97c18f80 (8 bytes) */
int __ZNSt9exceptionD0Ev(this)
  void *this;
{
  ((int (*)())__ZNSt9exceptionD4Ev)(this,3);
  return;
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
  ((int (*)())__ZNSt13bad_exceptionD4Ev)(this,0);
  return;
}

/* __ZNSt13bad_exceptionD1Ev @ 0x97c18fd8 (8 bytes) */
int __ZNSt13bad_exceptionD1Ev(this)
  void *this;
{
  ((int (*)())__ZNSt13bad_exceptionD4Ev)(this,2);
  return;
}

/* __ZNSt13bad_exceptionD0Ev @ 0x97c18fe0 (8 bytes) */
int __ZNSt13bad_exceptionD0Ev(this)
  void *this;
{
  ((int (*)())__ZNSt13bad_exceptionD4Ev)(this,3);
  return;
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
  ((int (*)())__ZNSt9bad_allocD4Ev)(this,0);
  return;
}

/* __ZNSt9bad_allocD1Ev @ 0x97c190cc (8 bytes) */
int __ZNSt9bad_allocD1Ev(this)
  void *this;
{
  ((int (*)())__ZNSt9bad_allocD4Ev)(this,2);
  return;
}

/* __ZNSt9bad_allocD0Ev @ 0x97c190d4 (8 bytes) */
int __ZNSt9bad_allocD0Ev(this)
  void *this;
{
  ((int (*)())__ZNSt9bad_allocD4Ev)(this,3);
  return;
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
  uint uVar4;
  
  puVar3 = _malloc(param_1 + 0x50U);
  if (puVar3 == (undefined *)0x0) {
    _pthread_mutex_lock((pthread_mutex_t *)&_emergency_mutex);
    uVar4 = 0;
    bVar1 = true;
    uVar2 = _emergency_used;
    if (param_1 + 0x50U < 0x101) {
      do {
        if ((uVar2 & 1) == 0) {
          _emergency_used = _emergency_used | 1 << (uVar4 & 0x3f);
          puVar3 = &_emergency_buffer + uVar4 * 0x100;
          bVar1 = puVar3 == (undefined *)0x0;
          break;
        }
        uVar4 = uVar4 + 1;
        uVar2 = uVar2 >> 1;
      } while (uVar4 < 2);
    }
    _pthread_mutex_unlock((pthread_mutex_t *)&_emergency_mutex);
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
int __gxx_exception_cleanup(param_1, param_2)
  unsigned char param_1;
  _Unwind_Exception *param_2;
{
  _Unwind_Exception *extraout_r4;
  unsigned char * puVar1;
  
  puVar1 = &param_2[-2].private_2;
  if (_URC_FOREIGN_EXCEPTION_CAUGHT < param_1) {
    ((int (*)())__cxxabiv1____terminate)((unsigned char *)param_2[-2].reserved[2]);
    param_2 = extraout_r4;
  }
  if ((code *)puVar1[1] != (code *)0x0) {
    (*(code *)puVar1[1])(param_2 + 1);
  }
  ((int (*)())___cxa_free_exception)(param_2 + 1);
  return;
}

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
  iVar5 = ((int (*)())___cxa_get_globals)();
  *(int *)(iVar5 + 4) = *(int *)(iVar5 + 4) + 1;
  __Unwind_RaiseException((_Unwind_Exception *)(param_1 + -0x20));
  ((int (*)())___cxa_begin_catch)((_Unwind_Exception *)(param_1 + -0x20));
  ((int (*)())std__terminate)();
  piVar6 = (int *)((int (*)())___cxa_get_globals)();
  iVar5 = *piVar6;
  if (iVar5 != 0) {
    *(int *)(iVar5 + 0x14) = -*(int *)(iVar5 + 0x14);
    __Unwind_RaiseException((_Unwind_Exception *)(iVar5 + 0x30));
    ((int (*)())___cxa_begin_catch)((_Unwind_Exception *)(iVar5 + 0x30));
  }
  uVar7 = ((int (*)())std__terminate)();
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

/* __Z21size_of_encoded_valueh @ 0x97c193e0 (120 bytes) */
int __Z21size_of_encoded_valueh(param_1)
  uint param_1;
{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (param_1 != 0xff) {
    uVar1 = param_1 & 7;
    uVar2 = 2;
    if (uVar1 != 2) {
      if (uVar1 < 3) {
        if (uVar1 != 0) {
LAB_97c19440:
                    
          _abort();
        }
        uVar2 = 4;
      }
      else {
        uVar2 = 4;
        if (uVar1 != 3) {
          if (uVar1 != 4) goto LAB_97c19440;
          uVar2 = 8;
        }
      }
    }
  }
  return uVar2;
}

/* __Z21base_of_encoded_valuehP15_Unwind_Context @ 0x97c19458 (172 bytes) */
int __Z21base_of_encoded_valuehP15_Unwind_Context(param_1, param_2)
  uint param_1;
  unsigned char * param_2;
{
  bool bVar1;
  uint uVar2;
  unsigned char uVar3;
  
  if (param_1 != 0xff) {
    uVar2 = param_1 & 0x70;
    if (uVar2 == 0x20) {
      uVar3 = __Unwind_GetTextRelBase(param_2);
      return uVar3;
    }
    if (uVar2 < 0x21) {
      if (uVar2 == 0) {
        return 0;
      }
      bVar1 = uVar2 == 0x10;
    }
    else {
      if (uVar2 == 0x40) {
        uVar3 = ((int (*)())__Unwind_GetRegionStart)(param_2);
        return uVar3;
      }
      if (uVar2 < 0x41) {
        if (uVar2 == 0x30) {
          uVar3 = __Unwind_GetDataRelBase(param_2);
          return uVar3;
        }
        goto LAB_97c194ec;
      }
      bVar1 = uVar2 == 0x50;
    }
    if (!bVar1) {
LAB_97c194ec:
                    
      _abort();
    }
  }
  return 0;
}

/* __Z12read_uleb128PKhPj @ 0x97c19504 (48 bytes) */
int __Z12read_uleb128PKhPj(param_1, param_2)
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
  return param_1;
}

/* __Z12read_sleb128PKhPi @ 0x97c19534 (76 bytes) */
int __Z12read_sleb128PKhPi(param_1, param_2)
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
  return param_1;
}

/* __Z28read_encoded_value_with_basehjPKhPj @ 0x97c19580 (312 bytes) */
int __Z28read_encoded_value_with_basehjPKhPj(param_1, param_2, param_3, param_4)
  uint param_1;
  uint param_2;
  uchar *param_3;
  uint *param_4;
{
  uint *puVar1;
  uint *local_30;
  uint *local_2c [6];
  
  if (param_1 == 0x50) {
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
    puVar1 = (uint *)((int (*)())__Z12read_uleb128PKhPj)(param_3,(uint *)&local_30);
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
    puVar1 = (uint *)((int (*)())__Z12read_sleb128PKhPi)(param_3,(int *)local_2c);
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
  unsigned char uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  unsigned char * plVar5;
  unsigned char * plVar6;
  uint local_30 [7];
  
  if (param_1 == (unsigned char *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = ((int (*)())__Unwind_GetRegionStart)(param_1);
  }
  *(unsigned char *)param_3 = uVar1;
  uVar4 = (uint)*param_2;
  plVar5 = (unsigned char *)(param_2 + 1);
  if (uVar4 == 0xff) {
    *(unsigned char *)(param_3 + 4) = uVar1;
  }
  else {
    uVar2 = ((int (*)())__Z21base_of_encoded_valuehP15_Unwind_Context)(uVar4,param_1);
    plVar5 = (unsigned char *)
             ((int (*)())__Z28read_encoded_value_with_basehjPKhPj)(uVar4,uVar2,(uchar *)plVar5,(uint *)(param_3 + 4));
  }
  plVar6 = plVar5 + 1;
  param_3[0x14] = *plVar5;
  plVar5 = (unsigned char *)0x0;
  if (param_3[0x14] != 0xff) {
    plVar6 = (unsigned char *)((int (*)())__Z12read_uleb128PKhPj)((uchar *)plVar6,local_30);
    plVar5 = plVar6 + local_30[0];
  }
  *(unsigned char **)(param_3 + 0xc) = plVar5;
  param_3[0x15] = *plVar6;
  iVar3 = ((int (*)())__Z12read_uleb128PKhPj)((uchar *)(plVar6 + 1),local_30);
  *(uint *)(param_3 + 0x10) = iVar3 + local_30[0];
  return iVar3;
}

/* __Z15get_ttype_entryP16lsda_header_infoj @ 0x97c197c4 (84 bytes) */
int __Z15get_ttype_entryP16lsda_header_infoj(param_1, param_2)
  unsigned char * param_1;
  uint param_2;
{
  int iVar1;
  uint local_20 [4];
  
  iVar1 = ((int (*)())__Z21size_of_encoded_valueh)((uint)(byte)param_1[0x14]);
  ((int (*)())__Z28read_encoded_value_with_basehjPKhPj)((uint)(byte)param_1[0x14],*(uint *)(param_1 + 8),
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
    puVar3 = (uchar *)((int (*)())__Z12read_uleb128PKhPj)(puVar3,local_20);
    if (local_20[0] == 0) {
      return 0;
    }
    ptVar1 = (unsigned char *)((int (*)())__Z15get_ttype_entryP16lsda_header_infoj)(param_1,local_20[0]);
    iVar2 = ((int (*)())get_adjusted_ptr)(ptVar1,param_2,&STACKARG(0x20));
  } while (iVar2 == 0);
  return 1;
}

/* FUN_97c19934 @ 0x97c19934 (968 bytes) */
int FUN_97c19934(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  uint param_2;
  int param_3;
  int param_4;
  unsigned char param_5;
  unsigned char * param_6;
{
  bool bVar1;
  uchar *puVar2;
  uchar *puVar3;
  unsigned char uVar4;
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
  byte in_cr7;
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
  if (!(bool)(in_cr7 >> 1 & 1)) {
    return 3;
  }
  if (((param_2 == 6) && (param_3 == 0x474e5543)) && (param_4 == 0x432b2b00)) {
    new_value = *(unsigned char *)(param_5 - 0xc);
    new_value_00 = *(unsigned char *)(param_5 - 0x18);
    bVar1 = new_value == 0;
    goto LAB_97c19c74;
  }
  puVar2 = (uchar *)((int (*)())__Unwind_GetLanguageSpecificData)(param_6);
  if (puVar2 == (uchar *)0x0) {
    return 8;
  }
  new_value = 0;
  puVar3 = (uchar *)((int (*)())parse_lsda_header)(param_6,puVar2,(unsigned char *)&iStack_80);
  puVar10 = (uchar *)0x0;
  new_value_00 = 0;
  uStack_78 = ((int (*)())__Z21base_of_encoded_valuehP15_Unwind_Context)((uint)bStack_6c,param_6);
  uVar4 = __Unwind_GetIP(param_6);
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
      if ((iStack_80 + uStack_60 <= uVar4 - 1) &&
         (puVar3 = puVar6, uVar4 - 1 < iStack_80 + uStack_60 + uStack_5c)) {
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
        *(uchar **)(param_5 - 0x10) = puVar2;
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
  undefined *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  _Unwind_Exception *exception_object;
  code *pcVar6;
  unsigned char * p_Var7;
  int iVar8;
  uchar *puVar9;
  unsigned char alStack_40 [8];
  undefined4 uStack_38;
  
  ((int (*)())___cxa_begin_catch)(param_1);
  uStack_38 = *(undefined4 *)(param_1 + -0xc);
  puVar9 = *(uchar **)(param_1 + -0x10);
  iVar8 = *(int *)(param_1 + -0x18);
  p_Var7 = *(unsigned char **)(param_1 + -0x24);
  uVar3 = ((int (*)())__cxxabiv1____unexpected)(*(unsigned char **)(param_1 + -0x28));
  ((int (*)())___cxa_begin_catch)(uVar3);
  puVar4 = (undefined4 *)((int (*)())___cxa_get_globals_fast)();
  puVar4 = (undefined4 *)*puVar4;
  ((int (*)())parse_lsda_header)((unsigned char *)0x0,puVar9,alStack_40);
  iVar5 = ((int (*)())check_exception_spec)(alStack_40,(unsigned char *)*puVar4,puVar4 + 0x14,iVar8);
  if (iVar5 != 0) {
    ___cxa_rethrow();
  }
  puVar2 = PTR_typeinfo_a7b7c180;
  iVar5 = ((int (*)())check_exception_spec)(alStack_40,(unsigned char *)PTR_typeinfo_a7b7c180,(void *)0x0,iVar8);
  if (iVar5 != 0) {
    puVar4 = (undefined4 *)___cxa_allocate_exception(4);
    puVar1 = PTR___ZNSt13bad_exceptionD1Ev_a7b7c17c;
    *puVar4 = PTR_vtable_a7b7c184 + 8;
                    
    ((int (*)())___cxa_throw)(puVar4,puVar2,puVar1);
  }
  exception_object = (_Unwind_Exception *)((int (*)())__cxxabiv1____terminate)(p_Var7);
  ((int (*)())___cxa_end_catch)();
  ((int (*)())___cxa_end_catch)();
  pcVar6 = (code *)__Unwind_Resume(exception_object);
  (*pcVar6)();
                    
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
  int *piVar3;
  
  piVar3 = (int *)((int (*)())___cxa_get_globals)();
  iVar2 = *(int *)(param_1 + -0x1c);
  iVar1 = *piVar3;
  if (iVar2 < 0) {
    iVar2 = -iVar2;
  }
  *(int *)(param_1 + -0x1c) = iVar2 + 1;
  piVar3[1] = piVar3[1] + -1;
  if (param_1 + -0x30 != iVar1) {
    *(int *)(param_1 + -0x20) = iVar1;
    *piVar3 = param_1 + -0x30;
  }
  return *(undefined4 *)(param_1 + -8);
}

/* ___cxa_end_catch @ 0x97c19fec (144 bytes) */
int ___cxa_end_catch()
{
  int *piVar1;
  int iVar2;
  undefined4 extraout_r3;
  int iVar3;
  
  piVar1 = (int *)((int (*)())___cxa_get_globals_fast)();
  iVar2 = *piVar1;
  iVar3 = *(int *)(iVar2 + 0x14);
  if (iVar3 < 0) {
    iVar3 = iVar3 + 1;
    if (iVar3 == 0) {
      piVar1[1] = piVar1[1] + 1;
      *piVar1 = *(int *)(iVar2 + 0x10);
    }
  }
  else {
    iVar3 = iVar3 + -1;
    if (iVar3 == 0) {
      *piVar1 = *(int *)(iVar2 + 0x10);
      __Unwind_DeleteException((_Unwind_Exception *)(iVar2 + 0x30));
      return extraout_r3;
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
  int iVar1;
  
  iVar1 = ((int (*)())___cxa_get_globals)();
  return *(int *)(iVar1 + 4) != 0;
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
  undefined4 uVar1;
  
  if (_use_thread_key != 0) {
    uVar1 = __keymgr_get_per_thread_data(0xd);
    return uVar1;
  }
  return &_globals_static;
}

/* ___cxa_get_globals @ 0x97c1a0fc (220 bytes) */
int ___cxa_get_globals()
{
  int iVar1;
  undefined4 *puVar2;
  
  if ((_use_thread_key == 0) ||
     ((_use_thread_key < 0 && (((int (*)())__Z21get_globals_init_oncev)(), _use_thread_key == 0)))) {
    return (undefined4 *)&_globals_static;
  }
  iVar1 = __keymgr_get_per_thread_data(0xd);
  if (iVar1 != 0) {
    return (undefined4 *)iVar1;
  }
  puVar2 = _malloc(8);
  if (puVar2 != (undefined4 *)0x0) {
    if ((*(int *)(PTR_DAT_a7b7c190 + 8) == 0) ||
       (*(ushort *)(*(int *)(PTR_DAT_a7b7c190 + 8) + 4) < 4)) {
      __keymgr_set_per_thread_data(0xd,puVar2);
      goto LAB_97c1a1b4;
    }
    iVar1 = __keymgr_set_per_thread_data(0xd,puVar2);
    if (iVar1 == 0) goto LAB_97c1a1b4;
  }
  ((int (*)())std__terminate)();
LAB_97c1a1b4:
  puVar2[1] = 0;
  *puVar2 = 0;
  return puVar2;
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
  _fflush((FILE *)(puVar1 + 0xb0));
                    
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
int _size_of_encoded_value_97c1a2c8(param_1)
  uint param_1;
{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (param_1 != 0xff) {
    uVar1 = param_1 & 7;
    uVar2 = 2;
    if (uVar1 != 2) {
      if (uVar1 < 3) {
        if (uVar1 != 0) {
LAB_97c1a328:
                    
          _abort();
        }
        uVar2 = 4;
      }
      else {
        uVar2 = 4;
        if (uVar1 != 3) {
          if (uVar1 != 4) goto LAB_97c1a328;
          uVar2 = 8;
        }
      }
    }
  }
  return uVar2;
}

/* _base_of_encoded_value @ 0x97c1a340 (172 bytes) */
int _base_of_encoded_value(param_1, param_2)
  uint param_1;
  unsigned char * param_2;
{
  bool bVar1;
  uint uVar2;
  unsigned char uVar3;
  
  if (param_1 != 0xff) {
    uVar2 = param_1 & 0x70;
    if (uVar2 == 0x20) {
      uVar3 = __Unwind_GetTextRelBase(param_2);
      return uVar3;
    }
    if (uVar2 < 0x21) {
      if (uVar2 == 0) {
        return 0;
      }
      bVar1 = uVar2 == 0x10;
    }
    else {
      if (uVar2 == 0x40) {
        uVar3 = ((int (*)())__Unwind_GetRegionStart)(param_2);
        return uVar3;
      }
      if (uVar2 < 0x41) {
        if (uVar2 == 0x30) {
          uVar3 = __Unwind_GetDataRelBase(param_2);
          return uVar3;
        }
        goto LAB_97c1a3d4;
      }
      bVar1 = uVar2 == 0x50;
    }
    if (!bVar1) {
LAB_97c1a3d4:
                    
      _abort();
    }
  }
  return 0;
}

/* _read_uleb128_97c1a3ec @ 0x97c1a3ec (48 bytes) */
int _read_uleb128_97c1a3ec(param_1, param_2)
  byte *param_1;
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
  return param_1;
}

/* _read_sleb128_97c1a41c @ 0x97c1a41c (76 bytes) */
int _read_sleb128_97c1a41c(param_1, param_2)
  byte *param_1;
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
  if ((uVar3 < 0x20) && ((bVar1 & 0x40) != 0)) {
    uVar4 = uVar4 | -1 << (uVar3 & 0x3f);
  }
  *param_2 = uVar4;
  return param_1;
}

/* _read_encoded_value_with_base_97c1a468 @ 0x97c1a468 (312 bytes) */
int _read_encoded_value_with_base_97c1a468(param_1, param_2, param_3, param_4)
  uint param_1;
  uint *param_2;
  uint *param_3;
  uint *param_4;
{
  uint *puVar1;
  uint *local_30;
  uint *local_2c [6];
  
  if (param_1 == 0x50) {
    local_2c[0] = (uint *)((int)param_3 + 3U & 0xfffffffc);
    puVar1 = local_2c[0] + 1;
    goto LAB_97c1a5b4;
  }
  switch(param_1 & 0xf) {
  case 0:
  case 3:
  case 0xb:
    local_2c[0] = (uint *)*param_3;
    puVar1 = param_3 + 1;
    break;
  case 1:
    puVar1 = (uint *)((int (*)())_read_uleb128_97c1a3ec)(param_3,&local_30);
    local_2c[0] = local_30;
    break;
  case 2:
    local_2c[0] = (uint *)(uint)*(ushort *)param_3;
    goto LAB_97c1a540;
  case 4:
  case 0xc:
    puVar1 = param_3 + 2;
    local_2c[0] = (uint *)((uint)*(byte *)((int)param_3 + 7) |
                          (uint)*(byte *)((int)param_3 + 6) << 8 |
                          (uint)*(byte *)((int)param_3 + 5) << 0x10 |
                          (uint)*(byte *)(param_3 + 1) << 0x18);
    break;
  default:
                    
    _abort();
  case 9:
    puVar1 = (uint *)((int (*)())_read_sleb128_97c1a41c)(param_3,local_2c);
    break;
  case 10:
    local_2c[0] = (uint *)(int)(short)*(ushort *)param_3;
LAB_97c1a540:
    puVar1 = (uint *)((int)param_3 + 2);
  }
  if (local_2c[0] != (uint *)0x0) {
    if ((param_1 & 0x70) == 0x10) {
      param_2 = param_3;
    }
    local_2c[0] = (uint *)((int)local_2c[0] + (int)param_2);
    if ((param_1 & 0x80) != 0) {
LAB_97c1a5b4:
      local_2c[0] = (uint *)*local_2c[0];
    }
  }
  *param_4 = (uint)local_2c[0];
  return puVar1;
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

