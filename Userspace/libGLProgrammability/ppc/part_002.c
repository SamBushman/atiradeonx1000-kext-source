#include "decls.h"

/* _FreeAtomTable @ 0x97b85ff8 (104 bytes) */
int _FreeAtomTable(param_1)
  int param_1;
{
  _FreeStringTable();
  _FreeHashTable(param_1 + 0xc);
  if (*(void **)(param_1 + 0x28) != (void *)0x0) {
    _free(*(void **)(param_1 + 0x28));
  }
  if (*(void **)(param_1 + 0x2c) != (void *)0x0) {
    _free(*(void **)(param_1 + 0x2c));
  }
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  return;
}

/* _InitCPP @ 0x97b86060 (812 bytes) */
int _InitCPP()
{
  undefined *puVar1;
  size_t sVar2;
  unsigned char _Var3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  char local_60 [4];
  char local_5c [4];
  char local_58;
  char acStack_21 [9];
  
  puVar1 = PTR__atable_a7b7c0ac;
  _bindAtom = _LookUpAddString(*(undefined4 *)PTR__atable_a7b7c0ac,"bind");
  _constAtom = _LookUpAddString(*(undefined4 *)puVar1,"const");
  _defaultAtom = _LookUpAddString(*(undefined4 *)puVar1,"default");
  _defineAtom = _LookUpAddString(*(undefined4 *)puVar1,"define");
  _definedAtom = _LookUpAddString(*(undefined4 *)puVar1,"defined");
  _elifAtom = _LookUpAddString(*(undefined4 *)puVar1,"elif");
  _elseAtom = _LookUpAddString(*(undefined4 *)puVar1,"else");
  _endifAtom = _LookUpAddString(*(undefined4 *)puVar1,"endif");
  _ifAtom = _LookUpAddString(*(undefined4 *)puVar1,"if");
  _ifdefAtom = _LookUpAddString(*(undefined4 *)puVar1,"ifdef");
  _ifndefAtom = _LookUpAddString(*(undefined4 *)puVar1,"ifndef");
  _includeAtom = _LookUpAddString(*(undefined4 *)puVar1,"include");
  _lineAtom = _LookUpAddString(*(undefined4 *)puVar1,"line");
  _pragmaAtom = _LookUpAddString(*(undefined4 *)puVar1,"pragma");
  _texunitAtom = _LookUpAddString(*(undefined4 *)puVar1,"texunit");
  _undefAtom = _LookUpAddString(*(undefined4 *)puVar1,"undef");
  _errorAtom = _LookUpAddString(*(undefined4 *)puVar1,"error");
  ___LINE__Atom = _LookUpAddString(*(undefined4 *)puVar1,"__LINE__");
  ___FILE__Atom = _LookUpAddString(*(undefined4 *)puVar1,"__FILE__");
  ___VERSION__Atom = _LookUpAddString(*(undefined4 *)puVar1,"__VERSION__");
  _versionAtom = _LookUpAddString(*(undefined4 *)puVar1,"version");
  _extensionAtom = _LookUpAddString(*(undefined4 *)puVar1,"extension");
  ((int (*)())_mem_CreatePool)(0,0);
  _macros = ((int (*)())_NewScopeInPool)();
  local_60[0] = s_PROFILE__97c23f9c[0];
  local_60[1] = s_PROFILE__97c23f9c[1];
  local_60[2] = s_PROFILE__97c23f9c[2];
  local_60[3] = s_PROFILE__97c23f9c[3];
  local_5c[0] = s_PROFILE__97c23f9c[4];
  local_5c[1] = s_PROFILE__97c23f9c[5];
  local_5c[2] = s_PROFILE__97c23f9c[6];
  local_5c[3] = s_PROFILE__97c23f9c[7];
  local_58 = s_PROFILE__97c23f9c[8];
  sVar2 = _strlen(local_60);
  puVar1 = PTR_DAT_a7b7c0a8;
  pcVar6 = local_60 + sVar2;
  pcVar7 = *(char **)(*(int *)PTR__cpp_a7b7c0a4 + 4);
  while( true ) {
    uVar4 = (uint)*pcVar7;
    if ((uVar4 & 0xffffff80) == 0) {
      uVar4 = -(*(uint *)(puVar1 + uVar4 * 4 + 0x34) & 0x500) >> 0x1f;
    }
    else {
      iVar5 = ___maskrune(uVar4,0x500);
      uVar4 = (uint)(iVar5 != 0);
    }
    if (((uVar4 == 0) && (*pcVar7 != '_')) || (acStack_21 <= pcVar6)) break;
    _Var3 = ___toupper((int)*pcVar7);
    pcVar7 = pcVar7 + 1;
    *pcVar6 = (char)_Var3;
    pcVar6 = pcVar6 + 1;
  }
  *pcVar6 = '\0';
  return 1;
}

/* _FreeCPP @ 0x97b8638c (84 bytes) */
int _FreeCPP()
{
  if (_macros != 0) {
    ((int (*)())_mem_FreePool)(*(undefined4 *)(_macros + 0x10));
    _macros = 0;
  }
  return 1;
}

/* _FinalCPP @ 0x97b863e0 (84 bytes) */
int _FinalCPP()
{
  if (*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x34) != 0) {
    _CPPErrorToInfoLog("#if mismatch");
  }
  return 1;
}

/* _CPPdefine @ 0x97b86434 (940 bytes) */
int _CPPdefine(param_1)
  int *param_1;
{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int local_150 [64];
  int local_50;
  void *local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined2 local_40;
  undefined2 local_3e;
  
  puVar1 = PTR__cpp_a7b7c0a4;
  local_50 = 0;
  local_44 = 0;
  local_4c = (void *)0x0;
  local_48 = 0;
  iVar2 = (**(code **)(*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20) + 4))
                    (*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20),param_1);
  if (iVar2 == 0x10e) {
    iVar5 = param_1[2];
    iVar2 = (**(code **)(*(int *)(*(int *)puVar1 + 0x20) + 4))
                      (*(int *)(*(int *)puVar1 + 0x20),param_1);
    if ((iVar2 == 0x28) && (*param_1 == 0)) {
      piVar6 = local_150;
      iVar8 = 0;
      do {
        iVar2 = (**(code **)(*(int *)(*(int *)puVar1 + 0x20) + 4))
                          (*(int *)(*(int *)puVar1 + 0x20),param_1);
        if ((iVar8 == 0) && (iVar2 == 0x29)) goto LAB_97b86554;
        if (iVar2 != 0x10e) goto LAB_97b86774;
        if (iVar8 < 0x40) {
          iVar8 = iVar8 + 1;
          *piVar6 = param_1[2];
          piVar6 = piVar6 + 1;
        }
        iVar2 = (**(code **)(*(int *)(*(int *)puVar1 + 0x20) + 4))
                          (*(int *)(*(int *)puVar1 + 0x20),param_1);
      } while (iVar2 == 0x2c);
      if (iVar2 != 0x29) goto LAB_97b86774;
LAB_97b86554:
      local_50 = iVar8;
      local_4c = (void *)((int (*)())_mem_Alloc)(*(undefined4 *)(_macros + 0x10),iVar8 << 2);
      _memcpy(local_4c,local_150,iVar8 << 2);
      iVar2 = (**(code **)(*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20) + 4))
                        (*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20),param_1);
    }
    uVar3 = _GetAtomString(*(undefined4 *)PTR__atable_a7b7c0ac,iVar5);
    local_48 = ((int (*)())_NewTokenStream)(uVar3,*(undefined4 *)(_macros + 0x10));
    puVar1 = PTR__cpp_a7b7c0a4;
    while (iVar2 != 10) {
      while (iVar2 == 0x5c) {
        iVar2 = (**(code **)(*(int *)(*(int *)puVar1 + 0x20) + 4))
                          (*(int *)(*(int *)puVar1 + 0x20),param_1);
        if (iVar2 == 10) {
          iVar2 = (**(code **)(*(int *)(*(int *)puVar1 + 0x20) + 4))
                            (*(int *)(*(int *)puVar1 + 0x20),param_1);
        }
        else {
          ((int (*)())_RecordToken)(local_48,0x5c,param_1);
        }
      }
      ((int (*)())_RecordToken)(local_48,iVar2,param_1);
      iVar2 = (**(code **)(*(int *)(*(int *)puVar1 + 0x20) + 4))
                        (*(int *)(*(int *)puVar1 + 0x20),param_1);
    }
    iVar8 = ((int (*)())_LookUpSymbol)(_macros,iVar5);
    if (iVar8 == 0) {
      local_40 = 0;
      local_3e = local_40;
      iVar8 = ((int (*)())_AddSymbol)(&local_40,_macros,iVar5,0);
    }
    else if ((*(uint *)(iVar8 + 0x24) & 0x40000000) == 0) {
      if (*(int *)(iVar8 + 0x18) == local_50) {
        iVar2 = 0;
        if (0 < local_50) {
          do {
            if (*(int *)(iVar2 * 4 + *(int *)(iVar8 + 0x1c)) != *(int *)(iVar2 * 4 + (int)local_4c))
            goto LAB_97b86728;
            iVar2 = iVar2 + 1;
          } while (iVar2 < local_50);
        }
        ((int (*)())_RewindTokenStream)(*(undefined4 *)(iVar8 + 0x20));
        ((int (*)())_RewindTokenStream)(local_48);
        do {
          iVar2 = ((int (*)())_ReadToken)(*(undefined4 *)(iVar8 + 0x20),param_1);
          iVar7 = *param_1;
          iVar4 = ((int (*)())_ReadToken)(local_48,param_1);
          if ((iVar4 != iVar2) || (*param_1 != iVar7)) goto LAB_97b86728;
        } while (0 < iVar4);
      }
      else {
LAB_97b86728:
        _StoreStr("Macro Redefined");
        _GetStringOfAtom(*(undefined4 *)PTR__atable_a7b7c0ac,iVar5);
        _StoreStr();
        uVar3 = _GetStrfromTStr();
        _DecLineNumber();
        _CPPShInfoLogMsg(uVar3);
        _IncLineNumber();
        _ResetTString();
      }
    }
    iVar2 = 10;
    *(undefined4 *)(iVar8 + 0x24) = local_44;
    *(int *)(iVar8 + 0x18) = local_50;
    *(void **)(iVar8 + 0x1c) = local_4c;
    *(undefined4 *)(iVar8 + 0x20) = local_48;
  }
  else {
LAB_97b86774:
    _CPPErrorToInfoLog("#define");
  }
  return iVar2;
}

/* _CPPundef @ 0x97b867e0 (208 bytes) */
int _CPPundef(param_1)
  int param_1;
{
  undefined *puVar1;
  int iVar2;
  
  puVar1 = PTR__cpp_a7b7c0a4;
  iVar2 = (**(code **)(*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20) + 4))
                    (*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20),param_1);
  if (iVar2 == 10) {
    _CPPErrorToInfoLog("#undef");
    iVar2 = 10;
  }
  else {
    if (iVar2 == 0x10e) {
      iVar2 = ((int (*)())_LookUpSymbol)(_macros,*(undefined4 *)(param_1 + 8));
      if (iVar2 != 0) {
        *(uint *)(iVar2 + 0x24) = *(uint *)(iVar2 + 0x24) | 0x40000000;
      }
      iVar2 = (**(code **)(*(int *)(*(int *)puVar1 + 0x20) + 4))
                        (*(int *)(*(int *)puVar1 + 0x20),param_1);
      if (iVar2 == 10) {
        return 10;
      }
    }
    _CPPErrorToInfoLog("#undef");
  }
  return iVar2;
}

/* _CPPelse @ 0x97b868b0 (740 bytes) */
int _CPPelse(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  puVar1 = PTR__cpp_a7b7c0a4;
  iVar4 = 0;
  iVar3 = (**(code **)(*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20) + 4))();
  do {
    while( true ) {
      while( true ) {
        while( true ) {
          do {
            while( true ) {
              if (iVar3 < 1) {
                return iVar3;
              }
              if (iVar3 == 0x23) break;
              while (iVar3 != 10) {
                iVar3 = (**(code **)(*(int *)(*(int *)puVar1 + 0x20) + 4))
                                  (*(int *)(*(int *)puVar1 + 0x20),param_2);
              }
              iVar3 = (**(code **)(*(int *)(*(int *)puVar1 + 0x20) + 4))
                                (*(int *)(*(int *)puVar1 + 0x20),param_2);
            }
            iVar3 = (**(code **)(*(int *)(*(int *)puVar1 + 0x20) + 4))
                              (*(int *)(*(int *)puVar1 + 0x20),param_2);
          } while (iVar3 != 0x10e);
          iVar2 = *(int *)(param_2 + 8);
          if (((iVar2 != _ifAtom) && (iVar2 != _ifdefAtom)) && (iVar2 != _ifndefAtom)) break;
          iVar4 = iVar4 + 1;
          *(int *)(*(int *)puVar1 + 0x34) = *(int *)(*(int *)puVar1 + 0x34) + 1;
          *(int *)(*(int *)puVar1 + 0x138) = *(int *)(*(int *)puVar1 + 0x138) + 1;
        }
        if (iVar2 != _endifAtom) break;
        iVar4 = iVar4 + -1;
        if (iVar4 < 1) {
          *(undefined4 *)(*(int *)(*(int *)puVar1 + 0x138) * 4 + *(int *)puVar1 + 0x38) = 0;
          *(int *)(*(int *)puVar1 + 0x138) = *(int *)(*(int *)puVar1 + 0x138) + -1;
          iVar4 = *(int *)(*(int *)puVar1 + 0x34);
          if (iVar4 == 0) {
            return 0x10e;
          }
          *(int *)(*(int *)puVar1 + 0x34) = iVar4 + -1;
          return 0x10e;
        }
        *(int *)(*(int *)puVar1 + 0x138) = *(int *)(*(int *)puVar1 + 0x138) + -1;
        *(int *)(*(int *)puVar1 + 0x34) = *(int *)(*(int *)puVar1 + 0x34) + -1;
      }
      if ((param_1 != 0) && (iVar4 == 0)) break;
      if ((iVar2 == _elseAtom) && (iVar2 = ((int (*)())_ChkCorrectElseNesting)(), iVar2 == 0)) {
        _CPPErrorToInfoLog("#else after a #else");
        *(undefined4 *)(*(int *)puVar1 + 0x140) = 1;
      }
    }
    if (iVar2 == _elseAtom) {
      iVar4 = (**(code **)(*(int *)(*(int *)puVar1 + 0x20) + 4))
                        (*(int *)(*(int *)puVar1 + 0x20),param_2);
      if (iVar4 == 10) {
        return 10;
      }
      _CPPWarningToInfoLog
                ("unexpected tokens following #else preprocessor directive - expected a newline");
      do {
        iVar4 = (**(code **)(*(int *)(*(int *)puVar1 + 0x20) + 4))
                          (*(int *)(*(int *)puVar1 + 0x20),param_2);
      } while (iVar4 != 10);
      return 10;
    }
  } while (iVar2 != _elifAtom);
  iVar4 = *(int *)(*(int *)puVar1 + 0x34);
  if (iVar4 != 0) {
    *(int *)(*(int *)puVar1 + 0x34) = iVar4 + -1;
    *(int *)(*(int *)puVar1 + 0x138) = *(int *)(*(int *)puVar1 + 0x138) + -1;
  }
  iVar4 = ((int (*)())_CPPif)(param_2);
  return iVar4;
}

/* _op_div @ 0x97b86c7c (8 bytes) */
int _op_div(param_1, param_2)
  int param_1;
  int param_2;
{
  return param_1 / param_2;
}

/* _op_cmpl @ 0x97b86ca0 (8 bytes) */
int _op_cmpl(param_1)
  uint param_1;
{
  return ~param_1;
}

/* _eval @ 0x97b86cb4 (860 bytes) */
int _eval(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  undefined4 *param_3;
  int *param_4;
  undefined4 *param_5;
{
  bool bVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  while (piVar5 = (int *)PTR__cpp_a7b7c0a4, param_1 == 0x10e) {
    if (param_5[2] == _definedAtom) {
      param_1 = (**(code **)(*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20) + 4))
                          (*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20),param_5);
      bVar1 = param_1 == 0x28;
      if (bVar1) {
        param_1 = (**(code **)(*(int *)(*piVar5 + 0x20) + 4))(*(int *)(*piVar5 + 0x20),param_5);
      }
      if (param_1 != 0x10e) goto LAB_97b86fdc;
      uVar7 = 0;
      iVar4 = ((int (*)())_LookUpSymbol)(_macros,param_5[2]);
      piVar5 = (int *)PTR__cpp_a7b7c0a4;
      if ((iVar4 != 0) && ((*(uint *)(iVar4 + 0x24) & 0x40000000) == 0)) {
        uVar7 = 1;
      }
      *param_3 = uVar7;
      param_1 = (**(code **)(*(int *)(*piVar5 + 0x20) + 4))(*(int *)(*piVar5 + 0x20),param_5);
      if (!bVar1) goto LAB_97b86f0c;
      goto LAB_97b86e70;
    }
    iVar4 = ((int (*)())_MacroExpand)(param_5[2],param_5);
    if (iVar4 == 0) goto LAB_97b86fdc;
    param_1 = (**(code **)(*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20) + 4))
                        (*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20),param_5);
  }
  if (param_1 == 0x10f) {
    *param_3 = *param_5;
    iVar4 = *(int *)(*piVar5 + 0x20);
LAB_97b86e10:
    param_1 = (**(code **)(iVar4 + 4))(iVar4,param_5);
LAB_97b86f0c:
    iVar4 = *param_4;
LAB_97b86f10:
    puVar2 = PTR__cpp_a7b7c0a4;
    if (iVar4 == 0) {
      while ((param_1 != 0x29 && (param_1 != 10))) {
        iVar4 = 0x11;
        piVar5 = &DAT_a7b7cf14;
        while (iVar3 = *piVar5, piVar5 = piVar5 + -3, iVar3 != param_1) {
          iVar4 = iVar4 + -1;
          if (iVar4 < 0) {
            return param_1;
          }
        }
        if (iVar4 < 0) {
          return param_1;
        }
        iVar3 = *(int *)(&UNK_a7b7ce4c + iVar4 * 0xc);
        if (iVar3 <= param_2) {
          return param_1;
        }
        uVar6 = *param_3;
        uVar7 = (**(code **)(*(int *)(*(int *)puVar2 + 0x20) + 4))
                          (*(int *)(*(int *)puVar2 + 0x20),param_5);
        param_1 = ((int (*)())_eval)(uVar7,iVar3,param_3,param_4,param_5);
        uVar7 = (**(code **)(&UNK_a7b7ce50 + iVar4 * 0xc))(uVar6,*param_3);
        *param_3 = uVar7;
        if (*param_4 != 0) {
          return param_1;
        }
      }
    }
  }
  else {
    if (param_1 == 0x28) {
      uVar7 = (**(code **)(*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20) + 4))
                        (*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20),param_5);
      param_1 = ((int (*)())_eval)(uVar7,0,param_3,param_4,param_5);
      iVar4 = *param_4;
      if (iVar4 != 0) goto LAB_97b86f10;
LAB_97b86e70:
      if (param_1 == 0x29) {
        iVar4 = *(int *)(*piVar5 + 0x20);
        goto LAB_97b86e10;
      }
    }
    else {
      iVar4 = 3;
      do {
        if (*(int *)(&_unop + iVar4 * 8) == param_1) {
          if (-1 < iVar4) {
            uVar7 = (**(code **)(*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20) + 4))
                              (*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20),param_5);
            param_1 = ((int (*)())_eval)(uVar7,0xc,param_3,param_4,param_5);
            uVar7 = (**(code **)(&UNK_a7b7cf24 + iVar4 * 8))(*param_3);
            *param_3 = uVar7;
            goto LAB_97b86f0c;
          }
          break;
        }
        iVar4 = iVar4 + -1;
      } while (-1 < iVar4);
    }
LAB_97b86fdc:
    _CPPErrorToInfoLog("incorrect preprocessor directive");
    *param_4 = 1;
    *param_3 = 0;
  }
  return param_1;
}

/* _CPPif @ 0x97b87010 (308 bytes) */
int _CPPif(param_1)
  undefined4 param_1;
{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  int local_20;
  int local_1c [4];
  
  puVar1 = PTR__cpp_a7b7c0a4;
  uVar3 = (**(code **)(*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20) + 4))
                    (*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20),param_1);
  local_1c[0] = 0;
  local_20 = 0;
  *(int *)(*(int *)puVar1 + 0x138) = *(int *)(*(int *)puVar1 + 0x138) + 1;
  iVar2 = *(int *)(*(int *)puVar1 + 0x34) + 1;
  *(int *)(*(int *)puVar1 + 0x34) = iVar2;
  if (iVar2 == 1) {
    iVar2 = *(int *)puVar1;
    _ifloc = **(undefined4 **)(iVar2 + 0x18);
  }
  else {
    iVar2 = *(int *)puVar1;
  }
  if (*(int *)(iVar2 + 0x34) < 0x41) {
    iVar2 = ((int (*)())_eval)(uVar3,0,&local_20,local_1c,param_1);
    if (iVar2 != 10) {
      _CPPWarningToInfoLog
                ("unexpected tokens following the preprocessor directive - expected a newline");
      puVar1 = PTR__cpp_a7b7c0a4;
      do {
        iVar2 = (**(code **)(*(int *)(*(int *)puVar1 + 0x20) + 4))
                          (*(int *)(*(int *)puVar1 + 0x20),param_1);
      } while (iVar2 != 10);
    }
    if ((local_20 == 0) && (local_1c[0] == 0)) {
      iVar2 = ((int (*)())_CPPelse)(1,param_1);
    }
  }
  else {
    _CPPErrorToInfoLog("max #if nesting depth exceeded");
    iVar2 = 0;
  }
  return iVar2;
}

/* _CPPifdef @ 0x97b87144 (348 bytes) */
int _CPPifdef(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  undefined4 uVar6;
  
  puVar1 = PTR__cpp_a7b7c0a4;
  iVar4 = (**(code **)(*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20) + 4))();
  uVar6 = *(undefined4 *)(param_2 + 8);
  iVar2 = *(int *)(*(int *)puVar1 + 0x34) + 1;
  *(int *)(*(int *)puVar1 + 0x34) = iVar2;
  if (iVar2 < 0x41) {
    *(int *)(*(int *)puVar1 + 0x138) = *(int *)(*(int *)puVar1 + 0x138) + 1;
    if (iVar4 == 0x10e) {
      iVar2 = ((int (*)())_LookUpSymbol)(_macros,uVar6);
      iVar4 = (**(code **)(*(int *)(*(int *)puVar1 + 0x20) + 4))
                        (*(int *)(*(int *)puVar1 + 0x20),param_2);
      if (iVar4 != 10) {
        _CPPWarningToInfoLog
                  ("unexpected tokens following #ifdef preprocessor directive - expected a newline")
        ;
        do {
          iVar4 = (**(code **)(*(int *)(*(int *)puVar1 + 0x20) + 4))
                            (*(int *)(*(int *)puVar1 + 0x20),param_2);
        } while (iVar4 != 10);
      }
      iVar3 = 0;
      if ((iVar2 != 0) && ((*(uint *)(iVar2 + 0x24) & 0x40000000) == 0)) {
        iVar3 = 1;
      }
      if (iVar3 != param_1) {
        iVar4 = ((int (*)())_CPPelse)(1,param_2);
      }
    }
    else {
      if (param_1 == 0) {
        pcVar5 = "ifndef";
      }
      else {
        pcVar5 = "ifdef";
      }
      _CPPErrorToInfoLog(pcVar5);
    }
  }
  else {
    _CPPErrorToInfoLog("max #if nesting depth exceeded");
    iVar4 = 0;
  }
  return iVar4;
}

/* _CPPline @ 0x97b872a0 (268 bytes) */
int _CPPline(param_1)
  int *param_1;
{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  
  puVar1 = PTR__cpp_a7b7c0a4;
  iVar2 = (**(code **)(*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20) + 4))
                    (*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20),param_1);
  if (iVar2 == 10) {
    _DecLineNumber();
    _CPPErrorToInfoLog("#line");
    _IncLineNumber();
    iVar2 = 10;
  }
  else {
    if (iVar2 == 0x10f) {
      iVar2 = _atoi((char *)(param_1 + 3));
      *param_1 = iVar2;
      _SetLineNumber();
      iVar2 = *(int *)(*(int *)puVar1 + 0x20);
      iVar2 = (**(code **)(iVar2 + 4))(iVar2,param_1);
      if (iVar2 == 0x10f) {
        iVar2 = _atoi((char *)(param_1 + 3));
        *param_1 = iVar2;
        _SetStringNumber();
        iVar2 = *(int *)(*(int *)puVar1 + 0x20);
        iVar3 = (**(code **)(iVar2 + 4))(iVar2,param_1);
        iVar2 = iVar3;
      }
      else {
        iVar3 = 10;
      }
      if (iVar2 == 10) {
        return iVar3;
      }
    }
    _CPPErrorToInfoLog("#line");
  }
  return iVar2;
}

/* _CPPerror @ 0x97b873ac (232 bytes) */
int _CPPerror(param_1)
  int param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  
  puVar1 = PTR__cpp_a7b7c0a4;
  iVar3 = (**(code **)(*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20) + 4))
                    (*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20),param_1);
  puVar2 = PTR__atable_a7b7c0ac;
  while (iVar3 != 10) {
    if ((iVar3 == 0x10b) || (iVar3 == 0x10f)) {
      iVar3 = param_1 + 0xc;
    }
    else {
      if ((iVar3 == 0x10e) || (iVar3 == 0x116)) {
        iVar3 = *(int *)(param_1 + 8);
      }
      iVar3 = _GetStringOfAtom(*(undefined4 *)puVar2,iVar3);
    }
    _StoreStr(iVar3);
    iVar3 = (**(code **)(*(int *)(*(int *)puVar1 + 0x20) + 4))
                      (*(int *)(*(int *)puVar1 + 0x20),param_1);
  }
  _DecLineNumber();
  _GetStrfromTStr();
  _CPPShInfoLogMsg();
  _ResetTString();
  *(undefined4 *)(*(int *)PTR__cpp_a7b7c0a4 + 0x140) = 1;
  _IncLineNumber();
  return 10;
}

/* _CPPpragma @ 0x97b87494 (528 bytes) */
int _CPPpragma(param_1)
  int param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  size_t sVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  char *pcVar10;
  undefined4 *puVar11;
  int iVar12;
  undefined2 local_40 [10];
  
  iVar12 = 0;
  uVar3 = (**(code **)(*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20) + 4))
                    (*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20),param_1);
  if (uVar3 == 10) {
    _DecLineNumber();
    _CPPErrorToInfoLog("#pragma");
    _IncLineNumber();
    uVar4 = 10;
  }
  else {
    puVar5 = _malloc(0x28);
    puVar2 = PTR__atable_a7b7c0ac;
    iVar8 = 10;
    do {
      iVar9 = iVar8;
      if (iVar8 <= iVar12) {
        iVar9 = iVar8 << 1;
        puVar5 = _realloc(puVar5,iVar8 << 3);
      }
      if (uVar3 == 0x10b) {
LAB_97b8758c:
        pcVar10 = (char *)(param_1 + 0xc);
        sVar6 = _strlen(pcVar10);
        pcVar7 = _malloc(sVar6 + 1);
        puVar5[iVar12] = pcVar7;
      }
      else {
        if ((int)uVar3 < 0x10c) {
          if (uVar3 == 0xffffffff) {
            _CPPShInfoLogMsg("#pragma directive must end with a newline");
            return 0xffffffff;
          }
        }
        else {
          if (uVar3 == 0x10e) {
            pcVar10 = (char *)_GetAtomString(*(undefined4 *)puVar2,*(undefined4 *)(param_1 + 8));
            sVar6 = _strlen(pcVar10);
            pcVar7 = _malloc(sVar6 + 1);
            puVar5[iVar12] = pcVar7;
            goto LAB_97b875f0;
          }
          if (uVar3 == 0x10f) goto LAB_97b8758c;
        }
        local_40[0] = (undefined2)((uVar3 & 0xff) << 8);
        pcVar7 = _malloc(2);
        puVar5[iVar12] = pcVar7;
        pcVar10 = (char *)local_40;
      }
LAB_97b875f0:
      iVar12 = iVar12 + 1;
      _strcpy(pcVar7,pcVar10);
      puVar1 = PTR__cpp_a7b7c0a4;
      uVar3 = (**(code **)(*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20) + 4))
                        (*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20),param_1);
      iVar8 = iVar9;
    } while (uVar3 != 10);
    iVar8 = *(int *)(*(int *)puVar1 + 0x20);
    (**(code **)(iVar8 + 0xc))(iVar8,10,param_1);
    _HandlePragma(puVar5,iVar12);
    iVar8 = *(int *)(*(int *)puVar1 + 0x20);
    uVar4 = (**(code **)(iVar8 + 4))(iVar8,param_1);
    puVar11 = puVar5;
    if (0 < iVar12) {
      do {
        _free((void *)*puVar11);
        iVar12 = iVar12 + -1;
        puVar11 = puVar11 + 1;
      } while (iVar12 != 0);
    }
    _free(puVar5);
  }
  return uVar4;
}

/* _CPPversion @ 0x97b876a4 (256 bytes) */
int _CPPversion(param_1)
  int *param_1;
{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  
  puVar1 = PTR__cpp_a7b7c0a4;
  iVar2 = (**(code **)(*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20) + 4))
                    (*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20),param_1);
  if (*(int *)(*(int *)puVar1 + 0x28) == 1) {
    _CPPShInfoLogMsg("#version must occur before any other statement in the program");
  }
  if (iVar2 == 10) {
    _DecLineNumber();
    _CPPErrorToInfoLog("#version");
    _IncLineNumber();
    iVar2 = 10;
  }
  else {
    if (iVar2 != 0x10f) {
      _CPPErrorToInfoLog("#version");
    }
    iVar2 = _atoi((char *)(param_1 + 3));
    *param_1 = iVar2;
    if (iVar2 != 0x6e) {
      _CPPShInfoLogMsg("Version number not supported by GL2");
    }
    iVar2 = *(int *)(*(int *)puVar1 + 0x20);
    iVar3 = (**(code **)(iVar2 + 4))(iVar2,param_1);
    iVar2 = 10;
    if (iVar3 != 10) {
      _CPPErrorToInfoLog("#version");
      iVar2 = iVar3;
    }
  }
  return iVar2;
}

/* _CPPextension @ 0x97b877a4 (348 bytes) */
int _CPPextension(param_1)
  int param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  char acStack_70 [92];
  
  puVar1 = PTR__cpp_a7b7c0a4;
  iVar3 = (**(code **)(*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20) + 4))
                    (*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20),param_1);
  if (iVar3 == 10) {
    _DecLineNumber();
    _CPPShInfoLogMsg("extension name not specified");
    _IncLineNumber();
    iVar3 = 10;
  }
  else {
    if (iVar3 != 0x10e) {
      _CPPErrorToInfoLog("#extension");
    }
    puVar2 = PTR__atable_a7b7c0ac;
    pcVar4 = (char *)_GetAtomString(*(undefined4 *)PTR__atable_a7b7c0ac,*(undefined4 *)(param_1 + 8)
                                   );
    _strcpy(acStack_70,pcVar4);
    iVar3 = (**(code **)(*(int *)(*(int *)puVar1 + 0x20) + 4))
                      (*(int *)(*(int *)puVar1 + 0x20),param_1);
    if (iVar3 == 0x3a) {
      iVar3 = (**(code **)(*(int *)(*(int *)puVar1 + 0x20) + 4))
                        (*(int *)(*(int *)puVar1 + 0x20),param_1);
      if (iVar3 == 0x10e) {
        uVar5 = _GetAtomString(*(undefined4 *)puVar2,*(undefined4 *)(param_1 + 8));
        _updateExtensionBehavior(acStack_70,uVar5);
        iVar3 = (**(code **)(*(int *)(*(int *)puVar1 + 0x20) + 4))
                          (*(int *)(*(int *)puVar1 + 0x20),param_1);
        if (iVar3 == 10) {
          return 10;
        }
        _CPPErrorToInfoLog("#extension");
        return iVar3;
      }
      pcVar4 = "behavior for extension not specified";
    }
    else {
      pcVar4 = "\':\' missing after extension name";
    }
    _CPPShInfoLogMsg(pcVar4);
  }
  return iVar3;
}

/* _readCPPline @ 0x97b87900 (972 bytes) */
int _readCPPline(param_1)
  int param_1;
{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  
  puVar1 = PTR__cpp_a7b7c0a4;
  uVar5 = 0;
  iVar3 = (**(code **)(*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20) + 4))
                    (*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20),param_1);
  if (iVar3 == 0x10e) {
    iVar2 = *(int *)(param_1 + 8);
    if (iVar2 == _defineAtom) {
      iVar3 = ((int (*)())_CPPdefine)(param_1);
    }
    else {
      if (iVar2 == _elseAtom) {
        iVar3 = ((int (*)())_ChkCorrectElseNesting)();
        if (iVar3 == 0) {
          _CPPErrorToInfoLog("#else after a #else");
          iVar3 = 0;
          uVar5 = 1;
          *(undefined4 *)(*(int *)puVar1 + 0x34) = 0;
          iVar2 = *(int *)puVar1;
          goto LAB_97b87cb4;
        }
        iVar3 = *(int *)puVar1;
        if (*(int *)(iVar3 + 0x34) == 0) {
          _CPPErrorToInfoLog("#else mismatch");
          *(undefined4 *)(*(int *)puVar1 + 0x140) = 1;
          iVar3 = *(int *)puVar1;
        }
        iVar3 = (**(code **)(*(int *)(iVar3 + 0x20) + 4))(*(int *)(iVar3 + 0x20),param_1);
        if (iVar3 != 10) {
          _CPPWarningToInfoLog
                    ("unexpected tokens following #else preprocessor directive - expected a newline"
                    );
          do {
            iVar3 = (**(code **)(*(int *)(*(int *)puVar1 + 0x20) + 4))
                              (*(int *)(*(int *)puVar1 + 0x20),param_1);
          } while (iVar3 != 10);
        }
      }
      else {
        if (iVar2 != _elifAtom) {
          if (iVar2 == _endifAtom) {
            *(undefined4 *)(*(int *)(*(int *)puVar1 + 0x138) * 4 + *(int *)puVar1 + 0x38) = 0;
            *(int *)(*(int *)puVar1 + 0x138) = *(int *)(*(int *)puVar1 + 0x138) + -1;
            iVar2 = *(int *)(*(int *)puVar1 + 0x34);
            if (iVar2 == 0) {
              _CPPErrorToInfoLog("#endif mismatch");
              *(undefined4 *)(*(int *)puVar1 + 0x140) = 1;
            }
            else {
              *(int *)(*(int *)puVar1 + 0x34) = iVar2 + -1;
            }
          }
          else if (iVar2 == _ifAtom) {
            iVar3 = ((int (*)())_CPPif)(param_1);
          }
          else {
            uVar4 = 1;
            if (iVar2 != _ifdefAtom) {
              if (iVar2 != _ifndefAtom) {
                if (iVar2 == _lineAtom) {
                  iVar3 = ((int (*)())_CPPline)(param_1);
                }
                else if (iVar2 == _pragmaAtom) {
                  iVar3 = ((int (*)())_CPPpragma)(param_1);
                }
                else if (iVar2 == _undefAtom) {
                  iVar3 = ((int (*)())_CPPundef)(param_1);
                }
                else if (iVar2 == _errorAtom) {
                  iVar3 = ((int (*)())_CPPerror)(param_1);
                }
                else if (iVar2 == _versionAtom) {
                  uVar5 = 1;
                  iVar3 = ((int (*)())_CPPversion)(param_1);
                }
                else if (iVar2 == _extensionAtom) {
                  iVar3 = ((int (*)())_CPPextension)(param_1);
                }
                else {
                  _StoreStr("Invalid Directive");
                  _GetStringOfAtom(*(undefined4 *)PTR__atable_a7b7c0ac,*(undefined4 *)(param_1 + 8))
                  ;
                  _StoreStr();
                  _GetStrfromTStr();
                  _CPPShInfoLogMsg();
                  _ResetTString();
                }
                goto LAB_97b87c50;
              }
              uVar4 = 0;
            }
            iVar3 = ((int (*)())_CPPifdef)(uVar4,param_1);
          }
          goto LAB_97b87c50;
        }
        iVar3 = *(int *)puVar1;
        if (*(int *)(iVar3 + 0x34) == 0) {
          _CPPErrorToInfoLog("#elif mismatch");
          *(undefined4 *)(*(int *)puVar1 + 0x140) = 1;
          iVar3 = *(int *)puVar1;
        }
        iVar3 = (**(code **)(*(int *)(iVar3 + 0x20) + 4))(*(int *)(iVar3 + 0x20),param_1);
        while (iVar3 != 10) {
          iVar3 = (**(code **)(*(int *)(*(int *)puVar1 + 0x20) + 4))
                            (*(int *)(*(int *)puVar1 + 0x20),param_1);
        }
      }
      iVar3 = ((int (*)())_CPPelse)(0,param_1);
    }
  }
LAB_97b87c50:
  puVar1 = PTR__cpp_a7b7c0a4;
  if ((iVar3 != 10) && (iVar3 != 0)) {
    while (iVar3 != -1) {
      iVar3 = (**(code **)(*(int *)(*(int *)puVar1 + 0x20) + 4))
                        (*(int *)(*(int *)puVar1 + 0x20),param_1);
      if ((iVar3 == 10) || (iVar3 == 0)) break;
    }
  }
  uVar5 = uVar5 ^ 1;
  iVar2 = *(int *)PTR__cpp_a7b7c0a4;
LAB_97b87cb4:
  *(uint *)(iVar2 + 0x28) = uVar5;
  return iVar3;
}

/* _FreeMacro @ 0x97b87ccc (8 bytes) */
int _FreeMacro(param_1)
  int param_1;
{
  ((int (*)())_DeleteTokenStream)(*(undefined4 *)(param_1 + 8));
  return;
}

/* _PushEofSrc @ 0x97b87ce0 (120 bytes) */
int _PushEofSrc()
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  
  puVar3 = _malloc(0x18);
  uVar2 = DAT_a7b7b010;
  uVar1 = DAT_a7b7b00c;
  iVar4 = *(int *)PTR__cpp_a7b7c0a4;
  *puVar3 = 0;
  puVar3[5] = 0;
  puVar3[2] = uVar2;
  puVar3[3] = uVar1;
  puVar3[4] = 0;
  puVar3[1] = uVar2;
  *puVar3 = *(undefined4 *)(iVar4 + 0x20);
  *(undefined4 **)(iVar4 + 0x20) = puVar3;
  return;
}

/* _PopEofSrc @ 0x97b87d58 (64 bytes) */
int _PopEofSrc()
{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(*(int *)PTR__cpp_a7b7c0a4 + 0x20);
  if (puVar1[1] != DAT_a7b7b010) {
    return;
  }
  *(undefined4 *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20) = *puVar1;
  _free(puVar1);
  return;
}

/* _PrescanMacroArg @ 0x97b87d98 (276 bytes) */
int _PrescanMacroArg(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  ((int (*)())_RewindTokenStream)();
  do {
    iVar2 = ((int (*)())_ReadToken)(param_1,param_2);
    if ((iVar2 == 0x10e) &&
       (iVar3 = ((int (*)())_LookUpSymbol)(_macros,*(undefined4 *)(param_2 + 8)), iVar3 != 0)) break;
  } while (0 < iVar2);
  if (0 < iVar2) {
    uVar4 = ((int (*)())_NewTokenStream)("macro arg",0);
    ((int (*)())_PushEofSrc)();
    _ReadFromTokenStream(param_1,0,0);
    puVar1 = PTR__cpp_a7b7c0a4;
    while (iVar2 = (**(code **)(*(int *)(*(int *)puVar1 + 0x20) + 4))
                             (*(int *)(*(int *)puVar1 + 0x20),param_2), 0 < iVar2) {
      if ((iVar2 != 0x10e) ||
         (iVar3 = ((int (*)())_MacroExpand)(*(undefined4 *)(param_2 + 8),param_2), iVar3 == 0)) {
        ((int (*)())_RecordToken)(uVar4,iVar2,param_2);
      }
    }
    ((int (*)())_PopEofSrc)();
    ((int (*)())_DeleteTokenStream)(param_1);
    param_1 = uVar4;
  }
  return param_1;
}

/* _macro_scan @ 0x97b87eac (336 bytes) */
int _macro_scan(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  bool bVar1;
  undefined *puVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  void *pvVar6;
  int iVar7;
  
  iVar5 = ((int (*)())_ReadToken)(*(undefined4 *)(param_1[6] + 8));
  puVar2 = PTR__cpp_a7b7c0a4;
  if (iVar5 == 0x10e) {
    iVar7 = *(int *)param_1[6] + -1;
    bVar1 = iVar7 < 0;
    if (!bVar1) {
      piVar4 = (int *)(iVar7 * 4 + ((int *)param_1[6])[1]);
      do {
        iVar3 = *piVar4;
        piVar4 = piVar4 + -1;
        if (iVar3 == *(int *)(param_2 + 8)) {
          if (!bVar1) {
            _ReadFromTokenStream
                      (*(undefined4 *)(iVar7 * 4 + param_1[7]),*(undefined4 *)(param_2 + 8),0);
            goto LAB_97b87fc4;
          }
          break;
        }
        iVar7 = iVar7 + -1;
        bVar1 = iVar7 < 0;
      } while (!bVar1);
    }
  }
  if (0 < iVar5) {
    return;
  }
  *(uint *)(param_1[6] + 0xc) = *(uint *)(param_1[6] + 0xc) & 0x7fffffff;
  *(undefined4 *)(*(int *)puVar2 + 0x20) = *param_1;
  pvVar6 = (void *)param_1[7];
  if (pvVar6 != (void *)0x0) {
    iVar5 = *(int *)param_1[6] + -1;
    if (-1 < iVar5) {
      while( true ) {
        ((int (*)())_DeleteTokenStream)(*(undefined4 *)(iVar5 * 4 + (int)pvVar6));
        iVar5 = iVar5 + -1;
        if (iVar5 < 0) break;
        pvVar6 = (void *)param_1[7];
      }
      pvVar6 = (void *)param_1[7];
    }
    _free(pvVar6);
  }
  _free(param_1);
LAB_97b87fc4:
                    
                    
  (**(code **)(*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20) + 4))
            (*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20),param_2);
  return;
}

/* _MacroExpand @ 0x97b87ffc (1024 bytes) */
int _MacroExpand(param_1, param_2)
  int param_1;
  int *param_2;
{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  undefined *puVar4;
  undefined *puVar5;
  int iVar6;
  undefined4 *puVar7;
  void *pvVar8;
  int iVar9;
  char *pcVar10;
  undefined4 uVar11;
  int *piVar12;
  int iVar13;
  int iVar14;
  
  iVar6 = ((int (*)())_LookUpSymbol)(_macros,param_1);
  if (param_1 == ___LINE__Atom) {
    iVar6 = _GetLineNumber();
  }
  else {
    if (param_1 != ___FILE__Atom) {
      if (param_1 != ___VERSION__Atom) {
        if ((iVar6 == 0) || ((*(uint *)(iVar6 + 0x24) & 0x40000000) != 0)) {
          return 0;
        }
        if ((int)*(uint *)(iVar6 + 0x24) < 0) {
          return 0;
        }
        puVar7 = _malloc(0x20);
        uVar11 = DAT_a7b7b008;
        iVar13 = *(int *)PTR__cpp_a7b7c0a4;
        puVar7[4] = 0;
        puVar7[5] = 0;
        puVar7[6] = 0;
        puVar7[7] = 0;
        *puVar7 = 0;
        puVar7[2] = 0;
        puVar7[3] = 0;
        puVar7[1] = uVar11;
        puVar7[5] = *(undefined4 *)(*(int *)(iVar13 + 0x20) + 0x14);
        uVar11 = *(undefined4 *)(*(int *)(iVar13 + 0x20) + 0x10);
        puVar7[6] = iVar6 + 0x18;
        puVar7[4] = uVar11;
        if (*(int *)(iVar6 + 0x1c) != 0) {
          iVar13 = (**(code **)(*(int *)(iVar13 + 0x20) + 4))(*(int *)(iVar13 + 0x20),param_2);
          if (iVar13 != 0x28) {
            _UngetToken(iVar13,param_2);
            param_2[2] = param_1;
            return 0;
          }
          iVar13 = 0;
          pvVar8 = _malloc(*(int *)puVar7[6] << 2);
          puVar7[7] = pvVar8;
          if (0 < *(int *)puVar7[6]) {
            do {
              uVar11 = ((int (*)())_NewTokenStream)("macro arg",0);
              iVar14 = iVar13 * 4;
              iVar13 = iVar13 + 1;
              *(undefined4 *)(iVar14 + puVar7[7]) = uVar11;
            } while (iVar13 < *(int *)puVar7[6]);
          }
          puVar4 = PTR__cpp_a7b7c0a4;
          iVar13 = 0;
          bVar3 = false;
LAB_97b881d8:
          iVar14 = 0;
          do {
            iVar9 = (**(code **)(*(int *)(*(int *)puVar4 + 0x20) + 4))
                              (*(int *)(*(int *)puVar4 + 0x20),param_2);
            puVar5 = PTR__cpp_a7b7c0a4;
            bVar1 = 0 < iVar9;
            if (!bVar1) goto LAB_97b8830c;
            piVar12 = (int *)puVar7[6];
            bVar2 = iVar9 == 0x29;
            if ((*piVar12 == 0) && (!bVar2)) goto LAB_97b88284;
            if (iVar14 == 0) {
              if (iVar9 == 0x2c) goto LAB_97b88284;
              if (bVar2) {
                if ((*piVar12 != 1) || (bVar3)) {
                  iVar13 = iVar13 + 1;
                }
                goto LAB_97b88294;
              }
            }
            if (iVar9 == 0x28) {
              iVar14 = iVar14 + 1;
            }
            if (bVar2) {
              iVar14 = iVar14 + -1;
            }
            bVar3 = true;
            ((int (*)())_RecordToken)(*(undefined4 *)(iVar13 * 4 + puVar7[7]),iVar9,param_2);
          } while( true );
        }
        goto LAB_97b883b8;
      }
      param_2[3] = 0x31303000;
      iVar6 = _atoi((char *)(param_2 + 3));
      *param_2 = iVar6;
      goto LAB_97b88078;
    }
    iVar6 = _GetStringNumber();
  }
  *param_2 = iVar6;
  _sprintf((char *)(param_2 + 3),"%d",iVar6);
LAB_97b88078:
  _UngetToken(0x10f,param_2);
  return 1;
LAB_97b88284:
  iVar13 = iVar13 + 1;
  if (*piVar12 <= iVar13) goto LAB_97b88294;
  goto LAB_97b881d8;
LAB_97b88294:
  if (iVar13 < *piVar12) {
    pcVar10 = "Too few args in Macro ";
LAB_97b8834c:
    _StoreStr(pcVar10);
    _GetStringOfAtom(*(undefined4 *)PTR__atable_a7b7c0ac,param_1);
    _StoreStr();
    _GetStrfromTStr();
    _CPPShInfoLogMsg();
    _ResetTString();
    piVar12 = (int *)puVar7[6];
  }
  else if (!bVar2) {
    iVar13 = 0;
    if (-1 < iVar9) {
      bVar3 = false;
      do {
        if (bVar3) {
          iVar13 = iVar13 + -1;
        }
        iVar14 = (**(code **)(*(int *)(*(int *)puVar5 + 0x20) + 4))
                           (*(int *)(*(int *)puVar5 + 0x20),param_2);
        if (iVar14 == 0x28) {
          iVar13 = iVar13 + 1;
        }
        bVar1 = 0 < iVar14;
      } while ((-1 < iVar14) && ((bVar3 = iVar14 == 0x29, 0 < iVar13 || (!bVar3))));
    }
    if (!bVar1) {
LAB_97b8830c:
      _StoreStr("EOF in Macro ");
      _GetStringOfAtom(*(undefined4 *)PTR__atable_a7b7c0ac,param_1);
      _StoreStr();
      _GetStrfromTStr();
      _CPPShInfoLogMsg();
      _ResetTString();
      return 1;
    }
    pcVar10 = "Too many args in Macro ";
    goto LAB_97b8834c;
  }
  iVar13 = 0;
  if (0 < *piVar12) {
    do {
      iVar14 = iVar13 * 4;
      iVar13 = iVar13 + 1;
      uVar11 = ((int (*)())_PrescanMacroArg)(*(undefined4 *)(iVar14 + puVar7[7]),param_2);
      *(undefined4 *)(iVar14 + puVar7[7]) = uVar11;
    } while (iVar13 < *(int *)puVar7[6]);
  }
LAB_97b883b8:
  puVar4 = PTR__cpp_a7b7c0a4;
  *puVar7 = *(undefined4 *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20);
  *(uint *)(iVar6 + 0x24) = *(uint *)(iVar6 + 0x24) | 0x80000000;
  ((int (*)())_RewindTokenStream)(*(undefined4 *)(iVar6 + 0x20));
  *(undefined4 **)(*(int *)puVar4 + 0x20) = puVar7;
  return 1;
}

/* _ChkCorrectElseNesting @ 0x97b883fc (72 bytes) */
int _ChkCorrectElseNesting()
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x138) * 4 + *(int *)PTR__cpp_a7b7c0a4;
  if (*(int *)(iVar1 + 0x38) != 0) {
    return 0;
  }
  *(undefined4 *)(iVar1 + 0x38) = 1;
  return 1;
}

/* _InitCPPStruct @ 0x97b88444 (144 bytes) */
int _InitCPPStruct()
{
  undefined4 uVar1;
  int *piVar2;
  undefined1 *puVar3;
  int iVar4;
  
  piVar2 = _malloc(0x158);
  uVar1 = 0;
  _cpp = piVar2;
  if (piVar2 != (int *)0x0) {
    _refCount = _refCount + 1;
    *piVar2 = (int)(piVar2 + 5);
    iVar4 = 0x10;
    puVar3 = (undefined1 *)((int)piVar2 + 0x13);
    do {
      *puVar3 = 0;
      puVar3 = puVar3 + -1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    ((int (*)())_ResetPreprocessor)();
    uVar1 = 1;
  }
  return uVar1;
}

/* _ResetPreprocessor @ 0x97b884d4 (196 bytes) */
int _ResetPreprocessor()
{
  int iVar1;
  
  *(undefined2 *)(_cpp + 0x14) = 0;
  *(undefined2 *)(_cpp + 0x16) = 0;
  *(undefined4 *)(_cpp + 0x2c) = 0;
  *(undefined4 *)(_cpp + 0x140) = 0;
  *(undefined4 *)(_cpp + 0x34) = 0;
  *(undefined4 *)(_cpp + 0x138) = 0;
  iVar1 = *(int *)(_cpp + 0x138);
  while (iVar1 < 0x40) {
    *(undefined4 *)(*(int *)(_cpp + 0x138) * 4 + _cpp + 0x38) = 0;
    *(int *)(_cpp + 0x138) = *(int *)(_cpp + 0x138) + 1;
    iVar1 = *(int *)(_cpp + 0x138);
  }
  *(undefined4 *)(_cpp + 0x138) = 0;
  *(uint *)(_cpp + 0x154) = *(uint *)(_cpp + 0x154) & 0x7fffffff;
  return 1;
}

/* _InitPreprocessor @ 0x97b88598 (136 bytes) */
int _InitPreprocessor()
{
  undefined *puVar1;
  int iVar2;
  bool bVar3;
  
  ((int (*)())_FreeCPPStruct)();
  ((int (*)())_InitCPPStruct)();
  *(undefined4 *)(_cpp + 0xc) = 1;
  puVar1 = PTR__atable_a7b7c0ac;
  *(char **)(_cpp + 4) = "generic";
  iVar2 = _InitAtomTable(*(undefined4 *)puVar1,0);
  bVar3 = true;
  if (iVar2 != 0) {
    iVar2 = ((int (*)())_InitScanner)(_cpp);
    bVar3 = iVar2 == 0;
  }
  return bVar3;
}

/* _FreeCPPStruct @ 0x97b88620 (92 bytes) */
int _FreeCPPStruct()
{
  if (_refCount != 0) {
    _free(_cpp);
    _refCount = _refCount + -1;
  }
  return 1;
}

/* _FinalizePreprocessor @ 0x97b8867c (72 bytes) */
int _FinalizePreprocessor()
{
  ((int (*)())_FreeAtomTable)(*(undefined4 *)PTR__atable_a7b7c0ac);
  ((int (*)())_FreeCPPStruct)();
  _FreeScanner();
  return 0;
}

/* _mem_CreatePool @ 0x97b886c4 (164 bytes) */
int _mem_CreatePool(param_1, param_2)
  uint param_1;
  uint param_2;
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  if (param_2 == 0) {
    param_2 = 8;
  }
  if (param_1 == 0) {
    param_1 = 0x10000;
  }
  uVar3 = param_2 - 1;
  puVar1 = (undefined4 *)0x0;
  if (((param_2 & uVar3) == 0) && (0x17 < param_1)) {
    if ((param_1 & uVar3) == 0) {
      puVar2 = _malloc(param_1);
      puVar1 = (undefined4 *)0x0;
      if (puVar2 != (undefined4 *)0x0) {
        puVar2[2] = (int)puVar2 + param_1;
        puVar2[5] = 0;
        puVar2[1] = (int)puVar2 + param_2 + 0x17 & ~uVar3;
        *puVar2 = 0;
        puVar2[3] = param_1;
        puVar2[4] = uVar3;
        puVar1 = puVar2;
      }
    }
  }
  return puVar1;
}

/* _mem_FreePool @ 0x97b88768 (108 bytes) */
int _mem_FreePool(param_1)
  undefined4 *param_1;
{
  int *piVar1;
  void *pvVar2;
  
  for (piVar1 = (int *)param_1[5]; piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {
    (*(code *)piVar1[1])(piVar1[2]);
  }
  while (param_1 != (void *)0x0) {
    pvVar2 = (void *)*param_1;
    _free(param_1);
    param_1 = pvVar2;
  }
  return;
}

/* _mem_Alloc @ 0x97b887d4 (224 bytes) */
int _mem_Alloc(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = param_1[4];
  uVar2 = param_1[1];
  uVar1 = param_2 + uVar5 & ~uVar5;
  if (uVar1 == 0) {
    uVar1 = uVar5;
  }
  uVar4 = uVar2 + uVar1;
  param_1[1] = uVar4;
  if (((uint)param_1[2] < uVar4) || (uVar4 < uVar2)) {
    param_1[1] = uVar2;
    uVar1 = uVar1 + uVar5 + 4 & ~uVar5;
    if (uVar1 < (uint)param_1[3]) {
      puVar3 = _malloc(param_1[3]);
      if (puVar3 == (undefined4 *)0x0) {
        return 0;
      }
      param_1[1] = (int)puVar3 + uVar1;
      param_1[2] = (int)puVar3 + param_1[3];
    }
    else {
      puVar3 = _malloc(uVar1);
      if (puVar3 == (undefined4 *)0x0) {
        return 0;
      }
    }
    *puVar3 = *param_1;
    *param_1 = puVar3;
    uVar2 = (int)puVar3 + param_1[4] + 4 & ~param_1[4];
  }
  return uVar2;
}

/* _mem_AddCleanup @ 0x97b888b4 (112 bytes) */
int _mem_AddCleanup(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  *(uint *)(param_1 + 4) = *(int *)(param_1 + 4) + 3U & 0xfffffffc;
  puVar2 = (undefined4 *)((int (*)())_mem_Alloc)(param_1,0xc);
  uVar1 = 0xffffffff;
  if (puVar2 != (undefined4 *)0x0) {
    uVar1 = *(undefined4 *)(param_1 + 0x14);
    puVar2[1] = param_2;
    *puVar2 = uVar1;
    uVar1 = 0;
    puVar2[2] = param_3;
    *(undefined4 **)(param_1 + 0x14) = puVar2;
  }
  return uVar1;
}

/* _InitScanner @ 0x97b88930 (116 bytes) */
int _InitScanner(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = ((int (*)())_InitCPP)();
  if (iVar1 != 0) {
    *(int *)(param_1 + 0x18) = param_1 + 0x30;
    *(undefined4 *)(param_1 + 0x28) = 0;
    *(undefined **)(param_1 + 0x20) = &_eof_inputsrc;
    *(undefined4 *)(param_1 + 0x24) = 10;
    *(undefined4 *)(param_1 + 0x1c) = 0;
    *(undefined2 *)(param_1 + 0x30) = 0;
    *(undefined2 *)(param_1 + 0x32) = 0;
  }
  return iVar1 != 0;
}

/* _str_getch @ 0x97b889a8 (228 bytes) */
int _str_getch(param_1)
  undefined4 *param_1;
{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  
  iVar5 = *(int *)PTR__cpp_a7b7c0a4;
  while( true ) {
    pcVar4 = (char *)param_1[6];
    if (*pcVar4 != '\0') {
      if (*pcVar4 == '\n') {
        param_1[5] = param_1[5] + 1;
        _IncLineNumber();
        pcVar4 = (char *)param_1[6];
      }
      cVar1 = *pcVar4;
      param_1[6] = pcVar4 + 1;
      return (int)cVar1;
    }
    iVar3 = *(int *)(iVar5 + 0x144) + 1;
    *(int *)(iVar5 + 0x144) = iVar3;
    if (*(int *)(iVar5 + 0x14c) <= iVar3) break;
    _free(param_1);
    _SetStringNumber(*(undefined4 *)(iVar5 + 0x144));
    _SetLineNumber(1);
    ((int (*)())_ScanFromString)(*(undefined4 *)(*(int *)(iVar5 + 0x144) * 4 + *(int *)(iVar5 + 0x150)));
    param_1 = *(undefined4 **)(iVar5 + 0x20);
  }
  uVar2 = *param_1;
  *(undefined4 *)(iVar5 + 0x144) = 0;
  *(undefined4 *)(iVar5 + 0x20) = uVar2;
  _free(param_1);
  return -1;
}

/* _ScanFromString @ 0x97b88af4 (148 bytes) */
int _ScanFromString(param_1)
  undefined4 param_1;
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  
  puVar3 = _malloc(0x1c);
  uVar1 = DAT_a7b7b038;
  uVar2 = DAT_a7b7b034;
  iVar4 = *(int *)PTR__cpp_a7b7c0a4;
  puVar3[4] = 0;
  puVar3[1] = uVar1;
  uVar1 = DAT_a7b7b030;
  *puVar3 = 0;
  puVar3[6] = param_1;
  puVar3[5] = 1;
  puVar3[2] = uVar2;
  puVar3[3] = uVar1;
  *puVar3 = *(undefined4 *)(iVar4 + 0x20);
  *(undefined4 **)(iVar4 + 0x20) = puVar3;
  return 1;
}

/* _lBuildFloatValue @ 0x97b88b88 (272 bytes) */
double _lBuildFloatValue(int param_1,int param_2,uint param_3)

{
  float fVar1;
  char *pcVar2;
  uint uVar3;
  int iVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  
  iVar4 = 0;
  dVar6 = DOUBLE_97c30a48;
  if (0 < param_2) {
    do {
      pcVar2 = (char *)(param_1 + iVar4);
      iVar4 = iVar4 + 1;
      dVar6 = dVar6 * DOUBLE_97c30a50 +
              ((double)CONCAT44(0x43300000,(int)*pcVar2 - 0x30U ^ 0x80000000) - DOUBLE_97c30a58);
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  if (param_3 != 0) {
    dVar5 = DOUBLE_97c30a50;
    dVar7 = DOUBLE_97c30a60;
    for (uVar3 = ((int)param_3 >> 0x1f ^ param_3) - ((int)param_3 >> 0x1f); uVar3 != 0;
        uVar3 = (int)uVar3 >> 1) {
      if ((uVar3 & 1) != 0) {
        dVar7 = dVar7 * dVar5;
      }
      dVar5 = dVar5 * dVar5;
    }
    if ((int)param_3 < 0) {
      dVar6 = dVar6 / dVar7;
    }
    else {
      dVar6 = dVar6 * dVar7;
    }
  }
  fVar1 = (float)dVar6;
  if ((((uint)fVar1 & 0x7f800000) == 0x7f800000) && (((uint)fVar1 & 0x7fffff) == 0)) {
    _CPPErrorToInfoLog(" ERROR___FP_CONST_OVERFLOW");
  }
  return (double)fVar1;
}

/* _lFloatConst @ 0x97b88c98 (588 bytes) */
int _lFloatConst(param_1, param_2, param_3, param_4)
  char *param_1;
  int param_2;
  int param_3;
  int param_4;
{
  undefined *puVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  double dVar9;
  
  puVar1 = PTR__cpp_a7b7c0a4;
  iVar5 = 0;
  iVar6 = 0;
  iVar8 = param_2;
  if (param_3 == 0x2e) {
    param_1[param_2] = '.';
    iVar8 = param_2 + 1;
    iVar3 = *(int *)(*(int *)puVar1 + 0x20);
    param_3 = (**(code **)(iVar3 + 8))(iVar3,param_4);
    uVar7 = param_3 - 0x30;
    while (uVar7 < 10) {
      if (iVar8 < 0x80) {
        iVar5 = iVar5 + 1;
        if ((0 < iVar8) || (param_3 != 0x30)) {
          param_1[iVar8] = (char)param_3;
          param_2 = param_2 + 1;
          iVar8 = iVar8 + 1;
        }
        iVar3 = *(int *)(*(int *)puVar1 + 0x20);
        param_3 = (**(code **)(iVar3 + 8))(iVar3,param_4);
        uVar7 = param_3 - 0x30;
      }
      else {
        iVar8 = 1;
        param_2 = 1;
        _CPPErrorToInfoLog("ERROR___FP_CONST_TOO_LONG");
      }
    }
  }
  puVar1 = PTR__cpp_a7b7c0a4;
  if ((param_3 != 0x65) && (param_3 != 0x45)) goto LAB_97b88e60;
  param_1[iVar8] = (char)param_3;
  iVar3 = iVar8 + 1;
  iVar4 = 1;
  param_3 = (**(code **)(*(int *)(*(int *)puVar1 + 0x20) + 8))
                      (*(int *)(*(int *)puVar1 + 0x20),param_4);
  if (param_3 == 0x2b) {
    param_1[iVar3] = '+';
    iVar3 = *(int *)puVar1;
LAB_97b88de8:
    param_3 = (**(code **)(*(int *)(iVar3 + 0x20) + 8))(*(int *)(iVar3 + 0x20),param_4);
    iVar3 = iVar8 + 2;
  }
  else if (param_3 == 0x2d) {
    param_1[iVar3] = '-';
    iVar3 = *(int *)puVar1;
    iVar4 = -1;
    goto LAB_97b88de8;
  }
  iVar8 = iVar3;
  puVar1 = PTR__cpp_a7b7c0a4;
  if (param_3 - 0x30U < 10) {
    do {
      param_1[iVar8] = (char)param_3;
      iVar8 = iVar8 + 1;
      iVar6 = iVar6 * 10 + param_3 + -0x30;
      param_3 = (**(code **)(*(int *)(*(int *)puVar1 + 0x20) + 8))
                          (*(int *)(*(int *)puVar1 + 0x20),param_4);
    } while (param_3 - 0x30U < 10);
  }
  else {
    _CPPErrorToInfoLog("ERROR___ERROR_IN_EXPONENT");
  }
  iVar6 = iVar6 * iVar4;
LAB_97b88e60:
  if (iVar8 == 0) {
    builtin_strncpy(param_1,"0.0",4);
    fVar2 = 0.0;
  }
  else {
    param_1[iVar8] = '\0';
    dVar9 = (double)((double (*)())_lBuildFloatValue)(param_1,param_2,iVar6 - iVar5);
    fVar2 = (float)dVar9;
  }
  *(float *)(param_4 + 4) = fVar2;
  _strcpy((char *)(param_4 + 0xc),param_1);
  (**(code **)(*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20) + 0xc))
            (*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20),param_3,param_4);
  return 0x10b;
}

/* _byte_scan @ 0x97b88ee4 (3060 bytes) */
int _byte_scan(param_1, param_2)
  undefined4 param_1;
  uint *param_2;
{
  bool bVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined1 *puVar7;
  int iVar8;
  int iVar9;
  uint *puVar10;
  undefined1 local_2d0 [144];
  undefined1 local_240 [536];
  
  uVar6 = 0;
  iVar8 = *(int *)PTR__cpp_a7b7c0a4;
LAB_97b88f18:
  *param_2 = 0;
  iVar3 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
  while (((iVar3 == 0x20 || (iVar3 == 9)) || (iVar3 == 0xd))) {
    *param_2 = 1;
    iVar3 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
  }
  if (iVar3 != -1) {
    *(undefined2 *)(iVar8 + 0x30) = *(undefined2 *)(*(int *)(iVar8 + 0x20) + 0x12);
    *(undefined2 *)(iVar8 + 0x32) = *(undefined2 *)(*(int *)(iVar8 + 0x20) + 0x16);
  }
  iVar9 = 0;
  switch(iVar3) {
  default:
    return iVar3;
  case 0x21:
    iVar3 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
    if (iVar3 != 0x3d) {
      (**(code **)(*(int *)(iVar8 + 0x20) + 0xc))(*(int *)(iVar8 + 0x20),iVar3,param_2);
      return 0x21;
    }
    return 0x113;
  case 0x22:
    iVar3 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
    bVar1 = iVar3 == 0x22;
    if (((bVar1) || (iVar3 == 10)) || (iVar3 == -1)) goto LAB_97b89c74;
    puVar7 = local_240;
    goto LAB_97b89bf4;
  case 0x25:
    iVar3 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
    if (iVar3 == 0x3d) {
      return 0x104;
    }
    if (iVar3 != 0x3e) {
      (**(code **)(*(int *)(iVar8 + 0x20) + 0xc))(*(int *)(iVar8 + 0x20),iVar3,param_2);
      return 0x25;
    }
    return 0x120;
  case 0x26:
    iVar3 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
    if (iVar3 == 0x26) {
      return 0x101;
    }
    if (iVar3 != 0x3d) {
      (**(code **)(*(int *)(iVar8 + 0x20) + 0xc))(*(int *)(iVar8 + 0x20),iVar3,param_2);
      return 0x26;
    }
    return 0x11a;
  case 0x2a:
    iVar3 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
    if (iVar3 != 0x3d) {
      (**(code **)(*(int *)(iVar8 + 0x20) + 0xc))(*(int *)(iVar8 + 0x20),iVar3,param_2);
      return 0x2a;
    }
    return 0x107;
  case 0x2b:
    iVar3 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
    if (iVar3 == 0x2b) {
      return 0x115;
    }
    if (iVar3 != 0x3d) {
      (**(code **)(*(int *)(iVar8 + 0x20) + 0xc))(*(int *)(iVar8 + 0x20),iVar3,param_2);
      return 0x2b;
    }
    return 0x105;
  case 0x2d:
    iVar3 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
    if (iVar3 == 0x2d) {
      return 0x112;
    }
    if (iVar3 != 0x3d) {
      (**(code **)(*(int *)(iVar8 + 0x20) + 0xc))(*(int *)(iVar8 + 0x20),iVar3,param_2);
      return 0x2d;
    }
    return 0x103;
  case 0x2e:
    iVar3 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
    if (9 < iVar3 - 0x30U) {
      if (iVar3 != 0x2e) {
        (**(code **)(*(int *)(iVar8 + 0x20) + 0xc))(*(int *)(iVar8 + 0x20),iVar3,param_2);
        return 0x2e;
      }
      return -1;
    }
    (**(code **)(*(int *)(iVar8 + 0x20) + 0xc))(*(int *)(iVar8 + 0x20),iVar3,param_2);
    iVar9 = 0;
    iVar4 = 0x2e;
    goto LAB_97b89a54;
  case 0x2f:
    iVar3 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
    if (iVar3 != 0x2f) break;
    do {
      iVar3 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
      if (iVar3 == 10) {
        return 10;
      }
    } while (iVar3 != -1);
switchD_97b88fcc_caseD_ffffffff:
    return -1;
  case 0x30:
    *(char *)(param_2 + 3) = (char)iVar3;
    iVar9 = 1;
    iVar4 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
    if ((iVar4 == 0x78) || (iVar4 == 0x58)) {
      *(char *)((int)param_2 + 0xd) = (char)iVar4;
      iVar9 = 2;
      iVar4 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
      uVar5 = iVar4 - 0x30;
      if ((uVar5 < 10) || ((iVar4 - 0x41U < 6 || (iVar4 - 0x61U < 6)))) {
        puVar7 = (undefined1 *)((int)param_2 + 0xe);
        bVar1 = false;
        uVar6 = 0;
        do {
          *puVar7 = (char)iVar4;
          iVar9 = iVar9 + 1;
          puVar7 = puVar7 + 1;
          if ((int)uVar6 < 0x10000000) {
            if ((9 < uVar5) && (uVar5 = iVar4 - 0x37, 5 < iVar4 - 0x41U)) {
              uVar5 = iVar4 - 0x57;
            }
            uVar6 = uVar6 << 4 | uVar5;
          }
          else {
            if (!bVar1) {
              _CPPErrorToInfoLog("ERROR___HEX_CONST_OVERFLOW");
            }
            bVar1 = true;
          }
          iVar4 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
          uVar5 = iVar4 - 0x30;
        } while (((uVar5 < 10) || (iVar4 - 0x41U < 6)) || (iVar4 - 0x61U < 6));
      }
      else {
        _CPPErrorToInfoLog("ERROR___ERROR_IN_HEX_CONSTANT");
      }
      goto LAB_97b89458;
    }
    uVar5 = iVar4 - 0x30;
    if (uVar5 < 8) {
      bVar1 = false;
      uVar6 = 0;
      puVar7 = (undefined1 *)((int)param_2 + 0xd);
      do {
        *puVar7 = (char)iVar4;
        iVar9 = iVar9 + 1;
        puVar7 = puVar7 + 1;
        if ((int)uVar6 < 0x20000000) {
          uVar6 = uVar6 << 3 | uVar5;
        }
        else {
          if (!bVar1) {
            _CPPErrorToInfoLog("ERROR___OCT_CONST_OVERFLOW");
          }
          bVar1 = true;
        }
        iVar4 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
        uVar5 = iVar4 - 0x30;
      } while (uVar5 < 8);
      if ((((iVar4 == 0x2e) || (iVar4 == 0x65)) ||
          ((iVar4 == 0x66 || ((iVar4 == 0x68 || (iVar4 == 0x78)))))) || (iVar4 == 0x45))
      goto LAB_97b89a54;
LAB_97b89458:
      *(undefined1 *)((int)param_2 + iVar9 + 0xc) = 0;
      (**(code **)(*(int *)(iVar8 + 0x20) + 0xc))(*(int *)(iVar8 + 0x20),iVar4,param_2);
      *param_2 = uVar6;
      return 0x10f;
    }
    iVar3 = 0x30;
    (**(code **)(*(int *)(iVar8 + 0x20) + 0xc))(*(int *)(iVar8 + 0x20),iVar4,param_2);
switchD_97b88fcc_caseD_31:
    puVar7 = (undefined1 *)((int)param_2 + iVar9 + 0xc);
    iVar4 = iVar3;
    do {
      if (iVar9 < 0x80) {
        if ((0 < iVar9) || (iVar4 != 0x30)) {
          *puVar7 = (char)iVar4;
          iVar9 = iVar9 + 1;
          puVar7 = puVar7 + 1;
        }
        iVar4 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
      }
    } while (iVar4 - 0x30U < 10);
    if (((((iVar4 != 0x2e) && (iVar4 != 0x65)) && (iVar4 != 0x66)) &&
        ((iVar4 != 0x68 && (iVar4 != 0x78)))) && (iVar4 != 0x45)) {
      *(undefined1 *)((int)param_2 + iVar9 + 0xc) = 0;
      uVar6 = 0;
      bVar1 = false;
      (**(code **)(*(int *)(iVar8 + 0x20) + 0xc))(*(int *)(iVar8 + 0x20),iVar4,param_2);
      if (0 < iVar9) {
        puVar10 = param_2 + 3;
        do {
          cVar2 = *(char *)puVar10;
          puVar10 = (uint *)((int)puVar10 + 1);
          if ((0xccccccc < (int)uVar6) || ((uVar6 == 0xccccccc && (7 < cVar2 + -0x30)))) {
            if (!bVar1) {
              _CPPErrorToInfoLog("ERROR___INTEGER_CONST_OVERFLOW");
            }
            bVar1 = true;
          }
          iVar9 = iVar9 + -1;
          uVar6 = uVar6 * 10 + cVar2 + -0x30;
        } while (iVar9 != 0);
      }
      *param_2 = uVar6;
      if (uVar6 == 0) {
        *(undefined2 *)(param_2 + 3) = 0x3000;
      }
      return 0x10f;
    }
LAB_97b89a54:
    iVar8 = ((int (*)())_lFloatConst)(param_2 + 3,iVar9,iVar4,param_2);
    return iVar8;
  case 0x31:
  case 0x32:
  case 0x33:
  case 0x34:
  case 0x35:
  case 0x36:
  case 0x37:
  case 0x38:
  case 0x39:
    goto switchD_97b88fcc_caseD_31;
  case 0x3a:
    iVar3 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
    if (iVar3 != 0x3e) {
      (**(code **)(*(int *)(iVar8 + 0x20) + 0xc))(*(int *)(iVar8 + 0x20),iVar3,param_2);
      return 0x3a;
    }
    return 0x11e;
  case 0x3c:
    iVar3 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
    if (iVar3 == 0x3c) {
      iVar3 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
      if (iVar3 != 0x3d) {
        (**(code **)(*(int *)(iVar8 + 0x20) + 0xc))(*(int *)(iVar8 + 0x20),iVar3,param_2);
        return 0x111;
      }
      return 0x119;
    }
    if (iVar3 == 0x3d) {
      return 0x110;
    }
    if (iVar3 == 0x25) {
      return 0x11f;
    }
    if (iVar3 != 0x3a) {
      (**(code **)(*(int *)(iVar8 + 0x20) + 0xc))(*(int *)(iVar8 + 0x20),iVar3,param_2);
      return 0x3c;
    }
    return 0x11d;
  case 0x3d:
    iVar3 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
    if (iVar3 != 0x3d) {
      (**(code **)(*(int *)(iVar8 + 0x20) + 0xc))(*(int *)(iVar8 + 0x20),iVar3,param_2);
      return 0x3d;
    }
    return 0x108;
  case 0x3e:
    iVar3 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
    if (iVar3 != 0x3e) {
      if (iVar3 != 0x3d) {
        (**(code **)(*(int *)(iVar8 + 0x20) + 0xc))(*(int *)(iVar8 + 0x20),iVar3,param_2);
        return 0x3e;
      }
      return 0x10c;
    }
    iVar3 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
    if (iVar3 != 0x3d) {
      (**(code **)(*(int *)(iVar8 + 0x20) + 0xc))(*(int *)(iVar8 + 0x20),iVar3,param_2);
      return 0x10d;
    }
    return 0x118;
  case 0x41:
  case 0x42:
  case 0x43:
  case 0x44:
  case 0x45:
  case 0x46:
  case 0x47:
  case 0x48:
  case 0x49:
  case 0x4a:
  case 0x4b:
  case 0x4c:
  case 0x4d:
  case 0x4e:
  case 0x4f:
  case 0x50:
  case 0x51:
  case 0x52:
  case 0x53:
  case 0x54:
  case 0x55:
  case 0x56:
  case 0x57:
  case 0x58:
  case 0x59:
  case 0x5a:
  case 0x5f:
  case 0x61:
  case 0x62:
  case 99:
  case 100:
  case 0x65:
  case 0x66:
  case 0x67:
  case 0x68:
  case 0x69:
  case 0x6a:
  case 0x6b:
  case 0x6c:
  case 0x6d:
  case 0x6e:
  case 0x6f:
  case 0x70:
  case 0x71:
  case 0x72:
  case 0x73:
  case 0x74:
  case 0x75:
  case 0x76:
  case 0x77:
  case 0x78:
  case 0x79:
  case 0x7a:
    bVar1 = false;
    do {
      if (!bVar1) {
        local_2d0[iVar9] = (char)iVar3;
        iVar9 = iVar9 + 1;
        bVar1 = 0x7f < iVar9;
      }
      iVar3 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
    } while (((iVar3 - 0x61U < 0x1a) || (iVar3 - 0x41U < 0x1a)) ||
            ((iVar3 - 0x30U < 10 || (iVar3 == 0x5f))));
    if (bVar1) {
      iVar9 = 0x7f;
    }
    local_2d0[iVar9] = 0;
    (**(code **)(*(int *)(iVar8 + 0x20) + 0xc))(*(int *)(iVar8 + 0x20),iVar3,param_2);
    uVar6 = _LookUpAddString(*(undefined4 *)PTR__atable_a7b7c0ac,local_2d0);
    param_2[2] = uVar6;
    return 0x10e;
  case 0x5e:
    iVar3 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
    if (iVar3 == 0x5e) {
      return 0x109;
    }
    if (iVar3 != 0x3d) {
      (**(code **)(*(int *)(iVar8 + 0x20) + 0xc))(*(int *)(iVar8 + 0x20),iVar3,param_2);
      return 0x5e;
    }
    return 0x11c;
  case 0x7c:
    iVar3 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
    if (iVar3 == 0x7c) {
      return 0x114;
    }
    if (iVar3 != 0x3d) {
      (**(code **)(*(int *)(iVar8 + 0x20) + 0xc))(*(int *)(iVar8 + 0x20),iVar3,param_2);
      return 0x7c;
    }
    return 0x11b;
  case -1:
    goto switchD_97b88fcc_caseD_ffffffff;
  }
  if (iVar3 != 0x2a) {
    if (iVar3 != 0x3d) {
      (**(code **)(*(int *)(iVar8 + 0x20) + 0xc))(*(int *)(iVar8 + 0x20),iVar3,param_2);
      return 0x2f;
    }
    return 0x106;
  }
  iVar3 = 0;
  iVar9 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
  do {
    while (iVar9 != 0x2a) {
      if (iVar9 == 10) {
        iVar3 = iVar3 + 1;
      }
      if (iVar9 == -1) {
LAB_97b89b60:
        _CPPErrorToInfoLog("ERROR___EOF_IN_COMMENT");
        return -1;
      }
      iVar9 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
    }
    iVar9 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
    if (iVar9 == -1) goto LAB_97b89b60;
  } while (iVar9 != 0x2f);
  if (iVar3 != 0) {
    return 10;
  }
  goto LAB_97b88f18;
LAB_97b89bf4:
  if (iVar3 == 0x5c) {
    iVar3 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
    bVar1 = iVar3 == 0x22;
    if ((iVar3 == 10) || (iVar3 == -1)) {
LAB_97b89c74:
      local_240[iVar9] = 0;
      if (!bVar1) {
        _CPPErrorToInfoLog("ERROR___CPP_EOL_IN_STRING");
        return 0x10a;
      }
      uVar6 = _LookUpAddString(*(undefined4 *)PTR__atable_a7b7c0ac,local_240);
      param_2[2] = uVar6;
      return 0x116;
    }
  }
  if (iVar9 < 0x200) {
    *puVar7 = (char)iVar3;
    iVar9 = iVar9 + 1;
    puVar7 = puVar7 + 1;
    iVar3 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
  }
  bVar1 = iVar3 == 0x22;
  if (((bVar1) || (iVar3 == 10)) || (iVar3 == -1)) goto LAB_97b89c74;
  goto LAB_97b89bf4;
}

/* _yylex_CPP @ 0x97b89cd0 (452 bytes) */
int _yylex_CPP(param_1, param_2)
  char *param_1;
  size_t param_2;
{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  size_t sVar7;
  undefined1 auStack_b0 [8];
  int local_a8;
  char acStack_a4 [136];
  
  puVar2 = PTR__atable_a7b7c0ac;
  puVar1 = PTR__cpp_a7b7c0a4;
  do {
    do {
      while( true ) {
        while( true ) {
          iVar3 = (**(code **)(*(int *)(*(int *)puVar1 + 0x20) + 4))
                            (*(int *)(*(int *)puVar1 + 0x20),auStack_b0);
          iVar4 = ((int (*)())_check_EOF)();
          if (iVar4 != 0) {
            return 0;
          }
          if (iVar3 != 0x23) break;
          if ((*(int *)(*(int *)puVar1 + 0x24) != 10) && (*(int *)(*(int *)puVar1 + 0x24) != 0)) {
            _CPPErrorToInfoLog(
                              "preprocessor command must not be preceded by any other statement in that line"
                              );
            return 0;
          }
          ((int (*)())_readCPPline)(auStack_b0);
          iVar3 = ((int (*)())_check_EOF)();
          if (iVar3 != 0) {
            return 0;
          }
        }
        *(int *)(*(int *)puVar1 + 0x24) = iVar3;
        if ((iVar3 != 0x10e) || (iVar4 = ((int (*)())_MacroExpand)(local_a8,auStack_b0), iVar4 == 0)) break;
        *(undefined4 *)(*(int *)puVar1 + 0x28) = 1;
      }
    } while (iVar3 == 10);
    if (iVar3 != 0x10e) {
      if ((iVar3 != 0x10b) && (iVar3 != 0x10f)) {
        *(undefined4 *)(*(int *)puVar1 + 0x28) = 1;
        uVar5 = *(undefined4 *)puVar2;
        goto LAB_97b89e08;
      }
      pcVar6 = acStack_a4;
      *(undefined4 *)(*(int *)puVar1 + 0x28) = 1;
    }
    else {
      *(undefined4 *)(*(int *)puVar1 + 0x28) = 1;
      uVar5 = *(undefined4 *)puVar2;
      iVar3 = local_a8;
LAB_97b89e08:
      pcVar6 = (char *)_GetStringOfAtom(uVar5,iVar3);
    }
    if (pcVar6 != (char *)0x0) {
      sVar7 = _strlen(pcVar6);
      if ((int)sVar7 < (int)param_2) {
        param_2 = 0;
        if (*pcVar6 != '\0') {
          _strcpy(param_1,pcVar6);
          *(uint *)(*(int *)puVar1 + 0x154) = *(uint *)(*(int *)puVar1 + 0x154) | 0x80000000;
          param_2 = _strlen(pcVar6);
        }
      }
      else {
        *(uint *)(*(int *)puVar1 + 0x154) = *(uint *)(*(int *)puVar1 + 0x154) | 0x80000000;
      }
      return param_2;
    }
  } while( true );
}

/* _check_EOF @ 0x97b89e94 (108 bytes) */
int _check_EOF(param_1)
  int param_1;
{
  undefined *puVar1;
  undefined4 uVar2;
  
  puVar1 = PTR__cpp_a7b7c0a4;
  uVar2 = 0;
  if (param_1 == -1) {
    if (0 < *(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x34)) {
      _CPPErrorToInfoLog("#endif missing!! Compilation stopped");
      *(undefined4 *)(*(int *)puVar1 + 0x140) = 1;
    }
    uVar2 = 1;
  }
  return uVar2;
}

/* _NewScopeInPool @ 0x97b89f4c (152 bytes) */
int _NewScopeInPool(param_1)
  int param_1;
{
  bool bVar1;
  int *piVar2;
  
  piVar2 = (int *)((int (*)())_mem_Alloc)(param_1,0x20);
  piVar2[4] = param_1;
  piVar2[2] = 0;
  piVar2[3] = 0;
  piVar2[5] = 0;
  piVar2[6] = 0;
  piVar2[7] = 0;
  bVar1 = _ScopeList != (int *)0x0;
  *piVar2 = (int)_ScopeList;
  if (bVar1) {
    *(int **)((int)_ScopeList + 4) = piVar2;
  }
  piVar2[1] = 0;
  _ScopeList = piVar2;
  ((int (*)())_mem_AddCleanup)(param_1,DAT_a7b7b048,piVar2);
  return piVar2;
}

/* _PushScope @ 0x97b89fe4 (148 bytes) */
int _PushScope(param_1)
  int *param_1;
{
  int *piVar1;
  int iVar2;
  
  if (_CurrentScope == (int *)0x0) {
    param_1[6] = 0;
  }
  else {
    iVar2 = *(int *)((int)_CurrentScope + 0x18) + 1;
    param_1[6] = iVar2;
    if ((iVar2 == 1) && (_GlobalScope == 0)) {
      param_1[6] = 2;
    }
    iVar2 = param_1[6];
    piVar1 = param_1;
    if (1 < iVar2) {
      while (2 < iVar2) {
        iVar2 = ((int *)*piVar1)[6];
        piVar1 = (int *)*piVar1;
      }
      param_1[3] = (int)piVar1;
    }
  }
  param_1[2] = (int)_CurrentScope;
  _CurrentScope = param_1;
  return;
}

/* _PopScope @ 0x97b8a078 (48 bytes) */
int _PopScope()
{
  if (_CurrentScope == 0) {
    return;
  }
  _CurrentScope = *(undefined4 *)(_CurrentScope + 8);
  return;
}

/* _NewSymbol @ 0x97b8a0a8 (116 bytes) */
int _NewSymbol(param_1, param_2, param_3, param_4)
  undefined4 *param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar2 = (undefined4 *)((int (*)())_mem_Alloc)(*(undefined4 *)(param_2 + 0x10),0x28);
  puVar2[2] = 0;
  puVar2[3] = param_3;
  iVar3 = 0x10;
  *puVar2 = 0;
  puVar2[1] = 0;
  uVar1 = *param_1;
  puVar2[5] = param_4;
  puVar2[4] = uVar1;
  puVar2 = puVar2 + 6;
  do {
    *(undefined1 *)puVar2 = 0;
    puVar2 = (undefined4 *)((int)puVar2 + 1);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}

/* _lAddToTree @ 0x97b8a11c (188 bytes) */
int _lAddToTree(param_1, param_2)
  int *param_1;
  int param_2;
{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  puVar1 = PTR__atable_a7b7c0ac;
  piVar5 = (int *)*param_1;
  if (piVar5 == (int *)0x0) {
    *param_1 = param_2;
  }
  else {
    iVar3 = _GetReversedAtom(*(undefined4 *)PTR__atable_a7b7c0ac,*(undefined4 *)(param_2 + 0xc));
    do {
      iVar4 = _GetReversedAtom(*(undefined4 *)puVar1,piVar5[3]);
      if (iVar4 == iVar3) {
        _CPPErrorToInfoLog("GetAtomString(atable, fSymb->name)");
        return;
      }
      if (iVar3 < iVar4) {
        piVar2 = (int *)*piVar5;
        if (piVar2 == (int *)0x0) {
          *piVar5 = param_2;
          return;
        }
      }
      else {
        piVar2 = (int *)piVar5[1];
        if (piVar2 == (int *)0x0) {
          piVar5[1] = param_2;
          return;
        }
      }
      piVar5 = piVar2;
    } while (piVar2 != (int *)0x0);
  }
  return;
}

/* _AddSymbol @ 0x97b8a1d8 (88 bytes) */
int _AddSymbol(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    param_2 = _CurrentScope;
  }
  uVar1 = ((int (*)())_NewSymbol)(param_1,param_2);
  ((int (*)())_lAddToTree)(param_2 + 0x14,uVar1);
  return uVar1;
}

/* _LookUpLocalSymbol @ 0x97b8a230 (148 bytes) */
int _LookUpLocalSymbol(param_1)
  int param_1;
{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  puVar1 = PTR__atable_a7b7c0ac;
  iVar2 = _GetReversedAtom(*(undefined4 *)PTR__atable_a7b7c0ac);
  if (param_1 == 0) {
    param_1 = _CurrentScope;
  }
  piVar4 = *(int **)(param_1 + 0x14);
  while( true ) {
    if (piVar4 == (int *)0x0) {
      return 0;
    }
    iVar3 = _GetReversedAtom(*(undefined4 *)puVar1,piVar4[3]);
    if (iVar3 == iVar2) break;
    if (iVar2 < iVar3) {
      piVar4 = (int *)*piVar4;
    }
    else {
      piVar4 = (int *)piVar4[1];
    }
  }
  return (int)piVar4;
}

/* _LookUpSymbol @ 0x97b8a2c4 (108 bytes) */
int _LookUpSymbol(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  
  iVar1 = _CurrentScope;
  if (param_1 != 0) goto LAB_97b8a2f8;
  while( true ) {
    param_1 = iVar1;
    if (param_1 == 0) {
      return 0;
    }
LAB_97b8a2f8:
    iVar1 = ((int (*)())_LookUpLocalSymbol)(param_1,param_2);
    if (iVar1 != 0) break;
    iVar1 = *(int *)(param_1 + 8);
  }
  return iVar1;
}

/* _idstr @ 0x97b8a330 (248 bytes) */
int _idstr(param_1, param_2)
  byte *param_1;
  int param_2;
{
  byte bVar1;
  undefined *puVar2;
  size_t sVar3;
  byte *pbVar4;
  uint uVar5;
  int iVar6;
  byte *pbVar7;
  
  sVar3 = _strlen((char *)param_1);
  if (param_2 == 0) {
    pbVar4 = _malloc(sVar3 + 1);
  }
  else {
    pbVar4 = (byte *)((int (*)())_mem_Alloc)(param_2,sVar3 + 1);
  }
  puVar2 = PTR_DAT_a7b7c0a8;
  bVar1 = *param_1;
  pbVar7 = pbVar4;
  do {
    if (bVar1 == 0) {
      *pbVar7 = 0;
      return pbVar4;
    }
    uVar5 = (uint)(char)bVar1;
    if ((uVar5 & 0xffffff80) == 0) {
      uVar5 = -(*(uint *)(puVar2 + uVar5 * 4 + 0x34) & 0x500) >> 0x1f;
    }
    else {
      iVar6 = ___maskrune(uVar5,0x500);
      uVar5 = (uint)(iVar6 != 0);
    }
    if (uVar5 == 0) {
      if (*param_1 - 0x2e < 2) {
        *pbVar7 = 0x5f;
        goto LAB_97b8a3f8;
      }
    }
    else {
      *pbVar7 = *param_1;
LAB_97b8a3f8:
      pbVar7 = pbVar7 + 1;
    }
    param_1 = param_1 + 1;
    bVar1 = *param_1;
  } while( true );
}

/* _lNewBlock @ 0x97b8a428 (136 bytes) */
int _lNewBlock(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 *puVar1;
  
  if (param_2 == 0) {
    puVar1 = _malloc(0x114);
  }
  else {
    puVar1 = (undefined4 *)((int (*)())_mem_Alloc)(param_2,0x114);
  }
  puVar1[4] = puVar1 + 5;
  puVar1[3] = 0x100;
  *puVar1 = 0;
  puVar1[2] = 0;
  puVar1[1] = 0;
  if (*(int *)(param_1 + 8) == 0) {
    *(undefined4 **)(param_1 + 8) = puVar1;
  }
  else {
    **(undefined4 **)(param_1 + 0xc) = puVar1;
  }
  *(undefined4 **)(param_1 + 0xc) = puVar1;
  return;
}

/* _lAddByte @ 0x97b8a4b0 (92 bytes) */
int _lAddByte(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0xc);
  iVar1 = *(int *)(iVar2 + 8);
  if (*(int *)(iVar2 + 0xc) <= iVar1) {
    iVar2 = ((int (*)())_lNewBlock)(param_1,0);
    iVar1 = *(int *)(iVar2 + 8);
  }
  *(undefined1 *)(*(int *)(iVar2 + 0x10) + iVar1) = param_2;
  *(int *)(iVar2 + 8) = iVar1 + 1;
  return;
}

/* _lReadByte @ 0x97b8a50c (88 bytes) */
int _lReadByte(param_1)
  int param_1;
{
  bool bVar1;
  uint uVar2;
  int *piVar3;
  
  piVar3 = *(int **)(param_1 + 0xc);
  uVar2 = 0xffffffff;
  bVar1 = piVar3 == (int *)0x0;
  if (!bVar1) {
    if (piVar3[2] <= piVar3[1]) {
      piVar3 = (int *)*piVar3;
      bVar1 = piVar3 == (int *)0x0;
      if (!bVar1) {
        piVar3[1] = 0;
      }
      *(int **)(param_1 + 0xc) = piVar3;
    }
    if (!bVar1) {
      uVar2 = (uint)*(byte *)(piVar3[4] + piVar3[1]);
      piVar3[1] = piVar3[1] + 1;
    }
  }
  return uVar2;
}

/* _NewTokenStream @ 0x97b8a564 (124 bytes) */
int _NewTokenStream(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_2 == 0) {
    puVar1 = _malloc(0x10);
  }
  else {
    puVar1 = (undefined4 *)((int (*)())_mem_Alloc)(param_2,0x10);
  }
  *puVar1 = 0;
  uVar2 = ((int (*)())_idstr)(param_1,param_2);
  puVar1[3] = 0;
  puVar1[1] = uVar2;
  puVar1[2] = 0;
  ((int (*)())_lNewBlock)(puVar1,param_2);
  return puVar1;
}

/* _DeleteTokenStream @ 0x97b8a5e0 (116 bytes) */
int _DeleteTokenStream(param_1)
  void *param_1;
{
  undefined4 *puVar1;
  void *pvVar2;
  
  if (param_1 == (void *)0x0) {
    return;
  }
  puVar1 = *(void **)((int)param_1 + 8);
  while (puVar1 != (void *)0x0) {
    pvVar2 = (void *)*puVar1;
    _free(puVar1);
    puVar1 = pvVar2;
  }
  if (*(void **)((int)param_1 + 4) != (void *)0x0) {
    _free(*(void **)((int)param_1 + 4));
  }
  _free(param_1);
  return;
}

/* _RecordToken @ 0x97b8a654 (292 bytes) */
int _RecordToken(param_1, param_2, param_3)
  undefined4 param_1;
  uint param_2;
  int *param_3;
{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  int *piVar4;
  
  if ((int)param_2 < 0x101) {
    uVar2 = param_2 & 0x7f;
  }
  else {
    uVar2 = (param_2 & 0x7f) - 0x80 & 0xff;
  }
  ((int (*)())_lAddByte)(param_1,uVar2);
  if (param_2 == 0x10e) {
LAB_97b8a6cc:
    pcVar3 = (char *)_GetAtomString(*(undefined4 *)PTR__atable_a7b7c0ac,param_3[2]);
    cVar1 = *pcVar3;
    while (cVar1 != '\0') {
      ((int (*)())_lAddByte)(param_1);
      pcVar3 = pcVar3 + 1;
      cVar1 = *pcVar3;
    }
  }
  else {
    if ((int)param_2 < 0x10f) {
      if (param_2 == 0x28) {
        ((int (*)())_lAddByte)(param_1,*param_3 != 0);
        return;
      }
      if (param_2 != 0x10b) {
        return;
      }
    }
    else if (param_2 != 0x10f) {
      if (1 < param_2 - 0x116) {
        return;
      }
      goto LAB_97b8a6cc;
    }
    piVar4 = param_3 + 3;
    cVar1 = *(char *)(param_3 + 3);
    while (cVar1 != '\0') {
      ((int (*)())_lAddByte)(param_1,cVar1);
      piVar4 = (int *)((int)piVar4 + 1);
      cVar1 = *(char *)piVar4;
    }
  }
  ((int (*)())_lAddByte)(param_1,0);
  return;
}

/* _RewindTokenStream @ 0x97b8a778 (28 bytes) */
int _RewindTokenStream(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 == 0) {
    return;
  }
  *(int *)(param_1 + 0xc) = iVar1;
  *(undefined4 *)(iVar1 + 4) = 0;
  return;
}

/* _ReadToken @ 0x97b8a794 (888 bytes) */
int _ReadToken(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  uint uVar1;
  int iVar2;
  char cVar3;
  undefined4 uVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  double dVar8;
  char local_2c0 [144];
  char local_230 [532];
  
  iVar2 = ((int (*)())_lReadByte)();
  if (iVar2 < 0) {
    return -1;
  }
  if (0x7f < iVar2) {
    iVar2 = iVar2 + 0x80;
  }
  if (iVar2 == 0x10e) {
LAB_97b8a810:
    iVar7 = 0;
    cVar3 = ((int (*)())_lReadByte)(param_1);
    iVar5 = (int)cVar3;
    uVar1 = iVar5 - 0x61;
    while (((((uVar1 & 0xff) < 0x1a || (iVar5 - 0x41U < 0x1a)) || (iVar5 - 0x30U < 10)) ||
           (iVar5 == 0x5f))) {
      if (iVar7 < 0x80) {
        local_2c0[iVar7] = (char)iVar5;
        cVar3 = ((int (*)())_lReadByte)(param_1);
        iVar7 = iVar7 + 1;
        iVar5 = (int)cVar3;
        uVar1 = iVar5 - 0x61;
      }
    }
    local_2c0[iVar7] = '\0';
    if (iVar5 == 0) {
      iVar2 = _LookUpAddString(*(undefined4 *)PTR__atable_a7b7c0ac,local_2c0);
      param_2[2] = iVar2;
      return 0x10e;
    }
    uVar4 = 0x140;
LAB_97b8aac8:
    ___eprintf("%s:%u: failed assertion `%s\'\n",
               "/SourceCache/OpenGL/OpenGL-4.7.14/GLProgrammability/glslang/MachineIndependent/preprocessor/tokens.c"
               ,uVar4,"ch == \'\\0\'");
  }
  else {
    if (iVar2 < 0x10f) {
      if (iVar2 == 0x28) {
        iVar7 = ((int (*)())_lReadByte)(param_1);
        goto LAB_97b8aaf0;
      }
      if (iVar2 != 0x10b) {
        return iVar2;
      }
      iVar7 = 0;
      cVar3 = ((int (*)())_lReadByte)(param_1);
      iVar5 = (int)cVar3;
      uVar1 = iVar5 - 0x30;
      while (((((uVar1 & 0xff) < 10 || (iVar5 == 0x65)) ||
              ((iVar5 == 0x45 || ((iVar5 == 0x2e || (iVar5 == 0x2b)))))) || (iVar5 == 0x2d))) {
        if (iVar7 < 0x80) {
          local_2c0[iVar7] = (char)iVar5;
          cVar3 = ((int (*)())_lReadByte)(param_1);
          iVar7 = iVar7 + 1;
          iVar5 = (int)cVar3;
          uVar1 = iVar5 - 0x30;
        }
      }
      local_2c0[iVar7] = '\0';
      if (iVar5 == 0) {
        _strcpy((char *)(param_2 + 3),local_2c0);
        dVar8 = (double)((double (*)())_glp_strtod)(param_2 + 3,0);
        param_2[1] = (int)(float)dVar8;
        return 0x10b;
      }
      uVar4 = 0x158;
      goto LAB_97b8aac8;
    }
    if (iVar2 == 0x116) {
      iVar2 = 0;
      pcVar6 = local_230;
      while (cVar3 = ((int (*)())_lReadByte)(param_1), cVar3 != '\0') {
        if (iVar2 < 0x200) {
          *pcVar6 = cVar3;
          iVar2 = iVar2 + 1;
          pcVar6 = pcVar6 + 1;
        }
      }
      local_230[iVar2] = '\0';
      iVar2 = _LookUpAddString(*(undefined4 *)PTR__atable_a7b7c0ac,local_230);
      param_2[2] = iVar2;
      return 0x116;
    }
    if (0x116 < iVar2) {
      if (iVar2 != 0x117) {
        return iVar2;
      }
      goto LAB_97b8a810;
    }
    if (iVar2 != 0x10f) {
      return iVar2;
    }
    iVar7 = 0;
    cVar3 = ((int (*)())_lReadByte)(param_1);
    iVar5 = (int)cVar3;
    uVar1 = iVar5 - 0x30;
    while ((uVar1 & 0xff) < 10) {
      if (iVar7 < 0x80) {
        local_2c0[iVar7] = (char)iVar5;
        cVar3 = ((int (*)())_lReadByte)(param_1);
        iVar7 = iVar7 + 1;
        iVar5 = (int)cVar3;
        uVar1 = iVar5 - 0x30;
      }
    }
    local_2c0[iVar7] = '\0';
    if (iVar5 != 0) {
      uVar4 = 0x168;
      goto LAB_97b8aac8;
    }
  }
  _strcpy((char *)(param_2 + 3),local_2c0);
  iVar7 = _atoi((char *)(param_2 + 3));
LAB_97b8aaf0:
  *param_2 = iVar7;
  return iVar2;
}

/* _scan_token @ 0x97b8ab0c (248 bytes) */
int _scan_token(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  undefined *puVar1;
  int iVar2;
  code *pcVar3;
  
  iVar2 = ((int (*)())_ReadToken)(param_1[6]);
  puVar1 = PTR__cpp_a7b7c0a4;
  **(undefined2 **)(*(int *)PTR__cpp_a7b7c0a4 + 0x18) =
       *(undefined2 *)(*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20) + 0x12);
  *(undefined2 *)(*(int *)(*(int *)puVar1 + 0x18) + 2) =
       *(undefined2 *)(*(int *)(*(int *)puVar1 + 0x20) + 0x16);
  if (iVar2 == 10) {
    iVar2 = 10;
    param_1[5] = param_1[5] + 1;
  }
  else if (iVar2 < 1) {
    *(undefined4 *)(*(int *)puVar1 + 0x20) = *param_1;
    pcVar3 = (code *)param_1[7];
    _free(param_1);
    if ((pcVar3 != (code *)0x0) && (iVar2 = (*pcVar3)(*(undefined4 *)puVar1), iVar2 == 0)) {
      return -1;
    }
                    
                    
    iVar2 = (**(code **)(*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20) + 4))
                      (*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20),param_2);
    return iVar2;
  }
  return iVar2;
}

