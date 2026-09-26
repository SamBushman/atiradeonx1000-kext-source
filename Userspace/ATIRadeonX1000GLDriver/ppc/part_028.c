#include "decls.h"

/* FUN_0010564c @ 0x10564c (584 bytes) */
int FUN_0010564c(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  undefined4 uVar2;
  int *a0;
  int iVar3;
  int *a0_00;
  int iVar4;
  int iVar5;
  
  iVar1 = FUN_00104054(param_1,*(undefined4 *)(param_2 + 0x6c4));
  uVar2 = 0;
  if (iVar1 == 0) {
    if (param_3 == 0) {
      iVar1 = param_1[0x21];
      iVar3 = 1;
      if (0 < iVar1) {
        do {
          iVar5 = FUN_00105594(param_1,iVar3);
          iVar1 = param_1[0x21];
          iVar3 = iVar3 + 1;
          *(int *)(iVar5 + 0x160) = *(int *)(iVar5 + 0x160) + -1;
        } while (iVar3 <= iVar1);
      }
    }
    else {
      iVar1 = param_1[0x21];
    }
    if (0 < iVar1) {
      iVar1 = 1;
      do {
        a0 = (int *)FUN_00105594(param_1,iVar1);
        iVar3 = (**(code **)(*a0 + 0x5c))(a0);
        if ((iVar3 != 0) || (iVar3 = (**(code **)(*a0 + 0x60))(a0), iVar3 != 0)) {
          iVar5 = 1;
          iVar3 = FUN_00104054(a0,*(undefined4 *)(param_2 + 0x6c4));
          if (iVar3 == 0) {
            for (; iVar3 = (**(code **)(*a0 + 0x14))(a0), iVar5 <= iVar3; iVar5 = iVar5 + 1) {
              a0_00 = (int *)FUN_00105594(a0,iVar5);
              a0_00[0x58] = a0_00[0x58] + -1;
              iVar3 = (**(code **)(*a0_00 + 0x5c))(a0_00);
              if ((iVar3 != 0) &&
                 (iVar3 = FUN_00104054(a0_00,*(undefined4 *)(param_2 + 0x6c4)), iVar3 == 0)) {
                (**(code **)(*a0 + 0x60))(a0);
                for (iVar3 = 1; iVar4 = (**(code **)(*a0_00 + 0x14))(a0_00), iVar3 <= iVar4;
                    iVar3 = iVar3 + 1) {
                  iVar4 = FUN_00105594(a0_00,iVar3);
                  *(int *)(iVar4 + 0x160) = *(int *)(iVar4 + 0x160) + -1;
                }
                (**(code **)(*a0_00 + 0xc))(a0_00,param_3,param_2);
              }
            }
            (**(code **)(*a0 + 0xc))(a0,param_3,param_2);
          }
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 <= param_1[0x21]);
    }
    (**(code **)(*param_1 + 0xc))(param_1,param_3,param_2);
    uVar2 = 1;
  }
  return uVar2;
}

/* FUN_00105894 @ 0x105894 (20 bytes) */
int FUN_00105894(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined4 uVar1;
  
  *(int *)(param_1 + 0x160) = *(int *)(param_1 + 0x160) + -1;
  uVar1 = ((int (*)())FUN_0010564c)(param_1,param_2,0);
  return uVar1;
}

/* FUN_001058a8 @ 0x1058a8 (136 bytes) */
int FUN_001058a8(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  
  if (((*(uint *)(param_2 + 0x30) & 0x80) != 0) && (iVar2 = 1, 0 < *(int *)(param_1 + 0x84))) {
    do {
      iVar1 = FUN_00105594(param_1,iVar2);
      if (iVar1 != 0) {
        iVar1 = FUN_00105594(param_1,iVar2);
        *(int *)(iVar1 + 0x160) = *(int *)(iVar1 + 0x160) + -1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 <= *(int *)(param_1 + 0x84));
  }
  return;
}

/* FUN_00105930 @ 0x105930 (276 bytes) */
int FUN_00105930(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  
  if (((*(uint *)(param_2 + 0x30) & 0x80) != 0) && (iVar4 = 1, 0 < *(int *)(param_1 + 0x84))) {
    do {
      iVar1 = FUN_00105594(param_1,iVar4);
      if (iVar1 != 0) {
        iVar1 = FUN_00105594(param_1,iVar4);
        puVar6 = *(uint **)(iVar1 + 0x10);
        uVar2 = puVar6[1];
        if (0 < (int)uVar2) {
          uVar5 = 0;
          do {
            if (uVar5 < *puVar6) {
              if (uVar2 <= uVar5) {
                _memset(uVar2 * 4 + puVar6[2],0,(uVar5 - uVar2) * 4 + 4);
                puVar6[1] = uVar5 + 1;
              }
              piVar3 = (int *)(uVar5 * 4 + puVar6[2]);
            }
            else {
              piVar3 = (int *)FUN_0019423c(puVar6,uVar5);
            }
            if (param_1 == *piVar3) {
              FUN_00194208(puVar6,uVar5);
              break;
            }
            uVar2 = puVar6[1];
            uVar5 = uVar5 + 1;
          } while ((int)uVar5 < (int)uVar2);
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 <= *(int *)(param_1 + 0x84));
  }
  return;
}

/* FUN_00105a44 @ 0x105a44 (224 bytes) */
int FUN_00105a44(param_1, param_2)
  int *param_1;
  int param_2;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = (**(code **)(*param_1 + 0x34))(param_1,param_2);
  if (iVar2 == 0) {
    (**(code **)(*param_1 + 0x38))(param_1);
  }
  ((int (*)())FUN_00105930)(param_1,*(undefined4 *)(param_2 + 0x6c4));
  iVar3 = param_1[1];
  iVar2 = (**(code **)(*param_1 + 0x40))(param_1);
  if ((iVar2 != 0) &&
     (iVar2 = *(int *)(*(int *)(param_2 + 0x6c4) + 0x3a0), param_1 == *(int **)(iVar2 + 300))) {
    *(int *)(iVar2 + 300) = iVar3;
  }
  uVar1 = param_1[5];
  if ((((uVar1 & 4) == 0) && (iVar3 != 0)) && ((*(uint *)(iVar3 + 0x14) & 4) != 0)) {
    *(uint *)(iVar3 + 0x14) = *(uint *)(iVar3 + 0x14) & 0xfffffffb;
    uVar1 = param_1[5];
  }
  param_1[5] = uVar1 & 0xfffffffe;
  FUN_0019401c(param_1);
  return;
}

/* FUN_00105b24 @ 0x105b24 (88 bytes) */
int FUN_00105b24(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  if ((*(uint *)(param_2 + 0x30) & 0x80) != 0) {
    ((int (*)())FUN_00105930)(param_1,param_2);
    ((int (*)())FUN_001058a8)(param_1,param_2);
    return;
  }
  return;
}

/* FUN_00105b7c @ 0x105b7c (224 bytes) */
int FUN_00105b7c(param_1, param_2, param_3)
  int *param_1;
  undefined4 param_2;
  int param_3;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = (**(code **)(*param_1 + 0x34))(param_1,param_2,param_3);
  if (iVar2 == 0) {
    (**(code **)(*param_1 + 0x38))(param_1);
  }
  ((int (*)())FUN_00105b24)(param_1,*(undefined4 *)(param_3 + 0x6c4));
  iVar3 = param_1[1];
  iVar2 = (**(code **)(*param_1 + 0x40))(param_1);
  if ((iVar2 != 0) &&
     (iVar2 = *(int *)(*(int *)(param_3 + 0x6c4) + 0x3a0), param_1 == *(int **)(iVar2 + 300))) {
    *(int *)(iVar2 + 300) = iVar3;
  }
  uVar1 = param_1[5];
  if ((((uVar1 & 4) == 0) && (iVar3 != 0)) && ((*(uint *)(iVar3 + 0x14) & 4) != 0)) {
    *(uint *)(iVar3 + 0x14) = *(uint *)(iVar3 + 0x14) & 0xfffffffb;
    uVar1 = param_1[5];
  }
  param_1[5] = uVar1 & 0xfffffffe;
  FUN_0019401c(param_1);
  return;
}

/* FUN_00105c5c @ 0x105c5c (168 bytes) */
int FUN_00105c5c(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  while( true ) {
    if (param_2 == 0) {
      return *(undefined4 *)(param_1 + 0x128);
    }
    iVar1 = FUN_00105594(param_1,param_2);
    if (iVar1 == 0) break;
    param_1 = FUN_00105594(param_1,param_2);
    param_2 = 0;
  }
  piVar3 = *(int **)(param_2 * 0x18 + param_1 + 0x8c);
  if (piVar3 == (int *)0x0) {
    return 0;
  }
                    
                    
  uVar2 = (**(code **)(*piVar3 + 0x24))(piVar3);
  return uVar2;
}

/* FUN_00105d04 @ 0x105d04 (184 bytes) */
int FUN_00105d04(param_1, param_2)
  undefined4 *param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((param_2[5] & 0x200U) == 0) {
    iVar3 = param_2[0x21];
  }
  else {
    iVar3 = param_2[0x21] + -1;
  }
  iVar1 = (**(code **)(*param_2 + 0x14))(param_2);
  do {
    iVar1 = iVar1 + 1;
    if (iVar3 < iVar1) {
      *param_1 = DAT_001af9bc;
      return param_1;
    }
    iVar2 = FUN_001054ec(param_2,iVar1);
  } while ((*(uint *)(*(int *)(iVar2 + 4) + 0x14) & 0x80000) == 0);
  *param_1 = *(undefined4 *)(iVar2 + 0x10);
  return param_1;
}

/* FUN_00105dbc @ 0x105dbc (152 bytes) */
int FUN_00105dbc(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined1 uVar1;
  int iVar2;
  
  if ((param_2 < 1) || (iVar2 = FUN_00105594(param_1,param_2), iVar2 == 0)) {
    iVar2 = FUN_001054ec(param_1,param_2);
    iVar2 = *(int *)(iVar2 + 0xc);
  }
  else {
    iVar2 = FUN_00105594(param_1,param_2);
    iVar2 = *(int *)(iVar2 + 0x98);
  }
  uVar1 = 2;
  if (PTR_PTR_001e8c60[iVar2 * 0x10 + 9] != '\x01') {
    uVar1 = PTR_PTR_001e8c60[iVar2 * 0x10 + 9] == '\x02';
  }
  return uVar1;
}

/* FUN_00105e54 @ 0x105e54 (72 bytes) */
int FUN_00105e54(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined4 uVar1;
  
  uVar1 = FUN_001054ec(param_3,param_4);
  FUN_00104730(param_2 * 0x18 + param_1 + 0x8c,uVar1);
  return;
}

/* FUN_00105e9c @ 0x105e9c (104 bytes) */
int FUN_00105e9c(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x84);
  iVar1 = iVar2 + 1;
  *(int *)(param_1 + 0x84) = iVar1;
  if ((*(uint *)(param_1 + 0x14) & 0x200) != 0) {
    ((int (*)())FUN_00105e54)(param_1,iVar1,param_1,iVar2);
    iVar1 = *(int *)(param_1 + 0x84) + -1;
  }
  FUN_001046c8(param_1,iVar1,param_2);
  return;
}

/* FUN_00105f04 @ 0x105f04 (256 bytes) */
int FUN_00105f04(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  
  if (((*(uint *)(param_2 + 0x30) & 0x80) != 0) && (iVar3 = 1, 0 < *(int *)(param_1 + 0x84))) {
    do {
      iVar1 = FUN_00105594(param_1,iVar3);
      if (iVar1 != 0) {
        iVar1 = FUN_00105594(param_1,iVar3);
        puVar5 = *(uint **)(iVar1 + 0x10);
        uVar4 = puVar5[1];
        if (uVar4 < *puVar5) {
          _memset(uVar4 * 4 + puVar5[2],0,4);
          piVar2 = (int *)(uVar4 * 4 + puVar5[2]);
          puVar5[1] = uVar4 + 1;
        }
        else {
          piVar2 = (int *)FUN_0019423c(puVar5,uVar4);
        }
        *piVar2 = param_1;
        iVar1 = FUN_00105594(param_1,iVar3);
        if (*(int *)(param_2 + 0x478) < *(int *)(iVar1 + 0x160)) {
          *(int *)(iVar1 + 0x160) = *(int *)(iVar1 + 0x160) + 1;
        }
        else {
          *(int *)(iVar1 + 0x160) = *(int *)(param_2 + 0x478) + 1;
        }
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 <= *(int *)(param_1 + 0x84));
  }
  return;
}

/* FUN_00106004 @ 0x106004 (428 bytes) */
int FUN_00106004(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 param_2;
  int param_3;
  int param_4;
  int param_5;
{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  
  iVar4 = *(int *)(param_5 + 0x6c4);
  if ((param_4 != 0) && (iVar1 = FUN_00105594(param_1,param_2), iVar1 != 0)) {
    iVar1 = FUN_00105594(param_1,param_2);
    puVar6 = *(uint **)(iVar1 + 0x10);
    uVar2 = puVar6[1];
    if (0 < (int)uVar2) {
      uVar5 = 0;
      do {
        if (uVar5 < *puVar6) {
          if (uVar2 <= uVar5) {
            _memset(uVar2 * 4 + puVar6[2],0,(uVar5 - uVar2) * 4 + 4);
            puVar6[1] = uVar5 + 1;
          }
          piVar3 = (int *)(uVar5 * 4 + puVar6[2]);
        }
        else {
          piVar3 = (int *)FUN_0019423c(puVar6,uVar5);
        }
        if (param_1 == *piVar3) {
          FUN_00194208(puVar6,uVar5);
          iVar1 = FUN_00105594(param_1,param_2);
          *(int *)(iVar1 + 0x160) = *(int *)(iVar1 + 0x160) + -1;
          break;
        }
        uVar2 = puVar6[1];
        uVar5 = uVar5 + 1;
      } while ((int)uVar5 < (int)uVar2);
    }
  }
  FUN_00105334(param_1,param_2,param_3,param_5);
  if ((param_4 != 0) && (param_3 != 0)) {
    puVar6 = *(uint **)(param_3 + 0x10);
    uVar2 = puVar6[1];
    if (uVar2 < *puVar6) {
      _memset(uVar2 * 4 + puVar6[2],0,4);
      piVar3 = (int *)(uVar2 * 4 + puVar6[2]);
      puVar6[1] = uVar2 + 1;
    }
    else {
      piVar3 = (int *)FUN_0019423c(puVar6,uVar2);
    }
    *piVar3 = param_1;
    iVar4 = *(int *)(iVar4 + 0x478);
    if (iVar4 < *(int *)(param_3 + 0x160)) {
      *(int *)(param_3 + 0x160) = *(int *)(param_3 + 0x160) + 1;
    }
    else {
      *(int *)(param_3 + 0x160) = iVar4 + 1;
    }
  }
  return;
}

/* FUN_001061b0 @ 0x1061b0 (128 bytes) */
int FUN_001061b0(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = *(int *)(param_1 + 0x84);
  iVar2 = *(int *)(param_2 + 0x8c);
  if (0 < iVar1) {
    iVar3 = 1;
    iVar4 = param_1;
    do {
      if (iVar2 == *(int *)(iVar4 + 0xa4)) {
        ((int (*)())FUN_00106004)(param_1,iVar3,param_2,0,param_3);
        iVar1 = *(int *)(param_1 + 0x84);
      }
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x18;
    } while (iVar3 <= iVar1);
  }
  return;
}

/* FUN_00106230 @ 0x106230 (144 bytes) */
int FUN_00106230(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  int param_6;
{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_6 + 0x30c) + 0x11c))
                    (*(int **)(param_6 + 0x30c),param_1,param_2,param_3,param_4,param_5,param_6);
  if (iVar1 != 0) {
    ((int (*)())FUN_00106004)(param_1,param_2,param_3,0,param_6);
  }
  return iVar1 != 0;
}

/* FUN_001062c0 @ 0x1062c0 (156 bytes) */
int FUN_001062c0(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  undefined4 *param_3;
  int param_4;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  int *piVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uVar8;
  uint *puVar9;
  
  if (param_2 < 5) {
    puVar2 = (undefined4 *)(param_2 * 0x18 + param_1 + 0x8c);
  }
  else {
    puVar9 = *(uint **)(param_1 + 0x118);
    if (puVar9 == (uint *)0x0) {
      uVar1 = *(undefined4 *)(param_4 + 0x374);
      puVar2 = (undefined4 *)FUN_00193e18(uVar1,0x14);
      puVar9 = puVar2 + 1;
      *puVar2 = uVar1;
      puVar2[1] = 2;
      puVar2[2] = 0;
      puVar2[4] = uVar1;
      uVar1 = FUN_00193e18(uVar1,8);
      puVar2[3] = uVar1;
      *(uint **)(param_1 + 0x118) = puVar9;
    }
    if ((int)puVar9[1] < (int)(param_2 - 4U)) {
      uVar1 = *(undefined4 *)(param_4 + 0x374);
      puVar2 = (undefined4 *)FUN_00193e18(uVar1,0x1c);
      *puVar2 = uVar1;
      puVar2[1] = 0;
      puVar2[2] = 0;
      puVar2[6] = 0;
      puVar9 = *(uint **)(param_1 + 0x118);
      uVar8 = puVar9[1];
      if (uVar8 < *puVar9) {
        _memset((void *)(uVar8 * 4 + puVar9[2]),0,4);
        piVar3 = (int *)(uVar8 * 4 + puVar9[2]);
        puVar9[1] = uVar8 + 1;
      }
      else {
        piVar3 = (int *)FUN_0019423c(puVar9,uVar8);
      }
      *piVar3 = (int)(puVar2 + 1);
      FUN_00103e84(puVar2 + 1,param_2);
      puVar9 = *(uint **)(param_1 + 0x118);
    }
    uVar8 = param_2 - 5;
    if (uVar8 < *puVar9) {
      uVar4 = puVar9[1];
      if (uVar4 <= uVar8) {
        _memset((void *)(uVar4 * 4 + puVar9[2]),0,(uVar8 - uVar4) * 4 + 4);
        puVar9[1] = param_2 - 4U;
      }
      puVar2 = (undefined4 *)(uVar8 * 4 + puVar9[2]);
    }
    else {
      puVar2 = (undefined4 *)FUN_0019423c(puVar9,uVar8);
    }
    puVar2 = (undefined4 *)*puVar2;
  }
  FUN_00103d50(puVar2,1,param_3[5] & 1);
  FUN_00103d50(puVar2,2,(uint)param_3[5] >> 1 & 1);
  uVar1 = *param_3;
  uVar5 = param_3[1];
  uVar7 = param_3[2];
  uVar6 = param_3[3];
  puVar2[4] = param_3[4];
  *puVar2 = uVar1;
  puVar2[1] = uVar5;
  puVar2[2] = uVar7;
  puVar2[3] = uVar6;
  return;
}

/* FUN_0010647c @ 0x10647c (620 bytes) */
int FUN_0010647c(param_1, param_2)
  int *param_1;
  int param_2;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30 [4];
  
  if (0 < param_1[0x20]) {
    iVar5 = 0;
    do {
      iVar3 = (**(code **)(*param_1 + 0x24))(param_1);
      if (iVar3 != 0) {
        FUN_001054ec(param_1,iVar5);
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < param_1[0x20]);
  }
  iVar5 = *(int *)(param_2 + 0x6c4);
  if (((*(uint *)(iVar5 + 0x30) & 8) == 0) && (*(int *)(param_1[0x22] + 8) != 0x8e)) {
    iVar3 = FUN_001054ec(param_1,0);
    iVar5 = 0;
    local_38 = *(undefined4 *)(iVar3 + 0x10);
    iVar3 = 4;
    do {
      if (*(char *)((int)&local_38 + iVar5) == '\0') {
        iVar5 = 1;
        if (0 < param_1[0x21]) {
          do {
            iVar3 = (**(code **)(*param_1 + 0x24))(param_1);
            if ((iVar3 != 0) || (iVar3 = (**(code **)(*param_1 + 0x28))(param_1), iVar3 != 0)) {
              FUN_001054ec(param_1,iVar5);
            }
            iVar5 = iVar5 + 1;
          } while (iVar5 <= param_1[0x21]);
        }
        goto LAB_0010663c;
      }
      iVar5 = iVar5 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    iVar5 = *(int *)(param_2 + 0x6c4);
    if (((*(uint *)(iVar5 + 0x30) & 0x20000) != 0) && (iVar3 = 1, 0 < param_1[0x21])) {
      do {
        iVar5 = FUN_001054ec(param_1,iVar3);
        local_34 = *(undefined4 *)(iVar5 + 0x10);
        iVar5 = FUN_00105594(param_1,iVar3);
        if (iVar5 != 0) {
          iVar4 = FUN_001054ec(iVar5,0);
          iVar6 = 0;
          local_30[0] = *(undefined4 *)(iVar4 + 0x10);
          do {
            uVar2 = (uint)*(byte *)((int)local_30 + iVar6 + -4);
            if (((uVar2 != 4) && (*(char *)((int)local_30 + uVar2) != '\0')) &&
               ((*(uint *)(iVar5 + 0x14) & 0x200) != 0)) {
              FUN_001054ec(iVar5,*(undefined4 *)(iVar5 + 0x84));
            }
            bVar1 = iVar6 != 3;
            iVar6 = iVar6 + 1;
          } while (bVar1);
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 <= param_1[0x21]);
LAB_0010663c:
      iVar5 = *(int *)(param_2 + 0x6c4);
    }
  }
  if ((*(uint *)(iVar5 + 0x30) & 0x800) == 0) {
    (**(code **)(*param_1 + 0x68))(param_1);
  }
  if (((param_1[5] & 0x200U) != 0) && ((*(uint *)(*(int *)(param_2 + 0x6c4) + 0x30) & 8) != 0)) {
    FUN_00105594(param_1,param_1[0x21]);
  }
  (**(code **)(*param_1 + 100))(param_1);
  return 1;
}

/* FUN_001066e8 @ 0x1066e8 (84 bytes) */
int FUN_001066e8(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  int iVar1;
  
  iVar1 = FUN_001045e4(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_001054ec(param_1,1);
    FUN_000f2c5c(*(undefined4 *)(iVar1 + 0x10));
  }
  ((int (*)())FUN_0010647c)(param_1,param_2);
  return;
}

/* FUN_0010673c @ 0x10673c (68 bytes) */
int FUN_0010673c(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  (**(code **)(*param_1 + 0x14))(param_1,param_2);
  ((int (*)())FUN_0010647c)(param_1,param_2);
  return;
}

/* FUN_00106780 @ 0x106780 (128 bytes) */
int FUN_00106780(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x84);
  if (0 < iVar1) {
    iVar2 = 1;
    do {
      iVar1 = FUN_001054ec(param_1,iVar2);
      iVar2 = iVar2 + 1;
      FUN_000f3190(*(undefined4 *)(iVar1 + 0x10));
      iVar1 = *(int *)(param_1 + 0x84);
    } while (iVar2 <= iVar1);
  }
  if (1 < iVar1) {
    iVar2 = 2;
    do {
      iVar2 = iVar2 + 1;
    } while (iVar2 <= iVar1);
  }
  ((int (*)())FUN_0010647c)(param_1,param_2);
  return;
}

/* FUN_00106804 @ 0x106804 (484 bytes) */
int FUN_00106804(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  
  iVar5 = *(int *)(param_4 + 0x6c4);
  if (param_3 != 0) {
    uVar2 = *(uint *)(param_1 + 0x14);
    if ((uVar2 & 0x200) == 0) goto LAB_00106908;
    iVar3 = FUN_00105594(param_1,*(undefined4 *)(param_1 + 0x84));
    if (iVar3 != 0) {
      puVar7 = *(uint **)(iVar3 + 0x10);
      uVar2 = puVar7[1];
      if (0 < (int)uVar2) {
        uVar6 = 0;
        do {
          if (uVar6 < *puVar7) {
            if (uVar2 <= uVar6) {
              _memset(uVar2 * 4 + puVar7[2],0,(uVar6 - uVar2) * 4 + 4);
              puVar7[1] = uVar6 + 1;
            }
            piVar4 = (int *)(uVar6 * 4 + puVar7[2]);
          }
          else {
            piVar4 = (int *)FUN_0019423c(puVar7,uVar6);
          }
          if (param_1 == *piVar4) {
            FUN_00194208(puVar7,uVar6);
            uVar2 = *(uint *)(param_1 + 0x14);
            *(int *)(iVar3 + 0x160) = *(int *)(iVar3 + 0x160) + -1;
            goto LAB_00106908;
          }
          uVar2 = puVar7[1];
          uVar6 = uVar6 + 1;
        } while ((int)uVar6 < (int)uVar2);
      }
    }
  }
  uVar2 = *(uint *)(param_1 + 0x14);
LAB_00106908:
  if ((uVar2 & 0x200) == 0) {
    *(uint *)(param_1 + 0x14) = uVar2 | 0x200;
    uVar1 = DAT_001af9c4;
    iVar3 = *(int *)(param_1 + 0x84) + 1;
    *(int *)(param_1 + 0x84) = iVar3;
    iVar3 = FUN_001054ec(param_1,iVar3);
    *(undefined4 *)(iVar3 + 0x10) = uVar1;
  }
  FUN_00105334(param_1,*(undefined4 *)(param_1 + 0x84),param_2,param_4);
  if ((param_3 != 0) && (param_2 != 0)) {
    puVar7 = *(uint **)(param_2 + 0x10);
    uVar2 = puVar7[1];
    if (uVar2 < *puVar7) {
      _memset(uVar2 * 4 + puVar7[2],0,4);
      piVar4 = (int *)(uVar2 * 4 + puVar7[2]);
      puVar7[1] = uVar2 + 1;
    }
    else {
      piVar4 = (int *)FUN_0019423c(puVar7,uVar2);
    }
    *piVar4 = param_1;
    iVar5 = *(int *)(iVar5 + 0x478);
    if (iVar5 < *(int *)(param_2 + 0x160)) {
      *(int *)(param_2 + 0x160) = *(int *)(param_2 + 0x160) + 1;
    }
    else {
      *(int *)(param_2 + 0x160) = iVar5 + 1;
    }
  }
  return;
}

/* FUN_001069e8 @ 0x1069e8 (352 bytes) */
int FUN_001069e8(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = *(int *)(param_1 + 0x84);
  iVar3 = iVar2 + 1;
  *(int *)(param_1 + 0x84) = iVar3;
  if ((*(uint *)(param_1 + 0x14) & 0x200) == 0) {
    ((int (*)())FUN_00106004)(param_1,iVar3,param_2,0,param_3);
    uVar1 = DAT_001af9bc;
    if (iVar3 == 0) {
      *(undefined4 *)(param_1 + 0x9c) = DAT_001af9bc;
    }
    else {
      iVar2 = FUN_001054ec(param_1,iVar3);
      *(undefined4 *)(iVar2 + 0x10) = uVar1;
    }
  }
  else {
    if ((*(uint *)(*(int *)(param_3 + 0x6c4) + 0x30) & 8) == 0) {
      uVar1 = FUN_00105594(param_1,iVar2);
      ((int (*)())FUN_00106004)(param_1,iVar3,uVar1,0,param_3);
    }
    else {
      uVar1 = FUN_00105594(param_1,iVar2);
      ((int (*)())FUN_00106804)(param_1,uVar1,0,param_3);
    }
    iVar4 = *(int *)(param_1 + 0x84);
    iVar3 = FUN_001054ec(param_1,iVar2);
    uVar1 = *(undefined4 *)(iVar3 + 0x10);
    if (iVar4 == 0) {
      *(undefined4 *)(param_1 + 0x9c) = uVar1;
    }
    else {
      iVar3 = FUN_001054ec(param_1,iVar4);
      *(undefined4 *)(iVar3 + 0x10) = uVar1;
    }
    ((int (*)())FUN_00106004)(param_1,iVar2,param_2,0,param_3);
    uVar1 = DAT_001af9bc;
    if (iVar2 == 0) {
      *(undefined4 *)(param_1 + 0x9c) = DAT_001af9bc;
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_001054ec(param_1,iVar2);
      *(undefined4 *)(iVar3 + 0x10) = uVar1;
      iVar3 = iVar2;
    }
  }
  return iVar3;
}

/* FUN_00106b48 @ 0x106b48 (88 bytes) */
int FUN_00106b48(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  int iVar1;
  undefined4 uVar2;
  
  ((int (*)())FUN_00106804)(param_1,*(undefined4 *)(param_2 + 4),param_3,param_4);
  uVar2 = *(undefined4 *)(param_2 + 0x10);
  if (*(int *)(param_1 + 0x84) == 0) {
    *(undefined4 *)(param_1 + 0x9c) = uVar2;
  }
  else {
    iVar1 = FUN_001054ec(param_1,*(int *)(param_1 + 0x84));
    *(undefined4 *)(iVar1 + 0x10) = uVar2;
  }
  return;
}

/* FUN_00106ba0 @ 0x106ba0 (276 bytes) */
int FUN_00106ba0(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int *param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *a0;
  int iVar5;
  
  if (0 < param_1[0x21]) {
    iVar2 = 1;
    do {
      iVar2 = iVar2 + 1;
    } while (iVar2 <= param_1[0x21]);
  }
  iVar2 = 0;
  do {
    FUN_001054ec(param_1,0);
    if (0 < param_1[0x21]) {
      iVar5 = 1;
      do {
        FUN_001054ec(param_1,iVar5);
        if ((*(uint *)(*(int *)(param_2 + 0x6c4) + 0x30) & 8) != 0) {
          if (iVar5 != 1) {
            uVar3 = FUN_00105594(param_1,iVar5);
            iVar4 = FUN_001054ec(param_1,iVar5);
            FUN_0010453c(uVar3,param_2,*(undefined4 *)(iVar4 + 0x10),param_4,param_5,param_6,param_7
                        );
          }
          a0 = (int *)FUN_00105594(param_1,iVar5);
          (**(code **)(*a0 + 0x60))(a0);
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 <= param_1[0x21]);
    }
    bVar1 = iVar2 != 3;
    iVar2 = iVar2 + 1;
  } while (bVar1);
  (**(code **)(*param_1 + 0x14))(param_1);
  ((int (*)())FUN_0010647c)(param_1,param_2);
  return;
}

/* FUN_00106cb4 @ 0x106cb4 (68 bytes) */
int FUN_00106cb4(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  (**(code **)(*param_1 + 0x14))(param_1,param_2);
  ((int (*)())FUN_0010647c)(param_1,param_2);
  return;
}

/* FUN_00106cf8 @ 0x106cf8 (772 bytes) */
int FUN_00106cf8(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  if ((param_1[5] & 0x200U) != 0) {
    piVar1 = (int *)FUN_00105594(param_1,param_1[0x21]);
    iVar2 = (**(code **)(*piVar1 + 0x50))(piVar1);
    if (iVar2 == 0) {
      if (piVar1[0x20] == 0) {
        return 0;
      }
      iVar2 = FUN_00126760(piVar1[0x26]);
      if (iVar2 == 0) {
        return 0;
      }
      if ((piVar1[5] & 2U) != 0) {
        return 0;
      }
      iVar2 = (**(code **)(*piVar1 + 0x50))(piVar1);
      if (iVar2 != 0) {
        return 0;
      }
      iVar2 = thunk_FUN_00134de8(param_2,piVar1);
      iVar3 = thunk_FUN_00134de8(param_2,param_1);
      if (iVar2 != iVar3) {
        return 0;
      }
    }
  }
  iVar2 = (**(code **)(*param_1 + 100))(param_1);
  if (iVar2 != 0) {
    for (iVar2 = 1; iVar3 = (**(code **)(*param_1 + 0x14))(param_1), iVar2 <= iVar3;
        iVar2 = iVar2 + 1) {
      if ((param_1[iVar2 * 6 + 0x28] & 1U) != 0) {
        return 0;
      }
      if ((param_1[iVar2 * 6 + 0x28] & 2U) != 0) {
        return 0;
      }
      iVar3 = FUN_000f31e8(param_1,iVar2);
      if (iVar3 == 0) {
        return 0;
      }
    }
    if ((param_1[0x48] == 0) && (param_1[0x49] == 0)) {
      if ((param_1[0x20] != 0) &&
         (((iVar2 = FUN_00126760(param_1[0x26]), iVar2 != 0 && ((param_1[5] & 2U) == 0)) &&
          (iVar2 = (**(code **)(*param_1 + 0x50))(param_1), iVar2 == 0)))) {
        iVar2 = 4;
        piVar1 = param_1;
        do {
          if (*(byte *)(piVar1 + 0x27) - 2 < 2) {
            return 0;
          }
          piVar1 = (int *)((int)piVar1 + 1);
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
      FUN_001054ec(param_1,0);
      iVar2 = ((int (*)())FUN_00105dbc)(param_1,0);
      if ((((iVar2 == 0) && ((param_1[5] & 2U) == 0)) &&
          ((param_1[0x20] != 0 &&
           ((iVar2 = FUN_00126760(param_1[0x26]), iVar2 != 0 && ((param_1[5] & 2U) == 0)))))) &&
         (iVar2 = (**(code **)(*param_1 + 0x50))(param_1), iVar2 == 0)) {
        piVar1 = (int *)FUN_00105594(param_1,1);
        iVar2 = (**(code **)(*piVar1 + 0x50))(piVar1);
        if (iVar2 != 0) {
          return 1;
        }
        piVar1 = (int *)FUN_00105594(param_1,1);
        if ((((piVar1[0x20] != 0) && (iVar2 = FUN_00126760(piVar1[0x26]), iVar2 != 0)) &&
            ((piVar1[5] & 2U) == 0)) && (iVar2 = (**(code **)(*piVar1 + 0x50))(piVar1), iVar2 == 0))
        {
          uVar4 = FUN_00105594(param_1,1);
          iVar2 = thunk_FUN_00134de8(param_2,uVar4);
          iVar3 = thunk_FUN_00134de8(param_2,param_1);
          if (iVar2 == iVar3) {
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

/* FUN_00106ffc @ 0x106ffc (80 bytes) */
int FUN_00106ffc(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined *puVar1;
  
  FUN_001051b0(param_1,param_2,param_3);
  puVar1 = PTR_DAT_001e8c64;
  param_1[0x20] = 1;
  param_1[0x21] = 1;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_0010704c @ 0x10704c (80 bytes) */
int FUN_0010704c(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined *puVar1;
  
  FUN_001051b0(param_1,param_2,param_3);
  puVar1 = PTR_DAT_001e8c64;
  param_1[0x20] = 1;
  param_1[0x21] = 1;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_0010709c @ 0x10709c (92 bytes) */
int FUN_0010709c(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined *puVar1;
  
  FUN_001051b0(param_1,param_2,param_3);
  puVar1 = PTR_DAT_001e8b50;
  param_1[5] = param_1[5] | 0x18000;
  *param_1 = puVar1 + 8;
  param_1[0x20] = 0;
  return;
}

/* FUN_001070f8 @ 0x1070f8 (92 bytes) */
int FUN_001070f8(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined *puVar1;
  
  FUN_001051b0(param_1,param_2,param_3);
  puVar1 = PTR_DAT_001e8b50;
  param_1[5] = param_1[5] | 0x18000;
  *param_1 = puVar1 + 8;
  param_1[0x20] = 0;
  return;
}

/* FUN_00107154 @ 0x107154 (84 bytes) */
int FUN_00107154(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined *puVar1;
  
  FUN_001051b0(param_1,param_2,param_3);
  puVar1 = PTR_DAT_001e8c58;
  param_1[0x4b] = 0;
  param_1[0x20] = 1;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_001071a8 @ 0x1071a8 (84 bytes) */
int FUN_001071a8(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined *puVar1;
  
  FUN_001051b0(param_1,param_2,param_3);
  puVar1 = PTR_DAT_001e8c58;
  param_1[0x4b] = 0;
  param_1[0x20] = 1;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_001071fc @ 0x1071fc (84 bytes) */
int FUN_001071fc(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined *puVar1;
  
  ((int (*)())FUN_0010704c)(param_1,param_2,param_3);
  puVar1 = PTR_DAT_001e8c10;
  param_1[0x4b] = 0;
  param_1[0x21] = 2;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_00107250 @ 0x107250 (128 bytes) */
int FUN_00107250(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  undefined4 uVar1;
  undefined *puVar2;
  
  ((int (*)())FUN_0010704c)(param_1,param_2,param_3);
  uVar1 = DAT_001af9bc;
  puVar2 = PTR_DAT_001e8c08 + 8;
  param_1[0x4b] = param_5;
  *param_1 = puVar2;
  param_1[0x4f] = 0;
  param_1[0x50] = uVar1;
  param_1[0x4c] = param_4;
  param_1[0x4d] = 0;
  param_1[0x4e] = 0;
  FUN_00104330(param_1);
  return;
}

/* FUN_001072d0 @ 0x1072d0 (128 bytes) */
int FUN_001072d0(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  undefined4 uVar1;
  undefined *puVar2;
  
  ((int (*)())FUN_0010704c)(param_1,param_2,param_3);
  uVar1 = DAT_001af9bc;
  puVar2 = PTR_DAT_001e8c08 + 8;
  param_1[0x4b] = param_5;
  *param_1 = puVar2;
  param_1[0x4f] = 0;
  param_1[0x50] = uVar1;
  param_1[0x4c] = param_4;
  param_1[0x4d] = 0;
  param_1[0x4e] = 0;
  FUN_00104330(param_1);
  return;
}

/* FUN_00107350 @ 0x107350 (84 bytes) */
int FUN_00107350(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_2 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x168);
  *puVar1 = uVar2;
  ((int (*)())FUN_001072d0)(puVar1 + 1,param_1,param_2,param_3,param_4);
  return puVar1 + 1;
}

/* FUN_001073dc @ 0x1073dc (68 bytes) */
int FUN_001073dc(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())FUN_0010704c)(param_1,param_2,param_3);
  *param_1 = PTR_DAT_001e8c08 + 8;
  return;
}

/* FUN_00107420 @ 0x107420 (68 bytes) */
int FUN_00107420(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())FUN_0010704c)(param_1,param_2,param_3);
  *param_1 = PTR_DAT_001e8c08 + 8;
  return;
}

/* FUN_00107464 @ 0x107464 (68 bytes) */
int FUN_00107464(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_2 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x168);
  *puVar1 = uVar2;
  ((int (*)())FUN_00107420)(puVar1 + 1,param_1,param_2);
  return puVar1 + 1;
}

/* FUN_001074e0 @ 0x1074e0 (232 bytes) */
int FUN_001074e0(param_1, param_2, param_3)
  undefined4 *param_1;
  int param_2;
  int param_3;
{
  undefined4 uVar1;
  undefined *puVar2;
  undefined2 *puVar3;
  
  ((int (*)())FUN_0010704c)(param_1,param_2,param_3);
  puVar2 = PTR_DAT_001e8c0c;
  param_1[0x4c] = 0;
  param_1[0x4d] = 0xffffffff;
  *param_1 = puVar2 + 8;
  param_1[0x26] = 0;
  param_1[0x2c] = 0;
  param_1[0x42] = 0;
  param_1[0x41] = 0;
  puVar3 = (undefined2 *)FUN_00193e18(*(undefined4 *)(param_3 + 0x374),0x24);
  _memset(puVar3,0,0x24);
  uVar1 = DAT_001af9bc;
  puVar3[4] = 7;
  puVar3[6] = 3;
  puVar3[9] = 1;
  puVar3[10] = 0;
  *puVar3 = 3;
  puVar3[1] = 3;
  puVar3[2] = 3;
  puVar3[3] = 7;
  puVar3[5] = 3;
  puVar3[7] = 1;
  puVar3[8] = 0;
  puVar3[0xb] = 0;
  puVar3[0xc] = 0;
  puVar3[0xd] = 0;
  puVar3[0xe] = 0;
  param_1[0x4f] = puVar3;
  param_1[0x4e] = 0xffffffff;
  param_1[0x50] = uVar1;
  if (param_2 == 0x77) {
    param_1[5] = param_1[5] | 8;
  }
  return;
}

/* FUN_00107600 @ 0x107600 (76 bytes) */
int FUN_00107600(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined *puVar1;
  
  ((int (*)())FUN_001074e0)(param_1,param_2,param_3);
  puVar1 = PTR_DAT_001e8c48;
  param_1[0x21] = 3;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_0010764c @ 0x10764c (232 bytes) */
int FUN_0010764c(param_1, param_2, param_3)
  undefined4 *param_1;
  int param_2;
  int param_3;
{
  undefined4 uVar1;
  undefined *puVar2;
  undefined2 *puVar3;
  
  ((int (*)())FUN_0010704c)(param_1,param_2,param_3);
  puVar2 = PTR_DAT_001e8c0c;
  param_1[0x4c] = 0;
  param_1[0x4d] = 0xffffffff;
  *param_1 = puVar2 + 8;
  param_1[0x26] = 0;
  param_1[0x2c] = 0;
  param_1[0x42] = 0;
  param_1[0x41] = 0;
  puVar3 = (undefined2 *)FUN_00193e18(*(undefined4 *)(param_3 + 0x374),0x24);
  _memset(puVar3,0,0x24);
  uVar1 = DAT_001af9bc;
  puVar3[4] = 7;
  puVar3[6] = 3;
  puVar3[9] = 1;
  puVar3[10] = 0;
  *puVar3 = 3;
  puVar3[1] = 3;
  puVar3[2] = 3;
  puVar3[3] = 7;
  puVar3[5] = 3;
  puVar3[7] = 1;
  puVar3[8] = 0;
  puVar3[0xb] = 0;
  puVar3[0xc] = 0;
  puVar3[0xd] = 0;
  puVar3[0xe] = 0;
  param_1[0x4f] = puVar3;
  param_1[0x4e] = 0xffffffff;
  param_1[0x50] = uVar1;
  if (param_2 == 0x77) {
    param_1[5] = param_1[5] | 8;
  }
  return;
}

/* FUN_0010776c @ 0x10776c (68 bytes) */
int FUN_0010776c(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_2 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x168);
  *puVar1 = uVar2;
  ((int (*)())FUN_0010764c)(puVar1 + 1,param_1,param_2);
  return puVar1 + 1;
}

/* FUN_001077e8 @ 0x1077e8 (68 bytes) */
int FUN_001077e8(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_2 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x168);
  *puVar1 = uVar2;
  ((int (*)())FUN_0010764c)(puVar1 + 1,param_1,param_2);
  return puVar1 + 1;
}

/* FUN_00107864 @ 0x107864 (76 bytes) */
int FUN_00107864(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined *puVar1;
  
  ((int (*)())FUN_001074e0)(param_1,param_2,param_3);
  puVar1 = PTR_DAT_001e8c48;
  param_1[0x21] = 3;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_001078b0 @ 0x1078b0 (68 bytes) */
int FUN_001078b0(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_2 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x168);
  *puVar1 = uVar2;
  ((int (*)())FUN_00107864)(puVar1 + 1,param_1,param_2);
  return puVar1 + 1;
}

/* FUN_0010792c @ 0x10792c (84 bytes) */
int FUN_0010792c(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined *puVar1;
  
  ((int (*)())FUN_0010704c)(param_1,param_2,param_3);
  puVar1 = PTR_DAT_001e8c50;
  param_1[0x4b] = 0;
  param_1[0x21] = 2;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_00107980 @ 0x107980 (84 bytes) */
int FUN_00107980(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined *puVar1;
  
  ((int (*)())FUN_0010704c)(param_1,param_2,param_3);
  puVar1 = PTR_DAT_001e8c50;
  param_1[0x4b] = 0;
  param_1[0x21] = 2;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_001079d4 @ 0x1079d4 (84 bytes) */
int FUN_001079d4(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined *puVar1;
  
  ((int (*)())FUN_0010704c)(param_1,param_2,param_3);
  puVar1 = PTR_DAT_001e8c10;
  param_1[0x4b] = 0;
  param_1[0x21] = 2;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_00107a28 @ 0x107a28 (76 bytes) */
int FUN_00107a28(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined *puVar1;
  
  ((int (*)())FUN_001071a8)(param_1,param_2,param_3);
  puVar1 = PTR_DAT_001e8c2c;
  param_1[0x21] = 0;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_00107a74 @ 0x107a74 (92 bytes) */
int FUN_00107a74(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 uVar1;
  undefined *puVar2;
  
  ((int (*)())FUN_00107a28)(param_1,param_2,param_3);
  uVar1 = DAT_001af9c8;
  puVar2 = PTR_DAT_001e8be8 + 8;
  param_1[0x20] = 0;
  *param_1 = puVar2;
  param_1[0x27] = uVar1;
  param_1[0x21] = 0;
  return;
}

/* FUN_00107ad0 @ 0x107ad0 (68 bytes) */
int FUN_00107ad0(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_2 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x168);
  *puVar1 = uVar2;
  ((int (*)())FUN_00107a74)(puVar1 + 1,param_1,param_2);
  return puVar1 + 1;
}

/* FUN_00107b4c @ 0x107b4c (92 bytes) */
int FUN_00107b4c(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 uVar1;
  undefined *puVar2;
  
  ((int (*)())FUN_00107a28)(param_1,param_2,param_3);
  uVar1 = DAT_001af9c8;
  puVar2 = PTR_DAT_001e8be8 + 8;
  param_1[0x20] = 0;
  *param_1 = puVar2;
  param_1[0x27] = uVar1;
  param_1[0x21] = 0;
  return;
}

/* FUN_00107ba8 @ 0x107ba8 (76 bytes) */
int FUN_00107ba8(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined *puVar1;
  
  ((int (*)())FUN_001071a8)(param_1,param_2,param_3);
  puVar1 = PTR_DAT_001e8c2c;
  param_1[0x21] = 0;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_00107bf4 @ 0x107bf4 (68 bytes) */
int FUN_00107bf4(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_2 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x168);
  *puVar1 = uVar2;
  ((int (*)())FUN_00107ba8)(puVar1 + 1,param_1,param_2);
  return puVar1 + 1;
}

/* FUN_00107c70 @ 0x107c70 (68 bytes) */
int FUN_00107c70(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_2 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x168);
  *puVar1 = uVar2;
  ((int (*)())FUN_00107ba8)(puVar1 + 1,param_1,param_2);
  return puVar1 + 1;
}

/* FUN_00107cec @ 0x107cec (76 bytes) */
int FUN_00107cec(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined *puVar1;
  
  ((int (*)())FUN_001071a8)(param_1,param_2,param_3);
  puVar1 = PTR_DAT_001e8c68;
  param_1[0x21] = 1;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_00107d38 @ 0x107d38 (112 bytes) */
int FUN_00107d38(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  bool bVar1;
  undefined *puVar2;
  int iVar3;
  
  ((int (*)())FUN_00107cec)(param_1,param_2,param_3);
  puVar2 = PTR_DAT_001e8bf0;
  param_1[0x20] = 1;
  *param_1 = puVar2 + 8;
  iVar3 = 0;
  do {
    bVar1 = iVar3 != 1;
    param_1[0x25] = 0xffffffff;
    param_1[0x26] = 0;
    iVar3 = iVar3 + 1;
    param_1 = param_1 + 6;
  } while (bVar1);
  return;
}

/* FUN_00107da8 @ 0x107da8 (76 bytes) */
int FUN_00107da8(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined *puVar1;
  
  ((int (*)())FUN_001071a8)(param_1,param_2,param_3);
  puVar1 = PTR_DAT_001e8c68;
  param_1[0x21] = 1;
  *param_1 = puVar1 + 8;
  return;
}

