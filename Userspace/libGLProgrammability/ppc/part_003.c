#include "decls.h"

/* _lFloatConst @ 0x97b88c98 (588 bytes) */
int _lFloatConst(param_1, param_2, param_3, param_4)
  undefined4 *param_1;
  int param_2;
  int param_3;
  int param_4;
{
  undefined *puVar1;
  float fVar2;
  int iVar3;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  undefined4 extraout_r4_02;
  undefined4 extraout_r4_03;
  undefined4 uVar4;
  int a3;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 in_r9;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  double lBuildFloatValueResult;
  
  puVar1 = PTR__cpp_a7b7c0a4;
  iVar6 = 0;
  iVar7 = 0;
  a3 = param_4;
  iVar9 = param_2;
  iVar3 = param_3;
  if (param_3 == 0x2e) {
    *(undefined1 *)((int)param_1 + param_2) = 0x2e;
    iVar9 = param_2 + 1;
    iVar3 = *(int *)(*(int *)puVar1 + 0x20);
    iVar3 = (**(code **)(iVar3 + 8))(iVar3,param_4);
    uVar8 = iVar3 - 0x30;
    uVar4 = extraout_r4;
    while (uVar8 < 10) {
      if (iVar9 < 0x80) {
        iVar6 = iVar6 + 1;
        if ((0 < iVar9) || (iVar3 != 0x30)) {
          *(char *)((int)param_1 + iVar9) = (char)iVar3;
          param_2 = param_2 + 1;
          iVar9 = iVar9 + 1;
        }
        iVar3 = *(int *)(*(int *)puVar1 + 0x20);
        iVar3 = (**(code **)(iVar3 + 8))(iVar3,param_4);
        uVar8 = iVar3 - 0x30;
        uVar4 = extraout_r4_00;
      }
      else {
        iVar9 = 1;
        param_2 = 1;
        _CPPErrorToInfoLog("ERROR___FP_CONST_TOO_LONG",uVar4,param_3,a3,in_r7,in_r8,in_r9);
        uVar4 = extraout_r4_01;
      }
    }
  }
  puVar1 = PTR__cpp_a7b7c0a4;
  if ((iVar3 != 0x65) && (iVar3 != 0x45)) goto LAB_97b88e60;
  *(char *)((int)param_1 + iVar9) = (char)iVar3;
  iVar10 = iVar9 + 1;
  iVar5 = 1;
  iVar3 = (**(code **)(*(int *)(*(int *)puVar1 + 0x20) + 8))
                    (*(int *)(*(int *)puVar1 + 0x20),param_4);
  if (iVar3 == 0x2b) {
    *(undefined1 *)((int)param_1 + iVar10) = 0x2b;
    iVar3 = *(int *)puVar1;
LAB_97b88de8:
    iVar3 = (**(code **)(*(int *)(iVar3 + 0x20) + 8))(*(int *)(iVar3 + 0x20),param_4);
    uVar4 = extraout_r4_03;
    iVar10 = iVar9 + 2;
  }
  else {
    uVar4 = extraout_r4_02;
    if (iVar3 == 0x2d) {
      *(undefined1 *)((int)param_1 + iVar10) = 0x2d;
      iVar3 = *(int *)puVar1;
      iVar5 = -1;
      goto LAB_97b88de8;
    }
  }
  iVar9 = iVar10;
  puVar1 = PTR__cpp_a7b7c0a4;
  if (iVar3 - 0x30U < 10) {
    do {
      *(char *)((int)param_1 + iVar9) = (char)iVar3;
      iVar9 = iVar9 + 1;
      iVar10 = *(int *)(*(int *)puVar1 + 0x20);
      iVar7 = iVar7 * 10 + iVar3 + -0x30;
      iVar3 = (**(code **)(iVar10 + 8))(iVar10,param_4,param_3,a3,in_r7,in_r8,*(int *)puVar1);
    } while (iVar3 - 0x30U < 10);
  }
  else {
    _CPPErrorToInfoLog("ERROR___ERROR_IN_EXPONENT",uVar4,param_3,a3,in_r7,in_r8,in_r9);
  }
  iVar7 = iVar7 * iVar5;
LAB_97b88e60:
  if (iVar9 == 0) {
    *param_1 = 0x302e3000;
    fVar2 = 0.0;
  }
  else {
    *(undefined1 *)((int)param_1 + iVar9) = 0;
    lBuildFloatValueResult = (double)((double (*)())_lBuildFloatValue)(param_1,param_2,iVar7 - iVar6);
    fVar2 = (float)lBuildFloatValueResult;
  }
  *(float *)(param_4 + 4) = fVar2;
  _strcpy(param_4 + 0xc,param_1);
  iVar6 = *(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20);
  (**(code **)(iVar6 + 0xc))(iVar6,iVar3,param_4,a3,in_r7,in_r8,*(int *)PTR__cpp_a7b7c0a4);
  return 0x10b;
}

/* _byte_scan @ 0x97b88ee4 (3060 bytes) */
int _byte_scan(param_1, token, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  uint *token;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
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
  undefined4 uVar4;
  undefined4 extraout_r4_05;
  undefined4 extraout_r4_06;
  undefined4 extraout_r4_07;
  undefined4 extraout_r4_08;
  undefined4 extraout_r4_09;
  undefined4 extraout_r4_10;
  uint *tokenAlias;
  uint digitValue;
  uint uVar7;
  undefined1 *lexemeCursor;
  int cppContext;
  int lexemeLength;
  uint *digitCursor;
  undefined1 identifierText [144];
  undefined1 stringLiteralText [536];
  
  uVar7 = 0;
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
    uVar4 = extraout_r4_08;
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
        uVar7 = 0;
        uVar4 = extraout_r4_00;
        do {
          *lexemeCursor = (char)a1;
          lexemeLength = lexemeLength + 1;
          lexemeCursor = lexemeCursor + 1;
          if ((int)uVar7 < 0x10000000) {
            if ((9 < digitValue) && (digitValue = a1 - 0x37, 5 < a1 - 0x41U)) {
              digitValue = a1 - 0x57;
            }
            uVar7 = uVar7 << 4 | digitValue;
          }
          else {
            if (!overflowReported) {
              _CPPErrorToInfoLog("ERROR___HEX_CONST_OVERFLOW",uVar4,param_3,param_4,param_5,param_6,
                                 digitValue);
            }
            overflowReported = true;
          }
          a1 = (**(code **)(*(int *)(cppContext + 0x20) + 8))(*(int *)(cppContext + 0x20),token);
          digitValue = a1 - 0x30;
          uVar4 = extraout_r4_01;
        } while (((digitValue < 10) || (a1 - 0x41U < 6)) || (a1 - 0x61U < 6));
      }
      else {
        _CPPErrorToInfoLog("ERROR___ERROR_IN_HEX_CONSTANT",extraout_r4_00,param_3,param_4,param_5,
                           param_6,digitValue);
      }
      goto LAB_97b89458;
    }
    digitValue = a1 - 0x30;
    if (digitValue < 8) {
      overflowReported = false;
      uVar7 = 0;
      lexemeCursor = (undefined1 *)((int)token + 0xd);
      uVar4 = extraout_r4;
      do {
        *lexemeCursor = (char)a1;
        lexemeLength = lexemeLength + 1;
        lexemeCursor = lexemeCursor + 1;
        if ((int)uVar7 < 0x20000000) {
          uVar7 = uVar7 << 3 | digitValue;
        }
        else {
          if (!overflowReported) {
            _CPPErrorToInfoLog("ERROR___OCT_CONST_OVERFLOW",uVar4,param_3,param_4,param_5,param_6,
                               digitValue);
          }
          overflowReported = true;
        }
        a1 = (**(code **)(*(int *)(cppContext + 0x20) + 8))(*(int *)(cppContext + 0x20),token);
        digitValue = a1 - 0x30;
        uVar4 = extraout_r4_02;
      } while (digitValue < 8);
      if ((((a1 == 0x2e) || (a1 == 0x65)) || ((a1 == 0x66 || ((a1 == 0x68 || (a1 == 0x78)))))) ||
         (a1 == 0x45)) goto LAB_97b89a54;
LAB_97b89458:
      *(undefined1 *)((int)token + lexemeLength + 0xc) = 0;
      (**(code **)(*(int *)(cppContext + 0x20) + 0xc))(*(int *)(cppContext + 0x20),a1,token);
      *token = uVar7;
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
      uVar7 = 0;
      overflowReported = false;
      tokenAlias = token;
      (**(code **)(*(int *)(cppContext + 0x20) + 0xc))(*(int *)(cppContext + 0x20),a1,token,param_4);
      if (0 < lexemeLength) {
        digitCursor = token + 3;
        uVar4 = extraout_r4_03;
        do {
          digitChar = *(char *)digitCursor;
          digitCursor = (uint *)((int)digitCursor + 1);
          if ((0xccccccc < (int)uVar7) || ((uVar7 == 0xccccccc && (7 < digitChar + -0x30)))) {
            if (!overflowReported) {
              _CPPErrorToInfoLog("ERROR___INTEGER_CONST_OVERFLOW",uVar4,tokenAlias,param_4,param_5,
                                 param_6,digitValue);
              uVar4 = extraout_r4_04;
            }
            overflowReported = true;
          }
          lexemeLength = lexemeLength + -1;
          uVar7 = uVar7 * 10 + digitChar + -0x30;
        } while (lexemeLength != 0);
      }
      *token = uVar7;
      if (uVar7 == 0) {
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
                        (*(int *)(cppContext + 0x20),token,param_3,param_4,param_5,param_6,digitValue);
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
  uVar4 = extraout_r4_05;
  do {
    while (lexemeLength != 0x2a) {
      if (lexemeLength == 10) {
        loopIndex = loopIndex + 1;
      }
      if (lexemeLength == -1) {
LAB_97b89b60:
        _CPPErrorToInfoLog("ERROR___EOF_IN_COMMENT",uVar4,param_3,param_4,param_5,param_6,digitValue);
        return -1;
      }
      lexemeLength = (**(code **)(*(int *)(cppContext + 0x20) + 8))(*(int *)(cppContext + 0x20),token);
      uVar4 = extraout_r4_06;
    }
    lexemeLength = (**(code **)(*(int *)(cppContext + 0x20) + 8))(*(int *)(cppContext + 0x20),token);
    uVar4 = extraout_r4_07;
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
    uVar4 = extraout_r4_09;
    if ((charOrTokenCode == 10) || (charOrTokenCode == -1)) {
LAB_97b89c74:
      stringLiteralText[lexemeLength] = 0;
      if (!overflowReported) {
        _CPPErrorToInfoLog("ERROR___CPP_EOL_IN_STRING",uVar4,param_3,param_4,param_5,param_6,digitValue);
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
    uVar4 = extraout_r4_10;
  }
  overflowReported = charOrTokenCode == 0x22;
  if (((overflowReported) || (charOrTokenCode == 10)) || (charOrTokenCode == -1)) goto LAB_97b89c74;
  goto LAB_97b89bf4;
}

/* _yylex_CPP @ 0x97b89cd0 (452 bytes) */
int _yylex_CPP(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 readCPPlineResult;
  int length;
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  undefined4 extraout_r4;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 a6;
  undefined1 auStack_b0 [8];
  int local_a8;
  char acStack_a4 [136];
  
  puVar2 = PTR__atable_a7b7c0ac;
  puVar1 = PTR__cpp_a7b7c0a4;
  a6 = 0xa7b79cdc;
  do {
    do {
      while( true ) {
        while( true ) {
          iVar3 = (**(code **)(*(int *)(*(int *)puVar1 + 0x20) + 4))
                            (*(int *)(*(int *)puVar1 + 0x20),auStack_b0,in_r5,in_r6,in_r7,in_r8,a6);
          iVar4 = ((int (*)())_check_EOF)(iVar3);
          if (iVar4 != 0) {
            return 0;
          }
          if (iVar3 != 0x23) break;
          if ((*(int *)(*(int *)puVar1 + 0x24) != 10) && (*(int *)(*(int *)puVar1 + 0x24) != 0)) {
            _CPPErrorToInfoLog("preprocessor command must not be preceded by any other statement in that line"
                               ,extraout_r4,in_r5,in_r6,in_r7,in_r8,a6);
            return 0;
          }
          readCPPlineResult = _readCPPline(auStack_b0);
          iVar3 = ((int (*)())_check_EOF)(readCPPlineResult);
          if (iVar3 != 0) {
            return 0;
          }
        }
        *(int *)(*(int *)puVar1 + 0x24) = iVar3;
        if ((iVar3 != 0x10e) || (iVar4 = _MacroExpand(local_a8,auStack_b0), iVar4 == 0)) break;
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
      length = _strlen(pcVar6);
      if (length < param_2) {
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
  undefined4 in_r4;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 in_r9;
  
  puVar1 = PTR__cpp_a7b7c0a4;
  uVar2 = 0;
  if (param_1 == -1) {
    if (0 < *(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x34)) {
      _CPPErrorToInfoLog("#endif missing!! Compilation stopped",in_r4,in_r5,in_r6,in_r7,in_r8,in_r9)
      ;
      *(undefined4 *)(*(int *)puVar1 + 0x140) = 1;
    }
    uVar2 = 1;
  }
  return uVar2;
}

/* FUN_97b89f04 @ 0x97b89f04 (72 bytes) */
int FUN_97b89f04(param_1)
  undefined4 *param_1;
{
  int unaff_r2 = (int)*param_1;   /* set by the entry _unlinkScope: lwz r2,0(r3) */
  
  if (unaff_r2 != 0) {
    *(undefined4 *)(unaff_r2 + 4) = param_1[1];
  }
  if ((undefined4 *)param_1[1] != (undefined4 *)0x0) {
    *(undefined4 *)param_1[1] = *param_1;
    return;
  }
  _ScopeList = *param_1;
  return;
}

/* _NewScopeInPool @ 0x97b89f4c (152 bytes) */
int _NewScopeInPool(param_1)
  int param_1;
{
  bool bVar1;
  int *piVar2;
  
  piVar2 = (int *)_mem_Alloc(param_1,0x20);
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
  _mem_AddCleanup(param_1,DAT_a7b7b048,piVar2);
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
  undefined4 *puVar3;
  int iVar4;
  
  puVar3 = (undefined4 *)_mem_Alloc(*(undefined4 *)(param_2 + 0x10),0x28);
  puVar3[2] = 0;
  puVar3[3] = param_3;
  iVar4 = 0x10;
  *puVar3 = 0;
  puVar3[1] = 0;
  uVar1 = *param_1;
  puVar3[5] = param_4;
  puVar3[4] = uVar1;
  puVar2 = puVar3 + 6;
  do {
    *(undefined1 *)puVar2 = 0;
    puVar2 = (undefined4 *)((int)puVar2 + 1);
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return puVar3;
}

/* _lAddToTree @ 0x97b8a11c (188 bytes) */
int _lAddToTree(param_1, param_2)
  int *param_1;
  int param_2;
{
  undefined *puVar1;
  int *piVar2;
  int reversedAtom;
  int iVar4;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 in_r9;
  int *piVar5;
  undefined8 reversedAtom2;
  
  puVar1 = PTR__atable_a7b7c0ac;
  piVar5 = (int *)*param_1;
  if (piVar5 == (int *)0x0) {
    *param_1 = param_2;
  }
  else {
    reversedAtom = _GetReversedAtom(*(undefined4 *)PTR__atable_a7b7c0ac,*(undefined4 *)(param_2 + 0xc));
    do {
      reversedAtom2 = _GetReversedAtom(*(undefined4 *)puVar1,piVar5[3]);
      iVar4 = (int)((ulonglong)reversedAtom2 >> 0x20);
      if (iVar4 == reversedAtom) {
        _CPPErrorToInfoLog("GetAtomString(atable, fSymb->name)",(int)reversedAtom2,in_r5,in_r6,in_r7,in_r8,
                           in_r9);
        return;
      }
      if (reversedAtom < iVar4) {
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
int _AddSymbol(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined4 newSymbolResult;
  
  if (param_2 == 0) {
    param_2 = _CurrentScope;
  }
  newSymbolResult = ((int (*)())_NewSymbol)(param_1,param_2,param_3,param_4);
  ((int (*)())_lAddToTree)(param_2 + 0x14,newSymbolResult);
  return newSymbolResult;
}

/* _LookUpLocalSymbol @ 0x97b8a230 (148 bytes) */
int _LookUpLocalSymbol(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined *puVar1;
  int reversedAtom;
  int reversedAtom2;
  int *piVar4;
  
  puVar1 = PTR__atable_a7b7c0ac;
  reversedAtom = _GetReversedAtom(*(undefined4 *)PTR__atable_a7b7c0ac,param_2);
  if (param_1 == 0) {
    param_1 = _CurrentScope;
  }
  piVar4 = *(int **)(param_1 + 0x14);
  while( true ) {
    if (piVar4 == (int *)0x0) {
      return 0;
    }
    reversedAtom2 = _GetReversedAtom(*(undefined4 *)puVar1,piVar4[3]);
    if (reversedAtom2 == reversedAtom) break;
    if (reversedAtom < reversedAtom2) {
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
  int length;
  byte bVar1;
  undefined *puVar2;
  int maskruneResult;
  byte *pbVar4;
  uint uVar5;
  byte *pbVar6;
  
  length = _strlen(param_1);
  if (param_2 == 0) {
    pbVar4 = (byte *)_malloc(length + 1);
  }
  else {
    pbVar4 = (byte *)_mem_Alloc(param_2,length + 1);
  }
  puVar2 = PTR_DAT_a7b7c0a8;
  bVar1 = *param_1;
  pbVar6 = pbVar4;
  do {
    if (bVar1 == 0) {
      *pbVar6 = 0;
      return pbVar4;
    }
    uVar5 = (uint)(char)bVar1;
    if ((uVar5 & 0xffffff80) == 0) {
      uVar5 = -(uint)(*(uint *)(puVar2 + uVar5 * 4 + 0x34) & 0x500) >> 0x1f;
    }
    else {
      maskruneResult = ___maskrune(uVar5,0x500);
      uVar5 = (uint)(maskruneResult != 0);
    }
    if (uVar5 == 0) {
      if (*param_1 - 0x2e < 2) {
        *pbVar6 = 0x5f;
        goto LAB_97b8a3f8;
      }
    }
    else {
      *pbVar6 = *param_1;
LAB_97b8a3f8:
      pbVar6 = pbVar6 + 1;
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
    puVar1 = (undefined4 *)_malloc(0x114);
  }
  else {
    puVar1 = (undefined4 *)_mem_Alloc(param_2,0x114);
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
  return puVar1;
}

/* _lAddByte @ 0x97b8a4b0 (92 bytes) */
int _lAddByte(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0xc);
  iVar1 = *(int *)(iVar2 + 8);
  if (*(int *)(iVar2 + 0xc) <= iVar1) {
    iVar2 = ((int (*)())_lNewBlock)(param_1,0);
    iVar1 = *(int *)(iVar2 + 8);
  }
  *(undefined1 *)(*(int *)(iVar2 + 0x10) + iVar1) = (undefined1)param_2;
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
  undefined4 idstrResult;
  
  if (param_2 == 0) {
    puVar1 = (undefined4 *)_malloc(0x10);
  }
  else {
    puVar1 = (undefined4 *)_mem_Alloc(param_2,0x10);
  }
  *puVar1 = 0;
  idstrResult = ((int (*)())_idstr)(param_1,param_2);
  puVar1[3] = 0;
  puVar1[1] = idstrResult;
  puVar1[2] = 0;
  ((int (*)())_lNewBlock)(puVar1,param_2);
  return puVar1;
}

/* _DeleteTokenStream @ 0x97b8a5e0 (116 bytes) */
int _DeleteTokenStream(param_1)
  int param_1;
{
  int *piVar1;
  int iVar2;
  
  if (param_1 == 0) {
    return;
  }
  piVar1 = (int *)*(int *)(param_1 + 8);
  while (piVar1 != (int *)0x0) {
    iVar2 = *piVar1;
    _free(piVar1);
    piVar1 = (int *)iVar2;
  }
  if (*(int *)(param_1 + 4) != 0) {
    _free(*(int *)(param_1 + 4));
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
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  
  if ((int)param_2 < 0x101) {
    uVar2 = param_2 & 0x7f;
  }
  else {
    uVar2 = (param_2 & 0x7f) - 0x80 & 0xff;
  }
  ((int (*)())_lAddByte)(param_1,uVar2);
  if (param_2 == 0x10e) {
LAB_97b8a6cc:
    pbVar3 = (byte *)_GetAtomString(*(undefined4 *)PTR__atable_a7b7c0ac,param_3[2]);
    bVar1 = *pbVar3;
    while (bVar1 != 0) {
      ((int (*)())_lAddByte)(param_1,(uint)bVar1);
      pbVar3 = pbVar3 + 1;
      bVar1 = *pbVar3;
    }
  }
  else {
    if ((int)param_2 < 0x10f) {
      if (param_2 == 0x28) {
        ((int (*)())_lAddByte)(param_1,(uint)(*param_3 != 0));
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
    pbVar3 = (byte *)(param_3 + 3);
    bVar1 = *(byte *)(param_3 + 3);
    while (bVar1 != 0) {
      ((int (*)())_lAddByte)(param_1,(uint)bVar1);
      pbVar3 = pbVar3 + 1;
      bVar1 = *pbVar3;
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
  undefined4 *param_2;
{
  undefined4 lookUpAddStringResult;
  undefined4 byteValue;
  int loopIndex2;
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  int loopIndex;
  double glp_strtodResult;
  undefined1 local_2c0 [144];
  char local_230 [532];
  
  iVar2 = ((int (*)())_lReadByte)(param_1);
  if (iVar2 < 0) {
    return -1;
  }
  if (0x7f < iVar2) {
    iVar2 = iVar2 + 0x80;
  }
  if (iVar2 == 0x10e) {
LAB_97b8a810:
    loopIndex = 0;
    byteValue = ((int (*)())_lReadByte)(param_1);
    iVar4 = (int)(char)byteValue;
    uVar1 = iVar4 - 0x61;
    while (((((uVar1 & 0xff) < 0x1a || (iVar4 - 0x41U < 0x1a)) || (iVar4 - 0x30U < 10)) ||
           (iVar4 == 0x5f))) {
      if (loopIndex < 0x80) {
        local_2c0[loopIndex] = (char)iVar4;
        byteValue = ((int (*)())_lReadByte)(param_1);
        loopIndex = loopIndex + 1;
        iVar4 = (int)(char)byteValue;
        uVar1 = iVar4 - 0x61;
      }
    }
    local_2c0[loopIndex] = 0;
    if (iVar4 == 0) {
      lookUpAddStringResult = _LookUpAddString(*(undefined4 *)PTR__atable_a7b7c0ac,local_2c0);
      param_2[2] = lookUpAddStringResult;
      return 0x10e;
    }
    uVar3 = 0x140;
LAB_97b8aac8:
    ___eprintf("%s:%u: failed assertion `%s\'\n",
               "/SourceCache/OpenGL/OpenGL-4.7.14/GLProgrammability/glslang/MachineIndependent/preprocessor/tokens.c"
               ,uVar3,"ch == \'\\0\'");
  }
  else {
    if (iVar2 < 0x10f) {
      if (iVar2 == 0x28) {
        uVar3 = ((int (*)())_lReadByte)(param_1);
        goto LAB_97b8aaf0;
      }
      if (iVar2 != 0x10b) {
        return iVar2;
      }
      loopIndex = 0;
      byteValue = ((int (*)())_lReadByte)(param_1);
      iVar4 = (int)(char)byteValue;
      uVar1 = iVar4 - 0x30;
      while (((((uVar1 & 0xff) < 10 || (iVar4 == 0x65)) ||
              ((iVar4 == 0x45 || ((iVar4 == 0x2e || (iVar4 == 0x2b)))))) || (iVar4 == 0x2d))) {
        if (loopIndex < 0x80) {
          local_2c0[loopIndex] = (char)iVar4;
          byteValue = ((int (*)())_lReadByte)(param_1);
          loopIndex = loopIndex + 1;
          iVar4 = (int)(char)byteValue;
          uVar1 = iVar4 - 0x30;
        }
      }
      local_2c0[loopIndex] = 0;
      if (iVar4 == 0) {
        _strcpy(param_2 + 3,local_2c0);
        glp_strtodResult = (double)((double (*)())_glp_strtod)(param_2 + 3,0);
        param_2[1] = (float)glp_strtodResult;
        return 0x10b;
      }
      uVar3 = 0x158;
      goto LAB_97b8aac8;
    }
    if (iVar2 == 0x116) {
      loopIndex2 = 0;
      pcVar5 = local_230;
      while( true ) {
        byteValue = ((int (*)())_lReadByte)(param_1);
        if ((char)byteValue == '\0') break;
        if (loopIndex2 < 0x200) {
          *pcVar5 = (char)byteValue;
          loopIndex2 = loopIndex2 + 1;
          pcVar5 = pcVar5 + 1;
        }
      }
      local_230[loopIndex2] = '\0';
      lookUpAddStringResult = _LookUpAddString(*(undefined4 *)PTR__atable_a7b7c0ac,local_230);
      param_2[2] = lookUpAddStringResult;
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
    loopIndex = 0;
    byteValue = ((int (*)())_lReadByte)(param_1);
    iVar4 = (int)(char)byteValue;
    uVar1 = iVar4 - 0x30;
    while ((uVar1 & 0xff) < 10) {
      if (loopIndex < 0x80) {
        local_2c0[loopIndex] = (char)iVar4;
        byteValue = ((int (*)())_lReadByte)(param_1);
        loopIndex = loopIndex + 1;
        iVar4 = (int)(char)byteValue;
        uVar1 = iVar4 - 0x30;
      }
    }
    local_2c0[loopIndex] = 0;
    if (iVar4 != 0) {
      uVar3 = 0x168;
      goto LAB_97b8aac8;
    }
  }
  _strcpy(param_2 + 3,local_2c0);
  uVar3 = _atoi(param_2 + 3);
LAB_97b8aaf0:
  *param_2 = uVar3;
  return iVar2;
}

/* _scan_token @ 0x97b8ab0c (248 bytes) */
int _scan_token(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  undefined *puVar1;
  int iVar2;
  code *pcVar3;
  
  iVar2 = ((int (*)())_ReadToken)(param_1[6],param_2);
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
    iVar2 = *(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20);
                    
                    
    iVar2 = (**(code **)(iVar2 + 4))
                      (iVar2,param_2,param_3,param_4,param_5,param_6,*(int *)PTR__cpp_a7b7c0a4);
    return iVar2;
  }
  return iVar2;
}

/* _ReadFromTokenStream @ 0x97b8ac04 (172 bytes) */
int _ReadFromTokenStream(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 uVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 *allocation;
  undefined4 uVar5;
  
  allocation = (undefined4 *)_malloc(0x20);
  puVar2 = PTR__cpp_a7b7c0a4;
  iVar3 = *(int *)PTR__cpp_a7b7c0a4;
  allocation[7] = 0;
  *allocation = 0;
  allocation[1] = 0;
  allocation[5] = 0;
  allocation[6] = 0;
  allocation[2] = 0;
  allocation[3] = 0;
  allocation[4] = param_2;
  uVar1 = DAT_a7b7b050;
  uVar5 = *(undefined4 *)(iVar3 + 0x20);
  allocation[5] = 1;
  allocation[1] = uVar1;
  *allocation = uVar5;
  allocation[7] = param_3;
  allocation[6] = param_1;
  ((int (*)())_RewindTokenStream)(param_1);
  *(undefined4 **)(*(int *)puVar2 + 0x20) = allocation;
  return 1;
}

/* FUN_97b8acb4 @ 0x97b8acb4 (96 bytes) */
int FUN_97b8acb4(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  undefined4 uVar1;
  
  uVar1 = param_1[6];
  _memcpy(param_2,param_1 + 7,0x90);
  *(undefined4 *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20) = *param_1;
  _free(param_1);
  return uVar1;
}

/* _UngetToken @ 0x97b8ad14 (156 bytes) */
int _UngetToken(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  undefined4 *allocation;
  int iVar2;
  
  allocation = (undefined4 *)_malloc(0xac);
  _memset(allocation,0,0xac);
  allocation[6] = param_1;
  _memcpy(allocation + 7,param_2,0x90);
  iVar2 = *(int *)PTR__cpp_a7b7c0a4;
  allocation[1] = DAT_a7b7b04c;
  *allocation = *(undefined4 *)(iVar2 + 0x20);
  allocation[4] = *(undefined4 *)(*(int *)(iVar2 + 0x20) + 0x10);
  allocation[5] = *(undefined4 *)(*(int *)(iVar2 + 0x20) + 0x14);
  *(undefined4 **)(iVar2 + 0x20) = allocation;
  return;
}

/* _DumpTokenStream @ 0x97b8adb0 (240 bytes) */
int _DumpTokenStream(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
{
  int iVar1;
  char *pcVar2;
  char acStack_80 [116];
  
  ((int (*)())_RewindTokenStream)(param_2);
  do {
    iVar1 = ((int (*)())_ReadToken)(param_2,param_3);
    if (iVar1 < 1) {
      return;
    }
    switch(iVar1) {
    case 0x10b:
    case 0x10f:
      goto switchD_97b8ae00_caseD_10b;
    default:
      if (0x7e < iVar1) goto LAB_97b8ae70;
      pcVar2 = "%c";
      break;
    case 0x10e:
    case 0x117:
      iVar1 = *(int *)(param_3 + 8);
LAB_97b8ae70:
      iVar1 = _GetAtomString(*(undefined4 *)PTR__atable_a7b7c0ac,iVar1);
      pcVar2 = "%s ";
      break;
    case 0x116:
      iVar1 = _GetAtomString(*(undefined4 *)PTR__atable_a7b7c0ac,*(undefined4 *)(param_3 + 8));
      pcVar2 = "\"%s\"";
    }
    _sprintf(acStack_80,pcVar2,iVar1);
switchD_97b8ae00_caseD_10b:
    _CPPDebugLogMsg(acStack_80);
  } while( true );
}

/* TBuiltIns__getNumStringArrays @ 0x97b8aed4 (20 bytes) */
int TBuiltIns__getNumStringArrays(this, param_2)
  unsigned char * this;
  int param_2;
{
  return 6 - (uint)(param_2 == 1);
}

/* TBuiltIns__getStringArray @ 0x97b8aee8 (204 bytes) */
int TBuiltIns__getStringArray(this, param_2, param_3)
  unsigned char * this;
  int param_2;
  uint param_3;
{
  undefined *puVar1;
  
  puVar1 = (undefined *)0x0;
  if (param_2 == 1) {
    if (param_3 == 0) {
      puVar1 = &_strBuiltInFunctions;
    }
    if (param_3 == 1) {
      puVar1 = &_strBuiltInFunctionsFragment;
    }
    if (param_3 == 2) {
      puVar1 = &_strStandardFragmentVaryings;
    }
    if (param_3 == 3) {
      puVar1 = &_strStandardUniformConstants;
    }
    if (param_3 != 4) {
      return puVar1;
    }
  }
  else {
    if (param_3 == 0) {
      puVar1 = &_strBuiltInFunctions;
    }
    if (param_3 == 1) {
      puVar1 = &_strBuiltInFunctionsVertex;
    }
    if (param_3 == 2) {
      puVar1 = &_strStandardVertexVaryings;
    }
    if (param_3 == 3) {
      puVar1 = &_strStandardVertexAttributes;
    }
    if (param_3 == 4) {
      puVar1 = &_strStandardUniformConstants;
    }
    if (param_3 != 5) {
      return puVar1;
    }
  }
  return &_strStandardUniforms;
}

/* TBuiltIns__getStringSizeArray @ 0x97b8afb4 (204 bytes) */
int TBuiltIns__getStringSizeArray(this, param_2, param_3)
  unsigned char * this;
  int param_2;
  uint param_3;
{
  undefined *puVar1;
  
  puVar1 = (undefined *)0x0;
  if (param_2 == 1) {
    if (param_3 == 0) {
      puVar1 = &_sizeBuiltInFunctions;
    }
    if (param_3 == 1) {
      puVar1 = &_sizeBuiltInFunctionsFragment;
    }
    if (param_3 == 2) {
      puVar1 = &_sizeStandardFragmentVaryings;
    }
    if (param_3 == 3) {
      puVar1 = &_sizeStandardUniformConstants;
    }
    if (param_3 != 4) {
      return puVar1;
    }
  }
  else {
    if (param_3 == 0) {
      puVar1 = &_sizeBuiltInFunctions;
    }
    if (param_3 == 1) {
      puVar1 = &_sizeBuiltInFunctionsVertex;
    }
    if (param_3 == 2) {
      puVar1 = &_sizeStandardVertexVaryings;
    }
    if (param_3 == 3) {
      puVar1 = &_sizeStandardVertexAttributes;
    }
    if (param_3 == 4) {
      puVar1 = &_sizeStandardUniformConstants;
    }
    if (param_3 != 5) {
      return puVar1;
    }
  }
  return &_sizeStandardUniforms;
}

/* TBuiltIns__getNumStrings @ 0x97b8b080 (148 bytes) */
int TBuiltIns__getNumStrings(this, param_2, param_3)
  unsigned char * this;
  int param_2;
  uint param_3;
{
  bool bVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (param_2 == 1) {
    if (param_3 == 0) {
      uVar2 = 0x454;
    }
    if (param_3 == 1) {
      uVar2 = 0x34;
    }
    if (param_3 == 2) {
      uVar2 = 0x14;
    }
    if (param_3 == 3) {
      uVar2 = 0x34;
    }
    bVar1 = param_3 == 4;
  }
  else {
    if (param_3 == 0) {
      uVar2 = 0x454;
    }
    if (param_3 == 1) {
      uVar2 = 8;
    }
    if (param_3 == 2) {
      uVar2 = 0x1c;
    }
    if (param_3 == 3) {
      uVar2 = 0x38;
    }
    if (param_3 == 4) {
      uVar2 = 0x34;
    }
    bVar1 = param_3 == 5;
  }
  if (bVar1) {
    uVar2 = 0x174;
  }
  return uVar2 >> 2;
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
  undefined4 *puVar5;
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
  char *pcVar10;
  unsigned char * in_r5;
  unsigned char * allocatorArgPtr;
  unsigned char * allocatorArgPtr2;
  undefined4 uVar13;
  undefined4 in_r6;
  undefined4 in_r7;
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
      in_r5 = (unsigned char *)poolAllocatorArgE;
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_(nameStringAllocation,nameChars,in_r5);
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
    variableName = (unsigned char *)(**(code **)(*symbol + 8))(symbol,passThroughR4,in_r5,in_r6,in_r7,nameString,levelsBegin);
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
    variableName = (unsigned char *)(**(code **)(*symbol + 8))(symbol,passThroughR4,allocatorArgPtr,in_r6,in_r7,nameString,levelsBegin);
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
    variableName = (unsigned char *)(**(code **)(*symbol + 8))(symbol,passThroughR4,allocatorArgPtr2,in_r6,in_r7,nameString,levelsBegin);
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
      in_r5 = (unsigned char *)poolAllocatorArg;
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_(nameStringAllocation,nameChars,in_r5);
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
    variableName = (unsigned char *)(**(code **)(*symbol + 8))(symbol,passThroughR4,in_r5,in_r6,in_r7,nameString,levelsBegin);
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
    variableName = (unsigned char *)(**(code **)(*symbol + 8))(symbol,passThroughR4,allocatorArgPtr,in_r6,in_r7,nameString,levelsBegin);
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
    variableName = (unsigned char *)(**(code **)(*symbol + 8))(symbol,passThroughR4,allocatorArgPtr2,in_r6,in_r7,nameString,levelsBegin);
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
    variableName = (unsigned char *)(**(code **)(*symbol + 8))(symbol,passThroughR4,allocatorArgPtr,in_r6,in_r7,nameString,levelsBegin);
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
    puVar5 = (undefined4 *)*symbolTable;
    uVar13 = 0x85;
    pcVar10 = *(char **)(operatorStrings + 0x214);
  }
  else {
    if (language != 1) {
      return;
    }
    TSymbolTableLevel__relateToOperator
              (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x14c),0x53);
    TSymbolTableLevel__relateToOperator
              (*(unsigned char **)*symbolTable,*(char **)(operatorStrings + 0x150),0x54);
    puVar5 = (undefined4 *)*symbolTable;
    pcVar10 = *(char **)(operatorStrings + 0x154);
    uVar13 = 0x55;
  }
  TSymbolTableLevel__relateToOperator((unsigned char *)*puVar5,pcVar10,uVar13);
  return;
}

/* __Z16IdentifyBuiltIns11EShLanguageR12TSymbolTableRK16TBuiltInResource @ 0x97b8c5c0 (600 bytes) */
int __Z16IdentifyBuiltIns11EShLanguageR12TSymbolTableRK16TBuiltInResource(language, symbolTable, builtInResource)
  int language;
  int *symbolTable;
  unsigned char * builtInResource;
{
  int *refCountPtr;
  int oldRefCount;
  int atomicStore;
  char *pcVar2;
  void *pvVar3;
  uint uVar4;
  unsigned char * poolAllocator;
  int *piVar6;
  void *this;
  unsigned char * psVar7;
  undefined4 extraout_r4;
  undefined4 a1;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar8;
  undefined4 uVar9;
  char reservation;
  byte cr0Flags;
  undefined8 uVar11;
  undefined4 local_70 [4];
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_40;
  int local_3c;
  int *local_38;
  undefined4 local_30 [6];
  
  if (language == 1) {
    iVar8 = *(int *)(builtInResource + 0x2c);
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    piVar6 = (int *)TPoolAllocator__allocate(poolAllocator,0x40);
    pcVar2 = DAT_a7b7b704;
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    uVar11 = TPoolAllocator__allocate(poolAllocator,8);
    this = (void *)((ulonglong)uVar11 >> 0x20);
    a1 = (undefined4)uVar11;
    cr0Flags = (this == (void *)0x0) << 1;
    pvVar3 = (void *)0x0;
    if (this != (void *)0x0) {
      local_70[0] = GetGlobalPoolAllocator();
      builtInResource = (unsigned char *)local_70;
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_(this,pcVar2,builtInResource);
      pvVar3 = this;
      a1 = extraout_r4;
    }
    piVar6[1] = (int)pvVar3;
    *piVar6 = (int)(PTR_vtable_a7b7c0b4 + 8);
    piVar6[4] = iVar8;
    piVar6[5] = 0;
    piVar6[6] = 0;
    piVar6[7] = 0;
    piVar6[8] = 0;
    piVar6[9] = 0;
    piVar6[3] = (int)&PTR___ZN5TTypeD1Ev_a7b7cf48;
    piVar6[10] = 0;
    piVar6[0xb] = 0;
    uVar4 = piVar6[0xc];
    piVar6[0xc] = uVar4 & 0x1ffffff | 0x24000000;
    piVar6[0xc] = uVar4 & 0x7ffff | 0x24080000;
    piVar6[0xc] = uVar4 & 0x7ff | 0x24082000;
    piVar6[0xc] = uVar4 & 0x3ff | 0x24082000;
    piVar6[0xc] = uVar4 & 0x1ff | 0x24082200;
    piVar6[0xd] = 0;
    piVar6[0xe] = 0;
    piVar6[0xf] = 0;
    iVar8 = symbolTable[3];
    symbolTable[3] = iVar8 + 1;
    piVar6[2] = iVar8 + 1;
    uVar9 = *(undefined4 *)(*symbolTable + ((symbolTable[1] - *symbolTable & 0xfffffffcU) - 4));
    local_5c = 0;
    psVar7 = (unsigned char *)(**(code **)(*piVar6 + 8))(piVar6,a1,builtInResource,in_r6,in_r7,in_r8,0);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&local_40,psVar7);
    local_38 = piVar6;
    std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&local_50,uVar9,&local_40);
    local_60 = local_50;
    refCountPtr = (int *)(local_3c + -4);
    local_5c = local_4c;
    local_30[0] = local_40;
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
                ((unsigned char *)(local_3c + -0xc),local_30);
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
  uint uVar1;
  int length;
  ulong length2;
  
  uVar1 = *(uint *)((int)this + 4);
  if ((uVar1 & 4) != 0) {
    length = _strlen(str);
    uVar1 = *(uint *)(*(int *)this + -8);
    if (uVar1 < *(int *)(*(int *)this + -0xc) + length + 2U) {
      __ZNSs7reserveEm(this,uVar1 + (uVar1 >> 1));
    }
    length2 = _strlen(str);
    __ZNSs6appendEPKcm(this,str,length2);
    uVar1 = *(uint *)((int)this + 4);
  }
  if ((uVar1 & 2) != 0) {
    _fprintf((FILE *)(PTR_DAT_a7b7c0bc + 0x58),"%s",str);
    return;
  }
  return;
}

/* __ZN13TInfoSinkBase6appendEic @ 0x97b8c8f8 (180 bytes) */
int __ZN13TInfoSinkBase6appendEic(this, param_2, param_3)
  void *this;
  int param_2;
  undefined4 param_3;
{
  uint uVar1;
  
  uVar1 = *(uint *)((int)this + 4);
  if ((uVar1 & 4) != 0) {
    uVar1 = *(uint *)(*(int *)this + -8);
    if (uVar1 < *(int *)(*(int *)this + -0xc) + param_2 + 2U) {
      __ZNSs7reserveEm(this,uVar1 + (uVar1 >> 1));
    }
    __ZNSs6appendEmc(this,param_2,param_3);
    uVar1 = *(uint *)((int)this + 4);
  }
  if ((uVar1 & 2) != 0) {
    _fprintf((FILE *)(PTR_DAT_a7b7c0bc + 0x58),"%c",param_3);
    return;
  }
  return;
}

/* __ZN13TInfoSinkBase6appendERKSs @ 0x97b8c9ac (204 bytes) */
int __ZN13TInfoSinkBase6appendERKSs(this, text)
  void *this;
  unsigned char * text;
{
  undefined *puVar1;
  uint uVar2;
  
  uVar2 = *(uint *)((int)this + 4);
  if ((uVar2 & 4) != 0) {
    uVar2 = *(uint *)(*(int *)this + -8);
    if (uVar2 < *(int *)(*(int *)this + -0xc) + *(int *)(*(int *)text + -0xc) + 2U) {
      __ZNSs7reserveEm(this,uVar2 + (uVar2 >> 1));
    }
    __ZNSs6appendERKSs(this,text);
    uVar2 = *(uint *)((int)this + 4);
  }
  puVar1 = PTR_DAT_a7b7c0bc;
  if ((uVar2 & 2) != 0) {
    *(undefined *)(*(int *)text + *(int *)(*(int *)text + -0xc)) = *PTR__S_terminal_a7b7c0b8;
    _fprintf((FILE *)(puVar1 + 0x58),"%s",*(undefined4 *)text);
    return;
  }
  return;
}

/* __ZN13TInfoSinkBase6appendERKSbIcSt11char_traitsIcE14pool_allocatorIcEE @ 0x97b8ca78 (244 bytes) */
int __ZN13TInfoSinkBase6appendERKSbIcSt11char_traitsIcE14pool_allocatorIcEE(this, text)
  void *this;
  unsigned char * text;
{
  undefined *puVar1;
  uint uVar2;
  ulong length;
  int iVar4;
  char *pcVar5;
  
  uVar2 = *(uint *)((int)this + 4);
  if ((uVar2 & 4) != 0) {
    iVar4 = *(int *)(text + 4);
    uVar2 = *(uint *)(*(int *)this + -8);
    if (uVar2 < *(int *)(*(int *)this + -0xc) + *(int *)(iVar4 + -0xc) + 2U) {
      __ZNSs7reserveEm(this,uVar2 + (uVar2 >> 1));
      iVar4 = *(int *)(text + 4);
    }
    *(undefined1 *)(iVar4 + *(int *)(iVar4 + -0xc)) = *DAT_a7b7b720;
    pcVar5 = *(char **)(text + 4);
    length = _strlen(pcVar5);
    __ZNSs6appendEPKcm(this,pcVar5,length);
    uVar2 = *(uint *)((int)this + 4);
  }
  puVar1 = PTR_DAT_a7b7c0bc;
  if ((uVar2 & 2) != 0) {
    *(undefined1 *)(*(int *)(text + 4) + *(int *)(*(int *)(text + 4) + -0xc)) = *DAT_a7b7b720;
    _fprintf((FILE *)(puVar1 + 0x58),"%s",*(undefined4 *)(text + 4));
    return;
  }
  return;
}

/* TIntermediate__addSymbol @ 0x97b8cb6c (376 bytes) */
int TIntermediate__addSymbol(this, param_2, text, type, param_5)
  unsigned char * this;
  int param_2;
  unsigned char * text;
  unsigned char * type;
  int param_5;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined *puVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  unsigned char * this_00;
  int *a0;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  char reservation;
  byte cr0Reg;
  
  this_00 = (unsigned char *)GetGlobalPoolAllocator();
  a0 = (int *)TPoolAllocator__allocate(this_00,0x3c);
  a0[1] = 0;
  *a0 = (int)&PTR_getLine_a7b7cf90;
  iVar6 = *(int *)(type + 4);
  iVar15 = *(int *)(type + 8);
  iVar14 = *(int *)(type + 0xc);
  iVar13 = *(int *)(type + 0x10);
  iVar12 = *(int *)(type + 0x14);
  iVar11 = *(int *)(type + 0x18);
  iVar10 = *(int *)(type + 0x1c);
  iVar9 = *(int *)(type + 0x20);
  a0[2] = (int)&PTR___ZN5TTypeD1Ev_a7b7cff8;
  a0[3] = iVar6;
  a0[4] = iVar15;
  a0[5] = iVar14;
  a0[6] = iVar13;
  a0[7] = iVar12;
  a0[8] = iVar11;
  a0[9] = iVar10;
  a0[10] = iVar9;
  uVar7 = a0[0xb];
  uVar2 = *(uint *)(type + 0x24) & 0xfe000000;
  a0[0xb] = uVar2 | uVar7 & 0x1ffffff;
  uVar3 = (*(uint *)(type + 0x24) >> 0x13 & 0x3f) << 0x13;
  a0[0xb] = uVar3 | uVar2 | uVar7 & 0x7ffff;
  uVar1 = *(uint *)(type + 0x24) & 0x7f800;
  a0[0xb] = uVar1 | uVar3 | uVar2 | uVar7 & 0x7ff;
  uVar4 = (*(uint *)(type + 0x24) >> 10 & 1) << 10;
  a0[0xb] = uVar4 | uVar1 | uVar3 | uVar2 | uVar7 & 0x3ff;
  puVar5 = PTR_vtable_a7b7c0dc;
  iVar6 = DAT_a7b7b9b8;
  a0[0xb] = (*(uint *)(type + 0x24) >> 9 & 1) << 9 |
            uVar4 | uVar1 | uVar3 | uVar2 | uVar7 & 0x1ff;
  piVar8 = (int *)(iVar6 + 8);
  *a0 = (int)(puVar5 + 8);
  a0[0xc] = param_2;
  do {
    if (reservation != '\0') {
      iVar9 = storeWordConditionalIndexed(*piVar8 + 1,0,piVar8);
      *piVar8 = iVar9;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  iVar9 = GetGlobalPoolAllocator();
  a0[0xd] = iVar9;
  a0[0xe] = iVar6 + 0xc;
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6assignERKS3_(a0 + 0xd,text);
  (**(code **)(*a0 + 4))(a0,param_5);
  return a0;
}

/* TIntermediate__addBinaryMath @ 0x97b8cce4 (2288 bytes) */
int TIntermediate__addBinaryMath(this, op, intermTyped1, intermTyped2, param_5, symbolTable)
  unsigned char * this;
  int op;
  int *intermTyped1;
  int *intermTyped2;
  int param_5;
  unsigned char * symbolTable;
{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  undefined *puVar5;
  uint uVar6;
  int *piVar7;
  unsigned char * this_00;
  int *a0;
  int iVar8;
  int iVar9;
  unsigned char * pTVar10;
  int *piVar11;
  unsigned char * pTVar12;
  unsigned char * pTVar13;
  unsigned char * a0_00;
  unsigned char * a2;
  undefined4 a3;
  undefined4 a4;
  code *pcVar14;
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
  undefined **local_f0 [2];
  int local_e8;
  uint local_cc;
  undefined **local_c0 [2];
  int local_b8;
  uint local_9c;
  undefined **local_90 [2];
  int local_88;
  uint local_6c;
  undefined **local_60 [9];
  uint local_3c;
  
  if (op - 0x13U < 0x1a) {
    switch(op) {
    case 0x13:
    case 0x14:
    case 0x15:
    case 0x16:
      bVar4 = false;
      (**(code **)(*intermTyped1 + 0x38))(&stackType,intermTyped1);
      bVar1 = false;
      if ((stackTypeBits >> 0x13 & 0x3f) == 0xe) {
LAB_97b8cff8:
        bVar4 = true;
        if (bVar1) goto LAB_97b8d008;
      }
      else {
        (**(code **)(*intermTyped1 + 0x38))(local_f0,intermTyped1);
        bVar1 = true;
        if ((local_cc >> 0x13 & 0x3f) == 3) goto LAB_97b8cff8;
LAB_97b8d008:
        local_f0[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
      }
      goto LAB_97b8d01c;
    default:
      goto switchD_97b8cd3c_default;
    case 0x21:
    case 0x22:
    case 0x23:
    case 0x24:
      bVar4 = false;
      bVar3 = false;
      bVar2 = false;
      (**(code **)(*intermTyped1 + 0x38))
                (&stackType,intermTyped1,intermTyped1,intermTyped2,param_5,symbolTable,(op - 0x13U) * 4);
      bVar1 = false;
      if ((stackTypeBits & 0x400) == 0) {
        bVar3 = true;
        (**(code **)(*intermTyped1 + 0x38))(local_f0,intermTyped1);
        if ((local_cc & 0x200) != 0) goto LAB_97b8ce68;
        bVar2 = true;
        (**(code **)(*intermTyped1 + 0x38))(local_c0,intermTyped1);
        if ((1 < (int)(local_9c << 0xd | local_9c >> 0x13) >> 0x18) && ((local_9c & 0x400) == 0))
        goto LAB_97b8ce68;
        bVar1 = true;
        (**(code **)(*intermTyped1 + 0x38))(local_90,intermTyped1);
        if ((local_6c >> 0x13 & 0x3f) == 0xe) goto LAB_97b8ce68;
      }
      else {
LAB_97b8ce68:
        bVar4 = true;
        if (!bVar1) break;
      }
      local_90[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
      break;
    case 0x2a:
    case 0x2b:
    case 0x2c:
      bVar4 = false;
      bVar3 = false;
      bVar2 = false;
      (**(code **)(*intermTyped1 + 0x38))(&stackType,intermTyped1);
      bVar1 = false;
      if ((stackTypeBits >> 0x13 & 0x3f) == 3) {
        bVar3 = true;
        (**(code **)(*intermTyped1 + 0x38))(local_f0,intermTyped1);
        if ((local_cc & 0x400) != 0) goto LAB_97b8cf4c;
        bVar2 = true;
        (**(code **)(*intermTyped1 + 0x38))(local_c0,intermTyped1);
        if ((local_9c & 0x200) != 0) goto LAB_97b8cf4c;
        bVar1 = true;
        (**(code **)(*intermTyped1 + 0x38))(local_60,intermTyped1);
        if ((1 < (int)(local_3c << 0xd | local_3c >> 0x13) >> 0x18) && ((local_3c & 0x400) == 0))
        goto LAB_97b8cf4c;
LAB_97b8cf5c:
        local_60[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
      }
      else {
LAB_97b8cf4c:
        bVar4 = true;
        if (bVar1) goto LAB_97b8cf5c;
      }
    }
    if (bVar2) {
      local_c0[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
    }
    if (bVar3) {
      local_f0[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
    }
LAB_97b8d01c:
    stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
    if (bVar4) {
      return (int *)0x0;
    }
  }
switchD_97b8cd3c_default:
  bVar2 = false;
  (**(code **)(*intermTyped1 + 0x38))(&stackType,intermTyped1);
  bVar1 = false;
  if (stackTypeStructure == 0) {
LAB_97b8d08c:
    bVar2 = true;
    if (bVar1) goto LAB_97b8d098;
  }
  else {
    (**(code **)(*intermTyped2 + 0x38))(local_f0,intermTyped2);
    bVar1 = true;
    if (local_e8 == 0) goto LAB_97b8d08c;
LAB_97b8d098:
    local_f0[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  }
  stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  if (bVar2) {
    (**(code **)(*intermTyped1 + 0x38))(local_c0,intermTyped1);
    piVar7 = (int *)((int (*)())TIntermediate__addConversion)(this,op,local_c0,intermTyped2);
    local_c0[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
    if (piVar7 == (int *)0x0) {
      (**(code **)(*intermTyped2 + 0x38))(local_c0,intermTyped2);
      intermTyped1 = (int *)((int (*)())TIntermediate__addConversion)(this,op,local_c0,intermTyped1);
      piVar7 = intermTyped2;
      if (intermTyped1 == (int *)0x0) {
        return (int *)0x0;
      }
    }
  }
  else {
    (**(code **)(*intermTyped1 + 0x38))(local_c0,intermTyped1);
    (**(code **)(*intermTyped2 + 0x38))(local_90,intermTyped2);
    bVar1 = false;
    if (((local_9c & 0x1fffe00) == (local_6c & 0x1fffe00)) && (local_b8 == local_88)) {
      bVar1 = true;
    }
    local_90[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
    piVar7 = intermTyped2;
    if (!bVar1) {
      return (int *)0x0;
    }
  }
  local_c0[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
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
  uVar6 = a0[0xb];
  a0[0xb] = uVar6 & 0x1ffffff;
  a0[0xb] = uVar6 & 0x7ffff | 0x80000;
  a0[0xb] = uVar6 & 0x7ff | 0x80800;
  a0[0xb] = uVar6 & 0x3ff | 0x80800;
  puVar5 = PTR_vtable_a7b7c0d8;
  a0[0xb] = uVar6 & 0x1ff | 0x80800;
  stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  a0[0xc] = op;
  *a0 = (int)(puVar5 + 8);
  if (param_5 == 0) {
    param_5 = (**(code **)*piVar7)(piVar7);
  }
  (**(code **)(*a0 + 4))(a0,param_5);
  (**(code **)(*a0 + 0x60))(a0,intermTyped1);
  (**(code **)(*a0 + 100))(a0,piVar7);
  iVar8 = (**(code **)(*a0 + 0x5c))(a0,*(undefined4 *)this);
  if (iVar8 == 0) {
    return (int *)0x0;
  }
  iVar8 = (**(code **)(*intermTyped1 + 0x18))(intermTyped1);
  iVar9 = (**(code **)(*piVar7 + 0x18))(piVar7);
  pTVar10 = (unsigned char *)0x0;
  if (iVar8 != 0) {
    pTVar10 = (unsigned char *)(**(code **)(*intermTyped1 + 0x18))(intermTyped1);
    piVar11 = (int *)TIntermediate__copyConstUnion(this,pTVar10);
    pTVar10 = (unsigned char *)(**(code **)(*piVar11 + 0x18))(piVar11);
  }
  pTVar12 = (unsigned char *)0x0;
  if (iVar9 != 0) {
    pTVar12 = (unsigned char *)(**(code **)(*piVar7 + 0x18))(piVar7);
    piVar11 = (int *)TIntermediate__copyConstUnion(this,pTVar12);
    pTVar12 = (unsigned char *)(**(code **)(*piVar11 + 0x18))(piVar11);
  }
  bVar1 = false;
  (**(code **)(*piVar7 + 0x38))(&stackType,piVar7);
  if (stackTypeBits >> 0x19 == 2) {
    (**(code **)(*intermTyped1 + 0x38))(local_f0,intermTyped1);
    bVar1 = local_cc >> 0x19 == 2;
    local_f0[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  }
  stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  if (bVar1) {
    iVar8 = (**(code **)(*piVar7 + 0x1c))(piVar7);
    if (iVar8 != 0) {
      pTVar13 = (unsigned char *)(**(code **)(*piVar7 + 0x1c))(piVar7);
      pTVar12 = (unsigned char *)TIntermediate__changeAggrToTempConst(this,pTVar13,symbolTable,param_5);
      if (*(int *)(pTVar12 + 0x30) == 0) {
        return (int *)0x0;
      }
    }
    iVar8 = (**(code **)(*intermTyped1 + 0x1c))(intermTyped1);
    if (iVar8 != 0) {
      pTVar13 = (unsigned char *)(**(code **)(*intermTyped1 + 0x1c))(intermTyped1);
      pTVar10 = (unsigned char *)TIntermediate__changeAggrToTempConst(this,pTVar13,symbolTable,param_5);
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
      iVar8 = *a0;
      pTVar12 = (unsigned char *)TIntermediate__copyConstUnion(this,pTVar10);
      pcVar14 = *(code **)(iVar8 + 0x60);
      goto LAB_97b8d618;
    }
    iVar8 = (**(code **)(*(int *)pTVar10 + 0x4c))(pTVar10);
    if ((iVar8 == 1) && (iVar8 = (**(code **)(*(int *)pTVar12 + 0x4c))(pTVar12), 1 < iVar8)) {
      a3 = *(undefined4 *)this;
      pcVar14 = *(code **)(*(int *)pTVar12 + 0x5c);
      a4 = 0;
      a0_00 = pTVar12;
      a2 = pTVar10;
    }
    else {
      a3 = *(undefined4 *)this;
      pcVar14 = *(code **)(*(int *)pTVar10 + 0x5c);
      a4 = 1;
      a0_00 = pTVar10;
      a2 = pTVar12;
    }
    piVar7 = (int *)(*pcVar14)(a0_00,a0[0xc],a2,a3,a4);
    if (piVar7 != (int *)0x0) {
      return piVar7;
    }
    (**(code **)(*a0 + 0x60))(a0,pTVar10);
  }
  pcVar14 = *(code **)(*a0 + 100);
LAB_97b8d618:
  (*pcVar14)(a0,pTVar12);
  return a0;
}

/* TIntermediate__addAssign @ 0x97b8d63c (640 bytes) */
int TIntermediate__addAssign(this, op, intermTyped1, intermTyped2, param_5)
  unsigned char * this;
  int op;
  int *intermTyped1;
  int *intermTyped2;
  int param_5;
{
  undefined *puVar1;
  uint uVar2;
  unsigned char * this_00;
  int *a0;
  int iVar3;
  unsigned char * pTVar4;
  int *piVar5;
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
  uVar2 = a0[0xb];
  a0[0xb] = uVar2 & 0x1ffffff;
  a0[0xb] = uVar2 & 0x7ffff | 0x80000;
  a0[0xb] = uVar2 & 0x7ff | 0x80800;
  a0[0xb] = uVar2 & 0x3ff | 0x80800;
  puVar1 = PTR_vtable_a7b7c0d8;
  a0[0xb] = uVar2 & 0x1ff | 0x80800;
  stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  *a0 = (int)(puVar1 + 8);
  a0[0xc] = op;
  if (param_5 == 0) {
    param_5 = (**(code **)*intermTyped1)(intermTyped1);
  }
  (**(code **)(*a0 + 4))(a0,param_5);
  iVar3 = (**(code **)(*intermTyped2 + 0x18))(intermTyped2);
  if (iVar3 != 0) {
    pTVar4 = (unsigned char *)(**(code **)(*intermTyped2 + 0x18))(intermTyped2);
    intermTyped2 = (int *)TIntermediate__copyConstUnion(this,pTVar4);
    if (intermTyped2 == (int *)0x0) {
      return (int *)0x0;
    }
  }
  (**(code **)(*intermTyped1 + 0x38))(&stackType,intermTyped1);
  iVar3 = ((int (*)())TIntermediate__addConversion)(this,op,&stackType,intermTyped2);
  stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  piVar5 = (int *)0x0;
  if (iVar3 != 0) {
    (**(code **)(*a0 + 0x60))(a0,intermTyped1);
    (**(code **)(*a0 + 100))(a0,iVar3);
    iVar3 = (**(code **)(*a0 + 0x5c))(a0,*(undefined4 *)this);
    piVar5 = (int *)0x0;
    if (iVar3 != 0) {
      piVar5 = a0;
    }
  }
  return piVar5;
}

/* TIntermediate__addIndex @ 0x97b8d8bc (460 bytes) */
int TIntermediate__addIndex(this, op, intermTyped1, intermTyped2, param_5)
  unsigned char * this;
  int op;
  undefined4 intermTyped1;
  undefined4 *intermTyped2;
  int param_5;
{
  undefined *puVar1;
  uint uVar2;
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
  uVar2 = a0[0xb];
  a0[0xb] = uVar2 & 0x1ffffff;
  a0[0xb] = uVar2 & 0x7ffff | 0x80000;
  a0[0xb] = uVar2 & 0x7ff | 0x80800;
  a0[0xb] = uVar2 & 0x3ff | 0x80800;
  puVar1 = PTR_vtable_a7b7c0d8;
  a0[0xb] = uVar2 & 0x1ff | 0x80800;
  a0[0xc] = op;
  *a0 = (int)(puVar1 + 8);
  if (param_5 == 0) {
    param_5 = (**(code **)*intermTyped2)(intermTyped2);
  }
  (**(code **)(*a0 + 4))(a0,param_5);
  (**(code **)(*a0 + 0x60))(a0,intermTyped1);
  (**(code **)(*a0 + 100))(a0,intermTyped2);
  return a0;
}

/* TIntermediate__addUnaryMath @ 0x97b8da88 (104 bytes) */
int TIntermediate__addUnaryMath(this, op, intermNode, param_4, symbolTable, param_6, param_7)
  unsigned char * this;
  int op;
  int *intermNode;
  uint param_4;
  unsigned char * symbolTable;
  undefined4 param_6;
  uint param_7;
{
  undefined *oldRefCount;
  undefined *atomicStore;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  undefined **ppuVar6;
  uint uVar7;
  undefined *puVar8;
  int *a1;
  uint uVar9;
  uint uVar10;
  int iVar11;
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
  undefined4 uVar14;
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
  char local_110 [20];
  uint stackTypeBits;
  undefined **local_f0 [8];
  unsigned char aaStack_d0 [4];
  uint local_cc;
  undefined **local_c0 [9];
  uint local_9c;
  undefined **local_90 [9];
  uint local_6c;
  undefined **local_60 [9];
  uint local_3c;
  
  uVar7 = param_4;
  a4 = symbolTable;
  a1 = (int *)(**(code **)(*intermNode + 0x14))
                        (intermNode,op,intermNode,param_4,symbolTable,param_6,param_7);
  if (a1 == (int *)0x0) {
    this_01 = *(void **)this;
                    
    ((int (*)())__ZN13TInfoSinkBase6appendEPKc)(this_01,"INTERNAL ERROR: ");
    uVar7 = param_4 & 0xffff;
    cr0Flags = (uVar7 == 0) << 1;
    if (uVar7 == 0) {
      _sprintf(local_110,"%d:? ",(int)param_4 >> 0x10);
    }
    else {
      _sprintf(local_110,"%d:%d",(int)param_4 >> 0x10,uVar7);
    }
    __ZNSsC1EPKcRKSaIcE(&stackType,local_110,aaStack_d0);
    *(undefined *)((int)stackType + (int)stackType[-3]) = *PTR__S_terminal_a7b7c0b8;
    ((int (*)())__ZN13TInfoSinkBase6appendEPKc)(this_01,(char *)stackType);
    ppuVar6 = stackType + -1;
    do {
      oldRefCount = *ppuVar6;
      if (reservation != '\0') {
        atomicStore = (undefined *)storeWordConditionalIndexed(oldRefCount + -1,0,ppuVar6);
        *ppuVar6 = atomicStore;
        cr0Flags = 2;
      }
    } while (!(bool)(cr0Flags >> 1 & 1));
    if ((int)oldRefCount < 1) {
      __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(stackType + -3),local_110);
    }
    ((int (*)())__ZN13TInfoSinkBase6appendEPKc)(this_01,": ");
    ((int (*)())__ZN13TInfoSinkBase6appendEPKc)(this_01,"Bad type in AddUnaryMath");
    ((int (*)())__ZN13TInfoSinkBase6appendEPKc)(this_01,"\n");
    return (int *)0x0;
  }
  if (op == 6) {
    bVar5 = false;
    bVar4 = false;
    bVar3 = false;
    bVar2 = false;
    (**(code **)(*a1 + 0x38))(&stackType,a1);
    uVar14 = extraout_r4_00;
    if ((stackTypeBits >> 0x13 & 0x3f) == 3) {
      bVar4 = true;
      (**(code **)(*a1 + 0x38))(local_c0,a1);
      uVar14 = extraout_r4_01;
      if ((local_9c & 0x400) != 0) goto LAB_97b8dcfc;
      bVar3 = true;
      (**(code **)(*a1 + 0x38))(local_90,a1);
      uVar14 = extraout_r4_02;
      if ((local_6c & 0x200) != 0) goto LAB_97b8dcfc;
      bVar2 = true;
      (**(code **)(*a1 + 0x38))(local_60,a1);
      uVar14 = extraout_r4_03;
      if ((1 < (int)(local_3c << 0xd | local_3c >> 0x13) >> 0x18) && ((local_3c & 0x400) == 0))
      goto LAB_97b8dcfc;
LAB_97b8dd0c:
      local_60[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
    }
    else {
LAB_97b8dcfc:
      bVar5 = true;
      if (bVar2) goto LAB_97b8dd0c;
    }
    if (bVar3) {
      local_90[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
    }
    if (bVar4) {
      local_c0[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
    }
LAB_97b8ddc8:
    stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
    if (bVar5) {
      return (int *)0x0;
    }
  }
  else {
    uVar14 = extraout_r4;
    if (op < 7) {
      if (op == 5) {
LAB_97b8dd4c:
        bVar5 = false;
        (**(code **)(*a1 + 0x38))(&stackType,a1);
        bVar2 = false;
        uVar14 = extraout_r4_04;
        if ((stackTypeBits >> 0x13 & 0x3f) == 0xe) {
LAB_97b8dda4:
          bVar5 = true;
          if (bVar2) goto LAB_97b8ddb4;
        }
        else {
          (**(code **)(*a1 + 0x38))(local_f0,a1);
          bVar2 = true;
          param_7 = local_cc & 0x200;
          uVar14 = extraout_r4_05;
          if (param_7 != 0) goto LAB_97b8dda4;
LAB_97b8ddb4:
          local_f0[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
        }
        goto LAB_97b8ddc8;
      }
    }
    else if (op - 9U < 4) goto LAB_97b8dd4c;
  }
  if (op == 0x67) {
    iVar11 = 3;
  }
  else if (op < 0x68) {
    if (op != 0x66) goto LAB_97b8decc;
    iVar11 = 2;
  }
  else {
    if (op != 0x68) goto LAB_97b8decc;
    iVar11 = 1;
  }
  uVar7 = (**(code **)(*a1 + 0x48))(a1,uVar14,intermNode,uVar7,a4,param_6,param_7);
  uVar9 = (**(code **)(*a1 + 0x50))(a1);
  uVar10 = (**(code **)(*a1 + 0x54))(a1);
  stackTypeBits = (uVar10 & 1) << 9 |
             (uVar9 & 1) << 10 | (uVar7 & 0xff) << 0xb | iVar11 << 0x13 | stackTypeBits & 0x1ff;
  local_110[0x10] = '\0';
  local_110[0x11] = '\0';
  local_110[0x12] = '\0';
  local_110[0x13] = '\0';
  stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  stackTypeArraySize = 0;
  stackTypeStructure = 0;
  stackTypeFieldName = 0;
  local_110[0] = '\0';
  local_110[1] = '\0';
  local_110[2] = '\0';
  local_110[3] = '\0';
  local_110[4] = '\0';
  local_110[5] = '\0';
  local_110[6] = '\0';
  local_110[7] = '\0';
  local_110[8] = '\0';
  local_110[9] = '\0';
  local_110[10] = '\0';
  local_110[0xb] = '\0';
  local_110[0xc] = '\0';
  local_110[0xd] = '\0';
  local_110[0xe] = '\0';
  local_110[0xf] = '\0';
  a1 = (int *)((int (*)())TIntermediate__addConversion)(this,op,&stackType,a1);
  stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  if (a1 == (int *)0x0) {
    return (int *)0x0;
  }
LAB_97b8decc:
  if (2 < op - 0x66U) {
    iVar11 = (**(code **)(*a1 + 0x18))(a1);
    if (iVar11 != 0) {
      pTVar12 = (unsigned char *)(**(code **)(*a1 + 0x18))(a1);
      a1 = (int *)TIntermediate__copyConstUnion(this,pTVar12);
    }
    iVar11 = (**(code **)(*a1 + 0x1c))(a1);
    if (iVar11 != 0) {
      (**(code **)(*a1 + 0x38))(&stackType,a1);
      stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
      if (stackTypeBits >> 0x19 == 2) {
        pTVar13 = (unsigned char *)(**(code **)(*a1 + 0x1c))(a1);
        a1 = (int *)TIntermediate__changeAggrToTempConst(this,pTVar13,symbolTable,param_4);
        iVar11 = (**(code **)(*a1 + 0x18))(a1);
        if (*(int *)(iVar11 + 0x30) == 0) {
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
    local_110[0] = '\0';
    local_110[1] = '\0';
    local_110[2] = '\0';
    local_110[3] = '\0';
    local_110[4] = '\0';
    local_110[5] = '\0';
    local_110[6] = '\0';
    local_110[7] = '\0';
    local_110[8] = '\0';
    local_110[9] = '\0';
    local_110[10] = '\0';
    local_110[0xb] = '\0';
    local_110[0xc] = '\0';
    local_110[0xd] = '\0';
    local_110[0xe] = '\0';
    local_110[0xf] = '\0';
    local_110[0x10] = '\0';
    local_110[0x11] = '\0';
    local_110[0x12] = '\0';
    local_110[0x13] = '\0';
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
    uVar7 = a0_00[0xb];
    a0_00[0xb] = uVar7 & 0x1ffffff;
    a0_00[0xb] = uVar7 & 0x7ffff | 0x80000;
    a0_00[0xb] = uVar7 & 0x7ff | 0x80800;
    a0_00[0xb] = uVar7 & 0x3ff | 0x80800;
    puVar8 = PTR_vtable_a7b7c0d4;
    a0_00[0xb] = uVar7 & 0x1ff | 0x80800;
    stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
    *a0_00 = (int)(puVar8 + 8);
    a0_00[0xd] = 0;
    a0_00[0xc] = op;
    if (param_4 == 0) {
      param_4 = (**(code **)*a1)(a1);
    }
    (**(code **)(*a0_00 + 4))(a0_00,param_4);
    (**(code **)(*a0_00 + 0x60))(a0_00,a1);
    iVar11 = (**(code **)(*a0_00 + 0x5c))(a0_00,*(undefined4 *)this);
    a1 = (int *)0x0;
    if ((iVar11 != 0) &&
       ((a0 == (int *)0x0 ||
        (a1 = (int *)(**(code **)(*a0 + 0x5c))(a0,op,0,*(undefined4 *)this,1), a1 == (int *)0x0
        )))) {
      a1 = a0_00;
    }
  }
  return a1;
}

/* TIntermediate__setAggregateOperator @ 0x97b8e1b8 (1132 bytes) */
int TIntermediate__setAggregateOperator(this, intermNode, op, param_4)
  unsigned char * this;
  unsigned char * intermNode;
  undefined4 op;
  int param_4;
{
  unsigned int ghidra_home[8] = { this, intermNode, op, param_4, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  bool bVar1;
  undefined *puVar2;
  uint uVar3;
  int *piVar4;
  int *a0;
  unsigned char * poolAllocator;
  int iVar6;
  int iVar7;
  unsigned char * this_00;
  undefined4 *puVar8;
  code *pcVar9;
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
    uVar3 = a0[0xb];
    a0[0xb] = uVar3 & 0x1ffffff;
    a0[0xb] = uVar3 & 0x7ffff | 0x80000;
    a0[0xb] = uVar3 & 0x7ff | 0x80800;
    a0[0xb] = uVar3 & 0x3ff | 0x80800;
    puVar2 = PTR_vtable_a7b7c0d0;
    a0[0xb] = uVar3 & 0x1ff | 0x80800;
    *a0 = (int)(puVar2 + 8);
    a0[0xc] = 0;
    iVar6 = GetGlobalPoolAllocator();
    a0[0x10] = 0;
    a0[0xe] = 0;
    a0[0xf] = 0;
    a0[0xd] = iVar6;
    iVar6 = GetGlobalPoolAllocator();
    a0[0x11] = iVar6;
    iVar6 = DAT_a7b7b9b8;
    a0[0x14] = 0;
    a0[0x12] = 0;
    piVar4 = (int *)(iVar6 + 8);
    a0[0x13] = 0;
    do {
      if (reservation != '\0') {
        iVar7 = storeWordConditionalIndexed(*piVar4 + 1,0,piVar4);
        *piVar4 = iVar7;
        cr0Flags = 2;
      }
    } while (!(bool)(cr0Flags >> 1 & 1));
    iVar7 = GetGlobalPoolAllocator();
    a0[0x16] = iVar6 + 0xc;
    bVar1 = param_4 == 0;
    a0[0x1a] = 0;
    a0[0x15] = iVar7;
    a0[0x17] = 0;
  }
  else {
    a0 = (int *)(**(code **)(*(int *)intermNode + 0x1c))(intermNode);
    cr0Flags = (a0 == (int *)0x0) << 1;
    if ((a0 == (int *)0x0) || (bVar1 = param_4 == 0, a0[0xc] != 0)) {
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
      uVar3 = a0[0xb];
      a0[0xb] = uVar3 & 0x1ffffff;
      a0[0xb] = uVar3 & 0x7ffff | 0x80000;
      a0[0xb] = uVar3 & 0x7ff | 0x80800;
      a0[0xb] = uVar3 & 0x3ff | 0x80800;
      puVar2 = PTR_vtable_a7b7c0d0;
      a0[0xb] = uVar3 & 0x1ff | 0x80800;
      *a0 = (int)(puVar2 + 8);
      a0[0xc] = 0;
      iVar6 = GetGlobalPoolAllocator();
      a0[0x10] = 0;
      a0[0xe] = 0;
      a0[0xf] = 0;
      a0[0xd] = iVar6;
      iVar6 = GetGlobalPoolAllocator();
      a0[0x11] = iVar6;
      iVar6 = DAT_a7b7b9b8;
      a0[0x14] = 0;
      a0[0x12] = 0;
      piVar4 = (int *)(iVar6 + 8);
      a0[0x13] = 0;
      do {
        if (reservation != '\0') {
          iVar7 = storeWordConditionalIndexed(*piVar4 + 1,0,piVar4);
          *piVar4 = iVar7;
          cr0Flags = 2;
        }
      } while (!(bool)(cr0Flags >> 1 & 1));
      iVar7 = GetGlobalPoolAllocator();
      a0[0x16] = iVar6 + 0xc;
      a0[0x15] = iVar7;
      pcVar9 = *(code **)(*a0 + 100);
      a0[0x1a] = 0;
      a0[0x17] = 0;
      this_00 = (unsigned char *)(*pcVar9)(a0);
      puVar8 = *(undefined4 **)(this_00 + 8);
      if (puVar8 == *(undefined4 **)(this_00 + 0xc)) {
        std__vector_TIntermNode__pool_allocator_TIntermNode______M_insert_aux
                  (this_00,puVar8,&(*(unsigned int *)((unsigned char *)ghidra_home + 4)));
      }
      else {
        iVar6 = 0;
        if (puVar8 != (undefined4 *)0x0) {
          *puVar8 = pTStack0000001c;
          iVar6 = *(int *)(this_00 + 8);
        }
        *(int *)(this_00 + 8) = iVar6 + 4;
      }
      bVar1 = false;
      if (param_4 == 0) {
        param_4 = (*(code *)**(undefined4 **)pTStack0000001c)(pTStack0000001c);
        bVar1 = param_4 == 0;
      }
    }
  }
  (**(code **)(*a0 + 0x60))(a0,op);
  if (!bVar1) {
    (**(code **)(*a0 + 4))(a0,param_4);
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
  undefined *oldRefCount;
  undefined *atomicStore;
  bool bVar2;
  undefined **ppuVar3;
  undefined *puVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  unsigned char * poolAllocator;
  unsigned char * pcVar10;
  int iVar11;
  int *piVar12;
  undefined4 uVar13;
  uint uVar14;
  uint uVar15;
  undefined4 a1;
  undefined4 a1_00;
  undefined4 a1_01;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  unsigned char * a2;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 *a6;
  unsigned char * pTVar16;
  char *pcVar17;
  undefined4 *puVar18;
  uint uVar19;
  void *this_00;
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
  undefined4 local_90;
  undefined4 *puStack_8c;
  char acStack_80 [64];
  longlong local_40;
  undefined1 auStack_38 [4];
  int local_34;
  
  a2 = type;
  piVar12 = intermTyped;
  iVar6 = (**(code **)(*intermTyped + 0x40))(intermTyped,op,type,intermTyped);
  if (iVar6 == 0) {
    return (int *)0x0;
  }
  if ((-1 < iVar6) && (iVar6 - 5U < 8)) {
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
  (**(code **)(*intermTyped + 0x38))((unsigned char *)&stackType,intermTyped,a2,piVar12,in_r7,in_r8,0);
  stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  if (stackTypeStructure != 0) {
    return (int *)0x0;
  }
  iVar6 = (**(code **)(*(int *)type + 0x38))(type);
  if (iVar6 != 0) {
    return (int *)0x0;
  }
  (**(code **)(*intermTyped + 0x38))((unsigned char *)&stackType,intermTyped);
  stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  if ((stackTypeBits & 0x200) != 0) {
    return (int *)0x0;
  }
  if (op == 0x67) {
    uVar7 = 3;
  }
  else if (op < 0x68) {
    if (op != 0x66) {
LAB_97b8e794:
      uVar7 = (**(code **)(*(int *)type + 0x20))(type);
      (**(code **)(*intermTyped + 0x38))(&stackType,intermTyped);
      if (uVar7 == (stackTypeBits >> 0x13 & 0x3f)) {
        return intermTyped;
      }
      return (int *)0x0;
    }
    uVar7 = 2;
  }
  else {
    if (op != 0x68) goto LAB_97b8e794;
    uVar7 = 1;
  }
  bVar2 = true;
  iVar6 = (**(code **)(*intermTyped + 0x1c))(intermTyped);
  if (iVar6 == 0) {
LAB_97b8e8ac:
    iVar6 = (**(code **)(*intermTyped + 0x1c))(intermTyped);
    if (iVar6 != 0) {
      piVar8 = (int *)(**(code **)(*intermTyped + 0x1c))(intermTyped);
      iVar6 = (**(code **)(*piVar8 + 100))(piVar8);
      pTVar16 = *(unsigned char **)(iVar6 + 4);
      while( true ) {
        if (pTVar16 == *(unsigned char **)(iVar6 + 8)) {
          piVar12 = (int *)(**(code **)(*intermTyped + 0x1c))(intermTyped);
          return piVar12;
        }
        poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
        pcVar10 = (unsigned char *)TPoolAllocator__allocate(poolAllocator,4);
        if (uVar7 != 2) break;
        piVar8 = (int *)(**(code **)(**(int **)pTVar16 + 0x14))(*(int **)pTVar16);
        (**(code **)(*piVar8 + 0x38))(&stackType,piVar8);
        uVar19 = stackTypeBits >> 0x13 & 0x3f;
        stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
        if (uVar19 == 1) {
          piVar12 = (int *)(**(code **)(**(int **)pTVar16 + 0x14))(*(int **)pTVar16);
          iVar11 = (**(code **)(*piVar12 + 0x18))(piVar12);
          local_40 = (longlong)(int)**(float **)(iVar11 + 0x30);
          *(int *)pcVar10 = (int)**(float **)(iVar11 + 0x30);
LAB_97b8ec88:
          stackTypeBits = uVar7 << 0x13 | stackTypeBits & 0x7ff | 0x4000000 | 0x800;
        }
        else {
          if (uVar19 != 3) {
            this_00 = *(void **)this;
            pcVar17 = "Bad promotion node";
            uVar7 = (**(code **)*intermTyped)(intermTyped,a1_00,a2,piVar12,in_r7,in_r8,a6);
                    
            goto override_jmp_97b8ea8c_case_0;
          }
          piVar12 = (int *)(**(code **)(**(int **)pTVar16 + 0x14))(*(int **)pTVar16);
          iVar11 = (**(code **)(*piVar12 + 0x18))(piVar12);
          a6 = *(undefined4 **)(iVar11 + 0x30);
          *(undefined4 *)pcVar10 = *a6;
LAB_97b8ecd8:
          stackTypeBits = uVar7 << 0x13 | stackTypeBits & 0xfff | 0x4000000 | 0x800;
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
        piVar12 = (int *)(**(code **)*intermTyped)(intermTyped);
        a2 = (unsigned char *)&stackType;
        iVar11 = ((int (*)())TIntermediate__addConstantUnion)(this,pcVar10,(unsigned char *)&stackType,(int)piVar12);
        stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
        if (iVar11 != 0) {
          std__vector_TIntermNode__pool_allocator_TIntermNode_____erase(auStack_38,iVar6,pTVar16);
          piVar12 = &local_34;
          a2 = pTVar16;
          local_34 = iVar11;
          std__vector_TIntermNode__pool_allocator_TIntermNode_____insert
                    (auStack_38,iVar6,pTVar16,piVar12);
        }
        pTVar16 = pTVar16 + 4;
      }
      if (uVar7 < 3) {
        if (uVar7 == 1) {
          piVar8 = (int *)(**(code **)(**(int **)pTVar16 + 0x14))(*(int **)pTVar16);
          (**(code **)(*piVar8 + 0x38))(&stackType,piVar8);
          uVar19 = stackTypeBits >> 0x13 & 0x3f;
          stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
          if (uVar19 == 2) {
            piVar12 = (int *)(**(code **)(**(int **)pTVar16 + 0x14))(*(int **)pTVar16);
            iVar11 = (**(code **)(*piVar12 + 0x18))(piVar12);
            a6 = (undefined4 *)(**(uint **)(iVar11 + 0x30) ^ 0x80000000);
            *(float *)pcVar10 = (float)((double)CONCAT44(0x43300000,a6) - 4503601774854144.0);
          }
          else {
            if (uVar19 != 3) {
              this_00 = *(void **)this;
              pcVar17 = "Bad promotion node";
              uVar7 = (**(code **)*intermTyped)(intermTyped,a1,a2,piVar12,in_r7,in_r8,a6);
                    
              goto override_jmp_97b8ea8c_case_0;
            }
            piVar12 = (int *)(**(code **)(**(int **)pTVar16 + 0x14))
                                       (*(int **)pTVar16,a1,a2,piVar12,in_r7,in_r8,a6);
            iVar11 = (**(code **)(*piVar12 + 0x18))(piVar12);
            a6 = (undefined4 *)**(undefined4 **)(iVar11 + 0x30);
            *(float *)pcVar10 = (float)((double)CONCAT44(0x43300000,a6) - 4503599627370496.0);
          }
          local_90 = 0x43300000;
          stackTypeBits = stackTypeBits & 0x7ff | 0x4080800;
          puStack_8c = a6;
          goto LAB_97b8ed90;
        }
      }
      else if (uVar7 == 3) {
        piVar8 = (int *)(**(code **)(**(int **)pTVar16 + 0x14))(*(int **)pTVar16);
        (**(code **)(*piVar8 + 0x38))(&stackType,piVar8);
        uVar19 = stackTypeBits >> 0x13 & 0x3f;
        stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
        if (uVar19 == 1) {
          piVar12 = (int *)(**(code **)(**(int **)pTVar16 + 0x14))(*(int **)pTVar16);
          iVar11 = (**(code **)(*piVar12 + 0x18))(piVar12);
          *(uint *)pcVar10 = (uint)(**(float **)(iVar11 + 0x30) != 0.0);
          goto LAB_97b8ec88;
        }
        if (uVar19 == 2) {
          piVar12 = (int *)(**(code **)(**(int **)pTVar16 + 0x14))(*(int **)pTVar16);
          iVar11 = (**(code **)(*piVar12 + 0x18))(piVar12);
          iVar11 = **(int **)(iVar11 + 0x30);
          a6 = (undefined4 *)(iVar11 + -1);
          *(uint *)pcVar10 = iVar11 - ((int)a6 + (uint)(iVar11 == 0));
          goto LAB_97b8ecd8;
        }
        this_00 = *(void **)this;
        pcVar17 = "Bad promotion node";
        uVar7 = (**(code **)*intermTyped)(intermTyped,a1_01,a2,piVar12,in_r7,in_r8,a6);
                    
        goto override_jmp_97b8ea8c_case_0;
      }
      this_00 = *(void **)this;
      pcVar17 = "Bad promotion node";
      uVar7 = (**(code **)*intermTyped)(intermTyped);
                    
      goto override_jmp_97b8ea8c_case_0;
    }
  }
  else {
    iVar6 = (**(code **)(*intermTyped + 0x1c))(intermTyped);
    if (*(int *)(iVar6 + 0x30) == 2) {
      bVar2 = false;
    }
    else {
      piVar8 = (int *)(**(code **)(*intermTyped + 0x1c))(intermTyped);
      iVar6 = (**(code **)(*piVar8 + 100))(piVar8);
      for (puVar18 = *(undefined4 **)(iVar6 + 4); puVar18 != *(undefined4 **)(iVar6 + 8);
          puVar18 = puVar18 + 1) {
        piVar8 = (int *)(**(code **)(*(int *)*puVar18 + 0x14))((int *)*puVar18);
        iVar11 = (**(code **)(*piVar8 + 0x18))(piVar8);
        if (iVar11 == 0) {
          bVar2 = false;
        }
      }
    }
    if (bVar2) goto LAB_97b8e8ac;
  }
  iVar6 = (**(code **)(*intermTyped + 0x18))(intermTyped);
  if (iVar6 != 0) {
    uVar13 = (**(code **)(*intermTyped + 0x18))(intermTyped);
    piVar12 = (int *)TIntermediate__promoteConstantUnion(this,uVar7,uVar13);
    return piVar12;
  }
  if (uVar7 != 2) {
    if (uVar7 < 3) {
      if (uVar7 == 1) {
        iVar6 = (**(code **)(*intermTyped + 0x40))(intermTyped);
        uVar13 = extraout_r4;
        if (iVar6 == 2) {
          iVar11 = 0x10;
        }
        else {
          iVar11 = 0xf;
          if (iVar6 != 3) {
            this_00 = *(void **)this;
            pcVar17 = "Bad promotion node";
            uVar7 = (**(code **)*intermTyped)(intermTyped);
                    
            goto override_jmp_97b8ea8c_case_0;
          }
        }
        goto LAB_97b8f1ac;
      }
    }
    else if (uVar7 == 3) {
      iVar6 = (**(code **)(*intermTyped + 0x40))(intermTyped);
      uVar13 = extraout_r4_00;
      if (iVar6 == 1) {
        iVar11 = 0xe;
      }
      else {
        iVar11 = 0xd;
        if (iVar6 != 2) {
          this_00 = *(void **)this;
          pcVar17 = "Bad promotion node";
          uVar7 = (**(code **)*intermTyped)(intermTyped);
                    
          goto override_jmp_97b8ea8c_case_0;
        }
      }
      goto LAB_97b8f1ac;
    }
    this_00 = *(void **)this;
    pcVar17 = "Bad promotion type";
    uVar7 = (**(code **)*intermTyped)(intermTyped);
                    
override_jmp_97b8ea8c_case_0:
    ((int (*)())__ZN13TInfoSinkBase6appendEPKc)(this_00,"INTERNAL ERROR: ");
    uVar19 = uVar7 & 0xffff;
    cr0Flags = (uVar19 == 0) << 1;
    if (uVar19 == 0) {
      _sprintf(acStack_80,"%d:? ",(int)uVar7 >> 0x10);
    }
    else {
      _sprintf(acStack_80,"%d:%d",(int)uVar7 >> 0x10,uVar19);
    }
    __ZNSsC1EPKcRKSaIcE(&stackType,acStack_80,(unsigned char *)&stackTypeTypeName);
    *(undefined *)((int)stackType + (int)stackType[-3]) = *PTR__S_terminal_a7b7c0b8;
    ((int (*)())__ZN13TInfoSinkBase6appendEPKc)(this_00,(char *)stackType);
    ppuVar3 = stackType + -1;
    do {
      oldRefCount = *ppuVar3;
      if (reservation != '\0') {
        atomicStore = (undefined *)storeWordConditionalIndexed(oldRefCount + -1,0,ppuVar3);
        *ppuVar3 = atomicStore;
        cr0Flags = 2;
      }
    } while (!(bool)(cr0Flags >> 1 & 1));
    if ((int)oldRefCount < 1) {
      __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(stackType + -3),(unsigned char *)&stackTypeTypeName);
    }
    ((int (*)())__ZN13TInfoSinkBase6appendEPKc)(this_00,": ");
    ((int (*)())__ZN13TInfoSinkBase6appendEPKc)(this_00,pcVar17);
    ((int (*)())__ZN13TInfoSinkBase6appendEPKc)(this_00,"\n");
    return (int *)0x0;
  }
  iVar6 = (**(code **)(*intermTyped + 0x40))(intermTyped);
  uVar13 = extraout_r4_01;
  if (iVar6 == 1) {
    iVar11 = 0x11;
  }
  else {
    iVar11 = 0x12;
    if (iVar6 != 3) {
      this_00 = *(void **)this;
      pcVar17 = "Bad promotion node";
      uVar7 = (**(code **)*intermTyped)(intermTyped);
                    
      goto override_jmp_97b8ea8c_case_0;
    }
  }
LAB_97b8f1ac:
  uVar19 = (**(code **)(*intermTyped + 0x48))(intermTyped,uVar13);
  uVar14 = (**(code **)(*intermTyped + 0x50))(intermTyped);
  uVar15 = (**(code **)(*intermTyped + 0x54))(intermTyped);
  stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  stackTypeBits = (uVar15 & 1) << 9 |
             (uVar14 & 1) << 10 | (uVar19 & 0xff) << 0xb | uVar7 << 0x13 | stackTypeBits & 0x1ff;
  stackTypeArraySize = 0;
  stackTypeStructure = 0;
  stackTypeFieldName = 0;
  stackTypeTypeName = 0;
  stackTypeWord14 = 0;
  stackTypeStructureSize = 0;
  stackTypeWord1c = 0;
  stackTypeWord20 = 0;
  poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
  piVar12 = (int *)TPoolAllocator__allocate(poolAllocator,0x38);
  piVar12[1] = 0;
  *piVar12 = (int)&PTR_getLine_a7b7cf90;
  piVar12[3] = stackTypeArraySize;
  piVar12[4] = stackTypeStructure;
  piVar12[5] = stackTypeFieldName;
  piVar12[6] = stackTypeTypeName;
  piVar12[7] = stackTypeWord14;
  piVar12[8] = stackTypeStructureSize;
  piVar12[2] = (int)&PTR___ZN5TTypeD1Ev_a7b7cff8;
  piVar12[10] = stackTypeWord20;
  piVar12[9] = stackTypeWord1c;
  puVar4 = PTR_vtable_a7b7c0d4;
  uVar5 = piVar12[0xb];
  uVar19 = stackTypeBits & 0xfe000000;
  piVar12[0xb] = uVar19 | uVar5 & 0x1ffffff;
  uVar14 = (stackTypeBits >> 0x13 & 0x3f) << 0x13;
  piVar12[0xb] = uVar14 | uVar19 | uVar5 & 0x7ffff;
  uVar7 = stackTypeBits & 0x7f800;
  piVar12[0xb] = uVar7 | uVar14 | uVar19 | uVar5 & 0x7ff;
  uVar15 = (stackTypeBits >> 10 & 1) << 10;
  piVar12[0xb] = uVar15 | uVar7 | uVar14 | uVar19 | uVar5 & 0x3ff;
  piVar12[0xb] = (stackTypeBits >> 9 & 1) << 9 | uVar15 | uVar7 | uVar14 | uVar19 | uVar5 & 0x1ff;
  piVar12[0xc] = iVar11;
  *piVar12 = (int)(puVar4 + 8);
  piVar12[0xd] = 0;
  uVar13 = (**(code **)*intermTyped)(intermTyped);
  (**(code **)(puVar4 + 0xc))(piVar12,uVar13);
  (**(code **)(*piVar12 + 0x60))(piVar12,intermTyped);
  return piVar12;
}

/* TIntermediate__growAggregate @ 0x97b8f36c (760 bytes) */
int TIntermediate__growAggregate(this, intermNode1, intermNode2, param_4)
  unsigned char * this;
  unsigned char * intermNode1;
  unsigned char * intermNode2;
  int param_4;
{
  unsigned int ghidra_home[8] = { this, intermNode1, intermNode2, param_4, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  undefined *puVar1;
  uint uVar2;
  int *piVar3;
  int *a0;
  unsigned char * this_00;
  int iVar4;
  int iVar5;
  unsigned char * pvVar6;
  undefined4 *puVar7;
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
  uVar2 = a0[0xb];
  a0[0xb] = uVar2 & 0x1ffffff;
  a0[0xb] = uVar2 & 0x7ffff | 0x80000;
  a0[0xb] = uVar2 & 0x7ff | 0x80800;
  a0[0xb] = uVar2 & 0x3ff | 0x80800;
  puVar1 = PTR_vtable_a7b7c0d0;
  a0[0xb] = uVar2 & 0x1ff | 0x80800;
  *a0 = (int)(puVar1 + 8);
  a0[0xc] = 0;
  iVar4 = GetGlobalPoolAllocator();
  a0[0x10] = 0;
  a0[0xe] = 0;
  a0[0xf] = 0;
  a0[0xd] = iVar4;
  iVar4 = GetGlobalPoolAllocator();
  a0[0x11] = iVar4;
  iVar4 = DAT_a7b7b9b8;
  a0[0x14] = 0;
  a0[0x12] = 0;
  piVar3 = (int *)(iVar4 + 8);
  a0[0x13] = 0;
  do {
    if (reservation != '\0') {
      iVar5 = storeWordConditionalIndexed(*piVar3 + 1,0,piVar3);
      *piVar3 = iVar5;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  iVar5 = GetGlobalPoolAllocator();
  a0[0x16] = iVar4 + 0xc;
  a0[0x15] = iVar5;
  a0[0x1a] = 0;
  a0[0x17] = 0;
  if (pTStack0000001c != (unsigned char *)0x0) {
    pvVar6 = (unsigned char *)(**(code **)(*a0 + 100))(a0);
    puVar7 = *(undefined4 **)(pvVar6 + 8);
    if (puVar7 == *(undefined4 **)(pvVar6 + 0xc)) {
      std__vector_TIntermNode__pool_allocator_TIntermNode______M_insert_aux
                (pvVar6,puVar7,&(*(unsigned int *)((unsigned char *)ghidra_home + 4)));
    }
    else {
      iVar4 = 0;
      if (puVar7 != (undefined4 *)0x0) {
        *puVar7 = pTStack0000001c;
        iVar4 = *(int *)(pvVar6 + 8);
      }
      *(int *)(pvVar6 + 8) = iVar4 + 4;
    }
  }
LAB_97b8f5cc:
  if (pTStack00000020 != (unsigned char *)0x0) {
    pvVar6 = (unsigned char *)(**(code **)(*a0 + 100))(a0);
    puVar7 = *(undefined4 **)(pvVar6 + 8);
    if (puVar7 == *(undefined4 **)(pvVar6 + 0xc)) {
      std__vector_TIntermNode__pool_allocator_TIntermNode______M_insert_aux
                (pvVar6,puVar7,&(*(unsigned int *)((unsigned char *)ghidra_home + 8)));
    }
    else {
      iVar4 = 0;
      if (puVar7 != (undefined4 *)0x0) {
        *puVar7 = pTStack00000020;
        iVar4 = *(int *)(pvVar6 + 8);
      }
      *(int *)(pvVar6 + 8) = iVar4 + 4;
    }
  }
  if (param_4 != 0) {
    (**(code **)(*a0 + 4))(a0,param_4);
  }
  return a0;
}

/* TIntermediate__makeAggregate @ 0x97b8f664 (632 bytes) */
int TIntermediate__makeAggregate(this, intermNode, param_3)
  unsigned char * this;
  unsigned char * intermNode;
  int param_3;
{
  unsigned int ghidra_home[8] = { this, intermNode, param_3, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  undefined *puVar1;
  uint uVar2;
  int *piVar3;
  int *a0;
  unsigned char * this_00;
  int iVar4;
  int iVar5;
  unsigned char * this_01;
  undefined4 *a1;
  undefined4 *extraout_r4;
  code *pcVar6;
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
    uVar2 = a0[0xb];
    a0[0xb] = uVar2 & 0x1ffffff;
    a0[0xb] = uVar2 & 0x7ffff | 0x80000;
    a0[0xb] = uVar2 & 0x7ff | 0x80800;
    a0[0xb] = uVar2 & 0x3ff | 0x80800;
    puVar1 = PTR_vtable_a7b7c0d0;
    a0[0xb] = uVar2 & 0x1ff | 0x80800;
    *a0 = (int)(puVar1 + 8);
    a0[0xc] = 0;
    iVar4 = GetGlobalPoolAllocator();
    a0[0x10] = 0;
    a0[0xe] = 0;
    a0[0xf] = 0;
    a0[0xd] = iVar4;
    iVar4 = GetGlobalPoolAllocator();
    a0[0x11] = iVar4;
    iVar4 = DAT_a7b7b9b8;
    a0[0x14] = 0;
    a0[0x12] = 0;
    piVar3 = (int *)(iVar4 + 8);
    a0[0x13] = 0;
    do {
      if (reservation != '\0') {
        iVar5 = storeWordConditionalIndexed(*piVar3 + 1,0,piVar3);
        *piVar3 = iVar5;
        cr0Reg = 2;
      }
    } while (!(bool)(cr0Reg >> 1 & 1));
    iVar5 = GetGlobalPoolAllocator();
    a0[0x16] = iVar4 + 0xc;
    a0[0x15] = iVar5;
    pcVar6 = *(code **)(*a0 + 100);
    a0[0x1a] = 0;
    a0[0x17] = 0;
    this_01 = (unsigned char *)(*pcVar6)(a0);
    a1 = *(undefined4 **)(this_01 + 8);
    if (a1 == *(undefined4 **)(this_01 + 0xc)) {
      std__vector_TIntermNode__pool_allocator_TIntermNode______M_insert_aux
                (this_01,a1,&(*(unsigned int *)((unsigned char *)ghidra_home + 4)));
      a1 = extraout_r4;
    }
    else {
      iVar4 = 0;
      if (a1 != (undefined4 *)0x0) {
        *a1 = pTStack0000001c;
        iVar4 = *(int *)(this_01 + 8);
      }
      *(int *)(this_01 + 8) = iVar4 + 4;
    }
    if (param_3 == 0) {
      iVar4 = *a0;
      param_3 = (*(code *)**(undefined4 **)pTStack0000001c)(pTStack0000001c,a1);
      pcVar6 = *(code **)(iVar4 + 4);
    }
    else {
      pcVar6 = *(code **)(*a0 + 4);
    }
    (*pcVar6)(a0,param_3);
  }
  return a0;
}

/* __ZN13TIntermediate12addSelectionEP12TIntermTyped15TIntermNodePairi @ 0x97b8f8dc (516 bytes) */
int __ZN13TIntermediate12addSelectionEP12TIntermTyped15TIntermNodePairi(param_1, intermTyped, intermNodePair, param_4, param_5)
  unsigned char * param_1;
  int *intermTyped;
  undefined4 *intermNodePair;
  undefined4 *param_4;
  undefined4 param_5;
{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  unsigned char * this;
  undefined4 *a0;
  undefined *a6;
  code *pcVar5;
  undefined4 *puStack00000020;
  undefined4 *puStack00000024;
  
  puStack00000020 = intermNodePair;
  puStack00000024 = param_4;
  iVar3 = (**(code **)(*intermTyped + 0x14))(intermTyped,intermTyped,intermNodePair,param_4,param_5);
  if (iVar3 != 0) {
    piVar4 = (int *)(**(code **)(*intermTyped + 0x14))(intermTyped);
    iVar3 = (**(code **)(*piVar4 + 0x18))(piVar4);
    if (iVar3 != 0) {
      piVar4 = (int *)(**(code **)(*intermTyped + 0x14))(intermTyped);
      iVar3 = (**(code **)(*piVar4 + 0x18))(piVar4);
      if (**(int **)(iVar3 + 0x30) == 0) {
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
  uVar2 = a0[0xb];
  a0[0xb] = uVar2 & 0x1ffffff;
  puVar1 = PTR_vtable_a7b7c0cc;
  a6 = PTR_vtable_a7b7c0cc + 8;
  a0[0xb] = uVar2 & 0x7ffff;
  pcVar5 = *(code **)(puVar1 + 0xc);
  a0[0xb] = uVar2 & 0x7ff | 0x800;
  a0[0xb] = uVar2 & 0x3ff | 0x800;
  a0[0xb] = uVar2 & 0x1ff | 0x800;
  a0[0xc] = intermTyped;
  a0[0xd] = puStack00000020;
  a0[0xe] = puStack00000024;
  *a0 = a6;
  (*pcVar5)(a0,param_5,intermNodePair,param_4,puStack00000024,puStack00000020,a6,
            &PTR___ZN5TTypeD1Ev_a7b7cff8);
  return a0;
}

/* TIntermediate__addComma @ 0x97b8fae0 (348 bytes) */
int TIntermediate__addComma(this, intermTyped1, intermTyped2, param_4)
  unsigned char * this;
  unsigned char * intermTyped1;
  unsigned char * intermTyped2;
  int param_4;
{
  bool bVar1;
  unsigned char * pTVar2;
  int *piVar3;
  int a3;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined **local_b0 [9];
  uint local_8c;
  undefined **local_80 [9];
  uint local_5c;
  undefined **local_50 [13];
  
  bVar1 = false;
  pTVar2 = intermTyped2;
  a3 = param_4;
  (**(code **)(*(int *)intermTyped1 + 0x38))(local_b0,intermTyped1,intermTyped2,param_4);
  if (local_8c >> 0x19 == 2) {
    (**(code **)(*(int *)intermTyped2 + 0x38))(local_80,intermTyped2,pTVar2,a3,in_r7,in_r8,0xa7b7faf0);
    bVar1 = local_5c >> 0x19 == 2;
    local_80[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  }
  local_b0[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  pTVar2 = intermTyped2;
  if (!bVar1) {
    pTVar2 = (unsigned char *)
             ((int (*)())TIntermediate__growAggregate)(this,(unsigned char *)intermTyped1,(unsigned char *)intermTyped2,param_4);
    piVar3 = (int *)(**(code **)(*(int *)pTVar2 + 0x1c))(pTVar2);
    (**(code **)(*piVar3 + 0x60))(piVar3,0x25);
    (**(code **)(*(int *)intermTyped2 + 0x38))(local_50,intermTyped2);
    (**(code **)(*(int *)pTVar2 + 0x34))(pTVar2,local_50);
    local_50[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
    piVar3 = (int *)(**(code **)(*(int *)pTVar2 + 0x3c))(pTVar2);
    (**(code **)(*piVar3 + 0x28))(piVar3,0);
  }
  return pTVar2;
}

/* __ZN13TIntermediate12addSelectionEP12TIntermTypedS1_S1_i @ 0x97b8fc3c (628 bytes) */
int __ZN13TIntermediate12addSelectionEP12TIntermTypedS1_S1_i(this, intermTyped1, intermTyped2, intermTyped3, param_5)
  void *this;
  unsigned char * intermTyped1;
  unsigned char * intermTyped2;
  unsigned char * intermTyped3;
  int param_5;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined *puVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  unsigned char * this_00;
  unsigned char * pTVar9;
  undefined4 a1;
  undefined ***a2;
  undefined ***a0;
  unsigned char * a3;
  undefined4 in_r8;
  unsigned char * a0_00;
  undefined8 uVar10;
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
  iVar8 = param_5;
  (**(code **)(*(int *)intermTyped2 + 0x38))(&stackType,intermTyped2,intermTyped2,intermTyped3,param_5);
  a2 = &stackType;
  a3 = intermTyped3;
  uVar10 = ((int (*)())TIntermediate__addConversion)(this,1,a2,intermTyped3);
  a0_00 = (unsigned char *)((ulonglong)uVar10 >> 0x20);
  a1 = (undefined4)uVar10;
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
  iVar7 = (**(code **)(*(int *)intermTyped1 + 0x18))(intermTyped1,a1);
  if (((iVar7 == 0) || (iVar7 = (**(code **)(*(int *)intermTyped2 + 0x18))(intermTyped2), iVar7 == 0)) ||
     (iVar7 = (**(code **)(*(int *)a0_00 + 0x18))(a0_00), iVar7 == 0)) {
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
    uVar6 = *(uint *)(pTVar9 + 0x2c);
    uVar2 = stackTypeBits & 0xfe000000;
    *(uint *)(pTVar9 + 0x2c) = uVar2 | uVar6 & 0x1ffffff;
    uVar3 = (stackTypeBits >> 0x13 & 0x3f) << 0x13;
    *(uint *)(pTVar9 + 0x2c) = uVar3 | uVar2 | uVar6 & 0x7ffff;
    uVar1 = stackTypeBits & 0x7f800;
    *(uint *)(pTVar9 + 0x2c) = uVar1 | uVar3 | uVar2 | uVar6 & 0x7ff;
    uVar4 = (stackTypeBits >> 10 & 1) << 10;
    *(uint *)(pTVar9 + 0x2c) = uVar4 | uVar1 | uVar3 | uVar2 | uVar6 & 0x3ff;
    puVar5 = PTR_vtable_a7b7c0cc;
    *(uint *)(pTVar9 + 0x2c) =
         (stackTypeBits >> 9 & 1) << 9 | uVar4 | uVar1 | uVar3 | uVar2 | uVar6 & 0x1ff;
    *(unsigned char **)(pTVar9 + 0x30) = intermTyped1;
    *(undefined **)pTVar9 = puVar5 + 8;
    *(unsigned char **)(pTVar9 + 0x34) = intermTyped2;
    *(unsigned char **)(pTVar9 + 0x38) = a0_00;
    stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
    (**(code **)(*(int *)pTVar9 + 4))(pTVar9,param_5,a2,a3,iVar8,in_r8,pTVar9 + 8);
  }
  else {
    iVar8 = (**(code **)(*(int *)intermTyped1 + 0x18))(intermTyped1);
    pTVar9 = intermTyped2;
    if (**(int **)(iVar8 + 0x30) == 0) {
      pTVar9 = a0_00;
    }
  }
  return pTVar9;
}

/* TIntermediate__addConstantUnion @ 0x97b8feb0 (300 bytes) */
int TIntermediate__addConstantUnion(this, constUnion, type, param_4)
  unsigned char * this;
  unsigned char * constUnion;
  unsigned char * type;
  int param_4;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined *puVar7;
  unsigned char * this_00;
  undefined4 *a0;
  undefined4 uVar8;
  undefined4 a2;
  undefined4 a3;
  undefined4 a4;
  undefined4 a5;
  undefined4 uVar9;
  uint a6;
  undefined4 a7;
  code *pcVar10;
  
  this_00 = (unsigned char *)GetGlobalPoolAllocator();
  a0 = (undefined4 *)TPoolAllocator__allocate(this_00,0x34);
  a0[1] = 0;
  *a0 = &PTR_getLine_a7b7cf90;
  uVar5 = *(undefined4 *)(type + 4);
  uVar9 = *(undefined4 *)(type + 8);
  uVar8 = *(undefined4 *)(type + 0x20);
  a7 = *(undefined4 *)(type + 0xc);
  a5 = *(undefined4 *)(type + 0x10);
  a4 = *(undefined4 *)(type + 0x14);
  a3 = *(undefined4 *)(type + 0x18);
  a2 = *(undefined4 *)(type + 0x1c);
  a0[2] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  a0[3] = uVar5;
  a0[10] = uVar8;
  a0[4] = uVar9;
  a0[5] = a7;
  a0[6] = a5;
  a0[7] = a4;
  a0[8] = a3;
  a0[9] = a2;
  uVar6 = a0[0xb];
  uVar2 = *(uint *)(type + 0x24) & 0xfe000000;
  a0[0xb] = uVar2 | uVar6 & 0x1ffffff;
  uVar3 = (*(uint *)(type + 0x24) >> 0x13 & 0x3f) << 0x13;
  a0[0xb] = uVar3 | uVar2 | uVar6 & 0x7ffff;
  uVar1 = *(uint *)(type + 0x24) & 0x7f800;
  a0[0xb] = uVar1 | uVar3 | uVar2 | uVar6 & 0x7ff;
  uVar4 = (*(uint *)(type + 0x24) >> 10 & 1) << 10;
  a0[0xb] = uVar4 | uVar1 | uVar3 | uVar2 | uVar6 & 0x3ff;
  puVar7 = PTR_vtable_a7b7c0c8 + 8;
  a6 = *(uint *)(type + 0x24) >> 9 & 1;
  pcVar10 = *(code **)(PTR_vtable_a7b7c0c8 + 0xc);
  a0[0xb] = a6 << 9 | uVar4 | uVar1 | uVar3 | uVar2 | uVar6 & 0x1ff;
  a0[0xc] = constUnion;
  *a0 = puVar7;
  (*pcVar10)(a0,param_4,a2,a3,a4,a5,a6,a7);
  return a0;
}

/* TIntermediate__addSwizzle @ 0x97b8ffdc (744 bytes) */
int TIntermediate__addSwizzle(this, vectorFields, param_3)
  unsigned char * this;
  unsigned char * vectorFields;
  int param_3;
{
  int atomicStore;
  undefined *puVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  unsigned char * poolAllocator;
  int *a0;
  unsigned char * this_00;
  unsigned char * pcVar6;
  undefined4 *puVar7;
  code *pcVar8;
  int iVar9;
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
  int local_80;
  int local_70;
  int local_60;
  undefined4 local_50 [6];
  
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
  uVar2 = a0[0xb];
  a0[0xb] = uVar2 & 0x1ffffff;
  a0[0xb] = uVar2 & 0x7ffff | 0x80000;
  a0[0xb] = uVar2 & 0x7ff | 0x80800;
  a0[0xb] = uVar2 & 0x3ff | 0x80800;
  puVar1 = PTR_vtable_a7b7c0d0;
  a0[0xb] = uVar2 & 0x1ff | 0x80800;
  stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  a0[0xc] = 1;
  *a0 = (int)(puVar1 + 8);
  local_80 = GetGlobalPoolAllocator();
  a0[0x10] = 0;
  a0[0xe] = 0;
  a0[0xf] = 0;
  a0[0xd] = local_80;
  local_70 = GetGlobalPoolAllocator();
  a0[0x11] = local_70;
  iVar9 = DAT_a7b7b9b8;
  a0[0x14] = 0;
  a0[0x12] = 0;
  piVar3 = (int *)(iVar9 + 8);
  a0[0x13] = 0;
  do {
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(*piVar3 + 1,0,piVar3);
      *piVar3 = atomicStore;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  local_60 = GetGlobalPoolAllocator();
  a0[0x16] = iVar9 + 0xc;
  iVar9 = 0;
  a0[0x15] = local_60;
  pcVar8 = *(code **)(*a0 + 4);
  a0[0x1a] = 0;
  (*pcVar8)(a0,param_3);
  this_00 = (unsigned char *)(**(code **)(*a0 + 100))(a0);
  if (0 < *(int *)(vectorFields + 0x10)) {
    pTVar10 = vectorFields;
    do {
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      pcVar6 = (unsigned char *)TPoolAllocator__allocate(poolAllocator,4);
      *(undefined4 *)pcVar6 = *(undefined4 *)pTVar10;
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
      local_50[0] = ((int (*)())TIntermediate__addConstantUnion)(this,pcVar6,(unsigned char *)&stackType,param_3);
      stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
      puVar7 = *(undefined4 **)(this_00 + 8);
      if (puVar7 == *(undefined4 **)(this_00 + 0xc)) {
        std__vector_TIntermNode__pool_allocator_TIntermNode______M_insert_aux
                  (this_00,puVar7,local_50);
      }
      else {
        iVar4 = 0;
        if (puVar7 != (undefined4 *)0x0) {
          *puVar7 = local_50[0];
          iVar4 = *(int *)(this_00 + 8);
        }
        *(int *)(this_00 + 8) = iVar4 + 4;
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < *(int *)(vectorFields + 0x10));
  }
  return a0;
}

/* TIntermediate__addLoop @ 0x97b902c4 (140 bytes) */
int TIntermediate__addLoop(this, intermNode, intermTyped1, intermTyped2, param_5, param_6)
  unsigned char * this;
  unsigned char * intermNode;
  unsigned char * intermTyped1;
  unsigned char * intermTyped2;
  undefined4 param_5;
  int param_6;
{
  undefined *puVar1;
  unsigned char * this_00;
  undefined4 *a0;
  code *pcVar2;
  
  this_00 = (unsigned char *)GetGlobalPoolAllocator();
  a0 = (undefined4 *)TPoolAllocator__allocate(this_00,0x18);
  puVar1 = PTR_vtable_a7b7c0c4;
  a0[1] = 0;
  a0[2] = intermNode;
  pcVar2 = *(code **)(puVar1 + 0xc);
  a0[3] = intermTyped1;
  a0[4] = intermTyped2;
  a0[5] = param_5;
  *a0 = puVar1 + 8;
  (*pcVar2)(a0,param_6);
  return a0;
}

/* __ZN13TIntermediate9addBranchE9TOperatori @ 0x97b90350 (12 bytes) */
int __ZN13TIntermediate9addBranchE9TOperatori(this, op, param_3)
  void *this;
  undefined4 op;
  undefined4 param_3;
{
  return ((int (*)())__ZN13TIntermediate9addBranchE9TOperatorP12TIntermTypedi)(this,op,0,param_3);
}

/* __ZN13TIntermediate9addBranchE9TOperatorP12TIntermTypedi @ 0x97b9035c (124 bytes) */
int __ZN13TIntermediate9addBranchE9TOperatorP12TIntermTypedi(this, op, intermTyped, param_4)
  void *this;
  undefined4 op;
  undefined4 intermTyped;
  undefined4 param_4;
{
  undefined *puVar1;
  unsigned char * this_00;
  undefined4 *a0;
  code *pcVar2;
  
  this_00 = (unsigned char *)GetGlobalPoolAllocator();
  a0 = (undefined4 *)TPoolAllocator__allocate(this_00,0x10);
  puVar1 = PTR_vtable_a7b7c0c0;
  a0[1] = 0;
  a0[2] = op;
  pcVar2 = *(code **)(puVar1 + 0xc);
  a0[3] = intermTyped;
  *a0 = puVar1 + 8;
  (*pcVar2)(a0,param_4);
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
  int iVar1;
  
  iVar1 = *(int *)(this + 0x30);
  if ((8 < iVar1) && ((iVar1 < 0xd || (iVar1 - 0x76U < 0xf)))) {
    return 1;
  }
  return 0;
}

