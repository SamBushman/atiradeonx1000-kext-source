#include "decls.h"

/* _PPCRuntimeCompilerGetBaseIndexInRegister @ 0x97bda06c (16 bytes) */
int _PPCRuntimeCompilerGetBaseIndexInRegister(param_1, param_2)
  int param_1;
  int param_2;
{
  return *(undefined2 *)(param_2 * 0x38 + param_1 + 0x18);
}

/* _PPCRuntimeCompilerGetOffsetInRegister @ 0x97bda07c (88 bytes) */
int _PPCRuntimeCompilerGetOffsetInRegister(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int local_40 [2];
  byte abStack_38 [40];
  
  iVar1 = param_2 * 0x38 + param_1;
  _memcpy(local_40,iVar1 + 8,0x24);
  return *(undefined4 *)(local_40[0] + (uint)abStack_38[*(int *)(iVar1 + 4)] * 4);
}

/* _PPCRuntimeCompilerBuildTransferSwizzle @ 0x97bda0d4 (104 bytes) */
int _PPCRuntimeCompilerBuildTransferSwizzle(param_1, param_2, param_3)
  undefined1 *param_1;
  int param_2;
  char *param_3;
{
  char cVar1;
  uint uVar2;
  undefined1 *puVar3;
  
  *param_1 = 0;
  param_1[1] = 1;
  param_1[2] = 2;
  param_1[3] = 3;
  puVar3 = param_1 + 3;
  do {
    cVar1 = *param_3;
    uVar2 = 0;
    param_3 = param_3 + 1;
    do {
      if (*(char *)(param_2 + uVar2) == cVar1) {
        *param_1 = (char)uVar2;
        break;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < 4);
    param_1 = param_1 + 1;
    if (puVar3 < param_1) {
      return;
    }
  } while( true );
}

/* _PPCRuntimeCompilerSwizzleRegisterAV @ 0x97bda13c (2444 bytes) */
int _PPCRuntimeCompilerSwizzleRegisterAV(param_1, param_2, param_3)
  int param_1;
  int param_2;
  uint *param_3;
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  uint *puVar12;
  
  uVar2 = *param_3;
  iVar4 = 1;
  iVar5 = 1;
  uVar3 = (uVar2 & 0x3000000) << 4 | (uVar2 & 0x30000) << 8 | (uVar2 & 0x300) << 0xc |
          (uVar2 & 3) << 0x10;
  uVar6 = 0;
  uVar3 = uVar3 | uVar3 >> 0x10;
  do {
    if (((uVar3 >> (uVar6 * -4 + 0x1c & 0x3f)) + 1 & 3) == (uVar3 >> (uVar6 * -4 + 0x18 & 0x3f) & 3)
       ) {
      iVar1 = uVar6 * 4 + 8;
      iVar4 = 2;
      uVar10 = 0x20 - iVar1;
      uVar7 = 0x1c - iVar1;
      goto LAB_97bda1ac;
    }
    uVar6 = uVar6 + 1;
  } while ((int)uVar6 < 4);
  goto LAB_97bda240;
  while( true ) {
    iVar5 = iVar5 + 1;
    uVar11 = uVar11 - 4;
    uVar10 = uVar10 - 4;
    if (3 < iVar5) break;
LAB_97bda278:
    if ((uVar3 >> (uVar11 & 0x3f) & 3) != (uVar3 >> (uVar10 & 0x3f) & 3)) break;
  }
  if ((uVar7 == 0) && (iVar5 < 4)) {
    uVar11 = 0x10;
    uVar10 = 0xc;
    do {
      if ((uVar3 >> (uVar11 & 0x3f) & 3) != (uVar3 >> (uVar10 & 0x3f) & 3)) break;
      iVar5 = iVar5 + 1;
      uVar7 = uVar7 - 1 & 3;
      uVar11 = uVar11 + 4;
      uVar10 = uVar10 + 4;
    } while (iVar5 < 4);
  }
  goto LAB_97bda304;
  while( true ) {
    iVar4 = iVar4 + 1;
    uVar10 = uVar10 - 4;
    uVar7 = uVar7 - 4;
    if (3 < iVar4) break;
LAB_97bda1ac:
    if (((uVar3 >> (uVar10 & 0x3f)) + 1 & 3) != (uVar3 >> (uVar7 & 0x3f) & 3)) break;
  }
  if ((uVar6 == 0) && (iVar4 < 4)) {
    uVar10 = 0x10;
    uVar7 = 0xc;
    do {
      if (((uVar3 >> (uVar10 & 0x3f)) + 1 & 3) != (uVar3 >> (uVar7 & 0x3f) & 3)) break;
      iVar4 = iVar4 + 1;
      uVar6 = uVar6 - 1 & 3;
      uVar10 = uVar10 + 4;
      uVar7 = uVar7 + 4;
    } while (iVar4 < 4);
  }
LAB_97bda240:
  uVar7 = 0;
  do {
    if ((uVar3 >> (uVar7 * -4 + 0x1c & 0x3f) & 3) == (uVar3 >> (uVar7 * -4 + 0x18 & 0x3f) & 3)) {
      iVar1 = uVar7 * 4 + 8;
      iVar5 = 2;
      uVar11 = 0x20 - iVar1;
      uVar10 = 0x1c - iVar1;
      goto LAB_97bda278;
    }
    uVar7 = uVar7 + 1;
  } while ((int)uVar7 < 4);
LAB_97bda304:
  if (iVar5 == 4) {
    puVar8 = *(uint **)(param_1 + 0xe30);
    *puVar8 = param_2 << 0x15 | (uVar3 >> (uVar7 * -4 + 0x1c & 0x3f) & 0xf) << 0x10 | param_2 << 0xb
              | 0x1000028c;
    *(uint **)(param_1 + 0xe30) = puVar8 + 1;
    return;
  }
  if (iVar4 == 4) {
    uVar6 = (uVar2 & 0x3000000) >> 0x18;
    if (uVar6 == 0) {
      return;
    }
    uVar2 = param_2 << 0x15 | param_2 << 0x10 | param_2 << 0xb;
    uVar6 = uVar6 << 8;
LAB_97bda710:
    puVar8 = *(uint **)(param_1 + 0xe30);
    uVar6 = uVar2 | uVar6 & 0x300 | 0x1000002c;
LAB_97bdaabc:
    *puVar8 = uVar6;
  }
  else {
    if (iVar5 == 3) {
      uVar2 = param_2 << 0xb;
      uVar6 = uVar3 >> (uVar7 * -4 + 0x10 & 0x3f);
      puVar8 = *(uint **)(param_1 + 0xe30);
      *puVar8 = (uVar3 >> (uVar7 * -4 + 0x1c & 0x3f) & 0xf) << 0x10 | 0x600000 | uVar2 | 0x1000028c;
      *(uint **)(param_1 + 0xe30) = puVar8 + 1;
      iVar4 = param_2;
      if ((uVar6 & 0xf) != 0) {
        iVar4 = 4;
        puVar8[1] = param_2 << 0x10 | 0x800000U | uVar2 | (uVar6 & 3) << 8 | 0x1000002c;
        *(uint **)(param_1 + 0xe30) = puVar8 + 2;
      }
      puVar8 = *(uint **)(param_1 + 0xe30);
      *puVar8 = param_2 << 0x15 | 0x30000U | iVar4 << 0xb | 0x1000012c;
      puVar8 = puVar8 + 1;
      *(uint **)(param_1 + 0xe30) = puVar8;
      if (uVar7 == 0) {
        return;
      }
      uVar2 = param_2 << 0x15 | param_2 << 0x10 | uVar2;
      uVar6 = uVar7;
    }
    else {
      if (iVar4 != 3) {
        if (iVar5 == 2) {
          uVar2 = param_2 << 0xb;
          uVar11 = uVar3 >> (uVar7 * -4 + 0x14 & 0x3f);
          uVar6 = uVar11 & 0xf;
          uVar10 = uVar3 >> (uVar7 * -4 + 0x10 & 0x3f) & 0xf;
          puVar8 = *(uint **)(param_1 + 0xe30);
          *puVar8 = (uVar3 >> (uVar7 * -4 + 0x1c & 0x3f) & 0xf) << 0x10 | 0x600000 | uVar2 |
                    0x1000028c;
          puVar12 = puVar8 + 1;
          *(uint **)(param_1 + 0xe30) = puVar12;
          if (uVar10 == (uVar6 + 1 & 3)) {
            iVar4 = param_2;
            if (uVar6 != 0) {
              iVar4 = 4;
              *puVar12 = param_2 << 0x10 | 0x800000U | uVar2 | (uVar11 & 3) << 8 | 0x1000002c;
              *(uint **)(param_1 + 0xe30) = puVar8 + 2;
            }
            puVar9 = *(uint **)(param_1 + 0xe30);
            uVar6 = param_2 << 0x15 | 0x30000U | iVar4 << 0xb | 0x1000022c;
LAB_97bda6e8:
            *puVar9 = uVar6;
            puVar9 = puVar9 + 1;
          }
          else {
            if (uVar10 != uVar6) {
              iVar4 = param_2;
              if (uVar6 != 0) {
                iVar4 = 4;
                *puVar12 = param_2 << 0x10 | 0x800000U | uVar2 | (uVar11 & 3) << 8 | 0x1000002c;
                *(uint **)(param_1 + 0xe30) = puVar8 + 2;
              }
              uVar3 = uVar3 >> (uVar7 * -4 + 0x10 & 0x3f);
              puVar8 = *(uint **)(param_1 + 0xe30);
              *puVar8 = iVar4 << 0xb | 0x1063012c;
              *(uint **)(param_1 + 0xe30) = puVar8 + 1;
              iVar4 = param_2;
              if ((uVar3 & 0xf) != 0) {
                iVar4 = 4;
                puVar8[1] = param_2 << 0x10 | 0x800000U | uVar2 | (uVar3 & 3) << 8 | 0x1000002c;
                *(uint **)(param_1 + 0xe30) = puVar8 + 2;
              }
              puVar9 = *(uint **)(param_1 + 0xe30);
              uVar6 = param_2 << 0x15 | 0x30000U | iVar4 << 0xb | 0x1000012c;
              goto LAB_97bda6e8;
            }
            puVar9 = puVar8 + 3;
            puVar8[2] = param_2 << 0x15 | 0x1003222c;
            *puVar12 = uVar6 << 0x10 | 0x800000 | uVar2 | 0x1000028c;
          }
          *(uint **)(param_1 + 0xe30) = puVar9;
          if (uVar7 == 0) {
            return;
          }
          uVar2 = param_2 << 0x15 | param_2 << 0x10 | uVar2;
          uVar6 = uVar7;
LAB_97bda70c:
          uVar6 = (4 - uVar6) * 0x100;
          goto LAB_97bda710;
        }
        if (iVar4 == 2) {
          uVar2 = uVar3 >> (uVar6 * -4 + 0x1c & 0x3f) & 0xf;
          iVar4 = param_2;
          if (uVar2 != 2) {
            puVar8 = *(uint **)(param_1 + 0xe30);
            iVar4 = 3;
            *puVar8 = param_2 << 0x10 | 0x600000U | param_2 << 0xb | (uVar2 * 4 + 8) * 0x40 & 0x300
                      | 0x1000002c;
            *(uint **)(param_1 + 0xe30) = puVar8 + 1;
          }
          uVar10 = uVar3 >> (uVar6 * -4 + 0x14 & 0x3f);
          uVar2 = uVar10 & 0xf;
          uVar7 = uVar3 >> (uVar6 * -4 + 0x10 & 0x3f) & 0xf;
          if (uVar7 == (uVar2 + 1 & 3)) {
            iVar5 = param_2;
            if (uVar2 != 0) {
              puVar8 = *(uint **)(param_1 + 0xe30);
              iVar5 = 4;
              *puVar8 = param_2 << 0x10 | 0x800000U | param_2 << 0xb | (uVar10 & 3) << 8 |
                        0x1000002c;
              *(uint **)(param_1 + 0xe30) = puVar8 + 1;
            }
            puVar8 = *(uint **)(param_1 + 0xe30);
            *puVar8 = param_2 << 0x15 | iVar4 << 0x10 | iVar5 << 0xb | 0x1000022c;
LAB_97bda854:
            *(uint **)(param_1 + 0xe30) = puVar8 + 1;
          }
          else {
            if (uVar7 == uVar2) {
              puVar8 = *(uint **)(param_1 + 0xe30);
              *puVar8 = uVar2 << 0x10 | 0x800000 | param_2 << 0xb | 0x1000028c;
              puVar8 = puVar8 + 1;
              *puVar8 = param_2 << 0x15 | iVar4 << 0x10 | 0x1000222c;
              goto LAB_97bda854;
            }
            iVar5 = param_2;
            if (uVar2 != 0) {
              puVar8 = *(uint **)(param_1 + 0xe30);
              iVar5 = 4;
              *puVar8 = param_2 << 0x10 | 0x800000U | param_2 << 0xb | (uVar10 & 3) << 8 |
                        0x1000002c;
              *(uint **)(param_1 + 0xe30) = puVar8 + 1;
            }
            uVar3 = uVar3 >> (uVar6 * -4 + 0x10 & 0x3f);
            puVar8 = *(uint **)(param_1 + 0xe30);
            *puVar8 = iVar4 << 0x10 | iVar5 << 0xb | 0x1060012c;
            *(uint **)(param_1 + 0xe30) = puVar8 + 1;
            iVar4 = param_2;
            if ((uVar3 & 0xf) != 0) {
              iVar4 = 4;
              puVar8[1] = param_2 << 0x10 | 0x800000U | param_2 << 0xb | (uVar3 & 3) << 8 |
                          0x1000002c;
              *(uint **)(param_1 + 0xe30) = puVar8 + 2;
            }
            puVar8 = *(uint **)(param_1 + 0xe30);
            *puVar8 = param_2 << 0x15 | 0x30000U | iVar4 << 0xb | 0x1000012c;
            *(uint **)(param_1 + 0xe30) = puVar8 + 1;
          }
          if (uVar6 == 0) {
            return;
          }
          uVar2 = param_2 << 0x15 | param_2 << 0x10 | param_2 << 0xb;
          goto LAB_97bda70c;
        }
        uVar6 = (uVar2 & 0x3000000) >> 0x18;
        iVar4 = param_2;
        if (uVar6 != 3) {
          puVar8 = *(uint **)(param_1 + 0xe30);
          iVar4 = 3;
          *puVar8 = param_2 << 0x10 | 0x600000U | param_2 << 0xb | (uVar6 * 4 + 4) * 0x40 & 0x300 |
                    0x1000002c;
          *(uint **)(param_1 + 0xe30) = puVar8 + 1;
        }
        iVar5 = param_2;
        if ((uVar2 & 0x30000) != 0) {
          puVar8 = *(uint **)(param_1 + 0xe30);
          iVar5 = 4;
          *puVar8 = param_2 << 0x10 | 0x800000U | param_2 << 0xb | ((uVar2 & 0x30000) >> 0x10) << 8
                    | 0x1000002c;
          *(uint **)(param_1 + 0xe30) = puVar8 + 1;
        }
        puVar8 = *(uint **)(param_1 + 0xe30);
        *puVar8 = iVar4 << 0x10 | iVar5 << 0xb | 0x1060012c;
        *(uint **)(param_1 + 0xe30) = puVar8 + 1;
        iVar4 = param_2;
        if ((uVar2 & 0x300) != 0) {
          iVar4 = 4;
          puVar8[1] = param_2 << 0x10 | 0x800000U | param_2 << 0xb | uVar2 & 0x300 | 0x1000002c;
          *(uint **)(param_1 + 0xe30) = puVar8 + 2;
        }
        puVar8 = *(uint **)(param_1 + 0xe30);
        *puVar8 = iVar4 << 0xb | 0x1063012c;
        *(uint **)(param_1 + 0xe30) = puVar8 + 1;
        iVar4 = param_2;
        if ((uVar2 & 3) != 0) {
          iVar4 = 4;
          puVar8[1] = param_2 << 0x10 | 0x800000U | param_2 << 0xb | (uVar2 & 3) << 8 | 0x1000002c;
          *(uint **)(param_1 + 0xe30) = puVar8 + 2;
        }
        puVar8 = *(uint **)(param_1 + 0xe30);
        uVar6 = param_2 << 0x15 | 0x30000U | iVar4 << 0xb | 0x1000012c;
        goto LAB_97bdaabc;
      }
      uVar2 = uVar3 >> (uVar6 * -4 + 0x1c & 0x3f) & 0xf;
      iVar4 = param_2;
      if (uVar2 != 1) {
        puVar8 = *(uint **)(param_1 + 0xe30);
        iVar4 = 3;
        *puVar8 = param_2 << 0x10 | 0x600000U | param_2 << 0xb | (uVar2 * 4 + 0xc) * 0x40 & 0x300 |
                  0x1000002c;
        *(uint **)(param_1 + 0xe30) = puVar8 + 1;
      }
      uVar3 = uVar3 >> (uVar6 * -4 + 0x10 & 0x3f);
      iVar5 = param_2;
      if ((uVar3 & 0xf) != 0) {
        puVar8 = *(uint **)(param_1 + 0xe30);
        iVar5 = 4;
        *puVar8 = param_2 << 0x10 | 0x800000U | param_2 << 0xb | (uVar3 & 3) << 8 | 0x1000002c;
        *(uint **)(param_1 + 0xe30) = puVar8 + 1;
      }
      puVar8 = *(uint **)(param_1 + 0xe30);
      *puVar8 = param_2 << 0x15 | iVar4 << 0x10 | iVar5 << 0xb | 0x1000012c;
      puVar8 = puVar8 + 1;
      *(uint **)(param_1 + 0xe30) = puVar8;
      if (uVar6 == 0) {
        return;
      }
      uVar2 = param_2 << 0x15 | param_2 << 0x10 | param_2 << 0xb;
    }
    *puVar8 = uVar2 | (4 - uVar6) * 0x100 & 0x300 | 0x1000002c;
  }
  *(uint **)(param_1 + 0xe30) = puVar8 + 1;
  return;
}

/* _PPCRuntimeCompilerFindVariableInfo @ 0x97bdaac8 (88 bytes) */
int _PPCRuntimeCompilerFindVariableInfo(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  int *piVar1;
  uint uVar2;
  
  uVar2 = 0;
  piVar1 = *(int **)(param_1 + 0xe00);
  if (*(uint *)(param_1 + 0xe04) != 0) {
    do {
      if (param_2 == *piVar1) {
        return piVar1;
      }
      uVar2 = uVar2 + 1;
      piVar1 = piVar1 + 2;
    } while (uVar2 < *(uint *)(param_1 + 0xe04));
  }
  return (int *)0x0;
}

/* _PPCRuntimeCompilerLoadSourceNO @ 0x97bdab20 (348 bytes) */
int _PPCRuntimeCompilerLoadSourceNO(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
  undefined4 param_10;
  undefined4 param_11;
  int param_12;
{
  int iVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uStack0000001c;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  
  iVar1 = param_12 * 4;
  uStack0000001c = param_2;
  uStack00000020 = param_3;
  uStack00000024 = param_4;
  uStack00000028 = param_5;
  uStack0000002c = param_6;
  uStack00000030 = param_7;
  uStack00000034 = param_8;
  if ((*(uint *)(param_1 + 0xe50) & 4) != 0) {
    uVar5 = 0;
    do {
      iVar4 = iVar1 + uVar5;
      _PPCRuntimeCompilerBackupRegister(param_1,iVar4);
      uVar5 = uVar5 + 1;
      _PPCRuntimeCompilerDirtyRegister(param_1,iVar4);
    } while (uVar5 < 4);
  }
  uVar5 = 0;
  do {
    uVar6 = uVar5 + 1;
    _PPCRuntimeCompilerLoadRegister
              (param_1,iVar1 + uVar5,uStack0000001c,uStack00000020,uStack00000024,uStack00000028,
               uStack0000002c,uStack00000030,uStack00000034,param_9,param_10,uVar5);
    uVar5 = uVar6;
  } while (uVar6 < 4);
  if ((*(unsigned char *)((unsigned char *)&(uStack0000002c) + 2)) == '\0') {
    return;
  }
  if (param_12 == 0) {
    uVar3 = *(undefined4 *)(param_1 + 0xe30);
    puVar2 = &_glpNegateSourceARTC;
  }
  else if (param_12 == 1) {
    uVar3 = *(undefined4 *)(param_1 + 0xe30);
    puVar2 = &_glpNegateSourceBRTC;
  }
  else {
    if (param_12 != 2) goto LAB_97bdac4c;
    uVar3 = *(undefined4 *)(param_1 + 0xe30);
    puVar2 = &_glpNegateSourceCRTC;
  }
  iVar4 = _glpRTCAddAChunk_97bd7cbc(puVar2,uVar3);
  *(int *)(param_1 + 0xe30) = *(int *)(param_1 + 0xe30) + iVar4 * 4;
LAB_97bdac4c:
  uVar5 = 0;
  do {
    iVar4 = iVar1 + uVar5;
    uVar5 = uVar5 + 1;
    _PPCRuntimeCompilerDirtyRegister(param_1,iVar4);
  } while (uVar5 < 4);
  return;
}

/* _PPCRuntimeCompilerLoadSourceAV @ 0x97bdac7c (268 bytes) */
int _PPCRuntimeCompilerLoadSourceAV(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
  undefined4 param_10;
  int param_11;
  int param_12;
{
  uint *puVar1;
  int iStack0000001c;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  
  iStack0000001c = param_2;
  uStack00000020 = param_3;
  uStack00000024 = param_4;
  uStack00000028 = param_5;
  uStack0000002c = param_6;
  uStack00000030 = param_7;
  uStack00000034 = param_8;
  if ((*(uint *)(param_1 + 0xe50) & 4) != 0) {
    _PPCRuntimeCompilerBackupRegister(param_1,param_12);
    _PPCRuntimeCompilerDirtyRegister(param_1,param_12);
  }
  iStack0000001c = iStack0000001c + param_11 * 0x10;
  _PPCRuntimeCompilerLoadRegister
            (param_1,param_12,iStack0000001c,uStack00000020,uStack00000024,uStack00000028,
             uStack0000002c,uStack00000030,uStack00000034,param_9,param_10,0);
  if ((*(unsigned char *)((unsigned char *)&(uStack0000002c) + 2)) != '\0') {
    puVar1 = *(uint **)(param_1 + 0xe30);
    *puVar1 = param_12 << 0x15 | param_12 << 0x10 | 0x10003cc4;
    *(uint **)(param_1 + 0xe30) = puVar1 + 1;
    _PPCRuntimeCompilerDirtyRegister(param_1,param_12);
    return;
  }
  return;
}

/* _PPCRuntimeCompilerWriteDestinationNO @ 0x97bdad88 (368 bytes) */
int _PPCRuntimeCompilerWriteDestinationNO(param_1, param_2)
  int param_1;
  int param_2;
{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  int local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  
  _memcpy(&local_50,*(int *)(param_1 + 0xe28) + 0xc,0x24);
  uVar2 = 0x2000000;
  _PPCRuntimeCompilerDirtyRegister(param_1,0x10);
  _PPCRuntimeCompilerDirtyRegister(param_1,0x11);
  _PPCRuntimeCompilerDirtyRegister(param_1,0x12);
  _PPCRuntimeCompilerDirtyRegister(param_1,0x13);
  uVar3 = 0;
  do {
    if (((*(unsigned char *)((unsigned char *)&(local_34) + 0)) >> (uVar3 & 0x3f) & 1) != 0) {
      if (((*(unsigned short *)((unsigned char *)&(local_40) + 0)) == 1) || ((*(uint *)(param_1 + 0xe50) & 4) == 0)) {
        puVar1 = *(uint **)(param_1 + 0xe30);
        *puVar1 = uVar2 | (uint)(ushort)((*(unsigned short *)((unsigned char *)&(local_40) + 0)) + 5) << 0x10 |
                  *(uint *)(uVar3 * 4 + local_50 + param_2 * 0x10) & 0xffff | 0xd0000000;
        *(uint **)(param_1 + 0xe30) = puVar1 + 1;
      }
      else {
        _PPCRuntimeCompilerDirtyRegistersWithData
                  (param_1,local_50,local_4c,local_48,local_44,local_40,local_3c,local_38,local_34,
                   local_30,uVar3);
        _PPCRuntimeCompilerSetRegister
                  (param_1,uVar3 + 0x10,local_50,local_4c,local_48,local_44,local_40,local_3c,
                   local_38,local_34,local_30,0,uVar3);
      }
    }
    uVar3 = uVar3 + 1;
    uVar2 = uVar2 + 0x200000;
  } while (uVar3 < 4);
  return;
}

/* _PPCRuntimeCompilerWriteDestinationAV @ 0x97bdaef8 (748 bytes) */
int _PPCRuntimeCompilerWriteDestinationAV(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 uVar1;
  undefined4 extraout_r4;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 in_r9;
  undefined4 *puVar2;
  undefined4 in_r10;
  int iVar3;
  int iVar4;
  int local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  uint local_34;
  undefined4 local_30;
  
  iVar4 = *(int *)(param_1 + 0xe28);
  _memcpy(&local_50,iVar4 + 0xc,0x24);
  local_50 = local_50 + param_2 * 0x10;
  _PPCRuntimeCompilerDirtyRegister(param_1,2);
  puVar2 = &local_48;
  ((int (*)())_PPCRuntimeCompilerSwizzleRegisterAV)(param_1,2,puVar2);
  _PPEmulatorVariableSwizzleFromMask(&local_50,extraout_r4,puVar2,in_r6,in_r7,in_r8,in_r9,in_r10);
  if (*(char *)(iVar4 + 6) != '\0') {
    iVar4 = _glpRTCAddAChunk_97bd7cbc
                      (&_glpOpBuildConditionCodeAVRTC,*(undefined4 *)(param_1 + 0xe30));
    iVar3 = *(int *)(param_1 + 0xe30);
    iVar4 = iVar4 * 4;
    puVar2 = (undefined4 *)(iVar3 + iVar4);
    *(undefined4 **)(param_1 + 0xe30) = puVar2;
    if ((*(unsigned char *)((unsigned char *)&(local_34) + 0)) == '\x0f') {
      *(undefined4 *)(iVar3 + iVar4) = 0x12852c84;
    }
    else {
      *(undefined4 *)(iVar3 + iVar4) = 0x10836a8c;
      *(undefined4 **)(param_1 + 0xe30) = puVar2 + 2;
      uVar1 = 0x1063212c;
      if ((local_34 & 0x1000000) == 0) {
        uVar1 = 0x1063492c;
      }
      puVar2[1] = uVar1;
      puVar2 = *(undefined4 **)(param_1 + 0xe30);
      uVar1 = 0x1063212c;
      *(undefined4 **)(param_1 + 0xe30) = puVar2 + 1;
      if ((local_34 & 0x2000000) == 0) {
        uVar1 = 0x1063492c;
      }
      *puVar2 = uVar1;
      puVar2 = *(undefined4 **)(param_1 + 0xe30);
      uVar1 = 0x1063212c;
      *(undefined4 **)(param_1 + 0xe30) = puVar2 + 1;
      if ((local_34 & 0x4000000) == 0) {
        uVar1 = 0x1063492c;
      }
      *puVar2 = uVar1;
      puVar2 = *(undefined4 **)(param_1 + 0xe30);
      uVar1 = 0x1063212c;
      *(undefined4 **)(param_1 + 0xe30) = puVar2 + 1;
      if ((local_34 & 0x8000000) == 0) {
        uVar1 = 0x1063492c;
      }
      *puVar2 = uVar1;
      puVar2 = *(undefined4 **)(param_1 + 0xe30);
      *puVar2 = 0x129428ea;
    }
    *(undefined4 **)(param_1 + 0xe30) = puVar2 + 1;
  }
  if ((char)local_40 != '\0') {
    _PPCRuntimeCompilerSaveAllTemporariesToMemory(param_1);
  }
  if (((((*(unsigned short *)((unsigned char *)&(local_40) + 0)) == 1) || ((*(unsigned short *)((unsigned char *)&(local_40) + 0)) == 9)) || ((*(uint *)(param_1 + 0xe50) & 4) == 0))
     || ((local_40 & 0xff) != 0)) {
    _PPCRuntimeCompilerSetRegister
              (param_1,2,local_50,local_4c,local_48,local_44,local_40,local_3c,local_38,local_34,
               local_30,0,0);
    _PPCRuntimeCompilerSaveRegisterToMemory(param_1,2);
    _PPCRuntimeCompilerDirtyRegistersWithData
              (param_1,local_50,local_4c,local_48,local_44,local_40,local_3c,local_38,local_34,
               local_30,0);
  }
  else {
    _PPCRuntimeCompilerDirtyRegistersWithData
              (param_1,local_50,local_4c,local_48,local_44,local_40,local_3c,local_38,local_34,
               local_30,0);
    _PPCRuntimeCompilerSetRegister
              (param_1,2,local_50,local_4c,local_48,local_44,local_40,local_3c,local_38,local_34,
               local_30,0,0);
  }
  return;
}

/* _PPCRuntimeCompilerTestConditionRegisterAV @ 0x97bdb1e4 (576 bytes) */
int _PPCRuntimeCompilerTestConditionRegisterAV(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  uint param_9;
{
  uint uVar1;
  undefined4 *puVar2;
  uint *puVar3;
  undefined4 uStack0000001c;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  
  uStack0000001c = param_2;
  uStack00000020 = param_3;
  uStack00000024 = param_4;
  uStack00000028 = param_5;
  uStack0000002c = param_6;
  uStack00000030 = param_7;
  uStack00000034 = param_8;
  switch(param_9 >> 0x10 & 0xff) {
  case 0:
    puVar3 = *(uint **)(param_1 + 0xe30);
    uVar1 = 0x10636a8c;
    goto LAB_97bdb424;
  case 1:
    puVar2 = *(undefined4 **)(param_1 + 0xe30);
    *puVar2 = 0x10b4a484;
    *(undefined4 **)(param_1 + 0xe30) = puVar2 + 1;
    ((int (*)())_PPCRuntimeCompilerSwizzleRegisterAV)(param_1,5,(int)&param_9 + 2);
    puVar3 = *(uint **)(param_1 + 0xe30);
    uVar1 = 0x10600000;
    break;
  case 2:
    puVar2 = *(undefined4 **)(param_1 + 0xe30);
    *puVar2 = 0x10b4a484;
    *(undefined4 **)(param_1 + 0xe30) = puVar2 + 1;
    ((int (*)())_PPCRuntimeCompilerSwizzleRegisterAV)(param_1,5,(int)&param_9 + 2);
    puVar2 = *(undefined4 **)(param_1 + 0xe30);
    uVar1 = 0x10810000;
    goto LAB_97bdb338;
  case 3:
    puVar2 = *(undefined4 **)(param_1 + 0xe30);
    *puVar2 = 0x10b4a484;
    *(undefined4 **)(param_1 + 0xe30) = puVar2 + 1;
    ((int (*)())_PPCRuntimeCompilerSwizzleRegisterAV)(param_1,5,(int)&param_9 + 2);
    puVar3 = *(uint **)(param_1 + 0xe30);
    uVar1 = 0x10610000;
    break;
  case 4:
    puVar2 = *(undefined4 **)(param_1 + 0xe30);
    *puVar2 = 0x10b4a484;
    *(undefined4 **)(param_1 + 0xe30) = puVar2 + 1;
    ((int (*)())_PPCRuntimeCompilerSwizzleRegisterAV)(param_1,5,(int)&param_9 + 2);
    puVar2 = *(undefined4 **)(param_1 + 0xe30);
    uVar1 = 0x10820000;
LAB_97bdb338:
    *puVar2 = 0x1060038c;
    puVar2[1] = uVar1 | 0x38c;
    puVar2[2] = 0x10651886;
    puVar2[3] = 0x10852086;
    puVar2[4] = 0x10632484;
    *(undefined4 **)(param_1 + 0xe30) = puVar2 + 5;
    return;
  case 5:
    puVar2 = *(undefined4 **)(param_1 + 0xe30);
    *puVar2 = 0x10b4a484;
    *(undefined4 **)(param_1 + 0xe30) = puVar2 + 1;
    ((int (*)())_PPCRuntimeCompilerSwizzleRegisterAV)(param_1,5,(int)&param_9 + 2);
    puVar3 = *(uint **)(param_1 + 0xe30);
    uVar1 = 0x10620000;
    break;
  case 6:
    puVar2 = *(undefined4 **)(param_1 + 0xe30);
    *puVar2 = 0x10b4a484;
    *(undefined4 **)(param_1 + 0xe30) = puVar2 + 1;
    ((int (*)())_PPCRuntimeCompilerSwizzleRegisterAV)(param_1,5,(int)&param_9 + 2);
    puVar2 = *(undefined4 **)(param_1 + 0xe30);
    *puVar2 = 0x1060038c;
    puVar2[1] = 0x10651886;
    puVar3 = puVar2 + 3;
    puVar2[2] = 0x10631d04;
    goto LAB_97bdb42c;
  case 7:
    puVar3 = *(uint **)(param_1 + 0xe30);
    uVar1 = 0x10694c84;
LAB_97bdb424:
    *puVar3 = uVar1;
    goto LAB_97bdb428;
  default:
    goto switchD_97bdb240_default;
  }
  *puVar3 = uVar1 | 0x38c;
  puVar3 = puVar3 + 1;
  *puVar3 = 0x10651886;
LAB_97bdb428:
  puVar3 = puVar3 + 1;
LAB_97bdb42c:
  *(uint **)(param_1 + 0xe30) = puVar3;
switchD_97bdb240_default:
  return;
}

/* _PPCRuntimeCompilerWriteFinalFragmentToBuffer @ 0x97bdb444 (568 bytes) */
int _PPCRuntimeCompilerWriteFinalFragmentToBuffer(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  bool bVar1;
  bool bVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  
  iVar6 = *(int *)(param_1 + 0xe20);
  bVar1 = false;
  if (((*(uint *)(*(int *)(iVar6 + 0xd80) + 0x3c) & 0x40) != 0) &&
     ((*(uint *)(*(int *)(iVar6 + 0xd80) + 0x70) & 0x1e0000) != 0x1e0000)) {
    bVar1 = true;
  }
  bVar2 = false;
  if (((*(uint *)(*(int *)(iVar6 + 0xd80) + 0x3c) & 0x20) != 0) &&
     (3 < (*(uint *)(*(int *)(iVar6 + 0xd80) + 0x68) & 0xf))) {
    bVar2 = true;
  }
  if ((*(uint *)(*(int *)(iVar6 + 0xd80) + 0x3c) & 1) != 0) {
    uVar3 = ((int (*)())_PPCRasterOpMachine_AlphaTestRTCAV)(param_1 + 0xe14,*(undefined4 *)(param_1 + 0xe30));
    iVar6 = *(int *)(param_1 + 0xe20);
    *(undefined4 *)(param_1 + 0xe30) = uVar3;
  }
  if ((*(uint *)(*(int *)(iVar6 + 0xd80) + 0x3c) & 6) != 0) {
    uVar3 = ((int (*)())_PPCRasterOpMachine_DepthAndStencilTestRTCAV)(param_1 + 0xe14,*(undefined4 *)(param_1 + 0xe30));
    iVar6 = *(int *)(param_1 + 0xe20);
    *(undefined4 *)(param_1 + 0xe30) = uVar3;
  }
  if ((((*(uint *)(*(int *)(iVar6 + 0xd80) + 0x3c) & 8) != 0) || (bVar2)) || (bVar1)) {
    uVar4 = _PPEmulatorFramebufferFormat(iVar6);
    if ((uVar4 & 0x8000) == 0) {
      uVar4 = _PPEmulatorFramebufferFormat(*(undefined4 *)(param_1 + 0xe20));
      if ((uVar4 & 0x8000000) != 0) {
        puVar5 = *(undefined4 **)(param_1 + 0xe30);
        *puVar5 = 0x7c4030ce;
        *(undefined4 **)(param_1 + 0xe30) = puVar5 + 1;
      }
    }
    else {
      iVar6 = _glpRTCAddAChunk_97bd7cbc
                        (&_glpOpConvertARGB8888ToRGBAFFFF,*(undefined4 *)(param_1 + 0xe30));
      *(int *)(param_1 + 0xe30) = *(int *)(param_1 + 0xe30) + iVar6 * 4;
    }
    iVar6 = *(int *)(param_1 + 0xe20);
  }
  if ((*(uint *)(*(int *)(iVar6 + 0xd80) + 0x3c) & 8) != 0) {
    uVar3 = ((int (*)())_PPCRasterOpMachine_BlendingRTCAV)(param_1 + 0xe14,*(undefined4 *)(param_1 + 0xe30));
    iVar6 = *(int *)(param_1 + 0xe20);
    *(undefined4 *)(param_1 + 0xe30) = uVar3;
  }
  if ((*(uint *)(*(int *)(iVar6 + 0xd80) + 0x3c) & 0x20) != 0) {
    uVar3 = ((int (*)())_PPCRasterOpMachine_LogicOpRTCAV)(param_1 + 0xe14,*(undefined4 *)(param_1 + 0xe30));
    *(undefined4 *)(param_1 + 0xe30) = uVar3;
  }
  if (bVar1) {
    uVar3 = ((int (*)())_PPCRasterOpMachine_BufferMaskRTCAV)(param_1 + 0xe14,*(undefined4 *)(param_1 + 0xe30));
    *(undefined4 *)(param_1 + 0xe30) = uVar3;
  }
  uVar4 = _PPEmulatorFramebufferFormat(*(undefined4 *)(param_1 + 0xe20));
  if ((uVar4 & 0x8000) == 0) {
    uVar4 = _PPEmulatorFramebufferFormat(*(undefined4 *)(param_1 + 0xe20));
    if ((uVar4 & 0x8000000) == 0) {
      return;
    }
    puVar5 = *(undefined4 **)(param_1 + 0xe30);
    *puVar5 = 0x7e6031ce;
  }
  else {
    puVar5 = *(undefined4 **)(param_1 + 0xe30);
    *puVar5 = 0x10739c84;
    puVar5 = puVar5 + 1;
    *(undefined4 **)(param_1 + 0xe30) = puVar5;
    iVar6 = _glpRTCAddAChunk_97bd7cbc(&_glpOpConvertRGBAFFFFToARGB8888,puVar5);
    puVar5 = (undefined4 *)(*(int *)(param_1 + 0xe30) + iVar6 * 4);
    *(undefined4 *)(*(int *)(param_1 + 0xe30) + iVar6 * 4) = 0x7c60318e;
  }
  *(undefined4 **)(param_1 + 0xe30) = puVar5 + 1;
  return;
}

/* _PPCRuntimeCompilerWritePrologNO @ 0x97bdb67c (828 bytes) */
int _PPCRuntimeCompilerWritePrologNO(param_1)
  int param_1;
{
  uint *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  iVar7 = 0x13;
  iVar5 = 0xd;
  uVar3 = 0x284;
  do {
    if ((iVar5 != 0x10) || ((*(uint *)(*(int *)(param_1 + 0xe24) + 0x34) & 0x200) != 0)) {
      puVar1 = *(uint **)(param_1 + 0xe30);
      *puVar1 = iVar5 << 0x15 | uVar3 & 0xffff | 0x90030000;
      *(uint **)(param_1 + 0xe30) = puVar1 + 1;
    }
    iVar5 = iVar5 + 1;
    uVar3 = uVar3 + 4;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  uVar6 = 0xe;
  iVar5 = 0x12;
  uVar3 = 0x308;
  piVar4 = (int *)(param_1 + 0x33c);
  do {
    if ((uVar6 < 0x14) || (*piVar4 != 0)) {
      puVar1 = *(uint **)(param_1 + 0xe30);
      *puVar1 = uVar6 << 0x15 | uVar3 & 0xffff | 0xd0030000;
      *(uint **)(param_1 + 0xe30) = puVar1 + 1;
    }
    uVar6 = uVar6 + 1;
    piVar4 = piVar4 + 0xe;
    uVar3 = uVar3 + 4;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  if ((*(uint *)(*(int *)(param_1 + 0xe24) + 0x34) & 0x400) != 0) {
    puVar2 = *(undefined4 **)(param_1 + 0xe30);
    *puVar2 = 0xfd00048e;
    puVar2[1] = 0xd1030350;
    puVar2[2] = 0xffc0004c;
    puVar2[3] = 0xffe0004c;
    *(undefined4 **)(param_1 + 0xe30) = puVar2 + 4;
  }
  puVar2 = *(undefined4 **)(param_1 + 0xe30);
  *puVar2 = 0x80430d9c;
  iVar5 = *(int *)(param_1 + 0xe24);
  *(undefined4 **)(param_1 + 0xe30) = puVar2 + 1;
  if ((*(uint *)(iVar5 + 0x34) & 1) != 0) {
    puVar2[1] = 0x80a30d84;
    iVar5 = *(int *)(param_1 + 0xe24);
    *(undefined4 **)(param_1 + 0xe30) = puVar2 + 2;
  }
  if ((*(uint *)(iVar5 + 0x34) & 2) != 0) {
    puVar2 = *(undefined4 **)(param_1 + 0xe30);
    *puVar2 = 0x80c30d88;
    iVar5 = *(int *)(param_1 + 0xe24);
    *(undefined4 **)(param_1 + 0xe30) = puVar2 + 1;
  }
  if ((*(uint *)(iVar5 + 0x34) & 4) != 0) {
    puVar2 = *(undefined4 **)(param_1 + 0xe30);
    *puVar2 = 0x80e30d8c;
    iVar5 = *(int *)(param_1 + 0xe24);
    *(undefined4 **)(param_1 + 0xe30) = puVar2 + 1;
  }
  if ((*(uint *)(iVar5 + 0x34) & 8) != 0) {
    puVar2 = *(undefined4 **)(param_1 + 0xe30);
    *puVar2 = 0x81030d90;
    iVar5 = *(int *)(param_1 + 0xe24);
    *(undefined4 **)(param_1 + 0xe30) = puVar2 + 1;
  }
  if ((*(uint *)(iVar5 + 0x34) & 0x10) != 0) {
    puVar2 = *(undefined4 **)(param_1 + 0xe30);
    *puVar2 = 0x81230d94;
    iVar5 = *(int *)(param_1 + 0xe24);
    *(undefined4 **)(param_1 + 0xe30) = puVar2 + 1;
  }
  if ((*(uint *)(iVar5 + 0x34) & 0x20) != 0) {
    puVar2 = *(undefined4 **)(param_1 + 0xe30);
    *puVar2 = 0x81430d98;
    iVar5 = *(int *)(param_1 + 0xe24);
    *(undefined4 **)(param_1 + 0xe30) = puVar2 + 1;
  }
  if (((*(int *)(iVar5 + 0x38) == 0x8804) || (*(int *)(iVar5 + 0x38) == 0x8b30)) &&
     ((*(uint *)(iVar5 + 0x34) & 0x1004) != 0)) {
    puVar2 = *(undefined4 **)(param_1 + 0xe30);
    *puVar2 = 0x81830da4;
    puVar2[1] = 0x81a30da0;
    *(undefined4 **)(param_1 + 0xe30) = puVar2 + 2;
  }
  iVar7 = _glpRTCAddAChunk_97bd7cbc(&_glpOpLoadOneAndZeroRTC,*(undefined4 *)(param_1 + 0xe30));
  iVar5 = *(int *)(param_1 + 0xe30);
  *(undefined4 *)(iVar5 + iVar7 * 4) = 0x7c8903a6;
  iVar5 = iVar5 + iVar7 * 4;
  iVar7 = *(int *)(param_1 + 0xe24);
  *(int *)(param_1 + 0xe30) = iVar5 + 4;
  if ((*(int *)(iVar7 + 0x38) != 0x8804) && (*(int *)(iVar7 + 0x38) != 0x8b30)) {
    *(undefined4 *)(iVar5 + 4) = 0x3a2000ff;
    *(undefined4 *)(iVar5 + 8) = 0x3a400000;
    iVar7 = *(int *)(param_1 + 0xe24);
    *(int *)(param_1 + 0xe30) = iVar5 + 0xc;
  }
  if ((*(int *)(iVar7 + 0x38) == 0x8804) || (*(int *)(iVar7 + 0x38) == 0x8b30)) {
    puVar2 = *(undefined4 **)(param_1 + 0xe30);
    *puVar2 = 0xfd805890;
    *(undefined4 **)(param_1 + 0xe30) = puVar2 + 1;
  }
  return;
}

/* _PPCRuntimeCompilerWriteEpilogNO @ 0x97bdb9b8 (352 bytes) */
int _PPCRuntimeCompilerWriteEpilogNO(param_1)
  int param_1;
{
  undefined4 *puVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  
  iVar2 = *(int *)(param_1 + 0xe24);
  if ((*(int *)(iVar2 + 0x38) != 0x8804) && (*(int *)(iVar2 + 0x38) != 0x8b30)) {
    puVar1 = *(undefined4 **)(param_1 + 0xe30);
    *puVar1 = 0x39e00008;
    puVar1[1] = 0x7e317830;
    puVar1[2] = 0x7e259378;
    iVar2 = *(int *)(param_1 + 0xe24);
    *(undefined4 **)(param_1 + 0xe30) = puVar1 + 3;
  }
  if ((*(uint *)(iVar2 + 0x34) & 0x400) != 0) {
    puVar1 = *(undefined4 **)(param_1 + 0xe30);
    *puVar1 = 0xc1030350;
    puVar1[1] = 0xfdfe458e;
    *(undefined4 **)(param_1 + 0xe30) = puVar1 + 2;
  }
  iVar2 = 0xd;
  iVar7 = 0x13;
  uVar4 = 0x284;
  do {
    if ((iVar2 != 0x10) || ((*(uint *)(*(int *)(param_1 + 0xe24) + 0x34) & 0x200) != 0)) {
      puVar3 = *(uint **)(param_1 + 0xe30);
      *puVar3 = iVar2 << 0x15 | uVar4 & 0xffff | 0x80030000;
      *(uint **)(param_1 + 0xe30) = puVar3 + 1;
    }
    iVar2 = iVar2 + 1;
    uVar4 = uVar4 + 4;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  uVar6 = 0xe;
  iVar2 = 0x12;
  uVar4 = 0x308;
  piVar5 = (int *)(param_1 + 0x33c);
  do {
    if ((uVar6 < 0x14) || (*piVar5 != 0)) {
      puVar3 = *(uint **)(param_1 + 0xe30);
      *puVar3 = uVar6 << 0x15 | uVar4 & 0xffff | 0xc0030000;
      *(uint **)(param_1 + 0xe30) = puVar3 + 1;
    }
    uVar6 = uVar6 + 1;
    piVar5 = piVar5 + 0xe;
    uVar4 = uVar4 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  puVar1 = *(undefined4 **)(param_1 + 0xe30);
  *puVar1 = 0x7ca32b78;
  puVar1[1] = 0x4e800020;
  *(undefined4 **)(param_1 + 0xe30) = puVar1 + 2;
  return;
}

/* _PPCRuntimeCompilerWritePrologAV @ 0x97bdbb18 (1132 bytes) */
int _PPCRuntimeCompilerWritePrologAV(param_1)
  int param_1;
{
  undefined4 *puVar1;
  uint *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  puVar1 = *(undefined4 **)(param_1 + 0xe30);
  *puVar1 = 0x7c0042a6;
  iVar7 = 0x20;
  *(undefined4 **)(param_1 + 0xe30) = puVar1 + 1;
  do {
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  puVar1 = *(undefined4 **)(param_1 + 0xe30);
  *puVar1 = 0x6405ffff;
  puVar1[1] = 0x60a5ffff;
  puVar1[2] = 0x7ca043a6;
  puVar1[3] = 0x10ff038c;
  iVar8 = 0x13;
  puVar1[4] = 0x10e73984;
  iVar7 = 0xd;
  *(undefined4 **)(param_1 + 0xe30) = puVar1 + 5;
  uVar4 = 0x284;
  do {
    if ((iVar7 != 0x10) || ((*(uint *)(*(int *)(param_1 + 0xe24) + 0x34) & 0x200) != 0)) {
      puVar2 = *(uint **)(param_1 + 0xe30);
      *puVar2 = iVar7 << 0x15 | uVar4 & 0xffff | 0x90030000;
      *(uint **)(param_1 + 0xe30) = puVar2 + 1;
    }
    iVar7 = iVar7 + 1;
    uVar4 = uVar4 + 4;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  puVar1 = *(undefined4 **)(param_1 + 0xe30);
  *puVar1 = 0x80430d9c;
  iVar7 = *(int *)(param_1 + 0xe24);
  *(undefined4 **)(param_1 + 0xe30) = puVar1 + 1;
  if ((*(uint *)(iVar7 + 0x34) & 1) != 0) {
    puVar1[1] = 0x80a30d84;
    iVar7 = *(int *)(param_1 + 0xe24);
    *(undefined4 **)(param_1 + 0xe30) = puVar1 + 2;
  }
  if ((*(uint *)(iVar7 + 0x34) & 2) != 0) {
    puVar1 = *(undefined4 **)(param_1 + 0xe30);
    *puVar1 = 0x80c30d88;
    iVar7 = *(int *)(param_1 + 0xe24);
    *(undefined4 **)(param_1 + 0xe30) = puVar1 + 1;
  }
  if ((*(uint *)(iVar7 + 0x34) & 4) != 0) {
    puVar1 = *(undefined4 **)(param_1 + 0xe30);
    *puVar1 = 0x80e30d8c;
    iVar7 = *(int *)(param_1 + 0xe24);
    *(undefined4 **)(param_1 + 0xe30) = puVar1 + 1;
  }
  if ((*(uint *)(iVar7 + 0x34) & 8) != 0) {
    puVar1 = *(undefined4 **)(param_1 + 0xe30);
    *puVar1 = 0x81030d90;
    iVar7 = *(int *)(param_1 + 0xe24);
    *(undefined4 **)(param_1 + 0xe30) = puVar1 + 1;
  }
  if ((*(uint *)(iVar7 + 0x34) & 0x10) != 0) {
    puVar1 = *(undefined4 **)(param_1 + 0xe30);
    *puVar1 = 0x81230d94;
    iVar7 = *(int *)(param_1 + 0xe24);
    *(undefined4 **)(param_1 + 0xe30) = puVar1 + 1;
  }
  if ((*(uint *)(iVar7 + 0x34) & 0x20) != 0) {
    puVar1 = *(undefined4 **)(param_1 + 0xe30);
    *puVar1 = 0x81430d98;
    *(undefined4 **)(param_1 + 0xe30) = puVar1 + 1;
  }
  iVar7 = _glpRTCAddAChunk_97bd7cbc(&_glpOpLoadOneAndZeroAVRTC,*(undefined4 *)(param_1 + 0xe30));
  iVar5 = *(int *)(param_1 + 0xe30);
  iVar8 = *(int *)(param_1 + 0xe24);
  iVar6 = iVar5 + iVar7 * 4;
  *(int *)(param_1 + 0xe30) = iVar6;
  if (((*(int *)(iVar8 + 0x38) == 0x8804) || (*(int *)(iVar8 + 0x38) == 0x8b30)) &&
     ((*(uint *)(iVar8 + 0x34) & 0x1004) != 0)) {
    *(undefined4 *)(iVar5 + iVar7 * 4) = 0x81830da4;
    *(undefined4 *)(iVar6 + 4) = 0x81a30da0;
    iVar8 = *(int *)(param_1 + 0xe24);
    *(int *)(param_1 + 0xe30) = iVar6 + 8;
  }
  if ((*(int *)(iVar8 + 0x38) != 0x8804) && (*(int *)(iVar8 + 0x38) != 0x8b30)) {
    puVar1 = *(undefined4 **)(param_1 + 0xe30);
    *puVar1 = 0x39e01b70;
    puVar1[1] = 0x7dcf10ce;
    puVar1[2] = 0x39e01b80;
    puVar1[3] = 0x7def10ce;
    puVar1[4] = 0x39e00000;
    puVar1[5] = 0x7e4f18ce;
    puVar1[6] = 0x121f038c;
    puVar1[7] = 0x12294c84;
    *(undefined4 **)(param_1 + 0xe30) = puVar1 + 8;
  }
  puVar1 = *(undefined4 **)(param_1 + 0xe30);
  *puVar1 = 0x7c8903a6;
  puVar1 = puVar1 + 1;
  *(undefined4 **)(param_1 + 0xe30) = puVar1;
  iVar7 = _glpRTCAddAChunk_97bd7cbc(&_glpOpLoadOneAndZeroRTC,puVar1);
  iVar8 = *(int *)(param_1 + 0xe24);
  *(int *)(param_1 + 0xe30) = *(int *)(param_1 + 0xe30) + iVar7 * 4;
  if ((*(int *)(iVar8 + 0x38) == 0x8804) || (*(int *)(iVar8 + 0x38) == 0x8b30)) {
    uVar4 = _PPEmulatorFramebufferFormat(*(undefined4 *)(param_1 + 0xe20));
    if ((uVar4 & 0x8000) != 0) {
      puVar1 = *(undefined4 **)(param_1 + 0xe30);
      *puVar1 = 0x39e00040;
      puVar1[1] = 0x7e4378ce;
      *(undefined4 **)(param_1 + 0xe30) = puVar1 + 2;
    }
    iVar8 = *(int *)(param_1 + 0xe24);
  }
  if ((*(int *)(iVar8 + 0x38) == 0x8804) || (*(int *)(iVar8 + 0x38) == 0x8b30)) {
    if ((*(uint *)(iVar8 + 0x34) & 4) != 0) {
      puVar1 = *(undefined4 **)(param_1 + 0xe30);
      *puVar1 = 0x7c6068ce;
      puVar3 = puVar1 + 1;
      *(undefined4 **)(param_1 + 0xe30) = puVar3;
      if ((*(uint *)(param_1 + 0xe50) & 8) == 0) {
        *puVar3 = 0x11c9436a;
        iVar8 = *(int *)(param_1 + 0xe24);
        *(undefined4 **)(param_1 + 0xe30) = puVar1 + 2;
      }
      else {
        *puVar3 = 0x1080190a;
        puVar1[2] = 0x11c9236a;
        iVar8 = *(int *)(param_1 + 0xe24);
        *(undefined4 **)(param_1 + 0xe30) = puVar1 + 3;
      }
    }
    if ((*(uint *)(iVar8 + 0x34) & 0x1000) != 0) {
      puVar1 = *(undefined4 **)(param_1 + 0xe30);
      *puVar1 = 0xfd805890;
      puVar1[1] = 0xc1ad0008;
      *(undefined4 **)(param_1 + 0xe30) = puVar1 + 2;
    }
  }
  return;
}

/* _PPCRuntimeCompilerWriteEpilogAV @ 0x97bdbf84 (304 bytes) */
int _PPCRuntimeCompilerWriteEpilogAV(param_1)
  int param_1;
{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0xe24) + 0x38);
  if ((iVar1 != 0x8804) && (iVar1 != 0x8b30)) {
    puVar4 = *(undefined4 **)(param_1 + 0xe30);
    *puVar4 = 0x1210486c;
    puVar4[1] = 0x39e0020e;
    puVar4[2] = 0x10718484;
    puVar4[3] = 0x7c6f194e;
    puVar4[4] = 0x7caf1a2e;
    *(undefined4 **)(param_1 + 0xe30) = puVar4 + 5;
  }
  iVar1 = 0xd;
  iVar5 = 0x13;
  uVar3 = 0x284;
  do {
    if ((iVar1 != 0x10) || ((*(uint *)(*(int *)(param_1 + 0xe24) + 0x34) & 0x200) != 0)) {
      puVar2 = *(uint **)(param_1 + 0xe30);
      *puVar2 = iVar1 << 0x15 | uVar3 & 0xffff | 0x80030000;
      *(uint **)(param_1 + 0xe30) = puVar2 + 1;
    }
    iVar1 = iVar1 + 1;
    uVar3 = uVar3 + 4;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  puVar4 = *(undefined4 **)(param_1 + 0xe30);
  *puVar4 = 0x7ca32b78;
  puVar4 = puVar4 + 1;
  *(undefined4 **)(param_1 + 0xe30) = puVar4;
  iVar1 = _glpRTCAddAChunk_97bd7cbc(&_glpEpilogAVRTC,puVar4);
  *(int *)(param_1 + 0xe30) = *(int *)(param_1 + 0xe30) + iVar1 * 4;
  return;
}

/* _PPCRuntimeCompilerStride @ 0x97bdc0b4 (548 bytes) */
int _PPCRuntimeCompilerStride(param_1)
  int param_1;
{
  ushort uVar1;
  uint *puVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar3 = *(int *)(param_1 + 0xe24);
  if ((*(int *)(iVar3 + 0x38) == 0x8804) || (*(int *)(iVar3 + 0x38) == 0x8b30)) {
    if (*(int *)(param_1 + 0xe4c) == 0) {
      puVar4 = *(undefined4 **)(param_1 + 0xe30);
      *puVar4 = 0xed8c502a;
      puVar4 = puVar4 + 1;
    }
    else {
      if ((*(uint *)(iVar3 + 0x34) & 4) != 0) {
        puVar4 = *(undefined4 **)(param_1 + 0xe30);
        *puVar4 = 0x10684b2c;
        puVar4[1] = 0x11ce180a;
        *(undefined4 **)(param_1 + 0xe30) = puVar4 + 2;
        if ((*(uint *)(param_1 + 0xe50) & 8) != 0) {
          puVar4[2] = 0x7c6068ce;
          puVar4[3] = 0x7c8060ce;
          puVar4[4] = 0x10a0728c;
          puVar4[5] = 0x10a4196e;
          puVar4[6] = 0x10c0290a;
          puVar4[7] = 0x11ce336a;
          *(undefined4 **)(param_1 + 0xe30) = puVar4 + 8;
        }
        iVar3 = *(int *)(param_1 + 0xe24);
      }
      if ((*(uint *)(iVar3 + 0x34) & 0x1000) == 0) goto LAB_97bdc214;
      puVar4 = *(undefined4 **)(param_1 + 0xe30);
      *puVar4 = 0xed8c502a;
      puVar4[1] = 0xc10d0008;
      puVar4[2] = 0xc12c0008;
      puVar4[3] = 0xeda9433a;
      puVar4 = puVar4 + 4;
    }
    *(undefined4 **)(param_1 + 0xe30) = puVar4;
    iVar3 = *(int *)(param_1 + 0xe24);
  }
  else {
    puVar2 = *(uint **)(param_1 + 0xe30);
    *puVar2 = *(ushort *)(iVar3 + 0xbe) | 0x38e70000;
    iVar3 = *(int *)(param_1 + 0xe24);
    *(uint **)(param_1 + 0xe30) = puVar2 + 1;
  }
LAB_97bdc214:
  if ((*(uint *)(iVar3 + 0x34) & 2) != 0) {
    puVar2 = *(uint **)(param_1 + 0xe30);
    *puVar2 = *(ushort *)(iVar3 + 0xba) | 0x38c60000;
    iVar3 = *(int *)(param_1 + 0xe24);
    *(uint **)(param_1 + 0xe30) = puVar2 + 1;
  }
  if ((*(uint *)(iVar3 + 0x34) & 0x1000) != 0) {
    puVar4 = *(undefined4 **)(param_1 + 0xe30);
    *puVar4 = 0x81e30da8;
    *(undefined4 **)(param_1 + 0xe30) = puVar4 + 1;
    uVar1 = *(ushort *)(*(int *)(param_1 + 0xe24) + 0xda);
    puVar4[2] = 0x91e30da8;
    puVar4[1] = uVar1 | 0x39ef0000;
    iVar3 = *(int *)(param_1 + 0xe24);
    *(undefined4 **)(param_1 + 0xe30) = puVar4 + 3;
  }
  if ((*(uint *)(iVar3 + 0x34) & 0x4000) != 0) {
    puVar4 = *(undefined4 **)(param_1 + 0xe30);
    *puVar4 = 0x81e30dac;
    *(undefined4 **)(param_1 + 0xe30) = puVar4 + 1;
    uVar1 = *(ushort *)(*(int *)(param_1 + 0xe24) + 0xde);
    puVar4[2] = 0x91e30dac;
    puVar4[1] = uVar1 | 0x39ef0000;
    *(undefined4 **)(param_1 + 0xe30) = puVar4 + 3;
  }
  return;
}

/* _PPCRuntimeCompilerLoop @ 0x97bdc2d8 (92 bytes) */
int _PPCRuntimeCompilerLoop(param_1)
  int param_1;
{
  uint uVar1;
  uint *puVar2;
  
  puVar2 = *(uint **)(param_1 + 0xe30);
  uVar1 = (uint)((int)puVar2 - *(int *)(param_1 + 0xe38)) >> 2;
  if (uVar1 < 0x1fff) {
    *puVar2 = uVar1 * -4 & 0xfffc | 0x42000000;
    *(uint **)(param_1 + 0xe30) = puVar2 + 1;
    return;
  }
  *puVar2 = 0x42400008;
  puVar2[1] = (~uVar1 & 0xffffff) << 2 | 0x48000000;
  *(uint **)(param_1 + 0xe30) = puVar2 + 2;
  return;
}

/* _PPCRuntimeCompilerCompileNO @ 0x97bdc334 (5348 bytes) */
int _PPCRuntimeCompilerCompileNO(param_1)
  int param_1;
{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  bool bVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  undefined4 uVar10;
  undefined *puVar11;
  undefined4 uVar12;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  int in_r8;
  undefined4 *in_r9;
  undefined4 uVar13;
  undefined4 uVar14;
  int iVar15;
  int *in_r10;
  int iVar16;
  uint uVar17;
  uint uVar18;
  int *piVar19;
  uint uVar20;
  uint *puVar21;
  
  _PPCRuntimeCompilerInitialise(param_1,0);
  uVar10 = _glpDCBAlloc(0x2000);
  iVar16 = 0x2000;
  *(undefined4 *)(param_1 + 0xe30) = uVar10;
  *(undefined4 *)(param_1 + 0xe2c) = uVar10;
  ((int (*)())_PPCRuntimeCompilerWritePrologNO)(param_1);
  *(undefined4 *)(param_1 + 0xe48) = 0;
  do {
    iVar6 = *(int *)(param_1 + 0xe48);
    if ((iVar6 != 1) && (iVar6 != 3)) {
      iVar6 = *(int *)(param_1 + 0xe24);
      puVar5 = *(undefined4 **)(iVar6 + 0x120);
      *(undefined4 **)(param_1 + 0xe28) = puVar5;
      while (puVar5 != (undefined4 *)0x0) {
        puVar21 = *(uint **)(param_1 + 0xe28);
        uVar17 = 1;
        bVar4 = true;
        uVar7 = puVar21[0xc];
        uVar18 = *puVar21;
        cVar1 = *(char *)(puVar21 + 1);
        if (uVar7 != 0) {
          iVar6 = 0;
          do {
            if ((*(char *)((int)puVar21 + iVar6 + 0x48) != '\0') &&
               (uVar8 = (uint)*(byte *)((int)puVar21 + iVar6 + 0x49), uVar17 < uVar8)) {
              uVar17 = uVar8;
            }
            iVar6 = iVar6 + 0x24;
            uVar7 = uVar7 - 1;
          } while (uVar7 != 0);
        }
        if (uVar18 == 0x22) {
          if ((*(int *)(param_1 + 0x380) == 0) &&
             (((uVar3 = *(ushort *)(puVar21 + 7),
               uVar7 = ((int (*)())_PPCRuntimeCompilerGetBaseIndexInRegister)(param_1,0x10), uVar3 != uVar7 ||
               (piVar19 = (int *)puVar21[3],
               iVar6 = ((int (*)())_PPCRuntimeCompilerGetOffsetInRegister)(param_1,0x10), *piVar19 != iVar6)) ||
              (puVar21 = *(uint **)(param_1 + 0xe28), (puVar21[10] & 0x1000000) == 0)))) {
            _PPCRuntimeCompilerBackupRegister(param_1,0x10);
            puVar21 = *(uint **)(param_1 + 0xe28);
          }
          if ((*(int *)(param_1 + 0x3b8) == 0) &&
             (((uVar3 = *(ushort *)(puVar21 + 7),
               uVar7 = ((int (*)())_PPCRuntimeCompilerGetBaseIndexInRegister)(param_1,0x11), uVar3 != uVar7 ||
               (uVar7 = puVar21[3], iVar6 = ((int (*)())_PPCRuntimeCompilerGetOffsetInRegister)(param_1,0x11),
               *(int *)(uVar7 + 4) != iVar6)) ||
              (puVar21 = *(uint **)(param_1 + 0xe28), (puVar21[10] & 0x2000000) == 0)))) {
            _PPCRuntimeCompilerBackupRegister(param_1,0x11);
            puVar21 = *(uint **)(param_1 + 0xe28);
          }
          if ((*(int *)(param_1 + 0x3f0) == 0) &&
             (((uVar3 = *(ushort *)(puVar21 + 7),
               uVar7 = ((int (*)())_PPCRuntimeCompilerGetBaseIndexInRegister)(param_1,0x12), uVar3 != uVar7 ||
               (uVar7 = puVar21[3], iVar6 = ((int (*)())_PPCRuntimeCompilerGetOffsetInRegister)(param_1,0x12),
               *(int *)(uVar7 + 8) != iVar6)) ||
              (puVar21 = *(uint **)(param_1 + 0xe28), (puVar21[10] & 0x4000000) == 0)))) {
            _PPCRuntimeCompilerBackupRegister(param_1,0x12);
            puVar21 = *(uint **)(param_1 + 0xe28);
          }
          if ((*(int *)(param_1 + 0x428) == 0) &&
             (((uVar3 = *(ushort *)(puVar21 + 7),
               uVar7 = ((int (*)())_PPCRuntimeCompilerGetBaseIndexInRegister)(param_1,0x13), uVar3 != uVar7 ||
               (uVar7 = puVar21[3], iVar6 = ((int (*)())_PPCRuntimeCompilerGetOffsetInRegister)(param_1,0x13),
               *(int *)(uVar7 + 0xc) != iVar6)) ||
              (puVar21 = *(uint **)(param_1 + 0xe28), (puVar21[10] & 0x8000000) == 0)))) {
            _PPCRuntimeCompilerBackupRegister(param_1,0x13);
            puVar21 = *(uint **)(param_1 + 0xe28);
          }
          if ((*(char *)(puVar21 + 0x12) == '\0') && (*(char *)(puVar21 + 0x1b) == '\0')) {
            ((int (*)())_PPCRuntimeCompilerLoadSourceNO)(param_1,puVar21[0xd],puVar21[0xe],puVar21[0xf],puVar21[0x10],puVar21[0x11],
                       puVar21[0x12],puVar21[0x13],puVar21[0x14],puVar21[0x15],0,0);
            iVar6 = *(int *)(param_1 + 0xe28);
            in_r10 = *(int **)(iVar6 + 0x70);
            in_r5 = *(undefined4 *)(iVar6 + 0x5c);
            in_r6 = *(undefined4 *)(iVar6 + 0x60);
            in_r7 = *(undefined4 *)(iVar6 + 100);
            in_r8 = *(int *)(iVar6 + 0x68);
            ((int (*)())_PPCRuntimeCompilerLoadSourceNO)(param_1,*(undefined4 *)(iVar6 + 0x58),in_r5,in_r6,in_r7,in_r8,
                       *(undefined4 *)(iVar6 + 0x6c),in_r10,*(undefined4 *)(iVar6 + 0x74),
                       *(undefined4 *)(iVar6 + 0x78),0,1);
            iVar6 = _glpRTCAddAChunk_97bd7cbc(&_glpOpMultRTC,*(undefined4 *)(param_1 + 0xe30));
            *(int *)(param_1 + 0xe30) = *(int *)(param_1 + 0xe30) + iVar6 * 4;
          }
          else if ((*(char *)(puVar21 + 0x12) == '\0') ||
                  (*(char *)((int)puVar21 + 0x49) != *(char *)((int)puVar21 + 0x6d))) {
            iVar6 = 0;
            if (*(char *)(puVar21 + 0x12) == '\0') {
              if (*(char *)(puVar21 + 0x1b) != '\0') {
                ((int (*)())_PPCRuntimeCompilerLoadSourceNO)(param_1,puVar21[0x16],puVar21[0x17],puVar21[0x18],puVar21[0x19],
                           puVar21[0x1a],puVar21[0x1b],puVar21[0x1c],puVar21[0x1d],puVar21[0x1e],0,1
                          );
                iVar9 = *(int *)(param_1 + 0xe28);
                iVar6 = 1;
                uVar13 = *(undefined4 *)(iVar9 + 0x54);
                uVar10 = *(undefined4 *)(iVar9 + 0x50);
                in_r10 = *(int **)(iVar9 + 0x4c);
                uVar12 = *(undefined4 *)(iVar9 + 0x34);
                in_r5 = *(undefined4 *)(iVar9 + 0x38);
                in_r6 = *(undefined4 *)(iVar9 + 0x3c);
                in_r7 = *(undefined4 *)(iVar9 + 0x40);
                in_r8 = *(int *)(iVar9 + 0x44);
                uVar14 = *(undefined4 *)(iVar9 + 0x48);
                goto LAB_97bdc778;
              }
            }
            else {
              ((int (*)())_PPCRuntimeCompilerLoadSourceNO)(param_1,puVar21[0xd],puVar21[0xe],puVar21[0xf],puVar21[0x10],puVar21[0x11],
                         puVar21[0x12],puVar21[0x13],puVar21[0x14],puVar21[0x15],0,1);
              iVar9 = *(int *)(param_1 + 0xe28);
              uVar13 = *(undefined4 *)(iVar9 + 0x78);
              uVar10 = *(undefined4 *)(iVar9 + 0x74);
              in_r10 = *(int **)(iVar9 + 0x70);
              uVar12 = *(undefined4 *)(iVar9 + 0x58);
              in_r5 = *(undefined4 *)(iVar9 + 0x5c);
              in_r6 = *(undefined4 *)(iVar9 + 0x60);
              in_r7 = *(undefined4 *)(iVar9 + 100);
              in_r8 = *(int *)(iVar9 + 0x68);
              uVar14 = *(undefined4 *)(iVar9 + 0x6c);
LAB_97bdc778:
              ((int (*)())_PPCRuntimeCompilerLoadSourceNO)(param_1,uVar12,in_r5,in_r6,in_r7,in_r8,uVar14,in_r10,uVar10,uVar13,0,0);
            }
            if (uVar17 == 2) {
              iVar9 = _glpRTCAddAChunk_97bd7cbc(&_glpOpDot4RTC,*(undefined4 *)(param_1 + 0xe30));
              iVar15 = *(int *)(param_1 + 0xe30);
              *(undefined4 *)(iVar15 + iVar9 * 4) = 0xfd008090;
              iVar6 = iVar6 * 0x24 + *(int *)(param_1 + 0xe28);
              *(int *)(param_1 + 0xe30) = iVar15 + iVar9 * 4 + 4;
              in_r5 = *(undefined4 *)(iVar6 + 0x38);
              in_r6 = *(undefined4 *)(iVar6 + 0x3c);
              in_r7 = *(undefined4 *)(iVar6 + 0x40);
              in_r8 = *(int *)(iVar6 + 0x44);
              ((int (*)())_PPCRuntimeCompilerLoadSourceNO)(param_1,*(undefined4 *)(iVar6 + 0x34),in_r5,in_r6,in_r7,in_r8,
                         *(undefined4 *)(iVar6 + 0x48),*(undefined4 *)(iVar6 + 0x4c),
                         *(undefined4 *)(iVar6 + 0x50),*(undefined4 *)(iVar6 + 0x54),1,1);
              iVar6 = _glpRTCAddAChunk_97bd7cbc(&_glpOpDot4RTC,*(undefined4 *)(param_1 + 0xe30));
              in_r10 = *(int **)(param_1 + 0xe30);
              iVar6 = iVar6 << 2;
              uVar17 = 0xfe200000;
            }
            else if (uVar17 == 3) {
              iVar9 = _glpRTCAddAChunk_97bd7cbc(&_glpOpDot4RTC,*(undefined4 *)(param_1 + 0xe30));
              iVar15 = *(int *)(param_1 + 0xe30);
              *(undefined4 *)(iVar15 + iVar9 * 4) = 0xfd008090;
              *(int *)(param_1 + 0xe30) = iVar15 + iVar9 * 4 + 4;
              iVar9 = iVar6 * 0x24 + *(int *)(param_1 + 0xe28);
              ((int (*)())_PPCRuntimeCompilerLoadSourceNO)(param_1,*(undefined4 *)(iVar9 + 0x34),*(undefined4 *)(iVar9 + 0x38),
                         *(undefined4 *)(iVar9 + 0x3c),*(undefined4 *)(iVar9 + 0x40),
                         *(undefined4 *)(iVar9 + 0x44),*(undefined4 *)(iVar9 + 0x48),
                         *(undefined4 *)(iVar9 + 0x4c),*(undefined4 *)(iVar9 + 0x50),
                         *(undefined4 *)(iVar9 + 0x54),1,1);
              iVar15 = _glpRTCAddAChunk_97bd7cbc(&_glpOpDot4RTC,*(undefined4 *)(param_1 + 0xe30));
              iVar9 = *(int *)(param_1 + 0xe30);
              *(undefined4 *)(iVar9 + iVar15 * 4) = 0xfe208090;
              *(int *)(param_1 + 0xe30) = iVar9 + iVar15 * 4 + 4;
              iVar6 = iVar6 * 0x24 + *(int *)(param_1 + 0xe28);
              in_r5 = *(undefined4 *)(iVar6 + 0x38);
              in_r6 = *(undefined4 *)(iVar6 + 0x3c);
              in_r7 = *(undefined4 *)(iVar6 + 0x40);
              in_r8 = *(int *)(iVar6 + 0x44);
              ((int (*)())_PPCRuntimeCompilerLoadSourceNO)(param_1,*(undefined4 *)(iVar6 + 0x34),in_r5,in_r6,in_r7,in_r8,
                         *(undefined4 *)(iVar6 + 0x48),*(undefined4 *)(iVar6 + 0x4c),
                         *(undefined4 *)(iVar6 + 0x50),*(undefined4 *)(iVar6 + 0x54),2,1);
              iVar6 = _glpRTCAddAChunk_97bd7cbc(&_glpOpDot4RTC,*(undefined4 *)(param_1 + 0xe30));
              in_r10 = *(int **)(param_1 + 0xe30);
              iVar6 = iVar6 << 2;
              uVar17 = 0xfe400000;
            }
            else {
              if (uVar17 != 4) goto LAB_97bdcb04;
              iVar6 = iVar6 * 0x24;
              iVar9 = _glpRTCAddAChunk_97bd7cbc(&_glpOpDot4RTC,*(undefined4 *)(param_1 + 0xe30));
              iVar15 = *(int *)(param_1 + 0xe30);
              *(undefined4 *)(iVar15 + iVar9 * 4) = 0xfd008090;
              *(int *)(param_1 + 0xe30) = iVar15 + iVar9 * 4 + 4;
              iVar9 = iVar6 + *(int *)(param_1 + 0xe28);
              ((int (*)())_PPCRuntimeCompilerLoadSourceNO)(param_1,*(undefined4 *)(iVar9 + 0x34),*(undefined4 *)(iVar9 + 0x38),
                         *(undefined4 *)(iVar9 + 0x3c),*(undefined4 *)(iVar9 + 0x40),
                         *(undefined4 *)(iVar9 + 0x44),*(undefined4 *)(iVar9 + 0x48),
                         *(undefined4 *)(iVar9 + 0x4c),*(undefined4 *)(iVar9 + 0x50),
                         *(undefined4 *)(iVar9 + 0x54),1,1);
              iVar9 = _glpRTCAddAChunk_97bd7cbc(&_glpOpDot4RTC,*(undefined4 *)(param_1 + 0xe30));
              iVar15 = *(int *)(param_1 + 0xe30);
              *(undefined4 *)(iVar15 + iVar9 * 4) = 0xfe208090;
              *(int *)(param_1 + 0xe30) = iVar15 + iVar9 * 4 + 4;
              iVar9 = iVar6 + *(int *)(param_1 + 0xe28);
              ((int (*)())_PPCRuntimeCompilerLoadSourceNO)(param_1,*(undefined4 *)(iVar9 + 0x34),*(undefined4 *)(iVar9 + 0x38),
                         *(undefined4 *)(iVar9 + 0x3c),*(undefined4 *)(iVar9 + 0x40),
                         *(undefined4 *)(iVar9 + 0x44),*(undefined4 *)(iVar9 + 0x48),
                         *(undefined4 *)(iVar9 + 0x4c),*(undefined4 *)(iVar9 + 0x50),
                         *(undefined4 *)(iVar9 + 0x54),2,1);
              iVar15 = _glpRTCAddAChunk_97bd7cbc(&_glpOpDot4RTC,*(undefined4 *)(param_1 + 0xe30));
              iVar9 = *(int *)(param_1 + 0xe30);
              *(undefined4 *)(iVar9 + iVar15 * 4) = 0xfe408090;
              *(int *)(param_1 + 0xe30) = iVar9 + iVar15 * 4 + 4;
              iVar6 = iVar6 + *(int *)(param_1 + 0xe28);
              in_r5 = *(undefined4 *)(iVar6 + 0x38);
              in_r6 = *(undefined4 *)(iVar6 + 0x3c);
              in_r7 = *(undefined4 *)(iVar6 + 0x40);
              in_r8 = *(int *)(iVar6 + 0x44);
              ((int (*)())_PPCRuntimeCompilerLoadSourceNO)(param_1,*(undefined4 *)(iVar6 + 0x34),in_r5,in_r6,in_r7,in_r8,
                         *(undefined4 *)(iVar6 + 0x48),*(undefined4 *)(iVar6 + 0x4c),
                         *(undefined4 *)(iVar6 + 0x50),*(undefined4 *)(iVar6 + 0x54),3,1);
              iVar6 = _glpRTCAddAChunk_97bd7cbc(&_glpOpDot4RTC,*(undefined4 *)(param_1 + 0xe30));
              in_r10 = *(int **)(param_1 + 0xe30);
              iVar6 = iVar6 << 2;
              uVar17 = 0xfe600000;
            }
            *(uint *)((int)in_r10 + iVar6) = uVar17 | 0x8090;
            *(undefined4 *)((int)in_r10 + iVar6 + 4) = 0xfe004090;
            *(int *)(param_1 + 0xe30) = (int)in_r10 + iVar6 + 8;
          }
LAB_97bdcb04:
          ((int (*)())_PPCRuntimeCompilerWriteDestinationNO)(param_1,0);
        }
        else {
          uVar7 = 0;
          if (uVar17 != 0) {
            do {
              if ((*(int *)(param_1 + 0x380) == 0) &&
                 (((uVar3 = *(ushort *)(puVar21 + 7),
                   uVar8 = ((int (*)())_PPCRuntimeCompilerGetBaseIndexInRegister)(param_1,0x10), uVar3 != uVar8
                   || (piVar19 = (int *)puVar21[3],
                      iVar6 = ((int (*)())_PPCRuntimeCompilerGetOffsetInRegister)(param_1,0x10),
                      *piVar19 != iVar6)) ||
                  (puVar21 = *(uint **)(param_1 + 0xe28), (puVar21[10] & 0x1000000) == 0)))) {
                _PPCRuntimeCompilerBackupRegister(param_1,0x10);
                puVar21 = *(uint **)(param_1 + 0xe28);
              }
              if ((*(int *)(param_1 + 0x3b8) == 0) &&
                 (((uVar3 = *(ushort *)(puVar21 + 7),
                   uVar8 = ((int (*)())_PPCRuntimeCompilerGetBaseIndexInRegister)(param_1,0x11), uVar3 != uVar8
                   || (uVar8 = puVar21[3],
                      iVar6 = ((int (*)())_PPCRuntimeCompilerGetOffsetInRegister)(param_1,0x11),
                      *(int *)(uVar8 + 4) != iVar6)) ||
                  (puVar21 = *(uint **)(param_1 + 0xe28), (puVar21[10] & 0x2000000) == 0)))) {
                _PPCRuntimeCompilerBackupRegister(param_1,0x11);
                puVar21 = *(uint **)(param_1 + 0xe28);
              }
              if ((*(int *)(param_1 + 0x3f0) == 0) &&
                 (((uVar3 = *(ushort *)(puVar21 + 7),
                   uVar8 = ((int (*)())_PPCRuntimeCompilerGetBaseIndexInRegister)(param_1,0x12), uVar3 != uVar8
                   || (uVar8 = puVar21[3],
                      iVar6 = ((int (*)())_PPCRuntimeCompilerGetOffsetInRegister)(param_1,0x12),
                      *(int *)(uVar8 + 8) != iVar6)) ||
                  (puVar21 = *(uint **)(param_1 + 0xe28), (puVar21[10] & 0x4000000) == 0)))) {
                _PPCRuntimeCompilerBackupRegister(param_1,0x12);
                puVar21 = *(uint **)(param_1 + 0xe28);
              }
              if ((*(int *)(param_1 + 0x428) == 0) &&
                 (((uVar3 = *(ushort *)(puVar21 + 7),
                   uVar8 = ((int (*)())_PPCRuntimeCompilerGetBaseIndexInRegister)(param_1,0x13), uVar3 != uVar8
                   || (uVar8 = puVar21[3],
                      iVar6 = ((int (*)())_PPCRuntimeCompilerGetOffsetInRegister)(param_1,0x13),
                      *(int *)(uVar8 + 0xc) != iVar6)) ||
                  (puVar21 = *(uint **)(param_1 + 0xe28), (puVar21[10] & 0x8000000) == 0)))) {
                _PPCRuntimeCompilerBackupRegister(param_1,0x13);
                puVar21 = *(uint **)(param_1 + 0xe28);
              }
              if (puVar21[0xc] != 0) {
                iVar6 = 0;
                uVar8 = 0;
                do {
                  uVar20 = uVar8 + 1;
                  in_r10 = *(int **)((int)puVar21 + iVar6 + 0x4c);
                  in_r5 = *(undefined4 *)((int)puVar21 + iVar6 + 0x38);
                  in_r6 = *(undefined4 *)((int)puVar21 + iVar6 + 0x3c);
                  in_r7 = *(undefined4 *)((int)puVar21 + iVar6 + 0x40);
                  in_r8 = *(int *)((int)puVar21 + iVar6 + 0x44);
                  ((int (*)())_PPCRuntimeCompilerLoadSourceNO)(param_1,*(undefined4 *)((int)puVar21 + iVar6 + 0x34),in_r5,in_r6,in_r7,
                             in_r8,*(undefined4 *)((int)puVar21 + iVar6 + 0x48),in_r10,
                             *(undefined4 *)((int)puVar21 + iVar6 + 0x50),
                             *(undefined4 *)((int)puVar21 + iVar6 + 0x54),uVar7,uVar8);
                  puVar21 = *(uint **)(param_1 + 0xe28);
                  iVar6 = iVar6 + 0x24;
                  uVar8 = uVar20;
                } while (uVar20 < puVar21[0xc]);
              }
              if (uVar18 < 0x15) {
                if (((0x12 < uVar18) || (uVar18 == 1)) || ((uVar18 != 0 && (uVar18 - 0x10 < 2)))) {
LAB_97bdcd64:
                  _PPCRuntimeCompilerDirtyRegister(param_1,0);
                  _PPCRuntimeCompilerDirtyRegister(param_1,1);
                  _PPCRuntimeCompilerDirtyRegister(param_1,2);
                  _PPCRuntimeCompilerDirtyRegister(param_1,3);
                  _PPCRuntimeCompilerDirtyRegister(param_1,4);
                  _PPCRuntimeCompilerDirtyRegister(param_1,5);
                  _PPCRuntimeCompilerDirtyRegister(param_1,6);
                  _PPCRuntimeCompilerDirtyRegister(param_1,7);
                }
              }
              else {
                if (uVar18 == 0x38) goto LAB_97bdcd64;
                if (uVar18 == 0x48) {
                  _PPCRuntimeCompilerDirtyRegister(param_1,0);
                  _PPCRuntimeCompilerDirtyRegistersWithIndirectData(param_1);
                }
              }
              switch(uVar18) {
              case 0:
                iVar6 = *(int *)(param_1 + 0xe30);
                puVar11 = &_glpOpMovRTC;
                break;
              case 1:
                iVar6 = _glpRTCAddAChunk_97bd7cbc
                                  (&_glpOpShuffleSrcRTC,*(undefined4 *)(param_1 + 0xe30));
                iVar6 = *(int *)(param_1 + 0xe30) + iVar6 * 4;
                *(int *)(param_1 + 0xe30) = iVar6;
                iVar6 = _glpRTCAddAChunk_97bd7cbc(&_glpOpLogRTC,iVar6);
                iVar6 = *(int *)(param_1 + 0xe30) + iVar6 * 4;
                *(int *)(param_1 + 0xe30) = iVar6;
                iVar6 = _glpRTCAddAChunk_97bd7cbc(&_glpOpRestoreSrcBRTC,iVar6);
                iVar6 = *(int *)(param_1 + 0xe30) + iVar6 * 4;
                *(int *)(param_1 + 0xe30) = iVar6;
                iVar6 = _glpRTCAddAChunk_97bd7cbc(&_glpOpExpRTC,iVar6);
                iVar6 = *(int *)(param_1 + 0xe30) + iVar6 * 4;
                *(int *)(param_1 + 0xe30) = iVar6;
                puVar11 = &_glpOpShuffleDstRTC;
                break;
              case 2:
                iVar6 = *(int *)(param_1 + 0xe30);
                puVar11 = &_glpOpAbsRTC;
                break;
              default:
                goto switchD_97bdcdfc_caseD_3;
              case 4:
                iVar6 = *(int *)(param_1 + 0xe30);
                puVar11 = &_glpOpFrcRTC;
                break;
              case 5:
                iVar6 = *(int *)(param_1 + 0xe30);
                puVar11 = &_glpOpFlrRTC;
                break;
              case 0xd:
                uVar10 = *(undefined4 *)(param_1 + 0xe30);
                puVar11 = &_glpOpRsqRTC;
                goto LAB_97bdcf9c;
              case 0xe:
                uVar10 = *(undefined4 *)(param_1 + 0xe30);
                puVar11 = &_glpOpRcpRTC;
                goto LAB_97bdcf9c;
              case 0x10:
                iVar6 = *(int *)(param_1 + 0xe30);
                goto LAB_97bdd288;
              case 0x11:
                iVar6 = *(int *)(param_1 + 0xe30);
                puVar11 = &_glpOpExpRTC;
                break;
              case 0x13:
                iVar6 = *(int *)(param_1 + 0xe30);
                puVar11 = &_glpOpLogRTC;
                goto LAB_97bdcfe4;
              case 0x14:
                iVar6 = *(int *)(param_1 + 0xe30);
                puVar11 = &_glpOpLogRTC;
                break;
              case 0x1f:
                iVar6 = *(int *)(param_1 + 0xe30);
                puVar11 = &_glpOpAddRTC;
                break;
              case 0x20:
                iVar6 = *(int *)(param_1 + 0xe30);
                puVar11 = &_glpOpSubRTC;
                break;
              case 0x22:
                iVar6 = *(int *)(param_1 + 0xe30);
                puVar11 = &_glpOpMultRTC;
                break;
              case 0x27:
                bVar2 = *(byte *)(*(int *)(param_1 + 0xe28) + 5);
                if (bVar2 == 2) {
                  uVar10 = *(undefined4 *)(param_1 + 0xe30);
                  puVar11 = &_glpOpDot2RTC;
LAB_97bdd170:
                  iVar6 = _glpRTCAddAChunk_97bd7cbc(puVar11,uVar10);
                  *(int *)(param_1 + 0xe30) = *(int *)(param_1 + 0xe30) + iVar6 * 4;
                }
                else {
                  if (2 < bVar2) {
                    if (bVar2 == 3) {
                      uVar10 = *(undefined4 *)(param_1 + 0xe30);
                      puVar11 = &_glpOpDot3RTC;
                    }
                    else {
                      if (bVar2 != 4) goto LAB_97bdd184;
                      uVar10 = *(undefined4 *)(param_1 + 0xe30);
                      puVar11 = &_glpOpDot4RTC;
                    }
                    goto LAB_97bdd170;
                  }
                  if (bVar2 == 1) {
                    uVar10 = *(undefined4 *)(param_1 + 0xe30);
                    puVar11 = &_glpOpDot1RTC;
                    goto LAB_97bdd170;
                  }
                }
LAB_97bdd184:
                iVar6 = *(int *)(param_1 + 0xe30);
                goto LAB_97bdcfb4;
              case 0x28:
                uVar10 = *(undefined4 *)(param_1 + 0xe30);
                puVar11 = &_glpOpDot3RTC;
                goto LAB_97bdcf9c;
              case 0x29:
                uVar10 = *(undefined4 *)(param_1 + 0xe30);
                puVar11 = &_glpOpDot4RTC;
                goto LAB_97bdcf9c;
              case 0x2a:
                uVar10 = *(undefined4 *)(param_1 + 0xe30);
                puVar11 = &_glpOpDphRTC;
LAB_97bdcf9c:
                iVar6 = _glpRTCAddAChunk_97bd7cbc(puVar11,uVar10);
                iVar6 = *(int *)(param_1 + 0xe30) + iVar6 * 4;
                *(int *)(param_1 + 0xe30) = iVar6;
LAB_97bdcfb4:
                puVar11 = &_glpOpSplatC0RTC;
                break;
              case 0x2b:
                iVar6 = *(int *)(param_1 + 0xe30);
                puVar11 = &_glpOpDistRTC;
                break;
              case 0x2c:
                iVar6 = *(int *)(param_1 + 0xe30);
                puVar11 = &_glpOpMinRTC;
                break;
              case 0x2d:
                iVar6 = *(int *)(param_1 + 0xe30);
                puVar11 = &_glpOpMaxRTC;
                break;
              case 0x2e:
                iVar6 = *(int *)(param_1 + 0xe30);
                puVar11 = &_glpOpXpdRTC;
                break;
              case 0x32:
                iVar6 = *(int *)(param_1 + 0xe30);
                puVar11 = &_glpOpSetGERTC;
                break;
              case 0x35:
                iVar6 = *(int *)(param_1 + 0xe30);
                puVar11 = &_glpOpSetLTRTC;
                break;
              case 0x38:
                iVar6 = _glpRTCAddAChunk_97bd7cbc
                                  (&_glpOpSaveSrcBRTC,*(undefined4 *)(param_1 + 0xe30));
                iVar6 = *(int *)(param_1 + 0xe30) + iVar6 * 4;
                *(int *)(param_1 + 0xe30) = iVar6;
                iVar6 = _glpRTCAddAChunk_97bd7cbc(&_glpOpLogRTC,iVar6);
                iVar6 = *(int *)(param_1 + 0xe30) + iVar6 * 4;
                *(int *)(param_1 + 0xe30) = iVar6;
                iVar6 = _glpRTCAddAChunk_97bd7cbc(&_glpOpRestoreSrcBRTC,iVar6);
                iVar6 = *(int *)(param_1 + 0xe30) + iVar6 * 4;
                *(int *)(param_1 + 0xe30) = iVar6;
LAB_97bdd288:
                puVar11 = &_glpOpExpRTC;
LAB_97bdcfe4:
                iVar6 = _glpRTCAddAChunk_97bd7cbc(puVar11,iVar6);
                iVar6 = *(int *)(param_1 + 0xe30) + iVar6 * 4;
                *(int *)(param_1 + 0xe30) = iVar6;
                puVar11 = &_glpOpSplatC2RTC;
                break;
              case 0x3c:
                iVar6 = *(int *)(param_1 + 0xe30);
                puVar11 = &_glpOpLerpRTC;
                break;
              case 0x3e:
                iVar6 = *(int *)(param_1 + 0xe30);
                puVar11 = &_glpOpCmpRTC;
                break;
              case 0x3f:
                iVar6 = *(int *)(param_1 + 0xe30);
                puVar11 = &_glpOpMultAddRTC;
                break;
              case 0x41:
                iVar6 = *(int *)(param_1 + 0xe28);
                switch(*(undefined1 *)(iVar6 + 0x60)) {
                case 0:
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  uVar10 = 0xfe000090;
                  break;
                case 1:
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  uVar10 = 0xfe000890;
                  break;
                case 2:
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  uVar10 = 0xfe001090;
                  break;
                case 3:
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  uVar10 = 0xfe001890;
                  break;
                case 4:
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  uVar10 = 0xfe000050;
                  break;
                case 5:
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  uVar10 = 0xfe000850;
                  break;
                case 6:
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  uVar10 = 0xfe001050;
                  break;
                case 7:
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  uVar10 = 0xfe001850;
                  break;
                case 8:
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  uVar10 = 0xfe005090;
                  break;
                case 9:
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  uVar10 = 0xfe005890;
                  break;
                case 10:
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  *puVar5 = 0xfe005050;
                  iVar6 = *(int *)(param_1 + 0xe28);
                  *(undefined4 **)(param_1 + 0xe30) = puVar5 + 1;
                default:
                  goto switchD_97bdd2fc_default;
                }
                *puVar5 = uVar10;
                *(undefined4 **)(param_1 + 0xe30) = puVar5 + 1;
                iVar6 = *(int *)(param_1 + 0xe28);
switchD_97bdd2fc_default:
                switch(*(undefined1 *)(iVar6 + 0x61)) {
                case 0:
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  uVar10 = 0xfe200090;
                  break;
                case 1:
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  uVar10 = 0xfe200890;
                  break;
                case 2:
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  uVar10 = 0xfe201090;
                  break;
                case 3:
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  uVar10 = 0xfe201890;
                  break;
                case 4:
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  uVar10 = 0xfe200050;
                  break;
                case 5:
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  uVar10 = 0xfe200850;
                  break;
                case 6:
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  uVar10 = 0xfe201050;
                  break;
                case 7:
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  uVar10 = 0xfe201850;
                  break;
                case 8:
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  uVar10 = 0xfe205090;
                  break;
                case 9:
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  uVar10 = 0xfe205890;
                  break;
                case 10:
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  *puVar5 = 0xfe205050;
                  iVar6 = *(int *)(param_1 + 0xe28);
                  *(undefined4 **)(param_1 + 0xe30) = puVar5 + 1;
                default:
                  goto switchD_97bdd41c_default;
                }
                *puVar5 = uVar10;
                *(undefined4 **)(param_1 + 0xe30) = puVar5 + 1;
                iVar6 = *(int *)(param_1 + 0xe28);
switchD_97bdd41c_default:
                switch(*(undefined1 *)(iVar6 + 0x62)) {
                case 0:
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  uVar10 = 0xfe400090;
                  break;
                case 1:
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  uVar10 = 0xfe400890;
                  break;
                case 2:
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  uVar10 = 0xfe401090;
                  break;
                case 3:
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  uVar10 = 0xfe401890;
                  break;
                case 4:
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  uVar10 = 0xfe400050;
                  break;
                case 5:
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  uVar10 = 0xfe400850;
                  break;
                case 6:
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  uVar10 = 0xfe401050;
                  break;
                case 7:
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  uVar10 = 0xfe401850;
                  break;
                case 8:
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  uVar10 = 0xfe405090;
                  break;
                case 9:
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  uVar10 = 0xfe405890;
                  break;
                case 10:
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  *puVar5 = 0xfe405050;
                  iVar6 = *(int *)(param_1 + 0xe28);
                  *(undefined4 **)(param_1 + 0xe30) = puVar5 + 1;
                default:
                  goto switchD_97bdd53c_default;
                }
                *puVar5 = uVar10;
                *(undefined4 **)(param_1 + 0xe30) = puVar5 + 1;
                iVar6 = *(int *)(param_1 + 0xe28);
switchD_97bdd53c_default:
                switch(*(undefined1 *)(iVar6 + 99)) {
                case 0:
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  uVar10 = 0xfe600090;
                  break;
                case 1:
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  uVar10 = 0xfe600890;
                  break;
                case 2:
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  uVar10 = 0xfe601090;
                  break;
                case 3:
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  uVar10 = 0xfe601890;
                  break;
                case 4:
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  uVar10 = 0xfe600050;
                  break;
                case 5:
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  uVar10 = 0xfe600850;
                  break;
                case 6:
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  uVar10 = 0xfe601050;
                  break;
                case 7:
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  uVar10 = 0xfe601850;
                  break;
                case 8:
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  uVar10 = 0xfe605090;
                  break;
                case 9:
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  uVar10 = 0xfe605890;
                  break;
                case 10:
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  uVar10 = 0xfe605050;
                  break;
                default:
                  goto switchD_97bdcdfc_caseD_3;
                }
                *puVar5 = uVar10;
                *(undefined4 **)(param_1 + 0xe30) = puVar5 + 1;
                goto switchD_97bdcdfc_caseD_3;
              case 0x42:
                in_r8 = *(int *)(param_1 + 0xe20);
                if (*(int *)(*(int *)(in_r8 + 0xd80) + 0x38) - 0x8b30U < 2) {
                  in_r10 = *(int **)(*(int *)(param_1 + 0xe28) + 0x58);
                  uVar10 = *(undefined4 *)
                            (*(int *)((uint)*(ushort *)(*(int *)(param_1 + 0xe28) + 0x68) * 4 +
                                      in_r8 + 0xd84) + *in_r10);
                }
                else {
                  uVar10 = *(undefined4 *)(*(int *)(param_1 + 0xe28) + 0x10c);
                }
                ((int (*)())_PPCTextureSamplerAttachGLDContext)(*(undefined4 *)(param_1 + 0xe1c),*(undefined4 *)(in_r8 + 0xd9c));
                iVar6 = *(int *)(*(int *)(param_1 + 0xe28) + 0x110);
                if (iVar6 == 2) {
                  in_r5 = *(undefined4 *)(param_1 + 0xe30);
                  uVar10 = ((int (*)())_PPCTextureSamplerSampleTexelRECTRTCNO)(*(undefined4 *)(param_1 + 0xe1c),uVar10,in_r5);
                }
                else {
                  if (iVar6 != 3) goto switchD_97bdcdfc_caseD_3;
                  in_r5 = *(undefined4 *)(param_1 + 0xe30);
                  uVar10 = ((int (*)())_PPCTextureSamplerSampleTexel2DRTCNO)(*(undefined4 *)(param_1 + 0xe1c),uVar10,in_r5);
                }
                *(undefined4 *)(param_1 + 0xe30) = uVar10;
                goto switchD_97bdcdfc_caseD_3;
              case 0x48:
                if ((*(byte *)(*(int *)(param_1 + 0xe28) + 0x28) & 1) != 0) {
                  iVar6 = _glpRTCAddAChunk_97bd7cbc(&_glpOpArlRTC,*(undefined4 *)(param_1 + 0xe30));
                  *(int *)(param_1 + 0xe30) = *(int *)(param_1 + 0xe30) + iVar6 * 4;
                }
              case 0x49:
              case 0x4a:
              case 0x4b:
              case 0x4c:
              case 0x4d:
              case 0x4f:
              case 0x55:
              case 0x56:
              case 0x57:
              case 0x58:
              case 0x59:
              case 0x5a:
                bVar4 = false;
                goto LAB_97bdd85c;
              case 0x5b:
                bVar4 = false;
                goto switchD_97bdcdfc_caseD_3;
              }
              iVar6 = _glpRTCAddAChunk_97bd7cbc(puVar11,iVar6);
              *(int *)(param_1 + 0xe30) = *(int *)(param_1 + 0xe30) + iVar6 * 4;
switchD_97bdcdfc_caseD_3:
              if (bVar4) {
                if (cVar1 != '\0') {
                  iVar6 = _glpRTCAddAChunk_97bd7cbc
                                    (&_glpOpSaturateRTC,*(undefined4 *)(param_1 + 0xe30));
                  *(int *)(param_1 + 0xe30) = *(int *)(param_1 + 0xe30) + iVar6 * 4;
                }
                ((int (*)())_PPCRuntimeCompilerWriteDestinationNO)(param_1,uVar7);
              }
LAB_97bdd85c:
              uVar7 = uVar7 + 1;
              if (uVar17 <= uVar7) break;
              puVar21 = *(uint **)(param_1 + 0xe28);
            } while( true );
          }
          iVar6 = *(int *)(param_1 + 0xe2c);
          if (iVar16 - 2000U < (uint)(*(int *)(param_1 + 0xe30) - iVar6)) {
            iVar16 = iVar16 + 0x2000;
            iVar9 = _glpDCBRealloc(iVar6,iVar16);
            *(int *)(param_1 + 0xe2c) = iVar9;
            iVar6 = iVar9 - iVar6 >> 2;
            if (iVar6 != 0) {
              iVar6 = iVar6 * 4;
              in_r10 = (int *)(*(int *)(param_1 + 0xe3c) + iVar6);
              *(int *)(param_1 + 0xe30) = *(int *)(param_1 + 0xe30) + iVar6;
              in_r8 = *(int *)(param_1 + 0xe40) + iVar6;
              *(int *)(param_1 + 0xe34) = *(int *)(param_1 + 0xe34) + iVar6;
              *(int *)(param_1 + 0xe38) = *(int *)(param_1 + 0xe38) + iVar6;
              *(int **)(param_1 + 0xe3c) = in_r10;
              *(int *)(param_1 + 0xe40) = in_r8;
            }
          }
        }
        iVar6 = *(int *)(param_1 + 0xe24);
        in_r9 = (undefined4 *)(*(int *)(param_1 + 0xe28) + 0x11c);
        if (*(int *)(param_1 + 0xe28) == *(int *)(iVar6 + 4)) {
          in_r9 = (undefined4 *)0x0;
        }
        *(undefined4 **)(param_1 + 0xe28) = in_r9;
        puVar5 = in_r9;
      }
      if ((*(int *)(iVar6 + 0x38) != 0x8804) && (*(int *)(iVar6 + 0x38) != 0x8b30)) {
        puVar5 = *(undefined4 **)(param_1 + 0xe30);
        *puVar5 = 0xc0060010;
        in_r9 = puVar5 + 1;
        *in_r9 = 0xc0260014;
        puVar5[2] = 0xc0460018;
        puVar5[3] = 0xc066001c;
        *(undefined4 **)(param_1 + 0xe30) = puVar5 + 4;
        iVar6 = _glpRTCAddAChunk_97bd7cbc(&_glpOpClippingRTC,puVar5 + 4);
        *(int *)(param_1 + 0xe30) = *(int *)(param_1 + 0xe30) + iVar6 * 4;
      }
      iVar6 = *(int *)(param_1 + 0xe48);
      if (iVar6 == 0) {
        _PPCRuntimeCompilerDirtyRegistersContainingAttributes(param_1);
        _PPCRuntimeCompilerDirtyRegistersContainingTemps(param_1);
        _PPCRuntimeCompilerDirtyRegistersContainingParams(param_1);
        iVar6 = *(int *)(param_1 + 0xe48);
        *(undefined4 *)(param_1 + 0xe38) = *(undefined4 *)(param_1 + 0xe30);
      }
      else if (iVar6 == 2) {
        ((int (*)())_PPCRuntimeCompilerStride)(param_1);
        ((int (*)())_PPCRuntimeCompilerLoop)(param_1);
        iVar6 = *(int *)(param_1 + 0xe48);
      }
    }
    *(uint *)(param_1 + 0xe48) = iVar6 + 1U;
    if (3 < iVar6 + 1U) {
      ((int (*)())_PPCRuntimeCompilerWriteEpilogNO)(param_1);
      iVar16 = *(int *)(param_1 + 0xe30) - *(int *)(param_1 + 0xe2c) >> 2;
      uVar10 = _glpDCBRealloc(*(int *)(param_1 + 0xe2c),iVar16 << 2);
      *(undefined4 *)(param_1 + 0xe2c) = uVar10;
                    
                    
      (*_glpPushInstructions)(iVar16,uVar10,in_r5,in_r6,in_r7,in_r8,in_r9,in_r10);
      return;
    }
  } while( true );
}

/* _PPCRuntimeCompilerCompileAV @ 0x97bdda38 (15728 bytes) */
int _PPCRuntimeCompilerCompileAV(param_1)
  int param_1;
{
  bool bVar1;
  char cVar2;
  byte bVar3;
  bool bVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  int iVar9;
  int *piVar10;
  int iVar11;
  uint uVar12;
  uint *puVar13;
  uint *puVar14;
  undefined4 uVar15;
  undefined *puVar16;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  undefined4 extraout_r4_02;
  undefined4 extraout_r4_03;
  undefined4 extraout_r4_04;
  undefined4 extraout_r4_05;
  undefined4 extraout_r4_06;
  undefined4 extraout_r4_07;
  undefined4 extraout_r4_08;
  undefined4 extraout_r4_09;
  undefined4 extraout_r4_10;
  undefined4 extraout_r4_11;
  undefined4 extraout_r4_12;
  undefined4 extraout_r4_13;
  undefined4 in_r5;
  undefined4 in_r6;
  int in_r7;
  int *in_r8;
  undefined4 *in_r9;
  int iVar17;
  undefined4 *puVar18;
  int *in_r10;
  int iVar19;
  uint uVar20;
  int iVar21;
  uint uVar22;
  undefined8 uVar23;
  
  _PPCRuntimeCompilerInitialise(param_1,1);
  uVar15 = _glpDCBAlloc(0x2000);
  iVar19 = 0x2000;
  *(undefined4 *)(param_1 + 0xe30) = uVar15;
  *(undefined4 *)(param_1 + 0xe2c) = uVar15;
  ((int (*)())_PPCRuntimeCompilerWritePrologAV)(param_1);
  *(undefined4 *)(param_1 + 0xe34) = *(undefined4 *)(param_1 + 0xe30);
  *(undefined4 *)(param_1 + 0xe48) = 0;
  uVar15 = extraout_r4;
  do {
    if (((1 < *(uint *)(param_1 + 0xe48)) &&
        (iVar9 = *(int *)(*(int *)(param_1 + 0xe20) + 0xd80), (*(uint *)(iVar9 + 0x3c) & 6) == 4))
       && ((*(uint *)(iVar9 + 0x34) & 0xa000) == 0)) {
      uVar23 = ((int (*)())_PPCRasterOpMachine_DepthTestRTCAV)(param_1 + 0xe14,*(undefined4 *)(param_1 + 0xe30));
      uVar15 = (undefined4)uVar23;
      *(int *)(param_1 + 0xe30) = (int)((ulonglong)uVar23 >> 0x20);
    }
    iVar9 = *(int *)(param_1 + 0xe24);
    puVar5 = *(undefined4 **)(iVar9 + 0x120);
    *(undefined4 **)(param_1 + 0xe28) = puVar5;
    while (puVar5 != (undefined4 *)0x0) {
      uVar20 = 1;
      bVar4 = true;
      piVar10 = *(int **)(param_1 + 0xe28);
      piVar10[0x46] = *(int *)(param_1 + 0xe30) - *(int *)(param_1 + 0xe2c);
      iVar21 = *piVar10;
      iVar9 = *(int *)(*(int *)(param_1 + 0xe28) + 0x30);
      cVar2 = *(char *)(piVar10 + 1);
      if (iVar9 != 0) {
        iVar17 = 0;
        do {
          iVar11 = iVar17 + *(int *)(param_1 + 0xe28);
          if ((*(char *)(iVar11 + 0x48) != '\0') &&
             (uVar12 = (uint)*(byte *)(iVar11 + 0x49), uVar20 < uVar12)) {
            uVar20 = uVar12;
          }
          iVar17 = iVar17 + 0x24;
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
      }
      if (iVar21 == 0x22) {
        _PPCRuntimeCompilerBackupRegister(param_1,2);
        _PPCRuntimeCompilerDirtyRegister(param_1,2);
        in_r9 = *(undefined4 **)(param_1 + 0xe28);
        if ((*(char *)(in_r9 + 0x12) == '\0') && (*(char *)(in_r9 + 0x1b) == '\0')) {
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,in_r9[0xd],in_r9[0xe],in_r9[0xf],in_r9[0x10],in_r9[0x11],in_r9[0x12],
                     in_r9[0x13],in_r9[0x14],in_r9[0x15],0,0);
          iVar9 = *(int *)(param_1 + 0xe28);
          in_r10 = *(int **)(iVar9 + 0x70);
          in_r5 = *(undefined4 *)(iVar9 + 0x5c);
          in_r6 = *(undefined4 *)(iVar9 + 0x60);
          in_r7 = *(int *)(iVar9 + 100);
          in_r8 = *(int **)(iVar9 + 0x68);
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar9 + 0x58),in_r5,in_r6,in_r7,in_r8,
                     *(undefined4 *)(iVar9 + 0x6c),in_r10,*(undefined4 *)(iVar9 + 0x74),
                     *(undefined4 *)(iVar9 + 0x78),0,1);
          iVar9 = _glpRTCAddAChunk_97bd7cbc(&_glpOpMulAVRTC,*(undefined4 *)(param_1 + 0xe30));
          iVar9 = *(int *)(param_1 + 0xe30) + iVar9 * 4;
          *(int *)(param_1 + 0xe30) = iVar9;
          if (cVar2 != '\0') {
            iVar9 = _glpRTCAddAChunk_97bd7cbc(&_glpOpSaturateAVRTC,iVar9);
            *(int *)(param_1 + 0xe30) = *(int *)(param_1 + 0xe30) + iVar9 * 4;
          }
LAB_97bdde9c:
          uVar15 = 0;
LAB_97bddea4:
          ((int (*)())_PPCRuntimeCompilerWriteDestinationAV)(param_1,uVar15);
          uVar15 = extraout_r4_01;
          goto LAB_97be18e4;
        }
        if (((*(char *)(in_r9 + 0x12) == '\0') || (*(char *)(in_r9 + 0x1b) == '\0')) ||
           (*(char *)((int)in_r9 + 0x49) != *(char *)((int)in_r9 + 0x6d))) {
          if ((*(char *)(in_r9 + 0x12) != '\0') && (1 < *(byte *)((int)in_r9 + 0x6d))) {
            ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,in_r9[0xd],in_r9[0xe],in_r9[0xf],in_r9[0x10],in_r9[0x11],in_r9[0x12],
                       in_r9[0x13],in_r9[0x14],in_r9[0x15],0,1);
            iVar9 = *(int *)(param_1 + 0xe28);
            in_r10 = *(int **)(iVar9 + 0x70);
            in_r5 = *(undefined4 *)(iVar9 + 0x5c);
            in_r6 = *(undefined4 *)(iVar9 + 0x60);
            in_r7 = *(int *)(iVar9 + 100);
            in_r8 = *(int **)(iVar9 + 0x68);
            ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar9 + 0x58),in_r5,in_r6,in_r7,in_r8,
                       *(undefined4 *)(iVar9 + 0x6c),in_r10,*(undefined4 *)(iVar9 + 0x74),
                       *(undefined4 *)(iVar9 + 0x78),0,0);
            if (uVar20 == 2) {
              puVar5 = *(undefined4 **)(param_1 + 0xe30);
              *puVar5 = 0x10a0028c;
              puVar5[1] = 0x1045386e;
              iVar9 = *(int *)(param_1 + 0xe28);
              *(undefined4 **)(param_1 + 0xe30) = puVar5 + 2;
              in_r10 = *(int **)(iVar9 + 0x4c);
              in_r5 = *(undefined4 *)(iVar9 + 0x38);
              in_r6 = *(undefined4 *)(iVar9 + 0x3c);
              in_r7 = *(int *)(iVar9 + 0x40);
              in_r8 = *(int **)(iVar9 + 0x44);
              ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar9 + 0x34),in_r5,in_r6,in_r7,in_r8,
                         *(undefined4 *)(iVar9 + 0x48),in_r10,*(undefined4 *)(iVar9 + 0x50),
                         *(undefined4 *)(iVar9 + 0x54),1,1);
              puVar5 = *(undefined4 **)(param_1 + 0xe30);
              *puVar5 = 0x10a1028c;
              puVar13 = puVar5 + 1;
              *puVar13 = 0x1045106e;
            }
            else {
              if (uVar20 == 3) {
                puVar5 = *(undefined4 **)(param_1 + 0xe30);
                *puVar5 = 0x10a0028c;
                puVar5[1] = 0x1045386e;
                iVar9 = *(int *)(param_1 + 0xe28);
                *(undefined4 **)(param_1 + 0xe30) = puVar5 + 2;
                ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar9 + 0x34),*(undefined4 *)(iVar9 + 0x38),
                           *(undefined4 *)(iVar9 + 0x3c),*(undefined4 *)(iVar9 + 0x40),
                           *(undefined4 *)(iVar9 + 0x44),*(undefined4 *)(iVar9 + 0x48),
                           *(undefined4 *)(iVar9 + 0x4c),*(undefined4 *)(iVar9 + 0x50),
                           *(undefined4 *)(iVar9 + 0x54),1,1);
                puVar5 = *(undefined4 **)(param_1 + 0xe30);
                *puVar5 = 0x10a1028c;
                puVar5[1] = 0x1045106e;
                iVar9 = *(int *)(param_1 + 0xe28);
                *(undefined4 **)(param_1 + 0xe30) = puVar5 + 2;
                in_r10 = *(int **)(iVar9 + 0x4c);
                in_r5 = *(undefined4 *)(iVar9 + 0x38);
                in_r6 = *(undefined4 *)(iVar9 + 0x3c);
                in_r7 = *(int *)(iVar9 + 0x40);
                in_r8 = *(int **)(iVar9 + 0x44);
                ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar9 + 0x34),in_r5,in_r6,in_r7,in_r8,
                           *(undefined4 *)(iVar9 + 0x48),in_r10,*(undefined4 *)(iVar9 + 0x50),
                           *(undefined4 *)(iVar9 + 0x54),2,1);
                puVar13 = *(uint **)(param_1 + 0xe30);
                uVar20 = 0x10a20000;
              }
              else {
                if (uVar20 != 4) goto LAB_97bdde9c;
                puVar5 = *(undefined4 **)(param_1 + 0xe30);
                *puVar5 = 0x10a0028c;
                puVar5[1] = 0x1045386e;
                iVar9 = *(int *)(param_1 + 0xe28);
                *(undefined4 **)(param_1 + 0xe30) = puVar5 + 2;
                ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar9 + 0x34),*(undefined4 *)(iVar9 + 0x38),
                           *(undefined4 *)(iVar9 + 0x3c),*(undefined4 *)(iVar9 + 0x40),
                           *(undefined4 *)(iVar9 + 0x44),*(undefined4 *)(iVar9 + 0x48),
                           *(undefined4 *)(iVar9 + 0x4c),*(undefined4 *)(iVar9 + 0x50),
                           *(undefined4 *)(iVar9 + 0x54),1,1);
                puVar5 = *(undefined4 **)(param_1 + 0xe30);
                *puVar5 = 0x10a1028c;
                puVar5[1] = 0x1045106e;
                iVar9 = *(int *)(param_1 + 0xe28);
                *(undefined4 **)(param_1 + 0xe30) = puVar5 + 2;
                ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar9 + 0x34),*(undefined4 *)(iVar9 + 0x38),
                           *(undefined4 *)(iVar9 + 0x3c),*(undefined4 *)(iVar9 + 0x40),
                           *(undefined4 *)(iVar9 + 0x44),*(undefined4 *)(iVar9 + 0x48),
                           *(undefined4 *)(iVar9 + 0x4c),*(undefined4 *)(iVar9 + 0x50),
                           *(undefined4 *)(iVar9 + 0x54),2,1);
                puVar5 = *(undefined4 **)(param_1 + 0xe30);
                *puVar5 = 0x10a2028c;
                puVar5[1] = 0x1045106e;
                iVar9 = *(int *)(param_1 + 0xe28);
                *(undefined4 **)(param_1 + 0xe30) = puVar5 + 2;
                in_r10 = *(int **)(iVar9 + 0x4c);
                in_r5 = *(undefined4 *)(iVar9 + 0x38);
                in_r6 = *(undefined4 *)(iVar9 + 0x3c);
                in_r7 = *(int *)(iVar9 + 0x40);
                in_r8 = *(int **)(iVar9 + 0x44);
                ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar9 + 0x34),in_r5,in_r6,in_r7,in_r8,
                           *(undefined4 *)(iVar9 + 0x48),in_r10,*(undefined4 *)(iVar9 + 0x50),
                           *(undefined4 *)(iVar9 + 0x54),3,1);
                puVar13 = *(uint **)(param_1 + 0xe30);
                uVar20 = 0x10a30000;
              }
              *puVar13 = uVar20 | 0x28c;
              puVar13 = puVar13 + 1;
              *puVar13 = 0x1045106e;
            }
            goto LAB_97bdde94;
          }
          if ((*(char *)(in_r9 + 0x1b) != '\0') && (1 < *(byte *)((int)in_r9 + 0x49))) {
            ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,in_r9[0x16],in_r9[0x17],in_r9[0x18],in_r9[0x19],in_r9[0x1a],
                       in_r9[0x1b],in_r9[0x1c],in_r9[0x1d],in_r9[0x1e],0,1);
            iVar9 = *(int *)(param_1 + 0xe28);
            in_r10 = *(int **)(iVar9 + 0x4c);
            in_r5 = *(undefined4 *)(iVar9 + 0x38);
            in_r6 = *(undefined4 *)(iVar9 + 0x3c);
            in_r7 = *(int *)(iVar9 + 0x40);
            in_r8 = *(int **)(iVar9 + 0x44);
            ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar9 + 0x34),in_r5,in_r6,in_r7,in_r8,
                       *(undefined4 *)(iVar9 + 0x48),in_r10,*(undefined4 *)(iVar9 + 0x50),
                       *(undefined4 *)(iVar9 + 0x54),0,0);
            if (uVar20 == 2) {
              iVar21 = _glpRTCAddAChunk_97bd7cbc(&_glpOpDp2AVRTC,*(undefined4 *)(param_1 + 0xe30));
              iVar17 = *(int *)(param_1 + 0xe30);
              *(undefined4 *)(iVar17 + iVar21 * 4) = 0x10a5112c;
              iVar9 = *(int *)(param_1 + 0xe28);
              *(int *)(param_1 + 0xe30) = iVar17 + iVar21 * 4 + 4;
              in_r5 = *(undefined4 *)(iVar9 + 0x5c);
              in_r6 = *(undefined4 *)(iVar9 + 0x60);
              in_r7 = *(int *)(iVar9 + 100);
              in_r8 = *(int **)(iVar9 + 0x68);
              ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar9 + 0x58),in_r5,in_r6,in_r7,in_r8,
                         *(undefined4 *)(iVar9 + 0x6c),*(undefined4 *)(iVar9 + 0x70),
                         *(undefined4 *)(iVar9 + 0x74),*(undefined4 *)(iVar9 + 0x78),1,1);
              iVar21 = _glpRTCAddAChunk_97bd7cbc(&_glpOpDp2AVRTC,*(undefined4 *)(param_1 + 0xe30));
              in_r10 = *(int **)(param_1 + 0xe30);
              piVar10 = in_r10 + iVar21;
              iVar9 = 0x10a5132c;
LAB_97bdeef0:
              in_r10[iVar21] = iVar9;
              piVar10[1] = 0x10452c84;
            }
            else {
              if (uVar20 == 3) {
                iVar21 = _glpRTCAddAChunk_97bd7cbc(&_glpOpDp3AVRTC,*(undefined4 *)(param_1 + 0xe30))
                ;
                iVar17 = *(int *)(param_1 + 0xe30);
                *(undefined4 *)(iVar17 + iVar21 * 4) = 0x10a5112c;
                iVar9 = *(int *)(param_1 + 0xe28);
                *(int *)(param_1 + 0xe30) = iVar17 + iVar21 * 4 + 4;
                ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar9 + 0x58),*(undefined4 *)(iVar9 + 0x5c),
                           *(undefined4 *)(iVar9 + 0x60),*(undefined4 *)(iVar9 + 100),
                           *(undefined4 *)(iVar9 + 0x68),*(undefined4 *)(iVar9 + 0x6c),
                           *(undefined4 *)(iVar9 + 0x70),*(undefined4 *)(iVar9 + 0x74),
                           *(undefined4 *)(iVar9 + 0x78),1,1);
                iVar21 = _glpRTCAddAChunk_97bd7cbc(&_glpOpDp3AVRTC,*(undefined4 *)(param_1 + 0xe30))
                ;
                iVar9 = *(int *)(param_1 + 0xe30);
                *(undefined4 *)(iVar9 + iVar21 * 4) = 0x10a5112c;
                iVar17 = *(int *)(param_1 + 0xe28);
                *(int *)(param_1 + 0xe30) = iVar9 + iVar21 * 4 + 4;
                in_r5 = *(undefined4 *)(iVar17 + 0x5c);
                in_r6 = *(undefined4 *)(iVar17 + 0x60);
                in_r7 = *(int *)(iVar17 + 100);
                in_r8 = *(int **)(iVar17 + 0x68);
                ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar17 + 0x58),in_r5,in_r6,in_r7,in_r8,
                           *(undefined4 *)(iVar17 + 0x6c),*(undefined4 *)(iVar17 + 0x70),
                           *(undefined4 *)(iVar17 + 0x74),*(undefined4 *)(iVar17 + 0x78),2,1);
                iVar21 = _glpRTCAddAChunk_97bd7cbc(&_glpOpDp3AVRTC,*(undefined4 *)(param_1 + 0xe30))
                ;
                in_r10 = *(int **)(param_1 + 0xe30);
                piVar10 = in_r10 + iVar21;
                iVar9 = 0x10a5122c;
                goto LAB_97bdeef0;
              }
              if (uVar20 != 4) goto LAB_97bdde9c;
              iVar21 = _glpRTCAddAChunk_97bd7cbc(&_glpOpDp4AVRTC,*(undefined4 *)(param_1 + 0xe30));
              iVar17 = *(int *)(param_1 + 0xe30);
              *(undefined4 *)(iVar17 + iVar21 * 4) = 0x10a5112c;
              iVar9 = *(int *)(param_1 + 0xe28);
              *(int *)(param_1 + 0xe30) = iVar17 + iVar21 * 4 + 4;
              ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar9 + 0x58),*(undefined4 *)(iVar9 + 0x5c),
                         *(undefined4 *)(iVar9 + 0x60),*(undefined4 *)(iVar9 + 100),
                         *(undefined4 *)(iVar9 + 0x68),*(undefined4 *)(iVar9 + 0x6c),
                         *(undefined4 *)(iVar9 + 0x70),*(undefined4 *)(iVar9 + 0x74),
                         *(undefined4 *)(iVar9 + 0x78),1,1);
              iVar21 = _glpRTCAddAChunk_97bd7cbc(&_glpOpDp4AVRTC,*(undefined4 *)(param_1 + 0xe30));
              iVar9 = *(int *)(param_1 + 0xe30);
              *(undefined4 *)(iVar9 + iVar21 * 4) = 0x10a5112c;
              iVar17 = *(int *)(param_1 + 0xe28);
              *(int *)(param_1 + 0xe30) = iVar9 + iVar21 * 4 + 4;
              ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar17 + 0x58),*(undefined4 *)(iVar17 + 0x5c),
                         *(undefined4 *)(iVar17 + 0x60),*(undefined4 *)(iVar17 + 100),
                         *(undefined4 *)(iVar17 + 0x68),*(undefined4 *)(iVar17 + 0x6c),
                         *(undefined4 *)(iVar17 + 0x70),*(undefined4 *)(iVar17 + 0x74),
                         *(undefined4 *)(iVar17 + 0x78),2,1);
              iVar21 = _glpRTCAddAChunk_97bd7cbc(&_glpOpDp4AVRTC,*(undefined4 *)(param_1 + 0xe30));
              iVar9 = *(int *)(param_1 + 0xe30);
              *(undefined4 *)(iVar9 + iVar21 * 4) = 0x10a5112c;
              iVar17 = *(int *)(param_1 + 0xe28);
              *(int *)(param_1 + 0xe30) = iVar9 + iVar21 * 4 + 4;
              in_r10 = *(int **)(iVar17 + 0x70);
              in_r5 = *(undefined4 *)(iVar17 + 0x5c);
              in_r6 = *(undefined4 *)(iVar17 + 0x60);
              in_r7 = *(int *)(iVar17 + 100);
              in_r8 = *(int **)(iVar17 + 0x68);
              ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar17 + 0x58),in_r5,in_r6,in_r7,in_r8,
                         *(undefined4 *)(iVar17 + 0x6c),in_r10,*(undefined4 *)(iVar17 + 0x74),
                         *(undefined4 *)(iVar17 + 0x78),3,1);
              iVar9 = _glpRTCAddAChunk_97bd7cbc(&_glpOpDp4AVRTC,*(undefined4 *)(param_1 + 0xe30));
              piVar10 = (int *)(*(int *)(param_1 + 0xe30) + iVar9 * 4);
              *(undefined4 *)(*(int *)(param_1 + 0xe30) + iVar9 * 4) = 0x10a5112c;
              piVar10[1] = 0x10452c84;
            }
            *(int **)(param_1 + 0xe30) = piVar10 + 2;
            goto LAB_97bdde9c;
          }
          if ((*(char *)(in_r9 + 0x12) == '\0') == 0) {
            iVar9 = 0x54;
          }
          else {
            iVar9 = 0x30;
          }
          iVar21 = (uint)(*(char *)(in_r9 + 0x12) == '\0') * 0x24;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)((int)in_r9 + iVar9 + 4),
                     *(undefined4 *)((int)in_r9 + iVar9 + 8),
                     *(undefined4 *)((int)in_r9 + iVar9 + 0xc),
                     *(undefined4 *)((int)in_r9 + iVar9 + 0x10),
                     *(undefined4 *)((int)in_r9 + iVar9 + 0x14),
                     *(undefined4 *)((int)in_r9 + iVar9 + 0x18),
                     *(undefined4 *)((int)in_r9 + iVar9 + 0x1c),
                     *(undefined4 *)((int)in_r9 + iVar9 + 0x20),
                     *(undefined4 *)((int)in_r9 + iVar9 + 0x24),0,0);
          iVar9 = iVar21 + *(int *)(param_1 + 0xe28);
          in_r10 = *(int **)(iVar9 + 0x4c);
          in_r5 = *(undefined4 *)(iVar9 + 0x38);
          in_r6 = *(undefined4 *)(iVar9 + 0x3c);
          in_r7 = *(int *)(iVar9 + 0x40);
          in_r8 = *(int **)(iVar9 + 0x44);
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar9 + 0x34),in_r5,in_r6,in_r7,in_r8,
                     *(undefined4 *)(iVar9 + 0x48),in_r10,*(undefined4 *)(iVar9 + 0x50),
                     *(undefined4 *)(iVar9 + 0x54),0,1);
          if (uVar20 == 2) {
            puVar5 = *(undefined4 **)(param_1 + 0xe30);
            *puVar5 = 0x1040386e;
            *(undefined4 **)(param_1 + 0xe30) = puVar5 + 1;
            ((int (*)())_PPCRuntimeCompilerWriteDestinationAV)(param_1,0);
            _PPCRuntimeCompilerBackupRegister(param_1,2);
            _PPCRuntimeCompilerDirtyRegister(param_1,2);
            iVar21 = iVar21 + *(int *)(param_1 + 0xe28);
            in_r10 = *(int **)(iVar21 + 0x4c);
            in_r5 = *(undefined4 *)(iVar21 + 0x38);
            in_r6 = *(undefined4 *)(iVar21 + 0x3c);
            in_r7 = *(int *)(iVar21 + 0x40);
            in_r8 = *(int **)(iVar21 + 0x44);
            ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar21 + 0x34),in_r5,in_r6,in_r7,in_r8,
                       *(undefined4 *)(iVar21 + 0x48),in_r10,*(undefined4 *)(iVar21 + 0x50),
                       *(undefined4 *)(iVar21 + 0x54),1,1);
            puVar5 = *(undefined4 **)(param_1 + 0xe30);
            uVar15 = 1;
          }
          else if (uVar20 == 3) {
            puVar5 = *(undefined4 **)(param_1 + 0xe30);
            *puVar5 = 0x1040386e;
            *(undefined4 **)(param_1 + 0xe30) = puVar5 + 1;
            ((int (*)())_PPCRuntimeCompilerWriteDestinationAV)(param_1,0);
            _PPCRuntimeCompilerBackupRegister(param_1,2);
            _PPCRuntimeCompilerDirtyRegister(param_1,2);
            iVar9 = iVar21 + *(int *)(param_1 + 0xe28);
            ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar9 + 0x34),*(undefined4 *)(iVar9 + 0x38),
                       *(undefined4 *)(iVar9 + 0x3c),*(undefined4 *)(iVar9 + 0x40),
                       *(undefined4 *)(iVar9 + 0x44),*(undefined4 *)(iVar9 + 0x48),
                       *(undefined4 *)(iVar9 + 0x4c),*(undefined4 *)(iVar9 + 0x50),
                       *(undefined4 *)(iVar9 + 0x54),1,1);
            puVar5 = *(undefined4 **)(param_1 + 0xe30);
            *puVar5 = 0x1040386e;
            *(undefined4 **)(param_1 + 0xe30) = puVar5 + 1;
            ((int (*)())_PPCRuntimeCompilerWriteDestinationAV)(param_1,1);
            _PPCRuntimeCompilerBackupRegister(param_1,2);
            _PPCRuntimeCompilerDirtyRegister(param_1,2);
            iVar21 = iVar21 + *(int *)(param_1 + 0xe28);
            in_r10 = *(int **)(iVar21 + 0x4c);
            in_r5 = *(undefined4 *)(iVar21 + 0x38);
            in_r6 = *(undefined4 *)(iVar21 + 0x3c);
            in_r7 = *(int *)(iVar21 + 0x40);
            in_r8 = *(int **)(iVar21 + 0x44);
            ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar21 + 0x34),in_r5,in_r6,in_r7,in_r8,
                       *(undefined4 *)(iVar21 + 0x48),in_r10,*(undefined4 *)(iVar21 + 0x50),
                       *(undefined4 *)(iVar21 + 0x54),2,1);
            puVar5 = *(undefined4 **)(param_1 + 0xe30);
            uVar15 = 2;
          }
          else {
            uVar15 = extraout_r4_02;
            if (uVar20 != 4) goto LAB_97be18e4;
            puVar5 = *(undefined4 **)(param_1 + 0xe30);
            *puVar5 = 0x1040386e;
            *(undefined4 **)(param_1 + 0xe30) = puVar5 + 1;
            ((int (*)())_PPCRuntimeCompilerWriteDestinationAV)(param_1,0);
            _PPCRuntimeCompilerBackupRegister(param_1,2);
            _PPCRuntimeCompilerDirtyRegister(param_1,2);
            iVar9 = iVar21 + *(int *)(param_1 + 0xe28);
            ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar9 + 0x34),*(undefined4 *)(iVar9 + 0x38),
                       *(undefined4 *)(iVar9 + 0x3c),*(undefined4 *)(iVar9 + 0x40),
                       *(undefined4 *)(iVar9 + 0x44),*(undefined4 *)(iVar9 + 0x48),
                       *(undefined4 *)(iVar9 + 0x4c),*(undefined4 *)(iVar9 + 0x50),
                       *(undefined4 *)(iVar9 + 0x54),1,1);
            puVar5 = *(undefined4 **)(param_1 + 0xe30);
            *puVar5 = 0x1040386e;
            *(undefined4 **)(param_1 + 0xe30) = puVar5 + 1;
            ((int (*)())_PPCRuntimeCompilerWriteDestinationAV)(param_1,1);
            _PPCRuntimeCompilerBackupRegister(param_1,2);
            _PPCRuntimeCompilerDirtyRegister(param_1,2);
            iVar9 = iVar21 + *(int *)(param_1 + 0xe28);
            ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar9 + 0x34),*(undefined4 *)(iVar9 + 0x38),
                       *(undefined4 *)(iVar9 + 0x3c),*(undefined4 *)(iVar9 + 0x40),
                       *(undefined4 *)(iVar9 + 0x44),*(undefined4 *)(iVar9 + 0x48),
                       *(undefined4 *)(iVar9 + 0x4c),*(undefined4 *)(iVar9 + 0x50),
                       *(undefined4 *)(iVar9 + 0x54),2,1);
            puVar5 = *(undefined4 **)(param_1 + 0xe30);
            *puVar5 = 0x1040386e;
            *(undefined4 **)(param_1 + 0xe30) = puVar5 + 1;
            ((int (*)())_PPCRuntimeCompilerWriteDestinationAV)(param_1,2);
            _PPCRuntimeCompilerBackupRegister(param_1,2);
            _PPCRuntimeCompilerDirtyRegister(param_1,2);
            iVar21 = iVar21 + *(int *)(param_1 + 0xe28);
            in_r10 = *(int **)(iVar21 + 0x4c);
            in_r5 = *(undefined4 *)(iVar21 + 0x38);
            in_r6 = *(undefined4 *)(iVar21 + 0x3c);
            in_r7 = *(int *)(iVar21 + 0x40);
            in_r8 = *(int **)(iVar21 + 0x44);
            ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar21 + 0x34),in_r5,in_r6,in_r7,in_r8,
                       *(undefined4 *)(iVar21 + 0x48),in_r10,*(undefined4 *)(iVar21 + 0x50),
                       *(undefined4 *)(iVar21 + 0x54),3,1);
            puVar5 = *(undefined4 **)(param_1 + 0xe30);
            uVar15 = 3;
          }
          *puVar5 = 0x1040386e;
          *(undefined4 **)(param_1 + 0xe30) = puVar5 + 1;
          goto LAB_97bddea4;
        }
        if (uVar20 == 2) {
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,in_r9[0xd],in_r9[0xe],in_r9[0xf],in_r9[0x10],in_r9[0x11],in_r9[0x12],
                     in_r9[0x13],in_r9[0x14],in_r9[0x15],0,0);
          iVar9 = *(int *)(param_1 + 0xe28);
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar9 + 0x58),*(undefined4 *)(iVar9 + 0x5c),
                     *(undefined4 *)(iVar9 + 0x60),*(undefined4 *)(iVar9 + 100),
                     *(undefined4 *)(iVar9 + 0x68),*(undefined4 *)(iVar9 + 0x6c),
                     *(undefined4 *)(iVar9 + 0x70),*(undefined4 *)(iVar9 + 0x74),
                     *(undefined4 *)(iVar9 + 0x78),0,1);
          puVar5 = *(undefined4 **)(param_1 + 0xe30);
          *puVar5 = 0x10c00a8c;
          puVar5[1] = 0x104039ae;
          iVar9 = *(int *)(param_1 + 0xe28);
          *(undefined4 **)(param_1 + 0xe30) = puVar5 + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar9 + 0x34),*(undefined4 *)(iVar9 + 0x38),
                     *(undefined4 *)(iVar9 + 0x3c),*(undefined4 *)(iVar9 + 0x40),
                     *(undefined4 *)(iVar9 + 0x44),*(undefined4 *)(iVar9 + 0x48),
                     *(undefined4 *)(iVar9 + 0x4c),*(undefined4 *)(iVar9 + 0x50),
                     *(undefined4 *)(iVar9 + 0x54),1,0);
          puVar5 = *(undefined4 **)(param_1 + 0xe30);
          *puVar5 = 0x10c10a8c;
          puVar5[1] = 0x104011ae;
          puVar5[2] = 0x3b000210;
          puVar5[3] = 0x7c43c1ce;
          iVar9 = *(int *)(param_1 + 0xe28);
          *(undefined4 **)(param_1 + 0xe30) = puVar5 + 4;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar9 + 0x58),*(undefined4 *)(iVar9 + 0x5c),
                     *(undefined4 *)(iVar9 + 0x60),*(undefined4 *)(iVar9 + 100),
                     *(undefined4 *)(iVar9 + 0x68),*(undefined4 *)(iVar9 + 0x6c),
                     *(undefined4 *)(iVar9 + 0x70),*(undefined4 *)(iVar9 + 0x74),
                     *(undefined4 *)(iVar9 + 0x78),1,1);
          puVar5 = *(undefined4 **)(param_1 + 0xe30);
          *puVar5 = 0x10c10a8c;
          puVar5[1] = 0x104039ae;
          iVar9 = *(int *)(param_1 + 0xe28);
          *(undefined4 **)(param_1 + 0xe30) = puVar5 + 2;
          in_r10 = *(int **)(iVar9 + 0x4c);
          in_r5 = *(undefined4 *)(iVar9 + 0x38);
          in_r6 = *(undefined4 *)(iVar9 + 0x3c);
          in_r7 = *(int *)(iVar9 + 0x40);
          in_r8 = *(int **)(iVar9 + 0x44);
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar9 + 0x34),in_r5,in_r6,in_r7,in_r8,
                     *(undefined4 *)(iVar9 + 0x48),in_r10,*(undefined4 *)(iVar9 + 0x50),
                     *(undefined4 *)(iVar9 + 0x54),0,0);
          puVar5 = *(undefined4 **)(param_1 + 0xe30);
          *puVar5 = 0x10c00a8c;
          puVar5 = puVar5 + 1;
          *puVar5 = 0x104011ae;
LAB_97bdde5c:
          *(undefined4 **)(param_1 + 0xe30) = puVar5 + 1;
          ((int (*)())_PPCRuntimeCompilerWriteDestinationAV)(param_1,1);
          _PPCRuntimeCompilerBackupRegister(param_1,2);
          _PPCRuntimeCompilerDirtyRegister(param_1,2);
          puVar13 = *(uint **)(param_1 + 0xe30);
          uVar20 = 0x7c43c0ce;
          goto LAB_97bdde90;
        }
        if (uVar20 == 3) {
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,in_r9[0xd],in_r9[0xe],in_r9[0xf],in_r9[0x10],in_r9[0x11],in_r9[0x12],
                     in_r9[0x13],in_r9[0x14],in_r9[0x15],0,0);
          iVar9 = *(int *)(param_1 + 0xe28);
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar9 + 0x58),*(undefined4 *)(iVar9 + 0x5c),
                     *(undefined4 *)(iVar9 + 0x60),*(undefined4 *)(iVar9 + 100),
                     *(undefined4 *)(iVar9 + 0x68),*(undefined4 *)(iVar9 + 0x6c),
                     *(undefined4 *)(iVar9 + 0x70),*(undefined4 *)(iVar9 + 0x74),
                     *(undefined4 *)(iVar9 + 0x78),0,1);
          puVar5 = *(undefined4 **)(param_1 + 0xe30);
          *puVar5 = 0x10c00a8c;
          puVar5[1] = 0x104039ae;
          iVar9 = *(int *)(param_1 + 0xe28);
          *(undefined4 **)(param_1 + 0xe30) = puVar5 + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar9 + 0x34),*(undefined4 *)(iVar9 + 0x38),
                     *(undefined4 *)(iVar9 + 0x3c),*(undefined4 *)(iVar9 + 0x40),
                     *(undefined4 *)(iVar9 + 0x44),*(undefined4 *)(iVar9 + 0x48),
                     *(undefined4 *)(iVar9 + 0x4c),*(undefined4 *)(iVar9 + 0x50),
                     *(undefined4 *)(iVar9 + 0x54),1,0);
          puVar5 = *(undefined4 **)(param_1 + 0xe30);
          *puVar5 = 0x10c10a8c;
          puVar5[1] = 0x104011ae;
          iVar9 = *(int *)(param_1 + 0xe28);
          *(undefined4 **)(param_1 + 0xe30) = puVar5 + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar9 + 0x34),*(undefined4 *)(iVar9 + 0x38),
                     *(undefined4 *)(iVar9 + 0x3c),*(undefined4 *)(iVar9 + 0x40),
                     *(undefined4 *)(iVar9 + 0x44),*(undefined4 *)(iVar9 + 0x48),
                     *(undefined4 *)(iVar9 + 0x4c),*(undefined4 *)(iVar9 + 0x50),
                     *(undefined4 *)(iVar9 + 0x54),2,0);
          puVar5 = *(undefined4 **)(param_1 + 0xe30);
          *puVar5 = 0x10c20a8c;
          puVar5[1] = 0x104011ae;
          puVar5[2] = 0x3b000210;
          puVar5[3] = 0x7c43c1ce;
          iVar9 = *(int *)(param_1 + 0xe28);
          *(undefined4 **)(param_1 + 0xe30) = puVar5 + 4;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar9 + 0x58),*(undefined4 *)(iVar9 + 0x5c),
                     *(undefined4 *)(iVar9 + 0x60),*(undefined4 *)(iVar9 + 100),
                     *(undefined4 *)(iVar9 + 0x68),*(undefined4 *)(iVar9 + 0x6c),
                     *(undefined4 *)(iVar9 + 0x70),*(undefined4 *)(iVar9 + 0x74),
                     *(undefined4 *)(iVar9 + 0x78),1,1);
          puVar5 = *(undefined4 **)(param_1 + 0xe30);
          *puVar5 = 0x10c20a8c;
          puVar5[1] = 0x104039ae;
          iVar9 = *(int *)(param_1 + 0xe28);
          *(undefined4 **)(param_1 + 0xe30) = puVar5 + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar9 + 0x34),*(undefined4 *)(iVar9 + 0x38),
                     *(undefined4 *)(iVar9 + 0x3c),*(undefined4 *)(iVar9 + 0x40),
                     *(undefined4 *)(iVar9 + 0x44),*(undefined4 *)(iVar9 + 0x48),
                     *(undefined4 *)(iVar9 + 0x4c),*(undefined4 *)(iVar9 + 0x50),
                     *(undefined4 *)(iVar9 + 0x54),1,0);
          puVar5 = *(undefined4 **)(param_1 + 0xe30);
          *puVar5 = 0x10c10a8c;
          puVar5[1] = 0x104011ae;
          iVar9 = *(int *)(param_1 + 0xe28);
          *(undefined4 **)(param_1 + 0xe30) = puVar5 + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar9 + 0x34),*(undefined4 *)(iVar9 + 0x38),
                     *(undefined4 *)(iVar9 + 0x3c),*(undefined4 *)(iVar9 + 0x40),
                     *(undefined4 *)(iVar9 + 0x44),*(undefined4 *)(iVar9 + 0x48),
                     *(undefined4 *)(iVar9 + 0x4c),*(undefined4 *)(iVar9 + 0x50),
                     *(undefined4 *)(iVar9 + 0x54),0,0);
          puVar5 = *(undefined4 **)(param_1 + 0xe30);
          *puVar5 = 0x10c00a8c;
          puVar5[1] = 0x104011ae;
          puVar5[2] = 0x3b200220;
          puVar5[3] = 0x7c43c9ce;
          iVar9 = *(int *)(param_1 + 0xe28);
          *(undefined4 **)(param_1 + 0xe30) = puVar5 + 4;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar9 + 0x58),*(undefined4 *)(iVar9 + 0x5c),
                     *(undefined4 *)(iVar9 + 0x60),*(undefined4 *)(iVar9 + 100),
                     *(undefined4 *)(iVar9 + 0x68),*(undefined4 *)(iVar9 + 0x6c),
                     *(undefined4 *)(iVar9 + 0x70),*(undefined4 *)(iVar9 + 0x74),
                     *(undefined4 *)(iVar9 + 0x78),2,1);
          puVar5 = *(undefined4 **)(param_1 + 0xe30);
          *puVar5 = 0x10c00a8c;
          puVar5[1] = 0x104039ae;
          iVar9 = *(int *)(param_1 + 0xe28);
          *(undefined4 **)(param_1 + 0xe30) = puVar5 + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar9 + 0x34),*(undefined4 *)(iVar9 + 0x38),
                     *(undefined4 *)(iVar9 + 0x3c),*(undefined4 *)(iVar9 + 0x40),
                     *(undefined4 *)(iVar9 + 0x44),*(undefined4 *)(iVar9 + 0x48),
                     *(undefined4 *)(iVar9 + 0x4c),*(undefined4 *)(iVar9 + 0x50),
                     *(undefined4 *)(iVar9 + 0x54),1,0);
          puVar5 = *(undefined4 **)(param_1 + 0xe30);
          *puVar5 = 0x10c10a8c;
          puVar5[1] = 0x104011ae;
          iVar9 = *(int *)(param_1 + 0xe28);
          *(undefined4 **)(param_1 + 0xe30) = puVar5 + 2;
          in_r10 = *(int **)(iVar9 + 0x4c);
          in_r5 = *(undefined4 *)(iVar9 + 0x38);
          in_r6 = *(undefined4 *)(iVar9 + 0x3c);
          in_r7 = *(int *)(iVar9 + 0x40);
          in_r8 = *(int **)(iVar9 + 0x44);
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar9 + 0x34),in_r5,in_r6,in_r7,in_r8,
                     *(undefined4 *)(iVar9 + 0x48),in_r10,*(undefined4 *)(iVar9 + 0x50),
                     *(undefined4 *)(iVar9 + 0x54),2,0);
          puVar5 = *(undefined4 **)(param_1 + 0xe30);
          *puVar5 = 0x10c20a8c;
          puVar5[1] = 0x104011ae;
          *(undefined4 **)(param_1 + 0xe30) = puVar5 + 2;
          ((int (*)())_PPCRuntimeCompilerWriteDestinationAV)(param_1,2);
          _PPCRuntimeCompilerBackupRegister(param_1,2);
          _PPCRuntimeCompilerDirtyRegister(param_1,2);
          puVar5 = *(undefined4 **)(param_1 + 0xe30);
          *puVar5 = 0x7c43c8ce;
          goto LAB_97bdde5c;
        }
        uVar15 = extraout_r4_00;
        if (uVar20 == 4) {
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,in_r9[0xd],in_r9[0xe],in_r9[0xf],in_r9[0x10],in_r9[0x11],in_r9[0x12],
                     in_r9[0x13],in_r9[0x14],in_r9[0x15],0,0);
          iVar9 = *(int *)(param_1 + 0xe28);
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar9 + 0x58),*(undefined4 *)(iVar9 + 0x5c),
                     *(undefined4 *)(iVar9 + 0x60),*(undefined4 *)(iVar9 + 100),
                     *(undefined4 *)(iVar9 + 0x68),*(undefined4 *)(iVar9 + 0x6c),
                     *(undefined4 *)(iVar9 + 0x70),*(undefined4 *)(iVar9 + 0x74),
                     *(undefined4 *)(iVar9 + 0x78),0,1);
          puVar5 = *(undefined4 **)(param_1 + 0xe30);
          *puVar5 = 0x10c00a8c;
          puVar5[1] = 0x104039ae;
          iVar9 = *(int *)(param_1 + 0xe28);
          *(undefined4 **)(param_1 + 0xe30) = puVar5 + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar9 + 0x34),*(undefined4 *)(iVar9 + 0x38),
                     *(undefined4 *)(iVar9 + 0x3c),*(undefined4 *)(iVar9 + 0x40),
                     *(undefined4 *)(iVar9 + 0x44),*(undefined4 *)(iVar9 + 0x48),
                     *(undefined4 *)(iVar9 + 0x4c),*(undefined4 *)(iVar9 + 0x50),
                     *(undefined4 *)(iVar9 + 0x54),1,0);
          puVar5 = *(undefined4 **)(param_1 + 0xe30);
          *puVar5 = 0x10c10a8c;
          puVar5[1] = 0x104011ae;
          iVar9 = *(int *)(param_1 + 0xe28);
          *(undefined4 **)(param_1 + 0xe30) = puVar5 + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar9 + 0x34),*(undefined4 *)(iVar9 + 0x38),
                     *(undefined4 *)(iVar9 + 0x3c),*(undefined4 *)(iVar9 + 0x40),
                     *(undefined4 *)(iVar9 + 0x44),*(undefined4 *)(iVar9 + 0x48),
                     *(undefined4 *)(iVar9 + 0x4c),*(undefined4 *)(iVar9 + 0x50),
                     *(undefined4 *)(iVar9 + 0x54),2,0);
          puVar5 = *(undefined4 **)(param_1 + 0xe30);
          *puVar5 = 0x10c20a8c;
          puVar5[1] = 0x104011ae;
          iVar9 = *(int *)(param_1 + 0xe28);
          *(undefined4 **)(param_1 + 0xe30) = puVar5 + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar9 + 0x34),*(undefined4 *)(iVar9 + 0x38),
                     *(undefined4 *)(iVar9 + 0x3c),*(undefined4 *)(iVar9 + 0x40),
                     *(undefined4 *)(iVar9 + 0x44),*(undefined4 *)(iVar9 + 0x48),
                     *(undefined4 *)(iVar9 + 0x4c),*(undefined4 *)(iVar9 + 0x50),
                     *(undefined4 *)(iVar9 + 0x54),3,0);
          puVar5 = *(undefined4 **)(param_1 + 0xe30);
          *puVar5 = 0x10c30a8c;
          puVar5[1] = 0x104011ae;
          puVar5[2] = 0x3ae00210;
          puVar5[3] = 0x7c43b9ce;
          iVar9 = *(int *)(param_1 + 0xe28);
          *(undefined4 **)(param_1 + 0xe30) = puVar5 + 4;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar9 + 0x58),*(undefined4 *)(iVar9 + 0x5c),
                     *(undefined4 *)(iVar9 + 0x60),*(undefined4 *)(iVar9 + 100),
                     *(undefined4 *)(iVar9 + 0x68),*(undefined4 *)(iVar9 + 0x6c),
                     *(undefined4 *)(iVar9 + 0x70),*(undefined4 *)(iVar9 + 0x74),
                     *(undefined4 *)(iVar9 + 0x78),1,1);
          puVar5 = *(undefined4 **)(param_1 + 0xe30);
          *puVar5 = 0x10c30a8c;
          puVar5[1] = 0x104039ae;
          iVar9 = *(int *)(param_1 + 0xe28);
          *(undefined4 **)(param_1 + 0xe30) = puVar5 + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar9 + 0x34),*(undefined4 *)(iVar9 + 0x38),
                     *(undefined4 *)(iVar9 + 0x3c),*(undefined4 *)(iVar9 + 0x40),
                     *(undefined4 *)(iVar9 + 0x44),*(undefined4 *)(iVar9 + 0x48),
                     *(undefined4 *)(iVar9 + 0x4c),*(undefined4 *)(iVar9 + 0x50),
                     *(undefined4 *)(iVar9 + 0x54),2,0);
          puVar5 = *(undefined4 **)(param_1 + 0xe30);
          *puVar5 = 0x10c20a8c;
          puVar5[1] = 0x104011ae;
          iVar9 = *(int *)(param_1 + 0xe28);
          *(undefined4 **)(param_1 + 0xe30) = puVar5 + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar9 + 0x34),*(undefined4 *)(iVar9 + 0x38),
                     *(undefined4 *)(iVar9 + 0x3c),*(undefined4 *)(iVar9 + 0x40),
                     *(undefined4 *)(iVar9 + 0x44),*(undefined4 *)(iVar9 + 0x48),
                     *(undefined4 *)(iVar9 + 0x4c),*(undefined4 *)(iVar9 + 0x50),
                     *(undefined4 *)(iVar9 + 0x54),1,0);
          puVar5 = *(undefined4 **)(param_1 + 0xe30);
          *puVar5 = 0x10c10a8c;
          puVar5[1] = 0x104011ae;
          iVar9 = *(int *)(param_1 + 0xe28);
          *(undefined4 **)(param_1 + 0xe30) = puVar5 + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar9 + 0x34),*(undefined4 *)(iVar9 + 0x38),
                     *(undefined4 *)(iVar9 + 0x3c),*(undefined4 *)(iVar9 + 0x40),
                     *(undefined4 *)(iVar9 + 0x44),*(undefined4 *)(iVar9 + 0x48),
                     *(undefined4 *)(iVar9 + 0x4c),*(undefined4 *)(iVar9 + 0x50),
                     *(undefined4 *)(iVar9 + 0x54),0,0);
          puVar5 = *(undefined4 **)(param_1 + 0xe30);
          *puVar5 = 0x10c00a8c;
          puVar5[1] = 0x104011ae;
          puVar5[2] = 0x3b000220;
          puVar5[3] = 0x7c43c1ce;
          iVar9 = *(int *)(param_1 + 0xe28);
          *(undefined4 **)(param_1 + 0xe30) = puVar5 + 4;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar9 + 0x58),*(undefined4 *)(iVar9 + 0x5c),
                     *(undefined4 *)(iVar9 + 0x60),*(undefined4 *)(iVar9 + 100),
                     *(undefined4 *)(iVar9 + 0x68),*(undefined4 *)(iVar9 + 0x6c),
                     *(undefined4 *)(iVar9 + 0x70),*(undefined4 *)(iVar9 + 0x74),
                     *(undefined4 *)(iVar9 + 0x78),2,1);
          puVar5 = *(undefined4 **)(param_1 + 0xe30);
          *puVar5 = 0x10c00a8c;
          puVar5[1] = 0x104039ae;
          iVar9 = *(int *)(param_1 + 0xe28);
          *(undefined4 **)(param_1 + 0xe30) = puVar5 + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar9 + 0x34),*(undefined4 *)(iVar9 + 0x38),
                     *(undefined4 *)(iVar9 + 0x3c),*(undefined4 *)(iVar9 + 0x40),
                     *(undefined4 *)(iVar9 + 0x44),*(undefined4 *)(iVar9 + 0x48),
                     *(undefined4 *)(iVar9 + 0x4c),*(undefined4 *)(iVar9 + 0x50),
                     *(undefined4 *)(iVar9 + 0x54),1,0);
          puVar5 = *(undefined4 **)(param_1 + 0xe30);
          *puVar5 = 0x10c10a8c;
          puVar5[1] = 0x104011ae;
          iVar9 = *(int *)(param_1 + 0xe28);
          *(undefined4 **)(param_1 + 0xe30) = puVar5 + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar9 + 0x34),*(undefined4 *)(iVar9 + 0x38),
                     *(undefined4 *)(iVar9 + 0x3c),*(undefined4 *)(iVar9 + 0x40),
                     *(undefined4 *)(iVar9 + 0x44),*(undefined4 *)(iVar9 + 0x48),
                     *(undefined4 *)(iVar9 + 0x4c),*(undefined4 *)(iVar9 + 0x50),
                     *(undefined4 *)(iVar9 + 0x54),2,0);
          puVar5 = *(undefined4 **)(param_1 + 0xe30);
          *puVar5 = 0x10c20a8c;
          puVar5[1] = 0x104011ae;
          iVar9 = *(int *)(param_1 + 0xe28);
          *(undefined4 **)(param_1 + 0xe30) = puVar5 + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar9 + 0x34),*(undefined4 *)(iVar9 + 0x38),
                     *(undefined4 *)(iVar9 + 0x3c),*(undefined4 *)(iVar9 + 0x40),
                     *(undefined4 *)(iVar9 + 0x44),*(undefined4 *)(iVar9 + 0x48),
                     *(undefined4 *)(iVar9 + 0x4c),*(undefined4 *)(iVar9 + 0x50),
                     *(undefined4 *)(iVar9 + 0x54),3,0);
          puVar5 = *(undefined4 **)(param_1 + 0xe30);
          *puVar5 = 0x10c30a8c;
          puVar5[1] = 0x104011ae;
          puVar5[2] = 0x3b200230;
          puVar5[3] = 0x7c43c9ce;
          iVar9 = *(int *)(param_1 + 0xe28);
          *(undefined4 **)(param_1 + 0xe30) = puVar5 + 4;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar9 + 0x58),*(undefined4 *)(iVar9 + 0x5c),
                     *(undefined4 *)(iVar9 + 0x60),*(undefined4 *)(iVar9 + 100),
                     *(undefined4 *)(iVar9 + 0x68),*(undefined4 *)(iVar9 + 0x6c),
                     *(undefined4 *)(iVar9 + 0x70),*(undefined4 *)(iVar9 + 0x74),
                     *(undefined4 *)(iVar9 + 0x78),3,1);
          puVar5 = *(undefined4 **)(param_1 + 0xe30);
          *puVar5 = 0x10c30a8c;
          puVar5[1] = 0x104039ae;
          iVar9 = *(int *)(param_1 + 0xe28);
          *(undefined4 **)(param_1 + 0xe30) = puVar5 + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar9 + 0x34),*(undefined4 *)(iVar9 + 0x38),
                     *(undefined4 *)(iVar9 + 0x3c),*(undefined4 *)(iVar9 + 0x40),
                     *(undefined4 *)(iVar9 + 0x44),*(undefined4 *)(iVar9 + 0x48),
                     *(undefined4 *)(iVar9 + 0x4c),*(undefined4 *)(iVar9 + 0x50),
                     *(undefined4 *)(iVar9 + 0x54),2,0);
          puVar5 = *(undefined4 **)(param_1 + 0xe30);
          *puVar5 = 0x10c20a8c;
          puVar5[1] = 0x104011ae;
          iVar9 = *(int *)(param_1 + 0xe28);
          *(undefined4 **)(param_1 + 0xe30) = puVar5 + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar9 + 0x34),*(undefined4 *)(iVar9 + 0x38),
                     *(undefined4 *)(iVar9 + 0x3c),*(undefined4 *)(iVar9 + 0x40),
                     *(undefined4 *)(iVar9 + 0x44),*(undefined4 *)(iVar9 + 0x48),
                     *(undefined4 *)(iVar9 + 0x4c),*(undefined4 *)(iVar9 + 0x50),
                     *(undefined4 *)(iVar9 + 0x54),1,0);
          puVar5 = *(undefined4 **)(param_1 + 0xe30);
          *puVar5 = 0x10c10a8c;
          puVar5[1] = 0x104011ae;
          iVar9 = *(int *)(param_1 + 0xe28);
          *(undefined4 **)(param_1 + 0xe30) = puVar5 + 2;
          in_r10 = *(int **)(iVar9 + 0x4c);
          in_r5 = *(undefined4 *)(iVar9 + 0x38);
          in_r6 = *(undefined4 *)(iVar9 + 0x3c);
          in_r7 = *(int *)(iVar9 + 0x40);
          in_r8 = *(int **)(iVar9 + 0x44);
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar9 + 0x34),in_r5,in_r6,in_r7,in_r8,
                     *(undefined4 *)(iVar9 + 0x48),in_r10,*(undefined4 *)(iVar9 + 0x50),
                     *(undefined4 *)(iVar9 + 0x54),0,0);
          puVar5 = *(undefined4 **)(param_1 + 0xe30);
          *puVar5 = 0x10c00a8c;
          puVar5[1] = 0x104011ae;
          *(undefined4 **)(param_1 + 0xe30) = puVar5 + 2;
          ((int (*)())_PPCRuntimeCompilerWriteDestinationAV)(param_1,3);
          _PPCRuntimeCompilerBackupRegister(param_1,2);
          _PPCRuntimeCompilerDirtyRegister(param_1,2);
          puVar5 = *(undefined4 **)(param_1 + 0xe30);
          *puVar5 = 0x7c43c8ce;
          *(undefined4 **)(param_1 + 0xe30) = puVar5 + 1;
          ((int (*)())_PPCRuntimeCompilerWriteDestinationAV)(param_1,2);
          _PPCRuntimeCompilerBackupRegister(param_1,2);
          _PPCRuntimeCompilerDirtyRegister(param_1,2);
          puVar5 = *(undefined4 **)(param_1 + 0xe30);
          *puVar5 = 0x7c43c0ce;
          *(undefined4 **)(param_1 + 0xe30) = puVar5 + 1;
          ((int (*)())_PPCRuntimeCompilerWriteDestinationAV)(param_1,1);
          _PPCRuntimeCompilerBackupRegister(param_1,2);
          _PPCRuntimeCompilerDirtyRegister(param_1,2);
          puVar13 = *(uint **)(param_1 + 0xe30);
          uVar20 = 0x7c43b8ce;
          goto LAB_97bdde90;
        }
      }
      else {
        if ((iVar21 == 0x31) || (iVar21 == 0x36)) {
          _PPCRuntimeCompilerBackupRegister(param_1,2);
          _PPCRuntimeCompilerDirtyRegister(param_1,2);
          if (uVar20 < 2) {
            iVar9 = *(int *)(param_1 + 0xe28);
            ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar9 + 0x34),*(undefined4 *)(iVar9 + 0x38),
                       *(undefined4 *)(iVar9 + 0x3c),*(undefined4 *)(iVar9 + 0x40),
                       *(undefined4 *)(iVar9 + 0x44),*(undefined4 *)(iVar9 + 0x48),
                       *(undefined4 *)(iVar9 + 0x4c),*(undefined4 *)(iVar9 + 0x50),
                       *(undefined4 *)(iVar9 + 0x54),0,0);
            iVar9 = *(int *)(param_1 + 0xe28);
            in_r10 = *(int **)(iVar9 + 0x70);
            in_r5 = *(undefined4 *)(iVar9 + 0x5c);
            in_r6 = *(undefined4 *)(iVar9 + 0x60);
            in_r7 = *(int *)(iVar9 + 100);
            in_r8 = *(int **)(iVar9 + 0x68);
            ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar9 + 0x58),in_r5,in_r6,in_r7,in_r8,
                       *(undefined4 *)(iVar9 + 0x6c),in_r10,*(undefined4 *)(iVar9 + 0x74),
                       *(undefined4 *)(iVar9 + 0x78),0,1);
            if (*(char *)(*(int *)(param_1 + 0xe28) + 0x21) == '\x01') {
              cVar2 = *(char *)(*(int *)(param_1 + 0xe28) + 5);
              if (cVar2 == '\x01') {
                puVar5 = *(undefined4 **)(param_1 + 0xe30);
                puVar16 = &_glpOpSetAllEqualTo1AVRTC;
              }
              else if (cVar2 == '\x02') {
                puVar5 = *(undefined4 **)(param_1 + 0xe30);
                puVar16 = &_glpOpSetAllEqualTo2AVRTC;
              }
              else if (cVar2 == '\x03') {
                puVar5 = *(undefined4 **)(param_1 + 0xe30);
                puVar16 = &_glpOpSetAllEqualTo3AVRTC;
              }
              else {
                if (cVar2 != '\x04') goto LAB_97bdf944;
                puVar5 = *(undefined4 **)(param_1 + 0xe30);
                puVar16 = &_glpOpSetAllEqualTo4AVRTC;
              }
            }
            else {
              puVar5 = *(undefined4 **)(param_1 + 0xe30);
              puVar16 = &_glpOpSetEqualToAVRTC;
            }
LAB_97bdf930:
            iVar9 = _glpRTCAddAChunk_97bd7cbc(puVar16,puVar5);
            *(int *)(param_1 + 0xe30) = *(int *)(param_1 + 0xe30) + iVar9 * 4;
          }
          else {
            puVar5 = *(undefined4 **)(param_1 + 0xe30);
            *puVar5 = 0x10a84484;
            *(undefined4 **)(param_1 + 0xe30) = puVar5 + 1;
            if (uVar20 == 3) {
              uVar20 = 0;
              do {
                iVar9 = *(int *)(param_1 + 0xe28);
                uVar12 = uVar20;
                if (*(char *)(iVar9 + 0x48) == '\0') {
                  uVar12 = 0;
                }
                ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar9 + 0x34),*(undefined4 *)(iVar9 + 0x38),
                           *(undefined4 *)(iVar9 + 0x3c),*(undefined4 *)(iVar9 + 0x40),
                           *(undefined4 *)(iVar9 + 0x44),*(undefined4 *)(iVar9 + 0x48),
                           *(undefined4 *)(iVar9 + 0x4c),*(undefined4 *)(iVar9 + 0x50),
                           *(undefined4 *)(iVar9 + 0x54),uVar12,0);
                iVar9 = *(int *)(param_1 + 0xe28);
                uVar12 = uVar20;
                if (*(char *)(iVar9 + 0x6c) == '\0') {
                  uVar12 = 0;
                }
                uVar20 = uVar20 + 1;
                in_r10 = *(int **)(iVar9 + 0x70);
                in_r5 = *(undefined4 *)(iVar9 + 0x5c);
                in_r6 = *(undefined4 *)(iVar9 + 0x60);
                in_r7 = *(int *)(iVar9 + 100);
                in_r8 = *(int **)(iVar9 + 0x68);
                ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar9 + 0x58),in_r5,in_r6,in_r7,in_r8,
                           *(undefined4 *)(iVar9 + 0x6c),in_r10,*(undefined4 *)(iVar9 + 0x74),
                           *(undefined4 *)(iVar9 + 0x78),uVar12,1);
                iVar9 = _glpRTCAddAChunk_97bd7cbc
                                  (&_glpOpSetAllEqualTo3AVRTC,*(undefined4 *)(param_1 + 0xe30));
                iVar17 = *(int *)(param_1 + 0xe30);
                *(undefined4 *)(iVar17 + iVar9 * 4) = 0x10a5112c;
                *(int *)(param_1 + 0xe30) = iVar17 + iVar9 * 4 + 4;
              } while (uVar20 < 3);
LAB_97bdf7ec:
              _PPCRuntimeCompilerBackupRegister(param_1,0);
              _PPCRuntimeCompilerDirtyRegister(param_1,0);
              puVar5 = *(undefined4 **)(param_1 + 0xe30);
              puVar16 = &_glpOpAllAVRTC;
              *puVar5 = 0x10052c84;
              puVar5 = puVar5 + 1;
              *(undefined4 **)(param_1 + 0xe30) = puVar5;
              goto LAB_97bdf930;
            }
            if (uVar20 < 4) {
              if (uVar20 == 2) {
                uVar20 = 0;
                do {
                  iVar9 = *(int *)(param_1 + 0xe28);
                  uVar12 = uVar20;
                  if (*(char *)(iVar9 + 0x48) == '\0') {
                    uVar12 = 0;
                  }
                  ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar9 + 0x34),*(undefined4 *)(iVar9 + 0x38),
                             *(undefined4 *)(iVar9 + 0x3c),*(undefined4 *)(iVar9 + 0x40),
                             *(undefined4 *)(iVar9 + 0x44),*(undefined4 *)(iVar9 + 0x48),
                             *(undefined4 *)(iVar9 + 0x4c),*(undefined4 *)(iVar9 + 0x50),
                             *(undefined4 *)(iVar9 + 0x54),uVar12,0);
                  iVar9 = *(int *)(param_1 + 0xe28);
                  uVar12 = uVar20;
                  if (*(char *)(iVar9 + 0x6c) == '\0') {
                    uVar12 = 0;
                  }
                  uVar20 = uVar20 + 1;
                  in_r10 = *(int **)(iVar9 + 0x70);
                  in_r5 = *(undefined4 *)(iVar9 + 0x5c);
                  in_r6 = *(undefined4 *)(iVar9 + 0x60);
                  in_r7 = *(int *)(iVar9 + 100);
                  in_r8 = *(int **)(iVar9 + 0x68);
                  ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar9 + 0x58),in_r5,in_r6,in_r7,in_r8,
                             *(undefined4 *)(iVar9 + 0x6c),in_r10,*(undefined4 *)(iVar9 + 0x74),
                             *(undefined4 *)(iVar9 + 0x78),uVar12,1);
                  iVar9 = _glpRTCAddAChunk_97bd7cbc
                                    (&_glpOpSetAllEqualTo2AVRTC,*(undefined4 *)(param_1 + 0xe30));
                  iVar17 = *(int *)(param_1 + 0xe30);
                  *(undefined4 *)(iVar17 + iVar9 * 4) = 0x10a5112c;
                  *(int *)(param_1 + 0xe30) = iVar17 + iVar9 * 4 + 4;
                } while (uVar20 < 2);
                goto LAB_97bdf7ec;
              }
            }
            else if (uVar20 == 4) {
              uVar20 = 0;
              do {
                iVar9 = *(int *)(param_1 + 0xe28);
                uVar12 = uVar20;
                if (*(char *)(iVar9 + 0x48) == '\0') {
                  uVar12 = 0;
                }
                ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar9 + 0x34),*(undefined4 *)(iVar9 + 0x38),
                           *(undefined4 *)(iVar9 + 0x3c),*(undefined4 *)(iVar9 + 0x40),
                           *(undefined4 *)(iVar9 + 0x44),*(undefined4 *)(iVar9 + 0x48),
                           *(undefined4 *)(iVar9 + 0x4c),*(undefined4 *)(iVar9 + 0x50),
                           *(undefined4 *)(iVar9 + 0x54),uVar12,0);
                iVar9 = *(int *)(param_1 + 0xe28);
                uVar12 = uVar20;
                if (*(char *)(iVar9 + 0x6c) == '\0') {
                  uVar12 = 0;
                }
                uVar20 = uVar20 + 1;
                in_r10 = *(int **)(iVar9 + 0x70);
                in_r5 = *(undefined4 *)(iVar9 + 0x5c);
                in_r6 = *(undefined4 *)(iVar9 + 0x60);
                in_r7 = *(int *)(iVar9 + 100);
                in_r8 = *(int **)(iVar9 + 0x68);
                ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar9 + 0x58),in_r5,in_r6,in_r7,in_r8,
                           *(undefined4 *)(iVar9 + 0x6c),in_r10,*(undefined4 *)(iVar9 + 0x74),
                           *(undefined4 *)(iVar9 + 0x78),uVar12,1);
                iVar9 = _glpRTCAddAChunk_97bd7cbc
                                  (&_glpOpSetAllEqualTo4AVRTC,*(undefined4 *)(param_1 + 0xe30));
                iVar17 = *(int *)(param_1 + 0xe30);
                *(undefined4 *)(iVar17 + iVar9 * 4) = 0x10a5112c;
                *(int *)(param_1 + 0xe30) = iVar17 + iVar9 * 4 + 4;
              } while (uVar20 < 4);
              goto LAB_97bdf7ec;
            }
          }
LAB_97bdf944:
          if (iVar21 == 0x36) {
            puVar13 = *(uint **)(param_1 + 0xe30);
            uVar20 = 0x1048104a;
LAB_97bdde90:
            *puVar13 = uVar20;
LAB_97bdde94:
            *(uint **)(param_1 + 0xe30) = puVar13 + 1;
          }
          goto LAB_97bdde9c;
        }
        uVar12 = 0;
        if (uVar20 != 0) {
          do {
            _PPCRuntimeCompilerBackupRegister(param_1,2);
            _PPCRuntimeCompilerDirtyRegister(param_1,2);
            iVar9 = *(int *)(param_1 + 0xe28);
            uVar15 = extraout_r4_03;
            if (*(int *)(iVar9 + 0x30) != 0) {
              iVar17 = 0;
              uVar7 = 0;
              do {
                iVar9 = iVar17 + iVar9;
                uVar6 = uVar12;
                if (*(char *)(iVar9 + 0x48) == '\0') {
                  uVar6 = 0;
                }
                uVar22 = uVar7 + 1;
                iVar17 = iVar17 + 0x24;
                in_r10 = *(int **)(iVar9 + 0x4c);
                in_r5 = *(undefined4 *)(iVar9 + 0x38);
                in_r6 = *(undefined4 *)(iVar9 + 0x3c);
                in_r7 = *(int *)(iVar9 + 0x40);
                in_r8 = *(int **)(iVar9 + 0x44);
                ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar9 + 0x34),in_r5,in_r6,in_r7,in_r8,
                           *(undefined4 *)(iVar9 + 0x48),in_r10,*(undefined4 *)(iVar9 + 0x50),
                           *(undefined4 *)(iVar9 + 0x54),uVar6,uVar7);
                iVar9 = *(int *)(param_1 + 0xe28);
                uVar15 = extraout_r4_04;
                uVar7 = uVar22;
              } while (uVar22 < *(uint *)(iVar9 + 0x30));
            }
            switch(iVar21) {
            case 1:
            case 0xb:
            case 0x10:
            case 0x11:
            case 0x13:
            case 0x14:
            case 0x18:
            case 0x2e:
            case 0x38:
            case 0x42:
            case 0x43:
            case 0x44:
            case 0x45:
            case 0x6f:
            case 0x70:
              _PPCRuntimeCompilerDirtyRegister(param_1,0);
              _PPCRuntimeCompilerDirtyRegister(param_1,1);
              uVar15 = extraout_r4_05;
              break;
            case 0x48:
              _PPCRuntimeCompilerDirtyRegistersWithIndirectData(param_1);
              uVar15 = extraout_r4_06;
            }
            switch(iVar21) {
            case 0:
switchD_97bdfc38_caseD_0:
              puVar5 = *(undefined4 **)(param_1 + 0xe30);
              puVar16 = &_glpOpMovAVRTC;
              break;
            case 1:
              puVar5 = *(undefined4 **)(param_1 + 0xe30);
              puVar16 = &_glpOpLitAVRTC;
              break;
            case 2:
              puVar5 = *(undefined4 **)(param_1 + 0xe30);
              puVar16 = &_glpOpAbsAVRTC;
              break;
            case 3:
              puVar5 = *(undefined4 **)(param_1 + 0xe30);
              puVar16 = &_glpOpCeilAVRTC;
              break;
            case 4:
              puVar5 = *(undefined4 **)(param_1 + 0xe30);
              puVar16 = &_glpOpFrcAVRTC;
              break;
            case 5:
              puVar5 = *(undefined4 **)(param_1 + 0xe30);
              puVar16 = &_glpOpFlrAVRTC;
              break;
            default:
              goto switchD_97bdfc38_caseD_6;
            case 7:
              puVar5 = *(undefined4 **)(param_1 + 0xe30);
              puVar16 = &_glpOpSetSignAVRTC;
              break;
            case 8:
              puVar5 = *(undefined4 **)(param_1 + 0xe30);
              puVar16 = &_glpOpAnyAVRTC;
              break;
            case 9:
              puVar5 = *(undefined4 **)(param_1 + 0xe30);
              puVar16 = &_glpOpAllAVRTC;
              break;
            case 10:
              puVar5 = *(undefined4 **)(param_1 + 0xe30);
              puVar16 = &_glpOpNotAVRTC;
              break;
            case 0xb:
              bVar3 = *(byte *)(*(int *)(param_1 + 0xe28) + 5);
              if (bVar3 == 2) {
                uVar23 = ((int (*)())_PPCNoiseGeneratorCalculate2DAVRTC)(*(int *)(param_1 + 0xe20) + 0x360,
                                    *(undefined4 *)(param_1 + 0xe30));
              }
              else if (bVar3 < 3) {
                if (bVar3 != 1) goto switchD_97bdfc38_caseD_6;
                uVar23 = ((int (*)())_PPCNoiseGeneratorCalculate1DAVRTC)(*(int *)(param_1 + 0xe20) + 0x360,
                                    *(undefined4 *)(param_1 + 0xe30));
              }
              else if (bVar3 == 3) {
                uVar23 = ((int (*)())_PPCNoiseGeneratorCalculate3DAVRTC)(*(int *)(param_1 + 0xe20) + 0x360,
                                    *(undefined4 *)(param_1 + 0xe30));
              }
              else {
                if (bVar3 != 4) goto switchD_97bdfc38_caseD_6;
                uVar23 = ((int (*)())_PPCNoiseGeneratorCalculate4DAVRTC)(*(int *)(param_1 + 0xe20) + 0x360,
                                    *(undefined4 *)(param_1 + 0xe30));
              }
              goto LAB_97be1634;
            case 0xc:
              puVar5 = *(undefined4 **)(param_1 + 0xe30);
              puVar16 = &_glpOpSqrtAVRTC;
              break;
            case 0xd:
              puVar5 = *(undefined4 **)(param_1 + 0xe30);
              puVar16 = &_glpOpRsqAVRTC;
              break;
            case 0xe:
              puVar5 = *(undefined4 **)(param_1 + 0xe30);
              puVar16 = &_glpOpRcpAVRTC;
              break;
            case 0x10:
              puVar5 = *(undefined4 **)(param_1 + 0xe30);
              goto LAB_97be04f0;
            case 0x11:
              puVar5 = *(undefined4 **)(param_1 + 0xe30);
              puVar16 = &_glpOpExpAVRTC;
              break;
            case 0x12:
              bVar3 = *(byte *)(*(int *)(param_1 + 0xe28) + 5);
              if (bVar3 == 2) {
                puVar5 = *(undefined4 **)(param_1 + 0xe30);
                puVar16 = &_glpOpLength2AVRTC;
              }
              else if (bVar3 < 3) {
                if (bVar3 != 1) goto switchD_97bdfc38_caseD_6;
                puVar5 = *(undefined4 **)(param_1 + 0xe30);
                puVar16 = &_glpOpLength1AVRTC;
              }
              else if (bVar3 == 3) {
                puVar5 = *(undefined4 **)(param_1 + 0xe30);
                puVar16 = &_glpOpLength3AVRTC;
              }
              else {
                if (bVar3 != 4) goto switchD_97bdfc38_caseD_6;
                puVar5 = *(undefined4 **)(param_1 + 0xe30);
                puVar16 = &_glpOpLength4AVRTC;
              }
              break;
            case 0x13:
              puVar5 = *(undefined4 **)(param_1 + 0xe30);
              puVar16 = &_glpOpLg2AVRTC;
              break;
            case 0x14:
              puVar5 = *(undefined4 **)(param_1 + 0xe30);
              puVar16 = &_glpOpLogAVRTC;
              break;
            case 0x15:
              bVar3 = *(byte *)(*(int *)(param_1 + 0xe28) + 5);
              if (bVar3 == 2) {
                puVar5 = *(undefined4 **)(param_1 + 0xe30);
                puVar16 = &_glpOpNormalise2AVRTC;
              }
              else if (bVar3 < 3) {
                if (bVar3 != 1) goto switchD_97bdfc38_caseD_6;
                puVar5 = *(undefined4 **)(param_1 + 0xe30);
                puVar16 = &_glpOpNormalise1AVRTC;
              }
              else if (bVar3 == 3) {
                puVar5 = *(undefined4 **)(param_1 + 0xe30);
                puVar16 = &_glpOpNormalise3AVRTC;
              }
              else {
                if (bVar3 != 4) goto switchD_97bdfc38_caseD_6;
                puVar5 = *(undefined4 **)(param_1 + 0xe30);
                puVar16 = &_glpOpNormalise4AVRTC;
              }
              break;
            case 0x16:
              puVar5 = *(undefined4 **)(param_1 + 0xe30);
              puVar16 = &_glpOpDegreesToRadiansAVRTC;
              break;
            case 0x17:
              puVar5 = *(undefined4 **)(param_1 + 0xe30);
              puVar16 = &_glpOpRadiansToDegreesAVRTC;
              break;
            case 0x18:
              puVar5 = *(undefined4 **)(param_1 + 0xe30);
              *puVar5 = 0x1003028c;
              puVar5 = puVar5 + 1;
              *(undefined4 **)(param_1 + 0xe30) = puVar5;
              iVar9 = _glpRTCAddAChunk_97bd7cbc(&_glpOpCosAVRTC,puVar5);
              iVar17 = *(int *)(param_1 + 0xe30) + iVar9 * 4 + 4;
              *(undefined4 *)(*(int *)(param_1 + 0xe30) + iVar9 * 4) = 0x10221484;
              *(int *)(param_1 + 0xe30) = iVar17;
              uVar23 = _glpRTCAddAChunk_97bd7cbc(&_glpOpSinAVRTC,iVar17);
              uVar15 = (undefined4)uVar23;
              iVar9 = (int)((ulonglong)uVar23 >> 0x20) * 4;
              puVar14 = (uint *)(*(int *)(param_1 + 0xe30) + iVar9 + 4);
              *(undefined4 *)(*(int *)(param_1 + 0xe30) + iVar9) = 0x1041132c;
              goto LAB_97be1820;
            case 0x19:
              puVar5 = *(undefined4 **)(param_1 + 0xe30);
              puVar16 = &_glpOpSinAVRTC;
              break;
            case 0x1a:
              puVar5 = *(undefined4 **)(param_1 + 0xe30);
              puVar16 = &_glpOpCosAVRTC;
              break;
            case 0x1f:
              puVar5 = *(undefined4 **)(param_1 + 0xe30);
              puVar16 = &_glpOpAddAVRTC;
              break;
            case 0x20:
              puVar5 = *(undefined4 **)(param_1 + 0xe30);
              puVar16 = &_glpOpSubAVRTC;
              break;
            case 0x21:
              puVar5 = *(undefined4 **)(param_1 + 0xe30);
              puVar16 = &_glpOpModAVRTC;
              break;
            case 0x23:
              puVar5 = *(undefined4 **)(param_1 + 0xe30);
              puVar16 = &_glpOpMulAVRTC;
              break;
            case 0x24:
              puVar5 = *(undefined4 **)(param_1 + 0xe30);
              puVar16 = &_glpOpLogicalAndAVRTC;
              break;
            case 0x25:
              puVar5 = *(undefined4 **)(param_1 + 0xe30);
              puVar16 = &_glpOpLogicalOrAVRTC;
              break;
            case 0x26:
              puVar5 = *(undefined4 **)(param_1 + 0xe30);
              puVar16 = &_glpOpLogicalXorAVRTC;
              break;
            case 0x27:
              bVar3 = *(byte *)(*(int *)(param_1 + 0xe28) + 5);
              if (bVar3 == 2) {
                puVar5 = *(undefined4 **)(param_1 + 0xe30);
                puVar16 = &_glpOpDp2AVRTC;
                break;
              }
              if (bVar3 < 3) {
                if (bVar3 == 1) {
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  puVar16 = &_glpOpDp1AVRTC;
                  break;
                }
              }
              else {
                if (bVar3 == 3) goto switchD_97bdfc38_caseD_28;
                if (bVar3 == 4) goto switchD_97bdfc38_caseD_29;
              }
              goto switchD_97bdfc38_caseD_6;
            case 0x28:
switchD_97bdfc38_caseD_28:
              puVar5 = *(undefined4 **)(param_1 + 0xe30);
              puVar16 = &_glpOpDp3AVRTC;
              break;
            case 0x29:
switchD_97bdfc38_caseD_29:
              puVar5 = *(undefined4 **)(param_1 + 0xe30);
              puVar16 = &_glpOpDp4AVRTC;
              break;
            case 0x2a:
              puVar5 = *(undefined4 **)(param_1 + 0xe30);
              puVar16 = &_glpOpDphAVRTC;
              break;
            case 0x2b:
              if (*(int *)(*(int *)(param_1 + 0xe24) + 0x38) - 0x8b30U < 2) {
                bVar3 = *(byte *)(*(int *)(param_1 + 0xe28) + 5);
                if (bVar3 == 2) {
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  puVar16 = &_glpOpDistance2GLSLAVRTC;
                }
                else if (bVar3 < 3) {
                  if (bVar3 != 1) goto switchD_97bdfc38_caseD_6;
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  puVar16 = &_glpOpDistance1GLSLAVRTC;
                }
                else if (bVar3 == 3) {
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  puVar16 = &_glpOpDistance3GLSLAVRTC;
                }
                else {
                  if (bVar3 != 4) goto switchD_97bdfc38_caseD_6;
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  puVar16 = &_glpOpDistance4GLSLAVRTC;
                }
              }
              else {
                puVar5 = *(undefined4 **)(param_1 + 0xe30);
                puVar16 = &_glpOpDistanceARBVPFPAVRTC;
              }
              break;
            case 0x2c:
              puVar5 = *(undefined4 **)(param_1 + 0xe30);
              puVar16 = &_glpOpMinAVRTC;
              break;
            case 0x2d:
              puVar5 = *(undefined4 **)(param_1 + 0xe30);
              puVar16 = &_glpOpMaxAVRTC;
              break;
            case 0x2e:
              puVar5 = *(undefined4 **)(param_1 + 0xe30);
              puVar16 = &_glpOpXpdAVRTC;
              break;
            case 0x2f:
              bVar3 = *(byte *)(*(int *)(param_1 + 0xe28) + 5);
              if (bVar3 == 2) {
                puVar5 = *(undefined4 **)(param_1 + 0xe30);
                puVar16 = &_glpOpReflect2AVRTC;
              }
              else if (bVar3 < 3) {
                if (bVar3 != 1) goto switchD_97bdfc38_caseD_6;
                puVar5 = *(undefined4 **)(param_1 + 0xe30);
                puVar16 = &_glpOpReflect1AVRTC;
              }
              else if (bVar3 == 3) {
                puVar5 = *(undefined4 **)(param_1 + 0xe30);
                puVar16 = &_glpOpReflect3AVRTC;
              }
              else {
                if (bVar3 != 4) goto switchD_97bdfc38_caseD_6;
                puVar5 = *(undefined4 **)(param_1 + 0xe30);
                puVar16 = &_glpOpReflect4AVRTC;
              }
              break;
            case 0x30:
              puVar5 = *(undefined4 **)(param_1 + 0xe30);
              puVar16 = &_glpOpStrAVRTC;
              break;
            case 0x32:
              puVar5 = *(undefined4 **)(param_1 + 0xe30);
              puVar16 = &_glpOpSgeAVRTC;
              break;
            case 0x33:
              puVar5 = *(undefined4 **)(param_1 + 0xe30);
              puVar16 = &_glpOpSgtAVRTC;
              break;
            case 0x34:
              puVar5 = *(undefined4 **)(param_1 + 0xe30);
              puVar16 = &_glpOpSleAVRTC;
              break;
            case 0x35:
              puVar5 = *(undefined4 **)(param_1 + 0xe30);
              puVar16 = &_glpOpSltAVRTC;
              break;
            case 0x37:
              puVar5 = *(undefined4 **)(param_1 + 0xe30);
              puVar16 = &_glpOpSflAVRTC;
              break;
            case 0x38:
              iVar9 = _glpRTCAddAChunk_97bd7cbc(&_glpOpLg2AVRTC,*(undefined4 *)(param_1 + 0xe30));
              iVar9 = *(int *)(param_1 + 0xe30) + iVar9 * 4;
              *(int *)(param_1 + 0xe30) = iVar9;
              iVar9 = _glpRTCAddAChunk_97bd7cbc(&_glpOpMulForPowAVRTC,iVar9);
              puVar5 = (undefined4 *)(*(int *)(param_1 + 0xe30) + iVar9 * 4);
              *(undefined4 **)(param_1 + 0xe30) = puVar5;
LAB_97be04f0:
              puVar16 = &_glpOpEx2AVRTC;
              break;
            case 0x39:
              puVar5 = *(undefined4 **)(param_1 + 0xe30);
              puVar16 = &_glpOpScalarSelectAVRTC;
              break;
            case 0x3a:
              iVar9 = *(int *)(*(int *)(param_1 + 0xe28) + 0x24);
              if (iVar9 == 1) {
                puVar5 = *(undefined4 **)(param_1 + 0xe30);
                puVar16 = &_glpOpDivideAVRTC;
              }
              else {
                if (iVar9 != 3) goto switchD_97bdfc38_caseD_6;
                puVar5 = *(undefined4 **)(param_1 + 0xe30);
                puVar16 = &_glpOpIntegerDivideAVRTC;
              }
              break;
            case 0x3b:
              bVar3 = *(byte *)(*(int *)(param_1 + 0xe28) + 5);
              if (bVar3 == 2) {
                puVar5 = *(undefined4 **)(param_1 + 0xe30);
                puVar16 = &_glpOpFaceForward2AVRTC;
              }
              else if (bVar3 < 3) {
                if (bVar3 != 1) goto switchD_97bdfc38_caseD_6;
                puVar5 = *(undefined4 **)(param_1 + 0xe30);
                puVar16 = &_glpOpFaceForward1AVRTC;
              }
              else if (bVar3 == 3) {
                puVar5 = *(undefined4 **)(param_1 + 0xe30);
                puVar16 = &_glpOpFaceForward3AVRTC;
              }
              else {
                if (bVar3 != 4) goto switchD_97bdfc38_caseD_6;
                puVar5 = *(undefined4 **)(param_1 + 0xe30);
                puVar16 = &_glpOpFaceForward4AVRTC;
              }
              break;
            case 0x3c:
              puVar5 = *(undefined4 **)(param_1 + 0xe30);
              puVar16 = &_glpOpLerpAVRTC;
              break;
            case 0x3d:
              puVar5 = *(undefined4 **)(param_1 + 0xe30);
              puVar16 = &_glpOpClampAVRTC;
              break;
            case 0x3e:
              puVar5 = *(undefined4 **)(param_1 + 0xe30);
              puVar16 = &_glpOpCmpAVRTC;
              break;
            case 0x3f:
              puVar5 = *(undefined4 **)(param_1 + 0xe30);
              puVar16 = &_glpOpMadAVRTC;
              break;
            case 0x40:
              puVar5 = *(undefined4 **)(param_1 + 0xe30);
              puVar16 = &_glpOpSmoothStepAVRTC;
              break;
            case 0x41:
              iVar9 = *(int *)(param_1 + 0xe28);
              in_r8 = (int *)(uint)*(byte *)(iVar9 + 99);
              uVar7 = (uint)*(byte *)(iVar9 + 0x61);
              in_r10 = (int *)(uint)*(byte *)(iVar9 + 0x62);
              switch(*(undefined1 *)(iVar9 + 0x60)) {
              case 0:
                if (uVar7 == 0) {
                  uVar7 = 0xffffffff;
                  if ((in_r10 == (int *)0x0) && (in_r10 = (int *)0xffffffff, in_r8 == (int *)0x0)) {
                    in_r8 = (int *)0xffffffff;
                  }
LAB_97be06cc:
                  puVar13 = *(uint **)(param_1 + 0xe30);
                  uVar6 = 0x10400000;
LAB_97be07d8:
                  uVar6 = uVar6 | 0x28c;
LAB_97be0ad4:
                  *puVar13 = uVar6;
LAB_97be0ad8:
                  *(uint **)(param_1 + 0xe30) = puVar13 + 1;
                  break;
                }
                if (uVar7 != 1) goto LAB_97be06cc;
                if (in_r10 != (int *)0x2) {
                  puVar13 = *(uint **)(param_1 + 0xe30);
                  uVar7 = 0x1040022c;
                  goto LAB_97be0794;
                }
                if (in_r8 != (int *)0x3) {
                  puVar14 = *(uint **)(param_1 + 0xe30);
                  uVar7 = 0x1040032c;
                  goto LAB_97be077c;
                }
                puVar14 = *(uint **)(param_1 + 0xe30);
                uVar7 = 0x10400484;
                goto LAB_97be1470;
              case 1:
                if (uVar7 == 1) {
                  uVar7 = 0xffffffff;
                  if ((in_r10 == (int *)0x1) && (in_r10 = (int *)0xffffffff, in_r8 == (int *)0x1)) {
                    in_r8 = (int *)0xffffffff;
                  }
LAB_97be0748:
                  puVar13 = *(uint **)(param_1 + 0xe30);
                  uVar6 = 0x10410000;
                  goto LAB_97be07d8;
                }
                if (uVar7 != 2) goto LAB_97be0748;
                if (in_r10 != (int *)0x3) {
                  puVar13 = *(uint **)(param_1 + 0xe30);
                  uVar7 = 0x1040032c;
                  goto LAB_97be0794;
                }
                if (in_r8 != (int *)0x0) {
                  puVar14 = *(uint **)(param_1 + 0xe30);
                  uVar7 = 0x10400484;
                  goto LAB_97be077c;
                }
                puVar14 = *(uint **)(param_1 + 0xe30);
                uVar7 = 0x10400000;
                goto LAB_97be13a0;
              case 2:
                if (uVar7 == 2) {
                  uVar7 = 0xffffffff;
                  if ((in_r10 == (int *)0x2) && (in_r10 = (int *)0xffffffff, in_r8 == (int *)0x2)) {
                    in_r8 = (int *)0xffffffff;
                  }
LAB_97be07d0:
                  puVar13 = *(uint **)(param_1 + 0xe30);
                  uVar6 = 0x10420000;
                  goto LAB_97be07d8;
                }
                if (uVar7 != 3) goto LAB_97be07d0;
                if (in_r10 != (int *)0x0) {
                  puVar13 = *(uint **)(param_1 + 0xe30);
                  uVar7 = 0x10400484;
                  goto LAB_97be0794;
                }
                if (in_r8 != (int *)0x1) {
                  puVar14 = *(uint **)(param_1 + 0xe30);
                  uVar7 = 0x10400000;
                  goto LAB_97be1050;
                }
                puVar14 = *(uint **)(param_1 + 0xe30);
                uVar7 = 0x10400000;
                goto LAB_97be1040;
              case 3:
                if (uVar7 == 0) {
                  if (in_r10 != (int *)0x1) {
                    puVar13 = *(uint **)(param_1 + 0xe30);
                    uVar7 = 0x10400000;
                    goto LAB_97be0c28;
                  }
                  if (in_r8 != (int *)0x2) {
                    puVar14 = *(uint **)(param_1 + 0xe30);
                    uVar7 = 0x10400000;
                    goto LAB_97be0c18;
                  }
                  puVar14 = *(uint **)(param_1 + 0xe30);
                  uVar7 = 0x10400000;
                  goto LAB_97be0c08;
                }
                if (uVar7 != 3) {
                  puVar13 = *(uint **)(param_1 + 0xe30);
                  uVar6 = 0x10400484;
                  goto LAB_97be0ad4;
                }
                if ((in_r10 == (int *)0x3) && (in_r10 = (int *)0xffffffff, in_r8 == (int *)0x3)) {
                  in_r8 = (int *)0xffffffff;
                }
                puVar13 = *(uint **)(param_1 + 0xe30);
                uVar7 = 0x1043028c;
                goto LAB_97be0794;
              case 4:
                if (uVar7 == 4) {
                  uVar7 = 0xffffffff;
                  if ((in_r10 == (int *)0x4) && (in_r10 = (int *)0xffffffff, in_r8 == (int *)0x4)) {
                    in_r8 = (int *)0xffffffff;
                  }
LAB_97be08c4:
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  uVar6 = 0x10400000;
LAB_97be0960:
                  *puVar5 = 0x10603cc4;
                  puVar13 = puVar5 + 1;
                  *puVar13 = uVar6 | 0x1a8c;
                  goto LAB_97be0ad8;
                }
                if (uVar7 != 5) goto LAB_97be08c4;
                if (in_r10 != (int *)0x6) {
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  uVar8 = 0x10603cc4;
                  uVar7 = 0x10431a2c;
                  goto LAB_97be0e64;
                }
                if (in_r8 == (int *)0x7) {
                  puVar14 = *(uint **)(param_1 + 0xe30);
                  uVar7 = 0x10403cc4;
                  goto LAB_97be1470;
                }
                puVar5 = *(undefined4 **)(param_1 + 0xe30);
                uVar8 = 0x10603cc4;
                uVar7 = 0x10431b2c;
                goto LAB_97be1248;
              case 5:
                if (uVar7 == 5) {
                  uVar7 = 0xffffffff;
                  if ((in_r10 == (int *)0x5) && (in_r10 = (int *)0xffffffff, in_r8 == (int *)0x5)) {
                    in_r8 = (int *)0xffffffff;
                  }
LAB_97be0954:
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  uVar6 = 0x10410000;
                  goto LAB_97be0960;
                }
                if (uVar7 != 6) goto LAB_97be0954;
                if (in_r10 != (int *)0x7) {
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  uVar8 = 0x10603cc4;
                  uVar7 = 0x10431b2c;
                  goto LAB_97be0e64;
                }
                if (in_r8 != (int *)0x4) {
                  puVar14 = *(uint **)(param_1 + 0xe30);
                  uVar7 = 0x10403cc4;
                  goto LAB_97be077c;
                }
                puVar14 = *(uint **)(param_1 + 0xe30);
                uVar7 = 0x10600000;
                uVar6 = 0x10430000;
                goto LAB_97be1484;
              case 6:
                if (uVar7 == 6) {
                  uVar7 = 0xffffffff;
                  if ((in_r10 == (int *)0x6) && (in_r10 = (int *)0xffffffff, in_r8 == (int *)0x6)) {
                    in_r8 = (int *)0xffffffff;
                  }
LAB_97be09ec:
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  uVar6 = 0x10420000;
                  goto LAB_97be0960;
                }
                if (uVar7 != 7) goto LAB_97be09ec;
                if (in_r10 != (int *)0x4) {
                  puVar13 = *(uint **)(param_1 + 0xe30);
                  uVar7 = 0x10403cc4;
                  goto LAB_97be0794;
                }
                puVar5 = *(undefined4 **)(param_1 + 0xe30);
                *puVar5 = 0x10603cc4;
                puVar13 = puVar5 + 1;
                *(uint **)(param_1 + 0xe30) = puVar13;
                if (in_r8 != (int *)0x5) {
                  uVar7 = 0x10430000;
                  goto LAB_97be1338;
                }
                uVar7 = 0x10430000;
                goto LAB_97be132c;
              case 7:
                if (uVar7 != 4) {
                  if (uVar7 != 7) {
                    puVar13 = *(uint **)(param_1 + 0xe30);
                    uVar6 = 0x10403cc4;
                    goto LAB_97be0ad4;
                  }
                  if ((in_r10 == (int *)0x7) && (in_r10 = (int *)0xffffffff, in_r8 == (int *)0x7)) {
                    in_r8 = (int *)0xffffffff;
                  }
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  uVar8 = 0x10603cc4;
                  uVar7 = 0x10431a8c;
                  goto LAB_97be0e64;
                }
                puVar5 = *(undefined4 **)(param_1 + 0xe30);
                *puVar5 = 0x10603cc4;
                puVar13 = puVar5 + 1;
                *(uint **)(param_1 + 0xe30) = puVar13;
                if (in_r10 != (int *)0x5) {
                  uVar7 = 0x10430000;
                  goto LAB_97be0fb8;
                }
                uVar7 = 0x10430000;
                if (in_r8 != (int *)0x6) goto LAB_97be0fac;
                uVar7 = 0x10430000;
                goto LAB_97be0ab4;
              case 8:
                puVar5 = *(undefined4 **)(param_1 + 0xe30);
                *puVar5 = 0x10484484;
                *(undefined4 **)(param_1 + 0xe30) = puVar5 + 1;
                if (uVar7 != 8) break;
                if (in_r10 != (int *)0x8) goto switchD_97be0ba4_default;
                bVar1 = in_r8 == (int *)0x8;
LAB_97be0b40:
                if (bVar1) goto switchD_97bdfc38_caseD_6;
                goto switchD_97be0fe8_default;
              case 9:
                puVar5 = *(undefined4 **)(param_1 + 0xe30);
                *puVar5 = 0x1040038c;
                *(undefined4 **)(param_1 + 0xe30) = puVar5 + 1;
                if (uVar7 != 9) break;
                if (in_r10 == (int *)0x9) {
                  bVar1 = in_r8 == (int *)0x9;
                  goto LAB_97be0b40;
                }
                goto switchD_97be0ba4_default;
              case 10:
                puVar5 = *(undefined4 **)(param_1 + 0xe30);
                *puVar5 = 0x10483cc4;
                *(undefined4 **)(param_1 + 0xe30) = puVar5 + 1;
                if (uVar7 == 10) {
                  uVar7 = 0xffffffff;
                  if (in_r10 != (int *)0xa) goto switchD_97be0ba4_default;
                  in_r10 = (int *)0xffffffff;
                  if (in_r8 != (int *)0xa) goto switchD_97be0fe8_default;
                  in_r8 = (int *)0xffffffff;
                }
              }
              switch(uVar7) {
              case 0:
                if (in_r10 == (int *)0x0) {
                  bVar1 = in_r8 == (int *)0x0;
                  puVar13 = *(uint **)(param_1 + 0xe30);
                  uVar7 = 0x10600000;
LAB_97be0c50:
                  uVar7 = uVar7 | 0x28c;
                  goto LAB_97be0c54;
                }
                if (in_r10 != (int *)0x1) {
                  puVar13 = *(uint **)(param_1 + 0xe30);
                  uVar7 = 0x10420000;
LAB_97be0c28:
                  uVar7 = uVar7 | 300;
                  goto LAB_97be0794;
                }
                if (in_r8 != (int *)0x2) {
                  puVar14 = *(uint **)(param_1 + 0xe30);
                  uVar7 = 0x10420000;
LAB_97be0c18:
                  uVar7 = uVar7 | 0x22c;
                  goto LAB_97be077c;
                }
                puVar14 = *(uint **)(param_1 + 0xe30);
                uVar7 = 0x10420000;
LAB_97be0c08:
                uVar7 = uVar7 | 0x32c;
                goto LAB_97be1470;
              case 1:
                if (in_r10 == (int *)0x1) {
                  bVar1 = in_r8 == (int *)0x1;
                  puVar13 = *(uint **)(param_1 + 0xe30);
                  uVar7 = 0x10610000;
                  goto LAB_97be0c50;
                }
                if (in_r10 != (int *)0x2) {
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  uVar8 = 0x1060012c;
                  goto LAB_97be0e60;
                }
                bVar1 = in_r8 == (int *)0x3;
                puVar13 = *(uint **)(param_1 + 0xe30);
                uVar7 = 0x1060012c;
                goto LAB_97be0c54;
              case 2:
                if (in_r10 == (int *)0x2) {
                  bVar1 = in_r8 == (int *)0x2;
                  puVar13 = *(uint **)(param_1 + 0xe30);
                  uVar7 = 0x10620000;
                  goto LAB_97be0c50;
                }
                if (in_r10 != (int *)0x3) {
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  uVar8 = 0x1060022c;
                  goto LAB_97be0e60;
                }
                bVar1 = in_r8 == (int *)0x0;
                puVar13 = *(uint **)(param_1 + 0xe30);
                uVar7 = 0x1060022c;
                goto LAB_97be0c54;
              case 3:
                if (in_r10 != (int *)0x0) {
                  if (in_r10 != (int *)0x3) {
                    puVar5 = *(undefined4 **)(param_1 + 0xe30);
                    uVar8 = 0x1060032c;
                    goto LAB_97be0e60;
                  }
                  bVar1 = in_r8 == (int *)0x3;
                  puVar13 = *(uint **)(param_1 + 0xe30);
                  uVar7 = 0x10630000;
                  goto LAB_97be0c50;
                }
                bVar1 = in_r8 == (int *)0x1;
                puVar13 = *(uint **)(param_1 + 0xe30);
                uVar7 = 0x1060032c;
LAB_97be0c54:
                *puVar13 = uVar7;
                puVar13 = puVar13 + 1;
                *(uint **)(param_1 + 0xe30) = puVar13;
LAB_97be0f9c:
                if (!bVar1) {
                  uVar7 = 0x10420000;
LAB_97be0fac:
                  uVar7 = uVar7 | 0x1a2c;
                  goto LAB_97be133c;
                }
                uVar7 = 0x10420000;
LAB_97be0ab4:
                uVar7 = uVar7 | 0x1b2c;
                goto LAB_97be181c;
              case 4:
                puVar5 = *(undefined4 **)(param_1 + 0xe30);
                *puVar5 = 0x10603cc4;
                puVar13 = puVar5 + 1;
                *(uint **)(param_1 + 0xe30) = puVar13;
                if (in_r10 == (int *)0x4) {
                  bVar1 = in_r8 == (int *)0x4;
                  uVar7 = 0x10600000;
LAB_97be0da4:
                  *puVar13 = uVar7 | 0x1a8c;
                  goto LAB_97be0e24;
                }
                if (in_r10 == (int *)0x5) {
                  bVar1 = in_r8 == (int *)0x6;
                  goto LAB_97be0f9c;
                }
                puVar13 = *(uint **)(param_1 + 0xe30);
                uVar7 = 0x1042192c;
LAB_97be0794:
                *puVar13 = uVar7;
                break;
              case 5:
                puVar5 = *(undefined4 **)(param_1 + 0xe30);
                *puVar5 = 0x10603cc4;
                puVar13 = puVar5 + 1;
                *(uint **)(param_1 + 0xe30) = puVar13;
                if (in_r10 == (int *)0x5) {
                  bVar1 = in_r8 == (int *)0x5;
                  uVar7 = 0x10610000;
                  goto LAB_97be0da4;
                }
                if (in_r10 != (int *)0x6) {
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  uVar8 = 0x1063192c;
                  goto LAB_97be0e60;
                }
                bVar1 = in_r8 == (int *)0x7;
                uVar7 = 0x1063192c;
LAB_97be0e1c:
                *puVar13 = uVar7;
LAB_97be0e24:
                *(uint **)(param_1 + 0xe30) = puVar13 + 1;
                if (!bVar1) {
                  puVar14 = puVar13 + 2;
                  puVar13[1] = 0x10421a2c;
                  goto LAB_97be1344;
                }
                uVar7 = 0x10421b2c;
                goto LAB_97be1418;
              case 6:
                puVar5 = *(undefined4 **)(param_1 + 0xe30);
                *puVar5 = 0x10603cc4;
                puVar13 = puVar5 + 1;
                *(uint **)(param_1 + 0xe30) = puVar13;
                if (in_r10 == (int *)0x6) {
                  bVar1 = in_r8 == (int *)0x6;
                  uVar7 = 0x10620000;
                  goto LAB_97be0da4;
                }
                if (in_r10 == (int *)0x7) {
                  bVar1 = in_r8 == (int *)0x4;
                  uVar7 = 0x10631a2c;
                  goto LAB_97be0e1c;
                }
                puVar5 = *(undefined4 **)(param_1 + 0xe30);
                uVar8 = 0x10631a2c;
LAB_97be0e60:
                uVar7 = 0x1042192c;
LAB_97be0e64:
                *puVar5 = uVar8;
                puVar13 = puVar5 + 1;
                *puVar13 = uVar7;
                break;
              case 7:
                puVar5 = *(undefined4 **)(param_1 + 0xe30);
                *puVar5 = 0x10603cc4;
                puVar18 = puVar5 + 1;
                *(undefined4 **)(param_1 + 0xe30) = puVar18;
                if (in_r10 == (int *)0x4) {
                  bVar1 = in_r8 == (int *)0x5;
                  uVar8 = 0x10631b2c;
                }
                else {
                  if (in_r10 != (int *)0x7) {
                    *puVar18 = 0x10631b2c;
                    puVar5[2] = 0x1042192c;
                    *(undefined4 **)(param_1 + 0xe30) = puVar5 + 3;
                    goto switchD_97be0ba4_default;
                  }
                  bVar1 = in_r8 == (int *)0x7;
                  uVar8 = 0x10631a8c;
                }
                *puVar18 = uVar8;
                *(undefined4 **)(param_1 + 0xe30) = puVar5 + 2;
                if (bVar1) {
                  puVar14 = puVar5 + 3;
                  puVar5[2] = 0x10421b2c;
                  goto LAB_97be1820;
                }
                puVar14 = puVar5 + 3;
                puVar5[2] = 0x10421a2c;
                goto LAB_97be1344;
              case 8:
                if (in_r10 != (int *)0x8) {
                  puVar13 = *(uint **)(param_1 + 0xe30);
                  uVar7 = 0x1042412c;
                  goto LAB_97be0794;
                }
                if (in_r8 == (int *)0x8) {
                  puVar14 = *(uint **)(param_1 + 0xe30);
                  uVar7 = 0x1042432c;
                  goto LAB_97be1470;
                }
                puVar14 = *(uint **)(param_1 + 0xe30);
                uVar7 = 0x1042422c;
                goto LAB_97be077c;
              case 9:
                puVar5 = *(undefined4 **)(param_1 + 0xe30);
                *puVar5 = 0x1060038c;
                puVar13 = puVar5 + 1;
                *(uint **)(param_1 + 0xe30) = puVar13;
                if (in_r10 == (int *)0x9) {
                  bVar1 = in_r8 == (int *)0x9;
                  goto LAB_97be0f9c;
                }
LAB_97be0fb4:
                uVar7 = 0x10420000;
LAB_97be0fb8:
                *puVar13 = uVar7 | 0x192c;
                break;
              case 10:
                puVar5 = *(undefined4 **)(param_1 + 0xe30);
                *puVar5 = 0x10683cc4;
                puVar13 = puVar5 + 1;
                *(uint **)(param_1 + 0xe30) = puVar13;
                if (in_r10 != (int *)0xa) goto LAB_97be0fb4;
                bVar1 = in_r8 == (int *)0xa;
                goto LAB_97be0f9c;
              default:
                goto switchD_97be0ba4_default;
              }
              *(uint **)(param_1 + 0xe30) = puVar13 + 1;
switchD_97be0ba4_default:
              switch((int)in_r10) {
              case 0x0:
                if (in_r8 == (int *)0x0) {
                  puVar14 = *(uint **)(param_1 + 0xe30);
                  uVar7 = 0x10600000;
LAB_97be1074:
                  uVar7 = uVar7 | 0x28c;
                  goto LAB_97be107c;
                }
                if (in_r8 != (int *)0x1) {
                  puVar14 = *(uint **)(param_1 + 0xe30);
                  uVar7 = 0x10420000;
LAB_97be1050:
                  uVar7 = uVar7 | 300;
                  goto LAB_97be077c;
                }
                puVar14 = *(uint **)(param_1 + 0xe30);
                uVar7 = 0x10420000;
LAB_97be1040:
                uVar7 = uVar7 | 0x22c;
                goto LAB_97be1470;
              case 0x1:
                if (in_r8 == (int *)0x1) {
                  puVar14 = *(uint **)(param_1 + 0xe30);
                  uVar7 = 0x10610000;
                  goto LAB_97be1074;
                }
                if (in_r8 == (int *)0x2) {
                  puVar14 = *(uint **)(param_1 + 0xe30);
                  uVar7 = 0x1060012c;
                  goto LAB_97be107c;
                }
                puVar5 = *(undefined4 **)(param_1 + 0xe30);
                uVar8 = 0x1060012c;
LAB_97be1244:
                uVar7 = 0x1042192c;
LAB_97be1248:
                *puVar5 = uVar8;
                puVar14 = puVar5 + 1;
                *puVar14 = uVar7;
                goto LAB_97be0780;
              case 0x2:
                if (in_r8 == (int *)0x2) {
                  puVar14 = *(uint **)(param_1 + 0xe30);
                  uVar7 = 0x10620000;
                  goto LAB_97be1074;
                }
                if (in_r8 != (int *)0x3) {
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  uVar8 = 0x1060022c;
                  goto LAB_97be1244;
                }
                puVar14 = *(uint **)(param_1 + 0xe30);
                uVar7 = 0x1060022c;
                goto LAB_97be107c;
              case 0x3:
                if (in_r8 != (int *)0x0) {
                  if (in_r8 != (int *)0x3) {
                    puVar5 = *(undefined4 **)(param_1 + 0xe30);
                    uVar8 = 0x1060032c;
                    goto LAB_97be1244;
                  }
                  puVar14 = *(uint **)(param_1 + 0xe30);
                  uVar7 = 0x10630000;
                  goto LAB_97be1074;
                }
                puVar14 = *(uint **)(param_1 + 0xe30);
                uVar7 = 0x1060032c;
LAB_97be107c:
                uVar6 = 0x10421a2c;
                goto LAB_97be148c;
              case 0x4:
                puVar5 = *(undefined4 **)(param_1 + 0xe30);
                *puVar5 = 0x10603cc4;
                puVar13 = puVar5 + 1;
                *(uint **)(param_1 + 0xe30) = puVar13;
                if (in_r8 == (int *)0x4) {
                  uVar7 = 0x10600000;
LAB_97be11c0:
                  uVar7 = uVar7 | 0x1a8c;
                  goto LAB_97be1290;
                }
                if (in_r8 != (int *)0x5) {
                  puVar14 = *(uint **)(param_1 + 0xe30);
                  uVar7 = 0x1042192c;
                  goto LAB_97be077c;
                }
                puVar14 = puVar5 + 2;
                *puVar13 = 0x10421a2c;
                goto LAB_97be1820;
              case 0x5:
                puVar5 = *(undefined4 **)(param_1 + 0xe30);
                *puVar5 = 0x10603cc4;
                puVar13 = puVar5 + 1;
                *(uint **)(param_1 + 0xe30) = puVar13;
                if (in_r8 == (int *)0x5) {
                  uVar7 = 0x10610000;
                  goto LAB_97be11c0;
                }
                if (in_r8 != (int *)0x6) {
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  uVar8 = 0x1063192c;
                  goto LAB_97be1244;
                }
                uVar7 = 0x1063192c;
                goto LAB_97be1290;
              case 0x6:
                puVar5 = *(undefined4 **)(param_1 + 0xe30);
                *puVar5 = 0x10603cc4;
                puVar13 = puVar5 + 1;
                *(uint **)(param_1 + 0xe30) = puVar13;
                if (in_r8 == (int *)0x6) {
                  uVar7 = 0x10620000;
                  goto LAB_97be11c0;
                }
                if (in_r8 != (int *)0x7) {
                  puVar5 = *(undefined4 **)(param_1 + 0xe30);
                  uVar8 = 0x10631a2c;
                  goto LAB_97be1244;
                }
                uVar7 = 0x10631a2c;
LAB_97be1290:
                *puVar13 = uVar7;
                puVar13[1] = 0x10421a2c;
                *(uint **)(param_1 + 0xe30) = puVar13 + 2;
                goto switchD_97bdfc38_caseD_6;
              case 0x7:
                puVar5 = *(undefined4 **)(param_1 + 0xe30);
                *puVar5 = 0x10603cc4;
                puVar13 = puVar5 + 1;
                *(uint **)(param_1 + 0xe30) = puVar13;
                if (in_r8 == (int *)0x4) {
                  uVar7 = 0x10631b2c;
                  goto LAB_97be1290;
                }
                uVar7 = 0x10630000;
                if (in_r8 == (int *)0x7) goto LAB_97be11c0;
                *puVar13 = 0x10631b2c;
                puVar5[2] = 0x1042192c;
                *(undefined4 **)(param_1 + 0xe30) = puVar5 + 3;
                break;
              case 0x8:
                if (in_r8 == (int *)0x8) {
                  puVar14 = *(uint **)(param_1 + 0xe30);
                  uVar7 = 0x1042422c;
                  goto LAB_97be1470;
                }
                puVar14 = *(uint **)(param_1 + 0xe30);
                uVar7 = 0x1042412c;
LAB_97be077c:
                *puVar14 = uVar7;
LAB_97be0780:
                puVar14 = puVar14 + 1;
LAB_97be1344:
                *(uint **)(param_1 + 0xe30) = puVar14;
                break;
              case 0x9:
                bVar1 = in_r8 == (int *)0x9;
                puVar5 = *(undefined4 **)(param_1 + 0xe30);
                uVar8 = 0x1060038c;
                goto LAB_97be1318;
              case 0xa:
                bVar1 = in_r8 == (int *)0xa;
                puVar5 = *(undefined4 **)(param_1 + 0xe30);
                uVar8 = 0x10683cc4;
LAB_97be1318:
                *puVar5 = uVar8;
                puVar13 = puVar5 + 1;
                *(uint **)(param_1 + 0xe30) = puVar13;
                if (!bVar1) {
                  uVar7 = 0x10420000;
LAB_97be1338:
                  uVar7 = uVar7 | 0x192c;
LAB_97be133c:
                  puVar14 = puVar13 + 1;
                  *puVar13 = uVar7;
                  goto LAB_97be1344;
                }
                uVar7 = 0x10420000;
LAB_97be132c:
                uVar7 = uVar7 | 0x1a2c;
LAB_97be181c:
                puVar14 = puVar13 + 1;
                *puVar13 = uVar7;
                goto LAB_97be1820;
              }
switchD_97be0fe8_default:
              switch((int)in_r8) {
              case 0x0:
                puVar14 = *(uint **)(param_1 + 0xe30);
                uVar7 = 0x10420000;
LAB_97be13a0:
                uVar7 = uVar7 | 300;
                goto LAB_97be1470;
              case 0x1:
                puVar14 = *(uint **)(param_1 + 0xe30);
                uVar6 = 0x10420000;
                uVar7 = 0x1060012c;
                break;
              case 0x2:
                puVar14 = *(uint **)(param_1 + 0xe30);
                uVar6 = 0x10420000;
                uVar7 = 0x1060022c;
                break;
              case 0x3:
                puVar14 = *(uint **)(param_1 + 0xe30);
                uVar6 = 0x10420000;
                uVar7 = 0x1060032c;
                break;
              case 0x4:
                puVar14 = *(uint **)(param_1 + 0xe30);
                uVar7 = 0x10600000;
                goto LAB_97be1480;
              case 0x5:
                puVar5 = *(undefined4 **)(param_1 + 0xe30);
                uVar7 = 0x1063192c;
                goto LAB_97be1404;
              case 0x6:
                puVar5 = *(undefined4 **)(param_1 + 0xe30);
                uVar7 = 0x10631a2c;
                goto LAB_97be1404;
              case 0x7:
                puVar5 = *(undefined4 **)(param_1 + 0xe30);
                uVar7 = 0x10631b2c;
LAB_97be1404:
                *puVar5 = 0x10603cc4;
                puVar13 = puVar5 + 1;
                *puVar13 = uVar7;
                uVar7 = 0x1042192c;
LAB_97be1418:
                puVar14 = puVar13 + 2;
                puVar13[1] = uVar7;
                goto LAB_97be1820;
              case 0x8:
                puVar14 = *(uint **)(param_1 + 0xe30);
                uVar7 = 0x1042412c;
LAB_97be1470:
                *puVar14 = uVar7;
                goto LAB_97be1494;
              case 0x9:
                puVar14 = *(uint **)(param_1 + 0xe30);
                uVar6 = 0x10420000;
                uVar7 = 0x1060038c;
                break;
              case 0xa:
                puVar14 = *(uint **)(param_1 + 0xe30);
                uVar7 = 0x10680000;
LAB_97be1480:
                uVar6 = 0x10420000;
LAB_97be1484:
                uVar7 = uVar7 | 0x3cc4;
                break;
              default:
                goto switchD_97bdfc38_caseD_6;
              }
              uVar6 = uVar6 | 0x192c;
LAB_97be148c:
              *puVar14 = uVar7;
              puVar14 = puVar14 + 1;
              *puVar14 = uVar6;
LAB_97be1494:
              puVar14 = puVar14 + 1;
LAB_97be1820:
              *(uint **)(param_1 + 0xe30) = puVar14;
              goto switchD_97bdfc38_caseD_6;
            case 0x42:
            case 0x43:
            case 0x44:
            case 0x45:
              in_r8 = *(int **)(param_1 + 0xe20);
              if (*(int *)(in_r8[0x360] + 0x38) - 0x8b30U < 2) {
                in_r10 = *(int **)(*(int *)(param_1 + 0xe28) + 0x58);
                uVar8 = *(undefined4 *)
                         (in_r8[*(ushort *)(*(int *)(param_1 + 0xe28) + 0x68) + 0x361] + *in_r10);
              }
              else {
                uVar8 = *(undefined4 *)(*(int *)(param_1 + 0xe28) + 0x10c);
              }
              ((int (*)())_PPCTextureSamplerAttachGLDContext)(*(undefined4 *)(param_1 + 0xe1c),in_r8[0x367]);
              uVar15 = 0;
              if ((iVar21 == 0x43) || (iVar21 == 0x45)) {
                uVar15 = 1;
              }
              ((int (*)())_PPCTextureSamplerSetProjectionEnabled)(*(undefined4 *)(param_1 + 0xe1c),uVar15);
              ((int (*)())_PPCTextureSamplerSetLodBiasEnabled)(*(undefined4 *)(param_1 + 0xe1c),(uint)(iVar21 - 0x44U < 2));
              if (((iVar21 == 0x44) &&
                  (iVar9 = *(int *)(*(int *)(*(int *)(param_1 + 0xe20) + 0xd80) + 0x38),
                  iVar9 != 0x8b30)) && (iVar9 != 0x8b31)) {
                puVar5 = *(undefined4 **)(param_1 + 0xe30);
                *puVar5 = 0x1043028c;
                puVar5[1] = 0x1000436a;
                *(undefined4 **)(param_1 + 0xe30) = puVar5 + 2;
              }
              uVar7 = *(uint *)(*(int *)(param_1 + 0xe28) + 0x110);
              if (uVar7 == 2) {
                in_r5 = *(undefined4 *)(param_1 + 0xe30);
                uVar23 = _PPCTextureSamplerSampleTexelRECTRTCAV
                                   (*(undefined4 *)(param_1 + 0xe1c),uVar8);
              }
              else {
                uVar15 = extraout_r4_07;
                if (uVar7 < 3) {
                  if (uVar7 != 1) goto switchD_97bdfc38_caseD_6;
                  in_r5 = *(undefined4 *)(param_1 + 0xe30);
                  uVar23 = ((int (*)())_PPCTextureSamplerSampleTexel3DRTCAV)(*(undefined4 *)(param_1 + 0xe1c),uVar8,in_r5);
                }
                else if (uVar7 == 3) {
                  in_r5 = *(undefined4 *)(param_1 + 0xe30);
                  uVar23 = ((int (*)())_PPCTextureSamplerSampleTexel2DRTCAV)(*(undefined4 *)(param_1 + 0xe1c),uVar8,in_r5);
                }
                else {
                  if (uVar7 != 4) goto switchD_97bdfc38_caseD_6;
                  in_r5 = *(undefined4 *)(param_1 + 0xe30);
                  uVar23 = ((int (*)())_PPCTextureSamplerSampleTexel1DRTCAV)(*(undefined4 *)(param_1 + 0xe1c),uVar8,in_r5);
                }
              }
LAB_97be1634:
              uVar15 = (undefined4)uVar23;
              *(int *)(param_1 + 0xe30) = (int)((ulonglong)uVar23 >> 0x20);
              goto switchD_97bdfc38_caseD_6;
            case 0x48:
              if ((*(byte *)(*(int *)(param_1 + 0xe28) + 0x28) & 1) != 0) {
                uVar23 = _glpRTCAddAChunk_97bd7cbc(&_glpOpArlAVRTC,*(undefined4 *)(param_1 + 0xe30))
                ;
                uVar15 = (undefined4)uVar23;
                *(int *)(param_1 + 0xe30) =
                     *(int *)(param_1 + 0xe30) + (int)((ulonglong)uVar23 >> 0x20) * 4;
              }
            case 0x49:
            case 0x4a:
            case 0x4c:
            case 0x4f:
            case 0x56:
            case 0x57:
            case 0x59:
            case 0x5a:
            case 0x5b:
            case 0x6a:
              goto switchD_97bdfc38_caseD_49;
            case 0x4b:
              iVar9 = *(int *)(param_1 + 0xe28);
              in_r5 = *(undefined4 *)(iVar9 + 0x10);
              in_r6 = *(undefined4 *)(iVar9 + 0x14);
              in_r7 = *(int *)(iVar9 + 0x18);
              in_r8 = *(int **)(iVar9 + 0x1c);
              ((int (*)())_PPCRuntimeCompilerTestConditionRegisterAV)(param_1,*(undefined4 *)(iVar9 + 0xc),in_r5,in_r6,in_r7,in_r8,
                         *(undefined4 *)(iVar9 + 0x20),*(undefined4 *)(iVar9 + 0x24),
                         *(undefined4 *)(iVar9 + 0x28));
              puVar5 = *(undefined4 **)(param_1 + 0xe30);
              *puVar5 = 0x10634e86;
              puVar5[1] = 0x4098000c;
              puVar5[2] = 0x419a0008;
              in_r10 = puVar5 + 3;
              uVar15 = extraout_r4_08;
              goto LAB_97be16ec;
            case 0x4d:
              puVar13 = *(uint **)(param_1 + 0xe30);
              *puVar13 = *(int *)(param_1 + 0xe40) - (int)puVar13 & 0x3fffffcU | 0x48000000;
              *(uint **)(param_1 + 0xe30) = puVar13 + 1;
              goto switchD_97bdfc38_caseD_49;
            case 0x54:
            case 0x58:
              piVar10 = *(int **)(*(int *)(param_1 + 0xe20) + 0xd80);
              iVar9 = *piVar10 + *(int *)(*(int *)(param_1 + 0xe28) + 8) * 0x11c;
              if ((uint)piVar10[1] < iVar9 - 0x11cU) {
                puVar13 = *(uint **)(param_1 + 0xe30);
                uVar7 = *(int *)(param_1 + 0xe40) - (int)puVar13;
              }
              else {
                puVar13 = *(uint **)(param_1 + 0xe30);
                uVar7 = *(int *)(iVar9 + -4) - ((int)puVar13 - *(int *)(param_1 + 0xe2c));
              }
              *puVar13 = uVar7 & 0x3fffffc | 0x48000000;
              goto LAB_97be17b0;
            case 0x55:
              puVar5 = *(undefined4 **)(param_1 + 0xe30);
              puVar5[1] = 0x40980008;
              in_r10 = puVar5 + 2;
              *puVar5 = 0x10604cc6;
LAB_97be16ec:
              *(int **)(param_1 + 0xe30) = in_r10;
              piVar10 = *(int **)(*(int *)(param_1 + 0xe20) + 0xd80);
              iVar9 = *piVar10 + *(int *)(*(int *)(param_1 + 0xe28) + 8) * 0x11c;
              if ((uint)piVar10[1] < iVar9 - 0x11cU) {
                uVar7 = *(int *)(param_1 + 0xe40) - (int)in_r10;
              }
              else {
                uVar7 = *(int *)(iVar9 + -4) - ((int)in_r10 - *(int *)(param_1 + 0xe2c));
              }
              puVar13 = *(uint **)(param_1 + 0xe30);
              *puVar13 = uVar7 & 0x3fffffc | 0x48000000;
LAB_97be17b0:
              *(uint **)(param_1 + 0xe30) = puVar13 + 1;
switchD_97bdfc38_caseD_49:
              bVar4 = false;
              goto LAB_97be1860;
            case 0x68:
              puVar5 = *(undefined4 **)(param_1 + 0xe30);
              puVar16 = &_glpOpRefractAVRTC;
              break;
            case 0x6b:
              piVar10 = *(int **)(*(int *)(param_1 + 0xe20) + 0xd80);
              iVar9 = *piVar10 + *(int *)(*(int *)(param_1 + 0xe28) + 8) * 0x11c;
              if ((uint)piVar10[1] < iVar9 - 0x11cU) {
                puVar13 = *(uint **)(param_1 + 0xe30);
                uVar7 = *(int *)(param_1 + 0xe40) - (int)puVar13;
              }
              else {
                puVar13 = *(uint **)(param_1 + 0xe30);
                uVar7 = *(int *)(iVar9 + -4) - ((int)puVar13 - *(int *)(param_1 + 0xe2c));
              }
              uVar7 = uVar7 & 0x3fffffc | 0x48000000;
              bVar4 = false;
              goto LAB_97be181c;
            case 0x6c:
              iVar9 = *(int *)(param_1 + 0xe28);
              if ((*(int *)(iVar9 + 0x24) == 3) && (*(int *)(iVar9 + 0x4c) == 1)) {
                puVar5 = *(undefined4 **)(param_1 + 0xe30);
                puVar16 = &_glpOpTruncateAVRTC;
              }
              else {
                if ((*(int *)(iVar9 + 0x24) != 4) ||
                   ((*(int *)(iVar9 + 0x4c) != 1 && (*(int *)(iVar9 + 0x4c) != 3))))
                goto switchD_97bdfc38_caseD_0;
                puVar5 = *(undefined4 **)(param_1 + 0xe30);
                puVar16 = &_glpOpSetNotEqualToZeroAVRTC;
              }
              break;
            case 0x6d:
              puVar5 = *(undefined4 **)(param_1 + 0xe30);
              puVar16 = &_glpOpDestinationScalarSelectAVRTC;
              break;
            case 0x6f:
              puVar18 = *(undefined4 **)(param_1 + 0xe30);
              *puVar18 = 0x39e001b0;
              puVar18[1] = 0x7c6378ce;
              puVar5 = puVar18 + 3;
              puVar18[2] = 0x100038ee;
              puVar16 = &_glpOpEx2AVRTC;
              *(undefined4 **)(param_1 + 0xe30) = puVar5;
              break;
            case 0x70:
              uVar23 = _glpRTCAddAChunk_97bd7cbc(&_glpOpLg2AVRTC,*(undefined4 *)(param_1 + 0xe30));
              uVar15 = (undefined4)uVar23;
              in_r7 = *(int *)(param_1 + 0xe30);
              iVar9 = (int)((ulonglong)uVar23 >> 0x20) * 4;
              in_r10 = (int *)(in_r7 + iVar9);
              in_r8 = in_r10 + 1;
              *(undefined4 *)(in_r7 + iVar9) = 0x39e001c0;
              in_r10[1] = 0x7c6378ce;
              in_r10[2] = 0x104238ee;
              *(int **)(param_1 + 0xe30) = in_r10 + 3;
              goto switchD_97bdfc38_caseD_6;
            }
            uVar23 = _glpRTCAddAChunk_97bd7cbc(puVar16,puVar5);
            uVar15 = (undefined4)uVar23;
            *(int *)(param_1 + 0xe30) =
                 *(int *)(param_1 + 0xe30) + (int)((ulonglong)uVar23 >> 0x20) * 4;
switchD_97bdfc38_caseD_6:
            if (bVar4) {
              if (cVar2 != '\0') {
                iVar9 = _glpRTCAddAChunk_97bd7cbc
                                  (&_glpOpSaturateAVRTC,*(undefined4 *)(param_1 + 0xe30));
                *(int *)(param_1 + 0xe30) = *(int *)(param_1 + 0xe30) + iVar9 * 4;
              }
              ((int (*)())_PPCRuntimeCompilerWriteDestinationAV)(param_1,uVar12);
              uVar15 = extraout_r4_09;
            }
LAB_97be1860:
            uVar12 = uVar12 + 1;
          } while (uVar12 < uVar20);
        }
        iVar9 = *(int *)(param_1 + 0xe2c);
        if (iVar19 - 3000U < (uint)(*(int *)(param_1 + 0xe30) - iVar9)) {
          iVar19 = iVar19 + 0x2000;
          uVar23 = _glpDCBRealloc(iVar9,iVar19);
          iVar21 = (int)((ulonglong)uVar23 >> 0x20);
          uVar15 = (undefined4)uVar23;
          *(int *)(param_1 + 0xe2c) = iVar21;
          iVar9 = iVar21 - iVar9 >> 2;
          if (iVar9 != 0) {
            iVar9 = iVar9 * 4;
            in_r10 = (int *)(*(int *)(param_1 + 0xe3c) + iVar9);
            *(int *)(param_1 + 0xe30) = *(int *)(param_1 + 0xe30) + iVar9;
            in_r8 = (int *)(*(int *)(param_1 + 0xe40) + iVar9);
            *(int *)(param_1 + 0xe34) = *(int *)(param_1 + 0xe34) + iVar9;
            *(int *)(param_1 + 0xe38) = *(int *)(param_1 + 0xe38) + iVar9;
            *(int **)(param_1 + 0xe3c) = in_r10;
            *(int **)(param_1 + 0xe40) = in_r8;
          }
        }
LAB_97be18e4:
        in_r9 = *(undefined4 **)(param_1 + 0xe28);
      }
      iVar9 = *(int *)(param_1 + 0xe24);
      puVar5 = in_r9 + 0x47;
      if (in_r9 == *(undefined4 **)(iVar9 + 4)) {
        puVar5 = (undefined4 *)0x0;
      }
      *(undefined4 **)(param_1 + 0xe28) = puVar5;
    }
    iVar21 = *(int *)(param_1 + 0xe48);
    if (iVar21 == 0) {
      *(undefined4 **)(param_1 + 0xe40) = *(undefined4 **)(param_1 + 0xe30);
      in_r9 = *(undefined4 **)(param_1 + 0xe30);
      while (((uint)in_r9 & 0xf) != 0) {
        *in_r9 = 0x60000000;
        *(undefined4 **)(param_1 + 0xe30) = in_r9 + 1;
        in_r9 = in_r9 + 1;
      }
      _PPCRuntimeCompilerInitialise(param_1,1);
      uVar8 = *(undefined4 *)(param_1 + 0xe34);
      uVar15 = extraout_r4_10;
LAB_97be1ac8:
      iVar21 = *(int *)(param_1 + 0xe48);
      *(undefined4 *)(param_1 + 0xe30) = uVar8;
    }
    else if (iVar21 == 1) {
      _PPCRuntimeCompilerBackupRegister(param_1,0);
      _PPCRuntimeCompilerBackupRegister(param_1,1);
      _PPCRuntimeCompilerBackupRegister(param_1,2);
      _PPCRuntimeCompilerDirtyRegistersContainingAttributes(param_1);
      _PPCRuntimeCompilerDirtyRegistersContainingTemps(param_1);
      _PPCRuntimeCompilerDirtyRegistersContainingParams(param_1);
      if (((uint)*(undefined4 **)(param_1 + 0xe30) & 0xf) != 0) {
        in_r9 = (undefined4 *)0x60000000;
        puVar5 = *(undefined4 **)(param_1 + 0xe30);
        do {
          puVar18 = puVar5 + 1;
          *puVar5 = 0x60000000;
          *(undefined4 **)(param_1 + 0xe30) = puVar18;
          puVar5 = puVar18;
        } while (((uint)puVar18 & 0xf) != 0);
      }
      _PPCRuntimeCompilerInitialiseVariableInfo(param_1);
      iVar21 = *(int *)(param_1 + 0xe48);
      *(undefined4 *)(param_1 + 0xe38) = *(undefined4 *)(param_1 + 0xe30);
      uVar15 = extraout_r4_11;
    }
    else {
      if (iVar21 == 2) {
        in_r9 = *(undefined4 **)(param_1 + 0xe30);
        *(undefined4 **)(param_1 + 0xe40) = in_r9;
        if ((*(int *)(iVar9 + 0x38) == 0x8804) || (*(int *)(iVar9 + 0x38) == 0x8b30)) {
          if ((*(uint *)(iVar9 + 0x34) & 2) != 0) {
            ((int (*)())_PPCRuntimeCompilerWriteFinalFragmentToBuffer)(param_1,uVar15,in_r5,in_r6,in_r7,in_r8,in_r9,in_r10);
            in_r9 = *(undefined4 **)(param_1 + 0xe30);
          }
        }
        else {
          _PPCRuntimeCompilerBackupRegister(param_1,0);
          puVar5 = *(undefined4 **)(param_1 + 0xe30);
          *puVar5 = 0x39e00010;
          puVar5[1] = 0x7c0678ce;
          *(undefined4 **)(param_1 + 0xe30) = puVar5 + 2;
          iVar9 = _glpRTCAddAChunk_97bd7cbc(&_glpOpClippingAVRTC,puVar5 + 2);
          in_r9 = (undefined4 *)(*(int *)(param_1 + 0xe30) + iVar9 * 4);
          *(undefined4 **)(param_1 + 0xe30) = in_r9;
        }
        *(undefined4 **)(param_1 + 0xe3c) = in_r9;
        _PPCRuntimeCompilerBackupRegister(param_1,0);
        _PPCRuntimeCompilerBackupRegister(param_1,1);
        _PPCRuntimeCompilerBackupRegister(param_1,2);
        _PPCRuntimeCompilerDirtyRegistersContainingAttributes(param_1);
        _PPCRuntimeCompilerDirtyRegistersContainingTemps(param_1);
        _PPCRuntimeCompilerDirtyRegistersContainingParams(param_1);
        _PPCRuntimeCompilerInitialiseVariableInfo(param_1);
        uVar8 = *(undefined4 *)(param_1 + 0xe38);
        uVar15 = extraout_r4_12;
        goto LAB_97be1ac8;
      }
      if (iVar21 == 3) {
        if ((*(int *)(iVar9 + 0x38) == 0x8804) || (*(int *)(iVar9 + 0x38) == 0x8b30)) {
          if ((*(uint *)(iVar9 + 0x34) & 2) != 0) {
            ((int (*)())_PPCRuntimeCompilerWriteFinalFragmentToBuffer)(param_1,uVar15,in_r5,in_r6,in_r7,in_r8,in_r9,in_r10);
          }
        }
        else {
          _PPCRuntimeCompilerBackupRegister(param_1,0);
          puVar5 = *(undefined4 **)(param_1 + 0xe30);
          *puVar5 = 0x39e00010;
          puVar5[1] = 0x7c0678ce;
          *(undefined4 **)(param_1 + 0xe30) = puVar5 + 2;
          iVar9 = _glpRTCAddAChunk_97bd7cbc(&_glpOpClippingAVRTC,puVar5 + 2);
          *(int *)(param_1 + 0xe30) = *(int *)(param_1 + 0xe30) + iVar9 * 4;
        }
        ((int (*)())_PPCRuntimeCompilerStride)(param_1);
        ((int (*)())_PPCRuntimeCompilerLoop)(param_1);
        iVar21 = *(int *)(param_1 + 0xe48);
        uVar15 = extraout_r4_13;
      }
    }
    *(uint *)(param_1 + 0xe48) = iVar21 + 1U;
    if (3 < iVar21 + 1U) {
      ((int (*)())_PPCRuntimeCompilerWriteEpilogAV)(param_1);
      iVar19 = *(int *)(param_1 + 0xe30) - *(int *)(param_1 + 0xe2c) >> 2;
      uVar15 = _glpDCBRealloc(*(int *)(param_1 + 0xe2c),iVar19 << 2);
      *(undefined4 *)(param_1 + 0xe2c) = uVar15;
                    
                    
      (*_glpPushInstructions)(iVar19,uVar15,in_r5,in_r6,in_r7,in_r8,in_r9,in_r10);
      return;
    }
  } while( true );
}

/* _PPCRuntimeCompilerGetCompiledResult @ 0x97be1be0 (8 bytes) */
int _PPCRuntimeCompilerGetCompiledResult(param_1)
  int param_1;
{
  return *(undefined4 *)(param_1 + 0xe2c);
}

/* _PPCTextureSamplerCreate @ 0x97be1be8 (12 bytes) */
int _PPCTextureSamplerCreate()
{
  undefined4 uVar1;
  
  uVar1 = _calloc(0x2c,1);
  return uVar1;
}

/* _PPCTextureSamplerInitialise @ 0x97be1bf4 (16 bytes) */
int _PPCTextureSamplerInitialise(param_1)
  int param_1;
{
  *(undefined4 *)(param_1 + 0x18) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x14) = 0xffffffff;
  return;
}

/* _PPCTextureSamplerAttachGLDContext @ 0x97be1c08 (8 bytes) */
int _PPCTextureSamplerAttachGLDContext(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  *param_1 = param_2;
  return;
}

/* _PPCTextureSamplerSetProjectionEnabled @ 0x97be1c10 (8 bytes) */
int _PPCTextureSamplerSetProjectionEnabled(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  *(undefined4 *)(param_1 + 0x20) = param_2;
  return;
}

/* _PPCTextureSamplerSetLodBiasEnabled @ 0x97be1c18 (8 bytes) */
int _PPCTextureSamplerSetLodBiasEnabled(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  *(undefined4 *)(param_1 + 0x24) = param_2;
  return;
}

/* _PPCTextureSamplerAttachDerivatives @ 0x97be1c20 (12 bytes) */
void _PPCTextureSamplerAttachDerivatives(int param_1,undefined4 param_2,double fparam_1)
{
  *(float *)(param_1 + 0x10) = (float)fparam_1;
  *(undefined4 *)(param_1 + 0xc) = param_2;
  return;
}

/* _glpRTCAddAChunk_97be1c2c @ 0x97be1c2c (48 bytes) */
int _glpRTCAddAChunk_97be1c2c(param_1, param_2)
  int *param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = *param_1;
  while (iVar1 != 0) {
    *param_2 = iVar1;
    iVar2 = iVar2 + 1;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
    iVar1 = *param_1;
  }
  return iVar2;
}

/* _PPCTextureSamplerSampleTexel1DRTCNO @ 0x97be1c5c (8 bytes) */
int _PPCTextureSamplerSampleTexel1DRTCNO(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  return param_3;
}

/* _PPCTextureSamplerSampleTexel2DRTCNO @ 0x97be1c64 (560 bytes) */
int _PPCTextureSamplerSampleTexel2DRTCNO(param_1, param_2, param_3)
  int *param_1;
  uint param_2;
  uint *param_3;
{
  short sVar1;
  short sVar2;
  uint uVar3;
  int *piVar4;
  undefined *puVar5;
  int iVar6;
  int iVar7;
  uint *puVar8;
  
  if (7 < param_2) {
    param_2 = 7;
  }
  piVar4 = *(int **)(param_2 * 4 + *param_1);
  if (piVar4 != (int *)0x0) {
    param_1[1] = (int)piVar4;
    sVar1 = *(short *)(*piVar4 + 0x10);
    sVar2 = *(short *)(*piVar4 + 0x12);
    if ((sVar1 == -0x7ed3) || (sVar2 == -0x7ed3)) {
      iVar7 = 0x812d;
    }
    else if ((sVar1 == 0x2900) || (iVar7 = 0, sVar2 == 0x2900)) {
      iVar7 = 0x2900;
    }
    if (((param_1[5] != param_2) || (param_1[6] != 3)) || (param_1[7] != iVar7)) {
      *param_3 = param_2 * 4 & 0xfffc | 0x82220000;
      puVar8 = param_3 + 1;
      if (sVar1 == 0x2901) {
        *puVar8 = 0x82910160;
        puVar8 = param_3 + 2;
      }
      if (sVar2 == 0x2901) {
        *puVar8 = 0x82b10164;
        puVar8 = puVar8 + 1;
      }
      if (iVar7 == 0x812d) {
        *puVar8 = 0x82510190;
        puVar8[1] = 0xc1d10170;
        puVar8[2] = 0xc1f10174;
        uVar3 = 0x823101c4;
      }
      else if (iVar7 == 0x2900) {
        *puVar8 = 0x82510190;
        puVar8[1] = 0xc1d10170;
        puVar8[2] = 0xc1f10174;
        uVar3 = 0x823101c8;
      }
      else {
        *puVar8 = 0x82510140;
        puVar8[1] = 0xc1d10120;
        puVar8[2] = 0xc1f10124;
        uVar3 = 0x823101c0;
      }
      puVar8[3] = uVar3;
      param_3 = puVar8 + 4;
      param_1[7] = iVar7;
      param_1[5] = param_2;
      param_1[6] = 3;
    }
    if (sVar1 == 0x2901) {
      if (sVar2 == 0x2901) {
        puVar5 = &_glpOpTexPrepareCoords2RRRTC;
      }
      else {
        puVar5 = &_glpOpTexPrepareCoords2RCRTC;
      }
    }
    else if (sVar2 == 0x2901) {
      puVar5 = &_glpOpTexPrepareCoords2CRRTC;
    }
    else {
      puVar5 = &_glpOpTexPrepareCoords2CCRTC;
    }
    iVar7 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(puVar5,param_3);
    iVar6 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSampleRTC,param_3 + iVar7);
    param_3 = param_3 + iVar7 + iVar6;
  }
  return param_3;
}

/* _PPCTextureSamplerSampleTexel3DRTCNO @ 0x97be1e94 (8 bytes) */
int _PPCTextureSamplerSampleTexel3DRTCNO(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  return param_3;
}

/* _PPCTextureSamplerSampleTexelRECTRTCNO @ 0x97be1e9c (488 bytes) */
int _PPCTextureSamplerSampleTexelRECTRTCNO(param_1, param_2, param_3)
  int *param_1;
  uint param_2;
  uint *param_3;
{
  short sVar1;
  short sVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  uint *puVar7;
  
  if (7 < param_2) {
    param_2 = 7;
  }
  piVar4 = *(int **)(param_2 * 4 + *param_1);
  if (piVar4 != (int *)0x0) {
    param_1[1] = (int)piVar4;
    sVar1 = *(short *)(*piVar4 + 0x10);
    sVar2 = *(short *)(*piVar4 + 0x12);
    if ((sVar1 == -0x7ed3) || (sVar2 == -0x7ed3)) {
      iVar6 = 0x812d;
    }
    else if ((sVar1 == 0x2900) || (iVar6 = 0, sVar2 == 0x2900)) {
      iVar6 = 0x2900;
    }
    if ((param_1[5] != param_2) || (param_1[6] != 2)) {
      *param_3 = param_2 * 4 & 0xfffc | 0x82220000;
      puVar7 = param_3 + 1;
      if (sVar1 == 0x2901) {
        *puVar7 = 0x82910160;
        puVar7 = param_3 + 2;
      }
      if (sVar2 == 0x2901) {
        *puVar7 = 0x82b10164;
        puVar7 = puVar7 + 1;
      }
      if (iVar6 == 0x812d) {
        *puVar7 = 0x82510190;
        puVar7[1] = 0xc1d10170;
        puVar7[2] = 0xc1f10174;
        uVar3 = 0x823101c4;
      }
      else if (iVar6 == 0x2900) {
        *puVar7 = 0x82510190;
        puVar7[1] = 0xc1d10170;
        puVar7[2] = 0xc1f10174;
        uVar3 = 0x823101c8;
      }
      else {
        *puVar7 = 0x82510140;
        puVar7[1] = 0xc1d10120;
        puVar7[2] = 0xc1f10124;
        uVar3 = 0x823101c0;
      }
      puVar7[3] = uVar3;
      param_3 = puVar7 + 4;
      param_1[7] = iVar6;
      param_1[5] = param_2;
      param_1[6] = 2;
    }
    iVar6 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexPrepareCoords4CCRTC,param_3);
    iVar5 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSampleRTC,param_3 + iVar6);
    param_3 = param_3 + iVar6 + iVar5;
  }
  return param_3;
}

/* _PPCTextureSamplerWrapCoordinates1DRTCAV @ 0x97be2084 (144 bytes) */
int _PPCTextureSamplerWrapCoordinates1DRTCAV(param_1, param_2)
  int param_1;
  int param_2;
{
  short sVar1;
  short sVar2;
  undefined *puVar3;
  int iVar4;
  
  sVar1 = *(short *)(**(int **)(param_1 + 4) + 0x16);
  sVar2 = *(short *)(**(int **)(param_1 + 4) + 0x10);
  if (((sVar1 == 0x2600) || (sVar1 == 0x2700)) && (sVar2 == 0x2900)) {
    sVar2 = -0x7ed1;
  }
  if (sVar2 == 0x2901) {
    puVar3 = &_glpOpTexWrapCoordsRRRAVRTC;
  }
  else {
    puVar3 = &_glpOpTexWrapCoordsCCCAVRTC;
  }
  iVar4 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(puVar3,param_2);
  return param_2 + iVar4 * 4;
}

/* _PPCTextureSamplerWrapCoordinates2DRTCAV @ 0x97be2114 (212 bytes) */
int _PPCTextureSamplerWrapCoordinates2DRTCAV(param_1, param_2)
  int param_1;
  int param_2;
{
  short sVar1;
  undefined *puVar2;
  int iVar3;
  short sVar4;
  
  iVar3 = **(int **)(param_1 + 4);
  sVar1 = *(short *)(iVar3 + 0x10);
  sVar4 = *(short *)(iVar3 + 0x12);
  if ((*(short *)(iVar3 + 0x16) == 0x2600) || (*(short *)(iVar3 + 0x16) == 0x2700)) {
    if (sVar1 == 0x2900) {
      sVar1 = -0x7ed1;
    }
    if (sVar4 == 0x2900) {
      sVar4 = -0x7ed1;
    }
  }
  if (sVar1 == 0x2901) {
    if (sVar4 == 0x2901) {
      puVar2 = &_glpOpTexWrapCoordsRRRAVRTC;
    }
    else {
      puVar2 = &_glpOpTexWrapCoordsRCCAVRTC;
    }
  }
  else if (sVar4 == 0x2901) {
    puVar2 = &_glpOpTexWrapCoordsCRRAVRTC;
  }
  else {
    puVar2 = &_glpOpTexWrapCoordsCCCAVRTC;
  }
  iVar3 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(puVar2,param_2);
  return param_2 + iVar3 * 4;
}

/* _PPCTextureSamplerWrapCoordinates3DRTCAV @ 0x97be21e8 (328 bytes) */
int _PPCTextureSamplerWrapCoordinates3DRTCAV(param_1, param_2)
  int param_1;
  int param_2;
{
  short sVar1;
  undefined *puVar2;
  int iVar3;
  short sVar4;
  short sVar5;
  
  iVar3 = **(int **)(param_1 + 4);
  sVar1 = *(short *)(iVar3 + 0x10);
  sVar5 = *(short *)(iVar3 + 0x12);
  sVar4 = *(short *)(iVar3 + 0x14);
  if ((*(short *)(iVar3 + 0x16) == 0x2600) || (*(short *)(iVar3 + 0x16) == 0x2700)) {
    if (sVar1 == 0x2900) {
      sVar1 = -0x7ed1;
    }
    if (sVar5 == 0x2900) {
      sVar5 = -0x7ed1;
    }
    if (sVar4 == 0x2900) {
      sVar4 = -0x7ed1;
    }
  }
  if (sVar1 == 0x2901) {
    if (sVar5 == 0x2901) {
      if (sVar4 == 0x2901) {
        puVar2 = &_glpOpTexWrapCoordsRRRAVRTC;
      }
      else {
        puVar2 = &_glpOpTexWrapCoordsRRCAVRTC;
      }
    }
    else if (sVar4 == 0x2901) {
      puVar2 = &_glpOpTexWrapCoordsRCRAVRTC;
    }
    else {
      puVar2 = &_glpOpTexWrapCoordsRCCAVRTC;
    }
  }
  else if (sVar5 == 0x2901) {
    if (sVar4 == 0x2901) {
      puVar2 = &_glpOpTexWrapCoordsCRRAVRTC;
    }
    else {
      puVar2 = &_glpOpTexWrapCoordsCRCAVRTC;
    }
  }
  else if (sVar4 == 0x2901) {
    puVar2 = &_glpOpTexWrapCoordsCCRAVRTC;
  }
  else {
    puVar2 = &_glpOpTexWrapCoordsCCCAVRTC;
  }
  iVar3 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(puVar2,param_2);
  return param_2 + iVar3 * 4;
}

/* _PPCTextureSamplerSampleTexel1DRTCAV @ 0x97be2330 (780 bytes) */
int _PPCTextureSamplerSampleTexel1DRTCAV(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  uint *param_3;
{
  uint *puVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  int *piVar5;
  uint *puVar6;
  
  piVar5 = *(int **)(param_2 * 4 + *param_1);
  if (*(ushort *)(*piVar5 + 0x16) - 0x2700 < 4) {
    param_1[10] = 1;
    if (param_1[9] != 0) {
      *param_3 = 0x39e00200;
      param_3[1] = 0x7c4379ce;
      param_3 = param_3 + 2;
    }
    uVar4 = param_2 * 4 & 0xfffcU | 0x82220000;
    *param_3 = uVar4;
    param_3[1] = 0x39e00120;
    param_3[2] = 0x7df178ce;
    param_3[3] = 0x39e00040;
    param_3[4] = 0x7c2c78ce;
    param_3[5] = 0x39ef00c0;
    param_3[6] = 0x7c4c78ce;
    iVar2 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexCalculateLambda1DAVRTC,param_3 + 7);
    puVar1 = param_3 + 7 + iVar2;
    *puVar1 = 0x39e00040;
    puVar1[1] = 0x7c9178ce;
    puVar1[2] = 0x1063200a;
    puVar6 = puVar1 + 3;
    if (param_1[9] != 0) {
      *puVar6 = 0x39e00200;
      puVar1[4] = 0x7c4378ce;
      puVar1[5] = 0x1063100a;
      puVar6 = puVar1 + 6;
    }
    *puVar6 = 0x39e00030;
    puVar6[1] = 0x7c3178ce;
    puVar6[2] = 0x39e00020;
    puVar6[3] = 0x7c5178ce;
    puVar6[4] = 0x1063144a;
    puVar6[5] = 0x10630c0a;
    puVar6[6] = 0x10601a8c;
    puVar6[7] = 0x10801b8a;
    puVar6[8] = 0x39e00200;
    puVar6[9] = 0x7c8379ce;
    puVar6[10] = 0x7f03782e;
    if (*(ushort *)(*piVar5 + 0x16) - 0x2700 < 2) {
      puVar3 = (undefined4 *)
               ((int (*)())_PPCTextureSamplerSampleTexel1DFromLevelRTCAV)(param_1,param_2,puVar6 + 0xb);
    }
    else {
      puVar6[0xb] = 0x10801aca;
      puVar6[0xc] = 0x1083204a;
      puVar6[0xd] = 0x39e00210;
      puVar6[0xe] = 0x7c8379ce;
      puVar6[0xf] = 0x39e00230;
      puVar6[0x10] = 0x7c0379ce;
      puVar3 = (undefined4 *)
               ((int (*)())_PPCTextureSamplerSampleTexel1DFromLevelRTCAV)(param_1,param_2,puVar6 + 0x11);
      *puVar3 = 0x39e00220;
      puVar3[1] = 0x7c4379ce;
      puVar3[2] = 0x3b180001;
      puVar3[3] = 0x39e00230;
      puVar3[4] = 0x7c0378ce;
      puVar3[5] = uVar4;
      puVar3 = (undefined4 *)
               ((int (*)())_PPCTextureSamplerSampleTexel1DFromLevelRTCAV)(param_1,param_2,puVar3 + 6);
      *puVar3 = 0x39e00220;
      puVar3[1] = 0x7c2378ce;
      puVar3[2] = 0x39e00210;
      puVar3[3] = 0x7c0378ce;
      puVar3[4] = 0x1000028c;
      puVar3[5] = 0x1068004a;
      puVar3[6] = 0x1063386e;
      puVar3[7] = 0x104018ae;
      puVar3 = puVar3 + 8;
    }
    return puVar3;
  }
  param_1[10] = 0;
  puVar3 = (undefined4 *)((int (*)())_PPCTextureSamplerSampleTexel1DFromLevelRTCAV)(param_1,param_2,param_3);
  return puVar3;
}

/* _PPCTextureSamplerSampleTexel2DRTCAV @ 0x97be263c (780 bytes) */
int _PPCTextureSamplerSampleTexel2DRTCAV(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  uint *param_3;
{
  uint *puVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  int *piVar5;
  uint *puVar6;
  
  piVar5 = *(int **)(param_2 * 4 + *param_1);
  if (*(ushort *)(*piVar5 + 0x16) - 0x2700 < 4) {
    param_1[10] = 1;
    if (param_1[9] != 0) {
      *param_3 = 0x39e00200;
      param_3[1] = 0x7c4379ce;
      param_3 = param_3 + 2;
    }
    uVar4 = param_2 * 4 & 0xfffcU | 0x82220000;
    *param_3 = uVar4;
    param_3[1] = 0x39e00120;
    param_3[2] = 0x7df178ce;
    param_3[3] = 0x39e00040;
    param_3[4] = 0x7c2c78ce;
    param_3[5] = 0x39ef00c0;
    param_3[6] = 0x7c4c78ce;
    iVar2 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexCalculateLambda2DAVRTC,param_3 + 7);
    puVar1 = param_3 + 7 + iVar2;
    *puVar1 = 0x39e00040;
    puVar1[1] = 0x7c9178ce;
    puVar1[2] = 0x1063200a;
    puVar6 = puVar1 + 3;
    if (param_1[9] != 0) {
      *puVar6 = 0x39e00200;
      puVar1[4] = 0x7c4378ce;
      puVar1[5] = 0x1063100a;
      puVar6 = puVar1 + 6;
    }
    *puVar6 = 0x39e00030;
    puVar6[1] = 0x7c3178ce;
    puVar6[2] = 0x39e00020;
    puVar6[3] = 0x7c5178ce;
    puVar6[4] = 0x1063144a;
    puVar6[5] = 0x10630c0a;
    puVar6[6] = 0x10601a8c;
    puVar6[7] = 0x10801b8a;
    puVar6[8] = 0x39e00200;
    puVar6[9] = 0x7c8379ce;
    puVar6[10] = 0x7f03782e;
    if (*(ushort *)(*piVar5 + 0x16) - 0x2700 < 2) {
      puVar3 = (undefined4 *)
               ((int (*)())_PPCTextureSamplerSampleTexel2DFromLevelRTCAV)(param_1,param_2,puVar6 + 0xb);
    }
    else {
      puVar6[0xb] = 0x10801aca;
      puVar6[0xc] = 0x1083204a;
      puVar6[0xd] = 0x39e00210;
      puVar6[0xe] = 0x7c8379ce;
      puVar6[0xf] = 0x39e00230;
      puVar6[0x10] = 0x7c0379ce;
      puVar3 = (undefined4 *)
               ((int (*)())_PPCTextureSamplerSampleTexel2DFromLevelRTCAV)(param_1,param_2,puVar6 + 0x11);
      *puVar3 = 0x39e00220;
      puVar3[1] = 0x7c4379ce;
      puVar3[2] = 0x3b180001;
      puVar3[3] = 0x39e00230;
      puVar3[4] = 0x7c0378ce;
      puVar3[5] = uVar4;
      puVar3 = (undefined4 *)
               ((int (*)())_PPCTextureSamplerSampleTexel2DFromLevelRTCAV)(param_1,param_2,puVar3 + 6);
      *puVar3 = 0x39e00220;
      puVar3[1] = 0x7c2378ce;
      puVar3[2] = 0x39e00210;
      puVar3[3] = 0x7c0378ce;
      puVar3[4] = 0x1000028c;
      puVar3[5] = 0x1068004a;
      puVar3[6] = 0x1063386e;
      puVar3[7] = 0x104018ae;
      puVar3 = puVar3 + 8;
    }
    return puVar3;
  }
  param_1[10] = 0;
  puVar3 = (undefined4 *)((int (*)())_PPCTextureSamplerSampleTexel2DFromLevelRTCAV)(param_1,param_2,param_3);
  return puVar3;
}

/* _PPCTextureSamplerSampleTexel3DRTCAV @ 0x97be2948 (780 bytes) */
int _PPCTextureSamplerSampleTexel3DRTCAV(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  uint *param_3;
{
  uint *puVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  int *piVar5;
  uint *puVar6;
  
  piVar5 = *(int **)(param_2 * 4 + *param_1);
  if (*(ushort *)(*piVar5 + 0x16) - 0x2700 < 4) {
    param_1[10] = 1;
    if (param_1[9] != 0) {
      *param_3 = 0x39e00200;
      param_3[1] = 0x7c4379ce;
      param_3 = param_3 + 2;
    }
    uVar4 = param_2 * 4 & 0xfffcU | 0x82220000;
    *param_3 = uVar4;
    param_3[1] = 0x39e00120;
    param_3[2] = 0x7df178ce;
    param_3[3] = 0x39e00040;
    param_3[4] = 0x7c2c78ce;
    param_3[5] = 0x39ef00c0;
    param_3[6] = 0x7c4c78ce;
    iVar2 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexCalculateLambda3DAVRTC,param_3 + 7);
    puVar1 = param_3 + 7 + iVar2;
    *puVar1 = 0x39e00040;
    puVar1[1] = 0x7c9178ce;
    puVar1[2] = 0x1063200a;
    puVar6 = puVar1 + 3;
    if (param_1[9] != 0) {
      *puVar6 = 0x39e00200;
      puVar1[4] = 0x7c4378ce;
      puVar1[5] = 0x1063100a;
      puVar6 = puVar1 + 6;
    }
    *puVar6 = 0x39e00030;
    puVar6[1] = 0x7c3178ce;
    puVar6[2] = 0x39e00020;
    puVar6[3] = 0x7c5178ce;
    puVar6[4] = 0x1063144a;
    puVar6[5] = 0x10630c0a;
    puVar6[6] = 0x10601a8c;
    puVar6[7] = 0x10801b8a;
    puVar6[8] = 0x39e00200;
    puVar6[9] = 0x7c8379ce;
    puVar6[10] = 0x7f03782e;
    if (*(ushort *)(*piVar5 + 0x16) - 0x2700 < 2) {
      puVar3 = (undefined4 *)
               ((int (*)())_PPCTextureSamplerSampleTexel3DFromLevelRTCAV)(param_1,param_2,puVar6 + 0xb);
    }
    else {
      puVar6[0xb] = 0x10801aca;
      puVar6[0xc] = 0x1083204a;
      puVar6[0xd] = 0x39e00210;
      puVar6[0xe] = 0x7c8379ce;
      puVar6[0xf] = 0x39e00230;
      puVar6[0x10] = 0x7c0379ce;
      puVar3 = (undefined4 *)
               ((int (*)())_PPCTextureSamplerSampleTexel3DFromLevelRTCAV)(param_1,param_2,puVar6 + 0x11);
      *puVar3 = 0x39e00220;
      puVar3[1] = 0x7c4379ce;
      puVar3[2] = 0x3b180001;
      puVar3[3] = 0x39e00230;
      puVar3[4] = 0x7c0378ce;
      puVar3[5] = uVar4;
      puVar3 = (undefined4 *)
               ((int (*)())_PPCTextureSamplerSampleTexel3DFromLevelRTCAV)(param_1,param_2,puVar3 + 6);
      *puVar3 = 0x39e00220;
      puVar3[1] = 0x7c2378ce;
      puVar3[2] = 0x39e00210;
      puVar3[3] = 0x7c0378ce;
      puVar3[4] = 0x1000028c;
      puVar3[5] = 0x1068004a;
      puVar3[6] = 0x1063386e;
      puVar3[7] = 0x104018ae;
      puVar3 = puVar3 + 8;
    }
    return puVar3;
  }
  param_1[10] = 0;
  puVar3 = (undefined4 *)((int (*)())_PPCTextureSamplerSampleTexel3DFromLevelRTCAV)(param_1,param_2,param_3);
  return puVar3;
}

/* _PPCTextureSamplerSampleTexel1DFromLevelRTCAV @ 0x97be2c58 (960 bytes) */
int _PPCTextureSamplerSampleTexel1DFromLevelRTCAV(param_1, param_2, param_3)
  int *param_1;
  uint param_2;
  uint *param_3;
{
  bool bVar1;
  short sVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  uint *puVar9;
  undefined4 *puVar10;
  
  if (7 < param_2) {
    param_2 = 7;
  }
  piVar8 = *(int **)(param_2 * 4 + *param_1);
  if (piVar8 == (int *)0x0) {
    return param_3;
  }
  param_1[1] = (int)piVar8;
  iVar5 = *piVar8;
  iVar7 = 0x812d;
  sVar2 = *(short *)(iVar5 + 0x10);
  if ((sVar2 != -0x7ed3) &&
     (((sVar2 != 0x2900 || (*(short *)(iVar5 + 0x16) == 0x2600)) ||
      (iVar7 = 0x2900, *(short *)(iVar5 + 0x16) == 0x2700)))) {
    iVar7 = 0;
  }
  if (((param_1[5] == param_2) && (param_1[6] == 4)) && (param_1[7] == iVar7)) {
    iVar4 = param_1[10];
    if (iVar4 != 0) goto LAB_97be2d14;
  }
  else {
    iVar4 = param_1[10];
LAB_97be2d14:
    if (iVar4 == 0) {
      uVar6 = 0x3a310120;
      *param_3 = param_2 * 4 & 0xfffc | 0x82220000;
    }
    else {
      *param_3 = 0x1ef800d0;
      uVar6 = 0x7e31ba14;
      param_3 = param_3 + 1;
      *param_3 = 0x3a310120;
    }
    param_3[1] = uVar6;
    puVar9 = param_3 + 2;
    if (sVar2 == 0x2901) {
      *puVar9 = 0x39e00040;
      param_3[3] = 0x7e3178ce;
      puVar9 = param_3 + 4;
    }
    if (iVar7 == 0x812d) {
      *puVar9 = 0x82510070;
      puVar9[1] = 0x39e00050;
      puVar9[2] = 0x7df178ce;
      puVar9[3] = 0x39e00080;
      puVar9[4] = 0x7e1178ce;
      uVar6 = 0x823100a4;
    }
    else if (iVar7 == 0x2900) {
      *puVar9 = 0x82510070;
      puVar9[1] = 0x39e00050;
      puVar9[2] = 0x7df178ce;
      puVar9[3] = 0x39e00080;
      puVar9[4] = 0x7e1178ce;
      uVar6 = 0x823100a8;
    }
    else {
      *puVar9 = 0x82510020;
      puVar9[1] = 0x39e00000;
      puVar9[2] = 0x7df178ce;
      puVar9[3] = 0x39e00030;
      puVar9[4] = 0x7e1178ce;
      uVar6 = 0x823100a0;
    }
    puVar9[5] = uVar6;
    param_1[5] = param_2;
    param_3 = puVar9 + 6;
    param_1[6] = 4;
    param_1[7] = iVar7;
    iVar5 = *piVar8;
  }
  uVar3 = *(ushort *)(iVar5 + 0x16);
  if (uVar3 == 0x2700) {
LAB_97be2ebc:
    if (param_1[8] != 0) {
      iVar5 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexProjectCoordinatesAVRTC,param_3);
      param_3 = param_3 + iVar5;
    }
    iVar5 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexFloatToIntNormalisedAVRTC,param_3);
    iVar5 = ((int (*)())_PPCTextureSamplerWrapCoordinates1DRTCAV)(param_1,param_3 + iVar5);
    iVar7 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample1DAVRTC,iVar5);
    puVar10 = (undefined4 *)(iVar5 + iVar7 * 4);
    *puVar10 = 0x10431c84;
  }
  else {
    if (uVar3 < 0x2701) {
      if (uVar3 == 0x2600) goto LAB_97be2ebc;
      bVar1 = uVar3 == 0x2601;
LAB_97be2eb4:
      if (!bVar1) {
        return param_3;
      }
    }
    else {
      if (uVar3 == 0x2702) goto LAB_97be2ebc;
      if (0x2701 < uVar3) {
        bVar1 = uVar3 == 0x2703;
        goto LAB_97be2eb4;
      }
    }
    if (param_1[8] != 0) {
      iVar5 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexProjectCoordinatesAVRTC,param_3);
      param_3 = param_3 + iVar5;
    }
    iVar5 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexFloatToIntNormalisedWithLERPValuesAVRTC,param_3);
    param_3[iVar5] = 0x10c00484;
    iVar5 = ((int (*)())_PPCTextureSamplerWrapCoordinates1DRTCAV)(param_1,param_3 + iVar5 + 1);
    iVar7 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample1DAVRTC,iVar5);
    puVar10 = (undefined4 *)(iVar5 + iVar7 * 4);
    *puVar10 = 0x1020228c;
    puVar10[1] = 0x104138ee;
    puVar10[2] = 0x100a4b2c;
    puVar10[3] = 0x10060780;
    iVar5 = ((int (*)())_PPCTextureSamplerWrapCoordinates1DRTCAV)(param_1,puVar10 + 4);
    iVar7 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample1DAVRTC,iVar5);
    puVar10 = (undefined4 *)(iVar5 + iVar7 * 4);
    *puVar10 = 0x10202a8c;
    puVar10 = puVar10 + 1;
    *puVar10 = 0x104110ee;
  }
  return puVar10 + 1;
}

/* _PPCTextureSamplerSampleTexel2DFromLevelRTCAV @ 0x97be3018 (1172 bytes) */
int _PPCTextureSamplerSampleTexel2DFromLevelRTCAV(param_1, param_2, param_3)
  int *param_1;
  uint param_2;
  uint *param_3;
{
  bool bVar1;
  short sVar2;
  short sVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  uint *puVar10;
  undefined4 *puVar11;
  
  if (7 < param_2) {
    param_2 = 7;
  }
  piVar9 = *(int **)(param_2 * 4 + *param_1);
  if (piVar9 == (int *)0x0) {
    return param_3;
  }
  param_1[1] = (int)piVar9;
  iVar6 = *piVar9;
  sVar2 = *(short *)(iVar6 + 0x10);
  sVar3 = *(short *)(iVar6 + 0x12);
  if ((sVar2 == -0x7ed3) || (sVar3 == -0x7ed3)) {
    iVar8 = 0x812d;
  }
  else if ((((sVar2 != 0x2900) && (sVar3 != 0x2900)) || (*(short *)(iVar6 + 0x16) == 0x2600)) ||
          (iVar8 = 0x2900, *(short *)(iVar6 + 0x16) == 0x2700)) {
    iVar8 = 0;
  }
  if (((param_1[5] == param_2) && (param_1[6] == 3)) && (param_1[7] == iVar8)) {
    iVar5 = param_1[10];
    if (iVar5 != 0) goto LAB_97be30f0;
  }
  else {
    iVar5 = param_1[10];
LAB_97be30f0:
    if (iVar5 == 0) {
      uVar7 = 0x3a310120;
      *param_3 = param_2 * 4 & 0xfffc | 0x82220000;
    }
    else {
      *param_3 = 0x1ef800d0;
      uVar7 = 0x7e31ba14;
      param_3 = param_3 + 1;
      *param_3 = 0x3a310120;
    }
    param_3[1] = uVar7;
    puVar10 = param_3 + 2;
    if ((sVar2 == 0x2901) || (sVar3 == 0x2901)) {
      *puVar10 = 0x39e00040;
      param_3[3] = 0x7e3178ce;
      puVar10 = param_3 + 4;
    }
    if (iVar8 == 0x812d) {
      *puVar10 = 0x82510070;
      puVar10[1] = 0x39e00050;
      puVar10[2] = 0x7df178ce;
      puVar10[3] = 0x39e00080;
      puVar10[4] = 0x7e1178ce;
      uVar7 = 0x823100a4;
    }
    else if (iVar8 == 0x2900) {
      *puVar10 = 0x82510070;
      puVar10[1] = 0x39e00050;
      puVar10[2] = 0x7df178ce;
      puVar10[3] = 0x39e00080;
      puVar10[4] = 0x7e1178ce;
      uVar7 = 0x823100a8;
    }
    else {
      *puVar10 = 0x82510020;
      puVar10[1] = 0x39e00000;
      puVar10[2] = 0x7df178ce;
      puVar10[3] = 0x39e00030;
      puVar10[4] = 0x7e1178ce;
      uVar7 = 0x823100a0;
    }
    puVar10[5] = uVar7;
    param_1[5] = param_2;
    param_3 = puVar10 + 6;
    param_1[6] = 3;
    param_1[7] = iVar8;
    iVar6 = *piVar9;
  }
  uVar4 = *(ushort *)(iVar6 + 0x16);
  if (uVar4 == 0x2700) {
LAB_97be32a0:
    if (param_1[8] != 0) {
      iVar6 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexProjectCoordinatesAVRTC,param_3);
      param_3 = param_3 + iVar6;
    }
    iVar6 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexFloatToIntNormalisedAVRTC,param_3);
    iVar6 = ((int (*)())_PPCTextureSamplerWrapCoordinates2DRTCAV)(param_1,param_3 + iVar6);
    iVar8 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample2DAVRTC,iVar6);
    puVar11 = (undefined4 *)(iVar6 + iVar8 * 4);
    *puVar11 = 0x10431c84;
  }
  else {
    if (uVar4 < 0x2701) {
      if (uVar4 == 0x2600) goto LAB_97be32a0;
      bVar1 = uVar4 == 0x2601;
LAB_97be3298:
      if (!bVar1) {
        return param_3;
      }
    }
    else {
      if (uVar4 == 0x2702) goto LAB_97be32a0;
      if (0x2701 < uVar4) {
        bVar1 = uVar4 == 0x2703;
        goto LAB_97be3298;
      }
    }
    if (param_1[8] != 0) {
      iVar6 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexProjectCoordinatesAVRTC,param_3);
      param_3 = param_3 + iVar6;
    }
    iVar6 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexFloatToIntNormalisedWithLERPValuesAVRTC,param_3);
    param_3[iVar6] = 0x10c00484;
    iVar6 = ((int (*)())_PPCTextureSamplerWrapCoordinates2DRTCAV)(param_1,param_3 + iVar6 + 1);
    iVar8 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample2DAVRTC,iVar6);
    puVar11 = (undefined4 *)(iVar6 + iVar8 * 4);
    *puVar11 = 0x1024492c;
    puVar11[1] = 0x1021392e;
    puVar11[2] = 0x10200a8c;
    puVar11[3] = 0x104138ee;
    puVar11[4] = 0x100a4a2c;
    puVar11[5] = 0x10060780;
    iVar6 = ((int (*)())_PPCTextureSamplerWrapCoordinates2DRTCAV)(param_1,puVar11 + 6);
    iVar8 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample2DAVRTC,iVar6);
    puVar11 = (undefined4 *)(iVar6 + iVar8 * 4);
    *puVar11 = 0x1025492c;
    puVar11[1] = 0x1021392e;
    puVar11[2] = 0x10200a8c;
    puVar11[3] = 0x104110ee;
    puVar11[4] = 0x100a4b2c;
    puVar11[5] = 0x10060780;
    iVar6 = ((int (*)())_PPCTextureSamplerWrapCoordinates2DRTCAV)(param_1,puVar11 + 6);
    iVar8 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample2DAVRTC,iVar6);
    puVar11 = (undefined4 *)(iVar6 + iVar8 * 4);
    *puVar11 = 0x1024492c;
    puVar11[1] = 0x1021396e;
    puVar11[2] = 0x10200a8c;
    puVar11[3] = 0x104110ee;
    puVar11[4] = 0x1003528c;
    puVar11[5] = 0x10060780;
    iVar6 = ((int (*)())_PPCTextureSamplerWrapCoordinates2DRTCAV)(param_1,puVar11 + 6);
    iVar8 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample2DAVRTC,iVar6);
    puVar11 = (undefined4 *)(iVar6 + iVar8 * 4);
    *puVar11 = 0x1025492c;
    puVar11[1] = 0x1021396e;
    puVar11[2] = 0x10200a8c;
    puVar11 = puVar11 + 3;
    *puVar11 = 0x104110ee;
  }
  return puVar11 + 1;
}

/* _PPCTextureSamplerSampleTexel3DFromLevelRTCAV @ 0x97be34ac (1612 bytes) */
int _PPCTextureSamplerSampleTexel3DFromLevelRTCAV(param_1, param_2, param_3)
  int *param_1;
  uint param_2;
  uint *param_3;
{
  bool bVar1;
  short sVar2;
  short sVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  int iVar9;
  uint *puVar10;
  undefined4 *puVar11;
  
  if (7 < param_2) {
    param_2 = 7;
  }
  piVar8 = *(int **)(param_2 * 4 + *param_1);
  if (piVar8 == (int *)0x0) {
    return param_3;
  }
  param_1[1] = (int)piVar8;
  iVar6 = *piVar8;
  sVar2 = *(short *)(iVar6 + 0x10);
  sVar3 = *(short *)(iVar6 + 0x12);
  if (((sVar2 == -0x7ed3) || (sVar3 == -0x7ed3)) || (*(short *)(iVar6 + 0x14) == -0x7ed3)) {
    iVar9 = 0x812d;
  }
  else if ((((sVar2 != 0x2900) && (sVar3 != 0x2900)) && (*(short *)(iVar6 + 0x14) != 0x2900)) ||
          ((*(short *)(iVar6 + 0x16) == 0x2600 ||
           (iVar9 = 0x2900, *(short *)(iVar6 + 0x16) == 0x2700)))) {
    iVar9 = 0;
  }
  if (((param_1[5] == param_2) && (param_1[6] == 1)) && (param_1[7] == iVar9)) {
    iVar5 = param_1[10];
    if (iVar5 != 0) goto LAB_97be359c;
  }
  else {
    iVar5 = param_1[10];
LAB_97be359c:
    if (iVar5 == 0) {
      uVar7 = 0x3a310120;
      *param_3 = param_2 * 4 & 0xfffc | 0x82220000;
    }
    else {
      *param_3 = 0x1ef800d0;
      uVar7 = 0x7e31ba14;
      param_3 = param_3 + 1;
      *param_3 = 0x3a310120;
    }
    param_3[1] = uVar7;
    puVar10 = param_3 + 2;
    if ((sVar2 == 0x2901) || (sVar3 == 0x2901)) {
      *puVar10 = 0x39e00040;
      param_3[3] = 0x7e3178ce;
      puVar10 = param_3 + 4;
    }
    if (iVar9 == 0x812d) {
      *puVar10 = 0x82510070;
      puVar10[1] = 0x82710074;
      puVar10[2] = 0x39e00050;
      puVar10[3] = 0x7df178ce;
      puVar10[4] = 0x39e00080;
      puVar10[5] = 0x7e1178ce;
      uVar7 = 0x823100a4;
    }
    else if (iVar9 == 0x2900) {
      *puVar10 = 0x82510070;
      puVar10[1] = 0x82710074;
      puVar10[2] = 0x39e00050;
      puVar10[3] = 0x7df178ce;
      puVar10[4] = 0x39e00080;
      puVar10[5] = 0x7e1178ce;
      uVar7 = 0x823100a8;
    }
    else {
      *puVar10 = 0x82510020;
      puVar10[1] = 0x82710024;
      puVar10[2] = 0x39e00000;
      puVar10[3] = 0x7df178ce;
      puVar10[4] = 0x39e00030;
      puVar10[5] = 0x7e1178ce;
      uVar7 = 0x823100a0;
    }
    puVar10[6] = uVar7;
    param_1[5] = param_2;
    param_3 = puVar10 + 7;
    param_1[6] = 1;
    param_1[7] = iVar9;
    iVar6 = *piVar8;
  }
  uVar4 = *(ushort *)(iVar6 + 0x16);
  if (uVar4 == 0x2700) {
LAB_97be376c:
    if (param_1[8] != 0) {
      iVar6 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexProjectCoordinatesAVRTC,param_3);
      param_3 = param_3 + iVar6;
    }
    iVar6 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexFloatToIntNormalisedAVRTC,param_3);
    iVar6 = ((int (*)())_PPCTextureSamplerWrapCoordinates3DRTCAV)(param_1,param_3 + iVar6);
    iVar9 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample3DAVRTC,iVar6);
    puVar11 = (undefined4 *)(iVar6 + iVar9 * 4);
    *puVar11 = 0x10431c84;
  }
  else {
    if (uVar4 < 0x2701) {
      if (uVar4 == 0x2600) goto LAB_97be376c;
      bVar1 = uVar4 == 0x2601;
LAB_97be3764:
      if (!bVar1) {
        return param_3;
      }
    }
    else {
      if (uVar4 == 0x2702) goto LAB_97be376c;
      if (0x2701 < uVar4) {
        bVar1 = uVar4 == 0x2703;
        goto LAB_97be3764;
      }
    }
    if (param_1[8] != 0) {
      iVar6 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexProjectCoordinatesAVRTC,param_3);
      param_3 = param_3 + iVar6;
    }
    iVar6 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexFloatToIntNormalisedWithLERPValuesAVRTC,param_3);
    param_3[iVar6] = 0x10c00484;
    iVar6 = ((int (*)())_PPCTextureSamplerWrapCoordinates3DRTCAV)(param_1,param_3 + iVar6 + 1);
    iVar9 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample3DAVRTC,iVar6);
    puVar11 = (undefined4 *)(iVar6 + iVar9 * 4);
    *puVar11 = 0x1024492c;
    puVar11[1] = 0x1021392e;
    puVar11[2] = 0x10044a2c;
    puVar11[3] = 0x1021382e;
    puVar11[4] = 0x10200a8c;
    puVar11[5] = 0x104138ee;
    puVar11[6] = 0x100a4a2c;
    puVar11[7] = 0x10060780;
    iVar6 = ((int (*)())_PPCTextureSamplerWrapCoordinates3DRTCAV)(param_1,puVar11 + 8);
    iVar9 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample3DAVRTC,iVar6);
    puVar11 = (undefined4 *)(iVar6 + iVar9 * 4);
    *puVar11 = 0x1025492c;
    puVar11[1] = 0x1021392e;
    puVar11[2] = 0x10044a2c;
    puVar11[3] = 0x1021382e;
    puVar11[4] = 0x10200a8c;
    puVar11[5] = 0x104110ee;
    puVar11[6] = 0x100a4b2c;
    puVar11[7] = 0x10060780;
    iVar6 = ((int (*)())_PPCTextureSamplerWrapCoordinates3DRTCAV)(param_1,puVar11 + 8);
    iVar9 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample3DAVRTC,iVar6);
    puVar11 = (undefined4 *)(iVar6 + iVar9 * 4);
    *puVar11 = 0x1024492c;
    puVar11[1] = 0x1021396e;
    puVar11[2] = 0x10044a2c;
    puVar11[3] = 0x1021382e;
    puVar11[4] = 0x10200a8c;
    puVar11[5] = 0x104110ee;
    puVar11[6] = 0x1003528c;
    puVar11[7] = 0x10004a2c;
    puVar11[8] = 0x10060780;
    iVar6 = ((int (*)())_PPCTextureSamplerWrapCoordinates3DRTCAV)(param_1,puVar11 + 9);
    iVar9 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample3DAVRTC,iVar6);
    puVar11 = (undefined4 *)(iVar6 + iVar9 * 4);
    *puVar11 = 0x1025492c;
    puVar11[1] = 0x1021396e;
    puVar11[2] = 0x10044a2c;
    puVar11[3] = 0x1021382e;
    puVar11[4] = 0x10200a8c;
    puVar11[5] = 0x104110ee;
    puVar11[6] = 0x100a492c;
    puVar11[7] = 0x10060780;
    iVar6 = ((int (*)())_PPCTextureSamplerWrapCoordinates3DRTCAV)(param_1,puVar11 + 8);
    iVar9 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample3DAVRTC,iVar6);
    puVar11 = (undefined4 *)(iVar6 + iVar9 * 4);
    *puVar11 = 0x1024492c;
    puVar11[1] = 0x1021392e;
    puVar11[2] = 0x10054a2c;
    puVar11[3] = 0x1021382e;
    puVar11[4] = 0x10200a8c;
    puVar11[5] = 0x104110ee;
    puVar11[6] = 0x1003528c;
    puVar11[7] = 0x1009032c;
    puVar11[8] = 0x10060780;
    iVar6 = ((int (*)())_PPCTextureSamplerWrapCoordinates3DRTCAV)(param_1,puVar11 + 9);
    iVar9 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample3DAVRTC,iVar6);
    puVar11 = (undefined4 *)(iVar6 + iVar9 * 4);
    *puVar11 = 0x1025492c;
    puVar11[1] = 0x1021392e;
    puVar11[2] = 0x10054a2c;
    puVar11[3] = 0x1021382e;
    puVar11[4] = 0x10200a8c;
    puVar11[5] = 0x104110ee;
    puVar11[6] = 0x1003528c;
    puVar11[7] = 0x1000492c;
    puVar11[8] = 0x1000022c;
    puVar11[9] = 0x10060780;
    iVar6 = ((int (*)())_PPCTextureSamplerWrapCoordinates3DRTCAV)(param_1,puVar11 + 10);
    iVar9 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample3DAVRTC,iVar6);
    puVar11 = (undefined4 *)(iVar6 + iVar9 * 4);
    *puVar11 = 0x1024492c;
    puVar11[1] = 0x1021396e;
    puVar11[2] = 0x10054a2c;
    puVar11[3] = 0x1021382e;
    puVar11[4] = 0x10200a8c;
    puVar11[5] = 0x104110ee;
    puVar11[6] = 0x1003528c;
    puVar11[7] = 0x10060780;
    iVar6 = ((int (*)())_PPCTextureSamplerWrapCoordinates3DRTCAV)(param_1,puVar11 + 8);
    iVar9 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample3DAVRTC,iVar6);
    puVar11 = (undefined4 *)(iVar6 + iVar9 * 4);
    *puVar11 = 0x1025492c;
    puVar11[1] = 0x1021396e;
    puVar11[2] = 0x10054a2c;
    puVar11[3] = 0x1021382e;
    puVar11[4] = 0x10200a8c;
    puVar11 = puVar11 + 5;
    *puVar11 = 0x104110ee;
  }
  return puVar11 + 1;
}

/* _PPCTextureSamplerSampleTexelRECTFromLevelRTCAV @ 0x97be3af8 (1084 bytes) */
int _PPCTextureSamplerSampleTexelRECTFromLevelRTCAV(param_1, param_2, param_3)
  int *param_1;
  uint param_2;
  uint *param_3;
{
  bool bVar1;
  short sVar2;
  short sVar3;
  ushort uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  uint *puVar9;
  
  if (7 < param_2) {
    param_2 = 7;
  }
  piVar8 = *(int **)(param_2 * 4 + *param_1);
  if (piVar8 == (int *)0x0) {
    return param_3;
  }
  param_1[1] = (int)piVar8;
  iVar6 = *piVar8;
  sVar2 = *(short *)(iVar6 + 0x10);
  sVar3 = *(short *)(iVar6 + 0x12);
  if ((sVar2 == -0x7ed3) || (sVar3 == -0x7ed3)) {
    iVar7 = 0x812d;
  }
  else if ((((sVar2 != 0x2900) && (sVar3 != 0x2900)) || (*(short *)(iVar6 + 0x16) == 0x2600)) ||
          (iVar7 = 0x2900, *(short *)(iVar6 + 0x16) == 0x2700)) {
    iVar7 = 0;
  }
  if (((param_1[5] != param_2) || (param_1[6] != 2)) || (param_1[7] != iVar7)) {
    *param_3 = param_2 * 4 & 0xfffc | 0x82220000;
    puVar9 = param_3 + 1;
    if ((sVar2 == 0x2901) || (sVar3 == 0x2901)) {
      *puVar9 = 0x39e00160;
      param_3[2] = 0x7e3178ce;
      puVar9 = param_3 + 3;
    }
    if (iVar7 == 0x812d) {
      *puVar9 = 0x82510190;
      puVar9[1] = 0x39e00170;
      puVar9[2] = 0x7df178ce;
      puVar9[3] = 0x39e001a0;
      puVar9[4] = 0x7e1178ce;
      uVar5 = 0x823101c4;
    }
    else if (iVar7 == 0x2900) {
      *puVar9 = 0x82510190;
      puVar9[1] = 0x39e00170;
      puVar9[2] = 0x7df178ce;
      puVar9[3] = 0x39e001a0;
      puVar9[4] = 0x7e1178ce;
      uVar5 = 0x823101c8;
    }
    else {
      *puVar9 = 0x82510140;
      puVar9[1] = 0x39e00120;
      puVar9[2] = 0x7df178ce;
      puVar9[3] = 0x39e00150;
      puVar9[4] = 0x7e1178ce;
      uVar5 = 0x823101c0;
    }
    puVar9[5] = uVar5;
    param_1[7] = iVar7;
    param_3 = puVar9 + 6;
    param_1[5] = param_2;
    param_1[6] = 2;
    iVar6 = *piVar8;
  }
  uVar4 = *(ushort *)(iVar6 + 0x16);
  if (uVar4 == 0x2700) {
LAB_97be3d34:
    iVar6 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexFloatToIntDenormalisedAVRTC,param_3);
    puVar9 = param_3 + iVar6;
    iVar6 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexWrapCoordsCCCAVRTC,puVar9);
    iVar7 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample2DAVRTC,puVar9 + iVar6);
    puVar9 = puVar9 + iVar6 + iVar7;
    *puVar9 = 0x10431c84;
  }
  else {
    if (uVar4 < 0x2701) {
      if (uVar4 == 0x2600) goto LAB_97be3d34;
      bVar1 = uVar4 == 0x2601;
LAB_97be3d2c:
      if (!bVar1) {
        return param_3;
      }
    }
    else {
      if (uVar4 == 0x2702) goto LAB_97be3d34;
      if (0x2701 < uVar4) {
        bVar1 = uVar4 == 0x2703;
        goto LAB_97be3d2c;
      }
    }
    iVar6 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexFloatToIntDenormalisedWithLERPValuesAVRTC,param_3);
    puVar9 = param_3 + iVar6;
    *puVar9 = 0x10c00484;
    puVar9 = puVar9 + 1;
    iVar6 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexWrapCoordsCCCAVRTC,puVar9);
    iVar7 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample2DAVRTC,puVar9 + iVar6);
    puVar9 = puVar9 + iVar6 + iVar7;
    *puVar9 = 0x1024492c;
    puVar9[1] = 0x1021392e;
    puVar9[2] = 0x10200a8c;
    puVar9[3] = 0x104138ee;
    puVar9[4] = 0x100a4a2c;
    puVar9[5] = 0x10060780;
    puVar9 = puVar9 + 6;
    iVar6 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexWrapCoordsCCCAVRTC,puVar9);
    iVar7 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample2DAVRTC,puVar9 + iVar6);
    puVar9 = puVar9 + iVar6 + iVar7;
    *puVar9 = 0x1025492c;
    puVar9[1] = 0x1021392e;
    puVar9[2] = 0x10200a8c;
    puVar9[3] = 0x104110ee;
    puVar9[4] = 0x100a4b2c;
    puVar9[5] = 0x10060780;
    puVar9 = puVar9 + 6;
    iVar6 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexWrapCoordsCCCAVRTC,puVar9);
    iVar7 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample2DAVRTC,puVar9 + iVar6);
    puVar9 = puVar9 + iVar6 + iVar7;
    *puVar9 = 0x1024492c;
    puVar9[1] = 0x1021396e;
    puVar9[2] = 0x10200a8c;
    puVar9[3] = 0x104110ee;
    puVar9[4] = 0x1003528c;
    puVar9[5] = 0x10060780;
    puVar9 = puVar9 + 6;
    iVar6 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexWrapCoordsCCCAVRTC,puVar9);
    iVar7 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample2DAVRTC,puVar9 + iVar6);
    puVar9 = puVar9 + iVar6 + iVar7;
    *puVar9 = 0x1025492c;
    puVar9[1] = 0x1021396e;
    puVar9[2] = 0x10200a8c;
    puVar9 = puVar9 + 3;
    *puVar9 = 0x104110ee;
  }
  return puVar9 + 1;
}

/* _PPCNoiseGeneratorCreate @ 0x97be3f34 (56 bytes) */
int _PPCNoiseGeneratorCreate()
{
  undefined4 uVar1;
  
  uVar1 = _malloc(0xa20);
  ((int (*)())_PPCNoiseGeneratorInitialise)(uVar1);
  return uVar1;
}

/* _PPCNoiseGeneratorInitialise @ 0x97be3f6c (280 bytes) */
int _PPCNoiseGeneratorInitialise(param_1)
  undefined1 *param_1;
{
  undefined1 uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  float *pfVar5;
  uint uVar6;
  undefined1 *puVar7;
  
  _memset(param_1,0,0xa20);
  uVar6 = 0;
  pfVar5 = (float *)(param_1 + 0x210);
  do {
    param_1[uVar6] = (char)uVar6;
    uVar3 = _random();
    uVar6 = uVar6 + 1;
    *pfVar5 = (float)(((double)CONCAT44(0x43300000,
                                        (uVar3 + (((int)uVar3 >> 9) +
                                                 (uint)((int)uVar3 < 0 && (uVar3 & 0x1ff) != 0)) *
                                                 -0x200) - 0x100 ^ 0x80000000) - 4503601774854144.0)
                     * 0.00390625);
    pfVar5 = pfVar5 + 1;
  } while (uVar6 < 0x100);
  puVar7 = param_1 + 0xff;
  do {
    uVar1 = *puVar7;
    uVar6 = _random();
    iVar4 = uVar6 + (((int)uVar6 >> 8) + (uint)((int)uVar6 < 0 && (uVar6 & 0xff) != 0)) * -0x100;
    *puVar7 = param_1[iVar4];
    puVar7 = puVar7 + -1;
    param_1[iVar4] = uVar1;
  } while (puVar7 != param_1);
  iVar4 = 0x102;
  puVar7 = param_1;
  do {
    uVar2 = *(undefined4 *)(puVar7 + 0x210);
    param_1[0x100] = *param_1;
    param_1 = param_1 + 1;
    *(undefined4 *)(puVar7 + 0x610) = uVar2;
    puVar7 = puVar7 + 4;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return puVar7;
}

/* _glpRTCAddAChunk_97be4088 @ 0x97be4088 (48 bytes) */
int _glpRTCAddAChunk_97be4088(param_1, param_2)
  int *param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = *param_1;
  while (iVar1 != 0) {
    *param_2 = iVar1;
    iVar2 = iVar2 + 1;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
    iVar1 = *param_1;
  }
  return iVar2;
}

/* _PPCNoiseGeneratorCalculate1DAVRTC @ 0x97be40b8 (228 bytes) */
int _PPCNoiseGeneratorCalculate1DAVRTC(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  *param_2 = 0x11a8400a;
  param_2[1] = 0x102b5c84;
  puVar5 = param_2 + 2;
  uVar4 = 0;
  do {
    uVar4 = uVar4 + 1;
    iVar2 = ((int (*)())_glpRTCAddAChunk_97be4088)(&_glpOpFirstStageAVRTC,puVar5);
    iVar3 = ((int (*)())_glpRTCAddAChunk_97be4088)(&_glpOpSecondStage1DAVRTC,puVar5 + iVar2);
    puVar1 = puVar5 + iVar2 + iVar3;
    *puVar1 = 0x1122486e;
    puVar1[1] = 0x10003b6e;
    puVar1[2] = 0x10213aee;
    puVar5 = puVar1 + 3;
  } while (uVar4 < 6);
  *puVar5 = 0x10494c84;
  puVar1[4] = 0x1120038c;
  puVar1[5] = 0x39c00030;
  puVar1[6] = 0x7dae18ce;
  return puVar1 + 7;
}

/* _PPCNoiseGeneratorCalculate2DAVRTC @ 0x97be419c (228 bytes) */
int _PPCNoiseGeneratorCalculate2DAVRTC(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  *param_2 = 0x11a8400a;
  param_2[1] = 0x102b5c84;
  puVar5 = param_2 + 2;
  uVar4 = 0;
  do {
    uVar4 = uVar4 + 1;
    iVar2 = ((int (*)())_glpRTCAddAChunk_97be4088)(&_glpOpFirstStageAVRTC,puVar5);
    iVar3 = ((int (*)())_glpRTCAddAChunk_97be4088)(&_glpOpSecondStage2DAVRTC,puVar5 + iVar2);
    puVar1 = puVar5 + iVar2 + iVar3;
    *puVar1 = 0x1122486e;
    puVar1[1] = 0x10003b6e;
    puVar1[2] = 0x10213aee;
    puVar5 = puVar1 + 3;
  } while (uVar4 < 6);
  *puVar5 = 0x10494c84;
  puVar1[4] = 0x1120038c;
  puVar1[5] = 0x39c00030;
  puVar1[6] = 0x7dae18ce;
  return puVar1 + 7;
}

/* _PPCNoiseGeneratorCalculate3DAVRTC @ 0x97be4280 (228 bytes) */
int _PPCNoiseGeneratorCalculate3DAVRTC(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  *param_2 = 0x11a8400a;
  param_2[1] = 0x102b5c84;
  puVar5 = param_2 + 2;
  uVar4 = 0;
  do {
    uVar4 = uVar4 + 1;
    iVar2 = ((int (*)())_glpRTCAddAChunk_97be4088)(&_glpOpFirstStageAVRTC,puVar5);
    iVar3 = ((int (*)())_glpRTCAddAChunk_97be4088)(&_glpOpSecondStage3DAVRTC,puVar5 + iVar2);
    puVar1 = puVar5 + iVar2 + iVar3;
    *puVar1 = 0x1122486e;
    puVar1[1] = 0x10003b6e;
    puVar1[2] = 0x10213aee;
    puVar5 = puVar1 + 3;
  } while (uVar4 < 6);
  *puVar5 = 0x10494c84;
  puVar1[4] = 0x1120038c;
  puVar1[5] = 0x39c00030;
  puVar1[6] = 0x7dae18ce;
  return puVar1 + 7;
}

/* _PPCNoiseGeneratorCalculate4DAVRTC @ 0x97be4364 (8 bytes) */
int _PPCNoiseGeneratorCalculate4DAVRTC(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  return param_2;
}

/* _PPCRasterOpMachineCreate @ 0x97be436c (60 bytes) */
int _PPCRasterOpMachineCreate()
{
  undefined4 uVar1;
  
  uVar1 = _calloc(8,1);
  ((int (*)())_PPCRasterOpMachineInitialise)(uVar1);
  return uVar1;
}

/* _PPCRasterOpMachineInitialise @ 0x97be43a8 (16 bytes) */
int _PPCRasterOpMachineInitialise(param_1)
  undefined4 *param_1;
{
  param_1[1] = 0;
  *param_1 = 0;
  return;
}

/* _PPCRasterOpMachineAttachEmulatorContext @ 0x97be43bc (8 bytes) */
int _PPCRasterOpMachineAttachEmulatorContext(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  *param_1 = param_2;
  return;
}

/* _PPCRasterOpMachineAttachRuntimeCompiler @ 0x97be43c4 (8 bytes) */
int _PPCRasterOpMachineAttachRuntimeCompiler(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  *(undefined4 *)(param_1 + 4) = param_2;
  return;
}

/* _PPCRasterOpMachine_DepthTestRTCAV @ 0x97be43cc (272 bytes) */
int _PPCRasterOpMachine_DepthTestRTCAV(param_1, param_2)
  int *param_1;
  uint *param_2;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = param_1[1];
  uVar2 = *(uint *)(*(int *)(*param_1 + 0xd80) + 0x50);
  uVar1 = uVar2 & 7;
  if ((uVar1 != 0) && (uVar1 != 7)) {
    *param_2 = 0x81e30da8;
    param_2[1] = 0xc10f0000;
    param_2[2] = 0xfc0d4000;
    param_2 = param_2 + 3;
  }
  uVar1 = (uint)(*(int *)(iVar3 + 0xe3c) - (int)param_2) >> 2;
  switch(uVar2 & 7) {
  case 0:
    *param_2 = (uVar1 & 0xffffff) << 2 | 0x48000000;
    goto LAB_97be44f0;
  case 1:
    uVar2 = 0x41800000;
    break;
  case 2:
    uVar2 = 0x41820000;
    break;
  case 3:
    uVar2 = 0x40810000;
    break;
  case 4:
    uVar2 = 0x41810000;
    break;
  case 5:
    uVar2 = 0x40820000;
    break;
  case 6:
    uVar2 = 0x40800000;
    break;
  default:
    goto switchD_97be4464_caseD_7;
  }
  *param_2 = uVar2 | 8;
  param_2 = param_2 + 1;
  *param_2 = (uVar1 - 1) * 4 & 0x3fffffc | 0x48000000;
LAB_97be44f0:
  param_2 = param_2 + 1;
switchD_97be4464_caseD_7:
  return param_2;
}

/* _PPCRasterOpMachine_DepthAndStencilTestRTCAV @ 0x97be44fc (1172 bytes) */
int _PPCRasterOpMachine_DepthAndStencilTestRTCAV(param_1, param_2)
  int *param_1;
  uint *param_2;
{
  bool bVar1;
  uint uVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  uint *puVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  uint *puVar15;
  
  iVar11 = *param_1;
  puVar15 = (uint *)0x0;
  iVar13 = param_1[1];
  iVar4 = *(int *)(iVar11 + 0xd80);
  uVar5 = *(uint *)(iVar4 + 0x48);
  uVar10 = *(uint *)(iVar4 + 0x3c);
  uVar2 = *(uint *)(iVar4 + 0x4c) >> 0x18;
  bVar1 = (uVar10 >> 6 & 1) == 0;
  uVar8 = *(uint *)(*(int *)(iVar11 + 0xd80) + 0x50);
  uVar9 = *(uint *)(*(int *)(iVar11 + 0xd80) + 0x70);
  if (bVar1) {
    uVar14 = 0xff;
  }
  else {
    uVar14 = uVar9 >> 8 & 0xff;
  }
  bVar3 = (uVar10 & 2) != 0;
  uVar12 = *(uint *)(iVar4 + 0x4c) >> 8 & 0xff;
  if (!bVar3) goto LAB_97be4754;
  *param_2 = 0x83430dac;
  param_2[1] = 0x8b3a0000;
  puVar7 = param_2 + 2;
  puVar6 = puVar7;
  switch(uVar5 >> 0xc & 7) {
  case 0:
    uVar5 = uVar5 >> 0xf;
    param_2 = puVar7;
    goto LAB_97be47b8;
  case 1:
    *puVar7 = uVar2 & uVar12 | 0x3ba00000;
    param_2[3] = uVar12 | 0x733e0000;
    uVar12 = 0x41800000;
    break;
  case 2:
    *puVar7 = uVar2 & uVar12 | 0x3ba00000;
    param_2[3] = uVar12 | 0x733e0000;
    uVar12 = 0x41820000;
    break;
  case 3:
    *puVar7 = uVar2 & uVar12 | 0x3ba00000;
    param_2[3] = uVar12 | 0x733e0000;
    uVar12 = 0x40810000;
    break;
  case 4:
    *puVar7 = uVar2 & uVar12 | 0x3ba00000;
    param_2[3] = uVar12 | 0x733e0000;
    uVar12 = 0x41810000;
    break;
  case 5:
    *puVar7 = uVar2 & uVar12 | 0x3ba00000;
    param_2[3] = uVar12 | 0x733e0000;
    uVar12 = 0x40820000;
    break;
  case 6:
    *puVar7 = uVar2 & uVar12 | 0x3ba00000;
    param_2[3] = uVar12 | 0x733e0000;
    uVar12 = 0x40800000;
    break;
  case 7:
    *puVar7 = 0x48000000;
    puVar6 = param_2 + 3;
    puVar15 = puVar7;
  default:
    goto switchD_97be45d8_default;
  }
  param_2[4] = 0x7c1df000;
  puVar15 = param_2 + 5;
  *puVar15 = uVar12;
  puVar6 = param_2 + 6;
switchD_97be45d8_default:
  puVar6 = (uint *)((int (*)())_PPCRasterOpMachineUpdateStencilBufferRTCAV)(uVar5 >> 0xf & 7,0x1a,0x19,uVar2,uVar14,puVar6);
  param_2 = puVar6 + 1;
  *puVar6 = *(int *)(iVar13 + 0xe3c) - (int)puVar6 & 0x3fffffcU | 0x48000000;
  *puVar15 = *puVar15 | (int)param_2 - (int)puVar15 & 0xfffcU;
LAB_97be4754:
  if ((uVar10 & 4) == 0) {
    if (!bVar3) {
      return param_2;
    }
    puVar15 = (uint *)((int (*)())_PPCRasterOpMachineUpdateStencilBufferRTCAV)(uVar5 >> 0x15 & 7,0x1a,0x19,uVar2,uVar14,param_2);
    return puVar15;
  }
  switch(uVar8 & 7) {
  case 0:
    if (bVar3) {
      uVar5 = uVar5 >> 0x12;
LAB_97be47b8:
      param_2 = (uint *)((int (*)())_PPCRasterOpMachineUpdateStencilBufferRTCAV)(uVar5 & 7,0x1a,0x19,uVar2,uVar14,param_2);
    }
    *param_2 = *(int *)(iVar13 + 0xe3c) - (int)param_2 & 0x3fffffcU | 0x48000000;
    return param_2 + 1;
  case 1:
    *param_2 = 0x81e30da8;
    param_2[1] = 0xc10f0000;
    uVar8 = 0x41800000;
    break;
  case 2:
    *param_2 = 0x81e30da8;
    param_2[1] = 0xc10f0000;
    uVar8 = 0x41820000;
    break;
  case 3:
    *param_2 = 0x81e30da8;
    param_2[1] = 0xc10f0000;
    uVar8 = 0x40810000;
    break;
  case 4:
    *param_2 = 0x81e30da8;
    param_2[1] = 0xc10f0000;
    uVar8 = 0x41810000;
    break;
  case 5:
    *param_2 = 0x81e30da8;
    param_2[1] = 0xc10f0000;
    uVar8 = 0x40820000;
    break;
  case 6:
    *param_2 = 0x81e30da8;
    param_2[1] = 0xc10f0000;
    uVar8 = 0x40800000;
    break;
  case 7:
    *param_2 = 0x81e30da8;
    uVar8 = 0x48000000;
    goto LAB_97be48e0;
  default:
    goto switchD_97be4784_default;
  }
  param_2 = param_2 + 2;
  *param_2 = 0xfc0d4000;
LAB_97be48e0:
  puVar15 = param_2 + 1;
  *puVar15 = uVar8;
  param_2 = param_2 + 2;
switchD_97be4784_default:
  if (bVar3) {
    param_2 = (uint *)((int (*)())_PPCRasterOpMachineUpdateStencilBufferRTCAV)(uVar5 >> 0x12 & 7,0x1a,0x19,uVar2,uVar14,param_2);
  }
  *param_2 = *(int *)(iVar13 + 0xe3c) - (int)param_2 & 0x3fffffcU | 0x48000000;
  puVar6 = param_2 + 1;
  *puVar15 = *puVar15 | (int)puVar6 - (int)puVar15 & 0xfffcU;
  if (bVar3) {
    puVar6 = (uint *)((int (*)())_PPCRasterOpMachineUpdateStencilBufferRTCAV)(uVar5 >> 0x15 & 7,0x1a,0x19,uVar2,uVar14,puVar6);
  }
  if ((bVar1) || ((uVar9 & 0x10000) != 0)) {
    *puVar6 = 0xd1af0000;
    puVar6 = puVar6 + 1;
  }
  return puVar6;
}

/* _PPCRasterOpMachine_AlphaTestRTCAV @ 0x97be49d0 (616 bytes) */
int _PPCRasterOpMachine_AlphaTestRTCAV(param_1, param_2)
  int *param_1;
  uint *param_2;
{
  float fVar1;
  uint uVar2;
  float fVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  double dVar7;
  
  uVar6 = 0;
  iVar4 = *(int *)(*param_1 + 0xd80);
  uVar5 = *(uint *)(iVar4 + 0x40);
  fVar3 = *(float *)(iVar4 + 0x44);
  uVar2 = uVar5 & 7;
  if ((uVar2 != 7) && (uVar2 != 0)) {
    uVar6 = _PPEmulatorFramebufferFormat(*param_1);
    if ((uVar6 & 0x1c000) == 0) {
      *param_2 = 0x3b000210;
      param_2[1] = 0x7e63c1ce;
      param_2[2] = 0xc123021c;
      param_2[3] = (uint)fVar3 >> 0x10 | 0x3de00000;
      param_2[4] = (uint)fVar3 & 0xffff | 0x61ef0000;
      param_2[5] = 0x91e30210;
      param_2[6] = 0xc1030210;
      uVar6 = 0xfc094000;
    }
    else {
      fVar1 = TAllocation__guardBlockSize;
      if ((fVar3 < TAllocation__guardBlockSize) || (fVar1 = FLOAT_97c3acd8, FLOAT_97c3acd8 < fVar3))
      {
        fVar3 = fVar1;
      }
      fVar3 = fVar3 * FLOAT_97c3acbc + FLOAT_97c3acc0;
      dVar7 = (double)fVar3;
      if (DOUBLE_97c30a78 <= dVar7) {
        uVar6 = (uint)(dVar7 - DOUBLE_97c30a78);
      }
      else {
        uVar6 = (uint)fVar3;
      }
      *param_2 = 0x10734c0a;
      param_2[1] = 0x1063444a;
      param_2[2] = 0x10635b2e;
      param_2[3] = 0x10601b8a;
      param_2[4] = 0x3b000210;
      param_2[5] = 0x7c63c1ce;
      uVar6 = uVar6 & 0xffff | 0x2c170000;
      param_2[6] = 0x82e3021c;
    }
    param_2[7] = uVar6;
    param_2 = param_2 + 8;
    uVar6 = (uint)(*(int *)(param_1[1] + 0xe3c) - (int)param_2) >> 2;
  }
  switch(uVar5 & 7) {
  case 0:
    uVar6 = *(int *)(param_1[1] + 0xe3c) - (int)param_2 & 0x3fffffcU | 0x48000000;
    break;
  case 1:
    uVar6 = (uVar6 & 0x3fff) << 2 | 0x40800000;
    break;
  case 2:
    uVar6 = (uVar6 & 0x3fff) << 2 | 0x40820000;
    break;
  case 3:
    uVar6 = (uVar6 & 0x3fff) << 2 | 0x41810000;
    break;
  case 4:
    uVar6 = (uVar6 & 0x3fff) << 2 | 0x40810000;
    break;
  case 5:
    uVar6 = (uVar6 & 0x3fff) << 2 | 0x41820000;
    break;
  case 6:
    uVar6 = (uVar6 & 0x3fff) << 2 | 0x41800000;
    break;
  default:
    goto switchD_97be4bb8_caseD_7;
  }
  *param_2 = uVar6;
  param_2 = param_2 + 1;
switchD_97be4bb8_caseD_7:
  return param_2;
}

/* _PPCRasterOpMachine_BlendingRTCAV @ 0x97be4c58 (888 bytes) */
int _PPCRasterOpMachine_BlendingRTCAV(param_1, param_2)
  int *param_1;
  uint *param_2;
{
  bool bVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  
  iVar6 = 0x13;
  uVar5 = *(uint *)(*(int *)(*param_1 + 0xd80) + 0x58);
  uVar2 = _PPEmulatorFramebufferFormat(*param_1);
  if ((uVar2 & 0x8000000) == 0) {
    *param_2 = 0x1273444a;
    param_2[1] = 0x12734c0a;
    param_2 = param_2 + 2;
  }
  if ((1 < (uVar5 >> 0x10 & 7) - 3) || (1 < (uVar5 >> 0x13 & 7) - 3)) {
    if (((((uVar5 & 0xf) - 8 < 4) ||
         (((uVar2 = uVar5 >> 4 & 0xf, uVar2 == 8 || (uVar2 == 9)) || (uVar2 == 10)))) ||
        ((((uVar2 == 0xb || (uVar2 = uVar5 >> 8 & 0xf, uVar2 == 8)) || (uVar2 == 9)) ||
         ((uVar2 == 10 || (uVar2 == 0xb)))))) ||
       ((uVar2 = uVar5 >> 0xc & 0xf, uVar2 == 8 ||
        (((uVar2 == 9 || (uVar2 == 10)) || (uVar2 == 0xb)))))) {
      *param_2 = 0x81e30d9c;
      param_2[1] = 0x81ef00d8;
      param_2[2] = 0x39c02d70;
      param_2[3] = 0x7ccf70ce;
      param_2 = param_2 + 4;
    }
    puVar3 = (undefined4 *)((int (*)())_PPCRasterOpMachineCalculateBlendingFactorsRTCAV)(param_2,0,uVar5 & 0xf);
    uVar2 = uVar5 >> 4 & 0xf;
    if ((uVar5 & 0xf) != uVar2) {
      puVar4 = (undefined4 *)((int (*)())_PPCRasterOpMachineCalculateBlendingFactorsRTCAV)(puVar3,3,uVar2);
      puVar3 = puVar4 + 1;
      *puVar4 = 0x10001b6a;
    }
    param_2 = (uint *)((int (*)())_PPCRasterOpMachineCalculateBlendingFactorsRTCAV)(puVar3,1,uVar5 >> 8 & 0xf);
    uVar2 = uVar5 >> 0xc & 0xf;
    if ((uVar5 >> 8 & 0xf) != uVar2) {
      puVar3 = (undefined4 *)((int (*)())_PPCRasterOpMachineCalculateBlendingFactorsRTCAV)(param_2,3,uVar2);
      param_2 = puVar3 + 1;
      *puVar3 = 0x10211b6a;
    }
  }
  uVar2 = uVar5 >> 0x10 & 7;
  bVar1 = uVar2 == (uVar5 >> 0x13 & 7);
  if (!bVar1) {
    iVar6 = 3;
  }
  switch(uVar2) {
  case 0:
    *param_2 = 0x1093482e;
    param_2 = param_2 + 1;
    *param_2 = iVar6 << 0x15 | 0x1002206e;
    goto LAB_97be4f04;
  case 1:
    *param_2 = 0x1093482e;
    uVar2 = iVar6 << 0x15 | 0x1004284a;
    break;
  case 2:
    *param_2 = 0x1093482e;
    uVar2 = iVar6 << 0x15 | 0x1005204a;
    break;
  case 3:
    uVar2 = iVar6 << 0x15 | 0x1013144a;
    goto LAB_97be4f00;
  case 4:
    uVar2 = iVar6 << 0x15 | 0x1013140a;
LAB_97be4f00:
    *param_2 = uVar2;
    goto LAB_97be4f04;
  default:
    goto switchD_97be4e5c_default;
  }
  param_2[1] = 0x10a2486e;
  param_2 = param_2 + 2;
  *param_2 = uVar2;
LAB_97be4f04:
  param_2 = param_2 + 1;
switchD_97be4e5c_default:
  if (bVar1) {
    return param_2;
  }
  switch(uVar5 >> 0x13 & 7) {
  case 0:
    uVar2 = 0x1262206e;
    *param_2 = 0x1093482e;
    goto LAB_97be4f88;
  case 1:
    *param_2 = 0x1093482e;
    uVar2 = 0x1264284a;
    break;
  case 2:
    *param_2 = 0x1093482e;
    uVar2 = 0x1265204a;
    break;
  case 3:
    uVar2 = 0x1273144a;
    goto LAB_97be4fc4;
  case 4:
    uVar2 = 0x1273140a;
LAB_97be4fc4:
    *param_2 = uVar2;
    goto LAB_97be4fc8;
  default:
    goto switchD_97be4f38_default;
  }
  param_2 = param_2 + 1;
  *param_2 = 0x10a2486e;
LAB_97be4f88:
  param_2 = param_2 + 1;
  *param_2 = uVar2;
LAB_97be4fc8:
  param_2 = param_2 + 1;
switchD_97be4f38_default:
  *param_2 = iVar6 << 0x10 | 0x12609b6a;
  return param_2 + 1;
}

/* _PPCRasterOpMachine_LogicOpRTCAV @ 0x97be4ff8 (520 bytes) */
int _PPCRasterOpMachine_LogicOpRTCAV(param_1, param_2)
  int *param_1;
  uint *param_2;
{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(*(int *)(*param_1 + 0xd80) + 0x68);
  uVar1 = uVar2 & 0xf;
  if ((uVar1 < 3) || (uVar1 == 4)) {
    if (uVar1 == 1) {
      uVar1 = 0x12684484;
    }
    else if (uVar1 < 2) {
      if (uVar1 != 0) {
        return param_2;
      }
      uVar1 = 0x12694c84;
    }
    else {
      if (uVar1 == 2) {
        return param_2;
      }
      if (uVar1 != 4) {
        return param_2;
      }
      uVar1 = 0x12621484;
    }
    *param_2 = uVar1;
    goto LAB_97be507c;
  }
  if (uVar1 != 5) {
    *param_2 = 0x10734b2e;
    param_2[1] = 0x10601b8a;
    param_2 = param_2 + 2;
  }
  uVar2 = uVar2 & 0xf;
  if (uVar2 != 3) {
    *param_2 = 0x10824b2e;
    param_2[1] = 0x1080238a;
    param_2 = param_2 + 2;
  }
  switch(uVar2) {
  case 3:
    uVar1 = 0x10c30000;
    goto LAB_97be5148;
  default:
    goto switchD_97be5104_caseD_4;
  case 5:
    uVar1 = 0x10c40000;
LAB_97be5148:
    uVar1 = uVar1 | 0x4d04;
    break;
  case 6:
    uVar1 = 0x10c32404;
    break;
  case 7:
    uVar1 = 0x10c32404;
    goto LAB_97be51a0;
  case 8:
    uVar1 = 0x10c32484;
    break;
  case 9:
    uVar1 = 0x10c32504;
    break;
  case 10:
    uVar1 = 0x10c324c4;
    break;
  case 0xb:
    uVar1 = 0x10c324c4;
LAB_97be51a0:
    uVar2 = 0x10c64d04;
LAB_97be51d8:
    *param_2 = uVar1;
    param_2 = param_2 + 1;
    *param_2 = uVar2;
    goto LAB_97be51e0;
  case 0xc:
    uVar1 = 0x10c32444;
    break;
  case 0xd:
    uVar1 = 0x10c41c44;
    break;
  case 0xe:
    uVar1 = 0x10840000;
    goto LAB_97be51cc;
  case 0xf:
    uVar1 = 0x10630000;
LAB_97be51cc:
    uVar1 = uVar1 | 0x4d04;
    uVar2 = 0x10c32484;
    goto LAB_97be51d8;
  }
  *param_2 = uVar1;
LAB_97be51e0:
  param_2 = param_2 + 1;
switchD_97be5104_caseD_4:
  *param_2 = 0x39e00020;
  param_2[1] = 0x7c6378ce;
  param_2[2] = 0x10c61c04;
  param_2[3] = 0x10c0330a;
  param_2[4] = 0x39e00070;
  param_2[5] = 0x7c6378ce;
  param_2 = param_2 + 6;
  *param_2 = 0x126648ee;
LAB_97be507c:
  return param_2 + 1;
}

/* _PPCRasterOpMachine_BufferMaskRTCAV @ 0x97be5234 (208 bytes) */
int _PPCRasterOpMachine_BufferMaskRTCAV(param_1, param_2)
  int *param_1;
  undefined4 *param_2;
{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = 0x1063492c;
  uVar1 = *(uint *)(*(int *)(*param_1 + 0xd80) + 0x70);
  *param_2 = 0x10836a8c;
  if ((uVar1 & 0x20000) == 0) {
    uVar2 = 0x1063212c;
  }
  param_2[1] = uVar2;
  uVar2 = 0x1063492c;
  if ((uVar1 & 0x40000) == 0) {
    uVar2 = 0x1063212c;
  }
  param_2[2] = uVar2;
  uVar2 = 0x1063492c;
  if ((uVar1 & 0x80000) == 0) {
    uVar2 = 0x1063212c;
  }
  param_2[3] = uVar2;
  uVar2 = 0x1063492c;
  if ((uVar1 & 0x100000) == 0) {
    uVar2 = 0x1063212c;
  }
  param_2[4] = uVar2;
  param_2[5] = 0x127310ea;
  return param_2 + 6;
}

/* _PPCRasterOpMachineCalculateBlendingFactorsRTCAV @ 0x97be5304 (400 bytes) */
int _PPCRasterOpMachineCalculateBlendingFactorsRTCAV(param_1, param_2, param_3)
  uint *param_1;
  int param_2;
  undefined4 param_3;
{
  uint uVar1;
  uint uVar2;
  
  switch(param_3) {
  case 0:
    uVar1 = param_2 << 0x15 | 0x10094c84;
    break;
  case 1:
    uVar1 = param_2 << 0x15 | 0x10084484;
    break;
  case 2:
    uVar1 = param_2 << 0x15 | 0x10139c84;
    break;
  case 3:
    uVar1 = param_2 << 0x15 | 0x1008984a;
    break;
  case 4:
    uVar1 = param_2 << 0x15 | 0x10039a8c;
    break;
  case 5:
    uVar1 = param_2 << 0x15 | param_2 << 0xb | 0x10080000;
    uVar2 = param_2 << 0x15 | 0x10039a8c;
    goto LAB_97be545c;
  case 6:
    uVar1 = param_2 << 0x15 | 0x1003128c;
    break;
  case 7:
    uVar1 = param_2 << 0x15 | param_2 << 0xb | 0x10080000;
    uVar2 = param_2 << 0x15 | 0x1003128c;
    goto LAB_97be545c;
  case 8:
    uVar1 = param_2 << 0x15 | 0x10063484;
    break;
  case 9:
    uVar1 = param_2 << 0x15 | 0x1008304a;
    break;
  case 10:
    uVar1 = param_2 << 0x15 | 0x1003328c;
    break;
  case 0xb:
    uVar1 = param_2 << 0x15 | param_2 << 0xb | 0x10080000;
    uVar2 = param_2 << 0x15 | 0x1003328c;
LAB_97be545c:
    *param_1 = uVar2;
    param_1 = param_1 + 1;
    *param_1 = uVar1 | 0x4a;
    goto LAB_97be5394;
  case 0xc:
    uVar1 = param_2 << 0x15 | 0x10021484;
    break;
  case 0xd:
    uVar1 = param_2 << 0x15 | 0x1008104a;
    break;
  case 0xe:
    uVar1 = param_2 << 0x15;
    uVar2 = uVar1 | param_2 << 0x10;
    *param_1 = uVar1 | 0x1008104a;
    param_1[1] = uVar2 | 0x10009c4a;
    param_1[2] = uVar1 | param_2 << 0xb | 0x1003028c;
    param_1 = param_1 + 3;
    *param_1 = uVar2 | 0x1000436a;
    goto LAB_97be5394;
  default:
    return param_1;
  }
  *param_1 = uVar1;
LAB_97be5394:
  return param_1 + 1;
}

/* _PPCRasterOpMachineUpdateStencilBufferRTCAV @ 0x97be54d0 (468 bytes) */
int _PPCRasterOpMachineUpdateStencilBufferRTCAV(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  int param_2;
  uint param_3;
  uint param_4;
  uint param_5;
  uint *param_6;
{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  
  switch(param_1) {
  case 0:
    *param_6 = param_5 ^ 0xffff | param_3 << 0x15 | 0x701e0000;
    puVar3 = param_6 + 1;
    *puVar3 = param_2 << 0x10 | 0x9bc00000;
    goto LAB_97be5588;
  case 1:
    return param_6;
  case 2:
    *param_6 = param_5 ^ 0xffff | param_3 << 0x15 | 0x701e0000;
    param_6[1] = param_4 & param_5 | 0x3be00000;
    puVar3 = param_6 + 2;
    *puVar3 = 0x7fdefb78;
    goto LAB_97be5580;
  case 3:
    *param_6 = (param_3 & 0x1f) << 0x10 | 0x2c0000ff;
    param_6[1] = param_3 << 0x10 | 0x3be00000;
    param_6[2] = 0x40800008;
    uVar1 = param_5 ^ 0xffff | param_3 << 0x15;
    uVar2 = param_3 << 0x10 | 0x3be00001;
    break;
  case 4:
    *param_6 = (param_3 & 0x1f) << 0x10 | 0x2c000000;
    param_6[1] = param_3 << 0x10 | 0x3be00000;
    param_6[2] = 0x40810008;
    uVar1 = param_5 ^ 0xffff | param_3 << 0x15;
    uVar2 = param_3 << 0x10 | 0x3be0ffff;
    break;
  case 5:
    *param_6 = param_5 ^ 0xffff | param_3 << 0x15 | 0x701e0000;
    param_6[1] = param_3 << 0x15 | param_3 << 0xb | 0x7c1f00f8;
    param_6[2] = param_5 | 0x73ff0000;
    param_6[3] = 0x7fdefb78;
    param_6[4] = param_2 << 0x10 | 0x9bc00000;
    return param_6 + 5;
  case 6:
    uVar1 = param_5 ^ 0xffff | param_3 << 0x15;
    uVar2 = param_3 << 0x10 | 0x3be00001;
    goto LAB_97be55e8;
  case 7:
    uVar1 = param_5 ^ 0xffff | param_3 << 0x15;
    uVar2 = param_3 << 0x10 | 0x3be0ffff;
LAB_97be55e8:
    *param_6 = uVar2;
    puVar3 = param_6 + 1;
    *puVar3 = 0x73ff00ff;
    goto LAB_97be55f4;
  default:
    return param_6;
  }
  puVar3 = param_6 + 3;
  *puVar3 = uVar2;
LAB_97be55f4:
  puVar3[1] = uVar1 | 0x701e0000;
  puVar3[2] = param_5 | 0x73ff0000;
  puVar3 = puVar3 + 3;
  *puVar3 = 0x7fdefb78;
LAB_97be5580:
  puVar3 = puVar3 + 1;
  *puVar3 = param_2 << 0x10 | 0x9bc00000;
LAB_97be5588:
  return puVar3 + 1;
}

