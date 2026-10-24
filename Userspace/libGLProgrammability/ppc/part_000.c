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
int dyld_stub_binding_helper(bindingInfo)
  undefined4 bindingInfo;
{
                    
                    
  (*dyld_lazy_symbol_binding_entry_point)(bindingInfo);
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
  int keywordCompare;
  int longShortMode;
  int optionCompare;
  int partLengthOrStatus;
  int ppParserExpandMacroResult;
  int ppParserScopeFindMacroResult;
  int ppParserParseOperationResult;
  int length;
  int compareResult;
  int opcode;
  int declStatusOrMnemonic;
  int length2;
  undefined4 precision;
  undefined4 updateCC;
  undefined4 saturate;
  undefined4 ccRegister;
  undefined4 leftoverR9;
  uint profile;
  int tableTier;
  int *opsList;
  undefined1 partBuf [256];
  char suffixedName [20];
  
  partLengthOrStatus = ((int (*)())_PPParserGetPart)(parser,partBuf,0);
  longShortMode = 0;
  if (partLengthOrStatus == 0) {
    return 1;
  }
  if ((*(uint *)(parser + 0x48c) & 0x22) != 0) {
    compareResult = _memcmp(partBuf,"LONG",5);
    if (compareResult == 0) {
      longShortMode = 1;
    }
    else {
      compareResult = _memcmp(partBuf,"SHORT",6);
      if (compareResult != 0) goto LAB_97b7db80;
      longShortMode = 2;
    }
    partLengthOrStatus = ((int (*)())_PPParserGetPart)(parser,partBuf,0);
    if (partLengthOrStatus == 0) {
      return 1;
    }
  }
LAB_97b7db80:
  compareResult = _memcmp(partBuf,"TEMP",5);
  if (compareResult == 0) {
    declStatusOrMnemonic = _PPParserParseTempDeclaration(parser,longShortMode);
  }
  else {
    compareResult = _memcmp(partBuf,"OUTPUT",7);
    if (compareResult == 0) {
      declStatusOrMnemonic = ((int (*)())_PPParserParseOutputDeclaration)(parser,longShortMode);
    }
    else {
      declStatusOrMnemonic = 0x2a;
      if (longShortMode == 0) {
        profile = *(uint *)(parser + 0x48c);
        if (((profile & 2) == 0) && (keywordCompare = _memcmp(partBuf,"ADDRESS",8), keywordCompare == 0)) {
          declStatusOrMnemonic = _PPParserParseAddressDeclaration(parser);
        }
        else {
          keywordCompare = _memcmp(partBuf,"PARAM",6);
          if (keywordCompare == 0) {
            declStatusOrMnemonic = ((int (*)())_PPParserParseParameterDeclaration)(parser);
          }
          else {
            keywordCompare = _memcmp(partBuf,"ATTRIB",7);
            if (keywordCompare == 0) {
              declStatusOrMnemonic = ((int (*)())_PPParserParseAttributeDeclaration)(parser);
            }
            else {
              keywordCompare = _memcmp(partBuf,"ALIAS",6);
              if (keywordCompare == 0) {
                declStatusOrMnemonic = _PPParserParseAliasDeclaration(parser);
              }
              else {
                keywordCompare = _memcmp(partBuf,"MACRO",6);
                if (keywordCompare == 0) {
                  declStatusOrMnemonic = _PPParserParseMacroDeclaration(parser);
                }
                else {
                  keywordCompare = _memcmp(partBuf,"BLOCK",6);
                  if (keywordCompare != 0) {
                    if ((profile & 2) == 0) {
                      opsList = &_OpsList_ARBvp10;
                    }
                    else {
                      opsList = &_OpsList_ARBfp10;
                    }
                    tableTier = 0;
                    do {
                      declStatusOrMnemonic = *opsList;
                      if (declStatusOrMnemonic != 0) {
                        do {
                          compareResult = _strcmp(partBuf,declStatusOrMnemonic);
                          if (compareResult == 0) {
                            opcode = opsList[1];
                            precision = 0;
                            goto LAB_97b7e2b0;
                          }
                          profile = *(uint *)(parser + 0x48c);
                          if ((profile & 0x10) != 0) {
                            _sprintf(suffixedName,"%sC",*opsList);
                            compareResult = _strcmp(partBuf,suffixedName);
                            if (compareResult != 0) {
                              profile = *(uint *)(parser + 0x48c);
                              if (profile != 0x34) goto LAB_97b7ddc8;
                              _sprintf(suffixedName,"%sC0",*opsList);
                              compareResult = _strcmp(partBuf,suffixedName);
                              if (compareResult == 0) goto LAB_97b7e228;
                              _sprintf(suffixedName,"%sC1",*opsList);
                              compareResult = _strcmp(partBuf,suffixedName);
                              if (compareResult != 0) {
                                profile = *(uint *)(parser + 0x48c);
                                goto LAB_97b7ddc8;
                              }
                              opcode = opsList[1];
                              saturate = 0;
LAB_97b7e28c:
                              updateCC = 1;
                              precision = 0;
                              ccRegister = 1;
                              goto LAB_97b7e334;
                            }
LAB_97b7e228:
                            opcode = opsList[1];
                            precision = 0;
                            goto LAB_97b7e234;
                          }
LAB_97b7ddc8:
                          if ((profile & 2) != 0) {
                            _sprintf(suffixedName,"%s_SAT",*opsList);
                            compareResult = _strcmp(partBuf,suffixedName);
                            if (compareResult == 0) {
                              opcode = opsList[1];
                              precision = 0;
                              goto LAB_97b7e260;
                            }
                            if ((*(uint *)(parser + 0x48c) & 0x10) == 0) goto LAB_97b7e11c;
                            _sprintf(suffixedName,"%sC_SAT",*opsList);
                            compareResult = _strcmp(partBuf,suffixedName);
                            if (compareResult == 0) {
LAB_97b7e268:
                              opcode = opsList[1];
                              precision = 0;
                              goto LAB_97b7e328;
                            }
                            if (*(int *)(parser + 0x48c) == 0x34) {
                              _sprintf(suffixedName,"%sC0_SAT",*opsList);
                              compareResult = _strcmp(partBuf,suffixedName);
                              if (compareResult == 0) goto LAB_97b7e268;
                              _sprintf(suffixedName,"%sC1_SAT",*opsList);
                              compareResult = _strcmp(partBuf,suffixedName);
                              if (compareResult == 0) {
                                opcode = opsList[1];
                                saturate = 1;
                                goto LAB_97b7e28c;
                              }
                            }
                            length = _strlen(partBuf);
                            length2 = _strlen(*opsList);
                            if (length == length2 + 1) {
                              _sprintf(suffixedName,"%sR",*opsList);
                              compareResult = _strcmp(partBuf,suffixedName);
                              if (compareResult == 0) {
                                opcode = opsList[1];
                                precision = 1;
                              }
                              else {
                                _sprintf(suffixedName,"%sH",*opsList);
                                compareResult = _strcmp(partBuf,suffixedName);
                                if (compareResult == 0) {
                                  opcode = opsList[1];
                                  precision = 2;
                                }
                                else {
                                  _sprintf(suffixedName,"%sX",*opsList);
                                  compareResult = _strcmp(partBuf,suffixedName);
                                  if (compareResult != 0) goto LAB_97b7e11c;
                                  opcode = opsList[1];
                                  precision = 3;
                                }
                              }
LAB_97b7e2b0:
                              updateCC = 0;
LAB_97b7e2b4:
                              saturate = 0;
                            }
                            else {
                              length = _strlen(partBuf);
                              length2 = _strlen(*opsList);
                              if (length == length2 + 2) {
                                _sprintf(suffixedName,"%sRC",*opsList);
                                compareResult = _strcmp(partBuf,suffixedName);
                                if (compareResult == 0) {
                                  opcode = opsList[1];
                                  precision = 1;
                                }
                                else {
                                  _sprintf(suffixedName,"%sHC",*opsList);
                                  compareResult = _strcmp(partBuf,suffixedName);
                                  if (compareResult == 0) {
                                    opcode = opsList[1];
                                    precision = 2;
                                  }
                                  else {
                                    _sprintf(suffixedName,"%sXC",*opsList);
                                    compareResult = _strcmp(partBuf,suffixedName);
                                    if (compareResult != 0) goto LAB_97b7e11c;
                                    opcode = opsList[1];
                                    precision = 3;
                                  }
                                }
LAB_97b7e234:
                                updateCC = 1;
                                goto LAB_97b7e2b4;
                              }
                              length = _strlen(partBuf);
                              length2 = _strlen(*opsList);
                              if (length == length2 + 5) {
                                _sprintf(suffixedName,"%sR_SAT",*opsList);
                                compareResult = _strcmp(partBuf,suffixedName);
                                if (compareResult == 0) {
                                  opcode = opsList[1];
                                  precision = 1;
                                }
                                else {
                                  _sprintf(suffixedName,"%sH_SAT",*opsList);
                                  compareResult = _strcmp(partBuf,suffixedName);
                                  if (compareResult == 0) {
                                    opcode = opsList[1];
                                    precision = 2;
                                  }
                                  else {
                                    _sprintf(suffixedName,"%sX_SAT",*opsList);
                                    compareResult = _strcmp(partBuf,suffixedName);
                                    if (compareResult != 0) goto LAB_97b7e11c;
                                    opcode = opsList[1];
                                    precision = 3;
                                  }
                                }
LAB_97b7e260:
                                updateCC = 0;
                              }
                              else {
                                length = _strlen(partBuf);
                                length2 = _strlen(*opsList);
                                if (length != length2 + 6) goto LAB_97b7e11c;
                                _sprintf(suffixedName,"%sRC_SAT",*opsList);
                                compareResult = _strcmp(partBuf,suffixedName);
                                if (compareResult == 0) {
                                  opcode = opsList[1];
                                  precision = 1;
                                }
                                else {
                                  _sprintf(suffixedName,"%sHC_SAT",*opsList);
                                  compareResult = _strcmp(partBuf,suffixedName);
                                  if (compareResult == 0) {
                                    opcode = opsList[1];
                                    precision = 2;
                                  }
                                  else {
                                    _sprintf(suffixedName,"%sXC_SAT",*opsList);
                                    compareResult = _strcmp(partBuf,suffixedName);
                                    if (compareResult != 0) goto LAB_97b7e11c;
                                    opcode = opsList[1];
                                    precision = 3;
                                  }
                                }
LAB_97b7e328:
                                updateCC = 1;
                              }
                              saturate = 1;
                            }
                            ccRegister = 0;
LAB_97b7e334:
                            ppParserParseOperationResult = ((int (*)())_PPParserParseOperation)(parser,opcode,precision,updateCC,saturate,ccRegister,leftoverR9);
                            return ppParserParseOperationResult;
                          }
LAB_97b7e11c:
                          opsList = opsList + 2;
                          declStatusOrMnemonic = *opsList;
                        } while (declStatusOrMnemonic != 0);
                        profile = *(uint *)(parser + 0x48c);
                      }
                      if (profile == 0x34) {
                        if (tableTier == 0) {
LAB_97b7e160:
                          opsList = (int *)&_OpsList_NVvp20;
                        }
                        else {
                          if (tableTier != 1) goto LAB_97b7e1b4;
                          opsList = &_OpsList_NVvp30;
                        }
                      }
                      else {
                        if (profile == 0x31) {
                          if (tableTier == 0) goto LAB_97b7e160;
                          goto LAB_97b7e1b4;
                        }
                        if (profile == 0x33) {
                          if (tableTier != 0) goto LAB_97b7e1b4;
                        }
                        else {
                          if (profile != 0x36) {
LAB_97b7e1b4:
                            if (((profile & 0x10) != 0) &&
                               (partLengthOrStatus = _PPParserParseLabel(parser,partBuf,partLengthOrStatus), partLengthOrStatus != 3))
                            {
                              return partLengthOrStatus;
                            }
                            ppParserScopeFindMacroResult = ((int (*)())_PPParserScopeFindMacro)(*(undefined4 *)(parser + 0x44c),partBuf);
                            if (ppParserScopeFindMacroResult != 0) {
                              ppParserExpandMacroResult = _PPParserExpandMacro(parser,ppParserScopeFindMacroResult);
                              return ppParserExpandMacroResult;
                            }
                            optionCompare = _memcmp(partBuf,"OPTION",7);
                            if (optionCompare == 0) {
                              return 8;
                            }
                            ((int (*)())_PPParserReturnPart)(parser);
                            return 6;
                          }
                          if (tableTier != 0) {
                            if (tableTier == 1) {
                              opsList = (int *)&_OpsList_NVfp20;
                              goto LAB_97b7e1ac;
                            }
                            goto LAB_97b7e1b4;
                          }
                        }
                        opsList = (int *)&_OpsList_NVfp10;
                      }
LAB_97b7e1ac:
                      tableTier = tableTier + 1;
                    } while( true );
                  }
                  declStatusOrMnemonic = _PPParserParseBlock(parser);
                }
              }
            }
          }
        }
      }
    }
  }
  return declStatusOrMnemonic;
}

/* _PPParserParseParameterDeclaration @ 0x97b7e35c (372 bytes) */
int _PPParserParseParameterDeclaration(parser)
  int parser;
{
  int ppParserParseDefaultArrayResult;
  int ppParserScopeAddIdentifierResult;
  int identifier;
  int part;
  int ppParserValidateNameResult;
  int status;
  int part2;
  undefined4 isArray;
  char partBuf [256];
  undefined4 paramBinding [7];
  
  paramBinding[0] = 1;
  part = ((int (*)())_PPParserGetPart)(parser,partBuf,0);
  isArray = 0;
  status = 0x2d;
  if (part != 0) {
    ppParserValidateNameResult = ((int (*)())_PPParserValidateName)(parser,partBuf);
    status = 0x12;
    if (ppParserValidateNameResult == 0) {
      identifier = ((int (*)())_PPParserIdentifierCreate)();
      ((int (*)())_PPParserIdentifierSetName)(identifier,partBuf);
      *(undefined4 *)(identifier + 0xc) = 2;
      ppParserScopeAddIdentifierResult = ((int (*)())_PPParserScopeAddIdentifier)(*(undefined4 *)(parser + 0x44c),identifier);
      if (ppParserScopeAddIdentifierResult == 0) {
        part2 = ((int (*)())_PPParserGetPart)(parser,partBuf,0);
        status = 0x2d;
        if (part2 != 0) {
          if (partBuf[0] == '[') {
            ((int (*)())_PPParserReturnPart)(parser);
            ppParserParseDefaultArrayResult = _PPParserParseDefaultArray(parser,paramBinding);
            if (ppParserParseDefaultArrayResult != 0) {
              return ppParserParseDefaultArrayResult;
            }
            *(undefined1 *)(identifier + 0x10) = 1;
            status = ((int (*)())_PPParserGetPart)(parser,partBuf,0);
            if (status == 0) {
              return 0x2d;
            }
            isArray = 1;
          }
          status = 10;
          if (partBuf[0] == '=') {
            *(undefined4 *)(identifier + 8) = *(undefined4 *)(parser + 0x20);
            status = ((int (*)())_PPParserParseParamBinding)(parser,isArray,paramBinding);
            if (status == 0) {
              *(undefined4 *)(identifier + 4) = paramBinding[0];
              part = ((int (*)())_PPParserGetPart)(parser,partBuf,0);
              status = 0x2d;
              if ((part != 0) && (status = 10, partBuf[0] == ';')) {
                status = 0;
              }
            }
          }
        }
      }
      else {
        _PPParserIdentifierFree(identifier);
        status = 0x1c;
      }
    }
  }
  return status;
}

/* _PPParserValidateName @ 0x97b7e4d0 (1360 bytes) */
int _PPParserValidateName(parser, name)
  int parser;
  undefined4 name;
{
  int loopIndex;
  int length;
  int compareResult;
  int nameLength;
  int compareResult2;
  int reservedWord;
  int mnemonic;
  uint profile;
  int length2;
  char *suffixFormat;
  int *tableEntry;
  char suffixedName [24];
  
  if ((*(uint *)(parser + 0x48c) & 2) == 0) {
    tableEntry = &_vpDclList;
  }
  else {
    tableEntry = &_fpDclList;
  }
  reservedWord = *tableEntry;
  while (reservedWord != 0) {
    compareResult2 = _strcmp(name,reservedWord);
    if (compareResult2 == 0) {
      return 0x12;
    }
    tableEntry = tableEntry + 2;
    reservedWord = *tableEntry;
  }
  nameLength = _strlen(name);
  profile = *(uint *)(parser + 0x48c);
  if ((((profile == 0) || (profile == 2)) && (1 < nameLength - 3U)) && ((nameLength != 7 && (nameLength != 8)))) {
    return 0;
  }
  if ((profile & 2) == 0) {
    tableEntry = &_OpsList_ARBvp10;
  }
  else {
    tableEntry = &_OpsList_ARBfp10;
  }
  loopIndex = 0;
  do {
    mnemonic = *tableEntry;
    if (mnemonic != 0) {
      do {
        compareResult = _strcmp(name,mnemonic);
        if (compareResult == 0) {
          return 0x12;
        }
        profile = *(uint *)(parser + 0x48c);
        if ((profile & 0x10) != 0) {
          _sprintf(suffixedName,"%sC",*tableEntry);
          compareResult = _strcmp(name,suffixedName);
          if (compareResult == 0) {
            return 0x12;
          }
          profile = *(uint *)(parser + 0x48c);
          if (profile == 0x34) {
            _sprintf(suffixedName,"%sC0",*tableEntry);
            compareResult = _strcmp(name,suffixedName);
            if (compareResult == 0) {
              return 0x12;
            }
            _sprintf(suffixedName,"%sC1",*tableEntry);
            compareResult = _strcmp(name,suffixedName);
            if (compareResult == 0) {
              return 0x12;
            }
            profile = *(uint *)(parser + 0x48c);
          }
        }
        if ((profile & 2) != 0) {
          _sprintf(suffixedName,"%s_SAT",*tableEntry);
          compareResult = _strcmp(name,suffixedName);
          if (compareResult == 0) {
            return 0x12;
          }
          if ((*(uint *)(parser + 0x48c) & 0x10) != 0) {
            _sprintf(suffixedName,"%sC_SAT",*tableEntry);
            compareResult = _strcmp(name,suffixedName);
            if (compareResult == 0) {
              return 0x12;
            }
            if (*(int *)(parser + 0x48c) == 0x34) {
              _sprintf(suffixedName,"%sC0_SAT",*tableEntry);
              compareResult = _strcmp(name,suffixedName);
              if (compareResult == 0) {
                return 0x12;
              }
              _sprintf(suffixedName,"%sC1_SAT",*tableEntry);
              compareResult = _strcmp(name,suffixedName);
              if (compareResult == 0) {
                return 0x12;
              }
            }
            length = _strlen(name);
            length2 = _strlen(*tableEntry);
            if (length == length2 + 1) {
              _sprintf(suffixedName,"%sR",*tableEntry);
              compareResult = _strcmp(name,suffixedName);
              if (compareResult == 0) {
                return 0x12;
              }
              _sprintf(suffixedName,"%sH",*tableEntry);
              compareResult = _strcmp(name,suffixedName);
              if (compareResult == 0) {
                return 0x12;
              }
              mnemonic = *tableEntry;
              suffixFormat = "%sX";
            }
            else {
              length = _strlen(name);
              length2 = _strlen(*tableEntry);
              if (length == length2 + 2) {
                _sprintf(suffixedName,"%sRC",*tableEntry);
                compareResult = _strcmp(name,suffixedName);
                if (compareResult == 0) {
                  return 0x12;
                }
                _sprintf(suffixedName,"%sHC",*tableEntry);
                compareResult = _strcmp(name,suffixedName);
                if (compareResult == 0) {
                  return 0x12;
                }
                mnemonic = *tableEntry;
                suffixFormat = "%sXC";
              }
              else {
                length = _strlen(name);
                length2 = _strlen(*tableEntry);
                if (length == length2 + 5) {
                  _sprintf(suffixedName,"%sR_SAT",*tableEntry);
                  compareResult = _strcmp(name,suffixedName);
                  if (compareResult == 0) {
                    return 0x12;
                  }
                  _sprintf(suffixedName,"%sH_SAT",*tableEntry);
                  compareResult = _strcmp(name,suffixedName);
                  if (compareResult == 0) {
                    return 0x12;
                  }
                  mnemonic = *tableEntry;
                  suffixFormat = "%sX_SAT";
                }
                else {
                  length = _strlen(name);
                  length2 = _strlen(*tableEntry);
                  if (length != length2 + 6) goto LAB_97b7e970;
                  _sprintf(suffixedName,"%sRC_SAT",*tableEntry);
                  compareResult = _strcmp(name,suffixedName);
                  if (compareResult == 0) {
                    return 0x12;
                  }
                  _sprintf(suffixedName,"%sHC_SAT",*tableEntry);
                  compareResult = _strcmp(name,suffixedName);
                  if (compareResult == 0) {
                    return 0x12;
                  }
                  mnemonic = *tableEntry;
                  suffixFormat = "%sXC_SAT";
                }
              }
            }
            _sprintf(suffixedName,suffixFormat,mnemonic);
            compareResult = _strcmp(name,suffixedName);
            if (compareResult == 0) {
              return 0x12;
            }
          }
        }
LAB_97b7e970:
        tableEntry = tableEntry + 2;
        mnemonic = *tableEntry;
      } while (mnemonic != 0);
      profile = *(uint *)(parser + 0x48c);
    }
    if (profile == 0x34) {
      if (loopIndex == 0) {
LAB_97b7e9b4:
        tableEntry = (int *)&_OpsList_NVvp20;
      }
      else {
        if (loopIndex != 1) {
          return 0;
        }
        tableEntry = &_OpsList_NVvp30;
      }
    }
    else {
      if (profile == 0x31) {
        if (loopIndex != 0) {
          return 0;
        }
        goto LAB_97b7e9b4;
      }
      if (profile == 0x33) {
        if (loopIndex != 0) {
          return 0;
        }
      }
      else {
        if (profile != 0x36) {
          return 0;
        }
        if (loopIndex != 0) {
          if (loopIndex != 1) {
            return 0;
          }
          tableEntry = (int *)&_OpsList_NVfp20;
          goto LAB_97b7ea00;
        }
      }
      tableEntry = (int *)&_OpsList_NVfp10;
    }
LAB_97b7ea00:
    loopIndex = loopIndex + 1;
  } while( true );
}

/* _PPParserIdentifierCreate @ 0x97b7ea20 (48 bytes) */
int _PPParserIdentifierCreate()
{
  int identifier;
  
  identifier = _calloc(0x24,1);
  *(undefined4 *)(identifier + 4) = 1;
  return identifier;
}

/* _PPParserIdentifierSetName @ 0x97b7ea50 (124 bytes) */
int _PPParserIdentifierSetName(identifier, name)
  int *identifier;
  int name;
{
  int length;
  int nameCopy;
  
  if (*identifier != 0) {
    _free(*identifier);
    *identifier = 0;
  }
  if (name != 0) {
    length = _strlen(name);
    nameCopy = _calloc(length + 1,1);
    *identifier = nameCopy;
    _memmove(nameCopy,name,length);
  }
  return name == 0;
}

/* _PPParserScopeAddIdentifier @ 0x97b7eacc (124 bytes) */
int _PPParserScopeAddIdentifier(scope, identifier)
  int *scope;
  undefined4 *identifier;
{
  undefined4 *firstIdentifier;
  int ppParserScopeFindIdentifierResult;
  undefined4 status;
  
  ppParserScopeFindIdentifierResult = ((int (*)())_PPParserScopeFindIdentifier)(scope,*identifier);
  status = 1;
  if (ppParserScopeFindIdentifierResult == 0) {
    firstIdentifier = (undefined4 *)*scope;
    if ((undefined4 *)*scope == (undefined4 *)0x0) {
      firstIdentifier = identifier;
    }
    *scope = (int)firstIdentifier;
    if (scope[1] != 0) {
      *(undefined4 **)(scope[1] + 0x20) = identifier;
      identifier[7] = scope[1];
    }
    status = 0;
    scope[1] = (int)identifier;
    identifier[6] = scope[6];
  }
  return status;
}

/* _PPParserScopeFindIdentifier @ 0x97b7eb48 (100 bytes) */
int _PPParserScopeFindIdentifier(scope, name)
  int *scope;
  undefined4 name;
{
  int compareResult;
  int *identifier;
  
  identifier = (int *)*scope;
  while( true ) {
    if (identifier == (int *)0x0) {
      return (int *)0x0;
    }
    if ((*identifier != 0) && (compareResult = _strcmp(*identifier,name), compareResult == 0)) break;
    identifier = (int *)identifier[8];
  }
  return identifier;
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
  bool singleBinding;
  bool isFragmentProgram;
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
  undefined4 bindingExtra0;
  undefined4 bindingExtra1;
  uint arrayFirstOrdinal;
  undefined2 arrayLastOrdinalLo;
  short arrayLastOrdinalHi;
  undefined4 constX;
  undefined4 constY;
  undefined4 constZ;
  undefined4 constW;
  undefined4 scalarX;
  undefined4 scalarY;
  undefined4 scalarZ;
  undefined4 scalarW;
  undefined4 arrayStart;
  uint arrayEnd [4];
  
  singleBinding = isBraceList == 0;
  programTypeOrIndex = *(uint *)(parser + 0x48c);
  loopIndex = 0;
  if (!singleBinding) {
    part = ((int (*)())_PPParserGetPart)(parser,partText,0);
    if (part == 0) {
      return 0x2d;
    }
    if (partText[0] != '{') {
      return 10;
    }
  }
  isFragmentProgram = ((programTypeOrIndex ^ 2) >> 1 & 1) == 0;
  arrayLastOrdinalLo = 0;
  arrayFirstOrdinal = (uint)*(ushort *)(parser + 0x22);
  do {
    part = ((int (*)())_PPParserGetPart)(parser,partText,1);
    if (part == 0) {
      return 0x2d;
    }
    bindingExtra1 = 0;
    bindingOrdinalWord = (uint)*(ushort *)(parser + 0x22);
    bindingWord = 0;
    bindingExtra0 = 0;
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
        if (singleBinding) {
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
          if (singleBinding) {
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
            if (isFragmentProgram) {
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
                if (isFragmentProgram) {
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
                      if (singleBinding) {
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
                      if (singleBinding) {
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
          constX = 0;
          constW = 0x3f800000;
          constZ = 0;
          constY = 0;
          scalars = _PPParserGetScalars(parser,&constX,4);
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
          constantValues = &constX;
        }
        else {
          ((int (*)())_PPParserReturnPart)(parser);
          constantValues = &scalarX;
          bindingWord = bindingWord & 0xffe0ffff | 0x110000;
          scalars = _PPParserGetScalars(parser,constantValues,1);
          if (scalars != 0) {
            return 10;
          }
          ppStream = *(undefined4 *)(parser + 0x1c);
          scalarW = scalarX;
          scalarY = scalarX;
          scalarZ = scalarX;
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
    if (singleBinding) goto LAB_97b80220;
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
      arrayLastOrdinalLo = CONCAT22(arrayLastOrdinalLo,*(short *)(parser + 0x22) + -1);
      if (1 < loopIndex) {
        _PPStreamAddParamBindingArray(*(undefined4 *)(parser + 0x1c),&arrayFirstOrdinal);
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
int _PPParserScopeFindMacro(scope, name)
  int scope;
  undefined4 name;
{
  int compareResult;
  int *macro;
  
  macro = *(int **)(scope + 8);
  while( true ) {
    if (macro == (int *)0x0) {
      return (int *)0x0;
    }
    if ((*macro != 0) && (compareResult = _strcmp(*macro,name), compareResult == 0)) break;
    macro = (int *)macro[7];
  }
  return macro;
}

/* _PPParserParseArray @ 0x97b8031c (176 bytes) */
int _PPParserParseArray(parser, indexOut)
  undefined4 parser;
  int *indexOut;
{
  int part;
  int status;
  char partBuf [260];
  
  part = ((int (*)())_PPParserGetPart)(parser,partBuf,0);
  status = 0x2d;
  if ((((part != 0) && (status = 0xb, partBuf[0] == '[')) &&
      (status = ((int (*)())_PPParserGetInteger)(parser,indexOut), status == 0)) && (status = 0x23, -1 < *indexOut))
  {
    part = ((int (*)())_PPParserGetPart)(parser,partBuf,0);
    status = 0x2d;
    if ((part != 0) && (status = 0xb, partBuf[0] == ']')) {
      status = 0;
    }
  }
  return status;
}

/* _PPParserGetInteger @ 0x97b803cc (112 bytes) */
int _PPParserGetInteger(parser, valueOut)
  undefined4 parser;
  long *valueOut;
{
  int part;
  undefined4 status;
  long strtolResult;
  char partText [256];
  char *intEnd [5];
  
  part = ((int (*)())_PPParserGetPart)(parser,partText,1);
  status = 0x2d;
  if (part != 0) {
    strtolResult = _strtol(partText,intEnd,0);
    *valueOut = strtolResult;
    status = 0x15;
    if (intEnd[0] == partText + part) {
      status = 0;
    }
  }
  return status;
}

/* _PPStreamAddParamBinding @ 0x97b8043c (108 bytes) */
int _PPStreamAddParamBinding(stream, binding)
  int stream;
  undefined4 *binding;
{
  undefined1 *allocation;
  undefined4 bindingList;
  undefined4 bindingWord3;
  undefined4 bindingWord0;
  undefined4 bindingWord2;
  undefined4 bindingWord1;
  
  allocation = (undefined1 *)_calloc(0x1c,1);
  bindingWord3 = binding[3];
  bindingList = *(undefined4 *)(stream + 0x10);
  bindingWord0 = *binding;
  bindingWord1 = binding[1];
  bindingWord2 = binding[2];
  *allocation = 3;
  *(undefined4 *)(allocation + 0xc) = bindingWord0;
  *(undefined4 *)(allocation + 0x10) = bindingWord1;
  *(undefined4 *)(allocation + 0x14) = bindingWord2;
  *(undefined4 *)(allocation + 0x18) = bindingWord3;
  return ((int (*)())_PPStreamChunkListAddChunk)(bindingList,allocation);
}

/* _PPParserParseAttributeDeclaration @ 0x97b804a8 (268 bytes) */
int _PPParserParseAttributeDeclaration(parser)
  int parser;
{
  int ppParserScopeAddIdentifierResult;
  int ppParserIdentifierCreateResult;
  int part;
  int ppParserValidateNameResult;
  int status;
  int part2;
  char partBuf [256];
  
  part = ((int (*)())_PPParserGetPart)(parser,partBuf,0);
  status = 0x2d;
  if (part != 0) {
    ppParserValidateNameResult = ((int (*)())_PPParserValidateName)(parser,partBuf);
    status = 0x12;
    if (ppParserValidateNameResult == 0) {
      ppParserIdentifierCreateResult = ((int (*)())_PPParserIdentifierCreate)();
      ((int (*)())_PPParserIdentifierSetName)(ppParserIdentifierCreateResult,partBuf);
      *(undefined4 *)(ppParserIdentifierCreateResult + 0xc) = 0;
      ppParserScopeAddIdentifierResult = ((int (*)())_PPParserScopeAddIdentifier)(*(undefined4 *)(parser + 0x44c),ppParserIdentifierCreateResult);
      if (ppParserScopeAddIdentifierResult == 0) {
        part2 = ((int (*)())_PPParserGetPart)(parser,partBuf,0);
        status = 0x2d;
        if ((part2 != 0) && (status = 10, partBuf[0] == '=')) {
          *(undefined4 *)(ppParserIdentifierCreateResult + 8) = *(undefined4 *)(parser + 0x24);
          status = ((int (*)())_PPParserParseAttributeBinding)(parser);
          if (status == 0) {
            part = ((int (*)())_PPParserGetPart)(parser,partBuf,0);
            status = 0x2d;
            if ((part != 0) && (status = 10, partBuf[0] == ';')) {
              status = 0;
            }
          }
        }
      }
      else {
        _PPParserIdentifierFree(ppParserIdentifierCreateResult);
        status = 0x1c;
      }
    }
  }
  return status;
}

/* _PPParserParseAttributeBinding @ 0x97b805b4 (1684 bytes) */
int _PPParserParseAttributeBinding(parser)
  int parser;
{
  uint profile;
  bool isFragmentProgram;
  uint indexLimit;
  int partLenCmpOrClass;
  int testAttribMatchResult;
  int bindingChunk;
  char partBuf [256];
  uint binding;
  undefined2 bindingOrdinal;
  undefined2 bindingOrdinalHi;
  uint arrayIndex [7];
  
  profile = *(uint *)(parser + 0x48c);
  partLenCmpOrClass = ((int (*)())_PPParserGetPart)(parser,partBuf,0);
  if (partLenCmpOrClass == 0) {
    return 0x2d;
  }
  isFragmentProgram = ((profile ^ 2) >> 1 & 1) == 0;
  bindingOrdinal = 0;
  binding = 0;
  if (isFragmentProgram) {
    partLenCmpOrClass = _memcmp(partBuf,"fragment",9);
  }
  else {
    partLenCmpOrClass = _memcmp(partBuf,"vertex",7);
  }
  if (partLenCmpOrClass != 0) {
    return 10;
  }
  partLenCmpOrClass = ((int (*)())_PPParserGetPart)(parser,partBuf,0);
  if (partLenCmpOrClass == 0) {
    return 0x2d;
  }
  if (partBuf[0] != '.') {
    return 10;
  }
  if (partLenCmpOrClass != 1) {
    return 10;
  }
  partLenCmpOrClass = ((int (*)())_PPParserGetPart)(parser,partBuf,0);
  if (partLenCmpOrClass == 0) {
    return 0x2d;
  }
  if ((!isFragmentProgram) && (partLenCmpOrClass = _memcmp(partBuf,"attrib",7), partLenCmpOrClass == 0)) {
    binding = binding & 0xfff0ffff | 0x90000;
    partLenCmpOrClass = ((int (*)())_PPParserParseArray)(parser,arrayIndex);
    if (partLenCmpOrClass != 0) {
      return partLenCmpOrClass;
    }
    partLenCmpOrClass = 0x3d;
    indexLimit = *(uint *)(parser + 0x488);
    goto LAB_97b80948;
  }
  partLenCmpOrClass = _memcmp(partBuf,"position",9);
  if (partLenCmpOrClass == 0) {
    partLenCmpOrClass = 1;
  }
  else {
    if ((isFragmentProgram) || (partLenCmpOrClass = _memcmp(partBuf,"normal",7), partLenCmpOrClass != 0)) {
      partLenCmpOrClass = _memcmp(partBuf,"color",6);
      if (partLenCmpOrClass == 0) {
        binding = binding & 0xfff0ffff | 0x20000;
        partLenCmpOrClass = ((int (*)())_PPParserGetPart)(parser,partBuf,0);
        if (partLenCmpOrClass == 0) {
          return 0x2d;
        }
        if ((partBuf[0] == '.') && (partLenCmpOrClass == 1)) {
          partLenCmpOrClass = ((int (*)())_PPParserGetPart)(parser,partBuf,0);
          if (partLenCmpOrClass == 0) {
            return 0x2d;
          }
          partLenCmpOrClass = _memcmp(partBuf,"secondary",10);
          if (partLenCmpOrClass == 0) {
            partLenCmpOrClass = 3;
            goto LAB_97b80b98;
          }
          partLenCmpOrClass = _memcmp(partBuf,"primary",8);
          if (partLenCmpOrClass == 0) goto LAB_97b80bac;
          ((int (*)())_PPParserReturnPart)(parser);
        }
        ((int (*)())_PPParserReturnPart)(parser);
        goto LAB_97b80bac;
      }
      partLenCmpOrClass = _memcmp(partBuf,"fogcoord",9);
      if (partLenCmpOrClass == 0) {
        partLenCmpOrClass = 5;
        goto LAB_97b80b98;
      }
      partLenCmpOrClass = _memcmp(partBuf,"texcoord",9);
      if (partLenCmpOrClass == 0) {
        binding = binding & 0xfff0ffff | 0x70000;
        partLenCmpOrClass = ((int (*)())_PPParserGetPart)(parser,partBuf,0);
        if (partLenCmpOrClass == 0) {
          return 0x2d;
        }
        ((int (*)())_PPParserReturnPart)(parser);
        if (partBuf[0] != '[') {
LAB_97b8095c:
          binding = binding & 0xffffffe0;
          goto LAB_97b80bac;
        }
        partLenCmpOrClass = ((int (*)())_PPParserParseArray)(parser,arrayIndex);
        if (partLenCmpOrClass != 0) {
          return partLenCmpOrClass;
        }
        partLenCmpOrClass = 0x38;
        indexLimit = *(uint *)(parser + 0x470);
LAB_97b80948:
        if (indexLimit <= arrayIndex[0]) {
          return partLenCmpOrClass;
        }
        binding = arrayIndex[0] & 0x1f | binding & 0xffffffe0;
        goto LAB_97b80bac;
      }
      if (isFragmentProgram) {
        partLenCmpOrClass = _memcmp(partBuf,"facing",7);
        if (partLenCmpOrClass != 0) {
          return 10;
        }
        if (*(int *)(parser + 0x48c) != 0x36) {
          return 10;
        }
        partLenCmpOrClass = 0xb;
        goto LAB_97b80b98;
      }
      partLenCmpOrClass = _memcmp(partBuf,"weight",7);
      if (partLenCmpOrClass == 0) {
        binding = binding & 0xfff0ffff | 0x60000;
        partLenCmpOrClass = ((int (*)())_PPParserGetPart)(parser,partBuf,0);
        if (partLenCmpOrClass == 0) {
          return 0x2d;
        }
        ((int (*)())_PPParserReturnPart)(parser);
        if (partBuf[0] != '[') goto LAB_97b8095c;
        partLenCmpOrClass = ((int (*)())_PPParserParseArray)(parser,arrayIndex);
        if (partLenCmpOrClass != 0) {
          return partLenCmpOrClass;
        }
        partLenCmpOrClass = 0x39;
        indexLimit = *(uint *)(parser + 0x478);
        goto LAB_97b80948;
      }
      partLenCmpOrClass = _memcmp(partBuf,"material",9);
      if (partLenCmpOrClass != 0) {
        return 10;
      }
      binding = binding & 0xfff0fffe | 0xa0000;
      partLenCmpOrClass = ((int (*)())_PPParserGetPart)(parser,partBuf,0);
      if (partLenCmpOrClass == 0) {
        return 0x2d;
      }
      if (partBuf[0] != '.') {
        return 10;
      }
      if (partLenCmpOrClass != 1) {
        return 10;
      }
      partLenCmpOrClass = ((int (*)())_PPParserGetPart)(parser,partBuf,0);
      if (partLenCmpOrClass == 0) {
        return 0x2d;
      }
      partLenCmpOrClass = _memcmp(partBuf,"front",6);
      if (partLenCmpOrClass == 0) {
LAB_97b80a4c:
        partLenCmpOrClass = ((int (*)())_PPParserGetPart)(parser,partBuf,0);
        if (partLenCmpOrClass == 0) {
          return 0x2d;
        }
        if ((partBuf[0] != '.') || (partLenCmpOrClass != 1)) {
          return 10;
        }
        partLenCmpOrClass = ((int (*)())_PPParserGetPart)(parser,partBuf,0);
        if (partLenCmpOrClass == 0) {
          return 0x2d;
        }
      }
      else {
        partLenCmpOrClass = _memcmp(partBuf,"back",5);
        if (partLenCmpOrClass == 0) {
          binding = binding | 1;
          goto LAB_97b80a4c;
        }
      }
      partLenCmpOrClass = _memcmp(partBuf,"ambient",8);
      if (partLenCmpOrClass == 0) {
        binding = binding & 0xffff0fff;
      }
      else {
        partLenCmpOrClass = _memcmp(partBuf,"diffuse",8);
        if (partLenCmpOrClass == 0) {
          partLenCmpOrClass = 1;
        }
        else {
          partLenCmpOrClass = _memcmp(partBuf,"specular",9);
          if (partLenCmpOrClass == 0) {
            partLenCmpOrClass = 2;
          }
          else {
            partLenCmpOrClass = _memcmp(partBuf,"emission",9);
            if (partLenCmpOrClass == 0) {
              partLenCmpOrClass = 3;
            }
            else {
              partLenCmpOrClass = _memcmp(partBuf,"shininess",10);
              if (partLenCmpOrClass != 0) {
                return 10;
              }
              partLenCmpOrClass = 4;
            }
          }
        }
        binding = partLenCmpOrClass << 0xc | binding & 0xffff0fff;
      }
      goto LAB_97b80bac;
    }
    partLenCmpOrClass = 4;
  }
LAB_97b80b98:
  binding = partLenCmpOrClass << 0x10 | binding & 0xfff0ffff;
LAB_97b80bac:
  if (isFragmentProgram) {
    partLenCmpOrClass = *(int *)(parser + 0x1c);
  }
  else {
    partLenCmpOrClass = *(int *)(parser + 0x1c);
    bindingChunk = **(int **)(partLenCmpOrClass + 0x18);
    if (bindingChunk != 0) {
      do {
        testAttribMatchResult = ((int (*)())_testAttribMatch)(&binding,bindingChunk + 0xc);
        if (testAttribMatchResult != 0) {
          return 0x13;
        }
        bindingChunk = *(int *)(bindingChunk + 8);
      } while (bindingChunk != 0);
    }
  }
  bindingOrdinal = CONCAT22(bindingOrdinal,(short)*(int *)(parser + 0x24));
  *(int *)(parser + 0x24) = *(int *)(parser + 0x24) + 1;
  ((int (*)())_PPStreamAddAttribBinding)(partLenCmpOrClass,&binding);
  partLenCmpOrClass = 0x35;
  if (*(uint *)(parser + 0x24) < 0x101) {
    partLenCmpOrClass = 0;
  }
  return partLenCmpOrClass;
}

/* _testAttribMatch @ 0x97b80c48 (300 bytes) */
int _testAttribMatch(binding, generic)
  uint *binding;
  uint *generic;
{
  bool matches;
  uint genericIndexWord;
  undefined4 result;
  
  genericIndexWord = *binding;
  if ((genericIndexWord >> 0x10 & 0xf) == 9) {
    binding = generic;
    if ((*generic >> 0x10 & 0xf) == 9) {
      return 0;
    }
  }
  else {
    if ((*generic >> 0x10 & 0xf) != 9) {
      return 0;
    }
    genericIndexWord = *generic;
  }
  switch(genericIndexWord & 0x1f) {
  case 0:
    matches = (*binding >> 0x10 & 0xf) == 1;
    break;
  case 1:
    matches = (*binding & 0xf001f) == 0x60000;
    break;
  case 2:
    matches = (*binding >> 0x10 & 0xf) == 4;
    break;
  case 3:
    matches = (*binding >> 0x10 & 0xf) == 2;
    break;
  case 4:
    matches = (*binding >> 0x10 & 0xf) == 3;
    break;
  case 5:
    matches = (*binding >> 0x10 & 0xf) == 5;
    break;
  case 6:
  case 7:
    goto switchD_97b80cc0_caseD_6;
  default:
    if ((*binding >> 0x10 & 0xf) == 7) {
      matches = (*binding & 0x1f) == (genericIndexWord & 0x1f) - 8;
      break;
    }
    goto switchD_97b80cc0_caseD_6;
  }
  result = 1;
  if (!matches) {
switchD_97b80cc0_caseD_6:
    result = 0;
  }
  return result;
}

/* _PPParserParseOutputDeclaration @ 0x97b80d94 (284 bytes) */
int _PPParserParseOutputDeclaration(parser, outputMode)
  int parser;
  undefined4 outputMode;
{
  int ppParserScopeAddIdentifierResult;
  int ppParserIdentifierCreateResult;
  int part;
  int ppParserValidateNameResult;
  int status;
  int part2;
  char partBuf [256];
  
  part = ((int (*)())_PPParserGetPart)(parser,partBuf,0);
  status = 0x2d;
  if (part != 0) {
    ppParserValidateNameResult = ((int (*)())_PPParserValidateName)(parser,partBuf);
    status = 0x12;
    if (ppParserValidateNameResult == 0) {
      ppParserIdentifierCreateResult = ((int (*)())_PPParserIdentifierCreate)();
      ((int (*)())_PPParserIdentifierSetName)(ppParserIdentifierCreateResult,partBuf);
      *(undefined4 *)(ppParserIdentifierCreateResult + 0xc) = 3;
      *(undefined4 *)(ppParserIdentifierCreateResult + 0x14) = outputMode;
      ppParserScopeAddIdentifierResult = ((int (*)())_PPParserScopeAddIdentifier)(*(undefined4 *)(parser + 0x44c),ppParserIdentifierCreateResult);
      if (ppParserScopeAddIdentifierResult == 0) {
        part2 = ((int (*)())_PPParserGetPart)(parser,partBuf,0);
        status = 0x2d;
        if ((part2 != 0) && (status = 10, partBuf[0] == '=')) {
          *(undefined4 *)(ppParserIdentifierCreateResult + 8) = *(undefined4 *)(parser + 0x28);
          status = ((int (*)())_PPParserParseOutputBinding)(parser,outputMode);
          if (status == 0) {
            part = ((int (*)())_PPParserGetPart)(parser,partBuf,0);
            status = 0x2d;
            if ((part != 0) && (status = 10, partBuf[0] == ';')) {
              status = 0;
            }
          }
        }
      }
      else {
        _PPParserIdentifierFree(ppParserIdentifierCreateResult);
        status = 0x1c;
      }
    }
  }
  return status;
}

/* _PPParserParseOutputBinding @ 0x97b80eb0 (1212 bytes) */
int _PPParserParseOutputBinding(parser, outputMode)
  int parser;
  int outputMode;
{
  int compareResult;
  bool isFragmentProgram;
  uint profile;
  int partLenCmpOrClass;
  int part;
  char partBuf;
  undefined1 partBuf1;
  uint binding;
  undefined2 bindingOrdinal;
  undefined2 bindingOrdinalHi;
  uint arrayIndex [7];
  
  profile = *(uint *)(parser + 0x48c);
  partLenCmpOrClass = ((int (*)())_PPParserGetPart)(parser,&partBuf,0);
  if (partLenCmpOrClass == 0) {
    return 0x2d;
  }
  binding = outputMode << 0x1d;
  bindingOrdinal = 0;
  partLenCmpOrClass = _memcmp(&partBuf,"result",7);
  if (partLenCmpOrClass != 0) {
    return 10;
  }
  partLenCmpOrClass = ((int (*)())_PPParserGetPart)(parser,&partBuf,0);
  if (partLenCmpOrClass == 0) {
    return 0x2d;
  }
  if ((partBuf != '.') || (partLenCmpOrClass != 1)) {
    return 10;
  }
  partLenCmpOrClass = ((int (*)())_PPParserGetPart)(parser,&partBuf,0);
  if (partLenCmpOrClass == 0) {
    return 0x2d;
  }
  isFragmentProgram = ((profile ^ 2) >> 1 & 1) == 0;
  if ((!isFragmentProgram) && (partLenCmpOrClass = _memcmp(&partBuf,"position",9), partLenCmpOrClass == 0)) {
    if ((*(byte *)(parser + 0x442) & 1) != 0) {
      return 0x22;
    }
    binding = binding & 0xfff0ffff | 0x10000;
    goto LAB_97b81320;
  }
  partLenCmpOrClass = _memcmp(&partBuf,"color",6);
  if (partLenCmpOrClass == 0) {
    binding = binding & 0xfff0fffe | 0x40000;
    if (isFragmentProgram) {
      if (*(char *)(parser + 0x445) != '\0') {
        partLenCmpOrClass = ((int (*)())_PPParserGetPart)(parser,&partBuf,0);
        if (partLenCmpOrClass == 0) {
          return 0x2d;
        }
        ((int (*)())_PPParserReturnPart)(parser);
        if (partBuf == '[') {
          partLenCmpOrClass = ((int (*)())_PPParserParseArray)(parser,arrayIndex);
          if (partLenCmpOrClass != 0) {
            return partLenCmpOrClass;
          }
          binding = (arrayIndex[0] & 7) << 1 | binding & 0xfffffff1;
        }
        else {
          binding = binding & 0xfffffff1;
        }
      }
      goto LAB_97b81320;
    }
    partLenCmpOrClass = ((int (*)())_PPParserGetPart)(parser,&partBuf,0);
    if (partLenCmpOrClass == 0) {
      return 0x2d;
    }
    if ((partBuf == '.') && (partLenCmpOrClass == 1)) {
      part = ((int (*)())_PPParserGetPart)(parser,&partBuf,0);
      if (part == 0) {
        return 0x2d;
      }
      compareResult = _memcmp(&partBuf,"back",5);
      if (compareResult == 0) {
        binding = binding | 1;
      }
      else {
        compareResult = _memcmp(&partBuf,"front",6);
        if (compareResult != 0) {
          ((int (*)())_PPParserReturnPart)(parser);
          partBuf1 = 0;
          partBuf = '.';
          goto LAB_97b810c0;
        }
      }
      partLenCmpOrClass = ((int (*)())_PPParserGetPart)(parser,&partBuf,0);
      if (partLenCmpOrClass == 0) {
        return 0x2d;
      }
    }
LAB_97b810c0:
    if ((partBuf == '.') && (partLenCmpOrClass == 1)) {
      partLenCmpOrClass = ((int (*)())_PPParserGetPart)(parser,&partBuf,0);
      if (partLenCmpOrClass == 0) {
        return 0x2d;
      }
      partLenCmpOrClass = _memcmp(&partBuf,"secondary",10);
      if (partLenCmpOrClass == 0) {
        partLenCmpOrClass = 5;
        goto LAB_97b8130c;
      }
      partLenCmpOrClass = _memcmp(&partBuf,"primary",8);
      if (partLenCmpOrClass == 0) goto LAB_97b81320;
      ((int (*)())_PPParserReturnPart)(parser);
    }
    ((int (*)())_PPParserReturnPart)(parser);
  }
  else {
    if (isFragmentProgram) {
      partLenCmpOrClass = _memcmp(&partBuf,"depth",6);
      if (partLenCmpOrClass != 0) {
        return 10;
      }
      partLenCmpOrClass = 7;
    }
    else {
      partLenCmpOrClass = _memcmp(&partBuf,"fogcoord",9);
      if (partLenCmpOrClass == 0) {
        partLenCmpOrClass = 2;
      }
      else {
        partLenCmpOrClass = _memcmp(&partBuf,"pointsize",10);
        if (partLenCmpOrClass == 0) {
          partLenCmpOrClass = 3;
        }
        else {
          partLenCmpOrClass = _memcmp(&partBuf,"texcoord",9);
          if (partLenCmpOrClass == 0) {
            binding = binding & 0xfff0ffff | 0x60000;
            partLenCmpOrClass = ((int (*)())_PPParserGetPart)(parser,&partBuf,0);
            if (partLenCmpOrClass == 0) {
              return 0x2d;
            }
            ((int (*)())_PPParserReturnPart)(parser);
            if (partBuf == '[') {
              partLenCmpOrClass = ((int (*)())_PPParserParseArray)(parser,arrayIndex);
              if (partLenCmpOrClass != 0) {
                return partLenCmpOrClass;
              }
              binding = arrayIndex[0] & 0x1f | binding & 0xffffffe0;
            }
            else {
              binding = binding & 0xffffffe0;
            }
            goto LAB_97b81320;
          }
          partLenCmpOrClass = _memcmp(&partBuf,"clip",5);
          if (partLenCmpOrClass != 0) {
            return 10;
          }
          if ((*(int *)(parser + 0x48c) != 0x31) && (*(int *)(parser + 0x48c) != 0x34)) {
            return 10;
          }
          partLenCmpOrClass = 9;
        }
      }
    }
LAB_97b8130c:
    binding = partLenCmpOrClass << 0x10 | binding & 0xfff0ffff;
  }
LAB_97b81320:
  bindingOrdinal = CONCAT22(bindingOrdinal,(short)*(int *)(parser + 0x28));
  *(int *)(parser + 0x28) = *(int *)(parser + 0x28) + 1;
  ((int (*)())_PPStreamAddOutputBinding)(*(undefined4 *)(parser + 0x1c),&binding);
  partLenCmpOrClass = 0x36;
  if (*(uint *)(parser + 0x28) < 0x101) {
    partLenCmpOrClass = 0;
  }
  return partLenCmpOrClass;
}

/* _PPStreamAddOutputBinding @ 0x97b8136c (92 bytes) */
int _PPStreamAddOutputBinding(stream, binding)
  int stream;
  undefined4 *binding;
{
  undefined1 *allocation;
  undefined4 bindingList;
  undefined4 bindingWord0;
  undefined4 bindingWord1;
  
  allocation = (undefined1 *)_calloc(0x14,1);
  bindingWord1 = binding[1];
  bindingList = *(undefined4 *)(stream + 0x1c);
  bindingWord0 = *binding;
  *allocation = 4;
  *(undefined4 *)(allocation + 0xc) = bindingWord0;
  *(undefined4 *)(allocation + 0x10) = bindingWord1;
  return ((int (*)())_PPStreamChunkListAddChunk)(bindingList,allocation);
}

/* _PPParserParseOperation @ 0x97b813c8 (1068 bytes) */
int _PPParserParseOperation(parser, opcode, precision, updateCC, saturate, ccRegister, unusedArg7)
  int parser;
  uint opcode;
  uint precision;
  uint updateCC;
  uint saturate;
  uint ccRegister;
  undefined4 unusedArg7;
{
  int ppParserParseBranchLabelResult;
  int part;
  bool hasDestination;
  bool addressDestination;
  bool requireScalarSwizzle;
  int status;
  int resultOrLastOp;
  undefined4 *sourceTarget;
  uint sourceCount;
  undefined4 *sourceCursor;
  uint loopIndex;
  char partBuf [256];
  undefined1 branchLabelText [256];
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
  undefined4 branchTarget;
  int sourceSwizzleInfo [6];
  
  opLine = *(int *)(parser + 0x18);
  status = 0;
  branchTarget = 0;
  sourceCount = 0;
  requireScalarSwizzle = false;
  opDest0 = 0;
  hasDestination = true;
  opDest1 = 0;
  addressDestination = false;
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
  opHeader = (opcode & 0xff) << 0x12;
  opFlags = (precision & 3) << 0x12 |
             (saturate & 1) << 0x14 | (ccRegister & 1) << 0x15 | (updateCC & 1) << 0x16;
  switch(opcode) {
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
    sourceCount = 1;
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
    sourceCount = 1;
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
    sourceCount = 2;
    break;
  case 0x38:
    sourceCount = 2;
LAB_97b81664:
    requireScalarSwizzle = true;
    break;
  case 0x3c:
  case 0x3e:
  case 0x3f:
  case 0x53:
  case 0x67:
    sourceCount = 3;
    break;
  case 0x48:
    if ((*(uint *)(parser + 0x48c) & 0x10) == 0) {
      requireScalarSwizzle = true;
    }
  case 0x49:
  case 0x4a:
    sourceCount = 1;
    addressDestination = true;
    break;
  case 0x4b:
  case 0x4c:
    ppParserParseBranchLabelResult = _PPParserParseBranchLabel(parser,branchLabelText,&branchTarget);
    if (ppParserParseBranchLabelResult != 0) {
      return ppParserParseBranchLabelResult;
    }
  case 0x4d:
  case 0x54:
  case 0x55:
    status = _PPParserParseBranchCondition(parser,&opDest0,opcode);
    goto LAB_97b816dc;
  case 0x4f:
    sourceCount = 1;
LAB_97b816dc:
    hasDestination = false;
    if (status != 0) {
      return status;
    }
    break;
  case 0x56:
  case 0x57:
  case 0x60:
  case 0x61:
    sourceCount = 1;
    goto LAB_97b816c8;
  case 0x58:
  case 0x59:
  case 0x5a:
  case 0x5b:
    sourceCount = 0;
LAB_97b816c8:
    hasDestination = false;
    break;
  case 0x62:
    sourceCount = 4;
  }
  if (hasDestination) {
    if (addressDestination) {
      status = _PPParserParseAddressDestination(parser,&opDest0);
    }
    else {
      status = ((int (*)())_PPParserParseDestination)(parser,&opDest0,opcode);
    }
    if (status != 0) {
      return status;
    }
  }
  loopIndex = 0;
  if (sourceCount != 0) {
    sourceCursor = &opSrc0A;
    do {
      sourceSwizzleInfo[0] = 0;
      if (hasDestination) {
        part = ((int (*)())_PPParserGetPart)(parser,partBuf,0);
        if (part == 0) {
          return 0x2d;
        }
        if (partBuf[0] != ',') {
          return 0x1f;
        }
      }
      if (opcode == 0x41) {
        if (loopIndex == 0) {
          status = ((int (*)())_PPParserParseSourceVar)(parser,&opSrc0A,0x41,sourceSwizzleInfo);
        }
        else {
          status = _PPParserParseSwizzleCode(parser,&opSrc1A);
        }
      }
      else {
        if ((loopIndex == 3) && (opcode == 0x62)) {
          sourceTarget = &opAuxA;
        }
        else {
          if ((loopIndex != 1) || (((1 < opcode - 0x42 && (opcode != 0x46)) && (opcode != 0x44)))) {
            if ((opcode == 0x4a) || (opcode - 0x60 < 2)) {
              status = _PPParserParseAddressSourceVar(parser,&opSrc0A);
            }
            else {
              status = ((int (*)())_PPParserParseSwizzleSourceVar)(parser,sourceCursor,opcode,sourceSwizzleInfo);
            }
            goto LAB_97b818a8;
          }
          sourceTarget = &opSrc1A;
        }
        status = _PPParserParseTextureSourceVar(parser,sourceTarget);
      }
LAB_97b818a8:
      if (status != 0) {
        return status;
      }
      if ((requireScalarSwizzle) && (sourceSwizzleInfo[0] == 0)) {
        return 0x14;
      }
      loopIndex = loopIndex + 1;
      sourceCursor = sourceCursor + 2;
    } while (loopIndex < sourceCount);
  }
  part = ((int (*)())_PPParserGetPart)(parser,partBuf,0);
  resultOrLastOp = 0x2d;
  if ((part != 0) && (resultOrLastOp = 0x1e, partBuf[0] == ';')) {
    status = *(int *)(parser + 0x1c);
    resultOrLastOp = 0x32;
    if (*(uint *)(*(int *)(status + 0x20) + 8) < *(uint *)(parser + 0x45c)) {
      resultOrLastOp = *(int *)(*(int *)(status + 0x20) + 4);
      if (resultOrLastOp == 0) {
        opHeader = sourceCount << 0x1d | opHeader & 0x3ffffff;
      }
      else {
        opHeader = *(uint *)(resultOrLastOp + 0xc) >> 3 & 0x1c000000 | sourceCount << 0x1d | opHeader & 0x3ffffff;
      }
      opWord13 = branchTarget;
      _PPStreamAddOperation(status,&opHeader,branchLabelText,*(undefined1 *)(parser + 0x440));
      *(undefined1 *)(parser + 0x440) = 0;
      resultOrLastOp = 0;
    }
  }
  return resultOrLastOp;
}

/* _PPParserParseDestination @ 0x97b81994 (604 bytes) */
int _PPParserParseDestination(parser, operand, opcode)
  int parser;
  uint *operand;
  int opcode;
{
  int ppParserParseOutputBindingResult;
  int ppParserScopeFindIdentifierResult;
  int arrayResult;
  int status;
  uint identifierKind;
  int part;
  char partBuf [256];
  undefined4 arrayIndex;
  
  status = ((int (*)())_PPParserGetPart)(parser,partBuf,1);
  if (status == 0) {
    return 0x2d;
  }
  ppParserScopeFindIdentifierResult = ((int (*)())_PPParserScopeFindIdentifier)(*(undefined4 *)(parser + 0x44c),partBuf);
  if (ppParserScopeFindIdentifierResult == 0) {
    status = _memcmp(partBuf,"result",7);
    if (status != 0) {
      return 0x19;
    }
    *(undefined2 *)((int)operand + 6) = *(undefined2 *)(parser + 0x2a);
    *operand = *operand & 0xfff1ffff | 0x60000;
    ((int (*)())_PPParserReturnPart)(parser);
    ppParserParseOutputBindingResult = ((int (*)())_PPParserParseOutputBinding)(parser,0);
    if (ppParserParseOutputBindingResult != 0) {
      return ppParserParseOutputBindingResult;
    }
  }
  else {
    arrayIndex = 0;
    if ((opcode - 0x5cU < 4) && (*(int *)(ppParserScopeFindIdentifierResult + 0x14) == 2)) {
      return 0x2c;
    }
    part = ((int (*)())_PPParserGetPart)(parser,partBuf,0);
    if (part == 0) {
      return 0x2d;
    }
    ((int (*)())_PPParserReturnPart)(parser);
    if (partBuf[0] == '[') {
      if (*(char *)(ppParserScopeFindIdentifierResult + 0x10) == '\0') {
        return 0x20;
      }
      arrayResult = ((int (*)())_PPParserParseArray)(parser,&arrayIndex);
      if (arrayResult != 0) {
        return arrayResult;
      }
      if (*(uint *)(ppParserScopeFindIdentifierResult + 4) <= arrayIndex) {
        ((int (*)())_PPParserReturnPart)(parser);
        return 0x23;
      }
    }
    else if (*(char *)(ppParserScopeFindIdentifierResult + 0x10) != '\0') {
      return 0x21;
    }
    *(short *)((int)operand + 6) = *(short *)(ppParserScopeFindIdentifierResult + 10) + (*(unsigned short *)((unsigned char *)&(arrayIndex) + 2));
    identifierKind = *(uint *)(ppParserScopeFindIdentifierResult + 0xc);
    if ((identifierKind != 1) && (identifierKind != 3)) {
      return 0x18;
    }
    *operand = (identifierKind & 7) << 0x11 | *operand & 0xfff1ffff;
  }
  *operand = *operand & 0xf03ffc0f | 0x1b1e06c;
  part = ((int (*)())_PPParserGetPart)(parser,partBuf,0);
  status = 0x2d;
  if (part != 0) {
    if ((partBuf[0] == '.') && (part == 1)) {
      status = _PPParserParseDestinationMask(parser,operand);
      if (status != 0) {
        return status;
      }
    }
    else {
      ((int (*)())_PPParserReturnPart)(parser);
    }
    if (((*(uint *)(parser + 0x48c) & 0x10) == 0) ||
       (status = _PPParserParseBranchCondition(parser,operand,0), status == 0)) {
      status = 0;
    }
  }
  return status;
}

/* _PPParserParseSwizzleSourceVar @ 0x97b81bf0 (460 bytes) */
int _PPParserParseSwizzleSourceVar(parser, operand, opcode, swizzleInfo)
  int parser;
  uint *operand;
  undefined4 opcode;
  undefined4 swizzleInfo;
{
  int part;
  int compareResult;
  int ppParserParseSourceSwizzleResult;
  int status;
  char partBuf [268];
  
  part = ((int (*)())_PPParserGetPart)(parser,partBuf,0);
  status = 0x2d;
  if (part != 0) {
    compareResult = _memcmp(partBuf,"-",2);
    if (compareResult == 0) {
      *operand = *operand | 0x8000000;
    }
    else {
      compareResult = _memcmp(partBuf,"+",2);
      if (compareResult != 0) {
        ((int (*)())_PPParserReturnPart)(parser);
      }
    }
    if ((*(uint *)(parser + 0x48c) & 0x20) != 0) {
      part = ((int (*)())_PPParserGetPart)(parser,partBuf,0);
      if (part == 0) {
        return 0x2d;
      }
      compareResult = _memcmp(partBuf,"|",2);
      if (compareResult == 0) {
        *operand = *operand | 0x4000000;
      }
      else {
        ((int (*)())_PPParserReturnPart)(parser);
      }
    }
    status = ((int (*)())_PPParserParseSourceVar)(parser,operand,opcode,swizzleInfo);
    if (status == 0) {
      part = ((int (*)())_PPParserGetPart)(parser,partBuf,0);
      status = 0x2d;
      if (part != 0) {
        if ((partBuf[0] == '.') && (part == 1)) {
          ppParserParseSourceSwizzleResult = _PPParserParseSourceSwizzle(parser,operand,swizzleInfo);
          if (ppParserParseSourceSwizzleResult != 0) {
            return ppParserParseSourceSwizzleResult;
          }
        }
        else {
          ((int (*)())_PPParserReturnPart)(parser);
        }
        if (((*(uint *)(parser + 0x48c) & 0x20) != 0) && ((*operand & 0x4000000) != 0)) {
          part = ((int (*)())_PPParserGetPart)(parser,partBuf,0);
          if (part == 0) {
            return 0x2d;
          }
          compareResult = _memcmp(partBuf,"|",2);
          if (compareResult != 0) {
            return 0x17;
          }
        }
        status = 0;
      }
    }
  }
  return status;
}

/* _PPParserParseSourceVar @ 0x97b81dbc (696 bytes) */
int _PPParserParseSourceVar(parser, operand, opcode, isLiteral)
  int parser;
  uint *operand;
  int opcode;
  uint *isLiteral;
{
  int ppParserScopeFindIdentifierResult;
  int ppParserParseIndirectArrayResult;
  int part;
  undefined2 ordinal;
  uint operandFlags;
  int status;
  int compareResult;
  char partBuf [256];
  char *literalEnd;
  undefined4 bindingCount;
  undefined4 arrayIndex;
  
  part = ((int (*)())_PPParserGetPart)(parser,partBuf,1);
  if (part == 0) {
    return 0x2d;
  }
  ppParserScopeFindIdentifierResult = ((int (*)())_PPParserScopeFindIdentifier)(*(undefined4 *)(parser + 0x44c),partBuf);
  if (ppParserScopeFindIdentifierResult == 0) {
    if ((*(uint *)(parser + 0x48c) & 2) == 0) {
      compareResult = _memcmp(partBuf,"vertex",7);
    }
    else {
      compareResult = _memcmp(partBuf,"fragment",9);
    }
    if (compareResult == 0) {
      *(undefined2 *)((int)operand + 6) = *(undefined2 *)(parser + 0x26);
      *operand = *operand & 0xfc7fffff;
      ((int (*)())_PPParserReturnPart)(parser);
      status = ((int (*)())_PPParserParseAttributeBinding)(parser);
    }
    else {
      if (((partBuf[0] != '{') && (compareResult = _memcmp(partBuf,"program",8), compareResult != 0)) &&
         (compareResult = _memcmp(partBuf,"state",6), compareResult != 0)) {
        ((double (*)())_glp_strtod)(partBuf,&literalEnd);
        operandFlags = (uint)(literalEnd == partBuf + part);
        *isLiteral = operandFlags;
        if (operandFlags == 0) {
          return 0x1a;
        }
      }
      ordinal = *(undefined2 *)(parser + 0x22);
      *operand = *operand & 0xfc7fffff | 0x1000000;
      *(undefined2 *)((int)operand + 6) = ordinal;
      bindingCount = 1;
      ((int (*)())_PPParserReturnPart)(parser);
      status = ((int (*)())_PPParserParseParamBinding)(parser,0,&bindingCount);
    }
    if (status != 0) {
      return status;
    }
  }
  else {
    arrayIndex = 0;
    if ((opcode - 99U < 4) && (*(int *)(ppParserScopeFindIdentifierResult + 0x14) == 2)) {
      return 0x2b;
    }
    part = ((int (*)())_PPParserGetPart)(parser,partBuf,0);
    if (part == 0) {
      return 0x2d;
    }
    ((int (*)())_PPParserReturnPart)(parser);
    if (partBuf[0] == '[') {
      if (*(char *)(ppParserScopeFindIdentifierResult + 0x10) == '\0') {
        return 0x20;
      }
      ppParserParseIndirectArrayResult = _PPParserParseIndirectArray(parser,operand,&arrayIndex);
      if (ppParserParseIndirectArrayResult != 0) {
        return ppParserParseIndirectArrayResult;
      }
      if (*(uint *)(ppParserScopeFindIdentifierResult + 4) <= arrayIndex) {
        ((int (*)())_PPParserReturnPart)(parser);
        return 0x23;
      }
    }
    else if (*(char *)(ppParserScopeFindIdentifierResult + 0x10) != '\0') {
      return 0x21;
    }
    *(short *)((int)operand + 6) = *(short *)(ppParserScopeFindIdentifierResult + 10) + (*(unsigned short *)((unsigned char *)&(arrayIndex) + 2));
    if (2 < *(uint *)(ppParserScopeFindIdentifierResult + 0xc)) {
      return 0x17;
    }
    *operand = (*(uint *)(ppParserScopeFindIdentifierResult + 0xc) & 7) << 0x17 | *operand & 0xfc7fffff;
  }
  if (*isLiteral == 0) {
    operandFlags = *operand & 0xff89ffff | 0xd8000;
  }
  else {
    operandFlags = *operand & 0xff807fff;
  }
  *operand = operandFlags;
  return 0;
}

/* _PPStreamAddOperation_97b82078 @ 0x97b82078 (216 bytes) */
int _PPStreamAddOperation_97b82078(stream, operationRecord, labelText, keepIndex)
  int stream;
  int operationRecord;
  int labelText;
  int keepIndex;
{
  int maxIndex;
  uint indexWord;
  int chunkSize;
  undefined1 *allocation;
  int labelLength;
  
  labelLength = *(int *)(operationRecord + 0x34);
  chunkSize = 0x38;
  if (labelLength != 0) {
    chunkSize = labelLength + 0x39;
  }
  allocation = (undefined1 *)_calloc(chunkSize + 0xc,1);
  *allocation = 8;
  _memcpy(allocation + 0xc,operationRecord,0x38);
  if ((labelLength != 0) && (labelText != 0)) {
    _memmove(allocation + 0x44,labelText,labelLength);
    allocation[labelLength + 0x44] = 0;
  }
  if (keepIndex == 0) {
    maxIndex = _PPStreamChunkListGetMaxIndex(*(undefined4 *)(stream + 0x20));
    indexWord = maxIndex + 1U & 0x3ffff | *(uint *)(allocation + 0xc) & 0xfffc0000;
  }
  else {
    indexWord = *(uint *)(allocation + 0xc) & 0xfffc0000;
  }
  *(uint *)(allocation + 0xc) = indexWord;
  return ((int (*)())_PPStreamChunkListAddChunk)(*(undefined4 *)(stream + 0x20),allocation);
}

/* _PPParserParseEnd @ 0x97b82150 (136 bytes) */
int _PPParserParseEnd(parser)
  undefined4 parser;
{
  int compareResult;
  int part;
  undefined4 status;
  undefined1 partText [264];
  
  part = ((int (*)())_PPParserGetPart)(parser,partText,0);
  status = 0x2d;
  if (part != 0) {
    compareResult = _memcmp(partText,"END",4);
    status = 6;
    if (compareResult == 0) {
      part = ((int (*)())_PPParserGetPart)(parser,partText,0);
      status = 9;
      if (part == 0) {
        status = 0;
      }
    }
  }
  return status;
}

/* _PPStreamAttribBindingIsEqual @ 0x97b821d8 (88 bytes) */
int _PPStreamAttribBindingIsEqual(chunkBinding, probeBinding)
  undefined4 *chunkBinding;
  undefined4 *probeBinding;
{
  int compareResult;
  undefined4 chunkWord0;
  undefined2 chunkWord1Lo;
  undefined2 chunkWord1Hi;
  undefined4 probeWord0;
  undefined4 probeWord1;
  
  probeWord1 = probeBinding[1];
  chunkWord0 = *chunkBinding;
  probeWord0 = *probeBinding;
  chunkWord1Lo = CONCAT22((short)((uint)chunkBinding[1] >> 0x10),(short)probeWord1);
  compareResult = _memcmp(&chunkWord0,&probeWord0,8);
  return compareResult == 0;
}

/* _PPStreamOutputBindingIsEqual @ 0x97b82230 (88 bytes) */
int _PPStreamOutputBindingIsEqual(chunkBinding, probeBinding)
  undefined4 *chunkBinding;
  undefined4 *probeBinding;
{
  int compareResult;
  undefined4 chunkWord0;
  undefined2 chunkWord1Lo;
  undefined2 chunkWord1Hi;
  undefined4 probeWord0;
  undefined4 probeWord1;
  
  probeWord1 = probeBinding[1];
  chunkWord0 = *chunkBinding;
  probeWord0 = *probeBinding;
  chunkWord1Lo = CONCAT22((short)((uint)chunkBinding[1] >> 0x10),(short)probeWord1);
  compareResult = _memcmp(&chunkWord0,&probeWord0,8);
  return compareResult == 0;
}

/* _PPStreamParamBindingIsEqual @ 0x97b82288 (88 bytes) */
int _PPStreamParamBindingIsEqual(chunkBinding, probeBinding)
  undefined4 *chunkBinding;
  undefined4 *probeBinding;
{
  int compareResult;
  undefined4 chunkWord0;
  undefined2 chunkWord1Lo;
  undefined2 chunkWord1Hi;
  undefined4 probeWord0;
  undefined4 probeWord1;
  
  probeWord1 = probeBinding[1];
  chunkWord0 = *chunkBinding;
  probeWord0 = *probeBinding;
  chunkWord1Lo = CONCAT22((short)((uint)chunkBinding[1] >> 0x10),(short)probeWord1);
  compareResult = _memcmp(&chunkWord0,&probeWord0,8);
  return compareResult == 0;
}

/* _PPStreamChunkListGetStream @ 0x97b822e0 (276 bytes) */
int _PPStreamChunkListGetStream(chunkList, entries, entryCount, context)
  int *chunkList;
  int entries;
  int *entryCount;
  undefined4 context;
{
  int entryIndex;
  int chunk;
  uint loopIndex;
  int entryPtr;
  undefined1 countOnlyEntry [16];
  uint chunkEntryCount;
  undefined1 extraEntry [16];
  
  entryIndex = 0;
  chunk = *chunkList;
  *entryCount = 0;
  for (; chunk != 0; chunk = *(int *)(chunk + 8)) {
    ((int (*)())_PPStreamChunkGetStream)(countOnlyEntry,chunk,context,&chunkEntryCount,0);
    *entryCount = *entryCount + chunkEntryCount;
  }
  if (entries != 0) {
    for (chunk = *chunkList; chunk != 0; chunk = *(int *)(chunk + 8)) {
      ((int (*)())_PPStreamChunkGetStream)(entryIndex * 8 + entries,chunk,context,&chunkEntryCount,0);
      entryIndex = entryIndex + 1;
      if (1 < chunkEntryCount) {
        chunkEntryCount = chunkEntryCount - 1;
        loopIndex = 0;
        if (chunkEntryCount != 0) {
          entryPtr = entryIndex * 8 + entries;
          do {
            loopIndex = loopIndex + 1;
            ((int (*)())_PPStreamChunkGetStream)(entryPtr,chunk,context,extraEntry,loopIndex);
            entryIndex = entryIndex + 1;
            entryPtr = entryPtr + 8;
          } while (loopIndex < chunkEntryCount);
        }
      }
    }
  }
  return;
}

/* _PPStreamChunkGetStream @ 0x97b823f4 (184 bytes) */
int _PPStreamChunkGetStream(outEntry, chunk, context, entryCountOut, entryIndex)
  undefined4 *outEntry;
  undefined1 *chunk;
  undefined4 context;
  int *entryCountOut;
  int entryIndex;
{
  undefined4 entryWord1;
  undefined4 entryWord0;
  
  *entryCountOut = 1;
  switch(*chunk) {
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
    entryWord1 = (*(unsigned int *)0x00000004);
    entryWord0 = (*(unsigned int *)0x00000000);
    goto LAB_97b824b4;
  case 8:
    *entryCountOut = (*(uint *)(chunk + 0xc) >> 0x1d) + 2;
    if (entryIndex != 0) {
      if (entryIndex == 1) {
        entryWord1 = *(undefined4 *)(chunk + 0x18);
        entryWord0 = *(undefined4 *)(chunk + 0x14);
        goto LAB_97b82490;
      }
      goto LAB_97b824a8;
    }
switchD_97b82430_caseD_0:
    entryWord1 = *(undefined4 *)(chunk + 0x10);
    entryWord0 = *(undefined4 *)(chunk + 0xc);
LAB_97b82490:
    outEntry[1] = entryWord1;
    *outEntry = entryWord0;
    return;
  case 10:
    *entryCountOut = 2;
LAB_97b824a8:
    entryWord1 = *(undefined4 *)(chunk + entryIndex * 8 + 0x10);
    entryWord0 = *(undefined4 *)(chunk + entryIndex * 8 + 0xc);
LAB_97b824b4:
    outEntry[1] = entryWord1;
    *outEntry = entryWord0;
    return;
  }
}

/* _PPStreamChunkListCreateFromChunkList @ 0x97b824dc (96 bytes) */
int _PPStreamChunkListCreateFromChunkList(sourceList)
  int *sourceList;
{
  undefined4 chunkList;
  undefined4 chunk;
  int sourceChunk;
  
  chunkList = ((int (*)())_PPStreamChunkListCreate)();
  for (sourceChunk = *sourceList; sourceChunk != 0; sourceChunk = *(int *)(sourceChunk + 8)) {
    chunk = ((int (*)())_PPStreamChunkCreateFromChunk)(sourceChunk);
    ((int (*)())_PPStreamChunkListAddChunk)(chunkList,chunk);
  }
  return chunkList;
}

/* _PPStreamChunkCreateFromChunk @ 0x97b8253c (128 bytes) */
int _PPStreamChunkCreateFromChunk(chunk)
  byte *chunk;
{
  uint chunkKind;
  int chunkAllocationSize;
  int newChunk;
  undefined4 extraWord;
  
  extraWord = 0;
  chunkKind = (uint)*chunk;
  if (chunkKind == 8) {
    extraWord = *(undefined4 *)(chunk + 0x40);
  }
  else if (chunkKind == 0xb) {
    extraWord = *(undefined4 *)(chunk + 0x10);
  }
  chunkAllocationSize = _GetChunkAllocationSize(chunkKind,extraWord);
  newChunk = _calloc(chunkAllocationSize + 0xc,1);
  _memmove(newChunk,chunk,chunkAllocationSize + 0xc);
  *(undefined4 *)(newChunk + 4) = 0;
  *(undefined4 *)(newChunk + 8) = 0;
  return newChunk;
}

