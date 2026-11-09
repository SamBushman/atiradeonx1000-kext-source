#include "decls.h"

/* FUN_0009dbfc @ 0x9dbfc (1068 bytes) */
int FUN_0009dbfc(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  uint param_3;
  undefined *param_4;
  float *param_5;
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
  float *pfVar10;
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
  uint local_38 [5];
  
  uVar11 = param_3;
  puVar9 = param_4;
  pfVar10 = param_5;
  iVar7 = _gleLookUpTexture(param_1,param_2);
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
    goto LAB_0009dd64;
  }
  if (iVar7 == 0) goto LAB_0009dd54;
  if (0xe < param_3) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x501;
    goto LAB_0009dd64;
  }
  uVar4 = param_2 - 0x8515;
  if (5 < uVar4) {
    uVar4 = 0;
  }
  iVar5 = iVar7 + uVar4 * 0x168 + param_3 * 0x18;
  if ((undefined *)0x8061 < param_4) {
    if (param_4 < (undefined *)0x86a2) {
      if ((undefined *)0x869f < param_4) {
LAB_0009dd4c:
        local_38[0] = 0xffffffff;
        goto LAB_0009dd7c;
      }
      if (param_4 == (undefined *)0x8071) {
        local_38[0] = (uint)*(ushort *)(iVar5 + 0xcc);
        goto LAB_0009dd7c;
      }
    }
    else if (param_4 == (undefined *)0x884a) goto LAB_0009dd4c;
LAB_0009dd54:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x500;
LAB_0009dd64:
    *(undefined4 *)(param_1 + 0x7574) = uVar3;
    return;
  }
  if ((undefined *)0x805b < param_4) goto LAB_0009dd4c;
  if (param_4 != ((unsigned char *)0x00001001)) {
    if (((unsigned char *)0x00001001) < param_4) {
      if (param_4 == ((unsigned char *)0x00001003)) goto LAB_0009dd4c;
      if (param_4 == ((unsigned char *)0x00001005)) {
        local_38[0] = (uint)*(byte *)(iVar5 + 0xce);
        goto LAB_0009dd7c;
      }
    }
    else if (param_4 == (undefined *)0x1000) {
      local_38[0] = (uint)*(ushort *)(iVar5 + 200);
      goto LAB_0009dd7c;
    }
    goto LAB_0009dd54;
  }
  local_38[0] = (uint)*(ushort *)(iVar5 + 0xca);
LAB_0009dd7c:
  if ((*(ushort *)(iVar7 + 0x24) & 0x100) == 0) goto LAB_0009df84;
  iVar5 = *(int *)(param_1 + 0x50ac);
  fparam_1 = extraout_f1;
  if (iVar5 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(param_1);
    fparam_1 = extraout_f1_00;
  }
  if (*(char *)(param_1 + 0x4691) == '\0') goto LAB_0009df84;
  iVar8 = *(int *)(param_1 + 0x744c);
  piVar12 = (int *)(param_1 + 0x310);
  cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
  if ((iVar8 != 0) && (*(int *)(iVar8 + 0xec) != 0)) {
    ((int (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar8 + 0x10,uVar11,puVar9,pfVar10,in_r8,iVar5,fparam_1,in_f2,in_f3,in_f4,
               in_f5,in_f6,in_f7,in_f8);
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
  }
  if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_0009de7c:
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
      goto LAB_0009de7c;
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
LAB_0009df84:
  if ((local_38[0] == 0xffffffff) || ((*(ushort *)(iVar7 + 0x24) & 0x100) != 0)) {
    (**(code **)(param_1 + 0x479c))
              (*(undefined4 *)(param_1 + 0x4688),
               *(undefined4 *)(iVar7 + (uint)*(byte *)(param_1 + 0x85a8) * 4),uVar4,param_3,param_4,
               local_38);
  }
  if ((param_4 == ((unsigned char *)0x00001003)) && (local_38[0] == 0)) {
    local_38[0] = 1;
  }
  *param_5 = (float)((double)CONCAT44(0x43300000,local_38[0] ^ 0x80000000) - DOUBLE_00108d58);
  return;
}

/* _glTexParameterf_ListExec @ 0x9e028 (52 bytes) */
int _glTexParameterf_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glTexParameterF_Exec(param_1,*param_2,param_2[1],param_2 + 2);
  return 0x18;
}

/* _glTexParameterF_Comp @ 0x9e05c (388 bytes) */
int _glTexParameterF_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined *param_3;
  undefined4 *param_4;
{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)_gleAddListItem(param_1,PTR__glTexParameterf_ListExec_001103f0,0x18);
  if (puVar2 == (undefined4 *)0x0) {
    return puVar2;
  }
  *puVar2 = param_2;
  puVar2[1] = param_3;
  if (param_3 == (undefined *)0x8191) goto LAB_0009e1a0;
  if (param_3 < (undefined *)0x8192) {
    if (param_3 == (undefined *)0x8066) goto LAB_0009e1a0;
    if (param_3 < (undefined *)0x8067) {
      if (param_3 == ((unsigned char *)0x00001004)) {
LAB_0009e1ac:
        puVar2[2] = *param_4;
        puVar2[3] = param_4[1];
        puVar2[4] = param_4[2];
        puVar2[5] = param_4[3];
        return puVar2;
      }
      if (param_3 < ((unsigned char *)0x00001004)) {
        return puVar2;
      }
      puVar1 = param_3 + -0x2800;
    }
    else {
      if (param_3 == (undefined *)0x80bf) goto LAB_0009e1a0;
      if (param_3 < (undefined *)0x80c0) {
        puVar1 = (undefined *)0x8072;
        goto LAB_0009e198;
      }
      puVar1 = param_3 + -0x813a;
    }
    if ((undefined *)0x3 < puVar1) {
      return puVar2;
    }
  }
  else {
    if (param_3 == (undefined *)0x85bc) goto LAB_0009e1a0;
    if (param_3 < (undefined *)0x85bd) {
      if (param_3 == (undefined *)0x8501) goto LAB_0009e1a0;
      if (param_3 < (undefined *)0x8502) {
        puVar1 = (undefined *)0x84fe;
      }
      else {
        puVar1 = (undefined *)0x85b6;
      }
    }
    else {
      if (param_3 < (undefined *)0x884e) {
        if (param_3 < (undefined *)0x884b) {
          if (param_3 != (undefined *)0x871a) {
            return puVar2;
          }
          goto LAB_0009e1ac;
        }
        goto LAB_0009e1a0;
      }
      puVar1 = (undefined *)0x8a7f;
    }
LAB_0009e198:
    if (param_3 != puVar1) {
      return puVar2;
    }
  }
LAB_0009e1a0:
  puVar2[2] = *param_4;
  return puVar2;
}

/* _glTexParameterf_Comp @ 0x9e1e0 (40 bytes) */
undefined4 _glTexParameterf_Comp(undefined4 param_1,undefined4 param_2,undefined4 param_3,float fparam_1)
{
  undefined4 uVar1;
  float fStack00000024;
  
  fStack00000024 = (float)fparam_1;
  uVar1 = ((int (*)())_glTexParameterF_Comp)(param_1,param_2,param_3,&STACKARG(0x24));
  return uVar1;
}

/* _glTexParameterf_CompExec @ 0x9e208 (80 bytes) */
void _glTexParameterf_CompExec(undefined4 param_1,undefined4 param_2,undefined4 param_3,double fparam_1)
{
  ((undefined4 (*)())_glTexParameterf_Comp)(param_1,param_2,param_3,fparam_1);
  ((void (*)())_glTexParameterf_Exec)(param_1,param_2,param_3,fparam_1);
  return;
}

/* _glTexParameterfv_CompExec @ 0x9e25c (72 bytes) */
int _glTexParameterfv_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  _glTexParameterfv_Comp(param_1,param_2,param_3,param_4);
  _glTexParameterfv_Exec(param_1,param_2,param_3,param_4);
  return;
}

/* _glTexParameteri_ListExec @ 0x9e2a4 (52 bytes) */
int _glTexParameteri_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glTexParameterI_Exec(param_1,*param_2,param_2[1],param_2 + 2);
  return 0x18;
}

/* _glTexParameterI_Comp @ 0x9e2d8 (388 bytes) */
int _glTexParameterI_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined *param_3;
  undefined4 *param_4;
{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)_gleAddListItem(param_1,PTR__glTexParameteri_ListExec_001103ec,0x18);
  if (puVar2 == (undefined4 *)0x0) {
    return puVar2;
  }
  *puVar2 = param_2;
  puVar2[1] = param_3;
  if (param_3 == (undefined *)0x8191) goto LAB_0009e41c;
  if (param_3 < (undefined *)0x8192) {
    if (param_3 == (undefined *)0x8066) goto LAB_0009e41c;
    if (param_3 < (undefined *)0x8067) {
      if (param_3 == ((unsigned char *)0x00001004)) {
LAB_0009e428:
        puVar2[2] = *param_4;
        puVar2[3] = param_4[1];
        puVar2[4] = param_4[2];
        puVar2[5] = param_4[3];
        return puVar2;
      }
      if (param_3 < ((unsigned char *)0x00001004)) {
        return puVar2;
      }
      puVar1 = param_3 + -0x2800;
    }
    else {
      if (param_3 == (undefined *)0x80bf) goto LAB_0009e41c;
      if (param_3 < (undefined *)0x80c0) {
        puVar1 = (undefined *)0x8072;
        goto LAB_0009e414;
      }
      puVar1 = param_3 + -0x813a;
    }
    if ((undefined *)0x3 < puVar1) {
      return puVar2;
    }
  }
  else {
    if (param_3 == (undefined *)0x85bc) goto LAB_0009e41c;
    if (param_3 < (undefined *)0x85bd) {
      if (param_3 == (undefined *)0x8501) goto LAB_0009e41c;
      if (param_3 < (undefined *)0x8502) {
        puVar1 = (undefined *)0x84fe;
      }
      else {
        puVar1 = (undefined *)0x85b6;
      }
    }
    else {
      if (param_3 < (undefined *)0x884e) {
        if (param_3 < (undefined *)0x884b) {
          if (param_3 != (undefined *)0x871a) {
            return puVar2;
          }
          goto LAB_0009e428;
        }
        goto LAB_0009e41c;
      }
      puVar1 = (undefined *)0x8a7f;
    }
LAB_0009e414:
    if (param_3 != puVar1) {
      return puVar2;
    }
  }
LAB_0009e41c:
  puVar2[2] = *param_4;
  return puVar2;
}

/* _glTexParameteri_Comp @ 0x9e45c (40 bytes) */
int _glTexParameteri_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  unsigned int ghidra_home[8] = { param_1, param_2, param_3, param_4, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  undefined4 uVar1;
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 12)) = param_4;
  uVar1 = ((int (*)())_glTexParameterI_Comp)(param_1,param_2,param_3,&(*(unsigned int *)((unsigned char *)ghidra_home + 12)));
  return uVar1;
}

/* _glTexParameteri_CompExec @ 0x9e484 (72 bytes) */
int _glTexParameteri_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())_glTexParameteri_Comp)(param_1,param_2,param_3,param_4);
  _glTexParameteri_Exec(param_1,param_2,param_3,param_4);
  return;
}

/* _glTexParameteriv_CompExec @ 0x9e4d4 (72 bytes) */
int _glTexParameteriv_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  _glTexParameteriv_Comp(param_1,param_2,param_3,param_4);
  _glTexParameteriv_Exec(param_1,param_2,param_3,param_4);
  return;
}

/* _glGetTexParameterPointervAPPLE_Exec @ 0x9e51c (140 bytes) */
int _glGetTexParameterPointervAPPLE_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  int param_3;
  undefined4 *param_4;
{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = _gleLookUpNonProxyTexture(param_1,param_2);
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if ((iVar2 != 0) && (param_3 == 0x85b8)) {
      *param_4 = *(undefined4 *)(iVar2 + 0x74);
      return;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x500;
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

/* _glTexImage1D_ListExec @ 0x9e5a8 (604 bytes) */
int _glTexImage1D_ListExec(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar7 = param_2[3];
  iVar6 = param_2[1];
  iVar5 = param_2[7] + 0x20;
  iVar4 = _gleCheckTexImage1DArgs
                    (param_1,*param_2,iVar6,param_2[2],iVar7,param_2[4],param_2[5],param_2[6]);
  if (iVar4 != 0) {
    uVar2 = *(ushort *)(iVar4 + 0x24);
    if ((uVar2 & 0x3c00) != 0x1000) {
      if ((uVar2 & 0x3c00) == 0) {
        *(ushort *)(iVar4 + 0x24) = uVar2 | 0x1000;
      }
      else if ((uVar2 & 0xc00) != 0) {
        if (*(int *)(param_1 + 0x7574) != 0) {
          return iVar5;
        }
        *(undefined4 *)(param_1 + 0x7574) = 0x502;
        return iVar5;
      }
    }
    if (((*(uint *)(param_1 + 0x3410) & 1) != 0) && (*(short *)(param_1 + 13000) == -0x7fea)) {
      iVar7 = (iVar7 - *(int *)(param_1 + 0x32d0)) + 1;
    }
    iVar3 = iVar4 + iVar6 * 0x18;
    iVar8 = iVar3 + 0xc4;
    if ((*(byte *)(iVar3 + 0xcf) & 0x20) != 0) {
      _gleDeletePluginTextureLevel(param_1,iVar4,iVar8,0,iVar6);
      if (*(int *)(iVar3 + 0xd8) != 0) {
        bVar1 = *(byte *)(iVar3 + 0xcf);
        if ((bVar1 & 1) == 0) {
          _gleFreeTextureLevel(param_1,iVar4,iVar8);
          bVar1 = *(byte *)(iVar3 + 0xcf);
        }
        else {
          *(undefined4 *)(iVar3 + 0xd8) = 0;
        }
        *(byte *)(iVar3 + 0xcf) = bVar1 & 0xef;
      }
      *(byte *)(iVar3 + 0xcf) = *(byte *)(iVar3 + 0xcf) & 0xdf;
    }
    iVar7 = _gleCreateTextureLevel
                      (param_1,iVar4,iVar8,param_2[2],iVar7,1,1,param_2[4],param_2[5],param_2[6],0,
                       param_2 + 8);
    if (iVar7 != 0) {
      _gleTextureImagePut(param_1,iVar8,0,0,0,param_2[3],1,1,param_2[5],param_2[6],1,0,param_2 + 8);
    }
    _gleCreatePluginTextureLevel(param_1,iVar4,iVar8,0,iVar6,param_2[2]);
    if ((((*(uint *)(iVar4 + 0x6c) & 0x8000) == 0) || (*(short *)(iVar4 + 0x60) != iVar6)) ||
       (iVar4 = _gleGenMipmapsToLevel(param_1,iVar4,0,iVar6,0xf,1), iVar4 == 0)) {
      *(uint *)(param_1 + 0x314) =
           *(uint *)(param_1 + 0x314) | 1 << (*(uint *)(param_1 + 0x53d4) & 0x3f);
    }
  }
  return iVar5;
}

/* _glTexImage1D_Comp @ 0x9e804 (664 bytes) */
int _glTexImage1D_Comp(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
  uint param_7;
  uint param_8;
  int param_9;
{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  double dVar9;
  
  iVar8 = *(int *)(param_1 + 0x4a6c);
  iVar5 = param_1;
  if (iVar8 != 0) {
    iVar4 = _gleOffsetLimitImage(param_1 + 0x31cc,param_5,1,param_7,param_8,param_9);
    iVar7 = *(int *)(iVar8 + 0x38);
    dVar9 = (double)((double (*)())_gleBytesPerElement)(param_8);
    iVar5 = (int)dVar9;
    if (iVar4 <= iVar7) {
      if (iVar5 == 0) {
        iVar5 = _glePixelBytes(param_7,param_8);
      }
      if (param_9 == (param_9 / iVar5) * iVar5) {
        if (*(int *)(iVar8 + 0x40) != 0) {
          iVar5 = _gleSynchronizePluginBuffer(param_1,iVar8 + 0x10);
        }
        param_9 = param_9 + *(int *)(iVar8 + 0x30);
        goto LAB_0009e8e4;
      }
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return iVar5;
    }
    uVar3 = 0x502;
    goto LAB_0009e9f8;
  }
LAB_0009e8e4:
  if (param_2 == 0x8063) {
    uVar3 = ((int (*)())_glTexImage1D_Exec)(param_1,0x8063,param_3,param_4,param_5,param_6,param_7,param_8,
                               param_9);
    return uVar3;
  }
  if (param_8 < 0x8037) {
    if (param_8 < 0x8033) {
      if (param_8 != 0x1a00) {
        if (param_8 < 0x1a01) {
          if (param_8 - 0x1400 < 7) {
            if (param_7 < 0x190b) {
              if (0x1902 < param_7) goto LAB_0009ea00;
              goto LAB_0009e9e0;
            }
            if ((param_7 == 0x8000) || ((0x7fff < param_7 && (param_7 - 0x80e0 < 2))))
            goto LAB_0009ea00;
          }
        }
        else if (param_8 == 0x8032) goto LAB_0009e9c0;
        goto LAB_0009e9e8;
      }
LAB_0009e9e0:
      bVar1 = param_7 == 0x1900;
    }
    else {
LAB_0009e9c8:
      if (param_7 == 0x1908) goto LAB_0009ea00;
      bVar1 = param_7 == 0x80e1;
    }
LAB_0009e9e4:
    if (bVar1) {
LAB_0009ea00:
      iVar5 = _gleRowBytes(param_7,param_8,param_5);
      if (iVar5 < 1) {
        return iVar5;
      }
      uVar2 = iVar5 + 3U & 0xfffffffc;
      piVar6 = (int *)_gleAddListItem(param_1,PTR__glTexImage1D_ListExec_001103fc,uVar2 + 0x20);
      if (piVar6 == (int *)0x0) {
        return 0;
      }
      *piVar6 = param_2;
      piVar6[1] = param_3;
      piVar6[2] = param_4;
      piVar6[4] = param_6;
      piVar6[7] = uVar2;
      piVar6[3] = param_5;
      piVar6[5] = param_7;
      piVar6[6] = param_8;
      if (param_9 == 0) {
        return (int)piVar6;
      }
      uVar3 = _gleFillImage(param_1,param_5,1,1,param_7,param_8,param_9,piVar6 + 8);
      return uVar3;
    }
  }
  else if (0x8361 < param_8) {
    if (param_8 < 0x8365) {
LAB_0009e9c0:
      bVar1 = param_7 == 0x1907;
      goto LAB_0009e9e4;
    }
    if (param_8 < 0x8369) goto LAB_0009e9c8;
  }
LAB_0009e9e8:
  if (*(int *)(param_1 + 0x7574) != 0) {
    return iVar5;
  }
  uVar3 = 0x500;
LAB_0009e9f8:
  *(undefined4 *)(param_1 + 0x7574) = uVar3;
  return iVar5;
}

/* _glTexImage1D_Exec @ 0x9ea9c (812 bytes) */
int _glTexImage1D_Exec(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9)
  int param_1;
  undefined4 param_2;
  int param_3;
  undefined4 param_4;
  int param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  int param_9;
{
  byte bVar1;
  ushort uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  double dVar8;
  
  if (-1 < *(short *)(param_1 + 0x4a10)) goto LAB_0009ebf4;
  if ((param_9 == 0) && (*(char *)(param_1 + 0x31e6) != '\0')) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x501;
    goto LAB_0009ec04;
  }
  iVar6 = *(int *)(param_1 + 0x4a6c);
  if (iVar6 == 0) {
LAB_0009eb98:
    iVar6 = _gleCheckTexImage1DArgs(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8)
    ;
    if (iVar6 == 0) {
      return;
    }
    uVar2 = *(ushort *)(iVar6 + 0x24);
    if ((uVar2 & 0x3c00) == 0x1000) {
LAB_0009ec0c:
      iVar5 = param_5;
      if (((*(uint *)(param_1 + 0x3410) & 1) != 0) && (*(short *)(param_1 + 13000) == -0x7fea)) {
        iVar5 = (param_5 - *(int *)(param_1 + 0x32d0)) + 1;
      }
      iVar4 = iVar6 + param_3 * 0x18;
      iVar7 = iVar4 + 0xc4;
      if ((*(byte *)(iVar4 + 0xcf) & 0x20) != 0) {
        _gleDeletePluginTextureLevel(param_1,iVar6,iVar7,0,param_3);
        if (*(int *)(iVar4 + 0xd8) != 0) {
          bVar1 = *(byte *)(iVar4 + 0xcf);
          if ((bVar1 & 1) == 0) {
            _gleFreeTextureLevel(param_1,iVar6,iVar7);
            bVar1 = *(byte *)(iVar4 + 0xcf);
          }
          else {
            *(undefined4 *)(iVar4 + 0xd8) = 0;
          }
          *(byte *)(iVar4 + 0xcf) = bVar1 & 0xef;
        }
        *(byte *)(iVar4 + 0xcf) = *(byte *)(iVar4 + 0xcf) & 0xdf;
      }
      iVar4 = _gleCreateTextureLevel
                        (param_1,iVar6,iVar7,param_4,iVar5,1,1,param_6,param_7,param_8,1,param_9);
      if ((iVar4 != 0) && (param_9 != 0)) {
        _gleTextureImagePut(param_1,iVar7,0,0,0,param_5,1,1,param_7,param_8,1,param_1 + 0x31cc,
                            param_9);
      }
      if ((((iVar5 != 0) &&
           (_gleCreatePluginTextureLevel(param_1,iVar6,iVar7,0,param_3,param_4),
           (*(uint *)(iVar6 + 0x6c) & 0x8000) != 0)) && (*(short *)(iVar6 + 0x60) == param_3)) &&
         (iVar6 = _gleGenMipmapsToLevel(param_1,iVar6,0,param_3,0xf,1), iVar6 != 0)) {
        return;
      }
      *(uint *)(param_1 + 0x314) =
           *(uint *)(param_1 + 0x314) | 1 << (*(uint *)(param_1 + 0x53d4) & 0x3f);
      return;
    }
    if ((uVar2 & 0x3c00) == 0) {
      *(ushort *)(iVar6 + 0x24) = uVar2 | 0x1000;
      goto LAB_0009ec0c;
    }
    if ((uVar2 & 0xc00) == 0) goto LAB_0009ec0c;
  }
  else {
    iVar4 = _gleOffsetLimitImage(param_1 + 0x31cc,param_5,1,param_7,param_8,param_9);
    iVar7 = *(int *)(iVar6 + 0x38);
    dVar8 = (double)((double (*)())_gleBytesPerElement)(param_8);
    iVar5 = (int)dVar8;
    if (iVar4 <= iVar7) {
      if (iVar5 == 0) {
        iVar5 = _glePixelBytes(param_7,param_8);
      }
      if (param_9 == (param_9 / iVar5) * iVar5) {
        if (*(int *)(iVar6 + 0x40) != 0) {
          _gleSynchronizePluginBuffer(param_1,iVar6 + 0x10);
        }
        param_9 = param_9 + *(int *)(iVar6 + 0x30);
        goto LAB_0009eb98;
      }
    }
  }
LAB_0009ebf4:
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar3 = 0x502;
LAB_0009ec04:
  *(undefined4 *)(param_1 + 0x7574) = uVar3;
  return;
}

/* _glTexImage1D_CompExec @ 0x9edc8 (116 bytes) */
int _glTexImage1D_CompExec(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
{
  ((int (*)())_glTexImage1D_Comp)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  ((int (*)())_glTexImage1D_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  return;
}

/* _glTexImage2D_ListExec @ 0x9ee3c (704 bytes) */
int _glTexImage2D_ListExec(param_1, param_2)
  int param_1;
  int *param_2;
{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  iVar9 = param_2[3];
  iVar10 = param_2[4];
  iVar8 = param_2[1];
  iVar7 = param_2[8] + 0x24;
  iVar5 = _gleCheckTexImage2DArgs
                    (param_1,*param_2,iVar8,param_2[2],iVar9,iVar10,param_2[5],param_2[6],param_2[7]
                    );
  if (iVar5 == 0) {
    return iVar7;
  }
  uVar2 = *(ushort *)(iVar5 + 0x24);
  if ((uVar2 & 0x3c00) != 0x1000) {
    if ((uVar2 & 0x3c00) == 0) {
      *(ushort *)(iVar5 + 0x24) = uVar2 | 0x1000;
    }
    else if ((uVar2 & 0xc00) != 0) {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return iVar7;
      }
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
      return iVar7;
    }
  }
  if ((*(uint *)(param_1 + 0x3410) & 2) == 0) {
    if (((*(uint *)(param_1 + 0x3410) & 4) == 0) || (*(short *)(param_1 + 0x3348) != -0x7fea))
    goto LAB_0009ef44;
    iVar6 = *(int *)(param_1 + 0x3354);
    iVar3 = *(int *)(param_1 + 0x3350);
  }
  else {
    if (*(short *)(param_1 + 0x3308) != -0x7fea) goto LAB_0009ef44;
    iVar6 = *(int *)(param_1 + 0x3314);
    iVar3 = *(int *)(param_1 + 0x3310);
  }
  iVar9 = (iVar9 - iVar3) + 1;
  iVar10 = (iVar10 - iVar6) + 1;
LAB_0009ef44:
  uVar4 = *param_2 - 0x8515;
  if (5 < uVar4) {
    uVar4 = 0;
  }
  iVar3 = iVar5 + uVar4 * 0x168 + iVar8 * 0x18;
  iVar6 = iVar3 + 0xc4;
  if ((*(byte *)(iVar3 + 0xcf) & 0x20) != 0) {
    _gleDeletePluginTextureLevel(param_1,iVar5,iVar6,uVar4,iVar8);
    if (*(int *)(iVar3 + 0xd8) != 0) {
      bVar1 = *(byte *)(iVar3 + 0xcf);
      if ((bVar1 & 1) == 0) {
        _gleFreeTextureLevel(param_1,iVar5,iVar6);
        bVar1 = *(byte *)(iVar3 + 0xcf);
      }
      else {
        *(undefined4 *)(iVar3 + 0xd8) = 0;
      }
      *(byte *)(iVar3 + 0xcf) = bVar1 & 0xef;
    }
    *(byte *)(iVar3 + 0xcf) = *(byte *)(iVar3 + 0xcf) & 0xdf;
  }
  iVar9 = _gleCreateTextureLevel
                    (param_1,iVar5,iVar6,param_2[2],iVar9,iVar10,1,param_2[5],param_2[6],param_2[7],
                     0,param_2 + 9);
  if (iVar9 != 0) {
    _gleTextureImagePut(param_1,iVar6,0,0,0,param_2[3],param_2[4],1,param_2[6],param_2[7],1,0,
                        param_2 + 9);
  }
  _gleCreatePluginTextureLevel(param_1,iVar5,iVar6,uVar4,iVar8,param_2[2]);
  if ((((*(uint *)(iVar5 + 0x6c) & 0x8000) == 0) || (*(short *)(iVar5 + 0x60) != iVar8)) ||
     (iVar5 = _gleGenMipmapsToLevel(param_1,iVar5,uVar4,iVar8,0xf,1), iVar5 == 0)) {
    *(uint *)(param_1 + 0x314) =
         *(uint *)(param_1 + 0x314) | 1 << (*(uint *)(param_1 + 0x53d4) & 0x3f);
  }
  return iVar7;
}

/* _glTexImage2D_Comp @ 0x9f0fc (744 bytes) */
int _glTexImage2D_Comp(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
  int param_7;
  uint param_8;
  uint param_9;
  int param_10;
{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  double dVar9;
  
  iVar8 = *(int *)(param_1 + 0x4a6c);
  iVar5 = param_1;
  if (iVar8 != 0) {
    iVar4 = _gleOffsetLimitImage(param_1 + 0x31cc,param_5,param_6,param_8,param_9,param_10);
    iVar7 = *(int *)(iVar8 + 0x38);
    dVar9 = (double)((double (*)())_gleBytesPerElement)(param_9);
    iVar5 = (int)dVar9;
    if (iVar4 <= iVar7) {
      if (iVar5 == 0) {
        iVar5 = _glePixelBytes(param_8,param_9);
      }
      if (param_10 == (param_10 / iVar5) * iVar5) {
        if (*(int *)(iVar8 + 0x40) != 0) {
          iVar5 = _gleSynchronizePluginBuffer(param_1,iVar8 + 0x10);
        }
        param_10 = param_10 + *(int *)(iVar8 + 0x30);
        goto LAB_0009f1e0;
      }
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return iVar5;
    }
    uVar2 = 0x502;
    goto LAB_0009f338;
  }
LAB_0009f1e0:
  if (((param_2 == 0x8064) || (param_2 == 0x851b)) || (param_2 == 0x84f7)) {
    uVar2 = _glTexImage2D_Exec(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
                               param_9,param_10);
    return uVar2;
  }
  if (param_9 < 0x8037) {
    if (param_9 < 0x8033) {
      if (param_9 != 0x1a00) {
        if (param_9 < 0x1a01) {
          if (param_9 - 0x1400 < 7) {
            if (param_8 < 0x190b) {
              if (0x1902 < param_8) goto LAB_0009f340;
              goto LAB_0009f320;
            }
            if ((param_8 == 0x8000) || ((0x7fff < param_8 && (param_8 - 0x80e0 < 2))))
            goto LAB_0009f340;
          }
        }
        else if (param_9 == 0x8032) goto LAB_0009f2f4;
        goto LAB_0009f328;
      }
LAB_0009f320:
      bVar1 = param_8 == 0x1900;
    }
    else {
LAB_0009f308:
      if (param_8 == 0x1908) goto LAB_0009f340;
      uVar3 = 0x80e1;
LAB_0009f318:
      bVar1 = param_8 == uVar3;
    }
LAB_0009f324:
    if (bVar1) {
LAB_0009f340:
      iVar5 = _gleImageSize(param_8,param_9,param_5,param_6);
      if (iVar5 < 1) {
        return iVar5;
      }
      uVar3 = iVar5 + 3U & 0xfffffffc;
      piVar6 = (int *)_gleAddListItem(param_1,PTR__glTexImage2D_ListExec_001103f8,uVar3 + 0x24);
      if (piVar6 == (int *)0x0) {
        return 0;
      }
      *piVar6 = param_2;
      piVar6[1] = param_3;
      piVar6[2] = param_4;
      piVar6[5] = param_7;
      piVar6[8] = uVar3;
      piVar6[3] = param_5;
      piVar6[4] = param_6;
      piVar6[6] = param_8;
      piVar6[7] = param_9;
      if (param_10 == 0) {
        return (int)piVar6;
      }
      uVar2 = _gleFillImage(param_1,param_5,param_6,1,param_8,param_9,param_10,piVar6 + 9);
      return uVar2;
    }
  }
  else if (param_9 < 0x8369) {
    if (0x8364 < param_9) goto LAB_0009f308;
    if (0x8361 < param_9) {
LAB_0009f2f4:
      bVar1 = param_8 == 0x1907;
      goto LAB_0009f324;
    }
  }
  else if (param_9 - 0x85ba < 2) {
    uVar3 = 0x85b9;
    goto LAB_0009f318;
  }
LAB_0009f328:
  if (*(int *)(param_1 + 0x7574) != 0) {
    return iVar5;
  }
  uVar2 = 0x500;
LAB_0009f338:
  *(undefined4 *)(param_1 + 0x7574) = uVar2;
  return iVar5;
}

/* _glTexImage2D_FlushExec @ 0x9f3e4 (64 bytes) */
int _glTexImage2D_FlushExec(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
  undefined4 param_10;
{
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  _glTexImage2D_Exec(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                     param_10);
  ((void (*)())_glFlush_Exec)(param_1,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
  return;
}

/* _glTexImage2D_CompExec @ 0x9f424 (128 bytes) */
int _glTexImage2D_CompExec(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
  undefined4 param_10;
{
  ((int (*)())_glTexImage2D_Comp)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                     param_10);
  _glTexImage2D_Exec(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                     param_10);
  return;
}

/* _glTexImage3D_ListExec @ 0x9f4a4 (564 bytes) */
int _glTexImage3D_ListExec(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar6 = param_2[1];
  iVar5 = param_2[9] + 0x28;
  iVar4 = _gleCheckTexImage3DArgs
                    (param_1,*param_2,iVar6,param_2[2],param_2[3],param_2[4],param_2[5],param_2[6],
                     param_2[7],param_2[8]);
  if (iVar4 != 0) {
    uVar2 = *(ushort *)(iVar4 + 0x24);
    if ((uVar2 & 0x3c00) != 0x1000) {
      if ((uVar2 & 0x3c00) == 0) {
        *(ushort *)(iVar4 + 0x24) = uVar2 | 0x1000;
      }
      else if ((uVar2 & 0xc00) != 0) {
        if (*(int *)(param_1 + 0x7574) != 0) {
          return iVar5;
        }
        *(undefined4 *)(param_1 + 0x7574) = 0x502;
        return iVar5;
      }
    }
    iVar3 = iVar4 + iVar6 * 0x18;
    iVar7 = iVar3 + 0xc4;
    if ((*(byte *)(iVar3 + 0xcf) & 0x20) != 0) {
      _gleDeletePluginTextureLevel(param_1,iVar4,iVar7,0,iVar6);
      if (*(int *)(iVar3 + 0xd8) != 0) {
        bVar1 = *(byte *)(iVar3 + 0xcf);
        if ((bVar1 & 1) == 0) {
          _gleFreeTextureLevel(param_1,iVar4,iVar7);
          bVar1 = *(byte *)(iVar3 + 0xcf);
        }
        else {
          *(undefined4 *)(iVar3 + 0xd8) = 0;
        }
        *(byte *)(iVar3 + 0xcf) = bVar1 & 0xef;
      }
      *(byte *)(iVar3 + 0xcf) = *(byte *)(iVar3 + 0xcf) & 0xdf;
    }
    iVar3 = _gleCreateTextureLevel
                      (param_1,iVar4,iVar7,param_2[2],param_2[3],param_2[4],param_2[5],param_2[6],
                       param_2[7],param_2[8],0,param_2 + 10);
    if (iVar3 != 0) {
      _gleTextureImagePut(param_1,iVar7,0,0,0,param_2[3],param_2[4],param_2[5],param_2[7],param_2[8]
                          ,0,0,param_2 + 10);
    }
    _gleCreatePluginTextureLevel(param_1,iVar4,iVar7,0,iVar6,param_2[2]);
    if ((((*(uint *)(iVar4 + 0x6c) & 0x8000) == 0) || (*(short *)(iVar4 + 0x60) != iVar6)) ||
       (iVar4 = _gleGenMipmapsToLevel(param_1,iVar4,0,iVar6,0xf,1), iVar4 == 0)) {
      *(uint *)(param_1 + 0x314) =
           *(uint *)(param_1 + 0x314) | 1 << (*(uint *)(param_1 + 0x53d4) & 0x3f);
    }
  }
  return iVar5;
}

/* _glTexImage3D_Comp @ 0x9f6d8 (708 bytes) */
int _glTexImage3D_Comp(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
  int param_7;
  int param_8;
  uint param_9;
  uint param_10;
  int param_11;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  double dVar9;
  
  iVar8 = *(int *)(param_1 + 0x4a6c);
  iVar4 = param_1;
  if (iVar8 == 0) {
LAB_0009f7b0:
    if (param_2 == 0x8070) {
      uVar5 = _glTexImage3D_Exec(param_1,0x8070,param_3,param_4,param_5,param_6,param_7,param_8,
                                 param_9,param_10,param_11);
      return uVar5;
    }
    if (param_10 < 0x8037) {
      if (0x8032 < param_10) {
LAB_0009f8a0:
        if (param_9 == 0x1908) goto LAB_0009f8ec;
        bVar1 = param_9 == 0x80e1;
LAB_0009f8b4:
        if (bVar1) {
LAB_0009f8ec:
          iVar4 = _gleImageSize(param_9,param_10,param_5,param_6);
          if (iVar4 * param_7 < 1) {
            return iVar4;
          }
          uVar2 = iVar4 * param_7 + 3U & 0xfffffffc;
          piVar6 = (int *)_gleAddListItem(param_1,PTR__glTexImage3D_ListExec_001103f4,uVar2 + 0x28);
          if (piVar6 == (int *)0x0) {
            return 0;
          }
          *piVar6 = param_2;
          piVar6[1] = param_3;
          piVar6[2] = param_4;
          piVar6[6] = param_8;
          piVar6[3] = param_5;
          piVar6[4] = param_6;
          piVar6[5] = param_7;
          piVar6[7] = param_9;
          piVar6[8] = param_10;
          piVar6[9] = uVar2;
          if ((int)uVar2 < 1) {
            return (int)piVar6;
          }
          if (param_11 == 0) {
            return (int)piVar6;
          }
          uVar5 = _gleFillImage(param_1,param_5,param_6,param_7,param_9,param_10,param_11,
                                piVar6 + 10);
          return uVar5;
        }
        goto LAB_0009f8b8;
      }
      if (param_10 == 0x1a00) {
        if (param_9 == 0x1900) goto LAB_0009f8ec;
      }
      else if (param_10 < 0x1a01) {
        if (param_10 - 0x1400 < 7) {
          if (0x190a < param_9) {
            if ((param_9 == 0x8000) || ((0x7fff < param_9 && (param_9 - 0x80e0 < 2))))
            goto LAB_0009f8ec;
            goto LAB_0009f8b8;
          }
          if (0x1902 < param_9) goto LAB_0009f8ec;
          bVar1 = param_9 == 0x1900;
          goto LAB_0009f8b4;
        }
      }
      else if (param_10 == 0x8032) goto LAB_0009f898;
    }
    else if (0x8361 < param_10) {
      if (param_10 < 0x8365) {
LAB_0009f898:
        bVar1 = param_9 == 0x1907;
        goto LAB_0009f8b4;
      }
      if (param_10 < 0x8369) goto LAB_0009f8a0;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return iVar4;
    }
    uVar5 = 0x500;
  }
  else {
    iVar3 = _gleOffsetLimitImage3D
                      (param_1 + 0x31cc,param_5,param_6,param_7,param_9,param_10,param_11);
    iVar7 = *(int *)(iVar8 + 0x38);
    dVar9 = (double)((double (*)())_gleBytesPerElement)(param_10);
    iVar4 = (int)dVar9;
    if (iVar3 <= iVar7) {
      if (iVar4 == 0) {
        iVar4 = _glePixelBytes(param_9,param_10);
      }
      if (param_11 == (param_11 / iVar4) * iVar4) {
        if (*(int *)(iVar8 + 0x40) != 0) {
          iVar4 = _gleSynchronizePluginBuffer(param_1,iVar8 + 0x10);
        }
        param_11 = param_11 + *(int *)(iVar8 + 0x30);
        goto LAB_0009f7b0;
      }
    }
LAB_0009f8b8:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return iVar4;
    }
    uVar5 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar5;
  return iVar4;
}

/* _glTexImage3D_CompExec @ 0x9f99c (140 bytes) */
int _glTexImage3D_CompExec(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11)
  undefined4 param_1;
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
{
  ((int (*)())_glTexImage3D_Comp)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                     param_10,param_11);
  _glTexImage3D_Exec(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                     param_10,param_11);
  return;
}

/* _glTexSubImage1D_ListExec @ 0x9fa28 (920 bytes) */
int _glTexSubImage1D_ListExec(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  byte bVar5;
  uint uVar6;
  int iVar7;
  
  iVar1 = param_2[6];
  if (*(short *)(param_1 + 0x4a10) < 0) {
    uVar6 = param_2[1];
    iVar3 = _gleCheckTexSubImage1DArgs
                      (param_1,*param_2,uVar6,param_2[2],param_2[3],param_2[4],param_2[5]);
    if (iVar3 != 0) {
      iVar2 = iVar3 + uVar6 * 0x18;
      iVar7 = iVar2 + 0xc4;
      if (((((int)uVar6 < (int)(uint)*(byte *)(iVar3 + 0x8d)) ||
           ((int)(uint)*(byte *)(iVar3 + 0x8f) < (int)uVar6)) ||
          ((*(ushort *)(iVar3 + 0x94) >> (uVar6 & 0x3f) & 1) == 0)) ||
         (iVar4 = (**(code **)(param_1 + 0x4710))
                            (*(undefined4 *)(param_1 + 0x4688),
                             *(undefined4 *)(iVar3 + (uint)*(byte *)(param_1 + 0x85a8) * 4),0,uVar6,
                             param_2[2],0,0,param_2[3]), iVar4 == 0)) {
        bVar5 = *(byte *)(iVar2 + 0xcf);
        if ((bVar5 & 0x10) == 0) {
          if ((bVar5 & 0x40) == 0) {
            if (*(int *)(iVar2 + 0xd8) == 0) {
              _gleAllocateTextureLevel(param_1,iVar3,iVar7);
              bVar5 = *(byte *)(iVar2 + 0xcf);
            }
            *(byte *)(iVar2 + 0xcf) = bVar5 | 0x10;
          }
          else {
            _gleUploadPluginTextureLevel
                      (param_1,iVar3,iVar7,0,uVar6,(uint)*(byte *)(param_1 + 0x85a8));
          }
        }
        _gleModifyPluginTextureLevel(param_1,iVar3,iVar7,0,uVar6,param_2[2],0,0,param_2[3]);
        _gleTextureImagePut(param_1,iVar7,param_2[2] + (uint)*(byte *)(iVar2 + 0xce),0,0,param_2[3],
                            1,1,param_2[4],param_2[5],1,0,param_2 + 7);
        if ((((*(uint *)(iVar3 + 0x6c) & 0x8000) == 0) || ((int)*(short *)(iVar3 + 0x60) != uVar6))
           || (iVar3 = _gleGenMipmapsToLevel(param_1,iVar3,0,uVar6,0xf,1), iVar3 == 0)) {
          *(uint *)(param_1 + 0x314) =
               *(uint *)(param_1 + 0x314) | 1 << (*(uint *)(param_1 + 0x53d4) & 0x3f);
        }
      }
      else {
        *(undefined4 *)(iVar3 + 0x20) =
             *(undefined4 *)
              ((uint)*(byte *)(param_1 + 0x85a8) * 4 + *(int *)(param_1 + 0x5148) + 0x8054);
        if (*(int *)(iVar2 + 0xd8) != 0) {
          bVar5 = *(byte *)(iVar2 + 0xcf);
          if (((bVar5 & 1) == 0) && (*(short *)(iVar3 + 0x3e) == -0x7a43)) {
            _gleFreeTextureLevel(param_1,iVar3,iVar7);
            bVar5 = *(byte *)(iVar2 + 0xcf);
          }
          *(byte *)(iVar2 + 0xcf) = bVar5 & 0xef;
          *(ushort *)(iVar3 + 0xa0) =
               *(ushort *)(iVar3 + 0xa0) &
               ((ushort)(-2 << (uVar6 & 0x1f)) | (ushort)(0xfffffffe >> 0x20 - (uVar6 & 0x1f)));
        }
        *(byte *)(iVar2 + 0xcf) = *(byte *)(iVar2 + 0xcf) | 0x40;
        if ((((*(uint *)(iVar3 + 0x6c) & 0x8000) != 0) && ((int)*(short *)(iVar3 + 0x60) == uVar6))
           && (uVar6 = uVar6 + 1, (int)uVar6 <= (int)(uint)*(byte *)(iVar3 + 0x83))) {
          iVar2 = uVar6 * 0x18 + iVar3 + 0xc4;
          do {
            if (*(int *)(iVar2 + 0x14) != 0) {
              if (((*(byte *)(iVar2 + 0xb) & 1) == 0) && (*(short *)(iVar3 + 0x3e) == -0x7a43)) {
                _gleFreeTextureLevel(param_1,iVar3,iVar2);
              }
              *(byte *)(iVar2 + 0xb) = *(byte *)(iVar2 + 0xb) & 0xef;
              *(ushort *)(iVar3 + 0xa0) = *(ushort *)(iVar3 + 0xa0) & ~(ushort)(1 << (uVar6 & 0x3f))
              ;
            }
            uVar6 = uVar6 + 1;
            *(byte *)(iVar2 + 0xb) = *(byte *)(iVar2 + 0xb) | 0x40;
            iVar2 = iVar2 + 0x18;
          } while ((int)uVar6 <= (int)(uint)*(byte *)(iVar3 + 0x83));
        }
      }
    }
  }
  else if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x502;
  }
  return iVar1 + 0x1c;
}

/* _glTexSubImage1D_Comp @ 0x9fdc0 (636 bytes) */
int _glTexSubImage1D_Comp(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
  uint param_6;
  uint param_7;
  int param_8;
{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  double dVar9;
  
  iVar8 = *(int *)(param_1 + 0x4a6c);
  iVar5 = param_1;
  if (iVar8 == 0) {
LAB_0009fe88:
    if (param_8 == 0) {
      return iVar5;
    }
    if (param_2 == 0xde0) {
      if (param_5 < 0) {
        if (*(int *)(param_1 + 0x7574) != 0) {
          return iVar5;
        }
        uVar3 = 0x501;
        goto LAB_0009ffa4;
      }
      if (param_7 < 0x8037) {
        if (0x8032 < param_7) {
LAB_0009ff60:
          if (param_6 == 0x1908) goto LAB_0009ffac;
          bVar1 = param_6 == 0x80e1;
LAB_0009ff74:
          if (bVar1) {
LAB_0009ffac:
            iVar5 = _gleRowBytes(param_6,param_7,param_5);
            if (iVar5 < 1) {
              return iVar5;
            }
            uVar2 = iVar5 + 3U & 0xfffffffc;
            puVar6 = (undefined4 *)
                     _gleAddListItem(param_1,PTR__glTexSubImage1D_ListExec_00110408,uVar2 + 0x1c);
            if (puVar6 == (undefined4 *)0x0) {
              return 0;
            }
            *puVar6 = 0xde0;
            puVar6[1] = param_3;
            puVar6[2] = param_4;
            puVar6[6] = uVar2;
            puVar6[3] = param_5;
            puVar6[4] = param_6;
            puVar6[5] = param_7;
            uVar3 = _gleFillImage(param_1,param_5,1,1,param_6,param_7,param_8,puVar6 + 7);
            return uVar3;
          }
          goto LAB_0009ff78;
        }
        if (param_7 == 0x1a00) {
          if (param_6 == 0x1900) goto LAB_0009ffac;
        }
        else if (param_7 < 0x1a01) {
          if (param_7 - 0x1400 < 7) {
            if (0x190a < param_6) {
              if ((param_6 == 0x8000) || ((0x7fff < param_6 && (param_6 - 0x80e0 < 2))))
              goto LAB_0009ffac;
              goto LAB_0009ff78;
            }
            if (0x1901 < param_6) goto LAB_0009ffac;
            bVar1 = param_6 == 0x1900;
            goto LAB_0009ff74;
          }
        }
        else if (param_7 == 0x8032) goto LAB_0009ff58;
      }
      else if (0x8361 < param_7) {
        if (param_7 < 0x8365) {
LAB_0009ff58:
          bVar1 = param_6 == 0x1907;
          goto LAB_0009ff74;
        }
        if (param_7 < 0x8369) goto LAB_0009ff60;
      }
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return iVar5;
    }
    uVar3 = 0x500;
  }
  else {
    iVar4 = _gleOffsetLimitImage(param_1 + 0x31cc,param_5,1,param_6,param_7,param_8);
    iVar7 = *(int *)(iVar8 + 0x38);
    dVar9 = (double)((double (*)())_gleBytesPerElement)(param_7);
    iVar5 = (int)dVar9;
    if (iVar4 <= iVar7) {
      if (iVar5 == 0) {
        iVar5 = _glePixelBytes(param_6,param_7);
      }
      if (param_8 == (param_8 / iVar5) * iVar5) {
        if (*(int *)(iVar8 + 0x40) != 0) {
          iVar5 = _gleSynchronizePluginBuffer(param_1,iVar8 + 0x10);
        }
        param_8 = param_8 + *(int *)(iVar8 + 0x30);
        goto LAB_0009fe88;
      }
    }
LAB_0009ff78:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return iVar5;
    }
    uVar3 = 0x502;
  }
LAB_0009ffa4:
  *(undefined4 *)(param_1 + 0x7574) = uVar3;
  return iVar5;
}

/* _glTexSubImage1D_Exec @ 0xa003c (1600 bytes) */
int _glTexSubImage1D_Exec(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  undefined4 param_2;
  uint param_3;
  int param_4;
  int param_5;
  undefined4 param_6;
  undefined4 param_7;
  int param_8;
{
  int iVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  double dVar9;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    iVar5 = *(int *)(param_1 + 0x4a6c);
    if (iVar5 == 0) {
LAB_000a0110:
      if (param_5 == 0) {
        return;
      }
      iVar2 = _gleCheckTexSubImage1DArgs(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
      if (iVar2 == 0) {
        return;
      }
      iVar1 = iVar2 + param_3 * 0x18;
      iVar7 = iVar1 + 0xc4;
      iVar8 = _checkFastPath(param_1,iVar7,param_4,0,0,param_5,1,param_6,param_7,param_8);
      if (iVar5 != 0) {
        if ((((iVar8 != 0) && ((int)(uint)*(byte *)(iVar2 + 0x8d) <= (int)param_3)) &&
            ((int)param_3 <= (int)(uint)*(byte *)(iVar2 + 0x8f))) &&
           (((*(ushort *)(iVar2 + 0x94) >> (param_3 & 0x3f) & 1) != 0 &&
            (iVar3 = (**(code **)(param_1 + 0x4710))
                               (*(undefined4 *)(param_1 + 0x4688),
                                *(undefined4 *)(iVar2 + (uint)*(byte *)(param_1 + 0x85a8) * 4),0,
                                param_3,param_4,0,0,param_5), iVar3 != 0)))) {
          *(undefined4 *)(iVar2 + 0x20) =
               *(undefined4 *)
                ((uint)*(byte *)(param_1 + 0x85a8) * 4 + *(int *)(param_1 + 0x5148) + 0x8054);
          if (*(int *)(iVar1 + 0xd8) != 0) {
            bVar4 = *(byte *)(iVar1 + 0xcf);
            if (((bVar4 & 1) == 0) && (*(short *)(iVar2 + 0x3e) == -0x7a43)) {
              _gleFreeTextureLevel(param_1,iVar2,iVar7);
              bVar4 = *(byte *)(iVar1 + 0xcf);
            }
            *(byte *)(iVar1 + 0xcf) = bVar4 & 0xef;
            *(ushort *)(iVar2 + 0xa0) =
                 *(ushort *)(iVar2 + 0xa0) &
                 ((ushort)(-2 << (param_3 & 0x1f)) | (ushort)(0xfffffffe >> 0x20 - (param_3 & 0x1f))
                 );
          }
          *(byte *)(iVar1 + 0xcf) = *(byte *)(iVar1 + 0xcf) | 0x40;
          if ((*(uint *)(iVar2 + 0x6c) & 0x8000) == 0) {
            return;
          }
          if ((int)*(short *)(iVar2 + 0x60) != param_3) {
            return;
          }
          uVar6 = param_3 + 1;
          if ((int)(uint)*(byte *)(iVar2 + 0x83) < (int)uVar6) {
            return;
          }
          iVar5 = uVar6 * 0x18 + iVar2 + 0xc4;
          do {
            if (*(int *)(iVar5 + 0x14) != 0) {
              if (((*(byte *)(iVar5 + 0xb) & 1) == 0) && (*(short *)(iVar2 + 0x3e) == -0x7a43)) {
                _gleFreeTextureLevel(param_1,iVar2,iVar5);
              }
              *(byte *)(iVar5 + 0xb) = *(byte *)(iVar5 + 0xb) & 0xef;
              *(ushort *)(iVar2 + 0xa0) = *(ushort *)(iVar2 + 0xa0) & ~(ushort)(1 << (uVar6 & 0x3f))
              ;
            }
            uVar6 = uVar6 + 1;
            *(byte *)(iVar5 + 0xb) = *(byte *)(iVar5 + 0xb) | 0x40;
            iVar5 = iVar5 + 0x18;
          } while ((int)uVar6 <= (int)(uint)*(byte *)(iVar2 + 0x83));
          return;
        }
        if (*(int *)(iVar5 + 0x40) != 0) {
          _gleSynchronizePluginBuffer(param_1,iVar5 + 0x10);
        }
      }
      if ((((iVar8 == 0) || ((int)param_3 < (int)(uint)*(byte *)(iVar2 + 0x8d))) ||
          ((int)(uint)*(byte *)(iVar2 + 0x8f) < (int)param_3)) ||
         (((*(ushort *)(iVar2 + 0x94) >> (param_3 & 0x3f) & 1) == 0 ||
          (iVar5 = (**(code **)(param_1 + 0x4710))
                             (*(undefined4 *)(param_1 + 0x4688),
                              *(undefined4 *)(iVar2 + (uint)*(byte *)(param_1 + 0x85a8) * 4),0,
                              param_3,param_4,0,0,param_5), iVar5 == 0)))) {
        bVar4 = *(byte *)(iVar1 + 0xcf);
        if ((bVar4 & 0x10) == 0) {
          if ((bVar4 & 0x40) == 0) {
            if (*(int *)(iVar1 + 0xd8) == 0) {
              _gleAllocateTextureLevel(param_1,iVar2,iVar7);
              bVar4 = *(byte *)(iVar1 + 0xcf);
            }
            *(byte *)(iVar1 + 0xcf) = bVar4 | 0x10;
          }
          else {
            _gleUploadPluginTextureLevel
                      (param_1,iVar2,iVar7,0,param_3,(uint)*(byte *)(param_1 + 0x85a8));
          }
        }
        _gleModifyPluginTextureLevel(param_1,iVar2,iVar7,0,param_3,param_4,0,0,param_5);
        _gleTextureImagePut(param_1,iVar7,param_4 + (uint)*(byte *)(iVar1 + 0xce),0,0,param_5,1,1,
                            param_6,param_7,1,param_1 + 0x31cc,param_8);
        if ((((*(uint *)(iVar2 + 0x6c) & 0x8000) != 0) && ((int)*(short *)(iVar2 + 0x60) == param_3)
            ) && (iVar5 = _gleGenMipmapsToLevel(param_1,iVar2,0,param_3,0xf,1), iVar5 != 0)) {
          return;
        }
        *(uint *)(param_1 + 0x314) =
             *(uint *)(param_1 + 0x314) | 1 << (*(uint *)(param_1 + 0x53d4) & 0x3f);
        return;
      }
      *(undefined4 *)(iVar2 + 0x20) =
           *(undefined4 *)
            ((uint)*(byte *)(param_1 + 0x85a8) * 4 + *(int *)(param_1 + 0x5148) + 0x8054);
      if (*(int *)(iVar1 + 0xd8) != 0) {
        bVar4 = *(byte *)(iVar1 + 0xcf);
        if (((bVar4 & 1) == 0) && (*(short *)(iVar2 + 0x3e) == -0x7a43)) {
          _gleFreeTextureLevel(param_1,iVar2,iVar7);
          bVar4 = *(byte *)(iVar1 + 0xcf);
        }
        *(byte *)(iVar1 + 0xcf) = bVar4 & 0xef;
        *(ushort *)(iVar2 + 0xa0) =
             *(ushort *)(iVar2 + 0xa0) &
             ((ushort)(-2 << (param_3 & 0x1f)) | (ushort)(0xfffffffe >> 0x20 - (param_3 & 0x1f)));
      }
      *(byte *)(iVar1 + 0xcf) = *(byte *)(iVar1 + 0xcf) | 0x40;
      if ((*(uint *)(iVar2 + 0x6c) & 0x8000) == 0) {
        return;
      }
      if ((int)*(short *)(iVar2 + 0x60) != param_3) {
        return;
      }
      uVar6 = param_3 + 1;
      if ((int)(uint)*(byte *)(iVar2 + 0x83) < (int)uVar6) {
        return;
      }
      iVar5 = uVar6 * 0x18 + iVar2 + 0xc4;
      do {
        if (*(int *)(iVar5 + 0x14) != 0) {
          if (((*(byte *)(iVar5 + 0xb) & 1) == 0) && (*(short *)(iVar2 + 0x3e) == -0x7a43)) {
            _gleFreeTextureLevel(param_1,iVar2,iVar5);
          }
          *(byte *)(iVar5 + 0xb) = *(byte *)(iVar5 + 0xb) & 0xef;
          *(ushort *)(iVar2 + 0xa0) = *(ushort *)(iVar2 + 0xa0) & ~(ushort)(1 << (uVar6 & 0x3f));
        }
        uVar6 = uVar6 + 1;
        *(byte *)(iVar5 + 0xb) = *(byte *)(iVar5 + 0xb) | 0x40;
        iVar5 = iVar5 + 0x18;
      } while ((int)uVar6 <= (int)(uint)*(byte *)(iVar2 + 0x83));
      return;
    }
    iVar1 = _gleOffsetLimitImage(param_1 + 0x31cc,param_5,1,param_6,param_7,param_8);
    iVar8 = *(int *)(iVar5 + 0x38);
    dVar9 = (double)((double (*)())_gleBytesPerElement)(param_7);
    iVar2 = (int)dVar9;
    if (iVar1 <= iVar8) {
      if (iVar2 == 0) {
        iVar2 = _glePixelBytes(param_6,param_7);
      }
      if (param_8 == (param_8 / iVar2) * iVar2) {
        param_8 = param_8 + *(int *)(iVar5 + 0x30);
        goto LAB_000a0110;
      }
    }
  }
  if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x502;
  }
  return;
}

/* _glTexSubImage1D_CompExec @ 0xa067c (104 bytes) */
int _glTexSubImage1D_CompExec(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  ((int (*)())_glTexSubImage1D_Comp)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  ((int (*)())_glTexSubImage1D_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}

/* _glTexSubImage2D_ListExec @ 0xa06e4 (1008 bytes) */
int _glTexSubImage2D_ListExec(param_1, param_2)
  int param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  byte bVar7;
  uint uVar8;
  int iVar9;
  
  iVar2 = param_2[8];
  if (*(short *)(param_1 + 0x4a10) < 0) {
    uVar8 = param_2[1];
    iVar5 = _gleCheckTexSubImage2DArgs
                      (param_1,*param_2,uVar8,param_2[2],param_2[3],param_2[4],param_2[5],param_2[6]
                       ,param_2[7]);
    if (iVar5 != 0) {
      uVar3 = *param_2 - 0x8515;
      if (5 < uVar3) {
        uVar3 = 0;
      }
      iVar4 = iVar5 + uVar3 * 0x168 + uVar8 * 0x18;
      iVar9 = iVar4 + 0xc4;
      if (((((int)uVar8 < (int)(uint)*(byte *)(iVar5 + 0x8d)) ||
           ((int)(uint)*(byte *)(iVar5 + 0x8f) < (int)uVar8)) ||
          (iVar1 = uVar3 * 2, (*(ushort *)(iVar1 + iVar5 + 0x94) >> (uVar8 & 0x3f) & 1) == 0)) ||
         (iVar6 = (**(code **)(param_1 + 0x4710))
                            (*(undefined4 *)(param_1 + 0x4688),
                             *(undefined4 *)(iVar5 + (uint)*(byte *)(param_1 + 0x85a8) * 4),uVar3,
                             uVar8,param_2[2],param_2[3],0,param_2[4]), iVar6 == 0)) {
        bVar7 = *(byte *)(iVar4 + 0xcf);
        if ((bVar7 & 0x10) == 0) {
          if ((bVar7 & 0x40) == 0) {
            if (*(int *)(iVar4 + 0xd8) == 0) {
              _gleAllocateTextureLevel(param_1,iVar5,iVar9);
              bVar7 = *(byte *)(iVar4 + 0xcf);
            }
            *(byte *)(iVar4 + 0xcf) = bVar7 | 0x10;
          }
          else {
            _gleUploadPluginTextureLevel
                      (param_1,iVar5,iVar9,uVar3,uVar8,(uint)*(byte *)(param_1 + 0x85a8));
          }
        }
        _gleModifyPluginTextureLevel
                  (param_1,iVar5,iVar9,uVar3,uVar8,param_2[2],param_2[3],0,param_2[4]);
        _gleTextureImagePut(param_1,iVar9,param_2[2] + (uint)*(byte *)(iVar4 + 0xce),
                            param_2[3] + (uint)*(byte *)(iVar4 + 0xce),0,param_2[4],param_2[5],1,
                            param_2[6],param_2[7],1,0,param_2 + 9);
        if ((((*(uint *)(iVar5 + 0x6c) & 0x8000) == 0) || ((int)*(short *)(iVar5 + 0x60) != uVar8))
           || (iVar5 = _gleGenMipmapsToLevel(param_1,iVar5,uVar3,uVar8,0xf,1), iVar5 == 0)) {
          *(uint *)(param_1 + 0x314) =
               *(uint *)(param_1 + 0x314) | 1 << (*(uint *)(param_1 + 0x53d4) & 0x3f);
        }
      }
      else {
        *(undefined4 *)(iVar5 + 0x20) =
             *(undefined4 *)
              ((uint)*(byte *)(param_1 + 0x85a8) * 4 + *(int *)(param_1 + 0x5148) + 0x8054);
        if (*(int *)(iVar4 + 0xd8) != 0) {
          bVar7 = *(byte *)(iVar4 + 0xcf);
          if (((bVar7 & 1) == 0) && (*(short *)(iVar5 + 0x3e) == -0x7a43)) {
            _gleFreeTextureLevel(param_1,iVar5,iVar9);
            bVar7 = *(byte *)(iVar4 + 0xcf);
          }
          *(byte *)(iVar4 + 0xcf) = bVar7 & 0xef;
          *(ushort *)(iVar1 + iVar5 + 0xa0) =
               *(ushort *)(iVar1 + iVar5 + 0xa0) &
               ((ushort)(-2 << (uVar8 & 0x1f)) | (ushort)(0xfffffffe >> 0x20 - (uVar8 & 0x1f)));
        }
        *(byte *)(iVar4 + 0xcf) = *(byte *)(iVar4 + 0xcf) | 0x40;
        if ((((*(uint *)(iVar5 + 0x6c) & 0x8000) != 0) && ((int)*(short *)(iVar5 + 0x60) == uVar8))
           && (uVar8 = uVar8 + 1, (int)uVar8 <= (int)(uint)*(byte *)(iVar5 + 0x83))) {
          iVar4 = uVar8 * 0x18 + uVar3 * 0x168 + iVar5 + 0xc4;
          do {
            if (*(int *)(iVar4 + 0x14) != 0) {
              if (((*(byte *)(iVar4 + 0xb) & 1) == 0) && (*(short *)(iVar5 + 0x3e) == -0x7a43)) {
                _gleFreeTextureLevel(param_1,iVar5,iVar4);
              }
              *(byte *)(iVar4 + 0xb) = *(byte *)(iVar4 + 0xb) & 0xef;
              *(ushort *)(iVar1 + iVar5 + 0xa0) =
                   *(ushort *)(iVar1 + iVar5 + 0xa0) & ~(ushort)(1 << (uVar8 & 0x3f));
            }
            uVar8 = uVar8 + 1;
            *(byte *)(iVar4 + 0xb) = *(byte *)(iVar4 + 0xb) | 0x40;
            iVar4 = iVar4 + 0x18;
          } while ((int)uVar8 <= (int)(uint)*(byte *)(iVar5 + 0x83));
        }
      }
    }
  }
  else if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x502;
  }
  return iVar2 + 0x24;
}

/* _glTexSubImage2D_Comp @ 0xa0ad4 (688 bytes) */
int _glTexSubImage2D_Comp(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10)
  int param_1;
  uint param_2;
  uint param_3;
  uint param_4;
  uint param_5;
  uint param_6;
  uint param_7;
  uint param_8;
  uint param_9;
  int param_10;
{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint *puVar6;
  int iVar7;
  int iVar8;
  double dVar9;
  
  iVar8 = *(int *)(param_1 + 0x4a6c);
  iVar5 = param_1;
  if (iVar8 == 0) {
LAB_000a0ba4:
    if (param_10 == 0) {
      return iVar5;
    }
    if ((param_2 == 0xde1) || ((0xde0 < param_2 && (param_2 - 0x8515 < 6)))) {
      if (((int)param_6 < 0) || ((int)param_7 < 0)) {
        if (*(int *)(param_1 + 0x7574) != 0) {
          return iVar5;
        }
        uVar3 = 0x501;
        goto LAB_000a0ce0;
      }
      if (param_9 < 0x8037) {
        if (0x8032 < param_9) {
LAB_000a0c9c:
          if (param_8 == 0x1908) goto LAB_000a0ce8;
          bVar1 = param_8 == 0x80e1;
LAB_000a0cb0:
          if (bVar1) {
LAB_000a0ce8:
            iVar5 = _gleImageSize(param_8,param_9,param_6,param_7);
            if (iVar5 < 1) {
              return iVar5;
            }
            uVar2 = iVar5 + 3U & 0xfffffffc;
            puVar6 = (uint *)_gleAddListItem(param_1,PTR__glTexSubImage2D_ListExec_00110404,
                                             uVar2 + 0x24);
            if (puVar6 == (uint *)0x0) {
              return 0;
            }
            *puVar6 = param_2;
            puVar6[1] = param_3;
            puVar6[2] = param_4;
            puVar6[3] = param_5;
            puVar6[8] = uVar2;
            puVar6[4] = param_6;
            puVar6[5] = param_7;
            puVar6[6] = param_8;
            puVar6[7] = param_9;
            uVar3 = _gleFillImage(param_1,param_6,param_7,1,param_8,param_9,param_10,puVar6 + 9);
            return uVar3;
          }
          goto LAB_000a0cb4;
        }
        if (param_9 == 0x1a00) {
          if (param_8 == 0x1900) goto LAB_000a0ce8;
        }
        else if (param_9 < 0x1a01) {
          if (param_9 - 0x1400 < 7) {
            if (0x190a < param_8) {
              if ((param_8 == 0x8000) || ((0x7fff < param_8 && (param_8 - 0x80e0 < 2))))
              goto LAB_000a0ce8;
              goto LAB_000a0cb4;
            }
            if (0x1901 < param_8) goto LAB_000a0ce8;
            bVar1 = param_8 == 0x1900;
            goto LAB_000a0cb0;
          }
        }
        else if (param_9 == 0x8032) goto LAB_000a0c94;
      }
      else if (0x8361 < param_9) {
        if (param_9 < 0x8365) {
LAB_000a0c94:
          bVar1 = param_8 == 0x1907;
          goto LAB_000a0cb0;
        }
        if (param_9 < 0x8369) goto LAB_000a0c9c;
      }
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return iVar5;
    }
    uVar3 = 0x500;
  }
  else {
    iVar4 = _gleOffsetLimitImage(param_1 + 0x31cc,param_6,param_7,param_8,param_9,param_10);
    iVar7 = *(int *)(iVar8 + 0x38);
    dVar9 = (double)((double (*)())_gleBytesPerElement)(param_9);
    iVar5 = (int)dVar9;
    if (iVar4 <= iVar7) {
      if (iVar5 == 0) {
        iVar5 = _glePixelBytes(param_8,param_9);
      }
      if (param_10 == (param_10 / iVar5) * iVar5) {
        if (*(int *)(iVar8 + 0x40) != 0) {
          iVar5 = _gleSynchronizePluginBuffer(param_1,iVar8 + 0x10);
        }
        param_10 = param_10 + *(int *)(iVar8 + 0x30);
        goto LAB_000a0ba4;
      }
    }
LAB_000a0cb4:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return iVar5;
    }
    uVar3 = 0x502;
  }
LAB_000a0ce0:
  *(undefined4 *)(param_1 + 0x7574) = uVar3;
  return iVar5;
}

/* _glTexSubImage2D_FlushExec @ 0xa0d84 (64 bytes) */
int _glTexSubImage2D_FlushExec(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
  undefined4 param_10;
{
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  _glTexSubImage2D_Exec
            (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10);
  ((void (*)())_glFlush_Exec)(param_1,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
  return;
}

/* _glTexSubImage2D_CompExec @ 0xa0dc4 (128 bytes) */
int _glTexSubImage2D_CompExec(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
  undefined4 param_10;
{
  ((int (*)())_glTexSubImage2D_Comp)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10);
  _glTexSubImage2D_Exec
            (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10);
  return;
}

/* _glTexSubImage3D_ListExec @ 0xa0e44 (968 bytes) */
int _glTexSubImage3D_ListExec(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  byte bVar6;
  uint uVar7;
  int iVar8;
  
  iVar2 = param_2[10];
  if (*(short *)(param_1 + 0x4a10) < 0) {
    uVar7 = param_2[1];
    iVar4 = _gleCheckTexSubImage3DArgs
                      (param_1,*param_2,uVar7,param_2[2],param_2[3],param_2[4],param_2[5],param_2[6]
                       ,param_2[7],param_2[8],param_2[9]);
    if (iVar4 != 0) {
      iVar3 = iVar4 + uVar7 * 0x18;
      iVar8 = iVar3 + 0xc4;
      if (((((int)uVar7 < (int)(uint)*(byte *)(iVar4 + 0x8d)) ||
           ((int)(uint)*(byte *)(iVar4 + 0x8f) < (int)uVar7)) ||
          ((*(ushort *)(iVar4 + 0x94) >> (uVar7 & 0x3f) & 1) == 0)) ||
         (iVar5 = (**(code **)(param_1 + 0x4710))
                            (*(undefined4 *)(param_1 + 0x4688),
                             *(undefined4 *)(iVar4 + (uint)*(byte *)(param_1 + 0x85a8) * 4),0,uVar7,
                             param_2[2],param_2[3],param_2[4],param_2[5]), iVar5 == 0)) {
        bVar6 = *(byte *)(iVar3 + 0xcf);
        if ((bVar6 & 0x10) == 0) {
          if ((bVar6 & 0x40) == 0) {
            if (*(int *)(iVar3 + 0xd8) == 0) {
              _gleAllocateTextureLevel(param_1,iVar4,iVar8);
              bVar6 = *(byte *)(iVar3 + 0xcf);
            }
            *(byte *)(iVar3 + 0xcf) = bVar6 | 0x10;
          }
          else {
            _gleUploadPluginTextureLevel
                      (param_1,iVar4,iVar8,0,uVar7,(uint)*(byte *)(param_1 + 0x85a8));
          }
        }
        _gleModifyPluginTextureLevel
                  (param_1,iVar4,iVar8,0,uVar7,param_2[2],param_2[3],param_2[4],param_2[5]);
        uVar1 = (uint)*(byte *)(iVar3 + 0xce);
        _gleTextureImagePut(param_1,iVar8,param_2[2] + uVar1,param_2[3] + uVar1,param_2[4] + uVar1,
                            param_2[5],param_2[6],param_2[7],param_2[8],param_2[9],0,0,param_2 + 0xb
                           );
        if ((((*(uint *)(iVar4 + 0x6c) & 0x8000) == 0) || ((int)*(short *)(iVar4 + 0x60) != uVar7))
           || (iVar4 = _gleGenMipmapsToLevel(param_1,iVar4,0,uVar7,0xf,1), iVar4 == 0)) {
          *(uint *)(param_1 + 0x314) =
               *(uint *)(param_1 + 0x314) | 1 << (*(uint *)(param_1 + 0x53d4) & 0x3f);
        }
      }
      else {
        *(undefined4 *)(iVar4 + 0x20) =
             *(undefined4 *)
              ((uint)*(byte *)(param_1 + 0x85a8) * 4 + *(int *)(param_1 + 0x5148) + 0x8054);
        if (*(int *)(iVar3 + 0xd8) != 0) {
          bVar6 = *(byte *)(iVar3 + 0xcf);
          if (((bVar6 & 1) == 0) && (*(short *)(iVar4 + 0x3e) == -0x7a43)) {
            _gleFreeTextureLevel(param_1,iVar4,iVar8);
            bVar6 = *(byte *)(iVar3 + 0xcf);
          }
          *(byte *)(iVar3 + 0xcf) = bVar6 & 0xef;
          *(ushort *)(iVar4 + 0xa0) =
               *(ushort *)(iVar4 + 0xa0) &
               ((ushort)(-2 << (uVar7 & 0x1f)) | (ushort)(0xfffffffe >> 0x20 - (uVar7 & 0x1f)));
        }
        *(byte *)(iVar3 + 0xcf) = *(byte *)(iVar3 + 0xcf) | 0x40;
        if ((((*(uint *)(iVar4 + 0x6c) & 0x8000) != 0) && ((int)*(short *)(iVar4 + 0x60) == uVar7))
           && (uVar7 = uVar7 + 1, (int)uVar7 <= (int)(uint)*(byte *)(iVar4 + 0x83))) {
          iVar3 = uVar7 * 0x18 + iVar4 + 0xc4;
          do {
            if (*(int *)(iVar3 + 0x14) != 0) {
              if (((*(byte *)(iVar3 + 0xb) & 1) == 0) && (*(short *)(iVar4 + 0x3e) == -0x7a43)) {
                _gleFreeTextureLevel(param_1,iVar4,iVar3);
              }
              *(byte *)(iVar3 + 0xb) = *(byte *)(iVar3 + 0xb) & 0xef;
              *(ushort *)(iVar4 + 0xa0) = *(ushort *)(iVar4 + 0xa0) & ~(ushort)(1 << (uVar7 & 0x3f))
              ;
            }
            uVar7 = uVar7 + 1;
            *(byte *)(iVar3 + 0xb) = *(byte *)(iVar3 + 0xb) | 0x40;
            iVar3 = iVar3 + 0x18;
          } while ((int)uVar7 <= (int)(uint)*(byte *)(iVar4 + 0x83));
        }
      }
    }
  }
  else if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x502;
  }
  return iVar2 + 0x2c;
}

/* _glTexSubImage3D_Comp @ 0xa120c (700 bytes) */
int _glTexSubImage3D_Comp(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  int param_7;
  int param_8;
  int param_9;
  uint param_10;
  uint param_11;
  int param_12;
{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  double dVar9;
  
  iVar8 = *(int *)(param_1 + 0x4a6c);
  iVar5 = param_1;
  if (iVar8 == 0) {
LAB_000a12e8:
    if (param_12 == 0) {
      return iVar5;
    }
    if (param_2 == 0x806f) {
      if (((param_7 < 0) || (param_8 < 0)) || (param_9 < 0)) {
        if (*(int *)(param_1 + 0x7574) != 0) {
          return iVar5;
        }
        uVar3 = 0x501;
        goto LAB_000a141c;
      }
      if (param_11 < 0x8037) {
        if (0x8032 < param_11) {
LAB_000a13d8:
          if (param_10 == 0x1908) goto LAB_000a1424;
          bVar1 = param_10 == 0x80e1;
LAB_000a13ec:
          if (bVar1) {
LAB_000a1424:
            iVar5 = _gleImageSize(param_10,param_11,param_7,param_8);
            if (iVar5 * param_9 < 1) {
              return iVar5;
            }
            uVar2 = iVar5 * param_9 + 3U & 0xfffffffc;
            puVar6 = (undefined4 *)
                     _gleAddListItem(param_1,PTR__glTexSubImage3D_ListExec_00110400,uVar2 + 0x2c);
            if (puVar6 == (undefined4 *)0x0) {
              return 0;
            }
            *puVar6 = 0x806f;
            puVar6[1] = param_3;
            puVar6[2] = param_4;
            puVar6[3] = param_5;
            puVar6[4] = param_6;
            puVar6[10] = uVar2;
            puVar6[5] = param_7;
            puVar6[6] = param_8;
            puVar6[7] = param_9;
            puVar6[8] = param_10;
            puVar6[9] = param_11;
            uVar3 = _gleFillImage(param_1,param_7,param_8,param_9,param_10,param_11,param_12,
                                  puVar6 + 0xb);
            return uVar3;
          }
          goto LAB_000a13f0;
        }
        if (param_11 == 0x1a00) {
          if (param_10 == 0x1900) goto LAB_000a1424;
        }
        else if (param_11 < 0x1a01) {
          if (param_11 - 0x1400 < 7) {
            if (0x190a < param_10) {
              if ((param_10 == 0x8000) || ((0x7fff < param_10 && (param_10 - 0x80e0 < 2))))
              goto LAB_000a1424;
              goto LAB_000a13f0;
            }
            if (0x1901 < param_10) goto LAB_000a1424;
            bVar1 = param_10 == 0x1900;
            goto LAB_000a13ec;
          }
        }
        else if (param_11 == 0x8032) goto LAB_000a13d0;
      }
      else if (0x8361 < param_11) {
        if (param_11 < 0x8365) {
LAB_000a13d0:
          bVar1 = param_10 == 0x1907;
          goto LAB_000a13ec;
        }
        if (param_11 < 0x8369) goto LAB_000a13d8;
      }
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return iVar5;
    }
    uVar3 = 0x500;
  }
  else {
    iVar4 = _gleOffsetLimitImage3D
                      (param_1 + 0x31cc,param_7,param_8,param_9,param_10,param_11,param_12);
    iVar7 = *(int *)(iVar8 + 0x38);
    dVar9 = (double)((double (*)())_gleBytesPerElement)(param_11);
    iVar5 = (int)dVar9;
    if (iVar4 <= iVar7) {
      if (iVar5 == 0) {
        iVar5 = _glePixelBytes(param_10,param_11);
      }
      if (param_12 == (param_12 / iVar5) * iVar5) {
        if (*(int *)(iVar8 + 0x40) != 0) {
          iVar5 = _gleSynchronizePluginBuffer(param_1,iVar8 + 0x10);
        }
        param_12 = param_12 + *(int *)(iVar8 + 0x30);
        goto LAB_000a12e8;
      }
    }
LAB_000a13f0:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return iVar5;
    }
    uVar3 = 0x502;
  }
LAB_000a141c:
  *(undefined4 *)(param_1 + 0x7574) = uVar3;
  return iVar5;
}

/* _glTexSubImage3D_Exec @ 0xa14c8 (1644 bytes) */
int _glTexSubImage3D_Exec(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12)
  int param_1;
  undefined4 param_2;
  uint param_3;
  int param_4;
  int param_5;
  int param_6;
  int param_7;
  int param_8;
  int param_9;
  undefined4 param_10;
  undefined4 param_11;
  int param_12;
{
  int iVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  double dVar9;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    iVar5 = *(int *)(param_1 + 0x4a6c);
    if (iVar5 == 0) {
LAB_000a15b0:
      if (param_7 == 0) {
        return;
      }
      if (param_8 == 0) {
        return;
      }
      if (param_9 == 0) {
        return;
      }
      iVar2 = _gleCheckTexSubImage3DArgs
                        (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                         param_10,param_11);
      if (iVar2 == 0) {
        return;
      }
      iVar1 = iVar2 + param_3 * 0x18;
      iVar7 = iVar1 + 0xc4;
      iVar8 = _checkFastPath(param_1,iVar7,param_4,param_5,param_6,param_7,param_8,param_10,param_11
                             ,param_12);
      if (iVar5 != 0) {
        if ((((iVar8 != 0) && ((int)(uint)*(byte *)(iVar2 + 0x8d) <= (int)param_3)) &&
            ((int)param_3 <= (int)(uint)*(byte *)(iVar2 + 0x8f))) &&
           (((*(ushort *)(iVar2 + 0x94) >> (param_3 & 0x3f) & 1) != 0 &&
            (iVar3 = (**(code **)(param_1 + 0x4710))
                               (*(undefined4 *)(param_1 + 0x4688),
                                *(undefined4 *)(iVar2 + (uint)*(byte *)(param_1 + 0x85a8) * 4),0,
                                param_3,param_4,param_5,param_6,param_7), iVar3 != 0)))) {
          *(undefined4 *)(iVar2 + 0x20) =
               *(undefined4 *)
                ((uint)*(byte *)(param_1 + 0x85a8) * 4 + *(int *)(param_1 + 0x5148) + 0x8054);
          if (*(int *)(iVar1 + 0xd8) != 0) {
            bVar4 = *(byte *)(iVar1 + 0xcf);
            if (((bVar4 & 1) == 0) && (*(short *)(iVar2 + 0x3e) == -0x7a43)) {
              _gleFreeTextureLevel(param_1,iVar2,iVar7);
              bVar4 = *(byte *)(iVar1 + 0xcf);
            }
            *(byte *)(iVar1 + 0xcf) = bVar4 & 0xef;
            *(ushort *)(iVar2 + 0xa0) =
                 *(ushort *)(iVar2 + 0xa0) &
                 ((ushort)(-2 << (param_3 & 0x1f)) | (ushort)(0xfffffffe >> 0x20 - (param_3 & 0x1f))
                 );
          }
          *(byte *)(iVar1 + 0xcf) = *(byte *)(iVar1 + 0xcf) | 0x40;
          if ((*(uint *)(iVar2 + 0x6c) & 0x8000) == 0) {
            return;
          }
          if ((int)*(short *)(iVar2 + 0x60) != param_3) {
            return;
          }
          uVar6 = param_3 + 1;
          if ((int)(uint)*(byte *)(iVar2 + 0x83) < (int)uVar6) {
            return;
          }
          iVar5 = uVar6 * 0x18 + iVar2 + 0xc4;
          do {
            if (*(int *)(iVar5 + 0x14) != 0) {
              if (((*(byte *)(iVar5 + 0xb) & 1) == 0) && (*(short *)(iVar2 + 0x3e) == -0x7a43)) {
                _gleFreeTextureLevel(param_1,iVar2,iVar5);
              }
              *(byte *)(iVar5 + 0xb) = *(byte *)(iVar5 + 0xb) & 0xef;
              *(ushort *)(iVar2 + 0xa0) = *(ushort *)(iVar2 + 0xa0) & ~(ushort)(1 << (uVar6 & 0x3f))
              ;
            }
            uVar6 = uVar6 + 1;
            *(byte *)(iVar5 + 0xb) = *(byte *)(iVar5 + 0xb) | 0x40;
            iVar5 = iVar5 + 0x18;
          } while ((int)uVar6 <= (int)(uint)*(byte *)(iVar2 + 0x83));
          return;
        }
        if (*(int *)(iVar5 + 0x40) != 0) {
          _gleSynchronizePluginBuffer(param_1,iVar5 + 0x10);
        }
      }
      if ((((iVar8 == 0) || ((int)param_3 < (int)(uint)*(byte *)(iVar2 + 0x8d))) ||
          ((int)(uint)*(byte *)(iVar2 + 0x8f) < (int)param_3)) ||
         (((*(ushort *)(iVar2 + 0x94) >> (param_3 & 0x3f) & 1) == 0 ||
          (iVar5 = (**(code **)(param_1 + 0x4710))
                             (*(undefined4 *)(param_1 + 0x4688),
                              *(undefined4 *)(iVar2 + (uint)*(byte *)(param_1 + 0x85a8) * 4),0,
                              param_3,param_4,param_5,param_6,param_7), iVar5 == 0)))) {
        bVar4 = *(byte *)(iVar1 + 0xcf);
        if ((bVar4 & 0x10) == 0) {
          if ((bVar4 & 0x40) == 0) {
            if (*(int *)(iVar1 + 0xd8) == 0) {
              _gleAllocateTextureLevel(param_1,iVar2,iVar7);
              bVar4 = *(byte *)(iVar1 + 0xcf);
            }
            *(byte *)(iVar1 + 0xcf) = bVar4 | 0x10;
          }
          else {
            _gleUploadPluginTextureLevel
                      (param_1,iVar2,iVar7,0,param_3,(uint)*(byte *)(param_1 + 0x85a8));
          }
        }
        _gleModifyPluginTextureLevel(param_1,iVar2,iVar7,0,param_3,param_4,param_5,param_6,param_7);
        uVar6 = (uint)*(byte *)(iVar1 + 0xce);
        _gleTextureImagePut(param_1,iVar7,param_4 + uVar6,param_5 + uVar6,param_6 + uVar6,param_7,
                            param_8,param_9,param_10,param_11,0,param_1 + 0x31cc,param_12);
        if ((((*(uint *)(iVar2 + 0x6c) & 0x8000) != 0) && ((int)*(short *)(iVar2 + 0x60) == param_3)
            ) && (iVar5 = _gleGenMipmapsToLevel(param_1,iVar2,0,param_3,0xf,1), iVar5 != 0)) {
          return;
        }
        *(uint *)(param_1 + 0x314) =
             *(uint *)(param_1 + 0x314) | 1 << (*(uint *)(param_1 + 0x53d4) & 0x3f);
        return;
      }
      *(undefined4 *)(iVar2 + 0x20) =
           *(undefined4 *)
            ((uint)*(byte *)(param_1 + 0x85a8) * 4 + *(int *)(param_1 + 0x5148) + 0x8054);
      if (*(int *)(iVar1 + 0xd8) != 0) {
        bVar4 = *(byte *)(iVar1 + 0xcf);
        if (((bVar4 & 1) == 0) && (*(short *)(iVar2 + 0x3e) == -0x7a43)) {
          _gleFreeTextureLevel(param_1,iVar2,iVar7);
          bVar4 = *(byte *)(iVar1 + 0xcf);
        }
        *(byte *)(iVar1 + 0xcf) = bVar4 & 0xef;
        *(ushort *)(iVar2 + 0xa0) =
             *(ushort *)(iVar2 + 0xa0) &
             ((ushort)(-2 << (param_3 & 0x1f)) | (ushort)(0xfffffffe >> 0x20 - (param_3 & 0x1f)));
      }
      *(byte *)(iVar1 + 0xcf) = *(byte *)(iVar1 + 0xcf) | 0x40;
      if ((*(uint *)(iVar2 + 0x6c) & 0x8000) == 0) {
        return;
      }
      if ((int)*(short *)(iVar2 + 0x60) != param_3) {
        return;
      }
      uVar6 = param_3 + 1;
      if ((int)(uint)*(byte *)(iVar2 + 0x83) < (int)uVar6) {
        return;
      }
      iVar5 = uVar6 * 0x18 + iVar2 + 0xc4;
      do {
        if (*(int *)(iVar5 + 0x14) != 0) {
          if (((*(byte *)(iVar5 + 0xb) & 1) == 0) && (*(short *)(iVar2 + 0x3e) == -0x7a43)) {
            _gleFreeTextureLevel(param_1,iVar2,iVar5);
          }
          *(byte *)(iVar5 + 0xb) = *(byte *)(iVar5 + 0xb) & 0xef;
          *(ushort *)(iVar2 + 0xa0) = *(ushort *)(iVar2 + 0xa0) & ~(ushort)(1 << (uVar6 & 0x3f));
        }
        uVar6 = uVar6 + 1;
        *(byte *)(iVar5 + 0xb) = *(byte *)(iVar5 + 0xb) | 0x40;
        iVar5 = iVar5 + 0x18;
      } while ((int)uVar6 <= (int)(uint)*(byte *)(iVar2 + 0x83));
      return;
    }
    iVar1 = _gleOffsetLimitImage3D
                      (param_1 + 0x31cc,param_7,param_8,param_9,param_10,param_11,param_12);
    iVar8 = *(int *)(iVar5 + 0x38);
    dVar9 = (double)((double (*)())_gleBytesPerElement)(param_11);
    iVar2 = (int)dVar9;
    if (iVar1 <= iVar8) {
      if (iVar2 == 0) {
        iVar2 = _glePixelBytes(param_10,param_11);
      }
      if (param_12 == (param_12 / iVar2) * iVar2) {
        param_12 = param_12 + *(int *)(iVar5 + 0x30);
        goto LAB_000a15b0;
      }
    }
  }
  if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x502;
  }
  return;
}

/* _glTexSubImage3D_CompExec @ 0xa1b34 (152 bytes) */
int _glTexSubImage3D_CompExec(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12)
  undefined4 param_1;
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
  undefined4 param_12;
{
  ((int (*)())_glTexSubImage3D_Comp)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,
             param_11,param_12);
  ((int (*)())_glTexSubImage3D_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,
             param_11,param_12);
  return;
}

/* _glVertex2_ListExec @ 0xa1bcc (84 bytes) */
int _glVertex2_ListExec(param_1, param_2)
  int param_1;
  float *param_2;
{
  code *pcVar1;
  
  pcVar1 = *(code **)(param_1 + 0x4884);
  if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
    pcVar1 = *(code **)(param_1 + 0x28);
  }
  (*pcVar1)(param_1,(double)*param_2,(double)param_2[1],(double)*(float *)(param_1 + 0x20),
            (double)*(float *)(param_1 + 0x24));
  return 8;
}

/* _glVertex4_ListExec @ 0xa1c20 (80 bytes) */
int _glVertex4_ListExec(param_1, param_2)
  int param_1;
  float *param_2;
{
  code *pcVar1;
  
  pcVar1 = *(code **)(param_1 + 0x4884);
  if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
    pcVar1 = *(code **)(param_1 + 0x28);
  }
  (*pcVar1)(param_1,(double)*param_2,(double)param_2[1],(double)param_2[2],(double)param_2[3]);
  return 0x10;
}

/* _glVertex2d_Comp @ 0xa1c70 (108 bytes) */
float * _glVertex2d_Comp(undefined4 param_1,double fparam_1,double fparam_2)
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glVertex2_ListExec_00110418,8);
  if (pfVar1 != (float *)0x0) {
    *pfVar1 = (float)fparam_1;
    pfVar1[1] = (float)fparam_2;
  }
  return pfVar1;
}

/* _glVertex2d_CompExec @ 0xa1cdc (80 bytes) */
void _glVertex2d_CompExec(undefined4 param_1,double fparam_1,double fparam_2)
{
  ((float * (*)())_glVertex2d_Comp)(param_1,fparam_1,fparam_2);
  ((void (*)())_glVertex2d_Exec)(param_1,fparam_1,fparam_2);
  return;
}

/* _glVertex2dv_Exec @ 0xa1d2c (60 bytes) */
int _glVertex2dv_Exec(param_1, param_2)
  int param_1;
  double *param_2;
{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x4884);
  if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
    UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x28);
  }
                    
                    
  (*((int (*)(int,int,double,double,double,double))UNRECOVERED_JUMPTABLE))
            (param_1, param_2, (double)(float)*param_2, (double)(float)param_2[1], (double)*(float *)(param_1 + 0x20), (double)*(float *)(param_1 + 0x24));
  return;
}

/* _glVertex2dv_Comp @ 0xa1d68 (96 bytes) */
int _glVertex2dv_Comp(param_1, param_2)
  undefined4 param_1;
  double *param_2;
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glVertex2_ListExec_00110418,8);
  if (pfVar1 != (float *)0x0) {
    *pfVar1 = (float)*param_2;
    pfVar1[1] = (float)param_2[1];
  }
  return pfVar1;
}

/* _glVertex2dv_CompExec @ 0xa1dc8 (56 bytes) */
int _glVertex2dv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glVertex2dv_Comp)(param_1,param_2);
  ((int (*)())_glVertex2dv_Exec)(param_1,param_2);
  return;
}

/* _glVertex3dv_Exec @ 0xa1e00 (64 bytes) */
int _glVertex3dv_Exec(param_1, param_2)
  int param_1;
  double *param_2;
{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x4884);
  if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
    UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x28);
  }
                    
                    
  (*((int (*)(int,int,double,double,double,double))UNRECOVERED_JUMPTABLE))
            (param_1, param_2, (double)(float)*param_2, (double)(float)param_2[1], (double)(float)param_2[2], (double)*(float *)(param_1 + 0x24));
  return;
}

/* _glVertex3dv_Comp @ 0xa1e40 (108 bytes) */
int _glVertex3dv_Comp(param_1, param_2)
  undefined4 param_1;
  double *param_2;
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glVertex3_ListExec_00110414,0xc);
  if (pfVar1 != (float *)0x0) {
    *pfVar1 = (float)*param_2;
    pfVar1[1] = (float)param_2[1];
    pfVar1[2] = (float)param_2[2];
  }
  return pfVar1;
}

/* _glVertex3dv_CompExec @ 0xa1eac (56 bytes) */
int _glVertex3dv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glVertex3dv_Comp)(param_1,param_2);
  ((int (*)())_glVertex3dv_Exec)(param_1,param_2);
  return;
}

/* _glVertex4d_Exec @ 0xa1ee4 (48 bytes) */
void _glVertex4d_Exec(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x4884);
  if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
    UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x28);
  }
                    
                    
  (*((int (*)(int,double,double,double,double))UNRECOVERED_JUMPTABLE))
            (param_1, (double)(float)fparam_1, (double)(float)fparam_2, (double)(float)fparam_3, (double)(float)fparam_4);
  return;
}

/* _glVertex4d_Comp @ 0xa1f14 (108 bytes) */
void _glVertex4d_Comp(undefined4 param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glVertex4_ListExec_00110410,0x10);
  if (pfVar1 != (float *)0x0) {
    *pfVar1 = (float)fparam_1;
    pfVar1[1] = (float)fparam_2;
    pfVar1[2] = (float)fparam_3;
    pfVar1[3] = (float)fparam_4;
  }
  FUN_00008b68();
  return;
}

/* _glVertex4d_CompExec @ 0xa1f80 (96 bytes) */
void _glVertex4d_CompExec(undefined4 param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  ((void (*)())_glVertex4d_Comp)(param_1,fparam_1,fparam_2,fparam_3,fparam_4);
  ((void (*)())_glVertex4d_Exec)(param_1,fparam_1,fparam_2,fparam_3,fparam_4);
  return;
}

/* _glVertex4dv_Exec @ 0xa1fe0 (64 bytes) */
int _glVertex4dv_Exec(param_1, param_2)
  int param_1;
  double *param_2;
{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x4884);
  if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
    UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x28);
  }
                    
                    
  (*((int (*)(int,int,double,double,double,double))UNRECOVERED_JUMPTABLE))
            (param_1, param_2, (double)(float)*param_2, (double)(float)param_2[1], (double)(float)param_2[2], (double)(float)param_2[3]);
  return;
}

/* _glVertex4dv_Comp @ 0xa2020 (120 bytes) */
int _glVertex4dv_Comp(param_1, param_2)
  undefined4 param_1;
  double *param_2;
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glVertex4_ListExec_00110410,0x10);
  if (pfVar1 != (float *)0x0) {
    *pfVar1 = (float)*param_2;
    pfVar1[1] = (float)param_2[1];
    pfVar1[2] = (float)param_2[2];
    pfVar1[3] = (float)param_2[3];
  }
  return pfVar1;
}

/* _glVertex4dv_CompExec @ 0xa2098 (56 bytes) */
int _glVertex4dv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glVertex4dv_Comp)(param_1,param_2);
  ((int (*)())_glVertex4dv_Exec)(param_1,param_2);
  return;
}

/* _glVertex2f_Comp @ 0xa20d0 (100 bytes) */
float * _glVertex2f_Comp(undefined4 param_1,double fparam_1,double fparam_2)
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glVertex2_ListExec_00110418,8);
  if (pfVar1 != (float *)0x0) {
    pfVar1[1] = (float)fparam_2;
    *pfVar1 = (float)fparam_1;
  }
  return pfVar1;
}

/* _glVertex2f_CompExec @ 0xa2134 (80 bytes) */
void _glVertex2f_CompExec(undefined4 param_1,double fparam_1,double fparam_2)
{
  ((float * (*)())_glVertex2f_Comp)(param_1,fparam_1,fparam_2);
  _glVertex2f_Exec(param_1);
  return;
}

/* _glVertex2fv_Exec @ 0xa2184 (52 bytes) */
int _glVertex2fv_Exec(param_1, param_2)
  int param_1;
  float *param_2;
{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x4884);
  if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
    UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x28);
  }
                    
                    
  (*((int (*)(int,int,double,double,double,double))UNRECOVERED_JUMPTABLE))
            (param_1, param_2, (double)*param_2, (double)param_2[1], (double)*(float *)(param_1 + 0x20), (double)*(float *)(param_1 + 0x24));
  return;
}

/* _glVertex2fv_Comp @ 0xa21b8 (88 bytes) */
int _glVertex2fv_Comp(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glVertex2_ListExec_00110418,8);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *param_2;
    puVar1[1] = param_2[1];
  }
  return puVar1;
}

/* _glVertex2fv_CompExec @ 0xa2210 (56 bytes) */
int _glVertex2fv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glVertex2fv_Comp)(param_1,param_2);
  ((int (*)())_glVertex2fv_Exec)(param_1,param_2);
  return;
}

/* _glVertex3fv_Exec @ 0xa2248 (52 bytes) */
int _glVertex3fv_Exec(param_1, param_2)
  int param_1;
  float *param_2;
{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x4884);
  if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
    UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x28);
  }
                    
                    
  (*((int (*)(int,int,double,double,double,double))UNRECOVERED_JUMPTABLE))
            (param_1, param_2, (double)*param_2, (double)param_2[1], (double)param_2[2], (double)*(float *)(param_1 + 0x24));
  return;
}

/* _glVertex3fv_Comp @ 0xa227c (96 bytes) */
int _glVertex3fv_Comp(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glVertex3_ListExec_00110414,0xc);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *param_2;
    puVar1[1] = param_2[1];
    puVar1[2] = param_2[2];
  }
  return puVar1;
}

/* _glVertex3fv_CompExec @ 0xa22dc (56 bytes) */
int _glVertex3fv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glVertex3fv_Comp)(param_1,param_2);
  ((int (*)())_glVertex3fv_Exec)(param_1,param_2);
  return;
}

/* _glVertex4f_Comp @ 0xa2314 (92 bytes) */
void _glVertex4f_Comp(undefined4 param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glVertex4_ListExec_00110410,0x10);
  if (pfVar1 != (float *)0x0) {
    pfVar1[3] = (float)fparam_4;
    *pfVar1 = (float)fparam_1;
    pfVar1[1] = (float)fparam_2;
    pfVar1[2] = (float)fparam_3;
  }
  FUN_00008b68();
  return;
}

