#include "decls.h"

/* _glDepthMask_ListExec @ 0x4595c (40 bytes) */
int _glDepthMask_ListExec(param_1, param_2)
  undefined4 param_1;
  byte *param_2;
{
  _glDepthMask_Exec(param_1,(uint)*param_2);
  return 4;
}

/* _gleEndDrawArraysOrElementsOutOfLine_ListExec @ 0x45984 (72 bytes) */
int _gleEndDrawArraysOrElementsOutOfLine_ListExec(param_1)
  int param_1;
{
  _gleSetCurrentVertexObject(param_1,*(undefined4 *)(param_1 + 0x5414));
  _gleSetClientEnableFlag(param_1,0x851d,(uint)*(byte *)(param_1 + 0x5411));
  return 4;
}

/* _gleOptimizedListFreeFunc @ 0x459cc (108 bytes) */
void _gleOptimizedListFreeFunc(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  uint *puVar1;
  uint *address;
  
  puVar1 = (uint *)*param_2;
  address = puVar1;
  if ((*puVar1 & 1) != 0) {
    _gleFreeVertexArrayObject(param_1,puVar1[1]);
    *puVar1 = 0;
    address = (uint *)*param_2;
  }
  _vm_deallocate(*(vm_map_t *)PTR_00112034,(vm_address_t)address,puVar1[3]);
  return;
}

/* _glReadBuffer_Exec @ 0x45a38 (404 bytes) */
void _glReadBuffer_Exec(param_1, param_2)
  int param_1;
  uint param_2;
{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (-1 < *(short *)(param_1 + 0x4a10)) goto LAB_00045bb4;
  if (param_2 == 0x404) {
LAB_00045abc:
    iVar3 = 0;
    if (*(int *)(param_1 + 0x744c) == 0) goto LAB_00045b84;
    goto LAB_00045bb4;
  }
  if (param_2 < 0x405) {
    if (param_2 == 0x401) {
LAB_00045ae8:
      if (*(int *)(param_1 + 0x744c) == 0) goto LAB_00045b10;
    }
    else {
      if (param_2 < 0x402) {
        if (param_2 != 0) {
          bVar1 = param_2 == 0x400;
LAB_00045aa4:
          if (!bVar1) goto LAB_00045b44;
          goto LAB_00045abc;
        }
LAB_00045b78:
        iVar3 = *(int *)(param_1 + 0x744c);
        bVar1 = iVar3 == 0;
      }
      else {
        if (param_2 == 0x402) goto LAB_00045acc;
        if (param_2 != 0x403) goto LAB_00045b44;
        if ((*(int *)(param_1 + 0x744c) != 0) || (*(char *)(param_1 + 0x7582) == '\0'))
        goto LAB_00045bb4;
LAB_00045b10:
        iVar3 = 0;
        bVar1 = *(char *)(*(int *)(param_1 + 0x468c) + 0x26) == '\0';
      }
      if (!bVar1) {
LAB_00045b84:
        if (iVar3 == 0) {
          *(short *)(param_1 + 0x3118) = (short)param_2;
        }
        else {
          *(short *)(iVar3 + 200) = (short)param_2;
          *(undefined4 *)(*(int *)(param_1 + 0x744c) + 0xec) = 1;
        }
        *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x100;
        return;
      }
    }
  }
  else {
    if (param_2 == 0x407) goto LAB_00045ae8;
    if (param_2 < 0x408) {
      if (param_2 != 0x405) {
        bVar1 = param_2 == 0x406;
        goto LAB_00045aa4;
      }
LAB_00045acc:
      if (*(int *)(param_1 + 0x744c) == 0) {
        iVar3 = 0;
        if (*(char *)(param_1 + 0x7582) != '\0') goto LAB_00045b84;
LAB_00045b64:
        if (*(int *)(param_1 + 0x7574) != 0) {
          return;
        }
        uVar2 = 0x500;
        goto LAB_00045bc4;
      }
    }
    else {
      if (3 < param_2 - 0x409) {
LAB_00045b44:
        if ((0x8cdf < param_2) && (param_2 < *(int *)(*(int *)(param_1 + 0x468c) + 0x18) + 0x8ce0U))
        goto LAB_00045b78;
        goto LAB_00045b64;
      }
      if ((*(int *)(param_1 + 0x744c) == 0) &&
         (param_2 < *(int *)(*(int *)(param_1 + 0x468c) + 0x54) + 0x409U)) {
        iVar3 = 0;
        goto LAB_00045b84;
      }
    }
  }
LAB_00045bb4:
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar2 = 0x502;
LAB_00045bc4:
  *(undefined4 *)(param_1 + 0x7574) = uVar2;
  return;
}

/* _glReadPixels_Exec @ 0x45bcc (1436 bytes) */
void _glReadPixels_Exec(int param_1,undefined4 param_2,undefined4 param_3,uint param_4,int param_5,uint param_6,uint param_7,int param_8,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int *piVar10;
  int iVar11;
  double extraout_f1;
  double dVar12;
  
  if (param_7 < 0x8037) {
    if (param_7 < 0x8033) {
      if (param_7 != 0x140b) {
        if (param_7 < 0x140c) {
          if (param_7 - 0x1400 < 7) goto LAB_00045c78;
        }
        else if (param_7 == 0x1a00) {
          if (param_6 - 0x1900 < 2) goto LAB_00045d24;
        }
        else if (param_7 == 0x8032) goto LAB_00045cb0;
LAB_00045d00:
        if (*(int *)(param_1 + 0x7574) != 0) {
          return;
        }
        uVar4 = 0x500;
        goto LAB_00046050;
      }
LAB_00045c78:
      if (param_6 != 0x8000) {
        if (param_6 < 0x8001) {
          bVar1 = 10 < param_6 - 0x1900;
        }
        else {
          bVar1 = 1 < param_6 - 0x80e0;
        }
        if (bVar1) goto LAB_00046040;
      }
    }
    else {
LAB_00045cb8:
      if (param_6 != 0x1908) {
        bVar1 = param_6 == 0x80e1;
        goto LAB_00045ccc;
      }
    }
LAB_00045d24:
    iVar6 = *(int *)(param_1 + 0x744c);
    if (iVar6 != 0) {
      iVar8 = *(int *)(param_1 + 0x50ac);
      uVar4 = param_3;
      uVar9 = param_4;
      iVar3 = param_5;
      uVar7 = param_6;
      if (iVar8 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
        _gleUpdateMatrixFunc(param_1);
        iVar6 = *(int *)(param_1 + 0x744c);
        fparam_1 = extraout_f1;
      }
      if (*(char *)(param_1 + 0x4691) != '\0') {
        piVar10 = (int *)(param_1 + 0x310);
        cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
        if ((iVar6 != 0) && (*(int *)(iVar6 + 0xec) != 0)) {
          ((void (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar6 + 0x10,uVar4,uVar9,iVar3,uVar7,iVar8,fparam_1,fparam_2,fparam_3,
                     fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
          *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
        }
        if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_00045e20:
          uVar9 = *(uint *)(param_1 + 0x31c);
        }
        else {
          iVar6 = 0;
          piVar5 = (int *)(param_1 + 0x324);
          do {
            iVar3 = *piVar5;
            piVar5 = piVar5 + 1;
            if (iVar3 != 0) {
              *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
              break;
            }
            iVar6 = iVar6 + 1;
          } while (iVar6 < 9);
          uVar9 = *(uint *)(param_1 + 0x31c);
          if ((uVar9 & 0x15555) != 0) {
            if (*(char *)(param_1 + 0x2e54) != '\0') {
              _gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
            }
            if (*(char *)(param_1 + 0x3094) != '\0') {
              _gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
            }
            goto LAB_00045e20;
          }
        }
        bVar1 = cVar2 == '\0';
        if (bVar1) {
          uVar9 = uVar9 & 0x17000000;
        }
        else {
          uVar9 = uVar9 & 0x17ffffff;
        }
        if (bVar1) {
          bVar1 = ((*piVar10 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar9 == 0) &&
                  *(int *)(param_1 + 800) == 0;
        }
        else {
          bVar1 = (((*piVar10 == 0 && *(int *)(param_1 + 0x314) == 0) &&
                   (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar9 == 0) &&
                  *(int *)(param_1 + 800) == 0;
        }
        if (!bVar1) {
          if (*(char *)(param_1 + 0x85a8) == *(char *)(param_1 + 0x85a6)) {
            uVar9 = (**(code **)(param_1 + 0x4788))
                              (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar10);
            if ((((uVar9 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
                ((uVar9 & 4) != (uint)*(byte *)(param_1 + 0x7581))) ||
               ((uVar9 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0'))) {
              if ((uVar9 & 4) == 0) {
                uVar9 = uVar9 & 0xfffffffe;
                *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
              }
              _gleUpdateDispatchCodeChange(param_1,uVar9);
              if (*(char *)(param_1 + 0x759d) == '\0') {
                if (*(int *)(param_1 + 0x7574) != 0) {
                  return;
                }
                uVar4 = 0x506;
                goto LAB_00046050;
              }
            }
          }
          else {
            _gleSwitchToNonRevertRenderer(param_1);
          }
          iVar6 = 0;
          do {
            iVar6 = iVar6 + 1;
            *piVar10 = 0;
            piVar10 = piVar10 + 1;
          } while (iVar6 < 0x13);
        }
        iVar6 = *(int *)(param_1 + 0x744c);
      }
      if (((*(short *)(iVar6 + 200) == 0) && (param_6 != 0x1901)) && (param_6 != 0x1902))
      goto LAB_00046040;
    }
    if (((*(short *)(param_1 + 0x4a10) < 0) && (param_6 != 0x1900)) &&
       (((param_6 != 0x1901 || (*(int *)(*(int *)(param_1 + 0x468c) + 0x40) != 0)) &&
        ((param_6 != 0x1902 || (*(int *)(*(int *)(param_1 + 0x468c) + 0x3c) != 0)))))) {
      if (((int)param_4 < 0) || (param_5 < 0)) {
        if (*(int *)(param_1 + 0x7574) != 0) {
          return;
        }
        uVar4 = 0x501;
        goto LAB_00046050;
      }
      iVar6 = *(int *)(param_1 + 0x4a68);
      if (iVar6 == 0) {
LAB_0004611c:
        (**(code **)(param_1 + 0x46a0))
                  (*(undefined4 *)(param_1 + 0x4688),param_2,param_3,param_4,param_5,param_6,param_7
                   ,param_8);
        return;
      }
      iVar8 = _gleOffsetLimitImage(param_1 + 0x31b0,param_4,param_5,param_6,param_7,param_8);
      iVar11 = *(int *)(iVar6 + 0x38);
      dVar12 = (double)((double (*)())_gleBytesPerElement)(param_7);
      iVar3 = (int)dVar12;
      if (iVar8 <= iVar11) {
        if (iVar3 == 0) {
          iVar3 = _glePixelBytes(param_6,param_7);
        }
        if (param_8 == (param_8 / iVar3) * iVar3) {
          param_8 = param_8 + *(int *)(iVar6 + 0x30);
          iVar3 = (**(code **)(param_1 + 0x46a0))
                            (*(undefined4 *)(param_1 + 0x4688),param_2,param_3,param_4,param_5,
                             param_6,param_7,param_8);
          if (iVar3 != 0) {
            *(undefined4 *)(iVar6 + 0x40) =
                 *(undefined4 *)
                  ((uint)*(byte *)(param_1 + 0x85a8) * 4 + *(int *)(param_1 + 0x5148) + 0x8054);
            return;
          }
          if (*(int *)(iVar6 + 0x40) != 0) {
            _gleSynchronizePluginBuffer(param_1,iVar6 + 0x10);
          }
          iVar3 = 0;
          if (*(char *)(param_1 + 0x85a4) != '\0') {
            do {
              iVar3 = iVar3 + 1;
              *(uint *)(iVar6 + 0x48) = *(uint *)(iVar6 + 0x48) | 2;
              iVar6 = iVar6 + 4;
            } while (iVar3 < (int)(uint)*(byte *)(param_1 + 0x85a4));
          }
          goto LAB_0004611c;
        }
      }
    }
  }
  else if (param_7 < 0x8369) {
    if (0x8364 < param_7) goto LAB_00045cb8;
    if (param_7 < 0x8362) goto LAB_00045d00;
LAB_00045cb0:
    bVar1 = param_6 == 0x1907;
LAB_00045ccc:
    if (bVar1) goto LAB_00045d24;
  }
  else {
    if (1 < param_7 - 0x85ba) goto LAB_00045d00;
    if ((param_6 == 0x85b9) && ((param_4 & 1) == 0)) goto LAB_00045d24;
  }
LAB_00046040:
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar4 = 0x502;
LAB_00046050:
  *(undefined4 *)(param_1 + 0x7574) = uVar4;
  return;
}

/* _gleSetEnable_NORMALIZE @ 0x46168 (44 bytes) */
void _gleSetEnable_NORMALIZE(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint param_3;
{
  if (*(byte *)(param_1 + 0x280d) == param_3) {
    return;
  }
  *(char *)(param_1 + 0x280d) = (char)param_3;
  *(uint *)(param_1 + 0x50ac) = *(uint *)(param_1 + 0x50ac) | 1;
  *(uint *)(param_1 + 0x318) = *(uint *)(param_1 + 0x318) | 0x40000000;
  return;
}

/* FUN_00046198 @ 0x46198 (1032 bytes) */
void FUN_00046198(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  uint param_3;
  undefined *param_4;
  uint *param_5;
{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  undefined *puVar9;
  uint *puVar10;
  undefined4 in_r8;
  uint uVar11;
  int *piVar12;
  double extraout_f1;
  double extraout_f1_00;
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  uint local_40 [7];
  
  local_40[0] = 0xffffffff;
  uVar11 = param_3;
  puVar9 = param_4;
  puVar10 = param_5;
  iVar7 = ((int (*)())_gleLookUpTexture)(param_1,param_2);
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
    goto LAB_00046300;
  }
  if (iVar7 == 0) goto LAB_000462f0;
  if (0xe < param_3) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x501;
    goto LAB_00046300;
  }
  uVar4 = param_2 - 0x8515;
  if (5 < uVar4) {
    uVar4 = 0;
  }
  iVar5 = iVar7 + uVar4 * 0x168 + param_3 * 0x18;
  if ((undefined *)0x8061 < param_4) {
    if (param_4 < (undefined *)0x86a2) {
      if ((undefined *)0x869f < param_4) {
LAB_000462e8:
        local_40[0] = 0xffffffff;
        goto LAB_00046318;
      }
      if (param_4 == (undefined *)0x8071) {
        local_40[0] = (uint)*(ushort *)(iVar5 + 0xcc);
        goto LAB_00046318;
      }
    }
    else if (param_4 == (undefined *)0x884a) goto LAB_000462e8;
LAB_000462f0:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x500;
LAB_00046300:
    *(undefined4 *)(param_1 + 0x7574) = uVar3;
    return;
  }
  if ((undefined *)0x805b < param_4) goto LAB_000462e8;
  if (param_4 != ((unsigned char *)0x00001001)) {
    if (((unsigned char *)0x00001001) < param_4) {
      if (param_4 == ((unsigned char *)0x00001003)) goto LAB_000462e8;
      if (param_4 == ((unsigned char *)0x00001005)) {
        local_40[0] = (uint)*(byte *)(iVar5 + 0xce);
        goto LAB_00046318;
      }
    }
    else if (param_4 == (undefined *)0x1000) {
      local_40[0] = (uint)*(ushort *)(iVar5 + 200);
      goto LAB_00046318;
    }
    goto LAB_000462f0;
  }
  local_40[0] = (uint)*(ushort *)(iVar5 + 0xca);
LAB_00046318:
  if ((*(ushort *)(iVar7 + 0x24) & 0x100) == 0) goto LAB_00046520;
  iVar5 = *(int *)(param_1 + 0x50ac);
  fparam_1 = extraout_f1;
  if (iVar5 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(param_1);
    fparam_1 = extraout_f1_00;
  }
  if (*(char *)(param_1 + 0x4691) == '\0') goto LAB_00046520;
  iVar8 = *(int *)(param_1 + 0x744c);
  piVar12 = (int *)(param_1 + 0x310);
  cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
  if ((iVar8 != 0) && (*(int *)(iVar8 + 0xec) != 0)) {
    ((void (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar8 + 0x10,uVar11,puVar9,puVar10,in_r8,iVar5,fparam_1,in_f2,in_f3,in_f4,
               in_f5,in_f6,in_f7,in_f8);
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
  }
  if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_00046418:
    uVar11 = *(uint *)(param_1 + 0x31c);
  }
  else {
    iVar5 = 0;
    piVar6 = (int *)(param_1 + 0x324);
    do {
      iVar8 = *piVar6;
      piVar6 = piVar6 + 1;
      if (iVar8 != 0) {
        *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
        break;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < 9);
    uVar11 = *(uint *)(param_1 + 0x31c);
    if ((uVar11 & 0x15555) != 0) {
      if (*(char *)(param_1 + 0x2e54) != '\0') {
        _gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
      }
      if (*(char *)(param_1 + 0x3094) != '\0') {
        _gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
      }
      goto LAB_00046418;
    }
  }
  bVar1 = cVar2 == '\0';
  if (bVar1) {
    uVar11 = uVar11 & 0x17000000;
  }
  else {
    uVar11 = uVar11 & 0x17ffffff;
  }
  if (bVar1) {
    bVar1 = ((*piVar12 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar11 == 0) &&
            *(int *)(param_1 + 800) == 0;
  }
  else {
    bVar1 = (((*piVar12 == 0 && *(int *)(param_1 + 0x314) == 0) &&
             (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar11 == 0) &&
            *(int *)(param_1 + 800) == 0;
  }
  if (!bVar1) {
    if (*(char *)(param_1 + 0x85a8) == *(char *)(param_1 + 0x85a6)) {
      uVar11 = (**(code **)(param_1 + 0x4788))
                         (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar12);
      if ((((uVar11 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
          ((uVar11 & 4) != (uint)*(byte *)(param_1 + 0x7581))) ||
         ((uVar11 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0'))) {
        if ((uVar11 & 4) == 0) {
          uVar11 = uVar11 & 0xfffffffe;
          *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
        }
        _gleUpdateDispatchCodeChange(param_1,uVar11);
      }
    }
    else {
      _gleSwitchToNonRevertRenderer(param_1);
    }
  }
  iVar5 = 0x13;
  do {
    *piVar12 = 0;
    piVar12 = piVar12 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
LAB_00046520:
  if ((local_40[0] == 0xffffffff) || ((*(ushort *)(iVar7 + 0x24) & 0x100) != 0)) {
    (**(code **)(param_1 + 0x479c))
              (*(undefined4 *)(param_1 + 0x4688),
               *(undefined4 *)(iVar7 + (uint)*(byte *)(param_1 + 0x85a8) * 4),uVar4,param_3,param_4,
               local_40);
  }
  if ((param_4 == ((unsigned char *)0x00001003)) && (local_40[0] == 0)) {
    local_40[0] = 1;
  }
  *param_5 = local_40[0];
  return;
}

/* _gleLookUpTexture @ 0x465a0 (360 bytes) */
int _gleLookUpTexture(param_1, param_2)
  int param_1;
  uint param_2;
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x53d4);
  if (param_2 != 0x84f5) {
    if (param_2 < 0x84f6) {
      if (param_2 == 0x8063) {
        iVar1 = *(int *)(param_1 + 0x52b8);
LAB_000466e0:
        return iVar1 + 0x10;
      }
      if (param_2 < 0x8064) {
        if (param_2 == 0xde0) {
          iVar1 = *(int *)(iVar1 * 0x14 + param_1 + 0x5164);
        }
        else {
          if (param_2 != 0xde1) {
            return 0;
          }
          iVar1 = *(int *)(iVar1 * 0x14 + param_1 + 0x5160);
        }
      }
      else {
        if (param_2 != 0x806f) {
          if (param_2 < 0x8070) {
            if (param_2 != 0x8064) {
              return 0;
            }
            iVar1 = *(int *)(param_1 + 0x52b4);
          }
          else {
            if (param_2 != 0x8070) {
              return 0;
            }
            iVar1 = *(int *)(param_1 + 0x52ac);
          }
          goto LAB_000466e0;
        }
        iVar1 = *(int *)(iVar1 * 0x14 + param_1 + 0x5158);
      }
      goto LAB_0004669c;
    }
    if (param_2 < 0x851b) {
      if (param_2 < 0x8515) {
        if (param_2 == 0x84f7) {
          iVar1 = *(int *)(param_1 + 0x52b0);
          goto LAB_000466e0;
        }
        if (param_2 != 0x8513) {
          return 0;
        }
      }
      iVar1 = *(int *)(iVar1 * 0x14 + param_1 + 0x5154);
      goto LAB_0004669c;
    }
    if (param_2 == 0x851b) {
      iVar1 = *(int *)(param_1 + 0x52a8);
      goto LAB_000466e0;
    }
    if (param_2 != 0x85b3) {
      return 0;
    }
  }
  iVar1 = *(int *)(iVar1 * 0x14 + param_1 + 0x515c);
LAB_0004669c:
  return iVar1 + 0x10;
}

/* _gleTexLevelStorage @ 0x46708 (2272 bytes) */
void _gleTexLevelStorage(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  uint param_2;
  int param_3;
  uint param_4;
  undefined2 *param_5;
  undefined2 *param_6;
  int param_7;
{
  uint uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  
  if ((param_3 == 0x85b9) && (param_4 - 0x85ba < 2)) {
    *param_5 = 0x85b9;
    goto LAB_00046c80;
  }
  if (param_7 == 0) goto LAB_000467fc;
  if (param_2 == 0x84ea) goto LAB_00046eb4;
  if (0x84ea < param_2) {
    if (param_2 == 0x84ed) goto LAB_00046d0c;
    if (0x84ed < param_2) {
      if (param_2 == 0x84ee) goto LAB_000467f8;
      if (param_2 != 0x8837) goto LAB_000467fc;
      goto LAB_00046c54;
    }
    if (param_2 == 0x84eb) goto LAB_00046c54;
    if (param_2 != 0x84ec) goto LAB_000467fc;
    param_2 = 0x8049;
LAB_000468e8:
    if (param_2 == 0x804f) {
LAB_00046df8:
      if ((param_4 != 0x8033) && (param_4 != 0x8365)) {
        uVar2 = 0x1908;
        uVar3 = 0x8033;
        goto LAB_00046fe0;
      }
    }
    else {
      if (param_2 < 0x8050) {
        if (param_2 < 0x804c) goto LAB_00046eb4;
        if (0x804d < param_2) {
          return;
        }
LAB_00046eac:
        uVar2 = 0x1909;
LAB_00046fcc:
        *param_5 = uVar2;
        uVar3 = 0x1403;
        goto LAB_00046c3c;
      }
      if (param_2 == 0x8052) {
LAB_00046c6c:
        if ((param_4 != 0x8036) && (param_4 != 0x8368)) {
          uVar2 = 0x1908;
          uVar3 = 0x8036;
          goto LAB_00046fe0;
        }
      }
      else {
        uVar2 = 0x1907;
        if (0x8052 < param_2) goto LAB_00046fcc;
        if (param_2 == 0x8050) {
          if (((1 < param_4 - 0x8363) && (param_4 != 0x8034)) && (param_4 != 0x8366)) {
            uVar2 = 0x1907;
            uVar3 = 0x8363;
            goto LAB_00046fe0;
          }
        }
        else {
          if (param_2 != 0x8051) {
            return;
          }
          if (param_4 != 0x8035) {
            uVar1 = 0x8367;
LAB_00046d50:
            if (param_4 != uVar1) goto LAB_00046d64;
          }
        }
      }
    }
LAB_00046c7c:
    *param_5 = (short)param_3;
LAB_00046c80:
    *param_6 = (short)param_4;
    return;
  }
  if (0x83f3 < param_2) {
    if (param_2 != 0x84e9) goto LAB_000467fc;
    goto LAB_00046f0c;
  }
  if (param_2 < 0x83f1) {
    if (param_2 == 0x83f0) goto LAB_00046d0c;
  }
  else {
LAB_000467f8:
    param_2 = 0x1908;
  }
LAB_000467fc:
  if (param_2 < 0x83f4) {
    if (0x83f1 < param_2) {
LAB_00046f34:
      *param_5 = (short)param_2;
      *param_6 = 0;
      return;
    }
    if (0x8048 < param_2) {
      if (param_2 < 0x8057) {
        if (param_2 < 0x8055) goto LAB_000468e8;
        goto LAB_00046df8;
      }
      if (32999 < param_2) {
        if (param_2 < 0x81a5) {
          return;
        }
        if (0x81a7 < param_2) {
          if (param_2 < 0x83f0) {
            return;
          }
          goto LAB_00046f34;
        }
LAB_00046fbc:
        if (3 < param_4 - 0x1400) {
          uVar2 = 0x1902;
          uVar3 = 0x1405;
          goto LAB_00046fe0;
        }
        uVar2 = 0x1902;
        goto LAB_00046fcc;
      }
      uVar2 = 0x1900;
      if (param_2 < 0x80e2) {
        if (param_2 == 0x8059) goto LAB_00046c6c;
        if (0x8059 < param_2) {
          if (0x805b < param_2) {
            return;
          }
          uVar2 = 0x1908;
          goto LAB_00046fcc;
        }
        if (param_2 == 0x8057) {
          if ((param_4 == 0x8034) || (param_4 == 0x8366)) goto LAB_00046c7c;
          uVar2 = 0x1908;
          uVar3 = 0x8034;
        }
        else {
          if (param_2 != 0x8058) {
            return;
          }
          if ((param_4 == 0x8035) || (param_4 == 0x8367)) goto LAB_00046c7c;
          uVar2 = 0x1908;
          uVar3 = 0x8035;
        }
        goto LAB_00046fe0;
      }
LAB_00046fa0:
      *param_5 = uVar2;
      uVar3 = 0x1401;
      goto LAB_00046c3c;
    }
    uVar2 = 0x190a;
    if (param_2 < 0x8046) {
      if (param_2 == 0x2a10) {
        if ((param_4 == 0x8032) || (param_4 == 0x8362)) goto LAB_00046c7c;
        uVar2 = 0x1907;
        uVar3 = 0x8032;
        goto LAB_00046fe0;
      }
      if (param_2 < 0x2a11) {
        if (param_2 == 0x1902) goto LAB_00046fbc;
        if (param_2 < 0x1903) {
          if (param_2 != 2) {
            if (param_2 < 3) {
              if (param_2 != 1) {
                return;
              }
LAB_00046eb4:
              uVar2 = 0x1909;
              goto LAB_00046fa0;
            }
            if (param_2 == 3) goto LAB_00046d0c;
            if (param_2 != 4) {
              return;
            }
LAB_00046e24:
            if (param_4 < 0x8037) {
              if ((param_4 < 0x8035) && ((param_4 != 0x8032 && (param_4 < 0x8032))))
              goto LAB_00046e7c;
            }
            else if (param_4 < 0x8367) {
              if ((param_4 < 0x8363) && (param_4 != 0x8362)) {
LAB_00046e7c:
                uVar2 = 0x1908;
                goto LAB_00046fa0;
              }
            }
            else if (0x8368 < param_4) goto LAB_00046e7c;
            goto LAB_00046c7c;
          }
        }
        else {
          if (param_2 == 0x1908) goto LAB_00046e24;
          if (param_2 < 0x1909) {
            if (param_2 == 0x1906) goto LAB_00046f0c;
            if (param_2 != 0x1907) {
              return;
            }
LAB_00046d0c:
            if (param_4 < 0x8037) {
              if (((param_4 < 0x8035) && (param_4 != 0x8032)) && (param_4 < 0x8032)) {
LAB_00046d64:
                uVar2 = 0x1907;
                goto LAB_00046fa0;
              }
            }
            else if (param_4 < 0x8367) {
              if (param_4 < 0x8363) {
                uVar1 = 0x8362;
                goto LAB_00046d50;
              }
            }
            else if (0x8368 < param_4) goto LAB_00046d64;
            goto LAB_00046c7c;
          }
          if (param_2 == 0x1909) goto LAB_00046eb4;
          if (param_2 != 0x190a) {
            return;
          }
        }
LAB_00046c54:
        uVar2 = 0x190a;
        goto LAB_00046fa0;
      }
      if (0x8040 < param_2) {
        if (param_2 < 0x8043) goto LAB_00046eac;
        goto LAB_00046c54;
      }
      if (0x803e < param_2) goto LAB_00046eb4;
      if (param_2 < 0x803b) {
        return;
      }
      if (param_2 < 0x803d) {
LAB_00046f0c:
        uVar2 = 0x1906;
        goto LAB_00046fa0;
      }
      uVar2 = 0x1906;
    }
    goto LAB_00046fcc;
  }
  if (0x8706 < param_2) {
    if (param_2 == 0x8817) {
LAB_00046e9c:
      uVar2 = 0x1909;
LAB_00046ea0:
      *param_5 = uVar2;
      uVar3 = 0x1406;
      goto LAB_00046c3c;
    }
    if (0x8817 < param_2) {
      if (param_2 == 0x881d) {
LAB_00046c30:
        uVar2 = 0x1909;
      }
      else if (param_2 < 0x881e) {
        if (param_2 == 0x881a) {
          uVar2 = 0x1908;
        }
        else {
          if (param_2 < 0x881b) {
            if (param_2 != 0x8818) {
              if (param_2 != 0x8819) {
                return;
              }
              uVar2 = 0x190a;
              goto LAB_00046ea0;
            }
            goto LAB_00046e9c;
          }
          if (param_2 == 0x881b) {
            uVar2 = 0x1907;
          }
          else {
            if (param_2 != 0x881c) {
              return;
            }
            uVar2 = 0x1906;
          }
        }
      }
      else {
        if (param_2 == 0x8837) {
LAB_00046f1c:
          uVar2 = 0x8837;
          goto LAB_00046f28;
        }
        if (0x8837 < param_2) {
          if (param_2 == 0x885e) {
            uVar2 = 0x86f4;
            goto LAB_00046fa0;
          }
          if (param_2 != 0x885f) {
            return;
          }
          uVar2 = 0x86f4;
          goto LAB_00046fb0;
        }
        if (param_2 == 0x881e) goto LAB_00046c30;
        if (param_2 != 0x881f) {
          return;
        }
        uVar2 = 0x190a;
      }
      *param_5 = uVar2;
      uVar3 = 0x140b;
      goto LAB_00046c3c;
    }
    if (param_2 != 0x870b) {
      if (0x870b < param_2) {
        if (param_2 == 0x8814) {
          uVar2 = 0x1908;
        }
        else {
          if (param_2 < 0x8815) {
            if (0x870d < param_2) {
              return;
            }
            uVar2 = 0x80e1;
            uVar3 = 7;
            goto LAB_00046fe0;
          }
          if (param_2 == 0x8815) {
            uVar2 = 0x1907;
          }
          else {
            if (param_2 != 0x8816) {
              return;
            }
            uVar2 = 0x1906;
          }
        }
        goto LAB_00046ea0;
      }
      if (param_2 == 0x8709) {
LAB_00046f88:
        uVar2 = 0x86f5;
        goto LAB_00046fb0;
      }
      if (param_2 < 0x870a) goto LAB_00046f68;
    }
LAB_00046f90:
    uVar2 = 0x86dc;
    uVar3 = 0x86db;
    goto LAB_00046fe0;
  }
  uVar2 = 0x1906;
  if (0x8704 < param_2) {
LAB_00046fb0:
    *param_5 = uVar2;
    uVar3 = 0x1400;
    goto LAB_00046c3c;
  }
  if (param_2 == 0x86f8) {
LAB_00046f70:
    uVar2 = 0x86f4;
    uVar3 = 5;
  }
  else {
    if (param_2 < 0x86f9) {
      if (param_2 < 0x84ee) {
        if ((param_2 < 0x84ec) && (param_2 != 0x84ea)) {
          if (0x84ea < param_2) goto LAB_00046f1c;
          if (param_2 != 0x84e9) {
            return;
          }
          if (((param_4 != 0x8034) && (param_4 != 0x8366)) &&
             ((param_3 == 0x1906 ||
              (((param_3 == 0x190a || (param_3 == 0x1908)) || (param_3 == 0x80e1))))))
          goto LAB_00046f0c;
          uVar2 = 0x83f1;
        }
        else {
          uVar2 = 0x83f0;
        }
LAB_00046f28:
        *param_5 = uVar2;
        uVar3 = 0;
        goto LAB_00046c3c;
      }
      if (param_2 != 0x86f4) {
        if (param_2 < 0x86f5) {
          if (param_2 == 0x84ee) {
            uVar2 = 0x83f2;
            goto LAB_00046f28;
          }
          uVar1 = 0x86dc;
        }
        else {
          if (param_2 == 0x86f5) goto LAB_00046f88;
          uVar1 = 0x86f6;
        }
        if (param_2 != uVar1) {
          return;
        }
        goto LAB_00046f90;
      }
      goto LAB_00046f70;
    }
    if (param_2 < 0x8700) {
      if (param_2 < 0x86fe) {
        if (param_2 < 0x86fb) {
          uVar2 = 0x86f4;
          uVar3 = 6;
          goto LAB_00046fe0;
        }
        if (0x86fc < param_2) {
          return;
        }
      }
      uVar2 = 0x80e1;
      uVar3 = 8;
    }
    else {
      if (param_2 < 0x8701) {
        return;
      }
      if (param_2 < 0x8703) {
LAB_00046f68:
        uVar2 = 0x1909;
        goto LAB_00046fb0;
      }
      uVar2 = 0x190a;
      uVar3 = 1;
    }
  }
LAB_00046fe0:
  *param_5 = uVar2;
LAB_00046c3c:
  *param_6 = uVar3;
  return;
}

/* _gleAllocateTextureLevel @ 0x46fe8 (196 bytes) */
int _gleAllocateTextureLevel(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  undefined *puVar1;
  undefined4 uVar2;
  vm_size_t size;
  vm_address_t local_20 [4];
  
  size = ((int (*)())_gleTextureLevelBytes)(param_1,param_3);
  puVar1 = PTR_00112034;
  uVar2 = 0;
  if (size != 0) {
    if (*(short *)(param_2 + 0x3e) == -0x7a43) {
      local_20[0] = _malloc(size);
    }
    else {
      *(byte *)(param_3 + 0xb) = *(byte *)(param_3 + 0xb) | 8;
      _vm_allocate(*(vm_map_t *)puVar1,local_20,size,1);
    }
    if (local_20[0] == 0) {
      if (*(int *)(param_1 + 0x7574) == 0) {
        *(undefined4 *)(param_1 + 0x7574) = 0x505;
      }
      uVar2 = 0;
    }
    else {
      *(vm_address_t *)(param_3 + 0x14) = local_20[0];
      uVar2 = 1;
    }
  }
  return uVar2;
}

/* _gleTextureLevelBytes @ 0x470ac (140 bytes) */
int _gleTextureLevelBytes(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  
  iVar2 = _glePixelBytes((uint)*(ushort *)(param_2 + 0x10),(uint)*(ushort *)(param_2 + 0x12));
  if (*(short *)(param_2 + 0x12) == 0) {
    iVar1 = ((int)(*(ushort *)(param_2 + 4) + 3) >> 2) * ((int)(*(ushort *)(param_2 + 6) + 3) >> 2)
            * (uint)*(ushort *)(param_2 + 8);
  }
  else {
    iVar1 = (uint)*(ushort *)(param_2 + 0xc) * (uint)*(ushort *)(param_2 + 0xe) *
            (uint)*(ushort *)(param_2 + 8);
  }
  return iVar1 * iVar2;
}

/* _gleTextureImagePut_FastUbyte @ 0x47138 (4672 bytes) */
int _gleTextureImagePut_FastUbyte(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11)
  undefined4 param_1;
  int param_2;
  int param_3;
  undefined1 *param_4;
  undefined1 *param_5;
  int param_6;
  undefined4 param_7;
  int param_8;
  int param_9;
  undefined4 param_10;
  int param_11;
{
  undefined1 *puVar1;
  bool bVar2;
  undefined1 uVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined1 *puVar6;
  uint uVar7;
  
  iVar5 = _gleComponents(param_10);
  puVar6 = param_5 + param_2 * iVar5;
  switch(param_10) {
  case 0x1900:
    bVar2 = param_11 == 0x1900;
    goto LAB_00048358;
  default:
    goto LAB_0004838c;
  case 0x1906:
    if (param_11 == 0x1908) {
      if (param_3 < 1) {
        return 1;
      }
      do {
        if (param_5 < puVar6) {
          iVar5 = (int)puVar6 - (int)param_5;
          puVar4 = param_4 + 3;
          do {
            uVar3 = *puVar4;
            puVar4 = puVar4 + 4;
            *param_5 = uVar3;
            param_5 = param_5 + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
        }
        param_3 = param_3 + -1;
        param_4 = param_4 + param_6;
        param_5 = param_5 + param_8;
        puVar6 = puVar6 + param_9;
      } while (param_3 != 0);
      return 1;
    }
    if (0x1908 < param_11) {
      if (param_11 == 0x8000) {
        if (param_3 < 1) {
          return 1;
        }
        do {
          if (param_5 < puVar6) {
            iVar5 = (int)puVar6 - (int)param_5;
            puVar4 = param_4;
            do {
              uVar3 = *puVar4;
              puVar4 = puVar4 + 4;
              *param_5 = uVar3;
              param_5 = param_5 + 1;
              iVar5 = iVar5 + -1;
            } while (iVar5 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = param_4 + param_6;
          param_5 = param_5 + param_8;
          puVar6 = puVar6 + param_9;
        } while (param_3 != 0);
        return 1;
      }
      if (0x8000 < param_11) {
        if (param_11 == 0x80e0) {
          if (param_3 < 1) {
            return 1;
          }
          do {
            if (param_5 < puVar6) {
              iVar5 = (int)puVar6 - (int)param_5;
              do {
                *param_5 = 0xff;
                param_5 = param_5 + 1;
                iVar5 = iVar5 + -1;
              } while (iVar5 != 0);
            }
            param_3 = param_3 + -1;
            param_5 = param_5 + param_8;
            puVar6 = puVar6 + param_9;
          } while (param_3 != 0);
          return 1;
        }
        if (param_11 == 0x80e1) {
          if (param_3 < 1) {
            return 1;
          }
          do {
            if (param_5 < puVar6) {
              iVar5 = (int)puVar6 - (int)param_5;
              puVar4 = param_4 + 3;
              do {
                uVar3 = *puVar4;
                puVar4 = puVar4 + 4;
                *param_5 = uVar3;
                param_5 = param_5 + 1;
                iVar5 = iVar5 + -1;
              } while (iVar5 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = param_4 + param_6;
            param_5 = param_5 + param_8;
            puVar6 = puVar6 + param_9;
          } while (param_3 != 0);
          return 1;
        }
        return 0;
      }
      if (param_11 == 0x1909) {
        if (param_3 < 1) {
          return 1;
        }
        do {
          if (param_5 < puVar6) {
            iVar5 = (int)puVar6 - (int)param_5;
            do {
              *param_5 = 0xff;
              param_5 = param_5 + 1;
              iVar5 = iVar5 + -1;
            } while (iVar5 != 0);
          }
          param_3 = param_3 + -1;
          param_5 = param_5 + param_8;
          puVar6 = puVar6 + param_9;
        } while (param_3 != 0);
        return 1;
      }
      if (param_11 == 0x190a) {
        if (param_3 < 1) {
          return 1;
        }
        do {
          if (param_5 < puVar6) {
            iVar5 = (int)puVar6 - (int)param_5;
            puVar4 = param_4 + 1;
            do {
              uVar3 = *puVar4;
              puVar4 = puVar4 + 2;
              *param_5 = uVar3;
              param_5 = param_5 + 1;
              iVar5 = iVar5 + -1;
            } while (iVar5 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = param_4 + param_6;
          param_5 = param_5 + param_8;
          puVar6 = puVar6 + param_9;
        } while (param_3 != 0);
        return 1;
      }
      return 0;
    }
    if (param_11 != 0x1906) {
      if (0x1906 < param_11) {
        if (param_3 < 1) {
          return 1;
        }
        do {
          if (param_5 < puVar6) {
            iVar5 = (int)puVar6 - (int)param_5;
            do {
              *param_5 = 0xff;
              param_5 = param_5 + 1;
              iVar5 = iVar5 + -1;
            } while (iVar5 != 0);
          }
          param_3 = param_3 + -1;
          param_5 = param_5 + param_8;
          puVar6 = puVar6 + param_9;
        } while (param_3 != 0);
        return 1;
      }
      if (0x1902 < param_11) {
        if (param_3 < 1) {
          return 1;
        }
        do {
          if (param_5 < puVar6) {
            iVar5 = (int)puVar6 - (int)param_5;
            do {
              *param_5 = 0xff;
              param_5 = param_5 + 1;
              iVar5 = iVar5 + -1;
            } while (iVar5 != 0);
          }
          param_3 = param_3 + -1;
          param_5 = param_5 + param_8;
          puVar6 = puVar6 + param_9;
        } while (param_3 != 0);
        return 1;
      }
      return 0;
    }
    break;
  case 0x1907:
    if (param_11 == 0x1908) {
      puVar4 = param_4;
      if (param_3 < 1) {
        return 1;
      }
      do {
        for (; param_5 < puVar6; param_5 = param_5 + 3) {
          *param_5 = *param_4;
          param_5[1] = param_4[1];
          puVar1 = param_4 + 2;
          param_4 = param_4 + 4;
          param_5[2] = *puVar1;
        }
        param_3 = param_3 + -1;
        param_4 = puVar4 + param_6;
        param_5 = param_5 + param_8;
        puVar6 = puVar6 + param_9;
        puVar4 = param_4;
      } while (param_3 != 0);
      return 1;
    }
    if (0x1908 < param_11) {
      if (param_11 == 0x8000) {
        if (param_3 < 1) {
          return 1;
        }
        do {
          if (param_5 < puVar6) {
            puVar4 = param_4 + 1;
            do {
              *param_5 = puVar4[2];
              param_5[1] = puVar4[1];
              uVar3 = *puVar4;
              puVar4 = puVar4 + 4;
              param_5[2] = uVar3;
              param_5 = param_5 + 3;
            } while (param_5 < puVar6);
          }
          param_3 = param_3 + -1;
          param_4 = param_4 + param_6;
          param_5 = param_5 + param_8;
          puVar6 = puVar6 + param_9;
        } while (param_3 != 0);
        return 1;
      }
      if (0x8000 < param_11) {
        if (param_11 == 0x80e0) {
          puVar4 = param_4;
          if (param_3 < 1) {
            return 1;
          }
          do {
            for (; param_5 < puVar6; param_5 = param_5 + 3) {
              *param_5 = param_4[2];
              param_5[1] = param_4[1];
              uVar3 = *param_4;
              param_4 = param_4 + 3;
              param_5[2] = uVar3;
            }
            param_3 = param_3 + -1;
            param_4 = puVar4 + param_6;
            param_5 = param_5 + param_8;
            puVar6 = puVar6 + param_9;
            puVar4 = param_4;
          } while (param_3 != 0);
          return 1;
        }
        if (param_11 == 0x80e1) {
          puVar4 = param_4;
          if (param_3 < 1) {
            return 1;
          }
          do {
            for (; param_5 < puVar6; param_5 = param_5 + 3) {
              *param_5 = param_4[2];
              param_5[1] = param_4[1];
              uVar3 = *param_4;
              param_4 = param_4 + 4;
              param_5[2] = uVar3;
            }
            param_3 = param_3 + -1;
            param_4 = puVar4 + param_6;
            param_5 = param_5 + param_8;
            puVar6 = puVar6 + param_9;
            puVar4 = param_4;
          } while (param_3 != 0);
          return 1;
        }
        return 0;
      }
      if (param_11 == 0x1909) {
        puVar4 = param_4;
        if (param_3 < 1) {
          return 1;
        }
        do {
          for (; param_5 < puVar6; param_5 = param_5 + 3) {
            uVar3 = *param_4;
            param_4 = param_4 + 1;
            *param_5 = uVar3;
            param_5[2] = *param_5;
            param_5[1] = *param_5;
          }
          param_3 = param_3 + -1;
          param_4 = puVar4 + param_6;
          param_5 = param_5 + param_8;
          puVar6 = puVar6 + param_9;
          puVar4 = param_4;
        } while (param_3 != 0);
        return 1;
      }
      if (param_11 == 0x190a) {
        puVar4 = param_4;
        if (param_3 < 1) {
          return 1;
        }
        do {
          for (; param_5 < puVar6; param_5 = param_5 + 3) {
            uVar3 = *param_4;
            param_4 = param_4 + 2;
            *param_5 = uVar3;
            param_5[2] = *param_5;
            param_5[1] = *param_5;
          }
          param_3 = param_3 + -1;
          param_4 = puVar4 + param_6;
          param_5 = param_5 + param_8;
          puVar6 = puVar6 + param_9;
          puVar4 = param_4;
        } while (param_3 != 0);
        return 1;
      }
      return 0;
    }
    if (param_11 == 0x1905) {
      puVar4 = param_4;
      if (param_3 < 1) {
        return 1;
      }
      do {
        for (; param_5 < puVar6; param_5 = param_5 + 3) {
          *param_5 = 0;
          param_5[1] = 0;
          uVar3 = *param_4;
          param_4 = param_4 + 1;
          param_5[2] = uVar3;
        }
        param_3 = param_3 + -1;
        param_4 = puVar4 + param_6;
        param_5 = param_5 + param_8;
        puVar6 = puVar6 + param_9;
        puVar4 = param_4;
      } while (param_3 != 0);
      return 1;
    }
    if (param_11 < 0x1906) {
      if (param_11 == 0x1903) {
        puVar4 = param_4;
        if (param_3 < 1) {
          return 1;
        }
        do {
          for (; param_5 < puVar6; param_5 = param_5 + 3) {
            uVar3 = *param_4;
            param_4 = param_4 + 1;
            param_5[1] = 0;
            *param_5 = uVar3;
            param_5[2] = 0;
          }
          param_3 = param_3 + -1;
          param_4 = puVar4 + param_6;
          param_5 = param_5 + param_8;
          puVar6 = puVar6 + param_9;
          puVar4 = param_4;
        } while (param_3 != 0);
        return 1;
      }
      if (param_11 == 0x1904) {
        puVar4 = param_4;
        if (param_3 < 1) {
          return 1;
        }
        do {
          for (; param_5 < puVar6; param_5 = param_5 + 3) {
            *param_5 = 0;
            uVar3 = *param_4;
            param_4 = param_4 + 1;
            param_5[2] = 0;
            param_5[1] = uVar3;
          }
          param_3 = param_3 + -1;
          param_4 = puVar4 + param_6;
          param_5 = param_5 + param_8;
          puVar6 = puVar6 + param_9;
          puVar4 = param_4;
        } while (param_3 != 0);
        return 1;
      }
      return 0;
    }
    if (param_11 == 0x1906) {
      if (param_3 < 1) {
        return 1;
      }
      do {
        for (; param_5 < puVar6; param_5 = param_5 + 3) {
          *param_5 = 0;
          param_5[1] = 0;
          param_5[2] = 0;
        }
        param_3 = param_3 + -1;
        param_5 = param_5 + param_8;
        puVar6 = puVar6 + param_9;
      } while (param_3 != 0);
      return 1;
    }
    if (param_11 != 0x1907) {
      return 0;
    }
    param_2 = param_2 * 3;
    break;
  case 0x1908:
    if (param_11 != 0x1908) {
      if (0x1908 < param_11) {
        if (param_11 == 0x8000) {
          if (param_3 < 1) {
            return 1;
          }
          do {
            if (param_5 < puVar6) {
              uVar7 = (uint)(puVar6 + (3 - (int)param_5)) >> 2;
              puVar4 = param_4;
              do {
                *param_5 = puVar4[3];
                param_5[1] = puVar4[2];
                param_5[2] = puVar4[1];
                uVar3 = *puVar4;
                puVar4 = puVar4 + 4;
                param_5[3] = uVar3;
                param_5 = param_5 + 4;
                uVar7 = uVar7 - 1;
              } while (uVar7 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = param_4 + param_6;
            param_5 = param_5 + param_8;
            puVar6 = puVar6 + param_9;
          } while (param_3 != 0);
          return 1;
        }
        if (0x8000 < param_11) {
          if (param_11 == 0x80e0) {
            if (param_3 < 1) {
              return 1;
            }
            do {
              if (param_5 < puVar6) {
                uVar7 = (uint)(puVar6 + (3 - (int)param_5)) >> 2;
                puVar4 = param_4;
                do {
                  *param_5 = puVar4[2];
                  param_5[1] = puVar4[1];
                  uVar3 = *puVar4;
                  puVar4 = puVar4 + 3;
                  param_5[3] = 0xff;
                  param_5[2] = uVar3;
                  param_5 = param_5 + 4;
                  uVar7 = uVar7 - 1;
                } while (uVar7 != 0);
              }
              param_3 = param_3 + -1;
              param_4 = param_4 + param_6;
              param_5 = param_5 + param_8;
              puVar6 = puVar6 + param_9;
            } while (param_3 != 0);
            return 1;
          }
          if (param_11 == 0x80e1) {
            if (param_3 < 1) {
              return 1;
            }
            do {
              if (param_5 < puVar6) {
                uVar7 = (uint)(puVar6 + (3 - (int)param_5)) >> 2;
                puVar4 = param_4;
                do {
                  *param_5 = puVar4[2];
                  param_5[1] = puVar4[1];
                  param_5[2] = *puVar4;
                  puVar1 = puVar4 + 3;
                  puVar4 = puVar4 + 4;
                  param_5[3] = *puVar1;
                  param_5 = param_5 + 4;
                  uVar7 = uVar7 - 1;
                } while (uVar7 != 0);
              }
              param_3 = param_3 + -1;
              param_4 = param_4 + param_6;
              param_5 = param_5 + param_8;
              puVar6 = puVar6 + param_9;
            } while (param_3 != 0);
            return 1;
          }
          return 0;
        }
        if (param_11 == 0x1909) {
          if (param_3 < 1) {
            return 1;
          }
          do {
            if (param_5 < puVar6) {
              uVar7 = (uint)(puVar6 + (3 - (int)param_5)) >> 2;
              puVar4 = param_4;
              do {
                uVar3 = *puVar4;
                puVar4 = puVar4 + 1;
                param_5[3] = 0xff;
                *param_5 = uVar3;
                param_5[2] = *param_5;
                param_5[1] = *param_5;
                param_5 = param_5 + 4;
                uVar7 = uVar7 - 1;
              } while (uVar7 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = param_4 + param_6;
            param_5 = param_5 + param_8;
            puVar6 = puVar6 + param_9;
          } while (param_3 != 0);
          return 1;
        }
        if (param_11 == 0x190a) {
          if (param_3 < 1) {
            return 1;
          }
          do {
            if (param_5 < puVar6) {
              uVar7 = (uint)(puVar6 + (3 - (int)param_5)) >> 2;
              puVar4 = param_4;
              do {
                *param_5 = *puVar4;
                param_5[2] = *param_5;
                param_5[1] = *param_5;
                puVar1 = puVar4 + 1;
                puVar4 = puVar4 + 2;
                param_5[3] = *puVar1;
                param_5 = param_5 + 4;
                uVar7 = uVar7 - 1;
              } while (uVar7 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = param_4 + param_6;
            param_5 = param_5 + param_8;
            puVar6 = puVar6 + param_9;
          } while (param_3 != 0);
          return 1;
        }
        return 0;
      }
      if (param_11 == 0x1905) {
        if (param_3 < 1) {
          return 1;
        }
        do {
          if (param_5 < puVar6) {
            uVar7 = (uint)(puVar6 + (3 - (int)param_5)) >> 2;
            puVar4 = param_4;
            do {
              *param_5 = 0;
              param_5[1] = 0;
              uVar3 = *puVar4;
              puVar4 = puVar4 + 1;
              param_5[3] = 0xff;
              param_5[2] = uVar3;
              param_5 = param_5 + 4;
              uVar7 = uVar7 - 1;
            } while (uVar7 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = param_4 + param_6;
          param_5 = param_5 + param_8;
          puVar6 = puVar6 + param_9;
        } while (param_3 != 0);
        return 1;
      }
      if (0x1905 < param_11) {
        if (param_11 == 0x1906) {
          if (param_3 < 1) {
            return 1;
          }
          do {
            if (param_5 < puVar6) {
              uVar7 = (uint)(puVar6 + (3 - (int)param_5)) >> 2;
              puVar4 = param_4;
              do {
                *param_5 = 0;
                param_5[1] = 0;
                param_5[2] = 0;
                uVar3 = *puVar4;
                puVar4 = puVar4 + 1;
                param_5[3] = uVar3;
                param_5 = param_5 + 4;
                uVar7 = uVar7 - 1;
              } while (uVar7 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = param_4 + param_6;
            param_5 = param_5 + param_8;
            puVar6 = puVar6 + param_9;
          } while (param_3 != 0);
          return 1;
        }
        if (param_11 == 0x1907) {
          if (param_3 < 1) {
            return 1;
          }
          do {
            if (param_5 < puVar6) {
              uVar7 = (uint)(puVar6 + (3 - (int)param_5)) >> 2;
              puVar4 = param_4;
              do {
                *param_5 = *puVar4;
                param_5[1] = puVar4[1];
                uVar3 = puVar4[2];
                puVar4 = puVar4 + 3;
                param_5[3] = 0xff;
                param_5[2] = uVar3;
                param_5 = param_5 + 4;
                uVar7 = uVar7 - 1;
              } while (uVar7 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = param_4 + param_6;
            param_5 = param_5 + param_8;
            puVar6 = puVar6 + param_9;
          } while (param_3 != 0);
          return 1;
        }
        return 0;
      }
      if (param_11 == 0x1903) {
        if (param_3 < 1) {
          return 1;
        }
        do {
          if (param_5 < puVar6) {
            uVar7 = (uint)(puVar6 + (3 - (int)param_5)) >> 2;
            puVar4 = param_4;
            do {
              uVar3 = *puVar4;
              puVar4 = puVar4 + 1;
              param_5[1] = 0;
              *param_5 = uVar3;
              param_5[2] = 0;
              param_5[3] = 0xff;
              param_5 = param_5 + 4;
              uVar7 = uVar7 - 1;
            } while (uVar7 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = param_4 + param_6;
          param_5 = param_5 + param_8;
          puVar6 = puVar6 + param_9;
        } while (param_3 != 0);
        return 1;
      }
      if (param_11 == 0x1904) {
        if (param_3 < 1) {
          return 1;
        }
        do {
          if (param_5 < puVar6) {
            uVar7 = (uint)(puVar6 + (3 - (int)param_5)) >> 2;
            puVar4 = param_4;
            do {
              *param_5 = 0;
              uVar3 = *puVar4;
              puVar4 = puVar4 + 1;
              param_5[2] = 0;
              param_5[1] = uVar3;
              param_5[3] = 0xff;
              param_5 = param_5 + 4;
              uVar7 = uVar7 - 1;
            } while (uVar7 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = param_4 + param_6;
          param_5 = param_5 + param_8;
          puVar6 = puVar6 + param_9;
        } while (param_3 != 0);
        return 1;
      }
      return 0;
    }
    param_2 = param_2 << 2;
    break;
  case 0x1909:
    if (param_11 == 0x1908) {
      if (param_3 < 1) {
        return 1;
      }
      do {
        if (param_5 < puVar6) {
          iVar5 = (int)puVar6 - (int)param_5;
          puVar4 = param_4;
          do {
            uVar3 = *puVar4;
            puVar4 = puVar4 + 4;
            *param_5 = uVar3;
            param_5 = param_5 + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
        }
        param_3 = param_3 + -1;
        param_4 = param_4 + param_6;
        param_5 = param_5 + param_8;
        puVar6 = puVar6 + param_9;
      } while (param_3 != 0);
      return 1;
    }
    if (0x1908 < param_11) {
      if (param_11 == 0x8000) {
        if (param_3 < 1) {
          return 1;
        }
        do {
          if (param_5 < puVar6) {
            iVar5 = (int)puVar6 - (int)param_5;
            puVar4 = param_4 + 3;
            do {
              uVar3 = *puVar4;
              puVar4 = puVar4 + 4;
              *param_5 = uVar3;
              param_5 = param_5 + 1;
              iVar5 = iVar5 + -1;
            } while (iVar5 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = param_4 + param_6;
          param_5 = param_5 + param_8;
          puVar6 = puVar6 + param_9;
        } while (param_3 != 0);
        return 1;
      }
      if (0x8000 < param_11) {
        if (param_11 == 0x80e0) {
          if (param_3 < 1) {
            return 1;
          }
          do {
            if (param_5 < puVar6) {
              iVar5 = (int)puVar6 - (int)param_5;
              puVar4 = param_4 + 2;
              do {
                uVar3 = *puVar4;
                puVar4 = puVar4 + 3;
                *param_5 = uVar3;
                param_5 = param_5 + 1;
                iVar5 = iVar5 + -1;
              } while (iVar5 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = param_4 + param_6;
            param_5 = param_5 + param_8;
            puVar6 = puVar6 + param_9;
          } while (param_3 != 0);
          return 1;
        }
        if (param_11 == 0x80e1) {
          if (param_3 < 1) {
            return 1;
          }
          do {
            if (param_5 < puVar6) {
              iVar5 = (int)puVar6 - (int)param_5;
              puVar4 = param_4 + 2;
              do {
                uVar3 = *puVar4;
                puVar4 = puVar4 + 4;
                *param_5 = uVar3;
                param_5 = param_5 + 1;
                iVar5 = iVar5 + -1;
              } while (iVar5 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = param_4 + param_6;
            param_5 = param_5 + param_8;
            puVar6 = puVar6 + param_9;
          } while (param_3 != 0);
          return 1;
        }
        return 0;
      }
      if (param_11 != 0x1909) {
        if (param_11 != 0x190a) {
          return 0;
        }
        if (param_3 < 1) {
          return 1;
        }
        do {
          if (param_5 < puVar6) {
            iVar5 = (int)puVar6 - (int)param_5;
            puVar4 = param_4;
            do {
              uVar3 = *puVar4;
              puVar4 = puVar4 + 2;
              *param_5 = uVar3;
              param_5 = param_5 + 1;
              iVar5 = iVar5 + -1;
            } while (iVar5 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = param_4 + param_6;
          param_5 = param_5 + param_8;
          puVar6 = puVar6 + param_9;
        } while (param_3 != 0);
        return 1;
      }
      break;
    }
    if (0x1906 < param_11) {
      if (param_3 < 1) {
        return 1;
      }
      do {
        if (param_5 < puVar6) {
          iVar5 = (int)puVar6 - (int)param_5;
          puVar4 = param_4;
          do {
            uVar3 = *puVar4;
            puVar4 = puVar4 + 3;
            *param_5 = uVar3;
            param_5 = param_5 + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
        }
        param_3 = param_3 + -1;
        param_4 = param_4 + param_6;
        param_5 = param_5 + param_8;
        puVar6 = puVar6 + param_9;
      } while (param_3 != 0);
      return 1;
    }
    if (0x1903 < param_11) {
      if (param_3 < 1) {
        return 1;
      }
      do {
        if (param_5 < puVar6) {
          iVar5 = (int)puVar6 - (int)param_5;
          do {
            *param_5 = 0;
            param_5 = param_5 + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
        }
        param_3 = param_3 + -1;
        param_5 = param_5 + param_8;
        puVar6 = puVar6 + param_9;
      } while (param_3 != 0);
      return 1;
    }
    bVar2 = param_11 == 0x1903;
LAB_00048358:
    if (!bVar2) {
LAB_0004838c:
      return 0;
    }
    break;
  case 0x190a:
    if (param_11 == 0x1908) {
      if (param_3 < 1) {
        return 1;
      }
      do {
        if (param_5 < puVar6) {
          uVar7 = (uint)(puVar6 + (1 - (int)param_5)) >> 1;
          puVar4 = param_4;
          do {
            *param_5 = *puVar4;
            puVar1 = puVar4 + 3;
            puVar4 = puVar4 + 4;
            param_5[1] = *puVar1;
            param_5 = param_5 + 2;
            uVar7 = uVar7 - 1;
          } while (uVar7 != 0);
        }
        param_3 = param_3 + -1;
        param_4 = param_4 + param_6;
        param_5 = param_5 + param_8;
        puVar6 = puVar6 + param_9;
      } while (param_3 != 0);
      return 1;
    }
    if (param_11 < 0x1909) {
      if (0x1905 < param_11) {
        if (param_11 == 0x1906) {
          if (param_3 < 1) {
            return 1;
          }
          do {
            if (param_5 < puVar6) {
              uVar7 = (uint)(puVar6 + (1 - (int)param_5)) >> 1;
              puVar4 = param_4;
              do {
                *param_5 = 0;
                uVar3 = *puVar4;
                puVar4 = puVar4 + 1;
                param_5[1] = uVar3;
                param_5 = param_5 + 2;
                uVar7 = uVar7 - 1;
              } while (uVar7 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = param_4 + param_6;
            param_5 = param_5 + param_8;
            puVar6 = puVar6 + param_9;
          } while (param_3 != 0);
          return 1;
        }
        if (param_11 == 0x1907) {
          if (param_3 < 1) {
            return 1;
          }
          do {
            if (param_5 < puVar6) {
              uVar7 = (uint)(puVar6 + (1 - (int)param_5)) >> 1;
              puVar4 = param_4;
              do {
                uVar3 = *puVar4;
                puVar4 = puVar4 + 3;
                param_5[1] = 0xff;
                *param_5 = uVar3;
                param_5 = param_5 + 2;
                uVar7 = uVar7 - 1;
              } while (uVar7 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = param_4 + param_6;
            param_5 = param_5 + param_8;
            puVar6 = puVar6 + param_9;
          } while (param_3 != 0);
          return 1;
        }
        return 0;
      }
      if (0x1903 < param_11) {
        if (param_3 < 1) {
          return 1;
        }
        do {
          if (param_5 < puVar6) {
            uVar7 = (uint)(puVar6 + (1 - (int)param_5)) >> 1;
            do {
              *param_5 = 0;
              param_5[1] = 0xff;
              param_5 = param_5 + 2;
              uVar7 = uVar7 - 1;
            } while (uVar7 != 0);
          }
          param_3 = param_3 + -1;
          param_5 = param_5 + param_8;
          puVar6 = puVar6 + param_9;
        } while (param_3 != 0);
        return 1;
      }
      if (param_11 != 0x1903) {
        return 0;
      }
      if (param_3 < 1) {
        return 1;
      }
      do {
        if (param_5 < puVar6) {
          uVar7 = (uint)(puVar6 + (1 - (int)param_5)) >> 1;
          puVar4 = param_4;
          do {
            uVar3 = *puVar4;
            puVar4 = puVar4 + 1;
            param_5[1] = 0xff;
            *param_5 = uVar3;
            param_5 = param_5 + 2;
            uVar7 = uVar7 - 1;
          } while (uVar7 != 0);
        }
        param_3 = param_3 + -1;
        param_4 = param_4 + param_6;
        param_5 = param_5 + param_8;
        puVar6 = puVar6 + param_9;
      } while (param_3 != 0);
      return 1;
    }
    if (param_11 == 0x8000) {
      if (param_3 < 1) {
        return 1;
      }
      do {
        if (param_5 < puVar6) {
          uVar7 = (uint)(puVar6 + (1 - (int)param_5)) >> 1;
          puVar4 = param_4;
          do {
            *param_5 = puVar4[3];
            uVar3 = *puVar4;
            puVar4 = puVar4 + 4;
            param_5[1] = uVar3;
            param_5 = param_5 + 2;
            uVar7 = uVar7 - 1;
          } while (uVar7 != 0);
        }
        param_3 = param_3 + -1;
        param_4 = param_4 + param_6;
        param_5 = param_5 + param_8;
        puVar6 = puVar6 + param_9;
      } while (param_3 != 0);
      return 1;
    }
    if (0x8000 < param_11) {
      if (param_11 == 0x80e0) {
        if (param_3 < 1) {
          return 1;
        }
        do {
          if (param_5 < puVar6) {
            uVar7 = (uint)(puVar6 + (1 - (int)param_5)) >> 1;
            puVar4 = param_4 + 2;
            do {
              uVar3 = *puVar4;
              puVar4 = puVar4 + 3;
              param_5[1] = 0xff;
              *param_5 = uVar3;
              param_5 = param_5 + 2;
              uVar7 = uVar7 - 1;
            } while (uVar7 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = param_4 + param_6;
          param_5 = param_5 + param_8;
          puVar6 = puVar6 + param_9;
        } while (param_3 != 0);
        return 1;
      }
      if (param_11 == 0x80e1) {
        if (param_3 < 1) {
          return 1;
        }
        do {
          if (param_5 < puVar6) {
            puVar4 = param_4 + 3;
            uVar7 = (uint)(puVar6 + (1 - (int)param_5)) >> 1;
            do {
              *param_5 = puVar4[-1];
              uVar3 = *puVar4;
              puVar4 = puVar4 + 4;
              param_5[1] = uVar3;
              param_5 = param_5 + 2;
              uVar7 = uVar7 - 1;
            } while (uVar7 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = param_4 + param_6;
          param_5 = param_5 + param_8;
          puVar6 = puVar6 + param_9;
        } while (param_3 != 0);
        return 1;
      }
      return 0;
    }
    if (param_11 == 0x1909) {
      if (param_3 < 1) {
        return 1;
      }
      do {
        if (param_5 < puVar6) {
          uVar7 = (uint)(puVar6 + (1 - (int)param_5)) >> 1;
          puVar4 = param_4;
          do {
            uVar3 = *puVar4;
            puVar4 = puVar4 + 1;
            param_5[1] = 0xff;
            *param_5 = uVar3;
            param_5 = param_5 + 2;
            uVar7 = uVar7 - 1;
          } while (uVar7 != 0);
        }
        param_3 = param_3 + -1;
        param_4 = param_4 + param_6;
        param_5 = param_5 + param_8;
        puVar6 = puVar6 + param_9;
      } while (param_3 != 0);
      return 1;
    }
    if (param_11 != 0x190a) {
      return 0;
    }
    param_2 = param_2 << 1;
  }
  ((int (*)())_gleCopy)(param_4,param_5,param_2,param_3,param_6,param_9);
  return 1;
}

/* _gleCopy @ 0x483a4 (212 bytes) */
int _gleCopy(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  uint param_3;
  uint param_4;
  uint param_5;
  uint param_6;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  if ((param_4 == 1) || ((param_5 == param_3 && (param_6 == param_5)))) {
    _memcpy(param_2,param_1,param_3 * param_4);
    return;
  }
  uVar4 = 0;
  if (param_4 == 0) {
    return;
  }
  uVar2 = param_3 & 3;
  do {
    iVar3 = 0;
    for (iVar5 = (int)param_3 >> 2; iVar5 != 0; iVar5 = iVar5 + -1) {
      iVar1 = iVar3 * 4;
      iVar3 = iVar3 + 1;
      *(undefined4 *)(param_2 + iVar1) = *(undefined4 *)(param_1 + iVar1);
    }
    if (uVar2 == 2) {
LAB_00048444:
      *(undefined1 *)(param_2 + param_3 + -2) = *(undefined1 *)(param_1 + param_3 + -2);
LAB_00048458:
      *(undefined1 *)(param_2 + param_3 + -1) = *(undefined1 *)(param_1 + param_3 + -1);
    }
    else if (uVar2 < 3) {
      if (uVar2 == 1) goto LAB_00048458;
    }
    else if (uVar2 == 3) {
      *(undefined1 *)(param_2 + param_3 + -3) = *(undefined1 *)(param_1 + param_3 + -3);
      goto LAB_00048444;
    }
    uVar4 = uVar4 + 1;
    param_1 = param_1 + param_5;
    param_2 = param_2 + param_6;
    if (param_4 <= uVar4) {
      return;
    }
  } while( true );
}

/* _gleDeletePluginTextureLevel @ 0x48478 (348 bytes) */
int _gleDeletePluginTextureLevel(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 *param_2;
  undefined4 param_3;
  int param_4;
  uint param_5;
{
  int *piVar1;
  undefined4 *puVar2;
  byte bVar3;
  ushort uVar4;
  ushort uVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  
  bVar3 = *(byte *)((int)param_2 + 0x82);
  uVar7 = 1 << (param_5 & 0x3f);
  uVar8 = 0x1f - *(byte *)((int)param_2 + 0x83);
  *(ushort *)((int)param_2 + param_4 * 2 + 0xa0) =
       *(ushort *)((int)param_2 + param_4 * 2 + 0xa0) & ~(ushort)uVar7;
  *(ushort *)((int)param_2 + param_4 * 2 + 0x94) =
       *(ushort *)((int)param_2 + param_4 * 2 + 0x94) & ~(ushort)uVar7;
  uVar4 = *(ushort *)(param_2 + 0x20);
  if (((uVar7 & (1 << (bVar3 & 0x3f) | 1U)) == 0) || (uVar4 == 0)) {
    if (((uVar7 & ((uint)(-1 << (uVar8 + bVar3 & 0x3f)) >> (uVar8 & 0x3f) | 1)) == 0) ||
       (uVar4 < 0x2602)) goto LAB_0004856c;
    uVar5 = 0;
    if (*(char *)(param_1 + 0x53e7) != '\0') {
      if (uVar4 == 0x2701) {
LAB_00048550:
        uVar5 = 0x2601;
      }
      else {
        uVar5 = uVar4;
        if (uVar4 < 0x2702) {
          if (uVar4 == 0x2700) {
LAB_00048558:
            uVar5 = 0x2600;
          }
        }
        else {
          if (uVar4 == 0x2702) goto LAB_00048558;
          if (uVar4 == 0x2703) goto LAB_00048550;
        }
      }
    }
  }
  else {
    uVar5 = 0;
  }
  *(ushort *)(param_2 + 0x20) = uVar5;
  *(byte *)((int)param_2 + 0x83) = bVar3;
LAB_0004856c:
  iVar9 = param_1 + 0x10000;
  iVar10 = 0;
  if (*(char *)(param_1 + 0x85a4) != '\0') {
    do {
      piVar1 = (int *)(iVar9 + -0x777c);
      uVar6 = *param_2;
      iVar10 = iVar10 + 1;
      puVar2 = (undefined4 *)(iVar9 + -0x7a54);
      iVar9 = iVar9 + 0x2e0;
      param_2 = param_2 + 1;
      (**(code **)(*piVar1 + 0x164))(*puVar2,uVar6,param_4,param_5);
    } while (iVar10 < (int)(uint)*(byte *)(param_1 + 0x85a4));
  }
  return;
}

/* _glMatrixMode_Comp @ 0x485d4 (76 bytes) */
int _glMatrixMode_Comp(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glMatrixMode_ListExec_00110210,4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glRotatef_Comp @ 0x48620 (404 bytes) */
void _glRotatef_Comp(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  float fVar1;
  double dVar2;
  double dVar3;
  
  dVar3 = (double)*(float *)(param_1 + 0x20);
  if ((fparam_3 == dVar3) && (fparam_4 == dVar3)) {
    fVar1 = FLOAT_00108e84;
    if (fparam_2 < dVar3) {
      fVar1 = FLOAT_00108eb0;
    }
    dVar3 = _sin((double)(float)(fparam_1 * (double)fVar1));
    dVar2 = _cos((double)(float)(fparam_1 * (double)fVar1));
    ((void (*)())_glRotateX_Comp)(param_1,(double)(float)dVar3,(double)(float)dVar2);
    return;
  }
  if ((fparam_2 == dVar3) && (fparam_4 == dVar3)) {
    fVar1 = FLOAT_00108e84;
    if (fparam_3 < dVar3) {
      fVar1 = FLOAT_00108eb0;
    }
    dVar3 = _sin((double)(float)(fparam_1 * (double)fVar1));
    dVar2 = _cos((double)(float)(fparam_1 * (double)fVar1));
    ((void (*)())_glRotateY_Comp)(param_1,(double)(float)dVar3,(double)(float)dVar2);
    return;
  }
  if ((fparam_2 == dVar3) && (fparam_3 == dVar3)) {
    fVar1 = FLOAT_00108e84;
    if (fparam_4 < dVar3) {
      fVar1 = FLOAT_00108eb0;
    }
    dVar3 = _sin((double)(float)(fparam_1 * (double)fVar1));
    dVar2 = _cos((double)(float)(fparam_1 * (double)fVar1));
    ((void (*)())_glRotateZ_Comp)(param_1,(double)(float)dVar3,(double)(float)dVar2);
    return;
  }
  ((void (*)())_glRotateXYZ_Comp)(param_1,fparam_1,fparam_2,fparam_3,fparam_4);
  return;
}

/* _glTexCoord2f_Comp @ 0x487b4 (100 bytes) */
float * _glTexCoord2f_Comp(undefined4 param_1,float fparam_1,float fparam_2)
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glTexCoord2_ListExec_001103bc,8);
  if (pfVar1 != (float *)0x0) {
    pfVar1[1] = (float)fparam_2;
    *pfVar1 = (float)fparam_1;
  }
  return pfVar1;
}

/* _gleSetEnable_TEXTURE_2D @ 0x48818 (80 bytes) */
void _gleSetEnable_TEXTURE_2D(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = *(uint *)(param_1 + 0x53d4);
  if (uVar3 < 8) {
    iVar2 = uVar3 * 0x7c + param_1;
    uVar4 = *(uint *)(iVar2 + 0x3534);
    uVar1 = uVar4 & 0xfffffff7 | param_3 << 3;
    if (uVar4 == uVar1) {
      return;
    }
    *(uint *)(iVar2 + 0x3534) = uVar1;
    _gleUpdateTextureParams(param_1,uVar3);
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x502;
  return;
}

/* _glLightModeli_Exec @ 0x48868 (368 bytes) */
void _glLightModeli_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  int param_3;
{
  undefined4 uVar1;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 == 0xb52) {
      if (param_3 == 0) {
        *(undefined1 *)(param_1 + 0x30ac) = 0;
      }
      else {
        *(undefined1 *)(param_1 + 0x30ac) = 1;
      }
      _gleUpdatePolyMode(param_1);
      _gleSelectVertexSubmitFunc(param_1);
      _gleSelectVertexAddMaterialFunc(param_1);
    }
    else if (param_2 < 0xb53) {
      if (param_2 != 0xb51) goto LAB_00048998;
      if (param_3 == 0) {
        *(undefined1 *)(param_1 + 0x30ad) = 0;
      }
      else {
        *(undefined1 *)(param_1 + 0x30ad) = 1;
      }
    }
    else if (param_2 == 0x81f8) {
      if (1 < param_3 - 0x81f9U) goto LAB_00048998;
      *(short *)(param_1 + 0x30a8) = (short)param_3;
      if ((*(char *)(param_1 + 0x30aa) != '\0') && (*(char *)(param_1 + 0x4664) == '\0')) {
        *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x800;
        *(bool *)(param_1 + 0x316b) = *(short *)(param_1 + 0x30a8) == -0x7e06;
      }
    }
    else {
      if (param_2 != 0x85b0) {
LAB_00048998:
        if (*(int *)(param_1 + 0x7574) != 0) {
          return;
        }
        uVar1 = 0x500;
        goto LAB_000489a8;
      }
      if (param_3 == 0) {
        *(undefined1 *)(param_1 + 0x30ae) = 0;
      }
      else {
        *(undefined1 *)(param_1 + 0x30ae) = 1;
      }
    }
    _gleUpdateLightModel(param_1);
    *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 1;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x502;
LAB_000489a8:
    *(undefined4 *)(param_1 + 0x7574) = uVar1;
  }
  return;
}

/* _gleSetEnable_FOG @ 0x489d8 (128 bytes) */
void _gleSetEnable_FOG(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint param_3;
{
  undefined *puVar1;
  
  if (*(byte *)(param_1 + 0x316a) != param_3) {
    *(uint *)(param_1 + 0x497c) = *(uint *)(param_1 + 0x497c) | 0x18;
    *(uint *)(param_1 + 0x50ac) = *(uint *)(param_1 + 0x50ac) | 1;
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x1000;
    *(char *)(param_1 + 0x316a) = (char)param_3;
    ((double (*)())_gleUpdateFogData)(param_1);
    puVar1 = PTR__gleSetClipInterpFunc_00112038;
    *(undefined **)(param_1 + 0x49c8) = PTR__gleSetEyeInterpFunc_0011203c;
    *(undefined **)(param_1 + 0x49cc) = puVar1;
  }
  return;
}

/* _glMultMatrixd_Exec @ 0x48a58 (140 bytes) */
int _glMultMatrixd_Exec(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  undefined1 auStack_50 [72];
  
  if ((*(short *)(param_1 + 0x4a10) < 0) && (*(int *)(param_1 + 0x4ff4) < 0x18)) {
    ((void (*)())_gleMultMatrixd)(*(undefined4 *)(param_1 + 0x4fec),param_2,auStack_50);
    iVar1 = _gleCopyMatrix(auStack_50,*(undefined4 *)(param_1 + 0x4fec));
    *(uint *)(param_1 + 0x50ac) = *(uint *)(param_1 + 0x50ac) | *(uint *)(param_1 + 0x50a8);
    *(uint *)(param_1 + 0x50b0) = *(uint *)(param_1 + 0x50b0) | *(uint *)(param_1 + 0x50a8);
  }
  else {
    iVar1 = param_1;
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
    }
  }
  return iVar1;
}

/* _gleMultMatrixd @ 0x48ae4 (900 bytes) */
void _gleMultMatrixd(param_1, param_2, param_3)
  float *param_1;
  double *param_2;
  float *param_3;
{
  *param_3 = (float)((double)param_1[0xc] * param_2[3] +
                    ((double)param_1[8] * param_2[2] +
                    ((double)*param_1 * *param_2 + (double)param_1[4] * param_2[1])));
  param_3[4] = (float)((double)param_1[0xc] * param_2[7] +
                      ((double)param_1[8] * param_2[6] +
                      ((double)*param_1 * param_2[4] + (double)param_1[4] * param_2[5])));
  param_3[8] = (float)((double)param_1[0xc] * param_2[0xb] +
                      ((double)param_1[8] * param_2[10] +
                      ((double)*param_1 * param_2[8] + (double)param_1[4] * param_2[9])));
  param_3[0xc] = (float)((double)param_1[0xc] * param_2[0xf] +
                        ((double)param_1[8] * param_2[0xe] +
                        ((double)*param_1 * param_2[0xc] + (double)param_1[4] * param_2[0xd])));
  param_3[1] = (float)((double)param_1[0xd] * param_2[3] +
                      ((double)param_1[9] * param_2[2] +
                      ((double)param_1[1] * *param_2 + (double)param_1[5] * param_2[1])));
  param_3[5] = (float)((double)param_1[0xd] * param_2[7] +
                      ((double)param_1[9] * param_2[6] +
                      ((double)param_1[1] * param_2[4] + (double)param_1[5] * param_2[5])));
  param_3[9] = (float)((double)param_1[0xd] * param_2[0xb] +
                      ((double)param_1[9] * param_2[10] +
                      ((double)param_1[1] * param_2[8] + (double)param_1[5] * param_2[9])));
  param_3[0xd] = (float)((double)param_1[0xd] * param_2[0xf] +
                        ((double)param_1[9] * param_2[0xe] +
                        ((double)param_1[1] * param_2[0xc] + (double)param_1[5] * param_2[0xd])));
  param_3[2] = (float)((double)param_1[0xe] * param_2[3] +
                      ((double)param_1[10] * param_2[2] +
                      ((double)param_1[2] * *param_2 + (double)param_1[6] * param_2[1])));
  param_3[6] = (float)((double)param_1[0xe] * param_2[7] +
                      ((double)param_1[10] * param_2[6] +
                      ((double)param_1[2] * param_2[4] + (double)param_1[6] * param_2[5])));
  param_3[10] = (float)((double)param_1[0xe] * param_2[0xb] +
                       ((double)param_1[10] * param_2[10] +
                       ((double)param_1[2] * param_2[8] + (double)param_1[6] * param_2[9])));
  param_3[0xe] = (float)((double)param_1[0xe] * param_2[0xf] +
                        ((double)param_1[10] * param_2[0xe] +
                        ((double)param_1[2] * param_2[0xc] + (double)param_1[6] * param_2[0xd])));
  param_3[3] = (float)((double)param_1[0xf] * param_2[3] +
                      ((double)param_1[0xb] * param_2[2] +
                      ((double)param_1[3] * *param_2 + (double)param_1[7] * param_2[1])));
  param_3[7] = (float)((double)param_1[0xf] * param_2[7] +
                      ((double)param_1[0xb] * param_2[6] +
                      ((double)param_1[3] * param_2[4] + (double)param_1[7] * param_2[5])));
  param_3[0xb] = (float)((double)param_1[0xf] * param_2[0xb] +
                        ((double)param_1[0xb] * param_2[10] +
                        ((double)param_1[3] * param_2[8] + (double)param_1[7] * param_2[9])));
  param_3[0xf] = (float)((double)param_1[0xf] * param_2[0xf] +
                        ((double)param_1[0xb] * param_2[0xe] +
                        ((double)param_1[3] * param_2[0xc] + (double)param_1[7] * param_2[0xd])));
  return;
}

/* _gleInvertMatrices @ 0x48e78 (156 bytes) */
int _gleInvertMatrices(param_1, param_2)
  int param_1;
  uint param_2;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = param_2 & 0xfffffff9;
  if ((param_2 & 0x10) != 0) {
    ((double (*)())_gleModelMatInvert)(param_1);
    uVar1 = param_2 & 0xffffffe9;
  }
  uVar3 = 0;
  uVar2 = uVar1;
  while (uVar2 != 0) {
    if ((uVar2 & 1) != 0) {
      *(uint *)(param_1 + 0x50b0) = *(uint *)(param_1 + 0x50b0) & ~(1 << (uVar3 & 0x3f));
      (*(code *)_gleInvertMatrix)(param_1,uVar3);
    }
    uVar3 = uVar3 + 1;
    uVar2 = uVar1 >> (uVar3 & 0x3f);
  }
  return;
}

/* _glPushAttrib_Exec @ 0x48f14 (548 bytes) */
void _glPushAttrib_Exec(param_1, param_2)
  int param_1;
  uint param_2;
{
  undefined4 uVar1;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (*(int *)(param_1 + 0x50fc) < 0x10) {
      **(undefined4 **)(param_1 + 0x50f8) = 0;
      if ((param_2 & 1) != 0) {
        ((void (*)())_gleAddAttribElem)(param_1,1);
      }
      if ((param_2 & 2) != 0) {
        ((void (*)())_gleAddAttribElem)(param_1,2);
      }
      if ((param_2 & 4) != 0) {
        ((void (*)())_gleAddAttribElem)(param_1,4);
      }
      if ((param_2 & 8) != 0) {
        ((void (*)())_gleAddAttribElem)(param_1,8);
      }
      if ((param_2 & 0x10) != 0) {
        ((void (*)())_gleAddAttribElem)(param_1,0x10);
      }
      if ((param_2 & 0x20) != 0) {
        ((void (*)())_gleAddAttribElem)(param_1,0x20);
      }
      if ((param_2 & 0x40) != 0) {
        ((void (*)())_gleAddAttribElem)(param_1,0x40);
      }
      if ((param_2 & 0x80) != 0) {
        ((void (*)())_gleAddAttribElem)(param_1,0x80);
      }
      if ((param_2 & 0x100) != 0) {
        ((void (*)())_gleAddAttribElem)(param_1,0x100);
      }
      if ((param_2 & 0x200) != 0) {
        ((void (*)())_gleAddAttribElem)(param_1,0x200);
      }
      if ((param_2 & 0x400) != 0) {
        ((void (*)())_gleAddAttribElem)(param_1,0x400);
      }
      if ((param_2 & 0x800) != 0) {
        ((void (*)())_gleAddAttribElem)(param_1,0x800);
      }
      if ((param_2 & 0x1000) != 0) {
        ((void (*)())_gleAddAttribElem)(param_1,0x1000);
      }
      if ((param_2 & 0x2000) != 0) {
        ((void (*)())_gleAddAttribElem)(param_1,0x2000);
      }
      if ((param_2 & 0x4000) != 0) {
        ((void (*)())_gleAddAttribElem)(param_1,0x4000);
      }
      if ((param_2 & 0x8000) != 0) {
        ((void (*)())_gleAddAttribElem)(param_1,0x8000);
      }
      if ((param_2 & 0x10000) != 0) {
        ((void (*)())_gleAddAttribElem)(param_1,0x10000);
      }
      if ((param_2 & 0x20000) != 0) {
        ((void (*)())_gleAddAttribElem)(param_1,0x20000);
      }
      if ((param_2 & 0x40000) != 0) {
        ((void (*)())_gleAddAttribElem)(param_1,0x40000);
      }
      if ((param_2 & 0x80000) != 0) {
        ((void (*)())_gleAddAttribElem)(param_1,0x80000);
      }
      *(int *)(param_1 + 0x50f8) = *(int *)(param_1 + 0x50f8) + 4;
      *(int *)(param_1 + 0x50fc) = *(int *)(param_1 + 0x50fc) + 1;
      return;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x503;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _gleAddAttribElem @ 0x49138 (120 bytes) */
void _gleAddAttribElem(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int *piVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)_malloc(0x2c48);
  if (puVar2 == (undefined4 *)0x0) {
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x505;
    }
  }
  else {
    *puVar2 = param_2;
    ((int (*)())_gleGetAttrib)(param_1,param_2,puVar2 + 1);
    piVar1 = *(int **)(param_1 + 0x50f8);
    puVar2[0xb11] = *piVar1;
    *piVar1 = (int)puVar2;
  }
  return;
}

/* _gleGetAttrib @ 0x491b0 (5648 bytes) */
int _gleGetAttrib(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  uint *param_3;
{
  uint *puVar1;
  undefined1 uVar2;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  ushort *puVar7;
  int iVar8;
  undefined1 *puVar9;
  uint *puVar10;
  int iVar11;
  int *piVar12;
  int iVar13;
  int iVar14;
  uint *puVar15;
  undefined1 *puVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  
  if (param_2 == 0x400) {
    puVar15 = (uint *)(param_1 + 0x3198);
    iVar14 = param_1 + 0x34f0;
    puVar10 = param_3;
    do {
      puVar10[2] = (uint)*(ushort *)(iVar14 + 0x10);
      *puVar10 = *(uint *)(iVar14 + 0xc);
      puVar10[1] = *(uint *)(iVar14 + 8);
      puVar10[3] = (uint)*(ushort *)(iVar14 + 0x12);
      puVar10[4] = (uint)*(ushort *)(iVar14 + 0x14);
      puVar7 = (ushort *)(iVar14 + 0x16);
      iVar14 = iVar14 + 0x10;
      puVar10[5] = (uint)*puVar7;
      uVar4 = *puVar15;
      puVar15 = puVar15 + 1;
      puVar10[6] = uVar4;
      puVar10 = puVar10 + 7;
    } while ((int)puVar10 <= (int)(param_3 + 7));
    param_3[0xe] = (uint)*(ushort *)(param_1 + 0x3518);
    param_3[0xf] = (uint)*(ushort *)(param_1 + 0x351a);
    param_3[0x10] = (uint)*(ushort *)(param_1 + 0x351c);
    param_3[0x11] = (uint)*(ushort *)(param_1 + 0x351e);
    param_3[0x13] = *(uint *)(param_1 + 0x3520);
    param_3[0x12] = *(uint *)(param_1 + 0x3114);
    param_3[0x14] = (uint)*(byte *)(param_1 + 0x7583);
    return param_1;
  }
  if (param_2 < 0x401) {
    if (param_2 == 0x10) {
      puVar9 = (undefined1 *)(param_1 + 0x3448);
      iVar14 = 0x80;
      do {
        uVar2 = *puVar9;
        puVar9 = puVar9 + 1;
        *(undefined1 *)param_3 = uVar2;
        param_3 = (uint *)((int)param_3 + 1);
        iVar14 = iVar14 + -1;
      } while (iVar14 != 0);
      return (int)puVar9;
    }
    if (param_2 < 0x11) {
      if (param_2 == 2) {
        *(undefined1 *)(param_3 + 10) = *(undefined1 *)(param_1 + 0x343c);
        *param_3 = *(uint *)(param_1 + 0x341c);
        param_3[1] = *(uint *)(param_1 + 0x3420);
        param_3[2] = *(uint *)(param_1 + 0x3424);
        param_3[3] = *(uint *)(param_1 + 0x3428);
        param_3[4] = *(uint *)(param_1 + 0x342c);
        param_3[5] = *(uint *)(param_1 + 0x3430);
        param_3[6] = *(uint *)(param_1 + 0x3434);
        param_3[7] = (uint)*(ushort *)(param_1 + 0x3440);
        param_3[9] = *(uint *)(param_1 + 0x3444);
        param_3[8] = (uint)*(ushort *)(param_1 + 0x3442);
        return param_1;
      }
      if (param_2 < 3) {
        if (param_2 != 1) {
          return param_1;
        }
        iVar5 = *(int *)(param_1 + 0x4854);
        iVar20 = 0x10;
        param_3[100] = *(uint *)(param_1 + 0x2a0);
        iVar6 = iVar5 + -0x200;
        param_3[0x65] = *(uint *)(param_1 + 0x2a4);
        param_3[0x66] = *(uint *)(param_1 + 0x2a8);
        param_3[0x67] = *(uint *)(param_1 + 0x2ac);
        puVar10 = param_3;
        iVar14 = param_1;
        do {
          puVar10[0x20] = *(uint *)(iVar14 + 0x1a0);
          puVar10[0x21] = *(uint *)(iVar14 + 0x1a4);
          puVar10[0x22] = *(uint *)(iVar14 + 0x1a8);
          puVar15 = (uint *)(iVar14 + 0x1ac);
          iVar14 = iVar14 + 0x10;
          puVar10[0x23] = *puVar15;
          puVar10 = puVar10 + 4;
          iVar20 = iVar20 + -1;
        } while (iVar20 != 0);
        puVar15 = param_3 + 0x60;
        iVar14 = 4;
        puVar10 = (uint *)(param_1 + 0x2d0);
        do {
          uVar4 = *puVar10;
          puVar10 = puVar10 + 1;
          *puVar15 = uVar4;
          puVar15 = puVar15 + 1;
          iVar14 = iVar14 + -1;
        } while (iVar14 != 0);
        iVar20 = 8;
        param_3[0x68] = *(uint *)(param_1 + 0x2b0);
        param_3[0x69] = *(uint *)(param_1 + 0x2b4);
        param_3[0x6a] = *(uint *)(param_1 + 0x2b8);
        param_3[0x6b] = *(uint *)(param_1 + 700);
        *(undefined8 *)(param_3 + 0x6c) = *(undefined8 *)(param_1 + 0x2c0);
        param_3[0x6e] = *(uint *)(param_1 + 0x2c8);
        param_3[0x6f] = *(uint *)(param_1 + 0x2cc);
        puVar10 = param_3;
        iVar14 = param_1;
        do {
          *puVar10 = *(uint *)(iVar14 + 0x120);
          puVar10[1] = *(uint *)(iVar14 + 0x128);
          puVar10[2] = *(uint *)(iVar14 + 0x124);
          puVar15 = (uint *)(iVar14 + 300);
          iVar14 = iVar14 + 0x10;
          puVar10[3] = *puVar15;
          puVar10[0x80] = *(uint *)(iVar6 + 0x80);
          puVar10[0x81] = *(uint *)(iVar6 + 0x84);
          puVar10[0x82] = *(uint *)(iVar6 + 0x88);
          puVar15 = (uint *)(iVar6 + 0x8c);
          iVar6 = iVar6 + 0x10;
          puVar10[0x83] = *puVar15;
          puVar10 = puVar10 + 4;
          iVar20 = iVar20 + -1;
        } while (iVar20 != 0);
        param_3[0x70] = *(uint *)(param_1 + 0x2e0);
        param_3[0x71] = *(uint *)(param_1 + 0x2e4);
        param_3[0x72] = *(uint *)(param_1 + 0x2e8);
        param_3[0x73] = *(uint *)(iVar5 + -500);
        param_3[0x74] = *(uint *)(iVar5 + -0x1e0);
        param_3[0x75] = *(uint *)(iVar5 + -0x1dc);
        param_3[0x76] = *(uint *)(iVar5 + -0x1d8);
        param_3[0x77] = *(uint *)(iVar5 + -0x1d4);
        param_3[0x78] = *(uint *)(iVar5 + -0x1f0);
        param_3[0x79] = *(uint *)(iVar5 + -0x1ec);
        param_3[0x7a] = *(uint *)(iVar5 + -0x1e8);
        param_3[0x7b] = *(uint *)(iVar5 + -0x1e4);
        param_3[0x7c] = *(uint *)(iVar5 + -0x1c0);
        param_3[0x7d] = *(uint *)(iVar5 + -0x1bc);
        param_3[0x7e] = *(uint *)(iVar5 + -0x1b8);
        param_3[0xa1] = *(uint *)(iVar5 + -0x1cc);
        param_3[0xa2] = *(uint *)(iVar5 + -0x1c8);
        param_3[0xa3] = *(uint *)(iVar5 + -0x1c4);
        uVar4 = *(uint *)(iVar5 + -0x1d0);
        param_3[0x7f] = 0x3f800000;
        param_3[0xa0] = uVar4;
        *(undefined1 *)((int)param_3 + 0x291) = *(undefined1 *)(param_1 + 0x2ef);
        *(undefined1 *)(param_3 + 0xa4) = *(undefined1 *)(param_1 + 0x2ec);
        return param_1;
      }
      if (param_2 == 4) {
        *(undefined1 *)((int)param_3 + 10) = *(undefined1 *)(param_1 + 0x318d);
        *(undefined1 *)((int)param_3 + 0xb) = *(undefined1 *)(param_1 + 0x318c);
        *(undefined2 *)(param_3 + 2) = *(undefined2 *)(param_1 + 0x3188);
        *param_3 = *(uint *)(param_1 + 0x3184);
        param_3[1] = *(uint *)(param_1 + 0x3180);
        return param_1;
      }
      if (param_2 != 8) {
        return param_1;
      }
      *(undefined1 *)(param_3 + 6) = *(undefined1 *)(param_1 + 0x34da);
      *param_3 = (uint)*(ushort *)(param_1 + 0x34d6);
      param_3[1] = (uint)*(ushort *)(param_1 + 0x34d4);
      param_3[2] = (uint)*(ushort *)(param_1 + 0x34d0);
      param_3[3] = (uint)*(ushort *)(param_1 + 0x34d2);
      *(undefined1 *)((int)param_3 + 0x19) = *(undefined1 *)(param_1 + 0x34d9);
      *(undefined1 *)((int)param_3 + 0x1a) = *(undefined1 *)(param_1 + 0x34d8);
      *(undefined1 *)((int)param_3 + 0x1b) = *(undefined1 *)(param_1 + 0x34dd);
      *(undefined1 *)(param_3 + 7) = *(undefined1 *)(param_1 + 0x34dc);
      *(undefined1 *)((int)param_3 + 0x1d) = *(undefined1 *)(param_1 + 0x34db);
      param_3[4] = *(uint *)(param_1 + 0x34c8);
      param_3[5] = *(uint *)(param_1 + 0x34cc);
      return param_1;
    }
    if (param_2 == 0x80) {
      *(undefined1 *)(param_3 + 9) = *(undefined1 *)(param_1 + 0x316a);
      *param_3 = *(uint *)(param_1 + 0x3140);
      param_3[1] = *(uint *)(param_1 + 0x3144);
      param_3[2] = *(uint *)(param_1 + 0x3148);
      param_3[3] = *(uint *)(param_1 + 0x314c);
      param_3[5] = *(uint *)(param_1 + 0x3150);
      param_3[6] = *(uint *)(param_1 + 0x3154);
      param_3[7] = *(uint *)(param_1 + 0x3158);
      param_3[4] = *(uint *)(param_1 + 0x3160);
      param_3[8] = (uint)*(ushort *)(param_1 + 0x3164);
      *(undefined1 *)((int)param_3 + 0x25) = *(undefined1 *)(param_1 + 0x4fea);
      return param_1;
    }
    if (0x80 < param_2) {
      if (param_2 == 0x100) {
        *(undefined1 *)(param_3 + 3) = *(undefined1 *)(param_1 + 0x3128);
        *param_3 = (uint)*(ushort *)(param_1 + 0x3124);
        *(undefined8 *)(param_3 + 1) = *(undefined8 *)(param_1 + 0x30e8);
        *(undefined1 *)((int)param_3 + 0xd) = *(undefined1 *)(param_1 + 0x31a4);
        *(undefined1 *)((int)param_3 + 0xf) = *(undefined1 *)(param_1 + 0x312a);
        *(undefined8 *)(param_3 + 4) = *(undefined8 *)(param_1 + 0x312c);
        *(undefined8 *)(param_3 + 6) = *(undefined8 *)(param_1 + 0x3134);
        *(undefined1 *)((int)param_3 + 0xe) = *(undefined1 *)(param_1 + 0x3129);
        return param_1;
      }
      if (param_2 != 0x200) {
        return param_1;
      }
      *param_3 = *(uint *)(param_1 + 0x30f0);
      param_3[1] = *(uint *)(param_1 + 0x30f4);
      param_3[2] = *(uint *)(param_1 + 0x30f8);
      param_3[3] = *(uint *)(param_1 + 0x30fc);
      return param_1;
    }
    if (param_2 == 0x20) {
      iVar14 = 0;
      param_3[2] = (uint)*(ushort *)(param_1 + 0x3118);
      *param_3 = *(uint *)(param_1 + 0x31a8);
      param_3[1] = *(uint *)(param_1 + 0x31ac);
      param_3[3] = *(uint *)(param_1 + 0x31e8);
      param_3[4] = *(uint *)(param_1 + 0x31ec);
      param_3[5] = *(uint *)(param_1 + 0x31f0);
      param_3[6] = *(uint *)(param_1 + 0x31f4);
      param_3[7] = *(uint *)(param_1 + 0x31f8);
      param_3[8] = *(uint *)(param_1 + 0x31fc);
      param_3[9] = *(uint *)(param_1 + 0x3200);
      param_3[10] = *(uint *)(param_1 + 0x3204);
      param_3[0xb] = *(uint *)(param_1 + 0x3208);
      param_3[0xc] = *(uint *)(param_1 + 0x320c);
      param_3[0xd] = *(uint *)(param_1 + 0x3210);
      param_3[0xe] = *(uint *)(param_1 + 0x3214);
      uVar4 = *(uint *)(param_1 + 0x3270);
      param_3[0xa0f] = uVar4;
      param_3[0xa10] = *(uint *)(param_1 + 0x3274);
      param_3[0xa11] = *(uint *)(param_1 + 0x3278);
      param_3[0xa12] = *(uint *)(param_1 + 0x327c);
      param_3[0xa13] = *(uint *)(param_1 + 0x3280);
      param_3[0xa14] = *(uint *)(param_1 + 0x3284);
      param_3[0xa15] = *(uint *)(param_1 + 0x3288);
      param_3[0xa16] = *(uint *)(param_1 + 0x328c);
      param_3[0xa17] = *(uint *)(param_1 + 0x3290);
      param_3[0xa18] = *(uint *)(param_1 + 0x3294);
      if (0 < (int)uVar4) {
        puVar10 = param_3 + 0xf;
        do {
          iVar5 = iVar14 * 4;
          iVar14 = iVar14 + 1;
          *puVar10 = *(uint *)(iVar5 + *(int *)(param_1 + 0x3248));
          puVar10 = puVar10 + 1;
          uVar4 = uVar4 - 1;
        } while (uVar4 != 0);
      }
      uVar4 = param_3[0xa11];
      iVar14 = 0;
      if (0 < (int)uVar4) {
        puVar10 = param_3 + 0x10f;
        do {
          iVar5 = iVar14 * 4;
          iVar14 = iVar14 + 1;
          *puVar10 = *(uint *)(iVar5 + *(int *)(param_1 + 0x324c));
          puVar10 = puVar10 + 1;
          uVar4 = uVar4 - 1;
        } while (uVar4 != 0);
      }
      uVar4 = param_3[0xa12];
      iVar14 = 0;
      if (0 < (int)uVar4) {
        puVar10 = param_3 + 0x20f;
        do {
          iVar5 = iVar14 * 4;
          iVar14 = iVar14 + 1;
          *puVar10 = *(uint *)(iVar5 + *(int *)(param_1 + 0x3250));
          puVar10 = puVar10 + 1;
          uVar4 = uVar4 - 1;
        } while (uVar4 != 0);
      }
      uVar4 = param_3[0xa13];
      iVar14 = 0;
      if (0 < (int)uVar4) {
        puVar10 = param_3 + 0x30f;
        do {
          iVar5 = iVar14 * 4;
          iVar14 = iVar14 + 1;
          *puVar10 = *(uint *)(iVar5 + *(int *)(param_1 + 0x3254));
          puVar10 = puVar10 + 1;
          uVar4 = uVar4 - 1;
        } while (uVar4 != 0);
      }
      uVar4 = param_3[0xa14];
      iVar14 = 0;
      if (0 < (int)uVar4) {
        puVar10 = param_3 + 0x40f;
        do {
          iVar5 = iVar14 * 4;
          iVar14 = iVar14 + 1;
          *puVar10 = *(uint *)(iVar5 + *(int *)(param_1 + 0x3258));
          puVar10 = puVar10 + 1;
          uVar4 = uVar4 - 1;
        } while (uVar4 != 0);
      }
      uVar4 = param_3[0xa15];
      iVar14 = 0;
      if (0 < (int)uVar4) {
        puVar10 = param_3 + 0x50f;
        do {
          iVar5 = iVar14 * 4;
          iVar14 = iVar14 + 1;
          *puVar10 = *(uint *)(iVar5 + *(int *)(param_1 + 0x325c));
          puVar10 = puVar10 + 1;
          uVar4 = uVar4 - 1;
        } while (uVar4 != 0);
      }
      uVar4 = param_3[0xa16];
      iVar14 = 0;
      if (0 < (int)uVar4) {
        puVar10 = param_3 + 0x60f;
        do {
          iVar5 = iVar14 * 4;
          iVar14 = iVar14 + 1;
          *puVar10 = *(uint *)(iVar5 + *(int *)(param_1 + 0x3260));
          puVar10 = puVar10 + 1;
          uVar4 = uVar4 - 1;
        } while (uVar4 != 0);
      }
      uVar4 = param_3[0xa17];
      iVar14 = 0;
      if (0 < (int)uVar4) {
        puVar10 = param_3 + 0x70f;
        do {
          iVar5 = iVar14 * 4;
          iVar14 = iVar14 + 1;
          *puVar10 = *(uint *)(iVar5 + *(int *)(param_1 + 0x3264));
          puVar10 = puVar10 + 1;
          uVar4 = uVar4 - 1;
        } while (uVar4 != 0);
      }
      uVar4 = param_3[0xa18];
      iVar14 = 0;
      if (0 < (int)uVar4) {
        puVar10 = param_3 + 0x80f;
        do {
          iVar5 = iVar14 * 4;
          iVar14 = iVar14 + 1;
          *puVar10 = *(uint *)(iVar5 + *(int *)(param_1 + 0x3268));
          puVar10 = puVar10 + 1;
          uVar4 = uVar4 - 1;
        } while (uVar4 != 0);
      }
      uVar4 = param_3[0xa10];
      iVar14 = 0;
      if (0 < (int)uVar4) {
        puVar10 = param_3 + 0x90f;
        do {
          iVar5 = iVar14 * 4;
          iVar14 = iVar14 + 1;
          *puVar10 = *(uint *)(iVar5 + *(int *)(param_1 + 0x326c));
          puVar10 = puVar10 + 1;
          uVar4 = uVar4 - 1;
        } while (uVar4 != 0);
      }
      *(byte *)(param_3 + 0xa19) = *(byte *)(param_1 + 0x3417) & 1;
      *(byte *)((int)param_3 + 0x2865) = (byte)(*(uint *)(param_1 + 0x3414) >> 1) & 1;
      return param_1;
    }
    if (param_2 != 0x40) {
      return param_1;
    }
    iVar5 = 8;
    *(undefined1 *)(param_3 + 8) = *(undefined1 *)(param_1 + 0x30ab);
    param_3[1] = (uint)*(ushort *)(param_1 + 0x30a4);
    param_3[2] = (uint)*(ushort *)(param_1 + 0x30a6);
    param_3[3] = *(uint *)(param_1 + 0x2810);
    param_3[4] = *(uint *)(param_1 + 0x2814);
    param_3[5] = *(uint *)(param_1 + 0x2818);
    param_3[6] = *(uint *)(param_1 + 0x281c);
    *(undefined1 *)((int)param_3 + 0x21) = *(undefined1 *)(param_1 + 0x30ad);
    *(undefined1 *)((int)param_3 + 0x22) = *(undefined1 *)(param_1 + 0x30ac);
    *(undefined1 *)((int)param_3 + 0x23) = *(undefined1 *)(param_1 + 0x30ae);
    *(undefined1 *)(param_3 + 9) = *(undefined1 *)(param_1 + 0x30aa);
    uVar4 = *(uint *)(param_1 + 0x30a0);
    param_3[7] = 8;
    param_3[10] = uVar4;
    puVar10 = param_3;
    iVar14 = param_1;
    do {
      puVar10[0x17] = *(uint *)(iVar14 + 0x2850);
      puVar10[0x18] = *(uint *)(iVar14 + 0x2854);
      puVar10[0x19] = *(uint *)(iVar14 + 0x2858);
      puVar10[0x1a] = *(uint *)(iVar14 + 0x285c);
      puVar10[0xb] = *(uint *)(iVar14 + 0x2820);
      puVar10[0xc] = *(uint *)(iVar14 + 0x2824);
      puVar10[0xd] = *(uint *)(iVar14 + 0x2828);
      puVar10[0xe] = *(uint *)(iVar14 + 0x282c);
      puVar10[0xf] = *(uint *)(iVar14 + 0x2830);
      puVar10[0x10] = *(uint *)(iVar14 + 0x2834);
      puVar10[0x11] = *(uint *)(iVar14 + 0x2838);
      puVar10[0x12] = *(uint *)(iVar14 + 0x283c);
      puVar10[0x13] = *(uint *)(iVar14 + 0x2840);
      puVar10[0x14] = *(uint *)(iVar14 + 0x2844);
      puVar10[0x15] = *(uint *)(iVar14 + 0x2848);
      puVar10[0x16] = *(uint *)(iVar14 + 0x284c);
      puVar10[0x1b] = *(uint *)(iVar14 + 0x2860);
      puVar10[0x1c] = *(uint *)(iVar14 + 0x2864);
      puVar10[0x1d] = *(uint *)(iVar14 + 0x2868);
      puVar10[0x1e] = *(uint *)(iVar14 + 0x287c);
      puVar10[0x1f] = *(uint *)(iVar14 + 0x2890);
      puVar10[0x20] = *(uint *)(iVar14 + 0x286c);
      puVar10[0x21] = *(uint *)(iVar14 + 0x2870);
      puVar10[0x22] = *(uint *)(iVar14 + 0x2874);
      puVar15 = (uint *)(iVar14 + 0x2878);
      iVar14 = iVar14 + 0x80;
      puVar10[0x23] = *puVar15;
      puVar10 = puVar10 + 0x19;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    puVar10 = param_3;
    iVar14 = param_1;
    iVar5 = param_1;
    do {
      puVar10[0x19b] = **(uint **)(iVar5 + 0x4dd0);
      puVar10[0x19c] = *(uint *)(*(int *)(iVar5 + 0x4dd0) + 4);
      puVar10[0x19d] = *(uint *)(*(int *)(iVar5 + 0x4dd0) + 8);
      puVar10[0x19e] = *(uint *)(*(int *)(iVar5 + 0x4dd0) + 0xc);
      puVar10[0x19f] = *(uint *)(*(int *)(iVar5 + 0x4dd0) + 0x10);
      puVar10[0x1a0] = *(uint *)(*(int *)(iVar5 + 0x4dd0) + 0x14);
      puVar10[0x1a1] = *(uint *)(*(int *)(iVar5 + 0x4dd0) + 0x18);
      puVar10[0x1a2] = *(uint *)(*(int *)(iVar5 + 0x4dd0) + 0x1c);
      puVar10[0x1a3] = *(uint *)(*(int *)(iVar5 + 0x4dd0) + 0x20);
      puVar10[0x1a4] = *(uint *)(*(int *)(iVar5 + 0x4dd0) + 0x24);
      puVar10[0x1a5] = *(uint *)(*(int *)(iVar5 + 0x4dd0) + 0x28);
      puVar10[0x1a6] = *(uint *)(*(int *)(iVar5 + 0x4dd0) + 0x2c);
      puVar10[0x1a7] = *(uint *)(*(int *)(iVar5 + 0x4dd0) + 0x30);
      puVar10[0x1a8] = *(uint *)(*(int *)(iVar5 + 0x4dd0) + 0x34);
      puVar10[0x1a9] = *(uint *)(*(int *)(iVar5 + 0x4dd0) + 0x38);
      puVar10[0x1aa] = *(uint *)(*(int *)(iVar5 + 0x4dd0) + 0x3c);
      piVar12 = (int *)(iVar5 + 0x4dd0);
      iVar5 = iVar5 + 4;
      puVar10[0x1ae] = *(uint *)(*piVar12 + 0x40);
      puVar10[0x1ab] = *(uint *)(iVar14 + 0x2f0);
      puVar10[0x1ac] = *(uint *)(iVar14 + 0x2f4);
      puVar15 = (uint *)(iVar14 + 0x2f8);
      iVar14 = iVar14 + 0x10;
      puVar10[0x1ad] = *puVar15;
      puVar10 = puVar10 + 0x14;
    } while (iVar14 <= param_1 + 0x10);
    uVar4 = *(uint *)(param_1 + 0x34f4);
LAB_0004a27c:
    *param_3 = uVar4;
  }
  else {
    if (param_2 == 0x8000) {
      *param_3 = (uint)*(ushort *)(param_1 + 0x316c);
      param_3[1] = (uint)*(ushort *)(param_1 + 0x316e);
      param_3[2] = (uint)*(ushort *)(param_1 + 0x3170);
      param_3[3] = (uint)*(ushort *)(param_1 + 0x3172);
      param_3[4] = (uint)*(ushort *)(param_1 + 0x3174);
      param_3[5] = *(uint *)(param_1 + 0x507c);
      param_3[6] = *(uint *)(param_1 + 0x5080);
      uVar4 = (uint)*(ushort *)(param_1 + 0x3176);
    }
    else {
      if (0x8000 < param_2) {
        if (param_2 == 0x40000) {
          iVar5 = 8;
          puVar10 = param_3;
          iVar14 = param_1;
          do {
            puVar10[1] = *(uint *)(iVar14 + 0x3cfc);
            puVar10[2] = *(uint *)(iVar14 + 0x3d00);
            puVar10[3] = *(uint *)(iVar14 + 0x3d04);
            puVar10[4] = *(uint *)(iVar14 + 0x3d08);
            puVar10[5] = *(uint *)(iVar14 + 0x3cec);
            puVar10[6] = *(uint *)(iVar14 + 0x3cf0);
            puVar10[7] = *(uint *)(iVar14 + 0x3cf4);
            puVar10[8] = *(uint *)(iVar14 + 0x3cf8);
            puVar10[0xb] = *(uint *)(iVar14 + 0x3d20);
            puVar10[0xc] = *(uint *)(iVar14 + 0x3d24);
            puVar10[0xd] = *(uint *)(iVar14 + 0x3d28);
            puVar10[0xe] = *(uint *)(iVar14 + 0x3d2c);
            puVar10[0xf] = *(uint *)(iVar14 + 0x3d10);
            puVar10[0x10] = *(uint *)(iVar14 + 0x3d14);
            puVar10[0x11] = *(uint *)(iVar14 + 0x3d18);
            puVar10[0x12] = *(uint *)(iVar14 + 0x3d1c);
            puVar10[0x15] = *(uint *)(iVar14 + 0x3d44);
            puVar10[0x16] = *(uint *)(iVar14 + 0x3d48);
            puVar10[0x17] = *(uint *)(iVar14 + 0x3d4c);
            puVar10[0x18] = *(uint *)(iVar14 + 0x3d50);
            puVar10[0x19] = *(uint *)(iVar14 + 0x3d34);
            puVar10[0x1a] = *(uint *)(iVar14 + 0x3d38);
            puVar10[0x1b] = *(uint *)(iVar14 + 0x3d3c);
            puVar10[0x1c] = *(uint *)(iVar14 + 0x3d40);
            puVar10[0x1f] = *(uint *)(iVar14 + 0x3d68);
            puVar10[0x20] = *(uint *)(iVar14 + 0x3d6c);
            puVar10[0x21] = *(uint *)(iVar14 + 0x3d70);
            puVar10[0x22] = *(uint *)(iVar14 + 0x3d74);
            puVar10[0x23] = *(uint *)(iVar14 + 0x3d58);
            puVar10[0x24] = *(uint *)(iVar14 + 0x3d5c);
            puVar10[0x25] = *(uint *)(iVar14 + 0x3d60);
            puVar10[0x26] = *(uint *)(iVar14 + 0x3d64);
            *(undefined1 *)(puVar10 + 9) = *(undefined1 *)(iVar14 + 0x3d78);
            *(undefined1 *)(puVar10 + 0x13) = *(undefined1 *)(iVar14 + 0x3d79);
            *(undefined1 *)(puVar10 + 0x1d) = *(undefined1 *)(iVar14 + 0x3d7a);
            *(undefined1 *)(puVar10 + 0x27) = *(undefined1 *)(iVar14 + 0x3d7b);
            *puVar10 = (uint)*(ushort *)(iVar14 + 0x3ce8);
            puVar10[10] = (uint)*(ushort *)(iVar14 + 0x3d0c);
            puVar10[0x14] = (uint)*(ushort *)(iVar14 + 0x3d30);
            puVar7 = (ushort *)(iVar14 + 0x3d54);
            iVar14 = iVar14 + 0x94;
            puVar10[0x1e] = (uint)*puVar7;
            puVar10 = puVar10 + 0x28;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
          iVar20 = 0;
          iVar6 = param_1 + 0x3530;
          puVar10 = param_3 + 0x1c4;
          iVar19 = 0;
          iVar14 = param_1;
          iVar5 = param_1;
          do {
            iVar17 = iVar19 + (int)param_3;
            iVar13 = iVar5 + 0x5140;
            *puVar10 = *(uint *)(iVar6 + 4);
            iVar21 = 5;
            do {
              iVar8 = *(int *)(iVar13 + 0x14);
              *(undefined4 *)(iVar17 + 0x514) = *(undefined4 *)(iVar8 + 0x50);
              *(undefined4 *)(iVar17 + 0x518) = *(undefined4 *)(iVar8 + 0x58);
              *(undefined4 *)(iVar17 + 0x51c) = *(undefined4 *)(iVar8 + 0x54);
              *(undefined4 *)(iVar17 + 0x520) = *(undefined4 *)(iVar8 + 0x5c);
              *(uint *)(iVar17 + 0x500) = (uint)*(ushort *)(iVar8 + 0x4a);
              *(uint *)(iVar17 + 0x504) = (uint)*(ushort *)(iVar8 + 0x4c);
              *(uint *)(iVar17 + 0x508) = (uint)*(ushort *)(iVar8 + 0x44);
              *(uint *)(iVar17 + 0x50c) = (uint)*(ushort *)(iVar8 + 0x46);
              *(uint *)(iVar17 + 0x510) = (uint)*(ushort *)(iVar8 + 0x48);
              piVar12 = (int *)(iVar13 + 0x14);
              iVar13 = iVar13 + 4;
              *(undefined4 *)(iVar17 + 0x524) = *(undefined4 *)(*piVar12 + 4);
              *(undefined4 *)(iVar17 + 0x528) = *(undefined4 *)(iVar8 + 0x38);
              *(undefined4 *)(iVar17 + 0x52c) = *(undefined4 *)(iVar8 + 0x60);
              *(undefined4 *)(iVar17 + 0x530) = *(undefined4 *)(iVar8 + 100);
              *(undefined4 *)(iVar17 + 0x534) = *(undefined4 *)(iVar8 + 0x68);
              *(undefined4 *)(iVar17 + 0x538) = *(undefined4 *)(iVar8 + 0x6c);
              *(int *)(iVar17 + 0x53c) = (int)*(short *)(iVar8 + 0x70);
              *(int *)(iVar17 + 0x540) = (int)*(short *)(iVar8 + 0x72);
              *(uint *)(iVar17 + 0x544) = (uint)*(ushort *)(iVar8 + 0x76);
              *(uint *)(iVar17 + 0x548) = (uint)*(ushort *)(iVar8 + 0x74);
              *(undefined4 *)(iVar17 + 0x54c) = *(undefined4 *)(iVar8 + 0x78);
              *(uint *)(iVar17 + 0x550) = (uint)*(ushort *)(iVar8 + 0x7c);
              iVar17 = iVar17 + 0x58;
              iVar21 = iVar21 + -1;
            } while (iVar21 != 0);
            iVar17 = 0;
            iVar13 = iVar19 + (int)param_3;
            do {
              iVar17 = iVar17 + -1;
              *(undefined4 *)(iVar13 + 0x6b8) = *(undefined4 *)(iVar14 + 0x3524);
              *(undefined4 *)(iVar13 + 0x6bc) = *(undefined4 *)(iVar14 + 0x3528);
              *(undefined4 *)(iVar13 + 0x6c0) = *(undefined4 *)(iVar14 + 0x352c);
              *(undefined4 *)(iVar13 + 0x6c4) = *(undefined4 *)(iVar14 + 0x3530);
              *(uint *)(iVar13 + 0x6c8) = (uint)*(ushort *)(iVar6 + 8);
              *(uint *)(iVar13 + 0x6cc) = (uint)*(ushort *)(iVar6 + 0xc);
              *(uint *)(iVar13 + 0x6d0) = (uint)*(ushort *)(iVar6 + 0xe);
              *(uint *)(iVar13 + 0x6d4) = (uint)*(ushort *)(iVar6 + 0x10);
              *(uint *)(iVar13 + 0x6d8) = (uint)*(ushort *)(iVar6 + 0x12);
              *(uint *)(iVar13 + 0x6dc) = (uint)*(ushort *)(iVar14 + 0x3544);
              *(uint *)(iVar13 + 0x6e0) = (uint)*(ushort *)(iVar14 + 0x3546);
              *(uint *)(iVar13 + 0x6e4) = (uint)*(ushort *)(iVar14 + 0x3548);
              *(uint *)(iVar13 + 0x6e8) = (uint)*(ushort *)(iVar14 + 0x354a);
              *(uint *)(iVar13 + 0x6ec) = (uint)*(ushort *)(iVar14 + 0x354c);
              *(uint *)(iVar13 + 0x6f0) = (uint)*(ushort *)(iVar14 + 0x354e);
              *(uint *)(iVar13 + 0x6f4) = (uint)*(ushort *)(iVar14 + 0x3550);
              *(uint *)(iVar13 + 0x6f8) = (uint)*(ushort *)(iVar14 + 0x3552);
              *(uint *)(iVar13 + 0x6fc) = (uint)*(ushort *)(iVar14 + 0x3554);
              *(uint *)(iVar13 + 0x700) = (uint)*(ushort *)(iVar14 + 0x3556);
              *(undefined4 *)(iVar13 + 0x704) = *(undefined4 *)(iVar14 + 0x3558);
              *(undefined4 *)(iVar13 + 0x708) = *(undefined4 *)(iVar14 + 0x355c);
              *(undefined4 *)(iVar13 + 0x70c) = *(undefined4 *)(iVar14 + 0x3560);
              iVar13 = iVar13 + 0x58;
            } while (-1 < iVar17);
            iVar20 = iVar20 + 1;
            iVar19 = iVar19 + 0x214;
            puVar10 = puVar10 + 0x85;
            iVar5 = iVar5 + 0x14;
            iVar14 = iVar14 + 0x7c;
            iVar6 = iVar6 + 0x7c;
          } while (iVar20 < 0x10);
          iVar5 = param_1 + 0x41f0;
          puVar10 = param_3 + 0x990;
          iVar14 = 1;
          param_3[0x991] = *(uint *)(param_1 + 0x41fc);
          do {
            iVar14 = iVar14 + -1;
            puVar10[2] = *(uint *)(iVar5 + 0x10);
            puVar10[3] = *(uint *)(iVar5 + 0x14);
            puVar10[4] = *(uint *)(iVar5 + 0x18);
            puVar15 = (uint *)(iVar5 + 0x1c);
            iVar5 = iVar5 + 0x10;
            puVar10[5] = *puVar15;
            puVar10 = puVar10 + 4;
          } while (-1 < iVar14);
          iVar6 = 0;
          iVar20 = 0;
          iVar14 = param_1;
          iVar5 = param_1;
          puVar10 = param_3;
          do {
            iVar8 = 0;
            iVar19 = param_1 + iVar20 * 8;
            iVar13 = iVar14 + 0x4270;
            puVar15 = puVar10 + 0x9bc;
            iVar17 = iVar5 + 0x4230;
            iVar21 = iVar6 + (int)param_3;
            do {
              iVar18 = iVar19 + 0x4210;
              iVar22 = 4;
              iVar11 = iVar21 + 0x2660;
              do {
                *(uint *)(iVar11 + 8) = (uint)*(ushort *)(iVar18 + 0x10);
                *(uint *)(iVar11 + 0xc) = (uint)*(ushort *)(iVar18 + 0x12);
                puVar7 = (ushort *)(iVar18 + 0x14);
                iVar18 = iVar18 + 8;
                *(uint *)(iVar11 + 0x10) = (uint)*puVar7;
                iVar11 = iVar11 + 0xc;
                iVar22 = iVar22 + -1;
              } while (iVar22 != 0);
              iVar8 = iVar8 + 1;
              iVar19 = iVar19 + 0x30;
              *(undefined1 *)(iVar21 + 0x2698) = *(undefined1 *)(iVar17 + 0x10);
              *(undefined1 *)(iVar21 + 0x2699) = *(undefined1 *)(iVar17 + 0x11);
              *(undefined1 *)(iVar21 + 0x269a) = *(undefined1 *)(iVar17 + 0x12);
              *(uint *)(iVar21 + 0x269c) = (uint)*(ushort *)(iVar17 + 0x14);
              *(uint *)(iVar21 + 0x26a0) = (uint)*(ushort *)(iVar17 + 0x16);
              *(uint *)(iVar21 + 0x26a4) = (uint)*(ushort *)(iVar17 + 0x18);
              *(uint *)(iVar21 + 0x26a8) = (uint)*(ushort *)(iVar17 + 0x1a);
              puVar7 = (ushort *)(iVar17 + 0x1c);
              iVar17 = iVar17 + 0x30;
              *(uint *)(iVar21 + 0x26ac) = (uint)*puVar7;
              iVar21 = iVar21 + 0x48;
              puVar15[2] = *(uint *)(iVar13 + 0x10);
              puVar15[3] = *(uint *)(iVar13 + 0x14);
              puVar15[4] = *(uint *)(iVar13 + 0x18);
              puVar1 = (uint *)(iVar13 + 0x1c);
              iVar13 = iVar13 + 0x10;
              puVar15[5] = *puVar1;
              puVar15 = puVar15 + 4;
            } while (iVar8 < 2);
            iVar5 = iVar5 + 0x80;
            iVar20 = iVar20 + 0x10;
            iVar14 = iVar14 + 0x80;
            iVar6 = iVar6 + 0xb0;
            puVar10 = puVar10 + 0x2c;
          } while (iVar5 <= param_1 + 0x380);
          iVar5 = param_1 + 0x4610;
          puVar10 = param_3 + 0xaf8;
          *(undefined1 *)(param_3 + 0xafa) = *(undefined1 *)(param_1 + 0x4620);
          iVar6 = 7;
          do {
            puVar10[3] = (uint)*(ushort *)(iVar5 + 0x14);
            puVar10[4] = (uint)*(ushort *)(iVar5 + 0x16);
            puVar7 = (ushort *)(iVar5 + 0x18);
            iVar5 = iVar5 + 8;
            puVar10[5] = (uint)*puVar7;
            puVar10 = puVar10 + 3;
            iVar6 = iVar6 + -1;
          } while (iVar6 != 0);
          param_3[0x990] = *(int *)(param_1 + 0x53d4) + 0x84c0;
          return iVar14;
        }
        if (0x40000 < param_2) {
          if (param_2 == 0x80000) {
            *(undefined1 *)(param_3 + 4) = *(undefined1 *)(param_1 + 0x34f0);
            *param_3 = *(uint *)(param_1 + 0x34e0);
            param_3[1] = *(uint *)(param_1 + 0x34e4);
            param_3[2] = *(uint *)(param_1 + 0x34e8);
            param_3[3] = *(uint *)(param_1 + 0x34ec);
            return param_1;
          }
          if (param_2 != 0x20000000) {
            return param_1;
          }
          *param_3 = *(uint *)(param_1 + 0x41ec);
          *(undefined1 *)(param_3 + 1) = *(undefined1 *)(param_1 + 0x41f0);
          *(undefined1 *)((int)param_3 + 5) = *(undefined1 *)(param_1 + 0x41f1);
          *(undefined1 *)((int)param_3 + 6) = *(undefined1 *)(param_1 + 0x41f2);
          *(undefined1 *)((int)param_3 + 7) = *(undefined1 *)(param_1 + 0x41f3);
          *(undefined1 *)(param_3 + 2) = *(undefined1 *)(param_1 + 0x41f4);
          return param_1;
        }
        if (param_2 == 0x10000) {
          *param_3 = *(uint *)(param_1 + 0x74a8);
          param_3[1] = *(uint *)(param_1 + 0x74ac);
          param_3[2] = *(uint *)(param_1 + 0x74b0);
          param_3[7] = *(uint *)(param_1 + 0x74b8);
          param_3[9] = *(uint *)(param_1 + 0x74bc);
          param_3[10] = *(uint *)(param_1 + 0x74c0);
          param_3[8] = *(uint *)(param_1 + 0x74c8);
          param_3[0xb] = *(uint *)(param_1 + 0x74cc);
          param_3[0xc] = *(uint *)(param_1 + 0x74d0);
          param_3[3] = *(uint *)(param_1 + 0x74d8);
          param_3[0xd] = *(uint *)(param_1 + 0x74dc);
          *(undefined1 *)(param_3 + 4) = *(undefined1 *)(param_1 + 0x74e0);
          *(undefined1 *)((int)param_3 + 0x11) = *(undefined1 *)(param_1 + 0x74e1);
          *(undefined1 *)((int)param_3 + 0x12) = *(undefined1 *)(param_1 + 0x74e2);
          *(undefined1 *)((int)param_3 + 0x13) = *(undefined1 *)(param_1 + 0x74e3);
          *(undefined1 *)(param_3 + 5) = *(undefined1 *)(param_1 + 0x74e4);
          *(undefined1 *)((int)param_3 + 0x15) = *(undefined1 *)(param_1 + 0x74e5);
          *(undefined1 *)((int)param_3 + 0x16) = *(undefined1 *)(param_1 + 0x74e6);
          *(undefined1 *)((int)param_3 + 0x17) = *(undefined1 *)(param_1 + 0x74e7);
          *(undefined1 *)(param_3 + 6) = *(undefined1 *)(param_1 + 0x74e8);
          *(undefined1 *)(param_3 + 0xe) = *(undefined1 *)(param_1 + 0x74e9);
          *(undefined1 *)((int)param_3 + 0x39) = *(undefined1 *)(param_1 + 0x74ea);
          *(undefined1 *)((int)param_3 + 0x3a) = *(undefined1 *)(param_1 + 0x74eb);
          *(undefined1 *)((int)param_3 + 0x3b) = *(undefined1 *)(param_1 + 0x74ec);
          *(undefined1 *)(param_3 + 0xf) = *(undefined1 *)(param_1 + 0x74ed);
          *(undefined1 *)((int)param_3 + 0x3d) = *(undefined1 *)(param_1 + 0x74ee);
          *(undefined1 *)((int)param_3 + 0x3e) = *(undefined1 *)(param_1 + 0x74ef);
          *(undefined1 *)((int)param_3 + 0x3f) = *(undefined1 *)(param_1 + 0x74f0);
          *(undefined1 *)(param_3 + 0x10) = *(undefined1 *)(param_1 + 0x74f1);
          *(undefined1 *)(param_3 + 0x11) = *(undefined1 *)(param_1 + 0x74f2);
          return param_1;
        }
        if (param_2 != 0x20000) {
          return param_1;
        }
        uVar4 = *(uint *)(param_1 + 0x5404);
        goto LAB_0004a27c;
      }
      if (param_2 == 0x1000) {
        iVar5 = 6;
        iVar14 = param_1 + 0x4180;
        param_3[1] = *(uint *)(param_1 + 0x4ff4);
        puVar10 = param_3 + 0x808;
        *(undefined1 *)(param_3 + 3) = *(undefined1 *)(param_1 + 0x280d);
        *(undefined1 *)((int)param_3 + 0xd) = *(undefined1 *)(param_1 + 0x280e);
        *(undefined1 *)((int)param_3 + 0xf) = *(undefined1 *)(param_1 + 0x280c);
        param_3[4] = (uint)*(ushort *)(param_1 + 0x2808);
        param_3[5] = (uint)*(ushort *)(param_1 + 0x280a);
        uVar4 = *(uint *)(param_1 + 0x2800);
        *param_3 = 6;
        param_3[6] = uVar4;
        param_3[0x80a] = *(uint *)(param_1 + 0x4188);
        do {
          puVar10[3] = *(uint *)(iVar14 + 0xc);
          puVar10[4] = *(uint *)(iVar14 + 0x10);
          puVar10[5] = *(uint *)(iVar14 + 0x14);
          puVar15 = (uint *)(iVar14 + 0x18);
          iVar14 = iVar14 + 0x10;
          puVar10[6] = *puVar15;
          puVar10 = puVar10 + 4;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
        puVar10 = param_3 + 7;
        piVar12 = (int *)(param_1 + 0x5420);
        iVar14 = 1;
        puVar15 = param_3 + 0x809;
        puVar9 = (undefined1 *)(param_1 + 0x4664);
        do {
          iVar5 = *piVar12;
          iVar14 = iVar14 + -1;
          piVar12 = piVar12 + 1;
          *puVar10 = *(uint *)(iVar5 + 4);
          puVar10 = puVar10 + 1;
          uVar2 = *puVar9;
          puVar9 = puVar9 + 8;
          *(undefined1 *)puVar15 = uVar2;
          puVar15 = (uint *)((int)puVar15 + 1);
        } while (-1 < iVar14);
        puVar15 = *(uint **)(param_1 + 0x4668);
        iVar14 = 0x100;
        puVar10 = param_3 + 8;
        do {
          puVar10[1] = *puVar15;
          puVar10[2] = puVar15[1];
          puVar10[3] = puVar15[2];
          puVar1 = puVar15 + 3;
          puVar15 = puVar15 + 4;
          puVar10[4] = *puVar1;
          puVar10 = puVar10 + 4;
          iVar14 = iVar14 + -1;
        } while (iVar14 != 0);
        puVar15 = *(uint **)(param_1 + 0x4670);
        iVar14 = 0x80;
        puVar10 = param_3 + 0x408;
        do {
          puVar10[1] = *puVar15;
          puVar10[2] = puVar15[1];
          puVar10[3] = puVar15[2];
          puVar1 = puVar15 + 3;
          puVar15 = puVar15 + 4;
          puVar10[4] = *puVar1;
          puVar10 = puVar10 + 4;
          iVar14 = iVar14 + -1;
        } while (iVar14 != 0);
        *(undefined1 *)((int)param_3 + 0xe) = *(undefined1 *)(param_1 + 0x4661);
        param_3[2] = (uint)*(byte *)(param_1 + 0x4660);
        return param_1;
      }
      if (0x1000 < param_2) {
        if (param_2 == 0x2000) {
          puVar15 = param_3 + 8;
          puVar10 = (uint *)(param_1 + 0x3534);
          *(undefined1 *)((int)param_3 + 0x97) = *(undefined1 *)(param_1 + 0x316a);
          iVar14 = 0x10;
          *(undefined1 *)(param_3 + 0x26) = *(undefined1 *)(param_1 + 0x30aa);
          *(undefined1 *)((int)param_3 + 0x9a) = *(undefined1 *)(param_1 + 0x318c);
          *(undefined1 *)((int)param_3 + 0xa3) = *(undefined1 *)(param_1 + 0x34d8);
          *(undefined1 *)(param_3 + 0x25) = *(undefined1 *)(param_1 + 0x34da);
          *(undefined1 *)(param_3 + 0x24) = *(undefined1 *)(param_1 + 0x30c6);
          *(undefined1 *)((int)param_3 + 0x92) = *(undefined1 *)(param_1 + 0x30e4);
          *(undefined1 *)((int)param_3 + 0x9b) = *(undefined1 *)(param_1 + 0x3193);
          *(undefined1 *)(param_3 + 0x27) = *(undefined1 *)(param_1 + 0x3192);
          *(undefined1 *)((int)param_3 + 0x96) = *(undefined1 *)(param_1 + 0x313c);
          *(undefined1 *)((int)param_3 + 0x95) = *(undefined1 *)(param_1 + 0x3128);
          *param_3 = *(uint *)(param_1 + 0x74d8);
          param_3[4] = *(uint *)(param_1 + 0x74dc);
          *(undefined1 *)(param_3 + 1) = *(undefined1 *)(param_1 + 0x74e0);
          *(undefined1 *)((int)param_3 + 5) = *(undefined1 *)(param_1 + 0x74e1);
          *(undefined1 *)((int)param_3 + 6) = *(undefined1 *)(param_1 + 0x74e2);
          *(undefined1 *)((int)param_3 + 7) = *(undefined1 *)(param_1 + 0x74e3);
          *(undefined1 *)(param_3 + 2) = *(undefined1 *)(param_1 + 0x74e4);
          *(undefined1 *)((int)param_3 + 9) = *(undefined1 *)(param_1 + 0x74e5);
          *(undefined1 *)((int)param_3 + 10) = *(undefined1 *)(param_1 + 0x74e6);
          *(undefined1 *)((int)param_3 + 0xb) = *(undefined1 *)(param_1 + 0x74e7);
          *(undefined1 *)(param_3 + 3) = *(undefined1 *)(param_1 + 0x74e8);
          *(undefined1 *)(param_3 + 5) = *(undefined1 *)(param_1 + 0x74e9);
          *(undefined1 *)((int)param_3 + 0x15) = *(undefined1 *)(param_1 + 0x74ea);
          *(undefined1 *)((int)param_3 + 0x16) = *(undefined1 *)(param_1 + 0x74eb);
          *(undefined1 *)((int)param_3 + 0x17) = *(undefined1 *)(param_1 + 0x74ec);
          *(undefined1 *)(param_3 + 6) = *(undefined1 *)(param_1 + 0x74ed);
          *(undefined1 *)((int)param_3 + 0x19) = *(undefined1 *)(param_1 + 0x74ee);
          *(undefined1 *)((int)param_3 + 0x1a) = *(undefined1 *)(param_1 + 0x74ef);
          *(undefined1 *)((int)param_3 + 0x1b) = *(undefined1 *)(param_1 + 0x74f0);
          *(undefined1 *)(param_3 + 7) = *(undefined1 *)(param_1 + 0x74f1);
          *(undefined1 *)((int)param_3 + 0x91) = *(undefined1 *)(param_1 + 0x74f2);
          *(undefined1 *)((int)param_3 + 0x9e) = *(undefined1 *)(param_1 + 0x343c);
          *(undefined1 *)((int)param_3 + 0xae) = *(undefined1 *)(param_1 + 0x343d);
          *(undefined1 *)((int)param_3 + 0x99) = *(undefined1 *)(param_1 + 0x318d);
          *(undefined1 *)((int)param_3 + 0xa2) = *(undefined1 *)(param_1 + 0x34d9);
          *(undefined1 *)(param_3 + 0x29) = *(undefined1 *)(param_1 + 0x34f0);
          *(undefined1 *)((int)param_3 + 0x93) = *(undefined1 *)(param_1 + 0x30ab);
          *(undefined1 *)((int)param_3 + 0x9d) = *(undefined1 *)(param_1 + 0x280d);
          *(undefined1 *)((int)param_3 + 0xa5) = *(undefined1 *)(param_1 + 0x280e);
          *(undefined1 *)((int)param_3 + 0x9f) = *(undefined1 *)(param_1 + 0x34dd);
          *(undefined1 *)(param_3 + 0x28) = *(undefined1 *)(param_1 + 0x34dc);
          *(undefined1 *)((int)param_3 + 0xa1) = *(undefined1 *)(param_1 + 0x34db);
          *(undefined1 *)((int)param_3 + 0xa6) = *(undefined1 *)(param_1 + 0x41f8);
          *(undefined1 *)((int)param_3 + 0xaf) = *(undefined1 *)(param_1 + 0x41f9);
          *(undefined1 *)((int)param_3 + 0xa7) = *(undefined1 *)(param_1 + 0x50b5);
          *(undefined1 *)((int)param_3 + 0xad) = *(undefined1 *)(param_1 + 0x280c);
          *(undefined1 *)(param_3 + 0x2a) = *(undefined1 *)(param_1 + 0x41f0);
          *(undefined1 *)((int)param_3 + 0xa9) = *(undefined1 *)(param_1 + 0x41f1);
          *(undefined1 *)((int)param_3 + 0xaa) = *(undefined1 *)(param_1 + 0x41f2);
          *(undefined1 *)((int)param_3 + 0xab) = *(undefined1 *)(param_1 + 0x41f3);
          *(undefined1 *)(param_3 + 0x2b) = *(undefined1 *)(param_1 + 0x4661);
          do {
            uVar4 = *puVar10;
            puVar10 = puVar10 + 0x1f;
            *puVar15 = uVar4;
            puVar15 = puVar15 + 1;
            iVar14 = iVar14 + -1;
          } while (iVar14 != 0);
          puVar16 = (undefined1 *)(param_1 + 0x3d7b);
          iVar14 = 8;
          puVar9 = (undefined1 *)((int)param_3 + 0x6f);
          do {
            puVar9[-3] = puVar16[-3];
            puVar9[-2] = puVar16[-2];
            puVar9[-1] = puVar16[-1];
            uVar2 = *puVar16;
            puVar16 = puVar16 + 0x94;
            *puVar9 = uVar2;
            puVar9 = puVar9 + 4;
            iVar14 = iVar14 + -1;
          } while (iVar14 != 0);
          iVar14 = 1;
          puVar10 = param_3 + 0x23;
          param_3[0x1a] = *(uint *)(param_1 + 0x3520);
          param_3[0x19] = *(uint *)(param_1 + 0x4188);
          puVar9 = (undefined1 *)(param_1 + 0x4664);
          param_3[0x18] = *(uint *)(param_1 + 0x30a0);
          do {
            iVar14 = iVar14 + -1;
            uVar2 = *puVar9;
            puVar9 = puVar9 + 8;
            *(undefined1 *)puVar10 = uVar2;
            puVar10 = (uint *)((int)puVar10 + 1);
          } while (-1 < iVar14);
          *(undefined1 *)(param_3 + 0x2c) = *(undefined1 *)(param_1 + 0x4fea);
          *(undefined1 *)((int)param_3 + 0xb1) = *(undefined1 *)(param_1 + 0x312a);
          *(undefined1 *)((int)param_3 + 0xb2) = *(undefined1 *)(param_1 + 0x3129);
          return param_1;
        }
        if (param_2 != 0x4000) {
          return param_1;
        }
        puVar10 = param_3 + 9;
        iVar14 = 4;
        puVar7 = (ushort *)(param_1 + 0x311a);
        do {
          uVar3 = *puVar7;
          puVar7 = puVar7 + 1;
          *puVar10 = (uint)uVar3;
          puVar10 = puVar10 + 1;
          iVar14 = iVar14 + -1;
        } while (iVar14 != 0);
        *(undefined1 *)(param_3 + 0x14) = *(undefined1 *)(param_1 + 0x30c6);
        *param_3 = (uint)*(ushort *)(param_1 + 0x30c4);
        param_3[1] = *(uint *)(param_1 + 0x30c0);
        *(undefined1 *)((int)param_3 + 0x51) = *(undefined1 *)(param_1 + 0x30e4);
        param_3[2] = (uint)*(ushort *)(param_1 + 0x30ca);
        param_3[3] = (uint)*(ushort *)(param_1 + 0x30c8);
        param_3[4] = (uint)*(ushort *)(param_1 + 0x30e0);
        param_3[5] = *(uint *)(param_1 + 0x30d0);
        param_3[6] = *(uint *)(param_1 + 0x30d4);
        param_3[7] = *(uint *)(param_1 + 0x30d8);
        param_3[8] = *(uint *)(param_1 + 0x30dc);
        *(undefined1 *)((int)param_3 + 0x52) = *(undefined1 *)(param_1 + 0x313c);
        *(undefined1 *)((int)param_3 + 0x53) = *(undefined1 *)(param_1 + 0x3193);
        *(undefined1 *)(param_3 + 0x15) = *(undefined1 *)(param_1 + 0x3192);
        param_3[0xd] = (uint)*(ushort *)(param_1 + 0x3190);
        param_3[0xe] = *(uint *)(param_1 + 0x3100);
        param_3[0xf] = *(uint *)(param_1 + 0x3104);
        param_3[0x10] = *(uint *)(param_1 + 0x3108);
        param_3[0x11] = *(uint *)(param_1 + 0x310c);
        param_3[0x12] = (uint)GH_F2U((float)((double)*(float *)(param_1 + 0x3110) * DOUBLE_00108d98));
        *(undefined1 *)((int)param_3 + 0x55) = *(undefined1 *)(param_1 + 0x31a0);
        *(undefined1 *)((int)param_3 + 0x56) = *(undefined1 *)(param_1 + 0x31a1);
        *(undefined1 *)((int)param_3 + 0x57) = *(undefined1 *)(param_1 + 0x31a2);
        *(undefined1 *)(param_3 + 0x16) = *(undefined1 *)(param_1 + 0x31a3);
        param_3[0x13] = *(uint *)(param_1 + 0x3194);
        return param_1;
      }
      if (param_2 != 0x800) {
        return param_1;
      }
      *(undefined8 *)param_3 = *(undefined8 *)(param_1 + 0x1b90);
      *(undefined8 *)(param_3 + 2) = *(undefined8 *)(param_1 + 0x1b98);
      param_3[4] = *(uint *)(param_1 + 0x1ba0);
      param_3[5] = *(uint *)(param_1 + 0x1ba4);
      param_3[6] = *(uint *)(param_1 + 0x1ba8);
      uVar4 = *(uint *)(param_1 + 0x1bac);
    }
    param_3[7] = uVar4;
  }
  return param_1;
}

/* _gleLightMaterialRGBAChange_F_AD @ 0x4a7c0 (296 bytes) */
void _gleLightMaterialRGBAChange_F_AD(param_1, param_2)
  int param_1;
  undefined8 *param_2;
{
  byte bVar1;
  undefined8 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  
  puVar2 = (undefined8 *)_glePushMaterial(param_1,0);
  *puVar2 = *param_2;
  puVar2[1] = param_2[1];
  puVar2[2] = *param_2;
  uVar6 = param_2[1];
  *(ushort *)((int)puVar2 + 0x234) = *(ushort *)((int)puVar2 + 0x234) | 0xc0c;
  puVar2[3] = uVar6;
  iVar4 = *(int *)(param_1 + 0x5434);
  if (iVar4 == 0) {
    bVar1 = *(byte *)(*(int *)(param_1 + 0x5420) + 0x2c0);
  }
  else {
    bVar1 = *(byte *)(*(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x2f4);
  }
  iVar5 = (bVar1 >> 3 & 0x1c) + param_1;
  iVar3 = *(int *)(param_1 + 0x5424);
  *(uint *)(iVar5 + 0x324) = *(uint *)(iVar5 + 0x324) | 1 << (bVar1 & 0x1f);
  bVar1 = *(byte *)(iVar3 + 0x2c0);
  iVar5 = (bVar1 >> 3 & 0x1c) + param_1;
  *(uint *)(iVar5 + 0x348) = *(uint *)(iVar5 + 0x348) | 1 << (bVar1 & 0x1f);
  if (iVar4 == 0) {
    bVar1 = *(byte *)(*(int *)(param_1 + 0x5420) + 0x2c1);
  }
  else {
    bVar1 = *(byte *)(*(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x2f5);
  }
  iVar4 = (bVar1 >> 3 & 0x1c) + param_1;
  *(uint *)(iVar4 + 0x324) = *(uint *)(iVar4 + 0x324) | 1 << (bVar1 & 0x1f);
  bVar1 = *(byte *)(iVar3 + 0x2c1);
  iVar4 = (bVar1 >> 3 & 0x1c) + param_1;
  *(uint *)(iVar4 + 0x348) = *(uint *)(iVar4 + 0x348) | 1 << (bVar1 & 0x1f);
  return;
}

/* _gleLightMaterialRGBAChange_F_E @ 0x4a8e8 (184 bytes) */
void _gleLightMaterialRGBAChange_F_E(param_1, param_2)
  int param_1;
  undefined8 *param_2;
{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  
  iVar2 = _glePushMaterial(param_1,0);
  *(undefined8 *)(iVar2 + 0x30) = *param_2;
  uVar4 = param_2[1];
  *(ushort *)(iVar2 + 0x234) = *(ushort *)(iVar2 + 0x234) | 0x202;
  *(undefined8 *)(iVar2 + 0x38) = uVar4;
  if (*(int *)(param_1 + 0x5434) == 0) {
    bVar1 = *(byte *)(*(int *)(param_1 + 0x5420) + 0x2c3);
  }
  else {
    bVar1 = *(byte *)(*(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x2f7);
  }
  iVar3 = (bVar1 >> 3 & 0x1c) + param_1;
  iVar2 = *(int *)(param_1 + 0x5424);
  *(uint *)(iVar3 + 0x324) = *(uint *)(iVar3 + 0x324) | 1 << (bVar1 & 0x1f);
  bVar1 = *(byte *)(iVar2 + 0x2c3);
  iVar2 = (bVar1 >> 3 & 0x1c) + param_1;
  *(uint *)(iVar2 + 0x348) = *(uint *)(iVar2 + 0x348) | 1 << (bVar1 & 0x1f);
  return;
}

/* _gleLightMaterialRGBAChange_F_S @ 0x4a9a0 (184 bytes) */
void _gleLightMaterialRGBAChange_F_S(param_1, param_2)
  int param_1;
  undefined8 *param_2;
{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  
  iVar2 = _glePushMaterial(param_1,0);
  *(undefined8 *)(iVar2 + 0x20) = *param_2;
  uVar4 = param_2[1];
  *(ushort *)(iVar2 + 0x234) = *(ushort *)(iVar2 + 0x234) | 0x1010;
  *(undefined8 *)(iVar2 + 0x28) = uVar4;
  if (*(int *)(param_1 + 0x5434) == 0) {
    bVar1 = *(byte *)(*(int *)(param_1 + 0x5420) + 0x2c2);
  }
  else {
    bVar1 = *(byte *)(*(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x2f6);
  }
  iVar3 = (bVar1 >> 3 & 0x1c) + param_1;
  iVar2 = *(int *)(param_1 + 0x5424);
  *(uint *)(iVar3 + 0x324) = *(uint *)(iVar3 + 0x324) | 1 << (bVar1 & 0x1f);
  bVar1 = *(byte *)(iVar2 + 0x2c2);
  iVar2 = (bVar1 >> 3 & 0x1c) + param_1;
  *(uint *)(iVar2 + 0x348) = *(uint *)(iVar2 + 0x348) | 1 << (bVar1 & 0x1f);
  return;
}

/* _glMaterialf_Exec @ 0x4aa58 (312 bytes) */
void _glMaterialf_Exec(int param_1,uint param_2,int param_3,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  undefined4 uVar1;
  
  if (((*(char *)(param_1 + 0x7580) != '\0') && (-1 < *(short *)(param_1 + 0x4a10))) &&
     (*(char *)(param_1 + 0x4664) == '\0')) {
    ((undefined4 (*)())_gleForceToSoftwareTCL)(param_1,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
  }
  if (param_3 == 0x1601) {
    if ((fparam_1 < (double)FLOAT_00108e50) ||
       ((double)(float)((double)CONCAT44(0x43300000,
                                         *(uint *)(*(int *)(param_1 + 0x468c) + 0xa0) ^ 0x80000000)
                       - DOUBLE_00108d58) < fparam_1)) {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar1 = 0x501;
      goto LAB_0004ab74;
    }
    if (param_2 == 0x405) {
      ((void (*)())_gleLightMaterialShineChange_B)(param_1,fparam_1);
      return;
    }
    if (param_2 < 0x406) {
      if (param_2 == 0x404) {
        ((void (*)())_gleLightMaterialShineChange_F)(param_1,fparam_1);
        return;
      }
    }
    else if (param_2 == 0x408) {
      ((void (*)())_gleLightMaterialShineChange_FB)(param_1,fparam_1);
      return;
    }
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar1 = 0x500;
LAB_0004ab74:
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _gleLightMaterialShineChange_F @ 0x4ab90 (180 bytes) */
void _gleLightMaterialShineChange_F(int param_1,float fparam_1)
{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = _glePushMaterial(param_1,0);
  *(float *)(iVar2 + 0x40) = (float)fparam_1;
  *(ushort *)(iVar2 + 0x234) = *(ushort *)(iVar2 + 0x234) | 0x101;
  if (*(int *)(param_1 + 0x5434) == 0) {
    bVar1 = *(byte *)(*(int *)(param_1 + 0x5420) + 0x2c4);
  }
  else {
    bVar1 = *(byte *)(*(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x2f8);
  }
  iVar3 = (bVar1 >> 3 & 0x1c) + param_1;
  iVar2 = *(int *)(param_1 + 0x5424);
  *(uint *)(iVar3 + 0x324) = *(uint *)(iVar3 + 0x324) | 1 << (bVar1 & 0x1f);
  bVar1 = *(byte *)(iVar2 + 0x2c4);
  iVar2 = (bVar1 >> 3 & 0x1c) + param_1;
  *(uint *)(iVar2 + 0x348) = *(uint *)(iVar2 + 0x348) | 1 << (bVar1 & 0x1f);
  return;
}

/* _glPopAttrib_Exec @ 0x4ac44 (188 bytes) */
void _glPopAttrib_Exec(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (0 < *(int *)(param_1 + 0x50fc)) {
      iVar2 = *(int *)(param_1 + 0x50f8);
      *(int *)(param_1 + 0x50fc) = *(int *)(param_1 + 0x50fc) + -1;
      *(int *)(param_1 + 0x50f8) = iVar2 + -4;
      iVar2 = *(int *)(iVar2 + -4);
      while (iVar2 != 0) {
        iVar3 = *(int *)(iVar2 + 0x2c44);
        ((void (*)())_gleRemoveAttribElem)(param_1,iVar2);
        iVar2 = iVar3;
      }
      _gleUpdateState(param_1);
      return;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x504;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _gleRemoveAttribElem @ 0x4ad00 (56 bytes) */
void _gleRemoveAttribElem(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((int (*)())_gleSetAttrib)(param_1,*param_2,param_2 + 1);
  _free(param_2);
  return;
}

/* _gleSetAttrib @ 0x4ad38 (6520 bytes) */
int _gleSetAttrib(param_1, param_2, param_3)
  int param_1;
  undefined *param_2;
  float *param_3;
{
  float *pfVar1;
  undefined2 uVar2;
  undefined *puVar3;
  uint uVar4;
  char cVar5;
  undefined1 uVar6;
  int iVar7;
  int iVar8;
  float fVar9;
  float fVar10;
  byte bVar13;
  float *pfVar11;
  undefined2 *puVar12;
  undefined1 *puVar14;
  undefined4 uVar15;
  int iVar16;
  undefined2 *puVar17;
  int iVar18;
  int *piVar19;
  float *pfVar20;
  undefined1 *puVar21;
  int iVar22;
  int iVar23;
  int iVar24;
  undefined4 *puVar25;
  int iVar26;
  int iVar27;
  int iVar28;
  
  if (param_2 == (undefined *)0x400) {
    pfVar20 = (float *)(param_1 + 0x3198);
    iVar16 = param_1 + 0x34f0;
    pfVar11 = param_3;
    do {
      *(undefined2 *)(iVar16 + 0x10) = *(undefined2 *)((int)pfVar11 + 10);
      *(float *)(iVar16 + 8) = pfVar11[1];
      *(float *)(iVar16 + 0xc) = *pfVar11;
      *(undefined2 *)(iVar16 + 0x12) = *(undefined2 *)((int)pfVar11 + 0xe);
      *(undefined2 *)(iVar16 + 0x14) = *(undefined2 *)((int)pfVar11 + 0x12);
      *(undefined2 *)(iVar16 + 0x16) = *(undefined2 *)((int)pfVar11 + 0x16);
      iVar16 = iVar16 + 0x10;
      pfVar1 = pfVar11 + 6;
      pfVar11 = pfVar11 + 7;
      *pfVar20 = *pfVar1;
      pfVar20 = pfVar20 + 1;
    } while ((int)pfVar11 <= (int)(param_3 + 7));
    *(undefined2 *)(param_1 + 0x3518) = *(undefined2 *)((int)param_3 + 0x3a);
    *(undefined2 *)(param_1 + 0x351a) = *(undefined2 *)((int)param_3 + 0x3e);
    *(undefined2 *)(param_1 + 0x351c) = *(undefined2 *)((int)param_3 + 0x42);
    *(undefined2 *)(param_1 + 0x351e) = *(undefined2 *)((int)param_3 + 0x46);
    *(float *)(param_1 + 0x3520) = param_3[0x13];
    *(float *)(param_1 + 0x3114) = param_3[0x12];
    *(undefined1 *)(param_1 + 0x7583) = *(undefined1 *)((int)param_3 + 0x53);
    return param_1;
  }
  if (param_2 < (undefined *)0x401) {
    if (param_2 == (undefined *)0x10) {
      puVar14 = (undefined1 *)(param_1 + 0x3448);
      iVar16 = 0x80;
      do {
        uVar6 = *(undefined1 *)param_3;
        param_3 = (float *)((int)param_3 + 1);
        *puVar14 = uVar6;
        puVar14 = puVar14 + 1;
        iVar16 = iVar16 + -1;
      } while (iVar16 != 0);
      return (int)puVar14;
    }
    if (param_2 < (undefined *)0x11) {
      if (param_2 == (undefined *)0x2) {
        *(undefined1 *)(param_1 + 0x343c) = *(undefined1 *)(param_3 + 10);
        *(float *)(param_1 + 0x341c) = *param_3;
        *(float *)(param_1 + 0x3420) = param_3[1];
        *(float *)(param_1 + 0x3424) = param_3[2];
        *(float *)(param_1 + 0x3428) = param_3[3];
        *(float *)(param_1 + 0x342c) = param_3[4];
        *(float *)(param_1 + 0x3430) = param_3[5];
        *(float *)(param_1 + 0x3434) = param_3[6];
        *(undefined2 *)(param_1 + 0x3440) = *(undefined2 *)((int)param_3 + 0x1e);
        *(float *)(param_1 + 0x3444) = param_3[9];
        *(undefined2 *)(param_1 + 0x3442) = *(undefined2 *)((int)param_3 + 0x22);
        return param_1;
      }
      if (param_2 < (undefined *)0x3) {
        if (param_2 != (undefined *)0x1) {
          return param_1;
        }
        iVar7 = *(int *)(param_1 + 0x4854);
        iVar26 = 0x10;
        *(float *)(param_1 + 0x2a0) = param_3[100];
        iVar8 = iVar7 + -0x200;
        *(float *)(param_1 + 0x2a4) = param_3[0x65];
        *(float *)(param_1 + 0x2a8) = param_3[0x66];
        *(float *)(param_1 + 0x2ac) = param_3[0x67];
        iVar16 = param_1;
        pfVar11 = param_3;
        do {
          *(float *)(iVar16 + 0x1a0) = pfVar11[0x20];
          *(float *)(iVar16 + 0x1a4) = pfVar11[0x21];
          *(float *)(iVar16 + 0x1a8) = pfVar11[0x22];
          pfVar20 = pfVar11 + 0x23;
          pfVar11 = pfVar11 + 4;
          *(float *)(iVar16 + 0x1ac) = *pfVar20;
          iVar16 = iVar16 + 0x10;
          iVar26 = iVar26 + -1;
        } while (iVar26 != 0);
        pfVar20 = (float *)(param_1 + 0x2d0);
        iVar16 = 4;
        pfVar11 = param_3 + 0x60;
        do {
          fVar9 = *pfVar11;
          pfVar11 = pfVar11 + 1;
          *pfVar20 = fVar9;
          pfVar20 = pfVar20 + 1;
          iVar16 = iVar16 + -1;
        } while (iVar16 != 0);
        iVar26 = 8;
        *(float *)(param_1 + 0x2b0) = param_3[0x68];
        *(float *)(param_1 + 0x2b4) = param_3[0x69];
        *(float *)(param_1 + 0x2b8) = param_3[0x6a];
        *(float *)(param_1 + 700) = param_3[0x6b];
        *(undefined8 *)(param_1 + 0x2c0) = *(undefined8 *)(param_3 + 0x6c);
        *(float *)(param_1 + 0x2c8) = param_3[0x6e];
        *(float *)(param_1 + 0x2cc) = param_3[0x6f];
        pfVar11 = param_3;
        iVar16 = param_1;
        do {
          *(float *)(iVar16 + 0x120) = *pfVar11;
          *(float *)(iVar16 + 0x124) = pfVar11[1];
          *(float *)(iVar16 + 0x128) = pfVar11[2];
          *(float *)(iVar16 + 300) = pfVar11[3];
          iVar16 = iVar16 + 0x10;
          *(float *)(iVar8 + 0x80) = pfVar11[0x80];
          *(float *)(iVar8 + 0x84) = pfVar11[0x81];
          *(float *)(iVar8 + 0x88) = pfVar11[0x82];
          pfVar20 = pfVar11 + 0x83;
          pfVar11 = pfVar11 + 4;
          *(float *)(iVar8 + 0x8c) = *pfVar20;
          iVar8 = iVar8 + 0x10;
          iVar26 = iVar26 + -1;
        } while (iVar26 != 0);
        *(float *)(param_1 + 0x2e0) = param_3[0x70];
        *(float *)(param_1 + 0x2e4) = param_3[0x71];
        *(float *)(param_1 + 0x2e8) = param_3[0x72];
        *(float *)(iVar7 + -500) = param_3[0x73];
        *(float *)(iVar7 + -0x1e0) = param_3[0x74];
        *(float *)(iVar7 + -0x1dc) = param_3[0x75];
        *(float *)(iVar7 + -0x1d8) = param_3[0x76];
        *(float *)(iVar7 + -0x1d4) = param_3[0x77];
        *(float *)(iVar7 + -0x1f0) = param_3[0x78];
        *(float *)(iVar7 + -0x1ec) = param_3[0x79];
        *(float *)(iVar7 + -0x1e8) = param_3[0x7a];
        *(float *)(iVar7 + -0x1e4) = param_3[0x7b];
        *(float *)(iVar7 + -0x1c0) = param_3[0x7c];
        *(float *)(iVar7 + -0x1bc) = param_3[0x7d];
        *(float *)(iVar7 + -0x1b8) = param_3[0x7e];
        *(float *)(iVar7 + -0x1d0) = param_3[0xa0];
        *(float *)(iVar7 + -0x1cc) = param_3[0xa1];
        *(float *)(iVar7 + -0x1c8) = param_3[0xa2];
        *(float *)(iVar7 + -0x1c4) = param_3[0xa3];
        *(undefined1 *)(param_1 + 0x2ef) = *(undefined1 *)((int)param_3 + 0x291);
        *(undefined1 *)(param_1 + 0x2ec) = *(undefined1 *)(param_3 + 0xa4);
        return param_1;
      }
      if (param_2 == (undefined *)0x4) {
        *(undefined1 *)(param_1 + 0x318d) = *(undefined1 *)((int)param_3 + 10);
        *(undefined1 *)(param_1 + 0x318c) = *(undefined1 *)((int)param_3 + 0xb);
        *(undefined2 *)(param_1 + 0x3188) = *(undefined2 *)(param_3 + 2);
        *(float *)(param_1 + 0x3184) = *param_3;
        *(float *)(param_1 + 0x3180) = param_3[1];
        return param_1;
      }
      if (param_2 != (undefined *)0x8) {
        return param_1;
      }
      *(undefined1 *)(param_1 + 0x34da) = *(undefined1 *)(param_3 + 6);
      *(undefined2 *)(param_1 + 0x34d6) = *(undefined2 *)((int)param_3 + 2);
      *(undefined2 *)(param_1 + 0x34d4) = *(undefined2 *)((int)param_3 + 6);
      *(undefined2 *)(param_1 + 0x34d0) = *(undefined2 *)((int)param_3 + 10);
      *(undefined2 *)(param_1 + 0x34d2) = *(undefined2 *)((int)param_3 + 0xe);
      *(undefined1 *)(param_1 + 0x34d9) = *(undefined1 *)((int)param_3 + 0x19);
      *(undefined1 *)(param_1 + 0x34d8) = *(undefined1 *)((int)param_3 + 0x1a);
      *(undefined1 *)(param_1 + 0x34dd) = *(undefined1 *)((int)param_3 + 0x1b);
      *(undefined1 *)(param_1 + 0x34dc) = *(undefined1 *)(param_3 + 7);
      *(undefined1 *)(param_1 + 0x34db) = *(undefined1 *)((int)param_3 + 0x1d);
      *(float *)(param_1 + 0x34c8) = param_3[4];
      *(float *)(param_1 + 0x34cc) = param_3[5];
      return param_1;
    }
    if (param_2 == (undefined *)0x80) {
      *(undefined1 *)(param_1 + 0x316a) = *(undefined1 *)(param_3 + 9);
      *(float *)(param_1 + 0x3140) = *param_3;
      *(float *)(param_1 + 0x3144) = param_3[1];
      *(float *)(param_1 + 0x3148) = param_3[2];
      *(float *)(param_1 + 0x314c) = param_3[3];
      *(float *)(param_1 + 0x3150) = param_3[5];
      *(float *)(param_1 + 0x3154) = param_3[6];
      *(float *)(param_1 + 0x3158) = param_3[7];
      *(float *)(param_1 + 0x3160) = param_3[4];
      *(undefined2 *)(param_1 + 0x3164) = *(undefined2 *)((int)param_3 + 0x22);
      *(undefined1 *)(param_1 + 0x4fea) = *(undefined1 *)((int)param_3 + 0x25);
      return param_1;
    }
    if (param_2 < (undefined *)0x81) {
      if (param_2 == (undefined *)0x20) {
        *(undefined2 *)(param_1 + 0x3118) = *(undefined2 *)((int)param_3 + 10);
        *(float *)(param_1 + 0x31a8) = *param_3;
        *(float *)(param_1 + 0x31ac) = param_3[1];
        *(float *)(param_1 + 0x31e8) = param_3[3];
        *(float *)(param_1 + 0x31ec) = param_3[4];
        *(float *)(param_1 + 0x31f0) = param_3[5];
        *(float *)(param_1 + 0x31f4) = param_3[6];
        *(float *)(param_1 + 0x31f8) = param_3[7];
        *(float *)(param_1 + 0x31fc) = param_3[8];
        *(float *)(param_1 + 0x3200) = param_3[9];
        *(float *)(param_1 + 0x3204) = param_3[10];
        *(float *)(param_1 + 0x3208) = param_3[0xb];
        *(float *)(param_1 + 0x320c) = param_3[0xc];
        *(float *)(param_1 + 0x3210) = param_3[0xd];
        *(float *)(param_1 + 0x3214) = param_3[0xe];
        _gleCopyPixelMapi(param_3 + 0xf,param_1 + 0x3248,param_3[0xa0f],param_1 + 0x3270);
        _gleCopyPixelMapi(param_3 + 0x90f,param_1 + 0x326c,param_3[0xa10],param_1 + 0x3274);
        _gleCopyPixelMapf(param_3 + 0x10f,param_1 + 0x324c,param_3[0xa11],param_1 + 0x3278);
        _gleCopyPixelMapf(param_3 + 0x20f,param_1 + 0x3250,param_3[0xa12],param_1 + 0x327c);
        _gleCopyPixelMapf(param_3 + 0x30f,param_1 + 0x3254,param_3[0xa13],param_1 + 0x3280);
        _gleCopyPixelMapf(param_3 + 0x40f,param_1 + 0x3258,param_3[0xa14],param_1 + 0x3284);
        _gleCopyPixelMapf(param_3 + 0x50f,param_1 + 0x325c,param_3[0xa15],param_1 + 0x3288);
        _gleCopyPixelMapf(param_3 + 0x60f,param_1 + 0x3260,param_3[0xa16],param_1 + 0x328c);
        _gleCopyPixelMapf(param_3 + 0x70f,param_1 + 0x3264,param_3[0xa17],param_1 + 0x3290);
        uVar15 = _gleCopyPixelMapf(param_3 + 0x80f,param_1 + 0x3268,param_3[0xa18],param_1 + 0x3294)
        ;
        if (*param_3 == FLOAT_00108e54) {
          uVar4 = *(uint *)(param_1 + 0x3414) & 0xffffbfff;
        }
        else {
          uVar4 = *(uint *)(param_1 + 0x3414) | 0x4000;
        }
        *(uint *)(param_1 + 0x3414) = uVar4;
        if (param_3[1] == FLOAT_00108e54) {
          uVar4 = *(uint *)(param_1 + 0x3414) & 0xffff7fff;
        }
        else {
          uVar4 = *(uint *)(param_1 + 0x3414) | 0x8000;
        }
        *(uint *)(param_1 + 0x3414) = uVar4;
        if (*(char *)(param_3 + 0xa19) == '\0') {
          uVar4 = *(uint *)(param_1 + 0x3414) & 0xfffffffe;
        }
        else {
          uVar4 = *(uint *)(param_1 + 0x3414) | 1;
        }
        *(uint *)(param_1 + 0x3414) = uVar4;
        if (*(char *)((int)param_3 + 0x2865) == '\0') {
          uVar4 = *(uint *)(param_1 + 0x3414) & 0xfffffffd;
        }
        else {
          uVar4 = *(uint *)(param_1 + 0x3414) | 2;
        }
        *(uint *)(param_1 + 0x3414) = uVar4;
        return uVar15;
      }
      if (param_2 != (undefined *)0x40) {
        return param_1;
      }
      *(undefined1 *)(param_1 + 0x30ab) = *(undefined1 *)(param_3 + 8);
      *(undefined2 *)(param_1 + 0x30a4) = *(undefined2 *)((int)param_3 + 6);
      *(undefined2 *)(param_1 + 0x30a6) = *(undefined2 *)((int)param_3 + 10);
      *(float *)(param_1 + 0x2810) = param_3[3];
      *(float *)(param_1 + 0x2814) = param_3[4];
      *(float *)(param_1 + 0x2818) = param_3[5];
      *(float *)(param_1 + 0x281c) = param_3[6];
      *(undefined1 *)(param_1 + 0x30ad) = *(undefined1 *)((int)param_3 + 0x21);
      *(undefined1 *)(param_1 + 0x30ac) = *(undefined1 *)((int)param_3 + 0x22);
      *(undefined1 *)(param_1 + 0x30ae) = *(undefined1 *)((int)param_3 + 0x23);
      *(undefined1 *)(param_1 + 0x30aa) = *(undefined1 *)(param_3 + 9);
      *(float *)(param_1 + 0x30a0) = param_3[10];
      fVar9 = param_3[7];
      if (8 < (int)GH_F2U(fVar9)) {
        fVar9 = 1.12104e-44;
      }
      iVar16 = param_1;
      pfVar11 = param_3;
      if (0 < (int)GH_F2U(fVar9)) {
        do {
          *(float *)(iVar16 + 0x2850) = pfVar11[0x17];
          *(float *)(iVar16 + 0x2854) = pfVar11[0x18];
          *(float *)(iVar16 + 0x2858) = pfVar11[0x19];
          *(float *)(iVar16 + 0x285c) = pfVar11[0x1a];
          *(float *)(iVar16 + 0x2820) = pfVar11[0xb];
          *(float *)(iVar16 + 0x2824) = pfVar11[0xc];
          *(float *)(iVar16 + 0x2828) = pfVar11[0xd];
          *(float *)(iVar16 + 0x282c) = pfVar11[0xe];
          *(float *)(iVar16 + 0x2830) = pfVar11[0xf];
          *(float *)(iVar16 + 0x2834) = pfVar11[0x10];
          *(float *)(iVar16 + 0x2838) = pfVar11[0x11];
          *(float *)(iVar16 + 0x283c) = pfVar11[0x12];
          *(float *)(iVar16 + 0x2840) = pfVar11[0x13];
          *(float *)(iVar16 + 0x2844) = pfVar11[0x14];
          *(float *)(iVar16 + 0x2848) = pfVar11[0x15];
          *(float *)(iVar16 + 0x284c) = pfVar11[0x16];
          *(float *)(iVar16 + 0x2860) = pfVar11[0x1b];
          *(float *)(iVar16 + 0x2864) = pfVar11[0x1c];
          *(float *)(iVar16 + 0x2868) = pfVar11[0x1d];
          *(float *)(iVar16 + 0x287c) = pfVar11[0x1e];
          *(float *)(iVar16 + 0x2890) = pfVar11[0x1f];
          *(float *)(iVar16 + 0x286c) = pfVar11[0x20];
          *(float *)(iVar16 + 0x2870) = pfVar11[0x21];
          *(float *)(iVar16 + 0x2874) = pfVar11[0x22];
          *(float *)(iVar16 + 0x2878) = pfVar11[0x23];
          fVar9 = GH_U2F((unsigned int)(((int)GH_F2U(fVar9) + -1)));
          iVar16 = iVar16 + 0x80;
          pfVar11 = pfVar11 + 0x19;
        } while (fVar9 != 0.0);
      }
      iVar16 = param_1;
      iVar7 = param_1;
      pfVar11 = param_3;
      do {
        **(float **)(iVar7 + 0x4dd0) = pfVar11[0x19b];
        *(float *)(*(int *)(iVar7 + 0x4dd0) + 4) = pfVar11[0x19c];
        *(float *)(*(int *)(iVar7 + 0x4dd0) + 8) = pfVar11[0x19d];
        *(float *)(*(int *)(iVar7 + 0x4dd0) + 0xc) = pfVar11[0x19e];
        *(float *)(*(int *)(iVar7 + 0x4dd0) + 0x10) = pfVar11[0x19f];
        *(float *)(*(int *)(iVar7 + 0x4dd0) + 0x14) = pfVar11[0x1a0];
        *(float *)(*(int *)(iVar7 + 0x4dd0) + 0x18) = pfVar11[0x1a1];
        *(float *)(*(int *)(iVar7 + 0x4dd0) + 0x1c) = pfVar11[0x1a2];
        *(float *)(*(int *)(iVar7 + 0x4dd0) + 0x20) = pfVar11[0x1a3];
        *(float *)(*(int *)(iVar7 + 0x4dd0) + 0x24) = pfVar11[0x1a4];
        *(float *)(*(int *)(iVar7 + 0x4dd0) + 0x28) = pfVar11[0x1a5];
        *(float *)(*(int *)(iVar7 + 0x4dd0) + 0x2c) = pfVar11[0x1a6];
        *(float *)(*(int *)(iVar7 + 0x4dd0) + 0x30) = pfVar11[0x1a7];
        *(float *)(*(int *)(iVar7 + 0x4dd0) + 0x34) = pfVar11[0x1a8];
        *(float *)(*(int *)(iVar7 + 0x4dd0) + 0x38) = pfVar11[0x1a9];
        *(float *)(*(int *)(iVar7 + 0x4dd0) + 0x3c) = pfVar11[0x1aa];
        piVar19 = (int *)(iVar7 + 0x4dd0);
        iVar7 = iVar7 + 4;
        *(float *)(*piVar19 + 0x40) = pfVar11[0x1ae];
        *(float *)(iVar16 + 0x2f0) = pfVar11[0x1ab];
        *(float *)(iVar16 + 0x2f4) = pfVar11[0x1ac];
        pfVar20 = pfVar11 + 0x1ad;
        pfVar11 = pfVar11 + 0x14;
        *(float *)(iVar16 + 0x2f8) = *pfVar20;
        iVar16 = iVar16 + 0x10;
      } while (iVar16 <= param_1 + 0x10);
      *(float *)(param_1 + 0x34f4) = *param_3;
      return param_1;
    }
    if (param_2 != (undefined *)0x100) {
      if (param_2 != (undefined *)0x200) {
        return param_1;
      }
      *(float *)(param_1 + 0x30f0) = *param_3;
      *(float *)(param_1 + 0x30f4) = param_3[1];
      *(float *)(param_1 + 0x30f8) = param_3[2];
      *(float *)(param_1 + 0x30fc) = param_3[3];
      return param_1;
    }
    *(undefined1 *)(param_1 + 0x3128) = *(undefined1 *)(param_3 + 3);
    *(undefined2 *)(param_1 + 0x3124) = *(undefined2 *)((int)param_3 + 2);
    *(undefined8 *)(param_1 + 0x30e8) = *(undefined8 *)(param_3 + 1);
    *(undefined1 *)(param_1 + 0x31a4) = *(undefined1 *)((int)param_3 + 0xd);
    *(undefined1 *)(param_1 + 0x312a) = *(undefined1 *)((int)param_3 + 0xf);
    *(undefined8 *)(param_1 + 0x312c) = *(undefined8 *)(param_3 + 4);
    *(undefined8 *)(param_1 + 0x3134) = *(undefined8 *)(param_3 + 6);
    uVar6 = *(undefined1 *)((int)param_3 + 0xe);
  }
  else {
    if (param_2 == (undefined *)0x8000) {
      *(undefined2 *)(param_1 + 0x316c) = *(undefined2 *)((int)param_3 + 2);
      *(undefined2 *)(param_1 + 0x316e) = *(undefined2 *)((int)param_3 + 6);
      *(undefined2 *)(param_1 + 0x3170) = *(undefined2 *)((int)param_3 + 10);
      *(undefined2 *)(param_1 + 0x3172) = *(undefined2 *)((int)param_3 + 0xe);
      *(undefined2 *)(param_1 + 0x3174) = *(undefined2 *)((int)param_3 + 0x12);
      *(float *)(param_1 + 0x507c) = param_3[5];
      *(float *)(param_1 + 0x5080) = param_3[6];
      *(undefined2 *)(param_1 + 0x3176) = *(undefined2 *)((int)param_3 + 0x1e);
      return param_1;
    }
    if ((undefined *)0x8000 < param_2) {
      if (param_2 == (undefined *)0x40000) {
        iVar7 = 8;
        iVar16 = param_1;
        pfVar11 = param_3;
        do {
          *(float *)(iVar16 + 0x3cfc) = pfVar11[1];
          *(float *)(iVar16 + 0x3d00) = pfVar11[2];
          *(float *)(iVar16 + 0x3d04) = pfVar11[3];
          *(float *)(iVar16 + 0x3d08) = pfVar11[4];
          *(float *)(iVar16 + 0x3cec) = pfVar11[5];
          *(float *)(iVar16 + 0x3cf0) = pfVar11[6];
          *(float *)(iVar16 + 0x3cf4) = pfVar11[7];
          *(float *)(iVar16 + 0x3cf8) = pfVar11[8];
          *(float *)(iVar16 + 0x3d20) = pfVar11[0xb];
          *(float *)(iVar16 + 0x3d24) = pfVar11[0xc];
          *(float *)(iVar16 + 0x3d28) = pfVar11[0xd];
          *(float *)(iVar16 + 0x3d2c) = pfVar11[0xe];
          *(float *)(iVar16 + 0x3d10) = pfVar11[0xf];
          *(float *)(iVar16 + 0x3d14) = pfVar11[0x10];
          *(float *)(iVar16 + 0x3d18) = pfVar11[0x11];
          *(float *)(iVar16 + 0x3d1c) = pfVar11[0x12];
          *(float *)(iVar16 + 0x3d44) = pfVar11[0x15];
          *(float *)(iVar16 + 0x3d48) = pfVar11[0x16];
          *(float *)(iVar16 + 0x3d4c) = pfVar11[0x17];
          *(float *)(iVar16 + 0x3d50) = pfVar11[0x18];
          *(float *)(iVar16 + 0x3d34) = pfVar11[0x19];
          *(float *)(iVar16 + 0x3d38) = pfVar11[0x1a];
          *(float *)(iVar16 + 0x3d3c) = pfVar11[0x1b];
          *(float *)(iVar16 + 0x3d40) = pfVar11[0x1c];
          *(float *)(iVar16 + 0x3d68) = pfVar11[0x1f];
          *(float *)(iVar16 + 0x3d6c) = pfVar11[0x20];
          *(float *)(iVar16 + 0x3d70) = pfVar11[0x21];
          *(float *)(iVar16 + 0x3d74) = pfVar11[0x22];
          *(float *)(iVar16 + 0x3d58) = pfVar11[0x23];
          *(float *)(iVar16 + 0x3d5c) = pfVar11[0x24];
          *(float *)(iVar16 + 0x3d60) = pfVar11[0x25];
          *(float *)(iVar16 + 0x3d64) = pfVar11[0x26];
          *(undefined1 *)(iVar16 + 0x3d78) = *(undefined1 *)(pfVar11 + 9);
          *(undefined1 *)(iVar16 + 0x3d79) = *(undefined1 *)(pfVar11 + 0x13);
          *(undefined1 *)(iVar16 + 0x3d7a) = *(undefined1 *)(pfVar11 + 0x1d);
          *(undefined1 *)(iVar16 + 0x3d7b) = *(undefined1 *)(pfVar11 + 0x27);
          *(undefined2 *)(iVar16 + 0x3ce8) = *(undefined2 *)((int)pfVar11 + 2);
          *(undefined2 *)(iVar16 + 0x3d0c) = *(undefined2 *)((int)pfVar11 + 0x2a);
          *(undefined2 *)(iVar16 + 0x3d30) = *(undefined2 *)((int)pfVar11 + 0x52);
          puVar12 = (undefined2 *)((int)pfVar11 + 0x7a);
          pfVar11 = pfVar11 + 0x28;
          *(undefined2 *)(iVar16 + 0x3d54) = *puVar12;
          iVar16 = iVar16 + 0x94;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
        iVar22 = 0;
        iVar26 = param_1 + 0x3530;
        iVar7 = 0;
        iVar8 = 0;
        iVar16 = param_1;
        do {
          *(undefined4 *)(iVar26 + 4) = *(undefined4 *)((int)param_3 + iVar8 + 0x710);
          if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
            _pthread_mutex_lock(*(int *)(param_1 + 0x5148) + 0x8028);
          }
          puVar25 = (undefined4 *)((int)param_3 + iVar8 + 0x524);
          iVar27 = 0;
          do {
            iVar23 = iVar27 + 1;
            _gleBindTexture(param_1,iVar27,*puVar25,iVar22);
            puVar25 = puVar25 + 0x16;
            iVar27 = iVar23;
          } while (iVar23 < 5);
          if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
            _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
          }
          iVar27 = 5;
          piVar19 = (int *)(param_1 + iVar7 * 4 + 0x5154);
          puVar14 = (undefined1 *)(iVar8 + (int)param_3);
          do {
            iVar23 = *piVar19;
            piVar19 = piVar19 + 1;
            *(undefined4 *)(iVar23 + 0x50) = *(undefined4 *)(puVar14 + 0x514);
            *(undefined4 *)(iVar23 + 0x54) = *(undefined4 *)(puVar14 + 0x518);
            *(undefined4 *)(iVar23 + 0x58) = *(undefined4 *)(puVar14 + 0x51c);
            *(undefined4 *)(iVar23 + 0x5c) = *(undefined4 *)(puVar14 + 0x520);
            *(undefined2 *)(iVar23 + 0x4a) = *(undefined2 *)(puVar14 + 0x502);
            *(undefined2 *)(iVar23 + 0x4c) = *(undefined2 *)(puVar14 + 0x506);
            *(undefined2 *)(iVar23 + 0x44) = *(undefined2 *)(puVar14 + 0x50a);
            *(undefined2 *)(iVar23 + 0x46) = *(undefined2 *)(puVar14 + 0x50e);
            *(undefined2 *)(iVar23 + 0x48) = *(undefined2 *)(puVar14 + 0x512);
            *(undefined4 *)(iVar23 + 0x38) = *(undefined4 *)(puVar14 + 0x528);
            *(undefined4 *)(iVar23 + 0x60) = *(undefined4 *)(puVar14 + 0x52c);
            *(undefined4 *)(iVar23 + 100) = *(undefined4 *)(puVar14 + 0x530);
            *(undefined4 *)(iVar23 + 0x68) = *(undefined4 *)(puVar14 + 0x534);
            *(undefined4 *)(iVar23 + 0x6c) = *(undefined4 *)(puVar14 + 0x538);
            *(undefined2 *)(iVar23 + 0x70) = *(undefined2 *)(puVar14 + 0x53e);
            *(undefined2 *)(iVar23 + 0x72) = *(undefined2 *)(puVar14 + 0x542);
            *(undefined2 *)(iVar23 + 0x76) = *(undefined2 *)(puVar14 + 0x546);
            *(undefined2 *)(iVar23 + 0x74) = *(undefined2 *)(puVar14 + 0x54a);
            *(undefined4 *)(iVar23 + 0x78) = *(undefined4 *)(puVar14 + 0x54c);
            puVar12 = (undefined2 *)(puVar14 + 0x552);
            puVar14 = puVar14 + 0x58;
            *(undefined2 *)(iVar23 + 0x7c) = *puVar12;
            iVar27 = iVar27 + -1;
          } while (iVar27 != 0);
          iVar27 = 0;
          puVar14 = (undefined1 *)(iVar8 + (int)param_3);
          do {
            iVar27 = iVar27 + -1;
            *(undefined4 *)(iVar16 + 0x3524) = *(undefined4 *)(puVar14 + 0x6b8);
            *(undefined4 *)(iVar16 + 0x3528) = *(undefined4 *)(puVar14 + 0x6bc);
            *(undefined4 *)(iVar16 + 0x352c) = *(undefined4 *)(puVar14 + 0x6c0);
            *(undefined4 *)(iVar16 + 0x3530) = *(undefined4 *)(puVar14 + 0x6c4);
            *(undefined2 *)(iVar26 + 8) = *(undefined2 *)(puVar14 + 0x6ca);
            *(undefined2 *)(iVar26 + 0xc) = *(undefined2 *)(puVar14 + 0x6ce);
            *(undefined2 *)(iVar26 + 0xe) = *(undefined2 *)(puVar14 + 0x6d2);
            *(undefined2 *)(iVar26 + 0x10) = *(undefined2 *)(puVar14 + 0x6d6);
            *(undefined2 *)(iVar26 + 0x12) = *(undefined2 *)(puVar14 + 0x6da);
            *(undefined2 *)(iVar16 + 0x3544) = *(undefined2 *)(puVar14 + 0x6de);
            *(undefined2 *)(iVar16 + 0x3546) = *(undefined2 *)(puVar14 + 0x6e2);
            *(undefined2 *)(iVar16 + 0x3548) = *(undefined2 *)(puVar14 + 0x6e6);
            *(undefined2 *)(iVar16 + 0x354a) = *(undefined2 *)(puVar14 + 0x6ea);
            *(undefined2 *)(iVar16 + 0x354c) = *(undefined2 *)(puVar14 + 0x6ee);
            *(undefined2 *)(iVar16 + 0x354e) = *(undefined2 *)(puVar14 + 0x6f2);
            *(undefined2 *)(iVar16 + 0x3550) = *(undefined2 *)(puVar14 + 0x6f6);
            *(undefined2 *)(iVar16 + 0x3552) = *(undefined2 *)(puVar14 + 0x6fa);
            *(undefined2 *)(iVar16 + 0x3554) = *(undefined2 *)(puVar14 + 0x6fe);
            *(undefined2 *)(iVar16 + 0x3556) = *(undefined2 *)(puVar14 + 0x702);
            *(undefined4 *)(iVar16 + 0x3558) = *(undefined4 *)(puVar14 + 0x704);
            *(undefined4 *)(iVar16 + 0x355c) = *(undefined4 *)(puVar14 + 0x708);
            puVar25 = (undefined4 *)(puVar14 + 0x70c);
            puVar14 = puVar14 + 0x58;
            *(undefined4 *)(iVar16 + 0x3560) = *puVar25;
          } while (-1 < iVar27);
          iVar22 = iVar22 + 1;
          iVar8 = iVar8 + 0x214;
          iVar7 = iVar7 + 5;
          iVar16 = iVar16 + 0x7c;
          iVar26 = iVar26 + 0x7c;
        } while (iVar22 < 0x10);
        pfVar11 = param_3 + 0x990;
        iVar16 = param_1 + 0x41f0;
        iVar7 = 1;
        *(float *)(param_1 + 0x41fc) = param_3[0x991];
        do {
          iVar7 = iVar7 + -1;
          *(float *)(iVar16 + 0x10) = pfVar11[2];
          *(float *)(iVar16 + 0x14) = pfVar11[3];
          *(float *)(iVar16 + 0x18) = pfVar11[4];
          pfVar20 = pfVar11 + 5;
          pfVar11 = pfVar11 + 4;
          *(float *)(iVar16 + 0x1c) = *pfVar20;
          iVar16 = iVar16 + 0x10;
        } while (-1 < iVar7);
        iVar8 = 0;
        iVar26 = 0;
        iVar16 = param_1;
        iVar7 = param_1;
        pfVar11 = param_3;
        do {
          iVar24 = 0;
          iVar22 = param_1 + iVar26 * 8;
          pfVar20 = pfVar11 + 0x9bc;
          iVar27 = iVar16 + 0x4270;
          iVar23 = iVar7 + 0x4230;
          puVar14 = (undefined1 *)(iVar8 + (int)param_3);
          do {
            puVar21 = puVar14 + 0x2660;
            iVar28 = 4;
            iVar18 = iVar22 + 0x4210;
            do {
              *(undefined2 *)(iVar18 + 0x10) = *(undefined2 *)(puVar21 + 10);
              *(undefined2 *)(iVar18 + 0x12) = *(undefined2 *)(puVar21 + 0xe);
              puVar12 = (undefined2 *)(puVar21 + 0x12);
              puVar21 = puVar21 + 0xc;
              *(undefined2 *)(iVar18 + 0x14) = *puVar12;
              iVar18 = iVar18 + 8;
              iVar28 = iVar28 + -1;
            } while (iVar28 != 0);
            iVar24 = iVar24 + 1;
            iVar22 = iVar22 + 0x30;
            *(undefined1 *)(iVar23 + 0x10) = puVar14[0x2698];
            *(undefined1 *)(iVar23 + 0x11) = puVar14[0x2699];
            *(undefined1 *)(iVar23 + 0x12) = puVar14[0x269a];
            *(undefined2 *)(iVar23 + 0x14) = *(undefined2 *)(puVar14 + 0x269e);
            *(undefined2 *)(iVar23 + 0x16) = *(undefined2 *)(puVar14 + 0x26a2);
            *(undefined2 *)(iVar23 + 0x18) = *(undefined2 *)(puVar14 + 0x26a6);
            *(undefined2 *)(iVar23 + 0x1a) = *(undefined2 *)(puVar14 + 0x26aa);
            puVar12 = (undefined2 *)(puVar14 + 0x26ae);
            puVar14 = puVar14 + 0x48;
            *(undefined2 *)(iVar23 + 0x1c) = *puVar12;
            iVar23 = iVar23 + 0x30;
            *(float *)(iVar27 + 0x10) = pfVar20[2];
            *(float *)(iVar27 + 0x14) = pfVar20[3];
            *(float *)(iVar27 + 0x18) = pfVar20[4];
            pfVar1 = pfVar20 + 5;
            pfVar20 = pfVar20 + 4;
            *(float *)(iVar27 + 0x1c) = *pfVar1;
            iVar27 = iVar27 + 0x10;
          } while (iVar24 < 2);
          iVar7 = iVar7 + 0x80;
          iVar26 = iVar26 + 0x10;
          iVar16 = iVar16 + 0x80;
          iVar8 = iVar8 + 0xb0;
          pfVar11 = pfVar11 + 0x2c;
        } while (iVar7 <= param_1 + 0x380);
        pfVar11 = param_3 + 0xaf8;
        iVar7 = param_1 + 0x4610;
        *(undefined1 *)(param_1 + 0x4620) = *(undefined1 *)(param_3 + 0xafa);
        iVar8 = 7;
        do {
          *(undefined2 *)(iVar7 + 0x14) = *(undefined2 *)((int)pfVar11 + 0xe);
          *(undefined2 *)(iVar7 + 0x16) = *(undefined2 *)((int)pfVar11 + 0x12);
          puVar12 = (undefined2 *)((int)pfVar11 + 0x16);
          pfVar11 = pfVar11 + 3;
          *(undefined2 *)(iVar7 + 0x18) = *puVar12;
          iVar7 = iVar7 + 8;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
        *(int *)(param_1 + 0x53d4) = (int)GH_F2U((float)(param_3[0x990])) + -0x84c0;
        return iVar16;
      }
      if ((undefined *)0x40000 < param_2) {
        if (param_2 == (undefined *)0x80000) {
          *(undefined1 *)(param_1 + 0x34f0) = *(undefined1 *)(param_3 + 4);
          *(float *)(param_1 + 0x34e0) = *param_3;
          *(float *)(param_1 + 0x34e4) = param_3[1];
          *(float *)(param_1 + 0x34e8) = param_3[2];
          *(float *)(param_1 + 0x34ec) = param_3[3];
          return param_1;
        }
        if (param_2 != (undefined *)0x20000000) {
          return param_1;
        }
        *(float *)(param_1 + 0x41ec) = *param_3;
        *(undefined1 *)(param_1 + 0x41f0) = *(undefined1 *)(param_3 + 1);
        *(undefined1 *)(param_1 + 0x41f1) = *(undefined1 *)((int)param_3 + 5);
        *(undefined1 *)(param_1 + 0x41f2) = *(undefined1 *)((int)param_3 + 6);
        *(undefined1 *)(param_1 + 0x41f3) = *(undefined1 *)((int)param_3 + 7);
        *(undefined1 *)(param_1 + 0x41f4) = *(undefined1 *)(param_3 + 2);
        return param_1;
      }
      if (param_2 == (undefined *)0x10000) {
        iVar16 = 0x10;
        uVar4 = 0;
        *(float *)(param_1 + 0x74a8) = *param_3;
        *(float *)(param_1 + 0x74ac) = param_3[1];
        *(float *)(param_1 + 0x74b0) = param_3[2];
        *(float *)(param_1 + 0x74b8) = param_3[7];
        *(float *)(param_1 + 0x74bc) = param_3[9];
        *(float *)(param_1 + 0x74c0) = param_3[10];
        *(float *)(param_1 + 0x74c8) = param_3[8];
        *(float *)(param_1 + 0x74cc) = param_3[0xb];
        *(float *)(param_1 + 0x74d0) = param_3[0xc];
        fVar9 = param_3[3];
        *(float *)(param_1 + 0x74d8) = fVar9;
        fVar10 = param_3[0xd];
        *(float *)(param_1 + 0x74dc) = fVar10;
        do {
          if (((uint)GH_F2U(fVar9) & 1 << (uVar4 & 0x3f)) == 0) {
            *(undefined1 *)(param_1 + uVar4 + 0x7524) = 0;
          }
          else {
            cVar5 = '\x04';
            if (*(int *)(param_1 + 0x7450) != 0) {
              cVar5 = (char)((unsigned char *)0x9da8)[uVar4 + *(int *)(param_1 + 0x7450)]<< 2
              ;
            }
            *(char *)(param_1 + uVar4 + 0x7524) = cVar5;
          }
          cVar5 = '\0';
          if (((uint)GH_F2U(fVar10) & 1 << (uVar4 & 0x3f)) != 0) {
            cVar5 = '\x04';
            if (*(int *)(param_1 + 0x7450) != 0) {
              cVar5 = *(char *)(uVar4 + *(int *)(param_1 + 0x7450) + 0x9db8) << 2;
            }
          }
          *(char *)(param_1 + uVar4 + 0x7564) = cVar5;
          uVar4 = uVar4 + 1;
          iVar16 = iVar16 + -1;
        } while (iVar16 != 0);
        uVar6 = 0xc;
        *(undefined1 *)(param_1 + 0x74e0) = *(undefined1 *)(param_3 + 4);
        *(undefined1 *)(param_1 + 0x74e1) = *(undefined1 *)((int)param_3 + 0x11);
        *(undefined1 *)(param_1 + 0x74e2) = *(undefined1 *)((int)param_3 + 0x12);
        *(undefined1 *)(param_1 + 0x74e3) = *(undefined1 *)((int)param_3 + 0x13);
        *(undefined1 *)(param_1 + 0x74e4) = *(undefined1 *)(param_3 + 5);
        *(undefined1 *)(param_1 + 0x74e5) = *(undefined1 *)((int)param_3 + 0x15);
        *(undefined1 *)(param_1 + 0x74e6) = *(undefined1 *)((int)param_3 + 0x16);
        *(undefined1 *)(param_1 + 0x74e7) = *(undefined1 *)((int)param_3 + 0x17);
        *(undefined1 *)(param_1 + 0x74e8) = *(undefined1 *)(param_3 + 6);
        *(undefined1 *)(param_1 + 0x74e9) = *(undefined1 *)(param_3 + 0xe);
        *(undefined1 *)(param_1 + 0x74ea) = *(undefined1 *)((int)param_3 + 0x39);
        *(undefined1 *)(param_1 + 0x74eb) = *(undefined1 *)((int)param_3 + 0x3a);
        *(undefined1 *)(param_1 + 0x74ec) = *(undefined1 *)((int)param_3 + 0x3b);
        *(undefined1 *)(param_1 + 0x74ed) = *(undefined1 *)(param_3 + 0xf);
        *(undefined1 *)(param_1 + 0x74ee) = *(undefined1 *)((int)param_3 + 0x3d);
        *(undefined1 *)(param_1 + 0x74ef) = *(undefined1 *)((int)param_3 + 0x3e);
        *(undefined1 *)(param_1 + 0x74f0) = *(undefined1 *)((int)param_3 + 0x3f);
        *(undefined1 *)(param_1 + 0x74f1) = *(undefined1 *)(param_3 + 0x10);
        *(undefined1 *)(param_1 + 0x74f2) = *(undefined1 *)(param_3 + 0x11);
        if (*(char *)(param_1 + 0x74e4) == '\0') {
          uVar6 = 0;
        }
        *(undefined1 *)(param_1 + 0x7515) = uVar6;
        *(byte *)(param_1 + 0x7516) = (byte)(-(uint)*(byte *)(param_1 + 0x74e2) >> 0x1b) & 0x10;
        bVar13 = 0x10;
        if (((*(char *)(param_1 + 0x74e8) == '\0') &&
            (bVar13 = 0xc, *(char *)(param_1 + 0x74e7) == '\0')) &&
           (bVar13 = 8, *(char *)(param_1 + 0x74e6) == '\0')) {
          bVar13 = (byte)(-(uint)*(byte *)(param_1 + 0x74e5) >> 0x1d) & 4;
        }
        *(byte *)(param_1 + 0x751c) = bVar13;
        uVar6 = 0x10;
        if ((*(char *)(param_1 + 0x74e1) == '\0') &&
           (uVar6 = 0xc, *(char *)(param_1 + 0x74e0) == '\0')) {
          uVar6 = 0;
        }
        *(undefined1 *)(param_1 + 0x7514) = uVar6;
        if ((*(char *)(param_1 + 0x74ed) != '\0') ||
           (uVar6 = 0, *(char *)(param_1 + 0x74f2) != '\0')) {
          uVar6 = 0xc;
        }
        *(undefined1 *)(param_1 + 0x7555) = uVar6;
        *(byte *)(param_1 + 0x7556) = (byte)(-(uint)*(byte *)(param_1 + 0x74eb) >> 0x1b) & 0x10;
        bVar13 = 0x10;
        if (((*(char *)(param_1 + 0x74f1) == '\0') &&
            (bVar13 = 0xc, *(char *)(param_1 + 0x74f0) == '\0')) &&
           (bVar13 = 8, *(char *)(param_1 + 0x74ef) == '\0')) {
          bVar13 = (byte)(-(uint)*(byte *)(param_1 + 0x74ee) >> 0x1d) & 4;
        }
        *(byte *)(param_1 + 0x755c) = bVar13;
        uVar6 = 0x10;
        if ((*(char *)(param_1 + 0x74ea) == '\0') &&
           (uVar6 = 0xc, *(char *)(param_1 + 0x74e9) == '\0')) {
          uVar6 = 0;
        }
        *(undefined1 *)(param_1 + 0x7554) = uVar6;
        puVar3 = PTR__gleSetVertexEval2Func_00112068;
        *(undefined **)(param_1 + 0x4898) = PTR__gleSetVertexEval1Func_0011206c;
        *(undefined **)(param_1 + 0x489c) = puVar3;
        return param_1;
      }
      if (param_2 != (undefined *)0x20000) {
        return param_1;
      }
      *(float *)(param_1 + 0x5404) = *param_3;
      return param_1;
    }
    if (param_2 == (undefined *)0x1000) {
      *(float *)(param_1 + 0x4ff4) = param_3[1];
      *(undefined1 *)(param_1 + 0x280d) = *(undefined1 *)(param_3 + 3);
      *(undefined1 *)(param_1 + 0x280e) = *(undefined1 *)((int)param_3 + 0xd);
      *(undefined1 *)(param_1 + 0x280c) = *(undefined1 *)((int)param_3 + 0xf);
      *(undefined2 *)(param_1 + 0x2808) = *(undefined2 *)((int)param_3 + 0x12);
      *(undefined2 *)(param_1 + 0x280a) = *(undefined2 *)((int)param_3 + 0x16);
      *(float *)(param_1 + 0x2800) = param_3[6];
      fVar9 = *param_3;
      if (6 < (int)GH_F2U(fVar9)) {
        fVar9 = 8.40779e-45;
      }
      *(float *)(param_1 + 0x4188) = param_3[0x80a];
      if (0 < (int)GH_F2U(fVar9)) {
        pfVar11 = param_3 + 0x808;
        iVar16 = param_1 + 0x4180;
        do {
          *(float *)(iVar16 + 0xc) = pfVar11[3];
          *(float *)(iVar16 + 0x10) = pfVar11[4];
          *(float *)(iVar16 + 0x14) = pfVar11[5];
          pfVar20 = pfVar11 + 6;
          pfVar11 = pfVar11 + 4;
          *(float *)(iVar16 + 0x18) = *pfVar20;
          iVar16 = iVar16 + 0x10;
          fVar9 = GH_U2F((unsigned int)(((int)GH_F2U(fVar9) + -1)));
        } while (fVar9 != 0.0);
      }
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_lock(*(int *)(param_1 + 0x5148) + 0x8028);
      }
      pfVar11 = param_3 + 7;
      puVar14 = (undefined1 *)(param_1 + 0x4664);
      pfVar20 = param_3 + 0x809;
      iVar16 = 0;
      do {
        iVar7 = iVar16 + 1;
        uVar15 = _gleBindPipelineProgram(param_1, iVar16, *(unsigned int *)pfVar11);
        uVar6 = *(undefined1 *)pfVar20;
        pfVar11 = pfVar11 + 1;
        pfVar20 = (float *)((int)pfVar20 + 1);
        *puVar14 = uVar6;
        puVar14 = puVar14 + 8;
        iVar16 = iVar7;
      } while (iVar7 < 2);
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
        uVar15 = _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
      }
      pfVar20 = *(float **)(param_1 + 0x4668);
      iVar16 = 0x100;
      pfVar11 = param_3 + 8;
      do {
        *pfVar20 = pfVar11[1];
        pfVar20[1] = pfVar11[2];
        pfVar20[2] = pfVar11[3];
        pfVar1 = pfVar11 + 4;
        pfVar11 = pfVar11 + 4;
        pfVar20[3] = *pfVar1;
        pfVar20 = pfVar20 + 4;
        iVar16 = iVar16 + -1;
      } while (iVar16 != 0);
      pfVar20 = *(float **)(param_1 + 0x4670);
      iVar16 = 0x80;
      pfVar11 = param_3 + 0x408;
      do {
        *pfVar20 = pfVar11[1];
        pfVar20[1] = pfVar11[2];
        pfVar20[2] = pfVar11[3];
        pfVar1 = pfVar11 + 4;
        pfVar11 = pfVar11 + 4;
        pfVar20[3] = *pfVar1;
        pfVar20 = pfVar20 + 4;
        iVar16 = iVar16 + -1;
      } while (iVar16 != 0);
      *(undefined1 *)(param_1 + 0x4661) = *(undefined1 *)((int)param_3 + 0xe);
      *(undefined1 *)(param_1 + 0x4660) = *(undefined1 *)((int)param_3 + 0xb);
      return uVar15;
    }
    if (param_2 < ((unsigned char *)0x00001001)) {
      if (param_2 != (undefined *)0x800) {
        return param_1;
      }
      *(undefined8 *)(param_1 + 0x1b90) = *(undefined8 *)param_3;
      *(undefined8 *)(param_1 + 0x1b98) = *(undefined8 *)(param_3 + 2);
      *(float *)(param_1 + 0x1ba0) = param_3[4];
      *(float *)(param_1 + 0x1ba4) = param_3[5];
      *(float *)(param_1 + 0x1ba8) = param_3[6];
      *(float *)(param_1 + 0x1bac) = param_3[7];
      return param_1;
    }
    if (param_2 != (undefined *)0x2000) {
      if (param_2 != (undefined *)0x4000) {
        return param_1;
      }
      puVar17 = (undefined2 *)(param_1 + 0x311a);
      iVar16 = 4;
      puVar12 = (undefined2 *)((int)param_3 + 0x26);
      do {
        uVar2 = *puVar12;
        puVar12 = puVar12 + 2;
        *puVar17 = uVar2;
        puVar17 = puVar17 + 1;
        iVar16 = iVar16 + -1;
      } while (iVar16 != 0);
      *(undefined1 *)(param_1 + 0x30c6) = *(undefined1 *)(param_3 + 0x14);
      *(undefined2 *)(param_1 + 0x30c4) = *(undefined2 *)((int)param_3 + 2);
      *(float *)(param_1 + 0x30c0) = param_3[1];
      *(undefined1 *)(param_1 + 0x30e4) = *(undefined1 *)((int)param_3 + 0x51);
      *(undefined2 *)(param_1 + 0x30ca) = *(undefined2 *)((int)param_3 + 10);
      *(undefined2 *)(param_1 + 0x30c8) = *(undefined2 *)((int)param_3 + 0xe);
      *(undefined2 *)(param_1 + 0x30e0) = *(undefined2 *)((int)param_3 + 0x12);
      *(float *)(param_1 + 0x30d0) = param_3[5];
      *(float *)(param_1 + 0x30d4) = param_3[6];
      *(float *)(param_1 + 0x30d8) = param_3[7];
      *(float *)(param_1 + 0x30dc) = param_3[8];
      *(undefined1 *)(param_1 + 0x313c) = *(undefined1 *)((int)param_3 + 0x52);
      *(undefined1 *)(param_1 + 0x3193) = *(undefined1 *)((int)param_3 + 0x53);
      *(undefined1 *)(param_1 + 0x3192) = *(undefined1 *)(param_3 + 0x15);
      *(undefined2 *)(param_1 + 0x3190) = *(undefined2 *)((int)param_3 + 0x36);
      *(float *)(param_1 + 0x3100) = param_3[0xe];
      *(float *)(param_1 + 0x3104) = param_3[0xf];
      *(float *)(param_1 + 0x3108) = param_3[0x10];
      *(float *)(param_1 + 0x310c) = param_3[0x11];
      *(float *)(param_1 + 0x3110) = param_3[0x12] * FLOAT_00108e5c;
      *(undefined1 *)(param_1 + 0x31a0) = *(undefined1 *)((int)param_3 + 0x55);
      *(undefined1 *)(param_1 + 0x31a1) = *(undefined1 *)((int)param_3 + 0x56);
      *(undefined1 *)(param_1 + 0x31a2) = *(undefined1 *)((int)param_3 + 0x57);
      *(undefined1 *)(param_1 + 0x31a3) = *(undefined1 *)(param_3 + 0x16);
      *(float *)(param_1 + 0x3194) = param_3[0x13];
      return param_1;
    }
    uVar4 = 0;
    *(undefined1 *)(param_1 + 0x316a) = *(undefined1 *)((int)param_3 + 0x97);
    *(undefined1 *)(param_1 + 0x30aa) = *(undefined1 *)(param_3 + 0x26);
    iVar16 = 0x10;
    *(undefined1 *)(param_1 + 0x318c) = *(undefined1 *)((int)param_3 + 0x9a);
    *(undefined1 *)(param_1 + 0x34d8) = *(undefined1 *)((int)param_3 + 0xa3);
    *(undefined1 *)(param_1 + 0x34da) = *(undefined1 *)(param_3 + 0x25);
    *(undefined1 *)(param_1 + 0x30c6) = *(undefined1 *)(param_3 + 0x24);
    *(undefined1 *)(param_1 + 0x30e4) = *(undefined1 *)((int)param_3 + 0x92);
    *(undefined1 *)(param_1 + 0x3193) = *(undefined1 *)((int)param_3 + 0x9b);
    *(undefined1 *)(param_1 + 0x3192) = *(undefined1 *)(param_3 + 0x27);
    *(undefined1 *)(param_1 + 0x313c) = *(undefined1 *)((int)param_3 + 0x96);
    *(undefined1 *)(param_1 + 0x3128) = *(undefined1 *)((int)param_3 + 0x95);
    fVar9 = *param_3;
    *(float *)(param_1 + 0x74d8) = fVar9;
    fVar10 = param_3[4];
    *(float *)(param_1 + 0x74dc) = fVar10;
    do {
      if (((uint)GH_F2U(fVar9) & 1 << (uVar4 & 0x3f)) == 0) {
        *(undefined1 *)(param_1 + uVar4 + 0x7524) = 0;
      }
      else {
        cVar5 = '\x04';
        if (*(int *)(param_1 + 0x7450) != 0) {
          cVar5 = (char)((unsigned char *)0x9da8)[uVar4 + *(int *)(param_1 + 0x7450)]<< 2;
        }
        *(char *)(param_1 + uVar4 + 0x7524) = cVar5;
      }
      cVar5 = '\0';
      if (((uint)GH_F2U(fVar10) & 1 << (uVar4 & 0x3f)) != 0) {
        cVar5 = '\x04';
        if (*(int *)(param_1 + 0x7450) != 0) {
          cVar5 = *(char *)(uVar4 + *(int *)(param_1 + 0x7450) + 0x9db8) << 2;
        }
      }
      *(char *)(param_1 + uVar4 + 0x7564) = cVar5;
      uVar4 = uVar4 + 1;
      iVar16 = iVar16 + -1;
    } while (iVar16 != 0);
    uVar6 = 0xc;
    *(undefined1 *)(param_1 + 0x74e0) = *(undefined1 *)(param_3 + 1);
    *(undefined1 *)(param_1 + 0x74e1) = *(undefined1 *)((int)param_3 + 5);
    *(undefined1 *)(param_1 + 0x74e2) = *(undefined1 *)((int)param_3 + 6);
    *(undefined1 *)(param_1 + 0x74e3) = *(undefined1 *)((int)param_3 + 7);
    *(undefined1 *)(param_1 + 0x74e4) = *(undefined1 *)(param_3 + 2);
    *(undefined1 *)(param_1 + 0x74e5) = *(undefined1 *)((int)param_3 + 9);
    *(undefined1 *)(param_1 + 0x74e6) = *(undefined1 *)((int)param_3 + 10);
    *(undefined1 *)(param_1 + 0x74e7) = *(undefined1 *)((int)param_3 + 0xb);
    *(undefined1 *)(param_1 + 0x74e8) = *(undefined1 *)(param_3 + 3);
    *(undefined1 *)(param_1 + 0x74e9) = *(undefined1 *)(param_3 + 5);
    *(undefined1 *)(param_1 + 0x74ea) = *(undefined1 *)((int)param_3 + 0x15);
    *(undefined1 *)(param_1 + 0x74eb) = *(undefined1 *)((int)param_3 + 0x16);
    *(undefined1 *)(param_1 + 0x74ec) = *(undefined1 *)((int)param_3 + 0x17);
    *(undefined1 *)(param_1 + 0x74ed) = *(undefined1 *)(param_3 + 6);
    *(undefined1 *)(param_1 + 0x74ee) = *(undefined1 *)((int)param_3 + 0x19);
    *(undefined1 *)(param_1 + 0x74ef) = *(undefined1 *)((int)param_3 + 0x1a);
    *(undefined1 *)(param_1 + 0x74f0) = *(undefined1 *)((int)param_3 + 0x1b);
    *(undefined1 *)(param_1 + 0x74f1) = *(undefined1 *)(param_3 + 7);
    *(undefined1 *)(param_1 + 0x74f2) = *(undefined1 *)((int)param_3 + 0x91);
    if (*(char *)(param_1 + 0x74e4) == '\0') {
      uVar6 = 0;
    }
    *(undefined1 *)(param_1 + 0x7515) = uVar6;
    *(byte *)(param_1 + 0x7516) = (byte)(-(uint)*(byte *)(param_1 + 0x74e2) >> 0x1b) & 0x10;
    bVar13 = 0x10;
    if (((*(char *)(param_1 + 0x74e8) == '\0') &&
        (bVar13 = 0xc, *(char *)(param_1 + 0x74e7) == '\0')) &&
       (bVar13 = 8, *(char *)(param_1 + 0x74e6) == '\0')) {
      bVar13 = (byte)(-(uint)*(byte *)(param_1 + 0x74e5) >> 0x1d) & 4;
    }
    *(byte *)(param_1 + 0x751c) = bVar13;
    uVar6 = 0x10;
    if ((*(char *)(param_1 + 0x74e1) == '\0') && (uVar6 = 0xc, *(char *)(param_1 + 0x74e0) == '\0'))
    {
      uVar6 = 0;
    }
    *(undefined1 *)(param_1 + 0x7514) = uVar6;
    if ((*(char *)(param_1 + 0x74ed) != '\0') || (uVar6 = 0, *(char *)(param_1 + 0x74f2) != '\0')) {
      uVar6 = 0xc;
    }
    *(undefined1 *)(param_1 + 0x7555) = uVar6;
    *(byte *)(param_1 + 0x7556) = (byte)(-(uint)*(byte *)(param_1 + 0x74eb) >> 0x1b) & 0x10;
    bVar13 = 0x10;
    if (((*(char *)(param_1 + 0x74f1) == '\0') &&
        (bVar13 = 0xc, *(char *)(param_1 + 0x74f0) == '\0')) &&
       (bVar13 = 8, *(char *)(param_1 + 0x74ef) == '\0')) {
      bVar13 = (byte)(-(uint)*(byte *)(param_1 + 0x74ee) >> 0x1d) & 4;
    }
    *(byte *)(param_1 + 0x755c) = bVar13;
    uVar6 = 0x10;
    if ((*(char *)(param_1 + 0x74ea) == '\0') && (uVar6 = 0xc, *(char *)(param_1 + 0x74e9) == '\0'))
    {
      uVar6 = 0;
    }
    *(undefined1 *)(param_1 + 0x7554) = uVar6;
    puVar3 = PTR__gleSetVertexEval1Func_0011206c;
    pfVar20 = (float *)(param_1 + 0x3534);
    *(undefined **)(param_1 + 0x489c) = PTR__gleSetVertexEval2Func_00112068;
    pfVar11 = param_3 + 8;
    *(undefined **)(param_1 + 0x4898) = puVar3;
    *(undefined1 *)(param_1 + 0x343c) = *(undefined1 *)((int)param_3 + 0x9e);
    *(undefined1 *)(param_1 + 0x343d) = *(undefined1 *)((int)param_3 + 0xae);
    iVar16 = 0x10;
    *(undefined1 *)(param_1 + 0x318d) = *(undefined1 *)((int)param_3 + 0x99);
    *(undefined1 *)(param_1 + 0x34d9) = *(undefined1 *)((int)param_3 + 0xa2);
    *(undefined1 *)(param_1 + 0x34f0) = *(undefined1 *)(param_3 + 0x29);
    *(undefined1 *)(param_1 + 0x30ab) = *(undefined1 *)((int)param_3 + 0x93);
    *(undefined1 *)(param_1 + 0x280d) = *(undefined1 *)((int)param_3 + 0x9d);
    *(undefined1 *)(param_1 + 0x280e) = *(undefined1 *)((int)param_3 + 0xa5);
    *(undefined1 *)(param_1 + 0x34dd) = *(undefined1 *)((int)param_3 + 0x9f);
    *(undefined1 *)(param_1 + 0x34dc) = *(undefined1 *)(param_3 + 0x28);
    *(undefined1 *)(param_1 + 0x34db) = *(undefined1 *)((int)param_3 + 0xa1);
    *(undefined1 *)(param_1 + 0x41f8) = *(undefined1 *)((int)param_3 + 0xa6);
    *(undefined1 *)(param_1 + 0x41f9) = *(undefined1 *)((int)param_3 + 0xaf);
    *(undefined1 *)(param_1 + 0x50b5) = *(undefined1 *)((int)param_3 + 0xa7);
    *(undefined1 *)(param_1 + 0x280c) = *(undefined1 *)((int)param_3 + 0xad);
    *(undefined1 *)(param_1 + 0x41f0) = *(undefined1 *)(param_3 + 0x2a);
    *(undefined1 *)(param_1 + 0x41f1) = *(undefined1 *)((int)param_3 + 0xa9);
    *(undefined1 *)(param_1 + 0x41f2) = *(undefined1 *)((int)param_3 + 0xaa);
    *(undefined1 *)(param_1 + 0x41f3) = *(undefined1 *)((int)param_3 + 0xab);
    *(undefined1 *)(param_1 + 0x4661) = *(undefined1 *)(param_3 + 0x2b);
    do {
      fVar9 = *pfVar11;
      pfVar11 = pfVar11 + 1;
      *pfVar20 = fVar9;
      pfVar20 = pfVar20 + 0x1f;
      iVar16 = iVar16 + -1;
    } while (iVar16 != 0);
    puVar21 = (undefined1 *)((int)param_3 + 0x6f);
    iVar16 = 8;
    puVar14 = (undefined1 *)(param_1 + 0x3d7b);
    do {
      puVar14[-3] = puVar21[-3];
      puVar14[-2] = puVar21[-2];
      puVar14[-1] = puVar21[-1];
      uVar6 = *puVar21;
      puVar21 = puVar21 + 4;
      *puVar14 = uVar6;
      puVar14 = puVar14 + 0x94;
      iVar16 = iVar16 + -1;
    } while (iVar16 != 0);
    iVar16 = 1;
    puVar14 = (undefined1 *)(param_1 + 0x4664);
    *(float *)(param_1 + 0x3520) = param_3[0x1a];
    *(float *)(param_1 + 0x4188) = param_3[0x19];
    pfVar11 = param_3 + 0x23;
    *(float *)(param_1 + 0x30a0) = param_3[0x18];
    do {
      iVar16 = iVar16 + -1;
      uVar6 = *(undefined1 *)pfVar11;
      pfVar11 = (float *)((int)pfVar11 + 1);
      *puVar14 = uVar6;
      puVar14 = puVar14 + 8;
    } while (-1 < iVar16);
    *(undefined1 *)(param_1 + 0x4fea) = *(undefined1 *)(param_3 + 0x2c);
    *(undefined1 *)(param_1 + 0x312a) = *(undefined1 *)((int)param_3 + 0xb1);
    uVar6 = *(undefined1 *)((int)param_3 + 0xb2);
  }
  *(undefined1 *)(param_1 + 0x3129) = uVar6;
  return param_1;
}

/* _glMatrixMode_ListExec @ 0x4c6b0 (40 bytes) */
int _glMatrixMode_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glMatrixMode_Exec(param_1,*param_2);
  return 4;
}

/* _glScale_ListExec @ 0x4c6d8 (48 bytes) */
int _glScale_ListExec(param_1, param_2)
  undefined4 param_1;
  float *param_2;
{
  ((void (*)())_glScale_Exec)(param_1,(double)*param_2,(double)param_2[1],(double)param_2[2]);
  return 0xc;
}

/* _glTexCoord2_ListExec @ 0x4c708 (40 bytes) */
int _glTexCoord2_ListExec(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined4 uVar1;
  
  uVar1 = param_2[1];
  *(undefined4 *)(param_1 + 0x120) = *param_2;
  *(undefined4 *)(param_1 + 300) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(param_1 + 0x124) = uVar1;
  *(undefined4 *)(param_1 + 0x128) = *(undefined4 *)(param_1 + 0x20);
  return 8;
}

/* _glEnableClientState_Exec @ 0x4c730 (44 bytes) */
void _glEnableClientState_Exec(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  if (*(short *)(param_1 + 0x4a10) < 0) {
    _gleSetClientEnableFlag(param_1,param_2,1);
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x502;
  return;
}

/* _gleFreeTextureLevel @ 0x4c75c (132 bytes) */
int _gleFreeTextureLevel(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
{
  vm_size_t size;
  
  if ((*(byte *)(param_3 + 0xb) & 8) == 0) {
    _free(*(undefined4 *)(param_3 + 0x14));
  }
  else {
    size = ((int (*)())_gleTextureLevelBytes)(param_1,param_3);
    *(byte *)(param_3 + 0xb) = *(byte *)(param_3 + 0xb) & 0xf7;
    if (size != 0) {
      _vm_deallocate(*(vm_map_t *)PTR_00112034,*(vm_address_t *)(param_3 + 0x14),size);
    }
  }
  *(undefined4 *)(param_3 + 0x14) = 0;
  return 1;
}

/* _glGetDoublev_Exec @ 0x4c7e0 (276 bytes) */
void _glGetDoublev_Exec(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined8 *param_3;
{
  double dVar1;
  undefined4 uVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  undefined1 auStack_b0 [16];
  uint local_a0 [32];
  undefined4 local_20;
  uint uStack_1c;
  int local_18 [2];
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    puVar3 = local_a0;
    iVar4 = _gleGetState(param_1,param_2,puVar3,local_18,auStack_b0);
    dVar1 = DOUBLE_00108d58;
    if (iVar4 == 0) {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar2 = 0x500;
      goto LAB_0004c854;
    }
    if (iVar4 != -1) {
      if (local_18[0] != 0x1404) {
        if (iVar4 < 1) {
          return;
        }
        do {
          uVar6 = *(undefined8 *)puVar3;
          puVar3 = puVar3 + 2;
          *param_3 = uVar6;
          param_3 = param_3 + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
        return;
      }
      iVar5 = 0;
      if (iVar4 < 1) {
        return;
      }
      do {
        local_20 = 0x43300000;
        uStack_1c = local_a0[iVar5 * 2] ^ 0x80000000;
        param_3[iVar5] = (double)CONCAT44(0x43300000,local_a0[iVar5 * 2] ^ 0x80000000) - dVar1;
        iVar4 = iVar4 + -1;
        iVar5 = iVar5 + 1;
      } while (iVar4 != 0);
      return;
    }
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar2 = 0x502;
LAB_0004c854:
  *(undefined4 *)(param_1 + 0x7574) = uVar2;
  return;
}

/* _gleGetMatrixd @ 0x4c8f4 (132 bytes) */
void _gleGetMatrixd(param_1, param_2)
  float *param_1;
  double *param_2;
{
  *param_2 = (double)*param_1;
  param_2[1] = (double)param_1[1];
  param_2[2] = (double)param_1[2];
  param_2[3] = (double)param_1[3];
  param_2[4] = (double)param_1[4];
  param_2[5] = (double)param_1[5];
  param_2[6] = (double)param_1[6];
  param_2[7] = (double)param_1[7];
  param_2[8] = (double)param_1[8];
  param_2[9] = (double)param_1[9];
  param_2[10] = (double)param_1[10];
  param_2[0xb] = (double)param_1[0xb];
  param_2[0xc] = (double)param_1[0xc];
  param_2[0xd] = (double)param_1[0xd];
  param_2[0xe] = (double)param_1[0xe];
  param_2[0xf] = (double)param_1[0xf];
  return;
}

/* _glRectd_Exec @ 0x4c978 (196 bytes) */
void _glRectd_Exec(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
    }
    FUN_00008b68();
    return;
  }
  ((void (*)())_glBegin_Exec)(param_1,9,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
  ((void (*)())_glVertex2d_Exec)(param_1,fparam_1,fparam_2);
  ((void (*)())_glVertex2d_Exec)(param_1,fparam_3,fparam_2);
  ((void (*)())_glVertex2d_Exec)(param_1,fparam_3,fparam_4);
  ((void (*)())_glVertex2d_Exec)(param_1,fparam_1,fparam_4);
  _glEnd_Exec(param_1);
  return;
}

/* _gleBeginPolygonRenderTCL @ 0x4ca3c (60 bytes) */
void _gleBeginPolygonRenderTCL(param_1)
  int param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  *(undefined1 *)(param_1 + 0x4a18) = 0;
  puVar2 = PTR__gleFlushPolygonTCLFunc_00112254;
  puVar1 = PTR__gleRenderPolygonTCLFunc_00112250;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined **)(param_1 + 0x4a0c) = puVar2;
  *(undefined **)(param_1 + 0x4a08) = puVar1;
  return;
}

/* _glVertex2d_Exec @ 0x4ca78 (52 bytes) */
void _glVertex2d_Exec(int param_1,double fparam_1,double fparam_2)
{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x4884);
  if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
    UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x28);
  }
                    
                    
  (*((int (*)(int,double,double,double,double))UNRECOVERED_JUMPTABLE))
            (param_1, (double)(float)fparam_1, (double)(float)fparam_2, (double)*(float *)(param_1 + 0x20), (double)*(float *)(param_1 + 0x24));
  return;
}

/* _glColorPointer_Exec @ 0x4cad4 (868 bytes) */
void _glColorPointer_Exec(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint param_2;
  code *param_3;
  int param_4;
  int param_5;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  int iVar8;
  
  iVar4 = *(int *)(param_1 + 0x4a60);
  uVar7 = param_4 << 7 | (uint)param_3 & 0xf | (param_2 & 3) << 4;
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x502;
LAB_0004cda8:
    *(undefined4 *)(param_1 + 0x7574) = uVar1;
    return;
  }
  *(uint *)(param_1 + 0x497c) = *(uint *)(param_1 + 0x497c) | 2;
  *(undefined4 *)(iVar4 + 0x350) = *(undefined4 *)(iVar4 + 0x350);
  *(uint *)(iVar4 + 0x354) = *(uint *)(iVar4 + 0x354) | 0x40000;
  if (*(int *)(iVar4 + 0x60) != param_5) {
    *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x100000;
  }
  *(int *)(iVar4 + 0x60) = param_5;
  iVar8 = *(int *)(iVar4 + 0x358);
  iVar3 = *(int *)(iVar4 + 0x368);
  if (iVar8 != iVar3) {
    if ((iVar3 != 0) && (iVar2 = *(int *)(iVar3 + 8) + -1, *(int *)(iVar3 + 8) = iVar2, iVar2 == 0))
    {
      _gleFreeBufferObject(param_1,iVar3);
    }
    if (iVar8 == 0) {
      iVar3 = 0;
      *(undefined4 *)(iVar4 + 0x338) = *(undefined4 *)(iVar4 + 0x338);
      *(uint *)(iVar4 + 0x33c) = *(uint *)(iVar4 + 0x33c) & 0xfffbffff;
      if (*(char *)(param_1 + 0x85a4) != '\0') {
        puVar5 = (undefined4 *)(iVar4 + 1000);
        do {
          *puVar5 = 0;
          iVar3 = iVar3 + 1;
          puVar5 = puVar5 + 0x23;
        } while (iVar3 < (int)(uint)*(byte *)(param_1 + 0x85a4));
      }
    }
    else {
      *(int *)(iVar8 + 8) = *(int *)(iVar8 + 8) + 1;
      *(undefined4 *)(iVar4 + 0x338) = *(undefined4 *)(iVar4 + 0x338);
      *(uint *)(iVar4 + 0x33c) = *(uint *)(iVar4 + 0x33c) | 0x40000;
      iVar3 = 0;
      if (*(char *)(param_1 + 0x85a4) != '\0') {
        puVar6 = (undefined4 *)(iVar4 + 1000);
        puVar5 = (undefined4 *)(iVar8 + 0x10);
        do {
          uVar1 = *puVar5;
          iVar3 = iVar3 + 1;
          puVar5 = puVar5 + 1;
          *puVar6 = uVar1;
          puVar6 = puVar6 + 0x23;
        } while (iVar3 < (int)(uint)*(byte *)(param_1 + 0x85a4));
      }
    }
    *(int *)(iVar4 + 0x368) = iVar8;
    *(undefined4 *)(iVar4 + 0x350) = *(undefined4 *)(iVar4 + 0x350);
    *(uint *)(iVar4 + 0x354) = *(uint *)(iVar4 + 0x354) | 0x10;
  }
  if (iVar8 != 0) {
    param_5 = param_5 + *(int *)(iVar8 + 0x30);
  }
  *(int *)(param_1 + 0x4900) = param_5;
  if (*(uint *)(iVar4 + 0x74) == uVar7) {
    return;
  }
  if ((1 < param_2 - 3) || (param_4 < 0)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x501;
    goto LAB_0004cda8;
  }
  switch((int)param_3) {
  case 0x1400:
    iVar8 = 0;
    param_3 = (code *)0x9400;
    goto LAB_0004cd3c;
  case 0x1401:
    iVar8 = 1;
    param_3 = (code *)0x9401;
LAB_0004cd3c:
    iVar3 = 1;
    goto LAB_0004cdb0;
  case 0x1402:
    iVar8 = 2;
    param_3 = (code *)0x9402;
    goto LAB_0004cd60;
  case 0x1403:
    iVar8 = 3;
    param_3 = (code *)0x9403;
LAB_0004cd60:
    iVar3 = 2;
    goto LAB_0004cdb0;
  case 0x1404:
    iVar8 = 4;
    param_3 = (code *)0x9404;
    break;
  case 0x1405:
    iVar8 = 5;
    param_3 = (code *)0x9404;
    break;
  case 0x1406:
    iVar8 = 6;
    break;
  default:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x500;
    goto LAB_0004cda8;
  case 0x140a:
    iVar8 = 7;
    iVar3 = 8;
    goto LAB_0004cdb0;
  }
  iVar3 = 4;
LAB_0004cdb0:
  *(short *)(iVar4 + 0x68) = (short)param_3;
  *(char *)(iVar4 + 0x6c) = (char)iVar3;
  *(short *)(iVar4 + 0x6a) = (short)param_2;
  if (param_4 < 1) {
    param_4 = param_2 * iVar3;
  }
  *(int *)(iVar4 + 100) = param_4;
  *(uint *)(iVar4 + 0x74) = uVar7;
  *(undefined4 *)(param_1 + 0x488c) = 0;
  *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x100000;
  *(undefined4 *)(param_1 + 0x4890) = 0;
  *(undefined4 *)(param_1 + 0x4894) = 0;
  if (*(int *)(param_1 + 0x5408) == 0) {
    uVar7 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xc) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar7 | *(uint *)(param_1 + 0x4684) & ~uVar7) + 0xc) =
         PTR__glArrayElement_Exec_00110454;
  }
  *(char *)(iVar4 + 0x6d) = (char)iVar8;
  uVar7 = iVar8 << 8;
  if (param_2 != 3) {
    uVar7 = (iVar8 + 8) * 0x100;
  }
  *(uint *)(iVar4 + 0x70) = uVar7;
  *(uint *)(param_1 + 0x49b0) = *(uint *)(param_1 + 0x49b0) & 0xfffff0ff | uVar7;
  return;
}

/* _glVertexPointer_Exec @ 0x4ce64 (776 bytes) */
void _glVertexPointer_Exec(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint param_2;
  uint param_3;
  int param_4;
  int param_5;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  int iVar8;
  
  iVar5 = *(int *)(param_1 + 0x4a60);
  uVar7 = param_4 << 7 | param_3 & 0xf | (param_2 & 3) << 4;
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x502;
    goto LAB_0004d0b0;
  }
  *(undefined4 *)(iVar5 + 0x350) = *(undefined4 *)(iVar5 + 0x350);
  *(uint *)(iVar5 + 0x354) = *(uint *)(iVar5 + 0x354) | 0x10000;
  if (*(int *)(iVar5 + 0x30) != param_5) {
    *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x100000;
  }
  *(int *)(iVar5 + 0x30) = param_5;
  iVar8 = *(int *)(iVar5 + 0x358);
  iVar3 = *(int *)(iVar5 + 0x360);
  if (iVar8 != iVar3) {
    if ((iVar3 != 0) && (iVar2 = *(int *)(iVar3 + 8) + -1, *(int *)(iVar3 + 8) = iVar2, iVar2 == 0))
    {
      _gleFreeBufferObject(param_1,iVar3);
    }
    if (iVar8 == 0) {
      iVar3 = 0;
      *(undefined4 *)(iVar5 + 0x338) = *(undefined4 *)(iVar5 + 0x338);
      *(uint *)(iVar5 + 0x33c) = *(uint *)(iVar5 + 0x33c) & 0xfffeffff;
      if (*(char *)(param_1 + 0x85a4) != '\0') {
        puVar4 = (undefined4 *)(iVar5 + 0x3e0);
        do {
          *puVar4 = 0;
          iVar3 = iVar3 + 1;
          puVar4 = puVar4 + 0x23;
        } while (iVar3 < (int)(uint)*(byte *)(param_1 + 0x85a4));
      }
    }
    else {
      *(int *)(iVar8 + 8) = *(int *)(iVar8 + 8) + 1;
      *(undefined4 *)(iVar5 + 0x338) = *(undefined4 *)(iVar5 + 0x338);
      *(uint *)(iVar5 + 0x33c) = *(uint *)(iVar5 + 0x33c) | 0x10000;
      iVar3 = 0;
      if (*(char *)(param_1 + 0x85a4) != '\0') {
        puVar6 = (undefined4 *)(iVar5 + 0x3e0);
        puVar4 = (undefined4 *)(iVar8 + 0x10);
        do {
          uVar1 = *puVar4;
          iVar3 = iVar3 + 1;
          puVar4 = puVar4 + 1;
          *puVar6 = uVar1;
          puVar6 = puVar6 + 0x23;
        } while (iVar3 < (int)(uint)*(byte *)(param_1 + 0x85a4));
      }
    }
    *(int *)(iVar5 + 0x360) = iVar8;
    *(undefined4 *)(iVar5 + 0x350) = *(undefined4 *)(iVar5 + 0x350);
    *(uint *)(iVar5 + 0x354) = *(uint *)(iVar5 + 0x354) | 0x10;
  }
  if (iVar8 != 0) {
    param_5 = param_5 + *(int *)(iVar8 + 0x30);
  }
  *(int *)(param_1 + 0x48f8) = param_5;
  if (*(uint *)(iVar5 + 0x44) == uVar7) {
    return;
  }
  if ((2 < param_2 - 2) || (param_4 < 0)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x501;
    goto LAB_0004d0b0;
  }
  if (param_3 != 0x1404) {
    if (param_3 < 0x1405) {
      if (param_3 == 0x1402) {
        iVar3 = 0;
        iVar8 = 2;
        goto LAB_0004d0b8;
      }
    }
    else {
      if (param_3 == 0x1406) {
        iVar3 = 2;
        goto LAB_0004d08c;
      }
      if (param_3 == 0x140a) {
        iVar3 = 3;
        iVar8 = 8;
        goto LAB_0004d0b8;
      }
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x500;
LAB_0004d0b0:
    *(undefined4 *)(param_1 + 0x7574) = uVar1;
    return;
  }
  iVar3 = 1;
LAB_0004d08c:
  iVar8 = 4;
LAB_0004d0b8:
  *(short *)(iVar5 + 0x38) = (short)param_3;
  *(char *)(iVar5 + 0x3c) = (char)iVar8;
  *(short *)(iVar5 + 0x3a) = (short)param_2;
  if (param_4 < 1) {
    param_4 = param_2 * iVar8;
  }
  *(int *)(iVar5 + 0x34) = param_4;
  *(uint *)(iVar5 + 0x44) = uVar7;
  *(undefined4 *)(param_1 + 0x488c) = 0;
  *(undefined4 *)(param_1 + 0x4890) = 0;
  *(undefined4 *)(param_1 + 0x4894) = 0;
  if (*(int *)(param_1 + 0x5408) == 0) {
    uVar7 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xc) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar7 | *(uint *)(param_1 + 0x4684) & ~uVar7) + 0xc) =
         PTR__glArrayElement_Exec_00110454;
  }
  *(char *)(iVar5 + 0x3d) = (char)iVar3;
  iVar8 = iVar3;
  if ((param_2 != 2) && (iVar8 = iVar3 + 4, param_2 != 3)) {
    iVar8 = iVar3 + 8;
  }
  *(int *)(iVar5 + 0x40) = iVar8 << 0xc;
  *(uint *)(param_1 + 0x49b0) = *(uint *)(param_1 + 0x49b0) & 0xffff0fff | iVar8 << 0xc;
  return;
}

/* _glTexCoordPointer_Exec @ 0x4d16c (972 bytes) */
void _glTexCoordPointer_Exec(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint param_2;
  uint param_3;
  int param_4;
  int param_5;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  int iVar8;
  undefined4 *puVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  
  uVar7 = *(uint *)(param_1 + 0x53d8);
  iVar8 = *(int *)(param_1 + 0x4a60);
  uVar10 = param_4 << 7 | param_3 & 0xf | (param_2 & 3) << 4;
  iVar14 = iVar8 + 0x10;
  uVar11 = (uVar7 & 1) * -4 + 4;
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x502;
    goto LAB_0004d44c;
  }
  uVar12 = uVar7 + 8;
  if (uVar12 < 0x11) {
    *(uint *)(param_1 + 0x497c) = *(uint *)(param_1 + 0x497c) | 8 << (uVar7 & 0x3f);
    uVar7 = 0x1000000 << (uVar7 & 0x3f);
    *(undefined4 *)(iVar8 + 0x350) = *(undefined4 *)(iVar8 + 0x350);
    *(uint *)(iVar8 + 0x354) = *(uint *)(iVar8 + 0x354) | uVar7;
    iVar3 = iVar14 + uVar12 * 0x18;
    if (*(int *)(iVar3 + 0x20) != param_5) {
      *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x100000;
    }
    iVar1 = uVar12 * 4;
    *(int *)(iVar3 + 0x20) = param_5;
    iVar5 = *(int *)(iVar1 + iVar14 + 0x350);
    if (uVar7 == 0x800000) {
      iVar13 = *(int *)(iVar8 + 0x35c);
    }
    else {
      iVar13 = *(int *)(iVar8 + 0x358);
    }
    if (iVar13 != iVar5) {
      if ((iVar5 != 0) &&
         (iVar4 = *(int *)(iVar5 + 8) + -1, *(int *)(iVar5 + 8) = iVar4, iVar4 == 0)) {
        _gleFreeBufferObject(param_1,iVar5);
      }
      if (iVar13 == 0) {
        *(undefined4 *)(iVar8 + 0x338) = *(undefined4 *)(iVar8 + 0x338);
        *(uint *)(iVar8 + 0x33c) = *(uint *)(iVar8 + 0x33c) & ~uVar7;
        iVar5 = 0;
        if (*(char *)(param_1 + 0x85a4) != '\0') {
          puVar6 = (undefined4 *)(uVar12 * 4 + iVar14 + 0x3d0);
          do {
            *puVar6 = 0;
            iVar5 = iVar5 + 1;
            puVar6 = puVar6 + 0x23;
          } while (iVar5 < (int)(uint)*(byte *)(param_1 + 0x85a4));
        }
      }
      else {
        *(int *)(iVar13 + 8) = *(int *)(iVar13 + 8) + 1;
        *(undefined4 *)(iVar8 + 0x338) = *(undefined4 *)(iVar8 + 0x338);
        *(uint *)(iVar8 + 0x33c) = *(uint *)(iVar8 + 0x33c) | uVar7;
        iVar5 = 0;
        if (*(char *)(param_1 + 0x85a4) != '\0') {
          puVar9 = (undefined4 *)(iVar13 + 0x10);
          puVar6 = (undefined4 *)(uVar12 * 4 + iVar14 + 0x3d0);
          do {
            uVar2 = *puVar9;
            iVar5 = iVar5 + 1;
            puVar9 = puVar9 + 1;
            *puVar6 = uVar2;
            puVar6 = puVar6 + 0x23;
          } while (iVar5 < (int)(uint)*(byte *)(param_1 + 0x85a4));
        }
      }
      uVar2 = *(undefined4 *)(iVar8 + 0x350);
      uVar7 = *(uint *)(iVar8 + 0x354);
      *(int *)(iVar1 + iVar14 + 0x350) = iVar13;
      *(undefined4 *)(iVar8 + 0x350) = uVar2;
      *(uint *)(iVar8 + 0x354) = uVar7 | 0x10;
    }
    if (iVar13 != 0) {
      param_5 = param_5 + *(int *)(iVar13 + 0x30);
    }
    *(int *)(iVar1 + param_1 + 0x48f8) = param_5;
    if (*(uint *)(iVar3 + 0x34) == uVar10) {
      return;
    }
    if ((param_2 - 1 < 4) && (-1 < param_4)) {
      if (param_3 == 0x1404) {
        iVar8 = 1;
LAB_0004d428:
        iVar14 = 4;
      }
      else if (param_3 < 0x1405) {
        if (param_3 != 0x1402) {
LAB_0004d43c:
          if (*(int *)(param_1 + 0x7574) != 0) {
            return;
          }
          uVar2 = 0x500;
          goto LAB_0004d44c;
        }
        iVar8 = 0;
        iVar14 = 2;
      }
      else {
        if (param_3 == 0x1406) {
          iVar8 = 2;
          goto LAB_0004d428;
        }
        if (param_3 != 0x140a) goto LAB_0004d43c;
        iVar8 = 3;
        iVar14 = 8;
      }
      *(short *)(iVar3 + 0x28) = (short)param_3;
      *(char *)(iVar3 + 0x2c) = (char)iVar14;
      *(short *)(iVar3 + 0x2a) = (short)param_2;
      if (param_4 < 1) {
        param_4 = param_2 * iVar14;
      }
      *(int *)(iVar3 + 0x24) = param_4;
      *(uint *)(iVar3 + 0x34) = uVar10;
      *(undefined4 *)(param_1 + 0x488c) = 0;
      *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x100000;
      *(undefined4 *)(param_1 + 0x4890) = 0;
      *(undefined4 *)(param_1 + 0x4894) = 0;
      if (*(int *)(param_1 + 0x5408) == 0) {
        uVar7 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xc) == 0);
        *(undefined **)
         ((*(uint *)(param_1 + 0x4680) & uVar7 | *(uint *)(param_1 + 0x4684) & ~uVar7) + 0xc) =
             PTR__glArrayElement_Exec_00110454;
      }
      *(char *)(iVar3 + 0x2d) = (char)iVar8;
      if (param_2 == 2) {
        iVar14 = iVar8 + 4;
      }
      else {
        if ((int)param_2 < 3) {
          uVar7 = iVar8 << (uVar11 & 0x3f);
          if (param_2 == 1) goto LAB_0004d508;
        }
        else {
          iVar14 = iVar8 + 8;
          if (param_2 == 3) goto LAB_0004d504;
        }
        iVar14 = iVar8 + 0xc;
      }
LAB_0004d504:
      uVar7 = iVar14 << (uVar11 & 0x3f);
LAB_0004d508:
      *(uint *)(iVar3 + 0x30) = uVar7;
      *(uint *)(param_1 + 0x49b0) = *(uint *)(param_1 + 0x49b0) & ~(0xf << (uVar11 & 0x3f)) | uVar7;
      return;
    }
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar2 = 0x501;
LAB_0004d44c:
  *(undefined4 *)(param_1 + 0x7574) = uVar2;
  return;
}

/* _glDrawArrays_Exec @ 0x4d538 (56 bytes) */
void _glDrawArrays_Exec(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  if (*(int *)(param_1 + 0x48dc) != 0x14ff) {
    *(undefined4 *)(param_1 + 0x488c) = 0;
    *(undefined4 *)(param_1 + 0x48dc) = 0x14ff;
    *(undefined4 *)(param_1 + 0x48d8) = 0;
    *(undefined4 *)(param_1 + 0x4978) = 0;
    *(undefined4 *)(param_1 + 0x4890) = 0;
  }
  ((void (*)())_gleEvalDrawArraysOrElements_Entires_Exec)(param_1,param_2,param_3,param_4,0,*(int *)(param_1 + 0x4a60) + 0x10,fparam_1,fparam_2,
             fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
  return;
}

/* _gleEvalDrawArraysOrElements_Entires_Exec @ 0x4d570 (812 bytes) */
void _gleEvalDrawArraysOrElements_Entires_Exec(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,int param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  uint uVar1;
  
  if (*(int *)(param_1 + 0x5408) != 0) {
    ((void (*)())_gleDrawArraysOrElements_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,fparam_1,fparam_2,fparam_3,fparam_4,
               fparam_5,fparam_6,fparam_7,fparam_8);
    return;
  }
  if ((*(uint *)(param_6 + 0x328) & *(uint *)(param_6 + 800)) != 0 ||
      (*(uint *)(param_6 + 0x32c) & *(uint *)(param_6 + 0x324)) != 0) {
    uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x104) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x104) =
         PTR__glDrawArrays_VBO_Exec_00110448;
    uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x10c) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x10c) =
         PTR__glDrawElements_VBO_Exec_00110444;
    uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x654) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x654) =
         PTR__glDrawRangeElements_VBO_Exec_00110440;
    ((void (*)())_gleDrawArraysOrElements_VBO_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,fparam_1,fparam_2,fparam_3,fparam_4,
               fparam_5,fparam_6,fparam_7,fparam_8);
    return;
  }
  if (((*(int *)(param_6 + 0x338) != 0) && (*(int *)(param_6 + 0x334) != 0)) &&
     ((*(char *)(param_1 + 0x465c) != '\0' ||
      ((*(short *)(param_6 + 0x332) == -0x7a42 || (*(short *)(param_6 + 0x332) == -0x7a41)))))) {
    uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x104) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x104) =
         PTR__glDrawArrays_VAR_Exec_0011043c;
    uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x10c) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x10c) =
         PTR__glDrawElements_VAR_Exec_00110438;
    uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x654) == 0);
    uVar1 = *(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1;
    *(undefined **)(uVar1 + 0x654) = PTR__glDrawRangeElements_VAR_Exec_00110434;
    ((void (*)())_gleDrawArraysOrElements_VAR_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,uVar1,fparam_1,fparam_2,fparam_3,
               fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
    return;
  }
  if (*(int *)(param_1 + 0x4988) != 0) {
    uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x104) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x104) =
         PTR__glDrawArrays_CVA_Exec_00110430;
    uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x10c) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x10c) =
         PTR__glDrawElements_CVA_Exec_0011042c;
    uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x654) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x654) =
         PTR__glDrawRangeElements_CVA_Exec_00110428;
    ((void (*)())_gleDrawArraysOrElements_CVA_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,fparam_1,fparam_2,fparam_3,fparam_4,
               fparam_5,fparam_6,fparam_7,fparam_8);
    return;
  }
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x104) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x104) =
       PTR__glDrawArrays_IMM_Exec_00110424;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x10c) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x10c) =
       PTR__glDrawElements_IMM_Exec_00110420;
  uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x654) == 0);
  *(undefined **)
   ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0x654) =
       PTR__glDrawRangeElements_IMM_Exec_0011041c;
  ((void (*)())_gleDrawArraysOrElements_IMM_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,fparam_1,fparam_2,fparam_3,fparam_4,
             fparam_5,fparam_6,fparam_7,fparam_8);
  return;
}

/* _gleDrawArraysOrElements_IMM_Exec @ 0x4d89c (1024 bytes) */
void _gleDrawArraysOrElements_IMM_Exec(int param_1,uint param_2,undefined4 param_3,int param_4,undefined4 param_5,int param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int *piVar13;
  short *psVar14;
  double extraout_f1;
  longlong lVar15;
  
  if (-1 < *(short *)(param_1 + 0x4a10)) {
LAB_0004d920:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
    goto LAB_0004db4c;
  }
  if (9 < param_2) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x500;
    goto LAB_0004db4c;
  }
  if (param_4 < 0) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x501;
    goto LAB_0004db4c;
  }
  if ((*(char *)(param_1 + 0x4664) != '\0') && (*(int *)(*(int *)(param_1 + 0x5420) + 0x4cc) == 0))
  goto LAB_0004d920;
  if ((*(uint *)(param_6 + 800) & 1) == 0 && (*(uint *)(param_6 + 0x324) & 0x10000) == 0) {
    return;
  }
  if (param_4 == 0) {
    return;
  }
  iVar8 = *(int *)(param_1 + 0x50ac);
  uVar3 = param_3;
  iVar9 = param_4;
  iVar4 = param_6;
  if (iVar8 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(param_1);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(param_1 + 0x4691) == '\0') goto LAB_0004db78;
  iVar7 = *(int *)(param_1 + 0x744c);
  piVar13 = (int *)(param_1 + 0x310);
  cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
  if ((iVar7 != 0) && (*(int *)(iVar7 + 0xec) != 0)) {
    ((void (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar7 + 0x10,uVar3,iVar9,param_5,iVar4,iVar8,fparam_1,fparam_2,fparam_3,
               fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
  }
  if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_0004da50:
    uVar10 = *(uint *)(param_1 + 0x31c);
  }
  else {
    iVar9 = 0;
    piVar6 = (int *)(param_1 + 0x324);
    do {
      iVar4 = *piVar6;
      piVar6 = piVar6 + 1;
      if (iVar4 != 0) {
        *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
        break;
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < 9);
    uVar10 = *(uint *)(param_1 + 0x31c);
    if ((uVar10 & 0x15555) != 0) {
      if (*(char *)(param_1 + 0x2e54) != '\0') {
        _gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
      }
      if (*(char *)(param_1 + 0x3094) != '\0') {
        _gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
      }
      goto LAB_0004da50;
    }
  }
  bVar1 = cVar2 == '\0';
  if (bVar1) {
    uVar10 = uVar10 & 0x17000000;
  }
  else {
    uVar10 = uVar10 & 0x17ffffff;
  }
  if (bVar1) {
    bVar1 = ((*piVar13 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar10 == 0) &&
            *(int *)(param_1 + 800) == 0;
  }
  else {
    bVar1 = (((*piVar13 == 0 && *(int *)(param_1 + 0x314) == 0) &&
             (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar10 == 0) &&
            *(int *)(param_1 + 800) == 0;
  }
  if (!bVar1) {
    if (*(char *)(param_1 + 0x85a8) == *(char *)(param_1 + 0x85a6)) {
      uVar10 = (**(code **)(param_1 + 0x4788))
                         (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar13);
      if ((((uVar10 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
          ((uVar10 & 4) != (uint)*(byte *)(param_1 + 0x7581))) ||
         ((uVar10 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0'))) {
        if ((uVar10 & 4) == 0) {
          uVar10 = uVar10 & 0xfffffffe;
          *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
        }
        _gleUpdateDispatchCodeChange(param_1,uVar10);
        if (*(char *)(param_1 + 0x759d) == '\0') {
          if (*(int *)(param_1 + 0x7574) != 0) {
            return;
          }
          uVar3 = 0x506;
LAB_0004db4c:
          *(undefined4 *)(param_1 + 0x7574) = uVar3;
          return;
        }
      }
    }
    else {
      _gleSwitchToNonRevertRenderer(param_1);
    }
    iVar9 = 0x13;
    do {
      *piVar13 = 0;
      piVar13 = piVar13 + 1;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
LAB_0004db78:
  uVar10 = 0;
  if (*(char *)(param_1 + 0x7580) != '\0') {
LAB_0004dc00:
    iVar9 = *(int *)(param_1 + 0x4890);
    if (iVar9 == 0) {
      iVar9 = ((int (*)())_gleGetVertexArrayFunc)(param_1);
      *(int *)(param_1 + 0x4890) = iVar9;
    }
    *(int *)(param_1 + 0x4a14) = param_4;
    ((void (*)())_gleDrawArraysOrElements_Core)(param_1,param_2,param_3,param_4,uVar10,*(uint *)(param_6 + 0x324) >> 0x12 & 1,
               param_6 + 0x20,iVar9);
    *(undefined4 *)(param_1 + 0x4a14) = 0;
    if (*(int *)(param_6 + 0x328) == 0 && *(int *)(param_6 + 0x32c) == 0) {
      return;
    }
    _gleUpdateDrawArraysFuncs(param_1);
    return;
  }
  uVar11 = *(uint *)(param_1 + 0x514c);
  uVar12 = 0;
  psVar14 = (short *)(param_6 + 0xea);
  do {
    uVar5 = uVar11 >> (uVar12 & 0x3f);
    if ((uVar5 & 1) == 0) {
      if (uVar5 == 0) goto LAB_0004dc00;
    }
    else {
      lVar15 = ___ashldi3(0,0x1000000,uVar12);
      if ((*(uint *)(param_6 + 800) & (uint)((ulonglong)lVar15 >> 0x20)) != 0 ||
          (*(uint *)(param_6 + 0x324) & (uint)lVar15) != 0) {
        if (*psVar14 == 4) {
          uVar10 = 3;
        }
        else if (*psVar14 == 3) {
          uVar10 = uVar10 | 1;
        }
      }
    }
    uVar12 = uVar12 + 1;
    psVar14 = psVar14 + 0xc;
  } while( true );
}

/* _gleGetVertexArrayFunc @ 0x4dcd4 (68 bytes) */
int _gleGetVertexArrayFunc(param_1)
  undefined4 param_1;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(*_gleBuildVertexFunc)(param_1,1);
  return *puVar1;
}

/* _gleSetFunctionIDFromArray @ 0x4dd18 (532 bytes) */
void _gleSetFunctionIDFromArray(param_1, param_2, param_3)
  int param_1;
  int param_2;
  uint *param_3;
{
  ushort uVar1;
  uint uVar2;
  ushort uVar4;
  uint uVar3;
  int iVar5;
  int iVar6;
  int iVar7;
  ushort uVar8;
  ushort *puVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  longlong lVar13;
  
  iVar7 = *(int *)(param_1 + 0x48dc);
  iVar5 = *(int *)(param_1 + 0x4674);
  uVar2 = iVar7 - 0x1400;
  uVar10 = *(uint *)(param_2 + 0x300);
  uVar11 = *(uint *)(param_2 + 0x304);
  if (((6 < uVar2) && (uVar2 = 7, iVar7 != 0x140a)) && (uVar2 = iVar7 - 0x93f8, 5 < iVar7 - 0x9400U)
     ) {
    uVar2 = 0xe;
  }
  uVar2 = *param_3 | (uVar2 & 0xf) << 0x10;
  *param_3 = uVar2;
  if (*(char *)(param_2 + 0x31c) != '\0') {
    *param_3 = uVar2 | 0x800000;
  }
  uVar2 = (uint)*(byte *)param_3;
  if (uVar2 != 0) {
    puVar9 = (ushort *)((int)param_3 + uVar2 * 2 + 4);
    do {
      uVar4 = *(ushort *)(param_3 + 1);
      uVar12 = 0;
      uVar3 = (uint)(uVar4 >> 10);
      if ((uVar3 == 0) || (uVar3 == 0x10)) {
        lVar13 = ___ashldi3(0,1,uVar3 + 0x10);
        if ((uVar10 & (uint)((ulonglong)lVar13 >> 0x20)) == 0 && (uVar11 & (uint)lVar13) == 0) {
          if ((uVar11 & 0x10000) == 0) {
            if ((uVar10 & 1) == 0) goto LAB_0004de9c;
            iVar7 = *(int *)(param_2 + 0x184);
            uVar8 = *(ushort *)(param_2 + 0x18a);
            uVar4 = uVar4 & 0x3ff | 0x4000;
            uVar1 = *(ushort *)(param_2 + 0x188);
          }
          else {
            uVar4 = uVar4 & 0x3ff;
            iVar7 = *(int *)(param_2 + 4);
            uVar8 = *(ushort *)(param_2 + 10);
            uVar1 = *(ushort *)(param_2 + 8);
          }
          uVar12 = (uint)uVar1;
          *(ushort *)(param_3 + 1) = uVar4;
        }
        else {
LAB_0004de6c:
          iVar6 = uVar3 * 0x18 + param_2;
          uVar12 = (uint)*(ushort *)(iVar6 + 8);
          iVar7 = *(int *)(iVar6 + 4);
          uVar8 = *(ushort *)(iVar6 + 10);
        }
      }
      else if (uVar3 < 0x20) {
        lVar13 = ___ashldi3(0,1,uVar3 + 0x10);
        if ((uVar10 & (uint)((ulonglong)lVar13 >> 0x20)) != 0 || (uVar11 & (uint)lVar13) != 0)
        goto LAB_0004de6c;
        uVar8 = (ushort)*(byte *)(iVar5 + 0x400 + uVar3);
        iVar7 = 0;
      }
      else if (uVar3 - 0x20 < 8) {
LAB_0004de9c:
        iVar7 = 0;
        uVar8 = 0;
      }
      else {
        iVar7 = 0;
        uVar8 = 1;
      }
      uVar3 = uVar12 - 0x1400;
      if (((6 < uVar3) && (uVar3 = 7, uVar12 != 0x140a)) &&
         (uVar3 = uVar12 - 0x93f8, 5 < uVar12 - 0x9400)) {
        uVar3 = 0xe;
      }
      if (0x3ff < iVar7) {
        iVar7 = 0x3ff;
      }
      uVar2 = uVar2 - 1;
      param_3 = (uint *)((int)param_3 + 2);
      *puVar9 = (uVar8 - 1) * 0x4000 | (ushort)(uVar3 << 10) | (ushort)iVar7;
      puVar9 = puVar9 + 1;
    } while (uVar2 != 0);
  }
  return;
}

/* _gleSetArrayLoadAddressNO @ 0x4df2c (504 bytes) */
int _gleSetArrayLoadAddressNO(param_1, param_2, param_3, param_4)
  uint *param_1;
  int param_2;
  uint param_3;
  uint param_4;
{
  uint uVar1;
  uint uVar2;
  
  if (param_4 == 0x3ff) {
    *param_1 = param_3 & 0xffff | 0x81030000;
    param_1[1] = param_3 + 4 & 0xffff | 0x81240000;
    param_1[2] = 0x7d2649d6;
    param_1[3] = 0x7ce84a14;
    return param_1 + 4;
  }
  uVar2 = 0x1f - LZCOUNT(param_4);
  uVar1 = param_3 & 0xffff;
  *param_1 = uVar1 | 0x81030000;
  if ((param_4 & (-2 << (uVar2 & 0x1f) | 0xfffffffeU >> 0x20 - (uVar2 & 0x1f))) == 0) {
    uVar2 = uVar2 * 0x800 | 0xc90000 | (0x1f - uVar2) * 2 | 0x54000000;
  }
  else {
    uVar2 = param_4 & 0xffff | 0x1d260000;
  }
  param_1[1] = uVar2;
  param_1[2] = 0x7ce84a14;
  switch((int)param_1 - param_2 >> 2) {
  case 0:
    *param_1 = uVar1 | 0x81030000;
    param_1[1] = param_4 & 0xffff | 0x1d260000;
    break;
  case 1:
    param_1[1] = param_1[-1];
    param_1[-1] = uVar1 | 0x81030000;
    *param_1 = param_4 & 0xffff | 0x1d260000;
    break;
  case 2:
    param_1[2] = param_1[-1];
    *param_1 = param_1[-2];
    param_1[-2] = uVar1 | 0x81030000;
    goto LAB_0004e0e0;
  case 3:
    param_1[2] = param_1[-1];
    *param_1 = param_1[-2];
    param_1[-2] = param_1[-3];
    param_1[-3] = uVar1 | 0x81030000;
LAB_0004e0e0:
    param_1[-1] = param_4 & 0xffff | 0x1d260000;
    param_1[1] = 0x7ce84a14;
    goto LAB_0004e12c;
  default:
    param_1[2] = param_1[-1];
    *param_1 = param_1[-2];
    param_1[-1] = param_1[-3];
    param_1[-3] = param_1[-4];
    param_1[-4] = uVar1 | 0x81030000;
    param_1[-2] = param_4 & 0xffff | 0x1d260000;
    param_1[1] = 0x7ce84a14;
    goto LAB_0004e12c;
  }
  param_1[2] = 0x7ce84a14;
LAB_0004e12c:
  return param_1 + 3;
}

/* _gleLoadDataElementNO @ 0x4e138 (2516 bytes) */
int _gleLoadDataElementNO(param_1, param_2, param_3, param_4, param_5)
  uint *param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
  int param_5;
{
  uint uVar1;
  uint uVar2;
  undefined *puVar3;
  int iVar4;
  uint *puVar5;
  
  if (param_4 == 1) {
    if (param_5 == 0) {
      if (param_2 == 2) {
LAB_0004e33c:
        uVar1 = 0xa0070000;
      }
      else {
        if (2 < param_2) {
          if (param_2 != 3) {
            if (param_2 != 4) {
              return param_1;
            }
            goto LAB_0004e344;
          }
          uVar1 = 0xa0070000;
          uVar2 = 0x89470002;
          goto LAB_0004e360;
        }
        if (param_2 != 1) {
          return param_1;
        }
        uVar1 = 0x88070000;
      }
    }
    else {
      if (param_2 == 2) {
        uVar1 = 0x39400002;
        uVar2 = 0x7c0a3e2c;
LAB_0004e360:
        *param_1 = uVar1;
LAB_0004e364:
        param_1 = param_1 + 1;
        *param_1 = uVar2;
        goto LAB_0004e368;
      }
      if (param_2 < 3) {
        if (param_2 != 1) {
          return param_1;
        }
        uVar1 = 0x88070003;
      }
      else {
        if (param_2 == 3) {
          *param_1 = 0x39400002;
          uVar2 = 0x89470001;
          param_1 = param_1 + 1;
          *param_1 = 0x7c0a3e2c;
          goto LAB_0004e364;
        }
        if (param_2 != 4) {
          return param_1;
        }
        uVar1 = 0x7c003c2c;
      }
    }
LAB_0004e1e4:
    *param_1 = uVar1;
LAB_0004e368:
    return param_1 + 1;
  }
  if (param_4 == 2) {
    if (param_5 == 0) {
      if (param_2 != 2) {
        if (param_2 < 3) {
          if (param_2 != 1) {
            return param_1;
          }
          goto LAB_0004e33c;
        }
        if (param_2 == 3) {
          uVar2 = 0xa1470000;
        }
        else {
          if (param_2 != 4) {
            return param_1;
          }
          uVar2 = 0x81470000;
        }
        uVar2 = uVar2 | 4;
        uVar1 = 0x80070000;
        goto LAB_0004e360;
      }
LAB_0004e344:
      uVar1 = 0x80070000;
    }
    else {
      if (param_2 == 2) {
        *param_1 = 0xa1470002;
        param_1[1] = 0xa0070000;
        param_1 = param_1 + 2;
        *param_1 = 0x5140801e;
        goto LAB_0004e368;
      }
      if (2 < param_2) {
        if (param_2 == 3) {
          *param_1 = 0xa1470002;
          param_1[1] = 0xa0070000;
          puVar5 = param_1 + 2;
          *puVar5 = 0x5140801e;
          uVar1 = 0xa1470006;
        }
        else {
          if (param_2 != 4) {
            return param_1;
          }
          *param_1 = 0xa1070002;
          param_1[1] = 0xa0070000;
          param_1[2] = 0x5100801e;
          param_1[3] = 0xa1070006;
          puVar5 = param_1 + 4;
          *puVar5 = 0xa1470004;
          uVar1 = 0x510a801e;
        }
        param_1 = puVar5 + 1;
        *param_1 = uVar1;
        goto LAB_0004e368;
      }
      if (param_2 != 1) {
        return param_1;
      }
      uVar1 = 0xa0070002;
    }
    goto LAB_0004e1e4;
  }
  switch(param_3) {
  case 0:
  case 8:
    if (param_5 == 0) {
      if (param_2 == 2) {
        puVar3 = &_gleLoadByte2RTC;
      }
      else if (param_2 < 3) {
        if (param_2 != 1) goto switchD_0004e390_default;
        puVar3 = &_gleLoadByte1RTC;
      }
      else if (param_2 == 3) {
        puVar3 = &_gleLoadByte3RTC;
      }
      else {
        if (param_2 != 4) goto switchD_0004e390_default;
        puVar3 = &_gleLoadByte4RTC;
      }
    }
    else if (param_2 == 2) {
      puVar3 = &_gleLoadByte2RevRTC;
    }
    else if (param_2 < 3) {
      if (param_2 != 1) goto switchD_0004e390_default;
      puVar3 = &_gleLoadByte1RevRTC;
    }
    else if (param_2 == 3) {
      puVar3 = &_gleLoadByte3RevRTC;
    }
    else {
      if (param_2 != 4) goto switchD_0004e390_default;
      puVar3 = &_gleLoadByte4RevRTC;
    }
    break;
  case 1:
  case 9:
    if (param_5 == 0) {
      if (param_2 == 2) {
        puVar3 = &_gleLoadUByte2RTC;
      }
      else if (param_2 < 3) {
        if (param_2 != 1) goto switchD_0004e390_default;
        puVar3 = &_gleLoadUByte1RTC;
      }
      else if (param_2 == 3) {
        puVar3 = &_gleLoadUByte3RTC;
      }
      else {
        if (param_2 != 4) goto switchD_0004e390_default;
        puVar3 = &_gleLoadUByte4RTC;
      }
    }
    else if (param_2 == 2) {
      puVar3 = &_gleLoadUByte2RevRTC;
    }
    else if (param_2 < 3) {
      if (param_2 != 1) goto switchD_0004e390_default;
      puVar3 = &_gleLoadUByte1RevRTC;
    }
    else if (param_2 == 3) {
      puVar3 = &_gleLoadUByte3RevRTC;
    }
    else {
      if (param_2 != 4) goto switchD_0004e390_default;
      puVar3 = &_gleLoadUByte4RevRTC;
    }
    break;
  case 2:
  case 10:
    if (param_5 == 0) {
      if (param_2 == 2) {
        puVar3 = &_gleLoadShort2RTC;
      }
      else if (param_2 < 3) {
        if (param_2 != 1) goto switchD_0004e390_default;
        puVar3 = &_gleLoadShort1RTC;
      }
      else if (param_2 == 3) {
        puVar3 = &_gleLoadShort3RTC;
      }
      else {
        if (param_2 != 4) goto switchD_0004e390_default;
        puVar3 = &_gleLoadShort4RTC;
      }
    }
    else if (param_2 == 2) {
      puVar3 = &_gleLoadShort2RevRTC;
    }
    else if (param_2 < 3) {
      if (param_2 != 1) goto switchD_0004e390_default;
      puVar3 = &_gleLoadShort1RevRTC;
    }
    else if (param_2 == 3) {
      puVar3 = &_gleLoadShort3RevRTC;
    }
    else {
      if (param_2 != 4) goto switchD_0004e390_default;
      puVar3 = &_gleLoadShort4RevRTC;
    }
    break;
  case 3:
  case 0xb:
    if (param_5 == 0) {
      if (param_2 == 2) {
        puVar3 = &_gleLoadUShort2RTC;
      }
      else if (param_2 < 3) {
        if (param_2 != 1) goto switchD_0004e390_default;
        puVar3 = &_gleLoadUShort1RTC;
      }
      else if (param_2 == 3) {
        puVar3 = &_gleLoadUShort3RTC;
      }
      else {
        if (param_2 != 4) goto switchD_0004e390_default;
        puVar3 = &_gleLoadUShort4RTC;
      }
    }
    else if (param_2 == 2) {
      puVar3 = &_gleLoadUShort2RevRTC;
    }
    else if (param_2 < 3) {
      if (param_2 != 1) goto switchD_0004e390_default;
      puVar3 = &_gleLoadUShort1RevRTC;
    }
    else if (param_2 == 3) {
      puVar3 = &_gleLoadUShort3RevRTC;
    }
    else {
      if (param_2 != 4) goto switchD_0004e390_default;
      puVar3 = &_gleLoadUShort4RevRTC;
    }
    break;
  case 4:
  case 0xc:
    if (param_2 == 2) {
      puVar3 = &_gleLoadInt2RTC;
    }
    else if (param_2 < 3) {
      if (param_2 != 1) goto switchD_0004e390_default;
      puVar3 = &_gleLoadInt1RTC;
    }
    else if (param_2 == 3) {
      puVar3 = &_gleLoadInt3RTC;
    }
    else {
      if (param_2 != 4) goto switchD_0004e390_default;
      puVar3 = &_gleLoadInt4RTC;
    }
    break;
  case 5:
  case 0xd:
    if (param_2 == 2) {
      puVar3 = &_gleLoadUInt2RTC;
    }
    else if (param_2 < 3) {
      if (param_2 != 1) goto switchD_0004e390_default;
      puVar3 = &_gleLoadUInt1RTC;
    }
    else if (param_2 == 3) {
      puVar3 = &_gleLoadUInt3RTC;
    }
    else {
      if (param_2 != 4) goto switchD_0004e390_default;
      puVar3 = &_gleLoadUInt4RTC;
    }
    break;
  case 6:
    if (param_2 == 2) {
      if (param_4 == 4) {
        uVar1 = 0xc8270000;
        goto LAB_0004e7c4;
      }
      uVar1 = 0xc0270000;
      uVar2 = 0xc0470004;
LAB_0004e828:
      *param_1 = uVar1;
      param_1 = param_1 + 1;
      *param_1 = uVar2;
LAB_0004e860:
      param_1 = param_1 + 1;
    }
    else if (param_2 < 3) {
      if (param_2 == 1) {
        uVar1 = 0xc0270000;
LAB_0004e7c4:
        *param_1 = uVar1;
        goto LAB_0004e860;
      }
    }
    else {
      if (param_2 == 3) {
        if (param_4 == 4) {
          *param_1 = 0xc8270000;
        }
        else {
          *param_1 = 0xc0270000;
          param_1 = param_1 + 1;
          *param_1 = 0xc0470004;
        }
        param_1 = param_1 + 1;
        uVar1 = 0xc0670008;
        goto LAB_0004e7c4;
      }
      if (param_2 == 4) {
        if (param_4 == 4) {
          uVar1 = 0xc8270000;
          uVar2 = 0xc8670008;
          goto LAB_0004e828;
        }
        *param_1 = 0xc0270000;
        param_1[1] = 0xc0470004;
        param_1[2] = 0xc0670008;
        param_1 = param_1 + 3;
        *param_1 = 0xc087000c;
        goto LAB_0004e860;
      }
    }
    goto switchD_0004e390_default;
  case 7:
    if (param_2 == 2) {
      puVar3 = &_gleLoadDouble2RTC;
    }
    else if (param_2 < 3) {
      if (param_2 != 1) goto switchD_0004e390_default;
      puVar3 = &_gleLoadDouble1RTC;
    }
    else if (param_2 == 3) {
      puVar3 = &_gleLoadDouble3RTC;
    }
    else {
      if (param_2 != 4) goto switchD_0004e390_default;
      puVar3 = &_gleLoadDouble4RTC;
    }
    break;
  default:
    goto switchD_0004e390_default;
  }
  iVar4 = _gleRTCAddAChunk_b50a8(puVar3,param_1);
  param_1 = param_1 + iVar4;
switchD_0004e390_default:
  switch(param_3) {
  case 8:
    if (param_2 == 2) {
      puVar3 = &_gleNormalizeByte2RTC;
    }
    else if (param_2 < 3) {
      if (param_2 != 1) {
        return param_1;
      }
      puVar3 = &_gleNormalizeByte1RTC;
    }
    else if (param_2 == 3) {
      puVar3 = &_gleNormalizeByte3RTC;
    }
    else {
      if (param_2 != 4) {
        return param_1;
      }
      puVar3 = &_gleNormalizeByte4RTC;
    }
    break;
  case 9:
    if (param_2 == 2) {
      puVar3 = &_gleNormalizeUByte2RTC;
    }
    else if (param_2 < 3) {
      if (param_2 != 1) {
        return param_1;
      }
      puVar3 = &_gleNormalizeUByte1RTC;
    }
    else if (param_2 == 3) {
      puVar3 = &_gleNormalizeUByte3RTC;
    }
    else {
      if (param_2 != 4) {
        return param_1;
      }
      puVar3 = &_gleNormalizeUByte4RTC;
    }
    break;
  case 10:
    if (param_2 == 2) {
      puVar3 = &_gleNormalizeShort2RTC;
    }
    else if (param_2 < 3) {
      if (param_2 != 1) {
        return param_1;
      }
      puVar3 = &_gleNormalizeShort1RTC;
    }
    else if (param_2 == 3) {
      puVar3 = &_gleNormalizeShort3RTC;
    }
    else {
      if (param_2 != 4) {
        return param_1;
      }
      puVar3 = &_gleNormalizeShort4RTC;
    }
    break;
  case 0xb:
    if (param_2 == 2) {
      puVar3 = &_gleNormalizeUShort2RTC;
    }
    else if (param_2 < 3) {
      if (param_2 != 1) {
        return param_1;
      }
      puVar3 = &_gleNormalizeUShort1RTC;
    }
    else if (param_2 == 3) {
      puVar3 = &_gleNormalizeUShort3RTC;
    }
    else {
      if (param_2 != 4) {
        return param_1;
      }
      puVar3 = &_gleNormalizeUShort4RTC;
    }
    break;
  case 0xc:
    if (param_2 == 2) {
      puVar3 = &_gleNormalizeInt2RTC;
    }
    else if (param_2 < 3) {
      if (param_2 != 1) {
        return param_1;
      }
      puVar3 = &_gleNormalizeInt1RTC;
    }
    else if (param_2 == 3) {
      puVar3 = &_gleNormalizeInt3RTC;
    }
    else {
      if (param_2 != 4) {
        return param_1;
      }
      puVar3 = &_gleNormalizeInt4RTC;
    }
    break;
  case 0xd:
    if (param_2 == 2) {
      puVar3 = &_gleNormalizeUInt2RTC;
    }
    else if (param_2 < 3) {
      if (param_2 != 1) {
        return param_1;
      }
      puVar3 = &_gleNormalizeUInt1RTC;
    }
    else if (param_2 == 3) {
      puVar3 = &_gleNormalizeUInt3RTC;
    }
    else {
      if (param_2 != 4) {
        return param_1;
      }
      puVar3 = &_gleNormalizeUInt4RTC;
    }
    break;
  default:
    goto switchD_0004e8f4_default;
  }
  iVar4 = _gleRTCAddAChunk_b50a8(puVar3,param_1);
  param_1 = param_1 + iVar4;
switchD_0004e8f4_default:
  return param_1;
}

/* _gleArrayIncAndStoreVertexLoop @ 0x4eb5c (224 bytes) */
int _gleArrayIncAndStoreVertexLoop(param_1, param_2, param_3, param_4)
  uint *param_1;
  int param_2;
  uint param_3;
  undefined4 param_4;
{
  uint *puVar1;
  
  *param_1 = param_3 & 0xffff | 0x38a50000;
  puVar1 = param_1 + 1;
  switch(param_4) {
  default:
    (*(volatile unsigned int *)0x0) = 0;
    goto LAB_0004ec20;
  case 1:
  case 3:
  case 5:
    *puVar1 = 0x80c348cc;
    param_1[2] = 0x38c60001;
    puVar1 = param_1 + 3;
    *puVar1 = 0x90c348cc;
    break;
  case 7:
  case 0xe:
    *puVar1 = 0x38c60001;
  }
  puVar1 = puVar1 + 1;
LAB_0004ec20:
  *puVar1 = 0x810348c8;
  puVar1[1] = 0x7c054000;
  puVar1[2] = param_2 - (int)(puVar1 + 2) & 0xfffcU | 0x40820000;
  puVar1[3] = 0x90c348cc;
  puVar1[4] = 0x90a34858;
  puVar1[5] = 0x7ca32b78;
  return puVar1 + 6;
}

/* _gleDrawArraysOrElements_Core @ 0x4ec78 (532 bytes) */
void _gleDrawArraysOrElements_Core(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  undefined4 param_5;
  int param_6;
  undefined4 param_7;
  code *param_8;
{
  uint uVar1;
  uint uVar2;
  short sVar3;
  code *pcVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  
  pcVar4 = *(code **)(param_2 * 4 + param_1 + 0x49e0);
  *(short *)(param_1 + 0x4a10) = (short)param_2;
  iVar5 = param_4 + param_3;
  (*pcVar4)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  *(undefined4 *)(param_1 + 0x486c) = param_5;
  if ((((*(char *)(param_1 + 0x7580) == '\0') && (param_6 != 0)) &&
      (*(char *)(param_1 + 0x4664) == '\0')) &&
     ((*(char *)(param_1 + 0x30aa) != '\0' && (*(char *)(param_1 + 0x30ab) != '\0')))) {
    if (*(short *)(param_1 + 0x30a4) == 0x404) {
      uVar7 = 0;
      uVar1 = 0;
    }
    else if (*(short *)(param_1 + 0x30a4) == 0x405) {
      uVar7 = 1;
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
      uVar7 = 1;
    }
    while( true ) {
      sVar3 = *(short *)(param_1 + 0x487c);
      uVar10 = *(uint *)(param_1 + 0x4858);
      uVar8 = uVar10 + (iVar5 - param_3) * (int)sVar3;
      iVar6 = param_3;
      uVar9 = *(uint *)(param_1 + 0x485c);
      if (uVar8 < *(uint *)(param_1 + 0x485c)) {
        uVar9 = uVar8;
      }
      while( true ) {
        *(uint *)(param_1 + 0x48c8) = uVar10 + (int)sVar3;
        param_3 = iVar6 + 1;
        uVar2 = (*param_8)(param_1,param_7,uVar10,iVar6);
        (**(code **)(param_1 + 0x4de0))(param_1,uVar10 + 0x30);
        if (uVar2 == uVar9) break;
        uVar10 = uVar1;
        if (uVar1 <= uVar7) {
          do {
            uVar11 = uVar10 + 1;
            _gleForcePushMaterial(param_1,uVar10);
            uVar10 = uVar11;
          } while ((int)uVar11 <= (int)uVar7);
        }
        sVar3 = *(short *)(param_1 + 0x487c);
        iVar6 = param_3;
        uVar10 = uVar2;
      }
      if (uVar2 == uVar8) break;
      (**(code **)(param_1 + 0x4a0c))(param_1);
    }
  }
  else {
    while( true ) {
      uVar7 = *(int *)(param_1 + 0x4858) + (iVar5 - param_3) * (int)*(short *)(param_1 + 0x487c);
      uVar1 = *(uint *)(param_1 + 0x485c);
      if (uVar7 < *(uint *)(param_1 + 0x485c)) {
        uVar1 = uVar7;
      }
      *(uint *)(param_1 + 0x48c8) = uVar1;
      uVar1 = (*param_8)(param_1,param_7,*(int *)(param_1 + 0x4858),param_3);
      if (uVar1 == uVar7) break;
      (**(code **)(param_1 + 0x4a0c))(param_1);
      param_3 = *(int *)(param_1 + 0x48cc);
    }
  }
  *(undefined2 *)(param_1 + 0x4a10) = 0xffff;
  (**(code **)(param_1 + 0x4a08))(param_1);
  _glePopAndCopyMaterials(param_1);
  return;
}

/* _gleFlushAtomicTCLFunc @ 0x4ee8c (60 bytes) */
void _gleFlushAtomicTCLFunc(param_1)
  int param_1;
{
  (**(code **)(param_1 + 0x4a08))(param_1);
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  return;
}

/* _gleFlushAndSubmit @ 0x4eec8 (116 bytes) */
void _gleFlushAndSubmit(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  (**(code **)(param_1 + 0x4a0c))(param_1);
                    
                    
  (**(int ( **)(int,double,double,double,double))(param_1 + 0x4884))(param_1, fparam_1, fparam_2, fparam_3, fparam_4);
  return;
}

/* _glVertexArrayRangeEXT_Exec @ 0x4ef3c (188 bytes) */
void _glVertexArrayRangeEXT_Exec(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x4a60);
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
    }
    return;
  }
  if ((*(int *)(iVar1 + 0x348) != param_2) || (*(int *)(iVar1 + 0x344) != param_3)) {
    _gleUpdateDrawArraysFuncs(param_1);
    *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x100000;
    *(int *)(iVar1 + 0x348) = param_2;
    *(int *)(iVar1 + 0x344) = param_3;
  }
  *(undefined4 *)(iVar1 + 0x350) = *(undefined4 *)(iVar1 + 0x350);
  *(uint *)(iVar1 + 0x354) = *(uint *)(iVar1 + 0x354) | 1;
  ((void (*)())_gleModifyPluginVertexArray)(param_1,iVar1 + 0x10);
  return;
}

/* _gleModifyPluginVertexArray @ 0x4eff8 (184 bytes) */
void _gleModifyPluginVertexArray(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  
  uVar6 = param_2[0xd0];
  uVar7 = param_2[0xd1];
  iVar4 = param_1 + 0x10000;
  param_2[0xd0] = 0;
  param_2[0xd1] = 0;
  iVar5 = 0;
  if (*(char *)(param_1 + 0x85a4) != '\0') {
    puVar8 = param_2 + 0x114;
    do {
      iVar5 = iVar5 + 1;
      puVar8[1] = puVar8[1] | uVar6;
      puVar8[2] = puVar8[2] | uVar7;
      puVar8 = puVar8 + 0x23;
      piVar1 = (int *)(iVar4 + -0x777c);
      uVar3 = *param_2;
      param_2 = param_2 + 1;
      puVar2 = (undefined4 *)(iVar4 + -0x7a54);
      iVar4 = iVar4 + 0x2e0;
      (**(code **)(*piVar1 + 0x1a8))(*puVar2,uVar3);
    } while (iVar5 < (int)(uint)*(byte *)(param_1 + 0x85a4));
  }
  *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x100000;
  return;
}

