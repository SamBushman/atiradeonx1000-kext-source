#include "decls.h"

/* _glFinish_Exec @ 0x555d4 (724 bytes) */
void _glFinish_Exec(int glContext,double fparam_1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  uint loopIndex3;
  int loopIndex2;
  int loopIndex;
  bool bVar1;
  char cVar2;
  undefined4 glErrorCode;
  int *srcCursor;
  int iVar5;
  int framebufferObject;
  undefined4 incomingR5;
  undefined4 incomingR6;
  undefined4 incomingR7;
  undefined4 incomingR8;
  int iVar6;
  int matrixChangeBits;
  uint uVar7;
  int *piVar8;
  double extraout_f1;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    matrixChangeBits = *(int *)(glContext + 0x50ac);
    if (matrixChangeBits != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
      _gleUpdateMatrixFunc(glContext);
      fparam_1 = extraout_f1;
    }
    if (*(char *)(glContext + 0x4691) != '\0') {
      framebufferObject = *(int *)(glContext + 0x744c);
      piVar8 = (int *)(glContext + 0x310);
      cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
      if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
        ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,incomingR5,incomingR6,incomingR7,incomingR8,matrixChangeBits,fparam_1,forwardedFloatArg2,forwardedFloatArg3,
                   forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
        *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
      }
      if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_00055708:
        uVar7 = *(uint *)(glContext + 0x31c);
      }
      else {
        loopIndex = 0;
        srcCursor = (int *)(glContext + 0x324);
        do {
          iVar5 = *srcCursor;
          srcCursor = srcCursor + 1;
          if (iVar5 != 0) {
            *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
            break;
          }
          loopIndex = loopIndex + 1;
        } while (loopIndex < 9);
        uVar7 = *(uint *)(glContext + 0x31c);
        if ((uVar7 & 0x15555) != 0) {
          if (*(char *)(glContext + 0x2e54) != '\0') {
            _gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
          }
          if (*(char *)(glContext + 0x3094) != '\0') {
            _gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
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
        bVar1 = ((*piVar8 == 0 && *(int *)(glContext + 0x314) == 0) && uVar7 == 0) &&
                *(int *)(glContext + 800) == 0;
      }
      else {
        bVar1 = (((*piVar8 == 0 && *(int *)(glContext + 0x314) == 0) &&
                 (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && uVar7 == 0) &&
                *(int *)(glContext + 800) == 0;
      }
      if (!bVar1) {
        if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
          uVar7 = (**(code **)(glContext + 0x4788))
                            (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,piVar8);
          if ((((uVar7 & 3) != (uint)*(byte *)(glContext + 0x7580)) ||
              ((uVar7 & 4) != (uint)*(byte *)(glContext + 0x7581))) ||
             ((uVar7 & 8) != (uint)(*(char *)(glContext + 0x759d) == '\0'))) {
            if ((uVar7 & 4) == 0) {
              uVar7 = uVar7 & 0xfffffffe;
              *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
            }
            _gleUpdateDispatchCodeChange(glContext,uVar7);
            if (*(char *)(glContext + 0x759d) == '\0') {
              if (*(int *)(glContext + 0x7574) != 0) {
                return;
              }
              glErrorCode = 0x506;
              goto LAB_0005580c;
            }
          }
        }
        else {
          _gleSwitchToNonRevertRenderer(glContext);
        }
        loopIndex2 = 0;
        do {
          loopIndex2 = loopIndex2 + 1;
          *piVar8 = 0;
          piVar8 = piVar8 + 1;
        } while (loopIndex2 < 0x13);
      }
    }
    loopIndex3 = 0;
    (**(code **)(glContext + 0x46f0))(*(undefined4 *)(glContext + 0x4688));
    if (*(char *)(glContext + 0x85a4) != '\0') {
      iVar6 = glContext + 0x10000;
      do {
        if (loopIndex3 != *(byte *)(glContext + 0x85a8)) {
          (**(code **)(*(int *)(iVar6 + -0x777c) + 0x178))(*(undefined4 *)(iVar6 + -0x7a54));
        }
        loopIndex3 = loopIndex3 + 1;
        iVar6 = iVar6 + 0x2e0;
      } while ((int)loopIndex3 < (int)(uint)*(byte *)(glContext + 0x85a4));
    }
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
LAB_0005580c:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  }
  return;
}

/* _glFrontFace_Exec @ 0x558a8 (76 bytes) */
void _glFrontFace_Exec(glContext, mode)
  int glContext;
  int mode;
{
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((1 < mode - 0x900U) && (*(int *)(glContext + 0x7574) == 0)) {
      *(undefined4 *)(glContext + 0x7574) = 0x500;
    }
    *(short *)(glContext + 0x34d4) = (short)mode;
    _gleUpdatePolyMode(glContext);
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x502;
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
  int glContext;
  int iVar2;
  
  glContext = _gl_list;
  while (glContext != 0) {
    iVar2 = *(int *)(glContext + 0x85a0);
    _gliDestroyContext(glContext);
    glContext = iVar2;
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
void _glepPluginDisconnect(plugin)
  int plugin;
{
  int iVar1;
  code *a0;
  
  if (*(int *)(plugin + 0x108) != 0) {
    iVar1 = _NSLookupSymbolInModule(*(undefined4 *)(plugin + 0x10c),"_gldTerminateLibrary");
    if ((iVar1 != 0) && (a0 = (code *)_NSAddressOfSymbol(iVar1), a0 != (code *)0x0)) {
      (*a0)(a0);
    }
    _NSUnLinkModule(*(undefined4 *)(plugin + 0x10c),0);
    *(undefined4 *)(plugin + 0x10c) = 0;
    _NSDestroyObjectFileImage(*(undefined4 *)(plugin + 0x108));
    *(undefined4 *)(plugin + 0x108) = 0;
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
void _glTexCoord3f_Exec(int glContext,float sCoord,float tCoord,float rCoord)
{
  *(float *)(glContext + 0x120) = (float)sCoord;
  *(uint *)(glContext + 0x486c) = *(uint *)(glContext + 0x486c) | 1;
  *(float *)(glContext + 0x124) = (float)tCoord;
  *(float *)(glContext + 0x128) = (float)rCoord;
  *(undefined4 *)(glContext + 300) = *(undefined4 *)(glContext + 0x24);
  return;
}

/* _glGetTexImage_Exec @ 0x55b00 (1268 bytes) */
void _glGetTexImage_Exec(glContext, target, level, format, type, pixels)
  int glContext;
  int target;
  uint level;
  uint format;
  uint type;
  int pixels;
{
  int loopIndex;
  undefined4 glErrorCode;
  bool bVar1;
  byte bVar2;
  ushort uVar3;
  undefined4 uVar4;
  short sVar5;
  int iVar6;
  int iVar7;
  int rowBytes;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  uint uVar12;
  uint glContextByte31c8;
  uint *puVar13;
  int *piVar14;
  int pixelPackBuffer;
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
  
  uVar16 = target - 0x8515;
  iVar7 = _gleLookUpNonProxyTexture(glContext,target);
  if (5 < uVar16) {
    uVar16 = 0;
  }
  iVar6 = iVar7 + uVar16 * 0x168 + level * 0x18;
  if (-1 < *(short *)(glContext + 0x4a10)) goto LAB_00055d40;
  if (iVar7 == 0) goto LAB_00055c7c;
  if (0xe < level) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x501;
    goto LAB_00055d50;
  }
  if (type < 0x8037) {
    if (0x8032 < type) {
LAB_00055c54:
      if (format != 0x1908) {
        uVar12 = 0x80e1;
        goto LAB_00055c70;
      }
      goto LAB_00055c94;
    }
    if (type != 0x140b) {
      if (type < 0x140c) {
        if (type - 0x1400 < 7) goto LAB_00055c00;
      }
      else if (type == 0x8032) goto LAB_00055c4c;
LAB_00055c7c:
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x500;
      goto LAB_00055d50;
    }
LAB_00055c00:
    if (format < 0x190b) {
      if (0x1901 < format) goto LAB_00055c94;
      if (format != 0x1900) goto LAB_00055d40;
      goto LAB_00055c98;
    }
    if ((format == 0x8000) || ((0x7fff < format && (format - 0x80e0 < 2)))) goto LAB_00055c94;
  }
  else {
    if (type < 0x8369) {
      if (0x8364 < type) goto LAB_00055c54;
      if (type < 0x8362) goto LAB_00055c7c;
LAB_00055c4c:
      bVar1 = format == 0x1907;
    }
    else {
      if (1 < type - 0x85ba) goto LAB_00055c7c;
      uVar12 = 0x85b9;
LAB_00055c70:
      bVar1 = format == uVar12;
    }
    if (!bVar1) goto LAB_00055d40;
LAB_00055c94:
    if (format == 0x1900) {
LAB_00055c98:
      sVar5 = *(short *)(iVar6 + 0xd4);
      if (sVar5 != 0x1900) goto LAB_00055d40;
    }
    else {
      sVar5 = *(short *)(iVar6 + 0xd4);
    }
    if ((format == 0x1902) == (sVar5 == 0x1902)) {
      pixelPackBuffer = *(int *)(glContext + 0x4a68);
      if (pixelPackBuffer == 0) {
LAB_00055d78:
        bVar2 = *(byte *)(iVar6 + 0xcf);
        if ((bVar2 & 0x20) == 0) {
          return;
        }
        if ((((int)level < (int)(uint)*(byte *)(iVar7 + 0x8d)) ||
            ((int)(uint)*(byte *)(iVar7 + 0x8f) < (int)level)) || ((bVar2 & 0x40) == 0)) {
          if ((bVar2 & 0x10) == 0) {
            return;
          }
        }
        else {
          ((void (*)())_gleUploadPluginTextureLevel)(glContext,iVar7,iVar6 + 0xc4,uVar16,level,(uint)*(byte *)(glContext + 0x85a8));
        }
        uVar16 = (uint)*(ushort *)(iVar6 + 0xca);
        puVar13 = &uStack_50;
        piVar14 = &iStack_4c;
        _glePixelPackSettings
                  (glContext,format,type,(uint)*(ushort *)(iVar6 + 200),uVar16,glContext + 0x31b0,
                   puVar13,piVar14,&puStack_60,auStack_5c,&uStack_58,auStack_54);
        if (((((*(byte *)(iVar6 + 0xcf) & 1) == 0) ||
             (pixels + iStack_4c != *(int *)(iVar6 + 0xd8))) ||
            ((format != *(ushort *)(iVar6 + 0xd4) ||
             ((type != *(ushort *)(iVar6 + 0xd6) ||
              (puVar13 = puStack_60, (uint)puStack_60 / uStack_50 != (uint)*(ushort *)(iVar6 + 0xd0)
              )))))) || (uStack_58 / (uint)puStack_60 != (uint)*(ushort *)(iVar6 + 0xd2))) {
          glContextByte31c8 = (uint)*(byte *)(glContext + 0x31c8);
        }
        else {
          glContextByte31c8 = (uint)*(byte *)(glContext + 0x31c8);
          if (glContextByte31c8 == 0) {
            return;
          }
        }
        uStack_ac = 0x60000;
        if ((*(short *)(iVar7 + 0x26) == 0x1907) &&
           ((*(short *)(iVar6 + 0xd4) == 0x1908 || (*(short *)(iVar6 + 0xd4) == -0x7f1f)))) {
          uStack_ac = 0x68000;
        }
        if (glContextByte31c8 != 0) {
          uStack_ac = uStack_ac | 2;
        }
        loopIndex = 0;
        rowBytes = _gleRowBytes((uint)*(ushort *)(iVar6 + 0xd4),(uint)*(ushort *)(iVar6 + 0xd6),
                             (uint)*(ushort *)(iVar6 + 0xd0));
        _glgConvertType((uint)*(ushort *)(iVar6 + 0xd4),(uint)*(ushort *)(iVar6 + 0xd6),&uStack_48,
                        &uStack_44,uVar16,glContextByte31c8,puVar13,piVar14);
        puVar10 = &uStack_40;
        puVar11 = auStack_3c;
        _glgConvertType(format,type,puVar10,puVar11,uVar16,glContextByte31c8,puVar13,piVar14);
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
        iStack_cc = rowBytes;
        do {
          loopIndex = loopIndex + 1;
          iStack_c0 = pixels + iStack_4c + iVar9;
          iStack_d0 = *(int *)(iVar6 + 0xd8) + iVar8;
          iVar8 = iVar8 + rowBytes * (uint)uVar3;
          _glgProcessPixels(glContext + 0x31a8,&iStack_d0,puVar10,puVar11,uVar16,glContextByte31c8,uVar4,piVar14)
          ;
          iVar9 = iVar9 + uStack_58;
        } while (loopIndex < (int)(uint)*(ushort *)(iVar6 + 0xcc));
        return;
      }
      iVar8 = _gleOffsetLimitImage3D
                        (glContext + 0x31b0,(uint)*(ushort *)(iVar6 + 200),
                         (uint)*(ushort *)(iVar6 + 0xca),(uint)*(ushort *)(iVar6 + 0xcc),format,
                         type,pixels);
      iVar17 = *(int *)(pixelPackBuffer + 0x38);
      dVar18 = (double)((double (*)())_gleBytesPerElement)(type);
      iVar9 = (int)dVar18;
      if (iVar8 <= iVar17) {
        if (iVar9 == 0) {
          iVar9 = _glePixelBytes(format,type);
        }
        if (pixels == (pixels / iVar9) * iVar9) {
          if (*(int *)(pixelPackBuffer + 0x40) != 0) {
            _gleSynchronizePluginBuffer(glContext,pixelPackBuffer + 0x10);
          }
          pixels = pixels + *(int *)(pixelPackBuffer + 0x30);
          goto LAB_00055d78;
        }
      }
    }
  }
LAB_00055d40:
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x502;
LAB_00055d50:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _gleUploadPluginTextureLevel @ 0x55ff4 (420 bytes) */
void _gleUploadPluginTextureLevel(glContext, param_2, param_3, forwardedArg4, level, param_6)
  int glContext;
  int param_2;
  int param_3;
  undefined4 forwardedArg4;
  undefined4 level;
  int param_6;
{
  ushort uVar1;
  int iVar2;
  undefined4 glContextWord31b0;
  undefined4 glContextWord31c8;
  undefined4 glContextWord31c4;
  undefined4 glContextWord31c0;
  undefined4 glContextWord31bc;
  undefined4 a5;
  int iVar8;
  undefined4 a7;
  
  if ((*(byte *)(param_3 + 0xb) & 1) == 0) {
    iVar8 = *(int *)(param_3 + 0x14);
    if (iVar8 == 0) {
      iVar8 = _gleAllocateTextureLevel(glContext,param_2,param_3);
      if (iVar8 == 0) {
        return;
      }
      iVar8 = *(int *)(param_3 + 0x14);
    }
    iVar2 = param_6 * 0x2e0 + glContext;
    (**(code **)(*(int *)(iVar2 + 0x8884) + 0x160))
              (*(undefined4 *)(iVar2 + 0x85ac),*(undefined4 *)(param_2 + param_6 * 4),forwardedArg4,
               level,iVar8);
    if ((*(byte *)(param_3 + 0xb) & 0x80) == 0) {
      *(byte *)(param_3 + 0xb) = *(byte *)(param_3 + 0xb) | 0x10;
      *(byte *)(param_3 + 0xb) = *(byte *)(param_3 + 0xb) & 0xbf;
    }
  }
  else {
    glContextWord31b0 = *(undefined4 *)(glContext + 0x31b0);
    *(uint *)(glContext + 0x31b0) = (uint)*(ushort *)(param_3 + 0xc);
    uVar1 = *(ushort *)(param_3 + 0xe);
    iVar8 = param_6 * 0x2e0 + glContext;
    glContextWord31bc = *(undefined4 *)(glContext + 0x31bc);
    glContextWord31c0 = *(undefined4 *)(glContext + 0x31c0);
    glContextWord31c4 = *(undefined4 *)(glContext + 0x31c4);
    a7 = *(undefined4 *)(0x31b4 + glContext);
    a5 = *(undefined4 *)(glContext + 0x31b8);
    glContextWord31c8 = *(undefined4 *)(glContext + 0x31c8);
    *(undefined4 *)(glContext + 0x31c4) = 1;
    *(uint *)(0x31b4 + glContext) = (uint)uVar1;
    *(undefined4 *)(glContext + 0x31c0) = 0;
    *(undefined4 *)(glContext + 0x31b8) = 0;
    *(undefined4 *)(glContext + 0x31bc) = 0;
    (**(code **)(*(int *)(iVar8 + 0x8884) + 0x160))
              (*(undefined4 *)(iVar8 + 0x85ac),*(undefined4 *)(param_2 + param_6 * 4),forwardedArg4,
               level,*(undefined4 *)(param_3 + 0x14),a5,iVar8 + 0x10000,a7);
    if ((*(byte *)(param_3 + 0xb) & 0x80) == 0) {
      *(byte *)(param_3 + 0xb) = *(byte *)(param_3 + 0xb) | 0x10;
      *(byte *)(param_3 + 0xb) = *(byte *)(param_3 + 0xb) & 0xbf;
    }
    *(undefined4 *)(glContext + 0x31c8) = glContextWord31c8;
    *(undefined4 *)(glContext + 0x31b0) = glContextWord31b0;
    *(undefined4 *)(0x31b4 + glContext) = a7;
    *(undefined4 *)(glContext + 0x31b8) = a5;
    *(undefined4 *)(glContext + 0x31bc) = glContextWord31bc;
    *(undefined4 *)(glContext + 0x31c0) = glContextWord31c0;
    *(undefined4 *)(glContext + 0x31c4) = glContextWord31c4;
  }
  return;
}

/* _gleFlushPrimitiveTCLFunc @ 0x56198 (760 bytes) */
void _gleFlushPrimitiveTCLFunc(glContext)
  int glContext;
{
  int loopIndex9;
  int loopIndex8;
  int loopIndex7;
  int loopIndex6;
  int loopIndex5;
  int loopIndex4;
  int loopIndex3;
  int loopIndex2;
  int loopIndex;
  int iVar1;
  int glContextWord4858;
  int glContextPtr4868;
  int iVar2;
  int glContextPtr4854;
  int glContextPtr4858;
  int iVar4;
  int glContextWord48582;
  int iVar5;
  uint uVar6;
  undefined8 local_220 [64];
  int local_20 [5];
  
  iVar5 = (int)*(short *)(glContext + 0x487c);
  switch(*(undefined2 *)(glContext + 0x4a10)) {
  case 2:
    if (*(char *)(glContext + 0x4a18) == '\0') {
      loopIndex8 = 0;
      glContextPtr4854 = *(int *)(glContext + 0x4854);
      glContextPtr4868 = *(int *)(glContext + 0x4868);
      if (0 < iVar5) {
        uVar6 = iVar5 + 7U >> 3;
        do {
          *(undefined8 *)(glContextPtr4854 + -0x100 + loopIndex8) = *(undefined8 *)(glContextPtr4868 + loopIndex8);
          loopIndex8 = loopIndex8 + 8;
          uVar6 = uVar6 - 1;
        } while (uVar6 != 0);
      }
    }
  case 3:
    loopIndex3 = 0;
    glContextWord4858 = *(int *)(glContext + 0x4858);
    *(undefined1 *)(glContext + 0x4a18) = 1;
    if (0 < iVar5) {
      uVar6 = iVar5 + 7U >> 3;
      do {
        *(undefined8 *)((int)local_220 + loopIndex3) = *(undefined8 *)((glContextWord4858 - iVar5) + loopIndex3);
        loopIndex3 = loopIndex3 + 8;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
    }
    break;
  case 5:
  case 8:
    iVar2 = iVar5 * 2;
    loopIndex9 = 0;
    glContextPtr4858 = *(int *)(glContext + 0x4858);
    iVar1 = iVar5 * -2;
    iVar5 = iVar2;
    if (0 < iVar2) {
      uVar6 = iVar2 + 7U >> 3;
      do {
        *(undefined8 *)((int)local_220 + loopIndex9) = *(undefined8 *)(glContextPtr4858 + iVar1 + loopIndex9);
        loopIndex9 = loopIndex9 + 8;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
    }
    break;
  case 6:
    loopIndex4 = 0;
    glContextWord48582 = *(int *)(glContext + 0x4858);
    glContextPtr4868 = *(int *)(glContext + 0x4868);
    if (0 < iVar5) {
      do {
        *(undefined8 *)((int)local_220 + loopIndex4) = *(undefined8 *)(glContextPtr4868 + loopIndex4);
        loopIndex4 = loopIndex4 + 8;
      } while (loopIndex4 < iVar5);
    }
    loopIndex5 = 0;
    if (0 < iVar5) {
      uVar6 = iVar5 + 7U >> 3;
      do {
        *(undefined8 *)((int)local_220 + loopIndex5 + iVar5) = *(undefined8 *)((glContextWord48582 - iVar5) + loopIndex5);
        loopIndex5 = loopIndex5 + 8;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
    }
    break;
  case 9:
    loopIndex6 = 0;
    iVar4 = *(int *)(glContext + 0x4858);
    glContextPtr4868 = *(int *)(glContext + 0x4868);
    if (0 < iVar5) {
      do {
        *(undefined8 *)((int)local_220 + loopIndex6) = *(undefined8 *)(glContextPtr4868 + loopIndex6);
        loopIndex6 = loopIndex6 + 8;
      } while (loopIndex6 < iVar5);
    }
    loopIndex7 = 0;
    iVar4 = iVar4 - iVar5;
    if (0 < iVar5) {
      uVar6 = iVar5 + 7U >> 3;
      do {
        *(undefined8 *)((int)local_220 + loopIndex7 + iVar5) = *(undefined8 *)(iVar4 + loopIndex7);
        loopIndex7 = loopIndex7 + 8;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
    }
    if ((*(short *)(glContext + 0x34d2) == 0x1b01) || (*(short *)(glContext + 0x34d0) == 0x1b01)) {
      *(undefined1 *)(iVar4 + *(short *)(glContext + 0x487e)) = 0;
    }
  }
  (**(code **)(glContext + 0x4a08))(glContext);
  local_20[0] = *(int *)(glContext + 0x4a14);
  iVar2 = (**(code **)(glContext + 0x46e8))
                    (*(undefined4 *)(glContext + 0x4688),(int)*(short *)(glContext + 0x4a10),local_20);
  *(int *)(glContext + 0x4868) = iVar2;
  *(int *)(glContext + 0x485c) = iVar2 + *(short *)(glContext + 0x487c) * local_20[0];
  switch(*(undefined2 *)(glContext + 0x4a10)) {
  default:
    goto switchD_00056410_caseD_0;
  case 2:
  case 3:
    loopIndex = 0;
    if (0 < iVar5) {
      uVar6 = iVar5 + 7U >> 3;
      do {
        *(undefined8 *)(iVar2 + loopIndex) = *(undefined8 *)((int)local_220 + loopIndex);
        loopIndex = loopIndex + 8;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
    }
    break;
  case 9:
    if ((*(short *)(glContext + 0x34d2) == 0x1b01) || (*(short *)(glContext + 0x34d0) == 0x1b01)) {
      *(undefined1 *)((int)local_220 + (int)*(short *)(glContext + 0x487e)) = 0;
    }
  case 6:
    iVar5 = iVar5 << 1;
  case 5:
  case 8:
    loopIndex2 = 0;
    if (0 < iVar5) {
      uVar6 = iVar5 + 7U >> 3;
      do {
        *(undefined8 *)(iVar2 + loopIndex2) = *(undefined8 *)((int)local_220 + loopIndex2);
        loopIndex2 = loopIndex2 + 8;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
    }
  }
  iVar2 = iVar2 + iVar5;
switchD_00056410_caseD_0:
  *(int *)(glContext + 0x4858) = iVar2;
  return;
}

/* _glMultMatrixf_Exec @ 0x564e0 (140 bytes) */
int _glMultMatrixf_Exec(glContext, m)
  int glContext;
  undefined4 m;
{
  int iVar1;
  undefined1 auStack_50 [72];
  
  if ((*(short *)(glContext + 0x4a10) < 0) && (*(int *)(glContext + 0x4ff4) < 0x18)) {
    ((void (*)())_gleMultMatrixf)(*(undefined4 *)(glContext + 0x4fec),m,auStack_50);
    iVar1 = _gleCopyMatrix(auStack_50,*(undefined4 *)(glContext + 0x4fec));
    *(uint *)(glContext + 0x50ac) = *(uint *)(glContext + 0x50ac) | *(uint *)(glContext + 0x50a8);
    *(uint *)(glContext + 0x50b0) = *(uint *)(glContext + 0x50b0) | *(uint *)(glContext + 0x50a8);
  }
  else {
    iVar1 = glContext;
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
    }
  }
  return iVar1;
}

/* _gleMultMatrixf @ 0x5656c (836 bytes) */
void _gleMultMatrixf(leftMatrix, m, product)
  float *leftMatrix;
  float *m;
  float *product;
{
  *product = leftMatrix[0xc] * m[3] +
             (leftMatrix[8] * m[2] + (*leftMatrix * *m + leftMatrix[4] * m[1]));
  product[4] = leftMatrix[0xc] * m[7] +
               (leftMatrix[8] * m[6] + (*leftMatrix * m[4] + leftMatrix[4] * m[5]));
  product[8] = leftMatrix[0xc] * m[0xb] +
               (leftMatrix[8] * m[10] + (*leftMatrix * m[8] + leftMatrix[4] * m[9]));
  product[0xc] = leftMatrix[0xc] * m[0xf] +
                 (leftMatrix[8] * m[0xe] + (*leftMatrix * m[0xc] + leftMatrix[4] * m[0xd]));
  product[1] = leftMatrix[0xd] * m[3] +
               (leftMatrix[9] * m[2] + (leftMatrix[1] * *m + leftMatrix[5] * m[1]));
  product[5] = leftMatrix[0xd] * m[7] +
               (leftMatrix[9] * m[6] + (leftMatrix[1] * m[4] + leftMatrix[5] * m[5]));
  product[9] = leftMatrix[0xd] * m[0xb] +
               (leftMatrix[9] * m[10] + (leftMatrix[1] * m[8] + leftMatrix[5] * m[9]));
  product[0xd] = leftMatrix[0xd] * m[0xf] +
                 (leftMatrix[9] * m[0xe] + (leftMatrix[1] * m[0xc] + leftMatrix[5] * m[0xd]));
  product[2] = leftMatrix[0xe] * m[3] +
               (leftMatrix[10] * m[2] + (leftMatrix[2] * *m + leftMatrix[6] * m[1]));
  product[6] = leftMatrix[0xe] * m[7] +
               (leftMatrix[10] * m[6] + (leftMatrix[2] * m[4] + leftMatrix[6] * m[5]));
  product[10] = leftMatrix[0xe] * m[0xb] +
                (leftMatrix[10] * m[10] + (leftMatrix[2] * m[8] + leftMatrix[6] * m[9]));
  product[0xe] = leftMatrix[0xe] * m[0xf] +
                 (leftMatrix[10] * m[0xe] + (leftMatrix[2] * m[0xc] + leftMatrix[6] * m[0xd]));
  product[3] = leftMatrix[0xf] * m[3] +
               (leftMatrix[0xb] * m[2] + (leftMatrix[3] * *m + leftMatrix[7] * m[1]));
  product[7] = leftMatrix[0xf] * m[7] +
               (leftMatrix[0xb] * m[6] + (leftMatrix[3] * m[4] + leftMatrix[7] * m[5]));
  product[0xb] = leftMatrix[0xf] * m[0xb] +
                 (leftMatrix[0xb] * m[10] + (leftMatrix[3] * m[8] + leftMatrix[7] * m[9]));
  product[0xf] = leftMatrix[0xf] * m[0xf] +
                 (leftMatrix[0xb] * m[0xe] + (leftMatrix[3] * m[0xc] + leftMatrix[7] * m[0xd]))
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
undefined4 _glAccum_ListExec(undefined4 glContext,undefined4 *recordedArgs,double unusedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  ((void (*)())_glAccum_Exec)(glContext,*recordedArgs,(double)GH_U2F((unsigned int)(recordedArgs[1])),forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,
                forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
  return 8;
}

/* _glAccum_Comp @ 0x568fc (92 bytes) */
undefined4 * _glAccum_Comp(undefined4 glContext,undefined4 op,float value)
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glAccum_ListExec_00110004,8);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[1] = (float)value;
    *listRecord = op;
  }
  return listRecord;
}

/* _glAccum_Exec @ 0x56958 (748 bytes) */
void _glAccum_Exec(int glContext,int op,double value,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  int remaining;
  int loopIndex;
  bool bVar1;
  char cVar2;
  undefined4 glErrorCode;
  int *srcCursor;
  int iVar5;
  int framebufferObject;
  undefined4 incomingR5;
  undefined4 incomingR6;
  undefined4 incomingR7;
  undefined4 incomingR8;
  int matrixChangeBits;
  uint uVar7;
  int *piVar8;
  double extraout_f1;
  double fparam_1_00;
  
  if ((-1 < *(short *)(glContext + 0x4a10)) || (*(int *)(*(int *)(glContext + 0x468c) + 0x44) < 1)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_00056bd4;
  }
  if (4 < op - 0x100U) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x500;
    goto LAB_00056bd4;
  }
  if ((op == 0x102) && (*(int *)(glContext + 0x4e1c) != 0x1c00)) {
    return;
  }
  matrixChangeBits = *(int *)(glContext + 0x50ac);
  fparam_1_00 = value;
  if (matrixChangeBits != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    fparam_1_00 = extraout_f1;
  }
  if (*(char *)(glContext + 0x4691) == '\0') goto LAB_00056c00;
  framebufferObject = *(int *)(glContext + 0x744c);
  piVar8 = (int *)(glContext + 0x310);
  cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
  if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
    ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,incomingR5,incomingR6,incomingR7,incomingR8,matrixChangeBits,fparam_1_00,forwardedFloatArg2,forwardedFloatArg3,
               forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
  }
  if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_00056ad8:
    uVar7 = *(uint *)(glContext + 0x31c);
  }
  else {
    loopIndex = 0;
    srcCursor = (int *)(glContext + 0x324);
    do {
      iVar5 = *srcCursor;
      srcCursor = srcCursor + 1;
      if (iVar5 != 0) {
        *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
        break;
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex < 9);
    uVar7 = *(uint *)(glContext + 0x31c);
    if ((uVar7 & 0x15555) != 0) {
      if (*(char *)(glContext + 0x2e54) != '\0') {
        _gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
      }
      if (*(char *)(glContext + 0x3094) != '\0') {
        _gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
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
    bVar1 = ((*piVar8 == 0 && *(int *)(glContext + 0x314) == 0) && uVar7 == 0) &&
            *(int *)(glContext + 800) == 0;
  }
  else {
    bVar1 = (((*piVar8 == 0 && *(int *)(glContext + 0x314) == 0) &&
             (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && uVar7 == 0) &&
            *(int *)(glContext + 800) == 0;
  }
  if (!bVar1) {
    if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
      uVar7 = (**(code **)(glContext + 0x4788))
                        (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,piVar8);
      if ((((uVar7 & 3) != (uint)*(byte *)(glContext + 0x7580)) ||
          ((uVar7 & 4) != (uint)*(byte *)(glContext + 0x7581))) ||
         ((uVar7 & 8) != (uint)(*(char *)(glContext + 0x759d) == '\0'))) {
        if ((uVar7 & 4) == 0) {
          uVar7 = uVar7 & 0xfffffffe;
          *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
        }
        _gleUpdateDispatchCodeChange(glContext,uVar7);
        if (*(char *)(glContext + 0x759d) == '\0') {
          if (*(int *)(glContext + 0x7574) != 0) {
            return;
          }
          glErrorCode = 0x506;
LAB_00056bd4:
          *(undefined4 *)(glContext + 0x7574) = glErrorCode;
          return;
        }
      }
    }
    else {
      _gleSwitchToNonRevertRenderer(glContext);
    }
    remaining = 0x13;
    do {
      *piVar8 = 0;
      piVar8 = piVar8 + 1;
      remaining = remaining + -1;
    } while (remaining != 0);
  }
LAB_00056c00:
                    
                    
  (**(int ( **)(int,int,double))(glContext + 0x4698))(*(undefined4 *)(glContext + 0x4688), op, value);
  return;
}

/* _glAccum_CompExec @ 0x56c44 (72 bytes) */
void _glAccum_CompExec(undefined4 glContext,undefined4 op,float value)
{
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((undefined4 * (*)())_glAccum_Comp)(glContext,op,value);
  ((void (*)())_glAccum_Exec)(glContext,op,value,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
  return;
}

/* _glActiveTexture_ListExec @ 0x56c8c (40 bytes) */
int _glActiveTexture_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  undefined4 *recordedArgs;
{
  _glActiveTexture_Exec(glContext,*recordedArgs);
  return 4;
}

/* _glActiveTexture_Comp @ 0x56cb4 (76 bytes) */
int _glActiveTexture_Comp(glContext, texture)
  undefined4 glContext;
  undefined4 texture;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glActiveTexture_ListExec_00110008,4);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = texture;
  }
  return listRecord;
}

/* _glActiveTexture_CompExec @ 0x56d00 (56 bytes) */
void _glActiveTexture_CompExec(glContext, texture)
  undefined4 glContext;
  undefined4 texture;
{
  ((int (*)())_glActiveTexture_Comp)(glContext,texture);
  _glActiveTexture_Exec(glContext,texture);
  return;
}

/* _glAlphaFunc_ListExec @ 0x56d38 (44 bytes) */
int _glAlphaFunc_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  undefined4 *recordedArgs;
{
  ((void (*)())_glAlphaFunc_Exec)(glContext,*recordedArgs,(double)GH_U2F((unsigned int)(recordedArgs[1])));
  return 8;
}

/* _glAlphaFunc_Comp @ 0x56d64 (92 bytes) */
undefined4 * _glAlphaFunc_Comp(undefined4 glContext,undefined4 func,float ref)
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glAlphaFunc_ListExec_0011000c,8);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[1] = (float)ref;
    *listRecord = func;
  }
  return listRecord;
}

/* _glAlphaFunc_CompExec @ 0x56dc0 (72 bytes) */
void _glAlphaFunc_CompExec(undefined4 glContext,undefined4 func,float ref)
{
  ((undefined4 * (*)())_glAlphaFunc_Comp)(glContext,func,ref);
  ((void (*)())_glAlphaFunc_Exec)(glContext,func,ref);
  return;
}

/* _glVertexArrayParameteriEXT_ListExec @ 0x56e08 (44 bytes) */
int _glVertexArrayParameteriEXT_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  undefined4 *recordedArgs;
{
  ((void (*)())_glVertexArrayParameteriEXT_Exec)(glContext,*recordedArgs,recordedArgs[1]);
  return 8;
}

/* _glVertexArrayParameteriEXT_Comp @ 0x56e34 (84 bytes) */
int _glVertexArrayParameteriEXT_Comp(glContext, pname, param)
  undefined4 glContext;
  undefined4 pname;
  undefined4 param;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           _gleAddListItem(glContext,PTR__glVertexArrayParameteriEXT_ListExec_00110010,8);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = param;
    *puVar1 = pname;
  }
  return puVar1;
}

/* _glVertexArrayParameteriEXT_Exec @ 0x56e88 (344 bytes) */
void _glVertexArrayParameteriEXT_Exec(glContext, pname, param)
  int glContext;
  int pname;
  uint param;
{
  undefined4 glErrorCode;
  int clientState;
  
  clientState = *(int *)(glContext + 0x4a60);
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_00056fc8;
  }
  if (pname != 0x851f) {
    if (pname == 0x897c) {
      *(char *)(clientState + 0x34c) = '\x01' - (param == 0);
      *(undefined4 *)(clientState + 0x350) = *(undefined4 *)(clientState + 0x350);
      *(uint *)(clientState + 0x354) = *(uint *)(clientState + 0x354) | 4;
      *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x100000;
      return;
    }
    goto LAB_00056fb8;
  }
  if (param == 0x85bd) {
    *(undefined2 *)(clientState + 0x342) = 0x85b4;
    goto LAB_00056f58;
  }
  if ((int)param < 0x85be) {
    if (param == 0x85b4) {
LAB_00056f34:
      if (*(ushort *)(clientState + 0x342) != param) {
        _gleUpdateDrawArraysFuncs(glContext);
        *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x100000;
        *(short *)(clientState + 0x342) = (short)param;
      }
LAB_00056f58:
      *(undefined4 *)(clientState + 0x350) = *(undefined4 *)(clientState + 0x350);
      *(uint *)(clientState + 0x354) = *(uint *)(clientState + 0x354) | 8;
      _gleModifyPluginVertexArray(glContext,clientState + 0x10);
      return;
    }
  }
  else if ((int)param < 0x85c0) goto LAB_00056f34;
LAB_00056fb8:
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x500;
LAB_00056fc8:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glVertexArrayParameteriEXT_CompExec @ 0x56fe0 (64 bytes) */
void _glVertexArrayParameteriEXT_CompExec(glContext, pname, param)
  undefined4 glContext;
  undefined4 pname;
  undefined4 param;
{
  ((int (*)())_glVertexArrayParameteriEXT_Comp)(glContext,pname,param);
  ((void (*)())_glVertexArrayParameteriEXT_Exec)(glContext,pname,param);
  return;
}

/* _glPushAttrib_ListExec @ 0x57020 (40 bytes) */
int _glPushAttrib_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  undefined4 *recordedArgs;
{
  _glPushAttrib_Exec(glContext,*recordedArgs);
  return 4;
}

/* _glPushAttrib_Comp @ 0x57048 (76 bytes) */
int _glPushAttrib_Comp(glContext, mask)
  undefined4 glContext;
  undefined4 mask;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glPushAttrib_ListExec_00110018,4);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = mask;
  }
  return listRecord;
}

/* _glPushAttrib_CompExec @ 0x57094 (56 bytes) */
void _glPushAttrib_CompExec(glContext, mask)
  undefined4 glContext;
  undefined4 mask;
{
  ((int (*)())_glPushAttrib_Comp)(glContext,mask);
  _glPushAttrib_Exec(glContext,mask);
  return;
}

/* _glPopAttrib_ListExec @ 0x570cc (36 bytes) */
int _glPopAttrib_ListExec(glContext)
  undefined4 glContext;
{
  _glPopAttrib_Exec(glContext);
  return 0;
}

/* _glPopAttrib_Comp @ 0x570f0 (32 bytes) */
int _glPopAttrib_Comp(glContext)
  undefined4 glContext;
{
  undefined4 listRecord;
  
  listRecord = _gleAddListItem(glContext,PTR__glPopAttrib_ListExec_00110014,0);
  return listRecord;
}

/* _glPopAttrib_CompExec @ 0x57110 (48 bytes) */
void _glPopAttrib_CompExec(glContext)
  undefined4 glContext;
{
  ((int (*)())_glPopAttrib_Comp)(glContext);
  _glPopAttrib_Exec(glContext);
  return;
}

/* _glPopClientAttrib_Exec @ 0x57140 (188 bytes) */
void _glPopClientAttrib_Exec(glContext)
  int glContext;
{
  undefined4 glErrorCode;
  int iVar2;
  int iVar3;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (0 < *(int *)(glContext + 0x5144)) {
      iVar2 = *(int *)(glContext + 0x5140);
      *(int *)(glContext + 0x5144) = *(int *)(glContext + 0x5144) + -1;
      *(int *)(glContext + 0x5140) = iVar2 + -4;
      iVar2 = *(int *)(iVar2 + -4);
      while (iVar2 != 0) {
        iVar3 = *(int *)(iVar2 + 700);
        _gleRemoveClientAttribElem(glContext,iVar2);
        iVar2 = iVar3;
      }
      _gleUpdateState(glContext);
      return;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x504;
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

/* _glPushClientAttrib_Exec @ 0x571fc (184 bytes) */
void _glPushClientAttrib_Exec(glContext, mask)
  int glContext;
  uint mask;
{
  undefined4 glErrorCode;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (*(int *)(glContext + 0x5144) < 0x10) {
      **(undefined4 **)(glContext + 0x5140) = 0;
      if ((mask & 1) != 0) {
        _gleAddClientAttribElem(glContext,1);
      }
      if ((mask & 2) != 0) {
        _gleAddClientAttribElem(glContext,2);
      }
      *(int *)(glContext + 0x5140) = *(int *)(glContext + 0x5140) + 4;
      *(int *)(glContext + 0x5144) = *(int *)(glContext + 0x5144) + 1;
      return;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x503;
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

/* _glBegin_NoopExec @ 0x572b4 (668 bytes) */
void _glBegin_NoopExec(int glContext,undefined4 mode,double fparam_1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  int remaining;
  int loopIndex;
  bool bVar1;
  char cVar2;
  undefined4 glErrorCode;
  int *srcCursor;
  int iVar5;
  int framebufferObject;
  undefined4 incomingR5;
  undefined4 incomingR6;
  undefined4 incomingR7;
  undefined4 incomingR8;
  int matrixChangeBits;
  uint uVar7;
  int *piVar8;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  
  if (*(char *)(glContext + 0x759c) == '\0') {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_00057518;
  }
  matrixChangeBits = *(int *)(glContext + 0x50ac);
  if (matrixChangeBits != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(glContext + 0x4691) == '\0') {
LAB_000574fc:
    if (*(char *)(glContext + 0x759d) != '\0') {
      ((void (*)())_glBegin_Exec)(glContext,mode,fparam_1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,
                    forwardedFloatArg8);
      return;
    }
  }
  else {
    framebufferObject = *(int *)(glContext + 0x744c);
    piVar8 = (int *)(glContext + 0x310);
    cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
    if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
      ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,incomingR5,incomingR6,incomingR7,incomingR8,matrixChangeBits,fparam_1,forwardedFloatArg2,forwardedFloatArg3,
                 forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
      fparam_1 = fparam_1;
    }
    if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_000573e8:
      uVar7 = *(uint *)(glContext + 0x31c);
    }
    else {
      loopIndex = 0;
      srcCursor = (int *)(glContext + 0x324);
      do {
        iVar5 = *srcCursor;
        srcCursor = srcCursor + 1;
        if (iVar5 != 0) {
          *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
          break;
        }
        loopIndex = loopIndex + 1;
      } while (loopIndex < 9);
      uVar7 = *(uint *)(glContext + 0x31c);
      if ((uVar7 & 0x15555) != 0) {
        if (*(char *)(glContext + 0x2e54) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
        }
        if (*(char *)(glContext + 0x3094) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
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
      bVar1 = ((*piVar8 == 0 && *(int *)(glContext + 0x314) == 0) && uVar7 == 0) &&
              *(int *)(glContext + 800) == 0;
    }
    else {
      bVar1 = (((*piVar8 == 0 && *(int *)(glContext + 0x314) == 0) &&
               (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && uVar7 == 0) &&
              *(int *)(glContext + 800) == 0;
    }
    if (bVar1) goto LAB_000574fc;
    if (*(char *)(glContext + 0x85a8) != *(char *)(glContext + 0x85a6)) {
      fparam_1 = (double)_gleSwitchToNonRevertRenderer(glContext);
LAB_000574e0:
      remaining = 0x13;
      do {
        *piVar8 = 0;
        piVar8 = piVar8 + 1;
        remaining = remaining + -1;
      } while (remaining != 0);
      goto LAB_000574fc;
    }
    uVar7 = (**(code **)(glContext + 0x4788))
                      (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,piVar8);
    if ((((uVar7 & 3) == (uint)*(byte *)(glContext + 0x7580)) &&
        ((uVar7 & 4) == (uint)*(byte *)(glContext + 0x7581))) &&
       (fparam_1 = extraout_f1_01, (uVar7 & 8) == (uint)(*(char *)(glContext + 0x759d) == '\0')))
    goto LAB_000574e0;
    if ((uVar7 & 4) == 0) {
      uVar7 = uVar7 & 0xfffffffe;
      *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
    }
    fparam_1 = (double)_gleUpdateDispatchCodeChange(glContext,uVar7);
    if (*(char *)(glContext + 0x759d) != '\0') goto LAB_000574e0;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x506;
LAB_00057518:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glBitmap_ListExec @ 0x57550 (976 bytes) */
int _glBitmap_ListExec(int glContext,uint *recordedArgs,double fparam_1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  int remaining;
  int loopIndex;
  bool bVar1;
  float fVar2;
  float fVar3;
  char cVar4;
  undefined4 glErrorCode;
  int *srcCursor;
  int iVar7;
  int framebufferObject;
  undefined4 incomingR5;
  undefined4 incomingR6;
  undefined4 incomingR7;
  undefined4 incomingR8;
  int glContextPtr4854;
  int matrixChangeBits;
  uint uVar10;
  int *piVar11;
  int iVar12;
  float *a1;
  double extraout_f1;
  
  glContextPtr4854 = *(int *)(glContext + 0x4854);
  a1 = (float *)(glContextPtr4854 + -0x200);
  iVar12 = recordedArgs[6] + 0x1c;
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return iVar12;
    }
    glErrorCode = 0x502;
    goto LAB_0005782c;
  }
  fVar2 = (float)((double)CONCAT44(0x43300000,*recordedArgs ^ 0x80000000) - DOUBLE_00108d58);
  if ((fVar2 < FLOAT_00108e50) ||
     (fVar3 = (float)((double)CONCAT44(0x43300000,recordedArgs[1] ^ 0x80000000) - DOUBLE_00108d58),
     fVar3 < FLOAT_00108e50)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return iVar12;
    }
    glErrorCode = 0x501;
    goto LAB_0005782c;
  }
  if (*(char *)(glContext + 0x2ef) == '\0') {
    return iVar12;
  }
  if (*(int *)(glContext + 0x4e1c) != 0x1c00) {
    if (*(int *)(glContext + 0x4e1c) == 0x1c01) {
      *(undefined4 *)(glContextPtr4854 + -0x200) = *(undefined4 *)(glContext + 0x2e0);
      *(undefined4 *)(glContextPtr4854 + -0x1fc) = *(undefined4 *)(glContext + 0x2e4);
      *(undefined4 *)(glContextPtr4854 + -0x1f8) = *(undefined4 *)(glContext + 0x2e8);
      _gleFeedbackBitmap(glContext,a1);
    }
    goto LAB_000578e8;
  }
  if ((!(FLOAT_00108e50 < fVar2)) || (!(FLOAT_00108e50 < fVar3))) goto LAB_000578e8;
  matrixChangeBits = *(int *)(glContext + 0x50ac);
  if (matrixChangeBits != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(glContext + 0x4691) != '\0') {
    framebufferObject = *(int *)(glContext + 0x744c);
    piVar11 = (int *)(glContext + 0x310);
    cVar4 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
    if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
      ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,incomingR5,incomingR6,incomingR7,incomingR8,matrixChangeBits,fparam_1,forwardedFloatArg2,forwardedFloatArg3,
                 forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
    }
    if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_00057730:
      uVar10 = *(uint *)(glContext + 0x31c);
    }
    else {
      loopIndex = 0;
      srcCursor = (int *)(glContext + 0x324);
      do {
        iVar7 = *srcCursor;
        srcCursor = srcCursor + 1;
        if (iVar7 != 0) {
          *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
          break;
        }
        loopIndex = loopIndex + 1;
      } while (loopIndex < 9);
      uVar10 = *(uint *)(glContext + 0x31c);
      if ((uVar10 & 0x15555) != 0) {
        if (*(char *)(glContext + 0x2e54) != '\0') {
          _gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
        }
        if (*(char *)(glContext + 0x3094) != '\0') {
          _gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
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
      bVar1 = ((*piVar11 == 0 && *(int *)(glContext + 0x314) == 0) && uVar10 == 0) &&
              *(int *)(glContext + 800) == 0;
    }
    else {
      bVar1 = (((*piVar11 == 0 && *(int *)(glContext + 0x314) == 0) &&
               (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && uVar10 == 0) &&
              *(int *)(glContext + 800) == 0;
    }
    if (!bVar1) {
      if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
        uVar10 = (**(code **)(glContext + 0x4788))
                           (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,piVar11);
        if ((((uVar10 & 3) != (uint)*(byte *)(glContext + 0x7580)) ||
            ((uVar10 & 4) != (uint)*(byte *)(glContext + 0x7581))) ||
           ((uVar10 & 8) != (uint)(*(char *)(glContext + 0x759d) == '\0'))) {
          if ((uVar10 & 4) == 0) {
            uVar10 = uVar10 & 0xfffffffe;
            *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
          }
          _gleUpdateDispatchCodeChange(glContext,uVar10);
          if (*(char *)(glContext + 0x759d) == '\0') {
            if (*(int *)(glContext + 0x7574) != 0) {
              return iVar12;
            }
            glErrorCode = 0x506;
LAB_0005782c:
            *(undefined4 *)(glContext + 0x7574) = glErrorCode;
            return iVar12;
          }
        }
      }
      else {
        _gleSwitchToNonRevertRenderer(glContext);
      }
      remaining = 0x13;
      do {
        *piVar11 = 0;
        piVar11 = piVar11 + 1;
        remaining = remaining + -1;
      } while (remaining != 0);
    }
  }
  *a1 = *(float *)(glContext + 0x4a44) * *(float *)(glContext + 0x2e0) + *(float *)(glContext + 0x4a48);
  *(float *)(glContextPtr4854 + -0x1fc) =
       *(float *)(glContext + 0x4a4c) * *(float *)(glContext + 0x2e4) + *(float *)(glContext + 0x4a50);
  *(float *)(glContextPtr4854 + -0x1f8) = *(float *)(glContext + 0x4a54) * *(float *)(glContext + 0x2e8);
  (**(code **)(glContext + 0x46ac))
            (*(undefined4 *)(glContext + 0x4688),a1,*recordedArgs,recordedArgs[1],incomingR7,incomingR8,recordedArgs + 7,1,
             (double)GH_U2F((unsigned int)(recordedArgs[2])),(double)GH_U2F((unsigned int)(recordedArgs[3])));
LAB_000578e8:
  *(float *)(glContext + 0x2e0) = *(float *)(glContext + 0x2e0) + GH_U2F((unsigned int)(recordedArgs[4]));
  *(float *)(glContext + 0x2e4) = *(float *)(glContext + 0x2e4) + GH_U2F((unsigned int)(recordedArgs[5]));
  return iVar12;
}

/* _glBitmap_Comp @ 0x57920 (444 bytes) */
void _glBitmap_Comp(int glContext,int width,int height,undefined4 xorigShadow,undefined4 yorigShadow,undefined4 xmoveShadow,undefined4 ymoveShadow,int bitmap,float xorig,float yorig,float xmove,float ymove)
{
  uint uVar1;
  int iVar2;
  int *listRecord;
  int iVar4;
  int pixelUnpackBuffer;
  
  pixelUnpackBuffer = *(int *)(glContext + 0x4a6c);
  iVar4 = (width + 7 >> 3) * height;
  uVar1 = iVar4 + 3U & 0xfffffffc;
  if (pixelUnpackBuffer != 0) {
    iVar2 = _gleOffsetLimitImage(glContext + 0x31cc,width,height,0,0x1a00,bitmap);
    if (*(int *)(pixelUnpackBuffer + 0x38) < iVar2) {
      if (*(int *)(glContext + 0x7574) == 0) {
        *(undefined4 *)(glContext + 0x7574) = 0x502;
      }
      goto LAB_00057ad0;
    }
    if (*(int *)(pixelUnpackBuffer + 0x40) != 0) {
      _gleSynchronizePluginBuffer(glContext,pixelUnpackBuffer + 0x10);
    }
    bitmap = bitmap + *(int *)(pixelUnpackBuffer + 0x30);
  }
  listRecord = (int *)_gleAddListItem(glContext,PTR__glBitmap_ListExec_00110020,uVar1 + 0x1c);
  if (listRecord != (int *)0x0) {
    listRecord[2] = (int)GH_F2U((float)xorig);
    listRecord[3] = (int)GH_F2U((float)yorig);
    listRecord[4] = (int)GH_F2U((float)xmove);
    listRecord[5] = (int)GH_F2U((float)ymove);
    listRecord[6] = uVar1;
    *listRecord = width;
    listRecord[1] = height;
    if (iVar4 != 0) {
      if ((((*(char *)(glContext + 0x31e5) == '\0') && (*(int *)(glContext + 0x31cc) == 0)) &&
          (*(int *)(glContext + 0x31d4) == 0)) &&
         ((*(int *)(glContext + 0x31e0) == 1 && ((*(uint *)(glContext + 0x31d8) & 7) == 0)))) {
        _gleCopy(bitmap + ((int)*(uint *)(glContext + 0x31d8) >> 3),listRecord + 7,iVar4,1,0,0);
        return;
      }
      _gleFillImage(glContext,width,height,1,0x1900,0x1a00,bitmap,listRecord + 7);
      return;
    }
  }
LAB_00057ad0:
  return;
}

/* _glBitmap_CompExec @ 0x57adc (120 bytes) */
void _glBitmap_CompExec(undefined4 glContext,undefined4 width,undefined4 height,undefined4 xorigShadow,undefined4 yorigShadow,undefined4 xmoveShadow,undefined4 ymoveShadow,undefined4 bitmap,float xorig,float yorig,float xmove,float ymove)
{
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((void (*)())_glBitmap_Comp)(glContext,width,height,xorigShadow,yorigShadow,xmoveShadow,ymoveShadow,bitmap,xorig,yorig,
                 xmove,ymove);
  ((void (*)())_glBitmap_Exec)(glContext,width,height,xorigShadow,yorigShadow,xmoveShadow,ymoveShadow,bitmap,xorig,yorig,
                 xmove,ymove,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
  return;
}

/* _glBitmap_NoopExec @ 0x57b54 (696 bytes) */
void _glBitmap_NoopExec(int glContext,undefined4 width,undefined4 height,undefined4 xorigShadow,undefined4 yorigShadow,undefined4 xmoveShadow,undefined4 ymoveShadow,undefined4 bitmap,double xorig,double yorig,float xmove,float ymove,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  int remaining;
  int loopIndex;
  bool bVar1;
  char cVar2;
  int iVar3;
  int *srcCursor;
  int framebufferObject;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  double extraout_f1;
  double fparam_1_00;
  double fparam_2_00;
  double fparam_3_00;
  double fparam_4_00;
  
  uVar7 = *(uint *)(glContext + 0x50ac);
  uVar6 = height;
  fparam_1_00 = xorig;
  fparam_2_00 = yorig;
  fparam_3_00 = xmove;
  fparam_4_00 = ymove;
  if (uVar7 != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    fparam_1_00 = extraout_f1;
  }
  if (*(char *)(glContext + 0x4691) != '\0') {
    framebufferObject = *(int *)(glContext + 0x744c);
    piVar9 = (int *)(glContext + 0x310);
    cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
    if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
      ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,uVar6,xorigShadow,yorigShadow,xmoveShadow,uVar7,fparam_1_00,fparam_2_00,
                 fparam_3_00,fparam_4_00,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
    }
    if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_00057c84:
      uVar8 = *(uint *)(glContext + 0x31c);
    }
    else {
      loopIndex = 0;
      srcCursor = (int *)(glContext + 0x324);
      do {
        iVar3 = *srcCursor;
        srcCursor = srcCursor + 1;
        if (iVar3 != 0) {
          *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
          break;
        }
        loopIndex = loopIndex + 1;
      } while (loopIndex < 9);
      uVar8 = *(uint *)(glContext + 0x31c);
      if ((uVar8 & 0x15555) != 0) {
        if (*(char *)(glContext + 0x2e54) != '\0') {
          _gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
        }
        if (*(char *)(glContext + 0x3094) != '\0') {
          _gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
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
    uVar7 = *(uint *)(glContext + 800);
    if (bVar1) {
      bVar1 = ((*piVar9 == 0 && *(int *)(glContext + 0x314) == 0) && uVar8 == 0) && uVar7 == 0;
    }
    else {
      bVar1 = (((*piVar9 == 0 && *(int *)(glContext + 0x314) == 0) &&
               (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && uVar8 == 0) && uVar7 == 0;
    }
    if (!bVar1) {
      uVar7 = (uint)*(byte *)(glContext + 0x85a6);
      if (*(byte *)(glContext + 0x85a8) == uVar7) {
        uVar8 = (**(code **)(glContext + 0x4788))
                          (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,piVar9);
        uVar7 = uVar8 & 4;
        if ((((uVar8 & 3) != (uint)*(byte *)(glContext + 0x7580)) ||
            (uVar7 != *(byte *)(glContext + 0x7581))) ||
           ((uVar8 & 8) != (uint)(*(char *)(glContext + 0x759d) == '\0'))) {
          if (uVar7 == 0) {
            uVar8 = uVar8 & 0xfffffffe;
            *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
          }
          _gleUpdateDispatchCodeChange(glContext,uVar8);
          if (*(char *)(glContext + 0x759d) == '\0') goto LAB_00057da4;
        }
      }
      else {
        _gleSwitchToNonRevertRenderer(glContext);
      }
      remaining = 0x13;
      do {
        *piVar9 = 0;
        piVar9 = piVar9 + 1;
        remaining = remaining + -1;
      } while (remaining != 0);
    }
  }
  if (*(char *)(glContext + 0x759d) != '\0') {
    ((void (*)())_glBitmap_Exec)(glContext,width,height,xorigShadow,yorigShadow,xmoveShadow,uVar7,bitmap,xorig,yorig,
                   xmove,ymove,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
    return;
  }
LAB_00057da4:
  if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x506;
  }
  return;
}

/* _glBlendFunc_ListExec @ 0x57e0c (44 bytes) */
int _glBlendFunc_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  undefined4 *recordedArgs;
{
  _glBlendFunc_Exec(glContext,*recordedArgs,recordedArgs[1]);
  return 8;
}

/* _glBlendFunc_Comp @ 0x57e38 (84 bytes) */
int _glBlendFunc_Comp(glContext, sfactor, dfactor)
  undefined4 glContext;
  undefined4 sfactor;
  undefined4 dfactor;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glBlendFunc_ListExec_00110034,8);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[1] = dfactor;
    *listRecord = sfactor;
  }
  return listRecord;
}

/* _glBlendFunc_CompExec @ 0x57e8c (64 bytes) */
void _glBlendFunc_CompExec(glContext, sfactor, dfactor)
  undefined4 glContext;
  undefined4 sfactor;
  undefined4 dfactor;
{
  ((int (*)())_glBlendFunc_Comp)(glContext,sfactor,dfactor);
  _glBlendFunc_Exec(glContext,sfactor,dfactor);
  return;
}

/* _glBlendColor_ListExec @ 0x57ecc (52 bytes) */
int _glBlendColor_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  float *recordedArgs;
{
  ((void (*)())_glBlendColor_Exec)(glContext,(double)*recordedArgs,(double)recordedArgs[1],(double)recordedArgs[2],
                     (double)recordedArgs[3]);
  return 0x10;
}

/* _glBlendColor_Comp @ 0x57f00 (92 bytes) */
void _glBlendColor_Comp(undefined4 glContext,float red,float green,float blue,float alpha)
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glBlendColor_ListExec_00110030,0x10);
  if (listRecord != (float *)0x0) {
    listRecord[3] = (float)alpha;
    *listRecord = (float)red;
    listRecord[1] = (float)green;
    listRecord[2] = (float)blue;
  }
  return;
}

/* _glBlendColor_Exec @ 0x57f5c (228 bytes) */
void _glBlendColor_Exec(int glContext,float red,float green,float blue,float alpha)
{
  float floatZero;
  float floatOne;
  float dVar3;
  float dVar4;
  
  floatOne = FLOAT_00108e54;
  floatZero = FLOAT_00108e50;
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    *(undefined4 *)(glContext + 0x7574) = 0x502;
    return;
  }
  dVar3 = (double)FLOAT_00108e50;
  dVar4 = (double)FLOAT_00108e54;
  *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 4;
  if (red < (double)dVar3) {
    *(float *)(glContext + 0x30d0) = floatZero;
  }
  else if ((double)dVar4 < red) {
    *(float *)(glContext + 0x30d0) = floatOne;
  }
  else {
    *(float *)(glContext + 0x30d0) = (float)red;
  }
  if (green < (double)dVar3) {
    *(float *)(glContext + 0x30d4) = floatZero;
  }
  else if ((double)dVar4 < green) {
    *(float *)(glContext + 0x30d4) = floatOne;
  }
  else {
    *(float *)(glContext + 0x30d4) = (float)green;
  }
  if (blue < (double)dVar3) {
    *(float *)(glContext + 0x30d8) = floatZero;
  }
  else if ((double)dVar4 < blue) {
    *(float *)(glContext + 0x30d8) = floatOne;
  }
  else {
    *(float *)(glContext + 0x30d8) = (float)blue;
  }
  if (alpha < (double)dVar3) {
    *(float *)(glContext + 0x30dc) = floatZero;
    return;
  }
  if ((double)dVar4 < alpha) {
    *(float *)(glContext + 0x30dc) = floatOne;
    return;
  }
  *(float *)(glContext + 0x30dc) = (float)alpha;
  return;
}

/* _glBlendColor_CompExec @ 0x58040 (96 bytes) */
void _glBlendColor_CompExec(undefined4 glContext,float red,float green,float blue,float alpha)
{
  ((void (*)())_glBlendColor_Comp)(glContext,red,green,blue,alpha);
  ((void (*)())_glBlendColor_Exec)(glContext,red,green,blue,alpha);
  return;
}

/* _glBlendEquation_ListExec @ 0x580a0 (40 bytes) */
int _glBlendEquation_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  undefined4 *recordedArgs;
{
  ((void (*)())_glBlendEquation_Exec)(glContext,*recordedArgs);
  return 4;
}

/* _glBlendEquation_Comp @ 0x580c8 (76 bytes) */
int _glBlendEquation_Comp(glContext, mode)
  undefined4 glContext;
  undefined4 mode;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glBlendEquation_ListExec_0011002c,4);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = mode;
  }
  return listRecord;
}

/* _glBlendEquation_Exec @ 0x58114 (128 bytes) */
void _glBlendEquation_Exec(glContext, mode)
  int glContext;
  uint mode;
{
  bool bVar1;
  undefined4 glErrorCode;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (mode < 0x800c) {
      if (0x8009 < mode) goto LAB_0005817c;
      bVar1 = 2 < mode - 0x8006;
    }
    else {
      bVar1 = 1 < mode - 0x877d;
    }
    if (!bVar1) {
LAB_0005817c:
      *(short *)(glContext + 0x30e2) = (short)mode;
      *(short *)(glContext + 0x30e0) = (short)mode;
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 2;
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

/* _glBlendEquation_CompExec @ 0x58194 (56 bytes) */
void _glBlendEquation_CompExec(glContext, mode)
  undefined4 glContext;
  undefined4 mode;
{
  ((int (*)())_glBlendEquation_Comp)(glContext,mode);
  ((void (*)())_glBlendEquation_Exec)(glContext,mode);
  return;
}

/* _glBlendFuncSeparate_ListExec @ 0x581cc (56 bytes) */
int _glBlendFuncSeparate_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  undefined4 *recordedArgs;
{
  ((void (*)())_glBlendFuncSeparate_Exec)(glContext,*recordedArgs,recordedArgs[1],recordedArgs[2],recordedArgs[3]);
  return 0x10;
}

/* _glBlendFuncSeparate_Comp @ 0x58204 (100 bytes) */
int _glBlendFuncSeparate_Comp(glContext, sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha)
  undefined4 glContext;
  undefined4 sfactorRGB;
  undefined4 dfactorRGB;
  undefined4 sfactorAlpha;
  undefined4 dfactorAlpha;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glBlendFuncSeparate_ListExec_00110028,0x10);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[3] = dfactorAlpha;
    *listRecord = sfactorRGB;
    listRecord[1] = dfactorRGB;
    listRecord[2] = sfactorAlpha;
  }
  return listRecord;
}

/* _glBlendFuncSeparate_Exec @ 0x58268 (248 bytes) */
void _glBlendFuncSeparate_Exec(glContext, sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha)
  int glContext;
  uint sfactorRGB;
  uint dfactorRGB;
  uint sfactorAlpha;
  uint dfactorAlpha;
{
  bool bVar1;
  undefined4 glErrorCode;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_000582c0;
  }
  if (dfactorRGB < 0x308) {
    if (dfactorRGB < 0x300) {
      bVar1 = 1 < dfactorRGB;
      goto LAB_000582ac;
    }
LAB_000582c8:
    if (sfactorRGB < 0x309) {
      if (sfactorRGB < 0x300) {
        bVar1 = 1 < sfactorRGB;
        goto LAB_000582ec;
      }
    }
    else {
      bVar1 = 3 < sfactorRGB - 0x8001;
LAB_000582ec:
      if (bVar1) goto LAB_000582b0;
    }
    if (dfactorAlpha < 0x308) {
      if (dfactorAlpha < 0x300) {
        bVar1 = 1 < dfactorAlpha;
        goto LAB_00058314;
      }
    }
    else {
      bVar1 = 3 < dfactorAlpha - 0x8001;
LAB_00058314:
      if (bVar1) goto LAB_000582b0;
    }
    if (sfactorAlpha < 0x309) {
      if (0x2ff < sfactorAlpha) goto LAB_00058340;
      bVar1 = 1 < sfactorAlpha;
    }
    else {
      bVar1 = 3 < sfactorAlpha - 0x8001;
    }
    if (!bVar1) {
LAB_00058340:
      *(short *)(glContext + 0x30ca) = (short)dfactorRGB;
      *(short *)(glContext + 0x30c8) = (short)sfactorRGB;
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 2;
      *(short *)(glContext + 0x30ce) = (short)dfactorAlpha;
      *(short *)(glContext + 0x30cc) = (short)sfactorAlpha;
      return;
    }
  }
  else {
    bVar1 = 3 < dfactorRGB - 0x8001;
LAB_000582ac:
    if (!bVar1) goto LAB_000582c8;
  }
LAB_000582b0:
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x500;
LAB_000582c0:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glBlendFuncSeparate_CompExec @ 0x58360 (80 bytes) */
void _glBlendFuncSeparate_CompExec(glContext, sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha)
  undefined4 glContext;
  undefined4 sfactorRGB;
  undefined4 dfactorRGB;
  undefined4 sfactorAlpha;
  undefined4 dfactorAlpha;
{
  ((int (*)())_glBlendFuncSeparate_Comp)(glContext,sfactorRGB,dfactorRGB,sfactorAlpha,dfactorAlpha);
  ((void (*)())_glBlendFuncSeparate_Exec)(glContext,sfactorRGB,dfactorRGB,sfactorAlpha,dfactorAlpha);
  return;
}

/* _glBlendEquationSeparateEXT_ListExec @ 0x583b0 (44 bytes) */
int _glBlendEquationSeparateEXT_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  undefined4 *recordedArgs;
{
  ((void (*)())_glBlendEquationSeparateEXT_Exec)(glContext,*recordedArgs,recordedArgs[1]);
  return 8;
}

/* _glBlendEquationSeparateEXT_Comp @ 0x583dc (84 bytes) */
int _glBlendEquationSeparateEXT_Comp(glContext, modeRGB, modeAlpha)
  undefined4 glContext;
  undefined4 modeRGB;
  undefined4 modeAlpha;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           _gleAddListItem(glContext,PTR__glBlendEquationSeparateEXT_ListExec_00110024,8);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = modeAlpha;
    *puVar1 = modeRGB;
  }
  return puVar1;
}

/* _glBlendEquationSeparateEXT_Exec @ 0x58430 (176 bytes) */
void _glBlendEquationSeparateEXT_Exec(glContext, modeRGB, modeAlpha)
  int glContext;
  uint modeRGB;
  uint modeAlpha;
{
  bool bVar1;
  undefined4 glErrorCode;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_00058490;
  }
  if (modeRGB < 0x800c) {
    if (modeRGB < 0x800a) {
      bVar1 = 2 < modeRGB - 0x8006;
      goto LAB_0005847c;
    }
LAB_00058498:
    if (modeAlpha < 0x800c) {
      if (0x8009 < modeAlpha) goto LAB_000584c8;
      bVar1 = 2 < modeAlpha - 0x8006;
    }
    else {
      bVar1 = 1 < modeAlpha - 0x877d;
    }
    if (!bVar1) {
LAB_000584c8:
      *(short *)(glContext + 0x30e0) = (short)modeRGB;
      *(short *)(glContext + 0x30e2) = (short)modeAlpha;
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 2;
      return;
    }
  }
  else {
    bVar1 = 1 < modeRGB - 0x877d;
LAB_0005847c:
    if (!bVar1) goto LAB_00058498;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x500;
LAB_00058490:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glBlendEquationSeparateEXT_CompExec @ 0x584e0 (64 bytes) */
void _glBlendEquationSeparateEXT_CompExec(glContext, modeRGB, modeAlpha)
  undefined4 glContext;
  undefined4 modeRGB;
  undefined4 modeAlpha;
{
  ((int (*)())_glBlendEquationSeparateEXT_Comp)(glContext,modeRGB,modeAlpha);
  ((void (*)())_glBlendEquationSeparateEXT_Exec)(glContext,modeRGB,modeAlpha);
  return;
}

