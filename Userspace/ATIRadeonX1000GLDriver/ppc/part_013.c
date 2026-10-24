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
  bool bVar1;
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
  float local_28;
  float local_24;
  float local_20;
  
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
            bVar1 = parser[5] != 0x11;
            if (!bVar1) {
              arbNextToken(parser);
            }
            binding[4] = 3;
LAB_0008a838:
            if (bVar1) goto LAB_0008a960;
          }
          else {
            if (tokenValue == 0x2b) {
              arbNextToken(parser);
              bVar1 = parser[5] != 0x11;
              if (!bVar1) {
                arbNextToken(parser);
              }
              binding[4] = 2;
              goto LAB_0008a838;
            }
            if (tokenValue == 0xf) {
              arbNextToken(parser);
              bVar1 = parser[5] != 0x11;
              if (!bVar1) {
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
    local_28 = (float)constantValue;
    local_24 = local_28;
    local_20 = local_28;
    stateKind = arbInternConstant(parser,&local_28);
    binding[3] = stateKind;
    return;
  }
  if ((tokenBit & 0x800000) == 0) goto LAB_000898c0;
  arbNextToken(parser);
  local_20 = 0.0;
  local_24 = 0.0;
  constantValue = (double)((double (*)())arbParseFloatConstant)(parser);
  local_28 = (float)constantValue;
  if (parser[5] == 0x13) {
    arbNextToken(parser);
    constantValue = (double)((double (*)())arbParseFloatConstant)(parser);
    local_24 = (float)constantValue;
    if (parser[5] == 0x13) {
      arbNextToken(parser);
      constantValue = (double)((double (*)())arbParseFloatConstant)(parser);
      local_20 = (float)constantValue;
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
  stateKind = arbInternConstant(parser,&local_28);
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
int arbValidateProgram(callbacks, program, param_3, param_4)
  int callbacks;
  undefined1 *program;
  int *param_3;
  undefined4 param_4;
{
  bool bVar1;
  int iVar2;
  undefined1 *puVar3;
  int *piVar4;
  byte bVar8;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int *workArea;
  undefined4 uVar10;
  int iVar11;
  int *a2;
  int *in_r7;
  uint *in_r8;
  int iVar12;
  int *piVar13;
  uint uVar14;
  int *piVar15;
  int iVar16;
  undefined *puVar17;
  uint uVar18;
  uint uVar19;
  uint *puVar20;
  int *piVar21;
  int iVar22;
  int local_d8 [16];
  int *local_98;
  int local_94;
  int local_90;
  int *local_8c;
  int *local_88;
  uint local_80;
  int *local_7c;
  uint local_78;
  int *local_74;
  int *local_70;
  int *local_6c;
  int *local_68;
  int *local_64;
  int local_60;
  int *local_5c;
  
  workArea = (int *)(**(code **)(callbacks + 0xc))(0x24a30,program,param_3,param_4);
  piVar15 = (int *)0x0;
  program[0x54] = 0;
  local_80 = 0;
  local_7c = (int *)0x0;
  local_78 = 0;
  local_74 = (int *)0x0;
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
    iVar12 = 0;
    puVar3 = program;
    do {
      *(undefined4 *)(puVar3 + 0x14) = 0;
      iVar12 = iVar12 + 1;
      puVar3 = puVar3 + 4;
    } while (iVar12 < (int)(uint)(byte)((unsigned char *)0x000013b1)[callbacks]);
  }
  if (0 < *(int *)(((unsigned char *)0x000011d4) + callbacks)) {
    iVar12 = 0;
    do {
      *(undefined1 *)(*(int *)(program + 0x94) + iVar12) = 0;
      iVar12 = iVar12 + 1;
    } while (iVar12 < *(int *)(((unsigned char *)0x000011d4) + callbacks));
  }
  iVar12 = (**(code **)(callbacks + 0xc))((undefined *)((int)param_3 + 1));
  if (iVar12 == 0) {
    _free(workArea);
    return;
  }
  a2 = param_3;
  _memcpy(iVar12,param_4,param_3);
  *(undefined1 *)(iVar12 + (int)param_3) = 0;
  workArea[3] = iVar12;
  *workArea = callbacks;
  workArea[1] = iVar12;
  workArea[2] = iVar12;
  workArea[4] = (int)(iVar12 + (int)param_3);
  workArea[0xb] = -1;
  workArea[10] = -1;
  workArea[9] = 1;
  piVar13 = (int *)((int)((unsigned char *)0x4) + 3);
  iVar12 = 7;
  workArea[0xc] = (int)"";
  piVar4 = workArea;
  do {
    *(undefined1 *)(piVar4 + 0xd) = 0;
    piVar4 = (int *)((int)piVar4 + 1);
    iVar12 = iVar12 + -1;
  } while (iVar12 != 0);
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
  iVar12 = ((int (*)())arbParseProgramText)(workArea);
  if (iVar12 != 0) {
    iVar12 = *workArea;
    bVar8 = *(char *)(workArea + 0xd) == '\x01';
    if (*(char *)((int)workArea + 0x35) == '\x01') {
      bVar8 = bVar8 + 1;
    }
    if (*(char *)((int)workArea + 0x36) == '\x01') {
      bVar8 = bVar8 + 1;
    }
    if (bVar8 < 2) {
      piVar13 = (int *)(uint)(bVar8 == 1);
      uVar5 = *(byte *)((int)workArea + 0x37) ^ 1;
      bVar8 = uVar5 == 0;
      piVar4 = (int *)-uVar5;
      if (*(char *)(workArea + 0xe) == '\x01') {
        bVar8 = bVar8 + 1;
      }
      local_98 = piVar13;
      if (bVar8 < 2) {
LAB_0008c88c:
        piVar21 = (int *)workArea[0xf];
        local_94 = 0;
        do {
          if (piVar21 != (int *)0x0) {
            piVar13 = workArea + 0x914a;
            local_6c = (int *)&DAT_001ac5a4;
            bVar1 = local_98 == (int *)0x0;
            local_8c = local_98;
            piVar15 = workArea + 0x928a;
            local_88 = (int *)&DAT_001ac5a4;
            local_68 = piVar13;
            local_64 = piVar15;
            do {
              iVar2 = piVar21[6];
              if (iVar2 == 1) {
                a2 = workArea + 0x9149;
                in_r8 = (uint *)(piVar21 + 6);
                in_r7 = local_88 + -0x1a48;
                piVar13 = local_8c;
                piVar15 = local_88;
                iVar2 = ((int (*)())arbfpInternParameter)(workArea,workArea + 0x9117,a2,
                                     *(int *)(((unsigned char *)0x000011ec) + iVar12) - (int)local_8c,in_r7,in_r8);
                if (iVar2 < 0) goto LAB_0008d2d0;
              }
              else if (iVar2 == 0) {
                if (*(int *)(((unsigned char *)0x000011dc) + iVar12) - (int)local_8c <= workArea[0x928b]) {
                  piVar13 = local_8c;
                  arbSetError(workArea,"too many temporaries");
                  goto LAB_0008d2d0;
                }
                piVar21[7] = workArea[0x928b];
                workArea[0x928b] = workArea[0x928b] + 1;
                piVar13 = local_8c;
              }
              else if (iVar2 == 2) {
                iVar2 = piVar21[3];
                local_90 = 1;
                if ((iVar2 == 0) || (local_90 = iVar2, 0 < iVar2)) {
                  iVar2 = 0;
                  iVar16 = 0;
                  do {
                    if (bVar1) {
                      iVar11 = 0;
                    }
                    else {
                      iVar11 = 2;
                    }
                    in_r8 = (uint *)(iVar16 + piVar21[5]);
                    in_r7 = local_6c + -0x1a4f;
                    a2 = local_64;
                    piVar15 = local_6c;
                    iVar11 = ((int (*)())arbfpInternParameter)(workArea,local_68,local_64,
                                          *(int *)(((unsigned char *)0x000011e4) + iVar12) - iVar11,in_r7,in_r8);
                    if (iVar11 < 0) goto LAB_0008d2d0;
                    iVar2 = iVar2 + 1;
                    iVar16 = iVar16 + 0x14;
                  } while (local_90 != iVar2);
                }
              }
              else if (iVar2 != 3) {
                arbErrorInternal(workArea);
                goto LAB_0008d2d0;
              }
              piVar21 = (int *)*piVar21;
              piVar4 = piVar15;
            } while (piVar21 != (int *)0x0);
          }
          local_94 = local_94 + 1;
          if (1 < local_94) {
            iVar16 = workArea[0x9014];
            piVar13 = *(int **)(((unsigned char *)0x000011d4) + iVar12);
            iVar2 = iVar16 + workArea[0x9015];
            if (iVar2 <= (int)piVar13) {
              bVar1 = local_98 == (int *)0x0;
              if (!bVar1) {
                if (*(char *)(workArea + 0xd) == '\x01') {
                  if (iVar16 <= *(int *)(((unsigned char *)0x00001204) + iVar12) + -3) {
                    if ((int)((int)piVar13 + -3) < iVar2) goto LAB_0008cad4;
                    goto LAB_0008ca70;
                  }
LAB_0008cab4:
                  arbSetError(workArea,"too many ALU instructions");
                  piVar15 = piVar4;
                  goto LAB_0008d2d0;
                }
LAB_0008ca70:
                if (*(char *)((int)workArea + 0x35) == '\x01') {
                  if (*(int *)(((unsigned char *)0x00001204) + iVar12) + -4 < iVar16) goto LAB_0008cab4;
                  if ((int)(piVar13 + -1) < iVar2) goto LAB_0008cad4;
                }
                if (*(char *)((int)workArea + 0x36) == '\x01') {
                  if (*(int *)(((unsigned char *)0x00001204) + iVar12) + -2 < iVar16) goto LAB_0008cab4;
                  if ((int)((int)piVar13 + -2) < iVar2) goto LAB_0008cad4;
                }
              }
              uVar5 = (uint)(byte)((unsigned char *)0x000013b1)[iVar12];
              if (uVar5 != 0) {
                piVar15 = local_d8;
                do {
                  *piVar15 = 0;
                  piVar15 = piVar15 + 1;
                  uVar5 = uVar5 - 1;
                } while (uVar5 != 0);
              }
              if (iVar2 < 1) {
                iVar11 = 0;
                iVar22 = 1;
              }
              else {
                piVar15 = local_d8;
                uVar5 = 0;
                uVar14 = 0;
                in_r7 = (int *)0x0;
                in_r8 = (uint *)0x0;
                iVar11 = 0;
                iVar22 = 1;
                a2 = (int *)0x0;
                iVar16 = iVar2;
                do {
                  uVar18 = *(uint *)((int)a2 + (int)(workArea + 0x14));
                  puVar17 = (undefined *)((int)a2 + (int)(workArea + 0x14));
                  local_70 = piVar15;
                  if (uVar18 < 0x20) {
                    if ((0x1c < uVar18) || (uVar18 == 0xb)) goto LAB_0008cb94;
LAB_0008cb70:
                    if (*(int *)(*(int *)(puVar17 + 0xc) + 0x18) == 0) {
                      uVar19 = *(uint *)(*(int *)(puVar17 + 0xc) + 0x1c);
                      uVar6 = uVar19 - 0x20;
                      if ((int)uVar6 < 0) {
                        uVar6 = 0;
                        uVar19 = 1 << (uVar19 & 0x3f);
                      }
                      else {
                        uVar19 = 0;
                        uVar6 = 1 << (uVar6 & 0x3f);
                      }
                      in_r7 = (int *)((uint)in_r7 | uVar6);
                      in_r8 = (uint *)((uint)in_r8 | uVar19);
                    }
                    iVar7 = *(int *)(puVar17 + 0x28);
                    if ((iVar7 != 0) && (*(int *)(iVar7 + 0x18) == 0)) {
                      uVar19 = *(uint *)(iVar7 + 0x1c) - 0x20;
                      if ((int)uVar19 < 0) {
                        piVar4 = (int *)((int)((unsigned char *)0x0) + 1);
                        uVar19 = 0;
                        uVar6 = 1 << (*(uint *)(iVar7 + 0x1c) & 0x3f);
                      }
                      else {
                        uVar6 = 0;
                        uVar19 = 1 << (uVar19 & 0x3f);
                      }
                      in_r7 = (int *)((uint)in_r7 | uVar19);
                      in_r8 = (uint *)((uint)in_r8 | uVar6);
                    }
                    iVar7 = *(int *)(puVar17 + 0x44);
                    if ((iVar7 != 0) && (*(int *)(iVar7 + 0x18) == 0)) {
                      uVar19 = *(uint *)(iVar7 + 0x1c) - 0x20;
                      if ((int)uVar19 < 0) {
                        uVar19 = 0;
                        uVar6 = 1 << (*(uint *)(iVar7 + 0x1c) & 0x3f);
                      }
                      else {
                        uVar6 = 0;
                        uVar19 = 1 << (uVar19 & 0x3f);
                      }
                      in_r7 = (int *)((uint)in_r7 | uVar19);
                      in_r8 = (uint *)((uint)in_r8 | uVar6);
                    }
                    piVar13 = *(int **)(puVar17 + 4);
                    if (piVar13[6] == 0) {
                      uVar19 = piVar13[7] - 0x20;
                      if ((int)uVar19 < 0) {
                        local_80 = 0;
                        local_7c = (int *)(1 << (piVar13[7] & 0x3fU));
                      }
                      else {
                        local_7c = (int *)0x0;
                        local_80 = 1 << (uVar19 & 0x3f);
                      }
                      in_r7 = (int *)((uint)in_r7 | local_80);
                      in_r8 = (uint *)((uint)in_r8 | (uint)local_7c);
                      piVar4 = local_7c;
                    }
                    if (uVar18 == 0xb) goto LAB_0008ce38;
LAB_0008cddc:
                    if (piVar13[6] == 0) {
                      uVar18 = piVar13[7] - 0x20;
                      if ((int)uVar18 < 0) {
                        local_78 = 0;
                        piVar4 = (int *)(1 << (piVar13[7] & 0x3fU));
                        local_74 = piVar4;
                      }
                      else {
                        local_78 = 1 << (uVar18 & 0x3f);
                        local_74 = (int *)0x0;
                      }
                      uVar5 = uVar5 | local_78;
                      uVar14 = uVar14 | (uint)local_74;
                      piVar13 = local_74;
                    }
                  }
                  else {
                    if (2 < uVar18 - 0x3d) goto LAB_0008cb70;
LAB_0008cb94:
                    piVar13 = *(int **)(*(int *)(puVar17 + 0xc) + 0x1c);
                    if (*(int *)(*(int *)(puVar17 + 0xc) + 0x18) == 0) {
                      if ((int)(piVar13 + -8) < 0) {
                        uVar19 = (uVar5 << 1) << (0x1fU - (int)piVar13 & 0x3f) |
                                 uVar14 >> ((uint)piVar13 & 0x3f);
                      }
                      else {
                        uVar19 = uVar5 >> ((uint)(piVar13 + -8) & 0x3f);
                      }
                      piVar13 = (int *)(uVar19 & 1);
                      if (piVar13 == (int *)0x0) goto LAB_0008cbd4;
LAB_0008cc20:
                      iVar22 = iVar22 + 1;
                      if (uVar18 != 0xb) {
                        uVar5 = 0;
                        uVar14 = 0;
                        in_r7 = (int *)0x0;
                        in_r8 = (uint *)0x0;
LAB_0008cc50:
                        piVar13 = (int *)(*(int *)(puVar17 + 0x40) * 4);
                        piVar4 = piVar15;
                        if (*(int *)((int)piVar13 + (int)piVar15) == 0) {
                          *(int *)((int)piVar13 + (int)piVar15) = *(int *)(puVar17 + 0x5c);
                          piVar13 = *(int **)(puVar17 + 4);
                        }
                        else {
                          if (*(int *)((int)piVar13 + (int)piVar15) != *(int *)(puVar17 + 0x5c)) {
                            arbSetError(workArea,"multiple targets on texture context");
                            goto LAB_0008d2d0;
                          }
                          piVar13 = *(int **)(puVar17 + 4);
                        }
                        goto LAB_0008cddc;
                      }
                      uVar5 = 0;
                      uVar14 = 0;
                      iVar11 = 1;
                      in_r7 = (int *)0x0;
                      in_r8 = (uint *)0x0;
                    }
                    else {
LAB_0008cbd4:
                      if (uVar18 != 0xb) {
                        if (*(int *)(*(int *)(puVar17 + 4) + 0x18) == 0) {
                          piVar13 = *(int **)(*(int *)(puVar17 + 4) + 0x1c);
                          if ((int)(piVar13 + -8) < 0) {
                            uVar19 = ((int)in_r7 << 1) << (0x1fU - (int)piVar13 & 0x3f) |
                                     (uint)in_r8 >> ((uint)piVar13 & 0x3f);
                          }
                          else {
                            uVar19 = (uint)in_r7 >> ((uint)(piVar13 + -8) & 0x3f);
                          }
                          piVar4 = (int *)(uVar19 & 1);
                          if (piVar4 != (int *)0x0) goto LAB_0008cc20;
                        }
                        goto LAB_0008cc50;
                      }
                      iVar11 = 1;
                    }
                  }
LAB_0008ce38:
                  a2 = a2 + 0x18;
                  iVar16 = iVar16 + -1;
                } while (iVar16 != 0);
              }
              piVar15 = piVar4;
              if (*(int *)(((unsigned char *)0x0000120cU) + iVar12) < iVar22) {
                arbSetError(workArea,"too many indirections");
              }
              else {
                piVar13 = (int *)workArea[0x928a];
                local_60 = iVar11;
                iVar2 = (**(code **)(iVar12 + 0xc))
                                  (iVar2 * 0x70 + (int)(workArea[0x9149] + (int)piVar13) * 0x14 +
                                   workArea[0x9116] * 0x10 + 0x70,iVar11,a2,iVar2,in_r7,in_r8,piVar13)
                ;
                *(int *)(program + 0x60) = iVar2;
                if (iVar2 != 0) {
                  if (local_60 != 0) {
                    program[3] = 1;
                  }
                  if (*(char *)((int)workArea + 0x3a) == '\x01') {
                    program[5] = 1;
                  }
                  if (bVar1) {
                    *(int **)(program + 8) = local_98;
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
                  if (((unsigned char *)0x000013b1)[iVar12] != '\0') {
                    iVar2 = 0;
                    piVar13 = local_d8;
                    puVar3 = program;
                    do {
                      iVar16 = *piVar13;
                      iVar2 = iVar2 + 1;
                      piVar13 = piVar13 + 1;
                      *(int *)(puVar3 + 0x14) = iVar16;
                      puVar3 = puVar3 + 4;
                    } while (iVar2 < (int)(uint)(byte)((unsigned char *)0x000013b1)[iVar12]);
                  }
                  *(int *)(program + 100) = *(int *)(program + 0x60);
                  *(int *)(program + 0x68) = workArea[0x9014] + workArea[0x9015];
                  *(int *)(program + 0x6c) = workArea[0x9014];
                  *(int *)(program + 0x70) = workArea[0x9015];
                  iVar2 = (workArea[0x9014] + workArea[0x9015]) * 0x70 + *(int *)(program + 0x60) + 0x70
                  ;
                  *(int *)(program + 0x78) = iVar2;
                  *(int *)(program + 0x7c) = workArea[0x9149];
                  iVar12 = workArea[0x9149] * 0x14 + iVar2;
                  *(int *)(program + 0x80) = iVar12;
                  *(int *)(program + 0x84) = workArea[0x928a];
                  *(int *)(program + 0x8c) = workArea[0x928a] * 0x14 + iVar12;
                  *(int *)(program + 0x90) = workArea[0x9116];
                  iVar12 = workArea[0x928b];
                  *(int *)(program + 0x74) = iVar22;
                  iVar16 = 0;
                  *(int *)(program + 0x88) = iVar12;
                  _memcpy(iVar2,workArea + 0x9117,workArea[0x9149] * 0x14);
                  _memcpy(*(undefined4 *)(program + 0x80),workArea + 0x914a,workArea[0x928a] * 0x14);
                  _memcpy(*(undefined4 *)(program + 0x8c),workArea + 0x9016,workArea[0x9116] << 4);
                  if (0 < workArea[0x9014] + workArea[0x9015]) {
                    iVar16 = 0;
                    local_5c = workArea + 0x14;
                    iVar2 = 0;
                    iVar12 = 0;
                    do {
                      iVar11 = *(int *)(program + 100);
                      in_r7 = (int *)((int)local_5c + iVar12);
                      puVar20 = (uint *)(iVar2 + iVar11);
                      _memset(puVar20,0,0x70);
                      *(undefined4 *)(iVar2 + iVar11) = *(undefined4 *)((int)local_5c + iVar12);
                      iVar11 = in_r7[1];
                      *(undefined1 *)(iVar16 + *(int *)(program + 0x94)) = 0;
                      if (iVar11 != 0) {
                        uVar5 = *(uint *)(iVar11 + 0x1c);
                        puVar20[1] = *(uint *)(iVar11 + 0x18);
                        puVar20[2] = uVar5;
                        if (*(int *)(iVar11 + 0x18) == 3) {
                          if (*(int *)(iVar11 + 0x1c) == 1) {
                            program[4] = 1;
                          }
                          else if (*(int *)(iVar11 + 0x1c) == 0) {
                            *(char *)(iVar16 + *(int *)(program + 0x94)) =
                                 (char)*(undefined4 *)(iVar11 + 0x24);
                          }
                        }
                      }
                      iVar11 = 0;
                      puVar20[3] = in_r7[2];
                      in_r8 = puVar20;
                      do {
                        iVar22 = in_r7[3];
                        if (iVar22 == 0) {
                          uVar5 = *puVar20;
                          if ((0x1c < uVar5) &&
                             (((uVar5 < 0x20 || (uVar5 - 0x3d < 3)) &&
                              (in_r8[0xb] = in_r7[9], iVar11 == 1)))) {
                            *(uint *)(program + 0x10) =
                                 1 << (puVar20[0x13] & 0x3f) | *(uint *)(program + 0x10);
                          }
                        }
                        else {
                          if (*(int *)(iVar22 + 0xc) == 0) {
                            uVar5 = *(uint *)(iVar22 + 0x1c);
                            uVar14 = *(uint *)(iVar22 + 0x18);
                            in_r8[0xb] = 0;
                            in_r8[5] = uVar5;
                            in_r8[4] = uVar14;
                          }
                          else {
                            uVar5 = *(uint *)(in_r7[9] * 0x14 + *(int *)(iVar22 + 0x14));
                            piVar15 = *(int **)(in_r7[9] * 0x14 + *(int *)(iVar22 + 0x14) + 4);
                            in_r8[0xb] = 0;
                            in_r8[4] = uVar5;
                            in_r8[5] = (uint)piVar15;
                          }
                          if (in_r8[4] == 1) {
                            iVar7 = in_r8[5] * 0x14 + *(int *)(program + 0x78);
                            iVar22 = *(int *)(iVar7 + 8);
                            if (iVar22 == 1) {
                              if (*(int *)(iVar7 + 0xc) == 1) {
                                *program = 1;
                              }
                            }
                            else if (iVar22 == 2) {
                              *(uint *)(program + 0xc) =
                                   1 << (*(uint *)(iVar7 + 0xc) & 0x3f) | *(uint *)(program + 0xc);
                            }
                            else if (iVar22 == 3) {
                              program[1] = 1;
                            }
                            else if (iVar22 == 4) {
                              program[2] = 1;
                            }
                          }
                          uVar5 = in_r7[5];
                          uVar14 = in_r7[6];
                          uVar18 = in_r7[7];
                          in_r8[6] = in_r7[4];
                          in_r8[7] = uVar5;
                          in_r8[8] = uVar14;
                          in_r8[9] = uVar18;
                          *(undefined1 *)(in_r8 + 10) = *(undefined1 *)(in_r7 + 8);
                        }
                        bVar1 = iVar11 != 2;
                        in_r7 = in_r7 + 7;
                        in_r8 = in_r8 + 8;
                        iVar11 = iVar11 + 1;
                      } while (bVar1);
                      iVar16 = iVar16 + 1;
                      iVar12 = iVar12 + 0x60;
                      iVar2 = iVar2 + 0x70;
                    } while (iVar16 < workArea[0x9014] + workArea[0x9015]);
                  }
                  _memset(iVar16 * 0x70 + *(int *)(program + 100),0,0x70);
                  piVar13 = *(int **)(program + 100);
                  piVar13[iVar16 * 0x1c] = 0x41;
                  program[0x54] = 1;
                }
              }
              goto LAB_0008d2d0;
            }
LAB_0008cad4:
            arbSetError(workArea,"too many total instructions");
            piVar15 = piVar4;
            goto LAB_0008d2d0;
          }
          if (local_94 == 0) goto LAB_0008c88c;
          piVar21 = (int *)workArea[0x11];
        } while( true );
      }
      arbSetError(workArea,"more than one precision hint option");
      piVar15 = piVar4;
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
  iVar12 = _strlen(workArea[0xc]);
  uVar10 = (**(code **)(callbacks + 0xc))(iVar12 + 0xb);
  *(undefined4 *)(((unsigned char *)0x00001128) + callbacks) = uVar10;
  if ((uint)workArea[0xb] < 10000) {
    printf_LDBLStub_1a32d0(uVar10,"line %d: %s",workArea[0xb],workArea[0xc],in_r7,in_r8,piVar13,piVar15);
  }
  else {
    _strcpy(uVar10,workArea[0xc]);
  }
  if (workArea[1] != 0) {
    (**(code **)(callbacks + 0x18))(workArea[1]);
  }
  piVar15 = (int *)workArea[0xf];
  while (piVar15 != (int *)0x0) {
    if ((int *)piVar15[5] != piVar15 + 6) {
      (**(code **)(callbacks + 0x18))(piVar15[5]);
    }
    iVar12 = *piVar15;
    (**(code **)(callbacks + 0x18))(piVar15);
    piVar15 = (int *)iVar12;
  }
  piVar15 = (int *)workArea[0x11];
  while (piVar15 != (int *)0x0) {
    if ((int *)piVar15[5] != piVar15 + 6) {
      (**(code **)(callbacks + 0x18))(piVar15[5]);
    }
    iVar12 = *piVar15;
    (**(code **)(callbacks + 0x18))(piVar15);
    piVar15 = (int *)iVar12;
  }
  piVar15 = (int *)workArea[0x13];
  while (piVar15 != (int *)0x0) {
    iVar12 = *piVar15;
    (**(code **)(callbacks + 0x18))(piVar15);
    piVar15 = (int *)iVar12;
  }
                    
                    
  (**(code **)(callbacks + 0x18))(workArea);
  return;
}

/* arbfpUpdateStateForProgram @ 0x8d470 (1744 bytes) */
int arbfpUpdateStateForProgram(context, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int context;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  uint *puVar1;
  bool bVar2;
  uint uVar3;
  undefined1 uVar4;
  uint uVar5;
  uint uVar6;
  undefined *programState;
  char *programObject;
  byte bVar9;
  int loopIndex;
  uint dirtyFlags;
  uint uVar12;
  uint uVar13;
  char *pcVar14;
  uint uVar15;
  undefined *puVar16;
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
      puVar16 = programState;
      do {
        *(undefined4 *)(puVar16 + 0x5c) = 0;
        loopIndex = loopIndex + 1;
        puVar16 = puVar16 + 4;
      } while (loopIndex < (int)(uint)(byte)((unsigned char *)0x000013b1)[context]);
    }
    uVar12 = 0xffffffff;
  }
  else {
    uVar3 = *(uint *)(programObject + 8);
    ((unsigned char *)0x000011d3)[context] = (char)uVar3;
    uVar5 = *(uint *)(programObject + 0xc);
    *(uint *)(((unsigned char *)0x00001228) + context) = uVar5;
    uVar15 = (uint)(byte)((unsigned char *)0x000013b6)[context];
    uVar12 = uVar15 - 1;
    if (-1 < (int)uVar12) {
      do {
        if (((uVar3 & 0xff | uVar5) >> (uVar12 & 0x3f) & 1) != 0) goto LAB_0008d4f8;
        uVar12 = uVar12 - 1;
        uVar15 = uVar15 - 1;
      } while (uVar15 != 0);
    }
    uVar12 = 0xffffffff;
LAB_0008d4f8:
    uVar15 = (uint)(byte)((unsigned char *)0x000013b1)[context];
    if (uVar15 != 0) {
      loopIndex = 0;
      pcVar14 = programObject;
      puVar16 = programState;
      do {
        switch(*(undefined4 *)(pcVar14 + 0x10)) {
        case 0:
          *(undefined4 *)(puVar16 + 0x5c) = 0;
          uVar15 = (uint)(byte)((unsigned char *)0x000013b1)[context];
          break;
        case 1:
        case 6:
          *(undefined4 *)(puVar16 + 0x5c) = 0x10;
          uVar15 = (uint)(byte)((unsigned char *)0x000013b1)[context];
          break;
        case 2:
        case 7:
          *(undefined4 *)(puVar16 + 0x5c) = 8;
          uVar15 = (uint)(byte)((unsigned char *)0x000013b1)[context];
          break;
        case 3:
          *(undefined4 *)(puVar16 + 0x5c) = 2;
          uVar15 = (uint)(byte)((unsigned char *)0x000013b1)[context];
          break;
        case 4:
          *(undefined4 *)(puVar16 + 0x5c) = 1;
          uVar15 = (uint)(byte)((unsigned char *)0x000013b1)[context];
          break;
        case 5:
        case 8:
          *(undefined4 *)(puVar16 + 0x5c) = 4;
          uVar15 = (uint)(byte)((unsigned char *)0x000013b1)[context];
        }
        loopIndex = loopIndex + 1;
        pcVar14 = pcVar14 + 4;
        puVar16 = puVar16 + 4;
      } while (loopIndex < (int)uVar15);
    }
  }
  bVar2 = (dirtyFlags >> 0xd & 1) == 0;
  if ((programObject[4] == '\0') || (bVar2)) {
    dirtyFlags = *(uint *)(context + 0x44);
    if ((dirtyFlags & 0x200) != 0) {
      uVar15 = *(uint *)(context + 0x3c);
      dirtyFlags = dirtyFlags & 0xfffffdff;
      goto LAB_0008d6a4;
    }
  }
  else {
    dirtyFlags = *(uint *)(context + 0x44);
    if ((dirtyFlags & 0x200) == 0) {
      uVar15 = *(uint *)(context + 0x3c);
      dirtyFlags = dirtyFlags | 0x200;
LAB_0008d6a4:
      *(uint *)(context + 0x44) = dirtyFlags;
      *(undefined1 *)(context + 0x29) = 1;
      *(uint *)(context + 0x3c) = uVar15 | 1;
    }
  }
  if ((*programObject == '\0') || (bVar2)) {
    if ((dirtyFlags & 0x1000) != 0) {
      dirtyFlags = dirtyFlags & 0xffffefff;
      *(uint *)(context + 0x44) = dirtyFlags;
      *(undefined1 *)(context + 0x29) = 1;
      *(uint *)(context + 0x38) = *(uint *)(context + 0x38) | 0x1000;
    }
    if ((bVar2) && ((dirtyFlags & 0x4000) != 0)) goto joined_r0x0008d734;
    if ((dirtyFlags & 0x10000) != 0) {
      uVar15 = *(uint *)(context + 0x38);
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
      uVar15 = *(uint *)(context + 0x38);
      dirtyFlags = dirtyFlags | 0x10000;
LAB_0008d760:
      *(uint *)(context + 0x44) = dirtyFlags;
      *(undefined1 *)(context + 0x29) = 1;
      *(uint *)(context + 0x38) = uVar15 | 0x20;
    }
  }
  if ((programObject[3] == '\0') || (bVar2)) {
    if ((dirtyFlags & 0x100) != 0) {
      uVar15 = *(uint *)(context + 0x38);
      dirtyFlags = dirtyFlags & 0xfffffeff;
      goto LAB_0008d7b0;
    }
  }
  else if ((dirtyFlags & 0x100) == 0) {
    uVar15 = *(uint *)(context + 0x38);
    dirtyFlags = dirtyFlags | 0x100;
LAB_0008d7b0:
    *(uint *)(context + 0x44) = dirtyFlags;
    *(undefined1 *)(context + 0x2a) = 1;
    *(uint *)(context + 0x38) = uVar15 | 1;
    *(undefined1 *)(context + 0x29) = 1;
  }
  if ((programObject[1] == '\0') || (bVar2)) {
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
  if ((programObject[2] == '\0') || (bVar2)) {
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
    bVar9 = ((unsigned char *)0x000013b0)[context];
    uVar15 = (uint)bVar9;
    if (uVar15 == 0) {
      uVar5 = 0xffffffff;
      uVar13 = 0xffffffff;
    }
    else {
      uVar6 = 0;
      uVar5 = 0xffffffff;
      uVar3 = 0xffffffff;
      do {
        uVar13 = uVar3;
        if (((((int)(uint)(byte)((unsigned char *)0x000011d3)[context] >> (uVar6 & 0x3f) & 1U) == 0) &&
            (uVar13 = uVar6, uVar3 != 0xffffffff)) && (uVar13 = uVar3, uVar5 == 0xffffffff)) {
          uVar5 = uVar6;
        }
        uVar6 = uVar6 + 1;
        uVar15 = uVar15 - 1;
        uVar3 = uVar13;
      } while (uVar15 != 0);
    }
    if ((dirtyFlags & 0x800) == 0) {
      if ((dirtyFlags & 0x400) != 0) {
        if (uVar13 != 0xffffffff) {
          bVar9 = (byte)uVar13;
        }
        ((unsigned char *)0x000011d2)[context] = bVar9;
        if ((int)uVar13 <= (int)uVar12) goto LAB_0008d98c;
        dirtyFlags = *(uint *)(context + 0x44);
        uVar12 = uVar13;
      }
    }
    else {
      if (uVar13 != 0xffffffff) {
        bVar9 = (byte)uVar13;
      }
      ((unsigned char *)0x000011d1)[context] = bVar9;
      if ((int)uVar12 < (int)uVar13) {
        uVar12 = uVar13;
      }
      dirtyFlags = *(uint *)(context + 0x44);
      if ((dirtyFlags & 0x400) != 0) {
        uVar4 = (undefined1)uVar5;
        if (uVar5 == 0xffffffff) {
          uVar4 = ((unsigned char *)0x000013b0)[context];
        }
        ((unsigned char *)0x000011d2)[context] = uVar4;
        if ((int)uVar12 < (int)uVar5) {
          dirtyFlags = *(uint *)(context + 0x44);
          uVar12 = uVar5;
        }
        else {
LAB_0008d98c:
          dirtyFlags = *(uint *)(context + 0x44);
        }
      }
    }
  }
  if ((bVar2) && (((unsigned char *)0x00002e0a)[stateBlock] != '\0')) {
    if ((dirtyFlags & 0x1000000) == 0) {
      *(uint *)(context + 0x44) = dirtyFlags | 0x1000000;
      uVar12 = *(uint *)(context + 0x38);
      *(uint *)(context + 0x18a4) = *(uint *)(context + 0x18a4) | 1;
      *(undefined1 *)(context + 0x29) = 1;
      *(uint *)(context + 0x38) = uVar12 | 0x100;
      if ((((int)dirtyFlags < 0 || (dirtyFlags & 0x800000) != 0) || (dirtyFlags & 0x200000) != 0) ||
          (dirtyFlags & 0x10000) != 0) {
        *(uint *)(context + 0x38) = uVar12 | 0x120;
      }
    }
  }
  else {
    if ((dirtyFlags & 0x1000000) != 0) {
      uVar15 = dirtyFlags & 0xfeffffff;
      *(uint *)(context + 0x44) = uVar15;
      uVar3 = *(uint *)(context + 0x38);
      *(uint *)(context + 0x18a4) = *(uint *)(context + 0x18a4) & 0xfffffffe;
      *(undefined1 *)(context + 0x29) = 1;
      *(uint *)(context + 0x38) = uVar3 | 0x100;
      if ((((int)dirtyFlags < 0 || (uVar15 >> 0x17 & 1) != 0) || (uVar15 >> 0x15 & 1) != 0) ||
          (uVar15 >> 0x10 & 1) != 0) {
        *(uint *)(context + 0x38) = uVar3 | 0x120;
      }
    }
    if (!bVar2) {
      dirtyFlags = (uint)(byte)((unsigned char *)0x000013b1)[context];
      if (dirtyFlags != 0) {
        stateBlock = context;
        if ((dirtyFlags == 0) || (dirtyFlags == 0x80000000)) {
          dirtyFlags = 1;
        }
        do {
          uVar15 = *(uint *)(stateBlock + 0x48) & 0xffffffe0;
          *(uint *)(stateBlock + 0x48) = uVar15;
          puVar1 = (uint *)(programState + 0x5c);
          programState = programState + 4;
          *(uint *)(stateBlock + 0x48) = uVar15 | *puVar1;
          stateBlock = stateBlock + 4;
          dirtyFlags = dirtyFlags - 1;
        } while (dirtyFlags != 0);
      }
      if ((int)(uint)*(byte *)(context + 0x2b) <= (int)uVar12) {
        *(char *)(context + 0x2b) = (char)uVar12 + '\x01';
      }
      bVar9 = ((unsigned char *)0x000013b6)[context];
      dirtyFlags = *(uint *)(context + 0x3c);
      *(byte *)(context + 0x2e) = *(byte *)(context + 0x2e) | 3;
      *(uint *)(context + 0x38) = *(uint *)(context + 0x38) | 0x2200;
      *(undefined1 *)(context + 0x29) = 1;
      *(ushort *)(context + 0x34) = (short)(1 << (bVar9 & 0x3f)) - 1U | *(ushort *)(context + 0x34);
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
int arbfpBindProgram(context, programSlot, param_3, param_4, param_5, param_6, param_7, param_8)
  int context;
  int programSlot;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  undefined4 programObject;
  
  if (*(int *)(((unsigned char *)0x00001270) + context) != programSlot) {
    *(int *)(((unsigned char *)0x00001270) + context) = programSlot;
    programObject = *(undefined4 *)(programSlot * 0x18 + *(int *)(*(int *)(((unsigned char *)0x0000112c) + context) + 8) + 0x14)
    ;
    *(undefined4 *)(((unsigned char *)0x0000121c) + context) = programObject;
    ((int (*)())arbfpUpdateStateForProgram)(context,programSlot,param_3,param_4,param_5,param_6,programObject,param_8);
    ((unsigned char *)0x000011d0)[context] = 1;
  }
  return;
}

/* FUN_0008dc40 @ 0x8dc40 (12 bytes) */
int FUN_0008dc40(param_1)
  int param_1;
{
                    
                    
  (**(code **)(((unsigned char *)0x00001278) + param_1))();
  return;
}

/* arbfpProgramObjectInit @ 0x8dc50 (336 bytes) */
int arbfpProgramObjectInit(context, programObject)
  int context;
  undefined1 *programObject;
{
  int loopIndex;
  undefined1 *puVar1;
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
    puVar1 = programObject;
    do {
      *(undefined4 *)(puVar1 + 0x10) = 0;
      loopIndex = loopIndex + 1;
      puVar1 = puVar1 + 4;
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
  undefined1 *puVar2;
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
    puVar2 = programObject;
    do {
      *(undefined4 *)(puVar2 + 0x10) = 0;
      loopIndex2 = loopIndex2 + 1;
      puVar2 = puVar2 + 4;
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
  byte bVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int newProgram;
  int compareResult;
  undefined4 uVar6;
  undefined4 extraout_r4;
  undefined4 uVar7;
  uint uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined1 *puVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined1 *puVar14;
  int stateHolder;
  undefined1 *currentProgram;
  undefined4 uVar17;
  int compiledProgram;
  undefined4 uVar19;
  
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
      uVar6 = (*(code *)context[3])(length);
      *(undefined4 *)(compiledProgram + 0x10) = uVar6;
      (*(code *)context[0x4d1])(uVar6,text,length);
      *(undefined4 *)(*(int *)(newProgram + 0x74) + 0x58) = *(undefined4 *)(compiledProgram + 0x10);
      context[0x487] = currentProgram;
      *(undefined1 **)(context[0x49c] * 0x18 + *(int *)(stateHolder + 8) + 0x14) = currentProgram;
      uVar7 = *(undefined4 *)(newProgram + 0x70);
      uVar2 = *(undefined4 *)(newProgram + 0x54);
      uVar17 = *(undefined4 *)(currentProgram + 0x70);
      uVar19 = *(undefined4 *)(currentProgram + 0x74);
      uVar6 = *(undefined4 *)(newProgram + 0x50);
      puVar11 = *(undefined1 **)(newProgram + 0x58);
      uVar13 = *(undefined4 *)(newProgram + 0x5c);
      uVar12 = *(undefined4 *)(newProgram + 0x60);
      uVar10 = *(undefined4 *)(newProgram + 100);
      uVar9 = *(undefined4 *)(newProgram + 0x68);
      bVar1 = *(byte *)(newProgram + 0x6c);
      uVar8 = (uint)bVar1;
      *(undefined4 *)(currentProgram + 0x74) = *(undefined4 *)(newProgram + 0x74);
      *(undefined4 *)(currentProgram + 0x70) = uVar7;
      *(undefined4 *)(currentProgram + 0x54) = uVar2;
      *(undefined4 *)(currentProgram + 0x50) = uVar6;
      *(undefined1 **)(currentProgram + 0x58) = puVar11;
      *(undefined4 *)(currentProgram + 0x5c) = uVar13;
      *(undefined4 *)(currentProgram + 0x60) = uVar12;
      *(undefined4 *)(currentProgram + 100) = uVar10;
      *(undefined4 *)(currentProgram + 0x68) = uVar9;
      currentProgram[0x6c] = bVar1;
      *(undefined4 *)(newProgram + 0x70) = uVar17;
      *(undefined4 *)(newProgram + 0x74) = uVar19;
      ((int (*)())arbfpProgramObjectFree)(context,newProgram);
      (*(code *)context[6])(newProgram);
      puVar14 = *(undefined1 **)(currentProgram + 0x74);
      currentProgram[4] = puVar14[4];
      *currentProgram = *puVar14;
      currentProgram[1] = puVar14[1];
      currentProgram[2] = puVar14[2];
      currentProgram[3] = puVar14[3];
      *(undefined4 *)(currentProgram + 8) = *(undefined4 *)(puVar14 + 0xc);
      *(undefined4 *)(currentProgram + 0xc) = *(undefined4 *)(puVar14 + 0x10);
      if (*(char *)((int)context + 0x13b1) != '\0') {
        puVar3 = (undefined4 *)(puVar14 + 0x14);
        newProgram = 0;
        puVar11 = currentProgram;
        do {
          uVar6 = *puVar3;
          newProgram = newProgram + 1;
          puVar3 = puVar3 + 1;
          *(undefined4 *)(puVar11 + 0x10) = uVar6;
          puVar11 = puVar11 + 4;
        } while (newProgram < (int)(uint)*(byte *)((int)context + 0x13b1));
      }
      ((int (*)())arbfpUpdateStateForProgram)(context,extraout_r4,uVar7,uVar8,uVar9,uVar10,puVar11,uVar12);
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
  undefined4 uVar2;
  undefined4 uVar3;
  char cVar4;
  char *allocation;
  
  byteCount = wordCount * 4;
  allocation = (char *)_malloc(byteCount + 0xd);
  cVar4 = s___ILfs1_0_001a5d2c[0xc];
  uVar3 = (*(unsigned int *)((unsigned char *)&(s___ILfs1_0_001a5d2c) + 8));
  uVar2 = (*(unsigned int *)((unsigned char *)&(s___ILfs1_0_001a5d2c) + 4));
  *(undefined4 *)allocation = (*(unsigned int *)((unsigned char *)&(s___ILfs1_0_001a5d2c) + 0));
  *(undefined4 *)(allocation + 4) = uVar2;
  allocation[0xc] = cVar4;
  *(undefined4 *)(allocation + 8) = uVar3;
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
  float factorB;
  float factorA;
  float pivotRowElem7Value;
  float pivotRowElem6Value;
  float pivotRowElem5Value;
  float pivotRowElem4Value;
  float pivotRowElem3;
  float pivotRowElem2;
  float pivotRowElem1;
  float *eliminateRowB;
  float *eliminateRowA;
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
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  float *pfVar7;
  float *pivotRowElem5;
  int lightOrFace;
  float *pivotRowElem4;
  float *pfVar11;
  float *pivotRow;
  int stateOwner;
  float *pfVar14;
  float *pfVar15;
  int stateBlock;
  float *eliminateRowC;
  int kind;
  float *pivotRowElem6;
  float *pivotRowElem7;
  double length;
  double depthNear;
  float matrixCopy [4];
  float local_d8;
  float local_d4;
  float local_d0;
  float local_cc;
  float local_c8;
  float local_c4;
  float local_c0;
  float local_bc;
  float local_b8;
  float local_b4;
  float local_b0;
  float local_ac;
  float local_a8 [14];
  float local_6c;
  float local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  float local_58;
  float local_54;
  undefined4 local_50;
  float local_4c;
  float local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  float local_38;
  float local_34;
  float local_30;
  undefined4 local_2c;
  
  fVar1 = FLOAT_001aa0e8;
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
    halfVectorZ = *(float *)(*(int *)(element + 0xc) * 0x80 + stateBlock + 0x24f8) + fVar1;
    outValue[2] = halfVectorZ;
    length = _sqrt((double)(halfVectorZ * halfVectorZ + lightDirX * lightDirX + lightDirY * lightDirY));
    outValue[3] = fVar1;
    fVar1 = fVar1 / (float)length;
    outValue[2] = halfVectorZ * fVar1;
    *outValue = fVar1 * lightDirX;
    outValue[1] = lightDirY * fVar1;
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
      fVar1 = *(float *)(stateBlock + 0x28cc);
    }
    else {
      fVar1 = *(float *)(stateBlock + 0x2b0c);
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
      fVar1 = *(float *)(stateBlock + 0x28dc);
    }
    else {
      fVar1 = *(float *)(stateBlock + 0x2b1c);
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
      fVar1 = *(float *)(stateBlock + 0x28ec);
    }
    else {
      fVar1 = *(float *)(stateBlock + 0x2b2c);
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
    fVar1 = *(float *)(((unsigned char *)0x000031d0) + *(int *)(element + 0xc) * 0x7c + *(int *)(stateOwner + 0x10));
LAB_0008f398:
    outValue[3] = fVar1;
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
    pfVar7 = matrixCopy;
    do {
      iVar4 = lightOrFace * 4;
      lightOrFace = lightOrFace + 1;
      *pfVar7 = *(float *)(stateBlock + iVar4);
      pfVar7 = pfVar7 + 1;
      stateOwner = stateOwner + -1;
    } while (stateOwner != 0);
    lightOrFace = *(int *)(element + 0x10);
    if ((lightOrFace == 1) || (lightOrFace == 3)) {
      local_a8[4] = 1.0;
      local_a8[0xd] = 1.0;
      local_a8[1] = local_d8;
      local_a8[2] = local_c8;
      local_68 = matrixCopy[2];
      local_a8[0] = matrixCopy[0];
      local_a8[7] = FLOAT_001aa0d4;
      local_a8[6] = FLOAT_001aa0d4;
      local_a8[5] = FLOAT_001aa0d4;
      local_a8[8] = matrixCopy[1];
      local_6c = FLOAT_001aa0d4;
      local_a8[3] = local_b8;
      local_a8[9] = local_d4;
      local_a8[0xc] = FLOAT_001aa0d4;
      local_a8[10] = local_c4;
      local_a8[0xb] = local_b4;
      local_64 = local_d0;
      local_60 = local_c0;
      local_5c = local_b0;
      local_50 = 0x3f800000;
      local_4c = FLOAT_001aa0d4;
      local_2c = 0x3f800000;
      local_54 = FLOAT_001aa0d4;
      local_58 = FLOAT_001aa0d4;
      local_30 = FLOAT_001aa0d4;
      local_34 = FLOAT_001aa0d4;
      local_38 = FLOAT_001aa0d4;
      local_44 = local_cc;
      local_40 = local_bc;
      local_48 = matrixCopy[3];
      local_3c = local_ac;
      eliminateRowA = &STACKARG(0xffffffb8);
      eliminateRowC = &STACKARG(0xffffff98);
      if (ABS(matrixCopy[3]) <= ABS(matrixCopy[2])) {
        eliminateRowA = &STACKARG(0xffffff98);
        eliminateRowC = &STACKARG(0xffffffb8);
      }
      eliminateRowB = local_a8 + 8;
      fVar1 = *eliminateRowA;
      if (ABS(*eliminateRowA) <= ABS(matrixCopy[1])) {
        eliminateRowB = eliminateRowA;
        eliminateRowA = local_a8 + 8;
        fVar1 = matrixCopy[1];
      }
      pivotRow = local_a8;
      if (ABS(matrixCopy[0]) < ABS(fVar1)) {
        pivotRow = eliminateRowA;
        eliminateRowA = local_a8;
      }
      fVar1 = *pivotRow;
      if (fVar1 != FLOAT_001aa0d4) {
        pivotRowElem1 = pivotRow[1];
        pivotRowElem4 = pivotRow + 4;
        factorA = *eliminateRowA / fVar1;
        factorB = *eliminateRowB / fVar1;
        fVar1 = *eliminateRowC / fVar1;
        eliminateRowA[1] = -(factorA * pivotRowElem1 - eliminateRowA[1]);
        eliminateRowB[1] = -(factorB * pivotRowElem1 - eliminateRowB[1]);
        eliminateRowC[1] = -(fVar1 * pivotRowElem1 - eliminateRowC[1]);
        pivotRowElem2 = pivotRow[2];
        eliminateRowA[2] = -(factorA * pivotRowElem2 - eliminateRowA[2]);
        eliminateRowB[2] = -(factorB * pivotRowElem2 - eliminateRowB[2]);
        eliminateRowC[2] = -(fVar1 * pivotRowElem2 - eliminateRowC[2]);
        pivotRowElem3 = pivotRow[3];
        eliminateRowA[3] = -(factorA * pivotRowElem3 - eliminateRowA[3]);
        eliminateRowB[3] = -(factorB * pivotRowElem3 - eliminateRowB[3]);
        eliminateRowC[3] = -(fVar1 * pivotRowElem3 - eliminateRowC[3]);
        pivotRowElem4Value = pivotRow[4];
        if (pivotRowElem4Value != FLOAT_001aa0d4) {
          eliminateRowA[4] = -(factorA * pivotRowElem4Value - eliminateRowA[4]);
          eliminateRowB[4] = -(factorB * pivotRowElem4Value - eliminateRowB[4]);
          eliminateRowC[4] = -(fVar1 * pivotRowElem4Value - eliminateRowC[4]);
        }
        pivotRowElem5Value = pivotRow[5];
        pivotRowElem5 = pivotRow + 5;
        if (pivotRowElem5Value != FLOAT_001aa0d4) {
          eliminateRowA[5] = -(factorA * pivotRowElem5Value - eliminateRowA[5]);
          eliminateRowB[5] = -(factorB * pivotRowElem5Value - eliminateRowB[5]);
          eliminateRowC[5] = -(fVar1 * pivotRowElem5Value - eliminateRowC[5]);
        }
        pivotRowElem6Value = pivotRow[6];
        pivotRowElem6 = pivotRow + 6;
        if (pivotRowElem6Value != FLOAT_001aa0d4) {
          eliminateRowA[6] = -(factorA * pivotRowElem6Value - eliminateRowA[6]);
          eliminateRowB[6] = -(factorB * pivotRowElem6Value - eliminateRowB[6]);
          eliminateRowC[6] = -(fVar1 * pivotRowElem6Value - eliminateRowC[6]);
        }
        pivotRowElem7Value = pivotRow[7];
        pivotRowElem7 = pivotRow + 7;
        if (pivotRowElem7Value != FLOAT_001aa0d4) {
          eliminateRowA[7] = -(factorA * pivotRowElem7Value - eliminateRowA[7]);
          eliminateRowB[7] = -(factorB * pivotRowElem7Value - eliminateRowB[7]);
          eliminateRowC[7] = -(fVar1 * pivotRowElem7Value - eliminateRowC[7]);
        }
        pfVar15 = eliminateRowB;
        if (ABS(eliminateRowB[1]) < ABS(eliminateRowC[1])) {
          pfVar15 = eliminateRowC;
          eliminateRowC = eliminateRowB;
        }
        fVar1 = pfVar15[1];
        fVar2 = eliminateRowA[1];
        pfVar11 = eliminateRowA + 1;
        pfVar14 = pfVar15;
        if (ABS(fVar2) < ABS(fVar1)) {
          pfVar11 = pfVar15 + 1;
          pfVar14 = eliminateRowA;
          eliminateRowA = pfVar15;
          fVar2 = fVar1;
        }
        if (fVar2 != FLOAT_001aa0d4) {
          fVar3 = pfVar14[1] / fVar2;
          fVar2 = eliminateRowC[1] / fVar2;
          pfVar14[2] = -(fVar3 * eliminateRowA[2] - pfVar14[2]);
          eliminateRowC[2] = -(fVar2 * eliminateRowA[2] - eliminateRowC[2]);
          pfVar14[3] = -(fVar3 * eliminateRowA[3] - pfVar14[3]);
          eliminateRowC[3] = -(fVar2 * eliminateRowA[3] - eliminateRowC[3]);
          fVar1 = eliminateRowA[4];
          if (fVar1 != FLOAT_001aa0d4) {
            pfVar14[4] = -(fVar3 * fVar1 - pfVar14[4]);
            eliminateRowC[4] = -(fVar2 * fVar1 - eliminateRowC[4]);
          }
          fVar1 = eliminateRowA[5];
          if (fVar1 != FLOAT_001aa0d4) {
            pfVar14[5] = -(fVar3 * fVar1 - pfVar14[5]);
            eliminateRowC[5] = -(fVar2 * fVar1 - eliminateRowC[5]);
          }
          fVar1 = eliminateRowA[6];
          if (fVar1 != FLOAT_001aa0d4) {
            pfVar14[6] = -(fVar3 * fVar1 - pfVar14[6]);
            eliminateRowC[6] = -(fVar2 * fVar1 - eliminateRowC[6]);
          }
          fVar1 = eliminateRowA[7];
          if (fVar1 != FLOAT_001aa0d4) {
            pfVar14[7] = -(fVar3 * fVar1 - pfVar14[7]);
            eliminateRowC[7] = -(fVar2 * fVar1 - eliminateRowC[7]);
          }
          pfVar15 = pfVar14;
          if (ABS(pfVar14[2]) < ABS(eliminateRowC[2])) {
            pfVar15 = eliminateRowC;
            eliminateRowC = pfVar14;
          }
          fVar1 = pfVar15[2];
          if (fVar1 != FLOAT_001aa0d4) {
            fVar1 = eliminateRowC[2] / fVar1;
            fVar2 = -(fVar1 * pfVar15[3] - eliminateRowC[3]);
            eliminateRowC[3] = fVar2;
            fVar3 = -(fVar1 * pfVar15[4] - eliminateRowC[4]);
            eliminateRowC[4] = fVar3;
            fVar6 = -(fVar1 * pfVar15[5] - eliminateRowC[5]);
            eliminateRowC[5] = fVar6;
            fVar5 = -(fVar1 * pfVar15[6] - eliminateRowC[6]);
            eliminateRowC[6] = fVar5;
            fVar1 = -(fVar1 * pfVar15[7] - eliminateRowC[7]);
            eliminateRowC[7] = fVar1;
            if (fVar2 != FLOAT_001aa0d4) {
              fVar2 = FLOAT_001aa0e8 / fVar2;
              fVar3 = fVar2 * fVar3;
              eliminateRowC[4] = fVar3;
              eliminateRowC[7] = fVar2 * fVar1;
              eliminateRowC[5] = fVar2 * fVar6;
              eliminateRowC[6] = fVar2 * fVar5;
              fVar1 = pfVar15[3];
              fVar2 = FLOAT_001aa0e8 / pfVar15[2];
              pfVar15[4] = fVar2 * -(fVar1 * fVar3 - pfVar15[4]);
              pfVar15[5] = fVar2 * -(fVar1 * eliminateRowC[5] - pfVar15[5]);
              pfVar15[6] = fVar2 * -(fVar1 * eliminateRowC[6] - pfVar15[6]);
              pfVar15[7] = fVar2 * -(fVar1 * eliminateRowC[7] - pfVar15[7]);
              fVar1 = eliminateRowA[3];
              eliminateRowA[4] = -(fVar1 * eliminateRowC[4] - eliminateRowA[4]);
              eliminateRowA[5] = -(fVar1 * eliminateRowC[5] - eliminateRowA[5]);
              eliminateRowA[6] = -(fVar1 * eliminateRowC[6] - eliminateRowA[6]);
              eliminateRowA[7] = -(fVar1 * eliminateRowC[7] - eliminateRowA[7]);
              fVar1 = pivotRow[3];
              *pivotRowElem4 = -(fVar1 * eliminateRowC[4] - *pivotRowElem4);
              *pivotRowElem5 = -(fVar1 * eliminateRowC[5] - *pivotRowElem5);
              *pivotRowElem6 = -(fVar1 * eliminateRowC[6] - *pivotRowElem6);
              *pivotRowElem7 = -(fVar1 * eliminateRowC[7] - *pivotRowElem7);
              fVar1 = eliminateRowA[2];
              fVar2 = FLOAT_001aa0e8 / *pfVar11;
              eliminateRowA[4] = fVar2 * -(fVar1 * pfVar15[4] - eliminateRowA[4]);
              eliminateRowA[5] = fVar2 * -(fVar1 * pfVar15[5] - eliminateRowA[5]);
              eliminateRowA[6] = fVar2 * -(fVar1 * pfVar15[6] - eliminateRowA[6]);
              eliminateRowA[7] = fVar2 * -(fVar1 * pfVar15[7] - eliminateRowA[7]);
              fVar1 = pivotRow[2];
              *pivotRowElem4 = -(fVar1 * pfVar15[4] - *pivotRowElem4);
              *pivotRowElem5 = -(fVar1 * pfVar15[5] - *pivotRowElem5);
              *pivotRowElem6 = -(fVar1 * pfVar15[6] - *pivotRowElem6);
              *pivotRowElem7 = -(fVar1 * pfVar15[7] - *pivotRowElem7);
              fVar1 = pivotRow[1];
              fVar2 = FLOAT_001aa0e8 / *pivotRow;
              *pivotRowElem4 = fVar2 * -(fVar1 * eliminateRowA[4] - *pivotRowElem4);
              *pivotRowElem5 = fVar2 * -(fVar1 * eliminateRowA[5] - *pivotRowElem5);
              *pivotRowElem6 = fVar2 * -(fVar1 * eliminateRowA[6] - *pivotRowElem6);
              local_b8 = fVar2 * -(fVar1 * eliminateRowA[7] - *pivotRowElem7);
              *pivotRowElem7 = local_b8;
              matrixCopy[0] = *pivotRowElem4;
              local_d8 = *pivotRowElem5;
              local_c8 = *pivotRowElem6;
              matrixCopy[1] = eliminateRowA[4];
              local_d4 = eliminateRowA[5];
              local_c4 = eliminateRowA[6];
              local_b4 = eliminateRowA[7];
              matrixCopy[2] = pfVar15[4];
              local_d0 = pfVar15[5];
              local_c0 = pfVar15[6];
              lightOrFace = *(int *)(element + 0x10);
              local_b0 = pfVar15[7];
              matrixCopy[3] = eliminateRowC[4];
              local_cc = eliminateRowC[5];
              local_bc = eliminateRowC[6];
              local_ac = eliminateRowC[7];
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
        pfVar7 = matrixCopy + kind;
        do {
          fVar1 = *pfVar7;
          pfVar7 = pfVar7 + 4;
          *(float *)(lightOrFace + (int)outValue) = fVar1;
          lightOrFace = lightOrFace + 4;
          stateBlock = stateBlock + -1;
        } while (stateBlock != 0);
      }
      else if (lightOrFace < 4) {
        lightOrFace = 0;
        pfVar7 = matrixCopy + kind * 4;
        stateBlock = 4;
        do {
          fVar1 = *pfVar7;
          pfVar7 = pfVar7 + 1;
          *(float *)(lightOrFace + (int)outValue) = fVar1;
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
  undefined4 uVar1;
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
  undefined *puVar5;
  
  puVar5 = ((unsigned char *)0x000011d0U) + context;
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
      *(undefined4 *)(puVar5 + 0x5c) = 0;
      loopIndex = loopIndex + 1;
      puVar5 = puVar5 + 4;
    } while (loopIndex < (int)(uint)(byte)((unsigned char *)0x000013b1)[context]);
  }
  FUN_000a0350(context,*(int *)(((unsigned char *)0x0000126c) + context) * 0x18 + *(int *)(stateHolder + 8));
  *(undefined4 *)(*(int *)(((unsigned char *)0x0000126c) + context) * 0x18 + *(int *)(stateHolder + 8) + 4) = 0x8804;
  *(undefined4 *)(*(int *)(((unsigned char *)0x0000126c) + context) * 0x18 + *(int *)(stateHolder + 8)) = 0;
  slotIndex = *(int *)(((unsigned char *)0x0000126c) + context);
  slotTable = *(int *)(stateHolder + 8);
  uVar1 = (**(code **)(context + 0xc))(0x78,a1,in_r5,in_r6,in_r7,in_r8,slotTable);
  *(undefined4 *)(slotIndex * 0x18 + slotTable + 0x14) = uVar1;
  ((int (*)())arbfpProgramObjectInit)(context,*(undefined4 *)
                        (*(int *)(((unsigned char *)0x0000126c) + context) * 0x18 + *(int *)(stateHolder + 8) + 0x14));
  FUN_000a0350(context,*(int *)(((unsigned char *)0x00001220) + context) * 0x18 + *(int *)(stateHolder + 8));
  *(undefined4 *)(*(int *)(((unsigned char *)0x00001220) + context) * 0x18 + *(int *)(stateHolder + 8) + 4) = 0x8804;
  *(undefined4 *)(*(int *)(((unsigned char *)0x00001220) + context) * 0x18 + *(int *)(stateHolder + 8)) = 0;
  slotIndex = *(int *)(((unsigned char *)0x00001220) + context);
  slotTable = *(int *)(stateHolder + 8);
  uVar1 = (**(code **)(context + 0xc))(0x78,a1_00,in_r5,in_r6,in_r7,in_r8,slotTable);
  *(undefined4 *)(slotIndex * 0x18 + slotTable + 0x14) = uVar1;
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
  undefined4 uVar1;
  char *defaultText;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar3;
  undefined4 in_r10;
  
  uVar1 = 0xf;
  ((unsigned char *)0x000011d0)[context] = 1;
  defaultText = "!!ARBfp1.0\nEND\n";
  *(int *)(((unsigned char *)0x00001270) + context) = *(int *)(((unsigned char *)0x0000126c) + context);
  *(undefined4 *)(((unsigned char *)0x0000121c) + context) =
       *(undefined4 *)
        (*(int *)(((unsigned char *)0x0000126c) + context) * 0x18 + *(int *)(*(int *)(((unsigned char *)0x0000112c) + context) + 8)
        + 0x14);
  iVar3 = *(int *)(((unsigned char *)0x0000112c) + context);
  ((int (*)())arbValidateProgram)(context,*(undefined4 *)
                        (*(int *)(*(int *)(((unsigned char *)0x00001220) + context) * 0x18 + *(int *)(iVar3 + 8) +
                                 0x14) + 0x74),0xf,"!!ARBfp1.0\nEND\n");
  return ((int (*)())arbfpBindProgram)(context,*(undefined4 *)(((unsigned char *)0x0000126c) + context),uVar1,defaultText,in_r7,in_r8,iVar3,
               in_r10);
}

/* FUN_0008f7f0 @ 0x8f7f0 (884 bytes) */
int FUN_0008f7f0(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  uint *param_4;
  uint param_5;
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  char cVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  bool bVar9;
  code *pcVar10;
  undefined4 uVar11;
  int a1;
  undefined4 *puVar12;
  undefined4 uVar13;
  undefined4 extraout_r4;
  undefined4 uVar14;
  uint *a3;
  undefined4 a3_00;
  undefined1 *a4;
  undefined *puVar15;
  undefined4 *a1_00;
  int iVar16;
  uint a6;
  int iVar17;
  undefined1 auStack_f8 [144];
  undefined4 local_68;
  uint uStack_64;
  undefined4 local_60;
  uint uStack_5c;
  undefined4 local_58;
  uint uStack_54;
  undefined4 i2dHi1;
  uint i2dLo1;
  undefined4 local_48;
  undefined4 uStack_44;
  longlong local_40;
  longlong local_38;
  
  iVar17 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  a3 = param_4;
  a1 = (**(code **)(param_1 + 0x2758))(param_1,10000,param_3,param_4,param_5);
  pcVar10 = *(code **)(param_1 + 0x275c);
  *(int *)(0x00002748 + param_1 + 4) = a1;
  (*pcVar10)(param_1,a1,param_3,a3,param_5);
  iVar16 = *(int *)(param_1 + 4);
  if (((((*(uint *)(iVar16 + 0x154) & 0x700000) == 0) || (*param_4 != 0)) || (param_4[1] != 0)) ||
     ((param_4[2] != *(uint *)(iVar16 + 0x15c) || (param_4[3] != *(uint *)(iVar16 + 0x160))))) {
    bVar9 = false;
    iVar16 = 0;
  }
  else {
    bVar9 = true;
    FUN_000a5c40(param_1);
    iVar16 = *(int *)(0x00002748 + param_1 + 4);
  }
  uVar14 = 0;
  a3_00 = 0;
  a4 = auStack_f8;
  FUN_00086ba0(param_1,1,0,0,a4);
  uVar13 = 0x25;
  if (*(char *)(param_1 + 0x2802) != '\0') {
    uVar13 = 0x23;
  }
  puVar12 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,uVar13,uVar14,a3_00,a4);
  cVar6 = *(char *)(param_1 + 0x2802);
  *(undefined4 **)(0x00002748 + param_1 + 4) = puVar12;
  if (cVar6 == '\0') {
    puVar12[1] = 0x10000000;
    *puVar12 = 0x5c8;
    *(undefined1 *)(param_1 + 0x2802) = 1;
  }
  uVar13 = (**(code **)(param_1 + 0x2758))(param_1,0x23,uVar14,a3_00,a4);
  *(undefined4 *)(0x00002748 + param_1 + 4) = uVar13;
  puVar12 = (undefined4 *)FUN_00083c90(param_1,uVar13);
  if (bVar9) {
    *(int *)(a1 + 8) = (int)puVar12 - a1 >> 2;
  }
  puVar15 = ((unsigned char *)0x00001087U);
  a1_00 = puVar12 + 0x10;
  local_68 = 0x43300000;
  local_60 = 0x43300000;
  local_58 = 0x43300000;
  i2dHi1 = 0x43300000;
  i2dLo1 = param_4[2] ^ 0x80000000;
  uStack_64 = param_4[1] ^ 0x80000000;
  uStack_5c = *param_4 ^ 0x80000000;
  uStack_54 = param_4[3] ^ 0x80000000;
  uStack_44 = *(undefined4 *)(param_1 + 8);
  uVar13 = *(undefined4 *)(((unsigned char *)0x00002dac) + iVar17);
  uVar14 = *(undefined4 *)(((unsigned char *)0x00002da0) + iVar17);
  uVar7 = *(undefined4 *)(((unsigned char *)0x00002da4) + iVar17);
  uVar8 = *(undefined4 *)(((unsigned char *)0x00002da8) + iVar17);
  local_48 = 0x43300000;
  fVar1 = (float)((double)CONCAT44(0x43300000,i2dLo1) - 4503601774854144.0);
  fVar2 = (float)((double)CONCAT44(0x43300000,uStack_64) - 4503601774854144.0);
  fVar3 = (float)((double)CONCAT44(0x43300000,uStack_54) - 4503601774854144.0);
  fVar4 = (float)((double)CONCAT44(0x43300000,uStack_5c) - 4503601774854144.0);
  fVar5 = (float)((double)CONCAT44(0x43300000,uStack_44) - 4503599627370496.0);
  a6 = (uint)(int)(*(float *)(param_1 + 0x2818) * 0.5 * fVar5 * (fVar3 - fVar2));
  local_40 = (longlong)(int)a6;
  iVar17 = (int)(fVar5 * *(float *)(param_1 + 0x2814) * 0.5 * (fVar1 - fVar4));
  local_38 = (longlong)iVar17;
  puVar12[2] = 0x82c;
  *puVar12 = ((unsigned char *)0x00001087U);
  puVar12[1] = iVar17 << 0x10 | a6 & 0xffff;
  uVar11 = *(undefined4 *)(param_1 + 0x1b84);
  puVar12[5] = 0x10031;
  puVar12[4] = 0xc0083500;
  puVar12[6] = (fVar4 + fVar1) * 0.5;
  puVar12[7] = (fVar2 + fVar3) * 0.5;
  puVar12[9] = 0x3f800000;
  puVar12[10] = uVar14;
  puVar12[0xb] = uVar7;
  puVar12[3] = uVar11;
  puVar12[0xc] = uVar8;
  puVar12[0xd] = uVar13;
  puVar12[0xe] = ((unsigned char *)0x00001087U);
  puVar12[8] = 0;
  puVar12[0xf] = *(undefined4 *)(param_1 + 0x1ccc);
  *(undefined4 **)(0x00002748 + param_1 + 4) = a1_00;
  (**(code **)(param_1 + 0x275c))(param_1,a1_00,puVar12,a3_00,((unsigned char *)0x00001087U),a1_00,a6,0xc0083500);
  FUN_0009d3b0(param_1,extraout_r4,puVar12,a3_00,puVar15,a1_00,a6);
  FUN_000872e0(param_1,auStack_f8);
  if (bVar9) {
    *(int *)(a1 + 4) = *(int *)(0x00002748 + param_1 + 4) - iVar16 >> 2;
  }
  return;
}

/* FUN_0008fb70 @ 0x8fb70 (248 bytes) */
int FUN_0008fb70(param_1)
  int param_1;
{
  int iVar1;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar2;
  
  if (*(int *)(((unsigned char *)0x00003e28) + *(int *)(*(int *)(param_1 + 4) + 0x10)) != 0) {
    FUN_00086840(param_1);
  }
  iVar2 = *(int *)(param_1 + 0x1b7c);
  *(undefined1 *)(param_1 + 0x23ec) = 1;
  if (*(char *)(param_1 + 0x1868) == '\0') {
    if ((*(uint *)(param_1 + 0x44) & 0x100000) != 0) {
      FUN_000651e0(param_1);
    }
  }
  else if ((*(uint *)(param_1 + 0x44) & 0x100000) != 0) {
    iVar1 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + **(int **)(((unsigned char *)0x00001168) + param_1));
    (**(code **)((int)((unsigned char *)0x00001294) + param_1))
              (param_1,iVar1 + 0x13c,*(undefined4 *)(iVar1 + 0x130),in_r6,in_r7,in_r8,
               *(int *)(((unsigned char *)0x0000118c) + param_1) * 4);
  }
  FUN_0009d2e0(param_1);
  *(char *)(param_1 + 0x23ec) = '\x01' - (iVar2 == *(int *)(param_1 + 0x1b7c));
  return;
}

/* FUN_0008fc70 @ 0x8fc70 (1028 bytes) */
int FUN_0008fc70(param_1)
  int param_1;
{
  uint loopIndex;
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  
  iVar4 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  _memset(param_1 + 0x19c,0xffffffff,0x68);
  FUN_0004fc80(param_1,0,3,0,0,0,0,0);
  *(undefined4 *)(param_1 + 0x19c) = 0;
  if (*(int *)(param_1 + 0x44) < 0) {
    FUN_0004fc80(param_1,1,3,0,1,0,0,0);
    *(undefined4 *)(param_1 + 0x1a0) = 1;
    if (((unsigned char *)0x00002d48)[iVar4 + 3] == '\0') {
      uVar3 = *(uint *)(param_1 + 0x44);
      uVar5 = 2;
    }
    else {
      uVar5 = 3;
      FUN_0004fc80(param_1,2,3,0,2,0,0,0);
      uVar3 = *(uint *)(param_1 + 0x44);
      *(undefined4 *)(param_1 + 0x1a8) = 2;
    }
  }
  else {
    uVar5 = *(uint *)(param_1 + 0x8c);
    if (((uVar5 >> 0x14 & 1) == 0 && (uVar5 >> 0x1a & 1) == 0) && (uVar5 >> 0x1b & 1) == 0) {
      iVar7 = 1;
      uVar6 = 1;
      uVar5 = 2;
    }
    else {
      iVar7 = 2;
      uVar5 = 3;
      FUN_0004fc80(param_1,1,3,0,1,0,0,0);
      uVar6 = 2;
      *(undefined4 *)(param_1 + 0x1a0) = 1;
    }
    FUN_0004fc80(param_1,uVar6,3,0,uVar6,0,0,0);
    uVar3 = *(uint *)(param_1 + 0x44);
    *(undefined4 *)(param_1 + 0x1a8) = uVar6;
    if ((uVar3 & 0xa10000) != 0) {
      FUN_0004fc80(param_1,uVar5,3,0,uVar5,0,0,0);
      uVar3 = *(uint *)(param_1 + 0x44);
      *(uint *)(param_1 + 0x1ac) = uVar5;
      uVar5 = iVar7 + 2;
    }
  }
  if ((uVar3 & 0x20000) == 0) {
    uVar2 = (uint)*(byte *)(param_1 + 0x2b);
    if ((uint)(byte)((unsigned char *)0x000013b0)[param_1] < (uint)*(byte *)(param_1 + 0x2b)) {
      uVar2 = (uint)(byte)((unsigned char *)0x000013b0)[param_1];
    }
    if (uVar2 == 0) goto LAB_0008ff78;
    loopIndex = 0;
    iVar7 = param_1;
    iVar8 = param_1;
    do {
      if ((((unsigned char *)0x00001438)[iVar8] != '\0') && (*(int *)(((unsigned char *)0x000013f8) + iVar7) != 0)) {
        FUN_0004fc80(param_1,uVar5,3,0,uVar5,0,0,0);
        *(uint *)(iVar7 + 0x1c8) = uVar5;
        uVar5 = uVar5 + 1;
      }
      loopIndex = loopIndex + 1;
      iVar8 = iVar8 + 1;
      iVar7 = iVar7 + 4;
    } while (loopIndex != uVar2);
  }
  else {
    if ((uVar3 & 0x2000) == 0) {
      bVar1 = ((unsigned char *)0x00001135)[param_1];
    }
    else {
      bVar1 = ((unsigned char *)0x000011d3)[param_1];
    }
    uVar2 = (uint)(byte)((unsigned char *)0x000013b0)[param_1];
    if (uVar2 == 0) goto LAB_0008ff78;
    loopIndex = 0;
    iVar7 = param_1;
    do {
      if (((uint)bVar1 & 1 << (loopIndex & 0x3f)) != 0) {
        FUN_0004fc80(param_1,uVar5,3,0,uVar5,0,0,0);
        uVar2 = (uint)(byte)((unsigned char *)0x000013b0)[param_1];
        *(uint *)(iVar7 + 0x1c8) = uVar5;
        uVar5 = uVar5 + 1;
      }
      loopIndex = loopIndex + 1;
      iVar7 = iVar7 + 4;
    } while ((int)loopIndex < (int)uVar2);
  }
  uVar3 = *(uint *)(param_1 + 0x44);
LAB_0008ff78:
  if (((uVar3 & 0x1000800) != 0) && (*(short *)(((unsigned char *)0x00002e06) + iVar4) == -0x7baf)) {
    FUN_0004fc80(param_1,uVar5,3,0,uVar5,0,0,0);
    *(uint *)(param_1 + 0x1ec) = uVar5;
    uVar5 = uVar5 + 1;
    *(undefined4 *)(param_1 + 0x1f0) = 0;
  }
  if (((unsigned char *)0x00004301)[iVar4] != '\0') {
    FUN_0004fc80(param_1,uVar5,3,0,uVar5,0,0,0);
    *(uint *)(param_1 + 0x1f8) = uVar5;
    uVar5 = uVar5 + 1;
  }
  uVar3 = uVar5 - 1;
  if ((uVar3 & 1) == 0) {
    iVar4 = (uVar3 * 2 & 0xfffffffc) + param_1;
    *(uint *)(iVar4 + 0x1be4) = *(uint *)(iVar4 + 0x1be4) | 0x2000;
  }
  else {
    iVar4 = (uVar3 * 2 & 0xfffffffc) + param_1;
    *(uint *)(iVar4 + 0x1be4) = *(uint *)(iVar4 + 0x1be4) | 0x20000000;
  }
  *(char *)(param_1 + 0x131) = (char)uVar5;
  *(uint *)(param_1 + 0x2430) = uVar5;
  *(uint *)(param_1 + 0x2438) = uVar5;
  *(undefined1 *)(param_1 + 0x2435) = 1;
  *(uint *)(param_1 + 0x243c) = uVar5;
  *(uint *)(param_1 + 0x1ca4) = (uVar5 & 0x1f) << 2 | *(uint *)(param_1 + 0x1ca4) & 0xffffff80;
  return;
}

/* FUN_000900a0 @ 0x900a0 (944 bytes) */
int FUN_000900a0(param_1)
  int param_1;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  
  uVar9 = *(uint *)(param_1 + 0x1b9c);
  iVar11 = *(int *)(param_1 + 0x1ba0);
  iVar10 = *(int *)(param_1 + 0x1ca0);
  iVar5 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if ((*(char *)(param_1 + 0x1868) != '\0') && (*(char *)(param_1 + 0x124) != '\0')) {
    FUN_0004dbe0(param_1);
    return;
  }
  uVar8 = *(uint *)(param_1 + 0x44);
  *(undefined4 *)(param_1 + 0x1ca0) = 1;
  if ((int)uVar8 < 0) {
    *(undefined4 *)(param_1 + 0x1ca0) = 3;
    if (((unsigned char *)0x00002d48)[iVar5 + 3] != '\0') {
      *(undefined4 *)(param_1 + 0x1ca0) = 7;
    }
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x8c);
    if (((uVar1 >> 0x14 & 1) != 0 || (uVar1 >> 0x1a & 1) != 0) || (uVar1 >> 0x1b & 1) != 0) {
      *(undefined4 *)(param_1 + 0x1ca0) = 3;
    }
    uVar1 = *(uint *)(param_1 + 0x1ca0);
    *(uint *)(param_1 + 0x1ca0) = uVar1 | 4;
    if ((uVar8 & 0xa10000) != 0) {
      *(uint *)(param_1 + 0x1ca0) = uVar1 | 0xc;
    }
  }
  if (((uVar8 & 0x1000800) != 0) && (*(short *)(((unsigned char *)0x00002e06) + iVar5) == -0x7baf)) {
    *(uint *)(param_1 + 0x1ca0) = *(uint *)(param_1 + 0x1ca0) | 0x40000;
  }
  if (((unsigned char *)0x00004301)[iVar5] != '\0') {
    *(uint *)(param_1 + 0x1ca0) = *(uint *)(param_1 + 0x1ca0) | 0x80000;
  }
  uVar1 = 3;
  *(undefined4 *)(param_1 + 0x1b9c) = 3;
  *(undefined4 *)(param_1 + 0x1ba0) = 0;
  uVar4 = *(uint *)(param_1 + 0x44);
  if ((int)uVar4 < 0) {
    if (*(short *)(((unsigned char *)0x00002d48) + iVar5) == -0x7e06) {
      *(undefined4 *)(param_1 + 0x1b9c) = 7;
    }
    if (((unsigned char *)0x00002d48)[iVar5 + 4] == '\0') {
      uVar1 = *(uint *)(param_1 + 0x1b9c);
    }
    else {
      uVar1 = *(uint *)(param_1 + 0x1b9c) | 0x1c;
      *(uint *)(param_1 + 0x1b9c) = uVar1;
    }
  }
  else if (((uVar4 >> 0x17 & 1) != 0 || (uVar4 >> 0x15 & 1) != 0) || (uVar4 >> 0x10 & 1) != 0) {
    uVar1 = 7;
    *(undefined4 *)(param_1 + 0x1b9c) = 7;
  }
  if ((*(uint *)(param_1 + 0xe8) & 1) != 0) {
    uVar1 = uVar1 | 0x10000;
    *(uint *)(param_1 + 0x1b9c) = uVar1;
  }
  if (((uVar8 & 0x1000000) != 0) && (*(char *)(param_1 + 0x121) == '\0')) {
    uVar1 = uVar1 | 4;
    *(uint *)(param_1 + 0x1b9c) = uVar1;
  }
  if ((uVar8 & 0x20000) == 0) {
    uVar8 = (uint)(byte)((unsigned char *)0x000013b0)[param_1];
    if ((uint)*(byte *)(param_1 + 0x2b) <= (uint)(byte)((unsigned char *)0x000013b0)[param_1]) {
      uVar8 = (uint)*(byte *)(param_1 + 0x2b);
    }
    if (uVar8 != 0) {
      iVar2 = 0;
      uVar4 = 0;
      iVar5 = param_1;
      iVar7 = param_1;
      do {
        if ((((unsigned char *)0x00001438)[iVar7] != '\0') && (*(int *)(((unsigned char *)0x000013f8) + iVar5) != 0)) {
          *(uint *)(param_1 + 0x1ba0) = 4 << (uVar4 & 0x3f) | *(uint *)(param_1 + 0x1ba0);
          *(uint *)(param_1 + 0x1ca0) = 1 << (iVar2 + 10U & 0x3f) | *(uint *)(param_1 + 0x1ca0);
        }
        iVar2 = iVar2 + 1;
        uVar4 = uVar4 + 3;
        iVar7 = iVar7 + 1;
        iVar5 = iVar5 + 4;
        uVar8 = uVar8 - 1;
      } while (uVar8 != 0);
    }
  }
  else {
    if ((uVar8 & 0x2000) == 0) {
      uVar4 = (uint)(byte)((unsigned char *)0x00001135)[param_1];
    }
    else {
      uVar4 = (uint)(byte)((unsigned char *)0x000011d3)[param_1];
      if ((uVar8 & 0x800) != 0) {
        *(uint *)(param_1 + 0x1ba0) =
             4 << ((uint)(byte)((unsigned char *)0x000011d1)[param_1] * 3 & 0x3f) | *(uint *)(param_1 + 0x1ba0);
      }
      if ((uVar8 & 0x400) != 0) {
        *(uint *)(param_1 + 0x1ba0) =
             4 << ((uint)(byte)((unsigned char *)0x000011d2)[param_1] * 3 & 0x3f) | *(uint *)(param_1 + 0x1ba0);
      }
    }
    uVar8 = (uint)(byte)((unsigned char *)0x000013b0)[param_1];
    if (uVar8 != 0) {
      uVar6 = 0;
      uVar3 = 0;
      if (uVar8 == 0) {
        uVar8 = 1;
      }
      do {
        if ((uVar4 & 1 << (uVar6 & 0x3f)) != 0) {
          *(uint *)(param_1 + 0x1ba0) = 4 << (uVar3 & 0x3f) | *(uint *)(param_1 + 0x1ba0);
          *(uint *)(param_1 + 0x1ca0) = 1 << (uVar6 + 10 & 0x3f) | *(uint *)(param_1 + 0x1ca0);
        }
        uVar6 = uVar6 + 1;
        uVar3 = uVar3 + 3;
        uVar8 = uVar8 - 1;
      } while (uVar8 != 0);
    }
  }
  if ((((uVar9 != uVar1) || (iVar11 != *(int *)(param_1 + 0x1ba0))) ||
      (iVar10 != *(int *)(param_1 + 0x1ca0))) || (*(char *)(param_1 + 299) != '\0')) {
    *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x40000;
    ((int (*)())FUN_0008fc70)(param_1);
    (**(code **)(((unsigned char *)0x00001334) + param_1))(param_1,1);
    *(undefined1 *)(param_1 + 299) = 0;
  }
  return;
}

/* gldValidateState @ 0x90470 (952 bytes) */
void gldValidateState(int glContext,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9)
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
  double in_stack_ffffffb8;
  
  if (*(char *)(glContext + 0x1868) != '\0') {
    if ((*(uint *)(glContext + 0x44) & 0x100000) == 0) {
      *(code **)(((unsigned char *)0x000012b4) + glContext) = FUN_000900a0;
    }
    else {
      *(undefined **)(((unsigned char *)0x000012b4) + glContext) = PTR_FUN_001e89ec;
    }
  }
  dirtyMask2 = *(uint *)(glContext + 0x1808) & 0x20000000;
  if (dirtyMask2 != 0) {
    fparam_1 = (double)FUN_000a4980(glContext,param_2,param_3,param_4,param_5);
    param_2 = extraout_r4;
  }
  dirtyMask = *(uint *)(glContext + 0x38);
  if (dirtyMask != 0) {
    if ((dirtyMask & 4) != 0) {
      fparam_1 = (double)((double (*)())gldValidatePolygonMode)(glContext,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,
                                      fparam_7,fparam_8);
      dirtyMask = *(uint *)(glContext + 0x38);
      param_2 = extraout_r4_00;
    }
    if ((dirtyMask & 2) != 0) {
      fparam_1 = (double)FUN_0004eba0(glContext,param_2,param_3,param_4,param_5,param_6,dirtyMask2);
      dirtyMask = *(uint *)(glContext + 0x38);
      param_2 = extraout_r4_01;
    }
    if ((dirtyMask & 8) != 0) {
      fparam_1 = (double)FUN_0004ed90(glContext);
      dirtyMask = *(uint *)(glContext + 0x38);
      param_2 = extraout_r4_02;
    }
    if ((dirtyMask & 0x400) != 0) {
      fparam_1 = (double)((double (*)())FUN_000520c0)(glContext,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,
                                      fparam_7,fparam_8);
      dirtyMask = *(uint *)(glContext + 0x38);
      param_2 = extraout_r4_03;
    }
    if ((dirtyMask & 0x100) != 0) {
      ((void (*)())FUN_0004f2e0)(glContext,param_2,param_3,param_4,fparam_1);
      fparam_1 = (double)FUN_0009cf10(glContext,extraout_r4_04,param_3,param_4,param_5,param_6);
      dirtyMask = *(uint *)(glContext + 0x38);
      param_2 = extraout_r4_05;
    }
    if ((dirtyMask & 0x800) != 0) {
      fparam_1 = (double)FUN_0009cff0(glContext);
      dirtyMask = *(uint *)(glContext + 0x38);
      param_2 = extraout_r4_06;
    }
    if ((dirtyMask & 0x4000) != 0) {
      fparam_1 = (double)gldValidateCullFace(glContext);
      dirtyMask = *(uint *)(glContext + 0x38);
      param_2 = extraout_r4_07;
    }
    if ((dirtyMask & 0x2200) != 0) {
      fparam_1 = (double)((double (*)())FUN_0004def0)(glContext,param_2,param_3,param_4,fparam_1,fparam_2,fparam_3,
                                      fparam_4,fparam_5,fparam_6,fparam_7,fparam_8,in_stack_ffffffb8
                                     );
      dirtyMask = *(uint *)(glContext + 0x38);
      param_2 = extraout_r4_08;
    }
    if ((*(uint *)(glContext + 0x8c) & 0x40000000) == 0) {
      if ((dirtyMask & 0x20000) != 0) {
        fparam_1 = (double)FUN_000867b0(glContext);
        dirtyMask = *(uint *)(glContext + 0x38);
        param_2 = extraout_r4_09;
      }
      if ((dirtyMask & 0x20) != 0) {
        ((void (*)())FUN_000bd9a0)(glContext,param_2,param_3,param_4,fparam_1);
        dirtyMask = *(uint *)(glContext + 0x38);
        param_2 = extraout_r4_10;
      }
      if ((dirtyMask & 0x1000) != 0) {
        if (*(char *)(glContext + 0x1868) == '\0') {
          FUN_00064f40(glContext,param_2);
          param_2 = extraout_r4_12;
        }
        else {
          (**(code **)((int)((unsigned char *)0x000011cc) + glContext))(glContext);
          param_2 = extraout_r4_11;
        }
      }
    }
    else if ((dirtyMask & 0x20) != 0) {
      ((void (*)())FUN_0004d620)(glContext,param_2,param_3,param_4,fparam_1);
      param_2 = extraout_r4_13;
    }
  }
  dirtyMask2 = *(uint *)(glContext + 0x3c);
  if (dirtyMask2 != 0) {
    if ((dirtyMask2 & 1) != 0) {
      gldValidateDepthTest(glContext);
      dirtyMask2 = *(uint *)(glContext + 0x3c);
      param_2 = extraout_r4_14;
    }
    if ((dirtyMask2 & 2) != 0) {
      gldValidateScissor(glContext);
      dirtyMask2 = *(uint *)(glContext + 0x3c);
      param_2 = extraout_r4_15;
    }
    if ((dirtyMask2 & 8) != 0) {
      gldValidateBlend(glContext);
      dirtyMask2 = *(uint *)(glContext + 0x3c);
      param_2 = extraout_r4_16;
    }
    if ((dirtyMask2 & 0x10) != 0) {
      gldValidateAlphaTest(glContext);
      dirtyMask2 = *(uint *)(glContext + 0x3c);
      param_2 = extraout_r4_17;
    }
    if ((dirtyMask2 & 0x20) != 0) {
      gldValidateStencil(glContext);
      dirtyMask2 = *(uint *)(glContext + 0x3c);
      param_2 = extraout_r4_18;
    }
    if ((dirtyMask2 & 0x40) != 0) {
      FUN_00050140(glContext,param_2,param_3,param_4,param_5,param_6);
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
        ((int (*)())FUN_000900a0)(glContext);
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

/* FUN_00090840 @ 0x90840 (264 bytes) */
int FUN_00090840(param_1)
  int param_1;
{
  uint uVar1;
  float fVar2;
  code *UNRECOVERED_JUMPTABLE;
  undefined4 *puVar3;
  bool bVar4;
  
  fVar2 = FLOAT_001aa0e8;
  if ((*(uint *)(param_1 + 0x8c) & 0x40000000) == 0) {
    *(uint *)(param_1 + 0x1b74) = *(uint *)(param_1 + 0x1b74) & 0xfffeffff;
    *(uint *)(param_1 + 0x1b84) = *(uint *)(param_1 + 0x1b84) & 0xfffffcff | 0x43f;
  }
  else {
    bVar4 = *(float *)(param_1 + 0x2814) != FLOAT_001aa0e8;
    uVar1 = *(uint *)(param_1 + 0x1b84) & 0xfffffbc0;
    *(uint *)(param_1 + 0x1b84) = uVar1 | 0x300;
    if ((bVar4) || (*(float *)(param_1 + 0x2818) != fVar2)) {
      *(uint *)(param_1 + 0x1b84) = uVar1 | 0x305;
    }
    *(uint *)(param_1 + 0x1b74) = *(uint *)(param_1 + 0x1b74) | 0x10000;
  }
  puVar3 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,4);
  *(undefined4 **)(0x00002748 + param_1 + 4) = puVar3;
  *puVar3 = 0x82c;
  *(undefined4 *)(*(int *)(0x00002748 + param_1 + 4) + 4) = *(undefined4 *)(param_1 + 0x1b84);
  *(undefined4 *)(*(int *)(0x00002748 + param_1 + 4) + 8) = 0x887;
  *(undefined4 *)(*(int *)(0x00002748 + param_1 + 4) + 0xc) = *(undefined4 *)(param_1 + 0x1b74);
  UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x275c);
  *(int *)(0x00002748 + param_1 + 4) = *(int *)(0x00002748 + param_1 + 4) + 0x10;
                    
                    
  (*UNRECOVERED_JUMPTABLE)(param_1,*(int *)(0x00002748 + param_1 + 4));
  return;
}

/* FUN_00090960 @ 0x90960 (48 bytes) */
int FUN_00090960(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if (*(char *)(iVar1 + 0x20) == '\0') {
    return;
  }
  if ((*(uint *)(param_1 + 0x8c) & 0x40000000) == 0) {
    return;
  }
  *(undefined1 *)(iVar1 + 0x20) = 0;
  *(undefined4 *)(iVar1 + 0x1cc) = 0;
  return ((int (*)())FUN_00090840)(param_1);
}

/* FUN_00090990 @ 0x90990 (772 bytes) */
int FUN_00090990(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(param_1 + 4);
  iVar4 = *(int *)(iVar3 + 0x10);
  if ((*(int *)(((unsigned char *)0x00003e28) + iVar4) == 0) || (bVar1 = true, ((unsigned char *)0x000013a8)[param_1] != '\0')) {
    bVar1 = false;
  }
  if ((((((*(char *)(iVar3 + 0x21) != '\0') && ((param_2[3] & 0x10000000) == 0)) &&
        ((*(int *)(*(int *)(iVar3 + 0x18) + 0x198) == 0 || (*(int *)(iVar3 + 0x1cc) != 0)))) &&
       ((((unsigned char *)0x00004304)[iVar4] == '\0' || (*(int *)(iVar3 + 0x1cc) != 0)))) &&
      ((((unsigned char *)0x00002d48)[iVar4 + 2] == '\0' || (((unsigned char *)0x00002d48)[iVar4 + 6] == '\0')))) && (!bVar1))
  {
    if (*(char *)(iVar3 + 0x20) == '\0') {
      *(undefined1 *)(iVar3 + 0x20) = 1;
      *(undefined1 *)(param_1 + 299) = 1;
      *(undefined1 *)(param_1 + 0x125) = 0;
      *(undefined1 *)(param_1 + 0x126) = 0;
      *(undefined1 *)(param_1 + 0x124) = 0;
      *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) & 0xbfffffff;
      param_2[4] = 0xffffffff;
      *param_2 = 0xffffffff;
      param_2[2] = param_2[2] | 0xfffffffd;
      param_2[1] = param_2[1] | 0x3ffffff;
      param_2[3] = param_2[3] | 0x7ffffff;
      *(undefined1 *)(param_1 + 0x2c) = 0xff;
      *(undefined4 *)(param_1 + 0x38) = 0x7ffff;
      *(undefined1 *)(param_1 + 0x2d) = 0xf;
      *(undefined1 *)(param_1 + 0x29) = 1;
      *(undefined2 *)(param_1 + 0x34) = 0xffff;
      *(undefined4 *)(param_1 + 0x3c) = 0x800015ff;
      *(undefined1 *)(param_1 + 0x2a) = 1;
      *(undefined4 *)(param_1 + 0x40) = 0x7ffff;
      *(undefined2 *)(param_1 + 0x32) = 0xffff;
      *(undefined1 *)(param_1 + 0x2e) = 3;
      *(undefined1 *)(param_1 + 0x30) = 7;
      *(undefined4 *)(param_1 + 0x180c) = 5;
      *(undefined4 *)(param_1 + 0x1810) = 0x1f;
      uVar2 = (uint)(byte)((unsigned char *)0x000013b5)[param_1];
      if (uVar2 != 0) {
        iVar3 = param_1;
        if (uVar2 == 0) {
          uVar2 = 1;
        }
        do {
          *(undefined1 *)(iVar3 + 0x1814) = 0x3f;
          *(undefined1 *)(iVar3 + 0x181c) = 3;
          iVar3 = iVar3 + 1;
          uVar2 = uVar2 - 1;
        } while (uVar2 != 0);
      }
      *(undefined1 *)(param_1 + 0x2803) = 1;
      *(undefined1 *)(param_1 + 0x23ec) = 1;
      *(undefined1 *)(param_1 + 0x29) = 1;
      *(undefined1 *)(param_1 + 0x247d) = 1;
      *(uint *)(param_1 + 0x2488) = *(uint *)(param_1 + 0x2488) | 7;
      return;
    }
    return;
  }
  if (*(char *)(iVar3 + 0x20) != '\0') {
    *(undefined1 *)(iVar3 + 0x20) = 0;
    *(undefined1 *)(param_1 + 299) = 1;
    *(undefined1 *)(param_1 + 0x126) = 1;
    *(undefined1 *)(param_1 + 0x124) = 1;
    *(undefined1 *)(param_1 + 0x125) = 0;
    *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) | 0x40000000;
    param_2[4] = 0xffffffff;
    *param_2 = 0xffffffff;
    param_2[2] = param_2[2] | 0xfffffffd;
    param_2[1] = param_2[1] | 0x3ffffff;
    param_2[3] = param_2[3] | 0x7ffffff;
    *(undefined1 *)(param_1 + 0x2c) = 0xff;
    *(undefined4 *)(param_1 + 0x38) = 0x7ffff;
    *(undefined1 *)(param_1 + 0x2d) = 0xf;
    *(undefined1 *)(param_1 + 0x29) = 1;
    *(undefined2 *)(param_1 + 0x34) = 0xffff;
    *(undefined4 *)(param_1 + 0x3c) = 0x800015ff;
    *(undefined1 *)(param_1 + 0x2a) = 1;
    *(undefined4 *)(param_1 + 0x40) = 0x7ffff;
    *(undefined2 *)(param_1 + 0x32) = 0xffff;
    *(undefined1 *)(param_1 + 0x2e) = 3;
    *(undefined1 *)(param_1 + 0x30) = 7;
    *(undefined4 *)(param_1 + 0x180c) = 5;
    *(undefined4 *)(param_1 + 0x1810) = 0x1f;
    uVar2 = (uint)(byte)((unsigned char *)0x000013b5)[param_1];
    if (uVar2 != 0) {
      iVar4 = param_1;
      if (uVar2 == 0) {
        uVar2 = 1;
      }
      do {
        *(undefined1 *)(iVar4 + 0x1814) = 0x3f;
        *(undefined1 *)(iVar4 + 0x181c) = 3;
        iVar4 = iVar4 + 1;
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
    }
    *(undefined1 *)(param_1 + 0x2803) = 1;
    *(undefined1 *)(param_1 + 0x23ec) = 1;
    *(undefined1 *)(param_1 + 0x29) = 1;
    *(undefined1 *)(param_1 + 0x247d) = 1;
    *(uint *)(param_1 + 0x2488) = *(uint *)(param_1 + 0x2488) | 7;
  }
  *(undefined4 *)(iVar3 + 0x1cc) = 0;
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
  char *pcVar1;
  char cVar2;
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
        cVar2 = *(char *)(allocState + 0x6c7);
        flagCursor = allocState;
        while (cVar2 != '\0') {
          loopIndex = loopIndex + 1;
          regCountdown = regCountdown + -1;
          if (regCountdown == 0) goto LAB_00091090;
          if (*(char *)(flagCursor + 0x6c8) == '\0') goto LAB_00090e7c;
          if (*(char *)(flagCursor + 0x6c9) == '\0') goto LAB_00090efc;
          if (*(char *)(flagCursor + 0x6ca) == '\0') goto LAB_00090f7c;
          pcVar1 = (char *)(flagCursor + 0x6cb);
          flagCursor = flagCursor + 4;
          cVar2 = *pcVar1;
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

/* FUN_000911a0 @ 0x911a0 (316 bytes) */
int FUN_000911a0(param_1, param_2)
  int param_1;
  int *param_2;
{
  int iVar1;
  
  iVar1 = *param_2;
  if (iVar1 == 1) {
    *(undefined1 *)(param_2[1] * 4 + param_1 + 0x6c4) = 0;
    *(undefined1 *)(param_2[1] * 4 + param_1 + 0x6c5) = 0;
    *(undefined1 *)(param_2[1] * 4 + param_1 + 0x6c6) = 0;
    return;
  }
  if (iVar1 == 0) {
    *(undefined1 *)(param_2[1] * 4 + param_1 + 0x6c4) = 0;
    *(undefined1 *)(param_2[1] * 4 + param_1 + 0x6c5) = 0;
    *(undefined1 *)(param_2[1] * 4 + param_1 + 0x6c6) = 0;
    *(undefined1 *)(param_2[1] * 4 + param_1 + 0x6c7) = 0;
    return;
  }
  if (iVar1 != 2) {
    return;
  }
  iVar1 = param_2[6];
  if (iVar1 != 1) {
    if (iVar1 == 0) {
      *(undefined1 *)(param_2[1] * 4 + param_1 + 0x6c4) = 0;
      return;
    }
    if (iVar1 != 2) {
      if (iVar1 != 3) {
        return;
      }
      *(undefined1 *)(param_2[1] * 4 + param_1 + 0x6c7) = 0;
      return;
    }
    *(undefined1 *)(param_2[1] * 4 + param_1 + 0x6c6) = 0;
    return;
  }
  *(undefined1 *)(param_2[1] * 4 + param_1 + 0x6c5) = 0;
  return;
}

/* FUN_000912f0 @ 0x912f0 (208 bytes) */
int FUN_000912f0(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  undefined4 *param_4;
  int *param_5;
{
  uint uVar1;
  
  uVar1 = param_2 - 8;
  if (uVar1 < 2) {
    *param_4 = *(undefined4 *)(*(int *)(param_1 + 0x3ec) + 8);
    if (param_3 == 1) {
      *param_5 = *(int *)(uVar1 * 0x24 + param_1 + 0x2dc);
    }
    else if (param_3 == 0) {
      *param_5 = *(int *)(uVar1 * 0x24 + param_1 + 0x2d8);
    }
    else if (param_3 == 2) {
      *param_5 = *(int *)(uVar1 * 0x24 + param_1 + 0x2e0);
    }
    else {
      if (param_3 != 3) {
        return 4;
      }
      *param_5 = *(int *)(uVar1 * 0x24 + param_1 + 0x2ec);
    }
  }
  else {
    *param_4 = *(undefined4 *)(*(int *)(param_1 + 0x3ec) + 4);
    *param_5 = *(int *)(param_2 * 4 + param_1 + 0xc);
  }
  return (uint)(*param_5 == -1) << 1;
}

/* FUN_000913e0 @ 0x913e0 (224 bytes) */
int FUN_000913e0(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint param_2;
  undefined4 *param_3;
  int *param_4;
  undefined4 *param_5;
{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 < 2) {
    *param_3 = *(undefined4 *)(*(int *)(param_1 + 0x3ec) + 4);
    *param_4 = *(int *)(param_1 + 0x58);
  }
  else {
    if (3 < param_2) {
      return 4;
    }
    *param_3 = *(undefined4 *)(*(int *)(param_1 + 0x3ec) + 8);
    *param_4 = *(int *)((param_2 & 1) * 4 + param_1 + 800);
  }
  uVar2 = 2;
  if (*param_4 != -1) {
    iVar1 = (param_2 & 1) * 4;
    uVar2 = 0;
    *param_5 = *(undefined4 *)((PTR_DAT_001dbdd4)[*(int *)(param_1 + 0x3d8)] + iVar1);
    param_5[1] = *(undefined4 *)((PTR_DAT_001dbdd4)[*(int *)(param_1 + 0x3d8)] + iVar1);
    param_5[2] = *(undefined4 *)((PTR_DAT_001dbdd4)[*(int *)(param_1 + 0x3d8)] + iVar1);
    param_5[3] = *(undefined4 *)((PTR_DAT_001dbdd4)[*(int *)(param_1 + 0x3d8)] + iVar1);
  }
  return uVar2;
}

/* noop_914c0 @ 0x914c0 (28 bytes) */
int noop_914c0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
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

/* FUN_000914e0 @ 0x914e0 (492 bytes) */
int FUN_000914e0(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVarS1;
  int iVarS2;
  int iVarS3;
  int iVarS4;
  int iVarS5;
  int iVarS6;
  int iVarS7;
  int iVarS8;
  
  uVar1 = 0;
  iVar3 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x3f8) == -1) {
    iVar2 = ((int (*)())ffvpAllocTempRegister)(param_1,0,param_1 + 0x3f4);
    uVar1 = 7;
    if (iVar2 == 0) {
      uVar4 = **(undefined4 **)(param_1 + 0x3f0);
      uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x3ec) + 8);
      uVar5 = *(undefined4 *)(param_1 + 0x3f8);
      iVar2 = *(int *)(param_1 + 0xb4);
      iVarS1 = *(int *)((int)*(int *)((int)param_1 + 1004) + 4);
      iVarS2 = *(int *)((int)param_1 + 0);
      iVarS3 = &DAT_001dbcd4;
      (**(code **)(((unsigned char *)0x000012ec) + iVar3))
                (param_1,uVar4,uVar5,&DAT_001dbd24,uVar1,iVar2 + 3,&DAT_001dbd14,&DAT_001fa5e8,iVarS1,iVarS2,iVarS3,&DAT_001fa5e8);
      iVarS4 = *(int *)((int)*(int *)((int)param_1 + 1004) + 4);
      iVarS5 = *(int *)((int)param_1 + 0);
      iVarS6 = &DAT_001dbcf4;
      (**(code **)(((unsigned char *)0x000012f4) + iVar3))
                (param_1,uVar4,uVar5,&DAT_001dbd24,uVar1,iVar2 + 2,&DAT_001dbd14,&DAT_001fa5e8,iVarS4,iVarS5,iVarS6,&DAT_001fa5e8,uVar4,uVar5,&DAT_001dbd14,&DAT_001fa5e8);
      iVarS7 = &DAT_001dbce4;
      (**(code **)(((unsigned char *)0x000012f4) + iVar3))
                (param_1,uVar4,uVar5,&DAT_001dbd24,uVar1,iVar2 + 1,&DAT_001dbd14,&DAT_001fa5e8,iVarS4,iVarS5,iVarS7,&DAT_001fa5e8,uVar4,uVar5,&DAT_001dbd14,&DAT_001fa5e8);
      iVarS8 = &DAT_001fa5f8;
      (**(code **)(((unsigned char *)0x000012f4) + iVar3))
                (param_1,uVar4,uVar5,&DAT_001dbd24,uVar1,iVar2,&DAT_001dbd14,&DAT_001fa5e8,iVarS4,iVarS5,iVarS8,&DAT_001fa5e8,uVar4,uVar5,&DAT_001dbd14,&DAT_001fa5e8);
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* FUN_000916d0 @ 0x916d0 (420 bytes) */
int FUN_000916d0(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVarS1;
  int iVarS2;
  
  uVar1 = 0;
  iVar3 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x3f8) == -1) {
    iVar2 = ((int (*)())ffvpAllocTempRegister)(param_1,0,param_1 + 0x3f4);
    uVar1 = 7;
    if (iVar2 == 0) {
      uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x3ec) + 8);
      uVar4 = **(undefined4 **)(param_1 + 0x3f0);
      uVar5 = *(undefined4 *)(param_1 + 0x3f8);
      iVar2 = *(int *)(param_1 + 0xb4);
      iVarS1 = *(int *)((int)*(int *)((int)param_1 + 1004) + 4);
      iVarS2 = *(int *)((int)param_1 + 0);
      (**(code **)(((unsigned char *)0x000012e4) + iVar3))
                (param_1,uVar4,uVar5,&DAT_001dbd04,uVar1,iVar2,&DAT_001dbd14,&DAT_001fa5e8,iVarS1,iVarS2,&DAT_001dbd14,&DAT_001fa5e8);
      (**(code **)(((unsigned char *)0x000012e4) + iVar3))
                (param_1,uVar4,uVar5,&DAT_001dbd64,uVar1,iVar2 + 1,&DAT_001dbd14,&DAT_001fa5e8,iVarS1,iVarS2,&DAT_001dbd14,&DAT_001fa5e8);
      (**(code **)(((unsigned char *)0x000012e4) + iVar3))
                (param_1,uVar4,uVar5,&DAT_001dbd54,uVar1,iVar2 + 2,&DAT_001dbd14,&DAT_001fa5e8,iVarS1,iVarS2,&DAT_001dbd14,&DAT_001fa5e8);
      (**(code **)(((unsigned char *)0x000012e4) + iVar3))
                (param_1,uVar4,uVar5,&DAT_001dbd44,uVar1,iVar2 + 3,&DAT_001dbd14,&DAT_001fa5e8,iVarS1,iVarS2,&DAT_001dbd14,&DAT_001fa5e8);
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* FUN_00091880 @ 0x91880 (248 bytes) */
int FUN_00091880(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int a5;
  
  uVar1 = 0;
  iVar3 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x510) == -1) {
    a5 = *(int *)(param_1 + 0x3f8);
    if (a5 == -1) {
      if ((*(uint *)(((unsigned char *)0x000013c0) + iVar3) & 4) == 0) {
        ((int (*)())FUN_000916d0)(param_1);
      }
      else {
        ((int (*)())FUN_000914e0)(param_1);
      }
      a5 = *(int *)(param_1 + 0x3f8);
      if (a5 == -1) {
        return 2;
      }
    }
    iVar2 = ((int (*)())ffvpAllocTempRegister)(param_1,2,param_1 + 0x50c);
    uVar1 = 7;
    if (iVar2 == 0) {
      (**(code **)(((unsigned char *)0x000012e4) + iVar3))
                (param_1,**(undefined4 **)(param_1 + 0x3f0),*(undefined4 *)(param_1 + 0x510),
                 param_1 + 0x514,**(undefined4 **)(param_1 + 0x3ec),a5,&DAT_001dbd74,&DAT_001fa5e8,**(undefined4 **)(param_1 + 0x3ec),a5,&DAT_001dbd74,&DAT_001fa5e8);
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* FUN_00091980 @ 0x91980 (176 bytes) */
int FUN_00091980(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = 0;
  iVar3 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x6a0) == -1) {
    iVar2 = ((int (*)())ffvpAllocTempRegister)(param_1,2,param_1 + 0x69c);
    uVar1 = 7;
    if (iVar2 == 0) {
      (**(code **)(((unsigned char *)0x00001314) + iVar3))
                (param_1,**(undefined4 **)(param_1 + 0x3f0),*(undefined4 *)(param_1 + 0x6a0),
                 param_1 + 0x6a4,param_2,param_3,&DAT_001dbcd4,&DAT_001fa5e8);
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* FUN_00091a30 @ 0x91a30 (352 bytes) */
int FUN_00091a30(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVarS1;
  int iVarS2;
  
  uVar1 = 0;
  iVar3 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x448) == -1) {
    iVar2 = ((int (*)())ffvpAllocTempRegister)(param_1,1,param_1 + 0x444);
    uVar1 = 7;
    if (iVar2 == 0) {
      uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x3ec) + 8);
      uVar4 = **(undefined4 **)(param_1 + 0x3f0);
      uVar5 = *(undefined4 *)(param_1 + 0x448);
      iVar2 = *(int *)(param_1 + 0xc4);
      iVarS1 = *(int *)((int)*(int *)((int)param_1 + 1004) + 4);
      iVarS2 = *(int *)((int)param_1 + 4);
      (**(code **)(((unsigned char *)0x000012e4) + iVar3))
                (param_1,uVar4,uVar5,&DAT_001dbd04,uVar1,iVar2,&DAT_001dbd74,&DAT_001fa5e8,iVarS1,iVarS2,&DAT_001dbd74,&DAT_001fa5e8);
      (**(code **)(((unsigned char *)0x000012e4) + iVar3))
                (param_1,uVar4,uVar5,&DAT_001dbd64,uVar1,iVar2 + 1,&DAT_001dbd74,&DAT_001fa5e8,iVarS1,iVarS2,&DAT_001dbd74,&DAT_001fa5e8);
      (**(code **)(((unsigned char *)0x000012e4) + iVar3))
                (param_1,uVar4,uVar5,&DAT_001dbd54,uVar1,iVar2 + 2,&DAT_001dbd74,&DAT_001fa5e8,iVarS1,iVarS2,&DAT_001dbd74,&DAT_001fa5e8);
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* FUN_00091b90 @ 0x91b90 (460 bytes) */
int FUN_00091b90(param_1)
  int param_1;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined1 auStack_68 [4];
  undefined4 local_64;
  undefined1 auStack_60 [16];
  undefined1 auStack_50 [32];
  int iVarS1;
  
  iVar3 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x498) != -1) {
    return 0;
  }
  if (*(char *)(iVar3 + 0x12a) == '\0') {
    iVar4 = *(int *)(param_1 + 4);
    uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x3ec) + 4);
    iVar1 = ((int (*)())ffvpAllocTempRegister)(param_1,1,param_1 + 0x494);
    if (iVar1 != 0) {
      return 7;
    }
  }
  else {
    iVar4 = *(int *)(param_1 + 0x448);
    if (iVar4 == -1) {
      ((int (*)())FUN_00091a30)(param_1);
      iVar4 = *(int *)(param_1 + 0x448);
      if (iVar4 == -1) {
        return 2;
      }
    }
    uVar2 = **(undefined4 **)(param_1 + 0x3ec);
    _memcpy(param_1 + 0x494,param_1 + 0x444,0x28);
  }
  iVar1 = ((int (*)())ffvpAllocTempRegister)(param_1,2,auStack_68);
  if (iVar1 != 0) {
    return 7;
  }
  uVar7 = **(undefined4 **)(param_1 + 0x3f0);
  uVar5 = **(undefined4 **)(param_1 + 0x3ec);
  uVar6 = *(undefined4 *)(param_1 + 0x498);
  (**(code **)(((unsigned char *)0x000012e4) + iVar3))
            (param_1,uVar7,local_64,auStack_60,uVar2,iVar4,&DAT_001dbd74,&DAT_001fa5e8,uVar2,iVar4,&DAT_001dbd74,&DAT_001fa5e8);
  (**(code **)(((unsigned char *)0x00001318) + iVar3))
            (param_1,uVar7,local_64,auStack_60,uVar5,local_64,auStack_50,&DAT_001fa5e8);
  iVarS1 = &DAT_001dbd74;
  (**(code **)(((unsigned char *)0x000012ec) + iVar3))
            (param_1,uVar7,uVar6,&DAT_001dbd84,uVar5,local_64,auStack_50,&DAT_001fa5e8,uVar2,iVar4,iVarS1,&DAT_001fa5e8);
  ((int (*)())FUN_000911a0)(param_1,auStack_68);
  return 0;
}

/* FUN_00091d70 @ 0x91d70 (300 bytes) */
int FUN_00091d70(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int iVarS1;
  
  iVar2 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x470) == -1) {
    if (*(char *)(iVar2 + 0x12a) == '\0') {
      iVar1 = ((int (*)())ffvpAllocTempRegister)(param_1,2,param_1 + 0x46c);
      if (iVar1 != 0) {
        return 7;
      }
    }
    else {
      if ((*(int *)(param_1 + 0x448) == -1) &&
         (((int (*)())FUN_00091a30)(param_1), *(int *)(param_1 + 0x448) == -1)) {
        return 2;
      }
      _memcpy(param_1 + 0x46c,param_1 + 0x444,0x28);
    }
    iVarS1 = &DAT_001dbd74;
    (**(code **)(((unsigned char *)0x000012ec) + iVar2))
              (param_1,**(undefined4 **)(param_1 + 0x3f0),*(undefined4 *)(param_1 + 0x470),
               &DAT_001dbd84,*(undefined4 *)(*(int *)(param_1 + 0x3ec) + 8),
               *(undefined4 *)(param_1 + 0x344),&DAT_001fa5f8,&DAT_001fa5e8,(*(char *)(iVar2 + 0x12a) == '\0' ? (*(int **)(param_1 + 0x3ec))[1] : **(int **)(param_1 + 0x3ec)),(*(char *)(iVar2 + 0x12a) == '\0' ? *(int *)(param_1 + 4) : *(int *)(param_1 + 0x448)),iVarS1,&DAT_001fa5e8);
  }
  return 0;
}

/* FUN_00091eb0 @ 0x91eb0 (648 bytes) */
int FUN_00091eb0(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  int param_3;
{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  int iVarS1;
  int iVarS2;
  
  uVar1 = 0;
  iVar6 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x560) == -1) {
    iVar2 = ((int (*)())ffvpAllocTempRegister)(param_1,0,param_1 + 0x55c);
    uVar1 = 7;
    if (iVar2 == 0) {
      uVar5 = *(undefined4 *)(param_1 + 0x560);
      uVar3 = *(undefined4 *)(param_1 + 0x5c);
      uVar4 = **(undefined4 **)(param_1 + 0x3f0);
      uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x3ec) + 4);
      if (param_2 < 4) {
        if (param_3 == 0) {
          (**(code **)(((unsigned char *)0x000012e8) + iVar6))
                    (param_1,uVar4,uVar5,&DAT_001dbd24,uVar1,uVar3,&DAT_001dbd74,&DAT_001fa5e8);
          uVar1 = 0;
        }
        else {
          local_58 = DAT_001fa608;
          local_48 = DAT_001dbd74;
          local_54 = DAT_001fa60c;
          local_4c = DAT_001fa614;
          local_50 = DAT_001fa610;
          local_3c = DAT_001dbd80;
          local_44 = DAT_001dbd78;
          local_40 = DAT_001dbd7c;
          if (param_2 == 1) {
            local_40 = 4;
            local_44 = 4;
            local_54 = 1;
          }
          else if (param_2 == 0) {
            local_40 = 4;
            local_58 = 1;
            local_48 = 4;
            local_44 = 4;
          }
          else if (param_2 == 2) {
            local_50 = 1;
            local_40 = 4;
          }
          else if (param_2 == 3) {
            local_4c = 1;
          }
          local_30 = 1;
          local_38 = 1;
          local_34 = 1;
          local_2c = 0;
          (**(code **)(((unsigned char *)0x000012e8) + iVar6))
                    (param_1,uVar4,uVar5,&DAT_001dbd24,uVar1,uVar3,&local_48,&DAT_001fa5e8);
          iVarS1 = ((unsigned char *)&DAT_001dbdc0 + 4);
          iVarS2 = &DAT_001fa5e8;
          (**(code **)(((unsigned char *)0x000012e4) + iVar6))
                    (param_1,uVar4,uVar5,&local_58,**(undefined4 **)(param_1 + 0x3ec),uVar5,
                     &DAT_001dbdb4,&local_38,**(undefined4 **)(param_1 + 0x3ec),uVar5,iVarS1,iVarS2);
          uVar1 = 0;
        }
      }
      else {
        (**(code **)(((unsigned char *)0x000012e8) + iVar6))
                  (param_1,uVar4,uVar5,&DAT_001dbd24,uVar1,uVar3,&DAT_001dbd14,&DAT_001fa5e8);
        uVar1 = 0;
      }
    }
  }
  return uVar1;
}

/* FUN_00092150 @ 0x92150 (200 bytes) */
int FUN_00092150(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = 0;
  iVar3 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x538) == -1) {
    iVar4 = *(int *)(param_1 + 0x510);
    if (iVar4 == -1) {
      ((int (*)())FUN_00091880)(param_1);
      iVar4 = *(int *)(param_1 + 0x510);
      if (iVar4 == -1) {
        return 2;
      }
    }
    iVar2 = ((int (*)())ffvpAllocTempRegister)(param_1,2,param_1 + 0x534);
    uVar1 = 7;
    if (iVar2 == 0) {
      (**(code **)(((unsigned char *)0x00001318) + iVar3))
                (param_1,**(undefined4 **)(param_1 + 0x3f0),*(undefined4 *)(param_1 + 0x538),
                 param_1 + 0x53c,**(undefined4 **)(param_1 + 0x3ec),iVar4,param_1 + 0x524,
                 &DAT_001fa5e8);
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* FUN_00092220 @ 0x92220 (296 bytes) */
int FUN_00092220(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int a5;
  int iVarS1;
  int iVarS2;
  
  iVar3 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x420) != -1) {
    return 0;
  }
  a5 = *(int *)(param_1 + 0x538);
  if (a5 == -1) {
    ((int (*)())FUN_00092150)(param_1);
    a5 = *(int *)(param_1 + 0x538);
    if (a5 != -1) goto LAB_0009226c;
LAB_00092320:
    uVar1 = 2;
  }
  else {
LAB_0009226c:
    if (*(int *)(param_1 + 0x3f8) == -1) {
      if ((*(uint *)(((unsigned char *)0x000013c0) + iVar3) & 4) == 0) {
        ((int (*)())FUN_000916d0)(param_1);
      }
      else {
        ((int (*)())FUN_000914e0)(param_1);
      }
      if (*(int *)(param_1 + 0x3f8) == -1) goto LAB_00092320;
    }
    iVar2 = ((int (*)())ffvpAllocTempRegister)(param_1,1,param_1 + 0x41c);
    uVar1 = 7;
    if (iVar2 == 0) {
      iVarS1 = *(int *)((int)param_1 + 1016);
      iVarS2 = &DAT_001dbd74;
      (**(code **)(((unsigned char *)0x000012ec) + iVar3))
                (param_1,**(undefined4 **)(param_1 + 0x3f0),*(undefined4 *)(param_1 + 0x420),
                 &DAT_001dbd84,**(undefined4 **)(param_1 + 0x3ec),a5,param_1 + 0x54c,&DAT_001fa5e8,**(undefined4 **)(param_1 + 0x3ec),iVarS1,iVarS2,&DAT_001fa5e8);
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* FUN_00092350 @ 0x92350 (512 bytes) */
int FUN_00092350(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined1 auStack_68 [4];
  undefined4 local_64;
  undefined1 auStack_60 [16];
  undefined1 auStack_50 [40];
  int iVarS1;
  int iVarS2;
  int iVarS3;
  
  iVar2 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x4c0) != -1) {
    return 0;
  }
  iVar3 = *(int *)(param_1 + 0x420);
  if (iVar3 == -1) {
    ((int (*)())FUN_00092220)(param_1);
    iVar3 = *(int *)(param_1 + 0x420);
    if (iVar3 == -1) {
      return 2;
    }
  }
  if (*(char *)(iVar2 + 0x128) == '\0') {
    if (*(char *)(iVar2 + 300) == '\0') {
      if (*(int *)(param_1 + 0x448) != -1) goto LAB_00092420;
      ((int (*)())FUN_00091a30)(param_1);
      iVar4 = *(int *)(param_1 + 0x448);
    }
    else {
      if (*(int *)(param_1 + 0x470) != -1) goto LAB_00092420;
      ((int (*)())FUN_00091d70)(param_1);
      iVar4 = *(int *)(param_1 + 0x470);
    }
  }
  else {
    if (*(int *)(param_1 + 0x498) != -1) goto LAB_00092420;
    ((int (*)())FUN_00091b90)(param_1);
    iVar4 = *(int *)(param_1 + 0x498);
  }
  if (iVar4 == -1) {
    return 2;
  }
LAB_00092420:
  iVar4 = ((int (*)())ffvpAllocTempRegister)(param_1,1,param_1 + 0x4bc);
  if (iVar4 == 0) {
    uVar1 = *(undefined4 *)(param_1 + 0x4c0);
    iVar4 = ((int (*)())ffvpAllocTempRegister)(param_1,2,auStack_68);
    if (iVar4 == 0) {
      uVar6 = **(undefined4 **)(param_1 + 0x3ec);
      uVar5 = **(undefined4 **)(param_1 + 0x3f0);
      (**(code **)(((unsigned char *)0x000012e4) + iVar2))
                (param_1,uVar5,local_64,auStack_60,uVar6,iVar3,&DAT_001dbd74,&DAT_001fa5e8,uVar6,(*(char *)(iVar2 + 0x128) == '\0' ? (*(char *)(iVar2 + 300) == '\0' ? *(int *)(param_1 + 0x448) : *(int *)(param_1 + 0x470)) : *(int *)(param_1 + 0x498)),&DAT_001dbd74,&DAT_001fa5e8);
      iVarS1 = &DAT_001dbd74;
      iVarS2 = &DAT_001dbd94;
      iVarS3 = *(int *)((int)param_1 + 1056);
      (**(code **)(((unsigned char *)0x000012f8) + iVar2))
                (param_1,uVar5,uVar1,&DAT_001dbd84,uVar6,local_64,auStack_50,&DAT_001fa5e8,uVar6,(*(char *)(iVar2 + 0x128) == '\0' ? (*(char *)(iVar2 + 300) == '\0' ? *(int *)(param_1 + 0x448) : *(int *)(param_1 + 0x470)) : *(int *)(param_1 + 0x498)),iVarS1,iVarS2,uVar6,iVarS3,iVarS1,&DAT_001fa5e8);
      ((int (*)())FUN_000911a0)(param_1,auStack_68);
      return 0;
    }
  }
  return 7;
}

/* FUN_00092570 @ 0x92570 (796 bytes) */
int FUN_00092570(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined1 auStack_a8 [4];
  undefined4 local_a4;
  undefined1 auStack_a0 [16];
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined1 auStack_80 [4];
  undefined4 local_7c;
  undefined1 auStack_78 [16];
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_5c;
  int iVarS1;
  int iVarS2;
  int iVarS3;
  int iVarS4;
  int iVarS5;
  int iVarS6;
  int iVarS7;
  
  uVar1 = 0;
  iVar3 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x4e8) == -1) {
    if ((*(int *)(param_1 + 0x4c0) == -1) &&
       (((int (*)())FUN_00092350)(param_1), *(int *)(param_1 + 0x4c0) == -1)) {
      return 2;
    }
    iVar2 = ((int (*)())ffvpAllocTempRegister)(param_1,1,param_1 + 0x4e4);
    if (iVar2 == 0) {
      uVar1 = *(undefined4 *)(param_1 + 0x4e8);
      iVar2 = ((int (*)())ffvpAllocTempRegister)(param_1,2,auStack_a8);
      if (iVar2 == 0) {
        iVar2 = ((int (*)())ffvpAllocTempRegister)(param_1,2,auStack_80);
        if (iVar2 == 0) {
          uVar5 = **(undefined4 **)(param_1 + 0x3ec);
          uVar4 = **(undefined4 **)(param_1 + 0x3f0);
          (**(code **)(((unsigned char *)0x000012f0) + iVar3))
                    (param_1,uVar4,local_a4,auStack_a0,uVar5,local_a4,&DAT_001dbdb4,&DAT_001fa5e8,uVar5,local_a4,&DAT_001dbdb4,&DAT_001fa5e8);
          local_d8 = 4;
          local_d4 = 4;
          local_cc = 4;
          local_d0 = local_88;
          iVarS1 = *(int *)((int)param_1 + 1216);
          iVarS2 = &DAT_001dbd74;
          iVarS3 = &local_d8;
          (**(code **)(((unsigned char *)0x000012f4) + iVar3))
                    (param_1,uVar4,uVar1,&DAT_001dbd84,uVar5,local_a4,&local_90,&DAT_001fa5e8,uVar5,iVarS1,iVarS2,&DAT_001fa5e8,uVar5,local_a4,iVarS3,&DAT_001fa5e8);
          (**(code **)(((unsigned char *)0x000012e4) + iVar3))
                    (param_1,uVar4,local_a4,auStack_a0,uVar5,uVar1,&DAT_001dbd74,&DAT_001fa5e8,uVar5,uVar1,&DAT_001dbd74,&DAT_001fa5e8);
          (**(code **)(((unsigned char *)0x00001318) + iVar3))
                    (param_1,uVar4,local_a4,auStack_a0,uVar5,local_a4,&local_90,&DAT_001fa5e8);
          (**(code **)(((unsigned char *)0x0000131c) + iVar3))
                    (param_1,uVar4,local_7c,auStack_78,uVar5,local_7c,&DAT_001dbdb4,&DAT_001dbd94);
          local_c8 = *(undefined4 *)(param_1 + 0x4d4);
          local_c4 = *(undefined4 *)(param_1 + 0x4d8);
          local_b0 = 4;
          local_d0 = 4;
          local_cc = 4;
          local_d8 = local_90;
          local_d4 = local_8c;
          local_c0 = 4;
          local_bc = 4;
          local_b8 = local_68;
          local_b4 = local_64;
          local_ac = local_5c;
          iVarS4 = *(int *)((int)param_1 + 1216);
          iVarS5 = &local_c8;
          iVarS6 = local_7c;
          iVarS7 = &local_b8;
          (**(code **)(((unsigned char *)0x000012f4) + iVar3))
                    (param_1,uVar4,uVar1,&DAT_001dbd84,uVar5,local_a4,&local_d8,&DAT_001fa5e8,uVar5,iVarS4,iVarS5,&DAT_001fa5e8,uVar5,iVarS6,iVarS7,&DAT_001fa5e8);
          ((int (*)())FUN_000911a0)(param_1,auStack_a8);
          ((int (*)())FUN_000911a0)(param_1,auStack_80);
          return 0;
        }
      }
    }
    uVar1 = 7;
  }
  return uVar1;
}

/* FUN_000928a0 @ 0x928a0 (792 bytes) */
int FUN_000928a0(param_1)
  int param_1;
{
  int iVar1;
  undefined4 *puVar2;
  int a5;
  undefined4 uVar3;
  int iVar4;
  undefined4 a4;
  undefined4 uVar5;
  undefined4 a1;
  undefined4 uVar6;
  int iVar7;
  undefined1 auStack_68 [4];
  undefined4 local_64;
  undefined1 auStack_60 [16];
  undefined1 auStack_50 [32];
  int iVarS1;
  int iVarS2;
  
  uVar3 = 0;
  iVar7 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x588) == -1) {
    puVar2 = *(undefined4 **)(param_1 + 0x3ec);
    uVar3 = *(undefined4 *)(param_1 + 0x330);
    a1 = **(undefined4 **)(param_1 + 0x3f0);
    a4 = puVar2[2];
    if (*(short *)(((unsigned char *)0x00002e06) + *(int *)(*(int *)(iVar7 + 4) + 0x10)) == -0x7bae) {
      a5 = *(int *)(param_1 + 0x3f8);
      if (a5 == -1) {
        if ((*(uint *)(((unsigned char *)0x000013c0) + iVar7) & 4) == 0) {
          ((int (*)())FUN_000916d0)(param_1);
        }
        else {
          ((int (*)())FUN_000914e0)(param_1);
        }
        a5 = *(int *)(param_1 + 0x3f8);
        if (a5 == -1) {
          return 2;
        }
        puVar2 = *(undefined4 **)(param_1 + 0x3ec);
      }
      uVar6 = *puVar2;
      puVar2 = &DAT_001dbcf4;
    }
    else {
      iVar1 = *(int *)(param_1 + 0x54);
      uVar6 = puVar2[1];
      a5 = *(int *)(param_1 + 0x50);
      if (iVar1 == 1) {
        puVar2 = &DAT_001dbce4;
      }
      else if (iVar1 == 0) {
        puVar2 = &DAT_001fa5f8;
      }
      else if (iVar1 == 2) {
        puVar2 = &DAT_001dbcf4;
      }
      else if (iVar1 == 3) {
        puVar2 = &DAT_001dbcd4;
      }
      else {
        puVar2 = &DAT_001dbd14;
      }
    }
    iVar1 = ((int (*)())ffvpAllocTempRegister)(param_1,2,param_1 + 0x584);
    if (iVar1 == 0) {
      uVar5 = *(undefined4 *)(param_1 + 0x588);
      iVar1 = ((int (*)())ffvpAllocTempRegister)(param_1,2,auStack_68);
      if (iVar1 == 0) {
        iVar4 = *(int *)(param_1 + 0x3d4);
        iVar1 = *(int *)(*(int *)(iVar4 + 4) + 0x10);
        if ((*(short *)(((unsigned char *)0x00002e06) + iVar1) == -0x7bae) &&
           (*(short *)(((unsigned char *)0x00002e08) + iVar1) == -0x7aa5)) {
          (**(code **)(((unsigned char *)0x000012e4) + iVar4))
                    (param_1,a1,local_64,auStack_60,uVar6,a5,&DAT_001dbd74,&DAT_001fa5e8,uVar6,a5,&DAT_001dbd74,&DAT_001fa5e8);
        }
        else {
          (**(code **)(((unsigned char *)0x000012ec) + iVar4))
                    (param_1,a1,local_64,auStack_60,uVar6,a5,puVar2,&DAT_001fa5e8,uVar6,a5,puVar2,&DAT_001fa5e8);
        }
        uVar6 = **(undefined4 **)(param_1 + 0x3ec);
        iVarS1 = *(int *)((int)*(int *)((int)param_1 + 1004) + 0);
        iVarS2 = &auStack_50;
        (**(code **)(((unsigned char *)0x000012ec) + iVar7))
                  (param_1,a1,local_64,auStack_60,a4,uVar3,&DAT_001dbcf4,&DAT_001fa5e8,iVarS1,local_64,iVarS2,&DAT_001fa5e8);
        if (*(int *)(param_1 + 0x3d8) == 0) {
          puVar2 = (undefined4 *)(param_1 + 0x58c);
          if (-1 < *(int *)(iVar7 + 0x44)) {
            uVar5 = *(undefined4 *)(param_1 + 0x70);
            puVar2 = &DAT_001dbd44;
            a1 = *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x18);
          }
        }
        else {
          uVar5 = *(undefined4 *)(param_1 + 0x70);
          puVar2 = &DAT_001dbd04;
          a1 = *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x18);
        }
        (**(code **)(((unsigned char *)0x00001320) + iVar7))
                  (param_1,a1,uVar5,puVar2,uVar6,local_64,auStack_50,&DAT_001fa5e8);
        ((int (*)())FUN_000911a0)(param_1,auStack_68);
        return 0;
      }
    }
    uVar3 = 7;
  }
  return uVar3;
}

/* FUN_00092bf0 @ 0x92bf0 (328 bytes) */
int FUN_00092bf0(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  undefined4 param_3;
{
  int iVar1;
  
  iVar1 = 0;
  if (param_2 < 3) {
    iVar1 = (**(code **)(param_1 + 0xc))(0x1998);
    *(int *)(iVar1 + 0x3d4) = param_1;
    _memset(iVar1,0xffffffff,0x68);
    _memset(iVar1 + 0x68,0xffffffff,0x3c);
    _memset(iVar1 + 0xa4,0xffffffff,0x324);
    *(uint *)(iVar1 + 0x3d8) = param_2;
    *(undefined4 *)(iVar1 + 0x3e0) = 0;
    *(undefined4 *)(iVar1 + 0x3c8) = 0;
    *(undefined4 *)(iVar1 + 0x3cc) = 0;
    *(undefined4 *)(iVar1 + 0x3d0) = 0;
    *(undefined4 *)(iVar1 + 0x3e4) = *(undefined4 *)(&DAT_001dbeac + param_2 * 4);
    *(undefined4 *)(iVar1 + 1000) = *(undefined4 *)(&DAT_001dbea4 + param_2 * 4);
    *(undefined **)(iVar1 + 0x3ec) = (PTR_DAT_001dbe84)[param_2];
    *(undefined **)(iVar1 + 0x3f0) = (PTR_DAT_001dbe3c)[param_2];
    _memset(iVar1 + 0x3f4,0xffffffff,0x2d0);
    _memset(iVar1 + 0x6c4,0,0x80);
    *(undefined1 *)(iVar1 + 0x744) = (undefined1)param_3;
    *(code **)(iVar1 + 0x748) = ffvpAllocTempRegister;
    *(code **)(iVar1 + 0x74c) = FUN_000911a0;
    if (*(code **)(((unsigned char *)0x000012d4) + param_1) != (code *)0x0) {
      (**(code **)(((unsigned char *)0x000012d4) + param_1))(param_1,iVar1);
    }
  }
  return iVar1;
}

/* FUN_00092d40 @ 0x92d40 (340 bytes) */
int FUN_00092d40(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  uint param_3;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_1 == (int *)0x0) {
    return 1;
  }
  if ((param_1[0x1a] != -1) && (iVar3 = *param_1, iVar3 != -1)) {
    if (param_2 != 0) {
      if (7 < param_3) {
        return 3;
      }
      if (param_1[param_3 + 0x21] == -1) {
        return 2;
      }
    }
    iVar1 = param_1[0xf5];
    uVar2 = *(undefined4 *)(param_1[0xfb] + 4);
    (**(code **)(((unsigned char *)0x000012e8) + iVar1))
              (param_1,*(undefined4 *)(param_1[0xfc] + 8),param_1[0x1a],&DAT_001dbd24,uVar2,iVar3,
               &DAT_001dbd14,&DAT_001fa5e8);
    if (((*(char *)(param_1 + 0x1d1) == '\0') || (param_1[0x1a8] != -1)) ||
       (((int (*)())FUN_00091980)(param_1,uVar2,iVar3), param_1[0x1a8] != -1)) {
      if (param_2 != 0) {
        (**(code **)(((unsigned char *)0x000012e8) + iVar1))
                  (param_1,*(undefined4 *)(param_1[0xfc] + 0x14),param_1[param_3 + 0x21],
                   &DAT_001dbd24,uVar2,iVar3,&DAT_001dbd14,&DAT_001fa5e8);
      }
      return 0;
    }
  }
  return 2;
}

/* FUN_00092ea0 @ 0x92ea0 (324 bytes) */
int FUN_00092ea0(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  uint param_4;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  
  if (param_1 == 0) {
    return 1;
  }
  if (param_2 == 3) {
    if (1 < param_4) {
      return 3;
    }
    iVar3 = *(int *)(param_4 * 4 + param_1 + 0x74);
    if ((iVar3 == -1) || (iVar5 = *(int *)(param_3 * 4 + param_1 + 0xc), iVar5 == -1)) {
      return 2;
    }
    iVar1 = *(int *)(param_1 + 0x3d8);
    iVar6 = *(int *)(param_1 + 0x3d4);
    uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0xc);
  }
  else {
    if (1 < param_4) {
      return 3;
    }
    iVar3 = *(int *)(param_4 * 4 + param_1 + 0x7c);
    if (iVar3 == -1) {
      return 2;
    }
    iVar5 = *(int *)(param_3 * 4 + param_1 + 0xc);
    if (iVar5 == -1) {
      return 2;
    }
    iVar1 = *(int *)(param_1 + 0x3d8);
    iVar6 = *(int *)(param_1 + 0x3d4);
    uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x10);
  }
  if ((iVar1 == 0) && (iVar3 == *(int *)(param_1 + 0x70))) {
    puVar4 = &DAT_001dbd84;
  }
  else {
    puVar4 = &DAT_001dbd24;
  }
  (**(code **)(((unsigned char *)0x000012e8) + iVar6))
            (param_1,uVar2,iVar3,puVar4,*(undefined4 *)(*(int *)(param_1 + 0x3ec) + 4),iVar5,
             &DAT_001dbd14,&DAT_001fa5e8);
  return 0;
}

/* FUN_00093000 @ 0x93000 (288 bytes) */
int FUN_00093000(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  uint param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  bool bVar1;
  int iVar2;
  undefined4 a1;
  int a2;
  undefined4 a4;
  
  if (param_1 == 0) {
    return 1;
  }
  if (7 < param_2) {
    return 3;
  }
  iVar2 = param_2 * 4 + param_1;
  a2 = *(int *)(iVar2 + 0x84);
  if (((a2 != -1) && (iVar2 = *(int *)(iVar2 + 0x2c), iVar2 != -1)) &&
     ((bVar1 = *(char *)(param_1 + 0x744) == '\0', bVar1 || (*(int *)(param_1 + 0xa4) != -1)))) {
    a1 = *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x14);
    a4 = *(undefined4 *)(*(int *)(param_1 + 0x3ec) + 4);
    if (bVar1) {
      (**(code **)(((unsigned char *)0x000012e8) + *(int *)(param_1 + 0x3d4)))
                (param_1,a1,a2,&DAT_001dbd24,a4,iVar2,&DAT_001dbd14,&DAT_001fa5e8);
      return 0;
    }
    if (*(int *)(param_1 + 0x6a0) != -1) {
      (**(code **)(((unsigned char *)0x000012ec) + *(int *)(param_1 + 0x3d4)))
                (param_1,a1,a2,&DAT_001dbd24,a4,iVar2,&DAT_001dbd14,&DAT_001fa5e8,**(int **)(param_1 + 0x3ec),*(int *)(param_1 + 0x6a0),(int)param_1 + 1716,&DAT_001fa5e8);
      return 0;
    }
  }
  return 2;
}

/* FUN_00093130 @ 0x93130 (168 bytes) */
int FUN_00093130(param_1)
  int param_1;
{
  undefined4 uVar1;
  
  uVar1 = 1;
  if (param_1 != 0) {
    if ((*(int *)(param_1 + 0x6c) == -1) || (*(int *)(param_1 + 0x4c) == -1)) {
      uVar1 = 2;
    }
    else {
      (**(code **)(((unsigned char *)0x000012e8) + *(int *)(param_1 + 0x3d4)))
                (param_1,*(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x1c),*(int *)(param_1 + 0x6c),
                 &DAT_001dbd24,*(undefined4 *)(*(int *)(param_1 + 0x3ec) + 4),
                 *(int *)(param_1 + 0x4c),&DAT_001fa5f8,&DAT_001fa5e8);
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* FUN_000931e0 @ 0x931e0 (404 bytes) */
int FUN_000931e0(param_1)
  int param_1;
{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  uVar3 = 1;
  if (param_1 != 0) {
    iVar1 = *(int *)(param_1 + 0x70);
    if ((iVar1 == -1) || (*(int *)(param_1 + 0x50) == -1)) {
      uVar3 = 2;
    }
    else if ((*(uint *)(param_1 + 0x54) < 4) &&
            ((((*(int *)(param_1 + 0x3d8) != 0 || (iVar1 == *(int *)(param_1 + 0x74))) ||
              (iVar1 == *(int *)(param_1 + 0x78))) ||
             ((iVar1 == *(int *)(param_1 + 0x7c) || (iVar1 == *(int *)(param_1 + 0x80))))))) {
      uVar3 = 0;
      *(undefined1 *)(*(int *)(param_1 + 0x3d4) + 0x12e) = 1;
      if (-1 < *(int *)(*(int *)(param_1 + 0x3d4) + 0x44)) {
        iVar1 = *(int *)(param_1 + 0x54);
        if (iVar1 == 1) {
          puVar4 = &DAT_001dbce4;
        }
        else if (iVar1 == 0) {
          puVar4 = &DAT_001fa5f8;
        }
        else if (iVar1 == 2) {
          puVar4 = &DAT_001dbcf4;
        }
        else if (iVar1 == 3) {
          puVar4 = &DAT_001dbcd4;
        }
        else {
          puVar4 = &DAT_001dbd14;
        }
        if (*(int *)(param_1 + 0x3d8) == 0) {
          puVar2 = &DAT_001dbd44;
        }
        else {
          puVar2 = &DAT_001dbd04;
        }
        (**(code **)(((unsigned char *)0x000012e8) + *(int *)(param_1 + 0x3d4)))
                  (param_1,*(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x18),
                   *(undefined4 *)(param_1 + 0x70),puVar2,
                   *(undefined4 *)(*(int *)(param_1 + 0x3ec) + 4),*(undefined4 *)(param_1 + 0x50),
                   puVar4,&DAT_001fa5e8);
        uVar3 = 0;
      }
    }
    else {
      uVar3 = 3;
    }
  }
  return uVar3;
}

/* FUN_00093390 @ 0x93390 (352 bytes) */
int FUN_00093390(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined1 auStack_68 [4];
  undefined4 uStack_64;
  int iVarS1;
  
  uVar1 = 1;
  if ((param_1 != 0) && (uVar1 = 2, *(int *)(param_1 + 8) != -1)) {
    iVar3 = *(int *)(param_1 + 0x3d4);
    iVar2 = ((int (*)())ffvpAllocTempRegister)(param_1,0,auStack_68);
    uVar1 = 7;
    if (iVar2 == 0) {
      uVar5 = *(undefined4 *)(param_1 + 8);
      uVar6 = (*(undefined4 **)(param_1 + 0x3ec))[1];
      uVar4 = **(undefined4 **)(param_1 + 0x3f0);
      uVar1 = **(undefined4 **)(param_1 + 0x3ec);
      (**(code **)(((unsigned char *)0x000012e4) + iVar3))
                (param_1,uVar4,uStack_64,&DAT_001dbd24,uVar6,uVar5,&DAT_001dbdb4,&DAT_001fa5e8,uVar6,uVar5,&DAT_001dbdb4,&DAT_001fa5e8);
      iVarS1 = *(int *)((int)*(int *)((int)param_1 + 1004) + 0);
      (**(code **)(((unsigned char *)0x000012ec) + iVar3))
                (param_1,uVar4,uStack_64,&DAT_001dbd24,uVar6,uVar5,&DAT_001dbd14,&DAT_001fa5e8,iVarS1,uStack_64,&DAT_001dbd14,&DAT_001fa5e8);
      (**(code **)(((unsigned char *)0x00001310) + iVar3))
                (param_1,*(undefined4 *)(*(int *)(param_1 + 0x3f0) + 4),0,&DAT_001dbd24,uVar1,
                 uStack_64,&DAT_001dbd14,&DAT_001fa5e8);
      ((int (*)())FUN_000911a0)(param_1,auStack_68);
      uVar1 = 0;
    }
  }
  return uVar1;
}


/* issue: auto-generated aliases bridging data.s/code.s references (written
 * without a leading underscore, matching the raw stock-binary symbol name)
 * against the real compiled C symbols (gcc adds one underscore automatically).
 * Needed because ld64 (required for this PPC binary's size - stock ld breaks on
 * large PPC links) does not silently reconcile this the way stock ld did. */
asm(".globl FUN_0008fb70");
asm(".set FUN_0008fb70, _FUN_0008fb70");
asm(".globl FUN_000900a0");
asm(".set FUN_000900a0, _FUN_000900a0");
asm(".globl FUN_00090470");
asm(".set FUN_00090470, _gldValidateState");
