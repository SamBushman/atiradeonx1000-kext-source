#include "decls.h"

/* _glGetTexLevelParameterfv_Exec_body @ 0x9dbfc (1068 bytes) */
void _glGetTexLevelParameterfv_Exec_body(glContext, param_2, param_3, param_4, param_5)
  int glContext;
  int param_2;
  uint param_3;
  undefined *param_4;
  float *param_5;
{
  bool bVar1;
  char cVar2;
  undefined4 glErrorCode;
  uint uVar4;
  int iVar5;
  int remaining;
  int loopIndex;
  int *srcCursor;
  int iVar7;
  int iVar8;
  int framebufferObject;
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
  iVar7 = _gleLookUpTexture(glContext,param_2);
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_0009dd64;
  }
  if (iVar7 == 0) goto LAB_0009dd54;
  if (0xe < param_3) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x501;
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
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x500;
LAB_0009dd64:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
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
  iVar5 = *(int *)(glContext + 0x50ac);
  fparam_1 = extraout_f1;
  if (iVar5 != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    fparam_1 = extraout_f1_00;
  }
  if (*(char *)(glContext + 0x4691) == '\0') goto LAB_0009df84;
  framebufferObject = *(int *)(glContext + 0x744c);
  piVar12 = (int *)(glContext + 0x310);
  cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
  if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
    ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,uVar11,puVar9,pfVar10,in_r8,iVar5,fparam_1,in_f2,in_f3,in_f4,
               in_f5,in_f6,in_f7,in_f8);
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
  }
  if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_0009de7c:
    uVar11 = *(uint *)(glContext + 0x31c);
  }
  else {
    loopIndex = 0;
    srcCursor = (int *)(glContext + 0x324);
    do {
      iVar8 = *srcCursor;
      srcCursor = srcCursor + 1;
      if (iVar8 != 0) {
        *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
        break;
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex < 9);
    uVar11 = *(uint *)(glContext + 0x31c);
    if ((uVar11 & 0x15555) != 0) {
      if (*(char *)(glContext + 0x2e54) != '\0') {
        _gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
      }
      if (*(char *)(glContext + 0x3094) != '\0') {
        _gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
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
    bVar1 = ((*piVar12 == 0 && *(int *)(glContext + 0x314) == 0) && uVar11 == 0) &&
            *(int *)(glContext + 800) == 0;
  }
  else {
    bVar1 = (((*piVar12 == 0 && *(int *)(glContext + 0x314) == 0) &&
             (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && uVar11 == 0) &&
            *(int *)(glContext + 800) == 0;
  }
  if (!bVar1) {
    if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
      uVar11 = (**(code **)(glContext + 0x4788))
                         (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,piVar12);
      if ((((uVar11 & 3) != (uint)*(byte *)(glContext + 0x7580)) ||
          ((uVar11 & 4) != (uint)*(byte *)(glContext + 0x7581))) ||
         ((uVar11 & 8) != (uint)(*(char *)(glContext + 0x759d) == '\0'))) {
        if ((uVar11 & 4) == 0) {
          uVar11 = uVar11 & 0xfffffffe;
          *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
        }
        _gleUpdateDispatchCodeChange(glContext,uVar11);
      }
    }
    else {
      _gleSwitchToNonRevertRenderer(glContext);
    }
  }
  remaining = 0x13;
  do {
    *piVar12 = 0;
    piVar12 = piVar12 + 1;
    remaining = remaining + -1;
  } while (remaining != 0);
LAB_0009df84:
  if ((local_38[0] == 0xffffffff) || ((*(ushort *)(iVar7 + 0x24) & 0x100) != 0)) {
    (**(code **)(glContext + 0x479c))
              (*(undefined4 *)(glContext + 0x4688),
               *(undefined4 *)(iVar7 + (uint)*(byte *)(glContext + 0x85a8) * 4),uVar4,param_3,param_4,
               local_38);
  }
  if ((param_4 == ((unsigned char *)0x00001003)) && (local_38[0] == 0)) {
    local_38[0] = 1;
  }
  *param_5 = (float)((double)CONCAT44(0x43300000,local_38[0] ^ 0x80000000) - DOUBLE_00108d58);
  return;
}

/* _glTexParameterf_ListExec @ 0x9e028 (52 bytes) */
int _glTexParameterf_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  _glTexParameterF_Exec(glContext,*listRecord,listRecord[1],listRecord + 2);
  return 0x18;
}

/* _glTexParameterF_Comp @ 0x9e05c (388 bytes) */
int _glTexParameterF_Comp(glContext, param_2, param_3, param_4)
  undefined4 glContext;
  undefined4 param_2;
  undefined *param_3;
  undefined4 *param_4;
{
  undefined *puVar1;
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glTexParameterf_ListExec_001103f0,0x18);
  if (listRecord == (undefined4 *)0x0) {
    return listRecord;
  }
  *listRecord = param_2;
  listRecord[1] = param_3;
  if (param_3 == (undefined *)0x8191) goto LAB_0009e1a0;
  if (param_3 < (undefined *)0x8192) {
    if (param_3 == (undefined *)0x8066) goto LAB_0009e1a0;
    if (param_3 < (undefined *)0x8067) {
      if (param_3 == ((unsigned char *)0x00001004)) {
LAB_0009e1ac:
        listRecord[2] = *param_4;
        listRecord[3] = param_4[1];
        listRecord[4] = param_4[2];
        listRecord[5] = param_4[3];
        return listRecord;
      }
      if (param_3 < ((unsigned char *)0x00001004)) {
        return listRecord;
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
      return listRecord;
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
            return listRecord;
          }
          goto LAB_0009e1ac;
        }
        goto LAB_0009e1a0;
      }
      puVar1 = (undefined *)0x8a7f;
    }
LAB_0009e198:
    if (param_3 != puVar1) {
      return listRecord;
    }
  }
LAB_0009e1a0:
  listRecord[2] = *param_4;
  return listRecord;
}

/* _glTexParameterf_Comp @ 0x9e1e0 (40 bytes) */
undefined4 _glTexParameterf_Comp(undefined4 glContext,undefined4 target,undefined4 pname,float param)
{
  undefined4 uVar1;
  float fStack00000024;
  
  fStack00000024 = (float)param;
  uVar1 = ((int (*)())_glTexParameterF_Comp)(glContext,target,pname,&STACKARG(0x24));
  return uVar1;
}

/* _glTexParameterf_CompExec @ 0x9e208 (80 bytes) */
void _glTexParameterf_CompExec(undefined4 glContext,undefined4 target,undefined4 pname,float param)
{
  ((undefined4 (*)())_glTexParameterf_Comp)(glContext,target,pname,param);
  ((void (*)())_glTexParameterf_Exec)(glContext,target,pname,param);
  return;
}

/* _glTexParameterfv_CompExec @ 0x9e25c (72 bytes) */
void _glTexParameterfv_CompExec(glContext, target, pname, params)
  undefined4 glContext;
  undefined4 target;
  undefined4 pname;
  undefined4 params;
{
  _glTexParameterfv_Comp(glContext,target,pname,params);
  _glTexParameterfv_Exec(glContext,target,pname,params);
  return;
}

/* _glTexParameteri_ListExec @ 0x9e2a4 (52 bytes) */
int _glTexParameteri_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  _glTexParameterI_Exec(glContext,*listRecord,listRecord[1],listRecord + 2);
  return 0x18;
}

/* _glTexParameterI_Comp @ 0x9e2d8 (388 bytes) */
int _glTexParameterI_Comp(glContext, param_2, param_3, param_4)
  undefined4 glContext;
  undefined4 param_2;
  undefined *param_3;
  undefined4 *param_4;
{
  undefined *puVar1;
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glTexParameteri_ListExec_001103ec,0x18);
  if (listRecord == (undefined4 *)0x0) {
    return listRecord;
  }
  *listRecord = param_2;
  listRecord[1] = param_3;
  if (param_3 == (undefined *)0x8191) goto LAB_0009e41c;
  if (param_3 < (undefined *)0x8192) {
    if (param_3 == (undefined *)0x8066) goto LAB_0009e41c;
    if (param_3 < (undefined *)0x8067) {
      if (param_3 == ((unsigned char *)0x00001004)) {
LAB_0009e428:
        listRecord[2] = *param_4;
        listRecord[3] = param_4[1];
        listRecord[4] = param_4[2];
        listRecord[5] = param_4[3];
        return listRecord;
      }
      if (param_3 < ((unsigned char *)0x00001004)) {
        return listRecord;
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
      return listRecord;
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
            return listRecord;
          }
          goto LAB_0009e428;
        }
        goto LAB_0009e41c;
      }
      puVar1 = (undefined *)0x8a7f;
    }
LAB_0009e414:
    if (param_3 != puVar1) {
      return listRecord;
    }
  }
LAB_0009e41c:
  listRecord[2] = *param_4;
  return listRecord;
}

/* _glTexParameteri_Comp @ 0x9e45c (40 bytes) */
int _glTexParameteri_Comp(glContext, target, pname, param)
  undefined4 glContext;
  undefined4 target;
  undefined4 pname;
  undefined4 param;
{
  unsigned int ghidra_home[8] = { glContext, target, pname, param, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  undefined4 uVar1;
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 12)) = param;
  uVar1 = ((int (*)())_glTexParameterI_Comp)(glContext,target,pname,&(*(unsigned int *)((unsigned char *)ghidra_home + 12)));
  return uVar1;
}

/* _glTexParameteri_CompExec @ 0x9e484 (72 bytes) */
void _glTexParameteri_CompExec(glContext, target, pname, param)
  undefined4 glContext;
  undefined4 target;
  undefined4 pname;
  undefined4 param;
{
  ((int (*)())_glTexParameteri_Comp)(glContext,target,pname,param);
  _glTexParameteri_Exec(glContext,target,pname,param);
  return;
}

/* _glTexParameteriv_CompExec @ 0x9e4d4 (72 bytes) */
void _glTexParameteriv_CompExec(glContext, target, pname, params)
  undefined4 glContext;
  undefined4 target;
  undefined4 pname;
  undefined4 params;
{
  _glTexParameteriv_Comp(glContext,target,pname,params);
  _glTexParameteriv_Exec(glContext,target,pname,params);
  return;
}

/* _glGetTexParameterPointervAPPLE_Exec @ 0x9e51c (140 bytes) */
void _glGetTexParameterPointervAPPLE_Exec(glContext, target, pname, params)
  int glContext;
  undefined4 target;
  int pname;
  undefined4 *params;
{
  undefined4 glErrorCode;
  int iVar2;
  
  iVar2 = _gleLookUpNonProxyTexture(glContext,target);
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((iVar2 != 0) && (pname == 0x85b8)) {
      *params = *(undefined4 *)(iVar2 + 0x74);
      return;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x500;
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glTexImage1D_ListExec @ 0x9e5a8 (604 bytes) */
int _glTexImage1D_ListExec(glContext, param_2)
  int glContext;
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
                    (glContext,*param_2,iVar6,param_2[2],iVar7,param_2[4],param_2[5],param_2[6]);
  if (iVar4 != 0) {
    uVar2 = *(ushort *)(iVar4 + 0x24);
    if ((uVar2 & 0x3c00) != 0x1000) {
      if ((uVar2 & 0x3c00) == 0) {
        *(ushort *)(iVar4 + 0x24) = uVar2 | 0x1000;
      }
      else if ((uVar2 & 0xc00) != 0) {
        if (*(int *)(glContext + 0x7574) != 0) {
          return iVar5;
        }
        *(undefined4 *)(glContext + 0x7574) = 0x502;
        return iVar5;
      }
    }
    if (((*(uint *)(glContext + 0x3410) & 1) != 0) && (*(short *)(glContext + 13000) == -0x7fea)) {
      iVar7 = (iVar7 - *(int *)(glContext + 0x32d0)) + 1;
    }
    iVar3 = iVar4 + iVar6 * 0x18;
    iVar8 = iVar3 + 0xc4;
    if ((*(byte *)(iVar3 + 0xcf) & 0x20) != 0) {
      _gleDeletePluginTextureLevel(glContext,iVar4,iVar8,0,iVar6);
      if (*(int *)(iVar3 + 0xd8) != 0) {
        bVar1 = *(byte *)(iVar3 + 0xcf);
        if ((bVar1 & 1) == 0) {
          _gleFreeTextureLevel(glContext,iVar4,iVar8);
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
                      (glContext,iVar4,iVar8,param_2[2],iVar7,1,1,param_2[4],param_2[5],param_2[6],0,
                       param_2 + 8);
    if (iVar7 != 0) {
      _gleTextureImagePut(glContext,iVar8,0,0,0,param_2[3],1,1,param_2[5],param_2[6],1,0,param_2 + 8);
    }
    _gleCreatePluginTextureLevel(glContext,iVar4,iVar8,0,iVar6,param_2[2]);
    if ((((*(uint *)(iVar4 + 0x6c) & 0x8000) == 0) || (*(short *)(iVar4 + 0x60) != iVar6)) ||
       (iVar4 = _gleGenMipmapsToLevel(glContext,iVar4,0,iVar6,0xf,1), iVar4 == 0)) {
      *(uint *)(glContext + 0x314) =
           *(uint *)(glContext + 0x314) | 1 << (*(uint *)(glContext + 0x53d4) & 0x3f);
    }
  }
  return iVar5;
}

/* _glTexImage1D_Comp @ 0x9e804 (664 bytes) */
int _glTexImage1D_Comp(glContext, target, level, internalformat, width, border, format, type, pixels)
  int glContext;
  int target;
  int level;
  int internalformat;
  int width;
  int border;
  uint format;
  uint type;
  int pixels;
{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 glErrorCode;
  int iVar4;
  int iVar5;
  int rowBytes;
  int *listRecord;
  int iVar7;
  int iVar8;
  double dVar9;
  
  iVar8 = *(int *)(glContext + 0x4a6c);
  iVar5 = glContext;
  if (iVar8 != 0) {
    iVar4 = _gleOffsetLimitImage(glContext + 0x31cc,width,1,format,type,pixels);
    iVar7 = *(int *)(iVar8 + 0x38);
    dVar9 = (double)((double (*)())_gleBytesPerElement)(type);
    iVar5 = (int)dVar9;
    if (iVar4 <= iVar7) {
      if (iVar5 == 0) {
        iVar5 = _glePixelBytes(format,type);
      }
      if (pixels == (pixels / iVar5) * iVar5) {
        if (*(int *)(iVar8 + 0x40) != 0) {
          _gleSynchronizePluginBuffer(glContext,iVar8 + 0x10);
        }
        pixels = pixels + *(int *)(iVar8 + 0x30);
        goto LAB_0009e8e4;
      }
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return iVar5;
    }
    glErrorCode = 0x502;
    goto LAB_0009e9f8;
  }
LAB_0009e8e4:
  if (target == 0x8063) {
    uVar3 = ((int (*)())_glTexImage1D_Exec)(glContext,0x8063,level,internalformat,width,border,format,type,
                               pixels);
    return uVar3;
  }
  if (type < 0x8037) {
    if (type < 0x8033) {
      if (type != 0x1a00) {
        if (type < 0x1a01) {
          if (type - 0x1400 < 7) {
            if (format < 0x190b) {
              if (0x1902 < format) goto LAB_0009ea00;
              goto LAB_0009e9e0;
            }
            if ((format == 0x8000) || ((0x7fff < format && (format - 0x80e0 < 2))))
            goto LAB_0009ea00;
          }
        }
        else if (type == 0x8032) goto LAB_0009e9c0;
        goto LAB_0009e9e8;
      }
LAB_0009e9e0:
      bVar1 = format == 0x1900;
    }
    else {
LAB_0009e9c8:
      if (format == 0x1908) goto LAB_0009ea00;
      bVar1 = format == 0x80e1;
    }
LAB_0009e9e4:
    if (bVar1) {
LAB_0009ea00:
      rowBytes = _gleRowBytes(format,type,width);
      if (rowBytes < 1) {
        return rowBytes;
      }
      uVar2 = rowBytes + 3U & 0xfffffffc;
      listRecord = (int *)_gleAddListItem(glContext,PTR__glTexImage1D_ListExec_001103fc,uVar2 + 0x20);
      if (listRecord == (int *)0x0) {
        return 0;
      }
      *listRecord = target;
      listRecord[1] = level;
      listRecord[2] = internalformat;
      listRecord[4] = border;
      listRecord[7] = uVar2;
      listRecord[3] = width;
      listRecord[5] = format;
      listRecord[6] = type;
      if (pixels == 0) {
        return (int)listRecord;
      }
      uVar3 = _gleFillImage(glContext,width,1,1,format,type,pixels,listRecord + 8);
      return uVar3;
    }
  }
  else if (0x8361 < type) {
    if (type < 0x8365) {
LAB_0009e9c0:
      bVar1 = format == 0x1907;
      goto LAB_0009e9e4;
    }
    if (type < 0x8369) goto LAB_0009e9c8;
  }
LAB_0009e9e8:
  if (*(int *)(glContext + 0x7574) != 0) {
    return iVar5;
  }
  glErrorCode = 0x500;
LAB_0009e9f8:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return iVar5;
}

/* _glTexImage1D_Exec @ 0x9ea9c (812 bytes) */
int _glTexImage1D_Exec(glContext, target, level, internalformat, width, border, format, type, pixels)
  int glContext;
  undefined4 target;
  int level;
  undefined4 internalformat;
  int width;
  undefined4 border;
  undefined4 format;
  undefined4 type;
  int pixels;
{
  byte bVar1;
  ushort uVar2;
  undefined4 glErrorCode;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  double dVar8;
  
  if (-1 < *(short *)(glContext + 0x4a10)) goto LAB_0009ebf4;
  if ((pixels == 0) && (*(char *)(glContext + 0x31e6) != '\0')) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x501;
    goto LAB_0009ec04;
  }
  iVar6 = *(int *)(glContext + 0x4a6c);
  if (iVar6 == 0) {
LAB_0009eb98:
    iVar6 = _gleCheckTexImage1DArgs(glContext,target,level,internalformat,width,border,format,type)
    ;
    if (iVar6 == 0) {
      return;
    }
    uVar2 = *(ushort *)(iVar6 + 0x24);
    if ((uVar2 & 0x3c00) == 0x1000) {
LAB_0009ec0c:
      iVar5 = width;
      if (((*(uint *)(glContext + 0x3410) & 1) != 0) && (*(short *)(glContext + 13000) == -0x7fea)) {
        iVar5 = (width - *(int *)(glContext + 0x32d0)) + 1;
      }
      iVar4 = iVar6 + level * 0x18;
      iVar7 = iVar4 + 0xc4;
      if ((*(byte *)(iVar4 + 0xcf) & 0x20) != 0) {
        _gleDeletePluginTextureLevel(glContext,iVar6,iVar7,0,level);
        if (*(int *)(iVar4 + 0xd8) != 0) {
          bVar1 = *(byte *)(iVar4 + 0xcf);
          if ((bVar1 & 1) == 0) {
            _gleFreeTextureLevel(glContext,iVar6,iVar7);
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
                        (glContext,iVar6,iVar7,internalformat,iVar5,1,1,border,format,type,1,pixels);
      if ((iVar4 != 0) && (pixels != 0)) {
        _gleTextureImagePut(glContext,iVar7,0,0,0,width,1,1,format,type,1,glContext + 0x31cc,
                            pixels);
      }
      if ((((iVar5 != 0) &&
           (_gleCreatePluginTextureLevel(glContext,iVar6,iVar7,0,level,internalformat),
           (*(uint *)(iVar6 + 0x6c) & 0x8000) != 0)) && (*(short *)(iVar6 + 0x60) == level)) &&
         (iVar6 = _gleGenMipmapsToLevel(glContext,iVar6,0,level,0xf,1), iVar6 != 0)) {
        return;
      }
      *(uint *)(glContext + 0x314) =
           *(uint *)(glContext + 0x314) | 1 << (*(uint *)(glContext + 0x53d4) & 0x3f);
      return;
    }
    if ((uVar2 & 0x3c00) == 0) {
      *(ushort *)(iVar6 + 0x24) = uVar2 | 0x1000;
      goto LAB_0009ec0c;
    }
    if ((uVar2 & 0xc00) == 0) goto LAB_0009ec0c;
  }
  else {
    iVar4 = _gleOffsetLimitImage(glContext + 0x31cc,width,1,format,type,pixels);
    iVar7 = *(int *)(iVar6 + 0x38);
    dVar8 = (double)((double (*)())_gleBytesPerElement)(type);
    iVar5 = (int)dVar8;
    if (iVar4 <= iVar7) {
      if (iVar5 == 0) {
        iVar5 = _glePixelBytes(format,type);
      }
      if (pixels == (pixels / iVar5) * iVar5) {
        if (*(int *)(iVar6 + 0x40) != 0) {
          _gleSynchronizePluginBuffer(glContext,iVar6 + 0x10);
        }
        pixels = pixels + *(int *)(iVar6 + 0x30);
        goto LAB_0009eb98;
      }
    }
  }
LAB_0009ebf4:
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x502;
LAB_0009ec04:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glTexImage1D_CompExec @ 0x9edc8 (116 bytes) */
void _glTexImage1D_CompExec(glContext, target, level, internalformat, width, border, format, type, pixels)
  undefined4 glContext;
  undefined4 target;
  undefined4 level;
  undefined4 internalformat;
  undefined4 width;
  undefined4 border;
  undefined4 format;
  undefined4 type;
  undefined4 pixels;
{
  ((int (*)())_glTexImage1D_Comp)(glContext,target,level,internalformat,width,border,format,type,pixels);
  ((int (*)())_glTexImage1D_Exec)(glContext,target,level,internalformat,width,border,format,type,pixels);
  return;
}

/* _glTexImage2D_ListExec @ 0x9ee3c (704 bytes) */
int _glTexImage2D_ListExec(glContext, param_2)
  int glContext;
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
                    (glContext,*param_2,iVar8,param_2[2],iVar9,iVar10,param_2[5],param_2[6],param_2[7]
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
      if (*(int *)(glContext + 0x7574) != 0) {
        return iVar7;
      }
      *(undefined4 *)(glContext + 0x7574) = 0x502;
      return iVar7;
    }
  }
  if ((*(uint *)(glContext + 0x3410) & 2) == 0) {
    if (((*(uint *)(glContext + 0x3410) & 4) == 0) || (*(short *)(glContext + 0x3348) != -0x7fea))
    goto LAB_0009ef44;
    iVar6 = *(int *)(glContext + 0x3354);
    iVar3 = *(int *)(glContext + 0x3350);
  }
  else {
    if (*(short *)(glContext + 0x3308) != -0x7fea) goto LAB_0009ef44;
    iVar6 = *(int *)(glContext + 0x3314);
    iVar3 = *(int *)(glContext + 0x3310);
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
    _gleDeletePluginTextureLevel(glContext,iVar5,iVar6,uVar4,iVar8);
    if (*(int *)(iVar3 + 0xd8) != 0) {
      bVar1 = *(byte *)(iVar3 + 0xcf);
      if ((bVar1 & 1) == 0) {
        _gleFreeTextureLevel(glContext,iVar5,iVar6);
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
                    (glContext,iVar5,iVar6,param_2[2],iVar9,iVar10,1,param_2[5],param_2[6],param_2[7],
                     0,param_2 + 9);
  if (iVar9 != 0) {
    _gleTextureImagePut(glContext,iVar6,0,0,0,param_2[3],param_2[4],1,param_2[6],param_2[7],1,0,
                        param_2 + 9);
  }
  _gleCreatePluginTextureLevel(glContext,iVar5,iVar6,uVar4,iVar8,param_2[2]);
  if ((((*(uint *)(iVar5 + 0x6c) & 0x8000) == 0) || (*(short *)(iVar5 + 0x60) != iVar8)) ||
     (iVar5 = _gleGenMipmapsToLevel(glContext,iVar5,uVar4,iVar8,0xf,1), iVar5 == 0)) {
    *(uint *)(glContext + 0x314) =
         *(uint *)(glContext + 0x314) | 1 << (*(uint *)(glContext + 0x53d4) & 0x3f);
  }
  return iVar7;
}

/* _glTexImage2D_Comp @ 0x9f0fc (744 bytes) */
int _glTexImage2D_Comp(glContext, target, level, internalformat, width, height, border, format, type, pixels)
  int glContext;
  int target;
  int level;
  int internalformat;
  int width;
  int height;
  int border;
  uint format;
  uint type;
  int pixels;
{
  bool bVar1;
  undefined4 uVar2;
  undefined4 glErrorCode;
  uint uVar3;
  int iVar4;
  int iVar5;
  int imageSize;
  int *listRecord;
  int iVar7;
  int iVar8;
  double dVar9;
  
  iVar8 = *(int *)(glContext + 0x4a6c);
  iVar5 = glContext;
  if (iVar8 != 0) {
    iVar4 = _gleOffsetLimitImage(glContext + 0x31cc,width,height,format,type,pixels);
    iVar7 = *(int *)(iVar8 + 0x38);
    dVar9 = (double)((double (*)())_gleBytesPerElement)(type);
    iVar5 = (int)dVar9;
    if (iVar4 <= iVar7) {
      if (iVar5 == 0) {
        iVar5 = _glePixelBytes(format,type);
      }
      if (pixels == (pixels / iVar5) * iVar5) {
        if (*(int *)(iVar8 + 0x40) != 0) {
          _gleSynchronizePluginBuffer(glContext,iVar8 + 0x10);
        }
        pixels = pixels + *(int *)(iVar8 + 0x30);
        goto LAB_0009f1e0;
      }
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return iVar5;
    }
    glErrorCode = 0x502;
    goto LAB_0009f338;
  }
LAB_0009f1e0:
  if (((target == 0x8064) || (target == 0x851b)) || (target == 0x84f7)) {
    uVar2 = _glTexImage2D_Exec(glContext,target,level,internalformat,width,height,border,format,
                               type,pixels);
    return uVar2;
  }
  if (type < 0x8037) {
    if (type < 0x8033) {
      if (type != 0x1a00) {
        if (type < 0x1a01) {
          if (type - 0x1400 < 7) {
            if (format < 0x190b) {
              if (0x1902 < format) goto LAB_0009f340;
              goto LAB_0009f320;
            }
            if ((format == 0x8000) || ((0x7fff < format && (format - 0x80e0 < 2))))
            goto LAB_0009f340;
          }
        }
        else if (type == 0x8032) goto LAB_0009f2f4;
        goto LAB_0009f328;
      }
LAB_0009f320:
      bVar1 = format == 0x1900;
    }
    else {
LAB_0009f308:
      if (format == 0x1908) goto LAB_0009f340;
      uVar3 = 0x80e1;
LAB_0009f318:
      bVar1 = format == uVar3;
    }
LAB_0009f324:
    if (bVar1) {
LAB_0009f340:
      imageSize = _gleImageSize(format,type,width,height);
      if (imageSize < 1) {
        return imageSize;
      }
      uVar3 = imageSize + 3U & 0xfffffffc;
      listRecord = (int *)_gleAddListItem(glContext,PTR__glTexImage2D_ListExec_001103f8,uVar3 + 0x24);
      if (listRecord == (int *)0x0) {
        return 0;
      }
      *listRecord = target;
      listRecord[1] = level;
      listRecord[2] = internalformat;
      listRecord[5] = border;
      listRecord[8] = uVar3;
      listRecord[3] = width;
      listRecord[4] = height;
      listRecord[6] = format;
      listRecord[7] = type;
      if (pixels == 0) {
        return (int)listRecord;
      }
      uVar2 = _gleFillImage(glContext,width,height,1,format,type,pixels,listRecord + 9);
      return uVar2;
    }
  }
  else if (type < 0x8369) {
    if (0x8364 < type) goto LAB_0009f308;
    if (0x8361 < type) {
LAB_0009f2f4:
      bVar1 = format == 0x1907;
      goto LAB_0009f324;
    }
  }
  else if (type - 0x85ba < 2) {
    uVar3 = 0x85b9;
    goto LAB_0009f318;
  }
LAB_0009f328:
  if (*(int *)(glContext + 0x7574) != 0) {
    return iVar5;
  }
  glErrorCode = 0x500;
LAB_0009f338:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return iVar5;
}

/* _glTexImage2D_FlushExec @ 0x9f3e4 (64 bytes) */
void _glTexImage2D_FlushExec(forwardedArg1, forwardedArg2, forwardedArg3, forwardedArg4, forwardedArg5, forwardedArg6, forwardedArg7, forwardedArg8, forwardedArg9, forwardedArg10)
  undefined4 forwardedArg1;
  undefined4 forwardedArg2;
  undefined4 forwardedArg3;
  undefined4 forwardedArg4;
  undefined4 forwardedArg5;
  undefined4 forwardedArg6;
  undefined4 forwardedArg7;
  undefined4 forwardedArg8;
  undefined4 forwardedArg9;
  undefined4 forwardedArg10;
{
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  _glTexImage2D_Exec(forwardedArg1,forwardedArg2,forwardedArg3,forwardedArg4,forwardedArg5,forwardedArg6,forwardedArg7,forwardedArg8,forwardedArg9,
                     forwardedArg10);
  ((void (*)())_glFlush_Exec)(forwardedArg1,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
  return;
}

/* _glTexImage2D_CompExec @ 0x9f424 (128 bytes) */
void _glTexImage2D_CompExec(glContext, target, level, internalformat, width, height, border, format, type, pixels)
  undefined4 glContext;
  undefined4 target;
  undefined4 level;
  undefined4 internalformat;
  undefined4 width;
  undefined4 height;
  undefined4 border;
  undefined4 format;
  undefined4 type;
  undefined4 pixels;
{
  ((int (*)())_glTexImage2D_Comp)(glContext,target,level,internalformat,width,height,border,format,type,
                     pixels);
  _glTexImage2D_Exec(glContext,target,level,internalformat,width,height,border,format,type,
                     pixels);
  return;
}

/* _glTexImage3D_ListExec @ 0x9f4a4 (564 bytes) */
int _glTexImage3D_ListExec(glContext, param_2)
  int glContext;
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
                    (glContext,*param_2,iVar6,param_2[2],param_2[3],param_2[4],param_2[5],param_2[6],
                     param_2[7],param_2[8]);
  if (iVar4 != 0) {
    uVar2 = *(ushort *)(iVar4 + 0x24);
    if ((uVar2 & 0x3c00) != 0x1000) {
      if ((uVar2 & 0x3c00) == 0) {
        *(ushort *)(iVar4 + 0x24) = uVar2 | 0x1000;
      }
      else if ((uVar2 & 0xc00) != 0) {
        if (*(int *)(glContext + 0x7574) != 0) {
          return iVar5;
        }
        *(undefined4 *)(glContext + 0x7574) = 0x502;
        return iVar5;
      }
    }
    iVar3 = iVar4 + iVar6 * 0x18;
    iVar7 = iVar3 + 0xc4;
    if ((*(byte *)(iVar3 + 0xcf) & 0x20) != 0) {
      _gleDeletePluginTextureLevel(glContext,iVar4,iVar7,0,iVar6);
      if (*(int *)(iVar3 + 0xd8) != 0) {
        bVar1 = *(byte *)(iVar3 + 0xcf);
        if ((bVar1 & 1) == 0) {
          _gleFreeTextureLevel(glContext,iVar4,iVar7);
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
                      (glContext,iVar4,iVar7,param_2[2],param_2[3],param_2[4],param_2[5],param_2[6],
                       param_2[7],param_2[8],0,param_2 + 10);
    if (iVar3 != 0) {
      _gleTextureImagePut(glContext,iVar7,0,0,0,param_2[3],param_2[4],param_2[5],param_2[7],param_2[8]
                          ,0,0,param_2 + 10);
    }
    _gleCreatePluginTextureLevel(glContext,iVar4,iVar7,0,iVar6,param_2[2]);
    if ((((*(uint *)(iVar4 + 0x6c) & 0x8000) == 0) || (*(short *)(iVar4 + 0x60) != iVar6)) ||
       (iVar4 = _gleGenMipmapsToLevel(glContext,iVar4,0,iVar6,0xf,1), iVar4 == 0)) {
      *(uint *)(glContext + 0x314) =
           *(uint *)(glContext + 0x314) | 1 << (*(uint *)(glContext + 0x53d4) & 0x3f);
    }
  }
  return iVar5;
}

/* _glTexImage3D_Comp @ 0x9f6d8 (708 bytes) */
int _glTexImage3D_Comp(glContext, target, level, internalformat, width, height, depth, border, format, type, pixels)
  int glContext;
  int target;
  int level;
  int internalformat;
  int width;
  int height;
  int depth;
  int border;
  uint format;
  uint type;
  int pixels;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int imageSize;
  undefined4 uVar5;
  undefined4 glErrorCode;
  int *listRecord;
  int iVar7;
  int iVar8;
  double dVar9;
  
  iVar8 = *(int *)(glContext + 0x4a6c);
  iVar4 = glContext;
  if (iVar8 == 0) {
LAB_0009f7b0:
    if (target == 0x8070) {
      uVar5 = _glTexImage3D_Exec(glContext,0x8070,level,internalformat,width,height,depth,border,
                                 format,type,pixels);
      return uVar5;
    }
    if (type < 0x8037) {
      if (0x8032 < type) {
LAB_0009f8a0:
        if (format == 0x1908) goto LAB_0009f8ec;
        bVar1 = format == 0x80e1;
LAB_0009f8b4:
        if (bVar1) {
LAB_0009f8ec:
          imageSize = _gleImageSize(format,type,width,height);
          if (imageSize * depth < 1) {
            return imageSize;
          }
          uVar2 = imageSize * depth + 3U & 0xfffffffc;
          listRecord = (int *)_gleAddListItem(glContext,PTR__glTexImage3D_ListExec_001103f4,uVar2 + 0x28);
          if (listRecord == (int *)0x0) {
            return 0;
          }
          *listRecord = target;
          listRecord[1] = level;
          listRecord[2] = internalformat;
          listRecord[6] = border;
          listRecord[3] = width;
          listRecord[4] = height;
          listRecord[5] = depth;
          listRecord[7] = format;
          listRecord[8] = type;
          listRecord[9] = uVar2;
          if ((int)uVar2 < 1) {
            return (int)listRecord;
          }
          if (pixels == 0) {
            return (int)listRecord;
          }
          uVar5 = _gleFillImage(glContext,width,height,depth,format,type,pixels,
                                listRecord + 10);
          return uVar5;
        }
        goto LAB_0009f8b8;
      }
      if (type == 0x1a00) {
        if (format == 0x1900) goto LAB_0009f8ec;
      }
      else if (type < 0x1a01) {
        if (type - 0x1400 < 7) {
          if (0x190a < format) {
            if ((format == 0x8000) || ((0x7fff < format && (format - 0x80e0 < 2))))
            goto LAB_0009f8ec;
            goto LAB_0009f8b8;
          }
          if (0x1902 < format) goto LAB_0009f8ec;
          bVar1 = format == 0x1900;
          goto LAB_0009f8b4;
        }
      }
      else if (type == 0x8032) goto LAB_0009f898;
    }
    else if (0x8361 < type) {
      if (type < 0x8365) {
LAB_0009f898:
        bVar1 = format == 0x1907;
        goto LAB_0009f8b4;
      }
      if (type < 0x8369) goto LAB_0009f8a0;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return iVar4;
    }
    glErrorCode = 0x500;
  }
  else {
    iVar3 = _gleOffsetLimitImage3D
                      (glContext + 0x31cc,width,height,depth,format,type,pixels);
    iVar7 = *(int *)(iVar8 + 0x38);
    dVar9 = (double)((double (*)())_gleBytesPerElement)(type);
    iVar4 = (int)dVar9;
    if (iVar3 <= iVar7) {
      if (iVar4 == 0) {
        iVar4 = _glePixelBytes(format,type);
      }
      if (pixels == (pixels / iVar4) * iVar4) {
        if (*(int *)(iVar8 + 0x40) != 0) {
          _gleSynchronizePluginBuffer(glContext,iVar8 + 0x10);
        }
        pixels = pixels + *(int *)(iVar8 + 0x30);
        goto LAB_0009f7b0;
      }
    }
LAB_0009f8b8:
    if (*(int *)(glContext + 0x7574) != 0) {
      return iVar4;
    }
    glErrorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return iVar4;
}

/* _glTexImage3D_CompExec @ 0x9f99c (140 bytes) */
void _glTexImage3D_CompExec(glContext, target, level, internalformat, width, height, depth, border, format, type, pixels)
  undefined4 glContext;
  undefined4 target;
  undefined4 level;
  undefined4 internalformat;
  undefined4 width;
  undefined4 height;
  undefined4 depth;
  undefined4 border;
  undefined4 format;
  undefined4 type;
  undefined4 pixels;
{
  ((int (*)())_glTexImage3D_Comp)(glContext,target,level,internalformat,width,height,depth,border,format,
                     type,pixels);
  _glTexImage3D_Exec(glContext,target,level,internalformat,width,height,depth,border,format,
                     type,pixels);
  return;
}

/* _glTexSubImage1D_ListExec @ 0x9fa28 (920 bytes) */
int _glTexSubImage1D_ListExec(glContext, param_2)
  int glContext;
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
  if (*(short *)(glContext + 0x4a10) < 0) {
    uVar6 = param_2[1];
    iVar3 = _gleCheckTexSubImage1DArgs
                      (glContext,*param_2,uVar6,param_2[2],param_2[3],param_2[4],param_2[5]);
    if (iVar3 != 0) {
      iVar2 = iVar3 + uVar6 * 0x18;
      iVar7 = iVar2 + 0xc4;
      if (((((int)uVar6 < (int)(uint)*(byte *)(iVar3 + 0x8d)) ||
           ((int)(uint)*(byte *)(iVar3 + 0x8f) < (int)uVar6)) ||
          ((*(ushort *)(iVar3 + 0x94) >> (uVar6 & 0x3f) & 1) == 0)) ||
         (iVar4 = (**(code **)(glContext + 0x4710))
                            (*(undefined4 *)(glContext + 0x4688),
                             *(undefined4 *)(iVar3 + (uint)*(byte *)(glContext + 0x85a8) * 4),0,uVar6,
                             param_2[2],0,0,param_2[3]), iVar4 == 0)) {
        bVar5 = *(byte *)(iVar2 + 0xcf);
        if ((bVar5 & 0x10) == 0) {
          if ((bVar5 & 0x40) == 0) {
            if (*(int *)(iVar2 + 0xd8) == 0) {
              _gleAllocateTextureLevel(glContext,iVar3,iVar7);
              bVar5 = *(byte *)(iVar2 + 0xcf);
            }
            *(byte *)(iVar2 + 0xcf) = bVar5 | 0x10;
          }
          else {
            _gleUploadPluginTextureLevel
                      (glContext,iVar3,iVar7,0,uVar6,(uint)*(byte *)(glContext + 0x85a8));
          }
        }
        _gleModifyPluginTextureLevel(glContext,iVar3,iVar7,0,uVar6,param_2[2],0,0,param_2[3],1,1);
        _gleTextureImagePut(glContext,iVar7,param_2[2] + (uint)*(byte *)(iVar2 + 0xce),0,0,param_2[3],
                            1,1,param_2[4],param_2[5],1,0,param_2 + 7);
        if ((((*(uint *)(iVar3 + 0x6c) & 0x8000) == 0) || ((int)*(short *)(iVar3 + 0x60) != uVar6))
           || (iVar3 = _gleGenMipmapsToLevel(glContext,iVar3,0,uVar6,0xf,1), iVar3 == 0)) {
          *(uint *)(glContext + 0x314) =
               *(uint *)(glContext + 0x314) | 1 << (*(uint *)(glContext + 0x53d4) & 0x3f);
        }
      }
      else {
        *(undefined4 *)(iVar3 + 0x20) =
             *(undefined4 *)
              ((uint)*(byte *)(glContext + 0x85a8) * 4 + *(int *)(glContext + 0x5148) + 0x8054);
        if (*(int *)(iVar2 + 0xd8) != 0) {
          bVar5 = *(byte *)(iVar2 + 0xcf);
          if (((bVar5 & 1) == 0) && (*(short *)(iVar3 + 0x3e) == -0x7a43)) {
            _gleFreeTextureLevel(glContext,iVar3,iVar7);
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
                _gleFreeTextureLevel(glContext,iVar3,iVar2);
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
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x502;
  }
  return iVar1 + 0x1c;
}

/* _glTexSubImage1D_Comp @ 0x9fdc0 (636 bytes) */
int _glTexSubImage1D_Comp(glContext, target, level, xoffset, width, format, type, pixels)
  int glContext;
  int target;
  undefined4 level;
  undefined4 xoffset;
  int width;
  uint format;
  uint type;
  int pixels;
{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 glErrorCode;
  int iVar4;
  int iVar5;
  int rowBytes;
  undefined4 *listRecord;
  int iVar7;
  int iVar8;
  double dVar9;
  
  iVar8 = *(int *)(glContext + 0x4a6c);
  iVar5 = glContext;
  if (iVar8 == 0) {
LAB_0009fe88:
    if (pixels == 0) {
      return iVar5;
    }
    if (target == 0xde0) {
      if (width < 0) {
        if (*(int *)(glContext + 0x7574) != 0) {
          return iVar5;
        }
        glErrorCode = 0x501;
        goto LAB_0009ffa4;
      }
      if (type < 0x8037) {
        if (0x8032 < type) {
LAB_0009ff60:
          if (format == 0x1908) goto LAB_0009ffac;
          bVar1 = format == 0x80e1;
LAB_0009ff74:
          if (bVar1) {
LAB_0009ffac:
            rowBytes = _gleRowBytes(format,type,width);
            if (rowBytes < 1) {
              return rowBytes;
            }
            uVar2 = rowBytes + 3U & 0xfffffffc;
            listRecord = (undefined4 *)
                     _gleAddListItem(glContext,PTR__glTexSubImage1D_ListExec_00110408,uVar2 + 0x1c);
            if (listRecord == (undefined4 *)0x0) {
              return 0;
            }
            *listRecord = 0xde0;
            listRecord[1] = level;
            listRecord[2] = xoffset;
            listRecord[6] = uVar2;
            listRecord[3] = width;
            listRecord[4] = format;
            listRecord[5] = type;
            uVar3 = _gleFillImage(glContext,width,1,1,format,type,pixels,listRecord + 7);
            return uVar3;
          }
          goto LAB_0009ff78;
        }
        if (type == 0x1a00) {
          if (format == 0x1900) goto LAB_0009ffac;
        }
        else if (type < 0x1a01) {
          if (type - 0x1400 < 7) {
            if (0x190a < format) {
              if ((format == 0x8000) || ((0x7fff < format && (format - 0x80e0 < 2))))
              goto LAB_0009ffac;
              goto LAB_0009ff78;
            }
            if (0x1901 < format) goto LAB_0009ffac;
            bVar1 = format == 0x1900;
            goto LAB_0009ff74;
          }
        }
        else if (type == 0x8032) goto LAB_0009ff58;
      }
      else if (0x8361 < type) {
        if (type < 0x8365) {
LAB_0009ff58:
          bVar1 = format == 0x1907;
          goto LAB_0009ff74;
        }
        if (type < 0x8369) goto LAB_0009ff60;
      }
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return iVar5;
    }
    glErrorCode = 0x500;
  }
  else {
    iVar4 = _gleOffsetLimitImage(glContext + 0x31cc,width,1,format,type,pixels);
    iVar7 = *(int *)(iVar8 + 0x38);
    dVar9 = (double)((double (*)())_gleBytesPerElement)(type);
    iVar5 = (int)dVar9;
    if (iVar4 <= iVar7) {
      if (iVar5 == 0) {
        iVar5 = _glePixelBytes(format,type);
      }
      if (pixels == (pixels / iVar5) * iVar5) {
        if (*(int *)(iVar8 + 0x40) != 0) {
          _gleSynchronizePluginBuffer(glContext,iVar8 + 0x10);
        }
        pixels = pixels + *(int *)(iVar8 + 0x30);
        goto LAB_0009fe88;
      }
    }
LAB_0009ff78:
    if (*(int *)(glContext + 0x7574) != 0) {
      return iVar5;
    }
    glErrorCode = 0x502;
  }
LAB_0009ffa4:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return iVar5;
}

/* _glTexSubImage1D_Exec @ 0xa003c (1600 bytes) */
void _glTexSubImage1D_Exec(glContext, target, level, xoffset, width, format, type, pixels)
  int glContext;
  undefined4 target;
  uint level;
  int xoffset;
  int width;
  undefined4 format;
  undefined4 type;
  int pixels;
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
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    iVar5 = *(int *)(glContext + 0x4a6c);
    if (iVar5 == 0) {
LAB_000a0110:
      if (width == 0) {
        return;
      }
      iVar2 = _gleCheckTexSubImage1DArgs(glContext,target,level,xoffset,width,format,type);
      if (iVar2 == 0) {
        return;
      }
      iVar1 = iVar2 + level * 0x18;
      iVar7 = iVar1 + 0xc4;
      iVar8 = _checkFastPath(glContext,iVar7,xoffset,0,0,width,1,format,type,pixels);
      if (iVar5 != 0) {
        if ((((iVar8 != 0) && ((int)(uint)*(byte *)(iVar2 + 0x8d) <= (int)level)) &&
            ((int)level <= (int)(uint)*(byte *)(iVar2 + 0x8f))) &&
           (((*(ushort *)(iVar2 + 0x94) >> (level & 0x3f) & 1) != 0 &&
            (iVar3 = (**(code **)(glContext + 0x4710))
                               (*(undefined4 *)(glContext + 0x4688),
                                *(undefined4 *)(iVar2 + (uint)*(byte *)(glContext + 0x85a8) * 4),0,
                                level,xoffset,0,0,width), iVar3 != 0)))) {
          *(undefined4 *)(iVar2 + 0x20) =
               *(undefined4 *)
                ((uint)*(byte *)(glContext + 0x85a8) * 4 + *(int *)(glContext + 0x5148) + 0x8054);
          if (*(int *)(iVar1 + 0xd8) != 0) {
            bVar4 = *(byte *)(iVar1 + 0xcf);
            if (((bVar4 & 1) == 0) && (*(short *)(iVar2 + 0x3e) == -0x7a43)) {
              _gleFreeTextureLevel(glContext,iVar2,iVar7);
              bVar4 = *(byte *)(iVar1 + 0xcf);
            }
            *(byte *)(iVar1 + 0xcf) = bVar4 & 0xef;
            *(ushort *)(iVar2 + 0xa0) =
                 *(ushort *)(iVar2 + 0xa0) &
                 ((ushort)(-2 << (level & 0x1f)) | (ushort)(0xfffffffe >> 0x20 - (level & 0x1f))
                 );
          }
          *(byte *)(iVar1 + 0xcf) = *(byte *)(iVar1 + 0xcf) | 0x40;
          if ((*(uint *)(iVar2 + 0x6c) & 0x8000) == 0) {
            return;
          }
          if ((int)*(short *)(iVar2 + 0x60) != level) {
            return;
          }
          uVar6 = level + 1;
          if ((int)(uint)*(byte *)(iVar2 + 0x83) < (int)uVar6) {
            return;
          }
          iVar5 = uVar6 * 0x18 + iVar2 + 0xc4;
          do {
            if (*(int *)(iVar5 + 0x14) != 0) {
              if (((*(byte *)(iVar5 + 0xb) & 1) == 0) && (*(short *)(iVar2 + 0x3e) == -0x7a43)) {
                _gleFreeTextureLevel(glContext,iVar2,iVar5);
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
          _gleSynchronizePluginBuffer(glContext,iVar5 + 0x10);
        }
      }
      if ((((iVar8 == 0) || ((int)level < (int)(uint)*(byte *)(iVar2 + 0x8d))) ||
          ((int)(uint)*(byte *)(iVar2 + 0x8f) < (int)level)) ||
         (((*(ushort *)(iVar2 + 0x94) >> (level & 0x3f) & 1) == 0 ||
          (iVar5 = (**(code **)(glContext + 0x4710))
                             (*(undefined4 *)(glContext + 0x4688),
                              *(undefined4 *)(iVar2 + (uint)*(byte *)(glContext + 0x85a8) * 4),0,
                              level,xoffset,0,0,width), iVar5 == 0)))) {
        bVar4 = *(byte *)(iVar1 + 0xcf);
        if ((bVar4 & 0x10) == 0) {
          if ((bVar4 & 0x40) == 0) {
            if (*(int *)(iVar1 + 0xd8) == 0) {
              _gleAllocateTextureLevel(glContext,iVar2,iVar7);
              bVar4 = *(byte *)(iVar1 + 0xcf);
            }
            *(byte *)(iVar1 + 0xcf) = bVar4 | 0x10;
          }
          else {
            _gleUploadPluginTextureLevel
                      (glContext,iVar2,iVar7,0,level,(uint)*(byte *)(glContext + 0x85a8));
          }
        }
        _gleModifyPluginTextureLevel(glContext,iVar2,iVar7,0,level,xoffset,0,0,width,1,1);
        _gleTextureImagePut(glContext,iVar7,xoffset + (uint)*(byte *)(iVar1 + 0xce),0,0,width,1,1,
                            format,type,1,glContext + 0x31cc,pixels);
        if ((((*(uint *)(iVar2 + 0x6c) & 0x8000) != 0) && ((int)*(short *)(iVar2 + 0x60) == level)
            ) && (iVar5 = _gleGenMipmapsToLevel(glContext,iVar2,0,level,0xf,1), iVar5 != 0)) {
          return;
        }
        *(uint *)(glContext + 0x314) =
             *(uint *)(glContext + 0x314) | 1 << (*(uint *)(glContext + 0x53d4) & 0x3f);
        return;
      }
      *(undefined4 *)(iVar2 + 0x20) =
           *(undefined4 *)
            ((uint)*(byte *)(glContext + 0x85a8) * 4 + *(int *)(glContext + 0x5148) + 0x8054);
      if (*(int *)(iVar1 + 0xd8) != 0) {
        bVar4 = *(byte *)(iVar1 + 0xcf);
        if (((bVar4 & 1) == 0) && (*(short *)(iVar2 + 0x3e) == -0x7a43)) {
          _gleFreeTextureLevel(glContext,iVar2,iVar7);
          bVar4 = *(byte *)(iVar1 + 0xcf);
        }
        *(byte *)(iVar1 + 0xcf) = bVar4 & 0xef;
        *(ushort *)(iVar2 + 0xa0) =
             *(ushort *)(iVar2 + 0xa0) &
             ((ushort)(-2 << (level & 0x1f)) | (ushort)(0xfffffffe >> 0x20 - (level & 0x1f)));
      }
      *(byte *)(iVar1 + 0xcf) = *(byte *)(iVar1 + 0xcf) | 0x40;
      if ((*(uint *)(iVar2 + 0x6c) & 0x8000) == 0) {
        return;
      }
      if ((int)*(short *)(iVar2 + 0x60) != level) {
        return;
      }
      uVar6 = level + 1;
      if ((int)(uint)*(byte *)(iVar2 + 0x83) < (int)uVar6) {
        return;
      }
      iVar5 = uVar6 * 0x18 + iVar2 + 0xc4;
      do {
        if (*(int *)(iVar5 + 0x14) != 0) {
          if (((*(byte *)(iVar5 + 0xb) & 1) == 0) && (*(short *)(iVar2 + 0x3e) == -0x7a43)) {
            _gleFreeTextureLevel(glContext,iVar2,iVar5);
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
    iVar1 = _gleOffsetLimitImage(glContext + 0x31cc,width,1,format,type,pixels);
    iVar8 = *(int *)(iVar5 + 0x38);
    dVar9 = (double)((double (*)())_gleBytesPerElement)(type);
    iVar2 = (int)dVar9;
    if (iVar1 <= iVar8) {
      if (iVar2 == 0) {
        iVar2 = _glePixelBytes(format,type);
      }
      if (pixels == (pixels / iVar2) * iVar2) {
        pixels = pixels + *(int *)(iVar5 + 0x30);
        goto LAB_000a0110;
      }
    }
  }
  if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x502;
  }
  return;
}

/* _glTexSubImage1D_CompExec @ 0xa067c (104 bytes) */
void _glTexSubImage1D_CompExec(glContext, target, level, xoffset, width, format, type, pixels)
  undefined4 glContext;
  undefined4 target;
  undefined4 level;
  undefined4 xoffset;
  undefined4 width;
  undefined4 format;
  undefined4 type;
  undefined4 pixels;
{
  ((int (*)())_glTexSubImage1D_Comp)(glContext,target,level,xoffset,width,format,type,pixels);
  ((void (*)())_glTexSubImage1D_Exec)(glContext,target,level,xoffset,width,format,type,pixels);
  return;
}

/* _glTexSubImage2D_ListExec @ 0xa06e4 (1008 bytes) */
int _glTexSubImage2D_ListExec(glContext, param_2)
  int glContext;
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
  if (*(short *)(glContext + 0x4a10) < 0) {
    uVar8 = param_2[1];
    iVar5 = _gleCheckTexSubImage2DArgs
                      (glContext,*param_2,uVar8,param_2[2],param_2[3],param_2[4],param_2[5],param_2[6]
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
         (iVar6 = (**(code **)(glContext + 0x4710))
                            (*(undefined4 *)(glContext + 0x4688),
                             *(undefined4 *)(iVar5 + (uint)*(byte *)(glContext + 0x85a8) * 4),uVar3,
                             uVar8,param_2[2],param_2[3],0,param_2[4]), iVar6 == 0)) {
        bVar7 = *(byte *)(iVar4 + 0xcf);
        if ((bVar7 & 0x10) == 0) {
          if ((bVar7 & 0x40) == 0) {
            if (*(int *)(iVar4 + 0xd8) == 0) {
              _gleAllocateTextureLevel(glContext,iVar5,iVar9);
              bVar7 = *(byte *)(iVar4 + 0xcf);
            }
            *(byte *)(iVar4 + 0xcf) = bVar7 | 0x10;
          }
          else {
            _gleUploadPluginTextureLevel
                      (glContext,iVar5,iVar9,uVar3,uVar8,(uint)*(byte *)(glContext + 0x85a8));
          }
        }
        _gleModifyPluginTextureLevel
                  (glContext,iVar5,iVar9,uVar3,uVar8,param_2[2],param_2[3],0,param_2[4],param_2[5],1);
        _gleTextureImagePut(glContext,iVar9,param_2[2] + (uint)*(byte *)(iVar4 + 0xce),
                            param_2[3] + (uint)*(byte *)(iVar4 + 0xce),0,param_2[4],param_2[5],1,
                            param_2[6],param_2[7],1,0,param_2 + 9);
        if ((((*(uint *)(iVar5 + 0x6c) & 0x8000) == 0) || ((int)*(short *)(iVar5 + 0x60) != uVar8))
           || (iVar5 = _gleGenMipmapsToLevel(glContext,iVar5,uVar3,uVar8,0xf,1), iVar5 == 0)) {
          *(uint *)(glContext + 0x314) =
               *(uint *)(glContext + 0x314) | 1 << (*(uint *)(glContext + 0x53d4) & 0x3f);
        }
      }
      else {
        *(undefined4 *)(iVar5 + 0x20) =
             *(undefined4 *)
              ((uint)*(byte *)(glContext + 0x85a8) * 4 + *(int *)(glContext + 0x5148) + 0x8054);
        if (*(int *)(iVar4 + 0xd8) != 0) {
          bVar7 = *(byte *)(iVar4 + 0xcf);
          if (((bVar7 & 1) == 0) && (*(short *)(iVar5 + 0x3e) == -0x7a43)) {
            _gleFreeTextureLevel(glContext,iVar5,iVar9);
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
                _gleFreeTextureLevel(glContext,iVar5,iVar4);
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
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x502;
  }
  return iVar2 + 0x24;
}

/* _glTexSubImage2D_Comp @ 0xa0ad4 (688 bytes) */
int _glTexSubImage2D_Comp(glContext, target, level, xoffset, yoffset, width, height, format, type, pixels)
  int glContext;
  uint target;
  uint level;
  uint xoffset;
  uint yoffset;
  uint width;
  uint height;
  uint format;
  uint type;
  int pixels;
{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 glErrorCode;
  int iVar4;
  int iVar5;
  int imageSize;
  uint *listRecord;
  int iVar7;
  int iVar8;
  double dVar9;
  
  iVar8 = *(int *)(glContext + 0x4a6c);
  iVar5 = glContext;
  if (iVar8 == 0) {
LAB_000a0ba4:
    if (pixels == 0) {
      return iVar5;
    }
    if ((target == 0xde1) || ((0xde0 < target && (target - 0x8515 < 6)))) {
      if (((int)width < 0) || ((int)height < 0)) {
        if (*(int *)(glContext + 0x7574) != 0) {
          return iVar5;
        }
        glErrorCode = 0x501;
        goto LAB_000a0ce0;
      }
      if (type < 0x8037) {
        if (0x8032 < type) {
LAB_000a0c9c:
          if (format == 0x1908) goto LAB_000a0ce8;
          bVar1 = format == 0x80e1;
LAB_000a0cb0:
          if (bVar1) {
LAB_000a0ce8:
            imageSize = _gleImageSize(format,type,width,height);
            if (imageSize < 1) {
              return imageSize;
            }
            uVar2 = imageSize + 3U & 0xfffffffc;
            listRecord = (uint *)_gleAddListItem(glContext,PTR__glTexSubImage2D_ListExec_00110404,
                                             uVar2 + 0x24);
            if (listRecord == (uint *)0x0) {
              return 0;
            }
            *listRecord = target;
            listRecord[1] = level;
            listRecord[2] = xoffset;
            listRecord[3] = yoffset;
            listRecord[8] = uVar2;
            listRecord[4] = width;
            listRecord[5] = height;
            listRecord[6] = format;
            listRecord[7] = type;
            uVar3 = _gleFillImage(glContext,width,height,1,format,type,pixels,listRecord + 9);
            return uVar3;
          }
          goto LAB_000a0cb4;
        }
        if (type == 0x1a00) {
          if (format == 0x1900) goto LAB_000a0ce8;
        }
        else if (type < 0x1a01) {
          if (type - 0x1400 < 7) {
            if (0x190a < format) {
              if ((format == 0x8000) || ((0x7fff < format && (format - 0x80e0 < 2))))
              goto LAB_000a0ce8;
              goto LAB_000a0cb4;
            }
            if (0x1901 < format) goto LAB_000a0ce8;
            bVar1 = format == 0x1900;
            goto LAB_000a0cb0;
          }
        }
        else if (type == 0x8032) goto LAB_000a0c94;
      }
      else if (0x8361 < type) {
        if (type < 0x8365) {
LAB_000a0c94:
          bVar1 = format == 0x1907;
          goto LAB_000a0cb0;
        }
        if (type < 0x8369) goto LAB_000a0c9c;
      }
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return iVar5;
    }
    glErrorCode = 0x500;
  }
  else {
    iVar4 = _gleOffsetLimitImage(glContext + 0x31cc,width,height,format,type,pixels);
    iVar7 = *(int *)(iVar8 + 0x38);
    dVar9 = (double)((double (*)())_gleBytesPerElement)(type);
    iVar5 = (int)dVar9;
    if (iVar4 <= iVar7) {
      if (iVar5 == 0) {
        iVar5 = _glePixelBytes(format,type);
      }
      if (pixels == (pixels / iVar5) * iVar5) {
        if (*(int *)(iVar8 + 0x40) != 0) {
          _gleSynchronizePluginBuffer(glContext,iVar8 + 0x10);
        }
        pixels = pixels + *(int *)(iVar8 + 0x30);
        goto LAB_000a0ba4;
      }
    }
LAB_000a0cb4:
    if (*(int *)(glContext + 0x7574) != 0) {
      return iVar5;
    }
    glErrorCode = 0x502;
  }
LAB_000a0ce0:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return iVar5;
}

/* _glTexSubImage2D_FlushExec @ 0xa0d84 (64 bytes) */
void _glTexSubImage2D_FlushExec(forwardedArg1, forwardedArg2, forwardedArg3, forwardedArg4, forwardedArg5, forwardedArg6, forwardedArg7, forwardedArg8, forwardedArg9, forwardedArg10)
  undefined4 forwardedArg1;
  undefined4 forwardedArg2;
  undefined4 forwardedArg3;
  undefined4 forwardedArg4;
  undefined4 forwardedArg5;
  undefined4 forwardedArg6;
  undefined4 forwardedArg7;
  undefined4 forwardedArg8;
  undefined4 forwardedArg9;
  undefined4 forwardedArg10;
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
            (forwardedArg1,forwardedArg2,forwardedArg3,forwardedArg4,forwardedArg5,forwardedArg6,forwardedArg7,forwardedArg8,forwardedArg9,forwardedArg10);
  ((void (*)())_glFlush_Exec)(forwardedArg1,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
  return;
}

/* _glTexSubImage2D_CompExec @ 0xa0dc4 (128 bytes) */
void _glTexSubImage2D_CompExec(glContext, target, level, xoffset, yoffset, width, height, format, type, pixels)
  undefined4 glContext;
  undefined4 target;
  undefined4 level;
  undefined4 xoffset;
  undefined4 yoffset;
  undefined4 width;
  undefined4 height;
  undefined4 format;
  undefined4 type;
  undefined4 pixels;
{
  ((int (*)())_glTexSubImage2D_Comp)(glContext,target,level,xoffset,yoffset,width,height,format,type,pixels);
  _glTexSubImage2D_Exec
            (glContext,target,level,xoffset,yoffset,width,height,format,type,pixels);
  return;
}

/* _glTexSubImage3D_ListExec @ 0xa0e44 (968 bytes) */
int _glTexSubImage3D_ListExec(glContext, param_2)
  int glContext;
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
  if (*(short *)(glContext + 0x4a10) < 0) {
    uVar7 = param_2[1];
    iVar4 = _gleCheckTexSubImage3DArgs
                      (glContext,*param_2,uVar7,param_2[2],param_2[3],param_2[4],param_2[5],param_2[6]
                       ,param_2[7],param_2[8],param_2[9]);
    if (iVar4 != 0) {
      iVar3 = iVar4 + uVar7 * 0x18;
      iVar8 = iVar3 + 0xc4;
      if (((((int)uVar7 < (int)(uint)*(byte *)(iVar4 + 0x8d)) ||
           ((int)(uint)*(byte *)(iVar4 + 0x8f) < (int)uVar7)) ||
          ((*(ushort *)(iVar4 + 0x94) >> (uVar7 & 0x3f) & 1) == 0)) ||
         (iVar5 = (**(code **)(glContext + 0x4710))
                            (*(undefined4 *)(glContext + 0x4688),
                             *(undefined4 *)(iVar4 + (uint)*(byte *)(glContext + 0x85a8) * 4),0,uVar7,
                             param_2[2],param_2[3],param_2[4],param_2[5]), iVar5 == 0)) {
        bVar6 = *(byte *)(iVar3 + 0xcf);
        if ((bVar6 & 0x10) == 0) {
          if ((bVar6 & 0x40) == 0) {
            if (*(int *)(iVar3 + 0xd8) == 0) {
              _gleAllocateTextureLevel(glContext,iVar4,iVar8);
              bVar6 = *(byte *)(iVar3 + 0xcf);
            }
            *(byte *)(iVar3 + 0xcf) = bVar6 | 0x10;
          }
          else {
            _gleUploadPluginTextureLevel
                      (glContext,iVar4,iVar8,0,uVar7,(uint)*(byte *)(glContext + 0x85a8));
          }
        }
        _gleModifyPluginTextureLevel
                  (glContext,iVar4,iVar8,0,uVar7,param_2[2],param_2[3],param_2[4],param_2[5],
                   param_2[6],param_2[7]);
        uVar1 = (uint)*(byte *)(iVar3 + 0xce);
        _gleTextureImagePut(glContext,iVar8,param_2[2] + uVar1,param_2[3] + uVar1,param_2[4] + uVar1,
                            param_2[5],param_2[6],param_2[7],param_2[8],param_2[9],0,0,param_2 + 0xb
                           );
        if ((((*(uint *)(iVar4 + 0x6c) & 0x8000) == 0) || ((int)*(short *)(iVar4 + 0x60) != uVar7))
           || (iVar4 = _gleGenMipmapsToLevel(glContext,iVar4,0,uVar7,0xf,1), iVar4 == 0)) {
          *(uint *)(glContext + 0x314) =
               *(uint *)(glContext + 0x314) | 1 << (*(uint *)(glContext + 0x53d4) & 0x3f);
        }
      }
      else {
        *(undefined4 *)(iVar4 + 0x20) =
             *(undefined4 *)
              ((uint)*(byte *)(glContext + 0x85a8) * 4 + *(int *)(glContext + 0x5148) + 0x8054);
        if (*(int *)(iVar3 + 0xd8) != 0) {
          bVar6 = *(byte *)(iVar3 + 0xcf);
          if (((bVar6 & 1) == 0) && (*(short *)(iVar4 + 0x3e) == -0x7a43)) {
            _gleFreeTextureLevel(glContext,iVar4,iVar8);
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
                _gleFreeTextureLevel(glContext,iVar4,iVar3);
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
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x502;
  }
  return iVar2 + 0x2c;
}

/* _glTexSubImage3D_Comp @ 0xa120c (700 bytes) */
int _glTexSubImage3D_Comp(glContext, target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels)
  int glContext;
  int target;
  undefined4 level;
  undefined4 xoffset;
  undefined4 yoffset;
  undefined4 zoffset;
  int width;
  int height;
  int depth;
  uint format;
  uint type;
  int pixels;
{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 glErrorCode;
  int iVar4;
  int iVar5;
  int imageSize;
  undefined4 *listRecord;
  int iVar7;
  int iVar8;
  double dVar9;
  
  iVar8 = *(int *)(glContext + 0x4a6c);
  iVar5 = glContext;
  if (iVar8 == 0) {
LAB_000a12e8:
    if (pixels == 0) {
      return iVar5;
    }
    if (target == 0x806f) {
      if (((width < 0) || (height < 0)) || (depth < 0)) {
        if (*(int *)(glContext + 0x7574) != 0) {
          return iVar5;
        }
        glErrorCode = 0x501;
        goto LAB_000a141c;
      }
      if (type < 0x8037) {
        if (0x8032 < type) {
LAB_000a13d8:
          if (format == 0x1908) goto LAB_000a1424;
          bVar1 = format == 0x80e1;
LAB_000a13ec:
          if (bVar1) {
LAB_000a1424:
            imageSize = _gleImageSize(format,type,width,height);
            if (imageSize * depth < 1) {
              return imageSize;
            }
            uVar2 = imageSize * depth + 3U & 0xfffffffc;
            listRecord = (undefined4 *)
                     _gleAddListItem(glContext,PTR__glTexSubImage3D_ListExec_00110400,uVar2 + 0x2c);
            if (listRecord == (undefined4 *)0x0) {
              return 0;
            }
            *listRecord = 0x806f;
            listRecord[1] = level;
            listRecord[2] = xoffset;
            listRecord[3] = yoffset;
            listRecord[4] = zoffset;
            listRecord[10] = uVar2;
            listRecord[5] = width;
            listRecord[6] = height;
            listRecord[7] = depth;
            listRecord[8] = format;
            listRecord[9] = type;
            uVar3 = _gleFillImage(glContext,width,height,depth,format,type,pixels,
                                  listRecord + 0xb);
            return uVar3;
          }
          goto LAB_000a13f0;
        }
        if (type == 0x1a00) {
          if (format == 0x1900) goto LAB_000a1424;
        }
        else if (type < 0x1a01) {
          if (type - 0x1400 < 7) {
            if (0x190a < format) {
              if ((format == 0x8000) || ((0x7fff < format && (format - 0x80e0 < 2))))
              goto LAB_000a1424;
              goto LAB_000a13f0;
            }
            if (0x1901 < format) goto LAB_000a1424;
            bVar1 = format == 0x1900;
            goto LAB_000a13ec;
          }
        }
        else if (type == 0x8032) goto LAB_000a13d0;
      }
      else if (0x8361 < type) {
        if (type < 0x8365) {
LAB_000a13d0:
          bVar1 = format == 0x1907;
          goto LAB_000a13ec;
        }
        if (type < 0x8369) goto LAB_000a13d8;
      }
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return iVar5;
    }
    glErrorCode = 0x500;
  }
  else {
    iVar4 = _gleOffsetLimitImage3D
                      (glContext + 0x31cc,width,height,depth,format,type,pixels);
    iVar7 = *(int *)(iVar8 + 0x38);
    dVar9 = (double)((double (*)())_gleBytesPerElement)(type);
    iVar5 = (int)dVar9;
    if (iVar4 <= iVar7) {
      if (iVar5 == 0) {
        iVar5 = _glePixelBytes(format,type);
      }
      if (pixels == (pixels / iVar5) * iVar5) {
        if (*(int *)(iVar8 + 0x40) != 0) {
          _gleSynchronizePluginBuffer(glContext,iVar8 + 0x10);
        }
        pixels = pixels + *(int *)(iVar8 + 0x30);
        goto LAB_000a12e8;
      }
    }
LAB_000a13f0:
    if (*(int *)(glContext + 0x7574) != 0) {
      return iVar5;
    }
    glErrorCode = 0x502;
  }
LAB_000a141c:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return iVar5;
}

/* _glTexSubImage3D_Exec @ 0xa14c8 (1644 bytes) */
void _glTexSubImage3D_Exec(glContext, target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels)
  int glContext;
  undefined4 target;
  uint level;
  int xoffset;
  int yoffset;
  int zoffset;
  int width;
  int height;
  int depth;
  undefined4 format;
  undefined4 type;
  int pixels;
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
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    iVar5 = *(int *)(glContext + 0x4a6c);
    if (iVar5 == 0) {
LAB_000a15b0:
      if (width == 0) {
        return;
      }
      if (height == 0) {
        return;
      }
      if (depth == 0) {
        return;
      }
      iVar2 = _gleCheckTexSubImage3DArgs
                        (glContext,target,level,xoffset,yoffset,zoffset,width,height,depth,
                         format,type);
      if (iVar2 == 0) {
        return;
      }
      iVar1 = iVar2 + level * 0x18;
      iVar7 = iVar1 + 0xc4;
      iVar8 = _checkFastPath(glContext,iVar7,xoffset,yoffset,zoffset,width,height,format,type
                             ,pixels);
      if (iVar5 != 0) {
        if ((((iVar8 != 0) && ((int)(uint)*(byte *)(iVar2 + 0x8d) <= (int)level)) &&
            ((int)level <= (int)(uint)*(byte *)(iVar2 + 0x8f))) &&
           (((*(ushort *)(iVar2 + 0x94) >> (level & 0x3f) & 1) != 0 &&
            (iVar3 = (**(code **)(glContext + 0x4710))
                               (*(undefined4 *)(glContext + 0x4688),
                                *(undefined4 *)(iVar2 + (uint)*(byte *)(glContext + 0x85a8) * 4),0,
                                level,xoffset,yoffset,zoffset,width), iVar3 != 0)))) {
          *(undefined4 *)(iVar2 + 0x20) =
               *(undefined4 *)
                ((uint)*(byte *)(glContext + 0x85a8) * 4 + *(int *)(glContext + 0x5148) + 0x8054);
          if (*(int *)(iVar1 + 0xd8) != 0) {
            bVar4 = *(byte *)(iVar1 + 0xcf);
            if (((bVar4 & 1) == 0) && (*(short *)(iVar2 + 0x3e) == -0x7a43)) {
              _gleFreeTextureLevel(glContext,iVar2,iVar7);
              bVar4 = *(byte *)(iVar1 + 0xcf);
            }
            *(byte *)(iVar1 + 0xcf) = bVar4 & 0xef;
            *(ushort *)(iVar2 + 0xa0) =
                 *(ushort *)(iVar2 + 0xa0) &
                 ((ushort)(-2 << (level & 0x1f)) | (ushort)(0xfffffffe >> 0x20 - (level & 0x1f))
                 );
          }
          *(byte *)(iVar1 + 0xcf) = *(byte *)(iVar1 + 0xcf) | 0x40;
          if ((*(uint *)(iVar2 + 0x6c) & 0x8000) == 0) {
            return;
          }
          if ((int)*(short *)(iVar2 + 0x60) != level) {
            return;
          }
          uVar6 = level + 1;
          if ((int)(uint)*(byte *)(iVar2 + 0x83) < (int)uVar6) {
            return;
          }
          iVar5 = uVar6 * 0x18 + iVar2 + 0xc4;
          do {
            if (*(int *)(iVar5 + 0x14) != 0) {
              if (((*(byte *)(iVar5 + 0xb) & 1) == 0) && (*(short *)(iVar2 + 0x3e) == -0x7a43)) {
                _gleFreeTextureLevel(glContext,iVar2,iVar5);
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
          _gleSynchronizePluginBuffer(glContext,iVar5 + 0x10);
        }
      }
      if ((((iVar8 == 0) || ((int)level < (int)(uint)*(byte *)(iVar2 + 0x8d))) ||
          ((int)(uint)*(byte *)(iVar2 + 0x8f) < (int)level)) ||
         (((*(ushort *)(iVar2 + 0x94) >> (level & 0x3f) & 1) == 0 ||
          (iVar5 = (**(code **)(glContext + 0x4710))
                             (*(undefined4 *)(glContext + 0x4688),
                              *(undefined4 *)(iVar2 + (uint)*(byte *)(glContext + 0x85a8) * 4),0,
                              level,xoffset,yoffset,zoffset,width), iVar5 == 0)))) {
        bVar4 = *(byte *)(iVar1 + 0xcf);
        if ((bVar4 & 0x10) == 0) {
          if ((bVar4 & 0x40) == 0) {
            if (*(int *)(iVar1 + 0xd8) == 0) {
              _gleAllocateTextureLevel(glContext,iVar2,iVar7);
              bVar4 = *(byte *)(iVar1 + 0xcf);
            }
            *(byte *)(iVar1 + 0xcf) = bVar4 | 0x10;
          }
          else {
            _gleUploadPluginTextureLevel
                      (glContext,iVar2,iVar7,0,level,(uint)*(byte *)(glContext + 0x85a8));
          }
        }
        _gleModifyPluginTextureLevel
                  (glContext,iVar2,iVar7,0,level,xoffset,yoffset,zoffset,width,height,depth);
        uVar6 = (uint)*(byte *)(iVar1 + 0xce);
        _gleTextureImagePut(glContext,iVar7,xoffset + uVar6,yoffset + uVar6,zoffset + uVar6,width,
                            height,depth,format,type,0,glContext + 0x31cc,pixels);
        if ((((*(uint *)(iVar2 + 0x6c) & 0x8000) != 0) && ((int)*(short *)(iVar2 + 0x60) == level)
            ) && (iVar5 = _gleGenMipmapsToLevel(glContext,iVar2,0,level,0xf,1), iVar5 != 0)) {
          return;
        }
        *(uint *)(glContext + 0x314) =
             *(uint *)(glContext + 0x314) | 1 << (*(uint *)(glContext + 0x53d4) & 0x3f);
        return;
      }
      *(undefined4 *)(iVar2 + 0x20) =
           *(undefined4 *)
            ((uint)*(byte *)(glContext + 0x85a8) * 4 + *(int *)(glContext + 0x5148) + 0x8054);
      if (*(int *)(iVar1 + 0xd8) != 0) {
        bVar4 = *(byte *)(iVar1 + 0xcf);
        if (((bVar4 & 1) == 0) && (*(short *)(iVar2 + 0x3e) == -0x7a43)) {
          _gleFreeTextureLevel(glContext,iVar2,iVar7);
          bVar4 = *(byte *)(iVar1 + 0xcf);
        }
        *(byte *)(iVar1 + 0xcf) = bVar4 & 0xef;
        *(ushort *)(iVar2 + 0xa0) =
             *(ushort *)(iVar2 + 0xa0) &
             ((ushort)(-2 << (level & 0x1f)) | (ushort)(0xfffffffe >> 0x20 - (level & 0x1f)));
      }
      *(byte *)(iVar1 + 0xcf) = *(byte *)(iVar1 + 0xcf) | 0x40;
      if ((*(uint *)(iVar2 + 0x6c) & 0x8000) == 0) {
        return;
      }
      if ((int)*(short *)(iVar2 + 0x60) != level) {
        return;
      }
      uVar6 = level + 1;
      if ((int)(uint)*(byte *)(iVar2 + 0x83) < (int)uVar6) {
        return;
      }
      iVar5 = uVar6 * 0x18 + iVar2 + 0xc4;
      do {
        if (*(int *)(iVar5 + 0x14) != 0) {
          if (((*(byte *)(iVar5 + 0xb) & 1) == 0) && (*(short *)(iVar2 + 0x3e) == -0x7a43)) {
            _gleFreeTextureLevel(glContext,iVar2,iVar5);
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
                      (glContext + 0x31cc,width,height,depth,format,type,pixels);
    iVar8 = *(int *)(iVar5 + 0x38);
    dVar9 = (double)((double (*)())_gleBytesPerElement)(type);
    iVar2 = (int)dVar9;
    if (iVar1 <= iVar8) {
      if (iVar2 == 0) {
        iVar2 = _glePixelBytes(format,type);
      }
      if (pixels == (pixels / iVar2) * iVar2) {
        pixels = pixels + *(int *)(iVar5 + 0x30);
        goto LAB_000a15b0;
      }
    }
  }
  if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x502;
  }
  return;
}

/* _glTexSubImage3D_CompExec @ 0xa1b34 (152 bytes) */
void _glTexSubImage3D_CompExec(glContext, target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels)
  undefined4 glContext;
  undefined4 target;
  undefined4 level;
  undefined4 xoffset;
  undefined4 yoffset;
  undefined4 zoffset;
  undefined4 width;
  undefined4 height;
  undefined4 depth;
  undefined4 format;
  undefined4 type;
  undefined4 pixels;
{
  ((int (*)())_glTexSubImage3D_Comp)(glContext,target,level,xoffset,yoffset,zoffset,width,height,depth,format,
             type,pixels);
  ((void (*)())_glTexSubImage3D_Exec)(glContext,target,level,xoffset,yoffset,zoffset,width,height,depth,format,
             type,pixels);
  return;
}

/* _glVertex2_ListExec @ 0xa1bcc (84 bytes) */
int _glVertex2_ListExec(glContext, param_2)
  int glContext;
  float *param_2;
{
  code *pcVar1;
  
  pcVar1 = *(code **)(glContext + 0x4884);
  if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
    pcVar1 = *(code **)(glContext + 0x28);
  }
  (*pcVar1)(glContext,(double)*param_2,(double)param_2[1],(double)*(float *)(glContext + 0x20),
            (double)*(float *)(glContext + 0x24));
  return 8;
}

/* _glVertex4_ListExec @ 0xa1c20 (80 bytes) */
int _glVertex4_ListExec(glContext, param_2)
  int glContext;
  float *param_2;
{
  code *pcVar1;
  
  pcVar1 = *(code **)(glContext + 0x4884);
  if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
    pcVar1 = *(code **)(glContext + 0x28);
  }
  (*pcVar1)(glContext,(double)*param_2,(double)param_2[1],(double)param_2[2],(double)param_2[3]);
  return 0x10;
}

/* _glVertex2d_Comp @ 0xa1c70 (108 bytes) */
float * _glVertex2d_Comp(undefined4 glContext,double x,double y)
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glVertex2_ListExec_00110418,8);
  if (listRecord != (float *)0x0) {
    *listRecord = (float)x;
    listRecord[1] = (float)y;
  }
  return listRecord;
}

/* _glVertex2d_CompExec @ 0xa1cdc (80 bytes) */
void _glVertex2d_CompExec(undefined4 glContext,double x,double y)
{
  ((float * (*)())_glVertex2d_Comp)(glContext,x,y);
  ((void (*)())_glVertex2d_Exec)(glContext,x,y);
  return;
}

/* _glVertex2dv_Exec @ 0xa1d2c (60 bytes) */
void _glVertex2dv_Exec(glContext, v)
  int glContext;
  double *v;
{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x4884);
  if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x28);
  }
                    
                    
  (*((int (*)(int,int,double,double,double,double))UNRECOVERED_JUMPTABLE))
            (glContext, v, (double)(float)*v, (double)(float)v[1], (double)*(float *)(glContext + 0x20), (double)*(float *)(glContext + 0x24));
  return;
}

/* _glVertex2dv_Comp @ 0xa1d68 (96 bytes) */
int _glVertex2dv_Comp(glContext, v)
  undefined4 glContext;
  double *v;
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glVertex2_ListExec_00110418,8);
  if (listRecord != (float *)0x0) {
    *listRecord = (float)*v;
    listRecord[1] = (float)v[1];
  }
  return listRecord;
}

/* _glVertex2dv_CompExec @ 0xa1dc8 (56 bytes) */
void _glVertex2dv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glVertex2dv_Comp)(glContext,v);
  ((void (*)())_glVertex2dv_Exec)(glContext,v);
  return;
}

/* _glVertex3dv_Exec @ 0xa1e00 (64 bytes) */
void _glVertex3dv_Exec(glContext, v)
  int glContext;
  double *v;
{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x4884);
  if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x28);
  }
                    
                    
  (*((int (*)(int,int,double,double,double,double))UNRECOVERED_JUMPTABLE))
            (glContext, v, (double)(float)*v, (double)(float)v[1], (double)(float)v[2], (double)*(float *)(glContext + 0x24));
  return;
}

/* _glVertex3dv_Comp @ 0xa1e40 (108 bytes) */
int _glVertex3dv_Comp(glContext, v)
  undefined4 glContext;
  double *v;
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glVertex3_ListExec_00110414,0xc);
  if (listRecord != (float *)0x0) {
    *listRecord = (float)*v;
    listRecord[1] = (float)v[1];
    listRecord[2] = (float)v[2];
  }
  return listRecord;
}

/* _glVertex3dv_CompExec @ 0xa1eac (56 bytes) */
void _glVertex3dv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glVertex3dv_Comp)(glContext,v);
  ((void (*)())_glVertex3dv_Exec)(glContext,v);
  return;
}

/* _glVertex4d_Exec @ 0xa1ee4 (48 bytes) */
void _glVertex4d_Exec(int glContext,double x,double y,double z,double w)
{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x4884);
  if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x28);
  }
                    
                    
  (*((int (*)(int,double,double,double,double))UNRECOVERED_JUMPTABLE))
            (glContext, (double)(float)x, (double)(float)y, (double)(float)z, (double)(float)w);
  return;
}

/* _glVertex4d_Comp @ 0xa1f14 (108 bytes) */
void _glVertex4d_Comp(undefined4 glContext,double x,double y,double z,double w)
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glVertex4_ListExec_00110410,0x10);
  if (listRecord != (float *)0x0) {
    *listRecord = (float)x;
    listRecord[1] = (float)y;
    listRecord[2] = (float)z;
    listRecord[3] = (float)w;
  }
  return;
}

/* _glVertex4d_CompExec @ 0xa1f80 (96 bytes) */
void _glVertex4d_CompExec(undefined4 glContext,double x,double y,double z,double w)
{
  ((void (*)())_glVertex4d_Comp)(glContext,x,y,z,w);
  ((void (*)())_glVertex4d_Exec)(glContext,x,y,z,w);
  return;
}

/* _glVertex4dv_Exec @ 0xa1fe0 (64 bytes) */
void _glVertex4dv_Exec(glContext, v)
  int glContext;
  double *v;
{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x4884);
  if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x28);
  }
                    
                    
  (*((int (*)(int,int,double,double,double,double))UNRECOVERED_JUMPTABLE))
            (glContext, v, (double)(float)*v, (double)(float)v[1], (double)(float)v[2], (double)(float)v[3]);
  return;
}

/* _glVertex4dv_Comp @ 0xa2020 (120 bytes) */
int _glVertex4dv_Comp(glContext, v)
  undefined4 glContext;
  double *v;
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glVertex4_ListExec_00110410,0x10);
  if (listRecord != (float *)0x0) {
    *listRecord = (float)*v;
    listRecord[1] = (float)v[1];
    listRecord[2] = (float)v[2];
    listRecord[3] = (float)v[3];
  }
  return listRecord;
}

/* _glVertex4dv_CompExec @ 0xa2098 (56 bytes) */
void _glVertex4dv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glVertex4dv_Comp)(glContext,v);
  ((void (*)())_glVertex4dv_Exec)(glContext,v);
  return;
}

/* _glVertex2f_Comp @ 0xa20d0 (100 bytes) */
float * _glVertex2f_Comp(undefined4 glContext,float x,float y)
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glVertex2_ListExec_00110418,8);
  if (listRecord != (float *)0x0) {
    listRecord[1] = (float)y;
    *listRecord = (float)x;
  }
  return listRecord;
}

/* _glVertex2f_CompExec @ 0xa2134 (80 bytes) */
void _glVertex2f_CompExec(undefined4 glContext,float x,float y)
{
  ((float * (*)())_glVertex2f_Comp)(glContext,x,y);
  ((void (*)())_glVertex2f_Exec)(glContext,x,y);
  return;
}

/* _glVertex2fv_Exec @ 0xa2184 (52 bytes) */
void _glVertex2fv_Exec(glContext, v)
  int glContext;
  float *v;
{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x4884);
  if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x28);
  }
                    
                    
  (*((int (*)(int,int,double,double,double,double))UNRECOVERED_JUMPTABLE))
            (glContext, v, (double)*v, (double)v[1], (double)*(float *)(glContext + 0x20), (double)*(float *)(glContext + 0x24));
  return;
}

/* _glVertex2fv_Comp @ 0xa21b8 (88 bytes) */
int _glVertex2fv_Comp(glContext, v)
  undefined4 glContext;
  undefined4 *v;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glVertex2_ListExec_00110418,8);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = *v;
    listRecord[1] = v[1];
  }
  return listRecord;
}

/* _glVertex2fv_CompExec @ 0xa2210 (56 bytes) */
void _glVertex2fv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glVertex2fv_Comp)(glContext,v);
  ((void (*)())_glVertex2fv_Exec)(glContext,v);
  return;
}

/* _glVertex3fv_Exec @ 0xa2248 (52 bytes) */
void _glVertex3fv_Exec(glContext, v)
  int glContext;
  float *v;
{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x4884);
  if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x28);
  }
                    
                    
  (*((int (*)(int,int,double,double,double,double))UNRECOVERED_JUMPTABLE))
            (glContext, v, (double)*v, (double)v[1], (double)v[2], (double)*(float *)(glContext + 0x24));
  return;
}

/* _glVertex3fv_Comp @ 0xa227c (96 bytes) */
int _glVertex3fv_Comp(glContext, v)
  undefined4 glContext;
  undefined4 *v;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glVertex3_ListExec_00110414,0xc);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = *v;
    listRecord[1] = v[1];
    listRecord[2] = v[2];
  }
  return listRecord;
}

/* _glVertex3fv_CompExec @ 0xa22dc (56 bytes) */
void _glVertex3fv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glVertex3fv_Comp)(glContext,v);
  ((void (*)())_glVertex3fv_Exec)(glContext,v);
  return;
}

/* _glVertex4f_Comp @ 0xa2314 (92 bytes) */
void _glVertex4f_Comp(undefined4 glContext,float x,float y,float z,float w)
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glVertex4_ListExec_00110410,0x10);
  if (listRecord != (float *)0x0) {
    listRecord[3] = (float)w;
    *listRecord = (float)x;
    listRecord[1] = (float)y;
    listRecord[2] = (float)z;
  }
  return;
}

