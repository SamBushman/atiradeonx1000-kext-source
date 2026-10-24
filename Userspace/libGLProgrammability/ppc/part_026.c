#include "decls.h"

/* __Unwind_FindEnclosingFunction @ 0x97c1a5e4 (56 bytes) */
int __Unwind_FindEnclosingFunction(pc)
  void *pc;
{
  void *unwind_Find_FDEResult;
  void *functionStart;
  dwarf_eh_bases ehBases [2];
  
  unwind_Find_FDEResult = ((int (*)())__Unwind_Find_FDE)((void *)((int)pc + -1),ehBases);
  functionStart = (void *)0x0;
  if (unwind_Find_FDEResult != (void *)0x0) {
    functionStart = (void *)ehBases[0].func;
  }
  return functionStart;
}

/* __Unwind_GetDataRelBase @ 0x97c1a61c (8 bytes) */
int __Unwind_GetDataRelBase(context)
  unsigned char * context;
{
  return *(unsigned char *)(context + 0x1cc);
}

/* __Unwind_GetTextRelBase @ 0x97c1a624 (8 bytes) */
int __Unwind_GetTextRelBase(context)
  unsigned char * context;
{
  return *(unsigned char *)(context + 0x1c8);
}

/* _extract_cie_info @ 0x97c1a62c (348 bytes) */
int _extract_cie_info(cie, context, fs)
  int cie;
  undefined4 context;
  int fs;
{
  undefined4 lebValue;
  char *ehPtrSrc;
  undefined1 retaddrColumn;
  char augChar;
  byte personalityEncoding;
  int length;
  undefined4 base_of_encoded_valueResult;
  undefined1 *pAfterSleb;
  byte *ret;
  char *p0;
  byte *p;
  char *aug;
  int utmp [5];
  
  aug = (char *)(cie + 9);
  length = _strlen(aug);
  p0 = aug + length + 1;
  ret = (byte *)0x0;
  if ((*(char *)(cie + 9) == 'e') && (*(char *)(cie + 10) == 'h')) {
    ehPtrSrc = aug + length + 1;
    p0 = aug + length + 5;
    aug = (char *)(cie + 0xb);
    *(undefined4 *)(fs + 0x3a0) = *(undefined4 *)ehPtrSrc;
  }
  lebValue = _read_uleb128_97c1a3ec(p0,fs + 0x398);
  pAfterSleb = (undefined1 *)_read_sleb128_97c1a41c(lebValue,fs + 0x394);
  retaddrColumn = *pAfterSleb;
  p = pAfterSleb + 1;
  *(undefined1 *)(fs + 0x39e) = 0xff;
  *(undefined1 *)(fs + 0x39c) = retaddrColumn;
  augChar = *aug;
  if (augChar == 'z') {
    p = (byte *)_read_uleb128_97c1a3ec(p,utmp);
    *(undefined1 *)(fs + 0x39f) = 1;
    aug = aug + 1;
    augChar = *aug;
    ret = p + utmp[0];
  }
  do {
    if (augChar == '\0') {
      if (ret == (byte *)0x0) {
        ret = p;
      }
      return ret;
    }
    if (augChar == 'L') {
      *(byte *)(fs + 0x39e) = *p;
LAB_97c1a718:
      p = p + 1;
    }
    else {
      if (augChar == 'R') {
        *(byte *)(fs + 0x39d) = *p;
        goto LAB_97c1a718;
      }
      if (augChar != 'P') {
        return ret;
      }
      personalityEncoding = *p;
      base_of_encoded_valueResult = _base_of_encoded_value((uint)personalityEncoding,context);
      p = (byte *)_read_encoded_value_with_base_97c1a468
                                  ((uint)personalityEncoding,base_of_encoded_valueResult,p + 1,fs + 0x390);
    }
    aug = aug + 1;
    augChar = *aug;
  } while( true );
}

/* _execute_stack_op @ 0x97c1a788 (1212 bytes) */
int _execute_stack_op(opPtr, opEnd, context, initial)
  ushort *opPtr;
  ushort *opEnd;
  int context;
  undefined4 initial;
{
  byte operandSize;
  ushort branchOffset;
  uint *result;
  int stackByteOffset;
  undefined4 lebValue;
  uint first;
  ushort *opPtrNext;
  uint stackElt;
  uint newStackElt;
  uint op;
  uint stackFrameWords [67];
  uint *operand;
  uint *stmp;
  int regNumber;
  uint offsetOrIndex;
  int utmp [7];
  
  stackFrameWords[3] = initial;
  stackElt = 1;
  while (opPtr < opEnd) {
    op = (uint)*(byte *)opPtr;
    opPtrNext = (ushort *)((int)opPtr + 1);
    newStackElt = stackElt;
    switch(op) {
    case 3:
    case 0xc:
    case 0xd:
      result = *(uint **)opPtrNext;
      opPtrNext = (ushort *)((int)opPtr + 5);
      break;
    default:
      goto switchD_97c1a7e8_caseD_4;
    case 6:
    case 0x19:
    case 0x1f:
    case 0x20:
    case 0x23:
    case 0x94:
      newStackElt = stackElt - 1;
      if ((int)newStackElt < 0) goto switchD_97c1a7e8_caseD_4;
      operand = (uint *)stackFrameWords[stackElt + 2];
      if (op == 0x1f) {
LAB_97c1acc8:
        result = (uint *)-(int)operand;
      }
      else {
        stackElt = newStackElt;
        if (op < 0x20) {
          if (op != 6) {
            if (op == 0x19) {
              if (-1 < (int)operand) goto LAB_97c1ae98;
              goto LAB_97c1acc8;
            }
            goto switchD_97c1a7e8_caseD_4;
          }
LAB_97c1ac88:
          result = (uint *)*operand;
        }
        else if (op == 0x23) {
          opPtrNext = (ushort *)_read_uleb128_97c1a3ec(opPtrNext,utmp);
          result = (uint *)((int)operand + utmp[0]);
        }
        else if (op < 0x24) {
          result = (uint *)~(uint)operand;
          if (op != 0x20) goto switchD_97c1a7e8_caseD_4;
        }
        else {
          if (op != 0x94) goto switchD_97c1a7e8_caseD_4;
          operandSize = *(byte *)opPtrNext;
          opPtrNext = opPtr + 1;
          if (operandSize == 2) {
            result = (uint *)(uint)*(ushort *)operand;
          }
          else {
            if (2 < operandSize) {
              if (operandSize == 4) goto LAB_97c1ac88;
              if (operandSize == 8) {
                operandSize = *(byte *)((int)operand + 7);
                newStackElt = (uint)*(byte *)((int)operand + 6) << 8 |
                        (uint)*(byte *)((int)operand + 5) << 0x10 |
                        (uint)*(byte *)(operand + 1) << 0x18;
                goto LAB_97c1acb4;
              }
              goto switchD_97c1a7e8_caseD_4;
            }
            if (operandSize != 1) goto switchD_97c1a7e8_caseD_4;
            result = (uint *)(uint)*(byte *)operand;
          }
        }
      }
      break;
    case 8:
      result = (uint *)(uint)*(byte *)opPtrNext;
      opPtrNext = opPtr + 1;
      break;
    case 9:
      operandSize = *(byte *)opPtrNext;
      opPtrNext = opPtr + 1;
      result = (uint *)(int)(char)operandSize;
      break;
    case 10:
      result = (uint *)(uint)*opPtrNext;
      goto LAB_97c1aa6c;
    case 0xb:
      result = (uint *)(int)(short)*opPtrNext;
LAB_97c1aa6c:
      opPtrNext = (ushort *)((int)opPtr + 3);
      break;
    case 0xe:
    case 0xf:
      operandSize = *(byte *)(opPtr + 4);
      newStackElt = (uint)*(byte *)((int)opPtr + 7) << 8 |
              (uint)*(byte *)(opPtr + 3) << 0x10 | (uint)*(byte *)((int)opPtr + 5) << 0x18;
      opPtrNext = (ushort *)((int)opPtr + 9);
LAB_97c1acb4:
      operand = (uint *)(operandSize | newStackElt);
      goto LAB_97c1ae98;
    case 0x10:
      opPtrNext = (ushort *)_read_uleb128_97c1a3ec(opPtrNext,&operand);
      goto LAB_97c1ae98;
    case 0x11:
      opPtrNext = (ushort *)_read_sleb128_97c1a41c(opPtrNext,&stmp);
      result = stmp;
      break;
    case 0x12:
      stackByteOffset = stackElt << 2;
      if (0 < (int)stackElt) goto LAB_97c1ab88;
      goto switchD_97c1a7e8_caseD_4;
    case 0x13:
      stackElt = stackElt - 1;
      if (-1 < (int)stackElt) goto switchD_97c1a7e8_caseD_96;
      goto switchD_97c1a7e8_caseD_4;
    case 0x14:
      if (1 < (int)stackElt) {
        operand = (uint *)stackFrameWords[stackElt + 1];
        goto LAB_97c1aba8;
      }
      goto switchD_97c1a7e8_caseD_4;
    case 0x15:
      offsetOrIndex = (uint)*(byte *)opPtrNext;
      opPtrNext = opPtr + 1;
      if ((int)offsetOrIndex < (int)(stackElt - 1)) {
        stackByteOffset = (stackElt - offsetOrIndex) * 4;
LAB_97c1ab88:
        operand = *(uint **)((int)stackFrameWords + stackByteOffset + 8);
LAB_97c1aba8:
        goto LAB_97c1ae98;
      }
      goto switchD_97c1a7e8_caseD_4;
    case 0x17:
      if (2 < (int)stackElt) {
        newStackElt = stackFrameWords[stackElt + 2];
        op = stackFrameWords[stackElt];
        stackFrameWords[stackElt + 2] = stackFrameWords[stackElt + 1];
        stackFrameWords[stackElt] = newStackElt;
        stackFrameWords[stackElt + 1] = op;
        goto switchD_97c1a7e8_caseD_96;
      }
      goto switchD_97c1a7e8_caseD_4;
    case 0x1a:
    case 0x1b:
    case 0x1c:
    case 0x1d:
    case 0x1e:
    case 0x21:
    case 0x22:
    case 0x29:
    case 0x2a:
    case 0x2b:
    case 0x2c:
    case 0x2d:
    case 0x2e:
      newStackElt = stackElt - 2;
      if ((int)newStackElt < 0) goto switchD_97c1a7e8_caseD_4;
      first = stackFrameWords[stackElt + 1];
      stackElt = stackFrameWords[stackElt + 2];
      switch(op) {
      case 0x1a:
        result = (uint *)(first & stackElt);
        break;
      case 0x1b:
        result = (uint *)((int)first / (int)stackElt);
        break;
      case 0x1c:
        result = (uint *)(first - stackElt);
        break;
      case 0x1d:
        result = (uint *)(first - ((int)first / (int)stackElt) * stackElt);
        break;
      case 0x1e:
        result = (uint *)(first * stackElt);
        break;
      default:
        goto switchD_97c1a7e8_caseD_4;
      case 0x21:
        result = (uint *)(first | stackElt);
        break;
      case 0x22:
        result = (uint *)(first + stackElt);
        break;
      case 0x24:
        result = (uint *)(first << (stackElt & 0x3f));
        break;
      case 0x25:
        result = (uint *)(first >> (stackElt & 0x3f));
        break;
      case 0x26:
        result = (uint *)((int)first >> (stackElt & 0x3f));
        break;
      case 0x27:
        result = (uint *)(first ^ stackElt);
        break;
      case 0x29:
        result = (uint *)(uint)(stackElt == first);
        break;
      case 0x2a:
        result = (uint *)0x1;
        if ((int)stackElt < (int)first) {
LAB_97c1ae34:
          result = (uint *)0x0;
        }
        break;
      case 0x2b:
        result = (uint *)0x1;
        if ((int)stackElt <= (int)first) goto LAB_97c1ae34;
        break;
      case 0x2c:
        result = (uint *)0x1;
        if ((int)first < (int)stackElt) goto LAB_97c1ae34;
        break;
      case 0x2d:
        result = (uint *)0x1;
        if ((int)first <= (int)stackElt) goto LAB_97c1ae34;
        break;
      case 0x2e:
        operand = (uint *)(uint)(stackElt != first);
        goto LAB_97c1ae4c;
      }
      break;
    case 0x28:
      newStackElt = stackElt - 1;
      if (-1 < (int)newStackElt) {
        branchOffset = *opPtrNext;
        opPtrNext = (ushort *)((int)opPtr + 3);
        offsetOrIndex = (int)(short)branchOffset;
        stackByteOffset = stackElt + 2;
        stackElt = newStackElt;
        if (stackFrameWords[stackByteOffset] != 0) {
          opPtrNext = (ushort *)((int)opPtrNext + (int)(short)branchOffset);
        }
        goto switchD_97c1a7e8_caseD_96;
      }
      goto switchD_97c1a7e8_caseD_4;
    case 0x2f:
      branchOffset = *opPtrNext;
      opPtrNext = (ushort *)((int)opPtr + (int)(short)branchOffset + 3U);
      offsetOrIndex = (int)(short)branchOffset;
      goto switchD_97c1a7e8_caseD_96;
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
    case 0x3a:
    case 0x3b:
    case 0x3c:
    case 0x3d:
    case 0x3e:
    case 0x3f:
    case 0x40:
    case 0x41:
    case 0x42:
    case 0x43:
    case 0x44:
    case 0x45:
    case 0x46:
    case 0x47:
    case 0x48:
    case 0x49:
    case 0x4a:
    case 0x4b:
    case 0x4c:
    case 0x4d:
    case 0x4e:
    case 0x4f:
      result = (uint *)(op - 0x30);
      break;
    case 0x50:
    case 0x51:
    case 0x52:
    case 0x53:
    case 0x54:
    case 0x55:
    case 0x56:
    case 0x57:
    case 0x58:
    case 0x59:
    case 0x5a:
    case 0x5b:
    case 0x5c:
    case 0x5d:
    case 0x5e:
    case 0x5f:
    case 0x60:
    case 0x61:
    case 0x62:
    case 99:
    case 100:
    case 0x65:
    case 0x66:
    case 0x67:
    case 0x68:
    case 0x69:
    case 0x6a:
    case 0x6b:
    case 0x6c:
    case 0x6d:
    case 0x6e:
    case 0x6f:
      stackByteOffset = op - 0x50;
      goto LAB_97c1aaf4;
    case 0x70:
    case 0x71:
    case 0x72:
    case 0x73:
    case 0x74:
    case 0x75:
    case 0x76:
    case 0x77:
    case 0x78:
    case 0x79:
    case 0x7a:
    case 0x7b:
    case 0x7c:
    case 0x7d:
    case 0x7e:
    case 0x7f:
    case 0x80:
    case 0x81:
    case 0x82:
    case 0x83:
    case 0x84:
    case 0x85:
    case 0x86:
    case 0x87:
    case 0x88:
    case 0x89:
    case 0x8a:
    case 0x8b:
    case 0x8c:
    case 0x8d:
    case 0x8e:
    case 0x8f:
      opPtrNext = (ushort *)_read_sleb128_97c1a41c(opPtrNext,&offsetOrIndex);
      stackByteOffset = op - 0x70;
      goto LAB_97c1ab30;
    case 0x90:
      opPtrNext = (ushort *)_read_uleb128_97c1a3ec(opPtrNext,&regNumber);
      stackByteOffset = regNumber;
LAB_97c1aaf4:
      operand = (uint *)**(uint **)(context + stackByteOffset * 4);
      goto LAB_97c1aba8;
    case 0x92:
      lebValue = _read_uleb128_97c1a3ec(opPtrNext,&regNumber);
      opPtrNext = (ushort *)_read_sleb128_97c1a41c(lebValue,&offsetOrIndex);
      stackByteOffset = regNumber;
LAB_97c1ab30:
      operand = (uint *)(**(int **)(context + stackByteOffset * 4) + offsetOrIndex);
LAB_97c1ae4c:
      stackElt = newStackElt;
      goto LAB_97c1ae98;
    case 0x96:
      goto switchD_97c1a7e8_caseD_96;
    }
    operand = result;
    stackElt = newStackElt;
LAB_97c1ae98:
    if (0x3f < stackElt) goto switchD_97c1a7e8_caseD_4;
    stackFrameWords[stackElt + 4] = (uint)operand;
    stackElt = stackElt + 1;
switchD_97c1a7e8_caseD_96:
    opPtr = opPtrNext;
  }
  if (-1 < (int)(stackElt - 1)) {
    return stackFrameWords[stackElt + 2];
  }
switchD_97c1a7e8_caseD_4:
                    
  _abort();
}

/* _execute_cfa_program @ 0x97c1aee8 (1084 bytes) */
int _execute_cfa_program(insnPtr, insnEnd, context, fs)
  uint *insnPtr;
  uint *insnEnd;
  int context;
  int fs;
{
  byte insn;
  int scaledValue;
  uint delta;
  undefined4 *unusedRs;
  byte insnClass;
  undefined4 pAfterReg;
  uint *ulebTarget;
  uint pc;
  int dataAlign;
  undefined4 *oldRs;
  undefined4 *nextOldRs;
  uint *insnNext;
  undefined4 *newUnusedRs;
  int offset;
  uint reg;
  undefined4 reg2;
  int soffset;
  
  unusedRs = (undefined4 *)&STACKARG(0xffffff90);
  oldRs = (undefined4 *)0x0;
  *(undefined4 *)(fs + 0x378) = 0;
  if ((insnPtr < insnEnd) &&
     (pc = *(uint *)(fs + 0x38c), pc < *(uint *)(context + 0x1c0))) {
    do {
      insn = *(byte *)insnPtr;
      insnNext = (uint *)((int)insnPtr + 1);
      insnClass = insn & 0xc0;
      if (insnClass == 0x40) {
        scaledValue = (insn & 0x3f) * *(int *)(fs + 0x398);
        goto LAB_97c1b0dc;
      }
      if (insnClass == 0x80) {
        reg = insn & 0x3f;
LAB_97c1b0f4:
        insnNext = (uint *)_read_uleb128_97c1a3ec(insnNext,&offset);
        dataAlign = *(int *)(fs + 0x394);
        scaledValue = offset;
LAB_97c1b10c:
        *(undefined4 *)(reg * 8 + fs + 4) = 1;
        scaledValue = scaledValue * dataAlign;
LAB_97c1b3a0:
        *(int *)(fs + reg * 8) = scaledValue;
        goto switchD_97c1afc0_caseD_0;
      }
      if (insnClass == 0xc0) {
        *(undefined4 *)((insn & 0x3f) * 8 + fs + 4) = 0;
        reg = insn & 0x3f;
        goto switchD_97c1afc0_caseD_0;
      }
      switch(insn) {
      case 0:
        break;
      case 1:
        insn = *(byte *)(fs + 0x39d);
        pAfterReg = _base_of_encoded_value((uint)insn,context);
        insnNext = (uint *)_read_encoded_value_with_base_97c1a468
                                    ((uint)insn,pAfterReg,insnNext,fs + 0x38c);
        break;
      case 2:
        delta = (uint)*(byte *)insnNext;
        insnNext = (uint *)((int)insnPtr + 2);
        goto LAB_97c1b0c0;
      case 3:
        delta = (uint)*(ushort *)insnNext;
        insnNext = (uint *)((int)insnPtr + 3);
LAB_97c1b0c0:
        scaledValue = *(int *)(fs + 0x398);
LAB_97c1b0d4:
        scaledValue = delta * scaledValue;
LAB_97c1b0dc:
        *(uint *)(fs + 0x38c) = pc + scaledValue;
        break;
      case 4:
        scaledValue = *(int *)(fs + 0x398);
        delta = *insnNext;
        insnNext = (uint *)((int)insnPtr + 5);
        goto LAB_97c1b0d4;
      case 5:
        insnNext = (uint *)_read_uleb128_97c1a3ec(insnNext,&reg);
        goto LAB_97c1b0f4;
      case 6:
        insnNext = (uint *)_read_uleb128_97c1a3ec(insnNext,&reg);
        *(undefined4 *)(reg * 8 + fs + 4) = 0;
        break;
      case 7:
      case 8:
        ulebTarget = &reg;
        goto LAB_97c1b358;
      case 9:
        pAfterReg = _read_uleb128_97c1a3ec(insnNext,&reg);
        insnNext = (uint *)_read_uleb128_97c1a3ec(pAfterReg,&reg2);
        *(undefined4 *)(reg * 8 + fs + 4) = 2;
        *(undefined4 *)(fs + reg * 8) = reg2;
        break;
      case 10:
        if (oldRs == (undefined4 *)0x0) {
          newUnusedRs = unusedRs + -0xe4;
          *newUnusedRs = *unusedRs;
          unusedRs = unusedRs + -0xd4;
          nextOldRs = oldRs;
        }
        else {
          newUnusedRs = unusedRs;
          nextOldRs = (undefined4 *)oldRs[0xde];
          unusedRs = oldRs;
        }
        _memcpy(unusedRs,fs,0x37c);
        *(undefined4 **)(fs + 0x378) = unusedRs;
        unusedRs = newUnusedRs;
        oldRs = nextOldRs;
        break;
      case 0xb:
        newUnusedRs = *(undefined4 **)(fs + 0x378);
        _memcpy(fs,newUnusedRs,0x37c);
        newUnusedRs[0xde] = oldRs;
        oldRs = newUnusedRs;
        break;
      case 0xc:
        pAfterReg = _read_uleb128_97c1a3ec(insnNext,fs + 0x380);
        insnNext = (uint *)_read_uleb128_97c1a3ec(pAfterReg,&offset);
        *(int *)(fs + 0x37c) = offset;
        *(undefined4 *)(fs + 0x388) = 1;
        break;
      case 0xd:
        insnNext = (uint *)_read_uleb128_97c1a3ec(insnNext,fs + 0x380);
        goto LAB_97c1b2e8;
      case 0xe:
        insnNext = (uint *)_read_uleb128_97c1a3ec(insnNext,&offset);
        *(int *)(fs + 0x37c) = offset;
        break;
      case 0xf:
        scaledValue = _read_uleb128_97c1a3ec(insnNext,&offset);
        *(int *)(fs + 900) = scaledValue;
        *(undefined4 *)(fs + 0x388) = 2;
        insnNext = (uint *)(scaledValue + offset);
        break;
      case 0x10:
        pAfterReg = _read_uleb128_97c1a3ec(insnNext,&reg);
        scaledValue = _read_uleb128_97c1a3ec(pAfterReg,&offset);
        *(undefined4 *)(reg * 8 + fs + 4) = 3;
        *(int *)(fs + reg * 8) = scaledValue;
        insnNext = (uint *)(scaledValue + offset);
        break;
      case 0x11:
        pAfterReg = _read_uleb128_97c1a3ec(insnNext,&reg);
        insnNext = (uint *)_read_sleb128_97c1a41c(pAfterReg,&soffset);
        dataAlign = *(int *)(fs + 0x394);
        scaledValue = soffset;
        goto LAB_97c1b10c;
      case 0x12:
        pAfterReg = _read_uleb128_97c1a3ec(insnNext,fs + 0x380);
        insnNext = (uint *)_read_sleb128_97c1a41c(pAfterReg,fs + 0x37c);
LAB_97c1b2e8:
        *(undefined4 *)(fs + 0x388) = 1;
        break;
      case 0x13:
        insnNext = (uint *)_read_sleb128_97c1a41c(insnNext,fs + 0x37c);
        break;
      default:
                    
        _abort();
      case 0x2d:
        reg = 0x10;
        do {
          *(undefined4 *)(reg * 8 + fs + 4) = 1;
          pc = reg + 1;
          *(uint *)(reg * 8 + fs) = reg * 4 + -0x40;
          reg = pc;
        } while (pc < 0x20);
        break;
      case 0x2e:
        ulebTarget = (uint *)(context + 0x1d4);
LAB_97c1b358:
        insnNext = (uint *)_read_uleb128_97c1a3ec(insnNext,ulebTarget);
        break;
      case 0x2f:
        pAfterReg = _read_uleb128_97c1a3ec(insnNext,&reg);
        insnNext = (uint *)_read_uleb128_97c1a3ec(pAfterReg,&offset);
        scaledValue = *(int *)(fs + 0x394);
        *(undefined4 *)(reg * 8 + fs + 4) = 1;
        scaledValue = -(offset * scaledValue);
        goto LAB_97c1b3a0;
      }
switchD_97c1afc0_caseD_0: ;
    } while ((insnNext < insnEnd) &&
            (pc = *(uint *)(fs + 0x38c), insnPtr = insnNext,
            pc < *(uint *)(context + 0x1c0)));
  }
  return;
}

/* _uw_frame_state_for @ 0x97c1b3e4 (328 bytes) */
int _uw_frame_state_for(context, fs)
  int context;
  int fs;
{
  undefined4 base_of_encoded_valueResult;
  int size_of_encoded_valueResult;
  undefined4 status;
  int cieDelta;
  int *unwind_Find_FDEResult;
  int extract_cie_infoResult;
  int augEnd;
  int cie;
  uint lsdaEncoding;
  int utmp [5];
  
  _memset(fs,0,0x3a4);
  *(undefined4 *)(context + 0x1c4) = 0;
  *(undefined4 *)(context + 0x1d4) = 0;
  unwind_Find_FDEResult = ((int (*)())__Unwind_Find_FDE)((void *)(*(int *)(context + 0x1c0) + -1),
                             (dwarf_eh_bases *)(context + 0x1c8));
  status = 5;
  if (unwind_Find_FDEResult != (int *)0x0) {
    *(undefined4 *)(fs + 0x38c) = *(undefined4 *)(context + 0x1d0);
    cieDelta = unwind_Find_FDEResult[1];
    cie = (int)unwind_Find_FDEResult + (4 - cieDelta);
    extract_cie_infoResult = ((int (*)())_extract_cie_info)(cie,context,fs);
    status = 3;
    if (extract_cie_infoResult != 0) {
      augEnd = 0;
      ((int (*)())_execute_cfa_program)(extract_cie_infoResult,cie + *(int *)((int)unwind_Find_FDEResult + (4 - cieDelta)) + 4,context,fs);
      size_of_encoded_valueResult = _size_of_encoded_value_97c1a2c8((uint)*(byte *)(fs + 0x39d));
      cieDelta = (int)unwind_Find_FDEResult + size_of_encoded_valueResult * 2 + 8;
      if (*(char *)(fs + 0x39f) != '\0') {
        cieDelta = _read_uleb128_97c1a3ec(cieDelta,utmp);
        augEnd = cieDelta + utmp[0];
      }
      lsdaEncoding = (uint)*(byte *)(fs + 0x39e);
      if (lsdaEncoding != 0xff) {
        base_of_encoded_valueResult = _base_of_encoded_value(lsdaEncoding,context);
        cieDelta = _read_encoded_value_with_base_97c1a468(lsdaEncoding,base_of_encoded_valueResult,cieDelta,context + 0x1c4);
      }
      if (augEnd == 0) {
        augEnd = cieDelta;
      }
      ((int (*)())_execute_cfa_program)(augEnd,(int)unwind_Find_FDEResult + *unwind_Find_FDEResult + 4,context,fs);
      status = 0;
    }
  }
  return status;
}

/* ___frame_state_for @ 0x97c1b52c (236 bytes) */
int ___frame_state_for(pcTarget, stateIn)
  int pcTarget;
  int stateIn;
{
  int regsLeft;
  char savedKind;
  int uw_frame_state_forResult;
  undefined1 *fsEntryCursor;
  char *savedOut;
  undefined4 *regOrOffsetOut;
  int result;
  undefined1 stackContext [448];
  int contextRa;
  undefined4 contextArgsSize;
  undefined4 uwFrameState;
  char fsBody [885];
  undefined4 fsCfaOffset;
  undefined2 fsCfaReg;
  int fsCfaHow;
  byte fsRetaddrColumn;
  undefined4 fsEhPtr;
  
  fsEntryCursor = stackContext;
  _memset(fsEntryCursor,0,0x1d8);
  contextRa = pcTarget + 1;
  uw_frame_state_forResult = ((int (*)())_uw_frame_state_for)(fsEntryCursor,&uwFrameState);
  result = 0;
  if ((uw_frame_state_forResult == 0) && (fsCfaHow != 2)) {
    regsLeft = 0x4e;
    regOrOffsetOut = (undefined4 *)(stateIn + 0x10);
    savedOut = (char *)(stateIn + 0x14c);
    do {
      savedKind = fsEntryCursor[0x1e7];
      *savedOut = savedKind;
      if ((savedKind == '\x01') || (savedKind == '\x02')) {
        *regOrOffsetOut = *(undefined4 *)(fsEntryCursor + 0x1e0);
      }
      else {
        *regOrOffsetOut = 0;
      }
      savedOut = savedOut + 1;
      fsEntryCursor = fsEntryCursor + 8;
      regOrOffsetOut = regOrOffsetOut + 1;
      regsLeft = regsLeft + -1;
    } while (regsLeft != 0);
    *(undefined2 *)(stateIn + 0x148) = fsCfaReg;
    *(undefined4 *)(stateIn + 8) = fsCfaOffset;
    *(ushort *)(stateIn + 0x14a) = (ushort)fsRetaddrColumn;
    *(undefined4 *)(stateIn + 0xc) = contextArgsSize;
    *(undefined4 *)(stateIn + 4) = fsEhPtr;
    result = stateIn;
  }
  return result;
}

/* _uw_update_context_1 @ 0x97c1b618 (320 bytes) */
int _uw_update_context_1(context, fs)
  int *context;
  int *fs;
{
  int regHow;
  int exp;
  int cfaRegValue;
  int *regSlotOrExpResult;
  int *cfa;
  int *lastReg;
  int origContext [120];
  int cfaExpLen;
  int regExpLen [5];
  
  _memcpy(origContext,context,0x1d8);
  if (fs[0xe2] == 1) {
    regSlotOrExpResult = (int *)context[fs[0xe0]];
    if (regSlotOrExpResult == (int *)0x0) {
      cfaRegValue = context[0x6f];
    }
    else {
      cfaRegValue = *regSlotOrExpResult;
    }
    cfa = (int *)(cfaRegValue + fs[0xdf]);
  }
  else {
    if (fs[0xe2] != 2) {
                    
      _abort();
    }
    exp = _read_uleb128_97c1a3ec(fs[0xe1],&cfaExpLen);
    regSlotOrExpResult = (int *)((int (*)())_execute_stack_op)(exp,exp + cfaExpLen,context,0);
    cfa = regSlotOrExpResult;
  }
  context[0x6f] = (int)cfa;
  lastReg = context + 0x6e;
  do {
    regHow = fs[1];
    if (regHow == 1) {
      *context = (int)cfa + *fs;
    }
    else if (regHow != 0) {
      if (regHow == 2) {
        *context = origContext[*fs];
      }
      else if (regHow == 3) {
        exp = _read_uleb128_97c1a3ec(*fs,regExpLen);
        regSlotOrExpResult = (int *)((int (*)())_execute_stack_op)(exp,exp + regExpLen[0],origContext,cfa);
        *context = (int)regSlotOrExpResult;
      }
    }
    context = context + 1;
    fs = fs + 2;
  } while ((int)context <= (int)lastReg);
  return regSlotOrExpResult;
}

/* _uw_update_context @ 0x97c1b758 (68 bytes) */
int _uw_update_context(context, fs)
  int context;
  int fs;
{
  ((int (*)())_uw_update_context_1)(context,fs);
  *(undefined4 *)(context + 0x1c0) =
       **(undefined4 **)(context + (uint)*(byte *)(fs + 0x39c) * 4);
  return;
}

/* _uw_init_context_1 @ 0x97c1b79c (132 bytes) */
int _uw_init_context_1(context, outerCfa, outerRa)
  int context;
  undefined4 outerCfa;
  undefined4 outerRa;
{
  undefined4 entryReturnAddress;
  undefined1 fs [892];
  int fsCfaOffset;
  int fsCfaReg;
  undefined4 fsCfaHow;
  
  _memset(context,0,0x1d8);
  *(undefined4 *)(context + 0x1c0) = entryReturnAddress;
  fsCfaOffset = ((int (*)())_uw_frame_state_for)(context,fs);
  if (fsCfaOffset != 0) {
                    
    _abort();
  }
  *(undefined4 *)(context + 0x1bc) = outerCfa;
  fsCfaHow = 1;
  fsCfaReg = fsCfaOffset;
  ((int (*)())_uw_update_context_1)(context,fs);
  *(undefined4 *)(context + 0x1c0) = outerRa;
  return;
}

/* _uw_install_context_1 @ 0x97c1b820 (652 bytes) */
int _uw_install_context_1(current, target)
  int current;
  int target;
{
  int pthread_onceResult;
  byte *regSizePtr;
  int regOffset;
  int currentReg;
  int targetReg;
  
  pthread_onceResult = _pthread_once((pthread_once_t *)&_once_regsizes_0,DAT_a7b7c084);
  if ((pthread_onceResult != 0) || (_dwarf_reg_size_table == '\0')) {
    _dwarf_reg_size_table = '\x04';
    DAT_a7b7ea7d = 4;
    DAT_a7b7ea7e = 4;
    DAT_a7b7ea7f = 4;
    DAT_a7b7ea80 = 4;
    DAT_a7b7ea81 = 4;
    DAT_a7b7ea82 = 4;
    DAT_a7b7ea83 = 4;
    DAT_a7b7ea84 = 4;
    DAT_a7b7ea85 = 4;
    DAT_a7b7ea86 = 4;
    DAT_a7b7ea87 = 4;
    DAT_a7b7ea88 = 4;
    DAT_a7b7ea89 = 4;
    DAT_a7b7ea8a = 4;
    DAT_a7b7ea8b = 4;
    DAT_a7b7ea8c = 4;
    DAT_a7b7ea8d = 4;
    DAT_a7b7ea8e = 4;
    DAT_a7b7ea8f = 4;
    DAT_a7b7ea90 = 4;
    DAT_a7b7ea91 = 4;
    DAT_a7b7ea92 = 4;
    DAT_a7b7ea93 = 4;
    DAT_a7b7ea94 = 4;
    DAT_a7b7ea95 = 4;
    DAT_a7b7ea96 = 4;
    DAT_a7b7ea97 = 4;
    DAT_a7b7ea98 = 4;
    DAT_a7b7ea99 = 4;
    DAT_a7b7ea9a = 4;
    DAT_a7b7ea9b = 4;
    DAT_a7b7ea9c = 8;
    DAT_a7b7ea9d = 8;
    DAT_a7b7eabb = 8;
    DAT_a7b7ea9e = 8;
    DAT_a7b7ea9f = 8;
    DAT_a7b7eaa0 = 8;
    DAT_a7b7eaa1 = 8;
    DAT_a7b7eaa2 = 8;
    DAT_a7b7eaa3 = 8;
    DAT_a7b7eaa4 = 8;
    DAT_a7b7eaa5 = 8;
    DAT_a7b7eaa6 = 8;
    DAT_a7b7eaa7 = 8;
    DAT_a7b7eaa8 = 8;
    DAT_a7b7eaa9 = 8;
    DAT_a7b7eaaa = 8;
    DAT_a7b7eaab = 8;
    DAT_a7b7eaac = 8;
    DAT_a7b7eaad = 8;
    DAT_a7b7eaae = 8;
    DAT_a7b7eaaf = 8;
    DAT_a7b7eab0 = 8;
    DAT_a7b7eab1 = 8;
    DAT_a7b7eab2 = 8;
    DAT_a7b7eab3 = 8;
    DAT_a7b7eab4 = 8;
    DAT_a7b7eab5 = 8;
    DAT_a7b7eab6 = 8;
    DAT_a7b7eab7 = 8;
    DAT_a7b7eab8 = 8;
    DAT_a7b7eab9 = 8;
    DAT_a7b7eaba = 8;
    DAT_a7b7eabc = 4;
    DAT_a7b7eabd = 4;
    DAT_a7b7eabe = 4;
    DAT_a7b7eabf = 4;
    DAT_a7b7eac0 = 4;
    DAT_a7b7eac1 = 4;
    DAT_a7b7eac2 = 4;
    DAT_a7b7eac3 = 4;
    DAT_a7b7eac4 = 4;
    DAT_a7b7eac5 = 4;
    DAT_a7b7eac6 = 4;
    DAT_a7b7eac7 = 4;
    DAT_a7b7eac8 = 4;
    DAT_a7b7eac9 = 0x10;
    DAT_a7b7eaca = 0x10;
    DAT_a7b7eacb = 0x10;
    DAT_a7b7eacc = 0x10;
    DAT_a7b7eacd = 0x10;
    DAT_a7b7eace = 0x10;
    DAT_a7b7eacf = 0x10;
    DAT_a7b7ead0 = 0x10;
    DAT_a7b7ead1 = 0x10;
    DAT_a7b7ead2 = 0x10;
    DAT_a7b7ead3 = 0x10;
    DAT_a7b7ead4 = 0x10;
    DAT_a7b7ead5 = 0x10;
    DAT_a7b7ead6 = 0x10;
    DAT_a7b7ead7 = 0x10;
    DAT_a7b7ead8 = 0x10;
    DAT_a7b7ead9 = 0x10;
    DAT_a7b7eada = 0x10;
    DAT_a7b7eadb = 0x10;
    DAT_a7b7eadc = 0x10;
    DAT_a7b7eadd = 0x10;
    DAT_a7b7eade = 0x10;
    DAT_a7b7eadf = 0x10;
    DAT_a7b7eae0 = 0x10;
    DAT_a7b7eae1 = 0x10;
    DAT_a7b7eae9 = 4;
    DAT_a7b7eae8 = 0x10;
    DAT_a7b7eae2 = 0x10;
    DAT_a7b7eae3 = 0x10;
    DAT_a7b7eae4 = 0x10;
    DAT_a7b7eae5 = 0x10;
    DAT_a7b7eae6 = 0x10;
    DAT_a7b7eae7 = 0x10;
  }
  regOffset = 0;
  regSizePtr = (byte *)&_dwarf_reg_size_table;
  do {
    targetReg = *(int *)(regOffset + target);
    currentReg = *(int *)(regOffset + current);
    if (((targetReg != 0) && (currentReg != 0)) && (targetReg != currentReg)) {
      _memcpy(currentReg,targetReg,(uint)*regSizePtr);
    }
    regSizePtr = regSizePtr + 1;
    regOffset = regOffset + 4;
  } while ((int)regSizePtr < -0x58481516);
  return (*(int *)(target + 0x1bc) - *(int *)(current + 0x1bc)) + *(int *)(target + 0x1d4);
}

/* __Unwind_RaiseException_Phase2 @ 0x97c1baac (192 bytes) */
int __Unwind_RaiseException_Phase2(exc, context)
  undefined4 *exc;
  int context;
{
  uint isHandlerFrame;
  bool notContinueUnwind;
  int uw_frame_state_forResult;
  int result;
  undefined1 fs [912];
  code *personality;
  
  while( true ) {
    uw_frame_state_forResult = ((int (*)())_uw_frame_state_for)(context,fs);
    result = 2;
    isHandlerFrame = (uint)(*(int *)(context + 0x1c0) == exc[4]);
    if ((uw_frame_state_forResult != 0) ||
       ((personality != (code *)0x0 &&
        ((result = (*personality)(1,isHandlerFrame << 2 | 2,*exc,exc[1],exc,context,2), result == 7 ||
         (notContinueUnwind = result != 8, result = 2, notContinueUnwind)))))) break;
    if (isHandlerFrame != 0) {
                    
      _abort();
    }
    ((int (*)())_uw_update_context)(context,fs);
  }
  return result;
}

/* __Unwind_RaiseException @ 0x97c1bb6c (284 bytes) */
int __Unwind_RaiseException(exception_object)
  _Unwind_Exception *exception_object;
{
  double this_context[0x1d8 / 8], cur_context[0x1d8 / 8];
  double fs[0x3d0 / 8];
  long offset;
  int code;
  __builtin_unwind_init();
  ((int (*)())_uw_init_context_1)(this_context, __builtin_dwarf_cfa(), __builtin_return_address(0));
  _memcpy(cur_context, this_context, 0x1d8);
  while (1) {
    void *pers;
    code = ((int (*)())_uw_frame_state_for)(cur_context, fs);
    if (code == 5) return 5;
    if (code != 0) return 3;
    pers = *(void **)((char *)fs + 0x390);
    if (pers != 0) {
      code = ((int (*)(int, int, unsigned long long, void *, void *))pers)(1, 1, exception_object->exception_class, exception_object, cur_context);
      if (code == 6) break;
      if (code != 8) return 3;
    }
    ((int (*)())_uw_update_context)(cur_context, fs);
  }
  exception_object->private_1 = 0;
  exception_object->private_2 = *(unsigned long *)((char *)cur_context + 0x1c0);
  _memcpy(cur_context, this_context, 0x1d8);
  code = ((int (*)())__Unwind_RaiseException_Phase2)(exception_object, cur_context);
  if (code != 7) return code;
  offset = ((int (*)())_uw_install_context_1)(this_context, cur_context);
  __builtin_eh_return(offset, __builtin_frob_return_addr(*(void **)((char *)cur_context + 0x1c0)));
}

/* __Unwind_ForcedUnwind_Phase2 @ 0x97c1bc88 (260 bytes) */
int __Unwind_ForcedUnwind_Phase2(exc, context)
  undefined4 *exc;
  undefined4 context;
{
  int uw_frame_state_forResult;
  int personalityResult;
  int stopCode;
  undefined4 action;
  code *stop;
  undefined4 stopArg;
  undefined1 fs [912];
  code *personality;
  
  stop = (code *)exc[3];
  stopArg = exc[4];
  while( true ) {
    uw_frame_state_forResult = ((int (*)())_uw_frame_state_for)(context,fs);
    if ((uw_frame_state_forResult != 0) && (uw_frame_state_forResult != 5)) {
      return 2;
    }
    action = 10;
    if (uw_frame_state_forResult == 5) {
      action = 0x1a;
    }
    stopCode = (*stop)(1,action,*exc,exc[1],exc,context,stopArg);
    if (stopCode != 0) break;
    if (uw_frame_state_forResult == 5) {
      return 5;
    }
    if (personality != (code *)0x0) {
      personalityResult = (*personality)(1,10,*exc,exc[1],exc,context);
      if (personalityResult == 7) {
        return 7;
      }
      if (personalityResult != 8) {
        return 2;
      }
    }
    ((int (*)())_uw_update_context)(context,fs);
  }
  return 2;
}

/* __Unwind_ForcedUnwind @ 0x97c1bd8c (148 bytes) */
int __Unwind_ForcedUnwind(exception_object, stop, stop_parameter, unusedArg4, unusedArg5, unusedArg6, unusedArg7)
  _Unwind_Exception *exception_object;
  void *stop;
  void *stop_parameter;
  undefined4 unusedArg4;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
  undefined4 unusedArg7;
{
  double this_context[0x1d8 / 8], cur_context[0x1d8 / 8];
  double fs[0x3d0 / 8];
  long offset;
  int code;
  __builtin_unwind_init();
  ((int (*)())_uw_init_context_1)(this_context, __builtin_dwarf_cfa(), __builtin_return_address(0));
  _memcpy(cur_context, this_context, 0x1d8);
  exception_object->private_1 = (unsigned long)stop;
  exception_object->private_2 = (unsigned long)stop_parameter;
  code = ((int (*)())__Unwind_ForcedUnwind_Phase2)(exception_object, cur_context);
  if (code != 7) return code;
  offset = ((int (*)())_uw_install_context_1)(this_context, cur_context);
  __builtin_eh_return(offset, __builtin_frob_return_addr(*(void **)((char *)cur_context + 0x1c0)));
}

/* __Unwind_Resume @ 0x97c1be20 (152 bytes) */
int __Unwind_Resume(exception_object)
  _Unwind_Exception *exception_object;
{
  double this_context[0x1d8 / 8], cur_context[0x1d8 / 8];
  double fs[0x3d0 / 8];
  long offset;
  int code;
  __builtin_unwind_init();
  ((int (*)())_uw_init_context_1)(this_context, __builtin_dwarf_cfa(), __builtin_return_address(0));
  _memcpy(cur_context, this_context, 0x1d8);
  if (exception_object->private_1 == 0)
    code = ((int (*)())__Unwind_RaiseException_Phase2)(exception_object, cur_context);
  else
    code = ((int (*)())__Unwind_ForcedUnwind_Phase2)(exception_object, cur_context);
  if (code != 7) _abort();
  offset = ((int (*)())_uw_install_context_1)(this_context, cur_context);
  __builtin_eh_return(offset, __builtin_frob_return_addr(*(void **)((char *)cur_context + 0x1c0)));
}

/* __Unwind_DeleteException @ 0x97c1beb8 (20 bytes) */
int __Unwind_DeleteException(exception_object)
  _Unwind_Exception *exception_object;
{
                    
                    
  (*exception_object->exception_cleanup)(1,exception_object);
  return;
}

/* __Unwind_GetGR @ 0x97c1becc (16 bytes) */
int __Unwind_GetGR(context, index)
  unsigned char * context;
  int index;
{
  return **(unsigned char **)(context + index * 4);
}

/* __Unwind_SetGR @ 0x97c1bedc (16 bytes) */
int __Unwind_SetGR(context, index, new_value)
  unsigned char * context;
  int index;
  unsigned char new_value;
{
  **(unsigned char **)(context + index * 4) = new_value;
  return;
}

/* __Unwind_GetIP @ 0x97c1beec (8 bytes) */
int __Unwind_GetIP(context)
  unsigned char * context;
{
  return *(unsigned char *)(context + 0x1c0);
}

/* __Unwind_SetIP @ 0x97c1bef4 (8 bytes) */
int __Unwind_SetIP(context, new_value)
  unsigned char * context;
  unsigned char new_value;
{
  *(unsigned char *)(context + 0x1c0) = new_value;
  return;
}

/* _init_dwarf_reg_size_table @ 0x97c1befc (1192 bytes) */
int _init_dwarf_reg_size_table()
{
  _dwarf_reg_size_table = 4;
  DAT_a7b7ea7d = 4;
  DAT_a7b7ea7e = 4;
  DAT_a7b7ea7f = 4;
  DAT_a7b7ea80 = 4;
  DAT_a7b7ea81 = 4;
  DAT_a7b7ea82 = 4;
  DAT_a7b7ea83 = 4;
  DAT_a7b7ea84 = 4;
  DAT_a7b7ea85 = 4;
  DAT_a7b7ea86 = 4;
  DAT_a7b7ea87 = 4;
  DAT_a7b7ea88 = 4;
  DAT_a7b7ea89 = 4;
  DAT_a7b7ea8a = 4;
  DAT_a7b7ea8b = 4;
  DAT_a7b7ea8c = 4;
  DAT_a7b7ea8d = 4;
  DAT_a7b7ea8e = 4;
  DAT_a7b7ea8f = 4;
  DAT_a7b7ea90 = 4;
  DAT_a7b7ea91 = 4;
  DAT_a7b7ea92 = 4;
  DAT_a7b7ea93 = 4;
  DAT_a7b7ea94 = 4;
  DAT_a7b7ea95 = 4;
  DAT_a7b7ea96 = 4;
  DAT_a7b7ea97 = 4;
  DAT_a7b7ea98 = 4;
  DAT_a7b7ea99 = 4;
  DAT_a7b7ea9a = 4;
  DAT_a7b7ea9b = 4;
  DAT_a7b7ea9c = 8;
  DAT_a7b7ea9d = 8;
  DAT_a7b7ea9e = 8;
  DAT_a7b7ea9f = 8;
  DAT_a7b7eaa0 = 8;
  DAT_a7b7eaa1 = 8;
  DAT_a7b7eaa2 = 8;
  DAT_a7b7eaa3 = 8;
  DAT_a7b7eaa4 = 8;
  DAT_a7b7eaa5 = 8;
  DAT_a7b7eaa6 = 8;
  DAT_a7b7eaa7 = 8;
  DAT_a7b7eaa8 = 8;
  DAT_a7b7eaa9 = 8;
  DAT_a7b7eaaa = 8;
  DAT_a7b7eaab = 8;
  DAT_a7b7eaac = 8;
  DAT_a7b7eaad = 8;
  DAT_a7b7eaae = 8;
  DAT_a7b7eaaf = 8;
  DAT_a7b7eab0 = 8;
  DAT_a7b7eab1 = 8;
  DAT_a7b7eab2 = 8;
  DAT_a7b7eab3 = 8;
  DAT_a7b7eab4 = 8;
  DAT_a7b7eab5 = 8;
  DAT_a7b7eab6 = 8;
  DAT_a7b7eab7 = 8;
  DAT_a7b7eab8 = 8;
  DAT_a7b7eab9 = 8;
  DAT_a7b7eaba = 8;
  DAT_a7b7eabb = 8;
  DAT_a7b7eabc = 4;
  DAT_a7b7eabd = 4;
  DAT_a7b7eabe = 4;
  DAT_a7b7eabf = 4;
  DAT_a7b7eac0 = 4;
  DAT_a7b7eac1 = 4;
  DAT_a7b7eac2 = 4;
  DAT_a7b7eac3 = 4;
  DAT_a7b7eac4 = 4;
  DAT_a7b7eac5 = 4;
  DAT_a7b7eac6 = 4;
  DAT_a7b7eac7 = 4;
  DAT_a7b7eac8 = 4;
  DAT_a7b7eac9 = 0x10;
  DAT_a7b7eaca = 0x10;
  DAT_a7b7eacb = 0x10;
  DAT_a7b7eacc = 0x10;
  DAT_a7b7eacd = 0x10;
  DAT_a7b7eace = 0x10;
  DAT_a7b7eacf = 0x10;
  DAT_a7b7ead0 = 0x10;
  DAT_a7b7ead1 = 0x10;
  DAT_a7b7ead2 = 0x10;
  DAT_a7b7ead3 = 0x10;
  DAT_a7b7ead4 = 0x10;
  DAT_a7b7ead5 = 0x10;
  DAT_a7b7ead6 = 0x10;
  DAT_a7b7ead7 = 0x10;
  DAT_a7b7ead8 = 0x10;
  DAT_a7b7ead9 = 0x10;
  DAT_a7b7eada = 0x10;
  DAT_a7b7eadb = 0x10;
  DAT_a7b7eadc = 0x10;
  DAT_a7b7eadd = 0x10;
  DAT_a7b7eade = 0x10;
  DAT_a7b7eadf = 0x10;
  DAT_a7b7eae0 = 0x10;
  DAT_a7b7eae1 = 0x10;
  DAT_a7b7eae2 = 0x10;
  DAT_a7b7eae3 = 0x10;
  DAT_a7b7eae4 = 0x10;
  DAT_a7b7eae5 = 0x10;
  DAT_a7b7eae6 = 0x10;
  DAT_a7b7eae7 = 0x10;
  DAT_a7b7eae8 = 0x10;
  DAT_a7b7eae9 = 4;
  return;
}

/* _size_of_encoded_value_97c1c3a4 @ 0x97c1c3a4 (120 bytes) */
int _size_of_encoded_value_97c1c3a4(encoding)
  uint encoding;
{
  uint format;
  undefined4 valueSize;
  
  valueSize = 0;
  if (encoding != 0xff) {
    format = encoding & 7;
    valueSize = 2;
    if (format != 2) {
      if (format < 3) {
        if (format != 0) {
LAB_97c1c404:
                    
          _abort();
        }
        valueSize = 4;
      }
      else {
        valueSize = 4;
        if (format != 3) {
          if (format != 4) goto LAB_97c1c404;
          valueSize = 8;
        }
      }
    }
  }
  return valueSize;
}

/* _read_uleb128_97c1c41c @ 0x97c1c41c (48 bytes) */
int _read_uleb128_97c1c41c(p, val)
  byte *p;
  uint *val;
{
  byte byteRead;
  uint shiftForByte;
  uint shift;
  uint result;
  
  shift = 0;
  result = 0;
  do {
    byteRead = *p;
    p = p + 1;
    shiftForByte = shift & 0x3f;
    shift = shift + 7;
    result = result | (byteRead & 0x7f) << shiftForByte;
  } while ((byteRead & 0x80) != 0);
  *val = result;
  return p;
}

/* _read_sleb128_97c1c44c @ 0x97c1c44c (76 bytes) */
int _read_sleb128_97c1c44c(p, val)
  byte *p;
  uint *val;
{
  byte byteRead;
  uint shiftForByte;
  uint shift;
  uint result;
  
  shift = 0;
  result = 0;
  do {
    byteRead = *p;
    p = p + 1;
    shiftForByte = shift & 0x3f;
    shift = shift + 7;
    result = result | (byteRead & 0x7f) << shiftForByte;
  } while ((byteRead & 0x80) != 0);
  if ((shift < 0x20) && ((byteRead & 0x40) != 0)) {
    result = result | -1 << (shift & 0x3f);
  }
  *val = result;
  return p;
}

/* _read_encoded_value_with_base_97c1c498 @ 0x97c1c498 (312 bytes) */
int _read_encoded_value_with_base_97c1c498(encoding, base, p, val)
  uint encoding;
  uint *base;
  uint *p;
  uint *val;
{
  uint *next;
  uint *utmp;
  uint *result [6];
  
  if (encoding == 0x50) {
    result[0] = (uint *)((int)p + 3U & 0xfffffffc);
    next = result[0] + 1;
    goto LAB_97c1c5e4;
  }
  switch(encoding & 0xf) {
  case 0:
  case 3:
  case 0xb:
    result[0] = (uint *)*p;
    next = p + 1;
    break;
  case 1:
    next = (uint *)((int (*)())_read_uleb128_97c1c41c)(p,&utmp);
    result[0] = utmp;
    break;
  case 2:
    result[0] = (uint *)(uint)*(ushort *)p;
    goto LAB_97c1c570;
  case 4:
  case 0xc:
    next = p + 2;
    result[0] = (uint *)((uint)*(byte *)((int)p + 7) |
                          (uint)*(byte *)((int)p + 6) << 8 |
                          (uint)*(byte *)((int)p + 5) << 0x10 |
                          (uint)*(byte *)(p + 1) << 0x18);
    break;
  default:
                    
    _abort();
  case 9:
    next = (uint *)((int (*)())_read_sleb128_97c1c44c)(p,result);
    break;
  case 10:
    result[0] = (uint *)(int)(short)*(ushort *)p;
LAB_97c1c570:
    next = (uint *)((int)p + 2);
  }
  if (result[0] != (uint *)0x0) {
    if ((encoding & 0x70) == 0x10) {
      base = p;
    }
    result[0] = (uint *)((int)result[0] + (int)base);
    if ((encoding & 0x80) != 0) {
LAB_97c1c5e4:
      result[0] = (uint *)*result[0];
    }
  }
  *val = (uint)result[0];
  return next;
}

/* ___register_frame_info_bases @ 0x97c1c604 (88 bytes) */
int ___register_frame_info_bases(fde, ob, tb, db)
  void *fde;
  void *ob;
  void *tb;
  void *db;
{
  if (*(int *)fde == 0) {
    return;
  }
  *(undefined4 *)ob = 0xffffffff;
  *(void **)((int)ob + 4) = tb;
  *(void **)((int)ob + 8) = db;
  *(void **)((int)ob + 0xc) = fde;
  *(undefined4 *)((int)ob + 0x10) = 0x1fe00000;
  *(undefined4 *)((int)ob + 0x14) = 0;
  *(void **)((int)ob + 0x18) = _unseen_objects;
  _unseen_objects = ob;
  return;
}

/* ___register_frame_info @ 0x97c1c65c (12 bytes) */
int ___register_frame_info(fde, ob)
  void *fde;
  void *ob;
{
  return ((int (*)())___register_frame_info_bases)(fde,ob,(void *)0x0,(void *)0x0);
}

/* ___register_frame @ 0x97c1c668 (88 bytes) */
int ___register_frame(fde)
  void *fde;
{
  void *ob;
  
  if (*(int *)fde != 0) {
    ob = (void *)_malloc(0x1c);
    ((int (*)())___register_frame_info)(fde,ob);
    return;
  }
  return;
}

/* ___register_frame_info_table_bases @ 0x97c1c6c0 (68 bytes) */
int ___register_frame_info_table_bases(fde, ob, tb, db)
  void *fde;
  void *ob;
  void *tb;
  void *db;
{
  *(undefined4 *)ob = 0xffffffff;
  *(void **)((int)ob + 4) = tb;
  *(void **)((int)ob + 8) = db;
  *(void **)((int)ob + 0xc) = fde;
  *(undefined4 *)((int)ob + 0x10) = 0x5fe00000;
  *(void **)((int)ob + 0x18) = _unseen_objects;
  _unseen_objects = ob;
  return;
}

/* ___register_frame_table @ 0x97c1c710 (68 bytes) */
int ___register_frame_table(fde, unusedArg)
  void *fde;
  undefined4 unusedArg;
{
  void *ob;
  
  ob = (void *)_malloc(0x1c);
  ((int (*)())___register_frame_info_table_bases)(fde,ob,(void *)0x0,(void *)0x0);
  return;
}

/* ___deregister_frame_info_bases @ 0x97c1c748 (240 bytes) */
int ___deregister_frame_info_bases(fde)
  void *fde;
{
  void *ob;
  undefined4 *linkSlot;
  
  if (*(int *)fde == 0) {
    return (void *)0x0;
  }
  linkSlot = &_unseen_objects;
  for (ob = _unseen_objects; ob != (void *)0x0; ob = *(void **)((int)ob + 0x18)) {
    if (*(void **)((int)ob + 0xc) == fde) goto LAB_97c1c810;
    linkSlot = (undefined4 *)((int)ob + 0x18);
  }
  linkSlot = &_seen_objects;
  ob = _seen_objects;
  do {
    if (ob == (void *)0x0) {
                    
      _abort();
    }
    if (*(int *)((int)ob + 0x10) < 0) {
      if ((void *)**(int **)((int)ob + 0xc) == fde) {
        *linkSlot = *(undefined4 *)((int)ob + 0x18);
        _free(*(undefined4 *)((int)ob + 0xc));
        return ob;
      }
    }
    else if (*(void **)((int)ob + 0xc) == fde) {
LAB_97c1c810:
      *linkSlot = *(undefined4 *)((int)ob + 0x18);
      return ob;
    }
    linkSlot = (undefined4 *)((int)ob + 0x18);
    ob = *(void **)((int)ob + 0x18);
  } while( true );
}

/* ___deregister_frame @ 0x97c1c83c (72 bytes) */
int ___deregister_frame(fde)
  void *fde;
{
  void *deregister_frame_infoResult;
  undefined4 r3Out0;
  
  if (*(int *)fde != 0) {
    deregister_frame_infoResult = ___deregister_frame_info(fde);
    _free(deregister_frame_infoResult);
    return r3Out0;
  }
  return fde;
}

/* _base_from_object @ 0x97c1c884 (120 bytes) */
int _base_from_object(encoding, ob)
  uint encoding;
  int ob;
{
  bool isPcrelOrAligned;
  uint application;
  
  if (encoding == 0xff) {
    return 0;
  }
  application = encoding & 0x70;
  if (application == 0x20) {
    return *(undefined4 *)(ob + 4);
  }
  if (application < 0x21) {
    if (application == 0) {
      return 0;
    }
    isPcrelOrAligned = application == 0x10;
  }
  else {
    if (application == 0x30) {
      return *(undefined4 *)(ob + 8);
    }
    isPcrelOrAligned = application == 0x50;
  }
  if (isPcrelOrAligned) {
    return 0;
  }
                    
  _abort();
}

/* _get_cie_encoding @ 0x97c1c8fc (200 bytes) */
int _get_cie_encoding(cie)
  int cie;
{
  int length;
  char augChar;
  int read_sleb128Result;
  undefined4 read_uleb128Result;
  byte *p;
  byte fdeEncoding;
  char *aug;
  undefined1 utmp [4];
  undefined1 stmp [4];
  undefined1 personality [12];
  
  fdeEncoding = 0;
  if (*(char *)(cie + 9) == 'z') {
    length = _strlen(cie + 9);
    read_uleb128Result = ((int (*)())_read_uleb128_97c1c41c)(cie + 9 + length + 1,utmp);
    read_sleb128Result = ((int (*)())_read_sleb128_97c1c44c)(read_uleb128Result,stmp);
    p = (byte *)((int (*)())_read_uleb128_97c1c41c)(read_sleb128Result + 1,utmp);
    for (aug = (char *)(cie + 10); augChar = *aug, augChar != 'R'; aug = aug + 1) {
      if (augChar == 'P') {
        p = (byte *)((int (*)())_read_encoded_value_with_base_97c1c498)(*p & 0x7f,0,p + 1,personality);
      }
      else {
        p = p + 1;
        if (augChar != 'L') {
          return 0;
        }
      }
    }
    fdeEncoding = *p;
  }
  return fdeEncoding;
}

/* _fde_unencoded_compare @ 0x97c1c9c4 (40 bytes) */
int _fde_unencoded_compare(ob, x, y)
  undefined4 ob;
  int x;
  int y;
{
  if (*(uint *)(y + 8) < *(uint *)(x + 8)) {
    return 1;
  }
  if (*(uint *)(x + 8) < *(uint *)(y + 8)) {
    return 0xffffffff;
  }
  return 0;
}

/* _fde_single_encoding_compare @ 0x97c1c9ec (152 bytes) */
int _fde_single_encoding_compare(ob, x, y)
  int ob;
  int x;
  int y;
{
  undefined4 baseAddress;
  undefined4 result;
  uint xPcBegin;
  uint yPcBegin [5];
  
  baseAddress = ((int (*)())_base_from_object)(*(uint *)(ob + 0x10) >> 0x15 & 0xff,ob);
  ((int (*)())_read_encoded_value_with_base_97c1c498)(*(uint *)(ob + 0x10) >> 0x15 & 0xff,baseAddress,x + 8,&xPcBegin);
  ((int (*)())_read_encoded_value_with_base_97c1c498)(*(uint *)(ob + 0x10) >> 0x15 & 0xff,baseAddress,y + 8,yPcBegin);
  result = 1;
  if (xPcBegin <= yPcBegin[0]) {
    if (xPcBegin < yPcBegin[0]) {
      result = 0xffffffff;
    }
    else {
      result = 0;
    }
  }
  return result;
}

/* _fde_mixed_encoding_compare @ 0x97c1ca84 (188 bytes) */
int _fde_mixed_encoding_compare(ob, x, y)
  undefined4 ob;
  int x;
  int y;
{
  undefined4 baseAddress;
  uint get_cie_encodingResult;
  undefined4 result;
  uint xPcBegin;
  uint yPcBegin [5];
  
  get_cie_encodingResult = ((int (*)())_get_cie_encoding)((x - *(int *)(x + 4)) + 4);
  baseAddress = ((int (*)())_base_from_object)(get_cie_encodingResult & 0xff,ob);
  ((int (*)())_read_encoded_value_with_base_97c1c498)(get_cie_encodingResult & 0xff,baseAddress,x + 8,&xPcBegin);
  get_cie_encodingResult = ((int (*)())_get_cie_encoding)((y - *(int *)(y + 4)) + 4);
  baseAddress = ((int (*)())_base_from_object)(get_cie_encodingResult & 0xff,ob);
  ((int (*)())_read_encoded_value_with_base_97c1c498)(get_cie_encodingResult & 0xff,baseAddress,y + 8,yPcBegin);
  result = 1;
  if (xPcBegin <= yPcBegin[0]) {
    if (xPcBegin < yPcBegin[0]) {
      result = 0xffffffff;
    }
    else {
      result = 0;
    }
  }
  return result;
}

/* _frame_heapsort @ 0x97c1cb40 (568 bytes) */
int _frame_heapsort(ob, fdeCompare, erratic)
  undefined4 ob;
  code *fdeCompare;
  int erratic;
{
  undefined4 tmp;
  undefined4 tmp2;
  int compareResult;
  int compareResult2;
  undefined4 r6Fwd;
  undefined4 r7Fwd;
  undefined4 r8Fwd;
  uint i;
  uint n;
  int leftChildIndexMinus1;
  undefined4 *a;
  int byteOffsetOfI2;
  uint heapBuildIndex;
  
  n = *(uint *)(erratic + 4);
  a = (undefined4 *)(erratic + 8);
  heapBuildIndex = n;
joined_r0x97c1cb68:
  if (heapBuildIndex == 0) {
    do {
      do {
        if (n < 2) {
          return;
        }
        n = n - 1;
        tmp = *a;
        *a = a[n];
        a[n] = tmp;
      } while (n < 2);
      leftChildIndexMinus1 = 0;
      heapBuildIndex = 0;
      do {
        i = leftChildIndexMinus1 + 2;
        if (i < n) {
          byteOffsetOfI2 = heapBuildIndex * 8;
          compareResult = (*fdeCompare)(ob,a[heapBuildIndex * 2 + 2],a[heapBuildIndex * 2 + 1],r6Fwd,r7Fwd,r8Fwd
                             ,tmp);
          if (compareResult < 1) {
            compareResult = heapBuildIndex << 2;
            goto LAB_97c1cd10;
          }
          compareResult = heapBuildIndex * 4;
          compareResult2 = (*fdeCompare)(ob,a[heapBuildIndex * 2 + 2],a[heapBuildIndex]);
          if (compareResult2 < 1) goto LAB_97c1cd10;
          tmp2 = a[heapBuildIndex];
          a[heapBuildIndex] = a[heapBuildIndex * 2 + 2];
          a[heapBuildIndex * 2 + 2] = tmp2;
        }
        else {
          compareResult = heapBuildIndex << 2;
          byteOffsetOfI2 = heapBuildIndex << 3;
LAB_97c1cd10:
          compareResult2 = (*fdeCompare)(ob,*(undefined4 *)((int)a + byteOffsetOfI2 + 4),
                             *(undefined4 *)(compareResult + (int)a));
          if (compareResult2 < 1) break;
          tmp2 = *(undefined4 *)(compareResult + (int)a);
          i = leftChildIndexMinus1 + 1;
          *(undefined4 *)(compareResult + (int)a) = *(undefined4 *)((int)a + byteOffsetOfI2 + 4);
          *(undefined4 *)((int)a + byteOffsetOfI2 + 4) = tmp2;
        }
        leftChildIndexMinus1 = i * 2;
        heapBuildIndex = i;
      } while (leftChildIndexMinus1 + 1U < n);
    } while( true );
  }
  heapBuildIndex = heapBuildIndex - 1;
  i = heapBuildIndex;
joined_r0x97c1cb84:
  do {
    leftChildIndexMinus1 = i * 2;
    if (n <= leftChildIndexMinus1 + 1U) goto joined_r0x97c1cb68;
    if (leftChildIndexMinus1 + 2U < n) {
      byteOffsetOfI2 = i * 8;
      compareResult = (*fdeCompare)(ob,a[i * 2 + 2],a[i * 2 + 1]);
      if (compareResult < 1) {
        compareResult = i << 2;
      }
      else {
        compareResult = i * 4;
        compareResult2 = (*fdeCompare)(ob,a[i * 2 + 2],a[i]);
        if (0 < compareResult2) {
          tmp = a[i];
          a[i] = a[i * 2 + 2];
          a[i * 2 + 2] = tmp;
          i = leftChildIndexMinus1 + 2U;
          goto joined_r0x97c1cb84;
        }
      }
    }
    else {
      compareResult = i << 2;
      byteOffsetOfI2 = i << 3;
    }
    compareResult2 = (*fdeCompare)(ob,*(undefined4 *)((int)a + byteOffsetOfI2 + 4),
                       *(undefined4 *)(compareResult + (int)a));
    if (compareResult2 < 1) goto joined_r0x97c1cb68;
    tmp = *(undefined4 *)(compareResult + (int)a);
    i = leftChildIndexMinus1 + 1;
    *(undefined4 *)(compareResult + (int)a) = *(undefined4 *)((int)a + byteOffsetOfI2 + 4);
    *(undefined4 *)((int)a + byteOffsetOfI2 + 4) = tmp;
  } while( true );
}

/* _classify_object_over_fdes @ 0x97c1cd78 (308 bytes) */
int _classify_object_over_fdes(ob, thisFde)
  uint *ob;
  int *thisFde;
{
  uint bits;
  int cie;
  uint objEncoding;
  uint sizeMask;
  int *last;
  undefined4 baseAddress;
  int count;
  int lastCie;
  uint encoding;
  uint pcBegin [7];
  
  lastCie = 0;
  count = 0;
  encoding = 0;
  baseAddress = 0;
  last = (int *)ob[5];
  do {
    if ((thisFde == last) || (*thisFde == 0)) {
      return count;
    }
    if (thisFde[1] != 0) {
      sizeMask = encoding & 0xff;
      cie = (int)thisFde + (4 - thisFde[1]);
      if (cie != lastCie) {
        encoding = ((int (*)())_get_cie_encoding)(cie);
        sizeMask = encoding & 0xff;
        baseAddress = ((int (*)())_base_from_object)(sizeMask,ob);
        bits = ob[4];
        objEncoding = bits >> 0x15 & 0xff;
        lastCie = cie;
        if (objEncoding == 0xff) {
          bits = (encoding & 0xff) << 0x15 | bits & 0xe01fffff;
        }
        else {
          if (objEncoding == encoding) goto LAB_97c1ce18;
          bits = bits | 0x20000000;
        }
        ob[4] = bits;
      }
LAB_97c1ce18:
      ((int (*)())_read_encoded_value_with_base_97c1c498)(sizeMask,baseAddress,thisFde + 2,pcBegin);
      sizeMask = ((int (*)())_size_of_encoded_value_97c1c3a4)(sizeMask);
      if (sizeMask < 4) {
        sizeMask = (1 << ((sizeMask & 7) << 3)) - 1;
      }
      else {
        sizeMask = 0xffffffff;
      }
      if (((pcBegin[0] & sizeMask) != 0) && (count = count + 1, pcBegin[0] < *ob)) {
        *ob = pcBegin[0];
      }
      last = (int *)ob[5];
    }
    thisFde = (int *)((int)thisFde + *thisFde + 4);
  } while( true );
}

/* _add_fdes @ 0x97c1ceac (332 bytes) */
int _add_fdes(ob, accu, thisFde)
  int ob;
  int *accu;
  int *thisFde;
{
  uint pcBegin;
  int cie;
  int count;
  undefined4 baseAddress;
  uint mixedEncoding;
  int *last;
  int lastCie;
  uint encoding;
  uint pcBeginValue [7];
  
  lastCie = 0;
  encoding = *(uint *)(ob + 0x10) >> 0x15 & 0xff;
  baseAddress = ((int (*)())_base_from_object)(encoding,ob);
  last = *(int **)(ob + 0x14);
  mixedEncoding = encoding;
  for (; (thisFde != last && (*thisFde != 0)); thisFde = (int *)((int)thisFde + *thisFde + 4)) {
    if (thisFde[1] != 0) {
      if (((*(uint *)(ob + 0x10) & 0x20000000) != 0) &&
         (cie = (int)thisFde + (4 - thisFde[1]), cie != lastCie)) {
        mixedEncoding = ((int (*)())_get_cie_encoding)(cie);
        encoding = mixedEncoding & 0xff;
        baseAddress = ((int (*)())_base_from_object)(encoding,ob);
        lastCie = cie;
      }
      if (mixedEncoding == 0) {
        pcBegin = thisFde[2];
      }
      else {
        ((int (*)())_read_encoded_value_with_base_97c1c498)(encoding,baseAddress,thisFde + 2,pcBeginValue);
        pcBegin = ((int (*)())_size_of_encoded_value_97c1c3a4)(encoding);
        if (pcBegin < 4) {
          pcBegin = (1 << ((pcBegin & 7) << 3)) - 1;
        }
        else {
          pcBegin = 0xffffffff;
        }
        pcBegin = pcBeginValue[0] & pcBegin;
      }
      if ((pcBegin != 0) && (cie = *accu, cie != 0)) {
        count = *(int *)(cie + 4);
        *(int *)(cie + 4) = count + 1;
        *(int **)(count * 4 + cie + 8) = thisFde;
      }
      last = *(int **)(ob + 0x14);
    }
  }
  return;
}

/* _linear_search_fdes @ 0x97c1cff8 (352 bytes) */
int _linear_search_fdes(ob, thisFde, pc)
  int ob;
  int *thisFde;
  int pc;
{
  int cie;
  undefined4 baseAddress;
  uint mixedEncoding;
  undefined4 read_encoded_value_with_baseResult;
  uint pcBegin;
  int *last;
  int lastCie;
  uint encoding;
  uint pcBeginValue;
  uint pcRange [6];
  
  lastCie = 0;
  encoding = *(uint *)(ob + 0x10) >> 0x15 & 0xff;
  baseAddress = ((int (*)())_base_from_object)(encoding,ob);
  last = *(int **)(ob + 0x14);
  mixedEncoding = encoding;
  do {
    if ((thisFde == last) || (*thisFde == 0)) {
      return (int *)0x0;
    }
    if (thisFde[1] != 0) {
      if (((*(uint *)(ob + 0x10) & 0x20000000) != 0) &&
         (cie = (int)thisFde + (4 - thisFde[1]), cie != lastCie)) {
        mixedEncoding = ((int (*)())_get_cie_encoding)(cie);
        encoding = mixedEncoding & 0xff;
        baseAddress = ((int (*)())_base_from_object)(encoding,ob);
        lastCie = cie;
      }
      if (mixedEncoding == 0) {
        pcBeginValue = thisFde[2];
        pcRange[0] = thisFde[3];
        pcBegin = pcBeginValue;
      }
      else {
        read_encoded_value_with_baseResult = ((int (*)())_read_encoded_value_with_base_97c1c498)(encoding,baseAddress,thisFde + 2,&pcBeginValue);
        ((int (*)())_read_encoded_value_with_base_97c1c498)(mixedEncoding & 0xf,0,read_encoded_value_with_baseResult,pcRange);
        pcBegin = ((int (*)())_size_of_encoded_value_97c1c3a4)(encoding);
        if (pcBegin < 4) {
          pcBegin = (1 << ((pcBegin & 7) << 3)) - 1;
        }
        else {
          pcBegin = 0xffffffff;
        }
        pcBegin = pcBeginValue & pcBegin;
      }
      if ((pcBegin != 0) && (pc - pcBeginValue < pcRange[0])) {
        return thisFde;
      }
      last = *(int **)(ob + 0x14);
    }
    thisFde = (int *)((int)thisFde + *thisFde + 4);
  } while( true );
}

/* _search_object @ 0x97c1d158 (624 bytes) */
int _search_object(ob, pc)
  uint *ob;
  uint pc;
{
  uint mixedMid;
  uint mixedLo;
  uint singleHi;
  uint mixedVec;
  uint unencodedLo;
  uint hi;
  uint get_cie_encodingResult;
  int linear_search_fdesResult;
  undefined4 baseAddress;
  uint objectBits;
  uint singleLo;
  undefined4 read_encoded_value_with_baseResult;
  undefined4 read_encoded_value_with_baseResult2;
  uint encoding;
  uint singleVec;
  uint unencodedMid;
  uint singleMid;
  int *arrayCursor;
  int f;
  uint mixedPcBegin;
  int mixedPcRange;
  uint singlePcBegin;
  int singlePcRange [3];
  
  objectBits = ob[4];
  if (-1 < (int)objectBits) {
    ((int (*)())_init_object)(ob);
    if (pc < *ob) {
      return 0;
    }
    objectBits = ob[4];
  }
  if ((int)objectBits < 0) {
    if ((objectBits & 0x20000000) == 0) {
      encoding = objectBits >> 0x15 & 0xff;
      if (encoding == 0) {
        unencodedLo = 0;
        hi = *(uint *)(ob[3] + 4);
        if (hi != 0) {
          do {
            unencodedMid = unencodedLo + hi >> 1;
            f = *(int *)(unencodedMid * 4 + ob[3] + 8);
            if ((*(uint *)(f + 8) <= pc) &&
               (unencodedLo = unencodedMid + 1, unencodedMid = hi,
               pc < *(uint *)(f + 8) + *(int *)(f + 0xc))) {
              return f;
            }
            hi = unencodedMid;
          } while (unencodedLo < unencodedMid);
        }
      }
      else {
        singleVec = ob[3];
        baseAddress = ((int (*)())_base_from_object)(encoding,ob);
        singleHi = *(uint *)(singleVec + 4);
        singleLo = 0;
        if (singleHi != 0) {
          do {
            singleMid = singleLo + singleHi >> 1;
            f = *(int *)(singleMid * 4 + singleVec + 8);
            read_encoded_value_with_baseResult2 = ((int (*)())_read_encoded_value_with_base_97c1c498)(encoding,baseAddress,f + 8,&singlePcBegin);
            ((int (*)())_read_encoded_value_with_base_97c1c498)(objectBits >> 0x15 & 0xf,0,read_encoded_value_with_baseResult2,singlePcRange);
            if ((singlePcBegin <= pc) &&
               (singleLo = singleMid + 1, singleMid = singleHi, pc < singlePcBegin + singlePcRange[0])) {
              return f;
            }
            singleHi = singleMid;
          } while (singleLo < singleMid);
        }
      }
    }
    else {
      mixedVec = ob[3];
      mixedLo = 0;
      hi = *(uint *)(mixedVec + 4);
      if (hi != 0) {
        do {
          mixedMid = mixedLo + hi >> 1;
          f = *(int *)(mixedMid * 4 + mixedVec + 8);
          get_cie_encodingResult = ((int (*)())_get_cie_encoding)((f - *(int *)(f + 4)) + 4);
          baseAddress = ((int (*)())_base_from_object)(get_cie_encodingResult & 0xff,ob);
          read_encoded_value_with_baseResult = ((int (*)())_read_encoded_value_with_base_97c1c498)(get_cie_encodingResult & 0xff,baseAddress,f + 8,&mixedPcBegin);
          ((int (*)())_read_encoded_value_with_base_97c1c498)(get_cie_encodingResult & 0xf,0,read_encoded_value_with_baseResult,&mixedPcRange);
          if ((mixedPcBegin <= pc) &&
             (mixedLo = mixedMid + 1, mixedMid = hi, pc < mixedPcBegin + mixedPcRange)) {
            return f;
          }
          hi = mixedMid;
        } while (mixedLo < mixedMid);
      }
    }
  }
  else {
    if ((objectBits & 0x40000000) == 0) {
      linear_search_fdesResult = ((int (*)())_linear_search_fdes)(ob,ob[3],pc);
      return linear_search_fdesResult;
    }
    arrayCursor = (int *)ob[3];
    f = *arrayCursor;
    while (f != 0) {
      linear_search_fdesResult = ((int (*)())_linear_search_fdes)(ob,f,pc);
      if (linear_search_fdesResult != 0) {
        return linear_search_fdesResult;
      }
      arrayCursor = arrayCursor + 1;
      f = *arrayCursor;
    }
  }
  return 0;
}

/* __Unwind_Find_registered_FDE @ 0x97c1d3c8 (356 bytes) */
int __Unwind_Find_registered_FDE(pc, bases)
  uint pc;
  uint *bases;
{
  uint *nextSlot;
  bool notFound;
  uint *cursor;
  uint encoding;
  undefined4 baseAddress;
  uint *linkSlot;
  int ret;
  uint *ob;
  
  ret = 0;
  for (ob = _seen_objects; ob != (uint *)0x0; ob = (uint *)ob[6]) {
    if (*ob <= pc) {
      ret = ((int (*)())_search_object)(ob,pc);
      if (ret != 0) goto LAB_97c1d4c0;
      break;
    }
  }
  ob = _unseen_objects;
  if (_unseen_objects == (uint *)0x0) {
    notFound = ret == 0;
  }
  else {
    do {
      _unseen_objects = (uint *)ob[6];
      ret = ((int (*)())_search_object)(ob,pc);
      linkSlot = (uint *)&_seen_objects;
      cursor = _seen_objects;
      if (_seen_objects != (uint *)0x0) {
        do {
          if (*cursor < *ob) goto LAB_97c1d498;
          nextSlot = cursor + 6;
          linkSlot = cursor + 6;
          cursor = (uint *)*nextSlot;
        } while ((uint *)*nextSlot != (uint *)0x0);
        cursor = (uint *)0x0;
      }
LAB_97c1d498:
      ob[6] = (uint)cursor;
      *linkSlot = (uint)ob;
      if (ret != 0) goto LAB_97c1d4c0;
      ob = _unseen_objects;
    } while (_unseen_objects != (uint *)0x0);
    notFound = true;
  }
  ob = _unseen_objects;
  if (!notFound) {
LAB_97c1d4c0:
    *bases = ob[1];
    bases[1] = ob[2];
    encoding = ob[4] >> 0x15 & 0xff;
    if ((ob[4] & 0x20000000) != 0) {
      encoding = ((int (*)())_get_cie_encoding)((ret - *(int *)(ret + 4)) + 4);
    }
    baseAddress = ((int (*)())_base_from_object)(encoding & 0xff,ob);
    ((int (*)())_read_encoded_value_with_base_97c1c498)(encoding & 0xff,baseAddress,ret + 8,bases + 2);
  }
  return ret;
}

/* _live_image_destructor @ 0x97c1d52c (196 bytes) */
int _live_image_destructor(image)
  int image;
{
  undefined4 *objectState;
  
  if (*(int *)(image + 0x1c) != 0) {
    objectState = (undefined4 *)__keymgr_get_and_lock_processwide_ptr(0x12e);
    if (objectState != (undefined4 *)0x0) {
      _seen_objects = *objectState;
      _unseen_objects = objectState[1];
      ((int (*)())___deregister_frame_info_bases)(*(void **)(image + 0x18));
      *objectState = _seen_objects;
      objectState[1] = _unseen_objects;
    }
    __keymgr_set_and_unlock_processwide_ptr(0x12e,objectState);
    _free(*(undefined4 *)(image + 0x1c));
    *(undefined4 *)(image + 0x1c) = 0;
    if ((*(uint *)(image + 0x14) & 2) != 0) {
      _free(*(undefined4 *)(image + 0x18));
    }
    *(undefined4 *)(image + 0x18) = 0;
  }
  *(undefined4 *)(image + 0xc) = 0;
  *(undefined4 *)(image + 0x14) = 0;
  return;
}

/* __Unwind_Find_FDE @ 0x97c1d5f0 (224 bytes) */
int __Unwind_Find_FDE(pc, bases)
  void *pc;
  dwarf_eh_bases *bases;
{
  bool dontAlloc;
  undefined4 *objectState;
  void *fde;
  
  objectState = (undefined4 *)__keymgr_get_and_lock_processwide_ptr(0x12e);
  dontAlloc = objectState == (undefined4 *)0x0;
  if (dontAlloc) {
    objectState = (undefined4 *)_calloc(1,0x10);
    dontAlloc = objectState == (undefined4 *)0x0;
    if (!dontAlloc) goto LAB_97c1d644;
  }
  else {
LAB_97c1d644:
    _seen_objects = *objectState;
    _unseen_objects = objectState[1];
    fde = (void *)((int (*)())__Unwind_Find_registered_FDE)(pc,bases);
    if (fde != (void *)0x0) goto LAB_97c1d688;
  }
  fde = (void *)((int (*)())_examine_objects)(pc,bases,(uint)dontAlloc);
LAB_97c1d688:
  if (!dontAlloc) {
    *objectState = _seen_objects;
    objectState[1] = _unseen_objects;
  }
  __keymgr_set_and_unlock_processwide_ptr(0x12e,objectState);
  return fde;
}

/* _init_object @ 0x97c1d6d0 (732 bytes) */
int _init_object(ob)
  uint ob;
{
  undefined4 fde2;
  int erraticAlias;
  int vectorBytes;
  bool linearEmpty;
  undefined4 *srcSlot;
  bool noFdes;
  undefined4 *v1;
  int arrayEntry;
  uint objectBits;
  uint classifyResult;
  int compareResult;
  undefined4 r3AfterFree;
  undefined4 *v2ArrayCursor;
  code *fdeCompare;
  undefined4 *v1IndexBase;
  int i2;
  undefined4 returnValue;
  int i1;
  uint totalCount;
  uint count;
  undefined4 *dstSlot;
  int *arrayCursor;
  undefined4 *v1Cursor;
  undefined4 *linearVec;
  int erraticVec;
  
  objectBits = *(uint *)(ob + 0x10);
  count = objectBits & 0x1fffff;
  if (count == 0) {
    if ((objectBits & 0x40000000) == 0) {
      classifyResult = ((int (*)())_classify_object_over_fdes)(ob,*(undefined4 *)(ob + 0xc));
      objectBits = *(uint *)(ob + 0x10);
      noFdes = classifyResult == 0;
      count = classifyResult;
    }
    else {
      arrayCursor = *(int **)(ob + 0xc);
      arrayEntry = *arrayCursor;
      noFdes = true;
      totalCount = 0;
      classifyResult = ob;
      if (arrayEntry != 0) {
        do {
          classifyResult = ((int (*)())_classify_object_over_fdes)(ob,arrayEntry);
          arrayCursor = arrayCursor + 1;
          arrayEntry = *arrayCursor;
          totalCount = totalCount + classifyResult;
        } while (arrayEntry != 0);
        objectBits = *(uint *)(ob + 0x10);
        noFdes = totalCount == 0;
        count = totalCount;
      }
    }
    *(uint *)(ob + 0x10) = count & 0x1fffff | objectBits & 0xffe00000;
    if ((count & 0x1fffff) != count) {
      *(uint *)(ob + 0x10) = objectBits & 0xffe00000;
    }
    if (noFdes) {
      return classifyResult;
    }
  }
  vectorBytes = count * 4 + 8;
  linearVec = (undefined4 *)_malloc(vectorBytes);
  returnValue = 0;
  if (linearVec != (undefined4 *)0x0) {
    linearVec[1] = 0;
    erraticVec = _malloc(vectorBytes);
    if (erraticVec != 0) {
      *(undefined4 *)(erraticVec + 4) = 0;
    }
    if ((*(uint *)(ob + 0x10) & 0x40000000) == 0) {
      ((int (*)())_add_fdes)(ob,&linearVec,*(undefined4 *)(ob + 0xc));
    }
    else {
      arrayCursor = *(int **)(ob + 0xc);
      arrayEntry = *arrayCursor;
      while (arrayEntry != 0) {
        ((int (*)())_add_fdes)(ob,&linearVec,arrayEntry);
        arrayCursor = arrayCursor + 1;
        arrayEntry = *arrayCursor;
      }
    }
    if ((linearVec != (undefined4 *)0x0) && (linearVec[1] != count)) {
LAB_97c1d890:
                    
      _abort();
    }
    fdeCompare = DAT_a7b7c094;
    if (((*(uint *)(ob + 0x10) & 0x20000000) == 0) &&
       (fdeCompare = DAT_a7b7c08c, (*(uint *)(ob + 0x10) >> 0x15 & 0xff) == 0)) {
      fdeCompare = DAT_a7b7c090;
    }
    if (erraticVec == 0) {
      returnValue = ((int (*)())_frame_heapsort)(ob,fdeCompare,linearVec);
    }
    else {
      ((int (*)())_fde_split)(ob,fdeCompare,linearVec,erraticVec);
      if (linearVec[1] + *(int *)(erraticVec + 4) != count) goto LAB_97c1d890;
      ((int (*)())_frame_heapsort)(ob,fdeCompare,erraticVec);
      erraticAlias = erraticVec;
      v1 = linearVec;
      i2 = *(int *)(erraticVec + 4);
      if (i2 != 0) {
        i1 = linearVec[1];
        v1IndexBase = linearVec + i2;
        linearEmpty = i1 == 0;
        v2ArrayCursor = (undefined4 *)(i2 * 4 + erraticVec + 8);
        do {
          v1IndexBase = v1IndexBase + -1;
          i2 = i2 + -1;
          dstSlot = v1IndexBase + i1 + 2;
          v1Cursor = v1 + i1;
          v2ArrayCursor = v2ArrayCursor + -1;
          fde2 = *v2ArrayCursor;
          while ((!linearEmpty && (compareResult = (*fdeCompare)(ob,v1Cursor[1],fde2), 0 < compareResult))) {
            srcSlot = v1Cursor + 1;
            i1 = i1 + -1;
            linearEmpty = i1 == 0;
            v1Cursor = v1Cursor + -1;
            *dstSlot = *srcSlot;
            dstSlot = dstSlot + -1;
          }
          v1[i1 + i2 + 2] = fde2;
        } while (i2 != 0);
        v1[1] = v1[1] + *(int *)(erraticAlias + 4);
      }
      _free(erraticVec);
      returnValue = r3AfterFree;
    }
    *linearVec = *(undefined4 *)(ob + 0xc);
    *(uint *)(ob + 0x10) = *(uint *)(ob + 0x10) | 0x80000000;
    *(undefined4 **)(ob + 0xc) = linearVec;
  }
  return returnValue;
}

/* _examine_objects @ 0x97c1d9ac (556 bytes) */
int _examine_objects(pc, bases, dontAlloc)
  undefined4 pc;
  uint *bases;
  uint dontAlloc;
{
  uint encoding;
  undefined4 baseAddress;
  uint *curNextLink;
  uint *cur;
  int image;
  int getsectdatafromheaderResult;
  undefined4 destructor;
  uint *prevLink;
  uint *ob;
  int ret;
  uint realFde;
  uint panicob [8];
  int sectionSize [7];
  
  image = __keymgr_get_and_lock_processwide_ptr(0x12d);
  destructor = DAT_a7b7c088;
  ret = 0;
  do {
    if (image == 0) {
LAB_97c1dbb0:
      __keymgr_unlock_processwide_ptr(0x12d);
      return ret;
    }
    if ((*(uint *)(image + 0x14) & 1) == 0) {
      getsectdatafromheaderResult = _getsectdatafromheader(*(undefined4 *)(image + 4),"__DATA","__eh_frame",sectionSize);
      if (getsectdatafromheaderResult == 0) {
        getsectdatafromheaderResult = _getsectdatafromheader(*(undefined4 *)(image + 4),"__TEXT","__eh_frame",sectionSize);
        if (getsectdatafromheaderResult != 0) {
          *(uint *)(image + 0x14) = *(uint *)(image + 0x14) | 4;
          goto LAB_97c1da58;
        }
      }
      else {
LAB_97c1da58:
        if (sectionSize[0] != 0) {
          ob = (uint *)0x0;
          realFde = getsectdatafromheaderResult + *(int *)(image + 8);
          if (dontAlloc == 0) {
            ob = (uint *)_calloc(1,0x1c);
          }
          dontAlloc = dontAlloc | ob == (uint *)0x0;
          if (dontAlloc != 0) {
            ob = panicob;
          }
          ob[3] = realFde;
          *ob = 0xffffffff;
          ob[4] = 0x1fe00000;
          ob[1] = 0;
          ob[2] = 0;
          ob[5] = realFde + sectionSize[0];
          *(uint *)(image + 0x18) = realFde;
          ret = ((int (*)())_search_object)(ob,pc);
          if (dontAlloc == 0) {
            *(undefined4 *)(image + 0xc) = destructor;
            prevLink = (uint *)&_seen_objects;
            *(uint **)(image + 0x1c) = ob;
            *(uint *)(image + 0x14) = *(uint *)(image + 0x14) | 9;
            cur = _seen_objects;
            if (_seen_objects != (uint *)0x0) {
              do {
                if (*cur < *ob) goto LAB_97c1db30;
                curNextLink = cur + 6;
                prevLink = cur + 6;
                cur = (uint *)*curNextLink;
              } while ((uint *)*curNextLink != (uint *)0x0);
              cur = (uint *)0x0;
            }
LAB_97c1db30:
            ob[6] = (uint)cur;
            *prevLink = (uint)ob;
          }
          if (ret == 0) goto LAB_97c1dba4;
          *bases = ob[1];
          bases[1] = ob[2];
          encoding = ob[4] >> 0x15 & 0xff;
          if ((ob[4] & 0x20000000) != 0) {
            encoding = ((int (*)())_get_cie_encoding)((ret - *(int *)(ret + 4)) + 4);
          }
          baseAddress = ((int (*)())_base_from_object)(encoding & 0xff,ob);
          ((int (*)())_read_encoded_value_with_base_97c1c498)(encoding & 0xff,baseAddress,ret + 8,bases + 2);
          goto LAB_97c1dbb0;
        }
      }
      *(uint *)(image + 0x14) = *(uint *)(image + 0x14) | 1;
    }
LAB_97c1dba4:
    image = *(int *)(image + 0x10);
  } while( true );
}

/* _fde_split @ 0x97c1dbd8 (296 bytes) */
int _fde_split(ob, fdeCompare, linear, erratic)
  undefined4 ob;
  code *fdeCompare;
  int linear;
  int erratic;
{
  int markerValue;
  int erraticCount;
  int *src;
  int *marker;
  int *dstErratic;
  int *dstLinear;
  uint n;
  uint loopIndex;
  undefined4 *prevLink;
  undefined4 *chain;
  undefined4 *linearElement;
  undefined4 *markerElement;
  int linearCount;
  
  loopIndex = 0;
  n = *(uint *)(linear + 4);
  if (n != 0) {
    markerElement = (undefined4 *)(erratic + 8);
    linearElement = (undefined4 *)(linear + 8);
    chain = &_marker_0;
    linearCount = linear;
    do {
      while ((chain != &_marker_0 && (erraticCount = (*fdeCompare)(ob,*linearElement,*chain), erraticCount < 0)))
      {
        prevLink = *(undefined4 **)((int)chain + (erratic - linear));
        *(undefined4 *)((int)chain + (erratic - linear)) = 0;
        chain = prevLink;
      }
      loopIndex = loopIndex + 1;
      *markerElement = chain;
      chain = (undefined4 *)(linearCount + 8);
      linearElement = linearElement + 1;
      markerElement = markerElement + 1;
      linearCount = linearCount + 4;
    } while (loopIndex < n);
  }
  erraticCount = 0;
  linearCount = 0;
  if (n != 0) {
    src = (int *)(linear + 8);
    marker = (int *)(erratic + 8);
    dstErratic = marker;
    dstLinear = src;
    do {
      markerValue = *marker;
      marker = marker + 1;
      if (markerValue == 0) {
        erraticCount = erraticCount + 1;
        *dstErratic = *src;
        dstErratic = dstErratic + 1;
      }
      else {
        linearCount = linearCount + 1;
        *dstLinear = *src;
        dstLinear = dstLinear + 1;
      }
      src = src + 1;
      n = n - 1;
    } while (n != 0);
  }
  *(int *)(linear + 4) = linearCount;
  *(int *)(erratic + 4) = erraticCount;
  return;
}

/* save_world @ 0x97c1dd00 (252 bytes) */
int save_world()
{
  int r11In;
  int globalWord;
  
  globalWord = *(int *)PTR_DAT_a7b7c100;
  *(unsigned char **)(&STACKARG(0x0) + r11In) = ((unsigned int)__builtin_frame_address(0));
  if (globalWord == 0) {
    return;
  }
  return;
}

/* eh_rest_world_r10 @ 0x97c1de10 (264 bytes) */
int eh_rest_world_r10(r3In, r4In, r5In, r6In, r7In, r8In, r9In, r10In)
  undefined4 r3In;
  undefined4 r4In;
  undefined4 r5In;
  undefined4 r6In;
  undefined4 r7In;
  undefined4 r8In;
  undefined4 r9In;
  undefined4 r10In;
{
  
                    
                    
  (**(code **)((*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x0)) + 8))
            (*(undefined4 *)((*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x0)) + -0x1b0),*(undefined4 *)((*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x0)) + -0x1ac)
             ,*(undefined4 *)((*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x0)) + -0x1a8),
             *(undefined4 *)((*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x0)) + -0x1a4),r10In,*(code **)((*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x0)) + 8),
             r9In,r10In);
  return;
}

/* __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_ @ 0x97c30ae0 (4 bytes) */
int __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_(this, str, pool_allocator)
  void *this;
  char *str;
  unsigned char * pool_allocator;
{
  return ((int (*)())__ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC4EPKcRKS2_)(this,str,pool_allocator);
}

/* __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC4EPKcRKS2_ @ 0x97c30ae4 (100 bytes) */
int __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC4EPKcRKS2_(this, str, alloc)
  void *this;
  char *str;
  unsigned char * alloc;
{
  char *newData;
  undefined4 poolAlloc;
  size_t length;
  char *endPtr;
  
  if (str == (char *)0x0) {
    endPtr = (char *)0xffffffff;
  }
  else {
    length = _strlen(str);
    endPtr = str + length;
  }
  newData = ((int (*)())__ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE12_S_constructIPKcEEPcT_S8_RKS2_St20forward_iterator_tag)(str,endPtr,alloc,0);
  poolAlloc = *(undefined4 *)alloc;
  *(char **)((int)this + 4) = newData;
  *(undefined4 *)this = poolAlloc;
  return;
}

/* __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_ @ 0x97c30b48 (4 bytes) */
int __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(this, text)
  void *this;
  unsigned char * text;
{
  return ((int (*)())__ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC4ERKS3_)(this,text);
}

/* __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC4ERKS3_ @ 0x97c30b4c (148 bytes) */
int __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC4ERKS3_(this, text)
  void *this;
  unsigned char * text;
{
  int atomicStore;
  int *refCountPtr;
  undefined4 allocWord;
  int adoptedData;
  char reservation;
  byte cr0Reg;
  int globalAlloc [4];
  int srcPool;
  
  adoptedData = *(int *)(text + 4);
  globalAlloc[0] = GetGlobalPoolAllocator();
  srcPool = *(int *)text;
  if ((*(int *)(adoptedData + -4) < 0) || (globalAlloc[0] != srcPool)) {
    adoptedData = ((int (*)())__ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep8_M_cloneERKS2_m)((void *)(adoptedData + -0xc),(unsigned char *)globalAlloc,0);
  }
  else {
    refCountPtr = (int *)(adoptedData + -4);
    do {
      if (reservation != '\0') {
        atomicStore = storeWordConditionalIndexed(*refCountPtr + 1,0,refCountPtr);
        *refCountPtr = atomicStore;
        cr0Reg = 2;
      }
    } while (!(bool)(cr0Reg >> 1 & 1));
  }
  allocWord = *(undefined4 *)text;
  *(int *)((int)this + 4) = adoptedData;
  *(undefined4 *)this = allocWord;
  return;
}

/* std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique @ 0x97c30be0 (388 bytes) */
int std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique(retPair, tree, value)
  unsigned char * retPair;
  unsigned char * tree;
  int value;
{
  uint valueKeySize;
  uint jKeySize;
  int cmp2;
  int jNode;
  int cmp;
  int comp;
  uint *minRef;
  void *keyChars;
  int header;
  int y;
  int x;
  uint keySize;
  uint nodeKeySize;
  int j [4];
  int leftmost [4];
  int insertResult [4];
  uint keySizeCopy;
  uint nodeKeySizeCopy;
  uint jKeySizeCopy;
  uint keySizeCopy2;
  
  header = *(int *)(tree + 4);
  comp = 1;
  y = header;
  if (*(int *)(header + 4) != 0) {
    keyChars = *(void **)(value + 4);
    x = *(int *)(header + 4);
    do {
      y = x;
      keySize = *(uint *)((int)keyChars + -0xc);
      keySizeCopy = keySize;
      nodeKeySize = *(uint *)(*(int *)(y + 0x14) + -0xc);
      nodeKeySizeCopy = nodeKeySize;
      minRef = &nodeKeySizeCopy;
      if (keySize <= nodeKeySize) {
        minRef = &keySizeCopy;
      }
      cmp = _memcmp(keyChars,*(void **)(y + 0x14),*minRef);
      if (cmp == 0) {
        cmp = keySize - nodeKeySize;
      }
      comp = -(cmp >> 0x1f);
      if (comp == 0) {
        x = *(int *)(y + 0xc);
      }
      else {
        x = *(int *)(y + 8);
      }
    } while (x != 0);
  }
  j[0] = y;
  if (comp != 0) {
    leftmost[0] = *(int *)(header + 8);
    if (y == leftmost[0]) {
      std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol_______M_insert((unsigned char *)insertResult,tree,(unsigned char *)0x0,y,value);
      goto LAB_97c30d34;
    }
    std___Rb_tree_base_iterator___M_decrement((unsigned char *)j);
  }
  jNode = j[0];
  minRef = &keySizeCopy2;
  jKeySize = *(uint *)(*(int *)(j[0] + 0x14) + -0xc);
  jKeySizeCopy = jKeySize;
  valueKeySize = *(uint *)((int)*(void **)(value + 4) + -0xc);
  keySizeCopy2 = valueKeySize;
  if (jKeySize <= valueKeySize) {
    minRef = &jKeySizeCopy;
  }
  cmp2 = _memcmp(*(void **)(j[0] + 0x14),*(void **)(value + 4),*minRef);
  if (cmp2 == 0) {
    cmp2 = jKeySize - valueKeySize;
  }
  if (-1 < cmp2) {
    *(int *)retPair = jNode;
    *(undefined4 *)(retPair + 4) = 0;
    return retPair;
  }
  std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol_______M_insert((unsigned char *)leftmost,tree,(unsigned char *)0x0,y,value);
  insertResult[0] = leftmost[0];
LAB_97c30d34:
  *(int *)retPair = insertResult[0];
  *(undefined4 *)(retPair + 4) = 1;
  return retPair;
}

/* __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_ @ 0x97c30d64 (12 bytes) */
int __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_(this, pool_allocator)
  unsigned char * this;
  undefined4 pool_allocator;
{
  return;
}

/* __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE12_S_constructIPKcEEPcT_S8_RKS2_St20forward_iterator_tag @ 0x97c30d70 (196 bytes) */
int __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE12_S_constructIPKcEEPcT_S8_RKS2_St20forward_iterator_tag(first, last, alloc)
  void *first;
  void *last;
  unsigned char * alloc;
{
  int atomicStore;
  int emptyRep;
  int *refCountPtr;
  int globalPool;
  ulong *rep;
  ulong length;
  ulong *newData;
  char reservation;
  byte cr0Reg;
  
  if ((first == last) &&
     (globalPool = GetGlobalPoolAllocator(), emptyRep = (*(int *)&DAT_a7b7b71c), *(int *)alloc == globalPool)) {
    refCountPtr = (int *)((*(int *)&DAT_a7b7b71c) + 8);
    do {
      if (reservation != '\0') {
        atomicStore = storeWordConditionalIndexed(*refCountPtr + 1,0,refCountPtr);
        *refCountPtr = atomicStore;
        cr0Reg = 2;
      }
    } while (!(bool)(cr0Reg >> 1 & 1));
    return (char *)(emptyRep + 0xc);
  }
  if (first == (void *)0x0) {
    std____throw_logic_error("attempt to create string with null pointer");
  }
  length = (int)last - (int)first;
  rep = (ulong *)__ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep9_S_createEmRKS2_
                              (length,alloc);
  newData = rep + 3;
  _memcpy(newData,first,length);
  *rep = length;
  *(char *)((int)newData + length) = '\0';
  return (char *)newData;
}

/* __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep8_M_cloneERKS2_m @ 0x97c30e34 (148 bytes) */
int __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep8_M_cloneERKS2_m(this, alloc, extra)
  void *this;
  unsigned char * alloc;
  ulong extra;
{
  uint requested;
  undefined4 *newRep;
  undefined4 copiedLength;
  uint newCapacity;
  
  requested = *(int *)this + extra;
  newCapacity = requested;
  if (((*(uint *)((int)this + 4) < requested) && (0xfe3 < requested)) &&
     (newCapacity = *(uint *)((int)this + 4) << 1, newCapacity < requested)) {
    newCapacity = requested;
  }
  newRep = (undefined4 *)
           __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep9_S_createEmRKS2_(newCapacity,alloc);
  copiedLength = 0;
  if (*(size_t *)this != 0) {
    _memcpy(newRep + 3,(void *)((int)this + 0xc),*(size_t *)this);
    copiedLength = *(undefined4 *)this;
  }
  *newRep = copiedLength;
  return newRep + 3;
}

