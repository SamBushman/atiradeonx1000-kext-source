#include "decls.h"

/* arbParseLocalParamNumber @ 0x89a20 (144 bytes) */
int arbParseLocalParamNumber(parser)
  int *parser;
{
  int localParamIndex;
  
  if (((parser[5] == 0xf) && (localParamIndex = parser[6], -1 < localParamIndex)) &&
     (localParamIndex < *(int *)(((unsigned char *)0x000011fc) + *parser))) {
    arbNextToken(parser);
  }
  else {
    localParamIndex = 0;
    arbSetError(parser,"invalid program local parameter number");
  }
  return localParamIndex;
}

/* arbParseEnvParamNumber @ 0x89ac0 (144 bytes) */
int arbParseEnvParamNumber(parser)
  int *parser;
{
  int envParamIndex;
  
  if (((parser[5] == 0xf) && (envParamIndex = parser[6], -1 < envParamIndex)) &&
     (envParamIndex < *(int *)(((unsigned char *)0x00001200) + *parser))) {
    arbNextToken(parser);
  }
  else {
    envParamIndex = 0;
    arbSetError(parser,"invalid program environment parameter number");
  }
  return envParamIndex;
}

/* arbParseTexCoordNumber @ 0x89b60 (168 bytes) */
int arbParseTexCoordNumber(parser)
  int *parser;
{
  int texCoordIndex;
  
  texCoordIndex = 0;
  if (parser[5] == 0x15) {
    arbNextToken(parser);
    if (((parser[5] != 0xf) || (texCoordIndex = parser[6], texCoordIndex < 0)) ||
       ((int)(uint)(byte)((unsigned char *)0x000013b0)[*parser] <= texCoordIndex)) {
      arbSetError(parser,"invalid texture coordinate");
      texCoordIndex = parser[6];
    }
    arbNextToken(parser);
    arbExpectToken(parser,0x16);
  }
  return texCoordIndex;
}

/* arbParseMatrixRowNumber @ 0x89c10 (128 bytes) */
int arbParseMatrixRowNumber(parser)
  int parser;
{
  uint row;
  
  if (((*(int *)(parser + 0x14) == 0xf) && (row = *(uint *)(parser + 0x18), -1 < (int)row)) &&
     (row < 4)) {
    arbNextToken(parser);
  }
  else {
    row = 0;
    arbSetError(parser,"invalid matrix row number");
  }
  return row;
}

/* arbParseLightNumber @ 0x89ca0 (144 bytes) */
int arbParseLightNumber(parser)
  int *parser;
{
  int light;
  
  if (((parser[5] == 0xf) && (light = parser[6], -1 < light)) &&
     (light < (int)(uint)(byte)((unsigned char *)0x000013b5)[*parser])) {
    arbNextToken(parser);
  }
  else {
    light = 0;
    arbSetError(parser,"invalid light number");
  }
  return light;
}

/* arbParseParamBinding @ 0x8aa40 (3780 bytes) */
int arbParseParamBinding(parser, variable, allowRange, isArrayElement)
  int *parser;
  undefined4 variable;
  int allowRange;
  int isArrayElement;
{
  int tokenValue;
  int paramNumber;
  int matrixRowNumber;
  bool notRangeToken;
  uint tokenBit;
  undefined4 *binding;
  undefined4 stateKind;
  int modifier;
  int firstIndex;
  int lastIndex;
  undefined4 *rangeBinding;
  char *errorMessage;
  undefined4 elementField8;
  undefined4 elementField12;
  double constantValue;
  float constVecX;
  float constVecY;
  float constVecZ;
  
  if (0x1a < (uint)parser[5]) {
LAB_0008aaa0:
    errorMessage = "invalid parameter binding";
    goto LAB_0008ab20;
  }
  tokenBit = 1 << (parser[5] & 0x3fU);
  if ((tokenBit & 0x818000) == 0) {
    if ((tokenBit & 1) != 0) {
      if (parser[6] == 0x1d) {
        arbNextToken(parser);
        arbExpectToken(parser,0x11);
        binding = (undefined4 *)arbAllocBindingEntry(parser,variable);
        *binding = 2;
        if (parser[5] == 0) {
          if (parser[6] == 9) {
            binding[2] = 0x32;
            arbNextToken(parser);
            arbExpectToken(parser,0x15);
            paramNumber = ((int (*)())arbParseEnvParamNumber)(parser);
            lastIndex = paramNumber;
            if ((allowRange == 0) || (parser[5] != 0x12)) {
LAB_0008abb4:
              arbExpectToken(parser,0x16);
              binding[3] = paramNumber;
              while (paramNumber = paramNumber + 1, paramNumber <= lastIndex) {
                rangeBinding = (undefined4 *)arbAllocBindingEntry(parser,variable);
                stateKind = binding[1];
                elementField8 = binding[2];
                elementField12 = binding[3];
                *rangeBinding = *binding;
                rangeBinding[1] = stateKind;
                rangeBinding[3] = elementField12;
                rangeBinding[2] = elementField8;
                stateKind = binding[4];
                rangeBinding[3] = paramNumber;
                rangeBinding[4] = stateKind;
                binding = rangeBinding;
              }
              return;
            }
            arbNextToken(parser);
            lastIndex = ((int (*)())arbParseEnvParamNumber)(parser);
            if (paramNumber <= lastIndex) goto LAB_0008abb4;
          }
          else {
            if (parser[6] != 0x14) goto LAB_0008ab0c;
            binding[2] = 0x33;
            arbNextToken(parser);
            arbExpectToken(parser,0x15);
            paramNumber = ((int (*)())arbParseLocalParamNumber)(parser);
            lastIndex = paramNumber;
            if ((allowRange == 0) || (parser[5] != 0x12)) goto LAB_0008abb4;
            arbNextToken(parser);
            lastIndex = ((int (*)())arbParseLocalParamNumber)(parser);
            if (paramNumber <= lastIndex) goto LAB_0008abb4;
          }
          errorMessage = "invalid program parameter range";
        }
        else {
LAB_0008ab0c:
          errorMessage = "invalid program parameter type";
        }
LAB_0008ab20:
        arbSetError(parser,errorMessage);
        return;
      }
      if (parser[6] != 0x27) {
        errorMessage = "invalid parameter binding";
        goto LAB_0008ab20;
      }
      arbNextToken(parser);
      arbExpectToken(parser,0x11);
      if (parser[5] != 0) {
        arbSetError(parser,"invalid state binding");
      }
      binding = (undefined4 *)arbAllocBindingEntry(parser,variable);
      *binding = 2;
      switch(parser[6]) {
      case 5:
        if (parser[5] != 0) {
LAB_0008a570:
          arbErrorInternal(parser);
          return;
        }
        arbNextToken(parser);
        arbExpectToken(parser,0x11);
        if ((parser[5] == 0) && (parser[6] == 0x1f)) {
          arbNextToken(parser);
          binding[2] = 0x18;
          return;
        }
        errorMessage = "invalid depth property";
        break;
      default:
        errorMessage = "invalid state binding";
        break;
      case 10:
        if (parser[5] != 0) goto LAB_0008a570;
        arbNextToken(parser);
        arbExpectToken(parser,0x11);
        if (parser[5] == 0) {
          if (parser[6] == 4) {
            arbNextToken(parser);
            binding[2] = 0x16;
            return;
          }
          if (parser[6] == 0x1a) {
            arbNextToken(parser);
            binding[2] = 0x17;
            return;
          }
        }
        errorMessage = "invalid fog property";
        break;
      case 0x11:
        if (parser[5] != 0) goto LAB_0008a570;
        arbNextToken(parser);
        arbExpectToken(parser,0x15);
        stateKind = ((int (*)())arbParseLightNumber)(parser);
        binding[3] = stateKind;
        arbExpectToken(parser,0x16);
        arbExpectToken(parser,0x11);
        if (parser[5] == 0) {
          switch(parser[6]) {
          default:
            goto switchD_0008a094_caseD_0;
          case 1:
            stateKind = 10;
            break;
          case 2:
            stateKind = 0xe;
            break;
          case 6:
            stateKind = 0xb;
            break;
          case 0xe:
            stateKind = 0x10;
            break;
          case 0x1b:
            stateKind = 0xd;
            break;
          case 0x25:
            stateKind = 0xc;
            break;
          case 0x26:
            arbNextToken(parser);
            arbExpectToken(parser,0x11);
            if ((parser[5] != 0) || (parser[6] != 7)) {
              errorMessage = "invalid spot light property";
              goto LAB_0008a9fc;
            }
            stateKind = 0xf;
          }
LAB_00089fc4:
          binding[2] = stateKind;
          arbNextToken(parser);
          return;
        }
switchD_0008a094_caseD_0:
        errorMessage = "invalid light property";
        break;
      case 0x12:
        if (parser[5] != 0) {
          arbErrorInternal(parser);
        }
        arbNextToken(parser);
        arbExpectToken(parser,0x11);
        if (parser[5] == 0) {
          binding[3] = 0;
          tokenValue = parser[6];
          if (tokenValue == 3) {
            binding[3] = 1;
            arbNextToken(parser);
            arbExpectToken(parser,0x11);
          }
          else if (tokenValue == 0xd) {
            arbNextToken(parser);
            arbExpectToken(parser,0x11);
          }
          else if (tokenValue == 1) {
            stateKind = 0x11;
            goto LAB_00089fc4;
          }
          if ((parser[5] == 0) && (parser[6] == 0x22)) {
            stateKind = 0x12;
            goto LAB_00089fc4;
          }
        }
        errorMessage = "invalid light model property";
        break;
      case 0x13:
        if (parser[5] != 0) goto LAB_0008a570;
        arbNextToken(parser);
        arbExpectToken(parser,0x15);
        stateKind = ((int (*)())arbParseLightNumber)(parser);
        binding[3] = stateKind;
        arbExpectToken(parser,0x16);
        arbExpectToken(parser,0x11);
        binding[4] = 0;
        if (parser[5] == 0) {
          if (parser[6] == 3) {
            binding[4] = 1;
LAB_0008a31c:
            arbNextToken(parser);
            arbExpectToken(parser,0x11);
            if (parser[5] != 0) goto LAB_0008a38c;
          }
          else if (parser[6] == 0xd) goto LAB_0008a31c;
          tokenValue = parser[6];
          if (tokenValue == 6) {
            stateKind = 0x14;
            goto LAB_00089fc4;
          }
          if (tokenValue == 0x25) {
            stateKind = 0x15;
            goto LAB_00089fc4;
          }
          if (tokenValue == 1) {
            stateKind = 0x13;
            goto LAB_00089fc4;
          }
        }
LAB_0008a38c:
        errorMessage = "invalid light product property";
        break;
      case 0x15:
        if (parser[5] != 0) goto LAB_0008a570;
        arbNextToken(parser);
        arbExpectToken(parser,0x11);
        binding[3] = 0;
        if (parser[5] == 0) {
          if (parser[6] == 3) {
            binding[3] = 1;
LAB_00089ec0:
            arbNextToken(parser);
            arbExpectToken(parser,0x11);
            if (parser[5] != 0) goto switchD_00089f14_caseD_0;
          }
          else if (parser[6] == 0xd) goto LAB_00089ec0;
          switch(parser[6]) {
          default:
            goto switchD_00089f14_caseD_0;
          case 1:
            stateKind = 5;
            break;
          case 6:
            stateKind = 6;
            break;
          case 8:
            stateKind = 8;
            break;
          case 0x24:
            stateKind = 9;
            break;
          case 0x25:
            stateKind = 7;
          }
          goto LAB_00089fc4;
        }
switchD_00089f14_caseD_0:
        errorMessage = "invalid material property";
        break;
      case 0x16:
        if (parser[5] != 0) goto LAB_0008a570;
        arbNextToken(parser);
        arbExpectToken(parser,0x11);
        if (parser[5] != 0) {
          arbSetError(parser,"invalid matrix property");
        }
        switch(parser[6]) {
        case 0x17:
          firstIndex = 0;
          arbNextToken(parser);
          binding[2] = 0x1a;
          if (parser[5] == 0x15) {
            arbNextToken(parser);
            if (((parser[5] == 0xf) && (firstIndex = parser[6], -1 < firstIndex)) &&
               (firstIndex < (int)(uint)(byte)((unsigned char *)0x000013b4)[*parser])) {
              arbNextToken(parser);
            }
            else {
              firstIndex = 0;
              arbSetError(parser,"invalid modelview matrix number");
            }
            arbExpectToken(parser,0x16);
          }
          binding[3] = firstIndex;
          break;
        case 0x18:
          arbNextToken(parser);
          binding[2] = 0x22;
          break;
        case 0x19:
          arbNextToken(parser);
          binding[2] = 0x2a;
          arbExpectToken(parser,0x15);
          arbSetError(parser,"invalid palette matrix number");
          binding[3] = 0;
          arbExpectToken(parser,0x16);
          break;
        default:
          arbSetError(parser,"invalid matrix property");
          break;
        case 0x1d:
          arbNextToken(parser);
          binding[2] = 0x2e;
          arbExpectToken(parser,0x15);
          if (((parser[5] == 0xf) && (firstIndex = parser[6], -1 < firstIndex)) &&
             (firstIndex < *(int *)(((unsigned char *)0x0000149c) + *parser))) {
            arbNextToken(parser);
          }
          else {
            firstIndex = 0;
            arbSetError(parser,"invalid program matrix number");
          }
          binding[3] = firstIndex;
          arbExpectToken(parser,0x16);
          break;
        case 0x1e:
          arbNextToken(parser);
          binding[2] = 0x1e;
          break;
        case 0x2a:
          arbNextToken(parser);
          binding[2] = 0x26;
          stateKind = ((int (*)())arbParseTexCoordNumber)(parser);
          binding[3] = stateKind;
        }
        if (parser[5] == 0x11) {
          arbNextToken(parser);
          if (parser[5] != 0) {
            errorMessage = "invalid matrix modifier";
            break;
          }
          tokenValue = parser[6];
          if (tokenValue == 0x10) {
            arbNextToken(parser);
            notRangeToken = parser[5] != 0x11;
            if (!notRangeToken) {
              arbNextToken(parser);
            }
            binding[4] = 3;
LAB_0008a838:
            if (notRangeToken) goto LAB_0008a960;
          }
          else {
            if (tokenValue == 0x2b) {
              arbNextToken(parser);
              notRangeToken = parser[5] != 0x11;
              if (!notRangeToken) {
                arbNextToken(parser);
              }
              binding[4] = 2;
              goto LAB_0008a838;
            }
            if (tokenValue == 0xf) {
              arbNextToken(parser);
              notRangeToken = parser[5] != 0x11;
              if (!notRangeToken) {
                arbNextToken(parser);
              }
              binding[4] = 1;
              goto LAB_0008a838;
            }
            binding[4] = 0;
          }
          if ((parser[5] == 0) && (parser[6] == 0x21)) {
            arbNextToken(parser);
            arbExpectToken(parser,0x15);
            matrixRowNumber = ((int (*)())arbParseMatrixRowNumber)(parser);
            lastIndex = matrixRowNumber;
            if ((allowRange != 0) && (parser[5] == 0x12)) {
              arbNextToken(parser);
              lastIndex = ((int (*)())arbParseMatrixRowNumber)(parser);
              if (lastIndex < matrixRowNumber) {
                errorMessage = "invalid matrix row range";
                break;
              }
            }
            firstIndex = matrixRowNumber + 1;
            arbExpectToken(parser,0x16);
LAB_0008a984:
            binding[2] = matrixRowNumber + binding[2];
            for (; firstIndex <= lastIndex; firstIndex = firstIndex + 1) {
              rangeBinding = (undefined4 *)arbAllocBindingEntry(parser,variable);
              modifier = binding[2];
              stateKind = *binding;
              elementField8 = binding[1];
              elementField12 = binding[3];
              rangeBinding[2] = modifier;
              *rangeBinding = stateKind;
              rangeBinding[1] = elementField8;
              rangeBinding[3] = elementField12;
              stateKind = binding[4];
              rangeBinding[2] = modifier + 1;
              rangeBinding[4] = stateKind;
              binding = rangeBinding;
            }
            return;
          }
          errorMessage = "invalid matrix row selector";
        }
        else {
LAB_0008a960:
          if (allowRange != 0) {
            lastIndex = 3;
            matrixRowNumber = 0;
            firstIndex = 1;
            goto LAB_0008a984;
          }
          errorMessage = "missing matrix row selector";
        }
        break;
      case 0x29:
        if (parser[5] != 0) goto LAB_0008a570;
        firstIndex = 0;
        arbNextToken(parser);
        if (parser[5] == 0x15) {
          arbNextToken(parser);
          if (((parser[5] != 0xf) || (firstIndex = parser[6], firstIndex < 0)) ||
             ((int)(uint)(byte)((unsigned char *)0x000013b2)[*parser] <= firstIndex)) {
            arbSetError(parser,"invalid legacy texture unit");
            firstIndex = parser[6];
          }
          arbNextToken(parser);
          arbExpectToken(parser,0x16);
        }
        binding[3] = firstIndex;
        arbExpectToken(parser,0x11);
        if ((parser[5] == 0) && (parser[6] == 4)) {
          stateKind = 0x19;
          goto LAB_00089fc4;
        }
        errorMessage = "invalid texenv property";
      }
LAB_0008a9fc:
      arbSetError(parser,errorMessage);
      return;
    }
    if ((tokenBit & 0x6000000) == 0) goto LAB_0008aaa0;
    if (isArrayElement == 0) {
      errorMessage = "consecutive sign operators";
      goto LAB_0008ab20;
    }
  }
  binding = (undefined4 *)arbAllocBindingEntry(parser,variable);
  binding[2] = 0x34;
  *binding = 2;
  if (0x1a < (uint)parser[5]) {
LAB_000898c0:
    arbSetError(parser,"invalid constant");
    return;
  }
  tokenBit = 1 << (parser[5] & 0x3fU);
  if ((tokenBit & 0x6018000) != 0) {
    constantValue = (double)((double (*)())arbParseFloatConstant)(parser);
    constVecX = (float)constantValue;
    constVecY = constVecX;
    constVecZ = constVecX;
    stateKind = arbInternConstant(parser,&constVecX);
    binding[3] = stateKind;
    return;
  }
  if ((tokenBit & 0x800000) == 0) goto LAB_000898c0;
  arbNextToken(parser);
  constVecZ = 0.0;
  constVecY = 0.0;
  constantValue = (double)((double (*)())arbParseFloatConstant)(parser);
  constVecX = (float)constantValue;
  if (parser[5] == 0x13) {
    arbNextToken(parser);
    constantValue = (double)((double (*)())arbParseFloatConstant)(parser);
    constVecY = (float)constantValue;
    if (parser[5] == 0x13) {
      arbNextToken(parser);
      constantValue = (double)((double (*)())arbParseFloatConstant)(parser);
      constVecZ = (float)constantValue;
      if (parser[5] == 0x13) {
        arbNextToken(parser);
        ((double (*)())arbParseFloatConstant)(parser);
        goto LAB_000899e0;
      }
    }
  }
  if ((parser[10] < 0) && (parser[0xb] == -1)) {
    parser[0xb] = parser[9];
    parser[0xc] = (int)
                   "warning: <paramConstVector> rule match where parser is supplying some default component(s)"
    ;
  }
LAB_000899e0:
  arbExpectToken(parser,0x18);
  stateKind = arbInternConstant(parser,&constVecX);
  binding[3] = stateKind;
  return;
}

/* arbParseFragmentAttribBinding @ 0x8ace0 (464 bytes) */
int arbParseFragmentAttribBinding(parser, variable)
  int parser;
  int variable;
{
  uint attribute;
  undefined4 colorType;
  char *errorMessage;
  
  if ((*(int *)(parser + 0x14) == 0) && (*(int *)(parser + 0x18) == 0xc)) {
    *(undefined4 *)(variable + 0x18) = 1;
    arbNextToken(parser);
    arbExpectToken(parser,0x11);
    if (*(int *)(parser + 0x14) != 0) {
      arbSetError(parser,"invalid fragment attribute binding item");
    }
    attribute = *(uint *)(parser + 0x18);
    if (attribute == 0xb) {
      arbNextToken(parser);
      *(undefined4 *)(variable + 0x20) = 3;
      return;
    }
    if (attribute < 0xc) {
      if (attribute == 4) {
        arbNextToken(parser);
        *(undefined4 *)(variable + 0x20) = 1;
        colorType = 0;
        if (*(int *)(parser + 0x14) == 0x11) {
          arbNextToken(parser);
          if (*(int *)(parser + 0x14) == 0) {
            if (*(int *)(parser + 0x18) == 0x1c) {
              arbNextToken(parser);
              colorType = 0;
            }
            else if (*(int *)(parser + 0x18) == 0x23) {
              arbNextToken(parser);
              colorType = 1;
            }
            else {
              *(int *)(parser + 0xc) = *(int *)(parser + 8) + -1;
              arbNextToken(parser);
              colorType = 0;
            }
          }
          else {
            arbSetError(parser,"invalid color type");
            colorType = 0;
          }
        }
        *(undefined4 *)(variable + 0x24) = colorType;
        return;
      }
    }
    else {
      if (attribute == 0x1b) {
        arbNextToken(parser);
        *(undefined4 *)(variable + 0x20) = 4;
        return;
      }
      if (attribute == 0x28) {
        arbNextToken(parser);
        *(undefined4 *)(variable + 0x20) = 2;
        colorType = ((int (*)())arbParseTexCoordNumber)(parser);
        *(undefined4 *)(variable + 0x24) = colorType;
        return;
      }
    }
    errorMessage = "invalid fragment attribute binding item";
  }
  else {
    errorMessage = "invalid fragment attribute binding";
  }
  arbSetError(parser,errorMessage);
  return;
}

/* arbParseComponentToken @ 0x8aec0 (136 bytes) */
int arbParseComponentToken(parser)
  int parser;
{
  undefined4 componentIndex;
  
  if ((*(int *)(parser + 0x14) == 0) &&
     (*(int *)(parser + 0xc) - (int)*(byte **)(parser + 8) == 1)) {
    componentIndex = arbComponentLetterToIndex(parser,(uint)**(byte **)(parser + 8));
    arbNextToken(parser);
  }
  else {
    componentIndex = 0;
    arbSetError(parser,"invalid component");
  }
  return componentIndex;
}

/* arbParseSourceRegister @ 0x8b160 (864 bytes) */
int arbParseSourceRegister(parser, operand, unused)
  int parser;
  int *operand;
  undefined4 unused;
{
  int variable;
  int variableKind;
  char *errorMessage;
  uint tokenKind;
  
  tokenKind = *(uint *)(parser + 0x14);
  if (tokenKind < 0x11) {
    if (0xe < tokenKind) goto LAB_0008b1f0;
    if (tokenKind != 0) goto LAB_0008b1a0;
    variable = *(int *)(parser + 0x18);
    if ((variable == 0x1d) || (variable == 0x27)) goto LAB_0008b1f0;
    if (variable == 0xc) {
      variable = arbAllocVariable(parser);
      if (variable == 0) {
        return;
      }
LAB_0008b270:
      *operand = variable;
      if (*(int *)(parser + 0x14) != 0) {
        arbErrorInternal(parser);
        return;
      }
      if (*(int *)(parser + 0x18) == 0xc) {
        ((int (*)())arbParseFragmentAttribBinding)(parser,variable);
      }
      else {
        arbNextToken(parser);
      }
      operand[6] = 0;
      return;
    }
    variable = arbParseVariableName(parser);
    if (variable == 0) {
      errorMessage = "undefined variable";
      goto LAB_0008b220;
    }
    variableKind = *(int *)(variable + 0x18);
    if (variableKind == 1) goto LAB_0008b270;
    if (variableKind == 0) {
      operand[6] = 0;
      *operand = variable;
      arbNextToken(parser);
      return;
    }
    if (variableKind != 2) {
      if (variableKind != 3) {
        arbErrorInternal(parser);
        return;
      }
      errorMessage = "invalid source register type";
      goto LAB_0008b220;
    }
  }
  else {
    if (tokenKind != 0x17) {
LAB_0008b1a0:
      errorMessage = "invalid source register";
LAB_0008b220:
      arbSetError(parser,errorMessage);
      return;
    }
LAB_0008b1f0:
    variable = arbAllocVariable(parser);
    if (variable == 0) {
      return;
    }
  }
  *operand = variable;
  tokenKind = *(uint *)(parser + 0x14);
  if (tokenKind < 0x11) {
    if (tokenKind < 0xf) {
      if (tokenKind == 0) {
        if ((*(int *)(parser + 0x18) != 0x1d) && (*(int *)(parser + 0x18) != 0x27)) {
          if (*(int *)(variable + 0xc) == 0) {
            arbNextToken(parser);
            operand[6] = 0;
            return;
          }
          arbNextToken(parser);
          arbExpectToken(parser,0x15);
          if (*(int *)(parser + 0x14) == 0xf) {
            variableKind = *(int *)(parser + 0x18);
            operand[6] = variableKind;
            if (variableKind <= *(int *)(variable + 0xc)) {
              arbNextToken(parser);
              arbExpectToken(parser,0x16);
              return;
            }
            errorMessage = "invalid array index";
          }
          else {
            errorMessage = "invalid array addressing";
          }
          arbSetError(parser,errorMessage);
          return;
        }
        ((int (*)())arbParseParamBinding)(parser,variable,0,0);
        operand[6] = 0;
        return;
      }
LAB_0008afa0:
      arbErrorInternal(parser);
      return;
    }
  }
  else if (tokenKind != 0x17) goto LAB_0008afa0;
  ((int (*)())arbParseParamBinding)(parser,variable,0,0);
  operand[6] = 0;
  return;
}

/* arbParseExtendedSwizzleSelector @ 0x8b300 (396 bytes) */
int arbParseExtendedSwizzleSelector(parser, signState)
  int parser;
  int *signState;
{
  uint letterBit;
  int expectedSign;
  int sign;
  byte letterIndex;
  int selectorSign;
  undefined4 selector;
  
  sign = arbParseOptionalSign(parser);
  if (*(int *)(parser + 0x14) == 0) {
    letterIndex = **(char **)(parser + 8) + 0x9f;
    if (letterIndex < 0x1a) {
      selectorSign = 1;
      letterBit = 1 << ((int)(char)letterIndex & 0x3fU);
      if (((letterBit & 0x20043) == 0) && (selectorSign = 0, (letterBit & 0x3c00000) == 0)) goto LAB_0008b3d0;
    }
    else {
LAB_0008b3d0:
      selectorSign = -1;
    }
    selector = ((int (*)())arbParseComponentToken)(parser);
    expectedSign = *signState;
    if (*signState == -1) {
      *signState = selectorSign;
      expectedSign = selectorSign;
    }
    if (selectorSign == expectedSign) goto LAB_0008b41c;
  }
  else if (*(int *)(parser + 0x14) == 0xf) {
    if (*(int *)(parser + 0x18) == 0) {
      selector = 4;
      arbNextToken(parser);
      goto LAB_0008b41c;
    }
    if (*(int *)(parser + 0x18) == 1) {
      selector = 5;
      arbNextToken(parser);
      goto LAB_0008b41c;
    }
  }
  selector = 0;
  arbSetError(parser,"invalid extended swizzle selector");
LAB_0008b41c:
  if (sign == -1) {
    switch(selector) {
    case 0:
      selector = 6;
      break;
    case 1:
      selector = 7;
      break;
    case 2:
      selector = 8;
      break;
    case 3:
      selector = 9;
      break;
    case 4:
      selector = 4;
      break;
    case 5:
      selector = 10;
      break;
    default:
      arbErrorInternal(parser);
    }
  }
  return selector;
}

/* arbParseDestRegister @ 0x8b4b0 (496 bytes) */
int arbParseDestRegister(parser, destination)
  int parser;
  int *destination;
{
  bool sameStyle;
  int variable;
  uint componentBit;
  char maskStyle;
  char letterStyle;
  uint writeMask;
  byte *letter;
  
  if (*(int *)(parser + 0x14) == 0) {
    if (*(int *)(parser + 0x18) == 0x20) {
      variable = arbAllocVariable(parser);
      if (variable != 0) {
        arbParseResultBinding(parser,variable + 0x18);
      }
    }
    else {
      variable = arbParseVariableName(parser);
      if (variable == 0) {
        arbSetError(parser,"undefined variable");
      }
      else {
        writeMask = *(uint *)(variable + 0x18);
        if (writeMask < 3) {
          if (writeMask == 0) {
LAB_0008b558:
            arbNextToken(parser);
          }
          else {
            variable = 0;
            arbSetError(parser,"invalid destination register type");
          }
        }
        else {
          if (writeMask == 3) goto LAB_0008b558;
          variable = 0;
          arbErrorInternal(parser);
        }
      }
    }
  }
  else {
    variable = 0;
    arbSetError(parser,"invalid destination register");
  }
  *destination = variable;
  writeMask = 0xf;
  if (*(int *)(parser + 0x14) == 0x11) {
    arbNextToken(parser);
    if (*(int *)(parser + 0x14) == 0) {
      letter = *(byte **)(parser + 8);
      if ((int)*(byte **)(parser + 0xc) - (int)letter < 5) {
        writeMask = 0;
        if (letter < *(byte **)(parser + 0xc)) {
          maskStyle = '\x02';
          do {
            componentBit = arbComponentLetterToIndex(parser,(uint)*letter);
            componentBit = 1 << (componentBit & 0x3f);
            letterStyle = 3 < (byte)(**(char **)(parser + 8) + 0x89U);
            if ((maskStyle == '\x02') || (sameStyle = maskStyle == letterStyle, letterStyle = maskStyle, sameStyle)) {
              if (writeMask < componentBit) {
                writeMask = writeMask | componentBit;
              }
              else {
                arbSetError(parser,"invalid writemask order");
              }
            }
            else {
              arbSetError(parser,"invalid writemask components");
            }
            letter = letter + 1;
            maskStyle = letterStyle;
          } while (letter < *(byte **)(parser + 0xc));
        }
        arbNextToken(parser);
        goto LAB_0008b6a0;
      }
    }
    writeMask = 0xf;
    arbSetError(parser,"invalid writemask");
  }
LAB_0008b6a0:
  destination[1] = writeMask;
  return;
}

/* arbParseSwizzleSuffix @ 0x8b6d0 (624 bytes) */
int arbParseSwizzleSuffix(parser, operand)
  int parser;
  int operand;
{
  char letter;
  int signOrSuffixLength;
  undefined4 componentIndex;
  undefined4 in_r5;
  char *suffixText;
  
  signOrSuffixLength = arbParseOptionalSign(parser);
  if (signOrSuffixLength == -1) {
    *(undefined1 *)(operand + 0x14) = 1;
  }
  else {
    *(undefined1 *)(operand + 0x14) = 0;
  }
  ((int (*)())arbParseSourceRegister)(parser,operand,in_r5);
  if (*(int *)(parser + 0x14) != 0x11) {
    *(undefined4 *)(operand + 4) = 0;
    *(undefined4 *)(operand + 0x10) = 3;
    *(undefined4 *)(operand + 8) = 1;
    *(undefined4 *)(operand + 0xc) = 2;
    return;
  }
  arbNextToken(parser);
  if (*(int *)(parser + 0x14) == 0) {
    signOrSuffixLength = *(int *)(parser + 0xc) - (int)*(byte **)(parser + 8);
    if ((signOrSuffixLength == 1) || (signOrSuffixLength == 4)) {
      componentIndex = arbComponentLetterToIndex(parser,(uint)**(byte **)(parser + 8));
      *(undefined4 *)(operand + 4) = componentIndex;
      if (*(int *)(parser + 0xc) - *(int *)(parser + 8) < 2) {
        *(undefined4 *)(operand + 0x10) = componentIndex;
        *(undefined4 *)(operand + 8) = componentIndex;
        *(undefined4 *)(operand + 0xc) = componentIndex;
      }
      else {
        componentIndex = arbComponentLetterToIndex(parser,(uint)*(byte *)(*(int *)(parser + 8) + 1));
        *(undefined4 *)(operand + 8) = componentIndex;
        componentIndex = arbComponentLetterToIndex(parser,(uint)*(byte *)(*(int *)(parser + 8) + 2));
        *(undefined4 *)(operand + 0xc) = componentIndex;
        componentIndex = arbComponentLetterToIndex(parser,(uint)*(byte *)(*(int *)(parser + 8) + 3));
        *(undefined4 *)(operand + 0x10) = componentIndex;
        suffixText = *(char **)(parser + 8);
        if ((byte)(*suffixText + 0x89U) < 4) {
          letter = suffixText[1];
          if (((((letter != 'r') && (letter != 'g')) && (letter != 'b')) &&
              (((letter != 'a' && (letter = suffixText[2], letter != 'r')) &&
               (((letter != 'g' && ((letter != 'b' && (letter != 'a')))) &&
                (letter = suffixText[3], letter != 'r')))))) &&
             (((letter != 'g' && (letter != 'b')) && (letter != 'a')))) goto LAB_0008b93c;
        }
        else if (((((3 < (byte)(suffixText[1] + 0x89U)) && (letter = suffixText[2], letter != 'x')) &&
                  (letter != 'y')) &&
                 (((letter != 'z' && (letter != 'w')) &&
                  ((letter = suffixText[3], letter != 'x' && ((letter != 'y' && (letter != 'z')))))))) &&
                (letter != 'w')) goto LAB_0008b93c;
        arbSetError(parser,"invalid swizzle suffix");
      }
LAB_0008b93c:
      arbNextToken(parser);
      return;
    }
  }
  arbSetError(parser,"invalid swizzle suffix");
  return;
}

/* arbfpParseScalarSourceOperand @ 0x8b960 (132 bytes) */
int arbfpParseScalarSourceOperand(parser, operand)
  undefined4 parser;
  int operand;
{
  int sign;
  undefined4 componentIndex;
  undefined4 in_r5;
  
  sign = arbParseOptionalSign(parser);
  if (sign == -1) {
    *(undefined1 *)(operand + 0x14) = 1;
  }
  else {
    *(undefined1 *)(operand + 0x14) = 0;
  }
  ((int (*)())arbParseSourceRegister)(parser,operand,in_r5);
  arbExpectToken(parser,0x11);
  componentIndex = ((int (*)())arbParseComponentToken)(parser);
  *(undefined4 *)(operand + 0x10) = componentIndex;
  *(undefined4 *)(operand + 4) = componentIndex;
  *(undefined4 *)(operand + 8) = componentIndex;
  *(undefined4 *)(operand + 0xc) = componentIndex;
  return;
}

/* arbParseProgramText @ 0x8b9f0 (2664 bytes) */
int arbParseProgramText(parser)
  int *parser;
{
  char headerChar;
  uint kindBit;
  int value;
  char *cursor;
  char *nextCursor;
  int *instructionRecord;
  undefined4 passThroughR5;
  uint tokenKind;
  int texImageUnit;
  undefined4 selectorSign [7];
  
  cursor = (char *)parser[3];
  headerChar = *cursor;
  nextCursor = cursor + 1;
  parser[3] = (int)nextCursor;
  if (headerChar == '!') {
    headerChar = cursor[1];
    nextCursor = cursor + 2;
    parser[3] = (int)nextCursor;
    if (headerChar == '!') {
      headerChar = cursor[2];
      nextCursor = cursor + 3;
      parser[3] = (int)nextCursor;
      if (headerChar == 'A') {
        headerChar = cursor[3];
        nextCursor = cursor + 4;
        parser[3] = (int)nextCursor;
        if (headerChar == 'R') {
          headerChar = cursor[4];
          nextCursor = cursor + 5;
          parser[3] = (int)nextCursor;
          if (headerChar == 'B') {
            headerChar = cursor[5];
            nextCursor = cursor + 6;
            parser[3] = (int)nextCursor;
            if (headerChar == 'f') {
              headerChar = cursor[6];
              nextCursor = cursor + 7;
              parser[3] = (int)nextCursor;
              if (headerChar == 'p') {
                headerChar = cursor[7];
                nextCursor = cursor + 8;
                parser[3] = (int)nextCursor;
                if (headerChar == '1') {
                  headerChar = cursor[8];
                  nextCursor = cursor + 9;
                  parser[3] = (int)nextCursor;
                  if (headerChar == '.') {
                    headerChar = cursor[9];
                    nextCursor = cursor + 10;
                    parser[3] = (int)nextCursor;
                    if (headerChar == '0') {
                      arbNextToken(parser);
                      tokenKind = parser[5];
                      while (tokenKind == 8) {
                        arbNextToken(parser);
                        if (parser[5] == 1) {
                          *(undefined1 *)((int)parser + parser[6] + 0x34) = 1;
                          arbNextToken(parser);
                        }
                        else {
                          arbSetError(parser,"invalid option name");
                        }
                        arbExpectToken(parser,0x14);
                        tokenKind = parser[5];
                      }
LAB_0008bbb0:
                      if ((tokenKind == 6) || (tokenKind == 0x1c)) {
                        arbExpectToken(parser,6);
                        arbExpectToken(parser,0x1c);
                        return (uint)parser[10] >> 0x1f;
                      }
                      if (tokenKind < 0xe) {
                        kindBit = 1 << (tokenKind & 0x3f);
                        if ((kindBit & 0x3618) != 0) {
                          if (parser[0x9014] < *(int *)(((unsigned char *)0x00001204) + *parser)) {
                            instructionRecord = parser + (parser[0x9014] + parser[0x9015]) * 0x18 + 0x14;
                            switch(tokenKind) {
                            case 3:
                              *instructionRecord = parser[6];
                              arbNextToken(parser);
                              ((int (*)())arbParseDestRegister)(parser,instructionRecord + 1);
                              arbExpectToken(parser,0x13);
                              ((int (*)())arbParseSwizzleSuffix)(parser,instructionRecord + 3);
                              arbExpectToken(parser,0x13);
                              ((int (*)())arbParseSwizzleSuffix)(parser,instructionRecord + 10);
                              instructionRecord[0x11] = 0;
                              break;
                            case 4:
                              *instructionRecord = parser[6];
                              arbNextToken(parser);
                              ((int (*)())arbParseDestRegister)(parser,instructionRecord + 1);
                              arbExpectToken(parser,0x13);
                              ((int (*)())arbfpParseScalarSourceOperand)(parser,instructionRecord + 3);
                              arbExpectToken(parser,0x13);
                              ((int (*)())arbfpParseScalarSourceOperand)(parser,instructionRecord + 10);
                              instructionRecord[0x11] = 0;
                              break;
                            default:
                              arbErrorInternal(parser);
                              break;
                            case 9:
                              *instructionRecord = parser[6];
                              arbNextToken(parser);
                              ((int (*)())arbParseDestRegister)(parser,instructionRecord + 1);
                              arbExpectToken(parser,0x13);
                              ((int (*)())arbfpParseScalarSourceOperand)(parser,instructionRecord + 3);
                              instructionRecord[0x11] = 0;
                              instructionRecord[10] = 0;
                              break;
                            case 10:
                              *instructionRecord = parser[6];
                              arbNextToken(parser);
                              ((int (*)())arbParseDestRegister)(parser,instructionRecord + 1);
                              arbExpectToken(parser,0x13);
                              ((int (*)())arbParseSourceRegister)(parser,instructionRecord + 3,passThroughR5);
                              arbExpectToken(parser,0x13);
                              selectorSign[0] = 0xffffffff;
                              value = ((int (*)())arbParseExtendedSwizzleSelector)(parser,selectorSign);
                              instructionRecord[4] = value;
                              arbExpectToken(parser,0x13);
                              value = ((int (*)())arbParseExtendedSwizzleSelector)(parser,selectorSign);
                              instructionRecord[5] = value;
                              arbExpectToken(parser,0x13);
                              value = ((int (*)())arbParseExtendedSwizzleSelector)(parser,selectorSign);
                              instructionRecord[6] = value;
                              arbExpectToken(parser,0x13);
                              value = ((int (*)())arbParseExtendedSwizzleSelector)(parser,selectorSign);
                              instructionRecord[7] = value;
                              instructionRecord[0x11] = 0;
                              *(undefined1 *)(instructionRecord + 8) = 0;
                              instructionRecord[10] = 0;
                              break;
                            case 0xc:
                              *instructionRecord = parser[6];
                              arbNextToken(parser);
                              ((int (*)())arbParseDestRegister)(parser,instructionRecord + 1);
                              arbExpectToken(parser,0x13);
                              ((int (*)())arbParseSwizzleSuffix)(parser,instructionRecord + 3);
                              arbExpectToken(parser,0x13);
                              ((int (*)())arbParseSwizzleSuffix)(parser,instructionRecord + 10);
                              arbExpectToken(parser,0x13);
                              ((int (*)())arbParseSwizzleSuffix)(parser,instructionRecord + 0x11);
                              break;
                            case 0xd:
                              *instructionRecord = parser[6];
                              arbNextToken(parser);
                              ((int (*)())arbParseDestRegister)(parser,instructionRecord + 1);
                              arbExpectToken(parser,0x13);
                              ((int (*)())arbParseSwizzleSuffix)(parser,instructionRecord + 3);
                              instructionRecord[0x11] = 0;
                              instructionRecord[10] = 0;
                            }
                            parser[0x9014] = parser[0x9014] + 1;
                            goto LAB_0008bba0;
                          }
                          arbSetError(parser,"too many ALU instructions");
                          tokenKind = parser[5];
                          goto LAB_0008bbb0;
                        }
                        if ((kindBit & 0x24) == 0) {
                          if ((kindBit & 0x880) == 0) goto LAB_0008bb90;
                          if (parser[0x9015] < *(int *)(((unsigned char *)0x00001208) + *parser)) {
                            value = parser[0x9015] + parser[0x9014];
                            if (tokenKind == 7) {
                              parser[value * 0x18 + 0x14] = parser[6];
                              arbNextToken(parser);
                              parser[value * 0x18 + 0x15] = 0;
                              ((int (*)())arbParseSwizzleSuffix)(parser,parser + value * 0x18 + 0x17);
                              parser[value * 0x18 + 0x25] = 0;
                              parser[value * 0x18 + 0x1e] = 0;
                            }
                            else if (tokenKind == 0xb) {
                              parser[value * 0x18 + 0x14] = parser[6];
                              arbNextToken(parser);
                              ((int (*)())arbParseDestRegister)(parser,parser + value * 0x18 + 0x15);
                              arbExpectToken(parser,0x13);
                              ((int (*)())arbParseSwizzleSuffix)(parser,parser + value * 0x18 + 0x17);
                              arbExpectToken(parser,0x13);
                              if ((parser[5] != 0) || (parser[6] != 0x2a)) {
                                arbSetError(parser,"invalid texture image unit");
                              }
                              texImageUnit = 0;
                              arbNextToken(parser);
                              if (parser[5] == 0x15) {
                                arbNextToken(parser);
                                if (((parser[5] != 0xf) || (texImageUnit = parser[6], texImageUnit < 0)) ||
                                   ((int)(uint)(byte)((unsigned char *)0x000013b1)[*parser] <= texImageUnit)) {
                                  arbSetError(parser,"invalid texture image unit number");
                                  texImageUnit = parser[6];
                                }
                                arbNextToken(parser);
                                arbExpectToken(parser,0x16);
                              }
                              parser[value * 0x18 + 0x24] = texImageUnit;
                              arbExpectToken(parser,0x13);
                              if (parser[5] != 0xe) {
                                arbSetError(parser,"invalid texture target");
                              }
                              arbNextToken(parser);
                              texImageUnit = parser[6];
                              parser[value * 0x18 + 0x2b] = texImageUnit;
                              if ((*(char *)((int)parser + 0x39) == '\0') && (texImageUnit - 6U < 3)) {
                                arbSetError(parser,"invalid texture target");
                              }
                              parser[value * 0x18 + 0x25] = 0;
                              parser[value * 0x18 + 0x1e] = 0;
                            }
                            else {
                              arbErrorInternal(parser);
                            }
                            parser[0x9015] = parser[0x9015] + 1;
                            goto LAB_0008bba0;
                          }
                          arbSetError(parser,"too many texture instructions");
                          tokenKind = parser[5];
                          goto LAB_0008bbb0;
                        }
                        if ((tokenKind != 2) && (tokenKind != 5)) {
                          arbErrorInternal(parser);
                          tokenKind = parser[5];
                        }
                        if (tokenKind == 2) {
                          arbNextToken(parser);
                          value = arbParseVariableName(parser);
                          if (value != 0) {
                            arbSetError(parser,"redeclared variable name");
                          }
                          instructionRecord = (int *)(**(code **)(*parser + 0xc))(0x10);
                          if (instructionRecord == (int *)0x0) {
                            arbErrorOutOfMemory(parser);
                          }
                          instructionRecord[2] = parser[3] - parser[2];
                          instructionRecord[1] = parser[2];
                          value = parser[0x13];
                          instructionRecord[3] = 0;
                          *instructionRecord = value;
                          parser[0x13] = (int)instructionRecord;
                          arbNextToken(parser);
                          arbExpectToken(parser,0x1b);
                          value = arbParseVariableName(parser);
                          if (value == 0) {
                            arbSetError(parser,"undefined variable binding in alias");
                          }
                          else {
                            instructionRecord[3] = value;
                            arbNextToken(parser);
                          }
                        }
                        else {
                          value = parser[6];
                          if (value == 1) {
                            arbNextToken(parser);
                            value = arbDeclareVariable(parser);
                            if (value != 0) {
                              arbExpectToken(parser,0x1b);
                              ((int (*)())arbParseFragmentAttribBinding)(parser,value);
                            }
                          }
                          else if (value == 0) {
                            arbNextToken(parser);
                            if (parser[5] != 0x1c) {
                              while (value = arbDeclareVariable(parser), value != 0) {
                                *(undefined4 *)(value + 0x20) = 0;
                                *(undefined4 *)(value + 0x18) = 0;
                                if ((parser[5] != 0x13) ||
                                   (arbNextToken(parser), parser[5] == 0x1c)) break;
                              }
                            }
                          }
                          else if (value == 2) {
                            arbNextToken(parser);
                            value = arbDeclareVariable(parser);
                            if (value != 0) {
                              *(undefined4 *)(value + 0x18) = 2;
                              if (parser[5] == 0x15) {
                                arbNextToken(parser);
                                if (parser[5] == 0xf) {
                                  texImageUnit = parser[6];
                                  if ((texImageUnit == 0) || (*(int *)(((unsigned char *)0x000011e4) + *parser) < texImageUnit))
                                  {
                                    arbSetError(parser,"invalid parameter array size");
                                    texImageUnit = 1;
                                  }
                                  else {
                                    arbNextToken(parser);
                                  }
                                }
                                else {
                                  texImageUnit = *(int *)(((unsigned char *)0x000011e4) + *parser) + 1;
                                }
                                *(int *)(value + 0xc) = texImageUnit;
                                texImageUnit = (**(code **)(*parser + 0xc))(texImageUnit * 0x14);
                                *(int *)(value + 0x14) = texImageUnit;
                                *(undefined4 *)(value + 0x10) = 0;
                                if (texImageUnit == 0) {
                                  arbErrorOutOfMemory(parser);
                                }
                                else {
                                  arbExpectToken(parser,0x16);
                                  arbExpectToken(parser,0x1b);
                                  arbExpectToken(parser,0x17);
                                  texImageUnit = parser[5];
                                  while (texImageUnit != 0x1c) {
                                    passThroughR5 = 1;
                                    ((int (*)())arbParseParamBinding)(parser,value,1,1);
                                    if (parser[5] != 0x13) break;
                                    arbNextToken(parser);
                                    texImageUnit = parser[5];
                                  }
                                  if (*(int *)(((unsigned char *)0x000011e4) + *parser) < *(int *)(value + 0xc)) {
                                    *(undefined4 *)(value + 0xc) = *(undefined4 *)(value + 0x10);
                                  }
                                  else if (*(int *)(value + 0xc) != *(int *)(value + 0x10)) {
                                    arbSetError(parser,"array size and binding count mismatch");
                                  }
                                  arbExpectToken(parser,0x18);
                                }
                              }
                              else {
                                *(undefined4 *)(value + 0xc) = 0;
                                arbExpectToken(parser,0x1b);
                                passThroughR5 = 0;
                                ((int (*)())arbParseParamBinding)(parser,value,0,1);
                              }
                            }
                          }
                          else if (value == 3) {
                            arbNextToken(parser);
                            value = arbDeclareVariable(parser);
                            if (value != 0) {
                              arbExpectToken(parser,0x1b);
                              arbParseResultBinding(parser,value + 0x18);
                            }
                          }
                          else {
                            arbErrorInternal(parser);
                          }
                        }
                      }
                      else {
LAB_0008bb90:
                        arbSetError(parser,"invalid statement");
                      }
LAB_0008bba0:
                      arbExpectToken(parser,0x14);
                      tokenKind = parser[5];
                      goto LAB_0008bbb0;
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
  parser[2] = (int)(nextCursor + -1);
  arbSetError(parser,"invalid header");
  return 0;
}

/* arbfpInternParameter @ 0x8c490 (248 bytes) */
int arbfpInternParameter(parser, table, countPtr, capacity, fullMessage, entry)
  undefined4 parser;
  int table;
  uint *countPtr;
  uint capacity;
  undefined4 fullMessage;
  undefined4 *entry;
{
  uint count;
  int cursor;
  undefined4 key3;
  uint tableIndex;
  undefined4 key2;
  uint remaining;
  
  count = *countPtr;
  if (0 < (int)count) {
    tableIndex = 0;
    cursor = table;
    remaining = count;
    do {
      if (((*(int *)(cursor + 8) == entry[2]) && (*(int *)(cursor + 0xc) == entry[3])) &&
         (*(int *)(cursor + 0x10) == entry[4])) {
        if (-1 < (int)tableIndex) {
          entry[1] = tableIndex;
          return tableIndex;
        }
        break;
      }
      tableIndex = tableIndex + 1;
      cursor = cursor + 0x14;
      remaining = remaining - 1;
    } while (remaining != 0);
  }
  if (count < capacity) {
    key2 = entry[2];
    key3 = entry[3];
    entry[1] = count;
    cursor = count * 0x14 + table;
    *(undefined4 *)(table + count * 0x14) = *entry;
    *(undefined4 *)(cursor + 8) = key2;
    *(undefined4 *)(cursor + 0xc) = key3;
    *(uint *)(cursor + 4) = count;
    *(undefined4 *)(cursor + 0x10) = entry[4];
    *countPtr = *countPtr + 1;
  }
  else {
    arbSetError(parser,fullMessage);
    count = 0xffffffff;
  }
  return count;
}

/* arbValidateProgram @ 0x8c590 (3768 bytes) */
int arbValidateProgram(callbacks, program, sourceLength, sourceText)
  int callbacks;
  undefined1 *program;
  int *sourceLength;
  undefined4 sourceText;
{
  uint shiftedBits;
  uint swizzleC;
  uint bitOffset;
  int *outputListNode;
  int *attribListNode;
  int *paramListNode;
  uint swizzleB;
  uint entryFieldA;
  int paramEntry;
  int srcSym2;
  uint swizzleA;
  uint entryType;
  uint symIndex;
  uint opcodeWord;
  uint dstIndex;
  uint writtenLo;
  uint unitCount;
  int *precisionCountNeg;
  int paramEntryType;
  int nextVal;
  int instsLeft;
  int aluCount;
  int outInstOffset;
  int paramBlock;
  int iVar2;
  int totalInsts;
  int arrayCount;
  int internStatus;
  int srcRec;
  int outInsts;
  int hasKill;
  int nextNode;
  int msgLen;
  int srcByteOffset;
  int tempCount;
  int secondListBase;
  int limits;
  int parseResult;
  int loopCounterD;
  int loopCounterC;
  int remaining;
  int loopCounterB;
  int sourceIndex;
  int loopCounter;
  bool moreSources;
  bool noFogOption;
  int declKind;
  undefined1 *unitSlotPtr;
  int *flagCursor;
  byte optionCount;
  uint notPrecisionHint;
  uint maskBit;
  int srcSym1;
  int *workArea;
  undefined4 errorMsgBuf;
  int fogBias;
  int *a2;
  int *in_r7;
  uint *in_r8;
  int sourceCopy;
  int *piVar13;
  uint writtenHi;
  int *piVar15;
  int byteOffset;
  undefined *inst;
  uint opcode;
  uint bitIndex;
  uint *outInst;
  int *declNode;
  int symbolRef;
  int unitTarget [16];
  int *hasFogOption;
  int loopCounterE;
  int arrayLen;
  int *fogOptionCopy;
  int *local_88;
  uint maskLoTmp;
  int *maskHiTmp;
  uint maskLoTmpB;
  int *maskHiTmpB;
  int *local_70;
  int *local_6c;
  int *paramListBase;
  int *attrListBase;
  int hasKillFlag;
  int *instBase;
  
  workArea = (int *)(**(code **)(callbacks + 0xc))(0x24a30,program,sourceLength,sourceText);
  piVar15 = (int *)0x0;
  program[0x54] = 0;
  maskLoTmp = 0;
  maskHiTmp = (int *)0x0;
  maskLoTmpB = 0;
  maskHiTmpB = (int *)0x0;
  if (*(int *)(program + 0x60) != 0) {
    (**(code **)(callbacks + 0x18))(*(int *)(program + 0x60));
    *(undefined4 *)(program + 0x60) = 0;
  }
  *(undefined4 *)(program + 0x10) = 0;
  *(undefined4 *)(program + 100) = 0;
  *(undefined4 *)(program + 0x78) = 0;
  *(undefined4 *)(program + 0x7c) = 0;
  *(undefined4 *)(program + 0x80) = 0;
  *(undefined4 *)(program + 0x84) = 0;
  *(undefined4 *)(program + 0x8c) = 0;
  *(undefined4 *)(program + 0x90) = 0;
  *(undefined4 *)(program + 0x88) = 0;
  *(undefined4 *)(program + 0x74) = 0;
  *(undefined4 *)(program + 0x6c) = 0;
  *(undefined4 *)(program + 0x70) = 0;
  *(undefined4 *)(program + 0x68) = 0;
  *program = 0;
  program[1] = 0;
  program[2] = 0;
  program[3] = 0;
  program[4] = 0;
  program[5] = 0;
  *(undefined4 *)(program + 0xc) = 0;
  if (((unsigned char *)0x000013b1)[callbacks] != '\0') {
    loopCounterB = 0;
    unitSlotPtr = program;
    do {
      *(undefined4 *)(unitSlotPtr + 0x14) = 0;
      loopCounterB = loopCounterB + 1;
      unitSlotPtr = unitSlotPtr + 4;
    } while (loopCounterB < (int)(uint)(byte)((unsigned char *)0x000013b1)[callbacks]);
  }
  if (0 < *(int *)(((unsigned char *)0x000011d4) + callbacks)) {
    loopCounterB = 0;
    do {
      *(undefined1 *)(*(int *)(program + 0x94) + loopCounterB) = 0;
      loopCounterB = loopCounterB + 1;
    } while (loopCounterB < *(int *)(((unsigned char *)0x000011d4) + callbacks));
  }
  sourceCopy = (**(code **)(callbacks + 0xc))((undefined *)((int)sourceLength + 1));
  if (sourceCopy == 0) {
    _free(workArea);
    return;
  }
  a2 = sourceLength;
  _memcpy(sourceCopy,sourceText,sourceLength);
  *(undefined1 *)(sourceCopy + (int)sourceLength) = 0;
  workArea[3] = sourceCopy;
  *workArea = callbacks;
  workArea[1] = sourceCopy;
  workArea[2] = sourceCopy;
  workArea[4] = (int)(sourceCopy + (int)sourceLength);
  workArea[0xb] = -1;
  workArea[10] = -1;
  workArea[9] = 1;
  piVar13 = (int *)((int)((unsigned char *)0x4) + 3);
  remaining = 7;
  workArea[0xc] = (int)"";
  flagCursor = workArea;
  do {
    *(undefined1 *)(flagCursor + 0xd) = 0;
    flagCursor = (int *)((int)flagCursor + 1);
    remaining = remaining + -1;
  } while (remaining != 0);
  workArea[0xf] = 0;
  workArea[0x928b] = 0;
  workArea[0x10] = 0;
  workArea[0x11] = 0;
  workArea[0x12] = 0;
  workArea[0x13] = 0;
  workArea[0x9014] = 0;
  workArea[0x9015] = 0;
  workArea[0x9116] = 0;
  workArea[0x9149] = 0;
  workArea[0x928a] = 0;
  parseResult = ((int (*)())arbParseProgramText)(workArea);
  if (parseResult != 0) {
    limits = *workArea;
    optionCount = *(char *)(workArea + 0xd) == '\x01';
    if (*(char *)((int)workArea + 0x35) == '\x01') {
      optionCount = optionCount + 1;
    }
    if (*(char *)((int)workArea + 0x36) == '\x01') {
      optionCount = optionCount + 1;
    }
    if (optionCount < 2) {
      piVar13 = (int *)(uint)(optionCount == 1);
      notPrecisionHint = *(byte *)((int)workArea + 0x37) ^ 1;
      optionCount = notPrecisionHint == 0;
      precisionCountNeg = (int *)-notPrecisionHint;
      if (*(char *)(workArea + 0xe) == '\x01') {
        optionCount = optionCount + 1;
      }
      hasFogOption = piVar13;
      if (optionCount < 2) {
LAB_0008c88c:
        declNode = (int *)workArea[0xf];
        loopCounterE = 0;
        do {
          if (declNode != (int *)0x0) {
            piVar13 = workArea + 0x914a;
            local_6c = (int *)&DAT_001ac5a4;
            noFogOption = hasFogOption == (int *)0x0;
            fogOptionCopy = hasFogOption;
            piVar15 = workArea + 0x928a;
            local_88 = (int *)&DAT_001ac5a4;
            paramListBase = piVar13;
            attrListBase = piVar15;
            do {
              declKind = declNode[6];
              if (declKind == 1) {
                a2 = workArea + 0x9149;
                in_r8 = (uint *)(declNode + 6);
                in_r7 = local_88 + -0x1a48;
                piVar13 = fogOptionCopy;
                piVar15 = local_88;
                internStatus = ((int (*)())arbfpInternParameter)(workArea,workArea + 0x9117,a2,
                                     *(int *)(((unsigned char *)0x000011ec) + limits) - (int)fogOptionCopy,in_r7,in_r8);
                if (internStatus < 0) goto LAB_0008d2d0;
              }
              else if (declKind == 0) {
                if (*(int *)(((unsigned char *)0x000011dc) + limits) - (int)fogOptionCopy <= workArea[0x928b]) {
                  piVar13 = fogOptionCopy;
                  arbSetError(workArea,"too many temporaries");
                  goto LAB_0008d2d0;
                }
                declNode[7] = workArea[0x928b];
                workArea[0x928b] = workArea[0x928b] + 1;
                piVar13 = fogOptionCopy;
              }
              else if (declKind == 2) {
                arrayCount = declNode[3];
                arrayLen = 1;
                if ((arrayCount == 0) || (arrayLen = arrayCount, 0 < arrayCount)) {
                  loopCounter = 0;
                  byteOffset = 0;
                  do {
                    if (noFogOption) {
                      fogBias = 0;
                    }
                    else {
                      fogBias = 2;
                    }
                    in_r8 = (uint *)(byteOffset + declNode[5]);
                    in_r7 = local_6c + -0x1a4f;
                    a2 = attrListBase;
                    piVar15 = local_6c;
                    fogBias = ((int (*)())arbfpInternParameter)(workArea,paramListBase,attrListBase,
                                          *(int *)(((unsigned char *)0x000011e4) + limits) - fogBias,in_r7,in_r8);
                    if (fogBias < 0) goto LAB_0008d2d0;
                    loopCounter = loopCounter + 1;
                    byteOffset = byteOffset + 0x14;
                  } while (arrayLen != loopCounter);
                }
              }
              else if (declKind != 3) {
                arbErrorInternal(workArea);
                goto LAB_0008d2d0;
              }
              declNode = (int *)*declNode;
              precisionCountNeg = piVar15;
            } while (declNode != (int *)0x0);
          }
          loopCounterE = loopCounterE + 1;
          if (1 < loopCounterE) {
            aluCount = workArea[0x9014];
            piVar13 = *(int **)(((unsigned char *)0x000011d4) + limits);
            totalInsts = aluCount + workArea[0x9015];
            if (totalInsts <= (int)piVar13) {
              noFogOption = hasFogOption == (int *)0x0;
              if (!noFogOption) {
                if (*(char *)(workArea + 0xd) == '\x01') {
                  if (aluCount <= *(int *)(((unsigned char *)0x00001204) + limits) + -3) {
                    if ((int)((int)piVar13 + -3) < totalInsts) goto LAB_0008cad4;
                    goto LAB_0008ca70;
                  }
LAB_0008cab4:
                  arbSetError(workArea,"too many ALU instructions");
                  piVar15 = precisionCountNeg;
                  goto LAB_0008d2d0;
                }
LAB_0008ca70:
                if (*(char *)((int)workArea + 0x35) == '\x01') {
                  if (*(int *)(((unsigned char *)0x00001204) + limits) + -4 < aluCount) goto LAB_0008cab4;
                  if ((int)(piVar13 + -1) < totalInsts) goto LAB_0008cad4;
                }
                if (*(char *)((int)workArea + 0x36) == '\x01') {
                  if (*(int *)(((unsigned char *)0x00001204) + limits) + -2 < aluCount) goto LAB_0008cab4;
                  if ((int)((int)piVar13 + -2) < totalInsts) goto LAB_0008cad4;
                }
              }
              unitCount = (uint)(byte)((unsigned char *)0x000013b1)[limits];
              if (unitCount != 0) {
                piVar15 = unitTarget;
                do {
                  *piVar15 = 0;
                  piVar15 = piVar15 + 1;
                  unitCount = unitCount - 1;
                } while (unitCount != 0);
              }
              if (totalInsts < 1) {
                hasKill = 0;
                loopCounterD = 1;
              }
              else {
                piVar15 = unitTarget;
                writtenLo = 0;
                writtenHi = 0;
                in_r7 = (int *)0x0;
                in_r8 = (uint *)0x0;
                hasKill = 0;
                loopCounterD = 1;
                a2 = (int *)0x0;
                instsLeft = totalInsts;
                do {
                  opcode = *(uint *)((int)a2 + (int)(workArea + 0x14));
                  inst = (undefined *)((int)a2 + (int)(workArea + 0x14));
                  local_70 = piVar15;
                  if (opcode < 0x20) {
                    if ((0x1c < opcode) || (opcode == 0xb)) goto LAB_0008cb94;
LAB_0008cb70:
                    if (*(int *)(*(int *)(inst + 0xc) + 0x18) == 0) {
                      bitIndex = *(uint *)(*(int *)(inst + 0xc) + 0x1c);
                      maskBit = bitIndex - 0x20;
                      if ((int)maskBit < 0) {
                        maskBit = 0;
                        bitIndex = 1 << (bitIndex & 0x3f);
                      }
                      else {
                        bitIndex = 0;
                        maskBit = 1 << (maskBit & 0x3f);
                      }
                      in_r7 = (int *)((uint)in_r7 | maskBit);
                      in_r8 = (uint *)((uint)in_r8 | bitIndex);
                    }
                    srcSym1 = *(int *)(inst + 0x28);
                    if ((srcSym1 != 0) && (*(int *)(srcSym1 + 0x18) == 0)) {
                      bitIndex = *(uint *)(srcSym1 + 0x1c) - 0x20;
                      if ((int)bitIndex < 0) {
                        precisionCountNeg = (int *)((int)((unsigned char *)0x0) + 1);
                        bitIndex = 0;
                        maskBit = 1 << (*(uint *)(srcSym1 + 0x1c) & 0x3f);
                      }
                      else {
                        maskBit = 0;
                        bitIndex = 1 << (bitIndex & 0x3f);
                      }
                      in_r7 = (int *)((uint)in_r7 | bitIndex);
                      in_r8 = (uint *)((uint)in_r8 | maskBit);
                    }
                    srcSym2 = *(int *)(inst + 0x44);
                    if ((srcSym2 != 0) && (*(int *)(srcSym2 + 0x18) == 0)) {
                      bitIndex = *(uint *)(srcSym2 + 0x1c) - 0x20;
                      if ((int)bitIndex < 0) {
                        bitIndex = 0;
                        maskBit = 1 << (*(uint *)(srcSym2 + 0x1c) & 0x3f);
                      }
                      else {
                        maskBit = 0;
                        bitIndex = 1 << (bitIndex & 0x3f);
                      }
                      in_r7 = (int *)((uint)in_r7 | bitIndex);
                      in_r8 = (uint *)((uint)in_r8 | maskBit);
                    }
                    piVar13 = *(int **)(inst + 4);
                    if (piVar13[6] == 0) {
                      bitIndex = piVar13[7] - 0x20;
                      if ((int)bitIndex < 0) {
                        maskLoTmp = 0;
                        maskHiTmp = (int *)(1 << (piVar13[7] & 0x3fU));
                      }
                      else {
                        maskHiTmp = (int *)0x0;
                        maskLoTmp = 1 << (bitIndex & 0x3f);
                      }
                      in_r7 = (int *)((uint)in_r7 | maskLoTmp);
                      in_r8 = (uint *)((uint)in_r8 | (uint)maskHiTmp);
                      precisionCountNeg = maskHiTmp;
                    }
                    if (opcode == 0xb) goto LAB_0008ce38;
LAB_0008cddc:
                    if (piVar13[6] == 0) {
                      bitOffset = piVar13[7] - 0x20;
                      if ((int)bitOffset < 0) {
                        maskLoTmpB = 0;
                        precisionCountNeg = (int *)(1 << (piVar13[7] & 0x3fU));
                        maskHiTmpB = precisionCountNeg;
                      }
                      else {
                        maskLoTmpB = 1 << (bitOffset & 0x3f);
                        maskHiTmpB = (int *)0x0;
                      }
                      writtenLo = writtenLo | maskLoTmpB;
                      writtenHi = writtenHi | (uint)maskHiTmpB;
                      piVar13 = maskHiTmpB;
                    }
                  }
                  else {
                    if (2 < opcode - 0x3d) goto LAB_0008cb70;
LAB_0008cb94:
                    piVar13 = *(int **)(*(int *)(inst + 0xc) + 0x1c);
                    if (*(int *)(*(int *)(inst + 0xc) + 0x18) == 0) {
                      if ((int)(piVar13 + -8) < 0) {
                        shiftedBits = (writtenLo << 1) << (0x1fU - (int)piVar13 & 0x3f) |
                                 writtenHi >> ((uint)piVar13 & 0x3f);
                      }
                      else {
                        shiftedBits = writtenLo >> ((uint)(piVar13 + -8) & 0x3f);
                      }
                      piVar13 = (int *)(shiftedBits & 1);
                      if (piVar13 == (int *)0x0) goto LAB_0008cbd4;
LAB_0008cc20:
                      loopCounterD = loopCounterD + 1;
                      if (opcode != 0xb) {
                        writtenLo = 0;
                        writtenHi = 0;
                        in_r7 = (int *)0x0;
                        in_r8 = (uint *)0x0;
LAB_0008cc50:
                        piVar13 = (int *)(*(int *)(inst + 0x40) * 4);
                        precisionCountNeg = piVar15;
                        if (*(int *)((int)piVar13 + (int)piVar15) == 0) {
                          *(int *)((int)piVar13 + (int)piVar15) = *(int *)(inst + 0x5c);
                          piVar13 = *(int **)(inst + 4);
                        }
                        else {
                          if (*(int *)((int)piVar13 + (int)piVar15) != *(int *)(inst + 0x5c)) {
                            arbSetError(workArea,"multiple targets on texture context");
                            goto LAB_0008d2d0;
                          }
                          piVar13 = *(int **)(inst + 4);
                        }
                        goto LAB_0008cddc;
                      }
                      writtenLo = 0;
                      writtenHi = 0;
                      hasKill = 1;
                      in_r7 = (int *)0x0;
                      in_r8 = (uint *)0x0;
                    }
                    else {
LAB_0008cbd4:
                      if (opcode != 0xb) {
                        if (*(int *)(*(int *)(inst + 4) + 0x18) == 0) {
                          piVar13 = *(int **)(*(int *)(inst + 4) + 0x1c);
                          if ((int)(piVar13 + -8) < 0) {
                            shiftedBits = ((int)in_r7 << 1) << (0x1fU - (int)piVar13 & 0x3f) |
                                     (uint)in_r8 >> ((uint)piVar13 & 0x3f);
                          }
                          else {
                            shiftedBits = (uint)in_r7 >> ((uint)(piVar13 + -8) & 0x3f);
                          }
                          precisionCountNeg = (int *)(shiftedBits & 1);
                          if (precisionCountNeg != (int *)0x0) goto LAB_0008cc20;
                        }
                        goto LAB_0008cc50;
                      }
                      hasKill = 1;
                    }
                  }
LAB_0008ce38:
                  a2 = a2 + 0x18;
                  instsLeft = instsLeft + -1;
                } while (instsLeft != 0);
              }
              piVar15 = precisionCountNeg;
              if (*(int *)(((unsigned char *)0x0000120cU) + limits) < loopCounterD) {
                arbSetError(workArea,"too many indirections");
              }
              else {
                piVar13 = (int *)workArea[0x928a];
                hasKillFlag = hasKill;
                iVar2 = (**(code **)(limits + 0xc))
                                  (totalInsts * 0x70 + (int)(workArea[0x9149] + (int)piVar13) * 0x14 +
                                   workArea[0x9116] * 0x10 + 0x70,hasKill,a2,totalInsts,in_r7,in_r8,piVar13)
                ;
                *(int *)(program + 0x60) = iVar2;
                if (iVar2 != 0) {
                  if (hasKillFlag != 0) {
                    program[3] = 1;
                  }
                  if (*(char *)((int)workArea + 0x3a) == '\x01') {
                    program[5] = 1;
                  }
                  if (noFogOption) {
                    *(int **)(program + 8) = hasFogOption;
                  }
                  else {
                    program[1] = 1;
                    if (*(char *)(workArea + 0xd) == '\x01') {
                      *(undefined4 *)(program + 8) = 0x800;
                    }
                    else if (*(char *)((int)workArea + 0x35) == '\x01') {
                      *(undefined4 *)(program + 8) = 0x801;
                    }
                    else if (*(char *)((int)workArea + 0x36) == '\x01') {
                      *(undefined4 *)(program + 8) = 0x2601;
                    }
                    else {
                      *(undefined4 *)(program + 8) = 0;
                    }
                  }
                  if (((unsigned char *)0x000013b1)[limits] != '\0') {
                    loopCounter = 0;
                    piVar13 = unitTarget;
                    unitSlotPtr = program;
                    do {
                      nextVal = *piVar13;
                      loopCounter = loopCounter + 1;
                      piVar13 = piVar13 + 1;
                      *(int *)(unitSlotPtr + 0x14) = nextVal;
                      unitSlotPtr = unitSlotPtr + 4;
                    } while (loopCounter < (int)(uint)(byte)((unsigned char *)0x000013b1)[limits]);
                  }
                  *(int *)(program + 100) = *(int *)(program + 0x60);
                  *(int *)(program + 0x68) = workArea[0x9014] + workArea[0x9015];
                  *(int *)(program + 0x6c) = workArea[0x9014];
                  *(int *)(program + 0x70) = workArea[0x9015];
                  paramBlock = (workArea[0x9014] + workArea[0x9015]) * 0x70 + *(int *)(program + 0x60) + 0x70
                  ;
                  *(int *)(program + 0x78) = paramBlock;
                  *(int *)(program + 0x7c) = workArea[0x9149];
                  secondListBase = workArea[0x9149] * 0x14 + paramBlock;
                  *(int *)(program + 0x80) = secondListBase;
                  *(int *)(program + 0x84) = workArea[0x928a];
                  *(int *)(program + 0x8c) = workArea[0x928a] * 0x14 + secondListBase;
                  *(int *)(program + 0x90) = workArea[0x9116];
                  tempCount = workArea[0x928b];
                  *(int *)(program + 0x74) = loopCounterD;
                  loopCounterC = 0;
                  *(int *)(program + 0x88) = tempCount;
                  _memcpy(paramBlock,workArea + 0x9117,workArea[0x9149] * 0x14);
                  _memcpy(*(undefined4 *)(program + 0x80),workArea + 0x914a,workArea[0x928a] * 0x14);
                  _memcpy(*(undefined4 *)(program + 0x8c),workArea + 0x9016,workArea[0x9116] << 4);
                  if (0 < workArea[0x9014] + workArea[0x9015]) {
                    loopCounterC = 0;
                    instBase = workArea + 0x14;
                    outInstOffset = 0;
                    srcByteOffset = 0;
                    do {
                      outInsts = *(int *)(program + 100);
                      in_r7 = (int *)((int)instBase + srcByteOffset);
                      outInst = (uint *)(outInstOffset + outInsts);
                      _memset(outInst,0,0x70);
                      *(undefined4 *)(outInstOffset + outInsts) = *(undefined4 *)((int)instBase + srcByteOffset);
                      srcRec = in_r7[1];
                      *(undefined1 *)(loopCounterC + *(int *)(program + 0x94)) = 0;
                      if (srcRec != 0) {
                        dstIndex = *(uint *)(srcRec + 0x1c);
                        outInst[1] = *(uint *)(srcRec + 0x18);
                        outInst[2] = dstIndex;
                        if (*(int *)(srcRec + 0x18) == 3) {
                          if (*(int *)(srcRec + 0x1c) == 1) {
                            program[4] = 1;
                          }
                          else if (*(int *)(srcRec + 0x1c) == 0) {
                            *(char *)(loopCounterC + *(int *)(program + 0x94)) =
                                 (char)*(undefined4 *)(srcRec + 0x24);
                          }
                        }
                      }
                      sourceIndex = 0;
                      outInst[3] = in_r7[2];
                      in_r8 = outInst;
                      do {
                        symbolRef = in_r7[3];
                        if (symbolRef == 0) {
                          opcodeWord = *outInst;
                          if ((0x1c < opcodeWord) &&
                             (((opcodeWord < 0x20 || (opcodeWord - 0x3d < 3)) &&
                              (in_r8[0xb] = in_r7[9], sourceIndex == 1)))) {
                            *(uint *)(program + 0x10) =
                                 1 << (outInst[0x13] & 0x3f) | *(uint *)(program + 0x10);
                          }
                        }
                        else {
                          if (*(int *)(symbolRef + 0xc) == 0) {
                            symIndex = *(uint *)(symbolRef + 0x1c);
                            entryFieldA = *(uint *)(symbolRef + 0x18);
                            in_r8[0xb] = 0;
                            in_r8[5] = symIndex;
                            in_r8[4] = entryFieldA;
                          }
                          else {
                            entryType = *(uint *)(in_r7[9] * 0x14 + *(int *)(symbolRef + 0x14));
                            piVar15 = *(int **)(in_r7[9] * 0x14 + *(int *)(symbolRef + 0x14) + 4);
                            in_r8[0xb] = 0;
                            in_r8[4] = entryType;
                            in_r8[5] = (uint)piVar15;
                          }
                          if (in_r8[4] == 1) {
                            paramEntry = in_r8[5] * 0x14 + *(int *)(program + 0x78);
                            paramEntryType = *(int *)(paramEntry + 8);
                            if (paramEntryType == 1) {
                              if (*(int *)(paramEntry + 0xc) == 1) {
                                *program = 1;
                              }
                            }
                            else if (paramEntryType == 2) {
                              *(uint *)(program + 0xc) =
                                   1 << (*(uint *)(paramEntry + 0xc) & 0x3f) | *(uint *)(program + 0xc);
                            }
                            else if (paramEntryType == 3) {
                              program[1] = 1;
                            }
                            else if (paramEntryType == 4) {
                              program[2] = 1;
                            }
                          }
                          swizzleA = in_r7[5];
                          swizzleB = in_r7[6];
                          swizzleC = in_r7[7];
                          in_r8[6] = in_r7[4];
                          in_r8[7] = swizzleA;
                          in_r8[8] = swizzleB;
                          in_r8[9] = swizzleC;
                          *(undefined1 *)(in_r8 + 10) = *(undefined1 *)(in_r7 + 8);
                        }
                        moreSources = sourceIndex != 2;
                        in_r7 = in_r7 + 7;
                        in_r8 = in_r8 + 8;
                        sourceIndex = sourceIndex + 1;
                      } while (moreSources);
                      loopCounterC = loopCounterC + 1;
                      srcByteOffset = srcByteOffset + 0x60;
                      outInstOffset = outInstOffset + 0x70;
                    } while (loopCounterC < workArea[0x9014] + workArea[0x9015]);
                  }
                  _memset(loopCounterC * 0x70 + *(int *)(program + 100),0,0x70);
                  piVar13 = *(int **)(program + 100);
                  piVar13[loopCounterC * 0x1c] = 0x41;
                  program[0x54] = 1;
                }
              }
              goto LAB_0008d2d0;
            }
LAB_0008cad4:
            arbSetError(workArea,"too many total instructions");
            piVar15 = precisionCountNeg;
            goto LAB_0008d2d0;
          }
          if (loopCounterE == 0) goto LAB_0008c88c;
          declNode = (int *)workArea[0x11];
        } while( true );
      }
      arbSetError(workArea,"more than one precision hint option");
      piVar15 = precisionCountNeg;
    }
    else {
      arbSetError(workArea,"more than one fog option");
    }
  }
LAB_0008d2d0:
  *(int *)(((unsigned char *)0x00001124) + callbacks) = workArea[10];
  if (*(int *)(((unsigned char *)0x00001128) + callbacks) != 0) {
    (**(code **)(callbacks + 0x18))(*(int *)(((unsigned char *)0x00001128) + callbacks));
  }
  msgLen = _strlen(workArea[0xc]);
  errorMsgBuf = (**(code **)(callbacks + 0xc))(msgLen + 0xb);
  *(undefined4 *)(((unsigned char *)0x00001128) + callbacks) = errorMsgBuf;
  if ((uint)workArea[0xb] < 10000) {
    printf_LDBLStub_1a32d0(errorMsgBuf,"line %d: %s",workArea[0xb],workArea[0xc],in_r7,in_r8,piVar13,piVar15);
  }
  else {
    _strcpy(errorMsgBuf,workArea[0xc]);
  }
  if (workArea[1] != 0) {
    (**(code **)(callbacks + 0x18))(workArea[1]);
  }
  paramListNode = (int *)workArea[0xf];
  while (paramListNode != (int *)0x0) {
    if ((int *)paramListNode[5] != paramListNode + 6) {
      (**(code **)(callbacks + 0x18))(paramListNode[5]);
    }
    nextNode = *paramListNode;
    (**(code **)(callbacks + 0x18))(paramListNode);
    paramListNode = (int *)nextNode;
  }
  attribListNode = (int *)workArea[0x11];
  while (attribListNode != (int *)0x0) {
    if ((int *)attribListNode[5] != attribListNode + 6) {
      (**(code **)(callbacks + 0x18))(attribListNode[5]);
    }
    nextNode = *attribListNode;
    (**(code **)(callbacks + 0x18))(attribListNode);
    attribListNode = (int *)nextNode;
  }
  outputListNode = (int *)workArea[0x13];
  while (outputListNode != (int *)0x0) {
    nextNode = *outputListNode;
    (**(code **)(callbacks + 0x18))(outputListNode);
    outputListNode = (int *)nextNode;
  }
                    
                    
  (**(code **)(callbacks + 0x18))(workArea);
  return;
}

/* arbfpUpdateStateForProgram @ 0x8d470 (1744 bytes) */
int arbfpUpdateStateForProgram(context, passThroughArg2, passThroughArg3, passThroughArg4, passThroughArg5, passThroughArg6, passThroughArg7, passThroughArg8)
  int context;
  undefined4 passThroughArg2;
  undefined4 passThroughArg3;
  undefined4 passThroughArg4;
  undefined4 passThroughArg5;
  undefined4 passThroughArg6;
  undefined4 passThroughArg7;
  undefined4 passThroughArg8;
{
  uint stateWord48Masked;
  uint clearedFlags;
  uint slotCountLoop;
  uint pendingWordC;
  uint ctxWord3c;
  uint maxUnits;
  uint pendingWordB;
  byte texUnitCount;
  uint firstUnsetSlot;
  uint pendingWordA;
  uint lastUnsetSlot;
  uint *slotFlagPtr;
  bool fpDisabled;
  uint liveMaskLow;
  undefined1 slotByte;
  uint liveMaskHigh;
  uint loopCounterB;
  undefined *programState;
  char *programObject;
  byte slotCount;
  int loopIndex;
  uint dirtyFlags;
  uint highestLiveSlot;
  uint lastUnsetSlotB;
  char *objectCursor;
  uint unitCountLoop;
  undefined *slotCursor;
  int stateBlock;
  
  programState = ((unsigned char *)0x000011d0U) + context;
  dirtyFlags = *(uint *)(context + 0x44);
  stateBlock = *(int *)(*(int *)(context + 4) + 0x10);
  ((unsigned char *)0x000011d2)[context] = 0;
  ((unsigned char *)0x000011d1)[context] = 0;
  programObject = *(char **)(((unsigned char *)0x0000121c) + context);
  if (*(char *)(*(int *)(programObject + 0x74) + 0x54) == '\0') {
    ((unsigned char *)0x000011d3)[context] = 0;
    *(undefined4 *)(((unsigned char *)0x00001228) + context) = 0;
    if (((unsigned char *)0x000013b1)[context] != '\0') {
      loopIndex = 0;
      slotCursor = programState;
      do {
        *(undefined4 *)(slotCursor + 0x5c) = 0;
        loopIndex = loopIndex + 1;
        slotCursor = slotCursor + 4;
      } while (loopIndex < (int)(uint)(byte)((unsigned char *)0x000013b1)[context]);
    }
    highestLiveSlot = 0xffffffff;
  }
  else {
    liveMaskLow = *(uint *)(programObject + 8);
    ((unsigned char *)0x000011d3)[context] = (char)liveMaskLow;
    liveMaskHigh = *(uint *)(programObject + 0xc);
    *(uint *)(((unsigned char *)0x00001228) + context) = liveMaskHigh;
    unitCountLoop = (uint)(byte)((unsigned char *)0x000013b6)[context];
    highestLiveSlot = unitCountLoop - 1;
    if (-1 < (int)highestLiveSlot) {
      do {
        if (((liveMaskLow & 0xff | liveMaskHigh) >> (highestLiveSlot & 0x3f) & 1) != 0) goto LAB_0008d4f8;
        highestLiveSlot = highestLiveSlot - 1;
        unitCountLoop = unitCountLoop - 1;
      } while (unitCountLoop != 0);
    }
    highestLiveSlot = 0xffffffff;
LAB_0008d4f8:
    maxUnits = (uint)(byte)((unsigned char *)0x000013b1)[context];
    if (maxUnits != 0) {
      loopIndex = 0;
      objectCursor = programObject;
      slotCursor = programState;
      do {
        switch(*(undefined4 *)(objectCursor + 0x10)) {
        case 0:
          *(undefined4 *)(slotCursor + 0x5c) = 0;
          maxUnits = (uint)(byte)((unsigned char *)0x000013b1)[context];
          break;
        case 1:
        case 6:
          *(undefined4 *)(slotCursor + 0x5c) = 0x10;
          maxUnits = (uint)(byte)((unsigned char *)0x000013b1)[context];
          break;
        case 2:
        case 7:
          *(undefined4 *)(slotCursor + 0x5c) = 8;
          maxUnits = (uint)(byte)((unsigned char *)0x000013b1)[context];
          break;
        case 3:
          *(undefined4 *)(slotCursor + 0x5c) = 2;
          maxUnits = (uint)(byte)((unsigned char *)0x000013b1)[context];
          break;
        case 4:
          *(undefined4 *)(slotCursor + 0x5c) = 1;
          maxUnits = (uint)(byte)((unsigned char *)0x000013b1)[context];
          break;
        case 5:
        case 8:
          *(undefined4 *)(slotCursor + 0x5c) = 4;
          maxUnits = (uint)(byte)((unsigned char *)0x000013b1)[context];
        }
        loopIndex = loopIndex + 1;
        objectCursor = objectCursor + 4;
        slotCursor = slotCursor + 4;
      } while (loopIndex < (int)maxUnits);
    }
  }
  fpDisabled = (dirtyFlags >> 0xd & 1) == 0;
  if ((programObject[4] == '\0') || (fpDisabled)) {
    dirtyFlags = *(uint *)(context + 0x44);
    if ((dirtyFlags & 0x200) != 0) {
      ctxWord3c = *(uint *)(context + 0x3c);
      dirtyFlags = dirtyFlags & 0xfffffdff;
      goto LAB_0008d6a4;
    }
  }
  else {
    dirtyFlags = *(uint *)(context + 0x44);
    if ((dirtyFlags & 0x200) == 0) {
      ctxWord3c = *(uint *)(context + 0x3c);
      dirtyFlags = dirtyFlags | 0x200;
LAB_0008d6a4:
      *(uint *)(context + 0x44) = dirtyFlags;
      *(undefined1 *)(context + 0x29) = 1;
      *(uint *)(context + 0x3c) = ctxWord3c | 1;
    }
  }
  if ((*programObject == '\0') || (fpDisabled)) {
    if ((dirtyFlags & 0x1000) != 0) {
      dirtyFlags = dirtyFlags & 0xffffefff;
      *(uint *)(context + 0x44) = dirtyFlags;
      *(undefined1 *)(context + 0x29) = 1;
      *(uint *)(context + 0x38) = *(uint *)(context + 0x38) | 0x1000;
    }
    if ((fpDisabled) && ((dirtyFlags & 0x4000) != 0)) goto joined_r0x0008d734;
    if ((dirtyFlags & 0x10000) != 0) {
      pendingWordC = *(uint *)(context + 0x38);
      dirtyFlags = dirtyFlags & 0xfffeffff;
      goto LAB_0008d760;
    }
  }
  else {
    if ((dirtyFlags & 0x1000) == 0) {
      dirtyFlags = dirtyFlags | 0x1000;
      *(uint *)(context + 0x44) = dirtyFlags;
      *(undefined1 *)(context + 0x29) = 1;
      *(uint *)(context + 0x38) = *(uint *)(context + 0x38) | 0x1000;
    }
joined_r0x0008d734:
    if ((dirtyFlags & 0x10000) == 0) {
      pendingWordC = *(uint *)(context + 0x38);
      dirtyFlags = dirtyFlags | 0x10000;
LAB_0008d760:
      *(uint *)(context + 0x44) = dirtyFlags;
      *(undefined1 *)(context + 0x29) = 1;
      *(uint *)(context + 0x38) = pendingWordC | 0x20;
    }
  }
  if ((programObject[3] == '\0') || (fpDisabled)) {
    if ((dirtyFlags & 0x100) != 0) {
      pendingWordC = *(uint *)(context + 0x38);
      dirtyFlags = dirtyFlags & 0xfffffeff;
      goto LAB_0008d7b0;
    }
  }
  else if ((dirtyFlags & 0x100) == 0) {
    pendingWordC = *(uint *)(context + 0x38);
    dirtyFlags = dirtyFlags | 0x100;
LAB_0008d7b0:
    *(uint *)(context + 0x44) = dirtyFlags;
    *(undefined1 *)(context + 0x2a) = 1;
    *(uint *)(context + 0x38) = pendingWordC | 1;
    *(undefined1 *)(context + 0x29) = 1;
  }
  if ((programObject[1] == '\0') || (fpDisabled)) {
    if ((dirtyFlags & 0x800) != 0) {
      dirtyFlags = dirtyFlags & 0xfffff7ff;
      *(uint *)(context + 0x44) = dirtyFlags;
      *(uint *)(context + 0x1874) = *(uint *)(context + 0x1874) & 0xffffdfff;
      *(uint *)(context + 0x38) = *(uint *)(context + 0x38) | 0x1000;
      *(undefined1 *)(context + 0x29) = 1;
    }
  }
  else {
    if ((dirtyFlags & 0x800) == 0) {
      dirtyFlags = dirtyFlags | 0x800;
      *(uint *)(context + 0x44) = dirtyFlags;
      *(uint *)(context + 0x1874) = *(uint *)(context + 0x1874) | 0x2000;
    }
    *(undefined1 *)(context + 0x29) = 1;
    *(uint *)(context + 0x38) = *(uint *)(context + 0x38) | 0x1000;
  }
  if ((programObject[2] == '\0') || (fpDisabled)) {
    if ((dirtyFlags & 0x400) != 0) {
      dirtyFlags = dirtyFlags & 0xfffffbff;
      *(uint *)(context + 0x44) = dirtyFlags;
      *(uint *)(context + 0x1874) = *(uint *)(context + 0x1874) & 0xffffefff;
      *(uint *)(context + 0x38) = *(uint *)(context + 0x38) | 0x1000;
      *(undefined1 *)(context + 0x29) = 1;
    }
  }
  else {
    if ((dirtyFlags & 0x400) == 0) {
      dirtyFlags = dirtyFlags | 0x400;
      *(uint *)(context + 0x44) = dirtyFlags;
      *(uint *)(context + 0x1874) = *(uint *)(context + 0x1874) | 0x1000;
    }
    *(undefined1 *)(context + 0x29) = 1;
    *(uint *)(context + 0x38) = *(uint *)(context + 0x38) | 0x1000;
  }
  if ((dirtyFlags & 0xc00) != 0) {
    slotCount = ((unsigned char *)0x000013b0)[context];
    slotCountLoop = (uint)slotCount;
    if (slotCountLoop == 0) {
      firstUnsetSlot = 0xffffffff;
      lastUnsetSlotB = 0xffffffff;
    }
    else {
      loopCounterB = 0;
      firstUnsetSlot = 0xffffffff;
      lastUnsetSlot = 0xffffffff;
      do {
        lastUnsetSlotB = lastUnsetSlot;
        if (((((int)(uint)(byte)((unsigned char *)0x000011d3)[context] >> (loopCounterB & 0x3f) & 1U) == 0) &&
            (lastUnsetSlotB = loopCounterB, lastUnsetSlot != 0xffffffff)) && (lastUnsetSlotB = lastUnsetSlot, firstUnsetSlot == 0xffffffff)) {
          firstUnsetSlot = loopCounterB;
        }
        loopCounterB = loopCounterB + 1;
        slotCountLoop = slotCountLoop - 1;
        lastUnsetSlot = lastUnsetSlotB;
      } while (slotCountLoop != 0);
    }
    if ((dirtyFlags & 0x800) == 0) {
      if ((dirtyFlags & 0x400) != 0) {
        if (lastUnsetSlotB != 0xffffffff) {
          slotCount = (byte)lastUnsetSlotB;
        }
        ((unsigned char *)0x000011d2)[context] = slotCount;
        if ((int)lastUnsetSlotB <= (int)highestLiveSlot) goto LAB_0008d98c;
        dirtyFlags = *(uint *)(context + 0x44);
        highestLiveSlot = lastUnsetSlotB;
      }
    }
    else {
      if (lastUnsetSlotB != 0xffffffff) {
        slotCount = (byte)lastUnsetSlotB;
      }
      ((unsigned char *)0x000011d1)[context] = slotCount;
      if ((int)highestLiveSlot < (int)lastUnsetSlotB) {
        highestLiveSlot = lastUnsetSlotB;
      }
      dirtyFlags = *(uint *)(context + 0x44);
      if ((dirtyFlags & 0x400) != 0) {
        slotByte = (undefined1)firstUnsetSlot;
        if (firstUnsetSlot == 0xffffffff) {
          slotByte = ((unsigned char *)0x000013b0)[context];
        }
        ((unsigned char *)0x000011d2)[context] = slotByte;
        if ((int)highestLiveSlot < (int)firstUnsetSlot) {
          dirtyFlags = *(uint *)(context + 0x44);
          highestLiveSlot = firstUnsetSlot;
        }
        else {
LAB_0008d98c:
          dirtyFlags = *(uint *)(context + 0x44);
        }
      }
    }
  }
  if ((fpDisabled) && (((unsigned char *)0x00002e0a)[stateBlock] != '\0')) {
    if ((dirtyFlags & 0x1000000) == 0) {
      *(uint *)(context + 0x44) = dirtyFlags | 0x1000000;
      pendingWordB = *(uint *)(context + 0x38);
      *(uint *)(context + 0x18a4) = *(uint *)(context + 0x18a4) | 1;
      *(undefined1 *)(context + 0x29) = 1;
      *(uint *)(context + 0x38) = pendingWordB | 0x100;
      if ((((int)dirtyFlags < 0 || (dirtyFlags & 0x800000) != 0) || (dirtyFlags & 0x200000) != 0) ||
          (dirtyFlags & 0x10000) != 0) {
        *(uint *)(context + 0x38) = pendingWordB | 0x120;
      }
    }
  }
  else {
    if ((dirtyFlags & 0x1000000) != 0) {
      clearedFlags = dirtyFlags & 0xfeffffff;
      *(uint *)(context + 0x44) = clearedFlags;
      pendingWordA = *(uint *)(context + 0x38);
      *(uint *)(context + 0x18a4) = *(uint *)(context + 0x18a4) & 0xfffffffe;
      *(undefined1 *)(context + 0x29) = 1;
      *(uint *)(context + 0x38) = pendingWordA | 0x100;
      if ((((int)dirtyFlags < 0 || (clearedFlags >> 0x17 & 1) != 0) || (clearedFlags >> 0x15 & 1) != 0) ||
          (clearedFlags >> 0x10 & 1) != 0) {
        *(uint *)(context + 0x38) = pendingWordA | 0x120;
      }
    }
    if (!fpDisabled) {
      dirtyFlags = (uint)(byte)((unsigned char *)0x000013b1)[context];
      if (dirtyFlags != 0) {
        stateBlock = context;
        if ((dirtyFlags == 0) || (dirtyFlags == 0x80000000)) {
          dirtyFlags = 1;
        }
        do {
          stateWord48Masked = *(uint *)(stateBlock + 0x48) & 0xffffffe0;
          *(uint *)(stateBlock + 0x48) = stateWord48Masked;
          slotFlagPtr = (uint *)(programState + 0x5c);
          programState = programState + 4;
          *(uint *)(stateBlock + 0x48) = stateWord48Masked | *slotFlagPtr;
          stateBlock = stateBlock + 4;
          dirtyFlags = dirtyFlags - 1;
        } while (dirtyFlags != 0);
      }
      if ((int)(uint)*(byte *)(context + 0x2b) <= (int)highestLiveSlot) {
        *(char *)(context + 0x2b) = (char)highestLiveSlot + '\x01';
      }
      texUnitCount = ((unsigned char *)0x000013b6)[context];
      dirtyFlags = *(uint *)(context + 0x3c);
      *(byte *)(context + 0x2e) = *(byte *)(context + 0x2e) | 3;
      *(uint *)(context + 0x38) = *(uint *)(context + 0x38) | 0x2200;
      *(undefined1 *)(context + 0x29) = 1;
      *(ushort *)(context + 0x34) = (short)(1 << (texUnitCount & 0x3f)) - 1U | *(ushort *)(context + 0x34);
      goto LAB_0008da14;
    }
  }
  *(undefined1 *)(context + 0x29) = 1;
  dirtyFlags = *(uint *)(context + 0x3c) | 0x100;
  *(uint *)(context + 0x3c) = dirtyFlags;
LAB_0008da14:
  *(uint *)(context + 0x3c) = dirtyFlags | 0x40;
  *(undefined1 *)(context + 0x29) = 1;
  return;
}

/* arbfpBindProgram @ 0x8dbd0 (100 bytes) */
int arbfpBindProgram(context, programSlot, passThroughArg3, passThroughArg4, passThroughArg5, passThroughArg6, passThroughArg7, passThroughArg8)
  int context;
  int programSlot;
  undefined4 passThroughArg3;
  undefined4 passThroughArg4;
  undefined4 passThroughArg5;
  undefined4 passThroughArg6;
  undefined4 passThroughArg7;
  undefined4 passThroughArg8;
{
  undefined4 programObject;
  
  if (*(int *)(((unsigned char *)0x00001270) + context) != programSlot) {
    *(int *)(((unsigned char *)0x00001270) + context) = programSlot;
    programObject = *(undefined4 *)(programSlot * 0x18 + *(int *)(*(int *)(((unsigned char *)0x0000112c) + context) + 8) + 0x14)
    ;
    *(undefined4 *)(((unsigned char *)0x0000121c) + context) = programObject;
    ((int (*)())arbfpUpdateStateForProgram)(context,programSlot,passThroughArg3,passThroughArg4,passThroughArg5,passThroughArg6,programObject,passThroughArg8);
    ((unsigned char *)0x000011d0)[context] = 1;
  }
  return;
}

/* gldCallHook1278 @ 0x8dc40 (12 bytes) */
int gldCallHook1278(ctx)
  int ctx;
{
                    
                    
  (**(code **)(((unsigned char *)0x00001278) + ctx))();
  return;
}

/* arbfpProgramObjectInit @ 0x8dc50 (336 bytes) */
int arbfpProgramObjectInit(context, programObject)
  int context;
  undefined1 *programObject;
{
  int loopIndex;
  undefined1 *unitSlotPtr;
  undefined4 instanceTable;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int compiledProgram;
  int compiledProgramCopy;
  int unitCount;
  
  *(undefined4 *)(programObject + 0xc) = 0;
  *(undefined4 *)(programObject + 8) = 0;
  programObject[4] = 0;
  *programObject = 0;
  programObject[1] = 0;
  programObject[2] = 0;
  programObject[3] = 0;
  if (((unsigned char *)0x000013b1)[context] != '\0') {
    loopIndex = 0;
    unitSlotPtr = programObject;
    do {
      *(undefined4 *)(unitSlotPtr + 0x10) = 0;
      loopIndex = loopIndex + 1;
      unitSlotPtr = unitSlotPtr + 4;
    } while (loopIndex < (int)(uint)(byte)((unsigned char *)0x000013b1)[context]);
  }
  instanceTable = (**(code **)(context + 0x10))(*(undefined4 *)(*(int *)(((unsigned char *)0x0000112c) + context) + 0x10),4)
  ;
  *(undefined4 *)(programObject + 0x50) = 0;
  *(undefined4 *)(programObject + 0x54) = 0;
  *(undefined4 *)(programObject + 0x70) = instanceTable;
  *(undefined4 *)(programObject + 0x58) = 0;
  programObject[0x6c] = 1;
  *(undefined4 *)(programObject + 0x5c) = 0;
  *(undefined4 *)(programObject + 0x60) = 0;
  *(undefined4 *)(programObject + 100) = 0;
  *(undefined4 *)(programObject + 0x68) = 0;
  compiledProgram = (**(code **)(context + 0xc))(0x98);
  *(int *)(programObject + 0x74) = compiledProgram;
  *(undefined1 *)(compiledProgram + 0x54) = 0;
  *(undefined1 *)(*(int *)(programObject + 0x74) + 0x55) = 0;
  compiledProgramCopy = *(int *)(programObject + 0x74);
  *(undefined4 *)(compiledProgramCopy + 0x60) = 0;
  *(undefined4 *)(*(int *)(programObject + 0x74) + 0x58) = 0;
  unitCount = *(int *)(((unsigned char *)0x000011d4) + context);
  compiledProgramCopy = (**(code **)(context + 0x10))(unitCount,1,in_r5,in_r6,in_r7,in_r8,compiledProgramCopy);
  *(int *)(compiledProgram + 0x94) = compiledProgramCopy;
  if (0 < unitCount) {
    compiledProgram = 0;
    do {
      *(undefined1 *)(compiledProgramCopy + compiledProgram) = 0;
      compiledProgram = compiledProgram + 1;
      unitCount = unitCount + -1;
    } while (unitCount != 0);
  }
  return;
}

/* arbfpProgramObjectFree @ 0x8dda0 (408 bytes) */
int arbfpProgramObjectFree(context, programObject)
  int context;
  undefined1 *programObject;
{
  int loopIndex2;
  int instanceCount;
  undefined1 *unitSlotPtr;
  int instanceTable;
  int stateHolder;
  int loopIndex;
  int instance;

  *(undefined4 *)(programObject + 0xc) = 0;
  *(undefined4 *)(programObject + 8) = 0;
  programObject[4] = 0;
  *programObject = 0;
  programObject[1] = 0;
  programObject[2] = 0;
  programObject[3] = 0;
  if (((unsigned char *)0x000013b1)[context] != '\0') {
    loopIndex2 = 0;
    unitSlotPtr = programObject;
    do {
      *(undefined4 *)(unitSlotPtr + 0x10) = 0;
      loopIndex2 = loopIndex2 + 1;
      unitSlotPtr = unitSlotPtr + 4;
    } while (loopIndex2 < (int)(uint)(byte)((unsigned char *)0x000013b1)[context]);
  }
  instanceTable = *(int *)(programObject + 0x70);
  stateHolder = *(int *)(((unsigned char *)0x0000112c) + context);
  if (instanceTable != 0) {
    instanceCount = *(int *)(stateHolder + 0x10);
    loopIndex = 0;
    if (0 < instanceCount) {
      do {
        /* issue #79 class: the stock's r4 is the slot's object (`lwzx r4,r2,r3` before the `beq`),
         * the callback is (ctx, obj) */
        instance = *(int *)(loopIndex * 4 + instanceTable);
        if (instance != 0) {
          *(undefined4 *)(loopIndex * 4 + instanceTable) = 0;
          ((int (*)())*(code **)(((unsigned char *)0x00001224) + context))(context,instance);
          instanceTable = *(int *)(programObject + 0x70);
          instanceCount = *(int *)(stateHolder + 0x10);
        }
        loopIndex = loopIndex + 1;
      } while (loopIndex < instanceCount);
    }
    (**(code **)(context + 0x18))(instanceTable);
    *(undefined4 *)(programObject + 0x70) = 0;
  }
  instanceTable = *(int *)(programObject + 0x74);
  if (instanceTable != 0) {
    if (*(int *)(instanceTable + 0x60) != 0) {
      (**(code **)(context + 0x18))(*(int *)(instanceTable + 0x60));
      *(undefined4 *)(*(int *)(programObject + 0x74) + 0x60) = 0;
      instanceTable = *(int *)(programObject + 0x74);
    }
    if (*(int *)(instanceTable + 0x94) != 0) {
      (**(code **)(context + 0x18))(*(int *)(instanceTable + 0x94));
      *(undefined4 *)(*(int *)(programObject + 0x74) + 0x94) = 0;
      instanceTable = *(int *)(programObject + 0x74);
    }
    (**(code **)(context + 0x18))(instanceTable);
    *(undefined4 *)(programObject + 0x74) = 0;
  }
  return;
}

/* arbfpProgramString @ 0x8df50 (880 bytes) */
int arbfpProgramString(context, format, length, text)
  undefined4 *context;
  undefined4 format;
  undefined4 length;
  undefined4 text;
{
  undefined4 paramWord;
  undefined4 savedWord50;
  byte programFlagByte;
  undefined4 savedWord54;
  undefined4 *paramCursor;
  int newProgram;
  int compareResult;
  undefined4 textCopy;
  undefined4 extraout_r4;
  undefined4 savedWord70;
  uint savedByte6c;
  undefined4 savedWord68;
  undefined4 savedWord64;
  undefined1 *savedWord58;
  undefined4 savedWord60;
  undefined4 savedWord5c;
  undefined1 *compiledInfo;
  int stateHolder;
  undefined1 *currentProgram;
  undefined4 oldWord70;
  int compiledProgram;
  undefined4 oldWord74;
  
  currentProgram = (undefined1 *)context[0x487];
  if ((*(int *)(currentProgram + 0x74) != 0) && (newProgram = (*(code *)context[3])(0x78), newProgram != 0)) {
    ((int (*)())arbfpProgramObjectInit)(context,newProgram);
    compiledProgram = *(int *)(newProgram + 0x74);
    if (compiledProgram == 0) {
      ((int (*)())arbfpProgramObjectFree)(context,newProgram);
      (*(code *)context[6])(newProgram);
      *context = 0x505;
    }
    else {
      stateHolder = context[1099];
      compareResult = _strncmp(text,"!!ILfs1.0\n",10);
      if (compareResult == 0) {
        *(undefined1 *)(compiledProgram + 0x55) = 1;
        *(undefined4 *)(*(int *)(newProgram + 0x74) + 0x58) = text;
        *(undefined4 *)(*(int *)(newProgram + 0x74) + 0x5c) = length;
        *(undefined1 *)(*(int *)(newProgram + 0x74) + 0x54) = 1;
      }
      else {
        *(undefined1 *)(compiledProgram + 0x55) = 0;
        ((int (*)())arbValidateProgram)(context,*(undefined4 *)(newProgram + 0x74),length,text);
        if (*(char *)(*(int *)(newProgram + 0x74) + 0x54) == '\0') {
          ((int (*)())arbfpProgramObjectFree)(context,newProgram);
          (*(code *)context[6])(newProgram);
          *context = 0x502;
          return;
        }
      }
      context[0x487] = newProgram;
      *(int *)(context[0x49c] * 0x18 + *(int *)(stateHolder + 8) + 0x14) = newProgram;
      compiledProgram = *(int *)(currentProgram + 0x74);
      *(undefined1 *)(newProgram + 2) = *(undefined1 *)(compiledProgram + 2);
      *(undefined1 *)(newProgram + 1) = *(undefined1 *)(compiledProgram + 1);
      compiledProgram = (*(code *)context[0x49f])(context,1);
      if (compiledProgram == 0) {
        *context = 0x502;
      }
      compiledProgram = context[0x49c] * 0x18 + *(int *)(context[1099] + 8);
      *(undefined4 *)(compiledProgram + 8) = format;
      *(undefined4 *)(compiledProgram + 0xc) = length;
      if (*(int *)(compiledProgram + 0x10) != 0) {
        (*(code *)context[6])(*(int *)(compiledProgram + 0x10));
      }
      textCopy = (*(code *)context[3])(length);
      *(undefined4 *)(compiledProgram + 0x10) = textCopy;
      (*(code *)context[0x4d1])(textCopy,text,length);
      *(undefined4 *)(*(int *)(newProgram + 0x74) + 0x58) = *(undefined4 *)(compiledProgram + 0x10);
      context[0x487] = currentProgram;
      *(undefined1 **)(context[0x49c] * 0x18 + *(int *)(stateHolder + 8) + 0x14) = currentProgram;
      savedWord70 = *(undefined4 *)(newProgram + 0x70);
      savedWord54 = *(undefined4 *)(newProgram + 0x54);
      oldWord70 = *(undefined4 *)(currentProgram + 0x70);
      oldWord74 = *(undefined4 *)(currentProgram + 0x74);
      savedWord50 = *(undefined4 *)(newProgram + 0x50);
      savedWord58 = *(undefined1 **)(newProgram + 0x58);
      savedWord5c = *(undefined4 *)(newProgram + 0x5c);
      savedWord60 = *(undefined4 *)(newProgram + 0x60);
      savedWord64 = *(undefined4 *)(newProgram + 100);
      savedWord68 = *(undefined4 *)(newProgram + 0x68);
      programFlagByte = *(byte *)(newProgram + 0x6c);
      savedByte6c = (uint)programFlagByte;
      *(undefined4 *)(currentProgram + 0x74) = *(undefined4 *)(newProgram + 0x74);
      *(undefined4 *)(currentProgram + 0x70) = savedWord70;
      *(undefined4 *)(currentProgram + 0x54) = savedWord54;
      *(undefined4 *)(currentProgram + 0x50) = savedWord50;
      *(undefined1 **)(currentProgram + 0x58) = savedWord58;
      *(undefined4 *)(currentProgram + 0x5c) = savedWord5c;
      *(undefined4 *)(currentProgram + 0x60) = savedWord60;
      *(undefined4 *)(currentProgram + 100) = savedWord64;
      *(undefined4 *)(currentProgram + 0x68) = savedWord68;
      currentProgram[0x6c] = programFlagByte;
      *(undefined4 *)(newProgram + 0x70) = oldWord70;
      *(undefined4 *)(newProgram + 0x74) = oldWord74;
      ((int (*)())arbfpProgramObjectFree)(context,newProgram);
      (*(code *)context[6])(newProgram);
      compiledInfo = *(undefined1 **)(currentProgram + 0x74);
      currentProgram[4] = compiledInfo[4];
      *currentProgram = *compiledInfo;
      currentProgram[1] = compiledInfo[1];
      currentProgram[2] = compiledInfo[2];
      currentProgram[3] = compiledInfo[3];
      *(undefined4 *)(currentProgram + 8) = *(undefined4 *)(compiledInfo + 0xc);
      *(undefined4 *)(currentProgram + 0xc) = *(undefined4 *)(compiledInfo + 0x10);
      if (*(char *)((int)context + 0x13b1) != '\0') {
        paramCursor = (undefined4 *)(compiledInfo + 0x14);
        newProgram = 0;
        savedWord58 = currentProgram;
        do {
          paramWord = *paramCursor;
          newProgram = newProgram + 1;
          paramCursor = paramCursor + 1;
          *(undefined4 *)(savedWord58 + 0x10) = paramWord;
          savedWord58 = savedWord58 + 4;
        } while (newProgram < (int)(uint)*(byte *)((int)context + 0x13b1));
      }
      ((int (*)())arbfpUpdateStateForProgram)(context,extraout_r4,savedWord70,savedByte6c,savedWord68,savedWord64,savedWord58,savedWord60);
      *(undefined1 *)(context + 0x474) = 1;
    }
  }
  return;
}

/* arbfpProgramStringIL @ 0x8e2e0 (168 bytes) */
int arbfpProgramStringIL(context, unused, wordCount, words)
  undefined4 context;
  undefined4 unused;
  int wordCount;
  undefined4 words;
{
  int byteCount;
  undefined4 headerWord1;
  undefined4 headerWord2;
  char headerLastByte;
  char *allocation;
  
  byteCount = wordCount * 4;
  allocation = (char *)_malloc(byteCount + 0xd);
  headerLastByte = s___ILfs1_0_001a5d2c[0xc];
  headerWord2 = (*(unsigned int *)((unsigned char *)&(s___ILfs1_0_001a5d2c) + 8));
  headerWord1 = (*(unsigned int *)((unsigned char *)&(s___ILfs1_0_001a5d2c) + 4));
  *(undefined4 *)allocation = (*(unsigned int *)((unsigned char *)&(s___ILfs1_0_001a5d2c) + 0));
  *(undefined4 *)(allocation + 4) = headerWord1;
  allocation[0xc] = headerLastByte;
  *(undefined4 *)(allocation + 8) = headerWord2;
  _memcpy(allocation + 10,words,byteCount);
  allocation[byteCount + 0xc] = '\0';
  ((int (*)())arbfpProgramString)(context,0x8875,byteCount + 0xc,allocation);
  return _free(allocation);
}

/* arbfpFetchParameterValue @ 0x8ebb0 (4284 bytes) */
int arbfpFetchParameterValue(context, element, outValue, unused)
  int context;
  int element;
  float *outValue;
  undefined4 unused;
{
  float *workRowP;
  float reducedElem4;
  float reciprocalPivot;
  float reducedElem3;
  float pivotRow0Elem1;
  float pivotRow0Elem2;
  float workRowAElem2;
  float pivotRow0Elem3;
  float workRowAElem3;
  float workRowPElem3;
  float workRowPElem2;
  float workRowAElem7;
  float workRowAElem6;
  float workRowAElem5;
  float workRowAElem4;
  float workRowPElem1;
  float pivotRow0Elem0;
  float workRowAElem0;
  float factorB;
  float factorA;
  float pivotRowElem7Value;
  float pivotRowElem6Value;
  float pivotRowElem5Value;
  float pivotRowElem4Value;
  float pivotRowElem3;
  float pivotRowElem2;
  float pivotRowElem1;
  float *workRowB;
  float *workRowA;
  float halfVectorZ;
  float lightDirY;
  float lightDirX;
  float materialSpecularB;
  float materialSpecularG;
  float materialSpecularR;
  float materialDiffuseB;
  float materialDiffuseG;
  float materialDiffuseR;
  float materialAmbientB;
  float materialAmbientG;
  float materialAmbientR;
  float materialShininess;
  float oneF;
  float stateFloat28cc;
  float workRowAElem1;
  float eliminationFactor;
  int copyByteOffset;
  float reducedElem6;
  float reducedElem5;
  float *outCursor;
  float *pivotRowElem5;
  int lightOrFace;
  float *pivotRowElem4;
  float *pivotRow1Elem1;
  float *pivotRow;
  int stateOwner;
  float *workRowD;
  float *swapRow;
  int stateBlock;
  float *workRowC;
  int kind;
  float *pivotRowElem6;
  float *pivotRowElem7;
  double length;
  double depthNear;
  float matrixCopy [4];
  float matrixCopy4;
  float matrixCopy5;
  float matrixCopy6;
  float matrixCopy7;
  float matrixCopy8;
  float matrixCopy9;
  float matrixCopy10;
  float matrixCopy11;
  float matrixCopy12;
  float matrixCopy13;
  float matrixCopy14;
  float matrixCopy15;
  float augRows [14];
  float augRow1Elem7;
  float augRow2Elem0;
  undefined4 augRow2Elem1;
  undefined4 augRow2Elem2;
  undefined4 augRow2Elem3;
  float augRow2Elem4;
  float augRow2Elem5;
  undefined4 augRow2Elem6;
  float augRow2Elem7;
  float augRow3Elem0;
  undefined4 augRow3Elem1;
  undefined4 augRow3Elem2;
  undefined4 augRow3Elem3;
  float augRow3Elem4;
  float augRow3Elem5;
  float augRow3Elem6;
  undefined4 augRow3Elem7;
  
  oneF = FLOAT_001aa0e8;
  kind = *(int *)(element + 8);
  stateOwner = *(int *)(context + 4);
  lightOrFace = *(int *)(element + 0xc);
  stateBlock = *(int *)(stateOwner + 0x10);
  switch(kind) {
  case 5:
    if (lightOrFace == 0) {
      *outValue = *(float *)(stateBlock + 0x28c0);
      outValue[1] = *(float *)(stateBlock + 0x28c4);
      outValue[2] = *(float *)(stateBlock + 0x28c8);
      outValue[3] = *(float *)(stateBlock + 0x28cc);
    }
    else {
      *outValue = *(float *)(stateBlock + 0x2b00);
      outValue[1] = *(float *)(stateBlock + 0x2b04);
      outValue[2] = *(float *)(stateBlock + 0x2b08);
      outValue[3] = *(float *)(stateBlock + 0x2b0c);
    }
    break;
  case 6:
    if (lightOrFace == 0) {
      *outValue = *(float *)(stateBlock + 0x28d0);
      outValue[1] = *(float *)(stateBlock + 0x28d4);
      outValue[2] = *(float *)(stateBlock + 0x28d8);
      outValue[3] = *(float *)(stateBlock + 0x28dc);
    }
    else {
      *outValue = *(float *)(stateBlock + 0x2b10);
      outValue[1] = *(float *)(stateBlock + 0x2b14);
      outValue[2] = *(float *)(stateBlock + 0x2b18);
      outValue[3] = *(float *)(stateBlock + 0x2b1c);
    }
    break;
  case 7:
    if (lightOrFace == 0) {
      *outValue = *(float *)(stateBlock + 0x28e0);
      outValue[1] = *(float *)(stateBlock + 0x28e4);
      outValue[2] = *(float *)(stateBlock + 0x28e8);
      outValue[3] = *(float *)(stateBlock + 0x28ec);
    }
    else {
      *outValue = *(float *)(stateBlock + 0x2b20);
      outValue[1] = *(float *)(stateBlock + 0x2b24);
      outValue[2] = *(float *)(stateBlock + 0x2b28);
      outValue[3] = *(float *)(stateBlock + 0x2b2c);
    }
    break;
  case 8:
    if (lightOrFace == 0) {
      *outValue = *(float *)(stateBlock + 0x28f0);
      outValue[1] = *(float *)(stateBlock + 0x28f4);
      outValue[2] = *(float *)(stateBlock + 0x28f8);
      outValue[3] = *(float *)(stateBlock + 0x28fc);
    }
    else {
      *outValue = *(float *)(stateBlock + 0x2b30);
      outValue[1] = *(float *)(stateBlock + 0x2b34);
      outValue[2] = *(float *)(((unsigned char *)0x00002b38) + stateBlock);
      outValue[3] = *(float *)(((unsigned char *)0x00002b3c) + stateBlock);
    }
    break;
  case 9:
    if (lightOrFace == 0) {
      materialShininess = *(float *)(stateBlock + 0x2900);
    }
    else {
      materialShininess = *(float *)(((unsigned char *)0x00002b40) + stateBlock);
    }
    *outValue = materialShininess;
    outValue[3] = 1.0;
    outValue[1] = 0.0;
    outValue[2] = 0.0;
    break;
  case 10:
    *outValue = *(float *)(lightOrFace * 0x80 + stateBlock + 0x24c0);
    outValue[1] = *(float *)(*(int *)(element + 0xc) * 0x80 + stateBlock + 0x24c4);
    outValue[2] = *(float *)(*(int *)(element + 0xc) * 0x80 + stateBlock + 0x24c8);
    outValue[3] = *(float *)(*(int *)(element + 0xc) * 0x80 + stateBlock + 0x24cc);
    break;
  case 0xb:
    *outValue = *(float *)(lightOrFace * 0x80 + stateBlock + 0x24d0);
    outValue[1] = *(float *)(*(int *)(element + 0xc) * 0x80 + stateBlock + 0x24d4);
    outValue[2] = *(float *)(*(int *)(element + 0xc) * 0x80 + stateBlock + 0x24d8);
    outValue[3] = *(float *)(*(int *)(element + 0xc) * 0x80 + stateBlock + 0x24dc);
    break;
  case 0xc:
    *outValue = *(float *)(lightOrFace * 0x80 + stateBlock + 0x24e0);
    outValue[1] = *(float *)(*(int *)(element + 0xc) * 0x80 + stateBlock + 0x24e4);
    outValue[2] = *(float *)(*(int *)(element + 0xc) * 0x80 + stateBlock + 0x24e8);
    outValue[3] = *(float *)(*(int *)(element + 0xc) * 0x80 + stateBlock + 0x24ec);
    break;
  case 0xd:
    *outValue = *(float *)(lightOrFace * 0x80 + stateBlock + 0x24f0);
    outValue[1] = *(float *)(*(int *)(element + 0xc) * 0x80 + stateBlock + 0x24f4);
    outValue[2] = *(float *)(*(int *)(element + 0xc) * 0x80 + stateBlock + 0x24f8);
    outValue[3] = *(float *)(*(int *)(element + 0xc) * 0x80 + stateBlock + 0x24fc);
    break;
  case 0xe:
    *outValue = *(float *)(lightOrFace * 0x80 + stateBlock + 0x2510);
    outValue[1] = *(float *)(*(int *)(element + 0xc) * 0x80 + stateBlock + 0x2514);
    outValue[2] = *(float *)(*(int *)(element + 0xc) * 0x80 + stateBlock + 0x2518);
    outValue[3] = *(float *)(*(int *)(element + 0xc) * 0x80 + stateBlock + 0x251c);
    break;
  case 0xf:
    *outValue = *(float *)(lightOrFace * 0x80 + stateBlock + 0x2500);
    outValue[1] = *(float *)(*(int *)(element + 0xc) * 0x80 + stateBlock + 0x2504);
    outValue[2] = *(float *)(*(int *)(element + 0xc) * 0x80 + stateBlock + 0x2508);
    outValue[3] = *(float *)(*(int *)(element + 0xc) * 0x80 + stateBlock + 0x250c);
    break;
  case 0x10:
    lightDirX = *(float *)(lightOrFace * 0x80 + stateBlock + 0x24f0);
    *outValue = lightDirX;
    lightDirY = *(float *)(*(int *)(element + 0xc) * 0x80 + stateBlock + 0x24f4);
    outValue[1] = lightDirY;
    halfVectorZ = *(float *)(*(int *)(element + 0xc) * 0x80 + stateBlock + 0x24f8) + oneF;
    outValue[2] = halfVectorZ;
    length = _sqrt((double)(halfVectorZ * halfVectorZ + lightDirX * lightDirX + lightDirY * lightDirY));
    outValue[3] = oneF;
    oneF = oneF / (float)length;
    outValue[2] = halfVectorZ * oneF;
    *outValue = oneF * lightDirX;
    outValue[1] = lightDirY * oneF;
    break;
  case 0x11:
    *outValue = *(float *)(stateBlock + 0x24b0);
    outValue[1] = *(float *)(stateBlock + 0x24b4);
    outValue[2] = *(float *)(stateBlock + 0x24b8);
    outValue[3] = *(float *)(stateBlock + 0x24bc);
    break;
  case 0x12:
    if (lightOrFace == 0) {
      *outValue = *(float *)(stateBlock + 0x24b0) * *(float *)(stateBlock + 0x28c0) +
                 *(float *)(stateBlock + 0x28f0);
      outValue[1] = *(float *)(stateBlock + 0x24b4) * *(float *)(stateBlock + 0x28c4) +
                   *(float *)(stateBlock + 0x28f4);
      outValue[2] = *(float *)(stateBlock + 0x24b8) * *(float *)(stateBlock + 0x28c8) +
                   *(float *)(stateBlock + 0x28f8);
      outValue[3] = *(float *)(stateBlock + 0x28dc);
    }
    else {
      *outValue = *(float *)(stateBlock + 0x24b0) * *(float *)(stateBlock + 0x2b00) +
                 *(float *)(stateBlock + 0x2b30);
      outValue[1] = *(float *)(stateBlock + 0x24b4) * *(float *)(stateBlock + 0x2b04) +
                   *(float *)(stateBlock + 0x2b34);
      outValue[2] = *(float *)(stateBlock + 0x24b8) * *(float *)(stateBlock + 0x2b08) +
                   *(float *)(((unsigned char *)0x00002b38) + stateBlock);
      outValue[3] = *(float *)(stateBlock + 0x2b1c);
    }
    break;
  case 0x13:
    if (*(int *)(element + 0x10) == 0) {
      materialAmbientR = *(float *)(stateBlock + 0x28c0);
    }
    else {
      materialAmbientR = *(float *)(stateBlock + 0x2b00);
    }
    *outValue = materialAmbientR * *(float *)(lightOrFace * 0x80 + stateBlock + 0x24c0);
    if (*(int *)(element + 0x10) == 0) {
      materialAmbientG = *(float *)(stateBlock + 0x28c4);
    }
    else {
      materialAmbientG = *(float *)(stateBlock + 0x2b04);
    }
    outValue[1] = materialAmbientG * *(float *)(*(int *)(element + 0xc) * 0x80 + stateBlock + 0x24c4);
    if (*(int *)(element + 0x10) == 0) {
      materialAmbientB = *(float *)(stateBlock + 0x28c8);
    }
    else {
      materialAmbientB = *(float *)(stateBlock + 0x2b08);
    }
    outValue[2] = materialAmbientB * *(float *)(*(int *)(element + 0xc) * 0x80 + stateBlock + 0x24c8);
    if (*(int *)(element + 0x10) == 0) {
      stateFloat28cc = *(float *)(stateBlock + 0x28cc);
    }
    else {
      stateFloat28cc = *(float *)(stateBlock + 0x2b0c);
    }
    goto LAB_0008f398;
  case 0x14:
    if (*(int *)(element + 0x10) == 0) {
      materialDiffuseR = *(float *)(stateBlock + 0x28d0);
    }
    else {
      materialDiffuseR = *(float *)(stateBlock + 0x2b10);
    }
    *outValue = materialDiffuseR * *(float *)(lightOrFace * 0x80 + stateBlock + 0x24d0);
    if (*(int *)(element + 0x10) == 0) {
      materialDiffuseG = *(float *)(stateBlock + 0x28d4);
    }
    else {
      materialDiffuseG = *(float *)(stateBlock + 0x2b14);
    }
    outValue[1] = materialDiffuseG * *(float *)(*(int *)(element + 0xc) * 0x80 + stateBlock + 0x24d4);
    if (*(int *)(element + 0x10) == 0) {
      materialDiffuseB = *(float *)(stateBlock + 0x28d8);
    }
    else {
      materialDiffuseB = *(float *)(stateBlock + 0x2b18);
    }
    outValue[2] = materialDiffuseB * *(float *)(*(int *)(element + 0xc) * 0x80 + stateBlock + 0x24d8);
    if (*(int *)(element + 0x10) == 0) {
      stateFloat28cc = *(float *)(stateBlock + 0x28dc);
    }
    else {
      stateFloat28cc = *(float *)(stateBlock + 0x2b1c);
    }
    goto LAB_0008f398;
  case 0x15:
    if (*(int *)(element + 0x10) == 0) {
      materialSpecularR = *(float *)(stateBlock + 0x28e0);
    }
    else {
      materialSpecularR = *(float *)(stateBlock + 0x2b20);
    }
    *outValue = materialSpecularR * *(float *)(lightOrFace * 0x80 + stateBlock + 0x24e0);
    if (*(int *)(element + 0x10) == 0) {
      materialSpecularG = *(float *)(stateBlock + 0x28e4);
    }
    else {
      materialSpecularG = *(float *)(stateBlock + 0x2b24);
    }
    outValue[1] = materialSpecularG * *(float *)(*(int *)(element + 0xc) * 0x80 + stateBlock + 0x24e4);
    if (*(int *)(element + 0x10) == 0) {
      materialSpecularB = *(float *)(stateBlock + 0x28e8);
    }
    else {
      materialSpecularB = *(float *)(stateBlock + 0x2b28);
    }
    outValue[2] = materialSpecularB * *(float *)(*(int *)(element + 0xc) * 0x80 + stateBlock + 0x24e8);
    if (*(int *)(element + 0x10) == 0) {
      stateFloat28cc = *(float *)(stateBlock + 0x28ec);
    }
    else {
      stateFloat28cc = *(float *)(stateBlock + 0x2b2c);
    }
    goto LAB_0008f398;
  case 0x16:
    *outValue = *(float *)(((unsigned char *)0x00002de0) + stateBlock);
    outValue[1] = *(float *)(((unsigned char *)0x00002de4) + stateBlock);
    outValue[2] = *(float *)(((unsigned char *)0x00002de8) + stateBlock);
    outValue[3] = *(float *)(((unsigned char *)0x00002dec) + stateBlock);
    break;
  case 0x17:
    *outValue = *(float *)(((unsigned char *)0x00002df0) + stateBlock);
    outValue[1] = *(float *)(((unsigned char *)0x00002df4) + stateBlock);
    outValue[2] = *(float *)(((unsigned char *)0x00002df8) + stateBlock);
    outValue[3] = *(float *)(((unsigned char *)0x00002dfc) + stateBlock);
    break;
  case 0x18:
    *outValue = (float)*(double *)(0x00001830 + stateBlock);
    outValue[1] = (float)*(double *)(stateBlock + 0x1838);
    depthNear = *(double *)(0x00001830 + stateBlock);
    length = *(double *)(stateBlock + 0x1838);
    outValue[3] = 1.0;
    outValue[2] = (float)(length - depthNear);
    break;
  case 0x19:
    *outValue = *(float *)(((unsigned char *)0x000031c4) + lightOrFace * 0x7c + stateBlock);
    outValue[1] = *(float *)(((unsigned char *)0x000031c8) + *(int *)(element + 0xc) * 0x7c + *(int *)(stateOwner + 0x10)
                           );
    outValue[2] = *(float *)(((unsigned char *)0x000031cc) + *(int *)(element + 0xc) * 0x7c + *(int *)(stateOwner + 0x10)
                           );
    stateFloat28cc = *(float *)(((unsigned char *)0x000031d0) + *(int *)(element + 0xc) * 0x7c + *(int *)(stateOwner + 0x10));
LAB_0008f398:
    outValue[3] = stateFloat28cc;
    break;
  case 0x1a:
  case 0x1b:
  case 0x1c:
  case 0x1d:
    kind = kind + -0x1a;
    stateBlock = stateBlock + lightOrFace * 0x40 + 0x1960;
    goto LAB_0008f444;
  case 0x1e:
  case 0x1f:
  case 0x20:
  case 0x21:
    stateBlock = stateBlock + 0x1920;
    kind = kind + -0x1e;
    goto LAB_0008f444;
  case 0x22:
  case 0x23:
  case 0x24:
  case 0x25:
    stateBlock = stateBlock + 0x1860;
    kind = kind + -0x22;
    goto LAB_0008f444;
  case 0x26:
  case 0x27:
  case 0x28:
  case 0x29:
    kind = kind + -0x26;
    stateBlock = stateBlock + lightOrFace * 0x40 + 0x1c60;
    goto LAB_0008f444;
  case 0x2e:
  case 0x2f:
  case 0x30:
  case 0x31:
    kind = kind + -0x2e;
    stateBlock = stateBlock + lightOrFace * 0x40 + 0x1a60;
LAB_0008f444:
    lightOrFace = 0;
    stateOwner = 0x10;
    outCursor = matrixCopy;
    do {
      copyByteOffset = lightOrFace * 4;
      lightOrFace = lightOrFace + 1;
      *outCursor = *(float *)(stateBlock + copyByteOffset);
      outCursor = outCursor + 1;
      stateOwner = stateOwner + -1;
    } while (stateOwner != 0);
    lightOrFace = *(int *)(element + 0x10);
    if ((lightOrFace == 1) || (lightOrFace == 3)) {
      augRows[4] = 1.0;
      augRows[0xd] = 1.0;
      augRows[1] = matrixCopy4;
      augRows[2] = matrixCopy8;
      augRow2Elem0 = matrixCopy[2];
      augRows[0] = matrixCopy[0];
      augRows[7] = FLOAT_001aa0d4;
      augRows[6] = FLOAT_001aa0d4;
      augRows[5] = FLOAT_001aa0d4;
      augRows[8] = matrixCopy[1];
      augRow1Elem7 = FLOAT_001aa0d4;
      augRows[3] = matrixCopy12;
      augRows[9] = matrixCopy5;
      augRows[0xc] = FLOAT_001aa0d4;
      augRows[10] = matrixCopy9;
      augRows[0xb] = matrixCopy13;
      augRow2Elem1 = matrixCopy6;
      augRow2Elem2 = matrixCopy10;
      augRow2Elem3 = matrixCopy14;
      augRow2Elem6 = 0x3f800000;
      augRow2Elem7 = FLOAT_001aa0d4;
      augRow3Elem7 = 0x3f800000;
      augRow2Elem5 = FLOAT_001aa0d4;
      augRow2Elem4 = FLOAT_001aa0d4;
      augRow3Elem6 = FLOAT_001aa0d4;
      augRow3Elem5 = FLOAT_001aa0d4;
      augRow3Elem4 = FLOAT_001aa0d4;
      augRow3Elem1 = matrixCopy7;
      augRow3Elem2 = matrixCopy11;
      augRow3Elem0 = matrixCopy[3];
      augRow3Elem3 = matrixCopy15;
      workRowA = &STACKARG(0xffffffb8);
      workRowC = &STACKARG(0xffffff98);
      if (ABS(matrixCopy[3]) <= ABS(matrixCopy[2])) {
        workRowA = &STACKARG(0xffffff98);
        workRowC = &STACKARG(0xffffffb8);
      }
      workRowB = augRows + 8;
      workRowAElem0 = *workRowA;
      if (ABS(*workRowA) <= ABS(matrixCopy[1])) {
        workRowB = workRowA;
        workRowA = augRows + 8;
        workRowAElem0 = matrixCopy[1];
      }
      pivotRow = augRows;
      if (ABS(matrixCopy[0]) < ABS(workRowAElem0)) {
        pivotRow = workRowA;
        workRowA = augRows;
      }
      pivotRow0Elem0 = *pivotRow;
      if (pivotRow0Elem0 != FLOAT_001aa0d4) {
        pivotRowElem1 = pivotRow[1];
        pivotRowElem4 = pivotRow + 4;
        factorA = *workRowA / pivotRow0Elem0;
        factorB = *workRowB / pivotRow0Elem0;
        pivotRow0Elem0 = *workRowC / pivotRow0Elem0;
        workRowA[1] = -(factorA * pivotRowElem1 - workRowA[1]);
        workRowB[1] = -(factorB * pivotRowElem1 - workRowB[1]);
        workRowC[1] = -(pivotRow0Elem0 * pivotRowElem1 - workRowC[1]);
        pivotRowElem2 = pivotRow[2];
        workRowA[2] = -(factorA * pivotRowElem2 - workRowA[2]);
        workRowB[2] = -(factorB * pivotRowElem2 - workRowB[2]);
        workRowC[2] = -(pivotRow0Elem0 * pivotRowElem2 - workRowC[2]);
        pivotRowElem3 = pivotRow[3];
        workRowA[3] = -(factorA * pivotRowElem3 - workRowA[3]);
        workRowB[3] = -(factorB * pivotRowElem3 - workRowB[3]);
        workRowC[3] = -(pivotRow0Elem0 * pivotRowElem3 - workRowC[3]);
        pivotRowElem4Value = pivotRow[4];
        if (pivotRowElem4Value != FLOAT_001aa0d4) {
          workRowA[4] = -(factorA * pivotRowElem4Value - workRowA[4]);
          workRowB[4] = -(factorB * pivotRowElem4Value - workRowB[4]);
          workRowC[4] = -(pivotRow0Elem0 * pivotRowElem4Value - workRowC[4]);
        }
        pivotRowElem5Value = pivotRow[5];
        pivotRowElem5 = pivotRow + 5;
        if (pivotRowElem5Value != FLOAT_001aa0d4) {
          workRowA[5] = -(factorA * pivotRowElem5Value - workRowA[5]);
          workRowB[5] = -(factorB * pivotRowElem5Value - workRowB[5]);
          workRowC[5] = -(pivotRow0Elem0 * pivotRowElem5Value - workRowC[5]);
        }
        pivotRowElem6Value = pivotRow[6];
        pivotRowElem6 = pivotRow + 6;
        if (pivotRowElem6Value != FLOAT_001aa0d4) {
          workRowA[6] = -(factorA * pivotRowElem6Value - workRowA[6]);
          workRowB[6] = -(factorB * pivotRowElem6Value - workRowB[6]);
          workRowC[6] = -(pivotRow0Elem0 * pivotRowElem6Value - workRowC[6]);
        }
        pivotRowElem7Value = pivotRow[7];
        pivotRowElem7 = pivotRow + 7;
        if (pivotRowElem7Value != FLOAT_001aa0d4) {
          workRowA[7] = -(factorA * pivotRowElem7Value - workRowA[7]);
          workRowB[7] = -(factorB * pivotRowElem7Value - workRowB[7]);
          workRowC[7] = -(pivotRow0Elem0 * pivotRowElem7Value - workRowC[7]);
        }
        swapRow = workRowB;
        if (ABS(workRowB[1]) < ABS(workRowC[1])) {
          swapRow = workRowC;
          workRowC = workRowB;
        }
        workRowPElem1 = swapRow[1];
        workRowAElem1 = workRowA[1];
        pivotRow1Elem1 = workRowA + 1;
        workRowD = swapRow;
        if (ABS(workRowAElem1) < ABS(workRowPElem1)) {
          pivotRow1Elem1 = swapRow + 1;
          workRowD = workRowA;
          workRowA = swapRow;
          workRowAElem1 = workRowPElem1;
        }
        if (workRowAElem1 != FLOAT_001aa0d4) {
          eliminationFactor = workRowD[1] / workRowAElem1;
          workRowAElem1 = workRowC[1] / workRowAElem1;
          workRowD[2] = -(eliminationFactor * workRowA[2] - workRowD[2]);
          workRowC[2] = -(workRowAElem1 * workRowA[2] - workRowC[2]);
          workRowD[3] = -(eliminationFactor * workRowA[3] - workRowD[3]);
          workRowC[3] = -(workRowAElem1 * workRowA[3] - workRowC[3]);
          workRowAElem4 = workRowA[4];
          if (workRowAElem4 != FLOAT_001aa0d4) {
            workRowD[4] = -(eliminationFactor * workRowAElem4 - workRowD[4]);
            workRowC[4] = -(workRowAElem1 * workRowAElem4 - workRowC[4]);
          }
          workRowAElem5 = workRowA[5];
          if (workRowAElem5 != FLOAT_001aa0d4) {
            workRowD[5] = -(eliminationFactor * workRowAElem5 - workRowD[5]);
            workRowC[5] = -(workRowAElem1 * workRowAElem5 - workRowC[5]);
          }
          workRowAElem6 = workRowA[6];
          if (workRowAElem6 != FLOAT_001aa0d4) {
            workRowD[6] = -(eliminationFactor * workRowAElem6 - workRowD[6]);
            workRowC[6] = -(workRowAElem1 * workRowAElem6 - workRowC[6]);
          }
          workRowAElem7 = workRowA[7];
          if (workRowAElem7 != FLOAT_001aa0d4) {
            workRowD[7] = -(eliminationFactor * workRowAElem7 - workRowD[7]);
            workRowC[7] = -(workRowAElem1 * workRowAElem7 - workRowC[7]);
          }
          workRowP = workRowD;
          if (ABS(workRowD[2]) < ABS(workRowC[2])) {
            workRowP = workRowC;
            workRowC = workRowD;
          }
          workRowPElem2 = workRowP[2];
          if (workRowPElem2 != FLOAT_001aa0d4) {
            workRowPElem2 = workRowC[2] / workRowPElem2;
            reducedElem3 = -(workRowPElem2 * workRowP[3] - workRowC[3]);
            workRowC[3] = reducedElem3;
            reducedElem4 = -(workRowPElem2 * workRowP[4] - workRowC[4]);
            workRowC[4] = reducedElem4;
            reducedElem5 = -(workRowPElem2 * workRowP[5] - workRowC[5]);
            workRowC[5] = reducedElem5;
            reducedElem6 = -(workRowPElem2 * workRowP[6] - workRowC[6]);
            workRowC[6] = reducedElem6;
            workRowPElem2 = -(workRowPElem2 * workRowP[7] - workRowC[7]);
            workRowC[7] = workRowPElem2;
            if (reducedElem3 != FLOAT_001aa0d4) {
              reducedElem3 = FLOAT_001aa0e8 / reducedElem3;
              reducedElem4 = reducedElem3 * reducedElem4;
              workRowC[4] = reducedElem4;
              workRowC[7] = reducedElem3 * workRowPElem2;
              workRowC[5] = reducedElem3 * reducedElem5;
              workRowC[6] = reducedElem3 * reducedElem6;
              workRowPElem3 = workRowP[3];
              reciprocalPivot = FLOAT_001aa0e8 / workRowP[2];
              workRowP[4] = reciprocalPivot * -(workRowPElem3 * reducedElem4 - workRowP[4]);
              workRowP[5] = reciprocalPivot * -(workRowPElem3 * workRowC[5] - workRowP[5]);
              workRowP[6] = reciprocalPivot * -(workRowPElem3 * workRowC[6] - workRowP[6]);
              workRowP[7] = reciprocalPivot * -(workRowPElem3 * workRowC[7] - workRowP[7]);
              workRowAElem3 = workRowA[3];
              workRowA[4] = -(workRowAElem3 * workRowC[4] - workRowA[4]);
              workRowA[5] = -(workRowAElem3 * workRowC[5] - workRowA[5]);
              workRowA[6] = -(workRowAElem3 * workRowC[6] - workRowA[6]);
              workRowA[7] = -(workRowAElem3 * workRowC[7] - workRowA[7]);
              pivotRow0Elem3 = pivotRow[3];
              *pivotRowElem4 = -(pivotRow0Elem3 * workRowC[4] - *pivotRowElem4);
              *pivotRowElem5 = -(pivotRow0Elem3 * workRowC[5] - *pivotRowElem5);
              *pivotRowElem6 = -(pivotRow0Elem3 * workRowC[6] - *pivotRowElem6);
              *pivotRowElem7 = -(pivotRow0Elem3 * workRowC[7] - *pivotRowElem7);
              workRowAElem2 = workRowA[2];
              reciprocalPivot = FLOAT_001aa0e8 / *pivotRow1Elem1;
              workRowA[4] = reciprocalPivot * -(workRowAElem2 * workRowP[4] - workRowA[4]);
              workRowA[5] = reciprocalPivot * -(workRowAElem2 * workRowP[5] - workRowA[5]);
              workRowA[6] = reciprocalPivot * -(workRowAElem2 * workRowP[6] - workRowA[6]);
              workRowA[7] = reciprocalPivot * -(workRowAElem2 * workRowP[7] - workRowA[7]);
              pivotRow0Elem2 = pivotRow[2];
              *pivotRowElem4 = -(pivotRow0Elem2 * workRowP[4] - *pivotRowElem4);
              *pivotRowElem5 = -(pivotRow0Elem2 * workRowP[5] - *pivotRowElem5);
              *pivotRowElem6 = -(pivotRow0Elem2 * workRowP[6] - *pivotRowElem6);
              *pivotRowElem7 = -(pivotRow0Elem2 * workRowP[7] - *pivotRowElem7);
              pivotRow0Elem1 = pivotRow[1];
              reciprocalPivot = FLOAT_001aa0e8 / *pivotRow;
              *pivotRowElem4 = reciprocalPivot * -(pivotRow0Elem1 * workRowA[4] - *pivotRowElem4);
              *pivotRowElem5 = reciprocalPivot * -(pivotRow0Elem1 * workRowA[5] - *pivotRowElem5);
              *pivotRowElem6 = reciprocalPivot * -(pivotRow0Elem1 * workRowA[6] - *pivotRowElem6);
              matrixCopy12 = reciprocalPivot * -(pivotRow0Elem1 * workRowA[7] - *pivotRowElem7);
              *pivotRowElem7 = matrixCopy12;
              matrixCopy[0] = *pivotRowElem4;
              matrixCopy4 = *pivotRowElem5;
              matrixCopy8 = *pivotRowElem6;
              matrixCopy[1] = workRowA[4];
              matrixCopy5 = workRowA[5];
              matrixCopy9 = workRowA[6];
              matrixCopy13 = workRowA[7];
              matrixCopy[2] = workRowP[4];
              matrixCopy6 = workRowP[5];
              matrixCopy10 = workRowP[6];
              lightOrFace = *(int *)(element + 0x10);
              matrixCopy14 = workRowP[7];
              matrixCopy[3] = workRowC[4];
              matrixCopy7 = workRowC[5];
              matrixCopy11 = workRowC[6];
              matrixCopy15 = workRowC[7];
              goto LAB_0008eb2c;
            }
          }
        }
        lightOrFace = *(int *)(element + 0x10);
      }
    }
LAB_0008eb2c:
    if (-1 < lightOrFace) {
      if (lightOrFace < 2) {
        lightOrFace = 0;
        stateBlock = 4;
        outCursor = matrixCopy + kind;
        do {
          workRowAElem0 = *outCursor;
          outCursor = outCursor + 4;
          *(float *)(lightOrFace + (int)outValue) = workRowAElem0;
          lightOrFace = lightOrFace + 4;
          stateBlock = stateBlock + -1;
        } while (stateBlock != 0);
      }
      else if (lightOrFace < 4) {
        lightOrFace = 0;
        outCursor = matrixCopy + kind * 4;
        stateBlock = 4;
        do {
          workRowAElem0 = *outCursor;
          outCursor = outCursor + 1;
          *(float *)(lightOrFace + (int)outValue) = workRowAElem0;
          lightOrFace = lightOrFace + 4;
          stateBlock = stateBlock + -1;
        } while (stateBlock != 0);
      }
    }
    return;
  case 0x32:
    *(undefined8 *)outValue = *(undefined8 *)(((unsigned char *)0x00001010) + lightOrFace * 0x10 + stateBlock);
    *(undefined8 *)(outValue + 2) = *(undefined8 *)(((unsigned char *)0x00001010) + lightOrFace * 0x10 + stateBlock + 8);
    break;
  case 0x33:
    stateBlock = *(int *)(**(int **)(*(int *)(stateOwner + 0x18) + 400) + 0x18);
    *(undefined8 *)outValue = *(undefined8 *)(lightOrFace * 0x10 + stateBlock);
    *(undefined8 *)(outValue + 2) = *(undefined8 *)(lightOrFace * 0x10 + stateBlock + 8);
  }
  return;
}

/* arbfpInitProgramState @ 0x8f520 (456 bytes) */
int arbfpInitProgramState(context)
  int context;
{
  int loopIndex;
  undefined4 programObject;
  undefined4 in_r4;
  undefined4 a1;
  undefined4 a1_00;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int slotIndex;
  int slotTable;
  int stateHolder;
  undefined *unitSlotPtr;
  
  unitSlotPtr = ((unsigned char *)0x000011d0U) + context;
  stateHolder = *(int *)(((unsigned char *)0x0000112c) + context);
  *(undefined4 *)(((unsigned char *)0x0000126c) + context) = 1;
  *(undefined4 *)(((unsigned char *)0x00001220) + context) = 2;
  (**(code **)(((unsigned char *)0x00001274) + context))
            (context,in_r4,in_r5,in_r6,in_r7,in_r8,*(code **)(((unsigned char *)0x00001274) + context));
  ((unsigned char *)0x000011d3)[context] = 0;
  *(undefined4 *)(((unsigned char *)0x00001228) + context) = 0;
  if (((unsigned char *)0x000013b1)[context] != '\0') {
    loopIndex = 0;
    do {
      *(undefined4 *)(unitSlotPtr + 0x5c) = 0;
      loopIndex = loopIndex + 1;
      unitSlotPtr = unitSlotPtr + 4;
    } while (loopIndex < (int)(uint)(byte)((unsigned char *)0x000013b1)[context]);
  }
  arbProgramEntryInit(context,*(int *)(((unsigned char *)0x0000126c) + context) * 0x18 + *(int *)(stateHolder + 8));
  *(undefined4 *)(*(int *)(((unsigned char *)0x0000126c) + context) * 0x18 + *(int *)(stateHolder + 8) + 4) = 0x8804;
  *(undefined4 *)(*(int *)(((unsigned char *)0x0000126c) + context) * 0x18 + *(int *)(stateHolder + 8)) = 0;
  slotIndex = *(int *)(((unsigned char *)0x0000126c) + context);
  slotTable = *(int *)(stateHolder + 8);
  programObject = (**(code **)(context + 0xc))(0x78,a1,in_r5,in_r6,in_r7,in_r8,slotTable);
  *(undefined4 *)(slotIndex * 0x18 + slotTable + 0x14) = programObject;
  ((int (*)())arbfpProgramObjectInit)(context,*(undefined4 *)
                        (*(int *)(((unsigned char *)0x0000126c) + context) * 0x18 + *(int *)(stateHolder + 8) + 0x14));
  arbProgramEntryInit(context,*(int *)(((unsigned char *)0x00001220) + context) * 0x18 + *(int *)(stateHolder + 8));
  *(undefined4 *)(*(int *)(((unsigned char *)0x00001220) + context) * 0x18 + *(int *)(stateHolder + 8) + 4) = 0x8804;
  *(undefined4 *)(*(int *)(((unsigned char *)0x00001220) + context) * 0x18 + *(int *)(stateHolder + 8)) = 0;
  slotIndex = *(int *)(((unsigned char *)0x00001220) + context);
  slotTable = *(int *)(stateHolder + 8);
  programObject = (**(code **)(context + 0xc))(0x78,a1_00,in_r5,in_r6,in_r7,in_r8,slotTable);
  *(undefined4 *)(slotIndex * 0x18 + slotTable + 0x14) = programObject;
  return ((int (*)())arbfpProgramObjectInit)(context,*(undefined4 *)
                        (*(int *)(((unsigned char *)0x00001220) + context) * 0x18 + *(int *)(stateHolder + 8) + 0x14));
}

/* arbfpGrowInstanceTable @ 0x8f6f0 (108 bytes) */
int arbfpGrowInstanceTable(context, programObject)
  int context;
  int programObject;
{
  undefined4 newTable;
  undefined4 oldTable;
  int stateHolder;
  
  stateHolder = *(int *)(((unsigned char *)0x0000112c) + context);
  oldTable = *(undefined4 *)(programObject + 0x70);
  newTable = (**(code **)(context + 0x10))(*(undefined4 *)(stateHolder + 0x10),4);
  *(undefined4 *)(programObject + 0x70) = newTable;
  _memcpy(newTable,oldTable,*(int *)(stateHolder + 0x10) * 4 + -4);
                    
                    
  (**(code **)(context + 0x18))(oldTable);
  return;
}

/* arbfpLoadDefaultProgram @ 0x8f760 (144 bytes) */
int arbfpLoadDefaultProgram(context)
  int context;
{
  undefined4 defaultLength;
  char *defaultText;
  undefined4 in_r7;
  undefined4 in_r8;
  int stateHolder;
  undefined4 in_r10;
  
  defaultLength = 0xf;
  ((unsigned char *)0x000011d0)[context] = 1;
  defaultText = "!!ARBfp1.0\nEND\n";
  *(int *)(((unsigned char *)0x00001270) + context) = *(int *)(((unsigned char *)0x0000126c) + context);
  *(undefined4 *)(((unsigned char *)0x0000121c) + context) =
       *(undefined4 *)
        (*(int *)(((unsigned char *)0x0000126c) + context) * 0x18 + *(int *)(*(int *)(((unsigned char *)0x0000112c) + context) + 8)
        + 0x14);
  stateHolder = *(int *)(((unsigned char *)0x0000112c) + context);
  ((int (*)())arbValidateProgram)(context,*(undefined4 *)
                        (*(int *)(*(int *)(((unsigned char *)0x00001220) + context) * 0x18 + *(int *)(stateHolder + 8) +
                                 0x14) + 0x74),0xf,"!!ARBfp1.0\nEND\n");
  return ((int (*)())arbfpBindProgram)(context,*(undefined4 *)(((unsigned char *)0x0000126c) + context),defaultLength,defaultText,in_r7,in_r8,stateHolder,
               in_r10);
}

/* gldDrawInternalRect @ 0x8f7f0 (884 bytes) */
int gldDrawInternalRect(ctx, param_2, param_3, rect, param_5)
  int ctx;
  undefined4 param_2;
  undefined4 param_3;
  uint *rect;
  uint param_5;
{
  int scaledWidth;
  undefined4 stateWord2da0;
  undefined4 stateWord2dac;
  undefined4 packetBase;
  float rectX1;
  float rectY0;
  float rectY1;
  float rectX0;
  float drawableHeight;
  char rasterInitFlag;
  undefined4 stateWord2da4;
  undefined4 stateWord2da8;
  bool recordCommands;
  code *commitFn;
  undefined4 reg1b84Value;
  int a1;
  undefined4 *packet;
  undefined4 packetWords;
  undefined4 extraout_r4;
  undefined4 uVar14;
  uint *a3;
  undefined4 a3_00;
  undefined1 *a4;
  undefined *puVar15;
  undefined4 *a1_00;
  int recordBase;
  uint a6;
  int stateBlock;
  undefined1 savedDrawState [144];
  undefined4 i2dHi2;
  uint i2dLo2;
  undefined4 i2dHi3;
  uint i2dLo3;
  undefined4 i2dHi4;
  uint i2dLo4;
  undefined4 i2dHi1;
  uint i2dLo1;
  undefined4 i2dHi5;
  undefined4 drawableHeightInt;
  longlong scaledHeightLL;
  longlong scaledWidthLL;
  
  stateBlock = *(int *)(*(int *)(ctx + 4) + 0x10);
  a3 = rect;
  a1 = (**(code **)(ctx + 0x2758))(ctx,10000,param_3,rect,param_5);
  commitFn = *(code **)(ctx + 0x275c);
  *(int *)(0x00002748 + ctx + 4) = a1;
  (*commitFn)(ctx,a1,param_3,a3,param_5);
  recordBase = *(int *)(ctx + 4);
  if (((((*(uint *)(recordBase + 0x154) & 0x700000) == 0) || (*rect != 0)) || (rect[1] != 0)) ||
     ((rect[2] != *(uint *)(recordBase + 0x15c) || (rect[3] != *(uint *)(recordBase + 0x160))))) {
    recordCommands = false;
    recordBase = 0;
  }
  else {
    recordCommands = true;
    FUN_000a5c40(ctx);
    recordBase = *(int *)(0x00002748 + ctx + 4);
  }
  uVar14 = 0;
  a3_00 = 0;
  a4 = savedDrawState;
  gldEnterInternalDrawState(ctx,1,0,0,a4);
  packetWords = 0x25;
  if (*(char *)(ctx + 0x2802) != '\0') {
    packetWords = 0x23;
  }
  packet = (undefined4 *)(**(code **)(ctx + 0x2758))(ctx,packetWords,uVar14,a3_00,a4);
  rasterInitFlag = *(char *)(ctx + 0x2802);
  *(undefined4 **)(0x00002748 + ctx + 4) = packet;
  if (rasterInitFlag == '\0') {
    packet[1] = 0x10000000;
    *packet = 0x5c8;
    *(undefined1 *)(ctx + 0x2802) = 1;
  }
  packetBase = (**(code **)(ctx + 0x2758))(ctx,0x23,uVar14,a3_00,a4);
  *(undefined4 *)(0x00002748 + ctx + 4) = packetBase;
  packet = (undefined4 *)gldEmitInternalDrawSetupPackets(ctx,packetBase);
  if (recordCommands) {
    *(int *)(a1 + 8) = (int)packet - a1 >> 2;
  }
  puVar15 = ((unsigned char *)0x00001087U);
  a1_00 = packet + 0x10;
  i2dHi2 = 0x43300000;
  i2dHi3 = 0x43300000;
  i2dHi4 = 0x43300000;
  i2dHi1 = 0x43300000;
  i2dLo1 = rect[2] ^ 0x80000000;
  i2dLo2 = rect[1] ^ 0x80000000;
  i2dLo3 = *rect ^ 0x80000000;
  i2dLo4 = rect[3] ^ 0x80000000;
  drawableHeightInt = *(undefined4 *)(ctx + 8);
  stateWord2dac = *(undefined4 *)(((unsigned char *)0x00002dac) + stateBlock);
  stateWord2da0 = *(undefined4 *)(((unsigned char *)0x00002da0) + stateBlock);
  stateWord2da4 = *(undefined4 *)(((unsigned char *)0x00002da4) + stateBlock);
  stateWord2da8 = *(undefined4 *)(((unsigned char *)0x00002da8) + stateBlock);
  i2dHi5 = 0x43300000;
  rectX1 = (float)((double)CONCAT44(0x43300000,i2dLo1) - 4503601774854144.0);
  rectY0 = (float)((double)CONCAT44(0x43300000,i2dLo2) - 4503601774854144.0);
  rectY1 = (float)((double)CONCAT44(0x43300000,i2dLo4) - 4503601774854144.0);
  rectX0 = (float)((double)CONCAT44(0x43300000,i2dLo3) - 4503601774854144.0);
  drawableHeight = (float)((double)CONCAT44(0x43300000,drawableHeightInt) - 4503599627370496.0);
  a6 = (uint)(int)(*(float *)(ctx + 0x2818) * 0.5 * drawableHeight * (rectY1 - rectY0));
  scaledHeightLL = (longlong)(int)a6;
  scaledWidth = (int)(drawableHeight * *(float *)(ctx + 0x2814) * 0.5 * (rectX1 - rectX0));
  scaledWidthLL = (longlong)scaledWidth;
  packet[2] = 0x82c;
  *packet = ((unsigned char *)0x00001087U);
  packet[1] = scaledWidth << 0x10 | a6 & 0xffff;
  reg1b84Value = *(undefined4 *)(ctx + 0x1b84);
  packet[5] = 0x10031;
  packet[4] = 0xc0083500;
  packet[6] = (rectX0 + rectX1) * 0.5;
  packet[7] = (rectY0 + rectY1) * 0.5;
  packet[9] = 0x3f800000;
  packet[10] = stateWord2da0;
  packet[0xb] = stateWord2da4;
  packet[3] = reg1b84Value;
  packet[0xc] = stateWord2da8;
  packet[0xd] = stateWord2dac;
  packet[0xe] = ((unsigned char *)0x00001087U);
  packet[8] = 0;
  packet[0xf] = *(undefined4 *)(ctx + 0x1ccc);
  *(undefined4 **)(0x00002748 + ctx + 4) = a1_00;
  (**(code **)(ctx + 0x275c))(ctx,a1_00,packet,a3_00,((unsigned char *)0x00001087U),a1_00,a6,0xc0083500);
  gldValidateVertexProgramState(ctx,extraout_r4,packet,a3_00,puVar15,a1_00,a6);
  gldLeaveInternalDrawState(ctx,savedDrawState);
  if (recordCommands) {
    *(int *)(a1 + 4) = *(int *)(0x00002748 + ctx + 4) - recordBase >> 2;
  }
  return;
}

/* gldFlushProgramStateForDraw @ 0x8fb70 (248 bytes) */
int gldFlushProgramStateForDraw(ctx)
  int ctx;
{
  int stateRecord;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int reg1b7cBefore;
  
  if (*(int *)(((unsigned char *)0x00003e28) + *(int *)(*(int *)(ctx + 4) + 0x10)) != 0) {
    gldUploadClipPlanes(ctx);
  }
  reg1b7cBefore = *(int *)(ctx + 0x1b7c);
  *(undefined1 *)(ctx + 0x23ec) = 1;
  if (*(char *)(ctx + 0x1868) == '\0') {
    if ((*(uint *)(ctx + 0x44) & 0x100000) != 0) {
      extvsFlushConstantUploads(ctx);
    }
  }
  else if ((*(uint *)(ctx + 0x44) & 0x100000) != 0) {
    stateRecord = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + **(int **)(((unsigned char *)0x00001168) + ctx));
    (**(code **)((int)((unsigned char *)0x00001294) + ctx))
              (ctx,stateRecord + 0x13c,*(undefined4 *)(stateRecord + 0x130),in_r6,in_r7,in_r8,
               *(int *)(((unsigned char *)0x0000118c) + ctx) * 4);
  }
  ffvpRunStateHook(ctx);
  *(char *)(ctx + 0x23ec) = '\x01' - (reg1b7cBefore == *(int *)(ctx + 0x1b7c));
  return;
}

/* ffvpAssignOutputSlots @ 0x8fc70 (1028 bytes) */
int ffvpAssignOutputSlots(ctx)
  int ctx;
{
  uint loopIndex;
  byte texEnableMask;
  uint texUnitCount;
  uint ctxFlags44;
  int stateBlock;
  uint nextSlot;
  undefined4 colorSlot;
  int slotBase;
  int unitCursor;
  int enableCursor;
  
  stateBlock = *(int *)(*(int *)(ctx + 4) + 0x10);
  _memset(ctx + 0x19c,0xffffffff,0x68);
  FUN_0004fc80(ctx,0,3,0,0,0,0,0);
  *(undefined4 *)(ctx + 0x19c) = 0;
  if (*(int *)(ctx + 0x44) < 0) {
    FUN_0004fc80(ctx,1,3,0,1,0,0,0);
    *(undefined4 *)(ctx + 0x1a0) = 1;
    if (((unsigned char *)0x00002d48)[stateBlock + 3] == '\0') {
      ctxFlags44 = *(uint *)(ctx + 0x44);
      nextSlot = 2;
    }
    else {
      nextSlot = 3;
      FUN_0004fc80(ctx,2,3,0,2,0,0,0);
      ctxFlags44 = *(uint *)(ctx + 0x44);
      *(undefined4 *)(ctx + 0x1a8) = 2;
    }
  }
  else {
    nextSlot = *(uint *)(ctx + 0x8c);
    if (((nextSlot >> 0x14 & 1) == 0 && (nextSlot >> 0x1a & 1) == 0) && (nextSlot >> 0x1b & 1) == 0) {
      slotBase = 1;
      colorSlot = 1;
      nextSlot = 2;
    }
    else {
      slotBase = 2;
      nextSlot = 3;
      FUN_0004fc80(ctx,1,3,0,1,0,0,0);
      colorSlot = 2;
      *(undefined4 *)(ctx + 0x1a0) = 1;
    }
    FUN_0004fc80(ctx,colorSlot,3,0,colorSlot,0,0,0);
    ctxFlags44 = *(uint *)(ctx + 0x44);
    *(undefined4 *)(ctx + 0x1a8) = colorSlot;
    if ((ctxFlags44 & 0xa10000) != 0) {
      FUN_0004fc80(ctx,nextSlot,3,0,nextSlot,0,0,0);
      ctxFlags44 = *(uint *)(ctx + 0x44);
      *(uint *)(ctx + 0x1ac) = nextSlot;
      nextSlot = slotBase + 2;
    }
  }
  if ((ctxFlags44 & 0x20000) == 0) {
    texUnitCount = (uint)*(byte *)(ctx + 0x2b);
    if ((uint)(byte)((unsigned char *)0x000013b0)[ctx] < (uint)*(byte *)(ctx + 0x2b)) {
      texUnitCount = (uint)(byte)((unsigned char *)0x000013b0)[ctx];
    }
    if (texUnitCount == 0) goto LAB_0008ff78;
    loopIndex = 0;
    unitCursor = ctx;
    enableCursor = ctx;
    do {
      if ((((unsigned char *)0x00001438)[enableCursor] != '\0') && (*(int *)(((unsigned char *)0x000013f8) + unitCursor) != 0)) {
        FUN_0004fc80(ctx,nextSlot,3,0,nextSlot,0,0,0);
        *(uint *)(unitCursor + 0x1c8) = nextSlot;
        nextSlot = nextSlot + 1;
      }
      loopIndex = loopIndex + 1;
      enableCursor = enableCursor + 1;
      unitCursor = unitCursor + 4;
    } while (loopIndex != texUnitCount);
  }
  else {
    if ((ctxFlags44 & 0x2000) == 0) {
      texEnableMask = ((unsigned char *)0x00001135)[ctx];
    }
    else {
      texEnableMask = ((unsigned char *)0x000011d3)[ctx];
    }
    texUnitCount = (uint)(byte)((unsigned char *)0x000013b0)[ctx];
    if (texUnitCount == 0) goto LAB_0008ff78;
    loopIndex = 0;
    unitCursor = ctx;
    do {
      if (((uint)texEnableMask & 1 << (loopIndex & 0x3f)) != 0) {
        FUN_0004fc80(ctx,nextSlot,3,0,nextSlot,0,0,0);
        texUnitCount = (uint)(byte)((unsigned char *)0x000013b0)[ctx];
        *(uint *)(unitCursor + 0x1c8) = nextSlot;
        nextSlot = nextSlot + 1;
      }
      loopIndex = loopIndex + 1;
      unitCursor = unitCursor + 4;
    } while ((int)loopIndex < (int)texUnitCount);
  }
  ctxFlags44 = *(uint *)(ctx + 0x44);
LAB_0008ff78:
  if (((ctxFlags44 & 0x1000800) != 0) && (*(short *)(((unsigned char *)0x00002e06) + stateBlock) == -0x7baf)) {
    FUN_0004fc80(ctx,nextSlot,3,0,nextSlot,0,0,0);
    *(uint *)(ctx + 0x1ec) = nextSlot;
    nextSlot = nextSlot + 1;
    *(undefined4 *)(ctx + 0x1f0) = 0;
  }
  if (((unsigned char *)0x00004301)[stateBlock] != '\0') {
    FUN_0004fc80(ctx,nextSlot,3,0,nextSlot,0,0,0);
    *(uint *)(ctx + 0x1f8) = nextSlot;
    nextSlot = nextSlot + 1;
  }
  ctxFlags44 = nextSlot - 1;
  if ((ctxFlags44 & 1) == 0) {
    stateBlock = (ctxFlags44 * 2 & 0xfffffffc) + ctx;
    *(uint *)(stateBlock + 0x1be4) = *(uint *)(stateBlock + 0x1be4) | 0x2000;
  }
  else {
    stateBlock = (ctxFlags44 * 2 & 0xfffffffc) + ctx;
    *(uint *)(stateBlock + 0x1be4) = *(uint *)(stateBlock + 0x1be4) | 0x20000000;
  }
  *(char *)(ctx + 0x131) = (char)nextSlot;
  *(uint *)(ctx + 0x2430) = nextSlot;
  *(uint *)(ctx + 0x2438) = nextSlot;
  *(undefined1 *)(ctx + 0x2435) = 1;
  *(uint *)(ctx + 0x243c) = nextSlot;
  *(uint *)(ctx + 0x1ca4) = (nextSlot & 0x1f) << 2 | *(uint *)(ctx + 0x1ca4) & 0xffffff80;
  return;
}

/* ffvpComputeOutputMasks @ 0x900a0 (944 bytes) */
int ffvpComputeOutputMasks(glContext)
  int glContext;
{
  uint texUnitCount;
  uint texLiveMask;
  uint texOutShift;
  uint newMask1b9c;
  uint outMask1ca0;
  int texPtrCursor;
  uint ctxFlags8c;
  int loopCounter;
  uint texBitShift;
  uint stateFlagsB;
  int stateBlock;
  uint loopCounterB;
  int texFlagCursor;
  uint stateFlags;
  uint oldMask1b9c;
  int oldMask1ca0;
  int oldMask1ba0;
  
  oldMask1b9c = *(uint *)(glContext + 0x1b9c);
  oldMask1ba0 = *(int *)(glContext + 0x1ba0);
  oldMask1ca0 = *(int *)(glContext + 0x1ca0);
  stateBlock = *(int *)(*(int *)(glContext + 4) + 0x10);
  if ((*(char *)(glContext + 0x1868) != '\0') && (*(char *)(glContext + 0x124) != '\0')) {
    FUN_0004dbe0(glContext);
    return;
  }
  stateFlags = *(uint *)(glContext + 0x44);
  *(undefined4 *)(glContext + 0x1ca0) = 1;
  if ((int)stateFlags < 0) {
    *(undefined4 *)(glContext + 0x1ca0) = 3;
    if (((unsigned char *)0x00002d48)[stateBlock + 3] != '\0') {
      *(undefined4 *)(glContext + 0x1ca0) = 7;
    }
  }
  else {
    ctxFlags8c = *(uint *)(glContext + 0x8c);
    if (((ctxFlags8c >> 0x14 & 1) != 0 || (ctxFlags8c >> 0x1a & 1) != 0) || (ctxFlags8c >> 0x1b & 1) != 0) {
      *(undefined4 *)(glContext + 0x1ca0) = 3;
    }
    outMask1ca0 = *(uint *)(glContext + 0x1ca0);
    *(uint *)(glContext + 0x1ca0) = outMask1ca0 | 4;
    if ((stateFlags & 0xa10000) != 0) {
      *(uint *)(glContext + 0x1ca0) = outMask1ca0 | 0xc;
    }
  }
  if (((stateFlags & 0x1000800) != 0) && (*(short *)(((unsigned char *)0x00002e06) + stateBlock) == -0x7baf)) {
    *(uint *)(glContext + 0x1ca0) = *(uint *)(glContext + 0x1ca0) | 0x40000;
  }
  if (((unsigned char *)0x00004301)[stateBlock] != '\0') {
    *(uint *)(glContext + 0x1ca0) = *(uint *)(glContext + 0x1ca0) | 0x80000;
  }
  newMask1b9c = 3;
  *(undefined4 *)(glContext + 0x1b9c) = 3;
  *(undefined4 *)(glContext + 0x1ba0) = 0;
  stateFlagsB = *(uint *)(glContext + 0x44);
  if ((int)stateFlagsB < 0) {
    if (*(short *)(((unsigned char *)0x00002d48) + stateBlock) == -0x7e06) {
      *(undefined4 *)(glContext + 0x1b9c) = 7;
    }
    if (((unsigned char *)0x00002d48)[stateBlock + 4] == '\0') {
      newMask1b9c = *(uint *)(glContext + 0x1b9c);
    }
    else {
      newMask1b9c = *(uint *)(glContext + 0x1b9c) | 0x1c;
      *(uint *)(glContext + 0x1b9c) = newMask1b9c;
    }
  }
  else if (((stateFlagsB >> 0x17 & 1) != 0 || (stateFlagsB >> 0x15 & 1) != 0) || (stateFlagsB >> 0x10 & 1) != 0) {
    newMask1b9c = 7;
    *(undefined4 *)(glContext + 0x1b9c) = 7;
  }
  if ((*(uint *)(glContext + 0xe8) & 1) != 0) {
    newMask1b9c = newMask1b9c | 0x10000;
    *(uint *)(glContext + 0x1b9c) = newMask1b9c;
  }
  if (((stateFlags & 0x1000000) != 0) && (*(char *)(glContext + 0x121) == '\0')) {
    newMask1b9c = newMask1b9c | 4;
    *(uint *)(glContext + 0x1b9c) = newMask1b9c;
  }
  if ((stateFlags & 0x20000) == 0) {
    texUnitCount = (uint)(byte)((unsigned char *)0x000013b0)[glContext];
    if ((uint)*(byte *)(glContext + 0x2b) <= (uint)(byte)((unsigned char *)0x000013b0)[glContext]) {
      texUnitCount = (uint)*(byte *)(glContext + 0x2b);
    }
    if (texUnitCount != 0) {
      loopCounter = 0;
      texOutShift = 0;
      texPtrCursor = glContext;
      texFlagCursor = glContext;
      do {
        if ((((unsigned char *)0x00001438)[texFlagCursor] != '\0') && (*(int *)(((unsigned char *)0x000013f8) + texPtrCursor) != 0)) {
          *(uint *)(glContext + 0x1ba0) = 4 << (texOutShift & 0x3f) | *(uint *)(glContext + 0x1ba0);
          *(uint *)(glContext + 0x1ca0) = 1 << (loopCounter + 10U & 0x3f) | *(uint *)(glContext + 0x1ca0);
        }
        loopCounter = loopCounter + 1;
        texOutShift = texOutShift + 3;
        texFlagCursor = texFlagCursor + 1;
        texPtrCursor = texPtrCursor + 4;
        texUnitCount = texUnitCount - 1;
      } while (texUnitCount != 0);
    }
  }
  else {
    if ((stateFlags & 0x2000) == 0) {
      texLiveMask = (uint)(byte)((unsigned char *)0x00001135)[glContext];
    }
    else {
      texLiveMask = (uint)(byte)((unsigned char *)0x000011d3)[glContext];
      if ((stateFlags & 0x800) != 0) {
        *(uint *)(glContext + 0x1ba0) =
             4 << ((uint)(byte)((unsigned char *)0x000011d1)[glContext] * 3 & 0x3f) | *(uint *)(glContext + 0x1ba0);
      }
      if ((stateFlags & 0x400) != 0) {
        *(uint *)(glContext + 0x1ba0) =
             4 << ((uint)(byte)((unsigned char *)0x000011d2)[glContext] * 3 & 0x3f) | *(uint *)(glContext + 0x1ba0);
      }
    }
    texUnitCount = (uint)(byte)((unsigned char *)0x000013b0)[glContext];
    if (texUnitCount != 0) {
      loopCounterB = 0;
      texBitShift = 0;
      if (texUnitCount == 0) {
        texUnitCount = 1;
      }
      do {
        if ((texLiveMask & 1 << (loopCounterB & 0x3f)) != 0) {
          *(uint *)(glContext + 0x1ba0) = 4 << (texBitShift & 0x3f) | *(uint *)(glContext + 0x1ba0);
          *(uint *)(glContext + 0x1ca0) = 1 << (loopCounterB + 10 & 0x3f) | *(uint *)(glContext + 0x1ca0);
        }
        loopCounterB = loopCounterB + 1;
        texBitShift = texBitShift + 3;
        texUnitCount = texUnitCount - 1;
      } while (texUnitCount != 0);
    }
  }
  if ((((oldMask1b9c != newMask1b9c) || (oldMask1ba0 != *(int *)(glContext + 0x1ba0))) ||
      (oldMask1ca0 != *(int *)(glContext + 0x1ca0))) || (*(char *)(glContext + 299) != '\0')) {
    *(uint *)(glContext + 0x1930) = *(uint *)(glContext + 0x1930) | 0x40000;
    ((int (*)())ffvpAssignOutputSlots)(glContext);
    (**(code **)(((unsigned char *)0x00001334) + glContext))(glContext,1);
    *(undefined1 *)(glContext + 299) = 0;
  }
  return;
}

/* gldValidateState @ 0x90470 (952 bytes) */
void gldValidateState(int glContext,undefined4 forwardedArg2,undefined4 forwardedArg3,undefined4 forwardedArg4,undefined4 forwardedArg5,undefined4 forwardedArg6,undefined4 forwardedArg7,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8,double fparam_9)
{
  uint dirtyMask;
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
  uint dirtyMask2;
  double forwarded_in_stack_ffffffb8;
  
  if (*(char *)(glContext + 0x1868) != '\0') {
    if ((*(uint *)(glContext + 0x44) & 0x100000) == 0) {
      *(code **)(((unsigned char *)0x000012b4) + glContext) = ffvpComputeOutputMasks;
    }
    else {
      *(undefined **)(((unsigned char *)0x000012b4) + glContext) = PTR_FUN_001e89ec;
    }
  }
  dirtyMask2 = *(uint *)(glContext + 0x1808) & 0x20000000;
  if (dirtyMask2 != 0) {
    forwardedFloatArg1 = (double)FUN_000a4980(glContext,forwardedArg2,forwardedArg3,forwardedArg4,forwardedArg5);
    forwardedArg2 = extraout_r4;
  }
  dirtyMask = *(uint *)(glContext + 0x38);
  if (dirtyMask != 0) {
    if ((dirtyMask & 4) != 0) {
      forwardedFloatArg1 = (double)((double (*)())gldValidatePolygonMode)(glContext,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,
                                      forwardedFloatArg7,forwardedFloatArg8);
      dirtyMask = *(uint *)(glContext + 0x38);
      forwardedArg2 = extraout_r4_00;
    }
    if ((dirtyMask & 2) != 0) {
      forwardedFloatArg1 = (double)FUN_0004eba0(glContext,forwardedArg2,forwardedArg3,forwardedArg4,forwardedArg5,forwardedArg6,dirtyMask2);
      dirtyMask = *(uint *)(glContext + 0x38);
      forwardedArg2 = extraout_r4_01;
    }
    if ((dirtyMask & 8) != 0) {
      forwardedFloatArg1 = (double)FUN_0004ed90(glContext);
      dirtyMask = *(uint *)(glContext + 0x38);
      forwardedArg2 = extraout_r4_02;
    }
    if ((dirtyMask & 0x400) != 0) {
      forwardedFloatArg1 = (double)((double (*)())FUN_000520c0)(glContext,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,
                                      forwardedFloatArg7,forwardedFloatArg8);
      dirtyMask = *(uint *)(glContext + 0x38);
      forwardedArg2 = extraout_r4_03;
    }
    if ((dirtyMask & 0x100) != 0) {
      ((void (*)())FUN_0004f2e0)(glContext,forwardedArg2,forwardedArg3,forwardedArg4,forwardedFloatArg1);
      forwardedFloatArg1 = (double)ffvpBuildFogKey(glContext,extraout_r4_04,forwardedArg3,forwardedArg4,forwardedArg5,forwardedArg6);
      dirtyMask = *(uint *)(glContext + 0x38);
      forwardedArg2 = extraout_r4_05;
    }
    if ((dirtyMask & 0x800) != 0) {
      forwardedFloatArg1 = (double)ffvpBuildBlendKey(glContext);
      dirtyMask = *(uint *)(glContext + 0x38);
      forwardedArg2 = extraout_r4_06;
    }
    if ((dirtyMask & 0x4000) != 0) {
      forwardedFloatArg1 = (double)gldValidateCullFace(glContext);
      dirtyMask = *(uint *)(glContext + 0x38);
      forwardedArg2 = extraout_r4_07;
    }
    if ((dirtyMask & 0x2200) != 0) {
      forwardedFloatArg1 = (double)((double (*)())FUN_0004def0)(glContext,forwardedArg2,forwardedArg3,forwardedArg4,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,
                                      forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8,forwarded_in_stack_ffffffb8
                                     );
      dirtyMask = *(uint *)(glContext + 0x38);
      forwardedArg2 = extraout_r4_08;
    }
    if ((*(uint *)(glContext + 0x8c) & 0x40000000) == 0) {
      if ((dirtyMask & 0x20000) != 0) {
        forwardedFloatArg1 = (double)gldSyncClipPlaneEnables(glContext);
        dirtyMask = *(uint *)(glContext + 0x38);
        forwardedArg2 = extraout_r4_09;
      }
      if ((dirtyMask & 0x20) != 0) {
        ((void (*)())FUN_000bd9a0)(glContext,forwardedArg2,forwardedArg3,forwardedArg4,forwardedFloatArg1);
        dirtyMask = *(uint *)(glContext + 0x38);
        forwardedArg2 = extraout_r4_10;
      }
      if ((dirtyMask & 0x1000) != 0) {
        if (*(char *)(glContext + 0x1868) == '\0') {
          extvsValidateProgramState(glContext,forwardedArg2);
          forwardedArg2 = extraout_r4_12;
        }
        else {
          (**(code **)((int)((unsigned char *)0x000011cc) + glContext))(glContext);
          forwardedArg2 = extraout_r4_11;
        }
      }
    }
    else if ((dirtyMask & 0x20) != 0) {
      ((void (*)())FUN_0004d620)(glContext,forwardedArg2,forwardedArg3,forwardedArg4,forwardedFloatArg1);
      forwardedArg2 = extraout_r4_13;
    }
  }
  dirtyMask2 = *(uint *)(glContext + 0x3c);
  if (dirtyMask2 != 0) {
    if ((dirtyMask2 & 1) != 0) {
      gldValidateDepthTest(glContext);
      dirtyMask2 = *(uint *)(glContext + 0x3c);
      forwardedArg2 = extraout_r4_14;
    }
    if ((dirtyMask2 & 2) != 0) {
      gldValidateScissor(glContext);
      dirtyMask2 = *(uint *)(glContext + 0x3c);
      forwardedArg2 = extraout_r4_15;
    }
    if ((dirtyMask2 & 8) != 0) {
      gldValidateBlend(glContext);
      dirtyMask2 = *(uint *)(glContext + 0x3c);
      forwardedArg2 = extraout_r4_16;
    }
    if ((dirtyMask2 & 0x10) != 0) {
      gldValidateAlphaTest(glContext);
      dirtyMask2 = *(uint *)(glContext + 0x3c);
      forwardedArg2 = extraout_r4_17;
    }
    if ((dirtyMask2 & 0x20) != 0) {
      gldValidateStencil(glContext);
      dirtyMask2 = *(uint *)(glContext + 0x3c);
      forwardedArg2 = extraout_r4_18;
    }
    if ((dirtyMask2 & 0x40) != 0) {
      FUN_00050140(glContext,forwardedArg2,forwardedArg3,forwardedArg4,forwardedArg5,forwardedArg6);
      dirtyMask2 = *(uint *)(glContext + 0x3c);
    }
    if ((dirtyMask2 & 0x400) != 0) {
      gldValidateTexEnvColor(glContext);
      dirtyMask2 = *(uint *)(glContext + 0x3c);
    }
    if ((dirtyMask2 & 0x1000) != 0) {
      FUN_000a5ec0(glContext);
    }
  }
  if ((*(uint *)(glContext + 0x44) & 0x100000) == 0) {
    if ((*(uint *)(glContext + 0x8c) & 0x40000000) == 0) {
      if ((((*(uint *)(glContext + 0x38) & 0x4b928) != 0) || (*(short *)(glContext + 0x34) != 0)) ||
         (*(char *)(glContext + 299) != '\0')) {
        ((int (*)())ffvpComputeOutputMasks)(glContext);
      }
    }
    else {
      FUN_0004dbe0(glContext);
    }
  }
  FUN_0004d100(glContext);
  FUN_00052280(glContext);
  *(undefined1 *)(glContext + 0x2e) = 0;
  *(undefined1 *)(glContext + 0x29) = 0;
  *(undefined2 *)(glContext + 0x32) = 0;
  *(undefined2 *)(glContext + 0x34) = 0;
  *(undefined1 *)(glContext + 0x2c) = 0;
  *(undefined1 *)(glContext + 0x2d) = 0;
  *(undefined4 *)(glContext + 0x1810) = 0;
  *(undefined4 *)(glContext + 0x38) = 0;
  *(undefined4 *)(glContext + 0x3c) = 0;
  *(undefined4 *)(glContext + 0x40) = 0;
  *(undefined4 *)(glContext + 0x180c) = 0;
  return;
}

/* gldEmitTclModeRegs @ 0x90840 (264 bytes) */
int gldEmitTclModeRegs(ctx)
  int ctx;
{
  uint reg1b84Masked;
  float oneF;
  code *streamSetCurrent;
  undefined4 *packet;
  bool xScaleNotOne;
  
  oneF = FLOAT_001aa0e8;
  if ((*(uint *)(ctx + 0x8c) & 0x40000000) == 0) {
    *(uint *)(ctx + 0x1b74) = *(uint *)(ctx + 0x1b74) & 0xfffeffff;
    *(uint *)(ctx + 0x1b84) = *(uint *)(ctx + 0x1b84) & 0xfffffcff | 0x43f;
  }
  else {
    xScaleNotOne = *(float *)(ctx + 0x2814) != FLOAT_001aa0e8;
    reg1b84Masked = *(uint *)(ctx + 0x1b84) & 0xfffffbc0;
    *(uint *)(ctx + 0x1b84) = reg1b84Masked | 0x300;
    if ((xScaleNotOne) || (*(float *)(ctx + 0x2818) != oneF)) {
      *(uint *)(ctx + 0x1b84) = reg1b84Masked | 0x305;
    }
    *(uint *)(ctx + 0x1b74) = *(uint *)(ctx + 0x1b74) | 0x10000;
  }
  packet = (undefined4 *)(**(code **)(ctx + 0x2758))(ctx,4);
  *(undefined4 **)(0x00002748 + ctx + 4) = packet;
  *packet = 0x82c;
  *(undefined4 *)(*(int *)(0x00002748 + ctx + 4) + 4) = *(undefined4 *)(ctx + 0x1b84);
  *(undefined4 *)(*(int *)(0x00002748 + ctx + 4) + 8) = 0x887;
  *(undefined4 *)(*(int *)(0x00002748 + ctx + 4) + 0xc) = *(undefined4 *)(ctx + 0x1b74);
  streamSetCurrent = *(code **)(ctx + 0x275c);
  *(int *)(0x00002748 + ctx + 4) = *(int *)(0x00002748 + ctx + 4) + 0x10;
                    
                    
  (*streamSetCurrent)(ctx,*(int *)(0x00002748 + ctx + 4));
  return;
}

/* gldClearHwTclFlag @ 0x90960 (48 bytes) */
int gldClearHwTclFlag(ctx)
  int ctx;
{
  int stateObject;
  
  stateObject = *(int *)(ctx + 4);
  if (*(char *)(stateObject + 0x20) == '\0') {
    return;
  }
  if ((*(uint *)(ctx + 0x8c) & 0x40000000) == 0) {
    return;
  }
  *(undefined1 *)(stateObject + 0x20) = 0;
  *(undefined4 *)(stateObject + 0x1cc) = 0;
  return ((int (*)())gldEmitTclModeRegs)(ctx);
}

/* gldUpdateHwTclState @ 0x90990 (772 bytes) */
int gldUpdateHwTclState(ctx, dirtyMasks)
  int ctx;
  undefined4 *dirtyMasks;
{
  int unitCursor2;
  int unitCursor;
  bool hwPathBlocked;
  uint unitCount;
  int stateObject;
  int stateBlock;
  
  stateObject = *(int *)(ctx + 4);
  stateBlock = *(int *)(stateObject + 0x10);
  if ((*(int *)(((unsigned char *)0x00003e28) + stateBlock) == 0) || (hwPathBlocked = true, ((unsigned char *)0x000013a8)[ctx] != '\0')) {
    hwPathBlocked = false;
  }
  if ((((((*(char *)(stateObject + 0x21) != '\0') && ((dirtyMasks[3] & 0x10000000) == 0)) &&
        ((*(int *)(*(int *)(stateObject + 0x18) + 0x198) == 0 || (*(int *)(stateObject + 0x1cc) != 0)))) &&
       ((((unsigned char *)0x00004304)[stateBlock] == '\0' || (*(int *)(stateObject + 0x1cc) != 0)))) &&
      ((((unsigned char *)0x00002d48)[stateBlock + 2] == '\0' || (((unsigned char *)0x00002d48)[stateBlock + 6] == '\0')))) && (!hwPathBlocked))
  {
    if (*(char *)(stateObject + 0x20) == '\0') {
      *(undefined1 *)(stateObject + 0x20) = 1;
      *(undefined1 *)(ctx + 299) = 1;
      *(undefined1 *)(ctx + 0x125) = 0;
      *(undefined1 *)(ctx + 0x126) = 0;
      *(undefined1 *)(ctx + 0x124) = 0;
      *(uint *)(ctx + 0x8c) = *(uint *)(ctx + 0x8c) & 0xbfffffff;
      dirtyMasks[4] = 0xffffffff;
      *dirtyMasks = 0xffffffff;
      dirtyMasks[2] = dirtyMasks[2] | 0xfffffffd;
      dirtyMasks[1] = dirtyMasks[1] | 0x3ffffff;
      dirtyMasks[3] = dirtyMasks[3] | 0x7ffffff;
      *(undefined1 *)(ctx + 0x2c) = 0xff;
      *(undefined4 *)(ctx + 0x38) = 0x7ffff;
      *(undefined1 *)(ctx + 0x2d) = 0xf;
      *(undefined1 *)(ctx + 0x29) = 1;
      *(undefined2 *)(ctx + 0x34) = 0xffff;
      *(undefined4 *)(ctx + 0x3c) = 0x800015ff;
      *(undefined1 *)(ctx + 0x2a) = 1;
      *(undefined4 *)(ctx + 0x40) = 0x7ffff;
      *(undefined2 *)(ctx + 0x32) = 0xffff;
      *(undefined1 *)(ctx + 0x2e) = 3;
      *(undefined1 *)(ctx + 0x30) = 7;
      *(undefined4 *)(ctx + 0x180c) = 5;
      *(undefined4 *)(ctx + 0x1810) = 0x1f;
      unitCount = (uint)(byte)((unsigned char *)0x000013b5)[ctx];
      if (unitCount != 0) {
        unitCursor = ctx;
        if (unitCount == 0) {
          unitCount = 1;
        }
        do {
          *(undefined1 *)(unitCursor + 0x1814) = 0x3f;
          *(undefined1 *)(unitCursor + 0x181c) = 3;
          unitCursor = unitCursor + 1;
          unitCount = unitCount - 1;
        } while (unitCount != 0);
      }
      *(undefined1 *)(ctx + 0x2803) = 1;
      *(undefined1 *)(ctx + 0x23ec) = 1;
      *(undefined1 *)(ctx + 0x29) = 1;
      *(undefined1 *)(ctx + 0x247d) = 1;
      *(uint *)(ctx + 0x2488) = *(uint *)(ctx + 0x2488) | 7;
      return;
    }
    return;
  }
  if (*(char *)(stateObject + 0x20) != '\0') {
    *(undefined1 *)(stateObject + 0x20) = 0;
    *(undefined1 *)(ctx + 299) = 1;
    *(undefined1 *)(ctx + 0x126) = 1;
    *(undefined1 *)(ctx + 0x124) = 1;
    *(undefined1 *)(ctx + 0x125) = 0;
    *(uint *)(ctx + 0x8c) = *(uint *)(ctx + 0x8c) | 0x40000000;
    dirtyMasks[4] = 0xffffffff;
    *dirtyMasks = 0xffffffff;
    dirtyMasks[2] = dirtyMasks[2] | 0xfffffffd;
    dirtyMasks[1] = dirtyMasks[1] | 0x3ffffff;
    dirtyMasks[3] = dirtyMasks[3] | 0x7ffffff;
    *(undefined1 *)(ctx + 0x2c) = 0xff;
    *(undefined4 *)(ctx + 0x38) = 0x7ffff;
    *(undefined1 *)(ctx + 0x2d) = 0xf;
    *(undefined1 *)(ctx + 0x29) = 1;
    *(undefined2 *)(ctx + 0x34) = 0xffff;
    *(undefined4 *)(ctx + 0x3c) = 0x800015ff;
    *(undefined1 *)(ctx + 0x2a) = 1;
    *(undefined4 *)(ctx + 0x40) = 0x7ffff;
    *(undefined2 *)(ctx + 0x32) = 0xffff;
    *(undefined1 *)(ctx + 0x2e) = 3;
    *(undefined1 *)(ctx + 0x30) = 7;
    *(undefined4 *)(ctx + 0x180c) = 5;
    *(undefined4 *)(ctx + 0x1810) = 0x1f;
    unitCount = (uint)(byte)((unsigned char *)0x000013b5)[ctx];
    if (unitCount != 0) {
      unitCursor2 = ctx;
      if (unitCount == 0) {
        unitCount = 1;
      }
      do {
        *(undefined1 *)(unitCursor2 + 0x1814) = 0x3f;
        *(undefined1 *)(unitCursor2 + 0x181c) = 3;
        unitCursor2 = unitCursor2 + 1;
        unitCount = unitCount - 1;
      } while (unitCount != 0);
    }
    *(undefined1 *)(ctx + 0x2803) = 1;
    *(undefined1 *)(ctx + 0x23ec) = 1;
    *(undefined1 *)(ctx + 0x29) = 1;
    *(undefined1 *)(ctx + 0x247d) = 1;
    *(uint *)(ctx + 0x2488) = *(uint *)(ctx + 0x2488) | 7;
  }
  *(undefined4 *)(stateObject + 0x1cc) = 0;
  return;
}

/* ffvpAllocTempRegister @ 0x90ca0 (1240 bytes) */
int ffvpAllocTempRegister(allocState, componentCount, resultOperand)
  int allocState;
  int componentCount;
  int *resultOperand;
{
  int resultWord6Staged;
  int resultWord7StagedB;
  int resultWord3Staged;
  int resultWord7Staged;
  int resultWord8StagedB;
  int resultWord4Staged;
  int resultWord8Staged;
  int resultWord9Staged;
  char *flagPtr;
  char flagByte;
  int resultWord5Staged;
  int regFlags;
  int flagCursor;
  int regCountdown;
  uint loopIndex;
  
  *resultOperand = componentCount;
  if (componentCount == 1) {
    regCountdown = *(int *)(allocState + 1000);
    if (regCountdown != 0) {
      loopIndex = 0;
      flagCursor = allocState;
      do {
        if (((*(char *)(flagCursor + 0x6c4) == '\0') && (*(char *)(flagCursor + 0x6c5) == '\0')) &&
           (*(char *)(flagCursor + 0x6c6) == '\0')) {
          resultOperand[1] = loopIndex;
          resultWord5Staged = DAT_001dbd90;
          resultWord4Staged = DAT_001dbd8c;
          resultWord3Staged = DAT_001dbd88;
          regFlags = loopIndex * 4 + allocState;
          resultOperand[2] = DAT_001dbd84;
          resultOperand[5] = resultWord5Staged;
          resultOperand[3] = resultWord3Staged;
          resultOperand[4] = resultWord4Staged;
          resultWord9Staged = DAT_001dbd80;
          resultWord8StagedB = DAT_001dbd7c;
          resultWord7StagedB = DAT_001dbd78;
          resultOperand[6] = DAT_001dbd74;
          resultOperand[9] = resultWord9Staged;
          resultOperand[7] = resultWord7StagedB;
          resultOperand[8] = resultWord8StagedB;
          *(undefined1 *)(regFlags + 0x6c6) = 1;
          *(undefined1 *)(regFlags + 0x6c4) = 1;
          *(undefined1 *)(regFlags + 0x6c5) = 1;
          if (loopIndex < *(uint *)(allocState + 0x3d0)) {
            return 0;
          }
          goto LAB_00090e50;
        }
        loopIndex = loopIndex + 1;
        flagCursor = flagCursor + 4;
        regCountdown = regCountdown + -1;
      } while (regCountdown != 0);
    }
  }
  else if (componentCount == 0) {
    regCountdown = *(int *)(allocState + 1000);
    if (regCountdown != 0) {
      loopIndex = 0;
      flagCursor = allocState;
      do {
        if (((*(char *)(flagCursor + 0x6c4) == '\0') && (*(char *)(flagCursor + 0x6c5) == '\0')) &&
           ((*(char *)(flagCursor + 0x6c6) == '\0' && (*(char *)(flagCursor + 0x6c7) == '\0')))) {
          resultOperand[1] = loopIndex;
          resultWord5Staged = DAT_001dbd30;
          resultWord4Staged = DAT_001dbd2c;
          resultWord3Staged = DAT_001dbd28;
          regFlags = loopIndex * 4 + allocState;
          resultOperand[2] = DAT_001dbd24;
          resultOperand[5] = resultWord5Staged;
          resultOperand[3] = resultWord3Staged;
          resultOperand[4] = resultWord4Staged;
          resultWord9Staged = DAT_001dbd20;
          resultWord8StagedB = DAT_001dbd1c;
          resultWord7StagedB = DAT_001dbd18;
          resultOperand[6] = DAT_001dbd14;
          resultOperand[9] = resultWord9Staged;
          resultOperand[7] = resultWord7StagedB;
          resultOperand[8] = resultWord8StagedB;
          *(undefined1 *)(regFlags + 0x6c7) = 1;
          *(undefined1 *)(regFlags + 0x6c4) = 1;
          *(undefined1 *)(regFlags + 0x6c5) = 1;
          *(undefined1 *)(regFlags + 0x6c6) = 1;
          if (loopIndex < *(uint *)(allocState + 0x3d0)) {
            return 0;
          }
LAB_00090e50:
          *(uint *)(allocState + 0x3d0) = loopIndex + 1;
          return 0;
        }
        loopIndex = loopIndex + 1;
        flagCursor = flagCursor + 4;
        regCountdown = regCountdown + -1;
      } while (regCountdown != 0);
    }
  }
  else {
    if (componentCount != 2) {
      return 4;
    }
    regCountdown = *(int *)(allocState + 1000);
    if (regCountdown != 0) {
      loopIndex = 0;
      if (*(char *)(allocState + 0x6c4) == '\0') {
LAB_00090e7c:
        resultOperand[1] = loopIndex;
        resultWord5Staged = DAT_001dbd10;
        resultWord4Staged = DAT_001dbd0c;
        resultWord3Staged = DAT_001dbd08;
        resultOperand[2] = DAT_001dbd04;
        resultOperand[5] = resultWord5Staged;
        resultOperand[3] = resultWord3Staged;
        resultOperand[4] = resultWord4Staged;
        resultWord8Staged = DAT_001fa600;
        resultWord7Staged = DAT_001fa5fc;
        resultWord6Staged = DAT_001fa5f8;
        resultOperand[9] = DAT_001fa604;
        resultOperand[7] = resultWord7Staged;
        resultOperand[6] = resultWord6Staged;
        resultOperand[8] = resultWord8Staged;
        *(undefined1 *)(loopIndex * 4 + allocState + 0x6c4) = 1;
        if (*(uint *)(allocState + 0x3d0) <= loopIndex) goto LAB_00091070;
      }
      else if (*(char *)(allocState + 0x6c5) == '\0') {
LAB_00090efc:
        resultOperand[1] = loopIndex;
        resultWord5Staged = DAT_001dbd70;
        resultWord4Staged = DAT_001dbd6c;
        resultWord3Staged = DAT_001dbd68;
        resultOperand[2] = DAT_001dbd64;
        resultOperand[5] = resultWord5Staged;
        resultOperand[3] = resultWord3Staged;
        resultOperand[4] = resultWord4Staged;
        resultWord8Staged = DAT_001dbcec;
        resultWord7Staged = DAT_001dbce8;
        resultWord6Staged = DAT_001dbce4;
        resultOperand[9] = DAT_001dbcf0;
        resultOperand[7] = resultWord7Staged;
        resultOperand[6] = resultWord6Staged;
        resultOperand[8] = resultWord8Staged;
        *(undefined1 *)(loopIndex * 4 + allocState + 0x6c5) = 1;
        if (*(uint *)(allocState + 0x3d0) <= loopIndex) goto LAB_00091070;
      }
      else if (*(char *)(allocState + 0x6c6) == '\0') {
LAB_00090f7c:
        resultOperand[1] = loopIndex;
        resultWord5Staged = DAT_001dbd60;
        resultWord4Staged = DAT_001dbd5c;
        resultWord3Staged = DAT_001dbd58;
        resultOperand[2] = DAT_001dbd54;
        resultOperand[5] = resultWord5Staged;
        resultOperand[3] = resultWord3Staged;
        resultOperand[4] = resultWord4Staged;
        resultWord8Staged = DAT_001dbcfc;
        resultWord7Staged = DAT_001dbcf8;
        resultWord6Staged = DAT_001dbcf4;
        resultOperand[9] = DAT_001dbd00;
        resultOperand[7] = resultWord7Staged;
        resultOperand[6] = resultWord6Staged;
        resultOperand[8] = resultWord8Staged;
        *(undefined1 *)(loopIndex * 4 + allocState + 0x6c6) = 1;
        if (*(uint *)(allocState + 0x3d0) <= loopIndex) {
LAB_00091070:
          *(uint *)(allocState + 0x3d0) = loopIndex + 1;
          return 0;
        }
      }
      else {
        flagByte = *(char *)(allocState + 0x6c7);
        flagCursor = allocState;
        while (flagByte != '\0') {
          loopIndex = loopIndex + 1;
          regCountdown = regCountdown + -1;
          if (regCountdown == 0) goto LAB_00091090;
          if (*(char *)(flagCursor + 0x6c8) == '\0') goto LAB_00090e7c;
          if (*(char *)(flagCursor + 0x6c9) == '\0') goto LAB_00090efc;
          if (*(char *)(flagCursor + 0x6ca) == '\0') goto LAB_00090f7c;
          flagPtr = (char *)(flagCursor + 0x6cb);
          flagCursor = flagCursor + 4;
          flagByte = *flagPtr;
        }
        resultOperand[1] = loopIndex;
        resultWord5Staged = DAT_001dbd50;
        resultWord4Staged = DAT_001dbd4c;
        resultWord3Staged = DAT_001dbd48;
        resultOperand[2] = DAT_001dbd44;
        resultOperand[5] = resultWord5Staged;
        resultOperand[3] = resultWord3Staged;
        resultOperand[4] = resultWord4Staged;
        resultWord8Staged = DAT_001dbcdc;
        resultWord7Staged = DAT_001dbcd8;
        resultWord6Staged = DAT_001dbcd4;
        resultOperand[9] = DAT_001dbce0;
        resultOperand[7] = resultWord7Staged;
        resultOperand[6] = resultWord6Staged;
        resultOperand[8] = resultWord8Staged;
        *(undefined1 *)(loopIndex * 4 + allocState + 0x6c7) = 1;
        if (*(uint *)(allocState + 0x3d0) <= loopIndex) goto LAB_00091070;
      }
      return 0;
    }
  }
LAB_00091090:
  resultOperand[1] = -1;
  resultWord5Staged = DAT_001fa614;
  resultWord4Staged = DAT_001fa610;
  resultWord3Staged = DAT_001fa60c;
  resultOperand[2] = DAT_001fa608;
  resultOperand[5] = resultWord5Staged;
  resultOperand[3] = resultWord3Staged;
  resultOperand[4] = resultWord4Staged;
  resultWord9Staged = DAT_001dbd40;
  resultWord8StagedB = DAT_001dbd3c;
  resultWord7StagedB = DAT_001dbd38;
  resultOperand[6] = DAT_001dbd34;
  resultOperand[9] = resultWord9Staged;
  resultOperand[7] = resultWord7StagedB;
  resultOperand[8] = resultWord8StagedB;
  return 7;
}

/* ffvpFreeTempRegister @ 0x911a0 (316 bytes) */
int ffvpFreeTempRegister(programBuilder, tempOperand)
  int programBuilder;
  int *tempOperand;
{
  int laneSel;
  int operandKind;
  
  operandKind = *tempOperand;
  if (operandKind == 1) {
    *(undefined1 *)(tempOperand[1] * 4 + programBuilder + 0x6c4) = 0;
    *(undefined1 *)(tempOperand[1] * 4 + programBuilder + 0x6c5) = 0;
    *(undefined1 *)(tempOperand[1] * 4 + programBuilder + 0x6c6) = 0;
    return;
  }
  if (operandKind == 0) {
    *(undefined1 *)(tempOperand[1] * 4 + programBuilder + 0x6c4) = 0;
    *(undefined1 *)(tempOperand[1] * 4 + programBuilder + 0x6c5) = 0;
    *(undefined1 *)(tempOperand[1] * 4 + programBuilder + 0x6c6) = 0;
    *(undefined1 *)(tempOperand[1] * 4 + programBuilder + 0x6c7) = 0;
    return;
  }
  if (operandKind != 2) {
    return;
  }
  laneSel = tempOperand[6];
  if (laneSel != 1) {
    if (laneSel == 0) {
      *(undefined1 *)(tempOperand[1] * 4 + programBuilder + 0x6c4) = 0;
      return;
    }
    if (laneSel != 2) {
      if (laneSel != 3) {
        return;
      }
      *(undefined1 *)(tempOperand[1] * 4 + programBuilder + 0x6c7) = 0;
      return;
    }
    *(undefined1 *)(tempOperand[1] * 4 + programBuilder + 0x6c6) = 0;
    return;
  }
  *(undefined1 *)(tempOperand[1] * 4 + programBuilder + 0x6c5) = 0;
  return;
}

/* ffvpResolveMaterialSource @ 0x912f0 (208 bytes) */
int ffvpResolveMaterialSource(programBuilder, sourceId, materialComponent, fileOut, regOut)
  int programBuilder;
  int sourceId;
  int materialComponent;
  undefined4 *fileOut;
  int *regOut;
{
  uint materialIndex;
  
  materialIndex = sourceId - 8;
  if (materialIndex < 2) {
    *fileOut = *(undefined4 *)(*(int *)(programBuilder + 0x3ec) + 8);
    if (materialComponent == 1) {
      *regOut = *(int *)(materialIndex * 0x24 + programBuilder + 0x2dc);
    }
    else if (materialComponent == 0) {
      *regOut = *(int *)(materialIndex * 0x24 + programBuilder + 0x2d8);
    }
    else if (materialComponent == 2) {
      *regOut = *(int *)(materialIndex * 0x24 + programBuilder + 0x2e0);
    }
    else {
      if (materialComponent != 3) {
        return 4;
      }
      *regOut = *(int *)(materialIndex * 0x24 + programBuilder + 0x2ec);
    }
  }
  else {
    *fileOut = *(undefined4 *)(*(int *)(programBuilder + 0x3ec) + 4);
    *regOut = *(int *)(sourceId * 4 + programBuilder + 0xc);
  }
  return (uint)(*regOut == -1) << 1;
}

/* ffvpResolveFixedSource @ 0x913e0 (224 bytes) */
int ffvpResolveFixedSource(programBuilder, sourceKind, fileOut, regOut, selectOut)
  int programBuilder;
  uint sourceKind;
  undefined4 *fileOut;
  int *regOut;
  undefined4 *selectOut;
{
  int sideOffset;
  undefined4 status;
  
  if (sourceKind < 2) {
    *fileOut = *(undefined4 *)(*(int *)(programBuilder + 0x3ec) + 4);
    *regOut = *(int *)(programBuilder + 0x58);
  }
  else {
    if (3 < sourceKind) {
      return 4;
    }
    *fileOut = *(undefined4 *)(*(int *)(programBuilder + 0x3ec) + 8);
    *regOut = *(int *)((sourceKind & 1) * 4 + programBuilder + 800);
  }
  status = 2;
  if (*regOut != -1) {
    sideOffset = (sourceKind & 1) * 4;
    status = 0;
    *selectOut = *(undefined4 *)((PTR_DAT_001dbdd4)[*(int *)(programBuilder + 0x3d8)] + sideOffset);
    selectOut[1] = *(undefined4 *)((PTR_DAT_001dbdd4)[*(int *)(programBuilder + 0x3d8)] + sideOffset);
    selectOut[2] = *(undefined4 *)((PTR_DAT_001dbdd4)[*(int *)(programBuilder + 0x3d8)] + sideOffset);
    selectOut[3] = *(undefined4 *)((PTR_DAT_001dbdd4)[*(int *)(programBuilder + 0x3d8)] + sideOffset);
  }
  return status;
}

/* noop_914c0 @ 0x914c0 (28 bytes) */
int noop_914c0(unusedArg1, unusedArg2, unusedArg3, unusedArg4, unusedArg5, unusedArg6, unusedArg7, unusedArg8)
  undefined4 unusedArg1;
  undefined4 unusedArg2;
  undefined4 unusedArg3;
  undefined4 unusedArg4;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
  undefined4 unusedArg7;
  undefined4 unusedArg8;
{
  return;
}

/* ffvpEmitEyePositionMad @ 0x914e0 (492 bytes) */
int ffvpEmitEyePositionMad(programBuilder)
  int programBuilder;
{
  undefined4 constFile;
  int modelviewConstReg;
  undefined4 status;
  int allocStatus;
  int glCtx;
  undefined4 dstTempFile;
  undefined4 eyePositionReg;
  int emit1Src1File;
  int emit1Src1Index;
  int emit1Src1Select;
  int src1File;
  int src1Index;
  int emit2Src1Select;
  int emit3Src1Select;
  int emit4Src1Select;
  
  status = 0;
  glCtx = *(int *)(programBuilder + 0x3d4);
  if (*(int *)(programBuilder + 0x3f8) == -1) {
    allocStatus = ((int (*)())ffvpAllocTempRegister)(programBuilder,0,programBuilder + 0x3f4);
    status = 7;
    if (allocStatus == 0) {
      dstTempFile = **(undefined4 **)(programBuilder + 0x3f0);
      constFile = *(undefined4 *)(*(int *)(programBuilder + 0x3ec) + 8);
      eyePositionReg = *(undefined4 *)(programBuilder + 0x3f8);
      modelviewConstReg = *(int *)(programBuilder + 0xb4);
      emit1Src1File = *(int *)((int)*(int *)((int)programBuilder + 1004) + 4);
      emit1Src1Index = *(int *)((int)programBuilder + 0);
      emit1Src1Select = &DAT_001dbcd4;
      (**(code **)(((unsigned char *)0x000012ec) + glCtx))
                (programBuilder,dstTempFile,eyePositionReg,&DAT_001dbd24,constFile,modelviewConstReg + 3,&DAT_001dbd14,&DAT_001fa5e8,emit1Src1File,emit1Src1Index,emit1Src1Select,&DAT_001fa5e8);
      src1File = *(int *)((int)*(int *)((int)programBuilder + 1004) + 4);
      src1Index = *(int *)((int)programBuilder + 0);
      emit2Src1Select = &DAT_001dbcf4;
      (**(code **)(((unsigned char *)0x000012f4) + glCtx))
                (programBuilder,dstTempFile,eyePositionReg,&DAT_001dbd24,constFile,modelviewConstReg + 2,&DAT_001dbd14,&DAT_001fa5e8,src1File,src1Index,emit2Src1Select,&DAT_001fa5e8,dstTempFile,eyePositionReg,&DAT_001dbd14,&DAT_001fa5e8);
      emit3Src1Select = &DAT_001dbce4;
      (**(code **)(((unsigned char *)0x000012f4) + glCtx))
                (programBuilder,dstTempFile,eyePositionReg,&DAT_001dbd24,constFile,modelviewConstReg + 1,&DAT_001dbd14,&DAT_001fa5e8,src1File,src1Index,emit3Src1Select,&DAT_001fa5e8,dstTempFile,eyePositionReg,&DAT_001dbd14,&DAT_001fa5e8);
      emit4Src1Select = &DAT_001fa5f8;
      (**(code **)(((unsigned char *)0x000012f4) + glCtx))
                (programBuilder,dstTempFile,eyePositionReg,&DAT_001dbd24,constFile,modelviewConstReg,&DAT_001dbd14,&DAT_001fa5e8,src1File,src1Index,emit4Src1Select,&DAT_001fa5e8,dstTempFile,eyePositionReg,&DAT_001dbd14,&DAT_001fa5e8);
      status = 0;
    }
  }
  return status;
}

/* ffvpEmitEyePositionDp4 @ 0x916d0 (420 bytes) */
int ffvpEmitEyePositionDp4(programBuilder)
  int programBuilder;
{
  undefined4 constFile;
  int modelviewConstReg;
  undefined4 status;
  int allocStatus;
  int glCtx;
  undefined4 dstTempFile;
  undefined4 eyePositionReg;
  int src1File;
  int src1Index;
  
  status = 0;
  glCtx = *(int *)(programBuilder + 0x3d4);
  if (*(int *)(programBuilder + 0x3f8) == -1) {
    allocStatus = ((int (*)())ffvpAllocTempRegister)(programBuilder,0,programBuilder + 0x3f4);
    status = 7;
    if (allocStatus == 0) {
      constFile = *(undefined4 *)(*(int *)(programBuilder + 0x3ec) + 8);
      dstTempFile = **(undefined4 **)(programBuilder + 0x3f0);
      eyePositionReg = *(undefined4 *)(programBuilder + 0x3f8);
      modelviewConstReg = *(int *)(programBuilder + 0xb4);
      src1File = *(int *)((int)*(int *)((int)programBuilder + 1004) + 4);
      src1Index = *(int *)((int)programBuilder + 0);
      (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                (programBuilder,dstTempFile,eyePositionReg,&DAT_001dbd04,constFile,modelviewConstReg,&DAT_001dbd14,&DAT_001fa5e8,src1File,src1Index,&DAT_001dbd14,&DAT_001fa5e8);
      (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                (programBuilder,dstTempFile,eyePositionReg,&DAT_001dbd64,constFile,modelviewConstReg + 1,&DAT_001dbd14,&DAT_001fa5e8,src1File,src1Index,&DAT_001dbd14,&DAT_001fa5e8);
      (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                (programBuilder,dstTempFile,eyePositionReg,&DAT_001dbd54,constFile,modelviewConstReg + 2,&DAT_001dbd14,&DAT_001fa5e8,src1File,src1Index,&DAT_001dbd14,&DAT_001fa5e8);
      (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                (programBuilder,dstTempFile,eyePositionReg,&DAT_001dbd44,constFile,modelviewConstReg + 3,&DAT_001dbd14,&DAT_001fa5e8,src1File,src1Index,&DAT_001dbd14,&DAT_001fa5e8);
      status = 0;
    }
  }
  return status;
}

/* ffvpEmitEyeDistanceSquared @ 0x91880 (248 bytes) */
int ffvpEmitEyeDistanceSquared(programBuilder)
  int programBuilder;
{
  undefined4 status;
  int allocStatus;
  int glCtx;
  int eyePositionReg;
  
  status = 0;
  glCtx = *(int *)(programBuilder + 0x3d4);
  if (*(int *)(programBuilder + 0x510) == -1) {
    eyePositionReg = *(int *)(programBuilder + 0x3f8);
    if (eyePositionReg == -1) {
      if ((*(uint *)(((unsigned char *)0x000013c0) + glCtx) & 4) == 0) {
        ((int (*)())ffvpEmitEyePositionDp4)(programBuilder);
      }
      else {
        ((int (*)())ffvpEmitEyePositionMad)(programBuilder);
      }
      eyePositionReg = *(int *)(programBuilder + 0x3f8);
      if (eyePositionReg == -1) {
        return 2;
      }
    }
    allocStatus = ((int (*)())ffvpAllocTempRegister)(programBuilder,2,programBuilder + 0x50c);
    status = 7;
    if (allocStatus == 0) {
      (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                (programBuilder,**(undefined4 **)(programBuilder + 0x3f0),*(undefined4 *)(programBuilder + 0x510),
                 programBuilder + 0x514,**(undefined4 **)(programBuilder + 0x3ec),eyePositionReg,&DAT_001dbd74,&DAT_001fa5e8,**(undefined4 **)(programBuilder + 0x3ec),eyePositionReg,&DAT_001dbd74,&DAT_001fa5e8);
      status = 0;
    }
  }
  return status;
}

/* ffvpEmitInverseW @ 0x91980 (176 bytes) */
int ffvpEmitInverseW(programBuilder, src0File, src0Index)
  int programBuilder;
  undefined4 src0File;
  undefined4 src0Index;
{
  undefined4 status;
  int allocStatus;
  int glCtx;
  
  status = 0;
  glCtx = *(int *)(programBuilder + 0x3d4);
  if (*(int *)(programBuilder + 0x6a0) == -1) {
    allocStatus = ((int (*)())ffvpAllocTempRegister)(programBuilder,2,programBuilder + 0x69c);
    status = 7;
    if (allocStatus == 0) {
      (**(code **)(((unsigned char *)0x00001314) + glCtx))
                (programBuilder,**(undefined4 **)(programBuilder + 0x3f0),*(undefined4 *)(programBuilder + 0x6a0),
                 programBuilder + 0x6a4,src0File,src0Index,&DAT_001dbcd4,&DAT_001fa5e8);
      status = 0;
    }
  }
  return status;
}

/* ffvpEmitEyeNormal @ 0x91a30 (352 bytes) */
int ffvpEmitEyeNormal(programBuilder)
  int programBuilder;
{
  undefined4 constFile;
  int invModelviewConstReg;
  undefined4 status;
  int allocStatus;
  int glCtx;
  undefined4 dstTempFile;
  undefined4 eyeNormalReg;
  int emit1Src1File;
  int emit1Src1Index;
  
  status = 0;
  glCtx = *(int *)(programBuilder + 0x3d4);
  if (*(int *)(programBuilder + 0x448) == -1) {
    allocStatus = ((int (*)())ffvpAllocTempRegister)(programBuilder,1,programBuilder + 0x444);
    status = 7;
    if (allocStatus == 0) {
      constFile = *(undefined4 *)(*(int *)(programBuilder + 0x3ec) + 8);
      dstTempFile = **(undefined4 **)(programBuilder + 0x3f0);
      eyeNormalReg = *(undefined4 *)(programBuilder + 0x448);
      invModelviewConstReg = *(int *)(programBuilder + 0xc4);
      emit1Src1File = *(int *)((int)*(int *)((int)programBuilder + 1004) + 4);
      emit1Src1Index = *(int *)((int)programBuilder + 4);
      (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                (programBuilder,dstTempFile,eyeNormalReg,&DAT_001dbd04,constFile,invModelviewConstReg,&DAT_001dbd74,&DAT_001fa5e8,emit1Src1File,emit1Src1Index,&DAT_001dbd74,&DAT_001fa5e8);
      (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                (programBuilder,dstTempFile,eyeNormalReg,&DAT_001dbd64,constFile,invModelviewConstReg + 1,&DAT_001dbd74,&DAT_001fa5e8,emit1Src1File,emit1Src1Index,&DAT_001dbd74,&DAT_001fa5e8);
      (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                (programBuilder,dstTempFile,eyeNormalReg,&DAT_001dbd54,constFile,invModelviewConstReg + 2,&DAT_001dbd74,&DAT_001fa5e8,emit1Src1File,emit1Src1Index,&DAT_001dbd74,&DAT_001fa5e8);
      status = 0;
    }
  }
  return status;
}

/* ffvpEmitNormalizedNormal @ 0x91b90 (460 bytes) */
int ffvpEmitNormalizedNormal(programBuilder)
  int programBuilder;
{
  int allocStatus;
  undefined4 normalFile;
  int glCtx;
  int normalReg;
  undefined4 srcTempFile;
  undefined4 unitNormalReg;
  undefined4 dstTempFile;
  undefined1 invLengthTemp [4];
  undefined4 invLengthTempReg;
  undefined1 invLengthTempMask [16];
  undefined1 invLengthTempSelect [32];
  int emit3Src1Select;
  
  glCtx = *(int *)(programBuilder + 0x3d4);
  if (*(int *)(programBuilder + 0x498) != -1) {
    return 0;
  }
  if (*(char *)(glCtx + 0x12a) == '\0') {
    normalReg = *(int *)(programBuilder + 4);
    normalFile = *(undefined4 *)(*(int *)(programBuilder + 0x3ec) + 4);
    allocStatus = ((int (*)())ffvpAllocTempRegister)(programBuilder,1,programBuilder + 0x494);
    if (allocStatus != 0) {
      return 7;
    }
  }
  else {
    normalReg = *(int *)(programBuilder + 0x448);
    if (normalReg == -1) {
      ((int (*)())ffvpEmitEyeNormal)(programBuilder);
      normalReg = *(int *)(programBuilder + 0x448);
      if (normalReg == -1) {
        return 2;
      }
    }
    normalFile = **(undefined4 **)(programBuilder + 0x3ec);
    _memcpy(programBuilder + 0x494,programBuilder + 0x444,0x28);
  }
  allocStatus = ((int (*)())ffvpAllocTempRegister)(programBuilder,2,invLengthTemp);
  if (allocStatus != 0) {
    return 7;
  }
  dstTempFile = **(undefined4 **)(programBuilder + 0x3f0);
  srcTempFile = **(undefined4 **)(programBuilder + 0x3ec);
  unitNormalReg = *(undefined4 *)(programBuilder + 0x498);
  (**(code **)(((unsigned char *)0x000012e4) + glCtx))
            (programBuilder,dstTempFile,invLengthTempReg,invLengthTempMask,normalFile,normalReg,&DAT_001dbd74,&DAT_001fa5e8,normalFile,normalReg,&DAT_001dbd74,&DAT_001fa5e8);
  (**(code **)(((unsigned char *)0x00001318) + glCtx))
            (programBuilder,dstTempFile,invLengthTempReg,invLengthTempMask,srcTempFile,invLengthTempReg,invLengthTempSelect,&DAT_001fa5e8);
  emit3Src1Select = &DAT_001dbd74;
  (**(code **)(((unsigned char *)0x000012ec) + glCtx))
            (programBuilder,dstTempFile,unitNormalReg,&DAT_001dbd84,srcTempFile,invLengthTempReg,invLengthTempSelect,&DAT_001fa5e8,normalFile,normalReg,emit3Src1Select,&DAT_001fa5e8);
  ((int (*)())ffvpFreeTempRegister)(programBuilder,invLengthTemp);
  return 0;
}

/* ffvpEmitRescaledNormal @ 0x91d70 (300 bytes) */
int ffvpEmitRescaledNormal(programBuilder)
  int programBuilder;
{
  int allocStatus;
  int glCtx;
  int emit1Src1Select;
  
  glCtx = *(int *)(programBuilder + 0x3d4);
  if (*(int *)(programBuilder + 0x470) == -1) {
    if (*(char *)(glCtx + 0x12a) == '\0') {
      allocStatus = ((int (*)())ffvpAllocTempRegister)(programBuilder,2,programBuilder + 0x46c);
      if (allocStatus != 0) {
        return 7;
      }
    }
    else {
      if ((*(int *)(programBuilder + 0x448) == -1) &&
         (((int (*)())ffvpEmitEyeNormal)(programBuilder), *(int *)(programBuilder + 0x448) == -1)) {
        return 2;
      }
      _memcpy(programBuilder + 0x46c,programBuilder + 0x444,0x28);
    }
    emit1Src1Select = &DAT_001dbd74;
    (**(code **)(((unsigned char *)0x000012ec) + glCtx))
              (programBuilder,**(undefined4 **)(programBuilder + 0x3f0),*(undefined4 *)(programBuilder + 0x470),
               &DAT_001dbd84,*(undefined4 *)(*(int *)(programBuilder + 0x3ec) + 8),
               *(undefined4 *)(programBuilder + 0x344),&DAT_001fa5f8,&DAT_001fa5e8,(*(char *)(glCtx + 0x12a) == '\0' ? (*(int **)(programBuilder + 0x3ec))[1] : **(int **)(programBuilder + 0x3ec)),(*(char *)(glCtx + 0x12a) == '\0' ? *(int *)(programBuilder + 4) : *(int *)(programBuilder + 0x448)),emit1Src1Select,&DAT_001fa5e8);
  }
  return 0;
}

/* ffvpEmitBlendWeights @ 0x91eb0 (648 bytes) */
int ffvpEmitBlendWeights(programBuilder, weightCount, implicitLastWeight)
  int programBuilder;
  uint weightCount;
  int implicitLastWeight;
{
  undefined4 inputFile;
  undefined4 status;
  int allocStatus;
  undefined4 weightInputReg;
  undefined4 dstTempFile;
  undefined4 blendWeightsReg;
  int glCtx;
  undefined4 fillMask0;
  undefined4 fillMask1;
  undefined4 fillMask2;
  undefined4 fillMask3;
  undefined4 fillSelect0;
  undefined4 fillSelect1;
  undefined4 fillSelect2;
  undefined4 fillSelect3;
  undefined4 fillNegate0;
  undefined4 fillNegate1;
  undefined4 fillNegate2;
  undefined4 fillNegate3;
  int emit3Src1Select;
  int emit3Src1Negate;
  
  status = 0;
  glCtx = *(int *)(programBuilder + 0x3d4);
  if (*(int *)(programBuilder + 0x560) == -1) {
    allocStatus = ((int (*)())ffvpAllocTempRegister)(programBuilder,0,programBuilder + 0x55c);
    status = 7;
    if (allocStatus == 0) {
      blendWeightsReg = *(undefined4 *)(programBuilder + 0x560);
      weightInputReg = *(undefined4 *)(programBuilder + 0x5c);
      dstTempFile = **(undefined4 **)(programBuilder + 0x3f0);
      inputFile = *(undefined4 *)(*(int *)(programBuilder + 0x3ec) + 4);
      if (weightCount < 4) {
        if (implicitLastWeight == 0) {
          (**(code **)(((unsigned char *)0x000012e8) + glCtx))
                    (programBuilder,dstTempFile,blendWeightsReg,&DAT_001dbd24,inputFile,weightInputReg,&DAT_001dbd74,&DAT_001fa5e8);
          status = 0;
        }
        else {
          fillMask0 = DAT_001fa608;
          fillSelect0 = DAT_001dbd74;
          fillMask1 = DAT_001fa60c;
          fillMask3 = DAT_001fa614;
          fillMask2 = DAT_001fa610;
          fillSelect3 = DAT_001dbd80;
          fillSelect1 = DAT_001dbd78;
          fillSelect2 = DAT_001dbd7c;
          if (weightCount == 1) {
            fillSelect2 = 4;
            fillSelect1 = 4;
            fillMask1 = 1;
          }
          else if (weightCount == 0) {
            fillSelect2 = 4;
            fillMask0 = 1;
            fillSelect0 = 4;
            fillSelect1 = 4;
          }
          else if (weightCount == 2) {
            fillMask2 = 1;
            fillSelect2 = 4;
          }
          else if (weightCount == 3) {
            fillMask3 = 1;
          }
          fillNegate2 = 1;
          fillNegate0 = 1;
          fillNegate1 = 1;
          fillNegate3 = 0;
          (**(code **)(((unsigned char *)0x000012e8) + glCtx))
                    (programBuilder,dstTempFile,blendWeightsReg,&DAT_001dbd24,inputFile,weightInputReg,&fillSelect0,&DAT_001fa5e8);
          emit3Src1Select = ((unsigned char *)&DAT_001dbdc0 + 4);
          emit3Src1Negate = &DAT_001fa5e8;
          (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                    (programBuilder,dstTempFile,blendWeightsReg,&fillMask0,**(undefined4 **)(programBuilder + 0x3ec),blendWeightsReg,
                     &DAT_001dbdb4,&fillNegate0,**(undefined4 **)(programBuilder + 0x3ec),blendWeightsReg,emit3Src1Select,emit3Src1Negate);
          status = 0;
        }
      }
      else {
        (**(code **)(((unsigned char *)0x000012e8) + glCtx))
                  (programBuilder,dstTempFile,blendWeightsReg,&DAT_001dbd24,inputFile,weightInputReg,&DAT_001dbd14,&DAT_001fa5e8);
        status = 0;
      }
    }
  }
  return status;
}

/* ffvpEmitInverseEyeDistance @ 0x92150 (200 bytes) */
int ffvpEmitInverseEyeDistance(programBuilder)
  int programBuilder;
{
  undefined4 status;
  int allocStatus;
  int glCtx;
  int eyeDistSqReg;
  
  status = 0;
  glCtx = *(int *)(programBuilder + 0x3d4);
  if (*(int *)(programBuilder + 0x538) == -1) {
    eyeDistSqReg = *(int *)(programBuilder + 0x510);
    if (eyeDistSqReg == -1) {
      ((int (*)())ffvpEmitEyeDistanceSquared)(programBuilder);
      eyeDistSqReg = *(int *)(programBuilder + 0x510);
      if (eyeDistSqReg == -1) {
        return 2;
      }
    }
    allocStatus = ((int (*)())ffvpAllocTempRegister)(programBuilder,2,programBuilder + 0x534);
    status = 7;
    if (allocStatus == 0) {
      (**(code **)(((unsigned char *)0x00001318) + glCtx))
                (programBuilder,**(undefined4 **)(programBuilder + 0x3f0),*(undefined4 *)(programBuilder + 0x538),
                 programBuilder + 0x53c,**(undefined4 **)(programBuilder + 0x3ec),eyeDistSqReg,programBuilder + 0x524,
                 &DAT_001fa5e8);
      status = 0;
    }
  }
  return status;
}

/* ffvpEmitEyeVector @ 0x92220 (296 bytes) */
int ffvpEmitEyeVector(programBuilder)
  int programBuilder;
{
  undefined4 status;
  int allocStatus;
  int glCtx;
  int invEyeDistReg;
  int emit1Src1Index;
  int emit1Src1Select;
  
  glCtx = *(int *)(programBuilder + 0x3d4);
  if (*(int *)(programBuilder + 0x420) != -1) {
    return 0;
  }
  invEyeDistReg = *(int *)(programBuilder + 0x538);
  if (invEyeDistReg == -1) {
    ((int (*)())ffvpEmitInverseEyeDistance)(programBuilder);
    invEyeDistReg = *(int *)(programBuilder + 0x538);
    if (invEyeDistReg != -1) goto LAB_0009226c;
LAB_00092320:
    status = 2;
  }
  else {
LAB_0009226c:
    if (*(int *)(programBuilder + 0x3f8) == -1) {
      if ((*(uint *)(((unsigned char *)0x000013c0) + glCtx) & 4) == 0) {
        ((int (*)())ffvpEmitEyePositionDp4)(programBuilder);
      }
      else {
        ((int (*)())ffvpEmitEyePositionMad)(programBuilder);
      }
      if (*(int *)(programBuilder + 0x3f8) == -1) goto LAB_00092320;
    }
    allocStatus = ((int (*)())ffvpAllocTempRegister)(programBuilder,1,programBuilder + 0x41c);
    status = 7;
    if (allocStatus == 0) {
      emit1Src1Index = *(int *)((int)programBuilder + 1016);
      emit1Src1Select = &DAT_001dbd74;
      (**(code **)(((unsigned char *)0x000012ec) + glCtx))
                (programBuilder,**(undefined4 **)(programBuilder + 0x3f0),*(undefined4 *)(programBuilder + 0x420),
                 &DAT_001dbd84,**(undefined4 **)(programBuilder + 0x3ec),invEyeDistReg,programBuilder + 0x54c,&DAT_001fa5e8,**(undefined4 **)(programBuilder + 0x3ec),emit1Src1Index,emit1Src1Select,&DAT_001fa5e8);
      status = 0;
    }
  }
  return status;
}

/* ffvpEmitReflectionVector @ 0x92350 (512 bytes) */
int ffvpEmitReflectionVector(programBuilder)
  int programBuilder;
{
  undefined4 reflectionReg;
  int glCtx;
  int eyeVectorReg;
  int normalReg;
  undefined4 dstTempFile;
  undefined4 srcTempFile;
  undefined1 dotTemp [4];
  undefined4 dotTempReg;
  undefined1 dotTempMask [16];
  undefined1 dotTempSelect [40];
  int emit2Src1Select;
  int emit2Src1Negate;
  int emit2Src2Index;
  
  glCtx = *(int *)(programBuilder + 0x3d4);
  if (*(int *)(programBuilder + 0x4c0) != -1) {
    return 0;
  }
  eyeVectorReg = *(int *)(programBuilder + 0x420);
  if (eyeVectorReg == -1) {
    ((int (*)())ffvpEmitEyeVector)(programBuilder);
    eyeVectorReg = *(int *)(programBuilder + 0x420);
    if (eyeVectorReg == -1) {
      return 2;
    }
  }
  if (*(char *)(glCtx + 0x128) == '\0') {
    if (*(char *)(glCtx + 300) == '\0') {
      if (*(int *)(programBuilder + 0x448) != -1) goto LAB_00092420;
      ((int (*)())ffvpEmitEyeNormal)(programBuilder);
      normalReg = *(int *)(programBuilder + 0x448);
    }
    else {
      if (*(int *)(programBuilder + 0x470) != -1) goto LAB_00092420;
      ((int (*)())ffvpEmitRescaledNormal)(programBuilder);
      normalReg = *(int *)(programBuilder + 0x470);
    }
  }
  else {
    if (*(int *)(programBuilder + 0x498) != -1) goto LAB_00092420;
    ((int (*)())ffvpEmitNormalizedNormal)(programBuilder);
    normalReg = *(int *)(programBuilder + 0x498);
  }
  if (normalReg == -1) {
    return 2;
  }
LAB_00092420:
  normalReg = ((int (*)())ffvpAllocTempRegister)(programBuilder,1,programBuilder + 0x4bc);
  if (normalReg == 0) {
    reflectionReg = *(undefined4 *)(programBuilder + 0x4c0);
    normalReg = ((int (*)())ffvpAllocTempRegister)(programBuilder,2,dotTemp);
    if (normalReg == 0) {
      srcTempFile = **(undefined4 **)(programBuilder + 0x3ec);
      dstTempFile = **(undefined4 **)(programBuilder + 0x3f0);
      (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                (programBuilder,dstTempFile,dotTempReg,dotTempMask,srcTempFile,eyeVectorReg,&DAT_001dbd74,&DAT_001fa5e8,srcTempFile,(*(char *)(glCtx + 0x128) == '\0' ? (*(char *)(glCtx + 300) == '\0' ? *(int *)(programBuilder + 0x448) : *(int *)(programBuilder + 0x470)) : *(int *)(programBuilder + 0x498)),&DAT_001dbd74,&DAT_001fa5e8);
      emit2Src1Select = &DAT_001dbd74;
      emit2Src1Negate = &DAT_001dbd94;
      emit2Src2Index = *(int *)((int)programBuilder + 1056);
      (**(code **)(((unsigned char *)0x000012f8) + glCtx))
                (programBuilder,dstTempFile,reflectionReg,&DAT_001dbd84,srcTempFile,dotTempReg,dotTempSelect,&DAT_001fa5e8,srcTempFile,(*(char *)(glCtx + 0x128) == '\0' ? (*(char *)(glCtx + 300) == '\0' ? *(int *)(programBuilder + 0x448) : *(int *)(programBuilder + 0x470)) : *(int *)(programBuilder + 0x498)),emit2Src1Select,emit2Src1Negate,srcTempFile,emit2Src2Index,emit2Src1Select,&DAT_001fa5e8);
      ((int (*)())ffvpFreeTempRegister)(programBuilder,dotTemp);
      return 0;
    }
  }
  return 7;
}

/* ffvpEmitSphereMapCoord @ 0x92570 (796 bytes) */
int ffvpEmitSphereMapCoord(programBuilder)
  int programBuilder;
{
  undefined4 sphereMapReg;
  undefined4 status;
  int allocStatus;
  int glCtx;
  undefined4 dstTempFile;
  undefined4 srcTempFile;
  undefined4 selectRowA0;
  undefined4 selectRowA1;
  undefined4 selectRowA2;
  undefined4 selectRowA3;
  undefined4 selectRowC0;
  undefined4 selectRowC1;
  undefined4 selectRowC2;
  undefined4 selectRowC3;
  undefined4 selectRowB0;
  undefined4 selectRowB1;
  undefined4 selectRowB2;
  undefined4 selectRowB3;
  undefined1 tempA [4];
  undefined4 tempAReg;
  undefined1 tempAMask [16];
  undefined4 tempASelect0;
  undefined4 tempASelect1;
  undefined4 tempASelect2;
  undefined1 tempB [4];
  undefined4 tempBReg;
  undefined1 tempBMask [16];
  undefined4 tempBSelect0;
  undefined4 tempBSelect1;
  undefined4 tempBSelect3;
  int emit2Src1Index;
  int emit2Src1Select;
  int emit2Src2Select;
  int emit6Src1Index;
  int emit6Src1Select;
  int emit6Src2Index;
  int emit6Src2Select;
  
  status = 0;
  glCtx = *(int *)(programBuilder + 0x3d4);
  if (*(int *)(programBuilder + 0x4e8) == -1) {
    if ((*(int *)(programBuilder + 0x4c0) == -1) &&
       (((int (*)())ffvpEmitReflectionVector)(programBuilder), *(int *)(programBuilder + 0x4c0) == -1)) {
      return 2;
    }
    allocStatus = ((int (*)())ffvpAllocTempRegister)(programBuilder,1,programBuilder + 0x4e4);
    if (allocStatus == 0) {
      sphereMapReg = *(undefined4 *)(programBuilder + 0x4e8);
      allocStatus = ((int (*)())ffvpAllocTempRegister)(programBuilder,2,tempA);
      if (allocStatus == 0) {
        allocStatus = ((int (*)())ffvpAllocTempRegister)(programBuilder,2,tempB);
        if (allocStatus == 0) {
          srcTempFile = **(undefined4 **)(programBuilder + 0x3ec);
          dstTempFile = **(undefined4 **)(programBuilder + 0x3f0);
          (**(code **)(((unsigned char *)0x000012f0) + glCtx))
                    (programBuilder,dstTempFile,tempAReg,tempAMask,srcTempFile,tempAReg,&DAT_001dbdb4,&DAT_001fa5e8,srcTempFile,tempAReg,&DAT_001dbdb4,&DAT_001fa5e8);
          selectRowA0 = 4;
          selectRowA1 = 4;
          selectRowA3 = 4;
          selectRowA2 = tempASelect2;
          emit2Src1Index = *(int *)((int)programBuilder + 1216);
          emit2Src1Select = &DAT_001dbd74;
          emit2Src2Select = &selectRowA0;
          (**(code **)(((unsigned char *)0x000012f4) + glCtx))
                    (programBuilder,dstTempFile,sphereMapReg,&DAT_001dbd84,srcTempFile,tempAReg,&tempASelect0,&DAT_001fa5e8,srcTempFile,emit2Src1Index,emit2Src1Select,&DAT_001fa5e8,srcTempFile,tempAReg,emit2Src2Select,&DAT_001fa5e8);
          (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                    (programBuilder,dstTempFile,tempAReg,tempAMask,srcTempFile,sphereMapReg,&DAT_001dbd74,&DAT_001fa5e8,srcTempFile,sphereMapReg,&DAT_001dbd74,&DAT_001fa5e8);
          (**(code **)(((unsigned char *)0x00001318) + glCtx))
                    (programBuilder,dstTempFile,tempAReg,tempAMask,srcTempFile,tempAReg,&tempASelect0,&DAT_001fa5e8);
          (**(code **)(((unsigned char *)0x0000131c) + glCtx))
                    (programBuilder,dstTempFile,tempBReg,tempBMask,srcTempFile,tempBReg,&DAT_001dbdb4,&DAT_001dbd94);
          selectRowC0 = *(undefined4 *)(programBuilder + 0x4d4);
          selectRowC1 = *(undefined4 *)(programBuilder + 0x4d8);
          selectRowB2 = 4;
          selectRowA2 = 4;
          selectRowA3 = 4;
          selectRowA0 = tempASelect0;
          selectRowA1 = tempASelect1;
          selectRowC2 = 4;
          selectRowC3 = 4;
          selectRowB0 = tempBSelect0;
          selectRowB1 = tempBSelect1;
          selectRowB3 = tempBSelect3;
          emit6Src1Index = *(int *)((int)programBuilder + 1216);
          emit6Src1Select = &selectRowC0;
          emit6Src2Index = tempBReg;
          emit6Src2Select = &selectRowB0;
          (**(code **)(((unsigned char *)0x000012f4) + glCtx))
                    (programBuilder,dstTempFile,sphereMapReg,&DAT_001dbd84,srcTempFile,tempAReg,&selectRowA0,&DAT_001fa5e8,srcTempFile,emit6Src1Index,emit6Src1Select,&DAT_001fa5e8,srcTempFile,emit6Src2Index,emit6Src2Select,&DAT_001fa5e8);
          ((int (*)())ffvpFreeTempRegister)(programBuilder,tempA);
          ((int (*)())ffvpFreeTempRegister)(programBuilder,tempB);
          return 0;
        }
      }
    }
    status = 7;
  }
  return status;
}

/* ffvpEmitFogExp2 @ 0x928a0 (792 bytes) */
int ffvpEmitFogExp2(programBuilder)
  int programBuilder;
{
  undefined4 srcTempFile;
  undefined4 fogParamConstReg;
  undefined4 *outputMask;
  undefined4 *fogCoordSelect;
  int stateBlock;
  int allocStatus;
  int fogCoordSelectIndex;
  undefined4 *fileTable;
  int fogCoordReg;
  undefined4 status;
  int glCtxCopy;
  undefined4 constFile;
  undefined4 fogDstReg;
  undefined4 dstFile;
  undefined4 fogCoordFile;
  int glCtx;
  undefined1 fogTemp [4];
  undefined4 fogTempReg;
  undefined1 fogTempMask [16];
  undefined1 fogTempSelect [32];
  int emit3Src1File;
  int emit3Src1Select;
  
  status = 0;
  glCtx = *(int *)(programBuilder + 0x3d4);
  if (*(int *)(programBuilder + 0x588) == -1) {
    fileTable = *(undefined4 **)(programBuilder + 0x3ec);
    fogParamConstReg = *(undefined4 *)(programBuilder + 0x330);
    dstFile = **(undefined4 **)(programBuilder + 0x3f0);
    constFile = fileTable[2];
    if (*(short *)(((unsigned char *)0x00002e06) + *(int *)(*(int *)(glCtx + 4) + 0x10)) == -0x7bae) {
      fogCoordReg = *(int *)(programBuilder + 0x3f8);
      if (fogCoordReg == -1) {
        if ((*(uint *)(((unsigned char *)0x000013c0) + glCtx) & 4) == 0) {
          ((int (*)())ffvpEmitEyePositionDp4)(programBuilder);
        }
        else {
          ((int (*)())ffvpEmitEyePositionMad)(programBuilder);
        }
        fogCoordReg = *(int *)(programBuilder + 0x3f8);
        if (fogCoordReg == -1) {
          return 2;
        }
        fileTable = *(undefined4 **)(programBuilder + 0x3ec);
      }
      fogCoordFile = *fileTable;
      fogCoordSelect = &DAT_001dbcf4;
    }
    else {
      fogCoordSelectIndex = *(int *)(programBuilder + 0x54);
      fogCoordFile = fileTable[1];
      fogCoordReg = *(int *)(programBuilder + 0x50);
      if (fogCoordSelectIndex == 1) {
        fogCoordSelect = &DAT_001dbce4;
      }
      else if (fogCoordSelectIndex == 0) {
        fogCoordSelect = &DAT_001fa5f8;
      }
      else if (fogCoordSelectIndex == 2) {
        fogCoordSelect = &DAT_001dbcf4;
      }
      else if (fogCoordSelectIndex == 3) {
        fogCoordSelect = &DAT_001dbcd4;
      }
      else {
        fogCoordSelect = &DAT_001dbd14;
      }
    }
    allocStatus = ((int (*)())ffvpAllocTempRegister)(programBuilder,2,programBuilder + 0x584);
    if (allocStatus == 0) {
      fogDstReg = *(undefined4 *)(programBuilder + 0x588);
      allocStatus = ((int (*)())ffvpAllocTempRegister)(programBuilder,2,fogTemp);
      if (allocStatus == 0) {
        glCtxCopy = *(int *)(programBuilder + 0x3d4);
        stateBlock = *(int *)(*(int *)(glCtxCopy + 4) + 0x10);
        if ((*(short *)(((unsigned char *)0x00002e06) + stateBlock) == -0x7bae) &&
           (*(short *)(((unsigned char *)0x00002e08) + stateBlock) == -0x7aa5)) {
          (**(code **)(((unsigned char *)0x000012e4) + glCtxCopy))
                    (programBuilder,dstFile,fogTempReg,fogTempMask,fogCoordFile,fogCoordReg,&DAT_001dbd74,&DAT_001fa5e8,fogCoordFile,fogCoordReg,&DAT_001dbd74,&DAT_001fa5e8);
        }
        else {
          (**(code **)(((unsigned char *)0x000012ec) + glCtxCopy))
                    (programBuilder,dstFile,fogTempReg,fogTempMask,fogCoordFile,fogCoordReg,fogCoordSelect,&DAT_001fa5e8,fogCoordFile,fogCoordReg,fogCoordSelect,&DAT_001fa5e8);
        }
        srcTempFile = **(undefined4 **)(programBuilder + 0x3ec);
        emit3Src1File = *(int *)((int)*(int *)((int)programBuilder + 1004) + 0);
        emit3Src1Select = &fogTempSelect;
        (**(code **)(((unsigned char *)0x000012ec) + glCtx))
                  (programBuilder,dstFile,fogTempReg,fogTempMask,constFile,fogParamConstReg,&DAT_001dbcf4,&DAT_001fa5e8,emit3Src1File,fogTempReg,emit3Src1Select,&DAT_001fa5e8);
        if (*(int *)(programBuilder + 0x3d8) == 0) {
          outputMask = (undefined4 *)(programBuilder + 0x58c);
          if (-1 < *(int *)(glCtx + 0x44)) {
            fogDstReg = *(undefined4 *)(programBuilder + 0x70);
            outputMask = &DAT_001dbd44;
            dstFile = *(undefined4 *)(*(int *)(programBuilder + 0x3f0) + 0x18);
          }
        }
        else {
          fogDstReg = *(undefined4 *)(programBuilder + 0x70);
          outputMask = &DAT_001dbd04;
          dstFile = *(undefined4 *)(*(int *)(programBuilder + 0x3f0) + 0x18);
        }
        (**(code **)(((unsigned char *)0x00001320) + glCtx))
                  (programBuilder,dstFile,fogDstReg,outputMask,srcTempFile,fogTempReg,fogTempSelect,&DAT_001fa5e8);
        ((int (*)())ffvpFreeTempRegister)(programBuilder,fogTemp);
        return 0;
      }
    }
    status = 7;
  }
  return status;
}

/* ffvpCreateBuilder @ 0x92bf0 (328 bytes) */
int ffvpCreateBuilder(glCtx, programMode, needsInvW)
  int glCtx;
  uint programMode;
  undefined4 needsInvW;
{
  int builder;
  
  builder = 0;
  if (programMode < 3) {
    builder = (**(code **)(glCtx + 0xc))(0x1998);
    *(int *)(builder + 0x3d4) = glCtx;
    _memset(builder,0xffffffff,0x68);
    _memset(builder + 0x68,0xffffffff,0x3c);
    _memset(builder + 0xa4,0xffffffff,0x324);
    *(uint *)(builder + 0x3d8) = programMode;
    *(undefined4 *)(builder + 0x3e0) = 0;
    *(undefined4 *)(builder + 0x3c8) = 0;
    *(undefined4 *)(builder + 0x3cc) = 0;
    *(undefined4 *)(builder + 0x3d0) = 0;
    *(undefined4 *)(builder + 0x3e4) = *(undefined4 *)(&DAT_001dbeac + programMode * 4);
    *(undefined4 *)(builder + 1000) = *(undefined4 *)(&DAT_001dbea4 + programMode * 4);
    *(undefined **)(builder + 0x3ec) = (PTR_DAT_001dbe84)[programMode];
    *(undefined **)(builder + 0x3f0) = (PTR_DAT_001dbe3c)[programMode];
    _memset(builder + 0x3f4,0xffffffff,0x2d0);
    _memset(builder + 0x6c4,0,0x80);
    *(undefined1 *)(builder + 0x744) = (undefined1)needsInvW;
    *(code **)(builder + 0x748) = ffvpAllocTempRegister;
    *(code **)(builder + 0x74c) = ffvpFreeTempRegister;
    if (*(code **)(((unsigned char *)0x000012d4) + glCtx) != (code *)0x0) {
      (**(code **)(((unsigned char *)0x000012d4) + glCtx))(glCtx,builder);
    }
  }
  return builder;
}

/* ffvpEmitPositionPassThrough @ 0x92d40 (340 bytes) */
int ffvpEmitPositionPassThrough(programBuilder, copyEnabled, copyOutIndex)
  int *programBuilder;
  int copyEnabled;
  uint copyOutIndex;
{
  int glCtx;
  undefined4 inputFile;
  int positionInputReg;
  
  if (programBuilder == (int *)0x0) {
    return 1;
  }
  if ((programBuilder[0x1a] != -1) && (positionInputReg = *programBuilder, positionInputReg != -1)) {
    if (copyEnabled != 0) {
      if (7 < copyOutIndex) {
        return 3;
      }
      if (programBuilder[copyOutIndex + 0x21] == -1) {
        return 2;
      }
    }
    glCtx = programBuilder[0xf5];
    inputFile = *(undefined4 *)(programBuilder[0xfb] + 4);
    (**(code **)(((unsigned char *)0x000012e8) + glCtx))
              (programBuilder,*(undefined4 *)(programBuilder[0xfc] + 8),programBuilder[0x1a],&DAT_001dbd24,inputFile,positionInputReg,
               &DAT_001dbd14,&DAT_001fa5e8);
    if (((*(char *)(programBuilder + 0x1d1) == '\0') || (programBuilder[0x1a8] != -1)) ||
       (((int (*)())ffvpEmitInverseW)(programBuilder,inputFile,positionInputReg), programBuilder[0x1a8] != -1)) {
      if (copyEnabled != 0) {
        (**(code **)(((unsigned char *)0x000012e8) + glCtx))
                  (programBuilder,*(undefined4 *)(programBuilder[0xfc] + 0x14),programBuilder[copyOutIndex + 0x21],
                   &DAT_001dbd24,inputFile,positionInputReg,&DAT_001dbd14,&DAT_001fa5e8);
      }
      return 0;
    }
  }
  return 2;
}

/* ffvpEmitColorPassThrough @ 0x92ea0 (324 bytes) */
int ffvpEmitColorPassThrough(programBuilder, colorKind, inputAttrib, sideIndex)
  int programBuilder;
  int colorKind;
  int inputAttrib;
  uint sideIndex;
{
  int programMode;
  undefined4 outFile;
  int outColorReg;
  undefined4 *maskPtr;
  int inColorReg;
  int glCtx;
  
  if (programBuilder == 0) {
    return 1;
  }
  if (colorKind == 3) {
    if (1 < sideIndex) {
      return 3;
    }
    outColorReg = *(int *)(sideIndex * 4 + programBuilder + 0x74);
    if ((outColorReg == -1) || (inColorReg = *(int *)(inputAttrib * 4 + programBuilder + 0xc), inColorReg == -1)) {
      return 2;
    }
    programMode = *(int *)(programBuilder + 0x3d8);
    glCtx = *(int *)(programBuilder + 0x3d4);
    outFile = *(undefined4 *)(*(int *)(programBuilder + 0x3f0) + 0xc);
  }
  else {
    if (1 < sideIndex) {
      return 3;
    }
    outColorReg = *(int *)(sideIndex * 4 + programBuilder + 0x7c);
    if (outColorReg == -1) {
      return 2;
    }
    inColorReg = *(int *)(inputAttrib * 4 + programBuilder + 0xc);
    if (inColorReg == -1) {
      return 2;
    }
    programMode = *(int *)(programBuilder + 0x3d8);
    glCtx = *(int *)(programBuilder + 0x3d4);
    outFile = *(undefined4 *)(*(int *)(programBuilder + 0x3f0) + 0x10);
  }
  if ((programMode == 0) && (outColorReg == *(int *)(programBuilder + 0x70))) {
    maskPtr = &DAT_001dbd84;
  }
  else {
    maskPtr = &DAT_001dbd24;
  }
  (**(code **)(((unsigned char *)0x000012e8) + glCtx))
            (programBuilder,outFile,outColorReg,maskPtr,*(undefined4 *)(*(int *)(programBuilder + 0x3ec) + 4),inColorReg,
             &DAT_001dbd14,&DAT_001fa5e8);
  return 0;
}

/* ffvpEmitTexCoordPassThrough @ 0x93000 (288 bytes) */
int ffvpEmitTexCoordPassThrough(programBuilder, texUnit, useXyz1Select, texUnitAlias, texMatrixEnabled, texMatrixUnit, texGenModes)
  int programBuilder;
  uint texUnit;
  undefined4 useXyz1Select;
  undefined4 texUnitAlias;
  undefined4 texMatrixEnabled;
  undefined4 texMatrixUnit;
  undefined4 texGenModes;
{
  bool noInvW;
  int texInputReg;
  undefined4 outFile;
  int texOutReg;
  undefined4 inputFile;
  
  if (programBuilder == 0) {
    return 1;
  }
  if (7 < texUnit) {
    return 3;
  }
  texInputReg = texUnit * 4 + programBuilder;
  texOutReg = *(int *)(texInputReg + 0x84);
  if (((texOutReg != -1) && (texInputReg = *(int *)(texInputReg + 0x2c), texInputReg != -1)) &&
     ((noInvW = *(char *)(programBuilder + 0x744) == '\0', noInvW || (*(int *)(programBuilder + 0xa4) != -1)))) {
    outFile = *(undefined4 *)(*(int *)(programBuilder + 0x3f0) + 0x14);
    inputFile = *(undefined4 *)(*(int *)(programBuilder + 0x3ec) + 4);
    if (noInvW) {
      (**(code **)(((unsigned char *)0x000012e8) + *(int *)(programBuilder + 0x3d4)))
                (programBuilder,outFile,texOutReg,&DAT_001dbd24,inputFile,texInputReg,&DAT_001dbd14,&DAT_001fa5e8);
      return 0;
    }
    if (*(int *)(programBuilder + 0x6a0) != -1) {
      (**(code **)(((unsigned char *)0x000012ec) + *(int *)(programBuilder + 0x3d4)))
                (programBuilder,outFile,texOutReg,&DAT_001dbd24,inputFile,texInputReg,&DAT_001dbd14,&DAT_001fa5e8,**(int **)(programBuilder + 0x3ec),*(int *)(programBuilder + 0x6a0),(int)programBuilder + 1716,&DAT_001fa5e8);
      return 0;
    }
  }
  return 2;
}

/* ffvpEmitPointSizePassThrough @ 0x93130 (168 bytes) */
int ffvpEmitPointSizePassThrough(programBuilder)
  int programBuilder;
{
  undefined4 status;
  
  status = 1;
  if (programBuilder != 0) {
    if ((*(int *)(programBuilder + 0x6c) == -1) || (*(int *)(programBuilder + 0x4c) == -1)) {
      status = 2;
    }
    else {
      (**(code **)(((unsigned char *)0x000012e8) + *(int *)(programBuilder + 0x3d4)))
                (programBuilder,*(undefined4 *)(*(int *)(programBuilder + 0x3f0) + 0x1c),*(int *)(programBuilder + 0x6c),
                 &DAT_001dbd24,*(undefined4 *)(*(int *)(programBuilder + 0x3ec) + 4),
                 *(int *)(programBuilder + 0x4c),&DAT_001fa5f8,&DAT_001fa5e8);
      status = 0;
    }
  }
  return status;
}

/* ffvpEmitFogPassThrough @ 0x931e0 (404 bytes) */
int ffvpEmitFogPassThrough(programBuilder)
  int programBuilder;
{
  int fogCoordComponents;
  int fogOutReg;
  undefined4 *fogMask;
  undefined4 status;
  undefined4 *fogSelect;
  
  status = 1;
  if (programBuilder != 0) {
    fogOutReg = *(int *)(programBuilder + 0x70);
    if ((fogOutReg == -1) || (*(int *)(programBuilder + 0x50) == -1)) {
      status = 2;
    }
    else if ((*(uint *)(programBuilder + 0x54) < 4) &&
            ((((*(int *)(programBuilder + 0x3d8) != 0 || (fogOutReg == *(int *)(programBuilder + 0x74))) ||
              (fogOutReg == *(int *)(programBuilder + 0x78))) ||
             ((fogOutReg == *(int *)(programBuilder + 0x7c) || (fogOutReg == *(int *)(programBuilder + 0x80))))))) {
      status = 0;
      *(undefined1 *)(*(int *)(programBuilder + 0x3d4) + 0x12e) = 1;
      if (-1 < *(int *)(*(int *)(programBuilder + 0x3d4) + 0x44)) {
        fogCoordComponents = *(int *)(programBuilder + 0x54);
        if (fogCoordComponents == 1) {
          fogSelect = &DAT_001dbce4;
        }
        else if (fogCoordComponents == 0) {
          fogSelect = &DAT_001fa5f8;
        }
        else if (fogCoordComponents == 2) {
          fogSelect = &DAT_001dbcf4;
        }
        else if (fogCoordComponents == 3) {
          fogSelect = &DAT_001dbcd4;
        }
        else {
          fogSelect = &DAT_001dbd14;
        }
        if (*(int *)(programBuilder + 0x3d8) == 0) {
          fogMask = &DAT_001dbd44;
        }
        else {
          fogMask = &DAT_001dbd04;
        }
        (**(code **)(((unsigned char *)0x000012e8) + *(int *)(programBuilder + 0x3d4)))
                  (programBuilder,*(undefined4 *)(*(int *)(programBuilder + 0x3f0) + 0x18),
                   *(undefined4 *)(programBuilder + 0x70),fogMask,
                   *(undefined4 *)(*(int *)(programBuilder + 0x3ec) + 4),*(undefined4 *)(programBuilder + 0x50),
                   fogSelect,&DAT_001fa5e8);
        status = 0;
      }
    }
    else {
      status = 3;
    }
  }
  return status;
}

/* ffvpEmitVectorLength @ 0x93390 (352 bytes) */
int ffvpEmitVectorLength(programBuilder)
  int programBuilder;
{
  undefined4 srcTempFile;
  undefined4 status;
  int allocStatus;
  int glCtx;
  undefined4 dstTempFile;
  undefined4 srcReg;
  undefined4 inputFile;
  undefined1 lenTemp [4];
  undefined4 lenTempReg;
  int emit2Src1File;
  
  status = 1;
  if ((programBuilder != 0) && (status = 2, *(int *)(programBuilder + 8) != -1)) {
    glCtx = *(int *)(programBuilder + 0x3d4);
    allocStatus = ((int (*)())ffvpAllocTempRegister)(programBuilder,0,lenTemp);
    status = 7;
    if (allocStatus == 0) {
      srcReg = *(undefined4 *)(programBuilder + 8);
      inputFile = (*(undefined4 **)(programBuilder + 0x3ec))[1];
      dstTempFile = **(undefined4 **)(programBuilder + 0x3f0);
      srcTempFile = **(undefined4 **)(programBuilder + 0x3ec);
      (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                (programBuilder,dstTempFile,lenTempReg,&DAT_001dbd24,inputFile,srcReg,&DAT_001dbdb4,&DAT_001fa5e8,inputFile,srcReg,&DAT_001dbdb4,&DAT_001fa5e8);
      emit2Src1File = *(int *)((int)*(int *)((int)programBuilder + 1004) + 0);
      (**(code **)(((unsigned char *)0x000012ec) + glCtx))
                (programBuilder,dstTempFile,lenTempReg,&DAT_001dbd24,inputFile,srcReg,&DAT_001dbd14,&DAT_001fa5e8,emit2Src1File,lenTempReg,&DAT_001dbd14,&DAT_001fa5e8);
      (**(code **)(((unsigned char *)0x00001310) + glCtx))
                (programBuilder,*(undefined4 *)(*(int *)(programBuilder + 0x3f0) + 4),0,&DAT_001dbd24,srcTempFile,
                 lenTempReg,&DAT_001dbd14,&DAT_001fa5e8);
      ((int (*)())ffvpFreeTempRegister)(programBuilder,lenTemp);
      status = 0;
    }
  }
  return status;
}


/* issue: auto-generated aliases bridging data.s/code.s references (written
 * without a leading underscore, matching the raw stock-binary symbol name)
 * against the real compiled C symbols (gcc adds one underscore automatically).
 * Needed because ld64 (required for this PPC binary's size - stock ld breaks on
 * large PPC links) does not silently reconcile this the way stock ld did. */
asm(".globl FUN_0008fb70");
asm(".set FUN_0008fb70, _gldFlushProgramStateForDraw");
asm(".globl ffvpComputeOutputMasks");
asm(".set ffvpComputeOutputMasks, _ffvpComputeOutputMasks");
asm(".globl gldValidateState");
asm(".set gldValidateState, _gldValidateState");
