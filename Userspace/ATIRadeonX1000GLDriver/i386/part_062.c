#include "decls.h"

/* FUN_001bf464 @ 0x1bf464 (48 bytes) */
int FUN_001bf464(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  float *param_2;
  float *param_3;
  float *param_4;
  int param_5;
{
  *param_2 = *param_3 * *param_4 + param_3[1] * param_4[1] + *(float *)(param_5 + 8);
  return;
}

/* FUN_001bf494 @ 0x1bf494 (81 bytes) */
int FUN_001bf494(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  float *param_2;
  float *param_3;
  undefined4 param_4;
  int param_5;
{
  float fVar1;
  float fVar2;
  
  fVar1 = *param_3;
  FUN_00119392();
  fVar2 = param_3[1];
  FUN_00119392();
  *param_2 = fVar1 + fVar2 + *(float *)(param_5 + 8);
  return;
}

/* FUN_001bf4e6 @ 0x1bf4e6 (48 bytes) */
int FUN_001bf4e6(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 *param_2;
  int param_3;
{
  if ((*(float *)(param_3 + 4) == 0.0) && (!NAN(*(float *)(param_3 + 4)))) {
    *param_2 = *(undefined4 *)(param_3 + 8);
    return 1;
  }
  *param_2 = *(undefined4 *)(param_3 + 0xc);
  return 1;
}

/* FUN_001bf516 @ 0x1bf516 (55 bytes) */
int FUN_001bf516(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 *param_2;
  int param_3;
{
  if (FLOAT_001c5b9c <= *(float *)(param_3 + 4)) {
    *param_2 = *(undefined4 *)(param_3 + 8);
    return 1;
  }
  *param_2 = *(undefined4 *)(param_3 + 0xc);
  return 1;
}

/* FUN_001bf54e @ 0x1bf54e (55 bytes) */
int FUN_001bf54e(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 *param_2;
  int param_3;
{
  if (FLOAT_001c5b9c < *(float *)(param_3 + 4)) {
    *param_2 = *(undefined4 *)(param_3 + 8);
    return 1;
  }
  *param_2 = *(undefined4 *)(param_3 + 0xc);
  return 1;
}

/* FUN_001bf586 @ 0x1bf586 (50 bytes) */
int FUN_001bf586(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 *param_2;
  int param_3;
{
  if ((*(float *)(param_3 + 4) == *(float *)(param_3 + 8)) &&
     (!NAN(*(float *)(param_3 + 4)) && !NAN(*(float *)(param_3 + 8)))) {
    *param_2 = 0x3f800000;
    return 1;
  }
  *param_2 = 0;
  return 1;
}

/* FUN_001bf5b8 @ 0x1bf5b8 (48 bytes) */
int FUN_001bf5b8(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 *param_2;
  int param_3;
{
  if (*(float *)(param_3 + 8) <= *(float *)(param_3 + 4) &&
      *(float *)(param_3 + 4) != *(float *)(param_3 + 8)) {
    *param_2 = 0x3f800000;
    return 1;
  }
  *param_2 = 0;
  return 1;
}

/* FUN_001bf5e8 @ 0x1bf5e8 (48 bytes) */
int FUN_001bf5e8(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 *param_2;
  int param_3;
{
  if (*(float *)(param_3 + 8) <= *(float *)(param_3 + 4)) {
    *param_2 = 0x3f800000;
    return 1;
  }
  *param_2 = 0;
  return 1;
}

/* FUN_001bf618 @ 0x1bf618 (50 bytes) */
int FUN_001bf618(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 *param_2;
  int param_3;
{
  if (*(float *)(param_3 + 4) != *(float *)(param_3 + 8)) {
    *param_2 = 0x3f800000;
    return 1;
  }
  *param_2 = 0;
  return 1;
}

/* FUN_001bf64a @ 0x1bf64a (10 bytes) */
int FUN_001bf64a()
{
  return 1;
}

/* FUN_001bf654 @ 0x1bf654 (10 bytes) */
int FUN_001bf654()
{
  return 1;
}

/* FUN_001bf65e @ 0x1bf65e (68 bytes) */
int FUN_001bf65e(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  float *param_2;
  float *param_3;
  float *param_4;
{
  *param_2 = *param_3 * *param_4 + param_3[1] * param_4[1] + param_3[2] * param_4[2] +
             param_3[3] * param_4[3];
  return;
}

/* FUN_001bf6a2 @ 0x1bf6a2 (9 bytes) */
int FUN_001bf6a2()
{
  FUN_001193b8();
  return;
}

/* FUN_001bf6ac @ 0x1bf6ac (9 bytes) */
int FUN_001bf6ac()
{
  FUN_001193de();
  return;
}

/* FUN_001bf6b6 @ 0x1bf6b6 (9 bytes) */
int FUN_001bf6b6()
{
  FUN_001193de();
  return;
}

/* FUN_001bf6c0 @ 0x1bf6c0 (9 bytes) */
int FUN_001bf6c0()
{
  FUN_001193de();
  return;
}

/* FUN_001bf6ca @ 0x1bf6ca (9 bytes) */
int FUN_001bf6ca()
{
  FUN_001193de();
  return;
}

/* FUN_001bf6d4 @ 0x1bf6d4 (9 bytes) */
int FUN_001bf6d4()
{
  FUN_001193de();
  return;
}

/* FUN_001bf6de @ 0x1bf6de (9 bytes) */
int FUN_001bf6de()
{
  FUN_001193de();
  return;
}

/* FUN_001bf6e8 @ 0x1bf6e8 (9 bytes) */
int FUN_001bf6e8()
{
  FUN_00119404();
  return;
}

/* FUN_001bf6f2 @ 0x1bf6f2 (9 bytes) */
int FUN_001bf6f2()
{
  FUN_00119404();
  return;
}

/* FUN_001bf6fc @ 0x1bf6fc (9 bytes) */
int FUN_001bf6fc()
{
  FUN_00119404();
  return;
}

/* FUN_001bf706 @ 0x1bf706 (9 bytes) */
int FUN_001bf706()
{
  FUN_00119404();
  return;
}

/* FUN_001bf710 @ 0x1bf710 (9 bytes) */
int FUN_001bf710()
{
  FUN_0011943c();
  return;
}

/* FUN_001bf71a @ 0x1bf71a (9 bytes) */
int FUN_001bf71a()
{
  FUN_0011943c();
  return;
}

/* FUN_001bf724 @ 0x1bf724 (9 bytes) */
int FUN_001bf724()
{
  FUN_0011943c();
  return;
}

/* FUN_001bf72e @ 0x1bf72e (9 bytes) */
int FUN_001bf72e()
{
  FUN_0011943c();
  return;
}

/* FUN_001bf738 @ 0x1bf738 (9 bytes) */
int FUN_001bf738()
{
  FUN_0011943c();
  return;
}

/* FUN_001bf742 @ 0x1bf742 (9 bytes) */
int FUN_001bf742()
{
  FUN_0011947e();
  return;
}

/* FUN_001bf74c @ 0x1bf74c (9 bytes) */
int FUN_001bf74c()
{
  FUN_001194c0();
  return;
}

/* FUN_001bf756 @ 0x1bf756 (9 bytes) */
int FUN_001bf756()
{
  FUN_00119506();
  return;
}

/* FUN_001bf760 @ 0x1bf760 (9 bytes) */
int FUN_001bf760()
{
  FUN_00119534();
  return;
}

/* FUN_001bf76a @ 0x1bf76a (9 bytes) */
int FUN_001bf76a()
{
  FUN_00119534();
  return;
}

/* FUN_001bf774 @ 0x1bf774 (9 bytes) */
int FUN_001bf774()
{
  FUN_00119534();
  return;
}

/* FUN_001bf77e @ 0x1bf77e (185 bytes) */
int FUN_001bf77e(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  int *param_3;
  int param_4;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  undefined4 local_1c;
  
  cVar5 = FUN_0018f7c8(param_2);
  if (cVar5 != '\0') {
    return 0;
  }
  uVar1 = *(undefined4 *)(param_2 + 0xb0);
  iVar2 = *(int *)(param_4 + 0x38c);
  iVar3 = *(int *)(*(int *)(param_4 + 0x3f4) + 0xa8);
  local_1c = 2;
  iVar7 = 0;
  do {
    iVar6 = FUN_0010b0f4(uVar1,0);
    uVar4 = local_1c;
    if (*(char *)(iVar7 + 0x10 + iVar6) != '\x01') {
      if (iVar2 <= iVar3) {
        return local_1c;
      }
      if (*param_3 == 0x7ffffffe) {
        cVar5 = FUN_0018a2c6(param_2,iVar7);
        uVar4 = 1;
        if (cVar5 == '\0') {
          uVar4 = local_1c;
        }
      }
    }
    local_1c = uVar4;
    iVar7 = iVar7 + 1;
    param_3 = param_3 + 1;
  } while (iVar7 != 4);
  return local_1c;
}

/* FUN_001bf838 @ 0x1bf838 (76 bytes) */
int FUN_001bf838(param_1, param_2, param_3)
  undefined4 param_1;
  float *param_2;
  int param_3;
{
  float fVar1;
  float fVar2;
  
  fVar1 = *(float *)(param_3 + 4);
  if ((fVar1 == 0.0) && (!NAN(fVar1))) {
    *param_2 = 0.0;
    return 1;
  }
  fVar2 = *(float *)(param_3 + 8);
  if ((fVar2 == 0.0) && (!NAN(fVar2))) {
    *param_2 = 0.0;
    return 1;
  }
  *param_2 = fVar1 * fVar2;
  return 1;
}

/* FUN_001bf884 @ 0x1bf884 (53 bytes) */
int FUN_001bf884(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_0021371d + 8;
  *param_1 = PTR_DAT_00213695 + 8;
  *param_1 = PTR_DAT_00213819 + 8;
  operator_delete(param_1);
  return;
}

/* FUN_001bf8ba @ 0x1bf8ba (46 bytes) */
int FUN_001bf8ba(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_0021371d + 8;
  *param_1 = PTR_DAT_00213695 + 8;
  *param_1 = PTR_DAT_00213819 + 8;
  return;
}

/* FUN_001bf8e8 @ 0x1bf8e8 (53 bytes) */
int FUN_001bf8e8(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_00213945 + 8;
  *param_1 = PTR_DAT_00213695 + 8;
  *param_1 = PTR_DAT_00213819 + 8;
  operator_delete(param_1);
  return;
}

/* FUN_001bf91e @ 0x1bf91e (46 bytes) */
int FUN_001bf91e(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_00213945 + 8;
  *param_1 = PTR_DAT_00213695 + 8;
  *param_1 = PTR_DAT_00213819 + 8;
  return;
}

/* FUN_001bf94c @ 0x1bf94c (53 bytes) */
int FUN_001bf94c(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_002137fd + 8;
  *param_1 = PTR_DAT_00213695 + 8;
  *param_1 = PTR_DAT_00213819 + 8;
  operator_delete(param_1);
  return;
}

/* FUN_001bf982 @ 0x1bf982 (46 bytes) */
int FUN_001bf982(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_002137fd + 8;
  *param_1 = PTR_DAT_00213695 + 8;
  *param_1 = PTR_DAT_00213819 + 8;
  return;
}

/* FUN_001bf9b0 @ 0x1bf9b0 (53 bytes) */
int FUN_001bf9b0(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_002138dd + 8;
  *param_1 = PTR_DAT_0021367d + 8;
  *param_1 = PTR_DAT_00213819 + 8;
  operator_delete(param_1);
  return;
}

/* FUN_001bf9e6 @ 0x1bf9e6 (46 bytes) */
int FUN_001bf9e6(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_002138dd + 8;
  *param_1 = PTR_DAT_0021367d + 8;
  *param_1 = PTR_DAT_00213819 + 8;
  return;
}

/* FUN_001bfa14 @ 0x1bfa14 (53 bytes) */
int FUN_001bfa14(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_00213885 + 8;
  *param_1 = PTR_DAT_0021367d + 8;
  *param_1 = PTR_DAT_00213819 + 8;
  operator_delete(param_1);
  return;
}

/* FUN_001bfa4a @ 0x1bfa4a (46 bytes) */
int FUN_001bfa4a(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_00213885 + 8;
  *param_1 = PTR_DAT_0021367d + 8;
  *param_1 = PTR_DAT_00213819 + 8;
  return;
}

/* FUN_001bfa78 @ 0x1bfa78 (53 bytes) */
int FUN_001bfa78(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_002138e5 + 8;
  *param_1 = PTR_DAT_0021367d + 8;
  *param_1 = PTR_DAT_00213819 + 8;
  operator_delete(param_1);
  return;
}

/* FUN_001bfaae @ 0x1bfaae (46 bytes) */
int FUN_001bfaae(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_002138e5 + 8;
  *param_1 = PTR_DAT_0021367d + 8;
  *param_1 = PTR_DAT_00213819 + 8;
  return;
}

/* FUN_001bfadc @ 0x1bfadc (53 bytes) */
int FUN_001bfadc(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_002138ad + 8;
  *param_1 = PTR_DAT_002136d1 + 8;
  *param_1 = PTR_DAT_00213819 + 8;
  operator_delete(param_1);
  return;
}

/* FUN_001bfb12 @ 0x1bfb12 (46 bytes) */
int FUN_001bfb12(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_002138ad + 8;
  *param_1 = PTR_DAT_002136d1 + 8;
  *param_1 = PTR_DAT_00213819 + 8;
  return;
}

/* FUN_001bfb40 @ 0x1bfb40 (53 bytes) */
int FUN_001bfb40(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_00213785 + 8;
  *param_1 = PTR_DAT_002136d1 + 8;
  *param_1 = PTR_DAT_00213819 + 8;
  operator_delete(param_1);
  return;
}

/* FUN_001bfb76 @ 0x1bfb76 (46 bytes) */
int FUN_001bfb76(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_00213785 + 8;
  *param_1 = PTR_DAT_002136d1 + 8;
  *param_1 = PTR_DAT_00213819 + 8;
  return;
}

/* FUN_001bfba4 @ 0x1bfba4 (53 bytes) */
int FUN_001bfba4(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_00213621 + 8;
  *param_1 = PTR_DAT_00213931 + 8;
  *param_1 = PTR_DAT_00213819 + 8;
  operator_delete(param_1);
  return;
}

/* FUN_001bfbda @ 0x1bfbda (46 bytes) */
int FUN_001bfbda(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_00213621 + 8;
  *param_1 = PTR_DAT_00213931 + 8;
  *param_1 = PTR_DAT_00213819 + 8;
  return;
}

/* FUN_001bfc08 @ 0x1bfc08 (53 bytes) */
int FUN_001bfc08(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_002135cd + 8;
  *param_1 = PTR_DAT_00213931 + 8;
  *param_1 = PTR_DAT_00213819 + 8;
  operator_delete(param_1);
  return;
}

/* FUN_001bfc3e @ 0x1bfc3e (46 bytes) */
int FUN_001bfc3e(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_002135cd + 8;
  *param_1 = PTR_DAT_00213931 + 8;
  *param_1 = PTR_DAT_00213819 + 8;
  return;
}

/* FUN_001bfc6c @ 0x1bfc6c (53 bytes) */
int FUN_001bfc6c(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_00213761 + 8;
  *param_1 = PTR_DAT_00213949 + 8;
  *param_1 = PTR_DAT_00213819 + 8;
  operator_delete(param_1);
  return;
}

/* FUN_001bfca2 @ 0x1bfca2 (46 bytes) */
int FUN_001bfca2(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_00213761 + 8;
  *param_1 = PTR_DAT_00213949 + 8;
  *param_1 = PTR_DAT_00213819 + 8;
  return;
}

/* FUN_001bfcd0 @ 0x1bfcd0 (53 bytes) */
int FUN_001bfcd0(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_002135ad + 8;
  *param_1 = PTR_DAT_00213975 + 8;
  *param_1 = PTR_DAT_00213819 + 8;
  operator_delete(param_1);
  return;
}

/* FUN_001bfd06 @ 0x1bfd06 (46 bytes) */
int FUN_001bfd06(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_002135ad + 8;
  *param_1 = PTR_DAT_00213975 + 8;
  *param_1 = PTR_DAT_00213819 + 8;
  return;
}

