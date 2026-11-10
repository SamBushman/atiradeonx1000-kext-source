#include "decls.h"

/* _gliInitializeLibrary @ 0x13c4 (48 bytes) */
void _gliInitializeLibrary(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  DAT_00111e28 = param_5;
  _gle_io_data = param_3;
  DAT_00111e1c = param_1;
  DAT_00111e20 = param_2;
  DAT_00111e24 = param_4;
  return;
}

/* _gliGetVersion @ 0x13f4 (448 bytes) */
int _gliGetVersion(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 *param_2;
  undefined4 *param_3;
{
  mach_port_t host;
  kern_return_t kVar1;
  int iVar2;
  integer_t aiStack_70 [3];
  int local_64;
  int local_60;
  mach_msg_type_number_t local_40 [2];
  int local_38 [3];
  size_t local_2c [5];
  
  ((int (*)())_glepPluginConnectAll)();
  local_40[0] = 0xc;
  host = _mach_host_self();
  kVar1 = _host_info(host,1,aiStack_70,local_40);
  _mach_port_deallocate(*(ipc_space_t *)PTR_00112034,host);
  iVar2 = 0;
  if (kVar1 != 0) {
    return 0;
  }
  if (local_64 != 0x12) goto LAB_00001554;
  local_38[0] = 6;
  local_2c[0] = 4;
  local_38[1] = 0xd;
  iVar2 = _sysctl(local_38,2,local_38 + 2,local_2c,(void *)0x0,0);
  if (local_38[2] != 0) {
    _gle_processor = _gle_processor | 0x30;
  }
  if ((*(uint *)PTR_00113e0c & 0x10) != 0) {
    _gle_processor = _gle_processor | 0x40;
  }
  if (local_60 < 9) {
    if (2 < local_60) goto LAB_00001524;
    if (local_60 < 0) goto LAB_00001544;
  }
  else {
    if ((0xb < local_60) && (local_60 != 100)) {
LAB_00001544:
      _gle_processor = _gle_processor | 0xb;
      goto LAB_00001554;
    }
    _gle_processor = _gle_processor | 8;
LAB_00001524:
    _gle_processor = _gle_processor | 1;
  }
  _gle_processor = _gle_processor | 2;
LAB_00001554:
  ((void (*)())_glePreInitGlobals)(iVar2);
  ((int (*)())_glePreInitTOC)();
  ((void (*)())_glePreInitNormalize)();
  ((void (*)())_glePreInitProjectionTransformFunc)();
  ((void (*)())_glePreInitModelviewTransformFunc)();
  ((void (*)())_glePreInitNormalTransformFunc)();
  ((void (*)())_glePreInitVertexSubmitFunc)();
  iVar2 = ((int (*)())_glepGetPlugins)();
  if (iVar2 != 0) {
    *param_1 = 2;
    *param_2 = 3;
    *param_3 = 0x20000;
    ((void (*)())_gleOptimizeDisplayListCreateHashTable)(0);
  }
  return iVar2 != 0;
}

/* _glepPluginConnectAll @ 0x15b4 (124 bytes) */
int _glepPluginConnectAll()
{
  int *in_r3;
  int *piVar1;
  
  if (_glep_plugin_head == 0) {
    in_r3 = (int *)((int (*)())_glepLoadRenderers)();
    piVar1 = (int *)_glep_plugin_head;
    while (piVar1 != (int *)0x0) {
      in_r3 = (int *)((int (*)())_glepPluginConnect)(piVar1);
      if (in_r3 == (int *)0x0) {
        in_r3 = (int *)_glepDeletePlugin(piVar1);
        piVar1 = in_r3;
      }
      else {
        piVar1 = (int *)*piVar1;
      }
    }
  }
  return in_r3;
}

/* _glepLoadRenderers @ 0x1630 (856 bytes) */
int _glepLoadRenderers()
{
  bool bVar1;
  bool bVar2;
  int iVar3;
  undefined *puVar4;
  undefined *puVar5;
  uint uVar6;
  undefined4 in_r3;
  int iVar7;
  char *pcVar8;
  int iVar9;
  undefined4 extraout_r3;
  int iVar10;
  int iVar11;
  undefined4 extraout_r3_00;
  char *pcVar12;
  uint uVar13;
  uint uVar14;
  int *piVar15;
  int iVar16;
  undefined1 auStack_147 [7];
  char acStack_140 [256];
  int local_40 [4];
  
  puVar5 = PTR__gle_io_data_00112434;
  puVar4 = PTR_00112430;
  uVar13 = 0;
  uVar14 = 0;
  if (*(int *)PTR__gle_io_data_00112434 != 0) {
    do {
      iVar7 = *(int *)(uVar14 * 4 + *(int *)(puVar5 + 4));
      in_r3 = 0;
      if (iVar7 != 0) {
        iVar7 = _IORegistryEntryCreateCFProperty(iVar7,&DAT_00113e50,*(undefined4 *)puVar4,0);
        in_r3 = 0;
        if (iVar7 != 0) {
          pcVar12 = (char *)0x0;
          pcVar8 = (char *)_CFStringGetCStringPtr(iVar7,0);
          bVar1 = pcVar8 == (char *)0x0;
          if (bVar1) {
            iVar9 = _CFStringGetLength(iVar7);
            pcVar12 = (char *)_malloc(iVar9 + 1);
            bVar2 = pcVar12 == (char *)0x0;
            if ((!bVar2) && (iVar9 = _CFStringGetCString(iVar7,pcVar12,iVar9 + 1,0), iVar9 != 0)) {
              pcVar8 = pcVar12;
              bVar1 = bVar2;
            }
          }
          else {
            bVar2 = true;
          }
          if (!bVar1) {
            _strncpy(acStack_140,"/System/Library/Extensions/",0x100);
            _strncat(acStack_140,pcVar8,0x100);
            _strcat(acStack_140,".bundle/Contents/MacOS/");
            _strncat(acStack_140,pcVar8,0x100);
            for (piVar15 = (int *)_glep_plugin_head; piVar15 != (int *)0x0;
                piVar15 = (int *)*piVar15) {
              iVar9 = _strcmp(acStack_140,piVar15 + 1);
              if (iVar9 == 0) {
                uVar6 = piVar15[0x44] | 1 << (uVar14 & 0x3f);
                goto LAB_000017c4;
              }
            }
            piVar15 = (int *)((int (*)())_glepAddPlugin)();
            if (piVar15 != (int *)0x0) {
              _strcpy((int)piVar15 + 4,acStack_140);
              uVar6 = 1 << (uVar14 & 0x3f);
LAB_000017c4:
              *(uint *)((int)piVar15 + 0x110) = uVar6;
            }
          }
          if (!bVar2) {
            _free(pcVar12);
          }
          _CFRelease(iVar7);
          in_r3 = extraout_r3;
        }
      }
      uVar6 = uVar14 & 0x3f;
      uVar14 = uVar14 + 1;
      uVar13 = uVar13 | 1 << uVar6;
    } while (uVar14 < *(uint *)puVar5);
  }
  puVar5 = PTR__gle_io_data_00112434;
  puVar4 = PTR__gleBindSurface_00111e0c;
  if ((*(int *)(PTR__gle_io_data_00112434 + 0xc) == 0) ||
     (*(int *)(PTR__gle_io_data_00112434 + 0x10) == 0)) {
    *(undefined **)(PTR__gle_io_data_00112434 + 0xc) = PTR__gleDoNonSimpleFlush_00111e10;
    *(undefined **)(puVar5 + 0x10) = puVar4;
  }
  else {
    pcVar12 = (char *)_getenv("GL_RESOURCES");
    pcVar8 = "/System/Library/Frameworks/OpenGL.framework/Versions/A/Resources/";
    if (pcVar12 != (char *)0x0) {
      pcVar8 = pcVar12;
    }
    iVar7 = _scandir(pcVar8,local_40,0,0);
    in_r3 = 0;
    if (iVar7 != 0) {
      iVar9 = 0;
      if (0 < iVar7) {
        do {
          iVar11 = local_40[0];
          iVar3 = iVar9 * 4;
          iVar16 = *(int *)(iVar3 + local_40[0]) + 8;
          iVar10 = _memcmp(iVar16,"GLDriver",8);
          if ((iVar10 == 0) || (iVar10 = _memcmp(iVar16,"GLRendererFloat",0xf), iVar10 == 0)) {
            iVar11 = ((int (*)())_glepAddPlugin)();
            if (iVar11 == 0) {
              return 0;
            }
            _strncpy(acStack_140,pcVar8,0x100);
            _strncat(acStack_140,(char *)(*(int *)(iVar3 + local_40[0]) + 8),0x100);
            _strcat(acStack_140,"/");
            _strncat(acStack_140,(char *)(*(int *)(iVar3 + local_40[0]) + 8),0x100);
            iVar10 = _strlen(acStack_140);
            auStack_147[iVar10] = 0;
            _strncpy((char *)(iVar11 + 4),acStack_140,0x100);
            *(uint *)(iVar11 + 0x110) = uVar13;
            iVar11 = local_40[0];
          }
          iVar9 = iVar9 + 1;
          _free(*(undefined4 *)(iVar3 + iVar11));
        } while (iVar9 < iVar7);
      }
      _free(local_40[0]);
      in_r3 = extraout_r3_00;
    }
  }
  return in_r3;
}

/* dyld_stub_binding_helper @ 0x1988 (48 bytes) */
void dyld_stub_binding_helper()
{
                    
                    
  (*dyld_lazy_symbol_binding_entry_point)();
  return;
}

/* _glepAddPlugin @ 0x19b8 (136 bytes) */
int _glepAddPlugin()
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar1 = &_glep_plugin_head;
  for (puVar2 = _glep_plugin_head; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {
    puVar1 = puVar2;
  }
  puVar3 = (undefined4 *)_malloc(0x208);
  puVar2 = (undefined4 *)0x0;
  if (puVar3 != (undefined4 *)0x0) {
    *puVar1 = puVar3;
    puVar3[0x44] = 0;
    *puVar3 = 0;
    *(undefined1 *)(puVar3 + 1) = 0;
    puVar3[0x41] = 0;
    puVar3[0x42] = 0;
    puVar3[0x43] = 0;
    puVar2 = puVar3;
  }
  return puVar2;
}

/* _glepPluginConnect @ 0x1a40 (280 bytes) */
int _glepPluginConnect(param_1)
  int param_1;
{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  int *piVar4;
  int local_30 [7];
  
  if (*(int *)(param_1 + 0x108) == 0) {
    iVar1 = _NSCreateObjectFileImageFromFile(param_1 + 4,local_30);
    if ((iVar1 == 1) && (local_30[0] != 0)) {
      *(int *)(param_1 + 0x108) = local_30[0];
      iVar1 = _NSLinkModule(local_30[0],param_1 + 4,2);
      *(int *)(param_1 + 0x10c) = iVar1;
      if (iVar1 != 0) {
        iVar1 = ((int (*)())_glepValidatePlugin)(param_1);
        if (iVar1 == 0) {
          return 0;
        }
        piVar4 = (int *)(param_1 + 0x114);
        pcVar3 = _glep_gld_names;
        do {
          iVar1 = _NSLookupSymbolInModule(*(undefined4 *)(param_1 + 0x10c),pcVar3);
          if (iVar1 == 0) {
LAB_00001b38:
            _glepPluginDisconnect(param_1);
            goto LAB_00001b40;
          }
          iVar1 = _NSAddressOfSymbol(iVar1);
          *piVar4 = iVar1;
          piVar4 = piVar4 + 1;
          if (iVar1 == 0) goto LAB_00001b38;
          pcVar3 = pcVar3 + 0x20;
        } while ((int)piVar4 < param_1 + 0x208);
        goto LAB_00001b30;
      }
      *(undefined4 *)(param_1 + 0x104) = 0xffff;
      _NSDestroyObjectFileImage(*(undefined4 *)(param_1 + 0x108));
      *(undefined4 *)(param_1 + 0x108) = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0x104) = 0xffff;
    }
LAB_00001b40:
    uVar2 = 0;
  }
  else {
LAB_00001b30:
    uVar2 = 1;
  }
  return uVar2;
}

/* _glepValidatePlugin @ 0x1b58 (368 bytes) */
int _glepValidatePlugin(param_1)
  int param_1;
{
  bool bVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  code *pcVar5;
  int local_20;
  int local_1c;
  int local_18;
  uint local_14 [3];
  
  if (((*(int *)(param_1 + 0x104) != 0xffff) &&
      (iVar4 = _NSLookupSymbolInModule(*(undefined4 *)(param_1 + 0x10c),"_gldInitializeLibrary"),
      iVar4 != 0)) && (pcVar5 = (code *)_NSAddressOfSymbol(iVar4), pcVar5 != (code *)0x0)) {
    (*pcVar5)(*(undefined4 *)(PTR__gle_io_data_00112434 + 4),
              *(undefined4 *)(PTR__gle_io_data_00112434 + 8),*(undefined4 *)(param_1 + 0x110),
              *(undefined4 *)(PTR__gle_io_data_00112434 + 0xc),
              *(undefined4 *)(PTR__gle_io_data_00112434 + 0x10));
    iVar4 = _NSLookupSymbolInModule(*(undefined4 *)(param_1 + 0x10c),_glep_gld_names);
    if (((iVar4 != 0) && (pcVar5 = (code *)_NSAddressOfSymbol(iVar4), pcVar5 != (code *)0x0)) &&
       (iVar4 = (*pcVar5)(&local_20,&local_1c,&local_18,local_14), iVar4 != 0)) {
      if (*(int *)(param_1 + 0x104) == 0) {
        local_14[0] = local_14[0] & 0xff00;
        if (((local_20 != 2) || (local_1c != 4)) || (local_18 != 0xb)) goto LAB_00001c9c;
        bVar1 = _glep_plugin_head == (int *)0x0;
        if (!bVar1) {
          uVar2 = _glep_plugin_head[0x41];
          piVar3 = _glep_plugin_head;
          while (local_14[0] != uVar2) {
            piVar3 = (int *)*piVar3;
            if (piVar3 == (int *)0x0) goto LAB_00001c90;
            bVar1 = false;
            uVar2 = piVar3[0x41];
          }
          if (!bVar1) goto LAB_00001c9c;
        }
LAB_00001c90:
        *(uint *)(param_1 + 0x104) = local_14[0];
      }
      return 1;
    }
  }
LAB_00001c9c:
  _glepPluginDisconnect(param_1);
  *(undefined4 *)(param_1 + 0x104) = 0xffff;
  return 0;
}

/* _glePreInitGlobals @ 0x1cc8 (212 bytes) */
void _glePreInitGlobals()
{
  double dVar1;
  float fVar2;
  undefined *puVar3;
  uint uVar4;
  float *pfVar5;
  undefined1 *puVar6;
  uint uVar7;
  int iVar8;
  
  puVar3 = PTR__gle_globals_struct_00112070;
  fVar2 = FLOAT_00108e78;
  dVar1 = DOUBLE_00108d58;
  uVar7 = 0;
  iVar8 = 0x100;
  pfVar5 = (float *)PTR__gle_globals_struct_00112070;
  do {
    uVar4 = uVar7 ^ 0x80000000;
    uVar7 = uVar7 + 1;
    *pfVar5 = (float)((double)CONCAT44(0x43300000,uVar4) - dVar1) * fVar2;
    pfVar5 = pfVar5 + 1;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  puVar3[0x404] = 3;
  puVar3[0x401] = 3;
  iVar8 = 8;
  puVar3[0x405] = 4;
  puVar3[0x407] = 0;
  puVar3[0x400] = 4;
  puVar3[0x402] = 4;
  puVar6 = puVar3 + 0x408;
  puVar3[0x406] = 1;
  puVar3[0x403] = 1;
  do {
    *puVar6 = 4;
    puVar6 = puVar6 + 1;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  puVar6 = puVar3 + 0x410;
  iVar8 = 0x10;
  do {
    *puVar6 = 4;
    puVar6 = puVar6 + 1;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  return;
}

/* _glePreInitTOC @ 0x1d9c (560 bytes) */
int _glePreInitTOC()
{
  float fVar1;
  float fVar2;
  undefined *puVar3;
  undefined4 in_r3;
  undefined4 extraout_r3;
  uint uVar4;
  
  puVar3 = PTR__gle_rtc_toc_struct_0011205c;
  *(undefined4 *)(PTR__gle_rtc_toc_struct_0011205c + 0x38) = 0x40400000;
  fVar1 = FLOAT_00108eb8;
  *(undefined4 *)(puVar3 + 0x30) = 0;
  *(float *)(puVar3 + 0x44) = fVar1;
  fVar1 = FLOAT_00108ebc;
  *(undefined4 *)(puVar3 + 0x3c) = 0x41400000;
  *(float *)(puVar3 + 0x4c) = fVar1;
  fVar1 = FLOAT_00108ec0;
  *(undefined4 *)(puVar3 + 0x48) = 0x3e800000;
  *(float *)(puVar3 + 0x54) = fVar1;
  fVar1 = FLOAT_00108e98;
  *(undefined4 *)(puVar3 + 0x40) = 0x3f000000;
  *(float *)(puVar3 + 0x58) = fVar1;
  fVar1 = FLOAT_00108e78;
  *(undefined4 *)(puVar3 + 0x50) = 0x3d800000;
  *(float *)(puVar3 + 0x5c) = fVar1;
  fVar1 = FLOAT_00108e9c;
  *(undefined4 *)(puVar3 + 0x68) = 0x30000000;
  *(float *)(puVar3 + 0x60) = fVar1;
  fVar1 = FLOAT_00108e74;
  *(undefined4 *)(puVar3 + 0x6c) = 0x2f800000;
  *(float *)(puVar3 + 100) = fVar1;
  *(float *)(puVar3 + 0x70) = FLOAT_00108e80;
  *(float *)(puVar3 + 0x74) = FLOAT_00108eb4;
  *(float *)(puVar3 + 0x78) = FLOAT_00108ec4;
  *(float *)(puVar3 + 0x7c) = FLOAT_00108ec8;
  fVar1 = FLOAT_00108ecc;
  *(undefined4 *)(puVar3 + 0x98) = 0x47800000;
  *(float *)(puVar3 + 0x80) = fVar1;
  fVar1 = FLOAT_00108ed0;
  *(undefined4 *)(puVar3 + 0x34) = 0x3f800000;
  *(float *)(puVar3 + 0x90) = fVar1;
  fVar1 = FLOAT_00108ed4;
  *(undefined4 *)(puVar3 + 0xb0) = 0x3f800000;
  *(float *)(puVar3 + 0x94) = fVar1;
  *(float *)(puVar3 + 0x9c) = FLOAT_00108ed8;
  *(float *)(puVar3 + 0xa0) = FLOAT_00108edc;
  *(float *)(puVar3 + 0xa4) = FLOAT_00108ee0;
  *(float *)(puVar3 + 0xa8) = FLOAT_00108ee4;
  *(float *)(puVar3 + 0xac) = FLOAT_00108ee8;
  *(float *)(puVar3 + 0xb4) = FLOAT_00108eec;
  *(float *)(puVar3 + 0xb8) = FLOAT_00108ef0;
  *(float *)(puVar3 + 0xbc) = FLOAT_00108ef4;
  *(float *)(puVar3 + 0xc0) = FLOAT_00108ef8;
  *(float *)(puVar3 + 0xc4) = FLOAT_00108efc;
  *(float *)(puVar3 + 200) = FLOAT_00108f00;
  *(float *)(puVar3 + 0xcc) = FLOAT_00108f04;
  *(float *)(puVar3 + 0xd0) = FLOAT_00108f08;
  uVar4 = *(uint *)PTR__gle_processor_0011204c;
  *(float *)(puVar3 + 0xd4) = FLOAT_00108f0c;
  fVar1 = FLOAT_00108f10;
  *(undefined8 *)(puVar3 + 0xe8) = 0x4330000000000000;
  fVar2 = FLOAT_00108f14;
  *(float *)(puVar3 + 0xd8) = fVar1;
  *(float *)(puVar3 + 0xdc) = fVar2;
  *(undefined8 *)(puVar3 + 0xe0) = 0x4330000080000000;
  if ((uVar4 & 0x10) != 0) {
    ((void (*)())_glePreInitVectorTOC)();
    in_r3 = extraout_r3;
  }
  return in_r3;
}

/* _glePreInitVectorTOC @ 0x1fcc (100 bytes) */
void _glePreInitVectorTOC()
{
  undefined4 *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  
  uVar13 = _UNK_00113e3c;
  uVar12 = _UNK_00113e38;
  uVar11 = _UNK_00113e34;
  uVar10 = _DAT_00113e30;
  uVar9 = _UNK_00113e2c;
  uVar8 = _UNK_00113e28;
  uVar7 = _UNK_00113e24;
  uVar6 = _UNK_00113e1c;
  uVar5 = _UNK_00113e18;
  uVar4 = _UNK_00113e14;
  uVar3 = _DAT_00113e10;
  puVar2 = PTR__gle_rtc_toc_struct_0011205c;
  puVar1 = (undefined4 *)((uint)(PTR__gle_rtc_toc_struct_0011205c + 0x10) & 0xfffffff0);
  *puVar1 = _DAT_00113e20;
  puVar1[1] = uVar7;
  puVar1[2] = uVar8;
  puVar1[3] = uVar9;
  puVar1 = (undefined4 *)((uint)(puVar2 + 0x20) & 0xfffffff0);
  *puVar1 = uVar10;
  puVar1[1] = uVar11;
  puVar1[2] = uVar12;
  puVar1[3] = uVar13;
  puVar1 = (undefined4 *)((uint)puVar2 & 0xfffffff0);
  *puVar1 = uVar3;
  puVar1[1] = uVar4;
  puVar1[2] = uVar5;
  puVar1[3] = uVar6;
  return;
}

/* _glePreInitNormalize @ 0x2030 (4 bytes) */
void _glePreInitNormalize()
{
  return;
}

/* _glePreInitProjectionTransformFunc @ 0x2034 (68 bytes) */
void _glePreInitProjectionTransformFunc()
{
  _gleBuildProjectionTransformFunc = PTR__gleBuildProjectionTransformFuncNO_00110a14;
  if ((*(uint *)PTR__gle_processor_0011204c & 0x10) != 0) {
    _gleBuildProjectionTransformFunc = PTR__gleBuildProjectionTransformFuncAV_00110a18;
  }
  return;
}

/* _glePreInitModelviewTransformFunc @ 0x2078 (68 bytes) */
void _glePreInitModelviewTransformFunc()
{
  _gleBuildModelviewTransformFunc = PTR__gleBuildModelviewTransformFuncNO_001109fc;
  if ((*(uint *)PTR__gle_processor_0011204c & 0x10) != 0) {
    _gleBuildModelviewTransformFunc = PTR__gleBuildModelviewTransformFuncAV_00110a00;
  }
  return;
}

/* _glePreInitNormalTransformFunc @ 0x20bc (68 bytes) */
void _glePreInitNormalTransformFunc()
{
  _gleBuildNormalTransformFunc = PTR__gleBuildNormalTransformFuncNO_00110a08;
  if ((*(uint *)PTR__gle_processor_0011204c & 0x10) != 0) {
    _gleBuildNormalTransformFunc = PTR__gleBuildNormalTransformFuncAV_00110a0c;
  }
  return;
}

/* _glePreInitVertexSubmitFunc @ 0x2100 (36 bytes) */
void _glePreInitVertexSubmitFunc()
{
  _gleBuildVertexFunc = PTR__gleBuildVertexFuncNO_001104f4;
  return;
}

/* _glepGetPlugins @ 0x2124 (28 bytes) */
int _glepGetPlugins()
{
  return _glep_plugin_head;
}

/* _gleOptimizeDisplayListCreateHashTable @ 0x2140 (248 bytes) */
void _gleOptimizeDisplayListCreateHashTable()
{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined **ppuVar8;
  int iVar9;
  
  if ((_gleDisplayListFunctionHash == 0) &&
     (_gleDisplayListFunctionHash = _calloc(1,0x80),
     PTR__glBegin_ListExec_00110a2c != (undefined *)0x0)) {
    iVar9 = 0;
    ppuVar8 = &PTR__glBegin_ListExec_00110a2c;
    do {
      puVar5 = (undefined4 *)_malloc(0x10);
      iVar2 = _gleDisplayListFunctionHash;
      uVar3 = *(undefined4 *)((int)&DAT_00110a30 + iVar9);
      uVar7 = *(undefined4 *)((int)&DAT_00110a34 + iVar9);
      uVar6 = *(uint *)((int)&PTR__glBegin_ListExec_00110a2c + iVar9);
      uVar1 = uVar6 & 0x7c;
      *puVar5 = *(undefined4 *)((int)&_fi + iVar9);
      puVar5[2] = uVar3;
      puVar5[3] = uVar7;
      puVar5[1] = uVar6;
      iVar4 = *(int *)(uVar1 + iVar2);
      if (iVar4 == 0) {
        *(undefined4 **)(uVar1 + iVar2) = puVar5;
      }
      else {
        for (iVar2 = *(int *)(iVar4 + 0xc); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0xc)) {
          iVar4 = iVar2;
        }
        *(undefined4 **)(iVar4 + 0xc) = puVar5;
      }
      ppuVar8 = ppuVar8 + 4;
      iVar9 = iVar9 + 0x10;
    } while (*ppuVar8 != (undefined *)0x0);
  }
  return;
}

/* _gliGetInteger @ 0x2238 (1900 bytes) */
int _gliGetInteger(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  uint *param_3;
{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined *puVar4;
  
  if ((param_2 == 0xe0) && (param_3 != (uint *)0x0)) {
    *param_3 = 0xaa8;
    return 0;
  }
  if ((param_1 == 0) || (*(int *)(param_1 + 0x467c) != 0x3463a223)) {
    return 0x2714;
  }
  if (param_3 == (uint *)0x0) {
    return 0x271e;
  }
  if (param_2 == 0x184) {
    uVar1 = (uint)*(short *)(param_1 + 0x48bc);
    goto LAB_0000296c;
  }
  if (param_2 < 0x185) {
    if (param_2 == 0x164) {
      uVar1 = (uint)*(short *)(param_1 + 0x509a);
      goto LAB_0000296c;
    }
    if (0x164 < param_2) {
      if (param_2 == 0x174) {
        uVar1 = (uint)*(short *)(param_1 + 0x49be);
      }
      else if (param_2 < 0x175) {
        if (param_2 == 0x16a) {
          uVar1 = (uint)*(short *)(param_1 + 0x48b4);
        }
        else if (param_2 < 0x16b) {
          if (param_2 == 0x166) {
            uVar1 = (uint)*(short *)(param_1 + 0x50a4);
          }
          else {
            if (param_2 != 0x168) goto LAB_00002978;
            uVar1 = (uint)*(short *)(param_1 + 0x50a6);
          }
        }
        else if (param_2 == 0x16c) {
          uVar1 = (uint)*(short *)(param_1 + 0x48b6);
        }
        else {
          if (param_2 != 0x172) goto LAB_00002978;
          uVar1 = (uint)*(short *)(param_1 + 0x49bc);
        }
      }
      else if (param_2 == 0x17c) {
        uVar1 = (uint)*(short *)(param_1 + 0x48a4);
      }
      else if (param_2 < 0x17d) {
        if (param_2 == 0x176) {
          uVar1 = (uint)*(short *)(param_1 + 0x49c0);
        }
        else {
          if (param_2 != 0x178) goto LAB_00002978;
          uVar1 = (uint)*(short *)(param_1 + 0x49c2);
        }
      }
      else if (param_2 == 0x180) {
        uVar1 = (uint)*(short *)(param_1 + 0x48ac);
      }
      else if (param_2 < 0x181) {
        if (param_2 != 0x17e) {
LAB_00002978:
          uVar3 = (**(code **)(param_1 + 0x477c))(*(undefined4 *)(param_1 + 0x4688),param_2,param_3)
          ;
          return uVar3;
        }
        uVar1 = (uint)*(short *)(param_1 + 0x48a6);
      }
      else {
        if (param_2 != 0x182) goto LAB_00002978;
        uVar1 = (uint)*(short *)(param_1 + 0x48ae);
      }
      goto LAB_0000296c;
    }
    if (param_2 == 0x135) {
      uVar1 = *(uint *)((uint)*(byte *)(param_1 + 0x85a8) * 0x2e0 + param_1 + 0x8888);
LAB_00002638:
      *param_3 = uVar1;
      return 0;
    }
    if (param_2 < 0x136) {
      if (param_2 != 0xe5) {
        if (param_2 < 0xe6) {
          if (param_2 == 0xdd) {
            uVar1 = (uint)*(byte *)(param_1 + 0x4690);
            goto LAB_0000296c;
          }
          if (param_2 == 0xe4) {
            uVar1 = *(uint *)(param_1 + 0x7590);
            goto LAB_00002638;
          }
        }
        else if (param_2 == 0x126) {
          iVar2 = _gleLookUpNonProxyTexture(param_1,*param_3);
          if (iVar2 == 0) {
            return 0x271a;
          }
          param_2 = 0x126;
          *param_3 = *(uint *)(iVar2 + (uint)*(byte *)(param_1 + 0x85a8) * 4);
        }
        else if (param_2 == 0x133) {
          uVar1 = (uint)*(byte *)(param_1 + 0x5410);
          goto LAB_00002638;
        }
        goto LAB_00002978;
      }
      uVar1 = (uint)*(byte *)(param_1 + 0x4693);
      goto LAB_00002638;
    }
    if (param_2 == 0x15e) {
      uVar1 = (uint)*(short *)(param_1 + 0x508c);
      goto LAB_0000296c;
    }
    if (0x15e < param_2) {
      if (param_2 == 0x160) {
        uVar1 = (uint)*(short *)(param_1 + 0x508e);
      }
      else {
        if (param_2 != 0x162) goto LAB_00002978;
        uVar1 = (uint)*(short *)(param_1 + 0x5098);
      }
      goto LAB_0000296c;
    }
    if (param_2 == 0x136) {
      uVar1 = (uint)(*(char *)(param_1 + 0x7580) == '\x01');
      goto LAB_0000296c;
    }
    if (param_2 != 0x137) goto LAB_00002978;
    uVar1 = *(uint *)(*(int *)((uint)*(byte *)(param_1 + 0x85a6) * 0x2e0 + param_1 + 0x8884) + 0x104
                     ) & 0xff00;
    if ((uVar1 == 0x200) || (uVar1 == 0x400)) {
      uVar1 = 0;
      goto LAB_0000296c;
    }
    uVar1 = -(uint)*(byte *)(param_1 + 0x7581);
  }
  else {
    if (param_2 == 0x643) {
      uVar3 = 6;
      puVar4 = (undefined *)(*(int *)(param_1 + 0x5148) + 0x6018);
      goto LAB_0000272c;
    }
    if (0x643 < param_2) {
      if (param_2 == 0x649) {
        uVar3 = 1;
        puVar4 = ((unsigned char *)0x00001004) + *(int *)(param_1 + 0x5148);
LAB_0000272c:
        _gleGetHashMachineObjectNameTargetPairs(param_1,puVar4,uVar3,param_3);
        return 0;
      }
      if (param_2 < 0x64a) {
        if (param_2 == 0x646) {
          puVar4 = (undefined *)(param_1 + 0x6440);
          uVar3 = 0xfffffff5;
        }
        else if (param_2 < 0x647) {
          if (param_2 == 0x644) {
            uVar3 = 5;
            puVar4 = (undefined *)(*(int *)(param_1 + 0x5148) + 0x5014);
          }
          else {
            if (param_2 != 0x645) goto LAB_00002978;
            uVar3 = 7;
            puVar4 = (undefined *)(*(int *)(param_1 + 0x5148) + 0x701c);
          }
        }
        else if (param_2 == 0x647) {
          puVar4 = (undefined *)(param_1 + 0x543c);
          uVar3 = 0xfffffff4;
        }
        else {
          if (param_2 != 0x648) goto LAB_00002978;
          puVar4 = *(undefined **)(param_1 + 0x5148);
          uVar3 = 0;
        }
        goto LAB_0000272c;
      }
      if (param_2 == 0x6a6) {
        iVar2 = *(int *)(param_1 + 0x5148);
        if (*(char *)(iVar2 + 0x8024) != '\0') {
          _pthread_mutex_lock(iVar2 + 0x8028);
          iVar2 = *(int *)(param_1 + 0x5148);
        }
        iVar2 = _gleLookupHashObject(iVar2 + 0x6018,*param_3);
        if (iVar2 == 0) goto LAB_000028f4;
        if (*(int *)(iVar2 + 0x10) == 0x8b40) {
          uVar1 = _ShGetLinkerStats(*(undefined4 *)(iVar2 + 0x40));
        }
        else {
          if (*(int *)(iVar2 + 0x10) != 0x8b48) goto LAB_000028f4;
          uVar1 = _ShGetCompilerStats(*(undefined4 *)(iVar2 + 0x30));
        }
      }
      else if (param_2 < 0x6a7) {
        if (param_2 == 0x6a4) {
          iVar2 = *(int *)(param_1 + 0x5148);
          if (*(char *)(iVar2 + 0x8024) != '\0') {
            _pthread_mutex_lock(iVar2 + 0x8028);
            iVar2 = *(int *)(param_1 + 0x5148);
          }
          iVar2 = _gleLookupHashObject(iVar2 + 0x6018,*param_3);
          if (iVar2 == 0) goto LAB_000028f4;
          if (*(int *)(iVar2 + 0x10) == 0x8b40) {
            uVar1 = _ShGetLinkerPPStream(*(undefined4 *)(iVar2 + 0x40));
          }
          else {
            if (*(int *)(iVar2 + 0x10) != 0x8b48) goto LAB_000028f4;
            uVar1 = _ShGetCompilerPPStream(*(undefined4 *)(iVar2 + 0x30));
          }
        }
        else {
          if (param_2 != 0x6a5) goto LAB_00002978;
          iVar2 = *(int *)(param_1 + 0x5148);
          if (*(char *)(iVar2 + 0x8024) != '\0') {
            _pthread_mutex_lock(iVar2 + 0x8028);
            iVar2 = *(int *)(param_1 + 0x5148);
          }
          iVar2 = _gleLookupHashObject(iVar2 + 0x6018,*param_3);
          if (iVar2 == 0) goto LAB_000028f4;
          if (*(int *)(iVar2 + 0x10) == 0x8b40) {
            uVar1 = _ShGetLinkerBindingTable(*(undefined4 *)(iVar2 + 0x40));
          }
          else {
            if (*(int *)(iVar2 + 0x10) != 0x8b48) goto LAB_000028f4;
            uVar1 = _ShGetCompilerSymbolTable(*(undefined4 *)(iVar2 + 0x30));
          }
        }
      }
      else {
        if (param_2 == 0x6a8) {
          uVar1 = *(uint *)(param_1 + 0x7598);
          goto LAB_00002638;
        }
        if (param_2 < 0x6a8) {
          uVar1 = *(uint *)(param_1 + 0x7594);
          goto LAB_00002638;
        }
        if (param_2 != 0x6a9) goto LAB_00002978;
        iVar2 = *(int *)(param_1 + 0x5148);
        if (*(char *)(iVar2 + 0x8024) != '\0') {
          _pthread_mutex_lock(iVar2 + 0x8028);
          iVar2 = *(int *)(param_1 + 0x5148);
        }
        iVar2 = _gleLookupHashObject(iVar2 + 0x6018,*param_3);
        if (iVar2 == 0) goto LAB_000028f4;
        if (*(int *)(iVar2 + 0x10) == 0x8b40) {
          uVar1 = _ShGetLinkerShaderToProgramString(*(undefined4 *)(iVar2 + 0x40));
        }
        else {
          if (*(int *)(iVar2 + 0x10) != 0x8b48) goto LAB_000028f4;
          uVar1 = _ShGetCompilerShaderToProgramString(*(undefined4 *)(iVar2 + 0x30));
        }
      }
      *param_3 = uVar1;
LAB_000028f4:
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) == '\0') {
        return 0;
      }
      _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
      return 0;
    }
    if (param_2 == 0x3e2) {
      uVar1 = (uint)*(byte *)(param_1 + 0x7584);
      goto LAB_00002638;
    }
    if (param_2 < 0x3e3) {
      if (param_2 == 0x18a) {
        uVar1 = (uint)*(short *)(param_1 + 0x48c6);
      }
      else {
        if (0x18a < param_2) {
          if (param_2 == 0x3e0) {
            uVar1 = (uint)*(byte *)(param_1 + 0x7587);
          }
          else {
            if (param_2 != 0x3e1) goto LAB_00002978;
            uVar1 = (uint)*(byte *)(param_1 + 0x7586);
          }
          goto LAB_00002638;
        }
        if (param_2 == 0x186) {
          uVar1 = (uint)*(short *)(param_1 + 0x48be);
        }
        else {
          if (param_2 != 0x188) goto LAB_00002978;
          uVar1 = (uint)*(short *)(param_1 + 0x48c4);
        }
      }
      goto LAB_0000296c;
    }
    if (param_2 == 0x640) {
      uVar3 = 2;
      puVar4 = (undefined *)(*(int *)(param_1 + 0x5148) + 0x2008);
      goto LAB_0000272c;
    }
    if (0x640 < param_2) {
      if (param_2 == 0x641) {
        uVar3 = 3;
        puVar4 = (undefined *)(*(int *)(param_1 + 0x5148) + 0x300c);
      }
      else {
        if (param_2 != 0x642) goto LAB_00002978;
        uVar3 = 4;
        puVar4 = (undefined *)(*(int *)(param_1 + 0x5148) + 0x4010);
      }
      goto LAB_0000272c;
    }
    if (param_2 == 0x3e4) {
      uVar1 = (uint)*(byte *)(param_1 + 0x53e7);
      goto LAB_00002638;
    }
    if (param_2 != 0x4d3) goto LAB_00002978;
    uVar1 = ~(int)*(short *)(param_1 + 0x4a10);
  }
  uVar1 = uVar1 >> 0x1f;
LAB_0000296c:
  *param_3 = uVar1;
  return 0;
}

/* _gliChoosePixelFormat @ 0x29a4 (260 bytes) */
int _gliChoosePixelFormat(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *local_30 [6];
  
  iVar3 = 0x271e;
  if ((param_1 != (int *)0x0) && (*param_1 = 0, param_2 != 0)) {
    piVar4 = (int *)((int (*)())_glepGetPlugins)();
    iVar3 = 0x271f;
    piVar2 = param_1;
    if (piVar4 != (int *)0x0) {
      do {
        iVar3 = (*(code *)piVar4[0x46])(local_30,param_2);
        if (local_30[0] != (int *)0x0) {
          *piVar2 = (int)local_30[0];
          local_30[0][1] = local_30[0][1] | 0x20000;
          iVar1 = *local_30[0];
          piVar2 = local_30[0];
          while (local_30[0] = piVar2, iVar1 != 0) {
            piVar2 = (int *)*piVar2;
            piVar2[1] = piVar2[1] | 0x20000;
            iVar1 = *piVar2;
          }
        }
        piVar4 = (int *)*piVar4;
        if (piVar4 == (int *)0x0) {
          if (iVar3 == 0) {
            return 0;
          }
          break;
        }
      } while (iVar3 == 0);
      if (*param_1 != 0) {
        ((int (*)())_gliDestroyPixelFormat)(*param_1);
        *param_1 = 0;
      }
    }
  }
  return iVar3;
}

/* _gliQueryRendererInfo @ 0x2aa8 (292 bytes) */
int _gliQueryRendererInfo(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  int *piVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  iVar4 = 0;
  iVar6 = 0;
  if (param_1 == (int *)0x0) {
    return 0x271e;
  }
  *param_1 = 0;
  piVar1 = (int *)((int (*)())_glepGetPlugins)();
  if (piVar1 == (int *)0x0) {
    return 0x271f;
  }
  do {
    piVar1 = (int *)*piVar1;
    iVar6 = iVar6 + 1;
  } while (piVar1 != (int *)0x0);
  piVar1 = (int *)_malloc(iVar6 * 0x38);
  if (piVar1 == (int *)0x0) {
    return 0x2720;
  }
  puVar2 = (undefined4 *)((int (*)())_glepGetPlugins)();
  iVar6 = 0;
  if (puVar2 != (undefined4 *)0x0) {
    piVar5 = piVar1 + 0xe;
    piVar3 = piVar1;
    do {
      iVar4 = (*(code *)puVar2[0x48])(piVar3,param_2);
      if (iVar4 == 0) {
        iVar6 = iVar6 + 1;
        *piVar3 = (int)piVar5;
        piVar3[1] = piVar3[1] | 0x20000;
        piVar3[2] = piVar3[2] | 0x8000;
        piVar5 = piVar5 + 0xe;
        piVar3 = piVar3 + 0xe;
        puVar2 = (undefined4 *)*puVar2;
      }
      else {
        if (iVar4 != 0x2719) break;
        puVar2 = (undefined4 *)*puVar2;
        iVar4 = 0;
      }
    } while (puVar2 != (undefined4 *)0x0);
    if ((iVar6 != 0) && (iVar4 == 0)) {
      piVar1[iVar6 * 0xe + -0xe] = 0;
      piVar3 = piVar1;
      goto LAB_00002bb0;
    }
  }
  piVar3 = (int *)0x0;
  _free(piVar1);
LAB_00002bb0:
  *param_1 = (int)piVar3;
  return iVar4;
}

/* _gliDestroyRendererInfo @ 0x2bcc (52 bytes) */
int _gliDestroyRendererInfo(param_1)
  int param_1;
{
  undefined4 uVar1;
  
  uVar1 = 0x271e;
  if (param_1 != 0) {
    _free(param_1);
    uVar1 = 0;
  }
  return uVar1;
}

/* _gliDestroyPixelFormat @ 0x2c00 (208 bytes) */
int _gliDestroyPixelFormat(param_1)
  int *param_1;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  
  iVar3 = 0x271e;
  iVar6 = 0;
  if (param_1 != (int *)0x0) {
    do {
      piVar7 = (int *)*param_1;
      bVar1 = piVar7 == (int *)0x0;
      if (bVar1) {
        uVar4 = param_1[1];
      }
      else {
        uVar4 = param_1[1];
        uVar2 = piVar7[1];
        while ((uVar2 & 0xff00) == (uVar4 & 0xff00)) {
          piVar7 = (int *)*piVar7;
          bVar1 = piVar7 == (int *)0x0;
          if (bVar1) break;
          uVar2 = piVar7[1];
        }
      }
      iVar3 = ((int (*)())_glepGetPlugin)(uVar4 & 0xff00);
      iVar5 = 0x271f;
      if (iVar3 != 0) {
        iVar5 = (**(code **)(iVar3 + 0x11c))(param_1);
      }
      iVar3 = iVar6;
      if ((iVar5 != 0) && (iVar6 == 0)) {
        iVar3 = iVar5;
      }
      iVar6 = iVar3;
      param_1 = piVar7;
    } while (!bVar1);
  }
  return iVar3;
}

/* _glepGetPlugin @ 0x2cd0 (72 bytes) */
int _glepGetPlugin(param_1)
  int param_1;
{
  int *piVar1;
  
  piVar1 = (int *)_glep_plugin_head;
  while( true ) {
    if (piVar1 == (int *)0x0) {
      return 0;
    }
    if (param_1 == piVar1[0x41]) break;
    piVar1 = (int *)*piVar1;
  }
  return (int)piVar1;
}

/* _gliCreateContext @ 0x2d18 (1112 bytes) */
int _gliCreateContext(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int *param_1;
  int *param_2;
  int param_3;
  undefined4 param_4;
  undefined4 param_5;
  uint param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  undefined4 *puVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int *piVar14;
  
  uVar12 = 0xff;
  bVar3 = false;
  if (param_1 == (int *)0x0) {
    return 0x271e;
  }
  *param_1 = 0;
  uVar13 = 0;
  piVar14 = param_2;
  if (param_2 != (int *)0x0) {
    do {
      uVar11 = uVar13;
      if ((piVar14[1] & 0xff0000U) != 0x20000) {
        return 0x2712;
      }
      if ((piVar14[2] & 0x40U) == 0) {
        bVar3 = true;
      }
      uVar13 = piVar14[1] & 0xff00;
      if ((uVar13 == 0x400) || (uVar13 == 0x500)) {
        uVar12 = uVar11;
      }
      piVar14 = (int *)*piVar14;
      uVar13 = uVar11 + 1;
    } while (piVar14 != (int *)0x0);
    if (uVar13 != 0) {
      bVar2 = false;
      if ((bVar3) && ((param_6 & 1) != 0)) {
        bVar2 = true;
      }
      if (bVar2) {
        if (uVar12 == 0xff) {
          uVar12 = uVar13;
          uVar13 = uVar11 + 2;
        }
      }
      else {
        uVar12 = 0xff;
      }
      if (8 < (int)uVar13) {
        return 0x2712;
      }
      bVar3 = param_3 == 0;
      if ((!bVar3) &&
         ((*(int *)(param_3 + 0x467c) != 0x3463a223 || (*(byte *)(param_3 + 0x85a4) != uVar13)))) {
        return 0x2719;
      }
      iVar5 = ((int (*)())_gleDCBAlloc)(uVar13 * 0x2e0 + 0x85b0);
      if (iVar5 == 0) {
        return 0x2720;
      }
      uVar11 = 0;
      bVar2 = uVar13 == 0;
      *(undefined2 *)(iVar5 + 0x360) = 2;
      *(undefined2 *)(iVar5 + 0x362) = 4;
      *(undefined1 *)(iVar5 + 0x85a6) = 0;
      *(char *)(iVar5 + 0x85a5) = (char)uVar12;
      *(undefined4 *)(iVar5 + 0x4680) = param_4;
      *(undefined4 *)(iVar5 + 0x4684) = param_5;
      *(undefined4 *)(iVar5 + 0x5148) = 0;
      *(char *)(iVar5 + 0x85a4) = (char)uVar13;
      if (0 < (int)uVar13) {
        iVar10 = iVar5 + 0x85ac;
        iVar9 = 0;
        piVar14 = param_2;
        do {
          _memset(iVar10,0,0x2e0);
          if (piVar14 == (int *)0x0) {
            uVar12 = 0x400;
            iVar7 = ((int (*)())_glepGetPlugin)(0x400);
            piVar14 = param_2;
            if (iVar7 == 0) {
              uVar6 = 0x500;
              uVar12 = 0x500;
              goto LAB_00002ef4;
            }
          }
          else {
            uVar6 = piVar14[1] & 0xff00;
            uVar12 = piVar14[1] & 0xff00ffff;
LAB_00002ef4:
            iVar7 = ((int (*)())_glepGetPlugin)(uVar6);
            if (iVar7 == 0) {
              bVar2 = uVar11 == uVar13;
              break;
            }
          }
          uVar11 = uVar11 + 1;
          iVar4 = iVar9 + iVar5;
          bVar2 = uVar11 == uVar13;
          iVar9 = iVar9 + 0x2e0;
          *(int *)(iVar4 + 0x8884) = iVar7;
          iVar10 = iVar10 + 0x2e0;
          *(uint *)(iVar4 + 0x8888) = uVar12;
          piVar14 = (int *)*piVar14;
        } while ((int)uVar11 < (int)uVar13);
      }
      if (bVar2) {
        if (bVar3) {
          uVar8 = ((int (*)())_gleCreateSharedState)(iVar5);
        }
        else {
          uVar8 = _gleShareSharedState(param_3);
        }
        *(undefined4 *)(iVar5 + 0x5148) = uVar8;
        iVar9 = *(int *)(iVar5 + 0x5148);
        if (iVar9 == 0) {
          _gleDCBFree(iVar5);
          return 0x2720;
        }
        iVar10 = 0;
        piVar14 = param_2;
        if (0 < (int)uVar13) {
          while( true ) {
            if (piVar14 == (int *)0x0) {
              piVar14 = param_2;
            }
            iVar7 = iVar10 * 0x2e0;
            if (bVar3) {
              uVar8 = 0;
            }
            else {
              uVar8 = *(undefined4 *)(iVar7 + param_3 + 0x85ac);
            }
            iVar9 = (**(code **)(*(int *)(iVar7 + iVar5 + 0x8884) + 300))
                              (iVar7 + iVar5 + 0x85ac,piVar14,
                               *(undefined4 *)(iVar10 * 4 + iVar9 + 0x8054),uVar8,
                               iVar5 + iVar7 + 0x85b0,iVar5 + 0x360,iVar5 + iVar7 + 0x86e0);
            if (iVar9 != 0) {
              iVar7 = _gleReleaseSharedState(iVar5);
              if (-1 < iVar10) {
                iVar4 = iVar10 * 0x2e0 + iVar5 + 0x10000;
                do {
                  piVar14 = (int *)(iVar4 + -0x777c);
                  puVar1 = (undefined4 *)(iVar4 + -0x7a54);
                  iVar4 = iVar4 + -0x2e0;
                  (**(code **)(*piVar14 + 0x130))(*puVar1);
                  iVar10 = iVar10 + -1;
                } while (-1 < iVar10);
              }
              goto LAB_00003108;
            }
            iVar10 = iVar10 + 1;
            piVar14 = (int *)*piVar14;
            if ((int)uVar13 <= iVar10) break;
            iVar9 = *(int *)(iVar5 + 0x5148);
          }
        }
        *(int *)(iVar5 + 0x468c) = iVar5 + 0x85b0;
        *(undefined4 *)(iVar5 + 0x4688) = *(undefined4 *)(iVar5 + 0x85ac);
        *(undefined1 *)(iVar5 + 0x85a8) = 0;
        _memcpy(iVar5 + 0x4754,*(int *)(iVar5 + 0x8884) + 0x114,0xf4);
        if (_gl_list == 0) {
          ((int (*)())_gleCreateEnableHashTable)();
        }
        iVar9 = ((int (*)())_gleInitializeContext)(iVar5);
        if (iVar9 == 0) {
          _gliSetCurrentPluginDispatchTable(iVar5);
          _gliInitDispatchTable(iVar5);
          _gliExecDispatchTable(iVar5);
          *(int *)(iVar5 + 0x85a0) = _gl_list;
          _gl_list = iVar5;
          *param_1 = iVar5;
          return 0;
        }
        iVar10 = 0;
        iVar7 = _gleReleaseSharedState(iVar5);
        if (*(char *)(iVar5 + 0x85a4) != '\0') {
          iVar4 = iVar5 + 0x10000;
          do {
            piVar14 = (int *)(iVar4 + -0x777c);
            iVar10 = iVar10 + 1;
            puVar1 = (undefined4 *)(iVar4 + -0x7a54);
            iVar4 = iVar4 + 0x2e0;
            (**(code **)(*piVar14 + 0x130))(*puVar1);
          } while (iVar10 < (int)(uint)*(byte *)(iVar5 + 0x85a4));
        }
LAB_00003108:
        if (iVar7 != 0) {
          _gleDestroySharedState(iVar5);
        }
        _gleDCBFree(iVar5);
        return iVar9;
      }
      _gleDCBFree(iVar5);
    }
  }
  return 0x2712;
}

/* _gleDCBAlloc @ 0x3170 (68 bytes) */
int _gleDCBAlloc(param_1)
  int param_1;
{
  int iVar1;
  uint uVar2;
  
  iVar1 = _malloc(param_1 + 0x3fU & 0xffffffe0);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = iVar1 + 0x20U & 0xffffffe0;
    *(char *)(uVar2 - 1) = (char)uVar2 - (char)iVar1;
  }
  return uVar2;
}

/* _gleCreateSharedState @ 0x31b4 (548 bytes) */
int _gleCreateSharedState(param_1)
  int param_1;
{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined2 *puVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  int *piVar11;
  uint uVar12;
  int iVar13;
  
  iVar3 = _malloc(0x94d4);
  *(undefined4 *)(iVar3 + 0x8020) = 1;
  *(undefined1 *)(iVar3 + 0x8024) = 0;
  _pthread_mutex_init(iVar3 + 0x8028,0);
  uVar12 = 0;
  if (*(char *)(param_1 + 0x85a4) != '\0') {
    iVar9 = iVar3 + 0x8054;
    piVar11 = (int *)(param_1 + 0x8884);
    do {
      iVar1 = *piVar11;
      piVar11 = piVar11 + 0xb8;
      iVar1 = (**(code **)(iVar1 + 0x124))(iVar9);
      if (iVar1 != 0) break;
      uVar12 = uVar12 + 1;
      iVar9 = iVar9 + 4;
    } while ((int)uVar12 < (int)(uint)*(byte *)(param_1 + 0x85a4));
  }
  if (uVar12 == *(byte *)(param_1 + 0x85a4)) {
    if ((int)uVar12 < 8) {
      iVar9 = 8 - uVar12;
      puVar10 = (undefined4 *)(uVar12 * 4 + iVar3 + 0x8054);
      do {
        *puVar10 = 0;
        puVar10 = puVar10 + 1;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
    }
    iVar9 = 0;
    puVar10 = (undefined4 *)(iVar3 + 0x1000);
    do {
      puVar2 = (undefined4 *)(iVar9 * 0x1004 + iVar3);
      iVar1 = 0x400;
      do {
        *puVar2 = 0;
        puVar2 = puVar2 + 1;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
      iVar9 = iVar9 + 1;
      *puVar10 = 0;
      puVar10 = puVar10 + 0x401;
    } while (iVar9 < 8);
    iVar8 = iVar3 + 0x10000;
    iVar6 = 0;
    iVar5 = 0;
    iVar9 = iVar8;
    iVar1 = iVar8;
    do {
      puVar7 = (undefined2 *)(iVar9 + -0x778c);
      iVar13 = 0x100;
      puVar10 = (undefined4 *)(iVar8 + -0x7f8c);
      do {
        *puVar10 = 0;
        puVar10[1] = 0;
        puVar10 = puVar10 + 2;
        *puVar7 = 0;
        puVar7 = puVar7 + 1;
        iVar13 = iVar13 + -1;
      } while (iVar13 != 0);
      iVar13 = 9;
      puVar10 = (undefined4 *)(iVar5 * 4 + iVar3 + 0x8a74);
      do {
        *puVar10 = 0xffffffff;
        puVar10 = puVar10 + 1;
        iVar13 = iVar13 + -1;
      } while (iVar13 != 0);
      iVar6 = iVar6 + 1;
      *(undefined4 *)(iVar1 + -0x7568) = 0;
      *(undefined4 *)(iVar1 + -0x7560) = 0;
      *(undefined4 *)(iVar1 + -0x7564) = 0;
      iVar8 = iVar8 + 0xa30;
      iVar9 = iVar9 + 0xa30;
      iVar5 = iVar5 + 0x28c;
      iVar1 = iVar1 + 0xa30;
    } while (iVar6 < 2);
  }
  else {
    iVar9 = uVar12 - 1;
    if (-1 < iVar9) {
      puVar10 = (undefined4 *)(iVar9 * 4 + iVar3 + 0x8054);
      piVar11 = (int *)(iVar9 * 0x2e0 + param_1 + 0x8884);
      do {
        iVar1 = *piVar11;
        piVar11 = piVar11 + -0xb8;
        uVar4 = *puVar10;
        puVar10 = puVar10 + -1;
        (**(code **)(iVar1 + 0x128))(uVar4);
        iVar9 = iVar9 + -1;
      } while (-1 < iVar9);
    }
    _pthread_mutex_destroy(iVar3 + 0x8028);
    _free(iVar3);
    iVar3 = 0;
  }
  return iVar3;
}

/* _gleCreateEnableHashTable @ 0x33d8 (2092 bytes) */
int _gleCreateEnableHashTable()
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  
  puVar3 = (undefined4 *)_malloc(0x4000);
  puVar1 = PTR__gleSetEnable_Error_00110e18;
  iVar5 = 0x400;
  puVar2 = puVar3;
  _gle_enable_hash_table = puVar3;
  do {
    *puVar2 = 0;
    puVar2[1] = puVar1;
    puVar2[2] = 0;
    puVar2 = puVar2 + 4;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0x80d0,PTR__gleSetEnable_COLOR_TABLE_00110e14);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0x80d2,PTR__gleSetEnable_POST_COLOR_MATRIX_COLOR_TABLE_00110e10);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0x80d1,PTR__gleSetEnable_POST_CONVOLUTION_COLOR_TABLE_00110e0c);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0x8024,PTR__gleSetEnable_HISTOGRAM_00110e08);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0x802e,PTR__gleSetEnable_MINMAX_00110e04);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0x8010,PTR__gleSetEnable_CONVOLUTION_1D_00110e00);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0x8011,PTR__gleSetEnable_CONVOLUTION_2D_00110dfc);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0x8012,PTR__gleSetEnable_SEPARABLE_2D_00110df8);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0x8861,PTR__gleSetEnable_POINT_SPRITE_ARB_00110df4);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0xb60,PTR__gleSetEnable_FOG_00110df0);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0xb50,PTR__gleSetEnable_LIGHTING_00110dec);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0xde0,PTR__gleSetEnable_TEXTURE_1D_00110de8);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0xde1,PTR__gleSetEnable_TEXTURE_2D_00110de4);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0x806f,PTR__gleSetEnable_TEXTURE_3D_00110de0);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0x8513,PTR__gleSetEnable_TEXTURE_CUBE_MAP_00110ddc);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0x84f5,PTR__gleSetEnable_TEXTURE_RECTANGLE_EXT_00110dd8);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0x85b3,PTR__gleSetEnable_TEXTURE_RECTANGLE_EXT_00110dd8);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0x81fb,PTR__gleSetEnable_SHARED_TEXTURE_PALETTE_EXT_00110dd4);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0xb24,PTR__gleSetEnable_LINE_STIPPLE_00110dd0);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0xb42,PTR__gleSetEnable_POLYGON_STIPPLE_00110dcc);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0xb44,PTR__gleSetEnable_CULL_FACE_00110dc8);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0xbc0,PTR__gleSetEnable_ALPHA_TEST_00110dc4);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0xbe2,PTR__gleSetEnable_BLEND_00110dc0);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0xbf1,PTR__gleSetEnable_INDEX_LOGIC_OP_00110dbc);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0xbf2,PTR__gleSetEnable_COLOR_LOGIC_OP_00110db8);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0xbd0,PTR__gleSetEnable_DITHER_00110db4);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0xb90,PTR__gleSetEnable_STENCIL_TEST_00110db0);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0xb71,PTR__gleSetEnable_DEPTH_TEST_00110dac);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0x3000,PTR__gleSetEnable_CLIP_PLANE_00110da8);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0x3001,PTR__gleSetEnable_CLIP_PLANE_00110da8);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0x3002,PTR__gleSetEnable_CLIP_PLANE_00110da8);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0x3003,PTR__gleSetEnable_CLIP_PLANE_00110da8);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0x3004,PTR__gleSetEnable_CLIP_PLANE_00110da8);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0x3005,PTR__gleSetEnable_CLIP_PLANE_00110da8);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0x4000,PTR__gleSetEnable_LIGHT_00110da4);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0x4001,PTR__gleSetEnable_LIGHT_00110da4);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0x4002,PTR__gleSetEnable_LIGHT_00110da4);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0x4003,PTR__gleSetEnable_LIGHT_00110da4);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0x4004,PTR__gleSetEnable_LIGHT_00110da4);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0x4005,PTR__gleSetEnable_LIGHT_00110da4);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0x4006,PTR__gleSetEnable_LIGHT_00110da4);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0x4007,PTR__gleSetEnable_LIGHT_00110da4);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0xc60,PTR__gleSetEnable_TEXTURE_GEN_S_00110da0);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0xc61,PTR__gleSetEnable_TEXTURE_GEN_T_00110d9c);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0xc62,PTR__gleSetEnable_TEXTURE_GEN_R_00110d98);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0xc63,PTR__gleSetEnable_TEXTURE_GEN_Q_00110d94);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0xd97,PTR__gleSetEnable_MAP1_VERTEX_3_00110d90);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0xd98,PTR__gleSetEnable_MAP1_VERTEX_4_00110d8c);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0xd90,PTR__gleSetEnable_MAP1_COLOR_4_00110d88);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0xd91,PTR__gleSetEnable_MAP1_INDEX_00110d84);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0xd92,PTR__gleSetEnable_MAP1_NORMAL_00110d80);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0xd93,PTR__gleSetEnable_MAP1_TEXTURE_COORD_1_00110d7c);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0xd94,PTR__gleSetEnable_MAP1_TEXTURE_COORD_2_00110d78);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0xd95,PTR__gleSetEnable_MAP1_TEXTURE_COORD_3_00110d74);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0xd96,PTR__gleSetEnable_MAP1_TEXTURE_COORD_4_00110d70);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0xdb7,PTR__gleSetEnable_MAP2_VERTEX_3_00110d6c);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0xdb8,PTR__gleSetEnable_MAP2_VERTEX_4_00110d68);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0xdb0,PTR__gleSetEnable_MAP2_COLOR_4_00110d64);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0xdb1,PTR__gleSetEnable_MAP2_INDEX_00110d60);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0xdb2,PTR__gleSetEnable_MAP2_NORMAL_00110d5c);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0xdb3,PTR__gleSetEnable_MAP2_TEXTURE_COORD_1_00110d58);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0xdb4,PTR__gleSetEnable_MAP2_TEXTURE_COORD_2_00110d54);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0xdb5,PTR__gleSetEnable_MAP2_TEXTURE_COORD_3_00110d50);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0xdb6,PTR__gleSetEnable_MAP2_TEXTURE_COORD_4_00110d4c);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0xb10,PTR__gleSetEnable_POINT_SMOOTH_00110d48);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0xb20,PTR__gleSetEnable_LINE_SMOOTH_00110d44);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0xb41,PTR__gleSetEnable_POLYGON_SMOOTH_00110d40);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0xc11,PTR__gleSetEnable_SCISSOR_TEST_00110d3c);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0xb57,PTR__gleSetEnable_COLOR_MATERIAL_00110d38);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0xba1,PTR__gleSetEnable_NORMALIZE_00110d34);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0x803a,PTR__gleSetEnable_RESCALE_NORMAL_EXT_00110d30);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0xd80,PTR__gleSetEnable_AUTO_NORMAL_00110d2c);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0x2a01,PTR__gleSetEnable_POLYGON_OFFSET_POINT_00110d28);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0x2a02,PTR__gleSetEnable_POLYGON_OFFSET_LINE_00110d24);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0x8037,PTR__gleSetEnable_POLYGON_OFFSET_FILL_00110d20);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0x8522,PTR__gleSetEnable_REGISTER_COMBINERS_NV_00110d1c);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0x8535,PTR__gleSetEnable_PER_STAGE_CONSTANTS_NV_00110d18);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0x86de,PTR__gleSetEnable_TEXTURE_SHADER_NV_00110d14);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0x864f,PTR__gleSetEnable_DEPTH_CLAMP_NV_00110d10);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0x19262,PTR__gleSetEnable_RASTER_POSITION_UNCLIPPED_IBM_00110d0c);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0x6090,PTR__gleSetEnable_PN_TRIANGLES_ATI_00110d08);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0x809d,PTR__gleSetEnable_MULTISAMPLE_00110d04);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0x809e,PTR__gleSetEnable_SAMPLE_ALPHA_TO_COVERAGE_00110d00);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0x809f,PTR__gleSetEnable_SAMPLE_ALPHA_TO_ONE_00110cfc);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0x80a0,PTR__gleSetEnable_SAMPLE_COVERAGE_00110cf8);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0x86a7,PTR__gleSetEnable_VERTEX_BLEND_ARB_00110cf4);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0x86a6,PTR__gleSetEnable_WEIGHT_SUM_UNITY_ARB_00110cf0);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0x8620,PTR__gleSetEnable_VERTEX_PROGRAM_ARB_00110cec);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0x8642,PTR__gleSetEnable_VERTEX_PROGRAM_POINT_SIZE_ARB_00110ce8);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0x8643,PTR__gleSetEnable_VERTEX_PROGRAM_TWO_SIDE_ARB_00110ce4);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0x8804,PTR__gleSetEnable_FRAGMENT_PROGRAM_ARB_00110ce0);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0x8200,PTR__gleSetEnable_TEXT_FRAGMENT_SHADER_ATI_00110cdc);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0x8458,PTR__gleSetEnable_COLOR_SUM_00110cd8);
  ((int (*)())_gleAddEnableHashFunc)(puVar3,0x8910,PTR__gleSetEnable_STENCIL_TEST_TWO_SIDE_EXT_00110cd4);
  uVar4 = ((int (*)())_gleAddEnableHashFunc)(puVar3,0x8890,PTR__gleSetEnable_DEPTH_BOUNDS_TEST_EXT_00110cd0);
  return uVar4;
}

/* _gleAddEnableHashFunc @ 0x3c04 (124 bytes) */
int _gleAddEnableHashFunc(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  undefined4 param_3;
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = (param_2 & 0x3ff) * 0x10;
  iVar5 = iVar6 + param_1;
  if (*(int *)(iVar6 + param_1) == 0) {
    *(uint *)(iVar6 + param_1) = param_2;
    *(undefined4 *)(iVar5 + 8) = 0;
  }
  else {
    puVar3 = (undefined4 *)_malloc(0x10);
    uVar1 = *(undefined4 *)(iVar6 + param_1);
    uVar4 = *(undefined4 *)(iVar5 + 8);
    uVar2 = *(undefined4 *)(iVar5 + 4);
    *(uint *)(iVar6 + param_1) = param_2;
    *(undefined4 **)(iVar5 + 8) = puVar3;
    *puVar3 = uVar1;
    puVar3[1] = uVar2;
    puVar3[2] = uVar4;
  }
  *(undefined4 *)(iVar5 + 4) = param_3;
  return;
}

/* _gleInitializeContext @ 0x3c80 (532 bytes) */
int _gleInitializeContext(param_1)
  int param_1;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined2 *puVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0x13;
  *(undefined4 *)(param_1 + 0x4730) = 0;
  *(undefined4 *)(param_1 + 0x471c) = 0;
  puVar2 = (undefined4 *)(param_1 + 0x310);
  *(undefined4 *)(param_1 + 0x4720) = 0;
  *(undefined4 *)(param_1 + 0x4724) = 0;
  *(undefined4 *)(param_1 + 0x4728) = 0;
  *(undefined4 *)(param_1 + 0x472c) = 0;
  do {
    *puVar2 = 0;
    puVar1 = PTR__gle_globals_struct_00112070;
    puVar2 = puVar2 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  *(undefined1 *)(param_1 + 0x7582) = *(undefined1 *)(*(int *)(param_1 + 0x468c) + 0x25);
  *(undefined **)(param_1 + 0x4674) = puVar1;
  *(undefined4 *)(param_1 + 0x467c) = 0x3463a223;
  ((void (*)())_gleNullMemoryPointers)(param_1);
  iVar5 = ((int (*)())_gleAllocVertexMachine)(param_1,0x24);
  if ((iVar5 == 0) && (iVar5 = ((int (*)())_gleAllocMaterials)(param_1), iVar5 == 0)) {
    ((void (*)())_gleShareEnableHashTable)(param_1);
    iVar5 = param_1 + 0x7468;
    *(undefined4 *)(param_1 + 0x747c) = 0;
    *(undefined4 *)(param_1 + 0x7478) = 0;
    *(int *)(param_1 + 0x7474) = iVar5;
    *(int *)(param_1 + 0x7470) = iVar5;
    *(int *)(param_1 + 0x746c) = iVar5;
    *(int *)(param_1 + 0x7468) = iVar5;
    *(undefined4 *)(param_1 + 0x7454) = 0;
    *(undefined4 *)(param_1 + 0x7464) = 0;
    *(undefined4 *)(param_1 + 0x7458) = 0;
    *(undefined4 *)(param_1 + 0x745c) = 0;
    *(undefined4 *)(param_1 + 0x7460) = 0;
    iVar5 = ((int (*)())_gleAllocVertexArrays)(param_1);
    if ((iVar5 == 0) && (iVar5 = ((int (*)())_gleAllocFunctions)(param_1), iVar5 == 0)) {
      ((void (*)())_gleInitConstants)(param_1);
      iVar4 = ((int (*)())_gleVecAlloc)(0x32c0);
      *(int *)(param_1 + 0x4678) = iVar4;
      if (iVar4 != 0) {
        *(undefined1 *)(param_1 + 0x4692) = 1;
        *(undefined1 *)(param_1 + 0x4690) = 1;
        *(ushort *)(param_1 + 0x3118) = 0x405 - (ushort)(*(char *)(param_1 + 0x7582) == '\0');
        iVar5 = 3;
        *(int *)(param_1 + 0x337c) = param_1 + 0x4734;
        *(undefined2 *)(param_1 + 0x311a) = *(undefined2 *)(param_1 + 0x3118);
        puVar3 = (undefined2 *)(param_1 + 0x311c);
        *(undefined1 *)(param_1 + 0x4694) = 0;
        *(undefined1 *)(param_1 + 0x4691) = 0;
        *(undefined1 *)(param_1 + 0x4693) = 0;
        do {
          *puVar3 = 0;
          puVar3 = puVar3 + 1;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
        ((void (*)())_gleInitGLDState)(param_1 + 0x360);
        ((void (*)())_gleInitGLIState)(param_1);
        ((void (*)())_gleInitDerivedState)(param_1);
        ((void (*)())_gleInitTextureState)(param_1);
        ((void (*)())_gleInitPipelineProgramState)(param_1);
        ((void (*)())_gleInitShaderState)(param_1);
        ((void (*)())_gleInitBufferState)(param_1);
        ((void (*)())_glePPEmulatorInitialize)(param_1);
        ((void (*)())_gleInitVertexArrayState)(param_1);
        ((void (*)())_gleInitFenceMachine)(param_1);
        ((void (*)())_gleInitQueryMachine)(param_1);
        ((void (*)())_gleInitDrawPixelsObject)(param_1);
        _gleUpdatePrimitiveData(param_1);
        _gleUpdateState(param_1);
        *(undefined4 *)(param_1 + 0x7590) = 0;
        return 0;
      }
    }
  }
  _gleTerminateContext(param_1);
  return iVar5;
}

/* _gleNullMemoryPointers @ 0x3e94 (416 bytes) */
void _gleNullMemoryPointers(param_1)
  int param_1;
{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  puVar1 = (undefined4 *)(param_1 + 0x4dd0);
  *(undefined4 *)(param_1 + 0x4854) = 0;
  iVar2 = 1;
  *(undefined4 *)(param_1 + 0x4678) = 0;
  do {
    iVar2 = iVar2 + -1;
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  } while (-1 < iVar2);
  *(undefined4 *)(param_1 + 0x5418) = 0;
  *(undefined4 *)(param_1 + 0x4dd8) = 0;
  *(undefined4 *)(param_1 + 0x4850) = 0;
  *(undefined4 *)(param_1 + 0x49ac) = 0;
  *(undefined4 *)(param_1 + 0x49b4) = 0;
  *(undefined4 *)(param_1 + 0x49b8) = 0;
  *(undefined4 *)(param_1 + 0x5088) = 0;
  *(undefined4 *)(param_1 + 0x5094) = 0;
  *(undefined4 *)(param_1 + 0x50a0) = 0;
  *(undefined4 *)(param_1 + 0x48a0) = 0;
  *(undefined4 *)(param_1 + 0x48a8) = 0;
  *(undefined4 *)(param_1 + 0x48c0) = 0;
  *(undefined4 *)(param_1 + 0x48b0) = 0;
  *(undefined4 *)(param_1 + 0x48b8) = 0;
  *(undefined4 *)(param_1 + 0x49d0) = 0;
  *(undefined4 *)(param_1 + 0x49d8) = 0;
  iVar2 = param_1;
  do {
    *(undefined4 *)(iVar2 + 0x5420) = 0;
    *(undefined4 *)(iVar2 + 0x5428) = 0;
    iVar2 = iVar2 + 4;
  } while (iVar2 <= param_1 + 4);
  iVar2 = param_1 + 0x10000;
  iVar3 = 0;
  *(undefined4 *)(param_1 + 0x5430) = 0;
  if (*(char *)(param_1 + 0x85a4) != '\0') {
    do {
      *(undefined4 *)(iVar2 + -0x7788) = 0;
      iVar3 = iVar3 + 1;
      *(undefined4 *)(iVar2 + -0x7784) = 0;
      iVar2 = iVar2 + 0x2e0;
    } while (iVar3 < (int)(uint)*(byte *)(param_1 + 0x85a4));
  }
  iVar3 = 0;
  *(undefined4 *)(param_1 + 0x7484) = 0;
  *(undefined4 *)(param_1 + 0x4a60) = 0;
  *(undefined4 *)(param_1 + 0x4a64) = 0;
  iVar2 = param_1;
  do {
    puVar1 = (undefined4 *)(iVar2 + 0x5154);
    iVar4 = 5;
    do {
      *puVar1 = 0;
      puVar1 = puVar1 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    iVar3 = iVar3 + 1;
    iVar2 = iVar2 + 0x14;
  } while (iVar3 < 0x10);
  iVar2 = 0x10;
  puVar1 = (undefined4 *)(param_1 + 0x52d4);
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  iVar3 = 3;
  iVar2 = param_1 + 0x52b0;
  do {
    *(undefined4 *)(iVar2 + 0xc) = 0;
    *(undefined4 *)(iVar2 + 0x18) = 0;
    iVar2 = iVar2 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  iVar3 = 5;
  iVar2 = param_1;
  do {
    *(undefined4 *)(iVar2 + 0x5294) = 0;
    *(undefined4 *)(iVar2 + 0x52a8) = 0;
    iVar2 = iVar2 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  iVar2 = 0;
  *(undefined4 *)(param_1 + 0x744c) = 0;
  *(undefined4 *)(param_1 + 0x48f4) = 0;
  *(undefined4 *)(param_1 + 0x7448) = 0;
  if (*(char *)(param_1 + 0x85a4) != '\0') {
    puVar1 = (undefined4 *)(param_1 + 0x8880);
    do {
      *puVar1 = 0;
      iVar2 = iVar2 + 1;
      puVar1 = puVar1 + 0xb8;
    } while (iVar2 < (int)(uint)*(byte *)(param_1 + 0x85a4));
    return;
  }
  return;
}

/* _gleAllocVertexMachine @ 0x4034 (228 bytes) */
int _gleAllocVertexMachine(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  
  iVar8 = param_2 + param_2 + 0xc;
  uVar4 = ((int (*)())_gleDCBAlloc)((iVar8 * 0x42 + (iVar8 + 0x1f >> 5)) * 4 + 0x200);
  uVar6 = uVar4 + iVar8 * 0x100 + 0x200;
  iVar3 = uVar4 + 0x200;
  iVar5 = iVar3 + iVar8 * 0x100;
  iVar7 = iVar3 + param_2 * 0x100;
  *(int *)(param_1 + 0x4864) = iVar3 + (param_2 + 0xc) * 0x100;
  *(int *)(param_1 + 0x4874) = iVar5 + iVar8 * 4;
  *(int *)(param_1 + 0x30b0) = iVar5 + iVar8 * 8;
  *(int *)(param_1 + 0x4858) = iVar3;
  *(int *)(param_1 + 0x485c) = iVar7;
  *(int *)(param_1 + 0x4878) = param_2;
  *(int *)(param_1 + 0x4854) = iVar3;
  *(int *)(param_1 + 0x4860) = iVar7;
  *(int *)(param_1 + 0x4870) = iVar5;
  uVar1 = *(undefined4 *)(param_1 + 0x24);
  uVar2 = *(undefined4 *)(param_1 + 0x20);
  if (uVar4 < uVar6) {
    uVar6 = (uVar6 - uVar4) + 0xff >> 8;
    do {
      *(undefined4 *)(uVar4 + 0x20) = uVar2;
      *(undefined4 *)(uVar4 + 0x24) = uVar2;
      *(undefined4 *)(uVar4 + 0x28) = uVar2;
      *(undefined4 *)(uVar4 + 0x2c) = uVar1;
      uVar4 = uVar4 + 0x100;
      uVar6 = uVar6 - 1;
    } while (uVar6 != 0);
  }
  return 0;
}

/* _gleAllocMaterials @ 0x4118 (60 bytes) */
int _gleAllocMaterials(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)(param_1 + 0x4dd0);
  iVar2 = param_1 + 0x2c20;
  iVar1 = 1;
  do {
    iVar1 = iVar1 + -1;
    *piVar3 = iVar2;
    *(undefined4 *)(iVar2 + 0x238) = 0;
    piVar3 = piVar3 + 1;
    *(undefined4 *)(iVar2 + 0x23c) = 0;
    *(undefined4 *)(iVar2 + 0x1e0) = 0;
    iVar2 = iVar2 + 0x240;
  } while (-1 < iVar1);
  *(undefined4 *)(param_1 + 0x4dd8) = 0;
  return 0;
}

/* _gleShareEnableHashTable @ 0x4154 (32 bytes) */
void _gleShareEnableHashTable(param_1)
  int param_1;
{
  *(undefined4 *)(param_1 + 0x4850) = _gle_enable_hash_table;
  return;
}

/* _gleAllocVertexArrays @ 0x4174 (192 bytes) */
int _gleAllocVertexArrays(param_1)
  int param_1;
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = ((int (*)())_gleInitFuncCache)();
  *(int *)(param_1 + 0x49b4) = iVar1;
  uVar2 = 0x2720;
  if (iVar1 != 0) {
    iVar1 = ((int (*)())_gleInitFuncCache)();
    *(int *)(param_1 + 0x49b8) = iVar1;
    uVar2 = 0x2720;
    if (iVar1 != 0) {
      *(undefined4 *)(param_1 + 0x497c) = 0x1f;
      *(undefined4 *)(param_1 + 0x4980) = 3;
      *(undefined4 *)(param_1 + 0x49c4) = 0;
      uVar2 = 0;
      *(undefined4 *)(param_1 + 0x49b0) = 0xaeee;
      *(undefined2 *)(param_1 + 0x49bc) = 0x14;
      *(undefined2 *)(param_1 + 0x49c0) = 6;
      *(undefined2 *)(param_1 + 0x49c2) = 1;
      *(undefined4 *)(param_1 + 0x4984) = 0;
      *(undefined4 *)(param_1 + 0x4988) = 0;
      *(undefined4 *)(param_1 + 0x498c) = 0;
      *(undefined2 *)(param_1 + 0x4990) = 0;
      *(undefined2 *)(param_1 + 0x4992) = 0;
      *(undefined4 *)(param_1 + 0x4994) = 0;
      *(undefined4 *)(param_1 + 0x499c) = 0;
      *(undefined4 *)(param_1 + 0x49a0) = 0;
      *(undefined4 *)(param_1 + 0x49a4) = 0;
      *(undefined4 *)(param_1 + 0x49a8) = 0;
      *(undefined4 *)(param_1 + 0x49ac) = 0;
      *(undefined2 *)(param_1 + 0x49be) = 1;
    }
  }
  return uVar2;
}

/* _gleInitFuncCache @ 0x4234 (140 bytes) */
int _gleInitFuncCache()
{
  int iVar1;
  int iVar2;
  
  iVar1 = ((int (*)())_gleDCBAlloc)(0x24);
  iVar2 = 0;
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x1c) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x20) = 0x4e800020;
    *(int *)(iVar1 + 4) = iVar1;
    *(int *)iVar1 = iVar1;
    *(undefined4 *)(iVar1 + 8) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0xc) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x10) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x14) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x18) = 0xffffffff;
    (*(code *)_glePushInstructions)(1,iVar1 + 0x20);
    iVar2 = iVar1;
  }
  return iVar2;
}

/* _gleAllocFunctions @ 0x42c0 (452 bytes) */
int _gleAllocFunctions(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = ((int (*)())_gleInitFuncCache)();
  uVar1 = 0x2720;
  *(int *)(param_1 + 0x5088) = iVar2;
  if (iVar2 != 0) {
    iVar2 = ((int (*)())_gleInitFuncCache)();
    uVar1 = 0x2720;
    *(int *)(param_1 + 0x5094) = iVar2;
    if (iVar2 != 0) {
      iVar2 = ((int (*)())_gleInitFuncCache)();
      uVar1 = 0x2720;
      *(int *)(param_1 + 0x50a0) = iVar2;
      if (iVar2 != 0) {
        iVar2 = ((int (*)())_gleInitFuncCache)();
        uVar1 = 0x2720;
        *(int *)(param_1 + 0x49d0) = iVar2;
        if (iVar2 != 0) {
          iVar2 = ((int (*)())_gleInitFuncCache)();
          uVar1 = 0x2720;
          *(int *)(param_1 + 0x49d8) = iVar2;
          if (iVar2 != 0) {
            iVar2 = ((int (*)())_gleInitFuncCache)();
            uVar1 = 0x2720;
            *(int *)(param_1 + 0x48a0) = iVar2;
            if (iVar2 != 0) {
              iVar2 = ((int (*)())_gleInitFuncCache)();
              uVar1 = 0x2720;
              *(int *)(param_1 + 0x48a8) = iVar2;
              if (iVar2 != 0) {
                iVar2 = ((int (*)())_gleInitFuncCache)();
                uVar1 = 0x2720;
                *(int *)(param_1 + 0x48c0) = iVar2;
                if (iVar2 != 0) {
                  iVar2 = ((int (*)())_gleInitFuncCache)();
                  uVar1 = 0x2720;
                  *(int *)(param_1 + 0x48b0) = iVar2;
                  if (iVar2 != 0) {
                    iVar2 = ((int (*)())_gleInitFuncCache)();
                    uVar1 = 0x2720;
                    *(int *)(param_1 + 0x48b8) = iVar2;
                    if (iVar2 != 0) {
                      *(undefined2 *)(param_1 + 0x48bc) = 0x10;
                      *(undefined2 *)(param_1 + 0x48be) = 1;
                      *(undefined2 *)(param_1 + 0x508c) = 0x10;
                      *(undefined2 *)(param_1 + 0x508e) = 1;
                      *(undefined2 *)(param_1 + 0x5098) = 0x10;
                      *(undefined2 *)(param_1 + 0x509a) = 1;
                      *(undefined2 *)(param_1 + 0x50a4) = 0x10;
                      *(undefined2 *)(param_1 + 0x50a6) = 1;
                      *(undefined2 *)(param_1 + 0x49d4) = 0x10;
                      *(undefined2 *)(param_1 + 0x49d6) = 1;
                      *(undefined2 *)(param_1 + 0x49dc) = 0x10;
                      *(undefined2 *)(param_1 + 0x49de) = 1;
                      *(undefined2 *)(param_1 + 0x48a4) = 0x10;
                      *(undefined2 *)(param_1 + 0x48a6) = 1;
                      *(undefined2 *)(param_1 + 0x48ac) = 0x10;
                      *(undefined2 *)(param_1 + 0x48ae) = 1;
                      *(undefined2 *)(param_1 + 0x48b4) = 0x10;
                      *(undefined4 *)(param_1 + 0x509c) = 0;
                      *(int *)(param_1 + 0x5060) = *(int *)(param_1 + 0x5088) + 0x20;
                      *(int *)(param_1 + 0x5064) = *(int *)(param_1 + 0x5094) + 0x20;
                      *(int *)(param_1 + 0x5068) = *(int *)(param_1 + 0x50a0) + 0x20;
                      *(int *)(param_1 + 0x49c8) = *(int *)(param_1 + 0x49d0) + 0x20;
                      *(int *)(param_1 + 0x49cc) = *(int *)(param_1 + 0x49d8) + 0x20;
                      *(int *)(param_1 + 0x4888) = *(int *)(param_1 + 0x48a0) + 0x20;
                      *(undefined4 *)(param_1 + 0x5084) = 0;
                      *(undefined4 *)(param_1 + 0x5090) = 0;
                      *(undefined2 *)(param_1 + 0x48b6) = 1;
                      *(int *)(param_1 + 0x488c) = iVar2 + 0x20;
                      uVar1 = 0;
                      iVar2 = *(int *)(param_1 + 0x48b0) + 0x20;
                      *(int *)(param_1 + 0x4890) = *(int *)(param_1 + 0x48a8) + 0x20;
                      *(int *)(param_1 + 0x489c) = iVar2;
                      *(int *)(param_1 + 0x4898) = iVar2;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return uVar1;
}

/* _gleInitConstants @ 0x4484 (192 bytes) */
void _gleInitConstants(param_1)
  int param_1;
{
  float fVar1;
  undefined *puVar2;
  undefined *puVar3;
  
  if ((*(uint *)PTR__gle_processor_0011204c & 0x10) != 0) {
    ((void (*)())_gleInitVectorConstants)(param_1);
  }
  puVar2 = PTR__gleFlushAndSubmit_00112050;
  *(undefined4 *)(param_1 + 0x24) = 0x3f800000;
  *(undefined **)(param_1 + 0x28) = puVar2;
  fVar1 = FLOAT_00108ebc;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(float *)(param_1 + 0x34) = fVar1;
  puVar3 = PTR__gle_rtc_toc_struct_0011205c;
  puVar2 = PTR__gleNoop_00110a20;
  fVar1 = FLOAT_00108ec0;
  *(undefined4 *)(param_1 + 0x30) = 0x3f000000;
  *(undefined4 *)(param_1 + 0xec) = 0;
  *(undefined **)(param_1 + 0x2c) = puVar3;
  *(float *)(param_1 + 0x38) = fVar1;
  *(undefined4 *)(param_1 + 0x3c) = 0xbf800000;
  *(undefined **)(param_1 + 0xdc) = puVar2;
  *(undefined4 *)(param_1 + 0xe8) = 0x43300000;
  *(undefined **)(param_1 + 0xd8) = puVar2;
  *(undefined4 *)(param_1 + 0xe0) = 0x43300000;
  *(undefined4 *)(param_1 + 0xe4) = 0;
  return;
}

/* _gleInitVectorConstants @ 0x4544 (56 bytes) */
void _gleInitVectorConstants(param_1)
  int param_1;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar4 = _UNK_00113e4c;
  uVar3 = _UNK_00113e48;
  uVar2 = _UNK_00113e44;
  puVar1 = (undefined4 *)(param_1 + 0x10U & 0xfffffff0);
  *puVar1 = _DAT_00113e40;
  puVar1[1] = uVar2;
  puVar1[2] = uVar3;
  puVar1[3] = uVar4;
  return;
}

/* _gleInitGLDState @ 0x457c (3076 bytes) */
void _gleInitGLDState(param_1)
  int param_1;
{
  float fVar1;
  float fVar2;
  undefined2 uVar3;
  undefined2 *puVar4;
  undefined1 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  *(undefined1 *)(param_1 + 0x2d66) = 0;
  *(undefined2 *)(param_1 + 0x2d64) = 0x207;
  *(undefined2 *)(param_1 + 0x2d82) = 0x8006;
  *(undefined2 *)(param_1 + 0x2dc4) = 0x201;
  *(undefined4 *)(param_1 + 0x2d88) = 0x3ff00000;
  *(undefined4 *)(param_1 + 0x2d8c) = 0;
  *(undefined2 *)(param_1 + 0x2d68) = 1;
  *(undefined2 *)(param_1 + 0x2d6c) = 1;
  *(undefined2 *)(param_1 + 0x2d80) = 0x8006;
  *(undefined4 *)(param_1 + 0x2d60) = 0;
  *(undefined2 *)(param_1 + 0x2d6a) = 0;
  *(undefined2 *)(param_1 + 0x2d6e) = 0;
  *(undefined4 *)(param_1 + 0x2d70) = 0;
  *(undefined4 *)(param_1 + 0x2d74) = 0;
  *(undefined4 *)(param_1 + 0x2d78) = 0;
  *(undefined4 *)(param_1 + 0x2d7c) = 0;
  *(undefined1 *)(param_1 + 0x2d84) = 0;
  *(undefined4 *)(param_1 + 0x2d90) = 0;
  *(undefined4 *)(param_1 + 0x2d94) = 0;
  *(undefined4 *)(param_1 + 0x2d98) = 0;
  *(undefined4 *)(param_1 + 0x2d9c) = 0;
  *(undefined4 *)(param_1 + 0x2da0) = 0;
  *(undefined4 *)(param_1 + 0x2da4) = 0;
  *(undefined4 *)(param_1 + 0x2da8) = 0;
  *(undefined2 *)(param_1 + 0x2e04) = 0x800;
  *(undefined2 *)(param_1 + 0x2e06) = 0x8452;
  *(undefined2 *)(param_1 + 0x2e08) = 0x855c;
  *(undefined1 *)(param_1 + 0x2ddc) = 1;
  *(undefined2 *)(param_1 + 0x2e1c) = 0x1100;
  *(undefined2 *)(param_1 + 0x2e28) = 0xffff;
  *(undefined2 *)(param_1 + 0x2e30) = 0x1503;
  *(undefined4 *)(param_1 + 0x2e3c) = 0xffffffff;
  *(undefined2 *)(param_1 + 0x2e0c) = 0x1100;
  *(undefined2 *)(param_1 + 0x2e0e) = 0x1100;
  *(undefined2 *)(param_1 + 0x2e10) = 0x1100;
  *(undefined2 *)(param_1 + 0x2e12) = 0x1100;
  *(undefined2 *)(param_1 + 0x2e14) = 0x1100;
  *(undefined2 *)(param_1 + 0x2e16) = 0x1100;
  *(undefined2 *)(param_1 + 0x2e18) = 0x1100;
  *(undefined2 *)(param_1 + 0x2e1a) = 0x1100;
  *(undefined4 *)(param_1 + 0x2dac) = 0;
  *(undefined4 *)(param_1 + 0x2db0) = 0;
  *(undefined4 *)(param_1 + 0x2db4) = 0;
  *(undefined1 *)(param_1 + 0x2dc8) = 0;
  *(undefined1 *)(param_1 + 0x2dc9) = 0;
  *(undefined4 *)(param_1 + 0x2de0) = 0;
  *(undefined4 *)(param_1 + 0x2de4) = 0;
  *(undefined4 *)(param_1 + 0x2de8) = 0;
  *(undefined4 *)(param_1 + 0x2dec) = 0;
  *(undefined4 *)(param_1 + 0x2df0) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x2df4) = 0;
  *(undefined4 *)(param_1 + 0x2df8) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x2dfc) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x2e00) = 0;
  *(undefined1 *)(param_1 + 0x2e0a) = 0;
  *(undefined1 *)(param_1 + 0x2e0b) = 0;
  *(undefined4 *)(param_1 + 0x2e20) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x2e24) = 1;
  *(undefined4 *)(param_1 + 0x2e34) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x2e38) = 0xffffffff;
  *(undefined1 *)(param_1 + 0x2e40) = 1;
  *(undefined1 *)(param_1 + 0x2e41) = 1;
  *(undefined1 *)(param_1 + 0x2e42) = 1;
  *(undefined1 *)(param_1 + 0x2e43) = 1;
  *(undefined1 *)(param_1 + 0x2e44) = 1;
  *(undefined4 *)(param_1 + 0x2e80) = 4;
  *(undefined4 *)(param_1 + 0x2e64) = 4;
  *(undefined1 *)(param_1 + 0x2e2c) = 0;
  *(undefined1 *)(param_1 + 0x2e2d) = 0;
  *(undefined1 *)(param_1 + 0x2e33) = 0;
  *(undefined1 *)(param_1 + 0x2e32) = 0;
  *(undefined4 *)(param_1 + 0x2e48) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x2e4c) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x2e50) = 0;
  *(undefined4 *)(param_1 + 0x2e54) = 0;
  *(undefined4 *)(param_1 + 0x2e58) = 0;
  *(undefined4 *)(param_1 + 0x2e5c) = 0;
  *(undefined4 *)(param_1 + 0x2e60) = 0;
  *(undefined1 *)(param_1 + 0x2e68) = 0;
  *(undefined1 *)(param_1 + 0x2e69) = 0;
  *(undefined1 *)(param_1 + 0x2e6a) = 0;
  *(undefined4 *)(param_1 + 0x2e6c) = 0;
  *(undefined4 *)(param_1 + 0x2e70) = 0;
  *(undefined4 *)(param_1 + 0x2e74) = 0;
  *(undefined4 *)(param_1 + 0x2e78) = 0;
  *(undefined4 *)(param_1 + 0x2e7c) = 0;
  *(undefined1 *)(param_1 + 0x2e84) = 0;
  *(undefined1 *)(param_1 + 0x2e85) = 0;
  *(undefined1 *)(param_1 + 0x2e86) = 0;
  *(undefined4 *)(param_1 + 0x2eb4) = 0;
  *(undefined4 *)(param_1 + 0x2eb0) = 0;
  *(undefined4 *)(param_1 + 0x2e8c) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x2e94) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x2e9c) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x2ea4) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x2eac) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x2e88) = 0;
  *(undefined4 *)(param_1 + 0x2e90) = 0;
  *(undefined4 *)(param_1 + 0x2e98) = 0;
  *(undefined4 *)(param_1 + 0x2ea0) = 0;
  *(undefined4 *)(param_1 + 0x2ea8) = 0;
  *(undefined4 *)(param_1 + 0x30b4) = 0;
  *(undefined **)(param_1 + 0x2ee8) = &_gle_default_pix_map_i;
  *(undefined **)(param_1 + 0x2f08) = &_gle_default_pix_map_f;
  *(undefined4 *)(param_1 + 0x2f34) = 1;
  *(undefined4 *)(param_1 + 0x2f10) = 1;
  *(undefined4 *)(param_1 + 0x2f14) = 1;
  *(undefined **)(param_1 + 0x2eec) = &_gle_default_pix_map_f;
  *(undefined4 *)(param_1 + 0x2f18) = 1;
  *(undefined **)(param_1 + 0x2ef0) = &_gle_default_pix_map_f;
  *(undefined4 *)(param_1 + 0x2f1c) = 1;
  *(undefined **)(param_1 + 0x2ef4) = &_gle_default_pix_map_f;
  *(undefined4 *)(param_1 + 0x2f20) = 1;
  *(undefined **)(param_1 + 0x2ef8) = &_gle_default_pix_map_f;
  *(undefined4 *)(param_1 + 0x2f24) = 1;
  *(undefined **)(param_1 + 0x2efc) = &_gle_default_pix_map_f;
  *(undefined4 *)(param_1 + 0x2f28) = 1;
  *(undefined **)(param_1 + 0x2f0c) = &_gle_default_pix_map_i;
  *(undefined **)(param_1 + 0x2f00) = &_gle_default_pix_map_f;
  *(undefined4 *)(param_1 + 0x2f2c) = 1;
  *(undefined **)(param_1 + 0x2f04) = &_gle_default_pix_map_f;
  *(undefined4 *)(param_1 + 0x2f30) = 1;
  *(undefined4 *)(param_1 + 0x2f48) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x2f4c) = 0;
  *(undefined4 *)(param_1 + 0x2f50) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x2f54) = 0;
  *(undefined4 *)(param_1 + 0x2f58) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x2f5c) = 0;
  *(undefined4 *)(param_1 + 0x2f60) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x2f64) = 0;
  *(undefined4 *)(param_1 + 0x2f88) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x2f94) = 0;
  *(undefined4 *)(param_1 + 0x2f98) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x2f9c) = 0;
  *(undefined4 *)(param_1 + 0x2fa0) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x2fa4) = 0;
  *(undefined4 *)(param_1 + 0x2fc8) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x2fd4) = 0;
  *(undefined4 *)(param_1 + 0x2fd8) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x2f8c) = 0;
  *(undefined4 *)(param_1 + 0x2f90) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x2fcc) = 0;
  *(undefined4 *)(param_1 + 0x2fd0) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x2fdc) = 0;
  *(undefined4 *)(param_1 + 0x2fe0) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x2fe4) = 0;
  *(undefined4 *)(param_1 + 0x3030) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x303c) = 0;
  *(undefined4 *)(param_1 + 0x3040) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x3044) = 0;
  *(undefined4 *)(param_1 + 0x3048) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x304c) = 0;
  *(undefined4 *)(param_1 + 0x2ffc) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x3090) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x309c) = 0;
  *(undefined4 *)(param_1 + 0x30a0) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x30a4) = 0;
  *(undefined4 *)(param_1 + 0x30a8) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x30ac) = 0;
  *(undefined4 *)(param_1 + 0x3008) = 0;
  *(undefined4 *)(param_1 + 0x300c) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x3010) = 0;
  *(undefined4 *)(param_1 + 0x3014) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x3018) = 0;
  *(undefined4 *)(param_1 + 0x3050) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x305c) = 0;
  *(undefined4 *)(param_1 + 0x3060) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x3064) = 0;
  *(undefined4 *)(param_1 + 0x3068) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x3034) = 0;
  *(undefined4 *)(param_1 + 0x3038) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x3094) = 0;
  *(undefined4 *)(param_1 + 0x3098) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x3000) = 0;
  *(undefined4 *)(param_1 + 0x3004) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x3054) = 0;
  *(undefined4 *)(param_1 + 0x3058) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x306c) = 0;
  *(undefined4 *)(param_1 + 0x3070) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x307c) = 0;
  *(undefined4 *)(param_1 + 0x3074) = 0;
  *(undefined4 *)(param_1 + 0x3078) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x3080) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x3084) = 0;
  *(undefined4 *)(param_1 + 0x3088) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x308c) = 0;
  *(undefined4 *)(param_1 + 0x30b0) = 0;
  *(undefined2 *)(param_1 + 0x2f68) = 0x8016;
  *(undefined2 *)(param_1 + 0x2fa8) = 0x8016;
  *(undefined4 *)(param_1 + 0x2fb8) = 0;
  *(undefined4 *)(param_1 + 0x2fbc) = 0;
  *(undefined4 *)(param_1 + 0x2fc0) = 0;
  *(undefined4 *)(param_1 + 0x2fc4) = 0;
  *(undefined4 *)(param_1 + 0x2f38) = 0;
  *(undefined4 *)(param_1 + 0x2f3c) = 0;
  *(undefined4 *)(param_1 + 0x2f40) = 0;
  *(undefined4 *)(param_1 + 0x2f44) = 0;
  *(undefined4 *)(param_1 + 0x2f78) = 0;
  *(undefined4 *)(param_1 + 0x2f7c) = 0;
  *(undefined4 *)(param_1 + 0x2f80) = 0;
  *(undefined4 *)(param_1 + 0x2f84) = 0;
  puVar7 = (undefined4 *)(param_1 + 0x30e8);
  *(undefined2 *)(param_1 + 0x2fe8) = 0x8016;
  *(undefined2 *)(param_1 + 0x2f6a) = 0x1908;
  *(undefined2 *)(param_1 + 0x2faa) = 0x1908;
  *(int *)(param_1 + 0x2ff8) = param_1 + 0x18e0;
  *(undefined2 *)(param_1 + 0x2fea) = 0x1908;
  iVar9 = 0x20;
  *(undefined4 *)(param_1 + 0x2f6c) = 0;
  *(undefined4 *)(param_1 + 0x2fac) = 0;
  *(undefined4 *)(param_1 + 0x2fec) = 0;
  *(undefined4 *)(param_1 + 0x2f70) = 0;
  *(undefined4 *)(param_1 + 0x2fb0) = 0;
  *(undefined4 *)(param_1 + 0x2ff0) = 0;
  *(undefined4 *)(param_1 + 0x2f74) = 0;
  *(undefined4 *)(param_1 + 0x2fb4) = 0;
  *(undefined4 *)(param_1 + 0x2ff4) = 0;
  *(undefined4 *)(param_1 + 0x3024) = 0;
  *(undefined4 *)(param_1 + 0x3028) = 0;
  *(undefined2 *)(param_1 + 0x302c) = 0x1908;
  *(undefined1 *)(param_1 + 0x302e) = 0;
  *(undefined4 *)(param_1 + 0x2ebc) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x2ec4) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x2ecc) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x2ed4) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x2edc) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x2ee4) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x2eb8) = 0;
  *(undefined4 *)(param_1 + 0x2ec0) = 0;
  *(undefined4 *)(param_1 + 0x2ec8) = 0;
  *(undefined4 *)(param_1 + 0x2ed0) = 0;
  *(undefined4 *)(param_1 + 0x2ed8) = 0;
  *(undefined4 *)(param_1 + 12000) = 0;
  *(undefined4 *)(param_1 + 0x30b8) = 0;
  **(undefined4 **)(param_1 + 0x301c) = 0x3f800000;
  *(undefined4 *)(*(int *)(param_1 + 0x301c) + 4) = 0x3f800000;
  *(undefined4 *)(*(int *)(param_1 + 0x301c) + 8) = 0x3f800000;
  *(undefined4 *)(*(int *)(param_1 + 0x301c) + 0xc) = 0x3f800000;
  *(undefined4 *)(*(int *)(param_1 + 0x301c) + 0x10) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x301c) + 0x14) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x301c) + 0x18) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x301c) + 0x1c) = 0;
  *(undefined1 *)(param_1 + 0x3022) = 0;
  *(undefined2 *)(param_1 + 0x3020) = 0x1908;
  *(undefined1 *)(param_1 + 0x30dd) = 0;
  *(undefined2 *)(param_1 + 0x30e0) = 0;
  *(undefined2 *)(param_1 + 0x30e2) = 0x60b4;
  *(undefined1 *)(param_1 + 0x30dc) = 0;
  *(undefined4 *)(param_1 + 0x30bc) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x30c0) = 0;
  *(undefined4 *)(param_1 + 0x30c4) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x30c8) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x30cc) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x30d0) = 0;
  *(undefined4 *)(param_1 + 0x30d4) = 0;
  *(undefined4 *)(param_1 + 0x30d8) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x30e4) = 0;
  do {
    *puVar7 = 0xffffffff;
    puVar7 = puVar7 + 1;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  *(undefined2 *)(param_1 + 0x3174) = 0x901;
  *(undefined2 *)(param_1 + 0x3172) = 0x1b02;
  *(undefined2 *)(param_1 + 0x3176) = 0x405;
  *(undefined1 *)(param_1 + 0x317e) = 0;
  *(undefined4 *)(param_1 + 0x3194) = 0x1d01;
  *(undefined2 *)(0x3170 + param_1) = 0x1b02;
  *(undefined1 *)(param_1 + 0x3178) = 0;
  *(undefined1 *)(param_1 + 0x3179) = 0;
  *(undefined1 *)(param_1 + 0x317a) = 0;
  *(undefined1 *)(param_1 + 0x317b) = 0;
  *(undefined1 *)(param_1 + 0x317c) = 0;
  *(undefined1 *)(param_1 + 0x317d) = 0;
  *(undefined1 *)(param_1 + 0x3190) = 0;
  *(undefined4 *)(param_1 + 0x3168) = 0;
  *(undefined4 *)(param_1 + 0x316c) = 0;
  *(undefined4 *)(param_1 + 0x3180) = 0;
  *(undefined4 *)(param_1 + 0x3184) = 0;
  *(undefined4 *)(param_1 + 0x3188) = 0;
  *(undefined4 *)(param_1 + 0x318c) = 0;
  iVar9 = param_1;
  do {
    *(undefined2 *)(iVar9 + 0x31a0) = 0x207;
    *(undefined4 *)(iVar9 + 0x3198) = 0xffffffff;
    *(undefined4 *)(iVar9 + 0x319c) = 0;
    *(undefined2 *)(iVar9 + 0x31a2) = 0x1e00;
    *(undefined2 *)(iVar9 + 0x31a4) = 0x1e00;
    *(undefined2 *)(iVar9 + 0x31a6) = 0x1e00;
    iVar9 = iVar9 + 0x10;
  } while (iVar9 <= param_1 + 0x10);
  iVar10 = 0x10;
  *(undefined2 *)(0x31b4 + param_1 + 4) = 0x207;
  *(undefined2 *)(param_1 + 0x31be) = 0x1e00;
  *(undefined1 *)(param_1 + 0x3e90) = 1;
  ((unsigned char *)0x3e94)[param_1] = 0x0;
  *(undefined2 *)(param_1 + 0x31ba) = 0x1e00;
  *(undefined2 *)(param_1 + 0x31bc) = 0x1e00;
  *(undefined4 *)(param_1 + 0x31c0) = 0;
  *(undefined1 *)(param_1 + 0x3e91) = 0;
  *(undefined1 *)(param_1 + 0x3e92) = 0;
  *(undefined1 *)(param_1 + 0x3e93) = 0;
  *(undefined4 *)(param_1 + 0x3e8c) = 0x3f800000;
  iVar9 = param_1;
  do {
    *(undefined2 *)(iVar9 + 0x31dc) = 0x2100;
    *(undefined2 *)(iVar9 + 0x31de) = 0x2100;
    *(undefined2 *)(iVar9 + 0x31e0) = 0x1702;
    *(undefined2 *)(iVar9 + 0x31e2) = 0x8578;
    *(undefined2 *)(iVar9 + 0x31e4) = 0x8576;
    *(undefined2 *)(iVar9 + 0x31e6) = 0x1702;
    *(undefined2 *)(iVar9 + 0x31e8) = 0x8578;
    *(undefined2 *)(iVar9 + 0x31ea) = 0x8576;
    *(undefined2 *)(iVar9 + 0x31ec) = 0x300;
    *(undefined2 *)(iVar9 + 0x31ee) = 0x300;
    *(undefined2 *)(iVar9 + 0x31f0) = 0x302;
    *(undefined2 *)(iVar9 + 0x31f2) = 0x302;
    *(undefined2 *)(iVar9 + 0x31f4) = 0x302;
    *(undefined2 *)(iVar9 + 0x31f6) = 0x302;
    *(undefined4 *)(iVar9 + 0x31f8) = 0x3f800000;
    *(undefined4 *)(iVar9 + 0x31fc) = 0x3f800000;
    *(undefined4 *)(iVar9 + 0x3200) = 0;
    *(undefined2 *)(iVar9 + 0x3204) = 0;
    *(undefined2 *)(iVar9 + 0x320a) = 0x84c0;
    *(undefined4 *)(iVar9 + 0x321c) = 0;
    *(undefined4 *)(iVar9 + 0x3220) = 0;
    *(undefined4 *)(iVar9 + 0x3224) = 0xbf800000;
    *(undefined4 *)(iVar9 + 0x3228) = 0x3f800000;
    *(undefined4 *)(iVar9 + 0x322c) = 0;
    *(undefined4 *)(iVar9 + 0x3230) = 0;
    *(undefined4 *)(iVar9 + 0x3234) = 0x3f800000;
    *(undefined4 *)(iVar9 + 0x3238) = 0x3f800000;
    *(undefined4 *)(iVar9 + 0x323c) = 0;
    *(undefined2 *)(iVar9 + 0x3210) = 0x202;
    *(undefined2 *)(iVar9 + 0x3212) = 0x202;
    *(undefined2 *)(iVar9 + 0x3214) = 0x202;
    *(undefined2 *)(iVar9 + 0x3216) = 0x202;
    *(undefined2 *)(iVar9 + 0x320c) = 0x8536;
    *(undefined2 *)(iVar9 + 0x31d8) = 0x2100;
    *(undefined4 *)(iVar9 + 0x31c4) = 0;
    *(undefined4 *)(iVar9 + 0x31c8) = 0;
    *(undefined4 *)(iVar9 + 0x31cc) = 0;
    *(undefined4 *)(iVar9 + 0x31d0) = 0;
    *(undefined4 *)(iVar9 + 0x31d4) = 0;
    iVar9 = iVar9 + 0x7c;
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  iVar10 = 8;
  iVar9 = param_1;
  do {
    *(undefined2 *)(iVar9 + 0x3988) = 0x2400;
    *(undefined4 *)(iVar9 + 0x398c) = 0x3f800000;
    *(undefined4 *)(iVar9 + 0x3990) = 0;
    *(undefined4 *)(iVar9 + 0x3994) = 0;
    *(undefined4 *)(iVar9 + 0x3998) = 0;
    *(undefined4 *)(iVar9 + 0x399c) = 0x3f800000;
    *(undefined4 *)(iVar9 + 0x39a0) = 0;
    *(undefined4 *)(iVar9 + 0x39a4) = 0;
    *(undefined4 *)(iVar9 + 0x39a8) = 0;
    *(undefined1 *)(iVar9 + 0x3a18) = 0;
    *(undefined2 *)(iVar9 + 0x39ac) = 0x2400;
    *(undefined4 *)(iVar9 + 0x39b0) = 0;
    *(undefined4 *)(iVar9 + 0x39b4) = 0x3f800000;
    *(undefined4 *)(iVar9 + 0x39b8) = 0;
    *(undefined4 *)(iVar9 + 0x39bc) = 0;
    *(undefined4 *)(iVar9 + 0x39c0) = 0;
    *(undefined4 *)(iVar9 + 0x39c4) = 0x3f800000;
    *(undefined4 *)(iVar9 + 0x39c8) = 0;
    *(undefined4 *)(iVar9 + 0x39cc) = 0;
    *(undefined1 *)(iVar9 + 0x3a19) = 0;
    *(undefined2 *)(iVar9 + 0x39d0) = 0x2400;
    *(undefined4 *)(iVar9 + 0x39d4) = 0;
    *(undefined4 *)(iVar9 + 0x39d8) = 0;
    *(undefined4 *)(iVar9 + 0x39dc) = 0;
    *(undefined4 *)(iVar9 + 0x39e0) = 0;
    *(undefined4 *)(iVar9 + 0x39e4) = 0;
    *(undefined4 *)(iVar9 + 0x39e8) = 0;
    *(undefined4 *)(iVar9 + 0x39ec) = 0;
    *(undefined4 *)(iVar9 + 0x39f0) = 0;
    *(undefined1 *)(iVar9 + 0x3a1a) = 0;
    *(undefined2 *)(iVar9 + 0x39f4) = 0x2400;
    *(undefined4 *)(iVar9 + 0x39f8) = 0;
    *(undefined4 *)(iVar9 + 0x39fc) = 0;
    *(undefined4 *)(iVar9 + 0x3a00) = 0;
    *(undefined4 *)(iVar9 + 0x3a04) = 0;
    *(undefined4 *)(iVar9 + 0x3a08) = 0;
    *(undefined4 *)(iVar9 + 0x3a0c) = 0;
    *(undefined4 *)(iVar9 + 0x3a10) = 0;
    *(undefined4 *)(iVar9 + 0x3a14) = 0;
    *(undefined1 *)(iVar9 + 0x3a1b) = 0;
    iVar9 = iVar9 + 0x94;
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  *(undefined2 *)(param_1 + 0x24a8) = 0x6096;
  *(undefined1 *)(param_1 + 0x24ac) = 0;
  *(undefined2 *)(param_1 + 0x24aa) = 0x6098;
  *(undefined4 *)(param_1 + 0x24a0) = 1;
  iVar10 = 0x17;
  *(undefined1 *)(param_1 + 0x24ad) = 0;
  *(undefined1 *)(param_1 + 0x24ae) = 0;
  *(undefined4 *)(param_1 + 0x24a4) = 0x3f800000;
  ((int (*)())_gleMakeIdentityMatrix)(param_1 + 0x2460);
  iVar8 = param_1 + 0x1e60;
  iVar9 = param_1 + 0x1860;
  do {
    ((int (*)())_gleMakeIdentityMatrix)(iVar9);
    ((int (*)())_gleMakeIdentityMatrix)(iVar8);
    iVar10 = iVar10 + -1;
    iVar8 = iVar8 + 0x40;
    iVar9 = iVar9 + 0x40;
  } while (-1 < iVar10);
  *(undefined4 *)(param_1 + 0x3e28) = 0;
  iVar10 = 6;
  iVar9 = param_1;
  do {
    *(undefined4 *)(iVar9 + 0x3e2c) = 0;
    *(undefined4 *)(iVar9 + 0x3e30) = 0;
    *(undefined4 *)(iVar9 + 0x3e34) = 0;
    *(undefined4 *)(iVar9 + 0x3e38) = 0;
    fVar1 = FLOAT_00108f80;
    iVar9 = iVar9 + 0x10;
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  *(undefined2 *)(param_1 + 0x2d44) = 0x408;
  *(undefined1 *)(param_1 + 0x2d4e) = 0;
  *(undefined2 *)(param_1 + 0x2d46) = 0x1602;
  iVar10 = 8;
  *(undefined2 *)(param_1 + 0x2d48) = 0x81f9;
  *(undefined4 *)(param_1 + 0x2d40) = 0;
  *(undefined1 *)(param_1 + 0x2d4a) = 0;
  *(undefined1 *)(param_1 + 0x2d4d) = 0;
  *(undefined1 *)(param_1 + 0x2d4c) = 0;
  *(undefined1 *)(param_1 + 0x2d4b) = 0;
  *(float *)(param_1 + 0x24b8) = fVar1;
  *(float *)(param_1 + 0x24b0) = fVar1;
  *(float *)(param_1 + 0x24b4) = fVar1;
  *(undefined4 *)(param_1 + 0x24bc) = 0x3f800000;
  iVar9 = param_1;
  do {
    *(undefined4 *)(iVar9 + 0x24c0) = 0;
    *(undefined4 *)(iVar9 + 0x24c4) = 0;
    *(undefined4 *)(iVar9 + 0x24c8) = 0;
    *(undefined4 *)(iVar9 + 0x24cc) = 0x3f800000;
    if (iVar9 == param_1) {
      *(undefined4 *)(param_1 + 0x24d0) = 0x3f800000;
      *(undefined4 *)(param_1 + 0x24d4) = 0x3f800000;
      *(undefined4 *)(param_1 + 0x24d8) = 0x3f800000;
      *(undefined4 *)(param_1 + 0x24dc) = 0x3f800000;
      *(undefined4 *)(param_1 + 0x24e0) = 0x3f800000;
      *(undefined4 *)(param_1 + 0x24e4) = 0x3f800000;
      *(undefined4 *)(param_1 + 0x24e8) = 0x3f800000;
      *(undefined4 *)(param_1 + 0x24ec) = 0x3f800000;
    }
    else {
      *(undefined4 *)(iVar9 + 0x24d0) = 0;
      *(undefined4 *)(iVar9 + 0x24d4) = 0;
      *(undefined4 *)(iVar9 + 0x24d8) = 0;
      *(undefined4 *)(iVar9 + 0x24dc) = 0x3f800000;
      *(undefined4 *)(iVar9 + 0x24e0) = 0;
      *(undefined4 *)(iVar9 + 0x24e4) = 0;
      *(undefined4 *)(iVar9 + 0x24e8) = 0;
      *(undefined4 *)(iVar9 + 0x24ec) = 0x3f800000;
    }
    *(undefined4 *)(iVar9 + 0x24f0) = 0;
    *(undefined4 *)(iVar9 + 0x24f4) = 0;
    *(undefined4 *)(iVar9 + 0x24f8) = 0x3f800000;
    *(undefined4 *)(iVar9 + 0x24fc) = 0;
    *(undefined4 *)(iVar9 + 0x2500) = 0;
    *(undefined4 *)(iVar9 + 0x2504) = 0;
    *(undefined4 *)(iVar9 + 0x2508) = 0xbf800000;
    *(undefined4 *)(iVar9 + 0x250c) = 0xbf800000;
    *(undefined4 *)(iVar9 + 0x2510) = 0x3f800000;
    *(undefined4 *)(iVar9 + 0x2514) = 0;
    *(undefined4 *)(iVar9 + 0x2518) = 0;
    *(undefined4 *)(iVar9 + 0x251c) = 0;
    *(undefined4 *)(iVar9 + 0x2520) = 0;
    *(undefined4 *)(iVar9 + 0x2524) = 0;
    *(undefined4 *)(iVar9 + 0x2528) = 0x3f800000;
    *(undefined4 *)(iVar9 + 0x252c) = 0x3f800000;
    *(undefined4 *)(iVar9 + 0x2530) = 0x43340000;
    fVar2 = FLOAT_00108f84;
    fVar1 = FLOAT_00108f80;
    iVar9 = iVar9 + 0x80;
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  *(undefined4 *)(param_1 + 0x184c) = 0;
  *(undefined4 *)(param_1 + 0x1830) = 0;
  *(undefined4 *)(param_1 + 0x1834) = 0;
  *(undefined4 *)(param_1 + 0x1840) = 0;
  *(undefined4 *)(param_1 + 0x1844) = 0;
  *(undefined4 *)(param_1 + 0x1848) = 0;
  *(undefined4 *)(param_1 + 0x1828) = 0x3f000000;
  *(undefined4 *)(param_1 + 0x1838) = 0x3ff00000;
  *(undefined4 *)(param_1 + 0x183c) = 0;
  *(undefined4 *)(param_1 + 0x1810) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x1814) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x1818) = 0x3f000000;
  *(undefined4 *)(param_1 + 0x181c) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x1820) = 0;
  *(undefined4 *)(param_1 + 0x1824) = 0;
  *(undefined4 *)(param_1 + 0x182c) = 0;
  *(undefined4 *)(param_1 + 0x1850) = 0;
  *(undefined4 *)(param_1 + 0x1854) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x1858) = 0x3f800000;
  iVar9 = param_1;
  do {
    *(float *)(iVar9 + 0x28c0) = fVar1;
    *(float *)(iVar9 + 0x28c4) = fVar1;
    *(float *)(iVar9 + 0x28c8) = fVar1;
    *(undefined4 *)(iVar9 + 0x28cc) = 0x3f800000;
    *(float *)(iVar9 + 0x28d0) = fVar2;
    *(float *)(iVar9 + 0x28d4) = fVar2;
    *(float *)(iVar9 + 0x28d8) = fVar2;
    *(undefined4 *)(iVar9 + 0x28dc) = 0x3f800000;
    *(undefined4 *)(iVar9 + 0x28e0) = 0;
    *(undefined4 *)(iVar9 + 0x28e4) = 0;
    *(undefined4 *)(iVar9 + 0x28e8) = 0;
    *(undefined4 *)(iVar9 + 0x28ec) = 0x3f800000;
    *(undefined4 *)(iVar9 + 0x28f0) = 0;
    *(undefined4 *)(iVar9 + 0x28f4) = 0;
    *(undefined4 *)(iVar9 + 0x28f8) = 0;
    *(undefined4 *)(iVar9 + 0x28fc) = 0x3f800000;
    *(undefined4 *)(iVar9 + 0x2900) = 0;
    *(undefined4 *)(iVar9 + 0x2904) = 0;
    *(undefined4 *)(iVar9 + 0x2908) = 0;
    *(undefined4 *)(iVar9 + 0x290c) = 0x3f800000;
    iVar9 = iVar9 + 0x240;
  } while (iVar9 <= param_1 + 0x240);
  *(undefined4 *)(param_1 + 0x3e9c) = 1;
  *(undefined1 *)(param_1 + 0x3e99) = 0;
  *(undefined1 *)(param_1 + 0x3984) = 0;
  *(undefined1 *)(param_1 + 0x3e98) = 0;
  iVar9 = param_1;
  do {
    *(undefined4 *)(iVar9 + 0x3ea0) = 0;
    *(undefined4 *)(iVar9 + 0x3ea4) = 0;
    *(undefined4 *)(iVar9 + 0x3ea8) = 0;
    *(undefined4 *)(iVar9 + 0x3eac) = 0;
    iVar9 = iVar9 + 0x10;
  } while (iVar9 <= param_1 + 0x10);
  iVar9 = 0;
  do {
    iVar8 = 0;
    iVar6 = iVar9 * 0x80 + param_1;
    iVar10 = iVar6;
    do {
      iVar11 = 4;
      puVar4 = (undefined2 *)(iVar10 + 0x3ec4);
      do {
        if (iVar8 == 0) {
          uVar3 = 0x1906;
        }
        else {
          uVar3 = 0x1907;
        }
        puVar4[-1] = uVar3;
        *puVar4 = 0x8536;
        puVar4 = puVar4 + 4;
        iVar11 = iVar11 + -1;
      } while (iVar11 != 0);
      iVar8 = iVar8 + 1;
      *(undefined2 *)(iVar6 + 0x3ec0) = 0x852c;
      *(undefined2 *)(iVar6 + 0x3ec8) = 0;
      *(undefined2 *)(iVar6 + 0x3ecc) = 0x8537;
      iVar10 = iVar10 + 0x30;
      *(undefined2 *)(iVar6 + 0x3ed0) = 0;
      *(undefined2 *)(iVar6 + 0x3ed8) = 0;
      *(undefined1 *)(iVar6 + 0x3ee0) = 0;
      *(undefined1 *)(iVar6 + 0x3ee1) = 0;
      *(undefined1 *)(iVar6 + 0x3ee2) = 0;
      *(undefined2 *)(iVar6 + 0x3ee4) = 0;
      *(undefined2 *)(iVar6 + 0x3ee6) = 0;
      *(undefined2 *)(iVar6 + 0x3ee8) = 0x8530;
      *(undefined2 *)(iVar6 + 0x3eea) = 0x8530;
      *(undefined2 *)(iVar6 + 0x3eec) = 0x852e;
      iVar6 = iVar6 + 0x30;
    } while (iVar8 < 2);
    iVar9 = iVar9 + 1;
  } while (iVar9 < 8);
  iVar10 = 7;
  iVar9 = param_1 + 0x42b0;
  do {
    *(undefined2 *)(iVar9 + 0x16) = 0x1907;
    *(undefined2 *)(iVar9 + 0x18) = 0x8536;
    iVar9 = iVar9 + 8;
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  *(undefined2 *)(param_1 + 0x42cc) = 0x8532;
  ((unsigned char *)0x42c0)[param_1] = 0x1;
  *(undefined2 *)(param_1 + 0x42f6) = 0x1906;
  iVar9 = 1;
  *(undefined2 *)(param_1 + 0x42d4) = 0xb60;
  puVar5 = (undefined1 *)(param_1 + 0x4304);
  *(undefined2 *)(param_1 + 0x42f4) = 0x852e;
  *(undefined1 *)(param_1 + 0x42fc) = 0;
  *(undefined2 *)(param_1 + 0x42c6) = 0x1906;
  *(undefined2 *)(param_1 + 0x42c4) = 0xb60;
  *(undefined2 *)(param_1 + 0x42dc) = 0;
  *(undefined2 *)(param_1 + 0x42e4) = 0;
  *(undefined2 *)(param_1 + 0x42ec) = 0;
  do {
    iVar9 = iVar9 + -1;
    *puVar5 = 0;
    puVar5 = puVar5 + 8;
  } while (-1 < iVar9);
  iVar10 = 0x100;
  *(undefined1 *)(param_1 + 0x4306) = 0;
  *(int *)(param_1 + 0x4308) = param_1 + 0x10;
  *(undefined1 *)(param_1 + 0x4305) = 0;
  iVar9 = param_1;
  do {
    *(undefined4 *)(iVar9 + 0x10) = 0;
    *(undefined4 *)(iVar9 + 0x14) = 0;
    *(undefined4 *)(iVar9 + 0x18) = 0;
    *(undefined4 *)(iVar9 + 0x1c) = 0x3f800000;
    iVar9 = iVar9 + 0x10;
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  iVar10 = 0x80;
  *(undefined **)(param_1 + 0x4310) = ((unsigned char *)0x00001010) + param_1;
  iVar9 = param_1;
  do {
    *(undefined4 *)(((unsigned char *)0x00001010) + iVar9) = 0;
    *(undefined4 *)(((unsigned char *)0x00001014) + iVar9) = 0;
    *(undefined4 *)(((unsigned char *)0x00001018) + iVar9) = 0;
    *(undefined4 *)(((unsigned char *)0x0000101c) + iVar9) = 0x3f800000;
    iVar9 = iVar9 + 0x10;
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  *(undefined1 *)(param_1 + 0x4302) = 0;
  *(undefined1 *)(param_1 + 0x4300) = 1;
  *(undefined1 *)(param_1 + 0x4301) = 0;
  return;
}

/* _gleMakeIdentityMatrix @ 0x5180 (76 bytes) */
int _gleMakeIdentityMatrix(param_1)
  undefined4 *param_1;
{
  param_1[0xf] = 0x3f800000;
  param_1[0xe] = 0;
  *param_1 = 0x3f800000;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0x3f800000;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0x3f800000;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  return;
}

/* _gleInitGLIState @ 0x51cc (776 bytes) */
void _gleInitGLIState(param_1)
  int param_1;
{
  undefined1 uVar1;
  float fVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = 0;
  do {
    iVar4 = iVar5 * 0x40;
    iVar5 = iVar5 + 1;
    ((int (*)())_gleMakeIdentityMatrix)(*(int *)(param_1 + 0x4678) + iVar4);
    fVar2 = FLOAT_00108e5c;
  } while (iVar5 < 0xcb);
  iVar5 = *(int *)(param_1 + 0x4854);
  *(undefined4 *)(param_1 + 0x5144) = 0;
  iVar4 = iVar5 + -0x200;
  *(undefined4 *)(param_1 + 0x50fc) = 0;
  *(float *)(param_1 + 700) = fVar2;
  *(undefined4 *)(param_1 + 0x2c0) = 0;
  iVar6 = 8;
  *(undefined4 *)(param_1 + 0x2c4) = 0;
  *(undefined4 *)(param_1 + 0x2c8) = 0;
  *(undefined4 *)(param_1 + 0x2cc) = 0;
  *(undefined4 *)(param_1 + 0x2b0) = 0;
  *(undefined4 *)(param_1 + 0x2b4) = 0;
  *(undefined4 *)(param_1 + 0x2b8) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x2e0) = 0;
  *(undefined4 *)(param_1 + 0x2e4) = 0;
  *(undefined4 *)(param_1 + 0x2e8) = 0;
  *(undefined4 *)(param_1 + 0x2ac) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x2a0) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x2a4) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x2a8) = 0x3f800000;
  *(undefined4 *)(iVar5 + -0x1d0) = 0x3f800000;
  *(undefined4 *)(iVar5 + -500) = 0x3f800000;
  *(undefined4 *)(iVar5 + -0x1cc) = 0x3f800000;
  *(undefined4 *)(iVar5 + -0x1c8) = 0x3f800000;
  *(undefined4 *)(iVar5 + -0x1c4) = 0x3f800000;
  iVar5 = param_1;
  do {
    *(undefined4 *)(iVar5 + 0x120) = 0;
    *(undefined4 *)(iVar5 + 0x124) = 0;
    *(undefined4 *)(iVar5 + 0x128) = 0;
    *(undefined4 *)(iVar5 + 300) = 0x3f800000;
    iVar5 = iVar5 + 0x10;
    *(undefined4 *)(iVar4 + 0x80) = 0;
    *(undefined4 *)(iVar4 + 0x84) = 0;
    *(undefined4 *)(iVar4 + 0x88) = 0;
    *(undefined4 *)(iVar4 + 0x8c) = 0x3f800000;
    iVar4 = iVar4 + 0x10;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  iVar4 = 0x10;
  iVar5 = param_1;
  do {
    *(undefined4 *)(iVar5 + 0x1a0) = 0;
    *(undefined4 *)(iVar5 + 0x1a4) = 0;
    *(undefined4 *)(iVar5 + 0x1a8) = 0;
    *(undefined4 *)(iVar5 + 0x1ac) = 0x3f800000;
    iVar5 = iVar5 + 0x10;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  *(undefined4 *)(param_1 + 0x2d0) = 0x3f800000;
  iVar5 = 3;
  puVar3 = (undefined4 *)(param_1 + 0x2d4);
  do {
    *puVar3 = 0;
    fVar2 = FLOAT_00108e5c;
    puVar3 = puVar3 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  *(undefined1 *)(param_1 + 0x2ef) = 1;
  *(undefined1 *)(param_1 + 0x2ec) = 1;
  iVar5 = param_1;
  do {
    *(undefined4 *)(iVar5 + 0x2f0) = 0;
    *(float *)(iVar5 + 0x2f4) = fVar2;
    *(float *)(iVar5 + 0x2f8) = fVar2;
    iVar5 = iVar5 + 0x10;
  } while (iVar5 <= param_1 + 0x10);
  *(undefined4 *)(param_1 + 0x74cc) = 0;
  *(undefined4 *)(param_1 + 0x74d0) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x5408) = 0;
  *(undefined4 *)(param_1 + 0x5404) = 0;
  *(undefined4 *)(0x74a4 + param_1 + 4) = 1;
  *(undefined4 *)(param_1 + 0x74ac) = 0;
  *(undefined4 *)(param_1 + 0x74b0) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x74b8) = 1;
  *(undefined4 *)(param_1 + 0x74c8) = 1;
  *(undefined4 *)(param_1 + 0x74bc) = 0;
  *(undefined4 *)(param_1 + 0x74c0) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x74d8) = 0;
  *(undefined4 *)(param_1 + 0x74dc) = 0;
  *(undefined1 *)(param_1 + 0x74e0) = 0;
  *(undefined1 *)(param_1 + 0x74e1) = 0;
  *(undefined1 *)(param_1 + 0x74e2) = 0;
  *(undefined1 *)(param_1 + 0x74e3) = 0;
  *(undefined1 *)(param_1 + 0x74e4) = 0;
  *(undefined1 *)(param_1 + 0x74e5) = 0;
  *(undefined1 *)(param_1 + 0x74e6) = 0;
  *(undefined1 *)(param_1 + 0x74e7) = 0;
  *(undefined1 *)(param_1 + 0x74e8) = 0;
  *(undefined1 *)(param_1 + 0x74e9) = 0;
  *(undefined1 *)(param_1 + 0x74ea) = 0;
  *(undefined1 *)(param_1 + 0x74eb) = 0;
  *(undefined1 *)(param_1 + 0x74ec) = 0;
  *(undefined1 *)(param_1 + 0x74ed) = 0;
  *(undefined1 *)(param_1 + 0x74ee) = 0;
  *(undefined1 *)(param_1 + 0x74ef) = 0;
  *(undefined1 *)(param_1 + 0x74f0) = 0;
  *(undefined1 *)(param_1 + 0x74f1) = 0;
  *(undefined1 *)(param_1 + 0x74f2) = 0;
  _memset(param_1 + 0x74f4,0,0x40);
  _memset(param_1 + 0x7534,0,0x40);
  *(undefined4 *)(param_1 + 0x4fd8) = 0x600;
  *(undefined4 *)(param_1 + 0x4ff4) = 4;
  *(undefined4 *)(param_1 + 0x754c) = 1;
  puVar3 = (undefined4 *)(param_1 + 0x4ffc);
  *(undefined4 *)(param_1 + 0x505c) = 0;
  iVar5 = 0x18;
  *(undefined **)(param_1 + 0x5080) = ((unsigned char *)0x00001100U);
  *(undefined **)(param_1 + 0x4ff8) = &_gleStackOffsets;
  *(undefined4 *)(param_1 + 0x750c) = 1;
  *(undefined4 *)(param_1 + 0x7450) = 0;
  *(undefined4 *)(param_1 + 0x4fd4) = 0;
  *(undefined1 *)(param_1 + 0x4df8) = 0;
  *(undefined **)(param_1 + 0x507c) = ((unsigned char *)0x00001100U);
  do {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  *(undefined4 *)(param_1 + 0x4e1c) = 0x1c00;
  *(int *)(param_1 + 0x4fbc) = param_1 + 0x4e2c;
  *(undefined4 *)(param_1 + 0x757c) = 0xffffffff;
  *(undefined2 *)(param_1 + 0x48e8) = 0x1406;
  *(undefined4 *)(param_1 + 0x4e28) = 0;
  *(undefined4 *)(param_1 + 0x53d4) = 0;
  *(undefined4 *)(param_1 + 0x53d8) = 0;
  *(undefined4 *)(param_1 + 0x514c) = 0;
  *(undefined4 *)(param_1 + 0x5150) = 0;
  *(undefined4 *)(param_1 + 0x48dc) = 0;
  *(undefined4 *)(param_1 + 0x48d8) = 0;
  *(undefined4 *)(param_1 + 0x48ec) = 0;
  *(undefined4 *)(param_1 + 0x48f0) = 0;
  *(undefined4 *)(param_1 + 0x48e0) = 0;
  *(undefined4 *)(param_1 + 0x48e4) = 0;
  *(undefined2 *)(param_1 + 0x48ea) = 0;
  *(undefined4 *)(param_1 + 0x7574) = 0;
  *(undefined1 *)(param_1 + 0x7583) = 0;
  uVar1 = *(undefined1 *)(*(int *)(param_1 + 0x468c) + 0x79);
  *(undefined1 *)(param_1 + 0x759d) = 1;
  *(undefined1 *)(param_1 + 0x7580) = uVar1;
  *(undefined1 *)(param_1 + 0x4fea) = 0;
  *(undefined1 *)(param_1 + 0x7581) = *(undefined1 *)(param_1 + 0x7580);
  *(undefined4 *)(param_1 + 0x7594) = 3;
  *(undefined4 *)(param_1 + 0x7598) = 0;
  *(undefined1 *)(param_1 + 0x759c) = 1;
  return;
}

/* _gleInitDerivedState @ 0x54d4 (728 bytes) */
void _gleInitDerivedState(param_1)
  int param_1;
{
  float fVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  undefined1 *puVar5;
  int iVar6;
  int *piVar7;
  
  iVar6 = *(int *)(param_1 + 0x4854);
  *(int *)(param_1 + 0x5140) = param_1 + 0x5100;
  *(int *)(param_1 + 0x50f8) = param_1 + 0x50b8;
  piVar7 = (int *)(param_1 + 0x4dd0);
  *(undefined1 *)(param_1 + 0x4e18) = 0;
  iVar4 = 1;
  *(undefined1 *)(param_1 + 0x2ed) = 0;
  *(undefined1 *)(param_1 + 0x2ee) = 6;
  *(undefined1 *)(iVar6 + -0x181) = 0;
  *(undefined4 *)(iVar6 + -0x200) = 0;
  *(undefined1 *)(iVar6 + -0x182) = 6;
  *(undefined1 *)(iVar6 + -0x184) = 0;
  *(undefined4 *)(iVar6 + -0x1e0) = 0;
  *(undefined4 *)(iVar6 + -0x1dc) = 0;
  *(undefined4 *)(iVar6 + -0x1d8) = 0;
  *(undefined4 *)(iVar6 + -0x1d4) = 0x3f800000;
  *(undefined4 *)(iVar6 + -0x1f0) = 0;
  *(undefined4 *)(iVar6 + -0x1ec) = 0;
  *(undefined4 *)(iVar6 + -0x1e8) = 0;
  *(undefined4 *)(iVar6 + -0x1e4) = 0x3f800000;
  *(undefined4 *)(iVar6 + -0x1fc) = 0;
  *(undefined4 *)(iVar6 + -0x1f8) = 0;
  *(undefined4 *)(iVar6 + -0x1c0) = 0;
  *(undefined4 *)(iVar6 + -0x1bc) = 0;
  *(undefined4 *)(iVar6 + -0x1b8) = 0x3f800000;
  *(undefined4 *)(iVar6 + -0x1b4) = 0x3f800000;
  *(undefined1 *)(iVar6 + -0x183) = 1;
  *(undefined1 *)(param_1 + 0x5410) = 1;
  *(undefined4 *)(param_1 + 0x540c) = 0;
  *(undefined4 *)(param_1 + 0x53e8) = 0;
  *(undefined4 *)(param_1 + 0x53ec) = 0;
  *(undefined4 *)(param_1 + 0x53f0) = 0;
  *(undefined4 *)(param_1 + 0x74b4) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x74c4) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x74d4) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x4fcc) = 0;
  *(undefined4 *)(param_1 + 0x4ddc) = 0;
  *(undefined4 *)(param_1 + 0x4fd0) = 0;
  *(undefined1 *)(param_1 + 0x4fdc) = 0;
  do {
    iVar4 = iVar4 + -1;
    iVar6 = *piVar7;
    piVar7 = piVar7 + 1;
    *(undefined4 *)(iVar6 + 500) = 0xbf800000;
    *(undefined1 *)(iVar6 + 0x234) = 0x1f;
    *(undefined1 *)(iVar6 + 0x235) = 0;
    *(undefined1 *)(iVar6 + 0x236) = 0;
  } while (-1 < iVar4);
  iVar6 = 8;
  iVar4 = param_1;
  do {
    *(undefined1 *)(iVar4 + 0x4ada) = 0;
    *(undefined1 *)(iVar4 + 0x4adb) = 1;
    *(undefined4 *)(iVar4 + 0x4a94) = 0xbf800000;
    *(undefined4 *)(iVar4 + 0x4ad4) = 0x3f800000;
    iVar4 = iVar4 + 0x6c;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  *(undefined1 *)(param_1 + 0x53e7) = 0;
  *(undefined4 *)(param_1 + 0x50b0) = 0;
  *(undefined1 *)(param_1 + 0x50b5) = 0;
  *(undefined1 *)(param_1 + 0x50b4) = 0;
  *(undefined1 *)(param_1 + 0x4fe0) = 0;
  *(undefined4 *)(param_1 + 0x4a14) = 0;
  *(undefined1 *)(param_1 + 0x4a18) = 0;
  *(undefined4 *)(param_1 + 20000) = 0;
  *(undefined4 *)(param_1 + 0x4e24) = 0;
  *(undefined4 *)(param_1 + 0x4fc0) = 0;
  *(undefined1 *)(param_1 + 0x4fc8) = 0;
  *(undefined4 *)(param_1 + 0x4fc4) = 0;
  *(undefined1 *)(param_1 + 0x4fc9) = 0;
  *(undefined4 *)(param_1 + 0x53dc) = 0;
  *(undefined4 *)(param_1 + 0x53e0) = 0;
  *(undefined1 *)(param_1 + 0x53e4) = 0;
  *(undefined1 *)(param_1 + 0x53e5) = 0;
  *(undefined1 *)(param_1 + 0x53e6) = 0;
  *(undefined4 *)(param_1 + 0x50a8) = 0x11;
  iVar4 = 8;
  *(undefined2 *)(param_1 + 0x4a12) = 0xffff;
  *(undefined1 *)(param_1 + 0x4fe3) = 2;
  puVar5 = (undefined1 *)(param_1 + 0x531c);
  *(undefined4 *)(param_1 + 0x50ac) = 0xffffffff;
  *(undefined2 *)(param_1 + 0x4a10) = 0xffff;
  *(int *)(param_1 + 0x4fec) = param_1 + 0x1cc0;
  *(int *)(param_1 + 0x4ff0) = param_1 + 0x22c0;
  *(undefined1 *)(param_1 + 0x4fe1) = 1;
  *(undefined1 *)(param_1 + 0x4fe2) = 1;
  do {
    *(undefined4 *)(puVar5 + -8) = 0;
    *(undefined4 *)(puVar5 + -4) = 0;
    *puVar5 = 0;
    puVar2 = PTR__gleSetVertexEval2Func_00112068;
    puVar5 = puVar5 + 0xc;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  *(undefined **)(param_1 + 0x4898) = PTR__gleSetVertexEval1Func_0011206c;
  puVar3 = PTR__gleSetVertexSubmitFunc_0011242c;
  *(undefined **)(param_1 + 0x489c) = puVar2;
  *(undefined **)(param_1 + 0x4888) = puVar3;
  puVar2 = PTR__gleSetEyeInterpFunc_0011203c;
  *(undefined2 *)(param_1 + 0x487e) = 0x7c;
  *(undefined **)(param_1 + 0x49c8) = puVar2;
  puVar2 = PTR__gleSetClipInterpFunc_00112038;
  fVar1 = FLOAT_00108e80;
  *(undefined4 *)(param_1 + 0x4884) = *(undefined4 *)(param_1 + 0xd8);
  *(undefined2 *)(param_1 + 0x487c) = 0x100;
  *(undefined **)(param_1 + 0x49cc) = puVar2;
  *(float *)(param_1 + 0x10c) = fVar1;
  *(undefined4 *)(param_1 + 0x488c) = 0;
  *(undefined4 *)(param_1 + 0x4890) = 0;
  *(undefined4 *)(param_1 + 0x4868) = 0;
  *(undefined4 *)(param_1 + 0x486c) = 0;
  *(undefined4 *)(param_1 + 0x48d0) = 0;
  *(undefined4 *)(param_1 + 0x48d4) = 0;
  *(undefined4 *)(param_1 + 0xf0) = 0;
  *(undefined4 *)(param_1 + 0xf4) = 0;
  *(undefined4 *)(param_1 + 0xf8) = 0;
  *(undefined4 *)(param_1 + 0xfc) = 0;
  *(undefined4 *)(param_1 + 0x100) = 0;
  *(undefined4 *)(param_1 + 0x104) = 0;
  *(undefined4 *)(param_1 + 0x108) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x110) = 0;
  *(undefined4 *)(param_1 + 0x114) = 0;
  *(undefined4 *)(param_1 + 0x118) = 0;
  *(undefined4 *)(param_1 + 0x11c) = 0;
  *(undefined4 *)(param_1 + 0x4a1c) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x758c) = 0;
  *(undefined4 *)(param_1 + 0x4a40) = 0x3f000000;
  *(undefined4 *)(param_1 + 0x4a50) = 0;
  *(undefined4 *)(param_1 + 0x4a54) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x4a20) = 0;
  *(undefined4 *)(param_1 + 0x4a24) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x4a28) = 0;
  *(undefined4 *)(param_1 + 0x4a2c) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x4a30) = 0;
  *(undefined4 *)(param_1 + 0x4a34) = 0x3f800000;
  *(undefined4 *)(param_1 + 19000) = 0;
  *(undefined4 *)(param_1 + 0x4a3c) = 0x3f000000;
  *(undefined4 *)(param_1 + 0x4a44) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x4a48) = 0;
  *(undefined4 *)(param_1 + 0x4a4c) = 0x3f800000;
  *(undefined1 *)(param_1 + 0x7584) = 0;
  *(undefined1 *)(param_1 + 0x7585) = 0;
  *(undefined1 *)(param_1 + 0x7586) = 0;
  *(undefined1 *)(param_1 + 0x7587) = 0;
  *(undefined4 *)(param_1 + 0x7588) = 0;
  return;
}

/* _gleInitTextureState @ 0x57ac (592 bytes) */
void _gleInitTextureState(param_1)
  int param_1;
{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  uint uVar10;
  int *piVar11;
  int iVar12;
  
  uVar10 = 0;
  piVar11 = (int *)(param_1 + 0x5294);
  iVar12 = param_1;
  do {
    iVar3 = ((int (*)())_gleCreateTextureObject)(uVar10 | 0x1000,0);
    ((void (*)())_gleCreatePluginTexture)(param_1,iVar3 + 0x10);
    *piVar11 = iVar3;
    iVar5 = uVar10 * 4 + param_1 + 0x10000;
    piVar6 = (int *)(iVar12 + 0x5154);
    iVar4 = 0xf;
    do {
      cVar1 = *(char *)(param_1 + 0x85a4);
      iVar8 = 0;
      *piVar6 = iVar3;
      piVar6 = piVar6 + 5;
      if (cVar1 != '\0') {
        puVar9 = (undefined4 *)(iVar5 + -0x7920);
        puVar7 = (undefined4 *)(iVar3 + 0x10);
        do {
          uVar2 = *puVar7;
          iVar8 = iVar8 + 1;
          puVar7 = puVar7 + 1;
          *puVar9 = uVar2;
          puVar9 = puVar9 + 0xb8;
        } while (iVar8 < (int)(uint)*(byte *)(param_1 + 0x85a4));
      }
      iVar4 = iVar4 + -1;
      iVar5 = iVar5 + 0x14;
    } while (-1 < iVar4);
    uVar10 = uVar10 + 1;
    iVar12 = iVar12 + 4;
    piVar11 = piVar11 + 1;
    *(int *)(iVar3 + 8) = *(int *)(iVar3 + 8) + 0x10;
  } while ((int)uVar10 < 5);
  uVar10 = 0;
  piVar11 = (int *)(param_1 + 0x52a8);
  do {
    iVar12 = ((int (*)())_gleCreateTextureObject)(uVar10 | 0x1100,0);
    uVar10 = uVar10 + 1;
    ((void (*)())_gleCreatePluginTexture)(param_1,iVar12 + 0x10);
    *piVar11 = iVar12;
    piVar11 = piVar11 + 1;
  } while ((int)uVar10 < 5);
  iVar3 = 0;
  piVar11 = (int *)(param_1 + 0x52bc);
  iVar12 = param_1;
  do {
    iVar4 = ((int (*)())_gleCreateTextureObject)(iVar3 << 4 | 0x1204,0);
    puVar7 = (undefined4 *)(iVar4 + 0x10);
    ((void (*)())_gleCreatePluginTexture)(param_1,puVar7);
    cVar1 = *(char *)(param_1 + 0x85a4);
    iVar5 = 0;
    *piVar11 = iVar4;
    piVar11 = piVar11 + 1;
    if (cVar1 != '\0') {
      puVar9 = (undefined4 *)(iVar12 + 0x8820);
      do {
        uVar2 = *puVar7;
        iVar5 = iVar5 + 1;
        puVar7 = puVar7 + 1;
        *puVar9 = uVar2;
        puVar9 = puVar9 + 0xb8;
      } while (iVar5 < (int)(uint)*(byte *)(param_1 + 0x85a4));
    }
    iVar3 = iVar3 + 1;
    iVar12 = iVar12 + 4;
  } while (iVar3 < 3);
  piVar11 = (int *)(param_1 + 0x52c8);
  uVar10 = 0;
  iVar12 = 2;
  do {
    iVar3 = ((int (*)())_gleCreateTextureObject)(uVar10 | 0x1304,0);
    uVar10 = uVar10 + 0x10;
    ((void (*)())_gleCreatePluginTexture)(param_1,iVar3 + 0x10);
    iVar12 = iVar12 + -1;
    *piVar11 = iVar3;
    piVar11 = piVar11 + 1;
  } while (-1 < iVar12);
  iVar3 = 0;
  piVar11 = (int *)(param_1 + 0x52d4);
  iVar12 = param_1;
  do {
    iVar4 = ((int (*)())_gleCreateTextureObject)(((unsigned char *)0x00001204U),0);
    puVar7 = (undefined4 *)(iVar4 + 0x10);
    ((void (*)())_gleCreatePluginTexture)(param_1,puVar7);
    cVar1 = *(char *)(param_1 + 0x85a4);
    iVar5 = 0;
    *piVar11 = iVar4;
    piVar11 = piVar11 + 1;
    if (cVar1 != '\0') {
      puVar9 = (undefined4 *)(iVar12 + 0x882c);
      do {
        uVar2 = *puVar7;
        iVar5 = iVar5 + 1;
        puVar7 = puVar7 + 1;
        *puVar9 = uVar2;
        puVar9 = puVar9 + 0xb8;
      } while (iVar5 < (int)(uint)*(byte *)(param_1 + 0x85a4));
    }
    iVar3 = iVar3 + 1;
    iVar12 = iVar12 + 4;
  } while (iVar3 < 0x10);
  return;
}

/* _gleCreateTextureObject @ 0x59fc (148 bytes) */
int _gleCreateTextureObject(param_1, param_2)
  uint param_1;
  undefined4 param_2;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar3;
  
  iVar3 = 0;
  if (((param_1 & 0x200) == 0) && (iVar3 = 6, (param_1 & 0xf) != 0)) {
    iVar3 = 1;
  }
  puVar2 = (undefined4 *)_malloc(iVar3 * 0x168 + 0x944);
  puVar1 = PTR__gleFreeTextureObject_001115dc;
  *puVar2 = 0;
  puVar2[1] = param_2;
  puVar2[2] = 1;
  puVar2[3] = puVar1;
  ((void (*)())_gleInitializeGLTexture)(param_1,iVar3,puVar2 + 4,in_r6,in_r7,in_r8,1);
  return puVar2;
}

/* _gleInitializeGLTexture @ 0x5a90 (832 bytes) */
void _gleInitializeGLTexture(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  int param_2;
  undefined4 *param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined1 uVar2;
  undefined2 uVar1;
  undefined1 uVar6;
  undefined2 uVar5;
  undefined4 *puVar3;
  int iVar4;
  int iVar7;
  int iVar8;
  int iVar9;
  
  *(undefined2 *)((int)param_3 + 0x32) = 0;
  *(undefined2 *)(param_3 + 0xc) = 0x404;
  param_3[8] = 0;
  *(ushort *)(param_3 + 9) = (*(unsigned short *)((unsigned char *)&(param_1) + 2));
  *(undefined2 *)((int)param_3 + 0x26) = 0;
  param_3[10] = 0x3f800000;
  param_3[0xb] = 0;
  if (((*(unsigned short *)((unsigned char *)&(param_1) + 2)) & 0x200) == 0) {
    *(undefined2 *)(param_3 + 0x1e) = 0;
  }
  else {
    *(undefined2 *)(param_3 + 0x1e) = 0x80e2;
  }
  *(undefined2 *)((int)param_3 + 0x7a) = 0;
  if (((*(unsigned short *)((unsigned char *)&(param_1) + 2)) & 0x2000) != 0) {
    *(undefined1 *)(param_3 + 0x24) = 1;
    *(undefined1 *)((int)param_3 + 0x92) = 2;
    *(undefined1 *)((int)param_3 + 0x93) = 0;
    *(undefined2 *)(param_3 + 0xe) = 0x812f;
    *(undefined2 *)((int)param_3 + 0x3a) = 0x2600;
    *(undefined1 *)((int)param_3 + 0x91) = 0;
    *(undefined2 *)(param_3 + 0xd) = 0x812f;
    *(undefined2 *)((int)param_3 + 0x36) = 0x812f;
    goto LAB_00005c28;
  }
  switch((*(unsigned short *)((unsigned char *)&(param_1) + 2)) & 0xf) {
  case 0:
    uVar6 = 6;
    goto LAB_00005bb8;
  case 1:
    *(undefined1 *)((int)param_3 + 0x91) = 0;
    *(undefined1 *)(param_3 + 0x24) = 1;
    *(undefined1 *)((int)param_3 + 0x93) = 2;
    *(undefined1 *)((int)param_3 + 0x92) = 2;
    break;
  case 2:
    uVar2 = 1;
    *(undefined1 *)(param_3 + 0x24) = 1;
    *(undefined1 *)((int)param_3 + 0x92) = 2;
    *(undefined1 *)((int)param_3 + 0x93) = 0;
    goto LAB_00005bc8;
  case 3:
    uVar6 = 1;
LAB_00005bb8:
    uVar2 = 0;
    *(undefined1 *)(param_3 + 0x24) = uVar6;
    *(undefined1 *)((int)param_3 + 0x92) = 2;
    *(undefined1 *)((int)param_3 + 0x93) = 0;
LAB_00005bc8:
    *(undefined1 *)((int)param_3 + 0x91) = uVar2;
    break;
  case 4:
    *(undefined1 *)(param_3 + 0x24) = 1;
    *(undefined1 *)((int)param_3 + 0x93) = 0;
    *(undefined1 *)((int)param_3 + 0x91) = 0;
    *(undefined1 *)((int)param_3 + 0x92) = 0;
    break;
  default:
    *(undefined1 *)((int)param_3 + 0x93) = 0;
    *(undefined1 *)((int)param_3 + 0x91) = 0;
    *(undefined1 *)(param_3 + 0x24) = 0;
    *(undefined1 *)((int)param_3 + 0x92) = 0;
  }
  if (((*(unsigned short *)((unsigned char *)&(param_1) + 2)) & 0xf) == 2) {
    uVar5 = 0x812f;
    uVar1 = 0x2601;
  }
  else {
    uVar5 = 0x2901;
    uVar1 = 0x2702;
  }
  *(undefined2 *)(param_3 + 0xe) = uVar5;
  *(undefined2 *)((int)param_3 + 0x3a) = uVar1;
  *(undefined2 *)(param_3 + 0xd) = uVar5;
  *(undefined2 *)((int)param_3 + 0x36) = uVar5;
LAB_00005c28:
  *(undefined2 *)(param_3 + 0xf) = 0x2601;
  *(undefined2 *)((int)param_3 + 0x3e) = 0x85bd;
  *(undefined2 *)(param_3 + 0x1f) = 0;
  *(undefined2 *)((int)param_3 + 0x7e) = 0;
  *(undefined2 *)(param_3 + 0x20) = 0;
  *(undefined1 *)((int)param_3 + 0x82) = 0;
  iVar8 = 8;
  *(undefined1 *)((int)param_3 + 0x83) = 0;
  *(undefined1 *)(param_3 + 0x21) = 0;
  *(undefined1 *)((int)param_3 + 0x85) = 0;
  *(undefined1 *)((int)param_3 + 0x86) = 0;
  *(undefined1 *)((int)param_3 + 0x87) = 0;
  *(undefined1 *)(param_3 + 0x22) = 0;
  *(undefined1 *)((int)param_3 + 0x89) = 0;
  *(undefined1 *)((int)param_3 + 0x8a) = 0;
  *(undefined1 *)((int)param_3 + 0x8b) = 0;
  *(undefined1 *)(param_3 + 0x23) = 0;
  *(undefined1 *)((int)param_3 + 0x8d) = 0;
  *(undefined1 *)((int)param_3 + 0x8e) = 0;
  *(undefined1 *)((int)param_3 + 0x8f) = 0;
  *(undefined2 *)(param_3 + 0x25) = 0;
  *(undefined2 *)((int)param_3 + 0x96) = 0;
  *(undefined2 *)(param_3 + 0x26) = 0;
  *(undefined2 *)((int)param_3 + 0x9a) = 0;
  *(undefined2 *)(param_3 + 0x27) = 0;
  *(undefined2 *)((int)param_3 + 0x9e) = 0;
  *(undefined2 *)(param_3 + 0x28) = 0;
  *(undefined2 *)((int)param_3 + 0xa2) = 0;
  *(undefined2 *)(param_3 + 0x29) = 0;
  *(undefined2 *)((int)param_3 + 0xa6) = 0;
  *(undefined2 *)(param_3 + 0x2a) = 0;
  *(undefined2 *)((int)param_3 + 0xaa) = 0;
  param_3[0x10] = 0;
  param_3[0x11] = 0;
  param_3[0x12] = 0;
  *(undefined2 *)(param_3 + 0x1b) = 0x1909;
  param_3[0x15] = 0xc47a0000;
  *(undefined2 *)((int)param_3 + 0x62) = 1000;
  *(undefined2 *)(param_3 + 0x19) = 0x203;
  param_3[0x14] = 0x3f800000;
  param_3[0x16] = 0x447a0000;
  *(undefined2 *)((int)param_3 + 0x66) = 0;
  param_3[0x1a] = 0;
  param_3[0x1b] = param_3[0x1b] & 0xffff7f3f;
  param_3[0x1d] = 0;
  param_3[0x13] = 0;
  param_3[0x17] = 0;
  *(undefined2 *)(param_3 + 0x18) = 0;
  param_3[0x1c] = 0;
  puVar3 = param_3;
  do {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  iVar8 = 0;
  *(undefined1 *)((int)param_3 + 0xb7) = 0;
  *(undefined2 *)(param_3 + 0x2f) = 0x1908;
  *(undefined2 *)((int)param_3 + 0xbe) = 0x1401;
  param_3[0x2b] = 0;
  *(undefined2 *)(param_3 + 0x2c) = 0;
  *(undefined2 *)((int)param_3 + 0xb2) = 0;
  *(undefined2 *)(param_3 + 0x2d) = 0;
  *(undefined1 *)((int)param_3 + 0xb6) = 0;
  *(undefined2 *)(param_3 + 0x2e) = 0;
  *(undefined2 *)((int)param_3 + 0xba) = 0;
  param_3[0x30] = 0;
  if (0 < param_2) {
    iVar7 = 0;
    do {
      iVar4 = (int)param_3 + iVar7;
      iVar9 = 0xf;
      do {
        *(undefined2 *)(iVar4 + 200) = 0;
        *(undefined2 *)(iVar4 + 0xca) = 0;
        *(undefined2 *)(iVar4 + 0xcc) = 0;
        *(undefined1 *)(iVar4 + 0xce) = 0;
        *(undefined2 *)(iVar4 + 0xd0) = 0;
        *(undefined2 *)(iVar4 + 0xd2) = 0;
        *(undefined2 *)(iVar4 + 0xd4) = 0x1908;
        *(undefined2 *)(iVar4 + 0xd6) = 0x1401;
        *(undefined4 *)(iVar4 + 0xd8) = 0;
        *(undefined1 *)(iVar4 + 0xcf) = 0;
        *(undefined4 *)(iVar4 + 0xc4) = 0;
        iVar4 = iVar4 + 0x18;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
      iVar8 = iVar8 + 1;
      iVar7 = iVar7 + 0x168;
    } while (iVar8 < param_2);
  }
  return;
}

/* _gleCreatePluginTexture @ 0x5de4 (120 bytes) */
void _gleCreatePluginTexture(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = param_1 + 0x10000;
  iVar4 = 0;
  if (*(char *)(param_1 + 0x85a4) != '\0') {
    iVar5 = param_2;
    do {
      piVar1 = (int *)(iVar3 + -0x777c);
      puVar2 = (undefined4 *)(iVar3 + -0x7a54);
      iVar3 = iVar3 + 0x2e0;
      iVar4 = iVar4 + 1;
      (**(code **)(*piVar1 + 0x14c))(*puVar2,iVar5,param_2 + 0x24);
      iVar5 = iVar5 + 4;
    } while (iVar4 < (int)(uint)*(byte *)(param_1 + 0x85a4));
  }
  return;
}

/* _gleInitPipelineProgramState @ 0x5e5c (624 bytes) */
void _gleInitPipelineProgramState(param_1)
  int param_1;
{
  char cVar1;
  byte bVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  ushort *puVar6;
  undefined1 *puVar7;
  int iVar8;
  uint *puVar9;
  uint *puVar10;
  undefined4 *puVar11;
  uint *puVar12;
  uint uVar13;
  undefined4 *puVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  int iVar19;
  uint uVar20;
  int iVar21;
  uint uVar22;
  
  iVar15 = *(int *)(param_1 + 0x5148);
  puVar7 = (undefined1 *)_malloc(0x600);
  *puVar7 = 0;
  iVar19 = 0;
  *(undefined4 *)(param_1 + 0x541c) = 0xffffffff;
  *(undefined1 **)(param_1 + 0x5418) = puVar7;
  iVar16 = param_1;
  iVar18 = param_1;
  do {
    iVar21 = 0;
    iVar8 = ((int (*)())_gleCreatePipelineProgramObject)(param_1,iVar19,0);
    ((void (*)())_gleCreatePluginPipelineProgram)(param_1,iVar8 + 0x10);
    cVar1 = *(char *)(param_1 + 0x85a4);
    *(int *)(iVar18 + 0x5428) = iVar8;
    *(int *)(iVar18 + 0x5420) = iVar8;
    if (cVar1 != '\0') {
      puVar11 = (undefined4 *)(iVar8 + 0x4a8);
      puVar14 = (undefined4 *)(iVar16 + 0x886c);
      do {
        uVar3 = *puVar11;
        iVar21 = iVar21 + 1;
        puVar11 = puVar11 + 1;
        *puVar14 = uVar3;
        puVar14 = puVar14 + 0xb8;
      } while (iVar21 < (int)(uint)*(byte *)(param_1 + 0x85a4));
    }
    iVar19 = iVar19 + 1;
    iVar16 = iVar16 + 4;
    iVar18 = iVar18 + 4;
    *(int *)(iVar8 + 8) = *(int *)(iVar8 + 8) + 1;
  } while (iVar19 < 2);
  iVar16 = iVar15 + 0x10000;
  if (*(char *)(iVar15 + 0x8024) != '\0') {
    _pthread_mutex_lock(iVar15 + 0x8028);
  }
  iVar19 = 0;
  iVar18 = param_1;
  do {
    if (*(int *)(iVar16 + -0x7560) == 0) {
      uVar17 = 0;
      uVar20 = 0;
      puVar9 = (uint *)_malloc((uint)*(byte *)(param_1 + 0x85a4) * 4 + 4);
      uVar22 = 1;
      uVar4 = 0x100;
      if (iVar19 != 0) {
        uVar4 = 0x80;
      }
      bVar2 = *(byte *)(param_1 + 0x85a4);
      iVar8 = 0;
      *puVar9 = uVar4;
      if (bVar2 != 0) {
        puVar6 = (ushort *)(iVar18 + 0x86a0);
        puVar10 = puVar9 + 1;
        do {
          uVar4 = (uint)*puVar6;
          puVar6 = puVar6 + 0x170;
          if (uVar4 != 0) {
            uVar13 = 0;
            puVar12 = puVar9;
            if (uVar22 != 0) {
              do {
                if (uVar4 == *puVar12) break;
                uVar13 = uVar13 + 1;
                puVar12 = puVar12 + 1;
              } while (uVar13 < uVar22);
            }
            if (uVar13 == uVar22) {
              *puVar10 = uVar4;
              uVar22 = uVar22 + 1;
              puVar10 = puVar10 + 1;
            }
          }
          iVar8 = iVar8 + 1;
        } while (iVar8 < (int)(uint)bVar2);
      }
      *(uint *)(iVar16 + -0x7564) = uVar22;
      uVar3 = _malloc(uVar22 << 2);
      *(undefined4 *)(iVar16 + -0x7560) = uVar3;
      if (uVar22 != 0) {
        do {
          uVar4 = 0x7ffffff;
          puVar10 = puVar9;
          for (uVar13 = uVar22; uVar13 != 0; uVar13 = uVar13 - 1) {
            uVar5 = *puVar10;
            puVar10 = puVar10 + 1;
            if ((uVar17 < uVar5) && (uVar5 < uVar4)) {
              uVar4 = uVar5;
            }
          }
          iVar8 = uVar20 * 4;
          uVar20 = uVar20 + 1;
          *(uint *)(iVar8 + *(int *)(iVar16 + -0x7560)) = uVar4;
          uVar17 = uVar4;
        } while (uVar20 < uVar22);
      }
      _free(puVar9);
    }
    iVar19 = iVar19 + 1;
    iVar18 = iVar18 + 0x10;
    iVar16 = iVar16 + 0xa30;
    if (1 < iVar19) {
      if (*(char *)(iVar15 + 0x8024) != '\0') {
        _pthread_mutex_unlock(iVar15 + 0x8028);
        return;
      }
      return;
    }
  } while( true );
}

/* _gleCreatePipelineProgramObject @ 0x60cc (480 bytes) */
int _gleCreatePipelineProgramObject(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
{
  int iVar1;
  uint uVar2;
  undefined *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  undefined1 uVar9;
  int iVar10;
  
  iVar8 = 0x4e4;
  if (param_2 == 0) {
    iVar7 = 0x100;
    iVar8 = 0x4e8;
    uVar9 = 0;
  }
  else if (param_2 == 1) {
    iVar7 = 0x80;
    iVar8 = 0x4f4;
    uVar9 = 0x80;
  }
  else {
    iVar7 = 0;
    uVar9 = 0;
  }
  uVar2 = iVar8 + 0xfU & 0xfffffff0;
  puVar6 = (undefined4 *)((int (*)())_gleVecAlloc)(uVar2 + iVar7 * 0x10);
  puVar3 = PTR__gleFreePipelineProgramObject_00110e90;
  *(undefined1 *)(puVar6 + 0x13) = 1;
  puVar6[2] = 1;
  puVar6[3] = puVar3;
  puVar6[1] = param_3;
  iVar8 = (int)puVar6 + uVar2;
  puVar6[9] = 0;
  puVar4 = puVar6 + 0x12a;
  *puVar6 = 0;
  iVar10 = 8;
  puVar6[4] = 0;
  puVar6[5] = 0;
  puVar6[6] = 0;
  puVar6[7] = 0;
  *(undefined2 *)(puVar6 + 0x14) = 0;
  *(undefined2 *)((int)puVar6 + 0x52) = 0;
  *(undefined2 *)(puVar6 + 0x15) = 0;
  *(undefined2 *)((int)puVar6 + 0x56) = 0;
  *(undefined2 *)((int)puVar6 + 0x4e) = 0;
  puVar6[8] = 0;
  do {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  iVar10 = 9;
  puVar4 = puVar6 + 10;
  do {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  puVar4 = puVar6 + 0x16;
  iVar10 = 0x450;
  do {
    *(undefined1 *)puVar4 = uVar9;
    puVar4 = (undefined4 *)((int)puVar4 + 1);
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  if (param_2 == 0) {
    puVar6[0x139] = 0;
  }
  else if (param_2 == 1) {
    *(undefined2 *)(puVar6 + 0x13c) = 0;
    puVar6[0x139] = 0;
    puVar6[0x13a] = 0;
    *(undefined2 *)(puVar6 + 0x13b) = 0;
    *(undefined2 *)((int)puVar6 + 0x4ee) = 0;
  }
  iVar10 = 0;
  puVar6[0x137] = 0;
  puVar6[0x133] = 0;
  puVar6[0x136] = 0;
  *(short *)((int)puVar6 + 0x4ca) = (short)param_2;
  puVar6[0x134] = 0xffffffff;
  puVar6[0x135] = 0xffffffff;
  puVar6[0x138] = iVar8;
  *(undefined2 *)(puVar6 + 0x132) = 0;
  for (; iVar7 != 0; iVar7 = iVar7 + -1) {
    iVar1 = iVar10 * 0x10;
    iVar10 = iVar10 + 1;
    iVar5 = iVar1 + iVar8;
    *(undefined4 *)(iVar8 + iVar1) = 0;
    *(undefined4 *)(iVar5 + 0xc) = 0x3f800000;
    *(undefined4 *)(iVar5 + 4) = 0;
    *(undefined4 *)(iVar5 + 8) = 0;
  }
  return puVar6;
}

/* _gleVecAlloc @ 0x62ac (12 bytes) */
int _gleVecAlloc(param_1)
  int param_1;
{
  undefined4 uVar1;
  
  uVar1 = _malloc(param_1 + 0xfU & 0xfffffff0);
  return uVar1;
}

/* _gleCreatePluginPipelineProgram @ 0x62b8 (120 bytes) */
void _gleCreatePluginPipelineProgram(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = param_1 + 0x10000;
  iVar4 = 0;
  if (*(char *)(param_1 + 0x85a4) != '\0') {
    iVar5 = param_2 + 0x498;
    do {
      piVar1 = (int *)(iVar3 + -0x777c);
      puVar2 = (undefined4 *)(iVar3 + -0x7a54);
      iVar3 = iVar3 + 0x2e0;
      iVar4 = iVar4 + 1;
      (**(code **)(*piVar1 + 400))(*puVar2,iVar5,param_2 + 0x4b8);
      iVar5 = iVar5 + 4;
    } while (iVar4 < (int)(uint)*(byte *)(param_1 + 0x85a4));
  }
  return;
}

/* _gleInitShaderState @ 0x6330 (16 bytes) */
void _gleInitShaderState(param_1)
  int param_1;
{
  *(undefined4 *)(param_1 + 0x5438) = 0;
  *(undefined4 *)(param_1 + 0x5434) = 0;
  return;
}

/* _gleInitBufferState @ 0x6340 (48 bytes) */
void _gleInitBufferState(param_1)
  int param_1;
{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0x20;
  *(undefined4 *)(param_1 + 0x48f4) = 0;
  puVar1 = (undefined4 *)(param_1 + 0x48f8);
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined4 *)(param_1 + 0x4a6c) = 0;
  *(undefined4 *)(param_1 + 0x4978) = 0;
  *(undefined4 *)(param_1 + 0x4a68) = 0;
  return;
}

/* _glePPEmulatorInitialize @ 0x6370 (48 bytes) */
void _glePPEmulatorInitialize(param_1)
  int param_1;
{
  undefined4 uVar1;
  
  uVar1 = _PPEmulatorCreate();
  *(undefined4 *)(param_1 + 0x4a5c) = uVar1;
  return;
}

/* _gleInitVertexArrayState @ 0x63a0 (148 bytes) */
void _gleInitVertexArrayState(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  
  iVar2 = ((int (*)())_gleCreateVertexArrayObject)(param_1,0);
  puVar5 = (undefined4 *)(iVar2 + 0x10);
  ((void (*)())_gleCreatePluginVertexArray)(param_1,puVar5);
  iVar4 = 0;
  *(int *)(param_1 + 0x4a64) = iVar2;
  *(int *)(param_1 + 0x4a60) = iVar2;
  if (*(char *)(param_1 + 0x85a4) != '\0') {
    puVar3 = (undefined4 *)(param_1 + 0x8874);
    do {
      uVar1 = *puVar5;
      iVar4 = iVar4 + 1;
      puVar5 = puVar5 + 1;
      *puVar3 = uVar1;
      puVar3 = puVar3 + 0xb8;
    } while (iVar4 < (int)(uint)*(byte *)(param_1 + 0x85a4));
  }
  *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + 1;
  return;
}

/* _gleCreateVertexArrayObject @ 0x6434 (428 bytes) */
int _gleCreateVertexArrayObject(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  
  puVar4 = (undefined4 *)((int (*)())_gleVecAlloc)((uint)*(byte *)(param_1 + 0x85a4) * 0x8c + 0x3e0);
  puVar1 = PTR__gleFreeVertexArrayObject_001115f8;
  iVar5 = 0x20;
  *puVar4 = 0;
  puVar4[2] = 1;
  puVar4[3] = puVar1;
  puVar4[1] = param_2;
  puVar2 = puVar4;
  do {
    puVar2[0xc] = 0;
    puVar2[0xd] = 0;
    *(undefined2 *)(puVar2 + 0xe) = 0x1406;
    *(undefined2 *)((int)puVar2 + 0x3a) = 4;
    *(undefined1 *)(puVar2 + 0xf) = 0;
    puVar2[0x11] = 0xffffffff;
    *(undefined1 *)((int)puVar2 + 0x3d) = 0;
    puVar2[0x10] = 0;
    puVar2 = puVar2 + 6;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  puVar4[0xd4] = 0;
  puVar4[0xd5] = 0;
  puVar4[0xcc] = 0;
  puVar4[0xcd] = 0;
  puVar4[0xce] = 0;
  puVar4[0xcf] = 0;
  *(undefined2 *)(puVar4 + 0x32) = 0x1401;
  iVar5 = 0x20;
  *(undefined2 *)(puVar4 + 0x38) = 0x1405;
  *(undefined2 *)((int)puVar4 + 0x342) = 0x85b4;
  puVar2 = puVar4 + 0xd8;
  *(undefined2 *)((int)puVar4 + 0x9a) = 3;
  *(undefined2 *)((int)puVar4 + 0xe2) = 1;
  puVar4[0xd7] = 0;
  *(undefined2 *)((int)puVar4 + 0x52) = 3;
  *(undefined2 *)((int)puVar4 + 0x82) = 1;
  *(undefined2 *)((int)puVar4 + 0xb2) = 1;
  *(undefined2 *)((int)puVar4 + 0xca) = 1;
  puVar4[0xd2] = 0;
  puVar4[0xd1] = 0;
  *(undefined1 *)(puVar4 + 0xd3) = 0;
  puVar4[0xd6] = 0;
  do {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  iVar5 = 8;
  puVar2 = puVar4 + 4;
  do {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  iVar5 = 0;
  puVar2 = puVar4;
  if (*(char *)(param_1 + 0x85a4) != '\0') {
    do {
      puVar3 = puVar4 + 0xf8;
      iVar6 = 0x20;
      do {
        *puVar3 = 0;
        puVar3 = puVar3 + 1;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      puVar2[0x118] = 0;
      iVar5 = iVar5 + 1;
      puVar2[0x119] = 0xffffffff;
      puVar2[0x11a] = 0xffffffff;
      puVar4 = puVar4 + 0x23;
      puVar2 = puVar2 + 0x23;
    } while (iVar5 < (int)(uint)*(byte *)(param_1 + 0x85a4));
  }
  return;
}

/* _gleCreatePluginVertexArray @ 0x65e0 (132 bytes) */
void _gleCreatePluginVertexArray(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar3 = param_1 + 0x10000;
  iVar4 = 0;
  if (*(char *)(param_1 + 0x85a4) != '\0') {
    iVar5 = param_2;
    iVar6 = param_2 + 0x3d0;
    do {
      piVar1 = (int *)(iVar3 + -0x777c);
      puVar2 = (undefined4 *)(iVar3 + -0x7a54);
      iVar3 = iVar3 + 0x2e0;
      iVar4 = iVar4 + 1;
      (**(code **)(*piVar1 + 0x1a4))(*puVar2,iVar5,param_2 + 0x20,iVar6);
      iVar5 = iVar5 + 4;
      iVar6 = iVar6 + 0x8c;
    } while (iVar4 < (int)(uint)*(byte *)(param_1 + 0x85a4));
  }
  return;
}

/* _gleInitFenceMachine @ 0x6664 (36 bytes) */
void _gleInitFenceMachine(param_1)
  int param_1;
{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0x400;
  puVar1 = (undefined4 *)(param_1 + 0x543c);
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined4 *)(param_1 + 0x643c) = 0;
  return;
}

/* _gleInitQueryMachine @ 0x6688 (40 bytes) */
void _gleInitQueryMachine(param_1)
  int param_1;
{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0x400;
  puVar1 = (undefined4 *)(param_1 + 0x6440);
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined4 *)(param_1 + 0x7444) = 0;
  *(undefined4 *)(param_1 + 0x7440) = 0;
  return;
}

/* _gleInitDrawPixelsObject @ 0x66b0 (40 bytes) */
void _gleInitDrawPixelsObject(param_1)
  int param_1;
{
  *(undefined4 *)(0x74a4 + param_1) = 0;
  *(undefined4 *)(param_1 + 0x7488) = 0;
  *(undefined4 *)(param_1 + 0x7494) = 0;
  *(undefined4 *)(param_1 + 0x748c) = 0;
  *(undefined4 *)(param_1 + 0x7490) = 0;
  *(undefined4 *)(param_1 + 0x7498) = 0;
  *(undefined4 *)(param_1 + 0x749c) = 0;
  *(undefined4 *)(param_1 + 0x74a0) = 0;
  return;
}

