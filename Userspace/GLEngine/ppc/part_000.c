#include "decls.h"

/* _gliInitializeLibrary @ 0x13c4 (48 bytes) */
void _gliInitializeLibrary(initArg1, initArg2, ioData, initArg4, initArg5)
  undefined4 initArg1;
  undefined4 initArg2;
  undefined4 ioData;
  undefined4 initArg4;
  undefined4 initArg5;
{
  gliInitLibraryArg5 = initArg5;
  _gle_io_data = ioData;
  gliInitLibraryArg1 = initArg1;
  gliInitLibraryArg2 = initArg2;
  gliInitLibraryArg4 = initArg4;
  return;
}

/* _gliGetVersion @ 0x13f4 (448 bytes) */
int _gliGetVersion(majorVersion, minorVersion, outValue3)
  undefined4 *majorVersion;
  undefined4 *minorVersion;
  undefined4 *outValue3;
{
  mach_port_t host;
  kern_return_t hostInfoStatus;
  int sysctlStatusThenPluginResult;
  integer_t hostBasicInfo [3];
  int hostCpuType;
  int hostCpuSubtype;
  mach_msg_type_number_t hostInfoCount [2];
  int sysctlMibAndVectorUnit [3];
  size_t sysctlResultLength [5];
  
  ((void (*)())_glepPluginConnectAll)();
  hostInfoCount[0] = 0xc;
  host = _mach_host_self();
  hostInfoStatus = _host_info(host,1,hostBasicInfo,hostInfoCount);
  _mach_port_deallocate(*(ipc_space_t *)PTR_00112034,host);
  sysctlStatusThenPluginResult = 0;
  if (hostInfoStatus != 0) {
    return 0;
  }
  if (hostCpuType != 0x12) goto LAB_00001554;
  sysctlMibAndVectorUnit[0] = 6;
  sysctlResultLength[0] = 4;
  sysctlMibAndVectorUnit[1] = 0xd;
  sysctlStatusThenPluginResult = _sysctl(sysctlMibAndVectorUnit,2,sysctlMibAndVectorUnit + 2,sysctlResultLength,(void *)0x0,0);
  if (sysctlMibAndVectorUnit[2] != 0) {
    _gle_processor = _gle_processor | 0x30;
  }
  if ((*(uint *)PTR_00113e0c & 0x10) != 0) {
    _gle_processor = _gle_processor | 0x40;
  }
  if (hostCpuSubtype < 9) {
    if (2 < hostCpuSubtype) goto LAB_00001524;
    if (hostCpuSubtype < 0) goto LAB_00001544;
  }
  else {
    if ((0xb < hostCpuSubtype) && (hostCpuSubtype != 100)) {
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
  ((void (*)())_glePreInitGlobals)(sysctlStatusThenPluginResult);
  ((int (*)())_glePreInitTOC)();
  ((void (*)())_glePreInitNormalize)();
  ((void (*)())_glePreInitProjectionTransformFunc)();
  ((void (*)())_glePreInitModelviewTransformFunc)();
  ((void (*)())_glePreInitNormalTransformFunc)();
  ((void (*)())_glePreInitVertexSubmitFunc)();
  sysctlStatusThenPluginResult = ((int (*)())_glepGetPlugins)();
  if (sysctlStatusThenPluginResult != 0) {
    *majorVersion = 2;
    *minorVersion = 3;
    *outValue3 = 0x20000;
    ((void (*)())_gleOptimizeDisplayListCreateHashTable)(0);
  }
  return sysctlStatusThenPluginResult != 0;
}

/* _glepPluginConnectAll @ 0x15b4 (124 bytes) */
void _glepPluginConnectAll()
{
  int connected;
  int *plugin;
  
  if (_glep_plugin_head == 0) {
    ((void (*)())_glepLoadRenderers)();
    plugin = (int *)_glep_plugin_head;
    while (plugin != (int *)0x0) {
      connected = ((int (*)())_glepPluginConnect)(plugin);
      if (connected == 0) {
        plugin = (int *)_glepDeletePlugin(plugin);
      }
      else {
        plugin = (int *)*plugin;
      }
    }
  }
  return;
}

/* _glepLoadRenderers @ 0x1630 (856 bytes) */
void _glepLoadRenderers()
{
  char *envResourcesDir;
  int scannedPlugin;
  int pathLength;
  char *resourcesDir;
  int dirEntryCount;
  uint bitShift;
  undefined *bindSurfaceFunc;
  int compareResult;
  int nameLength;
  bool noCStringPtr;
  bool noHeapCopy;
  int entryOffset;
  undefined *cfAllocator;
  undefined *gleIoData;
  uint pluginRendererMask;
  int registryEntryThenBundleNameString;
  char *bundleName;
  int loopIndex;
  int memcmpResult;
  int dirEntries;
  char *nameCopy;
  uint allRendererBits;
  uint loopIndex2;
  int *pluginIter;
  int dirEntryName;
  undefined1 auStack_147 [7];
  char pluginPath [256];
  int nameList [4];
  
  gleIoData = PTR__gle_io_data_00112434;
  cfAllocator = PTR_00112430;
  allRendererBits = 0;
  loopIndex2 = 0;
  if (*(int *)PTR__gle_io_data_00112434 != 0) {
    do {
      registryEntryThenBundleNameString = *(int *)(loopIndex2 * 4 + *(int *)(gleIoData + 4));
      if ((registryEntryThenBundleNameString != 0) &&
         (registryEntryThenBundleNameString = _IORegistryEntryCreateCFProperty(registryEntryThenBundleNameString,&cfstr_IOGLBundleName,*(undefined4 *)cfAllocator,0),
         registryEntryThenBundleNameString != 0)) {
        nameCopy = (char *)0x0;
        bundleName = (char *)_CFStringGetCStringPtr(registryEntryThenBundleNameString,0);
        noCStringPtr = bundleName == (char *)0x0;
        if (noCStringPtr) {
          nameLength = _CFStringGetLength(registryEntryThenBundleNameString);
          nameCopy = (char *)_malloc(nameLength + 1);
          noHeapCopy = nameCopy == (char *)0x0;
          if ((!noHeapCopy) && (nameLength = _CFStringGetCString(registryEntryThenBundleNameString,nameCopy,nameLength + 1,0), nameLength != 0)) {
            bundleName = nameCopy;
            noCStringPtr = noHeapCopy;
          }
        }
        else {
          noHeapCopy = true;
        }
        if (!noCStringPtr) {
          _strncpy(pluginPath,"/System/Library/Extensions/",0x100);
          _strncat(pluginPath,bundleName,0x100);
          _strcat(pluginPath,".bundle/Contents/MacOS/");
          _strncat(pluginPath,bundleName,0x100);
          for (pluginIter = (int *)_glep_plugin_head; pluginIter != (int *)0x0; pluginIter = (int *)*pluginIter)
          {
            compareResult = _strcmp(pluginPath,pluginIter + 1);
            if (compareResult == 0) {
              pluginRendererMask = pluginIter[0x44] | 1 << (loopIndex2 & 0x3f);
              goto LAB_000017c4;
            }
          }
          pluginIter = (int *)((int (*)())_glepAddPlugin)();
          if (pluginIter != (int *)0x0) {
            _strcpy((int)pluginIter + 4,pluginPath);
            pluginRendererMask = 1 << (loopIndex2 & 0x3f);
LAB_000017c4:
            *(uint *)((int)pluginIter + 0x110) = pluginRendererMask;
          }
        }
        if (!noHeapCopy) {
          _free(nameCopy);
        }
        _CFRelease(registryEntryThenBundleNameString);
      }
      bitShift = loopIndex2 & 0x3f;
      loopIndex2 = loopIndex2 + 1;
      allRendererBits = allRendererBits | 1 << bitShift;
    } while (loopIndex2 < *(uint *)gleIoData);
  }
  gleIoData = PTR__gle_io_data_00112434;
  bindSurfaceFunc = PTR__gleBindSurface_00111e0c;
  if ((*(int *)(PTR__gle_io_data_00112434 + 0xc) == 0) ||
     (*(int *)(PTR__gle_io_data_00112434 + 0x10) == 0)) {
    *(undefined **)(PTR__gle_io_data_00112434 + 0xc) = PTR__gleDoNonSimpleFlush_00111e10;
    *(undefined **)(gleIoData + 0x10) = bindSurfaceFunc;
  }
  else {
    envResourcesDir = (char *)_getenv("GL_RESOURCES");
    resourcesDir = "/System/Library/Frameworks/OpenGL.framework/Versions/A/Resources/";
    if (envResourcesDir != (char *)0x0) {
      resourcesDir = envResourcesDir;
    }
    dirEntryCount = _scandir(resourcesDir,nameList,0,0);
    if (dirEntryCount != 0) {
      loopIndex = 0;
      if (0 < dirEntryCount) {
        do {
          dirEntries = nameList[0];
          entryOffset = loopIndex * 4;
          dirEntryName = *(int *)(entryOffset + nameList[0]) + 8;
          memcmpResult = _memcmp(dirEntryName,"GLDriver",8);
          if ((memcmpResult == 0) || (memcmpResult = _memcmp(dirEntryName,"GLRendererFloat",0xf), memcmpResult == 0)) {
            scannedPlugin = ((int (*)())_glepAddPlugin)();
            if (scannedPlugin == 0) {
              return;
            }
            _strncpy(pluginPath,resourcesDir,0x100);
            _strncat(pluginPath,(char *)(*(int *)(entryOffset + nameList[0]) + 8),0x100);
            _strcat(pluginPath,"/");
            _strncat(pluginPath,(char *)(*(int *)(entryOffset + nameList[0]) + 8),0x100);
            pathLength = _strlen(pluginPath);
            auStack_147[pathLength] = 0;
            _strncpy((char *)(scannedPlugin + 4),pluginPath,0x100);
            *(uint *)(scannedPlugin + 0x110) = allRendererBits;
            dirEntries = nameList[0];
          }
          loopIndex = loopIndex + 1;
          _free(*(undefined4 *)(entryOffset + dirEntries));
        } while (loopIndex < dirEntryCount);
      }
      _free(nameList[0]);
    }
  }
  return;
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
  undefined4 *result;
  undefined4 *tailLink;
  undefined4 *node;
  undefined4 *newPlugin;
  
  tailLink = &_glep_plugin_head;
  for (node = _glep_plugin_head; node != (undefined4 *)0x0; node = (undefined4 *)*node) {
    tailLink = node;
  }
  newPlugin = (undefined4 *)_malloc(0x208);
  result = (undefined4 *)0x0;
  if (newPlugin != (undefined4 *)0x0) {
    *tailLink = newPlugin;
    newPlugin[0x44] = 0;
    *newPlugin = 0;
    *(undefined1 *)(newPlugin + 1) = 0;
    newPlugin[0x41] = 0;
    newPlugin[0x42] = 0;
    newPlugin[0x43] = 0;
    result = newPlugin;
  }
  return result;
}

/* _glepPluginConnect @ 0x1a40 (280 bytes) */
int _glepPluginConnect(plugin)
  int plugin;
{
  int validateResult;
  int module;
  int createStatus;
  int symbolThenAddress;
  undefined4 result;
  char *cursor;
  int *symbolSlot;
  int objectFileImage [7];
  
  if (*(int *)(plugin + 0x108) == 0) {
    createStatus = _NSCreateObjectFileImageFromFile(plugin + 4,objectFileImage);
    if ((createStatus == 1) && (objectFileImage[0] != 0)) {
      *(int *)(plugin + 0x108) = objectFileImage[0];
      module = _NSLinkModule(objectFileImage[0],plugin + 4,2);
      *(int *)(plugin + 0x10c) = module;
      if (module != 0) {
        validateResult = ((int (*)())_glepValidatePlugin)(plugin);
        if (validateResult == 0) {
          return 0;
        }
        symbolSlot = (int *)(plugin + 0x114);
        cursor = _glep_gld_names;
        do {
          symbolThenAddress = _NSLookupSymbolInModule(*(undefined4 *)(plugin + 0x10c),cursor);
          if (symbolThenAddress == 0) {
LAB_00001b38:
            _glepPluginDisconnect(plugin);
            goto LAB_00001b40;
          }
          symbolThenAddress = _NSAddressOfSymbol(symbolThenAddress);
          *symbolSlot = symbolThenAddress;
          symbolSlot = symbolSlot + 1;
          if (symbolThenAddress == 0) goto LAB_00001b38;
          cursor = cursor + 0x20;
        } while ((int)symbolSlot < plugin + 0x208);
        goto LAB_00001b30;
      }
      *(undefined4 *)(plugin + 0x104) = 0xffff;
      _NSDestroyObjectFileImage(*(undefined4 *)(plugin + 0x108));
      *(undefined4 *)(plugin + 0x108) = 0;
    }
    else {
      *(undefined4 *)(plugin + 0x104) = 0xffff;
    }
LAB_00001b40:
    result = 0;
  }
  else {
LAB_00001b30:
    result = 1;
  }
  return result;
}

/* _glepValidatePlugin @ 0x1b58 (368 bytes) */
int _glepValidatePlugin(plugin)
  int plugin;
{
  int infoSymbol;
  bool listEmpty;
  uint otherPluginId;
  int *otherPlugin;
  int initSymbol;
  code *symbolFunction;
  int versionMajor;
  int versionMinor;
  int versionRevision;
  uint pluginId [3];
  
  if (((*(int *)(plugin + 0x104) != 0xffff) &&
      (initSymbol = _NSLookupSymbolInModule(*(undefined4 *)(plugin + 0x10c),"_gldInitializeLibrary"),
      initSymbol != 0)) && (symbolFunction = (code *)_NSAddressOfSymbol(initSymbol), symbolFunction != (code *)0x0)) {
    (*symbolFunction)(*(undefined4 *)(PTR__gle_io_data_00112434 + 4),
              *(undefined4 *)(PTR__gle_io_data_00112434 + 8),*(undefined4 *)(plugin + 0x110),
              *(undefined4 *)(PTR__gle_io_data_00112434 + 0xc),
              *(undefined4 *)(PTR__gle_io_data_00112434 + 0x10));
    infoSymbol = _NSLookupSymbolInModule(*(undefined4 *)(plugin + 0x10c),_glep_gld_names);
    if (((infoSymbol != 0) && (symbolFunction = (code *)_NSAddressOfSymbol(infoSymbol), symbolFunction != (code *)0x0)) &&
       (infoSymbol = (*symbolFunction)(&versionMajor,&versionMinor,&versionRevision,pluginId), infoSymbol != 0)) {
      if (*(int *)(plugin + 0x104) == 0) {
        pluginId[0] = pluginId[0] & 0xff00;
        if (((versionMajor != 2) || (versionMinor != 4)) || (versionRevision != 0xb)) goto LAB_00001c9c;
        listEmpty = _glep_plugin_head == (int *)0x0;
        if (!listEmpty) {
          otherPluginId = _glep_plugin_head[0x41];
          otherPlugin = _glep_plugin_head;
          while (pluginId[0] != otherPluginId) {
            otherPlugin = (int *)*otherPlugin;
            if (otherPlugin == (int *)0x0) goto LAB_00001c90;
            listEmpty = false;
            otherPluginId = otherPlugin[0x41];
          }
          if (!listEmpty) goto LAB_00001c9c;
        }
LAB_00001c90:
        *(uint *)(plugin + 0x104) = pluginId[0];
      }
      return 1;
    }
  }
LAB_00001c9c:
  _glepPluginDisconnect(plugin);
  *(undefined4 *)(plugin + 0x104) = 0xffff;
  return 0;
}

/* _glePreInitGlobals @ 0x1cc8 (212 bytes) */
void _glePreInitGlobals()
{
  undefined1 *cursor2;
  int remaining3;
  int remaining2;
  double intToDoubleMagic;
  float ubyteToFloatScale;
  undefined *globalsStruct;
  uint flippedIndex;
  float *dstCursor;
  undefined1 *cursor;
  uint loopIndex;
  int remaining;
  
  globalsStruct = PTR__gle_globals_struct_00112070;
  ubyteToFloatScale = FLOAT_00108e78;
  intToDoubleMagic = DOUBLE_00108d58;
  loopIndex = 0;
  remaining = 0x100;
  dstCursor = (float *)PTR__gle_globals_struct_00112070;
  do {
    flippedIndex = loopIndex ^ 0x80000000;
    loopIndex = loopIndex + 1;
    *dstCursor = (float)((double)CONCAT44(0x43300000,flippedIndex) - intToDoubleMagic) * ubyteToFloatScale;
    dstCursor = dstCursor + 1;
    remaining = remaining + -1;
  } while (remaining != 0);
  globalsStruct[0x404] = 3;
  globalsStruct[0x401] = 3;
  remaining2 = 8;
  globalsStruct[0x405] = 4;
  globalsStruct[0x407] = 0;
  globalsStruct[0x400] = 4;
  globalsStruct[0x402] = 4;
  cursor = globalsStruct + 0x408;
  globalsStruct[0x406] = 1;
  globalsStruct[0x403] = 1;
  do {
    *cursor = 4;
    cursor = cursor + 1;
    remaining2 = remaining2 + -1;
  } while (remaining2 != 0);
  cursor2 = globalsStruct + 0x410;
  remaining3 = 0x10;
  do {
    *cursor2 = 4;
    cursor2 = cursor2 + 1;
    remaining3 = remaining3 + -1;
  } while (remaining3 != 0);
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
  undefined4 *vectorSlot10;
  undefined4 *identityByteVector;
  undefined4 *vectorSlot20;
  undefined *tocStruct;
  
  tocStruct = PTR__gle_rtc_toc_struct_0011205c;
  vectorSlot10 = (undefined4 *)((uint)(PTR__gle_rtc_toc_struct_0011205c + 0x10) & 0xfffffff0);
  *vectorSlot10 = 0x100004;
  vectorSlot10[1] = 0x10000;
  vectorSlot10[2] = 0x200008;
  vectorSlot10[3] = 0x20000;
  vectorSlot20 = (undefined4 *)((uint)(tocStruct + 0x20) & 0xfffffff0);
  *vectorSlot20 = 0x40;
  vectorSlot20[1] = 0x80;
  vectorSlot20[2] = 0;
  vectorSlot20[3] = 0;
  identityByteVector = (undefined4 *)((uint)tocStruct & 0xfffffff0);
  *identityByteVector = 0x3020100;
  identityByteVector[1] = 0x7060504;
  identityByteVector[2] = 0xb0a0908;
  identityByteVector[3] = 0xf0e0d0c;
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
  uint bucketOffset;
  int hashTableThenChainCursor;
  undefined4 entryWord2;
  int bucketHeadThenChainTail;
  undefined4 *allocatedBlock;
  uint execFunc;
  undefined4 entryWord3;
  undefined **cursor;
  int loopIndex;
  
  if ((_gleDisplayListFunctionHash == 0) &&
     (_gleDisplayListFunctionHash = _calloc(1,0x80),
     PTR__glBegin_ListExec_00110a2c != (undefined *)0x0)) {
    loopIndex = 0;
    cursor = &PTR__glBegin_ListExec_00110a2c;
    do {
      allocatedBlock = (undefined4 *)_malloc(0x10);
      hashTableThenChainCursor = _gleDisplayListFunctionHash;
      entryWord2 = *(undefined4 *)((int)&fi_word2 + loopIndex);
      entryWord3 = *(undefined4 *)((int)&fi_word3 + loopIndex);
      execFunc = *(uint *)((int)&PTR__glBegin_ListExec_00110a2c + loopIndex);
      bucketOffset = execFunc & 0x7c;
      *allocatedBlock = *(undefined4 *)((int)&_fi + loopIndex);
      allocatedBlock[2] = entryWord2;
      allocatedBlock[3] = entryWord3;
      allocatedBlock[1] = execFunc;
      bucketHeadThenChainTail = *(int *)(bucketOffset + hashTableThenChainCursor);
      if (bucketHeadThenChainTail == 0) {
        *(undefined4 **)(bucketOffset + hashTableThenChainCursor) = allocatedBlock;
      }
      else {
        for (hashTableThenChainCursor = *(int *)(bucketHeadThenChainTail + 0xc); hashTableThenChainCursor != 0; hashTableThenChainCursor = *(int *)(hashTableThenChainCursor + 0xc)) {
          bucketHeadThenChainTail = hashTableThenChainCursor;
        }
        *(undefined4 **)(bucketHeadThenChainTail + 0xc) = allocatedBlock;
      }
      cursor = cursor + 4;
      loopIndex = loopIndex + 0x10;
    } while (*cursor != (undefined *)0x0);
  }
  return;
}

/* _gliGetInteger @ 0x2238 (1900 bytes) */
int _gliGetInteger(glContext, stateId, valuePtr)
  int glContext;
  uint stateId;
  uint *valuePtr;
{
  uint stateValue;
  int sharedStateThenProgramOrShaderObject;
  int textureObject;
  undefined4 driverResult;
  undefined4 objectKind;
  undefined *hashTable;
  
  if ((stateId == 0xe0) && (valuePtr != (uint *)0x0)) {
    *valuePtr = 0xaa8;
    return 0;
  }
  if ((glContext == 0) || (*(int *)(glContext + 0x467c) != 0x3463a223)) {
    return 0x2714;
  }
  if (valuePtr == (uint *)0x0) {
    return 0x271e;
  }
  if (stateId == 0x184) {
    stateValue = (uint)*(short *)(glContext + 0x48bc);
    goto LAB_0000296c;
  }
  if (stateId < 0x185) {
    if (stateId == 0x164) {
      stateValue = (uint)*(short *)(glContext + 0x509a);
      goto LAB_0000296c;
    }
    if (0x164 < stateId) {
      if (stateId == 0x174) {
        stateValue = (uint)*(short *)(glContext + 0x49be);
      }
      else if (stateId < 0x175) {
        if (stateId == 0x16a) {
          stateValue = (uint)*(short *)(glContext + 0x48b4);
        }
        else if (stateId < 0x16b) {
          if (stateId == 0x166) {
            stateValue = (uint)*(short *)(glContext + 0x50a4);
          }
          else {
            if (stateId != 0x168) goto LAB_00002978;
            stateValue = (uint)*(short *)(glContext + 0x50a6);
          }
        }
        else if (stateId == 0x16c) {
          stateValue = (uint)*(short *)(glContext + 0x48b6);
        }
        else {
          if (stateId != 0x172) goto LAB_00002978;
          stateValue = (uint)*(short *)(glContext + 0x49bc);
        }
      }
      else if (stateId == 0x17c) {
        stateValue = (uint)*(short *)(glContext + 0x48a4);
      }
      else if (stateId < 0x17d) {
        if (stateId == 0x176) {
          stateValue = (uint)*(short *)(glContext + 0x49c0);
        }
        else {
          if (stateId != 0x178) goto LAB_00002978;
          stateValue = (uint)*(short *)(glContext + 0x49c2);
        }
      }
      else if (stateId == 0x180) {
        stateValue = (uint)*(short *)(glContext + 0x48ac);
      }
      else if (stateId < 0x181) {
        if (stateId != 0x17e) {
LAB_00002978:
          driverResult = (**(code **)(glContext + 0x477c))(*(undefined4 *)(glContext + 0x4688),stateId,valuePtr)
          ;
          return driverResult;
        }
        stateValue = (uint)*(short *)(glContext + 0x48a6);
      }
      else {
        if (stateId != 0x182) goto LAB_00002978;
        stateValue = (uint)*(short *)(glContext + 0x48ae);
      }
      goto LAB_0000296c;
    }
    if (stateId == 0x135) {
      stateValue = *(uint *)((uint)*(byte *)(glContext + 0x85a8) * 0x2e0 + glContext + 0x8888);
LAB_00002638:
      *valuePtr = stateValue;
      return 0;
    }
    if (stateId < 0x136) {
      if (stateId != 0xe5) {
        if (stateId < 0xe6) {
          if (stateId == 0xdd) {
            stateValue = (uint)*(byte *)(glContext + 0x4690);
            goto LAB_0000296c;
          }
          if (stateId == 0xe4) {
            stateValue = *(uint *)(glContext + 0x7590);
            goto LAB_00002638;
          }
        }
        else if (stateId == 0x126) {
          textureObject = _gleLookUpNonProxyTexture(glContext,*valuePtr);
          if (textureObject == 0) {
            return 0x271a;
          }
          stateId = 0x126;
          *valuePtr = *(uint *)(textureObject + (uint)*(byte *)(glContext + 0x85a8) * 4);
        }
        else if (stateId == 0x133) {
          stateValue = (uint)*(byte *)(glContext + 0x5410);
          goto LAB_00002638;
        }
        goto LAB_00002978;
      }
      stateValue = (uint)*(byte *)(glContext + 0x4693);
      goto LAB_00002638;
    }
    if (stateId == 0x15e) {
      stateValue = (uint)*(short *)(glContext + 0x508c);
      goto LAB_0000296c;
    }
    if (0x15e < stateId) {
      if (stateId == 0x160) {
        stateValue = (uint)*(short *)(glContext + 0x508e);
      }
      else {
        if (stateId != 0x162) goto LAB_00002978;
        stateValue = (uint)*(short *)(glContext + 0x5098);
      }
      goto LAB_0000296c;
    }
    if (stateId == 0x136) {
      stateValue = (uint)(*(char *)(glContext + 0x7580) == '\x01');
      goto LAB_0000296c;
    }
    if (stateId != 0x137) goto LAB_00002978;
    stateValue = *(uint *)(*(int *)((uint)*(byte *)(glContext + 0x85a6) * 0x2e0 + glContext + 0x8884) + 0x104
                     ) & 0xff00;
    if ((stateValue == 0x200) || (stateValue == 0x400)) {
      stateValue = 0;
      goto LAB_0000296c;
    }
    stateValue = -(uint)*(byte *)(glContext + 0x7581);
  }
  else {
    if (stateId == 0x643) {
      objectKind = 6;
      hashTable = (undefined *)(*(int *)(glContext + 0x5148) + 0x6018);
      goto LAB_0000272c;
    }
    if (0x643 < stateId) {
      if (stateId == 0x649) {
        objectKind = 1;
        hashTable = ((unsigned char *)0x00001004) + *(int *)(glContext + 0x5148);
LAB_0000272c:
        _gleGetHashMachineObjectNameTargetPairs(glContext,hashTable,objectKind,valuePtr);
        return 0;
      }
      if (stateId < 0x64a) {
        if (stateId == 0x646) {
          hashTable = (undefined *)(glContext + 0x6440);
          objectKind = 0xfffffff5;
        }
        else if (stateId < 0x647) {
          if (stateId == 0x644) {
            objectKind = 5;
            hashTable = (undefined *)(*(int *)(glContext + 0x5148) + 0x5014);
          }
          else {
            if (stateId != 0x645) goto LAB_00002978;
            objectKind = 7;
            hashTable = (undefined *)(*(int *)(glContext + 0x5148) + 0x701c);
          }
        }
        else if (stateId == 0x647) {
          hashTable = (undefined *)(glContext + 0x543c);
          objectKind = 0xfffffff4;
        }
        else {
          if (stateId != 0x648) goto LAB_00002978;
          hashTable = *(undefined **)(glContext + 0x5148);
          objectKind = 0;
        }
        goto LAB_0000272c;
      }
      if (stateId == 0x6a6) {
        sharedStateThenProgramOrShaderObject = *(int *)(glContext + 0x5148);
        if (*(char *)(sharedStateThenProgramOrShaderObject + 0x8024) != '\0') {
          _pthread_mutex_lock(sharedStateThenProgramOrShaderObject + 0x8028);
          sharedStateThenProgramOrShaderObject = *(int *)(glContext + 0x5148);
        }
        sharedStateThenProgramOrShaderObject = _gleLookupHashObject(sharedStateThenProgramOrShaderObject + 0x6018,*valuePtr);
        if (sharedStateThenProgramOrShaderObject == 0) goto LAB_000028f4;
        if (*(int *)(sharedStateThenProgramOrShaderObject + 0x10) == 0x8b40) {
          stateValue = _ShGetLinkerStats(*(undefined4 *)(sharedStateThenProgramOrShaderObject + 0x40));
        }
        else {
          if (*(int *)(sharedStateThenProgramOrShaderObject + 0x10) != 0x8b48) goto LAB_000028f4;
          stateValue = _ShGetCompilerStats(*(undefined4 *)(sharedStateThenProgramOrShaderObject + 0x30));
        }
      }
      else if (stateId < 0x6a7) {
        if (stateId == 0x6a4) {
          sharedStateThenProgramOrShaderObject = *(int *)(glContext + 0x5148);
          if (*(char *)(sharedStateThenProgramOrShaderObject + 0x8024) != '\0') {
            _pthread_mutex_lock(sharedStateThenProgramOrShaderObject + 0x8028);
            sharedStateThenProgramOrShaderObject = *(int *)(glContext + 0x5148);
          }
          sharedStateThenProgramOrShaderObject = _gleLookupHashObject(sharedStateThenProgramOrShaderObject + 0x6018,*valuePtr);
          if (sharedStateThenProgramOrShaderObject == 0) goto LAB_000028f4;
          if (*(int *)(sharedStateThenProgramOrShaderObject + 0x10) == 0x8b40) {
            stateValue = _ShGetLinkerPPStream(*(undefined4 *)(sharedStateThenProgramOrShaderObject + 0x40));
          }
          else {
            if (*(int *)(sharedStateThenProgramOrShaderObject + 0x10) != 0x8b48) goto LAB_000028f4;
            stateValue = _ShGetCompilerPPStream(*(undefined4 *)(sharedStateThenProgramOrShaderObject + 0x30));
          }
        }
        else {
          if (stateId != 0x6a5) goto LAB_00002978;
          sharedStateThenProgramOrShaderObject = *(int *)(glContext + 0x5148);
          if (*(char *)(sharedStateThenProgramOrShaderObject + 0x8024) != '\0') {
            _pthread_mutex_lock(sharedStateThenProgramOrShaderObject + 0x8028);
            sharedStateThenProgramOrShaderObject = *(int *)(glContext + 0x5148);
          }
          sharedStateThenProgramOrShaderObject = _gleLookupHashObject(sharedStateThenProgramOrShaderObject + 0x6018,*valuePtr);
          if (sharedStateThenProgramOrShaderObject == 0) goto LAB_000028f4;
          if (*(int *)(sharedStateThenProgramOrShaderObject + 0x10) == 0x8b40) {
            stateValue = _ShGetLinkerBindingTable(*(undefined4 *)(sharedStateThenProgramOrShaderObject + 0x40));
          }
          else {
            if (*(int *)(sharedStateThenProgramOrShaderObject + 0x10) != 0x8b48) goto LAB_000028f4;
            stateValue = _ShGetCompilerSymbolTable(*(undefined4 *)(sharedStateThenProgramOrShaderObject + 0x30));
          }
        }
      }
      else {
        if (stateId == 0x6a8) {
          stateValue = *(uint *)(glContext + 0x7598);
          goto LAB_00002638;
        }
        if (stateId < 0x6a8) {
          stateValue = *(uint *)(glContext + 0x7594);
          goto LAB_00002638;
        }
        if (stateId != 0x6a9) goto LAB_00002978;
        sharedStateThenProgramOrShaderObject = *(int *)(glContext + 0x5148);
        if (*(char *)(sharedStateThenProgramOrShaderObject + 0x8024) != '\0') {
          _pthread_mutex_lock(sharedStateThenProgramOrShaderObject + 0x8028);
          sharedStateThenProgramOrShaderObject = *(int *)(glContext + 0x5148);
        }
        sharedStateThenProgramOrShaderObject = _gleLookupHashObject(sharedStateThenProgramOrShaderObject + 0x6018,*valuePtr);
        if (sharedStateThenProgramOrShaderObject == 0) goto LAB_000028f4;
        if (*(int *)(sharedStateThenProgramOrShaderObject + 0x10) == 0x8b40) {
          stateValue = _ShGetLinkerShaderToProgramString(*(undefined4 *)(sharedStateThenProgramOrShaderObject + 0x40));
        }
        else {
          if (*(int *)(sharedStateThenProgramOrShaderObject + 0x10) != 0x8b48) goto LAB_000028f4;
          stateValue = _ShGetCompilerShaderToProgramString(*(undefined4 *)(sharedStateThenProgramOrShaderObject + 0x30));
        }
      }
      *valuePtr = stateValue;
LAB_000028f4:
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) == '\0') {
        return 0;
      }
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      return 0;
    }
    if (stateId == 0x3e2) {
      stateValue = (uint)*(byte *)(glContext + 0x7584);
      goto LAB_00002638;
    }
    if (stateId < 0x3e3) {
      if (stateId == 0x18a) {
        stateValue = (uint)*(short *)(glContext + 0x48c6);
      }
      else {
        if (0x18a < stateId) {
          if (stateId == 0x3e0) {
            stateValue = (uint)*(byte *)(glContext + 0x7587);
          }
          else {
            if (stateId != 0x3e1) goto LAB_00002978;
            stateValue = (uint)*(byte *)(glContext + 0x7586);
          }
          goto LAB_00002638;
        }
        if (stateId == 0x186) {
          stateValue = (uint)*(short *)(glContext + 0x48be);
        }
        else {
          if (stateId != 0x188) goto LAB_00002978;
          stateValue = (uint)*(short *)(glContext + 0x48c4);
        }
      }
      goto LAB_0000296c;
    }
    if (stateId == 0x640) {
      objectKind = 2;
      hashTable = (undefined *)(*(int *)(glContext + 0x5148) + 0x2008);
      goto LAB_0000272c;
    }
    if (0x640 < stateId) {
      if (stateId == 0x641) {
        objectKind = 3;
        hashTable = (undefined *)(*(int *)(glContext + 0x5148) + 0x300c);
      }
      else {
        if (stateId != 0x642) goto LAB_00002978;
        objectKind = 4;
        hashTable = (undefined *)(*(int *)(glContext + 0x5148) + 0x4010);
      }
      goto LAB_0000272c;
    }
    if (stateId == 0x3e4) {
      stateValue = (uint)*(byte *)(glContext + 0x53e7);
      goto LAB_00002638;
    }
    if (stateId != 0x4d3) goto LAB_00002978;
    stateValue = ~(int)*(short *)(glContext + 0x4a10);
  }
  stateValue = stateValue >> 0x1f;
LAB_0000296c:
  *valuePtr = stateValue;
  return 0;
}

/* _gliChoosePixelFormat @ 0x29a4 (260 bytes) */
int _gliChoosePixelFormat(pixelFormatListOut, attributes)
  int *pixelFormatListOut;
  int attributes;
{
  int nextFormat;
  int *linkSlot;
  int resultCode;
  int *plugin;
  int *pluginFormatOut [6];
  
  resultCode = 0x271e;
  if ((pixelFormatListOut != (int *)0x0) && (*pixelFormatListOut = 0, attributes != 0)) {
    plugin = (int *)((int (*)())_glepGetPlugins)();
    resultCode = 0x271f;
    linkSlot = pixelFormatListOut;
    if (plugin != (int *)0x0) {
      do {
        resultCode = (*(code *)plugin[0x46])(pluginFormatOut,attributes);
        if (pluginFormatOut[0] != (int *)0x0) {
          *linkSlot = (int)pluginFormatOut[0];
          pluginFormatOut[0][1] = pluginFormatOut[0][1] | 0x20000;
          nextFormat = *pluginFormatOut[0];
          linkSlot = pluginFormatOut[0];
          while (pluginFormatOut[0] = linkSlot, nextFormat != 0) {
            linkSlot = (int *)*linkSlot;
            linkSlot[1] = linkSlot[1] | 0x20000;
            nextFormat = *linkSlot;
          }
        }
        plugin = (int *)*plugin;
        if (plugin == (int *)0x0) {
          if (resultCode == 0) {
            return 0;
          }
          break;
        }
      } while (resultCode == 0);
      if (*pixelFormatListOut != 0) {
        ((int (*)())_gliDestroyPixelFormat)(*pixelFormatListOut);
        *pixelFormatListOut = 0;
      }
    }
  }
  return resultCode;
}

/* _gliQueryRendererInfo @ 0x2aa8 (292 bytes) */
int _gliQueryRendererInfo(rendererInfoListOut, forwardedArg2)
  int *rendererInfoListOut;
  undefined4 forwardedArg2;
{
  int *allocatedBlock;
  int *cursor;
  int loopIndex2;
  int *pluginCountCursor;
  undefined4 *pluginCursor;
  int *resultList;
  int pluginStatus;
  int *cursor2;
  int loopIndex;
  
  pluginStatus = 0;
  loopIndex = 0;
  if (rendererInfoListOut == (int *)0x0) {
    return 0x271e;
  }
  *rendererInfoListOut = 0;
  pluginCountCursor = (int *)((int (*)())_glepGetPlugins)();
  if (pluginCountCursor == (int *)0x0) {
    return 0x271f;
  }
  do {
    pluginCountCursor = (int *)*pluginCountCursor;
    loopIndex = loopIndex + 1;
  } while (pluginCountCursor != (int *)0x0);
  allocatedBlock = (int *)_malloc(loopIndex * 0x38);
  if (allocatedBlock == (int *)0x0) {
    return 0x2720;
  }
  pluginCursor = (undefined4 *)((int (*)())_glepGetPlugins)();
  loopIndex2 = 0;
  if (pluginCursor != (undefined4 *)0x0) {
    cursor2 = allocatedBlock + 0xe;
    cursor = allocatedBlock;
    do {
      pluginStatus = (*(code *)pluginCursor[0x48])(cursor,forwardedArg2);
      if (pluginStatus == 0) {
        loopIndex2 = loopIndex2 + 1;
        *cursor = (int)cursor2;
        cursor[1] = cursor[1] | 0x20000;
        cursor[2] = cursor[2] | 0x8000;
        cursor2 = cursor2 + 0xe;
        cursor = cursor + 0xe;
        pluginCursor = (undefined4 *)*pluginCursor;
      }
      else {
        if (pluginStatus != 0x2719) break;
        pluginCursor = (undefined4 *)*pluginCursor;
        pluginStatus = 0;
      }
    } while (pluginCursor != (undefined4 *)0x0);
    if ((loopIndex2 != 0) && (pluginStatus == 0)) {
      allocatedBlock[loopIndex2 * 0xe + -0xe] = 0;
      resultList = allocatedBlock;
      goto LAB_00002bb0;
    }
  }
  resultList = (int *)0x0;
  _free(allocatedBlock);
LAB_00002bb0:
  *rendererInfoListOut = (int)resultList;
  return pluginStatus;
}

/* _gliDestroyRendererInfo @ 0x2bcc (52 bytes) */
int _gliDestroyRendererInfo(rendererInfo)
  int rendererInfo;
{
  undefined4 cglError;
  
  cglError = 0x271e;
  if (rendererInfo != 0) {
    _free(rendererInfo);
    cglError = 0;
  }
  return cglError;
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
int _glepGetPlugin(pluginId)
  int pluginId;
{
  int *plugin;
  
  plugin = (int *)_glep_plugin_head;
  while( true ) {
    if (plugin == (int *)0x0) {
      return 0;
    }
    if (pluginId == plugin[0x41]) break;
    plugin = (int *)*plugin;
  }
  return (int)plugin;
}

/* _gliCreateContext @ 0x2d18 (1112 bytes) */
int _gliCreateContext(contextOut, rendererList, shareContext, dispatchTable4680, dispatchTable4684, createFlags, unusedArg7, unusedArg8)
  int *contextOut;
  int *rendererList;
  int shareContext;
  undefined4 dispatchTable4680;
  undefined4 dispatchTable4684;
  uint createFlags;
  undefined4 unusedArg7;
  undefined4 unusedArg8;
{
  uint loopIndex3;
  int loopIndex2;
  int loopIndex;
  undefined4 *rendererContextPtr;
  bool flagOrAllPluginsLoaded;
  bool flagOrNoShareContext;
  int rendererRecord;
  int glContext;
  uint pluginId;
  int pluginOrOffsetOrReleaseResult;
  undefined4 sharedStateOrShareArg;
  int sharedStateOrResult;
  int rendererCursorOrIndex;
  uint entryIndex;
  uint defaultIndexOrPluginFlags;
  uint rendererCountOrPluginId;
  int *listEntryOrRendererDispatch;
  
  defaultIndexOrPluginFlags = 0xff;
  flagOrNoShareContext = false;
  if (contextOut == (int *)0x0) {
    return 0x271e;
  }
  *contextOut = 0;
  rendererCountOrPluginId = 0;
  listEntryOrRendererDispatch = rendererList;
  if (rendererList != (int *)0x0) {
    do {
      entryIndex = rendererCountOrPluginId;
      if ((listEntryOrRendererDispatch[1] & 0xff0000U) != 0x20000) {
        return 0x2712;
      }
      if ((listEntryOrRendererDispatch[2] & 0x40U) == 0) {
        flagOrNoShareContext = true;
      }
      rendererCountOrPluginId = listEntryOrRendererDispatch[1] & 0xff00;
      if ((rendererCountOrPluginId == 0x400) || (rendererCountOrPluginId == 0x500)) {
        defaultIndexOrPluginFlags = entryIndex;
      }
      listEntryOrRendererDispatch = (int *)*listEntryOrRendererDispatch;
      rendererCountOrPluginId = entryIndex + 1;
    } while (listEntryOrRendererDispatch != (int *)0x0);
    if (rendererCountOrPluginId != 0) {
      flagOrAllPluginsLoaded = false;
      if ((flagOrNoShareContext) && ((createFlags & 1) != 0)) {
        flagOrAllPluginsLoaded = true;
      }
      if (flagOrAllPluginsLoaded) {
        if (defaultIndexOrPluginFlags == 0xff) {
          defaultIndexOrPluginFlags = rendererCountOrPluginId;
          rendererCountOrPluginId = entryIndex + 2;
        }
      }
      else {
        defaultIndexOrPluginFlags = 0xff;
      }
      if (8 < (int)rendererCountOrPluginId) {
        return 0x2712;
      }
      flagOrNoShareContext = shareContext == 0;
      if ((!flagOrNoShareContext) &&
         ((*(int *)(shareContext + 0x467c) != 0x3463a223 || (*(byte *)(shareContext + 0x85a4) != rendererCountOrPluginId)))) {
        return 0x2719;
      }
      glContext = ((int (*)())_gleDCBAlloc)(rendererCountOrPluginId * 0x2e0 + 0x85b0);
      if (glContext == 0) {
        return 0x2720;
      }
      loopIndex3 = 0;
      flagOrAllPluginsLoaded = rendererCountOrPluginId == 0;
      *(undefined2 *)(glContext + 0x360) = 2;
      *(undefined2 *)(glContext + 0x362) = 4;
      *(undefined1 *)(glContext + 0x85a6) = 0;
      *(char *)(glContext + 0x85a5) = (char)defaultIndexOrPluginFlags;
      *(undefined4 *)(glContext + 0x4680) = dispatchTable4680;
      *(undefined4 *)(glContext + 0x4684) = dispatchTable4684;
      *(undefined4 *)(glContext + 0x5148) = 0;
      *(char *)(glContext + 0x85a4) = (char)rendererCountOrPluginId;
      if (0 < (int)rendererCountOrPluginId) {
        rendererCursorOrIndex = glContext + 0x85ac;
        loopIndex2 = 0;
        listEntryOrRendererDispatch = rendererList;
        do {
          _memset(rendererCursorOrIndex,0,0x2e0);
          if (listEntryOrRendererDispatch == (int *)0x0) {
            defaultIndexOrPluginFlags = 0x400;
            pluginOrOffsetOrReleaseResult = ((int (*)())_glepGetPlugin)(0x400);
            listEntryOrRendererDispatch = rendererList;
            if (pluginOrOffsetOrReleaseResult == 0) {
              pluginId = 0x500;
              defaultIndexOrPluginFlags = 0x500;
              goto LAB_00002ef4;
            }
          }
          else {
            pluginId = listEntryOrRendererDispatch[1] & 0xff00;
            defaultIndexOrPluginFlags = listEntryOrRendererDispatch[1] & 0xff00ffff;
LAB_00002ef4:
            pluginOrOffsetOrReleaseResult = ((int (*)())_glepGetPlugin)(pluginId);
            if (pluginOrOffsetOrReleaseResult == 0) {
              flagOrAllPluginsLoaded = loopIndex3 == rendererCountOrPluginId;
              break;
            }
          }
          loopIndex3 = loopIndex3 + 1;
          rendererRecord = loopIndex2 + glContext;
          flagOrAllPluginsLoaded = loopIndex3 == rendererCountOrPluginId;
          loopIndex2 = loopIndex2 + 0x2e0;
          *(int *)(rendererRecord + 0x8884) = pluginOrOffsetOrReleaseResult;
          rendererCursorOrIndex = rendererCursorOrIndex + 0x2e0;
          *(uint *)(rendererRecord + 0x8888) = defaultIndexOrPluginFlags;
          listEntryOrRendererDispatch = (int *)*listEntryOrRendererDispatch;
        } while ((int)loopIndex3 < (int)rendererCountOrPluginId);
      }
      if (flagOrAllPluginsLoaded) {
        if (flagOrNoShareContext) {
          sharedStateOrShareArg = ((int (*)())_gleCreateSharedState)(glContext);
        }
        else {
          sharedStateOrShareArg = _gleShareSharedState(shareContext);
        }
        *(undefined4 *)(glContext + 0x5148) = sharedStateOrShareArg;
        sharedStateOrResult = *(int *)(glContext + 0x5148);
        if (sharedStateOrResult == 0) {
          _gleDCBFree(glContext);
          return 0x2720;
        }
        rendererCursorOrIndex = 0;
        listEntryOrRendererDispatch = rendererList;
        if (0 < (int)rendererCountOrPluginId) {
          while( true ) {
            if (listEntryOrRendererDispatch == (int *)0x0) {
              listEntryOrRendererDispatch = rendererList;
            }
            pluginOrOffsetOrReleaseResult = rendererCursorOrIndex * 0x2e0;
            if (flagOrNoShareContext) {
              sharedStateOrShareArg = 0;
            }
            else {
              sharedStateOrShareArg = *(undefined4 *)(pluginOrOffsetOrReleaseResult + shareContext + 0x85ac);
            }
            sharedStateOrResult = (**(code **)(*(int *)(pluginOrOffsetOrReleaseResult + glContext + 0x8884) + 300))
                              (pluginOrOffsetOrReleaseResult + glContext + 0x85ac,listEntryOrRendererDispatch,
                               *(undefined4 *)(rendererCursorOrIndex * 4 + sharedStateOrResult + 0x8054),sharedStateOrShareArg,
                               glContext + pluginOrOffsetOrReleaseResult + 0x85b0,glContext + 0x360,glContext + pluginOrOffsetOrReleaseResult + 0x86e0);
            if (sharedStateOrResult != 0) {
              pluginOrOffsetOrReleaseResult = _gleReleaseSharedState(glContext);
              if (-1 < rendererCursorOrIndex) {
                rendererRecord = rendererCursorOrIndex * 0x2e0 + glContext + 0x10000;
                do {
                  listEntryOrRendererDispatch = (int *)(rendererRecord + -0x777c);
                  rendererContextPtr = (undefined4 *)(rendererRecord + -0x7a54);
                  rendererRecord = rendererRecord + -0x2e0;
                  (**(code **)(*listEntryOrRendererDispatch + 0x130))(*rendererContextPtr);
                  rendererCursorOrIndex = rendererCursorOrIndex + -1;
                } while (-1 < rendererCursorOrIndex);
              }
              goto LAB_00003108;
            }
            rendererCursorOrIndex = rendererCursorOrIndex + 1;
            listEntryOrRendererDispatch = (int *)*listEntryOrRendererDispatch;
            if ((int)rendererCountOrPluginId <= rendererCursorOrIndex) break;
            sharedStateOrResult = *(int *)(glContext + 0x5148);
          }
        }
        *(int *)(glContext + 0x468c) = glContext + 0x85b0;
        *(undefined4 *)(glContext + 0x4688) = *(undefined4 *)(glContext + 0x85ac);
        *(undefined1 *)(glContext + 0x85a8) = 0;
        _memcpy(glContext + 0x4754,*(int *)(glContext + 0x8884) + 0x114,0xf4);
        if (_gl_list == 0) {
          ((int (*)())_gleCreateEnableHashTable)();
        }
        sharedStateOrResult = ((int (*)())_gleInitializeContext)(glContext);
        if (sharedStateOrResult == 0) {
          _gliSetCurrentPluginDispatchTable(glContext);
          _gliInitDispatchTable(glContext);
          _gliExecDispatchTable(glContext);
          *(int *)(glContext + 0x85a0) = _gl_list;
          _gl_list = glContext;
          *contextOut = glContext;
          return 0;
        }
        loopIndex = 0;
        pluginOrOffsetOrReleaseResult = _gleReleaseSharedState(glContext);
        if (*(char *)(glContext + 0x85a4) != '\0') {
          rendererRecord = glContext + 0x10000;
          do {
            listEntryOrRendererDispatch = (int *)(rendererRecord + -0x777c);
            loopIndex = loopIndex + 1;
            rendererContextPtr = (undefined4 *)(rendererRecord + -0x7a54);
            rendererRecord = rendererRecord + 0x2e0;
            (**(code **)(*listEntryOrRendererDispatch + 0x130))(*rendererContextPtr);
          } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
        }
LAB_00003108:
        if (pluginOrOffsetOrReleaseResult != 0) {
          _gleDestroySharedState(glContext);
        }
        _gleDCBFree(glContext);
        return sharedStateOrResult;
      }
      _gleDCBFree(glContext);
    }
  }
  return 0x2712;
}

/* _gleDCBAlloc @ 0x3170 (68 bytes) */
int _gleDCBAlloc(requestedSize)
  int requestedSize;
{
  int allocatedBlock;
  uint alignedBlock;
  
  allocatedBlock = _malloc(requestedSize + 0x3fU & 0xffffffe0);
  alignedBlock = 0;
  if (allocatedBlock != 0) {
    alignedBlock = allocatedBlock + 0x20U & 0xffffffe0;
    *(char *)(alignedBlock - 1) = (char)alignedBlock - (char)allocatedBlock;
  }
  return alignedBlock;
}

/* _gleCreateSharedState @ 0x31b4 (548 bytes) */
int _gleCreateSharedState(glContext)
  int glContext;
{
  int loopIndex3;
  int remaining3;
  int remaining;
  int iVar1;
  undefined4 *bucketCursor;
  int sharedState;
  undefined4 rendererHandle;
  int loopIndex;
  int loopIndex2;
  undefined2 *puVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  int *rendererSlot;
  uint loopIndex4;
  int remaining2;
  
  sharedState = _malloc(0x94d4);
  *(undefined4 *)(sharedState + 0x8020) = 1;
  *(undefined1 *)(sharedState + 0x8024) = 0;
  _pthread_mutex_init(sharedState + 0x8028,0);
  loopIndex4 = 0;
  if (*(char *)(glContext + 0x85a4) != '\0') {
    iVar9 = sharedState + 0x8054;
    rendererSlot = (int *)(glContext + 0x8884);
    do {
      iVar1 = *rendererSlot;
      rendererSlot = rendererSlot + 0xb8;
      iVar1 = (**(code **)(iVar1 + 0x124))(iVar9);
      if (iVar1 != 0) break;
      loopIndex4 = loopIndex4 + 1;
      iVar9 = iVar9 + 4;
    } while ((int)loopIndex4 < (int)(uint)*(byte *)(glContext + 0x85a4));
  }
  if (loopIndex4 == *(byte *)(glContext + 0x85a4)) {
    if ((int)loopIndex4 < 8) {
      iVar9 = 8 - loopIndex4;
      puVar10 = (undefined4 *)(loopIndex4 * 4 + sharedState + 0x8054);
      do {
        *puVar10 = 0;
        puVar10 = puVar10 + 1;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
    }
    loopIndex3 = 0;
    puVar10 = (undefined4 *)(sharedState + 0x1000);
    do {
      bucketCursor = (undefined4 *)(loopIndex3 * 0x1004 + sharedState);
      remaining = 0x400;
      do {
        *bucketCursor = 0;
        bucketCursor = bucketCursor + 1;
        remaining = remaining + -1;
      } while (remaining != 0);
      loopIndex3 = loopIndex3 + 1;
      *puVar10 = 0;
      puVar10 = puVar10 + 0x401;
    } while (loopIndex3 < 8);
    iVar8 = sharedState + 0x10000;
    loopIndex2 = 0;
    loopIndex = 0;
    iVar9 = iVar8;
    iVar1 = iVar8;
    do {
      puVar7 = (undefined2 *)(iVar9 + -0x778c);
      remaining2 = 0x100;
      puVar10 = (undefined4 *)(iVar8 + -0x7f8c);
      do {
        *puVar10 = 0;
        puVar10[1] = 0;
        puVar10 = puVar10 + 2;
        *puVar7 = 0;
        puVar7 = puVar7 + 1;
        remaining2 = remaining2 + -1;
      } while (remaining2 != 0);
      remaining3 = 9;
      puVar10 = (undefined4 *)(loopIndex * 4 + sharedState + 0x8a74);
      do {
        *puVar10 = 0xffffffff;
        puVar10 = puVar10 + 1;
        remaining3 = remaining3 + -1;
      } while (remaining3 != 0);
      loopIndex2 = loopIndex2 + 1;
      *(undefined4 *)(iVar1 + -0x7568) = 0;
      *(undefined4 *)(iVar1 + -0x7560) = 0;
      *(undefined4 *)(iVar1 + -0x7564) = 0;
      iVar8 = iVar8 + 0xa30;
      iVar9 = iVar9 + 0xa30;
      loopIndex = loopIndex + 0x28c;
      iVar1 = iVar1 + 0xa30;
    } while (loopIndex2 < 2);
  }
  else {
    iVar9 = loopIndex4 - 1;
    if (-1 < iVar9) {
      puVar10 = (undefined4 *)(iVar9 * 4 + sharedState + 0x8054);
      rendererSlot = (int *)(iVar9 * 0x2e0 + glContext + 0x8884);
      do {
        iVar1 = *rendererSlot;
        rendererSlot = rendererSlot + -0xb8;
        rendererHandle = *puVar10;
        puVar10 = puVar10 + -1;
        (**(code **)(iVar1 + 0x128))(rendererHandle);
        iVar9 = iVar9 + -1;
      } while (-1 < iVar9);
    }
    _pthread_mutex_destroy(sharedState + 0x8028);
    _free(sharedState);
    sharedState = 0;
  }
  return sharedState;
}

/* _gleCreateEnableHashTable @ 0x33d8 (2092 bytes) */
int _gleCreateEnableHashTable()
{
  undefined *errorFunc;
  undefined4 *cursor;
  undefined4 *allocatedBlock;
  undefined4 addResult;
  int remaining;
  
  allocatedBlock = (undefined4 *)_malloc(0x4000);
  errorFunc = PTR__gleSetEnable_Error_00110e18;
  remaining = 0x400;
  cursor = allocatedBlock;
  _gle_enable_hash_table = allocatedBlock;
  do {
    *cursor = 0;
    cursor[1] = errorFunc;
    cursor[2] = 0;
    cursor = cursor + 4;
    remaining = remaining + -1;
  } while (remaining != 0);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0x80d0,PTR__gleSetEnable_COLOR_TABLE_00110e14);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0x80d2,PTR__gleSetEnable_POST_COLOR_MATRIX_COLOR_TABLE_00110e10);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0x80d1,PTR__gleSetEnable_POST_CONVOLUTION_COLOR_TABLE_00110e0c);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0x8024,PTR__gleSetEnable_HISTOGRAM_00110e08);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0x802e,PTR__gleSetEnable_MINMAX_00110e04);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0x8010,PTR__gleSetEnable_CONVOLUTION_1D_00110e00);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0x8011,PTR__gleSetEnable_CONVOLUTION_2D_00110dfc);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0x8012,PTR__gleSetEnable_SEPARABLE_2D_00110df8);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0x8861,PTR__gleSetEnable_POINT_SPRITE_ARB_00110df4);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0xb60,PTR__gleSetEnable_FOG_00110df0);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0xb50,PTR__gleSetEnable_LIGHTING_00110dec);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0xde0,PTR__gleSetEnable_TEXTURE_1D_00110de8);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0xde1,PTR__gleSetEnable_TEXTURE_2D_00110de4);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0x806f,PTR__gleSetEnable_TEXTURE_3D_00110de0);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0x8513,PTR__gleSetEnable_TEXTURE_CUBE_MAP_00110ddc);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0x84f5,PTR__gleSetEnable_TEXTURE_RECTANGLE_EXT_00110dd8);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0x85b3,PTR__gleSetEnable_TEXTURE_RECTANGLE_EXT_00110dd8);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0x81fb,PTR__gleSetEnable_SHARED_TEXTURE_PALETTE_EXT_00110dd4);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0xb24,PTR__gleSetEnable_LINE_STIPPLE_00110dd0);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0xb42,PTR__gleSetEnable_POLYGON_STIPPLE_00110dcc);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0xb44,PTR__gleSetEnable_CULL_FACE_00110dc8);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0xbc0,PTR__gleSetEnable_ALPHA_TEST_00110dc4);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0xbe2,PTR__gleSetEnable_BLEND_00110dc0);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0xbf1,PTR__gleSetEnable_INDEX_LOGIC_OP_00110dbc);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0xbf2,PTR__gleSetEnable_COLOR_LOGIC_OP_00110db8);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0xbd0,PTR__gleSetEnable_DITHER_00110db4);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0xb90,PTR__gleSetEnable_STENCIL_TEST_00110db0);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0xb71,PTR__gleSetEnable_DEPTH_TEST_00110dac);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0x3000,PTR__gleSetEnable_CLIP_PLANE_00110da8);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0x3001,PTR__gleSetEnable_CLIP_PLANE_00110da8);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0x3002,PTR__gleSetEnable_CLIP_PLANE_00110da8);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0x3003,PTR__gleSetEnable_CLIP_PLANE_00110da8);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0x3004,PTR__gleSetEnable_CLIP_PLANE_00110da8);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0x3005,PTR__gleSetEnable_CLIP_PLANE_00110da8);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0x4000,PTR__gleSetEnable_LIGHT_00110da4);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0x4001,PTR__gleSetEnable_LIGHT_00110da4);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0x4002,PTR__gleSetEnable_LIGHT_00110da4);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0x4003,PTR__gleSetEnable_LIGHT_00110da4);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0x4004,PTR__gleSetEnable_LIGHT_00110da4);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0x4005,PTR__gleSetEnable_LIGHT_00110da4);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0x4006,PTR__gleSetEnable_LIGHT_00110da4);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0x4007,PTR__gleSetEnable_LIGHT_00110da4);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0xc60,PTR__gleSetEnable_TEXTURE_GEN_S_00110da0);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0xc61,PTR__gleSetEnable_TEXTURE_GEN_T_00110d9c);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0xc62,PTR__gleSetEnable_TEXTURE_GEN_R_00110d98);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0xc63,PTR__gleSetEnable_TEXTURE_GEN_Q_00110d94);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0xd97,PTR__gleSetEnable_MAP1_VERTEX_3_00110d90);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0xd98,PTR__gleSetEnable_MAP1_VERTEX_4_00110d8c);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0xd90,PTR__gleSetEnable_MAP1_COLOR_4_00110d88);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0xd91,PTR__gleSetEnable_MAP1_INDEX_00110d84);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0xd92,PTR__gleSetEnable_MAP1_NORMAL_00110d80);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0xd93,PTR__gleSetEnable_MAP1_TEXTURE_COORD_1_00110d7c);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0xd94,PTR__gleSetEnable_MAP1_TEXTURE_COORD_2_00110d78);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0xd95,PTR__gleSetEnable_MAP1_TEXTURE_COORD_3_00110d74);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0xd96,PTR__gleSetEnable_MAP1_TEXTURE_COORD_4_00110d70);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0xdb7,PTR__gleSetEnable_MAP2_VERTEX_3_00110d6c);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0xdb8,PTR__gleSetEnable_MAP2_VERTEX_4_00110d68);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0xdb0,PTR__gleSetEnable_MAP2_COLOR_4_00110d64);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0xdb1,PTR__gleSetEnable_MAP2_INDEX_00110d60);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0xdb2,PTR__gleSetEnable_MAP2_NORMAL_00110d5c);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0xdb3,PTR__gleSetEnable_MAP2_TEXTURE_COORD_1_00110d58);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0xdb4,PTR__gleSetEnable_MAP2_TEXTURE_COORD_2_00110d54);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0xdb5,PTR__gleSetEnable_MAP2_TEXTURE_COORD_3_00110d50);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0xdb6,PTR__gleSetEnable_MAP2_TEXTURE_COORD_4_00110d4c);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0xb10,PTR__gleSetEnable_POINT_SMOOTH_00110d48);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0xb20,PTR__gleSetEnable_LINE_SMOOTH_00110d44);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0xb41,PTR__gleSetEnable_POLYGON_SMOOTH_00110d40);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0xc11,PTR__gleSetEnable_SCISSOR_TEST_00110d3c);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0xb57,PTR__gleSetEnable_COLOR_MATERIAL_00110d38);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0xba1,PTR__gleSetEnable_NORMALIZE_00110d34);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0x803a,PTR__gleSetEnable_RESCALE_NORMAL_EXT_00110d30);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0xd80,PTR__gleSetEnable_AUTO_NORMAL_00110d2c);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0x2a01,PTR__gleSetEnable_POLYGON_OFFSET_POINT_00110d28);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0x2a02,PTR__gleSetEnable_POLYGON_OFFSET_LINE_00110d24);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0x8037,PTR__gleSetEnable_POLYGON_OFFSET_FILL_00110d20);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0x8522,PTR__gleSetEnable_REGISTER_COMBINERS_NV_00110d1c);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0x8535,PTR__gleSetEnable_PER_STAGE_CONSTANTS_NV_00110d18);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0x86de,PTR__gleSetEnable_TEXTURE_SHADER_NV_00110d14);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0x864f,PTR__gleSetEnable_DEPTH_CLAMP_NV_00110d10);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0x19262,PTR__gleSetEnable_RASTER_POSITION_UNCLIPPED_IBM_00110d0c);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0x6090,PTR__gleSetEnable_PN_TRIANGLES_ATI_00110d08);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0x809d,PTR__gleSetEnable_MULTISAMPLE_00110d04);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0x809e,PTR__gleSetEnable_SAMPLE_ALPHA_TO_COVERAGE_00110d00);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0x809f,PTR__gleSetEnable_SAMPLE_ALPHA_TO_ONE_00110cfc);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0x80a0,PTR__gleSetEnable_SAMPLE_COVERAGE_00110cf8);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0x86a7,PTR__gleSetEnable_VERTEX_BLEND_ARB_00110cf4);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0x86a6,PTR__gleSetEnable_WEIGHT_SUM_UNITY_ARB_00110cf0);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0x8620,PTR__gleSetEnable_VERTEX_PROGRAM_ARB_00110cec);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0x8642,PTR__gleSetEnable_VERTEX_PROGRAM_POINT_SIZE_ARB_00110ce8);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0x8643,PTR__gleSetEnable_VERTEX_PROGRAM_TWO_SIDE_ARB_00110ce4);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0x8804,PTR__gleSetEnable_FRAGMENT_PROGRAM_ARB_00110ce0);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0x8200,PTR__gleSetEnable_TEXT_FRAGMENT_SHADER_ATI_00110cdc);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0x8458,PTR__gleSetEnable_COLOR_SUM_00110cd8);
  ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0x8910,PTR__gleSetEnable_STENCIL_TEST_TWO_SIDE_EXT_00110cd4);
  addResult = ((int (*)())_gleAddEnableHashFunc)(allocatedBlock,0x8890,PTR__gleSetEnable_DEPTH_BOUNDS_TEST_EXT_00110cd0);
  return addResult;
}

/* _gleAddEnableHashFunc @ 0x3c04 (124 bytes) */
int _gleAddEnableHashFunc(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  undefined4 param_3;
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *allocatedBlock;
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
    allocatedBlock = (undefined4 *)_malloc(0x10);
    uVar1 = *(undefined4 *)(iVar6 + param_1);
    uVar4 = *(undefined4 *)(iVar5 + 8);
    uVar2 = *(undefined4 *)(iVar5 + 4);
    *(uint *)(iVar6 + param_1) = param_2;
    *(undefined4 **)(iVar5 + 8) = allocatedBlock;
    *allocatedBlock = uVar1;
    allocatedBlock[1] = uVar2;
    allocatedBlock[2] = uVar4;
  }
  *(undefined4 *)(iVar5 + 4) = param_3;
  return;
}

/* _gleInitializeContext @ 0x3c80 (532 bytes) */
int _gleInitializeContext(glContext)
  int glContext;
{
  int remaining2;
  int remaining;
  undefined *globalsStructPtr;
  undefined4 *dstCursor;
  undefined2 *dstCursor2;
  int allocatedBlock;
  int allocStatusThenListHead;
  
  remaining = 0x13;
  *(undefined4 *)(glContext + 0x4730) = 0;
  *(undefined4 *)(glContext + 0x471c) = 0;
  dstCursor = (undefined4 *)(glContext + 0x310);
  *(undefined4 *)(glContext + 0x4720) = 0;
  *(undefined4 *)(glContext + 0x4724) = 0;
  *(undefined4 *)(glContext + 0x4728) = 0;
  *(undefined4 *)(glContext + 0x472c) = 0;
  do {
    *dstCursor = 0;
    globalsStructPtr = PTR__gle_globals_struct_00112070;
    dstCursor = dstCursor + 1;
    remaining = remaining + -1;
  } while (remaining != 0);
  *(undefined1 *)(glContext + 0x7582) = *(undefined1 *)(*(int *)(glContext + 0x468c) + 0x25);
  *(undefined **)(glContext + 0x4674) = globalsStructPtr;
  *(undefined4 *)(glContext + 0x467c) = 0x3463a223;
  ((void (*)())_gleNullMemoryPointers)(glContext);
  allocStatusThenListHead = ((int (*)())_gleAllocVertexMachine)(glContext,0x24);
  if ((allocStatusThenListHead == 0) && (allocStatusThenListHead = ((int (*)())_gleAllocMaterials)(glContext), allocStatusThenListHead == 0)) {
    ((void (*)())_gleShareEnableHashTable)(glContext);
    allocStatusThenListHead = glContext + 0x7468;
    *(undefined4 *)(glContext + 0x747c) = 0;
    *(undefined4 *)(glContext + 0x7478) = 0;
    *(int *)(glContext + 0x7474) = allocStatusThenListHead;
    *(int *)(glContext + 0x7470) = allocStatusThenListHead;
    *(int *)(glContext + 0x746c) = allocStatusThenListHead;
    *(int *)(glContext + 0x7468) = allocStatusThenListHead;
    *(undefined4 *)(glContext + 0x7454) = 0;
    *(undefined4 *)(glContext + 0x7464) = 0;
    *(undefined4 *)(glContext + 0x7458) = 0;
    *(undefined4 *)(glContext + 0x745c) = 0;
    *(undefined4 *)(glContext + 0x7460) = 0;
    allocStatusThenListHead = ((int (*)())_gleAllocVertexArrays)(glContext);
    if ((allocStatusThenListHead == 0) && (allocStatusThenListHead = ((int (*)())_gleAllocFunctions)(glContext), allocStatusThenListHead == 0)) {
      ((void (*)())_gleInitConstants)(glContext);
      allocatedBlock = ((int (*)())_gleVecAlloc)(0x32c0);
      *(int *)(glContext + 0x4678) = allocatedBlock;
      if (allocatedBlock != 0) {
        *(undefined1 *)(glContext + 0x4692) = 1;
        *(undefined1 *)(glContext + 0x4690) = 1;
        *(ushort *)(glContext + 0x3118) = 0x405 - (ushort)(*(char *)(glContext + 0x7582) == '\0');
        remaining2 = 3;
        *(int *)(glContext + 0x337c) = glContext + 0x4734;
        *(undefined2 *)(glContext + 0x311a) = *(undefined2 *)(glContext + 0x3118);
        dstCursor2 = (undefined2 *)(glContext + 0x311c);
        *(undefined1 *)(glContext + 0x4694) = 0;
        *(undefined1 *)(glContext + 0x4691) = 0;
        *(undefined1 *)(glContext + 0x4693) = 0;
        do {
          *dstCursor2 = 0;
          dstCursor2 = dstCursor2 + 1;
          remaining2 = remaining2 + -1;
        } while (remaining2 != 0);
        ((void (*)())_gleInitGLDState)(glContext + 0x360);
        ((void (*)())_gleInitGLIState)(glContext);
        ((void (*)())_gleInitDerivedState)(glContext);
        ((void (*)())_gleInitTextureState)(glContext);
        ((void (*)())_gleInitPipelineProgramState)(glContext);
        ((void (*)())_gleInitShaderState)(glContext);
        ((void (*)())_gleInitBufferState)(glContext);
        ((void (*)())_glePPEmulatorInitialize)(glContext);
        ((void (*)())_gleInitVertexArrayState)(glContext);
        ((void (*)())_gleInitFenceMachine)(glContext);
        ((void (*)())_gleInitQueryMachine)(glContext);
        ((void (*)())_gleInitDrawPixelsObject)(glContext);
        _gleUpdatePrimitiveData(glContext);
        _gleUpdateState(glContext);
        *(undefined4 *)(glContext + 0x7590) = 0;
        return 0;
      }
    }
  }
  _gleTerminateContext(glContext);
  return allocStatusThenListHead;
}

/* _gleNullMemoryPointers @ 0x3e94 (416 bytes) */
void _gleNullMemoryPointers(glContext)
  int glContext;
{
  int remaining4;
  int remaining3;
  int loopIndex3;
  int loopIndex;
  int remaining2;
  int remaining;
  undefined4 *dstCursor;
  int pointerPairCursor;
  int rendererRecordCursor;
  int slotRecordCursor;
  int loopIndex2;
  int remaining5;
  
  dstCursor = (undefined4 *)(glContext + 0x4dd0);
  *(undefined4 *)(glContext + 0x4854) = 0;
  remaining = 1;
  *(undefined4 *)(glContext + 0x4678) = 0;
  do {
    remaining = remaining + -1;
    *dstCursor = 0;
    dstCursor = dstCursor + 1;
  } while (-1 < remaining);
  *(undefined4 *)(glContext + 0x5418) = 0;
  *(undefined4 *)(glContext + 0x4dd8) = 0;
  *(undefined4 *)(glContext + 0x4850) = 0;
  *(undefined4 *)(glContext + 0x49ac) = 0;
  *(undefined4 *)(glContext + 0x49b4) = 0;
  *(undefined4 *)(glContext + 0x49b8) = 0;
  *(undefined4 *)(glContext + 0x5088) = 0;
  *(undefined4 *)(glContext + 0x5094) = 0;
  *(undefined4 *)(glContext + 0x50a0) = 0;
  *(undefined4 *)(glContext + 0x48a0) = 0;
  *(undefined4 *)(glContext + 0x48a8) = 0;
  *(undefined4 *)(glContext + 0x48c0) = 0;
  *(undefined4 *)(glContext + 0x48b0) = 0;
  *(undefined4 *)(glContext + 0x48b8) = 0;
  *(undefined4 *)(glContext + 0x49d0) = 0;
  *(undefined4 *)(glContext + 0x49d8) = 0;
  pointerPairCursor = glContext;
  do {
    *(undefined4 *)(pointerPairCursor + 0x5420) = 0;
    *(undefined4 *)(pointerPairCursor + 0x5428) = 0;
    pointerPairCursor = pointerPairCursor + 4;
  } while (pointerPairCursor <= glContext + 4);
  rendererRecordCursor = glContext + 0x10000;
  loopIndex2 = 0;
  *(undefined4 *)(glContext + 0x5430) = 0;
  if (*(char *)(glContext + 0x85a4) != '\0') {
    do {
      *(undefined4 *)(rendererRecordCursor + -0x7788) = 0;
      loopIndex2 = loopIndex2 + 1;
      *(undefined4 *)(rendererRecordCursor + -0x7784) = 0;
      rendererRecordCursor = rendererRecordCursor + 0x2e0;
    } while (loopIndex2 < (int)(uint)*(byte *)(glContext + 0x85a4));
  }
  loopIndex3 = 0;
  *(undefined4 *)(glContext + 0x7484) = 0;
  *(undefined4 *)(glContext + 0x4a60) = 0;
  *(undefined4 *)(glContext + 0x4a64) = 0;
  slotRecordCursor = glContext;
  do {
    dstCursor = (undefined4 *)(slotRecordCursor + 0x5154);
    remaining5 = 5;
    do {
      *dstCursor = 0;
      dstCursor = dstCursor + 1;
      remaining5 = remaining5 + -1;
    } while (remaining5 != 0);
    loopIndex3 = loopIndex3 + 1;
    slotRecordCursor = slotRecordCursor + 0x14;
  } while (loopIndex3 < 0x10);
  remaining2 = 0x10;
  dstCursor = (undefined4 *)(glContext + 0x52d4);
  do {
    *dstCursor = 0;
    dstCursor = dstCursor + 1;
    remaining2 = remaining2 + -1;
  } while (remaining2 != 0);
  remaining3 = 3;
  pointerPairCursor = glContext + 0x52b0;
  do {
    *(undefined4 *)(pointerPairCursor + 0xc) = 0;
    *(undefined4 *)(pointerPairCursor + 0x18) = 0;
    pointerPairCursor = pointerPairCursor + 4;
    remaining3 = remaining3 + -1;
  } while (remaining3 != 0);
  remaining4 = 5;
  pointerPairCursor = glContext;
  do {
    *(undefined4 *)(pointerPairCursor + 0x5294) = 0;
    *(undefined4 *)(pointerPairCursor + 0x52a8) = 0;
    pointerPairCursor = pointerPairCursor + 4;
    remaining4 = remaining4 + -1;
  } while (remaining4 != 0);
  loopIndex = 0;
  *(undefined4 *)(glContext + 0x744c) = 0;
  *(undefined4 *)(glContext + 0x48f4) = 0;
  *(undefined4 *)(glContext + 0x7448) = 0;
  if (*(char *)(glContext + 0x85a4) != '\0') {
    dstCursor = (undefined4 *)(glContext + 0x8880);
    do {
      *dstCursor = 0;
      loopIndex = loopIndex + 1;
      dstCursor = dstCursor + 0xb8;
    } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
    return;
  }
  return;
}

/* _gleAllocVertexMachine @ 0x4034 (228 bytes) */
int _gleAllocVertexMachine(glContext, param_2)
  int glContext;
  int param_2;
{
  undefined4 glContextWord24;
  undefined4 glContextWord20;
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
  *(int *)(glContext + 0x4864) = iVar3 + (param_2 + 0xc) * 0x100;
  *(int *)(glContext + 0x4874) = iVar5 + iVar8 * 4;
  *(int *)(glContext + 0x30b0) = iVar5 + iVar8 * 8;
  *(int *)(glContext + 0x4858) = iVar3;
  *(int *)(glContext + 0x485c) = iVar7;
  *(int *)(glContext + 0x4878) = param_2;
  *(int *)(glContext + 0x4854) = iVar3;
  *(int *)(glContext + 0x4860) = iVar7;
  *(int *)(glContext + 0x4870) = iVar5;
  glContextWord24 = *(undefined4 *)(glContext + 0x24);
  glContextWord20 = *(undefined4 *)(glContext + 0x20);
  if (uVar4 < uVar6) {
    uVar6 = (uVar6 - uVar4) + 0xff >> 8;
    do {
      *(undefined4 *)(uVar4 + 0x20) = glContextWord20;
      *(undefined4 *)(uVar4 + 0x24) = glContextWord20;
      *(undefined4 *)(uVar4 + 0x28) = glContextWord20;
      *(undefined4 *)(uVar4 + 0x2c) = glContextWord24;
      uVar4 = uVar4 + 0x100;
      uVar6 = uVar6 - 1;
    } while (uVar6 != 0);
  }
  return 0;
}

/* _gleAllocMaterials @ 0x4118 (60 bytes) */
int _gleAllocMaterials(glContext)
  int glContext;
{
  int remaining;
  int materialRecord;
  int *dstCursor;
  
  dstCursor = (int *)(glContext + 0x4dd0);
  materialRecord = glContext + 0x2c20;
  remaining = 1;
  do {
    remaining = remaining + -1;
    *dstCursor = materialRecord;
    *(undefined4 *)(materialRecord + 0x238) = 0;
    dstCursor = dstCursor + 1;
    *(undefined4 *)(materialRecord + 0x23c) = 0;
    *(undefined4 *)(materialRecord + 0x1e0) = 0;
    materialRecord = materialRecord + 0x240;
  } while (-1 < remaining);
  *(undefined4 *)(glContext + 0x4dd8) = 0;
  return 0;
}

/* _gleShareEnableHashTable @ 0x4154 (32 bytes) */
void _gleShareEnableHashTable(glContext)
  int glContext;
{
  *(undefined4 *)(glContext + 0x4850) = _gle_enable_hash_table;
  return;
}

/* _gleAllocVertexArrays @ 0x4174 (192 bytes) */
int _gleAllocVertexArrays(glContext)
  int glContext;
{
  int funcCache;
  undefined4 allocStatus;
  
  funcCache = ((int (*)())_gleInitFuncCache)();
  *(int *)(glContext + 0x49b4) = funcCache;
  allocStatus = 0x2720;
  if (funcCache != 0) {
    funcCache = ((int (*)())_gleInitFuncCache)();
    *(int *)(glContext + 0x49b8) = funcCache;
    allocStatus = 0x2720;
    if (funcCache != 0) {
      *(undefined4 *)(glContext + 0x497c) = 0x1f;
      *(undefined4 *)(glContext + 0x4980) = 3;
      *(undefined4 *)(glContext + 0x49c4) = 0;
      allocStatus = 0;
      *(undefined4 *)(glContext + 0x49b0) = 0xaeee;
      *(undefined2 *)(glContext + 0x49bc) = 0x14;
      *(undefined2 *)(glContext + 0x49c0) = 6;
      *(undefined2 *)(glContext + 0x49c2) = 1;
      *(undefined4 *)(glContext + 0x4984) = 0;
      *(undefined4 *)(glContext + 0x4988) = 0;
      *(undefined4 *)(glContext + 0x498c) = 0;
      *(undefined2 *)(glContext + 0x4990) = 0;
      *(undefined2 *)(glContext + 0x4992) = 0;
      *(undefined4 *)(glContext + 0x4994) = 0;
      *(undefined4 *)(glContext + 0x499c) = 0;
      *(undefined4 *)(glContext + 0x49a0) = 0;
      *(undefined4 *)(glContext + 0x49a4) = 0;
      *(undefined4 *)(glContext + 0x49a8) = 0;
      *(undefined4 *)(glContext + 0x49ac) = 0;
      *(undefined2 *)(glContext + 0x49be) = 1;
    }
  }
  return allocStatus;
}

/* _gleInitFuncCache @ 0x4234 (140 bytes) */
int _gleInitFuncCache()
{
  int funcCache;
  int returnedCache;
  
  funcCache = ((int (*)())_gleDCBAlloc)(0x24);
  returnedCache = 0;
  if (funcCache != 0) {
    *(undefined4 *)(funcCache + 0x1c) = 0xffffffff;
    *(undefined4 *)(funcCache + 0x20) = 0x4e800020;
    *(int *)(funcCache + 4) = funcCache;
    *(int *)funcCache = funcCache;
    *(undefined4 *)(funcCache + 8) = 0xffffffff;
    *(undefined4 *)(funcCache + 0xc) = 0xffffffff;
    *(undefined4 *)(funcCache + 0x10) = 0xffffffff;
    *(undefined4 *)(funcCache + 0x14) = 0xffffffff;
    *(undefined4 *)(funcCache + 0x18) = 0xffffffff;
    (*(code *)_glePushInstructions)(1,funcCache + 0x20);
    returnedCache = funcCache;
  }
  return returnedCache;
}

/* _gleAllocFunctions @ 0x42c0 (452 bytes) */
int _gleAllocFunctions(glContext)
  int glContext;
{
  undefined4 resultCode;
  int funcCacheStart;
  int funcCache;
  
  funcCache = ((int (*)())_gleInitFuncCache)();
  resultCode = 0x2720;
  *(int *)(glContext + 0x5088) = funcCache;
  if (funcCache != 0) {
    funcCache = ((int (*)())_gleInitFuncCache)();
    resultCode = 0x2720;
    *(int *)(glContext + 0x5094) = funcCache;
    if (funcCache != 0) {
      funcCache = ((int (*)())_gleInitFuncCache)();
      resultCode = 0x2720;
      *(int *)(glContext + 0x50a0) = funcCache;
      if (funcCache != 0) {
        funcCache = ((int (*)())_gleInitFuncCache)();
        resultCode = 0x2720;
        *(int *)(glContext + 0x49d0) = funcCache;
        if (funcCache != 0) {
          funcCache = ((int (*)())_gleInitFuncCache)();
          resultCode = 0x2720;
          *(int *)(glContext + 0x49d8) = funcCache;
          if (funcCache != 0) {
            funcCache = ((int (*)())_gleInitFuncCache)();
            resultCode = 0x2720;
            *(int *)(glContext + 0x48a0) = funcCache;
            if (funcCache != 0) {
              funcCache = ((int (*)())_gleInitFuncCache)();
              resultCode = 0x2720;
              *(int *)(glContext + 0x48a8) = funcCache;
              if (funcCache != 0) {
                funcCache = ((int (*)())_gleInitFuncCache)();
                resultCode = 0x2720;
                *(int *)(glContext + 0x48c0) = funcCache;
                if (funcCache != 0) {
                  funcCache = ((int (*)())_gleInitFuncCache)();
                  resultCode = 0x2720;
                  *(int *)(glContext + 0x48b0) = funcCache;
                  if (funcCache != 0) {
                    funcCache = ((int (*)())_gleInitFuncCache)();
                    resultCode = 0x2720;
                    *(int *)(glContext + 0x48b8) = funcCache;
                    if (funcCache != 0) {
                      *(undefined2 *)(glContext + 0x48bc) = 0x10;
                      *(undefined2 *)(glContext + 0x48be) = 1;
                      *(undefined2 *)(glContext + 0x508c) = 0x10;
                      *(undefined2 *)(glContext + 0x508e) = 1;
                      *(undefined2 *)(glContext + 0x5098) = 0x10;
                      *(undefined2 *)(glContext + 0x509a) = 1;
                      *(undefined2 *)(glContext + 0x50a4) = 0x10;
                      *(undefined2 *)(glContext + 0x50a6) = 1;
                      *(undefined2 *)(glContext + 0x49d4) = 0x10;
                      *(undefined2 *)(glContext + 0x49d6) = 1;
                      *(undefined2 *)(glContext + 0x49dc) = 0x10;
                      *(undefined2 *)(glContext + 0x49de) = 1;
                      *(undefined2 *)(glContext + 0x48a4) = 0x10;
                      *(undefined2 *)(glContext + 0x48a6) = 1;
                      *(undefined2 *)(glContext + 0x48ac) = 0x10;
                      *(undefined2 *)(glContext + 0x48ae) = 1;
                      *(undefined2 *)(glContext + 0x48b4) = 0x10;
                      *(undefined4 *)(glContext + 0x509c) = 0;
                      *(int *)(glContext + 0x5060) = *(int *)(glContext + 0x5088) + 0x20;
                      *(int *)(glContext + 0x5064) = *(int *)(glContext + 0x5094) + 0x20;
                      *(int *)(glContext + 0x5068) = *(int *)(glContext + 0x50a0) + 0x20;
                      *(int *)(glContext + 0x49c8) = *(int *)(glContext + 0x49d0) + 0x20;
                      *(int *)(glContext + 0x49cc) = *(int *)(glContext + 0x49d8) + 0x20;
                      *(int *)(glContext + 0x4888) = *(int *)(glContext + 0x48a0) + 0x20;
                      *(undefined4 *)(glContext + 0x5084) = 0;
                      *(undefined4 *)(glContext + 0x5090) = 0;
                      *(undefined2 *)(glContext + 0x48b6) = 1;
                      *(int *)(glContext + 0x488c) = funcCache + 0x20;
                      resultCode = 0;
                      funcCacheStart = *(int *)(glContext + 0x48b0) + 0x20;
                      *(int *)(glContext + 0x4890) = *(int *)(glContext + 0x48a8) + 0x20;
                      *(int *)(glContext + 0x489c) = funcCacheStart;
                      *(int *)(glContext + 0x4898) = funcCacheStart;
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
  return resultCode;
}

/* _gleInitConstants @ 0x4484 (192 bytes) */
void _gleInitConstants(glContext)
  int glContext;
{
  float float34ThenFloat38;
  undefined *flushAndSubmitFuncThenNoopFunc;
  undefined *rtcTocStructPtr;
  
  if ((*(uint *)PTR__gle_processor_0011204c & 0x10) != 0) {
    ((void (*)())_gleInitVectorConstants)(glContext);
  }
  flushAndSubmitFuncThenNoopFunc = PTR__gleFlushAndSubmit_00112050;
  *(undefined4 *)(glContext + 0x24) = 0x3f800000;
  *(undefined **)(glContext + 0x28) = flushAndSubmitFuncThenNoopFunc;
  float34ThenFloat38 = FLOAT_00108ebc;
  *(undefined4 *)(glContext + 0x20) = 0;
  *(float *)(glContext + 0x34) = float34ThenFloat38;
  rtcTocStructPtr = PTR__gle_rtc_toc_struct_0011205c;
  flushAndSubmitFuncThenNoopFunc = PTR__gleNoop_00110a20;
  float34ThenFloat38 = FLOAT_00108ec0;
  *(undefined4 *)(glContext + 0x30) = 0x3f000000;
  *(undefined4 *)(glContext + 0xec) = 0;
  *(undefined **)(glContext + 0x2c) = rtcTocStructPtr;
  *(float *)(glContext + 0x38) = float34ThenFloat38;
  *(undefined4 *)(glContext + 0x3c) = 0xbf800000;
  *(undefined **)(glContext + 0xdc) = flushAndSubmitFuncThenNoopFunc;
  *(undefined4 *)(glContext + 0xe8) = 0x43300000;
  *(undefined **)(glContext + 0xd8) = flushAndSubmitFuncThenNoopFunc;
  *(undefined4 *)(glContext + 0xe0) = 0x43300000;
  *(undefined4 *)(glContext + 0xe4) = 0;
  return;
}

/* _gleInitVectorConstants @ 0x4544 (56 bytes) */
void _gleInitVectorConstants(glContext)
  int glContext;
{
  undefined4 *vectorConstants;
  
  vectorConstants = (undefined4 *)(glContext + 0x10U & 0xfffffff0);
  *vectorConstants = 0x1a;
  vectorConstants[1] = 0x1c;
  vectorConstants[2] = 0x1e;
  vectorConstants[3] = 0;
  return;
}

/* _gleInitGLDState @ 0x457c (3076 bytes) */
void _gleInitGLDState(glContext)
  int glContext;
{
  int remaining11;
  int loopIndex2;
  int remaining10;
  int loopIndex;
  int remaining8;
  int remaining7;
  int remaining6;
  int remaining5;
  int remaining4;
  int remaining3;
  int remaining2;
  int remaining;
  float defaultAmbientLevel;
  float defaultDiffuseLevel;
  undefined2 componentUsage;
  undefined2 *variableCursor;
  undefined1 *dstCursor;
  int portionRecord;
  undefined4 *dstCursor2;
  int matrixArrayCursorB;
  int initRecordCursor;
  int materialCursor;
  int lightCursor;
  int clipPlaneCursor;
  int matrixArrayCursorA;
  int texGenUnitCursor;
  int texEnvUnitCursor;
  int stencilFaceCursor;
  int portionVariablesBase;
  int remaining9;
  
  *(undefined1 *)(glContext + 0x2d66) = 0;
  *(undefined2 *)(glContext + 0x2d64) = 0x207;
  *(undefined2 *)(glContext + 0x2d82) = 0x8006;
  *(undefined2 *)(glContext + 0x2dc4) = 0x201;
  *(undefined4 *)(glContext + 0x2d88) = 0x3ff00000;
  *(undefined4 *)(glContext + 0x2d8c) = 0;
  *(undefined2 *)(glContext + 0x2d68) = 1;
  *(undefined2 *)(glContext + 0x2d6c) = 1;
  *(undefined2 *)(glContext + 0x2d80) = 0x8006;
  *(undefined4 *)(glContext + 0x2d60) = 0;
  *(undefined2 *)(glContext + 0x2d6a) = 0;
  *(undefined2 *)(glContext + 0x2d6e) = 0;
  *(undefined4 *)(glContext + 0x2d70) = 0;
  *(undefined4 *)(glContext + 0x2d74) = 0;
  *(undefined4 *)(glContext + 0x2d78) = 0;
  *(undefined4 *)(glContext + 0x2d7c) = 0;
  *(undefined1 *)(glContext + 0x2d84) = 0;
  *(undefined4 *)(glContext + 0x2d90) = 0;
  *(undefined4 *)(glContext + 0x2d94) = 0;
  *(undefined4 *)(glContext + 0x2d98) = 0;
  *(undefined4 *)(glContext + 0x2d9c) = 0;
  *(undefined4 *)(glContext + 0x2da0) = 0;
  *(undefined4 *)(glContext + 0x2da4) = 0;
  *(undefined4 *)(glContext + 0x2da8) = 0;
  *(undefined2 *)(glContext + 0x2e04) = 0x800;
  *(undefined2 *)(glContext + 0x2e06) = 0x8452;
  *(undefined2 *)(glContext + 0x2e08) = 0x855c;
  *(undefined1 *)(glContext + 0x2ddc) = 1;
  *(undefined2 *)(glContext + 0x2e1c) = 0x1100;
  *(undefined2 *)(glContext + 0x2e28) = 0xffff;
  *(undefined2 *)(glContext + 0x2e30) = 0x1503;
  *(undefined4 *)(glContext + 0x2e3c) = 0xffffffff;
  *(undefined2 *)(glContext + 0x2e0c) = 0x1100;
  *(undefined2 *)(glContext + 0x2e0e) = 0x1100;
  *(undefined2 *)(glContext + 0x2e10) = 0x1100;
  *(undefined2 *)(glContext + 0x2e12) = 0x1100;
  *(undefined2 *)(glContext + 0x2e14) = 0x1100;
  *(undefined2 *)(glContext + 0x2e16) = 0x1100;
  *(undefined2 *)(glContext + 0x2e18) = 0x1100;
  *(undefined2 *)(glContext + 0x2e1a) = 0x1100;
  *(undefined4 *)(glContext + 0x2dac) = 0;
  *(undefined4 *)(glContext + 0x2db0) = 0;
  *(undefined4 *)(glContext + 0x2db4) = 0;
  *(undefined1 *)(glContext + 0x2dc8) = 0;
  *(undefined1 *)(glContext + 0x2dc9) = 0;
  *(undefined4 *)(glContext + 0x2de0) = 0;
  *(undefined4 *)(glContext + 0x2de4) = 0;
  *(undefined4 *)(glContext + 0x2de8) = 0;
  *(undefined4 *)(glContext + 0x2dec) = 0;
  *(undefined4 *)(glContext + 0x2df0) = 0x3f800000;
  *(undefined4 *)(glContext + 0x2df4) = 0;
  *(undefined4 *)(glContext + 0x2df8) = 0x3f800000;
  *(undefined4 *)(glContext + 0x2dfc) = 0x3f800000;
  *(undefined4 *)(glContext + 0x2e00) = 0;
  *(undefined1 *)(glContext + 0x2e0a) = 0;
  *(undefined1 *)(glContext + 0x2e0b) = 0;
  *(undefined4 *)(glContext + 0x2e20) = 0x3f800000;
  *(undefined4 *)(glContext + 0x2e24) = 1;
  *(undefined4 *)(glContext + 0x2e34) = 0xffffffff;
  *(undefined4 *)(glContext + 0x2e38) = 0xffffffff;
  *(undefined1 *)(glContext + 0x2e40) = 1;
  *(undefined1 *)(glContext + 0x2e41) = 1;
  *(undefined1 *)(glContext + 0x2e42) = 1;
  *(undefined1 *)(glContext + 0x2e43) = 1;
  *(undefined1 *)(glContext + 0x2e44) = 1;
  *(undefined4 *)(glContext + 0x2e80) = 4;
  *(undefined4 *)(glContext + 0x2e64) = 4;
  *(undefined1 *)(glContext + 0x2e2c) = 0;
  *(undefined1 *)(glContext + 0x2e2d) = 0;
  *(undefined1 *)(glContext + 0x2e33) = 0;
  *(undefined1 *)(glContext + 0x2e32) = 0;
  *(undefined4 *)(glContext + 0x2e48) = 0x3f800000;
  *(undefined4 *)(glContext + 0x2e4c) = 0x3f800000;
  *(undefined4 *)(glContext + 0x2e50) = 0;
  *(undefined4 *)(glContext + 0x2e54) = 0;
  *(undefined4 *)(glContext + 0x2e58) = 0;
  *(undefined4 *)(glContext + 0x2e5c) = 0;
  *(undefined4 *)(glContext + 0x2e60) = 0;
  *(undefined1 *)(glContext + 0x2e68) = 0;
  *(undefined1 *)(glContext + 0x2e69) = 0;
  *(undefined1 *)(glContext + 0x2e6a) = 0;
  *(undefined4 *)(glContext + 0x2e6c) = 0;
  *(undefined4 *)(glContext + 0x2e70) = 0;
  *(undefined4 *)(glContext + 0x2e74) = 0;
  *(undefined4 *)(glContext + 0x2e78) = 0;
  *(undefined4 *)(glContext + 0x2e7c) = 0;
  *(undefined1 *)(glContext + 0x2e84) = 0;
  *(undefined1 *)(glContext + 0x2e85) = 0;
  *(undefined1 *)(glContext + 0x2e86) = 0;
  *(undefined4 *)(glContext + 0x2eb4) = 0;
  *(undefined4 *)(glContext + 0x2eb0) = 0;
  *(undefined4 *)(glContext + 0x2e8c) = 0x3f800000;
  *(undefined4 *)(glContext + 0x2e94) = 0x3f800000;
  *(undefined4 *)(glContext + 0x2e9c) = 0x3f800000;
  *(undefined4 *)(glContext + 0x2ea4) = 0x3f800000;
  *(undefined4 *)(glContext + 0x2eac) = 0x3f800000;
  *(undefined4 *)(glContext + 0x2e88) = 0;
  *(undefined4 *)(glContext + 0x2e90) = 0;
  *(undefined4 *)(glContext + 0x2e98) = 0;
  *(undefined4 *)(glContext + 0x2ea0) = 0;
  *(undefined4 *)(glContext + 0x2ea8) = 0;
  *(undefined4 *)(glContext + 0x30b4) = 0;
  *(undefined **)(glContext + 0x2ee8) = &_gle_default_pix_map_i;
  *(undefined **)(glContext + 0x2f08) = &_gle_default_pix_map_f;
  *(undefined4 *)(glContext + 0x2f34) = 1;
  *(undefined4 *)(glContext + 0x2f10) = 1;
  *(undefined4 *)(glContext + 0x2f14) = 1;
  *(undefined **)(glContext + 0x2eec) = &_gle_default_pix_map_f;
  *(undefined4 *)(glContext + 0x2f18) = 1;
  *(undefined **)(glContext + 0x2ef0) = &_gle_default_pix_map_f;
  *(undefined4 *)(glContext + 0x2f1c) = 1;
  *(undefined **)(glContext + 0x2ef4) = &_gle_default_pix_map_f;
  *(undefined4 *)(glContext + 0x2f20) = 1;
  *(undefined **)(glContext + 0x2ef8) = &_gle_default_pix_map_f;
  *(undefined4 *)(glContext + 0x2f24) = 1;
  *(undefined **)(glContext + 0x2efc) = &_gle_default_pix_map_f;
  *(undefined4 *)(glContext + 0x2f28) = 1;
  *(undefined **)(glContext + 0x2f0c) = &_gle_default_pix_map_i;
  *(undefined **)(glContext + 0x2f00) = &_gle_default_pix_map_f;
  *(undefined4 *)(glContext + 0x2f2c) = 1;
  *(undefined **)(glContext + 0x2f04) = &_gle_default_pix_map_f;
  *(undefined4 *)(glContext + 0x2f30) = 1;
  *(undefined4 *)(glContext + 0x2f48) = 0x3f800000;
  *(undefined4 *)(glContext + 0x2f4c) = 0;
  *(undefined4 *)(glContext + 0x2f50) = 0x3f800000;
  *(undefined4 *)(glContext + 0x2f54) = 0;
  *(undefined4 *)(glContext + 0x2f58) = 0x3f800000;
  *(undefined4 *)(glContext + 0x2f5c) = 0;
  *(undefined4 *)(glContext + 0x2f60) = 0x3f800000;
  *(undefined4 *)(glContext + 0x2f64) = 0;
  *(undefined4 *)(glContext + 0x2f88) = 0x3f800000;
  *(undefined4 *)(glContext + 0x2f94) = 0;
  *(undefined4 *)(glContext + 0x2f98) = 0x3f800000;
  *(undefined4 *)(glContext + 0x2f9c) = 0;
  *(undefined4 *)(glContext + 0x2fa0) = 0x3f800000;
  *(undefined4 *)(glContext + 0x2fa4) = 0;
  *(undefined4 *)(glContext + 0x2fc8) = 0x3f800000;
  *(undefined4 *)(glContext + 0x2fd4) = 0;
  *(undefined4 *)(glContext + 0x2fd8) = 0x3f800000;
  *(undefined4 *)(glContext + 0x2f8c) = 0;
  *(undefined4 *)(glContext + 0x2f90) = 0x3f800000;
  *(undefined4 *)(glContext + 0x2fcc) = 0;
  *(undefined4 *)(glContext + 0x2fd0) = 0x3f800000;
  *(undefined4 *)(glContext + 0x2fdc) = 0;
  *(undefined4 *)(glContext + 0x2fe0) = 0x3f800000;
  *(undefined4 *)(glContext + 0x2fe4) = 0;
  *(undefined4 *)(glContext + 0x3030) = 0x3f800000;
  *(undefined4 *)(glContext + 0x303c) = 0;
  *(undefined4 *)(glContext + 0x3040) = 0x3f800000;
  *(undefined4 *)(glContext + 0x3044) = 0;
  *(undefined4 *)(glContext + 0x3048) = 0x3f800000;
  *(undefined4 *)(glContext + 0x304c) = 0;
  *(undefined4 *)(glContext + 0x2ffc) = 0x3f800000;
  *(undefined4 *)(glContext + 0x3090) = 0x3f800000;
  *(undefined4 *)(glContext + 0x309c) = 0;
  *(undefined4 *)(glContext + 0x30a0) = 0x3f800000;
  *(undefined4 *)(glContext + 0x30a4) = 0;
  *(undefined4 *)(glContext + 0x30a8) = 0x3f800000;
  *(undefined4 *)(glContext + 0x30ac) = 0;
  *(undefined4 *)(glContext + 0x3008) = 0;
  *(undefined4 *)(glContext + 0x300c) = 0x3f800000;
  *(undefined4 *)(glContext + 0x3010) = 0;
  *(undefined4 *)(glContext + 0x3014) = 0x3f800000;
  *(undefined4 *)(glContext + 0x3018) = 0;
  *(undefined4 *)(glContext + 0x3050) = 0x3f800000;
  *(undefined4 *)(glContext + 0x305c) = 0;
  *(undefined4 *)(glContext + 0x3060) = 0x3f800000;
  *(undefined4 *)(glContext + 0x3064) = 0;
  *(undefined4 *)(glContext + 0x3068) = 0x3f800000;
  *(undefined4 *)(glContext + 0x3034) = 0;
  *(undefined4 *)(glContext + 0x3038) = 0x3f800000;
  *(undefined4 *)(glContext + 0x3094) = 0;
  *(undefined4 *)(glContext + 0x3098) = 0x3f800000;
  *(undefined4 *)(glContext + 0x3000) = 0;
  *(undefined4 *)(glContext + 0x3004) = 0x3f800000;
  *(undefined4 *)(glContext + 0x3054) = 0;
  *(undefined4 *)(glContext + 0x3058) = 0x3f800000;
  *(undefined4 *)(glContext + 0x306c) = 0;
  *(undefined4 *)(glContext + 0x3070) = 0x3f800000;
  *(undefined4 *)(glContext + 0x307c) = 0;
  *(undefined4 *)(glContext + 0x3074) = 0;
  *(undefined4 *)(glContext + 0x3078) = 0x3f800000;
  *(undefined4 *)(glContext + 0x3080) = 0x3f800000;
  *(undefined4 *)(glContext + 0x3084) = 0;
  *(undefined4 *)(glContext + 0x3088) = 0x3f800000;
  *(undefined4 *)(glContext + 0x308c) = 0;
  *(undefined4 *)(glContext + 0x30b0) = 0;
  *(undefined2 *)(glContext + 0x2f68) = 0x8016;
  *(undefined2 *)(glContext + 0x2fa8) = 0x8016;
  *(undefined4 *)(glContext + 0x2fb8) = 0;
  *(undefined4 *)(glContext + 0x2fbc) = 0;
  *(undefined4 *)(glContext + 0x2fc0) = 0;
  *(undefined4 *)(glContext + 0x2fc4) = 0;
  *(undefined4 *)(glContext + 0x2f38) = 0;
  *(undefined4 *)(glContext + 0x2f3c) = 0;
  *(undefined4 *)(glContext + 0x2f40) = 0;
  *(undefined4 *)(glContext + 0x2f44) = 0;
  *(undefined4 *)(glContext + 0x2f78) = 0;
  *(undefined4 *)(glContext + 0x2f7c) = 0;
  *(undefined4 *)(glContext + 0x2f80) = 0;
  *(undefined4 *)(glContext + 0x2f84) = 0;
  dstCursor2 = (undefined4 *)(glContext + 0x30e8);
  *(undefined2 *)(glContext + 0x2fe8) = 0x8016;
  *(undefined2 *)(glContext + 0x2f6a) = 0x1908;
  *(undefined2 *)(glContext + 0x2faa) = 0x1908;
  *(int *)(glContext + 0x2ff8) = glContext + 0x18e0;
  *(undefined2 *)(glContext + 0x2fea) = 0x1908;
  remaining10 = 0x20;
  *(undefined4 *)(glContext + 0x2f6c) = 0;
  *(undefined4 *)(glContext + 0x2fac) = 0;
  *(undefined4 *)(glContext + 0x2fec) = 0;
  *(undefined4 *)(glContext + 0x2f70) = 0;
  *(undefined4 *)(glContext + 0x2fb0) = 0;
  *(undefined4 *)(glContext + 0x2ff0) = 0;
  *(undefined4 *)(glContext + 0x2f74) = 0;
  *(undefined4 *)(glContext + 0x2fb4) = 0;
  *(undefined4 *)(glContext + 0x2ff4) = 0;
  *(undefined4 *)(glContext + 0x3024) = 0;
  *(undefined4 *)(glContext + 0x3028) = 0;
  *(undefined2 *)(glContext + 0x302c) = 0x1908;
  *(undefined1 *)(glContext + 0x302e) = 0;
  *(undefined4 *)(glContext + 0x2ebc) = 0x3f800000;
  *(undefined4 *)(glContext + 0x2ec4) = 0x3f800000;
  *(undefined4 *)(glContext + 0x2ecc) = 0x3f800000;
  *(undefined4 *)(glContext + 0x2ed4) = 0x3f800000;
  *(undefined4 *)(glContext + 0x2edc) = 0x3f800000;
  *(undefined4 *)(glContext + 0x2ee4) = 0x3f800000;
  *(undefined4 *)(glContext + 0x2eb8) = 0;
  *(undefined4 *)(glContext + 0x2ec0) = 0;
  *(undefined4 *)(glContext + 0x2ec8) = 0;
  *(undefined4 *)(glContext + 0x2ed0) = 0;
  *(undefined4 *)(glContext + 0x2ed8) = 0;
  *(undefined4 *)(glContext + 12000) = 0;
  *(undefined4 *)(glContext + 0x30b8) = 0;
  **(undefined4 **)(glContext + 0x301c) = 0x3f800000;
  *(undefined4 *)(*(int *)(glContext + 0x301c) + 4) = 0x3f800000;
  *(undefined4 *)(*(int *)(glContext + 0x301c) + 8) = 0x3f800000;
  *(undefined4 *)(*(int *)(glContext + 0x301c) + 0xc) = 0x3f800000;
  *(undefined4 *)(*(int *)(glContext + 0x301c) + 0x10) = 0;
  *(undefined4 *)(*(int *)(glContext + 0x301c) + 0x14) = 0;
  *(undefined4 *)(*(int *)(glContext + 0x301c) + 0x18) = 0;
  *(undefined4 *)(*(int *)(glContext + 0x301c) + 0x1c) = 0;
  *(undefined1 *)(glContext + 0x3022) = 0;
  *(undefined2 *)(glContext + 0x3020) = 0x1908;
  *(undefined1 *)(glContext + 0x30dd) = 0;
  *(undefined2 *)(glContext + 0x30e0) = 0;
  *(undefined2 *)(glContext + 0x30e2) = 0x60b4;
  *(undefined1 *)(glContext + 0x30dc) = 0;
  *(undefined4 *)(glContext + 0x30bc) = 0x3f800000;
  *(undefined4 *)(glContext + 0x30c0) = 0;
  *(undefined4 *)(glContext + 0x30c4) = 0x3f800000;
  *(undefined4 *)(glContext + 0x30c8) = 0x3f800000;
  *(undefined4 *)(glContext + 0x30cc) = 0x3f800000;
  *(undefined4 *)(glContext + 0x30d0) = 0;
  *(undefined4 *)(glContext + 0x30d4) = 0;
  *(undefined4 *)(glContext + 0x30d8) = 0x3f800000;
  *(undefined4 *)(glContext + 0x30e4) = 0;
  do {
    *dstCursor2 = 0xffffffff;
    dstCursor2 = dstCursor2 + 1;
    remaining10 = remaining10 + -1;
  } while (remaining10 != 0);
  *(undefined2 *)(glContext + 0x3174) = 0x901;
  *(undefined2 *)(glContext + 0x3172) = 0x1b02;
  *(undefined2 *)(glContext + 0x3176) = 0x405;
  *(undefined1 *)(glContext + 0x317e) = 0;
  *(undefined4 *)(glContext + 0x3194) = 0x1d01;
  *(undefined2 *)(0x3170 + glContext) = 0x1b02;
  *(undefined1 *)(glContext + 0x3178) = 0;
  *(undefined1 *)(glContext + 0x3179) = 0;
  *(undefined1 *)(glContext + 0x317a) = 0;
  *(undefined1 *)(glContext + 0x317b) = 0;
  *(undefined1 *)(glContext + 0x317c) = 0;
  *(undefined1 *)(glContext + 0x317d) = 0;
  *(undefined1 *)(glContext + 0x3190) = 0;
  *(undefined4 *)(glContext + 0x3168) = 0;
  *(undefined4 *)(glContext + 0x316c) = 0;
  *(undefined4 *)(glContext + 0x3180) = 0;
  *(undefined4 *)(glContext + 0x3184) = 0;
  *(undefined4 *)(glContext + 0x3188) = 0;
  *(undefined4 *)(glContext + 0x318c) = 0;
  stencilFaceCursor = glContext;
  do {
    *(undefined2 *)(stencilFaceCursor + 0x31a0) = 0x207;
    *(undefined4 *)(stencilFaceCursor + 0x3198) = 0xffffffff;
    *(undefined4 *)(stencilFaceCursor + 0x319c) = 0;
    *(undefined2 *)(stencilFaceCursor + 0x31a2) = 0x1e00;
    *(undefined2 *)(stencilFaceCursor + 0x31a4) = 0x1e00;
    *(undefined2 *)(stencilFaceCursor + 0x31a6) = 0x1e00;
    stencilFaceCursor = stencilFaceCursor + 0x10;
  } while (stencilFaceCursor <= glContext + 0x10);
  remaining = 0x10;
  *(undefined2 *)(0x31b4 + glContext + 4) = 0x207;
  *(undefined2 *)(glContext + 0x31be) = 0x1e00;
  *(undefined1 *)(glContext + 0x3e90) = 1;
  ((unsigned char *)0x3e94)[glContext] = 0x0;
  *(undefined2 *)(glContext + 0x31ba) = 0x1e00;
  *(undefined2 *)(glContext + 0x31bc) = 0x1e00;
  *(undefined4 *)(glContext + 0x31c0) = 0;
  *(undefined1 *)(glContext + 0x3e91) = 0;
  *(undefined1 *)(glContext + 0x3e92) = 0;
  *(undefined1 *)(glContext + 0x3e93) = 0;
  *(undefined4 *)(glContext + 0x3e8c) = 0x3f800000;
  texEnvUnitCursor = glContext;
  do {
    *(undefined2 *)(texEnvUnitCursor + 0x31dc) = 0x2100;
    *(undefined2 *)(texEnvUnitCursor + 0x31de) = 0x2100;
    *(undefined2 *)(texEnvUnitCursor + 0x31e0) = 0x1702;
    *(undefined2 *)(texEnvUnitCursor + 0x31e2) = 0x8578;
    *(undefined2 *)(texEnvUnitCursor + 0x31e4) = 0x8576;
    *(undefined2 *)(texEnvUnitCursor + 0x31e6) = 0x1702;
    *(undefined2 *)(texEnvUnitCursor + 0x31e8) = 0x8578;
    *(undefined2 *)(texEnvUnitCursor + 0x31ea) = 0x8576;
    *(undefined2 *)(texEnvUnitCursor + 0x31ec) = 0x300;
    *(undefined2 *)(texEnvUnitCursor + 0x31ee) = 0x300;
    *(undefined2 *)(texEnvUnitCursor + 0x31f0) = 0x302;
    *(undefined2 *)(texEnvUnitCursor + 0x31f2) = 0x302;
    *(undefined2 *)(texEnvUnitCursor + 0x31f4) = 0x302;
    *(undefined2 *)(texEnvUnitCursor + 0x31f6) = 0x302;
    *(undefined4 *)(texEnvUnitCursor + 0x31f8) = 0x3f800000;
    *(undefined4 *)(texEnvUnitCursor + 0x31fc) = 0x3f800000;
    *(undefined4 *)(texEnvUnitCursor + 0x3200) = 0;
    *(undefined2 *)(texEnvUnitCursor + 0x3204) = 0;
    *(undefined2 *)(texEnvUnitCursor + 0x320a) = 0x84c0;
    *(undefined4 *)(texEnvUnitCursor + 0x321c) = 0;
    *(undefined4 *)(texEnvUnitCursor + 0x3220) = 0;
    *(undefined4 *)(texEnvUnitCursor + 0x3224) = 0xbf800000;
    *(undefined4 *)(texEnvUnitCursor + 0x3228) = 0x3f800000;
    *(undefined4 *)(texEnvUnitCursor + 0x322c) = 0;
    *(undefined4 *)(texEnvUnitCursor + 0x3230) = 0;
    *(undefined4 *)(texEnvUnitCursor + 0x3234) = 0x3f800000;
    *(undefined4 *)(texEnvUnitCursor + 0x3238) = 0x3f800000;
    *(undefined4 *)(texEnvUnitCursor + 0x323c) = 0;
    *(undefined2 *)(texEnvUnitCursor + 0x3210) = 0x202;
    *(undefined2 *)(texEnvUnitCursor + 0x3212) = 0x202;
    *(undefined2 *)(texEnvUnitCursor + 0x3214) = 0x202;
    *(undefined2 *)(texEnvUnitCursor + 0x3216) = 0x202;
    *(undefined2 *)(texEnvUnitCursor + 0x320c) = 0x8536;
    *(undefined2 *)(texEnvUnitCursor + 0x31d8) = 0x2100;
    *(undefined4 *)(texEnvUnitCursor + 0x31c4) = 0;
    *(undefined4 *)(texEnvUnitCursor + 0x31c8) = 0;
    *(undefined4 *)(texEnvUnitCursor + 0x31cc) = 0;
    *(undefined4 *)(texEnvUnitCursor + 0x31d0) = 0;
    *(undefined4 *)(texEnvUnitCursor + 0x31d4) = 0;
    texEnvUnitCursor = texEnvUnitCursor + 0x7c;
    remaining = remaining + -1;
  } while (remaining != 0);
  remaining2 = 8;
  texGenUnitCursor = glContext;
  do {
    *(undefined2 *)(texGenUnitCursor + 0x3988) = 0x2400;
    *(undefined4 *)(texGenUnitCursor + 0x398c) = 0x3f800000;
    *(undefined4 *)(texGenUnitCursor + 0x3990) = 0;
    *(undefined4 *)(texGenUnitCursor + 0x3994) = 0;
    *(undefined4 *)(texGenUnitCursor + 0x3998) = 0;
    *(undefined4 *)(texGenUnitCursor + 0x399c) = 0x3f800000;
    *(undefined4 *)(texGenUnitCursor + 0x39a0) = 0;
    *(undefined4 *)(texGenUnitCursor + 0x39a4) = 0;
    *(undefined4 *)(texGenUnitCursor + 0x39a8) = 0;
    *(undefined1 *)(texGenUnitCursor + 0x3a18) = 0;
    *(undefined2 *)(texGenUnitCursor + 0x39ac) = 0x2400;
    *(undefined4 *)(texGenUnitCursor + 0x39b0) = 0;
    *(undefined4 *)(texGenUnitCursor + 0x39b4) = 0x3f800000;
    *(undefined4 *)(texGenUnitCursor + 0x39b8) = 0;
    *(undefined4 *)(texGenUnitCursor + 0x39bc) = 0;
    *(undefined4 *)(texGenUnitCursor + 0x39c0) = 0;
    *(undefined4 *)(texGenUnitCursor + 0x39c4) = 0x3f800000;
    *(undefined4 *)(texGenUnitCursor + 0x39c8) = 0;
    *(undefined4 *)(texGenUnitCursor + 0x39cc) = 0;
    *(undefined1 *)(texGenUnitCursor + 0x3a19) = 0;
    *(undefined2 *)(texGenUnitCursor + 0x39d0) = 0x2400;
    *(undefined4 *)(texGenUnitCursor + 0x39d4) = 0;
    *(undefined4 *)(texGenUnitCursor + 0x39d8) = 0;
    *(undefined4 *)(texGenUnitCursor + 0x39dc) = 0;
    *(undefined4 *)(texGenUnitCursor + 0x39e0) = 0;
    *(undefined4 *)(texGenUnitCursor + 0x39e4) = 0;
    *(undefined4 *)(texGenUnitCursor + 0x39e8) = 0;
    *(undefined4 *)(texGenUnitCursor + 0x39ec) = 0;
    *(undefined4 *)(texGenUnitCursor + 0x39f0) = 0;
    *(undefined1 *)(texGenUnitCursor + 0x3a1a) = 0;
    *(undefined2 *)(texGenUnitCursor + 0x39f4) = 0x2400;
    *(undefined4 *)(texGenUnitCursor + 0x39f8) = 0;
    *(undefined4 *)(texGenUnitCursor + 0x39fc) = 0;
    *(undefined4 *)(texGenUnitCursor + 0x3a00) = 0;
    *(undefined4 *)(texGenUnitCursor + 0x3a04) = 0;
    *(undefined4 *)(texGenUnitCursor + 0x3a08) = 0;
    *(undefined4 *)(texGenUnitCursor + 0x3a0c) = 0;
    *(undefined4 *)(texGenUnitCursor + 0x3a10) = 0;
    *(undefined4 *)(texGenUnitCursor + 0x3a14) = 0;
    *(undefined1 *)(texGenUnitCursor + 0x3a1b) = 0;
    texGenUnitCursor = texGenUnitCursor + 0x94;
    remaining2 = remaining2 + -1;
  } while (remaining2 != 0);
  *(undefined2 *)(glContext + 0x24a8) = 0x6096;
  *(undefined1 *)(glContext + 0x24ac) = 0;
  *(undefined2 *)(glContext + 0x24aa) = 0x6098;
  *(undefined4 *)(glContext + 0x24a0) = 1;
  remaining3 = 0x17;
  *(undefined1 *)(glContext + 0x24ad) = 0;
  *(undefined1 *)(glContext + 0x24ae) = 0;
  *(undefined4 *)(glContext + 0x24a4) = 0x3f800000;
  ((int (*)())_gleMakeIdentityMatrix)(glContext + 0x2460);
  matrixArrayCursorB = glContext + 0x1e60;
  matrixArrayCursorA = glContext + 0x1860;
  do {
    ((int (*)())_gleMakeIdentityMatrix)(matrixArrayCursorA);
    ((int (*)())_gleMakeIdentityMatrix)(matrixArrayCursorB);
    remaining3 = remaining3 + -1;
    matrixArrayCursorB = matrixArrayCursorB + 0x40;
    matrixArrayCursorA = matrixArrayCursorA + 0x40;
  } while (-1 < remaining3);
  *(undefined4 *)(glContext + 0x3e28) = 0;
  remaining4 = 6;
  clipPlaneCursor = glContext;
  do {
    *(undefined4 *)(clipPlaneCursor + 0x3e2c) = 0;
    *(undefined4 *)(clipPlaneCursor + 0x3e30) = 0;
    *(undefined4 *)(clipPlaneCursor + 0x3e34) = 0;
    *(undefined4 *)(clipPlaneCursor + 0x3e38) = 0;
    defaultAmbientLevel = FLOAT_00108f80;
    clipPlaneCursor = clipPlaneCursor + 0x10;
    remaining4 = remaining4 + -1;
  } while (remaining4 != 0);
  *(undefined2 *)(glContext + 0x2d44) = 0x408;
  *(undefined1 *)(glContext + 0x2d4e) = 0;
  *(undefined2 *)(glContext + 0x2d46) = 0x1602;
  remaining5 = 8;
  *(undefined2 *)(glContext + 0x2d48) = 0x81f9;
  *(undefined4 *)(glContext + 0x2d40) = 0;
  *(undefined1 *)(glContext + 0x2d4a) = 0;
  *(undefined1 *)(glContext + 0x2d4d) = 0;
  *(undefined1 *)(glContext + 0x2d4c) = 0;
  *(undefined1 *)(glContext + 0x2d4b) = 0;
  *(float *)(glContext + 0x24b8) = defaultAmbientLevel;
  *(float *)(glContext + 0x24b0) = defaultAmbientLevel;
  *(float *)(glContext + 0x24b4) = defaultAmbientLevel;
  *(undefined4 *)(glContext + 0x24bc) = 0x3f800000;
  lightCursor = glContext;
  do {
    *(undefined4 *)(lightCursor + 0x24c0) = 0;
    *(undefined4 *)(lightCursor + 0x24c4) = 0;
    *(undefined4 *)(lightCursor + 0x24c8) = 0;
    *(undefined4 *)(lightCursor + 0x24cc) = 0x3f800000;
    if (lightCursor == glContext) {
      *(undefined4 *)(glContext + 0x24d0) = 0x3f800000;
      *(undefined4 *)(glContext + 0x24d4) = 0x3f800000;
      *(undefined4 *)(glContext + 0x24d8) = 0x3f800000;
      *(undefined4 *)(glContext + 0x24dc) = 0x3f800000;
      *(undefined4 *)(glContext + 0x24e0) = 0x3f800000;
      *(undefined4 *)(glContext + 0x24e4) = 0x3f800000;
      *(undefined4 *)(glContext + 0x24e8) = 0x3f800000;
      *(undefined4 *)(glContext + 0x24ec) = 0x3f800000;
    }
    else {
      *(undefined4 *)(lightCursor + 0x24d0) = 0;
      *(undefined4 *)(lightCursor + 0x24d4) = 0;
      *(undefined4 *)(lightCursor + 0x24d8) = 0;
      *(undefined4 *)(lightCursor + 0x24dc) = 0x3f800000;
      *(undefined4 *)(lightCursor + 0x24e0) = 0;
      *(undefined4 *)(lightCursor + 0x24e4) = 0;
      *(undefined4 *)(lightCursor + 0x24e8) = 0;
      *(undefined4 *)(lightCursor + 0x24ec) = 0x3f800000;
    }
    *(undefined4 *)(lightCursor + 0x24f0) = 0;
    *(undefined4 *)(lightCursor + 0x24f4) = 0;
    *(undefined4 *)(lightCursor + 0x24f8) = 0x3f800000;
    *(undefined4 *)(lightCursor + 0x24fc) = 0;
    *(undefined4 *)(lightCursor + 0x2500) = 0;
    *(undefined4 *)(lightCursor + 0x2504) = 0;
    *(undefined4 *)(lightCursor + 0x2508) = 0xbf800000;
    *(undefined4 *)(lightCursor + 0x250c) = 0xbf800000;
    *(undefined4 *)(lightCursor + 0x2510) = 0x3f800000;
    *(undefined4 *)(lightCursor + 0x2514) = 0;
    *(undefined4 *)(lightCursor + 0x2518) = 0;
    *(undefined4 *)(lightCursor + 0x251c) = 0;
    *(undefined4 *)(lightCursor + 0x2520) = 0;
    *(undefined4 *)(lightCursor + 0x2524) = 0;
    *(undefined4 *)(lightCursor + 0x2528) = 0x3f800000;
    *(undefined4 *)(lightCursor + 0x252c) = 0x3f800000;
    *(undefined4 *)(lightCursor + 0x2530) = 0x43340000;
    defaultDiffuseLevel = FLOAT_00108f84;
    defaultAmbientLevel = FLOAT_00108f80;
    lightCursor = lightCursor + 0x80;
    remaining5 = remaining5 + -1;
  } while (remaining5 != 0);
  *(undefined4 *)(glContext + 0x184c) = 0;
  *(undefined4 *)(glContext + 0x1830) = 0;
  *(undefined4 *)(glContext + 0x1834) = 0;
  *(undefined4 *)(glContext + 0x1840) = 0;
  *(undefined4 *)(glContext + 0x1844) = 0;
  *(undefined4 *)(glContext + 0x1848) = 0;
  *(undefined4 *)(glContext + 0x1828) = 0x3f000000;
  *(undefined4 *)(glContext + 0x1838) = 0x3ff00000;
  *(undefined4 *)(glContext + 0x183c) = 0;
  *(undefined4 *)(glContext + 0x1810) = 0x3f800000;
  *(undefined4 *)(glContext + 0x1814) = 0x3f800000;
  *(undefined4 *)(glContext + 0x1818) = 0x3f000000;
  *(undefined4 *)(glContext + 0x181c) = 0x3f800000;
  *(undefined4 *)(glContext + 0x1820) = 0;
  *(undefined4 *)(glContext + 0x1824) = 0;
  *(undefined4 *)(glContext + 0x182c) = 0;
  *(undefined4 *)(glContext + 0x1850) = 0;
  *(undefined4 *)(glContext + 0x1854) = 0x3f800000;
  *(undefined4 *)(glContext + 0x1858) = 0x3f800000;
  materialCursor = glContext;
  do {
    *(float *)(materialCursor + 0x28c0) = defaultAmbientLevel;
    *(float *)(materialCursor + 0x28c4) = defaultAmbientLevel;
    *(float *)(materialCursor + 0x28c8) = defaultAmbientLevel;
    *(undefined4 *)(materialCursor + 0x28cc) = 0x3f800000;
    *(float *)(materialCursor + 0x28d0) = defaultDiffuseLevel;
    *(float *)(materialCursor + 0x28d4) = defaultDiffuseLevel;
    *(float *)(materialCursor + 0x28d8) = defaultDiffuseLevel;
    *(undefined4 *)(materialCursor + 0x28dc) = 0x3f800000;
    *(undefined4 *)(materialCursor + 0x28e0) = 0;
    *(undefined4 *)(materialCursor + 0x28e4) = 0;
    *(undefined4 *)(materialCursor + 0x28e8) = 0;
    *(undefined4 *)(materialCursor + 0x28ec) = 0x3f800000;
    *(undefined4 *)(materialCursor + 0x28f0) = 0;
    *(undefined4 *)(materialCursor + 0x28f4) = 0;
    *(undefined4 *)(materialCursor + 0x28f8) = 0;
    *(undefined4 *)(materialCursor + 0x28fc) = 0x3f800000;
    *(undefined4 *)(materialCursor + 0x2900) = 0;
    *(undefined4 *)(materialCursor + 0x2904) = 0;
    *(undefined4 *)(materialCursor + 0x2908) = 0;
    *(undefined4 *)(materialCursor + 0x290c) = 0x3f800000;
    materialCursor = materialCursor + 0x240;
  } while (materialCursor <= glContext + 0x240);
  *(undefined4 *)(glContext + 0x3e9c) = 1;
  *(undefined1 *)(glContext + 0x3e99) = 0;
  *(undefined1 *)(glContext + 0x3984) = 0;
  *(undefined1 *)(glContext + 0x3e98) = 0;
  initRecordCursor = glContext;
  do {
    *(undefined4 *)(initRecordCursor + 0x3ea0) = 0;
    *(undefined4 *)(initRecordCursor + 0x3ea4) = 0;
    *(undefined4 *)(initRecordCursor + 0x3ea8) = 0;
    *(undefined4 *)(initRecordCursor + 0x3eac) = 0;
    initRecordCursor = initRecordCursor + 0x10;
  } while (initRecordCursor <= glContext + 0x10);
  loopIndex2 = 0;
  do {
    loopIndex = 0;
    portionRecord = loopIndex2 * 0x80 + glContext;
    portionVariablesBase = portionRecord;
    do {
      remaining9 = 4;
      variableCursor = (undefined2 *)(portionVariablesBase + 0x3ec4);
      do {
        if (loopIndex == 0) {
          componentUsage = 0x1906;
        }
        else {
          componentUsage = 0x1907;
        }
        variableCursor[-1] = componentUsage;
        *variableCursor = 0x8536;
        variableCursor = variableCursor + 4;
        remaining9 = remaining9 + -1;
      } while (remaining9 != 0);
      loopIndex = loopIndex + 1;
      *(undefined2 *)(portionRecord + 0x3ec0) = 0x852c;
      *(undefined2 *)(portionRecord + 0x3ec8) = 0;
      *(undefined2 *)(portionRecord + 0x3ecc) = 0x8537;
      portionVariablesBase = portionVariablesBase + 0x30;
      *(undefined2 *)(portionRecord + 0x3ed0) = 0;
      *(undefined2 *)(portionRecord + 0x3ed8) = 0;
      *(undefined1 *)(portionRecord + 0x3ee0) = 0;
      *(undefined1 *)(portionRecord + 0x3ee1) = 0;
      *(undefined1 *)(portionRecord + 0x3ee2) = 0;
      *(undefined2 *)(portionRecord + 0x3ee4) = 0;
      *(undefined2 *)(portionRecord + 0x3ee6) = 0;
      *(undefined2 *)(portionRecord + 0x3ee8) = 0x8530;
      *(undefined2 *)(portionRecord + 0x3eea) = 0x8530;
      *(undefined2 *)(portionRecord + 0x3eec) = 0x852e;
      portionRecord = portionRecord + 0x30;
    } while (loopIndex < 2);
    loopIndex2 = loopIndex2 + 1;
  } while (loopIndex2 < 8);
  remaining6 = 7;
  initRecordCursor = glContext + 0x42b0;
  do {
    *(undefined2 *)(initRecordCursor + 0x16) = 0x1907;
    *(undefined2 *)(initRecordCursor + 0x18) = 0x8536;
    initRecordCursor = initRecordCursor + 8;
    remaining6 = remaining6 + -1;
  } while (remaining6 != 0);
  *(undefined2 *)(glContext + 0x42cc) = 0x8532;
  ((unsigned char *)0x42c0)[glContext] = 0x1;
  *(undefined2 *)(glContext + 0x42f6) = 0x1906;
  remaining11 = 1;
  *(undefined2 *)(glContext + 0x42d4) = 0xb60;
  dstCursor = (undefined1 *)(glContext + 0x4304);
  *(undefined2 *)(glContext + 0x42f4) = 0x852e;
  *(undefined1 *)(glContext + 0x42fc) = 0;
  *(undefined2 *)(glContext + 0x42c6) = 0x1906;
  *(undefined2 *)(glContext + 0x42c4) = 0xb60;
  *(undefined2 *)(glContext + 0x42dc) = 0;
  *(undefined2 *)(glContext + 0x42e4) = 0;
  *(undefined2 *)(glContext + 0x42ec) = 0;
  do {
    remaining11 = remaining11 + -1;
    *dstCursor = 0;
    dstCursor = dstCursor + 8;
  } while (-1 < remaining11);
  remaining7 = 0x100;
  *(undefined1 *)(glContext + 0x4306) = 0;
  *(int *)(glContext + 0x4308) = glContext + 0x10;
  *(undefined1 *)(glContext + 0x4305) = 0;
  initRecordCursor = glContext;
  do {
    *(undefined4 *)(initRecordCursor + 0x10) = 0;
    *(undefined4 *)(initRecordCursor + 0x14) = 0;
    *(undefined4 *)(initRecordCursor + 0x18) = 0;
    *(undefined4 *)(initRecordCursor + 0x1c) = 0x3f800000;
    initRecordCursor = initRecordCursor + 0x10;
    remaining7 = remaining7 + -1;
  } while (remaining7 != 0);
  remaining8 = 0x80;
  *(undefined **)(glContext + 0x4310) = ((unsigned char *)0x00001010) + glContext;
  initRecordCursor = glContext;
  do {
    *(undefined4 *)(((unsigned char *)0x00001010) + initRecordCursor) = 0;
    *(undefined4 *)(((unsigned char *)0x00001014) + initRecordCursor) = 0;
    *(undefined4 *)(((unsigned char *)0x00001018) + initRecordCursor) = 0;
    *(undefined4 *)(((unsigned char *)0x0000101c) + initRecordCursor) = 0x3f800000;
    initRecordCursor = initRecordCursor + 0x10;
    remaining8 = remaining8 + -1;
  } while (remaining8 != 0);
  *(undefined1 *)(glContext + 0x4302) = 0;
  *(undefined1 *)(glContext + 0x4300) = 1;
  *(undefined1 *)(glContext + 0x4301) = 0;
  return;
}

/* _gleMakeIdentityMatrix @ 0x5180 (76 bytes) */
int _gleMakeIdentityMatrix(matrix)
  undefined4 *matrix;
{
  matrix[0xf] = 0x3f800000;
  matrix[0xe] = 0;
  *matrix = 0x3f800000;
  matrix[1] = 0;
  matrix[2] = 0;
  matrix[3] = 0;
  matrix[4] = 0;
  matrix[5] = 0x3f800000;
  matrix[6] = 0;
  matrix[7] = 0;
  matrix[8] = 0;
  matrix[9] = 0;
  matrix[10] = 0x3f800000;
  matrix[0xb] = 0;
  matrix[0xc] = 0;
  matrix[0xd] = 0;
  return;
}

/* _gleInitGLIState @ 0x51cc (776 bytes) */
void _gleInitGLIState(glContext)
  int glContext;
{
  int remaining3;
  int remaining2;
  int loopIndex;
  int remaining;
  undefined1 rendererInfoByte79;
  float float257;
  undefined4 *dstCursor;
  int matrixByteOffset;
  int vertexTexCoordCursor;
  int stateSlotCursor;
  int currentVertexAttrib;
  int currentTexCoord;
  int glContextPtr4854;
  int remaining4;
  
  loopIndex = 0;
  do {
    matrixByteOffset = loopIndex * 0x40;
    loopIndex = loopIndex + 1;
    ((int (*)())_gleMakeIdentityMatrix)(*(int *)(glContext + 0x4678) + matrixByteOffset);
    float257 = FLOAT_00108e5c;
  } while (loopIndex < 0xcb);
  glContextPtr4854 = *(int *)(glContext + 0x4854);
  *(undefined4 *)(glContext + 0x5144) = 0;
  vertexTexCoordCursor = glContextPtr4854 + -0x200;
  *(undefined4 *)(glContext + 0x50fc) = 0;
  *(float *)(glContext + 700) = float257;
  *(undefined4 *)(glContext + 0x2c0) = 0;
  remaining4 = 8;
  *(undefined4 *)(glContext + 0x2c4) = 0;
  *(undefined4 *)(glContext + 0x2c8) = 0;
  *(undefined4 *)(glContext + 0x2cc) = 0;
  *(undefined4 *)(glContext + 0x2b0) = 0;
  *(undefined4 *)(glContext + 0x2b4) = 0;
  *(undefined4 *)(glContext + 0x2b8) = 0x3f800000;
  *(undefined4 *)(glContext + 0x2e0) = 0;
  *(undefined4 *)(glContext + 0x2e4) = 0;
  *(undefined4 *)(glContext + 0x2e8) = 0;
  *(undefined4 *)(glContext + 0x2ac) = 0x3f800000;
  *(undefined4 *)(glContext + 0x2a0) = 0x3f800000;
  *(undefined4 *)(glContext + 0x2a4) = 0x3f800000;
  *(undefined4 *)(glContext + 0x2a8) = 0x3f800000;
  *(undefined4 *)(glContextPtr4854 + -0x1d0) = 0x3f800000;
  *(undefined4 *)(glContextPtr4854 + -500) = 0x3f800000;
  *(undefined4 *)(glContextPtr4854 + -0x1cc) = 0x3f800000;
  *(undefined4 *)(glContextPtr4854 + -0x1c8) = 0x3f800000;
  *(undefined4 *)(glContextPtr4854 + -0x1c4) = 0x3f800000;
  currentTexCoord = glContext;
  do {
    *(undefined4 *)(currentTexCoord + 0x120) = 0;
    *(undefined4 *)(currentTexCoord + 0x124) = 0;
    *(undefined4 *)(currentTexCoord + 0x128) = 0;
    *(undefined4 *)(currentTexCoord + 300) = 0x3f800000;
    currentTexCoord = currentTexCoord + 0x10;
    *(undefined4 *)(vertexTexCoordCursor + 0x80) = 0;
    *(undefined4 *)(vertexTexCoordCursor + 0x84) = 0;
    *(undefined4 *)(vertexTexCoordCursor + 0x88) = 0;
    *(undefined4 *)(vertexTexCoordCursor + 0x8c) = 0x3f800000;
    vertexTexCoordCursor = vertexTexCoordCursor + 0x10;
    remaining4 = remaining4 + -1;
  } while (remaining4 != 0);
  remaining = 0x10;
  currentVertexAttrib = glContext;
  do {
    *(undefined4 *)(currentVertexAttrib + 0x1a0) = 0;
    *(undefined4 *)(currentVertexAttrib + 0x1a4) = 0;
    *(undefined4 *)(currentVertexAttrib + 0x1a8) = 0;
    *(undefined4 *)(currentVertexAttrib + 0x1ac) = 0x3f800000;
    currentVertexAttrib = currentVertexAttrib + 0x10;
    remaining = remaining + -1;
  } while (remaining != 0);
  *(undefined4 *)(glContext + 0x2d0) = 0x3f800000;
  remaining2 = 3;
  dstCursor = (undefined4 *)(glContext + 0x2d4);
  do {
    *dstCursor = 0;
    float257 = FLOAT_00108e5c;
    dstCursor = dstCursor + 1;
    remaining2 = remaining2 + -1;
  } while (remaining2 != 0);
  *(undefined1 *)(glContext + 0x2ef) = 1;
  *(undefined1 *)(glContext + 0x2ec) = 1;
  stateSlotCursor = glContext;
  do {
    *(undefined4 *)(stateSlotCursor + 0x2f0) = 0;
    *(float *)(stateSlotCursor + 0x2f4) = float257;
    *(float *)(stateSlotCursor + 0x2f8) = float257;
    stateSlotCursor = stateSlotCursor + 0x10;
  } while (stateSlotCursor <= glContext + 0x10);
  *(undefined4 *)(glContext + 0x74cc) = 0;
  *(undefined4 *)(glContext + 0x74d0) = 0x3f800000;
  *(undefined4 *)(glContext + 0x5408) = 0;
  *(undefined4 *)(glContext + 0x5404) = 0;
  *(undefined4 *)(0x74a4 + glContext + 4) = 1;
  *(undefined4 *)(glContext + 0x74ac) = 0;
  *(undefined4 *)(glContext + 0x74b0) = 0x3f800000;
  *(undefined4 *)(glContext + 0x74b8) = 1;
  *(undefined4 *)(glContext + 0x74c8) = 1;
  *(undefined4 *)(glContext + 0x74bc) = 0;
  *(undefined4 *)(glContext + 0x74c0) = 0x3f800000;
  *(undefined4 *)(glContext + 0x74d8) = 0;
  *(undefined4 *)(glContext + 0x74dc) = 0;
  *(undefined1 *)(glContext + 0x74e0) = 0;
  *(undefined1 *)(glContext + 0x74e1) = 0;
  *(undefined1 *)(glContext + 0x74e2) = 0;
  *(undefined1 *)(glContext + 0x74e3) = 0;
  *(undefined1 *)(glContext + 0x74e4) = 0;
  *(undefined1 *)(glContext + 0x74e5) = 0;
  *(undefined1 *)(glContext + 0x74e6) = 0;
  *(undefined1 *)(glContext + 0x74e7) = 0;
  *(undefined1 *)(glContext + 0x74e8) = 0;
  *(undefined1 *)(glContext + 0x74e9) = 0;
  *(undefined1 *)(glContext + 0x74ea) = 0;
  *(undefined1 *)(glContext + 0x74eb) = 0;
  *(undefined1 *)(glContext + 0x74ec) = 0;
  *(undefined1 *)(glContext + 0x74ed) = 0;
  *(undefined1 *)(glContext + 0x74ee) = 0;
  *(undefined1 *)(glContext + 0x74ef) = 0;
  *(undefined1 *)(glContext + 0x74f0) = 0;
  *(undefined1 *)(glContext + 0x74f1) = 0;
  *(undefined1 *)(glContext + 0x74f2) = 0;
  _memset(glContext + 0x74f4,0,0x40);
  _memset(glContext + 0x7534,0,0x40);
  *(undefined4 *)(glContext + 0x4fd8) = 0x600;
  *(undefined4 *)(glContext + 0x4ff4) = 4;
  *(undefined4 *)(glContext + 0x754c) = 1;
  dstCursor = (undefined4 *)(glContext + 0x4ffc);
  *(undefined4 *)(glContext + 0x505c) = 0;
  remaining3 = 0x18;
  *(undefined **)(glContext + 0x5080) = ((unsigned char *)0x00001100U);
  *(undefined **)(glContext + 0x4ff8) = &_gleStackOffsets;
  *(undefined4 *)(glContext + 0x750c) = 1;
  *(undefined4 *)(glContext + 0x7450) = 0;
  *(undefined4 *)(glContext + 0x4fd4) = 0;
  *(undefined1 *)(glContext + 0x4df8) = 0;
  *(undefined **)(glContext + 0x507c) = ((unsigned char *)0x00001100U);
  do {
    *dstCursor = 0;
    dstCursor = dstCursor + 1;
    remaining3 = remaining3 + -1;
  } while (remaining3 != 0);
  *(undefined4 *)(glContext + 0x4e1c) = 0x1c00;
  *(int *)(glContext + 0x4fbc) = glContext + 0x4e2c;
  *(undefined4 *)(glContext + 0x757c) = 0xffffffff;
  *(undefined2 *)(glContext + 0x48e8) = 0x1406;
  *(undefined4 *)(glContext + 0x4e28) = 0;
  *(undefined4 *)(glContext + 0x53d4) = 0;
  *(undefined4 *)(glContext + 0x53d8) = 0;
  *(undefined4 *)(glContext + 0x514c) = 0;
  *(undefined4 *)(glContext + 0x5150) = 0;
  *(undefined4 *)(glContext + 0x48dc) = 0;
  *(undefined4 *)(glContext + 0x48d8) = 0;
  *(undefined4 *)(glContext + 0x48ec) = 0;
  *(undefined4 *)(glContext + 0x48f0) = 0;
  *(undefined4 *)(glContext + 0x48e0) = 0;
  *(undefined4 *)(glContext + 0x48e4) = 0;
  *(undefined2 *)(glContext + 0x48ea) = 0;
  *(undefined4 *)(glContext + 0x7574) = 0;
  *(undefined1 *)(glContext + 0x7583) = 0;
  rendererInfoByte79 = *(undefined1 *)(*(int *)(glContext + 0x468c) + 0x79);
  *(undefined1 *)(glContext + 0x759d) = 1;
  *(undefined1 *)(glContext + 0x7580) = rendererInfoByte79;
  *(undefined1 *)(glContext + 0x4fea) = 0;
  *(undefined1 *)(glContext + 0x7581) = *(undefined1 *)(glContext + 0x7580);
  *(undefined4 *)(glContext + 0x7594) = 3;
  *(undefined4 *)(glContext + 0x7598) = 0;
  *(undefined1 *)(glContext + 0x759c) = 1;
  return;
}

/* _gleInitDerivedState @ 0x54d4 (728 bytes) */
void _gleInitDerivedState(glContext)
  int glContext;
{
  int remaining3;
  int remaining2;
  int remaining;
  float fVar1;
  undefined *vertexEval2FuncThenEyeInterpFuncThenClipInterpFunc;
  undefined *vertexSubmitFunc;
  int lightRecordCursor;
  undefined1 *dstCursor;
  int faceMaterialRecord;
  int glContextPtr4854;
  int *srcCursor;
  
  glContextPtr4854 = *(int *)(glContext + 0x4854);
  *(int *)(glContext + 0x5140) = glContext + 0x5100;
  *(int *)(glContext + 0x50f8) = glContext + 0x50b8;
  srcCursor = (int *)(glContext + 0x4dd0);
  *(undefined1 *)(glContext + 0x4e18) = 0;
  remaining = 1;
  *(undefined1 *)(glContext + 0x2ed) = 0;
  *(undefined1 *)(glContext + 0x2ee) = 6;
  *(undefined1 *)(glContextPtr4854 + -0x181) = 0;
  *(undefined4 *)(glContextPtr4854 + -0x200) = 0;
  *(undefined1 *)(glContextPtr4854 + -0x182) = 6;
  *(undefined1 *)(glContextPtr4854 + -0x184) = 0;
  *(undefined4 *)(glContextPtr4854 + -0x1e0) = 0;
  *(undefined4 *)(glContextPtr4854 + -0x1dc) = 0;
  *(undefined4 *)(glContextPtr4854 + -0x1d8) = 0;
  *(undefined4 *)(glContextPtr4854 + -0x1d4) = 0x3f800000;
  *(undefined4 *)(glContextPtr4854 + -0x1f0) = 0;
  *(undefined4 *)(glContextPtr4854 + -0x1ec) = 0;
  *(undefined4 *)(glContextPtr4854 + -0x1e8) = 0;
  *(undefined4 *)(glContextPtr4854 + -0x1e4) = 0x3f800000;
  *(undefined4 *)(glContextPtr4854 + -0x1fc) = 0;
  *(undefined4 *)(glContextPtr4854 + -0x1f8) = 0;
  *(undefined4 *)(glContextPtr4854 + -0x1c0) = 0;
  *(undefined4 *)(glContextPtr4854 + -0x1bc) = 0;
  *(undefined4 *)(glContextPtr4854 + -0x1b8) = 0x3f800000;
  *(undefined4 *)(glContextPtr4854 + -0x1b4) = 0x3f800000;
  *(undefined1 *)(glContextPtr4854 + -0x183) = 1;
  *(undefined1 *)(glContext + 0x5410) = 1;
  *(undefined4 *)(glContext + 0x540c) = 0;
  *(undefined4 *)(glContext + 0x53e8) = 0;
  *(undefined4 *)(glContext + 0x53ec) = 0;
  *(undefined4 *)(glContext + 0x53f0) = 0;
  *(undefined4 *)(glContext + 0x74b4) = 0x3f800000;
  *(undefined4 *)(glContext + 0x74c4) = 0x3f800000;
  *(undefined4 *)(glContext + 0x74d4) = 0x3f800000;
  *(undefined4 *)(glContext + 0x4fcc) = 0;
  *(undefined4 *)(glContext + 0x4ddc) = 0;
  *(undefined4 *)(glContext + 0x4fd0) = 0;
  *(undefined1 *)(glContext + 0x4fdc) = 0;
  do {
    remaining = remaining + -1;
    faceMaterialRecord = *srcCursor;
    srcCursor = srcCursor + 1;
    *(undefined4 *)(faceMaterialRecord + 500) = 0xbf800000;
    *(undefined1 *)(faceMaterialRecord + 0x234) = 0x1f;
    *(undefined1 *)(faceMaterialRecord + 0x235) = 0;
    *(undefined1 *)(faceMaterialRecord + 0x236) = 0;
  } while (-1 < remaining);
  remaining3 = 8;
  lightRecordCursor = glContext;
  do {
    *(undefined1 *)(lightRecordCursor + 0x4ada) = 0;
    *(undefined1 *)(lightRecordCursor + 0x4adb) = 1;
    *(undefined4 *)(lightRecordCursor + 0x4a94) = 0xbf800000;
    *(undefined4 *)(lightRecordCursor + 0x4ad4) = 0x3f800000;
    lightRecordCursor = lightRecordCursor + 0x6c;
    remaining3 = remaining3 + -1;
  } while (remaining3 != 0);
  *(undefined1 *)(glContext + 0x53e7) = 0;
  *(undefined4 *)(glContext + 0x50b0) = 0;
  *(undefined1 *)(glContext + 0x50b5) = 0;
  *(undefined1 *)(glContext + 0x50b4) = 0;
  *(undefined1 *)(glContext + 0x4fe0) = 0;
  *(undefined4 *)(glContext + 0x4a14) = 0;
  *(undefined1 *)(glContext + 0x4a18) = 0;
  *(undefined4 *)(glContext + 20000) = 0;
  *(undefined4 *)(glContext + 0x4e24) = 0;
  *(undefined4 *)(glContext + 0x4fc0) = 0;
  *(undefined1 *)(glContext + 0x4fc8) = 0;
  *(undefined4 *)(glContext + 0x4fc4) = 0;
  *(undefined1 *)(glContext + 0x4fc9) = 0;
  *(undefined4 *)(glContext + 0x53dc) = 0;
  *(undefined4 *)(glContext + 0x53e0) = 0;
  *(undefined1 *)(glContext + 0x53e4) = 0;
  *(undefined1 *)(glContext + 0x53e5) = 0;
  *(undefined1 *)(glContext + 0x53e6) = 0;
  *(undefined4 *)(glContext + 0x50a8) = 0x11;
  remaining2 = 8;
  *(undefined2 *)(glContext + 0x4a12) = 0xffff;
  *(undefined1 *)(glContext + 0x4fe3) = 2;
  dstCursor = (undefined1 *)(glContext + 0x531c);
  *(undefined4 *)(glContext + 0x50ac) = 0xffffffff;
  *(undefined2 *)(glContext + 0x4a10) = 0xffff;
  *(int *)(glContext + 0x4fec) = glContext + 0x1cc0;
  *(int *)(glContext + 0x4ff0) = glContext + 0x22c0;
  *(undefined1 *)(glContext + 0x4fe1) = 1;
  *(undefined1 *)(glContext + 0x4fe2) = 1;
  do {
    *(undefined4 *)(dstCursor + -8) = 0;
    *(undefined4 *)(dstCursor + -4) = 0;
    *dstCursor = 0;
    vertexEval2FuncThenEyeInterpFuncThenClipInterpFunc = PTR__gleSetVertexEval2Func_00112068;
    dstCursor = dstCursor + 0xc;
    remaining2 = remaining2 + -1;
  } while (remaining2 != 0);
  *(undefined **)(glContext + 0x4898) = PTR__gleSetVertexEval1Func_0011206c;
  vertexSubmitFunc = PTR__gleSetVertexSubmitFunc_0011242c;
  *(undefined **)(glContext + 0x489c) = vertexEval2FuncThenEyeInterpFuncThenClipInterpFunc;
  *(undefined **)(glContext + 0x4888) = vertexSubmitFunc;
  vertexEval2FuncThenEyeInterpFuncThenClipInterpFunc = PTR__gleSetEyeInterpFunc_0011203c;
  *(undefined2 *)(glContext + 0x487e) = 0x7c;
  *(undefined **)(glContext + 0x49c8) = vertexEval2FuncThenEyeInterpFuncThenClipInterpFunc;
  vertexEval2FuncThenEyeInterpFuncThenClipInterpFunc = PTR__gleSetClipInterpFunc_00112038;
  fVar1 = FLOAT_00108e80;
  *(undefined4 *)(glContext + 0x4884) = *(undefined4 *)(glContext + 0xd8);
  *(undefined2 *)(glContext + 0x487c) = 0x100;
  *(undefined **)(glContext + 0x49cc) = vertexEval2FuncThenEyeInterpFuncThenClipInterpFunc;
  *(float *)(glContext + 0x10c) = fVar1;
  *(undefined4 *)(glContext + 0x488c) = 0;
  *(undefined4 *)(glContext + 0x4890) = 0;
  *(undefined4 *)(glContext + 0x4868) = 0;
  *(undefined4 *)(glContext + 0x486c) = 0;
  *(undefined4 *)(glContext + 0x48d0) = 0;
  *(undefined4 *)(glContext + 0x48d4) = 0;
  *(undefined4 *)(glContext + 0xf0) = 0;
  *(undefined4 *)(glContext + 0xf4) = 0;
  *(undefined4 *)(glContext + 0xf8) = 0;
  *(undefined4 *)(glContext + 0xfc) = 0;
  *(undefined4 *)(glContext + 0x100) = 0;
  *(undefined4 *)(glContext + 0x104) = 0;
  *(undefined4 *)(glContext + 0x108) = 0x3f800000;
  *(undefined4 *)(glContext + 0x110) = 0;
  *(undefined4 *)(glContext + 0x114) = 0;
  *(undefined4 *)(glContext + 0x118) = 0;
  *(undefined4 *)(glContext + 0x11c) = 0;
  *(undefined4 *)(glContext + 0x4a1c) = 0x3f800000;
  *(undefined4 *)(glContext + 0x758c) = 0;
  *(undefined4 *)(glContext + 0x4a40) = 0x3f000000;
  *(undefined4 *)(glContext + 0x4a50) = 0;
  *(undefined4 *)(glContext + 0x4a54) = 0x3f800000;
  *(undefined4 *)(glContext + 0x4a20) = 0;
  *(undefined4 *)(glContext + 0x4a24) = 0x3f800000;
  *(undefined4 *)(glContext + 0x4a28) = 0;
  *(undefined4 *)(glContext + 0x4a2c) = 0x3f800000;
  *(undefined4 *)(glContext + 0x4a30) = 0;
  *(undefined4 *)(glContext + 0x4a34) = 0x3f800000;
  *(undefined4 *)(glContext + 19000) = 0;
  *(undefined4 *)(glContext + 0x4a3c) = 0x3f000000;
  *(undefined4 *)(glContext + 0x4a44) = 0x3f800000;
  *(undefined4 *)(glContext + 0x4a48) = 0;
  *(undefined4 *)(glContext + 0x4a4c) = 0x3f800000;
  *(undefined1 *)(glContext + 0x7584) = 0;
  *(undefined1 *)(glContext + 0x7585) = 0;
  *(undefined1 *)(glContext + 0x7586) = 0;
  *(undefined1 *)(glContext + 0x7587) = 0;
  *(undefined4 *)(glContext + 0x7588) = 0;
  return;
}

/* _gleInitTextureState @ 0x57ac (592 bytes) */
void _gleInitTextureState(glContext)
  int glContext;
{
  uint loopIndex8;
  uint loopIndex7;
  int loopIndex4;
  int loopIndex3;
  int remaining2;
  int loopIndex2;
  int loopIndex;
  int remaining;
  char glContextByte85a4;
  undefined4 copiedWord;
  int textureObject;
  int textureObject2;
  int rendererHandleBase;
  int *dstCursor;
  undefined4 *srcCursor;
  int loopIndex5;
  undefined4 *dstCursor2;
  uint loopIndex6;
  int *dstCursor3;
  int glContextPlusIndex4;
  int textureObject3;
  
  loopIndex6 = 0;
  dstCursor3 = (int *)(glContext + 0x5294);
  glContextPlusIndex4 = glContext;
  do {
    textureObject = ((int (*)())_gleCreateTextureObject)(loopIndex6 | 0x1000,0);
    ((void (*)())_gleCreatePluginTexture)(glContext,textureObject + 0x10);
    *dstCursor3 = textureObject;
    rendererHandleBase = loopIndex6 * 4 + glContext + 0x10000;
    dstCursor = (int *)(glContextPlusIndex4 + 0x5154);
    remaining2 = 0xf;
    do {
      glContextByte85a4 = *(char *)(glContext + 0x85a4);
      loopIndex5 = 0;
      *dstCursor = textureObject;
      dstCursor = dstCursor + 5;
      if (glContextByte85a4 != '\0') {
        dstCursor2 = (undefined4 *)(rendererHandleBase + -0x7920);
        srcCursor = (undefined4 *)(textureObject + 0x10);
        do {
          copiedWord = *srcCursor;
          loopIndex5 = loopIndex5 + 1;
          srcCursor = srcCursor + 1;
          *dstCursor2 = copiedWord;
          dstCursor2 = dstCursor2 + 0xb8;
        } while (loopIndex5 < (int)(uint)*(byte *)(glContext + 0x85a4));
      }
      remaining2 = remaining2 + -1;
      rendererHandleBase = rendererHandleBase + 0x14;
    } while (-1 < remaining2);
    loopIndex6 = loopIndex6 + 1;
    glContextPlusIndex4 = glContextPlusIndex4 + 4;
    dstCursor3 = dstCursor3 + 1;
    *(int *)(textureObject + 8) = *(int *)(textureObject + 8) + 0x10;
  } while ((int)loopIndex6 < 5);
  loopIndex7 = 0;
  dstCursor3 = (int *)(glContext + 0x52a8);
  do {
    textureObject3 = ((int (*)())_gleCreateTextureObject)(loopIndex7 | 0x1100,0);
    loopIndex7 = loopIndex7 + 1;
    ((void (*)())_gleCreatePluginTexture)(glContext,textureObject3 + 0x10);
    *dstCursor3 = textureObject3;
    dstCursor3 = dstCursor3 + 1;
  } while ((int)loopIndex7 < 5);
  loopIndex = 0;
  dstCursor3 = (int *)(glContext + 0x52bc);
  glContextPlusIndex4 = glContext;
  do {
    textureObject2 = ((int (*)())_gleCreateTextureObject)(loopIndex << 4 | 0x1204,0);
    srcCursor = (undefined4 *)(textureObject2 + 0x10);
    ((void (*)())_gleCreatePluginTexture)(glContext,srcCursor);
    glContextByte85a4 = *(char *)(glContext + 0x85a4);
    loopIndex3 = 0;
    *dstCursor3 = textureObject2;
    dstCursor3 = dstCursor3 + 1;
    if (glContextByte85a4 != '\0') {
      dstCursor2 = (undefined4 *)(glContextPlusIndex4 + 0x8820);
      do {
        copiedWord = *srcCursor;
        loopIndex3 = loopIndex3 + 1;
        srcCursor = srcCursor + 1;
        *dstCursor2 = copiedWord;
        dstCursor2 = dstCursor2 + 0xb8;
      } while (loopIndex3 < (int)(uint)*(byte *)(glContext + 0x85a4));
    }
    loopIndex = loopIndex + 1;
    glContextPlusIndex4 = glContextPlusIndex4 + 4;
  } while (loopIndex < 3);
  dstCursor3 = (int *)(glContext + 0x52c8);
  loopIndex8 = 0;
  remaining = 2;
  do {
    textureObject = ((int (*)())_gleCreateTextureObject)(loopIndex8 | 0x1304,0);
    loopIndex8 = loopIndex8 + 0x10;
    ((void (*)())_gleCreatePluginTexture)(glContext,textureObject + 0x10);
    remaining = remaining + -1;
    *dstCursor3 = textureObject;
    dstCursor3 = dstCursor3 + 1;
  } while (-1 < remaining);
  loopIndex2 = 0;
  dstCursor3 = (int *)(glContext + 0x52d4);
  glContextPlusIndex4 = glContext;
  do {
    textureObject2 = ((int (*)())_gleCreateTextureObject)(((unsigned char *)0x00001204U),0);
    srcCursor = (undefined4 *)(textureObject2 + 0x10);
    ((void (*)())_gleCreatePluginTexture)(glContext,srcCursor);
    glContextByte85a4 = *(char *)(glContext + 0x85a4);
    loopIndex4 = 0;
    *dstCursor3 = textureObject2;
    dstCursor3 = dstCursor3 + 1;
    if (glContextByte85a4 != '\0') {
      dstCursor2 = (undefined4 *)(glContextPlusIndex4 + 0x882c);
      do {
        copiedWord = *srcCursor;
        loopIndex4 = loopIndex4 + 1;
        srcCursor = srcCursor + 1;
        *dstCursor2 = copiedWord;
        dstCursor2 = dstCursor2 + 0xb8;
      } while (loopIndex4 < (int)(uint)*(byte *)(glContext + 0x85a4));
    }
    loopIndex2 = loopIndex2 + 1;
    glContextPlusIndex4 = glContextPlusIndex4 + 4;
  } while (loopIndex2 < 0x10);
  return;
}

/* _gleCreateTextureObject @ 0x59fc (148 bytes) */
int _gleCreateTextureObject(textureTypeFlags, texture)
  uint textureTypeFlags;
  undefined4 texture;
{
  undefined *freeFunction;
  undefined4 *allocatedBlock;
  undefined4 incomingR6;
  undefined4 incomingR7;
  undefined4 incomingR8;
  int faceCount;
  
  faceCount = 0;
  if (((textureTypeFlags & 0x200) == 0) && (faceCount = 6, (textureTypeFlags & 0xf) != 0)) {
    faceCount = 1;
  }
  allocatedBlock = (undefined4 *)_malloc(faceCount * 0x168 + 0x944);
  freeFunction = PTR__gleFreeTextureObject_001115dc;
  *allocatedBlock = 0;
  allocatedBlock[1] = texture;
  allocatedBlock[2] = 1;
  allocatedBlock[3] = freeFunction;
  ((void (*)())_gleInitializeGLTexture)(textureTypeFlags,faceCount,allocatedBlock + 4,incomingR6,incomingR7,incomingR8,1);
  return allocatedBlock;
}

/* _gleInitializeGLTexture @ 0x5a90 (832 bytes) */
void _gleInitializeGLTexture(textureTypeFlags, faceCount, textureObject, unusedArg4, unusedArg5, unusedArg6, unusedArg7)
  undefined4 textureTypeFlags;
  int faceCount;
  undefined4 *textureObject;
  undefined4 unusedArg4;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
  undefined4 unusedArg7;
{
  int loopIndex2;
  undefined1 uVar2;
  undefined2 defaultMinFilter;
  undefined1 uVar6;
  undefined2 defaultWrapMode;
  undefined4 *cursor;
  int levelRecord;
  int loopIndex;
  int remaining;
  int remaining2;
  
  *(undefined2 *)((int)textureObject + 0x32) = 0;
  *(undefined2 *)(textureObject + 0xc) = 0x404;
  textureObject[8] = 0;
  *(ushort *)(textureObject + 9) = (*(unsigned short *)((unsigned char *)&(textureTypeFlags) + 2));
  *(undefined2 *)((int)textureObject + 0x26) = 0;
  textureObject[10] = 0x3f800000;
  textureObject[0xb] = 0;
  if (((*(unsigned short *)((unsigned char *)&(textureTypeFlags) + 2)) & 0x200) == 0) {
    *(undefined2 *)(textureObject + 0x1e) = 0;
  }
  else {
    *(undefined2 *)(textureObject + 0x1e) = 0x80e2;
  }
  *(undefined2 *)((int)textureObject + 0x7a) = 0;
  if (((*(unsigned short *)((unsigned char *)&(textureTypeFlags) + 2)) & 0x2000) != 0) {
    *(undefined1 *)(textureObject + 0x24) = 1;
    *(undefined1 *)((int)textureObject + 0x92) = 2;
    *(undefined1 *)((int)textureObject + 0x93) = 0;
    *(undefined2 *)(textureObject + 0xe) = 0x812f;
    *(undefined2 *)((int)textureObject + 0x3a) = 0x2600;
    *(undefined1 *)((int)textureObject + 0x91) = 0;
    *(undefined2 *)(textureObject + 0xd) = 0x812f;
    *(undefined2 *)((int)textureObject + 0x36) = 0x812f;
    goto LAB_00005c28;
  }
  switch((*(unsigned short *)((unsigned char *)&(textureTypeFlags) + 2)) & 0xf) {
  case 0:
    uVar6 = 6;
    goto LAB_00005bb8;
  case 1:
    *(undefined1 *)((int)textureObject + 0x91) = 0;
    *(undefined1 *)(textureObject + 0x24) = 1;
    *(undefined1 *)((int)textureObject + 0x93) = 2;
    *(undefined1 *)((int)textureObject + 0x92) = 2;
    break;
  case 2:
    uVar2 = 1;
    *(undefined1 *)(textureObject + 0x24) = 1;
    *(undefined1 *)((int)textureObject + 0x92) = 2;
    *(undefined1 *)((int)textureObject + 0x93) = 0;
    goto LAB_00005bc8;
  case 3:
    uVar6 = 1;
LAB_00005bb8:
    uVar2 = 0;
    *(undefined1 *)(textureObject + 0x24) = uVar6;
    *(undefined1 *)((int)textureObject + 0x92) = 2;
    *(undefined1 *)((int)textureObject + 0x93) = 0;
LAB_00005bc8:
    *(undefined1 *)((int)textureObject + 0x91) = uVar2;
    break;
  case 4:
    *(undefined1 *)(textureObject + 0x24) = 1;
    *(undefined1 *)((int)textureObject + 0x93) = 0;
    *(undefined1 *)((int)textureObject + 0x91) = 0;
    *(undefined1 *)((int)textureObject + 0x92) = 0;
    break;
  default:
    *(undefined1 *)((int)textureObject + 0x93) = 0;
    *(undefined1 *)((int)textureObject + 0x91) = 0;
    *(undefined1 *)(textureObject + 0x24) = 0;
    *(undefined1 *)((int)textureObject + 0x92) = 0;
  }
  if (((*(unsigned short *)((unsigned char *)&(textureTypeFlags) + 2)) & 0xf) == 2) {
    defaultWrapMode = 0x812f;
    defaultMinFilter = 0x2601;
  }
  else {
    defaultWrapMode = 0x2901;
    defaultMinFilter = 0x2702;
  }
  *(undefined2 *)(textureObject + 0xe) = defaultWrapMode;
  *(undefined2 *)((int)textureObject + 0x3a) = defaultMinFilter;
  *(undefined2 *)(textureObject + 0xd) = defaultWrapMode;
  *(undefined2 *)((int)textureObject + 0x36) = defaultWrapMode;
LAB_00005c28:
  *(undefined2 *)(textureObject + 0xf) = 0x2601;
  *(undefined2 *)((int)textureObject + 0x3e) = 0x85bd;
  *(undefined2 *)(textureObject + 0x1f) = 0;
  *(undefined2 *)((int)textureObject + 0x7e) = 0;
  *(undefined2 *)(textureObject + 0x20) = 0;
  *(undefined1 *)((int)textureObject + 0x82) = 0;
  remaining = 8;
  *(undefined1 *)((int)textureObject + 0x83) = 0;
  *(undefined1 *)(textureObject + 0x21) = 0;
  *(undefined1 *)((int)textureObject + 0x85) = 0;
  *(undefined1 *)((int)textureObject + 0x86) = 0;
  *(undefined1 *)((int)textureObject + 0x87) = 0;
  *(undefined1 *)(textureObject + 0x22) = 0;
  *(undefined1 *)((int)textureObject + 0x89) = 0;
  *(undefined1 *)((int)textureObject + 0x8a) = 0;
  *(undefined1 *)((int)textureObject + 0x8b) = 0;
  *(undefined1 *)(textureObject + 0x23) = 0;
  *(undefined1 *)((int)textureObject + 0x8d) = 0;
  *(undefined1 *)((int)textureObject + 0x8e) = 0;
  *(undefined1 *)((int)textureObject + 0x8f) = 0;
  *(undefined2 *)(textureObject + 0x25) = 0;
  *(undefined2 *)((int)textureObject + 0x96) = 0;
  *(undefined2 *)(textureObject + 0x26) = 0;
  *(undefined2 *)((int)textureObject + 0x9a) = 0;
  *(undefined2 *)(textureObject + 0x27) = 0;
  *(undefined2 *)((int)textureObject + 0x9e) = 0;
  *(undefined2 *)(textureObject + 0x28) = 0;
  *(undefined2 *)((int)textureObject + 0xa2) = 0;
  *(undefined2 *)(textureObject + 0x29) = 0;
  *(undefined2 *)((int)textureObject + 0xa6) = 0;
  *(undefined2 *)(textureObject + 0x2a) = 0;
  *(undefined2 *)((int)textureObject + 0xaa) = 0;
  textureObject[0x10] = 0;
  textureObject[0x11] = 0;
  textureObject[0x12] = 0;
  *(undefined2 *)(textureObject + 0x1b) = 0x1909;
  textureObject[0x15] = 0xc47a0000;
  *(undefined2 *)((int)textureObject + 0x62) = 1000;
  *(undefined2 *)(textureObject + 0x19) = 0x203;
  textureObject[0x14] = 0x3f800000;
  textureObject[0x16] = 0x447a0000;
  *(undefined2 *)((int)textureObject + 0x66) = 0;
  textureObject[0x1a] = 0;
  textureObject[0x1b] = textureObject[0x1b] & 0xffff7f3f;
  textureObject[0x1d] = 0;
  textureObject[0x13] = 0;
  textureObject[0x17] = 0;
  *(undefined2 *)(textureObject + 0x18) = 0;
  textureObject[0x1c] = 0;
  cursor = textureObject;
  do {
    *cursor = 0;
    cursor = cursor + 1;
    remaining = remaining + -1;
  } while (remaining != 0);
  loopIndex2 = 0;
  *(undefined1 *)((int)textureObject + 0xb7) = 0;
  *(undefined2 *)(textureObject + 0x2f) = 0x1908;
  *(undefined2 *)((int)textureObject + 0xbe) = 0x1401;
  textureObject[0x2b] = 0;
  *(undefined2 *)(textureObject + 0x2c) = 0;
  *(undefined2 *)((int)textureObject + 0xb2) = 0;
  *(undefined2 *)(textureObject + 0x2d) = 0;
  *(undefined1 *)((int)textureObject + 0xb6) = 0;
  *(undefined2 *)(textureObject + 0x2e) = 0;
  *(undefined2 *)((int)textureObject + 0xba) = 0;
  textureObject[0x30] = 0;
  if (0 < faceCount) {
    loopIndex = 0;
    do {
      levelRecord = (int)textureObject + loopIndex;
      remaining2 = 0xf;
      do {
        *(undefined2 *)(levelRecord + 200) = 0;
        *(undefined2 *)(levelRecord + 0xca) = 0;
        *(undefined2 *)(levelRecord + 0xcc) = 0;
        *(undefined1 *)(levelRecord + 0xce) = 0;
        *(undefined2 *)(levelRecord + 0xd0) = 0;
        *(undefined2 *)(levelRecord + 0xd2) = 0;
        *(undefined2 *)(levelRecord + 0xd4) = 0x1908;
        *(undefined2 *)(levelRecord + 0xd6) = 0x1401;
        *(undefined4 *)(levelRecord + 0xd8) = 0;
        *(undefined1 *)(levelRecord + 0xcf) = 0;
        *(undefined4 *)(levelRecord + 0xc4) = 0;
        levelRecord = levelRecord + 0x18;
        remaining2 = remaining2 + -1;
      } while (remaining2 != 0);
      loopIndex2 = loopIndex2 + 1;
      loopIndex = loopIndex + 0x168;
    } while (loopIndex2 < faceCount);
  }
  return;
}

/* _gleCreatePluginTexture @ 0x5de4 (120 bytes) */
void _gleCreatePluginTexture(glContext, textureRecord)
  int glContext;
  int textureRecord;
{
  int *rendererCallbacks;
  undefined4 *rendererHandlePtr;
  int rendererRecordCursor;
  int loopIndex;
  int rendererSlot;
  
  rendererRecordCursor = glContext + 0x10000;
  loopIndex = 0;
  if (*(char *)(glContext + 0x85a4) != '\0') {
    rendererSlot = textureRecord;
    do {
      rendererCallbacks = (int *)(rendererRecordCursor + -0x777c);
      rendererHandlePtr = (undefined4 *)(rendererRecordCursor + -0x7a54);
      rendererRecordCursor = rendererRecordCursor + 0x2e0;
      loopIndex = loopIndex + 1;
      (**(code **)(*rendererCallbacks + 0x14c))(*rendererHandlePtr,rendererSlot,textureRecord + 0x24);
      rendererSlot = rendererSlot + 4;
    } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
  }
  return;
}

/* _gleInitPipelineProgramState @ 0x5e5c (624 bytes) */
void _gleInitPipelineProgramState(glContext)
  int glContext;
{
  undefined4 allocatedBlock;
  uint loopIndex5;
  uint *cursor2;
  int loopIndex4;
  int loopIndex2;
  char glContextByte85a42;
  byte glContextByte85a4;
  undefined4 rendererProgramHandle;
  uint uVar4;
  uint listValue;
  ushort *srcCursor;
  undefined1 *allocatedBlock2;
  int iVar8;
  uint *allocatedBlock3;
  uint *cursor;
  undefined4 *srcCursor2;
  uint *cursor3;
  uint entriesLeft;
  undefined4 *dstCursor;
  int sharedState;
  int iVar16;
  uint previousValue;
  int iVar18;
  int loopIndex;
  uint loopIndex6;
  int loopIndex3;
  uint loopIndex7;
  
  sharedState = *(int *)(glContext + 0x5148);
  allocatedBlock2 = (undefined1 *)_malloc(0x600);
  *allocatedBlock2 = 0;
  loopIndex = 0;
  *(undefined4 *)(glContext + 0x541c) = 0xffffffff;
  *(undefined1 **)(glContext + 0x5418) = allocatedBlock2;
  iVar16 = glContext;
  iVar18 = glContext;
  do {
    loopIndex3 = 0;
    iVar8 = ((int (*)())_gleCreatePipelineProgramObject)(glContext,loopIndex,0);
    ((void (*)())_gleCreatePluginPipelineProgram)(glContext,iVar8 + 0x10);
    glContextByte85a42 = *(char *)(glContext + 0x85a4);
    *(int *)(iVar18 + 0x5428) = iVar8;
    *(int *)(iVar18 + 0x5420) = iVar8;
    if (glContextByte85a42 != '\0') {
      srcCursor2 = (undefined4 *)(iVar8 + 0x4a8);
      dstCursor = (undefined4 *)(iVar16 + 0x886c);
      do {
        rendererProgramHandle = *srcCursor2;
        loopIndex3 = loopIndex3 + 1;
        srcCursor2 = srcCursor2 + 1;
        *dstCursor = rendererProgramHandle;
        dstCursor = dstCursor + 0xb8;
      } while (loopIndex3 < (int)(uint)*(byte *)(glContext + 0x85a4));
    }
    loopIndex = loopIndex + 1;
    iVar16 = iVar16 + 4;
    iVar18 = iVar18 + 4;
    *(int *)(iVar8 + 8) = *(int *)(iVar8 + 8) + 1;
  } while (loopIndex < 2);
  iVar16 = sharedState + 0x10000;
  if (*(char *)(sharedState + 0x8024) != '\0') {
    _pthread_mutex_lock(sharedState + 0x8028);
  }
  loopIndex2 = 0;
  iVar18 = glContext;
  do {
    if (*(int *)(iVar16 + -0x7560) == 0) {
      previousValue = 0;
      loopIndex6 = 0;
      allocatedBlock3 = (uint *)_malloc((uint)*(byte *)(glContext + 0x85a4) * 4 + 4);
      loopIndex7 = 1;
      uVar4 = 0x100;
      if (loopIndex2 != 0) {
        uVar4 = 0x80;
      }
      glContextByte85a4 = *(byte *)(glContext + 0x85a4);
      loopIndex4 = 0;
      *allocatedBlock3 = uVar4;
      if (glContextByte85a4 != 0) {
        srcCursor = (ushort *)(iVar18 + 0x86a0);
        cursor = allocatedBlock3 + 1;
        do {
          uVar4 = (uint)*srcCursor;
          srcCursor = srcCursor + 0x170;
          if (uVar4 != 0) {
            loopIndex5 = 0;
            cursor3 = allocatedBlock3;
            if (loopIndex7 != 0) {
              do {
                if (uVar4 == *cursor3) break;
                loopIndex5 = loopIndex5 + 1;
                cursor3 = cursor3 + 1;
              } while (loopIndex5 < loopIndex7);
            }
            if (loopIndex5 == loopIndex7) {
              *cursor = uVar4;
              loopIndex7 = loopIndex7 + 1;
              cursor = cursor + 1;
            }
          }
          loopIndex4 = loopIndex4 + 1;
        } while (loopIndex4 < (int)(uint)glContextByte85a4);
      }
      *(uint *)(iVar16 + -0x7564) = loopIndex7;
      allocatedBlock = _malloc(loopIndex7 << 2);
      *(undefined4 *)(iVar16 + -0x7560) = allocatedBlock;
      if (loopIndex7 != 0) {
        do {
          uVar4 = 0x7ffffff;
          cursor2 = allocatedBlock3;
          for (entriesLeft = loopIndex7; entriesLeft != 0; entriesLeft = entriesLeft - 1) {
            listValue = *cursor2;
            cursor2 = cursor2 + 1;
            if ((previousValue < listValue) && (listValue < uVar4)) {
              uVar4 = listValue;
            }
          }
          iVar8 = loopIndex6 * 4;
          loopIndex6 = loopIndex6 + 1;
          *(uint *)(iVar8 + *(int *)(iVar16 + -0x7560)) = uVar4;
          previousValue = uVar4;
        } while (loopIndex6 < loopIndex7);
      }
      _free(allocatedBlock3);
    }
    loopIndex2 = loopIndex2 + 1;
    iVar18 = iVar18 + 0x10;
    iVar16 = iVar16 + 0xa30;
    if (1 < loopIndex2) {
      if (*(char *)(sharedState + 0x8024) != '\0') {
        _pthread_mutex_unlock(sharedState + 0x8028);
        return;
      }
      return;
    }
  } while( true );
}

/* _gleCreatePipelineProgramObject @ 0x60cc (480 bytes) */
int _gleCreatePipelineProgramObject(glContext, param_2, program)
  undefined4 glContext;
  int param_2;
  undefined4 program;
{
  undefined4 *cursor2;
  undefined4 *cursor;
  int loopIndex;
  int remaining3;
  int remaining2;
  int iVar1;
  uint uVar2;
  undefined *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *allocatedBlock;
  int remaining4;
  int iVar8;
  undefined1 uVar9;
  int remaining;
  
  iVar8 = 0x4e4;
  if (param_2 == 0) {
    remaining4 = 0x100;
    iVar8 = 0x4e8;
    uVar9 = 0;
  }
  else if (param_2 == 1) {
    remaining4 = 0x80;
    iVar8 = 0x4f4;
    uVar9 = 0x80;
  }
  else {
    remaining4 = 0;
    uVar9 = 0;
  }
  uVar2 = iVar8 + 0xfU & 0xfffffff0;
  allocatedBlock = (undefined4 *)((int (*)())_gleVecAlloc)(uVar2 + remaining4 * 0x10);
  puVar3 = PTR__gleFreePipelineProgramObject_00110e90;
  *(undefined1 *)(allocatedBlock + 0x13) = 1;
  allocatedBlock[2] = 1;
  allocatedBlock[3] = puVar3;
  allocatedBlock[1] = program;
  iVar8 = (int)allocatedBlock + uVar2;
  allocatedBlock[9] = 0;
  cursor = allocatedBlock + 0x12a;
  *allocatedBlock = 0;
  remaining = 8;
  allocatedBlock[4] = 0;
  allocatedBlock[5] = 0;
  allocatedBlock[6] = 0;
  allocatedBlock[7] = 0;
  *(undefined2 *)(allocatedBlock + 0x14) = 0;
  *(undefined2 *)((int)allocatedBlock + 0x52) = 0;
  *(undefined2 *)(allocatedBlock + 0x15) = 0;
  *(undefined2 *)((int)allocatedBlock + 0x56) = 0;
  *(undefined2 *)((int)allocatedBlock + 0x4e) = 0;
  allocatedBlock[8] = 0;
  do {
    *cursor = 0;
    cursor = cursor + 1;
    remaining = remaining + -1;
  } while (remaining != 0);
  remaining2 = 9;
  cursor2 = allocatedBlock + 10;
  do {
    *cursor2 = 0;
    cursor2 = cursor2 + 1;
    remaining2 = remaining2 + -1;
  } while (remaining2 != 0);
  puVar4 = allocatedBlock + 0x16;
  remaining3 = 0x450;
  do {
    *(undefined1 *)puVar4 = uVar9;
    puVar4 = (undefined4 *)((int)puVar4 + 1);
    remaining3 = remaining3 + -1;
  } while (remaining3 != 0);
  if (param_2 == 0) {
    allocatedBlock[0x139] = 0;
  }
  else if (param_2 == 1) {
    *(undefined2 *)(allocatedBlock + 0x13c) = 0;
    allocatedBlock[0x139] = 0;
    allocatedBlock[0x13a] = 0;
    *(undefined2 *)(allocatedBlock + 0x13b) = 0;
    *(undefined2 *)((int)allocatedBlock + 0x4ee) = 0;
  }
  loopIndex = 0;
  allocatedBlock[0x137] = 0;
  allocatedBlock[0x133] = 0;
  allocatedBlock[0x136] = 0;
  *(short *)((int)allocatedBlock + 0x4ca) = (short)param_2;
  allocatedBlock[0x134] = 0xffffffff;
  allocatedBlock[0x135] = 0xffffffff;
  allocatedBlock[0x138] = iVar8;
  *(undefined2 *)(allocatedBlock + 0x132) = 0;
  for (; remaining4 != 0; remaining4 = remaining4 + -1) {
    iVar1 = loopIndex * 0x10;
    loopIndex = loopIndex + 1;
    iVar5 = iVar1 + iVar8;
    *(undefined4 *)(iVar8 + iVar1) = 0;
    *(undefined4 *)(iVar5 + 0xc) = 0x3f800000;
    *(undefined4 *)(iVar5 + 4) = 0;
    *(undefined4 *)(iVar5 + 8) = 0;
  }
  return allocatedBlock;
}

/* _gleVecAlloc @ 0x62ac (12 bytes) */
int _gleVecAlloc(byteSize)
  int byteSize;
{
  undefined4 allocatedBlock;
  
  allocatedBlock = _malloc(byteSize + 0xfU & 0xfffffff0);
  return allocatedBlock;
}

/* _gleCreatePluginPipelineProgram @ 0x62b8 (120 bytes) */
void _gleCreatePluginPipelineProgram(glContext, programObject)
  int glContext;
  int programObject;
{
  int *rendererCallbacks;
  undefined4 *rendererHandlePtr;
  int rendererRecordCursor;
  int loopIndex;
  int programHandleSlot;
  
  rendererRecordCursor = glContext + 0x10000;
  loopIndex = 0;
  if (*(char *)(glContext + 0x85a4) != '\0') {
    programHandleSlot = programObject + 0x498;
    do {
      rendererCallbacks = (int *)(rendererRecordCursor + -0x777c);
      rendererHandlePtr = (undefined4 *)(rendererRecordCursor + -0x7a54);
      rendererRecordCursor = rendererRecordCursor + 0x2e0;
      loopIndex = loopIndex + 1;
      (**(code **)(*rendererCallbacks + 400))(*rendererHandlePtr,programHandleSlot,programObject + 0x4b8);
      programHandleSlot = programHandleSlot + 4;
    } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
  }
  return;
}

/* _gleInitShaderState @ 0x6330 (16 bytes) */
void _gleInitShaderState(glContext)
  int glContext;
{
  *(undefined4 *)(glContext + 0x5438) = 0;
  *(undefined4 *)(glContext + 0x5434) = 0;
  return;
}

/* _gleInitBufferState @ 0x6340 (48 bytes) */
void _gleInitBufferState(glContext)
  int glContext;
{
  undefined4 *dstCursor;
  int remaining;
  
  remaining = 0x20;
  *(undefined4 *)(glContext + 0x48f4) = 0;
  dstCursor = (undefined4 *)(glContext + 0x48f8);
  do {
    *dstCursor = 0;
    dstCursor = dstCursor + 1;
    remaining = remaining + -1;
  } while (remaining != 0);
  *(undefined4 *)(glContext + 0x4a6c) = 0;
  *(undefined4 *)(glContext + 0x4978) = 0;
  *(undefined4 *)(glContext + 0x4a68) = 0;
  return;
}

/* _glePPEmulatorInitialize @ 0x6370 (48 bytes) */
void _glePPEmulatorInitialize(glContext)
  int glContext;
{
  undefined4 emulator;
  
  emulator = _PPEmulatorCreate();
  *(undefined4 *)(glContext + 0x4a5c) = emulator;
  return;
}

/* _gleInitVertexArrayState @ 0x63a0 (148 bytes) */
void _gleInitVertexArrayState(glContext)
  int glContext;
{
  undefined4 pluginVertexArray;
  int vertexArrayObject;
  undefined4 *dstCursor;
  int loopIndex;
  undefined4 *srcCursor;
  
  vertexArrayObject = ((int (*)())_gleCreateVertexArrayObject)(glContext,0);
  srcCursor = (undefined4 *)(vertexArrayObject + 0x10);
  ((void (*)())_gleCreatePluginVertexArray)(glContext,srcCursor);
  loopIndex = 0;
  *(int *)(glContext + 0x4a64) = vertexArrayObject;
  *(int *)(glContext + 0x4a60) = vertexArrayObject;
  if (*(char *)(glContext + 0x85a4) != '\0') {
    dstCursor = (undefined4 *)(glContext + 0x8874);
    do {
      pluginVertexArray = *srcCursor;
      loopIndex = loopIndex + 1;
      srcCursor = srcCursor + 1;
      *dstCursor = pluginVertexArray;
      dstCursor = dstCursor + 0xb8;
    } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
  }
  *(int *)(vertexArrayObject + 8) = *(int *)(vertexArrayObject + 8) + 1;
  return;
}

/* _gleCreateVertexArrayObject @ 0x6434 (428 bytes) */
int _gleCreateVertexArrayObject(glContext, param_2)
  int glContext;
  undefined4 param_2;
{
  undefined4 *cursor4;
  undefined4 *cursor3;
  undefined4 *cursor2;
  int loopIndex;
  int remaining3;
  int remaining2;
  undefined *puVar1;
  undefined4 *cursor;
  undefined4 *cursor5;
  undefined4 *puVar4;
  int remaining;
  int remaining4;
  undefined4 *vertexArrayObject;
  
  puVar4 = (undefined4 *)((int (*)())_gleVecAlloc)((uint)*(byte *)(glContext + 0x85a4) * 0x8c + 0x3e0);
  vertexArrayObject = puVar4;
  puVar1 = PTR__gleFreeVertexArrayObject_001115f8;
  remaining = 0x20;
  *puVar4 = 0;
  puVar4[2] = 1;
  puVar4[3] = puVar1;
  puVar4[1] = param_2;
  cursor = puVar4;
  do {
    cursor[0xc] = 0;
    cursor[0xd] = 0;
    *(undefined2 *)(cursor + 0xe) = 0x1406;
    *(undefined2 *)((int)cursor + 0x3a) = 4;
    *(undefined1 *)(cursor + 0xf) = 0;
    cursor[0x11] = 0xffffffff;
    *(undefined1 *)((int)cursor + 0x3d) = 0;
    cursor[0x10] = 0;
    cursor = cursor + 6;
    remaining = remaining + -1;
  } while (remaining != 0);
  puVar4[0xd4] = 0;
  puVar4[0xd5] = 0;
  puVar4[0xcc] = 0;
  puVar4[0xcd] = 0;
  puVar4[0xce] = 0;
  puVar4[0xcf] = 0;
  *(undefined2 *)(puVar4 + 0x32) = 0x1401;
  remaining2 = 0x20;
  *(undefined2 *)(puVar4 + 0x38) = 0x1405;
  *(undefined2 *)((int)puVar4 + 0x342) = 0x85b4;
  cursor2 = puVar4 + 0xd8;
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
    *cursor2 = 0;
    cursor2 = cursor2 + 1;
    remaining2 = remaining2 + -1;
  } while (remaining2 != 0);
  remaining3 = 8;
  cursor3 = puVar4 + 4;
  do {
    *cursor3 = 0;
    cursor3 = cursor3 + 1;
    remaining3 = remaining3 + -1;
  } while (remaining3 != 0);
  loopIndex = 0;
  cursor4 = puVar4;
  if (*(char *)(glContext + 0x85a4) != '\0') {
    do {
      cursor5 = puVar4 + 0xf8;
      remaining4 = 0x20;
      do {
        *cursor5 = 0;
        cursor5 = cursor5 + 1;
        remaining4 = remaining4 + -1;
      } while (remaining4 != 0);
      cursor4[0x118] = 0;
      loopIndex = loopIndex + 1;
      cursor4[0x119] = 0xffffffff;
      cursor4[0x11a] = 0xffffffff;
      puVar4 = puVar4 + 0x23;
      cursor4 = cursor4 + 0x23;
    } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
  }
  return (int)vertexArrayObject;
}

/* _gleCreatePluginVertexArray @ 0x65e0 (132 bytes) */
void _gleCreatePluginVertexArray(glContext, vertexArrayState)
  int glContext;
  int vertexArrayState;
{
  int *rendererCallbacks;
  undefined4 *rendererHandlePtr;
  int rendererRecordCursor;
  int loopIndex;
  int rendererSlot;
  int rendererRecord;
  
  rendererRecordCursor = glContext + 0x10000;
  loopIndex = 0;
  if (*(char *)(glContext + 0x85a4) != '\0') {
    rendererSlot = vertexArrayState;
    rendererRecord = vertexArrayState + 0x3d0;
    do {
      rendererCallbacks = (int *)(rendererRecordCursor + -0x777c);
      rendererHandlePtr = (undefined4 *)(rendererRecordCursor + -0x7a54);
      rendererRecordCursor = rendererRecordCursor + 0x2e0;
      loopIndex = loopIndex + 1;
      (**(code **)(*rendererCallbacks + 0x1a4))(*rendererHandlePtr,rendererSlot,vertexArrayState + 0x20,rendererRecord);
      rendererSlot = rendererSlot + 4;
      rendererRecord = rendererRecord + 0x8c;
    } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
  }
  return;
}

/* _gleInitFenceMachine @ 0x6664 (36 bytes) */
void _gleInitFenceMachine(glContext)
  int glContext;
{
  undefined4 *dstCursor;
  int remaining;
  
  remaining = 0x400;
  dstCursor = (undefined4 *)(glContext + 0x543c);
  do {
    *dstCursor = 0;
    dstCursor = dstCursor + 1;
    remaining = remaining + -1;
  } while (remaining != 0);
  *(undefined4 *)(glContext + 0x643c) = 0;
  return;
}

/* _gleInitQueryMachine @ 0x6688 (40 bytes) */
void _gleInitQueryMachine(glContext)
  int glContext;
{
  undefined4 *dstCursor;
  int remaining;
  
  remaining = 0x400;
  dstCursor = (undefined4 *)(glContext + 0x6440);
  do {
    *dstCursor = 0;
    dstCursor = dstCursor + 1;
    remaining = remaining + -1;
  } while (remaining != 0);
  *(undefined4 *)(glContext + 0x7444) = 0;
  *(undefined4 *)(glContext + 0x7440) = 0;
  return;
}

/* _gleInitDrawPixelsObject @ 0x66b0 (40 bytes) */
void _gleInitDrawPixelsObject(glContext)
  int glContext;
{
  *(undefined4 *)(0x74a4 + glContext) = 0;
  *(undefined4 *)(glContext + 0x7488) = 0;
  *(undefined4 *)(glContext + 0x7494) = 0;
  *(undefined4 *)(glContext + 0x748c) = 0;
  *(undefined4 *)(glContext + 0x7490) = 0;
  *(undefined4 *)(glContext + 0x7498) = 0;
  *(undefined4 *)(glContext + 0x749c) = 0;
  *(undefined4 *)(glContext + 0x74a0) = 0;
  return;
}

