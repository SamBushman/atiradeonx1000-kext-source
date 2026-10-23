#include "decls.h"

/* _lFloatConst @ 0x97b88c98 (588 bytes) */
int _lFloatConst(lexemeBuf, mantissaLength, triggerChar, token)
  undefined4 *lexemeBuf;
  int mantissaLength;
  int triggerChar;
  int token;
{
  int currentChar;
  int cppState;
  int inputSrc;
  int fractionDigitCount;
  undefined *cppGlobalSlot;
  float floatValue;
  int readSrc;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  undefined4 extraout_r4_02;
  undefined4 extraout_r4_03;
  undefined4 scratchR4;
  int a3;
  undefined4 scratchR7;
  undefined4 scratchR8;
  undefined4 scratchR9;
  int exponentSign;
  int ungetSrc;
  int exponentValue;
  uint digitOffset;
  int writeIndex;
  int nextWriteIndex;
  double lBuildFloatValueResult;
  
  cppGlobalSlot = PTR__cpp_a7b7c0a4;
  fractionDigitCount = 0;
  exponentValue = 0;
  a3 = token;
  writeIndex = mantissaLength;
  currentChar = triggerChar;
  if (triggerChar == 0x2e) {
    *(undefined1 *)((int)lexemeBuf + mantissaLength) = 0x2e;
    writeIndex = mantissaLength + 1;
    readSrc = *(int *)(*(int *)cppGlobalSlot + 0x20);
    currentChar = (**(code **)(readSrc + 8))(readSrc,token);
    digitOffset = currentChar - 0x30;
    scratchR4 = extraout_r4;
    while (digitOffset < 10) {
      if (writeIndex < 0x80) {
        fractionDigitCount = fractionDigitCount + 1;
        if ((0 < writeIndex) || (currentChar != 0x30)) {
          *(char *)((int)lexemeBuf + writeIndex) = (char)currentChar;
          mantissaLength = mantissaLength + 1;
          writeIndex = writeIndex + 1;
        }
        readSrc = *(int *)(*(int *)cppGlobalSlot + 0x20);
        currentChar = (**(code **)(readSrc + 8))(readSrc,token);
        digitOffset = currentChar - 0x30;
        scratchR4 = extraout_r4_00;
      }
      else {
        writeIndex = 1;
        mantissaLength = 1;
        _CPPErrorToInfoLog("ERROR___FP_CONST_TOO_LONG",scratchR4,triggerChar,a3,scratchR7,scratchR8,scratchR9);
        scratchR4 = extraout_r4_01;
      }
    }
  }
  cppGlobalSlot = PTR__cpp_a7b7c0a4;
  if ((currentChar != 0x65) && (currentChar != 0x45)) goto LAB_97b88e60;
  *(char *)((int)lexemeBuf + writeIndex) = (char)currentChar;
  nextWriteIndex = writeIndex + 1;
  exponentSign = 1;
  currentChar = (**(code **)(*(int *)(*(int *)cppGlobalSlot + 0x20) + 8))
                    (*(int *)(*(int *)cppGlobalSlot + 0x20),token);
  if (currentChar == 0x2b) {
    *(undefined1 *)((int)lexemeBuf + nextWriteIndex) = 0x2b;
    cppState = *(int *)cppGlobalSlot;
LAB_97b88de8:
    currentChar = (**(code **)(*(int *)(cppState + 0x20) + 8))(*(int *)(cppState + 0x20),token);
    scratchR4 = extraout_r4_03;
    nextWriteIndex = writeIndex + 2;
  }
  else {
    scratchR4 = extraout_r4_02;
    if (currentChar == 0x2d) {
      *(undefined1 *)((int)lexemeBuf + nextWriteIndex) = 0x2d;
      cppState = *(int *)cppGlobalSlot;
      exponentSign = -1;
      goto LAB_97b88de8;
    }
  }
  writeIndex = nextWriteIndex;
  cppGlobalSlot = PTR__cpp_a7b7c0a4;
  if (currentChar - 0x30U < 10) {
    do {
      *(char *)((int)lexemeBuf + writeIndex) = (char)currentChar;
      writeIndex = writeIndex + 1;
      inputSrc = *(int *)(*(int *)cppGlobalSlot + 0x20);
      exponentValue = exponentValue * 10 + currentChar + -0x30;
      currentChar = (**(code **)(inputSrc + 8))(inputSrc,token,triggerChar,a3,scratchR7,scratchR8,*(int *)cppGlobalSlot);
    } while (currentChar - 0x30U < 10);
  }
  else {
    _CPPErrorToInfoLog("ERROR___ERROR_IN_EXPONENT",scratchR4,triggerChar,a3,scratchR7,scratchR8,scratchR9);
  }
  exponentValue = exponentValue * exponentSign;
LAB_97b88e60:
  if (writeIndex == 0) {
    *lexemeBuf = 0x302e3000;
    floatValue = 0.0;
  }
  else {
    *(undefined1 *)((int)lexemeBuf + writeIndex) = 0;
    lBuildFloatValueResult = (double)((double (*)())_lBuildFloatValue)(lexemeBuf,mantissaLength,exponentValue - fractionDigitCount);
    floatValue = (float)lBuildFloatValueResult;
  }
  *(float *)(token + 4) = floatValue;
  _strcpy(token + 0xc,lexemeBuf);
  ungetSrc = *(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20);
  (**(code **)(ungetSrc + 0xc))(ungetSrc,currentChar,token,a3,scratchR7,scratchR8,*(int *)PTR__cpp_a7b7c0a4);
  return 0x10b;
}

/* _byte_scan @ 0x97b88ee4 (3060 bytes) */
int _byte_scan(unusedArg1, token, scratchR5, scratchR6, scratchR7, scratchR8)
  undefined4 unusedArg1;
  uint *token;
  undefined4 scratchR5;
  undefined4 scratchR6;
  undefined4 scratchR7;
  undefined4 scratchR8;
{
  uint lookUpAddStringResult;
  int result;
  int loopIndex;
  bool overflowReported;
  char digitChar;
  int charOrTokenCode;
  int a1;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  undefined4 extraout_r4_02;
  undefined4 extraout_r4_03;
  undefined4 extraout_r4_04;
  undefined4 scratchR4;
  undefined4 extraout_r4_05;
  undefined4 extraout_r4_06;
  undefined4 extraout_r4_07;
  undefined4 extraout_r4_08;
  undefined4 extraout_r4_09;
  undefined4 extraout_r4_10;
  uint *tokenAlias;
  uint digitValue;
  uint constantValue;
  undefined1 *lexemeCursor;
  int cppContext;
  int lexemeLength;
  uint *digitCursor;
  undefined1 identifierText [144];
  undefined1 stringLiteralText [536];
  
  constantValue = 0;
  cppContext = *(int *)PTR__cpp_a7b7c0a4;
LAB_97b88f18:
  *token = 0;
  charOrTokenCode = (**(code **)(*(int *)(cppContext + 0x20) + 8))(*(int *)(cppContext + 0x20),token);
  while (((charOrTokenCode == 0x20 || (charOrTokenCode == 9)) || (charOrTokenCode == 0xd))) {
    *token = 1;
    charOrTokenCode = (**(code **)(*(int *)(cppContext + 0x20) + 8))(*(int *)(cppContext + 0x20),token);
  }
  if (charOrTokenCode != -1) {
    *(undefined2 *)(cppContext + 0x30) = *(undefined2 *)(*(int *)(cppContext + 0x20) + 0x12);
    *(undefined2 *)(cppContext + 0x32) = *(undefined2 *)(*(int *)(cppContext + 0x20) + 0x16);
  }
  lexemeLength = 0;
  if (0x7d < charOrTokenCode + 1U) {
LAB_97b89cb4:
    return charOrTokenCode;
  }
  digitValue = (charOrTokenCode + 1U) * 4;
  switch(charOrTokenCode) {
  case 0:
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
  case 9:
  case 10:
  case 0xb:
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
  case 0x10:
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x14:
  case 0x15:
  case 0x16:
  case 0x17:
  case 0x18:
  case 0x19:
  case 0x1a:
  case 0x1b:
  case 0x1c:
  case 0x1d:
  case 0x1e:
  case 0x1f:
  case 0x20:
  case 0x23:
  case 0x24:
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2c:
  case 0x3b:
  case 0x3f:
  case 0x40:
  case 0x5b:
  case 0x5c:
  case 0x5d:
  case 0x60:
  case 0x7b:
    goto LAB_97b89cb4;
  case 0x21:
    charOrTokenCode = (**(code **)(*(int *)(cppContext + 0x20) + 8))(*(int *)(cppContext + 0x20),token);
    if (charOrTokenCode != 0x3d) {
      (**(code **)(*(int *)(cppContext + 0x20) + 0xc))(*(int *)(cppContext + 0x20),charOrTokenCode,token);
      return 0x21;
    }
    return 0x113;
  case 0x22:
    charOrTokenCode = (**(code **)(*(int *)(cppContext + 0x20) + 8))(*(int *)(cppContext + 0x20),token);
    overflowReported = charOrTokenCode == 0x22;
    scratchR4 = extraout_r4_08;
    if (((overflowReported) || (charOrTokenCode == 10)) || (charOrTokenCode == -1)) goto LAB_97b89c74;
    lexemeCursor = stringLiteralText;
    goto LAB_97b89bf4;
  case 0x25:
    charOrTokenCode = (**(code **)(*(int *)(cppContext + 0x20) + 8))(*(int *)(cppContext + 0x20),token);
    if (charOrTokenCode == 0x3d) {
      return 0x104;
    }
    if (charOrTokenCode != 0x3e) {
      (**(code **)(*(int *)(cppContext + 0x20) + 0xc))(*(int *)(cppContext + 0x20),charOrTokenCode,token);
      return 0x25;
    }
    return 0x120;
  case 0x26:
    charOrTokenCode = (**(code **)(*(int *)(cppContext + 0x20) + 8))(*(int *)(cppContext + 0x20),token);
    if (charOrTokenCode == 0x26) {
      return 0x101;
    }
    if (charOrTokenCode != 0x3d) {
      (**(code **)(*(int *)(cppContext + 0x20) + 0xc))(*(int *)(cppContext + 0x20),charOrTokenCode,token);
      return 0x26;
    }
    return 0x11a;
  case 0x2a:
    charOrTokenCode = (**(code **)(*(int *)(cppContext + 0x20) + 8))(*(int *)(cppContext + 0x20),token);
    if (charOrTokenCode != 0x3d) {
      (**(code **)(*(int *)(cppContext + 0x20) + 0xc))(*(int *)(cppContext + 0x20),charOrTokenCode,token);
      return 0x2a;
    }
    return 0x107;
  case 0x2b:
    charOrTokenCode = (**(code **)(*(int *)(cppContext + 0x20) + 8))(*(int *)(cppContext + 0x20),token);
    if (charOrTokenCode == 0x2b) {
      return 0x115;
    }
    if (charOrTokenCode != 0x3d) {
      (**(code **)(*(int *)(cppContext + 0x20) + 0xc))(*(int *)(cppContext + 0x20),charOrTokenCode,token);
      return 0x2b;
    }
    return 0x105;
  case 0x2d:
    charOrTokenCode = (**(code **)(*(int *)(cppContext + 0x20) + 8))(*(int *)(cppContext + 0x20),token);
    if (charOrTokenCode == 0x2d) {
      return 0x112;
    }
    if (charOrTokenCode != 0x3d) {
      (**(code **)(*(int *)(cppContext + 0x20) + 0xc))(*(int *)(cppContext + 0x20),charOrTokenCode,token);
      return 0x2d;
    }
    return 0x103;
  case 0x2e:
    charOrTokenCode = (**(code **)(*(int *)(cppContext + 0x20) + 8))(*(int *)(cppContext + 0x20),token);
    if (9 < charOrTokenCode - 0x30U) {
      if (charOrTokenCode != 0x2e) {
        (**(code **)(*(int *)(cppContext + 0x20) + 0xc))(*(int *)(cppContext + 0x20),charOrTokenCode,token);
        return 0x2e;
      }
      return -1;
    }
    (**(code **)(*(int *)(cppContext + 0x20) + 0xc))(*(int *)(cppContext + 0x20),charOrTokenCode,token);
    lexemeLength = 0;
    a1 = 0x2e;
    goto LAB_97b89a54;
  case 0x2f:
    charOrTokenCode = (**(code **)(*(int *)(cppContext + 0x20) + 8))(*(int *)(cppContext + 0x20),token);
    if (charOrTokenCode != 0x2f) break;
    do {
      charOrTokenCode = (**(code **)(*(int *)(cppContext + 0x20) + 8))(*(int *)(cppContext + 0x20),token);
      if (charOrTokenCode == 10) {
        return 10;
      }
    } while (charOrTokenCode != -1);
switchD_97b88fcc_caseD_ffffffff:
    return -1;
  case 0x30:
    *(char *)(token + 3) = (char)charOrTokenCode;
    lexemeLength = 1;
    a1 = (**(code **)(*(int *)(cppContext + 0x20) + 8))(*(int *)(cppContext + 0x20),token);
    if ((a1 == 0x78) || (a1 == 0x58)) {
      *(char *)((int)token + 0xd) = (char)a1;
      lexemeLength = 2;
      a1 = (**(code **)(*(int *)(cppContext + 0x20) + 8))(*(int *)(cppContext + 0x20),token);
      digitValue = a1 - 0x30;
      if ((digitValue < 10) || ((a1 - 0x41U < 6 || (a1 - 0x61U < 6)))) {
        lexemeCursor = (undefined1 *)((int)token + 0xe);
        overflowReported = false;
        constantValue = 0;
        scratchR4 = extraout_r4_00;
        do {
          *lexemeCursor = (char)a1;
          lexemeLength = lexemeLength + 1;
          lexemeCursor = lexemeCursor + 1;
          if ((int)constantValue < 0x10000000) {
            if ((9 < digitValue) && (digitValue = a1 - 0x37, 5 < a1 - 0x41U)) {
              digitValue = a1 - 0x57;
            }
            constantValue = constantValue << 4 | digitValue;
          }
          else {
            if (!overflowReported) {
              _CPPErrorToInfoLog("ERROR___HEX_CONST_OVERFLOW",scratchR4,scratchR5,scratchR6,scratchR7,scratchR8,
                                 digitValue);
            }
            overflowReported = true;
          }
          a1 = (**(code **)(*(int *)(cppContext + 0x20) + 8))(*(int *)(cppContext + 0x20),token);
          digitValue = a1 - 0x30;
          scratchR4 = extraout_r4_01;
        } while (((digitValue < 10) || (a1 - 0x41U < 6)) || (a1 - 0x61U < 6));
      }
      else {
        _CPPErrorToInfoLog("ERROR___ERROR_IN_HEX_CONSTANT",extraout_r4_00,scratchR5,scratchR6,scratchR7,
                           scratchR8,digitValue);
      }
      goto LAB_97b89458;
    }
    digitValue = a1 - 0x30;
    if (digitValue < 8) {
      overflowReported = false;
      constantValue = 0;
      lexemeCursor = (undefined1 *)((int)token + 0xd);
      scratchR4 = extraout_r4;
      do {
        *lexemeCursor = (char)a1;
        lexemeLength = lexemeLength + 1;
        lexemeCursor = lexemeCursor + 1;
        if ((int)constantValue < 0x20000000) {
          constantValue = constantValue << 3 | digitValue;
        }
        else {
          if (!overflowReported) {
            _CPPErrorToInfoLog("ERROR___OCT_CONST_OVERFLOW",scratchR4,scratchR5,scratchR6,scratchR7,scratchR8,
                               digitValue);
          }
          overflowReported = true;
        }
        a1 = (**(code **)(*(int *)(cppContext + 0x20) + 8))(*(int *)(cppContext + 0x20),token);
        digitValue = a1 - 0x30;
        scratchR4 = extraout_r4_02;
      } while (digitValue < 8);
      if ((((a1 == 0x2e) || (a1 == 0x65)) || ((a1 == 0x66 || ((a1 == 0x68 || (a1 == 0x78)))))) ||
         (a1 == 0x45)) goto LAB_97b89a54;
LAB_97b89458:
      *(undefined1 *)((int)token + lexemeLength + 0xc) = 0;
      (**(code **)(*(int *)(cppContext + 0x20) + 0xc))(*(int *)(cppContext + 0x20),a1,token);
      *token = constantValue;
      return 0x10f;
    }
    charOrTokenCode = 0x30;
    (**(code **)(*(int *)(cppContext + 0x20) + 0xc))(*(int *)(cppContext + 0x20),a1,token);
switchD_97b88fcc_caseD_31:
    lexemeCursor = (undefined1 *)((int)token + lexemeLength + 0xc);
    a1 = charOrTokenCode;
    do {
      if (lexemeLength < 0x80) {
        if ((0 < lexemeLength) || (a1 != 0x30)) {
          *lexemeCursor = (char)a1;
          lexemeLength = lexemeLength + 1;
          lexemeCursor = lexemeCursor + 1;
        }
        a1 = (**(code **)(*(int *)(cppContext + 0x20) + 8))(*(int *)(cppContext + 0x20),token);
      }
    } while (a1 - 0x30U < 10);
    if (((((a1 != 0x2e) && (a1 != 0x65)) && (a1 != 0x66)) && ((a1 != 0x68 && (a1 != 0x78)))) &&
       (a1 != 0x45)) {
      *(undefined1 *)((int)token + lexemeLength + 0xc) = 0;
      constantValue = 0;
      overflowReported = false;
      tokenAlias = token;
      (**(code **)(*(int *)(cppContext + 0x20) + 0xc))(*(int *)(cppContext + 0x20),a1,token,scratchR6);
      if (0 < lexemeLength) {
        digitCursor = token + 3;
        scratchR4 = extraout_r4_03;
        do {
          digitChar = *(char *)digitCursor;
          digitCursor = (uint *)((int)digitCursor + 1);
          if ((0xccccccc < (int)constantValue) || ((constantValue == 0xccccccc && (7 < digitChar + -0x30)))) {
            if (!overflowReported) {
              _CPPErrorToInfoLog("ERROR___INTEGER_CONST_OVERFLOW",scratchR4,tokenAlias,scratchR6,scratchR7,
                                 scratchR8,digitValue);
              scratchR4 = extraout_r4_04;
            }
            overflowReported = true;
          }
          lexemeLength = lexemeLength + -1;
          constantValue = constantValue * 10 + digitChar + -0x30;
        } while (lexemeLength != 0);
      }
      *token = constantValue;
      if (constantValue == 0) {
        *(undefined2 *)(token + 3) = 0x3000;
      }
      return 0x10f;
    }
LAB_97b89a54:
    result = ((int (*)())_lFloatConst)(token + 3,lexemeLength,a1,token);
    return result;
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
    charOrTokenCode = (**(code **)(*(int *)(cppContext + 0x20) + 8))(*(int *)(cppContext + 0x20),token);
    if (charOrTokenCode != 0x3e) {
      (**(code **)(*(int *)(cppContext + 0x20) + 0xc))(*(int *)(cppContext + 0x20),charOrTokenCode,token);
      return 0x3a;
    }
    return 0x11e;
  case 0x3c:
    charOrTokenCode = (**(code **)(*(int *)(cppContext + 0x20) + 8))(*(int *)(cppContext + 0x20),token);
    if (charOrTokenCode == 0x3c) {
      charOrTokenCode = (**(code **)(*(int *)(cppContext + 0x20) + 8))(*(int *)(cppContext + 0x20),token);
      if (charOrTokenCode != 0x3d) {
        (**(code **)(*(int *)(cppContext + 0x20) + 0xc))(*(int *)(cppContext + 0x20),charOrTokenCode,token);
        return 0x111;
      }
      return 0x119;
    }
    if (charOrTokenCode == 0x3d) {
      return 0x110;
    }
    if (charOrTokenCode == 0x25) {
      return 0x11f;
    }
    if (charOrTokenCode != 0x3a) {
      (**(code **)(*(int *)(cppContext + 0x20) + 0xc))(*(int *)(cppContext + 0x20),charOrTokenCode,token);
      return 0x3c;
    }
    return 0x11d;
  case 0x3d:
    charOrTokenCode = (**(code **)(*(int *)(cppContext + 0x20) + 8))(*(int *)(cppContext + 0x20),token);
    if (charOrTokenCode != 0x3d) {
      (**(code **)(*(int *)(cppContext + 0x20) + 0xc))(*(int *)(cppContext + 0x20),charOrTokenCode,token);
      return 0x3d;
    }
    return 0x108;
  case 0x3e:
    charOrTokenCode = (**(code **)(*(int *)(cppContext + 0x20) + 8))(*(int *)(cppContext + 0x20),token);
    if (charOrTokenCode != 0x3e) {
      if (charOrTokenCode != 0x3d) {
        (**(code **)(*(int *)(cppContext + 0x20) + 0xc))(*(int *)(cppContext + 0x20),charOrTokenCode,token);
        return 0x3e;
      }
      return 0x10c;
    }
    charOrTokenCode = (**(code **)(*(int *)(cppContext + 0x20) + 8))(*(int *)(cppContext + 0x20),token);
    if (charOrTokenCode != 0x3d) {
      (**(code **)(*(int *)(cppContext + 0x20) + 0xc))(*(int *)(cppContext + 0x20),charOrTokenCode,token);
      return 0x10d;
    }
    return 0x118;
  default:
    overflowReported = false;
    do {
      if (!overflowReported) {
        identifierText[lexemeLength] = (char)charOrTokenCode;
        lexemeLength = lexemeLength + 1;
        overflowReported = 0x7f < lexemeLength;
      }
      charOrTokenCode = (**(code **)(*(int *)(cppContext + 0x20) + 8))
                        (*(int *)(cppContext + 0x20),token,scratchR5,scratchR6,scratchR7,scratchR8,digitValue);
    } while (((charOrTokenCode - 0x61U < 0x1a) || (charOrTokenCode - 0x41U < 0x1a)) ||
            ((charOrTokenCode - 0x30U < 10 || (charOrTokenCode == 0x5f))));
    if (overflowReported) {
      lexemeLength = 0x7f;
    }
    identifierText[lexemeLength] = 0;
    (**(code **)(*(int *)(cppContext + 0x20) + 0xc))(*(int *)(cppContext + 0x20),charOrTokenCode,token);
    lookUpAddStringResult = _LookUpAddString(*(undefined4 *)PTR__atable_a7b7c0ac,identifierText);
    token[2] = lookUpAddStringResult;
    return 0x10e;
  case 0x5e:
    charOrTokenCode = (**(code **)(*(int *)(cppContext + 0x20) + 8))(*(int *)(cppContext + 0x20),token);
    if (charOrTokenCode == 0x5e) {
      return 0x109;
    }
    if (charOrTokenCode != 0x3d) {
      (**(code **)(*(int *)(cppContext + 0x20) + 0xc))(*(int *)(cppContext + 0x20),charOrTokenCode,token);
      return 0x5e;
    }
    return 0x11c;
  case 0x7c:
    charOrTokenCode = (**(code **)(*(int *)(cppContext + 0x20) + 8))(*(int *)(cppContext + 0x20),token);
    if (charOrTokenCode == 0x7c) {
      return 0x114;
    }
    if (charOrTokenCode != 0x3d) {
      (**(code **)(*(int *)(cppContext + 0x20) + 0xc))(*(int *)(cppContext + 0x20),charOrTokenCode,token);
      return 0x7c;
    }
    return 0x11b;
  case -1:
    goto switchD_97b88fcc_caseD_ffffffff;
  }
  if (charOrTokenCode != 0x2a) {
    if (charOrTokenCode != 0x3d) {
      (**(code **)(*(int *)(cppContext + 0x20) + 0xc))(*(int *)(cppContext + 0x20),charOrTokenCode,token);
      return 0x2f;
    }
    return 0x106;
  }
  loopIndex = 0;
  lexemeLength = (**(code **)(*(int *)(cppContext + 0x20) + 8))(*(int *)(cppContext + 0x20),token);
  scratchR4 = extraout_r4_05;
  do {
    while (lexemeLength != 0x2a) {
      if (lexemeLength == 10) {
        loopIndex = loopIndex + 1;
      }
      if (lexemeLength == -1) {
LAB_97b89b60:
        _CPPErrorToInfoLog("ERROR___EOF_IN_COMMENT",scratchR4,scratchR5,scratchR6,scratchR7,scratchR8,digitValue);
        return -1;
      }
      lexemeLength = (**(code **)(*(int *)(cppContext + 0x20) + 8))(*(int *)(cppContext + 0x20),token);
      scratchR4 = extraout_r4_06;
    }
    lexemeLength = (**(code **)(*(int *)(cppContext + 0x20) + 8))(*(int *)(cppContext + 0x20),token);
    scratchR4 = extraout_r4_07;
    if (lexemeLength == -1) goto LAB_97b89b60;
  } while (lexemeLength != 0x2f);
  if (loopIndex != 0) {
    return 10;
  }
  goto LAB_97b88f18;
LAB_97b89bf4:
  if (charOrTokenCode == 0x5c) {
    charOrTokenCode = (**(code **)(*(int *)(cppContext + 0x20) + 8))(*(int *)(cppContext + 0x20),token);
    overflowReported = charOrTokenCode == 0x22;
    scratchR4 = extraout_r4_09;
    if ((charOrTokenCode == 10) || (charOrTokenCode == -1)) {
LAB_97b89c74:
      stringLiteralText[lexemeLength] = 0;
      if (!overflowReported) {
        _CPPErrorToInfoLog("ERROR___CPP_EOL_IN_STRING",scratchR4,scratchR5,scratchR6,scratchR7,scratchR8,digitValue);
        return 0x10a;
      }
      lookUpAddStringResult = _LookUpAddString(*(undefined4 *)PTR__atable_a7b7c0ac,stringLiteralText);
      token[2] = lookUpAddStringResult;
      return 0x116;
    }
  }
  if (lexemeLength < 0x200) {
    *lexemeCursor = (char)charOrTokenCode;
    lexemeLength = lexemeLength + 1;
    lexemeCursor = lexemeCursor + 1;
    charOrTokenCode = (**(code **)(*(int *)(cppContext + 0x20) + 8))(*(int *)(cppContext + 0x20),token);
    scratchR4 = extraout_r4_10;
  }
  overflowReported = charOrTokenCode == 0x22;
  if (((overflowReported) || (charOrTokenCode == 10)) || (charOrTokenCode == -1)) goto LAB_97b89c74;
  goto LAB_97b89bf4;
}

/* _yylex_CPP @ 0x97b89cd0 (452 bytes) */
int _yylex_CPP(outBuf, maxLengthOrResult)
  undefined4 outBuf;
  int maxLengthOrResult;
{
  int token;
  int macroExpanded;
  undefined4 readCPPlineResult;
  int length;
  undefined *cppGlobalSlot;
  undefined *atomTableSlot;
  int eofAfterDirective;
  int eofFlag;
  undefined4 atomTable;
  char *tokenText;
  undefined4 extraout_r4;
  undefined4 scratchR5;
  undefined4 scratchR6;
  undefined4 scratchR7;
  undefined4 scratchR8;
  undefined4 a6;
  undefined1 auStack_b0 [8];
  int tokenAtom;
  char acStack_a4 [136];
  
  atomTableSlot = PTR__atable_a7b7c0ac;
  cppGlobalSlot = PTR__cpp_a7b7c0a4;
  a6 = 0xa7b79cdc;
  do {
    do {
      while( true ) {
        while( true ) {
          token = (**(code **)(*(int *)(*(int *)cppGlobalSlot + 0x20) + 4))
                            (*(int *)(*(int *)cppGlobalSlot + 0x20),auStack_b0,scratchR5,scratchR6,scratchR7,scratchR8,a6);
          eofFlag = ((int (*)())_check_EOF)(token);
          if (eofFlag != 0) {
            return 0;
          }
          if (token != 0x23) break;
          if ((*(int *)(*(int *)cppGlobalSlot + 0x24) != 10) && (*(int *)(*(int *)cppGlobalSlot + 0x24) != 0)) {
            _CPPErrorToInfoLog("preprocessor command must not be preceded by any other statement in that line"
                               ,extraout_r4,scratchR5,scratchR6,scratchR7,scratchR8,a6);
            return 0;
          }
          readCPPlineResult = _readCPPline(auStack_b0);
          eofAfterDirective = ((int (*)())_check_EOF)(readCPPlineResult);
          if (eofAfterDirective != 0) {
            return 0;
          }
        }
        *(int *)(*(int *)cppGlobalSlot + 0x24) = token;
        if ((token != 0x10e) || (macroExpanded = _MacroExpand(tokenAtom,auStack_b0), macroExpanded == 0)) break;
        *(undefined4 *)(*(int *)cppGlobalSlot + 0x28) = 1;
      }
    } while (token == 10);
    if (token != 0x10e) {
      if ((token != 0x10b) && (token != 0x10f)) {
        *(undefined4 *)(*(int *)cppGlobalSlot + 0x28) = 1;
        atomTable = *(undefined4 *)atomTableSlot;
        goto LAB_97b89e08;
      }
      tokenText = acStack_a4;
      *(undefined4 *)(*(int *)cppGlobalSlot + 0x28) = 1;
    }
    else {
      *(undefined4 *)(*(int *)cppGlobalSlot + 0x28) = 1;
      atomTable = *(undefined4 *)atomTableSlot;
      token = tokenAtom;
LAB_97b89e08:
      tokenText = (char *)_GetStringOfAtom(atomTable,token);
    }
    if (tokenText != (char *)0x0) {
      length = _strlen(tokenText);
      if (length < maxLengthOrResult) {
        maxLengthOrResult = 0;
        if (*tokenText != '\0') {
          _strcpy(outBuf,tokenText);
          *(uint *)(*(int *)cppGlobalSlot + 0x154) = *(uint *)(*(int *)cppGlobalSlot + 0x154) | 0x80000000;
          maxLengthOrResult = _strlen(tokenText);
        }
      }
      else {
        *(uint *)(*(int *)cppGlobalSlot + 0x154) = *(uint *)(*(int *)cppGlobalSlot + 0x154) | 0x80000000;
      }
      return maxLengthOrResult;
    }
  } while( true );
}

/* _check_EOF @ 0x97b89e94 (108 bytes) */
int _check_EOF(token)
  int token;
{
  undefined *cppGlobalSlot;
  undefined4 isEof;
  undefined4 scratchR4;
  undefined4 scratchR5;
  undefined4 scratchR6;
  undefined4 scratchR7;
  undefined4 scratchR8;
  undefined4 scratchR9;
  
  cppGlobalSlot = PTR__cpp_a7b7c0a4;
  isEof = 0;
  if (token == -1) {
    if (0 < *(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x34)) {
      _CPPErrorToInfoLog("#endif missing!! Compilation stopped",scratchR4,scratchR5,scratchR6,scratchR7,scratchR8,scratchR9)
      ;
      *(undefined4 *)(*(int *)cppGlobalSlot + 0x140) = 1;
    }
    isEof = 1;
  }
  return isEof;
}

/* FUN_97b89f04 @ 0x97b89f04 (72 bytes) */
int FUN_97b89f04(scope)
  undefined4 *scope;
{
  int unaff_r2 = (int)*scope;   /* set by the entry _unlinkScope: lwz r2,0(r3) */
  
  if (unaff_r2 != 0) {
    *(undefined4 *)(unaff_r2 + 4) = scope[1];
  }
  if ((undefined4 *)scope[1] != (undefined4 *)0x0) {
    *(undefined4 *)scope[1] = *scope;
    return;
  }
  _ScopeList = *scope;
  return;
}

/* _NewScopeInPool @ 0x97b89f4c (152 bytes) */
int _NewScopeInPool(pool)
  int pool;
{
  bool hadScopeList;
  int *scope;
  
  scope = (int *)_mem_Alloc(pool,0x20);
  scope[4] = pool;
  scope[2] = 0;
  scope[3] = 0;
  scope[5] = 0;
  scope[6] = 0;
  scope[7] = 0;
  hadScopeList = _ScopeList != (int *)0x0;
  *scope = (int)_ScopeList;
  if (hadScopeList) {
    *(int **)((int)_ScopeList + 4) = scope;
  }
  scope[1] = 0;
  _ScopeList = scope;
  _mem_AddCleanup(pool,DAT_a7b7b048,scope);
  return scope;
}

/* _PushScope @ 0x97b89fe4 (148 bytes) */
int _PushScope(scope)
  int *scope;
{
  int *ancestorCursor;
  int level;
  
  if (_CurrentScope == (int *)0x0) {
    scope[6] = 0;
  }
  else {
    level = *(int *)((int)_CurrentScope + 0x18) + 1;
    scope[6] = level;
    if ((level == 1) && (_GlobalScope == 0)) {
      scope[6] = 2;
    }
    level = scope[6];
    ancestorCursor = scope;
    if (1 < level) {
      while (2 < level) {
        level = ((int *)*ancestorCursor)[6];
        ancestorCursor = (int *)*ancestorCursor;
      }
      scope[3] = (int)ancestorCursor;
    }
  }
  scope[2] = (int)_CurrentScope;
  _CurrentScope = scope;
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
int _NewSymbol(loc, scope, name, kind)
  undefined4 *loc;
  int scope;
  undefined4 name;
  undefined4 kind;
{
  undefined4 locWord;
  undefined4 *detailsCursor;
  undefined4 *symbol;
  int bytesLeft;
  
  symbol = (undefined4 *)_mem_Alloc(*(undefined4 *)(scope + 0x10),0x28);
  symbol[2] = 0;
  symbol[3] = name;
  bytesLeft = 0x10;
  *symbol = 0;
  symbol[1] = 0;
  locWord = *loc;
  symbol[5] = kind;
  symbol[4] = locWord;
  detailsCursor = symbol + 6;
  do {
    *(undefined1 *)detailsCursor = 0;
    detailsCursor = (undefined4 *)((int)detailsCursor + 1);
    bytesLeft = bytesLeft + -1;
  } while (bytesLeft != 0);
  return symbol;
}

/* _lAddToTree @ 0x97b8a11c (188 bytes) */
int _lAddToTree(treeRoot, newSymbol)
  int *treeRoot;
  int newSymbol;
{
  undefined *atomTableSlot;
  int *child;
  int reversedAtom;
  int nodeReversedAtom;
  undefined4 scratchR5;
  undefined4 scratchR6;
  undefined4 scratchR7;
  undefined4 scratchR8;
  undefined4 scratchR9;
  int *node;
  undefined8 reversedAtom2;
  
  atomTableSlot = PTR__atable_a7b7c0ac;
  node = (int *)*treeRoot;
  if (node == (int *)0x0) {
    *treeRoot = newSymbol;
  }
  else {
    reversedAtom = _GetReversedAtom(*(undefined4 *)PTR__atable_a7b7c0ac,*(undefined4 *)(newSymbol + 0xc));
    do {
      reversedAtom2 = _GetReversedAtom(*(undefined4 *)atomTableSlot,node[3]);
      nodeReversedAtom = (int)((ulonglong)reversedAtom2 >> 0x20);
      if (nodeReversedAtom == reversedAtom) {
        _CPPErrorToInfoLog("GetAtomString(atable, fSymb->name)",(int)reversedAtom2,scratchR5,scratchR6,scratchR7,scratchR8,
                           scratchR9);
        return;
      }
      if (reversedAtom < nodeReversedAtom) {
        child = (int *)*node;
        if (child == (int *)0x0) {
          *node = newSymbol;
          return;
        }
      }
      else {
        child = (int *)node[1];
        if (child == (int *)0x0) {
          node[1] = newSymbol;
          return;
        }
      }
      node = child;
    } while (child != (int *)0x0);
  }
  return;
}

/* _AddSymbol @ 0x97b8a1d8 (88 bytes) */
int _AddSymbol(loc, scope, name, kind)
  undefined4 loc;
  int scope;
  undefined4 name;
  undefined4 kind;
{
  undefined4 newSymbolResult;
  
  if (scope == 0) {
    scope = _CurrentScope;
  }
  newSymbolResult = ((int (*)())_NewSymbol)(loc,scope,name,kind);
  ((int (*)())_lAddToTree)(scope + 0x14,newSymbolResult);
  return newSymbolResult;
}

/* _LookUpLocalSymbol @ 0x97b8a230 (148 bytes) */
int _LookUpLocalSymbol(scope, name)
  int scope;
  undefined4 name;
{
  undefined *atomTableSlot;
  int reversedAtom;
  int reversedAtom2;
  int *symbol;
  
  atomTableSlot = PTR__atable_a7b7c0ac;
  reversedAtom = _GetReversedAtom(*(undefined4 *)PTR__atable_a7b7c0ac,name);
  if (scope == 0) {
    scope = _CurrentScope;
  }
  symbol = *(int **)(scope + 0x14);
  while( true ) {
    if (symbol == (int *)0x0) {
      return 0;
    }
    reversedAtom2 = _GetReversedAtom(*(undefined4 *)atomTableSlot,symbol[3]);
    if (reversedAtom2 == reversedAtom) break;
    if (reversedAtom < reversedAtom2) {
      symbol = (int *)*symbol;
    }
    else {
      symbol = (int *)symbol[1];
    }
  }
  return (int)symbol;
}

/* _LookUpSymbol @ 0x97b8a2c4 (108 bytes) */
int _LookUpSymbol(scope, name)
  int scope;
  undefined4 name;
{
  int symbol;
  int nextScope;
  
  nextScope = _CurrentScope;
  if (scope != 0) goto LAB_97b8a2f8;
  while( true ) {
    scope = nextScope;
    if (scope == 0) {
      return 0;
    }
LAB_97b8a2f8:
    symbol = ((int (*)())_LookUpLocalSymbol)(scope,name);
    if (symbol != 0) break;
    nextScope = *(int *)(scope + 8);
  }
  return symbol;
}

/* _idstr @ 0x97b8a330 (248 bytes) */
int _idstr(srcCursor, pool)
  byte *srcCursor;
  int pool;
{
  uint isAlnum;
  int length;
  byte ch;
  undefined *runeLocale;
  int maskruneResult;
  byte *copy;
  uint charCode;
  byte *dstCursor;
  
  length = _strlen(srcCursor);
  if (pool == 0) {
    copy = (byte *)_malloc(length + 1);
  }
  else {
    copy = (byte *)_mem_Alloc(pool,length + 1);
  }
  runeLocale = PTR_DAT_a7b7c0a8;
  ch = *srcCursor;
  dstCursor = copy;
  do {
    if (ch == 0) {
      *dstCursor = 0;
      return copy;
    }
    charCode = (uint)(char)ch;
    if ((charCode & 0xffffff80) == 0) {
      isAlnum = -(uint)(*(uint *)(runeLocale + charCode * 4 + 0x34) & 0x500) >> 0x1f;
    }
    else {
      maskruneResult = ___maskrune(charCode,0x500);
      isAlnum = (uint)(maskruneResult != 0);
    }
    if (isAlnum == 0) {
      if (*srcCursor - 0x2e < 2) {
        *dstCursor = 0x5f;
        goto LAB_97b8a3f8;
      }
    }
    else {
      *dstCursor = *srcCursor;
LAB_97b8a3f8:
      dstCursor = dstCursor + 1;
    }
    srcCursor = srcCursor + 1;
    ch = *srcCursor;
  } while( true );
}

/* _lNewBlock @ 0x97b8a428 (136 bytes) */
int _lNewBlock(ts, pool)
  int ts;
  int pool;
{
  undefined4 *block;
  
  if (pool == 0) {
    block = (undefined4 *)_malloc(0x114);
  }
  else {
    block = (undefined4 *)_mem_Alloc(pool,0x114);
  }
  block[4] = block + 5;
  block[3] = 0x100;
  *block = 0;
  block[2] = 0;
  block[1] = 0;
  if (*(int *)(ts + 8) == 0) {
    *(undefined4 **)(ts + 8) = block;
  }
  else {
    **(undefined4 **)(ts + 0xc) = block;
  }
  *(undefined4 **)(ts + 0xc) = block;
  return block;
}

/* _lAddByte @ 0x97b8a4b0 (92 bytes) */
int _lAddByte(ts, byteValue)
  int ts;
  undefined4 byteValue;
{
  int writeIndex;
  int block;
  
  block = *(int *)(ts + 0xc);
  writeIndex = *(int *)(block + 8);
  if (*(int *)(block + 0xc) <= writeIndex) {
    block = ((int (*)())_lNewBlock)(ts,0);
    writeIndex = *(int *)(block + 8);
  }
  *(undefined1 *)(*(int *)(block + 0x10) + writeIndex) = (undefined1)byteValue;
  *(int *)(block + 8) = writeIndex + 1;
  return;
}

/* _lReadByte @ 0x97b8a50c (88 bytes) */
int _lReadByte(ts)
  int ts;
{
  bool noBlock;
  uint byteValue;
  int *block;
  
  block = *(int **)(ts + 0xc);
  byteValue = 0xffffffff;
  noBlock = block == (int *)0x0;
  if (!noBlock) {
    if (block[2] <= block[1]) {
      block = (int *)*block;
      noBlock = block == (int *)0x0;
      if (!noBlock) {
        block[1] = 0;
      }
      *(int **)(ts + 0xc) = block;
    }
    if (!noBlock) {
      byteValue = (uint)*(byte *)(block[4] + block[1]);
      block[1] = block[1] + 1;
    }
  }
  return byteValue;
}

/* _NewTokenStream @ 0x97b8a564 (124 bytes) */
int _NewTokenStream(name, pool)
  undefined4 name;
  int pool;
{
  undefined4 *ts;
  undefined4 idstrResult;
  
  if (pool == 0) {
    ts = (undefined4 *)_malloc(0x10);
  }
  else {
    ts = (undefined4 *)_mem_Alloc(pool,0x10);
  }
  *ts = 0;
  idstrResult = ((int (*)())_idstr)(name,pool);
  ts[3] = 0;
  ts[1] = idstrResult;
  ts[2] = 0;
  ((int (*)())_lNewBlock)(ts,pool);
  return ts;
}

/* _DeleteTokenStream @ 0x97b8a5e0 (116 bytes) */
int _DeleteTokenStream(ts)
  int ts;
{
  int *block;
  int nextBlock;
  
  if (ts == 0) {
    return;
  }
  block = (int *)*(int *)(ts + 8);
  while (block != (int *)0x0) {
    nextBlock = *block;
    _free(block);
    block = (int *)nextBlock;
  }
  if (*(int *)(ts + 4) != 0) {
    _free(*(int *)(ts + 4));
  }
  _free(ts);
  return;
}

/* _RecordToken @ 0x97b8a654 (292 bytes) */
int _RecordToken(ts, token, yylvalpp)
  undefined4 ts;
  uint token;
  int *yylvalpp;
{
  byte ch;
  uint tokenByte;
  byte *textCursor;
  
  if ((int)token < 0x101) {
    tokenByte = token & 0x7f;
  }
  else {
    tokenByte = (token & 0x7f) - 0x80 & 0xff;
  }
  ((int (*)())_lAddByte)(ts,tokenByte);
  if (token == 0x10e) {
LAB_97b8a6cc:
    textCursor = (byte *)_GetAtomString(*(undefined4 *)PTR__atable_a7b7c0ac,yylvalpp[2]);
    ch = *textCursor;
    while (ch != 0) {
      ((int (*)())_lAddByte)(ts,(uint)ch);
      textCursor = textCursor + 1;
      ch = *textCursor;
    }
  }
  else {
    if ((int)token < 0x10f) {
      if (token == 0x28) {
        ((int (*)())_lAddByte)(ts,(uint)(*yylvalpp != 0));
        return;
      }
      if (token != 0x10b) {
        return;
      }
    }
    else if (token != 0x10f) {
      if (1 < token - 0x116) {
        return;
      }
      goto LAB_97b8a6cc;
    }
    textCursor = (byte *)(yylvalpp + 3);
    ch = *(byte *)(yylvalpp + 3);
    while (ch != 0) {
      ((int (*)())_lAddByte)(ts,(uint)ch);
      textCursor = textCursor + 1;
      ch = *textCursor;
    }
  }
  ((int (*)())_lAddByte)(ts,0);
  return;
}

/* _RewindTokenStream @ 0x97b8a778 (28 bytes) */
int _RewindTokenStream(ts)
  int ts;
{
  int head;
  
  head = *(int *)(ts + 8);
  if (head == 0) {
    return;
  }
  *(int *)(ts + 0xc) = head;
  *(undefined4 *)(head + 4) = 0;
  return;
}

/* _ReadToken @ 0x97b8a794 (888 bytes) */
int _ReadToken(ts, yylvalpp)
  undefined4 ts;
  undefined4 *yylvalpp;
{
  undefined4 ival;
  undefined4 lookUpAddStringResult;
  undefined4 byteValue;
  int loopIndex2;
  uint charOffset;
  int token;
  undefined4 assertLine;
  int ch;
  char *stringCursor;
  int loopIndex;
  double glp_strtodResult;
  undefined1 lexemeBuf [144];
  char stringLiteralBuf [532];
  
  token = ((int (*)())_lReadByte)(ts);
  if (token < 0) {
    return -1;
  }
  if (0x7f < token) {
    token = token + 0x80;
  }
  if (token == 0x10e) {
LAB_97b8a810:
    loopIndex = 0;
    byteValue = ((int (*)())_lReadByte)(ts);
    ch = (int)(char)byteValue;
    charOffset = ch - 0x61;
    while (((((charOffset & 0xff) < 0x1a || (ch - 0x41U < 0x1a)) || (ch - 0x30U < 10)) ||
           (ch == 0x5f))) {
      if (loopIndex < 0x80) {
        lexemeBuf[loopIndex] = (char)ch;
        byteValue = ((int (*)())_lReadByte)(ts);
        loopIndex = loopIndex + 1;
        ch = (int)(char)byteValue;
        charOffset = ch - 0x61;
      }
    }
    lexemeBuf[loopIndex] = 0;
    if (ch == 0) {
      lookUpAddStringResult = _LookUpAddString(*(undefined4 *)PTR__atable_a7b7c0ac,lexemeBuf);
      yylvalpp[2] = lookUpAddStringResult;
      return 0x10e;
    }
    assertLine = 0x140;
LAB_97b8aac8:
    ___eprintf("%s:%u: failed assertion `%s\'\n",
               "/SourceCache/OpenGL/OpenGL-4.7.14/GLProgrammability/glslang/MachineIndependent/preprocessor/tokens.c"
               ,assertLine,"ch == \'\\0\'");
  }
  else {
    if (token < 0x10f) {
      if (token == 0x28) {
        ival = ((int (*)())_lReadByte)(ts);
        goto LAB_97b8aaf0;
      }
      if (token != 0x10b) {
        return token;
      }
      loopIndex = 0;
      byteValue = ((int (*)())_lReadByte)(ts);
      ch = (int)(char)byteValue;
      charOffset = ch - 0x30;
      while (((((charOffset & 0xff) < 10 || (ch == 0x65)) ||
              ((ch == 0x45 || ((ch == 0x2e || (ch == 0x2b)))))) || (ch == 0x2d))) {
        if (loopIndex < 0x80) {
          lexemeBuf[loopIndex] = (char)ch;
          byteValue = ((int (*)())_lReadByte)(ts);
          loopIndex = loopIndex + 1;
          ch = (int)(char)byteValue;
          charOffset = ch - 0x30;
        }
      }
      lexemeBuf[loopIndex] = 0;
      if (ch == 0) {
        _strcpy(yylvalpp + 3,lexemeBuf);
        glp_strtodResult = (double)((double (*)())_glp_strtod)(yylvalpp + 3,0);
        yylvalpp[1] = (float)glp_strtodResult;
        return 0x10b;
      }
      assertLine = 0x158;
      goto LAB_97b8aac8;
    }
    if (token == 0x116) {
      loopIndex2 = 0;
      stringCursor = stringLiteralBuf;
      while( true ) {
        byteValue = ((int (*)())_lReadByte)(ts);
        if ((char)byteValue == '\0') break;
        if (loopIndex2 < 0x200) {
          *stringCursor = (char)byteValue;
          loopIndex2 = loopIndex2 + 1;
          stringCursor = stringCursor + 1;
        }
      }
      stringLiteralBuf[loopIndex2] = '\0';
      lookUpAddStringResult = _LookUpAddString(*(undefined4 *)PTR__atable_a7b7c0ac,stringLiteralBuf);
      yylvalpp[2] = lookUpAddStringResult;
      return 0x116;
    }
    if (0x116 < token) {
      if (token != 0x117) {
        return token;
      }
      goto LAB_97b8a810;
    }
    if (token != 0x10f) {
      return token;
    }
    loopIndex = 0;
    byteValue = ((int (*)())_lReadByte)(ts);
    ch = (int)(char)byteValue;
    charOffset = ch - 0x30;
    while ((charOffset & 0xff) < 10) {
      if (loopIndex < 0x80) {
        lexemeBuf[loopIndex] = (char)ch;
        byteValue = ((int (*)())_lReadByte)(ts);
        loopIndex = loopIndex + 1;
        ch = (int)(char)byteValue;
        charOffset = ch - 0x30;
      }
    }
    lexemeBuf[loopIndex] = 0;
    if (ch != 0) {
      assertLine = 0x168;
      goto LAB_97b8aac8;
    }
  }
  _strcpy(yylvalpp + 3,lexemeBuf);
  ival = _atoi(yylvalpp + 3);
LAB_97b8aaf0:
  *yylvalpp = ival;
  return token;
}

/* _scan_token @ 0x97b8ab0c (248 bytes) */
int _scan_token(in, yylvalpp, scratchR5, scratchR6, scratchR7, scratchR8)
  undefined4 *in;
  undefined4 yylvalpp;
  undefined4 scratchR5;
  undefined4 scratchR6;
  undefined4 scratchR7;
  undefined4 scratchR8;
{
  int token;
  int inputSrc;
  undefined *cppGlobalSlot;
  int finalResult;
  code *finalFn;
  
  token = ((int (*)())_ReadToken)(in[6],yylvalpp);
  cppGlobalSlot = PTR__cpp_a7b7c0a4;
  **(undefined2 **)(*(int *)PTR__cpp_a7b7c0a4 + 0x18) =
       *(undefined2 *)(*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20) + 0x12);
  *(undefined2 *)(*(int *)(*(int *)cppGlobalSlot + 0x18) + 2) =
       *(undefined2 *)(*(int *)(*(int *)cppGlobalSlot + 0x20) + 0x16);
  if (token == 10) {
    token = 10;
    in[5] = in[5] + 1;
  }
  else if (token < 1) {
    *(undefined4 *)(*(int *)cppGlobalSlot + 0x20) = *in;
    finalFn = (code *)in[7];
    _free(in);
    if ((finalFn != (code *)0x0) && (finalResult = (*finalFn)(*(undefined4 *)cppGlobalSlot), finalResult == 0)) {
      return -1;
    }
    inputSrc = *(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20);
                    
                    
    token = (**(code **)(inputSrc + 4))
                      (inputSrc,yylvalpp,scratchR5,scratchR6,scratchR7,scratchR8,*(int *)PTR__cpp_a7b7c0a4);
    return token;
  }
  return token;
}

/* _ReadFromTokenStream @ 0x97b8ac04 (172 bytes) */
int _ReadFromTokenStream(ts, name, finalFn)
  undefined4 ts;
  undefined4 name;
  undefined4 finalFn;
{
  undefined4 scanFn;
  undefined *cppGlobalSlot;
  int cppState;
  undefined4 *allocation;
  undefined4 prevInput;
  
  allocation = (undefined4 *)_malloc(0x20);
  cppGlobalSlot = PTR__cpp_a7b7c0a4;
  cppState = *(int *)PTR__cpp_a7b7c0a4;
  allocation[7] = 0;
  *allocation = 0;
  allocation[1] = 0;
  allocation[5] = 0;
  allocation[6] = 0;
  allocation[2] = 0;
  allocation[3] = 0;
  allocation[4] = name;
  scanFn = DAT_a7b7b050;
  prevInput = *(undefined4 *)(cppState + 0x20);
  allocation[5] = 1;
  allocation[1] = scanFn;
  *allocation = prevInput;
  allocation[7] = finalFn;
  allocation[6] = ts;
  ((int (*)())_RewindTokenStream)(ts);
  *(undefined4 **)(*(int *)cppGlobalSlot + 0x20) = allocation;
  return 1;
}

/* FUN_97b8acb4 @ 0x97b8acb4 (96 bytes) */
int FUN_97b8acb4(in, yylvalpp)
  undefined4 *in;
  undefined4 yylvalpp;
{
  undefined4 token;
  
  token = in[6];
  _memcpy(yylvalpp,in + 7,0x90);
  *(undefined4 *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20) = *in;
  _free(in);
  return token;
}

/* _UngetToken @ 0x97b8ad14 (156 bytes) */
int _UngetToken(token, yylvalpp)
  undefined4 token;
  undefined4 yylvalpp;
{
  undefined4 *allocation;
  int cppState;
  
  allocation = (undefined4 *)_malloc(0xac);
  _memset(allocation,0,0xac);
  allocation[6] = token;
  _memcpy(allocation + 7,yylvalpp,0x90);
  cppState = *(int *)PTR__cpp_a7b7c0a4;
  allocation[1] = DAT_a7b7b04c;
  *allocation = *(undefined4 *)(cppState + 0x20);
  allocation[4] = *(undefined4 *)(*(int *)(cppState + 0x20) + 0x10);
  allocation[5] = *(undefined4 *)(*(int *)(cppState + 0x20) + 0x14);
  *(undefined4 **)(cppState + 0x20) = allocation;
  return;
}

/* _DumpTokenStream @ 0x97b8adb0 (240 bytes) */
int _DumpTokenStream(unusedArg1, ts, yylvalpp)
  undefined4 unusedArg1;
  undefined4 ts;
  int yylvalpp;
{
  int tokenOrFormatArg;
  char *format;
  char acStack_80 [116];
  
  ((int (*)())_RewindTokenStream)(ts);
  do {
    tokenOrFormatArg = ((int (*)())_ReadToken)(ts,yylvalpp);
    if (tokenOrFormatArg < 1) {
      return;
    }
    switch(tokenOrFormatArg) {
    case 0x10b:
    case 0x10f:
      goto switchD_97b8ae00_caseD_10b;
    default:
      if (0x7e < tokenOrFormatArg) goto LAB_97b8ae70;
      format = "%c";
      break;
    case 0x10e:
    case 0x117:
      tokenOrFormatArg = *(int *)(yylvalpp + 8);
LAB_97b8ae70:
      tokenOrFormatArg = _GetAtomString(*(undefined4 *)PTR__atable_a7b7c0ac,tokenOrFormatArg);
      format = "%s ";
      break;
    case 0x116:
      tokenOrFormatArg = _GetAtomString(*(undefined4 *)PTR__atable_a7b7c0ac,*(undefined4 *)(yylvalpp + 8));
      format = "\"%s\"";
    }
    _sprintf(acStack_80,format,tokenOrFormatArg);
switchD_97b8ae00_caseD_10b:
    _CPPDebugLogMsg(acStack_80);
  } while( true );
}

/* TBuiltIns__getNumStringArrays @ 0x97b8aed4 (20 bytes) */
int TBuiltIns__getNumStringArrays(this, language)
  unsigned char * this;
  int language;
{
  return 6 - (uint)(language == 1);
}

/* TBuiltIns__getStringArray @ 0x97b8aee8 (204 bytes) */
int TBuiltIns__getStringArray(this, language, arrayIndex)
  unsigned char * this;
  int language;
  uint arrayIndex;
{
  undefined *stringArray;
  
  stringArray = (undefined *)0x0;
  if (language == 1) {
    if (arrayIndex == 0) {
      stringArray = &_strBuiltInFunctions;
    }
    if (arrayIndex == 1) {
      stringArray = &_strBuiltInFunctionsFragment;
    }
    if (arrayIndex == 2) {
      stringArray = &_strStandardFragmentVaryings;
    }
    if (arrayIndex == 3) {
      stringArray = &_strStandardUniformConstants;
    }
    if (arrayIndex != 4) {
      return stringArray;
    }
  }
  else {
    if (arrayIndex == 0) {
      stringArray = &_strBuiltInFunctions;
    }
    if (arrayIndex == 1) {
      stringArray = &_strBuiltInFunctionsVertex;
    }
    if (arrayIndex == 2) {
      stringArray = &_strStandardVertexVaryings;
    }
    if (arrayIndex == 3) {
      stringArray = &_strStandardVertexAttributes;
    }
    if (arrayIndex == 4) {
      stringArray = &_strStandardUniformConstants;
    }
    if (arrayIndex != 5) {
      return stringArray;
    }
  }
  return &_strStandardUniforms;
}

/* TBuiltIns__getStringSizeArray @ 0x97b8afb4 (204 bytes) */
int TBuiltIns__getStringSizeArray(this, language, arrayIndex)
  unsigned char * this;
  int language;
  uint arrayIndex;
{
  undefined *stringSizeArray;
  
  stringSizeArray = (undefined *)0x0;
  if (language == 1) {
    if (arrayIndex == 0) {
      stringSizeArray = &_sizeBuiltInFunctions;
    }
    if (arrayIndex == 1) {
      stringSizeArray = &_sizeBuiltInFunctionsFragment;
    }
    if (arrayIndex == 2) {
      stringSizeArray = &_sizeStandardFragmentVaryings;
    }
    if (arrayIndex == 3) {
      stringSizeArray = &_sizeStandardUniformConstants;
    }
    if (arrayIndex != 4) {
      return stringSizeArray;
    }
  }
  else {
    if (arrayIndex == 0) {
      stringSizeArray = &_sizeBuiltInFunctions;
    }
    if (arrayIndex == 1) {
      stringSizeArray = &_sizeBuiltInFunctionsVertex;
    }
    if (arrayIndex == 2) {
      stringSizeArray = &_sizeStandardVertexVaryings;
    }
    if (arrayIndex == 3) {
      stringSizeArray = &_sizeStandardVertexAttributes;
    }
    if (arrayIndex == 4) {
      stringSizeArray = &_sizeStandardUniformConstants;
    }
    if (arrayIndex != 5) {
      return stringSizeArray;
    }
  }
  return &_sizeStandardUniforms;
}

/* TBuiltIns__getNumStrings @ 0x97b8b080 (148 bytes) */
int TBuiltIns__getNumStrings(this, language, arrayIndex)
  unsigned char * this;
  int language;
  uint arrayIndex;
{
  bool isStandardUniforms;
  uint arrayBytes;
  
  arrayBytes = 0;
  if (language == 1) {
    if (arrayIndex == 0) {
      arrayBytes = 0x454;
    }
    if (arrayIndex == 1) {
      arrayBytes = 0x34;
    }
    if (arrayIndex == 2) {
      arrayBytes = 0x14;
    }
    if (arrayIndex == 3) {
      arrayBytes = 0x34;
    }
    isStandardUniforms = arrayIndex == 4;
  }
  else {
    if (arrayIndex == 0) {
      arrayBytes = 0x454;
    }
    if (arrayIndex == 1) {
      arrayBytes = 8;
    }
    if (arrayIndex == 2) {
      arrayBytes = 0x1c;
    }
    if (arrayIndex == 3) {
      arrayBytes = 0x38;
    }
    if (arrayIndex == 4) {
      arrayBytes = 0x34;
    }
    isStandardUniforms = arrayIndex == 5;
  }
  if (isStandardUniforms) {
    arrayBytes = 0x174;
  }
  return arrayBytes >> 2;
}

/* __ZN9TBuiltIns10initializeEv @ 0x97b8b114 (4 bytes) */
int __ZN9TBuiltIns10initializeEv()
{
  return;
}

/* __ZN9TBuiltIns10initializeERK16TBuiltInResource @ 0x97b8b118 (4 bytes) */
int __ZN9TBuiltIns10initializeERK16TBuiltInResource(this)
  unsigned char * this;
{
  return;
}

/* __Z16IdentifyBuiltIns11EShLanguageR12TSymbolTable @ 0x97b8b11c (5284 bytes) */
int __Z16IdentifyBuiltIns11EShLanguageR12TSymbolTable(language, symbolTable)
  int language;
  int *symbolTable;
{
  int oldRefCount;
  uint oldVariableBits2;
  undefined4 passThroughR4;
  undefined *operatorStrings;
  char *nameChars;
  int levelsBegin;
  int atomicStore;
  uint oldVariableBits;
  uint basicTypeField;
  int uniqueId;
  undefined4 *levelArrayBegin;
  unsigned char * poolAllocator;
  int *symbol;
  unsigned char * variableName;
  void *nameStringAllocation;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  undefined4 extraout_r4_02;
  undefined4 extraout_r4_03;
  undefined4 extraout_r4_04;
  undefined4 extraout_r4_05;
  char *operatorName;
  unsigned char * scratchR5;
  unsigned char * allocatorArgPtr;
  unsigned char * allocatorArgPtr2;
  undefined4 operatorCode;
  undefined4 scratchR6;
  undefined4 scratchR7;
  void *nameString;
  undefined *variableVtable;
  undefined4 symbolTableLevel;
  char reservation;
  byte cr0Flags;
  undefined8 nameStringAllocationPair;
  undefined4 poolAllocatorArg [4];
  undefined **stackType;
  undefined4 stackTypeArraySize;
  undefined4 stackTypeStructure;
  undefined4 stackTypeFieldName;
  undefined4 stackTypeTypeName;
  undefined4 stackTypeWord14;
  undefined4 stackTypeStructureSize;
  undefined4 stackTypeWord1c;
  undefined4 stackTypeWord20;
  uint stackTypeBits;
  undefined4 insertResultCopy;
  undefined4 insertResultFlagCopy;
  undefined4 insertResult;
  undefined4 insertResultFlag;
  undefined4 nameCopy;
  int nameCopyChars;
  int *variableForInsert;
  undefined4 destroyAllocator [4];
  undefined4 poolAllocatorArgB [4];
  undefined **stackTypeB;
  undefined4 stackTypeBArraySize;
  undefined4 stackTypeBStructure;
  undefined4 stackTypeBFieldName;
  undefined4 stackTypeBTypeName;
  undefined4 stackTypeBWord14;
  undefined4 stackTypeBStructureSize;
  undefined4 stackTypeBWord1c;
  undefined4 stackTypeBWord20;
  uint stackTypeBBits;
  undefined4 insertResultCopyB;
  undefined4 insertResultFlagCopyB;
  undefined4 insertResultB;
  undefined4 insertResultFlagB;
  undefined4 nameCopyB;
  int nameCopyCharsB;
  int *variableForInsertB;
  undefined4 destroyAllocatorB [4];
  undefined4 poolAllocatorArgC [4];
  undefined **stackTypeC;
  undefined4 stackTypeCArraySize;
  undefined4 stackTypeCStructure;
  undefined4 stackTypeCFieldName;
  undefined4 stackTypeCTypeName;
  undefined4 stackTypeCWord14;
  undefined4 stackTypeCStructureSize;
  undefined4 stackTypeCWord1c;
  undefined4 stackTypeCWord20;
  uint stackTypeCBits;
  undefined4 insertResultCopyC;
  undefined4 insertResultFlagCopyC;
  undefined4 insertResultC;
  undefined4 insertResultFlagC;
  undefined4 nameCopyC;
  int nameCopyCharsC;
  int *variableForInsertC;
  undefined4 destroyAllocatorC [4];
  undefined4 poolAllocatorArgD [4];
  undefined **stackTypeD;
  undefined4 stackTypeDArraySize;
  undefined4 stackTypeDStructure;
  undefined4 stackTypeDFieldName;
  undefined4 stackTypeDTypeName;
  undefined4 stackTypeDWord14;
  undefined4 stackTypeDStructureSize;
  undefined4 stackTypeDWord1c;
  undefined4 stackTypeDWord20;
  uint stackTypeDBits;
  undefined4 insertResultCopyD;
  undefined4 insertResultFlagCopyD;
  undefined4 insertResultD;
  undefined4 insertResultFlagD;
  undefined4 nameCopyD;
  int nameCopyCharsD;
  int *variableForInsertD;
  undefined4 destroyAllocatorD [4];
  undefined4 poolAllocatorArgE [4];
  undefined **stackTypeE;
  undefined4 stackTypeEArraySize;
  undefined4 stackTypeEStructure;
  undefined4 stackTypeEFieldName;
  undefined4 stackTypeETypeName;
  undefined4 stackTypeEWord14;
  undefined4 stackTypeEStructureSize;
  undefined4 stackTypeEWord1c;
  undefined4 stackTypeEWord20;
  uint stackTypeEBits;
  undefined4 insertResultCopyE;
  undefined4 insertResultFlagCopyE;
  undefined4 insertResultE;
  undefined4 insertResultFlagE;
  undefined4 nameCopyE;
  int nameCopyCharsE;
  int *variableForInsertE;
  undefined4 destroyAllocatorE [4];
  undefined4 poolAllocatorArgF [4];
  undefined **stackTypeF;
  undefined4 stackTypeFArraySize;
  undefined4 stackTypeFStructure;
  undefined4 stackTypeFFieldName;
  undefined4 stackTypeFTypeName;
  undefined4 stackTypeFWord14;
  undefined4 stackTypeFStructureSize;
  undefined4 stackTypeFWord1c;
  undefined4 stackTypeFWord20;
  uint stackTypeFBits;
  undefined4 insertResultCopyF;
  undefined4 insertResultFlagCopyF;
  undefined4 insertResultF;
  undefined4 insertResultFlagF;
  undefined4 nameCopyF;
  int nameCopyCharsF;
  int *variableForInsertF;
  undefined4 destroyAllocatorF [4];
  undefined4 poolAllocatorArgG [4];
  undefined **stackTypeG;
  undefined4 stackTypeGArraySize;
  undefined4 stackTypeGStructure;
  undefined4 stackTypeGFieldName;
  undefined4 stackTypeGTypeName;
  undefined4 stackTypeGWord14;
  undefined4 stackTypeGStructureSize;
  undefined4 stackTypeGWord1c;
  undefined4 stackTypeGWord20;
  uint stackTypeGBits;
  undefined4 insertResultCopyG;
  undefined4 insertResultFlagCopyG;
  undefined4 insertResultG;
  undefined4 insertResultFlagG;
  undefined4 nameCopyG;
  int nameCopyCharsG;
  int *variableForInsertG;
  undefined4 destroyAllocatorG [6];
  
  if (language == 0) {
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    symbol = (int *)TPoolAllocator__allocate(poolAllocator,0x40);
    nameChars = DAT_a7b7b708;
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    nameStringAllocationPair = TPoolAllocator__allocate(poolAllocator,8);
    nameStringAllocation = (void *)((ulonglong)nameStringAllocationPair >> 0x20);
    passThroughR4 = (undefined4)nameStringAllocationPair;
    cr0Flags = (nameStringAllocation == (void *)0x0) << 1;
    nameString = (void *)0x0;
    if (nameStringAllocation != (void *)0x0) {
      poolAllocatorArgE[0] = GetGlobalPoolAllocator();
      scratchR5 = (unsigned char *)poolAllocatorArgE;
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_(nameStringAllocation,nameChars,scratchR5);
      passThroughR4 = extraout_r4_03;
      nameString = nameStringAllocation;
    }
    variableVtable = PTR_vtable_a7b7c0b4 + 8;
    stackTypeEBits = stackTypeEBits & 0x801ff | 0x1a082000;
    stackTypeEArraySize = 0;
    stackTypeEStructure = 0;
    stackTypeEFieldName = 0;
    allocatorArgPtr = (unsigned char *)&nameCopyE;
    stackTypeETypeName = 0;
    stackTypeEWord14 = 0;
    stackTypeEStructureSize = 0;
    stackTypeEWord1c = 0;
    stackTypeEWord20 = 0;
    stackTypeE = &PTR___ZN5TTypeD1Ev_a7b7cf48;
    symbol[1] = (int)nameString;
    *symbol = (int)variableVtable;
    symbol[4] = 0;
    symbol[5] = 0;
    symbol[6] = 0;
    symbol[7] = 0;
    symbol[8] = 0;
    symbol[9] = 0;
    symbol[10] = 0;
    symbol[3] = (int)&PTR___ZN5TTypeD1Ev_a7b7cf48;
    symbol[0xb] = 0;
    oldVariableBits = symbol[0xc];
    symbol[0xc] = oldVariableBits & 0x1ffffff | 0x1a000000;
    basicTypeField = (stackTypeEBits >> 0x13 & 0x3f) << 0x13;
    symbol[0xc] = basicTypeField | oldVariableBits & 0x7ffff | 0x1a000000;
    symbol[0xc] = basicTypeField | oldVariableBits & 0x7ff | 0x1a000000 | 0x2000;
    symbol[0xc] = basicTypeField | oldVariableBits & 0x3ff | 0x1a000000 | 0x2000;
    symbol[0xc] = basicTypeField | oldVariableBits & 0x1ff | 0x1a000000 | 0x2000;
    symbol[0xd] = 0;
    symbol[0xe] = 0;
    symbol[0xf] = 0;
    uniqueId = symbolTable[3];
    symbolTable[3] = uniqueId + 1;
    symbol[2] = uniqueId + 1;
    levelsBegin = *symbolTable;
    symbolTableLevel = *(undefined4 *)(levelsBegin + ((symbolTable[1] - levelsBegin & 0xfffffffcU) - 4));
    insertResultFlagCopyE = 0;
    variableName = (unsigned char *)(**(code **)(*symbol + 8))(symbol,passThroughR4,scratchR5,scratchR6,scratchR7,nameString,levelsBegin);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(allocatorArgPtr,variableName);
    variableForInsertE = symbol;
    std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&insertResultE,symbolTableLevel,allocatorArgPtr);
    insertResultCopyE = insertResultE;
    symbol = (int *)(nameCopyCharsE + -4);
    insertResultFlagCopyE = insertResultFlagE;
    destroyAllocatorE[0] = nameCopyE;
    do {
      oldRefCount = *symbol;
      if (reservation != '\0') {
        atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,symbol);
        *symbol = atomicStore;
        cr0Flags = 2;
      }
    } while (!(bool)(cr0Flags >> 1 & 1));
    if (oldRefCount < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(nameCopyCharsE + -0xc),destroyAllocatorE);
    }
    stackTypeE = &PTR___ZN5TTypeD1Ev_a7b7cf48;
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    symbol = (int *)TPoolAllocator__allocate(poolAllocator,0x40);
    nameChars = DAT_a7b7b70c;
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    nameStringAllocationPair = TPoolAllocator__allocate(poolAllocator,8);
    nameStringAllocation = (void *)((ulonglong)nameStringAllocationPair >> 0x20);
    passThroughR4 = (undefined4)nameStringAllocationPair;
    cr0Flags = (nameStringAllocation == (void *)0x0) << 1;
    nameString = (void *)0x0;
    if (nameStringAllocation != (void *)0x0) {
      poolAllocatorArgF[0] = GetGlobalPoolAllocator();
      allocatorArgPtr = (unsigned char *)poolAllocatorArgF;
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_(nameStringAllocation,nameChars,allocatorArgPtr);
      passThroughR4 = extraout_r4_04;
      nameString = nameStringAllocation;
    }
    variableVtable = PTR_vtable_a7b7c0b4 + 8;
    stackTypeFBits = stackTypeFBits & 0x1ff | 0x1c080800;
    stackTypeFArraySize = 0;
    stackTypeFStructure = 0;
    allocatorArgPtr2 = (unsigned char *)&nameCopyF;
    stackTypeFFieldName = 0;
    stackTypeFTypeName = 0;
    stackTypeFWord14 = 0;
    stackTypeFStructureSize = 0;
    stackTypeFWord1c = 0;
    stackTypeFWord20 = 0;
    stackTypeF = &PTR___ZN5TTypeD1Ev_a7b7cf48;
    symbol[1] = (int)nameString;
    *symbol = (int)variableVtable;
    symbol[4] = 0;
    symbol[5] = 0;
    symbol[6] = 0;
    symbol[7] = 0;
    symbol[8] = 0;
    symbol[9] = 0;
    symbol[10] = 0;
    symbol[3] = (int)&PTR___ZN5TTypeD1Ev_a7b7cf48;
    symbol[0xb] = 0;
    oldVariableBits2 = symbol[0xc];
    symbol[0xc] = oldVariableBits2 & 0x1ffffff | 0x1c000000;
    symbol[0xc] = oldVariableBits2 & 0x7ffff | 0x1c080000;
    symbol[0xc] = oldVariableBits2 & 0x7ff | 0x1c080800;
    symbol[0xc] = oldVariableBits2 & 0x3ff | 0x1c080800;
    symbol[0xc] = oldVariableBits2 & 0x1ff | 0x1c080800;
    symbol[0xd] = 0;
    symbol[0xe] = 0;
    symbol[0xf] = 0;
    uniqueId = symbolTable[3];
    symbolTable[3] = uniqueId + 1;
    symbol[2] = uniqueId + 1;
    levelsBegin = *symbolTable;
    symbolTableLevel = *(undefined4 *)(levelsBegin + ((symbolTable[1] - levelsBegin & 0xfffffffcU) - 4));
    insertResultFlagCopyF = 0;
    variableName = (unsigned char *)(**(code **)(*symbol + 8))(symbol,passThroughR4,allocatorArgPtr,scratchR6,scratchR7,nameString,levelsBegin);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(allocatorArgPtr2,variableName);
    variableForInsertF = symbol;
    std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&insertResultF,symbolTableLevel,allocatorArgPtr2);
    insertResultCopyF = insertResultF;
    symbol = (int *)(nameCopyCharsF + -4);
    insertResultFlagCopyF = insertResultFlagF;
    destroyAllocatorF[0] = nameCopyF;
    do {
      oldRefCount = *symbol;
      if (reservation != '\0') {
        atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,symbol);
        *symbol = atomicStore;
        cr0Flags = 2;
      }
    } while (!(bool)(cr0Flags >> 1 & 1));
    if (oldRefCount < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(nameCopyCharsF + -0xc),destroyAllocatorF);
    }
    stackTypeF = &PTR___ZN5TTypeD1Ev_a7b7cf48;
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    symbol = (int *)TPoolAllocator__allocate(poolAllocator,0x40);
    nameChars = DAT_a7b7b710;
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    nameStringAllocationPair = TPoolAllocator__allocate(poolAllocator,8);
    nameStringAllocation = (void *)((ulonglong)nameStringAllocationPair >> 0x20);
    passThroughR4 = (undefined4)nameStringAllocationPair;
    cr0Flags = (nameStringAllocation == (void *)0x0) << 1;
    nameString = (void *)0x0;
    if (nameStringAllocation != (void *)0x0) {
      poolAllocatorArgG[0] = GetGlobalPoolAllocator();
      allocatorArgPtr2 = (unsigned char *)poolAllocatorArgG;
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_(nameStringAllocation,nameChars,allocatorArgPtr2);
      passThroughR4 = extraout_r4_05;
      nameString = nameStringAllocation;
    }
    variableVtable = PTR_vtable_a7b7c0b4 + 8;
    stackTypeGBits = stackTypeGBits & 0x801ff | 0x1e082000;
    stackTypeGArraySize = 0;
    stackTypeGStructure = 0;
    stackTypeGFieldName = 0;
    stackTypeGTypeName = 0;
    stackTypeGWord14 = 0;
    stackTypeGStructureSize = 0;
    stackTypeGWord1c = 0;
    stackTypeGWord20 = 0;
    stackTypeG = &PTR___ZN5TTypeD1Ev_a7b7cf48;
    symbol[1] = (int)nameString;
    *symbol = (int)variableVtable;
    symbol[4] = 0;
    symbol[5] = 0;
    symbol[6] = 0;
    symbol[7] = 0;
    symbol[8] = 0;
    symbol[9] = 0;
    symbol[10] = 0;
    symbol[3] = (int)&PTR___ZN5TTypeD1Ev_a7b7cf48;
    symbol[0xb] = 0;
    oldVariableBits = symbol[0xc];
    symbol[0xc] = oldVariableBits & 0x1ffffff | 0x1e000000;
    basicTypeField = (stackTypeGBits >> 0x13 & 0x3f) << 0x13;
    symbol[0xc] = basicTypeField | oldVariableBits & 0x7ffff | 0x1e000000;
    symbol[0xc] = basicTypeField | oldVariableBits & 0x7ff | 0x1e000000 | 0x2000;
    symbol[0xc] = basicTypeField | oldVariableBits & 0x3ff | 0x1e000000 | 0x2000;
    symbol[0xc] = basicTypeField | oldVariableBits & 0x1ff | 0x1e000000 | 0x2000;
    symbol[0xd] = 0;
    symbol[0xe] = 0;
    symbol[0xf] = 0;
    uniqueId = symbolTable[3];
    symbolTable[3] = uniqueId + 1;
    symbol[2] = uniqueId + 1;
    levelsBegin = *symbolTable;
    symbolTableLevel = *(undefined4 *)(levelsBegin + ((symbolTable[1] - levelsBegin & 0xfffffffcU) - 4));
    insertResultFlagCopyG = 0;
    variableName = (unsigned char *)(**(code **)(*symbol + 8))(symbol,passThroughR4,allocatorArgPtr2,scratchR6,scratchR7,nameString,levelsBegin);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&nameCopyG,variableName);
    variableForInsertG = symbol;
    std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&insertResultG,symbolTableLevel,&nameCopyG);
    insertResultCopyG = insertResultG;
    symbol = (int *)(nameCopyCharsG + -4);
    insertResultFlagCopyG = insertResultFlagG;
    destroyAllocatorG[0] = nameCopyG;
    do {
      oldRefCount = *symbol;
      if (reservation != '\0') {
        atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,symbol);
        *symbol = atomicStore;
        cr0Flags = 2;
      }
    } while (!(bool)(cr0Flags >> 1 & 1));
    if (oldRefCount < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(nameCopyCharsG + -0xc),destroyAllocatorG);
    }
    stackTypeG = &PTR___ZN5TTypeD1Ev_a7b7cf48;
  }
  else if (language == 1) {
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    symbol = (int *)TPoolAllocator__allocate(poolAllocator,0x40);
    nameChars = _strSpecialBuiltIn;
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    nameStringAllocationPair = TPoolAllocator__allocate(poolAllocator,8);
    nameStringAllocation = (void *)((ulonglong)nameStringAllocationPair >> 0x20);
    passThroughR4 = (undefined4)nameStringAllocationPair;
    cr0Flags = (nameStringAllocation == (void *)0x0) << 1;
    nameString = (void *)0x0;
    if (nameStringAllocation != (void *)0x0) {
      poolAllocatorArg[0] = GetGlobalPoolAllocator();
      scratchR5 = (unsigned char *)poolAllocatorArg;
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_(nameStringAllocation,nameChars,scratchR5);
      passThroughR4 = extraout_r4;
      nameString = nameStringAllocation;
    }
    variableVtable = PTR_vtable_a7b7c0b4 + 8;
    stackTypeBits = stackTypeBits & 0x1801ff | 0x20180800;
    stackTypeArraySize = 0;
    stackTypeStructure = 0;
    stackTypeFieldName = 0;
    allocatorArgPtr = (unsigned char *)&nameCopy;
    stackTypeTypeName = 0;
    stackTypeWord14 = 0;
    stackTypeStructureSize = 0;
    stackTypeWord1c = 0;
    stackTypeWord20 = 0;
    stackType = &PTR___ZN5TTypeD1Ev_a7b7cf48;
    symbol[1] = (int)nameString;
    *symbol = (int)variableVtable;
    symbol[4] = 0;
    symbol[5] = 0;
    symbol[6] = 0;
    symbol[7] = 0;
    symbol[8] = 0;
    symbol[9] = 0;
    symbol[10] = 0;
    symbol[3] = (int)&PTR___ZN5TTypeD1Ev_a7b7cf48;
    symbol[0xb] = 0;
    oldVariableBits = symbol[0xc];
    symbol[0xc] = oldVariableBits & 0x1ffffff | 0x20000000;
    basicTypeField = (stackTypeBits >> 0x13 & 0x3f) << 0x13;
    symbol[0xc] = basicTypeField | oldVariableBits & 0x7ffff | 0x20000000;
    symbol[0xc] = basicTypeField | oldVariableBits & 0x7ff | 0x20000000 | 0x800;
    symbol[0xc] = basicTypeField | oldVariableBits & 0x3ff | 0x20000000 | 0x800;
    symbol[0xc] = basicTypeField | oldVariableBits & 0x1ff | 0x20000000 | 0x800;
    symbol[0xd] = 0;
    symbol[0xe] = 0;
    symbol[0xf] = 0;
    uniqueId = symbolTable[3];
    symbolTable[3] = uniqueId + 1;
    symbol[2] = uniqueId + 1;
    levelsBegin = *symbolTable;
    symbolTableLevel = *(undefined4 *)(levelsBegin + ((symbolTable[1] - levelsBegin & 0xfffffffcU) - 4));
    insertResultFlagCopy = 0;
    variableName = (unsigned char *)(**(code **)(*symbol + 8))(symbol,passThroughR4,scratchR5,scratchR6,scratchR7,nameString,levelsBegin);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(allocatorArgPtr,variableName);
    variableForInsert = symbol;
    std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&insertResult,symbolTableLevel,allocatorArgPtr);
    insertResultCopy = insertResult;
    symbol = (int *)(nameCopyChars + -4);
    insertResultFlagCopy = insertResultFlag;
    destroyAllocator[0] = nameCopy;
    do {
      oldRefCount = *symbol;
      if (reservation != '\0') {
        atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,symbol);
        *symbol = atomicStore;
        cr0Flags = 2;
      }
    } while (!(bool)(cr0Flags >> 1 & 1));
    if (oldRefCount < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(nameCopyChars + -0xc),destroyAllocator);
    }
    stackType = &PTR___ZN5TTypeD1Ev_a7b7cf48;
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    symbol = (int *)TPoolAllocator__allocate(poolAllocator,0x40);
    nameChars = DAT_a7b7b6f8;
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    nameStringAllocationPair = TPoolAllocator__allocate(poolAllocator,8);
    nameStringAllocation = (void *)((ulonglong)nameStringAllocationPair >> 0x20);
    passThroughR4 = (undefined4)nameStringAllocationPair;
    cr0Flags = (nameStringAllocation == (void *)0x0) << 1;
    nameString = (void *)0x0;
    if (nameStringAllocation != (void *)0x0) {
      poolAllocatorArgB[0] = GetGlobalPoolAllocator();
      allocatorArgPtr = (unsigned char *)poolAllocatorArgB;
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_(nameStringAllocation,nameChars,allocatorArgPtr);
      passThroughR4 = extraout_r4_00;
      nameString = nameStringAllocation;
    }
    variableVtable = PTR_vtable_a7b7c0b4 + 8;
    stackTypeBBits = stackTypeBBits & 0x801ff | 0x22082000;
    stackTypeBArraySize = 0;
    stackTypeBStructure = 0;
    stackTypeBFieldName = 0;
    allocatorArgPtr2 = (unsigned char *)&nameCopyB;
    stackTypeBTypeName = 0;
    stackTypeBWord14 = 0;
    stackTypeBStructureSize = 0;
    stackTypeBWord1c = 0;
    stackTypeBWord20 = 0;
    stackTypeB = &PTR___ZN5TTypeD1Ev_a7b7cf48;
    symbol[1] = (int)nameString;
    *symbol = (int)variableVtable;
    symbol[4] = 0;
    symbol[5] = 0;
    symbol[6] = 0;
    symbol[7] = 0;
    symbol[8] = 0;
    symbol[9] = 0;
    symbol[10] = 0;
    symbol[3] = (int)&PTR___ZN5TTypeD1Ev_a7b7cf48;
    symbol[0xb] = 0;
    oldVariableBits = symbol[0xc];
    symbol[0xc] = oldVariableBits & 0x1ffffff | 0x22000000;
    basicTypeField = (stackTypeBBits >> 0x13 & 0x3f) << 0x13;
    symbol[0xc] = basicTypeField | oldVariableBits & 0x7ffff | 0x22000000;
    symbol[0xc] = basicTypeField | oldVariableBits & 0x7ff | 0x22000000 | 0x2000;
    symbol[0xc] = basicTypeField | oldVariableBits & 0x3ff | 0x22000000 | 0x2000;
    symbol[0xc] = basicTypeField | oldVariableBits & 0x1ff | 0x22000000 | 0x2000;
    symbol[0xd] = 0;
    symbol[0xe] = 0;
    symbol[0xf] = 0;
    uniqueId = symbolTable[3];
    symbolTable[3] = uniqueId + 1;
    symbol[2] = uniqueId + 1;
    levelsBegin = *symbolTable;
    symbolTableLevel = *(undefined4 *)(levelsBegin + ((symbolTable[1] - levelsBegin & 0xfffffffcU) - 4));
    insertResultFlagCopyB = 0;
    variableName = (unsigned char *)(**(code **)(*symbol + 8))(symbol,passThroughR4,allocatorArgPtr,scratchR6,scratchR7,nameString,levelsBegin);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(allocatorArgPtr2,variableName);
    variableForInsertB = symbol;
    std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&insertResultB,symbolTableLevel,allocatorArgPtr2);
    insertResultCopyB = insertResultB;
    symbol = (int *)(nameCopyCharsB + -4);
    insertResultFlagCopyB = insertResultFlagB;
    destroyAllocatorB[0] = nameCopyB;
    do {
      oldRefCount = *symbol;
      if (reservation != '\0') {
        atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,symbol);
        *symbol = atomicStore;
        cr0Flags = 2;
      }
    } while (!(bool)(cr0Flags >> 1 & 1));
    if (oldRefCount < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(nameCopyCharsB + -0xc),destroyAllocatorB);
    }
    stackTypeB = &PTR___ZN5TTypeD1Ev_a7b7cf48;
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    symbol = (int *)TPoolAllocator__allocate(poolAllocator,0x40);
    nameChars = DAT_a7b7b6fc;
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    nameStringAllocationPair = TPoolAllocator__allocate(poolAllocator,8);
    nameStringAllocation = (void *)((ulonglong)nameStringAllocationPair >> 0x20);
    passThroughR4 = (undefined4)nameStringAllocationPair;
    cr0Flags = (nameStringAllocation == (void *)0x0) << 1;
    nameString = (void *)0x0;
    if (nameStringAllocation != (void *)0x0) {
      poolAllocatorArgC[0] = GetGlobalPoolAllocator();
      allocatorArgPtr2 = (unsigned char *)poolAllocatorArgC;
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_(nameStringAllocation,nameChars,allocatorArgPtr2);
      passThroughR4 = extraout_r4_01;
      nameString = nameStringAllocation;
    }
    variableVtable = PTR_vtable_a7b7c0b4 + 8;
    stackTypeCBits = stackTypeCBits & 0x801ff | 0x24082000;
    stackTypeCArraySize = 0;
    stackTypeCStructure = 0;
    stackTypeCFieldName = 0;
    allocatorArgPtr = (unsigned char *)&nameCopyC;
    stackTypeCTypeName = 0;
    stackTypeCWord14 = 0;
    stackTypeCStructureSize = 0;
    stackTypeCWord1c = 0;
    stackTypeCWord20 = 0;
    stackTypeC = &PTR___ZN5TTypeD1Ev_a7b7cf48;
    symbol[1] = (int)nameString;
    *symbol = (int)variableVtable;
    symbol[4] = 0;
    symbol[5] = 0;
    symbol[6] = 0;
    symbol[7] = 0;
    symbol[8] = 0;
    symbol[9] = 0;
    symbol[10] = 0;
    symbol[3] = (int)&PTR___ZN5TTypeD1Ev_a7b7cf48;
    symbol[0xb] = 0;
    oldVariableBits = symbol[0xc];
    symbol[0xc] = oldVariableBits & 0x1ffffff | 0x24000000;
    basicTypeField = (stackTypeCBits >> 0x13 & 0x3f) << 0x13;
    symbol[0xc] = basicTypeField | oldVariableBits & 0x7ffff | 0x24000000;
    symbol[0xc] = basicTypeField | oldVariableBits & 0x7ff | 0x24000000 | 0x2000;
    symbol[0xc] = basicTypeField | oldVariableBits & 0x3ff | 0x24000000 | 0x2000;
    symbol[0xc] = basicTypeField | oldVariableBits & 0x1ff | 0x24000000 | 0x2000;
    symbol[0xd] = 0;
    symbol[0xe] = 0;
    symbol[0xf] = 0;
    uniqueId = symbolTable[3];
    symbolTable[3] = uniqueId + 1;
    symbol[2] = uniqueId + 1;
    levelsBegin = *symbolTable;
    symbolTableLevel = *(undefined4 *)(levelsBegin + ((symbolTable[1] - levelsBegin & 0xfffffffcU) - 4));
    insertResultFlagCopyC = 0;
    variableName = (unsigned char *)(**(code **)(*symbol + 8))(symbol,passThroughR4,allocatorArgPtr2,scratchR6,scratchR7,nameString,levelsBegin);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(allocatorArgPtr,variableName);
    variableForInsertC = symbol;
    std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&insertResultC,symbolTableLevel,allocatorArgPtr);
    insertResultCopyC = insertResultC;
    symbol = (int *)(nameCopyCharsC + -4);
    insertResultFlagCopyC = insertResultFlagC;
    destroyAllocatorC[0] = nameCopyC;
    do {
      oldRefCount = *symbol;
      if (reservation != '\0') {
        atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,symbol);
        *symbol = atomicStore;
        cr0Flags = 2;
      }
    } while (!(bool)(cr0Flags >> 1 & 1));
    if (oldRefCount < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(nameCopyCharsC + -0xc),destroyAllocatorC);
    }
    stackTypeC = &PTR___ZN5TTypeD1Ev_a7b7cf48;
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    symbol = (int *)TPoolAllocator__allocate(poolAllocator,0x40);
    nameChars = DAT_a7b7b700;
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    nameStringAllocationPair = TPoolAllocator__allocate(poolAllocator,8);
    nameStringAllocation = (void *)((ulonglong)nameStringAllocationPair >> 0x20);
    passThroughR4 = (undefined4)nameStringAllocationPair;
    cr0Flags = (nameStringAllocation == (void *)0x0) << 1;
    nameString = (void *)0x0;
    if (nameStringAllocation != (void *)0x0) {
      poolAllocatorArgD[0] = GetGlobalPoolAllocator();
      allocatorArgPtr = (unsigned char *)poolAllocatorArgD;
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_(nameStringAllocation,nameChars,allocatorArgPtr);
      passThroughR4 = extraout_r4_02;
      nameString = nameStringAllocation;
    }
    variableVtable = PTR_vtable_a7b7c0b4 + 8;
    stackTypeDBits = stackTypeDBits & 0x1ff | 0x26080800;
    stackTypeDArraySize = 0;
    stackTypeDStructure = 0;
    stackTypeDFieldName = 0;
    stackTypeDTypeName = 0;
    stackTypeDWord14 = 0;
    stackTypeDStructureSize = 0;
    stackTypeDWord1c = 0;
    stackTypeDWord20 = 0;
    stackTypeD = &PTR___ZN5TTypeD1Ev_a7b7cf48;
    symbol[1] = (int)nameString;
    *symbol = (int)variableVtable;
    symbol[4] = 0;
    symbol[5] = 0;
    symbol[6] = 0;
    symbol[7] = 0;
    symbol[8] = 0;
    symbol[9] = 0;
    symbol[10] = 0;
    symbol[3] = (int)&PTR___ZN5TTypeD1Ev_a7b7cf48;
    symbol[0xb] = 0;
    oldVariableBits2 = symbol[0xc];
    symbol[0xc] = oldVariableBits2 & 0x1ffffff | 0x26000000;
    symbol[0xc] = oldVariableBits2 & 0x7ffff | 0x26080000;
    symbol[0xc] = oldVariableBits2 & 0x7ff | 0x26080800;
    symbol[0xc] = oldVariableBits2 & 0x3ff | 0x26080800;
    symbol[0xc] = oldVariableBits2 & 0x1ff | 0x26080800;
    symbol[0xd] = 0;
    symbol[0xe] = 0;
    symbol[0xf] = 0;
    uniqueId = symbolTable[3];
    symbolTable[3] = uniqueId + 1;
    symbol[2] = uniqueId + 1;
    levelsBegin = *symbolTable;
    symbolTableLevel = *(undefined4 *)(levelsBegin + ((symbolTable[1] - levelsBegin & 0xfffffffcU) - 4));
    insertResultFlagCopyD = 0;
    variableName = (unsigned char *)(**(code **)(*symbol + 8))(symbol,passThroughR4,allocatorArgPtr,scratchR6,scratchR7,nameString,levelsBegin);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&nameCopyD,variableName);
    variableForInsertD = symbol;
    std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&insertResultD,symbolTableLevel,&nameCopyD);
    insertResultCopyD = insertResultD;
    symbol = (int *)(nameCopyCharsD + -4);
    insertResultFlagCopyD = insertResultFlagD;
    destroyAllocatorD[0] = nameCopyD;
    do {
      oldRefCount = *symbol;
      if (reservation != '\0') {
        atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,symbol);
        *symbol = atomicStore;
        cr0Flags = 2;
      }
    } while (!(bool)(cr0Flags >> 1 & 1));
    if (oldRefCount < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(nameCopyCharsD + -0xc),destroyAllocatorD);
    }
    stackTypeD = &PTR___ZN5TTypeD1Ev_a7b7cf48;
  }
  operatorStrings = PTR__operatorStrings_a7b7c0b0;
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(PTR__operatorStrings_a7b7c0b0 + 0x1c),7);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x54),0x15);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x5c),0x17);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x7c),0x1f);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x80),0x20);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x84),0x21);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x88),0x22);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x8c),0x23);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x90),0x24);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0xc4),0x31);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 200),0x32);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0xcc),0x33);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0xd0),0x34);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0xd4),0x35);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0xd8),0x36);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0xdc),0x37);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0xe0),0x38);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0xe4),0x39);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0xf0),0x3c);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0xec),0x3b);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0xe8),0x3a);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0xf4),0x3d);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0xf8),0x3e);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0xfc),0x3f);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x100),0x40);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x104),0x41);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x108),0x42);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x10c),0x43);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x110),0x44);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x114),0x45);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x118),0x46);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x11c),0x47);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x120),0x48);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x124),0x49);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x128),0x4a);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 300),0x4b);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x130),0x4c);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x134),0x4d);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x138),0x4e);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x13c),0x4f);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x140),0x50);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x144),0x51);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x148),0x52);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x15c),0x57);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x160),0x58);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x218),0x86);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x21c),0x87);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x220),0x88);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x224),0x89);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x228),0x8a);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x22c),0x8b);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x230),0x8c);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x234),0x8d);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x238),0x8e);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x23c),0x8f);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x240),0x90);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x244),0x91);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x248),0x92);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x24c),0x93);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x250),0x94);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x254),0x95);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 600),0x96);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x25c),0x97);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x260),0x98);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x264),0x99);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x268),0x9a);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x26c),0x9b);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x270),0x9c);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x274),0x9d);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x278),0x9e);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x27c),0x9f);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x280),0xa0);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x284),0xa1);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x288),0xa2);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x28c),0xa3);
  if (language == 0) {
    levelArrayBegin = (undefined4 *)*symbolTable;
    operatorCode = 0x85;
    operatorName = *(char **)(operatorStrings + 0x214);
  }
  else {
    if (language != 1) {
      return;
    }
    TSymbolTableLevel__relateToOperator
              (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x14c),0x53);
    TSymbolTableLevel__relateToOperator
              (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x150),0x54);
    levelArrayBegin = (undefined4 *)*symbolTable;
    operatorName = *(char **)(operatorStrings + 0x154);
    operatorCode = 0x55;
  }
  TSymbolTableLevel__relateToOperator((unsigned char *)*levelArrayBegin,operatorName,operatorCode);
  return;
}

/* __Z16IdentifyBuiltIns11EShLanguageR12TSymbolTableRK16TBuiltInResource @ 0x97b8c5c0 (600 bytes) */
int __Z16IdentifyBuiltIns11EShLanguageR12TSymbolTableRK16TBuiltInResource(language, symbolTable, builtInResource)
  int language;
  int *symbolTable;
  unsigned char * builtInResource;
{
  int fragDataArraySize;
  int *refCountPtr;
  int oldRefCount;
  int atomicStore;
  char *nameChars;
  void *nameString;
  uint oldTypeBits;
  unsigned char * poolAllocator;
  int *variable;
  void *this;
  unsigned char * variableNameRef;
  undefined4 extraout_r4;
  undefined4 a1;
  undefined4 scratchR6;
  undefined4 scratchR7;
  undefined4 scratchR8;
  int uniqueId;
  undefined4 symbolTableLevel;
  char reservation;
  byte cr0Flags;
  undefined8 nameStringAllocationPair;
  undefined4 allocatorArg [4];
  undefined4 insertResultFirst;
  undefined4 insertResultSecond;
  undefined4 mapInsertFirst;
  undefined4 mapInsertSecond;
  undefined4 nameCopyAllocator;
  int nameCopyChars;
  int *mapEntryVariable;
  undefined4 destroyAllocatorArg [6];
  
  if (language == 1) {
    fragDataArraySize = *(int *)(builtInResource + 0x2c);
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    variable = (int *)TPoolAllocator__allocate(poolAllocator,0x40);
    nameChars = DAT_a7b7b704;
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    nameStringAllocationPair = TPoolAllocator__allocate(poolAllocator,8);
    this = (void *)((ulonglong)nameStringAllocationPair >> 0x20);
    a1 = (undefined4)nameStringAllocationPair;
    cr0Flags = (this == (void *)0x0) << 1;
    nameString = (void *)0x0;
    if (this != (void *)0x0) {
      allocatorArg[0] = GetGlobalPoolAllocator();
      builtInResource = (unsigned char *)allocatorArg;
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_(this,nameChars,builtInResource);
      nameString = this;
      a1 = extraout_r4;
    }
    variable[1] = (int)nameString;
    *variable = (int)(PTR_vtable_a7b7c0b4 + 8);
    variable[4] = fragDataArraySize;
    variable[5] = 0;
    variable[6] = 0;
    variable[7] = 0;
    variable[8] = 0;
    variable[9] = 0;
    variable[3] = (int)&PTR___ZN5TTypeD1Ev_a7b7cf48;
    variable[10] = 0;
    variable[0xb] = 0;
    oldTypeBits = variable[0xc];
    variable[0xc] = oldTypeBits & 0x1ffffff | 0x24000000;
    variable[0xc] = oldTypeBits & 0x7ffff | 0x24080000;
    variable[0xc] = oldTypeBits & 0x7ff | 0x24082000;
    variable[0xc] = oldTypeBits & 0x3ff | 0x24082000;
    variable[0xc] = oldTypeBits & 0x1ff | 0x24082200;
    variable[0xd] = 0;
    variable[0xe] = 0;
    variable[0xf] = 0;
    uniqueId = symbolTable[3];
    symbolTable[3] = uniqueId + 1;
    variable[2] = uniqueId + 1;
    symbolTableLevel = *(undefined4 *)(*symbolTable + ((symbolTable[1] - *symbolTable & 0xfffffffcU) - 4));
    insertResultSecond = 0;
    variableNameRef = (unsigned char *)(**(code **)(*variable + 8))(variable,a1,builtInResource,scratchR6,scratchR7,scratchR8,0);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&nameCopyAllocator,variableNameRef);
    mapEntryVariable = variable;
    std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&mapInsertFirst,symbolTableLevel,&nameCopyAllocator);
    insertResultFirst = mapInsertFirst;
    refCountPtr = (int *)(nameCopyChars + -4);
    insertResultSecond = mapInsertSecond;
    destroyAllocatorArg[0] = nameCopyAllocator;
    do {
      oldRefCount = *refCountPtr;
      if (reservation != '\0') {
        atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
        *refCountPtr = atomicStore;
        cr0Flags = 2;
      }
    } while (!(bool)(cr0Flags >> 1 & 1));
    if (oldRefCount < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(nameCopyChars + -0xc),destroyAllocatorArg);
    }
  }
  return;
}

/* GetPreprocessorBuiltinString @ 0x97b8c818 (28 bytes) */
int GetPreprocessorBuiltinString()
{
  return GetPreprocessorBuiltinString__PreprocessorBuiltinString;
}

/* __ZN13TInfoSinkBase6appendEPKc @ 0x97b8c834 (196 bytes) */
int __ZN13TInfoSinkBase6appendEPKc(this, str)
  void *this;
  char *str;
{
  uint targetFlags;
  uint capacity;
  int length;
  ulong length2;
  
  targetFlags = *(uint *)((int)this + 4);
  if ((targetFlags & 4) != 0) {
    length = _strlen(str);
    capacity = *(uint *)(*(int *)this + -8);
    if (capacity < *(int *)(*(int *)this + -0xc) + length + 2U) {
      __ZNSs7reserveEm(this,capacity + (capacity >> 1));
    }
    length2 = _strlen(str);
    __ZNSs6appendEPKcm(this,str,length2);
    targetFlags = *(uint *)((int)this + 4);
  }
  if ((targetFlags & 2) != 0) {
    _fprintf((FILE *)(PTR_DAT_a7b7c0bc + 0x58),"%s",str);
    return;
  }
  return;
}

/* __ZN13TInfoSinkBase6appendEic @ 0x97b8c8f8 (180 bytes) */
int __ZN13TInfoSinkBase6appendEic(this, count, ch)
  void *this;
  int count;
  undefined4 ch;
{
  uint targetFlags;
  uint capacity;
  
  targetFlags = *(uint *)((int)this + 4);
  if ((targetFlags & 4) != 0) {
    capacity = *(uint *)(*(int *)this + -8);
    if (capacity < *(int *)(*(int *)this + -0xc) + count + 2U) {
      __ZNSs7reserveEm(this,capacity + (capacity >> 1));
    }
    __ZNSs6appendEmc(this,count,ch);
    targetFlags = *(uint *)((int)this + 4);
  }
  if ((targetFlags & 2) != 0) {
    _fprintf((FILE *)(PTR_DAT_a7b7c0bc + 0x58),"%c",ch);
    return;
  }
  return;
}

/* __ZN13TInfoSinkBase6appendERKSs @ 0x97b8c9ac (204 bytes) */
int __ZN13TInfoSinkBase6appendERKSs(this, text)
  void *this;
  unsigned char * text;
{
  uint targetFlags;
  undefined *stdFiles;
  uint capacity;
  
  targetFlags = *(uint *)((int)this + 4);
  if ((targetFlags & 4) != 0) {
    capacity = *(uint *)(*(int *)this + -8);
    if (capacity < *(int *)(*(int *)this + -0xc) + *(int *)(*(int *)text + -0xc) + 2U) {
      __ZNSs7reserveEm(this,capacity + (capacity >> 1));
    }
    __ZNSs6appendERKSs(this,text);
    targetFlags = *(uint *)((int)this + 4);
  }
  stdFiles = PTR_DAT_a7b7c0bc;
  if ((targetFlags & 2) != 0) {
    *(undefined *)(*(int *)text + *(int *)(*(int *)text + -0xc)) = *PTR__S_terminal_a7b7c0b8;
    _fprintf((FILE *)(stdFiles + 0x58),"%s",*(undefined4 *)text);
    return;
  }
  return;
}

/* __ZN13TInfoSinkBase6appendERKSbIcSt11char_traitsIcE14pool_allocatorIcEE @ 0x97b8ca78 (244 bytes) */
int __ZN13TInfoSinkBase6appendERKSbIcSt11char_traitsIcE14pool_allocatorIcEE(this, text)
  void *this;
  unsigned char * text;
{
  uint targetFlags;
  undefined *stdFiles;
  uint capacity;
  ulong length;
  int textChars;
  char *textPtr;
  
  targetFlags = *(uint *)((int)this + 4);
  if ((targetFlags & 4) != 0) {
    textChars = *(int *)(text + 4);
    capacity = *(uint *)(*(int *)this + -8);
    if (capacity < *(int *)(*(int *)this + -0xc) + *(int *)(textChars + -0xc) + 2U) {
      __ZNSs7reserveEm(this,capacity + (capacity >> 1));
      textChars = *(int *)(text + 4);
    }
    *(undefined1 *)(textChars + *(int *)(textChars + -0xc)) = *DAT_a7b7b720;
    textPtr = *(char **)(text + 4);
    length = _strlen(textPtr);
    __ZNSs6appendEPKcm(this,textPtr,length);
    targetFlags = *(uint *)((int)this + 4);
  }
  stdFiles = PTR_DAT_a7b7c0bc;
  if ((targetFlags & 2) != 0) {
    *(undefined1 *)(*(int *)(text + 4) + *(int *)(*(int *)(text + 4) + -0xc)) = *DAT_a7b7b720;
    _fprintf((FILE *)(stdFiles + 0x58),"%s",*(undefined4 *)(text + 4));
    return;
  }
  return;
}

/* TIntermediate__addSymbol @ 0x97b8cb6c (376 bytes) */
int TIntermediate__addSymbol(this, id, text, type, line)
  unsigned char * this;
  int id;
  unsigned char * text;
  unsigned char * type;
  int line;
{
  int stringAllocator;
  int atomicStore;
  int emptyStringRep;
  uint typeSizeBits;
  uint typeQualifierBits;
  uint typeBasicTypeBits;
  uint typeMatrixBit;
  undefined *intermSymbolVtable;
  int typeArraySize;
  uint oldTypeBits;
  int *emptyRepRefCount;
  unsigned char * this_00;
  int *a0;
  int typeWord20;
  int typeWord1c;
  int typeStructureSize;
  int typeWord14;
  int typeTypeName;
  int typeFieldName;
  int typeStructure;
  char reservation;
  byte cr0Reg;
  
  this_00 = (unsigned char *)GetGlobalPoolAllocator();
  a0 = (int *)TPoolAllocator__allocate(this_00,0x3c);
  a0[1] = 0;
  *a0 = (int)&PTR_getLine_a7b7cf90;
  typeArraySize = *(int *)(type + 4);
  typeStructure = *(int *)(type + 8);
  typeFieldName = *(int *)(type + 0xc);
  typeTypeName = *(int *)(type + 0x10);
  typeWord14 = *(int *)(type + 0x14);
  typeStructureSize = *(int *)(type + 0x18);
  typeWord1c = *(int *)(type + 0x1c);
  typeWord20 = *(int *)(type + 0x20);
  a0[2] = (int)&PTR___ZN5TTypeD1Ev_a7b7cff8;
  a0[3] = typeArraySize;
  a0[4] = typeStructure;
  a0[5] = typeFieldName;
  a0[6] = typeTypeName;
  a0[7] = typeWord14;
  a0[8] = typeStructureSize;
  a0[9] = typeWord1c;
  a0[10] = typeWord20;
  oldTypeBits = a0[0xb];
  typeQualifierBits = *(uint *)(type + 0x24) & 0xfe000000;
  a0[0xb] = typeQualifierBits | oldTypeBits & 0x1ffffff;
  typeBasicTypeBits = (*(uint *)(type + 0x24) >> 0x13 & 0x3f) << 0x13;
  a0[0xb] = typeBasicTypeBits | typeQualifierBits | oldTypeBits & 0x7ffff;
  typeSizeBits = *(uint *)(type + 0x24) & 0x7f800;
  a0[0xb] = typeSizeBits | typeBasicTypeBits | typeQualifierBits | oldTypeBits & 0x7ff;
  typeMatrixBit = (*(uint *)(type + 0x24) >> 10 & 1) << 10;
  a0[0xb] = typeMatrixBit | typeSizeBits | typeBasicTypeBits | typeQualifierBits | oldTypeBits & 0x3ff;
  intermSymbolVtable = PTR_vtable_a7b7c0dc;
  emptyStringRep = DAT_a7b7b9b8;
  a0[0xb] = (*(uint *)(type + 0x24) >> 9 & 1) << 9 |
            typeMatrixBit | typeSizeBits | typeBasicTypeBits | typeQualifierBits | oldTypeBits & 0x1ff;
  emptyRepRefCount = (int *)(emptyStringRep + 8);
  *a0 = (int)(intermSymbolVtable + 8);
  a0[0xc] = id;
  do {
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(*emptyRepRefCount + 1,0,emptyRepRefCount);
      *emptyRepRefCount = atomicStore;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  stringAllocator = GetGlobalPoolAllocator();
  a0[0xd] = stringAllocator;
  a0[0xe] = emptyStringRep + 0xc;
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6assignERKS3_(a0 + 0xd,text);
  (**(code **)(*a0 + 4))(a0,line);
  return a0;
}

/* TIntermediate__addBinaryMath @ 0x97b8cce4 (2288 bytes) */
int TIntermediate__addBinaryMath(this, op, intermTyped1, intermTyped2, line, symbolTable)
  unsigned char * this;
  int op;
  int *intermTyped1;
  int *intermTyped2;
  int line;
  unsigned char * symbolTable;
{
  int *foldResult;
  int *rightConstCopy;
  code *foldFn;
  int constantSize;
  int nodeVtable;
  int leftAggregate;
  int rightAggregate;
  int leftConstantUnion;
  bool needsConversion;
  bool bothOperandsConst;
  bool operandTypesMatch;
  bool typeTemp3Live;
  bool typeTemp1Constructed;
  bool typeTemp2Live;
  bool typeTemp1Live;
  bool operandInvalid;
  undefined *intermBinaryVtable;
  uint oldTypeBits;
  int *rightOperand;
  unsigned char * this_00;
  int *a0;
  int promoteResult;
  int rightConstantUnion;
  unsigned char * pTVar10;
  int *leftConstCopy;
  unsigned char * pTVar12;
  unsigned char * pTVar13;
  unsigned char * a0_00;
  unsigned char * a2;
  undefined4 a3;
  undefined4 a4;
  code *setOperandFn;
  undefined **stackType;
  undefined4 stackTypeArraySize;
  int stackTypeStructure;
  undefined4 stackTypeFieldName;
  undefined4 stackTypeTypeName;
  undefined4 stackTypeWord14;
  undefined4 stackTypeStructureSize;
  undefined4 stackTypeWord1c;
  undefined4 stackTypeWord20;
  uint stackTypeBits;
  undefined **typeTemp1 [2];
  int typeTemp1Structure;
  uint typeTemp1Bits;
  undefined **typeTemp2 [2];
  int typeTemp2Structure;
  uint typeTemp2Bits;
  undefined **typeTemp3 [2];
  int typeTemp3Structure;
  uint typeTemp3Bits;
  undefined **typeTemp3Alt [9];
  uint typeTemp3AltBits;
  
  if (op - 0x13U < 0x1a) {
    switch(op) {
    case 0x13:
    case 0x14:
    case 0x15:
    case 0x16:
      operandInvalid = false;
      (**(code **)(*intermTyped1 + 0x38))(&stackType,intermTyped1);
      typeTemp1Constructed = false;
      if ((stackTypeBits >> 0x13 & 0x3f) == 0xe) {
LAB_97b8cff8:
        operandInvalid = true;
        if (typeTemp1Constructed) goto LAB_97b8d008;
      }
      else {
        (**(code **)(*intermTyped1 + 0x38))(typeTemp1,intermTyped1);
        typeTemp1Constructed = true;
        if ((typeTemp1Bits >> 0x13 & 0x3f) == 3) goto LAB_97b8cff8;
LAB_97b8d008:
        typeTemp1[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
      }
      goto LAB_97b8d01c;
    default:
      goto switchD_97b8cd3c_default;
    case 0x21:
    case 0x22:
    case 0x23:
    case 0x24:
      operandInvalid = false;
      typeTemp1Live = false;
      typeTemp2Live = false;
      (**(code **)(*intermTyped1 + 0x38))
                (&stackType,intermTyped1,intermTyped1,intermTyped2,line,symbolTable,(op - 0x13U) * 4);
      typeTemp3Live = false;
      if ((stackTypeBits & 0x400) == 0) {
        typeTemp1Live = true;
        (**(code **)(*intermTyped1 + 0x38))(typeTemp1,intermTyped1);
        if ((typeTemp1Bits & 0x200) != 0) goto LAB_97b8ce68;
        typeTemp2Live = true;
        (**(code **)(*intermTyped1 + 0x38))(typeTemp2,intermTyped1);
        if ((1 < (int)(typeTemp2Bits << 0xd | typeTemp2Bits >> 0x13) >> 0x18) && ((typeTemp2Bits & 0x400) == 0))
        goto LAB_97b8ce68;
        typeTemp3Live = true;
        (**(code **)(*intermTyped1 + 0x38))(typeTemp3,intermTyped1);
        if ((typeTemp3Bits >> 0x13 & 0x3f) == 0xe) goto LAB_97b8ce68;
      }
      else {
LAB_97b8ce68:
        operandInvalid = true;
        if (!typeTemp3Live) break;
      }
      typeTemp3[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
      break;
    case 0x2a:
    case 0x2b:
    case 0x2c:
      operandInvalid = false;
      typeTemp1Live = false;
      typeTemp2Live = false;
      (**(code **)(*intermTyped1 + 0x38))(&stackType,intermTyped1);
      typeTemp3Live = false;
      if ((stackTypeBits >> 0x13 & 0x3f) == 3) {
        typeTemp1Live = true;
        (**(code **)(*intermTyped1 + 0x38))(typeTemp1,intermTyped1);
        if ((typeTemp1Bits & 0x400) != 0) goto LAB_97b8cf4c;
        typeTemp2Live = true;
        (**(code **)(*intermTyped1 + 0x38))(typeTemp2,intermTyped1);
        if ((typeTemp2Bits & 0x200) != 0) goto LAB_97b8cf4c;
        typeTemp3Live = true;
        (**(code **)(*intermTyped1 + 0x38))(typeTemp3Alt,intermTyped1);
        if ((1 < (int)(typeTemp3AltBits << 0xd | typeTemp3AltBits >> 0x13) >> 0x18) && ((typeTemp3AltBits & 0x400) == 0))
        goto LAB_97b8cf4c;
LAB_97b8cf5c:
        typeTemp3Alt[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
      }
      else {
LAB_97b8cf4c:
        operandInvalid = true;
        if (typeTemp3Live) goto LAB_97b8cf5c;
      }
    }
    if (typeTemp2Live) {
      typeTemp2[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
    }
    if (typeTemp1Live) {
      typeTemp1[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
    }
LAB_97b8d01c:
    stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
    if (operandInvalid) {
      return (int *)0x0;
    }
  }
switchD_97b8cd3c_default:
  needsConversion = false;
  (**(code **)(*intermTyped1 + 0x38))(&stackType,intermTyped1);
  typeTemp1Constructed = false;
  if (stackTypeStructure == 0) {
LAB_97b8d08c:
    needsConversion = true;
    if (typeTemp1Constructed) goto LAB_97b8d098;
  }
  else {
    (**(code **)(*intermTyped2 + 0x38))(typeTemp1,intermTyped2);
    typeTemp1Constructed = true;
    if (typeTemp1Structure == 0) goto LAB_97b8d08c;
LAB_97b8d098:
    typeTemp1[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  }
  stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  if (needsConversion) {
    (**(code **)(*intermTyped1 + 0x38))(typeTemp2,intermTyped1);
    rightOperand = (int *)((int (*)())TIntermediate__addConversion)(this,op,typeTemp2,intermTyped2);
    typeTemp2[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
    if (rightOperand == (int *)0x0) {
      (**(code **)(*intermTyped2 + 0x38))(typeTemp2,intermTyped2);
      intermTyped1 = (int *)((int (*)())TIntermediate__addConversion)(this,op,typeTemp2,intermTyped1);
      rightOperand = intermTyped2;
      if (intermTyped1 == (int *)0x0) {
        return (int *)0x0;
      }
    }
  }
  else {
    (**(code **)(*intermTyped1 + 0x38))(typeTemp2,intermTyped1);
    (**(code **)(*intermTyped2 + 0x38))(typeTemp3,intermTyped2);
    operandTypesMatch = false;
    if (((typeTemp2Bits & 0x1fffe00) == (typeTemp3Bits & 0x1fffe00)) && (typeTemp2Structure == typeTemp3Structure)) {
      operandTypesMatch = true;
    }
    typeTemp3[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
    rightOperand = intermTyped2;
    if (!operandTypesMatch) {
      return (int *)0x0;
    }
  }
  typeTemp2[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  this_00 = (unsigned char *)GetGlobalPoolAllocator();
  a0 = (int *)TPoolAllocator__allocate(this_00,0x3c);
  stackTypeBits = stackTypeBits & 0x1ff | 0x80800;
  stackTypeArraySize = 0;
  stackTypeFieldName = 0;
  stackTypeTypeName = 0;
  stackTypeWord14 = 0;
  stackTypeStructureSize = 0;
  stackTypeWord1c = 0;
  stackTypeWord20 = 0;
  stackTypeStructure = 0;
  a0[1] = 0;
  *a0 = (int)&PTR_getLine_a7b7cf90;
  a0[3] = 0;
  a0[4] = 0;
  a0[5] = 0;
  a0[6] = 0;
  a0[7] = 0;
  a0[8] = 0;
  a0[2] = (int)&PTR___ZN5TTypeD1Ev_a7b7cff8;
  a0[9] = 0;
  a0[10] = 0;
  oldTypeBits = a0[0xb];
  a0[0xb] = oldTypeBits & 0x1ffffff;
  a0[0xb] = oldTypeBits & 0x7ffff | 0x80000;
  a0[0xb] = oldTypeBits & 0x7ff | 0x80800;
  a0[0xb] = oldTypeBits & 0x3ff | 0x80800;
  intermBinaryVtable = PTR_vtable_a7b7c0d8;
  a0[0xb] = oldTypeBits & 0x1ff | 0x80800;
  stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  a0[0xc] = op;
  *a0 = (int)(intermBinaryVtable + 8);
  if (line == 0) {
    line = (**(code **)*rightOperand)(rightOperand);
  }
  (**(code **)(*a0 + 4))(a0,line);
  (**(code **)(*a0 + 0x60))(a0,intermTyped1);
  (**(code **)(*a0 + 100))(a0,rightOperand);
  promoteResult = (**(code **)(*a0 + 0x5c))(a0,*(undefined4 *)this);
  if (promoteResult == 0) {
    return (int *)0x0;
  }
  leftConstantUnion = (**(code **)(*intermTyped1 + 0x18))(intermTyped1);
  rightConstantUnion = (**(code **)(*rightOperand + 0x18))(rightOperand);
  pTVar10 = (unsigned char *)0x0;
  if (leftConstantUnion != 0) {
    pTVar10 = (unsigned char *)(**(code **)(*intermTyped1 + 0x18))(intermTyped1);
    leftConstCopy = (int *)TIntermediate__copyConstUnion(this,pTVar10);
    pTVar10 = (unsigned char *)(**(code **)(*leftConstCopy + 0x18))(leftConstCopy);
  }
  pTVar12 = (unsigned char *)0x0;
  if (rightConstantUnion != 0) {
    pTVar12 = (unsigned char *)(**(code **)(*rightOperand + 0x18))(rightOperand);
    rightConstCopy = (int *)TIntermediate__copyConstUnion(this,pTVar12);
    pTVar12 = (unsigned char *)(**(code **)(*rightConstCopy + 0x18))(rightConstCopy);
  }
  bothOperandsConst = false;
  (**(code **)(*rightOperand + 0x38))(&stackType,rightOperand);
  if (stackTypeBits >> 0x19 == 2) {
    (**(code **)(*intermTyped1 + 0x38))(typeTemp1,intermTyped1);
    bothOperandsConst = typeTemp1Bits >> 0x19 == 2;
    typeTemp1[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  }
  stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  if (bothOperandsConst) {
    rightAggregate = (**(code **)(*rightOperand + 0x1c))(rightOperand);
    if (rightAggregate != 0) {
      pTVar13 = (unsigned char *)(**(code **)(*rightOperand + 0x1c))(rightOperand);
      pTVar12 = (unsigned char *)TIntermediate__changeAggrToTempConst(this,pTVar13,symbolTable,line);
      if (*(int *)(pTVar12 + 0x30) == 0) {
        return (int *)0x0;
      }
    }
    leftAggregate = (**(code **)(*intermTyped1 + 0x1c))(intermTyped1);
    if (leftAggregate != 0) {
      pTVar13 = (unsigned char *)(**(code **)(*intermTyped1 + 0x1c))(intermTyped1);
      pTVar10 = (unsigned char *)TIntermediate__changeAggrToTempConst(this,pTVar13,symbolTable,line);
      if (*(int *)(pTVar10 + 0x30) == 0) {
        return (int *)0x0;
      }
    }
  }
  if (pTVar10 == (unsigned char *)0x0) {
    if (pTVar12 == (unsigned char *)0x0) {
      return a0;
    }
  }
  else {
    if (pTVar12 == (unsigned char *)0x0) {
      nodeVtable = *a0;
      pTVar12 = (unsigned char *)TIntermediate__copyConstUnion(this,pTVar10);
      setOperandFn = *(code **)(nodeVtable + 0x60);
      goto LAB_97b8d618;
    }
    constantSize = (**(code **)(*(int *)pTVar10 + 0x4c))(pTVar10);
    if ((constantSize == 1) && (constantSize = (**(code **)(*(int *)pTVar12 + 0x4c))(pTVar12), 1 < constantSize)) {
      a3 = *(undefined4 *)this;
      foldFn = *(code **)(*(int *)pTVar12 + 0x5c);
      a4 = 0;
      a0_00 = pTVar12;
      a2 = pTVar10;
    }
    else {
      a3 = *(undefined4 *)this;
      foldFn = *(code **)(*(int *)pTVar10 + 0x5c);
      a4 = 1;
      a0_00 = pTVar10;
      a2 = pTVar12;
    }
    foldResult = (int *)(*foldFn)(a0_00,a0[0xc],a2,a3,a4);
    if (foldResult != (int *)0x0) {
      return foldResult;
    }
    (**(code **)(*a0 + 0x60))(a0,pTVar10);
  }
  setOperandFn = *(code **)(*a0 + 100);
LAB_97b8d618:
  (*setOperandFn)(a0,pTVar12);
  return a0;
}

/* TIntermediate__addAssign @ 0x97b8d63c (640 bytes) */
int TIntermediate__addAssign(this, op, intermTyped1, intermTyped2, line)
  unsigned char * this;
  int op;
  int *intermTyped1;
  int *intermTyped2;
  int line;
{
  int promoteResult;
  int convertedRight;
  undefined *intermBinaryVtable;
  uint oldTypeBits;
  unsigned char * this_00;
  int *a0;
  int rightConstUnion;
  unsigned char * rightConstUnionNode;
  int *result;
  undefined **stackType;
  undefined4 stackTypeArraySize;
  undefined4 stackTypeStructure;
  undefined4 stackTypeFieldName;
  undefined4 stackTypeTypeName;
  undefined4 stackTypeWord14;
  undefined4 stackTypeStructureSize;
  undefined4 stackTypeWord1c;
  undefined4 stackTypeWord20;
  uint stackTypeBits;
  
  this_00 = (unsigned char *)GetGlobalPoolAllocator();
  a0 = (int *)TPoolAllocator__allocate(this_00,0x3c);
  stackTypeBits = stackTypeBits & 0x1ff | 0x80800;
  stackTypeArraySize = 0;
  stackTypeFieldName = 0;
  stackTypeTypeName = 0;
  stackTypeWord14 = 0;
  stackTypeStructureSize = 0;
  stackTypeWord1c = 0;
  stackTypeWord20 = 0;
  stackTypeStructure = 0;
  a0[1] = 0;
  *a0 = (int)&PTR_getLine_a7b7cf90;
  a0[3] = 0;
  a0[4] = 0;
  a0[5] = 0;
  a0[6] = 0;
  a0[7] = 0;
  a0[8] = 0;
  a0[2] = (int)&PTR___ZN5TTypeD1Ev_a7b7cff8;
  a0[9] = 0;
  a0[10] = 0;
  oldTypeBits = a0[0xb];
  a0[0xb] = oldTypeBits & 0x1ffffff;
  a0[0xb] = oldTypeBits & 0x7ffff | 0x80000;
  a0[0xb] = oldTypeBits & 0x7ff | 0x80800;
  a0[0xb] = oldTypeBits & 0x3ff | 0x80800;
  intermBinaryVtable = PTR_vtable_a7b7c0d8;
  a0[0xb] = oldTypeBits & 0x1ff | 0x80800;
  stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  *a0 = (int)(intermBinaryVtable + 8);
  a0[0xc] = op;
  if (line == 0) {
    line = (**(code **)*intermTyped1)(intermTyped1);
  }
  (**(code **)(*a0 + 4))(a0,line);
  rightConstUnion = (**(code **)(*intermTyped2 + 0x18))(intermTyped2);
  if (rightConstUnion != 0) {
    rightConstUnionNode = (unsigned char *)(**(code **)(*intermTyped2 + 0x18))(intermTyped2);
    intermTyped2 = (int *)TIntermediate__copyConstUnion(this,rightConstUnionNode);
    if (intermTyped2 == (int *)0x0) {
      return (int *)0x0;
    }
  }
  (**(code **)(*intermTyped1 + 0x38))(&stackType,intermTyped1);
  convertedRight = ((int (*)())TIntermediate__addConversion)(this,op,&stackType,intermTyped2);
  stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  result = (int *)0x0;
  if (convertedRight != 0) {
    (**(code **)(*a0 + 0x60))(a0,intermTyped1);
    (**(code **)(*a0 + 100))(a0,convertedRight);
    promoteResult = (**(code **)(*a0 + 0x5c))(a0,*(undefined4 *)this);
    result = (int *)0x0;
    if (promoteResult != 0) {
      result = a0;
    }
  }
  return result;
}

/* TIntermediate__addIndex @ 0x97b8d8bc (460 bytes) */
int TIntermediate__addIndex(this, op, intermTyped1, intermTyped2, line)
  unsigned char * this;
  int op;
  undefined4 intermTyped1;
  undefined4 *intermTyped2;
  int line;
{
  undefined *intermBinaryVtable;
  uint oldTypeBits;
  unsigned char * this_00;
  int *a0;
  
  this_00 = (unsigned char *)GetGlobalPoolAllocator();
  a0 = (int *)TPoolAllocator__allocate(this_00,0x3c);
  a0[1] = 0;
  *a0 = (int)&PTR_getLine_a7b7cf90;
  a0[3] = 0;
  a0[4] = 0;
  a0[5] = 0;
  a0[6] = 0;
  a0[7] = 0;
  a0[8] = 0;
  a0[2] = (int)&PTR___ZN5TTypeD1Ev_a7b7cff8;
  a0[9] = 0;
  a0[10] = 0;
  oldTypeBits = a0[0xb];
  a0[0xb] = oldTypeBits & 0x1ffffff;
  a0[0xb] = oldTypeBits & 0x7ffff | 0x80000;
  a0[0xb] = oldTypeBits & 0x7ff | 0x80800;
  a0[0xb] = oldTypeBits & 0x3ff | 0x80800;
  intermBinaryVtable = PTR_vtable_a7b7c0d8;
  a0[0xb] = oldTypeBits & 0x1ff | 0x80800;
  a0[0xc] = op;
  *a0 = (int)(intermBinaryVtable + 8);
  if (line == 0) {
    line = (**(code **)*intermTyped2)(intermTyped2);
  }
  (**(code **)(*a0 + 4))(a0,line);
  (**(code **)(*a0 + 0x60))(a0,intermTyped1);
  (**(code **)(*a0 + 100))(a0,intermTyped2);
  return a0;
}

/* TIntermediate__addUnaryMath @ 0x97b8da88 (104 bytes) */
int TIntermediate__addUnaryMath(this, op, intermNode, sourceLoc, symbolTable, scratchR8, scratchR9)
  unsigned char * this;
  int op;
  int *intermNode;
  uint sourceLoc;
  unsigned char * symbolTable;
  undefined4 scratchR8;
  uint scratchR9;
{
  uint oldTypeBits;
  uint lineInString;
  int promoteResult;
  int constantUnionNode;
  int childAggregate;
  int childConstantUnion;
  bool typeTemp1Live;
  undefined *oldRefCount;
  undefined *atomicStore;
  bool typeTemp4Live;
  bool typeTemp3Live;
  bool typeTemp2Live;
  bool operandInvalid;
  undefined **refCountPtr;
  uint nominalSize;
  undefined *intermUnaryVtable;
  int *a1;
  uint isMatrix;
  uint isArray;
  int targetBasicType;
  unsigned char * pTVar12;
  unsigned char * pTVar13;
  int *a0;
  unsigned char * this_00;
  int *a0_00;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  undefined4 extraout_r4_02;
  undefined4 extraout_r4_03;
  undefined4 scratchR4;
  undefined4 extraout_r4_04;
  undefined4 extraout_r4_05;
  unsigned char * a4;
  void *this_01;
  char reservation;
  byte cr0Flags;
  undefined **stackType;
  undefined4 stackTypeArraySize;
  undefined4 stackTypeStructure;
  undefined4 stackTypeFieldName;
  char stackTypeTailBytes [20];
  uint stackTypeBits;
  undefined **typeTemp1 [8];
  unsigned char aaStack_d0 [4];
  uint typeTemp1Bits;
  undefined **typeTemp2 [9];
  uint typeTemp2Bits;
  undefined **typeTemp3 [9];
  uint typeTemp3Bits;
  undefined **typeTemp4 [9];
  uint typeTemp4Bits;
  
  nominalSize = sourceLoc;
  a4 = symbolTable;
  a1 = (int *)(**(code **)(*intermNode + 0x14))
                        (intermNode,op,intermNode,sourceLoc,symbolTable,scratchR8,scratchR9);
  if (a1 == (int *)0x0) {
    this_01 = *(void **)this;
                    
    ((int (*)())__ZN13TInfoSinkBase6appendEPKc)(this_01,"INTERNAL ERROR: ");
    lineInString = sourceLoc & 0xffff;
    cr0Flags = (lineInString == 0) << 1;
    if (lineInString == 0) {
      _sprintf(stackTypeTailBytes,"%d:? ",(int)sourceLoc >> 0x10);
    }
    else {
      _sprintf(stackTypeTailBytes,"%d:%d",(int)sourceLoc >> 0x10,lineInString);
    }
    __ZNSsC1EPKcRKSaIcE(&stackType,stackTypeTailBytes,aaStack_d0);
    *(undefined *)((int)stackType + (int)stackType[-3]) = *PTR__S_terminal_a7b7c0b8;
    ((int (*)())__ZN13TInfoSinkBase6appendEPKc)(this_01,(char *)stackType);
    refCountPtr = stackType + -1;
    do {
      oldRefCount = *refCountPtr;
      if (reservation != '\0') {
        atomicStore = (undefined *)storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
        *refCountPtr = atomicStore;
        cr0Flags = 2;
      }
    } while (!(bool)(cr0Flags >> 1 & 1));
    if ((int)oldRefCount < 1) {
      __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(stackType + -3),stackTypeTailBytes);
    }
    ((int (*)())__ZN13TInfoSinkBase6appendEPKc)(this_01,": ");
    ((int (*)())__ZN13TInfoSinkBase6appendEPKc)(this_01,"Bad type in AddUnaryMath");
    ((int (*)())__ZN13TInfoSinkBase6appendEPKc)(this_01,"\n");
    return (int *)0x0;
  }
  if (op == 6) {
    operandInvalid = false;
    typeTemp2Live = false;
    typeTemp3Live = false;
    typeTemp4Live = false;
    (**(code **)(*a1 + 0x38))(&stackType,a1);
    scratchR4 = extraout_r4_00;
    if ((stackTypeBits >> 0x13 & 0x3f) == 3) {
      typeTemp2Live = true;
      (**(code **)(*a1 + 0x38))(typeTemp2,a1);
      scratchR4 = extraout_r4_01;
      if ((typeTemp2Bits & 0x400) != 0) goto LAB_97b8dcfc;
      typeTemp3Live = true;
      (**(code **)(*a1 + 0x38))(typeTemp3,a1);
      scratchR4 = extraout_r4_02;
      if ((typeTemp3Bits & 0x200) != 0) goto LAB_97b8dcfc;
      typeTemp4Live = true;
      (**(code **)(*a1 + 0x38))(typeTemp4,a1);
      scratchR4 = extraout_r4_03;
      if ((1 < (int)(typeTemp4Bits << 0xd | typeTemp4Bits >> 0x13) >> 0x18) && ((typeTemp4Bits & 0x400) == 0))
      goto LAB_97b8dcfc;
LAB_97b8dd0c:
      typeTemp4[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
    }
    else {
LAB_97b8dcfc:
      operandInvalid = true;
      if (typeTemp4Live) goto LAB_97b8dd0c;
    }
    if (typeTemp3Live) {
      typeTemp3[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
    }
    if (typeTemp2Live) {
      typeTemp2[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
    }
LAB_97b8ddc8:
    stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
    if (operandInvalid) {
      return (int *)0x0;
    }
  }
  else {
    scratchR4 = extraout_r4;
    if (op < 7) {
      if (op == 5) {
LAB_97b8dd4c:
        operandInvalid = false;
        (**(code **)(*a1 + 0x38))(&stackType,a1);
        typeTemp1Live = false;
        scratchR4 = extraout_r4_04;
        if ((stackTypeBits >> 0x13 & 0x3f) == 0xe) {
LAB_97b8dda4:
          operandInvalid = true;
          if (typeTemp1Live) goto LAB_97b8ddb4;
        }
        else {
          (**(code **)(*a1 + 0x38))(typeTemp1,a1);
          typeTemp1Live = true;
          scratchR9 = typeTemp1Bits & 0x200;
          scratchR4 = extraout_r4_05;
          if (scratchR9 != 0) goto LAB_97b8dda4;
LAB_97b8ddb4:
          typeTemp1[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
        }
        goto LAB_97b8ddc8;
      }
    }
    else if (op - 9U < 4) goto LAB_97b8dd4c;
  }
  if (op == 0x67) {
    targetBasicType = 3;
  }
  else if (op < 0x68) {
    if (op != 0x66) goto LAB_97b8decc;
    targetBasicType = 2;
  }
  else {
    if (op != 0x68) goto LAB_97b8decc;
    targetBasicType = 1;
  }
  nominalSize = (**(code **)(*a1 + 0x48))(a1,scratchR4,intermNode,nominalSize,a4,scratchR8,scratchR9);
  isMatrix = (**(code **)(*a1 + 0x50))(a1);
  isArray = (**(code **)(*a1 + 0x54))(a1);
  stackTypeBits = (isArray & 1) << 9 |
             (isMatrix & 1) << 10 | (nominalSize & 0xff) << 0xb | targetBasicType << 0x13 | stackTypeBits & 0x1ff;
  stackTypeTailBytes[0x10] = '\0';
  stackTypeTailBytes[0x11] = '\0';
  stackTypeTailBytes[0x12] = '\0';
  stackTypeTailBytes[0x13] = '\0';
  stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  stackTypeArraySize = 0;
  stackTypeStructure = 0;
  stackTypeFieldName = 0;
  stackTypeTailBytes[0] = '\0';
  stackTypeTailBytes[1] = '\0';
  stackTypeTailBytes[2] = '\0';
  stackTypeTailBytes[3] = '\0';
  stackTypeTailBytes[4] = '\0';
  stackTypeTailBytes[5] = '\0';
  stackTypeTailBytes[6] = '\0';
  stackTypeTailBytes[7] = '\0';
  stackTypeTailBytes[8] = '\0';
  stackTypeTailBytes[9] = '\0';
  stackTypeTailBytes[10] = '\0';
  stackTypeTailBytes[0xb] = '\0';
  stackTypeTailBytes[0xc] = '\0';
  stackTypeTailBytes[0xd] = '\0';
  stackTypeTailBytes[0xe] = '\0';
  stackTypeTailBytes[0xf] = '\0';
  a1 = (int *)((int (*)())TIntermediate__addConversion)(this,op,&stackType,a1);
  stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  if (a1 == (int *)0x0) {
    return (int *)0x0;
  }
LAB_97b8decc:
  if (2 < op - 0x66U) {
    childConstantUnion = (**(code **)(*a1 + 0x18))(a1);
    if (childConstantUnion != 0) {
      pTVar12 = (unsigned char *)(**(code **)(*a1 + 0x18))(a1);
      a1 = (int *)TIntermediate__copyConstUnion(this,pTVar12);
    }
    childAggregate = (**(code **)(*a1 + 0x1c))(a1);
    if (childAggregate != 0) {
      (**(code **)(*a1 + 0x38))(&stackType,a1);
      stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
      if (stackTypeBits >> 0x19 == 2) {
        pTVar13 = (unsigned char *)(**(code **)(*a1 + 0x1c))(a1);
        a1 = (int *)TIntermediate__changeAggrToTempConst(this,pTVar13,symbolTable,sourceLoc);
        constantUnionNode = (**(code **)(*a1 + 0x18))(a1);
        if (*(int *)(constantUnionNode + 0x30) == 0) {
          return (int *)0x0;
        }
      }
    }
    a0 = (int *)(**(code **)(*a1 + 0x18))(a1);
    this_00 = (unsigned char *)GetGlobalPoolAllocator();
    a0_00 = (int *)TPoolAllocator__allocate(this_00,0x38);
    stackTypeBits = stackTypeBits & 0x1ff | 0x80800;
    stackTypeArraySize = 0;
    stackTypeStructure = 0;
    stackTypeFieldName = 0;
    stackTypeTailBytes[0] = '\0';
    stackTypeTailBytes[1] = '\0';
    stackTypeTailBytes[2] = '\0';
    stackTypeTailBytes[3] = '\0';
    stackTypeTailBytes[4] = '\0';
    stackTypeTailBytes[5] = '\0';
    stackTypeTailBytes[6] = '\0';
    stackTypeTailBytes[7] = '\0';
    stackTypeTailBytes[8] = '\0';
    stackTypeTailBytes[9] = '\0';
    stackTypeTailBytes[10] = '\0';
    stackTypeTailBytes[0xb] = '\0';
    stackTypeTailBytes[0xc] = '\0';
    stackTypeTailBytes[0xd] = '\0';
    stackTypeTailBytes[0xe] = '\0';
    stackTypeTailBytes[0xf] = '\0';
    stackTypeTailBytes[0x10] = '\0';
    stackTypeTailBytes[0x11] = '\0';
    stackTypeTailBytes[0x12] = '\0';
    stackTypeTailBytes[0x13] = '\0';
    *a0_00 = (int)&PTR_getLine_a7b7cf90;
    a0_00[1] = 0;
    a0_00[3] = 0;
    a0_00[4] = 0;
    a0_00[5] = 0;
    a0_00[6] = 0;
    a0_00[7] = 0;
    a0_00[8] = 0;
    a0_00[2] = (int)&PTR___ZN5TTypeD1Ev_a7b7cff8;
    a0_00[9] = 0;
    a0_00[10] = 0;
    oldTypeBits = a0_00[0xb];
    a0_00[0xb] = oldTypeBits & 0x1ffffff;
    a0_00[0xb] = oldTypeBits & 0x7ffff | 0x80000;
    a0_00[0xb] = oldTypeBits & 0x7ff | 0x80800;
    a0_00[0xb] = oldTypeBits & 0x3ff | 0x80800;
    intermUnaryVtable = PTR_vtable_a7b7c0d4;
    a0_00[0xb] = oldTypeBits & 0x1ff | 0x80800;
    stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
    *a0_00 = (int)(intermUnaryVtable + 8);
    a0_00[0xd] = 0;
    a0_00[0xc] = op;
    if (sourceLoc == 0) {
      sourceLoc = (**(code **)*a1)(a1);
    }
    (**(code **)(*a0_00 + 4))(a0_00,sourceLoc);
    (**(code **)(*a0_00 + 0x60))(a0_00,a1);
    promoteResult = (**(code **)(*a0_00 + 0x5c))(a0_00,*(undefined4 *)this);
    a1 = (int *)0x0;
    if ((promoteResult != 0) &&
       ((a0 == (int *)0x0 ||
        (a1 = (int *)(**(code **)(*a0 + 0x5c))(a0,op,0,*(undefined4 *)this,1), a1 == (int *)0x0
        )))) {
      a1 = a0_00;
    }
  }
  return a1;
}

/* TIntermediate__setAggregateOperator @ 0x97b8e1b8 (1132 bytes) */
int TIntermediate__setAggregateOperator(this, intermNode, op, line)
  unsigned char * this;
  unsigned char * intermNode;
  undefined4 op;
  int line;
{
  int stringAllocator;
  int sequenceFinishValue;
  int emptyStringRep;
  int nameAllocator;
  unsigned int ghidra_home[8] = { this, intermNode, op, line, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  bool noLine;
  undefined *intermAggregateVtable;
  uint oldTypeBits;
  int *emptyRepRefCount;
  int *a0;
  unsigned char * poolAllocator;
  int sequenceAllocator;
  int atomicStore;
  unsigned char * this_00;
  undefined4 *sequenceFinish;
  code *getSequenceFn;
  char reservation;
  byte cr0Flags;
  unsigned char * pTStack0000001c;
  
  cr0Flags = (intermNode == (unsigned char *)0x0) << 1;
  pTStack0000001c = intermNode;
  if (intermNode == (unsigned char *)0x0) {
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    a0 = (int *)TPoolAllocator__allocate(poolAllocator,0x6c);
    a0[1] = 0;
    *a0 = (int)&PTR_getLine_a7b7cf90;
    a0[3] = 0;
    a0[4] = 0;
    a0[5] = 0;
    a0[6] = 0;
    a0[7] = 0;
    a0[8] = 0;
    a0[2] = (int)&PTR___ZN5TTypeD1Ev_a7b7cff8;
    a0[9] = 0;
    a0[10] = 0;
    oldTypeBits = a0[0xb];
    a0[0xb] = oldTypeBits & 0x1ffffff;
    a0[0xb] = oldTypeBits & 0x7ffff | 0x80000;
    a0[0xb] = oldTypeBits & 0x7ff | 0x80800;
    a0[0xb] = oldTypeBits & 0x3ff | 0x80800;
    intermAggregateVtable = PTR_vtable_a7b7c0d0;
    a0[0xb] = oldTypeBits & 0x1ff | 0x80800;
    *a0 = (int)(intermAggregateVtable + 8);
    a0[0xc] = 0;
    sequenceAllocator = GetGlobalPoolAllocator();
    a0[0x10] = 0;
    a0[0xe] = 0;
    a0[0xf] = 0;
    a0[0xd] = sequenceAllocator;
    nameAllocator = GetGlobalPoolAllocator();
    a0[0x11] = nameAllocator;
    emptyStringRep = DAT_a7b7b9b8;
    a0[0x14] = 0;
    a0[0x12] = 0;
    emptyRepRefCount = (int *)(emptyStringRep + 8);
    a0[0x13] = 0;
    do {
      if (reservation != '\0') {
        atomicStore = storeWordConditionalIndexed(*emptyRepRefCount + 1,0,emptyRepRefCount);
        *emptyRepRefCount = atomicStore;
        cr0Flags = 2;
      }
    } while (!(bool)(cr0Flags >> 1 & 1));
    stringAllocator = GetGlobalPoolAllocator();
    a0[0x16] = emptyStringRep + 0xc;
    noLine = line == 0;
    a0[0x1a] = 0;
    a0[0x15] = stringAllocator;
    a0[0x17] = 0;
  }
  else {
    a0 = (int *)(**(code **)(*(int *)intermNode + 0x1c))(intermNode);
    cr0Flags = (a0 == (int *)0x0) << 1;
    if ((a0 == (int *)0x0) || (noLine = line == 0, a0[0xc] != 0)) {
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      a0 = (int *)TPoolAllocator__allocate(poolAllocator,0x6c);
      a0[1] = 0;
      *a0 = (int)&PTR_getLine_a7b7cf90;
      a0[3] = 0;
      a0[4] = 0;
      a0[5] = 0;
      a0[6] = 0;
      a0[7] = 0;
      a0[8] = 0;
      a0[2] = (int)&PTR___ZN5TTypeD1Ev_a7b7cff8;
      a0[9] = 0;
      a0[10] = 0;
      oldTypeBits = a0[0xb];
      a0[0xb] = oldTypeBits & 0x1ffffff;
      a0[0xb] = oldTypeBits & 0x7ffff | 0x80000;
      a0[0xb] = oldTypeBits & 0x7ff | 0x80800;
      a0[0xb] = oldTypeBits & 0x3ff | 0x80800;
      intermAggregateVtable = PTR_vtable_a7b7c0d0;
      a0[0xb] = oldTypeBits & 0x1ff | 0x80800;
      *a0 = (int)(intermAggregateVtable + 8);
      a0[0xc] = 0;
      sequenceAllocator = GetGlobalPoolAllocator();
      a0[0x10] = 0;
      a0[0xe] = 0;
      a0[0xf] = 0;
      a0[0xd] = sequenceAllocator;
      nameAllocator = GetGlobalPoolAllocator();
      a0[0x11] = nameAllocator;
      emptyStringRep = DAT_a7b7b9b8;
      a0[0x14] = 0;
      a0[0x12] = 0;
      emptyRepRefCount = (int *)(emptyStringRep + 8);
      a0[0x13] = 0;
      do {
        if (reservation != '\0') {
          atomicStore = storeWordConditionalIndexed(*emptyRepRefCount + 1,0,emptyRepRefCount);
          *emptyRepRefCount = atomicStore;
          cr0Flags = 2;
        }
      } while (!(bool)(cr0Flags >> 1 & 1));
      stringAllocator = GetGlobalPoolAllocator();
      a0[0x16] = emptyStringRep + 0xc;
      a0[0x15] = stringAllocator;
      getSequenceFn = *(code **)(*a0 + 100);
      a0[0x1a] = 0;
      a0[0x17] = 0;
      this_00 = (unsigned char *)(*getSequenceFn)(a0);
      sequenceFinish = *(undefined4 **)(this_00 + 8);
      if (sequenceFinish == *(undefined4 **)(this_00 + 0xc)) {
        std__vector_TIntermNode__pool_allocator_TIntermNode______M_insert_aux
                  (this_00,sequenceFinish,&(*(unsigned int *)((unsigned char *)ghidra_home + 4)));
      }
      else {
        sequenceFinishValue = 0;
        if (sequenceFinish != (undefined4 *)0x0) {
          *sequenceFinish = pTStack0000001c;
          sequenceFinishValue = *(int *)(this_00 + 8);
        }
        *(int *)(this_00 + 8) = sequenceFinishValue + 4;
      }
      noLine = false;
      if (line == 0) {
        line = (*(code *)**(undefined4 **)pTStack0000001c)(pTStack0000001c);
        noLine = line == 0;
      }
    }
  }
  (**(code **)(*a0 + 0x60))(a0,op);
  if (!noLine) {
    (**(code **)(*a0 + 4))(a0,line);
  }
  return a0;
}

/* TIntermediate__addConversion @ 0x97b8e624 (2488 bytes) */
int TIntermediate__addConversion(this, op, type, intermTyped)
  unsigned char * this;
  int op;
  unsigned char * type;
  int *intermTyped;
{
  uint matrixBit;
  uint basicTypeBits;
  undefined4 line;
  undefined4 scratchR4;
  undefined *oldRefCount;
  undefined *atomicStore;
  bool isAggregateOnly;
  undefined **refCountPtr;
  undefined *intermUnaryVtable;
  uint oldTypeBits;
  int sourceBasicTypeOrSequence;
  uint targetBasicType;
  int *typedNodeTemp;
  unsigned char * poolAllocator;
  unsigned char * convertedValue;
  int constantUnionOrNewNode;
  int *nodeTemp;
  undefined4 constantUnion;
  uint isMatrix;
  uint isArray;
  undefined4 a1;
  undefined4 a1_00;
  undefined4 a1_01;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  unsigned char * a2;
  undefined4 scratchR7;
  undefined4 scratchR8;
  undefined4 *a6;
  unsigned char * sequenceCursor;
  char *errorText;
  undefined4 *childCursor;
  uint childBasicType;
  void *infoSink;
  char reservation;
  byte cr0Flags;
  undefined **stackType;
  int stackTypeArraySize;
  int stackTypeStructure;
  int stackTypeFieldName;
  int stackTypeTypeName;
  int stackTypeWord14;
  int stackTypeStructureSize;
  int stackTypeWord1c;
  int stackTypeWord20;
  uint stackTypeBits;
  undefined4 i2dHi;
  undefined4 *puStack_8c;
  char acStack_80 [64];
  longlong d2iScratch;
  undefined1 auStack_38 [4];
  int newNodeSlot;
  
  a2 = type;
  nodeTemp = intermTyped;
  sourceBasicTypeOrSequence = (**(code **)(*intermTyped + 0x40))(intermTyped,op,type,intermTyped);
  if (sourceBasicTypeOrSequence == 0) {
    return (int *)0x0;
  }
  if ((-1 < sourceBasicTypeOrSequence) && (sourceBasicTypeOrSequence - 5U < 8)) {
    return (int *)0x0;
  }
  (**(code **)(*intermTyped + 0x38))(&stackType,intermTyped);
  a6 = (undefined4 *)0x0;
  if (((*(uint *)(type + 0x24) & 0x1fffe00) == (stackTypeBits & 0x1fffe00)) &&
     (*(int *)(type + 8) == stackTypeStructure)) {
    a6 = (undefined4 *)0x1;
  }
  stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  if (a6 != (undefined4 *)0x0) {
    return intermTyped;
  }
  if (*(int *)(type + 8) != 0) {
    return (int *)0x0;
  }
  (**(code **)(*intermTyped + 0x38))((unsigned char *)&stackType,intermTyped,a2,nodeTemp,scratchR7,scratchR8,0);
  stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  if (stackTypeStructure != 0) {
    return (int *)0x0;
  }
  sourceBasicTypeOrSequence = (**(code **)(*(int *)type + 0x38))(type);
  if (sourceBasicTypeOrSequence != 0) {
    return (int *)0x0;
  }
  (**(code **)(*intermTyped + 0x38))((unsigned char *)&stackType,intermTyped);
  stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  if ((stackTypeBits & 0x200) != 0) {
    return (int *)0x0;
  }
  if (op == 0x67) {
    targetBasicType = 3;
  }
  else if (op < 0x68) {
    if (op != 0x66) {
LAB_97b8e794:
      targetBasicType = (**(code **)(*(int *)type + 0x20))(type);
      (**(code **)(*intermTyped + 0x38))(&stackType,intermTyped);
      if (targetBasicType == (stackTypeBits >> 0x13 & 0x3f)) {
        return intermTyped;
      }
      return (int *)0x0;
    }
    targetBasicType = 2;
  }
  else {
    if (op != 0x68) goto LAB_97b8e794;
    targetBasicType = 1;
  }
  isAggregateOnly = true;
  sourceBasicTypeOrSequence = (**(code **)(*intermTyped + 0x1c))(intermTyped);
  if (sourceBasicTypeOrSequence == 0) {
LAB_97b8e8ac:
    sourceBasicTypeOrSequence = (**(code **)(*intermTyped + 0x1c))(intermTyped);
    if (sourceBasicTypeOrSequence != 0) {
      typedNodeTemp = (int *)(**(code **)(*intermTyped + 0x1c))(intermTyped);
      sourceBasicTypeOrSequence = (**(code **)(*typedNodeTemp + 100))(typedNodeTemp);
      sequenceCursor = *(unsigned char **)(sourceBasicTypeOrSequence + 4);
      while( true ) {
        if (sequenceCursor == *(unsigned char **)(sourceBasicTypeOrSequence + 8)) {
          nodeTemp = (int *)(**(code **)(*intermTyped + 0x1c))(intermTyped);
          return nodeTemp;
        }
        poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
        convertedValue = (unsigned char *)TPoolAllocator__allocate(poolAllocator,4);
        if (targetBasicType != 2) break;
        typedNodeTemp = (int *)(**(code **)(**(int **)sequenceCursor + 0x14))(*(int **)sequenceCursor);
        (**(code **)(*typedNodeTemp + 0x38))(&stackType,typedNodeTemp);
        childBasicType = stackTypeBits >> 0x13 & 0x3f;
        stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
        if (childBasicType == 1) {
          nodeTemp = (int *)(**(code **)(**(int **)sequenceCursor + 0x14))(*(int **)sequenceCursor);
          constantUnionOrNewNode = (**(code **)(*nodeTemp + 0x18))(nodeTemp);
          d2iScratch = (longlong)(int)**(float **)(constantUnionOrNewNode + 0x30);
          *(int *)convertedValue = (int)**(float **)(constantUnionOrNewNode + 0x30);
LAB_97b8ec88:
          stackTypeBits = targetBasicType << 0x13 | stackTypeBits & 0x7ff | 0x4000000 | 0x800;
        }
        else {
          if (childBasicType != 3) {
            infoSink = *(void **)this;
            errorText = "Bad promotion node";
            targetBasicType = (**(code **)*intermTyped)(intermTyped,a1_00,a2,nodeTemp,scratchR7,scratchR8,a6);
                    
            goto override_jmp_97b8ea8c_case_0;
          }
          nodeTemp = (int *)(**(code **)(**(int **)sequenceCursor + 0x14))(*(int **)sequenceCursor);
          constantUnionOrNewNode = (**(code **)(*nodeTemp + 0x18))(nodeTemp);
          a6 = *(undefined4 **)(constantUnionOrNewNode + 0x30);
          *(undefined4 *)convertedValue = *a6;
LAB_97b8ecd8:
          stackTypeBits = targetBasicType << 0x13 | stackTypeBits & 0xfff | 0x4000000 | 0x800;
        }
LAB_97b8ed90:
        stackTypeBits = stackTypeBits & 0xfffff9ff;
        stackTypeArraySize = 0;
        stackTypeStructure = 0;
        stackTypeFieldName = 0;
        stackTypeTypeName = 0;
        stackTypeWord14 = 0;
        stackTypeStructureSize = 0;
        stackTypeWord1c = 0;
        stackTypeWord20 = 0;
        stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
        nodeTemp = (int *)(**(code **)*intermTyped)(intermTyped);
        a2 = (unsigned char *)&stackType;
        constantUnionOrNewNode = ((int (*)())TIntermediate__addConstantUnion)(this,convertedValue,(unsigned char *)&stackType,(int)nodeTemp);
        stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
        if (constantUnionOrNewNode != 0) {
          std__vector_TIntermNode__pool_allocator_TIntermNode_____erase(auStack_38,sourceBasicTypeOrSequence,sequenceCursor);
          nodeTemp = &newNodeSlot;
          a2 = sequenceCursor;
          newNodeSlot = constantUnionOrNewNode;
          std__vector_TIntermNode__pool_allocator_TIntermNode_____insert
                    (auStack_38,sourceBasicTypeOrSequence,sequenceCursor,nodeTemp);
        }
        sequenceCursor = sequenceCursor + 4;
      }
      if (targetBasicType < 3) {
        if (targetBasicType == 1) {
          typedNodeTemp = (int *)(**(code **)(**(int **)sequenceCursor + 0x14))(*(int **)sequenceCursor);
          (**(code **)(*typedNodeTemp + 0x38))(&stackType,typedNodeTemp);
          childBasicType = stackTypeBits >> 0x13 & 0x3f;
          stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
          if (childBasicType == 2) {
            nodeTemp = (int *)(**(code **)(**(int **)sequenceCursor + 0x14))(*(int **)sequenceCursor);
            constantUnionOrNewNode = (**(code **)(*nodeTemp + 0x18))(nodeTemp);
            a6 = (undefined4 *)(**(uint **)(constantUnionOrNewNode + 0x30) ^ 0x80000000);
            *(float *)convertedValue = (float)((double)CONCAT44(0x43300000,a6) - 4503601774854144.0);
          }
          else {
            if (childBasicType != 3) {
              infoSink = *(void **)this;
              errorText = "Bad promotion node";
              targetBasicType = (**(code **)*intermTyped)(intermTyped,a1,a2,nodeTemp,scratchR7,scratchR8,a6);
                    
              goto override_jmp_97b8ea8c_case_0;
            }
            nodeTemp = (int *)(**(code **)(**(int **)sequenceCursor + 0x14))
                                       (*(int **)sequenceCursor,a1,a2,nodeTemp,scratchR7,scratchR8,a6);
            constantUnionOrNewNode = (**(code **)(*nodeTemp + 0x18))(nodeTemp);
            a6 = (undefined4 *)**(undefined4 **)(constantUnionOrNewNode + 0x30);
            *(float *)convertedValue = (float)((double)CONCAT44(0x43300000,a6) - 4503599627370496.0);
          }
          i2dHi = 0x43300000;
          stackTypeBits = stackTypeBits & 0x7ff | 0x4080800;
          puStack_8c = a6;
          goto LAB_97b8ed90;
        }
      }
      else if (targetBasicType == 3) {
        typedNodeTemp = (int *)(**(code **)(**(int **)sequenceCursor + 0x14))(*(int **)sequenceCursor);
        (**(code **)(*typedNodeTemp + 0x38))(&stackType,typedNodeTemp);
        childBasicType = stackTypeBits >> 0x13 & 0x3f;
        stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
        if (childBasicType == 1) {
          nodeTemp = (int *)(**(code **)(**(int **)sequenceCursor + 0x14))(*(int **)sequenceCursor);
          constantUnionOrNewNode = (**(code **)(*nodeTemp + 0x18))(nodeTemp);
          *(uint *)convertedValue = (uint)(**(float **)(constantUnionOrNewNode + 0x30) != 0.0);
          goto LAB_97b8ec88;
        }
        if (childBasicType == 2) {
          nodeTemp = (int *)(**(code **)(**(int **)sequenceCursor + 0x14))(*(int **)sequenceCursor);
          constantUnionOrNewNode = (**(code **)(*nodeTemp + 0x18))(nodeTemp);
          constantUnionOrNewNode = **(int **)(constantUnionOrNewNode + 0x30);
          a6 = (undefined4 *)(constantUnionOrNewNode + -1);
          *(uint *)convertedValue = constantUnionOrNewNode - ((int)a6 + (uint)(constantUnionOrNewNode == 0));
          goto LAB_97b8ecd8;
        }
        infoSink = *(void **)this;
        errorText = "Bad promotion node";
        targetBasicType = (**(code **)*intermTyped)(intermTyped,a1_01,a2,nodeTemp,scratchR7,scratchR8,a6);
                    
        goto override_jmp_97b8ea8c_case_0;
      }
      infoSink = *(void **)this;
      errorText = "Bad promotion node";
      targetBasicType = (**(code **)*intermTyped)(intermTyped);
                    
      goto override_jmp_97b8ea8c_case_0;
    }
  }
  else {
    sourceBasicTypeOrSequence = (**(code **)(*intermTyped + 0x1c))(intermTyped);
    if (*(int *)(sourceBasicTypeOrSequence + 0x30) == 2) {
      isAggregateOnly = false;
    }
    else {
      typedNodeTemp = (int *)(**(code **)(*intermTyped + 0x1c))(intermTyped);
      sourceBasicTypeOrSequence = (**(code **)(*typedNodeTemp + 100))(typedNodeTemp);
      for (childCursor = *(undefined4 **)(sourceBasicTypeOrSequence + 4); childCursor != *(undefined4 **)(sourceBasicTypeOrSequence + 8);
          childCursor = childCursor + 1) {
        typedNodeTemp = (int *)(**(code **)(*(int *)*childCursor + 0x14))((int *)*childCursor);
        constantUnionOrNewNode = (**(code **)(*typedNodeTemp + 0x18))(typedNodeTemp);
        if (constantUnionOrNewNode == 0) {
          isAggregateOnly = false;
        }
      }
    }
    if (isAggregateOnly) goto LAB_97b8e8ac;
  }
  sourceBasicTypeOrSequence = (**(code **)(*intermTyped + 0x18))(intermTyped);
  if (sourceBasicTypeOrSequence != 0) {
    constantUnion = (**(code **)(*intermTyped + 0x18))(intermTyped);
    nodeTemp = (int *)TIntermediate__promoteConstantUnion(this,targetBasicType,constantUnion);
    return nodeTemp;
  }
  if (targetBasicType != 2) {
    if (targetBasicType < 3) {
      if (targetBasicType == 1) {
        sourceBasicTypeOrSequence = (**(code **)(*intermTyped + 0x40))(intermTyped);
        scratchR4 = extraout_r4;
        if (sourceBasicTypeOrSequence == 2) {
          constantUnionOrNewNode = 0x10;
        }
        else {
          constantUnionOrNewNode = 0xf;
          if (sourceBasicTypeOrSequence != 3) {
            infoSink = *(void **)this;
            errorText = "Bad promotion node";
            targetBasicType = (**(code **)*intermTyped)(intermTyped);
                    
            goto override_jmp_97b8ea8c_case_0;
          }
        }
        goto LAB_97b8f1ac;
      }
    }
    else if (targetBasicType == 3) {
      sourceBasicTypeOrSequence = (**(code **)(*intermTyped + 0x40))(intermTyped);
      scratchR4 = extraout_r4_00;
      if (sourceBasicTypeOrSequence == 1) {
        constantUnionOrNewNode = 0xe;
      }
      else {
        constantUnionOrNewNode = 0xd;
        if (sourceBasicTypeOrSequence != 2) {
          infoSink = *(void **)this;
          errorText = "Bad promotion node";
          targetBasicType = (**(code **)*intermTyped)(intermTyped);
                    
          goto override_jmp_97b8ea8c_case_0;
        }
      }
      goto LAB_97b8f1ac;
    }
    infoSink = *(void **)this;
    errorText = "Bad promotion type";
    targetBasicType = (**(code **)*intermTyped)(intermTyped);
                    
override_jmp_97b8ea8c_case_0:
    ((int (*)())__ZN13TInfoSinkBase6appendEPKc)(infoSink,"INTERNAL ERROR: ");
    childBasicType = targetBasicType & 0xffff;
    cr0Flags = (childBasicType == 0) << 1;
    if (childBasicType == 0) {
      _sprintf(acStack_80,"%d:? ",(int)targetBasicType >> 0x10);
    }
    else {
      _sprintf(acStack_80,"%d:%d",(int)targetBasicType >> 0x10,childBasicType);
    }
    __ZNSsC1EPKcRKSaIcE(&stackType,acStack_80,(unsigned char *)&stackTypeTypeName);
    *(undefined *)((int)stackType + (int)stackType[-3]) = *PTR__S_terminal_a7b7c0b8;
    ((int (*)())__ZN13TInfoSinkBase6appendEPKc)(infoSink,(char *)stackType);
    refCountPtr = stackType + -1;
    do {
      oldRefCount = *refCountPtr;
      if (reservation != '\0') {
        atomicStore = (undefined *)storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
        *refCountPtr = atomicStore;
        cr0Flags = 2;
      }
    } while (!(bool)(cr0Flags >> 1 & 1));
    if ((int)oldRefCount < 1) {
      __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(stackType + -3),(unsigned char *)&stackTypeTypeName);
    }
    ((int (*)())__ZN13TInfoSinkBase6appendEPKc)(infoSink,": ");
    ((int (*)())__ZN13TInfoSinkBase6appendEPKc)(infoSink,errorText);
    ((int (*)())__ZN13TInfoSinkBase6appendEPKc)(infoSink,"\n");
    return (int *)0x0;
  }
  sourceBasicTypeOrSequence = (**(code **)(*intermTyped + 0x40))(intermTyped);
  scratchR4 = extraout_r4_01;
  if (sourceBasicTypeOrSequence == 1) {
    constantUnionOrNewNode = 0x11;
  }
  else {
    constantUnionOrNewNode = 0x12;
    if (sourceBasicTypeOrSequence != 3) {
      infoSink = *(void **)this;
      errorText = "Bad promotion node";
      targetBasicType = (**(code **)*intermTyped)(intermTyped);
                    
      goto override_jmp_97b8ea8c_case_0;
    }
  }
LAB_97b8f1ac:
  childBasicType = (**(code **)(*intermTyped + 0x48))(intermTyped,scratchR4);
  isMatrix = (**(code **)(*intermTyped + 0x50))(intermTyped);
  isArray = (**(code **)(*intermTyped + 0x54))(intermTyped);
  stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  stackTypeBits = (isArray & 1) << 9 |
             (isMatrix & 1) << 10 | (childBasicType & 0xff) << 0xb | targetBasicType << 0x13 | stackTypeBits & 0x1ff;
  stackTypeArraySize = 0;
  stackTypeStructure = 0;
  stackTypeFieldName = 0;
  stackTypeTypeName = 0;
  stackTypeWord14 = 0;
  stackTypeStructureSize = 0;
  stackTypeWord1c = 0;
  stackTypeWord20 = 0;
  poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
  nodeTemp = (int *)TPoolAllocator__allocate(poolAllocator,0x38);
  nodeTemp[1] = 0;
  *nodeTemp = (int)&PTR_getLine_a7b7cf90;
  nodeTemp[3] = stackTypeArraySize;
  nodeTemp[4] = stackTypeStructure;
  nodeTemp[5] = stackTypeFieldName;
  nodeTemp[6] = stackTypeTypeName;
  nodeTemp[7] = stackTypeWord14;
  nodeTemp[8] = stackTypeStructureSize;
  nodeTemp[2] = (int)&PTR___ZN5TTypeD1Ev_a7b7cff8;
  nodeTemp[10] = stackTypeWord20;
  nodeTemp[9] = stackTypeWord1c;
  intermUnaryVtable = PTR_vtable_a7b7c0d4;
  oldTypeBits = nodeTemp[0xb];
  childBasicType = stackTypeBits & 0xfe000000;
  nodeTemp[0xb] = childBasicType | oldTypeBits & 0x1ffffff;
  basicTypeBits = (stackTypeBits >> 0x13 & 0x3f) << 0x13;
  nodeTemp[0xb] = basicTypeBits | childBasicType | oldTypeBits & 0x7ffff;
  targetBasicType = stackTypeBits & 0x7f800;
  nodeTemp[0xb] = targetBasicType | basicTypeBits | childBasicType | oldTypeBits & 0x7ff;
  matrixBit = (stackTypeBits >> 10 & 1) << 10;
  nodeTemp[0xb] = matrixBit | targetBasicType | basicTypeBits | childBasicType | oldTypeBits & 0x3ff;
  nodeTemp[0xb] = (stackTypeBits >> 9 & 1) << 9 | matrixBit | targetBasicType | basicTypeBits | childBasicType | oldTypeBits & 0x1ff;
  nodeTemp[0xc] = constantUnionOrNewNode;
  *nodeTemp = (int)(intermUnaryVtable + 8);
  nodeTemp[0xd] = 0;
  line = (**(code **)*intermTyped)(intermTyped);
  (**(code **)(intermUnaryVtable + 0xc))(nodeTemp,line);
  (**(code **)(*nodeTemp + 0x60))(nodeTemp,intermTyped);
  return nodeTemp;
}

/* TIntermediate__growAggregate @ 0x97b8f36c (760 bytes) */
int TIntermediate__growAggregate(this, intermNode1, intermNode2, line)
  unsigned char * this;
  unsigned char * intermNode1;
  unsigned char * intermNode2;
  int line;
{
  int stringAllocator;
  int sequenceFinishValue;
  int emptyStringRep;
  int nameAllocator;
  unsigned int ghidra_home[8] = { this, intermNode1, intermNode2, line, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  undefined *intermAggregateVtable;
  uint oldTypeBits;
  int *emptyRepRefCount;
  int *a0;
  unsigned char * this_00;
  int sequenceAllocator;
  int atomicStore;
  unsigned char * sequence;
  undefined4 *sequenceFinish;
  char reservation;
  byte cr0Reg;
  unsigned char * pTStack0000001c;
  unsigned char * pTStack00000020;
  
  if ((intermNode1 == (unsigned char *)0x0) && (intermNode2 == (unsigned char *)0x0)) {
    return (int *)0x0;
  }
  pTStack0000001c = intermNode1;
  pTStack00000020 = intermNode2;
  if (intermNode1 != (unsigned char *)0x0) {
    a0 = (int *)(**(code **)(*(int *)intermNode1 + 0x1c))(intermNode1);
    cr0Reg = (a0 == (int *)0x0) << 1;
    if ((a0 != (int *)0x0) && (a0[0xc] == 0)) goto LAB_97b8f5cc;
  }
  this_00 = (unsigned char *)GetGlobalPoolAllocator();
  a0 = (int *)TPoolAllocator__allocate(this_00,0x6c);
  a0[1] = 0;
  *a0 = (int)&PTR_getLine_a7b7cf90;
  a0[3] = 0;
  a0[4] = 0;
  a0[5] = 0;
  a0[6] = 0;
  a0[7] = 0;
  a0[8] = 0;
  a0[2] = (int)&PTR___ZN5TTypeD1Ev_a7b7cff8;
  a0[9] = 0;
  a0[10] = 0;
  oldTypeBits = a0[0xb];
  a0[0xb] = oldTypeBits & 0x1ffffff;
  a0[0xb] = oldTypeBits & 0x7ffff | 0x80000;
  a0[0xb] = oldTypeBits & 0x7ff | 0x80800;
  a0[0xb] = oldTypeBits & 0x3ff | 0x80800;
  intermAggregateVtable = PTR_vtable_a7b7c0d0;
  a0[0xb] = oldTypeBits & 0x1ff | 0x80800;
  *a0 = (int)(intermAggregateVtable + 8);
  a0[0xc] = 0;
  sequenceAllocator = GetGlobalPoolAllocator();
  a0[0x10] = 0;
  a0[0xe] = 0;
  a0[0xf] = 0;
  a0[0xd] = sequenceAllocator;
  nameAllocator = GetGlobalPoolAllocator();
  a0[0x11] = nameAllocator;
  emptyStringRep = DAT_a7b7b9b8;
  a0[0x14] = 0;
  a0[0x12] = 0;
  emptyRepRefCount = (int *)(emptyStringRep + 8);
  a0[0x13] = 0;
  do {
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(*emptyRepRefCount + 1,0,emptyRepRefCount);
      *emptyRepRefCount = atomicStore;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  stringAllocator = GetGlobalPoolAllocator();
  a0[0x16] = emptyStringRep + 0xc;
  a0[0x15] = stringAllocator;
  a0[0x1a] = 0;
  a0[0x17] = 0;
  if (pTStack0000001c != (unsigned char *)0x0) {
    sequence = (unsigned char *)(**(code **)(*a0 + 100))(a0);
    sequenceFinish = *(undefined4 **)(sequence + 8);
    if (sequenceFinish == *(undefined4 **)(sequence + 0xc)) {
      std__vector_TIntermNode__pool_allocator_TIntermNode______M_insert_aux
                (sequence,sequenceFinish,&(*(unsigned int *)((unsigned char *)ghidra_home + 4)));
    }
    else {
      sequenceFinishValue = 0;
      if (sequenceFinish != (undefined4 *)0x0) {
        *sequenceFinish = pTStack0000001c;
        sequenceFinishValue = *(int *)(sequence + 8);
      }
      *(int *)(sequence + 8) = sequenceFinishValue + 4;
    }
  }
LAB_97b8f5cc:
  if (pTStack00000020 != (unsigned char *)0x0) {
    sequence = (unsigned char *)(**(code **)(*a0 + 100))(a0);
    sequenceFinish = *(undefined4 **)(sequence + 8);
    if (sequenceFinish == *(undefined4 **)(sequence + 0xc)) {
      std__vector_TIntermNode__pool_allocator_TIntermNode______M_insert_aux
                (sequence,sequenceFinish,&(*(unsigned int *)((unsigned char *)ghidra_home + 8)));
    }
    else {
      sequenceFinishValue = 0;
      if (sequenceFinish != (undefined4 *)0x0) {
        *sequenceFinish = pTStack00000020;
        sequenceFinishValue = *(int *)(sequence + 8);
      }
      *(int *)(sequence + 8) = sequenceFinishValue + 4;
    }
  }
  if (line != 0) {
    (**(code **)(*a0 + 4))(a0,line);
  }
  return a0;
}

/* TIntermediate__makeAggregate @ 0x97b8f664 (632 bytes) */
int TIntermediate__makeAggregate(this, intermNode, line)
  unsigned char * this;
  unsigned char * intermNode;
  int line;
{
  code *setLineFn;
  int stringAllocator;
  int nodeVtable;
  int sequenceFinishValue;
  int emptyStringRep;
  int nameAllocator;
  unsigned int ghidra_home[8] = { this, intermNode, line, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  undefined *intermAggregateVtable;
  uint oldTypeBits;
  int *emptyRepRefCount;
  int *a0;
  unsigned char * this_00;
  int sequenceAllocator;
  int atomicStore;
  unsigned char * this_01;
  undefined4 *a1;
  undefined4 *extraout_r4;
  code *getSequenceFn;
  char reservation;
  byte cr0Reg;
  unsigned char * pTStack0000001c;
  
  a0 = (int *)0x0;
  if (intermNode != (unsigned char *)0x0) {
    pTStack0000001c = intermNode;
    this_00 = (unsigned char *)GetGlobalPoolAllocator();
    a0 = (int *)TPoolAllocator__allocate(this_00,0x6c);
    a0[1] = 0;
    *a0 = (int)&PTR_getLine_a7b7cf90;
    a0[3] = 0;
    a0[4] = 0;
    a0[5] = 0;
    a0[6] = 0;
    a0[7] = 0;
    a0[8] = 0;
    a0[2] = (int)&PTR___ZN5TTypeD1Ev_a7b7cff8;
    a0[9] = 0;
    a0[10] = 0;
    oldTypeBits = a0[0xb];
    a0[0xb] = oldTypeBits & 0x1ffffff;
    a0[0xb] = oldTypeBits & 0x7ffff | 0x80000;
    a0[0xb] = oldTypeBits & 0x7ff | 0x80800;
    a0[0xb] = oldTypeBits & 0x3ff | 0x80800;
    intermAggregateVtable = PTR_vtable_a7b7c0d0;
    a0[0xb] = oldTypeBits & 0x1ff | 0x80800;
    *a0 = (int)(intermAggregateVtable + 8);
    a0[0xc] = 0;
    sequenceAllocator = GetGlobalPoolAllocator();
    a0[0x10] = 0;
    a0[0xe] = 0;
    a0[0xf] = 0;
    a0[0xd] = sequenceAllocator;
    nameAllocator = GetGlobalPoolAllocator();
    a0[0x11] = nameAllocator;
    emptyStringRep = DAT_a7b7b9b8;
    a0[0x14] = 0;
    a0[0x12] = 0;
    emptyRepRefCount = (int *)(emptyStringRep + 8);
    a0[0x13] = 0;
    do {
      if (reservation != '\0') {
        atomicStore = storeWordConditionalIndexed(*emptyRepRefCount + 1,0,emptyRepRefCount);
        *emptyRepRefCount = atomicStore;
        cr0Reg = 2;
      }
    } while (!(bool)(cr0Reg >> 1 & 1));
    stringAllocator = GetGlobalPoolAllocator();
    a0[0x16] = emptyStringRep + 0xc;
    a0[0x15] = stringAllocator;
    getSequenceFn = *(code **)(*a0 + 100);
    a0[0x1a] = 0;
    a0[0x17] = 0;
    this_01 = (unsigned char *)(*getSequenceFn)(a0);
    a1 = *(undefined4 **)(this_01 + 8);
    if (a1 == *(undefined4 **)(this_01 + 0xc)) {
      std__vector_TIntermNode__pool_allocator_TIntermNode______M_insert_aux
                (this_01,a1,&(*(unsigned int *)((unsigned char *)ghidra_home + 4)));
      a1 = extraout_r4;
    }
    else {
      sequenceFinishValue = 0;
      if (a1 != (undefined4 *)0x0) {
        *a1 = pTStack0000001c;
        sequenceFinishValue = *(int *)(this_01 + 8);
      }
      *(int *)(this_01 + 8) = sequenceFinishValue + 4;
    }
    if (line == 0) {
      nodeVtable = *a0;
      line = (*(code *)**(undefined4 **)pTStack0000001c)(pTStack0000001c,a1);
      setLineFn = *(code **)(nodeVtable + 4);
    }
    else {
      setLineFn = *(code **)(*a0 + 4);
    }
    (*setLineFn)(a0,line);
  }
  return a0;
}

/* __ZN13TIntermediate12addSelectionEP12TIntermTyped15TIntermNodePairi @ 0x97b8f8dc (516 bytes) */
int __ZN13TIntermediate12addSelectionEP12TIntermTyped15TIntermNodePairi(intermediate, intermTyped, intermNodePair, falseBlock, line)
  unsigned char * intermediate;
  int *intermTyped;
  undefined4 *intermNodePair;
  undefined4 *falseBlock;
  undefined4 line;
{
  int constUnion;
  undefined *intermSelectionVtable;
  uint oldTypeBits;
  int condAsTyped;
  int *condTypedNode;
  unsigned char * this;
  undefined4 *a0;
  undefined *a6;
  code *setLineFn;
  undefined4 *puStack00000020;
  undefined4 *puStack00000024;
  
  puStack00000020 = intermNodePair;
  puStack00000024 = falseBlock;
  condAsTyped = (**(code **)(*intermTyped + 0x14))(intermTyped,intermTyped,intermNodePair,falseBlock,line);
  if (condAsTyped != 0) {
    condTypedNode = (int *)(**(code **)(*intermTyped + 0x14))(intermTyped);
    constUnion = (**(code **)(*condTypedNode + 0x18))(condTypedNode);
    if (constUnion != 0) {
      condTypedNode = (int *)(**(code **)(*intermTyped + 0x14))(intermTyped);
      constUnion = (**(code **)(*condTypedNode + 0x18))(condTypedNode);
      if (**(int **)(constUnion + 0x30) == 0) {
        return puStack00000024;
      }
      return puStack00000020;
    }
  }
  this = (unsigned char *)GetGlobalPoolAllocator();
  a0 = (undefined4 *)TPoolAllocator__allocate(this,0x3c);
  *a0 = &PTR_getLine_a7b7cf90;
  a0[1] = 0;
  a0[3] = 0;
  a0[4] = 0;
  a0[5] = 0;
  a0[6] = 0;
  a0[7] = 0;
  a0[8] = 0;
  a0[2] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  a0[10] = 0;
  a0[9] = 0;
  oldTypeBits = a0[0xb];
  a0[0xb] = oldTypeBits & 0x1ffffff;
  intermSelectionVtable = PTR_vtable_a7b7c0cc;
  a6 = PTR_vtable_a7b7c0cc + 8;
  a0[0xb] = oldTypeBits & 0x7ffff;
  setLineFn = *(code **)(intermSelectionVtable + 0xc);
  a0[0xb] = oldTypeBits & 0x7ff | 0x800;
  a0[0xb] = oldTypeBits & 0x3ff | 0x800;
  a0[0xb] = oldTypeBits & 0x1ff | 0x800;
  a0[0xc] = intermTyped;
  a0[0xd] = puStack00000020;
  a0[0xe] = puStack00000024;
  *a0 = a6;
  (*setLineFn)(a0,line,intermNodePair,falseBlock,puStack00000024,puStack00000020,a6,
            &PTR___ZN5TTypeD1Ev_a7b7cff8);
  return a0;
}

/* TIntermediate__addComma @ 0x97b8fae0 (348 bytes) */
int TIntermediate__addComma(this, intermTyped1, intermTyped2, line)
  unsigned char * this;
  unsigned char * intermTyped1;
  unsigned char * intermTyped2;
  int line;
{
  int *nodeType;
  bool bothConst;
  unsigned char * pTVar2;
  int *aggregate;
  int a3;
  undefined4 scratchR7;
  undefined4 scratchR8;
  undefined **typeTemp1 [9];
  uint typeTemp1Bits;
  undefined **typeTemp2 [9];
  uint typeTemp2Bits;
  undefined **typeTemp3 [13];
  
  bothConst = false;
  pTVar2 = intermTyped2;
  a3 = line;
  (**(code **)(*(int *)intermTyped1 + 0x38))(typeTemp1,intermTyped1,intermTyped2,line);
  if (typeTemp1Bits >> 0x19 == 2) {
    (**(code **)(*(int *)intermTyped2 + 0x38))(typeTemp2,intermTyped2,pTVar2,a3,scratchR7,scratchR8,0xa7b7faf0);
    bothConst = typeTemp2Bits >> 0x19 == 2;
    typeTemp2[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  }
  typeTemp1[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  pTVar2 = intermTyped2;
  if (!bothConst) {
    pTVar2 = (unsigned char *)
             ((int (*)())TIntermediate__growAggregate)(this,(unsigned char *)intermTyped1,(unsigned char *)intermTyped2,line);
    aggregate = (int *)(**(code **)(*(int *)pTVar2 + 0x1c))(pTVar2);
    (**(code **)(*aggregate + 0x60))(aggregate,0x25);
    (**(code **)(*(int *)intermTyped2 + 0x38))(typeTemp3,intermTyped2);
    (**(code **)(*(int *)pTVar2 + 0x34))(pTVar2,typeTemp3);
    typeTemp3[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
    nodeType = (int *)(**(code **)(*(int *)pTVar2 + 0x3c))(pTVar2);
    (**(code **)(*nodeType + 0x28))(nodeType,0);
  }
  return pTVar2;
}

/* __ZN13TIntermediate12addSelectionEP12TIntermTypedS1_S1_i @ 0x97b8fc3c (628 bytes) */
int __ZN13TIntermediate12addSelectionEP12TIntermTypedS1_S1_i(this, intermTyped1, intermTyped2, intermTyped3, line)
  void *this;
  unsigned char * intermTyped1;
  unsigned char * intermTyped2;
  unsigned char * intermTyped3;
  int line;
{
  int condConstUnion;
  uint typeSizeBits;
  uint typeQualifierBits;
  uint typeBasicTypeBits;
  uint typeMatrixBit;
  undefined *intermSelectionVtable;
  uint oldTypeBits;
  int constantUnionTest;
  int lineCopy;
  unsigned char * this_00;
  unsigned char * pTVar9;
  undefined4 a1;
  undefined ***a2;
  undefined ***a0;
  unsigned char * a3;
  undefined4 scratchR8;
  unsigned char * a0_00;
  undefined8 convertedBranchPair;
  undefined **stackType;
  int stackTypeArraySize;
  int stackTypeStructure;
  int stackTypeFieldName;
  int stackTypeTypeName;
  int stackTypeWord14;
  int stackTypeStructureSize;
  int stackTypeWord1c;
  int stackTypeWord20;
  uint stackTypeBits;
  
  a0 = &stackType;
  lineCopy = line;
  (**(code **)(*(int *)intermTyped2 + 0x38))(&stackType,intermTyped2,intermTyped2,intermTyped3,line);
  a2 = &stackType;
  a3 = intermTyped3;
  convertedBranchPair = ((int (*)())TIntermediate__addConversion)(this,1,a2,intermTyped3);
  a0_00 = (unsigned char *)((ulonglong)convertedBranchPair >> 0x20);
  a1 = (undefined4)convertedBranchPair;
  stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  if (a0_00 == (unsigned char *)0x0) {
    (**(code **)(*(int *)intermTyped3 + 0x38))(a0,intermTyped3);
    pTVar9 = (unsigned char *)((int (*)())TIntermediate__addConversion)(this,1,a0,intermTyped2);
    a1 = 0;
    a2 = a0;
    a3 = intermTyped2;
    a0_00 = intermTyped3;
    intermTyped2 = pTVar9;
    if (pTVar9 == (unsigned char *)0x0) {
      return (unsigned char *)0x0;
    }
  }
  stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  constantUnionTest = (**(code **)(*(int *)intermTyped1 + 0x18))(intermTyped1,a1);
  if (((constantUnionTest == 0) || (constantUnionTest = (**(code **)(*(int *)intermTyped2 + 0x18))(intermTyped2), constantUnionTest == 0)) ||
     (constantUnionTest = (**(code **)(*(int *)a0_00 + 0x18))(a0_00), constantUnionTest == 0)) {
    this_00 = (unsigned char *)GetGlobalPoolAllocator();
    pTVar9 = (unsigned char *)TPoolAllocator__allocate(this_00,0x3c);
    (**(code **)(*(int *)intermTyped2 + 0x38))(&stackType,intermTyped2);
    *(int *)(pTVar9 + 4) = 0;
    *(undefined ***)pTVar9 = &PTR_getLine_a7b7cf90;
    *(int *)(pTVar9 + 0xc) = stackTypeArraySize;
    *(int *)(pTVar9 + 0x10) = stackTypeStructure;
    *(int *)(pTVar9 + 0x14) = stackTypeFieldName;
    *(int *)(pTVar9 + 0x18) = stackTypeTypeName;
    *(int *)(pTVar9 + 0x1c) = stackTypeWord14;
    *(int *)(pTVar9 + 0x20) = stackTypeStructureSize;
    *(undefined ***)(pTVar9 + 8) = &PTR___ZN5TTypeD1Ev_a7b7cff8;
    *(int *)(pTVar9 + 0x24) = stackTypeWord1c;
    *(int *)(pTVar9 + 0x28) = stackTypeWord20;
    oldTypeBits = *(uint *)(pTVar9 + 0x2c);
    typeQualifierBits = stackTypeBits & 0xfe000000;
    *(uint *)(pTVar9 + 0x2c) = typeQualifierBits | oldTypeBits & 0x1ffffff;
    typeBasicTypeBits = (stackTypeBits >> 0x13 & 0x3f) << 0x13;
    *(uint *)(pTVar9 + 0x2c) = typeBasicTypeBits | typeQualifierBits | oldTypeBits & 0x7ffff;
    typeSizeBits = stackTypeBits & 0x7f800;
    *(uint *)(pTVar9 + 0x2c) = typeSizeBits | typeBasicTypeBits | typeQualifierBits | oldTypeBits & 0x7ff;
    typeMatrixBit = (stackTypeBits >> 10 & 1) << 10;
    *(uint *)(pTVar9 + 0x2c) = typeMatrixBit | typeSizeBits | typeBasicTypeBits | typeQualifierBits | oldTypeBits & 0x3ff;
    intermSelectionVtable = PTR_vtable_a7b7c0cc;
    *(uint *)(pTVar9 + 0x2c) =
         (stackTypeBits >> 9 & 1) << 9 | typeMatrixBit | typeSizeBits | typeBasicTypeBits | typeQualifierBits | oldTypeBits & 0x1ff;
    *(unsigned char **)(pTVar9 + 0x30) = intermTyped1;
    *(undefined **)pTVar9 = intermSelectionVtable + 8;
    *(unsigned char **)(pTVar9 + 0x34) = intermTyped2;
    *(unsigned char **)(pTVar9 + 0x38) = a0_00;
    stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
    (**(code **)(*(int *)pTVar9 + 4))(pTVar9,line,a2,a3,lineCopy,scratchR8,pTVar9 + 8);
  }
  else {
    condConstUnion = (**(code **)(*(int *)intermTyped1 + 0x18))(intermTyped1);
    pTVar9 = intermTyped2;
    if (**(int **)(condConstUnion + 0x30) == 0) {
      pTVar9 = a0_00;
    }
  }
  return pTVar9;
}

/* TIntermediate__addConstantUnion @ 0x97b8feb0 (300 bytes) */
int TIntermediate__addConstantUnion(this, constUnion, type, line)
  unsigned char * this;
  unsigned char * constUnion;
  unsigned char * type;
  int line;
{
  uint typeSizeBits;
  uint typeQualifierBits;
  uint typeBasicTypeBits;
  uint typeMatrixBit;
  undefined4 typeArraySize;
  uint oldTypeBits;
  undefined *constantUnionVtable;
  unsigned char * this_00;
  undefined4 *a0;
  undefined4 typeWord20;
  undefined4 a2;
  undefined4 a3;
  undefined4 a4;
  undefined4 a5;
  undefined4 typeStructure;
  uint a6;
  undefined4 a7;
  code *setLineFn;
  
  this_00 = (unsigned char *)GetGlobalPoolAllocator();
  a0 = (undefined4 *)TPoolAllocator__allocate(this_00,0x34);
  a0[1] = 0;
  *a0 = &PTR_getLine_a7b7cf90;
  typeArraySize = *(undefined4 *)(type + 4);
  typeStructure = *(undefined4 *)(type + 8);
  typeWord20 = *(undefined4 *)(type + 0x20);
  a7 = *(undefined4 *)(type + 0xc);
  a5 = *(undefined4 *)(type + 0x10);
  a4 = *(undefined4 *)(type + 0x14);
  a3 = *(undefined4 *)(type + 0x18);
  a2 = *(undefined4 *)(type + 0x1c);
  a0[2] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  a0[3] = typeArraySize;
  a0[10] = typeWord20;
  a0[4] = typeStructure;
  a0[5] = a7;
  a0[6] = a5;
  a0[7] = a4;
  a0[8] = a3;
  a0[9] = a2;
  oldTypeBits = a0[0xb];
  typeQualifierBits = *(uint *)(type + 0x24) & 0xfe000000;
  a0[0xb] = typeQualifierBits | oldTypeBits & 0x1ffffff;
  typeBasicTypeBits = (*(uint *)(type + 0x24) >> 0x13 & 0x3f) << 0x13;
  a0[0xb] = typeBasicTypeBits | typeQualifierBits | oldTypeBits & 0x7ffff;
  typeSizeBits = *(uint *)(type + 0x24) & 0x7f800;
  a0[0xb] = typeSizeBits | typeBasicTypeBits | typeQualifierBits | oldTypeBits & 0x7ff;
  typeMatrixBit = (*(uint *)(type + 0x24) >> 10 & 1) << 10;
  a0[0xb] = typeMatrixBit | typeSizeBits | typeBasicTypeBits | typeQualifierBits | oldTypeBits & 0x3ff;
  constantUnionVtable = PTR_vtable_a7b7c0c8 + 8;
  a6 = *(uint *)(type + 0x24) >> 9 & 1;
  setLineFn = *(code **)(PTR_vtable_a7b7c0c8 + 0xc);
  a0[0xb] = a6 << 9 | typeMatrixBit | typeSizeBits | typeBasicTypeBits | typeQualifierBits | oldTypeBits & 0x1ff;
  a0[0xc] = constUnion;
  *a0 = constantUnionVtable;
  (*setLineFn)(a0,line,a2,a3,a4,a5,a6,a7);
  return a0;
}

/* TIntermediate__addSwizzle @ 0x97b8ffdc (744 bytes) */
int TIntermediate__addSwizzle(this, vectorFields, line)
  unsigned char * this;
  unsigned char * vectorFields;
  int line;
{
  int fieldIndex;
  int atomicStore;
  undefined *intermAggregateVtable;
  uint oldTypeBits;
  int *emptyRepRefCount;
  int sequenceFinishValue;
  unsigned char * poolAllocator;
  int *a0;
  unsigned char * this_00;
  unsigned char * constUnionValue;
  undefined4 *sequenceFinish;
  code *setLineFn;
  int emptyStringRep;
  unsigned char * pTVar10;
  char reservation;
  byte cr0Reg;
  undefined **stackType;
  undefined4 stackTypeArraySize;
  undefined4 stackTypeStructure;
  undefined4 stackTypeFieldName;
  undefined4 stackTypeTypeName;
  undefined4 stackTypeWord14;
  undefined4 stackTypeStructureSize;
  undefined4 stackTypeWord1c;
  undefined4 stackTypeWord20;
  uint stackTypeBits;
  int sequenceAllocator;
  int nameAllocator;
  int stringAllocator;
  undefined4 constantNodeSlot [6];
  
  poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
  a0 = (int *)TPoolAllocator__allocate(poolAllocator,0x6c);
  stackTypeBits = stackTypeBits & 0x1ff | 0x80800;
  stackTypeArraySize = 0;
  stackTypeStructure = 0;
  stackTypeFieldName = 0;
  stackTypeTypeName = 0;
  stackTypeWord14 = 0;
  stackTypeStructureSize = 0;
  stackTypeWord1c = 0;
  stackTypeWord20 = 0;
  *a0 = (int)&PTR_getLine_a7b7cf90;
  a0[1] = 0;
  a0[3] = 0;
  a0[4] = 0;
  a0[5] = 0;
  a0[6] = 0;
  a0[7] = 0;
  a0[8] = 0;
  a0[9] = 0;
  a0[2] = (int)&PTR___ZN5TTypeD1Ev_a7b7cff8;
  a0[10] = 0;
  oldTypeBits = a0[0xb];
  a0[0xb] = oldTypeBits & 0x1ffffff;
  a0[0xb] = oldTypeBits & 0x7ffff | 0x80000;
  a0[0xb] = oldTypeBits & 0x7ff | 0x80800;
  a0[0xb] = oldTypeBits & 0x3ff | 0x80800;
  intermAggregateVtable = PTR_vtable_a7b7c0d0;
  a0[0xb] = oldTypeBits & 0x1ff | 0x80800;
  stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  a0[0xc] = 1;
  *a0 = (int)(intermAggregateVtable + 8);
  sequenceAllocator = GetGlobalPoolAllocator();
  a0[0x10] = 0;
  a0[0xe] = 0;
  a0[0xf] = 0;
  a0[0xd] = sequenceAllocator;
  nameAllocator = GetGlobalPoolAllocator();
  a0[0x11] = nameAllocator;
  emptyStringRep = DAT_a7b7b9b8;
  a0[0x14] = 0;
  a0[0x12] = 0;
  emptyRepRefCount = (int *)(emptyStringRep + 8);
  a0[0x13] = 0;
  do {
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(*emptyRepRefCount + 1,0,emptyRepRefCount);
      *emptyRepRefCount = atomicStore;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  stringAllocator = GetGlobalPoolAllocator();
  a0[0x16] = emptyStringRep + 0xc;
  fieldIndex = 0;
  a0[0x15] = stringAllocator;
  setLineFn = *(code **)(*a0 + 4);
  a0[0x1a] = 0;
  (*setLineFn)(a0,line);
  this_00 = (unsigned char *)(**(code **)(*a0 + 100))(a0);
  if (0 < *(int *)(vectorFields + 0x10)) {
    pTVar10 = vectorFields;
    do {
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      constUnionValue = (unsigned char *)TPoolAllocator__allocate(poolAllocator,4);
      *(undefined4 *)constUnionValue = *(undefined4 *)pTVar10;
      stackTypeBits = stackTypeBits & 0x1ff | 0x4100800;
      pTVar10 = pTVar10 + 4;
      stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
      stackTypeArraySize = 0;
      stackTypeStructure = 0;
      stackTypeFieldName = 0;
      stackTypeTypeName = 0;
      stackTypeWord14 = 0;
      stackTypeStructureSize = 0;
      stackTypeWord1c = 0;
      stackTypeWord20 = 0;
      constantNodeSlot[0] = ((int (*)())TIntermediate__addConstantUnion)(this,constUnionValue,(unsigned char *)&stackType,line);
      stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
      sequenceFinish = *(undefined4 **)(this_00 + 8);
      if (sequenceFinish == *(undefined4 **)(this_00 + 0xc)) {
        std__vector_TIntermNode__pool_allocator_TIntermNode______M_insert_aux
                  (this_00,sequenceFinish,constantNodeSlot);
      }
      else {
        sequenceFinishValue = 0;
        if (sequenceFinish != (undefined4 *)0x0) {
          *sequenceFinish = constantNodeSlot[0];
          sequenceFinishValue = *(int *)(this_00 + 8);
        }
        *(int *)(this_00 + 8) = sequenceFinishValue + 4;
      }
      fieldIndex = fieldIndex + 1;
    } while (fieldIndex < *(int *)(vectorFields + 0x10));
  }
  return a0;
}

/* TIntermediate__addLoop @ 0x97b902c4 (140 bytes) */
int TIntermediate__addLoop(this, intermNode, intermTyped1, intermTyped2, testFirst, line)
  unsigned char * this;
  unsigned char * intermNode;
  unsigned char * intermTyped1;
  unsigned char * intermTyped2;
  undefined4 testFirst;
  int line;
{
  undefined *intermLoopVtable;
  unsigned char * this_00;
  undefined4 *a0;
  code *setLineFn;
  
  this_00 = (unsigned char *)GetGlobalPoolAllocator();
  a0 = (undefined4 *)TPoolAllocator__allocate(this_00,0x18);
  intermLoopVtable = PTR_vtable_a7b7c0c4;
  a0[1] = 0;
  a0[2] = intermNode;
  setLineFn = *(code **)(intermLoopVtable + 0xc);
  a0[3] = intermTyped1;
  a0[4] = intermTyped2;
  a0[5] = testFirst;
  *a0 = intermLoopVtable + 8;
  (*setLineFn)(a0,line);
  return a0;
}

/* __ZN13TIntermediate9addBranchE9TOperatori @ 0x97b90350 (12 bytes) */
int __ZN13TIntermediate9addBranchE9TOperatori(this, op, line)
  void *this;
  undefined4 op;
  undefined4 line;
{
  return ((int (*)())__ZN13TIntermediate9addBranchE9TOperatorP12TIntermTypedi)(this,op,0,line);
}

/* __ZN13TIntermediate9addBranchE9TOperatorP12TIntermTypedi @ 0x97b9035c (124 bytes) */
int __ZN13TIntermediate9addBranchE9TOperatorP12TIntermTypedi(this, op, intermTyped, line)
  void *this;
  undefined4 op;
  undefined4 intermTyped;
  undefined4 line;
{
  undefined *intermBranchVtable;
  unsigned char * this_00;
  undefined4 *a0;
  code *setLineFn;
  
  this_00 = (unsigned char *)GetGlobalPoolAllocator();
  a0 = (undefined4 *)TPoolAllocator__allocate(this_00,0x10);
  intermBranchVtable = PTR_vtable_a7b7c0c0;
  a0[1] = 0;
  a0[2] = op;
  setLineFn = *(code **)(intermBranchVtable + 0xc);
  a0[3] = intermTyped;
  *a0 = intermBranchVtable + 8;
  (*setLineFn)(a0,line);
  return a0;
}

/* TIntermediate__postProcess @ 0x97b903d8 (96 bytes) */
int TIntermediate__postProcess(this, intermNode)
  unsigned char * this;
  int *intermNode;
{
  int *a0;
  
  if (((intermNode != (int *)0x0) &&
      (a0 = (int *)(**(code **)(*intermNode + 0x1c))(intermNode), a0 != (int *)0x0)) && (a0[0xc] == 0)) {
    (**(code **)(*a0 + 0x60))(a0,1);
  }
  return 1;
}

/* TIntermediate__remove @ 0x97b90438 (12 bytes) */
int TIntermediate__remove(this, intermNode)
  unsigned char * this;
  unsigned char * intermNode;
{
  if (intermNode == (unsigned char *)0x0) {
    return;
  }
  return RemoveAllTreeNodes(intermNode);
}

/* TIntermOperator__modifiesState @ 0x97b90444 (48 bytes) */
int TIntermOperator__modifiesState(this)
  unsigned char * this;
{
  int op;
  
  op = *(int *)(this + 0x30);
  if ((8 < op) && ((op < 0xd || (op - 0x76U < 0xf)))) {
    return 1;
  }
  return 0;
}

