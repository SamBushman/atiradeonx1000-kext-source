#include "decls.h"

/* _glFinish_Exec @ 0x555d4 (724 bytes) */
void _glFinish_Exec(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar6;
  uint uVar7;
  int *piVar8;
  double extraout_f1;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    iVar6 = *(int *)(param_1 + 0x50ac);
    if (iVar6 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
      _gleUpdateMatrixFunc(param_1);
      fparam_1 = extraout_f1;
    }
    if (*(char *)(param_1 + 0x4691) != '\0') {
      iVar5 = *(int *)(param_1 + 0x744c);
      piVar8 = (int *)(param_1 + 0x310);
      cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
      if ((iVar5 != 0) && (*(int *)(iVar5 + 0xec) != 0)) {
        ((void (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar5 + 0x10,in_r5,in_r6,in_r7,in_r8,iVar6,fparam_1,fparam_2,fparam_3,
                   fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
        *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
      }
      if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_00055708:
        uVar7 = *(uint *)(param_1 + 0x31c);
      }
      else {
        iVar6 = 0;
        piVar4 = (int *)(param_1 + 0x324);
        do {
          iVar5 = *piVar4;
          piVar4 = piVar4 + 1;
          if (iVar5 != 0) {
            *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
            break;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < 9);
        uVar7 = *(uint *)(param_1 + 0x31c);
        if ((uVar7 & 0x15555) != 0) {
          if (*(char *)(param_1 + 0x2e54) != '\0') {
            _gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
          }
          if (*(char *)(param_1 + 0x3094) != '\0') {
            _gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
          }
          goto LAB_00055708;
        }
      }
      bVar1 = cVar2 == '\0';
      if (bVar1) {
        uVar7 = uVar7 & 0x17000000;
      }
      else {
        uVar7 = uVar7 & 0x17ffffff;
      }
      if (bVar1) {
        bVar1 = ((*piVar8 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar7 == 0) &&
                *(int *)(param_1 + 800) == 0;
      }
      else {
        bVar1 = (((*piVar8 == 0 && *(int *)(param_1 + 0x314) == 0) &&
                 (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar7 == 0) &&
                *(int *)(param_1 + 800) == 0;
      }
      if (!bVar1) {
        if (*(char *)(param_1 + 0x85a8) == *(char *)(param_1 + 0x85a6)) {
          uVar7 = (**(code **)(param_1 + 0x4788))
                            (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar8);
          if ((((uVar7 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
              ((uVar7 & 4) != (uint)*(byte *)(param_1 + 0x7581))) ||
             ((uVar7 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0'))) {
            if ((uVar7 & 4) == 0) {
              uVar7 = uVar7 & 0xfffffffe;
              *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
            }
            _gleUpdateDispatchCodeChange(param_1,uVar7);
            if (*(char *)(param_1 + 0x759d) == '\0') {
              if (*(int *)(param_1 + 0x7574) != 0) {
                return;
              }
              uVar3 = 0x506;
              goto LAB_0005580c;
            }
          }
        }
        else {
          _gleSwitchToNonRevertRenderer(param_1);
        }
        iVar6 = 0;
        do {
          iVar6 = iVar6 + 1;
          *piVar8 = 0;
          piVar8 = piVar8 + 1;
        } while (iVar6 < 0x13);
      }
    }
    uVar7 = 0;
    (**(code **)(param_1 + 0x46f0))(*(undefined4 *)(param_1 + 0x4688));
    if (*(char *)(param_1 + 0x85a4) != '\0') {
      iVar6 = param_1 + 0x10000;
      do {
        if (uVar7 != *(byte *)(param_1 + 0x85a8)) {
          (**(code **)(*(int *)(iVar6 + -0x777c) + 0x178))(*(undefined4 *)(iVar6 + -0x7a54));
        }
        uVar7 = uVar7 + 1;
        iVar6 = iVar6 + 0x2e0;
      } while ((int)uVar7 < (int)(uint)*(byte *)(param_1 + 0x85a4));
    }
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
LAB_0005580c:
    *(undefined4 *)(param_1 + 0x7574) = uVar3;
  }
  return;
}

/* _glFrontFace_Exec @ 0x558a8 (76 bytes) */
void _glFrontFace_Exec(param_1, param_2)
  int param_1;
  int param_2;
{
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if ((1 < param_2 - 0x900U) && (*(int *)(param_1 + 0x7574) == 0)) {
      *(undefined4 *)(param_1 + 0x7574) = 0x500;
    }
    *(short *)(param_1 + 0x34d4) = (short)param_2;
    _gleUpdatePolyMode(param_1);
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x502;
  return;
}

/* _gliTerminateLibrary @ 0x558f4 (40 bytes) */
void _gliTerminateLibrary()
{
  ((int (*)())_gliDestroyAllContexts)();
  ((void (*)())_glepPluginDisconnectAll)();
  return;
}

/* _gliDestroyAllContexts @ 0x5591c (92 bytes) */
int _gliDestroyAllContexts()
{
  int iVar1;
  int iVar2;
  
  iVar1 = _gl_list;
  while (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + 0x85a0);
    _gliDestroyContext(iVar1);
    iVar1 = iVar2;
  }
  _gl_list = 0;
  return 0;
}

/* _glepPluginDisconnectAll @ 0x55978 (100 bytes) */
void _glepPluginDisconnectAll()
{
  int *piVar1;
  
  piVar1 = _glep_plugin_head;
  if (_glep_plugin_head != (int *)0x0) {
    do {
      ((void (*)())_glepPluginDisconnect)(piVar1);
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)0x0);
    ((void (*)())_glepUnloadRenderers)();
    return;
  }
  return;
}

/* _glepPluginDisconnect @ 0x559dc (140 bytes) */
void _glepPluginDisconnect(param_1)
  int param_1;
{
  int iVar1;
  code *a0;
  
  if (*(int *)(param_1 + 0x108) != 0) {
    iVar1 = _NSLookupSymbolInModule(*(undefined4 *)(param_1 + 0x10c),"_gldTerminateLibrary");
    if ((iVar1 != 0) && (a0 = (code *)_NSAddressOfSymbol(iVar1), a0 != (code *)0x0)) {
      (*a0)(a0);
    }
    _NSUnLinkModule(*(undefined4 *)(param_1 + 0x10c),0);
    *(undefined4 *)(param_1 + 0x10c) = 0;
    _NSDestroyObjectFileImage(*(undefined4 *)(param_1 + 0x108));
    *(undefined4 *)(param_1 + 0x108) = 0;
  }
  return;
}

/* _glepUnloadRenderers @ 0x55a68 (116 bytes) */
void _glepUnloadRenderers()
{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  
  piVar1 = (int *)_glep_plugin_head;
  puVar2 = (undefined4 *)PTR__gle_io_data_00112434;
  while (PTR__gle_io_data_00112434 = (undefined *)puVar2, piVar1 != (int *)0x0) {
    iVar3 = *piVar1;
    _free(piVar1);
    piVar1 = (int *)iVar3;
    puVar2 = (undefined4 *)PTR__gle_io_data_00112434;
  }
  _glep_plugin_head = 0;
  puVar2[4] = 0;
  *puVar2 = 0;
  puVar2[1] = 0;
  puVar2[2] = 0;
  puVar2[3] = 0;
  return;
}

/* _glTexCoord3f_Exec @ 0x55adc (36 bytes) */
void _glTexCoord3f_Exec(int param_1,float fparam_1,float fparam_2,float fparam_3)
{
  *(float *)(param_1 + 0x120) = (float)fparam_1;
  *(uint *)(param_1 + 0x486c) = *(uint *)(param_1 + 0x486c) | 1;
  *(float *)(param_1 + 0x124) = (float)fparam_2;
  *(float *)(param_1 + 0x128) = (float)fparam_3;
  *(undefined4 *)(param_1 + 300) = *(undefined4 *)(param_1 + 0x24);
  return;
}

/* _glGetTexImage_Exec @ 0x55b00 (1268 bytes) */
void _glGetTexImage_Exec(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  uint param_3;
  uint param_4;
  uint param_5;
  int param_6;
{
  bool bVar1;
  byte bVar2;
  ushort uVar3;
  undefined4 uVar4;
  short sVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  uint uVar12;
  uint *puVar13;
  int *piVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  double dVar18;
  int iStack_d0;
  int iStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  int iStack_c0;
  uint *puStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  uint uStack_ac;
  undefined4 uStack_a8;
  uint uStack_a4;
  uint uStack_a0;
  undefined1 uStack_64;
  uint *puStack_60;
  undefined1 auStack_5c [4];
  uint uStack_58;
  undefined1 auStack_54 [4];
  uint uStack_50;
  int iStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 auStack_3c [3];
  
  uVar16 = param_2 - 0x8515;
  iVar7 = _gleLookUpNonProxyTexture(param_1,param_2);
  if (5 < uVar16) {
    uVar16 = 0;
  }
  iVar6 = iVar7 + uVar16 * 0x168 + param_3 * 0x18;
  if (-1 < *(short *)(param_1 + 0x4a10)) goto LAB_00055d40;
  if (iVar7 == 0) goto LAB_00055c7c;
  if (0xe < param_3) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar4 = 0x501;
    goto LAB_00055d50;
  }
  if (param_5 < 0x8037) {
    if (0x8032 < param_5) {
LAB_00055c54:
      if (param_4 != 0x1908) {
        uVar12 = 0x80e1;
        goto LAB_00055c70;
      }
      goto LAB_00055c94;
    }
    if (param_5 != 0x140b) {
      if (param_5 < 0x140c) {
        if (param_5 - 0x1400 < 7) goto LAB_00055c00;
      }
      else if (param_5 == 0x8032) goto LAB_00055c4c;
LAB_00055c7c:
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar4 = 0x500;
      goto LAB_00055d50;
    }
LAB_00055c00:
    if (param_4 < 0x190b) {
      if (0x1901 < param_4) goto LAB_00055c94;
      if (param_4 != 0x1900) goto LAB_00055d40;
      goto LAB_00055c98;
    }
    if ((param_4 == 0x8000) || ((0x7fff < param_4 && (param_4 - 0x80e0 < 2)))) goto LAB_00055c94;
  }
  else {
    if (param_5 < 0x8369) {
      if (0x8364 < param_5) goto LAB_00055c54;
      if (param_5 < 0x8362) goto LAB_00055c7c;
LAB_00055c4c:
      bVar1 = param_4 == 0x1907;
    }
    else {
      if (1 < param_5 - 0x85ba) goto LAB_00055c7c;
      uVar12 = 0x85b9;
LAB_00055c70:
      bVar1 = param_4 == uVar12;
    }
    if (!bVar1) goto LAB_00055d40;
LAB_00055c94:
    if (param_4 == 0x1900) {
LAB_00055c98:
      sVar5 = *(short *)(iVar6 + 0xd4);
      if (sVar5 != 0x1900) goto LAB_00055d40;
    }
    else {
      sVar5 = *(short *)(iVar6 + 0xd4);
    }
    if ((param_4 == 0x1902) == (sVar5 == 0x1902)) {
      iVar15 = *(int *)(param_1 + 0x4a68);
      if (iVar15 == 0) {
LAB_00055d78:
        bVar2 = *(byte *)(iVar6 + 0xcf);
        if ((bVar2 & 0x20) == 0) {
          return;
        }
        if ((((int)param_3 < (int)(uint)*(byte *)(iVar7 + 0x8d)) ||
            ((int)(uint)*(byte *)(iVar7 + 0x8f) < (int)param_3)) || ((bVar2 & 0x40) == 0)) {
          if ((bVar2 & 0x10) == 0) {
            return;
          }
        }
        else {
          ((void (*)())_gleUploadPluginTextureLevel)(param_1,iVar7,iVar6 + 0xc4,uVar16,param_3,(uint)*(byte *)(param_1 + 0x85a8));
        }
        uVar16 = (uint)*(ushort *)(iVar6 + 0xca);
        puVar13 = &uStack_50;
        piVar14 = &iStack_4c;
        _glePixelPackSettings
                  (param_1,param_4,param_5,(uint)*(ushort *)(iVar6 + 200),uVar16,param_1 + 0x31b0,
                   puVar13,piVar14,&puStack_60,auStack_5c,&uStack_58,auStack_54);
        if (((((*(byte *)(iVar6 + 0xcf) & 1) == 0) ||
             (param_6 + iStack_4c != *(int *)(iVar6 + 0xd8))) ||
            ((param_4 != *(ushort *)(iVar6 + 0xd4) ||
             ((param_5 != *(ushort *)(iVar6 + 0xd6) ||
              (puVar13 = puStack_60, (uint)puStack_60 / uStack_50 != (uint)*(ushort *)(iVar6 + 0xd0)
              )))))) || (uStack_58 / (uint)puStack_60 != (uint)*(ushort *)(iVar6 + 0xd2))) {
          uVar12 = (uint)*(byte *)(param_1 + 0x31c8);
        }
        else {
          uVar12 = (uint)*(byte *)(param_1 + 0x31c8);
          if (uVar12 == 0) {
            return;
          }
        }
        uStack_ac = 0x60000;
        if ((*(short *)(iVar7 + 0x26) == 0x1907) &&
           ((*(short *)(iVar6 + 0xd4) == 0x1908 || (*(short *)(iVar6 + 0xd4) == -0x7f1f)))) {
          uStack_ac = 0x68000;
        }
        if (uVar12 != 0) {
          uStack_ac = uStack_ac | 2;
        }
        iVar15 = 0;
        iVar7 = _gleRowBytes((uint)*(ushort *)(iVar6 + 0xd4),(uint)*(ushort *)(iVar6 + 0xd6),
                             (uint)*(ushort *)(iVar6 + 0xd0));
        _glgConvertType((uint)*(ushort *)(iVar6 + 0xd4),(uint)*(ushort *)(iVar6 + 0xd6),&uStack_48,
                        &uStack_44,uVar16,uVar12,puVar13,piVar14);
        puVar10 = &uStack_40;
        puVar11 = auStack_3c;
        _glgConvertType(param_4,param_5,puVar10,puVar11,uVar16,uVar12,puVar13,piVar14);
        uVar3 = *(ushort *)(iVar6 + 0xca);
        uVar4 = 0x68002;
        uStack_c8 = uStack_48;
        uStack_c4 = uStack_44;
        puStack_bc = puStack_60;
        uStack_b8 = uStack_40;
        uStack_b4 = auStack_3c[0];
        uStack_b0 = 2;
        uStack_a8 = 0x68002;
        uStack_a4 = (uint)*(ushort *)(iVar6 + 200);
        uStack_a0 = (uint)*(ushort *)(iVar6 + 0xca);
        uStack_64 = 0;
        if (*(short *)(iVar6 + 0xcc) == 0) {
          return;
        }
        iVar9 = 0;
        iVar8 = 0;
        iStack_cc = iVar7;
        do {
          iVar15 = iVar15 + 1;
          iStack_c0 = param_6 + iStack_4c + iVar9;
          iStack_d0 = *(int *)(iVar6 + 0xd8) + iVar8;
          iVar8 = iVar8 + iVar7 * (uint)uVar3;
          _glgProcessPixels(param_1 + 0x31a8,&iStack_d0,puVar10,puVar11,uVar16,uVar12,uVar4,piVar14)
          ;
          iVar9 = iVar9 + uStack_58;
        } while (iVar15 < (int)(uint)*(ushort *)(iVar6 + 0xcc));
        return;
      }
      iVar8 = _gleOffsetLimitImage3D
                        (param_1 + 0x31b0,(uint)*(ushort *)(iVar6 + 200),
                         (uint)*(ushort *)(iVar6 + 0xca),(uint)*(ushort *)(iVar6 + 0xcc),param_4,
                         param_5,param_6);
      iVar17 = *(int *)(iVar15 + 0x38);
      dVar18 = (double)((double (*)())_gleBytesPerElement)(param_5);
      iVar9 = (int)dVar18;
      if (iVar8 <= iVar17) {
        if (iVar9 == 0) {
          iVar9 = _glePixelBytes(param_4,param_5);
        }
        if (param_6 == (param_6 / iVar9) * iVar9) {
          if (*(int *)(iVar15 + 0x40) != 0) {
            _gleSynchronizePluginBuffer(param_1,iVar15 + 0x10);
          }
          param_6 = param_6 + *(int *)(iVar15 + 0x30);
          goto LAB_00055d78;
        }
      }
    }
  }
LAB_00055d40:
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar4 = 0x502;
LAB_00055d50:
  *(undefined4 *)(param_1 + 0x7574) = uVar4;
  return;
}

/* _gleUploadPluginTextureLevel @ 0x55ff4 (420 bytes) */
void _gleUploadPluginTextureLevel(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 param_5;
  int param_6;
{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 a5;
  int iVar8;
  undefined4 a7;
  
  if ((*(byte *)(param_3 + 0xb) & 1) == 0) {
    iVar8 = *(int *)(param_3 + 0x14);
    if (iVar8 == 0) {
      iVar8 = _gleAllocateTextureLevel(param_1,param_2,param_3);
      if (iVar8 == 0) {
        return;
      }
      iVar8 = *(int *)(param_3 + 0x14);
    }
    iVar2 = param_6 * 0x2e0 + param_1;
    (**(code **)(*(int *)(iVar2 + 0x8884) + 0x160))
              (*(undefined4 *)(iVar2 + 0x85ac),*(undefined4 *)(param_2 + param_6 * 4),param_4,
               param_5,iVar8);
    if ((*(byte *)(param_3 + 0xb) & 0x80) == 0) {
      *(byte *)(param_3 + 0xb) = *(byte *)(param_3 + 0xb) | 0x10;
      *(byte *)(param_3 + 0xb) = *(byte *)(param_3 + 0xb) & 0xbf;
    }
  }
  else {
    uVar3 = *(undefined4 *)(param_1 + 0x31b0);
    *(uint *)(param_1 + 0x31b0) = (uint)*(ushort *)(param_3 + 0xc);
    uVar1 = *(ushort *)(param_3 + 0xe);
    iVar8 = param_6 * 0x2e0 + param_1;
    uVar7 = *(undefined4 *)(param_1 + 0x31bc);
    uVar6 = *(undefined4 *)(param_1 + 0x31c0);
    uVar5 = *(undefined4 *)(param_1 + 0x31c4);
    a7 = *(undefined4 *)(0x31b4 + param_1);
    a5 = *(undefined4 *)(param_1 + 0x31b8);
    uVar4 = *(undefined4 *)(param_1 + 0x31c8);
    *(undefined4 *)(param_1 + 0x31c4) = 1;
    *(uint *)(0x31b4 + param_1) = (uint)uVar1;
    *(undefined4 *)(param_1 + 0x31c0) = 0;
    *(undefined4 *)(param_1 + 0x31b8) = 0;
    *(undefined4 *)(param_1 + 0x31bc) = 0;
    (**(code **)(*(int *)(iVar8 + 0x8884) + 0x160))
              (*(undefined4 *)(iVar8 + 0x85ac),*(undefined4 *)(param_2 + param_6 * 4),param_4,
               param_5,*(undefined4 *)(param_3 + 0x14),a5,iVar8 + 0x10000,a7);
    if ((*(byte *)(param_3 + 0xb) & 0x80) == 0) {
      *(byte *)(param_3 + 0xb) = *(byte *)(param_3 + 0xb) | 0x10;
      *(byte *)(param_3 + 0xb) = *(byte *)(param_3 + 0xb) & 0xbf;
    }
    *(undefined4 *)(param_1 + 0x31c8) = uVar4;
    *(undefined4 *)(param_1 + 0x31b0) = uVar3;
    *(undefined4 *)(0x31b4 + param_1) = a7;
    *(undefined4 *)(param_1 + 0x31b8) = a5;
    *(undefined4 *)(param_1 + 0x31bc) = uVar7;
    *(undefined4 *)(param_1 + 0x31c0) = uVar6;
    *(undefined4 *)(param_1 + 0x31c4) = uVar5;
  }
  return;
}

/* _gleFlushPrimitiveTCLFunc @ 0x56198 (760 bytes) */
void _gleFlushPrimitiveTCLFunc(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined8 local_220 [64];
  int local_20 [5];
  
  iVar5 = (int)*(short *)(param_1 + 0x487c);
  switch(*(undefined2 *)(param_1 + 0x4a10)) {
  case 2:
    if (*(char *)(param_1 + 0x4a18) == '\0') {
      iVar4 = 0;
      iVar2 = *(int *)(param_1 + 0x4854);
      iVar1 = *(int *)(param_1 + 0x4868);
      if (0 < iVar5) {
        uVar6 = iVar5 + 7U >> 3;
        do {
          *(undefined8 *)(iVar2 + -0x100 + iVar4) = *(undefined8 *)(iVar1 + iVar4);
          iVar4 = iVar4 + 8;
          uVar6 = uVar6 - 1;
        } while (uVar6 != 0);
      }
    }
  case 3:
    iVar2 = 0;
    iVar1 = *(int *)(param_1 + 0x4858);
    *(undefined1 *)(param_1 + 0x4a18) = 1;
    if (0 < iVar5) {
      uVar6 = iVar5 + 7U >> 3;
      do {
        *(undefined8 *)((int)local_220 + iVar2) = *(undefined8 *)((iVar1 - iVar5) + iVar2);
        iVar2 = iVar2 + 8;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
    }
    break;
  case 5:
  case 8:
    iVar2 = iVar5 * 2;
    iVar4 = 0;
    iVar3 = *(int *)(param_1 + 0x4858);
    iVar1 = iVar5 * -2;
    iVar5 = iVar2;
    if (0 < iVar2) {
      uVar6 = iVar2 + 7U >> 3;
      do {
        *(undefined8 *)((int)local_220 + iVar4) = *(undefined8 *)(iVar3 + iVar1 + iVar4);
        iVar4 = iVar4 + 8;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
    }
    break;
  case 6:
    iVar2 = 0;
    iVar4 = *(int *)(param_1 + 0x4858);
    iVar1 = *(int *)(param_1 + 0x4868);
    if (0 < iVar5) {
      do {
        *(undefined8 *)((int)local_220 + iVar2) = *(undefined8 *)(iVar1 + iVar2);
        iVar2 = iVar2 + 8;
      } while (iVar2 < iVar5);
    }
    iVar2 = 0;
    if (0 < iVar5) {
      uVar6 = iVar5 + 7U >> 3;
      do {
        *(undefined8 *)((int)local_220 + iVar2 + iVar5) = *(undefined8 *)((iVar4 - iVar5) + iVar2);
        iVar2 = iVar2 + 8;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
    }
    break;
  case 9:
    iVar2 = 0;
    iVar4 = *(int *)(param_1 + 0x4858);
    iVar1 = *(int *)(param_1 + 0x4868);
    if (0 < iVar5) {
      do {
        *(undefined8 *)((int)local_220 + iVar2) = *(undefined8 *)(iVar1 + iVar2);
        iVar2 = iVar2 + 8;
      } while (iVar2 < iVar5);
    }
    iVar2 = 0;
    iVar4 = iVar4 - iVar5;
    if (0 < iVar5) {
      uVar6 = iVar5 + 7U >> 3;
      do {
        *(undefined8 *)((int)local_220 + iVar2 + iVar5) = *(undefined8 *)(iVar4 + iVar2);
        iVar2 = iVar2 + 8;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
    }
    if ((*(short *)(param_1 + 0x34d2) == 0x1b01) || (*(short *)(param_1 + 0x34d0) == 0x1b01)) {
      *(undefined1 *)(iVar4 + *(short *)(param_1 + 0x487e)) = 0;
    }
  }
  (**(code **)(param_1 + 0x4a08))(param_1);
  local_20[0] = *(int *)(param_1 + 0x4a14);
  iVar2 = (**(code **)(param_1 + 0x46e8))
                    (*(undefined4 *)(param_1 + 0x4688),(int)*(short *)(param_1 + 0x4a10),local_20);
  *(int *)(param_1 + 0x4868) = iVar2;
  *(int *)(param_1 + 0x485c) = iVar2 + *(short *)(param_1 + 0x487c) * local_20[0];
  switch(*(undefined2 *)(param_1 + 0x4a10)) {
  default:
    goto switchD_00056410_caseD_0;
  case 2:
  case 3:
    iVar1 = 0;
    if (0 < iVar5) {
      uVar6 = iVar5 + 7U >> 3;
      do {
        *(undefined8 *)(iVar2 + iVar1) = *(undefined8 *)((int)local_220 + iVar1);
        iVar1 = iVar1 + 8;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
    }
    break;
  case 9:
    if ((*(short *)(param_1 + 0x34d2) == 0x1b01) || (*(short *)(param_1 + 0x34d0) == 0x1b01)) {
      *(undefined1 *)((int)local_220 + (int)*(short *)(param_1 + 0x487e)) = 0;
    }
  case 6:
    iVar5 = iVar5 << 1;
  case 5:
  case 8:
    iVar1 = 0;
    if (0 < iVar5) {
      uVar6 = iVar5 + 7U >> 3;
      do {
        *(undefined8 *)(iVar2 + iVar1) = *(undefined8 *)((int)local_220 + iVar1);
        iVar1 = iVar1 + 8;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
    }
  }
  iVar2 = iVar2 + iVar5;
switchD_00056410_caseD_0:
  *(int *)(param_1 + 0x4858) = iVar2;
  return;
}

/* _glMultMatrixf_Exec @ 0x564e0 (140 bytes) */
int _glMultMatrixf_Exec(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  undefined1 auStack_50 [72];
  
  if ((*(short *)(param_1 + 0x4a10) < 0) && (*(int *)(param_1 + 0x4ff4) < 0x18)) {
    ((void (*)())_gleMultMatrixf)(*(undefined4 *)(param_1 + 0x4fec),param_2,auStack_50);
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

/* _gleMultMatrixf @ 0x5656c (836 bytes) */
void _gleMultMatrixf(param_1, param_2, param_3)
  float *param_1;
  float *param_2;
  float *param_3;
{
  *param_3 = param_1[0xc] * param_2[3] +
             (param_1[8] * param_2[2] + (*param_1 * *param_2 + param_1[4] * param_2[1]));
  param_3[4] = param_1[0xc] * param_2[7] +
               (param_1[8] * param_2[6] + (*param_1 * param_2[4] + param_1[4] * param_2[5]));
  param_3[8] = param_1[0xc] * param_2[0xb] +
               (param_1[8] * param_2[10] + (*param_1 * param_2[8] + param_1[4] * param_2[9]));
  param_3[0xc] = param_1[0xc] * param_2[0xf] +
                 (param_1[8] * param_2[0xe] + (*param_1 * param_2[0xc] + param_1[4] * param_2[0xd]));
  param_3[1] = param_1[0xd] * param_2[3] +
               (param_1[9] * param_2[2] + (param_1[1] * *param_2 + param_1[5] * param_2[1]));
  param_3[5] = param_1[0xd] * param_2[7] +
               (param_1[9] * param_2[6] + (param_1[1] * param_2[4] + param_1[5] * param_2[5]));
  param_3[9] = param_1[0xd] * param_2[0xb] +
               (param_1[9] * param_2[10] + (param_1[1] * param_2[8] + param_1[5] * param_2[9]));
  param_3[0xd] = param_1[0xd] * param_2[0xf] +
                 (param_1[9] * param_2[0xe] + (param_1[1] * param_2[0xc] + param_1[5] * param_2[0xd]));
  param_3[2] = param_1[0xe] * param_2[3] +
               (param_1[10] * param_2[2] + (param_1[2] * *param_2 + param_1[6] * param_2[1]));
  param_3[6] = param_1[0xe] * param_2[7] +
               (param_1[10] * param_2[6] + (param_1[2] * param_2[4] + param_1[6] * param_2[5]));
  param_3[10] = param_1[0xe] * param_2[0xb] +
                (param_1[10] * param_2[10] + (param_1[2] * param_2[8] + param_1[6] * param_2[9]));
  param_3[0xe] = param_1[0xe] * param_2[0xf] +
                 (param_1[10] * param_2[0xe] + (param_1[2] * param_2[0xc] + param_1[6] * param_2[0xd]));
  param_3[3] = param_1[0xf] * param_2[3] +
               (param_1[0xb] * param_2[2] + (param_1[3] * *param_2 + param_1[7] * param_2[1]));
  param_3[7] = param_1[0xf] * param_2[7] +
               (param_1[0xb] * param_2[6] + (param_1[3] * param_2[4] + param_1[7] * param_2[5]));
  param_3[0xb] = param_1[0xf] * param_2[0xb] +
                 (param_1[0xb] * param_2[10] + (param_1[3] * param_2[8] + param_1[7] * param_2[9]));
  param_3[0xf] = param_1[0xf] * param_2[0xf] +
                 (param_1[0xb] * param_2[0xe] + (param_1[3] * param_2[0xc] + param_1[7] * param_2[0xd]))
  ;
  return;
}

/* __dyld_func_lookup @ 0x568b0 (32 bytes) */
void __dyld_func_lookup()
{
                    
                    
  (*dyld_func_lookup_pointer)();
  return;
}

/* _glAccum_ListExec @ 0x568d0 (44 bytes) */
undefined4 _glAccum_ListExec(undefined4 param_1,undefined4 *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  ((void (*)())_glAccum_Exec)(param_1,*param_2,(double)GH_U2F((unsigned int)(param_2[1])),fparam_2,fparam_3,fparam_4,fparam_5,
                fparam_6,fparam_7,fparam_8);
  return 8;
}

/* _glAccum_Comp @ 0x568fc (92 bytes) */
undefined4 * _glAccum_Comp(undefined4 param_1,undefined4 param_2,float fparam_1)
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glAccum_ListExec_00110004,8);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = (float)fparam_1;
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glAccum_Exec @ 0x56958 (748 bytes) */
void _glAccum_Exec(int param_1,int param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar6;
  uint uVar7;
  int *piVar8;
  double extraout_f1;
  double fparam_1_00;
  
  if ((-1 < *(short *)(param_1 + 0x4a10)) || (*(int *)(*(int *)(param_1 + 0x468c) + 0x44) < 1)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
    goto LAB_00056bd4;
  }
  if (4 < param_2 - 0x100U) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x500;
    goto LAB_00056bd4;
  }
  if ((param_2 == 0x102) && (*(int *)(param_1 + 0x4e1c) != 0x1c00)) {
    return;
  }
  iVar6 = *(int *)(param_1 + 0x50ac);
  fparam_1_00 = fparam_1;
  if (iVar6 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(param_1);
    fparam_1_00 = extraout_f1;
  }
  if (*(char *)(param_1 + 0x4691) == '\0') goto LAB_00056c00;
  iVar5 = *(int *)(param_1 + 0x744c);
  piVar8 = (int *)(param_1 + 0x310);
  cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
  if ((iVar5 != 0) && (*(int *)(iVar5 + 0xec) != 0)) {
    ((void (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar5 + 0x10,in_r5,in_r6,in_r7,in_r8,iVar6,fparam_1_00,fparam_2,fparam_3,
               fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
  }
  if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_00056ad8:
    uVar7 = *(uint *)(param_1 + 0x31c);
  }
  else {
    iVar6 = 0;
    piVar4 = (int *)(param_1 + 0x324);
    do {
      iVar5 = *piVar4;
      piVar4 = piVar4 + 1;
      if (iVar5 != 0) {
        *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
        break;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < 9);
    uVar7 = *(uint *)(param_1 + 0x31c);
    if ((uVar7 & 0x15555) != 0) {
      if (*(char *)(param_1 + 0x2e54) != '\0') {
        _gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
      }
      if (*(char *)(param_1 + 0x3094) != '\0') {
        _gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
      }
      goto LAB_00056ad8;
    }
  }
  bVar1 = cVar2 == '\0';
  if (bVar1) {
    uVar7 = uVar7 & 0x17000000;
  }
  else {
    uVar7 = uVar7 & 0x17ffffff;
  }
  if (bVar1) {
    bVar1 = ((*piVar8 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar7 == 0) &&
            *(int *)(param_1 + 800) == 0;
  }
  else {
    bVar1 = (((*piVar8 == 0 && *(int *)(param_1 + 0x314) == 0) &&
             (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar7 == 0) &&
            *(int *)(param_1 + 800) == 0;
  }
  if (!bVar1) {
    if (*(char *)(param_1 + 0x85a8) == *(char *)(param_1 + 0x85a6)) {
      uVar7 = (**(code **)(param_1 + 0x4788))
                        (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar8);
      if ((((uVar7 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
          ((uVar7 & 4) != (uint)*(byte *)(param_1 + 0x7581))) ||
         ((uVar7 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0'))) {
        if ((uVar7 & 4) == 0) {
          uVar7 = uVar7 & 0xfffffffe;
          *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
        }
        _gleUpdateDispatchCodeChange(param_1,uVar7);
        if (*(char *)(param_1 + 0x759d) == '\0') {
          if (*(int *)(param_1 + 0x7574) != 0) {
            return;
          }
          uVar3 = 0x506;
LAB_00056bd4:
          *(undefined4 *)(param_1 + 0x7574) = uVar3;
          return;
        }
      }
    }
    else {
      _gleSwitchToNonRevertRenderer(param_1);
    }
    iVar6 = 0x13;
    do {
      *piVar8 = 0;
      piVar8 = piVar8 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
LAB_00056c00:
                    
                    
  (**(int ( **)(int,int,double))(param_1 + 0x4698))(*(undefined4 *)(param_1 + 0x4688), param_2, fparam_1);
  return;
}

/* _glAccum_CompExec @ 0x56c44 (72 bytes) */
void _glAccum_CompExec(undefined4 param_1,undefined4 param_2,float fparam_1)
{
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((undefined4 * (*)())_glAccum_Comp)(param_1,param_2,fparam_1);
  ((void (*)())_glAccum_Exec)(param_1,param_2,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
  return;
}

/* _glActiveTexture_ListExec @ 0x56c8c (40 bytes) */
int _glActiveTexture_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glActiveTexture_Exec(param_1,*param_2);
  return 4;
}

/* _glActiveTexture_Comp @ 0x56cb4 (76 bytes) */
int _glActiveTexture_Comp(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glActiveTexture_ListExec_00110008,4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glActiveTexture_CompExec @ 0x56d00 (56 bytes) */
void _glActiveTexture_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glActiveTexture_Comp)(param_1,param_2);
  _glActiveTexture_Exec(param_1,param_2);
  return;
}

/* _glAlphaFunc_ListExec @ 0x56d38 (44 bytes) */
int _glAlphaFunc_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((void (*)())_glAlphaFunc_Exec)(param_1,*param_2,(double)GH_U2F((unsigned int)(param_2[1])));
  return 8;
}

/* _glAlphaFunc_Comp @ 0x56d64 (92 bytes) */
undefined4 * _glAlphaFunc_Comp(undefined4 param_1,undefined4 param_2,float fparam_1)
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glAlphaFunc_ListExec_0011000c,8);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = (float)fparam_1;
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glAlphaFunc_CompExec @ 0x56dc0 (72 bytes) */
void _glAlphaFunc_CompExec(undefined4 param_1,undefined4 param_2,float fparam_1)
{
  ((undefined4 * (*)())_glAlphaFunc_Comp)(param_1,param_2,fparam_1);
  ((void (*)())_glAlphaFunc_Exec)(param_1,param_2,fparam_1);
  return;
}

/* _glVertexArrayParameteriEXT_ListExec @ 0x56e08 (44 bytes) */
int _glVertexArrayParameteriEXT_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((void (*)())_glVertexArrayParameteriEXT_Exec)(param_1,*param_2,param_2[1]);
  return 8;
}

/* _glVertexArrayParameteriEXT_Comp @ 0x56e34 (84 bytes) */
int _glVertexArrayParameteriEXT_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           _gleAddListItem(param_1,PTR__glVertexArrayParameteriEXT_ListExec_00110010,8);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = param_3;
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glVertexArrayParameteriEXT_Exec @ 0x56e88 (344 bytes) */
void _glVertexArrayParameteriEXT_Exec(param_1, param_2, param_3)
  int param_1;
  int param_2;
  uint param_3;
{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x4a60);
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x502;
    goto LAB_00056fc8;
  }
  if (param_2 != 0x851f) {
    if (param_2 == 0x897c) {
      *(char *)(iVar2 + 0x34c) = '\x01' - (param_3 == 0);
      *(undefined4 *)(iVar2 + 0x350) = *(undefined4 *)(iVar2 + 0x350);
      *(uint *)(iVar2 + 0x354) = *(uint *)(iVar2 + 0x354) | 4;
      *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x100000;
      return;
    }
    goto LAB_00056fb8;
  }
  if (param_3 == 0x85bd) {
    *(undefined2 *)(iVar2 + 0x342) = 0x85b4;
    goto LAB_00056f58;
  }
  if ((int)param_3 < 0x85be) {
    if (param_3 == 0x85b4) {
LAB_00056f34:
      if (*(ushort *)(iVar2 + 0x342) != param_3) {
        _gleUpdateDrawArraysFuncs(param_1);
        *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x100000;
        *(short *)(iVar2 + 0x342) = (short)param_3;
      }
LAB_00056f58:
      *(undefined4 *)(iVar2 + 0x350) = *(undefined4 *)(iVar2 + 0x350);
      *(uint *)(iVar2 + 0x354) = *(uint *)(iVar2 + 0x354) | 8;
      _gleModifyPluginVertexArray(param_1,iVar2 + 0x10);
      return;
    }
  }
  else if ((int)param_3 < 0x85c0) goto LAB_00056f34;
LAB_00056fb8:
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar1 = 0x500;
LAB_00056fc8:
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glVertexArrayParameteriEXT_CompExec @ 0x56fe0 (64 bytes) */
void _glVertexArrayParameteriEXT_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glVertexArrayParameteriEXT_Comp)(param_1,param_2,param_3);
  ((void (*)())_glVertexArrayParameteriEXT_Exec)(param_1,param_2,param_3);
  return;
}

/* _glPushAttrib_ListExec @ 0x57020 (40 bytes) */
int _glPushAttrib_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glPushAttrib_Exec(param_1,*param_2);
  return 4;
}

/* _glPushAttrib_Comp @ 0x57048 (76 bytes) */
int _glPushAttrib_Comp(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glPushAttrib_ListExec_00110018,4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glPushAttrib_CompExec @ 0x57094 (56 bytes) */
void _glPushAttrib_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glPushAttrib_Comp)(param_1,param_2);
  _glPushAttrib_Exec(param_1,param_2);
  return;
}

/* _glPopAttrib_ListExec @ 0x570cc (36 bytes) */
int _glPopAttrib_ListExec(param_1)
  undefined4 param_1;
{
  _glPopAttrib_Exec(param_1);
  return 0;
}

/* _glPopAttrib_Comp @ 0x570f0 (32 bytes) */
int _glPopAttrib_Comp(param_1)
  undefined4 param_1;
{
  undefined4 uVar1;
  
  uVar1 = _gleAddListItem(param_1,PTR__glPopAttrib_ListExec_00110014,0);
  return uVar1;
}

/* _glPopAttrib_CompExec @ 0x57110 (48 bytes) */
void _glPopAttrib_CompExec(param_1)
  undefined4 param_1;
{
  ((int (*)())_glPopAttrib_Comp)(param_1);
  _glPopAttrib_Exec(param_1);
  return;
}

/* _glPopClientAttrib_Exec @ 0x57140 (188 bytes) */
void _glPopClientAttrib_Exec(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (0 < *(int *)(param_1 + 0x5144)) {
      iVar2 = *(int *)(param_1 + 0x5140);
      *(int *)(param_1 + 0x5144) = *(int *)(param_1 + 0x5144) + -1;
      *(int *)(param_1 + 0x5140) = iVar2 + -4;
      iVar2 = *(int *)(iVar2 + -4);
      while (iVar2 != 0) {
        iVar3 = *(int *)(iVar2 + 700);
        _gleRemoveClientAttribElem(param_1,iVar2);
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

/* _glPushClientAttrib_Exec @ 0x571fc (184 bytes) */
void _glPushClientAttrib_Exec(param_1, param_2)
  int param_1;
  uint param_2;
{
  undefined4 uVar1;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (*(int *)(param_1 + 0x5144) < 0x10) {
      **(undefined4 **)(param_1 + 0x5140) = 0;
      if ((param_2 & 1) != 0) {
        _gleAddClientAttribElem(param_1,1);
      }
      if ((param_2 & 2) != 0) {
        _gleAddClientAttribElem(param_1,2);
      }
      *(int *)(param_1 + 0x5140) = *(int *)(param_1 + 0x5140) + 4;
      *(int *)(param_1 + 0x5144) = *(int *)(param_1 + 0x5144) + 1;
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

/* _glBegin_NoopExec @ 0x572b4 (668 bytes) */
void _glBegin_NoopExec(int param_1,undefined4 param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar6;
  uint uVar7;
  int *piVar8;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  
  if (*(char *)(param_1 + 0x759c) == '\0') {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
    goto LAB_00057518;
  }
  iVar6 = *(int *)(param_1 + 0x50ac);
  if (iVar6 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(param_1);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(param_1 + 0x4691) == '\0') {
LAB_000574fc:
    if (*(char *)(param_1 + 0x759d) != '\0') {
      ((void (*)())_glBegin_Exec)(param_1,param_2,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,
                    fparam_8);
      return;
    }
  }
  else {
    iVar5 = *(int *)(param_1 + 0x744c);
    piVar8 = (int *)(param_1 + 0x310);
    cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
    if ((iVar5 != 0) && (*(int *)(iVar5 + 0xec) != 0)) {
      ((void (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar5 + 0x10,in_r5,in_r6,in_r7,in_r8,iVar6,fparam_1,fparam_2,fparam_3,
                 fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
      *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
      fparam_1 = fparam_1;
    }
    if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_000573e8:
      uVar7 = *(uint *)(param_1 + 0x31c);
    }
    else {
      iVar6 = 0;
      piVar4 = (int *)(param_1 + 0x324);
      do {
        iVar5 = *piVar4;
        piVar4 = piVar4 + 1;
        if (iVar5 != 0) {
          *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
          break;
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < 9);
      uVar7 = *(uint *)(param_1 + 0x31c);
      if ((uVar7 & 0x15555) != 0) {
        if (*(char *)(param_1 + 0x2e54) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
        }
        if (*(char *)(param_1 + 0x3094) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
        }
        goto LAB_000573e8;
      }
    }
    bVar1 = cVar2 == '\0';
    if (bVar1) {
      uVar7 = uVar7 & 0x17000000;
    }
    else {
      uVar7 = uVar7 & 0x17ffffff;
    }
    if (bVar1) {
      bVar1 = ((*piVar8 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar7 == 0) &&
              *(int *)(param_1 + 800) == 0;
    }
    else {
      bVar1 = (((*piVar8 == 0 && *(int *)(param_1 + 0x314) == 0) &&
               (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar7 == 0) &&
              *(int *)(param_1 + 800) == 0;
    }
    if (bVar1) goto LAB_000574fc;
    if (*(char *)(param_1 + 0x85a8) != *(char *)(param_1 + 0x85a6)) {
      fparam_1 = (double)_gleSwitchToNonRevertRenderer(param_1);
LAB_000574e0:
      iVar6 = 0x13;
      do {
        *piVar8 = 0;
        piVar8 = piVar8 + 1;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      goto LAB_000574fc;
    }
    uVar7 = (**(code **)(param_1 + 0x4788))
                      (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar8);
    if ((((uVar7 & 3) == (uint)*(byte *)(param_1 + 0x7580)) &&
        ((uVar7 & 4) == (uint)*(byte *)(param_1 + 0x7581))) &&
       (fparam_1 = extraout_f1_01, (uVar7 & 8) == (uint)(*(char *)(param_1 + 0x759d) == '\0')))
    goto LAB_000574e0;
    if ((uVar7 & 4) == 0) {
      uVar7 = uVar7 & 0xfffffffe;
      *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
    }
    fparam_1 = (double)_gleUpdateDispatchCodeChange(param_1,uVar7);
    if (*(char *)(param_1 + 0x759d) != '\0') goto LAB_000574e0;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar3 = 0x506;
LAB_00057518:
  *(undefined4 *)(param_1 + 0x7574) = uVar3;
  return;
}

/* _glBitmap_ListExec @ 0x57550 (976 bytes) */
int _glBitmap_ListExec(int param_1,uint *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  float fVar2;
  float fVar3;
  char cVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar8;
  int iVar9;
  uint uVar10;
  int *piVar11;
  int iVar12;
  float *a1;
  double extraout_f1;
  
  iVar8 = *(int *)(param_1 + 0x4854);
  a1 = (float *)(iVar8 + -0x200);
  iVar12 = param_2[6] + 0x1c;
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return iVar12;
    }
    uVar5 = 0x502;
    goto LAB_0005782c;
  }
  fVar2 = (float)((double)CONCAT44(0x43300000,*param_2 ^ 0x80000000) - DOUBLE_00108d58);
  if ((fVar2 < FLOAT_00108e50) ||
     (fVar3 = (float)((double)CONCAT44(0x43300000,param_2[1] ^ 0x80000000) - DOUBLE_00108d58),
     fVar3 < FLOAT_00108e50)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return iVar12;
    }
    uVar5 = 0x501;
    goto LAB_0005782c;
  }
  if (*(char *)(param_1 + 0x2ef) == '\0') {
    return iVar12;
  }
  if (*(int *)(param_1 + 0x4e1c) != 0x1c00) {
    if (*(int *)(param_1 + 0x4e1c) == 0x1c01) {
      *(undefined4 *)(iVar8 + -0x200) = *(undefined4 *)(param_1 + 0x2e0);
      *(undefined4 *)(iVar8 + -0x1fc) = *(undefined4 *)(param_1 + 0x2e4);
      *(undefined4 *)(iVar8 + -0x1f8) = *(undefined4 *)(param_1 + 0x2e8);
      _gleFeedbackBitmap(param_1,a1);
    }
    goto LAB_000578e8;
  }
  if ((!(FLOAT_00108e50 < fVar2)) || (!(FLOAT_00108e50 < fVar3))) goto LAB_000578e8;
  iVar9 = *(int *)(param_1 + 0x50ac);
  if (iVar9 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(param_1);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(param_1 + 0x4691) != '\0') {
    iVar7 = *(int *)(param_1 + 0x744c);
    piVar11 = (int *)(param_1 + 0x310);
    cVar4 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
    if ((iVar7 != 0) && (*(int *)(iVar7 + 0xec) != 0)) {
      ((void (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar7 + 0x10,in_r5,in_r6,in_r7,in_r8,iVar9,fparam_1,fparam_2,fparam_3,
                 fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
      *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
    }
    if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_00057730:
      uVar10 = *(uint *)(param_1 + 0x31c);
    }
    else {
      iVar9 = 0;
      piVar6 = (int *)(param_1 + 0x324);
      do {
        iVar7 = *piVar6;
        piVar6 = piVar6 + 1;
        if (iVar7 != 0) {
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
        goto LAB_00057730;
      }
    }
    bVar1 = cVar4 == '\0';
    if (bVar1) {
      uVar10 = uVar10 & 0x17000000;
    }
    else {
      uVar10 = uVar10 & 0x17ffffff;
    }
    if (bVar1) {
      bVar1 = ((*piVar11 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar10 == 0) &&
              *(int *)(param_1 + 800) == 0;
    }
    else {
      bVar1 = (((*piVar11 == 0 && *(int *)(param_1 + 0x314) == 0) &&
               (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar10 == 0) &&
              *(int *)(param_1 + 800) == 0;
    }
    if (!bVar1) {
      if (*(char *)(param_1 + 0x85a8) == *(char *)(param_1 + 0x85a6)) {
        uVar10 = (**(code **)(param_1 + 0x4788))
                           (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar11);
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
              return iVar12;
            }
            uVar5 = 0x506;
LAB_0005782c:
            *(undefined4 *)(param_1 + 0x7574) = uVar5;
            return iVar12;
          }
        }
      }
      else {
        _gleSwitchToNonRevertRenderer(param_1);
      }
      iVar9 = 0x13;
      do {
        *piVar11 = 0;
        piVar11 = piVar11 + 1;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
    }
  }
  *a1 = *(float *)(param_1 + 0x4a44) * *(float *)(param_1 + 0x2e0) + *(float *)(param_1 + 0x4a48);
  *(float *)(iVar8 + -0x1fc) =
       *(float *)(param_1 + 0x4a4c) * *(float *)(param_1 + 0x2e4) + *(float *)(param_1 + 0x4a50);
  *(float *)(iVar8 + -0x1f8) = *(float *)(param_1 + 0x4a54) * *(float *)(param_1 + 0x2e8);
  (**(code **)(param_1 + 0x46ac))
            (*(undefined4 *)(param_1 + 0x4688),a1,*param_2,param_2[1],in_r7,in_r8,param_2 + 7,1,
             (double)GH_U2F((unsigned int)(param_2[2])),(double)GH_U2F((unsigned int)(param_2[3])));
LAB_000578e8:
  *(float *)(param_1 + 0x2e0) = *(float *)(param_1 + 0x2e0) + GH_U2F((unsigned int)(param_2[4]));
  *(float *)(param_1 + 0x2e4) = *(float *)(param_1 + 0x2e4) + GH_U2F((unsigned int)(param_2[5]));
  return iVar12;
}

/* _glBitmap_Comp @ 0x57920 (444 bytes) */
void _glBitmap_Comp(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,int param_8,float fparam_1,float fparam_2,float fparam_3,float fparam_4)
{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = *(int *)(param_1 + 0x4a6c);
  iVar4 = (param_2 + 7 >> 3) * param_3;
  uVar1 = iVar4 + 3U & 0xfffffffc;
  if (iVar5 != 0) {
    iVar2 = _gleOffsetLimitImage(param_1 + 0x31cc,param_2,param_3,0,0x1a00,param_8);
    if (*(int *)(iVar5 + 0x38) < iVar2) {
      if (*(int *)(param_1 + 0x7574) == 0) {
        *(undefined4 *)(param_1 + 0x7574) = 0x502;
      }
      goto LAB_00057ad0;
    }
    if (*(int *)(iVar5 + 0x40) != 0) {
      _gleSynchronizePluginBuffer(param_1,iVar5 + 0x10);
    }
    param_8 = param_8 + *(int *)(iVar5 + 0x30);
  }
  piVar3 = (int *)_gleAddListItem(param_1,PTR__glBitmap_ListExec_00110020,uVar1 + 0x1c);
  if (piVar3 != (int *)0x0) {
    piVar3[2] = (int)GH_F2U((float)fparam_1);
    piVar3[3] = (int)GH_F2U((float)fparam_2);
    piVar3[4] = (int)GH_F2U((float)fparam_3);
    piVar3[5] = (int)GH_F2U((float)fparam_4);
    piVar3[6] = uVar1;
    *piVar3 = param_2;
    piVar3[1] = param_3;
    if (iVar4 != 0) {
      if ((((*(char *)(param_1 + 0x31e5) == '\0') && (*(int *)(param_1 + 0x31cc) == 0)) &&
          (*(int *)(param_1 + 0x31d4) == 0)) &&
         ((*(int *)(param_1 + 0x31e0) == 1 && ((*(uint *)(param_1 + 0x31d8) & 7) == 0)))) {
        _gleCopy(param_8 + ((int)*(uint *)(param_1 + 0x31d8) >> 3),piVar3 + 7,iVar4,1,0,0);
        return;
      }
      _gleFillImage(param_1,param_2,param_3,1,0x1900,0x1a00,param_8,piVar3 + 7);
      return;
    }
  }
LAB_00057ad0:
  return;
}

/* _glBitmap_CompExec @ 0x57adc (120 bytes) */
void _glBitmap_CompExec(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,float fparam_1,float fparam_2,float fparam_3,float fparam_4)
{
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((void (*)())_glBitmap_Comp)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,fparam_1,fparam_2,
                 fparam_3,fparam_4);
  ((void (*)())_glBitmap_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,fparam_1,fparam_2,
                 fparam_3,fparam_4,in_f5,in_f6,in_f7,in_f8);
  return;
}

/* _glBitmap_NoopExec @ 0x57b54 (696 bytes) */
void _glBitmap_NoopExec(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,double fparam_1,double fparam_2,float fparam_3,float fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  double extraout_f1;
  double fparam_1_00;
  double fparam_2_00;
  double fparam_3_00;
  double fparam_4_00;
  
  uVar7 = *(uint *)(param_1 + 0x50ac);
  uVar6 = param_3;
  fparam_1_00 = fparam_1;
  fparam_2_00 = fparam_2;
  fparam_3_00 = fparam_3;
  fparam_4_00 = fparam_4;
  if (uVar7 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(param_1);
    fparam_1_00 = extraout_f1;
  }
  if (*(char *)(param_1 + 0x4691) != '\0') {
    iVar5 = *(int *)(param_1 + 0x744c);
    piVar9 = (int *)(param_1 + 0x310);
    cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
    if ((iVar5 != 0) && (*(int *)(iVar5 + 0xec) != 0)) {
      ((void (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar5 + 0x10,uVar6,param_4,param_5,param_6,uVar7,fparam_1_00,fparam_2_00,
                 fparam_3_00,fparam_4_00,fparam_5,fparam_6,fparam_7,fparam_8);
      *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
    }
    if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_00057c84:
      uVar8 = *(uint *)(param_1 + 0x31c);
    }
    else {
      iVar5 = 0;
      piVar4 = (int *)(param_1 + 0x324);
      do {
        iVar3 = *piVar4;
        piVar4 = piVar4 + 1;
        if (iVar3 != 0) {
          *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
          break;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < 9);
      uVar8 = *(uint *)(param_1 + 0x31c);
      if ((uVar8 & 0x15555) != 0) {
        if (*(char *)(param_1 + 0x2e54) != '\0') {
          _gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
        }
        if (*(char *)(param_1 + 0x3094) != '\0') {
          _gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
        }
        goto LAB_00057c84;
      }
    }
    bVar1 = cVar2 == '\0';
    if (bVar1) {
      uVar8 = uVar8 & 0x17000000;
    }
    else {
      uVar8 = uVar8 & 0x17ffffff;
    }
    uVar7 = *(uint *)(param_1 + 800);
    if (bVar1) {
      bVar1 = ((*piVar9 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar8 == 0) && uVar7 == 0;
    }
    else {
      bVar1 = (((*piVar9 == 0 && *(int *)(param_1 + 0x314) == 0) &&
               (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar8 == 0) && uVar7 == 0;
    }
    if (!bVar1) {
      uVar7 = (uint)*(byte *)(param_1 + 0x85a6);
      if (*(byte *)(param_1 + 0x85a8) == uVar7) {
        uVar8 = (**(code **)(param_1 + 0x4788))
                          (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar9);
        uVar7 = uVar8 & 4;
        if ((((uVar8 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
            (uVar7 != *(byte *)(param_1 + 0x7581))) ||
           ((uVar8 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0'))) {
          if (uVar7 == 0) {
            uVar8 = uVar8 & 0xfffffffe;
            *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
          }
          _gleUpdateDispatchCodeChange(param_1,uVar8);
          if (*(char *)(param_1 + 0x759d) == '\0') goto LAB_00057da4;
        }
      }
      else {
        _gleSwitchToNonRevertRenderer(param_1);
      }
      iVar5 = 0x13;
      do {
        *piVar9 = 0;
        piVar9 = piVar9 + 1;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
  }
  if (*(char *)(param_1 + 0x759d) != '\0') {
    ((void (*)())_glBitmap_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,uVar7,param_8,fparam_1,fparam_2,
                   fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
    return;
  }
LAB_00057da4:
  if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x506;
  }
  return;
}

/* _glBlendFunc_ListExec @ 0x57e0c (44 bytes) */
int _glBlendFunc_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glBlendFunc_Exec(param_1,*param_2,param_2[1]);
  return 8;
}

/* _glBlendFunc_Comp @ 0x57e38 (84 bytes) */
int _glBlendFunc_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glBlendFunc_ListExec_00110034,8);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = param_3;
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glBlendFunc_CompExec @ 0x57e8c (64 bytes) */
void _glBlendFunc_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glBlendFunc_Comp)(param_1,param_2,param_3);
  _glBlendFunc_Exec(param_1,param_2,param_3);
  return;
}

/* _glBlendColor_ListExec @ 0x57ecc (52 bytes) */
int _glBlendColor_ListExec(param_1, param_2)
  undefined4 param_1;
  float *param_2;
{
  ((void (*)())_glBlendColor_Exec)(param_1,(double)*param_2,(double)param_2[1],(double)param_2[2],
                     (double)param_2[3]);
  return 0x10;
}

/* _glBlendColor_Comp @ 0x57f00 (92 bytes) */
void _glBlendColor_Comp(undefined4 param_1,float fparam_1,float fparam_2,float fparam_3,float fparam_4)
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glBlendColor_ListExec_00110030,0x10);
  if (pfVar1 != (float *)0x0) {
    pfVar1[3] = (float)fparam_4;
    *pfVar1 = (float)fparam_1;
    pfVar1[1] = (float)fparam_2;
    pfVar1[2] = (float)fparam_3;
  }
  return;
}

/* _glBlendColor_Exec @ 0x57f5c (228 bytes) */
void _glBlendColor_Exec(int param_1,float fparam_1,float fparam_2,float fparam_3,float fparam_4)
{
  float fVar1;
  float fVar2;
  float dVar3;
  float dVar4;
  
  fVar2 = FLOAT_00108e54;
  fVar1 = FLOAT_00108e50;
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    *(undefined4 *)(param_1 + 0x7574) = 0x502;
    return;
  }
  dVar3 = (double)FLOAT_00108e50;
  dVar4 = (double)FLOAT_00108e54;
  *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 4;
  if (fparam_1 < (double)dVar3) {
    *(float *)(param_1 + 0x30d0) = fVar1;
  }
  else if ((double)dVar4 < fparam_1) {
    *(float *)(param_1 + 0x30d0) = fVar2;
  }
  else {
    *(float *)(param_1 + 0x30d0) = (float)fparam_1;
  }
  if (fparam_2 < (double)dVar3) {
    *(float *)(param_1 + 0x30d4) = fVar1;
  }
  else if ((double)dVar4 < fparam_2) {
    *(float *)(param_1 + 0x30d4) = fVar2;
  }
  else {
    *(float *)(param_1 + 0x30d4) = (float)fparam_2;
  }
  if (fparam_3 < (double)dVar3) {
    *(float *)(param_1 + 0x30d8) = fVar1;
  }
  else if ((double)dVar4 < fparam_3) {
    *(float *)(param_1 + 0x30d8) = fVar2;
  }
  else {
    *(float *)(param_1 + 0x30d8) = (float)fparam_3;
  }
  if (fparam_4 < (double)dVar3) {
    *(float *)(param_1 + 0x30dc) = fVar1;
    return;
  }
  if ((double)dVar4 < fparam_4) {
    *(float *)(param_1 + 0x30dc) = fVar2;
    return;
  }
  *(float *)(param_1 + 0x30dc) = (float)fparam_4;
  return;
}

/* _glBlendColor_CompExec @ 0x58040 (96 bytes) */
void _glBlendColor_CompExec(undefined4 param_1,float fparam_1,float fparam_2,float fparam_3,float fparam_4)
{
  ((void (*)())_glBlendColor_Comp)(param_1,fparam_1,fparam_2,fparam_3,fparam_4);
  ((void (*)())_glBlendColor_Exec)(param_1,fparam_1,fparam_2,fparam_3,fparam_4);
  return;
}

/* _glBlendEquation_ListExec @ 0x580a0 (40 bytes) */
int _glBlendEquation_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((void (*)())_glBlendEquation_Exec)(param_1,*param_2);
  return 4;
}

/* _glBlendEquation_Comp @ 0x580c8 (76 bytes) */
int _glBlendEquation_Comp(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glBlendEquation_ListExec_0011002c,4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glBlendEquation_Exec @ 0x58114 (128 bytes) */
void _glBlendEquation_Exec(param_1, param_2)
  int param_1;
  uint param_2;
{
  bool bVar1;
  undefined4 uVar2;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 < 0x800c) {
      if (0x8009 < param_2) goto LAB_0005817c;
      bVar1 = 2 < param_2 - 0x8006;
    }
    else {
      bVar1 = 1 < param_2 - 0x877d;
    }
    if (!bVar1) {
LAB_0005817c:
      *(short *)(param_1 + 0x30e2) = (short)param_2;
      *(short *)(param_1 + 0x30e0) = (short)param_2;
      *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 2;
      return;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x500;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar2;
  return;
}

/* _glBlendEquation_CompExec @ 0x58194 (56 bytes) */
void _glBlendEquation_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glBlendEquation_Comp)(param_1,param_2);
  ((void (*)())_glBlendEquation_Exec)(param_1,param_2);
  return;
}

/* _glBlendFuncSeparate_ListExec @ 0x581cc (56 bytes) */
int _glBlendFuncSeparate_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((void (*)())_glBlendFuncSeparate_Exec)(param_1,*param_2,param_2[1],param_2[2],param_2[3]);
  return 0x10;
}

/* _glBlendFuncSeparate_Comp @ 0x58204 (100 bytes) */
int _glBlendFuncSeparate_Comp(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glBlendFuncSeparate_ListExec_00110028,0x10);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[3] = param_5;
    *puVar1 = param_2;
    puVar1[1] = param_3;
    puVar1[2] = param_4;
  }
  return puVar1;
}

/* _glBlendFuncSeparate_Exec @ 0x58268 (248 bytes) */
void _glBlendFuncSeparate_Exec(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint param_2;
  uint param_3;
  uint param_4;
  uint param_5;
{
  bool bVar1;
  undefined4 uVar2;
  
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x502;
    goto LAB_000582c0;
  }
  if (param_3 < 0x308) {
    if (param_3 < 0x300) {
      bVar1 = 1 < param_3;
      goto LAB_000582ac;
    }
LAB_000582c8:
    if (param_2 < 0x309) {
      if (param_2 < 0x300) {
        bVar1 = 1 < param_2;
        goto LAB_000582ec;
      }
    }
    else {
      bVar1 = 3 < param_2 - 0x8001;
LAB_000582ec:
      if (bVar1) goto LAB_000582b0;
    }
    if (param_5 < 0x308) {
      if (param_5 < 0x300) {
        bVar1 = 1 < param_5;
        goto LAB_00058314;
      }
    }
    else {
      bVar1 = 3 < param_5 - 0x8001;
LAB_00058314:
      if (bVar1) goto LAB_000582b0;
    }
    if (param_4 < 0x309) {
      if (0x2ff < param_4) goto LAB_00058340;
      bVar1 = 1 < param_4;
    }
    else {
      bVar1 = 3 < param_4 - 0x8001;
    }
    if (!bVar1) {
LAB_00058340:
      *(short *)(param_1 + 0x30ca) = (short)param_3;
      *(short *)(param_1 + 0x30c8) = (short)param_2;
      *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 2;
      *(short *)(param_1 + 0x30ce) = (short)param_5;
      *(short *)(param_1 + 0x30cc) = (short)param_4;
      return;
    }
  }
  else {
    bVar1 = 3 < param_3 - 0x8001;
LAB_000582ac:
    if (!bVar1) goto LAB_000582c8;
  }
LAB_000582b0:
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar2 = 0x500;
LAB_000582c0:
  *(undefined4 *)(param_1 + 0x7574) = uVar2;
  return;
}

/* _glBlendFuncSeparate_CompExec @ 0x58360 (80 bytes) */
void _glBlendFuncSeparate_CompExec(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  ((int (*)())_glBlendFuncSeparate_Comp)(param_1,param_2,param_3,param_4,param_5);
  ((void (*)())_glBlendFuncSeparate_Exec)(param_1,param_2,param_3,param_4,param_5);
  return;
}

/* _glBlendEquationSeparateEXT_ListExec @ 0x583b0 (44 bytes) */
int _glBlendEquationSeparateEXT_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((void (*)())_glBlendEquationSeparateEXT_Exec)(param_1,*param_2,param_2[1]);
  return 8;
}

/* _glBlendEquationSeparateEXT_Comp @ 0x583dc (84 bytes) */
int _glBlendEquationSeparateEXT_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           _gleAddListItem(param_1,PTR__glBlendEquationSeparateEXT_ListExec_00110024,8);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = param_3;
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glBlendEquationSeparateEXT_Exec @ 0x58430 (176 bytes) */
void _glBlendEquationSeparateEXT_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  uint param_3;
{
  bool bVar1;
  undefined4 uVar2;
  
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x502;
    goto LAB_00058490;
  }
  if (param_2 < 0x800c) {
    if (param_2 < 0x800a) {
      bVar1 = 2 < param_2 - 0x8006;
      goto LAB_0005847c;
    }
LAB_00058498:
    if (param_3 < 0x800c) {
      if (0x8009 < param_3) goto LAB_000584c8;
      bVar1 = 2 < param_3 - 0x8006;
    }
    else {
      bVar1 = 1 < param_3 - 0x877d;
    }
    if (!bVar1) {
LAB_000584c8:
      *(short *)(param_1 + 0x30e0) = (short)param_2;
      *(short *)(param_1 + 0x30e2) = (short)param_3;
      *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 2;
      return;
    }
  }
  else {
    bVar1 = 1 < param_2 - 0x877d;
LAB_0005847c:
    if (!bVar1) goto LAB_00058498;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar2 = 0x500;
LAB_00058490:
  *(undefined4 *)(param_1 + 0x7574) = uVar2;
  return;
}

/* _glBlendEquationSeparateEXT_CompExec @ 0x584e0 (64 bytes) */
void _glBlendEquationSeparateEXT_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glBlendEquationSeparateEXT_Comp)(param_1,param_2,param_3);
  ((void (*)())_glBlendEquationSeparateEXT_Exec)(param_1,param_2,param_3);
  return;
}

