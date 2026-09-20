#include "decls.h"

/* _PPEmulatorCreate @ 0x97b7bc5c (56 bytes) */
int _PPEmulatorCreate()
{
  void *pvVar1;
  
  pvVar1 = _malloc(0xe00);
  ((int (*)())_PPEmulatorInit)(pvVar1);
  return pvVar1;
}

/* dyld_stub_binding_helper @ 0x97b7bc94 (48 bytes) */
int dyld_stub_binding_helper()
{
                    
                    
  (*dyld_lazy_symbol_binding_entry_point)();
  return;
}

/* _PPEmulatorInit @ 0x97b7bcc4 (96 bytes) */
int _PPEmulatorInit(param_1)
  void *param_1;
{
  void *pvVar1;
  undefined4 uVar2;
  
  _memset(param_1,0,0xdf4);
  pvVar1 = _malloc(0x1010);
  *(void **)((int)param_1 + 0xd84) = pvVar1;
  _memset(pvVar1,0,0x1010);
  ((double (*)())_PPCConstantsAndScratchInitialise)(param_1);
  uVar2 = _InterpreterCreate();
  *(undefined4 *)((int)param_1 + 0xdf0) = uVar2;
  _InterpreterAttachEmulatorContext(uVar2,param_1);
  return;
}

/* _PPParserCreate @ 0x97b7bd24 (96 bytes) */
int _PPParserCreate(param_1)
  undefined4 param_1;
{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = _calloc(0x490,1);
  *(undefined4 *)((int)pvVar1 + 0x48c) = param_1;
  *(undefined4 *)((int)pvVar1 + 0x34) = 0xffffffff;
  *(undefined4 *)((int)pvVar1 + 0x38) = 0xffffffff;
  uVar2 = ((int (*)())_PPParserScopeCreate)(pvVar1);
  ((int (*)())_PPParserAddScope)(pvVar1,uVar2);
  return pvVar1;
}

/* _PPParserScopeCreate @ 0x97b7bd84 (408 bytes) */
int _PPParserScopeCreate(param_1)
  undefined4 param_1;
{
  void *pvVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_f0 [96];
  undefined1 auStack_90 [120];
  
  _memcpy(auStack_f0,
          "DP4 dst.x, mat[0], vec;\nDP4 dst.y, mat[1], vec;\nDP4 dst.z, mat[2], vec;\nDP4 dst.w, mat[3], vec;"
          ,0x60);
  _memcpy(auStack_90,
          "MUL tmp, mat[0], vec.x;\nMAD tmp, mat[1], vec.y, tmp;\nMAD tmp, mat[2], vec.z, tmp;\nMAD dst, mat[3], vec.w, tmp;\n"
          ,0x70);
  pvVar1 = _calloc(0x24,1);
  iVar2 = ((int (*)())_PPParserMacroCreate)();
  ((int (*)())_PPParserMacroSetSearchString)(param_1,iVar2,"MVMULT",6);
  ((int (*)())_PPParserMacroSetParamStringsCount)(iVar2,3);
  ((int (*)())_PPParserMacroSetParamString)(iVar2,0,"dst");
  ((int (*)())_PPParserMacroSetParamString)(iVar2,1,"mat");
  ((int (*)())_PPParserMacroSetParamString)(iVar2,2,"vec");
  uVar3 = ((int (*)())_PPParserPreprocessString)(param_1,auStack_f0,0);
  *(undefined4 *)(iVar2 + 4) = uVar3;
  ((int (*)())_PPParserScopeAddMacro)(pvVar1,iVar2);
  iVar2 = ((int (*)())_PPParserMacroCreate)();
  ((int (*)())_PPParserMacroSetSearchString)(param_1,iVar2,"TMVMULT",7);
  ((int (*)())_PPParserMacroSetParamStringsCount)(iVar2,4);
  ((int (*)())_PPParserMacroSetParamString)(iVar2,0,"dst");
  ((int (*)())_PPParserMacroSetParamString)(iVar2,1,"mat");
  ((int (*)())_PPParserMacroSetParamString)(iVar2,2,"vec");
  ((int (*)())_PPParserMacroSetParamString)(iVar2,3,"tmp");
  uVar3 = ((int (*)())_PPParserPreprocessString)(param_1,auStack_90,0);
  *(undefined4 *)(iVar2 + 4) = uVar3;
  ((int (*)())_PPParserScopeAddMacro)(pvVar1,iVar2);
  return pvVar1;
}

/* _PPParserMacroCreate @ 0x97b7bf1c (12 bytes) */
int _PPParserMacroCreate()
{
  void *pvVar1;
  
  pvVar1 = _calloc(0x20,1);
  return pvVar1;
}

/* _PPParserMacroSetSearchString @ 0x97b7bf28 (116 bytes) */
int _PPParserMacroSetSearchString(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int *param_2;
  void *param_3;
  size_t param_4;
{
  void *pvVar1;
  
  if ((void *)*param_2 != (void *)0x0) {
    _free((void *)*param_2);
    *param_2 = 0;
  }
  if (param_3 != (void *)0x0) {
    pvVar1 = _malloc(param_4 + 1);
    *param_2 = (int)pvVar1;
    _memmove(pvVar1,param_3,param_4);
    *(undefined1 *)(*param_2 + param_4) = 0;
  }
  return;
}

/* _PPParserMacroSetParamStringsCount @ 0x97b7bf9c (60 bytes) */
int _PPParserMacroSetParamStringsCount(param_1, param_2)
  int param_1;
  size_t param_2;
{
  void *pvVar1;
  
  pvVar1 = _calloc(4,param_2);
  *(void **)(param_1 + 0xc) = pvVar1;
  *(size_t *)(param_1 + 8) = param_2;
  return;
}

/* _PPParserMacroSetParamString @ 0x97b7bfd8 (116 bytes) */
int _PPParserMacroSetParamString(param_1, param_2, param_3)
  int param_1;
  int param_2;
  char *param_3;
{
  int iVar1;
  size_t sVar2;
  void *pvVar3;
  int iVar4;
  
  sVar2 = _strlen(param_3);
  iVar4 = *(int *)(param_1 + 0xc);
  pvVar3 = _malloc(sVar2 + 1);
  iVar1 = param_2 * 4;
  *(void **)(iVar1 + iVar4) = pvVar3;
  _memmove(*(void **)(iVar1 + *(int *)(param_1 + 0xc)),param_3,sVar2);
  *(undefined1 *)(*(int *)(iVar1 + *(int *)(param_1 + 0xc)) + sVar2) = 0;
  return;
}

/* _PPParserPreprocessString @ 0x97b7c04c (2588 bytes) */
int _PPParserPreprocessString(param_1, param_2, param_3)
  undefined4 param_1;
  char *param_2;
  int param_3;
{
  byte bVar1;
  char cVar2;
  bool bVar3;
  uint uVar4;
  undefined1 uVar5;
  size_t sVar6;
  uint uVar7;
  uint uVar8;
  void *pvVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  
  sVar6 = _strlen(param_2);
  if (param_3 == 0) {
    uVar7 = 0;
    uVar16 = 0;
LAB_97b7c0e8:
    uVar12 = 1;
  }
  else {
    uVar7 = 10;
    if (sVar6 < 10) {
      uVar7 = sVar6;
    }
    uVar16 = uVar7;
    if ((((uVar7 < sVar6) && (cVar2 = param_2[uVar7], cVar2 != ' ')) && (cVar2 != '\t')) &&
       (((cVar2 != '\n' && (cVar2 != '\r')) && (cVar2 != '#')))) {
      uVar7 = uVar7 + 1;
      goto LAB_97b7c0e8;
    }
    uVar12 = 0;
  }
  bVar3 = false;
  uVar11 = 0;
joined_r0x97b7c0f8:
  uVar4 = uVar16;
  if (sVar6 <= uVar4) goto LAB_97b7c6cc;
  iVar13 = 1;
  if (bVar3) {
    if (param_2[uVar4] != '\n') goto code_r0x97b7c67c;
    uVar16 = uVar4 + 1;
    goto LAB_97b7c6bc;
  }
  switch(param_2[uVar4]) {
  case '\t':
  case ' ':
    if ((((uVar12 == 0) && (uVar4 + 1 < sVar6)) &&
        ((cVar2 = param_2[uVar4 + 1], cVar2 != ' ' &&
         (((cVar2 != '\t' && (cVar2 != '\n')) && (cVar2 != '\r')))))) && (cVar2 != '#')) {
LAB_97b7c5fc:
      uVar7 = uVar7 + 1;
      uVar12 = 1;
    }
    goto LAB_97b7c604;
  case '\n':
    uVar7 = uVar7 + 1;
    uVar15 = uVar4 + 1;
    break;
  default:
    uVar7 = uVar7 + 1;
    uVar15 = uVar4 + 1;
    uVar12 = 0;
    goto LAB_97b7c664;
  case '\r':
    uVar7 = uVar7 + 1;
    if ((uVar4 + 1 < sVar6) && (param_2[uVar4 + 1] == '\n')) {
      iVar13 = 2;
    }
    uVar15 = uVar4 + iVar13;
    break;
  case '#':
    uVar15 = uVar4 + 1;
    bVar3 = true;
    break;
  case '(':
  case ')':
  case ',':
  case ':':
  case ';':
  case '=':
  case '[':
  case ']':
  case '{':
  case '|':
  case '}':
    if (uVar12 == 0) {
      uVar7 = uVar7 + 1;
    }
    uVar7 = uVar7 + 1;
    if (((uVar4 + 1 < sVar6) && (cVar2 = param_2[uVar4 + 1], cVar2 != ' ')) &&
       ((cVar2 != '\t' && (((cVar2 != '\n' && (cVar2 != '\r')) && (cVar2 != '#'))))))
    goto LAB_97b7c5fc;
    uVar12 = 0;
LAB_97b7c604:
    uVar15 = uVar4 + 1;
    goto LAB_97b7c664;
  case '+':
  case '-':
    if ((uVar12 == 0) && (uVar11 == 0)) {
      uVar7 = uVar7 + 1;
    }
    uVar15 = uVar4 + 1;
    uVar8 = uVar7 + 1;
    if ((((sVar6 <= uVar15) || (bVar1 = param_2[uVar4 + 1], bVar1 - 0x30 < 10)) || (bVar1 == 0x20))
       || (((bVar1 == 9 || (bVar1 == 10)) ||
           ((bVar1 == 0xd || ((bVar1 == 0x23 || (bVar1 == 0x2e)))))))) {
      uVar12 = 0;
      uVar16 = uVar4 + 1;
      if (uVar15 < sVar6) {
        cVar2 = param_2[uVar15];
        while ((cVar2 == ' ' || (cVar2 == '\t'))) {
          iVar13 = iVar13 + 1;
          uVar16 = uVar4 + iVar13;
          if (sVar6 <= uVar16) break;
          cVar2 = param_2[uVar16];
        }
      }
      uVar11 = 0;
      uVar7 = uVar8;
      if (uVar16 < sVar6) {
        if (((byte)param_2[uVar16] - 0x30 < 10) || (param_2[uVar16] == 0x2e)) {
          uVar11 = 1;
        }
        bVar1 = param_2[uVar16];
        if ((((9 < bVar1 - 0x30) && (bVar1 != 0x2e)) && (bVar1 != 10)) &&
           ((bVar1 != 0xd && (bVar1 != 0x23)))) {
          uVar16 = uVar4 + iVar13 + -1;
        }
      }
      goto joined_r0x97b7c0f8;
    }
    uVar7 = uVar7 + 2;
    break;
  case '.':
    if ((uVar4 + 1 < sVar6) && (param_2[uVar4 + 1] == '.')) {
      uVar16 = uVar7;
      if (uVar12 == 0) {
        uVar16 = uVar7 + 1;
      }
      uVar7 = uVar16 + 2;
      if (((((uVar4 + 2 < sVar6) && (cVar2 = param_2[uVar4 + 2], cVar2 != ' ')) && (cVar2 != '\t'))
          && ((cVar2 != '\n' && (cVar2 != '\r')))) && (cVar2 != '#')) {
        uVar7 = uVar16 + 3;
        uVar12 = 1;
      }
      else {
        uVar12 = 0;
      }
      uVar15 = uVar4 + 2;
      goto LAB_97b7c664;
    }
    if ((uVar12 == 0) && (uVar11 != 1)) {
      uVar7 = uVar7 + 1;
    }
    uVar16 = uVar7 + 1;
    if (sVar6 <= uVar4 + 1) goto LAB_97b7c64c;
    bVar1 = param_2[uVar4 + 1];
    if (bVar1 - 0x30 < 10) {
      uVar12 = 0;
      uVar11 = 3;
      uVar7 = uVar16;
      uVar16 = uVar4 + 1;
      goto joined_r0x97b7c0f8;
    }
    if ((((bVar1 != 0x20) && (bVar1 != 9)) && (bVar1 != 10)) && ((bVar1 != 0xd && (bVar1 != 0x23))))
    {
      uVar12 = 1;
      uVar7 = uVar7 + 2;
      uVar16 = uVar4 + 1;
      goto joined_r0x97b7c0f8;
    }
    goto LAB_97b7c64c;
  case '0':
  case '1':
  case '2':
  case '3':
  case '4':
  case '5':
  case '6':
  case '7':
  case '8':
  case '9':
    uVar11 = uVar11 | uVar12;
  case 'E':
  case 'e':
    uVar16 = uVar7 + 1;
LAB_97b7c64c:
    uVar12 = 0;
    uVar7 = uVar16;
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
    uVar7 = uVar7 + 1;
  }
  pvVar9 = _calloc(uVar7 + 1,1);
  if (param_3 == 0) {
    iVar13 = 0;
    uVar7 = 0;
LAB_97b7c774:
    uVar16 = 1;
  }
  else {
    uVar7 = 10;
    if (sVar6 < 10) {
      uVar7 = sVar6;
    }
    iVar13 = 0;
    for (uVar16 = uVar7; uVar16 != 0; uVar16 = uVar16 - 1) {
      *(char *)((int)pvVar9 + iVar13) = param_2[iVar13];
      iVar13 = iVar13 + 1;
    }
    if (((uVar7 < sVar6) && (cVar2 = param_2[uVar7], cVar2 != ' ')) &&
       ((cVar2 != '\t' && (((cVar2 != '\n' && (cVar2 != '\r')) && (cVar2 != '#')))))) {
      *(undefined1 *)((int)pvVar9 + iVar13) = 0x20;
      iVar13 = iVar13 + 1;
      goto LAB_97b7c774;
    }
    uVar16 = 0;
  }
  bVar3 = false;
  uVar12 = 0;
joined_r0x97b7c784:
  uVar11 = uVar7;
  if (sVar6 <= uVar11) {
    if (uVar16 == 0) {
      *(undefined1 *)((int)pvVar9 + iVar13) = 0x20;
    }
    return pvVar9;
  }
  iVar14 = 1;
  if (bVar3) {
    if (param_2[uVar11] != '\n') goto code_r0x97b7cd84;
    *(undefined1 *)((int)pvVar9 + iVar13) = 10;
    uVar7 = uVar11 + 1;
    goto LAB_97b7cdd0;
  }
  cVar2 = param_2[uVar11];
  iVar10 = iVar13;
  switch(cVar2) {
  case '\t':
  case ' ':
    if ((((uVar16 == 0) && (uVar11 + 1 < sVar6)) &&
        ((cVar2 = param_2[uVar11 + 1], cVar2 != ' ' &&
         (((cVar2 != '\t' && (cVar2 != '\n')) && (cVar2 != '\r')))))) && (cVar2 != '#')) {
LAB_97b7ccec:
      uVar16 = 1;
      *(undefined1 *)((int)pvVar9 + iVar13) = 0x20;
      iVar10 = iVar13 + 1;
    }
    goto LAB_97b7ccfc;
  case '\n':
    uVar5 = 10;
    goto LAB_97b7cbd8;
  default:
    *(char *)((int)pvVar9 + iVar13) = cVar2;
    uVar7 = uVar11 + 1;
    iVar10 = iVar13 + 1;
    uVar16 = 0;
    break;
  case '\r':
    *(undefined1 *)((int)pvVar9 + iVar13) = 10;
    iVar10 = iVar13 + 1;
    if ((uVar11 + 1 < sVar6) && (param_2[uVar11 + 1] == '\n')) {
      iVar14 = 2;
    }
    uVar7 = uVar11 + iVar14;
    goto LAB_97b7cbe0;
  case '#':
    uVar7 = uVar11 + 1;
    bVar3 = true;
    goto LAB_97b7cbe0;
  case '(':
  case ')':
  case ',':
  case ':':
  case ';':
  case '=':
  case '[':
  case ']':
  case '{':
  case '|':
  case '}':
    if (uVar16 == 0) {
      *(undefined1 *)((int)pvVar9 + iVar13) = 0x20;
      iVar13 = iVar13 + 1;
    }
    *(char *)((int)pvVar9 + iVar13) = cVar2;
    iVar13 = iVar13 + 1;
    if (((uVar11 + 1 < sVar6) && (cVar2 = param_2[uVar11 + 1], cVar2 != ' ')) &&
       ((cVar2 != '\t' && (((cVar2 != '\n' && (cVar2 != '\r')) && (cVar2 != '#'))))))
    goto LAB_97b7ccec;
    uVar16 = 0;
    iVar10 = iVar13;
LAB_97b7ccfc:
    uVar7 = uVar11 + 1;
    break;
  case '+':
  case '-':
    if ((uVar16 == 0) && (uVar12 == 0)) {
      *(undefined1 *)((int)pvVar9 + iVar13) = 0x20;
      iVar13 = iVar13 + 1;
    }
    uVar12 = uVar11 + 1;
    *(char *)((int)pvVar9 + iVar13) = cVar2;
    iVar13 = iVar13 + 1;
    if ((((sVar6 <= uVar12) || (bVar1 = param_2[uVar11 + 1], bVar1 - 0x30 < 10)) || (bVar1 == 0x20))
       || (((bVar1 == 9 || (bVar1 == 10)) ||
           ((bVar1 == 0xd || ((bVar1 == 0x23 || (bVar1 == 0x2e)))))))) {
      uVar16 = 0;
      uVar7 = uVar11 + 1;
      if (uVar12 < sVar6) {
        cVar2 = param_2[uVar12];
        while ((cVar2 == ' ' || (cVar2 == '\t'))) {
          iVar14 = iVar14 + 1;
          uVar7 = uVar11 + iVar14;
          if (sVar6 <= uVar7) break;
          cVar2 = param_2[uVar7];
        }
      }
      uVar12 = 0;
      if (uVar7 < sVar6) {
        if (((byte)param_2[uVar7] - 0x30 < 10) || (param_2[uVar7] == 0x2e)) {
          uVar12 = 1;
        }
        bVar1 = param_2[uVar7];
        if ((((9 < bVar1 - 0x30) && (bVar1 != 0x2e)) && (bVar1 != 10)) &&
           ((bVar1 != 0xd && (bVar1 != 0x23)))) {
          uVar7 = uVar11 + iVar14 + -1;
        }
      }
      goto joined_r0x97b7c784;
    }
    uVar5 = 0x20;
LAB_97b7cbd8:
    uVar7 = uVar11 + 1;
    *(undefined1 *)((int)pvVar9 + iVar13) = uVar5;
    iVar10 = iVar13 + 1;
LAB_97b7cbe0:
    uVar16 = 1;
    break;
  case '.':
    if ((sVar6 <= uVar11 + 1) || (param_2[uVar11 + 1] != '.')) {
      if ((uVar16 == 0) && (uVar12 != 1)) {
        *(undefined1 *)((int)pvVar9 + iVar13) = 0x20;
        iVar13 = iVar13 + 1;
      }
      *(undefined1 *)((int)pvVar9 + iVar13) = 0x2e;
      iVar14 = iVar13 + 1;
      if (sVar6 <= uVar11 + 1) goto LAB_97b7cd54;
      bVar1 = param_2[uVar11 + 1];
      if (bVar1 - 0x30 < 10) {
        uVar16 = 0;
        uVar12 = 3;
        iVar13 = iVar14;
        uVar7 = uVar11 + 1;
        goto joined_r0x97b7c784;
      }
      if ((((bVar1 != 0x20) && (bVar1 != 9)) && (bVar1 != 10)) &&
         ((bVar1 != 0xd && (bVar1 != 0x23)))) {
        *(undefined1 *)((int)pvVar9 + iVar14) = 0x20;
        uVar16 = 1;
        iVar13 = iVar13 + 2;
        uVar7 = uVar11 + 1;
        goto joined_r0x97b7c784;
      }
      goto LAB_97b7cd54;
    }
    if (uVar16 == 0) {
      *(undefined1 *)((int)pvVar9 + iVar13) = 0x20;
      iVar13 = iVar13 + 1;
    }
    *(undefined1 *)((int)pvVar9 + iVar13) = 0x2e;
    *(undefined1 *)((int)pvVar9 + iVar13 + 1) = 0x2e;
    iVar10 = iVar13 + 2;
    if (((((uVar11 + 2 < sVar6) && (cVar2 = param_2[uVar11 + 2], cVar2 != ' ')) && (cVar2 != '\t'))
        && ((cVar2 != '\n' && (cVar2 != '\r')))) && (cVar2 != '#')) {
      uVar16 = 1;
      *(undefined1 *)((int)pvVar9 + iVar10) = 0x20;
      iVar10 = iVar13 + 3;
    }
    else {
      uVar16 = 0;
    }
    uVar7 = uVar11 + 2;
    break;
  case '0':
  case '1':
  case '2':
  case '3':
  case '4':
  case '5':
  case '6':
  case '7':
  case '8':
  case '9':
    *(char *)((int)pvVar9 + iVar13) = cVar2;
    uVar12 = uVar12 | uVar16;
    iVar14 = iVar13 + 1;
    goto LAB_97b7cd54;
  case 'E':
  case 'e':
    *(char *)((int)pvVar9 + iVar13) = cVar2;
    iVar14 = iVar13 + 1;
LAB_97b7cd54:
    uVar16 = 0;
    iVar13 = iVar14;
    uVar7 = uVar11 + 1;
    goto joined_r0x97b7c784;
  }
  uVar12 = 0;
  iVar13 = iVar10;
  goto joined_r0x97b7c784;
code_r0x97b7cd84:
  uVar7 = uVar11 + 1;
  if (param_2[uVar11] == '\r') {
    *(undefined1 *)((int)pvVar9 + iVar13) = 10;
    if ((uVar11 + 1 < sVar6) && (param_2[uVar11 + 1] == '\n')) {
      iVar14 = 2;
    }
    uVar7 = uVar11 + iVar14;
LAB_97b7cdd0:
    bVar3 = false;
    iVar13 = iVar13 + 1;
  }
  goto joined_r0x97b7c784;
code_r0x97b7c67c:
  uVar16 = uVar4 + 1;
  if (param_2[uVar4] == '\r') {
    if ((uVar4 + 1 < sVar6) && (param_2[uVar4 + 1] == '\n')) {
      iVar13 = 2;
    }
    uVar16 = uVar4 + iVar13;
LAB_97b7c6bc:
    bVar3 = false;
    uVar7 = uVar7 + 1;
  }
  goto joined_r0x97b7c0f8;
}

/* _PPParserScopeAddMacro @ 0x97b7ce10 (52 bytes) */
int _PPParserScopeAddMacro(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    iVar1 = param_2;
  }
  *(int *)(param_1 + 8) = iVar1;
  if (*(int *)(param_1 + 0xc) != 0) {
    *(int *)(*(int *)(param_1 + 0xc) + 0x1c) = param_2;
    *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(param_1 + 0xc);
  }
  *(int *)(param_1 + 0xc) = param_2;
  return;
}

/* _PPParserAddScope @ 0x97b7ce44 (60 bytes) */
int _PPParserAddScope(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x448);
  if (*(int *)(param_1 + 0x448) == 0) {
    iVar1 = param_2;
  }
  *(int *)(param_1 + 0x448) = iVar1;
  if (*(int *)(param_1 + 0x44c) != 0) {
    *(int *)(*(int *)(param_1 + 0x44c) + 0x20) = param_2;
    *(undefined4 *)(param_2 + 0x1c) = *(undefined4 *)(param_1 + 0x44c);
  }
  *(int *)(param_1 + 0x44c) = param_2;
  *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(param_1 + 0x1c);
  return;
}

/* _PPParserInit @ 0x97b7ce80 (4 bytes) */
int _PPParserInit()
{
  return;
}

/* _PPParserAttachString @ 0x97b7ce84 (228 bytes) */
int _PPParserAttachString(param_1, param_2, param_3)
  int *param_1;
  char *param_2;
  int param_3;
{
  int iVar1;
  void *pvVar2;
  size_t sVar3;
  
  if ((void *)*param_1 == (void *)0x0) {
    if (param_2 != (char *)0x0) {
      if (param_3 == 0) {
        sVar3 = _strlen(param_2);
        pvVar2 = _calloc(sVar3 + 1,1);
        *param_1 = (int)pvVar2;
        _memmove(pvVar2,param_2,sVar3);
      }
      else {
        iVar1 = ((int (*)())_PPParserPreprocessString)(param_1,param_2,1);
        *param_1 = iVar1;
      }
      sVar3 = _strlen((char *)*param_1);
      iVar1 = 0;
      param_1[2] = 0;
      param_1[1] = sVar3;
      if (sVar3 != 0) {
        do {
          if (*(char *)(*param_1 + iVar1) == '\n') {
            param_1[2] = param_1[2] + 1;
          }
          iVar1 = iVar1 + 1;
          sVar3 = sVar3 - 1;
        } while (sVar3 != 0);
      }
    }
  }
  else {
    _free((void *)*param_1);
    param_1[1] = 0;
    *param_1 = 0;
  }
  return;
}

/* _PPStreamCreate @ 0x97b7cf68 (152 bytes) */
int _PPStreamCreate()
{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = _calloc(0x34,1);
  uVar2 = ((int (*)())_PPStreamChunkListCreate)();
  *(undefined4 *)((int)pvVar1 + 4) = uVar2;
  uVar2 = ((int (*)())_PPStreamChunkListCreate)();
  *(undefined4 *)((int)pvVar1 + 8) = uVar2;
  uVar2 = ((int (*)())_PPStreamChunkListCreate)();
  *(undefined4 *)((int)pvVar1 + 0xc) = uVar2;
  uVar2 = ((int (*)())_PPStreamChunkListCreate)();
  *(undefined4 *)((int)pvVar1 + 0x10) = uVar2;
  uVar2 = ((int (*)())_PPStreamChunkListCreate)();
  *(undefined4 *)((int)pvVar1 + 0x14) = uVar2;
  uVar2 = ((int (*)())_PPStreamChunkListCreate)();
  *(undefined4 *)((int)pvVar1 + 0x18) = uVar2;
  uVar2 = ((int (*)())_PPStreamChunkListCreate)();
  *(undefined4 *)((int)pvVar1 + 0x1c) = uVar2;
  uVar2 = ((int (*)())_PPStreamChunkListCreate)();
  *(undefined4 *)((int)pvVar1 + 0x20) = uVar2;
  uVar2 = ((int (*)())_PPStreamChunkListCreate)();
  *(undefined4 *)((int)pvVar1 + 0x24) = uVar2;
  uVar2 = ((int (*)())_PPStreamChunkListCreate)();
  *(undefined4 *)((int)pvVar1 + 0x2c) = uVar2;
  uVar2 = ((int (*)())_PPStreamChunkListCreate)();
  *(undefined4 *)((int)pvVar1 + 0x28) = uVar2;
  uVar2 = ((int (*)())_PPStreamChunkListCreate)();
  *(undefined4 *)((int)pvVar1 + 0x30) = uVar2;
  return pvVar1;
}

/* _PPStreamChunkListCreate @ 0x97b7d000 (12 bytes) */
int _PPStreamChunkListCreate()
{
  void *pvVar1;
  
  pvVar1 = _calloc(0xc,1);
  return pvVar1;
}

/* _PPParserAttachStream @ 0x97b7d00c (100 bytes) */
int _PPParserAttachStream(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x448);
  if (*(int *)(param_1 + 0x1c) != 0) {
    _PPStreamFree(*(int *)(param_1 + 0x1c));
  }
  *(undefined4 *)(param_1 + 0x1c) = param_2;
  for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x20)) {
    ((int (*)())_PPParserScopeAttachStream)(iVar1,param_2);
  }
  return;
}

/* _PPParserScopeAttachStream @ 0x97b7d070 (36 bytes) */
int _PPParserScopeAttachStream(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = *param_1;
  param_1[6] = param_2;
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
int _PPParserParse(param_1)
  int param_1;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if ((*(byte *)(param_1 + 0x441) & 2) == 0) {
    iVar3 = ((int (*)())_PPParserParseVersion)(param_1);
  }
  while (iVar3 == 0) {
    iVar3 = ((int (*)())_PPParserParseOption)(param_1);
  }
  if (iVar3 == 3) {
    do {
      iVar3 = ((int (*)())_PPParserParseStatement)(param_1);
    } while (iVar3 == 0);
  }
  bVar1 = false;
  if ((*(byte *)(param_1 + 0x441) & 2) == 0) {
    if (iVar3 == 6) {
      iVar3 = ((int (*)())_PPParserParseEnd)(param_1);
    }
    if (iVar3 == 1) {
      iVar3 = 0x2d;
    }
    if (iVar3 != 0) goto LAB_97b7d180;
    bVar1 = true;
    if (((*(uint *)(param_1 + 0x48c) & 0x10) != 0) &&
       (iVar2 = _PPStreamResolveBranches(*(undefined4 *)(param_1 + 0x1c)), iVar2 != 0)) {
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
    _PPParserBuildErrorString(param_1,iVar3,0);
    iVar2 = iVar3;
  }
  return iVar2;
}

/* _PPParserParseVersion @ 0x97b7d1bc (204 bytes) */
int _PPParserParseVersion(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  undefined1 auStack_110 [264];
  
  iVar2 = ((int (*)())_PPParserGetPart)(param_1,auStack_110,0);
  uVar1 = 4;
  if (iVar2 != 0) {
    if ((*(uint *)(param_1 + 0x48c) & 2) == 0) {
      iVar2 = _memcmp(auStack_110,"!!ARBvp1.0",0xb);
      if (iVar2 != 0) {
        return 4;
      }
      *(undefined4 *)(param_1 + 0x48c) = 0;
      **(undefined4 **)(param_1 + 0x1c) = 0x8620;
    }
    else {
      iVar2 = _memcmp(auStack_110,"!!ARBfp1.0",0xb);
      if (iVar2 != 0) {
        return 4;
      }
      *(undefined4 *)(param_1 + 0x48c) = 2;
      **(undefined4 **)(param_1 + 0x1c) = 0x8804;
    }
    uVar1 = 0;
  }
  return uVar1;
}

/* _PPParserGetPart @ 0x97b7d288 (368 bytes) */
int _PPParserGetPart(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  size_t sVar1;
  int iVar2;
  size_t sVar3;
  int iVar4;
  size_t sVar5;
  void *pvVar6;
  uint uVar7;
  undefined1 auStack_120 [260];
  
  sVar1 = param_1[3];
  iVar2 = param_1[4];
  uVar7 = 0;
  do {
    iVar4 = ((int (*)())_PPParserGetCharacter)(param_1,param_2 + uVar7);
    if ((iVar4 != 0) || (*(char *)(param_2 + uVar7) == ' ')) break;
    uVar7 = uVar7 + 1;
  } while (uVar7 < 0xff);
  *(undefined1 *)(param_2 + uVar7) = 0;
  if ((uVar7 == 0) || (uVar7 == 0xff)) {
    uVar7 = 0;
  }
  else if (((param_3 != 0) && (iVar4 = ((int (*)())_PPParserScopeFindMacro)(param_1[0x113],param_2), iVar4 != 0))
          && (*(int *)(iVar4 + 8) == 0)) {
    sVar5 = _PPParserMacroGetReplaceString(iVar4,param_1[0x123],0,auStack_120);
    sVar3 = (param_1[1] + sVar5) - uVar7;
    pvVar6 = _calloc(sVar3,1);
    _memmove(pvVar6,(void *)*param_1,sVar1);
    _memmove((void *)((int)pvVar6 + sVar1),auStack_120,sVar5);
    _memmove((void *)((int)pvVar6 + sVar5 + sVar1),(void *)(*param_1 + param_1[3]),
             param_1[1] - param_1[3]);
    _free((void *)*param_1);
    param_1[1] = sVar3 - 1;
    *param_1 = (int)pvVar6;
    param_1[3] = sVar1;
    param_1[4] = iVar2;
    uVar7 = ((int (*)())_PPParserGetPart)(param_1,param_2,0);
  }
  return uVar7;
}

/* _PPParserGetCharacter @ 0x97b7d3f8 (144 bytes) */
int _PPParserGetCharacter(param_1, param_2)
  int *param_1;
  char *param_2;
{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  
  bVar1 = false;
  iVar3 = param_1[3];
  uVar2 = 1;
  if (iVar3 != param_1[1]) {
    while( true ) {
      *param_2 = *(char *)(*param_1 + iVar3);
      iVar3 = param_1[3] + 1;
      param_1[3] = iVar3;
      if (*param_2 != '\n') break;
      param_1[4] = param_1[4] + 1;
      if (iVar3 == param_1[1]) {
        *param_2 = ' ';
        break;
      }
      bVar1 = true;
    }
    if (bVar1) {
      *param_2 = ' ';
      param_1[3] = param_1[3] + -1;
    }
    uVar2 = 0;
  }
  return uVar2;
}

/* _PPParserParseOption @ 0x97b7d488 (184 bytes) */
int _PPParserParseOption(param_1)
  undefined4 param_1;
{
  int iVar1;
  int iVar2;
  char local_110 [264];
  
  iVar1 = ((int (*)())_PPParserGetPart)(param_1,local_110,0);
  iVar2 = 1;
  if (iVar1 != 0) {
    iVar1 = _memcmp(local_110,"OPTION",7);
    if (iVar1 == 0) {
      iVar2 = ((int (*)())_PPParserParseOptionIdentifier)(param_1);
      if (iVar2 == 0) {
        iVar1 = ((int (*)())_PPParserGetPart)(param_1,local_110,0);
        iVar2 = 0x2d;
        if ((iVar1 != 0) && (iVar2 = 0x1e, local_110[0] == ';')) {
          iVar2 = 0;
        }
      }
    }
    else {
      ((int (*)())_PPParserReturnPart)(param_1);
      iVar2 = 3;
    }
  }
  return iVar2;
}

/* _PPParserParseOptionIdentifier @ 0x97b7d540 (916 bytes) */
int _PPParserParseOptionIdentifier(param_1)
  int param_1;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined1 auStack_120 [256];
  undefined4 local_20;
  uint local_1c;
  
  iVar1 = ((int (*)())_PPParserGetPart)(param_1,auStack_120,0);
  if (iVar1 == 0) {
    return 0x2d;
  }
  if ((*(uint *)(param_1 + 0x48c) & 2) == 0) {
    iVar1 = _memcmp(auStack_120,"ARB_position_invariant",0x17);
    if (iVar1 == 0) {
      ((int (*)())_PPStreamAddOption)(*(undefined4 *)(param_1 + 0x1c),0);
      local_1c = *(uint *)(param_1 + 0x24) & 0xffff;
      *(uint *)(param_1 + 0x24) = *(uint *)(param_1 + 0x24) + 1;
      local_20 = 0x10000;
      ((int (*)())_PPStreamAddAttribBinding)(*(undefined4 *)(param_1 + 0x1c),&local_20);
      *(byte *)(param_1 + 0x442) = *(byte *)(param_1 + 0x442) | 1;
      return 0;
    }
    iVar1 = _memcmp(auStack_120,"NV_vertex_program2",0x13);
    if (iVar1 == 0) {
      uVar2 = *(undefined4 *)(param_1 + 0x1c);
      *(undefined4 *)(param_1 + 0x48c) = 0x31;
      uVar3 = 10;
      goto LAB_97b7d8b8;
    }
    iVar1 = _memcmp(auStack_120,"NV_vertex_program3",0x13);
    if (iVar1 == 0) {
      uVar2 = *(undefined4 *)(param_1 + 0x1c);
      *(undefined4 *)(param_1 + 0x48c) = 0x34;
      uVar3 = 0xb;
      goto LAB_97b7d8b8;
    }
  }
  else {
    iVar1 = _memcmp(auStack_120,"ARB_fog_exp",0xc);
    if (iVar1 == 0) {
      if (1 < *(byte *)(param_1 + 0x443)) {
        return 0x27;
      }
      uVar2 = *(undefined4 *)(param_1 + 0x1c);
      *(undefined1 *)(param_1 + 0x443) = 1;
      uVar3 = 1;
      goto LAB_97b7d8b8;
    }
    iVar1 = _memcmp(auStack_120,"ARB_fog_exp2",0xd);
    if (iVar1 == 0) {
      if ((*(char *)(param_1 + 0x443) != '\0') && (*(char *)(param_1 + 0x443) != '\x02')) {
        return 0x27;
      }
      uVar2 = *(undefined4 *)(param_1 + 0x1c);
      *(undefined1 *)(param_1 + 0x443) = 2;
      uVar3 = 2;
      goto LAB_97b7d8b8;
    }
    iVar1 = _memcmp(auStack_120,"ARB_fog_linear",0xf);
    if (iVar1 == 0) {
      if ((*(char *)(param_1 + 0x443) != '\0') && (*(char *)(param_1 + 0x443) != '\x03')) {
        return 0x27;
      }
      uVar2 = *(undefined4 *)(param_1 + 0x1c);
      *(undefined1 *)(param_1 + 0x443) = 3;
      uVar3 = 3;
      goto LAB_97b7d8b8;
    }
    iVar1 = _memcmp(auStack_120,"ARB_precision_hint_fastest",0x1b);
    if (iVar1 == 0) {
      if ((*(char *)(param_1 + 0x444) != '\0') && (*(char *)(param_1 + 0x444) != '\x04')) {
        return 0x27;
      }
      uVar2 = *(undefined4 *)(param_1 + 0x1c);
      *(undefined1 *)(param_1 + 0x444) = 4;
      uVar3 = 4;
      goto LAB_97b7d8b8;
    }
    iVar1 = _memcmp(auStack_120,"ARB_precision_hint_nicest",0x1a);
    if (iVar1 == 0) {
      if ((*(char *)(param_1 + 0x444) != '\0') && (*(char *)(param_1 + 0x444) != '\x05')) {
        return 0x27;
      }
      uVar2 = *(undefined4 *)(param_1 + 0x1c);
      *(undefined1 *)(param_1 + 0x444) = 5;
      uVar3 = 5;
      goto LAB_97b7d8b8;
    }
    iVar1 = _memcmp(auStack_120,"NV_fragment_program",0x14);
    if (iVar1 == 0) {
      uVar2 = *(undefined4 *)(param_1 + 0x1c);
      *(undefined4 *)(param_1 + 0x48c) = 0x33;
      uVar3 = 8;
      goto LAB_97b7d8b8;
    }
    iVar1 = _memcmp(auStack_120,"NV_fragment_program2",0x15);
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x48c) = 0x36;
      ((int (*)())_PPStreamAddOption)(*(undefined4 *)(param_1 + 0x1c),9);
      _PPParserDeclareNVAddressRegisters(param_1);
      return 0;
    }
    iVar1 = _memcmp(auStack_120,"ARB_fragment_program_shadow",0x1c);
    if (iVar1 == 0) {
      uVar2 = *(undefined4 *)(param_1 + 0x1c);
      uVar3 = 0xd;
      goto LAB_97b7d8b8;
    }
    iVar1 = _memcmp(auStack_120,"ARB_draw_buffers",0x11);
    if (iVar1 == 0) {
      uVar2 = *(undefined4 *)(param_1 + 0x1c);
      *(undefined1 *)(param_1 + 0x445) = 1;
      uVar3 = 0xc;
      goto LAB_97b7d8b8;
    }
  }
  iVar1 = _memcmp(auStack_120,"APPLE_no_runtime_compile",0x19);
  if (iVar1 == 0) {
    uVar2 = *(undefined4 *)(param_1 + 0x1c);
    uVar3 = 6;
  }
  else {
    iVar1 = _memcmp(auStack_120,"APPLE_no_altivec",0x11);
    if (iVar1 != 0) {
      return 5;
    }
    uVar2 = *(undefined4 *)(param_1 + 0x1c);
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
  undefined1 *puVar1;
  undefined4 uVar2;
  
  puVar1 = _calloc(0x14,1);
  uVar2 = *(undefined4 *)(param_1 + 0x30);
  *puVar1 = 7;
  puVar1[0xf] = (undefined1)param_2;
  ((int (*)())_PPStreamChunkListAddChunk)(uVar2,puVar1);
  return;
}

/* _PPStreamChunkListAddChunk @ 0x97b7d924 (72 bytes) */
int _PPStreamChunkListAddChunk(param_1, param_2)
  int *param_1;
  int param_2;
{
  if (*param_1 == 0) {
    *param_1 = param_2;
    *(undefined4 *)(param_2 + 4) = 0;
  }
  if (param_1[1] != 0) {
    *(int *)(param_1[1] + 8) = param_2;
    *(int *)(param_2 + 4) = param_1[1];
  }
  *(undefined4 *)(param_2 + 8) = 0;
  param_1[1] = param_2;
  param_1[2] = param_1[2] + 1;
  return;
}

/* _PPStreamAddAttribBinding @ 0x97b7d96c (92 bytes) */
int _PPStreamAddAttribBinding(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined1 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  puVar1 = _calloc(0x14,1);
  uVar4 = param_2[1];
  uVar2 = *(undefined4 *)(param_1 + 0x18);
  uVar3 = *param_2;
  *puVar1 = 2;
  *(undefined4 *)(puVar1 + 0xc) = uVar3;
  *(undefined4 *)(puVar1 + 0x10) = uVar4;
  ((int (*)())_PPStreamChunkListAddChunk)(uVar2,puVar1);
  return;
}

/* _PPParserReturnPart @ 0x97b7d9c8 (132 bytes) */
int _PPParserReturnPart(param_1)
  undefined4 param_1;
{
  int iVar1;
  int iVar2;
  char local_20 [20];
  
  iVar1 = ((int (*)())_PPParserReturnCharacter)(param_1,local_20);
  iVar2 = 0;
  if (iVar1 == 0) {
    iVar2 = 0;
    while (iVar1 = ((int (*)())_PPParserReturnCharacter)(param_1,local_20), iVar1 == 0) {
      if (local_20[0] == ' ') {
        ((int (*)())_PPParserGetCharacter)(param_1,local_20);
        return iVar2;
      }
      iVar2 = iVar2 + 1;
    }
  }
  return iVar2;
}

/* _PPParserReturnCharacter @ 0x97b7da4c (144 bytes) */
int _PPParserReturnCharacter(param_1, param_2)
  int *param_1;
  char *param_2;
{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = param_1[3];
  bVar1 = false;
  uVar3 = 1;
  if (iVar2 != 0) {
    while( true ) {
      *param_2 = *(char *)(*param_1 + iVar2 + -1);
      iVar2 = param_1[3] + -1;
      param_1[3] = iVar2;
      if (*param_2 != '\n') break;
      param_1[4] = param_1[4] + -1;
      if (iVar2 == 0) {
        *param_2 = ' ';
        break;
      }
      bVar1 = true;
    }
    if (bVar1) {
      *param_2 = ' ';
      param_1[3] = param_1[3] + 1;
    }
    uVar3 = 0;
  }
  return uVar3;
}

/* _PPParserParseStatement @ 0x97b7dadc (2176 bytes) */
int _PPParserParseStatement(param_1)
  int param_1;
{
  char *pcVar1;
  int iVar2;
  int iVar3;
  size_t sVar4;
  size_t sVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 in_r9;
  uint uVar10;
  int iVar11;
  int *piVar12;
  char acStack_140 [256];
  char acStack_40 [20];
  
  iVar2 = ((int (*)())_PPParserGetPart)(param_1,acStack_140,0);
  iVar11 = 0;
  if (iVar2 == 0) {
    return 1;
  }
  if ((*(uint *)(param_1 + 0x48c) & 0x22) != 0) {
    iVar3 = _memcmp(acStack_140,"LONG",5);
    if (iVar3 == 0) {
      iVar11 = 1;
    }
    else {
      iVar3 = _memcmp(acStack_140,"SHORT",6);
      if (iVar3 != 0) goto LAB_97b7db80;
      iVar11 = 2;
    }
    iVar2 = ((int (*)())_PPParserGetPart)(param_1,acStack_140,0);
    if (iVar2 == 0) {
      return 1;
    }
  }
LAB_97b7db80:
  iVar3 = _memcmp(acStack_140,"TEMP",5);
  if (iVar3 == 0) {
    iVar3 = _PPParserParseTempDeclaration(param_1,iVar11);
  }
  else {
    iVar3 = _memcmp(acStack_140,"OUTPUT",7);
    if (iVar3 == 0) {
      iVar3 = ((int (*)())_PPParserParseOutputDeclaration)(param_1,iVar11);
    }
    else {
      iVar3 = 0x2a;
      if (iVar11 == 0) {
        uVar10 = *(uint *)(param_1 + 0x48c);
        if (((uVar10 & 2) == 0) && (iVar11 = _memcmp(acStack_140,"ADDRESS",8), iVar11 == 0)) {
          iVar3 = _PPParserParseAddressDeclaration(param_1);
        }
        else {
          iVar11 = _memcmp(acStack_140,"PARAM",6);
          if (iVar11 == 0) {
            iVar3 = ((int (*)())_PPParserParseParameterDeclaration)(param_1);
          }
          else {
            iVar11 = _memcmp(acStack_140,"ATTRIB",7);
            if (iVar11 == 0) {
              iVar3 = ((int (*)())_PPParserParseAttributeDeclaration)(param_1);
            }
            else {
              iVar11 = _memcmp(acStack_140,"ALIAS",6);
              if (iVar11 == 0) {
                iVar3 = _PPParserParseAliasDeclaration(param_1);
              }
              else {
                iVar11 = _memcmp(acStack_140,"MACRO",6);
                if (iVar11 == 0) {
                  iVar3 = _PPParserParseMacroDeclaration(param_1);
                }
                else {
                  iVar11 = _memcmp(acStack_140,"BLOCK",6);
                  if (iVar11 != 0) {
                    if ((uVar10 & 2) == 0) {
                      piVar12 = &_OpsList_ARBvp10;
                    }
                    else {
                      piVar12 = &_OpsList_ARBfp10;
                    }
                    iVar11 = 0;
                    do {
                      pcVar1 = (char *)*piVar12;
                      if (pcVar1 != (char *)0x0) {
                        do {
                          iVar3 = _strcmp(acStack_140,pcVar1);
                          if (iVar3 == 0) {
                            iVar2 = piVar12[1];
                            uVar6 = 0;
                            goto LAB_97b7e2b0;
                          }
                          uVar10 = *(uint *)(param_1 + 0x48c);
                          if ((uVar10 & 0x10) != 0) {
                            _sprintf(acStack_40,"%sC",*piVar12);
                            iVar3 = _strcmp(acStack_140,acStack_40);
                            if (iVar3 != 0) {
                              uVar10 = *(uint *)(param_1 + 0x48c);
                              if (uVar10 != 0x34) goto LAB_97b7ddc8;
                              _sprintf(acStack_40,"%sC0",*piVar12);
                              iVar3 = _strcmp(acStack_140,acStack_40);
                              if (iVar3 == 0) goto LAB_97b7e228;
                              _sprintf(acStack_40,"%sC1",*piVar12);
                              iVar3 = _strcmp(acStack_140,acStack_40);
                              if (iVar3 != 0) {
                                uVar10 = *(uint *)(param_1 + 0x48c);
                                goto LAB_97b7ddc8;
                              }
                              iVar2 = piVar12[1];
                              uVar8 = 0;
LAB_97b7e28c:
                              uVar7 = 1;
                              uVar6 = 0;
                              uVar9 = 1;
                              goto LAB_97b7e334;
                            }
LAB_97b7e228:
                            iVar2 = piVar12[1];
                            uVar6 = 0;
                            goto LAB_97b7e234;
                          }
LAB_97b7ddc8:
                          if ((uVar10 & 2) != 0) {
                            _sprintf(acStack_40,"%s_SAT",*piVar12);
                            iVar3 = _strcmp(acStack_140,acStack_40);
                            if (iVar3 == 0) {
                              iVar2 = piVar12[1];
                              uVar6 = 0;
                              goto LAB_97b7e260;
                            }
                            if ((*(uint *)(param_1 + 0x48c) & 0x10) == 0) goto LAB_97b7e11c;
                            _sprintf(acStack_40,"%sC_SAT",*piVar12);
                            iVar3 = _strcmp(acStack_140,acStack_40);
                            if (iVar3 == 0) {
LAB_97b7e268:
                              iVar2 = piVar12[1];
                              uVar6 = 0;
                              goto LAB_97b7e328;
                            }
                            if (*(int *)(param_1 + 0x48c) == 0x34) {
                              _sprintf(acStack_40,"%sC0_SAT",*piVar12);
                              iVar3 = _strcmp(acStack_140,acStack_40);
                              if (iVar3 == 0) goto LAB_97b7e268;
                              _sprintf(acStack_40,"%sC1_SAT",*piVar12);
                              iVar3 = _strcmp(acStack_140,acStack_40);
                              if (iVar3 == 0) {
                                iVar2 = piVar12[1];
                                uVar8 = 1;
                                goto LAB_97b7e28c;
                              }
                            }
                            sVar4 = _strlen(acStack_140);
                            sVar5 = _strlen((char *)*piVar12);
                            if (sVar4 == sVar5 + 1) {
                              _sprintf(acStack_40,"%sR",*piVar12);
                              iVar3 = _strcmp(acStack_140,acStack_40);
                              if (iVar3 == 0) {
                                iVar2 = piVar12[1];
                                uVar6 = 1;
                              }
                              else {
                                _sprintf(acStack_40,"%sH",*piVar12);
                                iVar3 = _strcmp(acStack_140,acStack_40);
                                if (iVar3 == 0) {
                                  iVar2 = piVar12[1];
                                  uVar6 = 2;
                                }
                                else {
                                  _sprintf(acStack_40,"%sX",*piVar12);
                                  iVar3 = _strcmp(acStack_140,acStack_40);
                                  if (iVar3 != 0) goto LAB_97b7e11c;
                                  iVar2 = piVar12[1];
                                  uVar6 = 3;
                                }
                              }
LAB_97b7e2b0:
                              uVar7 = 0;
LAB_97b7e2b4:
                              uVar8 = 0;
                            }
                            else {
                              sVar4 = _strlen(acStack_140);
                              sVar5 = _strlen((char *)*piVar12);
                              if (sVar4 == sVar5 + 2) {
                                _sprintf(acStack_40,"%sRC",*piVar12);
                                iVar3 = _strcmp(acStack_140,acStack_40);
                                if (iVar3 == 0) {
                                  iVar2 = piVar12[1];
                                  uVar6 = 1;
                                }
                                else {
                                  _sprintf(acStack_40,"%sHC",*piVar12);
                                  iVar3 = _strcmp(acStack_140,acStack_40);
                                  if (iVar3 == 0) {
                                    iVar2 = piVar12[1];
                                    uVar6 = 2;
                                  }
                                  else {
                                    _sprintf(acStack_40,"%sXC",*piVar12);
                                    iVar3 = _strcmp(acStack_140,acStack_40);
                                    if (iVar3 != 0) goto LAB_97b7e11c;
                                    iVar2 = piVar12[1];
                                    uVar6 = 3;
                                  }
                                }
LAB_97b7e234:
                                uVar7 = 1;
                                goto LAB_97b7e2b4;
                              }
                              sVar4 = _strlen(acStack_140);
                              sVar5 = _strlen((char *)*piVar12);
                              if (sVar4 == sVar5 + 5) {
                                _sprintf(acStack_40,"%sR_SAT",*piVar12);
                                iVar3 = _strcmp(acStack_140,acStack_40);
                                if (iVar3 == 0) {
                                  iVar2 = piVar12[1];
                                  uVar6 = 1;
                                }
                                else {
                                  _sprintf(acStack_40,"%sH_SAT",*piVar12);
                                  iVar3 = _strcmp(acStack_140,acStack_40);
                                  if (iVar3 == 0) {
                                    iVar2 = piVar12[1];
                                    uVar6 = 2;
                                  }
                                  else {
                                    _sprintf(acStack_40,"%sX_SAT",*piVar12);
                                    iVar3 = _strcmp(acStack_140,acStack_40);
                                    if (iVar3 != 0) goto LAB_97b7e11c;
                                    iVar2 = piVar12[1];
                                    uVar6 = 3;
                                  }
                                }
LAB_97b7e260:
                                uVar7 = 0;
                              }
                              else {
                                sVar4 = _strlen(acStack_140);
                                sVar5 = _strlen((char *)*piVar12);
                                if (sVar4 != sVar5 + 6) goto LAB_97b7e11c;
                                _sprintf(acStack_40,"%sRC_SAT",*piVar12);
                                iVar3 = _strcmp(acStack_140,acStack_40);
                                if (iVar3 == 0) {
                                  iVar2 = piVar12[1];
                                  uVar6 = 1;
                                }
                                else {
                                  _sprintf(acStack_40,"%sHC_SAT",*piVar12);
                                  iVar3 = _strcmp(acStack_140,acStack_40);
                                  if (iVar3 == 0) {
                                    iVar2 = piVar12[1];
                                    uVar6 = 2;
                                  }
                                  else {
                                    _sprintf(acStack_40,"%sXC_SAT",*piVar12);
                                    iVar3 = _strcmp(acStack_140,acStack_40);
                                    if (iVar3 != 0) goto LAB_97b7e11c;
                                    iVar2 = piVar12[1];
                                    uVar6 = 3;
                                  }
                                }
LAB_97b7e328:
                                uVar7 = 1;
                              }
                              uVar8 = 1;
                            }
                            uVar9 = 0;
LAB_97b7e334:
                            iVar2 = ((int (*)())_PPParserParseOperation)(param_1,iVar2,uVar6,uVar7,uVar8,uVar9,in_r9);
                            return iVar2;
                          }
LAB_97b7e11c:
                          piVar12 = piVar12 + 2;
                          pcVar1 = (char *)*piVar12;
                        } while (pcVar1 != (char *)0x0);
                        uVar10 = *(uint *)(param_1 + 0x48c);
                      }
                      if (uVar10 == 0x34) {
                        if (iVar11 == 0) {
LAB_97b7e160:
                          piVar12 = (int *)&_OpsList_NVvp20;
                        }
                        else {
                          if (iVar11 != 1) goto LAB_97b7e1b4;
                          piVar12 = &_OpsList_NVvp30;
                        }
                      }
                      else {
                        if (uVar10 == 0x31) {
                          if (iVar11 == 0) goto LAB_97b7e160;
                          goto LAB_97b7e1b4;
                        }
                        if (uVar10 == 0x33) {
                          if (iVar11 != 0) goto LAB_97b7e1b4;
                        }
                        else {
                          if (uVar10 != 0x36) {
LAB_97b7e1b4:
                            if (((uVar10 & 0x10) != 0) &&
                               (iVar2 = _PPParserParseLabel(param_1,acStack_140,iVar2), iVar2 != 3))
                            {
                              return iVar2;
                            }
                            iVar2 = ((int (*)())_PPParserScopeFindMacro)(*(undefined4 *)(param_1 + 0x44c),acStack_140);
                            if (iVar2 != 0) {
                              iVar2 = _PPParserExpandMacro(param_1,iVar2);
                              return iVar2;
                            }
                            iVar2 = _memcmp(acStack_140,"OPTION",7);
                            if (iVar2 == 0) {
                              return 8;
                            }
                            ((int (*)())_PPParserReturnPart)(param_1);
                            return 6;
                          }
                          if (iVar11 != 0) {
                            if (iVar11 == 1) {
                              piVar12 = (int *)&_OpsList_NVfp20;
                              goto LAB_97b7e1ac;
                            }
                            goto LAB_97b7e1b4;
                          }
                        }
                        piVar12 = (int *)&_OpsList_NVfp10;
                      }
LAB_97b7e1ac:
                      iVar11 = iVar11 + 1;
                    } while( true );
                  }
                  iVar3 = _PPParserParseBlock(param_1);
                }
              }
            }
          }
        }
      }
    }
  }
  return iVar3;
}

/* _PPParserParseParameterDeclaration @ 0x97b7e35c (372 bytes) */
int _PPParserParseParameterDeclaration(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  char local_130 [256];
  undefined4 local_30 [7];
  
  local_30[0] = 1;
  iVar1 = ((int (*)())_PPParserGetPart)(param_1,local_130,0);
  uVar4 = 0;
  iVar2 = 0x2d;
  if (iVar1 != 0) {
    iVar1 = ((int (*)())_PPParserValidateName)(param_1,local_130);
    iVar2 = 0x12;
    if (iVar1 == 0) {
      iVar1 = ((int (*)())_PPParserIdentifierCreate)();
      ((int (*)())_PPParserIdentifierSetName)(iVar1,local_130);
      *(undefined4 *)(iVar1 + 0xc) = 2;
      iVar2 = ((int (*)())_PPParserScopeAddIdentifier)(*(undefined4 *)(param_1 + 0x44c),iVar1);
      if (iVar2 == 0) {
        iVar3 = ((int (*)())_PPParserGetPart)(param_1,local_130,0);
        iVar2 = 0x2d;
        if (iVar3 != 0) {
          if (local_130[0] == '[') {
            ((int (*)())_PPParserReturnPart)(param_1);
            iVar2 = _PPParserParseDefaultArray(param_1,local_30);
            if (iVar2 != 0) {
              return iVar2;
            }
            *(undefined1 *)(iVar1 + 0x10) = 1;
            iVar2 = ((int (*)())_PPParserGetPart)(param_1,local_130,0);
            if (iVar2 == 0) {
              return 0x2d;
            }
            uVar4 = 1;
          }
          iVar2 = 10;
          if (local_130[0] == '=') {
            *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(param_1 + 0x20);
            iVar2 = ((int (*)())_PPParserParseParamBinding)(param_1,uVar4,local_30);
            if (iVar2 == 0) {
              *(undefined4 *)(iVar1 + 4) = local_30[0];
              iVar1 = ((int (*)())_PPParserGetPart)(param_1,local_130,0);
              iVar2 = 0x2d;
              if ((iVar1 != 0) && (iVar2 = 10, local_130[0] == ';')) {
                iVar2 = 0;
              }
            }
          }
        }
      }
      else {
        _PPParserIdentifierFree(iVar1);
        iVar2 = 0x1c;
      }
    }
  }
  return iVar2;
}

/* _PPParserValidateName @ 0x97b7e4d0 (1360 bytes) */
int _PPParserValidateName(param_1, param_2)
  int param_1;
  char *param_2;
{
  char *pcVar1;
  uint uVar2;
  int iVar3;
  size_t sVar4;
  int iVar5;
  size_t sVar6;
  undefined4 *puVar7;
  int *piVar8;
  char acStack_30 [24];
  
  if ((*(uint *)(param_1 + 0x48c) & 2) == 0) {
    puVar7 = &_vpDclList;
  }
  else {
    puVar7 = &_fpDclList;
  }
  pcVar1 = (char *)*puVar7;
  while (pcVar1 != (char *)0x0) {
    iVar3 = _strcmp(param_2,pcVar1);
    if (iVar3 == 0) {
      return 0x12;
    }
    puVar7 = puVar7 + 2;
    pcVar1 = (char *)*puVar7;
  }
  sVar4 = _strlen(param_2);
  uVar2 = *(uint *)(param_1 + 0x48c);
  if ((((uVar2 == 0) || (uVar2 == 2)) && (1 < sVar4 - 3)) && ((sVar4 != 7 && (sVar4 != 8)))) {
    return 0;
  }
  if ((uVar2 & 2) == 0) {
    piVar8 = &_OpsList_ARBvp10;
  }
  else {
    piVar8 = &_OpsList_ARBfp10;
  }
  iVar3 = 0;
  do {
    pcVar1 = (char *)*piVar8;
    if (pcVar1 != (char *)0x0) {
      do {
        iVar5 = _strcmp(param_2,pcVar1);
        if (iVar5 == 0) {
          return 0x12;
        }
        uVar2 = *(uint *)(param_1 + 0x48c);
        if ((uVar2 & 0x10) != 0) {
          _sprintf(acStack_30,"%sC",*piVar8);
          iVar5 = _strcmp(param_2,acStack_30);
          if (iVar5 == 0) {
            return 0x12;
          }
          uVar2 = *(uint *)(param_1 + 0x48c);
          if (uVar2 == 0x34) {
            _sprintf(acStack_30,"%sC0",*piVar8);
            iVar5 = _strcmp(param_2,acStack_30);
            if (iVar5 == 0) {
              return 0x12;
            }
            _sprintf(acStack_30,"%sC1",*piVar8);
            iVar5 = _strcmp(param_2,acStack_30);
            if (iVar5 == 0) {
              return 0x12;
            }
            uVar2 = *(uint *)(param_1 + 0x48c);
          }
        }
        if ((uVar2 & 2) != 0) {
          _sprintf(acStack_30,"%s_SAT",*piVar8);
          iVar5 = _strcmp(param_2,acStack_30);
          if (iVar5 == 0) {
            return 0x12;
          }
          if ((*(uint *)(param_1 + 0x48c) & 0x10) != 0) {
            _sprintf(acStack_30,"%sC_SAT",*piVar8);
            iVar5 = _strcmp(param_2,acStack_30);
            if (iVar5 == 0) {
              return 0x12;
            }
            if (*(int *)(param_1 + 0x48c) == 0x34) {
              _sprintf(acStack_30,"%sC0_SAT",*piVar8);
              iVar5 = _strcmp(param_2,acStack_30);
              if (iVar5 == 0) {
                return 0x12;
              }
              _sprintf(acStack_30,"%sC1_SAT",*piVar8);
              iVar5 = _strcmp(param_2,acStack_30);
              if (iVar5 == 0) {
                return 0x12;
              }
            }
            sVar4 = _strlen(param_2);
            sVar6 = _strlen((char *)*piVar8);
            if (sVar4 == sVar6 + 1) {
              _sprintf(acStack_30,"%sR",*piVar8);
              iVar5 = _strcmp(param_2,acStack_30);
              if (iVar5 == 0) {
                return 0x12;
              }
              _sprintf(acStack_30,"%sH",*piVar8);
              iVar5 = _strcmp(param_2,acStack_30);
              if (iVar5 == 0) {
                return 0x12;
              }
              iVar5 = *piVar8;
              pcVar1 = "%sX";
            }
            else {
              sVar4 = _strlen(param_2);
              sVar6 = _strlen((char *)*piVar8);
              if (sVar4 == sVar6 + 2) {
                _sprintf(acStack_30,"%sRC",*piVar8);
                iVar5 = _strcmp(param_2,acStack_30);
                if (iVar5 == 0) {
                  return 0x12;
                }
                _sprintf(acStack_30,"%sHC",*piVar8);
                iVar5 = _strcmp(param_2,acStack_30);
                if (iVar5 == 0) {
                  return 0x12;
                }
                iVar5 = *piVar8;
                pcVar1 = "%sXC";
              }
              else {
                sVar4 = _strlen(param_2);
                sVar6 = _strlen((char *)*piVar8);
                if (sVar4 == sVar6 + 5) {
                  _sprintf(acStack_30,"%sR_SAT",*piVar8);
                  iVar5 = _strcmp(param_2,acStack_30);
                  if (iVar5 == 0) {
                    return 0x12;
                  }
                  _sprintf(acStack_30,"%sH_SAT",*piVar8);
                  iVar5 = _strcmp(param_2,acStack_30);
                  if (iVar5 == 0) {
                    return 0x12;
                  }
                  iVar5 = *piVar8;
                  pcVar1 = "%sX_SAT";
                }
                else {
                  sVar4 = _strlen(param_2);
                  sVar6 = _strlen((char *)*piVar8);
                  if (sVar4 != sVar6 + 6) goto LAB_97b7e970;
                  _sprintf(acStack_30,"%sRC_SAT",*piVar8);
                  iVar5 = _strcmp(param_2,acStack_30);
                  if (iVar5 == 0) {
                    return 0x12;
                  }
                  _sprintf(acStack_30,"%sHC_SAT",*piVar8);
                  iVar5 = _strcmp(param_2,acStack_30);
                  if (iVar5 == 0) {
                    return 0x12;
                  }
                  iVar5 = *piVar8;
                  pcVar1 = "%sXC_SAT";
                }
              }
            }
            _sprintf(acStack_30,pcVar1,iVar5);
            iVar5 = _strcmp(param_2,acStack_30);
            if (iVar5 == 0) {
              return 0x12;
            }
          }
        }
LAB_97b7e970:
        piVar8 = piVar8 + 2;
        pcVar1 = (char *)*piVar8;
      } while (pcVar1 != (char *)0x0);
      uVar2 = *(uint *)(param_1 + 0x48c);
    }
    if (uVar2 == 0x34) {
      if (iVar3 == 0) {
LAB_97b7e9b4:
        piVar8 = (int *)&_OpsList_NVvp20;
      }
      else {
        if (iVar3 != 1) {
          return 0;
        }
        piVar8 = &_OpsList_NVvp30;
      }
    }
    else {
      if (uVar2 == 0x31) {
        if (iVar3 != 0) {
          return 0;
        }
        goto LAB_97b7e9b4;
      }
      if (uVar2 == 0x33) {
        if (iVar3 != 0) {
          return 0;
        }
      }
      else {
        if (uVar2 != 0x36) {
          return 0;
        }
        if (iVar3 != 0) {
          if (iVar3 != 1) {
            return 0;
          }
          piVar8 = (int *)&_OpsList_NVfp20;
          goto LAB_97b7ea00;
        }
      }
      piVar8 = (int *)&_OpsList_NVfp10;
    }
LAB_97b7ea00:
    iVar3 = iVar3 + 1;
  } while( true );
}

/* _PPParserIdentifierCreate @ 0x97b7ea20 (48 bytes) */
int _PPParserIdentifierCreate()
{
  void *pvVar1;
  
  pvVar1 = _calloc(0x24,1);
  *(undefined4 *)((int)pvVar1 + 4) = 1;
  return pvVar1;
}

/* _PPParserIdentifierSetName @ 0x97b7ea50 (124 bytes) */
int _PPParserIdentifierSetName(param_1, param_2)
  undefined4 *param_1;
  char *param_2;
{
  size_t sVar1;
  void *pvVar2;
  
  if ((void *)*param_1 != (void *)0x0) {
    _free((void *)*param_1);
    *param_1 = 0;
  }
  if (param_2 != (char *)0x0) {
    sVar1 = _strlen(param_2);
    pvVar2 = _calloc(sVar1 + 1,1);
    *param_1 = pvVar2;
    _memmove(pvVar2,param_2,sVar1);
  }
  return param_2 == (char *)0x0;
}

/* _PPParserScopeAddIdentifier @ 0x97b7eacc (124 bytes) */
int _PPParserScopeAddIdentifier(param_1, param_2)
  int *param_1;
  undefined4 *param_2;
{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = ((int (*)())_PPParserScopeFindIdentifier)(param_1,*param_2);
  uVar3 = 1;
  if (iVar2 == 0) {
    puVar1 = (undefined4 *)*param_1;
    if ((undefined4 *)*param_1 == (undefined4 *)0x0) {
      puVar1 = param_2;
    }
    *param_1 = (int)puVar1;
    if (param_1[1] != 0) {
      *(undefined4 **)(param_1[1] + 0x20) = param_2;
      param_2[7] = param_1[1];
    }
    uVar3 = 0;
    param_1[1] = (int)param_2;
    param_2[6] = param_1[6];
  }
  return uVar3;
}

/* _PPParserScopeFindIdentifier @ 0x97b7eb48 (100 bytes) */
int _PPParserScopeFindIdentifier(param_1, param_2)
  int *param_1;
  char *param_2;
{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)*param_1;
  while( true ) {
    if (puVar2 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    if (((char *)*puVar2 != (char *)0x0) && (iVar1 = _strcmp((char *)*puVar2,param_2), iVar1 == 0))
    break;
    puVar2 = (undefined4 *)puVar2[8];
  }
  return puVar2;
}

/* _PPParserParseParamBinding @ 0x97b7ebac (5900 bytes) */
int _PPParserParseParamBinding(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int *param_3;
{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  char cVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  char local_180 [256];
  undefined4 local_80;
  undefined4 local_7c;
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
  undefined4 local_40;
  uint local_3c [4];
  
  bVar1 = param_2 == 0;
  uVar3 = *(uint *)(param_1 + 0x48c);
  iVar9 = 0;
  if (!bVar1) {
    iVar5 = ((int (*)())_PPParserGetPart)(param_1,local_180,0);
    if (iVar5 == 0) {
      return 0x2d;
    }
    if (local_180[0] != '{') {
      return 10;
    }
  }
  bVar2 = ((uVar3 ^ 2) >> 1 & 1) == 0;
  local_6c = 0;
  local_70 = (uint)*(ushort *)(param_1 + 0x22);
  do {
    iVar5 = ((int (*)())_PPParserGetPart)(param_1,local_180,1);
    if (iVar5 == 0) {
      return 0x2d;
    }
    local_74 = 0;
    local_7c = (uint)*(ushort *)(param_1 + 0x22);
    local_80 = 0;
    local_78 = 0;
    iVar5 = _memcmp(local_180,"program",8);
    if (iVar5 == 0) {
      iVar5 = ((int (*)())_PPParserGetPart)(param_1,local_180,0);
      if (iVar5 == 0) {
        return 0x2d;
      }
      if (local_180[0] != '.') {
        return 10;
      }
      if (iVar5 != 1) {
        return 10;
      }
      iVar5 = ((int (*)())_PPParserGetPart)(param_1,local_180,0);
      if (iVar5 == 0) {
        return 0x2d;
      }
      iVar5 = _memcmp(local_180,"env",4);
      if (iVar5 == 0) {
        local_80 = local_80 & 0xffe0ffff | 0x20000;
        if (bVar1) {
          iVar5 = ((int (*)())_PPParserParseArray)(param_1,&local_40);
          local_3c[0] = local_40;
        }
        else {
          iVar5 = _PPParserParseRangeArray(param_1,&local_40,local_3c);
        }
        if (iVar5 != 0) {
          return iVar5;
        }
        uVar3 = local_40;
        while( true ) {
          if (*(uint *)(param_1 + 0x450) <= uVar3) {
            return 0x2e;
          }
          local_80 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_80) + 0)),(short)uVar3);
          ((int (*)())_PPStreamAddParamBinding)(*(undefined4 *)(param_1 + 0x1c),&local_80);
          if (uVar3 == local_3c[0]) break;
          iVar9 = iVar9 + 1;
          uVar3 = uVar3 + 1;
          iVar5 = *(int *)(param_1 + 0x20) + 1;
          local_7c = CONCAT22((*(unsigned short *)((unsigned char *)&(local_7c) + 0)),(short)iVar5);
          *(int *)(param_1 + 0x20) = iVar5;
        }
      }
      else {
        iVar5 = _memcmp(local_180,"local",6);
        if (iVar5 == 0) {
          local_80 = local_80 & 0xffe0ffff | 0x10000;
          if (bVar1) {
            iVar5 = ((int (*)())_PPParserParseArray)(param_1,&local_40);
            local_3c[0] = local_40;
          }
          else {
            iVar5 = _PPParserParseRangeArray(param_1,&local_40,local_3c);
          }
          if (iVar5 != 0) {
            return iVar5;
          }
          uVar3 = local_40;
          while( true ) {
            if (*(uint *)(param_1 + 0x454) <= uVar3) {
              return 0x2f;
            }
            local_80 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_80) + 0)),(short)uVar3);
            ((int (*)())_PPStreamAddParamBinding)(*(undefined4 *)(param_1 + 0x1c),&local_80);
            if (uVar3 == local_3c[0]) break;
            iVar9 = iVar9 + 1;
            uVar3 = uVar3 + 1;
            iVar5 = *(int *)(param_1 + 0x20) + 1;
            local_7c = CONCAT22((*(unsigned short *)((unsigned char *)&(local_7c) + 0)),(short)iVar5);
            *(int *)(param_1 + 0x20) = iVar5;
          }
        }
      }
    }
    else {
      iVar5 = _memcmp(local_180,"state",6);
      if (iVar5 == 0) {
        iVar5 = ((int (*)())_PPParserGetPart)(param_1,local_180,0);
        if (iVar5 == 0) {
          return 0x2d;
        }
        if (local_180[0] != '.') {
          return 10;
        }
        if (iVar5 != 1) {
          return 10;
        }
        iVar5 = ((int (*)())_PPParserGetPart)(param_1,local_180,0);
        if (iVar5 == 0) {
          return 0x2d;
        }
        iVar5 = _memcmp(local_180,"material",9);
        if (iVar5 == 0) {
          local_80 = local_80 & 0xffe0fffe | 0x50000;
          iVar5 = ((int (*)())_PPParserGetPart)(param_1,local_180,0);
          if (iVar5 == 0) {
            return 0x2d;
          }
          if (local_180[0] != '.') {
            return 10;
          }
          if (iVar5 != 1) {
            return 10;
          }
          iVar5 = ((int (*)())_PPParserGetPart)(param_1,local_180,0);
          if (iVar5 == 0) {
            return 0x2d;
          }
          iVar5 = _memcmp(local_180,"front",6);
          if (iVar5 == 0) {
LAB_97b7ef9c:
            iVar5 = ((int (*)())_PPParserGetPart)(param_1,local_180,0);
            if (iVar5 == 0) {
              return 0x2d;
            }
            if ((local_180[0] != '.') || (iVar5 != 1)) {
              return 10;
            }
            iVar5 = ((int (*)())_PPParserGetPart)(param_1,local_180,0);
            if (iVar5 == 0) {
              return 0x2d;
            }
          }
          else {
            iVar5 = _memcmp(local_180,"back",5);
            if (iVar5 == 0) {
              local_80 = local_80 | 1;
              goto LAB_97b7ef9c;
            }
          }
          iVar5 = _memcmp(local_180,"ambient",8);
          if (iVar5 == 0) {
            local_80 = local_80 & 0xfffffff1;
          }
          else {
            iVar5 = _memcmp(local_180,"diffuse",8);
            if (iVar5 == 0) {
              iVar5 = 1;
LAB_97b7f0a8:
              local_80 = iVar5 << 1 | local_80 & 0xfffffff1;
            }
            else {
              iVar5 = _memcmp(local_180,"specular",9);
              if (iVar5 == 0) {
                local_80 = local_80 & 0xfffffff1 | 4;
              }
              else {
                iVar5 = _memcmp(local_180,"emission",9);
                if (iVar5 != 0) {
                  iVar5 = _memcmp(local_180,"shininess",10);
                  if (iVar5 != 0) {
                    return 10;
                  }
                  iVar5 = 4;
                  goto LAB_97b7f0a8;
                }
                local_80 = local_80 & 0xfffffff1 | 6;
              }
            }
          }
        }
        else {
          iVar5 = _memcmp(local_180,"normalscale",0xc);
          if (iVar5 == 0) {
            uVar6 = *(undefined4 *)(param_1 + 0x1c);
            iVar5 = 0x12;
LAB_97b7fbb8:
            local_80 = iVar5 << 0x10 | local_80 & 0xffe0ffff;
            goto LAB_97b801d0;
          }
          iVar5 = _memcmp(local_180,"light",6);
          if (iVar5 == 0) {
            local_80 = local_80 & 0xffe0ffff | 0x30000;
            iVar5 = ((int (*)())_PPParserParseArray)(param_1,&local_40);
            if (iVar5 != 0) {
              return iVar5;
            }
            if (*(uint *)(param_1 + 0x484) <= local_40) {
              return 0x3c;
            }
            local_80 = CONCAT31((*(unsigned int *)((unsigned char *)&(local_80) + 0)),(undefined1)local_40);
            iVar5 = ((int (*)())_PPParserGetPart)(param_1,local_180,0);
            if (iVar5 == 0) {
              return 0x2d;
            }
            if (local_180[0] != '.') {
              return 10;
            }
            if (iVar5 != 1) {
              return 10;
            }
            iVar5 = ((int (*)())_PPParserGetPart)(param_1,local_180,0);
            if (iVar5 == 0) {
              return 0x2d;
            }
            iVar5 = _memcmp(local_180,"ambient",8);
            if (iVar5 == 0) {
              local_80 = local_80 & 0xfffff0ff;
            }
            else {
              iVar5 = _memcmp(local_180,"diffuse",8);
              if (iVar5 == 0) {
                local_80 = local_80 & 0xfffff0ff | 0x100;
              }
              else {
                iVar5 = _memcmp(local_180,"specular",9);
                if (iVar5 == 0) {
                  local_80 = local_80 & 0xfffff0ff | 0x200;
                }
                else {
                  iVar5 = _memcmp(local_180,"position",9);
                  if (iVar5 == 0) {
                    local_80 = local_80 & 0xfffff0ff | 0x300;
                  }
                  else {
                    iVar5 = _memcmp(local_180,"attenuation",0xc);
                    if (iVar5 == 0) {
                      local_80 = local_80 & 0xfffff0ff | 0x500;
                    }
                    else {
                      iVar5 = _memcmp(local_180,"spot",5);
                      if (iVar5 == 0) {
                        iVar5 = ((int (*)())_PPParserGetPart)(param_1,local_180,0);
                        if (iVar5 == 0) {
                          return 0x2d;
                        }
                        if (local_180[0] != '.') {
                          return 10;
                        }
                        if (iVar5 != 1) {
                          return 10;
                        }
                        iVar5 = ((int (*)())_PPParserGetPart)(param_1,local_180,0);
                        if (iVar5 == 0) {
                          return 0x2d;
                        }
                        iVar5 = _memcmp(local_180,"direction",10);
                        if (iVar5 != 0) {
                          return 10;
                        }
                        iVar5 = 4;
                      }
                      else {
                        iVar5 = _memcmp(local_180,"half",5);
                        if (iVar5 == 0) {
                          iVar5 = 6;
                        }
                        else {
                          iVar5 = _memcmp(local_180,"spotcutoff",0xb);
                          if (iVar5 != 0) {
                            return 10;
                          }
                          iVar5 = 7;
                        }
                      }
                      local_80 = iVar5 << 8 | local_80 & 0xfffff0ff;
                    }
                  }
                }
              }
            }
          }
          else {
            iVar5 = _memcmp(local_180,"lightmodel",0xb);
            if (iVar5 == 0) {
              iVar5 = ((int (*)())_PPParserGetPart)(param_1,local_180,0);
              if (iVar5 == 0) {
                return 0x2d;
              }
              if (local_180[0] != '.') {
                return 10;
              }
              if (iVar5 != 1) {
                return 10;
              }
              iVar5 = ((int (*)())_PPParserGetPart)(param_1,local_180,0);
              if (iVar5 == 0) {
                return 0x2d;
              }
              iVar5 = _memcmp(local_180,"ambient",8);
              if (iVar5 != 0) {
                iVar5 = _memcmp(local_180,"front",6);
                if (iVar5 == 0) {
                  local_80 = local_80 & 0xfffffffe;
LAB_97b7f420:
                  iVar5 = ((int (*)())_PPParserGetPart)(param_1,local_180,0);
                  if (iVar5 == 0) {
                    return 0x2d;
                  }
                  if (local_180[0] != '.') {
                    return 10;
                  }
                  if (iVar5 != 1) {
                    return 10;
                  }
                  iVar5 = ((int (*)())_PPParserGetPart)(param_1,local_180,0);
                  if (iVar5 == 0) {
                    return 0x2d;
                  }
                }
                else {
                  iVar5 = _memcmp(local_180,"back",5);
                  if (iVar5 == 0) {
                    local_80 = local_80 | 1;
                    goto LAB_97b7f420;
                  }
                }
                iVar5 = _memcmp(local_180,"scenecolor",0xb);
                if (iVar5 != 0) {
                  return 10;
                }
                local_80 = local_80 & 0xffe0fff1 | 0x5000a;
                goto LAB_97b7fa44;
              }
              iVar5 = 6;
              goto LAB_97b7fa3c;
            }
            iVar5 = _memcmp(local_180,"lightprod",10);
            if (iVar5 == 0) {
              local_80 = local_80 & 0xffe0feff | 0x40000;
              iVar5 = ((int (*)())_PPParserParseArray)(param_1,&local_40);
              if (iVar5 != 0) {
                return iVar5;
              }
              local_80 = CONCAT31((*(unsigned int *)((unsigned char *)&(local_80) + 0)),(undefined1)local_40);
              iVar5 = ((int (*)())_PPParserGetPart)(param_1,local_180,0);
              if (iVar5 == 0) {
                return 0x2d;
              }
              if (local_180[0] != '.') {
                return 10;
              }
              if (iVar5 != 1) {
                return 10;
              }
              iVar5 = ((int (*)())_PPParserGetPart)(param_1,local_180,0);
              if (iVar5 == 0) {
                return 0x2d;
              }
              iVar5 = _memcmp(local_180,"front",6);
              if (iVar5 == 0) {
LAB_97b7f59c:
                iVar5 = ((int (*)())_PPParserGetPart)(param_1,local_180,0);
                if (iVar5 == 0) {
                  return 0x2d;
                }
                if (local_180[0] != '.') {
                  return 10;
                }
                if (iVar5 != 1) {
                  return 10;
                }
                iVar5 = ((int (*)())_PPParserGetPart)(param_1,local_180,0);
                if (iVar5 == 0) {
                  return 0x2d;
                }
              }
              else {
                iVar5 = _memcmp(local_180,"back",5);
                if (iVar5 == 0) {
                  local_80 = local_80 | 0x100;
                  goto LAB_97b7f59c;
                }
              }
              iVar5 = _memcmp(local_180,"ambient",8);
              if (iVar5 == 0) {
                local_80 = local_80 & 0xfffff9ff;
              }
              else {
                iVar5 = _memcmp(local_180,"diffuse",8);
                if (iVar5 == 0) {
                  local_80 = local_80 & 0xfffff9ff | 0x200;
                }
                else {
                  iVar5 = _memcmp(local_180,"specular",9);
                  if (iVar5 != 0) {
                    return 10;
                  }
                  local_80 = local_80 & 0xfffff9ff | 0x400;
                }
              }
              goto LAB_97b7fa44;
            }
            if (bVar2) {
              iVar5 = _memcmp(local_180,"texenv",7);
              if (iVar5 != 0) goto LAB_97b7f980;
              local_80 = local_80 & 0xffe0ffe0 | 0x90000;
              iVar5 = ((int (*)())_PPParserGetPart)(param_1,local_180,0);
              if (iVar5 == 0) {
                return 0x2d;
              }
              if (local_180[0] == '[') {
                ((int (*)())_PPParserReturnPart)(param_1);
                iVar5 = ((int (*)())_PPParserParseArray)(param_1,&local_40);
                if (iVar5 != 0) {
                  return iVar5;
                }
                local_80 = local_40 & 0x1f | local_80 & 0xffffffe0;
                iVar5 = ((int (*)())_PPParserGetPart)(param_1,local_180,0);
                if (iVar5 == 0) {
                  return 0x2d;
                }
              }
              if (local_180[0] != '.') {
                return 10;
              }
              if (iVar5 != 1) {
                return 10;
              }
              iVar5 = ((int (*)())_PPParserGetPart)(param_1,local_180,0);
              if (iVar5 == 0) {
                return 0x2d;
              }
              iVar5 = _memcmp(local_180,"color",6);
LAB_97b7fae0:
              if (iVar5 != 0) {
                return 10;
              }
            }
            else {
              iVar5 = _memcmp(local_180,"texgen",7);
              if (iVar5 == 0) {
                iVar5 = ((int (*)())_PPParserGetPart)(param_1,local_180,0);
                if (iVar5 == 0) {
                  return 0x2d;
                }
                if (local_180[0] == '[') {
                  ((int (*)())_PPParserReturnPart)(param_1);
                  iVar5 = ((int (*)())_PPParserParseArray)(param_1,&local_40);
                  if (iVar5 != 0) {
                    return iVar5;
                  }
                  if (*(uint *)(param_1 + 0x470) <= local_40) {
                    return 0x38;
                  }
                  local_80 = local_40 & 0x1f | local_80 & 0xffffffe0;
                  iVar5 = ((int (*)())_PPParserGetPart)(param_1,local_180,0);
                  if (iVar5 == 0) {
                    return 0x2d;
                  }
                }
                else {
                  local_80 = local_80 & 0xffffffe0;
                }
                if (local_180[0] != '.') {
                  return 10;
                }
                if (iVar5 != 1) {
                  return 10;
                }
                iVar5 = ((int (*)())_PPParserGetPart)(param_1,local_180,0);
                if (iVar5 == 0) {
                  return 0x2d;
                }
                iVar5 = _memcmp(local_180,"eye",4);
                if (iVar5 == 0) {
                  iVar5 = 7;
                }
                else {
                  iVar5 = _memcmp(local_180,"object",7);
                  if (iVar5 != 0) {
                    return 10;
                  }
                  iVar5 = 8;
                }
                local_80 = iVar5 << 0x10 | local_80 & 0xffe0ffff;
                iVar5 = ((int (*)())_PPParserGetPart)(param_1,local_180,0);
                if (iVar5 == 0) {
                  return 0x2d;
                }
                if (local_180[0] != '.') {
                  return 10;
                }
                if (iVar5 != 1) {
                  return 10;
                }
                iVar5 = ((int (*)())_PPParserGetPart)(param_1,local_180,0);
                if (iVar5 == 0) {
                  return 0x2d;
                }
                iVar5 = _memcmp(local_180,"s",2);
                if (iVar5 == 0) {
                  local_80 = local_80 & 0xffffff1f;
                }
                else {
                  iVar5 = _memcmp(local_180,"t",2);
                  if (iVar5 == 0) {
                    local_80 = local_80 & 0xffffff1f | 0x20;
                  }
                  else {
                    iVar5 = _memcmp(local_180,"r",2);
                    if (iVar5 == 0) {
                      local_80 = local_80 & 0xffffff1f | 0x40;
                    }
                    else {
                      iVar5 = _memcmp(local_180,"q",2);
                      if (iVar5 != 0) {
                        return 0x11;
                      }
                      local_80 = local_80 & 0xffffff1f | 0x60;
                    }
                  }
                }
                goto LAB_97b7fa44;
              }
LAB_97b7f980:
              iVar5 = _memcmp(local_180,"fog",4);
              if (iVar5 == 0) {
                iVar5 = ((int (*)())_PPParserGetPart)(param_1,local_180,0);
                if (iVar5 == 0) {
                  return 0x2d;
                }
                if (local_180[0] != '.') {
                  return 10;
                }
                if (iVar5 != 1) {
                  return 10;
                }
                iVar5 = ((int (*)())_PPParserGetPart)(param_1,local_180,0);
                if (iVar5 == 0) {
                  return 0x2d;
                }
                iVar5 = _memcmp(local_180,"color",6);
                if (iVar5 == 0) {
                  iVar5 = 0xb;
                }
                else {
                  iVar5 = _memcmp(local_180,"params",7);
                  if (iVar5 != 0) {
                    return 10;
                  }
                  iVar5 = 0xc;
                }
              }
              else {
                if (bVar2) {
                  iVar5 = _memcmp(local_180,"depth",6);
                  if (iVar5 != 0) {
LAB_97b7fc90:
                    iVar5 = _memcmp(local_180,"matrix",7);
                    if (iVar5 != 0) {
                      return 10;
                    }
                    local_80 = local_80 & 0xffe03fff | 0x100000;
                    iVar5 = ((int (*)())_PPParserGetPart)(param_1,local_180,0);
                    if (iVar5 == 0) {
                      return 0x2d;
                    }
                    if (local_180[0] != '.') {
                      return 10;
                    }
                    if (iVar5 != 1) {
                      return 10;
                    }
                    iVar5 = ((int (*)())_PPParserGetPart)(param_1,local_180,0);
                    if (iVar5 == 0) {
                      return 0x2d;
                    }
                    iVar5 = _memcmp(local_180,"modelview",10);
                    if (iVar5 == 0) {
                      local_80 = local_80 & 0xfffff8ff | 0x300;
                      iVar5 = ((int (*)())_PPParserGetPart)(param_1,local_180,0);
                      if (iVar5 == 0) {
                        return 0x2d;
                      }
                      ((int (*)())_PPParserReturnPart)(param_1);
                      if (local_180[0] == '[') {
LAB_97b7fe54:
                        iVar5 = ((int (*)())_PPParserParseArray)(param_1,&local_40);
                        if (iVar5 != 0) {
                          return iVar5;
                        }
LAB_97b7fec8:
                        local_80 = CONCAT31((*(unsigned int *)((unsigned char *)&(local_80) + 0)),(undefined1)local_40);
                      }
                      else {
                        local_80 = local_80 & 0xffffff00;
                      }
                    }
                    else {
                      iVar5 = _memcmp(local_180,"projection",0xb);
                      if (iVar5 == 0) {
                        local_80 = local_80 & 0xfffff8ff | 0x100;
                      }
                      else {
                        iVar5 = _memcmp(local_180,"mvp",4);
                        if (iVar5 == 0) {
                          local_80 = local_80 & 0xfffff8ff;
                        }
                        else {
                          iVar5 = _memcmp(local_180,"color",6);
                          if (iVar5 == 0) {
                            local_80 = local_80 & 0xfffff8ff | 0x200;
                          }
                          else {
                            iVar5 = _memcmp(local_180,"texture",8);
                            if (iVar5 != 0) {
                              iVar5 = _memcmp(local_180,"program",8);
                              if (iVar5 != 0) {
                                return 10;
                              }
                              local_80 = local_80 & 0xfffff8ff | 0x500;
                              iVar5 = ((int (*)())_PPParserParseArray)(param_1,&local_40);
                              if (iVar5 != 0) {
                                return iVar5;
                              }
                              if (*(uint *)(param_1 + 0x458) <= local_40) {
                                return 0x30;
                              }
                              goto LAB_97b7fec8;
                            }
                            local_80 = local_80 & 0xfffff8ff | 0x400;
                            iVar5 = ((int (*)())_PPParserGetPart)(param_1,local_180,0);
                            if (iVar5 == 0) {
                              return 0x2d;
                            }
                            ((int (*)())_PPParserReturnPart)(param_1);
                            if (local_180[0] == '[') goto LAB_97b7fe54;
                            local_80 = local_80 & 0xffffff00;
                          }
                        }
                      }
                    }
                    iVar5 = ((int (*)())_PPParserGetPart)(param_1,local_180,0);
                    cVar4 = local_180[0];
                    if (iVar5 == 0) {
                      return 0x2d;
                    }
                    local_180[0] = cVar4;
                    if ((local_180[0] == '.') && (iVar5 == 1)) {
                      iVar7 = ((int (*)())_PPParserGetPart)(param_1,local_180,0);
                      if (iVar7 == 0) {
                        return 0x2d;
                      }
                      iVar7 = _memcmp(local_180,"inverse",8);
                      if (iVar7 == 0) {
                        local_80 = local_80 & 0xffff3fff | 0x8000;
                      }
                      else {
                        iVar7 = _memcmp(local_180,"transpose",10);
                        if (iVar7 == 0) {
                          local_80 = local_80 & 0xffff3fff | 0x4000;
                        }
                        else {
                          iVar7 = _memcmp(local_180,"invtrans",9);
                          if (iVar7 != 0) {
                            ((int (*)())_PPParserReturnPart)(param_1);
                            local_180[1] = 0;
                            local_180[0] = cVar4;
                            cVar4 = '.';
                            goto LAB_97b7ffd8;
                          }
                          local_80 = local_80 & 0xffff3fff | 0xc000;
                        }
                      }
                      iVar5 = ((int (*)())_PPParserGetPart)(param_1,local_180,0);
                      cVar4 = local_180[0];
                      if (iVar5 == 0) {
                        return 0x2d;
                      }
                    }
LAB_97b7ffd8:
                    local_40 = 0;
                    local_3c[0] = 3;
                    if ((cVar4 == '.') && (iVar5 == 1)) {
                      iVar5 = ((int (*)())_PPParserGetPart)(param_1,local_180,0);
                      if (iVar5 == 0) {
                        return 0x2d;
                      }
                      iVar5 = _memcmp(local_180,"row",4);
                      if (iVar5 != 0) {
                        return 10;
                      }
                      if (bVar1) {
                        iVar5 = ((int (*)())_PPParserParseArray)(param_1,&local_40);
                        local_3c[0] = local_40;
                      }
                      else {
                        iVar5 = _PPParserParseRangeArray(param_1,&local_40,local_3c);
                      }
                      if (iVar5 != 0) {
                        return iVar5;
                      }
                    }
                    else {
                      if (bVar1) {
                        return 10;
                      }
                      ((int (*)())_PPParserReturnPart)(param_1);
                    }
                    if (3 < (int)local_40) {
                      return 10;
                    }
                    if (3 < (int)local_3c[0]) {
                      return 10;
                    }
                    uVar3 = local_40;
                    while( true ) {
                      local_80 = (uVar3 & 3) << 0xc | local_80 & 0xffffcfff;
                      ((int (*)())_PPStreamAddParamBinding)(*(undefined4 *)(param_1 + 0x1c),&local_80);
                      if (uVar3 == local_3c[0]) break;
                      iVar9 = iVar9 + 1;
                      uVar3 = uVar3 + 1;
                      iVar5 = *(int *)(param_1 + 0x20) + 1;
                      local_7c = CONCAT22((*(unsigned short *)((unsigned char *)&(local_7c) + 0)),(short)iVar5);
                      *(int *)(param_1 + 0x20) = iVar5;
                    }
                    goto LAB_97b801d4;
                  }
                  local_80 = local_80 & 0xffe0ffff | 0xf0000;
                  iVar5 = ((int (*)())_PPParserGetPart)(param_1,local_180,0);
                  if (iVar5 == 0) {
                    return 0x2d;
                  }
                  if (local_180[0] != '.') {
                    return 10;
                  }
                  if (iVar5 != 1) {
                    return 10;
                  }
                  iVar5 = ((int (*)())_PPParserGetPart)(param_1,local_180,0);
                  if (iVar5 == 0) {
                    return 0x2d;
                  }
                  iVar5 = _memcmp(local_180,"range",6);
                  goto LAB_97b7fae0;
                }
                iVar5 = _memcmp(local_180,"clip",5);
                if (iVar5 == 0) {
                  iVar5 = ((int (*)())_PPParserParseArray)(param_1,&local_40);
                  if (iVar5 != 0) {
                    return iVar5;
                  }
                  if (*(uint *)(param_1 + 0x480) <= local_40) {
                    return 0x3b;
                  }
                  local_80 = CONCAT31((*(unsigned int *)((unsigned char *)&(local_80) + 0)),(undefined1)local_40);
                  iVar5 = ((int (*)())_PPParserGetPart)(param_1,local_180,0);
                  if (iVar5 == 0) {
                    return 0x2d;
                  }
                  if (local_180[0] != '.') {
                    return 10;
                  }
                  if (iVar5 != 1) {
                    return 10;
                  }
                  iVar5 = ((int (*)())_PPParserGetPart)(param_1,local_180,0);
                  if (iVar5 == 0) {
                    return 0x2d;
                  }
                  iVar5 = _memcmp(local_180,"plane",6);
                  if (iVar5 != 0) {
                    return 10;
                  }
                  uVar6 = *(undefined4 *)(param_1 + 0x1c);
                  iVar5 = 10;
                  goto LAB_97b7fbb8;
                }
                iVar5 = _memcmp(local_180,"point",6);
                if (iVar5 != 0) goto LAB_97b7fc90;
                iVar5 = ((int (*)())_PPParserGetPart)(param_1,local_180,0);
                if (iVar5 == 0) {
                  return 0x2d;
                }
                if (local_180[0] != '.') {
                  return 10;
                }
                if (iVar5 != 1) {
                  return 10;
                }
                iVar5 = ((int (*)())_PPParserGetPart)(param_1,local_180,0);
                if (iVar5 == 0) {
                  return 0x2d;
                }
                iVar5 = _memcmp(local_180,"size",5);
                if (iVar5 == 0) {
                  iVar5 = 0xd;
                }
                else {
                  iVar5 = _memcmp(local_180,"attenuation",0xc);
                  if (iVar5 != 0) {
                    return 10;
                  }
                  iVar5 = 0xe;
                }
              }
LAB_97b7fa3c:
              local_80 = iVar5 << 0x10 | local_80 & 0xffe0ffff;
            }
          }
        }
LAB_97b7fa44:
        uVar6 = *(undefined4 *)(param_1 + 0x1c);
      }
      else {
        if (local_180[0] == '{') {
          local_80 = 0x110000;
          local_60 = 0;
          local_54 = 0x3f800000;
          local_58 = 0;
          local_5c = 0;
          iVar5 = _PPParserGetScalars(param_1,&local_60,4);
          if (iVar5 != 0) {
            return iVar5;
          }
          iVar5 = ((int (*)())_PPParserGetPart)(param_1,local_180,0);
          if (iVar5 == 0) {
            return 0x2d;
          }
          if (local_180[0] != '}') {
            return 10;
          }
          uVar6 = *(undefined4 *)(param_1 + 0x1c);
          puVar8 = &local_60;
        }
        else {
          ((int (*)())_PPParserReturnPart)(param_1);
          puVar8 = &local_50;
          local_80 = local_80 & 0xffe0ffff | 0x110000;
          iVar5 = _PPParserGetScalars(param_1,puVar8,1);
          if (iVar5 != 0) {
            return 10;
          }
          uVar6 = *(undefined4 *)(param_1 + 0x1c);
          local_44 = local_50;
          local_4c = local_50;
          local_48 = local_50;
        }
        _PPStreamAddConstant(uVar6,puVar8);
        uVar6 = *(undefined4 *)(param_1 + 0x1c);
        local_80 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_80) + 0)),(short)*(int *)(param_1 + 0x2c));
        *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + 1;
      }
LAB_97b801d0:
      ((int (*)())_PPStreamAddParamBinding)(uVar6,&local_80);
    }
LAB_97b801d4:
    iVar9 = iVar9 + 1;
    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
    if (bVar1) goto LAB_97b80220;
    iVar5 = ((int (*)())_PPParserGetPart)(param_1,local_180,0);
    if (iVar5 == 0) {
      return 0x2d;
    }
  } while (local_180[0] == ',');
  iVar5 = 10;
  if (local_180[0] == '}') {
LAB_97b80220:
    if (*param_3 == 0) {
      *param_3 = iVar9;
    }
    else if (*param_3 != iVar9) {
      return 0x25;
    }
    uVar3 = *(uint *)(param_1 + 0x20);
    iVar5 = 0x34;
    if (uVar3 <= *(uint *)(param_1 + 0x464)) {
      local_6c = CONCAT22(local_6c,*(short *)(param_1 + 0x22) + -1);
      if (1 < iVar9) {
        _PPStreamAddParamBindingArray(*(undefined4 *)(param_1 + 0x1c),&local_70);
        uVar3 = *(uint *)(param_1 + 0x20);
      }
      iVar5 = 0x34;
      if (uVar3 < 0x101) {
        iVar5 = 0;
      }
    }
  }
  return iVar5;
}

/* _PPParserScopeFindMacro @ 0x97b802b8 (100 bytes) */
int _PPParserScopeFindMacro(param_1, param_2)
  int param_1;
  char *param_2;
{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)(param_1 + 8);
  while( true ) {
    if (puVar2 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    if (((char *)*puVar2 != (char *)0x0) && (iVar1 = _strcmp((char *)*puVar2,param_2), iVar1 == 0))
    break;
    puVar2 = (undefined4 *)puVar2[7];
  }
  return puVar2;
}

/* _PPParserParseArray @ 0x97b8031c (176 bytes) */
int _PPParserParseArray(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  char local_110 [260];
  
  iVar1 = ((int (*)())_PPParserGetPart)(param_1,local_110,0);
  iVar2 = 0x2d;
  if ((((iVar1 != 0) && (iVar2 = 0xb, local_110[0] == '[')) &&
      (iVar2 = ((int (*)())_PPParserGetInteger)(param_1,param_2), iVar2 == 0)) && (iVar2 = 0x23, -1 < *param_2))
  {
    iVar1 = ((int (*)())_PPParserGetPart)(param_1,local_110,0);
    iVar2 = 0x2d;
    if ((iVar1 != 0) && (iVar2 = 0xb, local_110[0] == ']')) {
      iVar2 = 0;
    }
  }
  return iVar2;
}

/* _PPParserGetInteger @ 0x97b803cc (112 bytes) */
int _PPParserGetInteger(param_1, param_2)
  undefined4 param_1;
  long *param_2;
{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  char acStack_120 [256];
  char *local_20 [5];
  
  iVar1 = ((int (*)())_PPParserGetPart)(param_1,acStack_120,1);
  uVar2 = 0x2d;
  if (iVar1 != 0) {
    lVar3 = _strtol(acStack_120,local_20,0);
    *param_2 = lVar3;
    uVar2 = 0x15;
    if (local_20[0] == acStack_120 + iVar1) {
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
  undefined1 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  puVar1 = _calloc(0x1c,1);
  uVar3 = param_2[3];
  uVar2 = *(undefined4 *)(param_1 + 0x10);
  uVar4 = *param_2;
  uVar6 = param_2[1];
  uVar5 = param_2[2];
  *puVar1 = 3;
  *(undefined4 *)(puVar1 + 0xc) = uVar4;
  *(undefined4 *)(puVar1 + 0x10) = uVar6;
  *(undefined4 *)(puVar1 + 0x14) = uVar5;
  *(undefined4 *)(puVar1 + 0x18) = uVar3;
  ((int (*)())_PPStreamChunkListAddChunk)(uVar2,puVar1);
  return;
}

/* _PPParserParseAttributeDeclaration @ 0x97b804a8 (268 bytes) */
int _PPParserParseAttributeDeclaration(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  char local_110 [256];
  
  iVar1 = ((int (*)())_PPParserGetPart)(param_1,local_110,0);
  iVar2 = 0x2d;
  if (iVar1 != 0) {
    iVar1 = ((int (*)())_PPParserValidateName)(param_1,local_110);
    iVar2 = 0x12;
    if (iVar1 == 0) {
      iVar1 = ((int (*)())_PPParserIdentifierCreate)();
      ((int (*)())_PPParserIdentifierSetName)(iVar1,local_110);
      *(undefined4 *)(iVar1 + 0xc) = 0;
      iVar2 = ((int (*)())_PPParserScopeAddIdentifier)(*(undefined4 *)(param_1 + 0x44c),iVar1);
      if (iVar2 == 0) {
        iVar3 = ((int (*)())_PPParserGetPart)(param_1,local_110,0);
        iVar2 = 0x2d;
        if ((iVar3 != 0) && (iVar2 = 10, local_110[0] == '=')) {
          *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(param_1 + 0x24);
          iVar2 = ((int (*)())_PPParserParseAttributeBinding)(param_1);
          if (iVar2 == 0) {
            iVar1 = ((int (*)())_PPParserGetPart)(param_1,local_110,0);
            iVar2 = 0x2d;
            if ((iVar1 != 0) && (iVar2 = 10, local_110[0] == ';')) {
              iVar2 = 0;
            }
          }
        }
      }
      else {
        _PPParserIdentifierFree(iVar1);
        iVar2 = 0x1c;
      }
    }
  }
  return iVar2;
}

/* _PPParserParseAttributeBinding @ 0x97b805b4 (1684 bytes) */
int _PPParserParseAttributeBinding(param_1)
  int param_1;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char local_140 [256];
  uint local_40;
  undefined2 local_3c;
  undefined2 uStack_3a;
  uint local_30 [7];
  
  uVar2 = *(uint *)(param_1 + 0x48c);
  iVar3 = ((int (*)())_PPParserGetPart)(param_1,local_140,0);
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
  iVar3 = ((int (*)())_PPParserGetPart)(param_1,local_140,0);
  if (iVar3 == 0) {
    return 0x2d;
  }
  if (local_140[0] != '.') {
    return 10;
  }
  if (iVar3 != 1) {
    return 10;
  }
  iVar3 = ((int (*)())_PPParserGetPart)(param_1,local_140,0);
  if (iVar3 == 0) {
    return 0x2d;
  }
  if ((!bVar1) && (iVar3 = _memcmp(local_140,"attrib",7), iVar3 == 0)) {
    local_40 = local_40 & 0xfff0ffff | 0x90000;
    iVar3 = ((int (*)())_PPParserParseArray)(param_1,local_30);
    if (iVar3 != 0) {
      return iVar3;
    }
    iVar3 = 0x3d;
    uVar2 = *(uint *)(param_1 + 0x488);
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
        iVar3 = ((int (*)())_PPParserGetPart)(param_1,local_140,0);
        if (iVar3 == 0) {
          return 0x2d;
        }
        if ((local_140[0] == '.') && (iVar3 == 1)) {
          iVar3 = ((int (*)())_PPParserGetPart)(param_1,local_140,0);
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
          ((int (*)())_PPParserReturnPart)(param_1);
        }
        ((int (*)())_PPParserReturnPart)(param_1);
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
        iVar3 = ((int (*)())_PPParserGetPart)(param_1,local_140,0);
        if (iVar3 == 0) {
          return 0x2d;
        }
        ((int (*)())_PPParserReturnPart)(param_1);
        if (local_140[0] != '[') {
LAB_97b8095c:
          local_40 = local_40 & 0xffffffe0;
          goto LAB_97b80bac;
        }
        iVar3 = ((int (*)())_PPParserParseArray)(param_1,local_30);
        if (iVar3 != 0) {
          return iVar3;
        }
        iVar3 = 0x38;
        uVar2 = *(uint *)(param_1 + 0x470);
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
        if (*(int *)(param_1 + 0x48c) != 0x36) {
          return 10;
        }
        iVar3 = 0xb;
        goto LAB_97b80b98;
      }
      iVar3 = _memcmp(local_140,"weight",7);
      if (iVar3 == 0) {
        local_40 = local_40 & 0xfff0ffff | 0x60000;
        iVar3 = ((int (*)())_PPParserGetPart)(param_1,local_140,0);
        if (iVar3 == 0) {
          return 0x2d;
        }
        ((int (*)())_PPParserReturnPart)(param_1);
        if (local_140[0] != '[') goto LAB_97b8095c;
        iVar3 = ((int (*)())_PPParserParseArray)(param_1,local_30);
        if (iVar3 != 0) {
          return iVar3;
        }
        iVar3 = 0x39;
        uVar2 = *(uint *)(param_1 + 0x478);
        goto LAB_97b80948;
      }
      iVar3 = _memcmp(local_140,"material",9);
      if (iVar3 != 0) {
        return 10;
      }
      local_40 = local_40 & 0xfff0fffe | 0xa0000;
      iVar3 = ((int (*)())_PPParserGetPart)(param_1,local_140,0);
      if (iVar3 == 0) {
        return 0x2d;
      }
      if (local_140[0] != '.') {
        return 10;
      }
      if (iVar3 != 1) {
        return 10;
      }
      iVar3 = ((int (*)())_PPParserGetPart)(param_1,local_140,0);
      if (iVar3 == 0) {
        return 0x2d;
      }
      iVar3 = _memcmp(local_140,"front",6);
      if (iVar3 == 0) {
LAB_97b80a4c:
        iVar3 = ((int (*)())_PPParserGetPart)(param_1,local_140,0);
        if (iVar3 == 0) {
          return 0x2d;
        }
        if ((local_140[0] != '.') || (iVar3 != 1)) {
          return 10;
        }
        iVar3 = ((int (*)())_PPParserGetPart)(param_1,local_140,0);
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
    iVar3 = *(int *)(param_1 + 0x1c);
  }
  else {
    iVar3 = *(int *)(param_1 + 0x1c);
    iVar5 = **(int **)(iVar3 + 0x18);
    if (iVar5 != 0) {
      do {
        iVar4 = ((int (*)())_testAttribMatch)(&local_40,iVar5 + 0xc);
        if (iVar4 != 0) {
          return 0x13;
        }
        iVar5 = *(int *)(iVar5 + 8);
      } while (iVar5 != 0);
    }
  }
  local_3c = CONCAT22(local_3c,(short)*(int *)(param_1 + 0x24));
  *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
  ((int (*)())_PPStreamAddAttribBinding)(iVar3,&local_40);
  iVar3 = 0x35;
  if (*(uint *)(param_1 + 0x24) < 0x101) {
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
int _PPParserParseOutputDeclaration(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  char local_110 [256];
  
  iVar1 = ((int (*)())_PPParserGetPart)(param_1,local_110,0);
  iVar2 = 0x2d;
  if (iVar1 != 0) {
    iVar1 = ((int (*)())_PPParserValidateName)(param_1,local_110);
    iVar2 = 0x12;
    if (iVar1 == 0) {
      iVar1 = ((int (*)())_PPParserIdentifierCreate)();
      ((int (*)())_PPParserIdentifierSetName)(iVar1,local_110);
      *(undefined4 *)(iVar1 + 0xc) = 3;
      *(undefined4 *)(iVar1 + 0x14) = param_2;
      iVar2 = ((int (*)())_PPParserScopeAddIdentifier)(*(undefined4 *)(param_1 + 0x44c),iVar1);
      if (iVar2 == 0) {
        iVar3 = ((int (*)())_PPParserGetPart)(param_1,local_110,0);
        iVar2 = 0x2d;
        if ((iVar3 != 0) && (iVar2 = 10, local_110[0] == '=')) {
          *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(param_1 + 0x28);
          iVar2 = ((int (*)())_PPParserParseOutputBinding)(param_1,param_2);
          if (iVar2 == 0) {
            iVar1 = ((int (*)())_PPParserGetPart)(param_1,local_110,0);
            iVar2 = 0x2d;
            if ((iVar1 != 0) && (iVar2 = 10, local_110[0] == ';')) {
              iVar2 = 0;
            }
          }
        }
      }
      else {
        _PPParserIdentifierFree(iVar1);
        iVar2 = 0x1c;
      }
    }
  }
  return iVar2;
}

/* _PPParserParseOutputBinding @ 0x97b80eb0 (1212 bytes) */
int _PPParserParseOutputBinding(param_1, param_2)
  int param_1;
  int param_2;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  char local_140;
  undefined1 local_13f;
  uint local_40;
  undefined2 local_3c;
  undefined2 uStack_3a;
  uint local_30 [7];
  
  uVar2 = *(uint *)(param_1 + 0x48c);
  iVar3 = ((int (*)())_PPParserGetPart)(param_1,&local_140,0);
  if (iVar3 == 0) {
    return 0x2d;
  }
  local_40 = param_2 << 0x1d;
  local_3c = 0;
  iVar3 = _memcmp(&local_140,"result",7);
  if (iVar3 != 0) {
    return 10;
  }
  iVar3 = ((int (*)())_PPParserGetPart)(param_1,&local_140,0);
  if (iVar3 == 0) {
    return 0x2d;
  }
  if ((local_140 != '.') || (iVar3 != 1)) {
    return 10;
  }
  iVar3 = ((int (*)())_PPParserGetPart)(param_1,&local_140,0);
  if (iVar3 == 0) {
    return 0x2d;
  }
  bVar1 = ((uVar2 ^ 2) >> 1 & 1) == 0;
  if ((!bVar1) && (iVar3 = _memcmp(&local_140,"position",9), iVar3 == 0)) {
    if ((*(byte *)(param_1 + 0x442) & 1) != 0) {
      return 0x22;
    }
    local_40 = local_40 & 0xfff0ffff | 0x10000;
    goto LAB_97b81320;
  }
  iVar3 = _memcmp(&local_140,"color",6);
  if (iVar3 == 0) {
    local_40 = local_40 & 0xfff0fffe | 0x40000;
    if (bVar1) {
      if (*(char *)(param_1 + 0x445) != '\0') {
        iVar3 = ((int (*)())_PPParserGetPart)(param_1,&local_140,0);
        if (iVar3 == 0) {
          return 0x2d;
        }
        ((int (*)())_PPParserReturnPart)(param_1);
        if (local_140 == '[') {
          iVar3 = ((int (*)())_PPParserParseArray)(param_1,local_30);
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
    iVar3 = ((int (*)())_PPParserGetPart)(param_1,&local_140,0);
    if (iVar3 == 0) {
      return 0x2d;
    }
    if ((local_140 == '.') && (iVar3 == 1)) {
      iVar4 = ((int (*)())_PPParserGetPart)(param_1,&local_140,0);
      if (iVar4 == 0) {
        return 0x2d;
      }
      iVar4 = _memcmp(&local_140,"back",5);
      if (iVar4 == 0) {
        local_40 = local_40 | 1;
      }
      else {
        iVar4 = _memcmp(&local_140,"front",6);
        if (iVar4 != 0) {
          ((int (*)())_PPParserReturnPart)(param_1);
          local_13f = 0;
          local_140 = '.';
          goto LAB_97b810c0;
        }
      }
      iVar3 = ((int (*)())_PPParserGetPart)(param_1,&local_140,0);
      if (iVar3 == 0) {
        return 0x2d;
      }
    }
LAB_97b810c0:
    if ((local_140 == '.') && (iVar3 == 1)) {
      iVar3 = ((int (*)())_PPParserGetPart)(param_1,&local_140,0);
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
      ((int (*)())_PPParserReturnPart)(param_1);
    }
    ((int (*)())_PPParserReturnPart)(param_1);
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
            iVar3 = ((int (*)())_PPParserGetPart)(param_1,&local_140,0);
            if (iVar3 == 0) {
              return 0x2d;
            }
            ((int (*)())_PPParserReturnPart)(param_1);
            if (local_140 == '[') {
              iVar3 = ((int (*)())_PPParserParseArray)(param_1,local_30);
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
          if ((*(int *)(param_1 + 0x48c) != 0x31) && (*(int *)(param_1 + 0x48c) != 0x34)) {
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
  local_3c = CONCAT22(local_3c,(short)*(int *)(param_1 + 0x28));
  *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
  ((int (*)())_PPStreamAddOutputBinding)(*(undefined4 *)(param_1 + 0x1c),&local_40);
  iVar3 = 0x36;
  if (*(uint *)(param_1 + 0x28) < 0x101) {
    iVar3 = 0;
  }
  return iVar3;
}

/* _PPStreamAddOutputBinding @ 0x97b8136c (92 bytes) */
int _PPStreamAddOutputBinding(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined1 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  puVar1 = _calloc(0x14,1);
  uVar4 = param_2[1];
  uVar2 = *(undefined4 *)(param_1 + 0x1c);
  uVar3 = *param_2;
  *puVar1 = 4;
  *(undefined4 *)(puVar1 + 0xc) = uVar3;
  *(undefined4 *)(puVar1 + 0x10) = uVar4;
  ((int (*)())_PPStreamChunkListAddChunk)(uVar2,puVar1);
  return;
}

/* _PPParserParseOperation @ 0x97b813c8 (1068 bytes) */
int _PPParserParseOperation(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  uint param_2;
  uint param_3;
  uint param_4;
  uint param_5;
  uint param_6;
  undefined4 param_7;
{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined4 *puVar8;
  uint uVar9;
  char local_290 [256];
  undefined1 auStack_190 [256];
  uint local_90;
  uint local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  int local_60;
  undefined4 local_5c;
  undefined4 local_50;
  int local_4c [6];
  
  local_60 = *(int *)(param_1 + 0x18);
  iVar4 = 0;
  local_50 = 0;
  uVar7 = 0;
  bVar3 = false;
  local_88 = 0;
  bVar1 = true;
  local_84 = 0;
  bVar2 = false;
  local_80 = 0;
  local_7c = 0;
  local_78 = 0;
  local_74 = 0;
  local_70 = 0;
  local_6c = 0;
  local_68 = 0;
  local_64 = 0;
  local_5c = 0;
  if ((*(byte *)(param_1 + 0x441) & 1) == 0) {
    local_60 = local_60 + *(int *)(param_1 + 0x10);
  }
  local_90 = (param_2 & 0xff) << 0x12;
  local_8c = (param_3 & 3) << 0x12 |
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
    if ((*(uint *)(param_1 + 0x48c) & 0x10) == 0) {
      bVar3 = true;
    }
  case 0x49:
  case 0x4a:
    uVar7 = 1;
    bVar2 = true;
    break;
  case 0x4b:
  case 0x4c:
    iVar4 = _PPParserParseBranchLabel(param_1,auStack_190,&local_50);
    if (iVar4 != 0) {
      return iVar4;
    }
  case 0x4d:
  case 0x54:
  case 0x55:
    iVar4 = _PPParserParseBranchCondition(param_1,&local_88,param_2);
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
      iVar4 = _PPParserParseAddressDestination(param_1,&local_88);
    }
    else {
      iVar4 = ((int (*)())_PPParserParseDestination)(param_1,&local_88,param_2);
    }
    if (iVar4 != 0) {
      return iVar4;
    }
  }
  uVar9 = 0;
  if (uVar7 != 0) {
    puVar8 = &local_80;
    do {
      local_4c[0] = 0;
      if (bVar1) {
        iVar4 = ((int (*)())_PPParserGetPart)(param_1,local_290,0);
        if (iVar4 == 0) {
          return 0x2d;
        }
        if (local_290[0] != ',') {
          return 0x1f;
        }
      }
      if (param_2 == 0x41) {
        if (uVar9 == 0) {
          iVar4 = ((int (*)())_PPParserParseSourceVar)(param_1,&local_80,0x41,local_4c);
        }
        else {
          iVar4 = _PPParserParseSwizzleCode(param_1,&local_78);
        }
      }
      else {
        if ((uVar9 == 3) && (param_2 == 0x62)) {
          puVar6 = &local_68;
        }
        else {
          if ((uVar9 != 1) || (((1 < param_2 - 0x42 && (param_2 != 0x46)) && (param_2 != 0x44)))) {
            if ((param_2 == 0x4a) || (param_2 - 0x60 < 2)) {
              iVar4 = _PPParserParseAddressSourceVar(param_1,&local_80);
            }
            else {
              iVar4 = ((int (*)())_PPParserParseSwizzleSourceVar)(param_1,puVar8,param_2,local_4c);
            }
            goto LAB_97b818a8;
          }
          puVar6 = &local_78;
        }
        iVar4 = _PPParserParseTextureSourceVar(param_1,puVar6);
      }
LAB_97b818a8:
      if (iVar4 != 0) {
        return iVar4;
      }
      if ((bVar3) && (local_4c[0] == 0)) {
        return 0x14;
      }
      uVar9 = uVar9 + 1;
      puVar8 = puVar8 + 2;
    } while (uVar9 < uVar7);
  }
  iVar4 = ((int (*)())_PPParserGetPart)(param_1,local_290,0);
  iVar5 = 0x2d;
  if ((iVar4 != 0) && (iVar5 = 0x1e, local_290[0] == ';')) {
    iVar4 = *(int *)(param_1 + 0x1c);
    iVar5 = 0x32;
    if (*(uint *)(*(int *)(iVar4 + 0x20) + 8) < *(uint *)(param_1 + 0x45c)) {
      iVar5 = *(int *)(*(int *)(iVar4 + 0x20) + 4);
      if (iVar5 == 0) {
        local_90 = uVar7 << 0x1d | local_90 & 0x3ffffff;
      }
      else {
        local_90 = *(uint *)(iVar5 + 0xc) >> 3 & 0x1c000000 | uVar7 << 0x1d | local_90 & 0x3ffffff;
      }
      local_5c = local_50;
      _PPStreamAddOperation(iVar4,&local_90,auStack_190,*(undefined1 *)(param_1 + 0x440));
      *(undefined1 *)(param_1 + 0x440) = 0;
      iVar5 = 0;
    }
  }
  return iVar5;
}

/* _PPParserParseDestination @ 0x97b81994 (604 bytes) */
int _PPParserParseDestination(param_1, param_2, param_3)
  int param_1;
  uint *param_2;
  int param_3;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  char local_130 [256];
  undefined4 local_30;
  
  iVar1 = ((int (*)())_PPParserGetPart)(param_1,local_130,1);
  if (iVar1 == 0) {
    return 0x2d;
  }
  iVar1 = ((int (*)())_PPParserScopeFindIdentifier)(*(undefined4 *)(param_1 + 0x44c),local_130);
  if (iVar1 == 0) {
    iVar1 = _memcmp(local_130,"result",7);
    if (iVar1 != 0) {
      return 0x19;
    }
    *(undefined2 *)((int)param_2 + 6) = *(undefined2 *)(param_1 + 0x2a);
    *param_2 = *param_2 & 0xfff1ffff | 0x60000;
    ((int (*)())_PPParserReturnPart)(param_1);
    iVar1 = ((int (*)())_PPParserParseOutputBinding)(param_1,0);
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  else {
    local_30 = 0;
    if ((param_3 - 0x5cU < 4) && (*(int *)(iVar1 + 0x14) == 2)) {
      return 0x2c;
    }
    iVar3 = ((int (*)())_PPParserGetPart)(param_1,local_130,0);
    if (iVar3 == 0) {
      return 0x2d;
    }
    ((int (*)())_PPParserReturnPart)(param_1);
    if (local_130[0] == '[') {
      if (*(char *)(iVar1 + 0x10) == '\0') {
        return 0x20;
      }
      iVar3 = ((int (*)())_PPParserParseArray)(param_1,&local_30);
      if (iVar3 != 0) {
        return iVar3;
      }
      if (*(uint *)(iVar1 + 4) <= local_30) {
        ((int (*)())_PPParserReturnPart)(param_1);
        return 0x23;
      }
    }
    else if (*(char *)(iVar1 + 0x10) != '\0') {
      return 0x21;
    }
    *(short *)((int)param_2 + 6) = *(short *)(iVar1 + 10) + (*(unsigned short *)((unsigned char *)&(local_30) + 2));
    uVar2 = *(uint *)(iVar1 + 0xc);
    if ((uVar2 != 1) && (uVar2 != 3)) {
      return 0x18;
    }
    *param_2 = (uVar2 & 7) << 0x11 | *param_2 & 0xfff1ffff;
  }
  *param_2 = *param_2 & 0xf03ffc0f | 0x1b1e06c;
  iVar3 = ((int (*)())_PPParserGetPart)(param_1,local_130,0);
  iVar1 = 0x2d;
  if (iVar3 != 0) {
    if ((local_130[0] == '.') && (iVar3 == 1)) {
      iVar1 = _PPParserParseDestinationMask(param_1,param_2);
      if (iVar1 != 0) {
        return iVar1;
      }
    }
    else {
      ((int (*)())_PPParserReturnPart)(param_1);
    }
    if (((*(uint *)(param_1 + 0x48c) & 0x10) == 0) ||
       (iVar1 = _PPParserParseBranchCondition(param_1,param_2,0), iVar1 == 0)) {
      iVar1 = 0;
    }
  }
  return iVar1;
}

/* _PPParserParseSwizzleSourceVar @ 0x97b81bf0 (460 bytes) */
int _PPParserParseSwizzleSourceVar(param_1, param_2, param_3, param_4)
  int param_1;
  uint *param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  int iVar1;
  int iVar2;
  char local_120 [268];
  
  iVar1 = ((int (*)())_PPParserGetPart)(param_1,local_120,0);
  iVar2 = 0x2d;
  if (iVar1 != 0) {
    iVar1 = _memcmp(local_120,"-",2);
    if (iVar1 == 0) {
      *param_2 = *param_2 | 0x8000000;
    }
    else {
      iVar1 = _memcmp(local_120,"+",2);
      if (iVar1 != 0) {
        ((int (*)())_PPParserReturnPart)(param_1);
      }
    }
    if ((*(uint *)(param_1 + 0x48c) & 0x20) != 0) {
      iVar1 = ((int (*)())_PPParserGetPart)(param_1,local_120,0);
      if (iVar1 == 0) {
        return 0x2d;
      }
      iVar1 = _memcmp(local_120,"|",2);
      if (iVar1 == 0) {
        *param_2 = *param_2 | 0x4000000;
      }
      else {
        ((int (*)())_PPParserReturnPart)(param_1);
      }
    }
    iVar2 = ((int (*)())_PPParserParseSourceVar)(param_1,param_2,param_3,param_4);
    if (iVar2 == 0) {
      iVar1 = ((int (*)())_PPParserGetPart)(param_1,local_120,0);
      iVar2 = 0x2d;
      if (iVar1 != 0) {
        if ((local_120[0] == '.') && (iVar1 == 1)) {
          iVar1 = _PPParserParseSourceSwizzle(param_1,param_2,param_4);
          if (iVar1 != 0) {
            return iVar1;
          }
        }
        else {
          ((int (*)())_PPParserReturnPart)(param_1);
        }
        if (((*(uint *)(param_1 + 0x48c) & 0x20) != 0) && ((*param_2 & 0x4000000) != 0)) {
          iVar1 = ((int (*)())_PPParserGetPart)(param_1,local_120,0);
          if (iVar1 == 0) {
            return 0x2d;
          }
          iVar1 = _memcmp(local_120,"|",2);
          if (iVar1 != 0) {
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
int _PPParserParseSourceVar(param_1, param_2, param_3, param_4)
  int param_1;
  uint *param_2;
  int param_3;
  uint *param_4;
{
  undefined2 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  char local_130 [256];
  char *local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  iVar3 = ((int (*)())_PPParserGetPart)(param_1,local_130,1);
  if (iVar3 == 0) {
    return 0x2d;
  }
  iVar4 = ((int (*)())_PPParserScopeFindIdentifier)(*(undefined4 *)(param_1 + 0x44c),local_130);
  if (iVar4 == 0) {
    if ((*(uint *)(param_1 + 0x48c) & 2) == 0) {
      iVar4 = _memcmp(local_130,"vertex",7);
    }
    else {
      iVar4 = _memcmp(local_130,"fragment",9);
    }
    if (iVar4 == 0) {
      *(undefined2 *)((int)param_2 + 6) = *(undefined2 *)(param_1 + 0x26);
      *param_2 = *param_2 & 0xfc7fffff;
      ((int (*)())_PPParserReturnPart)(param_1);
      iVar3 = ((int (*)())_PPParserParseAttributeBinding)(param_1);
    }
    else {
      if (((local_130[0] != '{') && (iVar4 = _memcmp(local_130,"program",8), iVar4 != 0)) &&
         (iVar4 = _memcmp(local_130,"state",6), iVar4 != 0)) {
        ((double (*)())_glp_strtod)(local_130,&local_30);
        uVar2 = (uint)(local_30 == local_130 + iVar3);
        *param_4 = uVar2;
        if (uVar2 == 0) {
          return 0x1a;
        }
      }
      uVar1 = *(undefined2 *)(param_1 + 0x22);
      *param_2 = *param_2 & 0xfc7fffff | 0x1000000;
      *(undefined2 *)((int)param_2 + 6) = uVar1;
      local_2c = 1;
      ((int (*)())_PPParserReturnPart)(param_1);
      iVar3 = ((int (*)())_PPParserParseParamBinding)(param_1,0,&local_2c);
    }
    if (iVar3 != 0) {
      return iVar3;
    }
  }
  else {
    local_28 = 0;
    if ((param_3 - 99U < 4) && (*(int *)(iVar4 + 0x14) == 2)) {
      return 0x2b;
    }
    iVar3 = ((int (*)())_PPParserGetPart)(param_1,local_130,0);
    if (iVar3 == 0) {
      return 0x2d;
    }
    ((int (*)())_PPParserReturnPart)(param_1);
    if (local_130[0] == '[') {
      if (*(char *)(iVar4 + 0x10) == '\0') {
        return 0x20;
      }
      iVar3 = _PPParserParseIndirectArray(param_1,param_2,&local_28);
      if (iVar3 != 0) {
        return iVar3;
      }
      if (*(uint *)(iVar4 + 4) <= local_28) {
        ((int (*)())_PPParserReturnPart)(param_1);
        return 0x23;
      }
    }
    else if (*(char *)(iVar4 + 0x10) != '\0') {
      return 0x21;
    }
    *(short *)((int)param_2 + 6) = *(short *)(iVar4 + 10) + (*(unsigned short *)((unsigned char *)&(local_28) + 2));
    if (2 < *(uint *)(iVar4 + 0xc)) {
      return 0x17;
    }
    *param_2 = (*(uint *)(iVar4 + 0xc) & 7) << 0x17 | *param_2 & 0xfc7fffff;
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
  void *param_2;
  void *param_3;
  int param_4;
{
  uint uVar1;
  int iVar2;
  undefined1 *puVar3;
  size_t sVar4;
  
  sVar4 = *(size_t *)((int)param_2 + 0x34);
  iVar2 = 0x38;
  if (sVar4 != 0) {
    iVar2 = sVar4 + 0x39;
  }
  puVar3 = _calloc(iVar2 + 0xc,1);
  *puVar3 = 8;
  _memcpy(puVar3 + 0xc,param_2,0x38);
  if ((sVar4 != 0) && (param_3 != (void *)0x0)) {
    _memmove(puVar3 + 0x44,param_3,sVar4);
    puVar3[sVar4 + 0x44] = 0;
  }
  if (param_4 == 0) {
    iVar2 = _PPStreamChunkListGetMaxIndex(*(undefined4 *)(param_1 + 0x20));
    uVar1 = iVar2 + 1U & 0x3ffff | *(uint *)(puVar3 + 0xc) & 0xfffc0000;
  }
  else {
    uVar1 = *(uint *)(puVar3 + 0xc) & 0xfffc0000;
  }
  *(uint *)(puVar3 + 0xc) = uVar1;
  ((int (*)())_PPStreamChunkListAddChunk)(*(undefined4 *)(param_1 + 0x20),puVar3);
  return;
}

/* _PPParserParseEnd @ 0x97b82150 (136 bytes) */
int _PPParserParseEnd(param_1)
  undefined4 param_1;
{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_110 [264];
  
  iVar1 = ((int (*)())_PPParserGetPart)(param_1,auStack_110,0);
  uVar2 = 0x2d;
  if (iVar1 != 0) {
    iVar1 = _memcmp(auStack_110,"END",4);
    uVar2 = 6;
    if (iVar1 == 0) {
      iVar1 = ((int (*)())_PPParserGetPart)(param_1,auStack_110,0);
      uVar2 = 9;
      if (iVar1 == 0) {
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}

/* _PPStreamAttribBindingIsEqual @ 0x97b821d8 (88 bytes) */
int _PPStreamAttribBindingIsEqual(param_1, param_2)
  undefined4 *param_1;
  undefined4 *param_2;
{
  int iVar1;
  undefined4 local_30;
  undefined2 local_2c;
  undefined2 uStack_2a;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_1c = param_2[1];
  local_30 = *param_1;
  local_20 = *param_2;
  local_2c = CONCAT22((short)((uint)param_1[1] >> 0x10),(short)local_1c);
  iVar1 = _memcmp(&local_30,&local_20,8);
  return iVar1 == 0;
}

/* _PPStreamOutputBindingIsEqual @ 0x97b82230 (88 bytes) */
int _PPStreamOutputBindingIsEqual(param_1, param_2)
  undefined4 *param_1;
  undefined4 *param_2;
{
  int iVar1;
  undefined4 local_30;
  undefined2 local_2c;
  undefined2 uStack_2a;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_1c = param_2[1];
  local_30 = *param_1;
  local_20 = *param_2;
  local_2c = CONCAT22((short)((uint)param_1[1] >> 0x10),(short)local_1c);
  iVar1 = _memcmp(&local_30,&local_20,8);
  return iVar1 == 0;
}

/* _PPStreamParamBindingIsEqual @ 0x97b82288 (88 bytes) */
int _PPStreamParamBindingIsEqual(param_1, param_2)
  undefined4 *param_1;
  undefined4 *param_2;
{
  int iVar1;
  undefined4 local_30;
  undefined2 local_2c;
  undefined2 uStack_2a;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_1c = param_2[1];
  local_30 = *param_1;
  local_20 = *param_2;
  local_2c = CONCAT22((short)((uint)param_1[1] >> 0x10),(short)local_1c);
  iVar1 = _memcmp(&local_30,&local_20,8);
  return iVar1 == 0;
}

/* _PPStreamChunkListGetStream @ 0x97b822e0 (276 bytes) */
int _PPStreamChunkListGetStream(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  int *param_3;
  undefined4 param_4;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined1 auStack_40 [16];
  uint local_30;
  undefined1 auStack_2c [16];
  
  iVar1 = 0;
  iVar2 = *param_1;
  *param_3 = 0;
  for (; iVar2 != 0; iVar2 = *(int *)(iVar2 + 8)) {
    ((int (*)())_PPStreamChunkGetStream)(auStack_40,iVar2,param_4,&local_30,0);
    *param_3 = *param_3 + local_30;
  }
  if (param_2 != 0) {
    for (iVar2 = *param_1; iVar2 != 0; iVar2 = *(int *)(iVar2 + 8)) {
      ((int (*)())_PPStreamChunkGetStream)(iVar1 * 8 + param_2,iVar2,param_4,&local_30,0);
      iVar1 = iVar1 + 1;
      if (1 < local_30) {
        local_30 = local_30 - 1;
        uVar3 = 0;
        if (local_30 != 0) {
          iVar4 = iVar1 * 8 + param_2;
          do {
            uVar3 = uVar3 + 1;
            ((int (*)())_PPStreamChunkGetStream)(iVar4,iVar2,param_4,auStack_2c,uVar3);
            iVar1 = iVar1 + 1;
            iVar4 = iVar4 + 8;
          } while (uVar3 < local_30);
        }
      }
    }
  }
  return;
}

/* _PPStreamChunkGetStream @ 0x97b823f4 (184 bytes) */
int _PPStreamChunkGetStream(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
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
    param_1[1] = uVar1;
    *param_1 = uVar2;
    return;
  case 10:
    *param_4 = 2;
LAB_97b824a8:
    uVar1 = *(undefined4 *)(param_2 + param_5 * 8 + 0x10);
    uVar2 = *(undefined4 *)(param_2 + param_5 * 8 + 0xc);
LAB_97b824b4:
    param_1[1] = uVar1;
    *param_1 = uVar2;
    return;
  }
}

/* _PPStreamChunkListCreateFromChunkList @ 0x97b824dc (96 bytes) */
int _PPStreamChunkListCreateFromChunkList(param_1)
  int *param_1;
{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = ((int (*)())_PPStreamChunkListCreate)();
  for (iVar3 = *param_1; iVar3 != 0; iVar3 = *(int *)(iVar3 + 8)) {
    uVar2 = ((int (*)())_PPStreamChunkCreateFromChunk)(iVar3);
    ((int (*)())_PPStreamChunkListAddChunk)(uVar1,uVar2);
  }
  return uVar1;
}

/* _PPStreamChunkCreateFromChunk @ 0x97b8253c (128 bytes) */
int _PPStreamChunkCreateFromChunk(param_1)
  byte *param_1;
{
  uint uVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  uVar1 = (uint)*param_1;
  if (uVar1 == 8) {
    uVar4 = *(undefined4 *)(param_1 + 0x40);
  }
  else if (uVar1 == 0xb) {
    uVar4 = *(undefined4 *)(param_1 + 0x10);
  }
  iVar2 = _GetChunkAllocationSize(uVar1,uVar4);
  pvVar3 = _calloc(iVar2 + 0xcU,1);
  _memmove(pvVar3,param_1,iVar2 + 0xcU);
  *(undefined4 *)((int)pvVar3 + 4) = 0;
  *(undefined4 *)((int)pvVar3 + 8) = 0;
  return pvVar3;
}

