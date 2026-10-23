#include "decls.h"

/* _PPEmulatorCreate @ 0x97b7bc5c (56 bytes) */
int _PPEmulatorCreate()
{
  undefined4 emulator;
  
  emulator = _malloc(0xe00);
  ((int (*)())_PPEmulatorInit)(emulator);
  return emulator;
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
  undefined4 sharedState;
  undefined4 interpreterCreateResult;
  
  _memset(emulator,0,0xdf4);
  sharedState = _malloc(0x1010);
  *(undefined4 *)(emulator + 0xd84) = sharedState;
  _memset(sharedState,0,0x1010);
  ((double (*)())_PPCConstantsAndScratchInitialise)(emulator);
  interpreterCreateResult = _InterpreterCreate();
  *(undefined4 *)(emulator + 0xdf0) = interpreterCreateResult;
  return _InterpreterAttachEmulatorContext(interpreterCreateResult,emulator);
}

/* _PPParserCreate @ 0x97b7bd24 (96 bytes) */
int _PPParserCreate(owner)
  undefined4 owner;
{
  int parser;
  undefined4 ppParserScopeCreateResult;
  
  parser = _calloc(0x490,1);
  *(undefined4 *)(parser + 0x48c) = owner;
  *(undefined4 *)(parser + 0x34) = 0xffffffff;
  *(undefined4 *)(parser + 0x38) = 0xffffffff;
  ppParserScopeCreateResult = ((int (*)())_PPParserScopeCreate)(parser);
  ((int (*)())_PPParserAddScope)(parser,ppParserScopeCreateResult);
  return parser;
}

/* _PPParserScopeCreate @ 0x97b7bd84 (408 bytes) */
int _PPParserScopeCreate(parser)
  undefined4 parser;
{
  undefined4 scope;
  int macro;
  undefined4 preprocessedBody;
  undefined1 mvmultBody [96];
  undefined1 tmvmultBody [120];
  
  _memcpy(mvmultBody,
          "DP4 dst.x, mat[0], vec;\nDP4 dst.y, mat[1], vec;\nDP4 dst.z, mat[2], vec;\nDP4 dst.w, mat[3], vec;"
          ,0x60);
  _memcpy(tmvmultBody,
          "MUL tmp, mat[0], vec.x;\nMAD tmp, mat[1], vec.y, tmp;\nMAD tmp, mat[2], vec.z, tmp;\nMAD dst, mat[3], vec.w, tmp;\n"
          ,0x70);
  scope = _calloc(0x24,1);
  macro = ((int (*)())_PPParserMacroCreate)();
  ((int (*)())_PPParserMacroSetSearchString)(parser,macro,"MVMULT",6);
  ((int (*)())_PPParserMacroSetParamStringsCount)(macro,3);
  ((int (*)())_PPParserMacroSetParamString)(macro,0,"dst");
  ((int (*)())_PPParserMacroSetParamString)(macro,1,"mat");
  ((int (*)())_PPParserMacroSetParamString)(macro,2,"vec");
  preprocessedBody = ((int (*)())_PPParserPreprocessString)(parser,mvmultBody,0);
  *(undefined4 *)(macro + 4) = preprocessedBody;
  ((int (*)())_PPParserScopeAddMacro)(scope,macro);
  macro = ((int (*)())_PPParserMacroCreate)();
  ((int (*)())_PPParserMacroSetSearchString)(parser,macro,"TMVMULT",7);
  ((int (*)())_PPParserMacroSetParamStringsCount)(macro,4);
  ((int (*)())_PPParserMacroSetParamString)(macro,0,"dst");
  ((int (*)())_PPParserMacroSetParamString)(macro,1,"mat");
  ((int (*)())_PPParserMacroSetParamString)(macro,2,"vec");
  ((int (*)())_PPParserMacroSetParamString)(macro,3,"tmp");
  preprocessedBody = ((int (*)())_PPParserPreprocessString)(parser,tmvmultBody,0);
  *(undefined4 *)(macro + 4) = preprocessedBody;
  ((int (*)())_PPParserScopeAddMacro)(scope,macro);
  return scope;
}

/* _PPParserMacroCreate @ 0x97b7bf1c (12 bytes) */
int _PPParserMacroCreate()
{
  undefined4 macro;
  
  macro = _calloc(0x20,1);
  return macro;
}

/* _PPParserMacroSetSearchString @ 0x97b7bf28 (116 bytes) */
int _PPParserMacroSetSearchString(parser, macro, searchString, length)
  undefined4 parser;
  int *macro;
  int searchString;
  int length;
{
  int copy;
  
  if (*macro != 0) {
    _free(*macro);
    *macro = 0;
  }
  if (searchString != 0) {
    copy = _malloc(length + 1);
    *macro = copy;
    _memmove(copy,searchString,length);
    *(undefined1 *)(*macro + length) = 0;
  }
  return;
}

/* _PPParserMacroSetParamStringsCount @ 0x97b7bf9c (60 bytes) */
int _PPParserMacroSetParamStringsCount(macro, count)
  int macro;
  undefined4 count;
{
  undefined4 paramArray;
  
  paramArray = _calloc(4,count);
  *(undefined4 *)(macro + 0xc) = paramArray;
  *(undefined4 *)(macro + 8) = count;
  return;
}

/* _PPParserMacroSetParamString @ 0x97b7bfd8 (116 bytes) */
int _PPParserMacroSetParamString(macro, index, paramString)
  int macro;
  int index;
  undefined4 paramString;
{
  int slotOffset;
  int length;
  undefined4 paramCopy;
  int paramArray;
  
  length = _strlen(paramString);
  paramArray = *(int *)(macro + 0xc);
  paramCopy = _malloc(length + 1);
  slotOffset = index * 4;
  *(undefined4 *)(slotOffset + paramArray) = paramCopy;
  _memmove(*(undefined4 *)(slotOffset + *(int *)(macro + 0xc)),paramString,length);
  *(undefined1 *)(*(int *)(slotOffset + *(int *)(macro + 0xc)) + length) = 0;
  return;
}

/* _PPParserPreprocessString @ 0x97b7c04c (2588 bytes) */
int _PPParserPreprocessString(parser, source, keepHeader)
  undefined4 parser;
  int source;
  int keepHeader;
{
  uint curSrcPos;
  uint numState;
  uint lastWasSep;
  uint headerLeft;
  uint srcPos;
  int output;
  byte nextByte;
  char nextCh;
  bool inComment;
  uint curPos;
  undefined1 ch;
  uint length;
  uint outLength;
  uint outLengthPlus1;
  int outPos;
  int nextOutPos;
  uint digitState;
  uint prevSep;
  int charStep;
  int charAdvance;
  uint nextPos;
  uint inPos;
  
  length = _strlen(source);
  if (keepHeader == 0) {
    outLength = 0;
    inPos = 0;
LAB_97b7c0e8:
    prevSep = 1;
  }
  else {
    outLength = 10;
    if (length < 10) {
      outLength = length;
    }
    inPos = outLength;
    if ((((outLength < length) && (nextCh = *(char *)(source + outLength), nextCh != ' ')) && (nextCh != '\t'))
       && (((nextCh != '\n' && (nextCh != '\r')) && (nextCh != '#')))) {
      outLength = outLength + 1;
      goto LAB_97b7c0e8;
    }
    prevSep = 0;
  }
  inComment = false;
  digitState = 0;
joined_r0x97b7c0f8:
  curPos = inPos;
  if (length <= curPos) goto LAB_97b7c6cc;
  charStep = 1;
  if (inComment) {
    if (*(char *)(source + curPos) != '\n') goto code_r0x97b7c67c;
    inPos = curPos + 1;
    goto LAB_97b7c6bc;
  }
  switch(*(undefined1 *)(source + curPos)) {
  case 9:
  case 0x20:
    if ((((prevSep == 0) && (curPos + 1 < length)) &&
        ((nextCh = *(char *)(source + curPos + 1), nextCh != ' ' &&
         (((nextCh != '\t' && (nextCh != '\n')) && (nextCh != '\r')))))) && (nextCh != '#')) {
LAB_97b7c5fc:
      outLength = outLength + 1;
      prevSep = 1;
    }
    goto LAB_97b7c604;
  case 10:
    outLength = outLength + 1;
    nextPos = curPos + 1;
    break;
  default:
    outLength = outLength + 1;
    nextPos = curPos + 1;
    prevSep = 0;
    goto LAB_97b7c664;
  case 0xd:
    outLength = outLength + 1;
    if ((curPos + 1 < length) && (*(char *)(source + curPos + 1) == '\n')) {
      charStep = 2;
    }
    nextPos = curPos + charStep;
    break;
  case 0x23:
    nextPos = curPos + 1;
    inComment = true;
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
    if (prevSep == 0) {
      outLength = outLength + 1;
    }
    outLength = outLength + 1;
    if (((curPos + 1 < length) && (nextCh = *(char *)(source + curPos + 1), nextCh != ' ')) &&
       ((nextCh != '\t' && (((nextCh != '\n' && (nextCh != '\r')) && (nextCh != '#'))))))
    goto LAB_97b7c5fc;
    prevSep = 0;
LAB_97b7c604:
    nextPos = curPos + 1;
    goto LAB_97b7c664;
  case 0x2b:
  case 0x2d:
    if ((prevSep == 0) && (digitState == 0)) {
      outLength = outLength + 1;
    }
    nextPos = curPos + 1;
    outLengthPlus1 = outLength + 1;
    if ((((length <= nextPos) || (nextByte = *(byte *)(source + curPos + 1), nextByte - 0x30 < 10)) ||
        (nextByte == 0x20)) ||
       (((nextByte == 9 || (nextByte == 10)) || ((nextByte == 0xd || ((nextByte == 0x23 || (nextByte == 0x2e)))))))
       ) {
      prevSep = 0;
      inPos = curPos + 1;
      if (nextPos < length) {
        nextCh = *(char *)(source + nextPos);
        while ((nextCh == ' ' || (nextCh == '\t'))) {
          charStep = charStep + 1;
          inPos = curPos + charStep;
          if (length <= inPos) break;
          nextCh = *(char *)(source + inPos);
        }
      }
      digitState = 0;
      outLength = outLengthPlus1;
      if (inPos < length) {
        if (((uint)(*(byte *)(source + inPos) - 0x30) < 10) || (*(byte *)(source + inPos) == 0x2e)) {
          digitState = 1;
        }
        nextByte = *(byte *)(source + inPos);
        if ((((9 < nextByte - 0x30) && (nextByte != 0x2e)) && (nextByte != 10)) &&
           ((nextByte != 0xd && (nextByte != 0x23)))) {
          inPos = curPos + charStep + -1;
        }
      }
      goto joined_r0x97b7c0f8;
    }
    outLength = outLength + 2;
    break;
  case 0x2e:
    if ((curPos + 1 < length) && (*(char *)(source + curPos + 1) == '.')) {
      inPos = outLength;
      if (prevSep == 0) {
        inPos = outLength + 1;
      }
      outLength = inPos + 2;
      if (((((curPos + 2 < length) && (nextCh = *(char *)(source + curPos + 2), nextCh != ' ')) &&
           (nextCh != '\t')) && ((nextCh != '\n' && (nextCh != '\r')))) && (nextCh != '#')) {
        outLength = inPos + 3;
        prevSep = 1;
      }
      else {
        prevSep = 0;
      }
      nextPos = curPos + 2;
      goto LAB_97b7c664;
    }
    if ((prevSep == 0) && (digitState != 1)) {
      outLength = outLength + 1;
    }
    inPos = outLength + 1;
    if (length <= curPos + 1) goto LAB_97b7c64c;
    nextByte = *(byte *)(source + curPos + 1);
    if (nextByte - 0x30 < 10) {
      prevSep = 0;
      digitState = 3;
      outLength = inPos;
      inPos = curPos + 1;
      goto joined_r0x97b7c0f8;
    }
    if ((((nextByte != 0x20) && (nextByte != 9)) && (nextByte != 10)) && ((nextByte != 0xd && (nextByte != 0x23))))
    {
      prevSep = 1;
      outLength = outLength + 2;
      inPos = curPos + 1;
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
    digitState = digitState | prevSep;
  case 0x45:
  case 0x65:
    inPos = outLength + 1;
LAB_97b7c64c:
    prevSep = 0;
    outLength = inPos;
    inPos = curPos + 1;
    goto joined_r0x97b7c0f8;
  }
  prevSep = 1;
LAB_97b7c664:
  digitState = 0;
  inPos = nextPos;
  goto joined_r0x97b7c0f8;
LAB_97b7c6cc:
  if (prevSep == 0) {
    outLength = outLength + 1;
  }
  output = _calloc(outLength + 1,1);
  if (keepHeader == 0) {
    outPos = 0;
    srcPos = 0;
LAB_97b7c774:
    lastWasSep = 1;
  }
  else {
    srcPos = 10;
    if (length < 10) {
      srcPos = length;
    }
    outPos = 0;
    for (headerLeft = srcPos; headerLeft != 0; headerLeft = headerLeft - 1) {
      *(undefined1 *)(output + outPos) = *(undefined1 *)(source + outPos);
      outPos = outPos + 1;
    }
    if (((srcPos < length) && (nextCh = *(char *)(source + srcPos), nextCh != ' ')) &&
       ((nextCh != '\t' && (((nextCh != '\n' && (nextCh != '\r')) && (nextCh != '#')))))) {
      *(undefined1 *)(output + outPos) = 0x20;
      outPos = outPos + 1;
      goto LAB_97b7c774;
    }
    lastWasSep = 0;
  }
  inComment = false;
  numState = 0;
joined_r0x97b7c784:
  curSrcPos = srcPos;
  if (length <= curSrcPos) {
    if (lastWasSep == 0) {
      *(undefined1 *)(output + outPos) = 0x20;
    }
    return output;
  }
  charAdvance = 1;
  if (inComment) {
    if (*(char *)(source + curSrcPos) != '\n') goto code_r0x97b7cd84;
    *(undefined1 *)(output + outPos) = 10;
    srcPos = curSrcPos + 1;
    goto LAB_97b7cdd0;
  }
  ch = *(undefined1 *)(source + curSrcPos);
  nextOutPos = outPos;
  switch(ch) {
  case 9:
  case 0x20:
    if ((((lastWasSep == 0) && (curSrcPos + 1 < length)) &&
        ((nextCh = *(char *)(source + curSrcPos + 1), nextCh != ' ' &&
         (((nextCh != '\t' && (nextCh != '\n')) && (nextCh != '\r')))))) && (nextCh != '#')) {
LAB_97b7ccec:
      lastWasSep = 1;
      *(undefined1 *)(output + outPos) = 0x20;
      nextOutPos = outPos + 1;
    }
    goto LAB_97b7ccfc;
  case 10:
    ch = 10;
    goto LAB_97b7cbd8;
  default:
    *(undefined1 *)(output + outPos) = ch;
    srcPos = curSrcPos + 1;
    nextOutPos = outPos + 1;
    lastWasSep = 0;
    break;
  case 0xd:
    *(undefined1 *)(output + outPos) = 10;
    nextOutPos = outPos + 1;
    if ((curSrcPos + 1 < length) && (*(char *)(source + curSrcPos + 1) == '\n')) {
      charAdvance = 2;
    }
    srcPos = curSrcPos + charAdvance;
    goto LAB_97b7cbe0;
  case 0x23:
    srcPos = curSrcPos + 1;
    inComment = true;
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
    if (lastWasSep == 0) {
      *(undefined1 *)(output + outPos) = 0x20;
      outPos = outPos + 1;
    }
    *(undefined1 *)(output + outPos) = ch;
    outPos = outPos + 1;
    if (((curSrcPos + 1 < length) && (nextCh = *(char *)(source + curSrcPos + 1), nextCh != ' ')) &&
       ((nextCh != '\t' && (((nextCh != '\n' && (nextCh != '\r')) && (nextCh != '#'))))))
    goto LAB_97b7ccec;
    lastWasSep = 0;
    nextOutPos = outPos;
LAB_97b7ccfc:
    srcPos = curSrcPos + 1;
    break;
  case 0x2b:
  case 0x2d:
    if ((lastWasSep == 0) && (numState == 0)) {
      *(undefined1 *)(output + outPos) = 0x20;
      outPos = outPos + 1;
    }
    numState = curSrcPos + 1;
    *(undefined1 *)(output + outPos) = ch;
    outPos = outPos + 1;
    if ((((length <= numState) || (nextByte = *(byte *)(source + curSrcPos + 1), nextByte - 0x30 < 10)) ||
        (nextByte == 0x20)) ||
       (((nextByte == 9 || (nextByte == 10)) || ((nextByte == 0xd || ((nextByte == 0x23 || (nextByte == 0x2e)))))))
       ) {
      lastWasSep = 0;
      srcPos = curSrcPos + 1;
      if (numState < length) {
        nextCh = *(char *)(source + numState);
        while ((nextCh == ' ' || (nextCh == '\t'))) {
          charAdvance = charAdvance + 1;
          srcPos = curSrcPos + charAdvance;
          if (length <= srcPos) break;
          nextCh = *(char *)(source + srcPos);
        }
      }
      numState = 0;
      if (srcPos < length) {
        if (((uint)(*(byte *)(source + srcPos) - 0x30) < 10) || (*(byte *)(source + srcPos) == 0x2e)) {
          numState = 1;
        }
        nextByte = *(byte *)(source + srcPos);
        if ((((9 < nextByte - 0x30) && (nextByte != 0x2e)) && (nextByte != 10)) &&
           ((nextByte != 0xd && (nextByte != 0x23)))) {
          srcPos = curSrcPos + charAdvance + -1;
        }
      }
      goto joined_r0x97b7c784;
    }
    ch = 0x20;
LAB_97b7cbd8:
    srcPos = curSrcPos + 1;
    *(undefined1 *)(output + outPos) = ch;
    nextOutPos = outPos + 1;
LAB_97b7cbe0:
    lastWasSep = 1;
    break;
  case 0x2e:
    if ((length <= curSrcPos + 1) || (*(char *)(source + curSrcPos + 1) != '.')) {
      if ((lastWasSep == 0) && (numState != 1)) {
        *(undefined1 *)(output + outPos) = 0x20;
        outPos = outPos + 1;
      }
      *(undefined1 *)(output + outPos) = 0x2e;
      charAdvance = outPos + 1;
      if (length <= curSrcPos + 1) goto LAB_97b7cd54;
      nextByte = *(byte *)(source + curSrcPos + 1);
      if (nextByte - 0x30 < 10) {
        lastWasSep = 0;
        numState = 3;
        outPos = charAdvance;
        srcPos = curSrcPos + 1;
        goto joined_r0x97b7c784;
      }
      if ((((nextByte != 0x20) && (nextByte != 9)) && (nextByte != 10)) &&
         ((nextByte != 0xd && (nextByte != 0x23)))) {
        *(undefined1 *)(output + charAdvance) = 0x20;
        lastWasSep = 1;
        outPos = outPos + 2;
        srcPos = curSrcPos + 1;
        goto joined_r0x97b7c784;
      }
      goto LAB_97b7cd54;
    }
    if (lastWasSep == 0) {
      *(undefined1 *)(output + outPos) = 0x20;
      outPos = outPos + 1;
    }
    *(undefined1 *)(output + outPos) = 0x2e;
    *(undefined1 *)(output + outPos + 1) = 0x2e;
    nextOutPos = outPos + 2;
    if (((((curSrcPos + 2 < length) && (nextCh = *(char *)(source + curSrcPos + 2), nextCh != ' ')) &&
         (nextCh != '\t')) && ((nextCh != '\n' && (nextCh != '\r')))) && (nextCh != '#')) {
      lastWasSep = 1;
      *(undefined1 *)(output + nextOutPos) = 0x20;
      nextOutPos = outPos + 3;
    }
    else {
      lastWasSep = 0;
    }
    srcPos = curSrcPos + 2;
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
    *(undefined1 *)(output + outPos) = ch;
    numState = numState | lastWasSep;
    charAdvance = outPos + 1;
    goto LAB_97b7cd54;
  case 0x45:
  case 0x65:
    *(undefined1 *)(output + outPos) = ch;
    charAdvance = outPos + 1;
LAB_97b7cd54:
    lastWasSep = 0;
    outPos = charAdvance;
    srcPos = curSrcPos + 1;
    goto joined_r0x97b7c784;
  }
  numState = 0;
  outPos = nextOutPos;
  goto joined_r0x97b7c784;
code_r0x97b7cd84:
  srcPos = curSrcPos + 1;
  if (*(char *)(source + curSrcPos) == '\r') {
    *(undefined1 *)(output + outPos) = 10;
    if ((curSrcPos + 1 < length) && (*(char *)(source + curSrcPos + 1) == '\n')) {
      charAdvance = 2;
    }
    srcPos = curSrcPos + charAdvance;
LAB_97b7cdd0:
    inComment = false;
    outPos = outPos + 1;
  }
  goto joined_r0x97b7c784;
code_r0x97b7c67c:
  inPos = curPos + 1;
  if (*(char *)(source + curPos) == '\r') {
    if ((curPos + 1 < length) && (*(char *)(source + curPos + 1) == '\n')) {
      charStep = 2;
    }
    inPos = curPos + charStep;
LAB_97b7c6bc:
    inComment = false;
    outLength = outLength + 1;
  }
  goto joined_r0x97b7c0f8;
}

/* _PPParserScopeAddMacro @ 0x97b7ce10 (52 bytes) */
int _PPParserScopeAddMacro(scope, macro)
  int scope;
  int macro;
{
  int firstMacro;
  
  firstMacro = *(int *)(scope + 8);
  if (*(int *)(scope + 8) == 0) {
    firstMacro = macro;
  }
  *(int *)(scope + 8) = firstMacro;
  if (*(int *)(scope + 0xc) != 0) {
    *(int *)(*(int *)(scope + 0xc) + 0x1c) = macro;
    *(undefined4 *)(macro + 0x18) = *(undefined4 *)(scope + 0xc);
  }
  *(int *)(scope + 0xc) = macro;
  return;
}

/* _PPParserAddScope @ 0x97b7ce44 (60 bytes) */
int _PPParserAddScope(parser, scope)
  int parser;
  int scope;
{
  int firstScope;
  
  firstScope = *(int *)(parser + 0x448);
  if (*(int *)(parser + 0x448) == 0) {
    firstScope = scope;
  }
  *(int *)(parser + 0x448) = firstScope;
  if (*(int *)(parser + 0x44c) != 0) {
    *(int *)(*(int *)(parser + 0x44c) + 0x20) = scope;
    *(undefined4 *)(scope + 0x1c) = *(undefined4 *)(parser + 0x44c);
  }
  *(int *)(parser + 0x44c) = scope;
  *(undefined4 *)(scope + 0x18) = *(undefined4 *)(parser + 0x1c);
  return;
}

/* _PPParserInit @ 0x97b7ce80 (4 bytes) */
int _PPParserInit()
{
  return;
}

/* _PPParserAttachString @ 0x97b7ce84 (228 bytes) */
int _PPParserAttachString(parser, text, preprocess)
  int *parser;
  int text;
  int preprocess;
{
  int preprocessedText;
  int copy;
  int length;
  int charsLeft;
  int scanIndex;
  
  if (*parser == 0) {
    if (text != 0) {
      if (preprocess == 0) {
        length = _strlen(text);
        copy = _calloc(length + 1,1);
        *parser = copy;
        _memmove(copy,text,length);
      }
      else {
        preprocessedText = ((int (*)())_PPParserPreprocessString)(parser,text,1);
        *parser = preprocessedText;
      }
      charsLeft = _strlen(*parser);
      scanIndex = 0;
      parser[2] = 0;
      parser[1] = charsLeft;
      if (charsLeft != 0) {
        do {
          if (*(char *)(*parser + scanIndex) == '\n') {
            parser[2] = parser[2] + 1;
          }
          scanIndex = scanIndex + 1;
          charsLeft = charsLeft + -1;
        } while (charsLeft != 0);
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
  int stream;
  undefined4 chunkList;
  
  stream = _calloc(0x34,1);
  chunkList = ((int (*)())_PPStreamChunkListCreate)();
  *(undefined4 *)(stream + 4) = chunkList;
  chunkList = ((int (*)())_PPStreamChunkListCreate)();
  *(undefined4 *)(stream + 8) = chunkList;
  chunkList = ((int (*)())_PPStreamChunkListCreate)();
  *(undefined4 *)(stream + 0xc) = chunkList;
  chunkList = ((int (*)())_PPStreamChunkListCreate)();
  *(undefined4 *)(stream + 0x10) = chunkList;
  chunkList = ((int (*)())_PPStreamChunkListCreate)();
  *(undefined4 *)(stream + 0x14) = chunkList;
  chunkList = ((int (*)())_PPStreamChunkListCreate)();
  *(undefined4 *)(stream + 0x18) = chunkList;
  chunkList = ((int (*)())_PPStreamChunkListCreate)();
  *(undefined4 *)(stream + 0x1c) = chunkList;
  chunkList = ((int (*)())_PPStreamChunkListCreate)();
  *(undefined4 *)(stream + 0x20) = chunkList;
  chunkList = ((int (*)())_PPStreamChunkListCreate)();
  *(undefined4 *)(stream + 0x24) = chunkList;
  chunkList = ((int (*)())_PPStreamChunkListCreate)();
  *(undefined4 *)(stream + 0x2c) = chunkList;
  chunkList = ((int (*)())_PPStreamChunkListCreate)();
  *(undefined4 *)(stream + 0x28) = chunkList;
  chunkList = ((int (*)())_PPStreamChunkListCreate)();
  *(undefined4 *)(stream + 0x30) = chunkList;
  return stream;
}

/* _PPStreamChunkListCreate @ 0x97b7d000 (12 bytes) */
int _PPStreamChunkListCreate()
{
  undefined4 chunkList;
  
  chunkList = _calloc(0xc,1);
  return chunkList;
}

/* _PPParserAttachStream @ 0x97b7d00c (100 bytes) */
int _PPParserAttachStream(parser, stream)
  int parser;
  undefined4 stream;
{
  int scope;
  
  scope = *(int *)(parser + 0x448);
  if (*(int *)(parser + 0x1c) != 0) {
    _PPStreamFree(*(int *)(parser + 0x1c));
  }
  *(undefined4 *)(parser + 0x1c) = stream;
  for (; scope != 0; scope = *(int *)(scope + 0x20)) {
    ((int (*)())_PPParserScopeAttachStream)(scope,stream);
  }
  return;
}

/* _PPParserScopeAttachStream @ 0x97b7d070 (36 bytes) */
int _PPParserScopeAttachStream(scope, stream)
  int *scope;
  int stream;
{
  int identifier;
  
  identifier = *scope;
  scope[6] = stream;
  if (identifier != 0) {
    do {
      *(int *)(identifier + 0x18) = stream;
      identifier = *(int *)(identifier + 0x20);
    } while (identifier != 0);
    return;
  }
  return;
}

/* _PPParserParse @ 0x97b7d094 (296 bytes) */
int _PPParserParse(parser)
  int parser;
{
  bool succeeded;
  int branchError;
  int status;
  
  status = 0;
  if ((*(byte *)(parser + 0x441) & 2) == 0) {
    status = ((int (*)())_PPParserParseVersion)(parser);
  }
  while (status == 0) {
    status = ((int (*)())_PPParserParseOption)(parser);
  }
  if (status == 3) {
    do {
      status = ((int (*)())_PPParserParseStatement)(parser);
    } while (status == 0);
  }
  succeeded = false;
  if ((*(byte *)(parser + 0x441) & 2) == 0) {
    if (status == 6) {
      status = ((int (*)())_PPParserParseEnd)(parser);
    }
    if (status == 1) {
      status = 0x2d;
    }
    if (status != 0) goto LAB_97b7d180;
    succeeded = true;
    if (((*(uint *)(parser + 0x48c) & 0x10) != 0) &&
       (branchError = _PPStreamResolveBranches(*(undefined4 *)(parser + 0x1c)), branchError != 0)) {
      status = 0x1b;
      goto LAB_97b7d170;
    }
  }
  else if (status == 1) {
    status = 0;
LAB_97b7d170:
    succeeded = status == 0;
  }
  if (succeeded) {
    return 0;
  }
LAB_97b7d180:
  branchError = 2;
  if (status != 2) {
    _PPParserBuildErrorString(parser,status,0);
    branchError = status;
  }
  return branchError;
}

/* _PPParserParseVersion @ 0x97b7d1bc (204 bytes) */
int _PPParserParseVersion(parser)
  int parser;
{
  int compareResult;
  undefined4 status;
  int part;
  undefined1 headerToken [264];
  
  part = ((int (*)())_PPParserGetPart)(parser,headerToken,0);
  status = 4;
  if (part != 0) {
    if ((*(uint *)(parser + 0x48c) & 2) == 0) {
      compareResult = _memcmp(headerToken,"!!ARBvp1.0",0xb);
      if (compareResult != 0) {
        return 4;
      }
      *(undefined4 *)(parser + 0x48c) = 0;
      **(undefined4 **)(parser + 0x1c) = 0x8620;
    }
    else {
      compareResult = _memcmp(headerToken,"!!ARBfp1.0",0xb);
      if (compareResult != 0) {
        return 4;
      }
      *(undefined4 *)(parser + 0x48c) = 2;
      **(undefined4 **)(parser + 0x1c) = 0x8804;
    }
    status = 0;
  }
  return status;
}

/* _PPParserGetPart @ 0x97b7d288 (368 bytes) */
int _PPParserGetPart(parser, partBuf, expandMacros)
  int *parser;
  int partBuf;
  int expandMacros;
{
  int macro;
  int getCharStatus;
  int savedPos;
  int savedLine;
  int newTextLength;
  int replaceLength;
  int newText;
  uint tokenLength;
  undefined1 replaceBuf [260];
  
  savedPos = parser[3];
  savedLine = parser[4];
  tokenLength = 0;
  do {
    getCharStatus = ((int (*)())_PPParserGetCharacter)(parser,partBuf + tokenLength);
    if ((getCharStatus != 0) || (*(char *)(partBuf + tokenLength) == ' ')) break;
    tokenLength = tokenLength + 1;
  } while (tokenLength < 0xff);
  *(undefined1 *)(partBuf + tokenLength) = 0;
  if ((tokenLength == 0) || (tokenLength == 0xff)) {
    tokenLength = 0;
  }
  else if (((expandMacros != 0) && (macro = ((int (*)())_PPParserScopeFindMacro)(parser[0x113],partBuf), macro != 0))
          && (*(int *)(macro + 8) == 0)) {
    replaceLength = _PPParserMacroGetReplaceString(macro,parser[0x123],0,replaceBuf);
    newTextLength = (parser[1] + replaceLength) - tokenLength;
    newText = _calloc(newTextLength,1);
    _memmove(newText,*parser,savedPos);
    _memmove(newText + savedPos,replaceBuf,replaceLength);
    _memmove(newText + savedPos + replaceLength,*parser + parser[3],parser[1] - parser[3]);
    _free(*parser);
    parser[1] = newTextLength + -1;
    *parser = newText;
    parser[3] = savedPos;
    parser[4] = savedLine;
    tokenLength = ((int (*)())_PPParserGetPart)(parser,partBuf,0);
  }
  return tokenLength;
}

/* _PPParserGetCharacter @ 0x97b7d3f8 (144 bytes) */
int _PPParserGetCharacter(parser, outChar)
  int *parser;
  char *outChar;
{
  bool sawNewline;
  undefined4 atEnd;
  int pos;
  
  sawNewline = false;
  pos = parser[3];
  atEnd = 1;
  if (pos != parser[1]) {
    while( true ) {
      *outChar = *(char *)(*parser + pos);
      pos = parser[3] + 1;
      parser[3] = pos;
      if (*outChar != '\n') break;
      parser[4] = parser[4] + 1;
      if (pos == parser[1]) {
        *outChar = ' ';
        break;
      }
      sawNewline = true;
    }
    if (sawNewline) {
      *outChar = ' ';
      parser[3] = parser[3] + -1;
    }
    atEnd = 0;
  }
  return atEnd;
}

/* _PPParserParseOption @ 0x97b7d488 (184 bytes) */
int _PPParserParseOption(parser)
  undefined4 parser;
{
  int compareResult;
  int part;
  int status;
  char optionToken [264];
  
  part = ((int (*)())_PPParserGetPart)(parser,optionToken,0);
  status = 1;
  if (part != 0) {
    compareResult = _memcmp(optionToken,"OPTION",7);
    if (compareResult == 0) {
      status = ((int (*)())_PPParserParseOptionIdentifier)(parser);
      if (status == 0) {
        part = ((int (*)())_PPParserGetPart)(parser,optionToken,0);
        status = 0x2d;
        if ((part != 0) && (status = 0x1e, optionToken[0] == ';')) {
          status = 0;
        }
      }
    }
    else {
      ((int (*)())_PPParserReturnPart)(parser);
      status = 3;
    }
  }
  return status;
}

/* _PPParserParseOptionIdentifier @ 0x97b7d540 (916 bytes) */
int _PPParserParseOptionIdentifier(parser)
  int parser;
{
  int compareResult;
  int part;
  undefined4 stream;
  undefined4 optionId;
  undefined1 optionName [256];
  undefined4 bindingWord;
  uint bindingIndex;
  
  part = ((int (*)())_PPParserGetPart)(parser,optionName,0);
  if (part == 0) {
    return 0x2d;
  }
  if ((*(uint *)(parser + 0x48c) & 2) == 0) {
    compareResult = _memcmp(optionName,"ARB_position_invariant",0x17);
    if (compareResult == 0) {
      ((int (*)())_PPStreamAddOption)(*(undefined4 *)(parser + 0x1c),0);
      bindingIndex = *(uint *)(parser + 0x24) & 0xffff;
      *(uint *)(parser + 0x24) = *(uint *)(parser + 0x24) + 1;
      bindingWord = 0x10000;
      ((int (*)())_PPStreamAddAttribBinding)(*(undefined4 *)(parser + 0x1c),&bindingWord);
      *(byte *)(parser + 0x442) = *(byte *)(parser + 0x442) | 1;
      return 0;
    }
    compareResult = _memcmp(optionName,"NV_vertex_program2",0x13);
    if (compareResult == 0) {
      stream = *(undefined4 *)(parser + 0x1c);
      *(undefined4 *)(parser + 0x48c) = 0x31;
      optionId = 10;
      goto LAB_97b7d8b8;
    }
    compareResult = _memcmp(optionName,"NV_vertex_program3",0x13);
    if (compareResult == 0) {
      stream = *(undefined4 *)(parser + 0x1c);
      *(undefined4 *)(parser + 0x48c) = 0x34;
      optionId = 0xb;
      goto LAB_97b7d8b8;
    }
  }
  else {
    compareResult = _memcmp(optionName,"ARB_fog_exp",0xc);
    if (compareResult == 0) {
      if (1 < *(byte *)(parser + 0x443)) {
        return 0x27;
      }
      stream = *(undefined4 *)(parser + 0x1c);
      *(undefined1 *)(parser + 0x443) = 1;
      optionId = 1;
      goto LAB_97b7d8b8;
    }
    compareResult = _memcmp(optionName,"ARB_fog_exp2",0xd);
    if (compareResult == 0) {
      if ((*(char *)(parser + 0x443) != '\0') && (*(char *)(parser + 0x443) != '\x02')) {
        return 0x27;
      }
      stream = *(undefined4 *)(parser + 0x1c);
      *(undefined1 *)(parser + 0x443) = 2;
      optionId = 2;
      goto LAB_97b7d8b8;
    }
    compareResult = _memcmp(optionName,"ARB_fog_linear",0xf);
    if (compareResult == 0) {
      if ((*(char *)(parser + 0x443) != '\0') && (*(char *)(parser + 0x443) != '\x03')) {
        return 0x27;
      }
      stream = *(undefined4 *)(parser + 0x1c);
      *(undefined1 *)(parser + 0x443) = 3;
      optionId = 3;
      goto LAB_97b7d8b8;
    }
    compareResult = _memcmp(optionName,"ARB_precision_hint_fastest",0x1b);
    if (compareResult == 0) {
      if ((*(char *)(parser + 0x444) != '\0') && (*(char *)(parser + 0x444) != '\x04')) {
        return 0x27;
      }
      stream = *(undefined4 *)(parser + 0x1c);
      *(undefined1 *)(parser + 0x444) = 4;
      optionId = 4;
      goto LAB_97b7d8b8;
    }
    compareResult = _memcmp(optionName,"ARB_precision_hint_nicest",0x1a);
    if (compareResult == 0) {
      if ((*(char *)(parser + 0x444) != '\0') && (*(char *)(parser + 0x444) != '\x05')) {
        return 0x27;
      }
      stream = *(undefined4 *)(parser + 0x1c);
      *(undefined1 *)(parser + 0x444) = 5;
      optionId = 5;
      goto LAB_97b7d8b8;
    }
    compareResult = _memcmp(optionName,"NV_fragment_program",0x14);
    if (compareResult == 0) {
      stream = *(undefined4 *)(parser + 0x1c);
      *(undefined4 *)(parser + 0x48c) = 0x33;
      optionId = 8;
      goto LAB_97b7d8b8;
    }
    compareResult = _memcmp(optionName,"NV_fragment_program2",0x15);
    if (compareResult == 0) {
      *(undefined4 *)(parser + 0x48c) = 0x36;
      ((int (*)())_PPStreamAddOption)(*(undefined4 *)(parser + 0x1c),9);
      _PPParserDeclareNVAddressRegisters(parser);
      return 0;
    }
    compareResult = _memcmp(optionName,"ARB_fragment_program_shadow",0x1c);
    if (compareResult == 0) {
      stream = *(undefined4 *)(parser + 0x1c);
      optionId = 0xd;
      goto LAB_97b7d8b8;
    }
    compareResult = _memcmp(optionName,"ARB_draw_buffers",0x11);
    if (compareResult == 0) {
      stream = *(undefined4 *)(parser + 0x1c);
      *(undefined1 *)(parser + 0x445) = 1;
      optionId = 0xc;
      goto LAB_97b7d8b8;
    }
  }
  compareResult = _memcmp(optionName,"APPLE_no_runtime_compile",0x19);
  if (compareResult == 0) {
    stream = *(undefined4 *)(parser + 0x1c);
    optionId = 6;
  }
  else {
    compareResult = _memcmp(optionName,"APPLE_no_altivec",0x11);
    if (compareResult != 0) {
      return 5;
    }
    stream = *(undefined4 *)(parser + 0x1c);
    optionId = 7;
  }
LAB_97b7d8b8:
  ((int (*)())_PPStreamAddOption)(stream,optionId);
  return 0;
}

/* _PPStreamAddOption @ 0x97b7d8d4 (80 bytes) */
int _PPStreamAddOption(stream, optionId)
  int stream;
  undefined4 optionId;
{
  undefined1 *optionChunk;
  undefined4 optionList;
  
  optionChunk = (undefined1 *)_calloc(0x14,1);
  optionList = *(undefined4 *)(stream + 0x30);
  *optionChunk = 7;
  optionChunk[0xf] = (undefined1)optionId;
  return ((int (*)())_PPStreamChunkListAddChunk)(optionList,optionChunk);
}

/* _PPStreamChunkListAddChunk @ 0x97b7d924 (72 bytes) */
int _PPStreamChunkListAddChunk(chunkList, chunk)
  int *chunkList;
  int chunk;
{
  if (*chunkList == 0) {
    *chunkList = chunk;
    *(undefined4 *)(chunk + 4) = 0;
  }
  if (chunkList[1] != 0) {
    *(int *)(chunkList[1] + 8) = chunk;
    *(int *)(chunk + 4) = chunkList[1];
  }
  *(undefined4 *)(chunk + 8) = 0;
  chunkList[1] = chunk;
  chunkList[2] = chunkList[2] + 1;
  return;
}

/* _PPStreamAddAttribBinding @ 0x97b7d96c (92 bytes) */
int _PPStreamAddAttribBinding(stream, binding)
  int stream;
  undefined4 *binding;
{
  undefined1 *bindingChunk;
  undefined4 bindingList;
  undefined4 bindingWord0;
  undefined4 bindingWord1;
  
  bindingChunk = (undefined1 *)_calloc(0x14,1);
  bindingWord1 = binding[1];
  bindingList = *(undefined4 *)(stream + 0x18);
  bindingWord0 = *binding;
  *bindingChunk = 2;
  *(undefined4 *)(bindingChunk + 0xc) = bindingWord0;
  *(undefined4 *)(bindingChunk + 0x10) = bindingWord1;
  return ((int (*)())_PPStreamChunkListAddChunk)(bindingList,bindingChunk);
}

/* _PPParserReturnPart @ 0x97b7d9c8 (132 bytes) */
int _PPParserReturnPart(parser)
  undefined4 parser;
{
  int status;
  int partLength;
  char ch [20];
  
  status = ((int (*)())_PPParserReturnCharacter)(parser,ch);
  partLength = 0;
  if (status == 0) {
    partLength = 0;
    while (status = ((int (*)())_PPParserReturnCharacter)(parser,ch), status == 0) {
      if (ch[0] == ' ') {
        ((int (*)())_PPParserGetCharacter)(parser,ch);
        return partLength;
      }
      partLength = partLength + 1;
    }
  }
  return partLength;
}

/* _PPParserReturnCharacter @ 0x97b7da4c (144 bytes) */
int _PPParserReturnCharacter(parser, outChar)
  int *parser;
  char *outChar;
{
  bool sawNewline;
  int pos;
  undefined4 atStart;
  
  pos = parser[3];
  sawNewline = false;
  atStart = 1;
  if (pos != 0) {
    while( true ) {
      *outChar = *(char *)(*parser + pos + -1);
      pos = parser[3] + -1;
      parser[3] = pos;
      if (*outChar != '\n') break;
      parser[4] = parser[4] + -1;
      if (pos == 0) {
        *outChar = ' ';
        break;
      }
      sawNewline = true;
    }
    if (sawNewline) {
      *outChar = ' ';
      parser[3] = parser[3] + 1;
    }
    atStart = 0;
  }
  return atStart;
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

