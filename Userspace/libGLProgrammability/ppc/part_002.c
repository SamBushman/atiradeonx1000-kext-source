#include "decls.h"

/* _AddAtomFixed @ 0x97b85cdc (196 bytes) */
int _AddAtomFixed(atable, atomName, atom)
  int atable;
  undefined4 atomName;
  int atom;
{
  int nextFreeAtom;
  int lookUpAddStringHashResult;
  undefined4 lReverseResult;
  int tableSize;
  
  lookUpAddStringHashResult = _LookUpAddStringHash(atable,atomName);
  tableSize = *(int *)(atable + 0x34);
  if ((tableSize <= *(int *)(atable + 0x30)) || (tableSize <= atom)) {
    tableSize = tableSize << 1;
    if (tableSize <= atom) {
      tableSize = atom + 1;
    }
    _GrowAtomTable(atable,tableSize);
  }
  *(undefined4 *)(atom * 4 + *(int *)(atable + 0x28)) =
       *(undefined4 *)(lookUpAddStringHashResult * 8 + *(int *)(atable + 0xc));
  *(int *)(lookUpAddStringHashResult * 8 + *(int *)(atable + 0xc) + 4) = atom;
  nextFreeAtom = *(int *)(atable + 0x30);
  while (nextFreeAtom <= atom) {
    lReverseResult = _lReverse(nextFreeAtom);
    *(undefined4 *)(*(int *)(atable + 0x30) * 4 + *(int *)(atable + 0x2c)) = lReverseResult;
    nextFreeAtom = *(int *)(atable + 0x30) + 1;
    *(int *)(atable + 0x30) = nextFreeAtom;
  }
  return atom;
}

/* _InitAtomTable @ 0x97b85da0 (368 bytes) */
int _InitAtomTable(atable, hashSize)
  int atable;
  int hashSize;
{
  undefined4 tokenAtom;
  int fillIndex;
  undefined4 *tokenNamePtr;
  char savedChar;
  char currentPunct;
  undefined4 *tokenCursor;
  int initResult;
  undefined4 success;
  char *punctCursor;
  int fillRemaining;
  char charStr[2];
#define charStr0 charStr[0]
#define charStr1 charStr[1]
  
  if (hashSize < 1) {
    hashSize = 0x7ff;
  }
  initResult = _InitStringTable(atable);
  success = 0;
  if (initResult != 0) {
    initResult = _InitHashTable(atable + 0xc,hashSize);
    success = 0;
    if (initResult != 0) {
      *(undefined4 *)(atable + 0x34) = 0;
      *(undefined4 *)(atable + 0x30) = 0;
      *(undefined4 *)(atable + 0x28) = 0;
      _GrowAtomTable(atable,0x400);
      success = 0;
      if (*(int *)(atable + 0x28) != 0) {
        ((int (*)())_AddAtomFixed)(atable,"<undefined>",0);
        fillRemaining = 0x121;
        fillIndex = 0;
        do {
          (*(undefined4 **)(atable + 0x28))[fillIndex] = **(undefined4 **)(atable + 0x28);
          fillRemaining = fillRemaining + -1;
          fillIndex = fillIndex + 1;
        } while (fillRemaining != 0);
        punctCursor = "~!%^&*()-+=|,.<>/?;:[]{}#";
        charStr1 = 0;
        currentPunct = s___________________________97c23e68[0];
        savedChar = charStr0;
        while (charStr0 = currentPunct, charStr0 != '\0') {
          ((int (*)())_AddAtomFixed)(atable,&charStr0,(int)charStr0);
          punctCursor = punctCursor + 1;
          savedChar = charStr0;
          currentPunct = *punctCursor;
        }
        tokenCursor = &_tokens;
        charStr0 = savedChar;
        do {
          tokenNamePtr = tokenCursor + 1;
          tokenAtom = *tokenCursor;
          tokenCursor = tokenCursor + 2;
          ((int (*)())_AddAtomFixed)(atable,*tokenNamePtr,tokenAtom);
        } while (tokenCursor < &UNK_a7b7ce41);
        if (*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 8) != 0) {
          ((int (*)())_AddAtomFixed)(atable,"error",0x10a);
        }
        _AddAtom(atable,"<*** end fixed atoms ***>");
        success = 1;
      }
    }
  }
  return success;
#undef charStr0
#undef charStr1
}

/* _PrintAtomTable @ 0x97b85f10 (208 bytes) */
int _PrintAtomTable(atable)
  int *atable;
{
  int loopIndex;
  int *collisionCount;
  int iVar2;
  char msgBuf [212];
  
  loopIndex = 0;
  if (0 < atable[0xc]) {
    do {
      _sprintf(msgBuf,"%d: \"%s\"",loopIndex,*atable + *(int *)(loopIndex * 4 + atable[10]));
      _CPPDebugLogMsg(msgBuf);
      loopIndex = loopIndex + 1;
    } while (loopIndex < atable[0xc]);
  }
  collisionCount = atable + 6;
  _sprintf(msgBuf,"Hash table: size=%d, entries=%d, collisions=",atable[4],atable[5]);
  _CPPDebugLogMsg(msgBuf);
  iVar2 = 2;
  do {
    _sprintf(msgBuf," %d",*collisionCount);
    _CPPDebugLogMsg(msgBuf);
    iVar2 = iVar2 + -1;
    collisionCount = collisionCount + 1;
  } while (-1 < iVar2);
  return;
}

/* _GetStringOfAtom @ 0x97b85fe0 (24 bytes) */
int _GetStringOfAtom(atable, atom)
  int *atable;
  int atom;
{
  return *atable + *(int *)(atom * 4 + atable[10]);
}

/* _FreeAtomTable @ 0x97b85ff8 (104 bytes) */
int _FreeAtomTable(atable)
  int atable;
{
  _FreeStringTable(atable);
  _FreeHashTable(atable + 0xc);
  if (*(int *)(atable + 0x28) != 0) {
    _free(*(int *)(atable + 0x28));
  }
  if (*(int *)(atable + 0x2c) != 0) {
    _free(*(int *)(atable + 0x2c));
  }
  *(undefined4 *)(atable + 0x34) = 0;
  *(undefined4 *)(atable + 0x28) = 0;
  *(undefined4 *)(atable + 0x2c) = 0;
  *(undefined4 *)(atable + 0x30) = 0;
  return;
}

/* _InitCPP @ 0x97b86060 (812 bytes) */
int _InitCPP()
{
  uint isAlnum;
  undefined *ctypeTable;
  int length;
  undefined *atableRef;
  undefined4 mem_CreatePoolResult;
  int maskruneResult;
  unsigned char upperChar;
  uint curChar;
  char *profileWrite;
  char *profileRead;
  char profileName [63];
  char profileLimit [9];
  
  atableRef = PTR__atable_a7b7c0ac;
  _bindAtom = _LookUpAddString(*(undefined4 *)PTR__atable_a7b7c0ac,"bind");
  _constAtom = _LookUpAddString(*(undefined4 *)atableRef,"const");
  _defaultAtom = _LookUpAddString(*(undefined4 *)atableRef,"default");
  _defineAtom = _LookUpAddString(*(undefined4 *)atableRef,"define");
  _definedAtom = _LookUpAddString(*(undefined4 *)atableRef,"defined");
  _elifAtom = _LookUpAddString(*(undefined4 *)atableRef,"elif");
  _elseAtom = _LookUpAddString(*(undefined4 *)atableRef,"else");
  _endifAtom = _LookUpAddString(*(undefined4 *)atableRef,"endif");
  _ifAtom = _LookUpAddString(*(undefined4 *)atableRef,"if");
  _ifdefAtom = _LookUpAddString(*(undefined4 *)atableRef,"ifdef");
  _ifndefAtom = _LookUpAddString(*(undefined4 *)atableRef,"ifndef");
  _includeAtom = _LookUpAddString(*(undefined4 *)atableRef,"include");
  _lineAtom = _LookUpAddString(*(undefined4 *)atableRef,"line");
  _pragmaAtom = _LookUpAddString(*(undefined4 *)atableRef,"pragma");
  _texunitAtom = _LookUpAddString(*(undefined4 *)atableRef,"texunit");
  _undefAtom = _LookUpAddString(*(undefined4 *)atableRef,"undef");
  _errorAtom = _LookUpAddString(*(undefined4 *)atableRef,"error");
  ___LINE__Atom = _LookUpAddString(*(undefined4 *)atableRef,"__LINE__");
  ___FILE__Atom = _LookUpAddString(*(undefined4 *)atableRef,"__FILE__");
  ___VERSION__Atom = _LookUpAddString(*(undefined4 *)atableRef,"__VERSION__");
  _versionAtom = _LookUpAddString(*(undefined4 *)atableRef,"version");
  _extensionAtom = _LookUpAddString(*(undefined4 *)atableRef,"extension");
  mem_CreatePoolResult = ((int (*)())_mem_CreatePool)(0,0);
  _macros = _NewScopeInPool(mem_CreatePoolResult);
  builtin_strncpy(profileName,"PROFILE_",9);
  length = _strlen(profileName);
  ctypeTable = PTR_DAT_a7b7c0a8;
  profileWrite = profileName + length;
  profileRead = *(char **)(*(int *)PTR__cpp_a7b7c0a4 + 4);
  while( true ) {
    curChar = (uint)*profileRead;
    if ((curChar & 0xffffff80) == 0) {
      isAlnum = -(uint)(*(uint *)(ctypeTable + curChar * 4 + 0x34) & 0x500) >> 0x1f;
    }
    else {
      maskruneResult = ___maskrune(curChar,0x500);
      isAlnum = (uint)(maskruneResult != 0);
    }
    if (((isAlnum == 0) && (*profileRead != '_')) || (profileLimit <= profileWrite)) break;
    upperChar = ___toupper((int)*profileRead);
    profileRead = profileRead + 1;
    *profileWrite = (char)upperChar;
    profileWrite = profileWrite + 1;
  }
  *profileWrite = '\0';
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
int _FinalCPP(unusedArg1, unusedArg2, unusedArg3, unusedArg4, unusedArg5, unusedArg6)
  undefined4 unusedArg1;
  undefined4 unusedArg2;
  undefined4 unusedArg3;
  undefined4 unusedArg4;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
{
  if (*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x34) != 0) {
    _CPPErrorToInfoLog("#if mismatch",unusedArg2,unusedArg3,unusedArg4,unusedArg5,unusedArg6,
                       *(int *)PTR__cpp_a7b7c0a4);
  }
  return 1;
}

/* _CPPdefine @ 0x97b86434 (940 bytes) */
int _CPPdefine(yylvalpp)
  int *yylvalpp;
{
  int readTokenResult2;
  undefined4 stringOfAtom;
  int loopIndex;
  int loopIndex2;
  undefined4 strfromTStr;
  undefined4 atomString;
  undefined *cppRef;
  int token;
  undefined4 r4Fwd;
  int readTokenResult;
  undefined4 extraOut1;
  undefined4 extraOut2;
  undefined4 extraOut3;
  undefined4 extraOut4;
  int *scratchR5;
  undefined4 leftoverR6;
  undefined4 leftoverR7;
  int scratchR8;
  int scratchR9;
  int macroAtom;
  int *argAtomWrite;
  int oldTokenInt;
  int macroSymbol;
  int argAtoms [64];
  int argCount;
  int argAtomsCopy;
  undefined4 bodyStream;
  undefined4 macroFlags;
  undefined2 dummyLocFile;
  undefined2 dummyLocLine;
  
  cppRef = PTR__cpp_a7b7c0a4;
  argCount = 0;
  macroFlags = 0;
  argAtomsCopy = 0;
  bodyStream = 0;
  token = (**(code **)(*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20) + 4))
                    (*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20),yylvalpp);
  r4Fwd = extraOut1;
  if (token == 0x10e) {
    macroAtom = yylvalpp[2];
    token = (**(code **)(*(int *)(*(int *)cppRef + 0x20) + 4))
                      (*(int *)(*(int *)cppRef + 0x20),yylvalpp);
    if ((token == 0x28) && (*yylvalpp == 0)) {
      argAtomWrite = argAtoms;
      loopIndex = 0;
      do {
        token = (**(code **)(*(int *)(*(int *)cppRef + 0x20) + 4))
                          (*(int *)(*(int *)cppRef + 0x20),yylvalpp);
        if ((loopIndex == 0) && (token == 0x29)) goto LAB_97b86554;
        r4Fwd = extraOut2;
        if (token != 0x10e) goto LAB_97b86774;
        if (loopIndex < 0x40) {
          loopIndex = loopIndex + 1;
          *argAtomWrite = yylvalpp[2];
          argAtomWrite = argAtomWrite + 1;
        }
        token = (**(code **)(*(int *)(*(int *)cppRef + 0x20) + 4))
                          (*(int *)(*(int *)cppRef + 0x20),yylvalpp);
      } while (token == 0x2c);
      r4Fwd = extraOut3;
      if (token != 0x29) goto LAB_97b86774;
LAB_97b86554:
      scratchR5 = (int *)(loopIndex << 2);
      argCount = loopIndex;
      argAtomsCopy = ((int (*)())_mem_Alloc)(*(undefined4 *)(_macros + 0x10),scratchR5);
      _memcpy(argAtomsCopy,argAtoms,scratchR5);
      scratchR9 = *(int *)PTR__cpp_a7b7c0a4;
      token = (**(code **)(*(int *)(scratchR9 + 0x20) + 4))
                        (*(int *)(scratchR9 + 0x20),yylvalpp,scratchR5,leftoverR6,leftoverR7,scratchR8,scratchR9);
    }
    atomString = _GetAtomString(*(undefined4 *)PTR__atable_a7b7c0ac,macroAtom);
    bodyStream = _NewTokenStream(atomString,*(undefined4 *)(_macros + 0x10));
    cppRef = PTR__cpp_a7b7c0a4;
    while (token != 10) {
      while (token == 0x5c) {
        token = (**(code **)(*(int *)(*(int *)cppRef + 0x20) + 4))
                          (*(int *)(*(int *)cppRef + 0x20),yylvalpp);
        if (token == 10) {
          token = (**(code **)(*(int *)(*(int *)cppRef + 0x20) + 4))
                            (*(int *)(*(int *)cppRef + 0x20),yylvalpp);
        }
        else {
          _RecordToken(bodyStream,0x5c,yylvalpp);
        }
      }
      scratchR5 = yylvalpp;
      _RecordToken(bodyStream,token,yylvalpp);
      token = (**(code **)(*(int *)(*(int *)cppRef + 0x20) + 4))
                        (*(int *)(*(int *)cppRef + 0x20),yylvalpp);
    }
    macroSymbol = _LookUpSymbol(_macros,macroAtom);
    if (macroSymbol == 0) {
      dummyLocFile = 0;
      dummyLocLine = dummyLocFile;
      macroSymbol = _AddSymbol(&dummyLocFile,_macros,macroAtom,0);
    }
    else if ((*(uint *)(macroSymbol + 0x24) & 0x40000000) == 0) {
      if (*(int *)(macroSymbol + 0x18) == argCount) {
        loopIndex2 = 0;
        if (0 < argCount) {
          scratchR8 = *(int *)(macroSymbol + 0x1c);
          do {
            scratchR9 = *(int *)(loopIndex2 * 4 + argAtomsCopy);
            if (*(int *)(loopIndex2 * 4 + scratchR8) != scratchR9) goto LAB_97b86728;
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 < argCount);
        }
        _RewindTokenStream(*(undefined4 *)(macroSymbol + 0x20));
        _RewindTokenStream(bodyStream);
        do {
          readTokenResult2 = _ReadToken(*(undefined4 *)(macroSymbol + 0x20),yylvalpp);
          oldTokenInt = *yylvalpp;
          readTokenResult = _ReadToken(bodyStream,yylvalpp);
          if ((readTokenResult != readTokenResult2) || (*yylvalpp != oldTokenInt)) goto LAB_97b86728;
        } while (0 < readTokenResult);
      }
      else {
LAB_97b86728:
        _StoreStr("Macro Redefined");
        stringOfAtom = ((int (*)())_GetStringOfAtom)(*(undefined4 *)PTR__atable_a7b7c0ac,macroAtom);
        _StoreStr(stringOfAtom);
        strfromTStr = _GetStrfromTStr();
        _DecLineNumber();
        _CPPShInfoLogMsg(strfromTStr,extraOut4,scratchR5,leftoverR6,leftoverR7,scratchR8,scratchR9);
        _IncLineNumber();
        _ResetTString();
      }
    }
    token = 10;
    *(undefined4 *)(macroSymbol + 0x24) = macroFlags;
    *(int *)(macroSymbol + 0x18) = argCount;
    *(int *)(macroSymbol + 0x1c) = argAtomsCopy;
    *(undefined4 *)(macroSymbol + 0x20) = bodyStream;
  }
  else {
LAB_97b86774:
    _CPPErrorToInfoLog("#define",r4Fwd,scratchR5,leftoverR6,leftoverR7,scratchR8,scratchR9);
  }
  return token;
}

/* _CPPundef @ 0x97b867e0 (208 bytes) */
int _CPPundef(yylvalpp)
  int yylvalpp;
{
  int lookUpSymbolResult;
  undefined *cppRef;
  int token;
  undefined4 extraOut1;
  undefined4 extraOut2;
  undefined4 r4Fwd;
  undefined4 leftoverR5;
  undefined4 leftoverR6;
  undefined4 leftoverR7;
  undefined4 leftoverR8;
  undefined4 leftoverR9;
  
  cppRef = PTR__cpp_a7b7c0a4;
  token = (**(code **)(*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20) + 4))
                    (*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20),yylvalpp);
  if (token == 10) {
    _CPPErrorToInfoLog("#undef",extraOut1,leftoverR5,leftoverR6,leftoverR7,leftoverR8,leftoverR9);
    token = 10;
  }
  else {
    r4Fwd = extraOut1;
    if (token == 0x10e) {
      lookUpSymbolResult = _LookUpSymbol(_macros,*(undefined4 *)(yylvalpp + 8));
      if (lookUpSymbolResult != 0) {
        *(uint *)(lookUpSymbolResult + 0x24) = *(uint *)(lookUpSymbolResult + 0x24) | 0x40000000;
      }
      token = (**(code **)(*(int *)(*(int *)cppRef + 0x20) + 4))
                        (*(int *)(*(int *)cppRef + 0x20),yylvalpp);
      r4Fwd = extraOut2;
      if (token == 10) {
        return 10;
      }
    }
    _CPPErrorToInfoLog("#undef",r4Fwd,leftoverR5,leftoverR6,leftoverR7,leftoverR8,leftoverR9);
  }
  return token;
}

/* _CPPelse @ 0x97b868b0 (740 bytes) */
int _CPPelse(matchElse, yylvalpp, unusedArg3, unusedArg4, unusedArg5, unusedArg6, unusedArg7)
  int matchElse;
  int yylvalpp;
  undefined4 unusedArg3;
  undefined4 unusedArg4;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
  int unusedArg7;
{
  int ifDepth;
  int afterElseToken;
  int cpPifResult;
  undefined *cppRef;
  int directiveAtom;
  int token;
  undefined4 extraOut1;
  int skipDepth;
  
  cppRef = PTR__cpp_a7b7c0a4;
  skipDepth = 0;
  token = (**(code **)(*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20) + 4))
                    (*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20),yylvalpp,unusedArg3,unusedArg4,unusedArg5,
                     unusedArg6,unusedArg7);
  do {
    while( true ) {
      while( true ) {
        while( true ) {
          do {
            while( true ) {
              if (token < 1) {
                return token;
              }
              if (token == 0x23) break;
              while (token != 10) {
                token = (**(code **)(*(int *)(*(int *)cppRef + 0x20) + 4))
                                  (*(int *)(*(int *)cppRef + 0x20),yylvalpp);
              }
              token = (**(code **)(*(int *)(*(int *)cppRef + 0x20) + 4))
                                (*(int *)(*(int *)cppRef + 0x20),yylvalpp);
            }
            token = (**(code **)(*(int *)(*(int *)cppRef + 0x20) + 4))
                              (*(int *)(*(int *)cppRef + 0x20),yylvalpp);
          } while (token != 0x10e);
          directiveAtom = *(int *)(yylvalpp + 8);
          if (((directiveAtom != _ifAtom) && (directiveAtom != _ifdefAtom)) && (directiveAtom != _ifndefAtom)) break;
          skipDepth = skipDepth + 1;
          *(int *)(*(int *)cppRef + 0x34) = *(int *)(*(int *)cppRef + 0x34) + 1;
          unusedArg7 = *(int *)cppRef;
          *(int *)(unusedArg7 + 0x138) = *(int *)(unusedArg7 + 0x138) + 1;
        }
        if (directiveAtom != _endifAtom) break;
        skipDepth = skipDepth + -1;
        if (skipDepth < 1) {
          *(undefined4 *)(*(int *)(*(int *)cppRef + 0x138) * 4 + *(int *)cppRef + 0x38) = 0;
          *(int *)(*(int *)cppRef + 0x138) = *(int *)(*(int *)cppRef + 0x138) + -1;
          ifDepth = *(int *)(*(int *)cppRef + 0x34);
          if (ifDepth == 0) {
            return 0x10e;
          }
          *(int *)(*(int *)cppRef + 0x34) = ifDepth + -1;
          return 0x10e;
        }
        *(int *)(*(int *)cppRef + 0x138) = *(int *)(*(int *)cppRef + 0x138) + -1;
        unusedArg7 = *(int *)cppRef;
        *(int *)(unusedArg7 + 0x34) = *(int *)(unusedArg7 + 0x34) + -1;
      }
      if ((matchElse != 0) && (skipDepth == 0)) break;
      if ((directiveAtom == _elseAtom) && (directiveAtom = ((int (*)())_ChkCorrectElseNesting)(), directiveAtom == 0)) {
        _CPPErrorToInfoLog("#else after a #else",extraOut1,unusedArg3,unusedArg4,unusedArg5,unusedArg6,unusedArg7
                          );
        *(undefined4 *)(*(int *)cppRef + 0x140) = 1;
      }
    }
    if (directiveAtom == _elseAtom) {
      afterElseToken = (**(code **)(*(int *)(*(int *)cppRef + 0x20) + 4))
                        (*(int *)(*(int *)cppRef + 0x20),yylvalpp,unusedArg3,unusedArg4,unusedArg5,unusedArg6,
                         unusedArg7);
      if (afterElseToken == 10) {
        return 10;
      }
      _CPPWarningToInfoLog
                ("unexpected tokens following #else preprocessor directive - expected a newline");
      do {
        afterElseToken = (**(code **)(*(int *)(*(int *)cppRef + 0x20) + 4))
                          (*(int *)(*(int *)cppRef + 0x20),yylvalpp);
      } while (afterElseToken != 10);
      return 10;
    }
  } while (directiveAtom != _elifAtom);
  ifDepth = *(int *)(*(int *)cppRef + 0x34);
  if (ifDepth != 0) {
    *(int *)(*(int *)cppRef + 0x34) = ifDepth + -1;
    *(int *)(*(int *)cppRef + 0x138) = *(int *)(*(int *)cppRef + 0x138) + -1;
  }
  cpPifResult = ((int (*)())_CPPif)(yylvalpp);
  return cpPifResult;
}

/* _op_logor @ 0x97b86b94 (28 bytes) */
int _op_logor(lhs, rhs)
  int lhs;
  int rhs;
{
  if ((lhs == 0) && (rhs == 0)) {
    return 0;
  }
  return 1;
}

/* _op_logand @ 0x97b86bb0 (28 bytes) */
int _op_logand(lhs, rhs)
  int lhs;
  int rhs;
{
  if (lhs == 0) {
    return 0;
  }
  if (rhs == 0) {
    return 0;
  }
  return 1;
}

/* _op_or @ 0x97b86bcc (8 bytes) */
int _op_or(lhs, rhs)
  uint lhs;
  uint rhs;
{
  return lhs | rhs;
}

/* _op_xor @ 0x97b86bd4 (8 bytes) */
int _op_xor(lhs, rhs)
  uint lhs;
  uint rhs;
{
  return lhs ^ rhs;
}

/* _op_and @ 0x97b86bdc (8 bytes) */
int _op_and(lhs, rhs)
  uint lhs;
  uint rhs;
{
  return lhs & rhs;
}

/* _op_eq @ 0x97b86be4 (16 bytes) */
int _op_eq(lhs, rhs)
  int lhs;
  int rhs;
{
  return lhs == rhs;
}

/* _op_ne @ 0x97b86bf4 (16 bytes) */
int _op_ne(lhs, rhs)
  int lhs;
  int rhs;
{
  return lhs != rhs;
}

/* _op_ge @ 0x97b86c04 (20 bytes) */
int _op_ge(lhs, rhs)
  int lhs;
  int rhs;
{
  if (rhs <= lhs) {
    return 1;
  }
  return 0;
}

/* _op_le @ 0x97b86c18 (20 bytes) */
int _op_le(lhs, rhs)
  int lhs;
  int rhs;
{
  if (lhs <= rhs) {
    return 1;
  }
  return 0;
}

/* _op_gt @ 0x97b86c2c (20 bytes) */
int _op_gt(lhs, rhs)
  int lhs;
  int rhs;
{
  if (rhs < lhs) {
    return 1;
  }
  return 0;
}

/* _op_lt @ 0x97b86c40 (20 bytes) */
int _op_lt(lhs, rhs)
  int lhs;
  int rhs;
{
  if (lhs < rhs) {
    return 1;
  }
  return 0;
}

/* _op_shl @ 0x97b86c54 (8 bytes) */
int _op_shl(lhs, rhs)
  int lhs;
  uint rhs;
{
  return lhs << (rhs & 0x3f);
}

/* _op_div @ 0x97b86c7c (8 bytes) */
int _op_div(lhs, rhs)
  int lhs;
  int rhs;
{
  return lhs / rhs;
}

/* _op_mod @ 0x97b86c84 (16 bytes) */
int _op_mod(lhs, rhs)
  int lhs;
  int rhs;
{
  return lhs - (lhs / rhs) * rhs;
}

/* _op_pos @ 0x97b86c94 (4 bytes) */
int _op_pos()
{
  return;
}

/* _op_cmpl @ 0x97b86ca0 (8 bytes) */
int _op_cmpl(value)
  uint value;
{
  return ~value;
}

/* _op_not @ 0x97b86ca8 (12 bytes) */
int _op_not(value)
  int value;
{
  return value == 0;
}

/* _eval @ 0x97b86cb4 (860 bytes) */
int _eval(token, precedence, result, errorFlag, yylvalpp)
  int token;
  int precedence;
  undefined4 *result;
  int *errorFlag;
  undefined4 *yylvalpp;
{
  undefined4 unopResult;
  undefined4 binopResult;
  undefined4 definedValue;
  undefined4 r4Artifact;
  int unopIndex;
  int binopIndex;
  int opPrecedence;
  int *binopCursor;
  int lookUpSymbolResult;
  bool hadOpenParen;
  undefined *cppRef;
  int errFlag;
  int tableToken;
  int nextToken;
  undefined4 extraOut1;
  undefined4 extraOut2;
  undefined4 extraOut3;
  int extraOut4;
  undefined4 *aliasResult;
  undefined4 *aliasYylvalpp;
  undefined4 leftoverR8;
  int cppState;
  int *aliasErrorFlag;
  int *cppRefInt;
  undefined4 lhsValue;
  undefined4 scanToken;
  undefined8 macroExpandResult;
  undefined8 r4TokenPair;
  
  nextToken = precedence;
  aliasResult = result;
  aliasErrorFlag = errorFlag;
  aliasYylvalpp = yylvalpp;
  while( true ) {
    cppRefInt = (int *)PTR__cpp_a7b7c0a4;
    r4TokenPair = CONCAT44(token,nextToken);
    if (token != 0x10e) break;
    if (yylvalpp[2] == _definedAtom) {
      nextToken = (**(code **)(*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20) + 4))
                        (*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20),yylvalpp);
      hadOpenParen = nextToken == 0x28;
      r4Artifact = extraOut1;
      if (hadOpenParen) {
        nextToken = (**(code **)(*(int *)(*cppRefInt + 0x20) + 4))(*(int *)(*cppRefInt + 0x20),yylvalpp);
        r4Artifact = extraOut2;
      }
      r4TokenPair = CONCAT44(nextToken,r4Artifact);
      if (nextToken != 0x10e) goto LAB_97b86fdc;
      definedValue = 0;
      lookUpSymbolResult = _LookUpSymbol(_macros,yylvalpp[2]);
      cppRefInt = (int *)PTR__cpp_a7b7c0a4;
      if ((lookUpSymbolResult != 0) && ((*(uint *)(lookUpSymbolResult + 0x24) & 0x40000000) == 0)) {
        definedValue = 1;
      }
      *result = definedValue;
      nextToken = (**(code **)(*(int *)(*cppRefInt + 0x20) + 4))(*(int *)(*cppRefInt + 0x20),yylvalpp);
      r4TokenPair = CONCAT44(nextToken,extraOut3);
      if (!hadOpenParen) goto LAB_97b86f0c;
      goto LAB_97b86e70;
    }
    macroExpandResult = ((int (*)())_MacroExpand)(yylvalpp[2],yylvalpp);
    r4TokenPair = CONCAT44(0x10e,(int)macroExpandResult);
    if ((int)((ulonglong)macroExpandResult >> 0x20) == 0) goto LAB_97b86fdc;
    cppState = *(int *)PTR__cpp_a7b7c0a4;
    token = (**(code **)(*(int *)(cppState + 0x20) + 4))
                        (*(int *)(cppState + 0x20),yylvalpp,aliasResult,aliasErrorFlag,aliasYylvalpp,leftoverR8,cppState);
    nextToken = extraOut4;
  }
  if (token == 0x10f) {
    *result = *yylvalpp;
    cppState = *cppRefInt;
    nextToken = *(int *)(cppState + 0x20);
LAB_97b86e10:
    nextToken = (**(code **)(nextToken + 4))(nextToken,yylvalpp,aliasResult,aliasErrorFlag,aliasYylvalpp,leftoverR8,cppState);
LAB_97b86f0c:
    errFlag = *errorFlag;
LAB_97b86f10:
    cppRef = PTR__cpp_a7b7c0a4;
    if (errFlag == 0) {
      while ((nextToken != 0x29 && (nextToken != 10))) {
        binopIndex = 0x11;
        binopCursor = &DAT_a7b7cf14;
        while (tableToken = *binopCursor, binopCursor = binopCursor + -3, tableToken != nextToken) {
          binopIndex = binopIndex + -1;
          if (binopIndex < 0) {
            return nextToken;
          }
        }
        if (binopIndex < 0) {
          return nextToken;
        }
        opPrecedence = *(int *)(&UNK_a7b7ce4c + binopIndex * 0xc);
        if (opPrecedence <= precedence) {
          return nextToken;
        }
        lhsValue = *result;
        scanToken = (**(code **)(*(int *)(*(int *)cppRef + 0x20) + 4))
                          (*(int *)(*(int *)cppRef + 0x20),yylvalpp);
        nextToken = ((int (*)())_eval)(scanToken,opPrecedence,result,errorFlag,yylvalpp);
        binopResult = (**(code **)(&UNK_a7b7ce50 + binopIndex * 0xc))(lhsValue,*result);
        *result = binopResult;
        if (*errorFlag != 0) {
          return nextToken;
        }
      }
    }
  }
  else {
    if (token == 0x28) {
      scanToken = (**(code **)(*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20) + 4))
                        (*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20),yylvalpp);
      aliasResult = result;
      aliasErrorFlag = errorFlag;
      aliasYylvalpp = yylvalpp;
      r4TokenPair = ((int (*)())_eval)(scanToken,0,result,errorFlag,yylvalpp);
      nextToken = (int)((ulonglong)r4TokenPair >> 0x20);
      errFlag = *errorFlag;
      if (errFlag != 0) goto LAB_97b86f10;
LAB_97b86e70:
      if ((int)((ulonglong)r4TokenPair >> 0x20) == 0x29) {
        nextToken = *(int *)(*cppRefInt + 0x20);
        goto LAB_97b86e10;
      }
    }
    else {
      unopIndex = 3;
      do {
        if (*(int *)(&_unop + unopIndex * 8) == token) {
          r4TokenPair = CONCAT44(token,nextToken);
          if (-1 < unopIndex) {
            nextToken = *(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20);
            scanToken = (**(code **)(nextToken + 4))
                              (nextToken,yylvalpp,aliasResult,aliasErrorFlag,aliasYylvalpp,leftoverR8,*(int *)PTR__cpp_a7b7c0a4);
            nextToken = ((int (*)())_eval)(scanToken,0xc,result,errorFlag,yylvalpp);
            unopResult = (**(code **)(&UNK_a7b7cf24 + unopIndex * 8))(*result);
            *result = unopResult;
            goto LAB_97b86f0c;
          }
          break;
        }
        unopIndex = unopIndex + -1;
      } while (-1 < unopIndex);
    }
LAB_97b86fdc:
    nextToken = (int)((ulonglong)r4TokenPair >> 0x20);
    _CPPErrorToInfoLog("incorrect preprocessor directive",(int)r4TokenPair,aliasResult,aliasErrorFlag,aliasYylvalpp,leftoverR8,cppState);
    *errorFlag = 1;
    *result = 0;
  }
  return nextToken;
}

/* _CPPif @ 0x97b87010 (308 bytes) */
int _CPPif(yylvalpp)
  undefined4 yylvalpp;
{
  int cppState;
  int oldIfDepth;
  undefined *cppRef;
  int endToken;
  undefined4 firstToken;
  undefined4 extraOut1;
  undefined4 leftoverR5;
  int *resultPtr;
  undefined4 leftoverR6;
  int *errorPtr;
  undefined4 leftoverR7;
  undefined4 yylvalForward;
  undefined4 leftoverR8;
  undefined4 *cppStateOrIfLoc;
  int exprValue;
  int exprError [4];
  
  cppRef = PTR__cpp_a7b7c0a4;
  firstToken = (**(code **)(*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20) + 4))
                    (*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20),yylvalpp);
  exprError[0] = 0;
  exprValue = 0;
  *(int *)(*(int *)cppRef + 0x138) = *(int *)(*(int *)cppRef + 0x138) + 1;
  cppStateOrIfLoc = *(undefined4 **)cppRef;
  oldIfDepth = cppStateOrIfLoc[0xd];
  cppStateOrIfLoc[0xd] = oldIfDepth + 1;
  if (oldIfDepth + 1 == 1) {
    cppState = *(int *)cppRef;
    cppStateOrIfLoc = *(undefined4 **)(cppState + 0x18);
    _ifloc = *cppStateOrIfLoc;
  }
  else {
    cppState = *(int *)cppRef;
  }
  if (*(int *)(cppState + 0x34) < 0x41) {
    resultPtr = &exprValue;
    errorPtr = exprError;
    yylvalForward = yylvalpp;
    endToken = ((int (*)())_eval)(firstToken,0,resultPtr,errorPtr,yylvalpp);
    if (endToken != 10) {
      _CPPWarningToInfoLog
                ("unexpected tokens following the preprocessor directive - expected a newline");
      cppRef = PTR__cpp_a7b7c0a4;
      do {
        endToken = (**(code **)(*(int *)(*(int *)cppRef + 0x20) + 4))
                          (*(int *)(*(int *)cppRef + 0x20),yylvalpp);
      } while (endToken != 10);
    }
    if ((exprValue == 0) && (exprError[0] == 0)) {
      endToken = ((int (*)())_CPPelse)(1,yylvalpp,resultPtr,errorPtr,yylvalForward,leftoverR8,cppStateOrIfLoc);
    }
  }
  else {
    _CPPErrorToInfoLog("max #if nesting depth exceeded",extraOut1,leftoverR5,leftoverR6,leftoverR7,leftoverR8,cppStateOrIfLoc);
    endToken = 0;
  }
  return endToken;
}

/* _CPPifdef @ 0x97b87144 (348 bytes) */
int _CPPifdef(isIfdef, yylvalpp)
  int isIfdef;
  int yylvalpp;
{
  int isDefined;
  int lookUpSymbolResult;
  undefined *cppRef;
  int ifDepth;
  int token;
  char *directiveName;
  undefined4 nameAtom;
  undefined4 leftoverR5;
  undefined4 leftoverR6;
  undefined4 leftoverR7;
  undefined4 leftoverR8;
  int cppState;
  uint elseTrackerOrUndefFlag;
  
  cppRef = PTR__cpp_a7b7c0a4;
  token = (**(code **)(*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20) + 4))
                    (*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20));
  cppState = *(int *)cppRef;
  nameAtom = *(undefined4 *)(yylvalpp + 8);
  ifDepth = *(int *)(cppState + 0x34) + 1;
  *(int *)(cppState + 0x34) = ifDepth;
  if (ifDepth < 0x41) {
    elseTrackerOrUndefFlag = *(int *)(*(int *)cppRef + 0x138) + 1;
    *(uint *)(*(int *)cppRef + 0x138) = elseTrackerOrUndefFlag;
    if (token == 0x10e) {
      lookUpSymbolResult = _LookUpSymbol(_macros,nameAtom);
      token = (**(code **)(*(int *)(*(int *)cppRef + 0x20) + 4))
                        (*(int *)(*(int *)cppRef + 0x20),yylvalpp);
      if (token != 10) {
        _CPPWarningToInfoLog
                  ("unexpected tokens following #ifdef preprocessor directive - expected a newline")
        ;
        do {
          token = (**(code **)(*(int *)(*(int *)cppRef + 0x20) + 4))
                            (*(int *)(*(int *)cppRef + 0x20),yylvalpp);
        } while (token != 10);
      }
      isDefined = 0;
      if ((lookUpSymbolResult != 0) && (elseTrackerOrUndefFlag = *(uint *)(lookUpSymbolResult + 0x24) & 0x40000000, elseTrackerOrUndefFlag == 0)) {
        isDefined = 1;
      }
      if (isDefined != isIfdef) {
        token = ((int (*)())_CPPelse)(1,yylvalpp,leftoverR5,leftoverR6,leftoverR7,leftoverR8,elseTrackerOrUndefFlag);
      }
    }
    else {
      if (isIfdef == 0) {
        directiveName = "ifndef";
      }
      else {
        directiveName = "ifdef";
      }
      _CPPErrorToInfoLog(directiveName,nameAtom,leftoverR5,leftoverR6,leftoverR7,leftoverR8,elseTrackerOrUndefFlag);
    }
  }
  else {
    _CPPErrorToInfoLog("max #if nesting depth exceeded",nameAtom,leftoverR5,leftoverR6,leftoverR7,leftoverR8,cppState);
    token = 0;
  }
  return token;
}

/* _CPPline @ 0x97b872a0 (268 bytes) */
int _CPPline(yylvalpp)
  undefined4 *yylvalpp;
{
  undefined4 atoiResult;
  undefined *cppRef;
  int token;
  undefined4 r4Fwd;
  int lastToken;
  undefined4 extraout_r4;
  undefined4 extraOut1;
  undefined4 extraout_r4_01;
  undefined4 extraout_r4_02;
  undefined4 leftoverR5;
  undefined4 leftoverR6;
  undefined4 leftoverR7;
  undefined4 leftoverR8;
  undefined4 leftoverR9;
  
  cppRef = PTR__cpp_a7b7c0a4;
  token = (**(code **)(*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20) + 4))
                    (*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20),yylvalpp);
  if (token == 10) {
    _DecLineNumber();
    _CPPErrorToInfoLog("#line",extraOut1,leftoverR5,leftoverR6,leftoverR7,leftoverR8,leftoverR9);
    _IncLineNumber();
    token = 10;
  }
  else {
    r4Fwd = extraout_r4;
    if (token == 0x10f) {
      atoiResult = _atoi(yylvalpp + 3);
      *yylvalpp = atoiResult;
      _SetLineNumber(atoiResult);
      token = *(int *)(*(int *)cppRef + 0x20);
      token = (**(code **)(token + 4))(token,yylvalpp);
      if (token == 0x10f) {
        atoiResult = _atoi(yylvalpp + 3);
        *yylvalpp = atoiResult;
        _SetStringNumber(atoiResult);
        token = *(int *)(*(int *)cppRef + 0x20);
        lastToken = (**(code **)(token + 4))(token,yylvalpp);
        token = lastToken;
        r4Fwd = extraout_r4_02;
      }
      else {
        lastToken = 10;
        r4Fwd = extraout_r4_01;
      }
      if (token == 10) {
        return lastToken;
      }
    }
    _CPPErrorToInfoLog("#line",r4Fwd,leftoverR5,leftoverR6,leftoverR7,leftoverR8,leftoverR9);
  }
  return token;
}

/* _CPPerror @ 0x97b873ac (232 bytes) */
int _CPPerror(yylvalpp)
  int yylvalpp;
{
  int messagePiece;
  undefined *cppRef;
  undefined *atableRef;
  int tokenOrAtom;
  undefined4 strfromTStr;
  undefined4 extraOut1;
  undefined4 leftoverR5;
  undefined4 leftoverR6;
  undefined4 leftoverR7;
  undefined4 leftoverR8;
  undefined4 leftoverR9;
  
  cppRef = PTR__cpp_a7b7c0a4;
  tokenOrAtom = (**(code **)(*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20) + 4))
                    (*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20),yylvalpp);
  atableRef = PTR__atable_a7b7c0ac;
  while (tokenOrAtom != 10) {
    if ((tokenOrAtom == 0x10b) || (tokenOrAtom == 0x10f)) {
      messagePiece = yylvalpp + 0xc;
    }
    else {
      if ((tokenOrAtom == 0x10e) || (tokenOrAtom == 0x116)) {
        tokenOrAtom = *(int *)(yylvalpp + 8);
      }
      messagePiece = ((int (*)())_GetStringOfAtom)(*(undefined4 *)atableRef,tokenOrAtom);
    }
    _StoreStr(messagePiece);
    tokenOrAtom = (**(code **)(*(int *)(*(int *)cppRef + 0x20) + 4))
                      (*(int *)(*(int *)cppRef + 0x20),yylvalpp);
  }
  _DecLineNumber();
  strfromTStr = _GetStrfromTStr();
  _CPPShInfoLogMsg(strfromTStr,extraOut1,leftoverR5,leftoverR6,leftoverR7,leftoverR8,leftoverR9);
  _ResetTString();
  *(undefined4 *)(*(int *)PTR__cpp_a7b7c0a4 + 0x140) = 1;
  _IncLineNumber();
  return 10;
}

/* _CPPpragma @ 0x97b87494 (528 bytes) */
int _CPPpragma(yylvalpp)
  int yylvalpp;
{
  int cppState;
  undefined4 r4Fwd;
  undefined4 tokenCopy;
  int length;
  undefined *cppRef;
  undefined *atableRef;
  uint token;
  undefined4 returnToken;
  undefined4 *allTokens;
  int tokenCapacity;
  undefined4 extraOut1;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  undefined4 extraout_r4_02;
  undefined4 leftoverR5;
  undefined4 leftoverR6;
  undefined4 leftoverR7;
  undefined4 leftoverR8;
  int currentInput;
  int nextCapacity;
  undefined2 *srcStr;
  undefined4 *freeCursor;
  int tokenCount;
  undefined2 charStr [10];
  
  cppState = *(int *)PTR__cpp_a7b7c0a4;
  tokenCount = 0;
  token = (**(code **)(*(int *)(cppState + 0x20) + 4))
                    (*(int *)(cppState + 0x20),yylvalpp,leftoverR5,leftoverR6,leftoverR7,leftoverR8,cppState);
  if (token == 10) {
    _DecLineNumber();
    _CPPErrorToInfoLog("#pragma",extraOut1,leftoverR5,leftoverR6,leftoverR7,leftoverR8,cppState);
    _IncLineNumber();
    returnToken = 10;
  }
  else {
    allTokens = (undefined4 *)_malloc(0x28);
    atableRef = PTR__atable_a7b7c0ac;
    r4Fwd = extraout_r4_00;
    tokenCapacity = 10;
    do {
      nextCapacity = tokenCapacity;
      if (tokenCapacity <= tokenCount) {
        nextCapacity = tokenCapacity << 1;
        allTokens = (undefined4 *)_realloc(allTokens,tokenCapacity << 3);
        r4Fwd = extraout_r4_01;
      }
      if (token == 0x10b) {
LAB_97b8758c:
        srcStr = (undefined2 *)(yylvalpp + 0xc);
        length = _strlen(srcStr);
        tokenCopy = _malloc(length + 1);
        allTokens[tokenCount] = tokenCopy;
      }
      else {
        if ((int)token < 0x10c) {
          if (token == 0xffffffff) {
            _CPPShInfoLogMsg("#pragma directive must end with a newline",r4Fwd,leftoverR5,leftoverR6,leftoverR7,
                             leftoverR8,cppState);
            return 0xffffffff;
          }
        }
        else {
          if (token == 0x10e) {
            srcStr = (undefined2 *)
                     _GetAtomString(*(undefined4 *)atableRef,*(undefined4 *)(yylvalpp + 8));
            length = _strlen(srcStr);
            tokenCopy = _malloc(length + 1);
            allTokens[tokenCount] = tokenCopy;
            goto LAB_97b875f0;
          }
          if (token == 0x10f) goto LAB_97b8758c;
        }
        charStr[0] = (undefined2)((token & 0xff) << 8);
        tokenCopy = _malloc(2);
        allTokens[tokenCount] = tokenCopy;
        srcStr = charStr;
      }
LAB_97b875f0:
      tokenCount = tokenCount + 1;
      _strcpy(tokenCopy,srcStr);
      cppRef = PTR__cpp_a7b7c0a4;
      token = (**(code **)(*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20) + 4))
                        (*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20),yylvalpp);
      r4Fwd = extraout_r4_02;
      tokenCapacity = nextCapacity;
    } while (token != 10);
    currentInput = *(int *)(*(int *)cppRef + 0x20);
    (**(code **)(currentInput + 0xc))(currentInput,10,yylvalpp);
    _HandlePragma(allTokens,tokenCount);
    currentInput = *(int *)(*(int *)cppRef + 0x20);
    returnToken = (**(code **)(currentInput + 4))(currentInput,yylvalpp);
    freeCursor = allTokens;
    if (0 < tokenCount) {
      do {
        _free(*freeCursor);
        tokenCount = tokenCount + -1;
        freeCursor = freeCursor + 1;
      } while (tokenCount != 0);
    }
    _free(allTokens);
  }
  return returnToken;
}

/* _CPPversion @ 0x97b876a4 (256 bytes) */
int _CPPversion(yylvalpp)
  int *yylvalpp;
{
  int currentInput;
  int atoiResult;
  undefined *cppRef;
  int token;
  int nextToken;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 r4Fwd;
  undefined4 extraOut1;
  undefined4 extraOut2;
  undefined4 extraOut3;
  undefined4 leftoverR5;
  undefined4 leftoverR6;
  undefined4 leftoverR7;
  undefined4 leftoverR8;
  undefined4 leftoverR9;
  
  cppRef = PTR__cpp_a7b7c0a4;
  token = (**(code **)(*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20) + 4))
                    (*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20),yylvalpp);
  r4Fwd = extraout_r4;
  if (*(int *)(*(int *)cppRef + 0x28) == 1) {
    _CPPShInfoLogMsg("#version must occur before any other statement in the program",extraout_r4,
                     leftoverR5,leftoverR6,leftoverR7,leftoverR8,leftoverR9);
    r4Fwd = extraout_r4_00;
  }
  if (token == 10) {
    _DecLineNumber();
    _CPPErrorToInfoLog("#version",extraOut1,leftoverR5,leftoverR6,leftoverR7,leftoverR8,leftoverR9);
    _IncLineNumber();
    token = 10;
  }
  else {
    if (token != 0x10f) {
      _CPPErrorToInfoLog("#version",r4Fwd,leftoverR5,leftoverR6,leftoverR7,leftoverR8,leftoverR9);
    }
    atoiResult = _atoi(yylvalpp + 3);
    *yylvalpp = atoiResult;
    if (atoiResult != 0x6e) {
      _CPPShInfoLogMsg("Version number not supported by GL2",extraOut2,leftoverR5,leftoverR6,leftoverR7,leftoverR8,
                       leftoverR9);
    }
    currentInput = *(int *)(*(int *)cppRef + 0x20);
    nextToken = (**(code **)(currentInput + 4))(currentInput,yylvalpp);
    token = 10;
    if (nextToken != 10) {
      _CPPErrorToInfoLog("#version",extraOut3,leftoverR5,leftoverR6,leftoverR7,leftoverR8,leftoverR9);
      token = nextToken;
    }
  }
  return token;
}

/* _CPPextension @ 0x97b877a4 (348 bytes) */
int _CPPextension(yylvalpp)
  int yylvalpp;
{
  undefined4 atomString;
  undefined *cppRef;
  undefined *atableRef;
  int token;
  undefined4 messageR4;
  char *errorMessage;
  undefined4 extraOut1;
  undefined4 extraOut2;
  undefined4 extraout_r4_01;
  undefined4 extraout_r4_02;
  undefined4 extraOut3;
  undefined4 leftoverR5;
  undefined4 leftoverR6;
  undefined4 leftoverR7;
  undefined4 leftoverR8;
  undefined4 leftoverR9;
  undefined1 extensionName [92];
  
  cppRef = PTR__cpp_a7b7c0a4;
  token = (**(code **)(*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20) + 4))
                    (*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20),yylvalpp);
  if (token == 10) {
    _DecLineNumber();
    _CPPShInfoLogMsg("extension name not specified",extraOut2,leftoverR5,leftoverR6,leftoverR7,leftoverR8,leftoverR9);
    _IncLineNumber();
    token = 10;
  }
  else {
    if (token != 0x10e) {
      _CPPErrorToInfoLog("#extension",extraOut1,leftoverR5,leftoverR6,leftoverR7,leftoverR8,leftoverR9);
    }
    atableRef = PTR__atable_a7b7c0ac;
    atomString = _GetAtomString(*(undefined4 *)PTR__atable_a7b7c0ac,*(undefined4 *)(yylvalpp + 8));
    _strcpy(extensionName,atomString);
    token = (**(code **)(*(int *)(*(int *)cppRef + 0x20) + 4))
                      (*(int *)(*(int *)cppRef + 0x20),yylvalpp);
    if (token == 0x3a) {
      token = (**(code **)(*(int *)(*(int *)cppRef + 0x20) + 4))
                        (*(int *)(*(int *)cppRef + 0x20),yylvalpp);
      if (token == 0x10e) {
        atomString = _GetAtomString(*(undefined4 *)atableRef,*(undefined4 *)(yylvalpp + 8));
        _updateExtensionBehavior(extensionName,atomString);
        token = (**(code **)(*(int *)(*(int *)cppRef + 0x20) + 4))
                          (*(int *)(*(int *)cppRef + 0x20),yylvalpp);
        if (token == 10) {
          return 10;
        }
        _CPPErrorToInfoLog("#extension",extraOut3,leftoverR5,leftoverR6,leftoverR7,leftoverR8,leftoverR9);
        return token;
      }
      errorMessage = "behavior for extension not specified";
      messageR4 = extraout_r4_02;
    }
    else {
      errorMessage = "\':\' missing after extension name";
      messageR4 = extraout_r4_01;
    }
    _CPPShInfoLogMsg(errorMessage,messageR4,leftoverR5,leftoverR6,leftoverR7,leftoverR8,leftoverR9);
  }
  return token;
}

/* _readCPPline @ 0x97b87900 (972 bytes) */
int _readCPPline(yylvalpp)
  int yylvalpp;
{
  int cppStateInput;
  int cppState;
  int chkCorrectElseNestingResult;
  undefined4 stringOfAtom;
  undefined4 strfromTStr;
  undefined *cppRef;
  int directiveAtom;
  int token;
  undefined4 isIfdef;
  undefined4 extraOut1;
  undefined4 extraOut2;
  undefined4 extraOut3;
  undefined4 leftoverR5;
  undefined4 leftoverR6;
  undefined4 leftoverR7;
  undefined4 leftoverR8;
  undefined4 leftoverR9;
  uint versionFlag;
  
  cppRef = PTR__cpp_a7b7c0a4;
  versionFlag = 0;
  token = (**(code **)(*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20) + 4))
                    (*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20),yylvalpp);
  if (token == 0x10e) {
    directiveAtom = *(int *)(yylvalpp + 8);
    if (directiveAtom == _defineAtom) {
      token = ((int (*)())_CPPdefine)(yylvalpp);
    }
    else {
      if (directiveAtom == _elseAtom) {
        chkCorrectElseNestingResult = ((int (*)())_ChkCorrectElseNesting)();
        if (chkCorrectElseNestingResult == 0) {
          _CPPErrorToInfoLog("#else after a #else",extraOut2,leftoverR5,leftoverR6,leftoverR7,leftoverR8,leftoverR9);
          token = 0;
          versionFlag = 1;
          *(undefined4 *)(*(int *)cppRef + 0x34) = 0;
          cppState = *(int *)cppRef;
          goto LAB_97b87cb4;
        }
        cppStateInput = *(int *)cppRef;
        if (*(int *)(cppStateInput + 0x34) == 0) {
          _CPPErrorToInfoLog("#else mismatch",extraOut2,leftoverR5,leftoverR6,leftoverR7,leftoverR8,leftoverR9);
          *(undefined4 *)(*(int *)cppRef + 0x140) = 1;
          cppStateInput = *(int *)cppRef;
        }
        token = (**(code **)(*(int *)(cppStateInput + 0x20) + 4))(*(int *)(cppStateInput + 0x20),yylvalpp);
        if (token != 10) {
          _CPPWarningToInfoLog
                    ("unexpected tokens following #else preprocessor directive - expected a newline"
                    );
          do {
            token = (**(code **)(*(int *)(*(int *)cppRef + 0x20) + 4))
                              (*(int *)(*(int *)cppRef + 0x20),yylvalpp);
          } while (token != 10);
        }
      }
      else {
        if (directiveAtom != _elifAtom) {
          if (directiveAtom == _endifAtom) {
            *(undefined4 *)(*(int *)(*(int *)cppRef + 0x138) * 4 + *(int *)cppRef + 0x38) = 0;
            *(int *)(*(int *)cppRef + 0x138) = *(int *)(*(int *)cppRef + 0x138) + -1;
            cppState = *(int *)cppRef;
            if (*(int *)(cppState + 0x34) == 0) {
              _CPPErrorToInfoLog("#endif mismatch",extraOut1,leftoverR5,leftoverR6,leftoverR7,leftoverR8,cppState);
              *(undefined4 *)(*(int *)cppRef + 0x140) = 1;
            }
            else {
              *(int *)(cppState + 0x34) = *(int *)(cppState + 0x34) + -1;
            }
          }
          else if (directiveAtom == _ifAtom) {
            token = ((int (*)())_CPPif)(yylvalpp);
          }
          else {
            isIfdef = 1;
            if (directiveAtom != _ifdefAtom) {
              if (directiveAtom != _ifndefAtom) {
                if (directiveAtom == _lineAtom) {
                  token = ((int (*)())_CPPline)(yylvalpp);
                }
                else if (directiveAtom == _pragmaAtom) {
                  token = ((int (*)())_CPPpragma)(yylvalpp);
                }
                else if (directiveAtom == _undefAtom) {
                  token = ((int (*)())_CPPundef)(yylvalpp);
                }
                else if (directiveAtom == _errorAtom) {
                  token = ((int (*)())_CPPerror)(yylvalpp);
                }
                else if (directiveAtom == _versionAtom) {
                  versionFlag = 1;
                  token = ((int (*)())_CPPversion)(yylvalpp);
                }
                else if (directiveAtom == _extensionAtom) {
                  token = ((int (*)())_CPPextension)(yylvalpp);
                }
                else {
                  _StoreStr("Invalid Directive");
                  stringOfAtom = ((int (*)())_GetStringOfAtom)(*(undefined4 *)PTR__atable_a7b7c0ac,
                                           *(undefined4 *)(yylvalpp + 8));
                  _StoreStr(stringOfAtom);
                  strfromTStr = _GetStrfromTStr();
                  _CPPShInfoLogMsg(strfromTStr,extraOut3,leftoverR5,leftoverR6,leftoverR7,leftoverR8,leftoverR9);
                  _ResetTString();
                }
                goto LAB_97b87c50;
              }
              isIfdef = 0;
            }
            token = ((int (*)())_CPPifdef)(isIfdef,yylvalpp);
          }
          goto LAB_97b87c50;
        }
        cppStateInput = *(int *)cppRef;
        if (*(int *)(cppStateInput + 0x34) == 0) {
          _CPPErrorToInfoLog("#elif mismatch",extraOut1,leftoverR5,leftoverR6,leftoverR7,leftoverR8,leftoverR9);
          *(undefined4 *)(*(int *)cppRef + 0x140) = 1;
          cppStateInput = *(int *)cppRef;
        }
        token = (**(code **)(*(int *)(cppStateInput + 0x20) + 4))(*(int *)(cppStateInput + 0x20),yylvalpp);
        while (token != 10) {
          token = (**(code **)(*(int *)(*(int *)cppRef + 0x20) + 4))
                            (*(int *)(*(int *)cppRef + 0x20),yylvalpp);
        }
      }
      token = ((int (*)())_CPPelse)(0,yylvalpp,leftoverR5,leftoverR6,leftoverR7,leftoverR8,leftoverR9);
    }
  }
LAB_97b87c50:
  cppRef = PTR__cpp_a7b7c0a4;
  if ((token != 10) && (token != 0)) {
    while (token != -1) {
      token = (**(code **)(*(int *)(*(int *)cppRef + 0x20) + 4))
                        (*(int *)(*(int *)cppRef + 0x20),yylvalpp);
      if ((token == 10) || (token == 0)) break;
    }
  }
  versionFlag = versionFlag ^ 1;
  cppState = *(int *)PTR__cpp_a7b7c0a4;
LAB_97b87cb4:
  *(uint *)(cppState + 0x28) = versionFlag;
  return token;
}

/* _FreeMacro @ 0x97b87ccc (8 bytes) */
int _FreeMacro(param_1)
  int param_1;
{
  return _DeleteTokenStream(*(undefined4 *)(param_1 + 8));
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
  undefined4 *allocation;
  int iVar4;
  
  allocation = (undefined4 *)_malloc(0x18);
  uVar2 = DAT_a7b7b010;
  uVar1 = DAT_a7b7b00c;
  iVar4 = *(int *)PTR__cpp_a7b7c0a4;
  *allocation = 0;
  allocation[5] = 0;
  allocation[2] = uVar2;
  allocation[3] = uVar1;
  allocation[4] = 0;
  allocation[1] = uVar2;
  *allocation = *(undefined4 *)(iVar4 + 0x20);
  *(undefined4 **)(iVar4 + 0x20) = allocation;
  return allocation;
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
  undefined4 newTokenStreamResult;
  
  _RewindTokenStream(param_1);
  do {
    iVar2 = _ReadToken(param_1,param_2);
    if ((iVar2 == 0x10e) &&
       (iVar3 = _LookUpSymbol(_macros,*(undefined4 *)(param_2 + 8)), iVar3 != 0)) break;
  } while (0 < iVar2);
  if (0 < iVar2) {
    newTokenStreamResult = _NewTokenStream("macro arg",0);
    ((int (*)())_PushEofSrc)();
    _ReadFromTokenStream(param_1,0,0);
    puVar1 = PTR__cpp_a7b7c0a4;
    while (iVar2 = (**(code **)(*(int *)(*(int *)puVar1 + 0x20) + 4))
                             (*(int *)(*(int *)puVar1 + 0x20),param_2), 0 < iVar2) {
      if ((iVar2 != 0x10e) ||
         (iVar3 = ((int (*)())_MacroExpand)(*(undefined4 *)(param_2 + 8),param_2), iVar3 == 0)) {
        _RecordToken(newTokenStreamResult,iVar2,param_2);
      }
    }
    ((int (*)())_PopEofSrc)();
    _DeleteTokenStream(param_1);
    param_1 = newTokenStreamResult;
  }
  return param_1;
}

/* _macro_scan @ 0x97b87eac (336 bytes) */
int _macro_scan(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 *param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  int readTokenResult;
  bool bVar1;
  undefined *puVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  
  readTokenResult = _ReadToken(*(undefined4 *)(param_1[6] + 8),param_2);
  puVar2 = PTR__cpp_a7b7c0a4;
  if (readTokenResult == 0x10e) {
    iVar6 = *(int *)param_1[6] + -1;
    bVar1 = iVar6 < 0;
    if (!bVar1) {
      piVar4 = (int *)(iVar6 * 4 + ((int *)param_1[6])[1]);
      do {
        iVar3 = *piVar4;
        piVar4 = piVar4 + -1;
        if (iVar3 == *(int *)(param_2 + 8)) {
          if (!bVar1) {
            param_3 = 0;
            _ReadFromTokenStream
                      (*(undefined4 *)(iVar6 * 4 + param_1[7]),*(undefined4 *)(param_2 + 8),0);
            goto LAB_97b87fc4;
          }
          break;
        }
        iVar6 = iVar6 + -1;
        bVar1 = iVar6 < 0;
      } while (!bVar1);
    }
  }
  if (0 < readTokenResult) {
    return;
  }
  *(uint *)(param_1[6] + 0xc) = *(uint *)(param_1[6] + 0xc) & 0x7fffffff;
  *(undefined4 *)(*(int *)puVar2 + 0x20) = *param_1;
  iVar5 = param_1[7];
  if (iVar5 != 0) {
    iVar6 = *(int *)param_1[6] + -1;
    if (-1 < iVar6) {
      while( true ) {
        _DeleteTokenStream(*(undefined4 *)(iVar6 * 4 + iVar5));
        iVar6 = iVar6 + -1;
        if (iVar6 < 0) break;
        iVar5 = param_1[7];
      }
      iVar5 = param_1[7];
    }
    _free(iVar5);
  }
  _free(param_1);
LAB_97b87fc4:
  iVar5 = *(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20);
                    
                    
  (**(code **)(iVar5 + 4))(iVar5,param_2,param_3,param_4,param_5,param_6,*(int *)PTR__cpp_a7b7c0a4);
  return;
}

/* _MacroExpand @ 0x97b87ffc (1024 bytes) */
int _MacroExpand(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined4 prescanMacroArgResult;
  undefined4 atoiResult;
  int newTokenStreamResult;
  undefined4 stringOfAtom;
  int loopIndex;
  undefined4 strfromTStr;
  undefined4 allocation2;
  bool bVar1;
  bool bVar2;
  bool bVar3;
  undefined *puVar4;
  undefined *puVar5;
  int lookUpSymbolResult;
  undefined4 uVar7;
  undefined4 *allocation;
  int iVar9;
  char *pcVar10;
  undefined4 extraOut1;
  undefined4 extraOut2;
  undefined4 *in_r5;
  undefined4 leftoverR6;
  undefined4 leftoverR7;
  undefined4 leftoverR8;
  int *a6;
  int iVar11;
  int iVar12;
  
  lookUpSymbolResult = _LookUpSymbol(_macros,param_1);
  if (param_1 == ___LINE__Atom) {
    uVar7 = _GetLineNumber();
  }
  else {
    if (param_1 != ___FILE__Atom) {
      if (param_1 != ___VERSION__Atom) {
        if ((lookUpSymbolResult == 0) || ((*(uint *)(lookUpSymbolResult + 0x24) & 0x40000000) != 0)) {
          return 0;
        }
        if ((int)*(uint *)(lookUpSymbolResult + 0x24) < 0) {
          return 0;
        }
        allocation = (undefined4 *)_malloc(0x20);
        uVar7 = DAT_a7b7b008;
        iVar11 = *(int *)PTR__cpp_a7b7c0a4;
        allocation[4] = 0;
        allocation[5] = 0;
        allocation[6] = 0;
        allocation[7] = 0;
        *allocation = 0;
        allocation[2] = 0;
        allocation[3] = 0;
        allocation[1] = uVar7;
        allocation[5] = *(undefined4 *)(*(int *)(iVar11 + 0x20) + 0x14);
        a6 = *(int **)(*(int *)(iVar11 + 0x20) + 0x10);
        allocation[6] = lookUpSymbolResult + 0x18;
        allocation[4] = a6;
        if (*(int *)(lookUpSymbolResult + 0x1c) != 0) {
          iVar11 = (**(code **)(*(int *)(iVar11 + 0x20) + 4))
                             (*(int *)(iVar11 + 0x20),param_2,in_r5,leftoverR6,leftoverR7,leftoverR8,a6,iVar11);
          if (iVar11 != 0x28) {
            _UngetToken(iVar11,param_2);
            param_2[2] = param_1;
            return 0;
          }
          allocation2 = _malloc(*(int *)allocation[6] << 2);
          allocation[7] = allocation2;
          iVar11 = 0;
          if (0 < *(int *)allocation[6]) {
            do {
              newTokenStreamResult = _NewTokenStream("macro arg",0);
              a6 = (int *)allocation[7];
              iVar12 = iVar11 + 1;
              a6[iVar11] = newTokenStreamResult;
              iVar11 = iVar12;
            } while (iVar12 < *(int *)allocation[6]);
          }
          puVar4 = PTR__cpp_a7b7c0a4;
          loopIndex = 0;
          bVar3 = false;
LAB_97b881d8:
          iVar9 = 0;
          do {
            iVar12 = (**(code **)(*(int *)(*(int *)puVar4 + 0x20) + 4))
                               (*(int *)(*(int *)puVar4 + 0x20),param_2);
            puVar5 = PTR__cpp_a7b7c0a4;
            bVar1 = 0 < iVar12;
            if (!bVar1) goto LAB_97b8830c;
            a6 = (int *)allocation[6];
            bVar2 = iVar12 == 0x29;
            if ((*a6 == 0) && (!bVar2)) goto LAB_97b88284;
            if (iVar9 == 0) {
              if (iVar12 == 0x2c) goto LAB_97b88284;
              if (bVar2) {
                if ((*a6 != 1) || (bVar3)) {
                  loopIndex = loopIndex + 1;
                }
                goto LAB_97b88294;
              }
            }
            if (iVar12 == 0x28) {
              iVar9 = iVar9 + 1;
            }
            if (bVar2) {
              iVar9 = iVar9 + -1;
            }
            bVar3 = true;
            in_r5 = param_2;
            _RecordToken(*(undefined4 *)(loopIndex * 4 + allocation[7]),iVar12,param_2);
          } while( true );
        }
        goto LAB_97b883b8;
      }
      param_2[3] = 0x31303000;
      atoiResult = _atoi(param_2 + 3);
      *param_2 = atoiResult;
      goto LAB_97b88078;
    }
    uVar7 = _GetStringNumber();
  }
  *param_2 = uVar7;
  _sprintf((char *)(param_2 + 3),"%d",uVar7);
LAB_97b88078:
  _UngetToken(0x10f,param_2);
  return 1;
LAB_97b88284:
  loopIndex = loopIndex + 1;
  if (*a6 <= loopIndex) goto LAB_97b88294;
  goto LAB_97b881d8;
LAB_97b88294:
  if (loopIndex < *a6) {
    pcVar10 = "Too few args in Macro ";
LAB_97b8834c:
    _StoreStr(pcVar10);
    stringOfAtom = ((int (*)())_GetStringOfAtom)(*(undefined4 *)PTR__atable_a7b7c0ac,param_1);
    _StoreStr(stringOfAtom);
    strfromTStr = _GetStrfromTStr();
    _CPPShInfoLogMsg(strfromTStr,extraOut2,in_r5,leftoverR6,leftoverR7,leftoverR8,a6);
    _ResetTString();
    a6 = (int *)allocation[6];
  }
  else if (!bVar2) {
    iVar11 = 0;
    if (-1 < iVar12) {
      bVar3 = false;
      do {
        if (bVar3) {
          iVar11 = iVar11 + -1;
        }
        iVar9 = (**(code **)(*(int *)(*(int *)puVar5 + 0x20) + 4))
                          (*(int *)(*(int *)puVar5 + 0x20),param_2);
        if (iVar9 == 0x28) {
          iVar11 = iVar11 + 1;
        }
        bVar1 = 0 < iVar9;
      } while ((-1 < iVar9) && ((bVar3 = iVar9 == 0x29, 0 < iVar11 || (!bVar3))));
    }
    if (!bVar1) {
LAB_97b8830c:
      _StoreStr("EOF in Macro ");
      stringOfAtom = ((int (*)())_GetStringOfAtom)(*(undefined4 *)PTR__atable_a7b7c0ac,param_1);
      _StoreStr(stringOfAtom);
      strfromTStr = _GetStrfromTStr();
      _CPPShInfoLogMsg(strfromTStr,extraOut1,in_r5,leftoverR6,leftoverR7,leftoverR8,a6);
      _ResetTString();
      return 1;
    }
    pcVar10 = "Too many args in Macro ";
    goto LAB_97b8834c;
  }
  loopIndex = 0;
  if (0 < *a6) {
    do {
      iVar9 = loopIndex * 4;
      loopIndex = loopIndex + 1;
      prescanMacroArgResult = ((int (*)())_PrescanMacroArg)(*(undefined4 *)(iVar9 + allocation[7]),param_2);
      *(undefined4 *)(iVar9 + allocation[7]) = prescanMacroArgResult;
    } while (loopIndex < *(int *)allocation[6]);
  }
LAB_97b883b8:
  puVar4 = PTR__cpp_a7b7c0a4;
  *allocation = *(undefined4 *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20);
  *(uint *)(lookUpSymbolResult + 0x24) = *(uint *)(lookUpSymbolResult + 0x24) | 0x80000000;
  _RewindTokenStream(*(undefined4 *)(lookUpSymbolResult + 0x20));
  *(undefined4 **)(*(int *)puVar4 + 0x20) = allocation;
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
  int *allocation;
  undefined1 *puVar3;
  int iVar4;
  
  allocation = (int *)_malloc(0x158);
  uVar1 = 0;
  _cpp = allocation;
  if (allocation != (int *)0x0) {
    _refCount = _refCount + 1;
    *allocation = (int)(allocation + 5);
    iVar4 = 0x10;
    puVar3 = (undefined1 *)((int)allocation + 0x13);
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
  int initScannerResult;
  undefined *puVar1;
  int initAtomTableResult;
  uint uVar3;
  
  ((int (*)())_FreeCPPStruct)();
  ((int (*)())_InitCPPStruct)();
  *(undefined4 *)(_cpp + 0xc) = 1;
  puVar1 = PTR__atable_a7b7c0ac;
  *(char **)(_cpp + 4) = "generic";
  initAtomTableResult = ((int (*)())_InitAtomTable)(*(undefined4 *)puVar1,0);
  uVar3 = 1;
  if (initAtomTableResult != 0) {
    initScannerResult = ((int (*)())_InitScanner)(_cpp);
    uVar3 = (uint)(initScannerResult == 0);
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
  undefined4 *allocation;
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
      allocation = (undefined4 *)_malloc(param_1);
      puVar1 = (undefined4 *)0x0;
      if (allocation != (undefined4 *)0x0) {
        allocation[2] = (int)allocation + param_1;
        allocation[5] = 0;
        allocation[1] = (int)allocation + param_2 + 0x17 & ~uVar3;
        *allocation = 0;
        allocation[3] = param_1;
        allocation[4] = uVar3;
        puVar1 = allocation;
      }
    }
  }
  return puVar1;
}

/* _mem_FreePool @ 0x97b88768 (108 bytes) */
int _mem_FreePool(param_1)
  int *param_1;
{
  int *piVar1;
  int iVar2;
  
  for (piVar1 = (int *)param_1[5]; piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {
    (*(code *)piVar1[1])(piVar1[2]);
  }
  while (param_1 != (int *)0x0) {
    iVar2 = *param_1;
    _free(param_1);
    param_1 = (int *)iVar2;
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
  undefined4 *allocation;
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
      allocation = (undefined4 *)_malloc(param_1[3]);
      if (allocation == (undefined4 *)0x0) {
        return 0;
      }
      param_1[1] = (int)allocation + uVar1;
      param_1[2] = (int)allocation + param_1[3];
    }
    else {
      allocation = (undefined4 *)_malloc(uVar1);
      if (allocation == (undefined4 *)0x0) {
        return 0;
      }
    }
    *allocation = *param_1;
    *param_1 = allocation;
    uVar2 = (int)allocation + param_1[4] + 4 & ~param_1[4];
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
  undefined4 *mem_AllocResult;
  
  *(uint *)(param_1 + 4) = *(int *)(param_1 + 4) + 3U & 0xfffffffc;
  mem_AllocResult = (undefined4 *)((int (*)())_mem_Alloc)(param_1,0xc);
  uVar1 = 0xffffffff;
  if (mem_AllocResult != (undefined4 *)0x0) {
    uVar1 = *(undefined4 *)(param_1 + 0x14);
    mem_AllocResult[1] = param_2;
    *mem_AllocResult = uVar1;
    uVar1 = 0;
    mem_AllocResult[2] = param_3;
    *(undefined4 **)(param_1 + 0x14) = mem_AllocResult;
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
  int initCPPResult;
  
  initCPPResult = ((int (*)())_InitCPP)();
  if (initCPPResult != 0) {
    *(int *)(param_1 + 0x18) = param_1 + 0x30;
    *(undefined4 *)(param_1 + 0x28) = 0;
    *(undefined **)(param_1 + 0x20) = &_eof_inputsrc;
    *(undefined4 *)(param_1 + 0x24) = 10;
    *(undefined4 *)(param_1 + 0x1c) = 0;
    *(undefined2 *)(param_1 + 0x30) = 0;
    *(undefined2 *)(param_1 + 0x32) = 0;
  }
  return initCPPResult != 0;
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
  return _DecLineNumber();
}

/* _ScanFromString @ 0x97b88af4 (148 bytes) */
int _ScanFromString(param_1)
  undefined4 param_1;
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *allocation;
  int iVar4;
  
  allocation = (undefined4 *)_malloc(0x1c);
  uVar1 = DAT_a7b7b038;
  uVar2 = DAT_a7b7b034;
  iVar4 = *(int *)PTR__cpp_a7b7c0a4;
  allocation[4] = 0;
  allocation[1] = uVar1;
  uVar1 = DAT_a7b7b030;
  *allocation = 0;
  allocation[6] = param_1;
  allocation[5] = 1;
  allocation[2] = uVar2;
  allocation[3] = uVar1;
  *allocation = *(undefined4 *)(iVar4 + 0x20);
  *(undefined4 **)(iVar4 + 0x20) = allocation;
  return 1;
}

/* _lBuildFloatValue @ 0x97b88b88 (272 bytes) */
double _lBuildFloatValue(int param_1,int param_2,uint param_3)
{
  float fVar1;
  char *pcVar2;
  uint uVar3;
  undefined4 leftoverR6;
  undefined4 leftoverR7;
  undefined4 leftoverR8;
  int iVar4;
  int iVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  
  iVar4 = 0;
  iVar5 = param_2;
  dVar7 = DOUBLE_97c30a48;
  if (0 < param_2) {
    do {
      pcVar2 = (char *)(param_1 + iVar4);
      iVar4 = iVar4 + 1;
      dVar7 = dVar7 * DOUBLE_97c30a50 +
              ((double)CONCAT44(0x43300000,(int)*pcVar2 - 0x30U ^ 0x80000000) - DOUBLE_97c30a58);
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  if (param_3 != 0) {
    dVar6 = DOUBLE_97c30a50;
    dVar8 = DOUBLE_97c30a60;
    for (uVar3 = ((int)param_3 >> 0x1f ^ param_3) - ((int)param_3 >> 0x1f); uVar3 != 0;
        uVar3 = (int)uVar3 >> 1) {
      if ((uVar3 & 1) != 0) {
        dVar8 = dVar8 * dVar6;
      }
      dVar6 = dVar6 * dVar6;
    }
    if ((int)param_3 < 0) {
      dVar7 = dVar7 / dVar8;
    }
    else {
      dVar7 = dVar7 * dVar8;
    }
  }
  fVar1 = (float)dVar7;
  if ((((uint)GH_F2U(fVar1) & 0x7f800000) == 0x7f800000) && (((uint)GH_F2U(fVar1) & 0x7fffff) == 0)) {
    _CPPErrorToInfoLog(" ERROR___FP_CONST_OVERFLOW",param_2,0,leftoverR6,leftoverR7,leftoverR8,iVar4);
  }
  return (double)fVar1;
}

