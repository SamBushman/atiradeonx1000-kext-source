#include "decls.h"

/* _BitSetXorEquals @ 0x97c08238 (128 bytes) */
int _BitSetXorEquals(param_1, param_2)
  undefined4 *param_1;
  undefined4 *param_2;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  _BitSetExpandEquals(param_1,*param_2);
  _BitSetExpandEquals(param_2,*param_1);
  iVar2 = 0;
  for (uVar3 = (uint)param_1[1] >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    iVar1 = iVar2 * 4;
    iVar2 = iVar2 + 1;
    *(uint *)(iVar1 + param_1[2]) = *(uint *)(iVar1 + param_1[2]) ^ *(uint *)(iVar1 + param_2[2]);
  }
  return param_1;
}

/* _BitSetCopyEquals @ 0x97c082b8 (120 bytes) */
int _BitSetCopyEquals(param_1, param_2)
  undefined4 *param_1;
  undefined4 *param_2;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  _BitSetExpandEquals(param_1,*param_2);
  _BitSetExpandEquals(param_2,*param_1);
  iVar2 = 0;
  for (uVar3 = (uint)param_1[1] >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    iVar1 = iVar2 * 4;
    iVar2 = iVar2 + 1;
    *(undefined4 *)(iVar1 + param_1[2]) = *(undefined4 *)(iVar1 + param_2[2]);
  }
  return param_1;
}

/* _BitSetEqualsTest @ 0x97c08330 (144 bytes) */
int _BitSetEqualsTest(param_1, param_2)
  int *param_1;
  undefined4 *param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  uVar4 = 1;
  _BitSetExpandEquals(param_1,*param_2);
  iVar5 = 0;
  _BitSetExpandEquals(param_2,*param_1);
  iVar3 = *param_1;
  if (0 < iVar3) {
    do {
      iVar1 = _BitSetGetEquals(param_1,iVar5);
      iVar2 = _BitSetGetEquals(param_2,iVar5);
      if (iVar1 != iVar2) {
        uVar4 = 0;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar3);
  }
  return uVar4;
}

/* _BitSetAndTest @ 0x97c083c0 (136 bytes) */
int _BitSetAndTest(param_1, param_2)
  int *param_1;
  undefined4 *param_2;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  uVar4 = 0;
  _BitSetExpandEquals(param_1,*param_2);
  _BitSetExpandEquals(param_2,*param_1);
  iVar3 = *param_1;
  iVar5 = 0;
  if (0 < iVar3) {
    do {
      uVar1 = _BitSetGetEquals(param_1,iVar5);
      iVar6 = iVar5 + 1;
      uVar2 = _BitSetGetEquals(param_2,iVar5);
      uVar4 = uVar4 | uVar1 & uVar2;
      iVar5 = iVar6;
    } while (iVar6 < iVar3);
  }
  return uVar4;
}

/* _BitSetAndNotTest @ 0x97c08448 (136 bytes) */
int _BitSetAndNotTest(param_1, param_2)
  int *param_1;
  undefined4 *param_2;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  uVar4 = 0;
  _BitSetExpandEquals(param_1,*param_2);
  _BitSetExpandEquals(param_2,*param_1);
  iVar3 = *param_1;
  iVar5 = 0;
  if (0 < iVar3) {
    do {
      uVar1 = _BitSetGetEquals(param_1,iVar5);
      iVar6 = iVar5 + 1;
      uVar2 = _BitSetGetEquals(param_2,iVar5);
      uVar4 = uVar4 | uVar1 & ~uVar2;
      iVar5 = iVar6;
    } while (iVar6 < iVar3);
  }
  return uVar4;
}

/* _BitSetOrTest @ 0x97c084d0 (136 bytes) */
int _BitSetOrTest(param_1, param_2)
  int *param_1;
  undefined4 *param_2;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  uVar4 = 0;
  _BitSetExpandEquals(param_1,*param_2);
  _BitSetExpandEquals(param_2,*param_1);
  iVar3 = *param_1;
  iVar5 = 0;
  if (0 < iVar3) {
    do {
      uVar1 = _BitSetGetEquals(param_1,iVar5);
      iVar6 = iVar5 + 1;
      uVar2 = _BitSetGetEquals(param_2,iVar5);
      uVar4 = uVar4 | uVar1 | uVar2;
      iVar5 = iVar6;
    } while (iVar6 < iVar3);
  }
  return uVar4;
}

/* _BitSetXorTest @ 0x97c08558 (136 bytes) */
int _BitSetXorTest(param_1, param_2)
  int *param_1;
  undefined4 *param_2;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  uVar4 = 0;
  _BitSetExpandEquals(param_1,*param_2);
  _BitSetExpandEquals(param_2,*param_1);
  iVar3 = *param_1;
  iVar5 = 0;
  if (0 < iVar3) {
    do {
      uVar1 = _BitSetGetEquals(param_1,iVar5);
      iVar6 = iVar5 + 1;
      uVar2 = _BitSetGetEquals(param_2,iVar5);
      uVar4 = uVar4 | uVar1 ^ uVar2;
      iVar5 = iVar6;
    } while (iVar6 < iVar3);
  }
  return uVar4;
}

/* _defaultHashFunction @ 0x97c085e0 (4 bytes) */
int _defaultHashFunction()
{
  return;
}

/* _defaultEqualsFunction @ 0x97c085e4 (8 bytes) */
int _defaultEqualsFunction(param_1, param_2)
  int param_1;
  int param_2;
{
  return param_1 - param_2;
}

/* _HashSetNew @ 0x97c085ec (192 bytes) */
int _HashSetNew(param_1, param_2, param_3)
  uint param_1;
  uint param_2;
  uint param_3;
{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  
  puVar2 = (uint *)_malloc(0x10);
  if (param_2 == 0) {
    param_2 = DAT_a7b7bf70;
  }
  puVar2[2] = param_2;
  if (param_3 == 0) {
    param_3 = DAT_a7b7bf6c;
  }
  puVar2[3] = param_3;
  *puVar2 = param_1;
  uVar3 = _malloc(param_1 << 3);
  uVar5 = 0;
  puVar2[1] = uVar3;
  if (*puVar2 != 0) {
    do {
      uVar3 = puVar2[1];
      iVar1 = uVar5 * 8;
      uVar5 = uVar5 + 1;
      *(undefined4 *)(uVar3 + iVar1) = 0;
      uVar4 = _malloc(4);
      *(undefined4 *)(uVar3 + iVar1 + 4) = uVar4;
    } while (uVar5 < *puVar2);
  }
  return puVar2;
}

/* _HashSetFree @ 0x97c086ac (132 bytes) */
int _HashSetFree(param_1)
  uint *param_1;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = 0;
  uVar3 = *param_1;
  if (uVar3 == 0) {
    uVar1 = param_1[1];
  }
  else {
    uVar1 = param_1[1];
    do {
      iVar2 = *(int *)(uVar1 + uVar4 * 8 + 4);
      if (iVar2 != 0) {
        _free(iVar2);
        uVar3 = *param_1;
        uVar1 = param_1[1];
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar3);
  }
  if (uVar1 != 0) {
    _free(uVar1);
  }
  _free(param_1);
  return;
}

/* _HashSetAdd @ 0x97c08730 (272 bytes) */
int _HashSetAdd(param_1, param_2)
  uint *param_1;
  undefined4 param_2;
{
  uint uVar1;
  int iVar2;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  uint a6;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  
  uVar4 = 0;
  uVar3 = 0xffffffff;
  uVar1 = (*(code *)param_1[2])(param_2,param_2);
  a6 = param_1[1];
  iVar2 = (uVar1 - (uVar1 / *param_1) * *param_1) * 8;
  puVar5 = (uint *)(a6 + iVar2);
  if (*(int *)(a6 + iVar2) == 0) {
    uVar1 = puVar5[1];
  }
  else {
    uVar1 = puVar5[1];
    do {
      iVar2 = *(int *)(uVar1 + uVar4 * 4);
      if (iVar2 == 0) {
        if (uVar3 == 0xffffffff) {
          uVar3 = uVar4;
        }
      }
      else {
        iVar2 = (*(code *)param_1[3])(iVar2,param_2,in_r5,in_r6,in_r7,in_r8,a6);
        if (iVar2 == 0) {
          *(undefined4 *)(uVar1 + uVar4 * 4) = param_2;
          return param_1;
        }
        uVar1 = puVar5[1];
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < *puVar5);
  }
  if (uVar3 == 0xffffffff) {
    uVar3 = *puVar5;
    *puVar5 = uVar3 + 1;
    uVar3 = _realloc(uVar1,(uVar3 + 1) * 4);
    puVar5[1] = uVar3;
    *(undefined4 *)(uVar3 + *puVar5 * 4 + -4) = param_2;
  }
  else {
    *(undefined4 *)(uVar1 + uVar3 * 4) = param_2;
  }
  return param_1;
}

/* _HashSetGet @ 0x97c08840 (176 bytes) */
int _HashSetGet(param_1, param_2)
  uint *param_1;
  undefined4 param_2;
{
  uint uVar1;
  int iVar2;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  uint a6;
  uint *puVar3;
  uint uVar4;
  
  uVar4 = 0;
  uVar1 = (*(code *)param_1[2])(param_2,param_2);
  a6 = param_1[1];
  iVar2 = (uVar1 - (uVar1 / *param_1) * *param_1) * 8;
  puVar3 = (uint *)(a6 + iVar2);
  if (*(int *)(a6 + iVar2) != 0) {
    do {
      uVar1 = puVar3[1];
      iVar2 = *(int *)(uVar1 + uVar4 * 4);
      if ((iVar2 != 0) &&
         (iVar2 = (*(code *)param_1[3])(iVar2,param_2,in_r5,in_r6,in_r7,in_r8,a6), iVar2 == 0)) {
        return *(undefined4 *)(uVar1 + uVar4 * 4);
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < *puVar3);
  }
  return 0;
}

/* _HashSetRemove @ 0x97c088f0 (184 bytes) */
int _HashSetRemove(param_1, param_2)
  uint *param_1;
  undefined4 param_2;
{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  uint a6;
  uint *puVar5;
  uint uVar6;
  
  uVar6 = 0;
  uVar3 = (*(code *)param_1[2])(param_2,param_2);
  a6 = param_1[1];
  iVar1 = (uVar3 - (uVar3 / *param_1) * *param_1) * 8;
  puVar5 = (uint *)(a6 + iVar1);
  if (*(int *)(a6 + iVar1) != 0) {
    do {
      uVar3 = puVar5[1];
      iVar1 = uVar6 * 4;
      if ((*(int *)(uVar3 + iVar1) != 0) &&
         (iVar4 = (*(code *)param_1[3])(*(int *)(uVar3 + iVar1),param_2,in_r5,in_r6,in_r7,in_r8,a6),
         iVar4 == 0)) {
        uVar2 = *(undefined4 *)(uVar3 + iVar1);
        *(undefined4 *)(uVar3 + iVar1) = 0;
        return uVar2;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < *puVar5);
  }
  return 0;
}

/* _HashSetIteratorSetup @ 0x97c089a8 (24 bytes) */
int _HashSetIteratorSetup(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  *param_2 = param_1;
  param_2[2] = 0;
  param_2[1] = 0;
  return param_2;
}

/* _HashSetIteratorNext @ 0x97c089c0 (160 bytes) */
int _HashSetIteratorNext(param_1)
  undefined4 *param_1;
{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  
  puVar3 = (uint *)*param_1;
  uVar1 = param_1[1];
  if (uVar1 < *puVar3) {
    do {
      uVar5 = param_1[2];
      puVar4 = (uint *)(puVar3[1] + uVar1 * 8);
      if (uVar5 < *(uint *)(puVar3[1] + uVar1 * 8)) {
        iVar2 = uVar5 << 2;
        do {
          uVar5 = uVar5 + 1;
          uVar1 = puVar4[1];
          if (*(int *)(uVar1 + iVar2) != 0) {
            param_1[2] = uVar5;
            return *(undefined4 *)(uVar1 + iVar2);
          }
          param_1[2] = uVar5;
          iVar2 = iVar2 + 4;
        } while (uVar5 < *puVar4);
      }
      param_1[2] = 0;
      uVar1 = param_1[1] + 1;
      param_1[1] = uVar1;
    } while (uVar1 < *puVar3);
  }
  return 0;
}

/* _HashTableNew @ 0x97c08a60 (84 bytes) */
int _HashTableNew(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)_malloc(4);
  uVar2 = ((int (*)())_HashSetNew)(param_1,param_2,param_3);
  *puVar1 = uVar2;
  return puVar1;
}

/* _HashTableFree @ 0x97c08ab4 (160 bytes) */
int _HashTableFree(param_1)
  int *param_1;
{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  
  uVar4 = 0;
  puVar1 = (uint *)*param_1;
  uVar3 = *puVar1;
  if (uVar3 != 0) {
    do {
      uVar6 = 0;
      puVar5 = (uint *)(puVar1[1] + uVar4 * 8);
      if (*(int *)(puVar1[1] + uVar4 * 8) != 0) {
        do {
          iVar2 = *(int *)(puVar5[1] + uVar6 * 4);
          if (iVar2 != 0) {
            _free(iVar2);
          }
          uVar6 = uVar6 + 1;
        } while (uVar6 < *puVar5);
        uVar3 = *puVar1;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar3);
    puVar1 = (uint *)*param_1;
  }
  ((int (*)())_HashSetFree)(puVar1);
  _free(param_1);
  return;
}

/* _HashTableAdd @ 0x97c08b54 (336 bytes) */
int _HashTableAdd(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 a2;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  uint a6;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  uint *puVar8;
  
  puVar6 = (uint *)*param_1;
  uVar7 = 0;
  uVar5 = 0xffffffff;
  a2 = param_3;
  uVar2 = (*(code *)puVar6[2])(param_2,param_2,param_3);
  a6 = puVar6[1];
  iVar1 = (uVar2 - (uVar2 / *puVar6) * *puVar6) * 8;
  puVar8 = (uint *)(a6 + iVar1);
  if (*(int *)(a6 + iVar1) == 0) {
    uVar2 = puVar8[1];
  }
  else {
    uVar2 = puVar8[1];
    do {
      iVar1 = uVar7 * 4;
      if (*(undefined4 **)(uVar2 + iVar1) == (undefined4 *)0x0) {
        if (uVar5 == 0xffffffff) {
          uVar5 = uVar7;
        }
      }
      else {
        iVar3 = (*(code *)puVar6[3])
                          (**(undefined4 **)(uVar2 + iVar1),param_2,a2,in_r6,in_r7,in_r8,a6);
        if (iVar3 == 0) {
          **(undefined4 **)(uVar2 + iVar1) = param_2;
          *(undefined4 *)(*(int *)(uVar2 + iVar1) + 4) = param_3;
          return param_1;
        }
        uVar2 = puVar8[1];
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < *puVar8);
  }
  if (uVar5 == 0xffffffff) {
    uVar5 = *puVar8;
    *puVar8 = uVar5 + 1;
    uVar5 = _realloc(uVar2,(uVar5 + 1) * 4);
    puVar8[1] = uVar5;
    iVar1 = uVar5 + *puVar8 * 4;
    puVar4 = (undefined4 *)_malloc(8);
    *(undefined4 **)(iVar1 + -4) = puVar4;
    *puVar4 = param_2;
    iVar1 = *(int *)(iVar1 + -4);
  }
  else {
    puVar4 = (undefined4 *)_malloc(8);
    *(undefined4 **)(uVar2 + uVar5 * 4) = puVar4;
    *puVar4 = param_2;
    iVar1 = *(int *)(uVar2 + uVar5 * 4);
  }
  *(undefined4 *)(iVar1 + 4) = param_3;
  return param_1;
}

/* _HashTableGet @ 0x97c08ca4 (184 bytes) */
int _HashTableGet(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  uint a6;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  
  uVar6 = 0;
  puVar4 = (uint *)*param_1;
  uVar1 = (*(code *)puVar4[2])(param_2,param_2);
  a6 = puVar4[1];
  iVar3 = (uVar1 - (uVar1 / *puVar4) * *puVar4) * 8;
  puVar5 = (uint *)(a6 + iVar3);
  if (*(int *)(a6 + iVar3) != 0) {
    do {
      uVar1 = puVar5[1];
      puVar2 = *(undefined4 **)(uVar1 + uVar6 * 4);
      if ((puVar2 != (undefined4 *)0x0) &&
         (iVar3 = (*(code *)puVar4[3])(*puVar2,param_2,in_r5,in_r6,in_r7,in_r8,a6), iVar3 == 0)) {
        return *(undefined4 *)(*(int *)(uVar1 + uVar6 * 4) + 4);
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < *puVar5);
  }
  return 0;
}

/* _HashTableRemove @ 0x97c08d5c (196 bytes) */
int _HashTableRemove(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint a6;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  undefined4 uVar7;
  
  uVar6 = 0;
  puVar4 = (uint *)*param_1;
  uVar2 = (*(code *)puVar4[2])(param_2,param_2,param_3,param_4,param_5,param_6);
  a6 = puVar4[1];
  iVar1 = (uVar2 - (uVar2 / *puVar4) * *puVar4) * 8;
  puVar5 = (uint *)(a6 + iVar1);
  if (*(int *)(a6 + iVar1) != 0) {
    do {
      uVar2 = puVar5[1];
      iVar1 = uVar6 * 4;
      if ((*(undefined4 **)(uVar2 + iVar1) != (undefined4 *)0x0) &&
         (iVar3 = (*(code *)puVar4[3])
                            (**(undefined4 **)(uVar2 + iVar1),param_2,param_3,param_4,param_5,
                             param_6,a6), iVar3 == 0)) {
        uVar7 = *(undefined4 *)(*(int *)(uVar2 + iVar1) + 4);
        _free(*(int *)(uVar2 + iVar1));
        *(undefined4 *)(uVar2 + iVar1) = 0;
        return uVar7;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < *puVar5);
  }
  return 0;
}

/* _GetValidArgs @ 0x97c08e20 (32 bytes) */
int _GetValidArgs(param_1)
  int param_1;
{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0xc) >> 0x1d;
  if (3 < (*(uint *)(param_1 + 0xc) >> 0x12 & 0xff) - 0x42) {
    return uVar1;
  }
  return uVar1 - 1;
}

/* _GetStreamArray_97c08e40 @ 0x97c08e40 (164 bytes) */
int _GetStreamArray_97c08e40(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint param_2;
  int param_3;
  uint *param_4;
  uint *param_5;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = 0;
  if (param_1 == 1) {
    for (iVar1 = **(int **)(param_3 + 8); iVar1 != 0; iVar1 = *(int *)(iVar1 + 8)) {
      uVar3 = (uint)*(ushort *)(iVar1 + 0xe);
      if ((uVar3 <= param_2) && (param_2 <= *(ushort *)(iVar1 + 0x12))) {
LAB_97c08e8c:
        *param_4 = uVar3;
        *param_5 = (uint)*(ushort *)(iVar1 + 0x12);
        return iVar2;
      }
      iVar2 = iVar2 + 1;
    }
  }
  else if (param_1 == 2) {
    for (iVar1 = **(int **)(param_3 + 0x14); iVar1 != 0; iVar1 = *(int *)(iVar1 + 8)) {
      uVar3 = (uint)*(ushort *)(iVar1 + 0xe);
      if ((uVar3 <= param_2) && (param_2 <= *(ushort *)(iVar1 + 0x12))) goto LAB_97c08e8c;
      iVar2 = iVar2 + 1;
    }
  }
  return -1;
}

/* _GetRegisterIndicies @ 0x97c08ee4 (168 bytes) */
int _GetRegisterIndicies(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  int *param_2;
  int *param_3;
  undefined4 param_4;
  int param_5;
  int param_6;
  int param_7;
  int param_8;
{
  int iVar1;
  
  *param_2 = 0;
  *param_3 = -1;
  if (param_6 != 0) {
    ((int (*)())_GetStreamArray_97c08e40)(param_4,param_5,param_1,param_2,param_3);
  }
  iVar1 = *param_3;
  if (((iVar1 == -1) && (param_7 != 0)) && (1 < param_8 + 1)) {
    iVar1 = param_5 + param_8;
    *param_2 = param_5;
    *param_3 = iVar1;
  }
  if (iVar1 == -1) {
    *param_2 = param_5;
    *param_3 = param_5;
  }
  return;
}

/* _GetRegister @ 0x97c08f8c (160 bytes) */
int _GetRegister(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  int param_3;
  int param_4;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0;
  uVar2 = 0;
  switch(param_2) {
  case 0:
    iVar3 = *(int *)(param_1 + 0x24);
    uVar2 = *(uint *)(param_1 + 0x38);
    break;
  case 1:
    iVar3 = *(int *)(param_1 + 0x20);
    uVar2 = *(uint *)(param_1 + 0x34);
    break;
  case 2:
    iVar3 = *(int *)(param_1 + 0x28);
    uVar2 = *(uint *)(param_1 + 0x3c);
    break;
  case 3:
    iVar3 = *(int *)(param_1 + 0x1c);
    uVar2 = *(uint *)(param_1 + 0x30);
    break;
  case 4:
    iVar3 = *(int *)(param_1 + 0x2c);
    uVar2 = *(uint *)(param_1 + 0x40);
  }
  uVar1 = iVar3 + param_3 * 4 + param_4;
  if (uVar1 < uVar2) {
    return *(int *)(param_1 + 0x10) + uVar1 * 0x2c;
  }
  return 0;
}

/* _BuildGenKill @ 0x97c09040 (364 bytes) */
int _BuildGenKill(param_1)
  int param_1;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  uint *puVar7;
  int iVar8;
  undefined4 *puVar9;
  uint uVar10;
  
  uVar3 = 0;
  if (*(int *)(param_1 + 4) != 0) {
    iVar4 = 0;
    do {
      iVar8 = *(int *)(param_1 + 8);
      uVar5 = 0;
      puVar6 = (uint *)(iVar8 + iVar4);
      uVar1 = _BitSetNew(*(undefined4 *)(param_1 + 0xc));
      puVar6[9] = uVar1;
      uVar1 = _BitSetNew(*(undefined4 *)(param_1 + 0xc));
      puVar6[10] = uVar1;
      uVar1 = _BitSetNew(*(undefined4 *)(param_1 + 0xc));
      iVar8 = *(int *)(iVar8 + iVar4);
      puVar6[6] = uVar1;
      if (iVar8 != 0) {
        iVar8 = 0;
        do {
          puVar7 = (uint *)(puVar6[1] + iVar8);
          if (puVar7[5] == 0) {
            uVar1 = 0;
            if (*(int *)(puVar6[1] + iVar8) != 0) {
              do {
                puVar9 = *(undefined4 **)(uVar1 * 4 + puVar7[1]);
                if (puVar9[6] == 0) {
                  iVar2 = _BitSetGetEquals(puVar6[10],*puVar9);
                  if (iVar2 == 0) {
                    _BitSetSetEquals(puVar6[9],*puVar9);
                  }
                  puVar9[9] = puVar9[9] + 1;
                }
                uVar1 = uVar1 + 1;
              } while (uVar1 < *puVar7);
            }
            uVar1 = puVar7[2];
            uVar10 = 0;
            if (uVar1 != 0) {
              do {
                puVar9 = *(undefined4 **)(uVar10 * 4 + puVar7[3]);
                if (puVar9[6] == 0) {
                  _BitSetSetEquals(puVar6[10],*puVar9);
                  puVar9[9] = puVar9[9] + 1;
                  uVar1 = puVar7[2];
                }
                uVar10 = uVar10 + 1;
              } while (uVar10 < uVar1);
            }
          }
          uVar5 = uVar5 + 1;
          iVar8 = iVar8 + 0x1c;
        } while (uVar5 < *puVar6);
      }
      uVar3 = uVar3 + 1;
      iVar4 = iVar4 + 0x2c;
    } while (uVar3 < *(uint *)(param_1 + 4));
  }
  return;
}

/* _BuildLiveOut @ 0x97c091ac (240 bytes) */
int _BuildLiveOut(param_1)
  int param_1;
{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  uVar2 = *(uint *)(param_1 + 4);
  do {
    bVar1 = false;
    uVar5 = 0;
    if (uVar2 != 0) {
      iVar6 = 0;
      do {
        uVar2 = 0;
        iVar8 = *(int *)(param_1 + 8) + iVar6;
        uVar3 = _BitSetClone(*(undefined4 *)(iVar8 + 0x18));
        if (*(int *)(iVar8 + 0x10) != 0) {
          do {
            iVar7 = uVar2 * 4;
            uVar2 = uVar2 + 1;
            iVar7 = *(int *)(iVar7 + *(int *)(iVar8 + 0x14));
            uVar4 = _BitSetClone(*(undefined4 *)(iVar7 + 0x18));
            _BitSetAndNotEquals(uVar4,*(undefined4 *)(iVar7 + 0x28));
            _BitSetOrEquals(uVar4,*(undefined4 *)(iVar7 + 0x24));
            _BitSetOrEquals(*(undefined4 *)(iVar8 + 0x18),uVar4);
            _BitSetFree(uVar4);
          } while (uVar2 < *(uint *)(iVar8 + 0x10));
        }
        uVar5 = uVar5 + 1;
        iVar6 = iVar6 + 0x2c;
        iVar8 = ((int (*)())_BitSetEqualsTest)(uVar3,*(undefined4 *)(iVar8 + 0x18));
        bVar1 = (bool)(bVar1 | iVar8 == 0);
        _BitSetFree(uVar3);
        uVar2 = *(uint *)(param_1 + 4);
      } while (uVar5 < uVar2);
    }
  } while (bVar1);
  return;
}

/* _BuildInterferenceSets @ 0x97c0929c (436 bytes) */
int _BuildInterferenceSets(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint *puVar8;
  undefined4 *puVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  
  uVar4 = 0;
  if (*(int *)(param_1 + 4) != 0) {
    iVar5 = 0;
    do {
      iVar11 = *(int *)(param_1 + 8);
      iVar6 = iVar11 + iVar5;
      uVar1 = _BitSetClone(*(undefined4 *)(iVar6 + 0x18));
      iVar11 = *(int *)(iVar11 + iVar5) + -1;
      if (-1 < iVar11) {
        iVar7 = iVar11 * 0x1c;
        do {
          puVar8 = (uint *)(*(int *)(iVar6 + 4) + iVar7);
          if (puVar8[5] == 0) {
            uVar3 = puVar8[2];
            uVar10 = 0;
            if (uVar3 != 0) {
              do {
                puVar9 = *(undefined4 **)(uVar10 * 4 + puVar8[3]);
                if (puVar9[6] == 0) {
                  for (iVar2 = _BitSetFirstSetBit(uVar1); iVar2 != -1;
                      iVar2 = _BitSetNextSetBit(uVar1,iVar2)) {
                    iVar12 = *(int *)(param_1 + 0x10) + iVar2 * 0x2c;
                    if (*(int *)(iVar12 + 0x18) == 0) {
                      _BitSetSetEquals(puVar9[2],
                                       *(undefined4 *)(*(int *)(param_1 + 0x10) + iVar2 * 0x2c));
                      _BitSetSetEquals(*(undefined4 *)(iVar12 + 8),*puVar9);
                    }
                  }
                  uVar3 = puVar8[2];
                }
                uVar10 = uVar10 + 1;
              } while (uVar10 < uVar3);
            }
            uVar10 = 0;
            if (uVar3 != 0) {
              do {
                puVar9 = *(undefined4 **)(uVar10 * 4 + puVar8[3]);
                if (puVar9[6] == 0) {
                  _BitSetClearEquals(uVar1,*puVar9);
                  uVar3 = puVar8[2];
                }
                uVar10 = uVar10 + 1;
              } while (uVar10 < uVar3);
            }
            uVar3 = *puVar8;
            uVar10 = 0;
            if (uVar3 != 0) {
              do {
                puVar9 = *(undefined4 **)(uVar10 * 4 + puVar8[1]);
                if (puVar9[6] == 0) {
                  _BitSetSetEquals(uVar1,*puVar9);
                  uVar3 = *puVar8;
                }
                uVar10 = uVar10 + 1;
              } while (uVar10 < uVar3);
            }
          }
          iVar11 = iVar11 + -1;
          iVar7 = iVar7 + -0x1c;
        } while (-1 < iVar11);
      }
      uVar4 = uVar4 + 1;
      _BitSetFree(uVar1);
      iVar5 = iVar5 + 0x2c;
    } while (uVar4 < *(uint *)(param_1 + 4));
  }
  return;
}

/* _RegistersMerge @ 0x97c09450 (612 bytes) */
int _RegistersMerge(param_1)
  int param_1;
{
  undefined4 *puVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  int local_50 [6];
  
  iVar5 = _malloc(8);
  iVar11 = 0;
  uVar6 = _malloc(0x10);
  piVar7 = (int *)_realloc(uVar6,0x10);
  iVar16 = 4;
  uVar13 = 1;
  iVar8 = 0;
  piVar4 = piVar7;
  do {
    iVar3 = *(int *)(param_1 + 0x10) + iVar8;
    iVar8 = iVar8 + 0x2c;
    *piVar4 = iVar3;
    piVar4 = piVar4 + 1;
    iVar16 = iVar16 + -1;
  } while (iVar16 != 0);
  uVar12 = 4;
  if (4 < *(uint *)(param_1 + 0xc)) {
    iVar8 = 0xb0;
    do {
      iVar16 = iVar8 + *(int *)(param_1 + 0x10);
      iVar3 = 4;
      piVar4 = local_50;
      do {
        *piVar4 = iVar16;
        piVar4 = piVar4 + 1;
        iVar16 = iVar16 + 0x2c;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      bVar2 = false;
      iVar16 = ((int (*)())_RegisterVectorIsFixed)(local_50);
      if (iVar16 == 0) {
        uVar14 = 0;
        piVar4 = piVar7;
        if (uVar13 != 0) {
LAB_97c09514:
          iVar16 = ((int (*)())_RegisterVectorCanMerge)(piVar4,local_50);
          if (iVar16 == 0) goto LAB_97c09608;
          iVar3 = 0;
          iVar16 = 3;
          do {
            iVar11 = iVar11 + 1;
            _BitSetOrEquals(*(undefined4 *)(*(int *)(iVar3 + (int)piVar4) + 8),
                            *(undefined4 *)(*(int *)(iVar3 + (int)local_50) + 8));
            *(int *)(*(int *)(iVar3 + (int)piVar4) + 0x24) =
                 *(int *)(*(int *)(iVar3 + (int)piVar4) + 0x24) +
                 *(int *)(*(int *)(iVar3 + (int)local_50) + 0x24);
            *(undefined4 *)(*(int *)(iVar3 + (int)local_50) + 0x18) = 1;
            ((int (*)())_RegistersReInterfere)(param_1,*(undefined4 *)(iVar3 + (int)local_50),
                       *(undefined4 *)(iVar3 + (int)piVar4));
            iVar5 = _realloc(iVar5,iVar11 * 8);
            iVar15 = iVar5 + iVar11 * 8;
            iVar16 = iVar16 + -1;
            *(undefined4 *)(iVar15 + -8) = *(undefined4 *)(iVar3 + (int)local_50);
            puVar1 = (undefined4 *)(iVar3 + (int)piVar4);
            iVar3 = iVar3 + 4;
            *(undefined4 *)(iVar15 + -4) = *puVar1;
          } while (-1 < iVar16);
          if ((*(int *)(*piVar4 + 0x14) == 1) && (*(int *)(local_50[0] + 0x14) == 1)) {
            iVar16 = *(int *)(*piVar4 + 0x28);
            uVar10 = *(uint *)(iVar16 + 0xc);
            uVar14 = *(uint *)(*(int *)(local_50[0] + 0x28) + 0xc) >> 0x18 & 3;
            uVar9 = uVar10 >> 0x18 & 3;
            if (uVar14 < uVar9) {
              uVar14 = uVar9;
            }
            *(uint *)(iVar16 + 0xc) = uVar14 << 0x18 | uVar10 & 0xfcffffff;
          }
          bVar2 = true;
        }
LAB_97c09618:
        if (!bVar2) goto LAB_97c09620;
      }
      else {
LAB_97c09620:
        uVar13 = uVar13 + 1;
        piVar7 = (int *)_realloc(piVar7,uVar13 * 0x10);
        iVar3 = 4;
        iVar16 = 0;
        do {
          *(undefined4 *)((int)piVar7 + iVar16 + uVar13 * 0x10 + -0x10) =
               *(undefined4 *)(iVar16 + (int)local_50);
          iVar16 = iVar16 + 4;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
      uVar12 = uVar12 + 4;
      iVar8 = iVar8 + 0xb0;
    } while (uVar12 < *(uint *)(param_1 + 0xc));
  }
  if (piVar7 != (int *)0x0) {
    _free(piVar7);
  }
  ((int (*)())_RegistersReplace)(param_1,iVar11,iVar5);
  if (iVar5 != 0) {
    _free(iVar5);
  }
  return;
LAB_97c09608:
  uVar14 = uVar14 + 1;
  piVar4 = piVar4 + 4;
  if (uVar13 <= uVar14) goto LAB_97c09618;
  goto LAB_97c09514;
}

/* _DeadCodeEliminationSimple @ 0x97c096b4 (440 bytes) */
int _DeadCodeEliminationSimple(param_1)
  undefined4 *param_1;
{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint *puVar12;
  
  uVar6 = 0;
  if (param_1[1] != 0) {
    iVar7 = 0;
    do {
      iVar10 = param_1[2];
      iVar8 = iVar10 + iVar7;
      uVar2 = _BitSetClone(*(undefined4 *)(iVar8 + 0x18));
      iVar10 = *(int *)(iVar10 + iVar7) + -1;
      if (-1 < iVar10) {
        iVar9 = iVar10 * 0x1c;
        do {
          puVar12 = (uint *)(*(int *)(iVar8 + 4) + iVar9);
          if (puVar12[5] == 0) {
            uVar5 = puVar12[2];
            uVar11 = 0;
            if (uVar5 == 0) {
              bVar1 = puVar12[4] == 0;
LAB_97c0978c:
              if (bVar1) {
                _PPStreamRemoveOperation(*param_1,puVar12[6]);
                puVar12[5] = 1;
                goto LAB_97c09828;
              }
            }
            else {
              bVar1 = puVar12[4] == 0;
              if (bVar1) {
                do {
                  puVar4 = *(undefined4 **)(uVar11 * 4 + puVar12[3]);
                  if (puVar4[6] == 0) {
                    iVar3 = _BitSetGetEquals(uVar2,*puVar4);
                    if (iVar3 != 0) {
                      bVar1 = false;
                    }
                    uVar5 = puVar12[2];
                  }
                  uVar11 = uVar11 + 1;
                  if (uVar5 <= uVar11) goto LAB_97c0978c;
                } while (bVar1);
              }
            }
            uVar11 = 0;
            if (uVar5 != 0) {
              do {
                puVar4 = *(undefined4 **)(uVar11 * 4 + puVar12[3]);
                if (puVar4[6] == 0) {
                  _BitSetClearEquals(uVar2,*puVar4);
                  uVar5 = puVar12[2];
                }
                uVar11 = uVar11 + 1;
              } while (uVar11 < uVar5);
            }
            uVar5 = *puVar12;
            uVar11 = 0;
            if (uVar5 != 0) {
              do {
                puVar4 = *(undefined4 **)(uVar11 * 4 + puVar12[1]);
                if (puVar4[6] == 0) {
                  _BitSetSetEquals(uVar2,*puVar4);
                  uVar5 = *puVar12;
                }
                uVar11 = uVar11 + 1;
              } while (uVar11 < uVar5);
            }
          }
LAB_97c09828:
          iVar10 = iVar10 + -1;
          iVar9 = iVar9 + -0x1c;
        } while (-1 < iVar10);
      }
      uVar6 = uVar6 + 1;
      _BitSetFree(uVar2);
      iVar7 = iVar7 + 0x2c;
    } while (uVar6 < (uint)param_1[1]);
  }
  return;
}

/* _RegistersReInterfere @ 0x97c0986c (140 bytes) */
int _RegistersReInterfere(param_1, param_2, param_3)
  int param_1;
  undefined4 *param_2;
  undefined4 *param_3;
{
  int iVar1;
  int iVar2;
  
  for (iVar1 = _BitSetFirstSetBit(param_2[2]); iVar1 != -1;
      iVar1 = _BitSetNextSetBit(param_2[2],iVar1)) {
    iVar2 = *(int *)(param_1 + 0x10) + iVar1 * 0x2c;
    if (*(int *)(iVar2 + 0x18) == 0) {
      _BitSetClearEquals(*(undefined4 *)(iVar2 + 8),*param_2);
      _BitSetSetEquals(*(undefined4 *)(iVar2 + 8),*param_3);
    }
  }
  return;
}

/* _RegistersReplace @ 0x97c098f8 (568 bytes) */
int _RegistersReplace(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int *param_3;
{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  int *piVar4;
  uint *puVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  
  for (iVar13 = **(int **)(*param_1 + 0x20); iVar13 != 0; iVar13 = *(int *)(iVar13 + 8)) {
    iVar11 = 0;
    if (0 < param_2) {
      do {
        iVar1 = ((int (*)())_GetValidArgs)(iVar13);
        iVar6 = 0;
        piVar4 = param_3 + iVar11 * 2;
        if (iVar1 < 1) {
          iVar7 = *piVar4;
        }
        else {
          iVar7 = param_3[iVar11 * 2];
          iVar10 = iVar13;
          do {
            if (((*(uint *)(iVar10 + 0x1c) >> 0x17 & 7) == *(uint *)(iVar7 + 0x14)) &&
               ((uint)*(ushort *)(iVar10 + 0x22) == *(uint *)(iVar7 + 4))) {
              *(uint *)(iVar10 + 0x1c) =
                   (*(uint *)(piVar4[1] + 0x14) & 7) << 0x17 | *(uint *)(iVar10 + 0x1c) & 0xfc7fffff
              ;
              *(undefined2 *)(iVar10 + 0x22) = *(undefined2 *)(piVar4[1] + 6);
              iVar7 = *piVar4;
            }
            iVar6 = iVar6 + 1;
            iVar10 = iVar10 + 8;
          } while (iVar6 < iVar1);
        }
        if (((*(uint *)(iVar13 + 0x14) >> 0x11 & 7) == *(uint *)(iVar7 + 0x14)) &&
           ((uint)*(ushort *)(iVar13 + 0x1a) == *(uint *)(iVar7 + 4))) {
          *(uint *)(iVar13 + 0x14) =
               (*(uint *)(piVar4[1] + 0x14) & 7) << 0x11 | *(uint *)(iVar13 + 0x14) & 0xfff1ffff;
          *(undefined2 *)(iVar13 + 0x1a) = *(undefined2 *)(piVar4[1] + 6);
        }
        iVar11 = iVar11 + 4;
      } while (iVar11 < param_2);
    }
  }
  uVar8 = param_1[1];
  uVar12 = 0;
  if (uVar8 != 0) {
    iVar13 = 0;
    do {
      uVar3 = 0;
      puVar2 = (uint *)(param_1[2] + iVar13);
      if (*(int *)(param_1[2] + iVar13) != 0) {
        iVar11 = 0;
        do {
          puVar5 = (uint *)(puVar2[1] + iVar11);
          if ((puVar5[5] == 0) && (piVar4 = param_3, iVar1 = param_2, 0 < param_2)) {
            do {
              uVar8 = *puVar5;
              uVar9 = 0;
              if (uVar8 != 0) {
                do {
                  if (*(int *)(uVar9 * 4 + puVar5[1]) == *piVar4) {
                    *(int *)(uVar9 * 4 + puVar5[1]) = piVar4[1];
                    uVar8 = *puVar5;
                  }
                  uVar9 = uVar9 + 1;
                } while (uVar9 < uVar8);
              }
              uVar8 = puVar5[2];
              uVar9 = 0;
              if (uVar8 != 0) {
                do {
                  if (*(int *)(uVar9 * 4 + puVar5[3]) == *piVar4) {
                    *(int *)(uVar9 * 4 + puVar5[3]) = piVar4[1];
                    uVar8 = puVar5[2];
                  }
                  uVar9 = uVar9 + 1;
                } while (uVar9 < uVar8);
              }
              iVar1 = iVar1 + -1;
              piVar4 = piVar4 + 2;
            } while (iVar1 != 0);
          }
          uVar3 = uVar3 + 1;
          iVar11 = iVar11 + 0x1c;
        } while (uVar3 < *puVar2);
        uVar8 = param_1[1];
      }
      uVar12 = uVar12 + 1;
      iVar13 = iVar13 + 0x2c;
    } while (uVar12 < uVar8);
  }
  return;
}

/* _RegistersCleanup @ 0x97c09b30 (628 bytes) */
int _RegistersCleanup(param_1)
  int *param_1;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint *puVar4;
  uint *puVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  uVar9 = 0;
  uVar8 = 0;
  if (param_1[3] != 0) {
    iVar6 = 0;
    do {
      uVar9 = uVar9 + 1;
      iVar2 = param_1[4] + iVar6;
      iVar6 = iVar6 + 0x2c;
      *(undefined4 *)(iVar2 + 0x18) = 1;
      uVar8 = param_1[3];
    } while (uVar9 < uVar8);
  }
  uVar9 = param_1[1];
  uVar10 = 0;
  if (uVar9 != 0) {
    iVar6 = 0;
    do {
      uVar8 = 0;
      puVar4 = (uint *)(param_1[2] + iVar6);
      if (*(int *)(param_1[2] + iVar6) != 0) {
        iVar2 = 0;
        do {
          uVar9 = puVar4[1];
          puVar5 = (uint *)(uVar9 + iVar2);
          if (puVar5[5] == 0) {
            uVar7 = 0;
            if (*(int *)(uVar9 + iVar2) != 0) {
              do {
                iVar1 = uVar7 * 4;
                uVar7 = uVar7 + 1;
                *(undefined4 *)(*(int *)(iVar1 + puVar5[1]) + 0x18) = 0;
              } while (uVar7 < *puVar5);
            }
            uVar9 = 0;
            if (puVar5[2] != 0) {
              do {
                iVar1 = uVar9 * 4;
                uVar9 = uVar9 + 1;
                *(undefined4 *)(*(int *)(iVar1 + puVar5[3]) + 0x18) = 0;
              } while (uVar9 < puVar5[2]);
            }
          }
          uVar8 = uVar8 + 1;
          iVar2 = iVar2 + 0x1c;
        } while (uVar8 < *puVar4);
        uVar9 = param_1[1];
      }
      uVar10 = uVar10 + 1;
      iVar6 = iVar6 + 0x2c;
    } while (uVar10 < uVar9);
    uVar8 = param_1[3];
  }
  uVar9 = 0;
  for (iVar6 = **(int **)(*param_1 + 0x10); iVar6 != 0; iVar6 = *(int *)(iVar6 + 8)) {
    uVar10 = uVar9;
    if (((*(uint *)(iVar6 + 0xc) >> 0x10 & 0x1f) != 0x11) &&
       (uVar10 = *(ushort *)(iVar6 + 0x12) + 1, uVar10 < uVar9)) {
      uVar10 = uVar9;
    }
    uVar9 = uVar10;
  }
  uVar10 = 0;
  if (uVar8 != 0) {
    do {
      iVar6 = param_1[4] + uVar10 * 0x2c;
      if ((((*(int *)(iVar6 + 0x18) == 0) || (*(int *)(iVar6 + 0x44) == 0)) ||
          (*(int *)(iVar6 + 0x70) == 0)) ||
         ((*(int *)(iVar6 + 0x9c) == 0 || (*(int *)(iVar6 + 0x28) == 0)))) goto LAB_97c09d98;
      switch(*(undefined4 *)(iVar6 + 0x14)) {
      default:
        goto switchD_97c09d2c_caseD_0;
      case 1:
        uVar3 = *(undefined4 *)(*param_1 + 4);
        break;
      case 2:
        if (uVar9 <= *(uint *)(iVar6 + 4)) {
          uVar3 = *(undefined4 *)(*param_1 + 0x10);
          break;
        }
        goto switchD_97c09d2c_caseD_0;
      case 3:
        uVar3 = *(undefined4 *)(*param_1 + 0x1c);
        break;
      case 4:
        uVar3 = *(undefined4 *)(*param_1 + 0xc);
      }
      _PPStreamChunkListRemoveChunk(uVar3,*(int *)(iVar6 + 0x28));
switchD_97c09d2c_caseD_0:
      *(undefined4 *)(iVar6 + 0x28) = 0;
      *(undefined4 *)(iVar6 + 0x54) = 0;
      *(undefined4 *)(iVar6 + 0x80) = 0;
      *(undefined4 *)(iVar6 + 0xac) = 0;
      uVar8 = param_1[3];
LAB_97c09d98:
      uVar10 = uVar10 + 4;
    } while (uVar10 < uVar8);
  }
  return;
}

/* _RegisterIsMergeable @ 0x97c09db8 (40 bytes) */
int _RegisterIsMergeable(param_1)
  int param_1;
{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((*(int *)(param_1 + 0x14) == 1) && (*(int *)(param_1 + 0x18) == 0)) {
    uVar1 = 1;
  }
  return uVar1;
}

/* _RegisterCanMerge @ 0x97c09de0 (168 bytes) */
int _RegisterCanMerge(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (((((*(int *)(param_1 + 0x10) == param_2[4]) && (*(int *)(param_1 + 0xc) == param_2[3])) &&
       (iVar1 = ((int (*)())_RegisterIsMergeable)(param_1), iVar1 != 0)) &&
      ((iVar1 = ((int (*)())_RegisterIsMergeable)(param_2), iVar1 != 0 &&
       ((iVar1 = ((int (*)())_RegisterIsFixed)(param_1), iVar1 == 0 ||
        (iVar1 = ((int (*)())_RegisterIsFixed)(param_2), iVar1 == 0)))))) &&
     (iVar1 = _BitSetGetEquals(*(undefined4 *)(param_1 + 8),*param_2), iVar1 == 0)) {
    uVar2 = 1;
  }
  return uVar2;
}

/* _RegisterIsFixed @ 0x97c09e88 (40 bytes) */
int _RegisterIsFixed(param_1)
  int param_1;
{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((*(int *)(param_1 + 0x1c) != 0) || (*(int *)(param_1 + 0x20) != 0)) {
    uVar1 = 1;
  }
  return uVar1;
}

/* _RegisterVectorCanMerge @ 0x97c09eb0 (136 bytes) */
int _RegisterVectorCanMerge(param_1, param_2)
  undefined4 *param_1;
  undefined4 *param_2;
{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = ((int (*)())_RegisterCanMerge)(*param_1,*param_2);
  if ((((iVar1 != 0) && (iVar1 = ((int (*)())_RegisterCanMerge)(param_1[1],param_2[1]), iVar1 != 0)) &&
      (iVar1 = ((int (*)())_RegisterCanMerge)(param_1[2],param_2[2]), iVar1 != 0)) &&
     (iVar1 = ((int (*)())_RegisterCanMerge)(param_1[3],param_2[3]), iVar1 != 0)) {
    uVar2 = 1;
  }
  return uVar2;
}

/* _RegisterVectorIsFixed @ 0x97c09f38 (116 bytes) */
int _RegisterVectorIsFixed(param_1)
  undefined4 *param_1;
{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = ((int (*)())_RegisterIsFixed)(*param_1);
  if ((((iVar1 != 0) || (iVar1 = ((int (*)())_RegisterIsFixed)(param_1[1]), iVar1 != 0)) ||
      (iVar1 = ((int (*)())_RegisterIsFixed)(param_1[2]), iVar1 != 0)) ||
     (iVar1 = ((int (*)())_RegisterIsFixed)(param_1[3]), iVar1 != 0)) {
    uVar2 = 1;
  }
  return uVar2;
}

/* _RegisterAdd @ 0x97c09fac (232 bytes) */
int _RegisterAdd(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
  int param_5;
  undefined4 param_6;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = param_4 + param_5 * 4;
  if (*(uint *)(param_1 + 0xc) < iVar4 + 4U) {
    iVar1 = _realloc(*(undefined4 *)(param_1 + 0x10),iVar4 * 0x2c + 0xb0);
    *(int *)(param_1 + 0x10) = iVar1;
    _memset(*(int *)(param_1 + 0xc) * 0x2c + iVar1,0,(iVar4 - *(int *)(param_1 + 0xc)) * 0x2c + 0xb0
           );
    *(uint *)(param_1 + 0xc) = iVar4 + 4U;
  }
  iVar3 = iVar4 * 0x2c;
  iVar5 = 4;
  iVar1 = 0;
  do {
    iVar2 = *(int *)(param_1 + 0x10) + iVar3;
    *(int *)(*(int *)(param_1 + 0x10) + iVar3) = iVar4 + iVar1;
    *(int *)(iVar2 + 0xc) = iVar1;
    iVar3 = iVar3 + 0x2c;
    *(undefined4 *)(iVar2 + 0x28) = param_2;
    iVar1 = iVar1 + 1;
    *(undefined4 *)(iVar2 + 8) = 0;
    *(undefined4 *)(iVar2 + 0x14) = param_3;
    *(undefined4 *)(iVar2 + 0x10) = param_6;
    *(int *)(iVar2 + 4) = param_5;
    *(undefined4 *)(iVar2 + 0x18) = 0;
    *(undefined4 *)(iVar2 + 0x1c) = 0;
    *(undefined4 *)(iVar2 + 0x20) = 0;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  return 0;
}

/* _RegisterFree @ 0x97c0a094 (16 bytes) */
int _RegisterFree(param_1)
  int param_1;
{
  if (*(int *)(param_1 + 8) == 0) {
    return;
  }
  _BitSetFree(*(int *)(param_1 + 8));
  return;
}

/* _InstructionAdd @ 0x97c0a0a4 (1324 bytes) */
int _InstructionAdd(param_1, param_2, param_3)
  undefined4 *param_1;
  int *param_2;
  int param_3;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int *piVar11;
  int iVar12;
  uint *puVar13;
  int iVar14;
  int iVar15;
  uint local_70 [5];
  int local_5c;
  int local_58;
  int local_54 [3];
  
  iVar3 = *param_2;
  *param_2 = iVar3 + 1;
  uVar9 = 0;
  bVar1 = false;
  iVar3 = _realloc(param_2[1],(iVar3 + 1) * 0x1c);
  param_2[1] = iVar3;
  iVar3 = iVar3 + *param_2 * 0x1c;
  piVar11 = (int *)(iVar3 + -0x1c);
  *(undefined4 *)(iVar3 + -0xc) = 0;
  *(int *)(iVar3 + -4) = param_3;
  switch(*(uint *)(param_3 + 0xc) >> 0x12 & 0xff) {
  case 0x4b:
  case 0x4c:
  case 0x4d:
  case 0x4f:
  case 0x54:
  case 0x55:
  case 0x56:
  case 0x57:
  case 0x58:
  case 0x59:
  case 0x5a:
  case 0x5b:
  case 0x69:
  case 0x6a:
  case 0x6b:
    *(undefined4 *)(iVar3 + -0xc) = 1;
    break;
  case 0x6d:
    bVar1 = true;
  }
  *piVar11 = 0;
  iVar10 = 0;
  *(undefined4 *)(iVar3 + -8) = 0;
  uVar5 = _malloc(4);
  *(undefined4 *)(iVar3 + -0x18) = uVar5;
  iVar6 = ((int (*)())_GetValidArgs)(param_3);
  iVar12 = param_3;
  iVar15 = param_3;
  if (0 < iVar6) {
    do {
      uVar4 = *(uint *)(iVar15 + 0x1c);
      local_70[0] = 0;
      uVar2 = uVar4 >> 0xc & 3;
      local_70[1] = 0;
      local_70[2] = 0;
      local_70[3] = 0;
      if (uVar2 == 1) {
LAB_97c0a284:
        *(undefined4 *)((int)local_70 + (*(uint *)(iVar15 + 0x1c) >> 0x11 & 0xc)) = 1;
LAB_97c0a290:
        *(undefined4 *)((int)local_70 + (*(uint *)(iVar15 + 0x1c) >> 0x13 & 0xc)) = 1;
      }
      else {
        if (1 < uVar2) {
          if (uVar2 != 2) {
            if (uVar2 != 3) goto LAB_97c0a29c;
            *(undefined4 *)((int)local_70 + (uVar4 >> 0xd & 0xc)) = 1;
            uVar4 = *(uint *)(iVar15 + 0x1c);
          }
          *(undefined4 *)((int)local_70 + (uVar4 >> 0xf & 0xc)) = 1;
          goto LAB_97c0a284;
        }
        if (uVar2 == 0) goto LAB_97c0a290;
      }
LAB_97c0a29c:
      uVar2 = *(uint *)(iVar15 + 0x1c);
      uVar9 = uVar9 | uVar2 >> 0x1f;
      ((int (*)())_GetRegisterIndicies)(*param_1,local_70 + 4,&local_5c,uVar2 >> 0x17 & 7,(uint)*(ushort *)(iVar15 + 0x22),
                 uVar2 >> 0x1f,uVar2 >> 0xe & 1,uVar2 >> 0xc & 3);
      if ((int)local_70[4] <= local_5c) {
        uVar2 = local_70[4];
        do {
          iVar14 = 0;
          puVar13 = local_70;
          do {
            uVar4 = *puVar13;
            puVar13 = puVar13 + 1;
            if ((uVar4 != 0) &&
               (iVar7 = ((int (*)())_GetRegister)(param_1,*(uint *)(iVar12 + 0x1c) >> 0x17 & 7,uVar2,iVar14),
               iVar7 != 0)) {
              iVar7 = *piVar11;
              *piVar11 = iVar7 + 1;
              iVar7 = _realloc(*(undefined4 *)(iVar3 + -0x18),(iVar7 + 1) * 4);
              *(int *)(iVar3 + -0x18) = iVar7;
              iVar7 = iVar7 + *piVar11 * 4;
              iVar8 = ((int (*)())_GetRegister)(param_1,*(uint *)(iVar12 + 0x1c) >> 0x17 & 7,uVar2,iVar14);
              *(int *)(iVar7 + -4) = iVar8;
              uVar4 = 0;
              *(uint *)(iVar8 + 0x1c) = *(uint *)(iVar8 + 0x1c) | *(uint *)(iVar12 + 0x1c) >> 0x1f;
              iVar7 = *(int *)(iVar7 + -4);
              if (((*(uint *)(iVar12 + 0x1c) & 0x4000) != 0) &&
                 (1 < (*(uint *)(iVar12 + 0x1c) >> 0xc & 3) + 1)) {
                uVar4 = 1;
              }
              *(uint *)(iVar7 + 0x20) = *(uint *)(iVar7 + 0x20) | uVar4;
            }
            iVar14 = iVar14 + 1;
          } while (iVar14 < 4);
          uVar2 = uVar2 + 1;
        } while ((int)uVar2 <= local_5c);
      }
      iVar10 = iVar10 + 1;
      iVar12 = iVar12 + 8;
      iVar15 = iVar15 + 8;
    } while (iVar10 < iVar6);
  }
  uVar2 = *(uint *)(param_3 + 0x14);
  local_70[1] = uVar2 >> 0xe & 1;
  local_70[3] = uVar2 >> 0x10 & 1;
  local_70[0] = uVar2 >> 0xd & 1;
  local_70[2] = uVar2 >> 0xf & 1;
  *(undefined4 *)(iVar3 + -0x14) = 0;
  uVar5 = _malloc(4);
  *(undefined4 *)(iVar3 + -0x10) = uVar5;
  *(uint *)(iVar3 + -0xc) =
       *(uint *)(iVar3 + -0xc) | (uint)((*(uint *)(param_3 + 0x14) >> 0x11 & 7) == 3);
  uVar4 = *(uint *)(param_3 + 0x14);
  uVar2 = *(uint *)(param_3 + 0x18);
  ((int (*)())_GetRegisterIndicies)(*param_1,&local_58,local_54,uVar4 >> 0x11 & 7,uVar2 & 0xffff,uVar2 >> 0x1f,
             uVar4 >> 0xc & 1,uVar4 >> 10 & 3);
  if (local_58 <= local_54[0]) {
    iVar12 = local_58;
    do {
      iVar15 = 0;
      puVar13 = local_70;
      do {
        uVar4 = *puVar13;
        puVar13 = puVar13 + 1;
        if (uVar4 != 0) {
          iVar6 = ((int (*)())_GetRegister)(param_1,*(uint *)(param_3 + 0x14) >> 0x11 & 7,iVar12,iVar15);
          if (iVar6 != 0) {
            iVar6 = *(int *)(iVar3 + -0x14) + 1;
            *(int *)(iVar3 + -0x14) = iVar6;
            iVar6 = _realloc(*(undefined4 *)(iVar3 + -0x10),iVar6 * 4);
            *(int *)(iVar3 + -0x10) = iVar6;
            iVar6 = iVar6 + *(int *)(iVar3 + -0x14) * 4;
            iVar10 = ((int (*)())_GetRegister)(param_1,*(uint *)(param_3 + 0x14) >> 0x11 & 7,iVar12,iVar15);
            *(int *)(iVar6 + -4) = iVar10;
            uVar4 = 0;
            *(uint *)(iVar10 + 0x1c) = *(uint *)(iVar10 + 0x1c) | *(uint *)(param_3 + 0x18) >> 0x1f;
            iVar6 = *(int *)(iVar6 + -4);
            if (((*(uint *)(param_3 + 0x14) & 0x1000) != 0) &&
               (1 < (*(uint *)(param_3 + 0x14) >> 10 & 3) + 1)) {
              uVar4 = 1;
            }
            *(uint *)(iVar6 + 0x20) = *(uint *)(iVar6 + 0x20) | uVar4;
          }
          if ((bVar1 || (int)uVar2 < 0) &&
             (iVar6 = ((int (*)())_GetRegister)(param_1,*(uint *)(param_3 + 0x14) >> 0x11 & 7,iVar12,iVar15),
             iVar6 != 0)) {
            iVar6 = *piVar11;
            *piVar11 = iVar6 + 1;
            iVar10 = _realloc(*(undefined4 *)(iVar3 + -0x18),(iVar6 + 1) * 4);
            iVar6 = *piVar11;
            *(int *)(iVar3 + -0x18) = iVar10;
            uVar5 = ((int (*)())_GetRegister)(param_1,*(uint *)(param_3 + 0x14) >> 0x11 & 7,iVar12,iVar15);
            *(undefined4 *)(iVar10 + iVar6 * 4 + -4) = uVar5;
          }
        }
        iVar15 = iVar15 + 1;
      } while (iVar15 < 4);
      iVar12 = iVar12 + 1;
    } while (iVar12 <= local_54[0]);
  }
  if ((uVar9 != 0 || (int)uVar2 < 0) && (iVar12 = ((int (*)())_GetRegister)(param_1,4,0,0), iVar12 != 0)) {
    iVar12 = *piVar11;
    *piVar11 = iVar12 + 1;
    iVar15 = _realloc(*(undefined4 *)(iVar3 + -0x18),(iVar12 + 1) * 4);
    iVar12 = *piVar11;
    *(int *)(iVar3 + -0x18) = iVar15;
    uVar5 = ((int (*)())_GetRegister)(param_1,4,0,0);
    *(undefined4 *)(iVar15 + iVar12 * 4 + -4) = uVar5;
  }
  return piVar11;
}

/* _InstructionFree @ 0x97c0a65c (88 bytes) */
int _InstructionFree(param_1)
  int param_1;
{
  if (*(int *)(param_1 + 4) != 0) {
    _free(*(int *)(param_1 + 4));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    _free(*(int *)(param_1 + 0xc));
    return;
  }
  return;
}

/* _BlockAdd @ 0x97c0a6b4 (160 bytes) */
int _BlockAdd(param_1)
  int param_1;
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 4) + 1;
  *(int *)(param_1 + 4) = iVar1;
  iVar1 = _realloc(*(undefined4 *)(param_1 + 8),iVar1 * 0x2c);
  *(int *)(param_1 + 8) = iVar1;
  iVar1 = iVar1 + *(int *)(param_1 + 4) * 0x2c;
  *(undefined4 *)(iVar1 + -0x2c) = 0;
  uVar2 = _malloc(0x1c);
  *(undefined4 *)(iVar1 + -0x24) = 0;
  *(undefined4 *)(iVar1 + -0x28) = uVar2;
  uVar2 = _malloc(4);
  *(undefined4 *)(iVar1 + -0x1c) = 0;
  *(undefined4 *)(iVar1 + -0x20) = uVar2;
  uVar2 = _malloc(4);
  *(undefined4 *)(iVar1 + -4) = 0;
  *(undefined4 *)(iVar1 + -0x18) = uVar2;
  *(undefined4 *)(iVar1 + -0x14) = 0;
  *(undefined4 *)(iVar1 + -0x10) = 0;
  *(undefined4 *)(iVar1 + -0xc) = 0;
  *(undefined4 *)(iVar1 + -8) = 0;
  return iVar1 + -0x2c;
}

/* _BlockFree @ 0x97c0a754 (236 bytes) */
int _BlockFree(param_1)
  uint *param_1;
{
  uint uVar1;
  int iVar2;
  
  uVar1 = 0;
  if (*param_1 != 0) {
    iVar2 = 0;
    do {
      uVar1 = uVar1 + 1;
      ((int (*)())_InstructionFree)(param_1[1] + iVar2);
      iVar2 = iVar2 + 0x1c;
    } while (uVar1 < *param_1);
  }
  if (param_1[1] != 0) {
    _free(param_1[1]);
  }
  if (param_1[3] != 0) {
    _free(param_1[3]);
  }
  if (param_1[5] != 0) {
    _free(param_1[5]);
  }
  if (param_1[6] != 0) {
    _BitSetFree(param_1[6]);
  }
  if (param_1[7] != 0) {
    _BitSetFree(param_1[7]);
  }
  if (param_1[8] != 0) {
    _BitSetFree(param_1[8]);
  }
  if (param_1[9] != 0) {
    _BitSetFree(param_1[9]);
  }
  if (param_1[10] != 0) {
    _BitSetFree(param_1[10]);
    return;
  }
  return;
}

/* _RegistersInitialize @ 0x97c0a840 (104 bytes) */
int _RegistersInitialize(param_1)
  int param_1;
{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = 0;
  uVar1 = *(uint *)(param_1 + 0xc);
  if (uVar1 != 0) {
    iVar3 = 0;
    do {
      iVar4 = *(int *)(param_1 + 0x10);
      uVar2 = _BitSetNew(uVar1);
      iVar4 = iVar4 + iVar3;
      iVar3 = iVar3 + 0x2c;
      *(undefined4 *)(iVar4 + 8) = uVar2;
      _BitSetSetEquals(uVar2,uVar5);
      uVar1 = *(uint *)(param_1 + 0xc);
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar1);
  }
  return;
}

/* _Registerify @ 0x97c0a8a8 (424 bytes) */
int _Registerify(param_1)
  int *param_1;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = param_1[3];
  iVar3 = *param_1;
  param_1[7] = iVar1;
  iVar4 = **(int **)(iVar3 + 0x1c);
  if (iVar4 != 0) {
    do {
      ((int (*)())_RegisterAdd)(param_1,iVar4,3,param_1[7],(uint)*(ushort *)(iVar4 + 0x12),
                   *(uint *)(iVar4 + 0xc) >> 0x1a & 7);
      iVar4 = *(int *)(iVar4 + 8);
    } while (iVar4 != 0);
    iVar1 = param_1[3];
    iVar3 = *param_1;
  }
  param_1[0xc] = iVar1;
  param_1[8] = iVar1;
  iVar4 = **(int **)(iVar3 + 4);
  if (iVar4 != 0) {
    do {
      ((int (*)())_RegisterAdd)(param_1,iVar4,1,param_1[8],(uint)*(ushort *)(iVar4 + 0x12),
                   *(uint *)(iVar4 + 0xc) >> 0x1a & 7);
      iVar4 = *(int *)(iVar4 + 8);
    } while (iVar4 != 0);
    iVar1 = param_1[3];
    iVar3 = *param_1;
  }
  param_1[0xd] = iVar1;
  param_1[9] = iVar1;
  iVar4 = **(int **)(iVar3 + 0x18);
  if (iVar4 != 0) {
    do {
      ((int (*)())_RegisterAdd)(param_1,iVar4,0,param_1[9],(uint)*(ushort *)(iVar4 + 0x12),
                   *(uint *)(iVar4 + 0xc) >> 0x1a & 7);
      iVar4 = *(int *)(iVar4 + 8);
    } while (iVar4 != 0);
    iVar1 = param_1[3];
    iVar3 = *param_1;
  }
  param_1[0xe] = iVar1;
  param_1[10] = iVar1;
  iVar4 = **(int **)(iVar3 + 0x10);
  if (iVar4 != 0) {
    do {
      ((int (*)())_RegisterAdd)(param_1,iVar4,2,param_1[10],(uint)*(ushort *)(iVar4 + 0x12),
                   *(uint *)(iVar4 + 0xc) >> 0x1a & 7);
      iVar4 = *(int *)(iVar4 + 8);
    } while (iVar4 != 0);
    iVar1 = param_1[3];
    iVar3 = *param_1;
  }
  param_1[0xf] = iVar1;
  param_1[0xb] = iVar1;
  iVar3 = **(int **)(iVar3 + 0xc);
  if (iVar3 != 0) {
    do {
      ((int (*)())_RegisterAdd)(param_1,iVar3,4,param_1[0xb],*(undefined4 *)(iVar3 + 0xc),3);
      iVar3 = *(int *)(iVar3 + 8);
    } while (iVar3 != 0);
    iVar1 = param_1[3];
  }
  param_1[0x10] = iVar1;
  uVar2 = ((int (*)())_RegistersInitialize)(param_1);
  return uVar2;
}

/* _RegistersFree @ 0x97c0aa50 (124 bytes) */
int _RegistersFree(param_1)
  int param_1;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = 0;
  if (*(int *)(param_1 + 0xc) != 0) {
    iVar3 = 0;
    do {
      uVar2 = uVar2 + 1;
      iVar1 = *(int *)(param_1 + 0x10) + iVar3;
      iVar3 = iVar3 + 0x2c;
      ((int (*)())_RegisterFree)(iVar1);
    } while (uVar2 < *(uint *)(param_1 + 0xc));
  }
  if (*(int *)(param_1 + 0x10) != 0) {
    _free(*(int *)(param_1 + 0x10));
    return;
  }
  return;
}

/* _GetOrAddBlock @ 0x97c0aacc (148 bytes) */
int _GetOrAddBlock(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = param_2 * 4;
  if (*(uint *)(param_1 + 0x14) < param_2 + 1U) {
    iVar2 = _realloc(*(undefined4 *)(param_1 + 0x18),iVar1 + 4);
    *(int *)(param_1 + 0x18) = iVar2;
    _memset(*(int *)(param_1 + 0x14) * 4 + iVar2,0,(param_2 - *(int *)(param_1 + 0x14)) * 4 + 4);
    *(uint *)(param_1 + 0x14) = param_2 + 1U;
  }
  if (*(int *)(iVar1 + *(int *)(param_1 + 0x18)) == 0) {
    uVar3 = ((int (*)())_BlockAdd)(param_1);
    *(undefined4 *)(iVar1 + *(int *)(param_1 + 0x18)) = uVar3;
  }
  return;
}

/* _GetBlockFrom @ 0x97c0ab60 (84 bytes) */
int _GetBlockFrom(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  int *param_3;
{
  int iVar1;
  int iVar2;
  
  if (*(uint *)(param_1 + 0x14) <= param_2) {
    return 0;
  }
  iVar2 = *(int *)(param_1 + 0x18);
  iVar1 = param_2 * 4;
  if (*(int *)(iVar1 + iVar2) == 0) {
    *(int *)(iVar1 + iVar2) = *(int *)(param_1 + 8) + *param_3 * 0x2c;
    *param_3 = *param_3 + 1;
    iVar2 = *(int *)(param_1 + 0x18);
  }
  return *(undefined4 *)(iVar1 + iVar2);
}

/* _GetBlock @ 0x97c0abb4 (36 bytes) */
int _GetBlock(param_1, param_2)
  int param_1;
  uint param_2;
{
  if (*(uint *)(param_1 + 0x14) <= param_2) {
    return 0;
  }
  return *(undefined4 *)(param_2 * 4 + *(int *)(param_1 + 0x18));
}

/* _Blockify @ 0x97c0abd8 (752 bytes) */
int _Blockify(param_1)
  int *param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined4 local_30 [6];
  
  _memset(param_1[6],0,param_1[5] << 2);
  ((int (*)())_GetOrAddBlock)(param_1,0);
  iVar7 = **(int **)(*param_1 + 0x20);
  while (iVar7 != 0) {
    iVar5 = *(int *)(iVar7 + 8);
    uVar4 = *(uint *)(iVar7 + 0xc);
    if (iVar5 != 0) {
      uVar4 = *(uint *)(iVar5 + 0xc);
    }
    uVar4 = uVar4 & 0x3ffff;
    switch(*(uint *)(iVar7 + 0xc) >> 0x12 & 0xff) {
    case 0x4b:
    case 0x54:
    case 0x55:
    case 0x56:
    case 0x57:
    case 0x58:
    case 0x5a:
    case 0x5b:
    case 0x69:
    case 0x6a:
    case 0x6b:
      ((int (*)())_GetOrAddBlock)(param_1,uVar4);
    case 0x4c:
      uVar4 = *(uint *)(iVar7 + 0x10) & 0x3ffff;
      break;
    case 0x4d:
    case 0x59:
      break;
    default:
      goto switchD_97c0ac70_caseD_4e;
    }
    ((int (*)())_GetOrAddBlock)(param_1,uVar4);
    iVar5 = *(int *)(iVar7 + 8);
switchD_97c0ac70_caseD_4e:
    iVar7 = iVar5;
  }
  _memset(param_1[6],0,param_1[5] << 2);
  local_30[0] = 0;
  ((int (*)())_GetBlockFrom)(param_1,0,local_30);
  iVar5 = *param_1;
  iVar7 = **(int **)(iVar5 + 0x20);
  if (**(int **)(iVar5 + 0x20) != 0) {
    do {
      iVar5 = *(int *)(iVar7 + 8);
      uVar4 = *(uint *)(iVar7 + 0xc);
      if (iVar5 != 0) {
        uVar4 = *(uint *)(iVar5 + 0xc);
      }
      uVar4 = uVar4 & 0x3ffff;
      switch(*(uint *)(iVar7 + 0xc) >> 0x12 & 0xff) {
      case 0x4b:
      case 0x54:
      case 0x55:
      case 0x56:
      case 0x57:
      case 0x58:
      case 0x5a:
      case 0x5b:
      case 0x69:
      case 0x6a:
      case 0x6b:
        ((int (*)())_GetBlockFrom)(param_1,uVar4,local_30);
      case 0x4c:
        uVar4 = *(uint *)(iVar7 + 0x10) & 0x3ffff;
        break;
      case 0x4d:
      case 0x59:
        break;
      default:
        goto switchD_97c0adac_caseD_4e;
      }
      ((int (*)())_GetBlockFrom)(param_1,uVar4,local_30);
      iVar5 = *(int *)(iVar7 + 8);
switchD_97c0adac_caseD_4e:
      iVar7 = iVar5;
    } while (iVar5 != 0);
    iVar5 = *param_1;
  }
  iVar1 = ((int (*)())_GetBlock)(param_1,0);
  iVar7 = **(int **)(iVar5 + 0x20);
  do {
    if (iVar7 == 0) {
      return;
    }
    uVar4 = *(uint *)(iVar7 + 0xc) & 0x3ffff;
    uVar6 = uVar4;
    if (*(int *)(iVar7 + 8) != 0) {
      uVar6 = *(uint *)(*(int *)(iVar7 + 8) + 0xc) & 0x3ffff;
    }
    iVar2 = ((int (*)())_GetBlock)(param_1,uVar4);
    iVar5 = iVar1;
    if (iVar2 != 0) {
      iVar5 = iVar2;
    }
    ((int (*)())_InstructionAdd)(param_1,iVar5,iVar7);
    iVar1 = iVar5;
    switch(*(uint *)(iVar7 + 0xc) >> 0x12 & 0xff) {
    case 0x4b:
    case 0x54:
    case 0x58:
    case 0x69:
      iVar2 = ((int (*)())_GetBlock)(param_1,uVar6);
      iVar3 = ((int (*)())_GetBlock)(param_1,*(uint *)(iVar7 + 0x10) & 0x3ffff);
      goto LAB_97c0b02c;
    case 0x4c:
      break;
    case 0x4d:
      iVar1 = ((int (*)())_GetBlock)(param_1,uVar6);
      break;
    default:
      iVar3 = ((int (*)())_GetBlock)(param_1,uVar6);
      iVar2 = iVar3;
      if (iVar3 != 0) goto LAB_97c0b02c;
      break;
    case 0x55:
    case 0x56:
    case 0x57:
    case 0x5a:
    case 0x5b:
    case 0x6a:
    case 0x6b:
      iVar2 = ((int (*)())_GetBlock)(param_1,uVar6);
      iVar3 = ((int (*)())_GetBlock)(param_1,*(uint *)(iVar7 + 0x10) & 0x3ffff);
      ((int (*)())_BlockAddSuccessor)(iVar5,iVar2);
      goto LAB_97c0b02c;
    case 0x59:
      iVar3 = ((int (*)())_GetBlock)(param_1,uVar6);
      iVar2 = iVar3;
LAB_97c0b02c:
      iVar1 = iVar2;
      ((int (*)())_BlockAddSuccessor)(iVar5,iVar3);
    }
    iVar7 = *(int *)(iVar7 + 8);
  } while( true );
}

/* _BlockAddSuccessor @ 0x97c0b054 (144 bytes) */
int _BlockAddSuccessor(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    iVar1 = *(int *)(param_2 + 8) + 1;
    *(int *)(param_2 + 8) = iVar1;
    iVar1 = _realloc(*(undefined4 *)(param_2 + 0xc),iVar1 * 4);
    *(int *)(param_2 + 0xc) = iVar1;
    *(int *)(iVar1 + *(int *)(param_2 + 8) * 4 + -4) = param_1;
    iVar1 = *(int *)(param_1 + 0x10) + 1;
    *(int *)(param_1 + 0x10) = iVar1;
    iVar1 = _realloc(*(undefined4 *)(param_1 + 0x14),iVar1 * 4);
    *(int *)(param_1 + 0x14) = iVar1;
    *(int *)(iVar1 + *(int *)(param_1 + 0x10) * 4 + -4) = param_2;
  }
  return;
}

/* _BlockAddPredecessor @ 0x97c0b0e4 (16 bytes) */
int _BlockAddPredecessor(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_BlockAddSuccessor)(param_2,param_1);
  return;
}

/* _BlocksFree @ 0x97c0b0f4 (124 bytes) */
int _BlocksFree(param_1)
  int param_1;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = 0;
  if (*(int *)(param_1 + 4) != 0) {
    iVar3 = 0;
    do {
      uVar2 = uVar2 + 1;
      iVar1 = *(int *)(param_1 + 8) + iVar3;
      iVar3 = iVar3 + 0x2c;
      ((int (*)())_BlockFree)(iVar1);
    } while (uVar2 < *(uint *)(param_1 + 4));
  }
  if (*(int *)(param_1 + 8) != 0) {
    _free(*(int *)(param_1 + 8));
    return;
  }
  return;
}

/* _ProgramNew @ 0x97c0b170 (152 bytes) */
int _ProgramNew(param_1)
  undefined4 param_1;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)_malloc(0x44);
  *puVar1 = param_1;
  puVar1[1] = 0;
  uVar2 = _malloc(0x2c);
  puVar1[2] = uVar2;
  puVar1[3] = 0;
  uVar2 = _malloc(0x2c);
  puVar1[4] = uVar2;
  puVar1[5] = 0;
  uVar2 = _malloc(4);
  puVar1[6] = uVar2;
  puVar1[0x10] = 0;
  puVar1[7] = 0;
  puVar1[8] = 0;
  puVar1[9] = 0;
  puVar1[10] = 0;
  puVar1[0xb] = 0;
  puVar1[0xc] = 0;
  puVar1[0xd] = 0;
  puVar1[0xe] = 0;
  puVar1[0xf] = 0;
  return puVar1;
}

/* _ProgramFree @ 0x97c0b208 (76 bytes) */
int _ProgramFree(param_1)
  int param_1;
{
  if (*(int *)(param_1 + 0x18) != 0) {
    _free(*(int *)(param_1 + 0x18));
  }
  ((int (*)())_RegistersFree)(param_1);
  ((int (*)())_BlocksFree)(param_1);
  _free(param_1);
  return;
}

/* _FlattenIfs @ 0x97c0b254 (468 bytes) */
int _FlattenIfs(param_1)
  int param_1;
{
  int *piVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  iVar11 = **(int **)(param_1 + 0x20);
  do {
    while( true ) {
      if (iVar11 == 0) {
        return;
      }
      iVar10 = iVar11;
      if ((*(uint *)(iVar11 + 0xc) >> 0x12 & 0xff) == 0x55) break;
LAB_97c0b480:
      iVar11 = *(int *)(iVar10 + 8);
    }
    iVar7 = 0;
    bVar2 = true;
    uVar8 = *(uint *)(iVar11 + 0x10) & 0x3ffff;
    iVar4 = 0;
    iVar9 = iVar11;
    do {
      if (((*(uint *)(iVar9 + 0xc) & 0x3ffff) == uVar8) && (iVar4 != 0)) {
        uVar3 = *(uint *)(iVar4 + 0xc) >> 0x12 & 0xff;
        if (uVar3 == 0x58) {
          uVar8 = *(uint *)(iVar4 + 0x10) & 0x3ffff;
          iVar7 = iVar4;
        }
        else {
          iVar6 = iVar4;
          if (uVar3 == 0x59) break;
        }
      }
      switch(*(uint *)(iVar9 + 0xc) >> 0x12 & 0xff) {
      case 0x4b:
      case 0x54:
      case 0x69:
        if (uVar8 < (*(uint *)(iVar9 + 0x10) & 0x3ffff)) goto switchD_97c0b318_caseD_4c;
        break;
      case 0x4c:
      case 0x4d:
switchD_97c0b318_caseD_4c:
        bVar2 = false;
      }
      iVar4 = ((int (*)())_GetValidArgs)(iVar9);
      if (0 < iVar4) {
        puVar5 = (uint *)(iVar9 + 0x1c);
        do {
          uVar3 = *puVar5;
          puVar5 = puVar5 + 2;
          if ((int)uVar3 < 0) {
            bVar2 = false;
          }
          if (((uVar3 & 0x4000) != 0) && (1 < (uVar3 >> 0xc & 3) + 1)) {
            bVar2 = false;
          }
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
      uVar3 = *(uint *)(iVar9 + 0x14);
      if ((uVar3 & 0x1e000) != 0) {
        if (*(int *)(iVar9 + 0x18) < 0) {
          bVar2 = false;
        }
        if (((uVar3 & 0x1000) != 0) && (1 < (uVar3 >> 10 & 3) + 1)) {
          bVar2 = false;
        }
      }
      piVar1 = (int *)(iVar9 + 8);
      iVar4 = iVar9;
      iVar6 = 0;
      iVar9 = *piVar1;
    } while (*piVar1 != 0);
    if (!bVar2) goto LAB_97c0b480;
    iVar10 = *(int *)(iVar11 + 4);
    _FlattenIf(param_1,iVar11,iVar7,iVar6);
    if (iVar10 != 0) goto LAB_97c0b480;
    iVar11 = **(int **)(param_1 + 0x20);
  } while( true );
}

/* _regEqualsFunction @ 0x97c0b4ac (36 bytes) */
int _regEqualsFunction(param_1, param_2)
  int *param_1;
  int *param_2;
{
  if (param_1[1] - param_2[1] != 0) {
    return param_1[1] - param_2[1];
  }
  return *param_1 - *param_2;
}

/* _AddTempRegister @ 0x97c0b4d0 (128 bytes) */
int _AddTempRegister(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  uint param_3;
  uint param_4;
{
  undefined4 uVar1;
  uint local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  uVar1 = _PPStreamChunkListGetMaxIndex(*(undefined4 *)(param_1 + 4));
  local_30 = (param_4 & 3) << 0x18 | (param_3 & 7) << 0x1a | param_2 << 0x1d | local_30 & 0xffffff;
  local_2c = CONCAT22((*(unsigned short *)((unsigned char *)&(local_2c) + 0)),(short)uVar1 + 1);
  _PPStreamAddTempUsage(param_1,&local_30);
  return local_2c & 0xffff;
}

/* _AddConstantParam @ 0x97c0b550 (436 bytes) */
int _AddConstantParam(param_1, param_2, param_3, param_4, param_5_w, param_6_w, param_7_w, param_8_w)
  int param_1;
  uint param_2;
  uint param_3;
  uint param_4;
  unsigned int param_5_w;
  unsigned int param_6_w;
  unsigned int param_7_w;
  unsigned int param_8_w;
{
  float param_5 = GH_U2F(param_5_w);
  float param_6 = GH_U2F(param_6_w);
  float param_7 = GH_U2F(param_7_w);
  float param_8 = GH_U2F(param_8_w);
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  float fStack00000028;
  float fStack0000002c;
  float fStack00000030;
  float fStack00000034;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  longlong local_40;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  local_50 = param_5;
  local_4c = param_6;
  local_48 = param_7;
  local_44 = param_8;
  if (param_3 != 1) {
    local_50 = GH_U2F((unsigned int)((int)param_5));
    local_4c = GH_U2F((unsigned int)((int)param_6));
    local_48 = GH_U2F((unsigned int)((int)param_7));
    local_44 = GH_U2F((unsigned int)((int)param_8));
    local_40 = (longlong)(int)GH_F2U(local_44);
  }
  piVar4 = *(int **)(param_1 + 0x10);
  iVar5 = *piVar4;
  fStack00000028 = param_5;
  fStack0000002c = param_6;
  fStack00000030 = param_7;
  fStack00000034 = param_8;
  if (iVar5 != 0) {
    do {
      uVar3 = *(uint *)(iVar5 + 0xc);
      if (((((uVar3 >> 0x10 & 0x1f) == 0x11) && ((uVar3 >> 0x1a & 7) == param_3)) &&
          ((uVar3 >> 0x18 & 3) == param_4)) && (uVar3 >> 0x1d == param_2)) {
        iVar1 = _PPStreamChunkListChunkAtIndex(*(undefined4 *)(param_1 + 0x2c),uVar3 & 0xffff);
        iVar1 = _memcmp(&local_50,iVar1 + 0xc,0x10);
        if (iVar1 == 0) {
          return *(undefined2 *)(iVar5 + 0x12);
        }
      }
      iVar5 = *(int *)(iVar5 + 8);
    } while (iVar5 != 0);
    piVar4 = *(int **)(param_1 + 0x10);
  }
  local_2c = 0;
  local_30 = 0x110000;
  local_28 = 0;
  uVar2 = _PPStreamChunkListGetMaxIndex(piVar4);
  uVar3 = (uint)local_30 >> 0x10;
  local_2c = CONCAT22((*(unsigned short *)((unsigned char *)&(local_2c) + 0)),(short)uVar2 + 1);
  local_30 = CONCAT22((ushort)((param_2 << 0x1d) >> 0x10) |
                      (ushort)(((param_4 & 3) << 0x18) >> 0x10) |
                      (ushort)(((param_3 & 7) << 0x1a) >> 0x10) | (ushort)uVar3 & 0xff,
                      *(undefined2 *)(*(int *)(param_1 + 0x2c) + 10));
  _PPStreamAddConstant(param_1,&local_50);
  _PPStreamAddParamBinding(param_1,&local_30);
  return (*(unsigned short *)((unsigned char *)&(local_2c) + 2));
}

