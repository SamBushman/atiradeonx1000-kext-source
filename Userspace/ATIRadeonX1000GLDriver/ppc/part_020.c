#include "decls.h"

/* ildisPrintShadowMode @ 0xdbcdc (192 bytes) */
int ildisPrintShadowMode(disassembler, shadowModeWord, passThroughR5, fmtArgR6, fmtArgR7, fmtArgR8, fmtArgR9, fmtArgR10)
  int *disassembler;
  uint shadowModeWord;
  undefined4 passThroughR5;
  undefined4 fmtArgR6;
  undefined4 fmtArgR7;
  undefined4 fmtArgR8;
  undefined4 fmtArgR9;
  undefined4 fmtArgR10;
{
  uint shadowModeCode;
  
  shadowModeCode = shadowModeWord >> 0x1a & 3;
  ildisAppendf(disassembler,"_shadowmode(",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  if (shadowModeCode == 1) {
    ildisAppendf(disassembler,"z",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  }
  else if (shadowModeCode == 0) {
    ildisAppendf(disassembler,"never",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  }
  else if (shadowModeCode == 2) {
    ildisAppendf(disassembler,"unknown",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  }
  else {
    *disassembler = *disassembler + 1;
    ildisAppendf(disassembler,"!!invalid!!",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  }
  ildisAppendf(disassembler,")",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  return;
}

/* ildisPrintBoundComponent @ 0xdbd9c (124 bytes) */
int ildisPrintBoundComponent(disassembler, boundCode, passThroughR5, fmtArgR6, fmtArgR7, fmtArgR8, fmtArgR9)
  int *disassembler;
  int boundCode;
  undefined4 passThroughR5;
  undefined4 fmtArgR6;
  undefined4 fmtArgR7;
  undefined4 fmtArgR8;
  undefined4 fmtArgR9;
{
  if (boundCode == 1) {
    ildisAppendf(disassembler,"0",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,0xdbda8);
    return;
  }
  if (boundCode == 0) {
    ildisAppendf(disassembler,"-",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,0xdbda8);
    return;
  }
  if (boundCode == 2) {
    ildisAppendf(disassembler,"1",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,0xdbda8);
    return;
  }
  if (boundCode == 3) {
    ildisAppendf(disassembler,"*",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,0xdbda8);
    return;
  }
  *disassembler = *disassembler + 1;
  return ildisAppendf(disassembler,"!!!invalid!!!",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,0xdbda8);
}

/* ildisPrintDclvoutOperands @ 0xdbe18 (284 bytes) */
int ildisPrintDclvoutOperands(disassembler, declarationWord, passThroughR5, fmtArgR6, fmtArgR7, fmtArgR8, fmtArgR9, fmtArgR10)
  int disassembler;
  uint declarationWord;
  undefined4 passThroughR5;
  undefined4 fmtArgR6;
  undefined4 fmtArgR7;
  undefined4 fmtArgR8;
  undefined4 fmtArgR9;
  undefined4 fmtArgR10;
{
  uint usageIndexValue;
  uint componentWord;
  undefined1 textBuffer [40];
  
  ildisPrintUsage(disassembler,declarationWord >> 0x10 & 0x1f,passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  usageIndexValue = declarationWord >> 0x15 & 0xff;
  printf_LDBLStub_1a32d0(textBuffer,"_usageIndex(%d)",usageIndexValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  ildisAppendf(disassembler,textBuffer,usageIndexValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  if ((int)declarationWord < 0) {
    componentWord = **(uint **)(disassembler + 8);
    *(uint **)(disassembler + 8) = *(uint **)(disassembler + 8) + 1;
    ildisAppendf(disassembler,"_x(",usageIndexValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    ((int (*)())ildisPrintBoundComponent)(disassembler,componentWord & 3,usageIndexValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
    ildisAppendf(disassembler,")",usageIndexValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    ildisAppendf(disassembler,"_y(",usageIndexValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    ((int (*)())ildisPrintBoundComponent)(disassembler,componentWord >> 2 & 3,usageIndexValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
    ildisAppendf(disassembler,")",usageIndexValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    ildisAppendf(disassembler,"_z(",usageIndexValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    ((int (*)())ildisPrintBoundComponent)(disassembler,componentWord >> 4 & 3,usageIndexValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
    ildisAppendf(disassembler,")",usageIndexValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    ildisAppendf(disassembler,"_w(",usageIndexValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    ((int (*)())ildisPrintBoundComponent)(disassembler,componentWord >> 6 & 3,usageIndexValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
    ildisAppendf(disassembler,")",usageIndexValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  }
  return;
}

/* ildisPrintDclpinOperands @ 0xdbf34 (356 bytes) */
int ildisPrintDclpinOperands(disassembler, declarationWord, passThroughR5, fmtArgR6, fmtArgR7, fmtArgR8, fmtArgR9, fmtArgR10)
  int disassembler;
  uint declarationWord;
  undefined4 passThroughR5;
  undefined4 fmtArgR6;
  undefined4 fmtArgR7;
  undefined4 fmtArgR8;
  undefined4 fmtArgR9;
  undefined4 fmtArgR10;
{
  uint usageIndexValue;
  uint componentWord;
  undefined1 textBuffer [40];
  
  ildisPrintUsage(disassembler,declarationWord >> 0x10 & 0x1f,passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  usageIndexValue = declarationWord >> 0x15 & 0xff;
  printf_LDBLStub_1a32d0(textBuffer,"_usageIndex(%d)",usageIndexValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  ildisAppendf(disassembler,textBuffer,usageIndexValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  if ((int)declarationWord < 0) {
    componentWord = **(uint **)(disassembler + 8);
    *(uint **)(disassembler + 8) = *(uint **)(disassembler + 8) + 1;
    ildisAppendf(disassembler,"_x(",usageIndexValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    ((int (*)())ildisPrintBoundComponent)(disassembler,componentWord & 3,usageIndexValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
    ildisAppendf(disassembler,")",usageIndexValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    ildisAppendf(disassembler,"_y(",usageIndexValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    ((int (*)())ildisPrintBoundComponent)(disassembler,componentWord >> 2 & 3,usageIndexValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
    ildisAppendf(disassembler,")",usageIndexValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    ildisAppendf(disassembler,"_z(",usageIndexValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    ((int (*)())ildisPrintBoundComponent)(disassembler,componentWord >> 4 & 3,usageIndexValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
    ildisAppendf(disassembler,")",usageIndexValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    ildisAppendf(disassembler,"_w(",usageIndexValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    ((int (*)())ildisPrintBoundComponent)(disassembler,componentWord >> 6 & 3,usageIndexValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
    ildisAppendf(disassembler,")",usageIndexValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    if ((componentWord & 0x100) != 0) {
      ildisAppendf(disassembler,"_centroid",usageIndexValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    }
    if ((componentWord & 0x200) != 0) {
      ildisAppendf(disassembler,"_constant",usageIndexValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    }
    if ((componentWord & 0x400) != 0) {
      ildisAppendf(disassembler,"_noperspective",usageIndexValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    }
  }
  return;
}

/* ildisPrintDclvOperands @ 0xdc098 (276 bytes) */
int ildisPrintDclvOperands(disassembler, declarationWord, passThroughR5, fmtArgR6, fmtArgR7, fmtArgR8, fmtArgR9, fmtArgR10)
  int disassembler;
  uint declarationWord;
  undefined4 passThroughR5;
  undefined4 fmtArgR6;
  undefined4 fmtArgR7;
  undefined4 fmtArgR8;
  undefined4 fmtArgR9;
  undefined4 fmtArgR10;
{
  uint elementIndex;
  uint componentWord;
  undefined1 textBuffer [40];
  
  elementIndex = declarationWord >> 0x10 & 0x3f;
  printf_LDBLStub_1a32d0(textBuffer,"_elem(%d)",elementIndex,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  ildisAppendf(disassembler,textBuffer,elementIndex,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  if ((int)declarationWord < 0) {
    componentWord = **(uint **)(disassembler + 8);
    *(uint **)(disassembler + 8) = *(uint **)(disassembler + 8) + 1;
    ildisAppendf(disassembler,"_x(",elementIndex,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    ((int (*)())ildisPrintBoundComponent)(disassembler,componentWord & 3,elementIndex,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
    ildisAppendf(disassembler,")",elementIndex,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    ildisAppendf(disassembler,"_y(",elementIndex,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    ((int (*)())ildisPrintBoundComponent)(disassembler,componentWord >> 2 & 3,elementIndex,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
    ildisAppendf(disassembler,")",elementIndex,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    ildisAppendf(disassembler,"_z(",elementIndex,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    ((int (*)())ildisPrintBoundComponent)(disassembler,componentWord >> 4 & 3,elementIndex,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
    ildisAppendf(disassembler,")",elementIndex,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    ildisAppendf(disassembler,"_w(",elementIndex,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    ((int (*)())ildisPrintBoundComponent)(disassembler,componentWord >> 6 & 3,elementIndex,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
    ildisAppendf(disassembler,")",elementIndex,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  }
  return;
}

/* ildisPrintDclpiOperands @ 0xdc1ac (280 bytes) */
int ildisPrintDclpiOperands(disassembler, declarationWord, passThroughR5, fmtArgR6, fmtArgR7, fmtArgR8, fmtArgR9, fmtArgR10)
  undefined4 disassembler;
  uint declarationWord;
  undefined4 passThroughR5;
  undefined4 fmtArgR6;
  undefined4 fmtArgR7;
  undefined4 fmtArgR8;
  undefined4 fmtArgR9;
  undefined4 fmtArgR10;
{
  ildisAppendf(disassembler,"_x(",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  ((int (*)())ildisPrintBoundComponent)(disassembler,declarationWord >> 0x10 & 3,passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
  ildisAppendf(disassembler,")",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  ildisAppendf(disassembler,"_y(",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  ((int (*)())ildisPrintBoundComponent)(disassembler,declarationWord >> 0x12 & 3,passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
  ildisAppendf(disassembler,")",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  ildisAppendf(disassembler,"_z(",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  ((int (*)())ildisPrintBoundComponent)(disassembler,declarationWord >> 0x14 & 3,passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
  ildisAppendf(disassembler,")",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  ildisAppendf(disassembler,"_w(",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  ((int (*)())ildisPrintBoundComponent)(disassembler,declarationWord >> 0x16 & 3,passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
  ildisAppendf(disassembler,")",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  if ((declarationWord & 0x1000000) != 0) {
    ildisAppendf(disassembler,"_center",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  }
  if ((declarationWord & 0x2000000) != 0) {
    ildisAppendf(disassembler,"_origin",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    return;
  }
  return;
}

/* ildisPrintResourceType @ 0xdc2c4 (196 bytes) */
int ildisPrintResourceType(disassembler, resourceTypeCode, passThroughR5, fmtArgR6, fmtArgR7, fmtArgR8, fmtArgR9)
  int *disassembler;
  uint resourceTypeCode;
  undefined4 passThroughR5;
  undefined4 fmtArgR6;
  undefined4 fmtArgR7;
  undefined4 fmtArgR8;
  undefined4 fmtArgR9;
{
  int passThroughR9Zero;
  
  if (resourceTypeCode < 10) {
    passThroughR9Zero = 0;
    switch(resourceTypeCode) {
    case 0:
      ildisAppendf(disassembler,"_type(unknown)",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,passThroughR9Zero,0xdc2d0);
      return;
    case 1:
      ildisAppendf(disassembler,"_type(1d)",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,passThroughR9Zero,0xdc2d0);
      return;
    case 2:
      ildisAppendf(disassembler,"_type(2d)",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,passThroughR9Zero,0xdc2d0);
      return;
    case 3:
      ildisAppendf(disassembler,"_type(3d)",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,passThroughR9Zero,0xdc2d0);
      return;
    case 4:
      ildisAppendf(disassembler,"_type(cubemap)",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,passThroughR9Zero,0xdc2d0);
      return;
    case 5:
      ildisAppendf(disassembler,"_type(2dmsaa)",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,passThroughR9Zero,0xdc2d0);
      return;
    case 6:
      ildisAppendf(disassembler,"_type(4c)",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,passThroughR9Zero,0xdc2d0);
      return;
    case 7:
      ildisAppendf(disassembler,"_type(buffer)",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,passThroughR9Zero,0xdc2d0);
      return;
    case 8:
      ildisAppendf(disassembler,"_type(1darray)",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,passThroughR9Zero,0xdc2d0);
      return;
    case 9:
      ildisAppendf(disassembler,"_type(2darray)",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,passThroughR9Zero,0xdc2d0);
      return;
    }
  }
  *disassembler = *disassembler + 1;
  ildisAppendf(disassembler,"_type(!!!invalid!!!)",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,0xdc2d0);
  return;
}

/* ildisPrintDclptCoordMode @ 0xdc3b0 (164 bytes) */
int ildisPrintDclptCoordMode(disassembler, declarationWord, passThroughR5, fmtArgR6, fmtArgR7, fmtArgR8, fmtArgR9)
  int *disassembler;
  uint declarationWord;
  undefined4 passThroughR5;
  undefined4 fmtArgR6;
  undefined4 fmtArgR7;
  undefined4 fmtArgR8;
  undefined4 fmtArgR9;
{
  char *coordModeText;
  undefined4 in_r10;
  uint coordModeCode;
  
  coordModeCode = declarationWord >> 0x1b & 3;
  ((int (*)())ildisPrintResourceType)(disassembler,declarationWord >> 0x18 & 7,passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
  if (coordModeCode == 1) {
    coordModeText = "_coordmode(normalized)";
  }
  else if (coordModeCode == 0) {
    coordModeText = "_coordmode(unknown)";
  }
  else if (coordModeCode == 2) {
    coordModeText = "_coordmode(unnormalized)";
  }
  else {
    coordModeText = "_coordmode(!!!invalid!!!)";
    *disassembler = *disassembler + 1;
  }
  return ildisAppendf(disassembler,coordModeText,passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,in_r10);
}

/* ildisPrintDcldefComponent @ 0xdc454 (104 bytes) */
int ildisPrintDcldefComponent(disassembler, componentCode, passThroughR5, fmtArgR6, fmtArgR7, fmtArgR8, fmtArgR9)
  int *disassembler;
  int componentCode;
  undefined4 passThroughR5;
  undefined4 fmtArgR6;
  undefined4 fmtArgR7;
  undefined4 fmtArgR8;
  undefined4 fmtArgR9;
{
  if (componentCode == 1) {
    ildisAppendf(disassembler,"0",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,0xdc460);
    return;
  }
  if (componentCode != 0) {
    if (componentCode == 2) {
      ildisAppendf(disassembler,"1",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,0xdc460);
      return;
    }
    *disassembler = *disassembler + 1;
    ildisAppendf(disassembler,"!!!invalid!!!",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,0xdc460);
    return;
  }
  return ildisAppendf(disassembler,"*",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,0xdc460);
}

/* ildisPrintDcldefComponents @ 0xdc4bc (192 bytes) */
int ildisPrintDcldefComponents(disassembler, componentsWord, passThroughR5, fmtArgR6, fmtArgR7, fmtArgR8, fmtArgR9, fmtArgR10)
  undefined4 disassembler;
  uint componentsWord;
  undefined4 passThroughR5;
  undefined4 fmtArgR6;
  undefined4 fmtArgR7;
  undefined4 fmtArgR8;
  undefined4 fmtArgR9;
  undefined4 fmtArgR10;
{
  uint componentsWordHome;
  undefined4 passThroughR5Home;
  
  componentsWordHome = componentsWord;
  passThroughR5Home = passThroughR5;
  ildisAppendf(disassembler,"_x(",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  ((int (*)())ildisPrintDcldefComponent)(disassembler,componentsWordHome >> 8 & 3,passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
  ildisAppendf(disassembler,")_y(",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  ((int (*)())ildisPrintDcldefComponent)(disassembler,componentsWordHome >> 10 & 3,passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
  ildisAppendf(disassembler,")_z(",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  ((int (*)())ildisPrintDcldefComponent)(disassembler,componentsWordHome >> 0xc & 3,passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
  ildisAppendf(disassembler,")_w(",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  ((int (*)())ildisPrintDcldefComponent)(disassembler,componentsWordHome >> 0xe & 3,passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
  ildisAppendf(disassembler,")",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  return;
}

/* ildisPrintZeroOp @ 0xdc57c (220 bytes) */
int ildisPrintZeroOp(disassembler, zeroOpWord, passThroughR5, fmtArgR6, fmtArgR7, fmtArgR8, fmtArgR9, fmtArgR10)
  int *disassembler;
  uint zeroOpWord;
  undefined4 passThroughR5;
  undefined4 fmtArgR6;
  undefined4 fmtArgR7;
  undefined4 fmtArgR8;
  undefined4 fmtArgR9;
  undefined4 fmtArgR10;
{
  uint zeroOpCode;
  
  zeroOpCode = zeroOpWord >> 0x10 & 3;
  ildisAppendf(disassembler,"_zeroop(",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  if (zeroOpCode == 1) {
    ildisAppendf(disassembler,"zero",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  }
  else if (zeroOpCode == 0) {
    ildisAppendf(disassembler,"fltmax",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  }
  else if (zeroOpCode == 2) {
    ildisAppendf(disassembler,"infinity",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  }
  else if (zeroOpCode == 3) {
    ildisAppendf(disassembler,"inf_else_max",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  }
  else {
    *disassembler = *disassembler + 1;
    ildisAppendf(disassembler,"!!!invalid!!!",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  }
  ildisAppendf(disassembler,")",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  return;
}

/* ildisPrintOutputTopology @ 0xdc658 (196 bytes) */
int ildisPrintOutputTopology(disassembler, instructionToken, fmtArgR5, fmtArgR6, fmtArgR7, fmtArgR8, fmtArgR9, fmtArgR10)
  undefined4 disassembler;
  uint instructionToken;
  undefined4 fmtArgR5;
  undefined4 fmtArgR6;
  undefined4 fmtArgR7;
  undefined4 fmtArgR8;
  char *fmtArgR9;
  undefined4 fmtArgR10;
{
  uint uVar1;
  char local_38 [4];
  char local_34 [4];
  char local_30 [4];
  char local_2c [40];
  
  uVar1 = instructionToken >> 0x10 & 0x3fff;
  if (uVar1 == 1) {
    fmtArgR9 = "_line_strip";
    *(unsigned int *)local_38 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s__line_strip_001a82c4) + 0));
    *(unsigned int *)local_34 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s__line_strip_001a82c4) + 4));
    *(unsigned int *)local_30 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s__line_strip_001a82c4) + 8));
  }
  else if (uVar1 == 0) {
    fmtArgR9 = "_point_list";
    *(unsigned int *)local_38 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s__point_list_001a82b8) + 0));
    *(unsigned int *)local_34 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s__point_list_001a82b8) + 4));
    *(unsigned int *)local_30 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s__point_list_001a82b8) + 8));
  }
  else if (uVar1 == 2) {
    *(unsigned int *)local_38 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s__triangle_strip_001a82d0) + 0));
    *(unsigned int *)local_34 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s__triangle_strip_001a82d0) + 4));
    *(unsigned int *)local_30 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s__triangle_strip_001a82d0) + 8));
    (*(unsigned int *)((unsigned char *)&(local_2c) + 0)) = (*(unsigned int *)((unsigned char *)&(s__triangle_strip_001a82d0) + 12));
    fmtArgR9 = (char *)(*(unsigned int *)((unsigned char *)&(s__triangle_strip_001a82d0) + 0));
    fmtArgR10 = (*(unsigned int *)((unsigned char *)&(s__triangle_strip_001a82d0) + 12));
  }
  return ildisAppendf(disassembler,local_38,fmtArgR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
}

/* ildisPrintInputPrimitive @ 0xdc71c (268 bytes) */
int ildisPrintInputPrimitive(disassembler, instructionToken, fmtArgR5, fmtArgR6, fmtArgR7, fmtArgR8, fmtArgR9, fmtArgR10)
  undefined4 disassembler;
  uint instructionToken;
  undefined4 fmtArgR5;
  undefined4 fmtArgR6;
  undefined4 fmtArgR7;
  undefined4 fmtArgR8;
  char *fmtArgR9;
  uint fmtArgR10;
{
  char local_38 [4];
  char local_34;
  char acStack_33 [3];
  char local_30 [4];
  char local_2c [40];
  
  switch(instructionToken >> 0x10 & 0x3fff) {
  case 0:
    fmtArgR9 = "_point";
    *(unsigned int *)local_38 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s__point_001a82e0) + 0));
    (*(unsigned short *)((unsigned char *)&(acStack_33) + 0)) = (*(unsigned short *)((unsigned char *)&(s__point_001a82e0) + 5));
    local_34 = s__point_001a82e0[4];
    break;
  case 1:
    fmtArgR9 = "_line";
    *(unsigned int *)local_38 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s__line_001a82e8) + 0));
    local_34 = (*(unsigned short *)((unsigned char *)&(s__line_001a82e8) + 4));
    break;
  case 2:
    fmtArgR9 = "_triangle";
    *(unsigned int *)local_38 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s__triangle_001a82f0) + 0));
    local_34 = (*(unsigned int *)((unsigned char *)&(s__triangle_001a82f0) + 4));
    (*(unsigned short *)((unsigned char *)&(local_30) + 0)) = (*(unsigned short *)((unsigned char *)&(s__triangle_001a82f0) + 8));
    break;
  case 3:
    fmtArgR9 = "_line_adj";
    *(unsigned int *)local_38 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s__line_adj_001a82fc) + 0));
    local_34 = (*(unsigned int *)((unsigned char *)&(s__line_adj_001a82fc) + 4));
    (*(unsigned short *)((unsigned char *)&(local_30) + 0)) = (*(unsigned short *)((unsigned char *)&(s__line_adj_001a82fc) + 8));
    break;
  case 4:
    fmtArgR10 = (uint)(ushort)(*(unsigned short *)((unsigned char *)&(s__triangle_adj_001a8308) + 12));
    *(unsigned int *)local_38 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s__triangle_adj_001a8308) + 0));
    local_34 = (*(unsigned int *)((unsigned char *)&(s__triangle_adj_001a8308) + 4));
    *(unsigned int *)local_30 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s__triangle_adj_001a8308) + 8));
    (*(unsigned short *)((unsigned char *)&(local_2c) + 0)) = (*(unsigned short *)((unsigned char *)&(s__triangle_adj_001a8308) + 12));
    fmtArgR9 = (char *)(*(unsigned int *)((unsigned char *)&(s__triangle_adj_001a8308) + 0));
  }
  ildisAppendf(disassembler,local_38,fmtArgR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  return;
}

/* ildisPrintStage @ 0xdc83c (80 bytes) */
int ildisPrintStage(disassembler, stageWord, passThroughR5, fmtArgR6, fmtArgR7, fmtArgR8, fmtArgR9, fmtArgR10)
  undefined4 disassembler;
  uint stageWord;
  undefined4 passThroughR5;
  undefined4 fmtArgR6;
  undefined4 fmtArgR7;
  undefined4 fmtArgR8;
  undefined4 fmtArgR9;
  undefined4 fmtArgR10;
{
  uint stageIndex;
  undefined1 textBuffer [44];
  
  stageIndex = stageWord >> 0x10 & 0xff;
  printf_LDBLStub_1a32d0(textBuffer,"_stage(%d)",stageIndex,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  return ildisAppendf(disassembler,textBuffer,stageIndex,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
}

/* ildisPrintTexldmsModifiers @ 0xdc88c (324 bytes) */
int ildisPrintTexldmsModifiers(disassembler, controlWord, passThroughR5, fmtArgR6, fmtArgR7, fmtArgR8, fmtArgR9, fmtArgR10)
  int disassembler;
  uint controlWord;
  undefined4 passThroughR5;
  undefined4 fmtArgR6;
  undefined4 fmtArgR7;
  undefined4 fmtArgR8;
  undefined4 fmtArgR9;
  undefined4 fmtArgR10;
{
  undefined4 integerBitsArg;
  undefined4 fractionBitsArg;
  uint extraWord;
  double dVar4;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  double in_stack_ffffffa8;
  double in_stack_ffffffb0;
  double in_stack_ffffffb8;
  double in_stack_ffffffc0;
  
  ((int (*)())ildisPrintStage)(disassembler,controlWord,passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  if ((int)controlWord < 0) {
    extraWord = **(uint **)(disassembler + 8);
    *(uint **)(disassembler + 8) = *(uint **)(disassembler + 8) + 1;
    ildisAppendf(disassembler,"_mag(",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    ildisPrintFilterName(disassembler,extraWord & 7,passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
    ildisAppendf(disassembler,")",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    ildisAppendf(disassembler,"_min(",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    ildisPrintFilterName(disassembler,extraWord >> 3 & 7,passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
    ildisAppendf(disassembler,")",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    ildisPrintAnisoMode(disassembler,extraWord >> 0xf & 7,passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  }
  if ((controlWord & 0x40000000) != 0) {
    extraWord = **(uint **)(disassembler + 8);
    *(uint **)(disassembler + 8) = *(uint **)(disassembler + 8) + 1;
    dVar4 = (double)ildisAppendf(disassembler,"_xoffset(",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10
                                );
    integerBitsArg = 7;
    fractionBitsArg = 1;
    ((void (*)())ildisPrintFixedPoint)(disassembler,extraWord & 0xff,7,1,dVar4,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                 in_stack_ffffffa8,in_stack_ffffffb0,in_stack_ffffffb8,in_stack_ffffffc0);
    ildisAppendf(disassembler,")",integerBitsArg,fractionBitsArg,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    dVar4 = (double)ildisAppendf(disassembler,"_yoffset(",integerBitsArg,fractionBitsArg,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    integerBitsArg = 7;
    fractionBitsArg = 1;
    ((void (*)())ildisPrintFixedPoint)(disassembler,extraWord >> 8 & 0xff,7,1,dVar4,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                 in_stack_ffffffa8,in_stack_ffffffb0,in_stack_ffffffb8,in_stack_ffffffc0);
    ildisAppendf(disassembler,")",integerBitsArg,fractionBitsArg,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    return;
  }
  return;
}

/* ildisPrintNormalizeFlag @ 0xdc9d0 (36 bytes) */
int ildisPrintNormalizeFlag(disassembler, controlWord, passThroughR5, fmtArgR6, fmtArgR7, fmtArgR8, fmtArgR9)
  undefined4 disassembler;
  uint controlWord;
  undefined4 passThroughR5;
  undefined4 fmtArgR6;
  undefined4 fmtArgR7;
  undefined4 fmtArgR8;
  undefined4 fmtArgR9;
{
  if ((controlWord & 0x10000) == 0) {
    return;
  }
  return ildisAppendf(disassembler,"_normalize",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,0xdc9d8);
}

/* ildisPrintRoundFlag @ 0xdc9f4 (36 bytes) */
int ildisPrintRoundFlag(disassembler, controlWord, passThroughR5, fmtArgR6, fmtArgR7, fmtArgR8, fmtArgR9)
  undefined4 disassembler;
  uint controlWord;
  undefined4 passThroughR5;
  undefined4 fmtArgR6;
  undefined4 fmtArgR7;
  undefined4 fmtArgR8;
  undefined4 fmtArgR9;
{
  if ((controlWord & 0x10000) == 0) {
    return;
  }
  return ildisAppendf(disassembler,"_round",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,0xdc9fc);
}

/* ildisPrintSampleFlag @ 0xdca18 (36 bytes) */
int ildisPrintSampleFlag(disassembler, controlWord, passThroughR5, fmtArgR6, fmtArgR7, fmtArgR8, fmtArgR9)
  undefined4 disassembler;
  uint controlWord;
  undefined4 passThroughR5;
  undefined4 fmtArgR6;
  undefined4 fmtArgR7;
  undefined4 fmtArgR8;
  undefined4 fmtArgR9;
{
  if ((controlWord & 0x1000000) == 0) {
    return;
  }
  return ildisAppendf(disassembler,"_sample",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,0xdca20);
}

/* ildisPrintCentroidFlag @ 0xdca3c (36 bytes) */
int ildisPrintCentroidFlag(disassembler, controlWord, passThroughR5, fmtArgR6, fmtArgR7, fmtArgR8, fmtArgR9)
  undefined4 disassembler;
  uint controlWord;
  undefined4 passThroughR5;
  undefined4 fmtArgR6;
  undefined4 fmtArgR7;
  undefined4 fmtArgR8;
  undefined4 fmtArgR9;
{
  if ((controlWord & 0x1000000) == 0) {
    return;
  }
  return ildisAppendf(disassembler,"_centroid",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,0xdca44);
}

/* ildisPrintSampleModifiers @ 0xdca60 (212 bytes) */
int ildisPrintSampleModifiers(disassembler, controlWord, passThroughR5, fmtArgR6, fmtArgR7, fmtArgR8, fmtArgR9, fmtArgR10)
  int disassembler;
  uint controlWord;
  undefined4 passThroughR5;
  undefined4 fmtArgR6;
  undefined4 fmtArgR7;
  undefined4 fmtArgR8;
  undefined4 fmtArgR9;
  undefined4 fmtArgR10;
{
  undefined4 offsetsWord;
  uint filterWord;
  
  ((int (*)())ildisPrintStage)(disassembler,controlWord,passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  ((int (*)())ildisPrintCentroidFlag)(disassembler,controlWord,passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
  if ((controlWord & 0x2000000) != 0) {
    ildisAppendf(disassembler,"_absolute",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  }
  ((int (*)())ildisPrintShadowMode)(disassembler,controlWord,passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  if ((int)controlWord < 0) {
    filterWord = **(uint **)(disassembler + 8);
    *(uint **)(disassembler + 8) = *(uint **)(disassembler + 8) + 1;
    ildisPrintFilterModes(disassembler,filterWord,passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    if ((filterWord & 0x2000000) != 0) {
      ildisAppendf(disassembler,"_qualitybias",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    }
  }
  if ((controlWord & 0x40000000) != 0) {
    offsetsWord = **(undefined4 **)(disassembler + 8);
    *(undefined4 **)(disassembler + 8) = *(undefined4 **)(disassembler + 8) + 1;
    ildisPrintTexelOffsets(disassembler,offsetsWord,passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    return;
  }
  return;
}

/* ildisPrintLoadModifiers @ 0xdcb34 (152 bytes) */
int ildisPrintLoadModifiers(disassembler, controlWord, passThroughR5, fmtArgR6, fmtArgR7, fmtArgR8, fmtArgR9, fmtArgR10)
  int disassembler;
  uint controlWord;
  undefined4 passThroughR5;
  undefined4 fmtArgR6;
  undefined4 fmtArgR7;
  undefined4 fmtArgR8;
  undefined4 fmtArgR9;
  undefined4 fmtArgR10;
{
  undefined4 extraWord;
  
  ((int (*)())ildisPrintStage)(disassembler,controlWord,passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  ((int (*)())ildisPrintCentroidFlag)(disassembler,controlWord,passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
  ((int (*)())ildisPrintShadowMode)(disassembler,controlWord,passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  if ((int)controlWord < 0) {
    extraWord = **(undefined4 **)(disassembler + 8);
    *(undefined4 **)(disassembler + 8) = *(undefined4 **)(disassembler + 8) + 1;
    ildisPrintFilterModes(disassembler,extraWord,passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  }
  if ((controlWord & 0x40000000) != 0) {
    extraWord = **(undefined4 **)(disassembler + 8);
    *(undefined4 **)(disassembler + 8) = *(undefined4 **)(disassembler + 8) + 1;
    ildisPrintTexelOffsets(disassembler,extraWord,passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    return;
  }
  return;
}

/* ildisPrintMatrixMode @ 0xdcbcc (244 bytes) */
int ildisPrintMatrixMode(disassembler, matrixModeWord, passThroughR5, fmtArgR6, fmtArgR7, fmtArgR8, fmtArgR9, fmtArgR10)
  int *disassembler;
  uint matrixModeWord;
  undefined4 passThroughR5;
  undefined4 fmtArgR6;
  undefined4 fmtArgR7;
  undefined4 fmtArgR8;
  int fmtArgR9;
  undefined4 fmtArgR10;
{
  uint matrixCode;
  
  ildisAppendf(disassembler,"_matrix(",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  matrixCode = matrixModeWord >> 0x10 & 7;
  if (matrixCode < 5) {
    fmtArgR9 = 0;
    switch(matrixCode) {
    case 0:
      ildisAppendf(disassembler,"4x4",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
      break;
    case 1:
      ildisAppendf(disassembler,"4x3",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
      break;
    case 2:
      ildisAppendf(disassembler,"3x4",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
      break;
    case 3:
      ildisAppendf(disassembler,"3x3",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
      break;
    case 4:
      ildisAppendf(disassembler,"3x2",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    }
  }
  else {
    *disassembler = *disassembler + 1;
    ildisAppendf(disassembler,"!!!invalid!!!",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  }
  ildisAppendf(disassembler,")",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  return;
}

/* ildisPrintRelop @ 0xdccd4 (264 bytes) */
int ildisPrintRelop(disassembler, relopWord, passThroughR5, fmtArgR6, fmtArgR7, fmtArgR8, fmtArgR9, fmtArgR10)
  int *disassembler;
  uint relopWord;
  undefined4 passThroughR5;
  undefined4 fmtArgR6;
  undefined4 fmtArgR7;
  undefined4 fmtArgR8;
  int fmtArgR9;
  undefined4 fmtArgR10;
{
  uint relopCode;
  
  ildisAppendf(disassembler,"_relop(",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  relopCode = relopWord >> 0x10 & 7;
  if (relopCode < 6) {
    fmtArgR9 = 0;
    switch(relopCode) {
    case 0:
      ildisAppendf(disassembler,"ne",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
      break;
    case 1:
      ildisAppendf(disassembler,"eq",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
      break;
    case 2:
      ildisAppendf(disassembler,"ge",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
      break;
    case 3:
      ildisAppendf(disassembler,"gt",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
      break;
    case 4:
      ildisAppendf(disassembler,"le",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
      break;
    case 5:
      ildisAppendf(disassembler,"lt",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    }
  }
  else {
    *disassembler = *disassembler + 1;
    ildisAppendf(disassembler,"!!!invalid!!!",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  }
  ildisAppendf(disassembler,")",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  return;
}

/* ildisPrintHeader @ 0xdcdf4 (256 bytes) */
int ildisPrintHeader(disassembler, passThroughR4, passThroughR5, fmtArgR6, fmtArgR7, fmtArgR8, shaderTypeTextArg, fmtArgR10)
  int disassembler;
  undefined4 passThroughR4;
  undefined4 passThroughR5;
  undefined4 fmtArgR6;
  undefined4 fmtArgR7;
  undefined4 fmtArgR8;
  char *shaderTypeTextArg;
  undefined4 fmtArgR10;
{
  uint shaderType;
  undefined4 extraout_r4;
  char *shaderTypeText;
  uint uVar3;
  uint minorVersion;
  char shaderTypeChar0;
  char shaderTypeCharsRest [15];
  undefined1 auStack_118 [268];
  
  uVar3 = **(uint **)(disassembler + 8);
  *(uint **)(disassembler + 8) = *(uint **)(disassembler + 8) + 1;
  shaderType = uVar3 >> 0x10 & 0xff;
  if (shaderType == 1) {
    shaderTypeTextArg = "ps";
    shaderTypeChar0 = s_ps_001a8390[0];
    shaderTypeCharsRest[0] = s_ps_001a8390[1];
    shaderTypeCharsRest[1] = s_ps_001a8390[2];
  }
  else if (shaderType == 0) {
    shaderTypeTextArg = "vs";
    shaderTypeChar0 = s_vs_001a838c[0];
    shaderTypeCharsRest[0] = s_vs_001a838c[1];
    shaderTypeCharsRest[1] = s_vs_001a838c[2];
  }
  else if (shaderType == 2) {
    shaderTypeTextArg = "gs";
    shaderTypeChar0 = s_gs_001a8394[0];
    shaderTypeCharsRest[0] = s_gs_001a8394[1];
    shaderTypeCharsRest[1] = s_gs_001a8394[2];
  }
  minorVersion = uVar3 & 0xff;
  shaderTypeText = &shaderTypeChar0;
  uVar3 = uVar3 >> 8 & 0xff;
  printf_LDBLStub_1a32d0(auStack_118,"il_%s_%d_%d",shaderTypeText,uVar3,minorVersion,fmtArgR8,shaderTypeTextArg,fmtArgR10);
  *(uint *)(disassembler + 0x218) = (uint)(shaderType == 1);
  ildisAppendf(disassembler,auStack_118,shaderTypeText,uVar3,minorVersion,fmtArgR8,shaderTypeTextArg,fmtArgR10);
  return ildisFlushLine(disassembler,extraout_r4,shaderTypeText,uVar3,minorVersion,fmtArgR8,shaderTypeTextArg,fmtArgR10);
}

/* ildisPrintRegisterType @ 0xdcef4 (640 bytes) */
int ildisPrintRegisterType(disassembler, registerTypeCode, passThroughR5, fmtArgR6, fmtArgR7, fmtArgR8, fmtArgR9)
  int *disassembler;
  uint registerTypeCode;
  undefined4 passThroughR5;
  undefined4 fmtArgR6;
  undefined4 fmtArgR7;
  undefined4 fmtArgR8;
  int fmtArgR9;
{
  char *registerTypeText;
  
  if (0x20 < registerTypeCode) {
switchD_000dcf24_caseD_7:
    registerTypeText = "!!!invalidRegType!!!";
    *disassembler = *disassembler + 1;
    goto LAB_000dd1f4;
  }
  fmtArgR9 = 0;
  switch(registerTypeCode) {
  case 0:
    ildisAppendf(disassembler,"b",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,0xdcf00);
    return;
  case 1:
    ildisAppendf(disassembler,"c",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,0xdcf00);
    return;
  case 2:
    ildisAppendf(disassembler,"i",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,0xdcf00);
    return;
  case 3:
    ildisAppendf(disassembler,"a",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,0xdcf00);
    return;
  case 4:
    ildisAppendf(disassembler,"r",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,0xdcf00);
    return;
  default:
    ildisAppendf(disassembler,"v",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,0xdcf00);
    return;
  case 6:
    ildisAppendf(disassembler,"vIndex",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,0xdcf00);
    return;
  case 7:
  case 0x1a:
    goto switchD_000dcf24_caseD_7;
  case 8:
    ildisAppendf(disassembler,"vBaryCoord",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,0xdcf00);
    return;
  case 9:
    ildisAppendf(disassembler,"vPrimIndex",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,0xdcf00);
    return;
  case 10:
    ildisAppendf(disassembler,"vQuadIndex",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,0xdcf00);
    return;
  case 0xb:
    if (disassembler[0x86] == 0) {
      registerTypeText = "o";
      break;
    }
    goto LAB_000dd09c;
  case 0xc:
    if (disassembler[0x86] != 0) {
      registerTypeText = "vPixIn";
      break;
    }
LAB_000dd09c:
    registerTypeText = "!!!invalidRegUsage(oVtxOut)!!!";
    break;
  case 0xd:
    ildisAppendf(disassembler,"oSprite",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,0xdcf00);
    return;
  case 0xe:
    if (disassembler[0x86] == 0) {
      registerTypeText = "oPos";
    }
    else {
      registerTypeText = "!!!invalidRegUsage(oPos)!!!";
    }
    break;
  case 0xf:
    if (disassembler[0x86] == 0) {
      registerTypeText = "oInterp";
    }
    else {
      registerTypeText = "vInterp";
    }
    break;
  case 0x10:
    if (disassembler[0x86] == 0) {
      registerTypeText = "oFog";
    }
    else {
      registerTypeText = "vFog";
    }
    break;
  case 0x11:
    if (disassembler[0x86] == 0) {
      registerTypeText = "oT";
    }
    else {
      registerTypeText = "vT";
    }
    break;
  case 0x12:
    if (disassembler[0x86] == 0) {
      registerTypeText = "oPriColor";
    }
    else {
      registerTypeText = "vPriColor";
    }
    break;
  case 0x13:
    if (disassembler[0x86] == 0) {
      registerTypeText = "oSecColor";
    }
    else {
      registerTypeText = "vSecColor";
    }
    break;
  case 0x14:
    if (disassembler[0x86] == 0) {
      registerTypeText = "!!!invalidRegUsage(oSpritCoord)!!!";
    }
    else {
      registerTypeText = "vSpriteCoord";
    }
    break;
  case 0x15:
    ildisAppendf(disassembler,"vFace",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,0xdcf00);
    return;
  case 0x16:
    ildisAppendf(disassembler,"vWinCoord",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,0xdcf00);
    return;
  case 0x17:
    ildisAppendf(disassembler,"oC",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,0xdcf00);
    return;
  case 0x18:
    ildisAppendf(disassembler,"oDepth",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,0xdcf00);
    return;
  case 0x19:
    ildisAppendf(disassembler,"oClip",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,0xdcf00);
    return;
  case 0x1b:
    ildisAppendf(disassembler,"x",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,0xdcf00);
    return;
  case 0x1c:
    ildisAppendf(disassembler,"cb",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,0xdcf00);
    return;
  case 0x1d:
    ildisAppendf(disassembler,"l",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,0xdcf00);
    return;
  case 0x1f:
    ildisAppendf(disassembler,"o",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,0xdcf00);
    return;
  case 0x20:
    ildisAppendf(disassembler,"icb",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,0xdcf00);
    return;
  }
LAB_000dd1f4:
  ildisAppendf(disassembler,registerTypeText,passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,0xdcf00);
  return;
}

/* ildisPrintSourceOperand @ 0xdd1f8 (1220 bytes) */
int ildisPrintSourceOperand(disassembler, passThroughR4, printedValue, fmtArgR6, fmtArgR7, fmtArgR8, fmtArgR9)
  int *disassembler;
  undefined4 passThroughR4;
  uint printedValue;
  undefined4 fmtArgR6;
  undefined4 fmtArgR7;
  undefined4 fmtArgR8;
  uint *fmtArgR9;
{
  undefined4 componentChar;
  uint divCompSelect;
  bool noModifierWord;
  bool indexPrinted;
  uint extraOperandBit;
  undefined4 letterStyle;
  uint *tokenPtr;
  undefined4 extraout_r4;
  uint addressRegisterIndex;
  undefined4 in_r10;
  uint unaff_r23;
  uint extraOperandCount;
  uint relativeMode;
  uint unaff_r28;
  uint loopIndex;
  uint operandWord;
  undefined1 formatBuffer [64];
  undefined2 formatBuffer2 [36];
  
  tokenPtr = (uint *)disassembler[2];
  operandWord = *tokenPtr;
  disassembler[2] = (int)(tokenPtr + 1);
  noModifierWord = (operandWord & 0x400000) == 0;
  if (!noModifierWord) {
    unaff_r28 = tokenPtr[1];
    disassembler[2] = (int)(tokenPtr + 2);
  }
  relativeMode = operandWord & 0x1800000;
  if (relativeMode == 0x800000) {
    unaff_r23 = *(uint *)disassembler[2];
    disassembler[2] = (int)((uint *)disassembler[2] + 1);
  }
  extraOperandCount = operandWord >> 0x19 & 1;
  extraOperandBit = operandWord & 0x2000000;
  if (extraOperandCount != 0xffffffff) {
    indexPrinted = false;
    loopIndex = 0;
    do {
      ((int (*)())ildisPrintRegisterType)(disassembler,operandWord >> 0x10 & 0x3f,printedValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
      if (((undefined4 *)(operandWord & 0x3f0000) == 0x001b0000) ||
         ((undefined4 *)(operandWord & 0x3f0000) == (undefined4 *)0x1c0000)) {
        printedValue = operandWord & 0xffff;
        printf_LDBLStub_1a32d0(formatBuffer,"%d",printedValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,in_r10);
        indexPrinted = true;
        ildisAppendf(disassembler,formatBuffer,printedValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,in_r10);
      }
LAB_000dd324:
      if (relativeMode == 0) {
        if (indexPrinted) {
          printedValue = 0;
          if ((operandWord & 0x4000000) != 0) {
            printedValue = *(uint *)disassembler[2];
            disassembler[2] = (int)((uint *)disassembler[2] + 1);
          }
          printf_LDBLStub_1a32d0(formatBuffer,"[%lu]",printedValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,in_r10);
          ildisAppendf(disassembler,formatBuffer,printedValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,in_r10);
        }
        else {
          if (extraOperandBit == 0) {
            printedValue = operandWord & 0xffff;
            printf_LDBLStub_1a32d0(formatBuffer,"%d",printedValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,in_r10);
          }
          else {
            printedValue = operandWord & 0xffff;
            printf_LDBLStub_1a32d0(formatBuffer,"[%d]",printedValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,in_r10);
          }
          ildisAppendf(disassembler,formatBuffer,printedValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,in_r10);
        }
      }
      else {
        if (relativeMode == 0x800000) {
          ildisAppendf(disassembler,"[",printedValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,in_r10);
          if ((unaff_r23 & 0x10000) == 0) {
            addressRegisterIndex = unaff_r23 & 0xffff;
            printf_LDBLStub_1a32d0(formatBuffer,"a%d",addressRegisterIndex,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,in_r10);
            ildisAppendf(disassembler,formatBuffer,addressRegisterIndex,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,in_r10);
            if ((unaff_r23 & 0xe0000) != 0) {
              letterStyle = returnZero_da8fc(disassembler,operandWord);
              componentChar = ildisComponentSelectChar(disassembler,unaff_r23 >> 0x11 & 7,letterStyle,fmtArgR6,fmtArgR7,fmtArgR8,
                                   fmtArgR9,in_r10);
              printf_LDBLStub_1a32d0(formatBuffer,".%c",componentChar,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,in_r10);
              ildisAppendf(disassembler,formatBuffer,componentChar,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,in_r10);
            }
          }
          else {
            ildisAppendf(disassembler,"al",printedValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,in_r10);
          }
          if (indexPrinted) {
            printedValue = 0;
            if ((operandWord & 0x4000000) != 0) {
              printedValue = *(uint *)disassembler[2];
              disassembler[2] = (int)((uint *)disassembler[2] + 1);
            }
LAB_000dd4f0:
            printf_LDBLStub_1a32d0(formatBuffer2,"+%lu",printedValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,in_r10);
            ildisAppendf(disassembler,formatBuffer2,printedValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,in_r10);
          }
          else {
            printedValue = operandWord & 0xffff;
            if (printedValue != 0) {
              printf_LDBLStub_1a32d0(formatBuffer,"+%d",printedValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,in_r10);
              ildisAppendf(disassembler,formatBuffer,printedValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,in_r10);
            }
          }
        }
        else {
          if (relativeMode != 0x1000000) goto LAB_000dd51c;
          formatBuffer2[0] = 0x5b00;
          ildisAppendf(disassembler,formatBuffer2,printedValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,in_r10);
          ((int (*)())ildisPrintSourceOperand)(disassembler,extraout_r4,printedValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
          if ((operandWord & 0x4000000) != 0) {
            printedValue = *(uint *)disassembler[2];
            disassembler[2] = (int)((uint *)disassembler[2] + 1);
            goto LAB_000dd4f0;
          }
        }
        ildisAppendf(disassembler,"]",printedValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,in_r10);
      }
LAB_000dd51c:
      loopIndex = loopIndex + 1;
      if (extraOperandCount + 1 <= loopIndex) goto LAB_000dd530;
    } while (loopIndex == 0);
    fmtArgR9 = (uint *)disassembler[2];
    operandWord = *fmtArgR9;
    disassembler[2] = (int)(fmtArgR9 + 1);
    if ((operandWord & 0x400000) != 0) {
      unaff_r28 = fmtArgR9[1];
      disassembler[2] = (int)(fmtArgR9 + 2);
    }
    relativeMode = operandWord & 0x1800000;
    extraOperandCount = operandWord >> 0x19 & 1;
    if (relativeMode == 0x800000) {
      unaff_r23 = *(uint *)disassembler[2];
      disassembler[2] = (int)((uint *)disassembler[2] + 1);
    }
    goto LAB_000dd324;
  }
LAB_000dd530:
  if (noModifierWord) {
    return;
  }
  letterStyle = returnZero_da8fc(disassembler,operandWord);
  ildisPrintSwizzle(disassembler,unaff_r28,letterStyle,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,in_r10);
  ildisPrintNegateComponents(disassembler,unaff_r28,letterStyle,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,in_r10);
  if ((unaff_r28 & 0x10000) != 0) {
    ildisAppendf(disassembler,"_invert",letterStyle,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,in_r10);
  }
  if ((unaff_r28 & 0x80000) != 0) {
    ildisAppendf(disassembler,"_sign",letterStyle,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,in_r10);
  }
  if ((unaff_r28 & 0x100000) != 0) {
    ildisAppendf(disassembler,"_abs",letterStyle,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,in_r10);
  }
  if ((unaff_r28 & 0x20000) != 0) {
    ildisAppendf(disassembler,"_bias",letterStyle,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,in_r10);
  }
  if ((unaff_r28 & 0x40000) != 0) {
    ildisAppendf(disassembler,"_x2",letterStyle,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,in_r10);
  }
  if ((unaff_r28 & 0xe00000) == 0) {
    return;
  }
  ildisAppendf(disassembler,"_divcomp(",letterStyle,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,in_r10);
  divCompSelect = unaff_r28 >> 0x15 & 7;
  if (divCompSelect == 2) {
    ildisAppendf(disassembler,"z",letterStyle,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,in_r10);
    goto LAB_000dd630;
  }
  if (divCompSelect < 3) {
    if (divCompSelect == 1) {
      ildisAppendf(disassembler,"y",letterStyle,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,in_r10);
      goto LAB_000dd630;
    }
  }
  else {
    if (divCompSelect == 3) {
      ildisAppendf(disassembler,"w",letterStyle,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,in_r10);
      goto LAB_000dd630;
    }
    if (divCompSelect == 4) {
      ildisAppendf(disassembler,"unknown",letterStyle,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,in_r10);
      goto LAB_000dd630;
    }
  }
  ildisAppendf(disassembler,"!!!invalid!!!",letterStyle,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,in_r10);
  *disassembler = *disassembler + 1;
LAB_000dd630:
  ildisAppendf(disassembler,")",letterStyle,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,in_r10);
  return;
}

/* ildisPrintDestinationOperand @ 0xdd6bc (988 bytes) */
int ildisPrintDestinationOperand(disassembler, passThroughR4, printedValue, fmtArgR6, fmtArgR7, fmtArgR8, fmtArgR9, fmtArgR10)
  int *disassembler;
  undefined4 passThroughR4;
  uint printedValue;
  undefined4 fmtArgR6;
  undefined4 fmtArgR7;
  undefined4 fmtArgR8;
  undefined4 fmtArgR9;
  undefined4 fmtArgR10;
{
  bool noModifierWord;
  bool indexPrinted;
  undefined4 *registerTypeBits;
  undefined4 letterStyle;
  uint *tokenPtr;
  undefined4 extraout_r4;
  undefined4 uVar6;
  uint unaff_r24;
  uint unaff_r25;
  uint operandWordOrIndex;
  uint relativeModeOrWord;
  undefined1 formatBuffer [64];
  undefined1 formatBuffer2 [84];
  
  tokenPtr = (uint *)disassembler[2];
  operandWordOrIndex = *tokenPtr;
  disassembler[2] = (int)(tokenPtr + 1);
  noModifierWord = (operandWordOrIndex >> 0x16 & 1) == 0;
  if (!noModifierWord) {
    unaff_r25 = tokenPtr[1];
    disassembler[2] = (int)(tokenPtr + 2);
  }
  relativeModeOrWord = operandWordOrIndex & 0x1800000;
  if (relativeModeOrWord == 0x800000) {
    unaff_r24 = *(uint *)disassembler[2];
    disassembler[2] = (int)((uint *)disassembler[2] + 1);
  }
  if (!noModifierWord) {
    ildisPrintResultModifiers(disassembler,unaff_r25,printedValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  }
  ildisAppendf(disassembler," ",printedValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  letterStyle = returnZero_da8f4(disassembler,operandWordOrIndex);
  ((int (*)())ildisPrintRegisterType)(disassembler,operandWordOrIndex >> 0x10 & 0x3f,printedValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
  if ((operandWordOrIndex & 0x23f0000) == 0x21e0000) {
    operandWordOrIndex = operandWordOrIndex & 0xffff;
    printf_LDBLStub_1a32d0(formatBuffer,"[%d]",operandWordOrIndex,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    ildisAppendf(disassembler,formatBuffer,operandWordOrIndex,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    relativeModeOrWord = *(uint *)disassembler[2];
    disassembler[2] = (int)((uint *)disassembler[2] + 1);
    operandWordOrIndex = relativeModeOrWord & 0xffff;
    printf_LDBLStub_1a32d0(formatBuffer,"[%d]",operandWordOrIndex,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    ildisAppendf(disassembler,formatBuffer,operandWordOrIndex,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    noModifierWord = (relativeModeOrWord & 0x400000) == 0;
  }
  else {
    registerTypeBits = (undefined4 *)(operandWordOrIndex & 0x3f0000);
    if (registerTypeBits == (undefined4 *)0x1f0000) {
      if ((relativeModeOrWord == 0x800000) || (indexPrinted = false, relativeModeOrWord == 0x1000000)) {
        indexPrinted = true;
      }
    }
    else if ((registerTypeBits == 0x001b0000) || (indexPrinted = false, registerTypeBits == (undefined4 *)0x1c0000)) {
      printedValue = operandWordOrIndex & 0xffff;
      printf_LDBLStub_1a32d0(formatBuffer,"%d",printedValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
      indexPrinted = true;
      ildisAppendf(disassembler,formatBuffer,printedValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    }
    if (relativeModeOrWord == 0) {
      if (indexPrinted) {
        uVar6 = 0;
        if ((operandWordOrIndex & 0x4000000) != 0) {
          uVar6 = *(undefined4 *)disassembler[2];
          disassembler[2] = (int)((undefined4 *)disassembler[2] + 1);
        }
        printf_LDBLStub_1a32d0(formatBuffer,"[%lu]",uVar6,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
        ildisAppendf(disassembler,formatBuffer,uVar6,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
      }
      else {
        operandWordOrIndex = operandWordOrIndex & 0xffff;
        printf_LDBLStub_1a32d0(formatBuffer,"%d",operandWordOrIndex,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
        ildisAppendf(disassembler,formatBuffer,operandWordOrIndex,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
      }
    }
    else {
      if (relativeModeOrWord == 0x800000) {
        ildisAppendf(disassembler,"[",printedValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
        if ((unaff_r24 & 0x10000) == 0) {
          relativeModeOrWord = unaff_r24 & 0xffff;
          printf_LDBLStub_1a32d0(formatBuffer,"a%d",relativeModeOrWord,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
          ildisAppendf(disassembler,formatBuffer,relativeModeOrWord,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
          if ((unaff_r24 & 0xe0000) != 0) {
            uVar6 = returnZero_da8f4(disassembler,operandWordOrIndex);
            uVar6 = ildisComponentSelectChar(disassembler,unaff_r24 >> 0x11 & 7,uVar6,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9
                                 ,fmtArgR10);
            printf_LDBLStub_1a32d0(formatBuffer,".%c",uVar6,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
            ildisAppendf(disassembler,formatBuffer,uVar6,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
          }
        }
        else {
          ildisAppendf(disassembler,"al",printedValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
        }
        if (indexPrinted) {
          printedValue = 0;
          if ((operandWordOrIndex & 0x4000000) != 0) {
            printedValue = *(uint *)disassembler[2];
            disassembler[2] = (int)((uint *)disassembler[2] + 1);
          }
          printf_LDBLStub_1a32d0(formatBuffer2,"+%lu",printedValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
        }
        else {
          printedValue = operandWordOrIndex & 0xffff;
          if (printedValue != 0) {
            printf_LDBLStub_1a32d0(formatBuffer,"+%d",printedValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
            ildisAppendf(disassembler,formatBuffer,printedValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
          }
        }
      }
      else {
        if (relativeModeOrWord != 0x1000000) goto joined_r0x000dda5c;
        if ((!indexPrinted) && (registerTypeBits != (undefined4 *)0x1f0000)) {
          ildisAppendf(disassembler,
                       "Error! Field relative_address == IL_ADDR_REG_RELATIVE not supported for this reg type."
                       ,printedValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
          *disassembler = *disassembler + 1;
          goto joined_r0x000dda5c;
        }
        ildisAppendf(disassembler,"[",printedValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
        ((int (*)())ildisPrintSourceOperand)(disassembler,extraout_r4,printedValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
        if ((operandWordOrIndex & 0x4000000) != 0) {
          printedValue = *(uint *)disassembler[2];
          disassembler[2] = (int)((uint *)disassembler[2] + 1);
          if (registerTypeBits == (undefined4 *)0x1f0000) {
            printedValue = printedValue + (operandWordOrIndex & 0xffff);
          }
          printf_LDBLStub_1a32d0(formatBuffer2,"+%lu",printedValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
          ildisAppendf(disassembler,formatBuffer2,printedValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
        }
      }
      ildisAppendf(disassembler,"]",printedValue,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    }
  }
joined_r0x000dda5c:
  if (!noModifierWord) {
    ildisPrintDestinationWriteMask(disassembler,unaff_r25,letterStyle,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  }
  return;
}

/* ildisPrintDestAnd3Sources @ 0xdda98 (124 bytes) */
int ildisPrintDestAnd3Sources(disassembler, passThroughR4, passThroughR5, fmtArgR6, fmtArgR7, fmtArgR8, fmtArgR9, fmtArgR10)
  undefined4 disassembler;
  undefined4 passThroughR4;
  undefined4 passThroughR5;
  undefined4 fmtArgR6;
  undefined4 fmtArgR7;
  undefined4 fmtArgR8;
  undefined4 fmtArgR9;
  undefined4 fmtArgR10;
{
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  undefined4 extraout_r4_02;
  
  ((int (*)())ildisPrintDestinationOperand)(disassembler,passThroughR4,passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  ildisAppendf(disassembler,", ",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  ((int (*)())ildisPrintSourceOperand)(disassembler,extraout_r4,passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
  ildisAppendf(disassembler,", ",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  ((int (*)())ildisPrintSourceOperand)(disassembler,extraout_r4_00,passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
  ildisAppendf(disassembler,", ",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  ((int (*)())ildisPrintSourceOperand)(disassembler,extraout_r4_01,passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
  return ildisFlushLine(disassembler,extraout_r4_02,passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
}

/* ildisPrintDestAnd2Sources @ 0xddb14 (104 bytes) */
int ildisPrintDestAnd2Sources(disassembler, passThroughR4, passThroughR5, fmtArgR6, fmtArgR7, fmtArgR8, fmtArgR9, fmtArgR10)
  undefined4 disassembler;
  undefined4 passThroughR4;
  undefined4 passThroughR5;
  undefined4 fmtArgR6;
  undefined4 fmtArgR7;
  undefined4 fmtArgR8;
  undefined4 fmtArgR9;
  undefined4 fmtArgR10;
{
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  
  ((int (*)())ildisPrintDestinationOperand)(disassembler,passThroughR4,passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  ildisAppendf(disassembler,", ",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  ((int (*)())ildisPrintSourceOperand)(disassembler,extraout_r4,passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
  ildisAppendf(disassembler,", ",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  ((int (*)())ildisPrintSourceOperand)(disassembler,extraout_r4_00,passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
  return ildisFlushLine(disassembler,extraout_r4_01,passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
}

/* ildisPrintDestAnd1Source @ 0xddb7c (80 bytes) */
int ildisPrintDestAnd1Source(disassembler, passThroughR4, passThroughR5, fmtArgR6, fmtArgR7, fmtArgR8, fmtArgR9, fmtArgR10)
  undefined4 disassembler;
  undefined4 passThroughR4;
  undefined4 passThroughR5;
  undefined4 fmtArgR6;
  undefined4 fmtArgR7;
  undefined4 fmtArgR8;
  undefined4 fmtArgR9;
  undefined4 fmtArgR10;
{
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  
  ((int (*)())ildisPrintDestinationOperand)(disassembler,passThroughR4,passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  ildisAppendf(disassembler,", ",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  ((int (*)())ildisPrintSourceOperand)(disassembler,extraout_r4,passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
  return ildisFlushLine(disassembler,extraout_r4_00,passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
}

/* ildisPrintInstruction @ 0xddbcc (10080 bytes) */
int ildisPrintInstruction(disassembler, passThroughR4, passThroughR5, fmtArgR6, fmtArgR7, fmtArgR8, fmtArgR9)
  int *disassembler;
  undefined4 passThroughR4;
  undefined4 passThroughR5;
  undefined4 fmtArgR6;
  undefined4 fmtArgR7;
  undefined4 fmtArgR8;
  int fmtArgR9;
{
  int commentBytes;
  uint resinfoResourceId;
  uint loadResourceId;
  uint resourceId;
  uint interpolationMode;
  uint outputSemantic;
  uint maxOutputVertexCount;
  uint exportStreamId;
  uint memimportElement;
  uint paramNumber;
  undefined4 defWord0;
  undefined4 immediateWord;
  undefined4 declResult;
  undefined4 *immediatePtr2;
  undefined4 *defWord3;
  undefined4 *immediatePtr;
  char *repSuffix;
  int literalIndex;
  int literalCountCopy;
  int literalCount;
  int fieldLength;
  char commentStreamChar;
  undefined4 *defPtrAlias;
  float *defFloatPtr;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  undefined4 extraout_r4_02;
  undefined4 extraout_r4_03;
  undefined4 extraout_r4_04;
  undefined4 extraout_r4_05;
  undefined4 extraout_r4_06;
  undefined4 extraout_r4_07;
  undefined4 extraout_r4_08;
  undefined4 extraout_r4_09;
  undefined4 extraout_r4_10;
  undefined4 extraout_r4_11;
  undefined4 extraout_r4_12;
  undefined4 extraout_r4_13;
  undefined4 extraout_r4_14;
  undefined4 extraout_r4_15;
  undefined4 extraout_r4_16;
  undefined4 extraout_r4_17;
  undefined4 extraout_r4_18;
  undefined4 extraout_r4_19;
  undefined4 extraout_r4_20;
  undefined4 extraout_r4_21;
  undefined4 extraout_r4_22;
  undefined4 extraout_r4_23;
  undefined4 extraout_r4_24;
  undefined4 extraout_r4_25;
  undefined4 extraout_r4_26;
  undefined4 extraout_r4_27;
  undefined4 extraout_r4_28;
  undefined4 extraout_r4_29;
  undefined4 extraout_r4_30;
  undefined4 extraout_r4_31;
  undefined4 extraout_r4_32;
  undefined4 extraout_r4_33;
  undefined4 extraout_r4_34;
  undefined4 extraout_r4_35;
  undefined4 extraout_r4_36;
  undefined4 extraout_r4_37;
  undefined4 extraout_r4_38;
  undefined4 extraout_r4_39;
  undefined4 extraout_r4_40;
  undefined4 extraout_r4_41;
  undefined4 extraout_r4_42;
  undefined4 extraout_r4_43;
  undefined4 extraout_r4_44;
  undefined4 extraout_r4_45;
  undefined4 extraout_r4_46;
  undefined4 extraout_r4_47;
  undefined4 extraout_r4_48;
  undefined4 extraout_r4_49;
  undefined4 extraout_r4_50;
  undefined4 extraout_r4_51;
  undefined4 extraout_r4_52;
  undefined4 extraout_r4_53;
  undefined4 extraout_r4_54;
  undefined4 extraout_r4_55;
  undefined4 extraout_r4_56;
  undefined4 extraout_r4_57;
  undefined4 extraout_r4_58;
  undefined4 extraout_r4_59;
  undefined4 extraout_r4_60;
  undefined4 extraout_r4_61;
  undefined4 extraout_r4_62;
  undefined4 extraout_r4_63;
  undefined4 extraout_r4_64;
  undefined4 extraout_r4_65;
  undefined4 extraout_r4_66;
  undefined4 extraout_r4_67;
  undefined4 extraout_r4_68;
  undefined4 extraout_r4_69;
  undefined4 extraout_r4_70;
  undefined4 extraout_r4_71;
  undefined4 extraout_r4_72;
  undefined4 extraout_r4_73;
  undefined4 extraout_r4_74;
  undefined4 extraout_r4_75;
  undefined4 extraout_r4_76;
  undefined4 extraout_r4_77;
  undefined4 extraout_r4_78;
  undefined4 extraout_r4_79;
  undefined4 extraout_r4_80;
  undefined4 extraout_r4_81;
  undefined4 extraout_r4_82;
  undefined4 extraout_r4_83;
  undefined4 extraout_r4_84;
  undefined4 extraout_r4_85;
  undefined4 extraout_r4_86;
  undefined4 extraout_r4_87;
  undefined4 extraout_r4_88;
  undefined4 extraout_r4_89;
  undefined4 extraout_r4_90;
  undefined4 extraout_r4_91;
  undefined4 extraout_r4_92;
  undefined4 extraout_r4_93;
  undefined4 extraout_r4_94;
  undefined4 extraout_r4_95;
  undefined4 extraout_r4_96;
  undefined4 extraout_r4_97;
  undefined4 extraout_r4_98;
  undefined4 extraout_r4_99;
  undefined4 extraout_r4_x00100;
  undefined4 extraout_r4_x00101;
  undefined4 extraout_r4_x00102;
  undefined4 extraout_r4_x00103;
  undefined4 extraout_r4_x00104;
  undefined4 extraout_r4_x00105;
  undefined4 extraout_r4_x00106;
  undefined4 extraout_r4_x00107;
  undefined4 extraout_r4_x00108;
  undefined4 extraout_r4_x00109;
  undefined4 extraout_r4_x00110;
  undefined4 extraout_r4_x00111;
  undefined4 extraout_r4_x00112;
  undefined4 extraout_r4_x00113;
  undefined4 extraout_r4_x00114;
  undefined4 extraout_r4_x00115;
  undefined4 extraout_r4_x00116;
  undefined4 extraout_r4_x00117;
  undefined4 extraout_r4_x00118;
  undefined4 extraout_r4_x00119;
  undefined4 extraout_r4_x00120;
  undefined4 extraout_r4_x00121;
  undefined4 extraout_r4_x00122;
  undefined4 extraout_r4_x00123;
  undefined4 extraout_r4_x00124;
  undefined4 extraout_r4_x00125;
  undefined4 extraout_r4_x00126;
  undefined4 extraout_r4_x00127;
  undefined4 extraout_r4_x00128;
  undefined4 extraout_r4_x00129;
  undefined4 extraout_r4_x00130;
  undefined4 extraout_r4_x00131;
  undefined4 extraout_r4_x00132;
  undefined4 extraout_r4_x00133;
  undefined4 extraout_r4_x00134;
  undefined4 extraout_r4_x00135;
  undefined4 extraout_r4_x00136;
  undefined4 extraout_r4_x00137;
  undefined4 extraout_r4_x00138;
  undefined4 extraout_r4_x00139;
  undefined4 extraout_r4_x00140;
  undefined4 extraout_r4_x00141;
  undefined4 extraout_r4_x00142;
  undefined4 extraout_r4_x00143;
  undefined4 extraout_r4_x00144;
  undefined4 extraout_r4_x00145;
  undefined4 extraout_r4_x00146;
  undefined4 extraout_r4_x00147;
  undefined4 extraout_r4_x00148;
  undefined4 extraout_r4_x00149;
  undefined4 extraout_r4_x00150;
  undefined4 extraout_r4_x00151;
  undefined4 extraout_r4_x00152;
  undefined4 extraout_r4_x00153;
  undefined4 extraout_r4_x00154;
  undefined4 extraout_r4_x00155;
  undefined4 extraout_r4_x00156;
  undefined4 extraout_r4_x00157;
  undefined4 extraout_r4_x00158;
  undefined4 extraout_r4_x00159;
  undefined4 extraout_r4_x00160;
  undefined4 extraout_r4_x00161;
  undefined4 extraout_r4_x00162;
  undefined4 extraout_r4_x00163;
  undefined4 extraout_r4_x00164;
  undefined4 extraout_r4_x00165;
  undefined4 extraout_r4_x00166;
  undefined4 extraout_r4_x00167;
  undefined4 extraout_r4_x00168;
  undefined4 extraout_r4_x00169;
  char *commentChar;
  undefined4 extraout_r4_x00170;
  undefined4 extraout_r4_x00171;
  undefined4 extraout_r4_x00172;
  undefined4 extraout_r4_x00173;
  undefined4 extraout_r4_x00174;
  undefined4 extraout_r4_x00175;
  undefined4 extraout_r4_x00176;
  undefined4 extraout_r4_x00177;
  undefined4 extraout_r4_x00178;
  undefined4 extraout_r4_x00179;
  undefined4 extraout_r4_x00180;
  undefined4 extraout_r4_x00181;
  undefined4 extraout_r4_x00182;
  undefined4 extraout_r4_x00183;
  undefined4 extraout_r4_x00184;
  undefined4 extraout_r4_x00185;
  undefined4 extraout_r4_x00186;
  undefined4 extraout_r4_x00187;
  undefined4 extraout_r4_x00188;
  undefined4 extraout_r4_x00189;
  undefined4 extraout_r4_x00190;
  undefined4 extraout_r4_x00191;
  undefined4 extraout_r4_x00192;
  undefined4 extraout_r4_x00193;
  undefined4 extraout_r4_x00194;
  undefined4 extraout_r4_x00195;
  undefined4 extraout_r4_x00196;
  undefined4 extraout_r4_x00197;
  undefined4 extraout_r4_x00198;
  undefined4 extraout_r4_x00199;
  undefined4 extraout_r4_x00200;
  undefined4 extraout_r4_x00201;
  undefined4 extraout_r4_x00202;
  undefined4 extraout_r4_x00203;
  undefined4 extraout_r4_x00204;
  undefined4 extraout_r4_x00205;
  undefined4 extraout_r4_x00206;
  undefined4 extraout_r4_x00207;
  undefined4 extraout_r4_x00208;
  undefined4 extraout_r4_x00209;
  undefined4 extraout_r4_x00210;
  undefined4 extraout_r4_x00211;
  undefined4 extraout_r4_x00212;
  undefined4 extraout_r4_x00213;
  undefined4 extraout_r4_x00214;
  undefined4 extraout_r4_x00215;
  undefined4 extraout_r4_x00216;
  undefined4 extraout_r4_x00217;
  undefined4 extraout_r4_x00218;
  undefined4 extraout_r4_x00219;
  undefined4 extraout_r4_x00220;
  undefined4 extraout_r4_x00221;
  undefined4 extraout_r4_x00222;
  undefined4 extraout_r4_x00223;
  undefined4 extraout_r4_x00224;
  undefined4 extraout_r4_x00225;
  undefined4 extraout_r4_x00226;
  undefined4 extraout_r4_x00227;
  undefined4 extraout_r4_x00228;
  undefined4 extraout_r4_x00229;
  undefined4 extraout_r4_x00230;
  undefined4 extraout_r4_x00231;
  undefined4 extraout_r4_x00232;
  undefined4 extraout_r4_x00233;
  undefined4 extraout_r4_x00234;
  undefined4 extraout_r4_x00235;
  undefined4 extraout_r4_x00236;
  undefined4 extraout_r4_x00237;
  undefined4 extraout_r4_x00238;
  undefined4 extraout_r4_x00239;
  undefined4 extraout_r4_x00240;
  undefined4 extraout_r4_x00241;
  undefined4 extraout_r4_x00242;
  char *mnemonic;
  undefined4 lastReturnR4;
  uint commentWordCount;
  undefined4 defWord1;
  undefined4 defWord2;
  uint memexportElemOffset;
  undefined4 defWord3Printed;
  float defFloat0;
  float defFloat2;
  undefined4 *defFloat3Bits;
  uint *nextWordPtr;
  uint *fmtArgR5;
  float defFloat1;
  uint instructionToken;
  int copiedCount;
  int commentCharIndex;
  int fieldOffset;
  uint scratchText;
  undefined4 scratchTextWord1;
  char textBuffer;
  char textBufferByte1;
  uint *instructionPtr;
  uint opcode;
  char acStack_132 [266];
  undefined4 result;
  
  instructionPtr = (uint *)disassembler[2];
  instructionToken = *instructionPtr;
  nextWordPtr = instructionPtr + 1;
  disassembler[2] = (int)nextWordPtr;
  opcode = instructionToken & 0xffff;
  if (opcode < 0xbf) {
    fmtArgR9 = 0;
    switch(opcode) {
    default:
      goto switchD_000ddc1c_caseD_0;
    case 1:
      mnemonic = "abs";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"abs",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_01,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 2:
      mnemonic = "acos";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"acos",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_02,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 3:
      mnemonic = "add";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"add",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd2Sources)(disassembler,extraout_r4_44,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 4:
      mnemonic = "asin";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"asin",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_04,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 5:
      mnemonic = "atan";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"atan",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_05,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 6:
      mnemonic = "break";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"break",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisFlushLine(disassembler,extraout_r4_x00111,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 7:
      mnemonic = "breakc";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"breakc",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintRelop)(disassembler,instructionToken,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisAppendf(disassembler," ",mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintSourceOperand)(disassembler,extraout_r4_x00112,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
      ildisAppendf(disassembler,", ",mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintSourceOperand)(disassembler,extraout_r4_x00113,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
      ildisFlushLine(disassembler,extraout_r4_x00114,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 8:
      mnemonic = "call";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"call",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisAppendf(disassembler," ",mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisPrintUnsigned(disassembler,extraout_r4_x00119,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisFlushLine(disassembler,extraout_r4_x00120,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 9:
      mnemonic = "callnz";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"callnz",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisAppendf(disassembler," ",mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintSourceOperand)(disassembler,extraout_r4_x00121,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
      ildisAppendf(disassembler,", ",mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisPrintUnsigned(disassembler,extraout_r4_x00122,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisFlushLine(disassembler,extraout_r4_x00123,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 10:
      mnemonic = "clamp";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"clamp",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd3Sources)(disassembler,extraout_r4_56,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0xb:
      mnemonic = "clg";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"clg",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_06,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0xc:
      mnemonic = "cmov";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"cmov",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd2Sources)(disassembler,extraout_r4_07,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0xd:
      mnemonic = "cmp";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"cmp",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintRelop)(disassembler,instructionToken,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisPrintCmpVal(disassembler,instructionToken,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd3Sources)(disassembler,extraout_r4_57,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0xe:
      mnemonic = "colorclamp";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"colorclamp",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_09,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0xf:
      commentWordCount = *nextWordPtr;
      disassembler[2] = (int)(instructionPtr + 2);
      commentBytes = (commentWordCount & 0xffff) * 4;
      commentChar = " ); ";
      ildisAppendIndentedf(disassembler,disassembler[0x87]," ); ",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      mnemonic = (char *)disassembler[2];
      copiedCount = 0;
      lastReturnR4 = extraout_r4_x00241;
      if ((commentWordCount & 0xffff) != 0) {
        commentStreamChar = *mnemonic;
        mnemonic = mnemonic + 1;
        commentChar = (char *)(int)commentStreamChar;
        copiedCount = 1;
        if (commentChar != (char *)0x0) {
          commentCharIndex = 1;
          do {
            ildisAppendf(disassembler,"%c",commentChar,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
            copiedCount = commentBytes;
            lastReturnR4 = extraout_r4_x00242;
            if (commentCharIndex == commentBytes) break;
            commentStreamChar = *mnemonic;
            commentCharIndex = commentCharIndex + 1;
            mnemonic = mnemonic + 1;
            commentChar = (char *)(int)commentStreamChar;
            copiedCount = commentCharIndex;
          } while (commentChar != (char *)0x0);
        }
      }
      for (commentBytes = commentBytes - copiedCount; commentBytes != 0; commentBytes = commentBytes + -1) {
        mnemonic = mnemonic + 1;
      }
      disassembler[2] = (int)mnemonic;
      ildisFlushLine(disassembler,lastReturnR4,commentChar,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x10:
      mnemonic = "continue";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"continue",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisFlushLine(disassembler,extraout_r4_x00130,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x11:
      mnemonic = "continuec";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"continuec",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintRelop)(disassembler,instructionToken,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisAppendf(disassembler," ",mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintSourceOperand)(disassembler,extraout_r4_x00131,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
      ildisAppendf(disassembler,", ",mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintSourceOperand)(disassembler,extraout_r4_x00132,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
      ildisFlushLine(disassembler,extraout_r4_x00133,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x12:
      mnemonic = "cos";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"cos",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_10,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x13:
      mnemonic = "crs";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"crs",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd2Sources)(disassembler,extraout_r4_45,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x14:
      mnemonic = "dclarray";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"dclarray",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisAppendf(disassembler," ",mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintSourceOperand)(disassembler,extraout_r4_x00180,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
      ildisAppendf(disassembler,", ",mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintSourceOperand)(disassembler,extraout_r4_x00181,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
      ildisFlushLine(disassembler,extraout_r4_x00182,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x15:
      scratchText = instructionToken;
      ildisAppendIndentedf(disassembler,disassembler[0x87],"dcldef",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDcldefComponents)(disassembler,scratchText,scratchTextWord1,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestinationOperand)(disassembler,extraout_r4_x00202,scratchTextWord1,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisFlushLine(disassembler,extraout_r4_x00203,scratchTextWord1,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x16:
      mnemonic = "dclpi";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"dclpi",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDclpiOperands)(disassembler,instructionToken,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestinationOperand)(disassembler,extraout_r4_x00191,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisFlushLine(disassembler,extraout_r4_x00192,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x17:
      mnemonic = "dclpin";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"dclpin",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDclpinOperands)(disassembler,instructionToken,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestinationOperand)(disassembler,extraout_r4_x00193,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisFlushLine(disassembler,extraout_r4_x00194,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x18:
      ildisAppendIndentedf(disassembler,disassembler[0x87],"dclpp",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisAppendIndentedf(disassembler,disassembler[0x87],"dclv",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      paramNumber = instructionToken >> 0x10 & 0xff;
      printf_LDBLStub_1a32d0(&scratchText,"_param(%d)",paramNumber,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisAppendf(disassembler,&scratchText,paramNumber,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestinationOperand)(disassembler,extraout_r4_x00195,paramNumber,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisFlushLine(disassembler,extraout_r4_x00196,paramNumber,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x19:
      mnemonic = "dclpt";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"dclpt",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDclptCoordMode)(disassembler,instructionToken,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
      ((int (*)())ildisPrintStage)(disassembler,instructionToken,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisFlushLine(disassembler,extraout_r4_x00201,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x1a:
      mnemonic = "dclv";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"dclv",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDclvOperands)(disassembler,instructionToken,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestinationOperand)(disassembler,extraout_r4_x00197,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisFlushLine(disassembler,extraout_r4_x00198,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x1b:
      mnemonic = "dclvout";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"dclvout",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDclvoutOperands)(disassembler,instructionToken,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestinationOperand)(disassembler,extraout_r4_x00199,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisFlushLine(disassembler,extraout_r4_x00200,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x1c:
      mnemonic = "def";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"def",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      if ((*(uint *)disassembler[2] & 0x3f0000) == 0x10000) {
        fmtArgR5 = &scratchText;
        declResult = ((int (*)())ildisPrintDestinationOperand)(disassembler,extraout_r4_x00204,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,
                             nextWordPtr);
        defFloatPtr = (float *)disassembler[2];
        nextWordPtr = (uint *)0x19dbd8;
        defFloat0 = *defFloatPtr;
        disassembler[2] = (int)(defFloatPtr + 1);
        defFloat1 = defFloatPtr[1];
        disassembler[2] = (int)(defFloatPtr + 2);
        defFloat2 = defFloatPtr[2];
        disassembler[2] = (int)(defFloatPtr + 3);
        defFloat3Bits = (*(undefined4 * *)(defFloatPtr + (3)));
        disassembler[2] = (int)(defFloatPtr + 4);
        textBuffer = s___001a44f4[0];
        textBufferByte1 = s___001a44f4[1];
        acStack_132[0] = s___001a44f4[2];
        defPtrAlias = defFloat3Bits;
        ((char * (*)())FUN_000cdc3c)(declResult,10,fmtArgR5,(double)defFloat0);
        fieldOffset = printf_LDBLStub_1a32d0(acStack_132,"%s, ",fmtArgR5,fmtArgR6,fmtArgR7,fmtArgR8,defPtrAlias,nextWordPtr);
        mnemonic = acStack_132 + fieldOffset;
        ((char * (*)())FUN_000cdc3c)(fieldOffset,10,fmtArgR5,(double)defFloat1);
        fieldOffset = printf_LDBLStub_1a32d0(mnemonic,"%s, ",fmtArgR5,fmtArgR6,fmtArgR7,fmtArgR8,defPtrAlias,nextWordPtr);
        ((char * (*)())FUN_000cdc3c)(fieldOffset,10,fmtArgR5,(double)defFloat2);
        fieldLength = printf_LDBLStub_1a32d0(mnemonic + fieldOffset,"%s, ",fmtArgR5,fmtArgR6,fmtArgR7,fmtArgR8,defPtrAlias,nextWordPtr)
        ;
        ((char * (*)())FUN_000cdc3c)(fieldLength,10,fmtArgR5,(double)GH_U2F((unsigned int)(defFloat3Bits)));
        printf_LDBLStub_1a32d0(mnemonic + fieldOffset + fieldLength,"%s",fmtArgR5,fmtArgR6,fmtArgR7,fmtArgR8,defPtrAlias,nextWordPtr);
      }
      else {
        ((int (*)())ildisPrintDestinationOperand)(disassembler,extraout_r4_x00204,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
        immediatePtr = (undefined4 *)disassembler[2];
        fmtArgR5 = (uint *)*immediatePtr;
        defPtrAlias = immediatePtr + 2;
        disassembler[2] = (int)(immediatePtr + 1);
        fmtArgR6 = immediatePtr[1];
        disassembler[2] = (int)defPtrAlias;
        fmtArgR7 = immediatePtr[2];
        disassembler[2] = (int)(immediatePtr + 3);
        fmtArgR8 = immediatePtr[3];
        disassembler[2] = (int)(immediatePtr + 4);
        printf_LDBLStub_1a32d0(&textBuffer,", %lu, %lu, %lu, %lu",fmtArgR5,fmtArgR6,fmtArgR7,fmtArgR8,defPtrAlias,
                     nextWordPtr);
      }
      ildisAppendf(disassembler,&textBuffer,fmtArgR5,fmtArgR6,fmtArgR7,fmtArgR8,defPtrAlias,nextWordPtr);
      ildisFlushLine(disassembler,extraout_r4_x00205,fmtArgR5,fmtArgR6,fmtArgR7,fmtArgR8,defPtrAlias,nextWordPtr);
      result = 1;
      break;
    case 0x1d:
      mnemonic = "defb";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"defb",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestinationOperand)(disassembler,extraout_r4_x00206,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      immediateWord = *(undefined4 *)disassembler[2];
      disassembler[2] = (int)((undefined4 *)disassembler[2] + 1);
      printf_LDBLStub_1a32d0(&scratchText,", %lu",immediateWord,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisAppendf(disassembler,&scratchText,immediateWord,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisFlushLine(disassembler,extraout_r4_x00207,immediateWord,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x1e:
      mnemonic = "det";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"det",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_x00104,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x1f:
      mnemonic = "dist";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"dist",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd2Sources)(disassembler,extraout_r4_46,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x20:
      mnemonic = "div";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"div",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintZeroOp)(disassembler,instructionToken,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd2Sources)(disassembler,extraout_r4_58,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x21:
      mnemonic = "dp2add";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"dp2add",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd3Sources)(disassembler,extraout_r4_60,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x22:
      mnemonic = "dp3";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"dp3",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd2Sources)(disassembler,extraout_r4_47,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x23:
      mnemonic = "dp4";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"dp4",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd2Sources)(disassembler,extraout_r4_48,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x24:
      mnemonic = "dst";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"dst",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd2Sources)(disassembler,extraout_r4_49,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x25:
      mnemonic = "dsx";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"dsx",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintCentroidFlag)(disassembler,instructionToken,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_61,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x26:
      mnemonic = "dsy";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"dsy",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintCentroidFlag)(disassembler,instructionToken,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_62,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x27:
      ildisSetIndent(disassembler,disassembler[0x87] + -1);
      mnemonic = "else";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"else",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisSetIndent(disassembler,disassembler[0x87] + 1);
      ildisFlushLine(disassembler,extraout_r4_x00138,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x28:
      mnemonic = "end";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"end",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisFlushLine(disassembler,extraout_r4_x00150,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 0;
      break;
    case 0x29:
      ildisSetIndent(disassembler,disassembler[0x87] + -1);
      mnemonic = "endif";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"endif",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisFlushLine(disassembler,extraout_r4_x00152,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x2a:
      ildisSetIndent(disassembler,disassembler[0x87] + -1);
      mnemonic = "endloop";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"endloop",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisFlushLine(disassembler,extraout_r4_x00153,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x2b:
      mnemonic = "endmain";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"endmain",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisFlushLine(disassembler,extraout_r4_x00139,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x2c:
      mnemonic = "exn";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"exn",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_13,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x2d:
      mnemonic = "exp";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"exp",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_15,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x2e:
      mnemonic = "expp";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"expp",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_16,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x2f:
      mnemonic = "faceforward";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"faceforward",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd3Sources)(disassembler,extraout_r4_63,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x30:
      mnemonic = "flr";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"flr",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_17,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x31:
      mnemonic = "frc";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"frc",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_18,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x32:
      mnemonic = "func";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"func",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisSetIndent(disassembler,disassembler[0x87] + 1);
      ildisAppendf(disassembler," ",mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisPrintUnsigned(disassembler,extraout_r4_x00154,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisFlushLine(disassembler,extraout_r4_x00155,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x33:
      mnemonic = "fwidth";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"fwidth",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_19,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x34:
      mnemonic = "ifc";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"ifc",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisSetIndent(disassembler,disassembler[0x87] + 1);
      ((int (*)())ildisPrintRelop)(disassembler,instructionToken,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisAppendf(disassembler," ",mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintSourceOperand)(disassembler,extraout_r4_x00156,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
      ildisAppendf(disassembler,", ",mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintSourceOperand)(disassembler,extraout_r4_x00157,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
      ildisFlushLine(disassembler,extraout_r4_x00158,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x35:
      mnemonic = "ifnz ";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"ifnz ",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisSetIndent(disassembler,disassembler[0x87] + 1);
      ((int (*)())ildisPrintSourceOperand)(disassembler,extraout_r4_x00164,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
      ildisFlushLine(disassembler,extraout_r4_x00165,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x36:
    case 0x43:
      ildisAppendIndentedf(disassembler,disassembler[0x87],"memimport",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      memimportElement = instructionToken >> 0x10 & 0x3f;
      printf_LDBLStub_1a32d0(&scratchText,"_elem(%d)",memimportElement,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisAppendf(disassembler,&scratchText,memimportElement,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_x00237,memimportElement,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x37:
      mnemonic = "kill";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"kill",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintStage)(disassembler,instructionToken,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintSampleFlag)(disassembler,instructionToken,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
      ildisAppendf(disassembler," ",mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintSourceOperand)(disassembler,extraout_r4_x00109,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
      ildisFlushLine(disassembler,extraout_r4_x00110,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x38:
      mnemonic = "len";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"len",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_21,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x39:
      mnemonic = "lit";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"lit",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_22,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x3a:
      mnemonic = "ln";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"ln",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintZeroOp)(disassembler,instructionToken,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_64,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x3b:
      mnemonic = "lod";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"lod",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintStage)(disassembler,instructionToken,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_x00231,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x3c:
      mnemonic = "log";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"log",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintZeroOp)(disassembler,instructionToken,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_65,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x3d:
      mnemonic = "logp";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"logp",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintZeroOp)(disassembler,instructionToken,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_66,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x3e:
      mnemonic = "loop";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"loop",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      if ((instructionToken & 0x10000) == 0) {
        repSuffix = " ";
      }
      else {
        repSuffix = "_rep ";
      }
      ildisAppendf(disassembler,repSuffix,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisSetIndent(disassembler,disassembler[0x87] + 1);
      ((int (*)())ildisPrintSourceOperand)(disassembler,extraout_r4_x00170,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
      ildisFlushLine(disassembler,extraout_r4_x00171,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x3f:
      mnemonic = "lrp";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"lrp",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd3Sources)(disassembler,extraout_r4_67,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x40:
      mnemonic = "mad";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"mad",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd3Sources)(disassembler,extraout_r4_68,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x41:
      mnemonic = "max";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"max",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd2Sources)(disassembler,extraout_r4_50,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x42:
      ildisAppendIndentedf(disassembler,disassembler[0x87],"memexport",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      memexportElemOffset = instructionToken >> 0x17 & 0x3f;
      exportStreamId = instructionToken >> 0x10 & 0x3f;
      instructionToken = instructionToken >> 0x16 & 1;
      printf_LDBLStub_1a32d0(&scratchText,"_exportStream(%d)_stateStride(%d)_elemOffset(%d)",exportStreamId,instructionToken,memexportElemOffset
                   ,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisAppendf(disassembler,&scratchText,exportStreamId,instructionToken,memexportElemOffset,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_x00240,exportStreamId,instructionToken,memexportElemOffset,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x44:
      mnemonic = "min";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"min",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd2Sources)(disassembler,extraout_r4_51,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x45:
      mnemonic = "mmul";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"mmul",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintMatrixMode)(disassembler,instructionToken,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd2Sources)(disassembler,extraout_r4_95,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x46:
      mnemonic = "mod";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"mod",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd2Sources)(disassembler,extraout_r4_52,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x47:
      mnemonic = "mov";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"mov",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_25,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x48:
      mnemonic = "mova";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"mova",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintRoundFlag)(disassembler,instructionToken,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_96,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x49:
      mnemonic = "mul";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"mul",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd2Sources)(disassembler,extraout_r4_53,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x4a:
      mnemonic = "noise";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"noise",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_26,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x4b:
      mnemonic = "nop";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"nop",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisFlushLine(disassembler,extraout_r4_x00173,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x4c:
      mnemonic = "nrm";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"nrm",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      if ((instructionToken & 0x40000) != 0) {
        ildisAppendf(disassembler,"_nrm4",mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      }
      ((int (*)())ildisPrintZeroOp)(disassembler,instructionToken,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_97,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x4d:
      mnemonic = "pireduce";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"pireduce",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_28,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x4e:
      mnemonic = "pow";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"pow",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd2Sources)(disassembler,extraout_r4_54,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x50:
      mnemonic = "project";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"project",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintStage)(disassembler,instructionToken,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_98,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x51:
      mnemonic = "rcp";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"rcp",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintZeroOp)(disassembler,instructionToken,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_99,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x52:
      mnemonic = "reflect";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"reflect",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintNormalizeFlag)(disassembler,instructionToken,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
      ((int (*)())ildisPrintDestAnd2Sources)(disassembler,extraout_r4_x00100,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x53:
      ildisSetIndent(disassembler,disassembler[0x87] + -1);
      mnemonic = "ret";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"ret",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisFlushLine(disassembler,extraout_r4_x00174,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x54:
      mnemonic = "rnd";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"rnd",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_29,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x55:
      mnemonic = "rsq";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"rsq",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintZeroOp)(disassembler,instructionToken,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_x00101,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x56:
      mnemonic = "set";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"set",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintRelop)(disassembler,instructionToken,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd2Sources)(disassembler,extraout_r4_x00102,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x57:
      mnemonic = "sgn";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"sgn",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_38,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x58:
      mnemonic = "sin";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"sin",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_39,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x59:
      mnemonic = "sincos";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"sincos",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_40,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x5a:
      mnemonic = "sqrt";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"sqrt",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_41,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x5b:
      mnemonic = "sub";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"sub",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd2Sources)(disassembler,extraout_r4_55,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x5c:
      mnemonic = "tan";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"tan",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_42,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x5d:
      mnemonic = "texld";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"texld",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintLoadModifiers)(disassembler,instructionToken,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_x00232,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x5e:
      mnemonic = "texldb";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"texldb",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintSampleModifiers)(disassembler,instructionToken,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd2Sources)(disassembler,extraout_r4_x00233,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x5f:
      mnemonic = "texldd";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"texldd",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintLoadModifiers)(disassembler,instructionToken,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd3Sources)(disassembler,extraout_r4_x00234,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x60:
      mnemonic = "texldms";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"texldms",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintTexldmsModifiers)(disassembler,instructionToken,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_x00235,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x61:
      mnemonic = "texweight";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"texweight",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintStage)(disassembler,instructionToken,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintCentroidFlag)(disassembler,instructionToken,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_x00236,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x62:
      mnemonic = "transpose";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"transpose",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_x00103,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 99:
      mnemonic = "trc";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"trc",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_43,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 100:
      mnemonic = "dxsincos";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"dxsincos",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd3Sources)(disassembler,extraout_r4_11,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x65:
      mnemonic = "break_logicalz";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"break_logicalz",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisAppendf(disassembler," ",mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintSourceOperand)(disassembler,extraout_r4_x00115,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
      ildisFlushLine(disassembler,extraout_r4_x00116,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x66:
      mnemonic = "break_logicalnz";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"break_logicalnz",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisAppendf(disassembler," ",mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintSourceOperand)(disassembler,extraout_r4_x00117,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
      ildisFlushLine(disassembler,extraout_r4_x00118,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x67:
      mnemonic = "call_logicalz";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"call_logicalz",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisAppendf(disassembler," ",mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintSourceOperand)(disassembler,extraout_r4_x00124,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
      ildisAppendf(disassembler,", ",mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisPrintUnsigned(disassembler,extraout_r4_x00125,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisFlushLine(disassembler,extraout_r4_x00126,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x68:
      mnemonic = "call_logicalnz";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"call_logicalnz",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisAppendf(disassembler," ",mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintSourceOperand)(disassembler,extraout_r4_x00127,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
      ildisAppendf(disassembler,", ",mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisPrintUnsigned(disassembler,extraout_r4_x00128,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisFlushLine(disassembler,extraout_r4_x00129,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x69:
      mnemonic = "case ";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"case ",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisAppendf(disassembler," ",mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      immediateWord = *(undefined4 *)disassembler[2];
      disassembler[2] = (int)((undefined4 *)disassembler[2] + 1);
      printf_LDBLStub_1a32d0(&scratchText,"%lu",immediateWord,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisAppendf(disassembler,&scratchText,immediateWord,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisFlushLine(disassembler,extraout_r4_x00163,immediateWord,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x6a:
      mnemonic = "continue_logicalz";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"continue_logicalz",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr
                  );
      ildisAppendf(disassembler," ",mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintSourceOperand)(disassembler,extraout_r4_x00134,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
      ildisFlushLine(disassembler,extraout_r4_x00135,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x6b:
      mnemonic = "continue_logicalnz";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"continue_logicalnz",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,
                   nextWordPtr);
      ildisAppendf(disassembler," ",mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintSourceOperand)(disassembler,extraout_r4_x00136,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
      ildisFlushLine(disassembler,extraout_r4_x00137,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x6c:
      mnemonic = "default";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"default",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisFlushLine(disassembler,extraout_r4_x00162,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x6d:
      mnemonic = "endswitch";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"endswitch",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisFlushLine(disassembler,extraout_r4_x00161,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x6e:
      mnemonic = "endfunc";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"endfunc",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisFlushLine(disassembler,extraout_r4_x00151,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x6f:
      mnemonic = "if_logicalz ";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"if_logicalz ",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisSetIndent(disassembler,disassembler[0x87] + 1);
      ((int (*)())ildisPrintSourceOperand)(disassembler,extraout_r4_x00166,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
      ildisFlushLine(disassembler,extraout_r4_x00167,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x70:
      mnemonic = "if_logicalnz ";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"if_logicalnz ",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisSetIndent(disassembler,disassembler[0x87] + 1);
      ((int (*)())ildisPrintSourceOperand)(disassembler,extraout_r4_x00168,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
      ildisFlushLine(disassembler,extraout_r4_x00169,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x71:
      mnemonic = "whileloop";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"whileloop",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisFlushLine(disassembler,extraout_r4_x00172,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisSetIndent(disassembler,disassembler[0x87] + 1);
      result = 1;
      break;
    case 0x72:
      mnemonic = "switch";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"switch",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisAppendf(disassembler," ",mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintSourceOperand)(disassembler,extraout_r4_x00159,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
      ildisFlushLine(disassembler,extraout_r4_x00160,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x73:
      mnemonic = "ret_dyn";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"ret_dyn",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisFlushLine(disassembler,extraout_r4_x00175,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x74:
      mnemonic = "ret_logicalz ";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"ret_logicalz ",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintSourceOperand)(disassembler,extraout_r4_x00176,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
      ildisFlushLine(disassembler,extraout_r4_x00177,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x75:
      mnemonic = "ret_logicalnz ";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"ret_logicalnz ",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintSourceOperand)(disassembler,extraout_r4_x00178,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
      ildisFlushLine(disassembler,extraout_r4_x00179,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x76:
      if ((int)instructionToken < 0) {
        ildisAppendIndentedf(disassembler,disassembler[0x87],"dcl_immed_cb",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
        literalCount = *(int *)disassembler[2];
        disassembler[2] = (int)((int *)disassembler[2] + 1);
        literalCountCopy = literalCount;
        printf_LDBLStub_1a32d0(&scratchText,"count = %d ",literalCount,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
        ildisAppendf(disassembler,&scratchText,literalCountCopy,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
        ildisFlushLine(disassembler,extraout_r4_x00185,literalCountCopy,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
        if (0 < literalCount) {
          literalIndex = 0;
          do {
            literalIndex = literalIndex + 1;
            immediateWord = *(undefined4 *)disassembler[2];
            disassembler[2] = (int)((undefined4 *)disassembler[2] + 1);
            printf_LDBLStub_1a32d0(&scratchText," 0x%x ",immediateWord,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
            fmtArgR5 = &scratchText;
            ildisAppendIndentedf(disassembler,disassembler[0x87] + 1,&scratchText,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,
                         nextWordPtr);
            ildisFlushLine(disassembler,extraout_r4_x00186,fmtArgR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr)
            ;
          } while (literalCount != literalIndex);
        }
        result = 1;
      }
      else {
        mnemonic = "dcl_cb";
        ildisAppendIndentedf(disassembler,disassembler[0x87],"dcl_cb",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
        ildisAppendf(disassembler," ",mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
        ((int (*)())ildisPrintSourceOperand)(disassembler,extraout_r4_x00187,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
        ildisFlushLine(disassembler,extraout_r4_x00188,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
        result = 1;
      }
      break;
    case 0x77:
      mnemonic = "dcl_indexed_temp_array";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"dcl_indexed_temp_array",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,
                   nextWordPtr);
      ildisAppendf(disassembler," ",mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintSourceOperand)(disassembler,extraout_r4_x00183,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
      ildisFlushLine(disassembler,extraout_r4_x00184,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x78:
      mnemonic = "dcl_input_primitive";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"dcl_input_primitive",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,
                   nextWordPtr);
      ((int (*)())ildisPrintInputPrimitive)(disassembler,instructionToken,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisFlushLine(disassembler,extraout_r4_x00222,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x79:
      mnemonic = "dcl_literal";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"dcl_literal",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisAppendf(disassembler," ",mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintSourceOperand)(disassembler,extraout_r4_x00189,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
      ildisAppendf(disassembler,",",mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      immediatePtr2 = (undefined4 *)disassembler[2];
      defWord0 = *immediatePtr2;
      defWord3 = immediatePtr2 + 2;
      disassembler[2] = (int)(immediatePtr2 + 1);
      defWord1 = immediatePtr2[1];
      disassembler[2] = (int)defWord3;
      defWord2 = immediatePtr2[2];
      disassembler[2] = (int)(immediatePtr2 + 3);
      defWord3Printed = immediatePtr2[3];
      disassembler[2] = (int)(immediatePtr2 + 4);
      printf_LDBLStub_1a32d0(&textBuffer," 0x%08lX, 0x%08lX, 0x%08lX, 0x%08lX",defWord0,defWord1,defWord2,defWord3Printed,defWord3
                   ,nextWordPtr);
      ildisAppendf(disassembler,&textBuffer,defWord0,defWord1,defWord2,defWord3Printed,defWord3,nextWordPtr);
      ildisFlushLine(disassembler,extraout_r4_x00190,defWord0,defWord1,defWord2,defWord3Printed,defWord3,nextWordPtr);
      result = 1;
      break;
    case 0x7a:
      ildisAppendIndentedf(disassembler,disassembler[0x87],"dcl_max_output_vertex_count",fmtArgR6,fmtArgR7,fmtArgR8,
                   fmtArgR9,nextWordPtr);
      maxOutputVertexCount = instructionToken >> 0x10 & 0x3fff;
      printf_LDBLStub_1a32d0(&scratchText,"(%d)",maxOutputVertexCount,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisAppendf(disassembler,&scratchText,maxOutputVertexCount,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisFlushLine(disassembler,extraout_r4_x00208,maxOutputVertexCount,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x7b:
      mnemonic = "dcl_odepth";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"dcl_odepth",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisFlushLine(disassembler,extraout_r4_x00224,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x7c:
      mnemonic = "dcl_output_topology";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"dcl_output_topology",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,
                   nextWordPtr);
      ((int (*)())ildisPrintOutputTopology)(disassembler,instructionToken,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisFlushLine(disassembler,extraout_r4_x00209,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x7d:
      mnemonic = "dcl_output";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"dcl_output",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      outputSemantic = instructionToken >> 0x10 & 0x3fff;
      lastReturnR4 = extraout_r4_x00210;
      if (outputSemantic < 0x13) {
        ildisAppendf(disassembler,(PTR_s__position_001dc3f4)[outputSemantic],mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,
                     fmtArgR9,nextWordPtr);
        lastReturnR4 = extraout_r4_x00211;
      }
      ((int (*)())ildisPrintDestinationOperand)(disassembler,lastReturnR4,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisFlushLine(disassembler,extraout_r4_x00212,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x7e:
      mnemonic = "dcl_input";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"dcl_input",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      lastReturnR4 = extraout_r4_x00213;
      if ((instructionToken & 0x7c000) != 0x14000) {
        ildisAppendf(disassembler,*(undefined4 *)
                              ((int)PTR_s__position_001dc3f4 + (instructionToken >> 0xc & 0x7c)),mnemonic,
                     fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
        lastReturnR4 = extraout_r4_x00214;
      }
      interpolationMode = instructionToken >> 0x13 & 7;
      if (interpolationMode < 6) {
        fmtArgR9 = 0;
        switch(interpolationMode) {
        case 1:
          ildisAppendf(disassembler,"_interp(constant)",mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
          lastReturnR4 = extraout_r4_x00215;
          break;
        case 2:
          ildisAppendf(disassembler,"_interp(linear)",mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
          lastReturnR4 = extraout_r4_x00216;
          break;
        case 3:
          ildisAppendf(disassembler,"_interp(linear_centroid)",mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,
                       nextWordPtr);
          lastReturnR4 = extraout_r4_x00217;
          break;
        case 4:
          ildisAppendf(disassembler,"_interp(linear_noperspective)",mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,
                       fmtArgR9,nextWordPtr);
          lastReturnR4 = extraout_r4_x00218;
          break;
        case 5:
          ildisAppendf(disassembler,"_interp(linear_noperspective_centroid)",mnemonic,fmtArgR6,fmtArgR7,
                       fmtArgR8,fmtArgR9,nextWordPtr);
          lastReturnR4 = extraout_r4_x00219;
        }
      }
      else {
        ildisAppendf(disassembler,"!!!bad interp mode!!!",mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr)
        ;
        *disassembler = *disassembler + 1;
        lastReturnR4 = extraout_r4_x00220;
      }
      ((int (*)())ildisPrintDestinationOperand)(disassembler,lastReturnR4,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisFlushLine(disassembler,extraout_r4_x00221,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x7f:
      mnemonic = "dcl_vprim";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"dcl_vprim",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisFlushLine(disassembler,extraout_r4_x00223,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x80:
      ildisAppendIndentedf(disassembler,disassembler[0x87],"dcl_resource",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      resourceId = instructionToken >> 0x10 & 0xff;
      printf_LDBLStub_1a32d0(&textBuffer,"_id(%d)",resourceId,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisAppendf(disassembler,&textBuffer,resourceId,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintResourceType)(disassembler,instructionToken >> 0x18 & 0xf,resourceId,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
      ildisPrintFormatXyzw(disassembler,extraout_r4_x00225,resourceId,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisFlushLine(disassembler,extraout_r4_x00226,resourceId,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x81:
      mnemonic = "cut";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"cut",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisFlushLine(disassembler,extraout_r4_x00141,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x82:
      mnemonic = "discard_logicalz";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"discard_logicalz",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr)
      ;
      ildisAppendf(disassembler," ",mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintSourceOperand)(disassembler,extraout_r4_x00227,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
      ildisFlushLine(disassembler,extraout_r4_x00228,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x83:
      mnemonic = "discard_logicalnz";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"discard_logicalnz",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr
                  );
      ildisAppendf(disassembler," ",mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintSourceOperand)(disassembler,extraout_r4_x00229,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
      ildisFlushLine(disassembler,extraout_r4_x00230,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x84:
      mnemonic = "emit";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"emit",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisFlushLine(disassembler,extraout_r4_x00140,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x85:
      mnemonic = "emitcut";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"emitcut",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisFlushLine(disassembler,extraout_r4_x00142,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x86:
      ildisAppendIndentedf(disassembler,disassembler[0x87],"load",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      loadResourceId = instructionToken >> 0x10 & 0x1fff;
      printf_LDBLStub_1a32d0(&textBuffer,"_id(%d)",loadResourceId,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisAppendf(disassembler,&textBuffer,loadResourceId,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisPrintAddressOffsetImmediate(disassembler,instructionToken,loadResourceId,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_x00143,loadResourceId,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x87:
      ildisAppendIndentedf(disassembler,disassembler[0x87],"resinfo",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      resinfoResourceId = instructionToken >> 0x10 & 0xfff;
      printf_LDBLStub_1a32d0(&textBuffer,"_id(%d)",resinfoResourceId,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisAppendf(disassembler,&textBuffer,resinfoResourceId,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      lastReturnR4 = extraout_r4_x00238;
      if ((instructionToken & 0x10000000) != 0) {
        ildisAppendf(disassembler,"_uint",resinfoResourceId,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
        lastReturnR4 = extraout_r4_x00239;
      }
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,lastReturnR4,resinfoResourceId,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x88:
      mnemonic = "sample";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"sample",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisPrintResourceSampler(disassembler,instructionToken,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisPrintAddressOffsetImmediate(disassembler,instructionToken,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_x00144,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x89:
      mnemonic = "sample_b";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"sample_b",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisPrintResourceSampler(disassembler,instructionToken,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisPrintAddressOffsetImmediate(disassembler,instructionToken,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd2Sources)(disassembler,extraout_r4_x00146,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x8a:
      mnemonic = "sample_g";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"sample_g",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisPrintResourceSampler(disassembler,instructionToken,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisPrintAddressOffsetImmediate(disassembler,instructionToken,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd3Sources)(disassembler,extraout_r4_x00145,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x8b:
      mnemonic = "sample_l";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"sample_l",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisPrintResourceSampler(disassembler,instructionToken,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisPrintAddressOffsetImmediate(disassembler,instructionToken,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_x00147,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x8c:
      mnemonic = "sample_c";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"sample_c",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisPrintResourceSampler(disassembler,instructionToken,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisPrintAddressOffsetImmediate(disassembler,instructionToken,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd2Sources)(disassembler,extraout_r4_x00148,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x8d:
      mnemonic = "sample_c_lz";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"sample_c_lz",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisPrintResourceSampler(disassembler,instructionToken,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ildisPrintAddressOffsetImmediate(disassembler,instructionToken,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd2Sources)(disassembler,extraout_r4_x00149,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x8e:
      mnemonic = "inot";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"inot",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_x00105,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x8f:
      mnemonic = "ior";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"ior",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd2Sources)(disassembler,extraout_r4_x00106,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x90:
      mnemonic = "ixor";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"ixor",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd2Sources)(disassembler,extraout_r4_x00107,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x91:
      mnemonic = "iadd";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"iadd",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd2Sources)(disassembler,extraout_r4_x00108,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x92:
      mnemonic = "imad";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"imad",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd3Sources)(disassembler,extraout_r4_69,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x93:
      mnemonic = "imax";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"imax",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd2Sources)(disassembler,extraout_r4_70,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x94:
      mnemonic = "imin";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"imin",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd2Sources)(disassembler,extraout_r4_71,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x95:
      mnemonic = "imul";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"imul",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd2Sources)(disassembler,extraout_r4_72,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x96:
      mnemonic = "imul_high";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"imul_high",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd2Sources)(disassembler,extraout_r4_73,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x97:
      mnemonic = "ieq";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"ieq",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd2Sources)(disassembler,extraout_r4_74,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x98:
      mnemonic = "ige";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"ige",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd2Sources)(disassembler,extraout_r4_75,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x99:
      mnemonic = "ilt";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"ilt",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd2Sources)(disassembler,extraout_r4_76,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x9a:
      mnemonic = "inegate";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"inegate",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_77,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x9b:
      mnemonic = "ine";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"ine",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd2Sources)(disassembler,extraout_r4_78,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x9c:
      mnemonic = "ishl";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"ishl",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd2Sources)(disassembler,extraout_r4_79,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x9d:
      mnemonic = "ishr";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"ishr",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd2Sources)(disassembler,extraout_r4_80,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x9e:
      mnemonic = "ushr";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"ushr",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd2Sources)(disassembler,extraout_r4_81,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0x9f:
      mnemonic = "udiv";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"udiv",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd2Sources)(disassembler,extraout_r4_82,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0xa0:
      mnemonic = "umod";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"umod",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd2Sources)(disassembler,extraout_r4_83,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0xa1:
      mnemonic = "umad";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"umad",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd3Sources)(disassembler,extraout_r4_84,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0xa2:
      mnemonic = "umax";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"umax",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd2Sources)(disassembler,extraout_r4_85,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0xa3:
      mnemonic = "umin";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"umin",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd2Sources)(disassembler,extraout_r4_86,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0xa4:
      mnemonic = "ult";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"ult",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd2Sources)(disassembler,extraout_r4_87,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0xa5:
      mnemonic = "uge";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"uge",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd2Sources)(disassembler,extraout_r4_88,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0xa6:
      mnemonic = "umul";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"umul",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd2Sources)(disassembler,extraout_r4_89,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0xa7:
      mnemonic = "umul_high";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"umul_high",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd2Sources)(disassembler,extraout_r4_90,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0xa8:
      mnemonic = "ftoi";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"ftoi",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_91,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0xa9:
      mnemonic = "ftou";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"ftou",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_92,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0xaa:
      mnemonic = "itof";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"itof",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_93,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0xab:
      mnemonic = "utof";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"utof",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_94,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0xac:
      mnemonic = "and";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"and",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd2Sources)(disassembler,extraout_r4_03,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0xad:
      mnemonic = "cmov_logical";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"cmov_logical",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd3Sources)(disassembler,extraout_r4_08,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0xae:
      mnemonic = "eq";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"eq",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd2Sources)(disassembler,extraout_r4_12,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0xaf:
      mnemonic = "exp_vec";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"exp_vec",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_14,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0xb0:
      mnemonic = "ge";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"ge",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd2Sources)(disassembler,extraout_r4_20,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0xb1:
      mnemonic = "log_vec";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"log_vec",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_23,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0xb2:
      mnemonic = "lt";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"lt",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd2Sources)(disassembler,extraout_r4_24,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0xb3:
      mnemonic = "ne";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"ne",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd2Sources)(disassembler,extraout_r4_27,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0xb4:
      mnemonic = "round_nearest";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"round_nearest",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_30,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0xb5:
      mnemonic = "round_neginf";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"round_neginf",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_31,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0xb6:
      mnemonic = "round_plusinf";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"round_plusinf",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_32,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0xb7:
      mnemonic = "round_zero";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"round_zero",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_33,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0xb8:
      mnemonic = "rsq_vec";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"rsq_vec",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_34,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0xb9:
      mnemonic = "sin_vec";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"sin_vec",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_35,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0xba:
      mnemonic = "cos_vec";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"cos_vec",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_36,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0xbb:
      mnemonic = "sqrt_vec";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"sqrt_vec",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd1Source)(disassembler,extraout_r4_37,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0xbc:
      mnemonic = "dp2";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"dp2",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintDestAnd2Sources)(disassembler,extraout_r4_59,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
      break;
    case 0xbe:
      mnemonic = "scatter";
      ildisAppendIndentedf(disassembler,disassembler[0x87],"scatter",fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      if ((instructionToken & 0x3fff0000) != 0) {
        ildisAppendf(disassembler,"_quad",mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      }
      ildisAppendf(disassembler," ",mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      ((int (*)())ildisPrintSourceOperand)(disassembler,extraout_r4,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
      ildisFlushLine(disassembler,extraout_r4_00,mnemonic,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
      result = 1;
    }
  }
  else {
switchD_000ddc1c_caseD_0:
    *disassembler = *disassembler + 1;
    ildisAppendf(disassembler,"!!!unknownOpcode!!!",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,nextWordPtr);
    result = 1;
  }
  return result;
}

/* ildisRun @ 0xe0640 (84 bytes) */
int ildisRun(disassembler, passThroughR4, passThroughR5, fmtArgR6, fmtArgR7, fmtArgR8)
  int disassembler;
  undefined4 passThroughR4;
  undefined4 passThroughR5;
  undefined4 fmtArgR6;
  undefined4 fmtArgR7;
  undefined4 fmtArgR8;
{
  undefined8 uVar1;
  
  do {
    if ((uint)(*(int *)(disassembler + 0xc) * 4 + *(int *)(disassembler + 4)) <= *(uint *)(disassembler + 8)) {
      return;
    }
    uVar1 = ((int (*)())ildisPrintInstruction)(disassembler,passThroughR4,passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,*(int *)(disassembler + 4));
    passThroughR4 = (undefined4)uVar1;
  } while ((int)((ulonglong)uVar1 >> 0x20) != 0);
  return;
}

/* ildisPrintProgram @ 0xe0694 (68 bytes) */
int ildisPrintProgram(disassembler, tokenStart, tokenCount)
  int disassembler;
  undefined4 tokenStart;
  undefined4 tokenCount;
{
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 in_r9;
  undefined4 in_r10;
  
  *(undefined4 *)(disassembler + 0xc) = tokenCount;
  *(undefined4 *)(disassembler + 4) = tokenStart;
  *(undefined4 *)(disassembler + 8) = tokenStart;
  ildisSkipToken(disassembler);
  ((int (*)())ildisPrintHeader)(disassembler,extraout_r4,tokenCount,in_r6,in_r7,in_r8,in_r9,in_r10);
  return ((int (*)())ildisRun)(disassembler,extraout_r4_00,tokenCount,in_r6,in_r7,in_r8);
}

/* ildisDisassembleTokens @ 0xe06d8 (104 bytes) */
int ildisDisassembleTokens(sinkArg, tokenStart, tokenCount, sinkRecord)
  undefined4 sinkArg;
  int tokenStart;
  int tokenCount;
  int sinkRecord;
{
  undefined1 auStack_248 [528];
  int sinkRecordField;
  undefined4 sinkArgField;
  
  if (((sinkRecord != 0) && (tokenStart != 0)) && (tokenCount != 0)) {
    ildisInitContext(auStack_248);
    sinkRecordField = sinkRecord;
    sinkArgField = sinkArg;
    ((int (*)())ildisPrintProgram)(auStack_248,tokenStart,tokenCount);
  }
  return;
}

/* ildisDisassembleBody @ 0xe0740 (80 bytes) */
int ildisDisassembleBody(disassembler, tokenStart, tokenCount, fmtArgR6, fmtArgR7, fmtArgR8)
  int disassembler;
  undefined4 tokenStart;
  undefined4 tokenCount;
  undefined4 fmtArgR6;
  undefined4 fmtArgR7;
  undefined4 fmtArgR8;
{
  undefined4 extraout_r4;
  undefined4 lineBufferSize;
  
  *(undefined4 *)(disassembler + 0xc) = tokenCount;
  lineBufferSize = 0x200;
  *(undefined4 *)(disassembler + 4) = tokenStart;
  *(undefined4 *)(disassembler + 8) = tokenStart;
  _memset(disassembler + 0x10,0,0x200);
  *(undefined4 *)(disassembler + 0x218) = 0;
  return ((int (*)())ildisRun)(disassembler,extraout_r4,lineBufferSize,fmtArgR6,fmtArgR7,fmtArgR8);
}

/* Compiler__setOptionBit @ 0xe0794 (36 bytes) */
int Compiler__setOptionBit(param_1, param_2)
  int param_1;
  uint param_2;
{
  int iVar1;
  
  iVar1 = ((int)param_2 >> 3) + param_1;
  *(byte *)(iVar1 + 0x59c) = (byte)(1 << (param_2 & 7)) | *(byte *)(iVar1 + 0x59c);
  return;
}

/* Compiler__clearOptionBit @ 0xe07b8 (36 bytes) */
int Compiler__clearOptionBit(param_1, param_2)
  int param_1;
  uint param_2;
{
  int iVar1;
  
  iVar1 = ((int)param_2 >> 3) + param_1;
  *(byte *)(iVar1 + 0x59c) =
       ((byte)(-2 << (param_2 & 7)) | (byte)(0xfffffffe >> 0x20 - (param_2 & 7))) &
       *(byte *)(iVar1 + 0x59c);
  return;
}

/* Compiler__isOptionEnabled @ 0xe07dc (84 bytes) */
int Compiler__isOptionEnabled(compiler, optionId)
  int compiler;
  uint optionId;
{
  int iVar1;
  
  if ((((int)*(char *)(((int)optionId >> 3) + compiler + 0x59c) >> (optionId & 7) & 1U) != 0) &&
     (iVar1 = BitSet__testBit(*(undefined4 *)(compiler + COMP_target),optionId), iVar1 != 0)) {
    return 1;
  }
  return 0;
}

/* FUN_000e0830 @ 0xe0830 (32 bytes) */
int FUN_000e0830(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  if ((param_2 == 0) && (*(int *)(param_1 + 0x64c) == param_3)) {
    return 1;
  }
  return 0;
}

/* FUN_000e0850 @ 0xe0850 (1112 bytes) */
int FUN_000e0850(param_1)
  int param_1;
{
  ((int (*)())Compiler__clearOptionBit)(param_1,0);
  ((int (*)())Compiler__setOptionBit)(param_1,1);
  ((int (*)())Compiler__setOptionBit)(param_1,2);
  ((int (*)())Compiler__setOptionBit)(param_1,3);
  ((int (*)())Compiler__clearOptionBit)(param_1,4);
  ((int (*)())Compiler__setOptionBit)(param_1,5);
  ((int (*)())Compiler__setOptionBit)(param_1,6);
  ((int (*)())Compiler__setOptionBit)(param_1,7);
  ((int (*)())Compiler__clearOptionBit)(param_1,8);
  ((int (*)())Compiler__setOptionBit)(param_1,9);
  ((int (*)())Compiler__setOptionBit)(param_1,10);
  ((int (*)())Compiler__clearOptionBit)(param_1,0xb);
  ((int (*)())Compiler__setOptionBit)(param_1,0xc);
  ((int (*)())Compiler__clearOptionBit)(param_1,0xd);
  ((int (*)())Compiler__setOptionBit)(param_1,0xe);
  ((int (*)())Compiler__setOptionBit)(param_1,0xf);
  ((int (*)())Compiler__clearOptionBit)(param_1,0x10);
  ((int (*)())Compiler__setOptionBit)(param_1,0x11);
  ((int (*)())Compiler__clearOptionBit)(param_1,0x12);
  ((int (*)())Compiler__setOptionBit)(param_1,0x13);
  ((int (*)())Compiler__setOptionBit)(param_1,0x14);
  ((int (*)())Compiler__setOptionBit)(param_1,0x15);
  ((int (*)())Compiler__setOptionBit)(param_1,0x16);
  ((int (*)())Compiler__setOptionBit)(param_1,0x17);
  ((int (*)())Compiler__setOptionBit)(param_1,0x18);
  ((int (*)())Compiler__setOptionBit)(param_1,0x19);
  ((int (*)())Compiler__setOptionBit)(param_1,0x1a);
  ((int (*)())Compiler__setOptionBit)(param_1,0x1b);
  ((int (*)())Compiler__setOptionBit)(param_1,0x1c);
  ((int (*)())Compiler__setOptionBit)(param_1,0x1d);
  ((int (*)())Compiler__setOptionBit)(param_1,0x1e);
  ((int (*)())Compiler__setOptionBit)(param_1,0x1f);
  ((int (*)())Compiler__setOptionBit)(param_1,0x20);
  ((int (*)())Compiler__setOptionBit)(param_1,0x21);
  ((int (*)())Compiler__setOptionBit)(param_1,0x22);
  ((int (*)())Compiler__setOptionBit)(param_1,0x23);
  ((int (*)())Compiler__setOptionBit)(param_1,0x24);
  ((int (*)())Compiler__setOptionBit)(param_1,0x25);
  ((int (*)())Compiler__setOptionBit)(param_1,0x26);
  ((int (*)())Compiler__setOptionBit)(param_1,0x27);
  ((int (*)())Compiler__setOptionBit)(param_1,0x28);
  ((int (*)())Compiler__setOptionBit)(param_1,0x29);
  ((int (*)())Compiler__clearOptionBit)(param_1,0x2a);
  ((int (*)())Compiler__clearOptionBit)(param_1,0x2b);
  ((int (*)())Compiler__clearOptionBit)(param_1,0x2c);
  ((int (*)())Compiler__setOptionBit)(param_1,0x2e);
  ((int (*)())Compiler__setOptionBit)(param_1,0x2f);
  ((int (*)())Compiler__clearOptionBit)(param_1,0x4e);
  ((int (*)())Compiler__clearOptionBit)(param_1,0x4f);
  ((int (*)())Compiler__setOptionBit)(param_1,0x30);
  ((int (*)())Compiler__setOptionBit)(param_1,0x31);
  ((int (*)())Compiler__setOptionBit)(param_1,0x32);
  ((int (*)())Compiler__setOptionBit)(param_1,0x33);
  ((int (*)())Compiler__clearOptionBit)(param_1,0x34);
  ((int (*)())Compiler__setOptionBit)(param_1,0x35);
  ((int (*)())Compiler__clearOptionBit)(param_1,0x36);
  ((int (*)())Compiler__clearOptionBit)(param_1,0x37);
  ((int (*)())Compiler__setOptionBit)(param_1,0x38);
  ((int (*)())Compiler__setOptionBit)(param_1,0x39);
  ((int (*)())Compiler__setOptionBit)(param_1,0x3a);
  ((int (*)())Compiler__setOptionBit)(param_1,0x3b);
  ((int (*)())Compiler__setOptionBit)(param_1,0x3c);
  ((int (*)())Compiler__setOptionBit)(param_1,0x3d);
  ((int (*)())Compiler__clearOptionBit)(param_1,0x3e);
  ((int (*)())Compiler__setOptionBit)(param_1,0x3f);
  ((int (*)())Compiler__clearOptionBit)(param_1,0x40);
  ((int (*)())Compiler__setOptionBit)(param_1,0x41);
  ((int (*)())Compiler__setOptionBit)(param_1,0x42);
  ((int (*)())Compiler__setOptionBit)(param_1,0x43);
  ((int (*)())Compiler__clearOptionBit)(param_1,0x44);
  ((int (*)())Compiler__setOptionBit)(param_1,0x45);
  ((int (*)())Compiler__clearOptionBit)(param_1,0x46);
  ((int (*)())Compiler__setOptionBit)(param_1,0x47);
  ((int (*)())Compiler__setOptionBit)(param_1,0x48);
  ((int (*)())Compiler__setOptionBit)(param_1,0x49);
  ((int (*)())Compiler__setOptionBit)(param_1,0x4a);
  ((int (*)())Compiler__setOptionBit)(param_1,0x4b);
  ((int (*)())Compiler__clearOptionBit)(param_1,0x4c);
  ((int (*)())Compiler__setOptionBit)(param_1,0x4d);
  *(undefined4 *)(param_1 + 0x64c) = 2;
  *(undefined4 *)(param_1 + 0x6b4) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x67c) = 100;
  *(undefined4 *)(param_1 + 0x6ac) = 4;
  *(undefined4 *)(param_1 + 0x650) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x654) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x658) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x65c) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x660) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x664) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x668) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x670) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x66c) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x674) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x678) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x680) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x684) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x688) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x68c) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x690) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x694) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x698) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x69c) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x6a0) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x6a4) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x6a8) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x6b0) = 0x7fffffff;
  return;
}

/* FUN_000e0ca8 @ 0xe0ca8 (28 bytes) */
int FUN_000e0ca8(param_1)
  int param_1;
{
  *(undefined4 *)(param_1 + 0x318) = 0;
  *(undefined4 *)(param_1 + 0x478) = 0x400;
  *(undefined4 *)(param_1 + 0x47c) = 0;
  *(undefined4 *)(param_1 + 0x480) = 0;
  return;
}

/* testBit24 @ 0xe0cc8 (8 bytes) */
int testBit24(param_1, param_2)
  undefined4 param_1;
  uint param_2;
{
  return param_2 >> 0x18 & 1;
}

/* FUN_000e0cd0 @ 0xe0cd0 (308 bytes) */
int FUN_000e0cd0(param_1, param_2)
  undefined4 param_1;
  uint param_2;
{
  int iVar1;
  
  iVar1 = ((int (*)())testBit24)(param_1,param_2);
  if (iVar1 != 0) {
    ((int (*)())Compiler__clearOptionBit)(param_1,9);
    ((int (*)())Compiler__clearOptionBit)(param_1,0x14);
    ((int (*)())Compiler__clearOptionBit)(param_1,0x1c);
    ((int (*)())Compiler__clearOptionBit)(param_1,0x1d);
    ((int (*)())Compiler__clearOptionBit)(param_1,0x39);
    ((int (*)())Compiler__clearOptionBit)(param_1,0x3b);
    ((int (*)())Compiler__clearOptionBit)(param_1,0x42);
    ((int (*)())Compiler__clearOptionBit)(param_1,0x27);
  }
  if ((param_2 & 0x100000) != 0) {
    ((int (*)())Compiler__setOptionBit)(param_1,0x2a);
  }
  if ((param_2 & 0x200000) != 0) {
    ((int (*)())Compiler__setOptionBit)(param_1,0x2b);
  }
  if ((param_2 & 0x200) != 0) {
    ((int (*)())Compiler__clearOptionBit)(param_1,0x3f);
  }
  if ((param_2 & 0x800) != 0) {
    ((int (*)())Compiler__clearOptionBit)(param_1,0x37);
  }
  if ((param_2 & 0x1000) != 0) {
    ((int (*)())Compiler__setOptionBit)(param_1,0x3e);
  }
  if ((param_2 & 0x2000) != 0) {
    ((int (*)())Compiler__setOptionBit)(param_1,0x4e);
  }
  if ((param_2 & 0x4000) != 0) {
    ((int (*)())Compiler__setOptionBit)(param_1,0x4f);
    return;
  }
  return;
}

/* Compiler__logf @ 0xe0e0c (28 bytes) */
int Compiler__logf(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  return;
}

/* FUN_000e0e28 @ 0xe0e28 (116 bytes) */
int FUN_000e0e28(param_1)
  int param_1;
{
  int iVar1;
  undefined1 auStack_b8 [128];
  undefined1 local_38;
  
  if (0 < *(int *)(param_1 + 0x3a4)) {
    iVar1 = 0;
    do {
      _memcpy(auStack_b8,iVar1 + *(int *)(param_1 + 0x3a0),0x80);
      iVar1 = iVar1 + 0x80;
      local_38 = 0;
    } while (iVar1 < *(int *)(param_1 + 0x3a4));
  }
  *(undefined4 *)(param_1 + 0x3a8) = 0;
  *(undefined4 *)(param_1 + 0x3a4) = 0;
  return;
}

/* noop_e0e9c @ 0xe0e9c (4 bytes) */
int noop_e0e9c()
{
  return;
}

/* noop_e0ea0 @ 0xe0ea0 (28 bytes) */
int noop_e0ea0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  return;
}

/* isWhitespaceChar @ 0xe0ebc (44 bytes) */
int isWhitespaceChar(param_1)
  int param_1;
{
  if ((((param_1 != 0x20) && (param_1 != 9)) && (param_1 != 10)) && (param_1 != 0xd)) {
    return 0;
  }
  return 1;
}

/* Compiler__setOption @ 0xe0ee8 (1184 bytes) */
int Compiler__setOption(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  int compareResult;
  bool bVar1;
  undefined4 length;
  int iVar3;
  int iVar4;
  undefined **ppuVar5;
  
  length = _strlen(param_2);
  ppuVar5 = &PTR_s_OPT_IGNORE_DEFINED_CONSTANTS_001dc444;
  iVar4 = 0;
  while (iVar3 = _strncmp(*ppuVar5,param_2,length), iVar3 != 0) {
    bVar1 = iVar4 == 0x4f;
    ppuVar5 = ppuVar5 + 1;
    iVar4 = iVar4 + 1;
    if (bVar1) {
      compareResult = _strncmp("opt_flatten_if_state",param_2,length);
      if (compareResult == 0) {
        *(int *)(param_1 + 0x64c) = param_3;
      }
      else {
        compareResult = _strncmp("max_copy_folds",param_2,length);
        if (compareResult == 0) {
          *(int *)(param_1 + 0x650) = param_3;
        }
        else {
          compareResult = _strncmp("max_vn_kills",param_2,length);
          if (compareResult == 0) {
            *(int *)(param_1 + 0x654) = param_3;
          }
          else {
            compareResult = _strncmp("max_vn_transforms",param_2,length);
            if (compareResult == 0) {
              *(int *)(param_1 + 0x658) = param_3;
            }
            else {
              compareResult = _strncmp("max_copy_merges",param_2,length);
              if (compareResult == 0) {
                *(int *)(param_1 + 0x65c) = param_3;
              }
              else {
                compareResult = _strncmp("max_copy_props",param_2,length);
                if (compareResult == 0) {
                  *(int *)(param_1 + 0x660) = param_3;
                }
                else {
                  compareResult = _strncmp("max_mix_insts",param_2,length);
                  if (compareResult == 0) {
                    *(int *)(param_1 + 0x664) = param_3;
                  }
                  else {
                    compareResult = _strncmp("max_presubs",param_2,length);
                    if (compareResult == 0) {
                      *(int *)(param_1 + 0x668) = param_3;
                    }
                    else {
                      compareResult = _strncmp("max_mov_and_shift",param_2,length);
                      if (compareResult == 0) {
                        *(int *)(param_1 + 0x670) = param_3;
                      }
                      else {
                        compareResult = _strncmp("max_useless_phis",param_2,length);
                        if (compareResult == 0) {
                          *(int *)(param_1 + 0x66c) = param_3;
                        }
                        else {
                          compareResult = _strncmp("max_balance_conversions",param_2,length);
                          if (compareResult == 0) {
                            *(int *)(param_1 + 0x674) = param_3;
                          }
                          else {
                            compareResult = _strncmp("max_coalesce_loops",param_2,length);
                            if (compareResult == 0) {
                              *(int *)(param_1 + 0x678) = param_3;
                            }
                            else {
                              compareResult = _strncmp("max_spill_loops",param_2,length);
                              if (compareResult == 0) {
                                *(int *)(param_1 + 0x67c) = param_3;
                              }
                              else {
                                compareResult = _strncmp("max_inst_hoists",param_2,length);
                                if (compareResult == 0) {
                                  *(int *)(param_1 + 0x680) = param_3;
                                }
                                else {
                                  compareResult = _strncmp("max_mad_mul_to_d2a",param_2,length);
                                  if (compareResult == 0) {
                                    *(int *)(param_1 + 0x684) = param_3;
                                  }
                                  else {
                                    compareResult = _strncmp("max_mad_d2a_to_dp3",param_2,length);
                                    if (compareResult == 0) {
                                      *(int *)(param_1 + 0x688) = param_3;
                                    }
                                    else {
                                      compareResult = _strncmp("max_add_add_to_dp3",param_2,length);
                                      if (compareResult == 0) {
                                        *(int *)(param_1 + 0x68c) = param_3;
                                      }
                                      else {
                                        compareResult = _strncmp("max_add_mul_to_mad",param_2,length);
                                        if (compareResult == 0) {
                                          *(int *)(param_1 + 0x690) = param_3;
                                        }
                                        else {
                                          compareResult = _strncmp("max_add_mad_mul_to_mov_mad_mad",param_2,
                                                           length);
                                          if (compareResult == 0) {
                                            *(int *)(param_1 + 0x694) = param_3;
                                          }
                                          else {
                                            compareResult = _strncmp("max_reassociate",param_2,length);
                                            if (compareResult == 0) {
                                              *(int *)(param_1 + 0x698) = param_3;
                                            }
                                            else {
                                              compareResult = _strncmp("max_reconst_alu",param_2,length);
                                              if (compareResult == 0) {
                                                *(int *)(param_1 + 0x69c) = param_3;
                                              }
                                              else {
                                                compareResult = _strncmp("max_remove_cnd_input",param_2,
                                                                 length);
                                                if (compareResult == 0) {
                                                  *(int *)(param_1 + 0x6a0) = param_3;
                                                }
                                                else {
                                                  compareResult = _strncmp("max_r600_minimize_cf_attempts",
                                                                   param_2,length);
                                                  if (compareResult == 0) {
                                                    *(int *)(param_1 + 0x6a4) = param_3;
                                                  }
                                                  else {
                                                    compareResult = _strncmp("max_flatten_if",param_2,length)
                                                    ;
                                                    if (compareResult == 0) {
                                                      *(int *)(param_1 + 0x6a8) = param_3;
                                                    }
                                                    else {
                                                      compareResult = _strncmp("rearrange_tree_depth",
                                                                       param_2,length);
                                                      if (compareResult == 0) {
                                                        *(int *)(param_1 + 0x6ac) = param_3;
                                                      }
                                                      else {
                                                        compareResult = _strncmp("limit_registers",param_2,
                                                                         length);
                                                        if (compareResult == 0) {
                                                          *(int *)(param_1 + 0x6b0) = param_3;
                                                        }
                                                        else {
                                                          compareResult = _strncmp("limit_instructions",
                                                                           param_2,length);
                                                          if (compareResult == 0) {
                                                            *(int *)(param_1 + 0x6b4) = param_3;
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
                  }
                }
              }
            }
          }
        }
      }
      return;
    }
  }
  if (param_3 != 0) {
    ((int (*)())Compiler__setOptionBit)(param_1,iVar4);
    return;
  }
  ((int (*)())Compiler__clearOptionBit)(param_1,iVar4);
  return;
}

/* noop_e1388 @ 0xe1388 (4 bytes) */
int noop_e1388()
{
  return;
}

/* noop_e138c @ 0xe138c (28 bytes) */
int noop_e138c(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  return;
}

/* FUN_000e13a8 @ 0xe13a8 (12 bytes) */
int FUN_000e13a8(param_1)
  int param_1;
{
  *(undefined4 *)(param_1 + 0x31c) = 1;
  return;
}

/* FUN_000e13b4 @ 0xe13b4 (152 bytes) */
int FUN_000e13b4(param_1)
  int param_1;
{
  *(undefined4 *)(param_1 + 0x334) = 1;
  *(undefined4 *)(param_1 + 0x3c4) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x324) = 0;
  *(undefined4 *)(param_1 + 0x32c) = 0;
  *(undefined4 *)(param_1 + 0x330) = 0;
  *(undefined4 *)(param_1 + 0x338) = 0;
  *(undefined4 *)(param_1 + 0x33c) = 0;
  *(undefined4 *)(param_1 + 0x340) = 0;
  *(undefined4 *)(param_1 + 0x344) = 0;
  *(undefined4 *)(param_1 + 0x348) = 0;
  *(undefined4 *)(param_1 + 0x3ac) = 0;
  *(undefined4 *)(param_1 + 0x3b0) = 0;
  *(undefined4 *)(param_1 + 0x3b4) = 0;
  *(undefined4 *)(param_1 + 0x3b8) = 0;
  *(undefined4 *)(param_1 + 0x3bc) = 0;
  *(undefined4 *)(param_1 + 0x3c0) = 0;
  Compiler__resetValueNumbers(param_1);
  *(undefined4 *)(param_1 + 0x3d0) = 0;
  *(undefined4 *)(param_1 + 0x648) = 0;
  if (*(int *)(param_1 + 0x318) == 0) {
    *(undefined4 *)(param_1 + 0x6bc) = 0;
    *(undefined4 *)(param_1 + 0x39c) = 0;
    *(undefined4 *)(param_1 + 0x6b8) = 0;
  }
  return;
}

/* FUN_000e144c @ 0xe144c (24 bytes) */
int FUN_000e144c(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  *(undefined4 *)(param_1 + 0x594) = param_7;
  *(undefined4 *)(param_1 + 0x588) = param_2;
  *(undefined4 *)(param_1 + 0x58c) = param_4;
  *(undefined4 *)(param_1 + 0x590) = param_5;
  *(undefined4 *)(param_1 + 0x598) = param_6;
  return;
}

/* Compiler__timerOutputFileName @ 0xe1464 (28 bytes) */
int Compiler__timerOutputFileName()
{
  return "timer.out";
}

/* Compiler__releaseOutputBuffer @ 0xe1484 (80 bytes) */
int Compiler__releaseOutputBuffer(param_1)
  int param_1;
{
  if (*(int *)(param_1 + 0x584) != 0) {
    /* issue #79 class: r4 = `lwz r4,0x584(r3)` (the field just tested) is the object handed to the release callback */
    (**(code **)(param_1 + 0x34c))(*(undefined4 *)(param_1 + 0x354),*(undefined4 *)(param_1 + 0x584));
    *(undefined4 *)(param_1 + 0x584) = 0;
  }
  return;
}

/* Compiler__setTableEntry534 @ 0xe14d4 (16 bytes) */
int Compiler__setTableEntry534(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  *(undefined4 *)(param_2 * 4 + param_1 + 0x534) = param_3;
  return;
}

/* FUN_000e14e4 @ 0xe14e4 (80 bytes) */
int FUN_000e14e4(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(**(int **)(param_1 + 0x30c) + 0x174))
                    (*(int **)(param_1 + 0x30c),param_2,param_3,param_1);
  *(undefined4 *)(param_3 * 4 + param_1 + 0x4d4) = uVar1;
  return;
}

/* Compiler__fail @ 0xe1534 (48 bytes) */
int Compiler__fail(compiler, errorCode)
  int compiler;
  int errorCode;
{
  if (errorCode == 0) {
    *(undefined4 *)(compiler + 0x314) = 1;
  }
  else {
    *(int *)(compiler + 0x314) = errorCode;
  }
                    
  _longjmp(*(undefined4 *)(compiler + 4),1);
}

/* Compiler__allocateOrFail @ 0xe1564 (84 bytes) */
int Compiler__allocateOrFail(compiler, size)
  int compiler;
  uint size;
{
  int iVar1;
  
  iVar1 = (**(code **)(compiler + 0x350))(*(undefined4 *)(compiler + 0x354),size);
  if (iVar1 == 0) {
    ((int (*)())Compiler__fail)(compiler,2);
  }
  return iVar1;
}

