#include "decls.h"

/* FUN_0010abd6 @ 0x10abd6 (89 bytes) */
int FUN_0010abd6(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x88) + 8);
  if (iVar1 < 0xae) {
    if ((0xaa < iVar1) || ((0x23 < iVar1 && ((iVar1 < 0x27 || (iVar1 == 0x9d)))))) {
      return 1;
    }
  }
  else if (0xeb < iVar1) {
    if (iVar1 < 0xef) {
      return 1;
    }
    if (iVar1 - 0xf2U < 3) {
      return 1;
    }
  }
  return 0;
}

/* FUN_0010ac30 @ 0x10ac30 (316 bytes) */
int FUN_0010ac30(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  int param_3;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  param_1[1] = 0;
  param_1[2] = 0;
  *param_1 = &PTR_FUN_001fc5e8;
  param_1[0x1f] = 0;
  puVar2 = param_1 + 0x23;
  iVar3 = 5;
  do {
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[5] = 0;
    puVar2 = puVar2 + 6;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  iVar3 = *(int *)(param_3 + 0x68);
  param_1[0x53] = iVar3;
  *(int *)(param_3 + 0x68) = iVar3 + 1;
  param_1[0x54] = 0;
  param_1[0x56] = 0;
  *(undefined1 *)(param_1 + 0x57) = 0;
  param_1[0x58] = 0;
  iVar3 = 2;
  puVar2 = param_1;
  do {
    puVar2[5] = 0;
    puVar2 = puVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  uVar1 = FUN_00118f66(param_2);
  param_1[0x22] = uVar1;
  param_1[5] = param_1[5] | 1;
  FUN_0010a85e(param_1,param_3);
  (*(code *)**(undefined4 **)param_1[0x22])((undefined4 *)param_1[0x22],param_1,param_3);
  if (-1 < *(char *)(*(int *)(param_3 + 0x3f4) + 0x30)) {
    return;
  }
  uVar1 = *(undefined4 *)(param_3 + 0xbc);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x14);
  *puVar2 = uVar1;
  puVar2[4] = uVar1;
  puVar2[2] = 0;
  puVar2[1] = 2;
  uVar1 = FUN_001a7bca(uVar1,8);
  puVar2[3] = uVar1;
  param_1[4] = puVar2 + 1;
  return;
}

/* FUN_0010ad9e @ 0x10ad9e (316 bytes) */
int FUN_0010ad9e(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  int param_3;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  param_1[1] = 0;
  param_1[2] = 0;
  *param_1 = &PTR_FUN_001fc5e8;
  param_1[0x1f] = 0;
  puVar2 = param_1 + 0x23;
  iVar3 = 5;
  do {
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[5] = 0;
    puVar2 = puVar2 + 6;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  iVar3 = *(int *)(param_3 + 0x68);
  param_1[0x53] = iVar3;
  *(int *)(param_3 + 0x68) = iVar3 + 1;
  param_1[0x54] = 0;
  param_1[0x56] = 0;
  *(undefined1 *)(param_1 + 0x57) = 0;
  param_1[0x58] = 0;
  iVar3 = 2;
  puVar2 = param_1;
  do {
    puVar2[5] = 0;
    puVar2 = puVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  uVar1 = FUN_00118f66(param_2);
  param_1[0x22] = uVar1;
  param_1[5] = param_1[5] | 1;
  FUN_0010a85e(param_1,param_3);
  (*(code *)**(undefined4 **)param_1[0x22])((undefined4 *)param_1[0x22],param_1,param_3);
  if (-1 < *(char *)(*(int *)(param_3 + 0x3f4) + 0x30)) {
    return;
  }
  uVar1 = *(undefined4 *)(param_3 + 0xbc);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x14);
  *puVar2 = uVar1;
  puVar2[4] = uVar1;
  puVar2[2] = 0;
  puVar2[1] = 2;
  uVar1 = FUN_001a7bca(uVar1,8);
  puVar2[3] = uVar1;
  param_1[4] = puVar2 + 1;
  return;
}

/* FUN_0010af0c @ 0x10af0c (457 bytes) */
int FUN_0010af0c(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  uint uVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  uint *puVar5;
  uint uVar6;
  
  if (param_2 < 5) {
    *(undefined4 *)(param_1 + 0x90 + param_2 * 0x18) = param_3;
    return;
  }
  if (*(int *)(param_1 + 0x118) == 0) {
    uVar4 = *(undefined4 *)(param_4 + 0xb8);
    puVar3 = (undefined4 *)FUN_001a7bca(uVar4,0x14);
    *puVar3 = uVar4;
    puVar3[4] = uVar4;
    puVar3[2] = 0;
    puVar3[1] = 2;
    uVar4 = FUN_001a7bca(uVar4,8);
    puVar3[3] = uVar4;
    *(undefined4 **)(param_1 + 0x118) = puVar3 + 1;
  }
  puVar5 = *(uint **)(param_1 + 0x118);
  if ((int)puVar5[1] < (int)(param_2 - 4U)) {
    uVar4 = *(undefined4 *)(param_4 + 0xb8);
    puVar3 = (undefined4 *)FUN_001a7bca(uVar4,0x1c);
    *puVar3 = uVar4;
    puVar3[1] = 0;
    puVar3[2] = 0;
    puVar3[6] = 0;
    puVar5 = *(uint **)(param_1 + 0x118);
    uVar1 = puVar5[1];
    if (uVar1 < *puVar5) {
      _memset((void *)(uVar1 * 4 + puVar5[2]),0,4);
      puVar5[1] = uVar1 + 1;
      piVar2 = (int *)(uVar1 * 4 + puVar5[2]);
    }
    else {
      piVar2 = (int *)FUN_001a7f7c(puVar5,uVar1);
    }
    *piVar2 = (int)(puVar3 + 1);
    FUN_00109cac(puVar3 + 1,param_2);
    puVar5 = *(uint **)(param_1 + 0x118);
    if (*puVar5 <= param_2 - 5U) goto LAB_0010af86;
  }
  else if (*puVar5 <= param_2 - 5U) {
LAB_0010af86:
    piVar2 = (int *)FUN_001a7f7c(puVar5,param_2 + -5);
    goto LAB_0010af77;
  }
  uVar6 = param_2 - 5;
  uVar1 = puVar5[1];
  if (uVar1 <= uVar6) {
    _memset((void *)(puVar5[2] + uVar1 * 4),0,(uVar6 - uVar1) * 4 + 4);
    puVar5[1] = param_2 - 4U;
  }
  piVar2 = (int *)(puVar5[2] + uVar6 * 4);
LAB_0010af77:
  *(undefined4 *)(*piVar2 + 4) = param_3;
  return;
}

/* FUN_0010b0f4 @ 0x10b0f4 (139 bytes) */
int FUN_0010b0f4(param_1, param_2)
  int param_1;
  int param_2;
{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  
  if (param_2 < 5) {
    return param_1 + 0x8c + param_2 * 0x18;
  }
  uVar5 = param_2 - 5;
  puVar1 = *(uint **)(param_1 + 0x118);
  if (uVar5 < *puVar1) {
    uVar2 = puVar1[1];
    if (uVar2 <= uVar5) {
      _memset((void *)(puVar1[2] + uVar2 * 4),0,(uVar5 - uVar2) * 4 + 4);
      puVar1[1] = param_2 - 4;
    }
    iVar3 = *(int *)(puVar1[2] + uVar5 * 4);
  }
  else {
    piVar4 = (int *)FUN_001a7f7c(puVar1,uVar5);
    iVar3 = *piVar4;
  }
  return iVar3;
}

/* FUN_0010b180 @ 0x10b180 (41 bytes) */
int FUN_0010b180(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  int iVar1;
  
  iVar1 = ((int (*)())FUN_0010b0f4)(param_1,param_2);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 4) != 0)) {
    return *(int *)(iVar1 + 4);
  }
  return 0;
}

/* FUN_0010b1aa @ 0x10b1aa (83 bytes) */
int FUN_0010b1aa(param_1)
  int *param_1;
{
  char cVar1;
  int iVar2;
  bool bVar3;
  
  cVar1 = (**(code **)(*param_1 + 0x54))(param_1);
  if (cVar1 == '\0') {
    bVar3 = false;
  }
  else {
    iVar2 = ((int (*)())FUN_0010b180)(param_1,1);
    if (iVar2 != 0) {
      return *(int *)(iVar2 + 0x98) == 0x2a;
    }
    bVar3 = param_1[0x2c] == 0x2a;
  }
  return bVar3;
}

/* FUN_0010b1fe @ 0x10b1fe (511 bytes) */
int FUN_0010b1fe(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int local_18;
  int local_14;
  int local_10;
  
  iVar2 = FUN_00109e42(param_1,*(undefined4 *)(param_2 + 0x3f4));
  if (iVar2 == 0) {
    if ((param_3 == '\0') && (0 < param_1[0x21])) {
      iVar2 = 1;
      do {
        iVar5 = ((int (*)())FUN_0010b180)(param_1,iVar2);
        *(int *)(iVar5 + 0x160) = *(int *)(iVar5 + 0x160) + -1;
        iVar2 = iVar2 + 1;
      } while (iVar2 <= param_1[0x21]);
      iVar2 = param_1[0x21];
    }
    else {
      iVar2 = param_1[0x21];
    }
    if (0 < iVar2) {
      local_18 = 1;
      do {
        piVar3 = (int *)((int (*)())FUN_0010b180)(param_1,local_18);
        cVar1 = (**(code **)(*piVar3 + 0x5c))(piVar3);
        if (((cVar1 != '\0') || (cVar1 = (**(code **)(*piVar3 + 0x60))(piVar3), cVar1 != '\0')) &&
           (iVar2 = FUN_00109e42(piVar3,*(undefined4 *)(param_2 + 0x3f4)), iVar2 == 0)) {
          local_14 = 1;
          iVar2 = (**(code **)(*piVar3 + 0x14))(piVar3);
          if (0 < iVar2) {
            do {
              piVar4 = (int *)((int (*)())FUN_0010b180)(piVar3,local_14);
              piVar4[0x58] = piVar4[0x58] + -1;
              cVar1 = (**(code **)(*piVar4 + 0x5c))(piVar4);
              if ((cVar1 != '\0') &&
                 (iVar2 = FUN_00109e42(piVar4,*(undefined4 *)(param_2 + 0x3f4)), iVar2 == 0)) {
                (**(code **)(*piVar3 + 0x60))(piVar3);
                for (local_10 = 1; iVar2 = (**(code **)(*piVar4 + 0x14))(piVar4), local_10 <= iVar2;
                    local_10 = local_10 + 1) {
                  iVar2 = ((int (*)())FUN_0010b180)(piVar4,local_10);
                  *(int *)(iVar2 + 0x160) = *(int *)(iVar2 + 0x160) + -1;
                }
                (**(code **)(*piVar4 + 0xc))(piVar4,param_3,param_2);
              }
              local_14 = local_14 + 1;
              iVar2 = (**(code **)(*piVar3 + 0x14))(piVar3);
            } while (local_14 <= iVar2);
          }
          (**(code **)(*piVar3 + 0xc))(piVar3,param_3,param_2);
        }
        local_18 = local_18 + 1;
      } while (local_18 <= param_1[0x21]);
    }
    (**(code **)(*param_1 + 0xc))(param_1,param_3,param_2);
    return 1;
  }
  return 0;
}

/* FUN_0010b3fe @ 0x10b3fe (44 bytes) */
int FUN_0010b3fe(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined1 uVar1;
  
  *(int *)(param_1 + 0x160) = *(int *)(param_1 + 0x160) + -1;
  uVar1 = ((int (*)())FUN_0010b1fe)(param_1,param_2,0);
  return uVar1;
}

/* FUN_0010b42a @ 0x10b42a (95 bytes) */
int FUN_0010b42a(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  
  if ((*(char *)(param_2 + 0x30) < '\0') && (0 < *(int *)(param_1 + 0x84))) {
    iVar2 = 1;
    do {
      iVar1 = ((int (*)())FUN_0010b180)(param_1,iVar2);
      if (iVar1 != 0) {
        iVar1 = ((int (*)())FUN_0010b180)(param_1,iVar2);
        *(int *)(iVar1 + 0x160) = *(int *)(iVar1 + 0x160) + -1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 <= *(int *)(param_1 + 0x84));
    return;
  }
  return;
}

/* FUN_0010b48a @ 0x10b48a (238 bytes) */
int FUN_0010b48a(param_1, param_2)
  int param_1;
  int param_2;
{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int local_10;
  
  if ((-1 < *(char *)(param_2 + 0x30)) || (*(int *)(param_1 + 0x84) < 1)) {
    return;
  }
  local_10 = 1;
  do {
    iVar3 = ((int (*)())FUN_0010b180)(param_1,local_10);
    if (iVar3 != 0) {
      iVar3 = ((int (*)())FUN_0010b180)(param_1,local_10);
      puVar1 = *(uint **)(iVar3 + 0x10);
      if (0 < (int)puVar1[1]) {
        uVar5 = 0;
        do {
          if (uVar5 < *puVar1) {
            uVar2 = puVar1[1];
            if (uVar2 <= uVar5) {
              _memset((void *)(puVar1[2] + uVar2 * 4),0,(uVar5 - uVar2) * 4 + 4);
              puVar1[1] = uVar5 + 1;
            }
            if (param_1 != *(int *)(puVar1[2] + uVar5 * 4)) goto LAB_0010b500;
LAB_0010b51f:
            FUN_001a7f3c(puVar1,uVar5);
            break;
          }
          piVar4 = (int *)FUN_001a7f7c(puVar1,uVar5);
          if (param_1 == *piVar4) goto LAB_0010b51f;
LAB_0010b500:
          uVar5 = uVar5 + 1;
        } while ((int)uVar5 < (int)puVar1[1]);
      }
    }
    local_10 = local_10 + 1;
    if (*(int *)(param_1 + 0x84) < local_10) {
      return;
    }
  } while( true );
}

/* FUN_0010b578 @ 0x10b578 (154 bytes) */
int FUN_0010b578(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  
  cVar3 = (**(code **)(*param_1 + 0x34))(param_1);
  if (cVar3 == '\0') {
    (**(code **)(*param_1 + 0x38))(param_1);
  }
  ((int (*)())FUN_0010b48a)(param_1,*(undefined4 *)(param_2 + 0x3f4));
  iVar1 = param_1[1];
  cVar3 = (**(code **)(*param_1 + 0x40))(param_1);
  if ((cVar3 != '\0') &&
     (iVar2 = *(int *)(*(int *)(param_2 + 0x3f4) + 0x394), param_1 == *(int **)(iVar2 + 0x124))) {
    *(int *)(iVar2 + 0x124) = iVar1;
  }
  uVar4 = param_1[5];
  if ((((uVar4 & 4) == 0) && (iVar1 != 0)) && ((*(uint *)(iVar1 + 0x14) & 4) != 0)) {
    *(uint *)(iVar1 + 0x14) = *(uint *)(iVar1 + 0x14) & 0xfffffffb;
    uVar4 = param_1[5];
  }
  param_1[5] = uVar4 & 0xfffffffe;
  FUN_001a7d72();
  return;
}

/* FUN_0010b612 @ 0x10b612 (56 bytes) */
int FUN_0010b612(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  if (-1 < *(char *)(param_2 + 0x30)) {
    return;
  }
  ((int (*)())FUN_0010b48a)(param_1,param_2);
  ((int (*)())FUN_0010b42a)();
  return;
}

/* FUN_0010b64a @ 0x10b64a (154 bytes) */
int FUN_0010b64a(param_1, param_2, param_3)
  int *param_1;
  undefined4 param_2;
  int param_3;
{
  int iVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  
  cVar3 = (**(code **)(*param_1 + 0x34))(param_1);
  if (cVar3 == '\0') {
    (**(code **)(*param_1 + 0x38))(param_1);
  }
  ((int (*)())FUN_0010b612)(param_1,*(undefined4 *)(param_3 + 0x3f4));
  iVar1 = param_1[1];
  cVar3 = (**(code **)(*param_1 + 0x40))(param_1);
  if ((cVar3 != '\0') &&
     (iVar2 = *(int *)(*(int *)(param_3 + 0x3f4) + 0x394), param_1 == *(int **)(iVar2 + 0x124))) {
    *(int *)(iVar2 + 0x124) = iVar1;
  }
  uVar4 = param_1[5];
  if ((((uVar4 & 4) == 0) && (iVar1 != 0)) && ((*(uint *)(iVar1 + 0x14) & 4) != 0)) {
    *(uint *)(iVar1 + 0x14) = *(uint *)(iVar1 + 0x14) & 0xfffffffb;
    uVar4 = param_1[5];
  }
  param_1[5] = uVar4 & 0xfffffffe;
  FUN_001a7d72();
  return;
}

/* FUN_0010b6e4 @ 0x10b6e4 (114 bytes) */
int FUN_0010b6e4(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  while( true ) {
    if (param_2 == 0) {
      return *(undefined4 *)(param_1 + 0x128);
    }
    iVar2 = ((int (*)())FUN_0010b180)(param_1,param_2);
    if (iVar2 == 0) break;
    param_1 = ((int (*)())FUN_0010b180)(param_1,param_2);
    param_2 = 0;
  }
  piVar1 = *(int **)(param_1 + 0x8c + param_2 * 0x18);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
                    
                    
  uVar3 = (**(code **)(*piVar1 + 0x24))();
  return uVar3;
}

/* FUN_0010b756 @ 0x10b756 (113 bytes) */
int FUN_0010b756(param_1)
  int *param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((*(byte *)((int)param_1 + 0x15) & 2) == 0) {
    iVar3 = param_1[0x21];
  }
  else {
    iVar3 = param_1[0x21] + -1;
  }
  iVar1 = (**(code **)(*param_1 + 0x14))(param_1);
  do {
    iVar1 = iVar1 + 1;
    if (iVar3 < iVar1) {
      return DAT_001cbe68;
    }
    iVar2 = ((int (*)())FUN_0010b0f4)(param_1,iVar1);
  } while ((*(byte *)(*(int *)(iVar2 + 4) + 0x16) & 8) == 0);
  return *(undefined4 *)(iVar2 + 0x10);
}

/* FUN_0010b7c8 @ 0x10b7c8 (149 bytes) */
int FUN_0010b7c8(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  char cVar1;
  int iVar2;
  
  if ((param_2 < 1) || (iVar2 = ((int (*)())FUN_0010b180)(param_1,param_2), iVar2 == 0)) {
    iVar2 = ((int (*)())FUN_0010b0f4)(param_1,param_2);
    cVar1 = PTR_PTR_00213559[*(int *)(iVar2 + 0xc) * 0x10 + 9];
  }
  else {
    iVar2 = ((int (*)())FUN_0010b180)(param_1,param_2);
    cVar1 = PTR_PTR_00213559[*(int *)(iVar2 + 0x98) * 0x10 + 9];
  }
  if (cVar1 != '\x01') {
    if (cVar1 == '\x02') {
      return 1;
    }
    return 0;
  }
  return 2;
}

/* FUN_0010b85e @ 0x10b85e (59 bytes) */
int FUN_0010b85e(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())FUN_0010b0f4)(param_3,param_4);
  FUN_0010a40a();
  return;
}

/* FUN_0010b89a @ 0x10b89a (110 bytes) */
int FUN_0010b89a(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x84);
  iVar1 = iVar2 + 1;
  *(int *)(param_1 + 0x84) = iVar1;
  if ((*(byte *)(param_1 + 0x15) & 2) != 0) {
    ((int (*)())FUN_0010b85e)(param_1,iVar1,param_1,iVar2);
    FUN_0010a3c2(param_1,*(int *)(param_1 + 0x84) + -1,param_2);
    return;
  }
  FUN_0010a3c2(param_1,iVar1,param_2);
  return;
}

/* FUN_0010b908 @ 0x10b908 (250 bytes) */
int FUN_0010b908(param_1, param_2)
  int param_1;
  int param_2;
{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int local_10;
  
  if ((*(char *)(param_2 + 0x30) < '\0') && (0 < *(int *)(param_1 + 0x84))) {
    local_10 = 1;
    do {
      iVar3 = ((int (*)())FUN_0010b180)(param_1,local_10);
      if (iVar3 != 0) {
        iVar3 = ((int (*)())FUN_0010b180)(param_1,local_10);
        puVar1 = *(uint **)(iVar3 + 0x10);
        uVar2 = puVar1[1];
        if (uVar2 < *puVar1) {
          _memset((void *)(uVar2 * 4 + puVar1[2]),0,4);
          puVar1[1] = uVar2 + 1;
          piVar4 = (int *)(uVar2 * 4 + puVar1[2]);
        }
        else {
          piVar4 = (int *)FUN_001a7f7c(puVar1,uVar2);
        }
        *piVar4 = param_1;
        iVar3 = *(int *)(param_2 + 0x46c);
        iVar5 = ((int (*)())FUN_0010b180)(param_1,local_10);
        if (iVar3 < *(int *)(iVar5 + 0x160)) {
          *(int *)(iVar5 + 0x160) = *(int *)(iVar5 + 0x160) + 1;
        }
        else {
          *(int *)(iVar5 + 0x160) = iVar3 + 1;
        }
      }
      local_10 = local_10 + 1;
    } while (local_10 <= *(int *)(param_1 + 0x84));
  }
  return;
}

/* FUN_0010ba02 @ 0x10ba02 (426 bytes) */
int FUN_0010ba02(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 param_2;
  int param_3;
  int param_4;
  int param_5;
{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  
  iVar1 = *(int *)(param_5 + 0x3f4);
  if (param_4 != '\0') {
    iVar5 = ((int (*)())FUN_0010b180)(param_1,param_2);
    if (iVar5 != 0) {
      iVar5 = ((int (*)())FUN_0010b180)(param_1,param_2);
      puVar2 = *(uint **)(iVar5 + 0x10);
      if (0 < (int)puVar2[1]) {
        uVar6 = 0;
        do {
          if (uVar6 < *puVar2) {
            uVar3 = puVar2[1];
            if (uVar3 <= uVar6) {
              _memset((void *)(puVar2[2] + uVar3 * 4),0,(uVar6 - uVar3) * 4 + 4);
              puVar2[1] = uVar6 + 1;
            }
            piVar4 = (int *)(puVar2[2] + uVar6 * 4);
          }
          else {
            piVar4 = (int *)FUN_001a7f7c(puVar2,uVar6);
          }
          if (param_1 == *piVar4) {
            FUN_001a7f3c(puVar2,uVar6);
            iVar5 = ((int (*)())FUN_0010b180)(param_1,param_2);
            *(int *)(iVar5 + 0x160) = *(int *)(iVar5 + 0x160) + -1;
            break;
          }
          uVar6 = uVar6 + 1;
        } while ((int)uVar6 < (int)puVar2[1]);
      }
    }
  }
  ((int (*)())FUN_0010af0c)(param_1,param_2,param_3,param_5);
  if ((param_4 != '\0') && (param_3 != 0)) {
    puVar2 = *(uint **)(param_3 + 0x10);
    uVar6 = puVar2[1];
    if (uVar6 < *puVar2) {
      _memset((void *)(uVar6 * 4 + puVar2[2]),0,4);
      puVar2[1] = uVar6 + 1;
      piVar4 = (int *)(uVar6 * 4 + puVar2[2]);
    }
    else {
      piVar4 = (int *)FUN_001a7f7c(puVar2,uVar6);
    }
    *piVar4 = param_1;
    iVar1 = *(int *)(iVar1 + 0x46c);
    if (iVar1 < *(int *)(param_3 + 0x160)) {
      *(int *)(param_3 + 0x160) = *(int *)(param_3 + 0x160) + 1;
      return;
    }
    *(int *)(param_3 + 0x160) = iVar1 + 1;
  }
  return;
}

/* FUN_0010bbac @ 0x10bbac (114 bytes) */
int FUN_0010bbac(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_2 + 0x8c);
  if (0 < *(int *)(param_1 + 0x84)) {
    iVar3 = 1;
    iVar2 = param_1;
    do {
      if (iVar1 == *(int *)(iVar2 + 0xa4)) {
        ((int (*)())FUN_0010ba02)(param_1,iVar3,param_2,0,param_3);
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x18;
    } while (iVar3 <= *(int *)(param_1 + 0x84));
  }
  return;
}

/* FUN_0010bc1e @ 0x10bc1e (125 bytes) */
int FUN_0010bc1e(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
  int param_5;
  int param_6;
{
  char cVar1;
  
  cVar1 = (**(code **)(**(int **)(param_6 + 0x54) + 0x11c))
                    (*(int **)(param_6 + 0x54),param_1,param_2,param_3,param_4,param_5,param_6);
  if (cVar1 == '\0') {
    return 0;
  }
  ((int (*)())FUN_0010ba02)(param_1,param_2,param_3,0,param_6);
  return 1;
}

/* FUN_0010bc9c @ 0x10bc9c (485 bytes) */
int FUN_0010bc9c(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  uint uVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 uVar4;
  uint *puVar5;
  
  if (param_2 < 5) {
    FUN_0010a40a();
    return;
  }
  if (*(int *)(param_1 + 0x118) == 0) {
    uVar4 = *(undefined4 *)(param_4 + 0xb8);
    puVar2 = (undefined4 *)FUN_001a7bca(uVar4,0x14);
    *puVar2 = uVar4;
    puVar2[4] = uVar4;
    puVar2[2] = 0;
    puVar2[1] = 2;
    uVar4 = FUN_001a7bca(uVar4,8);
    puVar2[3] = uVar4;
    *(undefined4 **)(param_1 + 0x118) = puVar2 + 1;
  }
  puVar5 = *(uint **)(param_1 + 0x118);
  if ((int)puVar5[1] < (int)(param_2 - 4U)) {
    uVar4 = *(undefined4 *)(param_4 + 0xb8);
    puVar2 = (undefined4 *)FUN_001a7bca(uVar4,0x1c);
    *puVar2 = uVar4;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[6] = 0;
    puVar5 = *(uint **)(param_1 + 0x118);
    uVar1 = puVar5[1];
    if (uVar1 < *puVar5) {
      _memset((void *)(uVar1 * 4 + puVar5[2]),0,4);
      puVar5[1] = uVar1 + 1;
      piVar3 = (int *)(uVar1 * 4 + puVar5[2]);
    }
    else {
      piVar3 = (int *)FUN_001a7f7c(puVar5,uVar1);
    }
    *piVar3 = (int)(puVar2 + 1);
    FUN_00109cac(puVar2 + 1,param_2);
    puVar5 = *(uint **)(param_1 + 0x118);
    if (*puVar5 <= param_2 - 5U) goto LAB_0010bd1b;
  }
  else if (*puVar5 <= param_2 - 5U) {
LAB_0010bd1b:
    FUN_001a7f7c(puVar5,param_2 + -5);
    goto LAB_0010bd05;
  }
  uVar1 = puVar5[1];
  if (uVar1 <= param_2 - 5U) {
    _memset((void *)(puVar5[2] + uVar1 * 4),0,((param_2 - 5U) - uVar1) * 4 + 4);
    puVar5[1] = param_2 - 4U;
  }
LAB_0010bd05:
  FUN_0010a40a();
  return;
}

/* FUN_0010be9e @ 0x10be9e (499 bytes) */
int FUN_0010be9e(param_1, param_2)
  int *param_1;
  int param_2;
{
  char cVar1;
  int iVar2;
  int iVar3;
  int local_20;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  if (0 < param_1[0x20]) {
    iVar3 = 0;
    do {
      while (cVar1 = (**(code **)(*param_1 + 0x24))(param_1), cVar1 != '\0') {
        ((int (*)())FUN_0010b0f4)(param_1,iVar3);
        iVar3 = iVar3 + 1;
        if (param_1[0x20] <= iVar3) goto LAB_0010bee5;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_1[0x20]);
  }
LAB_0010bee5:
  iVar3 = *(int *)(param_2 + 0x3f4);
  if (((*(byte *)(iVar3 + 0x30) & 8) == 0) && (*(int *)(param_1[0x22] + 8) != 0x8e)) {
    iVar3 = ((int (*)())FUN_0010b0f4)(param_1,0);
    local_10 = *(undefined4 *)(iVar3 + 0x10);
    iVar3 = 0;
    do {
      if (*(char *)((int)&local_10 + iVar3) == '\0') {
        if (0 < param_1[0x21]) {
          iVar3 = 1;
          do {
            cVar1 = (**(code **)(*param_1 + 0x24))(param_1);
            if ((cVar1 != '\0') || (cVar1 = (**(code **)(*param_1 + 0x28))(param_1), cVar1 != '\0'))
            {
              ((int (*)())FUN_0010b0f4)(param_1,iVar3);
            }
            iVar3 = iVar3 + 1;
          } while (iVar3 <= param_1[0x21]);
        }
        goto LAB_0010c02d;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 != 4);
    iVar3 = *(int *)(param_2 + 0x3f4);
    if (((*(byte *)(iVar3 + 0x32) & 2) != 0) && (0 < param_1[0x21])) {
      local_20 = 1;
      do {
        iVar3 = ((int (*)())FUN_0010b0f4)(param_1,local_20);
        local_14 = *(undefined4 *)(iVar3 + 0x10);
        iVar3 = ((int (*)())FUN_0010b180)(param_1,local_20);
        if (iVar3 != 0) {
          iVar2 = ((int (*)())FUN_0010b0f4)(iVar3,0);
          local_18 = *(undefined4 *)(iVar2 + 0x10);
          iVar2 = 0;
          do {
            if (((*(byte *)((int)&local_14 + iVar2) != 4) &&
                (*(char *)((int)&local_18 + (uint)*(byte *)((int)&local_14 + iVar2)) != '\0')) &&
               ((*(byte *)(iVar3 + 0x15) & 2) != 0)) {
              ((int (*)())FUN_0010b0f4)(iVar3,*(undefined4 *)(iVar3 + 0x84));
            }
            iVar2 = iVar2 + 1;
          } while (iVar2 != 4);
        }
        local_20 = local_20 + 1;
      } while (local_20 <= param_1[0x21]);
LAB_0010c02d:
      iVar3 = *(int *)(param_2 + 0x3f4);
    }
  }
  if ((*(byte *)(iVar3 + 0x31) & 8) == 0) {
    (**(code **)(*param_1 + 0x68))(param_1);
  }
  if (((*(byte *)((int)param_1 + 0x15) & 2) != 0) &&
     ((*(byte *)(*(int *)(param_2 + 0x3f4) + 0x30) & 8) != 0)) {
    ((int (*)())FUN_0010b180)(param_1,param_1[0x21]);
    (**(code **)(*param_1 + 100))(param_1);
    return 1;
  }
  (**(code **)(*param_1 + 100))(param_1);
  return 1;
}

/* FUN_0010c092 @ 0x10c092 (73 bytes) */
int FUN_0010c092(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  
  cVar1 = FUN_0010a320(param_1);
  if (cVar1 != '\0') {
    iVar3 = ((int (*)())FUN_0010b0f4)(param_1,1);
    FUN_000f5672(*(undefined4 *)(iVar3 + 0x10));
  }
  uVar2 = ((int (*)())FUN_0010be9e)(param_1,param_2);
  return uVar2;
}

/* FUN_0010c0dc @ 0x10c0dc (42 bytes) */
int FUN_0010c0dc(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  undefined1 uVar1;
  
  (**(code **)(*param_1 + 0x14))(param_1);
  uVar1 = ((int (*)())FUN_0010be9e)(param_1,param_2);
  return uVar1;
}

/* FUN_0010c106 @ 0x10c106 (106 bytes) */
int FUN_0010c106(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x84);
  if (0 < iVar3) {
    iVar2 = 1;
    do {
      iVar3 = ((int (*)())FUN_0010b0f4)(param_1,iVar2);
      FUN_000f59e0(*(undefined4 *)(iVar3 + 0x10));
      iVar2 = iVar2 + 1;
      iVar3 = *(int *)(param_1 + 0x84);
    } while (iVar2 <= iVar3);
  }
  if (1 < iVar3) {
    iVar2 = 2;
    do {
      iVar2 = iVar2 + 1;
    } while (iVar2 <= iVar3);
  }
  uVar1 = ((int (*)())FUN_0010be9e)(param_1,param_2);
  return uVar1;
}

/* FUN_0010c170 @ 0x10c170 (29 bytes) */
int FUN_0010c170(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  undefined1 uVar1;
  
  uVar1 = ((int (*)())FUN_0010be9e)(param_1,param_2);
  return uVar1;
}

/* FUN_0010c18e @ 0x10c18e (506 bytes) */
int FUN_0010c18e(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  
  iVar1 = *(int *)(param_4 + 0x3f4);
  if (param_3 != '\0') {
    uVar6 = *(uint *)(param_1 + 0x14);
    if ((uVar6 & 0x200) == 0) goto joined_r0x0010c278;
    iVar5 = ((int (*)())FUN_0010b180)(param_1,*(undefined4 *)(param_1 + 0x84));
    if (iVar5 == 0) {
LAB_0010c375:
      uVar6 = *(uint *)(param_1 + 0x14);
      goto joined_r0x0010c278;
    }
    puVar2 = *(uint **)(iVar5 + 0x10);
    if (0 < (int)puVar2[1]) {
      uVar6 = 0;
      do {
        if (uVar6 < *puVar2) {
          uVar3 = puVar2[1];
          if (uVar3 <= uVar6) {
            _memset((void *)(puVar2[2] + uVar3 * 4),0,(uVar6 - uVar3) * 4 + 4);
            puVar2[1] = uVar6 + 1;
          }
          piVar4 = (int *)(puVar2[2] + uVar6 * 4);
        }
        else {
          piVar4 = (int *)FUN_001a7f7c(puVar2,uVar6);
        }
        if (param_1 == *piVar4) {
          FUN_001a7f3c(puVar2,uVar6);
          *(int *)(iVar5 + 0x160) = *(int *)(iVar5 + 0x160) + -1;
          goto LAB_0010c375;
        }
        uVar6 = uVar6 + 1;
      } while ((int)uVar6 < (int)puVar2[1]);
      uVar6 = *(uint *)(param_1 + 0x14);
      goto joined_r0x0010c278;
    }
  }
  uVar6 = *(uint *)(param_1 + 0x14);
joined_r0x0010c278:
  if ((uVar6 & 0x200) == 0) {
    iVar5 = *(int *)(param_1 + 0x84) + 1;
    *(int *)(param_1 + 0x84) = iVar5;
    *(uint *)(param_1 + 0x14) = uVar6 | 0x200;
    iVar5 = ((int (*)())FUN_0010b0f4)(param_1,iVar5);
    *(undefined4 *)(iVar5 + 0x10) = DAT_001cbe70;
  }
  ((int (*)())FUN_0010af0c)(param_1,*(undefined4 *)(param_1 + 0x84),param_2,param_4);
  if ((param_3 != '\0') && (param_2 != 0)) {
    puVar2 = *(uint **)(param_2 + 0x10);
    uVar6 = puVar2[1];
    if (uVar6 < *puVar2) {
      _memset((void *)(uVar6 * 4 + puVar2[2]),0,4);
      puVar2[1] = uVar6 + 1;
      piVar4 = (int *)(uVar6 * 4 + puVar2[2]);
    }
    else {
      piVar4 = (int *)FUN_001a7f7c(puVar2,uVar6);
    }
    *piVar4 = param_1;
    iVar1 = *(int *)(iVar1 + 0x46c);
    if (iVar1 < *(int *)(param_2 + 0x160)) {
      *(int *)(param_2 + 0x160) = *(int *)(param_2 + 0x160) + 1;
      return;
    }
    *(int *)(param_2 + 0x160) = iVar1 + 1;
  }
  return;
}

/* FUN_0010c388 @ 0x10c388 (479 bytes) */
int FUN_0010c388(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(param_1 + 0x84);
  iVar3 = iVar2 + 1;
  *(int *)(param_1 + 0x84) = iVar3;
  if ((*(byte *)(param_1 + 0x15) & 2) == 0) {
    ((int (*)())FUN_0010ba02)(param_1,iVar3,param_2,0,param_3);
    if (iVar3 == 0) {
      *(undefined4 *)(param_1 + 0x9c) = DAT_001cbe68;
      return 0;
    }
    iVar2 = ((int (*)())FUN_0010b0f4)(param_1,iVar3);
    *(undefined4 *)(iVar2 + 0x10) = DAT_001cbe68;
  }
  else {
    if ((*(byte *)(*(int *)(param_3 + 0x3f4) + 0x30) & 8) == 0) {
      uVar1 = ((int (*)())FUN_0010b180)(param_1,iVar2);
      ((int (*)())FUN_0010ba02)(param_1,*(undefined4 *)(param_1 + 0x84),uVar1,0,param_3);
      iVar3 = ((int (*)())FUN_0010b0f4)(param_1,iVar2);
      uVar1 = *(undefined4 *)(iVar3 + 0x10);
      if (*(int *)(param_1 + 0x84) == 0) {
        *(undefined4 *)(param_1 + 0x9c) = uVar1;
      }
      else {
        iVar3 = ((int (*)())FUN_0010b0f4)(param_1,*(int *)(param_1 + 0x84));
        *(undefined4 *)(iVar3 + 0x10) = uVar1;
      }
    }
    else {
      uVar1 = ((int (*)())FUN_0010b180)(param_1,iVar2);
      ((int (*)())FUN_0010c18e)(param_1,uVar1,0,param_3);
      iVar3 = ((int (*)())FUN_0010b0f4)(param_1,iVar2);
      uVar1 = *(undefined4 *)(iVar3 + 0x10);
      if (*(int *)(param_1 + 0x84) == 0) {
        *(undefined4 *)(param_1 + 0x9c) = uVar1;
      }
      else {
        iVar3 = ((int (*)())FUN_0010b0f4)(param_1,*(int *)(param_1 + 0x84));
        *(undefined4 *)(iVar3 + 0x10) = uVar1;
      }
    }
    ((int (*)())FUN_0010ba02)(param_1,iVar2,param_2,0,param_3);
    if (iVar2 != 0) {
      iVar3 = ((int (*)())FUN_0010b0f4)(param_1,iVar2);
      *(undefined4 *)(iVar3 + 0x10) = DAT_001cbe68;
      return iVar2;
    }
    *(undefined4 *)(param_1 + 0x9c) = DAT_001cbe68;
    iVar3 = 0;
  }
  return iVar3;
}

/* FUN_0010c568 @ 0x10c568 (92 bytes) */
int FUN_0010c568(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
{
  undefined4 uVar1;
  int iVar2;
  
  ((int (*)())FUN_0010c18e)(param_1,*(undefined4 *)(param_2 + 4),param_3,param_4);
  uVar1 = *(undefined4 *)(param_2 + 0x10);
  if (*(int *)(param_1 + 0x84) == 0) {
    *(undefined4 *)(param_1 + 0x9c) = uVar1;
    return;
  }
  iVar2 = ((int (*)())FUN_0010b0f4)(param_1,*(int *)(param_1 + 0x84));
  *(undefined4 *)(iVar2 + 0x10) = uVar1;
  return;
}

/* FUN_0010c5c4 @ 0x10c5c4 (255 bytes) */
int FUN_0010c5c4(param_1, param_2)
  int *param_1;
  int param_2;
{
  undefined4 uVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  int local_10;
  
  if (0 < param_1[0x21]) {
    iVar3 = 1;
    do {
      iVar3 = iVar3 + 1;
    } while (iVar3 <= param_1[0x21]);
  }
  local_10 = 0;
  do {
    ((int (*)())FUN_0010b0f4)(param_1,0);
    if (0 < param_1[0x21]) {
      iVar3 = 1;
      do {
        ((int (*)())FUN_0010b0f4)(param_1,iVar3);
        if ((*(byte *)(*(int *)(param_2 + 0x3f4) + 0x30) & 8) != 0) {
          if (iVar3 != 1) {
            iVar4 = ((int (*)())FUN_0010b0f4)(param_1,iVar3);
            uVar1 = *(undefined4 *)(iVar4 + 0x10);
            uVar5 = ((int (*)())FUN_0010b180)(param_1,iVar3);
            FUN_0010a2a8(uVar5,param_2,uVar1);
          }
          piVar6 = (int *)((int (*)())FUN_0010b180)(param_1,iVar3);
          (**(code **)(*piVar6 + 0x60))(piVar6);
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 <= param_1[0x21]);
    }
    local_10 = local_10 + 1;
  } while (local_10 != 4);
  (**(code **)(*param_1 + 0x14))(param_1);
  uVar2 = ((int (*)())FUN_0010be9e)(param_1,param_2);
  return uVar2;
}

/* FUN_0010c6c4 @ 0x10c6c4 (42 bytes) */
int FUN_0010c6c4(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  undefined1 uVar1;
  
  (**(code **)(*param_1 + 0x14))(param_1);
  uVar1 = ((int (*)())FUN_0010be9e)(param_1,param_2);
  return uVar1;
}

/* FUN_0010c6ee @ 0x10c6ee (631 bytes) */
int FUN_0010c6ee(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  char cVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  if ((*(byte *)((int)param_1 + 0x15) & 2) != 0) {
    piVar2 = (int *)((int (*)())FUN_0010b180)(param_1,param_1[0x21]);
    cVar1 = (**(code **)(*piVar2 + 0x50))(piVar2);
    if (cVar1 == '\0') {
      if (piVar2[0x20] == 0) {
        return 0;
      }
      cVar1 = FUN_0012dfd8(piVar2[0x26]);
      if (cVar1 == '\0') {
        return 0;
      }
      if ((*(byte *)(piVar2 + 5) & 2) != 0) {
        return 0;
      }
      cVar1 = (**(code **)(*piVar2 + 0x50))(piVar2);
      if (cVar1 != '\0') {
        return 0;
      }
      iVar5 = FUN_0013c4e0(param_2,piVar2);
      iVar3 = FUN_0013c4e0(param_2,param_1);
      if (iVar5 != iVar3) {
        return 0;
      }
    }
  }
  cVar1 = (**(code **)(*param_1 + 100))(param_1);
  if (cVar1 != '\0') {
    for (iVar5 = 1; iVar3 = (**(code **)(*param_1 + 0x14))(param_1), iVar5 <= iVar3;
        iVar5 = iVar5 + 1) {
      if ((param_1[iVar5 * 6 + 0x28] & 1U) != 0) {
        return 0;
      }
      if ((param_1[iVar5 * 6 + 0x28] & 2U) != 0) {
        return 0;
      }
      cVar1 = FUN_000f5a1e(param_1,iVar5);
      if (cVar1 == '\0') {
        return 0;
      }
    }
    if (((char)param_1[0x48] == '\0') && (param_1[0x49] == 0)) {
      if ((param_1[0x20] != 0) &&
         (((cVar1 = FUN_0012dfd8(param_1[0x26]), cVar1 != '\0' &&
           ((*(byte *)(param_1 + 5) & 2) == 0)) &&
          (cVar1 = (**(code **)(*param_1 + 0x50))(param_1), cVar1 == '\0')))) {
        iVar5 = 0;
        piVar2 = param_1;
        do {
          if ((byte)((char)piVar2[0x27] - 2U) < 2) {
            return 0;
          }
          iVar5 = iVar5 + 1;
          piVar2 = (int *)((int)piVar2 + 1);
        } while (iVar5 != 4);
      }
      ((int (*)())FUN_0010b0f4)(param_1,0);
      iVar5 = ((int (*)())FUN_0010b7c8)(param_1,0);
      if ((((iVar5 == 0) && ((*(byte *)(param_1 + 5) & 2) == 0)) &&
          ((param_1[0x20] != 0 &&
           ((cVar1 = FUN_0012dfd8(param_1[0x26]), cVar1 != '\0' &&
            ((*(byte *)(param_1 + 5) & 2) == 0)))))) &&
         (cVar1 = (**(code **)(*param_1 + 0x50))(param_1), cVar1 == '\0')) {
        piVar2 = (int *)((int (*)())FUN_0010b180)(param_1,1);
        cVar1 = (**(code **)(*piVar2 + 0x50))(piVar2);
        if (cVar1 != '\0') {
          return 1;
        }
        piVar2 = (int *)((int (*)())FUN_0010b180)(param_1,1);
        if ((((piVar2[0x20] != 0) && (cVar1 = FUN_0012dfd8(piVar2[0x26]), cVar1 != '\0')) &&
            ((*(byte *)(piVar2 + 5) & 2) == 0)) &&
           (cVar1 = (**(code **)(*piVar2 + 0x50))(piVar2), cVar1 == '\0')) {
          uVar4 = ((int (*)())FUN_0010b180)(param_1,1);
          iVar5 = FUN_0013c4e0(param_2,uVar4);
          iVar3 = FUN_0013c4e0(param_2,param_1);
          if (iVar5 == iVar3) {
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

/* FUN_0010c966 @ 0x10c966 (76 bytes) */
int FUN_0010c966(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())FUN_0010ad9e)(param_1,param_2,param_3);
  *param_1 = PTR_DAT_0021355d + 8;
  param_1[0x21] = 1;
  param_1[0x20] = 1;
  return;
}

/* FUN_0010c9b2 @ 0x10c9b2 (76 bytes) */
int FUN_0010c9b2(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())FUN_0010ad9e)(param_1,param_2,param_3);
  *param_1 = PTR_DAT_0021355d + 8;
  param_1[0x21] = 1;
  param_1[0x20] = 1;
  return;
}

/* FUN_0010c9fe @ 0x10c9fe (73 bytes) */
int FUN_0010c9fe(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())FUN_0010ad9e)(param_1,param_2,param_3);
  *param_1 = PTR_DAT_00213449 + 8;
  param_1[0x20] = 0;
  param_1[5] = param_1[5] | 0x18000;
  return;
}

/* FUN_0010ca48 @ 0x10ca48 (73 bytes) */
int FUN_0010ca48(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())FUN_0010ad9e)(param_1,param_2,param_3);
  *param_1 = PTR_DAT_00213449 + 8;
  param_1[0x20] = 0;
  param_1[5] = param_1[5] | 0x18000;
  return;
}

/* FUN_0010ca92 @ 0x10ca92 (73 bytes) */
int FUN_0010ca92(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())FUN_0010ad9e)(param_1,param_2,param_3);
  *param_1 = PTR_DAT_00213551 + 8;
  param_1[0x20] = 1;
  *(undefined1 *)(param_1 + 0x4b) = 0;
  return;
}

/* FUN_0010cadc @ 0x10cadc (73 bytes) */
int FUN_0010cadc(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())FUN_0010ad9e)(param_1,param_2,param_3);
  *param_1 = PTR_DAT_00213551 + 8;
  param_1[0x20] = 1;
  *(undefined1 *)(param_1 + 0x4b) = 0;
  return;
}

/* FUN_0010cb26 @ 0x10cb26 (76 bytes) */
int FUN_0010cb26(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())FUN_0010c9b2)(param_1,param_2,param_3);
  *param_1 = PTR_DAT_00213509 + 8;
  param_1[0x21] = 2;
  param_1[0x4b] = 0;
  return;
}

/* FUN_0010cb72 @ 0x10cb72 (146 bytes) */
int FUN_0010cb72(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  ((int (*)())FUN_0010c9b2)(param_1,param_2,param_3);
  *param_1 = PTR_DAT_00213501 + 8;
  param_1[0x4b] = param_5;
  param_1[0x4c] = param_4;
  *(undefined1 *)(param_1 + 0x4d) = 0;
  param_1[0x4e] = 0;
  param_1[0x4f] = 0;
  param_1[0x50] = DAT_001cbe68;
  FUN_0010a0d2();
  return;
}

/* FUN_0010cc04 @ 0x10cc04 (146 bytes) */
int FUN_0010cc04(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  ((int (*)())FUN_0010c9b2)(param_1,param_2,param_3);
  *param_1 = PTR_DAT_00213501 + 8;
  param_1[0x4b] = param_5;
  param_1[0x4c] = param_4;
  *(undefined1 *)(param_1 + 0x4d) = 0;
  param_1[0x4e] = 0;
  param_1[0x4f] = 0;
  param_1[0x50] = DAT_001cbe68;
  FUN_0010a0d2();
  return;
}

/* FUN_0010cc96 @ 0x10cc96 (83 bytes) */
int FUN_0010cc96(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(param_2 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x168);
  *puVar2 = uVar1;
  ((int (*)())FUN_0010cc04)(puVar2 + 1,param_1,param_2,param_3,param_4);
  return puVar2 + 1;
}

/* FUN_0010cd08 @ 0x10cd08 (56 bytes) */
int FUN_0010cd08(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())FUN_0010c9b2)(param_1,param_2,param_3);
  *param_1 = PTR_DAT_00213501 + 8;
  return;
}

/* FUN_0010cd40 @ 0x10cd40 (56 bytes) */
int FUN_0010cd40(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())FUN_0010c9b2)(param_1,param_2,param_3);
  *param_1 = PTR_DAT_00213501 + 8;
  return;
}

/* FUN_0010cd78 @ 0x10cd78 (69 bytes) */
int FUN_0010cd78(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(param_2 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x168);
  *puVar2 = uVar1;
  ((int (*)())FUN_0010cd40)(puVar2 + 1,param_1,param_2);
  return puVar2 + 1;
}

/* FUN_0010cddc @ 0x10cddc (281 bytes) */
int FUN_0010cddc(param_1, param_2, param_3)
  undefined4 *param_1;
  int param_2;
  int param_3;
{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  ((int (*)())FUN_0010c9b2)(param_1,param_2,param_3);
  *param_1 = PTR_DAT_00213505 + 8;
  param_1[0x4c] = 0;
  param_1[0x4d] = 0xffffffff;
  param_1[0x26] = 0;
  param_1[0x2c] = 0;
  param_1[0x42] = 0;
  param_1[0x41] = 0;
  puVar1 = (undefined4 *)FUN_001a7bca(*(undefined4 *)(param_3 + 0xb8),0x24);
  puVar3 = puVar1;
  for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  *(undefined2 *)puVar1 = 3;
  *(undefined2 *)((int)puVar1 + 2) = 3;
  *(undefined2 *)(puVar1 + 1) = 3;
  *(undefined2 *)((int)puVar1 + 6) = 7;
  *(undefined2 *)(puVar1 + 2) = 7;
  *(undefined2 *)((int)puVar1 + 10) = 3;
  *(undefined2 *)(puVar1 + 3) = 3;
  *(undefined2 *)((int)puVar1 + 0xe) = 1;
  *(undefined2 *)(puVar1 + 4) = 0;
  *(undefined2 *)((int)puVar1 + 0x12) = 1;
  *(undefined2 *)((int)puVar1 + 0x16) = 0;
  *(undefined2 *)(puVar1 + 6) = 0;
  *(undefined2 *)((int)puVar1 + 0x1a) = 0;
  *(undefined2 *)(puVar1 + 7) = 0;
  *(undefined2 *)(puVar1 + 5) = 0;
  param_1[0x4f] = puVar1;
  param_1[0x4e] = 0xffffffff;
  param_1[0x50] = DAT_001cbe68;
  if (param_2 == 0x77) {
    param_1[5] = param_1[5] | 8;
  }
  return;
}

/* FUN_0010cf10 @ 0x10cf10 (66 bytes) */
int FUN_0010cf10(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())FUN_0010cddc)(param_1,param_2,param_3);
  *param_1 = PTR_DAT_00213541 + 8;
  param_1[0x21] = 3;
  return;
}

/* FUN_0010cf52 @ 0x10cf52 (281 bytes) */
int FUN_0010cf52(param_1, param_2, param_3)
  undefined4 *param_1;
  int param_2;
  int param_3;
{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  ((int (*)())FUN_0010c9b2)(param_1,param_2,param_3);
  *param_1 = PTR_DAT_00213505 + 8;
  param_1[0x4c] = 0;
  param_1[0x4d] = 0xffffffff;
  param_1[0x26] = 0;
  param_1[0x2c] = 0;
  param_1[0x42] = 0;
  param_1[0x41] = 0;
  puVar1 = (undefined4 *)FUN_001a7bca(*(undefined4 *)(param_3 + 0xb8),0x24);
  puVar3 = puVar1;
  for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  *(undefined2 *)puVar1 = 3;
  *(undefined2 *)((int)puVar1 + 2) = 3;
  *(undefined2 *)(puVar1 + 1) = 3;
  *(undefined2 *)((int)puVar1 + 6) = 7;
  *(undefined2 *)(puVar1 + 2) = 7;
  *(undefined2 *)((int)puVar1 + 10) = 3;
  *(undefined2 *)(puVar1 + 3) = 3;
  *(undefined2 *)((int)puVar1 + 0xe) = 1;
  *(undefined2 *)(puVar1 + 4) = 0;
  *(undefined2 *)((int)puVar1 + 0x12) = 1;
  *(undefined2 *)((int)puVar1 + 0x16) = 0;
  *(undefined2 *)(puVar1 + 6) = 0;
  *(undefined2 *)((int)puVar1 + 0x1a) = 0;
  *(undefined2 *)(puVar1 + 7) = 0;
  *(undefined2 *)(puVar1 + 5) = 0;
  param_1[0x4f] = puVar1;
  param_1[0x4e] = 0xffffffff;
  param_1[0x50] = DAT_001cbe68;
  if (param_2 == 0x77) {
    param_1[5] = param_1[5] | 8;
  }
  return;
}

/* FUN_0010d086 @ 0x10d086 (69 bytes) */
int FUN_0010d086(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(param_2 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x168);
  *puVar2 = uVar1;
  ((int (*)())FUN_0010cf52)(puVar2 + 1,param_1,param_2);
  return puVar2 + 1;
}

/* FUN_0010d0ea @ 0x10d0ea (69 bytes) */
int FUN_0010d0ea(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(param_2 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x168);
  *puVar2 = uVar1;
  ((int (*)())FUN_0010cf52)(puVar2 + 1,param_1,param_2);
  return puVar2 + 1;
}

/* FUN_0010d14e @ 0x10d14e (66 bytes) */
int FUN_0010d14e(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())FUN_0010cddc)(param_1,param_2,param_3);
  *param_1 = PTR_DAT_00213541 + 8;
  param_1[0x21] = 3;
  return;
}

/* FUN_0010d190 @ 0x10d190 (69 bytes) */
int FUN_0010d190(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(param_2 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x168);
  *puVar2 = uVar1;
  ((int (*)())FUN_0010d14e)(puVar2 + 1,param_1,param_2);
  return puVar2 + 1;
}

/* FUN_0010d1f4 @ 0x10d1f4 (76 bytes) */
int FUN_0010d1f4(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())FUN_0010c9b2)(param_1,param_2,param_3);
  *param_1 = PTR_DAT_00213549 + 8;
  param_1[0x21] = 2;
  param_1[0x4b] = 0;
  return;
}

/* FUN_0010d240 @ 0x10d240 (76 bytes) */
int FUN_0010d240(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())FUN_0010c9b2)(param_1,param_2,param_3);
  *param_1 = PTR_DAT_00213549 + 8;
  param_1[0x21] = 2;
  param_1[0x4b] = 0;
  return;
}

/* FUN_0010d28c @ 0x10d28c (76 bytes) */
int FUN_0010d28c(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())FUN_0010c9b2)(param_1,param_2,param_3);
  *param_1 = PTR_DAT_00213509 + 8;
  param_1[0x21] = 2;
  param_1[0x4b] = 0;
  return;
}

/* FUN_0010d2d8 @ 0x10d2d8 (66 bytes) */
int FUN_0010d2d8(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())FUN_0010cadc)(param_1,param_2,param_3);
  *param_1 = PTR_DAT_00213525 + 8;
  param_1[0x21] = 0;
  return;
}

/* FUN_0010d31a @ 0x10d31a (88 bytes) */
int FUN_0010d31a(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())FUN_0010d2d8)(param_1,param_2,param_3);
  *param_1 = PTR_DAT_002134e1 + 8;
  param_1[0x20] = 0;
  param_1[0x27] = DAT_001cbe74;
  param_1[0x21] = 0;
  return;
}

