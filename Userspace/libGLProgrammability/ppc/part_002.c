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
  int counterIndex;
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
  counterIndex = 2;
  do {
    _sprintf(msgBuf," %d",*collisionCount);
    _CPPDebugLogMsg(msgBuf);
    counterIndex = counterIndex + -1;
    collisionCount = collisionCount + 1;
  } while (-1 < counterIndex);
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
        if ((loopIndex == 0) && (token == 0x29)) goto setScratchR5;
        r4Fwd = extraOut2;
        if (token != 0x10e) goto callCPPErrorToInfoLog;
        if (loopIndex < 0x40) {
          loopIndex = loopIndex + 1;
          *argAtomWrite = yylvalpp[2];
          argAtomWrite = argAtomWrite + 1;
        }
        token = (**(code **)(*(int *)(*(int *)cppRef + 0x20) + 4))
                          (*(int *)(*(int *)cppRef + 0x20),yylvalpp);
      } while (token == 0x2c);
      r4Fwd = extraOut3;
      if (token != 0x29) goto callCPPErrorToInfoLog;
setScratchR5:
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
            if (*(int *)(loopIndex2 * 4 + scratchR8) != scratchR9) goto callStoreStr;
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 < argCount);
        }
        _RewindTokenStream(*(undefined4 *)(macroSymbol + 0x20));
        _RewindTokenStream(bodyStream);
        do {
          readTokenResult2 = _ReadToken(*(undefined4 *)(macroSymbol + 0x20),yylvalpp);
          oldTokenInt = *yylvalpp;
          readTokenResult = _ReadToken(bodyStream,yylvalpp);
          if ((readTokenResult != readTokenResult2) || (*yylvalpp != oldTokenInt)) goto callStoreStr;
        } while (0 < readTokenResult);
      }
      else {
callStoreStr:
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
callCPPErrorToInfoLog:
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
      if (nextToken != 0x10e) goto setNextToken;
      definedValue = 0;
      lookUpSymbolResult = _LookUpSymbol(_macros,yylvalpp[2]);
      cppRefInt = (int *)PTR__cpp_a7b7c0a4;
      if ((lookUpSymbolResult != 0) && ((*(uint *)(lookUpSymbolResult + 0x24) & 0x40000000) == 0)) {
        definedValue = 1;
      }
      *result = definedValue;
      nextToken = (**(code **)(*(int *)(*cppRefInt + 0x20) + 4))(*(int *)(*cppRefInt + 0x20),yylvalpp);
      r4TokenPair = CONCAT44(nextToken,extraOut3);
      if (!hadOpenParen) goto loopSetErrFlag;
      goto checkUlonglong;
    }
    macroExpandResult = ((int (*)())_MacroExpand)(yylvalpp[2],yylvalpp);
    r4TokenPair = CONCAT44(0x10e,(int)macroExpandResult);
    if ((int)((ulonglong)macroExpandResult >> 0x20) == 0) goto setNextToken;
    cppState = *(int *)PTR__cpp_a7b7c0a4;
    token = (**(code **)(*(int *)(cppState + 0x20) + 4))
                        (*(int *)(cppState + 0x20),yylvalpp,aliasResult,aliasErrorFlag,aliasYylvalpp,leftoverR8,cppState);
    nextToken = extraOut4;
  }
  if (token == 0x10f) {
    *result = *yylvalpp;
    cppState = *cppRefInt;
    nextToken = *(int *)(cppState + 0x20);
loopSetNextToken:
    nextToken = (**(code **)(nextToken + 4))(nextToken,yylvalpp,aliasResult,aliasErrorFlag,aliasYylvalpp,leftoverR8,cppState);
loopSetErrFlag:
    errFlag = *errorFlag;
loopSetCppRef:
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
      if (errFlag != 0) goto loopSetCppRef;
checkUlonglong:
      if ((int)((ulonglong)r4TokenPair >> 0x20) == 0x29) {
        nextToken = *(int *)(*cppRefInt + 0x20);
        goto loopSetNextToken;
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
            goto loopSetErrFlag;
          }
          break;
        }
        unopIndex = unopIndex + -1;
      } while (-1 < unopIndex);
    }
setNextToken:
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
  undefined4 extraOutA;
  undefined4 extraOut1;
  undefined4 extraOutB;
  undefined4 extraOutC;
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
    r4Fwd = extraOutA;
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
        r4Fwd = extraOutC;
      }
      else {
        lastToken = 10;
        r4Fwd = extraOutB;
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
  undefined4 extraOutA;
  undefined4 extraOutB;
  undefined4 extraOutC;
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
    r4Fwd = extraOutA;
    tokenCapacity = 10;
    do {
      nextCapacity = tokenCapacity;
      if (tokenCapacity <= tokenCount) {
        nextCapacity = tokenCapacity << 1;
        allTokens = (undefined4 *)_realloc(allTokens,tokenCapacity << 3);
        r4Fwd = extraOutB;
      }
      if (token == 0x10b) {
loopSetSrcStr:
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
            goto setTokenCount;
          }
          if (token == 0x10f) goto loopSetSrcStr;
        }
        charStr[0] = (undefined2)((token & 0xff) << 8);
        tokenCopy = _malloc(2);
        allTokens[tokenCount] = tokenCopy;
        srcStr = charStr;
      }
setTokenCount:
      tokenCount = tokenCount + 1;
      _strcpy(tokenCopy,srcStr);
      cppRef = PTR__cpp_a7b7c0a4;
      token = (**(code **)(*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20) + 4))
                        (*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20),yylvalpp);
      r4Fwd = extraOutC;
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
  undefined4 extraOutA;
  undefined4 extraOutB;
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
  r4Fwd = extraOutA;
  if (*(int *)(*(int *)cppRef + 0x28) == 1) {
    _CPPShInfoLogMsg("#version must occur before any other statement in the program",extraOutA,
                     leftoverR5,leftoverR6,leftoverR7,leftoverR8,leftoverR9);
    r4Fwd = extraOutB;
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
  undefined4 extraOutA;
  undefined4 extraOutB;
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
      messageR4 = extraOutB;
    }
    else {
      errorMessage = "\':\' missing after extension name";
      messageR4 = extraOutA;
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
          goto storeCppState;
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
                goto setCppRef;
              }
              isIfdef = 0;
            }
            token = ((int (*)())_CPPifdef)(isIfdef,yylvalpp);
          }
          goto setCppRef;
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
setCppRef:
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
storeCppState:
  *(uint *)(cppState + 0x28) = versionFlag;
  return token;
}

/* _FreeMacro @ 0x97b87ccc (8 bytes) */
int _FreeMacro(macro)
  int macro;
{
  return _DeleteTokenStream(*(undefined4 *)(macro + 8));
}

/* _eof_scan_97b87cd4 @ 0x97b87cd4 (8 bytes) */
int _eof_scan_97b87cd4()
{
  return 0xffffffff;
}

/* _PushEofSrc @ 0x97b87ce0 (120 bytes) */
int _PushEofSrc()
{
  undefined4 eofUngetchFn;
  undefined4 eofScanGetchFn;
  undefined4 *eofSrc;
  int cppState;
  
  eofSrc = (undefined4 *)_malloc(0x18);
  eofScanGetchFn = DAT_a7b7b010;
  eofUngetchFn = DAT_a7b7b00c;
  cppState = *(int *)PTR__cpp_a7b7c0a4;
  *eofSrc = 0;
  eofSrc[5] = 0;
  eofSrc[2] = eofScanGetchFn;
  eofSrc[3] = eofUngetchFn;
  eofSrc[4] = 0;
  eofSrc[1] = eofScanGetchFn;
  *eofSrc = *(undefined4 *)(cppState + 0x20);
  *(undefined4 **)(cppState + 0x20) = eofSrc;
  return eofSrc;
}

/* _PopEofSrc @ 0x97b87d58 (64 bytes) */
int _PopEofSrc()
{
  undefined4 *inputSrc;
  undefined4 extraOut1;
  
  inputSrc = *(undefined4 **)(*(int *)PTR__cpp_a7b7c0a4 + 0x20);
  if (inputSrc[1] != DAT_a7b7b010) {
    return inputSrc;
  }
  *(undefined4 *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20) = *inputSrc;
  _free(inputSrc);
  return (undefined4 *)extraOut1;
}

/* _PrescanMacroArg @ 0x97b87d98 (276 bytes) */
int _PrescanMacroArg(argStream, yylvalpp)
  undefined4 argStream;
  int yylvalpp;
{
  int expandResult;
  undefined *cppRef;
  int token;
  int macroSymbol;
  undefined4 expandedArg;
  
  _RewindTokenStream(argStream);
  do {
    token = _ReadToken(argStream,yylvalpp);
    if ((token == 0x10e) &&
       (macroSymbol = _LookUpSymbol(_macros,*(undefined4 *)(yylvalpp + 8)), macroSymbol != 0)) break;
  } while (0 < token);
  if (0 < token) {
    expandedArg = _NewTokenStream("macro arg",0);
    ((int (*)())_PushEofSrc)();
    _ReadFromTokenStream(argStream,0,0);
    cppRef = PTR__cpp_a7b7c0a4;
    while (token = (**(code **)(*(int *)(*(int *)cppRef + 0x20) + 4))
                             (*(int *)(*(int *)cppRef + 0x20),yylvalpp), 0 < token) {
      if ((token != 0x10e) ||
         (expandResult = ((int (*)())_MacroExpand)(*(undefined4 *)(yylvalpp + 8),yylvalpp), expandResult == 0)) {
        _RecordToken(expandedArg,token,yylvalpp);
      }
    }
    ((int (*)())_PopEofSrc)();
    _DeleteTokenStream(argStream);
    argStream = expandedArg;
  }
  return argStream;
}

/* _macro_scan @ 0x97b87eac (336 bytes) */
int _macro_scan(macroInput, yylvalpp, unusedArg3, unusedArg4, unusedArg5, unusedArg6)
  undefined4 *macroInput;
  int yylvalpp;
  undefined4 unusedArg3;
  undefined4 unusedArg4;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
{
  int argStreams;
  int readTokenResult;
  bool noMoreFormals;
  undefined *cppRef;
  int formalAtom;
  int *formalCursor;
  int currentInput;
  int formalIndex;
  
  readTokenResult = _ReadToken(*(undefined4 *)(macroInput[6] + 8),yylvalpp);
  cppRef = PTR__cpp_a7b7c0a4;
  if (readTokenResult == 0x10e) {
    formalIndex = *(int *)macroInput[6] + -1;
    noMoreFormals = formalIndex < 0;
    if (!noMoreFormals) {
      formalCursor = (int *)(formalIndex * 4 + ((int *)macroInput[6])[1]);
      do {
        formalAtom = *formalCursor;
        formalCursor = formalCursor + -1;
        if (formalAtom == *(int *)(yylvalpp + 8)) {
          if (!noMoreFormals) {
            unusedArg3 = 0;
            _ReadFromTokenStream
                      (*(undefined4 *)(formalIndex * 4 + macroInput[7]),*(undefined4 *)(yylvalpp + 8),0);
            goto setCurrentInput;
          }
          break;
        }
        formalIndex = formalIndex + -1;
        noMoreFormals = formalIndex < 0;
      } while (!noMoreFormals);
    }
  }
  if (0 < readTokenResult) {
    return;
  }
  *(uint *)(macroInput[6] + 0xc) = *(uint *)(macroInput[6] + 0xc) & 0x7fffffff;
  *(undefined4 *)(*(int *)cppRef + 0x20) = *macroInput;
  argStreams = macroInput[7];
  if (argStreams != 0) {
    formalIndex = *(int *)macroInput[6] + -1;
    if (-1 < formalIndex) {
      while( true ) {
        _DeleteTokenStream(*(undefined4 *)(formalIndex * 4 + argStreams));
        formalIndex = formalIndex + -1;
        if (formalIndex < 0) break;
        argStreams = macroInput[7];
      }
      argStreams = macroInput[7];
    }
    _free(argStreams);
  }
  _free(macroInput);
setCurrentInput:
  currentInput = *(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20);
                    
                    
  (**(code **)(currentInput + 4))(currentInput,yylvalpp,unusedArg3,unusedArg4,unusedArg5,unusedArg6,*(int *)PTR__cpp_a7b7c0a4);
  return;
}

/* _MacroExpand @ 0x97b87ffc (1024 bytes) */
int _MacroExpand(atom, yylvalpp)
  int atom;
  undefined4 *yylvalpp;
{
  int argByteOffset;
  int parenDepth;
  int nextArgStreamIndex;
  int argStreamIndex;
  int token;
  int cppState;
  undefined4 scanFunc;
  bool argHasTokens;
  undefined4 prescanMacroArgResult;
  undefined4 atoiResult;
  int newTokenStreamResult;
  undefined4 stringOfAtom;
  int argIndex;
  undefined4 strfromTStr;
  undefined4 argStreams;
  bool gotToken;
  bool isCloseParen;
  bool prevWasCloseParen;
  undefined *cppRef;
  undefined *cppRefCopy;
  int lookUpSymbolResult;
  undefined4 expansionNumber;
  undefined4 *macroInput;
  int skipToken;
  char *errorMessage;
  undefined4 extraOut1;
  undefined4 extraOut2;
  undefined4 *scratchR5;
  undefined4 leftoverR6;
  undefined4 leftoverR7;
  undefined4 leftoverR8;
  int *scratchPtr;
  int skipDepth;
  int argToken;
  
  lookUpSymbolResult = _LookUpSymbol(_macros,atom);
  if (atom == ___LINE__Atom) {
    expansionNumber = _GetLineNumber();
  }
  else {
    if (atom != ___FILE__Atom) {
      if (atom != ___VERSION__Atom) {
        if ((lookUpSymbolResult == 0) || ((*(uint *)(lookUpSymbolResult + 0x24) & 0x40000000) != 0)) {
          return 0;
        }
        if ((int)*(uint *)(lookUpSymbolResult + 0x24) < 0) {
          return 0;
        }
        macroInput = (undefined4 *)_malloc(0x20);
        scanFunc = DAT_a7b7b008;
        cppState = *(int *)PTR__cpp_a7b7c0a4;
        macroInput[4] = 0;
        macroInput[5] = 0;
        macroInput[6] = 0;
        macroInput[7] = 0;
        *macroInput = 0;
        macroInput[2] = 0;
        macroInput[3] = 0;
        macroInput[1] = scanFunc;
        macroInput[5] = *(undefined4 *)(*(int *)(cppState + 0x20) + 0x14);
        scratchPtr = *(int **)(*(int *)(cppState + 0x20) + 0x10);
        macroInput[6] = lookUpSymbolResult + 0x18;
        macroInput[4] = scratchPtr;
        if (*(int *)(lookUpSymbolResult + 0x1c) != 0) {
          token = (**(code **)(*(int *)(cppState + 0x20) + 4))
                             (*(int *)(cppState + 0x20),yylvalpp,scratchR5,leftoverR6,leftoverR7,leftoverR8,scratchPtr,cppState);
          if (token != 0x28) {
            _UngetToken(token,yylvalpp);
            yylvalpp[2] = atom;
            return 0;
          }
          argStreams = _malloc(*(int *)macroInput[6] << 2);
          macroInput[7] = argStreams;
          argStreamIndex = 0;
          if (0 < *(int *)macroInput[6]) {
            do {
              newTokenStreamResult = _NewTokenStream("macro arg",0);
              scratchPtr = (int *)macroInput[7];
              nextArgStreamIndex = argStreamIndex + 1;
              scratchPtr[argStreamIndex] = newTokenStreamResult;
              argStreamIndex = nextArgStreamIndex;
            } while (nextArgStreamIndex < *(int *)macroInput[6]);
          }
          cppRef = PTR__cpp_a7b7c0a4;
          argIndex = 0;
          argHasTokens = false;
loopSetParenDepth:
          parenDepth = 0;
          do {
            argToken = (**(code **)(*(int *)(*(int *)cppRef + 0x20) + 4))
                               (*(int *)(*(int *)cppRef + 0x20),yylvalpp);
            cppRefCopy = PTR__cpp_a7b7c0a4;
            gotToken = 0 < argToken;
            if (!gotToken) goto callStoreStr;
            scratchPtr = (int *)macroInput[6];
            isCloseParen = argToken == 0x29;
            if ((*scratchPtr == 0) && (!isCloseParen)) goto setArgIndex;
            if (parenDepth == 0) {
              if (argToken == 0x2c) goto setArgIndex;
              if (isCloseParen) {
                if ((*scratchPtr != 1) || (argHasTokens)) {
                  argIndex = argIndex + 1;
                }
                goto checkArgIndex;
              }
            }
            if (argToken == 0x28) {
              parenDepth = parenDepth + 1;
            }
            if (isCloseParen) {
              parenDepth = parenDepth + -1;
            }
            argHasTokens = true;
            scratchR5 = yylvalpp;
            _RecordToken(*(undefined4 *)(argIndex * 4 + macroInput[7]),argToken,yylvalpp);
          } while( true );
        }
        goto setCppRef;
      }
      yylvalpp[3] = 0x31303000;
      atoiResult = _atoi(yylvalpp + 3);
      *yylvalpp = atoiResult;
      goto callUngetToken;
    }
    expansionNumber = _GetStringNumber();
  }
  *yylvalpp = expansionNumber;
  _sprintf((char *)(yylvalpp + 3),"%d",expansionNumber);
callUngetToken:
  _UngetToken(0x10f,yylvalpp);
  return 1;
setArgIndex:
  argIndex = argIndex + 1;
  if (*scratchPtr <= argIndex) goto checkArgIndex;
  goto loopSetParenDepth;
checkArgIndex:
  if (argIndex < *scratchPtr) {
    errorMessage = "Too few args in Macro ";
loopCallStoreStr:
    _StoreStr(errorMessage);
    stringOfAtom = ((int (*)())_GetStringOfAtom)(*(undefined4 *)PTR__atable_a7b7c0ac,atom);
    _StoreStr(stringOfAtom);
    strfromTStr = _GetStrfromTStr();
    _CPPShInfoLogMsg(strfromTStr,extraOut2,scratchR5,leftoverR6,leftoverR7,leftoverR8,scratchPtr);
    _ResetTString();
    scratchPtr = (int *)macroInput[6];
  }
  else if (!isCloseParen) {
    skipDepth = 0;
    if (-1 < argToken) {
      prevWasCloseParen = false;
      do {
        if (prevWasCloseParen) {
          skipDepth = skipDepth + -1;
        }
        skipToken = (**(code **)(*(int *)(*(int *)cppRefCopy + 0x20) + 4))
                          (*(int *)(*(int *)cppRefCopy + 0x20),yylvalpp);
        if (skipToken == 0x28) {
          skipDepth = skipDepth + 1;
        }
        gotToken = 0 < skipToken;
      } while ((-1 < skipToken) && ((prevWasCloseParen = skipToken == 0x29, 0 < skipDepth || (!prevWasCloseParen))));
    }
    if (!gotToken) {
callStoreStr:
      _StoreStr("EOF in Macro ");
      stringOfAtom = ((int (*)())_GetStringOfAtom)(*(undefined4 *)PTR__atable_a7b7c0ac,atom);
      _StoreStr(stringOfAtom);
      strfromTStr = _GetStrfromTStr();
      _CPPShInfoLogMsg(strfromTStr,extraOut1,scratchR5,leftoverR6,leftoverR7,leftoverR8,scratchPtr);
      _ResetTString();
      return 1;
    }
    errorMessage = "Too many args in Macro ";
    goto loopCallStoreStr;
  }
  argIndex = 0;
  if (0 < *scratchPtr) {
    do {
      argByteOffset = argIndex * 4;
      argIndex = argIndex + 1;
      prescanMacroArgResult = ((int (*)())_PrescanMacroArg)(*(undefined4 *)(argByteOffset + macroInput[7]),yylvalpp);
      *(undefined4 *)(argByteOffset + macroInput[7]) = prescanMacroArgResult;
    } while (argIndex < *(int *)macroInput[6]);
  }
setCppRef:
  cppRef = PTR__cpp_a7b7c0a4;
  *macroInput = *(undefined4 *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20);
  *(uint *)(lookUpSymbolResult + 0x24) = *(uint *)(lookUpSymbolResult + 0x24) | 0x80000000;
  _RewindTokenStream(*(undefined4 *)(lookUpSymbolResult + 0x20));
  *(undefined4 **)(*(int *)cppRef + 0x20) = macroInput;
  return 1;
}

/* _ChkCorrectElseNesting @ 0x97b883fc (72 bytes) */
int _ChkCorrectElseNesting()
{
  int elseSlot;
  
  elseSlot = *(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x138) * 4 + *(int *)PTR__cpp_a7b7c0a4;
  if (*(int *)(elseSlot + 0x38) != 0) {
    return 0;
  }
  *(undefined4 *)(elseSlot + 0x38) = 1;
  return 1;
}

/* _InitCPPStruct @ 0x97b88444 (144 bytes) */
int _InitCPPStruct()
{
  undefined4 success;
  int *cppStruct;
  undefined1 *clearCursor;
  int clearCount;
  
  cppStruct = (int *)_malloc(0x158);
  success = 0;
  _cpp = cppStruct;
  if (cppStruct != (int *)0x0) {
    _refCount = _refCount + 1;
    *cppStruct = (int)(cppStruct + 5);
    clearCount = 0x10;
    clearCursor = (undefined1 *)((int)cppStruct + 0x13);
    do {
      *clearCursor = 0;
      clearCursor = clearCursor + -1;
      clearCount = clearCount + -1;
    } while (clearCount != 0);
    ((int (*)())_ResetPreprocessor)();
    success = 1;
  }
  return success;
}

/* _ResetPreprocessor @ 0x97b884d4 (196 bytes) */
int _ResetPreprocessor()
{
  int elseIndex;
  
  *(undefined2 *)(_cpp + 0x14) = 0;
  *(undefined2 *)(_cpp + 0x16) = 0;
  *(undefined4 *)(_cpp + 0x2c) = 0;
  *(undefined4 *)(_cpp + 0x140) = 0;
  *(undefined4 *)(_cpp + 0x34) = 0;
  *(undefined4 *)(_cpp + 0x138) = 0;
  elseIndex = *(int *)(_cpp + 0x138);
  while (elseIndex < 0x40) {
    *(undefined4 *)(*(int *)(_cpp + 0x138) * 4 + _cpp + 0x38) = 0;
    *(int *)(_cpp + 0x138) = *(int *)(_cpp + 0x138) + 1;
    elseIndex = *(int *)(_cpp + 0x138);
  }
  *(undefined4 *)(_cpp + 0x138) = 0;
  *(uint *)(_cpp + 0x154) = *(uint *)(_cpp + 0x154) & 0x7fffffff;
  return 1;
}

/* _InitPreprocessor @ 0x97b88598 (136 bytes) */
int _InitPreprocessor()
{
  int initScannerResult;
  undefined *atableRef;
  int initAtomTableResult;
  uint result;
  
  ((int (*)())_FreeCPPStruct)();
  ((int (*)())_InitCPPStruct)();
  *(undefined4 *)(_cpp + 0xc) = 1;
  atableRef = PTR__atable_a7b7c0ac;
  *(char **)(_cpp + 4) = "generic";
  initAtomTableResult = ((int (*)())_InitAtomTable)(*(undefined4 *)atableRef,0);
  result = 1;
  if (initAtomTableResult != 0) {
    initScannerResult = ((int (*)())_InitScanner)(_cpp);
    result = (uint)(initScannerResult == 0);
  }
  return result;
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
int _mem_CreatePool(growthSize, alignment)
  uint growthSize;
  uint alignment;
{
  undefined4 *pool;
  undefined4 *firstPage;
  uint alignMask;
  
  if (alignment == 0) {
    alignment = 8;
  }
  if (growthSize == 0) {
    growthSize = 0x10000;
  }
  alignMask = alignment - 1;
  pool = (undefined4 *)0x0;
  if (((alignment & alignMask) == 0) && (0x17 < growthSize)) {
    if ((growthSize & alignMask) == 0) {
      firstPage = (undefined4 *)_malloc(growthSize);
      pool = (undefined4 *)0x0;
      if (firstPage != (undefined4 *)0x0) {
        firstPage[2] = (int)firstPage + growthSize;
        firstPage[5] = 0;
        firstPage[1] = (int)firstPage + alignment + 0x17 & ~alignMask;
        *firstPage = 0;
        firstPage[3] = growthSize;
        firstPage[4] = alignMask;
        pool = firstPage;
      }
    }
  }
  return pool;
}

/* _mem_FreePool @ 0x97b88768 (108 bytes) */
int _mem_FreePool(pool)
  int *pool;
{
  int *cleanup;
  int nextPage;
  
  for (cleanup = (int *)pool[5]; cleanup != (int *)0x0; cleanup = (int *)*cleanup) {
    (*(code *)cleanup[1])(cleanup[2]);
  }
  while (pool != (int *)0x0) {
    nextPage = *pool;
    _free(pool);
    pool = (int *)nextPage;
  }
  return;
}

/* _mem_Alloc @ 0x97b887d4 (224 bytes) */
int _mem_Alloc(pool, byteCount)
  undefined4 *pool;
  int byteCount;
{
  uint alignedSize;
  uint allocPtr;
  undefined4 *newPage;
  uint newCurrent;
  uint alignMask;
  
  alignMask = pool[4];
  allocPtr = pool[1];
  alignedSize = byteCount + alignMask & ~alignMask;
  if (alignedSize == 0) {
    alignedSize = alignMask;
  }
  newCurrent = allocPtr + alignedSize;
  pool[1] = newCurrent;
  if (((uint)pool[2] < newCurrent) || (newCurrent < allocPtr)) {
    pool[1] = allocPtr;
    alignedSize = alignedSize + alignMask + 4 & ~alignMask;
    if (alignedSize < (uint)pool[3]) {
      newPage = (undefined4 *)_malloc(pool[3]);
      if (newPage == (undefined4 *)0x0) {
        return 0;
      }
      pool[1] = (int)newPage + alignedSize;
      pool[2] = (int)newPage + pool[3];
    }
    else {
      newPage = (undefined4 *)_malloc(alignedSize);
      if (newPage == (undefined4 *)0x0) {
        return 0;
      }
    }
    *newPage = *pool;
    *pool = newPage;
    allocPtr = (int)newPage + pool[4] + 4 & ~pool[4];
  }
  return allocPtr;
}

/* _mem_AddCleanup @ 0x97b888b4 (112 bytes) */
int _mem_AddCleanup(pool, cleanupFn, cleanupArg)
  int pool;
  undefined4 cleanupFn;
  undefined4 cleanupArg;
{
  undefined4 oldHead;
  undefined4 result;
  undefined4 *mem_AllocResult;
  
  *(uint *)(pool + 4) = *(int *)(pool + 4) + 3U & 0xfffffffc;
  mem_AllocResult = (undefined4 *)((int (*)())_mem_Alloc)(pool,0xc);
  result = 0xffffffff;
  if (mem_AllocResult != (undefined4 *)0x0) {
    oldHead = *(undefined4 *)(pool + 0x14);
    mem_AllocResult[1] = cleanupFn;
    *mem_AllocResult = oldHead;
    result = 0;
    mem_AllocResult[2] = cleanupArg;
    *(undefined4 **)(pool + 0x14) = mem_AllocResult;
  }
  return result;
}

/* _eof_scan_97b88924 @ 0x97b88924 (8 bytes) */
int _eof_scan_97b88924()
{
  return 0xffffffff;
}

/* _InitScanner @ 0x97b88930 (116 bytes) */
int _InitScanner(cpp)
  int cpp;
{
  int initCPPResult;
  
  initCPPResult = ((int (*)())_InitCPP)();
  if (initCPPResult != 0) {
    *(int *)(cpp + 0x18) = cpp + 0x30;
    *(undefined4 *)(cpp + 0x28) = 0;
    *(undefined **)(cpp + 0x20) = &_eof_inputsrc;
    *(undefined4 *)(cpp + 0x24) = 10;
    *(undefined4 *)(cpp + 0x1c) = 0;
    *(undefined2 *)(cpp + 0x30) = 0;
    *(undefined2 *)(cpp + 0x32) = 0;
  }
  return initCPPResult != 0;
}

/* _str_getch @ 0x97b889a8 (228 bytes) */
int _str_getch(stringSrc)
  undefined4 *stringSrc;
{
  char ch;
  undefined4 prevInput;
  int stringIndex;
  char *cursor;
  int cppState;
  
  cppState = *(int *)PTR__cpp_a7b7c0a4;
  while( true ) {
    cursor = (char *)stringSrc[6];
    if (*cursor != '\0') {
      if (*cursor == '\n') {
        stringSrc[5] = stringSrc[5] + 1;
        _IncLineNumber();
        cursor = (char *)stringSrc[6];
      }
      ch = *cursor;
      stringSrc[6] = cursor + 1;
      return (int)ch;
    }
    stringIndex = *(int *)(cppState + 0x144) + 1;
    *(int *)(cppState + 0x144) = stringIndex;
    if (*(int *)(cppState + 0x14c) <= stringIndex) break;
    _free(stringSrc);
    _SetStringNumber(*(undefined4 *)(cppState + 0x144));
    _SetLineNumber(1);
    ((int (*)())_ScanFromString)(*(undefined4 *)(*(int *)(cppState + 0x144) * 4 + *(int *)(cppState + 0x150)));
    stringSrc = *(undefined4 **)(cppState + 0x20);
  }
  prevInput = *stringSrc;
  *(undefined4 *)(cppState + 0x144) = 0;
  *(undefined4 *)(cppState + 0x20) = prevInput;
  _free(stringSrc);
  return -1;
}

/* _str_ungetch_body_97b88a90 @ 0x97b88a90 (100 bytes) */
int _str_ungetch_body_97b88a90(stringSrc, ch)
  int stringSrc;
  int ch;
{
  undefined1 *cursor = *(undefined1 **)(stringSrc + 0x18);   /* set by the entry _str_ungetch: lwz r2,0x18(r3) */
  
  if ((char)cursor[-1] == ch) {
    *(undefined1 **)(stringSrc + 0x18) = cursor + -1;
  }
  else {
    *cursor = 0;
    *(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x144) = *(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x144) + -1;
  }
  if (ch != 10) {
    return;
  }
  *(int *)(stringSrc + 0x14) = *(int *)(stringSrc + 0x14) + -1;
  return _DecLineNumber();
}

/* _ScanFromString @ 0x97b88af4 (148 bytes) */
int _ScanFromString(string)
  undefined4 string;
{
  undefined4 ungetchFn;
  undefined4 scanFn;
  undefined4 getchFn;
  undefined4 *stringSrc;
  int cppState;
  
  stringSrc = (undefined4 *)_malloc(0x1c);
  scanFn = DAT_a7b7b038;
  getchFn = DAT_a7b7b034;
  cppState = *(int *)PTR__cpp_a7b7c0a4;
  stringSrc[4] = 0;
  stringSrc[1] = scanFn;
  ungetchFn = DAT_a7b7b030;
  *stringSrc = 0;
  stringSrc[6] = string;
  stringSrc[5] = 1;
  stringSrc[2] = getchFn;
  stringSrc[3] = ungetchFn;
  *stringSrc = *(undefined4 *)(cppState + 0x20);
  *(undefined4 **)(cppState + 0x20) = stringSrc;
  return 1;
}

/* _lBuildFloatValue @ 0x97b88b88 (272 bytes) */
double _lBuildFloatValue(int digits,int digitCount,uint exponent10)
{
  float resultFloat;
  char *digitPtr;
  uint expRemaining;
  undefined4 leftoverR6;
  undefined4 leftoverR7;
  undefined4 leftoverR8;
  int digitIndex;
  int digitsLeft;
  double tenPower;
  double mantissa;
  double scale;
  
  digitIndex = 0;
  digitsLeft = digitCount;
  mantissa = DOUBLE_97c30a48;
  if (0 < digitCount) {
    do {
      digitPtr = (char *)(digits + digitIndex);
      digitIndex = digitIndex + 1;
      mantissa = mantissa * DOUBLE_97c30a50 +
              ((double)CONCAT44(0x43300000,(int)*digitPtr - 0x30U ^ 0x80000000) - DOUBLE_97c30a58);
      digitsLeft = digitsLeft + -1;
    } while (digitsLeft != 0);
  }
  if (exponent10 != 0) {
    tenPower = DOUBLE_97c30a50;
    scale = DOUBLE_97c30a60;
    for (expRemaining = ((int)exponent10 >> 0x1f ^ exponent10) - ((int)exponent10 >> 0x1f); expRemaining != 0;
        expRemaining = (int)expRemaining >> 1) {
      if ((expRemaining & 1) != 0) {
        scale = scale * tenPower;
      }
      tenPower = tenPower * tenPower;
    }
    if ((int)exponent10 < 0) {
      mantissa = mantissa / scale;
    }
    else {
      mantissa = mantissa * scale;
    }
  }
  resultFloat = (float)mantissa;
  if ((((uint)GH_F2U(resultFloat) & 0x7f800000) == 0x7f800000) && (((uint)GH_F2U(resultFloat) & 0x7fffff) == 0)) {
    _CPPErrorToInfoLog(" ERROR___FP_CONST_OVERFLOW",digitCount,0,leftoverR6,leftoverR7,leftoverR8,digitIndex);
  }
  return (double)resultFloat;
}

