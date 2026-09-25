#include "decls.h"

/* _AddAtomFixed @ 0x97b85cdc (196 bytes) */
int _AddAtomFixed(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = _LookUpAddStringHash(param_1,param_2);
  iVar3 = *(int *)(param_1 + 0x34);
  if ((iVar3 <= *(int *)(param_1 + 0x30)) || (iVar3 <= param_3)) {
    iVar3 = iVar3 << 1;
    if (iVar3 <= param_3) {
      iVar3 = param_3 + 1;
    }
    _GrowAtomTable(param_1,iVar3);
  }
  *(undefined4 *)(param_3 * 4 + *(int *)(param_1 + 0x28)) =
       *(undefined4 *)(iVar1 * 8 + *(int *)(param_1 + 0xc));
  *(int *)(iVar1 * 8 + *(int *)(param_1 + 0xc) + 4) = param_3;
  iVar3 = *(int *)(param_1 + 0x30);
  while (iVar3 <= param_3) {
    uVar2 = _lReverse(iVar3);
    *(undefined4 *)(*(int *)(param_1 + 0x30) * 4 + *(int *)(param_1 + 0x2c)) = uVar2;
    iVar3 = *(int *)(param_1 + 0x30) + 1;
    *(int *)(param_1 + 0x30) = iVar3;
  }
  return param_3;
}

/* _InitAtomTable @ 0x97b85da0 (368 bytes) */
int _InitAtomTable(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 *puVar1;
  char cVar2;
  char cVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  char *pcVar7;
  int iVar8;
  char local_20_str[2];
#define local_20 local_20_str[0]
#define local_1f local_20_str[1]
  
  if (param_2 < 1) {
    param_2 = 0x7ff;
  }
  iVar5 = _InitStringTable(param_1);
  uVar6 = 0;
  if (iVar5 != 0) {
    iVar5 = _InitHashTable(param_1 + 0xc,param_2);
    uVar6 = 0;
    if (iVar5 != 0) {
      *(undefined4 *)(param_1 + 0x34) = 0;
      *(undefined4 *)(param_1 + 0x30) = 0;
      *(undefined4 *)(param_1 + 0x28) = 0;
      _GrowAtomTable(param_1,0x400);
      uVar6 = 0;
      if (*(int *)(param_1 + 0x28) != 0) {
        ((int (*)())_AddAtomFixed)(param_1,"<undefined>",0);
        iVar8 = 0x121;
        iVar5 = 0;
        do {
          (*(undefined4 **)(param_1 + 0x28))[iVar5] = **(undefined4 **)(param_1 + 0x28);
          iVar8 = iVar8 + -1;
          iVar5 = iVar5 + 1;
        } while (iVar8 != 0);
        pcVar7 = "~!%^&*()-+=|,.<>/?;:[]{}#";
        local_1f = 0;
        cVar3 = s___________________________97c23e68[0];
        cVar2 = local_20;
        while (local_20 = cVar3, local_20 != '\0') {
          ((int (*)())_AddAtomFixed)(param_1,&local_20,(int)local_20);
          pcVar7 = pcVar7 + 1;
          cVar2 = local_20;
          cVar3 = *pcVar7;
        }
        puVar4 = &_tokens;
        local_20 = cVar2;
        do {
          puVar1 = puVar4 + 1;
          uVar6 = *puVar4;
          puVar4 = puVar4 + 2;
          ((int (*)())_AddAtomFixed)(param_1,*puVar1,uVar6);
        } while (puVar4 < &UNK_a7b7ce41);
        if (*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 8) != 0) {
          ((int (*)())_AddAtomFixed)(param_1,"error",0x10a);
        }
        _AddAtom(param_1,"<*** end fixed atoms ***>");
        uVar6 = 1;
      }
    }
  }
  return uVar6;
#undef local_20
#undef local_1f
}

/* _PrintAtomTable @ 0x97b85f10 (208 bytes) */
int _PrintAtomTable(param_1)
  int *param_1;
{
  int *piVar1;
  int iVar2;
  char acStack_e0 [212];
  
  iVar2 = 0;
  if (0 < param_1[0xc]) {
    do {
      _sprintf(acStack_e0,"%d: \"%s\"",iVar2,*param_1 + *(int *)(iVar2 * 4 + param_1[10]));
      _CPPDebugLogMsg(acStack_e0);
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_1[0xc]);
  }
  piVar1 = param_1 + 6;
  _sprintf(acStack_e0,"Hash table: size=%d, entries=%d, collisions=",param_1[4],param_1[5]);
  _CPPDebugLogMsg(acStack_e0);
  iVar2 = 2;
  do {
    _sprintf(acStack_e0," %d",*piVar1);
    _CPPDebugLogMsg(acStack_e0);
    iVar2 = iVar2 + -1;
    piVar1 = piVar1 + 1;
  } while (-1 < iVar2);
  return;
}

/* _GetStringOfAtom @ 0x97b85fe0 (24 bytes) */
int _GetStringOfAtom(param_1, param_2)
  int *param_1;
  int param_2;
{
  return *param_1 + *(int *)(param_2 * 4 + param_1[10]);
}

/* _FreeAtomTable @ 0x97b85ff8 (104 bytes) */
int _FreeAtomTable(param_1)
  int param_1;
{
  _FreeStringTable(param_1);
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
  undefined4 uVar2;
  size_t sVar3;
  unsigned char _Var4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
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
  uVar2 = ((int (*)())_mem_CreatePool)(0,0);
  _macros = _NewScopeInPool(uVar2);
  local_60[0] = s_PROFILE__97c23f9c[0];
  local_60[1] = s_PROFILE__97c23f9c[1];
  local_60[2] = s_PROFILE__97c23f9c[2];
  local_60[3] = s_PROFILE__97c23f9c[3];
  local_5c[0] = s_PROFILE__97c23f9c[4];
  local_5c[1] = s_PROFILE__97c23f9c[5];
  local_5c[2] = s_PROFILE__97c23f9c[6];
  local_5c[3] = s_PROFILE__97c23f9c[7];
  local_58 = s_PROFILE__97c23f9c[8];
  sVar3 = _strlen(local_60);
  puVar1 = PTR_DAT_a7b7c0a8;
  pcVar7 = local_60 + sVar3;
  pcVar8 = *(char **)(*(int *)PTR__cpp_a7b7c0a4 + 4);
  while( true ) {
    uVar5 = (uint)*pcVar8;
    if ((uVar5 & 0xffffff80) == 0) {
      uVar5 = -(*(uint *)(puVar1 + uVar5 * 4 + 0x34) & 0x500) >> 0x1f;
    }
    else {
      iVar6 = ___maskrune(uVar5,0x500);
      uVar5 = (uint)(iVar6 != 0);
    }
    if (((uVar5 == 0) && (*pcVar8 != '_')) || (acStack_21 <= pcVar7)) break;
    _Var4 = ___toupper((int)*pcVar8);
    pcVar8 = pcVar8 + 1;
    *pcVar7 = (char)_Var4;
    pcVar7 = pcVar7 + 1;
  }
  *pcVar7 = '\0';
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
    local_48 = _NewTokenStream(uVar3,*(undefined4 *)(_macros + 0x10));
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
          _RecordToken(local_48,0x5c,param_1);
        }
      }
      _RecordToken(local_48,iVar2,param_1);
      iVar2 = (**(code **)(*(int *)(*(int *)puVar1 + 0x20) + 4))
                        (*(int *)(*(int *)puVar1 + 0x20),param_1);
    }
    iVar8 = _LookUpSymbol(_macros,iVar5);
    if (iVar8 == 0) {
      local_40 = 0;
      local_3e = local_40;
      iVar8 = _AddSymbol(&local_40,_macros,iVar5,0);
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
        _RewindTokenStream(*(undefined4 *)(iVar8 + 0x20));
        _RewindTokenStream(local_48);
        do {
          iVar2 = _ReadToken(*(undefined4 *)(iVar8 + 0x20),param_1);
          iVar7 = *param_1;
          iVar4 = _ReadToken(local_48,param_1);
          if ((iVar4 != iVar2) || (*param_1 != iVar7)) goto LAB_97b86728;
        } while (0 < iVar4);
      }
      else {
LAB_97b86728:
        _StoreStr("Macro Redefined");
        uVar3 = ((int (*)())_GetStringOfAtom)(*(undefined4 *)PTR__atable_a7b7c0ac,iVar5);
        _StoreStr(uVar3);
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
      iVar2 = _LookUpSymbol(_macros,*(undefined4 *)(param_1 + 8));
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

/* _op_logor @ 0x97b86b94 (28 bytes) */
int _op_logor(param_1, param_2)
  int param_1;
  int param_2;
{
  if ((param_1 == 0) && (param_2 == 0)) {
    return 0;
  }
  return 1;
}

/* _op_logand @ 0x97b86bb0 (28 bytes) */
int _op_logand(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_1 == 0) {
    return 0;
  }
  if (param_2 == 0) {
    return 0;
  }
  return 1;
}

/* _op_or @ 0x97b86bcc (8 bytes) */
int _op_or(param_1, param_2)
  uint param_1;
  uint param_2;
{
  return param_1 | param_2;
}

/* _op_xor @ 0x97b86bd4 (8 bytes) */
int _op_xor(param_1, param_2)
  uint param_1;
  uint param_2;
{
  return param_1 ^ param_2;
}

/* _op_and @ 0x97b86bdc (8 bytes) */
int _op_and(param_1, param_2)
  uint param_1;
  uint param_2;
{
  return param_1 & param_2;
}

/* _op_eq @ 0x97b86be4 (16 bytes) */
int _op_eq(param_1, param_2)
  int param_1;
  int param_2;
{
  return param_1 == param_2;
}

/* _op_ne @ 0x97b86bf4 (16 bytes) */
int _op_ne(param_1, param_2)
  int param_1;
  int param_2;
{
  return param_1 != param_2;
}

/* _op_ge @ 0x97b86c04 (20 bytes) */
int _op_ge(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_2 <= param_1) {
    return 1;
  }
  return 0;
}

/* _op_le @ 0x97b86c18 (20 bytes) */
int _op_le(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_1 <= param_2) {
    return 1;
  }
  return 0;
}

/* _op_gt @ 0x97b86c2c (20 bytes) */
int _op_gt(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_2 < param_1) {
    return 1;
  }
  return 0;
}

/* _op_lt @ 0x97b86c40 (20 bytes) */
int _op_lt(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_1 < param_2) {
    return 1;
  }
  return 0;
}

/* _op_shl @ 0x97b86c54 (8 bytes) */
int _op_shl(param_1, param_2)
  int param_1;
  uint param_2;
{
  return param_1 << (param_2 & 0x3f);
}

/* _op_div @ 0x97b86c7c (8 bytes) */
int _op_div(param_1, param_2)
  int param_1;
  int param_2;
{
  return param_1 / param_2;
}

/* _op_mod @ 0x97b86c84 (16 bytes) */
int _op_mod(param_1, param_2)
  int param_1;
  int param_2;
{
  return param_1 - (param_1 / param_2) * param_2;
}

/* _op_pos @ 0x97b86c94 (4 bytes) */
int _op_pos()
{
  return;
}

/* _op_cmpl @ 0x97b86ca0 (8 bytes) */
int _op_cmpl(param_1)
  uint param_1;
{
  return ~param_1;
}

/* _op_not @ 0x97b86ca8 (12 bytes) */
int _op_not(param_1)
  int param_1;
{
  return param_1 == 0;
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
      iVar4 = _LookUpSymbol(_macros,param_5[2]);
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
      iVar2 = _LookUpSymbol(_macros,uVar6);
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
      _SetLineNumber(iVar2);
      iVar2 = *(int *)(*(int *)puVar1 + 0x20);
      iVar2 = (**(code **)(iVar2 + 4))(iVar2,param_1);
      if (iVar2 == 0x10f) {
        iVar2 = _atoi((char *)(param_1 + 3));
        *param_1 = iVar2;
        _SetStringNumber(iVar2);
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
  undefined4 uVar4;
  
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
      iVar3 = ((int (*)())_GetStringOfAtom)(*(undefined4 *)puVar2,iVar3);
    }
    _StoreStr(iVar3);
    iVar3 = (**(code **)(*(int *)(*(int *)puVar1 + 0x20) + 4))
                      (*(int *)(*(int *)puVar1 + 0x20),param_1);
  }
  _DecLineNumber();
  uVar4 = _GetStrfromTStr();
  _CPPShInfoLogMsg(uVar4);
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
                  uVar4 = ((int (*)())_GetStringOfAtom)(*(undefined4 *)PTR__atable_a7b7c0ac,
                                           *(undefined4 *)(param_1 + 8));
                  _StoreStr(uVar4);
                  uVar4 = _GetStrfromTStr();
                  _CPPShInfoLogMsg(uVar4);
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
  _DeleteTokenStream(*(undefined4 *)(param_1 + 8));
  return;
}

/* _eof_scan_97b87cd4 @ 0x97b87cd4 (8 bytes) */
int _eof_scan_97b87cd4()
{
  return 0xffffffff;
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
  return puVar3;
}

/* _PopEofSrc @ 0x97b87d58 (64 bytes) */
int _PopEofSrc()
{
  undefined4 *puVar1;
  undefined4 extraout_r3;
  
  puVar1 = *(undefined4 **)(*(int *)PTR__cpp_a7b7c0a4 + 0x20);
  if (puVar1[1] != DAT_a7b7b010) {
    return puVar1;
  }
  *(undefined4 *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20) = *puVar1;
  _free(puVar1);
  return (undefined4 *)extraout_r3;
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
  
  _RewindTokenStream(param_1);
  do {
    iVar2 = _ReadToken(param_1,param_2);
    if ((iVar2 == 0x10e) &&
       (iVar3 = _LookUpSymbol(_macros,*(undefined4 *)(param_2 + 8)), iVar3 != 0)) break;
  } while (0 < iVar2);
  if (0 < iVar2) {
    uVar4 = _NewTokenStream("macro arg",0);
    ((int (*)())_PushEofSrc)();
    _ReadFromTokenStream(param_1,0,0);
    puVar1 = PTR__cpp_a7b7c0a4;
    while (iVar2 = (**(code **)(*(int *)(*(int *)puVar1 + 0x20) + 4))
                             (*(int *)(*(int *)puVar1 + 0x20),param_2), 0 < iVar2) {
      if ((iVar2 != 0x10e) ||
         (iVar3 = ((int (*)())_MacroExpand)(*(undefined4 *)(param_2 + 8),param_2), iVar3 == 0)) {
        _RecordToken(uVar4,iVar2,param_2);
      }
    }
    ((int (*)())_PopEofSrc)();
    _DeleteTokenStream(param_1);
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
  
  iVar5 = _ReadToken(*(undefined4 *)(param_1[6] + 8),param_2);
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
        _DeleteTokenStream(*(undefined4 *)(iVar5 * 4 + (int)pvVar6));
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
  
  iVar6 = _LookUpSymbol(_macros,param_1);
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
              uVar11 = _NewTokenStream("macro arg",0);
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
            _RecordToken(*(undefined4 *)(iVar13 * 4 + puVar7[7]),iVar9,param_2);
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
    uVar11 = ((int (*)())_GetStringOfAtom)(*(undefined4 *)PTR__atable_a7b7c0ac,param_1);
    _StoreStr(uVar11);
    uVar11 = _GetStrfromTStr();
    _CPPShInfoLogMsg(uVar11);
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
      uVar11 = ((int (*)())_GetStringOfAtom)(*(undefined4 *)PTR__atable_a7b7c0ac,param_1);
      _StoreStr(uVar11);
      uVar11 = _GetStrfromTStr();
      _CPPShInfoLogMsg(uVar11);
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
  _RewindTokenStream(*(undefined4 *)(iVar6 + 0x20));
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
  uint uVar3;
  
  ((int (*)())_FreeCPPStruct)();
  ((int (*)())_InitCPPStruct)();
  *(undefined4 *)(_cpp + 0xc) = 1;
  puVar1 = PTR__atable_a7b7c0ac;
  *(char **)(_cpp + 4) = "generic";
  iVar2 = ((int (*)())_InitAtomTable)(*(undefined4 *)puVar1,0);
  uVar3 = 1;
  if (iVar2 != 0) {
    iVar2 = ((int (*)())_InitScanner)(_cpp);
    uVar3 = (uint)(iVar2 == 0);
  }
  return uVar3;
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

/* _eof_scan_97b88924 @ 0x97b88924 (8 bytes) */
int _eof_scan_97b88924()
{
  return 0xffffffff;
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

/* FUN_97b88a90 @ 0x97b88a90 (100 bytes) */
int FUN_97b88a90(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined1 *unaff_r2 = *(undefined1 **)(param_1 + 0x18);   /* set by the entry _str_ungetch: lwz r2,0x18(r3) */
  
  if ((char)unaff_r2[-1] == param_2) {
    *(undefined1 **)(param_1 + 0x18) = unaff_r2 + -1;
  }
  else {
    *unaff_r2 = 0;
    *(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x144) = *(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x144) + -1;
  }
  if (param_2 != 10) {
    return;
  }
  *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + -1;
  _DecLineNumber();
  return;
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

