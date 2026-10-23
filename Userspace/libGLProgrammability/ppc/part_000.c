#include "decls.h"

/* _PPEmulatorCreate @ 0x97b7bc5c (56 bytes) */
int _PPEmulatorCreate()
{
  undefined4 allocation;
  
  allocation = _malloc(0xe00);
  ((int (*)())_PPEmulatorInit)(allocation);
  return allocation;
}

/* dyld_stub_binding_helper @ 0x97b7bc94 (48 bytes) */
int dyld_stub_binding_helper(param_1)
  undefined4 param_1;
{
                    
                    
  (*dyld_lazy_symbol_binding_entry_point)(param_1);
  return;
}

/* _PPEmulatorInit @ 0x97b7bcc4 (96 bytes) */
int _PPEmulatorInit(emulator)
  int emulator;
{
  undefined4 allocation;
  undefined4 interpreterCreateResult;
  
  _memset(emulator,0,0xdf4);
  allocation = _malloc(0x1010);
  *(undefined4 *)(emulator + 0xd84) = allocation;
  _memset(allocation,0,0x1010);
  ((double (*)())_PPCConstantsAndScratchInitialise)(emulator);
  interpreterCreateResult = _InterpreterCreate();
  *(undefined4 *)(emulator + 0xdf0) = interpreterCreateResult;
  return _InterpreterAttachEmulatorContext(interpreterCreateResult,emulator);
}

/* _PPParserCreate @ 0x97b7bd24 (96 bytes) */
int _PPParserCreate(param_1)
  undefined4 param_1;
{
  int allocation;
  undefined4 ppParserScopeCreateResult;
  
  allocation = _calloc(0x490,1);
  *(undefined4 *)(allocation + 0x48c) = param_1;
  *(undefined4 *)(allocation + 0x34) = 0xffffffff;
  *(undefined4 *)(allocation + 0x38) = 0xffffffff;
  ppParserScopeCreateResult = ((int (*)())_PPParserScopeCreate)(allocation);
  ((int (*)())_PPParserAddScope)(allocation,ppParserScopeCreateResult);
  return allocation;
}

/* _PPParserScopeCreate @ 0x97b7bd84 (408 bytes) */
int _PPParserScopeCreate(param_1)
  undefined4 param_1;
{
  undefined4 allocation;
  int ppParserMacroCreateResult;
  undefined4 ppParserPreprocessStringResult;
  undefined1 auStack_f0 [96];
  undefined1 auStack_90 [120];
  
  _memcpy(auStack_f0,
          "DP4 dst.x, mat[0], vec;\nDP4 dst.y, mat[1], vec;\nDP4 dst.z, mat[2], vec;\nDP4 dst.w, mat[3], vec;"
          ,0x60);
  _memcpy(auStack_90,
          "MUL tmp, mat[0], vec.x;\nMAD tmp, mat[1], vec.y, tmp;\nMAD tmp, mat[2], vec.z, tmp;\nMAD dst, mat[3], vec.w, tmp;\n"
          ,0x70);
  allocation = _calloc(0x24,1);
  ppParserMacroCreateResult = ((int (*)())_PPParserMacroCreate)();
  ((int (*)())_PPParserMacroSetSearchString)(param_1,ppParserMacroCreateResult,"MVMULT",6);
  ((int (*)())_PPParserMacroSetParamStringsCount)(ppParserMacroCreateResult,3);
  ((int (*)())_PPParserMacroSetParamString)(ppParserMacroCreateResult,0,"dst");
  ((int (*)())_PPParserMacroSetParamString)(ppParserMacroCreateResult,1,"mat");
  ((int (*)())_PPParserMacroSetParamString)(ppParserMacroCreateResult,2,"vec");
  ppParserPreprocessStringResult = ((int (*)())_PPParserPreprocessString)(param_1,auStack_f0,0);
  *(undefined4 *)(ppParserMacroCreateResult + 4) = ppParserPreprocessStringResult;
  ((int (*)())_PPParserScopeAddMacro)(allocation,ppParserMacroCreateResult);
  ppParserMacroCreateResult = ((int (*)())_PPParserMacroCreate)();
  ((int (*)())_PPParserMacroSetSearchString)(param_1,ppParserMacroCreateResult,"TMVMULT",7);
  ((int (*)())_PPParserMacroSetParamStringsCount)(ppParserMacroCreateResult,4);
  ((int (*)())_PPParserMacroSetParamString)(ppParserMacroCreateResult,0,"dst");
  ((int (*)())_PPParserMacroSetParamString)(ppParserMacroCreateResult,1,"mat");
  ((int (*)())_PPParserMacroSetParamString)(ppParserMacroCreateResult,2,"vec");
  ((int (*)())_PPParserMacroSetParamString)(ppParserMacroCreateResult,3,"tmp");
  ppParserPreprocessStringResult = ((int (*)())_PPParserPreprocessString)(param_1,auStack_90,0);
  *(undefined4 *)(ppParserMacroCreateResult + 4) = ppParserPreprocessStringResult;
  ((int (*)())_PPParserScopeAddMacro)(allocation,ppParserMacroCreateResult);
  return allocation;
}

/* _PPParserMacroCreate @ 0x97b7bf1c (12 bytes) */
int _PPParserMacroCreate()
{
  undefined4 allocation;
  
  allocation = _calloc(0x20,1);
  return allocation;
}

/* _PPParserMacroSetSearchString @ 0x97b7bf28 (116 bytes) */
int _PPParserMacroSetSearchString(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int *param_2;
  int param_3;
  int param_4;
{
  int allocation;
  
  if (*param_2 != 0) {
    _free(*param_2);
    *param_2 = 0;
  }
  if (param_3 != 0) {
    allocation = _malloc(param_4 + 1);
    *param_2 = allocation;
    _memmove(allocation,param_3,param_4);
    *(undefined1 *)(*param_2 + param_4) = 0;
  }
  return;
}

/* _PPParserMacroSetParamStringsCount @ 0x97b7bf9c (60 bytes) */
int _PPParserMacroSetParamStringsCount(parser, param_2)
  int parser;
  undefined4 param_2;
{
  undefined4 allocation;
  
  allocation = _calloc(4,param_2);
  *(undefined4 *)(parser + 0xc) = allocation;
  *(undefined4 *)(parser + 8) = param_2;
  return;
}

/* _PPParserMacroSetParamString @ 0x97b7bfd8 (116 bytes) */
int _PPParserMacroSetParamString(parser, param_2, param_3)
  int parser;
  int param_2;
  undefined4 param_3;
{
  int iVar1;
  int length;
  undefined4 allocation;
  int iVar4;
  
  length = _strlen(param_3);
  iVar4 = *(int *)(parser + 0xc);
  allocation = _malloc(length + 1);
  iVar1 = param_2 * 4;
  *(undefined4 *)(iVar1 + iVar4) = allocation;
  _memmove(*(undefined4 *)(iVar1 + *(int *)(parser + 0xc)),param_3,length);
  *(undefined1 *)(*(int *)(iVar1 + *(int *)(parser + 0xc)) + length) = 0;
  return;
}

/* _PPParserPreprocessString @ 0x97b7c04c (2588 bytes) */
int _PPParserPreprocessString(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  int param_3;
{
  int allocation;
  byte bVar1;
  char cVar2;
  bool bVar3;
  uint uVar4;
  undefined1 uVar5;
  uint length;
  uint scanPos;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  
  length = _strlen(param_2);
  if (param_3 == 0) {
    scanPos = 0;
    uVar16 = 0;
LAB_97b7c0e8:
    uVar12 = 1;
  }
  else {
    scanPos = 10;
    if (length < 10) {
      scanPos = length;
    }
    uVar16 = scanPos;
    if ((((scanPos < length) && (cVar2 = *(char *)(param_2 + scanPos), cVar2 != ' ')) && (cVar2 != '\t'))
       && (((cVar2 != '\n' && (cVar2 != '\r')) && (cVar2 != '#')))) {
      scanPos = scanPos + 1;
      goto LAB_97b7c0e8;
    }
    uVar12 = 0;
  }
  bVar3 = false;
  uVar11 = 0;
joined_r0x97b7c0f8:
  uVar4 = uVar16;
  if (length <= uVar4) goto LAB_97b7c6cc;
  iVar13 = 1;
  if (bVar3) {
    if (*(char *)(param_2 + uVar4) != '\n') goto code_r0x97b7c67c;
    uVar16 = uVar4 + 1;
    goto LAB_97b7c6bc;
  }
  switch(*(undefined1 *)(param_2 + uVar4)) {
  case 9:
  case 0x20:
    if ((((uVar12 == 0) && (uVar4 + 1 < length)) &&
        ((cVar2 = *(char *)(param_2 + uVar4 + 1), cVar2 != ' ' &&
         (((cVar2 != '\t' && (cVar2 != '\n')) && (cVar2 != '\r')))))) && (cVar2 != '#')) {
LAB_97b7c5fc:
      scanPos = scanPos + 1;
      uVar12 = 1;
    }
    goto LAB_97b7c604;
  case 10:
    scanPos = scanPos + 1;
    uVar15 = uVar4 + 1;
    break;
  default:
    scanPos = scanPos + 1;
    uVar15 = uVar4 + 1;
    uVar12 = 0;
    goto LAB_97b7c664;
  case 0xd:
    scanPos = scanPos + 1;
    if ((uVar4 + 1 < length) && (*(char *)(param_2 + uVar4 + 1) == '\n')) {
      iVar13 = 2;
    }
    uVar15 = uVar4 + iVar13;
    break;
  case 0x23:
    uVar15 = uVar4 + 1;
    bVar3 = true;
    break;
  case 0x28:
  case 0x29:
  case 0x2c:
  case 0x3a:
  case 0x3b:
  case 0x3d:
  case 0x5b:
  case 0x5d:
  case 0x7b:
  case 0x7c:
  case 0x7d:
    if (uVar12 == 0) {
      scanPos = scanPos + 1;
    }
    scanPos = scanPos + 1;
    if (((uVar4 + 1 < length) && (cVar2 = *(char *)(param_2 + uVar4 + 1), cVar2 != ' ')) &&
       ((cVar2 != '\t' && (((cVar2 != '\n' && (cVar2 != '\r')) && (cVar2 != '#'))))))
    goto LAB_97b7c5fc;
    uVar12 = 0;
LAB_97b7c604:
    uVar15 = uVar4 + 1;
    goto LAB_97b7c664;
  case 0x2b:
  case 0x2d:
    if ((uVar12 == 0) && (uVar11 == 0)) {
      scanPos = scanPos + 1;
    }
    uVar15 = uVar4 + 1;
    uVar8 = scanPos + 1;
    if ((((length <= uVar15) || (bVar1 = *(byte *)(param_2 + uVar4 + 1), bVar1 - 0x30 < 10)) ||
        (bVar1 == 0x20)) ||
       (((bVar1 == 9 || (bVar1 == 10)) || ((bVar1 == 0xd || ((bVar1 == 0x23 || (bVar1 == 0x2e)))))))
       ) {
      uVar12 = 0;
      uVar16 = uVar4 + 1;
      if (uVar15 < length) {
        cVar2 = *(char *)(param_2 + uVar15);
        while ((cVar2 == ' ' || (cVar2 == '\t'))) {
          iVar13 = iVar13 + 1;
          uVar16 = uVar4 + iVar13;
          if (length <= uVar16) break;
          cVar2 = *(char *)(param_2 + uVar16);
        }
      }
      uVar11 = 0;
      scanPos = uVar8;
      if (uVar16 < length) {
        if (((uint)(*(byte *)(param_2 + uVar16) - 0x30) < 10) || (*(byte *)(param_2 + uVar16) == 0x2e)) {
          uVar11 = 1;
        }
        bVar1 = *(byte *)(param_2 + uVar16);
        if ((((9 < bVar1 - 0x30) && (bVar1 != 0x2e)) && (bVar1 != 10)) &&
           ((bVar1 != 0xd && (bVar1 != 0x23)))) {
          uVar16 = uVar4 + iVar13 + -1;
        }
      }
      goto joined_r0x97b7c0f8;
    }
    scanPos = scanPos + 2;
    break;
  case 0x2e:
    if ((uVar4 + 1 < length) && (*(char *)(param_2 + uVar4 + 1) == '.')) {
      uVar16 = scanPos;
      if (uVar12 == 0) {
        uVar16 = scanPos + 1;
      }
      scanPos = uVar16 + 2;
      if (((((uVar4 + 2 < length) && (cVar2 = *(char *)(param_2 + uVar4 + 2), cVar2 != ' ')) &&
           (cVar2 != '\t')) && ((cVar2 != '\n' && (cVar2 != '\r')))) && (cVar2 != '#')) {
        scanPos = uVar16 + 3;
        uVar12 = 1;
      }
      else {
        uVar12 = 0;
      }
      uVar15 = uVar4 + 2;
      goto LAB_97b7c664;
    }
    if ((uVar12 == 0) && (uVar11 != 1)) {
      scanPos = scanPos + 1;
    }
    uVar16 = scanPos + 1;
    if (length <= uVar4 + 1) goto LAB_97b7c64c;
    bVar1 = *(byte *)(param_2 + uVar4 + 1);
    if (bVar1 - 0x30 < 10) {
      uVar12 = 0;
      uVar11 = 3;
      scanPos = uVar16;
      uVar16 = uVar4 + 1;
      goto joined_r0x97b7c0f8;
    }
    if ((((bVar1 != 0x20) && (bVar1 != 9)) && (bVar1 != 10)) && ((bVar1 != 0xd && (bVar1 != 0x23))))
    {
      uVar12 = 1;
      scanPos = scanPos + 2;
      uVar16 = uVar4 + 1;
      goto joined_r0x97b7c0f8;
    }
    goto LAB_97b7c64c;
  case 0x30:
  case 0x31:
  case 0x32:
  case 0x33:
  case 0x34:
  case 0x35:
  case 0x36:
  case 0x37:
  case 0x38:
  case 0x39:
    uVar11 = uVar11 | uVar12;
  case 0x45:
  case 0x65:
    uVar16 = scanPos + 1;
LAB_97b7c64c:
    uVar12 = 0;
    scanPos = uVar16;
    uVar16 = uVar4 + 1;
    goto joined_r0x97b7c0f8;
  }
  uVar12 = 1;
LAB_97b7c664:
  uVar11 = 0;
  uVar16 = uVar15;
  goto joined_r0x97b7c0f8;
LAB_97b7c6cc:
  if (uVar12 == 0) {
    scanPos = scanPos + 1;
  }
  allocation = _calloc(scanPos + 1,1);
  if (param_3 == 0) {
    iVar9 = 0;
    scanPos = 0;
LAB_97b7c774:
    uVar16 = 1;
  }
  else {
    scanPos = 10;
    if (length < 10) {
      scanPos = length;
    }
    iVar9 = 0;
    for (uVar16 = scanPos; uVar16 != 0; uVar16 = uVar16 - 1) {
      *(undefined1 *)(allocation + iVar9) = *(undefined1 *)(param_2 + iVar9);
      iVar9 = iVar9 + 1;
    }
    if (((scanPos < length) && (cVar2 = *(char *)(param_2 + scanPos), cVar2 != ' ')) &&
       ((cVar2 != '\t' && (((cVar2 != '\n' && (cVar2 != '\r')) && (cVar2 != '#')))))) {
      *(undefined1 *)(allocation + iVar9) = 0x20;
      iVar9 = iVar9 + 1;
      goto LAB_97b7c774;
    }
    uVar16 = 0;
  }
  bVar3 = false;
  uVar12 = 0;
joined_r0x97b7c784:
  uVar11 = scanPos;
  if (length <= uVar11) {
    if (uVar16 == 0) {
      *(undefined1 *)(allocation + iVar9) = 0x20;
    }
    return allocation;
  }
  iVar14 = 1;
  if (bVar3) {
    if (*(char *)(param_2 + uVar11) != '\n') goto code_r0x97b7cd84;
    *(undefined1 *)(allocation + iVar9) = 10;
    scanPos = uVar11 + 1;
    goto LAB_97b7cdd0;
  }
  uVar5 = *(undefined1 *)(param_2 + uVar11);
  iVar10 = iVar9;
  switch(uVar5) {
  case 9:
  case 0x20:
    if ((((uVar16 == 0) && (uVar11 + 1 < length)) &&
        ((cVar2 = *(char *)(param_2 + uVar11 + 1), cVar2 != ' ' &&
         (((cVar2 != '\t' && (cVar2 != '\n')) && (cVar2 != '\r')))))) && (cVar2 != '#')) {
LAB_97b7ccec:
      uVar16 = 1;
      *(undefined1 *)(allocation + iVar9) = 0x20;
      iVar10 = iVar9 + 1;
    }
    goto LAB_97b7ccfc;
  case 10:
    uVar5 = 10;
    goto LAB_97b7cbd8;
  default:
    *(undefined1 *)(allocation + iVar9) = uVar5;
    scanPos = uVar11 + 1;
    iVar10 = iVar9 + 1;
    uVar16 = 0;
    break;
  case 0xd:
    *(undefined1 *)(allocation + iVar9) = 10;
    iVar10 = iVar9 + 1;
    if ((uVar11 + 1 < length) && (*(char *)(param_2 + uVar11 + 1) == '\n')) {
      iVar14 = 2;
    }
    scanPos = uVar11 + iVar14;
    goto LAB_97b7cbe0;
  case 0x23:
    scanPos = uVar11 + 1;
    bVar3 = true;
    goto LAB_97b7cbe0;
  case 0x28:
  case 0x29:
  case 0x2c:
  case 0x3a:
  case 0x3b:
  case 0x3d:
  case 0x5b:
  case 0x5d:
  case 0x7b:
  case 0x7c:
  case 0x7d:
    if (uVar16 == 0) {
      *(undefined1 *)(allocation + iVar9) = 0x20;
      iVar9 = iVar9 + 1;
    }
    *(undefined1 *)(allocation + iVar9) = uVar5;
    iVar9 = iVar9 + 1;
    if (((uVar11 + 1 < length) && (cVar2 = *(char *)(param_2 + uVar11 + 1), cVar2 != ' ')) &&
       ((cVar2 != '\t' && (((cVar2 != '\n' && (cVar2 != '\r')) && (cVar2 != '#'))))))
    goto LAB_97b7ccec;
    uVar16 = 0;
    iVar10 = iVar9;
LAB_97b7ccfc:
    scanPos = uVar11 + 1;
    break;
  case 0x2b:
  case 0x2d:
    if ((uVar16 == 0) && (uVar12 == 0)) {
      *(undefined1 *)(allocation + iVar9) = 0x20;
      iVar9 = iVar9 + 1;
    }
    uVar12 = uVar11 + 1;
    *(undefined1 *)(allocation + iVar9) = uVar5;
    iVar9 = iVar9 + 1;
    if ((((length <= uVar12) || (bVar1 = *(byte *)(param_2 + uVar11 + 1), bVar1 - 0x30 < 10)) ||
        (bVar1 == 0x20)) ||
       (((bVar1 == 9 || (bVar1 == 10)) || ((bVar1 == 0xd || ((bVar1 == 0x23 || (bVar1 == 0x2e)))))))
       ) {
      uVar16 = 0;
      scanPos = uVar11 + 1;
      if (uVar12 < length) {
        cVar2 = *(char *)(param_2 + uVar12);
        while ((cVar2 == ' ' || (cVar2 == '\t'))) {
          iVar14 = iVar14 + 1;
          scanPos = uVar11 + iVar14;
          if (length <= scanPos) break;
          cVar2 = *(char *)(param_2 + scanPos);
        }
      }
      uVar12 = 0;
      if (scanPos < length) {
        if (((uint)(*(byte *)(param_2 + scanPos) - 0x30) < 10) || (*(byte *)(param_2 + scanPos) == 0x2e)) {
          uVar12 = 1;
        }
        bVar1 = *(byte *)(param_2 + scanPos);
        if ((((9 < bVar1 - 0x30) && (bVar1 != 0x2e)) && (bVar1 != 10)) &&
           ((bVar1 != 0xd && (bVar1 != 0x23)))) {
          scanPos = uVar11 + iVar14 + -1;
        }
      }
      goto joined_r0x97b7c784;
    }
    uVar5 = 0x20;
LAB_97b7cbd8:
    scanPos = uVar11 + 1;
    *(undefined1 *)(allocation + iVar9) = uVar5;
    iVar10 = iVar9 + 1;
LAB_97b7cbe0:
    uVar16 = 1;
    break;
  case 0x2e:
    if ((length <= uVar11 + 1) || (*(char *)(param_2 + uVar11 + 1) != '.')) {
      if ((uVar16 == 0) && (uVar12 != 1)) {
        *(undefined1 *)(allocation + iVar9) = 0x20;
        iVar9 = iVar9 + 1;
      }
      *(undefined1 *)(allocation + iVar9) = 0x2e;
      iVar14 = iVar9 + 1;
      if (length <= uVar11 + 1) goto LAB_97b7cd54;
      bVar1 = *(byte *)(param_2 + uVar11 + 1);
      if (bVar1 - 0x30 < 10) {
        uVar16 = 0;
        uVar12 = 3;
        iVar9 = iVar14;
        scanPos = uVar11 + 1;
        goto joined_r0x97b7c784;
      }
      if ((((bVar1 != 0x20) && (bVar1 != 9)) && (bVar1 != 10)) &&
         ((bVar1 != 0xd && (bVar1 != 0x23)))) {
        *(undefined1 *)(allocation + iVar14) = 0x20;
        uVar16 = 1;
        iVar9 = iVar9 + 2;
        scanPos = uVar11 + 1;
        goto joined_r0x97b7c784;
      }
      goto LAB_97b7cd54;
    }
    if (uVar16 == 0) {
      *(undefined1 *)(allocation + iVar9) = 0x20;
      iVar9 = iVar9 + 1;
    }
    *(undefined1 *)(allocation + iVar9) = 0x2e;
    *(undefined1 *)(allocation + iVar9 + 1) = 0x2e;
    iVar10 = iVar9 + 2;
    if (((((uVar11 + 2 < length) && (cVar2 = *(char *)(param_2 + uVar11 + 2), cVar2 != ' ')) &&
         (cVar2 != '\t')) && ((cVar2 != '\n' && (cVar2 != '\r')))) && (cVar2 != '#')) {
      uVar16 = 1;
      *(undefined1 *)(allocation + iVar10) = 0x20;
      iVar10 = iVar9 + 3;
    }
    else {
      uVar16 = 0;
    }
    scanPos = uVar11 + 2;
    break;
  case 0x30:
  case 0x31:
  case 0x32:
  case 0x33:
  case 0x34:
  case 0x35:
  case 0x36:
  case 0x37:
  case 0x38:
  case 0x39:
    *(undefined1 *)(allocation + iVar9) = uVar5;
    uVar12 = uVar12 | uVar16;
    iVar14 = iVar9 + 1;
    goto LAB_97b7cd54;
  case 0x45:
  case 0x65:
    *(undefined1 *)(allocation + iVar9) = uVar5;
    iVar14 = iVar9 + 1;
LAB_97b7cd54:
    uVar16 = 0;
    iVar9 = iVar14;
    scanPos = uVar11 + 1;
    goto joined_r0x97b7c784;
  }
  uVar12 = 0;
  iVar9 = iVar10;
  goto joined_r0x97b7c784;
code_r0x97b7cd84:
  scanPos = uVar11 + 1;
  if (*(char *)(param_2 + uVar11) == '\r') {
    *(undefined1 *)(allocation + iVar9) = 10;
    if ((uVar11 + 1 < length) && (*(char *)(param_2 + uVar11 + 1) == '\n')) {
      iVar14 = 2;
    }
    scanPos = uVar11 + iVar14;
LAB_97b7cdd0:
    bVar3 = false;
    iVar9 = iVar9 + 1;
  }
  goto joined_r0x97b7c784;
code_r0x97b7c67c:
  uVar16 = uVar4 + 1;
  if (*(char *)(param_2 + uVar4) == '\r') {
    if ((uVar4 + 1 < length) && (*(char *)(param_2 + uVar4 + 1) == '\n')) {
      iVar13 = 2;
    }
    uVar16 = uVar4 + iVar13;
LAB_97b7c6bc:
    bVar3 = false;
    scanPos = scanPos + 1;
  }
  goto joined_r0x97b7c0f8;
}

/* _PPParserScopeAddMacro @ 0x97b7ce10 (52 bytes) */
int _PPParserScopeAddMacro(parser, param_2)
  int parser;
  int param_2;
{
  int iVar1;
  
  iVar1 = *(int *)(parser + 8);
  if (*(int *)(parser + 8) == 0) {
    iVar1 = param_2;
  }
  *(int *)(parser + 8) = iVar1;
  if (*(int *)(parser + 0xc) != 0) {
    *(int *)(*(int *)(parser + 0xc) + 0x1c) = param_2;
    *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(parser + 0xc);
  }
  *(int *)(parser + 0xc) = param_2;
  return;
}

/* _PPParserAddScope @ 0x97b7ce44 (60 bytes) */
int _PPParserAddScope(parser, param_2)
  int parser;
  int param_2;
{
  int iVar1;
  
  iVar1 = *(int *)(parser + 0x448);
  if (*(int *)(parser + 0x448) == 0) {
    iVar1 = param_2;
  }
  *(int *)(parser + 0x448) = iVar1;
  if (*(int *)(parser + 0x44c) != 0) {
    *(int *)(*(int *)(parser + 0x44c) + 0x20) = param_2;
    *(undefined4 *)(param_2 + 0x1c) = *(undefined4 *)(parser + 0x44c);
  }
  *(int *)(parser + 0x44c) = param_2;
  *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(parser + 0x1c);
  return;
}

/* _PPParserInit @ 0x97b7ce80 (4 bytes) */
int _PPParserInit()
{
  return;
}

/* _PPParserAttachString @ 0x97b7ce84 (228 bytes) */
int _PPParserAttachString(parser, param_2, param_3)
  int *parser;
  int param_2;
  int param_3;
{
  int ppParserPreprocessStringResult;
  int allocation;
  int length;
  int iVar1;
  int iVar2;
  
  if (*parser == 0) {
    if (param_2 != 0) {
      if (param_3 == 0) {
        length = _strlen(param_2);
        allocation = _calloc(length + 1,1);
        *parser = allocation;
        _memmove(allocation,param_2,length);
      }
      else {
        ppParserPreprocessStringResult = ((int (*)())_PPParserPreprocessString)(parser,param_2,1);
        *parser = ppParserPreprocessStringResult;
      }
      iVar1 = _strlen(*parser);
      iVar2 = 0;
      parser[2] = 0;
      parser[1] = iVar1;
      if (iVar1 != 0) {
        do {
          if (*(char *)(*parser + iVar2) == '\n') {
            parser[2] = parser[2] + 1;
          }
          iVar2 = iVar2 + 1;
          iVar1 = iVar1 + -1;
        } while (iVar1 != 0);
      }
    }
  }
  else {
    _free(*parser);
    parser[1] = 0;
    *parser = 0;
  }
  return;
}

/* _PPStreamCreate @ 0x97b7cf68 (152 bytes) */
int _PPStreamCreate()
{
  int allocation;
  undefined4 chunkList;
  
  allocation = _calloc(0x34,1);
  chunkList = ((int (*)())_PPStreamChunkListCreate)();
  *(undefined4 *)(allocation + 4) = chunkList;
  chunkList = ((int (*)())_PPStreamChunkListCreate)();
  *(undefined4 *)(allocation + 8) = chunkList;
  chunkList = ((int (*)())_PPStreamChunkListCreate)();
  *(undefined4 *)(allocation + 0xc) = chunkList;
  chunkList = ((int (*)())_PPStreamChunkListCreate)();
  *(undefined4 *)(allocation + 0x10) = chunkList;
  chunkList = ((int (*)())_PPStreamChunkListCreate)();
  *(undefined4 *)(allocation + 0x14) = chunkList;
  chunkList = ((int (*)())_PPStreamChunkListCreate)();
  *(undefined4 *)(allocation + 0x18) = chunkList;
  chunkList = ((int (*)())_PPStreamChunkListCreate)();
  *(undefined4 *)(allocation + 0x1c) = chunkList;
  chunkList = ((int (*)())_PPStreamChunkListCreate)();
  *(undefined4 *)(allocation + 0x20) = chunkList;
  chunkList = ((int (*)())_PPStreamChunkListCreate)();
  *(undefined4 *)(allocation + 0x24) = chunkList;
  chunkList = ((int (*)())_PPStreamChunkListCreate)();
  *(undefined4 *)(allocation + 0x2c) = chunkList;
  chunkList = ((int (*)())_PPStreamChunkListCreate)();
  *(undefined4 *)(allocation + 0x28) = chunkList;
  chunkList = ((int (*)())_PPStreamChunkListCreate)();
  *(undefined4 *)(allocation + 0x30) = chunkList;
  return allocation;
}

/* _PPStreamChunkListCreate @ 0x97b7d000 (12 bytes) */
int _PPStreamChunkListCreate()
{
  undefined4 allocation;
  
  allocation = _calloc(0xc,1);
  return allocation;
}

/* _PPParserAttachStream @ 0x97b7d00c (100 bytes) */
int _PPParserAttachStream(parser, param_2)
  int parser;
  undefined4 param_2;
{
  int iVar1;
  
  iVar1 = *(int *)(parser + 0x448);
  if (*(int *)(parser + 0x1c) != 0) {
    _PPStreamFree(*(int *)(parser + 0x1c));
  }
  *(undefined4 *)(parser + 0x1c) = param_2;
  for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x20)) {
    ((int (*)())_PPParserScopeAttachStream)(iVar1,param_2);
  }
  return;
}

/* _PPParserScopeAttachStream @ 0x97b7d070 (36 bytes) */
int _PPParserScopeAttachStream(parser, param_2)
  int *parser;
  int param_2;
{
  int iVar1;
  
  iVar1 = *parser;
  parser[6] = param_2;
  if (iVar1 != 0) {
    do {
      *(int *)(iVar1 + 0x18) = param_2;
      iVar1 = *(int *)(iVar1 + 0x20);
    } while (iVar1 != 0);
    return;
  }
  return;
}

/* _PPParserParse @ 0x97b7d094 (296 bytes) */
int _PPParserParse(parser)
  int parser;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if ((*(byte *)(parser + 0x441) & 2) == 0) {
    iVar3 = ((int (*)())_PPParserParseVersion)(parser);
  }
  while (iVar3 == 0) {
    iVar3 = ((int (*)())_PPParserParseOption)(parser);
  }
  if (iVar3 == 3) {
    do {
      iVar3 = ((int (*)())_PPParserParseStatement)(parser);
    } while (iVar3 == 0);
  }
  bVar1 = false;
  if ((*(byte *)(parser + 0x441) & 2) == 0) {
    if (iVar3 == 6) {
      iVar3 = ((int (*)())_PPParserParseEnd)(parser);
    }
    if (iVar3 == 1) {
      iVar3 = 0x2d;
    }
    if (iVar3 != 0) goto LAB_97b7d180;
    bVar1 = true;
    if (((*(uint *)(parser + 0x48c) & 0x10) != 0) &&
       (iVar2 = _PPStreamResolveBranches(*(undefined4 *)(parser + 0x1c)), iVar2 != 0)) {
      iVar3 = 0x1b;
      goto LAB_97b7d170;
    }
  }
  else if (iVar3 == 1) {
    iVar3 = 0;
LAB_97b7d170:
    bVar1 = iVar3 == 0;
  }
  if (bVar1) {
    return 0;
  }
LAB_97b7d180:
  iVar2 = 2;
  if (iVar3 != 2) {
    _PPParserBuildErrorString(parser,iVar3,0);
    iVar2 = iVar3;
  }
  return iVar2;
}

/* _PPParserParseVersion @ 0x97b7d1bc (204 bytes) */
int _PPParserParseVersion(parser)
  int parser;
{
  int compareResult;
  undefined4 uVar1;
  int part;
  undefined1 auStack_110 [264];
  
  part = ((int (*)())_PPParserGetPart)(parser,auStack_110,0);
  uVar1 = 4;
  if (part != 0) {
    if ((*(uint *)(parser + 0x48c) & 2) == 0) {
      compareResult = _memcmp(auStack_110,"!!ARBvp1.0",0xb);
      if (compareResult != 0) {
        return 4;
      }
      *(undefined4 *)(parser + 0x48c) = 0;
      **(undefined4 **)(parser + 0x1c) = 0x8620;
    }
    else {
      compareResult = _memcmp(auStack_110,"!!ARBfp1.0",0xb);
      if (compareResult != 0) {
        return 4;
      }
      *(undefined4 *)(parser + 0x48c) = 2;
      **(undefined4 **)(parser + 0x1c) = 0x8804;
    }
    uVar1 = 0;
  }
  return uVar1;
}

/* _PPParserGetPart @ 0x97b7d288 (368 bytes) */
int _PPParserGetPart(parser, param_2, param_3)
  int *parser;
  int param_2;
  int param_3;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int replaceString;
  int allocation;
  uint uVar6;
  undefined1 auStack_120 [260];
  
  iVar1 = parser[3];
  iVar2 = parser[4];
  uVar6 = 0;
  do {
    iVar3 = ((int (*)())_PPParserGetCharacter)(parser,param_2 + uVar6);
    if ((iVar3 != 0) || (*(char *)(param_2 + uVar6) == ' ')) break;
    uVar6 = uVar6 + 1;
  } while (uVar6 < 0xff);
  *(undefined1 *)(param_2 + uVar6) = 0;
  if ((uVar6 == 0) || (uVar6 == 0xff)) {
    uVar6 = 0;
  }
  else if (((param_3 != 0) && (iVar3 = ((int (*)())_PPParserScopeFindMacro)(parser[0x113],param_2), iVar3 != 0))
          && (*(int *)(iVar3 + 8) == 0)) {
    replaceString = _PPParserMacroGetReplaceString(iVar3,parser[0x123],0,auStack_120);
    iVar3 = (parser[1] + replaceString) - uVar6;
    allocation = _calloc(iVar3,1);
    _memmove(allocation,*parser,iVar1);
    _memmove(allocation + iVar1,auStack_120,replaceString);
    _memmove(allocation + iVar1 + replaceString,*parser + parser[3],parser[1] - parser[3]);
    _free(*parser);
    parser[1] = iVar3 + -1;
    *parser = allocation;
    parser[3] = iVar1;
    parser[4] = iVar2;
    uVar6 = ((int (*)())_PPParserGetPart)(parser,param_2,0);
  }
  return uVar6;
}

/* _PPParserGetCharacter @ 0x97b7d3f8 (144 bytes) */
int _PPParserGetCharacter(parser, param_2)
  int *parser;
  char *param_2;
{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  
  bVar1 = false;
  iVar3 = parser[3];
  uVar2 = 1;
  if (iVar3 != parser[1]) {
    while( true ) {
      *param_2 = *(char *)(*parser + iVar3);
      iVar3 = parser[3] + 1;
      parser[3] = iVar3;
      if (*param_2 != '\n') break;
      parser[4] = parser[4] + 1;
      if (iVar3 == parser[1]) {
        *param_2 = ' ';
        break;
      }
      bVar1 = true;
    }
    if (bVar1) {
      *param_2 = ' ';
      parser[3] = parser[3] + -1;
    }
    uVar2 = 0;
  }
  return uVar2;
}

/* _PPParserParseOption @ 0x97b7d488 (184 bytes) */
int _PPParserParseOption(parser)
  undefined4 parser;
{
  int compareResult;
  int part;
  int iVar2;
  char local_110 [264];
  
  part = ((int (*)())_PPParserGetPart)(parser,local_110,0);
  iVar2 = 1;
  if (part != 0) {
    compareResult = _memcmp(local_110,"OPTION",7);
    if (compareResult == 0) {
      iVar2 = ((int (*)())_PPParserParseOptionIdentifier)(parser);
      if (iVar2 == 0) {
        part = ((int (*)())_PPParserGetPart)(parser,local_110,0);
        iVar2 = 0x2d;
        if ((part != 0) && (iVar2 = 0x1e, local_110[0] == ';')) {
          iVar2 = 0;
        }
      }
    }
    else {
      ((int (*)())_PPParserReturnPart)(parser);
      iVar2 = 3;
    }
  }
  return iVar2;
}

/* _PPParserParseOptionIdentifier @ 0x97b7d540 (916 bytes) */
int _PPParserParseOptionIdentifier(parser)
  int parser;
{
  int compareResult;
  int part;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined1 auStack_120 [256];
  undefined4 local_20;
  uint local_1c;
  
  part = ((int (*)())_PPParserGetPart)(parser,auStack_120,0);
  if (part == 0) {
    return 0x2d;
  }
  if ((*(uint *)(parser + 0x48c) & 2) == 0) {
    compareResult = _memcmp(auStack_120,"ARB_position_invariant",0x17);
    if (compareResult == 0) {
      ((int (*)())_PPStreamAddOption)(*(undefined4 *)(parser + 0x1c),0);
      local_1c = *(uint *)(parser + 0x24) & 0xffff;
      *(uint *)(parser + 0x24) = *(uint *)(parser + 0x24) + 1;
      local_20 = 0x10000;
      ((int (*)())_PPStreamAddAttribBinding)(*(undefined4 *)(parser + 0x1c),&local_20);
      *(byte *)(parser + 0x442) = *(byte *)(parser + 0x442) | 1;
      return 0;
    }
    compareResult = _memcmp(auStack_120,"NV_vertex_program2",0x13);
    if (compareResult == 0) {
      uVar2 = *(undefined4 *)(parser + 0x1c);
      *(undefined4 *)(parser + 0x48c) = 0x31;
      uVar3 = 10;
      goto LAB_97b7d8b8;
    }
    compareResult = _memcmp(auStack_120,"NV_vertex_program3",0x13);
    if (compareResult == 0) {
      uVar2 = *(undefined4 *)(parser + 0x1c);
      *(undefined4 *)(parser + 0x48c) = 0x34;
      uVar3 = 0xb;
      goto LAB_97b7d8b8;
    }
  }
  else {
    compareResult = _memcmp(auStack_120,"ARB_fog_exp",0xc);
    if (compareResult == 0) {
      if (1 < *(byte *)(parser + 0x443)) {
        return 0x27;
      }
      uVar2 = *(undefined4 *)(parser + 0x1c);
      *(undefined1 *)(parser + 0x443) = 1;
      uVar3 = 1;
      goto LAB_97b7d8b8;
    }
    compareResult = _memcmp(auStack_120,"ARB_fog_exp2",0xd);
    if (compareResult == 0) {
      if ((*(char *)(parser + 0x443) != '\0') && (*(char *)(parser + 0x443) != '\x02')) {
        return 0x27;
      }
      uVar2 = *(undefined4 *)(parser + 0x1c);
      *(undefined1 *)(parser + 0x443) = 2;
      uVar3 = 2;
      goto LAB_97b7d8b8;
    }
    compareResult = _memcmp(auStack_120,"ARB_fog_linear",0xf);
    if (compareResult == 0) {
      if ((*(char *)(parser + 0x443) != '\0') && (*(char *)(parser + 0x443) != '\x03')) {
        return 0x27;
      }
      uVar2 = *(undefined4 *)(parser + 0x1c);
      *(undefined1 *)(parser + 0x443) = 3;
      uVar3 = 3;
      goto LAB_97b7d8b8;
    }
    compareResult = _memcmp(auStack_120,"ARB_precision_hint_fastest",0x1b);
    if (compareResult == 0) {
      if ((*(char *)(parser + 0x444) != '\0') && (*(char *)(parser + 0x444) != '\x04')) {
        return 0x27;
      }
      uVar2 = *(undefined4 *)(parser + 0x1c);
      *(undefined1 *)(parser + 0x444) = 4;
      uVar3 = 4;
      goto LAB_97b7d8b8;
    }
    compareResult = _memcmp(auStack_120,"ARB_precision_hint_nicest",0x1a);
    if (compareResult == 0) {
      if ((*(char *)(parser + 0x444) != '\0') && (*(char *)(parser + 0x444) != '\x05')) {
        return 0x27;
      }
      uVar2 = *(undefined4 *)(parser + 0x1c);
      *(undefined1 *)(parser + 0x444) = 5;
      uVar3 = 5;
      goto LAB_97b7d8b8;
    }
    compareResult = _memcmp(auStack_120,"NV_fragment_program",0x14);
    if (compareResult == 0) {
      uVar2 = *(undefined4 *)(parser + 0x1c);
      *(undefined4 *)(parser + 0x48c) = 0x33;
      uVar3 = 8;
      goto LAB_97b7d8b8;
    }
    compareResult = _memcmp(auStack_120,"NV_fragment_program2",0x15);
    if (compareResult == 0) {
      *(undefined4 *)(parser + 0x48c) = 0x36;
      ((int (*)())_PPStreamAddOption)(*(undefined4 *)(parser + 0x1c),9);
      _PPParserDeclareNVAddressRegisters(parser);
      return 0;
    }
    compareResult = _memcmp(auStack_120,"ARB_fragment_program_shadow",0x1c);
    if (compareResult == 0) {
      uVar2 = *(undefined4 *)(parser + 0x1c);
      uVar3 = 0xd;
      goto LAB_97b7d8b8;
    }
    compareResult = _memcmp(auStack_120,"ARB_draw_buffers",0x11);
    if (compareResult == 0) {
      uVar2 = *(undefined4 *)(parser + 0x1c);
      *(undefined1 *)(parser + 0x445) = 1;
      uVar3 = 0xc;
      goto LAB_97b7d8b8;
    }
  }
  compareResult = _memcmp(auStack_120,"APPLE_no_runtime_compile",0x19);
  if (compareResult == 0) {
    uVar2 = *(undefined4 *)(parser + 0x1c);
    uVar3 = 6;
  }
  else {
    compareResult = _memcmp(auStack_120,"APPLE_no_altivec",0x11);
    if (compareResult != 0) {
      return 5;
    }
    uVar2 = *(undefined4 *)(parser + 0x1c);
    uVar3 = 7;
  }
LAB_97b7d8b8:
  ((int (*)())_PPStreamAddOption)(uVar2,uVar3);
  return 0;
}

/* _PPStreamAddOption @ 0x97b7d8d4 (80 bytes) */
int _PPStreamAddOption(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined1 *allocation;
  undefined4 uVar2;
  
  allocation = (undefined1 *)_calloc(0x14,1);
  uVar2 = *(undefined4 *)(param_1 + 0x30);
  *allocation = 7;
  allocation[0xf] = (undefined1)param_2;
  return ((int (*)())_PPStreamChunkListAddChunk)(uVar2,allocation);
}

/* _PPStreamChunkListAddChunk @ 0x97b7d924 (72 bytes) */
int _PPStreamChunkListAddChunk(stream, param_2)
  int *stream;
  int param_2;
{
  if (*stream == 0) {
    *stream = param_2;
    *(undefined4 *)(param_2 + 4) = 0;
  }
  if (stream[1] != 0) {
    *(int *)(stream[1] + 8) = param_2;
    *(int *)(param_2 + 4) = stream[1];
  }
  *(undefined4 *)(param_2 + 8) = 0;
  stream[1] = param_2;
  stream[2] = stream[2] + 1;
  return;
}

/* _PPStreamAddAttribBinding @ 0x97b7d96c (92 bytes) */
int _PPStreamAddAttribBinding(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined1 *allocation;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  allocation = (undefined1 *)_calloc(0x14,1);
  uVar4 = param_2[1];
  uVar2 = *(undefined4 *)(param_1 + 0x18);
  uVar3 = *param_2;
  *allocation = 2;
  *(undefined4 *)(allocation + 0xc) = uVar3;
  *(undefined4 *)(allocation + 0x10) = uVar4;
  return ((int (*)())_PPStreamChunkListAddChunk)(uVar2,allocation);
}

/* _PPParserReturnPart @ 0x97b7d9c8 (132 bytes) */
int _PPParserReturnPart(parser)
  undefined4 parser;
{
  int iVar1;
  int iVar2;
  char local_20 [20];
  
  iVar1 = ((int (*)())_PPParserReturnCharacter)(parser,local_20);
  iVar2 = 0;
  if (iVar1 == 0) {
    iVar2 = 0;
    while (iVar1 = ((int (*)())_PPParserReturnCharacter)(parser,local_20), iVar1 == 0) {
      if (local_20[0] == ' ') {
        ((int (*)())_PPParserGetCharacter)(parser,local_20);
        return iVar2;
      }
      iVar2 = iVar2 + 1;
    }
  }
  return iVar2;
}

/* _PPParserReturnCharacter @ 0x97b7da4c (144 bytes) */
int _PPParserReturnCharacter(parser, param_2)
  int *parser;
  char *param_2;
{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = parser[3];
  bVar1 = false;
  uVar3 = 1;
  if (iVar2 != 0) {
    while( true ) {
      *param_2 = *(char *)(*parser + iVar2 + -1);
      iVar2 = parser[3] + -1;
      parser[3] = iVar2;
      if (*param_2 != '\n') break;
      parser[4] = parser[4] + -1;
      if (iVar2 == 0) {
        *param_2 = ' ';
        break;
      }
      bVar1 = true;
    }
    if (bVar1) {
      *param_2 = ' ';
      parser[3] = parser[3] + 1;
    }
    uVar3 = 0;
  }
  return uVar3;
}

/* _PPParserParseStatement @ 0x97b7dadc (2176 bytes) */
int _PPParserParseStatement(parser)
  int parser;
{
  int ppParserExpandMacroResult;
  int ppParserScopeFindMacroResult;
  int ppParserParseOperationResult;
  int length;
  int compareResult;
  int iVar1;
  int iVar2;
  int length2;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 leftoverR9;
  uint uVar8;
  int iVar9;
  int *opsList;
  undefined1 auStack_140 [256];
  char acStack_40 [20];
  
  iVar1 = ((int (*)())_PPParserGetPart)(parser,auStack_140,0);
  iVar9 = 0;
  if (iVar1 == 0) {
    return 1;
  }
  if ((*(uint *)(parser + 0x48c) & 0x22) != 0) {
    compareResult = _memcmp(auStack_140,"LONG",5);
    if (compareResult == 0) {
      iVar9 = 1;
    }
    else {
      compareResult = _memcmp(auStack_140,"SHORT",6);
      if (compareResult != 0) goto LAB_97b7db80;
      iVar9 = 2;
    }
    iVar1 = ((int (*)())_PPParserGetPart)(parser,auStack_140,0);
    if (iVar1 == 0) {
      return 1;
    }
  }
LAB_97b7db80:
  compareResult = _memcmp(auStack_140,"TEMP",5);
  if (compareResult == 0) {
    iVar2 = _PPParserParseTempDeclaration(parser,iVar9);
  }
  else {
    compareResult = _memcmp(auStack_140,"OUTPUT",7);
    if (compareResult == 0) {
      iVar2 = ((int (*)())_PPParserParseOutputDeclaration)(parser,iVar9);
    }
    else {
      iVar2 = 0x2a;
      if (iVar9 == 0) {
        uVar8 = *(uint *)(parser + 0x48c);
        if (((uVar8 & 2) == 0) && (iVar9 = _memcmp(auStack_140,"ADDRESS",8), iVar9 == 0)) {
          iVar2 = _PPParserParseAddressDeclaration(parser);
        }
        else {
          iVar9 = _memcmp(auStack_140,"PARAM",6);
          if (iVar9 == 0) {
            iVar2 = ((int (*)())_PPParserParseParameterDeclaration)(parser);
          }
          else {
            iVar9 = _memcmp(auStack_140,"ATTRIB",7);
            if (iVar9 == 0) {
              iVar2 = ((int (*)())_PPParserParseAttributeDeclaration)(parser);
            }
            else {
              iVar9 = _memcmp(auStack_140,"ALIAS",6);
              if (iVar9 == 0) {
                iVar2 = _PPParserParseAliasDeclaration(parser);
              }
              else {
                iVar9 = _memcmp(auStack_140,"MACRO",6);
                if (iVar9 == 0) {
                  iVar2 = _PPParserParseMacroDeclaration(parser);
                }
                else {
                  iVar9 = _memcmp(auStack_140,"BLOCK",6);
                  if (iVar9 != 0) {
                    if ((uVar8 & 2) == 0) {
                      opsList = &_OpsList_ARBvp10;
                    }
                    else {
                      opsList = &_OpsList_ARBfp10;
                    }
                    iVar9 = 0;
                    do {
                      iVar2 = *opsList;
                      if (iVar2 != 0) {
                        do {
                          compareResult = _strcmp(auStack_140,iVar2);
                          if (compareResult == 0) {
                            iVar1 = opsList[1];
                            uVar4 = 0;
                            goto LAB_97b7e2b0;
                          }
                          uVar8 = *(uint *)(parser + 0x48c);
                          if ((uVar8 & 0x10) != 0) {
                            _sprintf(acStack_40,"%sC",*opsList);
                            compareResult = _strcmp(auStack_140,acStack_40);
                            if (compareResult != 0) {
                              uVar8 = *(uint *)(parser + 0x48c);
                              if (uVar8 != 0x34) goto LAB_97b7ddc8;
                              _sprintf(acStack_40,"%sC0",*opsList);
                              compareResult = _strcmp(auStack_140,acStack_40);
                              if (compareResult == 0) goto LAB_97b7e228;
                              _sprintf(acStack_40,"%sC1",*opsList);
                              compareResult = _strcmp(auStack_140,acStack_40);
                              if (compareResult != 0) {
                                uVar8 = *(uint *)(parser + 0x48c);
                                goto LAB_97b7ddc8;
                              }
                              iVar1 = opsList[1];
                              uVar6 = 0;
LAB_97b7e28c:
                              uVar5 = 1;
                              uVar4 = 0;
                              uVar7 = 1;
                              goto LAB_97b7e334;
                            }
LAB_97b7e228:
                            iVar1 = opsList[1];
                            uVar4 = 0;
                            goto LAB_97b7e234;
                          }
LAB_97b7ddc8:
                          if ((uVar8 & 2) != 0) {
                            _sprintf(acStack_40,"%s_SAT",*opsList);
                            compareResult = _strcmp(auStack_140,acStack_40);
                            if (compareResult == 0) {
                              iVar1 = opsList[1];
                              uVar4 = 0;
                              goto LAB_97b7e260;
                            }
                            if ((*(uint *)(parser + 0x48c) & 0x10) == 0) goto LAB_97b7e11c;
                            _sprintf(acStack_40,"%sC_SAT",*opsList);
                            compareResult = _strcmp(auStack_140,acStack_40);
                            if (compareResult == 0) {
LAB_97b7e268:
                              iVar1 = opsList[1];
                              uVar4 = 0;
                              goto LAB_97b7e328;
                            }
                            if (*(int *)(parser + 0x48c) == 0x34) {
                              _sprintf(acStack_40,"%sC0_SAT",*opsList);
                              compareResult = _strcmp(auStack_140,acStack_40);
                              if (compareResult == 0) goto LAB_97b7e268;
                              _sprintf(acStack_40,"%sC1_SAT",*opsList);
                              compareResult = _strcmp(auStack_140,acStack_40);
                              if (compareResult == 0) {
                                iVar1 = opsList[1];
                                uVar6 = 1;
                                goto LAB_97b7e28c;
                              }
                            }
                            length = _strlen(auStack_140);
                            length2 = _strlen(*opsList);
                            if (length == length2 + 1) {
                              _sprintf(acStack_40,"%sR",*opsList);
                              compareResult = _strcmp(auStack_140,acStack_40);
                              if (compareResult == 0) {
                                iVar1 = opsList[1];
                                uVar4 = 1;
                              }
                              else {
                                _sprintf(acStack_40,"%sH",*opsList);
                                compareResult = _strcmp(auStack_140,acStack_40);
                                if (compareResult == 0) {
                                  iVar1 = opsList[1];
                                  uVar4 = 2;
                                }
                                else {
                                  _sprintf(acStack_40,"%sX",*opsList);
                                  compareResult = _strcmp(auStack_140,acStack_40);
                                  if (compareResult != 0) goto LAB_97b7e11c;
                                  iVar1 = opsList[1];
                                  uVar4 = 3;
                                }
                              }
LAB_97b7e2b0:
                              uVar5 = 0;
LAB_97b7e2b4:
                              uVar6 = 0;
                            }
                            else {
                              length = _strlen(auStack_140);
                              length2 = _strlen(*opsList);
                              if (length == length2 + 2) {
                                _sprintf(acStack_40,"%sRC",*opsList);
                                compareResult = _strcmp(auStack_140,acStack_40);
                                if (compareResult == 0) {
                                  iVar1 = opsList[1];
                                  uVar4 = 1;
                                }
                                else {
                                  _sprintf(acStack_40,"%sHC",*opsList);
                                  compareResult = _strcmp(auStack_140,acStack_40);
                                  if (compareResult == 0) {
                                    iVar1 = opsList[1];
                                    uVar4 = 2;
                                  }
                                  else {
                                    _sprintf(acStack_40,"%sXC",*opsList);
                                    compareResult = _strcmp(auStack_140,acStack_40);
                                    if (compareResult != 0) goto LAB_97b7e11c;
                                    iVar1 = opsList[1];
                                    uVar4 = 3;
                                  }
                                }
LAB_97b7e234:
                                uVar5 = 1;
                                goto LAB_97b7e2b4;
                              }
                              length = _strlen(auStack_140);
                              length2 = _strlen(*opsList);
                              if (length == length2 + 5) {
                                _sprintf(acStack_40,"%sR_SAT",*opsList);
                                compareResult = _strcmp(auStack_140,acStack_40);
                                if (compareResult == 0) {
                                  iVar1 = opsList[1];
                                  uVar4 = 1;
                                }
                                else {
                                  _sprintf(acStack_40,"%sH_SAT",*opsList);
                                  compareResult = _strcmp(auStack_140,acStack_40);
                                  if (compareResult == 0) {
                                    iVar1 = opsList[1];
                                    uVar4 = 2;
                                  }
                                  else {
                                    _sprintf(acStack_40,"%sX_SAT",*opsList);
                                    compareResult = _strcmp(auStack_140,acStack_40);
                                    if (compareResult != 0) goto LAB_97b7e11c;
                                    iVar1 = opsList[1];
                                    uVar4 = 3;
                                  }
                                }
LAB_97b7e260:
                                uVar5 = 0;
                              }
                              else {
                                length = _strlen(auStack_140);
                                length2 = _strlen(*opsList);
                                if (length != length2 + 6) goto LAB_97b7e11c;
                                _sprintf(acStack_40,"%sRC_SAT",*opsList);
                                compareResult = _strcmp(auStack_140,acStack_40);
                                if (compareResult == 0) {
                                  iVar1 = opsList[1];
                                  uVar4 = 1;
                                }
                                else {
                                  _sprintf(acStack_40,"%sHC_SAT",*opsList);
                                  compareResult = _strcmp(auStack_140,acStack_40);
                                  if (compareResult == 0) {
                                    iVar1 = opsList[1];
                                    uVar4 = 2;
                                  }
                                  else {
                                    _sprintf(acStack_40,"%sXC_SAT",*opsList);
                                    compareResult = _strcmp(auStack_140,acStack_40);
                                    if (compareResult != 0) goto LAB_97b7e11c;
                                    iVar1 = opsList[1];
                                    uVar4 = 3;
                                  }
                                }
LAB_97b7e328:
                                uVar5 = 1;
                              }
                              uVar6 = 1;
                            }
                            uVar7 = 0;
LAB_97b7e334:
                            ppParserParseOperationResult = ((int (*)())_PPParserParseOperation)(parser,iVar1,uVar4,uVar5,uVar6,uVar7,leftoverR9);
                            return ppParserParseOperationResult;
                          }
LAB_97b7e11c:
                          opsList = opsList + 2;
                          iVar2 = *opsList;
                        } while (iVar2 != 0);
                        uVar8 = *(uint *)(parser + 0x48c);
                      }
                      if (uVar8 == 0x34) {
                        if (iVar9 == 0) {
LAB_97b7e160:
                          opsList = (int *)&_OpsList_NVvp20;
                        }
                        else {
                          if (iVar9 != 1) goto LAB_97b7e1b4;
                          opsList = &_OpsList_NVvp30;
                        }
                      }
                      else {
                        if (uVar8 == 0x31) {
                          if (iVar9 == 0) goto LAB_97b7e160;
                          goto LAB_97b7e1b4;
                        }
                        if (uVar8 == 0x33) {
                          if (iVar9 != 0) goto LAB_97b7e1b4;
                        }
                        else {
                          if (uVar8 != 0x36) {
LAB_97b7e1b4:
                            if (((uVar8 & 0x10) != 0) &&
                               (iVar1 = _PPParserParseLabel(parser,auStack_140,iVar1), iVar1 != 3))
                            {
                              return iVar1;
                            }
                            ppParserScopeFindMacroResult = ((int (*)())_PPParserScopeFindMacro)(*(undefined4 *)(parser + 0x44c),auStack_140);
                            if (ppParserScopeFindMacroResult != 0) {
                              ppParserExpandMacroResult = _PPParserExpandMacro(parser,ppParserScopeFindMacroResult);
                              return ppParserExpandMacroResult;
                            }
                            iVar1 = _memcmp(auStack_140,"OPTION",7);
                            if (iVar1 == 0) {
                              return 8;
                            }
                            ((int (*)())_PPParserReturnPart)(parser);
                            return 6;
                          }
                          if (iVar9 != 0) {
                            if (iVar9 == 1) {
                              opsList = (int *)&_OpsList_NVfp20;
                              goto LAB_97b7e1ac;
                            }
                            goto LAB_97b7e1b4;
                          }
                        }
                        opsList = (int *)&_OpsList_NVfp10;
                      }
LAB_97b7e1ac:
                      iVar9 = iVar9 + 1;
                    } while( true );
                  }
                  iVar2 = _PPParserParseBlock(parser);
                }
              }
            }
          }
        }
      }
    }
  }
  return iVar2;
}

/* _PPParserParseParameterDeclaration @ 0x97b7e35c (372 bytes) */
int _PPParserParseParameterDeclaration(parser)
  int parser;
{
  int ppParserParseDefaultArrayResult;
  int ppParserScopeAddIdentifierResult;
  int ppParserIdentifierCreateResult;
  int part;
  int ppParserValidateNameResult;
  int iVar2;
  int part2;
  undefined4 uVar4;
  char local_130 [256];
  undefined4 local_30 [7];
  
  local_30[0] = 1;
  part = ((int (*)())_PPParserGetPart)(parser,local_130,0);
  uVar4 = 0;
  iVar2 = 0x2d;
  if (part != 0) {
    ppParserValidateNameResult = ((int (*)())_PPParserValidateName)(parser,local_130);
    iVar2 = 0x12;
    if (ppParserValidateNameResult == 0) {
      ppParserIdentifierCreateResult = ((int (*)())_PPParserIdentifierCreate)();
      ((int (*)())_PPParserIdentifierSetName)(ppParserIdentifierCreateResult,local_130);
      *(undefined4 *)(ppParserIdentifierCreateResult + 0xc) = 2;
      ppParserScopeAddIdentifierResult = ((int (*)())_PPParserScopeAddIdentifier)(*(undefined4 *)(parser + 0x44c),ppParserIdentifierCreateResult);
      if (ppParserScopeAddIdentifierResult == 0) {
        part2 = ((int (*)())_PPParserGetPart)(parser,local_130,0);
        iVar2 = 0x2d;
        if (part2 != 0) {
          if (local_130[0] == '[') {
            ((int (*)())_PPParserReturnPart)(parser);
            ppParserParseDefaultArrayResult = _PPParserParseDefaultArray(parser,local_30);
            if (ppParserParseDefaultArrayResult != 0) {
              return ppParserParseDefaultArrayResult;
            }
            *(undefined1 *)(ppParserIdentifierCreateResult + 0x10) = 1;
            iVar2 = ((int (*)())_PPParserGetPart)(parser,local_130,0);
            if (iVar2 == 0) {
              return 0x2d;
            }
            uVar4 = 1;
          }
          iVar2 = 10;
          if (local_130[0] == '=') {
            *(undefined4 *)(ppParserIdentifierCreateResult + 8) = *(undefined4 *)(parser + 0x20);
            iVar2 = ((int (*)())_PPParserParseParamBinding)(parser,uVar4,local_30);
            if (iVar2 == 0) {
              *(undefined4 *)(ppParserIdentifierCreateResult + 4) = local_30[0];
              part = ((int (*)())_PPParserGetPart)(parser,local_130,0);
              iVar2 = 0x2d;
              if ((part != 0) && (iVar2 = 10, local_130[0] == ';')) {
                iVar2 = 0;
              }
            }
          }
        }
      }
      else {
        _PPParserIdentifierFree(ppParserIdentifierCreateResult);
        iVar2 = 0x1c;
      }
    }
  }
  return iVar2;
}

/* _PPParserValidateName @ 0x97b7e4d0 (1360 bytes) */
int _PPParserValidateName(parser, param_2)
  int parser;
  undefined4 param_2;
{
  int loopIndex;
  int length;
  int compareResult;
  int length3;
  int compareResult2;
  int iVar1;
  int iVar2;
  uint uVar3;
  int length2;
  char *pcVar5;
  int *piVar6;
  char acStack_30 [24];
  
  if ((*(uint *)(parser + 0x48c) & 2) == 0) {
    piVar6 = &_vpDclList;
  }
  else {
    piVar6 = &_fpDclList;
  }
  iVar1 = *piVar6;
  while (iVar1 != 0) {
    compareResult2 = _strcmp(param_2,iVar1);
    if (compareResult2 == 0) {
      return 0x12;
    }
    piVar6 = piVar6 + 2;
    iVar1 = *piVar6;
  }
  length3 = _strlen(param_2);
  uVar3 = *(uint *)(parser + 0x48c);
  if ((((uVar3 == 0) || (uVar3 == 2)) && (1 < length3 - 3U)) && ((length3 != 7 && (length3 != 8)))) {
    return 0;
  }
  if ((uVar3 & 2) == 0) {
    piVar6 = &_OpsList_ARBvp10;
  }
  else {
    piVar6 = &_OpsList_ARBfp10;
  }
  loopIndex = 0;
  do {
    iVar2 = *piVar6;
    if (iVar2 != 0) {
      do {
        compareResult = _strcmp(param_2,iVar2);
        if (compareResult == 0) {
          return 0x12;
        }
        uVar3 = *(uint *)(parser + 0x48c);
        if ((uVar3 & 0x10) != 0) {
          _sprintf(acStack_30,"%sC",*piVar6);
          compareResult = _strcmp(param_2,acStack_30);
          if (compareResult == 0) {
            return 0x12;
          }
          uVar3 = *(uint *)(parser + 0x48c);
          if (uVar3 == 0x34) {
            _sprintf(acStack_30,"%sC0",*piVar6);
            compareResult = _strcmp(param_2,acStack_30);
            if (compareResult == 0) {
              return 0x12;
            }
            _sprintf(acStack_30,"%sC1",*piVar6);
            compareResult = _strcmp(param_2,acStack_30);
            if (compareResult == 0) {
              return 0x12;
            }
            uVar3 = *(uint *)(parser + 0x48c);
          }
        }
        if ((uVar3 & 2) != 0) {
          _sprintf(acStack_30,"%s_SAT",*piVar6);
          compareResult = _strcmp(param_2,acStack_30);
          if (compareResult == 0) {
            return 0x12;
          }
          if ((*(uint *)(parser + 0x48c) & 0x10) != 0) {
            _sprintf(acStack_30,"%sC_SAT",*piVar6);
            compareResult = _strcmp(param_2,acStack_30);
            if (compareResult == 0) {
              return 0x12;
            }
            if (*(int *)(parser + 0x48c) == 0x34) {
              _sprintf(acStack_30,"%sC0_SAT",*piVar6);
              compareResult = _strcmp(param_2,acStack_30);
              if (compareResult == 0) {
                return 0x12;
              }
              _sprintf(acStack_30,"%sC1_SAT",*piVar6);
              compareResult = _strcmp(param_2,acStack_30);
              if (compareResult == 0) {
                return 0x12;
              }
            }
            length = _strlen(param_2);
            length2 = _strlen(*piVar6);
            if (length == length2 + 1) {
              _sprintf(acStack_30,"%sR",*piVar6);
              compareResult = _strcmp(param_2,acStack_30);
              if (compareResult == 0) {
                return 0x12;
              }
              _sprintf(acStack_30,"%sH",*piVar6);
              compareResult = _strcmp(param_2,acStack_30);
              if (compareResult == 0) {
                return 0x12;
              }
              iVar2 = *piVar6;
              pcVar5 = "%sX";
            }
            else {
              length = _strlen(param_2);
              length2 = _strlen(*piVar6);
              if (length == length2 + 2) {
                _sprintf(acStack_30,"%sRC",*piVar6);
                compareResult = _strcmp(param_2,acStack_30);
                if (compareResult == 0) {
                  return 0x12;
                }
                _sprintf(acStack_30,"%sHC",*piVar6);
                compareResult = _strcmp(param_2,acStack_30);
                if (compareResult == 0) {
                  return 0x12;
                }
                iVar2 = *piVar6;
                pcVar5 = "%sXC";
              }
              else {
                length = _strlen(param_2);
                length2 = _strlen(*piVar6);
                if (length == length2 + 5) {
                  _sprintf(acStack_30,"%sR_SAT",*piVar6);
                  compareResult = _strcmp(param_2,acStack_30);
                  if (compareResult == 0) {
                    return 0x12;
                  }
                  _sprintf(acStack_30,"%sH_SAT",*piVar6);
                  compareResult = _strcmp(param_2,acStack_30);
                  if (compareResult == 0) {
                    return 0x12;
                  }
                  iVar2 = *piVar6;
                  pcVar5 = "%sX_SAT";
                }
                else {
                  length = _strlen(param_2);
                  length2 = _strlen(*piVar6);
                  if (length != length2 + 6) goto LAB_97b7e970;
                  _sprintf(acStack_30,"%sRC_SAT",*piVar6);
                  compareResult = _strcmp(param_2,acStack_30);
                  if (compareResult == 0) {
                    return 0x12;
                  }
                  _sprintf(acStack_30,"%sHC_SAT",*piVar6);
                  compareResult = _strcmp(param_2,acStack_30);
                  if (compareResult == 0) {
                    return 0x12;
                  }
                  iVar2 = *piVar6;
                  pcVar5 = "%sXC_SAT";
                }
              }
            }
            _sprintf(acStack_30,pcVar5,iVar2);
            compareResult = _strcmp(param_2,acStack_30);
            if (compareResult == 0) {
              return 0x12;
            }
          }
        }
LAB_97b7e970:
        piVar6 = piVar6 + 2;
        iVar2 = *piVar6;
      } while (iVar2 != 0);
      uVar3 = *(uint *)(parser + 0x48c);
    }
    if (uVar3 == 0x34) {
      if (loopIndex == 0) {
LAB_97b7e9b4:
        piVar6 = (int *)&_OpsList_NVvp20;
      }
      else {
        if (loopIndex != 1) {
          return 0;
        }
        piVar6 = &_OpsList_NVvp30;
      }
    }
    else {
      if (uVar3 == 0x31) {
        if (loopIndex != 0) {
          return 0;
        }
        goto LAB_97b7e9b4;
      }
      if (uVar3 == 0x33) {
        if (loopIndex != 0) {
          return 0;
        }
      }
      else {
        if (uVar3 != 0x36) {
          return 0;
        }
        if (loopIndex != 0) {
          if (loopIndex != 1) {
            return 0;
          }
          piVar6 = (int *)&_OpsList_NVfp20;
          goto LAB_97b7ea00;
        }
      }
      piVar6 = (int *)&_OpsList_NVfp10;
    }
LAB_97b7ea00:
    loopIndex = loopIndex + 1;
  } while( true );
}

/* _PPParserIdentifierCreate @ 0x97b7ea20 (48 bytes) */
int _PPParserIdentifierCreate()
{
  int allocation;
  
  allocation = _calloc(0x24,1);
  *(undefined4 *)(allocation + 4) = 1;
  return allocation;
}

/* _PPParserIdentifierSetName @ 0x97b7ea50 (124 bytes) */
int _PPParserIdentifierSetName(parser, param_2)
  int *parser;
  int param_2;
{
  int length;
  int allocation;
  
  if (*parser != 0) {
    _free(*parser);
    *parser = 0;
  }
  if (param_2 != 0) {
    length = _strlen(param_2);
    allocation = _calloc(length + 1,1);
    *parser = allocation;
    _memmove(allocation,param_2,length);
  }
  return param_2 == 0;
}

/* _PPParserScopeAddIdentifier @ 0x97b7eacc (124 bytes) */
int _PPParserScopeAddIdentifier(parser, param_2)
  int *parser;
  undefined4 *param_2;
{
  undefined4 *puVar1;
  int ppParserScopeFindIdentifierResult;
  undefined4 uVar3;
  
  ppParserScopeFindIdentifierResult = ((int (*)())_PPParserScopeFindIdentifier)(parser,*param_2);
  uVar3 = 1;
  if (ppParserScopeFindIdentifierResult == 0) {
    puVar1 = (undefined4 *)*parser;
    if ((undefined4 *)*parser == (undefined4 *)0x0) {
      puVar1 = param_2;
    }
    *parser = (int)puVar1;
    if (parser[1] != 0) {
      *(undefined4 **)(parser[1] + 0x20) = param_2;
      param_2[7] = parser[1];
    }
    uVar3 = 0;
    parser[1] = (int)param_2;
    param_2[6] = parser[6];
  }
  return uVar3;
}

/* _PPParserScopeFindIdentifier @ 0x97b7eb48 (100 bytes) */
int _PPParserScopeFindIdentifier(parser, param_2)
  int *parser;
  undefined4 param_2;
{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)*parser;
  while( true ) {
    if (piVar2 == (int *)0x0) {
      return (int *)0x0;
    }
    if ((*piVar2 != 0) && (iVar1 = _strcmp(*piVar2,param_2), iVar1 == 0)) break;
    piVar2 = (int *)piVar2[8];
  }
  return piVar2;
}

/* _PPParserParseParamBinding @ 0x97b7ebac (5900 bytes) */
int _PPParserParseParamBinding(parser, isBraceList, bindingCountOut)
  int parser;
  int isBraceList;
  int *bindingCountOut;
{
  int arrayResult;
  int part;
  int compareResult2;
  int scalars;
  int compareResult;
  bool bVar1;
  bool bVar2;
  uint programTypeOrIndex;
  char savedChar;
  int parseResultOrBindingClass;
  undefined4 ppStream;
  int part2;
  undefined4 *constantValues;
  int loopIndex;
  char partText [256];
  undefined4 bindingWord;
  undefined4 bindingOrdinalWord;
  undefined4 local_78;
  undefined4 local_74;
  uint local_70;
  undefined2 local_6c;
  short sStack_6a;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 arrayStart;
  uint arrayEnd [4];
  
  bVar1 = isBraceList == 0;
  programTypeOrIndex = *(uint *)(parser + 0x48c);
  loopIndex = 0;
  if (!bVar1) {
    part = ((int (*)())_PPParserGetPart)(parser,partText,0);
    if (part == 0) {
      return 0x2d;
    }
    if (partText[0] != '{') {
      return 10;
    }
  }
  bVar2 = ((programTypeOrIndex ^ 2) >> 1 & 1) == 0;
  local_6c = 0;
  local_70 = (uint)*(ushort *)(parser + 0x22);
  do {
    part = ((int (*)())_PPParserGetPart)(parser,partText,1);
    if (part == 0) {
      return 0x2d;
    }
    local_74 = 0;
    bindingOrdinalWord = (uint)*(ushort *)(parser + 0x22);
    bindingWord = 0;
    local_78 = 0;
    compareResult = _memcmp(partText,"program",8);
    if (compareResult == 0) {
      part = ((int (*)())_PPParserGetPart)(parser,partText,0);
      if (part == 0) {
        return 0x2d;
      }
      if (partText[0] != '.') {
        return 10;
      }
      if (part != 1) {
        return 10;
      }
      part = ((int (*)())_PPParserGetPart)(parser,partText,0);
      if (part == 0) {
        return 0x2d;
      }
      compareResult = _memcmp(partText,"env",4);
      if (compareResult == 0) {
        bindingWord = bindingWord & 0xffe0ffff | 0x20000;
        if (bVar1) {
          parseResultOrBindingClass = ((int (*)())_PPParserParseArray)(parser,&arrayStart);
          arrayEnd[0] = arrayStart;
        }
        else {
          parseResultOrBindingClass = _PPParserParseRangeArray(parser,&arrayStart,arrayEnd);
        }
        if (parseResultOrBindingClass != 0) {
          return parseResultOrBindingClass;
        }
        programTypeOrIndex = arrayStart;
        while( true ) {
          if (*(uint *)(parser + 0x450) <= programTypeOrIndex) {
            return 0x2e;
          }
          bindingWord = CONCAT22((*(unsigned short *)((unsigned char *)&(bindingWord) + 0)),(short)programTypeOrIndex);
          ((int (*)())_PPStreamAddParamBinding)(*(undefined4 *)(parser + 0x1c),&bindingWord);
          if (programTypeOrIndex == arrayEnd[0]) break;
          loopIndex = loopIndex + 1;
          programTypeOrIndex = programTypeOrIndex + 1;
          parseResultOrBindingClass = *(int *)(parser + 0x20) + 1;
          bindingOrdinalWord = CONCAT22((*(unsigned short *)((unsigned char *)&(bindingOrdinalWord) + 0)),(short)parseResultOrBindingClass);
          *(int *)(parser + 0x20) = parseResultOrBindingClass;
        }
      }
      else {
        compareResult = _memcmp(partText,"local",6);
        if (compareResult == 0) {
          bindingWord = bindingWord & 0xffe0ffff | 0x10000;
          if (bVar1) {
            parseResultOrBindingClass = ((int (*)())_PPParserParseArray)(parser,&arrayStart);
            arrayEnd[0] = arrayStart;
          }
          else {
            parseResultOrBindingClass = _PPParserParseRangeArray(parser,&arrayStart,arrayEnd);
          }
          if (parseResultOrBindingClass != 0) {
            return parseResultOrBindingClass;
          }
          programTypeOrIndex = arrayStart;
          while( true ) {
            if (*(uint *)(parser + 0x454) <= programTypeOrIndex) {
              return 0x2f;
            }
            bindingWord = CONCAT22((*(unsigned short *)((unsigned char *)&(bindingWord) + 0)),(short)programTypeOrIndex);
            ((int (*)())_PPStreamAddParamBinding)(*(undefined4 *)(parser + 0x1c),&bindingWord);
            if (programTypeOrIndex == arrayEnd[0]) break;
            loopIndex = loopIndex + 1;
            programTypeOrIndex = programTypeOrIndex + 1;
            parseResultOrBindingClass = *(int *)(parser + 0x20) + 1;
            bindingOrdinalWord = CONCAT22((*(unsigned short *)((unsigned char *)&(bindingOrdinalWord) + 0)),(short)parseResultOrBindingClass);
            *(int *)(parser + 0x20) = parseResultOrBindingClass;
          }
        }
      }
    }
    else {
      compareResult = _memcmp(partText,"state",6);
      if (compareResult == 0) {
        part = ((int (*)())_PPParserGetPart)(parser,partText,0);
        if (part == 0) {
          return 0x2d;
        }
        if (partText[0] != '.') {
          return 10;
        }
        if (part != 1) {
          return 10;
        }
        part = ((int (*)())_PPParserGetPart)(parser,partText,0);
        if (part == 0) {
          return 0x2d;
        }
        compareResult = _memcmp(partText,"material",9);
        if (compareResult == 0) {
          bindingWord = bindingWord & 0xffe0fffe | 0x50000;
          part = ((int (*)())_PPParserGetPart)(parser,partText,0);
          if (part == 0) {
            return 0x2d;
          }
          if (partText[0] != '.') {
            return 10;
          }
          if (part != 1) {
            return 10;
          }
          part = ((int (*)())_PPParserGetPart)(parser,partText,0);
          if (part == 0) {
            return 0x2d;
          }
          compareResult = _memcmp(partText,"front",6);
          if (compareResult == 0) {
LAB_97b7ef9c:
            part = ((int (*)())_PPParserGetPart)(parser,partText,0);
            if (part == 0) {
              return 0x2d;
            }
            if ((partText[0] != '.') || (part != 1)) {
              return 10;
            }
            part = ((int (*)())_PPParserGetPart)(parser,partText,0);
            if (part == 0) {
              return 0x2d;
            }
          }
          else {
            compareResult = _memcmp(partText,"back",5);
            if (compareResult == 0) {
              bindingWord = bindingWord | 1;
              goto LAB_97b7ef9c;
            }
          }
          compareResult = _memcmp(partText,"ambient",8);
          if (compareResult == 0) {
            bindingWord = bindingWord & 0xfffffff1;
          }
          else {
            compareResult = _memcmp(partText,"diffuse",8);
            if (compareResult == 0) {
              parseResultOrBindingClass = 1;
LAB_97b7f0a8:
              bindingWord = parseResultOrBindingClass << 1 | bindingWord & 0xfffffff1;
            }
            else {
              compareResult = _memcmp(partText,"specular",9);
              if (compareResult == 0) {
                bindingWord = bindingWord & 0xfffffff1 | 4;
              }
              else {
                compareResult = _memcmp(partText,"emission",9);
                if (compareResult != 0) {
                  compareResult = _memcmp(partText,"shininess",10);
                  if (compareResult != 0) {
                    return 10;
                  }
                  parseResultOrBindingClass = 4;
                  goto LAB_97b7f0a8;
                }
                bindingWord = bindingWord & 0xfffffff1 | 6;
              }
            }
          }
        }
        else {
          compareResult = _memcmp(partText,"normalscale",0xc);
          if (compareResult == 0) {
            ppStream = *(undefined4 *)(parser + 0x1c);
            parseResultOrBindingClass = 0x12;
LAB_97b7fbb8:
            bindingWord = parseResultOrBindingClass << 0x10 | bindingWord & 0xffe0ffff;
            goto LAB_97b801d0;
          }
          compareResult = _memcmp(partText,"light",6);
          if (compareResult == 0) {
            bindingWord = bindingWord & 0xffe0ffff | 0x30000;
            arrayResult = ((int (*)())_PPParserParseArray)(parser,&arrayStart);
            if (arrayResult != 0) {
              return arrayResult;
            }
            if (*(uint *)(parser + 0x484) <= arrayStart) {
              return 0x3c;
            }
            bindingWord = CONCAT31((*(unsigned int *)((unsigned char *)&(bindingWord) + 0)),(undefined1)arrayStart);
            part = ((int (*)())_PPParserGetPart)(parser,partText,0);
            if (part == 0) {
              return 0x2d;
            }
            if (partText[0] != '.') {
              return 10;
            }
            if (part != 1) {
              return 10;
            }
            part = ((int (*)())_PPParserGetPart)(parser,partText,0);
            if (part == 0) {
              return 0x2d;
            }
            compareResult = _memcmp(partText,"ambient",8);
            if (compareResult == 0) {
              bindingWord = bindingWord & 0xfffff0ff;
            }
            else {
              compareResult = _memcmp(partText,"diffuse",8);
              if (compareResult == 0) {
                bindingWord = bindingWord & 0xfffff0ff | 0x100;
              }
              else {
                compareResult = _memcmp(partText,"specular",9);
                if (compareResult == 0) {
                  bindingWord = bindingWord & 0xfffff0ff | 0x200;
                }
                else {
                  compareResult = _memcmp(partText,"position",9);
                  if (compareResult == 0) {
                    bindingWord = bindingWord & 0xfffff0ff | 0x300;
                  }
                  else {
                    compareResult = _memcmp(partText,"attenuation",0xc);
                    if (compareResult == 0) {
                      bindingWord = bindingWord & 0xfffff0ff | 0x500;
                    }
                    else {
                      compareResult = _memcmp(partText,"spot",5);
                      if (compareResult == 0) {
                        part = ((int (*)())_PPParserGetPart)(parser,partText,0);
                        if (part == 0) {
                          return 0x2d;
                        }
                        if (partText[0] != '.') {
                          return 10;
                        }
                        if (part != 1) {
                          return 10;
                        }
                        part = ((int (*)())_PPParserGetPart)(parser,partText,0);
                        if (part == 0) {
                          return 0x2d;
                        }
                        compareResult = _memcmp(partText,"direction",10);
                        if (compareResult != 0) {
                          return 10;
                        }
                        parseResultOrBindingClass = 4;
                      }
                      else {
                        compareResult = _memcmp(partText,"half",5);
                        if (compareResult == 0) {
                          parseResultOrBindingClass = 6;
                        }
                        else {
                          compareResult = _memcmp(partText,"spotcutoff",0xb);
                          if (compareResult != 0) {
                            return 10;
                          }
                          parseResultOrBindingClass = 7;
                        }
                      }
                      bindingWord = parseResultOrBindingClass << 8 | bindingWord & 0xfffff0ff;
                    }
                  }
                }
              }
            }
          }
          else {
            compareResult = _memcmp(partText,"lightmodel",0xb);
            if (compareResult == 0) {
              part = ((int (*)())_PPParserGetPart)(parser,partText,0);
              if (part == 0) {
                return 0x2d;
              }
              if (partText[0] != '.') {
                return 10;
              }
              if (part != 1) {
                return 10;
              }
              part = ((int (*)())_PPParserGetPart)(parser,partText,0);
              if (part == 0) {
                return 0x2d;
              }
              compareResult = _memcmp(partText,"ambient",8);
              if (compareResult != 0) {
                compareResult = _memcmp(partText,"front",6);
                if (compareResult == 0) {
                  bindingWord = bindingWord & 0xfffffffe;
LAB_97b7f420:
                  part = ((int (*)())_PPParserGetPart)(parser,partText,0);
                  if (part == 0) {
                    return 0x2d;
                  }
                  if (partText[0] != '.') {
                    return 10;
                  }
                  if (part != 1) {
                    return 10;
                  }
                  part = ((int (*)())_PPParserGetPart)(parser,partText,0);
                  if (part == 0) {
                    return 0x2d;
                  }
                }
                else {
                  compareResult = _memcmp(partText,"back",5);
                  if (compareResult == 0) {
                    bindingWord = bindingWord | 1;
                    goto LAB_97b7f420;
                  }
                }
                compareResult = _memcmp(partText,"scenecolor",0xb);
                if (compareResult != 0) {
                  return 10;
                }
                bindingWord = bindingWord & 0xffe0fff1 | 0x5000a;
                goto LAB_97b7fa44;
              }
              parseResultOrBindingClass = 6;
              goto LAB_97b7fa3c;
            }
            compareResult = _memcmp(partText,"lightprod",10);
            if (compareResult == 0) {
              bindingWord = bindingWord & 0xffe0feff | 0x40000;
              arrayResult = ((int (*)())_PPParserParseArray)(parser,&arrayStart);
              if (arrayResult != 0) {
                return arrayResult;
              }
              bindingWord = CONCAT31((*(unsigned int *)((unsigned char *)&(bindingWord) + 0)),(undefined1)arrayStart);
              part = ((int (*)())_PPParserGetPart)(parser,partText,0);
              if (part == 0) {
                return 0x2d;
              }
              if (partText[0] != '.') {
                return 10;
              }
              if (part != 1) {
                return 10;
              }
              part = ((int (*)())_PPParserGetPart)(parser,partText,0);
              if (part == 0) {
                return 0x2d;
              }
              compareResult = _memcmp(partText,"front",6);
              if (compareResult == 0) {
LAB_97b7f59c:
                part = ((int (*)())_PPParserGetPart)(parser,partText,0);
                if (part == 0) {
                  return 0x2d;
                }
                if (partText[0] != '.') {
                  return 10;
                }
                if (part != 1) {
                  return 10;
                }
                part = ((int (*)())_PPParserGetPart)(parser,partText,0);
                if (part == 0) {
                  return 0x2d;
                }
              }
              else {
                compareResult = _memcmp(partText,"back",5);
                if (compareResult == 0) {
                  bindingWord = bindingWord | 0x100;
                  goto LAB_97b7f59c;
                }
              }
              compareResult = _memcmp(partText,"ambient",8);
              if (compareResult == 0) {
                bindingWord = bindingWord & 0xfffff9ff;
              }
              else {
                compareResult = _memcmp(partText,"diffuse",8);
                if (compareResult == 0) {
                  bindingWord = bindingWord & 0xfffff9ff | 0x200;
                }
                else {
                  compareResult = _memcmp(partText,"specular",9);
                  if (compareResult != 0) {
                    return 10;
                  }
                  bindingWord = bindingWord & 0xfffff9ff | 0x400;
                }
              }
              goto LAB_97b7fa44;
            }
            if (bVar2) {
              compareResult = _memcmp(partText,"texenv",7);
              if (compareResult != 0) goto LAB_97b7f980;
              bindingWord = bindingWord & 0xffe0ffe0 | 0x90000;
              part = ((int (*)())_PPParserGetPart)(parser,partText,0);
              if (part == 0) {
                return 0x2d;
              }
              if (partText[0] == '[') {
                ((int (*)())_PPParserReturnPart)(parser);
                arrayResult = ((int (*)())_PPParserParseArray)(parser,&arrayStart);
                if (arrayResult != 0) {
                  return arrayResult;
                }
                bindingWord = arrayStart & 0x1f | bindingWord & 0xffffffe0;
                part = ((int (*)())_PPParserGetPart)(parser,partText,0);
                if (part == 0) {
                  return 0x2d;
                }
              }
              if (partText[0] != '.') {
                return 10;
              }
              if (part != 1) {
                return 10;
              }
              part = ((int (*)())_PPParserGetPart)(parser,partText,0);
              if (part == 0) {
                return 0x2d;
              }
              compareResult = _memcmp(partText,"color",6);
LAB_97b7fae0:
              if (compareResult != 0) {
                return 10;
              }
            }
            else {
              compareResult = _memcmp(partText,"texgen",7);
              if (compareResult == 0) {
                part = ((int (*)())_PPParserGetPart)(parser,partText,0);
                if (part == 0) {
                  return 0x2d;
                }
                if (partText[0] == '[') {
                  ((int (*)())_PPParserReturnPart)(parser);
                  arrayResult = ((int (*)())_PPParserParseArray)(parser,&arrayStart);
                  if (arrayResult != 0) {
                    return arrayResult;
                  }
                  if (*(uint *)(parser + 0x470) <= arrayStart) {
                    return 0x38;
                  }
                  bindingWord = arrayStart & 0x1f | bindingWord & 0xffffffe0;
                  part = ((int (*)())_PPParserGetPart)(parser,partText,0);
                  if (part == 0) {
                    return 0x2d;
                  }
                }
                else {
                  bindingWord = bindingWord & 0xffffffe0;
                }
                if (partText[0] != '.') {
                  return 10;
                }
                if (part != 1) {
                  return 10;
                }
                part = ((int (*)())_PPParserGetPart)(parser,partText,0);
                if (part == 0) {
                  return 0x2d;
                }
                compareResult = _memcmp(partText,"eye",4);
                if (compareResult == 0) {
                  parseResultOrBindingClass = 7;
                }
                else {
                  compareResult = _memcmp(partText,"object",7);
                  if (compareResult != 0) {
                    return 10;
                  }
                  parseResultOrBindingClass = 8;
                }
                bindingWord = parseResultOrBindingClass << 0x10 | bindingWord & 0xffe0ffff;
                part = ((int (*)())_PPParserGetPart)(parser,partText,0);
                if (part == 0) {
                  return 0x2d;
                }
                if (partText[0] != '.') {
                  return 10;
                }
                if (part != 1) {
                  return 10;
                }
                part = ((int (*)())_PPParserGetPart)(parser,partText,0);
                if (part == 0) {
                  return 0x2d;
                }
                compareResult = _memcmp(partText,"s",2);
                if (compareResult == 0) {
                  bindingWord = bindingWord & 0xffffff1f;
                }
                else {
                  compareResult = _memcmp(partText,"t",2);
                  if (compareResult == 0) {
                    bindingWord = bindingWord & 0xffffff1f | 0x20;
                  }
                  else {
                    compareResult = _memcmp(partText,"r",2);
                    if (compareResult == 0) {
                      bindingWord = bindingWord & 0xffffff1f | 0x40;
                    }
                    else {
                      compareResult = _memcmp(partText,"q",2);
                      if (compareResult != 0) {
                        return 0x11;
                      }
                      bindingWord = bindingWord & 0xffffff1f | 0x60;
                    }
                  }
                }
                goto LAB_97b7fa44;
              }
LAB_97b7f980:
              compareResult = _memcmp(partText,"fog",4);
              if (compareResult == 0) {
                part = ((int (*)())_PPParserGetPart)(parser,partText,0);
                if (part == 0) {
                  return 0x2d;
                }
                if (partText[0] != '.') {
                  return 10;
                }
                if (part != 1) {
                  return 10;
                }
                part = ((int (*)())_PPParserGetPart)(parser,partText,0);
                if (part == 0) {
                  return 0x2d;
                }
                compareResult = _memcmp(partText,"color",6);
                if (compareResult == 0) {
                  parseResultOrBindingClass = 0xb;
                }
                else {
                  compareResult = _memcmp(partText,"params",7);
                  if (compareResult != 0) {
                    return 10;
                  }
                  parseResultOrBindingClass = 0xc;
                }
              }
              else {
                if (bVar2) {
                  compareResult = _memcmp(partText,"depth",6);
                  if (compareResult != 0) {
LAB_97b7fc90:
                    compareResult = _memcmp(partText,"matrix",7);
                    if (compareResult != 0) {
                      return 10;
                    }
                    bindingWord = bindingWord & 0xffe03fff | 0x100000;
                    part = ((int (*)())_PPParserGetPart)(parser,partText,0);
                    if (part == 0) {
                      return 0x2d;
                    }
                    if (partText[0] != '.') {
                      return 10;
                    }
                    if (part != 1) {
                      return 10;
                    }
                    part = ((int (*)())_PPParserGetPart)(parser,partText,0);
                    if (part == 0) {
                      return 0x2d;
                    }
                    compareResult = _memcmp(partText,"modelview",10);
                    if (compareResult == 0) {
                      bindingWord = bindingWord & 0xfffff8ff | 0x300;
                      part = ((int (*)())_PPParserGetPart)(parser,partText,0);
                      if (part == 0) {
                        return 0x2d;
                      }
                      ((int (*)())_PPParserReturnPart)(parser);
                      if (partText[0] == '[') {
LAB_97b7fe54:
                        arrayResult = ((int (*)())_PPParserParseArray)(parser,&arrayStart);
                        if (arrayResult != 0) {
                          return arrayResult;
                        }
LAB_97b7fec8:
                        bindingWord = CONCAT31((*(unsigned int *)((unsigned char *)&(bindingWord) + 0)),(undefined1)arrayStart);
                      }
                      else {
                        bindingWord = bindingWord & 0xffffff00;
                      }
                    }
                    else {
                      compareResult = _memcmp(partText,"projection",0xb);
                      if (compareResult == 0) {
                        bindingWord = bindingWord & 0xfffff8ff | 0x100;
                      }
                      else {
                        compareResult = _memcmp(partText,"mvp",4);
                        if (compareResult == 0) {
                          bindingWord = bindingWord & 0xfffff8ff;
                        }
                        else {
                          compareResult = _memcmp(partText,"color",6);
                          if (compareResult == 0) {
                            bindingWord = bindingWord & 0xfffff8ff | 0x200;
                          }
                          else {
                            compareResult = _memcmp(partText,"texture",8);
                            if (compareResult != 0) {
                              compareResult = _memcmp(partText,"program",8);
                              if (compareResult != 0) {
                                return 10;
                              }
                              bindingWord = bindingWord & 0xfffff8ff | 0x500;
                              arrayResult = ((int (*)())_PPParserParseArray)(parser,&arrayStart);
                              if (arrayResult != 0) {
                                return arrayResult;
                              }
                              if (*(uint *)(parser + 0x458) <= arrayStart) {
                                return 0x30;
                              }
                              goto LAB_97b7fec8;
                            }
                            bindingWord = bindingWord & 0xfffff8ff | 0x400;
                            part = ((int (*)())_PPParserGetPart)(parser,partText,0);
                            if (part == 0) {
                              return 0x2d;
                            }
                            ((int (*)())_PPParserReturnPart)(parser);
                            if (partText[0] == '[') goto LAB_97b7fe54;
                            bindingWord = bindingWord & 0xffffff00;
                          }
                        }
                      }
                    }
                    part = ((int (*)())_PPParserGetPart)(parser,partText,0);
                    savedChar = partText[0];
                    if (part == 0) {
                      return 0x2d;
                    }
                    partText[0] = savedChar;
                    if ((partText[0] == '.') && (part == 1)) {
                      part2 = ((int (*)())_PPParserGetPart)(parser,partText,0);
                      if (part2 == 0) {
                        return 0x2d;
                      }
                      compareResult2 = _memcmp(partText,"inverse",8);
                      if (compareResult2 == 0) {
                        bindingWord = bindingWord & 0xffff3fff | 0x8000;
                      }
                      else {
                        compareResult2 = _memcmp(partText,"transpose",10);
                        if (compareResult2 == 0) {
                          bindingWord = bindingWord & 0xffff3fff | 0x4000;
                        }
                        else {
                          compareResult2 = _memcmp(partText,"invtrans",9);
                          if (compareResult2 != 0) {
                            ((int (*)())_PPParserReturnPart)(parser);
                            partText[1] = 0;
                            partText[0] = savedChar;
                            savedChar = '.';
                            goto LAB_97b7ffd8;
                          }
                          bindingWord = bindingWord & 0xffff3fff | 0xc000;
                        }
                      }
                      part = ((int (*)())_PPParserGetPart)(parser,partText,0);
                      savedChar = partText[0];
                      if (part == 0) {
                        return 0x2d;
                      }
                    }
LAB_97b7ffd8:
                    arrayStart = 0;
                    arrayEnd[0] = 3;
                    if ((savedChar == '.') && (part == 1)) {
                      part = ((int (*)())_PPParserGetPart)(parser,partText,0);
                      if (part == 0) {
                        return 0x2d;
                      }
                      compareResult = _memcmp(partText,"row",4);
                      if (compareResult != 0) {
                        return 10;
                      }
                      if (bVar1) {
                        parseResultOrBindingClass = ((int (*)())_PPParserParseArray)(parser,&arrayStart);
                        arrayEnd[0] = arrayStart;
                      }
                      else {
                        parseResultOrBindingClass = _PPParserParseRangeArray(parser,&arrayStart,arrayEnd);
                      }
                      if (parseResultOrBindingClass != 0) {
                        return parseResultOrBindingClass;
                      }
                    }
                    else {
                      if (bVar1) {
                        return 10;
                      }
                      ((int (*)())_PPParserReturnPart)(parser);
                    }
                    if (3 < (int)arrayStart) {
                      return 10;
                    }
                    if (3 < (int)arrayEnd[0]) {
                      return 10;
                    }
                    programTypeOrIndex = arrayStart;
                    while( true ) {
                      bindingWord = (programTypeOrIndex & 3) << 0xc | bindingWord & 0xffffcfff;
                      ((int (*)())_PPStreamAddParamBinding)(*(undefined4 *)(parser + 0x1c),&bindingWord);
                      if (programTypeOrIndex == arrayEnd[0]) break;
                      loopIndex = loopIndex + 1;
                      programTypeOrIndex = programTypeOrIndex + 1;
                      parseResultOrBindingClass = *(int *)(parser + 0x20) + 1;
                      bindingOrdinalWord = CONCAT22((*(unsigned short *)((unsigned char *)&(bindingOrdinalWord) + 0)),(short)parseResultOrBindingClass);
                      *(int *)(parser + 0x20) = parseResultOrBindingClass;
                    }
                    goto LAB_97b801d4;
                  }
                  bindingWord = bindingWord & 0xffe0ffff | 0xf0000;
                  part = ((int (*)())_PPParserGetPart)(parser,partText,0);
                  if (part == 0) {
                    return 0x2d;
                  }
                  if (partText[0] != '.') {
                    return 10;
                  }
                  if (part != 1) {
                    return 10;
                  }
                  part = ((int (*)())_PPParserGetPart)(parser,partText,0);
                  if (part == 0) {
                    return 0x2d;
                  }
                  compareResult = _memcmp(partText,"range",6);
                  goto LAB_97b7fae0;
                }
                compareResult = _memcmp(partText,"clip",5);
                if (compareResult == 0) {
                  arrayResult = ((int (*)())_PPParserParseArray)(parser,&arrayStart);
                  if (arrayResult != 0) {
                    return arrayResult;
                  }
                  if (*(uint *)(parser + 0x480) <= arrayStart) {
                    return 0x3b;
                  }
                  bindingWord = CONCAT31((*(unsigned int *)((unsigned char *)&(bindingWord) + 0)),(undefined1)arrayStart);
                  part = ((int (*)())_PPParserGetPart)(parser,partText,0);
                  if (part == 0) {
                    return 0x2d;
                  }
                  if (partText[0] != '.') {
                    return 10;
                  }
                  if (part != 1) {
                    return 10;
                  }
                  part = ((int (*)())_PPParserGetPart)(parser,partText,0);
                  if (part == 0) {
                    return 0x2d;
                  }
                  compareResult = _memcmp(partText,"plane",6);
                  if (compareResult != 0) {
                    return 10;
                  }
                  ppStream = *(undefined4 *)(parser + 0x1c);
                  parseResultOrBindingClass = 10;
                  goto LAB_97b7fbb8;
                }
                compareResult = _memcmp(partText,"point",6);
                if (compareResult != 0) goto LAB_97b7fc90;
                part = ((int (*)())_PPParserGetPart)(parser,partText,0);
                if (part == 0) {
                  return 0x2d;
                }
                if (partText[0] != '.') {
                  return 10;
                }
                if (part != 1) {
                  return 10;
                }
                part = ((int (*)())_PPParserGetPart)(parser,partText,0);
                if (part == 0) {
                  return 0x2d;
                }
                compareResult = _memcmp(partText,"size",5);
                if (compareResult == 0) {
                  parseResultOrBindingClass = 0xd;
                }
                else {
                  compareResult = _memcmp(partText,"attenuation",0xc);
                  if (compareResult != 0) {
                    return 10;
                  }
                  parseResultOrBindingClass = 0xe;
                }
              }
LAB_97b7fa3c:
              bindingWord = parseResultOrBindingClass << 0x10 | bindingWord & 0xffe0ffff;
            }
          }
        }
LAB_97b7fa44:
        ppStream = *(undefined4 *)(parser + 0x1c);
      }
      else {
        if (partText[0] == '{') {
          bindingWord = 0x110000;
          local_60 = 0;
          local_54 = 0x3f800000;
          local_58 = 0;
          local_5c = 0;
          scalars = _PPParserGetScalars(parser,&local_60,4);
          if (scalars != 0) {
            return scalars;
          }
          part = ((int (*)())_PPParserGetPart)(parser,partText,0);
          if (part == 0) {
            return 0x2d;
          }
          if (partText[0] != '}') {
            return 10;
          }
          ppStream = *(undefined4 *)(parser + 0x1c);
          constantValues = &local_60;
        }
        else {
          ((int (*)())_PPParserReturnPart)(parser);
          constantValues = &local_50;
          bindingWord = bindingWord & 0xffe0ffff | 0x110000;
          scalars = _PPParserGetScalars(parser,constantValues,1);
          if (scalars != 0) {
            return 10;
          }
          ppStream = *(undefined4 *)(parser + 0x1c);
          local_44 = local_50;
          local_4c = local_50;
          local_48 = local_50;
        }
        _PPStreamAddConstant(ppStream,constantValues);
        ppStream = *(undefined4 *)(parser + 0x1c);
        bindingWord = CONCAT22((*(unsigned short *)((unsigned char *)&(bindingWord) + 0)),(short)*(int *)(parser + 0x2c));
        *(int *)(parser + 0x2c) = *(int *)(parser + 0x2c) + 1;
      }
LAB_97b801d0:
      ((int (*)())_PPStreamAddParamBinding)(ppStream,&bindingWord);
    }
LAB_97b801d4:
    loopIndex = loopIndex + 1;
    *(int *)(parser + 0x20) = *(int *)(parser + 0x20) + 1;
    if (bVar1) goto LAB_97b80220;
    part = ((int (*)())_PPParserGetPart)(parser,partText,0);
    if (part == 0) {
      return 0x2d;
    }
  } while (partText[0] == ',');
  parseResultOrBindingClass = 10;
  if (partText[0] == '}') {
LAB_97b80220:
    if (*bindingCountOut == 0) {
      *bindingCountOut = loopIndex;
    }
    else if (*bindingCountOut != loopIndex) {
      return 0x25;
    }
    programTypeOrIndex = *(uint *)(parser + 0x20);
    parseResultOrBindingClass = 0x34;
    if (programTypeOrIndex <= *(uint *)(parser + 0x464)) {
      local_6c = CONCAT22(local_6c,*(short *)(parser + 0x22) + -1);
      if (1 < loopIndex) {
        _PPStreamAddParamBindingArray(*(undefined4 *)(parser + 0x1c),&local_70);
        programTypeOrIndex = *(uint *)(parser + 0x20);
      }
      parseResultOrBindingClass = 0x34;
      if (programTypeOrIndex < 0x101) {
        parseResultOrBindingClass = 0;
      }
    }
  }
  return parseResultOrBindingClass;
}

/* _PPParserScopeFindMacro @ 0x97b802b8 (100 bytes) */
int _PPParserScopeFindMacro(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 8);
  while( true ) {
    if (piVar2 == (int *)0x0) {
      return (int *)0x0;
    }
    if ((*piVar2 != 0) && (iVar1 = _strcmp(*piVar2,param_2), iVar1 == 0)) break;
    piVar2 = (int *)piVar2[7];
  }
  return piVar2;
}

/* _PPParserParseArray @ 0x97b8031c (176 bytes) */
int _PPParserParseArray(parser, param_2)
  undefined4 parser;
  int *param_2;
{
  int part;
  int iVar2;
  char local_110 [260];
  
  part = ((int (*)())_PPParserGetPart)(parser,local_110,0);
  iVar2 = 0x2d;
  if ((((part != 0) && (iVar2 = 0xb, local_110[0] == '[')) &&
      (iVar2 = ((int (*)())_PPParserGetInteger)(parser,param_2), iVar2 == 0)) && (iVar2 = 0x23, -1 < *param_2))
  {
    part = ((int (*)())_PPParserGetPart)(parser,local_110,0);
    iVar2 = 0x2d;
    if ((part != 0) && (iVar2 = 0xb, local_110[0] == ']')) {
      iVar2 = 0;
    }
  }
  return iVar2;
}

/* _PPParserGetInteger @ 0x97b803cc (112 bytes) */
int _PPParserGetInteger(parser, param_2)
  undefined4 parser;
  long *param_2;
{
  int part;
  undefined4 uVar2;
  long strtolResult;
  char acStack_120 [256];
  char *local_20 [5];
  
  part = ((int (*)())_PPParserGetPart)(parser,acStack_120,1);
  uVar2 = 0x2d;
  if (part != 0) {
    strtolResult = _strtol(acStack_120,local_20,0);
    *param_2 = strtolResult;
    uVar2 = 0x15;
    if (local_20[0] == acStack_120 + part) {
      uVar2 = 0;
    }
  }
  return uVar2;
}

/* _PPStreamAddParamBinding @ 0x97b8043c (108 bytes) */
int _PPStreamAddParamBinding(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined1 *allocation;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  allocation = (undefined1 *)_calloc(0x1c,1);
  uVar3 = param_2[3];
  uVar2 = *(undefined4 *)(param_1 + 0x10);
  uVar4 = *param_2;
  uVar6 = param_2[1];
  uVar5 = param_2[2];
  *allocation = 3;
  *(undefined4 *)(allocation + 0xc) = uVar4;
  *(undefined4 *)(allocation + 0x10) = uVar6;
  *(undefined4 *)(allocation + 0x14) = uVar5;
  *(undefined4 *)(allocation + 0x18) = uVar3;
  return ((int (*)())_PPStreamChunkListAddChunk)(uVar2,allocation);
}

/* _PPParserParseAttributeDeclaration @ 0x97b804a8 (268 bytes) */
int _PPParserParseAttributeDeclaration(parser)
  int parser;
{
  int ppParserScopeAddIdentifierResult;
  int ppParserIdentifierCreateResult;
  int part;
  int ppParserValidateNameResult;
  int iVar2;
  int part2;
  char local_110 [256];
  
  part = ((int (*)())_PPParserGetPart)(parser,local_110,0);
  iVar2 = 0x2d;
  if (part != 0) {
    ppParserValidateNameResult = ((int (*)())_PPParserValidateName)(parser,local_110);
    iVar2 = 0x12;
    if (ppParserValidateNameResult == 0) {
      ppParserIdentifierCreateResult = ((int (*)())_PPParserIdentifierCreate)();
      ((int (*)())_PPParserIdentifierSetName)(ppParserIdentifierCreateResult,local_110);
      *(undefined4 *)(ppParserIdentifierCreateResult + 0xc) = 0;
      ppParserScopeAddIdentifierResult = ((int (*)())_PPParserScopeAddIdentifier)(*(undefined4 *)(parser + 0x44c),ppParserIdentifierCreateResult);
      if (ppParserScopeAddIdentifierResult == 0) {
        part2 = ((int (*)())_PPParserGetPart)(parser,local_110,0);
        iVar2 = 0x2d;
        if ((part2 != 0) && (iVar2 = 10, local_110[0] == '=')) {
          *(undefined4 *)(ppParserIdentifierCreateResult + 8) = *(undefined4 *)(parser + 0x24);
          iVar2 = ((int (*)())_PPParserParseAttributeBinding)(parser);
          if (iVar2 == 0) {
            part = ((int (*)())_PPParserGetPart)(parser,local_110,0);
            iVar2 = 0x2d;
            if ((part != 0) && (iVar2 = 10, local_110[0] == ';')) {
              iVar2 = 0;
            }
          }
        }
      }
      else {
        _PPParserIdentifierFree(ppParserIdentifierCreateResult);
        iVar2 = 0x1c;
      }
    }
  }
  return iVar2;
}

/* _PPParserParseAttributeBinding @ 0x97b805b4 (1684 bytes) */
int _PPParserParseAttributeBinding(parser)
  int parser;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int testAttribMatchResult;
  int iVar5;
  char local_140 [256];
  uint local_40;
  undefined2 local_3c;
  undefined2 uStack_3a;
  uint local_30 [7];
  
  uVar2 = *(uint *)(parser + 0x48c);
  iVar3 = ((int (*)())_PPParserGetPart)(parser,local_140,0);
  if (iVar3 == 0) {
    return 0x2d;
  }
  bVar1 = ((uVar2 ^ 2) >> 1 & 1) == 0;
  local_3c = 0;
  local_40 = 0;
  if (bVar1) {
    iVar3 = _memcmp(local_140,"fragment",9);
  }
  else {
    iVar3 = _memcmp(local_140,"vertex",7);
  }
  if (iVar3 != 0) {
    return 10;
  }
  iVar3 = ((int (*)())_PPParserGetPart)(parser,local_140,0);
  if (iVar3 == 0) {
    return 0x2d;
  }
  if (local_140[0] != '.') {
    return 10;
  }
  if (iVar3 != 1) {
    return 10;
  }
  iVar3 = ((int (*)())_PPParserGetPart)(parser,local_140,0);
  if (iVar3 == 0) {
    return 0x2d;
  }
  if ((!bVar1) && (iVar3 = _memcmp(local_140,"attrib",7), iVar3 == 0)) {
    local_40 = local_40 & 0xfff0ffff | 0x90000;
    iVar3 = ((int (*)())_PPParserParseArray)(parser,local_30);
    if (iVar3 != 0) {
      return iVar3;
    }
    iVar3 = 0x3d;
    uVar2 = *(uint *)(parser + 0x488);
    goto LAB_97b80948;
  }
  iVar3 = _memcmp(local_140,"position",9);
  if (iVar3 == 0) {
    iVar3 = 1;
  }
  else {
    if ((bVar1) || (iVar3 = _memcmp(local_140,"normal",7), iVar3 != 0)) {
      iVar3 = _memcmp(local_140,"color",6);
      if (iVar3 == 0) {
        local_40 = local_40 & 0xfff0ffff | 0x20000;
        iVar3 = ((int (*)())_PPParserGetPart)(parser,local_140,0);
        if (iVar3 == 0) {
          return 0x2d;
        }
        if ((local_140[0] == '.') && (iVar3 == 1)) {
          iVar3 = ((int (*)())_PPParserGetPart)(parser,local_140,0);
          if (iVar3 == 0) {
            return 0x2d;
          }
          iVar3 = _memcmp(local_140,"secondary",10);
          if (iVar3 == 0) {
            iVar3 = 3;
            goto LAB_97b80b98;
          }
          iVar3 = _memcmp(local_140,"primary",8);
          if (iVar3 == 0) goto LAB_97b80bac;
          ((int (*)())_PPParserReturnPart)(parser);
        }
        ((int (*)())_PPParserReturnPart)(parser);
        goto LAB_97b80bac;
      }
      iVar3 = _memcmp(local_140,"fogcoord",9);
      if (iVar3 == 0) {
        iVar3 = 5;
        goto LAB_97b80b98;
      }
      iVar3 = _memcmp(local_140,"texcoord",9);
      if (iVar3 == 0) {
        local_40 = local_40 & 0xfff0ffff | 0x70000;
        iVar3 = ((int (*)())_PPParserGetPart)(parser,local_140,0);
        if (iVar3 == 0) {
          return 0x2d;
        }
        ((int (*)())_PPParserReturnPart)(parser);
        if (local_140[0] != '[') {
LAB_97b8095c:
          local_40 = local_40 & 0xffffffe0;
          goto LAB_97b80bac;
        }
        iVar3 = ((int (*)())_PPParserParseArray)(parser,local_30);
        if (iVar3 != 0) {
          return iVar3;
        }
        iVar3 = 0x38;
        uVar2 = *(uint *)(parser + 0x470);
LAB_97b80948:
        if (uVar2 <= local_30[0]) {
          return iVar3;
        }
        local_40 = local_30[0] & 0x1f | local_40 & 0xffffffe0;
        goto LAB_97b80bac;
      }
      if (bVar1) {
        iVar3 = _memcmp(local_140,"facing",7);
        if (iVar3 != 0) {
          return 10;
        }
        if (*(int *)(parser + 0x48c) != 0x36) {
          return 10;
        }
        iVar3 = 0xb;
        goto LAB_97b80b98;
      }
      iVar3 = _memcmp(local_140,"weight",7);
      if (iVar3 == 0) {
        local_40 = local_40 & 0xfff0ffff | 0x60000;
        iVar3 = ((int (*)())_PPParserGetPart)(parser,local_140,0);
        if (iVar3 == 0) {
          return 0x2d;
        }
        ((int (*)())_PPParserReturnPart)(parser);
        if (local_140[0] != '[') goto LAB_97b8095c;
        iVar3 = ((int (*)())_PPParserParseArray)(parser,local_30);
        if (iVar3 != 0) {
          return iVar3;
        }
        iVar3 = 0x39;
        uVar2 = *(uint *)(parser + 0x478);
        goto LAB_97b80948;
      }
      iVar3 = _memcmp(local_140,"material",9);
      if (iVar3 != 0) {
        return 10;
      }
      local_40 = local_40 & 0xfff0fffe | 0xa0000;
      iVar3 = ((int (*)())_PPParserGetPart)(parser,local_140,0);
      if (iVar3 == 0) {
        return 0x2d;
      }
      if (local_140[0] != '.') {
        return 10;
      }
      if (iVar3 != 1) {
        return 10;
      }
      iVar3 = ((int (*)())_PPParserGetPart)(parser,local_140,0);
      if (iVar3 == 0) {
        return 0x2d;
      }
      iVar3 = _memcmp(local_140,"front",6);
      if (iVar3 == 0) {
LAB_97b80a4c:
        iVar3 = ((int (*)())_PPParserGetPart)(parser,local_140,0);
        if (iVar3 == 0) {
          return 0x2d;
        }
        if ((local_140[0] != '.') || (iVar3 != 1)) {
          return 10;
        }
        iVar3 = ((int (*)())_PPParserGetPart)(parser,local_140,0);
        if (iVar3 == 0) {
          return 0x2d;
        }
      }
      else {
        iVar3 = _memcmp(local_140,"back",5);
        if (iVar3 == 0) {
          local_40 = local_40 | 1;
          goto LAB_97b80a4c;
        }
      }
      iVar3 = _memcmp(local_140,"ambient",8);
      if (iVar3 == 0) {
        local_40 = local_40 & 0xffff0fff;
      }
      else {
        iVar3 = _memcmp(local_140,"diffuse",8);
        if (iVar3 == 0) {
          iVar3 = 1;
        }
        else {
          iVar3 = _memcmp(local_140,"specular",9);
          if (iVar3 == 0) {
            iVar3 = 2;
          }
          else {
            iVar3 = _memcmp(local_140,"emission",9);
            if (iVar3 == 0) {
              iVar3 = 3;
            }
            else {
              iVar3 = _memcmp(local_140,"shininess",10);
              if (iVar3 != 0) {
                return 10;
              }
              iVar3 = 4;
            }
          }
        }
        local_40 = iVar3 << 0xc | local_40 & 0xffff0fff;
      }
      goto LAB_97b80bac;
    }
    iVar3 = 4;
  }
LAB_97b80b98:
  local_40 = iVar3 << 0x10 | local_40 & 0xfff0ffff;
LAB_97b80bac:
  if (bVar1) {
    iVar3 = *(int *)(parser + 0x1c);
  }
  else {
    iVar3 = *(int *)(parser + 0x1c);
    iVar5 = **(int **)(iVar3 + 0x18);
    if (iVar5 != 0) {
      do {
        testAttribMatchResult = ((int (*)())_testAttribMatch)(&local_40,iVar5 + 0xc);
        if (testAttribMatchResult != 0) {
          return 0x13;
        }
        iVar5 = *(int *)(iVar5 + 8);
      } while (iVar5 != 0);
    }
  }
  local_3c = CONCAT22(local_3c,(short)*(int *)(parser + 0x24));
  *(int *)(parser + 0x24) = *(int *)(parser + 0x24) + 1;
  ((int (*)())_PPStreamAddAttribBinding)(iVar3,&local_40);
  iVar3 = 0x35;
  if (*(uint *)(parser + 0x24) < 0x101) {
    iVar3 = 0;
  }
  return iVar3;
}

/* _testAttribMatch @ 0x97b80c48 (300 bytes) */
int _testAttribMatch(param_1, param_2)
  uint *param_1;
  uint *param_2;
{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar2 = *param_1;
  if ((uVar2 >> 0x10 & 0xf) == 9) {
    param_1 = param_2;
    if ((*param_2 >> 0x10 & 0xf) == 9) {
      return 0;
    }
  }
  else {
    if ((*param_2 >> 0x10 & 0xf) != 9) {
      return 0;
    }
    uVar2 = *param_2;
  }
  switch(uVar2 & 0x1f) {
  case 0:
    bVar1 = (*param_1 >> 0x10 & 0xf) == 1;
    break;
  case 1:
    bVar1 = (*param_1 & 0xf001f) == 0x60000;
    break;
  case 2:
    bVar1 = (*param_1 >> 0x10 & 0xf) == 4;
    break;
  case 3:
    bVar1 = (*param_1 >> 0x10 & 0xf) == 2;
    break;
  case 4:
    bVar1 = (*param_1 >> 0x10 & 0xf) == 3;
    break;
  case 5:
    bVar1 = (*param_1 >> 0x10 & 0xf) == 5;
    break;
  case 6:
  case 7:
    goto switchD_97b80cc0_caseD_6;
  default:
    if ((*param_1 >> 0x10 & 0xf) == 7) {
      bVar1 = (*param_1 & 0x1f) == (uVar2 & 0x1f) - 8;
      break;
    }
    goto switchD_97b80cc0_caseD_6;
  }
  uVar3 = 1;
  if (!bVar1) {
switchD_97b80cc0_caseD_6:
    uVar3 = 0;
  }
  return uVar3;
}

/* _PPParserParseOutputDeclaration @ 0x97b80d94 (284 bytes) */
int _PPParserParseOutputDeclaration(parser, param_2)
  int parser;
  undefined4 param_2;
{
  int ppParserScopeAddIdentifierResult;
  int ppParserIdentifierCreateResult;
  int part;
  int ppParserValidateNameResult;
  int iVar2;
  int part2;
  char local_110 [256];
  
  part = ((int (*)())_PPParserGetPart)(parser,local_110,0);
  iVar2 = 0x2d;
  if (part != 0) {
    ppParserValidateNameResult = ((int (*)())_PPParserValidateName)(parser,local_110);
    iVar2 = 0x12;
    if (ppParserValidateNameResult == 0) {
      ppParserIdentifierCreateResult = ((int (*)())_PPParserIdentifierCreate)();
      ((int (*)())_PPParserIdentifierSetName)(ppParserIdentifierCreateResult,local_110);
      *(undefined4 *)(ppParserIdentifierCreateResult + 0xc) = 3;
      *(undefined4 *)(ppParserIdentifierCreateResult + 0x14) = param_2;
      ppParserScopeAddIdentifierResult = ((int (*)())_PPParserScopeAddIdentifier)(*(undefined4 *)(parser + 0x44c),ppParserIdentifierCreateResult);
      if (ppParserScopeAddIdentifierResult == 0) {
        part2 = ((int (*)())_PPParserGetPart)(parser,local_110,0);
        iVar2 = 0x2d;
        if ((part2 != 0) && (iVar2 = 10, local_110[0] == '=')) {
          *(undefined4 *)(ppParserIdentifierCreateResult + 8) = *(undefined4 *)(parser + 0x28);
          iVar2 = ((int (*)())_PPParserParseOutputBinding)(parser,param_2);
          if (iVar2 == 0) {
            part = ((int (*)())_PPParserGetPart)(parser,local_110,0);
            iVar2 = 0x2d;
            if ((part != 0) && (iVar2 = 10, local_110[0] == ';')) {
              iVar2 = 0;
            }
          }
        }
      }
      else {
        _PPParserIdentifierFree(ppParserIdentifierCreateResult);
        iVar2 = 0x1c;
      }
    }
  }
  return iVar2;
}

/* _PPParserParseOutputBinding @ 0x97b80eb0 (1212 bytes) */
int _PPParserParseOutputBinding(parser, param_2)
  int parser;
  int param_2;
{
  int compareResult;
  bool bVar1;
  uint uVar2;
  int iVar3;
  int part;
  char local_140;
  undefined1 local_13f;
  uint local_40;
  undefined2 local_3c;
  undefined2 uStack_3a;
  uint local_30 [7];
  
  uVar2 = *(uint *)(parser + 0x48c);
  iVar3 = ((int (*)())_PPParserGetPart)(parser,&local_140,0);
  if (iVar3 == 0) {
    return 0x2d;
  }
  local_40 = param_2 << 0x1d;
  local_3c = 0;
  iVar3 = _memcmp(&local_140,"result",7);
  if (iVar3 != 0) {
    return 10;
  }
  iVar3 = ((int (*)())_PPParserGetPart)(parser,&local_140,0);
  if (iVar3 == 0) {
    return 0x2d;
  }
  if ((local_140 != '.') || (iVar3 != 1)) {
    return 10;
  }
  iVar3 = ((int (*)())_PPParserGetPart)(parser,&local_140,0);
  if (iVar3 == 0) {
    return 0x2d;
  }
  bVar1 = ((uVar2 ^ 2) >> 1 & 1) == 0;
  if ((!bVar1) && (iVar3 = _memcmp(&local_140,"position",9), iVar3 == 0)) {
    if ((*(byte *)(parser + 0x442) & 1) != 0) {
      return 0x22;
    }
    local_40 = local_40 & 0xfff0ffff | 0x10000;
    goto LAB_97b81320;
  }
  iVar3 = _memcmp(&local_140,"color",6);
  if (iVar3 == 0) {
    local_40 = local_40 & 0xfff0fffe | 0x40000;
    if (bVar1) {
      if (*(char *)(parser + 0x445) != '\0') {
        iVar3 = ((int (*)())_PPParserGetPart)(parser,&local_140,0);
        if (iVar3 == 0) {
          return 0x2d;
        }
        ((int (*)())_PPParserReturnPart)(parser);
        if (local_140 == '[') {
          iVar3 = ((int (*)())_PPParserParseArray)(parser,local_30);
          if (iVar3 != 0) {
            return iVar3;
          }
          local_40 = (local_30[0] & 7) << 1 | local_40 & 0xfffffff1;
        }
        else {
          local_40 = local_40 & 0xfffffff1;
        }
      }
      goto LAB_97b81320;
    }
    iVar3 = ((int (*)())_PPParserGetPart)(parser,&local_140,0);
    if (iVar3 == 0) {
      return 0x2d;
    }
    if ((local_140 == '.') && (iVar3 == 1)) {
      part = ((int (*)())_PPParserGetPart)(parser,&local_140,0);
      if (part == 0) {
        return 0x2d;
      }
      compareResult = _memcmp(&local_140,"back",5);
      if (compareResult == 0) {
        local_40 = local_40 | 1;
      }
      else {
        compareResult = _memcmp(&local_140,"front",6);
        if (compareResult != 0) {
          ((int (*)())_PPParserReturnPart)(parser);
          local_13f = 0;
          local_140 = '.';
          goto LAB_97b810c0;
        }
      }
      iVar3 = ((int (*)())_PPParserGetPart)(parser,&local_140,0);
      if (iVar3 == 0) {
        return 0x2d;
      }
    }
LAB_97b810c0:
    if ((local_140 == '.') && (iVar3 == 1)) {
      iVar3 = ((int (*)())_PPParserGetPart)(parser,&local_140,0);
      if (iVar3 == 0) {
        return 0x2d;
      }
      iVar3 = _memcmp(&local_140,"secondary",10);
      if (iVar3 == 0) {
        iVar3 = 5;
        goto LAB_97b8130c;
      }
      iVar3 = _memcmp(&local_140,"primary",8);
      if (iVar3 == 0) goto LAB_97b81320;
      ((int (*)())_PPParserReturnPart)(parser);
    }
    ((int (*)())_PPParserReturnPart)(parser);
  }
  else {
    if (bVar1) {
      iVar3 = _memcmp(&local_140,"depth",6);
      if (iVar3 != 0) {
        return 10;
      }
      iVar3 = 7;
    }
    else {
      iVar3 = _memcmp(&local_140,"fogcoord",9);
      if (iVar3 == 0) {
        iVar3 = 2;
      }
      else {
        iVar3 = _memcmp(&local_140,"pointsize",10);
        if (iVar3 == 0) {
          iVar3 = 3;
        }
        else {
          iVar3 = _memcmp(&local_140,"texcoord",9);
          if (iVar3 == 0) {
            local_40 = local_40 & 0xfff0ffff | 0x60000;
            iVar3 = ((int (*)())_PPParserGetPart)(parser,&local_140,0);
            if (iVar3 == 0) {
              return 0x2d;
            }
            ((int (*)())_PPParserReturnPart)(parser);
            if (local_140 == '[') {
              iVar3 = ((int (*)())_PPParserParseArray)(parser,local_30);
              if (iVar3 != 0) {
                return iVar3;
              }
              local_40 = local_30[0] & 0x1f | local_40 & 0xffffffe0;
            }
            else {
              local_40 = local_40 & 0xffffffe0;
            }
            goto LAB_97b81320;
          }
          iVar3 = _memcmp(&local_140,"clip",5);
          if (iVar3 != 0) {
            return 10;
          }
          if ((*(int *)(parser + 0x48c) != 0x31) && (*(int *)(parser + 0x48c) != 0x34)) {
            return 10;
          }
          iVar3 = 9;
        }
      }
    }
LAB_97b8130c:
    local_40 = iVar3 << 0x10 | local_40 & 0xfff0ffff;
  }
LAB_97b81320:
  local_3c = CONCAT22(local_3c,(short)*(int *)(parser + 0x28));
  *(int *)(parser + 0x28) = *(int *)(parser + 0x28) + 1;
  ((int (*)())_PPStreamAddOutputBinding)(*(undefined4 *)(parser + 0x1c),&local_40);
  iVar3 = 0x36;
  if (*(uint *)(parser + 0x28) < 0x101) {
    iVar3 = 0;
  }
  return iVar3;
}

/* _PPStreamAddOutputBinding @ 0x97b8136c (92 bytes) */
int _PPStreamAddOutputBinding(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined1 *allocation;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  allocation = (undefined1 *)_calloc(0x14,1);
  uVar4 = param_2[1];
  uVar2 = *(undefined4 *)(param_1 + 0x1c);
  uVar3 = *param_2;
  *allocation = 4;
  *(undefined4 *)(allocation + 0xc) = uVar3;
  *(undefined4 *)(allocation + 0x10) = uVar4;
  return ((int (*)())_PPStreamChunkListAddChunk)(uVar2,allocation);
}

/* _PPParserParseOperation @ 0x97b813c8 (1068 bytes) */
int _PPParserParseOperation(parser, param_2, param_3, param_4, param_5, param_6, param_7)
  int parser;
  uint param_2;
  uint param_3;
  uint param_4;
  uint param_5;
  uint param_6;
  undefined4 param_7;
{
  int ppParserParseBranchLabelResult;
  int part;
  bool bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined4 *puVar8;
  uint loopIndex;
  char local_290 [256];
  undefined1 auStack_190 [256];
  uint opHeader;
  uint opFlags;
  undefined4 opDest0;
  undefined4 opDest1;
  undefined4 opSrc0A;
  undefined4 opSrc0B;
  undefined4 opSrc1A;
  undefined4 opSrc1B;
  undefined4 opSrc2A;
  undefined4 opSrc2B;
  undefined4 opAuxA;
  undefined4 opAuxB;
  int opLine;
  undefined4 opWord13;
  undefined4 local_50;
  int local_4c [6];
  
  opLine = *(int *)(parser + 0x18);
  iVar4 = 0;
  local_50 = 0;
  uVar7 = 0;
  bVar3 = false;
  opDest0 = 0;
  bVar1 = true;
  opDest1 = 0;
  bVar2 = false;
  opSrc0A = 0;
  opSrc0B = 0;
  opSrc1A = 0;
  opSrc1B = 0;
  opSrc2A = 0;
  opSrc2B = 0;
  opAuxA = 0;
  opAuxB = 0;
  opWord13 = 0;
  if ((*(byte *)(parser + 0x441) & 1) == 0) {
    opLine = opLine + *(int *)(parser + 0x10);
  }
  opHeader = (param_2 & 0xff) << 0x12;
  opFlags = (param_3 & 3) << 0x12 |
             (param_5 & 1) << 0x14 | (param_6 & 1) << 0x15 | (param_4 & 1) << 0x16;
  switch(param_2) {
  case 0:
  case 1:
  case 2:
  case 4:
  case 5:
  case 7:
  case 0x15:
  case 0x50:
  case 0x51:
  case 0x5c:
  case 0x5d:
  case 0x5e:
  case 0x5f:
    uVar7 = 1;
    break;
  case 0xd:
  case 0xe:
  case 0xf:
  case 0x10:
  case 0x11:
  case 0x13:
  case 0x14:
  case 0x18:
  case 0x19:
  case 0x1a:
  case 99:
  case 100:
  case 0x65:
  case 0x66:
    uVar7 = 1;
    goto LAB_97b81664;
  case 0x1f:
  case 0x20:
  case 0x22:
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0x2c:
  case 0x2d:
  case 0x2e:
  case 0x2f:
  case 0x30:
  case 0x31:
  case 0x32:
  case 0x33:
  case 0x34:
  case 0x35:
  case 0x36:
  case 0x37:
  case 0x3a:
  case 0x41:
  case 0x42:
  case 0x43:
  case 0x44:
  case 0x46:
  case 0x52:
    uVar7 = 2;
    break;
  case 0x38:
    uVar7 = 2;
LAB_97b81664:
    bVar3 = true;
    break;
  case 0x3c:
  case 0x3e:
  case 0x3f:
  case 0x53:
  case 0x67:
    uVar7 = 3;
    break;
  case 0x48:
    if ((*(uint *)(parser + 0x48c) & 0x10) == 0) {
      bVar3 = true;
    }
  case 0x49:
  case 0x4a:
    uVar7 = 1;
    bVar2 = true;
    break;
  case 0x4b:
  case 0x4c:
    ppParserParseBranchLabelResult = _PPParserParseBranchLabel(parser,auStack_190,&local_50);
    if (ppParserParseBranchLabelResult != 0) {
      return ppParserParseBranchLabelResult;
    }
  case 0x4d:
  case 0x54:
  case 0x55:
    iVar4 = _PPParserParseBranchCondition(parser,&opDest0,param_2);
    goto LAB_97b816dc;
  case 0x4f:
    uVar7 = 1;
LAB_97b816dc:
    bVar1 = false;
    if (iVar4 != 0) {
      return iVar4;
    }
    break;
  case 0x56:
  case 0x57:
  case 0x60:
  case 0x61:
    uVar7 = 1;
    goto LAB_97b816c8;
  case 0x58:
  case 0x59:
  case 0x5a:
  case 0x5b:
    uVar7 = 0;
LAB_97b816c8:
    bVar1 = false;
    break;
  case 0x62:
    uVar7 = 4;
  }
  if (bVar1) {
    if (bVar2) {
      iVar4 = _PPParserParseAddressDestination(parser,&opDest0);
    }
    else {
      iVar4 = ((int (*)())_PPParserParseDestination)(parser,&opDest0,param_2);
    }
    if (iVar4 != 0) {
      return iVar4;
    }
  }
  loopIndex = 0;
  if (uVar7 != 0) {
    puVar8 = &opSrc0A;
    do {
      local_4c[0] = 0;
      if (bVar1) {
        part = ((int (*)())_PPParserGetPart)(parser,local_290,0);
        if (part == 0) {
          return 0x2d;
        }
        if (local_290[0] != ',') {
          return 0x1f;
        }
      }
      if (param_2 == 0x41) {
        if (loopIndex == 0) {
          iVar4 = ((int (*)())_PPParserParseSourceVar)(parser,&opSrc0A,0x41,local_4c);
        }
        else {
          iVar4 = _PPParserParseSwizzleCode(parser,&opSrc1A);
        }
      }
      else {
        if ((loopIndex == 3) && (param_2 == 0x62)) {
          puVar6 = &opAuxA;
        }
        else {
          if ((loopIndex != 1) || (((1 < param_2 - 0x42 && (param_2 != 0x46)) && (param_2 != 0x44)))) {
            if ((param_2 == 0x4a) || (param_2 - 0x60 < 2)) {
              iVar4 = _PPParserParseAddressSourceVar(parser,&opSrc0A);
            }
            else {
              iVar4 = ((int (*)())_PPParserParseSwizzleSourceVar)(parser,puVar8,param_2,local_4c);
            }
            goto LAB_97b818a8;
          }
          puVar6 = &opSrc1A;
        }
        iVar4 = _PPParserParseTextureSourceVar(parser,puVar6);
      }
LAB_97b818a8:
      if (iVar4 != 0) {
        return iVar4;
      }
      if ((bVar3) && (local_4c[0] == 0)) {
        return 0x14;
      }
      loopIndex = loopIndex + 1;
      puVar8 = puVar8 + 2;
    } while (loopIndex < uVar7);
  }
  part = ((int (*)())_PPParserGetPart)(parser,local_290,0);
  iVar5 = 0x2d;
  if ((part != 0) && (iVar5 = 0x1e, local_290[0] == ';')) {
    iVar4 = *(int *)(parser + 0x1c);
    iVar5 = 0x32;
    if (*(uint *)(*(int *)(iVar4 + 0x20) + 8) < *(uint *)(parser + 0x45c)) {
      iVar5 = *(int *)(*(int *)(iVar4 + 0x20) + 4);
      if (iVar5 == 0) {
        opHeader = uVar7 << 0x1d | opHeader & 0x3ffffff;
      }
      else {
        opHeader = *(uint *)(iVar5 + 0xc) >> 3 & 0x1c000000 | uVar7 << 0x1d | opHeader & 0x3ffffff;
      }
      opWord13 = local_50;
      _PPStreamAddOperation(iVar4,&opHeader,auStack_190,*(undefined1 *)(parser + 0x440));
      *(undefined1 *)(parser + 0x440) = 0;
      iVar5 = 0;
    }
  }
  return iVar5;
}

/* _PPParserParseDestination @ 0x97b81994 (604 bytes) */
int _PPParserParseDestination(parser, param_2, param_3)
  int parser;
  uint *param_2;
  int param_3;
{
  int ppParserParseOutputBindingResult;
  int ppParserScopeFindIdentifierResult;
  int arrayResult;
  int iVar1;
  uint uVar2;
  int part;
  char local_130 [256];
  undefined4 local_30;
  
  iVar1 = ((int (*)())_PPParserGetPart)(parser,local_130,1);
  if (iVar1 == 0) {
    return 0x2d;
  }
  ppParserScopeFindIdentifierResult = ((int (*)())_PPParserScopeFindIdentifier)(*(undefined4 *)(parser + 0x44c),local_130);
  if (ppParserScopeFindIdentifierResult == 0) {
    iVar1 = _memcmp(local_130,"result",7);
    if (iVar1 != 0) {
      return 0x19;
    }
    *(undefined2 *)((int)param_2 + 6) = *(undefined2 *)(parser + 0x2a);
    *param_2 = *param_2 & 0xfff1ffff | 0x60000;
    ((int (*)())_PPParserReturnPart)(parser);
    ppParserParseOutputBindingResult = ((int (*)())_PPParserParseOutputBinding)(parser,0);
    if (ppParserParseOutputBindingResult != 0) {
      return ppParserParseOutputBindingResult;
    }
  }
  else {
    local_30 = 0;
    if ((param_3 - 0x5cU < 4) && (*(int *)(ppParserScopeFindIdentifierResult + 0x14) == 2)) {
      return 0x2c;
    }
    part = ((int (*)())_PPParserGetPart)(parser,local_130,0);
    if (part == 0) {
      return 0x2d;
    }
    ((int (*)())_PPParserReturnPart)(parser);
    if (local_130[0] == '[') {
      if (*(char *)(ppParserScopeFindIdentifierResult + 0x10) == '\0') {
        return 0x20;
      }
      arrayResult = ((int (*)())_PPParserParseArray)(parser,&local_30);
      if (arrayResult != 0) {
        return arrayResult;
      }
      if (*(uint *)(ppParserScopeFindIdentifierResult + 4) <= local_30) {
        ((int (*)())_PPParserReturnPart)(parser);
        return 0x23;
      }
    }
    else if (*(char *)(ppParserScopeFindIdentifierResult + 0x10) != '\0') {
      return 0x21;
    }
    *(short *)((int)param_2 + 6) = *(short *)(ppParserScopeFindIdentifierResult + 10) + (*(unsigned short *)((unsigned char *)&(local_30) + 2));
    uVar2 = *(uint *)(ppParserScopeFindIdentifierResult + 0xc);
    if ((uVar2 != 1) && (uVar2 != 3)) {
      return 0x18;
    }
    *param_2 = (uVar2 & 7) << 0x11 | *param_2 & 0xfff1ffff;
  }
  *param_2 = *param_2 & 0xf03ffc0f | 0x1b1e06c;
  part = ((int (*)())_PPParserGetPart)(parser,local_130,0);
  iVar1 = 0x2d;
  if (part != 0) {
    if ((local_130[0] == '.') && (part == 1)) {
      iVar1 = _PPParserParseDestinationMask(parser,param_2);
      if (iVar1 != 0) {
        return iVar1;
      }
    }
    else {
      ((int (*)())_PPParserReturnPart)(parser);
    }
    if (((*(uint *)(parser + 0x48c) & 0x10) == 0) ||
       (iVar1 = _PPParserParseBranchCondition(parser,param_2,0), iVar1 == 0)) {
      iVar1 = 0;
    }
  }
  return iVar1;
}

/* _PPParserParseSwizzleSourceVar @ 0x97b81bf0 (460 bytes) */
int _PPParserParseSwizzleSourceVar(parser, param_2, param_3, param_4)
  int parser;
  uint *param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  int part;
  int compareResult;
  int ppParserParseSourceSwizzleResult;
  int iVar2;
  char local_120 [268];
  
  part = ((int (*)())_PPParserGetPart)(parser,local_120,0);
  iVar2 = 0x2d;
  if (part != 0) {
    compareResult = _memcmp(local_120,"-",2);
    if (compareResult == 0) {
      *param_2 = *param_2 | 0x8000000;
    }
    else {
      compareResult = _memcmp(local_120,"+",2);
      if (compareResult != 0) {
        ((int (*)())_PPParserReturnPart)(parser);
      }
    }
    if ((*(uint *)(parser + 0x48c) & 0x20) != 0) {
      part = ((int (*)())_PPParserGetPart)(parser,local_120,0);
      if (part == 0) {
        return 0x2d;
      }
      compareResult = _memcmp(local_120,"|",2);
      if (compareResult == 0) {
        *param_2 = *param_2 | 0x4000000;
      }
      else {
        ((int (*)())_PPParserReturnPart)(parser);
      }
    }
    iVar2 = ((int (*)())_PPParserParseSourceVar)(parser,param_2,param_3,param_4);
    if (iVar2 == 0) {
      part = ((int (*)())_PPParserGetPart)(parser,local_120,0);
      iVar2 = 0x2d;
      if (part != 0) {
        if ((local_120[0] == '.') && (part == 1)) {
          ppParserParseSourceSwizzleResult = _PPParserParseSourceSwizzle(parser,param_2,param_4);
          if (ppParserParseSourceSwizzleResult != 0) {
            return ppParserParseSourceSwizzleResult;
          }
        }
        else {
          ((int (*)())_PPParserReturnPart)(parser);
        }
        if (((*(uint *)(parser + 0x48c) & 0x20) != 0) && ((*param_2 & 0x4000000) != 0)) {
          part = ((int (*)())_PPParserGetPart)(parser,local_120,0);
          if (part == 0) {
            return 0x2d;
          }
          compareResult = _memcmp(local_120,"|",2);
          if (compareResult != 0) {
            return 0x17;
          }
        }
        iVar2 = 0;
      }
    }
  }
  return iVar2;
}

/* _PPParserParseSourceVar @ 0x97b81dbc (696 bytes) */
int _PPParserParseSourceVar(parser, param_2, param_3, param_4)
  int parser;
  uint *param_2;
  int param_3;
  uint *param_4;
{
  int ppParserScopeFindIdentifierResult;
  int ppParserParseIndirectArrayResult;
  int part;
  undefined2 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  char local_130 [256];
  char *local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  part = ((int (*)())_PPParserGetPart)(parser,local_130,1);
  if (part == 0) {
    return 0x2d;
  }
  ppParserScopeFindIdentifierResult = ((int (*)())_PPParserScopeFindIdentifier)(*(undefined4 *)(parser + 0x44c),local_130);
  if (ppParserScopeFindIdentifierResult == 0) {
    if ((*(uint *)(parser + 0x48c) & 2) == 0) {
      iVar4 = _memcmp(local_130,"vertex",7);
    }
    else {
      iVar4 = _memcmp(local_130,"fragment",9);
    }
    if (iVar4 == 0) {
      *(undefined2 *)((int)param_2 + 6) = *(undefined2 *)(parser + 0x26);
      *param_2 = *param_2 & 0xfc7fffff;
      ((int (*)())_PPParserReturnPart)(parser);
      iVar3 = ((int (*)())_PPParserParseAttributeBinding)(parser);
    }
    else {
      if (((local_130[0] != '{') && (iVar4 = _memcmp(local_130,"program",8), iVar4 != 0)) &&
         (iVar4 = _memcmp(local_130,"state",6), iVar4 != 0)) {
        ((double (*)())_glp_strtod)(local_130,&local_30);
        uVar2 = (uint)(local_30 == local_130 + part);
        *param_4 = uVar2;
        if (uVar2 == 0) {
          return 0x1a;
        }
      }
      uVar1 = *(undefined2 *)(parser + 0x22);
      *param_2 = *param_2 & 0xfc7fffff | 0x1000000;
      *(undefined2 *)((int)param_2 + 6) = uVar1;
      local_2c = 1;
      ((int (*)())_PPParserReturnPart)(parser);
      iVar3 = ((int (*)())_PPParserParseParamBinding)(parser,0,&local_2c);
    }
    if (iVar3 != 0) {
      return iVar3;
    }
  }
  else {
    local_28 = 0;
    if ((param_3 - 99U < 4) && (*(int *)(ppParserScopeFindIdentifierResult + 0x14) == 2)) {
      return 0x2b;
    }
    part = ((int (*)())_PPParserGetPart)(parser,local_130,0);
    if (part == 0) {
      return 0x2d;
    }
    ((int (*)())_PPParserReturnPart)(parser);
    if (local_130[0] == '[') {
      if (*(char *)(ppParserScopeFindIdentifierResult + 0x10) == '\0') {
        return 0x20;
      }
      ppParserParseIndirectArrayResult = _PPParserParseIndirectArray(parser,param_2,&local_28);
      if (ppParserParseIndirectArrayResult != 0) {
        return ppParserParseIndirectArrayResult;
      }
      if (*(uint *)(ppParserScopeFindIdentifierResult + 4) <= local_28) {
        ((int (*)())_PPParserReturnPart)(parser);
        return 0x23;
      }
    }
    else if (*(char *)(ppParserScopeFindIdentifierResult + 0x10) != '\0') {
      return 0x21;
    }
    *(short *)((int)param_2 + 6) = *(short *)(ppParserScopeFindIdentifierResult + 10) + (*(unsigned short *)((unsigned char *)&(local_28) + 2));
    if (2 < *(uint *)(ppParserScopeFindIdentifierResult + 0xc)) {
      return 0x17;
    }
    *param_2 = (*(uint *)(ppParserScopeFindIdentifierResult + 0xc) & 7) << 0x17 | *param_2 & 0xfc7fffff;
  }
  if (*param_4 == 0) {
    uVar2 = *param_2 & 0xff89ffff | 0xd8000;
  }
  else {
    uVar2 = *param_2 & 0xff807fff;
  }
  *param_2 = uVar2;
  return 0;
}

/* FUN_97b82078 @ 0x97b82078 (216 bytes) */
int FUN_97b82078(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  int maxIndex;
  uint uVar1;
  int iVar2;
  undefined1 *allocation;
  int iVar4;
  
  iVar4 = *(int *)(param_2 + 0x34);
  iVar2 = 0x38;
  if (iVar4 != 0) {
    iVar2 = iVar4 + 0x39;
  }
  allocation = (undefined1 *)_calloc(iVar2 + 0xc,1);
  *allocation = 8;
  _memcpy(allocation + 0xc,param_2,0x38);
  if ((iVar4 != 0) && (param_3 != 0)) {
    _memmove(allocation + 0x44,param_3,iVar4);
    allocation[iVar4 + 0x44] = 0;
  }
  if (param_4 == 0) {
    maxIndex = _PPStreamChunkListGetMaxIndex(*(undefined4 *)(param_1 + 0x20));
    uVar1 = maxIndex + 1U & 0x3ffff | *(uint *)(allocation + 0xc) & 0xfffc0000;
  }
  else {
    uVar1 = *(uint *)(allocation + 0xc) & 0xfffc0000;
  }
  *(uint *)(allocation + 0xc) = uVar1;
  return ((int (*)())_PPStreamChunkListAddChunk)(*(undefined4 *)(param_1 + 0x20),allocation);
}

/* _PPParserParseEnd @ 0x97b82150 (136 bytes) */
int _PPParserParseEnd(parser)
  undefined4 parser;
{
  int compareResult;
  int part;
  undefined4 uVar2;
  undefined1 auStack_110 [264];
  
  part = ((int (*)())_PPParserGetPart)(parser,auStack_110,0);
  uVar2 = 0x2d;
  if (part != 0) {
    compareResult = _memcmp(auStack_110,"END",4);
    uVar2 = 6;
    if (compareResult == 0) {
      part = ((int (*)())_PPParserGetPart)(parser,auStack_110,0);
      uVar2 = 9;
      if (part == 0) {
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}

/* _PPStreamAttribBindingIsEqual @ 0x97b821d8 (88 bytes) */
int _PPStreamAttribBindingIsEqual(stream, param_2)
  undefined4 *stream;
  undefined4 *param_2;
{
  int compareResult;
  undefined4 local_30;
  undefined2 local_2c;
  undefined2 uStack_2a;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_1c = param_2[1];
  local_30 = *stream;
  local_20 = *param_2;
  local_2c = CONCAT22((short)((uint)stream[1] >> 0x10),(short)local_1c);
  compareResult = _memcmp(&local_30,&local_20,8);
  return compareResult == 0;
}

/* _PPStreamOutputBindingIsEqual @ 0x97b82230 (88 bytes) */
int _PPStreamOutputBindingIsEqual(stream, param_2)
  undefined4 *stream;
  undefined4 *param_2;
{
  int compareResult;
  undefined4 local_30;
  undefined2 local_2c;
  undefined2 uStack_2a;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_1c = param_2[1];
  local_30 = *stream;
  local_20 = *param_2;
  local_2c = CONCAT22((short)((uint)stream[1] >> 0x10),(short)local_1c);
  compareResult = _memcmp(&local_30,&local_20,8);
  return compareResult == 0;
}

/* _PPStreamParamBindingIsEqual @ 0x97b82288 (88 bytes) */
int _PPStreamParamBindingIsEqual(stream, param_2)
  undefined4 *stream;
  undefined4 *param_2;
{
  int compareResult;
  undefined4 local_30;
  undefined2 local_2c;
  undefined2 uStack_2a;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_1c = param_2[1];
  local_30 = *stream;
  local_20 = *param_2;
  local_2c = CONCAT22((short)((uint)stream[1] >> 0x10),(short)local_1c);
  compareResult = _memcmp(&local_30,&local_20,8);
  return compareResult == 0;
}

/* _PPStreamChunkListGetStream @ 0x97b822e0 (276 bytes) */
int _PPStreamChunkListGetStream(stream, param_2, param_3, param_4)
  int *stream;
  int param_2;
  int *param_3;
  undefined4 param_4;
{
  int iVar1;
  int iVar2;
  uint loopIndex;
  int iVar4;
  undefined1 auStack_40 [16];
  uint local_30;
  undefined1 auStack_2c [16];
  
  iVar1 = 0;
  iVar2 = *stream;
  *param_3 = 0;
  for (; iVar2 != 0; iVar2 = *(int *)(iVar2 + 8)) {
    ((int (*)())_PPStreamChunkGetStream)(auStack_40,iVar2,param_4,&local_30,0);
    *param_3 = *param_3 + local_30;
  }
  if (param_2 != 0) {
    for (iVar2 = *stream; iVar2 != 0; iVar2 = *(int *)(iVar2 + 8)) {
      ((int (*)())_PPStreamChunkGetStream)(iVar1 * 8 + param_2,iVar2,param_4,&local_30,0);
      iVar1 = iVar1 + 1;
      if (1 < local_30) {
        local_30 = local_30 - 1;
        loopIndex = 0;
        if (local_30 != 0) {
          iVar4 = iVar1 * 8 + param_2;
          do {
            loopIndex = loopIndex + 1;
            ((int (*)())_PPStreamChunkGetStream)(iVar4,iVar2,param_4,auStack_2c,loopIndex);
            iVar1 = iVar1 + 1;
            iVar4 = iVar4 + 8;
          } while (loopIndex < local_30);
        }
      }
    }
  }
  return;
}

/* _PPStreamChunkGetStream @ 0x97b823f4 (184 bytes) */
int _PPStreamChunkGetStream(stream, param_2, param_3, param_4, param_5)
  undefined4 *stream;
  undefined1 *param_2;
  undefined4 param_3;
  int *param_4;
  int param_5;
{
  undefined4 uVar1;
  undefined4 uVar2;
  
  *param_4 = 1;
  switch(*param_2) {
  case 0:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
  case 9:
    goto switchD_97b82430_caseD_0;
  default:
    uVar1 = (*(unsigned int *)0x00000004);
    uVar2 = (*(unsigned int *)0x00000000);
    goto LAB_97b824b4;
  case 8:
    *param_4 = (*(uint *)(param_2 + 0xc) >> 0x1d) + 2;
    if (param_5 != 0) {
      if (param_5 == 1) {
        uVar1 = *(undefined4 *)(param_2 + 0x18);
        uVar2 = *(undefined4 *)(param_2 + 0x14);
        goto LAB_97b82490;
      }
      goto LAB_97b824a8;
    }
switchD_97b82430_caseD_0:
    uVar1 = *(undefined4 *)(param_2 + 0x10);
    uVar2 = *(undefined4 *)(param_2 + 0xc);
LAB_97b82490:
    stream[1] = uVar1;
    *stream = uVar2;
    return;
  case 10:
    *param_4 = 2;
LAB_97b824a8:
    uVar1 = *(undefined4 *)(param_2 + param_5 * 8 + 0x10);
    uVar2 = *(undefined4 *)(param_2 + param_5 * 8 + 0xc);
LAB_97b824b4:
    stream[1] = uVar1;
    *stream = uVar2;
    return;
  }
}

/* _PPStreamChunkListCreateFromChunkList @ 0x97b824dc (96 bytes) */
int _PPStreamChunkListCreateFromChunkList(stream)
  int *stream;
{
  undefined4 chunkList;
  undefined4 chunk;
  int iVar3;
  
  chunkList = ((int (*)())_PPStreamChunkListCreate)();
  for (iVar3 = *stream; iVar3 != 0; iVar3 = *(int *)(iVar3 + 8)) {
    chunk = ((int (*)())_PPStreamChunkCreateFromChunk)(iVar3);
    ((int (*)())_PPStreamChunkListAddChunk)(chunkList,chunk);
  }
  return chunkList;
}

/* _PPStreamChunkCreateFromChunk @ 0x97b8253c (128 bytes) */
int _PPStreamChunkCreateFromChunk(stream)
  byte *stream;
{
  uint uVar1;
  int chunkAllocationSize;
  int allocation;
  undefined4 uVar4;
  
  uVar4 = 0;
  uVar1 = (uint)*stream;
  if (uVar1 == 8) {
    uVar4 = *(undefined4 *)(stream + 0x40);
  }
  else if (uVar1 == 0xb) {
    uVar4 = *(undefined4 *)(stream + 0x10);
  }
  chunkAllocationSize = _GetChunkAllocationSize(uVar1,uVar4);
  allocation = _calloc(chunkAllocationSize + 0xc,1);
  _memmove(allocation,stream,chunkAllocationSize + 0xc);
  *(undefined4 *)(allocation + 4) = 0;
  *(undefined4 *)(allocation + 8) = 0;
  return allocation;
}

