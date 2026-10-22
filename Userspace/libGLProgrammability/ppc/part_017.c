#include "decls.h"

/* _PPStreamRemoveOperation @ 0x97bf2714 (192 bytes) */
int _PPStreamRemoveOperation(stream, param_2)
  int stream;
  int param_2;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = *(int *)(param_2 + 8);
  if (iVar5 != 0) {
    uVar2 = *(uint *)(iVar5 + 0xc);
    uVar1 = (*(uint *)(param_2 + 0xc) >> 0x1a & 7) << 0x1a;
    *(uint *)(iVar5 + 0xc) = uVar1 | uVar2 & 0xe3ffffff;
    uVar3 = *(uint *)(param_2 + 0xc) & 0x3ffff;
    if (uVar3 == 0) {
      uVar4 = 0;
      uVar3 = *(uint *)(*(int *)(param_2 + 8) + 0xc);
      *(uint *)(iVar5 + 0xc) = uVar1 | uVar2 & 0xe3fc0000;
      uVar3 = uVar3 & 0x3ffff;
    }
    else {
      uVar4 = uVar2 & 0x3ffff;
    }
    _renumberLabels(**(undefined4 **)(stream + 0x24),uVar3,uVar4,0);
    _renumberTargets(**(undefined4 **)(stream + 0x20),uVar3,uVar4,0);
  }
  _PPStreamChunkListRemoveChunk(*(undefined4 *)(stream + 0x20),param_2);
  return iVar5;
}

/* _adjustAllocation_97bf27d4 @ 0x97bf27d4 (124 bytes) */
int _adjustAllocation_97bf27d4(param_1, param_2, param_3)
  int *param_1;
  int *param_2;
  int *param_3;
{
  int allocation;
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *param_2;
  iVar3 = *param_3;
  if (*param_1 - (iVar3 - iVar1) < 0x800) {
    iVar2 = *param_1 + 0x1000;
    *param_1 = iVar2;
    allocation = _realloc(*param_2,iVar2);
    *param_3 = allocation;
    if (allocation == 0) {
      return 0;
    }
    *param_2 = allocation;
    *param_3 = allocation + (iVar3 - iVar1);
  }
  return 1;
}

/* _ncpy_97bf2850 @ 0x97bf2850 (144 bytes) */
int _ncpy_97bf2850(param_1, param_2)
  char *param_1;
  int param_2;
{
  int iVar1;
  char *local_20 [4];
  
  local_20[0] = param_1;
  if (param_2 < 0) {
    local_20[0] = param_1 + 1;
    *param_1 = '-';
    param_2 = -param_2;
  }
  iVar1 = param_2 / 10;
  if (iVar1 != 0) {
    ((int (*)())_handleDigit_97c05b70)(local_20,iVar1);
  }
  *local_20[0] = (char)param_2 + (char)iVar1 * -10 + '0';
  return local_20[0] + (1 - (int)param_1);
}

/* _glpSourceSign @ 0x97bf28e0 (180 bytes) */
int _glpSourceSign(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  uint param_4;
{
  char ch;
  int copyIndex;
  
  if ((param_4 & 1) == 0) {
    if ((*(uint *)(param_1 + param_3 * 8) & 0x8000000) == 0) {
      return param_2;
    }
    copyIndex = 0;
    ch = s___97c2a2d4[0];
    while (ch != '\0') {
      *(char *)(param_2 + copyIndex) = ch;
      ch = "-"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
  }
  else {
    if ((*(uint *)(param_1 + param_3 * 8) & 0x8000000) != 0) {
      return param_2;
    }
    copyIndex = 0;
    ch = s___97c2a2d4[0];
    while (ch != '\0') {
      *(char *)(param_2 + copyIndex) = ch;
      ch = "-"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
  }
  return param_2 + copyIndex;
}

/* _glpSourceType @ 0x97bf2994 (1080 bytes) */
int _glpSourceType(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  uint param_6;
  uint param_7;
{
  int copyIndex2;
  int copyEnd2;
  int copyEnd;
  int copyEnd3;
  char ch;
  uint uVar2;
  int iVar3;
  int iVar4;
  int copyIndex;
  int iVar6;
  
  if ((param_7 & 0x10) != 0) {
    if (param_6 == 1) {
      param_6 = *(uint *)(param_1 + 8) >> 6 & 3;
    }
    else if ((int)param_6 < 2) {
      if (param_6 == 0) {
        param_6 = *(uint *)(param_1 + 8) >> 8 & 3;
      }
    }
    else if (param_6 == 2) {
      param_6 = *(uint *)(param_1 + 8) >> 4 & 3;
    }
    else if (param_6 == 3) {
      param_6 = *(uint *)(param_1 + 8) >> 2 & 3;
    }
  }
  iVar6 = param_5 * 8;
  uVar2 = *(uint *)(iVar6 + param_1) >> 0x17 & 7;
  if (uVar2 == 1) {
    copyIndex = 0;
    ch = s_tmp_97c2d76c[0];
    while (ch != '\0') {
      *(char *)(param_2 + copyIndex) = ch;
      ch = "tmp"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
LAB_97bf2d98:
    copyEnd2 = ((int (*)())_ncpy_97bf2850)(param_2 + copyIndex,*(ushort *)(iVar6 + param_1 + 6) + param_6);
    return param_2 + copyIndex + copyEnd2;
  }
  if (uVar2 < 2) {
    if (uVar2 != 0) {
      return param_2;
    }
    copyIndex = 0;
    ch = s_att_97c2d7e4[0];
    while (ch != '\0') {
      *(char *)(param_2 + copyIndex) = ch;
      ch = "att"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    goto LAB_97bf2d98;
  }
  if (uVar2 != 2) {
    if (uVar2 != 3) {
      return param_2;
    }
    copyIndex = 0;
    ch = s_res_97c2d774[0];
    while (ch != '\0') {
      *(char *)(param_2 + copyIndex) = ch;
      ch = "res"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    goto LAB_97bf2d98;
  }
  copyIndex = 0;
  ch = s_prm_97c2d7e8[0];
  while (ch != '\0') {
    *(char *)(param_2 + copyIndex) = ch;
    ch = "prm"[copyIndex + 1];
    copyIndex = copyIndex + 1;
  }
  copyEnd3 = ((int (*)())_ncpy_97bf2850)(param_2 + copyIndex,
                         *(int *)(param_3 + (uint)*(ushort *)(iVar6 + param_1 + 6) * 4) + param_6);
  iVar3 = param_2 + copyIndex + copyEnd3;
  if (-1 < *(int *)(iVar6 + param_1)) {
    if (*(int *)(param_4 + (uint)*(ushort *)(iVar6 + param_1 + 6) * 4) == -1) {
      return iVar3;
    }
    copyIndex = 0;
    ch = s___97c29860[0];
    while (ch != '\0') {
      *(char *)(iVar3 + copyIndex) = ch;
      ch = "["[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    copyEnd = ((int (*)())_ncpy_97bf2850)(iVar3 + copyIndex,
                           *(undefined4 *)(param_4 + (uint)*(ushort *)(iVar6 + param_1 + 6) * 4));
    iVar4 = iVar3 + copyIndex + copyEnd;
    copyIndex2 = 0;
    ch = s___97c2d770[0];
    while (ch != '\0') {
      *(char *)(iVar4 + copyIndex2) = ch;
      ch = "]"[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    goto LAB_97bf2d5c;
  }
  copyIndex = 0;
  ch = s__adr_97c2d778[0];
  while (ch != '\0') {
    *(char *)(iVar3 + copyIndex) = ch;
    ch = "[adr"[copyIndex + 1];
    copyIndex = copyIndex + 1;
  }
  copyEnd = ((int (*)())_ncpy_97bf2850)(iVar3 + copyIndex,*(uint *)(iVar6 + param_1) >> 0x1e & 1);
  iVar4 = iVar3 + copyIndex + copyEnd;
  uVar2 = *(uint *)(iVar6 + param_1) >> 0x1c & 3;
  if (uVar2 == 1) {
    copyIndex2 = 0;
    ch = s__y_97c2d784[0];
    while (ch != '\0') {
      *(char *)(iVar4 + copyIndex2) = ch;
      ch = ".y"[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
LAB_97bf2c84:
    iVar4 = iVar4 + copyIndex2;
  }
  else {
    if (1 < uVar2) {
      if (uVar2 == 2) {
        copyIndex2 = 0;
        ch = s__z_97c2d788[0];
        while (ch != '\0') {
          *(char *)(iVar4 + copyIndex2) = ch;
          ch = ".z"[copyIndex2 + 1];
          copyIndex2 = copyIndex2 + 1;
        }
      }
      else {
        if (uVar2 != 3) goto LAB_97bf2c88;
        copyIndex2 = 0;
        ch = s__w_97c2d78c[0];
        while (ch != '\0') {
          *(char *)(iVar4 + copyIndex2) = ch;
          ch = ".w"[copyIndex2 + 1];
          copyIndex2 = copyIndex2 + 1;
        }
      }
      goto LAB_97bf2c84;
    }
    if (uVar2 == 0) {
      copyIndex2 = 0;
      ch = s__x_97c2d780[0];
      while (ch != '\0') {
        *(char *)(iVar4 + copyIndex2) = ch;
        ch = ".x"[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      goto LAB_97bf2c84;
    }
  }
LAB_97bf2c88:
  copyIndex2 = 0;
  ch = s___97c2d770[0];
  while (ch != '\0') {
    *(char *)(iVar4 + copyIndex2) = ch;
    ch = "]"[copyIndex2 + 1];
    copyIndex2 = copyIndex2 + 1;
  }
LAB_97bf2d5c:
  return iVar4 + copyIndex2;
}

/* _glpSourceComponents @ 0x97bf2dcc (504 bytes) */
int _glpSourceComponents(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  char *param_2;
  int param_3;
  uint param_4;
  uint param_5;
{
  int copyIndex;
  char ch;
  uint uVar2;
  int copyIndex2;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  
  uVar7 = 0x3210;
  if ((param_5 & 0x40) == 0) {
    uVar7 = *(uint *)(param_1 + param_3 * 8);
    uVar7 = uVar7 >> 3 & 0x3000 | uVar7 >> 9 & 0x300 | uVar7 >> 0xf & 0x30 | uVar7 >> 0x15 & 3;
  }
  uVar8 = uVar7;
  if ((param_5 & 0xc) != 0) {
    uVar4 = param_4;
    if ((param_5 & 4) == 0) {
      uVar4 = *(uint *)(param_1 + 8);
      uVar4 = (uVar4 & 0xc) << 10 | (uVar4 & 0x30) << 4 | uVar4 >> 2 & 0x30 | uVar4 >> 8 & 3;
    }
    if (uVar4 != 0x3210) {
      iVar10 = 4;
      uVar9 = 0;
      uVar8 = 0;
      do {
        uVar2 = uVar9 & 0x3f;
        uVar5 = (uVar4 & 3) * 4 - uVar9;
        if ((int)uVar5 < 1) {
          uVar5 = uVar7 << (-uVar5 & 0x3f);
        }
        else {
          uVar5 = (int)uVar7 >> (uVar5 & 0x3f);
        }
        uVar9 = uVar9 + 4;
        uVar8 = uVar8 | uVar5 & 3 << uVar2;
        uVar4 = (int)uVar4 >> 4;
        iVar10 = iVar10 + -1;
      } while (iVar10 != 0);
    }
  }
  if ((param_5 & 2) == 0) {
    iVar10 = 4;
    if ((*(uint *)(param_1 + param_3 * 8) & 0x3000) == 0) {
      iVar10 = 1;
    }
    if (uVar8 != 0x3210) {
      copyIndex2 = 0;
      ch = s___97c2a130[0];
      while (ch != '\0') {
        param_2[copyIndex2] = ch;
        ch = "."[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      param_2 = param_2 + copyIndex2;
      for (; iVar10 != 0; iVar10 = iVar10 + -1) {
        ch = (char)uVar8;
        uVar8 = (int)uVar8 >> 4;
        *param_2 = (ch + 1U & 3) + 0x77;
        param_2 = param_2 + 1;
      }
    }
  }
  else {
    copyIndex = 0;
    ch = s___97c2a130[0];
    while (ch != '\0') {
      param_2[copyIndex] = ch;
      ch = "."[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    pcVar6 = param_2 + copyIndex;
    if (param_4 == 1) {
      uVar8 = (int)uVar8 >> 4;
    }
    else if ((int)param_4 < 2) {
      if (param_4 != 0) {
        return pcVar6;
      }
    }
    else if (param_4 == 2) {
      uVar8 = (int)uVar8 >> 8;
    }
    else {
      if (param_4 != 3) {
        return pcVar6;
      }
      uVar8 = (int)uVar8 >> 0xc;
    }
    param_2[copyIndex] = ((char)uVar8 + 1U & 3) + 0x77;
    param_2 = pcVar6 + 1;
  }
  return param_2;
}

/* _glpWriteComponentsWithDestinationSwizzle @ 0x97bf2fc4 (244 bytes) */
int _glpWriteComponentsWithDestinationSwizzle(param_1, param_2)
  int param_1;
  char *param_2;
{
  int copyIndex;
  int loopIndex;
  char ch;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  
  uVar7 = *(uint *)(param_1 + 8);
  uVar7 = (uVar7 & 0xc) << 10 | (uVar7 & 0x30) << 4 | uVar7 >> 2 & 0x30 | uVar7 >> 8 & 3;
  if (uVar7 == 0x3210) {
    return param_2;
  }
  iVar8 = 4;
  uVar6 = 0;
  uVar5 = 0;
  do {
    uVar2 = uVar5 & 0x3f;
    uVar3 = (uVar7 & 3) * 4 - uVar5;
    if ((int)uVar3 < 1) {
      uVar3 = 0x3210 << (-uVar3 & 0x3f);
    }
    else {
      uVar3 = 0x3210 >> (uVar3 & 0x3f);
    }
    uVar5 = uVar5 + 4;
    uVar6 = uVar6 | uVar3 & 3 << uVar2;
    uVar7 = (int)uVar7 >> 4;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  if (uVar6 != 0x3210) {
    copyIndex = 0;
    ch = s___97c2a130[0];
    while (ch != '\0') {
      param_2[copyIndex] = ch;
      ch = "."[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    pcVar4 = param_2 + copyIndex;
    loopIndex = 0;
    do {
      loopIndex = loopIndex + 1;
      ch = (char)uVar6;
      uVar6 = (int)uVar6 >> 4;
      *pcVar4 = (ch + 1U & 3) + 0x77;
      pcVar4 = pcVar4 + 1;
    } while (loopIndex < 4);
    return pcVar4;
  }
  return param_2;
}

/* _glpWriteSourceOperand_97bf30b8 @ 0x97bf30b8 (128 bytes) */
int _glpWriteSourceOperand_97bf30b8(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  undefined4 uVar1;
  
  uVar1 = ((int (*)())_glpSourceSign)(param_1,param_2,param_5,param_8);
  uVar1 = ((int (*)())_glpSourceType)(param_1,uVar1,param_3,param_4,param_5,param_6,param_8);
  uVar1 = ((int (*)())_glpSourceComponents)(param_1,uVar1,param_5,param_7,param_8);
  return uVar1;
}

/* _glpWriteDestinationMask @ 0x97bf3138 (1312 bytes) */
int _glpWriteDestinationMask(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  uint param_4;
{
  int copyIndex2;
  int copyIndex;
  uint uVar1;
  char ch;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if ((param_4 & 2) == 0) {
    uVar1 = *(uint *)(param_1 + 8);
    if ((uVar1 & 0x1e000) == 0x1e000) {
      return param_2;
    }
    iVar5 = 0;
    iVar4 = iVar5;
    ch = s___97c2a130[0];
    if (s___97c2a130[0] != '\0') {
      do {
        *(char *)(param_2 + iVar4) = ch;
        iVar5 = iVar4 + 1;
        ch = "."[iVar4 + 1];
        iVar4 = iVar5;
      } while (ch != '\0');
      uVar1 = *(uint *)(param_1 + 8);
    }
    iVar5 = param_2 + iVar5;
    if ((uVar1 & 0x2000) != 0) {
      iVar3 = 0;
      iVar4 = iVar3;
      ch = s_x_97c2d790[0];
      if (s_x_97c2d790[0] != '\0') {
        do {
          *(char *)(iVar5 + iVar4) = ch;
          iVar3 = iVar4 + 1;
          ch = "x"[iVar4 + 1];
          iVar4 = iVar3;
        } while (ch != '\0');
        uVar1 = *(uint *)(param_1 + 8);
      }
      iVar5 = iVar5 + iVar3;
    }
    if ((uVar1 & 0x4000) != 0) {
      iVar3 = 0;
      iVar4 = iVar3;
      ch = s_y_97c2d794[0];
      if (s_y_97c2d794[0] != '\0') {
        do {
          *(char *)(iVar5 + iVar4) = ch;
          iVar3 = iVar4 + 1;
          ch = "y"[iVar4 + 1];
          iVar4 = iVar3;
        } while (ch != '\0');
        uVar1 = *(uint *)(param_1 + 8);
      }
      iVar5 = iVar5 + iVar3;
    }
    if ((uVar1 & 0x8000) != 0) {
      iVar3 = 0;
      iVar4 = iVar3;
      ch = s_z_97c2d798[0];
      if (s_z_97c2d798[0] != '\0') {
        do {
          *(char *)(iVar5 + iVar4) = ch;
          iVar3 = iVar4 + 1;
          ch = "z"[iVar4 + 1];
          iVar4 = iVar3;
        } while (ch != '\0');
        uVar1 = *(uint *)(param_1 + 8);
      }
      iVar5 = iVar5 + iVar3;
    }
    if ((uVar1 & 0x10000) == 0) {
      return iVar5;
    }
    copyIndex = 0;
    ch = s_w_97c2d79c[0];
    while (ch != '\0') {
      *(char *)(iVar5 + copyIndex) = ch;
      ch = "w"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
  }
  else if (param_3 == 1) {
    copyIndex2 = 0;
    ch = s___97c2a130[0];
    while (ch != '\0') {
      *(char *)(param_2 + copyIndex2) = ch;
      ch = "."[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    uVar1 = *(uint *)(param_1 + 8);
    iVar5 = param_2 + copyIndex2;
    if ((uVar1 & 0x4000) == 0) {
      if ((uVar1 & 0x8000) == 0) {
        if ((uVar1 & 0x10000) == 0) {
          return iVar5;
        }
        copyIndex = 0;
        ch = s_w_97c2d79c[0];
        while (ch != '\0') {
          *(char *)(iVar5 + copyIndex) = ch;
          ch = "w"[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
      }
      else {
        copyIndex = 0;
        ch = s_z_97c2d798[0];
        while (ch != '\0') {
          *(char *)(iVar5 + copyIndex) = ch;
          ch = "z"[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
      }
    }
    else {
      copyIndex = 0;
      ch = s_y_97c2d794[0];
      while (ch != '\0') {
        *(char *)(iVar5 + copyIndex) = ch;
        ch = "y"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
    }
  }
  else if (param_3 < 2) {
    if (param_3 != 0) {
      return param_2;
    }
    copyIndex2 = 0;
    ch = s___97c2a130[0];
    while (ch != '\0') {
      *(char *)(param_2 + copyIndex2) = ch;
      ch = "."[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    uVar1 = *(uint *)(param_1 + 8);
    iVar5 = param_2 + copyIndex2;
    if ((uVar1 & 0x2000) == 0) {
      if ((uVar1 & 0x4000) == 0) {
        if ((uVar1 & 0x8000) == 0) {
          if ((uVar1 & 0x10000) == 0) {
            return iVar5;
          }
          copyIndex = 0;
          ch = s_w_97c2d79c[0];
          while (ch != '\0') {
            *(char *)(iVar5 + copyIndex) = ch;
            ch = "w"[copyIndex + 1];
            copyIndex = copyIndex + 1;
          }
        }
        else {
          copyIndex = 0;
          ch = s_z_97c2d798[0];
          while (ch != '\0') {
            *(char *)(iVar5 + copyIndex) = ch;
            ch = "z"[copyIndex + 1];
            copyIndex = copyIndex + 1;
          }
        }
      }
      else {
        copyIndex = 0;
        ch = s_y_97c2d794[0];
        while (ch != '\0') {
          *(char *)(iVar5 + copyIndex) = ch;
          ch = "y"[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
      }
    }
    else {
      copyIndex = 0;
      ch = s_x_97c2d790[0];
      while (ch != '\0') {
        *(char *)(iVar5 + copyIndex) = ch;
        ch = "x"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
    }
  }
  else if (param_3 == 2) {
    copyIndex2 = 0;
    ch = s___97c2a130[0];
    while (ch != '\0') {
      *(char *)(param_2 + copyIndex2) = ch;
      ch = "."[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    iVar5 = param_2 + copyIndex2;
    if ((*(uint *)(param_1 + 8) & 0x8000) == 0) {
      if ((*(uint *)(param_1 + 8) & 0x10000) == 0) {
        return iVar5;
      }
      copyIndex = 0;
      ch = s_w_97c2d79c[0];
      while (ch != '\0') {
        *(char *)(iVar5 + copyIndex) = ch;
        ch = "w"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
    }
    else {
      copyIndex = 0;
      ch = s_z_97c2d798[0];
      while (ch != '\0') {
        *(char *)(iVar5 + copyIndex) = ch;
        ch = "z"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
    }
  }
  else {
    if (param_3 != 3) {
      return param_2;
    }
    copyIndex2 = 0;
    ch = s___97c2a130[0];
    while (ch != '\0') {
      *(char *)(param_2 + copyIndex2) = ch;
      ch = "."[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    iVar5 = param_2 + copyIndex2;
    if ((*(uint *)(param_1 + 8) & 0x10000) == 0) {
      return iVar5;
    }
    copyIndex = 0;
    ch = s_w_97c2d79c[0];
    while (ch != '\0') {
      *(char *)(iVar5 + copyIndex) = ch;
      ch = "w"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
  }
  return iVar5 + copyIndex;
}

/* _glpWriteDestinationOperand_97bf3658 @ 0x97bf3658 (348 bytes) */
int _glpWriteDestinationOperand_97bf3658(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  uint param_5;
{
  int copyEnd;
  char ch;
  uint uVar2;
  int copyIndex;
  undefined4 uVar4;
  
  uVar2 = *(uint *)(param_1 + 8) >> 0x11 & 7;
  if (uVar2 == 3) {
    copyIndex = 0;
    ch = s_res_97c2d774[0];
    while (ch != '\0') {
      *(char *)(param_2 + copyIndex) = ch;
      ch = "res"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
  }
  else if (uVar2 < 4) {
    if (uVar2 != 1) goto LAB_97bf3754;
    copyIndex = 0;
    ch = s_tmp_97c2d76c[0];
    while (ch != '\0') {
      *(char *)(param_2 + copyIndex) = ch;
      ch = "tmp"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
  }
  else {
    if (uVar2 != 4) goto LAB_97bf3754;
    copyIndex = 0;
    ch = s_adr_97c2d7e0[0];
    while (ch != '\0') {
      *(char *)(param_2 + copyIndex) = ch;
      ch = "adr"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
  }
  param_2 = param_2 + copyIndex;
LAB_97bf3754:
  copyEnd = ((int (*)())_ncpy_97bf2850)(param_2,(uint)*(ushort *)(param_1 + 0xe) + param_3);
  if ((param_5 & 0x40) == 0) {
    uVar4 = ((int (*)())_glpWriteDestinationMask)(param_1,param_2 + copyEnd,param_4,param_5);
  }
  else {
    uVar4 = ((int (*)())_glpSourceComponents)(param_1,param_2 + copyEnd,1,param_4,param_5);
  }
  return uVar4;
}

/* _glpWriteTextureOperand_97bf37b4 @ 0x97bf37b4 (760 bytes) */
int _glpWriteTextureOperand_97bf37b4(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  int copyIndex2;
  int copyIndex;
  char ch;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  copyIndex = 0;
  ch = s_texture__97c2d814[0];
  while (ch != '\0') {
    *(char *)(param_2 + copyIndex) = ch;
    ch = "texture["[copyIndex + 1];
    copyIndex = copyIndex + 1;
  }
  iVar4 = param_2 + copyIndex;
  if (param_4 == 0) {
    iVar2 = 0;
    ch = s_0_97c2d800[0];
    while (ch != '\0') {
      *(char *)(iVar4 + iVar2) = ch;
      ch = "0"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    iVar3 = param_3 << 3;
  }
  else {
    iVar3 = param_3 * 8;
    iVar2 = ((int (*)())_ncpy_97bf2850)(iVar4,*(undefined4 *)
                                  (param_4 + (uint)*(ushort *)(iVar3 + param_1 + 6) * 0x10));
  }
  copyIndex2 = 0;
  ch = s____97c2d820[0];
  while (ch != '\0') {
    *(char *)(iVar4 + iVar2 + copyIndex2) = ch;
    ch = "], "[copyIndex2 + 1];
    copyIndex2 = copyIndex2 + 1;
  }
  iVar5 = iVar4 + iVar2 + copyIndex2;
  switch(*(uint *)(iVar3 + param_1) >> 5 & 7) {
  case 0:
    iVar4 = 0;
    ch = s_CUBE_97c2d830[0];
    while (ch != '\0') {
      *(char *)(iVar5 + iVar4) = ch;
      ch = "CUBE"[iVar4 + 1];
      iVar4 = iVar4 + 1;
    }
    break;
  case 1:
    iVar4 = 0;
    ch = s_3D_97c2d82c[0];
    while (ch != '\0') {
      *(char *)(iVar5 + iVar4) = ch;
      ch = "3D"[iVar4 + 1];
      iVar4 = iVar4 + 1;
    }
    break;
  case 2:
    iVar4 = 0;
    ch = s_RECT_97c2d838[0];
    while (ch != '\0') {
      *(char *)(iVar5 + iVar4) = ch;
      ch = "RECT"[iVar4 + 1];
      iVar4 = iVar4 + 1;
    }
    break;
  case 3:
    iVar4 = 0;
    ch = s_2D_97c2d828[0];
    while (ch != '\0') {
      *(char *)(iVar5 + iVar4) = ch;
      ch = "2D"[iVar4 + 1];
      iVar4 = iVar4 + 1;
    }
    break;
  case 4:
    iVar4 = 0;
    ch = s_1D_97c2d824[0];
    while (ch != '\0') {
      *(char *)(iVar5 + iVar4) = ch;
      ch = "1D"[iVar4 + 1];
      iVar4 = iVar4 + 1;
    }
    break;
  case 5:
    iVar4 = 0;
    ch = s_SHADOWRECT_97c2d840[0];
    while (ch != '\0') {
      *(char *)(iVar5 + iVar4) = ch;
      ch = "SHADOWRECT"[iVar4 + 1];
      iVar4 = iVar4 + 1;
    }
    break;
  case 6:
    iVar4 = 0;
    ch = s_SHADOW2D_97c2d84c[0];
    while (ch != '\0') {
      *(char *)(iVar5 + iVar4) = ch;
      ch = "SHADOW2D"[iVar4 + 1];
      iVar4 = iVar4 + 1;
    }
    break;
  case 7:
    iVar4 = 0;
    ch = s_SHADOW1D_97c2d858[0];
    while (ch != '\0') {
      *(char *)(iVar5 + iVar4) = ch;
      ch = "SHADOW1D"[iVar4 + 1];
      iVar4 = iVar4 + 1;
    }
    break;
  default:
    goto switchD_97bf38d0_default;
  }
  iVar5 = iVar5 + iVar4;
switchD_97bf38d0_default:
  return iVar5;
}

/* _glpDisassemble2Op @ 0x97bf3acc (56112 bytes) */
int _glpDisassemble2Op(inst, outText, outWordCount, outTextLength, param_5, param_6, param_7, param_8, stateFlags, shaderType, param_11)
  uint *inst;
  int outText;
  int *outWordCount;
  int *outTextLength;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  uint *stateFlags;
  int shaderType;
  undefined4 param_11;
{
  char *outPtr;
  int outPos;
  int opOffsetOrTailLength;
  int copyIndex9;
  int copyIndex10;
  int copyIndex11;
  int copyEnd;
  int outCursor6;
  int copyEnd2;
  int outCursor7;
  int loopIndex2;
  int loopIndex3;
  int loopIndex4;
  int loopIndex;
  int copyIndex6;
  int outCursor;
  int copyIndex3;
  int outCursor2;
  int copyIndex2;
  int outCursor4;
  int copyIndex4;
  int outCursor5;
  int copyIndex5;
  int outCursor3;
  int copyIndex;
  bool bVar1;
  undefined *opStringTable;
  char ch;
  char *mnemonic;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  
  opStringTable = PTR__ppstreamOpString_a7b7c108;
  uVar8 = *inst;
  uVar9 = uVar8 >> 0x12 & 0xff;
  if ((int)inst[3] < 0) {
    return 0xffffffff;
  }
  if (((((uVar8 >> 0x1d != 0) && ((int)inst[4] < 0)) &&
       (((inst[4] >> 0x17 & 7) != 2 || (shaderType == 0x8b30)))) ||
      (((1 < uVar8 >> 0x1d && ((int)inst[6] < 0)) &&
       (((inst[6] >> 0x17 & 7) != 2 || (shaderType == 0x8b30)))))) ||
     ((((2 < uVar8 >> 0x1d && ((int)inst[8] < 0)) &&
       (((inst[8] >> 0x17 & 7) != 2 || (shaderType == 0x8b30)))) || (0x70 < uVar9)))) {
LAB_97c017a4:
    return 0xffffffff;
  }
  opOffsetOrTailLength = uVar9 * 4;
  iVar6 = outText;
  switch(uVar9) {
  case 0:
    iVar11 = 1;
    if ((inst[2] & 0x1000) != 0) {
      iVar11 = (inst[2] >> 10 & 3) + 1;
    }
    loopIndex3 = 0;
    if (iVar11 == 0) goto LAB_97c0178c;
    do {
      copyIndex4 = 0;
      ch = s_MOV_97c2e430[0];
      while (ch != '\0') {
        *(char *)(iVar6 + copyIndex4) = ch;
        ch = "MOV "[copyIndex4 + 1];
        copyIndex4 = copyIndex4 + 1;
      }
      outCursor4 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,iVar6 + copyIndex4,loopIndex3,0,0);
      copyIndex3 = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor4 + copyIndex3) = ch;
        ch = ", "[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor4 + copyIndex3,param_5,param_6,2,loopIndex3,0,8);
      copyIndex4 = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex4) = ch;
        ch = ";\n"[copyIndex4 + 1];
        copyIndex4 = copyIndex4 + 1;
      }
      loopIndex3 = loopIndex3 + 1;
      iVar6 = outCursor + copyIndex4;
    } while (loopIndex3 < iVar11);
    goto LAB_97c01788;
  default:
    goto LAB_97c017a4;
  case 2:
  case 4:
  case 5:
    copyIndex9 = 0;
    mnemonic = *(char **)(PTR__ppstreamOpString_a7b7c108 + opOffsetOrTailLength);
    ch = *mnemonic;
    while (ch != '\0') {
      *(char *)(outText + copyIndex9) = ch;
      copyIndex9 = copyIndex9 + 1;
      ch = mnemonic[copyIndex9];
    }
    copyIndex = 0;
    ch = s__97c291c0[0];
    while (ch != '\0') {
      *(char *)(outText + copyIndex9 + copyIndex) = ch;
      ch = " "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outText + copyIndex9 + copyIndex,0,0,0);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    iVar6 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,2,0,0,8);
    opOffsetOrTailLength = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(iVar6 + opOffsetOrTailLength) = ch;
      ch = ";\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 3:
    *stateFlags = *stateFlags | 1;
    copyIndex = 0;
    ch = s_FLR_scratch__97c2e420[0];
    while (ch != '\0') {
      *(char *)(outText + copyIndex) = ch;
      ch = "FLR scratch, "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,param_5,param_6,2,0,0,9);
    copyIndex = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ";\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    copyIndex2 = 0;
    ch = s_MOV_97c2e430[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex + copyIndex2) = ch;
      ch = "MOV "[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    iVar6 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor + copyIndex + copyIndex2,0,0,0);
    opOffsetOrTailLength = 0;
    ch = s____scratch__97c2e438[0];
    while (ch != '\0') {
      *(char *)(iVar6 + opOffsetOrTailLength) = ch;
      ch = ", -scratch;\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 6:
    if ((stateFlags[1] & 0x400000) == 0) {
      return 0xffffffff;
    }
    if (shaderType != 0x8b30) {
      return 0xffffffff;
    }
    *stateFlags = *stateFlags | 0x400003;
    copyIndex = 0;
    ch = s_DDX_scratch__97c2f7fc[0];
    while (ch != '\0') {
      *(char *)(outText + copyIndex) = ch;
      ch = "DDX scratch, "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,param_5,param_6,2,0,0,8);
    copyIndex = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ";\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    copyIndex2 = 0;
    ch = s_ABS_scratch__scratch__97c2e8c0[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex + copyIndex2) = ch;
      ch = "ABS scratch, scratch;\n"[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outCursor2 = outCursor + copyIndex + copyIndex2;
    copyIndex = 0;
    ch = s_DDY_scratch1__97c2f80c[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "DDY scratch1, "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex,param_5,param_6,2,0,0,8);
    copyIndex = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ";\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    copyIndex2 = 0;
    ch = s_ABS_scratch1__scratch1__97c2e880[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex + copyIndex2) = ch;
      ch = "ABS scratch1, scratch1;\n"[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outCursor2 = outCursor + copyIndex + copyIndex2;
    copyIndex = 0;
    ch = s_ADD_97c2e6d4[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "ADD "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    iVar6 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor2 + copyIndex,0,0,0);
    opOffsetOrTailLength = 0;
    ch = s___scratch__scratch1__97c2e4f8[0];
    while (ch != '\0') {
      *(char *)(iVar6 + opOffsetOrTailLength) = ch;
      ch = ", scratch, scratch1;\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 7:
    if (((stateFlags[1] & 0x100000) == 0) || (shaderType != 0x8b31)) {
      *stateFlags = *stateFlags | 0x1003;
      copyIndex = 0;
      ch = s_SLT_scratch__97c2e474[0];
      while (ch != '\0') {
        *(char *)(outText + copyIndex) = ch;
        ch = "SLT scratch, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,param_5,param_6,2,0,0,8);
      copyIndex = 0;
      ch = s___kZERO__97c2e484[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", kZERO;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      copyIndex2 = 0;
      ch = s_SLT_scratch1__97c2e490[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex + copyIndex2) = ch;
        ch = "SLT scratch1, "[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex + copyIndex2,param_5,param_6,2,0,0,9);
      copyIndex = 0;
      ch = s___kZERO__97c2e484[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", kZERO;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      copyIndex2 = 0;
      ch = s_SUB_97c2e934[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex + copyIndex2) = ch;
        ch = "SUB "[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      iVar6 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor + copyIndex + copyIndex2,0,0,0);
      opOffsetOrTailLength = 0;
      ch = s___scratch1__scratch__97c2e93c[0];
      while (ch != '\0') {
        *(char *)(iVar6 + opOffsetOrTailLength) = ch;
        ch = ", scratch1, scratch;\n"[opOffsetOrTailLength + 1];
        opOffsetOrTailLength = opOffsetOrTailLength + 1;
      }
    }
    else {
      *stateFlags = *stateFlags | 0x100000;
      copyIndex = 0;
      ch = s_SSG_97c2e92c[0];
      while (ch != '\0') {
        *(char *)(outText + copyIndex) = ch;
        ch = "SSG "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outText + copyIndex,0,0,0);
      copyIndex = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      iVar6 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,2,0,0,8);
      opOffsetOrTailLength = 0;
      ch = s_____end_97c2e910[0];
      while (ch != '\0') {
        *(char *)(iVar6 + opOffsetOrTailLength) = ch;
        ch = ";\n# end\n"[opOffsetOrTailLength + 1];
        opOffsetOrTailLength = opOffsetOrTailLength + 1;
      }
    }
    break;
  case 8:
    uVar9 = *stateFlags;
    *stateFlags = uVar9 | 0x2000;
    uVar8 = inst[4] >> 0xc & 3;
    if (uVar8 == 2) {
      *stateFlags = uVar9 | 0x3001;
      copyIndex = 0;
      ch = s_DP3_scratch_x__97c2e734[0];
      while (ch != '\0') {
        *(char *)(outText + copyIndex) = ch;
        ch = "DP3 scratch.x, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,param_5,param_6,2,0,0,0);
      copyIndex = 0;
      ch = s___kONE__97c2e9b0[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", kONE;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
LAB_97bfb2c8:
      iVar11 = outCursor + copyIndex;
    }
    else {
      iVar11 = outText;
      if (uVar8 < 3) {
        if (uVar8 == 1) {
          *stateFlags = uVar9 | 0x2001;
          copyIndex = 0;
          ch = s_ADD_scratch_x__97c2e960[0];
          while (ch != '\0') {
            *(char *)(outText + copyIndex) = ch;
            ch = "ADD scratch.x, "[copyIndex + 1];
            copyIndex = copyIndex + 1;
          }
          outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,param_5,param_6,2,0,0,2);
          copyIndex = 0;
          ch = s___97c2d7ec[0];
          while (ch != '\0') {
            *(char *)(outCursor + copyIndex) = ch;
            ch = ", "[copyIndex + 1];
            copyIndex = copyIndex + 1;
          }
          outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,2,0,0,2);
          copyIndex = 0;
          ch = s___97c2d8f8[0];
          while (ch != '\0') {
            *(char *)(outCursor + copyIndex) = ch;
            ch = ";\n"[copyIndex + 1];
            copyIndex = copyIndex + 1;
          }
          goto LAB_97bfb2c8;
        }
      }
      else if (uVar8 == 3) {
        *stateFlags = uVar9 | 0x3001;
        copyIndex = 0;
        ch = s_DP4_scratch_x__97c2e744[0];
        while (ch != '\0') {
          *(char *)(outText + copyIndex) = ch;
          ch = "DP4 scratch.x, "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,param_5,param_6,2,0,0,0);
        copyIndex = 0;
        ch = s___kONE__97c2e9b0[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex) = ch;
          ch = ", kONE;\n"[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        goto LAB_97bfb2c8;
      }
    }
    copyIndex3 = 0;
    ch = s_SGE_97c2e91c[0];
    while (ch != '\0') {
      *(char *)(iVar11 + copyIndex3) = ch;
      ch = "SGE "[copyIndex3 + 1];
      copyIndex3 = copyIndex3 + 1;
    }
    iVar6 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,iVar11 + copyIndex3,0,0,0);
    opOffsetOrTailLength = 0;
    ch = s___scratch_x__kHALF__97c2e970[0];
    while (ch != '\0') {
      *(char *)(iVar6 + opOffsetOrTailLength) = ch;
      ch = ", scratch.x, kHALF;\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 9:
    uVar9 = inst[4] >> 0xc & 3;
    if (uVar9 == 2) {
      *stateFlags = *stateFlags | 1;
      copyIndex = 0;
      ch = s_MUL_scratch_x__97c2e6fc[0];
      while (ch != '\0') {
        *(char *)(outText + copyIndex) = ch;
        ch = "MUL scratch.x, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,param_5,param_6,2,0,0,2);
      copyIndex = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,2,0,1,2);
      copyIndex = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ";\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      copyIndex2 = 0;
      ch = s_MUL_97c2e4f0[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex + copyIndex2) = ch;
        ch = "MUL "[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor + copyIndex + copyIndex2,0,0,0);
      copyIndex = 0;
      ch = s___scratch_x__97c2e9a0[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", scratch.x, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      iVar6 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,2,0,2,2);
      opOffsetOrTailLength = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        *(char *)(iVar6 + opOffsetOrTailLength) = ch;
        ch = ";\n"[opOffsetOrTailLength + 1];
        opOffsetOrTailLength = opOffsetOrTailLength + 1;
      }
    }
    else if (uVar9 < 3) {
      if (uVar9 != 1) goto LAB_97c0178c;
      copyIndex = 0;
      ch = s_MUL_97c2e4f0[0];
      while (ch != '\0') {
        *(char *)(outText + copyIndex) = ch;
        ch = "MUL "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outText + copyIndex,0,0,0);
      copyIndex = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,2,0,0,2);
      copyIndex = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      iVar6 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,2,0,1,2);
      opOffsetOrTailLength = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        *(char *)(iVar6 + opOffsetOrTailLength) = ch;
        ch = ";\n"[opOffsetOrTailLength + 1];
        opOffsetOrTailLength = opOffsetOrTailLength + 1;
      }
    }
    else {
      if (uVar9 != 3) goto LAB_97c0178c;
      *stateFlags = *stateFlags | 1;
      copyIndex = 0;
      ch = s_MUL_scratch_xy__97c2e510[0];
      while (ch != '\0') {
        *(char *)(outText + copyIndex) = ch;
        ch = "MUL scratch.xy, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor6 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,param_5,param_6,2,0,0x3210,4)
      ;
      copyIndex = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor6 + copyIndex) = ch;
        ch = ", "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor6 + copyIndex,param_5,param_6,2,0,0x3232,4);
      copyIndex = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ";\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      copyIndex2 = 0;
      ch = s_MUL_97c2e4f0[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex + copyIndex2) = ch;
        ch = "MUL "[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      iVar6 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor + copyIndex + copyIndex2,0,0,0);
      opOffsetOrTailLength = 0;
      ch = s___scratch_x__scratch_y__97c2e524[0];
      while (ch != '\0') {
        *(char *)(iVar6 + opOffsetOrTailLength) = ch;
        ch = ", scratch.x, scratch.y;\n"[opOffsetOrTailLength + 1];
        opOffsetOrTailLength = opOffsetOrTailLength + 1;
      }
    }
    break;
  case 10:
    *stateFlags = *stateFlags | 0x1000;
    copyIndex = 0;
    ch = s_SUB_97c2e934[0];
    while (ch != '\0') {
      *(char *)(outText + copyIndex) = ch;
      ch = "SUB "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outText + copyIndex,0,0,0);
    copyIndex = 0;
    ch = s___kONE__97c2e954[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", kONE, "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    iVar6 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,2,0,0,8);
    opOffsetOrTailLength = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(iVar6 + opOffsetOrTailLength) = ch;
      ch = ";\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 0xc:
    uVar8 = inst[2];
    *stateFlags = *stateFlags | 1;
    uVar9 = inst[2];
    uVar8 = uVar8 >> 0xd & 0xf;
    loopIndex = 0;
    do {
      if ((uVar8 & 1) != 0) {
        copyIndex2 = 0;
        ch = s_RSQ_scratch_x__97c2e57c[0];
        while (ch != '\0') {
          *(char *)(iVar6 + copyIndex2) = ch;
          ch = "RSQ scratch.x, "[copyIndex2 + 1];
          copyIndex2 = copyIndex2 + 1;
        }
        outCursor7 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,iVar6 + copyIndex2,param_5,param_6,2,0,loopIndex,10)
        ;
        copyIndex3 = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          *(char *)(outCursor7 + copyIndex3) = ch;
          ch = ";\n"[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        copyIndex4 = 0;
        ch = s_RCP_97c2e58c[0];
        while (ch != '\0') {
          *(char *)(outCursor7 + copyIndex3 + copyIndex4) = ch;
          ch = "RCP "[copyIndex4 + 1];
          copyIndex4 = copyIndex4 + 1;
        }
        outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor7 + copyIndex3 + copyIndex4,0,loopIndex,2);
        copyIndex2 = 0;
        ch = s___scratch_x__97c2e594[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex2) = ch;
          ch = ", scratch.x;\n"[copyIndex2 + 1];
          copyIndex2 = copyIndex2 + 1;
        }
        uVar9 = inst[2];
        iVar6 = outCursor + copyIndex2;
      }
      loopIndex = loopIndex + 1;
      uVar8 = (int)uVar8 >> 1;
    } while (loopIndex <= (int)(uVar9 >> 10 & 3));
    goto LAB_97c01788;
  case 0xd:
  case 0x10:
  case 0x13:
    uVar8 = inst[2];
    uVar9 = uVar8 >> 0xd & 0xf;
    loopIndex3 = 0;
    do {
      if ((uVar9 & 1) != 0) {
        mnemonic = *(char **)(opStringTable + opOffsetOrTailLength);
        copyIndex10 = 0;
        ch = *mnemonic;
        while (ch != '\0') {
          *(char *)(iVar6 + copyIndex10) = ch;
          copyIndex10 = copyIndex10 + 1;
          ch = mnemonic[copyIndex10];
        }
        copyIndex5 = 0;
        ch = s__97c291c0[0];
        while (ch != '\0') {
          *(char *)(iVar6 + copyIndex10 + copyIndex5) = ch;
          ch = " "[copyIndex5 + 1];
          copyIndex5 = copyIndex5 + 1;
        }
        outCursor4 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,iVar6 + copyIndex10 + copyIndex5,0,loopIndex3,2);
        copyIndex3 = 0;
        ch = s___97c2d7ec[0];
        while (ch != '\0') {
          *(char *)(outCursor4 + copyIndex3) = ch;
          ch = ", "[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        outCursor6 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor4 + copyIndex3,param_5,param_6,2,0,loopIndex3,10)
        ;
        copyIndex4 = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          *(char *)(outCursor6 + copyIndex4) = ch;
          ch = ";\n"[copyIndex4 + 1];
          copyIndex4 = copyIndex4 + 1;
        }
        uVar8 = inst[2];
        iVar6 = outCursor6 + copyIndex4;
      }
      loopIndex3 = loopIndex3 + 1;
      uVar9 = (int)uVar9 >> 1;
    } while (loopIndex3 <= (int)(uVar8 >> 10 & 3));
    goto LAB_97c01788;
  case 0x12:
    *stateFlags = *stateFlags | 1;
    uVar8 = inst[4] >> 0xc & 3;
    if (uVar8 == 1) {
      copyIndex = 0;
      ch = s_SWZ_scratch__97c2e79c[0];
      while (ch != '\0') {
        *(char *)(outText + copyIndex) = ch;
        ch = "SWZ scratch, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      iVar6 = ((int (*)())_glpSourceType)(inst,outText + copyIndex,param_5,param_6,2,0,0);
      copyIndex = 0;
      ch = s___x__y__0__0__97c2e7ac[0];
      while (ch != '\0') {
        *(char *)(iVar6 + copyIndex) = ch;
        ch = ", x, y, 0, 0;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = iVar6 + copyIndex;
      copyIndex = 0;
      ch = s_DP3_scratch_x__scratch__scratch__97c2e7bc[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = "DP3 scratch.x, scratch, scratch;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
    }
    else {
      if (uVar8 == 0) {
        copyIndex = 0;
        ch = s_MUL_scratch_x__97c2e6fc[0];
        while (ch != '\0') {
          *(char *)(outText + copyIndex) = ch;
          ch = "MUL scratch.x, "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
      }
      else if (uVar8 == 2) {
        copyIndex = 0;
        ch = s_DP3_scratch_x__97c2e734[0];
        while (ch != '\0') {
          *(char *)(outText + copyIndex) = ch;
          ch = "DP3 scratch.x, "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
      }
      else {
        copyIndex = 0;
        ch = s_DP4_scratch_x__97c2e744[0];
        while (ch != '\0') {
          *(char *)(outText + copyIndex) = ch;
          ch = "DP4 scratch.x, "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,param_5,param_6,2,0,0,0);
      copyIndex = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,2,0,0,0);
      copyIndex = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ";\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
    }
    copyIndex2 = 0;
    ch = s_RSQ_scratch_x__scratch_x__97c2e754[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex + copyIndex2) = ch;
      ch = "RSQ scratch.x, scratch.x;\n"[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outCursor2 = outCursor + copyIndex + copyIndex2;
    copyIndex = 0;
    ch = s_RCP_97c2e58c[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "RCP "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    iVar6 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor2 + copyIndex,0,0,0);
    opOffsetOrTailLength = 0;
    ch = s___scratch_x__97c2e594[0];
    while (ch != '\0') {
      *(char *)(iVar6 + opOffsetOrTailLength) = ch;
      ch = ", scratch.x;\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 0x15:
    if ((((inst[4] >> 0xc & 3) == 3) || ((stateFlags[1] & 0x800000) == 0)) || (shaderType != 0x8b30))
    {
      *stateFlags = *stateFlags | 1;
      uVar8 = inst[2] >> 10 & 3;
      if (uVar8 == 0) {
        copyIndex = 0;
        ch = s_MUL_scratch_x__97c2e6fc[0];
        while (ch != '\0') {
          *(char *)(outText + copyIndex) = ch;
          ch = "MUL scratch.x, "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,param_5,param_6,2,0,0,0);
        copyIndex = 0;
        ch = s___97c2d7ec[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex) = ch;
          ch = ", "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,2,0,0,0);
        copyIndex = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex) = ch;
          ch = ";\n"[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
      }
      else if (uVar8 == 1) {
        copyIndex = 0;
        ch = s_MUL_scratch_xy__97c2e510[0];
        while (ch != '\0') {
          *(char *)(outText + copyIndex) = ch;
          ch = "MUL scratch.xy, "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,param_5,param_6,2,0,0,0);
        copyIndex = 0;
        ch = s___97c2d7ec[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex) = ch;
          ch = ", "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,2,0,0,0);
        copyIndex = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex) = ch;
          ch = ";\n"[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        outCursor = outCursor + copyIndex;
        copyIndex = 0;
        ch = s_MUL_scratch_x__scratch_x__scratc_97c2e70c[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex) = ch;
          ch = "MUL scratch.x, scratch.x, scratch.y;\n"[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
      }
      else {
        if (uVar8 == 2) {
          copyIndex = 0;
          ch = s_DP3_scratch_x__97c2e734[0];
          while (ch != '\0') {
            *(char *)(outText + copyIndex) = ch;
            ch = "DP3 scratch.x, "[copyIndex + 1];
            copyIndex = copyIndex + 1;
          }
        }
        else {
          copyIndex = 0;
          ch = s_DP4_scratch_x__97c2e744[0];
          while (ch != '\0') {
            *(char *)(outText + copyIndex) = ch;
            ch = "DP4 scratch.x, "[copyIndex + 1];
            copyIndex = copyIndex + 1;
          }
        }
        outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,param_5,param_6,2,0,0,0);
        copyIndex = 0;
        ch = s___97c2d7ec[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex) = ch;
          ch = ", "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,2,0,0,0);
        copyIndex = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex) = ch;
          ch = ";\n"[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
      }
      copyIndex2 = 0;
      ch = s_RSQ_scratch_x__scratch_x__97c2e754[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex + copyIndex2) = ch;
        ch = "RSQ scratch.x, scratch.x;\n"[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      outCursor2 = outCursor + copyIndex + copyIndex2;
      copyIndex = 0;
      ch = s_MUL_97c2e4f0[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "MUL "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor2 + copyIndex,0,0,0);
      copyIndex = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      iVar6 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,2,0,0,8);
      opOffsetOrTailLength = 0;
      ch = s___scratch_x__97c2e594[0];
      while (ch != '\0') {
        *(char *)(iVar6 + opOffsetOrTailLength) = ch;
        ch = ", scratch.x;\n"[opOffsetOrTailLength + 1];
        opOffsetOrTailLength = opOffsetOrTailLength + 1;
      }
    }
    else {
      uVar8 = *stateFlags;
      *stateFlags = uVar8 | 0x800000;
      if ((inst[4] >> 0xc & 3) == 2) {
        copyIndex = 0;
        ch = s_NRM_97c2e6dc[0];
        while (ch != '\0') {
          *(char *)(outText + copyIndex) = ch;
          ch = "NRM "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        iVar11 = outText + copyIndex;
        if ((inst[2] & 0x3fc) == 0x6c) {
          outCursor3 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,iVar11,0,0,0);
        }
        else {
          copyIndex3 = 0;
          ch = s_scratch_97c2e63c[0];
          while (ch != '\0') {
            *(char *)(iVar11 + copyIndex3) = ch;
            ch = "scratch"[copyIndex3 + 1];
            copyIndex3 = copyIndex3 + 1;
          }
          outCursor3 = iVar11 + copyIndex3;
        }
        copyIndex3 = 0;
        ch = s___97c2d7ec[0];
        while (ch != '\0') {
          *(char *)(outCursor3 + copyIndex3) = ch;
          ch = ", "[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor3 + copyIndex3,param_5,param_6,2,0,0,0);
        copyIndex = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex) = ch;
          ch = ";\n"[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
      }
      else {
        *stateFlags = uVar8 | 0x800001;
        copyIndex = 0;
        ch = s_MUL_scratch__97c2e62c[0];
        while (ch != '\0') {
          *(char *)(outText + copyIndex) = ch;
          ch = "MUL scratch, "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        outCursor3 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,param_5,param_6,2,0,0,0);
        if ((inst[4] & 0x3000) == 0) {
          *stateFlags = *stateFlags | 0x1000;
          copyIndex2 = 0;
          ch = s___kFLOAT__97c2e6e4[0];
          while (ch != '\0') {
            *(char *)(outCursor3 + copyIndex2) = ch;
            ch = ", kFLOAT;\n"[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
        }
        else {
          *stateFlags = *stateFlags | 0x1000;
          copyIndex2 = 0;
          ch = s___kVEC2__97c2e6f0[0];
          while (ch != '\0') {
            *(char *)(outCursor3 + copyIndex2) = ch;
            ch = ", kVEC2;\n"[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
        }
        copyIndex3 = 0;
        ch = s_NRM_97c2e6dc[0];
        while (ch != '\0') {
          *(char *)(outCursor3 + copyIndex2 + copyIndex3) = ch;
          ch = "NRM "[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        outCursor = outCursor3 + copyIndex2 + copyIndex3;
        if ((inst[2] & 0x3fc) == 0x6c) {
          outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor,0,0,0);
        }
        else {
          copyIndex = 0;
          ch = s_scratch_97c2e63c[0];
          while (ch != '\0') {
            *(char *)(outCursor + copyIndex) = ch;
            ch = "scratch"[copyIndex + 1];
            copyIndex = copyIndex + 1;
          }
          outCursor = outCursor + copyIndex;
        }
        copyIndex = 0;
        ch = s___scratch__97c2e620[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex) = ch;
          ch = ", scratch;\n"[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
      }
      iVar6 = outCursor + copyIndex;
      if ((inst[2] & 0x3fc) == 0x6c) goto LAB_97c01788;
      copyIndex = 0;
      ch = s_MOV_97c2e430[0];
      while (ch != '\0') {
        *(char *)(iVar6 + copyIndex) = ch;
        ch = "MOV "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,iVar6 + copyIndex,0,0,0);
      copyIndex = 0;
      ch = s___scratch_97c2e65c[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", scratch"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      iVar6 = ((int (*)())_glpWriteComponentsWithDestinationSwizzle)(inst,outCursor + copyIndex);
      opOffsetOrTailLength = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        *(char *)(iVar6 + opOffsetOrTailLength) = ch;
        ch = ";\n"[opOffsetOrTailLength + 1];
        opOffsetOrTailLength = opOffsetOrTailLength + 1;
      }
    }
    break;
  case 0x16:
    copyIndex = 0;
    ch = s_MUL_97c2e4f0[0];
    while (ch != '\0') {
      *(char *)(outText + copyIndex) = ch;
      ch = "MUL "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outText + copyIndex,0,0,0);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    iVar6 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,2,0,0,8);
    opOffsetOrTailLength = 0;
    ch = s___0_0174532925199__97c2e9d0[0];
    while (ch != '\0') {
      *(char *)(iVar6 + opOffsetOrTailLength) = ch;
      ch = ", 0.0174532925199;\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 0x17:
    copyIndex = 0;
    ch = s_MUL_97c2e4f0[0];
    while (ch != '\0') {
      *(char *)(outText + copyIndex) = ch;
      ch = "MUL "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outText + copyIndex,0,0,0);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    iVar6 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,2,0,0,8);
    opOffsetOrTailLength = 0;
    ch = s___57_295779513082__97c2e9bc[0];
    while (ch != '\0') {
      *(char *)(iVar6 + opOffsetOrTailLength) = ch;
      ch = ", 57.295779513082;\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 0x19:
    if (shaderType == 0x8b30) {
      loopIndex = 0;
      do {
        copyIndex2 = 0;
        ch = s_SIN_97c2eb80[0];
        while (ch != '\0') {
          *(char *)(iVar6 + copyIndex2) = ch;
          ch = "SIN "[copyIndex2 + 1];
          copyIndex2 = copyIndex2 + 1;
        }
        outCursor2 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,iVar6 + copyIndex2,0,loopIndex,2);
        copyIndex3 = 0;
        ch = s___97c2d7ec[0];
        while (ch != '\0') {
          *(char *)(outCursor2 + copyIndex3) = ch;
          ch = ", "[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        outCursor6 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex3,param_5,param_6,2,0,loopIndex,10)
        ;
        copyIndex2 = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          *(char *)(outCursor6 + copyIndex2) = ch;
          ch = ";\n"[copyIndex2 + 1];
          copyIndex2 = copyIndex2 + 1;
        }
        loopIndex = loopIndex + 1;
        iVar6 = outCursor6 + copyIndex2;
      } while (loopIndex <= (int)(inst[2] >> 10 & 3));
      opOffsetOrTailLength = 0;
      ch = s___end_97c2eb88[0];
      while (ch != '\0') {
        *(char *)(iVar6 + opOffsetOrTailLength) = ch;
        ch = "# end\n"[opOffsetOrTailLength + 1];
        opOffsetOrTailLength = opOffsetOrTailLength + 1;
      }
    }
    else {
      if (((stateFlags[1] & 0x100000) != 0) && (shaderType == 0x8b31)) {
        *stateFlags = *stateFlags | 0x100000;
        copyIndex3 = 0;
        ch = s___sine__SIN__using_NV_vertex_pro_97c2eb90[0];
        while (ch != '\0') {
          *(char *)(outText + copyIndex3) = ch;
          ch = "# sine (SIN) using NV_vertex_program2_option\n"[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        iVar6 = outText + copyIndex3;
        loopIndex = 0;
        do {
          copyIndex2 = 0;
          ch = s_SIN_97c2eb80[0];
          while (ch != '\0') {
            *(char *)(iVar6 + copyIndex2) = ch;
            ch = "SIN "[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
          outCursor2 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,iVar6 + copyIndex2,0,loopIndex,2);
          copyIndex3 = 0;
          ch = s___97c2d7ec[0];
          while (ch != '\0') {
            *(char *)(outCursor2 + copyIndex3) = ch;
            ch = ", "[copyIndex3 + 1];
            copyIndex3 = copyIndex3 + 1;
          }
          outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex3,param_5,param_6,2,0,loopIndex,10);
          copyIndex2 = 0;
          ch = s___97c2d8f8[0];
          while (ch != '\0') {
            *(char *)(outCursor + copyIndex2) = ch;
            ch = ";\n"[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
          loopIndex = loopIndex + 1;
          iVar6 = outCursor + copyIndex2;
        } while (loopIndex <= (int)(inst[2] >> 10 & 3));
        goto LAB_97c01788;
      }
      *stateFlags = *stateFlags | 0x7007;
      copyIndex = 0;
      ch = s_MAD_scratch__97c2e64c[0];
      while (ch != '\0') {
        *(char *)(outText + copyIndex) = ch;
        ch = "MAD scratch, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,param_5,param_6,2,0,0,8);
      copyIndex = 0;
      ch = s___k2PI_RCP__kHALF__97c2ebc0[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", k2PI_RCP, kHALF;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      copyIndex2 = 0;
      ch = s_FRC_scratch__scratch__97c2ebd4[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex + copyIndex2) = ch;
        ch = "FRC scratch, scratch;\n"[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      outCursor2 = outCursor + copyIndex + copyIndex2;
      copyIndex = 0;
      ch = s_MAD_scratch__scratch__k2PI___kPI_97c2ebec[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "MAD scratch, scratch, k2PI, -kPI;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor2 = outCursor2 + copyIndex;
      copyIndex = 0;
      ch = s_SLT_scratch1__scratch__kZERO__97c2ec10[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "SLT scratch1, scratch, kZERO;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor2 = outCursor2 + copyIndex;
      copyIndex = 0;
      ch = s_ABS_scratch__scratch__97c2e8c0[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "ABS scratch, scratch;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor2 = outCursor2 + copyIndex;
      copyIndex = 0;
      ch = s_SUB_scratch__scratch__kHALFPI__97c2ec30[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "SUB scratch, scratch, kHALFPI;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor2 = outCursor2 + copyIndex;
      copyIndex = 0;
      ch = s_ABS_scratch__scratch__97c2e8c0[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "ABS scratch, scratch;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor2 = outCursor2 + copyIndex;
      copyIndex = 0;
      ch = s_MUL_scratch__scratch__kHALFPI_RC_97c2ec50[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "MUL scratch, scratch, kHALFPI_RCP;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor2 = outCursor2 + copyIndex;
      copyIndex = 0;
      ch = s_SUB_scratch2__kTHREE__scratch__97c2ec74[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "SUB scratch2, kTHREE, scratch;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor2 = outCursor2 + copyIndex;
      copyIndex = 0;
      ch = s_MUL_scratch2__scratch2__scratch__97c2ec94[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "MUL scratch2, scratch2, scratch;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor2 = outCursor2 + copyIndex;
      copyIndex = 0;
      ch = s_MUL_scratch2__scratch2__scratch__97c2ec94[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "MUL scratch2, scratch2, scratch;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor2 = outCursor2 + copyIndex;
      copyIndex = 0;
      ch = s_MAD_scratch2__scratch2___kHALF__k_97c2ecb8[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "MAD scratch2, scratch2, -kHALF, kONE;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor2 = outCursor2 + copyIndex;
      copyIndex = 0;
      ch = s_MAD_scratch1__scratch1___kTWO__k_97c2ece0[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "MAD scratch1, scratch1, -kTWO, kONE;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor2 = outCursor2 + copyIndex;
      copyIndex = 0;
      ch = s_MUL_97c2e4f0[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "MUL "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      iVar6 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor2 + copyIndex,0,0,0);
      opOffsetOrTailLength = 0;
      ch = s___scratch2__scratch1__97c2ed08[0];
      while (ch != '\0') {
        *(char *)(iVar6 + opOffsetOrTailLength) = ch;
        ch = ", scratch2, scratch1;\n"[opOffsetOrTailLength + 1];
        opOffsetOrTailLength = opOffsetOrTailLength + 1;
      }
    }
    break;
  case 0x1a:
    if (shaderType == 0x8b30) {
      copyIndex3 = 0;
      ch = s___cosine__COS__97c2ed20[0];
      while (ch != '\0') {
        *(char *)(outText + copyIndex3) = ch;
        ch = "# cosine (COS)\n"[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      iVar6 = outText + copyIndex3;
      loopIndex = 0;
      do {
        copyIndex2 = 0;
        ch = s_COS_97c2ed30[0];
        while (ch != '\0') {
          *(char *)(iVar6 + copyIndex2) = ch;
          ch = "COS "[copyIndex2 + 1];
          copyIndex2 = copyIndex2 + 1;
        }
        outCursor2 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,iVar6 + copyIndex2,0,loopIndex,2);
        copyIndex3 = 0;
        ch = s___97c2d7ec[0];
        while (ch != '\0') {
          *(char *)(outCursor2 + copyIndex3) = ch;
          ch = ", "[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        outCursor6 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex3,param_5,param_6,2,0,loopIndex,10)
        ;
        copyIndex2 = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          *(char *)(outCursor6 + copyIndex2) = ch;
          ch = ";\n"[copyIndex2 + 1];
          copyIndex2 = copyIndex2 + 1;
        }
        loopIndex = loopIndex + 1;
        iVar6 = outCursor6 + copyIndex2;
      } while (loopIndex <= (int)(inst[2] >> 10 & 3));
      opOffsetOrTailLength = 0;
      ch = s___end_97c2eb88[0];
      while (ch != '\0') {
        *(char *)(iVar6 + opOffsetOrTailLength) = ch;
        ch = "# end\n"[opOffsetOrTailLength + 1];
        opOffsetOrTailLength = opOffsetOrTailLength + 1;
      }
    }
    else {
      if (((stateFlags[1] & 0x100000) != 0) && (shaderType == 0x8b31)) {
        *stateFlags = *stateFlags | 0x100000;
        copyIndex3 = 0;
        ch = s___cosine__COS__using_NV_vertex_p_97c2ed38[0];
        while (ch != '\0') {
          *(char *)(outText + copyIndex3) = ch;
          ch = "# cosine (COS) using NV_vertex_program2_option\n"[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        iVar6 = outText + copyIndex3;
        loopIndex = 0;
        do {
          copyIndex2 = 0;
          ch = s_COS_97c2ed30[0];
          while (ch != '\0') {
            *(char *)(iVar6 + copyIndex2) = ch;
            ch = "COS "[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
          outCursor2 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,iVar6 + copyIndex2,0,loopIndex,2);
          copyIndex3 = 0;
          ch = s___97c2d7ec[0];
          while (ch != '\0') {
            *(char *)(outCursor2 + copyIndex3) = ch;
            ch = ", "[copyIndex3 + 1];
            copyIndex3 = copyIndex3 + 1;
          }
          outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex3,param_5,param_6,2,0,loopIndex,10);
          copyIndex2 = 0;
          ch = s___97c2d8f8[0];
          while (ch != '\0') {
            *(char *)(outCursor + copyIndex2) = ch;
            ch = ";\n"[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
          loopIndex = loopIndex + 1;
          iVar6 = outCursor + copyIndex2;
        } while (loopIndex <= (int)(inst[2] >> 10 & 3));
        goto LAB_97c01788;
      }
      *stateFlags = *stateFlags | 0x7003;
      copyIndex = 0;
      ch = s_MAD_scratch__97c2e64c[0];
      while (ch != '\0') {
        *(char *)(outText + copyIndex) = ch;
        ch = "MAD scratch, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,param_5,param_6,2,0,0,8);
      copyIndex = 0;
      ch = s___k2PI_RCP__kHALF__97c2ebc0[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", k2PI_RCP, kHALF;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      copyIndex2 = 0;
      ch = s_FRC_scratch__scratch__97c2ebd4[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex + copyIndex2) = ch;
        ch = "FRC scratch, scratch;\n"[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      outCursor2 = outCursor + copyIndex + copyIndex2;
      copyIndex = 0;
      ch = s_MAD_scratch__scratch__k2PI___kPI_97c2ebec[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "MAD scratch, scratch, k2PI, -kPI;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor2 = outCursor2 + copyIndex;
      copyIndex = 0;
      ch = s_ABS_scratch__scratch__97c2e8c0[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "ABS scratch, scratch;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor2 = outCursor2 + copyIndex;
      copyIndex = 0;
      ch = s_MUL_scratch__scratch__kHALFPI_RC_97c2ec50[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "MUL scratch, scratch, kHALFPI_RCP;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor2 = outCursor2 + copyIndex;
      copyIndex = 0;
      ch = s_SUB_scratch1__kTHREE__scratch__97c2ed68[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "SUB scratch1, kTHREE, scratch;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor2 = outCursor2 + copyIndex;
      copyIndex = 0;
      ch = s_MUL_scratch1__scratch1__scratch__97c2ed88[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "MUL scratch1, scratch1, scratch;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor2 = outCursor2 + copyIndex;
      copyIndex = 0;
      ch = s_MUL_scratch1__scratch1__scratch__97c2ed88[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "MUL scratch1, scratch1, scratch;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor2 = outCursor2 + copyIndex;
      copyIndex = 0;
      ch = s_MAD_97c2e644[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "MAD "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      iVar6 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor2 + copyIndex,0,0,0);
      opOffsetOrTailLength = 0;
      ch = s___scratch1___kHALF__kONE__97c2edac[0];
      while (ch != '\0') {
        *(char *)(iVar6 + opOffsetOrTailLength) = ch;
        ch = ", scratch1, -kHALF, kONE;\n"[opOffsetOrTailLength + 1];
        opOffsetOrTailLength = opOffsetOrTailLength + 1;
      }
    }
    break;
  case 0x1b:
    *stateFlags = *stateFlags | 0x2f00f;
    copyIndex = 0;
    ch = s_MAD_scratch__97c2e64c[0];
    while (ch != '\0') {
      *(char *)(outText + copyIndex) = ch;
      ch = "MAD scratch, "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,param_5,param_6,2,0,0,8);
    copyIndex = 0;
    ch = s___kPI_RCP__kHALF__97c2edc8[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", kPI_RCP, kHALF;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    copyIndex2 = 0;
    ch = s_FRC_scratch__scratch__97c2ebd4[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex + copyIndex2) = ch;
      ch = "FRC scratch, scratch;\n"[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outCursor2 = outCursor + copyIndex + copyIndex2;
    copyIndex = 0;
    ch = s_MAD_scratch__scratch__kPI___kHAL_97c2eddc[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "MAD scratch, scratch, kPI, -kHALFPI;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor2 = outCursor2 + copyIndex;
    copyIndex = 0;
    ch = s_MUL_scratch1__scratch__scratch__97c2ee04[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "MUL scratch1, scratch, scratch;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor2 = outCursor2 + copyIndex;
    copyIndex = 0;
    ch = s_MUL_scratch2__scratch1__scratch__97c2ee28[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "MUL scratch2, scratch1, scratch;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor2 = outCursor2 + copyIndex;
    copyIndex = 0;
    ch = s_MUL_scratch3__scratch1__scratch1_97c2ee4c[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "MUL scratch3, scratch1, scratch1;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor2 = outCursor2 + copyIndex;
    copyIndex = 0;
    ch = s_MAD_scratch__kTAN_K1__scratch2__s_97c2ee70[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "MAD scratch, kTAN_K1, scratch2, scratch;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor2 = outCursor2 + copyIndex;
    copyIndex = 0;
    ch = s_MAD_scratch2__kTAN_K2__scratch1__97c2ee9c[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "MAD scratch2, kTAN_K2, scratch1, kONE;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor2 = outCursor2 + copyIndex;
    copyIndex = 0;
    ch = s_MAD_scratch1__kTAN_K3__scratch3__97c2eec4[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "MAD scratch1, kTAN_K3, scratch3, scratch2;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outPtr = (char *)(outCursor2 + copyIndex);
    if ((inst[2] & 0x3000) == 0) {
      copyIndex = 0;
      ch = s_RCP_scratch1_x__scratch1_x__97c2eef0[0];
      while (ch != '\0') {
        outPtr[copyIndex] = ch;
        ch = "RCP scratch1.x, scratch1.x;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outPtr = outPtr + copyIndex;
    }
    else {
      loopIndex = 0;
      do {
        copyIndex3 = 0;
        ch = s_RCP_scratch1__97c2ea98[0];
        while (ch != '\0') {
          outPtr[copyIndex3] = ch;
          ch = "RCP scratch1."[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        loopIndex = loopIndex + 1;
        outPtr = outPtr + copyIndex3;
        *outPtr = ((byte)loopIndex & 3) + 0x77;
        copyIndex3 = 0;
        ch = s___scratch1__97c2ef10[0];
        while (ch != '\0') {
          outPtr[copyIndex3 + 1] = ch;
          ch = ", scratch1."[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        outPtr = outPtr + copyIndex3 + 1;
        *outPtr = ((byte)loopIndex & 3) + 0x77;
        copyIndex3 = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          outPtr[copyIndex3 + 1] = ch;
          ch = ";\n"[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        outPtr = outPtr + copyIndex3 + 1;
      } while (loopIndex <= (int)(inst[2] >> 10 & 3));
    }
    copyIndex = 0;
    ch = s_MUL_97c2e4f0[0];
    while (ch != '\0') {
      outPtr[copyIndex] = ch;
      ch = "MUL "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    iVar6 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outPtr + copyIndex,0,0,0);
    opOffsetOrTailLength = 0;
    ch = s___scratch__scratch1__97c2e4f8[0];
    while (ch != '\0') {
      *(char *)(iVar6 + opOffsetOrTailLength) = ch;
      ch = ", scratch, scratch1;\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 0x1c:
    *stateFlags = *stateFlags | 0x1307f;
    copyIndex = 0;
    ch = s_SLT_scratch__97c2e474[0];
    while (ch != '\0') {
      *(char *)(outText + copyIndex) = ch;
      ch = "SLT scratch, "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,param_5,param_6,2,0,0,8);
    copyIndex = 0;
    ch = s___kZERO__97c2e484[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", kZERO;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    copyIndex2 = 0;
    ch = s_MUL_scratch1__97c2ef1c[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex + copyIndex2) = ch;
      ch = "MUL scratch1, "[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex + copyIndex2,param_5,param_6,2,0,0,8);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,2,0,0,8);
    copyIndex = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ";\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    copyIndex2 = 0;
    ch = s_SUB_scratch1__kONE__scratch1__97c2ef2c[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex + copyIndex2) = ch;
      ch = "SUB scratch1, kONE, scratch1;\n"[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outCursor2 = outCursor + copyIndex + copyIndex2;
    copyIndex = 0;
    ch = s_SGE_scratch5__kZERO__scratch1__97c2ef4c[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "SGE scratch5, kZERO, scratch1;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outPtr = (char *)(outCursor2 + copyIndex);
    loopIndex = 0;
    do {
      copyIndex3 = 0;
      ch = s_RSQ_scratch1__97c2ef6c[0];
      while (ch != '\0') {
        outPtr[copyIndex3] = ch;
        ch = "RSQ scratch1."[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      loopIndex = loopIndex + 1;
      outPtr = outPtr + copyIndex3;
      *outPtr = ((byte)loopIndex & 3) + 0x77;
      copyIndex3 = 0;
      ch = s___scratch1__97c2ef10[0];
      while (ch != '\0') {
        outPtr[copyIndex3 + 1] = ch;
        ch = ", scratch1."[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      outPtr = outPtr + copyIndex3 + 1;
      *outPtr = ((byte)loopIndex & 3) + 0x77;
      copyIndex3 = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        outPtr[copyIndex3 + 1] = ch;
        ch = ";\n"[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      outPtr = outPtr + copyIndex3 + 1;
    } while (loopIndex <= (int)(inst[4] >> 0xc & 3));
    copyIndex = 0;
    ch = s_MUL_scratch2__97c2ef7c[0];
    while (ch != '\0') {
      outPtr[copyIndex] = ch;
      ch = "MUL scratch2, "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outPtr + copyIndex,param_5,param_6,2,0,0,8);
    copyIndex = 0;
    ch = s___scratch1__97c2e684[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", scratch1;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    copyIndex2 = 0;
    ch = s_ABS_scratch2__scratch2__97c2ef8c[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex + copyIndex2) = ch;
      ch = "ABS scratch2, scratch2;\n"[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outCursor2 = outCursor + copyIndex + copyIndex2;
    copyIndex = 0;
    ch = s_SLT_scratch6__kONE__scratch2__97c2efa8[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "SLT scratch6, kONE, scratch2;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outPtr = (char *)(outCursor2 + copyIndex);
    loopIndex = 0;
    do {
      copyIndex3 = 0;
      ch = s_RCP_scratch3__97c2efc8[0];
      while (ch != '\0') {
        outPtr[copyIndex3] = ch;
        ch = "RCP scratch3."[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      loopIndex = loopIndex + 1;
      outPtr = outPtr + copyIndex3;
      *outPtr = ((byte)loopIndex & 3) + 0x77;
      copyIndex3 = 0;
      ch = s___scratch2__97c2efd8[0];
      while (ch != '\0') {
        outPtr[copyIndex3 + 1] = ch;
        ch = ", scratch2."[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      outPtr = outPtr + copyIndex3 + 1;
      *outPtr = ((byte)loopIndex & 3) + 0x77;
      copyIndex3 = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        outPtr[copyIndex3 + 1] = ch;
        ch = ";\n"[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      outPtr = outPtr + copyIndex3 + 1;
    } while (loopIndex <= (int)(inst[4] >> 0xc & 3));
    copyIndex = 0;
    ch = s_SUB_scratch3__scratch3__scratch2_97c2efe4[0];
    while (ch != '\0') {
      outPtr[copyIndex] = ch;
      ch = "SUB scratch3, scratch3, scratch2;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    copyIndex3 = 0;
    ch = s_MAD_scratch2__scratch6__scratch3_97c2f008[0];
    while (ch != '\0') {
      outPtr[copyIndex3 + copyIndex] = ch;
      ch = "MAD scratch2, scratch6, scratch3, scratch2;\n"[copyIndex3 + 1];
      copyIndex3 = copyIndex3 + 1;
    }
    copyIndex2 = 0;
    ch = s_MUL_scratch1__scratch2__scratch2_97c2f038[0];
    while (ch != '\0') {
      outPtr[copyIndex2 + copyIndex3 + copyIndex] = ch;
      ch = "MUL scratch1, scratch2, scratch2;\n"[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    iVar5 = copyIndex2 + copyIndex3 + copyIndex;
    copyIndex = 0;
    ch = s_MUL_scratch3__scratch1__scratch2_97c2f05c[0];
    while (ch != '\0') {
      outPtr[copyIndex + iVar5] = ch;
      ch = "MUL scratch3, scratch1, scratch2;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    iVar11 = copyIndex + iVar5;
    copyIndex3 = 0;
    ch = s_MUL_scratch4__scratch1__scratch1_97c2f080[0];
    while (ch != '\0') {
      outPtr[copyIndex3 + iVar11] = ch;
      ch = "MUL scratch4, scratch1, scratch1;\n"[copyIndex3 + 1];
      copyIndex3 = copyIndex3 + 1;
    }
    outPos = copyIndex3 + iVar11;
    copyIndex = 0;
    ch = s_MUL_scratch2__kATAN_K1__scratch2_97c2f0a4[0];
    while (ch != '\0') {
      outPtr[copyIndex + outPos] = ch;
      ch = "MUL scratch2, kATAN_K1, scratch2;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    iVar11 = copyIndex + outPos;
    copyIndex3 = 0;
    ch = s_MAD_scratch2__kATAN_K3__scratch3_97c2f0c8[0];
    while (ch != '\0') {
      outPtr[copyIndex3 + iVar11] = ch;
      ch = "MAD scratch2, kATAN_K3, scratch3, scratch2;\n"[copyIndex3 + 1];
      copyIndex3 = copyIndex3 + 1;
    }
    outPos = copyIndex3 + iVar11;
    copyIndex = 0;
    ch = s_MAD_scratch1__kATAN_K2__scratch1_97c2f0f8[0];
    while (ch != '\0') {
      outPtr[copyIndex + outPos] = ch;
      ch = "MAD scratch1, kATAN_K2, scratch1, kONE;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    iVar11 = copyIndex + outPos;
    copyIndex3 = 0;
    ch = s_MAD_scratch1__kATAN_K4__scratch4_97c2f124[0];
    while (ch != '\0') {
      outPtr[copyIndex3 + iVar11] = ch;
      ch = "MAD scratch1, kATAN_K4, scratch4, scratch1;\n"[copyIndex3 + 1];
      copyIndex3 = copyIndex3 + 1;
    }
    outPtr = outPtr + copyIndex3 + iVar11;
    loopIndex = 0;
    do {
      copyIndex3 = 0;
      ch = s_RCP_scratch1__97c2ea98[0];
      while (ch != '\0') {
        outPtr[copyIndex3] = ch;
        ch = "RCP scratch1."[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      loopIndex = loopIndex + 1;
      outPtr = outPtr + copyIndex3;
      *outPtr = ((byte)loopIndex & 3) + 0x77;
      copyIndex3 = 0;
      ch = s___scratch1__97c2ef10[0];
      while (ch != '\0') {
        outPtr[copyIndex3 + 1] = ch;
        ch = ", scratch1."[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      outPtr = outPtr + copyIndex3 + 1;
      *outPtr = ((byte)loopIndex & 3) + 0x77;
      copyIndex3 = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        outPtr[copyIndex3 + 1] = ch;
        ch = ";\n"[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      outPtr = outPtr + copyIndex3 + 1;
    } while (loopIndex <= (int)(inst[4] >> 0xc & 3));
    copyIndex = 0;
    ch = s_MUL_scratch2__scratch2__scratch1_97c2f154[0];
    while (ch != '\0') {
      outPtr[copyIndex] = ch;
      ch = "MUL scratch2, scratch2, scratch1;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    copyIndex3 = 0;
    ch = s_MAD_scratch1__kTWO___scratch2__k_97c2f178[0];
    while (ch != '\0') {
      outPtr[copyIndex3 + copyIndex] = ch;
      ch = "MAD scratch1, kTWO, -scratch2, kHALFPI;\n"[copyIndex3 + 1];
      copyIndex3 = copyIndex3 + 1;
    }
    copyIndex2 = 0;
    ch = s_MAD_scratch2__scratch6__scratch1_97c2f1a4[0];
    while (ch != '\0') {
      outPtr[copyIndex2 + copyIndex3 + copyIndex] = ch;
      ch = "MAD scratch2, scratch6, scratch1, scratch2;\n"[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    iVar5 = copyIndex2 + copyIndex3 + copyIndex;
    copyIndex = 0;
    ch = s_SUB_scratch1__kHALFPI__scratch2__97c2f1d4[0];
    while (ch != '\0') {
      outPtr[copyIndex + iVar5] = ch;
      ch = "SUB scratch1, kHALFPI, scratch2;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    iVar11 = copyIndex + iVar5;
    copyIndex3 = 0;
    ch = s_MAD_scratch2__scratch5__scratch1_97c2f1f8[0];
    while (ch != '\0') {
      outPtr[copyIndex3 + iVar11] = ch;
      ch = "MAD scratch2, scratch5, scratch1, scratch2;\n"[copyIndex3 + 1];
      copyIndex3 = copyIndex3 + 1;
    }
    outPos = copyIndex3 + iVar11;
    copyIndex = 0;
    ch = s_MAD_scratch__scratch___kTWO__kON_97c2f228[0];
    while (ch != '\0') {
      outPtr[copyIndex + outPos] = ch;
      ch = "MAD scratch, scratch, -kTWO, kONE;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    iVar11 = copyIndex + outPos;
    copyIndex3 = 0;
    ch = s_MUL_97c2e4f0[0];
    while (ch != '\0') {
      outPtr[copyIndex3 + iVar11] = ch;
      ch = "MUL "[copyIndex3 + 1];
      copyIndex3 = copyIndex3 + 1;
    }
    iVar6 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outPtr + copyIndex3 + iVar11,0,0,0);
    opOffsetOrTailLength = 0;
    ch = s___scratch2__scratch__97c2f24c[0];
    while (ch != '\0') {
      *(char *)(iVar6 + opOffsetOrTailLength) = ch;
      ch = ", scratch2, scratch;\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 0x1d:
    *stateFlags = *stateFlags | 0x3307f;
    copyIndex = 0;
    ch = s_SLT_scratch__97c2e474[0];
    while (ch != '\0') {
      *(char *)(outText + copyIndex) = ch;
      ch = "SLT scratch, "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,param_5,param_6,2,0,0,8);
    copyIndex = 0;
    ch = s___kZERO__97c2e484[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", kZERO;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    copyIndex2 = 0;
    ch = s_MUL_scratch1__97c2ef1c[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex + copyIndex2) = ch;
      ch = "MUL scratch1, "[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex + copyIndex2,param_5,param_6,2,0,0,8);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,2,0,0,8);
    copyIndex = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ";\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    copyIndex2 = 0;
    ch = s_SUB_scratch1__kONE__scratch1__97c2ef2c[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex + copyIndex2) = ch;
      ch = "SUB scratch1, kONE, scratch1;\n"[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outCursor2 = outCursor + copyIndex + copyIndex2;
    copyIndex = 0;
    ch = s_SGE_scratch5__kZERO__scratch1__97c2ef4c[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "SGE scratch5, kZERO, scratch1;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outPtr = (char *)(outCursor2 + copyIndex);
    loopIndex = 0;
    do {
      copyIndex3 = 0;
      ch = s_RSQ_scratch1__97c2ef6c[0];
      while (ch != '\0') {
        outPtr[copyIndex3] = ch;
        ch = "RSQ scratch1."[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      loopIndex = loopIndex + 1;
      outPtr = outPtr + copyIndex3;
      *outPtr = ((byte)loopIndex & 3) + 0x77;
      copyIndex3 = 0;
      ch = s___scratch1__97c2ef10[0];
      while (ch != '\0') {
        outPtr[copyIndex3 + 1] = ch;
        ch = ", scratch1."[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      outPtr = outPtr + copyIndex3 + 1;
      *outPtr = ((byte)loopIndex & 3) + 0x77;
      copyIndex3 = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        outPtr[copyIndex3 + 1] = ch;
        ch = ";\n"[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      outPtr = outPtr + copyIndex3 + 1;
    } while (loopIndex <= (int)(inst[4] >> 0xc & 3));
    copyIndex = 0;
    ch = s_MUL_scratch2__97c2ef7c[0];
    while (ch != '\0') {
      outPtr[copyIndex] = ch;
      ch = "MUL scratch2, "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outPtr + copyIndex,param_5,param_6,2,0,0,8);
    copyIndex = 0;
    ch = s___scratch1__97c2e684[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", scratch1;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    copyIndex2 = 0;
    ch = s_ABS_scratch2__scratch2__97c2ef8c[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex + copyIndex2) = ch;
      ch = "ABS scratch2, scratch2;\n"[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outCursor2 = outCursor + copyIndex + copyIndex2;
    copyIndex = 0;
    ch = s_ADD_scratch2__scratch2__kOFFSET__97c2f5c0[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "ADD scratch2, scratch2, kOFFSET;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor2 = outCursor2 + copyIndex;
    copyIndex = 0;
    ch = s_SLT_scratch6__kONE__scratch2__97c2efa8[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "SLT scratch6, kONE, scratch2;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outPtr = (char *)(outCursor2 + copyIndex);
    loopIndex = 0;
    do {
      copyIndex3 = 0;
      ch = s_RCP_scratch3__97c2efc8[0];
      while (ch != '\0') {
        outPtr[copyIndex3] = ch;
        ch = "RCP scratch3."[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      loopIndex = loopIndex + 1;
      outPtr = outPtr + copyIndex3;
      *outPtr = ((byte)loopIndex & 3) + 0x77;
      copyIndex3 = 0;
      ch = s___scratch2__97c2efd8[0];
      while (ch != '\0') {
        outPtr[copyIndex3 + 1] = ch;
        ch = ", scratch2."[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      outPtr = outPtr + copyIndex3 + 1;
      *outPtr = ((byte)loopIndex & 3) + 0x77;
      copyIndex3 = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        outPtr[copyIndex3 + 1] = ch;
        ch = ";\n"[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      outPtr = outPtr + copyIndex3 + 1;
    } while (loopIndex <= (int)(inst[4] >> 0xc & 3));
    copyIndex = 0;
    ch = s_SUB_scratch3__scratch3__scratch2_97c2efe4[0];
    while (ch != '\0') {
      outPtr[copyIndex] = ch;
      ch = "SUB scratch3, scratch3, scratch2;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    copyIndex3 = 0;
    ch = s_MAD_scratch2__scratch6__scratch3_97c2f008[0];
    while (ch != '\0') {
      outPtr[copyIndex3 + copyIndex] = ch;
      ch = "MAD scratch2, scratch6, scratch3, scratch2;\n"[copyIndex3 + 1];
      copyIndex3 = copyIndex3 + 1;
    }
    copyIndex2 = 0;
    ch = s_MUL_scratch1__scratch2__scratch2_97c2f038[0];
    while (ch != '\0') {
      outPtr[copyIndex2 + copyIndex3 + copyIndex] = ch;
      ch = "MUL scratch1, scratch2, scratch2;\n"[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    iVar5 = copyIndex2 + copyIndex3 + copyIndex;
    copyIndex = 0;
    ch = s_MUL_scratch3__scratch1__scratch2_97c2f05c[0];
    while (ch != '\0') {
      outPtr[copyIndex + iVar5] = ch;
      ch = "MUL scratch3, scratch1, scratch2;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    iVar11 = copyIndex + iVar5;
    copyIndex3 = 0;
    ch = s_MUL_scratch4__scratch1__scratch1_97c2f080[0];
    while (ch != '\0') {
      outPtr[copyIndex3 + iVar11] = ch;
      ch = "MUL scratch4, scratch1, scratch1;\n"[copyIndex3 + 1];
      copyIndex3 = copyIndex3 + 1;
    }
    outPos = copyIndex3 + iVar11;
    copyIndex = 0;
    ch = s_MUL_scratch2__kATAN_K1__scratch2_97c2f0a4[0];
    while (ch != '\0') {
      outPtr[copyIndex + outPos] = ch;
      ch = "MUL scratch2, kATAN_K1, scratch2;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    iVar11 = copyIndex + outPos;
    copyIndex3 = 0;
    ch = s_MAD_scratch2__kATAN_K3__scratch3_97c2f0c8[0];
    while (ch != '\0') {
      outPtr[copyIndex3 + iVar11] = ch;
      ch = "MAD scratch2, kATAN_K3, scratch3, scratch2;\n"[copyIndex3 + 1];
      copyIndex3 = copyIndex3 + 1;
    }
    outPos = copyIndex3 + iVar11;
    copyIndex = 0;
    ch = s_MAD_scratch1__kATAN_K2__scratch1_97c2f0f8[0];
    while (ch != '\0') {
      outPtr[copyIndex + outPos] = ch;
      ch = "MAD scratch1, kATAN_K2, scratch1, kONE;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    iVar11 = copyIndex + outPos;
    copyIndex3 = 0;
    ch = s_MAD_scratch1__kATAN_K4__scratch4_97c2f124[0];
    while (ch != '\0') {
      outPtr[copyIndex3 + iVar11] = ch;
      ch = "MAD scratch1, kATAN_K4, scratch4, scratch1;\n"[copyIndex3 + 1];
      copyIndex3 = copyIndex3 + 1;
    }
    outPtr = outPtr + copyIndex3 + iVar11;
    loopIndex = 0;
    do {
      copyIndex3 = 0;
      ch = s_RCP_scratch1__97c2ea98[0];
      while (ch != '\0') {
        outPtr[copyIndex3] = ch;
        ch = "RCP scratch1."[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      loopIndex = loopIndex + 1;
      outPtr = outPtr + copyIndex3;
      *outPtr = ((byte)loopIndex & 3) + 0x77;
      copyIndex3 = 0;
      ch = s___scratch1__97c2ef10[0];
      while (ch != '\0') {
        outPtr[copyIndex3 + 1] = ch;
        ch = ", scratch1."[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      outPtr = outPtr + copyIndex3 + 1;
      *outPtr = ((byte)loopIndex & 3) + 0x77;
      copyIndex3 = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        outPtr[copyIndex3 + 1] = ch;
        ch = ";\n"[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      outPtr = outPtr + copyIndex3 + 1;
    } while (loopIndex <= (int)(inst[4] >> 0xc & 3));
    copyIndex = 0;
    ch = s_MUL_scratch2__scratch2__scratch1_97c2f154[0];
    while (ch != '\0') {
      outPtr[copyIndex] = ch;
      ch = "MUL scratch2, scratch2, scratch1;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    copyIndex3 = 0;
    ch = s_MAD_scratch1__kTWO___scratch2__k_97c2f178[0];
    while (ch != '\0') {
      outPtr[copyIndex3 + copyIndex] = ch;
      ch = "MAD scratch1, kTWO, -scratch2, kHALFPI;\n"[copyIndex3 + 1];
      copyIndex3 = copyIndex3 + 1;
    }
    copyIndex2 = 0;
    ch = s_MAD_scratch2__scratch6__scratch1_97c2f1a4[0];
    while (ch != '\0') {
      outPtr[copyIndex2 + copyIndex3 + copyIndex] = ch;
      ch = "MAD scratch2, scratch6, scratch1, scratch2;\n"[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    iVar5 = copyIndex2 + copyIndex3 + copyIndex;
    copyIndex = 0;
    ch = s_SUB_scratch1__kHALFPI__scratch2__97c2f1d4[0];
    while (ch != '\0') {
      outPtr[copyIndex + iVar5] = ch;
      ch = "SUB scratch1, kHALFPI, scratch2;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    iVar11 = copyIndex + iVar5;
    copyIndex3 = 0;
    ch = s_MAD_scratch2__scratch5__scratch1_97c2f1f8[0];
    while (ch != '\0') {
      outPtr[copyIndex3 + iVar11] = ch;
      ch = "MAD scratch2, scratch5, scratch1, scratch2;\n"[copyIndex3 + 1];
      copyIndex3 = copyIndex3 + 1;
    }
    outPos = copyIndex3 + iVar11;
    copyIndex = 0;
    ch = s_MAD_scratch__scratch___kTWO__kON_97c2f228[0];
    while (ch != '\0') {
      outPtr[copyIndex + outPos] = ch;
      ch = "MAD scratch, scratch, -kTWO, kONE;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    iVar11 = copyIndex + outPos;
    copyIndex3 = 0;
    ch = s_MUL_scratch__scratch2__scratch__97c2f5e4[0];
    while (ch != '\0') {
      outPtr[copyIndex3 + iVar11] = ch;
      ch = "MUL scratch, scratch2, scratch;\n"[copyIndex3 + 1];
      copyIndex3 = copyIndex3 + 1;
    }
    outPos = copyIndex3 + iVar11;
    copyIndex = 0;
    ch = s_SUB_97c2e934[0];
    while (ch != '\0') {
      outPtr[copyIndex + outPos] = ch;
      ch = "SUB "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    iVar6 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outPtr + copyIndex + outPos,0,0,0);
    opOffsetOrTailLength = 0;
    ch = s___kHALFPI__scratch__97c2f608[0];
    while (ch != '\0') {
      *(char *)(iVar6 + opOffsetOrTailLength) = ch;
      ch = ", kHALFPI, scratch;\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 0x1e:
    *stateFlags = *stateFlags | 0x331ff;
    if (*inst >> 0x1d == 2) {
      copyIndex = 0;
      ch = s_SGE_scratch__97c2f264[0];
      while (ch != '\0') {
        *(char *)(outText + copyIndex) = ch;
        ch = "SGE scratch, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,param_5,param_6,2,0,0,8);
      copyIndex = 0;
      ch = s___kZERO__97c2e484[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", kZERO;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      copyIndex2 = 0;
      ch = s_MAD_scratch__scratch__k2PI___kPI_97c2ebec[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex + copyIndex2) = ch;
        ch = "MAD scratch, scratch, k2PI, -kPI;\n"[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      outCursor2 = outCursor + copyIndex + copyIndex2;
      copyIndex = 0;
      ch = s_SLT_scratch1__97c2e490[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "SLT scratch1, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex,param_5,param_6,3,0,0,8);
      copyIndex = 0;
      ch = s___kZERO__97c2e484[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", kZERO;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      copyIndex2 = 0;
      ch = s_MUL_scratch4__scratch__scratch1__97c2f274[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex + copyIndex2) = ch;
        ch = "MUL scratch4, scratch, scratch1;\n"[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      outCursor2 = outCursor + copyIndex + copyIndex2;
      copyIndex = 0;
      ch = s_ABS_scratch__97c2e448[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "ABS scratch, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex,param_5,param_6,3,0,0,8);
      copyIndex = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ";\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      copyIndex2 = 0;
      ch = s_SGE_scratch5___scratch__kZERO__97c2f298[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex + copyIndex2) = ch;
        ch = "SGE scratch5, -scratch, kZERO;\n"[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      outCursor2 = outCursor + copyIndex + copyIndex2;
      copyIndex = 0;
      ch = s_SLT_scratch__97c2e474[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "SLT scratch, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex,param_5,param_6,2,0,0,8);
      copyIndex = 0;
      ch = s___kZERO__97c2e484[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", kZERO;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      copyIndex2 = 0;
      ch = s_MAD_scratch6__scratch___kPI__kHA_97c2f2b8[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex + copyIndex2) = ch;
        ch = "MAD scratch6, scratch, -kPI, kHALFPI;\n"[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      outCursor2 = outCursor + copyIndex + copyIndex2;
      copyIndex = 0;
      ch = s_MAD_scratch1__scratch5__kOFFSET__97c2f2e0[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "MAD scratch1, scratch5, kOFFSET, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex,param_5,param_6,3,0,0,8);
      copyIndex = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ";\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outPtr = (char *)(outCursor + copyIndex);
      loopIndex = 0;
      do {
        copyIndex3 = 0;
        ch = s_RCP_scratch__97c2e5f0[0];
        while (ch != '\0') {
          outPtr[copyIndex3] = ch;
          ch = "RCP scratch."[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        loopIndex = loopIndex + 1;
        outPtr = outPtr + copyIndex3;
        *outPtr = ((byte)loopIndex & 3) + 0x77;
        copyIndex3 = 0;
        ch = s___scratch1__97c2ef10[0];
        while (ch != '\0') {
          outPtr[copyIndex3 + 1] = ch;
          ch = ", scratch1."[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        outPtr = outPtr + copyIndex3 + 1;
        *outPtr = ((byte)loopIndex & 3) + 0x77;
        copyIndex3 = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          outPtr[copyIndex3 + 1] = ch;
          ch = ";\n"[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        outPtr = outPtr + copyIndex3 + 1;
      } while (loopIndex <= (int)(inst[6] >> 0xc & 3));
      copyIndex = 0;
      ch = s_MUL_scratch__97c2e62c[0];
      while (ch != '\0') {
        outPtr[copyIndex] = ch;
        ch = "MUL scratch, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outPtr + copyIndex,param_5,param_6,2,0,0,8);
      copyIndex = 0;
      ch = s___scratch__97c2e620[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", scratch;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      copyIndex2 = 0;
      ch = s_SLT_scratch7__scratch__kZERO__97c2f304[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex + copyIndex2) = ch;
        ch = "SLT scratch7, scratch, kZERO;\n"[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      outCursor2 = outCursor + copyIndex + copyIndex2;
      copyIndex = 0;
      ch = s_ABS_scratch__scratch__97c2e8c0[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "ABS scratch, scratch;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor2 = outCursor2 + copyIndex;
      copyIndex = 0;
      ch = s_SLT_scratch8__kONE__scratch__97c2f324[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "SLT scratch8, kONE, scratch;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor2 = outCursor2 + copyIndex;
      copyIndex = 0;
      ch = s_SGE_scratch1___scratch__kZERO__97c2f344[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "SGE scratch1, -scratch, kZERO;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor2 = outCursor2 + copyIndex;
      copyIndex = 0;
      ch = s_MAD_scratch__scratch1__kOFFSET__s_97c2f364[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "MAD scratch, scratch1, kOFFSET, scratch;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outPtr = (char *)(outCursor2 + copyIndex);
      loopIndex = 0;
      do {
        copyIndex3 = 0;
        ch = s_RCP_scratch1__97c2ea98[0];
        while (ch != '\0') {
          outPtr[copyIndex3] = ch;
          ch = "RCP scratch1."[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        loopIndex = loopIndex + 1;
        outPtr = outPtr + copyIndex3;
        *outPtr = ((byte)loopIndex & 3) + 0x77;
        copyIndex3 = 0;
        ch = s___scratch__97c2eaa8[0];
        while (ch != '\0') {
          outPtr[copyIndex3 + 1] = ch;
          ch = ", scratch."[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        outPtr = outPtr + copyIndex3 + 1;
        *outPtr = ((byte)loopIndex & 3) + 0x77;
        copyIndex3 = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          outPtr[copyIndex3 + 1] = ch;
          ch = ";\n"[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        outPtr = outPtr + copyIndex3 + 1;
      } while (loopIndex <= (int)(inst[4] >> 0xc & 3));
      copyIndex = 0;
      ch = s_SUB_scratch1__scratch1__scratch__97c2f390[0];
      while (ch != '\0') {
        outPtr[copyIndex] = ch;
        ch = "SUB scratch1, scratch1, scratch;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      copyIndex3 = 0;
      ch = s_MAD_scratch__scratch8__scratch1__97c2f3b4[0];
      while (ch != '\0') {
        outPtr[copyIndex3 + copyIndex] = ch;
        ch = "MAD scratch, scratch8, scratch1, scratch;\n"[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      copyIndex2 = 0;
      ch = s_MUL_scratch1__scratch__scratch__97c2ee04[0];
      while (ch != '\0') {
        outPtr[copyIndex2 + copyIndex3 + copyIndex] = ch;
        ch = "MUL scratch1, scratch, scratch;\n"[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      iVar5 = copyIndex2 + copyIndex3 + copyIndex;
      copyIndex = 0;
      ch = s_MUL_scratch2__scratch1__scratch__97c2ee28[0];
      while (ch != '\0') {
        outPtr[copyIndex + iVar5] = ch;
        ch = "MUL scratch2, scratch1, scratch;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      iVar11 = copyIndex + iVar5;
      copyIndex3 = 0;
      ch = s_MUL_scratch3__scratch1__scratch1_97c2ee4c[0];
      while (ch != '\0') {
        outPtr[copyIndex3 + iVar11] = ch;
        ch = "MUL scratch3, scratch1, scratch1;\n"[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      outPos = copyIndex3 + iVar11;
      copyIndex = 0;
      ch = s_MUL_scratch__kATAN_K1__scratch__97c2f3e0[0];
      while (ch != '\0') {
        outPtr[copyIndex + outPos] = ch;
        ch = "MUL scratch, kATAN_K1, scratch;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      iVar11 = copyIndex + outPos;
      copyIndex3 = 0;
      ch = s_MAD_scratch2__kATAN_K3__scratch2_97c2f404[0];
      while (ch != '\0') {
        outPtr[copyIndex3 + iVar11] = ch;
        ch = "MAD scratch2, kATAN_K3, scratch2, scratch;\n"[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      outPos = copyIndex3 + iVar11;
      copyIndex = 0;
      ch = s_MAD_scratch__kATAN_K2__scratch1__97c2f430[0];
      while (ch != '\0') {
        outPtr[copyIndex + outPos] = ch;
        ch = "MAD scratch, kATAN_K2, scratch1, kONE;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      iVar11 = copyIndex + outPos;
      copyIndex3 = 0;
      ch = s_MAD_scratch__kATAN_K4__scratch3__97c2f458[0];
      while (ch != '\0') {
        outPtr[copyIndex3 + iVar11] = ch;
        ch = "MAD scratch, kATAN_K4, scratch3, scratch;\n"[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      outPtr = outPtr + copyIndex3 + iVar11;
      loopIndex = 0;
      do {
        copyIndex3 = 0;
        ch = s_RCP_scratch__97c2e5f0[0];
        while (ch != '\0') {
          outPtr[copyIndex3] = ch;
          ch = "RCP scratch."[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        loopIndex = loopIndex + 1;
        outPtr = outPtr + copyIndex3;
        *outPtr = ((byte)loopIndex & 3) + 0x77;
        copyIndex3 = 0;
        ch = s___scratch__97c2eaa8[0];
        while (ch != '\0') {
          outPtr[copyIndex3 + 1] = ch;
          ch = ", scratch."[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        outPtr = outPtr + copyIndex3 + 1;
        *outPtr = ((byte)loopIndex & 3) + 0x77;
        copyIndex3 = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          outPtr[copyIndex3 + 1] = ch;
          ch = ";\n"[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        outPtr = outPtr + copyIndex3 + 1;
      } while (loopIndex <= (int)(inst[4] >> 0xc & 3));
      copyIndex = 0;
      ch = s_MUL_scratch1__scratch2__scratch__97c2f484[0];
      while (ch != '\0') {
        outPtr[copyIndex] = ch;
        ch = "MUL scratch1, scratch2, scratch;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      copyIndex3 = 0;
      ch = s_MAD_scratch__kTWO___scratch1__kH_97c2f4a8[0];
      while (ch != '\0') {
        outPtr[copyIndex3 + copyIndex] = ch;
        ch = "MAD scratch, kTWO, -scratch1, kHALFPI;\n"[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      copyIndex2 = 0;
      ch = s_MAD_scratch__scratch8__scratch__s_97c2f4d0[0];
      while (ch != '\0') {
        outPtr[copyIndex2 + copyIndex3 + copyIndex] = ch;
        ch = "MAD scratch, scratch8, scratch, scratch1;\n"[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      iVar5 = copyIndex2 + copyIndex3 + copyIndex;
      copyIndex = 0;
      ch = s_MAD_scratch2__scratch7___kTWO__k_97c2f4fc[0];
      while (ch != '\0') {
        outPtr[copyIndex + iVar5] = ch;
        ch = "MAD scratch2, scratch7, -kTWO, kONE;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      iVar11 = copyIndex + iVar5;
      copyIndex3 = 0;
      ch = s_MUL_scratch__scratch__scratch2__97c2f524[0];
      while (ch != '\0') {
        outPtr[copyIndex3 + iVar11] = ch;
        ch = "MUL scratch, scratch, scratch2;\n"[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      outPos = copyIndex3 + iVar11;
      copyIndex = 0;
      ch = s_ADD_scratch__scratch__scratch4__97c2f548[0];
      while (ch != '\0') {
        outPtr[copyIndex + outPos] = ch;
        ch = "ADD scratch, scratch, scratch4;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      iVar11 = copyIndex + outPos;
      copyIndex3 = 0;
      ch = s_SUB_scratch1__scratch6__scratch__97c2f56c[0];
      while (ch != '\0') {
        outPtr[copyIndex3 + iVar11] = ch;
        ch = "SUB scratch1, scratch6, scratch;\n"[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      outPos = copyIndex3 + iVar11;
      copyIndex = 0;
      ch = s_MAD_97c2e644[0];
      while (ch != '\0') {
        outPtr[copyIndex + outPos] = ch;
        ch = "MAD "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      iVar6 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outPtr + copyIndex + outPos,0,0,0);
      opOffsetOrTailLength = 0;
      ch = s___scratch5__scratch1__scratch__97c2f590[0];
      while (ch != '\0') {
        *(char *)(iVar6 + opOffsetOrTailLength) = ch;
        ch = ", scratch5, scratch1, scratch;\n"[opOffsetOrTailLength + 1];
        opOffsetOrTailLength = opOffsetOrTailLength + 1;
      }
    }
    else {
      copyIndex = 0;
      ch = s_SLT_scratch__97c2e474[0];
      while (ch != '\0') {
        *(char *)(outText + copyIndex) = ch;
        ch = "SLT scratch, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,param_5,param_6,2,0,0,8);
      copyIndex = 0;
      ch = s___kZERO__97c2e484[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", kZERO;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      copyIndex2 = 0;
      ch = s_ABS_scratch2__97c2f5b0[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex + copyIndex2) = ch;
        ch = "ABS scratch2, "[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex + copyIndex2,param_5,param_6,2,0,0,8);
      copyIndex = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ";\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      copyIndex2 = 0;
      ch = s_SLT_scratch6__kONE__scratch2__97c2efa8[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex + copyIndex2) = ch;
        ch = "SLT scratch6, kONE, scratch2;\n"[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      outPtr = (char *)(outCursor + copyIndex + copyIndex2);
      loopIndex = 0;
      do {
        copyIndex3 = 0;
        ch = s_RCP_scratch3__97c2efc8[0];
        while (ch != '\0') {
          outPtr[copyIndex3] = ch;
          ch = "RCP scratch3."[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        loopIndex = loopIndex + 1;
        outPtr = outPtr + copyIndex3;
        *outPtr = ((byte)loopIndex & 3) + 0x77;
        copyIndex3 = 0;
        ch = s___scratch2__97c2efd8[0];
        while (ch != '\0') {
          outPtr[copyIndex3 + 1] = ch;
          ch = ", scratch2."[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        outPtr = outPtr + copyIndex3 + 1;
        *outPtr = ((byte)loopIndex & 3) + 0x77;
        copyIndex3 = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          outPtr[copyIndex3 + 1] = ch;
          ch = ";\n"[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        outPtr = outPtr + copyIndex3 + 1;
      } while (loopIndex <= (int)(inst[4] >> 0xc & 3));
      copyIndex = 0;
      ch = s_SUB_scratch3__scratch3__scratch2_97c2efe4[0];
      while (ch != '\0') {
        outPtr[copyIndex] = ch;
        ch = "SUB scratch3, scratch3, scratch2;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      copyIndex3 = 0;
      ch = s_MAD_scratch2__scratch6__scratch3_97c2f008[0];
      while (ch != '\0') {
        outPtr[copyIndex3 + copyIndex] = ch;
        ch = "MAD scratch2, scratch6, scratch3, scratch2;\n"[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      copyIndex2 = 0;
      ch = s_MUL_scratch1__scratch2__scratch2_97c2f038[0];
      while (ch != '\0') {
        outPtr[copyIndex2 + copyIndex3 + copyIndex] = ch;
        ch = "MUL scratch1, scratch2, scratch2;\n"[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      iVar5 = copyIndex2 + copyIndex3 + copyIndex;
      copyIndex = 0;
      ch = s_MUL_scratch3__scratch1__scratch2_97c2f05c[0];
      while (ch != '\0') {
        outPtr[copyIndex + iVar5] = ch;
        ch = "MUL scratch3, scratch1, scratch2;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      iVar11 = copyIndex + iVar5;
      copyIndex3 = 0;
      ch = s_MUL_scratch4__scratch1__scratch1_97c2f080[0];
      while (ch != '\0') {
        outPtr[copyIndex3 + iVar11] = ch;
        ch = "MUL scratch4, scratch1, scratch1;\n"[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      outPos = copyIndex3 + iVar11;
      copyIndex = 0;
      ch = s_MUL_scratch2__kATAN_K1__scratch2_97c2f0a4[0];
      while (ch != '\0') {
        outPtr[copyIndex + outPos] = ch;
        ch = "MUL scratch2, kATAN_K1, scratch2;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      iVar11 = copyIndex + outPos;
      copyIndex3 = 0;
      ch = s_MAD_scratch2__kATAN_K3__scratch3_97c2f0c8[0];
      while (ch != '\0') {
        outPtr[copyIndex3 + iVar11] = ch;
        ch = "MAD scratch2, kATAN_K3, scratch3, scratch2;\n"[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      outPos = copyIndex3 + iVar11;
      copyIndex = 0;
      ch = s_MAD_scratch1__kATAN_K2__scratch1_97c2f0f8[0];
      while (ch != '\0') {
        outPtr[copyIndex + outPos] = ch;
        ch = "MAD scratch1, kATAN_K2, scratch1, kONE;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      iVar11 = copyIndex + outPos;
      copyIndex3 = 0;
      ch = s_MAD_scratch1__kATAN_K4__scratch4_97c2f124[0];
      while (ch != '\0') {
        outPtr[copyIndex3 + iVar11] = ch;
        ch = "MAD scratch1, kATAN_K4, scratch4, scratch1;\n"[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      outPtr = outPtr + copyIndex3 + iVar11;
      loopIndex = 0;
      do {
        copyIndex3 = 0;
        ch = s_RCP_scratch1__97c2ea98[0];
        while (ch != '\0') {
          outPtr[copyIndex3] = ch;
          ch = "RCP scratch1."[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        loopIndex = loopIndex + 1;
        outPtr = outPtr + copyIndex3;
        *outPtr = ((byte)loopIndex & 3) + 0x77;
        copyIndex3 = 0;
        ch = s___scratch1__97c2ef10[0];
        while (ch != '\0') {
          outPtr[copyIndex3 + 1] = ch;
          ch = ", scratch1."[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        outPtr = outPtr + copyIndex3 + 1;
        *outPtr = ((byte)loopIndex & 3) + 0x77;
        copyIndex3 = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          outPtr[copyIndex3 + 1] = ch;
          ch = ";\n"[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        outPtr = outPtr + copyIndex3 + 1;
      } while (loopIndex <= (int)(inst[4] >> 0xc & 3));
      copyIndex = 0;
      ch = s_MUL_scratch2__scratch2__scratch1_97c2f154[0];
      while (ch != '\0') {
        outPtr[copyIndex] = ch;
        ch = "MUL scratch2, scratch2, scratch1;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      copyIndex3 = 0;
      ch = s_MAD_scratch1__kTWO___scratch2__k_97c2f178[0];
      while (ch != '\0') {
        outPtr[copyIndex3 + copyIndex] = ch;
        ch = "MAD scratch1, kTWO, -scratch2, kHALFPI;\n"[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      copyIndex2 = 0;
      ch = s_MAD_scratch2__scratch6__scratch1_97c2f1a4[0];
      while (ch != '\0') {
        outPtr[copyIndex2 + copyIndex3 + copyIndex] = ch;
        ch = "MAD scratch2, scratch6, scratch1, scratch2;\n"[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      iVar5 = copyIndex2 + copyIndex3 + copyIndex;
      copyIndex = 0;
      ch = s_MAD_scratch__scratch___kTWO__kON_97c2f228[0];
      while (ch != '\0') {
        outPtr[copyIndex + iVar5] = ch;
        ch = "MAD scratch, scratch, -kTWO, kONE;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      iVar11 = copyIndex + iVar5;
      copyIndex3 = 0;
      ch = s_MUL_97c2e4f0[0];
      while (ch != '\0') {
        outPtr[copyIndex3 + iVar11] = ch;
        ch = "MUL "[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      iVar6 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outPtr + copyIndex3 + iVar11,0,0,0);
      opOffsetOrTailLength = 0;
      ch = s___scratch2__scratch__97c2f24c[0];
      while (ch != '\0') {
        *(char *)(iVar6 + opOffsetOrTailLength) = ch;
        ch = ", scratch2, scratch;\n"[opOffsetOrTailLength + 1];
        opOffsetOrTailLength = opOffsetOrTailLength + 1;
      }
    }
    break;
  case 0x1f:
  case 0x20:
    iVar5 = 1;
    if ((inst[2] & 0x1000) != 0) {
      iVar5 = (inst[2] >> 10 & 3) + 1;
    }
    loopIndex4 = 0;
    if (iVar5 == 0) goto LAB_97c0178c;
    do {
      copyIndex11 = 0;
      mnemonic = *(char **)(PTR__ppstreamOpString_a7b7c108 + opOffsetOrTailLength);
      ch = *mnemonic;
      while (ch != '\0') {
        *(char *)(iVar6 + copyIndex11) = ch;
        copyIndex11 = copyIndex11 + 1;
        ch = mnemonic[copyIndex11];
      }
      copyIndex6 = 0;
      ch = s__97c291c0[0];
      while (ch != '\0') {
        *(char *)(iVar6 + copyIndex11 + copyIndex6) = ch;
        ch = " "[copyIndex6 + 1];
        copyIndex6 = copyIndex6 + 1;
      }
      outCursor5 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,iVar6 + copyIndex11 + copyIndex6,loopIndex4,0,0);
      copyIndex3 = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor5 + copyIndex3) = ch;
        ch = ", "[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      iVar7 = loopIndex4;
      if ((inst[4] & 0x4000) == 0) {
        iVar7 = 0;
      }
      outCursor5 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor5 + copyIndex3,param_5,param_6,2,iVar7,0,8);
      copyIndex3 = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor5 + copyIndex3) = ch;
        ch = ", "[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      iVar7 = loopIndex4;
      if ((inst[6] & 0x4000) == 0) {
        iVar7 = 0;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor5 + copyIndex3,param_5,param_6,3,iVar7,0,8);
      copyIndex5 = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex5) = ch;
        ch = ";\n"[copyIndex5 + 1];
        copyIndex5 = copyIndex5 + 1;
      }
      loopIndex4 = loopIndex4 + 1;
      iVar6 = outCursor + copyIndex5;
    } while (loopIndex4 < iVar5);
    goto LAB_97c01788;
  case 0x21:
    *stateFlags = *stateFlags | 1;
    if ((inst[6] >> 0xc & 3) == 0) {
      copyIndex = 0;
      ch = s_RCP_scratch__97c2e600[0];
      while (ch != '\0') {
        *(char *)(outText + copyIndex) = ch;
        ch = "RCP scratch, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,param_5,param_6,3,0,0,0);
      copyIndex = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ";\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      iVar6 = outCursor + copyIndex;
    }
    else {
      iVar11 = 0;
      do {
        copyIndex2 = 0;
        ch = s_RCP_scratch__97c2e5f0[0];
        while (ch != '\0') {
          *(char *)(iVar6 + copyIndex2) = ch;
          ch = "RCP scratch."[copyIndex2 + 1];
          copyIndex2 = copyIndex2 + 1;
        }
        iVar13 = iVar11 + 1;
        outPtr = (char *)(iVar6 + copyIndex2);
        *outPtr = ((byte)iVar13 & 3) + 0x77;
        copyIndex3 = 0;
        ch = s___97c2d7ec[0];
        while (ch != '\0') {
          outPtr[copyIndex3 + 1] = ch;
          ch = ", "[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outPtr + copyIndex3 + 1,param_5,param_6,3,0,iVar11,10);
        copyIndex = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex) = ch;
          ch = ";\n"[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        iVar6 = outCursor + copyIndex;
        iVar11 = iVar13;
      } while (iVar13 <= (int)(inst[6] >> 0xc & 3));
    }
    copyIndex = 0;
    ch = s_MUL_scratch__scratch__97c2e9ec[0];
    while (ch != '\0') {
      *(char *)(iVar6 + copyIndex) = ch;
      ch = "MUL scratch, scratch, "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,iVar6 + copyIndex,param_5,param_6,2,0,0,8);
    copyIndex = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ";\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    copyIndex2 = 0;
    ch = s_FLR_scratch__scratch__97c2ea04[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex + copyIndex2) = ch;
      ch = "FLR scratch, scratch;\n"[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outCursor2 = outCursor + copyIndex + copyIndex2;
    copyIndex = 0;
    ch = s_MAD_97c2e644[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "MAD "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor2 + copyIndex,0,0,0);
    copyIndex = 0;
    ch = s___scratch__97c2e570[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", scratch, "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,3,0,0,9);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    iVar6 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,2,0,0,8);
    opOffsetOrTailLength = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(iVar6 + opOffsetOrTailLength) = ch;
      ch = ";\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 0x22:
  case 0x4e:
    bVar1 = false;
    if ((*(short *)((int)inst + 0xe) == *(short *)((int)inst + 0x16)) ||
       (*(short *)((int)inst + 0xe) == *(short *)((int)inst + 0x1e))) {
      bVar1 = true;
    }
    uVar8 = inst[4];
    if (((uVar8 & 0x4000) == 0) || ((inst[6] & 0x4000) == 0)) {
      if (((uVar8 & 0x4000) == 0) && ((inst[6] & 0x4000) == 0)) {
        copyIndex = 0;
        ch = s_MUL_97c2e4f0[0];
        while (ch != '\0') {
          *(char *)(outText + copyIndex) = ch;
          ch = "MUL "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outText + copyIndex,0,0,0);
        copyIndex = 0;
        ch = s___97c2d7ec[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex) = ch;
          ch = ", "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,2,0,0,8);
        copyIndex = 0;
        ch = s___97c2d7ec[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex) = ch;
          ch = ", "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        iVar6 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,3,0,0,8);
        opOffsetOrTailLength = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          *(char *)(iVar6 + opOffsetOrTailLength) = ch;
          ch = ";\n"[opOffsetOrTailLength + 1];
          opOffsetOrTailLength = opOffsetOrTailLength + 1;
        }
        break;
      }
      if (((uVar8 & 0x3000) == 0) || (uVar9 = inst[6] >> 0xc & 3, uVar9 == 0)) {
        loopIndex = 0;
        do {
          copyIndex2 = 0;
          ch = s_MUL_97c2e4f0[0];
          while (ch != '\0') {
            *(char *)(iVar6 + copyIndex2) = ch;
            ch = "MUL "[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
          outCursor2 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,iVar6 + copyIndex2,loopIndex,0,0);
          copyIndex3 = 0;
          ch = s___97c2d7ec[0];
          while (ch != '\0') {
            *(char *)(outCursor2 + copyIndex3) = ch;
            ch = ", "[copyIndex3 + 1];
            copyIndex3 = copyIndex3 + 1;
          }
          iVar13 = loopIndex;
          if ((inst[4] & 0x4000) == 0) {
            iVar13 = 0;
          }
          outCursor2 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex3,param_5,param_6,2,iVar13,0,0);
          copyIndex3 = 0;
          ch = s___97c2d7ec[0];
          while (ch != '\0') {
            *(char *)(outCursor2 + copyIndex3) = ch;
            ch = ", "[copyIndex3 + 1];
            copyIndex3 = copyIndex3 + 1;
          }
          iVar13 = loopIndex;
          if ((inst[6] & 0x4000) == 0) {
            iVar13 = 0;
          }
          outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex3,param_5,param_6,3,iVar13,0,0);
          copyIndex2 = 0;
          ch = s___97c2d8f8[0];
          while (ch != '\0') {
            *(char *)(outCursor + copyIndex2) = ch;
            ch = ";\n"[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
          loopIndex = loopIndex + 1;
          iVar6 = outCursor + copyIndex2;
        } while (loopIndex <= (int)(inst[2] >> 10 & 3));
      }
      else if ((uVar8 & 0x4000) == 0) {
        if (bVar1) {
          if ((uVar9 != 1) || (((stateFlags[1] & 0x800000) != 0 && (shaderType == 0x8b30)))) {
            *stateFlags = *stateFlags | 1;
            uVar8 = inst[2];
            uVar10 = uVar8 >> 0xd & 0xf;
            loopIndex2 = 0;
            iVar11 = outText;
            do {
              if ((uVar10 & 1) != 0) {
                if (uVar9 != 1) {
                  if (uVar9 == 2) {
                    copyIndex2 = 0;
                    ch = s_DP3_scratch_97c2e6bc[0];
                    while (ch != '\0') {
                      *(char *)(iVar11 + copyIndex2) = ch;
                      ch = "DP3 scratch"[copyIndex2 + 1];
                      copyIndex2 = copyIndex2 + 1;
                    }
                  }
                  else {
                    copyIndex2 = 0;
                    ch = s_DP4_scratch_97c2e6c8[0];
                    while (ch != '\0') {
                      *(char *)(iVar11 + copyIndex2) = ch;
                      ch = "DP4 scratch"[copyIndex2 + 1];
                      copyIndex2 = copyIndex2 + 1;
                    }
                  }
                }
                else {
                  *stateFlags = *stateFlags | 0x800000;
                  copyIndex2 = 0;
                  ch = s___NV_fragment_program2_DP2_97c2e694[0];
                  while (ch != '\0') {
                    *(char *)(iVar11 + copyIndex2) = ch;
                    ch = "# NV_fragment_program2:DP2\n"[copyIndex2 + 1];
                    copyIndex2 = copyIndex2 + 1;
                  }
                  iVar11 = iVar11 + copyIndex2;
                  copyIndex2 = 0;
                  ch = s_DP2_scratch_97c2e6b0[0];
                  while (ch != '\0') {
                    *(char *)(iVar11 + copyIndex2) = ch;
                    ch = "DP2 scratch"[copyIndex2 + 1];
                    copyIndex2 = copyIndex2 + 1;
                  }
                }
                outCursor2 = ((int (*)())_glpWriteDestinationMask)(inst,iVar11 + copyIndex2,loopIndex2,2);
                copyIndex = 0;
                ch = s___97c2d7ec[0];
                while (ch != '\0') {
                  *(char *)(outCursor2 + copyIndex) = ch;
                  ch = ", "[copyIndex + 1];
                  copyIndex = copyIndex + 1;
                }
                outCursor2 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex,param_5,param_6,2,0,0,0);
                copyIndex = 0;
                ch = s___97c2d7ec[0];
                while (ch != '\0') {
                  *(char *)(outCursor2 + copyIndex) = ch;
                  ch = ", "[copyIndex + 1];
                  copyIndex = copyIndex + 1;
                }
                outCursor3 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex,param_5,param_6,3,loopIndex2,0,0x10);
                copyIndex2 = 0;
                ch = s___97c2d8f8[0];
                while (ch != '\0') {
                  *(char *)(outCursor3 + copyIndex2) = ch;
                  ch = ";\n"[copyIndex2 + 1];
                  copyIndex2 = copyIndex2 + 1;
                }
                uVar8 = inst[2];
                iVar11 = outCursor3 + copyIndex2;
              }
              loopIndex2 = loopIndex2 + 1;
              uVar10 = (int)uVar10 >> 1;
            } while (loopIndex2 <= (int)(uVar8 >> 10 & 3));
            copyIndex3 = 0;
            ch = s_MOV_97c2e430[0];
            while (ch != '\0') {
              *(char *)(iVar11 + copyIndex3) = ch;
              ch = "MOV "[copyIndex3 + 1];
              copyIndex3 = copyIndex3 + 1;
            }
            iVar6 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,iVar11 + copyIndex3,0,0,0);
            opOffsetOrTailLength = 0;
            ch = s___scratch__97c2e620[0];
            while (ch != '\0') {
              *(char *)(iVar6 + opOffsetOrTailLength) = ch;
              ch = ", scratch;\n"[opOffsetOrTailLength + 1];
              opOffsetOrTailLength = opOffsetOrTailLength + 1;
            }
          }
          else {
            *stateFlags = *stateFlags | 3;
            uVar8 = inst[2];
            uVar9 = uVar8 >> 0xd & 0xf;
            loopIndex2 = 0;
            iVar11 = outText;
            do {
              if ((uVar9 & 1) != 0) {
                copyIndex2 = 0;
                ch = s_MUL_scratch__97c2e62c[0];
                while (ch != '\0') {
                  *(char *)(iVar11 + copyIndex2) = ch;
                  ch = "MUL scratch, "[copyIndex2 + 1];
                  copyIndex2 = copyIndex2 + 1;
                }
                outCursor2 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,iVar11 + copyIndex2,param_5,param_6,2,0,0,0);
                copyIndex = 0;
                ch = s___97c2d7ec[0];
                while (ch != '\0') {
                  *(char *)(outCursor2 + copyIndex) = ch;
                  ch = ", "[copyIndex + 1];
                  copyIndex = copyIndex + 1;
                }
                outCursor2 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex,param_5,param_6,3,loopIndex2,0,0x10);
                copyIndex = 0;
                ch = s___97c2d8f8[0];
                while (ch != '\0') {
                  *(char *)(outCursor2 + copyIndex) = ch;
                  ch = ";\n"[copyIndex + 1];
                  copyIndex = copyIndex + 1;
                }
                copyIndex4 = 0;
                ch = s_ADD_scratch1_97c2e674[0];
                while (ch != '\0') {
                  *(char *)(outCursor2 + copyIndex + copyIndex4) = ch;
                  ch = "ADD scratch1"[copyIndex4 + 1];
                  copyIndex4 = copyIndex4 + 1;
                }
                outCursor3 = ((int (*)())_glpWriteDestinationMask)(inst,outCursor2 + copyIndex + copyIndex4,loopIndex2,2);
                copyIndex2 = 0;
                ch = s___scratch_x__scratch_y__97c2e524[0];
                while (ch != '\0') {
                  *(char *)(outCursor3 + copyIndex2) = ch;
                  ch = ", scratch.x, scratch.y;\n"[copyIndex2 + 1];
                  copyIndex2 = copyIndex2 + 1;
                }
                uVar8 = inst[2];
                iVar11 = outCursor3 + copyIndex2;
              }
              loopIndex2 = loopIndex2 + 1;
              uVar9 = (int)uVar9 >> 1;
            } while (loopIndex2 <= (int)(uVar8 >> 10 & 3));
            copyIndex3 = 0;
            ch = s_MOV_97c2e430[0];
            while (ch != '\0') {
              *(char *)(iVar11 + copyIndex3) = ch;
              ch = "MOV "[copyIndex3 + 1];
              copyIndex3 = copyIndex3 + 1;
            }
            iVar6 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,iVar11 + copyIndex3,0,0,0);
            opOffsetOrTailLength = 0;
            ch = s___scratch1__97c2e684[0];
            while (ch != '\0') {
              *(char *)(iVar6 + opOffsetOrTailLength) = ch;
              ch = ", scratch1;\n"[opOffsetOrTailLength + 1];
              opOffsetOrTailLength = opOffsetOrTailLength + 1;
            }
          }
          break;
        }
        if ((uVar9 != 1) || (((stateFlags[1] & 0x800000) != 0 && (shaderType == 0x8b30)))) {
          uVar8 = inst[2];
          uVar10 = uVar8 >> 0xd & 0xf;
          loopIndex = 0;
          do {
            if ((uVar10 & 1) != 0) {
              if (uVar9 != 1) {
                if (uVar9 == 2) {
                  copyIndex2 = 0;
                  ch = s_DP3_97c2e548[0];
                  while (ch != '\0') {
                    *(char *)(iVar6 + copyIndex2) = ch;
                    ch = "DP3 "[copyIndex2 + 1];
                    copyIndex2 = copyIndex2 + 1;
                  }
                }
                else {
                  copyIndex2 = 0;
                  ch = s_DP4_97c2e550[0];
                  while (ch != '\0') {
                    *(char *)(iVar6 + copyIndex2) = ch;
                    ch = "DP4 "[copyIndex2 + 1];
                    copyIndex2 = copyIndex2 + 1;
                  }
                }
              }
              else {
                *stateFlags = *stateFlags | 0x800000;
                copyIndex2 = 0;
                ch = s___NV_fragment_program2_DP2_97c2e694[0];
                while (ch != '\0') {
                  *(char *)(iVar6 + copyIndex2) = ch;
                  ch = "# NV_fragment_program2:DP2\n"[copyIndex2 + 1];
                  copyIndex2 = copyIndex2 + 1;
                }
                iVar6 = iVar6 + copyIndex2;
                copyIndex2 = 0;
                ch = s_DP2_97c2e540[0];
                while (ch != '\0') {
                  *(char *)(iVar6 + copyIndex2) = ch;
                  ch = "DP2 "[copyIndex2 + 1];
                  copyIndex2 = copyIndex2 + 1;
                }
              }
              outCursor2 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,iVar6 + copyIndex2,0,loopIndex,2);
              copyIndex3 = 0;
              ch = s___97c2d7ec[0];
              while (ch != '\0') {
                *(char *)(outCursor2 + copyIndex3) = ch;
                ch = ", "[copyIndex3 + 1];
                copyIndex3 = copyIndex3 + 1;
              }
              outCursor7 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex3,param_5,param_6,2,0,0,0)
              ;
              copyIndex3 = 0;
              ch = s___97c2d7ec[0];
              while (ch != '\0') {
                *(char *)(outCursor7 + copyIndex3) = ch;
                ch = ", "[copyIndex3 + 1];
                copyIndex3 = copyIndex3 + 1;
              }
              outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor7 + copyIndex3,param_5,param_6,3,loopIndex,0,0x10);
              copyIndex2 = 0;
              ch = s___97c2d8f8[0];
              while (ch != '\0') {
                *(char *)(outCursor + copyIndex2) = ch;
                ch = ";\n"[copyIndex2 + 1];
                copyIndex2 = copyIndex2 + 1;
              }
              uVar8 = inst[2];
              iVar6 = outCursor + copyIndex2;
            }
            loopIndex = loopIndex + 1;
            uVar10 = (int)uVar10 >> 1;
          } while (loopIndex <= (int)(uVar8 >> 10 & 3));
        }
        else {
          *stateFlags = *stateFlags | 1;
          uVar8 = inst[2];
          uVar9 = uVar8 >> 0xd & 0xf;
          loopIndex = 0;
          do {
            if ((uVar9 & 1) != 0) {
              copyIndex2 = 0;
              ch = s_MUL_scratch__97c2e62c[0];
              while (ch != '\0') {
                *(char *)(iVar6 + copyIndex2) = ch;
                ch = "MUL scratch, "[copyIndex2 + 1];
                copyIndex2 = copyIndex2 + 1;
              }
              outCursor7 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,iVar6 + copyIndex2,param_5,param_6,2,0,0,0)
              ;
              copyIndex3 = 0;
              ch = s___97c2d7ec[0];
              while (ch != '\0') {
                *(char *)(outCursor7 + copyIndex3) = ch;
                ch = ", "[copyIndex3 + 1];
                copyIndex3 = copyIndex3 + 1;
              }
              outCursor2 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor7 + copyIndex3,param_5,param_6,3,loopIndex,0,0x10);
              copyIndex3 = 0;
              ch = s___97c2d8f8[0];
              while (ch != '\0') {
                *(char *)(outCursor2 + copyIndex3) = ch;
                ch = ";\n"[copyIndex3 + 1];
                copyIndex3 = copyIndex3 + 1;
              }
              copyIndex4 = 0;
              ch = s_ADD_97c2e6d4[0];
              while (ch != '\0') {
                *(char *)(outCursor2 + copyIndex3 + copyIndex4) = ch;
                ch = "ADD "[copyIndex4 + 1];
                copyIndex4 = copyIndex4 + 1;
              }
              outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor2 + copyIndex3 + copyIndex4,0,loopIndex,2);
              copyIndex2 = 0;
              ch = s___scratch_x__scratch_y__97c2e524[0];
              while (ch != '\0') {
                *(char *)(outCursor + copyIndex2) = ch;
                ch = ", scratch.x, scratch.y;\n"[copyIndex2 + 1];
                copyIndex2 = copyIndex2 + 1;
              }
              uVar8 = inst[2];
              iVar6 = outCursor + copyIndex2;
            }
            loopIndex = loopIndex + 1;
            uVar9 = (int)uVar9 >> 1;
          } while (loopIndex <= (int)(uVar8 >> 10 & 3));
        }
      }
      else {
        *stateFlags = *stateFlags | 1;
        uVar8 = inst[4];
        uVar9 = 0;
        do {
          if (uVar9 == 0) {
            iVar5 = 0;
            iVar11 = iVar5;
            ch = s_MUL_97c2e4f0[0];
            if (s_MUL_97c2e4f0[0] != '\0') {
              do {
                *(char *)(iVar6 + iVar11) = ch;
                iVar5 = iVar11 + 1;
                ch = "MUL "[iVar11 + 1];
                iVar11 = iVar5;
              } while (ch != '\0');
              goto LAB_97bf6dac;
            }
          }
          else {
            iVar5 = 0;
            iVar11 = iVar5;
            ch = s_MAD_97c2e644[0];
            if (s_MAD_97c2e644[0] != '\0') {
              do {
                *(char *)(iVar6 + iVar11) = ch;
                iVar5 = iVar11 + 1;
                ch = "MAD "[iVar11 + 1];
                iVar11 = iVar5;
              } while (ch != '\0');
LAB_97bf6dac:
              uVar8 = inst[4];
            }
          }
          outCursor = iVar6 + iVar5;
          if (uVar9 == (uVar8 >> 0xc & 3)) {
            outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor,0,0,0);
            copyIndex = 0;
            ch = s___97c2d7ec[0];
            while (ch != '\0') {
              *(char *)(outCursor + copyIndex) = ch;
              ch = ", "[copyIndex + 1];
              copyIndex = copyIndex + 1;
            }
          }
          else {
            copyIndex = 0;
            ch = s_scratch__97c2e668[0];
            while (ch != '\0') {
              *(char *)(outCursor + copyIndex) = ch;
              ch = "scratch, "[copyIndex + 1];
              copyIndex = copyIndex + 1;
            }
          }
          outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,2,uVar9,0,8);
          copyIndex = 0;
          ch = s___97c2d7ec[0];
          while (ch != '\0') {
            *(char *)(outCursor + copyIndex) = ch;
            ch = ", "[copyIndex + 1];
            copyIndex = copyIndex + 1;
          }
          outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,3,0,uVar9,2);
          if (uVar9 == 0) {
            copyIndex = 0;
            ch = s___97c2d8f8[0];
            while (ch != '\0') {
              *(char *)(outCursor + copyIndex) = ch;
              ch = ";\n"[copyIndex + 1];
              copyIndex = copyIndex + 1;
            }
          }
          else {
            copyIndex = 0;
            ch = s___scratch__97c2e620[0];
            while (ch != '\0') {
              *(char *)(outCursor + copyIndex) = ch;
              ch = ", scratch;\n"[copyIndex + 1];
              copyIndex = copyIndex + 1;
            }
          }
          uVar8 = inst[4];
          iVar6 = outCursor + copyIndex;
          uVar9 = uVar9 + 1;
        } while ((int)uVar9 <= (int)(uVar8 >> 0xc & 3));
      }
    }
    else {
      *stateFlags = *stateFlags | 1;
      uVar8 = inst[2] >> 10 & 3;
      if (uVar8 == 1) {
        iVar11 = 0;
        do {
          copyIndex2 = 0;
          ch = s_MUL_scratch__97c2e62c[0];
          while (ch != '\0') {
            *(char *)(iVar6 + copyIndex2) = ch;
            ch = "MUL scratch, "[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
          outCursor2 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,iVar6 + copyIndex2,param_5,param_6,2,0,0,0);
          copyIndex3 = 0;
          ch = s___97c2d7ec[0];
          while (ch != '\0') {
            *(char *)(outCursor2 + copyIndex3) = ch;
            ch = ", "[copyIndex3 + 1];
            copyIndex3 = copyIndex3 + 1;
          }
          outCursor2 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex3,param_5,param_6,3,0,iVar11,2);
          copyIndex3 = 0;
          ch = s___97c2d8f8[0];
          while (ch != '\0') {
            *(char *)(outCursor2 + copyIndex3) = ch;
            ch = ";\n"[copyIndex3 + 1];
            copyIndex3 = copyIndex3 + 1;
          }
          copyIndex4 = 0;
          ch = s_MAD_97c2e644[0];
          while (ch != '\0') {
            *(char *)(outCursor2 + copyIndex3 + copyIndex4) = ch;
            ch = "MAD "[copyIndex4 + 1];
            copyIndex4 = copyIndex4 + 1;
          }
          outCursor4 = outCursor2 + copyIndex3 + copyIndex4;
          if (!bVar1) {
            outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor4,iVar11,0,0);
          }
          else {
            copyIndex2 = 0;
            ch = s_scratch_97c2e63c[0];
            while (ch != '\0') {
              *(char *)(outCursor4 + copyIndex2) = ch;
              ch = "scratch"[copyIndex2 + 1];
              copyIndex2 = copyIndex2 + 1;
            }
            copyEnd = ((int (*)())_ncpy_97bf2850)(outCursor4 + copyIndex2,iVar11 + 1);
            outCursor = outCursor4 + copyIndex2 + copyEnd;
          }
          iVar13 = iVar11 + 1;
          copyIndex2 = 0;
          ch = s___97c2d7ec[0];
          while (ch != '\0') {
            *(char *)(outCursor + copyIndex2) = ch;
            ch = ", "[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
          outCursor2 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex2,param_5,param_6,2,1,0,0);
          copyIndex3 = 0;
          ch = s___97c2d7ec[0];
          while (ch != '\0') {
            *(char *)(outCursor2 + copyIndex3) = ch;
            ch = ", "[copyIndex3 + 1];
            copyIndex3 = copyIndex3 + 1;
          }
          outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex3,param_5,param_6,3,1,iVar11,2);
          copyIndex = 0;
          ch = s___scratch__97c2e620[0];
          while (ch != '\0') {
            *(char *)(outCursor + copyIndex) = ch;
            ch = ", scratch;\n"[copyIndex + 1];
            copyIndex = copyIndex + 1;
          }
          iVar6 = outCursor + copyIndex;
          iVar11 = iVar13;
        } while (iVar13 <= (int)(inst[2] >> 10 & 3));
        if (bVar1) {
          uVar8 = *stateFlags | 6;
LAB_97bf68e0:
          *stateFlags = uVar8;
LAB_97bf68e4:
          if (bVar1) {
            loopIndex = 0;
            do {
              copyIndex2 = 0;
              ch = s_MOV_97c2e430[0];
              while (ch != '\0') {
                *(char *)(iVar6 + copyIndex2) = ch;
                ch = "MOV "[copyIndex2 + 1];
                copyIndex2 = copyIndex2 + 1;
              }
              outCursor4 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,iVar6 + copyIndex2,loopIndex,0,0);
              copyIndex2 = 0;
              ch = s___scratch_97c2e65c[0];
              while (ch != '\0') {
                *(char *)(outCursor4 + copyIndex2) = ch;
                ch = ", scratch"[copyIndex2 + 1];
                copyIndex2 = copyIndex2 + 1;
              }
              loopIndex = loopIndex + 1;
              copyEnd = ((int (*)())_ncpy_97bf2850)(outCursor4 + copyIndex2,loopIndex);
              outCursor = outCursor4 + copyIndex2 + copyEnd;
              copyIndex2 = 0;
              ch = s___97c2d8f8[0];
              while (ch != '\0') {
                *(char *)(outCursor + copyIndex2) = ch;
                ch = ";\n"[copyIndex2 + 1];
                copyIndex2 = copyIndex2 + 1;
              }
              iVar6 = outCursor + copyIndex2;
            } while (loopIndex <= (int)(inst[2] >> 10 & 3));
          }
        }
      }
      else if (uVar8 == 2) {
        iVar11 = 0;
        do {
          copyIndex2 = 0;
          ch = s_MUL_scratch__97c2e62c[0];
          while (ch != '\0') {
            *(char *)(iVar6 + copyIndex2) = ch;
            ch = "MUL scratch, "[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
          outCursor2 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,iVar6 + copyIndex2,param_5,param_6,2,0,0,0);
          copyIndex3 = 0;
          ch = s___97c2d7ec[0];
          while (ch != '\0') {
            *(char *)(outCursor2 + copyIndex3) = ch;
            ch = ", "[copyIndex3 + 1];
            copyIndex3 = copyIndex3 + 1;
          }
          outCursor2 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex3,param_5,param_6,3,0,iVar11,2);
          copyIndex3 = 0;
          ch = s___97c2d8f8[0];
          while (ch != '\0') {
            *(char *)(outCursor2 + copyIndex3) = ch;
            ch = ";\n"[copyIndex3 + 1];
            copyIndex3 = copyIndex3 + 1;
          }
          copyIndex4 = 0;
          ch = s_MAD_scratch__97c2e64c[0];
          while (ch != '\0') {
            *(char *)(outCursor2 + copyIndex3 + copyIndex4) = ch;
            ch = "MAD scratch, "[copyIndex4 + 1];
            copyIndex4 = copyIndex4 + 1;
          }
          outCursor2 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex3 + copyIndex4,param_5,param_6,2,1,0,0);
          copyIndex3 = 0;
          ch = s___97c2d7ec[0];
          while (ch != '\0') {
            *(char *)(outCursor2 + copyIndex3) = ch;
            ch = ", "[copyIndex3 + 1];
            copyIndex3 = copyIndex3 + 1;
          }
          outCursor2 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex3,param_5,param_6,3,1,iVar11,2);
          copyIndex3 = 0;
          ch = s___scratch__97c2e620[0];
          while (ch != '\0') {
            *(char *)(outCursor2 + copyIndex3) = ch;
            ch = ", scratch;\n"[copyIndex3 + 1];
            copyIndex3 = copyIndex3 + 1;
          }
          copyIndex4 = 0;
          ch = s_MAD_97c2e644[0];
          while (ch != '\0') {
            *(char *)(outCursor2 + copyIndex3 + copyIndex4) = ch;
            ch = "MAD "[copyIndex4 + 1];
            copyIndex4 = copyIndex4 + 1;
          }
          outCursor4 = outCursor2 + copyIndex3 + copyIndex4;
          if (!bVar1) {
            outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor4,iVar11,0,0);
          }
          else {
            copyIndex2 = 0;
            ch = s_scratch_97c2e63c[0];
            while (ch != '\0') {
              *(char *)(outCursor4 + copyIndex2) = ch;
              ch = "scratch"[copyIndex2 + 1];
              copyIndex2 = copyIndex2 + 1;
            }
            copyEnd = ((int (*)())_ncpy_97bf2850)(outCursor4 + copyIndex2,iVar11 + 1);
            outCursor = outCursor4 + copyIndex2 + copyEnd;
          }
          iVar13 = iVar11 + 1;
          copyIndex2 = 0;
          ch = s___97c2d7ec[0];
          while (ch != '\0') {
            *(char *)(outCursor + copyIndex2) = ch;
            ch = ", "[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
          outCursor2 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex2,param_5,param_6,2,2,0,0);
          copyIndex3 = 0;
          ch = s___97c2d7ec[0];
          while (ch != '\0') {
            *(char *)(outCursor2 + copyIndex3) = ch;
            ch = ", "[copyIndex3 + 1];
            copyIndex3 = copyIndex3 + 1;
          }
          outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex3,param_5,param_6,3,2,iVar11,2);
          copyIndex = 0;
          ch = s___scratch__97c2e620[0];
          while (ch != '\0') {
            *(char *)(outCursor + copyIndex) = ch;
            ch = ", scratch;\n"[copyIndex + 1];
            copyIndex = copyIndex + 1;
          }
          iVar6 = outCursor + copyIndex;
          iVar11 = iVar13;
        } while (iVar13 <= (int)(inst[2] >> 10 & 3));
        if (bVar1) {
          uVar8 = *stateFlags | 0xe;
          goto LAB_97bf68e0;
        }
      }
      else {
        if (uVar8 != 3) goto LAB_97bf68e4;
        iVar11 = 0;
        do {
          copyIndex2 = 0;
          ch = s_MUL_scratch__97c2e62c[0];
          while (ch != '\0') {
            *(char *)(iVar6 + copyIndex2) = ch;
            ch = "MUL scratch, "[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
          outCursor2 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,iVar6 + copyIndex2,param_5,param_6,2,0,0,0);
          copyIndex3 = 0;
          ch = s___97c2d7ec[0];
          while (ch != '\0') {
            *(char *)(outCursor2 + copyIndex3) = ch;
            ch = ", "[copyIndex3 + 1];
            copyIndex3 = copyIndex3 + 1;
          }
          outCursor2 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex3,param_5,param_6,3,0,iVar11,2);
          copyIndex3 = 0;
          ch = s___97c2d8f8[0];
          while (ch != '\0') {
            *(char *)(outCursor2 + copyIndex3) = ch;
            ch = ";\n"[copyIndex3 + 1];
            copyIndex3 = copyIndex3 + 1;
          }
          copyIndex4 = 0;
          ch = s_MAD_scratch__97c2e64c[0];
          while (ch != '\0') {
            *(char *)(outCursor2 + copyIndex3 + copyIndex4) = ch;
            ch = "MAD scratch, "[copyIndex4 + 1];
            copyIndex4 = copyIndex4 + 1;
          }
          outCursor2 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex3 + copyIndex4,param_5,param_6,2,1,0,0);
          copyIndex3 = 0;
          ch = s___97c2d7ec[0];
          while (ch != '\0') {
            *(char *)(outCursor2 + copyIndex3) = ch;
            ch = ", "[copyIndex3 + 1];
            copyIndex3 = copyIndex3 + 1;
          }
          outCursor2 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex3,param_5,param_6,3,1,iVar11,2);
          copyIndex3 = 0;
          ch = s___scratch__97c2e620[0];
          while (ch != '\0') {
            *(char *)(outCursor2 + copyIndex3) = ch;
            ch = ", scratch;\n"[copyIndex3 + 1];
            copyIndex3 = copyIndex3 + 1;
          }
          copyIndex4 = 0;
          ch = s_MAD_scratch__97c2e64c[0];
          while (ch != '\0') {
            *(char *)(outCursor2 + copyIndex3 + copyIndex4) = ch;
            ch = "MAD scratch, "[copyIndex4 + 1];
            copyIndex4 = copyIndex4 + 1;
          }
          outCursor2 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex3 + copyIndex4,param_5,param_6,2,2,0,0);
          copyIndex3 = 0;
          ch = s___97c2d7ec[0];
          while (ch != '\0') {
            *(char *)(outCursor2 + copyIndex3) = ch;
            ch = ", "[copyIndex3 + 1];
            copyIndex3 = copyIndex3 + 1;
          }
          outCursor2 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex3,param_5,param_6,3,2,iVar11,2);
          copyIndex3 = 0;
          ch = s___scratch__97c2e620[0];
          while (ch != '\0') {
            *(char *)(outCursor2 + copyIndex3) = ch;
            ch = ", scratch;\n"[copyIndex3 + 1];
            copyIndex3 = copyIndex3 + 1;
          }
          copyIndex4 = 0;
          ch = s_MAD_97c2e644[0];
          while (ch != '\0') {
            *(char *)(outCursor2 + copyIndex3 + copyIndex4) = ch;
            ch = "MAD "[copyIndex4 + 1];
            copyIndex4 = copyIndex4 + 1;
          }
          outCursor4 = outCursor2 + copyIndex3 + copyIndex4;
          if (!bVar1) {
            outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor4,iVar11,0,0);
          }
          else {
            copyIndex2 = 0;
            ch = s_scratch_97c2e63c[0];
            while (ch != '\0') {
              *(char *)(outCursor4 + copyIndex2) = ch;
              ch = "scratch"[copyIndex2 + 1];
              copyIndex2 = copyIndex2 + 1;
            }
            copyEnd = ((int (*)())_ncpy_97bf2850)(outCursor4 + copyIndex2,iVar11 + 1);
            outCursor = outCursor4 + copyIndex2 + copyEnd;
          }
          iVar13 = iVar11 + 1;
          copyIndex2 = 0;
          ch = s___97c2d7ec[0];
          while (ch != '\0') {
            *(char *)(outCursor + copyIndex2) = ch;
            ch = ", "[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
          outCursor2 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex2,param_5,param_6,2,3,0,0);
          copyIndex3 = 0;
          ch = s___97c2d7ec[0];
          while (ch != '\0') {
            *(char *)(outCursor2 + copyIndex3) = ch;
            ch = ", "[copyIndex3 + 1];
            copyIndex3 = copyIndex3 + 1;
          }
          outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex3,param_5,param_6,3,3,iVar11,2);
          copyIndex = 0;
          ch = s___scratch__97c2e620[0];
          while (ch != '\0') {
            *(char *)(outCursor + copyIndex) = ch;
            ch = ", scratch;\n"[copyIndex + 1];
            copyIndex = copyIndex + 1;
          }
          iVar6 = outCursor + copyIndex;
          iVar11 = iVar13;
        } while (iVar13 <= (int)(inst[2] >> 10 & 3));
        if (bVar1) {
          uVar8 = *stateFlags | 0x1e;
          goto LAB_97bf68e0;
        }
      }
    }
    goto LAB_97c01788;
  case 0x23:
    bVar1 = false;
    if ((*(short *)((int)inst + 0xe) == *(short *)((int)inst + 0x16)) ||
       (*(short *)((int)inst + 0xe) == *(short *)((int)inst + 0x1e))) {
      bVar1 = true;
    }
    loopIndex = 0;
    do {
      copyIndex2 = 0;
      ch = s_MUL_97c2e4f0[0];
      while (ch != '\0') {
        *(char *)(iVar6 + copyIndex2) = ch;
        ch = "MUL "[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      outCursor = iVar6 + copyIndex2;
      if (!bVar1) {
        outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor,loopIndex,0,0);
      }
      else {
        copyIndex2 = 0;
        ch = s_scratch_97c2e63c[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex2) = ch;
          ch = "scratch"[copyIndex2 + 1];
          copyIndex2 = copyIndex2 + 1;
        }
        outCursor = outCursor + copyIndex2;
        if (loopIndex != 0) {
          copyEnd2 = ((int (*)())_ncpy_97bf2850)(outCursor,loopIndex);
          outCursor = outCursor + copyEnd2;
        }
      }
      copyIndex2 = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex2) = ch;
        ch = ", "[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      outCursor2 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex2,param_5,param_6,2,loopIndex,0,0);
      copyIndex3 = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex3) = ch;
        ch = ", "[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex3,param_5,param_6,3,loopIndex,0,0);
      copyIndex2 = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex2) = ch;
        ch = ";\n"[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      loopIndex = loopIndex + 1;
      iVar6 = outCursor + copyIndex2;
      uVar8 = inst[2] >> 10 & 3;
    } while (loopIndex <= (int)uVar8);
    if (bVar1) {
      if (uVar8 == 1) {
        uVar8 = *stateFlags | 3;
LAB_97bf7aec:
        *stateFlags = uVar8;
      }
      else {
        if (uVar8 == 2) {
          uVar8 = *stateFlags | 7;
          goto LAB_97bf7aec;
        }
        if (uVar8 == 3) {
          uVar8 = *stateFlags | 0xf;
          goto LAB_97bf7aec;
        }
      }
      loopIndex = 0;
      do {
        copyIndex2 = 0;
        ch = s_MOV_97c2e430[0];
        while (ch != '\0') {
          *(char *)(iVar6 + copyIndex2) = ch;
          ch = "MOV "[copyIndex2 + 1];
          copyIndex2 = copyIndex2 + 1;
        }
        outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,iVar6 + copyIndex2,loopIndex,0,0);
        copyIndex2 = 0;
        ch = s___scratch_97c2e65c[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex2) = ch;
          ch = ", scratch"[copyIndex2 + 1];
          copyIndex2 = copyIndex2 + 1;
        }
        outCursor = outCursor + copyIndex2;
        if (loopIndex != 0) {
          copyEnd2 = ((int (*)())_ncpy_97bf2850)(outCursor,loopIndex);
          outCursor = outCursor + copyEnd2;
        }
        copyIndex2 = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex2) = ch;
          ch = ";\n"[copyIndex2 + 1];
          copyIndex2 = copyIndex2 + 1;
        }
        loopIndex = loopIndex + 1;
        iVar6 = outCursor + copyIndex2;
      } while (loopIndex <= (int)(inst[2] >> 10 & 3));
    }
    goto LAB_97c01788;
  case 0x24:
    copyIndex = 0;
    ch = s_MUL_97c2e4f0[0];
    while (ch != '\0') {
      *(char *)(outText + copyIndex) = ch;
      ch = "MUL "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outText + copyIndex,0,0,0);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,2,0,0,0);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    iVar6 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,3,0,0,0);
    opOffsetOrTailLength = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(iVar6 + opOffsetOrTailLength) = ch;
      ch = ";\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 0x25:
    *stateFlags = *stateFlags | 0x2001;
    copyIndex = 0;
    ch = s_ADD_scratch_x__97c2e960[0];
    while (ch != '\0') {
      *(char *)(outText + copyIndex) = ch;
      ch = "ADD scratch.x, "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,param_5,param_6,2,0,0,0);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,3,0,0,0);
    copyIndex = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ";\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    copyIndex2 = 0;
    ch = s_SGE_97c2e91c[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex + copyIndex2) = ch;
      ch = "SGE "[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    iVar6 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor + copyIndex + copyIndex2,0,0,0);
    opOffsetOrTailLength = 0;
    ch = s___scratch_x__kHALF__97c2e970[0];
    while (ch != '\0') {
      *(char *)(iVar6 + opOffsetOrTailLength) = ch;
      ch = ", scratch.x, kHALF;\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 0x26:
    *stateFlags = *stateFlags | 1;
    copyIndex = 0;
    ch = s_SUB_scratch_x__97c2e988[0];
    while (ch != '\0') {
      *(char *)(outText + copyIndex) = ch;
      ch = "SUB scratch.x, "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,param_5,param_6,2,0,0,0);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,3,0,0,0);
    copyIndex = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ";\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    copyIndex2 = 0;
    ch = s_ABS_97c2e998[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex + copyIndex2) = ch;
      ch = "ABS "[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    iVar6 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor + copyIndex + copyIndex2,0,0,0);
    opOffsetOrTailLength = 0;
    ch = s___scratch_x__97c2e594[0];
    while (ch != '\0') {
      *(char *)(iVar6 + opOffsetOrTailLength) = ch;
      ch = ", scratch.x;\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 0x27:
    uVar8 = inst[4];
    if (((uVar8 >> 0xc & 3) == 1) && (((stateFlags[1] & 0x800000) == 0 || (shaderType != 0x8b30)))) {
      copyIndex = 0;
      ch = s_MUL_scratch_xy__97c2e510[0];
      while (ch != '\0') {
        *(char *)(outText + copyIndex) = ch;
        ch = "MUL scratch.xy, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,param_5,param_6,2,0,0,0);
      copyIndex = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,3,0,0,0);
      copyIndex = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ";\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      copyIndex2 = 0;
      ch = s_MUL_97c2e4f0[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex + copyIndex2) = ch;
        ch = "MUL "[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      iVar6 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor + copyIndex + copyIndex2,0,0,0);
      opOffsetOrTailLength = 0;
      ch = s___scratch_x__scratch_y__97c2e524[0];
      while (ch != '\0') {
        *(char *)(iVar6 + opOffsetOrTailLength) = ch;
        ch = ", scratch.x, scratch.y;\n"[opOffsetOrTailLength + 1];
        opOffsetOrTailLength = opOffsetOrTailLength + 1;
      }
    }
    else {
      if ((uVar8 >> 0xc & 3) == 1) {
        *stateFlags = *stateFlags | 0x800000;
        uVar8 = inst[4];
      }
      uVar8 = uVar8 >> 0xc & 3;
      if (uVar8 == 0) {
        copyIndex = 0;
        ch = s_MUL_97c2e4f0[0];
        while (ch != '\0') {
          *(char *)(outText + copyIndex) = ch;
          ch = "MUL "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
      }
      else if (uVar8 == 1) {
        copyIndex = 0;
        ch = s_DP2_97c2e540[0];
        while (ch != '\0') {
          *(char *)(outText + copyIndex) = ch;
          ch = "DP2 "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
      }
      else if (uVar8 == 2) {
        copyIndex = 0;
        ch = s_DP3_97c2e548[0];
        while (ch != '\0') {
          *(char *)(outText + copyIndex) = ch;
          ch = "DP3 "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
      }
      else {
        copyIndex = 0;
        ch = s_DP4_97c2e550[0];
        while (ch != '\0') {
          *(char *)(outText + copyIndex) = ch;
          ch = "DP4 "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
      }
      outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outText + copyIndex,0,0,0);
      copyIndex = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,2,0,0,0);
      copyIndex = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      iVar6 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,3,0,0,0);
      opOffsetOrTailLength = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        *(char *)(iVar6 + opOffsetOrTailLength) = ch;
        ch = ";\n"[opOffsetOrTailLength + 1];
        opOffsetOrTailLength = opOffsetOrTailLength + 1;
      }
    }
    break;
  case 0x2b:
    *stateFlags = *stateFlags | 1;
    copyIndex = 0;
    ch = s_ADD_scratch__97c2e7e0[0];
    while (ch != '\0') {
      *(char *)(outText + copyIndex) = ch;
      ch = "ADD scratch, "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,param_5,param_6,2,0,0,0);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,3,0,0,1);
    copyIndex = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ";\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = outCursor + copyIndex;
    uVar8 = inst[4] >> 0xc & 3;
    if (uVar8 == 1) {
      copyIndex = 0;
      ch = s_SWZ_scratch__scratch__x__y__0__0_97c2e7f0[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = "SWZ scratch, scratch, x, y, 0, 0;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = outCursor + copyIndex;
      copyIndex = 0;
      ch = s_DP3_scratch_x__scratch__scratch__97c2e7bc[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = "DP3 scratch.x, scratch, scratch;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
    }
    else if (uVar8 == 0) {
      copyIndex = 0;
      ch = s_MUL_scratch_x__scratch_x__scratc_97c2e814[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = "MUL scratch.x, scratch.x, scratch.x;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
    }
    else if (uVar8 == 2) {
      copyIndex = 0;
      ch = s_DP3_scratch_x__scratch__scratch__97c2e7bc[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = "DP3 scratch.x, scratch, scratch;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
    }
    else {
      copyIndex = 0;
      ch = s_DP4_scratch_x__scratch__scratch__97c2e83c[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = "DP4 scratch.x, scratch, scratch;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
    }
    copyIndex2 = 0;
    ch = s_RSQ_scratch_x__scratch_x__97c2e754[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex + copyIndex2) = ch;
      ch = "RSQ scratch.x, scratch.x;\n"[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outCursor2 = outCursor + copyIndex + copyIndex2;
    copyIndex = 0;
    ch = s_RCP_97c2e58c[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "RCP "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    iVar6 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor2 + copyIndex,0,0,0);
    opOffsetOrTailLength = 0;
    ch = s___scratch_x__97c2e594[0];
    while (ch != '\0') {
      *(char *)(iVar6 + opOffsetOrTailLength) = ch;
      ch = ", scratch.x;\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 0x2c:
  case 0x2d:
    copyIndex9 = 0;
    mnemonic = *(char **)(PTR__ppstreamOpString_a7b7c108 + opOffsetOrTailLength);
    ch = *mnemonic;
    while (ch != '\0') {
      *(char *)(outText + copyIndex9) = ch;
      copyIndex9 = copyIndex9 + 1;
      ch = mnemonic[copyIndex9];
    }
    copyIndex = 0;
    ch = s__97c291c0[0];
    while (ch != '\0') {
      *(char *)(outText + copyIndex9 + copyIndex) = ch;
      ch = " "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outText + copyIndex9 + copyIndex,0,0,0);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,2,0,0,8);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    iVar6 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,3,0,0,8);
    opOffsetOrTailLength = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(iVar6 + opOffsetOrTailLength) = ch;
      ch = ";\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 0x2e:
  case 0x32:
  case 0x35:
    copyIndex9 = 0;
    mnemonic = *(char **)(PTR__ppstreamOpString_a7b7c108 + opOffsetOrTailLength);
    ch = *mnemonic;
    while (ch != '\0') {
      *(char *)(outText + copyIndex9) = ch;
      copyIndex9 = copyIndex9 + 1;
      ch = mnemonic[copyIndex9];
    }
    copyIndex = 0;
    ch = s__97c291c0[0];
    while (ch != '\0') {
      *(char *)(outText + copyIndex9 + copyIndex) = ch;
      ch = " "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outText + copyIndex9 + copyIndex,0,0,0);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,2,0,0,8);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    iVar6 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,3,0,0,8);
    opOffsetOrTailLength = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(iVar6 + opOffsetOrTailLength) = ch;
      ch = ";\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 0x2f:
    *stateFlags = *stateFlags | 1;
    if ((inst[2] >> 10 & 3) == 2) {
      copyIndex = 0;
      ch = s_DP3_scratch_x__97c2e734[0];
      while (ch != '\0') {
        *(char *)(outText + copyIndex) = ch;
        ch = "DP3 scratch.x, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
    }
    else {
      copyIndex = 0;
      ch = s_DP4_scratch_x__97c2e744[0];
      while (ch != '\0') {
        *(char *)(outText + copyIndex) = ch;
        ch = "DP4 scratch.x, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,param_5,param_6,2,0,0,0);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,3,0,0,0);
    copyIndex = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ";\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    copyIndex2 = 0;
    ch = s_MUL_scratch__97c2e62c[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex + copyIndex2) = ch;
      ch = "MUL scratch, "[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex + copyIndex2,param_5,param_6,3,0,0,0);
    copyIndex = 0;
    ch = s___scratch_x__97c2e594[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", scratch.x;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    copyIndex2 = 0;
    ch = s_ADD_scratch__scratch__scratch__97c2e770[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex + copyIndex2) = ch;
      ch = "ADD scratch, scratch, scratch;\n"[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outCursor2 = outCursor + copyIndex + copyIndex2;
    copyIndex = 0;
    ch = s_ADD_97c2e6d4[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "ADD "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor2 + copyIndex,0,0,0);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,2,0,0,8);
    copyIndex = 0;
    ch = s____scratch_97c2e790[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", -scratch"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    iVar6 = ((int (*)())_glpWriteComponentsWithDestinationSwizzle)(inst,outCursor + copyIndex);
    opOffsetOrTailLength = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(iVar6 + opOffsetOrTailLength) = ch;
      ch = ";\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 0x31:
    if (((inst[4] & 0x4000) == 0) && ((inst[6] & 0x4000) == 0)) {
      if ((((stateFlags[1] & 0x100000) == 0) || (shaderType != 0x8b31)) &&
         (((stateFlags[1] & 0x400000) == 0 || (shaderType != 0x8b30)))) {
        *stateFlags = *stateFlags | 0x1001;
        copyIndex = 0;
        ch = s_SUB_scratch__97c2e870[0];
        while (ch != '\0') {
          *(char *)(outText + copyIndex) = ch;
          ch = "SUB scratch, "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,param_5,param_6,2,0,0,8);
        copyIndex = 0;
        ch = s___97c2d7ec[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex) = ch;
          ch = ", "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,3,0,0,8);
        copyIndex = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex) = ch;
          ch = ";\n"[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        copyIndex2 = 0;
        ch = s_ABS_scratch__scratch__97c2e8c0[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex + copyIndex2) = ch;
          ch = "ABS scratch, scratch;\n"[copyIndex2 + 1];
          copyIndex2 = copyIndex2 + 1;
        }
        outCursor2 = outCursor + copyIndex + copyIndex2;
        copyIndex = 0;
        ch = s_SGE_97c2e91c[0];
        while (ch != '\0') {
          *(char *)(outCursor2 + copyIndex) = ch;
          ch = "SGE "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        iVar6 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor2 + copyIndex,0,0,0);
        opOffsetOrTailLength = 0;
        ch = s____scratch__kZERO__97c2e460[0];
        while (ch != '\0') {
          *(char *)(iVar6 + opOffsetOrTailLength) = ch;
          ch = ", -scratch, kZERO;\n"[opOffsetOrTailLength + 1];
          opOffsetOrTailLength = opOffsetOrTailLength + 1;
        }
      }
      else {
        if (shaderType == 0x8b31) {
          uVar8 = *stateFlags | 0x100000;
        }
        else {
          uVar8 = *stateFlags | 0x400000;
        }
        *stateFlags = uVar8;
        copyIndex = 0;
        ch = s_SEQ_97c2e924[0];
        while (ch != '\0') {
          *(char *)(outText + copyIndex) = ch;
          ch = "SEQ "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outText + copyIndex,0,0,0);
        copyIndex = 0;
        ch = s___97c2d7ec[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex) = ch;
          ch = ", "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,2,0,0,8);
        copyIndex = 0;
        ch = s___97c2d7ec[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex) = ch;
          ch = ", "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        iVar6 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,3,0,0,8);
        opOffsetOrTailLength = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          *(char *)(iVar6 + opOffsetOrTailLength) = ch;
          ch = ";\n"[opOffsetOrTailLength + 1];
          opOffsetOrTailLength = opOffsetOrTailLength + 1;
        }
      }
    }
    else {
      *stateFlags = *stateFlags | 3;
      uVar8 = inst[4];
      if ((uVar8 & 0x4000) == 0) {
        uVar8 = inst[6];
      }
      uVar8 = uVar8 >> 0xc & 3;
      loopIndex2 = 0;
      iVar11 = outText;
      do {
        bVar1 = loopIndex2 == 0;
        if (bVar1) {
          copyIndex2 = 0;
          ch = s_SUB_scratch__97c2e870[0];
          while (ch != '\0') {
            *(char *)(iVar11 + copyIndex2) = ch;
            ch = "SUB scratch, "[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
        }
        else {
          copyIndex2 = 0;
          ch = s_SUB_scratch1__97c2e860[0];
          while (ch != '\0') {
            *(char *)(iVar11 + copyIndex2) = ch;
            ch = "SUB scratch1, "[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
        }
        iVar13 = loopIndex2;
        if ((inst[4] & 0x4000) == 0) {
          iVar13 = 0;
        }
        outCursor7 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,iVar11 + copyIndex2,param_5,param_6,2,iVar13,0,0)
        ;
        copyIndex = 0;
        ch = s___97c2d7ec[0];
        while (ch != '\0') {
          *(char *)(outCursor7 + copyIndex) = ch;
          ch = ", "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        iVar13 = loopIndex2;
        if ((inst[6] & 0x4000) == 0) {
          iVar13 = 0;
        }
        outCursor3 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor7 + copyIndex,param_5,param_6,3,iVar13,0,0);
        copyIndex2 = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          *(char *)(outCursor3 + copyIndex2) = ch;
          ch = ";\n"[copyIndex2 + 1];
          copyIndex2 = copyIndex2 + 1;
        }
        outCursor3 = outCursor3 + copyIndex2;
        if (bVar1) {
          copyIndex2 = 0;
          ch = s_ABS_scratch__scratch__97c2e8c0[0];
          while (ch != '\0') {
            *(char *)(outCursor3 + copyIndex2) = ch;
            ch = "ABS scratch, scratch;\n"[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
        }
        else {
          copyIndex2 = 0;
          ch = s_ABS_scratch1__scratch1__97c2e880[0];
          while (ch != '\0') {
            *(char *)(outCursor3 + copyIndex2) = ch;
            ch = "ABS scratch1, scratch1;\n"[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
        }
        iVar11 = outCursor3 + copyIndex2;
        if (!bVar1) {
          copyIndex2 = 0;
          ch = s_ADD_scratch__scratch__scratch1__97c2e89c[0];
          while (ch != '\0') {
            *(char *)(iVar11 + copyIndex2) = ch;
            ch = "ADD scratch, scratch, scratch1;\n"[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
          iVar11 = iVar11 + copyIndex2;
        }
        loopIndex2 = loopIndex2 + 1;
      } while (loopIndex2 <= (int)uVar8);
      copyIndex3 = 0;
      ch = s_DP4_scratch__scratch__97c2e8d8[0];
      while (ch != '\0') {
        *(char *)(iVar11 + copyIndex3) = ch;
        ch = "DP4 scratch, scratch, "[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      outCursor3 = iVar11 + copyIndex3;
      if (uVar8 == 1) {
        *stateFlags = *stateFlags | 0x1000;
        copyIndex3 = 0;
        ch = s_kVEC2_97c2e8f0[0];
        while (ch != '\0') {
          *(char *)(outCursor3 + copyIndex3) = ch;
          ch = "kVEC2"[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
LAB_97bf9b6c:
        outCursor3 = outCursor3 + copyIndex3;
      }
      else {
        if (uVar8 == 2) {
          *stateFlags = *stateFlags | 0x1000;
          copyIndex3 = 0;
          ch = s_kVEC3_97c2e8f8[0];
          while (ch != '\0') {
            *(char *)(outCursor3 + copyIndex3) = ch;
            ch = "kVEC3"[copyIndex3 + 1];
            copyIndex3 = copyIndex3 + 1;
          }
          goto LAB_97bf9b6c;
        }
        if (uVar8 == 3) {
          *stateFlags = *stateFlags | 0x1000;
          copyIndex3 = 0;
          ch = s_kVEC4_97c2e900[0];
          while (ch != '\0') {
            *(char *)(outCursor3 + copyIndex3) = ch;
            ch = "kVEC4"[copyIndex3 + 1];
            copyIndex3 = copyIndex3 + 1;
          }
          goto LAB_97bf9b6c;
        }
      }
      copyIndex3 = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        *(char *)(outCursor3 + copyIndex3) = ch;
        ch = ";\n"[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      copyIndex2 = 0;
      ch = s_ABS_scratch__scratch__97c2e8c0[0];
      while (ch != '\0') {
        *(char *)(outCursor3 + copyIndex3 + copyIndex2) = ch;
        ch = "ABS scratch, scratch;\n"[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      outCursor2 = outCursor3 + copyIndex3 + copyIndex2;
      copyIndex = 0;
      ch = s_SGE_97c2e91c[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "SGE "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      iVar6 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor2 + copyIndex,0,0,0);
      opOffsetOrTailLength = 0;
      ch = s____scratch__kZERO__97c2e460[0];
      while (ch != '\0') {
        *(char *)(iVar6 + opOffsetOrTailLength) = ch;
        ch = ", -scratch, kZERO;\n"[opOffsetOrTailLength + 1];
        opOffsetOrTailLength = opOffsetOrTailLength + 1;
      }
    }
    break;
  case 0x33:
    copyIndex = 0;
    ch = s_SLT_97c2e458[0];
    while (ch != '\0') {
      *(char *)(outText + copyIndex) = ch;
      ch = "SLT "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outText + copyIndex,0,0,0);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,2,0,0,1);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    iVar6 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,3,0,0,1);
    opOffsetOrTailLength = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(iVar6 + opOffsetOrTailLength) = ch;
      ch = ";\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 0x34:
    copyIndex = 0;
    ch = s_SGE_97c2e91c[0];
    while (ch != '\0') {
      *(char *)(outText + copyIndex) = ch;
      ch = "SGE "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outText + copyIndex,0,0,0);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,2,0,0,1);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    iVar6 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,3,0,0,1);
    opOffsetOrTailLength = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(iVar6 + opOffsetOrTailLength) = ch;
      ch = ";\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 0x36:
    if (((inst[4] & 0x4000) == 0) && ((inst[6] & 0x4000) == 0)) {
      if ((((stateFlags[1] & 0x100000) == 0) || (shaderType != 0x8b31)) &&
         (((stateFlags[1] & 0x400000) == 0 || (shaderType != 0x8b30)))) {
        *stateFlags = *stateFlags | 0x1001;
        copyIndex = 0;
        ch = s_SUB_scratch__97c2e870[0];
        while (ch != '\0') {
          *(char *)(outText + copyIndex) = ch;
          ch = "SUB scratch, "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,param_5,param_6,2,0,0,8);
        copyIndex = 0;
        ch = s___97c2d7ec[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex) = ch;
          ch = ", "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,3,0,0,0);
        copyIndex = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex) = ch;
          ch = ";\n"[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        copyIndex2 = 0;
        ch = s_ABS_scratch__scratch__97c2e8c0[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex + copyIndex2) = ch;
          ch = "ABS scratch, scratch;\n"[copyIndex2 + 1];
          copyIndex2 = copyIndex2 + 1;
        }
        outCursor2 = outCursor + copyIndex + copyIndex2;
        copyIndex = 0;
        ch = s_SLT_97c2e458[0];
        while (ch != '\0') {
          *(char *)(outCursor2 + copyIndex) = ch;
          ch = "SLT "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        iVar6 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor2 + copyIndex,0,0,0);
        opOffsetOrTailLength = 0;
        ch = s____scratch__kZERO__97c2e460[0];
        while (ch != '\0') {
          *(char *)(iVar6 + opOffsetOrTailLength) = ch;
          ch = ", -scratch, kZERO;\n"[opOffsetOrTailLength + 1];
          opOffsetOrTailLength = opOffsetOrTailLength + 1;
        }
      }
      else {
        if (shaderType == 0x8b31) {
          uVar8 = *stateFlags | 0x100000;
        }
        else {
          uVar8 = *stateFlags | 0x400000;
        }
        *stateFlags = uVar8;
        copyIndex = 0;
        ch = s_SNE_97c2e908[0];
        while (ch != '\0') {
          *(char *)(outText + copyIndex) = ch;
          ch = "SNE "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outText + copyIndex,0,0,0);
        copyIndex = 0;
        ch = s___97c2d7ec[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex) = ch;
          ch = ", "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,2,0,0,8);
        copyIndex = 0;
        ch = s___97c2d7ec[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex) = ch;
          ch = ", "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        iVar6 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,3,0,0,8);
        opOffsetOrTailLength = 0;
        ch = s_____end_97c2e910[0];
        while (ch != '\0') {
          *(char *)(iVar6 + opOffsetOrTailLength) = ch;
          ch = ";\n# end\n"[opOffsetOrTailLength + 1];
          opOffsetOrTailLength = opOffsetOrTailLength + 1;
        }
      }
    }
    else {
      *stateFlags = *stateFlags | 3;
      uVar8 = inst[4];
      if ((uVar8 & 0x4000) == 0) {
        uVar8 = inst[6];
      }
      uVar8 = uVar8 >> 0xc & 3;
      loopIndex2 = 0;
      iVar11 = outText;
      do {
        bVar1 = loopIndex2 == 0;
        if (bVar1) {
          copyIndex2 = 0;
          ch = s_SUB_scratch__97c2e870[0];
          while (ch != '\0') {
            *(char *)(iVar11 + copyIndex2) = ch;
            ch = "SUB scratch, "[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
        }
        else {
          copyIndex2 = 0;
          ch = s_SUB_scratch1__97c2e860[0];
          while (ch != '\0') {
            *(char *)(iVar11 + copyIndex2) = ch;
            ch = "SUB scratch1, "[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
        }
        iVar13 = loopIndex2;
        if ((inst[4] & 0x4000) == 0) {
          iVar13 = 0;
        }
        outCursor7 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,iVar11 + copyIndex2,param_5,param_6,2,iVar13,0,0)
        ;
        copyIndex = 0;
        ch = s___97c2d7ec[0];
        while (ch != '\0') {
          *(char *)(outCursor7 + copyIndex) = ch;
          ch = ", "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        iVar13 = loopIndex2;
        if ((inst[6] & 0x4000) == 0) {
          iVar13 = 0;
        }
        outCursor3 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor7 + copyIndex,param_5,param_6,3,iVar13,0,0);
        copyIndex2 = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          *(char *)(outCursor3 + copyIndex2) = ch;
          ch = ";\n"[copyIndex2 + 1];
          copyIndex2 = copyIndex2 + 1;
        }
        outCursor3 = outCursor3 + copyIndex2;
        if (bVar1) {
          copyIndex2 = 0;
          ch = s_ABS_scratch__scratch__97c2e8c0[0];
          while (ch != '\0') {
            *(char *)(outCursor3 + copyIndex2) = ch;
            ch = "ABS scratch, scratch;\n"[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
        }
        else {
          copyIndex2 = 0;
          ch = s_ABS_scratch1__scratch1__97c2e880[0];
          while (ch != '\0') {
            *(char *)(outCursor3 + copyIndex2) = ch;
            ch = "ABS scratch1, scratch1;\n"[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
        }
        iVar11 = outCursor3 + copyIndex2;
        if (!bVar1) {
          copyIndex2 = 0;
          ch = s_ADD_scratch__scratch__scratch1__97c2e89c[0];
          while (ch != '\0') {
            *(char *)(iVar11 + copyIndex2) = ch;
            ch = "ADD scratch, scratch, scratch1;\n"[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
          iVar11 = iVar11 + copyIndex2;
        }
        loopIndex2 = loopIndex2 + 1;
      } while (loopIndex2 <= (int)uVar8);
      copyIndex3 = 0;
      ch = s_DP4_scratch__scratch__97c2e8d8[0];
      while (ch != '\0') {
        *(char *)(iVar11 + copyIndex3) = ch;
        ch = "DP4 scratch, scratch, "[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      outCursor3 = iVar11 + copyIndex3;
      if (uVar8 == 1) {
        *stateFlags = *stateFlags | 0x1000;
        copyIndex3 = 0;
        ch = s_kVEC2_97c2e8f0[0];
        while (ch != '\0') {
          *(char *)(outCursor3 + copyIndex3) = ch;
          ch = "kVEC2"[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
LAB_97bf9370:
        outCursor3 = outCursor3 + copyIndex3;
      }
      else {
        if (uVar8 == 2) {
          *stateFlags = *stateFlags | 0x1000;
          copyIndex3 = 0;
          ch = s_kVEC3_97c2e8f8[0];
          while (ch != '\0') {
            *(char *)(outCursor3 + copyIndex3) = ch;
            ch = "kVEC3"[copyIndex3 + 1];
            copyIndex3 = copyIndex3 + 1;
          }
          goto LAB_97bf9370;
        }
        if (uVar8 == 3) {
          *stateFlags = *stateFlags | 0x1000;
          copyIndex3 = 0;
          ch = s_kVEC4_97c2e900[0];
          while (ch != '\0') {
            *(char *)(outCursor3 + copyIndex3) = ch;
            ch = "kVEC4"[copyIndex3 + 1];
            copyIndex3 = copyIndex3 + 1;
          }
          goto LAB_97bf9370;
        }
      }
      copyIndex3 = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        *(char *)(outCursor3 + copyIndex3) = ch;
        ch = ";\n"[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      copyIndex2 = 0;
      ch = s_ABS_scratch__scratch__97c2e8c0[0];
      while (ch != '\0') {
        *(char *)(outCursor3 + copyIndex3 + copyIndex2) = ch;
        ch = "ABS scratch, scratch;\n"[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      outCursor2 = outCursor3 + copyIndex3 + copyIndex2;
      copyIndex = 0;
      ch = s_SLT_97c2e458[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "SLT "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      iVar6 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor2 + copyIndex,0,0,0);
      opOffsetOrTailLength = 0;
      ch = s____scratch__kZERO__97c2e460[0];
      while (ch != '\0') {
        *(char *)(iVar6 + opOffsetOrTailLength) = ch;
        ch = ", -scratch, kZERO;\n"[opOffsetOrTailLength + 1];
        opOffsetOrTailLength = opOffsetOrTailLength + 1;
      }
    }
    break;
  case 0x38:
    uVar8 = inst[2];
    uVar9 = uVar8 >> 0xd & 0xf;
    loopIndex3 = 0;
    do {
      if ((uVar9 & 1) != 0) {
        mnemonic = *(char **)(opStringTable + opOffsetOrTailLength);
        copyIndex10 = 0;
        ch = *mnemonic;
        while (ch != '\0') {
          *(char *)(iVar6 + copyIndex10) = ch;
          copyIndex10 = copyIndex10 + 1;
          ch = mnemonic[copyIndex10];
        }
        copyIndex5 = 0;
        ch = s__97c291c0[0];
        while (ch != '\0') {
          *(char *)(iVar6 + copyIndex10 + copyIndex5) = ch;
          ch = " "[copyIndex5 + 1];
          copyIndex5 = copyIndex5 + 1;
        }
        outCursor4 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,iVar6 + copyIndex10 + copyIndex5,0,loopIndex3,2);
        copyIndex3 = 0;
        ch = s___97c2d7ec[0];
        while (ch != '\0') {
          *(char *)(outCursor4 + copyIndex3) = ch;
          ch = ", "[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        outCursor4 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor4 + copyIndex3,param_5,param_6,2,0,loopIndex3,10);
        copyIndex3 = 0;
        ch = s___97c2d7ec[0];
        while (ch != '\0') {
          *(char *)(outCursor4 + copyIndex3) = ch;
          ch = ", "[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        outCursor6 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor4 + copyIndex3,param_5,param_6,3,0,loopIndex3,10)
        ;
        copyIndex4 = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          *(char *)(outCursor6 + copyIndex4) = ch;
          ch = ";\n"[copyIndex4 + 1];
          copyIndex4 = copyIndex4 + 1;
        }
        uVar8 = inst[2];
        iVar6 = outCursor6 + copyIndex4;
      }
      loopIndex3 = loopIndex3 + 1;
      uVar9 = (int)uVar9 >> 1;
    } while (loopIndex3 <= (int)(uVar8 >> 10 & 3));
    goto LAB_97c01788;
  case 0x39:
    *stateFlags = *stateFlags | 0x1001;
    copyIndex = 0;
    ch = s_SUB_scratch__kSEL__97c2f620[0];
    while (ch != '\0') {
      *(char *)(outText + copyIndex) = ch;
      ch = "SUB scratch, kSEL, "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,param_5,param_6,3,0,0,0);
    copyIndex = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ";\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    copyIndex2 = 0;
    ch = s_ABS_scratch__scratch__97c2e8c0[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex + copyIndex2) = ch;
      ch = "ABS scratch, scratch;\n"[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outCursor2 = outCursor + copyIndex + copyIndex2;
    copyIndex = 0;
    ch = s_SGE_scratch___scratch__kZERO__97c2f634[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "SGE scratch, -scratch, kZERO;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor2 = outCursor2 + copyIndex;
    copyIndex = 0;
    ch = s_DP4_97c2e550[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "DP4 "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor2 + copyIndex,0,0,0);
    copyIndex = 0;
    ch = s___scratch__97c2e570[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", scratch, "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    iVar6 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,2,0,0,0);
    opOffsetOrTailLength = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(iVar6 + opOffsetOrTailLength) = ch;
      ch = ";\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 0x3a:
    *stateFlags = *stateFlags | 1;
    if (((inst[4] & 0x4000) == 0) || ((inst[6] & 0x4000) == 0)) {
      if ((inst[4] & 0x4000) == 0) {
        if ((inst[6] & 0x4000) == 0) {
          if ((inst[6] & 0x3000) == 0) {
            copyIndex = 0;
            ch = s_RCP_scratch__97c2e600[0];
            while (ch != '\0') {
              *(char *)(outText + copyIndex) = ch;
              ch = "RCP scratch, "[copyIndex + 1];
              copyIndex = copyIndex + 1;
            }
            outCursor3 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,param_5,param_6,3,0,0,0);
            copyIndex3 = 0;
            ch = s___97c2d8f8[0];
            while (ch != '\0') {
              *(char *)(outCursor3 + copyIndex3) = ch;
              ch = ";\n"[copyIndex3 + 1];
              copyIndex3 = copyIndex3 + 1;
            }
            iVar11 = outCursor3 + copyIndex3;
          }
          else {
            uVar8 = inst[2];
            uVar9 = uVar8 >> 0xd & 0xf;
            loopIndex2 = 0;
            iVar11 = outText;
            do {
              if ((uVar9 & 1) != 0) {
                copyIndex2 = 0;
                ch = s_RCP_scratch__97c2e5f0[0];
                while (ch != '\0') {
                  *(char *)(iVar11 + copyIndex2) = ch;
                  ch = "RCP scratch."[copyIndex2 + 1];
                  copyIndex2 = copyIndex2 + 1;
                }
                outPtr = (char *)(iVar11 + copyIndex2);
                *outPtr = ((char)loopIndex2 + 1U & 3) + 0x77;
                copyIndex = 0;
                ch = s___97c2d7ec[0];
                while (ch != '\0') {
                  outPtr[copyIndex + 1] = ch;
                  ch = ", "[copyIndex + 1];
                  copyIndex = copyIndex + 1;
                }
                outCursor3 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outPtr + copyIndex + 1,param_5,param_6,3,0,loopIndex2,10);
                copyIndex2 = 0;
                ch = s___97c2d8f8[0];
                while (ch != '\0') {
                  *(char *)(outCursor3 + copyIndex2) = ch;
                  ch = ";\n"[copyIndex2 + 1];
                  copyIndex2 = copyIndex2 + 1;
                }
                uVar8 = inst[2];
                iVar11 = outCursor3 + copyIndex2;
              }
              loopIndex2 = loopIndex2 + 1;
              uVar9 = (int)uVar9 >> 1;
            } while (loopIndex2 <= (int)(uVar8 >> 10 & 3));
          }
          copyIndex3 = 0;
          ch = s_MUL_97c2e4f0[0];
          while (ch != '\0') {
            *(char *)(iVar11 + copyIndex3) = ch;
            ch = "MUL "[copyIndex3 + 1];
            copyIndex3 = copyIndex3 + 1;
          }
          outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,iVar11 + copyIndex3,0,0,0);
          copyIndex = 0;
          ch = s___97c2d7ec[0];
          while (ch != '\0') {
            *(char *)(outCursor + copyIndex) = ch;
            ch = ", "[copyIndex + 1];
            copyIndex = copyIndex + 1;
          }
          iVar6 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,2,0,0,8);
          opOffsetOrTailLength = 0;
          ch = s___scratch__97c2e620[0];
          while (ch != '\0') {
            *(char *)(iVar6 + opOffsetOrTailLength) = ch;
            ch = ", scratch;\n"[opOffsetOrTailLength + 1];
            opOffsetOrTailLength = opOffsetOrTailLength + 1;
          }
          break;
        }
        loopIndex = 0;
        do {
          iVar5 = 0;
          do {
            copyIndex4 = 0;
            ch = s_RCP_scratch__97c2e5f0[0];
            while (ch != '\0') {
              *(char *)(iVar6 + copyIndex4) = ch;
              ch = "RCP scratch."[copyIndex4 + 1];
              copyIndex4 = copyIndex4 + 1;
            }
            iVar12 = iVar5 + 1;
            outPtr = (char *)(iVar6 + copyIndex4);
            *outPtr = ((byte)iVar12 & 3) + 0x77;
            copyIndex3 = 0;
            ch = s___97c2d7ec[0];
            while (ch != '\0') {
              outPtr[copyIndex3 + 1] = ch;
              ch = ", "[copyIndex3 + 1];
              copyIndex3 = copyIndex3 + 1;
            }
            outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outPtr + copyIndex3 + 1,param_5,param_6,3,loopIndex,iVar5,2);
            copyIndex2 = 0;
            ch = s___97c2d8f8[0];
            while (ch != '\0') {
              *(char *)(outCursor + copyIndex2) = ch;
              ch = ";\n"[copyIndex2 + 1];
              copyIndex2 = copyIndex2 + 1;
            }
            iVar6 = outCursor + copyIndex2;
            iVar5 = iVar12;
          } while (iVar12 <= (int)(inst[6] >> 0xc & 3));
          copyIndex2 = 0;
          ch = s_MUL_97c2e4f0[0];
          while (ch != '\0') {
            *(char *)(iVar6 + copyIndex2) = ch;
            ch = "MUL "[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
          outCursor2 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,iVar6 + copyIndex2,loopIndex,0,0);
          copyIndex3 = 0;
          ch = s___97c2d7ec[0];
          while (ch != '\0') {
            *(char *)(outCursor2 + copyIndex3) = ch;
            ch = ", "[copyIndex3 + 1];
            copyIndex3 = copyIndex3 + 1;
          }
          outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex3,param_5,param_6,2,0,0,0);
          copyIndex2 = 0;
          ch = s___scratch__97c2e5e0[0];
          while (ch != '\0') {
            *(char *)(outCursor + copyIndex2) = ch;
            ch = ", scratch; \n"[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
          loopIndex = loopIndex + 1;
          iVar6 = outCursor + copyIndex2;
        } while (loopIndex <= (int)(inst[6] >> 0xc & 3));
      }
      else {
        copyIndex = 0;
        ch = s_RCP_scratch__97c2e600[0];
        while (ch != '\0') {
          *(char *)(outText + copyIndex) = ch;
          ch = "RCP scratch, "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,param_5,param_6,3,0,0,0);
        copyIndex = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex) = ch;
          ch = ";\n"[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        iVar6 = outCursor + copyIndex;
        loopIndex = 0;
        do {
          copyIndex2 = 0;
          ch = s_MUL_97c2e4f0[0];
          while (ch != '\0') {
            *(char *)(iVar6 + copyIndex2) = ch;
            ch = "MUL "[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
          outCursor2 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,iVar6 + copyIndex2,loopIndex,0,0);
          copyIndex3 = 0;
          ch = s___97c2d7ec[0];
          while (ch != '\0') {
            *(char *)(outCursor2 + copyIndex3) = ch;
            ch = ", "[copyIndex3 + 1];
            copyIndex3 = copyIndex3 + 1;
          }
          outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex3,param_5,param_6,2,loopIndex,0,0);
          copyIndex2 = 0;
          ch = s___scratch_x__97c2e610[0];
          while (ch != '\0') {
            *(char *)(outCursor + copyIndex2) = ch;
            ch = ", scratch.x; \n"[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
          loopIndex = loopIndex + 1;
          iVar6 = outCursor + copyIndex2;
        } while (loopIndex <= (int)(inst[2] >> 10 & 3));
      }
    }
    else {
      loopIndex = 0;
      do {
        iVar5 = 0;
        do {
          copyIndex4 = 0;
          ch = s_RCP_scratch__97c2e5f0[0];
          while (ch != '\0') {
            *(char *)(iVar6 + copyIndex4) = ch;
            ch = "RCP scratch."[copyIndex4 + 1];
            copyIndex4 = copyIndex4 + 1;
          }
          iVar12 = iVar5 + 1;
          outPtr = (char *)(iVar6 + copyIndex4);
          *outPtr = ((byte)iVar12 & 3) + 0x77;
          copyIndex3 = 0;
          ch = s___97c2d7ec[0];
          while (ch != '\0') {
            outPtr[copyIndex3 + 1] = ch;
            ch = ", "[copyIndex3 + 1];
            copyIndex3 = copyIndex3 + 1;
          }
          outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outPtr + copyIndex3 + 1,param_5,param_6,3,loopIndex,iVar5,2);
          copyIndex2 = 0;
          ch = s___97c2d8f8[0];
          while (ch != '\0') {
            *(char *)(outCursor + copyIndex2) = ch;
            ch = ";\n"[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
          iVar6 = outCursor + copyIndex2;
          iVar5 = iVar12;
        } while (iVar12 <= (int)(inst[6] >> 0xc & 3));
        copyIndex2 = 0;
        ch = s_MUL_97c2e4f0[0];
        while (ch != '\0') {
          *(char *)(iVar6 + copyIndex2) = ch;
          ch = "MUL "[copyIndex2 + 1];
          copyIndex2 = copyIndex2 + 1;
        }
        outCursor2 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,iVar6 + copyIndex2,loopIndex,0,0);
        copyIndex3 = 0;
        ch = s___97c2d7ec[0];
        while (ch != '\0') {
          *(char *)(outCursor2 + copyIndex3) = ch;
          ch = ", "[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex3,param_5,param_6,2,loopIndex,0,0);
        copyIndex2 = 0;
        ch = s___scratch__97c2e5e0[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex2) = ch;
          ch = ", scratch; \n"[copyIndex2 + 1];
          copyIndex2 = copyIndex2 + 1;
        }
        loopIndex = loopIndex + 1;
        iVar6 = outCursor + copyIndex2;
      } while (loopIndex <= (int)(inst[6] >> 0xc & 3));
    }
    goto LAB_97c01788;
  case 0x3b:
    *stateFlags = *stateFlags | 0x1001;
    uVar8 = inst[8] >> 0xc & 3;
    if (uVar8 == 1) {
      copyIndex = 0;
      ch = s_SWZ_scratch__97c2e79c[0];
      while (ch != '\0') {
        *(char *)(outText + copyIndex) = ch;
        ch = "SWZ scratch, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      iVar6 = ((int (*)())_glpSourceType)(inst,outText + copyIndex,param_5,param_6,4,0,0);
      copyIndex = 0;
      ch = s___x__y__0__0__97c2e7ac[0];
      while (ch != '\0') {
        *(char *)(iVar6 + copyIndex) = ch;
        ch = ", x, y, 0, 0;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      copyIndex2 = 0;
      ch = s_DP3_scratch_x__scratch__97c2ea1c[0];
      while (ch != '\0') {
        *(char *)(iVar6 + copyIndex + copyIndex2) = ch;
        ch = "DP3 scratch.x, scratch, "[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,iVar6 + copyIndex + copyIndex2,param_5,param_6,3,0,0,0);
      copyIndex = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ";\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
    }
    else {
      if (uVar8 == 0) {
        copyIndex = 0;
        ch = s_MUL_scratch_x__97c2e6fc[0];
        while (ch != '\0') {
          *(char *)(outText + copyIndex) = ch;
          ch = "MUL scratch.x, "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
      }
      else if (uVar8 == 2) {
        copyIndex = 0;
        ch = s_DP3_scratch_x__97c2e734[0];
        while (ch != '\0') {
          *(char *)(outText + copyIndex) = ch;
          ch = "DP3 scratch.x, "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
      }
      else {
        copyIndex = 0;
        ch = s_DP4_scratch_x__97c2e744[0];
        while (ch != '\0') {
          *(char *)(outText + copyIndex) = ch;
          ch = "DP4 scratch.x, "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,param_5,param_6,4,0,0,0);
      copyIndex = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,3,0,0,0);
      copyIndex = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ";\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
    }
    copyIndex2 = 0;
    ch = s_SLT_scratch__scratch_x__kZERO__97c2ea38[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex + copyIndex2) = ch;
      ch = "SLT scratch, scratch.x, kZERO;\n"[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outCursor2 = outCursor + copyIndex + copyIndex2;
    copyIndex = 0;
    ch = s_MAD_scratch__scratch__kTWO___kON_97c2ea58[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "MAD scratch, scratch, kTWO, -kONE;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor2 = outCursor2 + copyIndex;
    copyIndex = 0;
    ch = s_MUL_97c2e4f0[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "MUL "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor2 + copyIndex,0,0,0);
    copyIndex = 0;
    ch = s___scratch__97c2e570[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", scratch, "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    iVar6 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,2,0,0,8);
    opOffsetOrTailLength = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(iVar6 + opOffsetOrTailLength) = ch;
      ch = ";\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 0x3c:
    if (shaderType == 0x8b30) {
      copyIndex = 0;
      ch = s_LRP_97c2e9e4[0];
      while (ch != '\0') {
        *(char *)(outText + copyIndex) = ch;
        ch = "LRP "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outText + copyIndex,0,0,0);
      copyIndex = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,2,0,0,8);
      copyIndex = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,3,0,0,8);
      copyIndex = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      iVar6 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,4,0,0,8);
      opOffsetOrTailLength = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        *(char *)(iVar6 + opOffsetOrTailLength) = ch;
        ch = ";\n"[opOffsetOrTailLength + 1];
        opOffsetOrTailLength = opOffsetOrTailLength + 1;
      }
    }
    else {
      *stateFlags = *stateFlags | 1;
      copyIndex = 0;
      ch = s_MAD_scratch__97c2e64c[0];
      while (ch != '\0') {
        *(char *)(outText + copyIndex) = ch;
        ch = "MAD scratch, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,param_5,param_6,4,0,0,8);
      copyIndex = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,2,0,0,9);
      copyIndex = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,4,0,0,8);
      copyIndex = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ";\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      copyIndex2 = 0;
      ch = s_MAD_97c2e644[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex + copyIndex2) = ch;
        ch = "MAD "[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor + copyIndex + copyIndex2,0,0,0);
      copyIndex = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,3,0,0,8);
      copyIndex = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      iVar6 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,2,0,0,8);
      opOffsetOrTailLength = 0;
      ch = s___scratch__97c2e620[0];
      while (ch != '\0') {
        *(char *)(iVar6 + opOffsetOrTailLength) = ch;
        ch = ", scratch;\n"[opOffsetOrTailLength + 1];
        opOffsetOrTailLength = opOffsetOrTailLength + 1;
      }
    }
    break;
  case 0x3d:
    *stateFlags = *stateFlags | 1;
    copyIndex = 0;
    ch = s_MAX_scratch__97c2e558[0];
    while (ch != '\0') {
      *(char *)(outText + copyIndex) = ch;
      ch = "MAX scratch, "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,param_5,param_6,2,0,0,8);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,3,0,0,8);
    copyIndex = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ";\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    copyIndex2 = 0;
    ch = s_MIN_97c2e568[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex + copyIndex2) = ch;
      ch = "MIN "[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor + copyIndex + copyIndex2,0,0,0);
    copyIndex = 0;
    ch = s___scratch__97c2e570[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", scratch, "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    iVar6 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,4,0,0,8);
    opOffsetOrTailLength = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(iVar6 + opOffsetOrTailLength) = ch;
      ch = ";\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 0x3e:
    if (shaderType == 0x8b30) {
      copyIndex = 0;
      ch = s_CMP_97c2f81c[0];
      while (ch != '\0') {
        *(char *)(outText + copyIndex) = ch;
        ch = "CMP "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outText + copyIndex,0,0,0);
      copyIndex = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,2,0,0,0);
      copyIndex = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,3,0,0,0);
      copyIndex = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      iVar6 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,4,0,0,0);
      opOffsetOrTailLength = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        *(char *)(iVar6 + opOffsetOrTailLength) = ch;
        ch = ";\n"[opOffsetOrTailLength + 1];
        opOffsetOrTailLength = opOffsetOrTailLength + 1;
      }
    }
    else {
      *stateFlags = *stateFlags | 0x1001;
      copyIndex = 0;
      ch = s_SLT_scratch__97c2e474[0];
      while (ch != '\0') {
        *(char *)(outText + copyIndex) = ch;
        ch = "SLT scratch, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,param_5,param_6,2,0,0,0);
      copyIndex = 0;
      ch = s___kZERO__97c2e484[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", kZERO;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = outCursor + copyIndex;
      if (shaderType == 0x8b30) {
        copyIndex = 0;
        ch = s_LRP_97c2e9e4[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex) = ch;
          ch = "LRP "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor + copyIndex,0,0,0);
        copyIndex = 0;
        ch = s___scratch__97c2e570[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex) = ch;
          ch = ", scratch, "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,3,0,0,0);
        copyIndex = 0;
        ch = s___97c2d7ec[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex) = ch;
          ch = ", "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        iVar6 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,4,0,0,0);
        opOffsetOrTailLength = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          *(char *)(iVar6 + opOffsetOrTailLength) = ch;
          ch = ";\n"[opOffsetOrTailLength + 1];
          opOffsetOrTailLength = opOffsetOrTailLength + 1;
        }
      }
      else {
        *stateFlags = *stateFlags | 0x1002;
        copyIndex = 0;
        ch = s_SUB_scratch1__kONE__scratch__97c2f668[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex) = ch;
          ch = "SUB scratch1, kONE, scratch;\n"[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        copyIndex2 = 0;
        ch = s_MUL_scratch__scratch__97c2e9ec[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex + copyIndex2) = ch;
          ch = "MUL scratch, scratch, "[copyIndex2 + 1];
          copyIndex2 = copyIndex2 + 1;
        }
        outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex + copyIndex2,param_5,param_6,3,0,0,0);
        copyIndex = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex) = ch;
          ch = ";\n"[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        copyIndex2 = 0;
        ch = s_MAD_97c2e644[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex + copyIndex2) = ch;
          ch = "MAD "[copyIndex2 + 1];
          copyIndex2 = copyIndex2 + 1;
        }
        outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor + copyIndex + copyIndex2,0,0,0);
        copyIndex = 0;
        ch = s___scratch1__97c2f688[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex) = ch;
          ch = ", scratch1, "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        iVar6 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,4,0,0,0);
        opOffsetOrTailLength = 0;
        ch = s___scratch__97c2e620[0];
        while (ch != '\0') {
          *(char *)(iVar6 + opOffsetOrTailLength) = ch;
          ch = ", scratch;\n"[opOffsetOrTailLength + 1];
          opOffsetOrTailLength = opOffsetOrTailLength + 1;
        }
      }
    }
    break;
  case 0x40:
    *stateFlags = *stateFlags | 0x1003;
    copyIndex = 0;
    ch = s_SUB_scratch__97c2e870[0];
    while (ch != '\0') {
      *(char *)(outText + copyIndex) = ch;
      ch = "SUB scratch, "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,param_5,param_6,3,0,0,8);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,2,0,0,8);
    copyIndex = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ";\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outPtr = (char *)(outCursor + copyIndex);
    if ((inst[8] >> 0xc & 3) == 0) {
      copyIndex = 0;
      ch = s_RCP_scratch1_x__scratch_x__97c2ea7c[0];
      while (ch != '\0') {
        outPtr[copyIndex] = ch;
        ch = "RCP scratch1.x, scratch.x;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outPtr = outPtr + copyIndex;
    }
    else {
      loopIndex = 0;
      do {
        copyIndex3 = 0;
        ch = s_RCP_scratch1__97c2ea98[0];
        while (ch != '\0') {
          outPtr[copyIndex3] = ch;
          ch = "RCP scratch1."[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        loopIndex = loopIndex + 1;
        outPtr = outPtr + copyIndex3;
        *outPtr = ((byte)loopIndex & 3) + 0x77;
        copyIndex3 = 0;
        ch = s___scratch__97c2eaa8[0];
        while (ch != '\0') {
          outPtr[copyIndex3 + 1] = ch;
          ch = ", scratch."[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        outPtr = outPtr + copyIndex3 + 1;
        *outPtr = ((byte)loopIndex & 3) + 0x77;
        copyIndex3 = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          outPtr[copyIndex3 + 1] = ch;
          ch = ";\n"[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        outPtr = outPtr + copyIndex3 + 1;
      } while (loopIndex <= (int)(inst[8] >> 0xc & 3));
    }
    copyIndex = 0;
    ch = s_SUB_scratch__97c2e870[0];
    while (ch != '\0') {
      outPtr[copyIndex] = ch;
      ch = "SUB scratch, "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outPtr + copyIndex,param_5,param_6,4,0,0,8);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,2,0,0,8);
    copyIndex = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ";\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    copyIndex2 = 0;
    ch = s_MUL_scratch__scratch__scratch1__97c2eab4[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex + copyIndex2) = ch;
      ch = "MUL scratch, scratch, scratch1;\n"[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outCursor2 = outCursor + copyIndex + copyIndex2;
    copyIndex = 0;
    ch = s_MAX_scratch__scratch__kZERO__97c2ead8[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "MAX scratch, scratch, kZERO;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor2 = outCursor2 + copyIndex;
    copyIndex = 0;
    ch = s_MIN_scratch__scratch__kONE__97c2eaf8[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "MIN scratch, scratch, kONE;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor2 = outCursor2 + copyIndex;
    copyIndex = 0;
    ch = s_ADD_scratch1__scratch__scratch__97c2eb18[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "ADD scratch1, scratch, scratch;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor2 = outCursor2 + copyIndex;
    copyIndex = 0;
    ch = s_SUB_scratch1__kTHREE__scratch1__97c2eb3c[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "SUB scratch1, kTHREE, scratch1;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor2 = outCursor2 + copyIndex;
    copyIndex = 0;
    ch = s_MUL_scratch__scratch__scratch__97c2eb60[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "MUL scratch, scratch, scratch;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor2 = outCursor2 + copyIndex;
    copyIndex = 0;
    ch = s_MUL_97c2e4f0[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "MUL "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    iVar6 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor2 + copyIndex,0,0,0);
    opOffsetOrTailLength = 0;
    ch = s___scratch__scratch1__97c2e4f8[0];
    while (ch != '\0') {
      *(char *)(iVar6 + opOffsetOrTailLength) = ch;
      ch = ", scratch, scratch1;\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 0x42:
  case 0x43:
  case 0x44:
    if (shaderType == 0x8b30) {
      uVar8 = stateFlags[1];
    }
    else {
      uVar8 = stateFlags[1];
      if ((uVar8 & 0x200000) == 0) {
        return 0xffffffff;
      }
      if (shaderType != 0x8b31) {
        return 0xffffffff;
      }
    }
    if (((uVar8 & 0x400000) == 0) || (shaderType != 0x8b30)) {
      if ((inst[8] >> 5 & 7) - 5 < 3) {
        return 0xffffffff;
      }
    }
    else {
      *stateFlags = *stateFlags | 0x1000000;
    }
    if (shaderType == 0x8b31) {
      *stateFlags = *stateFlags | 0x200000;
    }
    copyIndex9 = 0;
    mnemonic = *(char **)(PTR__ppstreamOpString_a7b7c108 + opOffsetOrTailLength);
    ch = *mnemonic;
    while (ch != '\0') {
      *(char *)(outText + copyIndex9) = ch;
      copyIndex9 = copyIndex9 + 1;
      ch = mnemonic[copyIndex9];
    }
    copyIndex = 0;
    ch = s__97c291c0[0];
    while (ch != '\0') {
      *(char *)(outText + copyIndex9 + copyIndex) = ch;
      ch = " "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outText + copyIndex9 + copyIndex,0,0,0);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,2,0,0,0);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    iVar6 = ((int (*)())_glpWriteTextureOperand_97bf37b4)(inst,outCursor + copyIndex,4,param_11);
    opOffsetOrTailLength = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(iVar6 + opOffsetOrTailLength) = ch;
      ch = ";\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 0x48:
    if (shaderType != 0x8b31) {
      return 0xffffffff;
    }
    copyIndex = 0;
    ch = s_ARL_97c2f7e4[0];
    while (ch != '\0') {
      *(char *)(outText + copyIndex) = ch;
      ch = "ARL "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outText + copyIndex,0,0,0);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    iVar6 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,2,0,0,8);
    opOffsetOrTailLength = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(iVar6 + opOffsetOrTailLength) = ch;
      ch = ";\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 0x4d:
    iVar6 = 0;
    iVar11 = iVar6;
    ch = s__97c26c38[0];
    if (s__97c26c38[0] != '\0') {
      do {
        *(char *)(outText + iVar11) = ch;
        iVar6 = iVar11 + 1;
        ch = "\n"[iVar11 + 1];
        iVar11 = iVar6;
      } while (ch != '\0');
      uVar8 = *inst;
    }
    iVar6 = outText + iVar6;
    goto LAB_97c0178c;
  case 0x4f:
    copyIndex9 = 0;
    mnemonic = *(char **)(PTR__ppstreamOpString_a7b7c108 + opOffsetOrTailLength);
    ch = *mnemonic;
    while (ch != '\0') {
      *(char *)(outText + copyIndex9) = ch;
      copyIndex9 = copyIndex9 + 1;
      ch = mnemonic[copyIndex9];
    }
    copyIndex = 0;
    ch = s__97c291c0[0];
    while (ch != '\0') {
      *(char *)(outText + copyIndex9 + copyIndex) = ch;
      ch = " "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    iVar6 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex9 + copyIndex,param_5,param_6,2,0,0,8);
    opOffsetOrTailLength = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(iVar6 + opOffsetOrTailLength) = ch;
      ch = ";\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 0x50:
    if ((stateFlags[1] & 0x400000) == 0) {
      return 0xffffffff;
    }
    if (shaderType != 0x8b30) {
      return 0xffffffff;
    }
    *stateFlags = *stateFlags | 0x400000;
    copyIndex = 0;
    ch = s_DDX_97c2f7ec[0];
    while (ch != '\0') {
      *(char *)(outText + copyIndex) = ch;
      ch = "DDX "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outText + copyIndex,0,0,0);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    iVar6 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,2,0,0,8);
    opOffsetOrTailLength = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(iVar6 + opOffsetOrTailLength) = ch;
      ch = ";\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 0x51:
    if ((stateFlags[1] & 0x400000) == 0) {
      return 0xffffffff;
    }
    if (shaderType != 0x8b30) {
      return 0xffffffff;
    }
    *stateFlags = *stateFlags | 0x400000;
    copyIndex = 0;
    ch = s_DDY_97c2f7f4[0];
    while (ch != '\0') {
      *(char *)(outText + copyIndex) = ch;
      ch = "DDY "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outText + copyIndex,0,0,0);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    iVar6 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,2,0,0,8);
    opOffsetOrTailLength = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(iVar6 + opOffsetOrTailLength) = ch;
      ch = ";\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 0x57:
    if ((stateFlags[1] & 0x800000) == 0) {
      return 0xffffffff;
    }
    if (shaderType != 0x8b30) {
      return 0xffffffff;
    }
    *stateFlags = *stateFlags | 0x800000;
    copyIndex = 0;
    ch = s_REP_97c2f824[0];
    while (ch != '\0') {
      *(char *)(outText + copyIndex) = ch;
      ch = "REP "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    iVar6 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,param_5,param_6,2,0,0,0);
    opOffsetOrTailLength = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(iVar6 + opOffsetOrTailLength) = ch;
      ch = ";\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 0x5b:
    if ((stateFlags[1] & 0x800000) == 0) {
      return 0xffffffff;
    }
    if (shaderType != 0x8b30) {
      return 0xffffffff;
    }
    *stateFlags = *stateFlags | 0x800000;
    copyIndex3 = 0;
    ch = s_ENDREP__97c2f82c[0];
    while (ch != '\0') {
      *(char *)(outText + copyIndex3) = ch;
      ch = "ENDREP;\n"[copyIndex3 + 1];
      copyIndex3 = copyIndex3 + 1;
    }
    iVar6 = outText + copyIndex3;
    goto LAB_97c01788;
  case 0x68:
    *stateFlags = *stateFlags | 0x1007;
    uVar8 = inst[2] >> 10 & 3;
    if (uVar8 == 1) {
      copyIndex = 0;
      ch = s_MUL_scratch_xy__97c2e510[0];
      while (ch != '\0') {
        *(char *)(outText + copyIndex) = ch;
        ch = "MUL scratch.xy, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,param_5,param_6,2,0,0,0);
      copyIndex = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor2 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,3,0,0,0);
      copyIndex3 = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex3) = ch;
        ch = ";\n"[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      copyIndex = 0;
      ch = s_MUL_scratch__scratch_x__scratch__97c2f6b4[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex3 + copyIndex) = ch;
        ch = "MUL scratch, scratch.x, scratch.y;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor3 = outCursor2 + copyIndex3 + copyIndex;
    }
    else {
      if (uVar8 == 0) {
        copyIndex = 0;
        ch = s_MUL_scratch__97c2e62c[0];
        while (ch != '\0') {
          *(char *)(outText + copyIndex) = ch;
          ch = "MUL scratch, "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
LAB_97c00620:
        iVar11 = outText + copyIndex;
      }
      else {
        if (uVar8 == 2) {
          copyIndex = 0;
          ch = s_DP3_scratch__97c2f6d8[0];
          while (ch != '\0') {
            *(char *)(outText + copyIndex) = ch;
            ch = "DP3 scratch, "[copyIndex + 1];
            copyIndex = copyIndex + 1;
          }
          goto LAB_97c00620;
        }
        iVar11 = outText;
        if (uVar8 == 3) {
          copyIndex = 0;
          ch = s_DP4_scratch__97c2f6e8[0];
          while (ch != '\0') {
            *(char *)(outText + copyIndex) = ch;
            ch = "DP4 scratch, "[copyIndex + 1];
            copyIndex = copyIndex + 1;
          }
          goto LAB_97c00620;
        }
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,iVar11,param_5,param_6,2,0,0,0);
      copyIndex = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor3 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,3,0,0,0);
    }
    copyIndex3 = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(outCursor3 + copyIndex3) = ch;
      ch = ";\n"[copyIndex3 + 1];
      copyIndex3 = copyIndex3 + 1;
    }
    copyIndex2 = 0;
    ch = s_MAD_scratch1__scratch___scratch__97c2f6f8[0];
    while (ch != '\0') {
      *(char *)(outCursor3 + copyIndex3 + copyIndex2) = ch;
      ch = "MAD scratch1, scratch, -scratch, kONE;\n"[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outCursor2 = outCursor3 + copyIndex3 + copyIndex2;
    copyIndex = 0;
    ch = s_MUL_scratch2__97c2ef7c[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "MUL scratch2, "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex,param_5,param_6,4,0,0,0);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,4,0,0,0);
    copyIndex = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ";\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    copyIndex2 = 0;
    ch = s_MAD_scratch1__scratch2___scratch_97c2f720[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex + copyIndex2) = ch;
      ch = "MAD scratch1, scratch2, -scratch1, kONE;\n"[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outCursor2 = outCursor + copyIndex + copyIndex2;
    copyIndex = 0;
    ch = s_RSQ_scratch2__scratch1_x__97c2f74c[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "RSQ scratch2, scratch1.x;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor2 = outCursor2 + copyIndex;
    copyIndex = 0;
    ch = s_RCP_scratch2__scratch2_x__97c2f768[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "RCP scratch2, scratch2.x;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor2 = outCursor2 + copyIndex;
    copyIndex = 0;
    ch = s_MAD_scratch2__scratch_x__97c2f784[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "MAD scratch2, scratch.x, "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex,param_5,param_6,4,0,0,8);
    copyIndex = 0;
    ch = s___scratch2_x__97c2f7a0[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", scratch2.x;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    copyIndex2 = 0;
    ch = s_MUL_scratch2__97c2ef7c[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex + copyIndex2) = ch;
      ch = "MUL scratch2, "[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex + copyIndex2,param_5,param_6,3,0,0,8);
    copyIndex = 0;
    ch = s___scratch2_x__97c2f7a0[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", scratch2.x;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    copyIndex2 = 0;
    ch = s_MAD_scratch__97c2e64c[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex + copyIndex2) = ch;
      ch = "MAD scratch, "[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex + copyIndex2,param_5,param_6,2,0,0,8);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,4,0,0,8);
    copyIndex = 0;
    ch = s____scratch2__97c2f7b0[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", -scratch2;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    copyIndex2 = 0;
    ch = s_SGE_scratch1__scratch1_x__kZERO__97c2f7c0[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex + copyIndex2) = ch;
      ch = "SGE scratch1, scratch1.x, kZERO;\n"[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outCursor2 = outCursor + copyIndex + copyIndex2;
    copyIndex = 0;
    ch = s_MUL_97c2e4f0[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "MUL "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    iVar6 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor2 + copyIndex,0,0,0);
    opOffsetOrTailLength = 0;
    ch = s___scratch__scratch1__97c2e4f8[0];
    while (ch != '\0') {
      *(char *)(iVar6 + opOffsetOrTailLength) = ch;
      ch = ", scratch, scratch1;\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 0x6c:
    uVar9 = inst[1] >> 0x17 & 7;
    if (uVar9 == 4) {
      *stateFlags = *stateFlags | 0x1001;
      copyIndex = 0;
      ch = s_ABS_scratch__97c2e448[0];
      while (ch != '\0') {
        *(char *)(outText + copyIndex) = ch;
        ch = "ABS scratch, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,param_5,param_6,2,0,0,8);
      copyIndex = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ";\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      copyIndex2 = 0;
      ch = s_SLT_97c2e458[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex + copyIndex2) = ch;
        ch = "SLT "[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      iVar6 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor + copyIndex + copyIndex2,0,0,0);
      opOffsetOrTailLength = 0;
      ch = s____scratch__kZERO__97c2e460[0];
      while (ch != '\0') {
        *(char *)(iVar6 + opOffsetOrTailLength) = ch;
        ch = ", -scratch, kZERO;\n"[opOffsetOrTailLength + 1];
        opOffsetOrTailLength = opOffsetOrTailLength + 1;
      }
    }
    else if (uVar9 == 3) {
      *stateFlags = *stateFlags | 0x1003;
      copyIndex = 0;
      ch = s_SLT_scratch__97c2e474[0];
      while (ch != '\0') {
        *(char *)(outText + copyIndex) = ch;
        ch = "SLT scratch, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,param_5,param_6,2,0,0,8);
      copyIndex = 0;
      ch = s___kZERO__97c2e484[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", kZERO;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      copyIndex2 = 0;
      ch = s_SLT_scratch1__97c2e490[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex + copyIndex2) = ch;
        ch = "SLT scratch1, "[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex + copyIndex2,param_5,param_6,2,0,0,9);
      copyIndex = 0;
      ch = s___kZERO__97c2e484[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", kZERO;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      copyIndex2 = 0;
      ch = s_ADD_scratch___scratch__scratch1__97c2e4a0[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex + copyIndex2) = ch;
        ch = "ADD scratch, -scratch, scratch1;\n"[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      outCursor2 = outCursor + copyIndex + copyIndex2;
      copyIndex = 0;
      ch = s_ABS_scratch1__97c2e4c4[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "ABS scratch1, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex,param_5,param_6,2,0,0,8);
      copyIndex = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ";\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      copyIndex2 = 0;
      ch = s_FLR_scratch1__scratch1__97c2e4d4[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex + copyIndex2) = ch;
        ch = "FLR scratch1, scratch1;\n"[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      outCursor2 = outCursor + copyIndex + copyIndex2;
      copyIndex = 0;
      ch = s_MUL_97c2e4f0[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "MUL "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      iVar6 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor2 + copyIndex,0,0,0);
      opOffsetOrTailLength = 0;
      ch = s___scratch__scratch1__97c2e4f8[0];
      while (ch != '\0') {
        *(char *)(iVar6 + opOffsetOrTailLength) = ch;
        ch = ", scratch, scratch1;\n"[opOffsetOrTailLength + 1];
        opOffsetOrTailLength = opOffsetOrTailLength + 1;
      }
    }
    else {
      if (uVar9 != 1) goto LAB_97c0178c;
      copyIndex = 0;
      ch = s_MOV_97c2e430[0];
      while (ch != '\0') {
        *(char *)(outText + copyIndex) = ch;
        ch = "MOV "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outText + copyIndex,0,0,0);
      copyIndex = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      iVar6 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,2,0,0,8);
      opOffsetOrTailLength = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        *(char *)(iVar6 + opOffsetOrTailLength) = ch;
        ch = ";\n"[opOffsetOrTailLength + 1];
        opOffsetOrTailLength = opOffsetOrTailLength + 1;
      }
    }
    break;
  case 0x6d:
    if ((inst[2] >> 0x11 & 7) != 1) {
      return 0xffffffff;
    }
    *stateFlags = *stateFlags | 0x1001;
    copyIndex = 0;
    ch = s_SUB_scratch__kSEL_97c2f654[0];
    while (ch != '\0') {
      *(char *)(outText + copyIndex) = ch;
      ch = "SUB scratch, kSEL"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteComponentsWithDestinationSwizzle)(inst,outText + copyIndex);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,3,0,0,0);
    copyIndex = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ";\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = outCursor + copyIndex;
    if (shaderType == 0x8b31) {
      *stateFlags = *stateFlags | 0x1002;
      copyIndex = 0;
      ch = s_ABS_scratch__scratch__97c2e8c0[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = "ABS scratch, scratch;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      copyIndex2 = 0;
      ch = s_SGE_scratch___scratch__kZERO__97c2f634[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex + copyIndex2) = ch;
        ch = "SGE scratch, -scratch, kZERO;\n"[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      outCursor2 = outCursor + copyIndex + copyIndex2;
      copyIndex = 0;
      ch = s_SUB_scratch1__kONE__scratch__97c2f668[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "SUB scratch1, kONE, scratch;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor2 = outCursor2 + copyIndex;
      copyIndex = 0;
      ch = s_MUL_scratch__scratch__97c2e9ec[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "MUL scratch, scratch, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex,param_5,param_6,2,0,0,0);
      copyIndex = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ";\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      copyIndex2 = 0;
      ch = s_MAD_97c2e644[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex + copyIndex2) = ch;
        ch = "MAD "[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor + copyIndex + copyIndex2,0,0,0);
      copyIndex = 0;
      ch = s___scratch1__97c2f688[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", scratch1, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      iVar6 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor + copyIndex,0,0,0x40);
      opOffsetOrTailLength = 0;
      ch = s___scratch__97c2e620[0];
      while (ch != '\0') {
        *(char *)(iVar6 + opOffsetOrTailLength) = ch;
        ch = ", scratch;\n"[opOffsetOrTailLength + 1];
        opOffsetOrTailLength = opOffsetOrTailLength + 1;
      }
    }
    else {
      copyIndex = 0;
      ch = s_ABS_SAT_scratch__scratch__97c2f698[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = "ABS_SAT scratch, scratch;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      copyIndex2 = 0;
      ch = s_LRP_97c2e9e4[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex + copyIndex2) = ch;
        ch = "LRP "[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor + copyIndex + copyIndex2,0,0,0);
      copyIndex = 0;
      ch = s___scratch__97c2e570[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", scratch, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor + copyIndex,0,0,0x40);
      copyIndex = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      iVar6 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,param_5,param_6,2,0,0,0);
      opOffsetOrTailLength = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        *(char *)(iVar6 + opOffsetOrTailLength) = ch;
        ch = ";\n"[opOffsetOrTailLength + 1];
        opOffsetOrTailLength = opOffsetOrTailLength + 1;
      }
    }
    break;
  case 0x6f:
    *stateFlags = *stateFlags | 0x20000;
    uVar8 = inst[2];
    loopIndex = 0;
    uVar9 = uVar8 >> 0xd & 0xf;
    do {
      if ((uVar9 & 1) != 0) {
        copyIndex2 = 0;
        ch = s_POW_97c2e5a4[0];
        while (ch != '\0') {
          *(char *)(iVar6 + copyIndex2) = ch;
          ch = "POW "[copyIndex2 + 1];
          copyIndex2 = copyIndex2 + 1;
        }
        outCursor2 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,iVar6 + copyIndex2,0,loopIndex,2);
        copyIndex3 = 0;
        ch = s___kE__97c2e5ac[0];
        while (ch != '\0') {
          *(char *)(outCursor2 + copyIndex3) = ch;
          ch = ", kE, "[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        outCursor6 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex3,param_5,param_6,2,0,loopIndex,10)
        ;
        copyIndex2 = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          *(char *)(outCursor6 + copyIndex2) = ch;
          ch = ";\n"[copyIndex2 + 1];
          copyIndex2 = copyIndex2 + 1;
        }
        uVar8 = inst[2];
        iVar6 = outCursor6 + copyIndex2;
      }
      loopIndex = loopIndex + 1;
      uVar9 = (int)uVar9 >> 1;
    } while (loopIndex <= (int)(uVar8 >> 10 & 3));
    goto LAB_97c01788;
  case 0x70:
    *stateFlags = *stateFlags | 0x20001;
    uVar8 = inst[2];
    loopIndex = 0;
    uVar9 = uVar8 >> 0xd & 0xf;
    do {
      if ((uVar9 & 1) != 0) {
        copyIndex2 = 0;
        ch = s_LG2_scratch__97c2e5b4[0];
        while (ch != '\0') {
          *(char *)(iVar6 + copyIndex2) = ch;
          ch = "LG2 scratch, "[copyIndex2 + 1];
          copyIndex2 = copyIndex2 + 1;
        }
        outCursor7 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,iVar6 + copyIndex2,param_5,param_6,2,0,loopIndex,10)
        ;
        copyIndex3 = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          *(char *)(outCursor7 + copyIndex3) = ch;
          ch = ";\n"[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        copyIndex4 = 0;
        ch = s_MUL_97c2e4f0[0];
        while (ch != '\0') {
          *(char *)(outCursor7 + copyIndex3 + copyIndex4) = ch;
          ch = "MUL "[copyIndex4 + 1];
          copyIndex4 = copyIndex4 + 1;
        }
        outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor7 + copyIndex3 + copyIndex4,0,loopIndex,2);
        copyIndex2 = 0;
        ch = s___scratch__k1_OVER_LOG2_E__97c2e5c4[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex2) = ch;
          ch = ", scratch, k1_OVER_LOG2_E;\n"[copyIndex2 + 1];
          copyIndex2 = copyIndex2 + 1;
        }
        uVar8 = inst[2];
        iVar6 = outCursor + copyIndex2;
      }
      loopIndex = loopIndex + 1;
      uVar9 = (int)uVar9 >> 1;
    } while (loopIndex <= (int)(uVar8 >> 10 & 3));
    goto LAB_97c01788;
  }
  iVar6 = iVar6 + opOffsetOrTailLength;
LAB_97c01788:
  uVar8 = *inst;
LAB_97c0178c:
  *outWordCount = (uVar8 >> 0x1d) + 1;
  *outTextLength = iVar6 - outText;
  return 0;
}

/* _isParamArrayStart_97c017c0 @ 0x97c017c0 (96 bytes) */
int _isParamArrayStart_97c017c0(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  uint *param_3;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x38);
  iVar1 = param_1 + *(int *)(param_1 + 0x3c) * 8;
  if ((iVar3 != 0) && (iVar2 = 0, 0 < iVar3)) {
    do {
      if ((*(uint *)(iVar1 + iVar2 * 8) & 0xffff) == param_2) {
        *param_3 = (uint)*(ushort *)(iVar2 * 8 + iVar1 + 6);
        return 1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar3);
  }
  return 0;
}

/* _glpPPShaderToProgramString @ 0x97c01820 (15972 bytes) */
int _glpPPShaderToProgramString(shader, param_2, param_3)
  int *shader;
  undefined4 param_2;
  uint param_3;
{
  int copyIndex10;
  int copyIndex9;
  int copyEnd;
  int copyEnd3;
  int copyEnd4;
  int copyEnd6;
  int copyEnd5;
  uint loopIndex4;
  int loopIndex;
  int loopIndex3;
  int loopIndex2;
  int allocation2;
  int copyLength8;
  int copyIndex;
  int copyLength;
  int copyIndex6;
  int copyLength3;
  int copyIndex3;
  int copyLength5;
  int copyIndex4;
  int copyLength10;
  int copyLength7;
  int copyIndex8;
  int copyLength9;
  int copyIndex5;
  int copyLength4;
  int copyIndex2;
  int copyLength2;
  int copyIndex7;
  char ch;
  uint uVar1;
  int iVar3;
  int iVar4;
  int iVar5;
  uint *puVar6;
  int iVar7;
  int copyEnd2;
  char *pcVar9;
  char *allocation;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 uVar11;
  undefined4 extraout_r4_01;
  int copyLength6;
  int iVar13;
  int *piVar14;
  int *piVar15;
  int iVar16;
  int iVar17;
  int *piVar18;
  int iVar19;
  char *pcVar20;
  int iVar21;
  char *pcVar22;
  uint uVar23;
  float *pfVar24;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  undefined8 uVar25;
  double in_stack_ffffff48;
  double in_stack_ffffff50;
  double in_stack_ffffff58;
  double in_stack_ffffff60;
  double in_stack_ffffff68;
  uint local_70;
  uint local_6c;
  int local_68;
  char *local_64;
  char *local_60;
  uint local_5c;
  int local_58;
  int local_54;
  undefined4 local_50;
  char *local_4c;
  char *local_48 [2];
  
  local_68 = 0x1000;
  local_50 = 1;
  local_70 = 0;
  local_6c = 0;
  local_64 = (char *)_malloc(0x1000);
  iVar13 = 0;
  iVar16 = 0;
  piVar15 = (int *)0x0;
  piVar14 = (int *)0x0;
  if (local_64 == (char *)0x0) {
    return 0;
  }
  iVar17 = *shader;
  if ((param_3 & 2) == 0) {
    if ((param_3 & 1) != 0) {
      local_6c = local_6c | 0x100000;
    }
  }
  else {
    local_6c = local_6c | 0x300000;
  }
  if ((param_3 & 8) == 0) {
    if ((param_3 & 4) != 0) {
      local_6c = local_6c | 0x400000;
    }
  }
  else {
    local_6c = local_6c | 0xc00000;
  }
  iVar19 = shader[6];
  uVar11 = extraout_r4;
  local_60 = local_64;
  if (iVar19 != 0) {
    ch = 'A';
    copyIndex8 = 0;
    do {
      local_64[copyIndex8] = ch;
      copyLength10 = copyIndex8 + 1;
      ch = "ADDRESS adr0"[copyIndex8 + 1];
      copyIndex8 = copyLength10;
    } while (ch != '\0');
    iVar21 = 1;
    local_60 = local_64 + copyLength10;
    if (1 < iVar19) {
      do {
        ch = ',';
        copyIndex4 = 0;
        do {
          local_60[copyIndex4] = ch;
          copyLength5 = copyIndex4 + 1;
          ch = ", adr"[copyIndex4 + 1];
          copyIndex4 = copyLength5;
        } while (ch != '\0');
        local_60 = local_60 + copyLength5;
        iVar3 = iVar21 + 1;
        copyEnd6 = ((int (*)())_ncpy_97bf2850)(local_60,iVar21);
        local_60 = local_60 + copyEnd6;
        iVar21 = iVar3;
      } while (iVar3 < iVar19);
    }
    ch = ';';
    copyIndex5 = 0;
    do {
      local_60[copyIndex5] = ch;
      copyLength7 = copyIndex5 + 1;
      ch = ";\n"[copyIndex5 + 1];
      copyIndex5 = copyLength7;
    } while (ch != '\0');
    local_60 = local_60 + copyLength7;
    uVar25 = ((int (*)())_adjustAllocation_97bf27d4)(&local_68,&local_64,&local_60);
    uVar11 = (undefined4)uVar25;
    pcVar9 = local_64;
    if ((int)((ulonglong)uVar25 >> 0x20) == 0) goto LAB_97c04d50;
    ch = '\n';
    copyIndex5 = 0;
    do {
      local_60[copyIndex5] = ch;
      copyLength7 = copyIndex5 + 1;
      ch = "\n"[copyIndex5 + 1];
      copyIndex5 = copyLength7;
    } while (ch != '\0');
    local_60 = local_60 + copyLength7;
  }
  iVar19 = shader[4];
  loopIndex2 = 0;
  if (0 < iVar19) {
    piVar18 = shader + shader[5] * 2 + 1;
    do {
      ch = 'T';
      copyIndex4 = 0;
      do {
        local_60[copyIndex4] = ch;
        copyLength5 = copyIndex4 + 1;
        ch = "TEMP "[copyIndex4 + 1];
        copyIndex4 = copyLength5;
      } while (ch != '\0');
      ch = 't';
      copyIndex4 = 0;
      do {
        local_60[copyIndex4 + copyLength5] = ch;
        copyLength3 = copyIndex4 + 1;
        ch = "tmp"[copyIndex4 + 1];
        copyIndex4 = copyLength3;
      } while (ch != '\0');
      local_60 = local_60 + copyLength3 + copyLength5;
      copyEnd3 = ((int (*)())_ncpy_97bf2850)(local_60,(uint)(ushort)*piVar18);
      ch = ';';
      copyIndex4 = 0;
      do {
        local_60[copyIndex4 + copyEnd3] = ch;
        copyLength3 = copyIndex4 + 1;
        ch = ";\n"[copyIndex4 + 1];
        copyIndex4 = copyLength3;
      } while (ch != '\0');
      local_60 = local_60 + copyLength3 + copyEnd3;
      uVar25 = ((int (*)())_adjustAllocation_97bf27d4)(&local_68,&local_64,&local_60);
      uVar11 = (undefined4)uVar25;
      pcVar9 = local_64;
      if ((int)((ulonglong)uVar25 >> 0x20) == 0) goto LAB_97c04d50;
      loopIndex2 = loopIndex2 + 1;
      piVar18 = piVar18 + 2;
    } while (loopIndex2 < iVar19);
  }
  if (iVar19 != 0) {
    ch = '\n';
    copyIndex5 = 0;
    do {
      local_60[copyIndex5] = ch;
      copyLength7 = copyIndex5 + 1;
      ch = "\n"[copyIndex5 + 1];
      copyIndex5 = copyLength7;
    } while (ch != '\0');
    local_60 = local_60 + copyLength7;
  }
  iVar21 = shader[8];
  loopIndex3 = 0;
  iVar19 = shader[9];
  if (0 < iVar21) {
    do {
      uVar23 = (uint)shader[iVar19 * 2 + loopIndex3 * 2] >> 0x10 & 0xf;
      if (uVar23 == 0) goto LAB_97c0239c;
      ch = 'A';
      copyIndex3 = 0;
      do {
        local_60[copyIndex3] = ch;
        copyLength3 = copyIndex3 + 1;
        ch = "ATTRIB att"[copyIndex3 + 1];
        copyIndex3 = copyLength3;
      } while (ch != '\0');
      local_60 = local_60 + copyLength3;
      copyEnd3 = ((int (*)())_ncpy_97bf2850)(local_60,(uint)*(ushort *)((int)shader + loopIndex3 * 8 + iVar19 * 8 + 6));
      local_60 = local_60 + copyEnd3;
      if (iVar17 == 0x8b30) {
        ch = ' ';
        copyIndex3 = 0;
        do {
          local_60[copyIndex3] = ch;
          copyLength3 = copyIndex3 + 1;
          ch = " = fragment."[copyIndex3 + 1];
          copyIndex3 = copyLength3;
        } while (ch != '\0');
LAB_97c01cf4:
        local_60 = local_60 + copyLength3;
      }
      else if (iVar17 == 0x8b31) {
        ch = ' ';
        copyIndex3 = 0;
        do {
          local_60[copyIndex3] = ch;
          copyLength3 = copyIndex3 + 1;
          ch = " = vertex."[copyIndex3 + 1];
          copyIndex3 = copyLength3;
        } while (ch != '\0');
        goto LAB_97c01cf4;
      }
      switch(uVar23) {
      default:
        goto switchD_97c01d20_caseD_0;
      case 1:
        ch = 'p';
        copyIndex3 = 0;
        do {
          local_60[copyIndex3] = ch;
          copyLength3 = copyIndex3 + 1;
          ch = "position"[copyIndex3 + 1];
          copyIndex3 = copyLength3;
        } while (ch != '\0');
        break;
      case 2:
        ch = 'c';
        copyIndex3 = 0;
        do {
          local_60[copyIndex3] = ch;
          copyLength3 = copyIndex3 + 1;
          ch = "color.primary"[copyIndex3 + 1];
          copyIndex3 = copyLength3;
        } while (ch != '\0');
        break;
      case 3:
        ch = 'c';
        copyIndex3 = 0;
        do {
          local_60[copyIndex3] = ch;
          copyLength3 = copyIndex3 + 1;
          ch = "color.secondary"[copyIndex3 + 1];
          copyIndex3 = copyLength3;
        } while (ch != '\0');
        break;
      case 4:
        ch = 'n';
        copyIndex3 = 0;
        do {
          local_60[copyIndex3] = ch;
          copyLength3 = copyIndex3 + 1;
          ch = "normal"[copyIndex3 + 1];
          copyIndex3 = copyLength3;
        } while (ch != '\0');
        break;
      case 5:
        ch = 'f';
        copyIndex3 = 0;
        do {
          local_60[copyIndex3] = ch;
          copyLength3 = copyIndex3 + 1;
          ch = "fogcoord"[copyIndex3 + 1];
          copyIndex3 = copyLength3;
        } while (ch != '\0');
        break;
      case 6:
        ch = 'w';
        copyIndex3 = 0;
        do {
          local_60[copyIndex3] = ch;
          copyLength3 = copyIndex3 + 1;
          ch = "weight["[copyIndex3 + 1];
          copyIndex3 = copyLength3;
        } while (ch != '\0');
        local_60 = local_60 + copyLength3;
        copyEnd3 = ((int (*)())_ncpy_97bf2850)(local_60,shader[iVar19 * 2 + loopIndex3 * 2] & 0x1f);
        ch = ']';
        local_60 = local_60 + copyEnd3;
        copyIndex3 = 0;
        do {
          local_60[copyIndex3] = ch;
          copyLength3 = copyIndex3 + 1;
          ch = "]"[copyIndex3 + 1];
          copyIndex3 = copyLength3;
        } while (ch != '\0');
        goto LAB_97c02100;
      case 7:
        ch = 't';
        copyIndex3 = 0;
        do {
          local_60[copyIndex3] = ch;
          copyLength3 = copyIndex3 + 1;
          ch = "texcoord["[copyIndex3 + 1];
          copyIndex3 = copyLength3;
        } while (ch != '\0');
        local_60 = local_60 + copyLength3;
        copyEnd3 = ((int (*)())_ncpy_97bf2850)(local_60,shader[iVar19 * 2 + loopIndex3 * 2] & 0x1f);
        ch = ']';
        local_60 = local_60 + copyEnd3;
        copyIndex3 = 0;
        do {
          local_60[copyIndex3] = ch;
          copyLength3 = copyIndex3 + 1;
          ch = "]"[copyIndex3 + 1];
          copyIndex3 = copyLength3;
        } while (ch != '\0');
        goto LAB_97c02100;
      case 8:
        ch = 'm';
        copyIndex3 = 0;
        do {
          local_60[copyIndex3] = ch;
          copyLength3 = copyIndex3 + 1;
          ch = "matrixindex["[copyIndex3 + 1];
          copyIndex3 = copyLength3;
        } while (ch != '\0');
        local_60 = local_60 + copyLength3;
        copyEnd3 = ((int (*)())_ncpy_97bf2850)(local_60,shader[iVar19 * 2 + loopIndex3 * 2] & 0x1f);
        ch = ']';
        local_60 = local_60 + copyEnd3;
        copyIndex3 = 0;
        do {
          local_60[copyIndex3] = ch;
          copyLength3 = copyIndex3 + 1;
          ch = "]"[copyIndex3 + 1];
          copyIndex3 = copyLength3;
        } while (ch != '\0');
        goto LAB_97c02100;
      case 9:
        ch = 'a';
        copyIndex3 = 0;
        do {
          local_60[copyIndex3] = ch;
          copyLength3 = copyIndex3 + 1;
          ch = "attrib["[copyIndex3 + 1];
          copyIndex3 = copyLength3;
        } while (ch != '\0');
        local_60 = local_60 + copyLength3;
        copyEnd3 = ((int (*)())_ncpy_97bf2850)(local_60,shader[iVar19 * 2 + loopIndex3 * 2] & 0x1f);
        ch = ']';
        local_60 = local_60 + copyEnd3;
        copyIndex3 = 0;
        do {
          local_60[copyIndex3] = ch;
          copyLength3 = copyIndex3 + 1;
          ch = "]"[copyIndex3 + 1];
          copyIndex3 = copyLength3;
        } while (ch != '\0');
LAB_97c02100:
        local_60 = local_60 + copyLength3;
        goto switchD_97c01d20_caseD_0;
      case 10:
        ch = 'm';
        copyIndex3 = 0;
        do {
          local_60[copyIndex3] = ch;
          copyLength3 = copyIndex3 + 1;
          ch = "material."[copyIndex3 + 1];
          copyIndex3 = copyLength3;
        } while (ch != '\0');
        local_60 = local_60 + copyLength3;
        if ((shader[iVar19 * 2 + loopIndex3 * 2] & 1U) == 0) {
          ch = 'f';
          copyIndex3 = 0;
          do {
            local_60[copyIndex3] = ch;
            copyLength3 = copyIndex3 + 1;
            ch = "front."[copyIndex3 + 1];
            copyIndex3 = copyLength3;
          } while (ch != '\0');
LAB_97c021d8:
          local_60 = local_60 + copyLength3;
        }
        else if ((shader[iVar19 * 2 + loopIndex3 * 2] & 1U) == 1) {
          ch = 'b';
          copyIndex3 = 0;
          do {
            local_60[copyIndex3] = ch;
            copyLength3 = copyIndex3 + 1;
            ch = "back."[copyIndex3 + 1];
            copyIndex3 = copyLength3;
          } while (ch != '\0');
          goto LAB_97c021d8;
        }
        switch((uint)shader[iVar19 * 2 + loopIndex3 * 2] >> 0xc & 0xf) {
        case 0:
          ch = 'a';
          copyIndex3 = 0;
          do {
            local_60[copyIndex3] = ch;
            copyLength3 = copyIndex3 + 1;
            ch = "ambient"[copyIndex3 + 1];
            copyIndex3 = copyLength3;
          } while (ch != '\0');
          break;
        case 1:
          ch = 'd';
          copyIndex3 = 0;
          do {
            local_60[copyIndex3] = ch;
            copyLength3 = copyIndex3 + 1;
            ch = "diffuse"[copyIndex3 + 1];
            copyIndex3 = copyLength3;
          } while (ch != '\0');
          break;
        case 2:
          ch = 's';
          copyIndex3 = 0;
          do {
            local_60[copyIndex3] = ch;
            copyLength3 = copyIndex3 + 1;
            ch = "specular"[copyIndex3 + 1];
            copyIndex3 = copyLength3;
          } while (ch != '\0');
          break;
        case 3:
          ch = 'e';
          copyIndex3 = 0;
          do {
            local_60[copyIndex3] = ch;
            copyLength3 = copyIndex3 + 1;
            ch = "emission"[copyIndex3 + 1];
            copyIndex3 = copyLength3;
          } while (ch != '\0');
          break;
        case 4:
          ch = 's';
          copyIndex3 = 0;
          do {
            local_60[copyIndex3] = ch;
            copyLength3 = copyIndex3 + 1;
            ch = "shininess"[copyIndex3 + 1];
            copyIndex3 = copyLength3;
          } while (ch != '\0');
          break;
        default:
          goto switchD_97c01d20_caseD_0;
        }
        break;
      case 0xb:
        ch = 'f';
        copyIndex3 = 0;
        do {
          local_60[copyIndex3] = ch;
          copyLength3 = copyIndex3 + 1;
          ch = "frontfacing"[copyIndex3 + 1];
          copyIndex3 = copyLength3;
        } while (ch != '\0');
      }
      local_60 = local_60 + copyLength3;
switchD_97c01d20_caseD_0:
      ch = ';';
      copyIndex3 = 0;
      do {
        local_60[copyIndex3] = ch;
        copyLength3 = copyIndex3 + 1;
        ch = ";\n"[copyIndex3 + 1];
        copyIndex3 = copyLength3;
      } while (ch != '\0');
      local_60 = local_60 + copyLength3;
      uVar25 = ((int (*)())_adjustAllocation_97bf27d4)(&local_68,&local_64,&local_60);
      uVar11 = (undefined4)uVar25;
      pcVar9 = local_64;
      if ((int)((ulonglong)uVar25 >> 0x20) == 0) goto LAB_97c04d50;
LAB_97c0239c:
      loopIndex3 = loopIndex3 + 1;
    } while (loopIndex3 < iVar21);
  }
  if (iVar21 != 0) {
    ch = '\n';
    copyIndex5 = 0;
    do {
      local_60[copyIndex5] = ch;
      copyLength7 = copyIndex5 + 1;
      ch = "\n"[copyIndex5 + 1];
      copyIndex5 = copyLength7;
    } while (ch != '\0');
    local_60 = local_60 + copyLength7;
  }
  iVar21 = shader[10];
  iVar19 = shader[0xb];
  if (iVar21 != 0) {
    uVar23 = 0xffffffff;
    if (0 < iVar21) {
      puVar6 = (uint *)(shader + iVar19 * 2 + 1);
      iVar3 = iVar21;
      do {
        uVar1 = *puVar6;
        puVar6 = puVar6 + 2;
        if ((int)uVar23 < (int)(uVar1 & 0xffff)) {
          uVar23 = uVar1 & 0xffff;
        }
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      if (uVar23 != 0xffffffff) {
        iVar3 = uVar23 * 4 + 4;
        iVar16 = _malloc(iVar3);
        piVar15 = (int *)_malloc(iVar3);
        if ((iVar16 == 0) || (uVar11 = extraout_r4_00, piVar15 == (int *)0x0)) {
          piVar14 = piVar15;
          pcVar9 = local_64;
          if (iVar16 != 0) {
            _free(iVar16);
            pcVar9 = local_64;
          }
joined_r0x97c02488:
          local_64 = pcVar9;
          if (piVar14 != (int *)0x0) {
            _free(piVar14);
            pcVar9 = local_64;
          }
          goto LAB_97c04d50;
        }
      }
    }
    if (shader[0xe] != 0) {
      piVar14 = (int *)_malloc(shader[0xe] << 2);
      uVar11 = extraout_r4_01;
    }
    uVar25 = CONCAT44(piVar14,uVar11);
    loopIndex3 = 0;
    iVar4 = -1;
    local_5c = 0xffffffff;
    uVar23 = 0xffffffff;
    piVar18 = piVar14;
    if (0 < iVar21) {
      do {
        iVar5 = loopIndex3 * 8 + iVar19 * 8;
        if ((shader[iVar19 * 2 + loopIndex3 * 2] & 0x1f0000U) != 0) {
          if (uVar23 == 0xffffffff) {
            uVar1 = (uint)*(ushort *)((int)shader + iVar5 + 6);
            *(uint *)(uVar1 * 4 + iVar16) = uVar1;
            uVar25 = ((int (*)())_isParamArrayStart_97c017c0)(shader,(uint)*(ushort *)((int)shader + iVar5 + 6),&local_5c);
            if ((int)((ulonglong)uVar25 >> 0x20) == 0) {
              piVar15[*(ushort *)((int)shader + iVar5 + 6)] = iVar4;
            }
            else {
              uVar23 = (uint)*(ushort *)((int)shader + iVar5 + 6);
              piVar15[uVar23] = 0;
              iVar4 = 1;
            }
          }
          else {
            uVar1 = (uint)*(ushort *)((int)shader + iVar5 + 6);
            if ((int)uVar1 <= (int)local_5c) {
              *(uint *)(uVar1 * 4 + iVar16) = uVar23;
              piVar15[*(ushort *)((int)shader + iVar5 + 6)] = iVar4;
              iVar4 = iVar4 + 1;
              if (*(ushort *)((int)shader + iVar5 + 6) == local_5c) {
                uVar23 = 0xffffffff;
                local_5c = 0xffffffff;
                *piVar18 = iVar4;
                piVar18 = piVar18 + 1;
                iVar4 = -1;
              }
            }
          }
        }
        loopIndex3 = loopIndex3 + 1;
      } while (loopIndex3 < iVar21);
    }
    loopIndex = 0;
    iVar3 = 0;
    if (0 < iVar21) {
      do {
        iVar5 = loopIndex * 8;
        uVar23 = (uint)shader[iVar19 * 2 + loopIndex * 2] >> 0x10 & 0x1f;
        if (uVar23 == 0) goto LAB_97c04238;
        if (piVar15[*(ushort *)((int)shader + iVar5 + iVar19 * 8 + 6)] == -1) {
          ch = 'P';
          copyIndex = 0;
          do {
            local_60[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PARAM prm"[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          local_60 = local_60 + copyLength;
          uVar25 = ((int (*)())_ncpy_97bf2850)(local_60,*(undefined4 *)
                                            (iVar16 + (uint)*(ushort *)
                                                             ((int)shader + iVar5 + iVar19 * 8 + 6)
                                                      * 4));
          ch = ' ';
          copyIndex = 0;
          do {
            (local_60 + (int)((ulonglong)uVar25 >> 0x20))[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = " = "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          local_60 = local_60 + (int)((ulonglong)uVar25 >> 0x20) + copyLength;
        }
        else {
          if (piVar15[*(ushort *)((int)shader + iVar5 + iVar19 * 8 + 6)] == 0) {
            iVar13 = 0;
            ch = 'P';
            copyIndex = 0;
            do {
              local_60[copyIndex] = ch;
              copyLength = copyIndex + 1;
              ch = "PARAM prm"[copyIndex + 1];
              copyIndex = copyLength;
            } while (ch != '\0');
            local_60 = local_60 + copyLength;
            copyEnd = ((int (*)())_ncpy_97bf2850)(local_60,*(undefined4 *)
                                             (iVar16 + (uint)*(ushort *)
                                                              ((int)shader + iVar5 + iVar19 * 8 + 6
                                                              ) * 4));
            ch = '[';
            copyIndex = 0;
            do {
              local_60[copyIndex + copyEnd] = ch;
              copyLength6 = copyIndex + 1;
              ch = "["[copyIndex + 1];
              copyIndex = copyLength6;
            } while (ch != '\0');
            local_60 = local_60 + copyLength6 + copyEnd;
            uVar25 = ((int (*)())_ncpy_97bf2850)(local_60,piVar14[iVar3]);
            ch = ']';
            copyIndex = 0;
            do {
              (local_60 + (int)((ulonglong)uVar25 >> 0x20))[copyIndex] = ch;
              copyLength = copyIndex + 1;
              ch = "]"[copyIndex + 1];
              copyIndex = copyLength;
            } while (ch != '\0');
            local_60 = local_60 + (int)((ulonglong)uVar25 >> 0x20) + copyLength;
            ch = ' ';
            copyIndex = 0;
            do {
              local_60[copyIndex] = ch;
              copyLength = copyIndex + 1;
              ch = " = {\n    "[copyIndex + 1];
              copyIndex = copyLength;
            } while (ch != '\0');
          }
          else {
            iVar13 = iVar13 + 1;
            ch = ' ';
            copyIndex = 0;
            do {
              local_60[copyIndex] = ch;
              copyLength = copyIndex + 1;
              ch = "    "[copyIndex + 1];
              copyIndex = copyLength;
            } while (ch != '\0');
          }
          local_60 = local_60 + copyLength;
        }
        if (uVar23 == 0) {
LAB_97c028a4:
          ch = 's';
          copyIndex = 0;
          do {
            local_60[copyIndex] = ch;
            iVar7 = copyIndex + 1;
            ch = "state."[copyIndex + 1];
            copyIndex = iVar7;
          } while (ch != '\0');
        }
        else if (uVar23 < 3) {
          ch = 'p';
          copyIndex = 0;
          do {
            local_60[copyIndex] = ch;
            iVar7 = copyIndex + 1;
            ch = "program."[copyIndex + 1];
            copyIndex = iVar7;
          } while (ch != '\0');
        }
        else {
          if (uVar23 != 0x11) goto LAB_97c028a4;
          iVar7 = 0;
        }
        local_60 = local_60 + iVar7;
        switch(uVar23) {
        default:
          goto switchD_97c02904_caseD_0;
        case 1:
          ch = 'l';
          copyIndex = 0;
          do {
            local_60[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "local["[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          local_60 = local_60 + copyLength;
          copyEnd2 = ((int (*)())_ncpy_97bf2850)(local_60,shader[iVar19 * 2 + loopIndex * 2] & 0xffff);
          ch = ']';
          local_60 = local_60 + copyEnd2;
          copyIndex = 0;
          do {
            local_60[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "]"[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          goto LAB_97c040c4;
        case 2:
          ch = 'e';
          copyIndex = 0;
          do {
            local_60[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "env["[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          local_60 = local_60 + copyLength;
          copyEnd2 = ((int (*)())_ncpy_97bf2850)(local_60,shader[iVar19 * 2 + loopIndex * 2] & 0xffff);
          ch = ']';
          local_60 = local_60 + copyEnd2;
          copyIndex = 0;
          do {
            local_60[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "]"[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          goto LAB_97c040c4;
        case 3:
          ch = 'l';
          copyIndex = 0;
          do {
            local_60[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "light["[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          local_60 = local_60 + copyLength;
          iVar7 = ((int (*)())_ncpy_97bf2850)(local_60,shader[iVar19 * 2 + loopIndex * 2] & 0xff);
          ch = ']';
          copyIndex = 0;
          do {
            local_60[copyIndex + iVar7] = ch;
            copyLength6 = copyIndex + 1;
            ch = "]."[copyIndex + 1];
            copyIndex = copyLength6;
          } while (ch != '\0');
          local_60 = local_60 + copyLength6 + iVar7;
          switch((uint)shader[iVar19 * 2 + loopIndex * 2] >> 8 & 0xf) {
          case 0:
            ch = 'a';
            copyIndex = 0;
            do {
              local_60[copyIndex] = ch;
              iVar7 = copyIndex + 1;
              ch = "ambient"[copyIndex + 1];
              copyIndex = iVar7;
            } while (ch != '\0');
            break;
          case 1:
            ch = 'd';
            copyIndex = 0;
            do {
              local_60[copyIndex] = ch;
              iVar7 = copyIndex + 1;
              ch = "diffuse"[copyIndex + 1];
              copyIndex = iVar7;
            } while (ch != '\0');
            break;
          case 2:
            ch = 's';
            copyIndex = 0;
            do {
              local_60[copyIndex] = ch;
              iVar7 = copyIndex + 1;
              ch = "specular"[copyIndex + 1];
              copyIndex = iVar7;
            } while (ch != '\0');
            break;
          case 3:
            ch = 'p';
            copyIndex = 0;
            do {
              local_60[copyIndex] = ch;
              iVar7 = copyIndex + 1;
              ch = "position"[copyIndex + 1];
              copyIndex = iVar7;
            } while (ch != '\0');
            break;
          case 4:
            ch = 's';
            copyIndex = 0;
            do {
              local_60[copyIndex] = ch;
              iVar7 = copyIndex + 1;
              ch = "spot.direction"[copyIndex + 1];
              copyIndex = iVar7;
            } while (ch != '\0');
            break;
          case 5:
            ch = 'a';
            copyIndex = 0;
            do {
              local_60[copyIndex] = ch;
              iVar7 = copyIndex + 1;
              ch = "attenuation"[copyIndex + 1];
              copyIndex = iVar7;
            } while (ch != '\0');
            break;
          case 6:
            ch = 'h';
            copyIndex = 0;
            do {
              local_60[copyIndex] = ch;
              iVar7 = copyIndex + 1;
              ch = "half"[copyIndex + 1];
              copyIndex = iVar7;
            } while (ch != '\0');
            break;
          case 7:
            ch = 's';
            copyIndex = 0;
            do {
              local_60[copyIndex] = ch;
              iVar7 = copyIndex + 1;
              ch = "spotcutoff"[copyIndex + 1];
              copyIndex = iVar7;
            } while (ch != '\0');
            break;
          default:
            goto switchD_97c02904_caseD_0;
          }
          break;
        case 4:
          ch = 'l';
          copyIndex = 0;
          do {
            local_60[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "lightprod["[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          local_60 = local_60 + copyLength;
          copyEnd = ((int (*)())_ncpy_97bf2850)(local_60,shader[iVar19 * 2 + loopIndex * 2] & 0xff);
          ch = ']';
          copyIndex = 0;
          do {
            local_60[copyIndex + copyEnd] = ch;
            copyLength6 = copyIndex + 1;
            ch = "]."[copyIndex + 1];
            copyIndex = copyLength6;
          } while (ch != '\0');
          local_60 = local_60 + copyLength6 + copyEnd;
          uVar23 = (uint)shader[iVar19 * 2 + loopIndex * 2] >> 8 & 1;
          if (uVar23 == 0) {
            ch = 'f';
            copyIndex = 0;
            do {
              local_60[copyIndex] = ch;
              copyLength = copyIndex + 1;
              ch = "front."[copyIndex + 1];
              copyIndex = copyLength;
            } while (ch != '\0');
LAB_97c02e60:
            local_60 = local_60 + copyLength;
          }
          else if (uVar23 == 1) {
            ch = 'b';
            copyIndex = 0;
            do {
              local_60[copyIndex] = ch;
              copyLength = copyIndex + 1;
              ch = "back."[copyIndex + 1];
              copyIndex = copyLength;
            } while (ch != '\0');
            goto LAB_97c02e60;
          }
          uVar23 = (uint)shader[iVar19 * 2 + loopIndex * 2] >> 9 & 3;
          if (uVar23 == 1) {
            ch = 'd';
            copyIndex = 0;
            do {
              local_60[copyIndex] = ch;
              iVar7 = copyIndex + 1;
              ch = "diffuse"[copyIndex + 1];
              copyIndex = iVar7;
            } while (ch != '\0');
            break;
          }
          if (uVar23 < 2) {
            if (uVar23 == 0) {
              ch = 'a';
              copyIndex = 0;
              do {
                local_60[copyIndex] = ch;
                iVar7 = copyIndex + 1;
                ch = "ambient"[copyIndex + 1];
                copyIndex = iVar7;
              } while (ch != '\0');
              break;
            }
          }
          else if (uVar23 == 2) {
            ch = 's';
            copyIndex = 0;
            do {
              local_60[copyIndex] = ch;
              iVar7 = copyIndex + 1;
              ch = "specular"[copyIndex + 1];
              copyIndex = iVar7;
            } while (ch != '\0');
            break;
          }
          goto switchD_97c02904_caseD_0;
        case 5:
          if (((uint)shader[iVar19 * 2 + loopIndex * 2] >> 1 & 7) == 5) {
            ch = 'l';
            copyIndex = 0;
            do {
              local_60[copyIndex] = ch;
              iVar7 = copyIndex + 1;
              ch = "lightmodel."[copyIndex + 1];
              copyIndex = iVar7;
            } while (ch != '\0');
          }
          else {
            ch = 'm';
            copyIndex = 0;
            do {
              local_60[copyIndex] = ch;
              iVar7 = copyIndex + 1;
              ch = "material."[copyIndex + 1];
              copyIndex = iVar7;
            } while (ch != '\0');
          }
          local_60 = local_60 + iVar7;
          if ((shader[iVar19 * 2 + loopIndex * 2] & 1U) == 0) {
            ch = 'f';
            copyIndex = 0;
            do {
              local_60[copyIndex] = ch;
              iVar7 = copyIndex + 1;
              ch = "front."[copyIndex + 1];
              copyIndex = iVar7;
            } while (ch != '\0');
LAB_97c03088:
            local_60 = local_60 + iVar7;
          }
          else if ((shader[iVar19 * 2 + loopIndex * 2] & 1U) == 1) {
            ch = 'b';
            copyIndex = 0;
            do {
              local_60[copyIndex] = ch;
              iVar7 = copyIndex + 1;
              ch = "back."[copyIndex + 1];
              copyIndex = iVar7;
            } while (ch != '\0');
            goto LAB_97c03088;
          }
          switch((uint)shader[iVar19 * 2 + loopIndex * 2] >> 1 & 7) {
          case 0:
            ch = 'a';
            copyIndex = 0;
            do {
              local_60[copyIndex] = ch;
              iVar7 = copyIndex + 1;
              ch = "ambient"[copyIndex + 1];
              copyIndex = iVar7;
            } while (ch != '\0');
            break;
          case 1:
            ch = 'd';
            copyIndex = 0;
            do {
              local_60[copyIndex] = ch;
              iVar7 = copyIndex + 1;
              ch = "diffuse"[copyIndex + 1];
              copyIndex = iVar7;
            } while (ch != '\0');
            break;
          case 2:
            ch = 's';
            copyIndex = 0;
            do {
              local_60[copyIndex] = ch;
              iVar7 = copyIndex + 1;
              ch = "specular"[copyIndex + 1];
              copyIndex = iVar7;
            } while (ch != '\0');
            break;
          case 3:
            ch = 'e';
            copyIndex = 0;
            do {
              local_60[copyIndex] = ch;
              iVar7 = copyIndex + 1;
              ch = "emission"[copyIndex + 1];
              copyIndex = iVar7;
            } while (ch != '\0');
            break;
          case 4:
            ch = 's';
            copyIndex = 0;
            do {
              local_60[copyIndex] = ch;
              iVar7 = copyIndex + 1;
              ch = "shininess"[copyIndex + 1];
              copyIndex = iVar7;
            } while (ch != '\0');
            break;
          case 5:
            ch = 's';
            copyIndex = 0;
            do {
              local_60[copyIndex] = ch;
              iVar7 = copyIndex + 1;
              ch = "scenecolor"[copyIndex + 1];
              copyIndex = iVar7;
            } while (ch != '\0');
            break;
          default:
            goto switchD_97c02904_caseD_0;
          }
          break;
        case 6:
          ch = 'l';
          copyIndex = 0;
          do {
            local_60[copyIndex] = ch;
            iVar7 = copyIndex + 1;
            ch = "lightmodel.ambient"[copyIndex + 1];
            copyIndex = iVar7;
          } while (ch != '\0');
          break;
        case 7:
          ch = 't';
          copyIndex = 0;
          do {
            local_60[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "texgen["[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          local_60 = local_60 + copyLength;
          copyEnd = ((int (*)())_ncpy_97bf2850)(local_60,shader[iVar19 * 2 + loopIndex * 2] & 0x1f);
          ch = ']';
          copyIndex = 0;
          do {
            local_60[copyIndex + copyEnd] = ch;
            copyLength6 = copyIndex + 1;
            ch = "].eye."[copyIndex + 1];
            copyIndex = copyLength6;
          } while (ch != '\0');
          local_60 = local_60 + copyLength6 + copyEnd;
          uVar23 = (uint)shader[iVar19 * 2 + loopIndex * 2] >> 5 & 7;
          if (uVar23 == 1) {
            ch = 't';
            copyIndex = 0;
            do {
              local_60[copyIndex] = ch;
              iVar7 = copyIndex + 1;
              ch = "t"[copyIndex + 1];
              copyIndex = iVar7;
            } while (ch != '\0');
          }
          else if (uVar23 < 2) {
            if (uVar23 != 0) goto switchD_97c02904_caseD_0;
            ch = 's';
            copyIndex = 0;
            do {
              local_60[copyIndex] = ch;
              iVar7 = copyIndex + 1;
              ch = "s"[copyIndex + 1];
              copyIndex = iVar7;
            } while (ch != '\0');
          }
          else if (uVar23 == 2) {
            ch = 'r';
            copyIndex = 0;
            do {
              local_60[copyIndex] = ch;
              iVar7 = copyIndex + 1;
              ch = "r"[copyIndex + 1];
              copyIndex = iVar7;
            } while (ch != '\0');
          }
          else {
            if (uVar23 != 3) goto switchD_97c02904_caseD_0;
            ch = 'q';
            copyIndex = 0;
            do {
              local_60[copyIndex] = ch;
              iVar7 = copyIndex + 1;
              ch = "q"[copyIndex + 1];
              copyIndex = iVar7;
            } while (ch != '\0');
          }
          break;
        case 8:
          ch = 't';
          copyIndex = 0;
          do {
            local_60[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "texgen["[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          local_60 = local_60 + copyLength;
          copyEnd = ((int (*)())_ncpy_97bf2850)(local_60,shader[iVar19 * 2 + loopIndex * 2] & 0x1f);
          ch = ']';
          copyIndex = 0;
          do {
            local_60[copyIndex + copyEnd] = ch;
            copyLength6 = copyIndex + 1;
            ch = "].object."[copyIndex + 1];
            copyIndex = copyLength6;
          } while (ch != '\0');
          local_60 = local_60 + copyLength6 + copyEnd;
          uVar23 = (uint)shader[iVar19 * 2 + loopIndex * 2] >> 5 & 7;
          if (uVar23 == 1) {
            ch = 't';
            copyIndex = 0;
            do {
              local_60[copyIndex] = ch;
              iVar7 = copyIndex + 1;
              ch = "t"[copyIndex + 1];
              copyIndex = iVar7;
            } while (ch != '\0');
          }
          else if (uVar23 < 2) {
            if (uVar23 != 0) goto switchD_97c02904_caseD_0;
            ch = 's';
            copyIndex = 0;
            do {
              local_60[copyIndex] = ch;
              iVar7 = copyIndex + 1;
              ch = "s"[copyIndex + 1];
              copyIndex = iVar7;
            } while (ch != '\0');
          }
          else if (uVar23 == 2) {
            ch = 'r';
            copyIndex = 0;
            do {
              local_60[copyIndex] = ch;
              iVar7 = copyIndex + 1;
              ch = "r"[copyIndex + 1];
              copyIndex = iVar7;
            } while (ch != '\0');
          }
          else {
            if (uVar23 != 3) goto switchD_97c02904_caseD_0;
            ch = 'q';
            copyIndex = 0;
            do {
              local_60[copyIndex] = ch;
              iVar7 = copyIndex + 1;
              ch = "q"[copyIndex + 1];
              copyIndex = iVar7;
            } while (ch != '\0');
          }
          break;
        case 9:
          ch = 't';
          copyIndex = 0;
          do {
            local_60[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "texenv["[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          local_60 = local_60 + copyLength;
          copyEnd2 = ((int (*)())_ncpy_97bf2850)(local_60,shader[iVar19 * 2 + loopIndex * 2] & 0x1f);
          ch = ']';
          local_60 = local_60 + copyEnd2;
          copyIndex = 0;
          do {
            local_60[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "].color"[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          goto LAB_97c040c4;
        case 10:
          ch = 'c';
          copyIndex = 0;
          do {
            local_60[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "clip["[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          local_60 = local_60 + copyLength;
          copyEnd2 = ((int (*)())_ncpy_97bf2850)(local_60,shader[iVar19 * 2 + loopIndex * 2] & 0xff);
          ch = ']';
          local_60 = local_60 + copyEnd2;
          copyIndex = 0;
          do {
            local_60[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "].plane"[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          goto LAB_97c040c4;
        case 0xb:
          ch = 'f';
          copyIndex = 0;
          do {
            local_60[copyIndex] = ch;
            iVar7 = copyIndex + 1;
            ch = "fog.color"[copyIndex + 1];
            copyIndex = iVar7;
          } while (ch != '\0');
          break;
        case 0xc:
          ch = 'f';
          copyIndex = 0;
          do {
            local_60[copyIndex] = ch;
            iVar7 = copyIndex + 1;
            ch = "fog.params"[copyIndex + 1];
            copyIndex = iVar7;
          } while (ch != '\0');
          break;
        case 0xd:
          ch = 'p';
          copyIndex = 0;
          do {
            local_60[copyIndex] = ch;
            iVar7 = copyIndex + 1;
            ch = "point.size"[copyIndex + 1];
            copyIndex = iVar7;
          } while (ch != '\0');
          break;
        case 0xe:
          ch = 'p';
          copyIndex = 0;
          do {
            local_60[copyIndex] = ch;
            iVar7 = copyIndex + 1;
            ch = "point.attenuation"[copyIndex + 1];
            copyIndex = iVar7;
          } while (ch != '\0');
          break;
        case 0xf:
          ch = 'd';
          copyIndex = 0;
          do {
            local_60[copyIndex] = ch;
            iVar7 = copyIndex + 1;
            ch = "depth.range"[copyIndex + 1];
            copyIndex = iVar7;
          } while (ch != '\0');
          break;
        case 0x10:
          ch = 'm';
          copyIndex = 0;
          do {
            local_60[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "matrix."[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          local_60 = local_60 + copyLength;
          switch((uint)shader[iVar19 * 2 + loopIndex * 2] >> 8 & 7) {
          case 0:
            ch = 'm';
            copyIndex = 0;
            do {
              local_60[copyIndex] = ch;
              copyLength = copyIndex + 1;
              ch = "mvp."[copyIndex + 1];
              copyIndex = copyLength;
            } while (ch != '\0');
            goto LAB_97c038d4;
          case 1:
            ch = 'p';
            copyIndex = 0;
            do {
              local_60[copyIndex] = ch;
              copyLength = copyIndex + 1;
              ch = "projection."[copyIndex + 1];
              copyIndex = copyLength;
            } while (ch != '\0');
LAB_97c038d4:
            local_60 = local_60 + copyLength;
            goto switchD_97c0384c_default;
          case 2:
            ch = 'c';
            copyIndex = 0;
            do {
              local_60[copyIndex] = ch;
              copyLength = copyIndex + 1;
              ch = "color["[copyIndex + 1];
              copyIndex = copyLength;
            } while (ch != '\0');
            local_60 = local_60 + copyLength;
            copyEnd2 = ((int (*)())_ncpy_97bf2850)(local_60,shader[iVar19 * 2 + loopIndex * 2] & 0xff);
            ch = ']';
            local_60 = local_60 + copyEnd2;
            copyIndex = 0;
            do {
              local_60[copyIndex] = ch;
              copyLength = copyIndex + 1;
              ch = "]."[copyIndex + 1];
              copyIndex = copyLength;
            } while (ch != '\0');
            break;
          case 3:
            ch = 'm';
            copyIndex = 0;
            do {
              local_60[copyIndex] = ch;
              copyLength = copyIndex + 1;
              ch = "modelview["[copyIndex + 1];
              copyIndex = copyLength;
            } while (ch != '\0');
            local_60 = local_60 + copyLength;
            copyEnd2 = ((int (*)())_ncpy_97bf2850)(local_60,shader[iVar19 * 2 + loopIndex * 2] & 0xff);
            ch = ']';
            local_60 = local_60 + copyEnd2;
            copyIndex = 0;
            do {
              local_60[copyIndex] = ch;
              copyLength = copyIndex + 1;
              ch = "]."[copyIndex + 1];
              copyIndex = copyLength;
            } while (ch != '\0');
            break;
          case 4:
            ch = 't';
            copyIndex = 0;
            do {
              local_60[copyIndex] = ch;
              copyLength = copyIndex + 1;
              ch = "texture["[copyIndex + 1];
              copyIndex = copyLength;
            } while (ch != '\0');
            local_60 = local_60 + copyLength;
            copyEnd2 = ((int (*)())_ncpy_97bf2850)(local_60,shader[iVar19 * 2 + loopIndex * 2] & 0xff);
            ch = ']';
            local_60 = local_60 + copyEnd2;
            copyIndex = 0;
            do {
              local_60[copyIndex] = ch;
              copyLength = copyIndex + 1;
              ch = "]."[copyIndex + 1];
              copyIndex = copyLength;
            } while (ch != '\0');
            break;
          case 5:
            ch = 'p';
            copyIndex = 0;
            do {
              local_60[copyIndex] = ch;
              copyLength = copyIndex + 1;
              ch = "program["[copyIndex + 1];
              copyIndex = copyLength;
            } while (ch != '\0');
            local_60 = local_60 + copyLength;
            copyEnd2 = ((int (*)())_ncpy_97bf2850)(local_60,shader[iVar19 * 2 + loopIndex * 2] & 0xff);
            ch = ']';
            local_60 = local_60 + copyEnd2;
            copyIndex = 0;
            do {
              local_60[copyIndex] = ch;
              copyLength = copyIndex + 1;
              ch = "]."[copyIndex + 1];
              copyIndex = copyLength;
            } while (ch != '\0');
            break;
          default:
            goto switchD_97c0384c_default;
          }
          local_60 = local_60 + copyLength;
switchD_97c0384c_default:
          uVar23 = (uint)shader[iVar19 * 2 + loopIndex * 2] >> 0xe & 3;
          if (uVar23 == 1) {
            ch = 't';
            copyIndex = 0;
            do {
              local_60[copyIndex] = ch;
              copyLength = copyIndex + 1;
              ch = "transpose."[copyIndex + 1];
              copyIndex = copyLength;
            } while (ch != '\0');
LAB_97c03c14:
            local_60 = local_60 + copyLength;
          }
          else if (1 < uVar23) {
            if (uVar23 == 2) {
              ch = 'i';
              copyIndex = 0;
              do {
                local_60[copyIndex] = ch;
                copyLength = copyIndex + 1;
                ch = "inverse."[copyIndex + 1];
                copyIndex = copyLength;
              } while (ch != '\0');
            }
            else {
              if (uVar23 != 3) goto LAB_97c03c20;
              ch = 'i';
              copyIndex = 0;
              do {
                local_60[copyIndex] = ch;
                copyLength = copyIndex + 1;
                ch = "invtrans."[copyIndex + 1];
                copyIndex = copyLength;
              } while (ch != '\0');
            }
            goto LAB_97c03c14;
          }
LAB_97c03c20:
          ch = 'r';
          copyIndex = 0;
          do {
            local_60[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "row["[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          local_60 = local_60 + copyLength;
          copyEnd2 = ((int (*)())_ncpy_97bf2850)(local_60,(uint)shader[iVar19 * 2 + loopIndex * 2] >> 0xc & 3);
          ch = ']';
          local_60 = local_60 + copyEnd2;
          copyIndex = 0;
          do {
            local_60[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "]"[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
LAB_97c040c4:
          local_60 = local_60 + copyLength;
          goto switchD_97c02904_caseD_0;
        case 0x11:
          pfVar24 = (float *)(shader +
                             shader[0x1b] * 2 + (shader[iVar19 * 2 + loopIndex * 2] & 0xffffU) * 4);
          switch((uint)shader[iVar19 * 2 + loopIndex * 2] >> 0x1a & 7) {
          case 0:
          case 1:
            ch = '{';
            copyIndex = 0;
            do {
              local_60[copyIndex] = ch;
              copyLength = copyIndex + 1;
              ch = "{"[copyIndex + 1];
              copyIndex = copyLength;
            } while (ch != '\0');
            local_60 = local_60 + copyLength;
            uVar25 = ((char * (*)())_glp_dtostr)((int)((ulonglong)uVar25 >> 0x20),(int)uVar25,local_60,
                                 local_64 + (local_68 - (int)local_60),(double)*pfVar24,1e-07,in_f3,
                                 in_f4,in_f5,in_f6,in_f7,in_f8,in_stack_ffffff48,in_stack_ffffff50,
                                 in_stack_ffffff58,in_stack_ffffff60,in_stack_ffffff68);
            iVar7 = (int)((ulonglong)uVar25 >> 0x20);
            ch = ',';
            copyIndex = 0;
            do {
              *(char *)(iVar7 + copyIndex) = ch;
              copyLength6 = copyIndex + 1;
              ch = ", "[copyIndex + 1];
              copyIndex = copyLength6;
            } while (ch != '\0');
            local_60 = (char *)(iVar7 + copyLength6);
            uVar25 = ((char * (*)())_glp_dtostr)(iVar7,(int)uVar25,local_60,local_64 + (local_68 - (int)local_60),
                                 (double)pfVar24[1],1e-07,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                                 in_stack_ffffff48,in_stack_ffffff50,in_stack_ffffff58,
                                 in_stack_ffffff60,in_stack_ffffff68);
            iVar7 = (int)((ulonglong)uVar25 >> 0x20);
            ch = ',';
            copyIndex = 0;
            do {
              *(char *)(iVar7 + copyIndex) = ch;
              copyLength6 = copyIndex + 1;
              ch = ", "[copyIndex + 1];
              copyIndex = copyLength6;
            } while (ch != '\0');
            local_60 = (char *)(iVar7 + copyLength6);
            uVar25 = ((char * (*)())_glp_dtostr)(iVar7,(int)uVar25,local_60,local_64 + (local_68 - (int)local_60),
                                 (double)pfVar24[2],1e-07,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                                 in_stack_ffffff48,in_stack_ffffff50,in_stack_ffffff58,
                                 in_stack_ffffff60,in_stack_ffffff68);
            iVar7 = (int)((ulonglong)uVar25 >> 0x20);
            ch = ',';
            copyIndex = 0;
            do {
              *(char *)(iVar7 + copyIndex) = ch;
              copyLength6 = copyIndex + 1;
              ch = ", "[copyIndex + 1];
              copyIndex = copyLength6;
            } while (ch != '\0');
            local_60 = (char *)(iVar7 + copyLength6);
            local_60 = (char *)((char * (*)())_glp_dtostr)(iVar7,(int)uVar25,local_60,
                                           local_64 + (local_68 - (int)local_60),(double)pfVar24[3],
                                           1e-07,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                                           in_stack_ffffff48,in_stack_ffffff50,in_stack_ffffff58,
                                           in_stack_ffffff60,in_stack_ffffff68);
            ch = '}';
            copyIndex = 0;
            do {
              local_60[copyIndex] = ch;
              iVar7 = copyIndex + 1;
              ch = "}"[copyIndex + 1];
              copyIndex = iVar7;
            } while (ch != '\0');
            break;
          case 2:
            ch = '{';
            copyIndex = 0;
            do {
              local_60[copyIndex] = ch;
              iVar7 = copyIndex + 1;
              ch = "{-- Fixed constant data not currently supported --}"[copyIndex + 1];
              copyIndex = iVar7;
            } while (ch != '\0');
            break;
          case 3:
          case 4:
            ch = '{';
            copyIndex = 0;
            do {
              local_60[copyIndex] = ch;
              copyLength = copyIndex + 1;
              ch = "{"[copyIndex + 1];
              copyIndex = copyLength;
            } while (ch != '\0');
            local_60 = local_60 + copyLength;
            copyEnd = ((int (*)())_ncpy_97bf2850)(local_60, *(unsigned int *)pfVar24);
            ch = ',';
            copyIndex = 0;
            do {
              local_60[copyIndex + copyEnd] = ch;
              copyLength6 = copyIndex + 1;
              ch = ", "[copyIndex + 1];
              copyIndex = copyLength6;
            } while (ch != '\0');
            local_60 = local_60 + copyLength6 + copyEnd;
            copyEnd = ((int (*)())_ncpy_97bf2850)(local_60, ((unsigned int *)pfVar24)[1]);
            ch = ',';
            copyIndex = 0;
            do {
              local_60[copyIndex + copyEnd] = ch;
              copyLength6 = copyIndex + 1;
              ch = ", "[copyIndex + 1];
              copyIndex = copyLength6;
            } while (ch != '\0');
            local_60 = local_60 + copyLength6 + copyEnd;
            copyEnd = ((int (*)())_ncpy_97bf2850)(local_60, ((unsigned int *)pfVar24)[2]);
            ch = ',';
            copyIndex = 0;
            do {
              local_60[copyIndex + copyEnd] = ch;
              copyLength6 = copyIndex + 1;
              ch = ", "[copyIndex + 1];
              copyIndex = copyLength6;
            } while (ch != '\0');
            local_60 = local_60 + copyLength6 + copyEnd;
            copyEnd2 = ((int (*)())_ncpy_97bf2850)(local_60, ((unsigned int *)pfVar24)[3]);
            ch = '}';
            local_60 = local_60 + copyEnd2;
            copyIndex = 0;
            do {
              local_60[copyIndex] = ch;
              copyLength = copyIndex + 1;
              ch = "}"[copyIndex + 1];
              copyIndex = copyLength;
            } while (ch != '\0');
            goto LAB_97c040c4;
          default:
            goto switchD_97c02904_caseD_0;
          }
          break;
        case 0x12:
          ch = 'n';
          copyIndex = 0;
          do {
            local_60[copyIndex] = ch;
            iVar7 = copyIndex + 1;
            ch = "normalscale"[copyIndex + 1];
            copyIndex = iVar7;
          } while (ch != '\0');
        }
        local_60 = local_60 + iVar7;
switchD_97c02904_caseD_0:
        if (piVar15[*(ushort *)((int)shader + iVar5 + iVar19 * 8 + 6)] == -1) {
          ch = ';';
          copyIndex6 = 0;
          do {
            local_60[copyIndex6] = ch;
            copyLength8 = copyIndex6 + 1;
            ch = ";\n"[copyIndex6 + 1];
            copyIndex6 = copyLength8;
          } while (ch != '\0');
        }
        else if (iVar13 + 1 == piVar14[iVar3]) {
          iVar3 = iVar3 + 1;
          ch = '\n';
          copyIndex6 = 0;
          do {
            local_60[copyIndex6] = ch;
            copyLength8 = copyIndex6 + 1;
            ch = "\n};\n"[copyIndex6 + 1];
            copyIndex6 = copyLength8;
          } while (ch != '\0');
        }
        else {
          ch = ',';
          copyIndex6 = 0;
          do {
            local_60[copyIndex6] = ch;
            copyLength8 = copyIndex6 + 1;
            ch = ",\n"[copyIndex6 + 1];
            copyIndex6 = copyLength8;
          } while (ch != '\0');
        }
        local_60 = local_60 + copyLength8;
        uVar25 = ((int (*)())_adjustAllocation_97bf27d4)(&local_68,&local_64,&local_60);
        if ((int)((ulonglong)uVar25 >> 0x20) == 0) {
          if (iVar16 != 0) {
            _free(iVar16);
          }
          pcVar9 = local_64;
          if (piVar15 != (int *)0x0) {
            _free(piVar15);
            pcVar9 = local_64;
          }
          goto joined_r0x97c02488;
        }
LAB_97c04238:
        loopIndex = loopIndex + 1;
      } while (loopIndex < iVar21);
    }
    if (piVar14 != (int *)0x0) {
      _free(piVar14);
    }
  }
  iVar19 = shader[0xc];
  loopIndex2 = 0;
  iVar13 = shader[0xd];
  if (0 < iVar19) {
    do {
      uVar23 = (uint)shader[iVar13 * 2 + loopIndex2 * 2] >> 0x10 & 0xf;
      if (uVar23 == 0) goto LAB_97c04904;
      ch = 'O';
      copyIndex4 = 0;
      do {
        local_60[copyIndex4] = ch;
        copyLength5 = copyIndex4 + 1;
        ch = "OUTPUT res"[copyIndex4 + 1];
        copyIndex4 = copyLength5;
      } while (ch != '\0');
      local_60 = local_60 + copyLength5;
      iVar4 = ((int (*)())_ncpy_97bf2850)(local_60,(uint)*(ushort *)((int)shader + loopIndex2 * 8 + iVar13 * 8 + 6))
      ;
      ch = ' ';
      copyIndex4 = 0;
      do {
        local_60[copyIndex4 + iVar4] = ch;
        copyLength3 = copyIndex4 + 1;
        ch = " = "[copyIndex4 + 1];
        copyIndex4 = copyLength3;
      } while (ch != '\0');
      local_60 = local_60 + copyLength3 + iVar4;
      switch(uVar23) {
      default:
        goto switchD_97c04350_caseD_0;
      case 1:
        ch = 'r';
        copyIndex4 = 0;
        do {
          local_60[copyIndex4] = ch;
          iVar4 = copyIndex4 + 1;
          ch = "result.position"[copyIndex4 + 1];
          copyIndex4 = iVar4;
        } while (ch != '\0');
        break;
      case 2:
        ch = 'r';
        copyIndex4 = 0;
        do {
          local_60[copyIndex4] = ch;
          iVar4 = copyIndex4 + 1;
          ch = "result.fogcoord"[copyIndex4 + 1];
          copyIndex4 = iVar4;
        } while (ch != '\0');
        break;
      case 3:
        ch = 'r';
        copyIndex4 = 0;
        do {
          local_60[copyIndex4] = ch;
          iVar4 = copyIndex4 + 1;
          ch = "result.pointsize"[copyIndex4 + 1];
          copyIndex4 = iVar4;
        } while (ch != '\0');
        break;
      case 4:
        ch = 'r';
        copyIndex4 = 0;
        do {
          local_60[copyIndex4] = ch;
          copyLength5 = copyIndex4 + 1;
          ch = "result.color"[copyIndex4 + 1];
          copyIndex4 = copyLength5;
        } while (ch != '\0');
        local_60 = local_60 + copyLength5;
        if (iVar17 == 0x8b31) {
          if ((shader[iVar13 * 2 + loopIndex2 * 2] & 1U) == 0) {
            ch = '.';
            copyIndex4 = 0;
            do {
              local_60[copyIndex4] = ch;
              iVar4 = copyIndex4 + 1;
              ch = ".front.primary"[copyIndex4 + 1];
              copyIndex4 = iVar4;
            } while (ch != '\0');
          }
          else {
            if ((shader[iVar13 * 2 + loopIndex2 * 2] & 1U) != 1) goto switchD_97c04350_caseD_0;
            ch = '.';
            copyIndex4 = 0;
            do {
              local_60[copyIndex4] = ch;
              iVar4 = copyIndex4 + 1;
              ch = ".back.primary"[copyIndex4 + 1];
              copyIndex4 = iVar4;
            } while (ch != '\0');
          }
          break;
        }
        if ((iVar17 == 0x8b30) && (1 < ((uint)shader[iVar13 * 2 + loopIndex2 * 2] >> 1 & 7))) {
          ch = '[';
          copyIndex4 = 0;
          do {
            local_60[copyIndex4] = ch;
            copyLength5 = copyIndex4 + 1;
            ch = "["[copyIndex4 + 1];
            copyIndex4 = copyLength5;
          } while (ch != '\0');
          local_60 = local_60 + copyLength5;
          copyEnd4 = ((int (*)())_ncpy_97bf2850)(local_60,(uint)shader[iVar13 * 2 + loopIndex2 * 2] >> 1 & 7);
          ch = ']';
          local_60 = local_60 + copyEnd4;
          copyIndex4 = 0;
          do {
            local_60[copyIndex4] = ch;
            copyLength5 = copyIndex4 + 1;
            ch = "]"[copyIndex4 + 1];
            copyIndex4 = copyLength5;
          } while (ch != '\0');
          goto LAB_97c04804;
        }
        goto switchD_97c04350_caseD_0;
      case 5:
        ch = 'r';
        copyIndex4 = 0;
        do {
          local_60[copyIndex4] = ch;
          copyLength5 = copyIndex4 + 1;
          ch = "result.color"[copyIndex4 + 1];
          copyIndex4 = copyLength5;
        } while (ch != '\0');
        local_60 = local_60 + copyLength5;
        if (iVar17 == 0x8b31) {
          if ((shader[iVar13 * 2 + loopIndex2 * 2] & 1U) == 0) {
            ch = '.';
            copyIndex4 = 0;
            do {
              local_60[copyIndex4] = ch;
              iVar4 = copyIndex4 + 1;
              ch = ".front.secondary"[copyIndex4 + 1];
              copyIndex4 = iVar4;
            } while (ch != '\0');
          }
          else {
            if ((shader[iVar13 * 2 + loopIndex2 * 2] & 1U) != 1) goto switchD_97c04350_caseD_0;
            ch = '.';
            copyIndex4 = 0;
            do {
              local_60[copyIndex4] = ch;
              iVar4 = copyIndex4 + 1;
              ch = ".back.secondary"[copyIndex4 + 1];
              copyIndex4 = iVar4;
            } while (ch != '\0');
          }
          break;
        }
        goto switchD_97c04350_caseD_0;
      case 6:
        ch = 'r';
        copyIndex4 = 0;
        do {
          local_60[copyIndex4] = ch;
          copyLength5 = copyIndex4 + 1;
          ch = "result.texcoord["[copyIndex4 + 1];
          copyIndex4 = copyLength5;
        } while (ch != '\0');
        local_60 = local_60 + copyLength5;
        copyEnd4 = ((int (*)())_ncpy_97bf2850)(local_60,shader[iVar13 * 2 + loopIndex2 * 2] & 0x1f);
        ch = ']';
        local_60 = local_60 + copyEnd4;
        copyIndex4 = 0;
        do {
          local_60[copyIndex4] = ch;
          copyLength5 = copyIndex4 + 1;
          ch = "]"[copyIndex4 + 1];
          copyIndex4 = copyLength5;
        } while (ch != '\0');
        goto LAB_97c04804;
      case 7:
        ch = 'r';
        copyIndex4 = 0;
        do {
          local_60[copyIndex4] = ch;
          iVar4 = copyIndex4 + 1;
          ch = "result.depth"[copyIndex4 + 1];
          copyIndex4 = iVar4;
        } while (ch != '\0');
        break;
      case 8:
        ch = 'r';
        copyIndex4 = 0;
        do {
          local_60[copyIndex4] = ch;
          iVar4 = copyIndex4 + 1;
          ch = "result.eyePosition"[copyIndex4 + 1];
          copyIndex4 = iVar4;
        } while (ch != '\0');
        break;
      case 9:
        ch = 'r';
        copyIndex4 = 0;
        do {
          local_60[copyIndex4] = ch;
          iVar4 = copyIndex4 + 1;
          ch = "result.clipVertex"[copyIndex4 + 1];
          copyIndex4 = iVar4;
        } while (ch != '\0');
        break;
      case 10:
        ch = 'r';
        copyIndex4 = 0;
        do {
          local_60[copyIndex4] = ch;
          copyLength5 = copyIndex4 + 1;
          ch = "result.attrib["[copyIndex4 + 1];
          copyIndex4 = copyLength5;
        } while (ch != '\0');
        local_60 = local_60 + copyLength5;
        copyEnd4 = ((int (*)())_ncpy_97bf2850)(local_60,shader[iVar13 * 2 + loopIndex2 * 2] & 0x1f);
        ch = ']';
        local_60 = local_60 + copyEnd4;
        copyIndex4 = 0;
        do {
          local_60[copyIndex4] = ch;
          copyLength5 = copyIndex4 + 1;
          ch = "]"[copyIndex4 + 1];
          copyIndex4 = copyLength5;
        } while (ch != '\0');
LAB_97c04804:
        local_60 = local_60 + copyLength5;
        goto switchD_97c04350_caseD_0;
      }
      local_60 = local_60 + iVar4;
switchD_97c04350_caseD_0:
      ch = ';';
      copyIndex4 = 0;
      do {
        local_60[copyIndex4] = ch;
        copyLength5 = copyIndex4 + 1;
        ch = ";\n"[copyIndex4 + 1];
        copyIndex4 = copyLength5;
      } while (ch != '\0');
      local_60 = local_60 + copyLength5;
      iVar3 = ((int (*)())_adjustAllocation_97bf27d4)(&local_68,&local_64,&local_60);
      if (iVar3 == 0) {
        piVar14 = piVar15;
        pcVar9 = local_64;
        if (iVar16 != 0) {
          _free(iVar16);
          pcVar9 = local_64;
        }
        goto joined_r0x97c02488;
      }
LAB_97c04904:
      loopIndex2 = loopIndex2 + 1;
    } while (loopIndex2 < iVar19);
  }
  ch = '\n';
  copyIndex7 = 0;
  do {
    local_60[copyIndex7] = ch;
    copyLength9 = copyIndex7 + 1;
    ch = "\n"[copyIndex7 + 1];
    copyIndex7 = copyLength9;
  } while (ch != '\0');
  local_60 = local_60 + copyLength9;
  local_48[0] = (char *)_malloc(local_68);
  pcVar9 = local_64;
  if (local_48[0] == (char *)0x0) goto LAB_97c04d50;
  iVar19 = shader[0x14];
  loopIndex2 = 0;
  iVar13 = shader[0x15];
  iVar3 = 0;
  local_4c = local_48[0];
  if (0 < iVar19) {
    do {
      iVar4 = ((int (*)())_glpDisassemble2Op)(shader + iVar13 * 2 + iVar3 * 2,local_48[0],&local_58,&local_54,
                                 iVar16,piVar15,0,&local_50,&local_70,iVar17,param_2);
      if (iVar4 == -1) {
LAB_97c04a0c:
        if (iVar16 != 0) {
          _free(iVar16);
        }
        if (piVar15 != (int *)0x0) {
          _free(piVar15);
        }
        goto LAB_97c04ab8;
      }
      local_48[0] = local_48[0] + local_54;
      iVar3 = iVar3 + local_58;
      iVar4 = ((int (*)())_adjustAllocation_97bf27d4)(&local_68,&local_4c,local_48);
      if (iVar4 == 0) goto LAB_97c04a0c;
      loopIndex2 = loopIndex2 + 1;
      iVar3 = iVar3 + 1;
    } while (loopIndex2 < iVar19);
  }
  if (iVar16 != 0) {
    _free(iVar16);
  }
  if (piVar15 != (int *)0x0) {
    _free(piVar15);
  }
  ch = 'E';
  copyIndex2 = 0;
  do {
    local_48[0][copyIndex2] = ch;
    copyLength2 = copyIndex2 + 1;
    ch = "END\n"[copyIndex2 + 1];
    copyIndex2 = copyLength2;
  } while (ch != '\0');
  local_48[0] = local_48[0] + copyLength2;
  pcVar9 = (char *)_malloc(local_68);
  if (pcVar9 == (char *)0x0) {
LAB_97c04ab8:
    _free(local_64);
    pcVar9 = local_4c;
    goto LAB_97c04d50;
  }
  if (*shader == 0x8b30) {
    ch = '!';
    copyIndex2 = 0;
    do {
      pcVar9[copyIndex2] = ch;
      copyLength2 = copyIndex2 + 1;
      ch = "!!ARBfp1.0\n\n"[copyIndex2 + 1];
      copyIndex2 = copyLength2;
    } while (ch != '\0');
  }
  else if (*shader == 0x8b31) {
    ch = '!';
    copyIndex2 = 0;
    do {
      pcVar9[copyIndex2] = ch;
      copyLength2 = copyIndex2 + 1;
      ch = "!!ARBvp1.0\n\n"[copyIndex2 + 1];
      copyIndex2 = copyLength2;
    } while (ch != '\0');
  }
  else {
    ch = 'U';
    copyIndex2 = 0;
    do {
      pcVar9[copyIndex2] = ch;
      copyLength2 = copyIndex2 + 1;
      ch = "Unknown Target (error)\n\n"[copyIndex2 + 1];
      copyIndex2 = copyLength2;
    } while (ch != '\0');
  }
  pcVar20 = pcVar9 + copyLength2;
  if ((local_70 & 0x200000) == 0) {
    if ((local_70 & 0x100000) != 0) {
      ch = 'O';
      copyIndex2 = 0;
      do {
        pcVar20[copyIndex2] = ch;
        copyLength2 = copyIndex2 + 1;
        ch = "OPTION NV_vertex_program2;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength2;
      } while (ch != '\0');
      goto LAB_97c04c18;
    }
  }
  else {
    ch = 'O';
    copyIndex2 = 0;
    do {
      pcVar20[copyIndex2] = ch;
      copyLength2 = copyIndex2 + 1;
      ch = "OPTION NV_vertex_program3;\n"[copyIndex2 + 1];
      copyIndex2 = copyLength2;
    } while (ch != '\0');
LAB_97c04c18:
    pcVar20 = pcVar20 + copyLength2;
  }
  if ((local_70 & 0x800000) == 0) {
    if ((local_70 & 0x400000) != 0) {
      ch = 'O';
      copyIndex2 = 0;
      do {
        pcVar20[copyIndex2] = ch;
        copyLength2 = copyIndex2 + 1;
        ch = "OPTION NV_fragment_program;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength2;
      } while (ch != '\0');
      goto LAB_97c04c9c;
    }
  }
  else {
    ch = 'O';
    copyIndex2 = 0;
    do {
      pcVar20[copyIndex2] = ch;
      copyLength2 = copyIndex2 + 1;
      ch = "OPTION NV_fragment_program2;\n"[copyIndex2 + 1];
      copyIndex2 = copyLength2;
    } while (ch != '\0');
LAB_97c04c9c:
    pcVar20 = pcVar20 + copyLength2;
  }
  if ((local_70 & 0x1000000) != 0) {
    ch = 'O';
    copyIndex2 = 0;
    do {
      pcVar20[copyIndex2] = ch;
      copyLength2 = copyIndex2 + 1;
      ch = "OPTION ARB_fragment_program_shadow;\n"[copyIndex2 + 1];
      copyIndex2 = copyLength2;
    } while (ch != '\0');
    pcVar20 = pcVar20 + copyLength2;
  }
  if ((local_70 & 0xf00000) != 0) {
    ch = '\n';
    copyIndex2 = 0;
    do {
      pcVar20[copyIndex2] = ch;
      copyLength2 = copyIndex2 + 1;
      ch = "\n"[copyIndex2 + 1];
      copyIndex2 = copyLength2;
    } while (ch != '\0');
    pcVar20 = pcVar20 + copyLength2;
  }
  allocation = (char *)_malloc(local_68);
  if (allocation != (char *)0x0) {
    pcVar22 = allocation;
    if ((local_70 & 0x1000) != 0) {
      ch = 'P';
      copyIndex2 = 0;
      do {
        allocation[copyIndex2] = ch;
        copyLength2 = copyIndex2 + 1;
        ch = "PARAM kARRAY1 = { 0.0, 1.0, 2.0, 3.0 };\n"[copyIndex2 + 1];
        copyIndex2 = copyLength2;
      } while (ch != '\0');
      ch = 'A';
      copyIndex2 = 0;
      do {
        allocation[copyIndex2 + copyLength2] = ch;
        copyLength4 = copyIndex2 + 1;
        ch = "ALIAS kZERO       = kARRAY1.xxxx;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength4;
      } while (ch != '\0');
      iVar17 = copyLength4 + copyLength2;
      ch = 'A';
      copyIndex2 = 0;
      do {
        allocation[copyIndex2 + iVar17] = ch;
        copyLength2 = copyIndex2 + 1;
        ch = "ALIAS kONE        = kARRAY1.yyyy;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength2;
      } while (ch != '\0');
      iVar13 = copyLength2 + iVar17;
      ch = 'A';
      copyIndex2 = 0;
      do {
        allocation[copyIndex2 + iVar13] = ch;
        copyLength4 = copyIndex2 + 1;
        ch = "ALIAS kTWO        = kARRAY1.zzzz;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength4;
      } while (ch != '\0');
      iVar17 = copyLength4 + iVar13;
      ch = 'A';
      copyIndex2 = 0;
      do {
        allocation[copyIndex2 + iVar17] = ch;
        copyLength2 = copyIndex2 + 1;
        ch = "ALIAS kTHREE      = kARRAY1.wwww;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength2;
      } while (ch != '\0');
      iVar13 = copyLength2 + iVar17;
      ch = 'A';
      copyIndex2 = 0;
      do {
        allocation[copyIndex2 + iVar13] = ch;
        copyLength4 = copyIndex2 + 1;
        ch = "ALIAS kSEL        = kARRAY1;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength4;
      } while (ch != '\0');
      iVar17 = copyLength4 + iVar13;
      ch = 'A';
      copyIndex2 = 0;
      do {
        allocation[copyIndex2 + iVar17] = ch;
        copyLength2 = copyIndex2 + 1;
        ch = "ALIAS kFLOAT      = kARRAY1.yxxx;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength2;
      } while (ch != '\0');
      iVar13 = copyLength2 + iVar17;
      ch = 'A';
      copyIndex2 = 0;
      do {
        allocation[copyIndex2 + iVar13] = ch;
        copyLength4 = copyIndex2 + 1;
        ch = "ALIAS kVEC2       = kARRAY1.yyxx;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength4;
      } while (ch != '\0');
      iVar17 = copyLength4 + iVar13;
      ch = 'A';
      copyIndex2 = 0;
      do {
        allocation[copyIndex2 + iVar17] = ch;
        copyLength2 = copyIndex2 + 1;
        ch = "ALIAS kVEC3       = kARRAY1.yyyx;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength2;
      } while (ch != '\0');
      iVar13 = copyLength2 + iVar17;
      ch = 'A';
      copyIndex2 = 0;
      do {
        allocation[copyIndex2 + iVar13] = ch;
        copyLength4 = copyIndex2 + 1;
        ch = "ALIAS kVEC4       = kARRAY1.yyyy;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength4;
      } while (ch != '\0');
      pcVar22 = allocation + copyLength4 + iVar13;
    }
    if ((local_70 & 0x2000) != 0) {
      ch = 'P';
      iVar16 = 0;
      do {
        pcVar22[iVar16] = ch;
        iVar13 = iVar16 + 1;
        ch = "PARAM kARRAY2 = { 0.5, 3.141592653589793, 6.283185307179586, 1.570796326794897 };\n"
                [iVar16 + 1];
        iVar16 = iVar13;
      } while (ch != '\0');
      ch = 'A';
      copyIndex2 = 0;
      do {
        pcVar22[copyIndex2 + iVar13] = ch;
        copyLength4 = copyIndex2 + 1;
        ch = "ALIAS kHALF       = kARRAY2.xxxx;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength4;
      } while (ch != '\0');
      iVar17 = copyLength4 + iVar13;
      ch = 'A';
      copyIndex2 = 0;
      do {
        pcVar22[copyIndex2 + iVar17] = ch;
        copyLength2 = copyIndex2 + 1;
        ch = "ALIAS kPI         = kARRAY2.yyyy;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength2;
      } while (ch != '\0');
      iVar13 = copyLength2 + iVar17;
      ch = 'A';
      copyIndex2 = 0;
      do {
        pcVar22[copyIndex2 + iVar13] = ch;
        copyLength4 = copyIndex2 + 1;
        ch = "ALIAS k2PI        = kARRAY2.zzzz;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength4;
      } while (ch != '\0');
      iVar17 = copyLength4 + iVar13;
      ch = 'A';
      copyIndex2 = 0;
      do {
        pcVar22[copyIndex2 + iVar17] = ch;
        copyLength2 = copyIndex2 + 1;
        ch = "ALIAS kHALFPI     = kARRAY2.wwww;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength2;
      } while (ch != '\0');
      pcVar22 = pcVar22 + copyLength2 + iVar17;
    }
    if ((local_70 & 0x4000) != 0) {
      ch = 'P';
      iVar16 = 0;
      do {
        pcVar22[iVar16] = ch;
        iVar13 = iVar16 + 1;
        ch = "PARAM kARRAY3 = { 0.636619772367581, 0.31830988618379067, 0.159154943091895, -0.0962243 };\n"
                [iVar16 + 1];
        iVar16 = iVar13;
      } while (ch != '\0');
      ch = 'A';
      copyIndex2 = 0;
      do {
        pcVar22[copyIndex2 + iVar13] = ch;
        copyLength4 = copyIndex2 + 1;
        ch = "ALIAS kHALFPI_RCP = kARRAY3.xxxx;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength4;
      } while (ch != '\0');
      iVar17 = copyLength4 + iVar13;
      ch = 'A';
      copyIndex2 = 0;
      do {
        pcVar22[copyIndex2 + iVar17] = ch;
        copyLength2 = copyIndex2 + 1;
        ch = "ALIAS kPI_RCP     = kARRAY3.yyyy;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength2;
      } while (ch != '\0');
      iVar13 = copyLength2 + iVar17;
      ch = 'A';
      copyIndex2 = 0;
      do {
        pcVar22[copyIndex2 + iVar13] = ch;
        copyLength4 = copyIndex2 + 1;
        ch = "ALIAS k2PI_RCP    = kARRAY3.zzzz;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength4;
      } while (ch != '\0');
      iVar17 = copyLength4 + iVar13;
      ch = 'A';
      copyIndex2 = 0;
      do {
        pcVar22[copyIndex2 + iVar17] = ch;
        copyLength2 = copyIndex2 + 1;
        ch = "ALIAS kTAN_K1     = kARRAY3.wwww;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength2;
      } while (ch != '\0');
      pcVar22 = pcVar22 + copyLength2 + iVar17;
    }
    if ((local_70 & 0x8000) != 0) {
      ch = 'P';
      iVar16 = 0;
      do {
        pcVar22[iVar16] = ch;
        iVar13 = iVar16 + 1;
        ch = "PARAM kARRAY4 = { -0.429562, 0.00986998, 57.295779513082, 0.0174532925199 };\n"
                [iVar16 + 1];
        iVar16 = iVar13;
      } while (ch != '\0');
      ch = 'A';
      copyIndex2 = 0;
      do {
        pcVar22[copyIndex2 + iVar13] = ch;
        copyLength4 = copyIndex2 + 1;
        ch = "ALIAS kTAN_K2     = kARRAY4.xxxx;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength4;
      } while (ch != '\0');
      iVar17 = copyLength4 + iVar13;
      ch = 'A';
      copyIndex2 = 0;
      do {
        pcVar22[copyIndex2 + iVar17] = ch;
        copyLength2 = copyIndex2 + 1;
        ch = "ALIAS kTAN_K3     = kARRAY4.yyyy;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength2;
      } while (ch != '\0');
      iVar13 = copyLength2 + iVar17;
      ch = 'A';
      copyIndex2 = 0;
      do {
        pcVar22[copyIndex2 + iVar13] = ch;
        copyLength4 = copyIndex2 + 1;
        ch = "ALIAS kDEGREES    = kARRAY4.zzzz;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength4;
      } while (ch != '\0');
      iVar17 = copyLength4 + iVar13;
      ch = 'A';
      copyIndex2 = 0;
      do {
        pcVar22[copyIndex2 + iVar17] = ch;
        copyLength2 = copyIndex2 + 1;
        ch = "ALIAS kRADIANS    = kARRAY4.wwww;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength2;
      } while (ch != '\0');
      pcVar22 = pcVar22 + copyLength2 + iVar17;
    }
    if ((local_70 & 0x10000) != 0) {
      ch = 'P';
      copyIndex2 = 0;
      do {
        pcVar22[copyIndex2] = ch;
        copyLength2 = copyIndex2 + 1;
        ch = "PARAM kARRAY5 = { 0.999918, 0.746304, 0.414164, 0.054165 };\n"[copyIndex2 + 1];
        copyIndex2 = copyLength2;
      } while (ch != '\0');
      ch = 'A';
      copyIndex2 = 0;
      do {
        pcVar22[copyIndex2 + copyLength2] = ch;
        copyLength4 = copyIndex2 + 1;
        ch = "ALIAS kATAN_K1    = kARRAY5.xxxx;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength4;
      } while (ch != '\0');
      iVar17 = copyLength4 + copyLength2;
      ch = 'A';
      copyIndex2 = 0;
      do {
        pcVar22[copyIndex2 + iVar17] = ch;
        copyLength2 = copyIndex2 + 1;
        ch = "ALIAS kATAN_K2    = kARRAY5.yyyy;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength2;
      } while (ch != '\0');
      iVar13 = copyLength2 + iVar17;
      ch = 'A';
      copyIndex2 = 0;
      do {
        pcVar22[copyIndex2 + iVar13] = ch;
        copyLength4 = copyIndex2 + 1;
        ch = "ALIAS kATAN_K3    = kARRAY5.zzzz;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength4;
      } while (ch != '\0');
      iVar17 = copyLength4 + iVar13;
      ch = 'A';
      copyIndex2 = 0;
      do {
        pcVar22[copyIndex2 + iVar17] = ch;
        copyLength2 = copyIndex2 + 1;
        ch = "ALIAS kATAN_K4    = kARRAY5.wwww;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength2;
      } while (ch != '\0');
      pcVar22 = pcVar22 + copyLength2 + iVar17;
    }
    if ((local_70 & 0x20000) != 0) {
      ch = 'P';
      iVar16 = 0;
      do {
        pcVar22[iVar16] = ch;
        iVar13 = iVar16 + 1;
        ch = "PARAM kARRAY6 = { 0.671088e-17, 2.718281828459045, 0.69314718056, 0.0 };\n"
                [iVar16 + 1];
        iVar16 = iVar13;
      } while (ch != '\0');
      ch = 'A';
      copyIndex2 = 0;
      do {
        pcVar22[copyIndex2 + iVar13] = ch;
        copyLength4 = copyIndex2 + 1;
        ch = "ALIAS kOFFSET     = kARRAY6.xxxx;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength4;
      } while (ch != '\0');
      iVar17 = copyLength4 + iVar13;
      ch = 'A';
      copyIndex2 = 0;
      do {
        pcVar22[copyIndex2 + iVar17] = ch;
        copyLength2 = copyIndex2 + 1;
        ch = "ALIAS kE          = kARRAY6.y;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength2;
      } while (ch != '\0');
      iVar13 = copyLength2 + iVar17;
      ch = 'A';
      copyIndex2 = 0;
      do {
        pcVar22[copyIndex2 + iVar13] = ch;
        copyLength4 = copyIndex2 + 1;
        ch = "ALIAS k1_OVER_LOG2_E = kARRAY6.zzzz;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength4;
      } while (ch != '\0');
      pcVar22 = pcVar22 + copyLength4 + iVar13;
    }
    if ((local_70 & 0xff000) != 0) {
      ch = '\n';
      copyIndex2 = 0;
      do {
        pcVar22[copyIndex2] = ch;
        copyLength2 = copyIndex2 + 1;
        ch = "\n"[copyIndex2 + 1];
        copyIndex2 = copyLength2;
      } while (ch != '\0');
      pcVar22 = pcVar22 + copyLength2;
    }
    loopIndex4 = 0;
    uVar1 = local_70;
    while ((uVar1 & 1) != 0) {
      ch = 'T';
      copyIndex2 = 0;
      do {
        pcVar22[copyIndex2] = ch;
        copyLength2 = copyIndex2 + 1;
        ch = "TEMP scratch"[copyIndex2 + 1];
        copyIndex2 = copyLength2;
      } while (ch != '\0');
      pcVar22 = pcVar22 + copyLength2;
      if (loopIndex4 != 0) {
        copyEnd5 = ((int (*)())_ncpy_97bf2850)(pcVar22,loopIndex4);
        pcVar22 = pcVar22 + copyEnd5;
      }
      ch = ';';
      copyIndex2 = 0;
      do {
        pcVar22[copyIndex2] = ch;
        copyLength2 = copyIndex2 + 1;
        ch = ";\n"[copyIndex2 + 1];
        copyIndex2 = copyLength2;
      } while (ch != '\0');
      loopIndex4 = loopIndex4 + 1;
      pcVar22 = pcVar22 + copyLength2;
      uVar1 = (int)local_70 >> (loopIndex4 & 0x3f);
    }
    if ((local_70 & 0xfff) != 0) {
      ch = '\n';
      copyIndex2 = 0;
      do {
        pcVar22[copyIndex2] = ch;
        copyLength2 = copyIndex2 + 1;
        ch = "\n"[copyIndex2 + 1];
        copyIndex2 = copyLength2;
      } while (ch != '\0');
      pcVar22 = pcVar22 + copyLength2;
    }
    allocation2 = _malloc(pcVar22 + (int)(pcVar20 +
                                    (int)(local_60 +
                                         (int)(local_48[0] +
                                              (((-(int)local_64 - (int)pcVar9) - (int)allocation) -
                                              (int)local_4c) + 1))));
    *pcVar20 = '\0';
    copyIndex9 = 0;
    *local_60 = '\0';
    *pcVar22 = '\0';
    *local_48[0] = '\0';
    ch = *pcVar9;
    while (ch != '\0') {
      *(char *)(allocation2 + copyIndex9) = ch;
      copyIndex9 = copyIndex9 + 1;
      ch = pcVar9[copyIndex9];
    }
    copyIndex10 = 0;
    ch = *local_64;
    while (ch != '\0') {
      *(char *)(allocation2 + copyIndex9 + copyIndex10) = ch;
      copyIndex10 = copyIndex10 + 1;
      ch = local_64[copyIndex10];
    }
    iVar17 = allocation2 + copyIndex9 + copyIndex10;
    copyIndex9 = 0;
    ch = *allocation;
    while (ch != '\0') {
      *(char *)(iVar17 + copyIndex9) = ch;
      copyIndex9 = copyIndex9 + 1;
      ch = allocation[copyIndex9];
    }
    iVar17 = iVar17 + copyIndex9;
    copyIndex9 = 0;
    ch = *local_4c;
    while (ch != '\0') {
      *(char *)(iVar17 + copyIndex9) = ch;
      copyIndex9 = copyIndex9 + 1;
      ch = local_4c[copyIndex9];
    }
    *(undefined1 *)(iVar17 + copyIndex9) = 0;
    _free(pcVar9);
    _free(local_64);
    _free(allocation);
    _free(local_4c);
    return allocation2;
  }
  _free(local_64);
  _free(local_4c);
LAB_97c04d50:
  _free(pcVar9);
  return 0;
}

/* _glpPPShaderToProgram @ 0x97c057a4 (472 bytes) */
int _glpPPShaderToProgram(param_1, param_2, param_3)
  int *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_30 [5];
  
  _memset(&local_70,0,0x3c);
  iVar1 = ((int (*)())_glpPPShaderToProgramString)(param_1,param_2,param_3);
  iVar5 = 0;
  uVar2 = 0;
  if (iVar1 != 0) {
    if (*param_1 == 0x8b30) {
      iVar5 = _PPParserCreate(2);
      local_60 = 0x100;
      local_64 = 0x8000;
      local_5c = 0x80;
      local_58 = 0x40;
      local_54 = 0;
      local_70 = 0x80;
      local_6c = 0x80;
      local_38 = 0;
    }
    else if (*param_1 == 0x8b31) {
      iVar5 = _PPParserCreate(0);
      local_38 = 0x10;
      local_64 = 0x8000;
      local_5c = 0x100;
      local_58 = 0x20;
      local_54 = 2;
      local_70 = 0x100;
      local_6c = 0x100;
      local_60 = 0x100;
    }
    uVar3 = _PPStreamCreate();
    _PPParserAttachStream(iVar5,uVar3);
    local_4c = 0x10;
    local_48 = 4;
    local_44 = 1;
    local_40 = 6;
    local_3c = 8;
    local_68 = 8;
    local_50 = 8;
    _memcpy(iVar5 + 0x450,&local_70,0x3c);
    _PPParserAttachString(iVar5,iVar1,1);
    iVar4 = _PPParserParse(iVar5);
    uVar2 = 0;
    if (iVar4 == 0) {
      _PPStreamGetStream(uVar3,0,local_30);
      uVar2 = _calloc(local_30[0],8);
      _PPStreamGetStream(uVar3,uVar2,local_30);
      _PPStreamFree(uVar3);
      _PPParserFree(iVar5);
      _free(iVar1);
    }
  }
  return uVar2;
}

/* _glpFreePPShaderToProgram @ 0x97c0597c (12 bytes) */
int _glpFreePPShaderToProgram(param_1)
  int param_1;
{
  if (param_1 == 0) {
    return;
  }
  return _free(param_1);
}

/* _glpUniformToFloat @ 0x97c05988 (344 bytes) */
int _glpUniformToFloat(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  float *param_3;
  float *param_4;
{
  float fVar1;
  float fVar2;
  float fVar3;
  bool bVar4;
  bool bVar5;
  double dVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int loopIndex;
  
  dVar6 = DOUBLE_97c30a58;
  if (param_1 != 0) {
    iVar9 = *(int *)(param_1 + 0x28);
    bVar4 = false;
    bVar5 = false;
    iVar7 = param_1 + *(int *)(param_1 + 0x2c) * 8;
    if (iVar9 != 0) {
      loopIndex = 0;
      if (0 < iVar9) {
        do {
          uVar8 = *(uint *)(iVar7 + loopIndex * 8);
          if (((uVar8 >> 0x10 & 0x1f) == 1) && ((uVar8 & 0xffff) == param_2)) {
            bVar4 = true;
            if ((-1 < *(int *)(loopIndex * 8 + iVar7 + 4)) && ((uVar8 >> 0x1a & 7) != 1)) {
              bVar5 = true;
            }
            break;
          }
          loopIndex = loopIndex + 1;
        } while (loopIndex < iVar9);
      }
      if (bVar4) {
        if (bVar5) {
          *param_4 = (float)((double)CONCAT44(0x43300000,-*param_3) - DOUBLE_97c30a58);
          param_4[1] = (float)((double)CONCAT44(0x43300000,-param_3[1]) - dVar6);
          param_4[2] = (float)((double)CONCAT44(0x43300000,-param_3[2]) - dVar6);
          param_4[3] = (float)((double)CONCAT44(0x43300000,-param_3[3]) - dVar6);
        }
        else {
          fVar1 = *param_3;
          fVar2 = param_3[1];
          fVar3 = param_3[2];
          param_4[3] = param_3[3];
          *param_4 = fVar1;
          param_4[1] = fVar2;
          param_4[2] = fVar3;
        }
      }
    }
  }
  return;
}

/* _glpUniformsToFloats @ 0x97c05ae0 (144 bytes) */
int _glpUniformsToFloats(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  if (param_1 != 0) {
    iVar4 = *(int *)(param_1 + 0x28);
    iVar2 = *(int *)(param_1 + 0x2c);
    if ((iVar4 != 0) && (iVar5 = 0, 0 < iVar4)) {
      do {
        uVar3 = *(uint *)(param_1 + iVar2 * 8 + iVar5 * 8);
        if ((uVar3 >> 0x10 & 0x1f) == 1) {
          uVar3 = uVar3 & 0xffff;
          iVar1 = uVar3 * 0x10;
          ((int (*)())_glpUniformToFloat)(param_1,uVar3,param_2 + iVar1,param_3 + iVar1);
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar4);
    }
  }
  return;
}

/* _handleDigit_97c05b70 @ 0x97c05b70 (112 bytes) */
int _handleDigit_97c05b70(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = param_2 / 10;
  if (iVar1 != 0) {
    ((int (*)())_handleDigit_97c05b70)(param_1,iVar1);
  }
  *(char *)*param_1 = (char)param_2 + (char)iVar1 * -10 + '0';
  *param_1 = *param_1 + 1;
  return;
}

/* _clearFuncInfoList @ 0x97c05be0 (68 bytes) */
int _clearFuncInfoList(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (param_2 != 0) {
    do {
      iVar1 = iVar3 * 0x20;
      iVar3 = iVar3 + 1;
      iVar2 = iVar1 + param_1;
      *(undefined4 *)(param_1 + iVar1) = 0xffffffff;
      *(undefined4 *)(iVar2 + 0x14) = 0;
      *(undefined4 *)(iVar2 + 4) = 0xffffffff;
      *(undefined4 *)(iVar2 + 8) = 0;
      *(undefined4 *)(iVar2 + 0xc) = 0;
      *(undefined4 *)(iVar2 + 0x10) = 0;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
    return;
  }
  return;
}

/* _UpdateFunctionIndex @ 0x97c05c24 (60 bytes) */
int _UpdateFunctionIndex(param_1, param_2, param_3, param_4)
  uint param_1;
  int param_2;
  int param_3;
  uint param_4;
{
  uint uVar1;
  
  uVar1 = 0;
  if (param_4 != 0) {
    do {
      if (param_2 == *(int *)(param_3 + uVar1 * 0x20)) break;
      uVar1 = uVar1 + 1;
    } while (uVar1 < param_4);
  }
  if (uVar1 == param_4) {
    uVar1 = param_1;
  }
  return uVar1;
}

/* _RecordFunctionCall @ 0x97c05c60 (188 bytes) */
int _RecordFunctionCall(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  uint param_3;
{
  int allocation;
  uint loopIndex;
  
  loopIndex = 0;
  if (param_3 != 0) {
    do {
      if (param_1 == *(int *)(loopIndex * 0x20 + *param_2)) break;
      loopIndex = loopIndex + 1;
    } while (loopIndex < param_3);
  }
  if (loopIndex == param_3) {
    if ((param_3 & 0x7f) == 0) {
      allocation = _malloc(param_3 * 0x20 + 0x1000);
      ((int (*)())_clearFuncInfoList)(allocation,param_3 + 0x80);
      _memcpy(allocation,*param_2,param_3 * 0x20);
      if (*param_2 != 0) {
        _free(*param_2);
      }
      *param_2 = allocation;
    }
    param_3 = param_3 + 1;
    *(int *)(loopIndex * 0x20 + *param_2) = param_1;
  }
  return param_3;
}

/* _RecordFunctionEdge @ 0x97c05d1c (72 bytes) */
int _RecordFunctionEdge(param_1, param_2, param_3, param_4, param_5)
  uint param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
  uint param_5;
{
  uint loopIndex;
  
  loopIndex = 0;
  if (param_5 == 0) {
    return param_1;
  }
  do {
    if (param_2 == *(int *)(param_4 + loopIndex * 0x20)) {
      if (-1 < (int)param_1) {
        *(undefined4 *)(param_1 * 0x20 + param_4 + 4) = param_3;
      }
      return loopIndex;
    }
    loopIndex = loopIndex + 1;
  } while (loopIndex < param_5);
  return param_1;
}

/* _ClearJumpTable @ 0x97c05d64 (92 bytes) */
int _ClearJumpTable(param_1)
  int param_1;
{
  if (*(int *)(param_1 + 0xc) != 0) {
    _free(*(undefined4 *)(param_1 + 0x10));
    _free(*(undefined4 *)(param_1 + 0x14));
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}

/* _AddOpToJumpTable @ 0x97c05dc0 (396 bytes) */
int _AddOpToJumpTable(param_1, param_2)
  uint *param_1;
  int param_2;
{
  uint loopIndex;
  uint loopIndex2;
  int iVar1;
  uint uVar2;
  int allocation;
  uint uVar4;
  
  *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 1;
  uVar4 = *param_1;
  switch(uVar4 >> 0x12 & 0xff) {
  case 0x4b:
  case 0x4c:
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
    uVar2 = *(uint *)(param_2 + 0xc);
    if ((uVar2 & 0x7f) == 0) {
      allocation = _malloc(uVar2 * 4 + 0x200);
      _memset(allocation,0,*(int *)(param_2 + 0xc) * 4 + 0x200);
      loopIndex2 = 0;
      uVar4 = 0;
      if (*(int *)(param_2 + 0xc) != 0) {
        do {
          iVar1 = loopIndex2 * 4;
          loopIndex2 = loopIndex2 + 1;
          *(undefined4 *)(iVar1 + allocation) = *(undefined4 *)(iVar1 + *(int *)(param_2 + 0x10));
          uVar4 = *(uint *)(param_2 + 0xc);
        } while (loopIndex2 < uVar4);
      }
      if (*(int *)(param_2 + 0x10) != 0) {
        _free(*(int *)(param_2 + 0x10));
        uVar4 = *(uint *)(param_2 + 0xc);
      }
      *(int *)(param_2 + 0x10) = allocation;
      allocation = _malloc(uVar4 * 4 + 0x200);
      _memset(allocation,0,*(int *)(param_2 + 0xc) * 4 + 0x200);
      loopIndex = 0;
      uVar2 = 0;
      if (*(int *)(param_2 + 0xc) != 0) {
        do {
          iVar1 = loopIndex * 4;
          loopIndex = loopIndex + 1;
          *(undefined4 *)(iVar1 + allocation) = *(undefined4 *)(iVar1 + *(int *)(param_2 + 0x14));
          uVar2 = *(uint *)(param_2 + 0xc);
        } while (loopIndex < uVar2);
      }
      if (*(int *)(param_2 + 0x14) != 0) {
        _free(*(int *)(param_2 + 0x14));
        uVar2 = *(uint *)(param_2 + 0xc);
      }
      *(int *)(param_2 + 0x14) = allocation;
      uVar4 = *param_1;
    }
    *(uint *)(uVar2 * 4 + *(int *)(param_2 + 0x10)) = uVar4 & 0x3ffff;
    *(uint *)(*(int *)(param_2 + 0xc) * 4 + *(int *)(param_2 + 0x14)) = param_1[1] & 0x3ffff;
    *(int *)(param_2 + 0xc) = *(int *)(param_2 + 0xc) + 1;
  }
  return;
}

/* _UpdateFunctionTable @ 0x97c05fd0 (68 bytes) */
int _UpdateFunctionTable(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
  int param_5;
{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (param_5 != 0) {
    do {
      iVar1 = iVar2 * 0x20;
      if (param_1 == *(int *)(iVar1 + param_4)) {
        *(undefined4 *)(iVar1 + param_4) = param_2;
      }
      if (param_1 == *(int *)(iVar1 + param_4 + 4)) {
        *(undefined4 *)(iVar1 + param_4 + 4) = param_3;
      }
      iVar2 = iVar2 + 1;
      param_5 = param_5 + -1;
    } while (param_5 != 0);
    return;
  }
  return;
}

/* _FindFunctionIndex @ 0x97c06014 (48 bytes) */
int _FindFunctionIndex(param_1, param_2, param_3)
  int param_1;
  int param_2;
  uint param_3;
{
  uint loopIndex;
  
  loopIndex = 0;
  if (param_3 != 0) {
    do {
      if (param_1 == *(int *)(param_2 + loopIndex * 0x20)) {
        return loopIndex;
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex < param_3);
  }
  return loopIndex;
}

/* _InlineFunctionsBranch @ 0x97c06044 (1488 bytes) */
int _InlineFunctionsBranch(param_1)
  int param_1;
{
  bool bVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined4 extraout_r3;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int loopIndex;
  uint uVar13;
  int iVar14;
  int iVar15;
  bool bVar16;
  uint uVar17;
  int iVar18;
  uint local_90;
  uint local_8c;
  int local_50 [6];
  
  piVar3 = *(int **)(param_1 + 0x20);
  local_50[0] = 0;
  uVar17 = 0;
  iVar15 = *piVar3;
  uVar13 = 0;
  iVar14 = -1;
  if (iVar15 != 0) {
    do {
      uVar8 = *(uint *)(iVar15 + 0xc);
      uVar17 = uVar8 & 0x3ffff;
      if (uVar17 == 0) {
        uVar13 = ((int (*)())_RecordFunctionCall)(0,local_50,uVar13);
        uVar8 = *(uint *)(iVar15 + 0xc);
      }
      if ((uVar8 >> 0x12 & 0xff) == 0x4c) {
        uVar13 = ((int (*)())_RecordFunctionCall)(*(uint *)(iVar15 + 0x10) & 0x3ffff,local_50,uVar13);
      }
      iVar15 = *(int *)(iVar15 + 8);
    } while (iVar15 != 0);
    piVar3 = *(int **)(param_1 + 0x20);
  }
  uVar8 = 0;
  for (iVar15 = *piVar3; iVar15 != 0; iVar15 = *(int *)(iVar15 + 8)) {
    uVar17 = *(uint *)(iVar15 + 0xc) & 0x3ffff;
    iVar14 = ((int (*)())_RecordFunctionEdge)(iVar14,uVar17,uVar8,local_50[0],uVar13);
    ((int (*)())_AddOpToJumpTable)(iVar15 + 0xc,local_50[0] + iVar14 * 0x20);
    uVar8 = uVar17;
  }
  uVar5 = ((int (*)())_RecordFunctionEdge)(iVar14,0,uVar17,local_50[0],uVar13);
  if (1 < uVar13) {
    piVar3 = *(int **)(param_1 + 0x20);
    iVar15 = *piVar3;
    bVar16 = iVar15 == 0;
    if (!bVar16) {
      do {
        iVar14 = ((int (*)())_UpdateFunctionIndex)(iVar14,*(uint *)(iVar15 + 0xc) & 0x3ffff,local_50[0],uVar13);
        iVar18 = iVar15;
        if ((*(uint *)(iVar15 + 0xc) >> 0x12 & 0xff) == 0x4c) {
          uVar8 = 0xffffffff;
          loopIndex = 0;
          iVar6 = ((int (*)())_FindFunctionIndex)(*(uint *)(iVar15 + 0x10) & 0x3ffff,local_50[0],uVar13);
          uVar10 = *(uint *)(*(int *)(iVar15 + 8) + 0xc);
          uVar17 = *(uint *)(iVar15 + 0xc) & 0x3ffff;
          iVar18 = *(int *)(iVar15 + 4);
          iVar6 = iVar6 * 0x20;
          _PPStreamChunkListRemoveChunk(*(undefined4 *)(param_1 + 0x20),iVar15);
          iVar15 = **(int **)(param_1 + 0x20);
          uVar2 = *(uint *)(iVar15 + 0xc);
          while (*(uint *)(iVar6 + local_50[0]) != (uVar2 & 0x3ffff)) {
            iVar15 = *(int *)(iVar15 + 8);
            uVar2 = *(uint *)(iVar15 + 0xc);
          }
          bVar16 = true;
          iVar7 = iVar18;
          do {
            _memcpy(&local_90,iVar15 + 0xc,0x38);
            if (((local_90 >> 0x12 & 0xff) == 0x4d) &&
               ((local_90 & 0x3ffff) != *(uint *)(iVar6 + local_50[0] + 4))) {
              local_8c = uVar10 & 0x3ffff | local_8c & 0xfffc0000;
              local_90 = local_90 & 0xfc03ffff | 0x12c0000;
            }
            else if ((local_90 >> 0x12 & 0xff) == 0x4d) {
              local_90 = local_90 & 0xfc03ffff | 0x1b80000;
            }
            uVar5 = 0;
            if ((uVar17 == 0) && (uVar8 == 0xffffffff)) {
              uVar5 = 1;
            }
            iVar7 = _PPStreamInsertOperationAfterChunk(param_1,&local_90,iVar15 + 0x44,uVar5,iVar7);
            uVar2 = *(uint *)(iVar7 + 0x10);
            if ((uVar2 & 0x3ffff) != 0) {
              iVar9 = 0;
              iVar4 = **(int **)(param_1 + 0x20);
              uVar11 = *(uint *)(iVar4 + 0xc);
              while (*(uint *)(iVar6 + local_50[0]) != (uVar11 & 0x3ffff)) {
                iVar4 = *(int *)(iVar4 + 8);
                uVar11 = *(uint *)(iVar4 + 0xc);
              }
              bVar1 = true;
              while ((uVar11 & 0x3ffff) != (uVar2 & 0x3ffff)) {
                if ((uVar11 & 0x3ffff) == *(uint *)(iVar6 + local_50[0] + 4)) {
                  bVar1 = false;
                }
                iVar4 = *(int *)(iVar4 + 8);
                iVar9 = iVar9 + 1;
                if (!bVar1) goto LAB_97c0638c;
                uVar11 = *(uint *)(iVar4 + 0xc);
              }
              *(uint *)(iVar7 + 0x10) =
                   ((*(uint *)(iVar7 + 0xc) & 0x3ffff) - loopIndex) + iVar9 & 0x3ffff |
                   uVar2 & 0xfffc0000;
            }
LAB_97c0638c:
            if (uVar8 == 0xffffffff) {
              uVar8 = *(uint *)(iVar7 + 0xc) & 0x3ffff;
            }
            if ((*(uint *)(iVar15 + 0xc) & 0x3ffff) == *(uint *)(iVar6 + local_50[0] + 4)) {
              bVar16 = false;
            }
            iVar15 = *(int *)(iVar15 + 8);
            loopIndex = loopIndex + 1;
          } while (bVar16);
          if (loopIndex < 1) {
            iVar15 = *(int *)(iVar7 + 8);
            if (uVar17 == 0) {
              *(uint *)(iVar15 + 0xc) = *(uint *)(iVar15 + 0xc) & 0xfffc0000;
            }
            uVar8 = *(uint *)(iVar15 + 0xc) & 0x3ffff;
            uVar2 = uVar8;
          }
          else {
            uVar2 = *(uint *)(iVar7 + 0xc) & 0x3ffff;
          }
          bVar16 = iVar18 == 0;
          _PPStreamChangeBranchTargets(param_1,uVar17,uVar8);
          ((int (*)())_UpdateFunctionTable)(uVar17,uVar8,uVar2,local_50[0],uVar13);
        }
        iVar15 = iVar14 * 0x20;
        iVar6 = **(int **)(param_1 + 0x20);
        ((int (*)())_ClearJumpTable)(local_50[0] + iVar15);
        uVar17 = *(uint *)(iVar6 + 0xc);
        while (*(uint *)(iVar15 + local_50[0]) != (uVar17 & 0x3ffff)) {
          iVar6 = *(int *)(iVar6 + 8);
          uVar17 = *(uint *)(iVar6 + 0xc);
        }
        if (*(uint *)(iVar15 + local_50[0] + 4) != (uVar17 & 0x3ffff)) {
          do {
            ((int (*)())_AddOpToJumpTable)(iVar6 + 0xc,local_50[0] + iVar15);
            iVar6 = *(int *)(iVar6 + 8);
          } while (*(uint *)(iVar15 + local_50[0] + 4) != (*(uint *)(iVar6 + 0xc) & 0x3ffff));
        }
        uVar5 = ((int (*)())_AddOpToJumpTable)(iVar6 + 0xc,local_50[0] + iVar15);
        if (bVar16) {
          iVar15 = **(int **)(param_1 + 0x20);
        }
        else {
          iVar15 = *(int *)(iVar18 + 8);
        }
        bVar16 = iVar15 == 0;
      } while (!bVar16);
      piVar3 = *(int **)(param_1 + 0x20);
    }
    uVar17 = 0;
    bVar16 = false;
    iVar14 = *piVar3;
    while (iVar15 = iVar14, iVar15 != 0) {
      iVar14 = *(int *)(iVar15 + 8);
      if ((bVar16) || (uVar17 = 0, uVar13 == 0)) {
        uVar8 = *(uint *)(iVar15 + 0xc);
      }
      else {
        uVar8 = *(uint *)(iVar15 + 0xc);
        do {
          uVar2 = *(uint *)(uVar17 * 0x20 + local_50[0]);
          if ((uVar2 != 0) && (uVar2 == (uVar8 & 0x3ffff))) {
            bVar16 = true;
            break;
          }
          uVar17 = uVar17 + 1;
        } while (uVar17 < uVar13);
      }
      if (bVar16) {
        if (*(uint *)(uVar17 * 0x20 + local_50[0] + 4) == (uVar8 & 0x3ffff)) {
          bVar16 = false;
        }
        _PPStreamRemoveLabelsAtOperationIndex(param_1,uVar8 & 0x3ffff);
        uVar5 = _PPStreamChunkListRemoveChunk(*(undefined4 *)(param_1 + 0x20),iVar15);
      }
      else if ((uVar8 >> 0x12 & 0xff) == 0x6e) {
        uVar5 = ((int (*)())_PPStreamRemoveOperation)(param_1,iVar15);
      }
    }
  }
  if (local_50[0] != 0) {
    uVar17 = 0;
    if (uVar13 != 0) {
      do {
        iVar14 = uVar17 * 0x20;
        uVar17 = uVar17 + 1;
        ((int (*)())_ClearJumpTable)(local_50[0] + iVar14);
      } while (uVar17 < uVar13);
    }
    _free(local_50[0]);
    uVar5 = extraout_r3;
  }
  return uVar5;
}

/* _IsParamSampler @ 0x97c06614 (84 bytes) */
int _IsParamSampler(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  if ((param_1 == 2) &&
     (iVar1 = _PPStreamChunkListChunkAtIndex(*(undefined4 *)(param_3 + 0x10),param_2),
     (*(uint *)(iVar1 + 0xc) >> 0x10 & 0x1f) == 1)) {
    uVar2 = *(uint *)(iVar1 + 0x10) >> 0x1f;
  }
  return uVar2;
}

/* _GetStreamArray_97c06668 @ 0x97c06668 (152 bytes) */
int _GetStreamArray_97c06668(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  int param_3;
{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (param_1 == 1) {
    for (iVar1 = **(int **)(param_3 + 8); iVar1 != 0; iVar1 = *(int *)(iVar1 + 8)) {
      if ((*(ushort *)(iVar1 + 0xe) <= param_2) && (param_2 <= *(ushort *)(iVar1 + 0x12))) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
    }
  }
  else if (param_1 == 2) {
    for (iVar1 = **(int **)(param_3 + 0x14); iVar1 != 0; iVar1 = *(int *)(iVar1 + 8)) {
      if ((*(ushort *)(iVar1 + 0xe) <= param_2) && (param_2 <= *(ushort *)(iVar1 + 0x12))) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
    }
  }
  return -1;
}

/* _FindMatchingAvailableCopy @ 0x97c06700 (164 bytes) */
int _FindMatchingAvailableCopy(param_1, param_2)
  int param_1;
  uint *param_2;
{
  int iVar1;
  int iVar2;
  uint loopIndex;
  
  loopIndex = 0;
  if (*param_2 != 0) {
    iVar2 = 0;
    do {
      iVar1 = iVar2 + param_2[1];
      if ((((*(int *)(iVar2 + param_2[1]) != 0) && (*(int *)(iVar1 + 4) == *(int *)(param_1 + 4)))
          && (*(int *)(iVar1 + 8) == *(int *)(param_1 + 8))) &&
         (((*(int *)(iVar1 + 0xc) == *(int *)(param_1 + 0xc) &&
           (*(int *)(iVar1 + 0x10) == *(int *)(param_1 + 0x10))) &&
          ((*(int *)(iVar1 + 0x38) == *(int *)(param_1 + 0x38) &&
           (*(int *)(iVar1 + 0x3c) == *(int *)(param_1 + 0x3c))))))) {
        return iVar1;
      }
      loopIndex = loopIndex + 1;
      iVar2 = iVar2 + 0x48;
    } while (loopIndex < *param_2);
  }
  return 0;
}

/* _UpdateACUsingAvailableCopyTable @ 0x97c067a4 (444 bytes) */
int _UpdateACUsingAvailableCopyTable(param_1, param_2, param_3)
  int param_1;
  uint *param_2;
  undefined4 param_3;
{
  int loopIndex2;
  bool bVar1;
  uint uVar2;
  undefined4 streamArray_97c06668;
  int iVar4;
  int iVar5;
  int *piVar6;
  uint loopIndex;
  int iVar8;
  int iVar9;
  uint uVar10;
  
  loopIndex = 0;
  if (*param_2 != 0) {
    piVar6 = (int *)param_2[1];
    iVar4 = 0;
    do {
      if (((*piVar6 != 0) && (piVar6[1] == *(int *)(param_1 + 0xc))) &&
         (piVar6[2] == *(int *)(param_1 + 0x10))) {
        uVar10 = *(uint *)(param_1 + 0x14);
        bVar1 = true;
        loopIndex2 = 0;
        uVar2 = 0;
        iVar8 = param_1;
        do {
          if (((uVar2 <= uVar10) && (*(int *)(iVar8 + 0x28) != 0)) &&
             (uVar2 = uVar2 + 1, piVar6[*(int *)(iVar8 + 0x18) + 10] != 1)) {
            bVar1 = false;
          }
          loopIndex2 = loopIndex2 + 1;
          iVar8 = iVar8 + 4;
          if (3 < loopIndex2) {
            if (bVar1) {
              *(int *)(param_1 + 0xc) = piVar6[3];
              *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(iVar4 + param_2[1] + 0x10);
              if (*(int *)(param_1 + 0x38) == 0) {
                iVar8 = *(int *)(iVar4 + param_2[1] + 0x38);
              }
              else {
                iVar8 = 1 - *(int *)(iVar4 + param_2[1] + 0x38);
              }
              *(int *)(param_1 + 0x38) = iVar8;
              iVar5 = 4;
              iVar8 = 0;
              loopIndex = 0;
              do {
                if ((uVar10 < loopIndex) || (iVar9 = iVar8 * 4 + param_1, *(int *)(iVar9 + 0x28) == 0))
                {
                  *(int *)(iVar8 * 4 + param_1 + 0x18) = iVar8;
                }
                else {
                  loopIndex = loopIndex + 1;
                  *(undefined4 *)(iVar9 + 0x18) =
                       *(undefined4 *)(*(int *)(iVar9 + 0x18) * 4 + iVar4 + param_2[1] + 0x18);
                }
                iVar8 = iVar8 + 1;
                iVar5 = iVar5 + -1;
              } while (iVar5 != 0);
              streamArray_97c06668 = ((int (*)())_GetStreamArray_97c06668)(*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x10),
                                 param_3);
              *(undefined4 *)(param_1 + 0x44) = streamArray_97c06668;
              return 1;
            }
            break;
          }
        } while (bVar1);
      }
      loopIndex = loopIndex + 1;
      iVar4 = iVar4 + 0x48;
      piVar6 = piVar6 + 0x12;
    } while (loopIndex < *param_2);
  }
  return 0;
}

/* _AddToAvailableCopyTable @ 0x97c06960 (1196 bytes) */
int _AddToAvailableCopyTable(param_1, param_2, param_3)
  uint *param_1;
  uint *param_2;
  undefined4 param_3;
{
  int loopIndex;
  uint uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int loopIndex2;
  int iVar13;
  int iVar14;
  undefined4 local_80;
  uint local_7c;
  int local_78;
  uint local_74;
  int local_70;
  uint local_6c;
  uint local_68 [4];
  uint local_58 [4];
  uint local_48 [8];
  
  iVar11 = 1;
  if (((((*param_1 >> 0x12 & 0xff) == 0) && (uVar9 = param_1[3], -1 < (int)uVar9)) &&
      (uVar8 = param_1[4], -1 < (int)uVar8)) &&
     ((uVar6 = param_1[2], (uVar6 >> 0x11 & 7) != (uVar8 >> 0x17 & 7) ||
      (*(short *)((int)param_1 + 0xe) != *(short *)((int)param_1 + 0x16))))) {
    uVar1 = param_1[1];
    if ((uVar1 & 0x10000000) != 0) {
      iVar11 = (uVar1 >> 0x1a & 3) + 1;
    }
    loopIndex2 = 0;
    if (iVar11 != 0) {
      do {
        local_78 = (uVar9 & 0xffff) + loopIndex2;
        local_6c = uVar1 >> 0x1a & 3;
        local_70 = (uint)*(ushort *)((int)param_1 + 0x16) + loopIndex2;
        local_74 = uVar8 >> 0x17 & 7;
        local_7c = uVar6 >> 0x11 & 7;
        local_48[0] = uVar8 >> 0x1b & 1;
        iVar13 = 4;
        local_80 = 1;
        loopIndex = 0;
        uVar9 = 0;
        puVar3 = &local_80;
        do {
          uVar10 = 0;
          uVar1 = 0;
          if (uVar9 <= local_6c) {
            if (loopIndex == 1) {
              uVar10 = uVar6 >> 0xe & 1;
              uVar1 = uVar6 >> 6 & 3;
            }
            else if (loopIndex < 2) {
              if (loopIndex == 0) {
                uVar10 = uVar6 >> 0xd & 1;
                uVar1 = uVar6 >> 8 & 3;
              }
            }
            else if (loopIndex == 2) {
              uVar10 = uVar6 >> 0xf & 1;
              uVar1 = uVar6 >> 4 & 3;
            }
            else if (loopIndex == 3) {
              uVar10 = uVar6 >> 0x10 & 1;
              uVar1 = uVar6 >> 2 & 3;
            }
          }
          uVar9 = uVar9 + uVar10;
          puVar3[10] = uVar10;
          if (uVar1 == 1) {
            puVar3[6] = uVar8 >> 0x13 & 3;
          }
          else if (uVar1 == 0) {
            puVar3[6] = uVar8 >> 0x15 & 3;
          }
          else if (uVar1 == 2) {
            puVar3[6] = uVar8 >> 0x11 & 3;
          }
          else if (uVar1 == 3) {
            puVar3[6] = uVar8 >> 0xf & 3;
          }
          loopIndex = loopIndex + 1;
          puVar3 = puVar3 + 1;
          iVar13 = iVar13 + -1;
        } while (iVar13 != 0);
        if (loopIndex < 4) {
          piVar4 = &local_70;
          iVar7 = 0;
          do {
            piVar4[10] = 0;
            piVar4[6] = 0;
            piVar4 = piVar4 + 1;
            iVar7 = iVar7 + -1;
          } while (iVar7 != 0);
        }
        local_48[2] = ((int (*)())_GetStreamArray_97c06668)(local_7c,local_78,param_3);
        local_48[3] = ((int (*)())_GetStreamArray_97c06668)(local_74,local_70,param_3);
        if (((param_1[1] & 0x10000000) != 0) && (loopIndex2 == 0)) {
          local_48[1] = 1;
          iVar7 = ((int (*)())_FindMatchingAvailableCopy)(&local_80,param_2);
          if (iVar7 == 0) {
            uVar9 = *param_2;
            if ((uVar9 & 7) == 0) {
              uVar6 = 0;
              uVar8 = _malloc(uVar9 * 0x48 + 0x240);
              _memset(uVar8,0,*param_2 * 0x48 + 0x240);
              uVar9 = 0;
              if (*param_2 != 0) {
                iVar7 = 0;
                do {
                  iVar13 = iVar7 + uVar8;
                  iVar14 = iVar7 + param_2[1];
                  iVar7 = iVar7 + 0x48;
                  _memcpy(iVar13,iVar14,0x48);
                  uVar9 = *param_2;
                  uVar6 = uVar6 + 1;
                } while (uVar6 < uVar9);
              }
              if (param_2[1] != 0) {
                _free(param_2[1]);
                uVar9 = *param_2;
              }
              param_2[1] = uVar8;
            }
            _memcpy(uVar9 * 0x48 + param_2[1],&local_80,0x48);
            *param_2 = *param_2 + 1;
          }
          else {
            iVar14 = 4;
            puVar3 = &local_80;
            iVar13 = iVar7;
            do {
              if ((puVar3[10] == 1) && (*(int *)(iVar13 + 0x28) == 0)) {
                iVar5 = *(int *)(iVar7 + 0x14);
                uVar2 = puVar3[6];
                *(undefined4 *)(iVar13 + 0x28) = 1;
                *(int *)(iVar7 + 0x14) = iVar5 + 1;
LAB_97c06bf0:
                *(undefined4 *)(iVar13 + 0x18) = uVar2;
              }
              else if (puVar3[10] == 1) {
                uVar2 = puVar3[6];
                goto LAB_97c06bf0;
              }
              iVar13 = iVar13 + 4;
              puVar3 = puVar3 + 1;
              iVar14 = iVar14 + -1;
            } while (iVar14 != 0);
          }
        }
        local_48[1] = 0;
        do {
          iVar7 = ((int (*)())_UpdateACUsingAvailableCopyTable)(&local_80,param_2,param_3);
        } while (iVar7 != 0);
        iVar7 = ((int (*)())_FindMatchingAvailableCopy)(&local_80,param_2);
        if (iVar7 == 0) {
          uVar9 = *param_2;
          if ((uVar9 & 7) == 0) {
            uVar6 = 0;
            uVar8 = _malloc(uVar9 * 0x48 + 0x240);
            _memset(uVar8,0,*param_2 * 0x48 + 0x240);
            uVar9 = 0;
            if (*param_2 != 0) {
              iVar7 = 0;
              do {
                uVar6 = uVar6 + 1;
                _memcpy(iVar7 + uVar8,iVar7 + param_2[1],0x48);
                uVar9 = *param_2;
                iVar7 = iVar7 + 0x48;
              } while (uVar6 < uVar9);
            }
            if (param_2[1] != 0) {
              _free(param_2[1]);
              uVar9 = *param_2;
            }
            param_2[1] = uVar8;
          }
          _memcpy(uVar9 * 0x48 + param_2[1],&local_80,0x48);
          *param_2 = *param_2 + 1;
        }
        else {
          iVar14 = 4;
          puVar3 = &local_80;
          iVar13 = iVar7;
          do {
            if ((puVar3[10] == 1) && (*(int *)(iVar13 + 0x28) == 0)) {
              iVar5 = *(int *)(iVar7 + 0x14);
              uVar2 = puVar3[6];
              *(undefined4 *)(iVar13 + 0x28) = 1;
              *(int *)(iVar7 + 0x14) = iVar5 + 1;
LAB_97c06d30:
              *(undefined4 *)(iVar13 + 0x18) = uVar2;
            }
            else if (puVar3[10] == 1) {
              uVar2 = puVar3[6];
              goto LAB_97c06d30;
            }
            iVar13 = iVar13 + 4;
            puVar3 = puVar3 + 1;
            iVar14 = iVar14 + -1;
          } while (iVar14 != 0);
        }
        loopIndex2 = loopIndex2 + 1;
        if (iVar11 <= loopIndex2) {
          return;
        }
        uVar9 = param_1[3];
        uVar8 = param_1[4];
        uVar6 = param_1[2];
        uVar1 = param_1[1];
      } while( true );
    }
  }
  return;
}

/* _FindInAvailableCopyTableSource @ 0x97c06e0c (304 bytes) */
int _FindInAvailableCopyTableSource(param_1, param_2, param_3)
  uint param_1;
  uint param_2;
  uint *param_3;
{
  bool bVar1;
  uint uVar2;
  int *piVar3;
  uint loopIndex;
  
  bVar1 = false;
  loopIndex = 0;
  if (*param_3 != 0) {
    piVar3 = (int *)param_3[1];
    do {
      if (((((*piVar3 != 0) && (piVar3[1] == (param_1 >> 0x17 & 7))) &&
           (piVar3[2] == (param_2 & 0xffff))) &&
          ((piVar3[0xf] == (param_1 >> 0xe & 1) &&
           (uVar2 = param_1 >> 0xc & 3, uVar2 <= (uint)piVar3[5])))) && (-1 < (int)param_1)) {
        bVar1 = true;
        if (uVar2 == 1) {
LAB_97c06ed8:
          if (*(int *)((int)piVar3 + (param_1 >> 0x11 & 0xc) + 0x28) == 1) {
LAB_97c06eec:
            if (*(int *)((int)piVar3 + (param_1 >> 0x13 & 0xc) + 0x28) == 1) goto LAB_97c06f04;
          }
        }
        else {
          if (uVar2 < 2) {
            if (uVar2 != 0) goto LAB_97c06f04;
            goto LAB_97c06eec;
          }
          if (uVar2 == 2) {
LAB_97c06ec4:
            if (*(int *)((int)piVar3 + (param_1 >> 0xf & 0xc) + 0x28) == 1) goto LAB_97c06ed8;
          }
          else {
            if (uVar2 != 3) goto LAB_97c06f04;
            if (*(int *)((int)piVar3 + (param_1 >> 0xd & 0xc) + 0x28) == 1) goto LAB_97c06ec4;
          }
        }
        bVar1 = false;
      }
LAB_97c06f04:
      loopIndex = loopIndex + 1;
      piVar3 = piVar3 + 0x12;
    } while ((loopIndex < *param_3) && (!bVar1));
  }
  if (bVar1) {
    return param_3[1] + (loopIndex - 1) * 0x48;
  }
  return 0;
}

/* _CheckRemoveAvailableCopyTable @ 0x97c06f3c (756 bytes) */
int _CheckRemoveAvailableCopyTable(param_1, param_2, param_3, param_4, param_5, param_6)
  uint param_1;
  uint param_2;
  int param_3;
  int param_4;
  uint *param_5;
  undefined4 param_6;
{
  int loopIndex3;
  int loopIndex;
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint loopIndex2;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uStack00000018;
  uint uStack0000001c;
  
  iVar4 = -1;
  uStack00000018 = param_1;
  uStack0000001c = param_2;
  if ((int)param_2 < 0) {
    iVar4 = ((int (*)())_GetStreamArray_97c06668)(param_1 >> 0x11 & 7,(param_2 & 0xffff) + param_3,param_6);
  }
  uVar6 = *param_5;
  loopIndex2 = 0;
  if (uVar6 != 0) {
    iVar9 = 0;
    do {
      uVar10 = param_5[1];
      if (*(int *)(iVar9 + uVar10) != 0) {
        bVar1 = false;
        if ((iVar4 < 0) || (iVar4 != *(int *)(iVar9 + uVar10 + 0x40))) {
          iVar7 = iVar9 + uVar10;
          if ((*(int *)(iVar7 + 0x3c) != 0) &&
             (*(uint *)(iVar7 + 4) == (uStack00000018 >> 0x11 & 7))) {
            uVar6 = (uStack0000001c & 0xffff) + param_3;
            if ((*(uint *)(iVar7 + 8) <= uVar6) &&
               (uVar6 <= *(uint *)(iVar7 + 8) + *(int *)(iVar7 + 0x14))) goto LAB_97c070dc;
          }
          iVar7 = iVar9 + uVar10;
          if ((*(uint *)(iVar7 + 4) == (uStack00000018 >> 0x11 & 7)) &&
             ((*(int *)(iVar7 + 8) == (uStack0000001c & 0xffff) + param_3 &&
              (*(int *)(iVar7 + 0x3c) == param_4)))) {
            piVar3 = (int *)(iVar7 + 0x28);
            loopIndex = 0;
            do {
              iVar8 = *piVar3;
              piVar3 = piVar3 + 1;
              if (iVar8 == 1) {
                if (loopIndex == 1) {
                  uVar6 = uStack00000018 >> 0xe & 1;
                }
                else if (loopIndex < 2) {
                  uVar6 = uStack00000018 >> 0xd & 1;
                  if (loopIndex != 0) goto LAB_97c070c8;
                }
                else if (loopIndex == 2) {
                  uVar6 = uStack00000018 >> 0xf & 1;
                }
                else {
                  if (loopIndex != 3) goto LAB_97c070c8;
                  uVar6 = uStack00000018 >> 0x10 & 1;
                }
                if (uVar6 == 1) {
                  bVar1 = true;
                  break;
                }
              }
LAB_97c070c8:
              loopIndex = loopIndex + 1;
            } while (loopIndex <= (int)(uStack00000018 >> 10 & 3));
            if (bVar1) goto LAB_97c070dc;
          }
        }
        else {
LAB_97c070dc:
          *(undefined4 *)(iVar9 + uVar10) = 0;
          uVar10 = param_5[1];
        }
        bVar1 = false;
        if ((iVar4 < 0) || (iVar4 != *(int *)(iVar9 + uVar10 + 0x44))) {
          iVar7 = iVar9 + uVar10;
          if ((*(int *)(iVar7 + 0x3c) != 0) &&
             (*(uint *)(iVar7 + 0xc) == (uStack00000018 >> 0x11 & 7))) {
            uVar6 = (uStack0000001c & 0xffff) + param_3;
            if ((*(uint *)(iVar7 + 0x10) <= uVar6) &&
               (uVar6 <= *(uint *)(iVar7 + 0x10) + *(int *)(iVar7 + 0x14))) goto LAB_97c07204;
          }
          iVar7 = iVar9 + uVar10;
          if ((*(uint *)(iVar7 + 0xc) == (uStack00000018 >> 0x11 & 7)) &&
             ((*(int *)(iVar7 + 0x10) == (uStack0000001c & 0xffff) + param_3 &&
              (*(int *)(iVar7 + 0x3c) == param_4)))) {
            loopIndex3 = 0;
            do {
              if (*(int *)(iVar7 + 0x28) == 1) {
                iVar2 = *(int *)(iVar7 + 0x18);
                if (iVar2 == 1) {
                  uVar6 = uStack00000018 >> 0xe & 1;
                }
                else {
                  uVar6 = uStack00000018 >> 0xd & 1;
                  if (iVar2 != 0) {
                    if (iVar2 == 2) {
                      uVar6 = uStack00000018 >> 0xf & 1;
                    }
                    else {
                      if (iVar2 != 3) goto LAB_97c071ec;
                      uVar6 = uStack00000018 >> 0x10 & 1;
                    }
                  }
                }
                if (uVar6 == 1) {
                  bVar1 = true;
                  break;
                }
              }
LAB_97c071ec:
              loopIndex3 = loopIndex3 + 1;
              iVar7 = iVar7 + 4;
            } while (loopIndex3 <= (int)(uStack00000018 >> 10 & 3));
          }
          if (bVar1) goto LAB_97c07204;
        }
        else {
LAB_97c07204:
          *(undefined4 *)(iVar9 + uVar10) = 0;
        }
        uVar6 = *param_5;
      }
      loopIndex2 = loopIndex2 + 1;
      iVar9 = iVar9 + 0x48;
    } while (loopIndex2 < uVar6);
  }
  return;
}

/* _ReplaceUsingAvailableCopyTable @ 0x97c07230 (580 bytes) */
int _ReplaceUsingAvailableCopyTable(param_1, param_2)
  uint *param_1;
  undefined4 param_2;
{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  int loopIndex;
  uint *puVar5;
  
  loopIndex = 0;
  puVar2 = param_1;
  puVar5 = param_1;
  if (*param_1 >> 0x1d != 0) {
    do {
      puVar2 = (uint *)((int (*)())_FindInAvailableCopyTableSource)(puVar5[4],puVar5[5],param_2);
      if (puVar2 != (uint *)0x0) {
        uVar3 = puVar5[4];
        uVar1 = (puVar2[3] & 7) << 0x17;
        puVar5[4] = uVar1 | uVar3 & 0xfc7fffff;
        *(undefined2 *)((int)puVar5 + 0x16) = *(undefined2 *)((int)puVar2 + 0x12);
        if ((uVar3 & 0x8000000) == 0) {
          puVar5[4] = (puVar2[0xe] & 1) << 0x1b | uVar1 | uVar3 & 0xf47fffff;
        }
        else {
          puVar5[4] = (1 - puVar2[0xe]) * 0x8000000 & 0x8000000 | uVar1 | uVar3 & 0xf47fffff;
        }
        uVar1 = puVar5[4];
        uVar3 = uVar1 >> 0xc & 3;
        if (uVar3 == 1) goto LAB_97c07398;
        if (uVar3 < 2) {
          if (uVar3 != 0) goto LAB_97c07448;
        }
        else {
          if (uVar3 == 2) goto LAB_97c07340;
          if (uVar3 != 3) goto LAB_97c07448;
          uVar3 = uVar1 >> 0xf & 3;
          if (uVar3 == 1) {
            uVar3 = puVar2[7];
LAB_97c07338:
            puVar5[4] = (uVar3 & 3) << 0xf | uVar1 & 0xfffe7fff;
          }
          else {
            if (1 < uVar3) {
              if (uVar3 == 2) {
                uVar3 = puVar2[8];
              }
              else {
                if (uVar3 != 3) goto LAB_97c07340;
                uVar3 = puVar2[9];
              }
              goto LAB_97c07338;
            }
            if (uVar3 == 0) {
              uVar3 = puVar2[6];
              goto LAB_97c07338;
            }
          }
LAB_97c07340:
          uVar1 = puVar5[4] >> 0x11 & 3;
          if (uVar1 == 1) {
            uVar1 = puVar2[7];
LAB_97c07390:
            puVar5[4] = (uVar1 & 3) << 0x11 | puVar5[4] & 0xfff9ffff;
          }
          else {
            if (1 < uVar1) {
              if (uVar1 == 2) {
                uVar1 = puVar2[8];
              }
              else {
                if (uVar1 != 3) goto LAB_97c07398;
                uVar1 = puVar2[9];
              }
              goto LAB_97c07390;
            }
            if (uVar1 == 0) {
              uVar1 = puVar2[6];
              goto LAB_97c07390;
            }
          }
LAB_97c07398:
          uVar1 = puVar5[4] >> 0x13 & 3;
          if (uVar1 == 1) {
            uVar1 = puVar2[7];
          }
          else if (uVar1 < 2) {
            if (uVar1 != 0) goto LAB_97c073f0;
            uVar1 = puVar2[6];
          }
          else if (uVar1 == 2) {
            uVar1 = puVar2[8];
          }
          else {
            if (uVar1 != 3) goto LAB_97c073f0;
            uVar1 = puVar2[9];
          }
          puVar5[4] = (uVar1 & 3) << 0x13 | puVar5[4] & 0xffe7ffff;
        }
LAB_97c073f0:
        uVar1 = puVar5[4] >> 0x15 & 3;
        if (uVar1 == 1) {
          uVar1 = puVar2[7];
        }
        else if (uVar1 < 2) {
          if (uVar1 != 0) goto LAB_97c07448;
          uVar1 = puVar2[6];
        }
        else if (uVar1 == 2) {
          uVar1 = puVar2[8];
        }
        else {
          if (uVar1 != 3) goto LAB_97c07448;
          uVar1 = puVar2[9];
        }
        puVar5[4] = (uVar1 & 3) << 0x15 | puVar5[4] & 0xff9fffff;
      }
LAB_97c07448:
      loopIndex = loopIndex + 1;
      puVar5 = puVar5 + 2;
    } while (loopIndex < (int)(*param_1 >> 0x1d));
  }
  return puVar2;
}

/* _RemoveFromAvailableCopyTable @ 0x97c07474 (152 bytes) */
int _RemoveFromAvailableCopyTable(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = *(uint *)(param_1 + 8);
  iVar2 = 1;
  if ((uVar1 & 0x1000) != 0) {
    iVar2 = (uVar1 >> 10 & 3) + 1;
    ((int (*)())_CheckRemoveAvailableCopyTable)(uVar1,*(undefined4 *)(param_1 + 0xc),0,1,param_2,param_3);
  }
  iVar3 = 0;
  if (iVar2 != 0) {
    do {
      iVar4 = iVar3 + 1;
      ((int (*)())_CheckRemoveAvailableCopyTable)(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),iVar3,0,param_2,param_3
                );
      iVar3 = iVar4;
    } while (iVar4 < iVar2);
  }
  return;
}

/* _CopyPropagateOperation @ 0x97c0750c (80 bytes) */
int _CopyPropagateOperation(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_ReplaceUsingAvailableCopyTable)(param_1,param_2);
  ((int (*)())_RemoveFromAvailableCopyTable)(param_1,param_2,param_3);
  return ((int (*)())_AddToAvailableCopyTable)(param_1,param_2,param_3);
}

/* _EndLocalAvailableCopyList @ 0x97c0755c (132 bytes) */
int _EndLocalAvailableCopyList(param_1)
  uint *param_1;
{
  uint uVar1;
  
  uVar1 = *param_1 >> 0x12 & 0xff;
  if (((((uVar1 != 0x4c) && (uVar1 != 0x55)) && (uVar1 != 0x58)) &&
      ((((uVar1 != 0x6a && (uVar1 != 0x6b)) &&
        ((uVar1 != 0x59 && ((uVar1 != 0x69 && (uVar1 != 0x54)))))) && (uVar1 != 0x4d)))) &&
     ((((uVar1 != 0x4b && (uVar1 != 0x57)) && (uVar1 != 0x5b)) &&
      ((uVar1 != 0x56 && (uVar1 != 0x5a)))))) {
    return 0;
  }
  return 1;
}

/* _LocalCopyPropagator @ 0x97c075e0 (236 bytes) */
int _LocalCopyPropagator(param_1)
  int param_1;
{
  uint *allocation;
  int iVar2;
  int isParamSampler;
  int iVar4;
  uint uVar5;
  
  iVar4 = **(int **)(param_1 + 0x20);
  allocation = (uint *)_malloc(8);
  allocation[1] = 0;
  *allocation = 0;
  for (; iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    iVar2 = ((int (*)())_EndLocalAvailableCopyList)(iVar4 + 0xc);
    if ((iVar2 != 0) && (uVar5 = 0, *allocation != 0)) {
      iVar2 = 0;
      do {
        isParamSampler = ((int (*)())_IsParamSampler)(*(undefined4 *)(iVar2 + allocation[1] + 0xc),
                                *(undefined4 *)(iVar2 + allocation[1] + 0x10),param_1);
        if (isParamSampler == 0) {
          *(undefined4 *)(iVar2 + allocation[1]) = 0;
        }
        uVar5 = uVar5 + 1;
        iVar2 = iVar2 + 0x48;
      } while (uVar5 < *allocation);
    }
    ((int (*)())_CopyPropagateOperation)(iVar4 + 0xc,allocation,param_1);
  }
  if (allocation[1] != 0) {
    _free(allocation[1]);
  }
  return _free(allocation);
}

/* _EmbedSamplerParamIndices @ 0x97c076cc (144 bytes) */
int _EmbedSamplerParamIndices(param_1)
  int param_1;
{
  bool bVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = **(int **)(param_1 + 0x20);
  if (iVar5 == 0) {
    return;
  }
  do {
    uVar3 = *(uint *)(iVar5 + 0xc) >> 0x12 & 0xff;
    if ((0x41 < uVar3) && ((uVar3 < 0x48 || (uVar3 == 0x62)))) {
      iVar4 = **(int **)(param_1 + 0x10);
      bVar1 = iVar4 == 0;
      if (!bVar1) {
        sVar2 = *(short *)(iVar4 + 0x12);
        while (*(short *)(iVar5 + 0x2a) != sVar2) {
          iVar4 = *(int *)(iVar4 + 8);
          if (iVar4 == 0) goto LAB_97c0774c;
          bVar1 = false;
          sVar2 = *(short *)(iVar4 + 0x12);
        }
        if ((!bVar1) && ((*(uint *)(iVar4 + 0xc) >> 0x10 & 0x1f) == 1)) {
          *(short *)(iVar5 + 0x32) = (short)*(uint *)(iVar4 + 0xc);
        }
      }
    }
LAB_97c0774c:
    iVar5 = *(int *)(iVar5 + 8);
    if (iVar5 == 0) {
      return;
    }
  } while( true );
}

/* _LinearizeFixOutputReads @ 0x97c0775c (916 bytes) */
int _LinearizeFixOutputReads(param_1)
  int param_1;
{
  uint loopIndex2;
  uint loopIndex;
  ushort uVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  undefined4 maxIndex;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint local_80;
  undefined4 local_7c;
  int local_78;
  int local_74;
  undefined4 local_70;
  uint local_6c;
  uint local_68;
  uint local_64;
  uint local_60;
  uint local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  
  iVar9 = **(int **)(param_1 + 0x1c);
  do {
    if (iVar9 == 0) {
      return;
    }
    bVar2 = false;
    uVar1 = *(ushort *)(iVar9 + 0x12);
    local_7c = **(int **)(param_1 + 0x20);
    if (local_7c != 0) {
      do {
        loopIndex = 0;
        uVar7 = *(uint *)(local_7c + 0xc) >> 0x1d;
        if (uVar7 != 0) {
          iVar3 = local_7c + 0x10;
          do {
            if ((((*(uint *)(iVar3 + 0xc) >> 0x17 & 7) == 3) && (*(ushort *)(iVar3 + 0x12) == uVar1)
                ) || (((*(uint *)(local_7c + 0xc) >> 0x12 & 0xff) == 0x6d &&
                      (((*(uint *)(local_7c + 0x14) >> 0x11 & 7) == 3 &&
                       (*(ushort *)(local_7c + 0x1a) == uVar1)))))) {
              bVar2 = true;
              break;
            }
            if (bVar2) break;
            loopIndex = loopIndex + 1;
            iVar3 = iVar3 + 8;
          } while (loopIndex < uVar7);
        }
        local_7c = *(int *)(local_7c + 8);
      } while (local_7c != 0);
      if (bVar2) {
        local_80 = 0;
        local_78 = local_7c;
        local_74 = local_7c;
        maxIndex = _PPStreamChunkListGetMaxIndex(*(undefined4 *)(param_1 + 4));
        local_7c = CONCAT22((*(unsigned short *)((unsigned char *)&(local_7c) + 0)),(short)maxIndex + 1);
        local_80 = (*(uint *)(iVar9 + 0xc) >> 0x18 & 3) << 0x18 |
                   (*(uint *)(iVar9 + 0xc) >> 0x1a & 7) << 0x1a |
                   *(uint *)(iVar9 + 0xc) & 0xe0000000 | local_80 & 0xffffff;
        _PPStreamAddTempUsage(param_1,&local_80);
        piVar4 = *(int **)(param_1 + 0x20);
        iVar3 = *piVar4;
        if (iVar3 != 0) {
          do {
            if (((*(uint *)(iVar3 + 0x14) >> 0x11 & 7) == 3) && (*(ushort *)(iVar3 + 0x1a) == uVar1)
               ) {
              *(uint *)(iVar3 + 0x14) = *(uint *)(iVar3 + 0x14) & 0xfff1ffff | 0x20000;
              *(undefined2 *)(iVar3 + 0x1a) = (*(unsigned short *)((unsigned char *)&(local_7c) + 2));
            }
            uVar6 = *(uint *)(iVar3 + 0xc);
            loopIndex2 = 0;
            if (uVar6 >> 0x1d != 0) {
              iVar8 = iVar3 + 0x10;
              do {
                if (((*(uint *)(iVar8 + 0xc) >> 0x17 & 7) == 3) &&
                   (*(ushort *)(iVar8 + 0x12) == uVar1)) {
                  *(uint *)(iVar8 + 0xc) = *(uint *)(iVar8 + 0xc) & 0xfc7fffff | 0x800000;
                  *(undefined2 *)(iVar8 + 0x12) = (*(unsigned short *)((unsigned char *)&(local_7c) + 2));
                  uVar6 = *(uint *)(iVar3 + 0xc);
                }
                loopIndex2 = loopIndex2 + 1;
                iVar8 = iVar8 + 8;
              } while (loopIndex2 < uVar6 >> 0x1d);
            }
            iVar3 = *(int *)(iVar3 + 8);
          } while (iVar3 != 0);
          piVar4 = *(int **)(param_1 + 0x20);
        }
        for (iVar3 = *piVar4; iVar3 != 0; iVar3 = *(int *)(iVar3 + 8)) {
          if ((*(uint *)(iVar3 + 0xc) >> 0x12 & 0xff) == 0x4d) {
            uVar7 = local_80 >> 0x18 & 3;
            local_68 = uVar7 << 10 | 0x6c;
            local_58 = 0;
            local_54 = 0;
            local_50 = 0;
            local_4c = 0;
            local_48 = 0;
            local_44 = 0;
            local_40 = *(undefined4 *)(iVar3 + 0x3c);
            local_70 = 0x20000000;
            local_3c = 0;
            if (uVar7 == 1) {
LAB_97c07a24:
              local_68 = local_68 | 0x4000;
LAB_97c07a2c:
              local_68 = local_68 | 0x2000;
            }
            else {
              if (1 < uVar7) {
                if (uVar7 != 2) {
                  if (uVar7 != 3) goto LAB_97c07a34;
                  local_68 = 0x10c6c;
                }
                local_68 = local_68 | 0x8000;
                goto LAB_97c07a24;
              }
              if (uVar7 == 0) goto LAB_97c07a2c;
            }
LAB_97c07a34:
            uVar7 = local_80 >> 0x18 & 3;
            local_6c = (local_80 >> 0x1d & 3) << 0x12 |
                       uVar7 << 0x1a | (local_80 >> 0x1a & 7) << 0x17;
            local_68 = local_68 | 0x60000;
            local_60 = uVar7 << 0xc | 0x8d8000;
            local_5c = local_7c & 0xffff;
            local_64 = (uint)uVar1;
            iVar8 = _PPStreamInsertOperationAfterChunk
                              (param_1,&local_70,0,0,*(undefined4 *)(iVar3 + 4));
            _PPStreamChangeBranchTargets
                      (param_1,*(uint *)(iVar3 + 0xc) & 0x3ffff,*(uint *)(iVar8 + 0xc) & 0x3ffff);
          }
        }
      }
    }
    iVar9 = *(int *)(iVar9 + 8);
  } while( true );
}

/* _glpPPShaderLinearizeStreamMgr @ 0x97c07af0 (320 bytes) */
int _glpPPShaderLinearizeStreamMgr(param_1, param_2)
  undefined4 param_1;
  uint param_2;
{
  undefined4 uVar1;
  
  if ((param_2 & 1) != 0) {
    ((int (*)())_InlineFunctionsBranch)(param_1);
  }
  if ((param_2 & 0x102) != 0) {
    _DetectConstantLoopsSimple(param_1);
    _UnrollConstantLoopsSimple(param_1,param_2 & 0x100);
  }
  if ((param_2 & 4) != 0) {
    _PPStreamPackIndices(param_1);
    _FlattenIfs(param_1);
  }
  if ((param_2 & 0x106) != 0) {
    ((int (*)())_LinearizeFixOutputReads)(param_1);
  }
  if ((param_2 & 0x80) != 0) {
    _ConstantPropagateFold(param_1);
  }
  if ((param_2 & 8) != 0) {
    ((int (*)())_LocalCopyPropagator)(param_1);
  }
  if ((param_2 & 0x10) != 0) {
    ((int (*)())_EmbedSamplerParamIndices)(param_1);
  }
  uVar1 = 0;
  if (param_2 != 0) {
    _PPStreamPackIndices(param_1);
    uVar1 = _ProgramNew(param_1);
    _Registerify(uVar1);
    _Blockify(uVar1);
  }
  if ((param_2 & 0x60) != 0) {
    _BuildGenKill(uVar1);
    _BuildLiveOut(uVar1);
  }
  if ((param_2 & 0x40) != 0) {
    _DeadCodeEliminationSimple(uVar1);
  }
  if ((param_2 & 0x20) != 0) {
    _BuildInterferenceSets(uVar1);
    _RegistersMerge(uVar1);
  }
  if (param_2 != 0) {
    _RegistersCleanup(uVar1);
    _ProgramFree(uVar1);
  }
  return _PPStreamPackIndices(param_1);
}

/* _glpPPShaderLinearize @ 0x97c07c30 (156 bytes) */
int _glpPPShaderLinearize(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  undefined4 uVar1;
  undefined4 uVar2;
  int local_30 [7];
  
  uVar2 = 0;
  local_30[0] = 0;
  uVar1 = _PPStreamCreate();
  _PPStreamAttachStream(uVar1,param_1);
  ((int (*)())_glpPPShaderLinearizeStreamMgr)(uVar1,param_2);
  _PPStreamGetStream(uVar1,0,local_30);
  if (local_30[0] != 0) {
    uVar2 = _malloc(local_30[0] * 8 + 0xfU & 0xfffffff0);
    _PPStreamGetStream(uVar1,uVar2,local_30);
  }
  _PPStreamFree(uVar1);
  return uVar2;
}

/* _glpFreePPShaderLinearize @ 0x97c07ccc (12 bytes) */
int _glpFreePPShaderLinearize(param_1)
  int param_1;
{
  if (param_1 == 0) {
    return;
  }
  return _free(param_1);
}

/* _BitSetNew @ 0x97c07cd8 (104 bytes) */
int _BitSetNew(param_1)
  uint param_1;
{
  uint allocation2;
  uint *allocation;
  uint uVar2;
  
  uVar2 = (param_1 >> 3 & 0x1ffffffc) + 4;
  allocation = (uint *)_malloc(0xc);
  *allocation = param_1;
  allocation[1] = uVar2;
  allocation2 = _malloc(uVar2);
  allocation[2] = allocation2;
  ((int (*)())_BitSetSetRangeEqualsInternal)(allocation,0,param_1,0);
  return allocation;
}

/* _BitSetClone @ 0x97c07d40 (64 bytes) */
int _BitSetClone(bitSet)
  undefined4 *bitSet;
{
  undefined4 uVar1;
  
  uVar1 = ((int (*)())_BitSetNew)(*bitSet);
  _BitSetCopyEquals(uVar1,bitSet);
  return uVar1;
}

/* _BitSetFree @ 0x97c07d80 (52 bytes) */
int _BitSetFree(param_1)
  int param_1;
{
  undefined4 extraout_r3;
  
  _free(*(undefined4 *)(param_1 + 8));
  _free(param_1);
  return extraout_r3;
}

/* _BitSetGetSizeInBits @ 0x97c07db4 (8 bytes) */
int _BitSetGetSizeInBits(bitSet)
  undefined4 *bitSet;
{
  return *bitSet;
}

/* _BitSetGetEquals @ 0x97c07dbc (88 bytes) */
int _BitSetGetEquals(param_1, param_2)
  int param_1;
  uint param_2;
{
  ((int (*)())_BitSetExpandEquals)(param_1,param_2 + 1);
  return (*(uint *)((param_2 >> 3 & 0x1ffffffc) + *(int *)(param_1 + 8)) & 1 << (param_2 & 0x1f)) !=
         0;
}

/* _BitSetSetEquals @ 0x97c07e14 (88 bytes) */
int _BitSetSetEquals(bitSet, param_2)
  int bitSet;
  uint param_2;
{
  uint uVar1;
  
  ((int (*)())_BitSetExpandEquals)(bitSet,param_2 + 1);
  uVar1 = param_2 >> 3 & 0x1ffffffc;
  *(uint *)(uVar1 + *(int *)(bitSet + 8)) =
       *(uint *)(uVar1 + *(int *)(bitSet + 8)) | 1 << (param_2 & 0x1f);
  return bitSet;
}

/* _BitSetClearEquals @ 0x97c07e6c (88 bytes) */
int _BitSetClearEquals(bitSet, param_2)
  int bitSet;
  uint param_2;
{
  uint uVar1;
  
  ((int (*)())_BitSetExpandEquals)(bitSet,param_2 + 1);
  uVar1 = param_2 >> 3 & 0x1ffffffc;
  *(uint *)(uVar1 + *(int *)(bitSet + 8)) =
       *(uint *)(uVar1 + *(int *)(bitSet + 8)) &
       (-2 << (param_2 & 0x1f) | 0xfffffffeU >> 0x20 - (param_2 & 0x1f));
  return bitSet;
}

/* _BitSetSetRangeEquals @ 0x97c07ec4 (84 bytes) */
int _BitSetSetRangeEquals(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())_BitSetExpandEquals)(param_1,param_3);
  ((int (*)())_BitSetSetRangeEqualsInternal)(param_1,param_2,param_3,param_4);
  return param_1;
}

/* _BitSetSetRangeEqualsInternal @ 0x97c07f18 (100 bytes) */
int _BitSetSetRangeEqualsInternal(bitSet, param_2, param_3, param_4)
  int bitSet;
  uint param_2;
  uint param_3;
  int param_4;
{
  int iVar1;
  uint uVar2;
  
  if (param_3 <= param_2) {
    return;
  }
  iVar1 = param_3 - param_2;
  do {
    if (param_4 == 0) {
      uVar2 = param_2 >> 3 & 0x1ffffffc;
      *(uint *)(uVar2 + *(int *)(bitSet + 8)) =
           *(uint *)(uVar2 + *(int *)(bitSet + 8)) & ~(1 << (param_2 & 0x1f));
    }
    else {
      uVar2 = param_2 >> 3 & 0x1ffffffc;
      *(uint *)(uVar2 + *(int *)(bitSet + 8)) =
           *(uint *)(uVar2 + *(int *)(bitSet + 8)) | 1 << (param_2 & 0x1f);
    }
    param_2 = param_2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}

/* _BitSetExpandEquals @ 0x97c07f7c (60 bytes) */
int _BitSetExpandEquals(bitSet, param_2)
  uint *bitSet;
  uint param_2;
{
  if (*bitSet < param_2) {
    ((int (*)())_BitSetSetSizeEquals)(bitSet,param_2);
  }
  return bitSet;
}

/* _BitSetSetSizeEquals @ 0x97c07fb8 (112 bytes) */
int _BitSetSetSizeEquals(bitSet, param_2)
  uint *bitSet;
  uint param_2;
{
  uint allocation;
  uint uVar2;
  
  if (*bitSet != param_2) {
    uVar2 = (param_2 >> 3 & 0x1ffffffc) + 4;
    allocation = _realloc(bitSet[2],uVar2);
    bitSet[2] = allocation;
    ((int (*)())_BitSetSetRangeEqualsInternal)(bitSet,*bitSet,param_2,0);
    *bitSet = param_2;
    bitSet[1] = uVar2;
  }
  return bitSet;
}

/* _BitSetNextSetBit @ 0x97c08030 (136 bytes) */
int _BitSetNextSetBit(bitSet, param_2)
  uint *bitSet;
  int param_2;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = param_2 + 1U >> 5;
  uVar3 = param_2 + 1U & 0x1f;
  if (uVar4 < bitSet[1] >> 2) {
    do {
      uVar1 = *(uint *)(uVar4 * 4 + bitSet[2]);
      if ((uVar1 != 0) && (uVar3 < 0x20)) {
        do {
          if (((uVar1 & 1 << (uVar3 & 0x3f)) != 0) &&
             (uVar2 = uVar4 * 0x20 + uVar3, uVar2 < *bitSet)) {
            return uVar2;
          }
          uVar3 = uVar3 + 1;
        } while (uVar3 < 0x20);
      }
      uVar4 = uVar4 + 1;
      uVar3 = 0;
    } while ((int)uVar4 < (int)(bitSet[1] >> 2));
  }
  return 0xffffffff;
}

/* _BitSetAndEquals @ 0x97c080b8 (128 bytes) */
int _BitSetAndEquals(bitSet, param_2)
  undefined4 *bitSet;
  undefined4 *param_2;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  ((int (*)())_BitSetExpandEquals)(bitSet,*param_2);
  ((int (*)())_BitSetExpandEquals)(param_2,*bitSet);
  iVar2 = 0;
  for (uVar3 = (uint)bitSet[1] >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    iVar1 = iVar2 * 4;
    iVar2 = iVar2 + 1;
    *(uint *)(iVar1 + bitSet[2]) = *(uint *)(iVar1 + bitSet[2]) & *(uint *)(iVar1 + param_2[2]);
  }
  return bitSet;
}

/* _BitSetAndNotEquals @ 0x97c08138 (128 bytes) */
int _BitSetAndNotEquals(bitSet, param_2)
  undefined4 *bitSet;
  undefined4 *param_2;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  ((int (*)())_BitSetExpandEquals)(bitSet,*param_2);
  ((int (*)())_BitSetExpandEquals)(param_2,*bitSet);
  iVar2 = 0;
  for (uVar3 = (uint)bitSet[1] >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    iVar1 = iVar2 * 4;
    iVar2 = iVar2 + 1;
    *(uint *)(iVar1 + bitSet[2]) = *(uint *)(iVar1 + bitSet[2]) & ~*(uint *)(iVar1 + param_2[2]);
  }
  return bitSet;
}

/* _BitSetOrEquals @ 0x97c081b8 (128 bytes) */
int _BitSetOrEquals(bitSet, param_2)
  undefined4 *bitSet;
  undefined4 *param_2;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  ((int (*)())_BitSetExpandEquals)(bitSet,*param_2);
  ((int (*)())_BitSetExpandEquals)(param_2,*bitSet);
  iVar2 = 0;
  for (uVar3 = (uint)bitSet[1] >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    iVar1 = iVar2 * 4;
    iVar2 = iVar2 + 1;
    *(uint *)(iVar1 + bitSet[2]) = *(uint *)(iVar1 + bitSet[2]) | *(uint *)(iVar1 + param_2[2]);
  }
  return bitSet;
}

