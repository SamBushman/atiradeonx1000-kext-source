#include "decls.h"

/* atifsReplayTextureOps @ 0x3e4d0 (276 bytes) */
int atifsReplayTextureOps(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
  uint *param_4;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int loopIndex;
  
  if (param_3 != 0) {
    loopIndex = 0;
    do {
      uVar5 = *param_4;
      param_4 = param_4 + 1;
      uVar4 = 0x8977;
      uVar1 = uVar5 & 0x300;
      iVar2 = (uVar5 >> 0xc & 0xff) + 0x8921;
      if (uVar1 != 0x100) {
        if (uVar1 < 0x101) {
          uVar4 = 0x8976;
          if (uVar1 != 0) {
LAB_0003e540:
            uVar4 = 0;
          }
        }
        else {
          uVar4 = 0x8978;
          if (uVar1 != 0x200) {
            if (uVar1 != 0x300) goto LAB_0003e540;
            uVar4 = 0x8979;
          }
        }
      }
      uVar1 = uVar5 >> 0x14 & 0xff;
      if ((uVar5 & 7) == 1) {
        iVar3 = uVar1 + 0x8921;
      }
      else {
        iVar3 = 0;
        if ((uVar5 & 7) == 5) {
          iVar3 = uVar1 + 0x84c0;
        }
      }
      if ((uVar5 & 0xf0) == 0) {
        glPassTexCoordATI_impl(param_1,iVar2,iVar3,uVar4);
      }
      else {
        glSampleMapATI_impl(param_1,iVar2,iVar3,uVar4);
      }
      loopIndex = loopIndex + 1;
    } while (param_3 != loopIndex);
  }
  return;
}

/* atifsReplayColorAlphaOps @ 0x3e600 (1352 bytes) */
int atifsReplayColorAlphaOps(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
  uint *param_4;
{
  undefined *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint *recordPtr;
  int loopIndex;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  uint uVar11;
  int iVar12;
  undefined4 local_68;
  undefined4 local_64;
  uint local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  
  if (param_3 != 0) {
    iVar9 = 0;
    loopIndex = 0;
    do {
      uVar5 = *param_4;
      param_4 = param_4 + 1;
      uVar2 = uVar5 & 0xf00;
      if (uVar2 == 0x500) {
        uVar10 = 0x8967;
      }
      else if (uVar2 < 0x501) {
        if (uVar2 == 0x200) {
          uVar10 = 0x8964;
        }
        else if (uVar2 < 0x201) {
          if (uVar2 == 0) {
            uVar10 = 0x8961;
          }
          else {
            uVar10 = 0x8963;
            if (uVar2 != 0x100) {
LAB_0003e674:
              uVar10 = 0;
            }
          }
        }
        else if (uVar2 == 0x300) {
          uVar10 = 0x8965;
        }
        else {
          if (uVar2 != 0x400) goto LAB_0003e674;
          uVar10 = 0x8966;
        }
      }
      else if (uVar2 == 0x800) {
        uVar10 = 0x896a;
      }
      else if (uVar2 < 0x801) {
        if (uVar2 == 0x600) {
          uVar10 = 0x8968;
        }
        else {
          if (uVar2 != 0x700) goto LAB_0003e674;
          uVar10 = 0x8969;
        }
      }
      else if (uVar2 == 0x900) {
        uVar10 = 0x896b;
      }
      else {
        if (uVar2 != 0xa00) goto LAB_0003e674;
        uVar10 = 0x896c;
      }
      uVar11 = 0;
      iVar8 = (uVar5 >> 0x14 & 0xff) + 0x8921;
      if ((uVar5 & 0xf000) != 0) {
        puVar1 = (undefined *)(uVar5 & 0x7000);
        uVar11 = 4;
        if (puVar1 != (undefined *)0x3000) {
          if (puVar1 < (undefined *)0x3001) {
            uVar11 = 1;
            if ((puVar1 != (undefined *)0x1000) && (uVar11 = 2, puVar1 != (undefined *)0x2000)) {
LAB_0003e7c8:
              uVar11 = 0;
            }
          }
          else {
            uVar11 = 0x10;
            if ((puVar1 != ((unsigned char *)0x00005000)) && (uVar11 = 0x20, puVar1 != (undefined *)0x6000)) {
              if (puVar1 != (undefined *)0x4000) goto LAB_0003e7c8;
              uVar11 = 8;
            }
          }
        }
        if ((uVar5 & 0x8000) != 0) {
          uVar11 = uVar11 | 0x40;
        }
      }
      if (uVar2 == 0) {
        iVar9 = 1;
LAB_0003e830:
        recordPtr = &local_60;
        iVar12 = iVar9;
        do {
          uVar4 = *param_4;
          param_4 = param_4 + 1;
          uVar2 = uVar4 & 7;
          uVar3 = uVar4 >> 0x14 & 0xff;
          if (uVar2 == 2) {
            uVar3 = uVar3 + 0x8941;
          }
          else if (uVar2 < 3) {
            if (uVar2 != 1) goto LAB_0003e868;
            uVar3 = uVar3 + 0x8921;
          }
          else if (uVar2 != 3) {
            if (uVar2 == 4) {
              if (uVar3 == 0) {
                uVar3 = 0x8577;
              }
              else {
                if (uVar3 != 1) goto LAB_0003e868;
                uVar3 = 0x896d;
              }
            }
            else {
LAB_0003e868:
              uVar3 = 0;
            }
          }
          uVar2 = uVar4 & 0x7000;
          recordPtr[-2] = uVar3;
          if (uVar2 == 0x2000) {
            uVar3 = 0x1904;
          }
          else if (uVar2 < 0x2001) {
            uVar3 = 0x1903;
            if (uVar2 != 0x1000) {
LAB_0003e904:
              uVar3 = 0;
            }
          }
          else {
            uVar3 = 0x1905;
            if ((uVar2 != 0x3000) && (uVar3 = 0x1906, uVar2 != 0x4000)) goto LAB_0003e904;
          }
          recordPtr[-1] = uVar3;
          uVar2 = 0;
          if ((uVar4 & 0xf00) != 0) {
            uVar2 = uVar4 >> 6 & 4;
            if ((uVar4 & 0x200) != 0) {
              uVar2 = uVar2 | 1;
            }
            if ((uVar4 & 0x400) != 0) {
              uVar2 = uVar2 | 8;
            }
            if ((uVar4 & 0x800) != 0) {
              uVar2 = uVar2 | 2;
            }
          }
          *recordPtr = uVar2;
          recordPtr = recordPtr + 3;
          iVar12 = iVar12 + -1;
        } while (iVar12 != 0);
      }
      else {
        if (uVar2 < 0x501) {
          iVar9 = 2;
          goto LAB_0003e830;
        }
        if (uVar2 < 0xa01) {
          iVar9 = 3;
          goto LAB_0003e830;
        }
        if (iVar9 != 0) goto LAB_0003e830;
      }
      if ((uVar5 & 0x70000) == 0) {
        uVar2 = 0;
        if ((uVar5 & 0xf0000) == 0) goto LAB_0003e9b8;
      }
      else {
        uVar2 = (uVar5 & 0x70000) >> 0x10 & 1;
        if ((uVar5 & 0x20000) != 0) {
          uVar2 = uVar2 | 2;
        }
        if ((uVar5 & 0x40000) != 0) {
          uVar2 = uVar2 | 4;
        }
LAB_0003e9b8:
        if (iVar9 == 2) {
          glColorFragmentOp2ATI_impl(param_1,uVar10,iVar8,uVar2,uVar11,local_68,local_64,local_60,local_5c,
                       local_58,local_54);
        }
        else if (iVar9 == 3) {
          glColorFragmentOp3ATI_impl(param_1,uVar10,iVar8,uVar2,uVar11,local_68,local_64,local_60,local_5c,
                       local_58,local_54,local_50,local_4c,local_48);
        }
        else if (iVar9 == 1) {
          glColorFragmentOp1ATI_impl(param_1,uVar10,iVar8,uVar2,uVar11,local_68,local_64,local_60);
        }
      }
      if (((uVar5 & 0x80000) != 0) || ((uVar5 & 0xf0000) == 0)) {
        if (iVar9 == 2) {
          glAlphaFragmentOp2ATI_impl(param_1,uVar10,iVar8,uVar11,local_68,local_64,local_60,local_5c,local_58,
                       local_54);
        }
        else if (iVar9 == 3) {
          glAlphaFragmentOp3ATI_impl(param_1,uVar10,iVar8,uVar11,local_68,local_64,local_60,local_5c,local_58,
                       local_54,local_50,local_4c,local_48);
        }
        else if (iVar9 == 1) {
          glAlphaFragmentOp1ATI_impl(param_1,uVar10,iVar8,uVar11,local_68,local_64,local_60);
        }
      }
      loopIndex = loopIndex + 1;
    } while (param_3 != loopIndex);
  }
  return;
}

/* atifsReplayProgram @ 0x3eb70 (296 bytes) */
int atifsReplayProgram(param_1, param_2, param_3)
  int param_1;
  uint *param_2;
  undefined4 param_3;
{
  ushort uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint loopIndex;
  uint *puVar6;
  
  *(undefined2 *)(param_1 + 0x2800) = 0;
  glBeginFragmentShaderATI_impl(param_1);
  uVar1 = *(ushort *)((int)param_2 + 0x16);
  uVar4 = *param_2 >> 0x10 & 0xff;
  puVar6 = param_2 + (*param_2 & 0xffff);
  if (uVar4 != 0) {
    loopIndex = 0;
    do {
      uVar2 = *puVar6;
      puVar6 = puVar6 + 1;
      if ((uVar2 & 3) == 1) {
        glSetFragmentShaderConstantATI_impl(param_1,(uVar2 >> 0x14 & 0xff) + 0x8941,
                     (int)param_2 + (uVar2 >> 8 & 0xff0) + (uint)uVar1 * 4);
      }
      loopIndex = loopIndex + 1;
    } while (uVar4 != loopIndex);
  }
  ((int (*)())atifsReplayTextureOps)(param_1,param_3,param_2[1] >> 0x10 & 0xff,param_2 + (param_2[1] & 0xffff));
  ((int (*)())atifsReplayColorAlphaOps)(param_1,param_3,param_2[2] >> 0x10 & 0xff,param_2 + (param_2[2] & 0xffff));
  ((int (*)())atifsReplayTextureOps)(param_1,param_3,param_2[3] >> 0x10 & 0xff,param_2 + (param_2[3] & 0xffff));
  ((int (*)())atifsReplayColorAlphaOps)(param_1,param_3,param_2[4] >> 0x10 & 0xff,param_2 + (param_2[4] & 0xffff));
  glEndFragmentShaderATI_impl(param_1);
  uVar3 = FUN_000a11a0(param_1);
  *(undefined4 *)(param_1 + 0x27b8) = uVar3;
  return 1;
}

/* fpilEmitAngleConstants @ 0x3eca0 (164 bytes) */
int fpilEmitAngleConstants(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  uVar5 = *(uint *)(param_1[0xd] + 0x20);
  if ((uVar5 & 0x4000000) == 0) {
    *(uint *)(param_1[0xd] + 0x20) = uVar5 | 0x4000000;
    fVar4 = FLOAT_001aa13c;
    fVar3 = FLOAT_001aa138;
    fVar2 = FLOAT_001aa134;
    fVar1 = FLOAT_001aa130;
    iVar6 = param_1[6];
    iVar7 = param_1[10];
    *(undefined4 *)(iVar6 * 4 + iVar7) = 0x1c;
    iVar7 = iVar6 * 4 + iVar7;
    uVar5 = *(uint *)(*param_1 + 0x28);
    *(float *)(iVar7 + 8) = fVar1;
    *(uint *)(iVar7 + 4) = uVar5 & 0xffff | 0x10000;
    *(float *)(iVar7 + 0x14) = fVar4;
    *(float *)(iVar7 + 0xc) = fVar2;
    *(float *)(iVar7 + 0x10) = fVar3;
    param_1[6] = param_1[6] + 6;
  }
  return param_1[9];
}

/* fpilClassifyDestination @ 0x3ed50 (60 bytes) */
int fpilClassifyDestination(param_1, param_2)
  int *param_1;
  int param_2;
{
  uint uVar1;
  
  uVar1 = *(uint *)(((uint)*(ushort *)(param_2 + 6) + *(int *)(*param_1 + 0x14)) * 8 + *param_1) >>
          0x1a & 7;
  if (uVar1 == 3) {
    return 1;
  }
  return (uint)(uVar1 == 4) << 1;
}

/* fpilBuildDestinationToken @ 0x3ed90 (160 bytes) */
int fpilBuildDestinationToken(translator, irDest, outToken, outMask, saturate)
  int *translator;
  uint *irDest;
  uint *outToken;
  uint *outMask;
  int saturate;
{
  ushort irIndex;
  uint regIndex;
  uint modifier;
  int iVar4;
  uint irWord;
  
  irWord = *irDest;
  modifier = 0;
  if ((irWord & 0xe0000) == 0x20000) {
    regIndex = (uint)*(ushort *)((int)irDest + 6);
  }
  else {
    irIndex = *(ushort *)((int)irDest + 6);
    iVar4 = *(int *)(*translator + 0x10);
    translator[4] = 1 << (irIndex & 0x3f) | translator[4];
    regIndex = (uint)irIndex + iVar4 + 1;
    irWord = *irDest;
  }
  if (saturate != 0) {
    modifier = 0x100;
  }
  *outToken = regIndex & 0xffff | 0x440000;
  *outMask = (irWord >> 0x10 & 1) << 6 |
             (irWord >> 0xf & 1) << 4 | (irWord >> 0xe & 1) << 2 | irWord >> 0xd & 1 | modifier;
  return 0;
}

/* fpilSetComponentSelect @ 0x3ee30 (88 bytes) */
int fpilSetComponentSelect(param_1, param_2, param_3)
  uint param_1;
  int param_2;
  uint *param_3;
{
  if (param_2 == 0) {
    *param_3 = param_1 & 7 | *param_3 & 0xfffffff8;
    return;
  }
  if (param_2 == 1) {
    *param_3 = (param_1 & 7) << 4 | *param_3 & 0xffffff8f;
    return;
  }
  if (param_2 == 2) {
    *param_3 = (param_1 & 7) << 8 | *param_3 & 0xfffff8ff;
    return;
  }
  *param_3 = (param_1 & 7) << 0xc | *param_3 & 0xffff8fff;
  return;
}

/* fpilEmitScalarConstant @ 0x3eea0 (168 bytes) */
int fpilEmitScalarConstant(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint *param_3;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  if ((*(uint *)(param_1 + 0x14) >> 0x15 & 0x3f) < 0x20) {
    iVar1 = *(int *)(param_1 + 0x28);
    iVar3 = *(int *)(param_1 + 0x18) * 4;
    *(undefined4 *)(iVar3 + iVar1) = 0x1c;
    iVar3 = iVar3 + iVar1;
    uVar2 = *(uint *)(param_1 + 0x14);
    *(undefined4 *)(iVar3 + 0x14) = 0;
    *(undefined4 *)(iVar3 + 0xc) = 0;
    *(undefined4 *)(iVar3 + 0x10) = 0;
    *(undefined4 *)(iVar3 + 8) = param_2;
    *(uint *)(iVar3 + 4) = uVar2 >> 0x15 & 0x3f | 0x20000;
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 6;
    *param_3 = *(uint *)(param_1 + 0x14) >> 0x15 & 0x3f;
    *(uint *)(param_1 + 0x14) =
         ((*(uint *)(param_1 + 0x14) >> 0x15 & 0x3f) + 1) * 0x200000 & 0x7e00000 |
         *(uint *)(param_1 + 0x14) & 0xf81fffff;
    return *(int *)(param_1 + 0x24);
  }
  if (*(int *)(param_1 + 0x24) != 0) {
    return *(int *)(param_1 + 0x24);
  }
  *(undefined4 *)(param_1 + 0x24) = 4;
  return 4;
}

/* fpilReserveTokens @ 0x3ef50 (240 bytes) */
int fpilReserveTokens(translator, nWords, outPtr)
  int translator;
  int nWords;
  int *outPtr;
{
  int allocation;
  uint uVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)(translator + 0x28);
  iVar2 = *(int *)(translator + 0x2c);
  uVar1 = *(uint *)(translator + 0x30);
  if (uVar1 < (uint)(nWords + iVar2)) {
    if (uVar1 == 0) {
      uVar1 = 0x10;
    }
    else {
      uVar1 = uVar1 << 1;
    }
    for (; uVar1 < (uint)(nWords + iVar2); uVar1 = uVar1 << 1) {
    }
    if (*piVar3 == 0) {
      allocation = _malloc(uVar1 << 2);
    }
    else {
      allocation = _realloc(*piVar3,uVar1 << 2);
    }
    if (allocation == 0) {
      if (*(int *)(translator + 0x24) != 0) {
        return *(int *)(translator + 0x24);
      }
      *(undefined4 *)(translator + 0x24) = 1;
      return 1;
    }
    *piVar3 = allocation;
    *(uint *)(translator + 0x30) = uVar1;
    iVar2 = *(int *)(translator + 0x2c);
  }
  *(int *)(translator + 0x2c) = nWords + iVar2;
  *outPtr = iVar2 * 4 + *piVar3;
  return 0;
}

/* fpilMapConstantRegister @ 0x3f050 (336 bytes) */
int fpilMapConstantRegister(translator, instIndex, outRegister)
  int *translator;
  int instIndex;
  undefined4 *outRegister;
{
  int constEntryOffset;
  int constEntry;
  uint cachedPairCount;
  int loopIndex;
  byte *nextPairByte;
  ushort wantedIndex;
  int instRecord;
  byte *pairCache;
  int program;
  byte *scanPtr;
  uint entryWord;
  uint pairsLeft;
  
  program = *translator;
  instRecord = program + *(int *)(program + 0x54) * 8 + instIndex * 8;
  if ((*(uint *)(instRecord + 0x18) & 0x3800000) == 0x1000000) {
    constEntryOffset = ((uint)*(ushort *)(instRecord + 0x1e) + *(int *)(program + 0x2c)) * 8;
    entryWord = *(uint *)(program + constEntryOffset);
    constEntry = program + constEntryOffset;
    if (((entryWord & 0x1f0000) == 0x10000) && ((entryWord & 0x1c000000) == 0xc000000)) {
      *outRegister = *(undefined4 *)((uint)*(ushort *)(constEntry + 2) * 0x10 + translator[3]);
      pairCache = (byte *)translator[0xd];
      cachedPairCount = *(uint *)(pairCache + 0x20) >> 0x1b;
      if (cachedPairCount == 0) {
        wantedIndex = *(ushort *)(constEntry + 2);
LAB_0003f164:
        pairCache[cachedPairCount * 2] = (byte)wantedIndex;
        *(char *)(cachedPairCount * 2 + translator[0xd] + 1) = (char)*outRegister;
        *(int *)(translator[0xd] + 0x20) = *(int *)(translator[0xd] + 0x20) + 0x8000000;
        return 0;
      }
      wantedIndex = *(ushort *)(constEntry + 2);
      if (*pairCache != wantedIndex) {
        loopIndex = 0;
        scanPtr = pairCache;
        pairsLeft = cachedPairCount;
        do {
          loopIndex = loopIndex + 1;
          pairsLeft = pairsLeft - 1;
          if (pairsLeft == 0) {
            if (0xf < loopIndex) {
              if (translator[9] != 0) {
                return translator[9];
              }
              translator[9] = 4;
              return 4;
            }
            goto LAB_0003f164;
          }
          nextPairByte = scanPtr + 2;
          scanPtr = scanPtr + 2;
        } while (*nextPairByte != wantedIndex);
      }
      return 0;
    }
  }
  if (translator[9] != 0) {
    return translator[9];
  }
  translator[9] = 2;
  return 2;
}

/* fpilTranslateSource @ 0x3f1c0 (700 bytes) */
int fpilTranslateSource(translator, irSource, outToken, outSwizzle)
  int *translator;
  uint *irSource;
  uint *outToken;
  uint *outSwizzle;
{
  int iVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  undefined *puVar10;
  
  uVar7 = *irSource;
  uVar5 = uVar7 & 0x3800000;
  if (uVar5 == 0) {
    iVar8 = *translator;
    iVar1 = ((uint)*(ushort *)((int)irSource + 6) + *(int *)(iVar8 + 0x24)) * 8;
    switch(*(ushort *)(iVar8 + iVar1) & 0xf) {
    default:
switchD_0003f230_caseD_0:
      if (translator[9] != 0) {
        return translator[9];
      }
      translator[9] = 3;
      return 3;
    case 1:
      bVar2 = false;
      puVar10 = ((unsigned char *)0x00160000);
      break;
    case 2:
      bVar2 = false;
      puVar10 = (undefined *)0x120000;
      break;
    case 3:
      bVar2 = false;
      puVar10 = (undefined *)0x130000;
      break;
    case 5:
      bVar2 = true;
      puVar10 = (undefined *)0x100000;
      break;
    case 7:
      bVar2 = false;
      puVar10 = (undefined *)(*(uint *)(iVar8 + iVar1) & 0x1f | 0x110000);
    }
  }
  else if (uVar5 == 0x1000000) {
    bVar2 = false;
    puVar10 = (undefined *)(*(ushort *)((int)irSource + 6) | 0x10000);
  }
  else if (uVar5 == 0x800000) {
    bVar2 = false;
    puVar10 = (undefined *)(*(ushort *)((int)irSource + 6) | 0x40000);
  }
  else {
    if (uVar5 != 0x1800000) goto switchD_0003f230_caseD_0;
    bVar2 = false;
    puVar10 = (undefined *)
              ((uint)*(ushort *)((int)irSource + 6) + *(int *)(*translator + 0x10) + 1 & 0xffff |
              0x40000);
  }
  if ((translator[5] & 0x20000000U) == 0) {
    uVar5 = 4;
  }
  else {
    uVar5 = (uVar7 >> 0xc & 3) + 1;
  }
  uVar3 = uVar7 >> 0x1b & 1;
  uVar6 = 4;
  if (uVar5 != 0) {
    uVar6 = *(uint *)(&DAT_001dac08 + (uVar7 >> 0x13 & 0xc)) >> 0x19 & 7;
  }
  uVar4 = uVar3 ^ *(uint *)(&DAT_001dac08 + (uVar7 >> 0x13 & 0xc)) >> 0x18 & 1;
  uVar9 = uVar4 << 3 | uVar6;
  if (uVar5 < 2) {
    uVar5 = uVar4 << 0xf |
            uVar6 << 0xc | uVar4 << 0xb | uVar6 << 8 | uVar4 << 7 | uVar6 << 4 | uVar9;
  }
  else {
    uVar6 = 4;
    if (2 < uVar5) {
      uVar6 = *(uint *)(&DAT_001dac08 + (uVar7 >> 0xf & 0xc)) >> 0x19 & 7;
    }
    uVar4 = 4;
    if (3 < uVar5) {
      uVar4 = *(uint *)(&DAT_001dac08 + (uVar7 >> 0xd & 0xc)) >> 0x19 & 7;
    }
    uVar5 = (uVar3 ^ *(uint *)(&DAT_001dac08 + (uVar7 >> 0xd & 0xc)) >> 0x18 & 1) << 0xf |
            uVar4 << 0xc |
            (uVar3 ^ *(uint *)(&DAT_001dac08 + (uVar7 >> 0xf & 0xc)) >> 0x18 & 1) << 0xb |
            uVar6 << 8 |
            (uVar3 ^ *(uint *)(&DAT_001dac08 + (uVar7 >> 0x11 & 0xc)) >> 0x18 & 1) << 7 |
            *(uint *)(&DAT_001dac08 + (uVar7 >> 0x11 & 0xc)) >> 0x15 & 0x70 | uVar9;
  }
  if (bVar2) {
    uVar5 = ((byte)(DAT_001dac00)[uVar5 >> 0xc & 7] & 7) << 0xc |
            ((byte)(DAT_001dac00)[uVar5 >> 8 & 7] & 7) << 8 |
            ((byte)(DAT_001dac00)[uVar5 >> 4 & 7] & 7) << 4 |
            (byte)(DAT_001dac00)[uVar5 & 7] & 7 | uVar5 & 0xffff8888;
  }
  *outToken = (uint)puVar10 | 0x400000;
  *outSwizzle = uVar5;
  return 0;
}

/* fpilTranslateSourceWithSwizzle @ 0x3f4e0 (232 bytes) */
int fpilTranslateSourceWithSwizzle(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint *param_2;
  undefined4 *param_3;
  uint *param_4;
  uint *param_5;
{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 local_38;
  uint local_34 [7];
  
  iVar2 = ((int (*)())fpilTranslateSource)(param_1,param_2,&local_38,local_34);
  if (iVar2 == 0) {
    uVar6 = *param_5;
    uVar3 = 0;
    uVar7 = *param_2 >> 0x1b & 1;
    uVar1 = *(uint *)(&DAT_001dac08 + (uVar6 >> 10 & 0x3c));
    uVar5 = *(uint *)(&DAT_001dac08 + (uVar6 >> 6 & 0x3c));
    uVar4 = *(uint *)(&DAT_001dac08 + (uVar6 >> 2 & 0x3c));
    uVar6 = *(uint *)(&DAT_001dac08 + (uVar6 & 0xf) * 4);
    *param_3 = local_38;
    *param_4 = (uVar7 ^ uVar6 >> 0x18 & 1) << 0xf |
               uVar6 >> 0xd & 0x7000 |
               (uVar7 ^ uVar4 >> 0x18 & 1) << 0xb |
               uVar4 >> 0x11 & 0x700 |
               (uVar7 ^ uVar5 >> 0x18 & 1) << 7 |
               uVar5 >> 0x15 & 0x70 |
               (uVar7 ^ uVar1 >> 0x18 & 1) << 3 | uVar1 >> 0x19 & 7 | local_34[0] & 0xffff0000;
  }
  else {
    uVar3 = *(undefined4 *)(param_1 + 0x24);
  }
  return uVar3;
}

/* freeIfNonNull @ 0x3f5d0 (12 bytes) */
int freeIfNonNull(pointer)
  int pointer;
{
  if (pointer == 0) {
    return;
  }
  return _free(pointer);
}

/* fpilDestroyTranslator @ 0x3f5e0 (112 bytes) */
int fpilDestroyTranslator(param_1)
  int param_1;
{
  if (*(int *)(param_1 + 0x34) != 0) {
    ((int (*)())freeIfNonNull)(*(int *)(param_1 + 0x34));
  }
  if (*(int *)(param_1 + 0x28) != 0) {
    _free(*(int *)(param_1 + 0x28));
  }
  if (param_1 != 0) {
    _free(param_1);
    return;
  }
  return;
}

/* fpilCreateTranslator @ 0x3f660 (220 bytes) */
int fpilCreateTranslator()
{
  int iVar1;
  int allocation;
  int allocation2;
  
  allocation = _malloc(0x38);
  if (allocation != 0) {
    _memset(allocation,0,0x38);
    *(undefined4 *)(allocation + 0x24) = 0;
    *(undefined4 *)(allocation + 0x28) = 0;
    *(undefined4 *)(allocation + 0x30) = 0;
    *(undefined4 *)(allocation + 0x2c) = 0;
    *(undefined4 *)(allocation + 4) = 0xffffffff;
    *(undefined4 *)(allocation + 8) = 0xffffffff;
    allocation2 = _malloc(0x24);
    iVar1 = 0;
    if (allocation2 != 0) {
      _memset(allocation2,0,0x24);
      iVar1 = allocation2;
    }
    *(int *)(allocation + 0x34) = iVar1;
    if (*(int *)(allocation + 0x34) != 0) {
      return allocation;
    }
    if (allocation != 0) {
      _free(allocation);
      return 0;
    }
  }
  return 0;
}

/* fpilTranslateDestination @ 0x3f750 (232 bytes) */
int fpilTranslateDestination(translator, irDest, outToken, outMask, flag)
  int *translator;
  uint *irDest;
  uint *outToken;
  uint *outMask;
  undefined4 flag;
{
  undefined4 uVar1;
  uint uVar2;
  
  if (((translator[5] & 0x20000000U) != 0) &&
     (((((uVar2 = *irDest, (uVar2 & 0x2000) != 0 && ((uVar2 & 0x300) != 0)) ||
        (((uVar2 & 0x4000) != 0 && ((uVar2 & 0xc0) != 0x40)))) ||
       (((uVar2 & 0x8000) != 0 && ((uVar2 & 0x30) != 0x20)))) ||
      (((uVar2 & 0x10000) != 0 && ((uVar2 & 0xc) != 0xc)))))) {
    uVar1 = *(undefined4 *)(*translator + 0x10);
    *outToken = 0;
    *outMask = 0;
    *outToken = *outToken & 0xffc0ffff | 0x40000;
    *(short *)((int)outToken + 2) = (short)uVar1;
    *outToken = *outToken | 0x400000;
    *outMask = *outMask & 0xffffff00 | 0x55;
    return 0;
  }
  uVar1 = ((int (*)())fpilBuildDestinationToken)(translator,irDest,outToken,outMask,flag);
  return uVar1;
}

/* fpilEmitEmptyProgram @ 0x3f850 (396 bytes) */
int fpilEmitEmptyProgram(param_1)
  int param_1;
{
  int translatorError;
  int allocation;
  uint tokenCapacity;
  int tokenCount;
  dword *pdVar3;
  dword *pdVar4;
  dword *pdVar5;
  undefined4 *tokenWritePtr;
  dword *pdVar7;
  int *tokenDataPtrAddr;
  dword *pdVar9;
  dword *pdVar10;
  
  tokenDataPtrAddr = (int *)(param_1 + 0x28);
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  tokenCount = *(int *)(param_1 + 0x2c);
  tokenCapacity = *(uint *)(param_1 + 0x30);
  if (tokenCapacity < tokenCount + 7U) {
    if (tokenCapacity == 0) {
      tokenCapacity = 0x10;
    }
    else {
      tokenCapacity = tokenCapacity << 1;
    }
    for (; tokenCapacity < tokenCount + 7U; tokenCapacity = tokenCapacity << 1) {
    }
    if (*tokenDataPtrAddr == 0) {
      allocation = _malloc(tokenCapacity << 2);
    }
    else {
      allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
    }
    if (allocation == 0) {
      translatorError = *(int *)(param_1 + 0x24);
      if (translatorError == 0) {
        translatorError = 1;
        *(undefined4 *)(param_1 + 0x24) = 1;
      }
      if (translatorError != 0) {
        return translatorError;
      }
      tokenWritePtr = (undefined4 *)0x0;
      pdVar7 = ((unsigned char *)0x4);
      pdVar9 = ((unsigned char *)0x8);
      pdVar10 = ((unsigned char *)0xc);
      pdVar3 = ((unsigned char *)0x10);
      pdVar4 = ((unsigned char *)0x14);
      pdVar5 = ((unsigned char *)0x18);
      goto LAB_0003f918;
    }
    *tokenDataPtrAddr = allocation;
    *(uint *)(param_1 + 0x30) = tokenCapacity;
    tokenCount = *(int *)(param_1 + 0x2c);
  }
  *(int *)(param_1 + 0x2c) = tokenCount + 7;
  tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
  pdVar7 = tokenWritePtr + 1;
  pdVar9 = tokenWritePtr + 2;
  pdVar10 = tokenWritePtr + 3;
  pdVar3 = tokenWritePtr + 4;
  pdVar4 = tokenWritePtr + 5;
  pdVar5 = tokenWritePtr + 6;
LAB_0003f918:
  *tokenWritePtr = 1;
  *pdVar7 = 0x10200;
  *pdVar9 = 0x47;
  *pdVar10 = 0x170000;
  *pdVar3 = 0x440000;
  *pdVar4 = (dword)((unsigned char *)0x00004444);
  *pdVar5 = 0x28;
  return 0;
}

/* fpilEmitMoveFromTemp @ 0x3f9f0 (472 bytes) */
int fpilEmitMoveFromTemp(param_1, param_2, param_3)
  int *param_1;
  uint *param_2;
  undefined4 param_3;
{
  int translatorError;
  int tokenCount;
  int allocation;
  undefined4 *tokenWritePtr;
  int iVar2;
  uint tokenCapacity;
  uint uVar4;
  uint uVar5;
  dword *pdVar6;
  dword *pdVar7;
  uint uVar8;
  uint uVar9;
  dword *pdVar10;
  uint uVar11;
  dword *pdVar12;
  int *tokenDataPtrAddr;
  dword local_38;
  dword local_34 [6];
  
  local_38 = 0;
  local_34[0] = 0;
  iVar2 = ((int (*)())fpilBuildDestinationToken)(param_1,param_2,&local_38,local_34,param_3);
  if (iVar2 != 0) {
    return param_1[9];
  }
  uVar11 = *param_2;
  tokenDataPtrAddr = param_1 + 10;
  tokenCount = param_1[0xb];
  tokenCapacity = param_1[0xc];
  uVar8 = *(uint *)(&DAT_001dac08 + (uVar11 >> 6 & 0xc));
  uVar5 = *(uint *)(&DAT_001dac08 + (uVar11 >> 4 & 0xc));
  uVar4 = *(uint *)(&DAT_001dac08 + (uVar11 >> 2 & 0xc));
  uVar9 = *(uint *)(&DAT_001dac08 + (uVar11 & 0xc));
  uVar11 = *(uint *)(*param_1 + 0x10);
  if (tokenCapacity < tokenCount + 5U) {
    if (tokenCapacity == 0) {
      tokenCapacity = 0x10;
    }
    else {
      tokenCapacity = tokenCapacity << 1;
    }
    for (; tokenCapacity < tokenCount + 5U; tokenCapacity = tokenCapacity << 1) {
    }
    if (*tokenDataPtrAddr == 0) {
      allocation = _malloc(tokenCapacity << 2);
    }
    else {
      allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
    }
    if (allocation == 0) {
      translatorError = param_1[9];
      if (translatorError == 0) {
        translatorError = 1;
        param_1[9] = 1;
      }
      if (translatorError != 0) {
        return translatorError;
      }
      tokenWritePtr = (undefined4 *)0x0;
      pdVar6 = ((unsigned char *)0x4);
      pdVar10 = ((unsigned char *)0x8);
      pdVar12 = ((unsigned char *)0xc);
      pdVar7 = ((unsigned char *)0x10);
      goto LAB_0003fb50;
    }
    *tokenDataPtrAddr = allocation;
    param_1[0xc] = tokenCapacity;
    tokenCount = param_1[0xb];
  }
  param_1[0xb] = tokenCount + 5;
  tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
  pdVar6 = tokenWritePtr + 1;
  pdVar10 = tokenWritePtr + 2;
  pdVar12 = tokenWritePtr + 3;
  pdVar7 = tokenWritePtr + 4;
LAB_0003fb50:
  *tokenWritePtr = 0x47;
  *pdVar6 = local_38;
  *pdVar10 = local_34[0];
  *pdVar12 = uVar11 & 0xffff | 0x440000;
  *pdVar7 = uVar9 >> 9 & 0x8000 |
            uVar9 >> 0xd & 0x7000 |
            uVar4 >> 0xd & 0x800 |
            uVar4 >> 0x11 & 0x700 |
            uVar5 >> 0x11 & 0x80 | uVar5 >> 0x15 & 0x70 | uVar8 >> 0x15 & 8 | uVar8 >> 0x19 & 7;
  return 0;
}

/* fpilEmitInstruction @ 0x3fbf0 (392 bytes) */
int fpilEmitInstruction(translator, ilInstr, nDst, nSrc)
  int translator;
  undefined4 *ilInstr;
  int nDst;
  int nSrc;
{
  int headerWords;
  int errorCode;
  int allocation;
  undefined4 *srcAuxWordPtr;
  uint capacityWords;
  uint requiredWords;
  undefined4 *recordPtr;
  undefined4 *sourceOutPtr;
  int usedWords;
  int recordWords;
  int *dataPtrAddr;
  
  if (*(int *)(translator + 0x24) != 0) {
    return *(int *)(translator + 0x24);
  }
  dataPtrAddr = (int *)(translator + 0x28);
  usedWords = *(int *)(translator + 0x2c);
  capacityWords = *(uint *)(translator + 0x30);
  recordWords = (nDst + nSrc) * 2 + 1;
  requiredWords = recordWords + usedWords;
  if (capacityWords < requiredWords) {
    if (capacityWords == 0) {
      capacityWords = 0x10;
    }
    else {
      capacityWords = capacityWords << 1;
    }
    for (; capacityWords < requiredWords; capacityWords = capacityWords << 1) {
    }
    if (*dataPtrAddr == 0) {
      allocation = _malloc(capacityWords << 2);
    }
    else {
      allocation = _realloc(*dataPtrAddr,capacityWords << 2);
    }
    if (allocation == 0) {
      errorCode = *(int *)(translator + 0x24);
      if (errorCode == 0) {
        errorCode = 1;
        *(undefined4 *)(translator + 0x24) = 1;
      }
      recordPtr = (undefined4 *)0x0;
      if (errorCode != 0) {
        return errorCode;
      }
      goto LAB_0003fcc0;
    }
    *dataPtrAddr = allocation;
    *(uint *)(translator + 0x30) = capacityWords;
    usedWords = *(int *)(translator + 0x2c);
  }
  *(int *)(translator + 0x2c) = recordWords + usedWords;
  recordPtr = (undefined4 *)(usedWords * 4 + *dataPtrAddr);
LAB_0003fcc0:
  *recordPtr = *ilInstr;
  if (nDst == 0) {
    headerWords = 1;
  }
  else {
    headerWords = 3;
    recordPtr[1] = ilInstr[1];
    recordPtr[2] = ilInstr[2];
  }
  if (0 < nSrc) {
    recordPtr = recordPtr + headerWords;
    sourceOutPtr = recordPtr;
    do {
      *sourceOutPtr = ilInstr[3];
      sourceOutPtr = sourceOutPtr + 2;
      srcAuxWordPtr = ilInstr + 6;
      ilInstr = ilInstr + 1;
      recordPtr[1] = *srcAuxWordPtr;
      recordPtr = recordPtr + 2;
      nSrc = nSrc + -1;
    } while (nSrc != 0);
  }
  return 0;
}

/* fragmentTranslateSimpleOp @ 0x3fd80 (440 bytes) */
int fragmentTranslateSimpleOp(translator, slot, ilInstr)
  int *translator;
  int slot;
  undefined4 *ilInstr;
{
  int translatorError;
  int tokenCount;
  int allocation;
  undefined4 *puVar1;
  uint tokenCapacity;
  uint uVar3;
  undefined4 *tokenWritePtr;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int *tokenDataPtrAddr;
  uint uVar10;
  
  uVar6 = *(uint *)(*translator + *(int *)(*translator + 0x54) * 8 + slot * 8);
  uVar10 = uVar6 >> 0x1d;
  uVar6 = (*(uint *)(&DAT_001dac40 + (uVar6 >> 0xe & 0xff0)) ^ 0x20000000) >> 0x1d & 1;
  if (translator[9] != 0) {
    return translator[9];
  }
  tokenDataPtrAddr = translator + 10;
  tokenCount = translator[0xb];
  tokenCapacity = translator[0xc];
  iVar8 = (uVar6 + uVar10) * 2 + 1;
  uVar3 = iVar8 + tokenCount;
  if (tokenCapacity < uVar3) {
    if (tokenCapacity == 0) {
      tokenCapacity = 0x10;
    }
    else {
      tokenCapacity = tokenCapacity << 1;
    }
    for (; tokenCapacity < uVar3; tokenCapacity = tokenCapacity << 1) {
    }
    if (*tokenDataPtrAddr == 0) {
      allocation = _malloc(tokenCapacity << 2);
    }
    else {
      allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
    }
    if (allocation == 0) {
      translatorError = translator[9];
      if (translatorError == 0) {
        translatorError = 1;
        translator[9] = 1;
      }
      tokenWritePtr = (undefined4 *)0x0;
      if (translatorError != 0) {
        return translatorError;
      }
      goto LAB_0003fe80;
    }
    *tokenDataPtrAddr = allocation;
    translator[0xc] = tokenCapacity;
    tokenCount = translator[0xb];
  }
  translator[0xb] = iVar8 + tokenCount;
  tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
LAB_0003fe80:
  *tokenWritePtr = *ilInstr;
  if (uVar6 == 0) {
    iVar7 = 1;
  }
  else {
    iVar7 = 3;
    tokenWritePtr[1] = ilInstr[1];
    tokenWritePtr[2] = ilInstr[2];
  }
  if (uVar10 != 0) {
    tokenWritePtr = tokenWritePtr + iVar7;
    puVar5 = tokenWritePtr;
    do {
      *puVar5 = ilInstr[3];
      puVar5 = puVar5 + 2;
      puVar1 = ilInstr + 6;
      ilInstr = ilInstr + 1;
      tokenWritePtr[1] = *puVar1;
      tokenWritePtr = tokenWritePtr + 2;
      uVar10 = uVar10 - 1;
    } while (uVar10 != 0);
  }
  return 0;
}

/* fragmentTranslateRep @ 0x3ff40 (592 bytes) */
int fragmentTranslateRep(translator, slot, ilInstr)
  int *translator;
  undefined4 slot;
  undefined4 *ilInstr;
{
  uint tokenCapacity;
  int translatorError;
  int tokenCount;
  int allocation;
  int iVar1;
  int iVar2;
  undefined4 *tokenWritePtr;
  uint uVar4;
  int iVar5;
  dword *pdVar6;
  dword *pdVar7;
  int *tokenDataPtrAddr;
  int aiStack_48 [4];
  longlong lStack_38;
  float fStack_30;
  
  if ((ilInstr[3] & 0x3f0000) != 0x10000) {
    if (translator[9] != 0) {
      return translator[9];
    }
    translator[9] = 2;
    return 2;
  }
  iVar5 = *translator;
  iVar2 = (uint)*(ushort *)((int)ilInstr + 0xe) * 8;
  iVar1 = iVar5 + *(int *)(iVar5 + 0x2c) * 8;
  uVar4 = *(uint *)(iVar1 + iVar2);
  if ((((uVar4 & 0x1f0000) == 0x110000) && ((uVar4 >> 0x1a & 7) < 2)) && ((ilInstr[6] & 7) < 4)) {
    aiStack_48[0] = translator[9];
    fStack_30 = *(float *)(iVar5 + *(int *)(iVar5 + 0x6c) * 8 +
                          ((uint)*(ushort *)(iVar1 + iVar2 + 2) * 4 + (ilInstr[6] & 7)) * 4);
  }
  else {
    aiStack_48[0] = translator[9];
    if (aiStack_48[0] == 0) {
      aiStack_48[0] = 2;
      translator[9] = 2;
    }
    fStack_30 = 0.0;
  }
  if (aiStack_48[0] != 0) {
    return aiStack_48[0];
  }
  lStack_38 = (longlong)(int)fStack_30;
  ((int (*)())fpilEmitScalarConstant)(translator,(int)fStack_30,aiStack_48);
  ilInstr[3] = ilInstr[3] & 0xffc0ffff | 0x20000;
  *(short *)((int)ilInstr + 0xe) = (short)aiStack_48[0];
  if (translator[9] != 0) {
    return translator[9];
  }
  tokenDataPtrAddr = translator + 10;
  tokenCount = translator[0xb];
  tokenCapacity = translator[0xc];
  if (tokenCapacity < tokenCount + 3U) {
    if (tokenCapacity == 0) {
      tokenCapacity = 0x10;
    }
    else {
      tokenCapacity = tokenCapacity << 1;
    }
    for (; tokenCapacity < tokenCount + 3U; tokenCapacity = tokenCapacity << 1) {
    }
    if (*tokenDataPtrAddr == 0) {
      allocation = _malloc(tokenCapacity << 2);
    }
    else {
      allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
    }
    if (allocation == 0) {
      translatorError = translator[9];
      if (translatorError == 0) {
        translatorError = 1;
        translator[9] = 1;
      }
      if (translatorError != 0) {
        return translatorError;
      }
      tokenWritePtr = (undefined4 *)0x0;
      pdVar7 = ((unsigned char *)0x4);
      pdVar6 = ((unsigned char *)0x8);
      goto LAB_00040128;
    }
    *tokenDataPtrAddr = allocation;
    translator[0xc] = tokenCapacity;
    tokenCount = translator[0xb];
  }
  translator[0xb] = tokenCount + 3;
  tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
  pdVar7 = tokenWritePtr + 1;
  pdVar6 = tokenWritePtr + 2;
LAB_00040128:
  *tokenWritePtr = *ilInstr;
  *pdVar7 = ilInstr[3];
  *pdVar6 = ilInstr[6];
  return 0;
}

/* fragmentTranslateDdy @ 0x401b0 (420 bytes) */
int fragmentTranslateDdy(translator, slot, ilInstr)
  int translator;
  undefined4 slot;
  undefined4 *ilInstr;
{
  uint tokenCapacity;
  int translatorError;
  int allocation;
  uint uVar1;
  int tokenCount;
  dword *pdVar3;
  dword *pdVar4;
  undefined4 *tokenWritePtr;
  dword *pdVar6;
  dword *pdVar7;
  int *tokenDataPtrAddr;
  
  *(uint *)(*(int *)(translator + 0x34) + 0x20) =
       *(uint *)(*(int *)(translator + 0x34) + 0x20) | 0x1000000;
  if ((*(uint *)(*(int *)(translator + 0x34) + 0x20) & 0x800000) != 0) {
    uVar1 = ilInstr[6];
    ilInstr[6] = (uVar1 & 0xfffff777 ^ 0x8000) & 0x8000 |
                 (uVar1 & 0xffffff77 ^ 0x800) & 0x800 |
                 (uVar1 & 0xfffffff7 ^ 0x80) & 0x80 | (uVar1 ^ 8) & 8 | uVar1 & 0xffff7777;
  }
  if (*(int *)(translator + 0x24) != 0) {
    return *(int *)(translator + 0x24);
  }
  tokenDataPtrAddr = (int *)(translator + 0x28);
  tokenCount = *(int *)(translator + 0x2c);
  tokenCapacity = *(uint *)(translator + 0x30);
  if (tokenCapacity < tokenCount + 5U) {
    if (tokenCapacity == 0) {
      tokenCapacity = 0x10;
    }
    else {
      tokenCapacity = tokenCapacity << 1;
    }
    for (; tokenCapacity < tokenCount + 5U; tokenCapacity = tokenCapacity << 1) {
    }
    if (*tokenDataPtrAddr == 0) {
      allocation = _malloc(tokenCapacity << 2);
    }
    else {
      allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
    }
    if (allocation == 0) {
      translatorError = *(int *)(translator + 0x24);
      if (translatorError == 0) {
        translatorError = 1;
        *(undefined4 *)(translator + 0x24) = 1;
      }
      if (translatorError != 0) {
        return translatorError;
      }
      tokenWritePtr = (undefined4 *)0x0;
      pdVar3 = ((unsigned char *)0x4);
      pdVar4 = ((unsigned char *)0x8);
      pdVar6 = ((unsigned char *)0xc);
      pdVar7 = ((unsigned char *)0x10);
      goto LAB_000402d0;
    }
    *tokenDataPtrAddr = allocation;
    *(uint *)(translator + 0x30) = tokenCapacity;
    tokenCount = *(int *)(translator + 0x2c);
  }
  *(int *)(translator + 0x2c) = tokenCount + 5;
  tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
  pdVar3 = tokenWritePtr + 1;
  pdVar4 = tokenWritePtr + 2;
  pdVar6 = tokenWritePtr + 3;
  pdVar7 = tokenWritePtr + 4;
LAB_000402d0:
  *tokenWritePtr = *ilInstr;
  *pdVar3 = ilInstr[1];
  *pdVar4 = ilInstr[2];
  *pdVar6 = ilInstr[3];
  *pdVar7 = ilInstr[6];
  return 0;
}

/* fragmentTranslateScalarMath @ 0x40370 (4 bytes) */
int fragmentTranslateScalarMath(translator, slot, ilInstr)
  int *translator;
  int slot;
  undefined4 *ilInstr;
{
  uint tokenCapacity2;
  uint tokenCapacity;
  int translatorError;
  int tokenCount;
  undefined4 *tokenWritePtr;
  void *allocation;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 unaff_r21;
  undefined4 unaff_r22;
  uint uVar6;
  uint *puVar7;
  uint *puVar8;
  uint uVar9;
  int *tokenDataPtrAddr;
  
  uVar6 = 1;
  if ((translator[5] & 0x20000000U) != 0) {
    uVar6 = (*(uint *)(slot * 8 + *translator + *(int *)(*translator + 0x54) * 8 + 4) >> 0x1a & 3) + 1;
  }
  uVar9 = ilInstr[6];
  if (1 < uVar6) {
    iVar4 = translator[8];
    unaff_r22 = ilInstr[1];
    unaff_r21 = ilInstr[2];
    ilInstr[1] = 0x40000;
    *(short *)((int)ilInstr + 6) = (short)iVar4;
    ilInstr[2] = 0x55;
    ilInstr[1] = ilInstr[1] | 0x400000;
  }
  uVar3 = uVar9 >> 3 & 1;
  puVar8 = ilInstr + 6;
  ilInstr[6] = uVar3 << 0xf |
               (uVar9 & 7) << 0xc |
               uVar3 << 0xb |
               (uVar9 & 7) << 8 | uVar3 << 7 | (uVar9 & 7) << 4 | uVar3 << 3 | uVar9 & 0xffff0007;
  if (translator[9] == 0) {
    tokenDataPtrAddr = translator + 10;
    tokenCount = translator[0xb];
    tokenCapacity = translator[0xc];
    if (tokenCapacity < tokenCount + 5U) {
      if (tokenCapacity == 0) {
        tokenCapacity = 0x10;
      }
      else {
        tokenCapacity = tokenCapacity << 1;
      }
      for (; tokenCapacity < tokenCount + 5U; tokenCapacity = tokenCapacity << 1) {
      }
      if ((void *)*tokenDataPtrAddr == (void *)0x0) {
        allocation = _malloc(tokenCapacity << 2);
      }
      else {
        allocation = _realloc((void *)*tokenDataPtrAddr,tokenCapacity << 2);
      }
      if (allocation == (void *)0x0) {
        if (translator[9] == 0) {
          translator[9] = 1;
        }
        goto LAB_00040524;
      }
      *tokenDataPtrAddr = (int)allocation;
      translator[0xc] = tokenCapacity;
      tokenCount = translator[0xb];
    }
    translator[0xb] = tokenCount + 5;
    tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
    *tokenWritePtr = *ilInstr;
    tokenWritePtr[1] = ilInstr[1];
    tokenWritePtr[2] = ilInstr[2];
    tokenWritePtr[3] = ilInstr[3];
    tokenWritePtr[4] = ilInstr[6];
  }
LAB_00040524:
  if (1 >= uVar6) {
    return translator[9];
  }
  uVar3 = uVar9 >> 4 & 7;
  uVar5 = uVar9 >> 7 & 1;
  puVar7 = ilInstr + 2;
  ilInstr[2] = ilInstr[2] & 0xfffffffc;
  *puVar8 = uVar5 << 0xf |
            uVar3 << 0xc |
            uVar5 << 0xb |
            uVar3 << 8 | uVar5 << 7 | uVar3 << 4 | uVar5 << 3 | uVar3 | *puVar8 & 0xffff0000;
  if (translator[9] == 0) {
    tokenDataPtrAddr = translator + 10;
    tokenCount = translator[0xb];
    tokenCapacity = translator[0xc];
    if (tokenCapacity < tokenCount + 5U) {
      if (tokenCapacity == 0) {
        tokenCapacity = 0x10;
      }
      else {
        tokenCapacity = tokenCapacity << 1;
      }
      for (; tokenCapacity < tokenCount + 5U; tokenCapacity = tokenCapacity << 1) {
      }
      if ((void *)*tokenDataPtrAddr == (void *)0x0) {
        allocation = _malloc(tokenCapacity << 2);
      }
      else {
        allocation = _realloc((void *)*tokenDataPtrAddr,tokenCapacity << 2);
      }
      if (allocation == (void *)0x0) {
        if (translator[9] == 0) {
          translator[9] = 1;
        }
        goto LAB_00040664;
      }
      *tokenDataPtrAddr = (int)allocation;
      translator[0xc] = tokenCapacity;
      tokenCount = translator[0xb];
    }
    translator[0xb] = tokenCount + 5;
    tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
    *tokenWritePtr = *ilInstr;
    tokenWritePtr[1] = ilInstr[1];
    tokenWritePtr[2] = ilInstr[2];
    tokenWritePtr[3] = ilInstr[3];
    tokenWritePtr[4] = ilInstr[6];
  }
LAB_00040664:
  if (uVar6 < 3) goto LAB_000408d0;
  uVar3 = uVar9 >> 8 & 7;
  uVar5 = uVar9 >> 0xb & 1;
  *puVar7 = *puVar7 & 0xfffffff3;
  *puVar8 = uVar5 << 0xf |
            uVar3 << 0xc |
            uVar5 << 0xb |
            uVar3 << 8 | uVar5 << 7 | uVar3 << 4 | uVar5 << 3 | uVar3 | *puVar8 & 0xffff0000;
  if (translator[9] == 0) {
    tokenDataPtrAddr = translator + 10;
    tokenCount = translator[0xb];
    tokenCapacity = translator[0xc];
    if (tokenCapacity < tokenCount + 5U) {
      if (tokenCapacity == 0) {
        tokenCapacity = 0x10;
      }
      else {
        tokenCapacity = tokenCapacity << 1;
      }
      for (; tokenCapacity < tokenCount + 5U; tokenCapacity = tokenCapacity << 1) {
      }
      if ((void *)*tokenDataPtrAddr == (void *)0x0) {
        allocation = _malloc(tokenCapacity << 2);
      }
      else {
        allocation = _realloc((void *)*tokenDataPtrAddr,tokenCapacity << 2);
      }
      if (allocation == (void *)0x0) {
        if (translator[9] == 0) {
          translator[9] = 1;
        }
        goto LAB_00040794;
      }
      *tokenDataPtrAddr = (int)allocation;
      translator[0xc] = tokenCapacity;
      tokenCount = translator[0xb];
    }
    translator[0xb] = tokenCount + 5;
    tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
    *tokenWritePtr = *ilInstr;
    tokenWritePtr[1] = ilInstr[1];
    tokenWritePtr[2] = ilInstr[2];
    tokenWritePtr[3] = ilInstr[3];
    tokenWritePtr[4] = ilInstr[6];
  }
LAB_00040794:
  if (uVar6 == 4) {
    uVar6 = uVar9 >> 0xc & 7;
    uVar9 = uVar9 >> 0xf & 1;
    *puVar7 = *puVar7 & 0xffffffcf;
    *puVar8 = uVar9 << 0xf |
              uVar6 << 0xc |
              uVar9 << 0xb |
              uVar6 << 8 | uVar9 << 7 | uVar6 << 4 | uVar9 << 3 | uVar6 | *puVar8 & 0xffff0000;
    if (translator[9] == 0) {
      tokenDataPtrAddr = translator + 10;
      tokenCount = translator[0xb];
      tokenCapacity2 = translator[0xc];
      if (tokenCapacity2 < tokenCount + 5U) {
        if (tokenCapacity2 == 0) {
          tokenCapacity2 = 0x10;
        }
        else {
          tokenCapacity2 = tokenCapacity2 << 1;
        }
        for (; tokenCapacity2 < tokenCount + 5U; tokenCapacity2 = tokenCapacity2 << 1) {
        }
        if ((void *)*tokenDataPtrAddr == (void *)0x0) {
          allocation = _malloc(tokenCapacity2 << 2);
        }
        else {
          allocation = _realloc((void *)*tokenDataPtrAddr,tokenCapacity2 << 2);
        }
        if (allocation == (void *)0x0) {
          if (translator[9] == 0) {
            translator[9] = 1;
          }
          goto LAB_000408d0;
        }
        *tokenDataPtrAddr = (int)allocation;
        translator[0xc] = tokenCapacity2;
        tokenCount = translator[0xb];
      }
      translator[0xb] = tokenCount + 5;
      tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
      *tokenWritePtr = *ilInstr;
      tokenWritePtr[1] = ilInstr[1];
      tokenWritePtr[2] = ilInstr[2];
      tokenWritePtr[3] = ilInstr[3];
      tokenWritePtr[4] = ilInstr[6];
    }
  }
LAB_000408d0:
  iVar4 = translator[8];
  ilInstr[3] = 0;
  *puVar8 = 0;
  ilInstr[3] = ilInstr[3] & 0xffc0ffff | 0x40000;
  *(short *)((int)ilInstr + 0xe) = (short)iVar4;
  ilInstr[3] = ilInstr[3] | 0x400000;
  *puVar8 = *puVar8 & 0xffff0000 | 0x3210;
  *ilInstr = 0;
  ilInstr[1] = unaff_r22;
  ilInstr[2] = unaff_r21;
  *(undefined2 *)((int)ilInstr + 2) = 0x47;
  translatorError = translator[9];
  if (translatorError == 0) {
    tokenDataPtrAddr = translator + 10;
    tokenCount = translator[0xb];
    tokenCapacity2 = translator[0xc];
    if (tokenCapacity2 < tokenCount + 5U) {
      if (tokenCapacity2 == 0) {
        tokenCapacity2 = 0x10;
      }
      else {
        tokenCapacity2 = tokenCapacity2 << 1;
      }
      for (; tokenCapacity2 < tokenCount + 5U; tokenCapacity2 = tokenCapacity2 << 1) {
      }
      if ((void *)*tokenDataPtrAddr == (void *)0x0) {
        allocation = _malloc(tokenCapacity2 << 2);
      }
      else {
        allocation = _realloc((void *)*tokenDataPtrAddr,tokenCapacity2 << 2);
      }
      if (allocation == (void *)0x0) {
        if (translator[9] != 0) {
          return translator[9];
        }
        translator[9] = 1;
        return 1;
      }
      *tokenDataPtrAddr = (int)allocation;
      translator[0xc] = tokenCapacity2;
      tokenCount = translator[0xb];
    }
    translator[0xb] = tokenCount + 5;
    tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
    *tokenWritePtr = *ilInstr;
    tokenWritePtr[1] = ilInstr[1];
    tokenWritePtr[2] = ilInstr[2];
    tokenWritePtr[3] = ilInstr[3];
    tokenWritePtr[4] = ilInstr[6];
    translatorError = translator[9];
  }
  return translatorError;
}

/* fragmentTranslateScalarMathBody @ 0x40374 (1800 bytes) */
int fragmentTranslateScalarMathBody(translator, slot, ilInstr, param_4, param_5, param_6, param_7, param_8)
  int *translator;
  int slot;
  undefined4 *ilInstr;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  uint tokenCapacity2;
  uint tokenCapacity;
  int translatorError;
  int tokenCount;
  int allocation;
  undefined4 *tokenWritePtr;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 unaff_r21;
  undefined4 unaff_r22;
  uint uVar5;
  uint *puVar6;
  uint *puVar7;
  uint uVar8;
  int *tokenDataPtrAddr;
  
  uVar5 = 1;
  if ((translator[5] & 0x20000000U) != 0) {
    uVar5 = (*(uint *)(slot * 8 + *translator + *(int *)(*translator + 0x54) * 8 + 4) >> 0x1a & 3) + 1;
  }
  uVar8 = ilInstr[6];
  if (1 < uVar5) {
    iVar3 = translator[8];
    unaff_r22 = ilInstr[1];
    unaff_r21 = ilInstr[2];
    ilInstr[1] = 0x40000;
    *(short *)((int)ilInstr + 6) = (short)iVar3;
    ilInstr[2] = 0x55;
    ilInstr[1] = ilInstr[1] | 0x400000;
  }
  uVar2 = uVar8 >> 3 & 1;
  puVar7 = ilInstr + 6;
  ilInstr[6] = uVar2 << 0xf |
               (uVar8 & 7) << 0xc |
               uVar2 << 0xb |
               (uVar8 & 7) << 8 | uVar2 << 7 | (uVar8 & 7) << 4 | uVar2 << 3 | uVar8 & 0xffff0007;
  if (translator[9] == 0) {
    tokenDataPtrAddr = translator + 10;
    tokenCount = translator[0xb];
    tokenCapacity = translator[0xc];
    if (tokenCapacity < tokenCount + 5U) {
      if (tokenCapacity == 0) {
        tokenCapacity = 0x10;
      }
      else {
        tokenCapacity = tokenCapacity << 1;
      }
      for (; tokenCapacity < tokenCount + 5U; tokenCapacity = tokenCapacity << 1) {
      }
      if (*tokenDataPtrAddr == 0) {
        allocation = _malloc(tokenCapacity << 2);
      }
      else {
        allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
      }
      if (allocation == 0) {
        if (translator[9] == 0) {
          translator[9] = 1;
        }
        goto LAB_00040524;
      }
      *tokenDataPtrAddr = allocation;
      translator[0xc] = tokenCapacity;
      tokenCount = translator[0xb];
    }
    translator[0xb] = tokenCount + 5;
    tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
    *tokenWritePtr = *ilInstr;
    tokenWritePtr[1] = ilInstr[1];
    tokenWritePtr[2] = ilInstr[2];
    tokenWritePtr[3] = ilInstr[3];
    tokenWritePtr[4] = ilInstr[6];
  }
LAB_00040524:
  if (1 >= uVar5) {
    return translator[9];
  }
  uVar2 = uVar8 >> 4 & 7;
  uVar4 = uVar8 >> 7 & 1;
  puVar6 = ilInstr + 2;
  ilInstr[2] = ilInstr[2] & 0xfffffffc;
  *puVar7 = uVar4 << 0xf |
            uVar2 << 0xc |
            uVar4 << 0xb |
            uVar2 << 8 | uVar4 << 7 | uVar2 << 4 | uVar4 << 3 | uVar2 | *puVar7 & 0xffff0000;
  if (translator[9] == 0) {
    tokenDataPtrAddr = translator + 10;
    tokenCount = translator[0xb];
    tokenCapacity = translator[0xc];
    if (tokenCapacity < tokenCount + 5U) {
      if (tokenCapacity == 0) {
        tokenCapacity = 0x10;
      }
      else {
        tokenCapacity = tokenCapacity << 1;
      }
      for (; tokenCapacity < tokenCount + 5U; tokenCapacity = tokenCapacity << 1) {
      }
      if (*tokenDataPtrAddr == 0) {
        allocation = _malloc(tokenCapacity << 2);
      }
      else {
        allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
      }
      if (allocation == 0) {
        if (translator[9] == 0) {
          translator[9] = 1;
        }
        goto LAB_00040664;
      }
      *tokenDataPtrAddr = allocation;
      translator[0xc] = tokenCapacity;
      tokenCount = translator[0xb];
    }
    translator[0xb] = tokenCount + 5;
    tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
    *tokenWritePtr = *ilInstr;
    tokenWritePtr[1] = ilInstr[1];
    tokenWritePtr[2] = ilInstr[2];
    tokenWritePtr[3] = ilInstr[3];
    tokenWritePtr[4] = ilInstr[6];
  }
LAB_00040664:
  if (uVar5 < 3) goto LAB_000408d0;
  uVar2 = uVar8 >> 8 & 7;
  uVar4 = uVar8 >> 0xb & 1;
  *puVar6 = *puVar6 & 0xfffffff3;
  *puVar7 = uVar4 << 0xf |
            uVar2 << 0xc |
            uVar4 << 0xb |
            uVar2 << 8 | uVar4 << 7 | uVar2 << 4 | uVar4 << 3 | uVar2 | *puVar7 & 0xffff0000;
  if (translator[9] == 0) {
    tokenDataPtrAddr = translator + 10;
    tokenCount = translator[0xb];
    tokenCapacity = translator[0xc];
    if (tokenCapacity < tokenCount + 5U) {
      if (tokenCapacity == 0) {
        tokenCapacity = 0x10;
      }
      else {
        tokenCapacity = tokenCapacity << 1;
      }
      for (; tokenCapacity < tokenCount + 5U; tokenCapacity = tokenCapacity << 1) {
      }
      if (*tokenDataPtrAddr == 0) {
        allocation = _malloc(tokenCapacity << 2);
      }
      else {
        allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
      }
      if (allocation == 0) {
        if (translator[9] == 0) {
          translator[9] = 1;
        }
        goto LAB_00040794;
      }
      *tokenDataPtrAddr = allocation;
      translator[0xc] = tokenCapacity;
      tokenCount = translator[0xb];
    }
    translator[0xb] = tokenCount + 5;
    tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
    *tokenWritePtr = *ilInstr;
    tokenWritePtr[1] = ilInstr[1];
    tokenWritePtr[2] = ilInstr[2];
    tokenWritePtr[3] = ilInstr[3];
    tokenWritePtr[4] = ilInstr[6];
  }
LAB_00040794:
  if (uVar5 == 4) {
    uVar5 = uVar8 >> 0xc & 7;
    uVar8 = uVar8 >> 0xf & 1;
    *puVar6 = *puVar6 & 0xffffffcf;
    *puVar7 = uVar8 << 0xf |
              uVar5 << 0xc |
              uVar8 << 0xb |
              uVar5 << 8 | uVar8 << 7 | uVar5 << 4 | uVar8 << 3 | uVar5 | *puVar7 & 0xffff0000;
    if (translator[9] == 0) {
      tokenDataPtrAddr = translator + 10;
      tokenCount = translator[0xb];
      tokenCapacity2 = translator[0xc];
      if (tokenCapacity2 < tokenCount + 5U) {
        if (tokenCapacity2 == 0) {
          tokenCapacity2 = 0x10;
        }
        else {
          tokenCapacity2 = tokenCapacity2 << 1;
        }
        for (; tokenCapacity2 < tokenCount + 5U; tokenCapacity2 = tokenCapacity2 << 1) {
        }
        if (*tokenDataPtrAddr == 0) {
          allocation = _malloc(tokenCapacity2 << 2);
        }
        else {
          allocation = _realloc(*tokenDataPtrAddr,tokenCapacity2 << 2);
        }
        if (allocation == 0) {
          if (translator[9] == 0) {
            translator[9] = 1;
          }
          goto LAB_000408d0;
        }
        *tokenDataPtrAddr = allocation;
        translator[0xc] = tokenCapacity2;
        tokenCount = translator[0xb];
      }
      translator[0xb] = tokenCount + 5;
      tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
      *tokenWritePtr = *ilInstr;
      tokenWritePtr[1] = ilInstr[1];
      tokenWritePtr[2] = ilInstr[2];
      tokenWritePtr[3] = ilInstr[3];
      tokenWritePtr[4] = ilInstr[6];
    }
  }
LAB_000408d0:
  iVar3 = translator[8];
  ilInstr[3] = 0;
  *puVar7 = 0;
  ilInstr[3] = ilInstr[3] & 0xffc0ffff | 0x40000;
  *(short *)((int)ilInstr + 0xe) = (short)iVar3;
  ilInstr[3] = ilInstr[3] | 0x400000;
  *puVar7 = *puVar7 & 0xffff0000 | 0x3210;
  *ilInstr = 0;
  ilInstr[1] = unaff_r22;
  ilInstr[2] = unaff_r21;
  *(undefined2 *)((int)ilInstr + 2) = 0x47;
  translatorError = translator[9];
  if (translatorError == 0) {
    tokenDataPtrAddr = translator + 10;
    tokenCount = translator[0xb];
    tokenCapacity2 = translator[0xc];
    if (tokenCapacity2 < tokenCount + 5U) {
      if (tokenCapacity2 == 0) {
        tokenCapacity2 = 0x10;
      }
      else {
        tokenCapacity2 = tokenCapacity2 << 1;
      }
      for (; tokenCapacity2 < tokenCount + 5U; tokenCapacity2 = tokenCapacity2 << 1) {
      }
      if (*tokenDataPtrAddr == 0) {
        allocation = _malloc(tokenCapacity2 << 2);
      }
      else {
        allocation = _realloc(*tokenDataPtrAddr,tokenCapacity2 << 2);
      }
      if (allocation == 0) {
        if (translator[9] != 0) {
          return translator[9];
        }
        translator[9] = 1;
        return 1;
      }
      *tokenDataPtrAddr = allocation;
      translator[0xc] = tokenCapacity2;
      tokenCount = translator[0xb];
    }
    translator[0xb] = tokenCount + 5;
    tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
    *tokenWritePtr = *ilInstr;
    tokenWritePtr[1] = ilInstr[1];
    tokenWritePtr[2] = ilInstr[2];
    tokenWritePtr[3] = ilInstr[3];
    tokenWritePtr[4] = ilInstr[6];
    translatorError = translator[9];
  }
  return translatorError;
}

/* FUN_00040ac4 @ 0x40ac4 (2096 bytes) */
int FUN_00040ac4(translator, slot, ilInstr, unusedArg4, unusedArg5, unusedArg6, unusedArg7, unusedArg8)
  int *translator;
  int slot;
  undefined4 *ilInstr;
  undefined4 unusedArg4;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
  undefined4 unusedArg7;
  undefined4 unusedArg8;
{
  uint src1SelectComp3;
  uint src1NegateComp3;
  uint src0NegateComp2;
  uint src1SelectComp2;
  uint src0NegateComp3;
  uint src0SelectComp2;
  uint src0SelectComp1;
  uint src0SelectComp3;
  uint src1NegateComp2;
  uint src1NegateComp1;
  uint tokenCapacity2;
  uint tokenCapacity;
  int translatorError;
  int tokenCount;
  int allocation;
  undefined4 *recordSwzNext;
  bool moreSources;
  int srcIndex;
  uint src0NegateComp0;
  uint src1SelectComp1;
  undefined4 *recordPtr;
  int iVar7;
  uint src1NegateComp0;
  uint src0NegateComp1;
  undefined4 *tokenWritePtr;
  undefined4 unaff_r19;
  undefined4 unaff_r20;
  uint repeatCount;
  uint *dstMaskPtr;
  uint *srcSwizzle1Ptr;
  uint *srcSwizzle0Ptr;
  uint srcSwizzle1;
  uint srcSwizzle0;
  int *tokenDataPtrAddr;
  
  repeatCount = 1;
  if ((translator[5] & 0x20000000U) != 0) {
    repeatCount = (*(uint *)(slot * 8 + *translator + *(int *)(*translator + 0x54) * 8 + 4) >> 0x1a & 3) + 1
    ;
  }
  srcSwizzle0 = ilInstr[6];
  srcSwizzle1 = ilInstr[7];
  if (repeatCount >= 2) {
    iVar7 = translator[8];
    unaff_r20 = ilInstr[1];
    unaff_r19 = ilInstr[2];
    ilInstr[1] = 0x40000;
    *(short *)((int)ilInstr + 6) = (short)iVar7;
    ilInstr[2] = 0x55;
    ilInstr[1] = ilInstr[1] | 0x400000;
  }
  src0NegateComp0 = srcSwizzle0 >> 3 & 1;
  src1NegateComp0 = srcSwizzle1 >> 3 & 1;
  srcSwizzle0Ptr = ilInstr + 6;
  srcSwizzle1Ptr = ilInstr + 7;
  ilInstr[6] = src0NegateComp0 << 0xf |
               (srcSwizzle0 & 7) << 0xc |
               src0NegateComp0 << 0xb |
               (srcSwizzle0 & 7) << 8 | src0NegateComp0 << 7 | (srcSwizzle0 & 7) << 4 | src0NegateComp0 << 3 | srcSwizzle0 & 0xffff0007
  ;
  ilInstr[7] = src1NegateComp0 << 0xf |
               (srcSwizzle1 & 7) << 0xc |
               src1NegateComp0 << 0xb |
               (srcSwizzle1 & 7) << 8 | src1NegateComp0 << 7 | (srcSwizzle1 & 7) << 4 | src1NegateComp0 << 3 | srcSwizzle1 & 0xffff0007
  ;
  if (translator[9] == 0) {
    tokenDataPtrAddr = translator + 10;
    tokenCount = translator[0xb];
    tokenCapacity = translator[0xc];
    if (tokenCapacity < tokenCount + 7U) {
      if (tokenCapacity == 0) {
        tokenCapacity = 0x10;
      }
      else {
        tokenCapacity = tokenCapacity << 1;
      }
      for (; tokenCapacity < tokenCount + 7U; tokenCapacity = tokenCapacity << 1) {
      }
      if (*tokenDataPtrAddr == 0) {
        allocation = _malloc(tokenCapacity << 2);
      }
      else {
        allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
      }
      if (allocation == 0) {
        if (translator[9] == 0) {
          translator[9] = 1;
        }
        goto LAB_00040cf0;
      }
      *tokenDataPtrAddr = allocation;
      translator[0xc] = tokenCapacity;
      tokenCount = translator[0xb];
    }
    srcIndex = 0;
    translator[0xb] = tokenCount + 7;
    tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
    *tokenWritePtr = *ilInstr;
    tokenWritePtr[1] = ilInstr[1];
    tokenWritePtr[2] = ilInstr[2];
    recordPtr = ilInstr;
    do {
      moreSources = srcIndex != 1;
      srcIndex = srcIndex + 1;
      tokenWritePtr[3] = recordPtr[3];
      recordSwzNext = recordPtr + 6;
      recordPtr = recordPtr + 1;
      tokenWritePtr[4] = *recordSwzNext;
      tokenWritePtr = tokenWritePtr + 2;
    } while (moreSources);
  }
LAB_00040cf0:
  if (repeatCount < 2) {
    return translator[9];
  }
  src0SelectComp1 = srcSwizzle0 >> 4 & 7;
  src0NegateComp1 = srcSwizzle0 >> 7 & 1;
  src1SelectComp1 = srcSwizzle1 >> 4 & 7;
  src1NegateComp1 = srcSwizzle1 >> 7 & 1;
  dstMaskPtr = ilInstr + 2;
  ilInstr[2] = ilInstr[2] & 0xfffffffc;
  *srcSwizzle0Ptr = src0NegateComp1 << 0xf |
             src0SelectComp1 << 0xc |
             src0NegateComp1 << 0xb |
             src0SelectComp1 << 8 | src0NegateComp1 << 7 | src0SelectComp1 << 4 | src0NegateComp1 << 3 | src0SelectComp1 | *srcSwizzle0Ptr & 0xffff0000;
  *srcSwizzle1Ptr = src1NegateComp1 << 0xf |
             src1SelectComp1 << 0xc |
             src1NegateComp1 << 0xb |
             src1SelectComp1 << 8 | src1NegateComp1 << 7 | src1SelectComp1 << 4 | src1NegateComp1 << 3 | src1SelectComp1 | *srcSwizzle1Ptr & 0xffff0000;
  if (translator[9] == 0) {
    tokenDataPtrAddr = translator + 10;
    tokenCount = translator[0xb];
    tokenCapacity = translator[0xc];
    if (tokenCapacity < tokenCount + 7U) {
      if (tokenCapacity == 0) {
        tokenCapacity = 0x10;
      }
      else {
        tokenCapacity = tokenCapacity << 1;
      }
      for (; tokenCapacity < tokenCount + 7U; tokenCapacity = tokenCapacity << 1) {
      }
      if (*tokenDataPtrAddr == 0) {
        allocation = _malloc(tokenCapacity << 2);
      }
      else {
        allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
      }
      if (allocation == 0) {
        if (translator[9] == 0) {
          translator[9] = 1;
        }
        goto LAB_00040e70;
      }
      *tokenDataPtrAddr = allocation;
      translator[0xc] = tokenCapacity;
      tokenCount = translator[0xb];
    }
    srcIndex = 0;
    translator[0xb] = tokenCount + 7;
    tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
    *tokenWritePtr = *ilInstr;
    tokenWritePtr[1] = ilInstr[1];
    tokenWritePtr[2] = ilInstr[2];
    recordPtr = ilInstr;
    do {
      moreSources = srcIndex != 1;
      srcIndex = srcIndex + 1;
      tokenWritePtr[3] = recordPtr[3];
      recordSwzNext = recordPtr + 6;
      recordPtr = recordPtr + 1;
      tokenWritePtr[4] = *recordSwzNext;
      tokenWritePtr = tokenWritePtr + 2;
    } while (moreSources);
  }
LAB_00040e70:
  if (repeatCount < 3) goto LAB_00041170;
  src0SelectComp2 = srcSwizzle0 >> 8 & 7;
  src0NegateComp2 = srcSwizzle0 >> 0xb & 1;
  src1SelectComp2 = srcSwizzle1 >> 8 & 7;
  src1NegateComp2 = srcSwizzle1 >> 0xb & 1;
  *dstMaskPtr = *dstMaskPtr & 0xfffffff3;
  *srcSwizzle0Ptr = src0NegateComp2 << 0xf |
             src0SelectComp2 << 0xc |
             src0NegateComp2 << 0xb |
             src0SelectComp2 << 8 | src0NegateComp2 << 7 | src0SelectComp2 << 4 | src0NegateComp2 << 3 | src0SelectComp2 | *srcSwizzle0Ptr & 0xffff0000;
  *srcSwizzle1Ptr = src1NegateComp2 << 0xf |
             src1SelectComp2 << 0xc |
             src1NegateComp2 << 0xb |
             src1SelectComp2 << 8 | src1NegateComp2 << 7 | src1SelectComp2 << 4 | src1NegateComp2 << 3 | src1SelectComp2 | *srcSwizzle1Ptr & 0xffff0000;
  if (translator[9] == 0) {
    tokenDataPtrAddr = translator + 10;
    tokenCount = translator[0xb];
    tokenCapacity = translator[0xc];
    if (tokenCapacity < tokenCount + 7U) {
      if (tokenCapacity == 0) {
        tokenCapacity = 0x10;
      }
      else {
        tokenCapacity = tokenCapacity << 1;
      }
      for (; tokenCapacity < tokenCount + 7U; tokenCapacity = tokenCapacity << 1) {
      }
      if (*tokenDataPtrAddr == 0) {
        allocation = _malloc(tokenCapacity << 2);
      }
      else {
        allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
      }
      if (allocation == 0) {
        if (translator[9] == 0) {
          translator[9] = 1;
        }
        goto LAB_00040ff0;
      }
      *tokenDataPtrAddr = allocation;
      translator[0xc] = tokenCapacity;
      tokenCount = translator[0xb];
    }
    srcIndex = 0;
    translator[0xb] = tokenCount + 7;
    tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
    *tokenWritePtr = *ilInstr;
    tokenWritePtr[1] = ilInstr[1];
    tokenWritePtr[2] = ilInstr[2];
    recordPtr = ilInstr;
    do {
      moreSources = srcIndex != 1;
      srcIndex = srcIndex + 1;
      tokenWritePtr[3] = recordPtr[3];
      recordSwzNext = recordPtr + 6;
      recordPtr = recordPtr + 1;
      tokenWritePtr[4] = *recordSwzNext;
      tokenWritePtr = tokenWritePtr + 2;
    } while (moreSources);
  }
LAB_00040ff0:
  if (repeatCount == 4) {
    src0SelectComp3 = srcSwizzle0 >> 0xc & 7;
    src0NegateComp3 = srcSwizzle0 >> 0xf & 1;
    src1SelectComp3 = srcSwizzle1 >> 0xc & 7;
    src1NegateComp3 = srcSwizzle1 >> 0xf & 1;
    *dstMaskPtr = *dstMaskPtr & 0xffffffcf;
    *srcSwizzle0Ptr = src0NegateComp3 << 0xf |
               src0SelectComp3 << 0xc |
               src0NegateComp3 << 0xb |
               src0SelectComp3 << 8 | src0NegateComp3 << 7 | src0SelectComp3 << 4 | src0NegateComp3 << 3 | src0SelectComp3 | *srcSwizzle0Ptr & 0xffff0000;
    *srcSwizzle1Ptr = src1NegateComp3 << 0xf |
               src1SelectComp3 << 0xc |
               src1NegateComp3 << 0xb |
               src1SelectComp3 << 8 |
               src1NegateComp3 << 7 | src1SelectComp3 << 4 | src1NegateComp3 << 3 | src1SelectComp3 | *srcSwizzle1Ptr & 0xffff0000;
    if (translator[9] == 0) {
      tokenDataPtrAddr = translator + 10;
      tokenCount = translator[0xb];
      tokenCapacity2 = translator[0xc];
      if (tokenCapacity2 < tokenCount + 7U) {
        if (tokenCapacity2 == 0) {
          tokenCapacity2 = 0x10;
        }
        else {
          tokenCapacity2 = tokenCapacity2 << 1;
        }
        for (; tokenCapacity2 < tokenCount + 7U; tokenCapacity2 = tokenCapacity2 << 1) {
        }
        if (*tokenDataPtrAddr == 0) {
          allocation = _malloc(tokenCapacity2 << 2);
        }
        else {
          allocation = _realloc(*tokenDataPtrAddr,tokenCapacity2 << 2);
        }
        if (allocation == 0) {
          if (translator[9] == 0) {
            translator[9] = 1;
          }
          goto LAB_00041170;
        }
        *tokenDataPtrAddr = allocation;
        translator[0xc] = tokenCapacity2;
        tokenCount = translator[0xb];
      }
      srcIndex = 0;
      translator[0xb] = tokenCount + 7;
      tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
      *tokenWritePtr = *ilInstr;
      tokenWritePtr[1] = ilInstr[1];
      tokenWritePtr[2] = ilInstr[2];
      recordPtr = ilInstr;
      do {
        moreSources = srcIndex != 1;
        srcIndex = srcIndex + 1;
        tokenWritePtr[3] = recordPtr[3];
        recordSwzNext = recordPtr + 6;
        recordPtr = recordPtr + 1;
        tokenWritePtr[4] = *recordSwzNext;
        tokenWritePtr = tokenWritePtr + 2;
      } while (moreSources);
    }
  }
LAB_00041170:
  iVar7 = translator[8];
  ilInstr[3] = 0;
  *srcSwizzle0Ptr = 0;
  ilInstr[3] = ilInstr[3] & 0xffc0ffff | 0x40000;
  *(short *)((int)ilInstr + 0xe) = (short)iVar7;
  ilInstr[3] = ilInstr[3] | 0x400000;
  *srcSwizzle0Ptr = *srcSwizzle0Ptr & 0xffff0000 | 0x3210;
  *ilInstr = 0;
  ilInstr[1] = unaff_r20;
  ilInstr[2] = unaff_r19;
  *(undefined2 *)((int)ilInstr + 2) = 0x47;
  translatorError = translator[9];
  if (translatorError == 0) {
    tokenDataPtrAddr = translator + 10;
    tokenCount = translator[0xb];
    tokenCapacity2 = translator[0xc];
    if (tokenCapacity2 < tokenCount + 5U) {
      if (tokenCapacity2 == 0) {
        tokenCapacity2 = 0x10;
      }
      else {
        tokenCapacity2 = tokenCapacity2 << 1;
      }
      for (; tokenCapacity2 < tokenCount + 5U; tokenCapacity2 = tokenCapacity2 << 1) {
      }
      if (*tokenDataPtrAddr == 0) {
        allocation = _malloc(tokenCapacity2 << 2);
      }
      else {
        allocation = _realloc(*tokenDataPtrAddr,tokenCapacity2 << 2);
      }
      if (allocation == 0) {
        if (translator[9] != 0) {
          return translator[9];
        }
        translator[9] = 1;
        return 1;
      }
      *tokenDataPtrAddr = allocation;
      translator[0xc] = tokenCapacity2;
      tokenCount = translator[0xb];
    }
    translator[0xb] = tokenCount + 5;
    tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
    *tokenWritePtr = *ilInstr;
    tokenWritePtr[1] = ilInstr[1];
    tokenWritePtr[2] = ilInstr[2];
    tokenWritePtr[3] = ilInstr[3];
    tokenWritePtr[4] = ilInstr[6];
    translatorError = translator[9];
  }
  return translatorError;
}

/* fragmentTranslateTrig @ 0x41310 (488 bytes) */
int fragmentTranslateTrig(translator, slot, ilInstr)
  int translator;
  undefined4 slot;
  int ilInstr;
{
  int allocation;
  undefined4 *tokenWritePtr;
  undefined2 uVar2;
  uint tokenCapacity;
  int tokenCount;
  undefined4 uVar5;
  int *tokenDataPtrAddr;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_40;
  
  _memcpy(&uStack_58,ilInstr,0x24);
  uVar5 = *(undefined4 *)(translator + 0x20);
  *(undefined4 *)(ilInstr + 0x18) = 0;
  uVar2 = (undefined2)uVar5;
  *(undefined4 *)(ilInstr + 0xc) = 0x40000;
  *(undefined2 *)(ilInstr + 0xe) = uVar2;
  uStack_50 = 0x55;
  uStack_54 = CONCAT22(4,uVar2);
  uStack_58 = 0x4d;
  *(uint *)(ilInstr + 0x18) = *(uint *)(ilInstr + 0x18) & 0xffff0000 | 0x3210;
  *(uint *)(ilInstr + 0xc) = *(uint *)(ilInstr + 0xc) | 0x400000;
  uStack_54 = uStack_54 | 0x400000;
  if (*(int *)(translator + 0x24) == 0) {
    tokenDataPtrAddr = (int *)(translator + 0x28);
    tokenCount = *(int *)(translator + 0x2c);
    tokenCapacity = *(uint *)(translator + 0x30);
    if (tokenCapacity < tokenCount + 5U) {
      if (tokenCapacity == 0) {
        tokenCapacity = 0x10;
      }
      else {
        tokenCapacity = tokenCapacity << 1;
      }
      for (; tokenCapacity < tokenCount + 5U; tokenCapacity = tokenCapacity << 1) {
      }
      if (*tokenDataPtrAddr == 0) {
        allocation = _malloc(tokenCapacity << 2);
      }
      else {
        allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
      }
      if (allocation == 0) {
        if (*(int *)(translator + 0x24) == 0) {
          *(undefined4 *)(translator + 0x24) = 1;
        }
        goto LAB_000414c0;
      }
      *tokenDataPtrAddr = allocation;
      *(uint *)(translator + 0x30) = tokenCapacity;
      tokenCount = *(int *)(translator + 0x2c);
    }
    *(int *)(translator + 0x2c) = tokenCount + 5;
    tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
    *tokenWritePtr = uStack_58;
    tokenWritePtr[1] = uStack_54;
    tokenWritePtr[2] = uStack_50;
    tokenWritePtr[3] = uStack_4c;
    tokenWritePtr[4] = uStack_40;
  }
LAB_000414c0:
  *(int *)(translator + 0x20) = *(int *)(translator + 0x20) + 1;
  ((int (*)())fragmentTranslateScalarMath)(translator,slot,ilInstr);
  *(int *)(translator + 0x20) = *(int *)(translator + 0x20) + -1;
  return *(undefined4 *)(translator + 0x24);
}

/* fragmentTranslateAngleConvert @ 0x41510 (548 bytes) */
int fragmentTranslateAngleConvert(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int *param_1;
  int param_2;
  undefined4 *param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  uint tokenCapacity;
  int translatorError;
  int tokenCount;
  int allocation;
  undefined4 *puVar1;
  bool bVar2;
  int iVar3;
  undefined4 *tokenWritePtr;
  dword *pdVar5;
  dword *pdVar6;
  undefined4 uVar7;
  int *tokenDataPtrAddr;
  uint uVar9;
  
  iVar3 = (param_2 + *(int *)(*param_1 + 0x54)) * 8;
  uVar9 = *(uint *)(iVar3 + *param_1);
  ((int (*)())fpilEmitAngleConstants)(param_1,iVar3,param_3,param_4,param_5,param_6,param_7);
  uVar7 = *(undefined4 *)(*param_1 + 0x28);
  param_3[7] = 0;
  param_3[4] = 0x10000;
  *(short *)((int)param_3 + 0x12) = (short)uVar7;
  uVar9 = *(uint *)(&UNK_001aa574 + (2 - ((int)-(uVar9 & 0x3fc0000 ^ 0x580000) >> 0x1f)) * 4);
  param_3[4] = param_3[4] | 0x400000;
  param_3[7] = (uVar9 & 7) << 0xc |
               (uVar9 & 7) << 8 | (uVar9 & 7) << 4 | uVar9 & 7 | param_3[7] & 0xffff0000;
  if (param_1[9] != 0) {
    return param_1[9];
  }
  tokenDataPtrAddr = param_1 + 10;
  tokenCount = param_1[0xb];
  tokenCapacity = param_1[0xc];
  if (tokenCapacity < tokenCount + 7U) {
    if (tokenCapacity == 0) {
      tokenCapacity = 0x10;
    }
    else {
      tokenCapacity = tokenCapacity << 1;
    }
    for (; tokenCapacity < tokenCount + 7U; tokenCapacity = tokenCapacity << 1) {
    }
    if (*tokenDataPtrAddr == 0) {
      allocation = _malloc(tokenCapacity << 2);
    }
    else {
      allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
    }
    if (allocation == 0) {
      translatorError = param_1[9];
      if (translatorError == 0) {
        translatorError = 1;
        param_1[9] = 1;
      }
      if (translatorError != 0) {
        return translatorError;
      }
      tokenWritePtr = (undefined4 *)0x0;
      pdVar5 = ((unsigned char *)0x4);
      pdVar6 = ((unsigned char *)0x8);
      goto LAB_00041698;
    }
    *tokenDataPtrAddr = allocation;
    param_1[0xc] = tokenCapacity;
    tokenCount = param_1[0xb];
  }
  param_1[0xb] = tokenCount + 7;
  tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
  pdVar5 = tokenWritePtr + 1;
  pdVar6 = tokenWritePtr + 2;
LAB_00041698:
  iVar3 = 0;
  *tokenWritePtr = *param_3;
  *pdVar5 = param_3[1];
  *pdVar6 = param_3[2];
  do {
    bVar2 = iVar3 != 1;
    iVar3 = iVar3 + 1;
    tokenWritePtr[3] = param_3[3];
    puVar1 = param_3 + 6;
    param_3 = param_3 + 1;
    tokenWritePtr[4] = *puVar1;
    tokenWritePtr = tokenWritePtr + 2;
  } while (bVar2);
  return 0;
}

/* fragmentTranslateMod @ 0x41750 (1160 bytes) */
int fragmentTranslateMod(translator, slot, ilInstr)
  int translator;
  undefined4 slot;
  int ilInstr;
{
  undefined4 *tokenWritePtr;
  undefined4 *recordWordNext;
  undefined **recordWordNext2;
  uint uVar3;
  undefined4 *puVar4;
  undefined2 uVar5;
  dword *pdVar6;
  int iVar7;
  undefined4 *recordPtr;
  dword *pdVar9;
  undefined **recordPtr2;
  int *piVar11;
  undefined4 ilInstAOpcode;
  undefined4 ilInstADst;
  dword ilInstADstMask;
  undefined4 ilInstASrc0;
  undefined4 ilInstASrc1;
  undefined4 ilInstASrc2;
  undefined *ilInstASwz0;
  uint ilInstASwz1;
  undefined4 ilInstASwz2;
  
  _memset(&ilInstAOpcode,0,0x24);
  iVar7 = *(int *)(translator + 0x24);
  uVar5 = (undefined2)*(undefined4 *)(translator + 0x20);
  ilInstADst = CONCAT22(4,uVar5);
  ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),0x20);
  ilInstADstMask = 0x55;
  ilInstASrc0 = *(undefined **)(ilInstr + 0xc);
  ilInstASwz0 = *(undefined **)(ilInstr + 0x18);
  ilInstASrc1 = *(undefined4 *)(ilInstr + 0x10);
  ilInstASwz1 = *(undefined4 *)(ilInstr + 0x1c);
  ilInstADst = ilInstADst | 0x400000;
  if (iVar7 == 0) {
    piVar11 = (int *)(translator + 0x28);
    iVar7 = *(int *)(translator + 0x2c);
    uVar3 = *(uint *)(translator + 0x30);
    if (uVar3 < iVar7 + 7U) {
      if (uVar3 == 0) {
        uVar3 = 0x10;
      }
      else {
        uVar3 = uVar3 << 1;
      }
      for (; uVar3 < iVar7 + 7U; uVar3 = uVar3 << 1) {
      }
      if (*piVar11 == 0) {
        iVar7 = _malloc(uVar3 << 2);
      }
      else {
        iVar7 = _realloc(*piVar11,uVar3 << 2);
      }
      if (iVar7 == 0) {
        iVar7 = *(int *)(translator + 0x24);
        if (iVar7 == 0) {
          iVar7 = 1;
          *(undefined4 *)(translator + 0x24) = 1;
        }
        uVar5 = (undefined2)*(undefined4 *)(translator + 0x20);
        goto LAB_000418f0;
      }
      *piVar11 = iVar7;
      *(uint *)(translator + 0x30) = uVar3;
      iVar7 = *(int *)(translator + 0x2c);
    }
    recordPtr = &ilInstASrc0;
    *(int *)(translator + 0x2c) = iVar7 + 7;
    tokenWritePtr = (undefined4 *)(iVar7 * 4 + *piVar11);
    *tokenWritePtr = ilInstAOpcode;
    tokenWritePtr[1] = ilInstADst;
    tokenWritePtr[2] = ilInstADstMask;
    do {
      tokenWritePtr[3] = *recordPtr;
      recordWordNext = recordPtr + 3;
      recordPtr = recordPtr + 1;
      tokenWritePtr[4] = *recordWordNext;
      tokenWritePtr = tokenWritePtr + 2;
    } while (&ilInstASrc2 != recordPtr);
    uVar5 = (undefined2)*(undefined4 *)(translator + 0x20);
    iVar7 = *(int *)(translator + 0x24);
  }
LAB_000418f0:
  ilInstASrc0 = (undefined *)CONCAT22(4,uVar5);
  ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),0x30);
  ilInstASwz0 = ((unsigned char *)0x00003210);
  ilInstASrc0 = (undefined *)((uint)ilInstASrc0 | 0x400000);
  if (iVar7 == 0) {
    piVar11 = (int *)(translator + 0x28);
    iVar7 = *(int *)(translator + 0x2c);
    uVar3 = *(uint *)(translator + 0x30);
    if (uVar3 < iVar7 + 5U) {
      if (uVar3 == 0) {
        uVar3 = 0x10;
      }
      else {
        uVar3 = uVar3 << 1;
      }
      for (; uVar3 < iVar7 + 5U; uVar3 = uVar3 << 1) {
      }
      if (*piVar11 == 0) {
        iVar7 = _malloc(uVar3 << 2);
      }
      else {
        iVar7 = _realloc(*piVar11,uVar3 << 2);
      }
      if (iVar7 == 0) {
        iVar7 = *(int *)(translator + 0x24);
        if (iVar7 == 0) {
          iVar7 = 1;
          *(undefined4 *)(translator + 0x24) = 1;
        }
        goto LAB_00041a08;
      }
      *piVar11 = iVar7;
      *(uint *)(translator + 0x30) = uVar3;
      iVar7 = *(int *)(translator + 0x2c);
    }
    *(int *)(translator + 0x2c) = iVar7 + 5;
    tokenWritePtr = (undefined4 *)(iVar7 * 4 + *piVar11);
    *tokenWritePtr = ilInstAOpcode;
    tokenWritePtr[1] = ilInstADst;
    tokenWritePtr[2] = ilInstADstMask;
    tokenWritePtr[3] = ilInstASrc0;
    tokenWritePtr[4] = ilInstASwz0;
    iVar7 = *(int *)(translator + 0x24);
  }
LAB_00041a08:
  uVar3 = *(uint *)(ilInstr + 0x1c);
  ilInstADstMask = *(dword *)(ilInstr + 8);
  ilInstADst = *(dword *)(ilInstr + 4);
  ilInstASrc1 = *(undefined4 *)(ilInstr + 0x10);
  ilInstASrc2 = *(undefined4 *)(ilInstr + 0xc);
  ilInstASwz2 = *(undefined4 *)(ilInstr + 0x18);
  ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),0x40);
  ilInstASwz1 = (uVar3 & 0xfffff777 ^ 0x8000) & 0x8000 |
              (uVar3 & 0xffffff77 ^ 0x800) & 0x800 |
              (uVar3 & 0xfffffff7 ^ 0x80) & 0x80 | (uVar3 ^ 8) & 8 | uVar3 & 0xffff7777;
  if (iVar7 != 0) {
    return iVar7;
  }
  piVar11 = (int *)(translator + 0x28);
  iVar7 = *(int *)(translator + 0x2c);
  uVar3 = *(uint *)(translator + 0x30);
  if (uVar3 < iVar7 + 9U) {
    if (uVar3 == 0) {
      uVar3 = 0x10;
    }
    else {
      uVar3 = uVar3 << 1;
    }
    for (; uVar3 < iVar7 + 9U; uVar3 = uVar3 << 1) {
    }
    if (*piVar11 == 0) {
      iVar7 = _malloc(uVar3 << 2);
    }
    else {
      iVar7 = _realloc(*piVar11,uVar3 << 2);
    }
    if (iVar7 == 0) {
      iVar7 = *(int *)(translator + 0x24);
      if (iVar7 == 0) {
        iVar7 = 1;
        *(undefined4 *)(translator + 0x24) = 1;
      }
      if (iVar7 != 0) {
        return iVar7;
      }
      puVar4 = (undefined4 *)0x0;
      pdVar6 = ((unsigned char *)0x4);
      pdVar9 = ((unsigned char *)0x8);
      goto LAB_00041b48;
    }
    *piVar11 = iVar7;
    *(uint *)(translator + 0x30) = uVar3;
    iVar7 = *(int *)(translator + 0x2c);
  }
  *(int *)(translator + 0x2c) = iVar7 + 9;
  puVar4 = (undefined4 *)(iVar7 * 4 + *piVar11);
  pdVar6 = puVar4 + 1;
  pdVar9 = puVar4 + 2;
LAB_00041b48:
  recordPtr2 = (undefined **)&ilInstASrc0;
  *puVar4 = ilInstAOpcode;
  *pdVar6 = ilInstADst;
  *pdVar9 = ilInstADstMask;
  do {
    puVar4[3] = *recordPtr2;
    recordWordNext2 = recordPtr2 + 3;
    recordPtr2 = recordPtr2 + 1;
    puVar4[4] = *recordWordNext2;
    puVar4 = puVar4 + 2;
  } while (&ilInstASwz0 != recordPtr2);
  return 0;
}

/* fragmentTranslateAtn @ 0x41c00 (4544 bytes) */
int fragmentTranslateAtn(emitter, slot, instr)
  int *emitter;
  int slot;
  int instr;
{
  uint tokenCapacity;
  uint *tokenWritePtr;
  uint *recordPtr4;
  undefined **recordPtr3;
  undefined **recordPtr;
  undefined4 *recordWordNext;
  uint *recordWordNext2;
  undefined **recordWordNext3;
  undefined *puVar4;
  uint capacity;
  int bufferCount;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  undefined4 extraout_r4_02;
  undefined4 extraout_r4_03;
  undefined4 extraout_r4_04;
  undefined4 uVar7;
  uint srcRegWord1;
  undefined *puVar9;
  char *pcVar10;
  undefined **ppuVar11;
  undefined4 uVar12;
  uint *puVar13;
  short tempRegisterHalf;
  undefined4 *recordPtr2;
  undefined **recordWordNext4;
  uint *puVar16;
  undefined4 *tokenWritePtr2;
  int tempRegister;
  int *bufferDataPtr;
  undefined4 entryHeader;
  undefined4 ilInstADst;
  uint ilInstADstMask;
  undefined4 ilInstASrc0;
  undefined4 ilInstASrc1;
  undefined4 ilInstASrc2;
  undefined *apuStack_50 [11];
  
  if ((*(uint *)((slot + *(int *)(*emitter + 0x54)) * 8 + *emitter) & 0xe0000000) == 0x20000000)
  {
    *(undefined4 *)(instr + 0x10) = 0x40000;
    *(undefined2 *)(instr + 0x12) = 0;
    *(undefined **)(instr + 0x1c) = ((unsigned char *)0x00005555);
    *(uint *)(instr + 0x10) = *(uint *)(instr + 0x10) | 0x400000;
  }
  _memset(&entryHeader,0,0x24);
  tempRegister = emitter[8];
  bufferCount = emitter[9];
  ilInstADst = CONCAT22(4,(short)tempRegister);
  entryHeader = CONCAT22((*(unsigned short *)((unsigned char *)&(entryHeader) + 0)),0x5b);
  srcRegWord1 = *(uint *)(instr + 0x10);
  ilInstADstMask = 0x55;
  apuStack_50[0] = (undefined *)(*(uint *)(instr + 0x18) & 0xffff7777 | 0x100000);
  apuStack_50[1] = (undefined *)(*(uint *)(instr + 0x1c) & 0xffff7777 | 0x100000);
  ilInstASrc0 = *(undefined **)(instr + 0xc);
  ilInstASrc1 = (undefined *)srcRegWord1;
  ilInstADst = ilInstADst | 0x400000;
  if (bufferCount == 0) {
    bufferDataPtr = emitter + 10;
    bufferCount = emitter[0xb];
    capacity = emitter[0xc];
    if (capacity < bufferCount + 7U) {
      if (capacity == 0) {
        capacity = 0x10;
      }
      else {
        capacity = capacity << 1;
      }
      for (; capacity < bufferCount + 7U; capacity = capacity << 1) {
      }
      if (*bufferDataPtr == 0) {
        bufferCount = _malloc(capacity << 2);
      }
      else {
        bufferCount = _realloc(*bufferDataPtr,capacity << 2);
      }
      if (bufferCount == 0) {
        bufferCount = emitter[9];
        if (bufferCount == 0) {
          bufferCount = 1;
          emitter[9] = 1;
        }
        tempRegister = emitter[8];
        goto LAB_00041e30;
      }
      *bufferDataPtr = bufferCount;
      emitter[0xc] = capacity;
      bufferCount = emitter[0xb];
    }
    recordPtr2 = &ilInstASrc0;
    emitter[0xb] = bufferCount + 7;
    tokenWritePtr2 = (undefined4 *)(bufferCount * 4 + *bufferDataPtr);
    *tokenWritePtr2 = entryHeader;
    tokenWritePtr2[1] = ilInstADst;
    tokenWritePtr2[2] = ilInstADstMask;
    do {
      tokenWritePtr2[3] = *recordPtr2;
      recordWordNext = recordPtr2 + 3;
      recordPtr2 = recordPtr2 + 1;
      tokenWritePtr2[4] = *recordWordNext;
      tokenWritePtr2 = tokenWritePtr2 + 2;
    } while (&ilInstASrc2 != recordPtr2);
    tempRegister = emitter[8];
    bufferCount = emitter[9];
  }
LAB_00041e30:
  puVar4 = apuStack_50[0];
  ilInstASrc2 = (uint *)ilInstASrc1;
  puVar9 = ilInstASrc0;
  entryHeader = CONCAT22((*(unsigned short *)((unsigned char *)&(entryHeader) + 0)),0xd);
  ilInstADst = CONCAT22(4,(short)tempRegister + 1);
  ilInstASrc0 = (undefined *)CONCAT22(4,(short)tempRegister);
  ilInstASrc1 = puVar9;
  ilInstADstMask = 0x55;
  apuStack_50[2] = apuStack_50[1];
  apuStack_50[0] = ((unsigned char *)0x00003210);
  apuStack_50[1] = puVar4;
  entryHeader = entryHeader & 0xc000ffff | 0x30000;
  ilInstADst = ilInstADst | 0x400000;
  ilInstASrc0 = (undefined *)((uint)ilInstASrc0 | 0x400000);
  if (bufferCount == 0) {
    bufferDataPtr = emitter + 10;
    bufferCount = emitter[0xb];
    capacity = emitter[0xc];
    if (capacity < bufferCount + 9U) {
      if (capacity == 0) {
        capacity = 0x10;
      }
      else {
        capacity = capacity << 1;
      }
      for (; capacity < bufferCount + 9U; capacity = capacity << 1) {
      }
      if (*bufferDataPtr == 0) {
        bufferCount = _malloc(capacity << 2);
      }
      else {
        bufferCount = _realloc(*bufferDataPtr,capacity << 2);
      }
      if (bufferCount == 0) {
        bufferCount = emitter[9];
        if (bufferCount == 0) {
          bufferCount = 1;
          emitter[9] = 1;
        }
        tempRegister = emitter[8];
        goto LAB_00042000;
      }
      *bufferDataPtr = bufferCount;
      emitter[0xc] = capacity;
      bufferCount = emitter[0xb];
    }
    recordPtr = (undefined **)&ilInstASrc0;
    emitter[0xb] = bufferCount + 9;
    tokenWritePtr = (uint *)(bufferCount * 4 + *bufferDataPtr);
    *tokenWritePtr = entryHeader;
    tokenWritePtr[1] = ilInstADst;
    tokenWritePtr[2] = ilInstADstMask;
    do {
      tokenWritePtr[3] = (uint)*recordPtr;
      recordWordNext4 = recordPtr + 3;
      recordPtr = recordPtr + 1;
      tokenWritePtr[4] = (uint)*recordWordNext4;
      tokenWritePtr = tokenWritePtr + 2;
    } while (apuStack_50 != recordPtr);
    tempRegister = emitter[8];
    bufferCount = emitter[9];
  }
LAB_00042000:
  ilInstASrc0 = (undefined *)CONCAT22(4,(short)tempRegister);
  ilInstADst = CONCAT22(4,(short)tempRegister + 2);
  entryHeader = entryHeader & 0xc000ffff | 0x40000;
  ilInstADstMask = 0x55;
  apuStack_50[0] = ((unsigned char *)0x00003210);
  ilInstADst = ilInstADst | 0x400000;
  ilInstASrc0 = (undefined *)((uint)ilInstASrc0 | 0x400000);
  if (bufferCount == 0) {
    bufferDataPtr = emitter + 10;
    bufferCount = emitter[0xb];
    capacity = emitter[0xc];
    if (capacity < bufferCount + 9U) {
      if (capacity == 0) {
        capacity = 0x10;
      }
      else {
        capacity = capacity << 1;
      }
      for (; capacity < bufferCount + 9U; capacity = capacity << 1) {
      }
      if (*bufferDataPtr == 0) {
        bufferCount = _malloc(capacity << 2);
      }
      else {
        bufferCount = _realloc(*bufferDataPtr,capacity << 2);
      }
      if (bufferCount == 0) {
        bufferCount = emitter[9];
        if (bufferCount == 0) {
          bufferCount = 1;
          emitter[9] = 1;
        }
        tempRegister = emitter[8];
        goto LAB_000421a0;
      }
      *bufferDataPtr = bufferCount;
      emitter[0xc] = capacity;
      bufferCount = emitter[0xb];
    }
    recordPtr = (undefined **)&ilInstASrc0;
    emitter[0xb] = bufferCount + 9;
    tokenWritePtr = (uint *)(bufferCount * 4 + *bufferDataPtr);
    *tokenWritePtr = entryHeader;
    tokenWritePtr[1] = ilInstADst;
    tokenWritePtr[2] = ilInstADstMask;
    do {
      tokenWritePtr[3] = (uint)*recordPtr;
      recordWordNext4 = recordPtr + 3;
      recordPtr = recordPtr + 1;
      tokenWritePtr[4] = (uint)*recordWordNext4;
      tokenWritePtr = tokenWritePtr + 2;
    } while (apuStack_50 != recordPtr);
    tempRegister = emitter[8];
    bufferCount = emitter[9];
  }
LAB_000421a0:
  tempRegisterHalf = (short)tempRegister + 1;
  entryHeader = CONCAT22((*(unsigned short *)((unsigned char *)&(entryHeader) + 0)),0x20);
  ilInstASrc0 = (undefined *)CONCAT22(4,(short)tempRegister + 2);
  ilInstADst = CONCAT22(4,tempRegisterHalf);
  ilInstASrc1 = (undefined *)CONCAT22(4,tempRegisterHalf);
  pcVar10 = (*(GhidraMachOSection *)0x00000054).sectname + 1;
  ilInstADstMask = 0x55;
  apuStack_50[0] = ((unsigned char *)0x00003210);
  apuStack_50[1] = ((unsigned char *)0x00003210);
  entryHeader = entryHeader & 0xc000ffff;
  ilInstADst = ilInstADst | 0x400000;
  ilInstASrc0 = (undefined *)((uint)ilInstASrc0 | 0x400000);
  ilInstASrc1 = (undefined *)((uint)ilInstASrc1 | 0x400000);
  if (bufferCount == 0) {
    bufferDataPtr = emitter + 10;
    bufferCount = emitter[0xb];
    capacity = emitter[0xc];
    if (capacity < bufferCount + 7U) {
      if (capacity == 0) {
        capacity = 0x10;
      }
      else {
        capacity = capacity << 1;
      }
      for (; capacity < bufferCount + 7U; capacity = capacity << 1) {
      }
      if (*bufferDataPtr == 0) {
        bufferCount = _malloc(capacity << 2);
      }
      else {
        bufferCount = _realloc(*bufferDataPtr,capacity << 2);
      }
      if (bufferCount != 0) {
        *bufferDataPtr = bufferCount;
        emitter[0xc] = capacity;
        bufferCount = emitter[0xb];
        goto LAB_000422f0;
      }
      if (emitter[9] == 0) {
        emitter[9] = 1;
      }
    }
    else {
LAB_000422f0:
      recordPtr4 = &ilInstASrc0;
      pcVar10 = (char *)&ilInstASrc2;
      emitter[0xb] = bufferCount + 7;
      tokenWritePtr = (uint *)(bufferCount * 4 + *bufferDataPtr);
      *tokenWritePtr = entryHeader;
      tokenWritePtr[1] = ilInstADst;
      tokenWritePtr[2] = ilInstADstMask;
      do {
        tokenWritePtr[3] = *recordPtr4;
        recordWordNext2 = recordPtr4 + 3;
        recordPtr4 = recordPtr4 + 1;
        tokenWritePtr[4] = *recordWordNext2;
        tokenWritePtr = tokenWritePtr + 2;
      } while ((uint *)pcVar10 != recordPtr4);
    }
    tempRegister = emitter[8];
  }
  ilInstASrc0 = (undefined *)CONCAT22(4,(short)tempRegister + 1);
  emitter[8] = tempRegister + 3;
  (*(unsigned short *)((unsigned char *)&(entryHeader) + 2)) = 5;
  uVar12 = 0xffff7777;
  apuStack_50[0] = ((unsigned char *)0x00003210);
  ilInstASrc0 = (undefined *)((uint)ilInstASrc0 | 0x400000);
  ((int (*)())fragmentTranslateScalarMath)(emitter,slot,&entryHeader);
  uVar7 = 0x24;
  emitter[8] = emitter[8] + -3;
  _memset(&entryHeader,0,0x24);
  entryHeader = CONCAT22((*(unsigned short *)((unsigned char *)&(entryHeader) + 0)),0x5b);
  ((int (*)())fpilEmitAngleConstants)(emitter,extraout_r4,uVar7,srcRegWord1,puVar9,pcVar10,uVar12);
  tempRegisterHalf = (short)emitter[8];
  ilInstASrc1 = (undefined *)CONCAT22(4,tempRegisterHalf + 1);
  ilInstADst = CONCAT22(4,tempRegisterHalf + 2);
  ilInstASrc0 = (undefined *)CONCAT22(1,(short)*(undefined4 *)(*emitter + 0x28));
  bufferCount = emitter[9];
  apuStack_50[1] = ((unsigned char *)0x00003210);
  ilInstADstMask = 0x55;
  ilInstADst = ilInstADst | 0x400000;
  ilInstASrc1 = (undefined *)((uint)ilInstASrc1 | 0x400000);
  ilInstASrc0 = (undefined *)((uint)ilInstASrc0 | 0x400000);
  apuStack_50[0] = ((unsigned char *)0x00001111);
  uVar7 = extraout_r4_00;
  if (bufferCount == 0) {
    bufferDataPtr = emitter + 10;
    bufferCount = emitter[0xb];
    tokenCapacity = emitter[0xc];
    if (tokenCapacity < bufferCount + 7U) {
      if (tokenCapacity == 0) {
        tokenCapacity = 0x10;
      }
      else {
        tokenCapacity = tokenCapacity << 1;
      }
      for (; tokenCapacity < bufferCount + 7U; tokenCapacity = tokenCapacity << 1) {
      }
      if (*bufferDataPtr == 0) {
        bufferCount = _malloc(tokenCapacity << 2);
        uVar7 = extraout_r4_01;
      }
      else {
        bufferCount = _realloc(*bufferDataPtr,tokenCapacity << 2);
        uVar7 = extraout_r4_02;
      }
      if (bufferCount == 0) {
        bufferCount = emitter[9];
        if (bufferCount == 0) {
          bufferCount = 1;
          emitter[9] = 1;
        }
        tempRegisterHalf = (short)emitter[8];
        goto LAB_00042600;
      }
      *bufferDataPtr = bufferCount;
      emitter[0xc] = tokenCapacity;
      bufferCount = emitter[0xb];
    }
    recordPtr2 = &ilInstASrc0;
    emitter[0xb] = bufferCount + 7;
    tokenWritePtr2 = (undefined4 *)(bufferCount * 4 + *bufferDataPtr);
    *tokenWritePtr2 = entryHeader;
    tokenWritePtr2[1] = ilInstADst;
    tokenWritePtr2[2] = ilInstADstMask;
    do {
      tokenWritePtr2[3] = *recordPtr2;
      recordWordNext = recordPtr2 + 3;
      recordPtr2 = recordPtr2 + 1;
      tokenWritePtr2[4] = *recordWordNext;
      tokenWritePtr2 = tokenWritePtr2 + 2;
    } while (&ilInstASrc2 != recordPtr2);
    tempRegisterHalf = (short)emitter[8];
    bufferCount = emitter[9];
  }
LAB_00042600:
  entryHeader = CONCAT22((*(unsigned short *)((unsigned char *)&(entryHeader) + 0)),0xd);
  ilInstASrc0 = (undefined *)CONCAT22(4,tempRegisterHalf);
  ilInstASrc1 = (undefined *)CONCAT22(4,tempRegisterHalf + 2);
  ilInstADst = CONCAT22(4,tempRegisterHalf + 1);
  ilInstASrc2 = (uint *)CONCAT22(4,tempRegisterHalf + 1);
  uVar12 = 0x55;
  puVar9 = ((unsigned char *)0x00003210);
  ppuVar11 = (undefined **)((unsigned char *)0x00003210);
  ilInstADstMask = 0x55;
  apuStack_50[2] = ((unsigned char *)0x00003210);
  apuStack_50[1] = ((unsigned char *)0x00003210);
  apuStack_50[0] = ((unsigned char *)0x00003210);
  entryHeader = entryHeader & 0xc000ffff | 0x30000;
  ilInstADst = ilInstADst | 0x400000;
  ilInstASrc0 = (undefined *)((uint)ilInstASrc0 | 0x400000);
  ilInstASrc1 = (undefined *)((uint)ilInstASrc1 | 0x400000);
  puVar13 = (uint *)((uint)ilInstASrc2 | 0x400000);
  ilInstASrc2 = puVar13;
  if (bufferCount == 0) {
    bufferDataPtr = emitter + 10;
    puVar13 = (uint *)emitter[0xb];
    tokenCapacity = emitter[0xc];
    if (tokenCapacity < (int)puVar13 + 9U) {
      if (tokenCapacity == 0) {
        tokenCapacity = 0x10;
      }
      else {
        tokenCapacity = tokenCapacity << 1;
      }
      for (; tokenCapacity < (int)puVar13 + 9U; tokenCapacity = tokenCapacity << 1) {
      }
      if (*bufferDataPtr == 0) {
        bufferCount = _malloc(tokenCapacity << 2);
        uVar7 = extraout_r4_03;
      }
      else {
        bufferCount = _realloc(*bufferDataPtr,tokenCapacity << 2);
        uVar7 = extraout_r4_04;
      }
      if (bufferCount == 0) {
        if (emitter[9] == 0) {
          emitter[9] = 1;
        }
        goto LAB_00042800;
      }
      *bufferDataPtr = bufferCount;
      emitter[0xc] = tokenCapacity;
      puVar13 = (uint *)emitter[0xb];
    }
    recordPtr3 = (undefined **)&ilInstASrc0;
    ppuVar11 = apuStack_50;
    emitter[0xb] = (int)puVar13 + 9;
    puVar13 = (uint *)((int)puVar13 * 4 + *bufferDataPtr);
    *puVar13 = entryHeader;
    puVar13[1] = ilInstADst;
    puVar13[2] = ilInstADstMask;
    puVar16 = puVar13;
    do {
      puVar16[3] = (uint)*recordPtr3;
      recordWordNext3 = recordPtr3 + 3;
      recordPtr3 = recordPtr3 + 1;
      puVar16[4] = (uint)*recordWordNext3;
      puVar16 = puVar16 + 2;
    } while (ppuVar11 != recordPtr3);
  }
LAB_00042800:
  entryHeader = CONCAT22((*(unsigned short *)((unsigned char *)&(entryHeader) + 0)),0x5b);
  entryHeader = entryHeader & 0xc000ffff;
  ((int (*)())fpilEmitAngleConstants)(emitter,uVar7,entryHeader,uVar12,puVar9,ppuVar11,puVar13);
  tempRegisterHalf = (short)emitter[8];
  ilInstASrc0 = (undefined *)CONCAT22(1,(short)*(undefined4 *)(*emitter + 0x28));
  ilInstADst = CONCAT22(4,tempRegisterHalf + 2);
  ilInstASrc1 = (undefined *)CONCAT22(4,tempRegisterHalf + 1);
  bufferCount = emitter[9];
  apuStack_50[0] = (undefined *)0x0;
  apuStack_50[1] = ((unsigned char *)0x00003210);
  ilInstADstMask = 0x55;
  ilInstASrc0 = (undefined *)((uint)ilInstASrc0 | 0x400000);
  ilInstADst = ilInstADst | 0x400000;
  ilInstASrc1 = (undefined *)((uint)ilInstASrc1 | 0x400000);
  if (bufferCount == 0) {
    bufferDataPtr = emitter + 10;
    bufferCount = emitter[0xb];
    tokenCapacity = emitter[0xc];
    if (tokenCapacity < bufferCount + 7U) {
      if (tokenCapacity == 0) {
        tokenCapacity = 0x10;
      }
      else {
        tokenCapacity = tokenCapacity << 1;
      }
      for (; tokenCapacity < bufferCount + 7U; tokenCapacity = tokenCapacity << 1) {
      }
      if (*bufferDataPtr == 0) {
        bufferCount = _malloc(tokenCapacity << 2);
      }
      else {
        bufferCount = _realloc(*bufferDataPtr,tokenCapacity << 2);
      }
      if (bufferCount == 0) {
        bufferCount = emitter[9];
        if (bufferCount == 0) {
          bufferCount = 1;
          emitter[9] = 1;
        }
        tempRegisterHalf = (short)emitter[8];
        goto LAB_000429f0;
      }
      *bufferDataPtr = bufferCount;
      emitter[0xc] = tokenCapacity;
      bufferCount = emitter[0xb];
    }
    recordPtr4 = &ilInstASrc0;
    emitter[0xb] = bufferCount + 7;
    tokenWritePtr = (uint *)(bufferCount * 4 + *bufferDataPtr);
    *tokenWritePtr = entryHeader;
    tokenWritePtr[1] = ilInstADst;
    tokenWritePtr[2] = ilInstADstMask;
    do {
      tokenWritePtr[3] = *recordPtr4;
      recordWordNext2 = recordPtr4 + 3;
      recordPtr4 = recordPtr4 + 1;
      tokenWritePtr[4] = *recordWordNext2;
      tokenWritePtr = tokenWritePtr + 2;
    } while (recordPtr4 != &ilInstASrc2);
    tempRegisterHalf = (short)emitter[8];
    bufferCount = emitter[9];
  }
LAB_000429f0:
  entryHeader = CONCAT22((*(unsigned short *)((unsigned char *)&(entryHeader) + 0)),0xd);
  ilInstASrc1 = (undefined *)CONCAT22(4,tempRegisterHalf + 2);
  ilInstASrc2 = (uint *)CONCAT22(4,tempRegisterHalf + 1);
  ilInstADst = CONCAT22(4,tempRegisterHalf + 1);
  entryHeader = entryHeader & 0xc000ffff | 0x50000;
  ilInstADstMask = 0x55;
  apuStack_50[1] = ((unsigned char *)0x00003210);
  apuStack_50[2] = ((unsigned char *)0x00003210);
  ilInstASrc0 = *(undefined **)(instr + 0x10);
  apuStack_50[0] = *(undefined **)(instr + 0x1c);
  ilInstADst = ilInstADst | 0x400000;
  ilInstASrc1 = (undefined *)((uint)ilInstASrc1 | 0x400000);
  ilInstASrc2 = (uint *)((uint)ilInstASrc2 | 0x400000);
  if (bufferCount == 0) {
    bufferDataPtr = emitter + 10;
    bufferCount = emitter[0xb];
    tokenCapacity = emitter[0xc];
    if (tokenCapacity < bufferCount + 9U) {
      if (tokenCapacity == 0) {
        tokenCapacity = 0x10;
      }
      else {
        tokenCapacity = tokenCapacity << 1;
      }
      for (; tokenCapacity < bufferCount + 9U; tokenCapacity = tokenCapacity << 1) {
      }
      if (*bufferDataPtr == 0) {
        bufferCount = _malloc(tokenCapacity << 2);
      }
      else {
        bufferCount = _realloc(*bufferDataPtr,tokenCapacity << 2);
      }
      if (bufferCount == 0) {
        bufferCount = emitter[9];
        if (bufferCount == 0) {
          bufferCount = 1;
          emitter[9] = 1;
        }
        tempRegisterHalf = (short)emitter[8];
        goto LAB_00042bf0;
      }
      *bufferDataPtr = bufferCount;
      emitter[0xc] = tokenCapacity;
      bufferCount = emitter[0xb];
    }
    recordPtr = (undefined **)&ilInstASrc0;
    emitter[0xb] = bufferCount + 9;
    tokenWritePtr = (uint *)(bufferCount * 4 + *bufferDataPtr);
    *tokenWritePtr = entryHeader;
    tokenWritePtr[1] = ilInstADst;
    tokenWritePtr[2] = ilInstADstMask;
    do {
      tokenWritePtr[3] = (uint)*recordPtr;
      recordWordNext4 = recordPtr + 3;
      recordPtr = recordPtr + 1;
      tokenWritePtr[4] = (uint)*recordWordNext4;
      tokenWritePtr = tokenWritePtr + 2;
    } while (apuStack_50 != recordPtr);
    tempRegisterHalf = (short)emitter[8];
    bufferCount = emitter[9];
  }
LAB_00042bf0:
  entryHeader = CONCAT22((*(unsigned short *)((unsigned char *)&(entryHeader) + 0)),0xd);
  ilInstASrc2 = (uint *)CONCAT22(4,tempRegisterHalf + 1);
  ilInstASrc1 = (undefined *)CONCAT22(4,tempRegisterHalf + 1);
  entryHeader = entryHeader & 0xc000ffff | 0x50000;
  ilInstADstMask = *(uint *)(instr + 8);
  ilInstADst = *(uint *)(instr + 4);
  apuStack_50[2] = ((unsigned char *)0x00003210);
  ilInstASrc0 = *(undefined **)(instr + 0xc);
  apuStack_50[0] = *(undefined **)(instr + 0x18);
  ilInstASrc1 = (undefined *)((uint)ilInstASrc1 | 0x400000);
  ilInstASrc2 = (uint *)((uint)ilInstASrc2 | 0x400000);
  apuStack_50[1] = (undefined *)0xba98;
  if (bufferCount == 0) {
    bufferDataPtr = emitter + 10;
    bufferCount = emitter[0xb];
    tokenCapacity = emitter[0xc];
    if (tokenCapacity < bufferCount + 9U) {
      if (tokenCapacity == 0) {
        tokenCapacity = 0x10;
      }
      else {
        tokenCapacity = tokenCapacity << 1;
      }
      for (; tokenCapacity < bufferCount + 9U; tokenCapacity = tokenCapacity << 1) {
      }
      if (*bufferDataPtr == 0) {
        bufferCount = _malloc(tokenCapacity << 2);
      }
      else {
        bufferCount = _realloc(*bufferDataPtr,tokenCapacity << 2);
      }
      if (bufferCount == 0) {
        if (emitter[9] != 0) {
          return emitter[9];
        }
        emitter[9] = 1;
        return 1;
      }
      *bufferDataPtr = bufferCount;
      emitter[0xc] = tokenCapacity;
      bufferCount = emitter[0xb];
    }
    recordPtr = (undefined **)&ilInstASrc0;
    emitter[0xb] = bufferCount + 9;
    tokenWritePtr = (uint *)(bufferCount * 4 + *bufferDataPtr);
    *tokenWritePtr = entryHeader;
    tokenWritePtr[1] = ilInstADst;
    tokenWritePtr[2] = ilInstADstMask;
    do {
      tokenWritePtr[3] = (uint)*recordPtr;
      recordWordNext4 = recordPtr + 3;
      recordPtr = recordPtr + 1;
      tokenWritePtr[4] = (uint)*recordWordNext4;
      tokenWritePtr = tokenWritePtr + 2;
    } while (apuStack_50 != recordPtr);
    bufferCount = emitter[9];
  }
  return bufferCount;
}

/* fragmentTranslateRfr @ 0x42e00 (4024 bytes) */
int fragmentTranslateRfr(emitter, slot, instr)
  int emitter;
  undefined4 slot;
  int instr;
{
  undefined4 *recordWordNext;
  undefined **recordWordNext2;
  uint capacity;
  int bufferCount;
  undefined4 *recordPtr;
  undefined **recordPtr2;
  undefined4 *tokenWritePtr;
  uint *tokenWritePtr2;
  int *bufferDataPtr;
  short sVar10;
  undefined4 entryHeader;
  undefined4 ilInstADst;
  uint ilInstADstMask;
  undefined4 ilInstASrc0;
  undefined4 ilInstASrc1;
  undefined4 ilInstASrc2;
  undefined *apuStack_40 [11];
  
  _memset(&entryHeader,0,0x24);
  bufferCount = *(int *)(emitter + 0x24);
  sVar10 = (short)*(undefined4 *)(emitter + 0x20);
  ilInstADst = CONCAT22(4,sVar10);
  entryHeader = CONCAT22((*(unsigned short *)((unsigned char *)&(entryHeader) + 0)),0x23);
  ilInstADstMask = 0x55;
  ilInstASrc0 = *(undefined **)(instr + 0xc);
  apuStack_40[0] = *(undefined **)(instr + 0x18);
  ilInstASrc1 = (undefined *)*(undefined4 *)(instr + 0x10);
  apuStack_40[1] = (undefined *)*(undefined4 *)(instr + 0x1c);
  ilInstADst = ilInstADst | 0x400000;
  if (bufferCount == 0) {
    bufferDataPtr = (int *)(emitter + 0x28);
    bufferCount = *(int *)(emitter + 0x2c);
    capacity = *(uint *)(emitter + 0x30);
    if (capacity < bufferCount + 7U) {
      if (capacity == 0) {
        capacity = 0x10;
      }
      else {
        capacity = capacity << 1;
      }
      for (; capacity < bufferCount + 7U; capacity = capacity << 1) {
      }
      if (*bufferDataPtr == 0) {
        bufferCount = _malloc(capacity << 2);
      }
      else {
        bufferCount = _realloc(*bufferDataPtr,capacity << 2);
      }
      if (bufferCount == 0) {
        bufferCount = *(int *)(emitter + 0x24);
        if (bufferCount == 0) {
          bufferCount = 1;
          *(undefined4 *)(emitter + 0x24) = 1;
        }
        sVar10 = (short)*(undefined4 *)(emitter + 0x20);
        goto LAB_00042fa0;
      }
      *bufferDataPtr = bufferCount;
      *(uint *)(emitter + 0x30) = capacity;
      bufferCount = *(int *)(emitter + 0x2c);
    }
    recordPtr = &ilInstASrc0;
    *(int *)(emitter + 0x2c) = bufferCount + 7;
    tokenWritePtr = (undefined4 *)(bufferCount * 4 + *bufferDataPtr);
    *tokenWritePtr = entryHeader;
    tokenWritePtr[1] = ilInstADst;
    tokenWritePtr[2] = ilInstADstMask;
    do {
      tokenWritePtr[3] = *recordPtr;
      recordWordNext = recordPtr + 3;
      recordPtr = recordPtr + 1;
      tokenWritePtr[4] = *recordWordNext;
      tokenWritePtr = tokenWritePtr + 2;
    } while (&ilInstASrc2 != recordPtr);
    sVar10 = (short)*(undefined4 *)(emitter + 0x20);
    bufferCount = *(int *)(emitter + 0x24);
  }
LAB_00042fa0:
  ilInstADst = CONCAT22(4,sVar10 + 1);
  ilInstASrc0 = (undefined *)CONCAT22(4,sVar10);
  ilInstASrc1 = (undefined *)CONCAT22(4,sVar10);
  ilInstADstMask = 0x55;
  apuStack_40[0] = ((unsigned char *)0x00003210);
  entryHeader = CONCAT22((*(unsigned short *)((unsigned char *)&(entryHeader) + 0)),0x40);
  apuStack_40[1] = ((unsigned char *)0x00003210);
  apuStack_40[2] = (undefined *)0xdddd;
  ilInstADst = ilInstADst | 0x400000;
  ilInstASrc0 = (undefined *)((uint)ilInstASrc0 | 0x400000);
  ilInstASrc2 = 0x440000;
  ilInstASrc1 = (undefined *)((uint)ilInstASrc1 | 0x400000);
  if (bufferCount == 0) {
    bufferDataPtr = (int *)(emitter + 0x28);
    bufferCount = *(int *)(emitter + 0x2c);
    capacity = *(uint *)(emitter + 0x30);
    if (capacity < bufferCount + 9U) {
      if (capacity == 0) {
        capacity = 0x10;
      }
      else {
        capacity = capacity << 1;
      }
      for (; capacity < bufferCount + 9U; capacity = capacity << 1) {
      }
      if (*bufferDataPtr == 0) {
        bufferCount = _malloc(capacity << 2);
      }
      else {
        bufferCount = _realloc(*bufferDataPtr,capacity << 2);
      }
      if (bufferCount == 0) {
        bufferCount = *(int *)(emitter + 0x24);
        if (bufferCount == 0) {
          bufferCount = 1;
          *(undefined4 *)(emitter + 0x24) = 1;
        }
        sVar10 = (short)*(undefined4 *)(emitter + 0x20);
        goto LAB_000431b0;
      }
      *bufferDataPtr = bufferCount;
      *(uint *)(emitter + 0x30) = capacity;
      bufferCount = *(int *)(emitter + 0x2c);
    }
    recordPtr2 = (undefined **)&ilInstASrc0;
    *(int *)(emitter + 0x2c) = bufferCount + 9;
    tokenWritePtr = (undefined4 *)(bufferCount * 4 + *bufferDataPtr);
    *tokenWritePtr = entryHeader;
    tokenWritePtr[1] = ilInstADst;
    tokenWritePtr[2] = ilInstADstMask;
    do {
      tokenWritePtr[3] = *recordPtr2;
      recordWordNext2 = recordPtr2 + 3;
      recordPtr2 = recordPtr2 + 1;
      tokenWritePtr[4] = *recordWordNext2;
      tokenWritePtr = tokenWritePtr + 2;
    } while (apuStack_40 != recordPtr2);
    sVar10 = (short)*(undefined4 *)(emitter + 0x20);
    bufferCount = *(int *)(emitter + 0x24);
  }
LAB_000431b0:
  ilInstADst = CONCAT22(4,sVar10 + 2);
  entryHeader = CONCAT22((*(unsigned short *)((unsigned char *)&(entryHeader) + 0)),0x49);
  ilInstADstMask = 0x55;
  ilInstASrc1 = *(undefined **)(instr + 0x14);
  apuStack_40[1] = *(undefined **)(instr + 0x20);
  ilInstASrc0 = *(undefined **)(instr + 0x14);
  apuStack_40[0] = *(undefined **)(instr + 0x20);
  ilInstADst = ilInstADst | 0x400000;
  if (bufferCount == 0) {
    bufferDataPtr = (int *)(emitter + 0x28);
    bufferCount = *(int *)(emitter + 0x2c);
    capacity = *(uint *)(emitter + 0x30);
    if (capacity < bufferCount + 7U) {
      if (capacity == 0) {
        capacity = 0x10;
      }
      else {
        capacity = capacity << 1;
      }
      for (; capacity < bufferCount + 7U; capacity = capacity << 1) {
      }
      if (*bufferDataPtr == 0) {
        bufferCount = _malloc(capacity << 2);
      }
      else {
        bufferCount = _realloc(*bufferDataPtr,capacity << 2);
      }
      if (bufferCount == 0) {
        bufferCount = *(int *)(emitter + 0x24);
        if (bufferCount == 0) {
          bufferCount = 1;
          *(undefined4 *)(emitter + 0x24) = 1;
        }
        sVar10 = (short)*(undefined4 *)(emitter + 0x20);
        goto LAB_00043320;
      }
      *bufferDataPtr = bufferCount;
      *(uint *)(emitter + 0x30) = capacity;
      bufferCount = *(int *)(emitter + 0x2c);
    }
    recordPtr = &ilInstASrc0;
    *(int *)(emitter + 0x2c) = bufferCount + 7;
    tokenWritePtr = (undefined4 *)(bufferCount * 4 + *bufferDataPtr);
    *tokenWritePtr = entryHeader;
    tokenWritePtr[1] = ilInstADst;
    tokenWritePtr[2] = ilInstADstMask;
    do {
      tokenWritePtr[3] = *recordPtr;
      recordWordNext = recordPtr + 3;
      recordPtr = recordPtr + 1;
      tokenWritePtr[4] = *recordWordNext;
      tokenWritePtr = tokenWritePtr + 2;
    } while (&ilInstASrc2 != recordPtr);
    sVar10 = (short)*(undefined4 *)(emitter + 0x20);
    bufferCount = *(int *)(emitter + 0x24);
  }
LAB_00043320:
  ilInstADst = CONCAT22(4,sVar10 + 1);
  ilInstASrc0 = (undefined *)CONCAT22(4,sVar10 + 2);
  ilInstASrc1 = (undefined *)CONCAT22(4,sVar10 + 1);
  ilInstADstMask = 0x55;
  entryHeader = CONCAT22((*(unsigned short *)((unsigned char *)&(entryHeader) + 0)),0x40);
  apuStack_40[1] = ((unsigned char *)0x00003210);
  apuStack_40[0] = ((unsigned char *)0x00003210);
  ilInstADst = ilInstADst | 0x400000;
  ilInstASrc0 = (undefined *)((uint)ilInstASrc0 | 0x400000);
  ilInstASrc1 = (undefined *)((uint)ilInstASrc1 | 0x400000);
  apuStack_40[2] = ((unsigned char *)0x00005555U);
  ilInstASrc2 = 0x440000;
  if (bufferCount == 0) {
    bufferDataPtr = (int *)(emitter + 0x28);
    bufferCount = *(int *)(emitter + 0x2c);
    capacity = *(uint *)(emitter + 0x30);
    if (capacity < bufferCount + 9U) {
      if (capacity == 0) {
        capacity = 0x10;
      }
      else {
        capacity = capacity << 1;
      }
      for (; capacity < bufferCount + 9U; capacity = capacity << 1) {
      }
      if (*bufferDataPtr == 0) {
        bufferCount = _malloc(capacity << 2);
      }
      else {
        bufferCount = _realloc(*bufferDataPtr,capacity << 2);
      }
      if (bufferCount == 0) {
        bufferCount = *(int *)(emitter + 0x24);
        if (bufferCount == 0) {
          bufferCount = 1;
          *(undefined4 *)(emitter + 0x24) = 1;
        }
        sVar10 = (short)*(undefined4 *)(emitter + 0x20);
        goto LAB_00043510;
      }
      *bufferDataPtr = bufferCount;
      *(uint *)(emitter + 0x30) = capacity;
      bufferCount = *(int *)(emitter + 0x2c);
    }
    recordPtr2 = (undefined **)&ilInstASrc0;
    *(int *)(emitter + 0x2c) = bufferCount + 9;
    tokenWritePtr = (undefined4 *)(bufferCount * 4 + *bufferDataPtr);
    *tokenWritePtr = entryHeader;
    tokenWritePtr[1] = ilInstADst;
    tokenWritePtr[2] = ilInstADstMask;
    do {
      tokenWritePtr[3] = *recordPtr2;
      recordWordNext2 = recordPtr2 + 3;
      recordPtr2 = recordPtr2 + 1;
      tokenWritePtr[4] = *recordWordNext2;
      tokenWritePtr = tokenWritePtr + 2;
    } while (apuStack_40 != recordPtr2);
    sVar10 = (short)*(undefined4 *)(emitter + 0x20);
    bufferCount = *(int *)(emitter + 0x24);
  }
LAB_00043510:
  ilInstADst = CONCAT22(4,sVar10 + 2);
  ilInstASrc0 = (undefined *)CONCAT22(4,sVar10 + 1);
  ilInstADstMask = 0x55;
  entryHeader = CONCAT22((*(unsigned short *)((unsigned char *)&(entryHeader) + 0)),0x5a);
  apuStack_40[0] = ((unsigned char *)0x00003210);
  ilInstADst = ilInstADst | 0x400000;
  ilInstASrc0 = (undefined *)((uint)ilInstASrc0 | 0x400000);
  if (bufferCount == 0) {
    bufferDataPtr = (int *)(emitter + 0x28);
    bufferCount = *(int *)(emitter + 0x2c);
    capacity = *(uint *)(emitter + 0x30);
    if (capacity < bufferCount + 5U) {
      if (capacity == 0) {
        capacity = 0x10;
      }
      else {
        capacity = capacity << 1;
      }
      for (; capacity < bufferCount + 5U; capacity = capacity << 1) {
      }
      if (*bufferDataPtr == 0) {
        bufferCount = _malloc(capacity << 2);
      }
      else {
        bufferCount = _realloc(*bufferDataPtr,capacity << 2);
      }
      if (bufferCount == 0) {
        bufferCount = *(int *)(emitter + 0x24);
        if (bufferCount == 0) {
          bufferCount = 1;
          *(undefined4 *)(emitter + 0x24) = 1;
        }
        sVar10 = (short)*(undefined4 *)(emitter + 0x20);
        goto LAB_00043670;
      }
      *bufferDataPtr = bufferCount;
      *(uint *)(emitter + 0x30) = capacity;
      bufferCount = *(int *)(emitter + 0x2c);
    }
    *(int *)(emitter + 0x2c) = bufferCount + 5;
    tokenWritePtr = (undefined4 *)(bufferCount * 4 + *bufferDataPtr);
    *tokenWritePtr = entryHeader;
    tokenWritePtr[1] = ilInstADst;
    tokenWritePtr[2] = ilInstADstMask;
    tokenWritePtr[3] = ilInstASrc0;
    tokenWritePtr[4] = apuStack_40[0];
    sVar10 = (short)*(undefined4 *)(emitter + 0x20);
    bufferCount = *(int *)(emitter + 0x24);
  }
LAB_00043670:
  ilInstADst = CONCAT22(4,sVar10 + 2);
  ilInstASrc2 = CONCAT22(4,sVar10 + 2);
  ilInstASrc1 = (undefined *)CONCAT22(4,sVar10);
  entryHeader = CONCAT22((*(unsigned short *)((unsigned char *)&(entryHeader) + 0)),0x40);
  ilInstADst = ilInstADst | 0x400000;
  ilInstADstMask = 0x55;
  apuStack_40[1] = ((unsigned char *)0x00003210);
  apuStack_40[2] = ((unsigned char *)0x00003210);
  ilInstASrc0 = *(undefined **)(instr + 0x14);
  apuStack_40[0] = *(undefined **)(instr + 0x20);
  ilInstASrc2 = ilInstASrc2 | 0x400000;
  ilInstASrc1 = (undefined *)((uint)ilInstASrc1 | 0x400000);
  if (bufferCount == 0) {
    bufferDataPtr = (int *)(emitter + 0x28);
    bufferCount = *(int *)(emitter + 0x2c);
    capacity = *(uint *)(emitter + 0x30);
    if (capacity < bufferCount + 9U) {
      if (capacity == 0) {
        capacity = 0x10;
      }
      else {
        capacity = capacity << 1;
      }
      for (; capacity < bufferCount + 9U; capacity = capacity << 1) {
      }
      if (*bufferDataPtr == 0) {
        bufferCount = _malloc(capacity << 2);
      }
      else {
        bufferCount = _realloc(*bufferDataPtr,capacity << 2);
      }
      if (bufferCount == 0) {
        bufferCount = *(int *)(emitter + 0x24);
        if (bufferCount == 0) {
          bufferCount = 1;
          *(undefined4 *)(emitter + 0x24) = 1;
        }
        sVar10 = (short)*(undefined4 *)(emitter + 0x20);
        goto LAB_00043870;
      }
      *bufferDataPtr = bufferCount;
      *(uint *)(emitter + 0x30) = capacity;
      bufferCount = *(int *)(emitter + 0x2c);
    }
    recordPtr2 = (undefined **)&ilInstASrc0;
    *(int *)(emitter + 0x2c) = bufferCount + 9;
    tokenWritePtr = (undefined4 *)(bufferCount * 4 + *bufferDataPtr);
    *tokenWritePtr = entryHeader;
    tokenWritePtr[1] = ilInstADst;
    tokenWritePtr[2] = ilInstADstMask;
    do {
      tokenWritePtr[3] = *recordPtr2;
      recordWordNext2 = recordPtr2 + 3;
      recordPtr2 = recordPtr2 + 1;
      tokenWritePtr[4] = *recordWordNext2;
      tokenWritePtr = tokenWritePtr + 2;
    } while (apuStack_40 != recordPtr2);
    sVar10 = (short)*(undefined4 *)(emitter + 0x20);
    bufferCount = *(int *)(emitter + 0x24);
  }
LAB_00043870:
  ilInstADst = CONCAT22(4,sVar10 + 2);
  ilInstASrc0 = (undefined *)CONCAT22(4,sVar10 + 2);
  entryHeader = CONCAT22((*(unsigned short *)((unsigned char *)&(entryHeader) + 0)),0x49);
  apuStack_40[0] = ((unsigned char *)0x00003210);
  ilInstADstMask = 0x55;
  ilInstADst = ilInstADst | 0x400000;
  ilInstASrc1 = (undefined *)*(undefined4 *)(instr + 0x10);
  apuStack_40[1] = (undefined *)*(undefined4 *)(instr + 0x1c);
  ilInstASrc0 = (undefined *)((uint)ilInstASrc0 | 0x400000);
  if (bufferCount == 0) {
    bufferDataPtr = (int *)(emitter + 0x28);
    bufferCount = *(int *)(emitter + 0x2c);
    capacity = *(uint *)(emitter + 0x30);
    if (capacity < bufferCount + 7U) {
      if (capacity == 0) {
        capacity = 0x10;
      }
      else {
        capacity = capacity << 1;
      }
      for (; capacity < bufferCount + 7U; capacity = capacity << 1) {
      }
      if (*bufferDataPtr == 0) {
        bufferCount = _malloc(capacity << 2);
      }
      else {
        bufferCount = _realloc(*bufferDataPtr,capacity << 2);
      }
      if (bufferCount == 0) {
        bufferCount = *(int *)(emitter + 0x24);
        if (bufferCount == 0) {
          bufferCount = 1;
          *(undefined4 *)(emitter + 0x24) = 1;
        }
        sVar10 = (short)*(undefined4 *)(emitter + 0x20);
        goto LAB_00043a10;
      }
      *bufferDataPtr = bufferCount;
      *(uint *)(emitter + 0x30) = capacity;
      bufferCount = *(int *)(emitter + 0x2c);
    }
    recordPtr = &ilInstASrc0;
    *(int *)(emitter + 0x2c) = bufferCount + 7;
    tokenWritePtr = (undefined4 *)(bufferCount * 4 + *bufferDataPtr);
    *tokenWritePtr = entryHeader;
    tokenWritePtr[1] = ilInstADst;
    tokenWritePtr[2] = ilInstADstMask;
    do {
      tokenWritePtr[3] = *recordPtr;
      recordWordNext = recordPtr + 3;
      recordPtr = recordPtr + 1;
      tokenWritePtr[4] = *recordWordNext;
      tokenWritePtr = tokenWritePtr + 2;
    } while (recordPtr != &ilInstASrc2);
    sVar10 = (short)*(undefined4 *)(emitter + 0x20);
    bufferCount = *(int *)(emitter + 0x24);
  }
LAB_00043a10:
  ilInstADst = CONCAT22(4,sVar10 + 2);
  ilInstASrc2 = CONCAT22(4,sVar10 + 2);
  entryHeader = CONCAT22((*(unsigned short *)((unsigned char *)&(entryHeader) + 0)),0x40);
  ilInstADstMask = 0x55;
  ilInstADst = ilInstADst | 0x400000;
  apuStack_40[2] = (undefined *)0xba98;
  ilInstASrc0 = *(undefined **)(instr + 0x14);
  apuStack_40[0] = *(undefined **)(instr + 0x20);
  ilInstASrc1 = (undefined *)*(undefined4 *)(instr + 0xc);
  apuStack_40[1] = (undefined *)*(undefined4 *)(instr + 0x18);
  ilInstASrc2 = ilInstASrc2 | 0x400000;
  if (bufferCount == 0) {
    bufferDataPtr = (int *)(emitter + 0x28);
    bufferCount = *(int *)(emitter + 0x2c);
    capacity = *(uint *)(emitter + 0x30);
    if (capacity < bufferCount + 9U) {
      if (capacity == 0) {
        capacity = 0x10;
      }
      else {
        capacity = capacity << 1;
      }
      for (; capacity < bufferCount + 9U; capacity = capacity << 1) {
      }
      if (*bufferDataPtr == 0) {
        bufferCount = _malloc(capacity << 2);
      }
      else {
        bufferCount = _realloc(*bufferDataPtr,capacity << 2);
      }
      if (bufferCount == 0) {
        bufferCount = *(int *)(emitter + 0x24);
        if (bufferCount == 0) {
          bufferCount = 1;
          *(undefined4 *)(emitter + 0x24) = 1;
        }
        sVar10 = (short)*(undefined4 *)(emitter + 0x20);
        goto LAB_00043be0;
      }
      *bufferDataPtr = bufferCount;
      *(uint *)(emitter + 0x30) = capacity;
      bufferCount = *(int *)(emitter + 0x2c);
    }
    recordPtr2 = (undefined **)&ilInstASrc0;
    *(int *)(emitter + 0x2c) = bufferCount + 9;
    tokenWritePtr = (undefined4 *)(bufferCount * 4 + *bufferDataPtr);
    *tokenWritePtr = entryHeader;
    tokenWritePtr[1] = ilInstADst;
    tokenWritePtr[2] = ilInstADstMask;
    do {
      tokenWritePtr[3] = *recordPtr2;
      recordWordNext2 = recordPtr2 + 3;
      recordPtr2 = recordPtr2 + 1;
      tokenWritePtr[4] = *recordWordNext2;
      tokenWritePtr = tokenWritePtr + 2;
    } while (apuStack_40 != recordPtr2);
    sVar10 = (short)*(undefined4 *)(emitter + 0x20);
    bufferCount = *(int *)(emitter + 0x24);
  }
LAB_00043be0:
  entryHeader = CONCAT22((*(unsigned short *)((unsigned char *)&(entryHeader) + 0)),0xd);
  ilInstASrc0 = (undefined *)CONCAT22(4,sVar10 + 1);
  ilInstASrc2 = CONCAT22(4,sVar10 + 2);
  entryHeader = entryHeader & 0xc000ffff | 0x50000;
  ilInstADstMask = *(uint *)(instr + 8);
  ilInstADst = *(uint *)(instr + 4);
  apuStack_40[1] = ((unsigned char *)0x00004444);
  apuStack_40[0] = ((unsigned char *)0x00003210);
  apuStack_40[2] = ((unsigned char *)0x00003210);
  ilInstASrc0 = (undefined *)((uint)ilInstASrc0 | 0x400000);
  ilInstASrc1 = (undefined *)0x440000;
  ilInstASrc2 = ilInstASrc2 | 0x400000;
  if (bufferCount == 0) {
    bufferDataPtr = (int *)(emitter + 0x28);
    bufferCount = *(int *)(emitter + 0x2c);
    capacity = *(uint *)(emitter + 0x30);
    if (capacity < bufferCount + 9U) {
      if (capacity == 0) {
        capacity = 0x10;
      }
      else {
        capacity = capacity << 1;
      }
      for (; capacity < bufferCount + 9U; capacity = capacity << 1) {
      }
      if (*bufferDataPtr == 0) {
        bufferCount = _malloc(capacity << 2);
      }
      else {
        bufferCount = _realloc(*bufferDataPtr,capacity << 2);
      }
      if (bufferCount == 0) {
        if (*(int *)(emitter + 0x24) != 0) {
          return *(int *)(emitter + 0x24);
        }
        *(undefined4 *)(emitter + 0x24) = 1;
        return 1;
      }
      *bufferDataPtr = bufferCount;
      *(uint *)(emitter + 0x30) = capacity;
      bufferCount = *(int *)(emitter + 0x2c);
    }
    recordPtr2 = (undefined **)&ilInstASrc0;
    *(int *)(emitter + 0x2c) = bufferCount + 9;
    tokenWritePtr2 = (uint *)(bufferCount * 4 + *bufferDataPtr);
    *tokenWritePtr2 = entryHeader;
    tokenWritePtr2[1] = ilInstADst;
    tokenWritePtr2[2] = ilInstADstMask;
    do {
      tokenWritePtr2[3] = (uint)*recordPtr2;
      recordWordNext2 = recordPtr2 + 3;
      recordPtr2 = recordPtr2 + 1;
      tokenWritePtr2[4] = (uint)*recordWordNext2;
      tokenWritePtr2 = tokenWritePtr2 + 2;
    } while (apuStack_40 != recordPtr2);
    bufferCount = *(int *)(emitter + 0x24);
  }
  return bufferCount;
}

/* fragmentTranslateFfw @ 0x43df0 (352 bytes) */
int fragmentTranslateFfw(translator, slot, ilInstr)
  int translator;
  undefined4 slot;
  undefined4 *ilInstr;
{
  int tokenCount;
  int allocation;
  undefined4 *puVar1;
  bool bVar2;
  uint tokenCapacity;
  int translatorError;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 *tokenWritePtr;
  int *tokenDataPtrAddr;
  
  uVar6 = ilInstr[5];
  uVar7 = ilInstr[8];
  ilInstr[5] = ilInstr[3];
  ilInstr[8] = ilInstr[6];
  ilInstr[3] = uVar6;
  ilInstr[6] = uVar7;
  translatorError = *(int *)(translator + 0x24);
  if (translatorError == 0) {
    tokenDataPtrAddr = (int *)(translator + 0x28);
    tokenCount = *(int *)(translator + 0x2c);
    tokenCapacity = *(uint *)(translator + 0x30);
    if (tokenCapacity < tokenCount + 9U) {
      if (tokenCapacity == 0) {
        tokenCapacity = 0x10;
      }
      else {
        tokenCapacity = tokenCapacity << 1;
      }
      for (; tokenCapacity < tokenCount + 9U; tokenCapacity = tokenCapacity << 1) {
      }
      if (*tokenDataPtrAddr == 0) {
        allocation = _malloc(tokenCapacity << 2);
      }
      else {
        allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
      }
      if (allocation == 0) {
        if (*(int *)(translator + 0x24) != 0) {
          return *(int *)(translator + 0x24);
        }
        *(undefined4 *)(translator + 0x24) = 1;
        return 1;
      }
      *tokenDataPtrAddr = allocation;
      *(uint *)(translator + 0x30) = tokenCapacity;
      tokenCount = *(int *)(translator + 0x2c);
    }
    iVar5 = 0;
    *(int *)(translator + 0x2c) = tokenCount + 9;
    tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
    *tokenWritePtr = *ilInstr;
    tokenWritePtr[1] = ilInstr[1];
    tokenWritePtr[2] = ilInstr[2];
    do {
      bVar2 = iVar5 != 2;
      iVar5 = iVar5 + 1;
      tokenWritePtr[3] = ilInstr[3];
      puVar1 = ilInstr + 6;
      ilInstr = ilInstr + 1;
      tokenWritePtr[4] = *puVar1;
      tokenWritePtr = tokenWritePtr + 2;
    } while (bVar2);
    translatorError = *(int *)(translator + 0x24);
  }
  return translatorError;
}

/* fragmentTranslateDst @ 0x43f60 (996 bytes) */
int fragmentTranslateDst(translator, slot, ilInstr)
  int translator;
  undefined4 slot;
  undefined4 *ilInstr;
{
  int allocation;
  undefined4 *puVar1;
  bool bVar2;
  uint tokenCapacity;
  int tokenCount;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined4 *tokenWritePtr;
  undefined4 uVar9;
  undefined4 uVar10;
  int *tokenDataPtrAddr;
  
  if ((*(uint *)(translator + 0x14) & 0x20000000) == 0) {
    *(undefined2 *)((int)ilInstr + 2) = 0x24;
    if (*(int *)(translator + 0x24) != 0) {
      return *(int *)(translator + 0x24);
    }
    tokenDataPtrAddr = (int *)(translator + 0x28);
    tokenCount = *(int *)(translator + 0x2c);
    tokenCapacity = *(uint *)(translator + 0x30);
    if (tokenCount + 7U <= tokenCapacity) {
LAB_000442bc:
      iVar5 = 0;
      *(int *)(translator + 0x2c) = tokenCount + 7;
      tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
      *tokenWritePtr = *ilInstr;
      tokenWritePtr[1] = ilInstr[1];
      tokenWritePtr[2] = ilInstr[2];
      do {
        bVar2 = iVar5 != 1;
        iVar5 = iVar5 + 1;
        tokenWritePtr[3] = ilInstr[3];
        puVar6 = ilInstr + 6;
        ilInstr = ilInstr + 1;
        tokenWritePtr[4] = *puVar6;
        tokenWritePtr = tokenWritePtr + 2;
      } while (bVar2);
      return *(int *)(translator + 0x24);
    }
    if (tokenCapacity == 0) {
      tokenCapacity = 0x10;
    }
    else {
      tokenCapacity = tokenCapacity << 1;
    }
    for (; tokenCapacity < tokenCount + 7U; tokenCapacity = tokenCapacity << 1) {
    }
    if (*tokenDataPtrAddr == 0) {
      allocation = _malloc(tokenCapacity << 2);
    }
    else {
      allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
    }
    if (allocation != 0) {
      *tokenDataPtrAddr = allocation;
      *(uint *)(translator + 0x30) = tokenCapacity;
      tokenCount = *(int *)(translator + 0x2c);
      goto LAB_000442bc;
    }
    goto LAB_0004432c;
  }
  uVar7 = *(undefined4 *)(translator + 0x20);
  uVar10 = ilInstr[1];
  uVar9 = ilInstr[2];
  ilInstr[1] = 0x40000;
  *(short *)((int)ilInstr + 6) = (short)uVar7;
  ilInstr[2] = 0x55;
  ilInstr[1] = ilInstr[1] | 0x400000;
  if (*(int *)(translator + 0x24) == 0) {
    tokenDataPtrAddr = (int *)(translator + 0x28);
    tokenCount = *(int *)(translator + 0x2c);
    tokenCapacity = *(uint *)(translator + 0x30);
    if (tokenCapacity < tokenCount + 7U) {
      if (tokenCapacity == 0) {
        tokenCapacity = 0x10;
      }
      else {
        tokenCapacity = tokenCapacity << 1;
      }
      for (; tokenCapacity < tokenCount + 7U; tokenCapacity = tokenCapacity << 1) {
      }
      if (*tokenDataPtrAddr == 0) {
        allocation = _malloc(tokenCapacity << 2);
      }
      else {
        allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
      }
      if (allocation == 0) {
        if (*(int *)(translator + 0x24) == 0) {
          *(undefined4 *)(translator + 0x24) = 1;
        }
        goto LAB_000440e0;
      }
      *tokenDataPtrAddr = allocation;
      *(uint *)(translator + 0x30) = tokenCapacity;
      tokenCount = *(int *)(translator + 0x2c);
    }
    iVar5 = 0;
    *(int *)(translator + 0x2c) = tokenCount + 7;
    tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
    *tokenWritePtr = *ilInstr;
    tokenWritePtr[1] = ilInstr[1];
    tokenWritePtr[2] = ilInstr[2];
    puVar6 = ilInstr;
    do {
      bVar2 = iVar5 != 1;
      iVar5 = iVar5 + 1;
      tokenWritePtr[3] = puVar6[3];
      puVar1 = puVar6 + 6;
      puVar6 = puVar6 + 1;
      tokenWritePtr[4] = *puVar1;
      tokenWritePtr = tokenWritePtr + 2;
    } while (bVar2);
  }
LAB_000440e0:
  ilInstr[1] = uVar10;
  ilInstr[2] = uVar9;
  *ilInstr = 0;
  *(undefined2 *)((int)ilInstr + 2) = 0x38;
  uVar7 = *(undefined4 *)(translator + 0x20);
  ilInstr[3] = 0x40000;
  *(short *)((int)ilInstr + 0xe) = (short)uVar7;
  ilInstr[6] = ((unsigned char *)0x00003210);
  ilInstr[3] = ilInstr[3] | 0x400000;
  if (*(int *)(translator + 0x24) != 0) {
    return *(int *)(translator + 0x24);
  }
  tokenDataPtrAddr = (int *)(translator + 0x28);
  tokenCount = *(int *)(translator + 0x2c);
  tokenCapacity = *(uint *)(translator + 0x30);
  if (tokenCapacity < tokenCount + 5U) {
    if (tokenCapacity == 0) {
      tokenCapacity = 0x10;
    }
    else {
      tokenCapacity = tokenCapacity << 1;
    }
    for (; tokenCapacity < tokenCount + 5U; tokenCapacity = tokenCapacity << 1) {
    }
    if (*tokenDataPtrAddr == 0) {
      allocation = _malloc(tokenCapacity << 2);
    }
    else {
      allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
    }
    if (allocation == 0) {
LAB_0004432c:
      if (*(int *)(translator + 0x24) == 0) {
        *(undefined4 *)(translator + 0x24) = 1;
        return 1;
      }
      return *(int *)(translator + 0x24);
    }
    *tokenDataPtrAddr = allocation;
    *(uint *)(translator + 0x30) = tokenCapacity;
    tokenCount = *(int *)(translator + 0x2c);
  }
  *(int *)(translator + 0x2c) = tokenCount + 5;
  tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
  *tokenWritePtr = *ilInstr;
  tokenWritePtr[1] = ilInstr[1];
  tokenWritePtr[2] = ilInstr[2];
  tokenWritePtr[3] = ilInstr[3];
  tokenWritePtr[4] = ilInstr[6];
  return *(int *)(translator + 0x24);
}

/* fragmentTranslateIf @ 0x44360 (388 bytes) */
int fragmentTranslateIf(translator, slot, ilInstr)
  int translator;
  undefined4 slot;
  undefined4 *ilInstr;
{
  int translatorError;
  int tokenCount;
  int allocation;
  undefined4 *puVar1;
  bool bVar2;
  uint tokenCapacity;
  int iVar4;
  undefined4 *tokenWritePtr;
  int *tokenDataPtrAddr;
  
  ilInstr[4] = 0x40000;
  *(undefined2 *)((int)ilInstr + 0x12) = 0;
  ilInstr[7] = ((unsigned char *)0x00004444);
  ilInstr[4] = ilInstr[4] | 0x400000;
  if (*(int *)(translator + 0x24) != 0) {
    return *(int *)(translator + 0x24);
  }
  tokenDataPtrAddr = (int *)(translator + 0x28);
  tokenCount = *(int *)(translator + 0x2c);
  tokenCapacity = *(uint *)(translator + 0x30);
  if (tokenCapacity < tokenCount + 5U) {
    if (tokenCapacity == 0) {
      tokenCapacity = 0x10;
    }
    else {
      tokenCapacity = tokenCapacity << 1;
    }
    for (; tokenCapacity < tokenCount + 5U; tokenCapacity = tokenCapacity << 1) {
    }
    if (*tokenDataPtrAddr == 0) {
      allocation = _malloc(tokenCapacity << 2);
    }
    else {
      allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
    }
    if (allocation == 0) {
      translatorError = *(int *)(translator + 0x24);
      if (translatorError == 0) {
        translatorError = 1;
        *(undefined4 *)(translator + 0x24) = 1;
      }
      tokenWritePtr = (undefined4 *)0x0;
      if (translatorError != 0) {
        return translatorError;
      }
      goto LAB_00044460;
    }
    *tokenDataPtrAddr = allocation;
    *(uint *)(translator + 0x30) = tokenCapacity;
    tokenCount = *(int *)(translator + 0x2c);
  }
  *(int *)(translator + 0x2c) = tokenCount + 5;
  tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
LAB_00044460:
  iVar4 = 0;
  *tokenWritePtr = *ilInstr;
  do {
    bVar2 = iVar4 != 1;
    iVar4 = iVar4 + 1;
    tokenWritePtr[1] = ilInstr[3];
    puVar1 = ilInstr + 6;
    ilInstr = ilInstr + 1;
    tokenWritePtr[2] = *puVar1;
    tokenWritePtr = tokenWritePtr + 2;
  } while (bVar2);
  return 0;
}

/* fragmentTranslateRfl @ 0x44500 (1432 bytes) */
int fragmentTranslateRfl(translator, slot, ilInstr)
  int translator;
  undefined4 slot;
  int ilInstr;
{
  int tokenCount;
  int allocation;
  undefined4 *recordWordNext;
  uint tokenCapacity;
  int translatorError;
  undefined2 uVar4;
  undefined4 *recordPtr;
  undefined4 *tokenWritePtr;
  int *tokenDataPtrAddr;
  undefined4 ilInstAOpcode;
  undefined4 ilInstADst;
  undefined4 ilInstADstMask;
  undefined4 ilInstASrc0;
  undefined4 ilInstASrc1;
  undefined4 ilInstASrc2;
  undefined *ilInstASwz0;
  undefined *ilInstASwz1;
  
  _memset(&ilInstAOpcode,0,0x24);
  translatorError = *(int *)(translator + 0x24);
  uVar4 = (undefined2)*(undefined4 *)(translator + 0x20);
  ilInstADst = CONCAT22(4,uVar4);
  ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),0x23);
  ilInstADstMask = 0x55;
  ilInstASrc0 = *(undefined4 *)(ilInstr + 0xc);
  ilInstASwz0 = (undefined *)*(undefined4 *)(ilInstr + 0x18);
  ilInstASrc1 = *(undefined4 *)(ilInstr + 0x10);
  ilInstASwz1 = (undefined *)*(undefined4 *)(ilInstr + 0x1c);
  ilInstADst = ilInstADst | 0x400000;
  if (translatorError == 0) {
    tokenDataPtrAddr = (int *)(translator + 0x28);
    tokenCount = *(int *)(translator + 0x2c);
    tokenCapacity = *(uint *)(translator + 0x30);
    if (tokenCapacity < tokenCount + 7U) {
      if (tokenCapacity == 0) {
        tokenCapacity = 0x10;
      }
      else {
        tokenCapacity = tokenCapacity << 1;
      }
      for (; tokenCapacity < tokenCount + 7U; tokenCapacity = tokenCapacity << 1) {
      }
      if (*tokenDataPtrAddr == 0) {
        allocation = _malloc(tokenCapacity << 2);
      }
      else {
        allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
      }
      if (allocation == 0) {
        translatorError = *(int *)(translator + 0x24);
        if (translatorError == 0) {
          translatorError = 1;
          *(undefined4 *)(translator + 0x24) = 1;
        }
        uVar4 = (undefined2)*(undefined4 *)(translator + 0x20);
        goto LAB_000446a0;
      }
      *tokenDataPtrAddr = allocation;
      *(uint *)(translator + 0x30) = tokenCapacity;
      tokenCount = *(int *)(translator + 0x2c);
    }
    recordPtr = &ilInstASrc0;
    *(int *)(translator + 0x2c) = tokenCount + 7;
    tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
    *tokenWritePtr = ilInstAOpcode;
    tokenWritePtr[1] = ilInstADst;
    tokenWritePtr[2] = ilInstADstMask;
    do {
      tokenWritePtr[3] = *recordPtr;
      recordWordNext = recordPtr + 3;
      recordPtr = recordPtr + 1;
      tokenWritePtr[4] = *recordWordNext;
      tokenWritePtr = tokenWritePtr + 2;
    } while (&ilInstASrc2 != recordPtr);
    uVar4 = (undefined2)*(undefined4 *)(translator + 0x20);
    translatorError = *(int *)(translator + 0x24);
  }
LAB_000446a0:
  ilInstASrc0 = CONCAT22(4,uVar4);
  ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),0x49);
  ilInstASwz0 = ((unsigned char *)0x00003210);
  ilInstASrc0 = ilInstASrc0 | 0x400000;
  if (translatorError == 0) {
    tokenDataPtrAddr = (int *)(translator + 0x28);
    tokenCount = *(int *)(translator + 0x2c);
    tokenCapacity = *(uint *)(translator + 0x30);
    if (tokenCapacity < tokenCount + 7U) {
      if (tokenCapacity == 0) {
        tokenCapacity = 0x10;
      }
      else {
        tokenCapacity = tokenCapacity << 1;
      }
      for (; tokenCapacity < tokenCount + 7U; tokenCapacity = tokenCapacity << 1) {
      }
      if (*tokenDataPtrAddr == 0) {
        allocation = _malloc(tokenCapacity << 2);
      }
      else {
        allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
      }
      if (allocation == 0) {
        translatorError = *(int *)(translator + 0x24);
        if (translatorError == 0) {
          translatorError = 1;
          *(undefined4 *)(translator + 0x24) = 1;
        }
        uVar4 = (undefined2)*(undefined4 *)(translator + 0x20);
        goto LAB_00044810;
      }
      *tokenDataPtrAddr = allocation;
      *(uint *)(translator + 0x30) = tokenCapacity;
      tokenCount = *(int *)(translator + 0x2c);
    }
    recordPtr = &ilInstASrc0;
    *(int *)(translator + 0x2c) = tokenCount + 7;
    tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
    *tokenWritePtr = ilInstAOpcode;
    tokenWritePtr[1] = ilInstADst;
    tokenWritePtr[2] = ilInstADstMask;
    do {
      tokenWritePtr[3] = *recordPtr;
      recordWordNext = recordPtr + 3;
      recordPtr = recordPtr + 1;
      tokenWritePtr[4] = *recordWordNext;
      tokenWritePtr = tokenWritePtr + 2;
    } while (&ilInstASrc2 != recordPtr);
    uVar4 = (undefined2)*(undefined4 *)(translator + 0x20);
    translatorError = *(int *)(translator + 0x24);
  }
LAB_00044810:
  ilInstASrc1 = CONCAT22(4,uVar4);
  ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),3);
  ilInstASwz1 = ((unsigned char *)0x00003210);
  ilInstASrc1 = ilInstASrc1 | 0x400000;
  if (translatorError == 0) {
    tokenDataPtrAddr = (int *)(translator + 0x28);
    tokenCount = *(int *)(translator + 0x2c);
    tokenCapacity = *(uint *)(translator + 0x30);
    if (tokenCapacity < tokenCount + 7U) {
      if (tokenCapacity == 0) {
        tokenCapacity = 0x10;
      }
      else {
        tokenCapacity = tokenCapacity << 1;
      }
      for (; tokenCapacity < tokenCount + 7U; tokenCapacity = tokenCapacity << 1) {
      }
      if (*tokenDataPtrAddr == 0) {
        allocation = _malloc(tokenCapacity << 2);
      }
      else {
        allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
      }
      if (allocation == 0) {
        translatorError = *(int *)(translator + 0x24);
        if (translatorError == 0) {
          translatorError = 1;
          *(undefined4 *)(translator + 0x24) = 1;
        }
        goto LAB_00044970;
      }
      *tokenDataPtrAddr = allocation;
      *(uint *)(translator + 0x30) = tokenCapacity;
      tokenCount = *(int *)(translator + 0x2c);
    }
    recordPtr = &ilInstASrc0;
    *(int *)(translator + 0x2c) = tokenCount + 7;
    tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
    *tokenWritePtr = ilInstAOpcode;
    tokenWritePtr[1] = ilInstADst;
    tokenWritePtr[2] = ilInstADstMask;
    do {
      tokenWritePtr[3] = *recordPtr;
      recordWordNext = recordPtr + 3;
      recordPtr = recordPtr + 1;
      tokenWritePtr[4] = *recordWordNext;
      tokenWritePtr = tokenWritePtr + 2;
    } while (recordPtr != &ilInstASrc2);
    translatorError = *(int *)(translator + 0x24);
  }
LAB_00044970:
  ilInstADst = *(undefined4 *)(ilInstr + 4);
  ilInstADstMask = *(undefined4 *)(ilInstr + 8);
  ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),0x5b);
  ilInstASwz0 = (undefined *)*(undefined4 *)(ilInstr + 0x18);
  ilInstASrc0 = *(undefined4 *)(ilInstr + 0xc);
  if (translatorError == 0) {
    tokenDataPtrAddr = (int *)(translator + 0x28);
    tokenCount = *(int *)(translator + 0x2c);
    tokenCapacity = *(uint *)(translator + 0x30);
    if (tokenCapacity < tokenCount + 7U) {
      if (tokenCapacity == 0) {
        tokenCapacity = 0x10;
      }
      else {
        tokenCapacity = tokenCapacity << 1;
      }
      for (; tokenCapacity < tokenCount + 7U; tokenCapacity = tokenCapacity << 1) {
      }
      if (*tokenDataPtrAddr == 0) {
        allocation = _malloc(tokenCapacity << 2);
      }
      else {
        allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
      }
      if (allocation == 0) {
        if (*(int *)(translator + 0x24) != 0) {
          return *(int *)(translator + 0x24);
        }
        *(undefined4 *)(translator + 0x24) = 1;
        return 1;
      }
      *tokenDataPtrAddr = allocation;
      *(uint *)(translator + 0x30) = tokenCapacity;
      tokenCount = *(int *)(translator + 0x2c);
    }
    recordPtr = &ilInstASrc0;
    *(int *)(translator + 0x2c) = tokenCount + 7;
    tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
    *tokenWritePtr = ilInstAOpcode;
    tokenWritePtr[1] = ilInstADst;
    tokenWritePtr[2] = ilInstADstMask;
    do {
      tokenWritePtr[3] = *recordPtr;
      recordWordNext = recordPtr + 3;
      recordPtr = recordPtr + 1;
      tokenWritePtr[4] = *recordWordNext;
      tokenWritePtr = tokenWritePtr + 2;
    } while (recordPtr != &ilInstASrc2);
    translatorError = *(int *)(translator + 0x24);
  }
  return translatorError;
}

/* fragmentTranslateWhile @ 0x44ac0 (440 bytes) */
int fragmentTranslateWhile(translator, slot, ilInstr)
  int translator;
  undefined4 slot;
  undefined4 *ilInstr;
{
  uint tokenCapacity;
  int translatorError;
  int allocation;
  uint uVar1;
  int tokenCount;
  undefined4 *tokenWritePtr;
  dword *pdVar4;
  dword *pdVar5;
  int *tokenDataPtrAddr;
  uint auStack_38 [9];
  
  uVar1 = *(uint *)(translator + 0x14);
  if ((uVar1 & 0x100000) == 0) {
    auStack_38[0] = uVar1 & 0x100000;
    ((int (*)())fpilEmitScalarConstant)(translator,0xff,auStack_38);
    uVar1 = (auStack_38[0] & 0x1f) << 0xf | *(uint *)(translator + 0x14) & 0xfff07fff | 0x100000;
    *(uint *)(translator + 0x14) = uVar1;
  }
  ilInstr[3] = 0x40000;
  *(ushort *)((int)ilInstr + 0xe) = (ushort)(uVar1 >> 0xf) & 0x1f;
  ilInstr[6] = ((unsigned char *)0x00003210);
  ilInstr[3] = ilInstr[3] & 0xffc0ffff | 0x420000;
  if (*(int *)(translator + 0x24) != 0) {
    return *(int *)(translator + 0x24);
  }
  tokenDataPtrAddr = (int *)(translator + 0x28);
  tokenCount = *(int *)(translator + 0x2c);
  tokenCapacity = *(uint *)(translator + 0x30);
  if (tokenCapacity < tokenCount + 3U) {
    if (tokenCapacity == 0) {
      tokenCapacity = 0x10;
    }
    else {
      tokenCapacity = tokenCapacity << 1;
    }
    for (; tokenCapacity < tokenCount + 3U; tokenCapacity = tokenCapacity << 1) {
    }
    if (*tokenDataPtrAddr == 0) {
      allocation = _malloc(tokenCapacity << 2);
    }
    else {
      allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
    }
    if (allocation == 0) {
      translatorError = *(int *)(translator + 0x24);
      if (translatorError == 0) {
        translatorError = 1;
        *(undefined4 *)(translator + 0x24) = 1;
      }
      if (translatorError != 0) {
        return translatorError;
      }
      tokenWritePtr = (undefined4 *)0x0;
      pdVar5 = ((unsigned char *)0x4);
      pdVar4 = ((unsigned char *)0x8);
      goto LAB_00044c08;
    }
    *tokenDataPtrAddr = allocation;
    *(uint *)(translator + 0x30) = tokenCapacity;
    tokenCount = *(int *)(translator + 0x2c);
  }
  *(int *)(translator + 0x2c) = tokenCount + 3;
  tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
  pdVar5 = tokenWritePtr + 1;
  pdVar4 = tokenWritePtr + 2;
LAB_00044c08:
  *tokenWritePtr = *ilInstr;
  *pdVar5 = ilInstr[3];
  *pdVar4 = ilInstr[6];
  return 0;
}

/* fragmentTranslateDsl @ 0x44c90 (2856 bytes) */
int fragmentTranslateDsl(emitter, param_2)
  int *emitter;
  int param_2;
{
  undefined4 *tokenWritePtr;
  undefined **recordPtr3;
  undefined **recordPtr2;
  undefined **recordWordNext4;
  undefined4 *recordWordNext3;
  undefined4 *recordWordNext;
  undefined **recordWordNext2;
  int bufferCount;
  uint capacity;
  undefined4 *recordPtr;
  undefined4 *puVar6;
  undefined **ppuVar7;
  undefined **recordWordNext5;
  undefined4 *tokenWritePtr2;
  uint *tokenWritePtr3;
  int iVar11;
  int *bufferDataPtr;
  undefined1 auStack_b8 [2];
  ushort local_b6;
  undefined1 auStack_b4 [4];
  undefined *local_b0;
  undefined4 ilInstAOpcode;
  undefined4 ilInstADst;
  undefined4 ilInstADstMask;
  undefined4 ilInstASrc0;
  undefined4 ilInstASrc1;
  undefined4 ilInstASrc2;
  undefined *ilInstASwz0;
  undefined *ilInstASwz1;
  undefined4 ilInstBOpcode;
  undefined4 ilInstBDst;
  uint ilInstBDstMask;
  undefined4 ilInstBSrc0;
  undefined4 ilInstBSrc1;
  undefined4 ilInstBSrc2;
  undefined *local_70 [3];
  undefined4 ilInstCOpcode;
  undefined4 ilInstCDst;
  undefined4 ilInstCDstMask;
  undefined4 ilInstCSrc0;
  undefined1 auStack_54 [4];
  uint ilInstCSrc2;
  undefined *ilInstCSwz0;
  undefined1 auStack_48 [4];
  undefined *ilInstCSwz2;
  
  iVar11 = *emitter;
  recordPtr = &ilInstASrc0;
  bufferCount = *(int *)(iVar11 + 0x54);
  _memset(&ilInstAOpcode,0,0x24);
  iVar11 = iVar11 + bufferCount * 8 + param_2 * 8;
  _memset(&ilInstBOpcode,0,0x24);
  ilInstADst = CONCAT22(4,(short)emitter[8]);
  ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),0x5b);
  ilInstADstMask = 0x55;
  ilInstADst = ilInstADst | 0x400000;
  bufferCount = ((int (*)())fpilTranslateSource)(emitter,iVar11 + 0x18,recordPtr,&ilInstASwz0);
  if (bufferCount == 0) {
    ilInstASwz1 = ((unsigned char *)0x00005555U);
    ilInstASrc1 = 0x440000;
    if (emitter[9] != 0) {
      return emitter[9];
    }
    bufferDataPtr = emitter + 10;
    bufferCount = emitter[0xb];
    capacity = emitter[0xc];
    if (capacity < bufferCount + 7U) {
      if (capacity == 0) {
        capacity = 0x10;
      }
      else {
        capacity = capacity << 1;
      }
      for (; capacity < bufferCount + 7U; capacity = capacity << 1) {
      }
      if (*bufferDataPtr == 0) {
        bufferCount = _malloc(capacity << 2);
      }
      else {
        bufferCount = _realloc(*bufferDataPtr,capacity << 2);
      }
      if (bufferCount == 0) goto LAB_000457a8;
      *bufferDataPtr = bufferCount;
      emitter[0xc] = capacity;
      bufferCount = emitter[0xb];
    }
    emitter[0xb] = bufferCount + 7;
    tokenWritePtr2 = (undefined4 *)(bufferCount * 4 + *bufferDataPtr);
    *tokenWritePtr2 = ilInstAOpcode;
    tokenWritePtr2[1] = ilInstADst;
    tokenWritePtr2[2] = ilInstADstMask;
    puVar6 = recordPtr;
    do {
      tokenWritePtr2[3] = *puVar6;
      recordWordNext = puVar6 + 3;
      puVar6 = puVar6 + 1;
      tokenWritePtr2[4] = *recordWordNext;
      tokenWritePtr2 = tokenWritePtr2 + 2;
    } while (&ilInstASrc2 != puVar6);
    ilInstBOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstBOpcode) + 0)),0xd);
    ilInstBDst = CONCAT22(4,(short)emitter[8] + 1);
    ilInstBSrc0 = (undefined *)CONCAT22(4,(short)emitter[8]);
    ilInstBOpcode = ilInstBOpcode & 0xc000ffff | 0x20000;
    ilInstBDst = ilInstBDst | 0x400000;
    ilInstBDstMask = 0x55;
    local_70[0] = ((unsigned char *)0x00003210);
    local_70[1] = ((unsigned char *)0x00004454);
    local_70[2] = ((unsigned char *)0x00004445);
    ilInstBSrc0 = (undefined *)((uint)ilInstBSrc0 | 0x400000);
    ilInstBSrc1 = 0x440000;
    ilInstBSrc2 = 0x440000;
    if (emitter[9] != 0) {
      return emitter[9];
    }
    bufferCount = emitter[0xb];
    capacity = emitter[0xc];
    if (capacity < bufferCount + 9U) {
      if (capacity == 0) {
        capacity = 0x10;
      }
      else {
        capacity = capacity << 1;
      }
      for (; capacity < bufferCount + 9U; capacity = capacity << 1) {
      }
      if (*bufferDataPtr == 0) {
        bufferCount = _malloc(capacity << 2);
      }
      else {
        bufferCount = _realloc(*bufferDataPtr,capacity << 2);
      }
      if (bufferCount == 0) goto LAB_000457a8;
      *bufferDataPtr = bufferCount;
      emitter[0xc] = capacity;
      bufferCount = emitter[0xb];
    }
    recordPtr3 = (undefined **)&ilInstBSrc0;
    emitter[0xb] = bufferCount + 9;
    tokenWritePtr3 = (uint *)(bufferCount * 4 + *bufferDataPtr);
    *tokenWritePtr3 = ilInstBOpcode;
    tokenWritePtr3[1] = ilInstBDst;
    tokenWritePtr3[2] = ilInstBDstMask;
    ppuVar7 = recordPtr3;
    do {
      tokenWritePtr3[3] = (uint)*ppuVar7;
      recordWordNext2 = ppuVar7 + 3;
      ppuVar7 = ppuVar7 + 1;
      tokenWritePtr3[4] = (uint)*recordWordNext2;
      tokenWritePtr3 = tokenWritePtr3 + 2;
    } while (local_70 != ppuVar7);
    if (1 < (*(uint *)(iVar11 + 4) >> 0x1a & 3)) {
      ilInstASrc0 = CONCAT22(4,(short)emitter[8]);
      ilInstASwz0 = ((unsigned char *)0x00003210);
      ilInstASrc0 = ilInstASrc0 | 0x400000;
      if (emitter[9] != 0) {
        return emitter[9];
      }
      bufferCount = emitter[0xb];
      capacity = emitter[0xc];
      if (capacity < bufferCount + 7U) {
        if (capacity == 0) {
          capacity = 0x10;
        }
        else {
          capacity = capacity << 1;
        }
        for (; capacity < bufferCount + 7U; capacity = capacity << 1) {
        }
        if (*bufferDataPtr == 0) {
          bufferCount = _malloc(capacity << 2);
        }
        else {
          bufferCount = _realloc(*bufferDataPtr,capacity << 2);
        }
        if (bufferCount == 0) goto LAB_000457a8;
        *bufferDataPtr = bufferCount;
        emitter[0xc] = capacity;
        bufferCount = emitter[0xb];
      }
      emitter[0xb] = bufferCount + 7;
      tokenWritePtr2 = (undefined4 *)(bufferCount * 4 + *bufferDataPtr);
      *tokenWritePtr2 = ilInstAOpcode;
      tokenWritePtr2[1] = ilInstADst;
      tokenWritePtr2[2] = ilInstADstMask;
      puVar6 = recordPtr;
      do {
        tokenWritePtr2[3] = *puVar6;
        recordWordNext = puVar6 + 3;
        puVar6 = puVar6 + 1;
        tokenWritePtr2[4] = *recordWordNext;
        tokenWritePtr2 = tokenWritePtr2 + 2;
      } while (&ilInstASrc2 != puVar6);
      ilInstBSrc2 = CONCAT22(4,(short)emitter[8] + 1);
      local_70[1] = (undefined *)((uint)local_70[1] & 0xfffff88f | 0x540);
      local_70[2] = ((unsigned char *)0x00003210);
      ilInstBSrc2 = ilInstBSrc2 | 0x400000;
      if (emitter[9] != 0) {
        return emitter[9];
      }
      bufferCount = emitter[0xb];
      capacity = emitter[0xc];
      if (capacity < bufferCount + 9U) {
        if (capacity == 0) {
          capacity = 0x10;
        }
        else {
          capacity = capacity << 1;
        }
        for (; capacity < bufferCount + 9U; capacity = capacity << 1) {
        }
        if (*bufferDataPtr == 0) {
          bufferCount = _malloc(capacity << 2);
        }
        else {
          bufferCount = _realloc(*bufferDataPtr,capacity << 2);
        }
        if (bufferCount == 0) goto LAB_000457a8;
        *bufferDataPtr = bufferCount;
        emitter[0xc] = capacity;
        bufferCount = emitter[0xb];
      }
      emitter[0xb] = bufferCount + 9;
      tokenWritePtr3 = (uint *)(bufferCount * 4 + *bufferDataPtr);
      *tokenWritePtr3 = ilInstBOpcode;
      tokenWritePtr3[1] = ilInstBDst;
      tokenWritePtr3[2] = ilInstBDstMask;
      ppuVar7 = recordPtr3;
      do {
        tokenWritePtr3[3] = (uint)*ppuVar7;
        recordWordNext2 = ppuVar7 + 3;
        ppuVar7 = ppuVar7 + 1;
        tokenWritePtr3[4] = (uint)*recordWordNext2;
        tokenWritePtr3 = tokenWritePtr3 + 2;
      } while (local_70 != ppuVar7);
      if ((*(uint *)(iVar11 + 4) & 0xc000000) == 0xc000000) {
        if (emitter[9] != 0) {
          return emitter[9];
        }
        bufferCount = emitter[0xb];
        capacity = emitter[0xc];
        if (capacity < bufferCount + 7U) {
          if (capacity == 0) {
            capacity = 0x10;
          }
          else {
            capacity = capacity << 1;
          }
          for (; capacity < bufferCount + 7U; capacity = capacity << 1) {
          }
          if (*bufferDataPtr == 0) {
            bufferCount = _malloc(capacity << 2);
          }
          else {
            bufferCount = _realloc(*bufferDataPtr,capacity << 2);
          }
          if (bufferCount == 0) goto LAB_000457a8;
          *bufferDataPtr = bufferCount;
          emitter[0xc] = capacity;
          bufferCount = emitter[0xb];
        }
        emitter[0xb] = bufferCount + 7;
        tokenWritePtr2 = (undefined4 *)(bufferCount * 4 + *bufferDataPtr);
        *tokenWritePtr2 = ilInstAOpcode;
        tokenWritePtr2[1] = ilInstADst;
        tokenWritePtr2[2] = ilInstADstMask;
        do {
          tokenWritePtr2[3] = *recordPtr;
          recordWordNext3 = recordPtr + 3;
          recordPtr = recordPtr + 1;
          tokenWritePtr2[4] = *recordWordNext3;
          tokenWritePtr2 = tokenWritePtr2 + 2;
        } while (&ilInstASrc2 != recordPtr);
        local_70[1] = (undefined *)((uint)local_70[1] & 0xffff88ff | 0x5400);
        if (emitter[9] != 0) {
          return emitter[9];
        }
        bufferCount = emitter[0xb];
        capacity = emitter[0xc];
        if (capacity < bufferCount + 9U) {
          if (capacity == 0) {
            capacity = 0x10;
          }
          else {
            capacity = capacity << 1;
          }
          for (; capacity < bufferCount + 9U; capacity = capacity << 1) {
          }
          if (*bufferDataPtr == 0) {
            bufferCount = _malloc(capacity << 2);
          }
          else {
            bufferCount = _realloc(*bufferDataPtr,capacity << 2);
          }
          if (bufferCount == 0) goto LAB_000457a8;
          *bufferDataPtr = bufferCount;
          emitter[0xc] = capacity;
          bufferCount = emitter[0xb];
        }
        emitter[0xb] = bufferCount + 9;
        tokenWritePtr3 = (uint *)(bufferCount * 4 + *bufferDataPtr);
        *tokenWritePtr3 = ilInstBOpcode;
        tokenWritePtr3[1] = ilInstBDst;
        tokenWritePtr3[2] = ilInstBDstMask;
        do {
          tokenWritePtr3[3] = (uint)*recordPtr3;
          recordWordNext4 = recordPtr3 + 3;
          recordPtr3 = recordPtr3 + 1;
          tokenWritePtr3[4] = (uint)*recordWordNext4;
          tokenWritePtr3 = tokenWritePtr3 + 2;
        } while (local_70 != recordPtr3);
      }
    }
    _memset(&ilInstCOpcode,0,0x24);
    ilInstCOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstCOpcode) + 0)),0xd);
    ilInstBOpcode = ilInstBOpcode & 0xc000ffff | 0x30000;
    bufferCount = ((int (*)())fpilTranslateDestination)(emitter,iVar11 + 8,&ilInstCDst,&ilInstCDstMask,*(uint *)(iVar11 + 4) >> 0x14 & 1);
    if (bufferCount == 0) {
      ilInstCSrc0 = (undefined *)CONCAT22(4,(short)emitter[8] + 1);
      ilInstCSwz0 = ((unsigned char *)0x00003210);
      ilInstCSrc0 = (undefined *)((uint)ilInstCSrc0 | 0x400000);
      bufferCount = ((int (*)())fpilTranslateSource)(emitter,iVar11 + 0x10,auStack_54,auStack_48);
      if (bufferCount == 0) {
        bufferCount = ((int (*)())fpilBuildDestinationToken)(emitter,iVar11 + 8,auStack_b8,auStack_b4,0);
        if (bufferCount == 0) {
          local_b0 = ((unsigned char *)0x00003210);
          capacity = *(uint *)(iVar11 + 8);
          if ((capacity & 0x2000) != 0) {
            ((int (*)())fpilSetComponentSelect)(0,capacity >> 8 & 3,&local_b0);
            capacity = *(uint *)(iVar11 + 8);
          }
          if ((capacity & 0x4000) != 0) {
            ((int (*)())fpilSetComponentSelect)(1,capacity >> 6 & 3,&local_b0);
            capacity = *(uint *)(iVar11 + 8);
          }
          if ((capacity & 0x8000) != 0) {
            ((int (*)())fpilSetComponentSelect)(2,capacity >> 4 & 3,&local_b0);
            capacity = *(uint *)(iVar11 + 8);
          }
          if ((capacity & 0x10000) != 0) {
            ((int (*)())fpilSetComponentSelect)(3,capacity >> 2 & 3,&local_b0);
          }
          bufferCount = emitter[9];
          ilInstCSrc2 = local_b6 | 0x440000;
          ilInstCSwz2 = local_b0;
        }
        else {
          bufferCount = emitter[9];
        }
        if (bufferCount != 0) {
          return bufferCount;
        }
        bufferCount = emitter[0xb];
        capacity = emitter[0xc];
        if (capacity < bufferCount + 9U) {
          if (capacity == 0) {
            capacity = 0x10;
          }
          else {
            capacity = capacity << 1;
          }
          for (; capacity < bufferCount + 9U; capacity = capacity << 1) {
          }
          if (*bufferDataPtr == 0) {
            bufferCount = _malloc(capacity << 2);
          }
          else {
            bufferCount = _realloc(*bufferDataPtr,capacity << 2);
          }
          if (bufferCount == 0) {
LAB_000457a8:
            if (emitter[9] != 0) {
              return emitter[9];
            }
            emitter[9] = 1;
            return 1;
          }
          *bufferDataPtr = bufferCount;
          emitter[0xc] = capacity;
          bufferCount = emitter[0xb];
        }
        recordPtr2 = (undefined **)&ilInstCSrc0;
        emitter[0xb] = bufferCount + 9;
        tokenWritePtr = (undefined4 *)(bufferCount * 4 + *bufferDataPtr);
        *tokenWritePtr = ilInstCOpcode;
        tokenWritePtr[1] = ilInstCDst;
        tokenWritePtr[2] = ilInstCDstMask;
        do {
          tokenWritePtr[3] = *recordPtr2;
          recordWordNext5 = recordPtr2 + 3;
          recordPtr2 = recordPtr2 + 1;
          tokenWritePtr[4] = *recordWordNext5;
          tokenWritePtr = tokenWritePtr + 2;
        } while (&ilInstCSwz0 != recordPtr2);
        return 0;
      }
    }
  }
  return emitter[9];
}

/* fragmentTranslateSel @ 0x457f0 (2412 bytes) */
int fragmentTranslateSel(emitter, param_2)
  int *emitter;
  int param_2;
{
  uint *tokenWritePtr3;
  undefined **recordWordNext4;
  undefined4 *recordWordNext3;
  undefined4 *recordWordNext;
  undefined **recordWordNext2;
  int bufferCount;
  uint capacity;
  short sVar5;
  undefined4 *recordPtr;
  uint uVar7;
  uint uVar8;
  undefined4 *puVar9;
  undefined **ppuVar10;
  undefined **recordPtr2;
  uint *tokenWritePtr;
  undefined4 *tokenWritePtr2;
  uint *puVar14;
  int *bufferDataPtr;
  int iVar16;
  uint local_98;
  uint local_94;
  undefined4 local_90;
  uint local_8c;
  undefined4 ilInstAOpcode;
  undefined4 ilInstADst;
  undefined4 ilInstADstMask;
  undefined4 ilInstASrc0;
  undefined4 ilInstASrc1;
  undefined4 ilInstASrc2;
  undefined *ilInstASwz0;
  undefined *ilInstASwz1;
  undefined4 ilInstBOpcode;
  undefined4 ilInstBDst;
  uint ilInstBDstMask;
  undefined4 ilInstBSrc0;
  undefined4 ilInstBSrc1;
  undefined4 ilInstBSrc2;
  undefined *ilInstBSwz0;
  uint ilInstBSwz1;
  undefined *ilInstBSwz2;
  
  iVar16 = *emitter;
  bufferCount = *(int *)(iVar16 + 0x54);
  _memset(&ilInstAOpcode,0,0x24);
  iVar16 = iVar16 + bufferCount * 8 + param_2 * 8;
  _memset(&ilInstBOpcode,0,0x24);
  bufferCount = ((int (*)())fpilTranslateDestination)(emitter,iVar16 + 8,&local_98,&local_94,*(uint *)(iVar16 + 4) >> 0x14 & 1);
  if (bufferCount != 0) {
LAB_000458f0:
    return emitter[9];
  }
  puVar14 = (uint *)(iVar16 + 0x10);
  bufferCount = ((int (*)())fpilTranslateSource)(emitter,puVar14,&local_90,&local_8c);
  if (bufferCount != 0) goto LAB_000458f0;
  recordPtr = &ilInstASrc0;
  ilInstADst = CONCAT22(4,(short)emitter[8]);
  ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),0x5b);
  ilInstADstMask = 0x55;
  ilInstADst = ilInstADst | 0x400000;
  bufferCount = ((int (*)())fpilTranslateSource)(emitter,iVar16 + 0x18,recordPtr,&ilInstASwz0);
  if (bufferCount != 0) goto LAB_000458f0;
  ilInstASwz1 = ((unsigned char *)0x00005555U);
  ilInstASrc1 = 0x440000;
  if (emitter[9] != 0) {
    return emitter[9];
  }
  bufferDataPtr = emitter + 10;
  bufferCount = emitter[0xb];
  capacity = emitter[0xc];
  if (capacity < bufferCount + 7U) {
    if (capacity == 0) {
      capacity = 0x10;
    }
    else {
      capacity = capacity << 1;
    }
    for (; capacity < bufferCount + 7U; capacity = capacity << 1) {
    }
    if (*bufferDataPtr == 0) {
      bufferCount = _malloc(capacity << 2);
    }
    else {
      bufferCount = _realloc(*bufferDataPtr,capacity << 2);
    }
    if (bufferCount == 0) goto LAB_00046124;
    *bufferDataPtr = bufferCount;
    emitter[0xc] = capacity;
    bufferCount = emitter[0xb];
  }
  emitter[0xb] = bufferCount + 7;
  tokenWritePtr2 = (undefined4 *)(bufferCount * 4 + *bufferDataPtr);
  *tokenWritePtr2 = ilInstAOpcode;
  tokenWritePtr2[1] = ilInstADst;
  tokenWritePtr2[2] = ilInstADstMask;
  puVar9 = recordPtr;
  do {
    tokenWritePtr2[3] = *puVar9;
    recordWordNext = puVar9 + 3;
    puVar9 = puVar9 + 1;
    tokenWritePtr2[4] = *recordWordNext;
    tokenWritePtr2 = tokenWritePtr2 + 2;
  } while (&ilInstASrc2 != puVar9);
  ilInstBOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstBOpcode) + 0)),0xd);
  ilInstBOpcode = ilInstBOpcode & 0xc000ffff | 0x20000;
  if ((*puVar14 & 0x3000) == 0x1000) {
    sVar5 = (short)emitter[8];
    ilInstBDst = local_98;
    ilInstBDstMask = local_94;
  }
  else {
    sVar5 = (short)emitter[8];
    ilInstBDst = CONCAT22(4,sVar5 + 1);
    ilInstBDstMask = 0x55;
    ilInstBDst = ilInstBDst | 0x400000;
  }
  uVar8 = local_8c >> 4 & 7;
  uVar7 = local_8c >> 7 & 1;
  ilInstBSrc0 = (undefined *)CONCAT22(4,sVar5);
  capacity = local_8c >> 3 & 1;
  ilInstBSwz0 = ((unsigned char *)0x00003210);
  ilInstBSrc2 = local_90;
  ilInstBSwz2 = (undefined *)
             (capacity << 0xf |
             (local_8c & 7) << 0xc |
             capacity << 0xb |
             (local_8c & 7) << 8 | capacity << 7 | (local_8c & 7) << 4 | local_8c & 0xffff000f);
  ilInstBSrc1 = local_90;
  ilInstBSrc0 = (undefined *)((uint)ilInstBSrc0 | 0x400000);
  ilInstBSwz1 = uVar7 << 0xf |
             uVar8 << 0xc |
             uVar7 << 0xb |
             uVar8 << 8 | uVar7 << 7 | uVar8 << 4 | uVar7 << 3 | local_8c & 0xffff0000 | uVar8;
  if (emitter[9] != 0) {
    return emitter[9];
  }
  bufferCount = emitter[0xb];
  capacity = emitter[0xc];
  if (capacity < bufferCount + 9U) {
    if (capacity == 0) {
      capacity = 0x10;
    }
    else {
      capacity = capacity << 1;
    }
    for (; capacity < bufferCount + 9U; capacity = capacity << 1) {
    }
    if (*bufferDataPtr == 0) {
      bufferCount = _malloc(capacity << 2);
    }
    else {
      bufferCount = _realloc(*bufferDataPtr,capacity << 2);
    }
    if (bufferCount == 0) goto LAB_00046124;
    *bufferDataPtr = bufferCount;
    emitter[0xc] = capacity;
    bufferCount = emitter[0xb];
  }
  recordPtr2 = (undefined **)&ilInstBSrc0;
  emitter[0xb] = bufferCount + 9;
  tokenWritePtr = (uint *)(bufferCount * 4 + *bufferDataPtr);
  *tokenWritePtr = ilInstBOpcode;
  tokenWritePtr[1] = ilInstBDst;
  tokenWritePtr[2] = ilInstBDstMask;
  ppuVar10 = recordPtr2;
  do {
    tokenWritePtr[3] = (uint)*ppuVar10;
    recordWordNext2 = ppuVar10 + 3;
    ppuVar10 = ppuVar10 + 1;
    tokenWritePtr[4] = (uint)*recordWordNext2;
    tokenWritePtr = tokenWritePtr + 2;
  } while (&ilInstBSwz0 != ppuVar10);
  if (1 < (*puVar14 >> 0xc & 3)) {
    ilInstASrc0 = CONCAT22(4,(short)emitter[8]);
    ilInstASwz0 = ((unsigned char *)0x00003210);
    ilInstASrc0 = ilInstASrc0 | 0x400000;
    if (emitter[9] != 0) {
      return emitter[9];
    }
    bufferCount = emitter[0xb];
    capacity = emitter[0xc];
    if (capacity < bufferCount + 7U) {
      if (capacity == 0) {
        capacity = 0x10;
      }
      else {
        capacity = capacity << 1;
      }
      for (; capacity < bufferCount + 7U; capacity = capacity << 1) {
      }
      if (*bufferDataPtr == 0) {
        bufferCount = _malloc(capacity << 2);
      }
      else {
        bufferCount = _realloc(*bufferDataPtr,capacity << 2);
      }
      if (bufferCount == 0) goto LAB_00046124;
      *bufferDataPtr = bufferCount;
      emitter[0xc] = capacity;
      bufferCount = emitter[0xb];
    }
    emitter[0xb] = bufferCount + 7;
    tokenWritePtr2 = (undefined4 *)(bufferCount * 4 + *bufferDataPtr);
    *tokenWritePtr2 = ilInstAOpcode;
    tokenWritePtr2[1] = ilInstADst;
    tokenWritePtr2[2] = ilInstADstMask;
    puVar9 = recordPtr;
    do {
      tokenWritePtr2[3] = *puVar9;
      recordWordNext = puVar9 + 3;
      puVar9 = puVar9 + 1;
      tokenWritePtr2[4] = *recordWordNext;
      tokenWritePtr2 = tokenWritePtr2 + 2;
    } while (&ilInstASrc2 != puVar9);
    if ((*puVar14 & 0x3000) == 0x2000) {
      ilInstBDst = local_98;
      ilInstBDstMask = local_94;
    }
    capacity = local_8c >> 8 & 7;
    uVar7 = local_8c >> 0xb & 1;
    ilInstBSrc2 = CONCAT22(4,(short)emitter[8] + 1);
    ilInstBSwz2 = ((unsigned char *)0x00003210);
    ilInstBSrc2 = ilInstBSrc2 | 0x400000;
    ilInstBSwz1 = uVar7 << 0xf |
               capacity << 0xc |
               uVar7 << 0xb |
               capacity << 8 | uVar7 << 7 | capacity << 4 | uVar7 << 3 | capacity | ilInstBSwz1 & 0xffff0000;
    if (emitter[9] != 0) {
      return emitter[9];
    }
    bufferCount = emitter[0xb];
    capacity = emitter[0xc];
    if (capacity < bufferCount + 9U) {
      if (capacity == 0) {
        capacity = 0x10;
      }
      else {
        capacity = capacity << 1;
      }
      for (; capacity < bufferCount + 9U; capacity = capacity << 1) {
      }
      if (*bufferDataPtr == 0) {
        bufferCount = _malloc(capacity << 2);
      }
      else {
        bufferCount = _realloc(*bufferDataPtr,capacity << 2);
      }
      if (bufferCount == 0) goto LAB_00046124;
      *bufferDataPtr = bufferCount;
      emitter[0xc] = capacity;
      bufferCount = emitter[0xb];
    }
    emitter[0xb] = bufferCount + 9;
    tokenWritePtr = (uint *)(bufferCount * 4 + *bufferDataPtr);
    *tokenWritePtr = ilInstBOpcode;
    tokenWritePtr[1] = ilInstBDst;
    tokenWritePtr[2] = ilInstBDstMask;
    ppuVar10 = recordPtr2;
    do {
      tokenWritePtr[3] = (uint)*ppuVar10;
      recordWordNext2 = ppuVar10 + 3;
      ppuVar10 = ppuVar10 + 1;
      tokenWritePtr[4] = (uint)*recordWordNext2;
      tokenWritePtr = tokenWritePtr + 2;
    } while (&ilInstBSwz0 != ppuVar10);
    if ((*puVar14 & 0x3000) != 0x3000) {
      return 0;
    }
    if (emitter[9] != 0) {
      return emitter[9];
    }
    bufferCount = emitter[0xb];
    capacity = emitter[0xc];
    if (capacity < bufferCount + 7U) {
      if (capacity == 0) {
        capacity = 0x10;
      }
      else {
        capacity = capacity << 1;
      }
      for (; capacity < bufferCount + 7U; capacity = capacity << 1) {
      }
      if (*bufferDataPtr == 0) {
        bufferCount = _malloc(capacity << 2);
      }
      else {
        bufferCount = _realloc(*bufferDataPtr,capacity << 2);
      }
      if (bufferCount == 0) goto LAB_00046124;
      *bufferDataPtr = bufferCount;
      emitter[0xc] = capacity;
      bufferCount = emitter[0xb];
    }
    emitter[0xb] = bufferCount + 7;
    tokenWritePtr2 = (undefined4 *)(bufferCount * 4 + *bufferDataPtr);
    *tokenWritePtr2 = ilInstAOpcode;
    tokenWritePtr2[1] = ilInstADst;
    tokenWritePtr2[2] = ilInstADstMask;
    do {
      tokenWritePtr2[3] = *recordPtr;
      recordWordNext3 = recordPtr + 3;
      recordPtr = recordPtr + 1;
      tokenWritePtr2[4] = *recordWordNext3;
      tokenWritePtr2 = tokenWritePtr2 + 2;
    } while (&ilInstASrc2 != recordPtr);
    uVar7 = local_8c >> 0xc & 7;
    capacity = local_8c >> 0xf & 1;
    ilInstBDst = local_98;
    ilInstBDstMask = local_94;
    ilInstBSwz1 = capacity << 0xf |
               uVar7 << 0xc |
               capacity << 0xb |
               uVar7 << 8 | capacity << 7 | uVar7 << 4 | capacity << 3 | uVar7 | ilInstBSwz1 & 0xffff0000;
    if (emitter[9] != 0) {
      return emitter[9];
    }
    bufferCount = emitter[0xb];
    capacity = emitter[0xc];
    if (capacity < bufferCount + 9U) {
      if (capacity == 0) {
        capacity = 0x10;
      }
      else {
        capacity = capacity << 1;
      }
      for (; capacity < bufferCount + 9U; capacity = capacity << 1) {
      }
      if (*bufferDataPtr == 0) {
        bufferCount = _malloc(capacity << 2);
      }
      else {
        bufferCount = _realloc(*bufferDataPtr,capacity << 2);
      }
      if (bufferCount == 0) {
LAB_00046124:
        if (emitter[9] == 0) {
          emitter[9] = 1;
          return 1;
        }
        return emitter[9];
      }
      *bufferDataPtr = bufferCount;
      emitter[0xc] = capacity;
      bufferCount = emitter[0xb];
    }
    emitter[0xb] = bufferCount + 9;
    tokenWritePtr3 = (uint *)(bufferCount * 4 + *bufferDataPtr);
    *tokenWritePtr3 = ilInstBOpcode;
    tokenWritePtr3[1] = ilInstBDst;
    tokenWritePtr3[2] = ilInstBDstMask;
    do {
      tokenWritePtr3[3] = (uint)*recordPtr2;
      recordWordNext4 = recordPtr2 + 3;
      recordPtr2 = recordPtr2 + 1;
      tokenWritePtr3[4] = (uint)*recordWordNext4;
      tokenWritePtr3 = tokenWritePtr3 + 2;
    } while (recordPtr2 != &ilInstBSwz0);
  }
  return 0;
}

/* fragmentTranslateAll @ 0x46180 (1528 bytes) */
int fragmentTranslateAll(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  uint tokenCapacity;
  int tokenCount2;
  int tokenCount;
  undefined4 *recordPtr2;
  undefined4 *recordPtr;
  undefined4 *recordWordNext2;
  int allocation;
  int allocation2;
  undefined4 *recordWordNext;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 *tokenWritePtr;
  undefined4 *puVar7;
  undefined4 *recordWordNext3;
  int iVar9;
  int *tokenDataPtrAddr;
  undefined4 ilInstAOpcode;
  uint ilInstADst;
  uint ilInstADstMask;
  undefined4 ilInstASrc0;
  uint ilInstASrc1;
  undefined4 ilInstASrc2;
  undefined *ilInstASwz0;
  uint ilInstASwz1;
  
  bVar2 = param_3 == 0;
  iVar9 = *param_1 + *(int *)(*param_1 + 0x54) * 8;
  _memset(&ilInstAOpcode,0,0x24);
  if (bVar2) {
    param_3 = (*(uint *)(param_2 * 8 + iVar9 + 4) >> 0x1a & 3) + 1;
  }
  if (param_3 < 3) {
    if (param_3 == 1) {
      (*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 2)) = 0x47;
    }
    else {
      (*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 2)) = 0x49;
    }
    iVar9 = iVar9 + param_2 * 8;
    iVar5 = ((int (*)())fpilTranslateDestination)(param_1,iVar9 + 8,&ilInstADst,&ilInstADstMask,1);
    if (iVar5 != 0) {
LAB_00046640:
      return param_1[9];
    }
    if (bVar2) {
      iVar9 = ((int (*)())fpilTranslateSource)(param_1,iVar9 + 0x10,&ilInstASrc0,&ilInstASwz0);
      if (iVar9 != 0) goto LAB_00046640;
    }
    else {
      ilInstASrc0 = CONCAT22(4,(short)param_1[8]);
      ilInstASwz0 = ((unsigned char *)0x00003210);
      ilInstASrc0 = ilInstASrc0 | 0x400000;
    }
    if (param_3 == 2) {
      ilInstASrc1 = ilInstASrc0;
      ilInstASwz1 = (uint)ilInstASwz0 >> 4 & 8 | (uint)ilInstASwz0 >> 4 & 7 | (uint)ilInstASwz0 & 0xfffffff0;
    }
    if (param_1[9] != 0) {
      return param_1[9];
    }
    tokenDataPtrAddr = param_1 + 10;
    tokenCount2 = param_1[0xb];
    iVar5 = param_3 * 2 + 3;
    tokenCapacity = param_1[0xc];
    uVar4 = iVar5 + tokenCount2;
    if (tokenCapacity < uVar4) {
      if (tokenCapacity == 0) {
        tokenCapacity = 0x10;
      }
      else {
        tokenCapacity = tokenCapacity << 1;
      }
      for (; tokenCapacity < uVar4; tokenCapacity = tokenCapacity << 1) {
      }
      if (*tokenDataPtrAddr == 0) {
        allocation = _malloc(tokenCapacity << 2);
      }
      else {
        allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
      }
      if (allocation == 0) goto LAB_0004676c;
      *tokenDataPtrAddr = allocation;
      param_1[0xc] = tokenCapacity;
      tokenCount2 = param_1[0xb];
    }
    param_1[0xb] = iVar5 + tokenCount2;
    tokenWritePtr = (undefined4 *)(tokenCount2 * 4 + *tokenDataPtrAddr);
    *tokenWritePtr = ilInstAOpcode;
    tokenWritePtr[1] = ilInstADst;
    tokenWritePtr[2] = ilInstADstMask;
    if (0 < param_3) {
      recordPtr = &ilInstASrc0;
      do {
        tokenWritePtr[3] = *recordPtr;
        recordWordNext3 = recordPtr + 3;
        recordPtr = recordPtr + 1;
        tokenWritePtr[4] = *recordWordNext3;
        tokenWritePtr = tokenWritePtr + 2;
        param_3 = param_3 + -1;
      } while (param_3 != 0);
    }
  }
  else {
    ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),0x49);
    ilInstADstMask = ilInstADstMask & 0xffffff00 | 0x111;
    ilInstADst = CONCAT22((short)(ilInstADst >> 0x10),(short)param_1[8]) & 0xffc0ffff | 0x440000;
    if (bVar2) {
      iVar5 = ((int (*)())fpilTranslateSource)(param_1,iVar9 + param_2 * 8 + 0x10,&ilInstASrc0,&ilInstASwz0);
      if (iVar5 != 0) goto LAB_00046640;
    }
    else {
      ilInstASrc0 = CONCAT22(4,(short)param_1[8]);
      ilInstASwz0 = ((unsigned char *)0x00003210);
      ilInstASrc0 = ilInstASrc0 | 0x400000;
    }
    ilInstASrc1 = ilInstASrc0;
    uVar3 = (uint)ilInstASwz0 >> 4 & 7;
    uVar4 = (uint)ilInstASwz0 >> 4 & 8;
    if (param_3 == 3) {
      ilInstASwz1 = uVar4 | uVar3 | (uint)ilInstASwz0 & 0xfffff0f0 | 0x500;
    }
    else {
      ilInstASwz1 = ((uint)ilInstASwz0 & 0xfffff8f0) >> 4 & 0x800 |
                 (uint)ilInstASwz0 >> 4 & 0x700 | uVar4 | uVar3 | (uint)ilInstASwz0 & 0xfffff0f0;
    }
    if (param_1[9] != 0) {
      return param_1[9];
    }
    tokenDataPtrAddr = param_1 + 10;
    tokenCount = param_1[0xb];
    tokenCapacity = param_1[0xc];
    if (tokenCapacity < tokenCount + 7U) {
      if (tokenCapacity == 0) {
        tokenCapacity = 0x10;
      }
      else {
        tokenCapacity = tokenCapacity << 1;
      }
      for (; tokenCapacity < tokenCount + 7U; tokenCapacity = tokenCapacity << 1) {
      }
      if (*tokenDataPtrAddr == 0) {
        allocation2 = _malloc(tokenCapacity << 2);
      }
      else {
        allocation2 = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
      }
      if (allocation2 == 0) goto LAB_0004676c;
      *tokenDataPtrAddr = allocation2;
      param_1[0xc] = tokenCapacity;
      tokenCount = param_1[0xb];
    }
    recordPtr2 = &ilInstASrc0;
    param_1[0xb] = tokenCount + 7;
    tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
    *tokenWritePtr = ilInstAOpcode;
    tokenWritePtr[1] = ilInstADst;
    tokenWritePtr[2] = ilInstADstMask;
    puVar7 = recordPtr2;
    do {
      tokenWritePtr[3] = *puVar7;
      recordWordNext = puVar7 + 3;
      puVar7 = puVar7 + 1;
      tokenWritePtr[4] = *recordWordNext;
      tokenWritePtr = tokenWritePtr + 2;
    } while (&ilInstASrc2 != puVar7);
    iVar9 = ((int (*)())fpilTranslateDestination)(param_1,iVar9 + param_2 * 8 + 8,&ilInstADst,&ilInstADstMask,1);
    if (iVar9 != 0) goto LAB_00046640;
    ilInstASrc0 = CONCAT22(4,(short)param_1[8]);
    ilInstASwz0 = (undefined *)0x0;
    ilInstASwz1 = ilInstASwz1 & 0xfffffff8 | 2;
    ilInstASrc1 = ilInstASrc0 | 0x400000;
    ilInstASrc0 = ilInstASrc0 | 0x400000;
    if (param_1[9] != 0) {
      return param_1[9];
    }
    tokenCount2 = param_1[0xb];
    tokenCapacity = param_1[0xc];
    if (tokenCapacity < tokenCount2 + 7U) {
      if (tokenCapacity == 0) {
        tokenCapacity = 0x10;
      }
      else {
        tokenCapacity = tokenCapacity << 1;
      }
      for (; tokenCapacity < tokenCount2 + 7U; tokenCapacity = tokenCapacity << 1) {
      }
      if (*tokenDataPtrAddr == 0) {
        allocation = _malloc(tokenCapacity << 2);
      }
      else {
        allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
      }
      if (allocation == 0) {
LAB_0004676c:
        if (param_1[9] != 0) {
          return param_1[9];
        }
        param_1[9] = 1;
        return 1;
      }
      *tokenDataPtrAddr = allocation;
      param_1[0xc] = tokenCapacity;
      tokenCount2 = param_1[0xb];
    }
    param_1[0xb] = tokenCount2 + 7;
    tokenWritePtr = (undefined4 *)(tokenCount2 * 4 + *tokenDataPtrAddr);
    *tokenWritePtr = ilInstAOpcode;
    tokenWritePtr[1] = ilInstADst;
    tokenWritePtr[2] = ilInstADstMask;
    do {
      tokenWritePtr[3] = *recordPtr2;
      recordWordNext2 = recordPtr2 + 3;
      recordPtr2 = recordPtr2 + 1;
      tokenWritePtr[4] = *recordWordNext2;
      tokenWritePtr = tokenWritePtr + 2;
    } while (recordPtr2 != &ilInstASrc2);
  }
  return 0;
}

/* fragmentTranslateAny @ 0x467a0 (632 bytes) */
int fragmentTranslateAny(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  int tokenCount;
  int translatorError;
  int allocation;
  undefined4 *recordWordNext;
  int iVar2;
  uint tokenCapacity;
  undefined2 uVar5;
  undefined4 *recordPtr;
  undefined4 *tokenWritePtr;
  int *tokenDataPtrAddr;
  int iVar8;
  undefined4 ilInstAOpcode;
  undefined4 ilInstADst;
  undefined4 ilInstADstMask;
  undefined4 ilInstASrc0;
  uint ilInstASrc1;
  undefined4 ilInstASrc2;
  undefined *ilInstASwz0;
  uint ilInstASwz1;
  
  iVar8 = *param_1;
  iVar2 = *(int *)(iVar8 + 0x54);
  _memset(&ilInstAOpcode,0,0x24);
  iVar8 = iVar8 + iVar2 * 8 + param_2 * 8;
  ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),0x23);
  iVar2 = ((int (*)())fpilTranslateDestination)(param_1,iVar8 + 8,&ilInstADst,&ilInstADstMask,1);
  if (iVar2 == 0) {
    if (param_3 == 0) {
      iVar2 = ((int (*)())fpilTranslateSource)(param_1,iVar8 + 0x10,&ilInstASrc0,&ilInstASwz0);
      if (iVar2 != 0) goto LAB_000468f0;
      uVar5 = (undefined2)param_1[8];
    }
    else {
      uVar5 = (undefined2)param_1[8];
      ilInstASrc0 = CONCAT22(4,uVar5);
      ilInstASwz0 = ((unsigned char *)0x00003210);
      ilInstASrc0 = ilInstASrc0 | 0x400000;
    }
    translatorError = param_1[9];
    ilInstASwz1 = ilInstASwz1 & 0xffff0000 | 0x5555;
    ilInstASrc1 = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstASrc1) + 0)),uVar5) & 0xffc0ffff | 0x440000;
    if (translatorError == 0) {
      tokenDataPtrAddr = param_1 + 10;
      tokenCount = param_1[0xb];
      tokenCapacity = param_1[0xc];
      if (tokenCapacity < tokenCount + 7U) {
        if (tokenCapacity == 0) {
          tokenCapacity = 0x10;
        }
        else {
          tokenCapacity = tokenCapacity << 1;
        }
        for (; tokenCapacity < tokenCount + 7U; tokenCapacity = tokenCapacity << 1) {
        }
        if (*tokenDataPtrAddr == 0) {
          allocation = _malloc(tokenCapacity << 2);
        }
        else {
          allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
        }
        if (allocation == 0) {
          if (param_1[9] != 0) {
            return param_1[9];
          }
          param_1[9] = 1;
          return 1;
        }
        *tokenDataPtrAddr = allocation;
        param_1[0xc] = tokenCapacity;
        tokenCount = param_1[0xb];
      }
      recordPtr = &ilInstASrc0;
      param_1[0xb] = tokenCount + 7;
      tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
      *tokenWritePtr = ilInstAOpcode;
      tokenWritePtr[1] = ilInstADst;
      tokenWritePtr[2] = ilInstADstMask;
      do {
        tokenWritePtr[3] = *recordPtr;
        recordWordNext = recordPtr + 3;
        recordPtr = recordPtr + 1;
        tokenWritePtr[4] = *recordWordNext;
        tokenWritePtr = tokenWritePtr + 2;
      } while (&ilInstASrc2 != recordPtr);
      translatorError = 0;
    }
  }
  else {
LAB_000468f0:
    translatorError = param_1[9];
  }
  return translatorError;
}

/* fragmentTranslateArithmetic @ 0x46a30 (1080 bytes) */
int fragmentTranslateArithmetic(param_1, param_2)
  int *param_1;
  int param_2;
{
  uint tokenCapacity2;
  uint tokenCapacity;
  int tokenCount2;
  int allocation;
  uint *recordWordNext;
  int tokenCount;
  uint *recordPtr;
  uint *tokenWritePtr;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int *tokenDataPtrAddr;
  undefined4 ilInstAOpcode;
  undefined4 ilInstADst;
  uint ilInstADstMask;
  undefined4 ilInstASrc0;
  undefined1 auStack_58 [2];
  short local_56;
  uint ilInstASrc2;
  uint ilInstASwz0;
  undefined1 auStack_4c [32];
  
  iVar11 = *param_1 + *(int *)(*param_1 + 0x54) * 8;
  _memset(&ilInstAOpcode,0,0x24);
  iVar12 = iVar11 + param_2 * 8;
  uVar9 = *(uint *)(iVar11 + param_2 * 8) >> 0x12 & 0xff;
  if ((param_1[5] & 0x20000000U) == 0) {
    uVar7 = 0;
    uVar5 = 0;
    uVar6 = 0;
    uVar10 = 3;
  }
  else {
    uVar7 = *(uint *)(iVar12 + 4) >> 0x1c & 1;
    uVar5 = *(uint *)(iVar12 + 0x10) >> 0xe & 1;
    uVar6 = *(uint *)(iVar12 + 0x18) >> 0xe & 1;
    uVar10 = *(uint *)(iVar12 + 4) >> 0x1a & 3;
  }
  iVar11 = uVar9 * 0x10;
  ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),(short)(*(uint *)(&DAT_001dac34 + iVar11) >> 1));
  ilInstAOpcode = (*(uint *)(&DAT_001dac38 + iVar11) >> 0x13) << 0x10 | ilInstAOpcode & 0xc000ffff;
  iVar11 = ((int (*)())fpilTranslateDestination)(param_1,iVar12 + 8,&ilInstADst,&ilInstADstMask,*(uint *)(iVar12 + 4) >> 0x14 & 1);
  if (iVar11 == 0) {
    iVar11 = ((int (*)())fpilTranslateSource)(param_1,iVar12 + 0x10,&ilInstASrc0,&ilInstASwz0);
    if ((iVar11 == 0) &&
       (iVar11 = ((int (*)())fpilTranslateSource)(param_1,iVar12 + 0x18,auStack_58,auStack_4c), iVar11 == 0)) {
      if (uVar7 == 0) {
        iVar11 = 1;
      }
      else {
        iVar11 = uVar10 + 1;
        if (iVar11 == 0) {
LAB_00046cd4:
          if ((((param_1[5] & 0x20000000U) == 0) || (uVar9 != 0x3a)) ||
             (iVar11 = ((int (*)())fpilClassifyDestination)(param_1,iVar12 + 8), iVar11 != 1)) {
            return 0;
          }
          ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),99);
          ilInstASrc0 = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstASrc0) + 0)),(*(unsigned short *)((unsigned char *)&(ilInstADst) + 2)));
          ilInstASwz0 = ilInstASwz0 & 0xffff0000 | 0x3210;
          ilInstASrc0 = (ilInstADst >> 0x10 & 0x3f) << 0x10 | ilInstASrc0 & 0xffc0ffff;
          ilInstAOpcode = ilInstAOpcode & 0xc000ffff;
          if (param_1[9] != 0) {
            return param_1[9];
          }
          tokenDataPtrAddr = param_1 + 10;
          tokenCount2 = param_1[0xb];
          tokenCapacity = param_1[0xc];
          if (tokenCapacity < tokenCount2 + 5U) {
            if (tokenCapacity == 0) {
              tokenCapacity = 0x10;
            }
            else {
              tokenCapacity = tokenCapacity << 1;
            }
            for (; tokenCapacity < tokenCount2 + 5U; tokenCapacity = tokenCapacity << 1) {
            }
            if (*tokenDataPtrAddr == 0) {
              iVar11 = _malloc(tokenCapacity << 2);
            }
            else {
              iVar11 = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
            }
            if (iVar11 == 0) {
LAB_00046e28:
              if (param_1[9] != 0) {
                return param_1[9];
              }
              param_1[9] = 1;
              return 1;
            }
            *tokenDataPtrAddr = iVar11;
            param_1[0xc] = tokenCapacity;
            tokenCount2 = param_1[0xb];
          }
          param_1[0xb] = tokenCount2 + 5;
          tokenWritePtr = (uint *)(tokenCount2 * 4 + *tokenDataPtrAddr);
          *tokenWritePtr = ilInstAOpcode;
          tokenWritePtr[1] = ilInstADst;
          tokenWritePtr[2] = ilInstADstMask;
          tokenWritePtr[3] = ilInstASrc0;
          tokenWritePtr[4] = ilInstASwz0;
          return 0;
        }
      }
      if (param_1[9] != 0) {
        return param_1[9];
      }
      iVar8 = 0;
      tokenDataPtrAddr = param_1 + 10;
      do {
        tokenCount = param_1[0xb];
        tokenCapacity2 = param_1[0xc];
        if (tokenCapacity2 < tokenCount + 7U) {
          if (tokenCapacity2 == 0) {
            tokenCapacity2 = 0x10;
          }
          else {
            tokenCapacity2 = tokenCapacity2 << 1;
          }
          for (; tokenCapacity2 < tokenCount + 7U; tokenCapacity2 = tokenCapacity2 << 1) {
          }
          if (*tokenDataPtrAddr == 0) {
            allocation = _malloc(tokenCapacity2 << 2);
          }
          else {
            allocation = _realloc(*tokenDataPtrAddr,tokenCapacity2 << 2);
          }
          if (allocation == 0) goto LAB_00046e28;
          *tokenDataPtrAddr = allocation;
          param_1[0xc] = tokenCapacity2;
          tokenCount = param_1[0xb];
        }
        param_1[0xb] = tokenCount + 7;
        tokenWritePtr = (uint *)(tokenCount * 4 + *tokenDataPtrAddr);
        *tokenWritePtr = ilInstAOpcode;
        tokenWritePtr[1] = ilInstADst;
        tokenWritePtr[2] = ilInstADstMask;
        recordPtr = &ilInstASrc0;
        do {
          tokenWritePtr[3] = *recordPtr;
          recordWordNext = recordPtr + 3;
          recordPtr = recordPtr + 1;
          tokenWritePtr[4] = *recordWordNext;
          tokenWritePtr = tokenWritePtr + 2;
        } while (recordPtr != &ilInstASrc2);
        if (uVar7 != 0) {
          ilInstADst = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstADst) + 0)),(*(unsigned short *)((unsigned char *)&(ilInstADst) + 2)) + 1);
        }
        if (uVar5 != 0) {
          ilInstASrc0 = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstASrc0) + 0)),(*(unsigned short *)((unsigned char *)&(ilInstASrc0) + 2)) + 1);
        }
        if (uVar6 != 0) {
          local_56 = local_56 + 1;
        }
        iVar8 = iVar8 + 1;
        if (iVar11 == iVar8) goto LAB_00046cd4;
        if (param_1[9] != 0) {
          return param_1[9];
        }
      } while( true );
    }
  }
  return param_1[9];
}

/* fragmentInstructionToIL @ 0x46e90 (7800 bytes) */
int fragmentInstructionToIL(translator, unusedArg2, unusedArg3, unusedArg4, unusedArg5, unusedArg6, unusedArg7, unusedArg8)
  int *translator;
  undefined4 unusedArg2;
  undefined4 unusedArg3;
  undefined4 unusedArg4;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
  undefined4 unusedArg7;
  undefined4 unusedArg8;
{
  int maxRegSpan;
  int regSpan;
  int programPtr;
  int instructionBlock2;
  int instBlockOffset;
  int newTempBase;
  int arraySourceCount;
  int tempRegBase;
  int srcWordOffset;
  int srcSwizzleStatus;
  int tokenWordCount;
  int instructionBlock;
  int instructionBlock4;
  bool advanceSrc0;
  bool moreTemps;
  bool moreSources;
  short tempRegisterBase;
  undefined2 ilSelectOpcode;
  undefined4 emittedSourceCount;
  uint *src1OperandPtr;
  uint *src0OperandPtr;
  uint *dstOutPair;
  uint opcodeInfoWord1;
  int srcStatus3;
  int emitStatus3;
  int srcStatus2;
  int emitStatus2;
  int emitStatus;
  int reserveStatus;
  int callStatus;
  int srcStatus;
  int dstStatus;
  int constStatus;
  uint opcode;
  int opcodeInfoOffset;
  int instructionBlockOffset;
  int recordByteOffset;
  uint operandCount;
  bool bVar1;
  bool advanceSrc1;
  short tempRegisterIndex;
  uint uVar4;
  int program;
  int iVar6;
  uint opcodeInfoWord0;
  int returnCode;
  undefined4 saturate;
  undefined2 tempRegisterHalf;
  uint uVar11;
  undefined *adjustedSwizzle;
  uint uVar13;
  int tempRegister;
  int recordSpan;
  int instructionCount;
  int instructionIndex;
  int recordIndex;
  uint *currentRecord;
  uint *instructionRecords;
  uint *sourceRecordCursor;
  uint uVar22;
  int iVar23;
  int iVar24;
  undefined4 *srcOutCursor;
  uint *src0Operand;
  uint dstToken;
  uint dstMask;
  uint srcToken;
  uint srcSwizzle;
  uint dstToken2;
  uint dstMask2;
  uint *reservedTokens;
  undefined4 local_ec;
  uint local_e8;
  uint local_e4;
  uint local_e0;
  uint local_dc;
  uint local_d8;
  undefined4 ilInstBOpcode;
  undefined4 ilInstBDst;
  uint ilInstBDstMask;
  undefined4 ilInstBSrc0;
  undefined4 ilInstBSrc1;
  undefined *ilInstBSwz0;
  undefined *ilInstBSwz12 [2];
  undefined4 ilInstAOpcode;
  undefined4 ilInstADst;
  uint ilInstADstMask;
  undefined4 ilInstASrc0;
  undefined4 ilInstASrc1;
  undefined4 ilInstASrc2;
  undefined *ilInstASwz0;
  undefined *ilInstASwz1;
  undefined *ilInstASwz2;
  int src1RegSpan;
  int src0RegSpan;
  int dstRegSpan;
  uint src1Advances;
  uint src0Advances;
  uint *instHeader;
  uint local_70;
  uint local_6c;
  uint savedDstToken;
  uint savedDstMask;
  undefined4 *ilInstBPtr;
  undefined4 *ilInstAPtr;
  
  program = *translator;
  instructionCount = *(int *)(program + 0x50);
  instructionBlockOffset = *(int *)(program + 0x54) * 8;
  instructionRecords = (uint *)(program + instructionBlockOffset);
  if (instructionCount < 1) {
LAB_00048d20:
    returnCode = 0;
  }
  else {
    opcode = *(uint *)(program + instructionBlockOffset) >> 0x12 & 0xff;
    opcodeInfoOffset = opcode * 0x10;
    uVar13 = *(uint *)(&DAT_001dac34 + opcodeInfoOffset) >> 0x11 & 0xf;
    if ((uVar13 != 0) && ((*(uint *)(&DAT_001dac40 + opcodeInfoOffset) >> 0x1c & DAT_001db344) == 0)) {
      instructionIndex = 0;
      recordIndex = 0;
      recordByteOffset = 0;
      currentRecord = instructionRecords;
      do {
        operandCount = *currentRecord >> 0x1d;
        recordSpan = operandCount + 2;
        if (uVar13 == 2) {
          instructionBlock = *translator + *(int *)(*translator + 0x54) * 8;
          uVar13 = *(uint *)(recordByteOffset + instructionBlock) >> 0x12 & 0xff;
          if ((uVar13 - 0x44 < 2) || (iVar23 = 0, uVar13 == 0x47)) {
            iVar23 = 1;
          }
          if (((uVar13 == 0x43) || (uVar13 == 0x45)) || (bVar1 = false, uVar13 == 0x47)) {
            bVar1 = true;
          }
          ilInstAPtr = &ilInstAOpcode;
          iVar24 = instructionBlock + recordByteOffset;
          _memset(ilInstAPtr,0,0x24);
          ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),(short)(*(uint *)(&DAT_001dac34 + uVar13 * 0x10) >> 1))
          ;
          ((int (*)())fpilTranslateDestination)(translator,iVar24 + 8,&ilInstADst,&ilInstADstMask,
                       *(uint *)(recordByteOffset + instructionBlock + 4) >> 0x14 & 1);
          ((int (*)())fpilTranslateSource)(translator,iVar24 + 0x10,&ilInstASrc0,&ilInstASwz0);
          if ((translator[5] & 0x20000000U) == 0) {
            ilInstAOpcode = (*(uint *)(iVar24 + 0x18) & 0x1f) << 0x10 | ilInstAOpcode & 0xc000ffff;
            uVar13 = *(uint *)(iVar24 + 0x18) >> 5 & 7;
            if (iVar23 != 0) {
              ilInstASrc1 = ilInstASrc0;
              ilInstASwz1 = ilInstASwz0;
            }
          }
          else {
            reservedTokens = (uint *)0x0;
            constStatus = ((int (*)())fpilMapConstantRegister)(translator,recordIndex,&reservedTokens);
            if (constStatus != 0) goto LAB_00048a2c;
            ilInstAOpcode = ((uint)reservedTokens & 0x3fff) << 0x10 | ilInstAOpcode & 0xc000ffff;
            uVar13 = *(uint *)(iVar24 + 0x20) >> 5 & 7;
            if (iVar23 != 0) {
              ((int (*)())fpilTranslateSource)(translator,iVar24 + 0x28,&ilInstASrc1,&ilInstASwz1);
              uVar11 = (uint)ilInstASwz1 >> 3 & 1;
              ilInstASwz1 = (undefined *)
                         (uVar11 << 0xf |
                         ((uint)ilInstASwz1 & 7) << 0xc |
                         uVar11 << 0xb |
                         ((uint)ilInstASwz1 & 7) << 8 |
                         uVar11 << 7 | ((uint)ilInstASwz1 & 7) << 4 | (uint)ilInstASwz1 & 0xffff000f);
            }
          }
          if (uVar13 - 5 < 3) {
            ilInstAOpcode = ilInstAOpcode & 0xf3ffffff | 0x4000000;
          }
          adjustedSwizzle = ilInstASwz0;
          if ((bVar1) &&
             (adjustedSwizzle = (undefined *)((uint)ilInstASwz0 & 0xff1fffff | 0x600000),
             ((uint)ilInstASwz0 & 0x8000) != 0)) {
            adjustedSwizzle = (undefined *)
                      (((uint)ilInstASwz0 & 0xff1ff777 ^ 0x8000) & 0x8000 |
                      ((uint)ilInstASwz0 & 0xff1fff77 ^ 0x800) & 0x800 |
                      ((uint)ilInstASwz0 & 0xff1ffff7 ^ 0x80) & 0x80 |
                      ((uint)adjustedSwizzle ^ 8) & 8 | (uint)ilInstASwz0 & 0xff1f7777 | 0x600000);
          }
          ilInstASwz0 = adjustedSwizzle;
          ((int (*)())fpilEmitInstruction)(translator,ilInstAPtr,1,iVar23 + 1);
LAB_00048c70:
          if (opcode != 0x4d) {
LAB_00048c78:
            if ((((*(uint *)(&DAT_001dac34 + opcodeInfoOffset) >> 0x11 & 0xf) != 3) &&
                ((translator[5] & 0x20000000U) != 0)) &&
               (((((uVar13 = *(uint *)((int)instructionRecords + recordByteOffset + 8), (uVar13 & 0x2000) != 0 &&
                   ((uVar13 & 0x300) != 0)) ||
                  (((uVar13 & 0x4000) != 0 && ((uVar13 & 0xc0) != 0x40)))) ||
                 (((uVar13 & 0x8000) != 0 && ((uVar13 & 0x30) != 0x20)))) ||
                (((uVar13 & 0x10000) != 0 && ((uVar13 & 0xc) != 0xc)))))) {
              ((int (*)())fpilEmitMoveFromTemp)(translator,(int)instructionRecords + recordByteOffset + 8,currentRecord[1] >> 0x14 & 1);
            }
          }
        }
        else {
          if (uVar13 != 7) {
            if (uVar13 == 5) {
              ilInstBPtr = &ilInstBOpcode;
              _memset(ilInstBPtr,0,0x24);
              ilInstBOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstBOpcode) + 0)),(short)(*(uint *)(&DAT_001dac34 + opcodeInfoOffset) >> 1));
              ilInstBOpcode = (*(uint *)(&DAT_001dac38 + opcodeInfoOffset) >> 0x13) << 0x10 | ilInstBOpcode & 0xc000ffff;
              if ((*(uint *)(&DAT_001dac40 + opcodeInfoOffset) >> 0x1c & 2) == 0) {
                if (((currentRecord[1] & 0x100000) != 0) ||
                   (saturate = 0, (*(uint *)(&DAT_001dac40 + opcodeInfoOffset) >> 0x1c & 1) != 0)) {
                  saturate = 1;
                }
                ((int (*)())fpilTranslateDestination)(translator,(int)instructionRecords + recordByteOffset + 8,&ilInstBDst,&ilInstBDstMask,saturate);
              }
              if (operandCount != 0) {
                uVar13 = 0;
                srcOutCursor = &ilInstBSrc0;
                sourceRecordCursor = instructionRecords + recordIndex * 2 + 4;
                do {
                  uVar13 = uVar13 + 1;
                  ((int (*)())fpilTranslateSource)(translator,sourceRecordCursor,srcOutCursor,srcOutCursor + 3);
                  srcOutCursor = srcOutCursor + 1;
                  sourceRecordCursor = sourceRecordCursor + 2;
                } while (operandCount != uVar13);
              }
              (**(code **)(&DAT_001dac3c + opcodeInfoOffset))(translator,recordIndex,ilInstBPtr);
LAB_00048a2c:
              if (translator[9] != 0) {
                return translator[9];
              }
            }
            else {
              opcodeInfoWord0 = *(uint *)(&DAT_001dac34 + opcodeInfoOffset);
              opcodeInfoWord1 = *(uint *)(&DAT_001dac38 + opcodeInfoOffset);
              if (uVar13 == 4) {
                operandCount = operandCount - 1;
              }
              tokenWordCount = operandCount * 2 + 1;
              if (uVar13 != 3) {
                tokenWordCount = operandCount * 2 + 3;
              }
              tokenWordCount = ((int (*)())fpilReserveTokens)(translator,tokenWordCount,&reservedTokens);
              if (tokenWordCount != 0) goto LAB_00048d74;
              *reservedTokens = (opcodeInfoWord1 >> 0x13) << 0x10 | opcodeInfoWord0 >> 1 & 0xffff;
              if ((*(uint *)(&DAT_001dac34 + opcodeInfoOffset) >> 0x11 & 0xf) != 3) {
                if (((currentRecord[1] & 0x100000) != 0) ||
                   (saturate = 0, (*(uint *)(&DAT_001dac40 + opcodeInfoOffset) & 0x10000000) != 0)) {
                  saturate = 1;
                }
                dstStatus = ((int (*)())fpilTranslateDestination)(translator,(int)instructionRecords + recordByteOffset + 8,&dstToken,&dstMask,saturate);
                if (dstStatus != 0) goto LAB_00048d74;
                reservedTokens[1] = dstToken;
                reservedTokens[2] = dstMask;
              }
              if ((*(uint *)(&DAT_001dac34 + opcodeInfoOffset) >> 0x11 & 0xf) == 4) {
                srcSwizzleStatus = ((int (*)())fpilTranslateSourceWithSwizzle)(translator,(int)instructionRecords + recordByteOffset + 0x10,&srcToken,&srcSwizzle,
                                     (int)instructionRecords + recordByteOffset + 0x18);
              }
              else {
                srcSwizzleStatus = ((int (*)())fpilTranslateSource)(translator,(int)instructionRecords + recordByteOffset + 0x10,&srcToken,&srcSwizzle);
              }
              if (srcSwizzleStatus != 0) goto LAB_00048d74;
              uVar13 = *(uint *)(&DAT_001dac34 + opcodeInfoOffset) >> 0x11 & 0xf;
              if (uVar13 == 6) {
                srcSwizzle = srcSwizzle & 0xffff0fff | 0x5000;
              }
              if (uVar13 == 3) {
                reservedTokens[1] = srcToken;
                reservedTokens[2] = srcSwizzle;
              }
              else {
                reservedTokens[3] = srcToken;
                reservedTokens[4] = srcSwizzle;
              }
              if (1 < (int)operandCount) {
                srcStatus = ((int (*)())fpilTranslateSource)(translator,(int)instructionRecords + recordByteOffset + 0x18,&srcToken,&srcSwizzle);
                if (srcStatus != 0) goto LAB_00048d74;
                reservedTokens[5] = srcToken;
                reservedTokens[6] = srcSwizzle;
                if (2 < (int)operandCount) {
                  srcStatus = ((int (*)())fpilTranslateSource)(translator,(int)instructionRecords + recordByteOffset + 0x20,&srcToken,&srcSwizzle);
                  if (srcStatus != 0) goto LAB_00048d74;
                  reservedTokens[7] = srcToken;
                  reservedTokens[8] = srcSwizzle;
                }
              }
            }
            goto LAB_00048c70;
          }
          if (opcode == 0) {
            ilInstAPtr = &ilInstAOpcode;
            iVar24 = *translator + *(int *)(*translator + 0x54) * 8;
            _memset(ilInstAPtr,0,0x24);
            iVar23 = recordByteOffset + iVar24;
            iVar24 = iVar24 + recordByteOffset;
            ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),0x47);
            callStatus = ((int (*)())fpilTranslateDestination)(translator,iVar24 + 8,&ilInstADst,&ilInstADstMask,
                                 *(uint *)(iVar23 + 4) >> 0x14 & 1);
            if ((callStatus == 0) &&
               (callStatus = ((int (*)())fpilTranslateSource)(translator,iVar24 + 0x10,&ilInstASrc0,&ilInstASwz0), callStatus == 0)) {
              if (((translator[5] & 0x20000000U) == 0) ||
                 (uVar13 = *(uint *)(iVar23 + 4), (uVar13 & 0x10000000) == 0)) {
                iVar6 = 1;
              }
              else {
                iVar6 = (uVar13 >> 0x1a & 3) + 1;
                if (iVar6 == 0) goto LAB_00048c78;
              }
              iVar23 = 0;
              do {
                emitStatus3 = ((int (*)())fpilEmitInstruction)(translator,ilInstAPtr,1,1);
                if (emitStatus3 != 0) goto LAB_00048418;
                iVar23 = iVar23 + 1;
                ilInstADst = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstADst) + 0)),(*(unsigned short *)((unsigned char *)&(ilInstADst) + 2)) + 1);
                ilInstASrc0 = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstASrc0) + 0)),(*(unsigned short *)((unsigned char *)&(ilInstASrc0) + 2)) + 1);
              } while (iVar6 != iVar23);
              goto LAB_00048c78;
            }
LAB_00048418:
            if (translator[9] != 0) {
              return translator[9];
            }
            goto LAB_00048c78;
          }
          if (opcode == 0x40) {
            instructionBlock2 = *translator + *(int *)(*translator + 0x54) * 8;
            dstStatus = ((int (*)())fpilTranslateDestination)(translator,instructionBlock2 + recordByteOffset + 8,&dstToken2,&dstMask2,
                                 *(uint *)(recordByteOffset + instructionBlock2 + 4) >> 0x14 & 1);
            if (dstStatus == 0) {
              ilInstAPtr = &ilInstAOpcode;
              srcWordOffset = 0;
              instructionBlock2 = recordIndex * 8 + instructionBlock2 + 0x10;
              do {
                srcStatus3 = ((int (*)())fpilTranslateSource)(translator,instructionBlock2,srcWordOffset + (int)ilInstAPtr,(int)&local_e0 + srcWordOffset);
                if (srcStatus3 != 0) goto LAB_00048418;
                moreSources = srcWordOffset != 8;
                instructionBlock2 = instructionBlock2 + 8;
                srcWordOffset = srcWordOffset + 4;
              } while (moreSources);
              tempRegBase = translator[8];
              iVar24 = 0;
              iVar23 = 0;
              ilInstBPtr = &ilInstBOpcode;
              dstOutPair = &dstToken;
              do {
                tempRegisterIndex = (short)tempRegBase + (short)iVar24;
                moreTemps = iVar24 != 2;
                iVar24 = iVar24 + 1;
                *(undefined4 *)(iVar23 + (int)ilInstBPtr) = 0;
                dstOutPair[0xd] = dstOutPair[0xd] & 0xffc0ffff | 0x40000;
                *(short *)((int)dstOutPair + 0x36) = tempRegisterIndex;
                *(undefined4 *)((int)&local_ec + iVar23) = 0;
                iVar23 = iVar23 + 4;
                dstOutPair[7] = dstOutPair[7] & 0xffc0ffff | 0x40000;
                *(short *)((int)dstOutPair + 0x1e) = tempRegisterIndex;
                dstOutPair[7] = dstOutPair[7] | 0x400000;
                dstOutPair = dstOutPair + 1;
              } while (moreTemps);
              reserveStatus = ((int (*)())fpilReserveTokens)(translator,7,&reservedTokens);
              uVar13 = local_ec;
              if (reserveStatus == 0) {
                *reservedTokens = 0x5b;
                reservedTokens[1] = local_ec;
                reservedTokens[2] = dstMask2;
                reservedTokens[3] = ilInstADstMask;
                reservedTokens[4] = local_d8;
                reservedTokens[5] = ilInstAOpcode;
                reservedTokens[6] = local_e0;
                reserveStatus = ((int (*)())fpilReserveTokens)(translator,7,&reservedTokens);
                if (reserveStatus == 0) {
                  *reservedTokens = 0x5b;
                  local_6c = local_e8;
                  reservedTokens[1] = local_e8;
                  reservedTokens[2] = dstMask2;
                  reservedTokens[3] = ilInstADst;
                  reservedTokens[4] = local_dc;
                  reservedTokens[5] = ilInstAOpcode;
                  reservedTokens[6] = local_e0;
                  dstMask2 = dstMask2 | 0x100;
                  reserveStatus = ((int (*)())fpilReserveTokens)(translator,5,&reservedTokens);
                  uVar22 = ilInstBOpcode;
                  if (reserveStatus == 0) {
                    *reservedTokens = 0x20;
                    reservedTokens[1] = uVar13;
                    reservedTokens[2] = dstMask2;
                    reservedTokens[3] = ilInstBOpcode;
                    local_70 = ilInstBDst;
                    reservedTokens[4] = ilInstBDst;
                    dstMask2 = dstMask2 & 0xfffffeff;
                    reserveStatus = ((int (*)())fpilReserveTokens)(translator,5,&reservedTokens);
                    if (reserveStatus == 0) {
                      *reservedTokens = 3;
                      reservedTokens[1] = local_6c;
                      reservedTokens[2] = dstMask2;
                      reservedTokens[3] = uVar22;
                      reservedTokens[4] = uVar22;
                      reserveStatus = ((int (*)())fpilReserveTokens)(translator,5,&reservedTokens);
                      if (reserveStatus == 0) {
                        *reservedTokens = 0x49;
                        reservedTokens[1] = uVar13;
                        reservedTokens[2] = dstMask2;
                        reservedTokens[3] = uVar22;
                        reservedTokens[4] = uVar22;
                        reserveStatus = ((int (*)())fpilReserveTokens)(translator,5,&reservedTokens);
                        uVar13 = ilInstBOpcode;
                        if (reserveStatus == 0) {
                          *reservedTokens = 0x49;
                          reservedTokens[1] = local_6c;
                          reservedTokens[2] = dstMask2;
                          reservedTokens[3] = uVar22;
                          reservedTokens[4] = local_70;
                          reserveStatus = ((int (*)())fpilReserveTokens)(translator,7,&reservedTokens);
                          if (reserveStatus == 0) {
                            *reservedTokens = 0x23;
                            reservedTokens[1] = local_e4;
                            reservedTokens[2] = dstMask2;
                            reservedTokens[3] = uVar13 | 0x400000;
                            reservedTokens[4] = (uint)((unsigned char *)0x00004555);
                            reservedTokens[5] = uVar13 | 0x400000;
                            reservedTokens[6] = (uint)((unsigned char *)0x00004555);
                            ilInstBDst = ilInstBDst | 0x400000;
                            reserveStatus = ((int (*)())fpilReserveTokens)(translator,7,&reservedTokens);
                            if (reserveStatus == 0) {
                              *reservedTokens = 0x40;
                              reservedTokens[1] = dstToken2;
                              reservedTokens[2] = dstMask2;
                              reservedTokens[3] = ilInstBOpcode;
                              reservedTokens[4] = ilInstBDstMask;
                              reservedTokens[5] = ilInstBDst;
                              reservedTokens[6] = 0xba98;
                              goto LAB_00048c78;
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            goto LAB_00048418;
          }
          if (opcode == 0x22) {
            instructionBlock2 = *translator + *(int *)(*translator + 0x54) * 8;
            iVar24 = instructionBlock2 + recordByteOffset;
            src0OperandPtr = (uint *)(iVar24 + 0x10);
            arraySourceCount = (*(uint *)(iVar24 + 0x10) >> 0xe & 1) + (*(uint *)(iVar24 + 0x18) >> 0xe & 1);
            if ((arraySourceCount == 1) &&
               (((*(uint *)(iVar24 + 0x10) & 0x3000) == 0 ||
                ((*(uint *)(iVar24 + 0x18) & 0x3000) == 0)))) {
              iVar6 = ((int (*)())fragmentTranslateArithmetic)(translator,recordIndex);
              goto joined_r0x00048448;
            }
            ilInstBPtr = &ilInstBOpcode;
            _memset(ilInstBPtr,0,0x24);
            ilInstBOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstBOpcode) + 0)),0x49);
            instructionBlock2 = ((int (*)())fpilTranslateDestination)(translator,iVar24 + 8,&ilInstBDst,&ilInstBDstMask,
                                  *(uint *)(recordByteOffset + instructionBlock2 + 4) >> 0x14 & 1);
            if (((instructionBlock2 != 0) ||
                (instructionBlock2 = ((int (*)())fpilTranslateSource)(translator,src0OperandPtr,&ilInstBSrc0,&ilInstBSwz0), instructionBlock2 != 0)) ||
               (instructionBlock2 = ((int (*)())fpilTranslateSource)(translator,(uint *)(iVar24 + 0x18),&ilInstBSrc1,ilInstBSwz12),
               uVar22 = ilInstBDstMask, uVar13 = ilInstBDst, instructionBlock2 != 0)) {
LAB_000479ec:
              iVar6 = translator[9];
              goto joined_r0x00048448;
            }
            if (arraySourceCount == 0) {
              emitStatus = ((int (*)())fpilEmitInstruction)(translator,ilInstBPtr,1,2);
joined_r0x000479e8:
              if (emitStatus != 0) goto LAB_000479ec;
            }
            else if (arraySourceCount != 1) {
              tempRegisterHalf = (undefined2)translator[8];
              ilInstBDst = CONCAT22(4,tempRegisterHalf);
              savedDstToken = uVar13;
              regSpan = (*src0OperandPtr >> 0xc & 3) + 1;
              newTempBase = regSpan + translator[8];
              savedDstMask = ilInstBDstMask;
              translator[8] = newTempBase;
              ilInstBDstMask = 0x55;
              ilInstBDst = ilInstBDst | 0x400000;
              if (regSpan != 0) {
                ilInstAPtr = &ilInstAOpcode;
                iVar6 = 0;
                do {
                  uVar22 = *src0OperandPtr >> 0xc & 3;
                  _memcpy(ilInstAPtr,ilInstBPtr,0x24);
                  tempRegister = translator[8];
                  uVar13 = (uint)ilInstBSwz12[0] >> 3 & 1;
                  ilInstADst = CONCAT22(4,(short)tempRegister);
                  ilInstADstMask = 0x55;
                  ilInstASwz1 = (undefined *)
                             (uVar13 << 0xf |
                             ((uint)ilInstBSwz12[0] & 7) << 0xc |
                             uVar13 << 0xb |
                             ((uint)ilInstBSwz12[0] & 7) << 8 |
                             uVar13 << 7 |
                             ((uint)ilInstBSwz12[0] & 7) << 4 |
                             uVar13 << 3 | (uint)ilInstBSwz12[0] & 7 | (uint)ilInstASwz1 & 0xffff0000);
                  ilInstADst = ilInstADst | 0x400000;
                  emitStatus3 = ((int (*)())fpilEmitInstruction)(translator,ilInstAPtr,1,2);
                  if (emitStatus3 == 0) {
                    ilInstASrc2 = CONCAT22(4,(short)tempRegister);
                    ilInstASrc0 = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstASrc0) + 0)),(*(unsigned short *)((unsigned char *)&(ilInstASrc0) + 2)) + 1);
                    ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),0x40);
                    ilInstASwz2 = ((unsigned char *)0x00003210);
                    ilInstASrc2 = ilInstASrc2 | 0x400000;
                    if (uVar22 == 1) {
                      ilInstADst = ilInstBDst;
                      ilInstADstMask = ilInstBDstMask;
                    }
                    uVar11 = (uint)ilInstBSwz12[0] >> 4 & 7;
                    uVar13 = (uint)ilInstBSwz12[0] >> 7 & 1;
                    ilInstASwz1 = (undefined *)
                               (uVar13 << 0xf |
                               uVar11 << 0xc |
                               uVar13 << 0xb |
                               uVar11 << 8 |
                               uVar13 << 7 |
                               uVar11 << 4 | uVar13 << 3 | uVar11 | (uint)ilInstASwz1 & 0xffff0000);
                    emitStatus3 = ((int (*)())fpilEmitInstruction)(translator,ilInstAPtr,1,3);
                    if ((emitStatus3 == 0) && (1 < uVar22)) {
                      ilInstASrc0 = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstASrc0) + 0)),(*(unsigned short *)((unsigned char *)&(ilInstASrc0) + 2)) + 1);
                      if (uVar22 == 2) {
                        ilInstADst = ilInstBDst;
                        ilInstADstMask = ilInstBDstMask;
                      }
                      uVar11 = (uint)ilInstBSwz12[0] >> 8 & 7;
                      uVar13 = (uint)ilInstBSwz12[0] >> 0xb & 1;
                      ilInstASwz1 = (undefined *)
                                 (uVar13 << 0xf |
                                 uVar11 << 0xc |
                                 uVar13 << 0xb |
                                 uVar11 << 8 |
                                 uVar13 << 7 |
                                 uVar11 << 4 | uVar13 << 3 | uVar11 | (uint)ilInstASwz1 & 0xffff0000);
                      emitStatus3 = ((int (*)())fpilEmitInstruction)(translator,ilInstAPtr,1,3);
                      if ((emitStatus3 == 0) && (uVar22 == 3)) {
                        uVar22 = (uint)ilInstBSwz12[0] >> 0xc & 7;
                        uVar13 = (uint)ilInstBSwz12[0] >> 0xf & 1;
                        ilInstADst = ilInstBDst;
                        ilInstADstMask = ilInstBDstMask;
                        ilInstASrc0 = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstASrc0) + 0)),(*(unsigned short *)((unsigned char *)&(ilInstASrc0) + 2)) + 1);
                        ilInstASwz1 = (undefined *)
                                   (uVar13 << 0xf |
                                   uVar22 << 0xc |
                                   uVar13 << 0xb |
                                   uVar22 << 8 |
                                   uVar13 << 7 |
                                   uVar22 << 4 | uVar13 << 3 | uVar22 | (uint)ilInstASwz1 & 0xffff0000)
                        ;
                        ((int (*)())fpilEmitInstruction)(translator,ilInstAPtr,1,3);
                      }
                    }
                  }
                  iVar6 = iVar6 + 1;
                  ilInstBDst = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstBDst) + 0)),(*(unsigned short *)((unsigned char *)&(ilInstBDst) + 2)) + 1);
                  ilInstBSrc1 = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstBSrc1) + 0)),(*(unsigned short *)((unsigned char *)&(ilInstBSrc1) + 2)) + 1);
                } while (regSpan != iVar6);
                newTempBase = translator[8];
              }
              ilInstBSrc0 = CONCAT22(4,tempRegisterHalf);
              translator[8] = newTempBase - regSpan;
              ilInstBOpcode = 0x47;
              ilInstBSwz0 = ((unsigned char *)0x00003210);
              ilInstBDst = savedDstToken;
              ilInstBDstMask = savedDstMask;
              ilInstBSrc0 = ilInstBSrc0 | 0x400000;
              if (regSpan != 0) {
                iVar6 = 0;
                do {
                  iVar6 = iVar6 + 1;
                  ((int (*)())fpilEmitInstruction)(translator,ilInstBPtr,1,1);
                  ilInstBDst = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstBDst) + 0)),(*(unsigned short *)((unsigned char *)&(ilInstBDst) + 2)) + 1);
                  ilInstBSrc0 = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstBSrc0) + 0)),(*(unsigned short *)((unsigned char *)&(ilInstBSrc0) + 2)) + 1);
                } while (regSpan != iVar6);
              }
            }
            else {
              if ((*src0OperandPtr & 0x4000) == 0) {
                uVar11 = ilInstBDstMask & 3;
                ilInstBDst = CONCAT22(4,(short)translator[8]);
                ilInstBDstMask = 0;
                ilInstBOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstBOpcode) + 0)),0x23);
                ilInstBDst = ilInstBDst | 0x400000;
                do {
                  iVar6 = 0;
                  bVar1 = uVar11 == 1;
                  while( true ) {
                    if (bVar1) {
                      uVar4 = ilInstBDstMask & 0xffffff00;
                      if (iVar6 == 0) {
                        ilInstBDstMask = uVar4 | 1;
                      }
                      else if (iVar6 == 1) {
                        ilInstBDstMask = uVar4 | 4;
                      }
                      else if (iVar6 == 2) {
                        ilInstBDstMask = uVar4 | 0x10;
                      }
                      else {
                        ilInstBDstMask = ilInstBDstMask & 0xffffff00 | 0x40;
                      }
                      emitStatus2 = ((int (*)())fpilEmitInstruction)(translator,ilInstBPtr,1,2);
                      if (emitStatus2 != 0) goto LAB_000479ec;
                    }
                    iVar6 = iVar6 + 1;
                    ilInstBSrc1 = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstBSrc1) + 0)),(*(unsigned short *)((unsigned char *)&(ilInstBSrc1) + 2)) + 1);
                    if ((int)(*(uint *)(iVar24 + 0x18) >> 0xc & 3) < iVar6) {
                      ilInstBSrc0 = CONCAT22(4,(short)translator[8]);
                      ilInstBOpcode = 0x47;
                      ilInstBSwz0 = ((unsigned char *)0x00003210);
                      ilInstBSrc0 = ilInstBSrc0 | 0x400000;
                      ilInstBDst = uVar13;
                      ilInstBDstMask = uVar22;
                      emitStatus = ((int (*)())fpilEmitInstruction)(translator,ilInstBPtr,1,1);
                      goto joined_r0x000479e8;
                    }
                    if (iVar6 == 0) break;
                    if (iVar6 == 1) {
                      bVar1 = (uVar22 & 0xc) == 4;
                    }
                    else if (iVar6 == 2) {
                      bVar1 = (uVar22 & 0x30) == 0x10;
                    }
                    else {
                      bVar1 = (uVar22 & 0xc0) == 0x40;
                    }
                  }
                } while( true );
              }
              ilInstAPtr = &ilInstAOpcode;
              uVar22 = *src0OperandPtr >> 0xc & 3;
              _memcpy(ilInstAPtr,ilInstBPtr,0x24);
              tempRegBase = translator[8];
              uVar13 = (uint)ilInstBSwz12[0] >> 3 & 1;
              ilInstADst = CONCAT22(4,(short)tempRegBase);
              ilInstADstMask = 0x55;
              ilInstASwz1 = (undefined *)
                         (uVar13 << 0xf |
                         ((uint)ilInstBSwz12[0] & 7) << 0xc |
                         uVar13 << 0xb |
                         ((uint)ilInstBSwz12[0] & 7) << 8 |
                         uVar13 << 7 |
                         ((uint)ilInstBSwz12[0] & 7) << 4 |
                         uVar13 << 3 | (uint)ilInstBSwz12[0] & 7 | (uint)ilInstASwz1 & 0xffff0000);
              ilInstADst = ilInstADst | 0x400000;
              emitStatus2 = ((int (*)())fpilEmitInstruction)(translator,ilInstAPtr,1,2);
              if (emitStatus2 == 0) {
                ilInstASrc2 = CONCAT22(4,(short)tempRegBase);
                ilInstASrc0 = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstASrc0) + 0)),(*(unsigned short *)((unsigned char *)&(ilInstASrc0) + 2)) + 1);
                ilInstASwz2 = ((unsigned char *)0x00003210);
                ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),0x40);
                ilInstASrc2 = ilInstASrc2 | 0x400000;
                if (uVar22 == 1) {
                  ilInstADst = ilInstBDst;
                  ilInstADstMask = ilInstBDstMask;
                }
                uVar11 = (uint)ilInstBSwz12[0] >> 4 & 7;
                uVar13 = (uint)ilInstBSwz12[0] >> 7 & 1;
                ilInstASwz1 = (undefined *)
                           (uVar13 << 0xf |
                           uVar11 << 0xc |
                           uVar13 << 0xb |
                           uVar11 << 8 |
                           uVar13 << 7 |
                           uVar11 << 4 | uVar13 << 3 | uVar11 | (uint)ilInstASwz1 & 0xffff0000);
                emitStatus = ((int (*)())fpilEmitInstruction)(translator,ilInstAPtr,1,3);
                if ((emitStatus == 0) && (1 < uVar22)) {
                  ilInstASrc0 = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstASrc0) + 0)),(*(unsigned short *)((unsigned char *)&(ilInstASrc0) + 2)) + 1);
                  if (uVar22 == 2) {
                    ilInstADst = ilInstBDst;
                    ilInstADstMask = ilInstBDstMask;
                  }
                  uVar11 = (uint)ilInstBSwz12[0] >> 8 & 7;
                  uVar13 = (uint)ilInstBSwz12[0] >> 0xb & 1;
                  ilInstASwz1 = (undefined *)
                             (uVar13 << 0xf |
                             uVar11 << 0xc |
                             uVar13 << 0xb |
                             uVar11 << 8 |
                             uVar13 << 7 |
                             uVar11 << 4 | uVar13 << 3 | uVar11 | (uint)ilInstASwz1 & 0xffff0000);
                  emitStatus = ((int (*)())fpilEmitInstruction)(translator,ilInstAPtr,1,3);
                  if ((emitStatus == 0) && (uVar22 == 3)) {
                    uVar22 = (uint)ilInstBSwz12[0] >> 0xc & 7;
                    uVar13 = (uint)ilInstBSwz12[0] >> 0xf & 1;
                    ilInstADst = ilInstBDst;
                    ilInstADstMask = ilInstBDstMask;
                    ilInstASrc0 = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstASrc0) + 0)),(*(unsigned short *)((unsigned char *)&(ilInstASrc0) + 2)) + 1);
                    ilInstASwz1 = (undefined *)
                               (uVar13 << 0xf |
                               uVar22 << 0xc |
                               uVar13 << 0xb |
                               uVar22 << 8 |
                               uVar13 << 7 |
                               uVar22 << 4 | uVar13 << 3 | uVar22 | (uint)ilInstASwz1 & 0xffff0000);
                    ((int (*)())fpilEmitInstruction)(translator,ilInstAPtr,1,3);
                  }
                }
              }
            }
            goto LAB_00048c78;
          }
          if (((opcode - 0x1f < 2) || (opcode == 0x23)) || (opcode == 0x3a)) {
            iVar6 = ((int (*)())fragmentTranslateArithmetic)(translator,recordIndex);
            goto joined_r0x0004802c;
          }
          if (opcode == 0x6c) {
            ilInstAPtr = &ilInstAOpcode;
            instructionBlock4 = *translator + *(int *)(*translator + 0x54) * 8;
            _memset(ilInstAPtr,0,0x24);
            iVar23 = instructionBlock4 + recordByteOffset;
            iVar24 = iVar23 + 8;
            iVar6 = ((int (*)())fpilClassifyDestination)(translator,iVar24);
            if (iVar6 == 1) {
              ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),99);
            }
            else if (iVar6 == 2) {
              ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),0x56);
              ilInstAOpcode = ilInstAOpcode & 0xc000ffff;
            }
            else {
              ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),0x47);
            }
            iVar24 = ((int (*)())fpilTranslateDestination)(translator,iVar24,&ilInstADst,&ilInstADstMask,
                                  *(uint *)(recordByteOffset + instructionBlock4 + 4) >> 0x14 & 1);
            if ((iVar24 == 0) &&
               (iVar23 = ((int (*)())fpilTranslateSource)(translator,iVar23 + 0x10,&ilInstASrc0,&ilInstASwz0), iVar23 == 0)) {
              emittedSourceCount = 1;
              if (iVar6 == 2) {
                emittedSourceCount = 2;
                ilInstASwz1 = (undefined *)((uint)ilInstASwz1 & 0xffff0000 | 0x4444);
                ilInstASrc1 = CONCAT22((short)(ilInstASrc1 >> 0x10),(short)translator[8]) & 0xffc0ffff |
                           0x440000;
              }
              emitStatus = ((int (*)())fpilEmitInstruction)(translator,ilInstAPtr,1,emittedSourceCount);
              goto joined_r0x00048414;
            }
            goto LAB_00048418;
          }
          if (opcode == 8) {
            iVar6 = ((int (*)())fragmentTranslateAny)(translator,recordIndex,0);
joined_r0x00048448:
            if (iVar6 != 0) {
LAB_00048d74:
              return translator[9];
            }
            goto LAB_00048c78;
          }
          if (opcode == 9) {
            iVar6 = ((int (*)())fragmentTranslateAll)(translator,recordIndex,0);
            goto joined_r0x00048448;
          }
          if (opcode == 10) {
            ilInstAPtr = &ilInstAOpcode;
            programPtr = *translator;
            instBlockOffset = *(int *)(programPtr + 0x54);
            _memset(ilInstAPtr,0,0x24);
            programPtr = programPtr + instBlockOffset * 8 + recordByteOffset;
            ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),0x5b);
            dstStatus = ((int (*)())fpilTranslateDestination)(translator,programPtr + 8,&ilInstADst,&ilInstADstMask,1);
            if (dstStatus == 0) {
              ilInstASwz0 = (undefined *)((uint)ilInstASwz0 & 0xffff0000 | 0x5555);
              ilInstASrc0 = CONCAT22((short)(ilInstASrc0 >> 0x10),(short)translator[8]) & 0xffc0ffff |
                         0x440000;
              srcStatus = ((int (*)())fpilTranslateSource)(translator,programPtr + 0x10,&ilInstASrc1,&ilInstASwz1);
              if (srcStatus == 0) {
                emitStatus = ((int (*)())fpilEmitInstruction)(translator,ilInstAPtr,1,2);
joined_r0x00048414:
                if (emitStatus == 0) goto LAB_00048c78;
              }
            }
            goto LAB_00048418;
          }
          if (opcode == 0x26) {
            ilInstAPtr = &ilInstAOpcode;
            programPtr = *translator;
            instBlockOffset = *(int *)(programPtr + 0x54);
            _memset(ilInstAPtr,0,0x24);
            programPtr = programPtr + instBlockOffset * 8 + recordByteOffset;
            ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),0x5b);
            ilInstADstMask = ilInstADstMask & 0xffffff00 | 0x55;
            ilInstADst = CONCAT22((short)(ilInstADst >> 0x10),(short)translator[8]) & 0xffc0ffff | 0x440000
            ;
            callStatus = ((int (*)())fpilTranslateSource)(translator,programPtr + 0x10,&ilInstASrc0,&ilInstASwz0);
            if (((callStatus == 0) &&
                (callStatus = ((int (*)())fpilTranslateSource)(translator,programPtr + 0x18,&ilInstASrc1,&ilInstASwz1), callStatus == 0)) &&
               (callStatus = ((int (*)())fpilEmitInstruction)(translator,ilInstAPtr,1,2), callStatus == 0)) {
              ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),1);
              dstStatus = ((int (*)())fpilTranslateDestination)(translator,programPtr + 8,&ilInstADst,&ilInstADstMask,1);
              if (dstStatus == 0) {
                ilInstASrc0 = CONCAT22(4,(short)translator[8]);
                ilInstASwz0 = ((unsigned char *)0x00003210);
                ilInstASrc0 = ilInstASrc0 | 0x400000;
                emitStatus = ((int (*)())fpilEmitInstruction)(translator,ilInstAPtr,1,1);
                goto joined_r0x00048414;
              }
            }
            goto LAB_00048418;
          }
          if (opcode == 0x39) {
            iVar6 = ((int (*)())fragmentTranslateSel)(translator,recordIndex);
            goto joined_r0x00048448;
          }
          if (opcode == 0x6d) {
            iVar6 = ((int (*)())fragmentTranslateDsl)(translator,recordIndex);
            goto joined_r0x00048448;
          }
          if ((opcode == 0x31) || (opcode == 0x36)) {
            instructionBlock = *translator + *(int *)(*translator + 0x54) * 8;
            if ((translator[5] & 0x20000000U) == 0) {
              src1Advances = 0;
              src0Advances = 0;
            }
            else {
              src0Advances = *(uint *)(instructionBlock + recordByteOffset + 0x10) >> 0xe & 1;
              src1Advances = *(uint *)(instructionBlock + recordByteOffset + 0x18) >> 0xe & 1;
            }
            src0Operand = (uint *)(recordByteOffset + instructionBlock + 0x10);
            src1OperandPtr = (uint *)(recordByteOffset + instructionBlock + 0x18);
            instHeader = (uint *)(recordByteOffset + instructionBlock);
            ilInstAPtr = &ilInstAOpcode;
            dstRegSpan = (instHeader[1] >> 0x1a & 3) + 1;
            src0RegSpan = (*src0Operand >> 0xc & 3) + 1;
            src1RegSpan = (*src1OperandPtr >> 0xc & 3) + 1;
            _memset(ilInstAPtr,0,0x24);
            ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),0x56);
            ilInstAOpcode = (uint)((*(uint *)(recordByteOffset + instructionBlock) & 0x3fc0000) == 0xc40000) << 0x10 |
                       ilInstAOpcode & 0xc000ffff;
            srcStatus2 = ((int (*)())fpilTranslateSource)(translator,src0Operand,&ilInstASrc0,&ilInstASwz0);
            if ((srcStatus2 == 0) &&
               (srcStatus2 = ((int (*)())fpilTranslateSource)(translator,src1OperandPtr,&ilInstASrc1,&ilInstASwz1), srcStatus2 == 0)) {
              if (dstRegSpan < 2) {
                ilInstADst = CONCAT22(4,(short)translator[8]);
                ilInstADstMask = 0x55;
                ilInstADst = ilInstADst | 0x400000;
                emitStatus2 = ((int (*)())fpilEmitInstruction)(translator,ilInstAPtr,1,2);
                if (emitStatus2 == 0) {
                  maxRegSpan = src0RegSpan;
                  if (src0RegSpan < src1RegSpan) {
                    maxRegSpan = src1RegSpan;
                  }
                  advanceSrc0 = src0Advances != 0;
                  if (((advanceSrc0) || (src1Advances != 0)) && (1 < maxRegSpan)) {
                    ilInstBPtr = &ilInstBOpcode;
                    ilInstADst = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstADst) + 0)),(short)translator[8] + 1);
                    _memset(ilInstBPtr,0,0x24);
                    ilSelectOpcode = 0x49;
                    if ((*(uint *)(recordByteOffset + instructionBlock) & 0x3fc0000) != 0xc40000) {
                      ilSelectOpcode = 3;
                    }
                    ilInstBOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstBOpcode) + 0)),ilSelectOpcode);
                    tempRegisterBase = (short)translator[8];
                    ilInstBDst = CONCAT22(4,tempRegisterBase);
                    iVar6 = 1;
                    ilInstBSrc1 = CONCAT22(4,tempRegisterBase + 1);
                    ilInstBSrc0 = CONCAT22(4,tempRegisterBase);
                    ilInstBDstMask = 0x55;
                    advanceSrc1 = src1Advances != 0;
                    ilInstBSwz12[0] = ((unsigned char *)0x00003210);
                    ilInstBSwz0 = ((unsigned char *)0x00003210);
                    ilInstBDst = ilInstBDst | 0x400000;
                    ilInstBSrc1 = ilInstBSrc1 | 0x400000;
                    ilInstBSrc0 = ilInstBSrc0 | 0x400000;
                    do {
                      if (advanceSrc0) {
                        ilInstASrc0 = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstASrc0) + 0)),(*(unsigned short *)((unsigned char *)&(ilInstASrc0) + 2)) + 1);
                      }
                      if (advanceSrc1) {
                        ilInstASrc1 = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstASrc1) + 0)),(*(unsigned short *)((unsigned char *)&(ilInstASrc1) + 2)) + 1);
                      }
                      emitStatus3 = ((int (*)())fpilEmitInstruction)(translator,ilInstAPtr,1,2);
                      if ((emitStatus3 != 0) ||
                         (emitStatus3 = ((int (*)())fpilEmitInstruction)(translator,ilInstBPtr,1,2), emitStatus3 != 0))
                      goto LAB_000488e8;
                      iVar6 = iVar6 + 1;
                    } while (maxRegSpan != iVar6);
                  }
                  if ((*instHeader & 0x3fc0000) == 0xc40000) {
                    iVar6 = ((int (*)())fragmentTranslateAll)(translator,recordIndex,maxRegSpan);
                    goto joined_r0x0004802c;
                  }
                  ilInstBPtr = &ilInstBOpcode;
                  programPtr = *translator;
                  instBlockOffset = *(int *)(programPtr + 0x54);
                  _memset(ilInstBPtr,0,0x24);
                  ilInstBOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstBOpcode) + 0)),0x23);
                  instBlockOffset = ((int (*)())fpilTranslateDestination)(translator,programPtr + instBlockOffset * 8 + recordByteOffset + 8,&ilInstBDst,&ilInstBDstMask,1)
                  ;
                  if (instBlockOffset == 0) {
                    ilInstBSrc0 = CONCAT22(4,(short)translator[8]);
                    ilInstBSwz0 = ((unsigned char *)0x00003210);
                    ilInstBSwz12[0] = (undefined *)((uint)ilInstBSwz12[0] & 0xffff0000 | 0x5555);
                    ilInstBSrc0 = ilInstBSrc0 | 0x400000;
                    ilInstBSrc1 = CONCAT22((short)(ilInstBSrc1 >> 0x10),(short)translator[8]) & 0xffc0ffff |
                               0x440000;
                    emitStatus = ((int (*)())fpilEmitInstruction)(translator,ilInstBPtr,1,2);
                    if (emitStatus == 0) goto LAB_00048c70;
                  }
                }
                goto LAB_000488e8;
              }
              ((int (*)())fpilTranslateDestination)(translator,recordByteOffset + instructionBlock + 8,&ilInstADst,&ilInstADstMask,0);
              ((int (*)())fpilEmitInstruction)(translator,ilInstAPtr,1,2);
              iVar6 = translator[9];
            }
            else {
LAB_000488e8:
              iVar6 = translator[9];
            }
joined_r0x0004802c:
            if (iVar6 != 0) goto LAB_00048d74;
            goto LAB_00048c70;
          }
          if (opcode != 0x4d) break;
        }
        instructionIndex = instructionIndex + 1;
        recordIndex = recordIndex + recordSpan;
        if (instructionCount == instructionIndex) goto LAB_00048d20;
        recordByteOffset = recordIndex * 8;
        currentRecord = instructionRecords + recordIndex * 2;
        opcode = instructionRecords[recordIndex * 2] >> 0x12 & 0xff;
        opcodeInfoOffset = opcode * 0x10;
        uVar13 = *(uint *)(&DAT_001dac34 + opcodeInfoOffset) >> 0x11 & 0xf;
        if ((uVar13 == 0) || ((*(uint *)(&DAT_001dac40 + opcodeInfoOffset) >> 0x1c & DAT_001db344) != 0))
        break;
      } while( true );
    }
    returnCode = translator[9];
    if (returnCode == 0) {
      returnCode = 3;
      translator[9] = 3;
    }
  }
  return returnCode;
}

/* fragmentProgramToIL @ 0x48da0 (6552 bytes) */
int fragmentProgramToIL(translator)
  int *translator;
{
  bool moreChannels;
  uint channelIndex;
  uint translatorFlags;
  uint fogMode;
  uint outputIndex;
  uint *outputEntry;
  uint outputCount;
  uint constantIndex;
  uint paramTypeBits;
  uint paramIndex;
  uint *paramEntry;
  uint paramCount;
  uint requiredTokenWords;
  uint *attribEntry;
  int attribRemaining;
  int outputRemaining;
  int optionEntry;
  int optionCount;
  int allocation2;
  int allocation;
  uint tokenCapacity4;
  uint tokenCapacity3;
  uint tokenCapacity;
  undefined4 *tokenWritePtr2;
  int *tokenDataPtrAddr;
  int tokenCount3;
  int translatorError3;
  int translatorError2;
  int tokenCount2;
  int translatorError;
  int tokenCount;
  undefined **ppuVar1;
  undefined4 *puVar2;
  bool bVar3;
  ushort attribBinding;
  short sVar5;
  undefined2 uVar6;
  short sVar7;
  double intToDoubleBias;
  uint uVar9;
  uint *outputScanEntry;
  uint tokenCapacity2;
  int iVar12;
  int iVar13;
  uint uVar14;
  undefined4 in_r4;
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
  int in_r5;
  undefined4 in_r6;
  undefined4 *tokenWritePtr;
  dword *pdVar16;
  int iVar17;
  uint paramKind;
  undefined4 *puVar19;
  undefined **ppuVar20;
  int *program;
  undefined *puVar22;
  uint uVar23;
  undefined4 uVar24;
  uint uVar25;
  undefined4 *tokenWritePtr3;
  int iVar27;
  undefined4 ilInstAOpcode;
  undefined4 ilInstADst;
  uint ilInstADstMask;
  undefined4 ilInstASrc0;
  undefined4 ilInstASrc1;
  undefined4 ilInstASrc2;
  undefined *local_a0 [10];
  undefined4 intToDoubleHiA;
  uint intToDoubleLoA;
  undefined4 intToDoubleHiB;
  uint intToDoubleLoB;
  undefined4 intToDoubleHiC;
  uint intToDoubleLoC;
  undefined4 intToDoubleHiD;
  uint intToDoubleLoD;
  
  program = (int *)*translator;
  if (program == (int *)0x0) {
    if (translator[9] != 0) {
      return translator[9];
    }
    translator[9] = 2;
    return 2;
  }
  translator[8] = program[4] + program[0xc] + 1;
  iVar12 = *program;
  if ((iVar12 != 0x8804) && (iVar12 != 0x8b30)) {
switchD_00049180_caseD_0:
    if (translator[9] != 0) {
      return translator[9];
    }
LAB_0004a4ec:
    translator[9] = 3;
    return 3;
  }
  tokenDataPtrAddr = translator + 10;
  translator[5] = (uint)(iVar12 - 0x8b30U < 2) << 0x1d | translator[5] & 0xdfffffffU;
  tokenCount = translator[0xb];
  tokenCapacity = translator[0xc];
  if (tokenCapacity < tokenCount + 2U) {
    if (tokenCapacity == 0) {
      tokenCapacity = 0x10;
    }
    else {
      tokenCapacity = tokenCapacity << 1;
    }
    for (; tokenCapacity < tokenCount + 2U; tokenCapacity = tokenCapacity << 1) {
    }
    if (*tokenDataPtrAddr == 0) {
      allocation = _malloc(tokenCapacity << 2);
      in_r4 = extraout_r4;
    }
    else {
      allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
      in_r4 = extraout_r4_00;
    }
    if (allocation != 0) {
      *tokenDataPtrAddr = allocation;
      translator[0xc] = tokenCapacity;
      tokenCount = translator[0xb];
      goto LAB_00048eb4;
    }
    translatorError = translator[9];
    if (translatorError == 0) {
      translatorError = 1;
      translator[9] = 1;
    }
    if (translatorError != 0) {
      return translatorError;
    }
    tokenWritePtr3 = (undefined4 *)0x0;
    pdVar16 = ((unsigned char *)0x4);
  }
  else {
LAB_00048eb4:
    translator[0xb] = tokenCount + 2;
    tokenWritePtr3 = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
    pdVar16 = tokenWritePtr3 + 1;
  }
  *tokenWritePtr3 = 1;
  *pdVar16 = 0x10200;
  iVar27 = *translator;
  outputRemaining = *(int *)(iVar27 + 0x30);
  outputScanEntry = (uint *)(iVar27 + *(int *)(iVar27 + 0x34) * 8);
  if (0 < outputRemaining) {
    do {
      if (((*outputScanEntry >> 0x10 & 0xf) == 4) && ((*outputScanEntry & 0xe) != 0)) {
        *(uint *)(translator[0xd] + 0x20) = *(uint *)(translator[0xd] + 0x20) | 0x400000;
        iVar27 = *translator;
        break;
      }
      outputScanEntry = outputScanEntry + 2;
      outputRemaining = outputRemaining + -1;
    } while (outputRemaining != 0);
  }
  optionCount = *(int *)(iVar27 + 0x48);
  optionEntry = iVar27 + *(int *)(iVar27 + 0x4c) * 8;
  if (0 < optionCount) {
    do {
      switch(*(undefined1 *)(optionEntry + 3)) {
      case 0:
      case 8:
      case 10:
        translatorError = translator[9];
        if (translatorError == 0) goto LAB_0004a4ec;
        if (translatorError != 0) {
          return translatorError;
        }
        goto LAB_00049048;
      case 1:
        translator[5] = translator[5] & 0xe7ffffffU | 0x10000000;
        break;
      case 2:
        translator[5] = translator[5] & 0xe7ffffffU | 0x18000000;
        break;
      case 3:
        translator[5] = translator[5] & 0xe7ffffffU | 0x8000000;
      }
      optionCount = optionCount + -1;
      optionEntry = optionEntry + 8;
    } while (optionCount != 0);
  }
LAB_00049048:
  attribRemaining = *(int *)(iVar27 + 0x20);
  tokenCount2 = translator[0xb];
  tokenCapacity = translator[0xc];
  requiredTokenWords = attribRemaining * 2 + tokenCount2;
  attribEntry = (uint *)(iVar27 + *(int *)(iVar27 + 0x24) * 8);
  if (tokenCapacity < requiredTokenWords) {
    if (tokenCapacity == 0) {
      tokenCapacity = 0x10;
    }
    else {
      tokenCapacity = tokenCapacity << 1;
    }
    for (; tokenCapacity < requiredTokenWords; tokenCapacity = tokenCapacity << 1) {
    }
    if (*tokenDataPtrAddr == 0) {
      allocation2 = _malloc(tokenCapacity << 2);
      in_r4 = extraout_r4_01;
    }
    else {
      allocation2 = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
      in_r4 = extraout_r4_02;
    }
    if (allocation2 == 0) goto LAB_0004a55c;
    *tokenDataPtrAddr = allocation2;
    translator[0xc] = tokenCapacity;
    tokenCount2 = translator[0xb];
  }
  translator[0xb] = attribRemaining * 2 + tokenCount2;
  tokenWritePtr = (undefined4 *)(tokenCount2 * 4 + *tokenDataPtrAddr);
  if (attribRemaining < 1) {
LAB_0004921c:
    if ((translator[5] & 0x18000000U) != 0) {
      tokenCount = translator[0xb];
      tokenCapacity = translator[0xc];
      if (tokenCapacity < tokenCount + 2U) {
        if (tokenCapacity == 0) {
          tokenCapacity = 0x10;
        }
        else {
          tokenCapacity = tokenCapacity << 1;
        }
        for (; tokenCapacity < tokenCount + 2U; tokenCapacity = tokenCapacity << 1) {
        }
        if (*tokenDataPtrAddr == 0) {
          allocation = _malloc(tokenCapacity << 2);
          in_r4 = extraout_r4_03;
        }
        else {
          allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
          in_r4 = extraout_r4_04;
        }
        if (allocation == 0) goto LAB_0004a55c;
        *tokenDataPtrAddr = allocation;
        translator[0xc] = tokenCapacity;
        tokenCount = translator[0xb];
      }
      translator[0xb] = tokenCount + 2;
      tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
      *tokenWritePtr = 0x1ff0016;
      tokenWritePtr[1] = 0x100000;
    }
  }
  else {
    in_r5 = 0;
    do {
      attribBinding = *(ushort *)attribEntry;
      if ((attribBinding & 0xf) == 1) {
        *tokenWritePtr = 0x3ff0016;
switchD_00049180_caseD_1:
        puVar22 = ((unsigned char *)0x00160000);
      }
      else {
        *tokenWritePtr = 0x1ff0016;
        switch(attribBinding & 0xf) {
        default:
          goto switchD_00049180_caseD_0;
        case 1:
          goto switchD_00049180_caseD_1;
        case 2:
          puVar22 = (undefined *)0x120000;
          break;
        case 3:
          puVar22 = (undefined *)0x130000;
          break;
        case 5:
          in_r5 = 1;
          puVar22 = (undefined *)0x100000;
          break;
        case 7:
          puVar22 = (undefined *)(*attribEntry & 0x1f | 0x110000);
        }
      }
      attribRemaining = attribRemaining + -1;
      tokenWritePtr[1] = puVar22;
      tokenWritePtr = tokenWritePtr + 2;
      attribEntry = attribEntry + 2;
    } while (attribRemaining != 0);
    in_r6 = 0;
    if (in_r5 == 0) goto LAB_0004921c;
  }
  uVar9 = translator[1];
  uVar14 = translator[2];
  tokenWritePtr2 = (undefined4 *)0x0;
  iVar27 = 0x10;
  iVar12 = 0;
  do {
    iVar13 = iVar12;
    switch(uVar14 & 0xf) {
    case 0:
      tokenWritePtr = &ilInstAOpcode;
      iVar13 = iVar12 + 1;
      tokenWritePtr[iVar12] = (int)tokenWritePtr2 << 0x10 | 0xc000019;
      break;
    case 1:
      tokenWritePtr = &ilInstAOpcode;
      iVar13 = iVar12 + 1;
      tokenWritePtr[iVar12] = (int)tokenWritePtr2 << 0x10 | 0xb000019;
      break;
    case 2:
      tokenWritePtr = &ilInstAOpcode;
      iVar13 = iVar12 + 1;
      tokenWritePtr[iVar12] = (int)tokenWritePtr2 << 0x10 | 0x12000019;
      break;
    case 3:
      tokenWritePtr = &ilInstAOpcode;
      iVar13 = iVar12 + 1;
      tokenWritePtr[iVar12] = (int)tokenWritePtr2 << 0x10 | 0xa000019;
      break;
    case 4:
      tokenWritePtr = &ilInstAOpcode;
      iVar13 = iVar12 + 1;
      tokenWritePtr[iVar12] = (int)tokenWritePtr2 << 0x10 | 0x9000019;
    }
    iVar27 = iVar27 + -1;
    uVar23 = uVar9 << 0x1c;
    uVar9 = uVar9 >> 4;
    tokenWritePtr2 = (undefined4 *)((int)tokenWritePtr2 + 1);
    uVar14 = uVar23 | uVar14 >> 4;
    iVar12 = iVar13;
  } while (iVar27 != 0);
  tokenCount = translator[0xb];
  tokenCapacity = translator[0xc];
  if (tokenCapacity < (uint)(iVar13 + tokenCount)) {
    if (tokenCapacity == 0) {
      tokenCapacity = 0x10;
    }
    else {
      tokenCapacity = tokenCapacity << 1;
    }
    for (; tokenCapacity < (uint)(iVar13 + tokenCount); tokenCapacity = tokenCapacity << 1) {
    }
    if (*tokenDataPtrAddr == 0) {
      allocation2 = _malloc(tokenCapacity << 2);
      in_r4 = extraout_r4_05;
    }
    else {
      allocation2 = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
      in_r4 = extraout_r4_06;
    }
    if (allocation2 != 0) {
      *tokenDataPtrAddr = allocation2;
      translator[0xc] = tokenCapacity;
      tokenCount = translator[0xb];
      goto LAB_00049448;
    }
    translatorError2 = translator[9];
    if (translatorError2 == 0) {
      translatorError2 = 1;
      translator[9] = 1;
    }
    iVar27 = 0;
    if (translatorError2 != 0) {
      return translatorError2;
    }
  }
  else {
LAB_00049448:
    iVar27 = tokenCount * 4;
    tokenCount = iVar13 + tokenCount;
    translator[0xb] = tokenCount;
    iVar27 = iVar27 + *tokenDataPtrAddr;
  }
  if (0 < iVar13) {
    iVar17 = 0;
    tokenWritePtr = &ilInstAOpcode;
    do {
      *(undefined4 *)(iVar17 + iVar27) = *(undefined4 *)(iVar17 + (int)tokenWritePtr);
      iVar17 = iVar17 + 4;
      iVar13 = iVar13 + -1;
    } while (iVar13 != 0);
  }
  intToDoubleBias = DOUBLE_001aa1e0;
  iVar27 = *translator;
  paramCount = *(uint *)(iVar27 + 0x28);
  paramEntry = (uint *)(iVar27 + *(int *)(iVar27 + 0x2c) * 8);
  iVar27 = iVar27 + *(int *)(iVar27 + 0x6c) * 8;
  if (0 < (int)paramCount) {
    paramIndex = 0;
    do {
      paramTypeBits = *paramEntry & 0x1c000000;
      paramKind = *paramEntry >> 0x10 & 0x1f;
      if ((((paramTypeBits != 0xc000000) && (paramTypeBits != 0x4000000)) && (paramTypeBits != 0x10000000)) &&
         (paramTypeBits != 0)) {
        translatorError3 = translator[9];
        if (translatorError3 == 0) goto LAB_0004a4ec;
        goto LAB_0004980c;
      }
      if (paramKind == 0x11) {
        tokenCount2 = translator[0xb];
        tokenCapacity4 = translator[0xc];
        if (tokenCapacity4 < tokenCount2 + 6U) {
          if (tokenCapacity4 == 0) {
            tokenCapacity4 = 0x10;
          }
          else {
            tokenCapacity4 = tokenCapacity4 << 1;
          }
          for (; tokenCapacity4 < tokenCount2 + 6U; tokenCapacity4 = tokenCapacity4 << 1) {
          }
          if (*tokenDataPtrAddr == 0) {
            allocation = _malloc(tokenCapacity4 << 2);
            in_r4 = extraout_r4_07;
          }
          else {
            allocation = _realloc(*tokenDataPtrAddr,tokenCapacity4 << 2);
            in_r4 = extraout_r4_08;
          }
          if (allocation == 0) goto LAB_0004a55c;
          *tokenDataPtrAddr = allocation;
          translator[0xc] = tokenCapacity4;
          tokenCount2 = translator[0xb];
        }
        tokenCount = tokenCount2 + 6;
        translator[0xb] = tokenCount;
        tokenWritePtr2 = (undefined4 *)(tokenCount2 * 4 + *tokenDataPtrAddr);
        *tokenWritePtr2 = 0x1c;
        tokenWritePtr2[1] = paramIndex & 0xffff | 0x10000;
        constantIndex = (uint)(ushort)*paramEntry;
        if ((*paramEntry & 0x1c000000) == 0xc000000) {
          intToDoubleHiA = 0x43300000;
          iVar13 = iVar27 + constantIndex * 0x10;
          intToDoubleLoA = *(uint *)(constantIndex * 0x10 + iVar27) ^ 0x80000000;
          tokenWritePtr2[2] = (float)((double)CONCAT44(0x43300000,intToDoubleLoA) - intToDoubleBias);
          intToDoubleHiB = 0x43300000;
          intToDoubleLoB = *(uint *)(iVar13 + 4) ^ 0x80000000;
          tokenWritePtr2[3] = (float)((double)CONCAT44(0x43300000,intToDoubleLoB) - intToDoubleBias);
          intToDoubleHiC = 0x43300000;
          intToDoubleLoC = *(uint *)(iVar13 + 8) ^ 0x80000000;
          tokenWritePtr2[4] = (float)((double)CONCAT44(0x43300000,intToDoubleLoC) - intToDoubleBias);
          intToDoubleHiD = 0x43300000;
          intToDoubleLoD = *(uint *)(iVar13 + 0xc) ^ 0x80000000;
          tokenWritePtr2[5] = (float)((double)CONCAT44(0x43300000,intToDoubleLoD) - intToDoubleBias);
        }
        else if ((*paramEntry & 0x1c000000) == 0x10000000) {
          iVar13 = iVar27 + constantIndex * 0x10;
          tokenWritePtr2[2] = (uint)(*(int *)(iVar27 + constantIndex * 0x10) != 0);
          tokenWritePtr2[3] = (uint)(*(int *)(iVar13 + 4) != 0);
          tokenWritePtr2[4] = (uint)(*(int *)(iVar13 + 8) != 0);
          tokenWritePtr2[5] = (uint)(*(int *)(iVar13 + 0xc) != 0);
        }
        else {
          iVar13 = iVar27 + constantIndex * 0x10;
          tokenWritePtr2[2] = *(undefined4 *)(iVar27 + constantIndex * 0x10);
          tokenWritePtr2[3] = *(undefined4 *)(iVar13 + 4);
          tokenWritePtr2[4] = *(undefined4 *)(iVar13 + 8);
          tokenWritePtr2[5] = *(undefined4 *)(iVar13 + 0xc);
        }
      }
      paramIndex = paramIndex + 1;
      paramEntry = paramEntry + 2;
    } while (paramCount != paramIndex);
  }
  translator[6] = translator[0xb];
  tokenCount3 = translator[0xb];
  tokenCapacity = translator[0xc];
  if (tokenCapacity < tokenCount3 + 0xc6U) {
    if (tokenCapacity == 0) {
      tokenCapacity = 0x10;
    }
    else {
      tokenCapacity = tokenCapacity << 1;
    }
    for (; tokenCapacity < tokenCount3 + 0xc6U; tokenCapacity = tokenCapacity << 1) {
    }
    if (*tokenDataPtrAddr == 0) {
      allocation = _malloc(tokenCapacity << 2);
      in_r4 = extraout_r4_09;
    }
    else {
      allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
      in_r4 = extraout_r4_10;
    }
    if (allocation == 0) {
LAB_0004a55c:
      if (translator[9] != 0) {
        return translator[9];
      }
      translator[9] = 1;
      return 1;
    }
    *tokenDataPtrAddr = allocation;
    translator[0xc] = tokenCapacity;
    tokenCount3 = translator[0xb];
  }
  tokenCount = tokenCount3 + 0xc6;
  translator[0xb] = tokenCount;
  paramKind = tokenCount3 * 4 + *tokenDataPtrAddr;
  iVar27 = 0;
  iVar13 = 0xc6;
  do {
    *(undefined4 *)(iVar27 + paramKind) = 0x4b;
    iVar27 = iVar27 + 4;
    iVar13 = iVar13 + -1;
  } while (iVar13 != 0);
  translatorError3 = translator[9];
  translator[7] = translator[0xb];
LAB_0004980c:
  if (translatorError3 != 0) {
    return translatorError3;
  }
  tokenCount = ((int (*)())fragmentInstructionToIL)(translator,in_r4,in_r5,in_r6,tokenWritePtr,tokenCount,paramKind,tokenWritePtr2);
  if (tokenCount != 0) goto LAB_0004a7b4;
  iVar12 = *translator;
  outputCount = *(uint *)(iVar12 + 0x30);
  outputEntry = (uint *)(iVar12 + *(int *)(iVar12 + 0x34) * 8);
  if (0 < (int)outputCount) {
    outputIndex = 0;
    do {
      if ((1 << (outputIndex & 0x3f) & translator[4]) != 0) {
        uVar24 = 0x55;
        puVar22 = ((unsigned char *)0x00003210);
        uVar23 = outputIndex + *(int *)(*translator + 0x10) + 1 & 0xffff | 0x440000;
        if ((*(ushort *)outputEntry & 0xf) == 4) {
          iVar12 = translator[0xd];
          if (((*(uint *)(iVar12 + 0x20) & 0x400000) != 0) ||
             (bVar3 = true, (*(uint *)(iVar12 + 0x20) >> 0x12 & 0xf) < 2)) {
            bVar3 = false;
          }
          translatorFlags = translator[5];
          translator[5] = translatorFlags | 0x80000000;
          uVar25 = *outputEntry >> 1 & 7 | 0x570000;
          if ((translatorFlags & 0x18000000) != 0) {
            *(uint *)(iVar12 + 0x20) = *(uint *)(iVar12 + 0x20) | 0x2000000;
            uVar6 = (undefined2)translator[8];
            sVar7 = ((ushort)((uint)*(undefined4 *)(translator[0xd] + 0x20) >> 0x1a) & 1) +
                    (short)*(undefined4 *)(*translator + 0x28);
            _memset(&ilInstAOpcode,0,0x24);
            sVar5 = sVar7 + 1;
            fogMode = (uint)translator[5] >> 0x1b & 3;
            ilInstADst = CONCAT22(4,uVar6);
            ilInstADstMask = 0x55;
            local_a0[0] = (undefined *)((uint)local_a0[0] & 0xffff0000);
            ilInstASrc0 = (undefined *)((uint)ilInstASrc0 & 0xffc0ffff | 0x500000);
            ilInstADst = ilInstADst | 0x400000;
            if (fogMode == 1) {
              translatorError = translator[9];
              ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),0x40);
              ilInstADstMask = 0x155;
              local_a0[1] = (undefined *)0x0;
              ilInstASrc1 = CONCAT22(1,sVar5) | 0x400000;
              local_a0[2] = ((unsigned char *)0x00001111);
              ilInstASrc2 = CONCAT22(1,sVar5) | 0x400000;
              if (translatorError == 0) {
                tokenCount = translator[0xb];
                tokenCapacity3 = translator[0xc];
                if (tokenCapacity3 < tokenCount + 9U) {
                  if (tokenCapacity3 == 0) {
                    tokenCapacity3 = 0x10;
                  }
                  else {
                    tokenCapacity3 = tokenCapacity3 << 1;
                  }
                  for (; tokenCapacity3 < tokenCount + 9U; tokenCapacity3 = tokenCapacity3 << 1) {
                  }
                  if (*tokenDataPtrAddr == 0) {
                    allocation = _malloc(tokenCapacity3 << 2);
                  }
                  else {
                    allocation = _realloc(*tokenDataPtrAddr,tokenCapacity3 << 2);
                  }
                  if (allocation == 0) {
LAB_0004a188:
                    translatorError = translator[9];
                    if (translatorError == 0) {
                      translatorError = 1;
                      translator[9] = 1;
                    }
                    goto LAB_0004a0d8;
                  }
                  *tokenDataPtrAddr = allocation;
                  translator[0xc] = tokenCapacity3;
                  tokenCount = translator[0xb];
                }
                ppuVar20 = (undefined **)&ilInstASrc0;
                translator[0xb] = tokenCount + 9;
                tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
                *tokenWritePtr = ilInstAOpcode;
                tokenWritePtr[1] = ilInstADst;
                tokenWritePtr[2] = ilInstADstMask;
                do {
                  tokenWritePtr[3] = *ppuVar20;
                  ppuVar1 = ppuVar20 + 3;
                  ppuVar20 = ppuVar20 + 1;
                  tokenWritePtr[4] = *ppuVar1;
                  tokenWritePtr = tokenWritePtr + 2;
                } while (local_a0 != ppuVar20);
                goto LAB_0004a0d4;
              }
            }
            else {
              if ((fogMode == 0) || (3 < fogMode)) goto LAB_0004a474;
              ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),0x49);
              if ((translator[5] & 0x18000000U) == 0x10000000) {
                ilInstASrc1 = CONCAT22(1,sVar5);
                translatorError = translator[9];
                local_a0[1] = (undefined *)0x2222;
                ilInstASrc1 = ilInstASrc1 | 0x400000;
                if (translatorError == 0) {
                  tokenCount = translator[0xb];
                  tokenCapacity3 = translator[0xc];
                  if (tokenCapacity3 < tokenCount + 7U) {
                    if (tokenCapacity3 == 0) {
                      tokenCapacity3 = 0x10;
                    }
                    else {
                      tokenCapacity3 = tokenCapacity3 << 1;
                    }
                    for (; tokenCapacity3 < tokenCount + 7U; tokenCapacity3 = tokenCapacity3 << 1) {
                    }
                    if (*tokenDataPtrAddr == 0) {
                      allocation = _malloc(tokenCapacity3 << 2);
                    }
                    else {
                      allocation = _realloc(*tokenDataPtrAddr,tokenCapacity3 << 2);
                    }
                    if (allocation == 0) {
LAB_00049f94:
                      translatorError = translator[9];
                      if (translatorError == 0) {
                        translatorError = 1;
                        translator[9] = 1;
                      }
                      goto LAB_00049fa8;
                    }
                    *tokenDataPtrAddr = allocation;
                    translator[0xc] = tokenCapacity3;
                    tokenCount = translator[0xb];
                  }
                  puVar19 = &ilInstASrc0;
                  translator[0xb] = tokenCount + 7;
                  tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
                  *tokenWritePtr = ilInstAOpcode;
                  tokenWritePtr[1] = ilInstADst;
                  tokenWritePtr[2] = ilInstADstMask;
                  do {
                    tokenWritePtr[3] = *puVar19;
                    puVar2 = puVar19 + 3;
                    puVar19 = puVar19 + 1;
                    tokenWritePtr[4] = *puVar2;
                    tokenWritePtr = tokenWritePtr + 2;
                  } while (&ilInstASrc2 != puVar19);
LAB_00049f80:
                  translatorError = translator[9];
                }
              }
              else {
                ilInstASrc1 = CONCAT22(1,sVar5);
                translatorError = translator[9];
                ilInstASrc1 = ilInstASrc1 | 0x400000;
                local_a0[1] = ((unsigned char *)0x00003333);
                if (translatorError == 0) {
                  tokenCount = translator[0xb];
                  tokenCapacity3 = translator[0xc];
                  if (tokenCapacity3 < tokenCount + 7U) {
                    if (tokenCapacity3 == 0) {
                      tokenCapacity3 = 0x10;
                    }
                    else {
                      tokenCapacity3 = tokenCapacity3 << 1;
                    }
                    for (; tokenCapacity3 < tokenCount + 7U; tokenCapacity3 = tokenCapacity3 << 1) {
                    }
                    if (*tokenDataPtrAddr == 0) {
                      allocation = _malloc(tokenCapacity3 << 2);
                    }
                    else {
                      allocation = _realloc(*tokenDataPtrAddr,tokenCapacity3 << 2);
                    }
                    if (allocation == 0) {
                      translatorError = translator[9];
                      if (translatorError == 0) {
                        translatorError = 1;
                        translator[9] = 1;
                      }
                      goto LAB_00049e2c;
                    }
                    *tokenDataPtrAddr = allocation;
                    translator[0xc] = tokenCapacity3;
                    tokenCount = translator[0xb];
                  }
                  puVar19 = &ilInstASrc0;
                  translator[0xb] = tokenCount + 7;
                  tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
                  *tokenWritePtr = ilInstAOpcode;
                  tokenWritePtr[1] = ilInstADst;
                  tokenWritePtr[2] = ilInstADstMask;
                  do {
                    tokenWritePtr[3] = *puVar19;
                    puVar2 = puVar19 + 3;
                    puVar19 = puVar19 + 1;
                    tokenWritePtr[4] = *puVar2;
                    tokenWritePtr = tokenWritePtr + 2;
                  } while (&ilInstASrc2 != puVar19);
                  translatorError = translator[9];
                }
LAB_00049e2c:
                ilInstASrc0 = (undefined *)CONCAT22(4,uVar6);
                ilInstASrc1 = CONCAT22(4,uVar6);
                local_a0[0] = ((unsigned char *)0x00003210);
                local_a0[1] = ((unsigned char *)0x00003210);
                ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),0x49);
                ilInstASrc0 = (undefined *)((uint)ilInstASrc0 | 0x400000);
                ilInstASrc1 = ilInstASrc1 | 0x400000;
                if (translatorError == 0) {
                  tokenCount = translator[0xb];
                  tokenCapacity3 = translator[0xc];
                  if (tokenCapacity3 < tokenCount + 7U) {
                    if (tokenCapacity3 == 0) {
                      tokenCapacity3 = 0x10;
                    }
                    else {
                      tokenCapacity3 = tokenCapacity3 << 1;
                    }
                    for (; tokenCapacity3 < tokenCount + 7U; tokenCapacity3 = tokenCapacity3 << 1) {
                    }
                    if (*tokenDataPtrAddr == 0) {
                      allocation = _malloc(tokenCapacity3 << 2);
                    }
                    else {
                      allocation = _realloc(*tokenDataPtrAddr,tokenCapacity3 << 2);
                    }
                    if (allocation == 0) goto LAB_00049f94;
                    *tokenDataPtrAddr = allocation;
                    translator[0xc] = tokenCapacity3;
                    tokenCount = translator[0xb];
                  }
                  puVar19 = &ilInstASrc0;
                  translator[0xb] = tokenCount + 7;
                  tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
                  *tokenWritePtr = ilInstAOpcode;
                  tokenWritePtr[1] = ilInstADst;
                  tokenWritePtr[2] = ilInstADstMask;
                  do {
                    tokenWritePtr[3] = *puVar19;
                    puVar2 = puVar19 + 3;
                    puVar19 = puVar19 + 1;
                    tokenWritePtr[4] = *puVar2;
                    tokenWritePtr = tokenWritePtr + 2;
                  } while (&ilInstASrc2 != puVar19);
                  goto LAB_00049f80;
                }
              }
LAB_00049fa8:
              ilInstASrc0 = (undefined *)CONCAT22(4,uVar6);
              ilInstADstMask = ilInstADstMask | 0x100;
              ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),0x2d);
              ilInstASrc0 = (undefined *)((uint)ilInstASrc0 | 0x400000);
              local_a0[0] = (undefined *)0xba98;
              if (translatorError != 0) goto LAB_0004a0d8;
              tokenCount = translator[0xb];
              tokenCapacity3 = translator[0xc];
              if (tokenCapacity3 < tokenCount + 5U) {
                if (tokenCapacity3 == 0) {
                  tokenCapacity3 = 0x10;
                }
                else {
                  tokenCapacity3 = tokenCapacity3 << 1;
                }
                for (; tokenCapacity3 < tokenCount + 5U; tokenCapacity3 = tokenCapacity3 << 1) {
                }
                if (*tokenDataPtrAddr == 0) {
                  allocation = _malloc(tokenCapacity3 << 2);
                }
                else {
                  allocation = _realloc(*tokenDataPtrAddr,tokenCapacity3 << 2);
                }
                if (allocation == 0) goto LAB_0004a188;
                *tokenDataPtrAddr = allocation;
                translator[0xc] = tokenCapacity3;
                tokenCount = translator[0xb];
              }
              translator[0xb] = tokenCount + 5;
              tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
              *tokenWritePtr = ilInstAOpcode;
              tokenWritePtr[1] = ilInstADst;
              tokenWritePtr[2] = ilInstADstMask;
              tokenWritePtr[3] = ilInstASrc0;
              tokenWritePtr[4] = local_a0[0];
LAB_0004a0d4:
              translatorError = translator[9];
            }
LAB_0004a0d8:
            iVar27 = *translator;
            ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),0x47);
            ilInstADstMask = 0x155;
            sVar5 = (short)outputIndex;
            ilInstADst = CONCAT22(4,sVar5 + (short)*(undefined4 *)(iVar27 + 0x10) + 1);
            ilInstADst = ilInstADst | 0x400000;
            local_a0[0] = ((unsigned char *)0x00003210);
            ilInstASrc0 = (undefined *)CONCAT22(4,sVar5 + (short)*(undefined4 *)(iVar27 + 0x10) + 1);
            ilInstASrc0 = (undefined *)((uint)ilInstASrc0 | 0x400000);
            if (translatorError == 0) {
              tokenCount = translator[0xb];
              tokenCapacity3 = translator[0xc];
              if (tokenCapacity3 < tokenCount + 5U) {
                if (tokenCapacity3 == 0) {
                  tokenCapacity3 = 0x10;
                }
                else {
                  tokenCapacity3 = tokenCapacity3 << 1;
                }
                for (; tokenCapacity3 < tokenCount + 5U; tokenCapacity3 = tokenCapacity3 << 1) {
                }
                if (*tokenDataPtrAddr == 0) {
                  allocation = _malloc(tokenCapacity3 << 2);
                }
                else {
                  allocation = _realloc(*tokenDataPtrAddr,tokenCapacity3 << 2);
                }
                if (allocation == 0) {
                  translatorError = translator[9];
                  if (translatorError == 0) {
                    translatorError = 1;
                    translator[9] = 1;
                  }
                  iVar27 = *translator;
                  goto LAB_0004a25c;
                }
                *tokenDataPtrAddr = allocation;
                translator[0xc] = tokenCapacity3;
                tokenCount = translator[0xb];
              }
              translator[0xb] = tokenCount + 5;
              tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
              *tokenWritePtr = ilInstAOpcode;
              tokenWritePtr[1] = ilInstADst;
              tokenWritePtr[2] = ilInstADstMask;
              tokenWritePtr[3] = ilInstASrc0;
              tokenWritePtr[4] = local_a0[0];
              iVar27 = *translator;
              translatorError = translator[9];
            }
LAB_0004a25c:
            ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),0x3f);
            ilInstASrc0 = (undefined *)CONCAT22(4,uVar6);
            ilInstADstMask = 0x15;
            local_a0[0] = ((unsigned char *)0x00003210);
            ilInstADst = CONCAT22(4,sVar5 + (short)*(undefined4 *)(iVar27 + 0x10) + 1);
            ilInstASrc0 = (undefined *)((uint)ilInstASrc0 | 0x400000);
            ilInstADst = ilInstADst | 0x400000;
            ilInstASrc2 = CONCAT22(1,sVar7);
            local_a0[1] = ((unsigned char *)0x00003210);
            local_a0[2] = ((unsigned char *)0x00003210);
            ilInstASrc1 = CONCAT22(4,sVar5 + (short)*(undefined4 *)(iVar27 + 0x10) + 1);
            ilInstASrc2 = ilInstASrc2 | 0x400000;
            ilInstASrc1 = ilInstASrc1 | 0x400000;
            if (translatorError == 0) {
              tokenCount = translator[0xb];
              tokenCapacity3 = translator[0xc];
              if (tokenCapacity3 < tokenCount + 9U) {
                if (tokenCapacity3 == 0) {
                  tokenCapacity3 = 0x10;
                }
                else {
                  tokenCapacity3 = tokenCapacity3 << 1;
                }
                for (; tokenCapacity3 < tokenCount + 9U; tokenCapacity3 = tokenCapacity3 << 1) {
                }
                if (*tokenDataPtrAddr == 0) {
                  allocation = _malloc(tokenCapacity3 << 2);
                }
                else {
                  allocation = _realloc(*tokenDataPtrAddr,tokenCapacity3 << 2);
                }
                if (allocation == 0) {
                  if (translator[9] == 0) {
                    translator[9] = 1;
                  }
                  goto LAB_0004a474;
                }
                *tokenDataPtrAddr = allocation;
                translator[0xc] = tokenCapacity3;
                tokenCount = translator[0xb];
              }
              ppuVar20 = (undefined **)&ilInstASrc0;
              translator[0xb] = tokenCount + 9;
              tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
              *tokenWritePtr = ilInstAOpcode;
              tokenWritePtr[1] = ilInstADst;
              tokenWritePtr[2] = ilInstADstMask;
              do {
                tokenWritePtr[3] = *ppuVar20;
                ppuVar1 = ppuVar20 + 3;
                ppuVar20 = ppuVar20 + 1;
                tokenWritePtr[4] = *ppuVar1;
                tokenWritePtr = tokenWritePtr + 2;
              } while (local_a0 != ppuVar20);
            }
          }
LAB_0004a474:
          channelIndex = 0;
          if (bVar3) {
            do {
              if (((int)(*(uint *)(translator[0xd] + 0x20) >> 0x12 & 0xf) >> (channelIndex & 0x3f) & 1U) != 0
                 ) {
                tokenCount = translator[0xb];
                tokenCapacity2 = translator[0xc];
                if (tokenCapacity2 < tokenCount + 5U) {
                  if (tokenCapacity2 == 0) {
                    tokenCapacity2 = 0x10;
                  }
                  else {
                    tokenCapacity2 = tokenCapacity2 << 1;
                  }
                  for (; tokenCapacity2 < tokenCount + 5U; tokenCapacity2 = tokenCapacity2 << 1) {
                  }
                  if (*tokenDataPtrAddr == 0) {
                    allocation = _malloc(tokenCapacity2 << 2);
                  }
                  else {
                    allocation = _realloc(*tokenDataPtrAddr,tokenCapacity2 << 2);
                  }
                  if (allocation == 0) goto LAB_0004a55c;
                  *tokenDataPtrAddr = allocation;
                  translator[0xc] = tokenCapacity2;
                  tokenCount = translator[0xb];
                }
                uVar25 = channelIndex & 0xffff | uVar25 & 0xffff0000;
                translator[0xb] = tokenCount + 5;
                iVar27 = tokenCount * 4 + *tokenDataPtrAddr;
                *(undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr) = 0x47;
                *(undefined **)(iVar27 + 0x10) = ((unsigned char *)0x00003210);
                *(uint *)(iVar27 + 4) = uVar25;
                *(undefined4 *)(iVar27 + 8) = 0x55;
                *(uint *)(iVar27 + 0xc) = uVar23;
              }
              moreChannels = channelIndex != 3;
              channelIndex = channelIndex + 1;
            } while (moreChannels);
            goto LAB_0004a680;
          }
        }
        else {
          if ((*(ushort *)outputEntry & 0xf) != 7) goto switchD_00049180_caseD_0;
          translatorFlags = translator[5];
          uVar24 = 0x155;
          translator[5] = translatorFlags | 0x40000000;
          uVar25 = 0x580000;
          if ((translatorFlags & 0x20000000) == 0) {
            puVar22 = ((unsigned char *)0x00003212);
          }
        }
        tokenCount = translator[0xb];
        tokenCapacity3 = translator[0xc];
        if (tokenCapacity3 < tokenCount + 5U) {
          if (tokenCapacity3 == 0) {
            tokenCapacity3 = 0x10;
          }
          else {
            tokenCapacity3 = tokenCapacity3 << 1;
          }
          for (; tokenCapacity3 < tokenCount + 5U; tokenCapacity3 = tokenCapacity3 << 1) {
          }
          if (*tokenDataPtrAddr == 0) {
            allocation = _malloc(tokenCapacity3 << 2);
          }
          else {
            allocation = _realloc(*tokenDataPtrAddr,tokenCapacity3 << 2);
          }
          if (allocation == 0) goto LAB_0004a55c;
          *tokenDataPtrAddr = allocation;
          translator[0xc] = tokenCapacity3;
          tokenCount = translator[0xb];
        }
        translator[0xb] = tokenCount + 5;
        tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
        *tokenWritePtr = 0x47;
        tokenWritePtr[4] = puVar22;
        tokenWritePtr[1] = uVar25;
        tokenWritePtr[2] = uVar24;
        tokenWritePtr[3] = uVar23;
      }
LAB_0004a680:
      outputIndex = outputIndex + 1;
      outputEntry = outputEntry + 2;
    } while (outputCount != outputIndex);
  }
  tokenCount = translator[0xb];
  tokenCapacity = translator[0xc];
  if (tokenCapacity < tokenCount + 1U) {
    if (tokenCapacity == 0) {
      tokenCapacity = 0x10;
    }
    else {
      tokenCapacity = tokenCapacity << 1;
    }
    for (; tokenCapacity < tokenCount + 1U; tokenCapacity = tokenCapacity << 1) {
    }
    if (*tokenDataPtrAddr == 0) {
      allocation = _malloc(tokenCapacity << 2);
    }
    else {
      allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
    }
    if (allocation != 0) {
      *tokenDataPtrAddr = allocation;
      translator[0xc] = tokenCapacity;
      tokenCount = translator[0xb];
      goto LAB_0004a708;
    }
    translatorError = translator[9];
    if (translatorError == 0) {
      translatorError = 1;
      translator[9] = 1;
    }
    if (translatorError != 0) {
      return translatorError;
    }
  }
  else {
LAB_0004a708:
    translator[0xb] = tokenCount + 1;
    tokenWritePtr3 = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
  }
  *tokenWritePtr3 = 0x28;
  iVar12 = translator[7];
  iVar27 = iVar12 - translator[6];
  if (iVar27 != 0) {
    _memmove(translator[10] + translator[6] * 4,translator[10] + iVar12 * 4,(translator[0xb] - iVar12) * 4);
    translator[7] = translator[6];
    translator[0xb] = translator[0xb] - iVar27;
  }
  if ((translator[5] & 0xc0000000U) == 0) {
    ((int (*)())fpilEmitEmptyProgram)(translator);
  }
LAB_0004a7b4:
  return translator[9];
}

/* floatToFp24 @ 0x4a7d0 (80 bytes) */
uint floatToFp24(double value)
{
  float fVar1;
  uint uVar2;
  uint uVar3;
  
  fVar1 = (float)value;
  uVar2 = (uint)GH_F2U(fVar1) >> 0x17 & 0xff;
  uVar3 = (uint)GH_F2U(fVar1) >> 8 & 0x800000;
  if (uVar2 < 0x41) {
    return 0;
  }
  if (0xbf < uVar2) {
    return uVar3 | 0x7fffff;
  }
  return (uint)GH_F2U(fVar1) >> 7 & 0xffff | uVar3 | (uVar2 - 0x40) * 0x10000;
}

/* fp24ToFloat @ 0x4a830 (40 bytes) */
double fp24ToFloat(uint fp24Bits)
{
  return (double)GH_U2F((unsigned int)(((fp24Bits & 0x800000) << 8 | ((fp24Bits >> 0x10 & 0x7f) + 0x40) * 0x800000 |
                        (fp24Bits & 0xffff) << 7)));
}

/* FUN_0004a860 @ 0x4a860 (112 bytes) */
int FUN_0004a860(glContext, param_2, param_3, param_4, param_5, param_6, param_7)
  int glContext;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  char cVar1;
  
  if (((*(uint *)(glContext + 0x44) & 0x20000) != 0) && (*(int *)(glContext + 0x1e70) != 0)) {
    if ((*(uint *)(glContext + 0x44) & 0x2000) == 0) {
      cVar1 = ((unsigned char *)0x00001136)[glContext];
    }
    else {
      cVar1 = ((unsigned char *)0x000011d0)[glContext];
    }
    if (cVar1 == '\0') {
                    
                    
      (**(code **)(glContext + 0x294c))(glContext);
      return;
    }
  }
                    
                    
  (**(code **)(glContext + 0x294c))(glContext,*(undefined4 *)(glContext + 0x1e5c));
  return;
}

/* FUN_0004a8f0 @ 0x4a8f0 (140 bytes) */
void FUN_0004a8f0(int glContext,undefined4 param_2,undefined4 param_3,undefined4 param_4,double fparam_1)
{
  if ((*(uint *)(glContext + 0x44) & 0x20000) == 0) {
    FUN_000b6580(glContext,0);
                    
                    
    (**(code **)(glContext + 0x294c))(glContext,*(undefined4 *)(glContext + 0x1e5c));
    return;
  }
  if ((*(uint *)(glContext + 0x44) & 0x2000) != 0) {
    ((undefined4 (*)())FUN_000afe40)(glContext,0,param_3,param_4,fparam_1);
    return;
  }
  atifsCompileCurrentShader(glContext);
  return;
}

/* FUN_0004a990 @ 0x4a990 (100 bytes) */
int FUN_0004a990(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  /* issue #74: this called freeAndNullField(param_2+8) twice in a row with the identical argument.
   * freeAndNullField is a plain free-and-null helper, so the second call was always a guaranteed
   * no-op once the first succeeded (or, before the malloc_size() guard above, a second harmless
   * skip once the first left a bad value in place) - a redundant duplicate, not a real second
   * resource being freed. Removed; no other call site in this corpus uses a different offset
   * here to compare against, so there is no evidence a second, distinct field was ever meant
   * to be freed. */
  freeAndNullField(param_2 + 8);
  *param_2 = 0;
  param_2[7] = 0;
  if ((param_1 != 0) && (param_2 == *(undefined4 **)(param_1 + 0x1e68))) {
    *(undefined4 *)(param_1 + 0x1e68) = 0;
  }
  return;
}

/* FUN_0004aa00 @ 0x4aa00 (136 bytes) */
int FUN_0004aa00(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 uVar1;
  undefined1 *puVar2;
  
  puVar2 = *(undefined1 **)(((unsigned char *)0x00001488) + param_1);
  if ((puVar2 == (undefined1 *)0x0) ||
     ((*(int *)(puVar2 + 0x37cc) < 0x41 && (*(int *)(puVar2 + 0x37d0) < 0x41)))) {
    uVar1 = 0;
  }
  else {
    if (param_2 != 0) {
      *(undefined4 *)(param_1 + 0x1e68) = 0;
      *puVar2 = 0;
      *(undefined4 *)(((unsigned char *)0x00001488) + param_1) = 0;
    }
    arbfpBindFragmentProgram(param_1,puVar2);
    uVar1 = 1;
  }
  return uVar1;
}

/* FUN_0004aa90 @ 0x4aa90 (196 bytes) */
int FUN_0004aa90(param_1, param_2)
  int param_1;
  uint *param_2;
{
  uint *puVar1;
  uint *puVar2;
  int loopIndex;
  
  if (((unsigned char *)0x000013b2)[param_1] != '\0') {
    loopIndex = 0;
    puVar2 = param_2;
    do {
      puVar1 = puVar2 + 1;
      loopIndex = loopIndex + 1;
      puVar2[0x22] = puVar2[0x22] & 0xfe001fc0 | 0xd10000;
      puVar2 = puVar2 + 1;
      *puVar2 = *puVar1 & 0xfffcffef;
    } while (loopIndex < (int)(uint)(byte)((unsigned char *)0x000013b2)[param_1]);
  }
  param_2[0x87] = 0;
  param_2[0x83] = 1;
  param_2[0x84] = 0;
  param_2[0x86] = 0;
  *param_2 = *param_2 & 0xfffffff0;
  param_2[1] = param_2[1] & 0xfffc0fff | 0x10000;
  param_2[0x22] = param_2[0x22] & 0xffffe03f;
  param_2[0x82] = param_2[0x82] & 0xfffff800 | 0x80;
  return;
}

/* FUN_0004ab60 @ 0x4ab60 (304 bytes) */
int FUN_0004ab60(glContext)
  int glContext;
{
  int loopIndex;
  int iVar1;
  int iVar2;
  
  FUN_000b6020(glContext,(*(uint *)(PTR_DAT_001e88c8 + (uint)*(byte *)(glContext + 0x293f) * 0x24 + 0x20
                                 ) ^ 0x800000) >> 0x17 & 1,1);
  *(uint *)(((unsigned char *)0x00001544) + *(int *)(glContext + 0x1e60)) =
       *(uint *)(((unsigned char *)0x00001544) + *(int *)(glContext + 0x1e60)) & 0xffc0003f | 0x40;
  *(undefined4 *)(((unsigned char *)0x00001098) + *(int *)(glContext + 0x1e60)) = 1;
  ((int (*)())FUN_0004aa90)(glContext,((unsigned char *)0x000010ec) + *(int *)(glContext + 0x1e60));
  *(undefined4 *)(glContext + 0x1e84) = 0;
  *(undefined4 *)(glContext + 0x277c) = 0xffffffff;
  *(undefined4 *)(glContext + 0x1e64) = 0;
  *(undefined4 *)(glContext + 0x1e80) = 0;
  if (0 < *(int *)(glContext + 0x1e74)) {
    loopIndex = 0;
    do {
      iVar2 = loopIndex * 4;
      loopIndex = loopIndex + 1;
      ((unsigned char *)0x000010e9)[*(int *)(iVar2 + *(int *)(glContext + 0x1e7c))] = 0;
      ((unsigned char *)0x000010ea)[*(int *)(iVar2 + *(int *)(glContext + 0x1e7c))] = 0;
    } while (loopIndex < *(int *)(glContext + 0x1e74));
  }
  *(undefined4 *)(glContext + 0x1e74) = 0;
  if (*(int *)(glContext + 0x1e5c) == 0) {
    *(undefined4 *)(glContext + 0x1e5c) = *(undefined4 *)(glContext + 0x1e60);
  }
  *(undefined4 *)(glContext + 0x1e84) = 0;
  *(undefined4 *)(glContext + 0x1e80) = 0;
  iVar2 = 8;
  iVar1 = 0;
  do {
    *(undefined4 *)(glContext + 0x1e88 + iVar1) = 0;
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

/* FUN_0004ac90 @ 0x4ac90 (1272 bytes) */
int FUN_0004ac90(glContext)
  int glContext;
{
  uint loopIndex;
  bool bVar1;
  uint uVar2;
  int iVar3;
  code *pcVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  code *pcVar8;
  int *glContextWord1e5c;
  uint uVar10;
  uint uVar11;
  int iVar12;
  uint *puVar13;
  int iVar14;
  double fparam_1;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  
  glContextWord1e5c = *(int **)(glContext + 0x1e5c);
  glContextWord1e5c[0x42e] = glContextWord1e5c[0x42e] & 0xffff00ff;
  uVar11 = (uint)*(byte *)(glContext + 0x2b);
  if ((uint)(byte)((unsigned char *)0x000013b2)[glContext] < (uint)*(byte *)(glContext + 0x2b)) {
    uVar11 = (uint)(byte)((unsigned char *)0x000013b2)[glContext];
  }
  bVar1 = false;
  if (uVar11 != 0) {
    loopIndex = 0;
    iVar12 = glContext;
    do {
      iVar3 = *(int *)(((unsigned char *)0x000013f8) + iVar12);
      if (((iVar3 != 0) && (*(short *)(iVar3 + 0x38) == 0x1902)) &&
         (fparam_1 = (double)*(float *)(iVar3 + 0x50), fparam_1 != 0.0)) {
        iVar3 = ((int)loopIndex >> 2) + (uint)((int)loopIndex < 0 && (loopIndex & 3) != 0);
        if (iVar3 == 1) {
          iVar14 = ((uint (*)())floatToFp24)(fparam_1);
          glContextWord1e5c[0x68] = iVar14;
        }
        else if (iVar3 < 2) {
          if (iVar3 == 0) {
            iVar14 = ((uint (*)())floatToFp24)(fparam_1);
            glContextWord1e5c[99] = iVar14;
          }
        }
        else if (iVar3 == 2) {
          iVar14 = ((uint (*)())floatToFp24)(fparam_1);
          glContextWord1e5c[0x6d] = iVar14;
        }
        else if (iVar3 == 3) {
          iVar14 = ((uint (*)())floatToFp24)(fparam_1);
          glContextWord1e5c[0x72] = iVar14;
        }
        uVar2 = iVar3 + 0x10U >> 3 & 0x1ffffffc;
        bVar1 = true;
        *(uint *)((int)glContextWord1e5c + (int)(((unsigned char *)0x000010b8) + uVar2)) =
             1 << (iVar3 + 0x10U & 0x1f) | *(uint *)((int)glContextWord1e5c + (int)(((unsigned char *)0x000010b8) + uVar2));
      }
      loopIndex = loopIndex + 1;
      iVar12 = iVar12 + 4;
    } while (uVar11 != loopIndex);
  }
  if (*(char *)(glContext + 0x121) != '\0') {
    iVar12 = *(int *)(*(int *)(glContext + 4) + 0x10);
    local_58 = *(undefined4 *)(((unsigned char *)0x00002de0) + iVar12);
    local_54 = *(undefined4 *)(((unsigned char *)0x00002de4) + iVar12);
    local_50 = *(undefined4 *)(((unsigned char *)0x00002de8) + iVar12);
    local_4c = 0;
    local_48 = -1.0 / (*(float *)(((unsigned char *)0x00002df8) + iVar12) - *(float *)(((unsigned char *)0x00002df4) + iVar12));
    local_44 = *(float *)(((unsigned char *)0x00002df8) + iVar12) * *(float *)(((unsigned char *)0x00002dfc) + iVar12);
    local_40 = *(float *)(((unsigned char *)0x00002df0) + iVar12) / 0.6931472;
    local_3c = *(float *)(((unsigned char *)0x00002df0) + iVar12) / 0.83255464;
    (**(code **)(((unsigned char *)0x00001280) + glContext))
              (glContext,0,
               *(undefined4 *)(((unsigned char *)0x00003878) + *(int *)(((unsigned char *)0x000036c0) + *(int *)(glContext + 0x1e5c)))
               ,*(undefined4 *)
                 (((unsigned char *)0x00003878) + *(int *)(((unsigned char *)0x000036c0) + *(int *)(glContext + 0x1e5c))),&local_58,1,
               1,*(code **)(((unsigned char *)0x00001280) + glContext));
    (**(code **)(((unsigned char *)0x00001280) + glContext))
              (glContext,0,
               *(undefined4 *)(((unsigned char *)0x0000387c) + *(int *)(((unsigned char *)0x000036c0) + *(int *)(glContext + 0x1e5c)))
               ,*(undefined4 *)
                 (((unsigned char *)0x0000387c) + *(int *)(((unsigned char *)0x000036c0) + *(int *)(glContext + 0x1e5c))),&local_48,1,
               1);
  }
  noop_b5190(glContext,*(int *)(glContext + 0x1e5c) + 0x1784,
               ((unsigned char *)0x00001660) + *(int *)(glContext + 0x1e5c));
  uVar11 = (uint)*(byte *)(glContext + 0x20);
  if (uVar11 != 0) {
    iVar12 = 0;
    iVar3 = glContext + 0x28b4;
    do {
      if ((uVar11 & 1) != 0) {
        (**(code **)(((unsigned char *)0x00001280) + glContext))(glContext,0,iVar12 + 0x14,iVar12 + 0x14,iVar3,1,1);
      }
      uVar11 = uVar11 >> 1;
      iVar12 = iVar12 + 1;
      iVar3 = iVar3 + 0x10;
    } while (uVar11 != 0);
  }
  if ((bVar1) && (*(undefined1 *)((int)glContextWord1e5c + 0x10eb) = 0, glContextWord1e5c == *(int **)(glContext + 0x1e64)))
  {
    if (*(int *)(glContext + 0x23e0) == 0) {
      iVar12 = glContextWord1e5c[0xdac];
      puVar13 = (uint *)(glContextWord1e5c + 0x43b);
      piVar5 = glContextWord1e5c + 0x423;
      piVar6 = glContextWord1e5c;
    }
    else {
      iVar12 = glContextWord1e5c[0xdaf];
      puVar13 = (uint *)(glContextWord1e5c + 0x4c6);
      piVar5 = glContextWord1e5c + 0x424;
      piVar6 = glContextWord1e5c + 7;
    }
    *(int **)(glContext + 0x1e64) = glContextWord1e5c;
    if (*piVar6 == 0) {
      iVar3 = piVar6[1];
      *(undefined4 *)(0x00002348 + glContext + 4) = 1;
      *(int *)(glContext + 0x2350) = iVar3;
      *(int *)(glContext + 0x2338) = *piVar5;
      *piVar6 = 1;
      *(uint *)(glContext + 0x1930) = *(uint *)(glContext + 0x1930) | 0x100000;
    }
    if (*(char *)((int)glContextWord1e5c + 0x10eb) == '\0') {
      iVar14 = 8;
      iVar3 = glContext;
      piVar6 = glContextWord1e5c;
      do {
        piVar5 = piVar6 + 0x42e;
        piVar6 = piVar6 + 1;
        *(int *)(iVar3 + 0x1e88) = *piVar5;
        iVar3 = iVar3 + 4;
        iVar14 = iVar14 + -1;
      } while (iVar14 != 0);
      uVar11 = 0;
      pcVar4 = 0x00001f30 + glContext;
      piVar5 = glContextWord1e5c + 0x20;
      piVar6 = glContextWord1e5c;
      do {
        uVar10 = piVar6[0x42e];
        if (uVar10 != 0) {
          piVar7 = piVar5 + 3;
          pcVar8 = pcVar4 + 8;
          uVar2 = uVar11;
          do {
            if (((uVar10 & 1) != 0) && ((1 << (uVar2 & 0x3f) & glContextWord1e5c[0x436]) == 0)) {
              *(int *)pcVar8 = *piVar7;
              *(int *)(pcVar8 + 4) = piVar7[1];
              *(int *)(pcVar8 + 8) = piVar7[2];
              *(int *)(pcVar8 + 0xc) = piVar7[3];
            }
            uVar10 = uVar10 >> 1;
            uVar2 = uVar2 + 1;
            piVar7 = piVar7 + 4;
            pcVar8 = pcVar8 + 0x10;
          } while (uVar10 != 0);
        }
        bVar1 = uVar11 != 0xe0;
        piVar6 = piVar6 + 1;
        piVar5 = piVar5 + 0x80;
        pcVar4 = pcVar4 + 0x200;
        uVar11 = uVar11 + 0x20;
      } while (bVar1);
      *(undefined1 *)((int)glContextWord1e5c + 0x10eb) = 1;
      *(uint *)(glContext + 0x1930) = *(uint *)(glContext + 0x1930) | 0x40000000;
    }
    if (puVar13[0x85] == 0) {
      *(uint *)(glContext + 0x1f2c) = puVar13[0x82];
      uVar11 = *puVar13;
      *(int *)(glContext + 0x1f34) = iVar12;
      *(uint *)(0x00001f30 + glContext) = uVar11 & 0xffffff1f;
      _memcpy(glContext + 0x1ea8,puVar13 + 1,iVar12 << 2);
      uVar2 = puVar13[0x23];
      uVar10 = puVar13[0x24];
      uVar11 = puVar13[0x25];
      *(uint *)(glContext + 0x1ee8) = puVar13[0x22];
      *(uint *)(glContext + 0x1eec) = uVar2;
      *(uint *)(glContext + 0x1ef0) = uVar10;
      *(uint *)(glContext + 0x1ef4) = uVar11;
      uVar2 = puVar13[0x26];
      uVar10 = puVar13[0x27];
      uVar11 = puVar13[0x28];
      *(uint *)(glContext + 0x1f04) = puVar13[0x29];
      *(uint *)(glContext + 0x1ef8) = uVar2;
      *(uint *)(glContext + 0x1efc) = uVar10;
      *(uint *)(glContext + 0x1f00) = uVar11;
      puVar13[0x85] = 1;
      *(uint *)(glContext + 0x1930) = *(uint *)(glContext + 0x1930) | 0x80000000;
    }
  }
  return;
}

/* FUN_0004b190 @ 0x4b190 (700 bytes) */
int FUN_0004b190(glContext, param_2)
  int glContext;
  int param_2;
{
  undefined4 registerDirty;
  int glContextWord1e5c;
  bool bVar1;
  bool bVar2;
  char cVar4;
  code *pcVar3;
  undefined1 *puVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  
  iVar7 = *(int *)(glContext + 0x276c);
  if (((*(uint *)(glContext + 0x44) & 0x20000) == 0) || (*(int *)(glContext + 0x1e70) == 0)) {
LAB_0004b200:
    uVar8 = 1;
    iVar9 = *(int *)(glContext + 0x1e5c);
    bVar2 = false;
  }
  else {
    if ((*(uint *)(glContext + 0x44) & 0x2000) == 0) {
      cVar4 = ((unsigned char *)0x00001136)[glContext];
    }
    else {
      cVar4 = ((unsigned char *)0x000011d0)[glContext];
    }
    if (cVar4 != '\0') goto LAB_0004b200;
    uVar8 = 0;
    iVar9 = *(int *)(glContext + 0x1e70);
    bVar2 = true;
  }
  bVar1 = param_2 == 0;
  if (bVar1) {
    *(undefined4 *)(glContext + 0x23e0) = 0;
  }
  else {
    *(undefined4 *)(glContext + 0x23e0) = 1;
  }
  puVar5 = *(undefined1 **)(((unsigned char *)0x000036c0) + iVar9);
  if (puVar5 == (undefined1 *)0x0) {
    return;
  }
  if (param_2 == *(int *)(((unsigned char *)0x000010e4) + iVar9)) {
    if (((unsigned char *)0x000036c4)[iVar9] == '\0') {
      if (!bVar1) {
        cVar4 = '\0';
        goto LAB_0004b2f8;
      }
      cVar4 = ((unsigned char *)0x000010e9)[iVar9];
    }
    else {
      if (bVar1) goto LAB_0004b340;
      cVar4 = ((unsigned char *)0x000010ea)[iVar9];
    }
    if (cVar4 != '\0') {
      return;
    }
    if (bVar2) {
      *puVar5 = (char)uVar8;
      ((unsigned char *)0x000010e9)[iVar9] = 0;
      ((unsigned char *)0x000010ea)[iVar9] = 0;
LAB_0004b42c:
      arbfpBindFragmentProgram(glContext,*(undefined4 *)(((unsigned char *)0x000036c0) + iVar9));
      return;
    }
    glContextWord1e5c = *(int *)(glContext + 0x1e5c);
    ((unsigned char *)0x000010e9)[glContextWord1e5c] = 0;
    ((unsigned char *)0x000010ea)[glContextWord1e5c] = 0;
    (**(code **)(glContext + 0x294c))(glContext,glContextWord1e5c);
    pcVar3 = *(code **)(((unsigned char *)0x00001330) + glContext);
    registerDirty = *(undefined4 *)(glContext + 0x1930);
  }
  else {
    if (!bVar1) {
      cVar4 = ((unsigned char *)0x000036c4)[iVar9];
LAB_0004b2f8:
      if (cVar4 == '\0') {
        if (bVar2) {
          arbfpCompileFragmentProgram(glContext,0,puVar5,puVar5 + 4);
        }
        else {
          FUN_000b6580(glContext,1);
        }
        ((unsigned char *)0x000036c4)[iVar9] = 1;
      }
    }
LAB_0004b340:
    *(int *)(((unsigned char *)0x000010e4) + iVar9) = param_2;
    *(int *)(((unsigned char *)0x00001528) + iVar9) = param_2;
    *(int *)(((unsigned char *)0x000012fc) + iVar9) = param_2;
    if (param_2 == 2) {
      iVar7 = iVar7 << 2;
      uVar6 = 4;
    }
    else {
      iVar7 = iVar7 * 4;
      uVar6 = (*(uint *)(((unsigned char *)0x000013e0) + iVar7 + iVar9) >> 6 & 0x3f) + 1 & 0x3f;
    }
    *(uint *)(((unsigned char *)0x000013e0) + iVar7 + iVar9) =
         uVar6 << 0xc | *(uint *)(((unsigned char *)0x000013e0) + iVar7 + iVar9) & 0xff000fff | 0xfc0000;
    if (bVar2) {
      **(undefined1 **)(((unsigned char *)0x000036c0) + iVar9) = (char)uVar8;
      ((unsigned char *)0x000010e9)[iVar9] = 0;
      ((unsigned char *)0x000010ea)[iVar9] = 0;
      *(undefined4 *)(glContext + 0x1e68) = uVar8;
      goto LAB_0004b42c;
    }
    glContextWord1e5c = *(int *)(glContext + 0x1e5c);
    ((unsigned char *)0x000010e9)[glContextWord1e5c] = 0;
    ((unsigned char *)0x000010ea)[glContextWord1e5c] = 0;
    *(undefined4 *)(glContext + 0x1e68) = 0;
    (**(code **)(((unsigned char *)0x00001334) + glContext))(glContext,1);
    (**(code **)(glContext + 0x294c))(glContext,glContextWord1e5c);
    pcVar3 = *(code **)(((unsigned char *)0x00001330) + glContext);
    registerDirty = *(undefined4 *)(glContext + 0x1930);
  }
  (*pcVar3)(glContext,registerDirty);
  *(uint *)(glContext + 0x1930) = *(uint *)(glContext + 0x1930) & 0x3fefffff;
  return;
}

/* FUN_0004b480 @ 0x4b480 (148 bytes) */
int FUN_0004b480(glContext, param_2)
  int glContext;
  int param_2;
{
  int iVar1;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  code *a6;
  undefined4 registerDirty;
  
  iVar1 = param_2 * 4 + glContext;
  if (*(int *)(((unsigned char *)0x00001448) + iVar1) != 0) {
    registerDirty = *(undefined4 *)(glContext + 0x1930);
    *(undefined4 *)(glContext + 0x23e0) = 0;
    **(undefined1 **)(((unsigned char *)0x00001448) + iVar1) = 0;
    (**(code **)(((unsigned char *)0x00001290) + glContext))
              (glContext,*(undefined4 *)(((unsigned char *)0x00001448) + iVar1),in_r5,in_r6,in_r7,in_r8,0);
    a6 = *(code **)(((unsigned char *)0x00001330) + glContext);
    *(uint *)(glContext + 0x1f2c) = *(uint *)(glContext + 0x1f2c) & 0xfffff800 | 0x80;
    (*a6)(glContext,0xc0100000,in_r5,in_r6,in_r7,in_r8,a6);
    *(undefined4 *)(glContext + 0x1930) = registerDirty;
  }
  return;
}

/* FUN_0004b520 @ 0x4b520 (160 bytes) */
int FUN_0004b520(glContext, param_2)
  int glContext;
  int param_2;
{
  int *glContextWord1e7c;
  int loopIndex;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(glContext + 0x1e74);
  while( true ) {
    if (iVar3 < 1) {
      return;
    }
    glContextWord1e7c = *(int **)(glContext + 0x1e7c);
    loopIndex = 0;
    if (param_2 != *glContextWord1e7c) {
      loopIndex = 0;
      iVar4 = iVar3;
      do {
        loopIndex = loopIndex + 1;
        iVar4 = iVar4 + -1;
        if (iVar4 == 0) {
          return;
        }
      } while (param_2 != glContextWord1e7c[loopIndex]);
    }
    iVar3 = iVar3 + -1;
    *(int *)(glContext + 0x1e74) = iVar3;
    if (iVar3 == loopIndex) break;
    if (loopIndex < iVar3) {
      iVar4 = loopIndex << 2;
      while( true ) {
        loopIndex = loopIndex + 1;
        *(undefined4 *)(iVar4 + (int)glContextWord1e7c) = *(undefined4 *)((int)glContextWord1e7c + iVar4 + 4);
        iVar4 = iVar4 + 4;
        iVar3 = *(int *)(glContext + 0x1e74);
        if (iVar3 <= loopIndex) break;
        glContextWord1e7c = *(int **)(glContext + 0x1e7c);
      }
    }
  }
  return;
}

/* FUN_0004b5d0 @ 0x4b5d0 (296 bytes) */
int FUN_0004b5d0(glContext, param_2)
  int glContext;
  int param_2;
{
  int *glContextWord1e7c;
  int loopIndex;
  int iVar3;
  int iVar4;
  int iVar5;
  
  ((int (*)())FUN_0004a990)(glContext,param_2);
  if ((glContext != 0) && (iVar5 = *(int *)(((unsigned char *)0x000036c0) + param_2), iVar5 != 0)) {
    (**(code **)(glContext + 0x18))(*(undefined4 *)(iVar5 + 0xc));
    *(undefined4 *)(iVar5 + 0xc) = 0;
    iVar5 = *(int *)(((unsigned char *)0x000036c0) + param_2);
    iVar3 = *(int *)(glContext + 0x1e74);
    while (0 < iVar3) {
      glContextWord1e7c = *(int **)(glContext + 0x1e7c);
      loopIndex = 0;
      if (param_2 != *glContextWord1e7c) {
        loopIndex = 0;
        iVar4 = iVar3;
        do {
          loopIndex = loopIndex + 1;
          iVar4 = iVar4 + -1;
          if (iVar4 == 0) goto LAB_0004b6a8;
        } while (glContextWord1e7c[loopIndex] != param_2);
      }
      iVar3 = iVar3 + -1;
      *(int *)(glContext + 0x1e74) = iVar3;
      if (iVar3 == loopIndex) break;
      if (loopIndex < iVar3) {
        iVar4 = loopIndex << 2;
        while( true ) {
          loopIndex = loopIndex + 1;
          *(undefined4 *)(iVar4 + (int)glContextWord1e7c) = *(undefined4 *)((int)glContextWord1e7c + iVar4 + 4);
          iVar4 = iVar4 + 4;
          iVar3 = *(int *)(glContext + 0x1e74);
          if (iVar3 <= loopIndex) break;
          glContextWord1e7c = *(int **)(glContext + 0x1e7c);
        }
      }
    }
LAB_0004b6a8:
    (**(code **)(glContext + 0x18))(*(undefined4 *)(((unsigned char *)0x000036c0) + param_2));
    if (param_2 != iVar5 + 0x124) {
      *(undefined4 *)(((unsigned char *)0x000036c0) + param_2) = 0;
    }
  }
  return;
}

/* FUN_0004b710 @ 0x4b710 (188 bytes) */
int FUN_0004b710(glContext)
  int glContext;
{
  undefined *puVar1;
  int loopIndex;
  undefined *puVar3;
  
  if (*(short *)(glContext + 0x1e6c) != 0) {
    loopIndex = 0;
    puVar3 = (undefined *)0x0;
    do {
      loopIndex = loopIndex + 1;
      puVar1 = puVar3 + *(int *)(glContext + 0x1e60);
      puVar3 = ((unsigned char *)0x00003754U) + (int)puVar3;
      *(undefined4 *)(puVar1 + 0x1780) = 0;
      ((int (*)())FUN_0004b5d0)(glContext,puVar1);
    } while (loopIndex < (int)(uint)*(ushort *)(glContext + 0x1e6c));
  }
  _free(*(undefined4 *)(glContext + 0x1e60));
  _memset(*(undefined4 *)(((unsigned char *)0x00001114) + glContext),0xff,
          (uint)*(ushort *)(((unsigned char *)0x00001110) + glContext) << 1);
  *(undefined2 *)(glContext + 0x1e6c) = 0;
  *(undefined4 *)(glContext + 0x1e5c) = 0;
  *(undefined4 *)(glContext + 0x1e80) = 0;
  *(undefined4 *)(glContext + 0x1e84) = 0;
  *(undefined4 *)(glContext + 0x1e60) = 0;
  return;
}

/* FUN_0004b7d0 @ 0x4b7d0 (392 bytes) */
int FUN_0004b7d0(glContext)
  int glContext;
{
  int iVar1;
  int iVar2;
  undefined4 allocation;
  int iVar4;
  uint uVar5;
  uint loopIndex2;
  int loopIndex;
  int iVar8;
  
  iVar8 = *(int *)(((unsigned char *)0x0000112c) + glContext);
  ((int (*)())FUN_0004b710)(glContext);
  *(undefined2 *)(glContext + 0x1e6c) = 1;
  allocation = _malloc(((unsigned char *)0x00003754U));
  *(undefined4 *)(glContext + 0x1e60) = allocation;
  _memset(allocation,0,((unsigned char *)0x00003754U));
  *(undefined4 *)(glContext + 0x1e5c) = 0;
  ((int (*)())FUN_0004ab60)(glContext);
  *(undefined2 *)(((unsigned char *)0x000015c8) + *(int *)(glContext + 0x1e60)) = 0xffff;
  FUN_000b5fb0(glContext);
  iVar4 = *(int *)(((unsigned char *)0x00001154) + glContext);
  iVar1 = *(int *)(iVar4 + 0x88);
  if (iVar1 != 0) {
    uVar5 = *(uint *)(iVar4 + 4);
    loopIndex = 0;
    if (uVar5 != 0) {
      do {
        iVar1 = *(int *)(*(int *)(((unsigned char *)0x0000113c) + glContext) * 4 +
                        *(int *)(loopIndex * 0x78 + iVar1 + 0x70));
        if (iVar1 != 0) {
          *(undefined1 *)(iVar1 + 0x119) = 1;
          uVar5 = *(uint *)(iVar4 + 4);
        }
        iVar2 = uVar5 - loopIndex;
        if ((uVar5 < loopIndex + 1U) || (uVar5 == 0)) {
          iVar2 = 1;
        }
        do {
          loopIndex = loopIndex + 1;
          iVar2 = iVar2 + -1;
          if (iVar2 == 0) goto LAB_0004b8b8;
          iVar1 = *(int *)(iVar4 + 0x88);
        } while (iVar1 == 0);
      } while( true );
    }
  }
LAB_0004b8b8:
  uVar5 = *(uint *)(iVar8 + 4);
  if (uVar5 != 0) {
    loopIndex2 = 0;
    iVar1 = 0;
    do {
      iVar4 = iVar1 + *(int *)(iVar8 + 8);
      if (((*(int *)(iVar4 + 4) == 0x8804) &&
          (iVar4 = *(int *)(*(int *)(iVar4 + 0x14) + 0x70), iVar4 != 0)) &&
         (iVar4 = *(int *)(*(int *)(((unsigned char *)0x00001130) + glContext) * 4 + iVar4), iVar4 != 0)) {
        *(undefined1 *)(iVar4 + 0x119) = 1;
        uVar5 = *(uint *)(iVar8 + 4);
      }
      loopIndex2 = loopIndex2 + 1;
      iVar1 = iVar1 + 0x18;
    } while (loopIndex2 < uVar5);
  }
  return;
}

/* FUN_0004b980 @ 0x4b980 (616 bytes) */
int FUN_0004b980(param_1, param_2)
  int param_1;
  int param_2;
{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint *puVar7;
  uint uVar8;
  uint *puVar9;
  uint *puVar10;
  uint *puVar11;
  uint uVar12;
  uint uVar13;
  uint loopIndex;
  int iVar15;
  
  uVar13 = (uint)*(ushort *)(((unsigned char *)0x00001110) + param_1);
  iVar15 = *(int *)(param_1 + 0x1e60);
  if (uVar13 != 0x2811) {
    *(short *)(((unsigned char *)0x00001110) + param_1) = (short)(uVar13 + param_2);
    if (0x2811 < (uVar13 + param_2 & 0xffff)) {
      *(undefined2 *)(((unsigned char *)0x00001110) + param_1) = 0x2811;
    }
    iVar5 = (**(code **)(param_1 + 0xc))((uint)*(ushort *)(((unsigned char *)0x00001110) + param_1) << 1);
    _memset(iVar5,0xff,(uint)*(ushort *)(((unsigned char *)0x00001110) + param_1) << 1);
    if (uVar13 == 0) {
      iVar6 = *(int *)(((unsigned char *)0x00001114) + param_1);
    }
    else {
      iVar6 = *(int *)(((unsigned char *)0x00001114) + param_1);
      loopIndex = 0;
      do {
        uVar12 = (uint)*(ushort *)(loopIndex * 2 + iVar6);
        if (uVar12 != 0xffff) {
          do {
            iVar6 = iVar15 + uVar12 * 0x3754;
            puVar7 = (uint *)(((unsigned char *)0x000015c8) + iVar6);
            puVar9 = (uint *)(((unsigned char *)0x00001544) + iVar6);
            if (puVar7 < ((unsigned char *)0x00001570) + iVar6) {
              uVar8 = 0;
            }
            else {
              uVar8 = 0;
              puVar11 = (uint *)(((unsigned char *)0x00001570) + iVar6);
              puVar10 = puVar9;
              do {
                puVar9 = puVar11;
                uVar8 = uVar8 ^ *puVar10 ^ (puVar10[1] << 3 | puVar10[1] >> 0x1d) ^
                        (puVar10[2] << 6 | puVar10[2] >> 0x1a) ^
                        (puVar10[3] << 9 | puVar10[3] >> 0x17) ^
                        (puVar10[4] << 0xc | puVar10[4] >> 0x14) ^
                        (puVar10[5] << 0xf | puVar10[5] >> 0x11) ^
                        (puVar10[6] << 0x12 | puVar10[6] >> 0xe) ^
                        (puVar10[7] << 0x15 | puVar10[7] >> 0xb) ^
                        (puVar10[8] << 0x18 | puVar10[8] >> 8) ^
                        (puVar10[9] << 0x1b | puVar10[9] >> 5) ^
                        (puVar10[10] << 0x1e | puVar10[10] >> 2);
                puVar11 = puVar9 + 0xb;
                puVar10 = puVar9;
              } while (puVar9 + 0xb <= puVar7);
            }
            puVar11 = puVar9 + 5;
            if (puVar7 < puVar11) {
              uVar4 = 0;
              puVar11 = puVar9;
            }
            else {
              uVar4 = 0xf;
              uVar8 = uVar8 ^ *puVar9 ^ (puVar9[1] << 3 | puVar9[1] >> 0x1d) ^
                      (puVar9[2] << 6 | puVar9[2] >> 0x1a) ^ (puVar9[3] << 9 | puVar9[3] >> 0x17) ^
                      (puVar9[4] << 0xc | puVar9[4] >> 0x14);
            }
            for (; puVar11 < puVar7; puVar11 = puVar11 + 1) {
              uVar3 = uVar4 & 0x1f;
              uVar4 = uVar4 + 3;
              uVar8 = uVar8 ^ (*puVar11 << uVar3 | *puVar11 >> 0x20 - uVar3);
            }
            uVar1 = *(ushort *)(((unsigned char *)0x000015c8) + iVar6);
            iVar2 = (uVar8 - (uVar8 / *(ushort *)(((unsigned char *)0x00001110) + param_1)) *
                             (uint)*(ushort *)(((unsigned char *)0x00001110) + param_1)) * 2;
            *(undefined2 *)(((unsigned char *)0x000015c8) + iVar6) = *(undefined2 *)(iVar5 + iVar2);
            *(short *)(iVar5 + iVar2) = (short)uVar12;
            uVar12 = (uint)uVar1;
          } while (uVar1 != 0xffff);
          iVar6 = *(int *)(((unsigned char *)0x00001114) + param_1);
        }
        loopIndex = loopIndex + 1;
      } while (loopIndex < uVar13);
    }
    (**(code **)(param_1 + 0x18))(iVar6);
    *(int *)(((unsigned char *)0x00001114) + param_1) = iVar5;
  }
  return;
}

/* FUN_0004bbf0 @ 0x4bbf0 (1244 bytes) */
int FUN_0004bbf0(glContext)
  int glContext;
{
  int glContextWord1e60;
  ushort glContextWord1e6c;
  undefined4 allocation2;
  int allocation;
  int loopIndex;
  uint *puVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  ushort uVar7;
  uint *puVar8;
  undefined4 uVar9;
  uint uVar10;
  uint *puVar11;
  uint *puVar12;
  uint *puVar13;
  uint *puVar14;
  int iVar15;
  undefined *puVar16;
  uint uVar17;
  
  uVar17 = 0x11;
  puVar8 = (uint *)(glContext + 0x18a4);
  if (*(byte *)(glContext + 0x2b) < 9) {
    uVar17 = (uint)*(byte *)(glContext + 0x2b) * 2 + 1;
  }
  cVar2 = ((unsigned char *)0x00001112)[glContext];
  if (cVar2 == '\0') {
    puVar11 = (uint *)(glContext + 0x18e8);
    uVar7 = *(ushort *)(((unsigned char *)0x00001110) + glContext);
    if (puVar11 < (uint *)(glContext + 0x18d0)) {
      uVar5 = 0;
      puVar12 = puVar8;
    }
    else {
      uVar5 = 0;
      puVar14 = (uint *)(glContext + 0x18d0);
      puVar13 = puVar8;
      do {
        puVar12 = puVar14;
        uVar5 = uVar5 ^ *puVar13 ^ (puVar13[1] << 3 | puVar13[1] >> 0x1d) ^
                (puVar13[2] << 6 | puVar13[2] >> 0x1a) ^ (puVar13[3] << 9 | puVar13[3] >> 0x17) ^
                (puVar13[4] << 0xc | puVar13[4] >> 0x14) ^ (puVar13[5] << 0xf | puVar13[5] >> 0x11)
                ^ (puVar13[6] << 0x12 | puVar13[6] >> 0xe) ^
                (puVar13[7] << 0x15 | puVar13[7] >> 0xb) ^ (puVar13[8] << 0x18 | puVar13[8] >> 8) ^
                (puVar13[9] << 0x1b | puVar13[9] >> 5) ^ (puVar13[10] << 0x1e | puVar13[10] >> 2);
        puVar14 = puVar12 + 0xb;
        puVar13 = puVar12;
      } while (puVar12 + 0xb <= puVar11);
    }
    puVar14 = puVar12 + 5;
    if (puVar11 < puVar14) {
      uVar10 = 0;
      puVar14 = puVar12;
    }
    else {
      uVar10 = 0xf;
      uVar5 = uVar5 ^ *puVar12 ^ (puVar12[1] << 3 | puVar12[1] >> 0x1d) ^
              (puVar12[2] << 6 | puVar12[2] >> 0x1a) ^ (puVar12[3] << 9 | puVar12[3] >> 0x17) ^
              (puVar12[4] << 0xc | puVar12[4] >> 0x14);
    }
    for (; puVar14 < puVar11; puVar14 = puVar14 + 1) {
      uVar3 = uVar10 & 0x1f;
      uVar10 = uVar10 + 3;
      uVar5 = uVar5 ^ (*puVar14 << uVar3 | *puVar14 >> 0x20 - uVar3);
    }
    uVar5 = uVar5 - (uVar5 / uVar7) * (uint)uVar7;
  }
  else {
    uVar7 = *(ushort *)(((unsigned char *)0x00001110) + glContext);
    uVar5 = *(int *)(glContext + 0x18a8) + *(int *)(glContext + 0x18b0) + *(int *)(glContext + 0x18b8) +
            *(int *)(glContext + 0x18c0);
    uVar5 = uVar5 - (uVar5 / uVar7) * (uint)uVar7;
  }
  iVar6 = *(int *)(((unsigned char *)0x00001114) + glContext);
  iVar4 = (uVar5 & 0xffff) * 2;
  *(undefined4 *)(glContext + 0x277c) = 0xffffffff;
  uVar5 = (uint)*(ushort *)(iVar6 + iVar4);
  if (uVar5 == 0xffff) {
    loopIndex = 0;
  }
  else {
    loopIndex = 0;
    uVar10 = uVar5;
    do {
      uVar5 = uVar10;
      loopIndex = loopIndex + 1;
      glContextWord1e60 = *(int *)(glContext + 0x1e60) + uVar5 * 0x3754;
      puVar16 = ((unsigned char *)0x00001544) + glContextWord1e60;
      if ((*puVar8 == *(uint *)(((unsigned char *)0x00001544) + glContextWord1e60) &&
          *(int *)(glContext + 0x18a8) == *(int *)(((unsigned char *)0x00001548) + glContextWord1e60)) &&
          *(int *)(glContext + 0x18ac) == *(int *)(((unsigned char *)0x0000154c) + glContextWord1e60)) {
        if (uVar17 < 4) {
LAB_0004bee0:
          *(int *)(glContext + 0x1e5c) = glContextWord1e60;
          return 1;
        }
        if (*(int *)(((unsigned char *)0x00001550) + glContextWord1e60) == *(int *)(glContext + 0x18b0) &&
            *(int *)(((unsigned char *)0x00001554) + glContextWord1e60) == *(int *)(glContext + 0x18b4)) {
          uVar10 = 3;
          puVar11 = puVar8;
          do {
            uVar10 = uVar10 + 2;
            if (uVar17 <= uVar10) goto LAB_0004bee0;
            puVar12 = (uint *)(puVar16 + 0x18);
            puVar14 = puVar11 + 6;
            puVar13 = (uint *)(puVar16 + 0x14);
            puVar1 = puVar11 + 5;
            puVar16 = puVar16 + 8;
            puVar11 = puVar11 + 2;
          } while (*puVar13 == *puVar1 && *puVar14 == *puVar12);
        }
      }
      uVar10 = (uint)*(ushort *)(((unsigned char *)0x000015c8) + glContextWord1e60);
    } while (*(ushort *)(((unsigned char *)0x000015c8) + glContextWord1e60) != 0xffff);
  }
  if ((cVar2 == '\0') || (loopIndex < 7)) {
    if ((loopIndex < 8) || (0x2810 < uVar7)) {
      glContextWord1e6c = *(ushort *)(glContext + 0x1e6c);
      if (0x400 < glContextWord1e6c) {
        uVar5 = 0;
        ((int (*)())FUN_0004b710)(glContext);
        *(undefined2 *)(glContext + 0x1e6c) = 1;
        allocation2 = _malloc(((unsigned char *)0x00003754U));
        *(undefined4 *)(glContext + 0x1e60) = allocation2;
        _memset(allocation2,0,((unsigned char *)0x00003754U));
        ((int (*)())FUN_0004ab60)(glContext);
        *(undefined2 *)(((unsigned char *)0x000015c8) + *(int *)(glContext + 0x1e60)) = 0xffff;
        glContextWord1e6c = *(ushort *)(glContext + 0x1e6c);
      }
      *(ushort *)(glContext + 0x1e6c) = glContextWord1e6c + 1;
      if (*(int *)(glContext + 0x1e68) != 0) {
        ((unsigned char *)0x000010e9)[*(int *)(glContext + 0x1e68)] = 0;
        ((unsigned char *)0x000010ea)[*(int *)(glContext + 0x1e68)] = 0;
        ((unsigned char *)0x000010eb)[*(int *)(glContext + 0x1e68)] = 0;
        *(undefined4 *)(glContext + 0x1e68) = 0;
      }
      if (0 < *(int *)(glContext + 0x1e74)) {
        loopIndex = 0;
        do {
          iVar15 = loopIndex * 4;
          loopIndex = loopIndex + 1;
          ((unsigned char *)0x000010e9)[*(int *)(*(int *)(glContext + 0x1e7c) + iVar15)] = 0;
          ((unsigned char *)0x000010ea)[*(int *)(*(int *)(glContext + 0x1e7c) + iVar15)] = 0;
        } while (loopIndex < *(int *)(glContext + 0x1e74));
      }
      *(undefined4 *)(glContext + 0x1e74) = 0;
      allocation = _realloc(*(undefined4 *)(glContext + 0x1e60),
                       (uint)*(ushort *)(glContext + 0x1e6c) * 0x3754);
      *(int *)(glContext + 0x1e60) = allocation;
      if (allocation == 0) {
        return 0;
      }
      glContextWord1e6c = *(ushort *)(glContext + 0x1e6c);
      iVar15 = *(int *)(((unsigned char *)0x00001114) + glContext);
      *(uint *)(glContext + 0x1e5c) = allocation + (uint)glContextWord1e6c * 0x3754 + -0x3754;
      if (*(short *)(iVar4 + iVar15) == -1) {
        *(ushort *)(iVar4 + iVar15) = glContextWord1e6c - 1;
      }
      else {
        *(ushort *)(((unsigned char *)0x000015c8) + uVar5 * 0x3754 + allocation) = glContextWord1e6c - 1;
      }
      _memset(*(undefined4 *)(glContext + 0x1e5c),0,((unsigned char *)0x00003754U));
      *(undefined2 *)(((unsigned char *)0x000015c8) + *(int *)(glContext + 0x1e5c)) = 0xffff;
      _memcpy(((unsigned char *)0x00001544) + *(int *)(glContext + 0x1e5c),glContext + 0x18a4,0x84);
      return 0;
    }
    if (cVar2 == '\0') {
      ((int (*)())FUN_0004b980)(glContext,0x313);
      goto LAB_0004bf48;
    }
  }
  ((int (*)())FUN_0004b980)(glContext,0);
  ((unsigned char *)0x00001112)[glContext] = 0;
LAB_0004bf48:
  uVar9 = ((int (*)())FUN_0004bbf0)(glContext);
  return uVar9;
}

/* FUN_0004c100 @ 0x4c100 (336 bytes) */
int FUN_0004c100(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  iVar2 = *(int *)(param_2 + 0x1e64);
  if (iVar2 != 0) {
    if (*(int *)(param_2 + 0x23e0) == 0) {
      uVar4 = *(uint *)(((unsigned char *)0x000036a8) + iVar2);
      puVar5 = (undefined4 *)(iVar2 + 4);
      puVar1 = ((unsigned char *)0x000010ec);
    }
    else {
      uVar4 = *(uint *)(((unsigned char *)0x000036b4) + iVar2);
      puVar5 = (undefined4 *)(iVar2 + 0x20);
      puVar1 = ((unsigned char *)0x00001318);
    }
    *(undefined4 *)(param_1 + 0x250) = *(undefined4 *)(puVar1 + iVar2 + 0x44);
    *(undefined4 *)(param_1 + 600) = *(undefined4 *)(puVar1 + iVar2 + 0x48);
    uVar3 = puVar5[2];
    *(undefined4 *)(param_1 + 0x218) = 0;
    *(undefined4 *)(param_1 + 0x220) = uVar3;
    *(undefined4 *)(param_1 + 0x210) = puVar5[3];
    *(undefined4 *)(param_1 + 0x208) = *puVar5;
    *(undefined4 *)(param_1 + 0x200) = puVar5[1];
    if (uVar4 != 0) {
      *(undefined4 *)(param_1 + 0x108) = *(undefined4 *)puVar5[4];
      *(undefined4 *)(param_1 + 0x110) = *(undefined4 *)(puVar5[4] + 4);
      *(undefined4 *)(param_1 + 0x118) = *(undefined4 *)(puVar5[4] + 8);
      *(undefined4 *)(param_1 + 0x120) = *(undefined4 *)(puVar5[4] + 0xc);
      *(undefined4 *)(param_1 + 0x128) = *(undefined4 *)(puVar5[4] + 0x10);
      *(undefined4 *)(param_1 + 0x130) = *(undefined4 *)(puVar5[4] + 0x14);
      if (1 < uVar4) {
        *(undefined4 *)(param_1 + 0x138) = *(undefined4 *)(puVar5[4] + 0x18);
        *(undefined4 *)(param_1 + 0x140) = *(undefined4 *)(puVar5[4] + 0x1c);
        *(undefined4 *)(param_1 + 0x148) = *(undefined4 *)(puVar5[4] + 0x20);
        *(undefined4 *)(param_1 + 0x150) = *(undefined4 *)(puVar5[4] + 0x24);
        *(undefined4 *)(param_1 + 0x158) = *(undefined4 *)(puVar5[4] + 0x28);
        *(undefined4 *)(param_1 + 0x160) = *(undefined4 *)(puVar5[4] + 0x2c);
        return;
      }
      goto LAB_0004c1ac;
    }
  }
  *(undefined4 *)(param_1 + 0x1fc) = 0xc0001000;
  *(undefined4 *)(param_1 + 0x104) = 0xc00a1000;
  *(undefined4 *)(param_1 + 0x24c) = 0xc0001000;
  *(undefined4 *)(param_1 + 0x254) = 0xc0001000;
  *(undefined4 *)(param_1 + 0x21c) = 0xc0001000;
  *(undefined4 *)(param_1 + 0x214) = 0xc0001000;
  *(undefined4 *)(param_1 + 0x20c) = 0xc0001000;
  *(undefined4 *)(param_1 + 0x204) = 0xc0001000;
LAB_0004c1ac:
  *(undefined4 *)(param_1 + 0x134) = 0xc00a1000;
  return;
}


/* issue: auto-generated aliases bridging data.s/code.s references (written
 * without a leading underscore, matching the raw stock-binary symbol name)
 * against the real compiled C symbols (gcc adds one underscore automatically).
 * Needed because ld64 (required for this PPC binary's size - stock ld breaks on
 * large PPC links) does not silently reconcile this the way stock ld did. */
asm(".globl fragmentTranslateSimpleOp");
asm(".set fragmentTranslateSimpleOp, _fragmentTranslateSimpleOp");
asm(".globl fragmentTranslateRep");
asm(".set fragmentTranslateRep, _fragmentTranslateRep");
asm(".globl fragmentTranslateDdy");
asm(".set fragmentTranslateDdy, _fragmentTranslateDdy");
asm(".globl fragmentTranslateScalarMath");
asm(".set fragmentTranslateScalarMath, _fragmentTranslateScalarMath");
asm(".globl fragmentTranslateTrig");
asm(".set fragmentTranslateTrig, _fragmentTranslateTrig");
asm(".globl fragmentTranslateAngleConvert");
asm(".set fragmentTranslateAngleConvert, _fragmentTranslateAngleConvert");
asm(".globl fragmentTranslateMod");
asm(".set fragmentTranslateMod, _fragmentTranslateMod");
asm(".globl fragmentTranslateAtn");
asm(".set fragmentTranslateAtn, _fragmentTranslateAtn");
asm(".globl fragmentTranslateRfr");
asm(".set fragmentTranslateRfr, _fragmentTranslateRfr");
asm(".globl fragmentTranslateFfw");
asm(".set fragmentTranslateFfw, _fragmentTranslateFfw");
asm(".globl fragmentTranslateDst");
asm(".set fragmentTranslateDst, _fragmentTranslateDst");
asm(".globl fragmentTranslateIf");
asm(".set fragmentTranslateIf, _fragmentTranslateIf");
asm(".globl fragmentTranslateRfl");
asm(".set fragmentTranslateRfl, _fragmentTranslateRfl");
asm(".globl fragmentTranslateWhile");
asm(".set fragmentTranslateWhile, _fragmentTranslateWhile");
