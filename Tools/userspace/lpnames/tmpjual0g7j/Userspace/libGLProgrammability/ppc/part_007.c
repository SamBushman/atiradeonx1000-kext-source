#include "decls.h"

/* yy_delete_buffer @ 0x97badae0 (124 bytes) */
int yy_delete_buffer(yy_buffer_state)
  unsigned char * yy_buffer_state;
{
  if (yy_buffer_state != (unsigned char *)0x0) {
    if (yy_buffer_state == _yy_current_buffer) {
      _yy_current_buffer = (unsigned char *)0x0;
    }
    if (*(int *)(yy_buffer_state + 0x14) != 0) {
      ((int (*)())yy_flex_free)(*(void **)(yy_buffer_state + 4));
    }
    ((int (*)())yy_flex_free)(yy_buffer_state);
    return;
  }
  return;
}

/* yy_init_buffer @ 0x97badb5c (68 bytes) */
int yy_init_buffer(yy_buffer_state, file)
  unsigned char * yy_buffer_state;
  unsigned char * file;
{
  ((int (*)())yy_flush_buffer)(yy_buffer_state);
  *(undefined4 *)(yy_buffer_state + 0x18) = 0;
  *(undefined4 *)(yy_buffer_state + 0x20) = 1;
  *(unsigned char **)yy_buffer_state = file;
  return;
}

/* yy_flush_buffer @ 0x97badba0 (88 bytes) */
int yy_flush_buffer(yy_buffer_state)
  unsigned char * yy_buffer_state;
{
  if (yy_buffer_state == (unsigned char *)0x0) {
    return;
  }
  *(undefined4 *)(yy_buffer_state + 0x10) = 0;
  **(undefined1 **)(yy_buffer_state + 4) = 0;
  *(undefined1 *)(*(int *)(yy_buffer_state + 4) + 1) = 0;
  *(undefined4 *)(yy_buffer_state + 0x1c) = 1;
  *(undefined4 *)(yy_buffer_state + 8) = *(undefined4 *)(yy_buffer_state + 4);
  *(undefined4 *)(yy_buffer_state + 0x24) = 0;
  if (yy_buffer_state != _yy_current_buffer) {
    return;
  }
  return yy_load_buffer_state();
}

/* yy_scan_buffer @ 0x97badbf8 (192 bytes) */
int yy_scan_buffer(base, bufSize)
  char *base;
  uint bufSize;
{
  unsigned char * buffer;
  
  if (((bufSize < 2) || (base[bufSize - 2] != '\0')) || (base[bufSize - 1] != '\0')) {
    buffer = (unsigned char *)0x0;
  }
  else {
    buffer = (unsigned char *)((int (*)())yy_flex_alloc)(0x28);
    if (buffer == (unsigned char *)0x0) {
      ((int (*)())yy_fatal_error)("out of dynamic memory in yy_scan_buffer()");
    }
    *(char **)(buffer + 8) = base;
    *(uint *)(buffer + 0x10) = bufSize - 2;
    *(undefined4 *)(buffer + 0x1c) = 1;
    *(undefined4 *)(buffer + 0x24) = 0;
    *(uint *)(buffer + 0xc) = bufSize - 2;
    *(char **)(buffer + 4) = base;
    *(undefined4 *)(buffer + 0x14) = 0;
    *(undefined4 *)buffer = 0;
    *(undefined4 *)(buffer + 0x18) = 0;
    *(undefined4 *)(buffer + 0x20) = 0;
    yy_switch_to_buffer(buffer);
  }
  return buffer;
}

/* yy_scan_string @ 0x97badcb8 (44 bytes) */
int yy_scan_string(str)
  char *str;
{
  char ch;
  int copyIndex;
  
  copyIndex = 0;
  ch = *str;
  while (ch != '\0') {
    copyIndex = copyIndex + 1;
    ch = str[copyIndex];
  }
  return ((int (*)())yy_scan_bytes)(str,copyIndex);
}

/* yy_scan_bytes @ 0x97badce4 (176 bytes) */
int yy_scan_bytes(bytes, len)
  char *bytes;
  int len;
{
  int yy_scan_bufferResult;
  int copyIdx;
  char *yy_flex_allocResult;
  int remaining;
  
  yy_flex_allocResult = (char *)((int (*)())yy_flex_alloc)(len + 2U);
  if (yy_flex_allocResult == (char *)0x0) {
    ((int (*)())yy_fatal_error)("out of dynamic memory in yy_scan_bytes()");
  }
  copyIdx = 0;
  remaining = len;
  if (0 < len) {
    do {
      yy_flex_allocResult[copyIdx] = bytes[copyIdx];
      copyIdx = copyIdx + 1;
      remaining = remaining + -1;
    } while (remaining != 0);
  }
  yy_flex_allocResult[len + 1] = '\0';
  yy_flex_allocResult[len] = '\0';
  yy_scan_bufferResult = ((int (*)())yy_scan_buffer)(yy_flex_allocResult,len + 2U);
  if (yy_scan_bufferResult == 0) {
    ((int (*)())yy_fatal_error)("bad buffer in yy_scan_bytes()");
  }
  *(undefined4 *)(yy_scan_bufferResult + 0x14) = 1;
  return yy_scan_bufferResult;
}

/* yy_fatal_error @ 0x97badd94 (60 bytes) */
int yy_fatal_error(str)
  char *str;
{
  _fprintf((FILE *)(PTR_DAT_a7b7c0bc + 0xb0),"%s\n",str);
                    
  _exit(2);
}

/* yy_flex_alloc @ 0x97baddd0 (4 bytes) */
int yy_flex_alloc(bytes)
  uint bytes;
{
                    
                    
  return _malloc(bytes);
}

/* yy_flex_realloc @ 0x97baddd4 (4 bytes) */
int yy_flex_realloc(ptr, newSize)
  void *ptr;
  uint newSize;
{
                    
                    
  return _realloc(ptr,newSize);
}

/* yy_flex_free @ 0x97baddd8 (4 bytes) */
int yy_flex_free(ptr)
  void *ptr;
{
                    
                    
  return _free(ptr);
}

/* PaParseStrings @ 0x97badddc (452 bytes) */
int PaParseStrings(shaderStrings, stringLengths, numStrings, freeSymbolsFlag, parseContext)
  char **shaderStrings;
  int *stringLengths;
  int numStrings;
  int freeSymbolsFlag;
  unsigned char * parseContext;
{
  undefined *cppPtr;
  undefined *cppPtr2;
  int numStringsCopy;
  char **stringPtr;
  undefined4 result;
  undefined4 *node;
  undefined4 r4Out0;
  int freeSymbolsFlagCopy;
  unsigned char * parseContextCopy;
  undefined4 staleR8;
  int stringIdx;
  undefined4 staleR10;
  int defaultLength [4];
  
  numStringsCopy = numStrings;
  freeSymbolsFlagCopy = freeSymbolsFlag;
  parseContextCopy = parseContext;
  _ScanFromString(*shaderStrings);
  result = 1;
  *(unsigned char **)(*(int *)PTR__cpp_a7b7c0a4 + 0x2c) = parseContext;
  if (numStrings != 0) {
    stringIdx = 0;
    stringPtr = shaderStrings;
    if (0 < numStrings) {
      do {
        if (*stringPtr == (char *)0x0) {
          TParseContext__error
                    ((int)parseContext,(char *)0x0,"Null shader source string","","",staleR8,stringIdx,staleR10);
          TParseContext__recover(parseContext);
          goto LAB_97badf80;
        }
        stringIdx = stringIdx + 1;
        stringPtr = stringPtr + 1;
      } while (stringIdx < numStrings);
    }
    if (stringLengths == (int *)0x0) {
      stringLengths = defaultLength;
      defaultLength[0] = _strlen(*shaderStrings);
    }
    yyrestart((unsigned char *)0x0);
    cppPtr = PTR__cpp_a7b7c0a4;
    result = 0;
    *(undefined4 *)(parseContext + 0x60) = 0;
    *(undefined4 *)(*(int *)cppPtr + 0x144) = 0;
    *(char ***)(*(int *)cppPtr + 0x150) = shaderStrings;
    *(int *)(*(int *)cppPtr + 0x14c) = numStrings;
    *(int **)(*(int *)cppPtr + 0x148) = stringLengths;
    *(undefined4 *)(*(int *)cppPtr + 0x28) = 0;
    _yylineno = 1;
    if ((-1 < **(int **)(*(int *)cppPtr + 0x148)) &&
       (((yyparse(parseContext,r4Out0,numStringsCopy,freeSymbolsFlagCopy,parseContextCopy,staleR8,*(int **)(*(int *)cppPtr + 0x148),
                  staleR10), cppPtr2 = PTR__cpp_a7b7c0a4, *(int *)(*(int *)cppPtr + 0x140) == 1 ||
         (*(int *)(parseContext + 0x14) != 0)) || (result = 0, 0 < *(int *)(parseContext + 0x18))))) {
      if (freeSymbolsFlag != 0) {
        numStringsCopy = *(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20);
        while (numStringsCopy != 0) {
          numStringsCopy = *(int *)cppPtr2;
          node = *(undefined4 **)(numStringsCopy + 0x20);
          *(undefined4 *)(numStringsCopy + 0x20) = *node;
          _free(node);
          numStringsCopy = *(int *)(*(int *)cppPtr2 + 0x20);
        }
      }
LAB_97badf80:
      result = 1;
    }
  }
  return result;
}

/* yyerror @ 0x97badfa0 (184 bytes) */
int yyerror(msg, staleR4, staleR5, staleR6, staleR7, staleR8, staleR9, staleR10)
  char *msg;
  undefined4 staleR4;
  undefined4 staleR5;
  undefined4 staleR6;
  undefined4 staleR7;
  undefined4 staleR8;
  undefined4 staleR9;
  undefined4 staleR10;
{
  undefined *cppPtr;
  int parseContext;
  char *tokenText;
  
  cppPtr = PTR__cpp_a7b7c0a4;
  parseContext = *(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x2c);
  tokenText = _yytext;
  if (*(int *)(parseContext + 0x60) != 0) {
    if (-1 < *(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x154)) {
      return;
    }
    tokenText = "pre-mature EOF";
  }
  TParseContext__error(parseContext,_yylineno,"syntax error",tokenText,msg,"",staleR9,staleR10);
  TParseContext__recover(*(unsigned char **)(*(int *)cppPtr + 0x2c));
  return;
}

/* PaReservedWord @ 0x97bae058 (108 bytes) */
int PaReservedWord()
{
  undefined *cppPtr;
  undefined4 staleR9;
  undefined4 staleR10;
  
  cppPtr = PTR__cpp_a7b7c0a4;
  TParseContext__error
            (*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x2c),_yylineno,"Reserved word.",_yytext,"","",
             staleR9,staleR10);
  return TParseContext__recover(*(unsigned char **)(*(int *)cppPtr + 0x2c));
}

/* PaIdentOrType @ 0x97bae0c4 (228 bytes) */
int PaIdentOrType(text, parseContext, symbol)
  unsigned char * text;
  unsigned char * parseContext;
  unsigned char ** symbol;
{
  unsigned char * foundSymbol;
  undefined4 token;
  int symbolLevelOrFlag;
  int *symbolTable;
  int levelIdx;
  int findIter [5];
  
  symbolTable = *(int **)(parseContext + 4);
  symbolLevelOrFlag = *symbolTable;
  levelIdx = (symbolTable[1] - symbolLevelOrFlag >> 2) + -1;
  while( true ) {
    symbolLevelOrFlag = *(int *)(symbolLevelOrFlag + levelIdx * 4);
    std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______find((unsigned char *)findIter,symbolLevelOrFlag,text);
    foundSymbol = (unsigned char *)0x0;
    if (findIter[0] != *(int *)(symbolLevelOrFlag + 4)) {
      foundSymbol = *(unsigned char **)(findIter[0] + 0x18);
    }
    levelIdx = levelIdx + -1;
    if ((foundSymbol != (unsigned char *)0x0) || (levelIdx < 0)) break;
    symbolLevelOrFlag = *symbolTable;
  }
  *symbol = foundSymbol;
  if ((((*(int *)(parseContext + 0x1c) != 0) || (foundSymbol == (unsigned char *)0x0)) ||
      (symbolLevelOrFlag = (**(code **)(*(int *)foundSymbol + 0x10))(foundSymbol), symbolLevelOrFlag == 0)) ||
     (*(int *)(*symbol + 0x34) == 0)) {
    token = 0x12a;
  }
  else {
    token = 299;
    *(undefined4 *)(parseContext + 0x1c) = 1;
  }
  return token;
}

/* PaParseComment @ 0x97bae1a8 (228 bytes) */
int PaParseComment(lineCounter, parseContext)
  int *lineCounter;
  unsigned char * parseContext;
{
  int yyinputResult;
  undefined4 staleR9;
  undefined4 staleR10;
  int starState;
  
  starState = 0;
  do {
    while( true ) {
      yyinputResult = yyinput();
      if (yyinputResult == 10) {
        *lineCounter = *lineCounter + 1;
      }
      if (yyinputResult != 0x2a) break;
      starState = 1;
    }
    if (yyinputResult < 0x2b) {
      if (yyinputResult == -1) {
        TParseContext__error
                  ((int)parseContext,_yylineno,"End of shader found before end of comment.","","","",
                   staleR9,staleR10);
        TParseContext__recover(*(unsigned char **)(*(int *)PTR__cpp_a7b7c0a4 + 0x2c));
        return 0;
      }
LAB_97bae268:
      starState = 0;
    }
    else {
      if (yyinputResult != 0x2f) goto LAB_97bae268;
      if (starState == 1) {
        return 1;
      }
    }
    if (starState == 2) {
      return 1;
    }
  } while( true );
}

/* _CPPDebugLogMsg @ 0x97bae28c (92 bytes) */
int _CPPDebugLogMsg(str)
  char *str;
{
  void *this;
  
  this = (void *)(*(int *)(*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x2c) + 8) + 8);
  __ZN13TInfoSinkBase6appendEPKc(this,str);
  return __ZN13TInfoSinkBase6appendEPKc(this,"\n");
}

/* _CPPWarningToInfoLog @ 0x97bae2e8 (92 bytes) */
int _CPPWarningToInfoLog(str)
  char *str;
{
  int oldRefCount;
  int atomicStore;
  uint lineNo;
  int *refCountPtr;
  int stringNo;
  uint lineInString;
  void *this;
  char reservation;
  byte cr0Flags;
  char *lineStr [4];
  char lineBuf [64];
  unsigned char lineStrAlloc [16];
  
  lineNo = _yylineno;
  this = *(void **)(*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x2c) + 8);
                    
  __ZN13TInfoSinkBase6appendEPKc(this,"WARNING: ");
  lineInString = lineNo & 0xffff;
  cr0Flags = (lineInString == 0) << 1;
  stringNo = (int)lineNo >> 0x10;
  if (lineInString == 0) {
    _sprintf(lineBuf,"%d:? ",stringNo);
  }
  else {
    _sprintf(lineBuf,"%d:%d",stringNo,lineInString);
  }
  __ZNSsC1EPKcRKSaIcE(lineStr,lineBuf,lineStrAlloc);
  lineStr[0][*(int *)(lineStr[0] + -0xc)] = *PTR__S_terminal_a7b7c0b8;
  __ZN13TInfoSinkBase6appendEPKc(this,lineStr[0]);
  refCountPtr = (int *)(lineStr[0] + -4);
  do {
    oldRefCount = *refCountPtr;
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
      *refCountPtr = atomicStore;
      cr0Flags = 2;
    }
  } while (!(bool)(cr0Flags >> 1 & 1));
  if (oldRefCount < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(lineStr[0] + -0xc));
  }
  __ZN13TInfoSinkBase6appendEPKc(this,": ");
  __ZN13TInfoSinkBase6appendEPKc(this,str);
  __ZN13TInfoSinkBase6appendEPKc(this,"\n");
  return;
}

/* _CPPShInfoLogMsg @ 0x97bae468 (100 bytes) */
int _CPPShInfoLogMsg(msg, staleR4, staleR5, staleR6, staleR7, staleR8, staleR9)
  undefined4 msg;
  undefined4 staleR4;
  undefined4 staleR5;
  undefined4 staleR6;
  undefined4 staleR7;
  undefined4 staleR8;
  undefined4 staleR9;
{
  undefined *cppPtr;
  undefined4 staleR10;
  
  cppPtr = PTR__cpp_a7b7c0a4;
  TParseContext__error
            (*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x2c),_yylineno,"","",msg,"",staleR9,staleR10);
  return TParseContext__recover(*(unsigned char **)(*(int *)cppPtr + 0x2c));
}

/* _CPPErrorToInfoLog @ 0x97bae4cc (104 bytes) */
int _CPPErrorToInfoLog(msg, staleR4, staleR5, staleR6, staleR7, staleR8, staleR9)
  undefined4 msg;
  undefined4 staleR4;
  undefined4 staleR5;
  undefined4 staleR6;
  undefined4 staleR7;
  undefined4 staleR8;
  undefined4 staleR9;
{
  undefined *cppPtr;
  undefined4 staleR10;
  
  cppPtr = PTR__cpp_a7b7c0a4;
  TParseContext__error
            (*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x2c),_yylineno,"syntax error","",msg,"",
             staleR9,staleR10);
  return TParseContext__recover(*(unsigned char **)(*(int *)cppPtr + 0x2c));
}

/* _SetLineNumber @ 0x97bae534 (44 bytes) */
int _SetLineNumber(lineNumber)
  uint lineNumber;
{
  _yylineno = _yylineno & 0xffff0000 | lineNumber;
  return;
}

/* _SetStringNumber @ 0x97bae560 (44 bytes) */
int _SetStringNumber(stringNumber)
  int stringNumber;
{
  _yylineno = stringNumber << 0x10 | (uint)(*(unsigned short *)((unsigned char *)&(_yylineno) + 2));
  return _yylineno;
}

/* _GetStringNumber @ 0x97bae58c (32 bytes) */
int _GetStringNumber()
{
  return _yylineno >> 0x10;
}

/* _GetLineNumber @ 0x97bae5ac (32 bytes) */
int _GetLineNumber()
{
  return _yylineno & 0xffff;
}

/* _IncLineNumber @ 0x97bae5cc (52 bytes) */
int _IncLineNumber()
{
  if (0xffff < (_yylineno & 0xffff)) {
    return;
  }
  _yylineno = _yylineno + 1;
  return;
}

/* _DecLineNumber @ 0x97bae600 (52 bytes) */
int _DecLineNumber()
{
  if ((_yylineno & 0xffff) == 0) {
    return;
  }
  _yylineno = _yylineno - 1;
  return;
}

/* _HandlePragma @ 0x97bae634 (576 bytes) */
int _HandlePragma(tokens, tokenCount)
  undefined4 *tokens;
  int tokenCount;
{
  int compareResult;
  char *message;
  undefined4 r4Out0;
  undefined4 r4Out1;
  undefined4 r4Out2;
  undefined4 r4Out3;
  undefined4 r4Out4;
  undefined4 r4Out5;
  undefined4 r4Out6;
  undefined4 r4Out7;
  undefined4 cmpLen;
  undefined4 staleR6;
  undefined4 staleR7;
  undefined4 staleR8;
  int cppState;
  undefined4 tokenTextOrStale;
  
  tokenTextOrStale = *tokens;
  cmpLen = 9;
  compareResult = _memcmp(tokenTextOrStale,"optimize",9);
  if (compareResult == 0) {
    if (tokenCount == 4) {
      cmpLen = 2;
      compareResult = _memcmp(tokens[1],"(",2);
      if (compareResult == 0) {
        tokenTextOrStale = tokens[2];
        compareResult = _memcmp(tokenTextOrStale,"on",3);
        if (compareResult == 0) {
          cppState = *(int *)PTR__cpp_a7b7c0a4;
          *(undefined4 *)(*(int *)(cppState + 0x2c) + 0x40) = 1;
        }
        else {
          cmpLen = 4;
          compareResult = _memcmp(tokenTextOrStale,"off",4);
          if (compareResult != 0) {
            message = "\"on\" or \"off\" expected after \'(\' for \'optimize\' pragma";
            tokenTextOrStale = r4Out2;
            goto LAB_97bae84c;
          }
          cppState = *(int *)PTR__cpp_a7b7c0a4;
          *(undefined4 *)(*(int *)(cppState + 0x2c) + 0x40) = 0;
        }
        cmpLen = 2;
        compareResult = _memcmp(tokens[3],")",2);
        if (compareResult == 0) {
          return;
        }
        message = "\")\" expected to end \'optimize\' pragma";
        tokenTextOrStale = r4Out3;
      }
      else {
        message = "\"(\" expected after \'optimize\' keyword";
        tokenTextOrStale = r4Out1;
      }
    }
    else {
      message = "optimize pragma syntax is incorrect";
      tokenTextOrStale = r4Out0;
    }
  }
  else {
    cmpLen = 6;
    compareResult = _memcmp(tokenTextOrStale,"debug",6);
    if (compareResult != 0) {
      return;
    }
    if (tokenCount == 4) {
      cmpLen = 2;
      compareResult = _memcmp(tokens[1],"(",2);
      if (compareResult == 0) {
        tokenTextOrStale = tokens[2];
        compareResult = _memcmp(tokenTextOrStale,"on",3);
        if (compareResult == 0) {
          cppState = *(int *)PTR__cpp_a7b7c0a4;
          *(undefined4 *)(*(int *)(cppState + 0x2c) + 0x44) = 1;
        }
        else {
          cmpLen = 4;
          compareResult = _memcmp(tokenTextOrStale,"off",4);
          if (compareResult != 0) {
            message = "\"on\" or \"off\" expected after \'(\' for \'debug\' pragma";
            tokenTextOrStale = r4Out6;
            goto LAB_97bae84c;
          }
          cppState = *(int *)PTR__cpp_a7b7c0a4;
          *(undefined4 *)(*(int *)(cppState + 0x2c) + 0x44) = 0;
        }
        cmpLen = 2;
        compareResult = _memcmp(tokens[3],")",2);
        if (compareResult == 0) {
          return;
        }
        message = "\")\" expected to end \'debug\' pragma";
        tokenTextOrStale = r4Out7;
      }
      else {
        message = "\"(\" expected after \'debug\' keyword";
        tokenTextOrStale = r4Out5;
      }
    }
    else {
      message = "debug pragma syntax is incorrect";
      tokenTextOrStale = r4Out4;
    }
  }
LAB_97bae84c:
  ((int (*)())_CPPShInfoLogMsg)(message,tokenTextOrStale,cmpLen,staleR6,staleR7,staleR8,cppState);
  return;
}

/* _StoreStr @ 0x97bae874 (448 bytes) */
int _StoreStr(str)
  char *str;
{
  int *refCountPtr;
  int oldRefCount;
  int atomicStore;
  int *emptyRepRefCount;
  int emptyRep;
  ulong length;
  unsigned char * destroyResult;
  unsigned char * tokenString;
  char reservation;
  byte cr0Reg;
  undefined4 newStrAlloc;
  int newStrData;
  undefined4 newStrAllocCopy;
  undefined4 copyStrAlloc;
  int copyStrData;
  undefined4 ctorAlloc [4];
  undefined4 copyDestroyAlloc [4];
  undefined4 concatStrAlloc;
  int concatStrData;
  undefined4 accumStrAlloc;
  int accumStrData;
  undefined4 concatDestroyAlloc [4];
  undefined4 accumDestroyAlloc [4];
  undefined4 newDestroyAlloc [7];
  
  emptyRep = DAT_a7b7baa8;
  emptyRepRefCount = (int *)(DAT_a7b7baa8 + 8);
  do {
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(*emptyRepRefCount + 1,0,emptyRepRefCount);
      *emptyRepRefCount = atomicStore;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  newStrAlloc = GetGlobalPoolAllocator();
  newStrData = emptyRep + 0xc;
  newStrAllocCopy = newStrAlloc;
  ctorAlloc[0] = GetGlobalPoolAllocator();
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
            ((unsigned char *)&copyStrAlloc,str,(unsigned char *)ctorAlloc);
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6assignERKS3_(&newStrAlloc,(unsigned char *)&copyStrAlloc);
  refCountPtr = (int *)(copyStrData + -4);
  copyDestroyAlloc[0] = copyStrAlloc;
  do {
    oldRefCount = *refCountPtr;
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
      *refCountPtr = atomicStore;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  if (oldRefCount < 1) {
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
              ((unsigned char *)(copyStrData + -0xc),copyDestroyAlloc);
  }
  tokenString = (unsigned char *)(*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x2c) + 0x58);
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_((unsigned char *)&accumStrAlloc,tokenString);
  length = _strlen(" ");
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEPKcm((unsigned char *)&accumStrAlloc," ",length);
  __ZStplIcSt11char_traitsIcE14pool_allocatorIcEESbIT_T0_T1_ERKS7_S9_
            ((unsigned char *)&concatStrAlloc,(unsigned char *)&accumStrAlloc,&newStrAlloc);
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6assignERKS3_(tokenString,(unsigned char *)&concatStrAlloc);
  refCountPtr = (int *)(concatStrData + -4);
  concatDestroyAlloc[0] = concatStrAlloc;
  do {
    oldRefCount = *refCountPtr;
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
      *refCountPtr = atomicStore;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  if (oldRefCount < 1) {
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
              ((unsigned char *)(concatStrData + -0xc),concatDestroyAlloc);
  }
  refCountPtr = (int *)(accumStrData + -4);
  accumDestroyAlloc[0] = accumStrAlloc;
  do {
    oldRefCount = *refCountPtr;
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
      *refCountPtr = atomicStore;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  if (oldRefCount < 1) {
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
              ((unsigned char *)(accumStrData + -0xc),accumDestroyAlloc);
  }
  refCountPtr = (int *)(newStrData + -4);
  destroyResult = (unsigned char *)(newStrData + -0xc);
  newDestroyAlloc[0] = newStrAlloc;
  do {
    oldRefCount = *refCountPtr;
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
      *refCountPtr = atomicStore;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  if (oldRefCount < 1) {
    destroyResult = (unsigned char *)
             __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_(destroyResult,newDestroyAlloc);
  }
  return destroyResult;
}

/* _GetStrfromTStr @ 0x97baea34 (80 bytes) */
int _GetStrfromTStr()
{
  undefined *cppPtr;
  int cpp;
  int parseContext;
  int tokenData;
  
  cppPtr = PTR__cpp_a7b7c0a4;
  cpp = *(int *)PTR__cpp_a7b7c0a4;
  parseContext = *(int *)(cpp + 0x2c);
  tokenData = *(int *)(parseContext + 0x5c);
  *(undefined1 *)(tokenData + *(int *)(tokenData + -0xc)) = *DAT_a7b7baa4;
  *(undefined4 *)(cpp + 0x13c) = *(undefined4 *)(parseContext + 0x5c);
  return *(undefined4 *)(*(int *)cppPtr + 0x13c);
}

/* _ResetTString @ 0x97baea84 (252 bytes) */
int _ResetTString()
{
  int parseContext;
  uint length;
  char *data;
  unsigned char * result;
  
  parseContext = *(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x2c);
  length = _strlen("");
  if (0x3ffffffc < length) {
    std____throw_length_error("basic_string::assign");
  }
  data = *(char **)(parseContext + 0x5c);
  if (((0 < *(int *)(data + -4)) || ("" < data)) || (data + *(int *)(data + -0xc) < "")) {
    result = __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE15_M_replace_safeIPKcEERS3_N9__gnu_cxx17__normal_iteratorIPcS3_EESB_T_SC_
                       ((void *)(parseContext + 0x58),data,data + *(int *)(data + -0xc),"","" + length
                       );
    return (char *)result;
  }
  if ((uint)((int)"" - (int)data) < length) {
    if (data == "") goto LAB_97baeb5c;
    _memmove(data,"",length);
  }
  else {
    _memcpy(data,"",length);
  }
  data = *(char **)(parseContext + 0x5c);
LAB_97baeb5c:
  *(uint *)(data + -0xc) = length;
  *(undefined1 *)(*(int *)(parseContext + 0x5c) + length) = 0;
  return data;
}

/* _GetBehavior @ 0x97baeb80 (484 bytes) */
int _GetBehavior(str)
  char *str;
{
  int compareResult;
  byte terminator;
  int atomicStore;
  int *refCountPtr;
  int oldRefCount;
  undefined4 behavior;
  ulong length;
  undefined4 r4Out0;
  undefined4 staleR6;
  undefined4 staleR7;
  undefined4 staleR8;
  char reservation;
  byte cr0Reg;
  undefined4 fullStrAlloc;
  int fullStrData;
  undefined4 catStrAlloc;
  int catStrData;
  undefined4 prefixStrAlloc;
  int prefixStrData;
  undefined4 prefixCtorAlloc [4];
  undefined4 fullDestroyAlloc [4];
  undefined4 catDestroyAlloc [4];
  undefined4 prefixDestroyAlloc [4];
  
  compareResult = _memcmp("require",str,8);
  behavior = 0;
  if (compareResult != 0) {
    compareResult = _memcmp("enable",str,7);
    behavior = 1;
    if (compareResult != 0) {
      compareResult = _memcmp("disable",str,8);
      behavior = 3;
      if (compareResult != 0) {
        compareResult = _memcmp("warn",str,5);
        behavior = 2;
        if (compareResult != 0) {
          prefixCtorAlloc[0] = GetGlobalPoolAllocator();
          __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                    ((unsigned char *)&prefixStrAlloc,"behavior \'",(unsigned char *)prefixCtorAlloc);
          __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_
                    ((unsigned char *)&catStrAlloc,(unsigned char *)&prefixStrAlloc);
          length = _strlen(str);
          __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEPKcm
                    ((unsigned char *)&catStrAlloc,str,length);
          __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&fullStrAlloc,(unsigned char *)&catStrAlloc);
          length = _strlen("\' is not supported");
          __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEPKcm
                    (&fullStrAlloc,"\' is not supported",length);
          terminator = *DAT_a7b7baa4;
          *(byte *)(fullStrData + *(int *)(fullStrData + -0xc)) = terminator;
          ((int (*)())_CPPShInfoLogMsg)(fullStrData,r4Out0,length,staleR6,staleR7,staleR8,(uint)terminator);
          refCountPtr = (int *)(fullStrData + -4);
          fullDestroyAlloc[0] = fullStrAlloc;
          do {
            oldRefCount = *refCountPtr;
            if (reservation != '\0') {
              atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
              *refCountPtr = atomicStore;
              cr0Reg = 2;
            }
          } while (!(bool)(cr0Reg >> 1 & 1));
          if (oldRefCount < 1) {
            __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                      ((unsigned char *)(fullStrData + -0xc),fullDestroyAlloc);
          }
          refCountPtr = (int *)(catStrData + -4);
          catDestroyAlloc[0] = catStrAlloc;
          do {
            oldRefCount = *refCountPtr;
            if (reservation != '\0') {
              atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
              *refCountPtr = atomicStore;
              cr0Reg = 2;
            }
          } while (!(bool)(cr0Reg >> 1 & 1));
          if (oldRefCount < 1) {
            __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                      ((unsigned char *)(catStrData + -0xc),catDestroyAlloc);
          }
          refCountPtr = (int *)(prefixStrData + -4);
          prefixDestroyAlloc[0] = prefixStrAlloc;
          do {
            oldRefCount = *refCountPtr;
            if (reservation != '\0') {
              atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
              *refCountPtr = atomicStore;
              cr0Reg = 2;
            }
          } while (!(bool)(cr0Reg >> 1 & 1));
          if (oldRefCount < 1) {
            __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                      ((unsigned char *)(prefixStrData + -0xc),prefixDestroyAlloc);
          }
          behavior = 3;
        }
      }
    }
  }
  return behavior;
}

/* _updateExtensionBehavior @ 0x97baed64 (1124 bytes) */
int _updateExtensionBehavior(extensionName, behaviorName)
  char *extensionName;
  undefined4 behaviorName;
{
  int stringNo;
  int parseContextState;
  int *refCountPtr;
  int oldRefCount;
  uint behavior2;
  int compareResult;
  byte terminator;
  int atomicStore;
  undefined *cppPtr;
  char *msgText;
  int *emptyRepRefCount;
  uint lineNo;
  int emptyRep;
  ulong length;
  undefined4 r4Out0;
  undefined4 r4Out1;
  undefined4 *destroyAllocPtr;
  undefined4 cmpLen;
  undefined4 staleR6;
  uint column;
  undefined4 staleR7;
  undefined4 staleR8;
  undefined4 staleR9;
  void *infoSink;
  char reservation;
  byte cr0Reg;
  int extIter [4];
  undefined4 msgStrAlloc;
  char *msgStrData;
  undefined4 msgAllocCopy;
  int firstExtNode;
  int endNodeAll;
  int findIter [4];
  undefined4 keyStrAlloc;
  int keyStrData;
  undefined4 keyCtorAlloc [4];
  undefined4 keyDestroyAlloc [4];
  int endNodeFind;
  char *fullStrAlloc;
  int fullStrData;
  undefined4 catStrAlloc;
  int catStrData;
  undefined4 errPrefixStrAlloc;
  int errPrefixStrData;
  undefined4 errPrefixCtorAlloc [4];
  char *errFullDestroyAlloc [4];
  undefined4 errCatDestroyAlloc [4];
  undefined4 errPrefixDestroyAlloc [4];
  undefined4 warnPrefixStrAlloc;
  int warnPrefixStrData;
  undefined4 warnPrefixCtorAlloc [4];
  char *warnFullDestroyAlloc [4];
  undefined4 warnCatDestroyAlloc [4];
  undefined4 warnPrefixDestroyAlloc [4];
  char lineText [64];
  undefined4 msgDestroyAllocAll [4];
  undefined4 msgDestroyAllocFound [4];
  undefined4 msgDestroyAllocErr [5];
  
  behavior2 = ((int (*)())_GetBehavior)(behaviorName);
  emptyRep = DAT_a7b7baa8;
  emptyRepRefCount = (int *)(DAT_a7b7baa8 + 8);
  do {
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(*emptyRepRefCount + 1,0,emptyRepRefCount);
      *emptyRepRefCount = atomicStore;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  msgStrAlloc = GetGlobalPoolAllocator();
  msgStrData = (char *)(emptyRep + 0xc);
  cmpLen = 4;
  msgAllocCopy = msgStrAlloc;
  compareResult = _memcmp(extensionName,"all",4);
  cppPtr = PTR__cpp_a7b7c0a4;
  if (compareResult == 0) {
    if (1 < behavior2) {
      extIter[0] = *(int *)(*(int *)(*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x2c) + 0x34) + 8);
      firstExtNode = extIter[0];
      while (endNodeAll = *(int *)(*(int *)(*(int *)cppPtr + 0x2c) + 0x34), extIter[0] != endNodeAll
            ) {
        *(uint *)(extIter[0] + 0x18) = behavior2;
        std___Rb_tree_base_iterator___M_increment((unsigned char *)extIter);
      }
LAB_97baf31c:
      refCountPtr = (int *)(msgStrData + -4);
      msgDestroyAllocAll[0] = msgStrAlloc;
      do {
        oldRefCount = *refCountPtr;
        if (reservation != '\0') {
          atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
          *refCountPtr = atomicStore;
          cr0Reg = 2;
        }
      } while (!(bool)(cr0Reg >> 1 & 1));
      if (0 < oldRefCount) {
        return;
      }
      destroyAllocPtr = msgDestroyAllocAll;
      goto code_r0x97baf34c;
    }
    ((int (*)())_CPPShInfoLogMsg)("extension \'all\' cannot have \'require\' or \'enable\' behavior",r4Out0,
                     cmpLen,staleR6,staleR7,staleR8,staleR9);
    refCountPtr = (int *)(msgStrData + -4);
    msgDestroyAllocErr[0] = msgStrAlloc;
    do {
      oldRefCount = *refCountPtr;
      if (reservation != '\0') {
        atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
        *refCountPtr = atomicStore;
        cr0Reg = 2;
      }
    } while (!(bool)(cr0Reg >> 1 & 1));
    destroyAllocPtr = msgDestroyAllocErr;
  }
  else {
    parseContextState = *(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x2c);
    keyCtorAlloc[0] = GetGlobalPoolAllocator();
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
              (&keyStrAlloc,extensionName,(unsigned char *)keyCtorAlloc);
    std___Rb_tree_std__string_std__pair_std__string_const_TBehavior__std___Select1st_std__pair_std__string_const_TBehavior___std__less_std__string__pool_allocator_std__pair_std__string_const_TBehavior_____find((unsigned char *)findIter,parseContextState + 0x30,&keyStrAlloc);
    extIter[0] = findIter[0];
    refCountPtr = (int *)(keyStrData + -4);
    keyDestroyAlloc[0] = keyStrAlloc;
    do {
      oldRefCount = *refCountPtr;
      if (reservation != '\0') {
        atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
        *refCountPtr = atomicStore;
        cr0Reg = 2;
      }
    } while (!(bool)(cr0Reg >> 1 & 1));
    if (oldRefCount < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(keyStrData + -0xc),keyDestroyAlloc);
    }
    endNodeFind = *(int *)(*(int *)(*(int *)cppPtr + 0x2c) + 0x34);
    if (extIter[0] != endNodeFind) {
      *(uint *)(extIter[0] + 0x18) = behavior2;
      goto LAB_97baf31c;
    }
    if (behavior2 == 0) {
      errPrefixCtorAlloc[0] = GetGlobalPoolAllocator();
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                ((unsigned char *)&errPrefixStrAlloc,"extension \'",(unsigned char *)errPrefixCtorAlloc);
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_
                ((unsigned char *)&catStrAlloc,(unsigned char *)&errPrefixStrAlloc);
      length = _strlen(extensionName);
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEPKcm((unsigned char *)&catStrAlloc,extensionName,length)
      ;
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&fullStrAlloc,(unsigned char *)&catStrAlloc);
      length = _strlen("\' is not supported");
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEPKcm
                (&fullStrAlloc,"\' is not supported",length);
      terminator = *DAT_a7b7baa4;
      *(byte *)(fullStrData + *(int *)(fullStrData + -0xc)) = terminator;
      ((int (*)())_CPPShInfoLogMsg)(fullStrData,r4Out1,length,staleR6,staleR7,staleR8,(uint)terminator);
      refCountPtr = (int *)(fullStrData + -4);
      errFullDestroyAlloc[0] = fullStrAlloc;
      do {
        oldRefCount = *refCountPtr;
        if (reservation != '\0') {
          atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
          *refCountPtr = atomicStore;
          cr0Reg = 2;
        }
      } while (!(bool)(cr0Reg >> 1 & 1));
      if (oldRefCount < 1) {
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                  ((unsigned char *)(fullStrData + -0xc),errFullDestroyAlloc);
      }
      refCountPtr = (int *)(catStrData + -4);
      errCatDestroyAlloc[0] = catStrAlloc;
      do {
        oldRefCount = *refCountPtr;
        if (reservation != '\0') {
          atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
          *refCountPtr = atomicStore;
          cr0Reg = 2;
        }
      } while (!(bool)(cr0Reg >> 1 & 1));
      if (oldRefCount < 1) {
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                  ((unsigned char *)(catStrData + -0xc),errCatDestroyAlloc);
      }
      refCountPtr = (int *)(errPrefixStrData + -4);
      errPrefixDestroyAlloc[0] = errPrefixStrAlloc;
      do {
        oldRefCount = *refCountPtr;
        if (reservation != '\0') {
          atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
          *refCountPtr = atomicStore;
          cr0Reg = 2;
        }
      } while (!(bool)(cr0Reg >> 1 & 1));
      if (oldRefCount < 1) {
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                  ((unsigned char *)(errPrefixStrData + -0xc),errPrefixDestroyAlloc);
      }
    }
    else if ((-1 < (int)behavior2) && ((int)behavior2 < 4)) {
      warnPrefixCtorAlloc[0] = GetGlobalPoolAllocator();
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                ((unsigned char *)&warnPrefixStrAlloc,"extension \'",(unsigned char *)warnPrefixCtorAlloc);
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_
                ((unsigned char *)&catStrAlloc,(unsigned char *)&warnPrefixStrAlloc);
      length = _strlen(extensionName);
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEPKcm((unsigned char *)&catStrAlloc,extensionName,length)
      ;
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_
                ((unsigned char *)&fullStrAlloc,(unsigned char *)&catStrAlloc);
      length = _strlen("\' is not supported");
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEPKcm
                ((unsigned char *)&fullStrAlloc,"\' is not supported",length);
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6assignERKS3_(&msgStrAlloc,(unsigned char *)&fullStrAlloc);
      refCountPtr = (int *)(fullStrData + -4);
      warnFullDestroyAlloc[0] = fullStrAlloc;
      do {
        oldRefCount = *refCountPtr;
        if (reservation != '\0') {
          atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
          *refCountPtr = atomicStore;
          cr0Reg = 2;
        }
      } while (!(bool)(cr0Reg >> 1 & 1));
      if (oldRefCount < 1) {
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                  ((unsigned char *)(fullStrData + -0xc),warnFullDestroyAlloc);
      }
      refCountPtr = (int *)(catStrData + -4);
      warnCatDestroyAlloc[0] = catStrAlloc;
      do {
        oldRefCount = *refCountPtr;
        if (reservation != '\0') {
          atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
          *refCountPtr = atomicStore;
          cr0Reg = 2;
        }
      } while (!(bool)(cr0Reg >> 1 & 1));
      if (oldRefCount < 1) {
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                  ((unsigned char *)(catStrData + -0xc),warnCatDestroyAlloc);
      }
      refCountPtr = (int *)(warnPrefixStrData + -4);
      warnPrefixDestroyAlloc[0] = warnPrefixStrAlloc;
      do {
        oldRefCount = *refCountPtr;
        if (reservation != '\0') {
          atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
          *refCountPtr = atomicStore;
          cr0Reg = 2;
        }
      } while (!(bool)(cr0Reg >> 1 & 1));
      if (oldRefCount < 1) {
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                  ((unsigned char *)(warnPrefixStrData + -0xc),warnPrefixDestroyAlloc);
      }
      msgText = msgStrData;
      infoSink = *(void **)(*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x2c) + 8);
      msgStrData[*(int *)(msgStrData + -0xc)] = *DAT_a7b7baa4;
      lineNo = _yylineno;
                    
      __ZN13TInfoSinkBase6appendEPKc(infoSink,"WARNING: ");
      column = lineNo & 0xffff;
      cr0Reg = (column == 0) << 1;
      stringNo = (int)lineNo >> 0x10;
      if (column == 0) {
        _sprintf(lineText,"%d:? ",stringNo);
      }
      else {
        _sprintf(lineText,"%d:%d",stringNo,column);
      }
      __ZNSsC1EPKcRKSaIcE((unsigned char *)&fullStrAlloc,lineText,(unsigned char *)&catStrAlloc);
      fullStrAlloc[*(int *)(fullStrAlloc + -0xc)] = *PTR__S_terminal_a7b7c0b8;
      __ZN13TInfoSinkBase6appendEPKc(infoSink,fullStrAlloc);
      refCountPtr = (int *)(fullStrAlloc + -4);
      do {
        oldRefCount = *refCountPtr;
        if (reservation != '\0') {
          atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
          *refCountPtr = atomicStore;
          cr0Reg = 2;
        }
      } while (!(bool)(cr0Reg >> 1 & 1));
      if (oldRefCount < 1) {
        __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(fullStrAlloc + -0xc));
      }
      __ZN13TInfoSinkBase6appendEPKc(infoSink,": ");
      __ZN13TInfoSinkBase6appendEPKc(infoSink,msgText);
      __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
    }
    refCountPtr = (int *)(msgStrData + -4);
    msgDestroyAllocFound[0] = msgStrAlloc;
    do {
      oldRefCount = *refCountPtr;
      if (reservation != '\0') {
        atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
        *refCountPtr = atomicStore;
        cr0Reg = 2;
      }
    } while (!(bool)(cr0Reg >> 1 & 1));
    destroyAllocPtr = msgDestroyAllocFound;
  }
  if (0 < oldRefCount) {
    return;
  }
code_r0x97baf34c:
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
            ((unsigned char *)(msgStrData + -0xc),destroyAllocPtr);
  return;
}

/* setInitialState @ 0x97baf364 (32 bytes) */
int setInitialState()
{
  _yy_start = 1;
  return;
}

/* scpy @ 0x97baf384 (52 bytes) */
int scpy(str1, str2)
  char *str1;
  char *str2;
{
  char ch;
  int copyIndex;
  
  ch = *str2;
  copyIndex = 0;
  if (ch != '\0') {
    do {
      str1[copyIndex] = ch;
      copyIndex = copyIndex + 1;
      ch = str2[copyIndex];
    } while (ch != '\0');
    return copyIndex;
  }
  return copyIndex;
}

/* handleDigit @ 0x97baf3b8 (112 bytes) */
int handleDigit(outPtr, value)
  char **outPtr;
  int value;
{
  int quotient;
  
  quotient = value / 10;
  if (quotient != 0) {
    ((int (*)())handleDigit)(outPtr,quotient);
  }
  **outPtr = (char)value + (char)quotient * -10 + '0';
  *outPtr = *outPtr + 1;
  return;
}

/* ncpy @ 0x97baf428 (88 bytes) */
int ncpy(out, value)
  char *out;
  int value;
{
  char *cursor [6];
  
  cursor[0] = out;
  if (value < 0) {
    cursor[0] = out + 1;
    *out = '-';
    value = -value;
  }
  ((int (*)())handleDigit)(cursor,value);
  return (int)cursor[0] - (int)out;
}

/* PrintAttribute @ 0x97baf480 (456 bytes) */
int PrintAttribute(_PPStreamToken, ordinalIn)
  uint _PPStreamToken;
  uint ordinalIn;
{
  uint indexValue;
  char *allocation;
  int copyEnd;
  char *label;
  char *writePtr;
  uint bindingWord;
  uint ordinal;
  
  bindingWord = _PPStreamToken;
  ordinal = ordinalIn;
  allocation = (char *)_malloc(0x100);
  copyEnd = ((int (*)())ncpy)(allocation,ordinal & 0xffff);
  writePtr = allocation + copyEnd;
  switch(bindingWord >> 0x10 & 0xf) {
  case 0:
    label = ": PP_BIND_ATTRIB_NONE";
    break;
  case 1:
    label = ": PP_BIND_ATTRIB_POSITION";
    break;
  case 2:
    label = ": PP_BIND_ATTRIB_COLOR";
    break;
  case 3:
    label = ": PP_BIND_ATTRIB_SEC_COLOR";
    break;
  case 4:
    label = ": PP_BIND_ATTRIB_NORMAL";
    break;
  case 5:
    label = ": PP_BIND_ATTRIB_FOG_COORD";
    break;
  case 6:
    label = ": PP_BIND_ATTRIB_WEIGHT:";
    goto LAB_97baf584;
  case 7:
    label = ": PP_BIND_ATTRIB_TEX_COORD:";
    goto LAB_97baf584;
  case 8:
    label = ": PP_BIND_ATTRIB_MATRIX_INDICES:";
    goto LAB_97baf584;
  case 9:
    label = ": PP_BIND_ATTRIB_ATTRIB:";
LAB_97baf584:
    copyEnd = ((int (*)())scpy)(writePtr,label);
    writePtr = writePtr + copyEnd;
    indexValue = bindingWord & 0x1f;
LAB_97baf658:
    copyEnd = ((int (*)())ncpy)(writePtr,indexValue);
    goto LAB_97baf660;
  case 10:
    copyEnd = ((int (*)())scpy)(writePtr,"PP_BIND_ATTRIB_MATERIAL:");
    writePtr = writePtr + copyEnd;
    switch(bindingWord >> 0xc & 0xf) {
    case 0:
      label = "PP_ATTRIB_MATERIAL_AMBIENT:";
      break;
    case 1:
      label = "PP_ATTRIB_MATERIAL_DIFFUSE:";
      break;
    case 2:
      label = "PP_ATTRIB_MATERIAL_SPECULAR:";
      break;
    case 3:
      label = "PP_ATTRIB_MATERIAL_EMISSION:";
      break;
    case 4:
      label = "PP_ATTRIB_MATERIAL_SHININESS:";
      break;
    default:
      goto switchD_97baf5f0_default;
    }
    copyEnd = ((int (*)())scpy)(writePtr,label);
    writePtr = writePtr + copyEnd;
switchD_97baf5f0_default:
    indexValue = bindingWord & 1;
    goto LAB_97baf658;
  case 0xb:
    label = ": PP_BIND_ATTRIB_FRONT_FACING";
    break;
  default:
    goto switchD_97baf4e0_default;
  }
  copyEnd = ((int (*)())scpy)(writePtr,label);
LAB_97baf660:
  writePtr = writePtr + copyEnd;
switchD_97baf4e0_default:
  *writePtr = '\0';
  _realloc(allocation,writePtr + (1 - (int)allocation));
  return;
}

/* PrintParam @ 0x97baf68c (1228 bytes) */
int PrintParam(_PPStreamToken, ordinalIn)
  uint _PPStreamToken;
  uint ordinalIn;
{
  uint bindingBits14;
  uint bindingIndex;
  uint bindingBits5;
  char *allocation;
  int copyEnd;
  int copyEnd2;
  uint bindingBits9;
  char *label;
  char *writePtr;
  uint bindingWord;
  uint ordinal;
  
  bindingWord = _PPStreamToken;
  ordinal = ordinalIn;
  allocation = (char *)_malloc(0x100);
  copyEnd = ((int (*)())ncpy)(allocation,ordinal & 0xffff);
  writePtr = allocation + copyEnd;
  switch(bindingWord >> 0x10 & 0x1f) {
  case 0:
    label = ": PP_BIND_PARAM_NONE:";
    goto LAB_97baf750;
  case 1:
    label = ": PP_BIND_PARAM_PROGRAM_LOCAL:";
    goto LAB_97baf750;
  case 2:
    label = ": PP_BIND_PARAM_PROGRAM_ENV:";
    goto LAB_97baf750;
  case 3:
    copyEnd = ((int (*)())scpy)(writePtr,": PP_BIND_PARAM_LIGHT:");
    copyEnd2 = ((int (*)())ncpy)(writePtr + copyEnd,bindingWord & 0xff);
    writePtr = writePtr + copyEnd + copyEnd2;
    switch(bindingWord >> 8 & 0xf) {
    case 0:
      label = ":PP_PARAM_LIGHT_AMBIENT";
      break;
    case 1:
      label = ":PP_PARAM_LIGHT_DIFFUSE";
      break;
    case 2:
      label = ":PP_PARAM_LIGHT_SPECULAR";
      break;
    case 3:
      label = ":PP_PARAM_LIGHT_POSITION";
      break;
    case 4:
      label = ":PP_PARAM_LIGHT_DIRECTION";
      break;
    case 5:
      label = ":PP_PARAM_LIGHT_ATTENUATION";
      break;
    case 6:
      label = ":PP_PARAM_LIGHT_HALF";
      break;
    case 7:
      label = ":PP_PARAM_LIGHT_SPOTCUTOFF";
      break;
    default:
      goto switchD_97bafb24_default;
    }
    break;
  case 4:
    copyEnd = ((int (*)())scpy)(writePtr,": PP_BIND_PARAM_LIGHT_PROD:");
    writePtr = writePtr + copyEnd;
    copyEnd = ((int (*)())ncpy)(writePtr,bindingWord & 0xff);
    writePtr = writePtr + copyEnd;
    copyEnd = ((int (*)())scpy)(writePtr,":");
    copyEnd2 = ((int (*)())ncpy)(writePtr + copyEnd,bindingWord >> 8 & 1);
    writePtr = writePtr + copyEnd + copyEnd2;
    bindingBits9 = bindingWord >> 9 & 3;
    if (bindingBits9 == 1) {
      label = ":PP_PARAM_LIGHT_PROD_DIFFUSE";
    }
    else if (bindingBits9 == 0) {
      label = ":PP_PARAM_LIGHT_PROD_AMBIENT";
    }
    else {
      if (bindingBits9 != 2) goto switchD_97bafb24_default;
      label = ":PP_PARAM_LIGHT_PROD_SPECULAR";
    }
    break;
  case 5:
    copyEnd = ((int (*)())scpy)(writePtr,": PP_BIND_PARAM_MATERIAL:");
    copyEnd2 = ((int (*)())ncpy)(writePtr + copyEnd,bindingWord & 1);
    writePtr = writePtr + copyEnd + copyEnd2;
    switch(bindingWord >> 1 & 7) {
    case 0:
      label = ":PP_PARAM_MATERIAL_AMBIENT";
      break;
    case 1:
      label = ":PP_PARAM_MATERIAL_DIFFUSE";
      break;
    case 2:
      label = ":PP_PARAM_MATERIAL_SPECULAR";
      break;
    case 3:
      label = ":PP_PARAM_MATERIAL_EMISSION";
      break;
    case 4:
      label = ":PP_PARAM_MATERIAL_SHININESS";
      break;
    case 5:
      label = ":PP_PARAM_MATERIAL_SCENE_COLOR";
      break;
    default:
      goto switchD_97bafb24_default;
    }
    break;
  case 6:
    label = ": PP_BIND_PARAM_LIGHT_MODEL";
    break;
  case 7:
    label = ": PP_BIND_PARAM_TEX_GEN_EYE_PLANE:";
    goto LAB_97baf9a4;
  case 8:
    label = ": PP_BIND_PARAM_TEX_GEN_OBJECT_PLANE:";
LAB_97baf9a4:
    copyEnd = ((int (*)())scpy)(writePtr,label);
    writePtr = writePtr + copyEnd;
    bindingBits5 = bindingWord >> 5 & 7;
    if (bindingBits5 == 1) {
      label = "PP_PARAM_TEX_GEN_COORD_T:";
LAB_97bafa10:
      copyEnd = ((int (*)())scpy)(writePtr,label);
      writePtr = writePtr + copyEnd;
    }
    else {
      if (bindingBits5 == 0) {
        label = "PP_PARAM_TEX_GEN_COORD_S:";
        goto LAB_97bafa10;
      }
      if (bindingBits5 == 2) {
        label = "PP_PARAM_TEX_GEN_COORD_R:";
        goto LAB_97bafa10;
      }
      if (bindingBits5 == 3) {
        label = "PP_PARAM_TEX_GEN_COORD_Q:";
        goto LAB_97bafa10;
      }
    }
    bindingIndex = bindingWord & 0x1f;
    goto LAB_97baf760;
  default:
    label = ": Error, binding not found.";
    break;
  case 10:
    label = ": PP_BIND_PARAM_CLIP_PLANE:";
    goto LAB_97bafb84;
  case 0xb:
    label = ": PP_BIND_PARAM_FOG_COLOR";
    break;
  case 0xc:
    label = ": PP_BIND_PARAM_FOG_PARAMETERS";
    break;
  case 0xd:
    label = ": PP_BIND_PARAM_POINT_PARAMETERS";
    break;
  case 0xe:
    label = ": PP_BIND_PARAM_POINT_ATTENUATION";
    break;
  case 0xf:
    label = ": PP_BIND_PARAM_DEPTH_RANGE";
    break;
  case 0x10:
    copyEnd = ((int (*)())scpy)(writePtr,": PP_BIND_PARAM_MATRIX:");
    writePtr = writePtr + copyEnd;
    bindingBits14 = bindingWord >> 0xe & 3;
    if (bindingBits14 == 1) {
      label = "PP_MATRIX_TRANSFORM_TRANSPOSE:";
LAB_97bafae0:
      copyEnd = ((int (*)())scpy)(writePtr,label);
      writePtr = writePtr + copyEnd;
    }
    else {
      if (bindingBits14 == 0) {
        label = "PP_MATRIX_TRANSFORM_IDENTITY:";
        goto LAB_97bafae0;
      }
      if (bindingBits14 == 2) {
        label = "PP_MATRIX_TRANSFORM_INVERSE:";
        goto LAB_97bafae0;
      }
      if (bindingBits14 == 3) {
        label = "PP_MATRIX_TRANSFORM_INVERSE_TRANSPOSE:";
        goto LAB_97bafae0;
      }
    }
    copyEnd = ((int (*)())ncpy)(writePtr,bindingWord >> 0xc & 3);
    writePtr = writePtr + copyEnd;
    switch(bindingWord >> 8 & 7) {
    case 0:
      label = ":PP_PARAM_MATRIX_MODELVIEW_PROJECTION";
      break;
    case 1:
      label = ":PP_PARAM_MATRIX_PROJECTION";
      break;
    case 2:
      label = ":PP_PARAM_MATRIX_COLOR";
      break;
    case 3:
      label = ":PP_PARAM_MATRIX_MODELVIEW:";
      goto LAB_97bafb84;
    case 4:
      label = ":PP_PARAM_MATRIX_TEXTURE:";
      goto LAB_97bafb84;
    case 5:
      label = ":PP_PARAM_MATRIX_PROGRAM:";
LAB_97bafb84:
      copyEnd = ((int (*)())scpy)(writePtr,label);
      bindingIndex = bindingWord & 0xff;
      goto LAB_97baf75c;
    default:
      goto switchD_97bafb24_default;
    }
    break;
  case 0x11:
    label = ": PP_BIND_PARAM_CONSTANT:";
LAB_97baf750:
    copyEnd = ((int (*)())scpy)(writePtr,label);
    bindingIndex = bindingWord & 0xffff;
LAB_97baf75c:
    writePtr = writePtr + copyEnd;
LAB_97baf760:
    copyEnd = ((int (*)())ncpy)(writePtr,bindingIndex);
    goto LAB_97bafbc8;
  case 0x12:
    label = ": PP_BIND_PARAM_NORMAL_SCALE";
  }
  copyEnd = ((int (*)())scpy)(writePtr,label);
LAB_97bafbc8:
  writePtr = writePtr + copyEnd;
switchD_97bafb24_default:
  *writePtr = '\0';
  _realloc(allocation,writePtr + (1 - (int)allocation));
  return;
}

/* PrintOutput @ 0x97bafbf4 (420 bytes) */
int PrintOutput(_PPStreamToken, ordinalIn)
  uint _PPStreamToken;
  uint ordinalIn;
{
  char *allocation;
  int copyEnd;
  int copyEnd2;
  undefined4 allocation2;
  uint indexValue;
  char *label;
  char *writePtr;
  uint bindingWord;
  uint ordinal;
  
  bindingWord = _PPStreamToken;
  ordinal = ordinalIn;
  allocation = (char *)_malloc(0x100);
  copyEnd = ((int (*)())ncpy)(allocation,ordinal & 0xffff);
  writePtr = allocation + copyEnd;
  switch(bindingWord >> 0x10 & 0xf) {
  default:
    label = ": Error, binding not found.";
    break;
  case 1:
    label = ": PP_BIND_OUTPUT_RESULT_POSITION";
    break;
  case 2:
    label = ": PP_BIND_OUTPUT_RESULT_FOG_COORD";
    break;
  case 3:
    label = ": PP_BIND_OUTPUT_RESULT_POINT_SIZE";
    break;
  case 4:
    copyEnd = ((int (*)())scpy)(writePtr,": PP_BIND_OUTPUT_RESULT_COLOR:");
    if ((bindingWord & 1) == 0) {
      label = "PP_FACE_FRONT:";
    }
    else {
      label = "PP_FACE_BACK:";
    }
    copyEnd2 = ((int (*)())scpy)(writePtr + copyEnd,label);
    writePtr = writePtr + copyEnd + copyEnd2;
    indexValue = bindingWord >> 1 & 7;
    goto LAB_97bafcf4;
  case 5:
    copyEnd = ((int (*)())scpy)(writePtr,": PP_BIND_OUTPUT_RESULT_SEC_COLOR:");
    writePtr = writePtr + copyEnd;
    if ((bindingWord & 1) == 0) {
      label = "PP_FACE_FRONT";
    }
    else {
      label = "PP_FACE_BACK";
    }
    break;
  case 6:
    label = ": PP_BIND_OUTPUT_RESULT_TEX_COORD:";
    goto LAB_97bafd6c;
  case 7:
    label = ": PP_BIND_OUTPUT_RESULT_DEPTH";
    break;
  case 8:
    label = ": PP_BIND_OUTPUT_RESULT_EYE_POSITION";
    break;
  case 9:
    label = ": PP_BIND_OUTPUT_RESULT_CLIP_VERTEX";
    break;
  case 10:
    label = ": PP_BIND_OUTPUT_RESULT_ATTRIB:";
LAB_97bafd6c:
    copyEnd = ((int (*)())scpy)(writePtr,label);
    writePtr = writePtr + copyEnd;
    indexValue = bindingWord & 0x1f;
LAB_97bafcf4:
    copyEnd = ((int (*)())ncpy)(writePtr,indexValue);
    goto LAB_97bafd98;
  }
  copyEnd = ((int (*)())scpy)(writePtr,label);
LAB_97bafd98:
  writePtr[copyEnd] = '\0';
  allocation2 = _realloc(allocation,writePtr + copyEnd + (1 - (int)allocation));
  return allocation2;
}

/* PrintTemp @ 0x97bafdc4 (76 bytes) */
int PrintTemp(_PPStreamToken, ordinalIn)
  undefined4 _PPStreamToken;
  uint ordinalIn;
{
  char *allocation;
  int copyEnd;
  undefined4 bindingWord;
  uint ordinal;
  
  bindingWord = _PPStreamToken;
  ordinal = ordinalIn;
  allocation = (char *)_malloc(0x10);
  copyEnd = ((int (*)())ncpy)(allocation,ordinal & 0xffff);
  allocation[copyEnd] = '\0';
  return allocation;
}

/* Binding__ClearName @ 0x97bafe10 (72 bytes) */
int Binding__ClearName(this)
  unsigned char * this;
{
  if (*(int *)(this + 8) != 0) {
    _free(*(int *)(this + 8));
  }
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  return;
}

/* __ZN7BindingC2Ev @ 0x97bafe58 (4 bytes) */
int __ZN7BindingC2Ev(this)
  void *this;
{
  *(undefined1 *)((int)this + 0x35) = 0;
  *(undefined4 *)((int)this + 0x20) = 0xffffffff;
  *(undefined4 *)((int)this + 0x1c) = 1;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x2c) = 0;
  *(undefined4 *)((int)this + 0x30) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x18) = 1;
  *(undefined2 *)((int)this + 0x24) = 0;
  *(undefined4 *)this = 0;
  *(undefined1 *)((int)this + 0x34) = 0;
  return;
}

/* __ZN7BindingC1Ev @ 0x97bafe5c (4 bytes) */
int __ZN7BindingC1Ev(this)
  void *this;
{
  *(undefined1 *)((int)this + 0x35) = 0;
  *(undefined4 *)((int)this + 0x20) = 0xffffffff;
  *(undefined4 *)((int)this + 0x1c) = 1;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x2c) = 0;
  *(undefined4 *)((int)this + 0x30) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x18) = 1;
  *(undefined2 *)((int)this + 0x24) = 0;
  *(undefined4 *)this = 0;
  *(undefined1 *)((int)this + 0x34) = 0;
  return;
}

/* __ZN7BindingC4Ev @ 0x97bafe60 (76 bytes) */
int __ZN7BindingC4Ev(this)
  void *this;
{
  *(undefined1 *)((int)this + 0x35) = 0;
  *(undefined4 *)((int)this + 0x20) = 0xffffffff;
  *(undefined4 *)((int)this + 0x1c) = 1;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x2c) = 0;
  *(undefined4 *)((int)this + 0x30) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x18) = 1;
  *(undefined2 *)((int)this + 0x24) = 0;
  *(undefined4 *)this = 0;
  *(undefined1 *)((int)this + 0x34) = 0;
  return;
}

/* __ZN7BindingD2Ev @ 0x97bafeac (8 bytes) */
int __ZN7BindingD2Ev(this)
  void *this;
{
  return ((int (*)())__ZN7BindingD4Ev)(this);
}

/* __ZN7BindingD1Ev @ 0x97bafeb4 (8 bytes) */
int __ZN7BindingD1Ev(this)
  void *this;
{
  return ((int (*)())__ZN7BindingD4Ev)(this);
}

/* __ZN7BindingD4Ev @ 0x97bafebc (4 bytes) */
int __ZN7BindingD4Ev(this)
  void *this;
{
  if (*(void **)((int)this + 8) != (void *)0x0) {
    _free(*(void **)((int)this + 8));
  }
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  return;
}

/* __ZN7BindingC2ERKS_ @ 0x97bafec0 (4 bytes) */
int __ZN7BindingC2ERKS_(this, binding)
  void *this;
  unsigned char * binding;
{
  bool isClientRequest;
  ulong actualSize;
  int activeIndex;
  int location;
  bool isBuiltIn;
  ushort openGLType;
  ulong decSize;
  char *name;
  
  *(undefined4 *)((int)this + 8) = 0;
  name = *(char **)(binding + 8);
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  ((int (*)())Binding__SetName)(this,name);
  location = Binding__GetLocation(binding);
  Binding__SetLocation(this,location);
  activeIndex = Binding__GetActiveIndex(binding);
  Binding__SetActiveIndex(this,activeIndex);
  isClientRequest = (bool)((int (*)())Binding__IsClientRequest)(binding);
  ((int (*)())Binding__SetClientRequest)(this,isClientRequest);
  isBuiltIn = (bool)((int (*)())Binding__IsBuiltIn)(binding);
  ((int (*)())Binding__SetBuiltIn)(this,isBuiltIn);
  openGLType = Binding__GetOpenGLType(binding);
  Binding__SetOpenGLType(this,openGLType);
  decSize = Binding__GetDecSize(binding);
  Binding__SetDecSize(this,decSize);
  actualSize = Binding__GetActualSize(binding);
  Binding__SetActualSize(this,actualSize);
  *(undefined1 *)((int)this + 0x35) = 0;
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined1 *)((int)this + 0x34) = 0;
  return;
}

/* __ZN7BindingC1ERKS_ @ 0x97bafec4 (4 bytes) */
int __ZN7BindingC1ERKS_(this, binding)
  void *this;
  unsigned char * binding;
{
  bool isClientRequest;
  ulong actualSize;
  int activeIndex;
  int location;
  bool isBuiltIn;
  ushort openGLType;
  ulong decSize;
  char *name;
  
  *(undefined4 *)((int)this + 8) = 0;
  name = *(char **)(binding + 8);
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  ((int (*)())Binding__SetName)(this,name);
  location = Binding__GetLocation(binding);
  Binding__SetLocation(this,location);
  activeIndex = Binding__GetActiveIndex(binding);
  Binding__SetActiveIndex(this,activeIndex);
  isClientRequest = (bool)((int (*)())Binding__IsClientRequest)(binding);
  ((int (*)())Binding__SetClientRequest)(this,isClientRequest);
  isBuiltIn = (bool)((int (*)())Binding__IsBuiltIn)(binding);
  ((int (*)())Binding__SetBuiltIn)(this,isBuiltIn);
  openGLType = Binding__GetOpenGLType(binding);
  Binding__SetOpenGLType(this,openGLType);
  decSize = Binding__GetDecSize(binding);
  Binding__SetDecSize(this,decSize);
  actualSize = Binding__GetActualSize(binding);
  Binding__SetActualSize(this,actualSize);
  *(undefined1 *)((int)this + 0x35) = 0;
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined1 *)((int)this + 0x34) = 0;
  return;
}

/* __ZN7BindingC4ERKS_ @ 0x97bafec8 (224 bytes) */
int __ZN7BindingC4ERKS_(this, binding)
  void *this;
  unsigned char * binding;
{
  undefined4 isBuiltIn;
  ulong actualSize;
  int activeIndex;
  int location;
  undefined4 isClientRequest;
  ushort openGLType;
  ulong decSize;
  char *name;
  
  *(undefined4 *)((int)this + 8) = 0;
  name = *(char **)(binding + 8);
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  ((int (*)())Binding__SetName)(this,name);
  location = Binding__GetLocation(binding);
  Binding__SetLocation(this,location);
  activeIndex = Binding__GetActiveIndex(binding);
  Binding__SetActiveIndex(this,activeIndex);
  isClientRequest = ((int (*)())Binding__IsClientRequest)(binding);
  ((int (*)())Binding__SetClientRequest)(this,isClientRequest);
  isBuiltIn = ((int (*)())Binding__IsBuiltIn)(binding);
  ((int (*)())Binding__SetBuiltIn)(this,isBuiltIn);
  openGLType = Binding__GetOpenGLType(binding);
  Binding__SetOpenGLType(this,openGLType);
  decSize = Binding__GetDecSize(binding);
  Binding__SetDecSize(this,decSize);
  actualSize = Binding__GetActualSize(binding);
  Binding__SetActualSize(this,actualSize);
  *(undefined1 *)((int)this + 0x35) = 0;
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined1 *)((int)this + 0x34) = 0;
  return;
}

/* Binding__operator_ @ 0x97baffa8 (232 bytes) */
int Binding__operator_(this, binding)
  unsigned char * this;
  unsigned char * binding;
{
  undefined4 isBuiltIn;
  ulong actualSize;
  int activeIndex;
  unsigned char BVar1;
  int location;
  undefined4 isClientRequest;
  ushort openGLType;
  ulong decSize;
  
  if (this != binding) {
    SetName(this,*(char **)(binding + 8));
    location = Binding__GetLocation(binding);
    Binding__SetLocation(this,location);
    activeIndex = Binding__GetActiveIndex(binding);
    Binding__SetActiveIndex(this,activeIndex);
    isClientRequest = ((int (*)())Binding__IsClientRequest)(binding);
    ((int (*)())Binding__SetClientRequest)(this,isClientRequest);
    isBuiltIn = ((int (*)())Binding__IsBuiltIn)(binding);
    ((int (*)())Binding__SetBuiltIn)(this,isBuiltIn);
    openGLType = Binding__GetOpenGLType(binding);
    Binding__SetOpenGLType(this,openGLType);
    decSize = Binding__GetDecSize(binding);
    Binding__SetDecSize(this,decSize);
    actualSize = Binding__GetActualSize(binding);
    Binding__SetActualSize(this,actualSize);
    this[0x34] = binding[0x34];
    BVar1 = binding[0x35];
    *(undefined4 *)(this + 4) = 0;
    this[0x35] = BVar1;
    *(undefined4 *)this = 0;
  }
  return this;
}

/* __ZeqRK7BindingS1_ @ 0x97bb0090 (88 bytes) */
int __ZeqRK7BindingS1_(binding1, binding2)
  unsigned char * binding1;
  unsigned char * binding2;
{
  int nameCmp;
  
  if (((*(int *)(binding1 + 0xc) == *(int *)(binding2 + 0xc)) &&
      (*(int *)(binding1 + 0x10) == *(int *)(binding2 + 0x10))) &&
     (nameCmp = _strncmp(*(undefined4 *)(binding1 + 8),*(undefined4 *)(binding2 + 8),
                       *(int *)(binding1 + 0x10)), nameCmp == 0)) {
    return 1;
  }
  return 0;
}

/* Binding__CatName @ 0x97bb00e8 (208 bytes) */
int Binding__CatName(this, str)
  unsigned char * this;
  char *str;
{
  int length;
  char *chPtr;
  int hashSum;
  int nameLen;
  char *allocation;
  int charIdx;
  
  if (str != (char *)0x0) {
    length = _strlen(str);
    allocation = (char *)_malloc(length + *(int *)(this + 0x10) + 1);
    if (*(char **)(this + 8) != (char *)0x0) {
      _strncpy(allocation,*(char **)(this + 8),*(int *)(this + 0x10) + 1);
    }
    _strncpy(allocation + *(int *)(this + 0x10),str,length + 1);
    *(int *)(this + 0x10) = *(int *)(this + 0x10) + length;
    _free(*(undefined4 *)(this + 8));
    nameLen = *(int *)(this + 0x10);
    charIdx = 0;
    *(undefined4 *)(this + 0xc) = 0;
    *(char **)(this + 8) = allocation;
    if (nameLen != 0) {
      hashSum = 0;
      do {
        chPtr = allocation + charIdx;
        charIdx = charIdx + 1;
        hashSum = hashSum + *chPtr;
        nameLen = nameLen + -1;
      } while (nameLen != 0);
      *(int *)(this + 0xc) = hashSum;
    }
  }
  return;
}

/* Binding__SetName @ 0x97bb01b8 (164 bytes) */
int Binding__SetName(this, str)
  unsigned char * this;
  char *str;
{
  char *allocation;
  int nameLen;
  char *chPtr;
  int charIdx;
  
  ClearName(this);
  if ((str != (char *)0x0) && (nameLen = _strlen(str), 0 < nameLen)) {
    *(int *)(this + 0x10) = nameLen;
    allocation = (char *)_malloc(nameLen + 1);
    *(char **)(this + 8) = allocation;
    _strncpy(allocation,str,*(int *)(this + 0x10) + 1);
    nameLen = *(int *)(this + 0x10);
    charIdx = 0;
    *(undefined4 *)(this + 0xc) = 0;
    if (nameLen != 0) {
      do {
        chPtr = (char *)(*(int *)(this + 8) + charIdx);
        charIdx = charIdx + 1;
        *(int *)(this + 0xc) = *(int *)(this + 0xc) + (int)*chPtr;
        nameLen = nameLen + -1;
      } while (nameLen != 0);
    }
  }
  return;
}

/* Binding__SetNameFromArrayName @ 0x97bb025c (332 bytes) */
int Binding__SetNameFromArrayName(this, str)
  unsigned char * this;
  char *str;
{
  int charIdx;
  int clearIdx;
  int lenOrBracketPos;
  char *allocation;
  bool foundBracket;
  int nameLen;
  char *chPtr;
  int nameData;
  undefined4 arrayIndex;
  int bracketPos;
  
  ClearName(this);
  arrayIndex = 0;
  if ((str != (char *)0x0) && (nameLen = _strlen(str), 0 < nameLen)) {
    *(int *)(this + 0x10) = nameLen;
    allocation = (char *)_malloc(nameLen + 1);
    *(char **)(this + 8) = allocation;
    _strncpy(allocation,str,*(int *)(this + 0x10) + 1);
    nameData = *(int *)(this + 8);
    lenOrBracketPos = *(int *)(this + 0x10);
    if (*(char *)(nameData + lenOrBracketPos + -1) == ']') {
      foundBracket = false;
      bracketPos = lenOrBracketPos + -1;
      do {
        bracketPos = bracketPos + -1;
        if (*(char *)(nameData + bracketPos) == '[') {
          foundBracket = true;
        }
        if (bracketPos < 0) {
          if (!foundBracket) goto LAB_97bb0358;
          break;
        }
      } while (!foundBracket);
      arrayIndex = _atoi(nameData + bracketPos + 1);
      clearIdx = bracketPos;
      if (bracketPos < *(int *)(this + 0x10) + 1) {
        do {
          *(undefined1 *)(*(int *)(this + 8) + clearIdx) = 0;
          clearIdx = clearIdx + 1;
        } while (clearIdx < *(int *)(this + 0x10) + 1);
      }
      *(int *)(this + 0x10) = bracketPos;
      lenOrBracketPos = bracketPos;
    }
LAB_97bb0358:
    charIdx = 0;
    *(undefined4 *)(this + 0xc) = 0;
    if (lenOrBracketPos != 0) {
      do {
        chPtr = (char *)(*(int *)(this + 8) + charIdx);
        charIdx = charIdx + 1;
        *(int *)(this + 0xc) = *(int *)(this + 0xc) + (int)*chPtr;
        lenOrBracketPos = lenOrBracketPos + -1;
      } while (lenOrBracketPos != 0);
    }
  }
  return arrayIndex;
}

/* Binding__RemoveNameBackToChar @ 0x97bb03a8 (132 bytes) */
int Binding__RemoveNameBackToChar(this, stopChar)
  unsigned char * this;
  int stopChar;
{
  int newLen;
  char *chPtr;
  bool found;
  int scanPos;
  int charIdx;
  
  scanPos = *(int *)(this + 0x10);
  found = false;
  if (-1 < scanPos) {
    do {
      if (*(char *)(*(int *)(this + 8) + scanPos) == stopChar) {
        found = true;
      }
      *(undefined1 *)(*(int *)(this + 8) + scanPos) = 0;
      scanPos = scanPos + -1;
    } while ((-1 < scanPos) && (!found));
  }
  newLen = scanPos + 1;
  charIdx = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(int *)(this + 0x10) = newLen;
  if (0 < newLen) {
    do {
      chPtr = (char *)(*(int *)(this + 8) + charIdx);
      charIdx = charIdx + 1;
      *(int *)(this + 0xc) = *(int *)(this + 0xc) + (int)*chPtr;
      newLen = newLen + -1;
    } while (newLen != 0);
    return;
  }
  return;
}

/* Binding__GetHash @ 0x97bb042c (20 bytes) */
int Binding__GetHash(this, numBuckets)
  unsigned char * this;
  uint numBuckets;
{
  return *(uint *)(this + 0xc) - (*(uint *)(this + 0xc) / numBuckets) * numBuckets;
}

/* Binding__IsClientRequest @ 0x97bb0440 (8 bytes) */
int Binding__IsClientRequest(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 0x2c);
}

/* Binding__SetClientRequest @ 0x97bb0448 (8 bytes) */
int Binding__SetClientRequest(this, isClientRequest)
  unsigned char * this;
  undefined4 isClientRequest;
{
  *(undefined4 *)(this + 0x2c) = isClientRequest;
  return;
}

/* Binding__IsBuiltIn @ 0x97bb0450 (8 bytes) */
int Binding__IsBuiltIn(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 0x30);
}

/* Binding__SetBuiltIn @ 0x97bb0458 (8 bytes) */
int Binding__SetBuiltIn(this, isBuiltIn)
  unsigned char * this;
  undefined4 isBuiltIn;
{
  *(undefined4 *)(this + 0x30) = isBuiltIn;
  return;
}

