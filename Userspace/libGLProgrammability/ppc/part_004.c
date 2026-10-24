#include "decls.h"

/* TIntermOperator__isConstructor @ 0x97b90474 (24 bytes) */
int TIntermOperator__isConstructor(this)
  unsigned char * this;
{
  return *(int *)(this + 0x30) - 0x66U < 0x10;
}

/* TIntermUnary__promote @ 0x97b9048c (304 bytes) */
int TIntermUnary__promote(this)
  unsigned char * this;
{
  int operandBasicType;
  bool operandTypeMatches;
  int op;
  undefined1 operandType [56];
  
  op = *(int *)(this + 0x30);
  if (op == 8) {
    operandBasicType = (**(code **)(**(int **)(this + 0x34) + 0x40))(*(int **)(this + 0x34));
    operandTypeMatches = operandBasicType == 2;
LAB_97b9055c:
    if (!operandTypeMatches) {
      return 0;
    }
  }
  else {
    if (op < 9) {
      if (op == 6) {
        operandBasicType = (**(code **)(**(int **)(this + 0x34) + 0x40))(*(int **)(this + 0x34));
        operandTypeMatches = operandBasicType == 3;
        goto LAB_97b9055c;
      }
      if (6 < op) {
        return 1;
      }
      if (op != 5) goto LAB_97b90544;
    }
    else if (0xc < op) {
      if (op - 0x57U < 2) {
        return 1;
      }
LAB_97b90544:
      operandBasicType = (**(code **)(**(int **)(this + 0x34) + 0x40))(*(int **)(this + 0x34));
      operandTypeMatches = operandBasicType == 1;
      goto LAB_97b9055c;
    }
    operandBasicType = (**(code **)(**(int **)(this + 0x34) + 0x40))(*(int **)(this + 0x34));
    if (operandBasicType == 3) {
      return 0;
    }
  }
  (**(code **)(**(int **)(this + 0x34) + 0x38))(operandType,*(int **)(this + 0x34));
  (**(code **)(*(int *)this + 0x34))(this,operandType);
  return 1;
}

/* TIntermBinary__promote @ 0x97b905bc (1680 bytes) */
int TIntermBinary__promote(this, infoSink, scratchR5, scratchR6, scratchR7, scratchR8)
  unsigned char * this;
  unsigned char * infoSink;
  undefined4 scratchR5;
  undefined4 scratchR6;
  undefined4 scratchR7;
  undefined4 scratchR8;
{
  int leftNominalSizeQuery;
  int rightIsVectorQuery;
  int leftIsVectorQuery;
  int sizeInBytes;
  int leftIsMatrixQuery;
  int rightBasicTypeQuery;
  int leftBasicTypeQuery;
  int thisVtable;
  int operatorCode;
  int leftIsArrayQuery;
  undefined4 newOperator;
  int resultIsMatrix;
  int rightNominalSize;
  int leftMatrixFlag;
  int rightMatrixFlag;
  bool operandTypesMatch;
  undefined *atomicStore;
  undefined **refCountPtr;
  undefined4 scratchR4;
  undefined *oldRefCount;
  uint resultNominalSize;
  int rightNominalSizeQuery;
  uint leftBasicType;
  uint leftNominalSize;
  uint leftIsMatrix;
  int rightBasicType;
  undefined4 infoSinkCopy;
  undefined4 r4Out0;
  undefined4 r4Out1;
  undefined4 r4Out2;
  undefined4 r4Out3;
  undefined4 r4Out4;
  undefined4 r4Out5;
  undefined4 r4Out6;
  undefined4 r4Out7;
  undefined4 r4Out8;
  undefined4 r4Out9;
  code *setTypeFn;
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
  char typeTempOverlay [8];
  int typeTempStructure;
  unsigned char allocatorDummy [4];
  uint typeTempBits;
  
  resultNominalSize = (**(code **)(**(int **)(this + 0x34) + 0x48))
                    (*(int **)(this + 0x34),infoSink,scratchR5,scratchR6,scratchR7,scratchR8);
  rightNominalSizeQuery = (**(code **)(**(int **)(this + 0x38) + 0x48))(*(int **)(this + 0x38));
  if ((int)resultNominalSize < rightNominalSizeQuery) {
    resultNominalSize = (**(code **)(**(int **)(this + 0x38) + 0x48))(*(int **)(this + 0x38));
  }
  leftBasicType = (**(code **)(**(int **)(this + 0x34) + 0x40))(*(int **)(this + 0x34));
  leftIsArrayQuery = (**(code **)(**(int **)(this + 0x34) + 0x54))(*(int **)(this + 0x34));
  if (leftIsArrayQuery != 0) {
    return 0;
  }
  stackTypeArraySize = (**(code **)(**(int **)(this + 0x38) + 0x54))(*(int **)(this + 0x38));
  if (stackTypeArraySize != 0) {
    return 0;
  }
  leftNominalSize = (**(code **)(**(int **)(this + 0x34) + 0x48))(*(int **)(this + 0x34));
  leftIsMatrix = (**(code **)(**(int **)(this + 0x34) + 0x50))(*(int **)(this + 0x34));
  stackTypeBits = (leftIsMatrix & 1) << 10 | (leftNominalSize & 0xff) << 0xb | (leftBasicType & 0x3f) << 0x13 | stackTypeBits & 0x1ff;
  stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  stackTypeStructure = stackTypeArraySize;
  stackTypeFieldName = stackTypeArraySize;
  stackTypeTypeName = stackTypeArraySize;
  stackTypeWord14 = stackTypeArraySize;
  stackTypeStructureSize = stackTypeArraySize;
  stackTypeWord1c = stackTypeArraySize;
  stackTypeWord20 = stackTypeArraySize;
  (**(code **)(*(int *)this + 0x34))(this,&stackType);
  stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  if (resultNominalSize == 1) {
    operatorCode = *(int *)(this + 0x30);
    if (operatorCode < 0x25) {
      if (0x20 < operatorCode) {
LAB_97b90770:
        thisVtable = *(int *)this;
        stackTypeBits = stackTypeBits & 0x1801ff;
        goto LAB_97b90850;
      }
      if (0x16 < operatorCode) {
        if (operatorCode < 0x1d) {
          leftBasicTypeQuery = (**(code **)(**(int **)(this + 0x34) + 0x40))(*(int **)(this + 0x34));
          if (leftBasicTypeQuery != 2) {
            return 0;
          }
          rightBasicTypeQuery = (**(code **)(**(int **)(this + 0x38) + 0x40))(*(int **)(this + 0x38));
          operandTypesMatch = rightBasicTypeQuery == 2;
          goto LAB_97b90940;
        }
        if (operatorCode < 0x1f) goto LAB_97b90770;
      }
    }
    else {
      if (operatorCode == 0x2c) {
LAB_97b907c4:
        leftBasicTypeQuery = (**(code **)(**(int **)(this + 0x34) + 0x40))(*(int **)(this + 0x34),infoSinkCopy);
        if (leftBasicTypeQuery != 3) {
          return 0;
        }
        rightBasicTypeQuery = (**(code **)(**(int **)(this + 0x38) + 0x40))(*(int **)(this + 0x38));
        if (rightBasicTypeQuery != 3) {
          return 0;
        }
        thisVtable = *(int *)this;
        stackTypeBits = stackTypeBits & 0x9ff;
LAB_97b90850:
        stackTypeBits = stackTypeBits | 0x180800;
        stackTypeWord20 = 0;
        stackTypeWord1c = 0;
        stackTypeStructureSize = 0;
        stackTypeWord14 = 0;
        stackTypeTypeName = 0;
        stackTypeFieldName = 0;
        stackTypeStructure = 0;
        stackTypeArraySize = 0;
        stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
        (**(code **)(thisVtable + 0x34))(this,&stackType,scratchR5,scratchR6,scratchR7,scratchR8,thisVtable);
        return 1;
      }
      if (operatorCode < 0x2d) {
        if (operatorCode == 0x2a) goto LAB_97b907c4;
      }
      else if (operatorCode - 0x7fU < 6) {
        leftBasicTypeQuery = (**(code **)(**(int **)(this + 0x34) + 0x40))(*(int **)(this + 0x34));
        if (leftBasicTypeQuery != 2) {
          return 0;
        }
        rightBasicTypeQuery = (**(code **)(**(int **)(this + 0x38) + 0x40))(*(int **)(this + 0x38));
        if (rightBasicTypeQuery != 2) {
          return 0;
        }
      }
    }
    leftBasicTypeQuery = (**(code **)(**(int **)(this + 0x34) + 0x40))(*(int **)(this + 0x34));
    rightBasicType = (**(code **)(**(int **)(this + 0x38) + 0x40))(*(int **)(this + 0x38));
    if (leftBasicTypeQuery != rightBasicType) {
      return 0;
    }
    leftIsMatrixQuery = (**(code **)(**(int **)(this + 0x34) + 0x50))(*(int **)(this + 0x34));
    rightMatrixFlag = (**(code **)(**(int **)(this + 0x38) + 0x50))(*(int **)(this + 0x38));
    operandTypesMatch = leftIsMatrixQuery == rightMatrixFlag;
LAB_97b90940:
    if (!operandTypesMatch) {
      return 0;
    }
    return 1;
  }
  leftNominalSize = (**(code **)(**(int **)(this + 0x34) + 0x48))(*(int **)(this + 0x34));
  if ((leftNominalSize != resultNominalSize) &&
     (leftIsArrayQuery = (**(code **)(**(int **)(this + 0x34) + 0x48))(*(int **)(this + 0x34)), leftIsArrayQuery != 1)) {
    return 0;
  }
  leftNominalSize = (**(code **)(**(int **)(this + 0x38) + 0x48))(*(int **)(this + 0x38));
  scratchR4 = r4Out0;
  if ((leftNominalSize != resultNominalSize) &&
     (leftIsArrayQuery = (**(code **)(**(int **)(this + 0x38) + 0x48))(*(int **)(this + 0x38)),
     scratchR4 = r4Out1, leftIsArrayQuery != 1)) {
    return 0;
  }
  leftNominalSize = *(int *)(this + 0x30) - 0x13;
  if (0x6c < leftNominalSize) {
    return 0;
  }
  sizeInBytes = leftNominalSize * 4;
  switch(*(int *)(this + 0x30)) {
  case 0x13:
  case 0x14:
  case 0x16:
  case 0x17:
  case 0x77:
  case 0x78:
  case 0x7e:
  case 0x7f:
    goto switchD_97b909e0_caseD_13;
  case 0x15:
    leftMatrixFlag = (**(code **)(**(int **)(this + 0x34) + 0x50))
                       (*(int **)(this + 0x34),scratchR4,scratchR5,scratchR6,scratchR7,scratchR8,sizeInBytes);
    scratchR4 = r4Out2;
    if ((leftMatrixFlag == 0) &&
       (leftMatrixFlag = (**(code **)(**(int **)(this + 0x38) + 0x50))(*(int **)(this + 0x38)),
       scratchR4 = r4Out3, leftMatrixFlag != 0)) {
      leftIsVectorQuery = (**(code **)(**(int **)(this + 0x34) + 0x58))(*(int **)(this + 0x34));
      if (leftIsVectorQuery != 0) {
        newOperator = 0x27;
        goto LAB_97b9100c;
      }
      stackTypeBits = (resultNominalSize & 0xff) << 0xb | (leftBasicType & 0x3f) << 0x13 | stackTypeBits & 0x5ff | 0x400;
      thisVtable = *(int *)this;
      *(undefined4 *)(this + 0x30) = 0x29;
    }
    else {
      leftMatrixFlag = (**(code **)(**(int **)(this + 0x34) + 0x50))
                         (*(int **)(this + 0x34),scratchR4,scratchR5,scratchR6,scratchR7,scratchR8,sizeInBytes);
      scratchR4 = r4Out4;
      if ((leftMatrixFlag == 0) ||
         (leftMatrixFlag = (**(code **)(**(int **)(this + 0x38) + 0x50))(*(int **)(this + 0x38)),
         scratchR4 = r4Out5, leftMatrixFlag != 0)) {
        leftMatrixFlag = (**(code **)(**(int **)(this + 0x34) + 0x50))
                           (*(int **)(this + 0x34),scratchR4,scratchR5,scratchR6,scratchR7,scratchR8,sizeInBytes);
        if (leftMatrixFlag != 0) {
          rightMatrixFlag = (**(code **)(**(int **)(this + 0x38) + 0x50))(*(int **)(this + 0x38));
          newOperator = 0x56;
          if (rightMatrixFlag != 0) goto LAB_97b9100c;
        }
        leftMatrixFlag = (**(code **)(**(int **)(this + 0x34) + 0x50))(*(int **)(this + 0x34));
        scratchR4 = r4Out6;
        if ((leftMatrixFlag != 0) ||
           (leftMatrixFlag = (**(code **)(**(int **)(this + 0x38) + 0x50))(*(int **)(this + 0x38)),
           scratchR4 = r4Out7, leftMatrixFlag != 0)) {
          resultNominalSize = (*(code *)**(undefined4 **)this)(this,scratchR4,scratchR5,scratchR6,scratchR7,scratchR8,sizeInBytes)
          ;
                    
          __ZN13TInfoSinkBase6appendEPKc(infoSink,"INTERNAL ERROR: ");
          leftBasicType = resultNominalSize & 0xffff;
          cr0Flags = (leftBasicType == 0) << 1;
          if (leftBasicType == 0) {
            _sprintf(typeTempOverlay,"%d:? ",(int)resultNominalSize >> 0x10);
          }
          else {
            _sprintf(typeTempOverlay,"%d:%d",(int)resultNominalSize >> 0x10,leftBasicType);
          }
          __ZNSsC1EPKcRKSaIcE(&stackType,typeTempOverlay,(unsigned char *)&stackTypeTypeName);
          *(undefined *)((int)stackType + (int)stackType[-3]) = *PTR__S_terminal_a7b7c0b8;
          __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)stackType);
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
          __ZN13TInfoSinkBase6appendEPKc(infoSink,": ");
code_r0x97b91274:
          __ZN13TInfoSinkBase6appendEPKc(infoSink,"Missing elses");
          __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
          return 0;
        }
        leftIsVectorQuery = (**(code **)(**(int **)(this + 0x34) + 0x58))(*(int **)(this + 0x34));
        if (((leftIsVectorQuery != 0) &&
            (leftIsVectorQuery = (**(code **)(**(int **)(this + 0x38) + 0x58))(*(int **)(this + 0x38)),
            leftIsVectorQuery != 0)) ||
           ((leftIsVectorQuery = (**(code **)(**(int **)(this + 0x34) + 0x58))(*(int **)(this + 0x34)),
            leftIsVectorQuery == 0 &&
            (leftIsVectorQuery = (**(code **)(**(int **)(this + 0x38) + 0x58))(*(int **)(this + 0x38)),
            leftIsVectorQuery == 0)))) goto LAB_97b91520;
        thisVtable = *(int *)this;
        leftBasicType = (leftBasicType & 0x3f) << 0x13 | stackTypeBits & 0x7ffff;
        newOperator = 0x26;
      }
      else {
        rightIsVectorQuery = (**(code **)(**(int **)(this + 0x38) + 0x58))(*(int **)(this + 0x38));
        newOperator = 0x29;
        if (rightIsVectorQuery == 0) goto LAB_97b9100c;
        thisVtable = *(int *)this;
        leftBasicType = (leftBasicType & 0x3f) << 0x13 | stackTypeBits & 0x7ffff;
        newOperator = 0x28;
      }
LAB_97b910f8:
      stackTypeBits = (resultNominalSize & 0xff) << 0xb | leftBasicType & 0xfff801ff;
      *(undefined4 *)(this + 0x30) = newOperator;
    }
    goto LAB_97b914fc;
  default:
    goto switchD_97b909e0_caseD_18;
  case 0x1d:
  case 0x1e:
  case 0x21:
  case 0x22:
  case 0x23:
  case 0x24:
    leftIsMatrixQuery = (**(code **)(**(int **)(this + 0x34) + 0x50))
                      (*(int **)(this + 0x34),scratchR4,scratchR5,scratchR6,scratchR7,scratchR8,sizeInBytes);
    if ((leftIsMatrixQuery != 0) &&
       (leftIsMatrixQuery = (**(code **)(**(int **)(this + 0x38) + 0x58))(*(int **)(this + 0x38)), leftIsMatrixQuery != 0))
    {
      return 0;
    }
    leftIsVectorQuery = (**(code **)(**(int **)(this + 0x34) + 0x58))(*(int **)(this + 0x34));
    if ((leftIsVectorQuery != 0) &&
       (leftIsVectorQuery = (**(code **)(**(int **)(this + 0x38) + 0x50))(*(int **)(this + 0x38)), leftIsVectorQuery != 0))
    {
      return 0;
    }
    leftBasicTypeQuery = (**(code **)(**(int **)(this + 0x34) + 0x40))(*(int **)(this + 0x34));
    rightBasicType = (**(code **)(**(int **)(this + 0x38) + 0x40))(*(int **)(this + 0x38));
    if (leftBasicTypeQuery != rightBasicType) {
      return 0;
    }
    thisVtable = *(int *)this;
    stackTypeBits = stackTypeBits & 0x1801ff | 0x180800;
LAB_97b914fc:
    setTypeFn = *(code **)(thisVtable + 0x34);
    goto LAB_97b91508;
  case 0x76:
    break;
  case 0x79:
    leftMatrixFlag = (**(code **)(**(int **)(this + 0x34) + 0x50))(*(int **)(this + 0x34),scratchR4);
    if ((leftMatrixFlag == 0) &&
       (leftMatrixFlag = (**(code **)(**(int **)(this + 0x38) + 0x50))(*(int **)(this + 0x38)), leftMatrixFlag != 0)
       ) {
      leftIsVectorQuery = (**(code **)(**(int **)(this + 0x34) + 0x58))(*(int **)(this + 0x34));
      if (leftIsVectorQuery == 0) {
        return 0;
      }
      newOperator = 0x7a;
    }
    else {
      leftMatrixFlag = (**(code **)(**(int **)(this + 0x34) + 0x50))(*(int **)(this + 0x34));
      if ((leftMatrixFlag == 0) ||
         (leftMatrixFlag = (**(code **)(**(int **)(this + 0x38) + 0x50))(*(int **)(this + 0x38)),
         leftMatrixFlag != 0)) {
        leftMatrixFlag = (**(code **)(**(int **)(this + 0x34) + 0x50))(*(int **)(this + 0x34));
        if ((leftMatrixFlag == 0) ||
           (leftMatrixFlag = (**(code **)(**(int **)(this + 0x38) + 0x50))(*(int **)(this + 0x38)),
           leftMatrixFlag == 0)) {
          leftMatrixFlag = (**(code **)(**(int **)(this + 0x34) + 0x50))(*(int **)(this + 0x34));
          scratchR4 = r4Out8;
          if ((leftMatrixFlag != 0) ||
             (leftMatrixFlag = (**(code **)(**(int **)(this + 0x38) + 0x50))(*(int **)(this + 0x38)),
             scratchR4 = r4Out9, leftMatrixFlag != 0)) {
            resultNominalSize = (*(code *)**(undefined4 **)this)
                              (this,scratchR4,scratchR5,scratchR6,scratchR7,scratchR8,sizeInBytes);
                    
            __ZN13TInfoSinkBase6appendEPKc(infoSink,"INTERNAL ERROR: ");
            leftBasicType = resultNominalSize & 0xffff;
            cr0Flags = (leftBasicType == 0) << 1;
            if (leftBasicType == 0) {
              _sprintf((char *)&stackTypeTypeName,"%d:? ",(int)resultNominalSize >> 0x10);
            }
            else {
              _sprintf((char *)&stackTypeTypeName,"%d:%d",(int)resultNominalSize >> 0x10,leftBasicType);
            }
            __ZNSsC1EPKcRKSaIcE(&stackType,(char *)&stackTypeTypeName,allocatorDummy);
            *(undefined *)((int)stackType + (int)stackType[-3]) = *PTR__S_terminal_a7b7c0b8;
            __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)stackType);
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
              __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(stackType + -3),&stackTypeTypeName);
            }
            __ZN13TInfoSinkBase6appendEPKc(infoSink,": ");
            goto code_r0x97b91274;
          }
          leftIsVectorQuery = (**(code **)(**(int **)(this + 0x34) + 0x58))(*(int **)(this + 0x34));
          if (((leftIsVectorQuery != 0) &&
              (leftIsVectorQuery = (**(code **)(**(int **)(this + 0x38) + 0x58))(*(int **)(this + 0x38)),
              leftIsVectorQuery != 0)) ||
             ((leftIsVectorQuery = (**(code **)(**(int **)(this + 0x34) + 0x58))(*(int **)(this + 0x34)),
              leftIsVectorQuery == 0 &&
              (leftIsVectorQuery = (**(code **)(**(int **)(this + 0x38) + 0x58))(*(int **)(this + 0x38)),
              leftIsVectorQuery == 0)))) goto LAB_97b91520;
          leftIsVectorQuery = (**(code **)(**(int **)(this + 0x34) + 0x58))(*(int **)(this + 0x34));
          if (leftIsVectorQuery == 0) {
            return 0;
          }
          thisVtable = *(int *)this;
          newOperator = 0x7b;
          leftBasicType = (leftBasicType & 0x3f) << 0x13 | stackTypeBits & 0x7ffff;
          goto LAB_97b910f8;
        }
        newOperator = 0x7d;
      }
      else {
        rightIsVectorQuery = (**(code **)(**(int **)(this + 0x38) + 0x58))(*(int **)(this + 0x38));
        if (rightIsVectorQuery != 0) {
          return 0;
        }
        newOperator = 0x7c;
      }
    }
LAB_97b9100c:
    *(undefined4 *)(this + 0x30) = newOperator;
    goto LAB_97b91520;
  }
  leftNominalSizeQuery = (**(code **)(**(int **)(this + 0x34) + 0x48))(*(int **)(this + 0x34),scratchR4);
  rightNominalSize = (**(code **)(**(int **)(this + 0x38) + 0x48))(*(int **)(this + 0x38));
  if (leftNominalSizeQuery != rightNominalSize) {
    return 0;
  }
switchD_97b909e0_caseD_13:
  leftIsMatrixQuery = (**(code **)(**(int **)(this + 0x34) + 0x50))(*(int **)(this + 0x34));
  if (((leftIsMatrixQuery == 0) ||
      (leftIsMatrixQuery = (**(code **)(**(int **)(this + 0x38) + 0x58))(*(int **)(this + 0x38)), leftIsMatrixQuery == 0))
     && ((leftIsMatrixQuery = (**(code **)(**(int **)(this + 0x34) + 0x58))(*(int **)(this + 0x34)), leftIsMatrixQuery == 0
         || (leftIsMatrixQuery = (**(code **)(**(int **)(this + 0x38) + 0x50))(*(int **)(this + 0x38)),
            leftIsMatrixQuery == 0)))) {
    leftBasicTypeQuery = (**(code **)(**(int **)(this + 0x34) + 0x40))(*(int **)(this + 0x34));
    rightBasicType = (**(code **)(**(int **)(this + 0x38) + 0x40))(*(int **)(this + 0x38));
    if (leftBasicTypeQuery == rightBasicType) {
      resultIsMatrix = 0;
      leftIsMatrixQuery = (**(code **)(**(int **)(this + 0x34) + 0x50))(*(int **)(this + 0x34));
      if ((leftIsMatrixQuery != 0) ||
         (leftIsMatrixQuery = (**(code **)(**(int **)(this + 0x38) + 0x50))(*(int **)(this + 0x38)), leftIsMatrixQuery != 0)
         ) {
        resultIsMatrix = 1;
      }
      thisVtable = *(int *)this;
      stackTypeBits = resultIsMatrix << 10 | (resultNominalSize & 0xff) << 0xb | (leftBasicType & 0x3f) << 0x13 | stackTypeBits & 0x1ff;
      setTypeFn = *(code **)(thisVtable + 0x34);
LAB_97b91508:
      stackTypeWord20 = 0;
      stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
      stackTypeArraySize = stackTypeWord20;
      stackTypeStructure = stackTypeWord20;
      stackTypeFieldName = stackTypeWord20;
      stackTypeTypeName = stackTypeWord20;
      stackTypeWord14 = stackTypeWord20;
      stackTypeStructureSize = stackTypeWord20;
      stackTypeWord1c = stackTypeWord20;
      (*setTypeFn)(this,&stackType,scratchR5,scratchR6,scratchR7,scratchR8,thisVtable);
      stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
LAB_97b91520:
      operatorCode = *(int *)(this + 0x30);
      if ((0x75 < operatorCode) && ((operatorCode < 0x7a || (operatorCode - 0x7eU < 7)))) {
        (**(code **)(*(int *)this + 0x38))(&stackType,this);
        (**(code **)(**(int **)(this + 0x34) + 0x38))(typeTempOverlay,*(int **)(this + 0x34));
        operandTypesMatch = false;
        if (((stackTypeBits & 0x1fffe00) == (typeTempBits & 0x1fffe00)) && (stackTypeStructure == typeTempStructure)) {
          operandTypesMatch = true;
        }
        if (!operandTypesMatch) {
          return 0;
        }
      }
      return 1;
    }
  }
switchD_97b909e0_caseD_18:
  return 0;
}

/* compareStructure @ 0x97b915d4 (336 bytes) */
int compareStructure(type, constUnion1, constUnion2, constIndexPtr)
  unsigned char * type;
  unsigned char * constUnion1;
  unsigned char * constUnion2;
  int *constIndexPtr;
{
  int constIndex;
  int fieldBasicType;
  int fieldSize;
  int fieldTypeVtable;
  int fieldOffset;
  int fieldsBegin;
  int *fieldType;
  undefined4 r4Out0;
  undefined4 r4Out1;
  undefined4 scratchR4;
  unsigned char * constUnion2Copy;
  int *constIndexPtrCopy;
  undefined4 scratchR7;
  undefined4 scratchR8;
  uint fieldCount;
  uint fieldIndex;
  int typeList;
  int memberIndex;
  undefined8 nestedResult;
  
  fieldIndex = 0;
  typeList = *(int *)(type + 8);
  fieldsBegin = *(int *)(typeList + 4);
  fieldCount = *(int *)(typeList + 8) - fieldsBegin >> 3;
  constUnion2Copy = constUnion2;
  constIndexPtrCopy = constIndexPtr;
  if (fieldCount == 0) {
    return 1;
  }
  do {
    fieldOffset = fieldIndex * 8;
    memberIndex = 0;
    fieldSize = (**(code **)(**(int **)(fieldsBegin + fieldOffset) + 0x30))(*(int **)(fieldsBegin + fieldOffset));
    scratchR4 = r4Out0;
    if (0 < fieldSize) {
      do {
        fieldType = *(int **)(*(int *)(typeList + 4) + fieldOffset);
        fieldTypeVtable = *fieldType;
        fieldBasicType = (**(code **)(fieldTypeVtable + 0x20))(fieldType,scratchR4,constUnion2Copy,constIndexPtrCopy,scratchR7,scratchR8,fieldTypeVtable);
        scratchR4 = r4Out1;
        if (fieldBasicType == 2) {
LAB_97b916a8:
          constIndex = *constIndexPtr;
          if (*(int *)(constUnion2 + constIndex * 4) != *(int *)(constUnion1 + constIndex * 4)) {
            return 0;
          }
LAB_97b916c8:
          *constIndexPtr = constIndex + 1;
        }
        else if (fieldBasicType < 3) {
          if (fieldBasicType == 1) {
            constIndex = *constIndexPtr;
            if (*(float *)(constUnion2 + constIndex * 4) != *(float *)(constUnion1 + constIndex * 4)) {
              return 0;
            }
            goto LAB_97b916c8;
          }
        }
        else {
          if (fieldBasicType == 3) goto LAB_97b916a8;
          if (fieldBasicType == 0xe) {
            constUnion2Copy = constUnion2;
            constIndexPtrCopy = constIndexPtr;
            nestedResult = ((int (*)())compareStructure)(*(unsigned char **)(*(int *)(typeList + 4) + fieldOffset),constUnion1,constUnion2,
                                     constIndexPtr);
            scratchR4 = (undefined4)nestedResult;
            if ((int)((ulonglong)nestedResult >> 0x20) == 0) {
              return 0;
            }
          }
        }
        memberIndex = memberIndex + 1;
      } while (memberIndex < fieldSize);
    }
    fieldIndex = fieldIndex + 1;
    if (fieldCount <= fieldIndex) {
      return 1;
    }
    fieldsBegin = *(int *)(typeList + 4);
  } while( true );
}

/* TIntermConstantUnion__fold @ 0x97b91724 (792 bytes) */
int TIntermConstantUnion__fold(this, op, rightOperand, infoSink, swapOperands, unusedArg6, unusedArg7)
  unsigned char * this;
  int op;
  unsigned char * rightOperand;
  void *infoSink;
  int swapOperands;
  undefined4 unusedArg6;
  uint unusedArg7;
{
  float integerResult;
  float foldedValue;
  float quotientValue;
  float operandValue;
  int divisionResult;
  int thisIsVector;
  int thisElementCount;
  int loopIndex;
  int rightUnionPtr;
  int thisNominalSize;
  int structuresEqual;
  int operandTypeQuery;
  int foldNodeVtable;
  int smallCode;
  uint bitwiseResult;
  uint retypedBits;
  uint basicTypeInPlaceBits;
  uint scalarBits;
  uint componentXor;
  uint sourceLoc;
  uint operatorOffset;
  uint nominalSizeInPlace;
  int loopBound;
  int cursorOffset;
  int strideOffset;
  int componentCounter;
  int newComponentArray;
  int byteOffset;
  int scanIndex;
  int allocatedArray;
  int sizeQuery;
  int rightUnionNode;
  undefined *typeVtable;
  undefined *oldRefCount;
  uint thisFirstComponent;
  uint rightFirstValue;
  uint foldNodeBits;
  uint sourceLine;
  bool lessEqualResult;
  bool equalityResult;
  bool refCountPositive;
  uint rightFirstComponent;
  uint newNodeBits;
  unsigned char *rightOperandArg;
  undefined4 *thisVtablePtr;
  float *rightFloats;
  unsigned char *thisComponentCursor;
  bool sizeFlag;
  undefined *newRefCount;
  uint typeBit10;
  undefined **refCountPtrCopy;
  float leftValue;
  float unaryResult;
  uint nodeBitsBefore;
  undefined *constUnionVtable;
  unsigned char *rightUnionArray;
  uint qualifierBits;
  undefined4 *newConstUnionNode;
  int componentIndex;
  int elementCount;
  int minValue;
  int *rightConstUnion;
  uint *resultBool;
  unsigned char * poolAllocator;
  int thisSizeValue;
  unsigned char *foldResultNode;
  undefined4 r4Value;
  unsigned char * stringRep;
  uint typeBasicTypeField;
  undefined4 r4In0;
  undefined4 r4In1;
  undefined4 r4In2;
  undefined4 r4In3;
  undefined4 r4In4;
  undefined4 r4In5;
  undefined4 r4Out0;
  undefined4 r4Out1;
  undefined4 r4In6;
  undefined4 r4In7;
  undefined4 r4In8;
  undefined4 r4Out2;
  undefined4 r4Out3;
  undefined4 r4In9;
  undefined4 r4In10;
  undefined4 r4In11;
  undefined4 r4In12;
  undefined4 r4Out4;
  undefined4 r4Out5;
  undefined4 r4Out6;
  undefined4 r4Out7;
  undefined4 r4Out8;
  undefined4 r4Out9;
  undefined4 r4Out10;
  undefined4 r4Out11;
  unsigned char * locText;
  undefined4 r4Out12;
  void *infoSinkArg;
  int columnOffset;
  float *resultCursor;
  uint basicTypeInPlace;
  float *resultFloats;
  unsigned char * thisUnion;
  int componentLoopIndex;
  undefined **refCountPtr;
  char *message;
  bool canFold;
  char reservation;
  byte reservationOk;
  int columnsLeft;
  undefined8 allocPair;
  undefined **unaryTypeVtbl;
  undefined4 unaryTypeWord1;
  undefined4 unaryTypeWord2;
  undefined4 unaryTypeWord3;
  undefined4 unaryTypeWord4Overlay;
  undefined4 unaryTypeWord5;
  undefined4 unaryTypeWord6;
  undefined4 unaryTypeWord7;
  undefined4 unaryTypeWord8;
  uint unaryTypeBits;
  undefined **binaryTypeVtbl;
  int binaryTypeWord1;
  int binaryTypeWord2;
  int binaryTypeWord3;
  int binaryTypeWord4Overlay;
  int binaryTypeWord5;
  int binaryTypeWord6;
  int binaryTypeWord7;
  int binaryTypeWord8;
  uint binaryTypeBits;
  undefined **compareTypeVtbl;
  int compareTypeWord1;
  int compareTypeWord2;
  int compareTypeWord3;
  int compareTypeWord4Overlay;
  int compareTypeWord5;
  int compareTypeWord6;
  int compareTypeWord7;
  int compareTypeWord8;
  uint compareTypeBits;
  undefined **rightTypeOverlay [4];
  unsigned char locTextBuf [16];
  unsigned char stringAllocator [4];
  uint rightTypeBits;
  undefined **tailTypeVtbl;
  undefined4 tailTypeWord1;
  undefined4 tailTypeWord2;
  undefined4 tailTypeWord3;
  undefined4 tailTypeWord4Overlay;
  undefined4 tailTypeWord5;
  undefined4 tailTypeWord6;
  undefined4 tailTypeWord7;
  undefined4 tailTypeWord8;
  uint tailTypeBits;
  unsigned char stringAllocator2 [16];
  char locTextBuf2 [16];
  unsigned char stringAllocator3 [48];
  char locTextBuf3 [64];
  int compareStructureOut;
  uint picBase;
  
  thisUnion = *(unsigned char **)(this + 0x30);
  if (rightOperand == (unsigned char *)0x0) {
    componentIndex = 0;
    thisSizeValue = (**(code **)(*(int *)this + 0x4c))(this,op);
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    resultFloats = (float *)TPoolAllocator__allocate(poolAllocator,thisSizeValue << 2);
    thisSizeValue = (**(code **)(*(int *)this + 0x4c))(this);
    if (1 < thisSizeValue) {
      for (; thisSizeValue = (**(code **)(*(int *)this + 0x4c))(this), componentIndex < thisSizeValue; componentIndex = componentIndex + 1
          ) {
        if (op == 5) {
          (**(code **)(*(int *)this + 0x38))(&unaryTypeVtbl,this);
          typeBasicTypeField = unaryTypeBits >> 0x13 & 0x3f;
          unaryTypeVtbl = &PTR___ZN5TTypeD1Ev_a7b7cff8;
          if (typeBasicTypeField != 1) {
            if (typeBasicTypeField == 2) {
              unaryResult = GH_U2F((unsigned int)(-*(int *)(thisUnion + componentIndex * 4)));
              goto LAB_97b956a0;
            }
            sourceLoc = (*(code *)**(undefined4 **)this)(this);
                    
            goto override_jmp_97b95640_case_0;
          }
          resultFloats[componentIndex] = -*(float *)(thisUnion + componentIndex * 4);
        }
        else {
          if (op != 6) {
            return (unsigned char *)0x0;
          }
          (**(code **)(*(int *)this + 0x38))(&unaryTypeVtbl,this);
          unaryTypeVtbl = &PTR___ZN5TTypeD1Ev_a7b7cff8;
          if ((unaryTypeBits >> 0x13 & 0x3f) != 3) {
            sourceLoc = (*(code *)**(undefined4 **)this)(this);
                    
            goto override_jmp_97b95640_case_0;
          }
          unaryResult = GH_U2F((unsigned int)((*(uint *)(thisUnion + componentIndex * 4) ^ 1)));
LAB_97b956a0:
          resultFloats[componentIndex] = unaryResult;
        }
        unaryTypeVtbl = &PTR___ZN5TTypeD1Ev_a7b7cff8;
      }
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      newConstUnionNode = (undefined4 *)TPoolAllocator__allocate(poolAllocator,0x34);
      (**(code **)(*(int *)this + 0x38))(&unaryTypeVtbl,this);
      allocPair = CONCAT44(newConstUnionNode,r4Out12);
      newConstUnionNode[1] = 0;
      *newConstUnionNode = &PTR_getLine_a7b7cf90;
      newConstUnionNode[3] = unaryTypeWord1;
      newConstUnionNode[4] = unaryTypeWord2;
      newConstUnionNode[5] = unaryTypeWord3;
      newConstUnionNode[6] = unaryTypeWord4Overlay;
      newConstUnionNode[7] = unaryTypeWord5;
      newConstUnionNode[8] = unaryTypeWord6;
      newConstUnionNode[2] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
      newConstUnionNode[9] = unaryTypeWord7;
      newConstUnionNode[10] = unaryTypeWord8;
      nodeBitsBefore = newConstUnionNode[0xb];
      qualifierBits = unaryTypeBits & 0xfe000000;
      newConstUnionNode[0xb] = qualifierBits | nodeBitsBefore & 0x1ffffff;
      basicTypeInPlace = (unaryTypeBits >> 0x13 & 0x3f) << 0x13;
      newConstUnionNode[0xb] = basicTypeInPlace | qualifierBits | nodeBitsBefore & 0x7ffff;
      nominalSizeInPlace = unaryTypeBits & 0x7f800;
      newConstUnionNode[0xb] = nominalSizeInPlace | basicTypeInPlace | qualifierBits | nodeBitsBefore & 0x7ff;
      typeBit10 = (unaryTypeBits >> 10 & 1) << 10;
      newConstUnionNode[0xb] = typeBit10 | nominalSizeInPlace | basicTypeInPlace | qualifierBits | nodeBitsBefore & 0x3ff;
      constUnionVtable = PTR_vtable_a7b7c0c8;
      newConstUnionNode[0xb] = (unaryTypeBits >> 9 & 1) << 9 | typeBit10 | nominalSizeInPlace | basicTypeInPlace | qualifierBits | nodeBitsBefore & 0x1ff;
      newConstUnionNode[0xc] = resultFloats;
      *newConstUnionNode = constUnionVtable + 8;
      goto LAB_97b95bbc;
    }
    if (op == 5) {
      (**(code **)(*(int *)this + 0x38))(&unaryTypeVtbl,this);
      typeBasicTypeField = unaryTypeBits >> 0x13 & 0x3f;
      unaryTypeVtbl = &PTR___ZN5TTypeD1Ev_a7b7cff8;
      if (typeBasicTypeField == 1) {
        *resultFloats = -**(float **)(this + 0x30);
        poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
        allocPair = TPoolAllocator__allocate(poolAllocator,0x34);
        retypedBits = unaryTypeBits & 0x7ff | 0x4080000;
        goto LAB_97b9597c;
      }
      if (typeBasicTypeField == 2) {
        *resultFloats = GH_U2F((unsigned int)(-**(int **)(this + 0x30)));
        poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
        allocPair = TPoolAllocator__allocate(poolAllocator,0x34);
        smallCode = 2;
        goto LAB_97b9596c;
      }
      sourceLoc = *(uint *)(this + 4);
                    
    }
    else {
      if (op != 6) {
        return (unsigned char *)0x0;
      }
      (**(code **)(*(int *)this + 0x38))(&unaryTypeVtbl,this);
      unaryTypeVtbl = &PTR___ZN5TTypeD1Ev_a7b7cff8;
      if ((unaryTypeBits >> 0x13 & 0x3f) == 3) {
        *resultFloats = GH_U2F((unsigned int)((**(uint **)(this + 0x30) ^ 1)));
        poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
        allocPair = TPoolAllocator__allocate(poolAllocator,0x34);
        smallCode = 3;
LAB_97b9596c:
        retypedBits = smallCode << 0x13 | unaryTypeBits & 0xfff | 0x4000000;
LAB_97b9597c:
        newConstUnionNode = (undefined4 *)((ulonglong)allocPair >> 0x20);
        unaryTypeBits = retypedBits & 0xfffff9ff | 0x800;
        unaryTypeWord1 = 0;
        unaryTypeWord2 = 0;
        unaryTypeWord3 = 0;
        unaryTypeWord4Overlay = 0;
        unaryTypeWord5 = 0;
        unaryTypeWord6 = 0;
        unaryTypeWord7 = 0;
        unaryTypeWord8 = 0;
        newConstUnionNode[1] = 0;
        *newConstUnionNode = &PTR_getLine_a7b7cf90;
        newConstUnionNode[3] = 0;
        newConstUnionNode[4] = 0;
        newConstUnionNode[5] = 0;
        newConstUnionNode[6] = 0;
        newConstUnionNode[7] = 0;
        newConstUnionNode[8] = 0;
        newConstUnionNode[2] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
        newConstUnionNode[9] = 0;
        newConstUnionNode[10] = 0;
        newNodeBits = newConstUnionNode[0xb];
        qualifierBits = retypedBits & 0xfe000000;
        newConstUnionNode[0xb] = qualifierBits | newNodeBits & 0x1ffffff;
        retypedBits = (retypedBits >> 0x13 & 0x3f) << 0x13;
        newConstUnionNode[0xb] = retypedBits | qualifierBits | newNodeBits & 0x7ffff;
        newConstUnionNode[0xb] = retypedBits | qualifierBits | newNodeBits & 0x7ff | 0x800;
        newConstUnionNode[0xb] = retypedBits | qualifierBits | newNodeBits & 0x3ff | 0x800;
        constUnionVtable = PTR_vtable_a7b7c0c8;
        newConstUnionNode[0xb] = retypedBits | qualifierBits | newNodeBits & 0x1ff | 0x800;
        newConstUnionNode[0xc] = resultFloats;
        *newConstUnionNode = constUnionVtable + 8;
LAB_97b95bbc:
        foldResultNode = (unsigned char *)((ulonglong)allocPair >> 0x20);
        unaryTypeVtbl = &PTR___ZN5TTypeD1Ev_a7b7cff8;
        foldNodeVtable = *(int *)foldResultNode;
        r4Value = (*(code *)**(undefined4 **)this)(this,(int)allocPair);
        (**(code **)(foldNodeVtable + 4))(foldResultNode,r4Value);
        return foldResultNode;
      }
      sourceLoc = *(uint *)(this + 4);
                    
    }
override_jmp_97b95640_case_0:
    message = "Unary operation not folded into constant";
    __ZN13TInfoSinkBase6appendEPKc(infoSink,"INTERNAL ERROR: ");
    sourceLine = sourceLoc & 0xffff;
    reservationOk = (sourceLine == 0) << 1;
    if (sourceLine == 0) {
      _sprintf((char *)&unaryTypeWord4Overlay,"%d:? ",(int)sourceLoc >> 0x10);
    }
    else {
      _sprintf((char *)&unaryTypeWord4Overlay,"%d:%d",(int)sourceLoc >> 0x10,sourceLine);
    }
    locText = (unsigned char *)&unaryTypeWord4Overlay;
    __ZNSsC1EPKcRKSaIcE(&unaryTypeVtbl,(char *)locText,(unsigned char *)&binaryTypeWord8);
                    
    *(undefined *)((int)unaryTypeVtbl + (int)unaryTypeVtbl[-3]) = *PTR__S_terminal_a7b7c0b8;
    __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)unaryTypeVtbl);
    refCountPtr = unaryTypeVtbl;
code_r0x97b95b60:
    refCountPtrCopy = refCountPtr + -1;
    do {
      oldRefCount = *refCountPtrCopy;
                    
      if (reservation != '\0') {
        newRefCount = (undefined *)storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtrCopy);
        *refCountPtrCopy = newRefCount;
        reservationOk = 2;
      }
    } while (!(bool)(reservationOk >> 1 & 1));
joined_r0x97b95b7c:
    if ((int)oldRefCount < 1) {
      __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(refCountPtr + -3),locText);
    }
    __ZN13TInfoSinkBase6appendEPKc(infoSink,": ");
code_r0x97b95ba0:
    __ZN13TInfoSinkBase6appendEPKc(infoSink,message);
    __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
switchD_97b94d20_caseD_17:
    return (unsigned char *)0x0;
  }
  canFold = false;
  rightOperandArg = rightOperand;
  infoSinkArg = infoSink;
  operandTypeQuery = swapOperands;
  sizeQuery = (**(code **)(*(int *)rightOperand + 0x18))(rightOperand);
  if ((sizeQuery != 0) && (sizeQuery = (**(code **)(*(int *)rightOperand + 0x4c))(rightOperand), sizeQuery == 1)) {
    (**(code **)(*(int *)rightOperand + 0x38))(&unaryTypeVtbl,rightOperand);
    if (((unaryTypeBits >> 0x13 & 0x3f) != 0xe) &&
       (sizeQuery = (**(code **)(*(int *)this + 0x4c))(this), 1 < sizeQuery)) {
      canFold = true;
    }
    picBase = 0xa7b81734;
    unaryTypeVtbl = &PTR___ZN5TTypeD1Ev_a7b7cff8;
    if (!canFold) goto LAB_97b92a7c;
    rightUnionNode = (**(code **)(*(int *)rightOperand + 0x18))(rightOperand);
    operatorOffset = op - 0x13;
    if (operatorOffset < 0x1a) {
      thisElementCount = operatorOffset * 4;
      switch(operatorOffset) {
      case 0:
        picBase = 0xa7b81734;
        thisElementCount = (**(code **)(*(int *)this + 0x4c))(this,operatorOffset,rightOperandArg,infoSinkArg,operandTypeQuery,unusedArg6,thisElementCount);
        poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
        newComponentArray = TPoolAllocator__allocate(poolAllocator,thisElementCount << 2);
        for (componentLoopIndex = 0; loopBound = (**(code **)(*(int *)this + 0x4c))(this), componentLoopIndex < loopBound;
            componentLoopIndex = componentLoopIndex + 1) {
          (**(code **)(*(int *)this + 0x38))(&binaryTypeVtbl,this);
          typeBasicTypeField = binaryTypeBits >> 0x13 & 0x3f;
          binaryTypeVtbl = (undefined **)(picBase - 0x473c);
          if (typeBasicTypeField != 1) {
            if (typeBasicTypeField == 2) {
              *(int *)(componentLoopIndex * 4 + newComponentArray) =
                   *(int *)(thisUnion + componentLoopIndex * 4) + **(int **)(rightUnionNode + 0x30);
              goto LAB_97b919a8;
            }
            message = "Constant folding cannot be done for \"+\"";
            sourceLoc = (*(code *)**(undefined4 **)this)(this,r4In0,rightOperandArg,infoSinkArg,operandTypeQuery,unusedArg6,picBase);
                    
override_jmp_97b9198c_case_0:
            __ZN13TInfoSinkBase6appendEPKc(infoSink,"INTERNAL ERROR: ");
            sourceLine = sourceLoc & 0xffff;
            reservationOk = (sourceLine == 0) << 1;
            if (sourceLine == 0) {
              _sprintf((char *)&binaryTypeWord4Overlay,"%d:? ",(int)sourceLoc >> 0x10);
            }
            else {
              _sprintf((char *)&binaryTypeWord4Overlay,"%d:%d",(int)sourceLoc >> 0x10,sourceLine);
            }
            locText = (unsigned char *)&binaryTypeWord4Overlay;
            __ZNSsC1EPKcRKSaIcE(&binaryTypeVtbl,(char *)locText,(unsigned char *)&compareTypeWord8);
            *(undefined *)((int)binaryTypeVtbl + (int)binaryTypeVtbl[-3]) = *PTR__S_terminal_a7b7c0b8;
            __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)binaryTypeVtbl);
            refCountPtr = binaryTypeVtbl + -1;
            stringRep = (unsigned char *)(binaryTypeVtbl + -3);
            do {
              oldRefCount = *refCountPtr;
              if (reservation != '\0') {
                newRefCount = (undefined *)storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
                *refCountPtr = newRefCount;
                reservationOk = 2;
              }
            } while (!(bool)(reservationOk >> 1 & 1));
            refCountPositive = 0 < (int)oldRefCount;
            goto code_r0x97b93fb8;
          }
          *(float *)(newComponentArray + componentLoopIndex * 4) =
               *(float *)(thisUnion + componentLoopIndex * 4) + **(float **)(rightUnionNode + 0x30);
LAB_97b919a8: ;
        }
        break;
      case 1:
        picBase = 0xa7b81734;
        thisElementCount = (**(code **)(*(int *)this + 0x4c))(this);
        poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
        newComponentArray = TPoolAllocator__allocate(poolAllocator,thisElementCount << 2);
        for (componentLoopIndex = 0; loopBound = (**(code **)(*(int *)this + 0x4c))(this), componentLoopIndex < loopBound;
            componentLoopIndex = componentLoopIndex + 1) {
          (**(code **)(*(int *)this + 0x38))(&binaryTypeVtbl,this);
          typeBasicTypeField = binaryTypeBits >> 0x13 & 0x3f;
          binaryTypeVtbl = (undefined **)(picBase - 0x473c);
          if (typeBasicTypeField == 1) {
            if (swapOperands == 0) {
              operandValue = *(float *)(thisUnion + componentLoopIndex * 4);
              leftValue = **(float **)(rightUnionNode + 0x30);
            }
            else {
              leftValue = *(float *)(thisUnion + componentLoopIndex * 4);
              operandValue = **(float **)(rightUnionNode + 0x30);
            }
            *(float *)(newComponentArray + componentLoopIndex * 4) = leftValue - operandValue;
          }
          else {
            if (typeBasicTypeField != 2) {
              message = "Constant folding cannot be done for \"-\"";
              sourceLoc = (*(code *)**(undefined4 **)this)
                                 (this,r4In2,rightOperandArg,infoSinkArg,operandTypeQuery,unusedArg6,picBase);
                    
              goto override_jmp_97b9198c_case_0;
            }
            if (swapOperands == 0) {
              loopBound = **(int **)(rightUnionNode + 0x30) - *(int *)(thisUnion + componentLoopIndex * 4);
            }
            else {
              loopBound = *(int *)(thisUnion + componentLoopIndex * 4) - **(int **)(rightUnionNode + 0x30);
            }
            *(int *)(componentLoopIndex * 4 + newComponentArray) = loopBound;
          }
        }
        break;
      default:
        goto switchD_97b91834_caseD_15;
      case 3:
        picBase = 0xa7b81734;
        thisSizeValue = (**(code **)(*(int *)this + 0x4c))(this);
        poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
        newComponentArray = TPoolAllocator__allocate(poolAllocator,thisSizeValue << 2);
        for (loopIndex = 0; thisElementCount = (**(code **)(*(int *)this + 0x4c))(this), loopIndex < thisElementCount;
            loopIndex = loopIndex + 1) {
          (**(code **)(*(int *)this + 0x38))(&binaryTypeVtbl,this);
          typeBasicTypeField = binaryTypeBits >> 0x13 & 0x3f;
          binaryTypeVtbl = (undefined **)(picBase - 0x473c);
          if (typeBasicTypeField == 1) {
            if (swapOperands == 0) {
              if (*(float *)(thisUnion + loopIndex * 4) == 0.0) {
                sourceLoc = (*(code *)**(undefined4 **)this)(this);
                    
                __ZN13TInfoSinkBase6appendEPKc(infoSink,"WARNING: ");
                sourceLine = sourceLoc & 0xffff;
                reservationOk = (sourceLine == 0) << 1;
                if (sourceLine == 0) {
                  _sprintf((char *)&binaryTypeWord4Overlay,"%d:? ",(int)sourceLoc >> 0x10);
                }
                else {
                  _sprintf((char *)&binaryTypeWord4Overlay,"%d:%d",(int)sourceLoc >> 0x10,sourceLine);
                }
                __ZNSsC1EPKcRKSaIcE(&binaryTypeVtbl,(char *)&binaryTypeWord4Overlay,(unsigned char *)&compareTypeWord8);
                *(undefined *)((int)binaryTypeVtbl + (int)binaryTypeVtbl[-3]) = *PTR__S_terminal_a7b7c0b8;
                __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)binaryTypeVtbl);
                refCountPtr = binaryTypeVtbl + -1;
                do {
                  oldRefCount = *refCountPtr;
                  if (reservation != '\0') {
                    newRefCount = (undefined *)storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
                    *refCountPtr = newRefCount;
                    reservationOk = 2;
                  }
                } while (!(bool)(reservationOk >> 1 & 1));
                if ((int)oldRefCount < 1) {
                  __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(binaryTypeVtbl + -3),&binaryTypeWord4Overlay);
                }
                __ZN13TInfoSinkBase6appendEPKc(infoSink,": ");
                __ZN13TInfoSinkBase6appendEPKc
                          (infoSink,"Divide by zero error during constant folding");
                __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
                quotientValue = 3.4028235e+38;
              }
              else {
                quotientValue = **(float **)(rightUnionNode + 0x30) / *(float *)(thisUnion + loopIndex * 4);
              }
              *(float *)(loopIndex * 4 + newComponentArray) = quotientValue;
            }
            else {
              if (**(float **)(rightUnionNode + 0x30) == 0.0) {
                sourceLoc = (*(code *)**(undefined4 **)this)(this);
                    
                __ZN13TInfoSinkBase6appendEPKc(infoSink,"WARNING: ");
                sourceLine = sourceLoc & 0xffff;
                reservationOk = (sourceLine == 0) << 1;
                if (sourceLine == 0) {
                  _sprintf((char *)&binaryTypeWord4Overlay,"%d:? ",(int)sourceLoc >> 0x10);
                }
                else {
                  _sprintf((char *)&binaryTypeWord4Overlay,"%d:%d",(int)sourceLoc >> 0x10,sourceLine);
                }
                __ZNSsC1EPKcRKSaIcE(&binaryTypeVtbl,(char *)&binaryTypeWord4Overlay,(unsigned char *)&compareTypeWord8);
                *(undefined *)((int)binaryTypeVtbl + (int)binaryTypeVtbl[-3]) = *PTR__S_terminal_a7b7c0b8;
                __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)binaryTypeVtbl);
                refCountPtr = binaryTypeVtbl + -1;
                do {
                  oldRefCount = *refCountPtr;
                  if (reservation != '\0') {
                    newRefCount = (undefined *)storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
                    *refCountPtr = newRefCount;
                    reservationOk = 2;
                  }
                } while (!(bool)(reservationOk >> 1 & 1));
                if ((int)oldRefCount < 1) {
                  __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(binaryTypeVtbl + -3),&binaryTypeWord4Overlay);
                }
                __ZN13TInfoSinkBase6appendEPKc(infoSink,": ");
                __ZN13TInfoSinkBase6appendEPKc
                          (infoSink,"Divide by zero error during constant folding");
                __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
                thisElementCount = loopIndex << 2;
                quotientValue = 3.4028235e+38;
              }
              else {
                thisElementCount = loopIndex * 4;
                quotientValue = *(float *)(thisUnion + thisElementCount) / **(float **)(rightUnionNode + 0x30);
              }
              *(float *)(newComponentArray + thisElementCount) = quotientValue;
            }
          }
          else {
            if (typeBasicTypeField != 2) {
              message = "Constant folding cannot be done for \"/\"";
              sourceLoc = (*(code *)**(undefined4 **)this)(this);
                    
              goto override_jmp_97b9198c_case_0;
            }
            if (swapOperands == 0) {
              if (*(int *)(thisUnion + loopIndex * 4) == 0) {
                sourceLoc = (*(code *)**(undefined4 **)this)(this);
                    
                __ZN13TInfoSinkBase6appendEPKc(infoSink,"WARNING: ");
                sourceLine = sourceLoc & 0xffff;
                reservationOk = (sourceLine == 0) << 1;
                if (sourceLine == 0) {
                  _sprintf((char *)&binaryTypeWord4Overlay,"%d:? ",(int)sourceLoc >> 0x10);
                }
                else {
                  _sprintf((char *)&binaryTypeWord4Overlay,"%d:%d",(int)sourceLoc >> 0x10,sourceLine);
                }
                __ZNSsC1EPKcRKSaIcE(&binaryTypeVtbl,(char *)&binaryTypeWord4Overlay,(unsigned char *)&compareTypeWord8);
                *(undefined *)((int)binaryTypeVtbl + (int)binaryTypeVtbl[-3]) = *PTR__S_terminal_a7b7c0b8;
                __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)binaryTypeVtbl);
                refCountPtr = binaryTypeVtbl + -1;
                do {
                  oldRefCount = *refCountPtr;
                  if (reservation != '\0') {
                    newRefCount = (undefined *)storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
                    *refCountPtr = newRefCount;
                    reservationOk = 2;
                  }
                } while (!(bool)(reservationOk >> 1 & 1));
                if ((int)oldRefCount < 1) {
                  __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(binaryTypeVtbl + -3),&binaryTypeWord4Overlay);
                }
                __ZN13TInfoSinkBase6appendEPKc(infoSink,": ");
                __ZN13TInfoSinkBase6appendEPKc
                          (infoSink,"Divide by zero error during constant folding");
                __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
                thisElementCount = 0x7fffffff;
              }
              else {
                thisElementCount = **(int **)(rightUnionNode + 0x30) / *(int *)(thisUnion + loopIndex * 4);
              }
              *(int *)(loopIndex * 4 + newComponentArray) = thisElementCount;
            }
            else {
              if (**(int **)(rightUnionNode + 0x30) == 0) {
                sourceLoc = (*(code *)**(undefined4 **)this)(this);
                    
                __ZN13TInfoSinkBase6appendEPKc(infoSink,"WARNING: ");
                sourceLine = sourceLoc & 0xffff;
                reservationOk = (sourceLine == 0) << 1;
                if (sourceLine == 0) {
                  _sprintf((char *)&binaryTypeWord4Overlay,"%d:? ",(int)sourceLoc >> 0x10);
                }
                else {
                  _sprintf((char *)&binaryTypeWord4Overlay,"%d:%d",(int)sourceLoc >> 0x10,sourceLine);
                }
                __ZNSsC1EPKcRKSaIcE(&binaryTypeVtbl,(char *)&binaryTypeWord4Overlay,(unsigned char *)&compareTypeWord8);
                *(undefined *)((int)binaryTypeVtbl + (int)binaryTypeVtbl[-3]) = *PTR__S_terminal_a7b7c0b8;
                __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)binaryTypeVtbl);
                refCountPtr = binaryTypeVtbl + -1;
                do {
                  oldRefCount = *refCountPtr;
                  if (reservation != '\0') {
                    newRefCount = (undefined *)storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
                    *refCountPtr = newRefCount;
                    reservationOk = 2;
                  }
                } while (!(bool)(reservationOk >> 1 & 1));
                if ((int)oldRefCount < 1) {
                  __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(binaryTypeVtbl + -3),&binaryTypeWord4Overlay);
                }
                __ZN13TInfoSinkBase6appendEPKc(infoSink,": ");
                __ZN13TInfoSinkBase6appendEPKc
                          (infoSink,"Divide by zero error during constant folding");
                __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
                minValue = 0x7fffffff;
                thisElementCount = loopIndex << 2;
              }
              else {
                thisElementCount = loopIndex * 4;
                minValue = *(int *)(thisUnion + thisElementCount) / **(int **)(rightUnionNode + 0x30);
              }
              *(int *)(thisElementCount + newComponentArray) = minValue;
            }
          }
        }
        break;
      case 0x13:
      case 0x16:
        picBase = 0xa7b81734;
        thisElementCount = (**(code **)(*(int *)this + 0x4c))(this);
        poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
        allocPair = TPoolAllocator__allocate(poolAllocator,thisElementCount << 2);
        newComponentArray = (int)((ulonglong)allocPair >> 0x20);
        r4Value = (undefined4)allocPair;
        for (componentLoopIndex = 0; loopBound = (**(code **)(*(int *)this + 0x4c))(this,r4Value), componentLoopIndex < loopBound;
            componentLoopIndex = componentLoopIndex + 1) {
          (**(code **)(*(int *)this + 0x38))(&binaryTypeVtbl,this);
          typeBasicTypeField = binaryTypeBits >> 0x13 & 0x3f;
          binaryTypeVtbl = (undefined **)(picBase - 0x473c);
          if (typeBasicTypeField == 1) {
            *(float *)(newComponentArray + componentLoopIndex * 4) =
                 *(float *)(thisUnion + componentLoopIndex * 4) * **(float **)(rightUnionNode + 0x30);
          }
          else {
            if (typeBasicTypeField != 2) {
              message = "Constant folding cannot be done for \"*\"";
              sourceLoc = (*(code *)**(undefined4 **)this)
                                 (this,r4In1,rightOperandArg,infoSinkArg,operandTypeQuery,unusedArg6,picBase);
                    
              __ZN13TInfoSinkBase6appendEPKc(infoSink,"INTERNAL ERROR: ");
              sourceLine = sourceLoc & 0xffff;
              reservationOk = (sourceLine == 0) << 1;
              if (sourceLine == 0) {
                _sprintf((char *)rightTypeOverlay,"%d:? ",(int)sourceLoc >> 0x10);
              }
              else {
                _sprintf((char *)rightTypeOverlay,"%d:%d",(int)sourceLoc >> 0x10,sourceLine);
              }
              locText = (unsigned char *)&binaryTypeWord4Overlay;
              __ZNSsC1EPKcRKSaIcE(&binaryTypeVtbl,(char *)rightTypeOverlay,locText);
              *(undefined *)((int)binaryTypeVtbl + (int)binaryTypeVtbl[-3]) = *PTR__S_terminal_a7b7c0b8;
              __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)binaryTypeVtbl);
              refCountPtr = binaryTypeVtbl;
              goto code_r0x97b932f0;
            }
            *(int *)(componentLoopIndex * 4 + newComponentArray) =
                 *(int *)(thisUnion + componentLoopIndex * 4) * **(int **)(rightUnionNode + 0x30);
          }
          r4Value = r4In1;
        }
        break;
      case 0x17:
        picBase = 0xa7b81734;
        thisElementCount = (**(code **)(*(int *)this + 0x4c))(this);
        poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
        allocPair = TPoolAllocator__allocate(poolAllocator,thisElementCount << 2);
        newComponentArray = (int)((ulonglong)allocPair >> 0x20);
        r4Value = (undefined4)allocPair;
        for (componentLoopIndex = 0; loopBound = (**(code **)(*(int *)this + 0x4c))(this,r4Value), componentLoopIndex < loopBound;
            componentLoopIndex = componentLoopIndex + 1) {
          (**(code **)(*(int *)this + 0x38))(&binaryTypeVtbl,this);
          binaryTypeVtbl = (undefined **)(picBase - 0x473c);
          if ((binaryTypeBits >> 0x13 & 0x3f) != 3) {
            message = "Constant folding cannot be done for \"||\"";
            sourceLoc = (*(code *)**(undefined4 **)this)(this,r4In5,rightOperandArg,infoSinkArg,operandTypeQuery,unusedArg6,picBase)
            ;
                    
            goto override_jmp_97b9198c_case_0;
          }
          r4Value = 0;
          if ((*(int *)(thisUnion + componentLoopIndex * 4) != 0) || (**(int **)(rightUnionNode + 0x30) != 0)) {
            r4Value = 1;
          }
          *(undefined4 *)(componentLoopIndex * 4 + newComponentArray) = r4Value;
          r4Value = r4In5;
        }
        break;
      case 0x18:
        picBase = 0xa7b81734;
        elementCount = (**(code **)(*(int *)this + 0x4c))(this);
        poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
        allocPair = TPoolAllocator__allocate(poolAllocator,elementCount << 2);
        newComponentArray = (int)((ulonglong)allocPair >> 0x20);
        r4Value = (undefined4)allocPair;
        for (componentCounter = 0;
            thisElementCount = (**(code **)(*(int *)this + 0x4c))
                               (this,r4Value,rightOperandArg,infoSinkArg,operandTypeQuery,unusedArg6,thisElementCount), componentCounter < thisElementCount;
            componentCounter = componentCounter + 1) {
          (**(code **)(*(int *)this + 0x38))(&binaryTypeVtbl,this);
          binaryTypeVtbl = (undefined **)(picBase - 0x473c);
          if ((binaryTypeBits >> 0x13 & 0x3f) != 3) {
            message = "Constant folding cannot be done for \"^^\"";
            sourceLoc = (*(code *)**(undefined4 **)this)(this,r4In4,rightOperandArg,infoSinkArg,operandTypeQuery,unusedArg6,picBase)
            ;
                    
            goto override_jmp_97b9198c_case_0;
          }
          componentXor = *(uint *)(thisUnion + componentCounter * 4) ^ **(uint **)(rightUnionNode + 0x30);
          thisElementCount = componentXor - 1;
          *(uint *)(componentCounter * 4 + newComponentArray) = componentXor - (thisElementCount + (uint)(componentXor == 0));
          r4Value = r4In4;
        }
        break;
      case 0x19:
        picBase = 0xa7b81734;
        thisElementCount = (**(code **)(*(int *)this + 0x4c))(this,operatorOffset);
        poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
        newComponentArray = TPoolAllocator__allocate(poolAllocator,thisElementCount << 2);
        for (componentLoopIndex = 0; loopBound = (**(code **)(*(int *)this + 0x4c))(this), componentLoopIndex < loopBound;
            componentLoopIndex = componentLoopIndex + 1) {
          (**(code **)(*(int *)this + 0x38))(&binaryTypeVtbl,this);
          binaryTypeVtbl = (undefined **)(picBase - 0x473c);
          if ((binaryTypeBits >> 0x13 & 0x3f) != 3) {
            message = "Constant folding cannot be done for \"&&\"";
            sourceLoc = (*(code *)**(undefined4 **)this)(this,r4In3,rightOperandArg,infoSinkArg,operandTypeQuery,unusedArg6,picBase)
            ;
                    
            goto override_jmp_97b9198c_case_0;
          }
          r4Value = 0;
          if ((*(int *)(thisUnion + componentLoopIndex * 4) != 0) && (**(int **)(rightUnionNode + 0x30) != 0)) {
            r4Value = 1;
          }
          *(undefined4 *)(componentLoopIndex * 4 + newComponentArray) = r4Value;
        }
      }
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      foldResultNode = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x34);
      (**(code **)(*(int *)this + 0x38))(&binaryTypeVtbl,this);
      *(int *)(foldResultNode + 4) = 0;
      *(undefined ***)foldResultNode = &PTR_getLine_a7b7cf90;
      *(int *)(foldResultNode + 0xc) = binaryTypeWord1;
      binaryTypeVtbl = (undefined **)(picBase - 0x473c);
      *(int *)(foldResultNode + 0x10) = binaryTypeWord2;
      *(int *)(foldResultNode + 0x14) = binaryTypeWord3;
      *(int *)(foldResultNode + 0x18) = binaryTypeWord4Overlay;
      *(int *)(foldResultNode + 0x1c) = binaryTypeWord5;
      *(int *)(foldResultNode + 0x20) = binaryTypeWord6;
      *(undefined ***)(foldResultNode + 8) = binaryTypeVtbl;
      *(int *)(foldResultNode + 0x24) = binaryTypeWord7;
      *(int *)(foldResultNode + 0x28) = binaryTypeWord8;
      nodeBitsBefore = *(uint *)(foldResultNode + 0x2c);
      qualifierBits = binaryTypeBits & 0xfe000000;
      *(uint *)(foldResultNode + 0x2c) = qualifierBits | nodeBitsBefore & 0x1ffffff;
      basicTypeInPlace = (binaryTypeBits >> 0x13 & 0x3f) << 0x13;
      *(uint *)(foldResultNode + 0x2c) = basicTypeInPlace | qualifierBits | nodeBitsBefore & 0x7ffff;
      nominalSizeInPlace = binaryTypeBits & 0x7f800;
      *(uint *)(foldResultNode + 0x2c) = nominalSizeInPlace | basicTypeInPlace | qualifierBits | nodeBitsBefore & 0x7ff;
      typeBit10 = (binaryTypeBits >> 10 & 1) << 10;
      *(uint *)(foldResultNode + 0x2c) = typeBit10 | nominalSizeInPlace | basicTypeInPlace | qualifierBits | nodeBitsBefore & 0x3ff;
      constUnionVtable = PTR_vtable_a7b7c0c8;
      *(uint *)(foldResultNode + 0x2c) =
           (binaryTypeBits >> 9 & 1) << 9 | typeBit10 | nominalSizeInPlace | basicTypeInPlace | qualifierBits | nodeBitsBefore & 0x1ff;
      *(undefined **)foldResultNode = constUnionVtable + 8;
      *(int *)(foldResultNode + 0x30) = newComponentArray;
      goto LAB_97b94758;
    }
switchD_97b91834_caseD_15:
    message = "Invalid operator for constant folding";
    sourceLoc = (*(code *)**(undefined4 **)this)(this);
                    
    __ZN13TInfoSinkBase6appendEPKc(infoSink,"INTERNAL ERROR: ");
    sourceLine = sourceLoc & 0xffff;
    reservationOk = (sourceLine == 0) << 1;
    if (sourceLine == 0) {
      _sprintf((char *)&binaryTypeWord4Overlay,"%d:? ",(int)sourceLoc >> 0x10);
    }
    else {
      _sprintf((char *)&binaryTypeWord4Overlay,"%d:%d",(int)sourceLoc >> 0x10,sourceLine);
    }
    locText = (unsigned char *)&binaryTypeWord4Overlay;
    __ZNSsC1EPKcRKSaIcE(&binaryTypeVtbl,(char *)locText,(unsigned char *)&compareTypeWord8);
    *(undefined *)((int)binaryTypeVtbl + (int)binaryTypeVtbl[-3]) = *PTR__S_terminal_a7b7c0b8;
    __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)binaryTypeVtbl);
    refCountPtrCopy = binaryTypeVtbl + -1;
    do {
      oldRefCount = *refCountPtrCopy;
      if (reservation != '\0') {
        newRefCount = (undefined *)storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtrCopy);
        *refCountPtrCopy = newRefCount;
        reservationOk = 2;
      }
      refCountPtr = binaryTypeVtbl;
    } while (!(bool)(reservationOk >> 1 & 1));
    goto joined_r0x97b95b7c;
  }
LAB_97b92a7c:
  rightUnionNode = (**(code **)(*(int *)rightOperand + 0x18))(rightOperand);
  if (rightUnionNode != 0) {
    sizeQuery = (**(code **)(*(int *)this + 0x4c))(this);
    r4Value = r4Out0;
    if (sizeQuery < 2) {
      picBase = 0xa7b81734;
      (**(code **)(*(int *)this + 0x38))(&binaryTypeVtbl,this);
      binaryTypeVtbl = (undefined **)(picBase - 0x473c);
      r4Value = r4Out1;
      unusedArg7 = picBase;
      if ((binaryTypeBits >> 0x13 & 0x3f) != 0xe) goto LAB_97b9478c;
    }
    allocatedArray = 0;
    canFold = false;
    rightConstUnion = (int *)(**(code **)(*(int *)rightOperand + 0x18))
                          (rightOperand,r4Value,rightOperandArg,infoSinkArg,operandTypeQuery,unusedArg6,unusedArg7);
    operatorOffset = op - 0x13;
    rightFloats = (float *)rightConstUnion[0xc];
    compareStructureOut = 0;
    if (0x43 < operatorOffset) {
switchD_97b92b40_caseD_17:
      message = "Invalid operator for constant folding";
      sourceLoc = (*(code *)**(undefined4 **)this)(this);
                    
override_jmp_97b938f4_case_0:
      __ZN13TInfoSinkBase6appendEPKc(infoSink,"INTERNAL ERROR: ");
      sourceLine = sourceLoc & 0xffff;
      reservationOk = (sourceLine == 0) << 1;
      if (sourceLine == 0) {
        _sprintf((char *)&compareTypeWord4Overlay,"%d:? ",(int)sourceLoc >> 0x10);
      }
      else {
        _sprintf((char *)&compareTypeWord4Overlay,"%d:%d",(int)sourceLoc >> 0x10,sourceLine);
      }
code_r0x97b945f4:
      __ZNSsC1EPKcRKSaIcE(&compareTypeVtbl,(char *)&compareTypeWord4Overlay,stringAllocator);
      *(undefined *)((int)compareTypeVtbl + (int)compareTypeVtbl[-3]) = *PTR__S_terminal_a7b7c0b8;
      __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)compareTypeVtbl);
      refCountPtr = compareTypeVtbl + -1;
      do {
        oldRefCount = *refCountPtr;
        if (reservation != '\0') {
          newRefCount = (undefined *)storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
          *refCountPtr = newRefCount;
          reservationOk = 2;
        }
      } while (!(bool)(reservationOk >> 1 & 1));
      locText = (unsigned char *)&compareTypeWord4Overlay;
      refCountPtr = compareTypeVtbl;
      goto joined_r0x97b95b7c;
    }
    thisElementCount = operatorOffset * 4;
    switch(operatorOffset) {
    case 0:
      picBase = 0xa7b81734;
      sizeQuery = (**(code **)(*(int *)this + 0x4c))(this,operatorOffset,rightOperandArg,infoSinkArg,operandTypeQuery,unusedArg6,thisElementCount);
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      allocPair = TPoolAllocator__allocate(poolAllocator,sizeQuery << 2);
      allocatedArray = (int)((ulonglong)allocPair >> 0x20);
      r4Value = (undefined4)allocPair;
      for (componentLoopIndex = 0; elementCount = (**(code **)(*(int *)this + 0x4c))(this,r4Value), componentLoopIndex < elementCount;
          componentLoopIndex = componentLoopIndex + 1) {
        (**(code **)(*(int *)this + 0x38))(&compareTypeVtbl,this);
        typeBasicTypeField = compareTypeBits >> 0x13 & 0x3f;
        compareTypeVtbl = (undefined **)(picBase - 0x473c);
        if (typeBasicTypeField != 1) {
          if (typeBasicTypeField == 2) {
            *(int *)(allocatedArray + componentLoopIndex * 4) = *(int *)(thisUnion + componentLoopIndex * 4) + (int)GH_F2U(rightFloats[componentLoopIndex]);
            goto LAB_97b92dd4;
          }
          message = "Constant folding cannot be done for \"+\"";
          sourceLoc = (*(code *)**(undefined4 **)this)(this,r4In6,rightOperandArg,infoSinkArg,operandTypeQuery,unusedArg6,picBase);
                    
          __ZN13TInfoSinkBase6appendEPKc(infoSink,"INTERNAL ERROR: ");
          sourceLine = sourceLoc & 0xffff;
          reservationOk = (sourceLine == 0) << 1;
          if (sourceLine == 0) {
            _sprintf((char *)&compareTypeWord4Overlay,"%d:? ",(int)sourceLoc >> 0x10);
          }
          else {
            _sprintf((char *)&compareTypeWord4Overlay,"%d:%d",(int)sourceLoc >> 0x10,sourceLine);
          }
          locText = (unsigned char *)&tailTypeWord4Overlay;
code_r0x97b93f6c:
          __ZNSsC1EPKcRKSaIcE(&compareTypeVtbl,(char *)&compareTypeWord4Overlay,locText);
          *(undefined *)((int)compareTypeVtbl + (int)compareTypeVtbl[-3]) = *PTR__S_terminal_a7b7c0b8;
          __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)compareTypeVtbl);
          refCountPtr = compareTypeVtbl + -1;
          stringRep = (unsigned char *)(compareTypeVtbl + -3);
          do {
            oldRefCount = *refCountPtr;
            if (reservation != '\0') {
              newRefCount = (undefined *)storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
              *refCountPtr = newRefCount;
              reservationOk = 2;
            }
          } while (!(bool)(reservationOk >> 1 & 1));
          refCountPositive = 0 < (int)oldRefCount;
          locText = (unsigned char *)&compareTypeWord4Overlay;
          goto code_r0x97b93fb8;
        }
        *(float *)(allocatedArray + componentLoopIndex * 4) = *(float *)(thisUnion + componentLoopIndex * 4) + rightFloats[componentLoopIndex];
LAB_97b92dd4:
        r4Value = r4In6;
      }
      break;
    case 1:
      picBase = 0xa7b81734;
      sizeQuery = (**(code **)(*(int *)this + 0x4c))(this);
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      allocPair = TPoolAllocator__allocate(poolAllocator,sizeQuery << 2);
      allocatedArray = (int)((ulonglong)allocPair >> 0x20);
      r4Value = (undefined4)allocPair;
      for (componentLoopIndex = 0; elementCount = (**(code **)(*(int *)this + 0x4c))(this,r4Value), componentLoopIndex < elementCount;
          componentLoopIndex = componentLoopIndex + 1) {
        (**(code **)(*(int *)this + 0x38))(&compareTypeVtbl,this);
        typeBasicTypeField = compareTypeBits >> 0x13 & 0x3f;
        compareTypeVtbl = (undefined **)(picBase - 0x473c);
        if (typeBasicTypeField == 1) {
          if (swapOperands == 0) {
            operandValue = rightFloats[componentLoopIndex];
            leftValue = *(float *)(thisUnion + componentLoopIndex * 4);
          }
          else {
            operandValue = *(float *)(thisUnion + componentLoopIndex * 4);
            leftValue = rightFloats[componentLoopIndex];
          }
          *(float *)(allocatedArray + componentLoopIndex * 4) = operandValue - leftValue;
        }
        else {
          if (typeBasicTypeField != 2) {
            message = "Constant folding cannot be done for \"-\"";
            sourceLoc = (*(code *)**(undefined4 **)this)(this,r4In7,rightOperandArg,infoSinkArg,operandTypeQuery,unusedArg6,picBase)
            ;
                    
            __ZN13TInfoSinkBase6appendEPKc(infoSink,"INTERNAL ERROR: ");
            sourceLine = sourceLoc & 0xffff;
            reservationOk = (sourceLine == 0) << 1;
            if (sourceLine == 0) {
              _sprintf((char *)&compareTypeWord4Overlay,"%d:? ",(int)sourceLoc >> 0x10);
            }
            else {
              _sprintf((char *)&compareTypeWord4Overlay,"%d:%d",(int)sourceLoc >> 0x10,sourceLine);
            }
            locText = (unsigned char *)&tailTypeWord8;
            goto code_r0x97b93f6c;
          }
          if (swapOperands == 0) {
            operandValue = rightFloats[componentLoopIndex];
            leftValue = *(float *)(thisUnion + componentLoopIndex * 4);
          }
          else {
            operandValue = *(float *)(thisUnion + componentLoopIndex * 4);
            leftValue = rightFloats[componentLoopIndex];
          }
          *(int *)(allocatedArray + componentLoopIndex * 4) = (int)GH_F2U(operandValue) - (int)GH_F2U(leftValue);
        }
        r4Value = r4In7;
      }
      break;
    case 2:
      thisIsVector = (**(code **)(*(int *)this + 0x58))(this);
      if (thisIsVector != 0) {
        scanIndex = 0;
        thisElementCount = (**(code **)(*(int *)this + 0x4c))(this);
        poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
        allocatedArray = TPoolAllocator__allocate(poolAllocator,thisElementCount << 2);
        if (0 < thisElementCount) {
          picBase = 0xa7b81734;
          do {
            (**(code **)(*(int *)this + 0x38))(&compareTypeVtbl,this);
            typeBasicTypeField = compareTypeBits >> 0x13 & 0x3f;
            compareTypeVtbl = (undefined **)(picBase - 0x473c);
            if (typeBasicTypeField == 1) {
              *(float *)(allocatedArray + scanIndex * 4) = *(float *)(thisUnion + scanIndex * 4) * rightFloats[scanIndex];
            }
            else {
              if (typeBasicTypeField != 2) {
                message = "Constant folding cannot be done for vector multiply";
                sourceLoc = (*(code *)**(undefined4 **)this)
                                   (this,r4In8,rightOperandArg,infoSinkArg,operandTypeQuery,unusedArg6,picBase);
                    
                __ZN13TInfoSinkBase6appendEPKc(infoSink,"INTERNAL ERROR: ");
                sourceLine = sourceLoc & 0xffff;
                reservationOk = (sourceLine == 0) << 1;
                if (sourceLine == 0) {
                  _sprintf((char *)&compareTypeWord4Overlay,"%d:? ",(int)sourceLoc >> 0x10);
                }
                else {
                  _sprintf((char *)&compareTypeWord4Overlay,"%d:%d",(int)sourceLoc >> 0x10,sourceLine);
                }
                locText = stringAllocator2;
                goto code_r0x97b93f6c;
              }
              *(int *)(allocatedArray + scanIndex * 4) = *(int *)(thisUnion + scanIndex * 4) * (int)GH_F2U(rightFloats[scanIndex]);
            }
            scanIndex = scanIndex + 1;
          } while (scanIndex < thisElementCount);
          break;
        }
      }
      picBase = 0xa7b81734;
      break;
    case 3:
      picBase = 0xa7b81734;
      thisSizeValue = (**(code **)(*(int *)this + 0x4c))(this);
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      allocatedArray = TPoolAllocator__allocate(poolAllocator,thisSizeValue << 2);
      for (loopIndex = 0; thisElementCount = (**(code **)(*(int *)this + 0x4c))(this), loopIndex < thisElementCount;
          loopIndex = loopIndex + 1) {
        (**(code **)(*(int *)this + 0x38))(&compareTypeVtbl,this);
        typeBasicTypeField = compareTypeBits >> 0x13 & 0x3f;
        compareTypeVtbl = (undefined **)(picBase - 0x473c);
        if (typeBasicTypeField != 1) {
          if (typeBasicTypeField == 2) {
            if (swapOperands == 0) {
              operandValue = *(float *)(thisUnion + loopIndex * 4);
              if (operandValue == 0.0) {
                sourceLoc = (*(code *)**(undefined4 **)this)(this);
                    
                goto override_jmp_97b93698_case_0;
              }
              leftValue = rightFloats[loopIndex];
code_r0x97b93828:
              divisionResult = (int)GH_F2U(leftValue) / (int)GH_F2U(operandValue);
            }
            else {
              operandValue = rightFloats[loopIndex];
              if (operandValue != 0.0) {
                leftValue = *(float *)(thisUnion + loopIndex * 4);
                goto code_r0x97b93828;
              }
              sourceLoc = (*(code *)**(undefined4 **)this)(this);
                    
override_jmp_97b93698_case_0:
              __ZN13TInfoSinkBase6appendEPKc(infoSink,"WARNING: ");
              sourceLine = sourceLoc & 0xffff;
              reservationOk = (sourceLine == 0) << 1;
              if (sourceLine == 0) {
                _sprintf((char *)&compareTypeWord4Overlay,"%d:? ",(int)sourceLoc >> 0x10);
              }
              else {
                _sprintf((char *)&compareTypeWord4Overlay,"%d:%d",(int)sourceLoc >> 0x10,sourceLine);
              }
              __ZNSsC1EPKcRKSaIcE(&compareTypeVtbl,(char *)&compareTypeWord4Overlay,stringAllocator);
              *(undefined *)((int)compareTypeVtbl + (int)compareTypeVtbl[-3]) = *PTR__S_terminal_a7b7c0b8;
              __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)compareTypeVtbl);
              refCountPtr = compareTypeVtbl + -1;
              do {
                oldRefCount = *refCountPtr;
                if (reservation != '\0') {
                  newRefCount = (undefined *)storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
                  *refCountPtr = newRefCount;
                  reservationOk = 2;
                }
              } while (!(bool)(reservationOk >> 1 & 1));
              if ((int)oldRefCount < 1) {
                __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(compareTypeVtbl + -3),&compareTypeWord4Overlay);
              }
              __ZN13TInfoSinkBase6appendEPKc(infoSink,": ");
              __ZN13TInfoSinkBase6appendEPKc(infoSink,"Divide by zero error during constant folding")
              ;
              __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
              divisionResult = 0x7fffffff;
            }
            *(int *)(loopIndex * 4 + allocatedArray) = divisionResult;
            goto code_r0x97b93884;
          }
          message = "Constant folding cannot be done for \"/\"";
          sourceLoc = (*(code *)**(undefined4 **)this)(this);
                    
override_jmp_97b93868_case_0:
          __ZN13TInfoSinkBase6appendEPKc(infoSink,"INTERNAL ERROR: ");
          sourceLine = sourceLoc & 0xffff;
          reservationOk = (sourceLine == 0) << 1;
          if (sourceLine == 0) {
            _sprintf((char *)&compareTypeWord4Overlay,"%d:? ",(int)sourceLoc >> 0x10);
          }
          else {
            _sprintf((char *)&compareTypeWord4Overlay,"%d:%d",(int)sourceLoc >> 0x10,sourceLine);
          }
          locText = stringAllocator;
          goto code_r0x97b93f6c;
        }
        if (swapOperands == 0) {
          operandValue = *(float *)(thisUnion + loopIndex * 4);
          if (operandValue == 0.0) {
            sourceLoc = (*(code *)**(undefined4 **)this)(this);
                    
            goto override_jmp_97b934a8_case_0;
          }
          leftValue = rightFloats[loopIndex];
code_r0x97b93640:
          leftValue = leftValue / operandValue;
        }
        else {
          operandValue = rightFloats[loopIndex];
          if (operandValue != 0.0) {
            leftValue = *(float *)(thisUnion + loopIndex * 4);
            goto code_r0x97b93640;
          }
          sourceLoc = (*(code *)**(undefined4 **)this)(this);
                    
override_jmp_97b934a8_case_0:
          __ZN13TInfoSinkBase6appendEPKc(infoSink,"WARNING: ");
          sourceLine = sourceLoc & 0xffff;
          reservationOk = (sourceLine == 0) << 1;
          if (sourceLine == 0) {
            _sprintf((char *)&compareTypeWord4Overlay,"%d:? ",(int)sourceLoc >> 0x10);
          }
          else {
            _sprintf((char *)&compareTypeWord4Overlay,"%d:%d",(int)sourceLoc >> 0x10,sourceLine);
          }
          __ZNSsC1EPKcRKSaIcE(&compareTypeVtbl,(char *)&compareTypeWord4Overlay,stringAllocator);
          *(undefined *)((int)compareTypeVtbl + (int)compareTypeVtbl[-3]) = *PTR__S_terminal_a7b7c0b8;
          __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)compareTypeVtbl);
          refCountPtr = compareTypeVtbl + -1;
          do {
            oldRefCount = *refCountPtr;
            if (reservation != '\0') {
              newRefCount = (undefined *)storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
              *refCountPtr = newRefCount;
              reservationOk = 2;
            }
          } while (!(bool)(reservationOk >> 1 & 1));
          if ((int)oldRefCount < 1) {
            __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(compareTypeVtbl + -3),&compareTypeWord4Overlay);
          }
          __ZN13TInfoSinkBase6appendEPKc(infoSink,": ");
          __ZN13TInfoSinkBase6appendEPKc(infoSink,"Divide by zero error during constant folding");
          __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
          leftValue = 3.4028235e+38;
        }
        *(float *)(loopIndex * 4 + allocatedArray) = leftValue;
code_r0x97b93884: ;
      }
      break;
    default:
      goto switchD_97b92b40_caseD_17;
    case 10:
      picBase = 0xa7b81734;
      (**(code **)(*(int *)this + 0x38))((unsigned char *)&compareTypeVtbl,this);
      typeBasicTypeField = compareTypeBits >> 0x13 & 0x3f;
      refCountPtr = (undefined **)(picBase - 0x473c);
      compareTypeVtbl = refCountPtr;
      if (typeBasicTypeField == 2) {
        r4Value = r4Out4;
        operandValue = GH_U2F((unsigned int)(picBase));
        for (componentIndex = 0;
            thisElementCount = (**(code **)(*(int *)this + 0x4c))(this,r4Value,rightOperandArg,infoSinkArg,operandTypeQuery,unusedArg6,operandValue)
            , componentIndex < thisElementCount; componentIndex = componentIndex + 1) {
          operandValue = rightFloats[componentIndex];
          if (*(float *)(thisUnion + componentIndex * 4) != operandValue) goto LAB_97b94304;
          r4Value = r4Out6;
        }
        goto LAB_97b943d4;
      }
      if (2 < typeBasicTypeField) {
        if (typeBasicTypeField == 3) {
          r4Value = r4Out4;
          operandValue = GH_U2F((unsigned int)(picBase));
          for (componentIndex = 0;
              thisElementCount = (**(code **)(*(int *)this + 0x4c))
                                 (this,r4Value,rightOperandArg,infoSinkArg,operandTypeQuery,unusedArg6,operandValue), componentIndex < thisElementCount;
              componentIndex = componentIndex + 1) {
            operandValue = rightFloats[componentIndex];
            if (*(float *)(thisUnion + componentIndex * 4) != operandValue) goto LAB_97b94304;
            r4Value = r4Out7;
          }
        }
        else {
          if (typeBasicTypeField != 0xe) goto LAB_97b9414c;
          rightUnionArray = (unsigned char *)rightConstUnion[0xc];
          (**(code **)(*rightConstUnion + 0x38))((unsigned char *)&compareTypeVtbl,rightConstUnion);
          structuresEqual = ((int (*)())compareStructure)((unsigned char *)&compareTypeVtbl,rightUnionArray,thisUnion,&compareStructureOut);
          sizeFlag = structuresEqual == 1;
LAB_97b942fc:
          compareTypeVtbl = refCountPtr;
          if (!sizeFlag) {
LAB_97b94304:
            canFold = true;
          }
        }
        goto LAB_97b943d4;
      }
      if (typeBasicTypeField == 1) {
        r4Value = r4Out4;
        scalarBits = picBase;
        for (componentIndex = 0;
            thisElementCount = (**(code **)(*(int *)this + 0x4c))
                               (this,r4Value,rightOperandArg,infoSinkArg,operandTypeQuery,unusedArg6,scalarBits), componentIndex < thisElementCount;
            componentIndex = componentIndex + 1) {
          if (*(float *)(thisUnion + componentIndex * 4) != rightFloats[componentIndex]) goto LAB_97b94304;
          r4Value = r4Out5;
        }
        goto LAB_97b943d4;
      }
LAB_97b9414c:
      message = "Constant folding cannot be done for \"==\"";
      sourceLoc = (*(code *)**(undefined4 **)this)(this);
                    
override_jmp_97b94180_case_0:
      __ZN13TInfoSinkBase6appendEPKc(infoSink,"INTERNAL ERROR: ");
      sourceLine = sourceLoc & 0xffff;
      reservationOk = (sourceLine == 0) << 1;
      if (sourceLine == 0) {
        _sprintf((char *)&compareTypeWord4Overlay,"%d:? ",(int)sourceLoc >> 0x10);
      }
      else {
        _sprintf((char *)&compareTypeWord4Overlay,"%d:%d",(int)sourceLoc >> 0x10,sourceLine);
      }
      goto code_r0x97b945f4;
    case 0xb:
      picBase = 0xa7b81734;
      (**(code **)(*(int *)this + 0x38))((unsigned char *)&compareTypeVtbl,this);
      typeBasicTypeField = compareTypeBits >> 0x13 & 0x3f;
      refCountPtr = (undefined **)(picBase - 0x473c);
      compareTypeVtbl = refCountPtr;
      if (typeBasicTypeField == 2) {
        r4Value = r4Out8;
        operandValue = GH_U2F((unsigned int)(picBase));
        for (componentIndex = 0;
            thisElementCount = (**(code **)(*(int *)this + 0x4c))(this,r4Value,rightOperandArg,infoSinkArg,operandTypeQuery,unusedArg6,operandValue)
            , componentIndex < thisElementCount; componentIndex = componentIndex + 1) {
          operandValue = rightFloats[componentIndex];
          if (*(float *)(thisUnion + componentIndex * 4) == operandValue) goto LAB_97b94304;
          r4Value = r4Out10;
        }
      }
      else if (typeBasicTypeField < 3) {
        if (typeBasicTypeField != 1) {
LAB_97b9430c:
          message = "Constant folding cannot be done for \"!=\"";
          sourceLoc = (*(code *)**(undefined4 **)this)(this);
                    
          goto override_jmp_97b94180_case_0;
        }
        r4Value = r4Out8;
        scalarBits = picBase;
        for (componentIndex = 0;
            thisElementCount = (**(code **)(*(int *)this + 0x4c))
                               (this,r4Value,rightOperandArg,infoSinkArg,operandTypeQuery,unusedArg6,scalarBits), componentIndex < thisElementCount;
            componentIndex = componentIndex + 1) {
          if (*(float *)(thisUnion + componentIndex * 4) == rightFloats[componentIndex]) goto LAB_97b94304;
          r4Value = r4Out9;
        }
      }
      else {
        if (typeBasicTypeField != 3) {
          if (typeBasicTypeField == 0xe) {
            rightUnionArray = (unsigned char *)rightConstUnion[0xc];
            (**(code **)(*rightConstUnion + 0x38))((unsigned char *)&compareTypeVtbl,rightConstUnion);
            structuresEqual = ((int (*)())compareStructure)((unsigned char *)&compareTypeVtbl,rightUnionArray,thisUnion,&compareStructureOut);
            sizeFlag = structuresEqual == 0;
            goto LAB_97b942fc;
          }
          goto LAB_97b9430c;
        }
        r4Value = r4Out8;
        operandValue = GH_U2F((unsigned int)(picBase));
        for (componentIndex = 0;
            thisElementCount = (**(code **)(*(int *)this + 0x4c))(this,r4Value,rightOperandArg,infoSinkArg,operandTypeQuery,unusedArg6,operandValue)
            , componentIndex < thisElementCount; componentIndex = componentIndex + 1) {
          operandValue = rightFloats[componentIndex];
          if (*(float *)(thisUnion + componentIndex * 4) == operandValue) goto LAB_97b94304;
          r4Value = r4Out11;
        }
      }
LAB_97b943d4:
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      resultBool = (uint *)TPoolAllocator__allocate(poolAllocator,4);
      *resultBool = (uint)!canFold;
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      foldResultNode = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x34);
      compareTypeBits = compareTypeBits & 0x1801ff | 0x4180800;
      compareTypeVtbl = (undefined **)(picBase - 0x473c);
      compareTypeWord1 = 0;
      compareTypeWord3 = 0;
      compareTypeWord4Overlay = 0;
      compareTypeWord5 = 0;
      compareTypeWord6 = 0;
      compareTypeWord7 = 0;
      compareTypeWord8 = 0;
      compareTypeWord2 = 0;
      *(int *)(foldResultNode + 4) = 0;
      *(undefined ***)foldResultNode = &PTR_getLine_a7b7cf90;
      *(int *)(foldResultNode + 0xc) = 0;
      *(int *)(foldResultNode + 0x10) = 0;
      *(int *)(foldResultNode + 0x14) = 0;
      *(int *)(foldResultNode + 0x18) = 0;
      *(int *)(foldResultNode + 0x1c) = 0;
      *(int *)(foldResultNode + 0x20) = 0;
      *(undefined ***)(foldResultNode + 8) = compareTypeVtbl;
      *(int *)(foldResultNode + 0x24) = 0;
      *(int *)(foldResultNode + 0x28) = 0;
      foldNodeBits = *(uint *)(foldResultNode + 0x2c);
      *(uint *)(foldResultNode + 0x2c) = foldNodeBits & 0x1ffffff | 0x4000000;
      basicTypeInPlaceBits = (compareTypeBits >> 0x13 & 0x3f) << 0x13;
      *(uint *)(foldResultNode + 0x2c) = basicTypeInPlaceBits | foldNodeBits & 0x7ffff | 0x4000000;
      *(uint *)(foldResultNode + 0x2c) = basicTypeInPlaceBits | foldNodeBits & 0x7ff | 0x4000000 | 0x800;
      *(uint *)(foldResultNode + 0x2c) = basicTypeInPlaceBits | foldNodeBits & 0x3ff | 0x4000000 | 0x800;
      constUnionVtable = PTR_vtable_a7b7c0c8;
      *(uint *)(foldResultNode + 0x2c) = basicTypeInPlaceBits | foldNodeBits & 0x1ff | 0x4000000 | 0x800;
      *(uint **)(foldResultNode + 0x30) = resultBool;
      *(undefined **)foldResultNode = constUnionVtable + 8;
      thisVtablePtr = *(undefined4 **)this;
      rightOperand = this;
LAB_97b953d4:
      foldNodeVtable = *(int *)foldResultNode;
      r4Value = (*(code *)*thisVtablePtr)(rightOperand);
      (**(code **)(foldNodeVtable + 4))(foldResultNode,r4Value);
      return foldResultNode;
    case 0x14:
      picBase = 0xa7b81734;
      (**(code **)(*(int *)this + 0x38))(&compareTypeVtbl,this);
      compareTypeVtbl = (undefined **)(picBase - 0x473c);
      if ((compareTypeBits >> 0x13 & 0x3f) != 1) {
        message = "Constant Folding cannot be done for vector times matrix";
        sourceLoc = (*(code *)**(undefined4 **)this)(this,r4In9,rightOperandArg,infoSinkArg,operandTypeQuery,unusedArg6,picBase);
                    
        __ZN13TInfoSinkBase6appendEPKc(infoSink,"INTERNAL ERROR: ");
        sourceLine = sourceLoc & 0xffff;
        reservationOk = (sourceLine == 0) << 1;
        if (sourceLine == 0) {
          _sprintf((char *)locTextBuf,"%d:? ",(int)sourceLoc >> 0x10);
        }
        else {
          _sprintf((char *)locTextBuf,"%d:%d",(int)sourceLoc >> 0x10,sourceLine);
        }
        locText = locTextBuf;
        __ZNSsC1EPKcRKSaIcE(rightTypeOverlay,(char *)locText,(unsigned char *)&tailTypeWord8);
        *(undefined *)((int)rightTypeOverlay[0] + (int)rightTypeOverlay[0][-3]) = *PTR__S_terminal_a7b7c0b8;
        __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)rightTypeOverlay[0]);
        refCountPtr = rightTypeOverlay[0];
        goto code_r0x97b95b60;
      }
      thisNominalSize = (**(code **)(*(int *)this + 0x48))(this,r4In9);
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      allocatedArray = TPoolAllocator__allocate(poolAllocator,thisNominalSize << 2);
      thisNominalSize = (**(code **)(*(int *)this + 0x48))(this);
      componentLoopIndex = 0;
      if (0 < thisNominalSize) {
        scanIndex = 0;
        do {
          strideOffset = componentLoopIndex * 4;
          *(undefined4 *)(strideOffset + allocatedArray) = 0;
          if (0 < thisNominalSize) {
            resultCursor = rightFloats + scanIndex;
            thisComponentCursor = thisUnion;
            columnOffset = thisNominalSize;
            do {
              operandValue = *(float *)thisComponentCursor;
              thisComponentCursor = thisComponentCursor + 4;
              leftValue = *resultCursor;
              resultCursor = resultCursor + 1;
              *(float *)(strideOffset + allocatedArray) = operandValue * leftValue + *(float *)(strideOffset + allocatedArray);
              columnOffset = columnOffset + -1;
            } while (columnOffset != 0);
          }
          componentLoopIndex = componentLoopIndex + 1;
          scanIndex = scanIndex + thisNominalSize;
        } while (componentLoopIndex < thisNominalSize);
      }
      break;
    case 0x15:
      operandTypeQuery = (**(code **)(*rightConstUnion + 0x40))(rightConstUnion,operatorOffset);
      if (operandTypeQuery != 1) {
        message = "Constant Folding cannot be done for matrix times vector";
        sourceLoc = (*(code *)**(undefined4 **)this)(this);
                    
        goto override_jmp_97b938f4_case_0;
      }
      thisNominalSize = (**(code **)(*(int *)this + 0x48))(this);
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      allocatedArray = TPoolAllocator__allocate(poolAllocator,thisNominalSize << 2);
      thisNominalSize = (**(code **)(*(int *)this + 0x48))(this);
      componentLoopIndex = 0;
      if (0 < thisNominalSize) {
        scanIndex = 0;
        do {
          *(undefined4 *)(scanIndex + allocatedArray) = 0;
          if (0 < thisNominalSize) {
            thisComponentCursor = thisUnion + scanIndex;
            resultCursor = rightFloats;
            cursorOffset = thisNominalSize;
            do {
              operandValue = *(float *)thisComponentCursor;
              thisComponentCursor = thisComponentCursor + thisNominalSize * 4;
              leftValue = *resultCursor;
              resultCursor = resultCursor + 1;
              *(float *)(scanIndex + allocatedArray) = operandValue * leftValue + *(float *)(scanIndex + allocatedArray);
              cursorOffset = cursorOffset + -1;
            } while (cursorOffset != 0);
          }
          componentLoopIndex = componentLoopIndex + 1;
          scanIndex = scanIndex + 4;
        } while (componentLoopIndex < thisNominalSize);
      }
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      foldResultNode = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x34);
      (**(code **)(*rightConstUnion + 0x38))(&compareTypeVtbl,rightConstUnion);
      *(undefined ***)foldResultNode = &PTR_getLine_a7b7cf90;
      typeVtable = &TType__vtable;
      *(int *)(foldResultNode + 4) = 0;
      goto LAB_97b946a4;
    case 0x17:
      picBase = 0xa7b81734;
      sizeQuery = (**(code **)(*(int *)this + 0x4c))(this);
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      allocPair = TPoolAllocator__allocate(poolAllocator,sizeQuery << 2);
      allocatedArray = (int)((ulonglong)allocPair >> 0x20);
      r4Value = (undefined4)allocPair;
      for (componentLoopIndex = 0; elementCount = (**(code **)(*(int *)this + 0x4c))(this,r4Value), componentLoopIndex < elementCount;
          componentLoopIndex = componentLoopIndex + 1) {
        (**(code **)(*(int *)this + 0x38))(&compareTypeVtbl,this);
        compareTypeVtbl = (undefined **)(picBase - 0x473c);
        if ((compareTypeBits >> 0x13 & 0x3f) != 3) {
          message = "Constant folding cannot be done for \"||\"";
          sourceLoc = (*(code *)**(undefined4 **)this)(this,r4In12,rightOperandArg,infoSinkArg,operandTypeQuery,unusedArg6,picBase);
                    
          goto override_jmp_97b93868_case_0;
        }
        r4Value = 0;
        if ((*(int *)(thisUnion + componentLoopIndex * 4) != 0) || (rightFloats[componentLoopIndex] != 0.0)) {
          r4Value = 1;
        }
        *(undefined4 *)(componentLoopIndex * 4 + allocatedArray) = r4Value;
        r4Value = r4In12;
      }
      break;
    case 0x18:
      picBase = 0xa7b81734;
      sizeQuery = (**(code **)(*(int *)this + 0x4c))(this);
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      allocPair = TPoolAllocator__allocate(poolAllocator,sizeQuery << 2);
      allocatedArray = (int)((ulonglong)allocPair >> 0x20);
      r4Value = (undefined4)allocPair;
      for (scanIndex = 0;
          thisElementCount = (**(code **)(*(int *)this + 0x4c))(this,r4Value,rightOperandArg,infoSinkArg,operandTypeQuery,unusedArg6,thisElementCount),
          scanIndex < thisElementCount; scanIndex = scanIndex + 1) {
        (**(code **)(*(int *)this + 0x38))(&compareTypeVtbl,this);
        compareTypeVtbl = (undefined **)(picBase - 0x473c);
        if ((compareTypeBits >> 0x13 & 0x3f) != 3) {
          message = "Constant folding cannot be done for \"^^\"";
          sourceLoc = (*(code *)**(undefined4 **)this)(this,r4In11,rightOperandArg,infoSinkArg,operandTypeQuery,unusedArg6,picBase);
                    
          goto override_jmp_97b93868_case_0;
        }
        thisElementCount = scanIndex * 4;
        *(uint *)(thisElementCount + allocatedArray) = (uint)(*(float *)(thisUnion + thisElementCount) != rightFloats[scanIndex]);
        r4Value = r4In11;
      }
      break;
    case 0x19:
      picBase = 0xa7b81734;
      allocatedArray = (**(code **)(*(int *)this + 0x4c))(this);
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      allocatedArray = TPoolAllocator__allocate(poolAllocator,allocatedArray << 2);
      for (componentLoopIndex = 0; elementCount = (**(code **)(*(int *)this + 0x4c))(this), componentLoopIndex < elementCount;
          componentLoopIndex = componentLoopIndex + 1) {
        (**(code **)(*(int *)this + 0x38))(&compareTypeVtbl,this);
        compareTypeVtbl = (undefined **)(picBase - 0x473c);
        if ((compareTypeBits >> 0x13 & 0x3f) != 3) {
          message = "Constant folding cannot be done for \"&&\"";
          sourceLoc = (*(code *)**(undefined4 **)this)(this,r4In10,rightOperandArg,infoSinkArg,operandTypeQuery,unusedArg6,picBase);
                    
          goto override_jmp_97b93868_case_0;
        }
        r4Value = 0;
        if ((*(int *)(thisUnion + componentLoopIndex * 4) != 0) && (rightFloats[componentLoopIndex] != 0.0)) {
          r4Value = 1;
        }
        *(undefined4 *)(componentLoopIndex * 4 + allocatedArray) = r4Value;
      }
      break;
    case 0x43:
      canFold = false;
      (**(code **)(*(int *)this + 0x38))(&compareTypeVtbl,this);
      r4Value = r4Out2;
      if (((compareTypeBits >> 0x13 & 0x3f) != 1) ||
         (operandTypeQuery = (**(code **)(*rightConstUnion + 0x40))(rightConstUnion), r4Value = r4Out3, operandTypeQuery != 1)) {
        canFold = true;
      }
      picBase = 0xa7b81734;
      compareTypeVtbl = &PTR___ZN5TTypeD1Ev_a7b7cff8;
      if (!canFold) {
        thisNominalSize = (**(code **)(*(int *)this + 0x48))(this,r4Value);
        poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
        allocatedArray = TPoolAllocator__allocate(poolAllocator,thisNominalSize * thisNominalSize * 4);
        componentLoopIndex = 0;
        if (0 < thisNominalSize) {
          do {
            if (0 < thisNominalSize) {
              columnOffset = 0;
              byteOffset = componentLoopIndex * 4;
              cursorOffset = thisNominalSize;
              do {
                *(undefined4 *)(byteOffset + allocatedArray) = 0;
                if (0 < thisNominalSize) {
                  resultCursor = rightFloats + columnOffset;
                  thisComponentCursor = thisUnion + componentLoopIndex * 4;
                  columnsLeft = thisNominalSize;
                  do {
                    operandValue = *(float *)thisComponentCursor;
                    thisComponentCursor = thisComponentCursor + thisNominalSize * 4;
                    leftValue = *resultCursor;
                    resultCursor = resultCursor + 1;
                    *(float *)(allocatedArray + byteOffset) = operandValue * leftValue + *(float *)(allocatedArray + byteOffset);
                    columnsLeft = columnsLeft + -1;
                  } while (columnsLeft != 0);
                }
                cursorOffset = cursorOffset + -1;
                columnOffset = columnOffset + thisNominalSize;
                byteOffset = byteOffset + thisNominalSize * 4;
              } while (cursorOffset != 0);
            }
            componentLoopIndex = componentLoopIndex + 1;
          } while (componentLoopIndex < thisNominalSize);
        }
        break;
      }
      message = "Constant Folding cannot be done for matrix multiply";
      sourceLoc = (*(code *)**(undefined4 **)this)(this);
                    
      __ZN13TInfoSinkBase6appendEPKc(infoSink,"INTERNAL ERROR: ");
      sourceLine = sourceLoc & 0xffff;
      reservationOk = (sourceLine == 0) << 1;
      if (sourceLine == 0) {
        _sprintf(locTextBuf2,"%d:? ",(int)sourceLoc >> 0x10);
      }
      else {
        _sprintf(locTextBuf2,"%d:%d",(int)sourceLoc >> 0x10,sourceLine);
      }
      locText = locTextBuf;
      __ZNSsC1EPKcRKSaIcE(rightTypeOverlay,locTextBuf2,locText);
      *(undefined *)((int)rightTypeOverlay[0] + (int)rightTypeOverlay[0][-3]) = *PTR__S_terminal_a7b7c0b8;
      __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)rightTypeOverlay[0]);
      refCountPtr = rightTypeOverlay[0];
code_r0x97b932f0:
      refCountPtrCopy = refCountPtr + -1;
      stringRep = (unsigned char *)(refCountPtr + -3);
      do {
        oldRefCount = *refCountPtrCopy;
        if (reservation != '\0') {
          newRefCount = (undefined *)storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtrCopy);
          *refCountPtrCopy = newRefCount;
          reservationOk = 2;
        }
      } while (!(bool)(reservationOk >> 1 & 1));
      refCountPositive = 0 < (int)oldRefCount;
code_r0x97b93fb8:
      if (!refCountPositive) goto code_r0x97b95524;
      goto code_r0x97b95528;
    }
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    foldResultNode = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x34);
    (**(code **)(*(int *)this + 0x38))(&compareTypeVtbl,this);
    *(int *)(foldResultNode + 4) = 0;
    *(undefined ***)foldResultNode = &PTR_getLine_a7b7cf90;
    typeVtable = (undefined *)(picBase - 0x4744);
LAB_97b946a4:
    compareTypeVtbl = (undefined **)(typeVtable + 8);
    *(int *)(foldResultNode + 0xc) = compareTypeWord1;
    *(int *)(foldResultNode + 0x10) = compareTypeWord2;
    *(int *)(foldResultNode + 0x14) = compareTypeWord3;
    *(int *)(foldResultNode + 0x18) = compareTypeWord4Overlay;
    *(int *)(foldResultNode + 0x1c) = compareTypeWord5;
    *(int *)(foldResultNode + 0x20) = compareTypeWord6;
    *(undefined ***)(foldResultNode + 8) = compareTypeVtbl;
    *(int *)(foldResultNode + 0x24) = compareTypeWord7;
    *(int *)(foldResultNode + 0x28) = compareTypeWord8;
    nodeBitsBefore = *(uint *)(foldResultNode + 0x2c);
    qualifierBits = compareTypeBits & 0xfe000000;
    *(uint *)(foldResultNode + 0x2c) = qualifierBits | nodeBitsBefore & 0x1ffffff;
    basicTypeInPlace = (compareTypeBits >> 0x13 & 0x3f) << 0x13;
    *(uint *)(foldResultNode + 0x2c) = basicTypeInPlace | qualifierBits | nodeBitsBefore & 0x7ffff;
    nominalSizeInPlace = compareTypeBits & 0x7f800;
    *(uint *)(foldResultNode + 0x2c) = nominalSizeInPlace | basicTypeInPlace | qualifierBits | nodeBitsBefore & 0x7ff;
    typeBit10 = (compareTypeBits >> 10 & 1) << 10;
    *(uint *)(foldResultNode + 0x2c) = typeBit10 | nominalSizeInPlace | basicTypeInPlace | qualifierBits | nodeBitsBefore & 0x3ff;
    constUnionVtable = PTR_vtable_a7b7c0c8;
    *(uint *)(foldResultNode + 0x2c) =
         (compareTypeBits >> 9 & 1) << 9 | typeBit10 | nominalSizeInPlace | basicTypeInPlace | qualifierBits | nodeBitsBefore & 0x1ff;
    *(int *)(foldResultNode + 0x30) = allocatedArray;
    *(undefined **)foldResultNode = constUnionVtable + 8;
LAB_97b94758:
    foldNodeVtable = *(int *)foldResultNode;
    r4Value = (*(code *)**(undefined4 **)this)(this);
    (**(code **)(foldNodeVtable + 4))(foldResultNode,r4Value);
    return foldResultNode;
  }
LAB_97b9478c:
  canFold = false;
  sizeQuery = (**(code **)(*(int *)this + 0x4c))(this);
  if (sizeQuery != 1) {
    return this;
  }
  (**(code **)(*(int *)this + 0x38))(&compareTypeVtbl,this);
  if (((compareTypeBits >> 0x13 & 0x3f) != 0xe) &&
     (sizeQuery = (**(code **)(*(int *)rightOperand + 0x4c))(rightOperand), sizeQuery == 1)) {
    (**(code **)(*(int *)rightOperand + 0x38))(rightTypeOverlay,rightOperand);
    canFold = (rightTypeBits >> 0x13 & 0x3f) != 0xe;
    rightTypeOverlay[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  }
  compareTypeVtbl = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  if (!canFold) {
    return this;
  }
  poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
  resultFloats = (float *)TPoolAllocator__allocate(poolAllocator,4);
  picBase = 0xa7b81734;
  (**(code **)(*(int *)this + 0x38))(&tailTypeVtbl,this);
  tailTypeVtbl = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  typeBasicTypeField = tailTypeBits >> 0x13 & 0x3f;
  if (typeBasicTypeField != 2) {
    if (2 < typeBasicTypeField) {
      if (typeBasicTypeField != 3) goto LAB_97b95400;
      rightUnionPtr = (**(code **)(*(int *)rightOperand + 0x18))(rightOperand);
      rightFirstValue = **(uint **)(rightUnionPtr + 0x30);
      bitwiseResult = **(uint **)(this + 0x30);
      if (op == 0x2b) {
        equalityResult = bitwiseResult == rightFirstValue;
LAB_97b9529c:
        *resultFloats = GH_U2F((unsigned int)((1 - (uint)equalityResult)));
        poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
        foldResultNode = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x34);
        tailTypeBits = tailTypeBits & 0x1801ff | 0x4180800;
        tailTypeVtbl = (undefined **)(picBase - 0x473c);
        tailTypeWord1 = 0;
        tailTypeWord3 = 0;
        tailTypeWord4Overlay = 0;
        tailTypeWord5 = 0;
        tailTypeWord6 = 0;
        tailTypeWord7 = 0;
        tailTypeWord8 = 0;
        tailTypeWord2 = 0;
        *(int *)(foldResultNode + 4) = 0;
        *(undefined ***)foldResultNode = &PTR_getLine_a7b7cf90;
        *(int *)(foldResultNode + 0xc) = 0;
        *(int *)(foldResultNode + 0x10) = 0;
        *(int *)(foldResultNode + 0x14) = 0;
        *(int *)(foldResultNode + 0x18) = 0;
        *(int *)(foldResultNode + 0x1c) = 0;
        *(int *)(foldResultNode + 0x20) = 0;
        *(undefined ***)(foldResultNode + 8) = tailTypeVtbl;
        *(int *)(foldResultNode + 0x24) = 0;
        *(int *)(foldResultNode + 0x28) = 0;
        foldNodeBits = *(uint *)(foldResultNode + 0x2c);
        *(uint *)(foldResultNode + 0x2c) = foldNodeBits & 0x1ffffff | 0x4000000;
        basicTypeInPlaceBits = (tailTypeBits >> 0x13 & 0x3f) << 0x13;
        *(uint *)(foldResultNode + 0x2c) = basicTypeInPlaceBits | foldNodeBits & 0x7ffff | 0x4000000;
        *(uint *)(foldResultNode + 0x2c) = basicTypeInPlaceBits | foldNodeBits & 0x7ff | 0x4000000 | 0x800;
        *(uint *)(foldResultNode + 0x2c) = basicTypeInPlaceBits | foldNodeBits & 0x3ff | 0x4000000 | 0x800;
        constUnionVtable = PTR_vtable_a7b7c0c8;
        *(uint *)(foldResultNode + 0x2c) = basicTypeInPlaceBits | foldNodeBits & 0x1ff | 0x4000000 | 0x800;
        *(float **)(foldResultNode + 0x30) = resultFloats;
        *(undefined **)foldResultNode = constUnionVtable + 8;
        thisVtablePtr = *(undefined4 **)rightOperand;
        goto LAB_97b953d4;
      }
      if (op < 0x2c) {
        if (op == 0x2a) {
          bitwiseResult = bitwiseResult | rightFirstValue;
LAB_97b95254:
          equalityResult = bitwiseResult == 0;
          goto LAB_97b9529c;
        }
      }
      else {
        bitwiseResult = bitwiseResult & rightFirstValue;
        if (op == 0x2c) goto LAB_97b95254;
      }
      message = "Binary operator cannot be folded into constant bool";
      sourceLoc = *(uint *)(this + 4);
                    
override_jmp_97b95280_case_0:
      __ZN13TInfoSinkBase6appendEPKc(infoSink,"INTERNAL ERROR: ");
      sourceLine = sourceLoc & 0xffff;
      reservationOk = (sourceLine == 0) << 1;
      if (sourceLine == 0) {
        _sprintf((char *)&tailTypeWord4Overlay,"%d:? ",(int)sourceLoc >> 0x10);
      }
      else {
        _sprintf((char *)&tailTypeWord4Overlay,"%d:%d",(int)sourceLoc >> 0x10,sourceLine);
      }
      locText = (unsigned char *)&tailTypeWord4Overlay;
      __ZNSsC1EPKcRKSaIcE(&tailTypeVtbl,(char *)locText,stringAllocator3);
                    
      *(undefined *)((int)tailTypeVtbl + (int)tailTypeVtbl[-3]) = *PTR__S_terminal_a7b7c0b8;
      __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)tailTypeVtbl);
      refCountPtr = tailTypeVtbl + -1;
      stringRep = (unsigned char *)(tailTypeVtbl + -3);
      do {
        oldRefCount = *refCountPtr;
                    
        if (reservation != '\0') {
          newRefCount = (undefined *)storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
          *refCountPtr = newRefCount;
          reservationOk = 2;
        }
      } while (!(bool)(reservationOk >> 1 & 1));
      if ((int)oldRefCount < 1) {
code_r0x97b95524:
        __ZNSs4_Rep10_M_destroyERKSaIcE(stringRep,locText);
      }
code_r0x97b95528:
      __ZN13TInfoSinkBase6appendEPKc(infoSink,": ");
      goto code_r0x97b95ba0;
    }
    if (typeBasicTypeField != 1) {
LAB_97b95400:
      message = "Cannot fold constant";
      sourceLoc = (*(code *)**(undefined4 **)this)(this);
                    
      goto override_jmp_97b95280_case_0;
    }
    rightUnionNode = (**(code **)(*(int *)rightOperand + 0x18))(rightOperand);
    operatorOffset = op - 0x13;
    foldedValue = **(float **)(rightUnionNode + 0x30);
    leftValue = **(float **)(this + 0x30);
    if (0x11 < operatorOffset) {
      return (unsigned char *)0x0;
    }
    switch(operatorOffset) {
    case 0:
      leftValue = leftValue + foldedValue;
      goto LAB_97b94ef8;
    case 1:
      leftValue = leftValue - foldedValue;
      goto LAB_97b94ef8;
    case 2:
      leftValue = leftValue * foldedValue;
      goto LAB_97b94ef8;
    case 3:
      if (foldedValue == 0.0) {
        operatorOffset = (*(code *)**(undefined4 **)this)(this,operatorOffset,rightOperandArg,infoSinkArg,operandTypeQuery,unusedArg6,operatorOffset * 4);
                    
        __ZN13TInfoSinkBase6appendEPKc(infoSink,"WARNING: ");
        sourceLine = operatorOffset & 0xffff;
        reservationOk = (sourceLine == 0) << 1;
        if (sourceLine == 0) {
          _sprintf((char *)&tailTypeWord4Overlay,"%d:? ",(int)operatorOffset >> 0x10);
        }
        else {
          _sprintf((char *)&tailTypeWord4Overlay,"%d:%d",(int)operatorOffset >> 0x10,sourceLine);
        }
        __ZNSsC1EPKcRKSaIcE(&tailTypeVtbl,(char *)&tailTypeWord4Overlay,stringAllocator3);
        *(undefined *)((int)tailTypeVtbl + (int)tailTypeVtbl[-3]) = *PTR__S_terminal_a7b7c0b8;
        __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)tailTypeVtbl);
        refCountPtr = tailTypeVtbl + -1;
        do {
          oldRefCount = *refCountPtr;
          if (reservation != '\0') {
            newRefCount = (undefined *)storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
            *refCountPtr = newRefCount;
            reservationOk = 2;
          }
        } while (!(bool)(reservationOk >> 1 & 1));
        if ((int)oldRefCount < 1) {
          __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(tailTypeVtbl + -3),&tailTypeWord4Overlay);
        }
        __ZN13TInfoSinkBase6appendEPKc(infoSink,": ");
        __ZN13TInfoSinkBase6appendEPKc(infoSink,"Divide by zero error during constant folding");
        __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
        leftValue = 3.4028235e+38;
      }
      else {
        leftValue = leftValue / foldedValue;
      }
LAB_97b94ef8:
      *resultFloats = leftValue;
      goto code_r0x97b95098;
    default:
      goto switchD_97b94d20_caseD_17;
    case 10:
      foldedValue = GH_U2F((unsigned int)((uint)(leftValue == foldedValue)));
      break;
    case 0xb:
      foldedValue = GH_U2F((unsigned int)((uint)(leftValue != foldedValue)));
      break;
    case 0xe:
      foldedValue = GH_U2F((unsigned int)((uint)(leftValue < foldedValue)));
      break;
    case 0xf:
      foldedValue = GH_U2F((unsigned int)((uint)(foldedValue < leftValue)));
      break;
    case 0x10:
      lessEqualResult = leftValue <= foldedValue;
      goto LAB_97b94f58;
    case 0x11:
      lessEqualResult = foldedValue <= leftValue;
LAB_97b94f58:
      foldedValue = GH_U2F((unsigned int)((uint)lessEqualResult));
    }
    *resultFloats = foldedValue;
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    foldResultNode = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x34);
    tailTypeBits = tailTypeBits & 0x1801ff | 0x4180800;
    tailTypeVtbl = (undefined **)(picBase - 0x473c);
    tailTypeWord1 = 0;
    tailTypeWord3 = 0;
    tailTypeWord4Overlay = 0;
    tailTypeWord5 = 0;
    tailTypeWord6 = 0;
    tailTypeWord7 = 0;
    tailTypeWord8 = 0;
    tailTypeWord2 = 0;
    *(int *)(foldResultNode + 4) = 0;
    *(undefined ***)foldResultNode = &PTR_getLine_a7b7cf90;
    *(int *)(foldResultNode + 0xc) = 0;
    *(int *)(foldResultNode + 0x10) = 0;
    *(int *)(foldResultNode + 0x14) = 0;
    *(int *)(foldResultNode + 0x18) = 0;
    *(int *)(foldResultNode + 0x1c) = 0;
    *(int *)(foldResultNode + 0x20) = 0;
    *(int *)(foldResultNode + 0x24) = 0;
    *(undefined ***)(foldResultNode + 8) = tailTypeVtbl;
    *(int *)(foldResultNode + 0x28) = 0;
    foldNodeBits = *(uint *)(foldResultNode + 0x2c);
    *(uint *)(foldResultNode + 0x2c) = foldNodeBits & 0x1ffffff | 0x4000000;
    basicTypeInPlaceBits = (tailTypeBits >> 0x13 & 0x3f) << 0x13;
    *(uint *)(foldResultNode + 0x2c) = basicTypeInPlaceBits | foldNodeBits & 0x7ffff | 0x4000000;
    *(uint *)(foldResultNode + 0x2c) = basicTypeInPlaceBits | foldNodeBits & 0x7ff | 0x4000000 | 0x800;
    *(uint *)(foldResultNode + 0x2c) = basicTypeInPlaceBits | foldNodeBits & 0x3ff | 0x4000000 | 0x800;
    constUnionVtable = PTR_vtable_a7b7c0c8;
    *(uint *)(foldResultNode + 0x2c) = basicTypeInPlaceBits | foldNodeBits & 0x1ff | 0x4000000 | 0x800;
    *(float **)(foldResultNode + 0x30) = resultFloats;
    *(undefined **)foldResultNode = constUnionVtable + 8;
    if (foldResultNode != (unsigned char *)0x0) goto LAB_97b951c0;
code_r0x97b95098:
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    foldResultNode = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x34);
    retypedBits = tailTypeBits & 0x7ff | 0x4080000;
    goto code_r0x97b950c8;
  }
  rightUnionNode = (**(code **)(*(int *)rightOperand + 0x18))(rightOperand);
  operatorOffset = op - 0x13;
  rightFirstComponent = **(uint **)(rightUnionNode + 0x30);
  thisFirstComponent = **(uint **)(this + 0x30);
  if (0x11 < operatorOffset) {
    return (unsigned char *)0x0;
  }
  switch(operatorOffset) {
  case 0:
    integerResult = GH_U2F((unsigned int)((thisFirstComponent + rightFirstComponent)));
    break;
  case 1:
    integerResult = GH_U2F((unsigned int)((thisFirstComponent - rightFirstComponent)));
    break;
  case 2:
    integerResult = GH_U2F((unsigned int)((thisFirstComponent * rightFirstComponent)));
    break;
  case 3:
    if (rightFirstComponent == 0) {
      sourceLoc = (*(code *)**(undefined4 **)this)
                         (this,operatorOffset,rightOperandArg,infoSinkArg,operandTypeQuery,unusedArg6,operatorOffset * 4,thisFirstComponent);
                    
      __ZN13TInfoSinkBase6appendEPKc(infoSink,"WARNING: ");
      sourceLine = sourceLoc & 0xffff;
      reservationOk = (sourceLine == 0) << 1;
      if (sourceLine == 0) {
        _sprintf(locTextBuf3,"%d:? ",(int)sourceLoc >> 0x10);
      }
      else {
        _sprintf(locTextBuf3,"%d:%d",(int)sourceLoc >> 0x10,sourceLine);
      }
      __ZNSsC1EPKcRKSaIcE(&tailTypeVtbl,locTextBuf3,(unsigned char *)&tailTypeWord4Overlay);
      *(undefined *)((int)tailTypeVtbl + (int)tailTypeVtbl[-3]) = *PTR__S_terminal_a7b7c0b8;
      __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)tailTypeVtbl);
      refCountPtr = tailTypeVtbl + -1;
      do {
        oldRefCount = *refCountPtr;
        if (reservation != '\0') {
          newRefCount = (undefined *)storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
          *refCountPtr = newRefCount;
          reservationOk = 2;
        }
      } while (!(bool)(reservationOk >> 1 & 1));
      if ((int)oldRefCount < 1) {
        __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(tailTypeVtbl + -3),(unsigned char *)&tailTypeWord4Overlay);
      }
      __ZN13TInfoSinkBase6appendEPKc(infoSink,": ");
      __ZN13TInfoSinkBase6appendEPKc(infoSink,"Divide by zero error during constant folding");
      __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
      integerResult = GH_U2F(0x7fffffffU);
    }
    else {
      integerResult = GH_U2F((unsigned int)(((int)thisFirstComponent / (int)rightFirstComponent)));
    }
    break;
  case 4:
    integerResult = GH_U2F((unsigned int)((thisFirstComponent - ((int)thisFirstComponent / (int)rightFirstComponent) * rightFirstComponent)));
    break;
  case 5:
    integerResult = GH_U2F((unsigned int)(((int)thisFirstComponent >> (rightFirstComponent & 0x3f))));
    break;
  case 6:
    integerResult = GH_U2F((unsigned int)((thisFirstComponent << (rightFirstComponent & 0x3f))));
    break;
  case 7:
    integerResult = GH_U2F((unsigned int)((thisFirstComponent & rightFirstComponent)));
    break;
  case 8:
    integerResult = GH_U2F((unsigned int)((thisFirstComponent | rightFirstComponent)));
    break;
  case 9:
    integerResult = GH_U2F((unsigned int)((thisFirstComponent ^ rightFirstComponent)));
    break;
  case 10:
    integerResult = GH_U2F((unsigned int)((uint)(thisFirstComponent == rightFirstComponent)));
    goto LAB_97b94b6c;
  case 0xb:
    *resultFloats = GH_U2F((unsigned int)((uint)(thisFirstComponent != rightFirstComponent)));
    goto LAB_97b94b70;
  default:
    goto switchD_97b94d20_caseD_17;
  case 0xe:
    integerResult = 1.4013e-45;
    if ((int)rightFirstComponent <= (int)thisFirstComponent) {
LAB_97b94b68:
      integerResult = 0.0;
    }
    goto LAB_97b94b6c;
  case 0xf:
    integerResult = 1.4013e-45;
    if ((int)thisFirstComponent <= (int)rightFirstComponent) goto LAB_97b94b68;
    goto LAB_97b94b6c;
  case 0x10:
    integerResult = 1.4013e-45;
    if ((int)rightFirstComponent < (int)thisFirstComponent) goto LAB_97b94b68;
    goto LAB_97b94b6c;
  case 0x11:
    integerResult = 1.4013e-45;
    if ((int)thisFirstComponent < (int)rightFirstComponent) goto LAB_97b94b68;
LAB_97b94b6c:
    *resultFloats = integerResult;
LAB_97b94b70:
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    foldResultNode = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x34);
    tailTypeBits = tailTypeBits & 0x1801ff | 0x4180800;
    tailTypeVtbl = (undefined **)(picBase - 0x473c);
    tailTypeWord1 = 0;
    tailTypeWord3 = 0;
    tailTypeWord4Overlay = 0;
    tailTypeWord5 = 0;
    tailTypeWord6 = 0;
    tailTypeWord7 = 0;
    tailTypeWord8 = 0;
    tailTypeWord2 = 0;
    *(int *)(foldResultNode + 4) = 0;
    *(undefined ***)foldResultNode = &PTR_getLine_a7b7cf90;
    *(int *)(foldResultNode + 0xc) = 0;
    *(int *)(foldResultNode + 0x10) = 0;
    *(int *)(foldResultNode + 0x14) = 0;
    *(int *)(foldResultNode + 0x18) = 0;
    *(int *)(foldResultNode + 0x1c) = 0;
    *(int *)(foldResultNode + 0x20) = 0;
    *(int *)(foldResultNode + 0x24) = 0;
    *(undefined ***)(foldResultNode + 8) = tailTypeVtbl;
    *(int *)(foldResultNode + 0x28) = 0;
    foldNodeBits = *(uint *)(foldResultNode + 0x2c);
    *(uint *)(foldResultNode + 0x2c) = foldNodeBits & 0x1ffffff | 0x4000000;
    basicTypeInPlaceBits = (tailTypeBits >> 0x13 & 0x3f) << 0x13;
    *(uint *)(foldResultNode + 0x2c) = basicTypeInPlaceBits | foldNodeBits & 0x7ffff | 0x4000000;
    *(uint *)(foldResultNode + 0x2c) = basicTypeInPlaceBits | foldNodeBits & 0x7ff | 0x4000000 | 0x800;
    *(uint *)(foldResultNode + 0x2c) = basicTypeInPlaceBits | foldNodeBits & 0x3ff | 0x4000000 | 0x800;
    constUnionVtable = PTR_vtable_a7b7c0c8;
    *(uint *)(foldResultNode + 0x2c) = basicTypeInPlaceBits | foldNodeBits & 0x1ff | 0x4000000 | 0x800;
    *(float **)(foldResultNode + 0x30) = resultFloats;
    *(undefined **)foldResultNode = constUnionVtable + 8;
    if (foldResultNode != (unsigned char *)0x0) goto LAB_97b951c0;
    goto code_r0x97b94ca4;
  }
  *resultFloats = integerResult;
code_r0x97b94ca4:
  poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
  foldResultNode = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x34);
  retypedBits = tailTypeBits & 0xfff | 0x4100000;
code_r0x97b950c8:
  tailTypeVtbl = (undefined **)(picBase - 0x473c);
  tailTypeBits = retypedBits & 0xfffff9ff | 0x800;
  *(int *)(foldResultNode + 4) = 0;
  *(undefined ***)foldResultNode = &PTR_getLine_a7b7cf90;
  *(int *)(foldResultNode + 0xc) = 0;
  *(int *)(foldResultNode + 0x10) = 0;
  *(int *)(foldResultNode + 0x14) = 0;
  *(int *)(foldResultNode + 0x18) = 0;
  *(int *)(foldResultNode + 0x1c) = 0;
  *(int *)(foldResultNode + 0x20) = 0;
  *(undefined ***)(foldResultNode + 8) = tailTypeVtbl;
  *(int *)(foldResultNode + 0x24) = 0;
  *(int *)(foldResultNode + 0x28) = 0;
  newNodeBits = *(uint *)(foldResultNode + 0x2c);
  qualifierBits = retypedBits & 0xfe000000;
  *(uint *)(foldResultNode + 0x2c) = qualifierBits | newNodeBits & 0x1ffffff;
  retypedBits = retypedBits & 0x1f80000;
  *(uint *)(foldResultNode + 0x2c) = retypedBits | qualifierBits | newNodeBits & 0x7ffff;
  *(uint *)(foldResultNode + 0x2c) = retypedBits | qualifierBits | newNodeBits & 0x7ff | 0x800;
  *(uint *)(foldResultNode + 0x2c) = retypedBits | qualifierBits | newNodeBits & 0x3ff | 0x800;
  constUnionVtable = PTR_vtable_a7b7c0c8;
  *(uint *)(foldResultNode + 0x2c) = retypedBits | qualifierBits | newNodeBits & 0x1ff | 0x800;
  *(float **)(foldResultNode + 0x30) = resultFloats;
  *(undefined **)foldResultNode = constUnionVtable + 8;
LAB_97b951c0:
  tailTypeWord8 = 0;
  foldNodeVtable = *(int *)foldResultNode;
  tailTypeWord1 = tailTypeWord8;
  tailTypeWord2 = tailTypeWord8;
  tailTypeWord3 = tailTypeWord8;
  tailTypeWord4Overlay = tailTypeWord8;
  tailTypeWord5 = tailTypeWord8;
  tailTypeWord6 = tailTypeWord8;
  tailTypeWord7 = tailTypeWord8;
  r4Value = (*(code *)**(undefined4 **)rightOperand)(rightOperand);
  (**(code **)(foldNodeVtable + 4))(foldResultNode,r4Value);
  return foldResultNode;
}

/* TIntermediate__changeAggrToTempConst @ 0x97b95c0c (484 bytes) */
int TIntermediate__changeAggrToTempConst(this, intermAggregate, symbolTable, line)
  unsigned char * this;
  unsigned char * intermAggregate;
  unsigned char * symbolTable;
  int line;
{
  int nodeLine;
  int parseResult;
  int childConstUnion;
  int childSequence;
  int objectSize;
  unsigned char * poolAllocator;
  int *childTyped;
  int lineCopy;
  undefined4 constNode;
  undefined4 intermAggregateCopy;
  unsigned char * symbolTableCopy;
  undefined4 scratchR7;
  undefined4 scratchR8;
  int childVtable;
  unsigned char * constArray;
  undefined8 constArrayAlloc;
  undefined **typeTemp [9];
  uint typeTempBits;
  
  symbolTableCopy = symbolTable;
  lineCopy = line;
  (**(code **)(*(int *)intermAggregate + 0x38))(typeTemp,intermAggregate,symbolTable,line);
  if ((typeTempBits & 0x400) == 0) {
    objectSize = (int)(typeTempBits << 0xd | typeTempBits >> 0x13) >> 0x18;
  }
  else {
    objectSize = (int)(typeTempBits << 0xd | typeTempBits >> 0x13) >> 0x18;
    objectSize = objectSize * objectSize;
  }
  poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
  constArrayAlloc = TPoolAllocator__allocate(poolAllocator,objectSize << 2);
  constArray = (unsigned char *)((ulonglong)constArrayAlloc >> 0x20);
  typeTemp[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  childSequence = (**(code **)(*(int *)intermAggregate + 100))
                    (intermAggregate,(int)constArrayAlloc,symbolTableCopy,lineCopy,scratchR7,scratchR8,*(int *)intermAggregate);
  if (*(int *)(childSequence + 8) - *(int *)(childSequence + 4) >> 2 == 1) {
    childSequence = (**(code **)(*(int *)intermAggregate + 100))(intermAggregate);
    childVtable = *(int *)**(undefined4 **)(childSequence + 4);
    childTyped = (int *)(**(code **)(childVtable + 0x14))
                          ((int *)**(undefined4 **)(childSequence + 4),intermAggregateCopy,symbolTableCopy,lineCopy,scratchR7,scratchR8,childVtable);
    childConstUnion = (**(code **)(*childTyped + 0x18))(childTyped);
    if (childConstUnion != 0) {
      (**(code **)(*(int *)intermAggregate + 0x38))(typeTemp,intermAggregate);
      parseResult = ((int (*)())TIntermediate__parseConstTree)(this,line,(unsigned char *)intermAggregate,constArray,*(undefined4 *)(intermAggregate + 0x30),
                         symbolTable,typeTemp,1);
      goto LAB_97b95d90;
    }
  }
  (**(code **)(*(int *)intermAggregate + 0x38))(typeTemp,intermAggregate);
  parseResult = ((int (*)())TIntermediate__parseConstTree)(this,line,(unsigned char *)intermAggregate,constArray,*(undefined4 *)(intermAggregate + 0x30),
                     symbolTable,typeTemp,0);
LAB_97b95d90:
  typeTemp[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  if (parseResult != 0) {
    constArray = (unsigned char *)0x0;
  }
  (**(code **)(*(int *)intermAggregate + 0x38))(typeTemp,intermAggregate);
  nodeLine = (*(code *)**(undefined4 **)intermAggregate)(intermAggregate);
  constNode = TIntermediate__addConstantUnion(this,constArray,(unsigned char *)typeTemp,nodeLine);
  return constNode;
}

/* TIntermediate__copyConstUnion @ 0x97b95df0 (336 bytes) */
int TIntermediate__copyConstUnion(this, intermConstantUnion)
  unsigned char * this;
  unsigned char * intermConstantUnion;
{
  int byteOffset;
  int objectSize;
  unsigned char * poolAllocator;
  int newConstArray;
  unsigned char * resultNode;
  int componentIndex;
  int oldConstArray;
  undefined **typeTemp1 [9];
  uint typeTemp1Bits;
  undefined **typeTemp2 [2];
  unsigned char * typeTemp2Structure;
  uint typeTemp2Bits;
  undefined **typeTemp3 [14];
  
  oldConstArray = *(int *)(intermConstantUnion + 0x30);
  resultNode = (unsigned char *)0x0;
  if (oldConstArray != 0) {
    (**(code **)(*(int *)intermConstantUnion + 0x38))(typeTemp1);
    typeTemp1[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
    if ((typeTemp1Bits >> 0x13 & 0x3f) == 0xe) {
      (**(code **)(*(int *)intermConstantUnion + 0x38))(typeTemp2,intermConstantUnion);
      (**(code **)(*(int *)intermConstantUnion + 0x38))((unsigned char *)typeTemp3,intermConstantUnion);
      objectSize = TType__setStructSize((unsigned char *)typeTemp3,typeTemp2Structure);
      typeTemp3[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
    }
    else {
      (**(code **)(*(int *)intermConstantUnion + 0x38))(typeTemp2,intermConstantUnion);
      if ((typeTemp2Bits & 0x400) == 0) {
        objectSize = (int)(typeTemp2Bits << 0xd | typeTemp2Bits >> 0x13) >> 0x18;
      }
      else {
        objectSize = (int)(typeTemp2Bits << 0xd | typeTemp2Bits >> 0x13) >> 0x18;
        objectSize = objectSize * objectSize;
      }
    }
    typeTemp2[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    newConstArray = TPoolAllocator__allocate(poolAllocator,objectSize << 2);
    componentIndex = 0;
    if (0 < objectSize) {
      do {
        byteOffset = componentIndex * 4;
        componentIndex = componentIndex + 1;
        *(undefined4 *)(newConstArray + byteOffset) = *(undefined4 *)(oldConstArray + byteOffset);
        objectSize = objectSize + -1;
      } while (objectSize != 0);
    }
    *(int *)(intermConstantUnion + 0x30) = newConstArray;
    resultNode = intermConstantUnion;
  }
  return resultNode;
}

/* TIntermediate__promoteConstantUnion @ 0x97b95f40 (876 bytes) */
int TIntermediate__promoteConstantUnion(this, basicType, intermConstantUnion)
  unsigned char * this;
  uint basicType;
  int *intermConstantUnion;
{
  uint sourceLoc;
  uint srcValue;
  int line;
  undefined *atomicStore;
  int componentCount;
  undefined **refCountPtr;
  undefined *oldRefCount;
  unsigned char * poolAllocator;
  unsigned char * newConstArray;
  uint srcBasicType;
  undefined4 constNode;
  undefined4 basicTypeCopy;
  undefined4 basicTypeCopy2;
  undefined4 basicTypeCopy3;
  int *intermConstantUnionCopy;
  undefined4 scratchR6;
  uint sourceLine;
  undefined4 scratchR7;
  undefined4 scratchR8;
  undefined *scratchR9;
  int srcConstArray;
  char *errorText;
  int componentIndex;
  void *infoSink;
  char reservation;
  byte cr0Flags;
  double i2dBias;
  undefined **typeTempOverlay [4];
  unsigned char allocatorDummy [20];
  uint typeTempBits;
  undefined4 i2dHi;
  uint i2dLo;
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
  longlong d2iScratch;
  
  srcConstArray = intermConstantUnion[0xc];
  intermConstantUnionCopy = intermConstantUnion;
  (**(code **)(*intermConstantUnion + 0x38))(typeTempOverlay,intermConstantUnion,intermConstantUnion);
  if ((typeTempBits & 0x400) == 0) {
    componentCount = (int)(typeTempBits << 0xd | typeTempBits >> 0x13) >> 0x18;
  }
  else {
    componentCount = (int)(typeTempBits << 0xd | typeTempBits >> 0x13) >> 0x18;
    componentCount = componentCount * componentCount;
  }
  typeTempOverlay[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
  componentIndex = 0;
  newConstArray = (unsigned char *)TPoolAllocator__allocate(poolAllocator,componentCount << 2);
  if (0 < componentCount) {
    do {
      if (basicType == 2) {
        (**(code **)(*intermConstantUnion + 0x38))(typeTempOverlay,intermConstantUnion);
        srcBasicType = typeTempBits >> 0x13 & 0x3f;
        typeTempOverlay[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
        if (srcBasicType == 2) {
LAB_97b96230:
          srcValue = *(uint *)(componentIndex * 4 + srcConstArray);
        }
        else {
          if (2 < srcBasicType) {
            if (srcBasicType != 3) goto LAB_97b96174;
            goto LAB_97b96230;
          }
          if (srcBasicType != 1) {
LAB_97b96174:
            infoSink = *(void **)this;
            errorText = "Cannot promote";
            sourceLoc = (**(code **)*intermConstantUnion)(intermConstantUnion);
                    
            goto override_jmp_97b960f0_case_0;
          }
          srcValue = (uint)(int)*(float *)(componentIndex * 4 + srcConstArray);
          d2iScratch = (longlong)(int)srcValue;
        }
LAB_97b9625c:
        *(uint *)(newConstArray + componentIndex * 4) = srcValue;
      }
      else if ((int)basicType < 3) {
        if (basicType != 1) {
LAB_97b962b8:
          infoSink = *(void **)this;
          errorText = "Incorrect data type found";
          sourceLoc = (**(code **)*intermConstantUnion)(intermConstantUnion);
                    
override_jmp_97b960f0_case_0:
          __ZN13TInfoSinkBase6appendEPKc(infoSink,"INTERNAL ERROR: ");
          sourceLine = sourceLoc & 0xffff;
          cr0Flags = (sourceLine == 0) << 1;
          if (sourceLine == 0) {
            _sprintf((char *)&stackType,"%d:? ",(int)sourceLoc >> 0x10);
          }
          else {
            _sprintf((char *)&stackType,"%d:%d",(int)sourceLoc >> 0x10,sourceLine);
          }
          __ZNSsC1EPKcRKSaIcE(typeTempOverlay,(char *)&stackType,allocatorDummy);
          *(undefined *)((int)typeTempOverlay[0] + (int)typeTempOverlay[0][-3]) = *PTR__S_terminal_a7b7c0b8;
          __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)typeTempOverlay[0]);
          refCountPtr = typeTempOverlay[0] + -1;
          do {
            oldRefCount = *refCountPtr;
            if (reservation != '\0') {
              atomicStore = (undefined *)storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
              *refCountPtr = atomicStore;
              cr0Flags = 2;
            }
          } while (!(bool)(cr0Flags >> 1 & 1));
          if ((int)oldRefCount < 1) {
            __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(typeTempOverlay[0] + -3),allocatorDummy);
          }
          __ZN13TInfoSinkBase6appendEPKc(infoSink,": ");
          __ZN13TInfoSinkBase6appendEPKc(infoSink,errorText);
          __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
          return 0;
        }
        (**(code **)(*intermConstantUnion + 0x38))(typeTempOverlay,intermConstantUnion);
        srcBasicType = typeTempBits >> 0x13 & 0x3f;
        typeTempOverlay[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
        if (srcBasicType != 2) {
          if (srcBasicType < 3) {
            if (srcBasicType == 1) {
              *(undefined4 *)(newConstArray + componentIndex * 4) = *(undefined4 *)(srcConstArray + componentIndex * 4);
              goto LAB_97b9641c;
            }
          }
          else if (srcBasicType == 3) {
            i2dLo = *(uint *)(componentIndex * 4 + srcConstArray);
            i2dBias = 4503599627370496.0;
            goto LAB_97b96098;
          }
          infoSink = *(void **)this;
          errorText = "Cannot promote";
          sourceLoc = (**(code **)*intermConstantUnion)(intermConstantUnion,basicTypeCopy,intermConstantUnionCopy,scratchR6,scratchR7,scratchR8,scratchR9);
                    
          goto override_jmp_97b960f0_case_0;
        }
        i2dLo = *(uint *)(componentIndex * 4 + srcConstArray) ^ 0x80000000;
        i2dBias = 4503601774854144.0;
LAB_97b96098:
        scratchR9 = (undefined *)(componentIndex * 4);
        i2dHi = 0x43300000;
        *(float *)(newConstArray + (int)scratchR9) = (float)((double)CONCAT44(0x43300000,i2dLo) - i2dBias);
      }
      else {
        if (basicType != 3) goto LAB_97b962b8;
        (**(code **)(*intermConstantUnion + 0x38))(typeTempOverlay,intermConstantUnion);
        srcBasicType = typeTempBits >> 0x13 & 0x3f;
        typeTempOverlay[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
        if (srcBasicType != 2) {
          if (srcBasicType < 3) {
            if (srcBasicType == 1) {
              scratchR9 = &DAT_97c35f58;
              srcValue = (uint)(*(float *)(componentIndex * 4 + srcConstArray) != 0.0);
              goto LAB_97b9625c;
            }
          }
          else if (srcBasicType == 3) goto LAB_97b96230;
          infoSink = *(void **)this;
          errorText = "Cannot promote";
          sourceLoc = (**(code **)*intermConstantUnion)(intermConstantUnion,basicTypeCopy2,intermConstantUnionCopy,scratchR6,scratchR7,scratchR8,scratchR9);
                    
          goto override_jmp_97b960f0_case_0;
        }
        scratchR9 = (undefined *)(uint)(*(int *)(srcConstArray + componentIndex * 4) != 0);
        *(undefined **)(newConstArray + componentIndex * 4) = scratchR9;
      }
LAB_97b9641c:
      typeTempOverlay[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
      componentIndex = componentIndex + 1;
    } while (componentIndex < componentCount);
  }
  (**(code **)(*intermConstantUnion + 0x38))(typeTempOverlay,intermConstantUnion);
  stackTypeBits = (typeTempBits >> 9 & 1) << 9 |
             (typeTempBits >> 10 & 1) << 10 |
             typeTempBits & 0x7f800 |
             (basicType & 0x3f) << 0x13 | typeTempBits & 0xfe000000 | stackTypeBits & 0x1ff;
  stackTypeWord20 = 0;
  stackTypeArraySize = 0;
  stackTypeStructure = 0;
  stackTypeFieldName = 0;
  stackTypeTypeName = 0;
  stackTypeWord14 = 0;
  stackTypeStructureSize = 0;
  stackTypeWord1c = 0;
  stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  line = (**(code **)*intermConstantUnion)(intermConstantUnion,basicTypeCopy3,intermConstantUnionCopy,scratchR6,scratchR7,scratchR8,(undefined4 *)*intermConstantUnion);
  constNode = TIntermediate__addConstantUnion(this,newConstArray,(unsigned char *)&stackType,line);
  return constNode;
}

/* __ZN13TIntermediate15removeChildNodeER7TVectorIP11TIntermNodeER5TTypeRiRN9__gnu_cxx17__normal_iteratorIPS2_St6vectorIS2_14pool_allocatorIS2_EEEEP16TIntermAggregate @ 0x97b964e8 (824 bytes) */
int __ZN13TIntermediate15removeChildNodeER7TVectorIP11TIntermNodeER5TTypeRiRN9__gnu_cxx17__normal_iteratorIPS2_St6vectorIS2_14pool_allocatorIS2_EEEEP16TIntermAggregate(this, vector, type, indexPtr, __normal_iterator, intermAggregate)
  void *this;
  unsigned char * vector;
  unsigned char * type;
  int *indexPtr;
  unsigned char * __normal_iterator;
  unsigned char * intermAggregate;
{
  int adjustedIndex;
  int nodeVtable;
  int childVtable;
  int childConstUnion;
  int loopIndex;
  uint typeSizeBits;
  uint typeQualifierBits;
  uint typeBasicTypeBits;
  uint typeMatrixBit;
  uint oldTypeBits;
  int componentCount;
  int oldSequenceBegin;
  int aggregateSequence;
  int removeMatrixConstNodeResult;
  unsigned char * poolAllocator;
  undefined4 *constValueSlot;
  int *newConstantUnionNode;
  int *childConstantUnion;
  undefined4 aggregateLine;
  undefined4 vectorCopy;
  unsigned char * fwdR6;
  int childIndex;
  unsigned char * intermAggregateCopy;
  int oldSequenceEnd;
  undefined *constantUnionVtable;
  undefined8 newNodeAlloc;
  undefined **typeTemp [9];
  uint typeTempBits;
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
  undefined4 insertResult;
  int *insertNodeSlot [3];
  
  if (intermAggregate != (unsigned char *)0x0) {
    *(int *)__normal_iterator = *(int *)(vector + 4) + *indexPtr * 4;
    intermAggregateCopy = intermAggregate;
    aggregateSequence = (**(code **)(*(int *)intermAggregate + 100))
                      (intermAggregate,vector,type,indexPtr,__normal_iterator,intermAggregate,*(int *)intermAggregate);
    oldSequenceEnd = *(int *)(vector + 8);
    oldSequenceBegin = *(int *)(vector + 4);
    if (*(int *)(aggregateSequence + 8) - *(int *)(aggregateSequence + 4) >> 2 == 1) {
      childIndex = *indexPtr;
      fwdR6 = intermAggregate;
      removeMatrixConstNodeResult = ((int (*)())TIntermediate__removeMatrixConstNode)(this,vector,type,intermAggregate,childIndex);
      if (removeMatrixConstNodeResult == 0) {
        loopIndex = 0;
        constantUnionVtable = PTR_vtable_a7b7c0c8 + 8;
        while( true ) {
          (**(code **)(*(int *)intermAggregate + 0x38))(typeTemp,intermAggregate);
          if ((typeTempBits & 0x400) == 0) {
            componentCount = (int)(typeTempBits << 0xd | typeTempBits >> 0x13) >> 0x18;
          }
          else {
            componentCount = (int)(typeTempBits << 0xd | typeTempBits >> 0x13) >> 0x18;
            componentCount = componentCount * componentCount;
          }
          typeTemp[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
          if (componentCount <= loopIndex) break;
          poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
          constValueSlot = (undefined4 *)TPoolAllocator__allocate(poolAllocator,4);
          loopIndex = loopIndex + 1;
          childConstUnion = (**(code **)(*(int *)**(undefined4 **)(aggregateSequence + 4) + 0x18))
                            ((int *)**(undefined4 **)(aggregateSequence + 4));
          *constValueSlot = **(undefined4 **)(childConstUnion + 0x30);
          poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
          newNodeAlloc = TPoolAllocator__allocate(poolAllocator,0x34);
          newConstantUnionNode = (int *)((ulonglong)newNodeAlloc >> 0x20);
          childVtable = *(int *)**(undefined4 **)(aggregateSequence + 4);
          childConstantUnion = (int *)(**(code **)(childVtable + 0x18))
                                ((int *)**(undefined4 **)(aggregateSequence + 4),(int)newNodeAlloc,type,fwdR6,childIndex,intermAggregateCopy,
                                 childVtable);
          (**(code **)(*childConstantUnion + 0x38))(&stackType,childConstantUnion);
          *newConstantUnionNode = (int)&PTR_getLine_a7b7cf90;
          newConstantUnionNode[1] = 0;
          newConstantUnionNode[3] = stackTypeArraySize;
          newConstantUnionNode[4] = stackTypeStructure;
          newConstantUnionNode[5] = stackTypeFieldName;
          newConstantUnionNode[6] = stackTypeTypeName;
          newConstantUnionNode[7] = stackTypeWord14;
          newConstantUnionNode[8] = stackTypeStructureSize;
          newConstantUnionNode[2] = (int)&PTR___ZN5TTypeD1Ev_a7b7cff8;
          newConstantUnionNode[9] = stackTypeWord1c;
          newConstantUnionNode[10] = stackTypeWord20;
          oldTypeBits = newConstantUnionNode[0xb];
          typeQualifierBits = stackTypeBits & 0xfe000000;
          newConstantUnionNode[0xb] = typeQualifierBits | oldTypeBits & 0x1ffffff;
          typeBasicTypeBits = (stackTypeBits >> 0x13 & 0x3f) << 0x13;
          newConstantUnionNode[0xb] = typeBasicTypeBits | typeQualifierBits | oldTypeBits & 0x7ffff;
          typeSizeBits = stackTypeBits & 0x7f800;
          newConstantUnionNode[0xb] = typeSizeBits | typeBasicTypeBits | typeQualifierBits | oldTypeBits & 0x7ff;
          typeMatrixBit = (stackTypeBits >> 10 & 1) << 10;
          newConstantUnionNode[0xb] = typeMatrixBit | typeSizeBits | typeBasicTypeBits | typeQualifierBits | oldTypeBits & 0x3ff;
          newConstantUnionNode[0xb] = (stackTypeBits >> 9 & 1) << 9 | typeMatrixBit | typeSizeBits | typeBasicTypeBits | typeQualifierBits | oldTypeBits & 0x1ff;
          newConstantUnionNode[0xc] = (int)constValueSlot;
          *newConstantUnionNode = (int)constantUnionVtable;
          stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
          nodeVtable = *newConstantUnionNode;
          aggregateLine = (*(code *)**(undefined4 **)intermAggregate)(intermAggregate,vectorCopy,type,fwdR6,childIndex,intermAggregateCopy,newConstantUnionNode + 2);
          (**(code **)(nodeVtable + 4))(newConstantUnionNode,aggregateLine);
          type = (unsigned char *)(*(int *)(vector + 4) + *indexPtr * 4);
          fwdR6 = (unsigned char *)insertNodeSlot;
          *(unsigned char **)__normal_iterator = type;
          insertNodeSlot[0] = newConstantUnionNode;
          std__vector_TIntermNode__pool_allocator_TIntermNode_____insert
                    (&insertResult,vector,type,fwdR6);
        }
      }
    }
    else {
      std__vector_TIntermNode__pool_allocator_TIntermNode______M_range_insert___gnu_cxx____normal_iterator_TIntermNode___std__vector_TIntermNode__pool_allocator_TIntermNode_____
                (vector,*(undefined4 *)__normal_iterator,*(int *)(aggregateSequence + 4),*(int *)(aggregateSequence + 8));
    }
    adjustedIndex = (*indexPtr + (*(int *)(vector + 8) - *(int *)(vector + 4) >> 2)) -
            (oldSequenceEnd - oldSequenceBegin >> 2);
    *indexPtr = adjustedIndex;
    adjustedIndex = *(int *)(vector + 4) + adjustedIndex * 4;
    *(int *)__normal_iterator = adjustedIndex;
    std__vector_TIntermNode__pool_allocator_TIntermNode_____erase(&insertResult,vector,adjustedIndex);
    *(undefined4 *)__normal_iterator = insertResult;
    *indexPtr = *indexPtr + -1;
    *(int *)__normal_iterator = *(int *)__normal_iterator + -4;
  }
  return;
}

/* __ZN13TIntermediate15removeChildNodeEP12TIntermTypedP5TTypeP16TIntermAggregate @ 0x97b96820 (496 bytes) */
int __ZN13TIntermediate15removeChildNodeEP12TIntermTypedP5TTypeP16TIntermAggregate(this, intermTyped, type, intermAggregate)
  void *this;
  unsigned char * intermTyped;
  unsigned char * type;
  unsigned char * intermAggregate;
{
  int elementIndex;
  int checkSequence;
  int aggregateSequence;
  int removeMatrixConstNodeResult;
  undefined4 *sequenceFinish;
  int prevFinish;
  int typeObjectSize;
  int *aggregateNode;
  unsigned char * childSequence;
  int firstChildVtable;
  int elementSequence;
  undefined4 intermTypedCopy;
  unsigned char * typeCopy;
  unsigned char * intermAggregateCopy;
  undefined4 scratchR7;
  undefined4 scratchR8;
  undefined1 eraseResultSlot [20];
  
  typeCopy = type;
  intermAggregateCopy = intermAggregate;
  typeObjectSize = (**(code **)(*(int *)type + 0x30))(type,intermTyped,type,intermAggregate);
  if (typeObjectSize == 1) {
    aggregateSequence = (**(code **)(*(int *)intermAggregate + 100))(intermAggregate);
    firstChildVtable = *(int *)**(undefined4 **)(aggregateSequence + 4);
    intermTyped = (unsigned char *)
              (**(code **)(firstChildVtable + 0x14))
                        ((int *)**(undefined4 **)(aggregateSequence + 4),intermTypedCopy,typeCopy,intermAggregateCopy,scratchR7,scratchR8,firstChildVtable);
  }
  else {
    typeObjectSize = (**(code **)(*(int *)type + 0x30))(type);
    aggregateNode = (int *)(**(code **)(*(int *)intermTyped + 0x1c))(intermTyped);
    childSequence = (unsigned char *)(**(code **)(*aggregateNode + 100))(aggregateNode);
    checkSequence = (**(code **)(*(int *)intermAggregate + 100))(intermAggregate);
    if (*(int *)(checkSequence + 8) - *(int *)(checkSequence + 4) >> 2 == 1) {
      removeMatrixConstNodeResult = ((int (*)())TIntermediate__removeMatrixConstNode)(this,(unsigned char *)childSequence,type,intermAggregate,1);
      if (removeMatrixConstNodeResult == 0) {
        aggregateSequence = (**(code **)(*(int *)intermAggregate + 100))(intermAggregate);
        sequenceFinish = *(undefined4 **)(childSequence + 8);
        if (sequenceFinish == *(undefined4 **)(childSequence + 0xc)) {
          std__vector_TIntermNode__pool_allocator_TIntermNode______M_insert_aux
                    (childSequence,sequenceFinish,*(undefined4 **)(aggregateSequence + 4));
        }
        else {
          elementIndex = 0;
          if (sequenceFinish != (undefined4 *)0x0) {
            *sequenceFinish = **(undefined4 **)(aggregateSequence + 4);
            elementIndex = *(int *)(childSequence + 8);
          }
          *(int *)(childSequence + 8) = elementIndex + 4;
        }
      }
    }
    else {
      elementIndex = 0;
      if (0 < typeObjectSize) {
        do {
          elementSequence = (**(code **)(*(int *)intermAggregate + 100))(intermAggregate);
          sequenceFinish = *(undefined4 **)(childSequence + 8);
          if (sequenceFinish == *(undefined4 **)(childSequence + 0xc)) {
            std__vector_TIntermNode__pool_allocator_TIntermNode______M_insert_aux
                      (childSequence,sequenceFinish,*(int *)(elementSequence + 4) + elementIndex * 4);
          }
          else {
            prevFinish = 0;
            if (sequenceFinish != (undefined4 *)0x0) {
              *sequenceFinish = *(undefined4 *)(*(int *)(elementSequence + 4) + elementIndex * 4);
              prevFinish = *(int *)(childSequence + 8);
            }
            *(int *)(childSequence + 8) = prevFinish + 4;
          }
          elementIndex = elementIndex + 1;
        } while (elementIndex < typeObjectSize);
      }
    }
    std__vector_TIntermNode__pool_allocator_TIntermNode_____erase
              (eraseResultSlot,childSequence,*(undefined4 *)(childSequence + 4));
  }
  return intermTyped;
}

/* TIntermediate__removeMatrixConstNode @ 0x97b96a10 (776 bytes) */
int TIntermediate__removeMatrixConstNode(this, vector, type, intermAggregate, index)
  unsigned char * this;
  unsigned char * vector;
  unsigned char * type;
  unsigned char * intermAggregate;
  int index;
{
  int nodeVtable;
  int typeBasicType;
  int childVtable;
  int diagonalStride;
  uint typeSizeBits;
  uint typeQualifierBits;
  uint typeBasicTypeBits;
  uint typeMatrixBit;
  uint oldTypeBits;
  int componentCount;
  undefined4 result;
  int aggregateSequence;
  unsigned char * poolAllocator;
  undefined4 *constValueSlot;
  int *newConstantUnionNode;
  int *childNode;
  undefined4 vectorCopy;
  undefined4 vectorCopy2;
  unsigned char * fwdR5;
  unsigned char * fwdR6;
  int indexCopy;
  undefined4 scratchR8;
  undefined *constantUnionVtable;
  int elementIndex;
  undefined8 newNodeAlloc;
  undefined **typeTemp [9];
  uint typeTempBits;
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
  undefined1 insertResultSlot [4];
  int *insertNodeSlot [3];
  
  result = 0;
  if (intermAggregate != (unsigned char *)0x0) {
    fwdR5 = type;
    fwdR6 = intermAggregate;
    indexCopy = index;
    aggregateSequence = (**(code **)(*(int *)intermAggregate + 100))(intermAggregate);
    result = 0;
    if (*(int *)(intermAggregate + 0x30) - 0x72U < 3) {
      elementIndex = 0;
      constantUnionVtable = PTR_vtable_a7b7c0c8 + 8;
      while( true ) {
        (**(code **)(*(int *)intermAggregate + 0x38))(typeTemp,intermAggregate);
        if ((typeTempBits & 0x400) == 0) {
          componentCount = (int)(typeTempBits << 0xd | typeTempBits >> 0x13) >> 0x18;
        }
        else {
          componentCount = (int)(typeTempBits << 0xd | typeTempBits >> 0x13) >> 0x18;
          componentCount = componentCount * componentCount;
        }
        typeTemp[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
        result = 1;
        if (componentCount <= elementIndex) break;
        poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
        constValueSlot = (undefined4 *)TPoolAllocator__allocate(poolAllocator,4);
        (**(code **)(*(int *)intermAggregate + 0x38))(&stackType,intermAggregate);
        stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
        diagonalStride = ((int)(stackTypeBits << 0xd | stackTypeBits >> 0x13) >> 0x18) + 1;
        if (elementIndex == (elementIndex / diagonalStride) * diagonalStride) {
          childVtable = *(int *)**(undefined4 **)(aggregateSequence + 4);
          childVtable = (**(code **)(childVtable + 0x18))
                            ((int *)**(undefined4 **)(aggregateSequence + 4),vectorCopy,fwdR5,fwdR6,indexCopy,scratchR8,childVtable);
          *constValueSlot = **(undefined4 **)(childVtable + 0x30);
        }
        else {
          typeBasicType = (**(code **)(*(int *)type + 0x20))(type);
          if (typeBasicType == 2) {
LAB_97b96b5c:
            *constValueSlot = 0;
          }
          else if (typeBasicType < 3) {
            if (typeBasicType == 1) {
              *constValueSlot = 0;
            }
          }
          else if (typeBasicType == 3) goto LAB_97b96b5c;
        }
        poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
        newNodeAlloc = TPoolAllocator__allocate(poolAllocator,0x34);
        newConstantUnionNode = (int *)((ulonglong)newNodeAlloc >> 0x20);
        childNode = (int *)**(undefined4 **)(aggregateSequence + 4);
        childNode = (int *)(**(code **)(*childNode + 0x18))
                                   (childNode,(int)newNodeAlloc,fwdR5,fwdR6,indexCopy,scratchR8,*(undefined4 **)(aggregateSequence + 4));
        (**(code **)(*childNode + 0x38))(&stackType,childNode);
        *newConstantUnionNode = (int)&PTR_getLine_a7b7cf90;
        newConstantUnionNode[1] = 0;
        newConstantUnionNode[3] = stackTypeArraySize;
        newConstantUnionNode[4] = stackTypeStructure;
        newConstantUnionNode[5] = stackTypeFieldName;
        newConstantUnionNode[6] = stackTypeTypeName;
        newConstantUnionNode[7] = stackTypeWord14;
        newConstantUnionNode[8] = stackTypeStructureSize;
        newConstantUnionNode[2] = (int)&PTR___ZN5TTypeD1Ev_a7b7cff8;
        newConstantUnionNode[9] = stackTypeWord1c;
        newConstantUnionNode[10] = stackTypeWord20;
        oldTypeBits = newConstantUnionNode[0xb];
        typeQualifierBits = stackTypeBits & 0xfe000000;
        newConstantUnionNode[0xb] = typeQualifierBits | oldTypeBits & 0x1ffffff;
        typeBasicTypeBits = (stackTypeBits >> 0x13 & 0x3f) << 0x13;
        newConstantUnionNode[0xb] = typeBasicTypeBits | typeQualifierBits | oldTypeBits & 0x7ffff;
        typeSizeBits = stackTypeBits & 0x7f800;
        newConstantUnionNode[0xb] = typeSizeBits | typeBasicTypeBits | typeQualifierBits | oldTypeBits & 0x7ff;
        typeMatrixBit = (stackTypeBits >> 10 & 1) << 10;
        newConstantUnionNode[0xb] = typeMatrixBit | typeSizeBits | typeBasicTypeBits | typeQualifierBits | oldTypeBits & 0x3ff;
        newConstantUnionNode[0xb] = (stackTypeBits >> 9 & 1) << 9 | typeMatrixBit | typeSizeBits | typeBasicTypeBits | typeQualifierBits | oldTypeBits & 0x1ff;
        newConstantUnionNode[0xc] = (int)constValueSlot;
        *newConstantUnionNode = (int)constantUnionVtable;
        stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
        nodeVtable = *newConstantUnionNode;
        result = (*(code *)**(undefined4 **)intermAggregate)(intermAggregate,vectorCopy2,fwdR5,fwdR6,indexCopy,scratchR8,newConstantUnionNode + 2);
        (**(code **)(nodeVtable + 4))(newConstantUnionNode,result);
        fwdR5 = (unsigned char *)(*(int *)(vector + 4) + index * 4 + elementIndex * 4);
        fwdR6 = (unsigned char *)insertNodeSlot;
        elementIndex = elementIndex + 1;
        insertNodeSlot[0] = newConstantUnionNode;
        std__vector_TIntermNode__pool_allocator_TIntermNode_____insert(insertResultSlot,vector,fwdR5,fwdR6);
      }
    }
  }
  return result;
}

/* TIntermAggregate__addToPragmaTable @ 0x97b96d18 (184 bytes) */
int TIntermAggregate__addToPragmaTable(this, map)
  unsigned char * this;
  unsigned char * map;
{
  unsigned char * pragmaTable;
  unsigned char * poolAllocator;
  int *headerNode;
  int existingPragmaTable;
  
  existingPragmaTable = *(int *)(this + 0x68);
  if (existingPragmaTable != 0) {
    ___eprintf("%s:%u: failed assertion `%s\'\n",
               "/SourceCache/OpenGL/OpenGL-4.7.14/GLProgrammability/glslang/MachineIndependent/Intermediate.cpp"
               ,0x865,"!pragmaTable");
  }
  pragmaTable = operator_new(0x10);
  poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
  *(unsigned char **)pragmaTable = poolAllocator;
  *(int *)(pragmaTable + 4) = existingPragmaTable;
  headerNode = (int *)TPoolAllocator__allocate(poolAllocator,0x20);
  *(int *)(pragmaTable + 8) = existingPragmaTable;
  *(int **)(pragmaTable + 4) = headerNode;
  *headerNode = existingPragmaTable;
  *(int *)(*(int *)(pragmaTable + 4) + 4) = existingPragmaTable;
  *(int *)(*(int *)(pragmaTable + 4) + 8) = *(int *)(pragmaTable + 4);
  *(int *)(*(int *)(pragmaTable + 4) + 0xc) = *(int *)(pragmaTable + 4);
  *(unsigned char
    **)(this + 0x68) = pragmaTable;
  return std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string_____operator_(pragmaTable,(unsigned char *)map);
}

/* TType__getCompleteString @ 0x97b96dd0 (276 bytes) */
int TType__getCompleteString(result, type)
  void *result;
  int type;
{
  int sprintfResult;
  undefined4 basicString;
  undefined4 qualifierString;
  int nominalSize;
  uint typeBits;
  char *writeCursor;
  char descriptionBuf [112];
  undefined4 allocatorArg [4];
  
  typeBits = *(uint *)(type + 0x24);
  writeCursor = descriptionBuf;
  if (1 < typeBits >> 0x19) {
    qualifierString = getQualifierString(typeBits >> 0x19);
    sprintfResult = _sprintf(writeCursor,"%s ",qualifierString);
    typeBits = *(uint *)(type + 0x24);
    writeCursor = writeCursor + sprintfResult;
  }
  if ((typeBits & 0x200) != 0) {
    sprintfResult = _sprintf(writeCursor,"array of ");
    typeBits = *(uint *)(type + 0x24);
    writeCursor = writeCursor + sprintfResult;
  }
  if ((typeBits & 0x400) == 0) {
    nominalSize = (int)(typeBits << 0xd | typeBits >> 0x13) >> 0x18;
    if (nominalSize < 2) goto LAB_97b96e98;
    sprintfResult = _sprintf(writeCursor,"%d-component vector of ",nominalSize);
  }
  else {
    nominalSize = (int)(typeBits << 0xd | typeBits >> 0x13) >> 0x18;
    sprintfResult = _sprintf(writeCursor,"%dX%d matrix of ",nominalSize,nominalSize);
  }
  typeBits = *(uint *)(type + 0x24);
  writeCursor = writeCursor + sprintfResult;
LAB_97b96e98:
  basicString = TType__getBasicString(typeBits >> 0x13 & 0x3f);
  _sprintf(writeCursor,"%s",basicString);
  allocatorArg[0] = GetGlobalPoolAllocator();
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
            (result,descriptionBuf,(unsigned char *)allocatorArg);
  return result;
}

/* OutputTreeText @ 0x97b96ee4 (240 bytes) */
int OutputTreeText(infoSink, intermNode, depth)
  unsigned char * infoSink;
  unsigned char * intermNode;
  int depth;
{
  int atomicStore;
  int *refCountPtr;
  int oldRefCount;
  uint sourceLoc;
  uint sourceLine;
  char reservation;
  byte cr0Flags;
  int locString [4];
  char locTextBuf [64];
  unsigned char allocatorDummy [28];
  
  sourceLoc = (*(code *)**(undefined4 **)intermNode)(intermNode,intermNode,depth);
  sourceLine = sourceLoc & 0xffff;
  cr0Flags = (sourceLine == 0) << 1;
  if (sourceLine == 0) {
    _sprintf(locTextBuf,"%d:? ",(int)sourceLoc >> 0x10);
  }
  else {
    _sprintf(locTextBuf,"%d:%d",(int)sourceLoc >> 0x10,sourceLine);
  }
  __ZNSsC1EPKcRKSaIcE(locString,locTextBuf,allocatorDummy);
  __ZN13TInfoSinkBase6appendERKSs(infoSink + 8,(unsigned char *)locString);
  refCountPtr = (int *)(locString[0] + -4);
  do {
    oldRefCount = *refCountPtr;
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
      *refCountPtr = atomicStore;
      cr0Flags = 2;
    }
  } while (!(bool)(cr0Flags >> 1 & 1));
  if (oldRefCount < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(locString[0] + -0xc),locTextBuf);
  }
  if (0 < depth) {
    do {
      __ZN13TInfoSinkBase6appendEPKc(infoSink + 8,"  ");
      depth = depth + -1;
    } while (depth != 0);
  }
  return;
}

/* OutputSymbol @ 0x97b96fd4 (268 bytes) */
int OutputSymbol(intermSymbol, intermTraverser, scratchR5, scratchR6, scratchR7, scratchR8)
  unsigned char * intermSymbol;
  unsigned char * intermTraverser;
  undefined4 scratchR5;
  undefined4 scratchR6;
  undefined4 scratchR7;
  undefined4 scratchR8;
{
  int oldRefCount;
  int atomicStore;
  undefined1 *stringTerminal;
  int *refCountPtr;
  int typeCharsCopy;
  int symbolName;
  undefined4 symbolId;
  undefined4 intermTraverserCopy;
  undefined4 intermTraverserCopy2;
  int traverserDepth;
  int symbolNameChars;
  undefined4 nameChars;
  char reservation;
  byte cr0Reg;
  char symbolTextBuf [112];
  undefined4 typeString;
  int typeStringChars;
  undefined4 destroyAllocatorArg [7];
  
  traverserDepth = *(int *)(intermTraverser + 0x20);
  ((int (*)())OutputTreeText)(*(unsigned char **)(intermTraverser + 0x30),(unsigned char *)intermSymbol,traverserDepth);
  ((int (*)())TType__getCompleteString)(&typeString,intermSymbol + 8);
  typeCharsCopy = typeStringChars;
  stringTerminal = DAT_a7b7b9e0;
  *(undefined1 *)(typeStringChars + *(int *)(typeStringChars + -0xc)) = *DAT_a7b7b9e0;
  symbolName = (**(code **)(*(int *)intermSymbol + 0x60))(intermSymbol,intermTraverserCopy,traverserDepth,scratchR6,scratchR7,scratchR8,typeStringChars);
  symbolNameChars = *(int *)(symbolName + 4);
  *(undefined1 *)(symbolNameChars + *(int *)(symbolNameChars + -0xc)) = *stringTerminal;
  nameChars = *(undefined4 *)(symbolName + 4);
  symbolId = (**(code **)(*(int *)intermSymbol + 0x5c))(intermSymbol,intermTraverserCopy2,traverserDepth,scratchR6,scratchR7,scratchR8,symbolNameChars,symbolName);
  _sprintf(symbolTextBuf,"\'%s\' (%s) id: %d\n",nameChars,typeCharsCopy,symbolId);
  refCountPtr = (int *)(typeStringChars + -4);
  destroyAllocatorArg[0] = typeString;
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
              ((unsigned char *)(typeStringChars + -0xc),destroyAllocatorArg);
  }
  return __ZN13TInfoSinkBase6appendEPKc((void *)(*(int *)(intermTraverser + 0x30) + 8),symbolTextBuf);
}

/* OutputBinary @ 0x97b970e0 (248 bytes) */
int OutputBinary(preVisit, intermBinary, intermTraverser)
  int preVisit;
  unsigned char * intermBinary;
  unsigned char * intermTraverser;
{
  unsigned char *debugSink;
  int atomicStore;
  int *refCountPtr;
  int oldRefCount;
  char *opName;
  unsigned char *infoSink;
  char reservation;
  byte cr0Reg;
  undefined4 typeString;
  int typeStringChars;
  undefined4 destroyAllocatorArg [5];
  
  infoSink = *(unsigned char **)(intermTraverser + 0x30);
  ((int (*)())OutputTreeText)(infoSink,(unsigned char *)intermBinary,*(int *)(intermTraverser + 0x20));
  if (*(int *)(intermBinary + 0x30) == 0x15) {
    opName = "Multiply";
  }
  else {
    opName = *(char **)(PTR__operatorStrings_a7b7c0b0 + *(int *)(intermBinary + 0x30) * 4);
  }
  debugSink = infoSink + 8;
  __ZN13TInfoSinkBase6appendEPKc(debugSink,opName);
  __ZN13TInfoSinkBase6appendEPKc(debugSink," (");
  ((int (*)())TType__getCompleteString)(&typeString,intermBinary + 8);
  __ZN13TInfoSinkBase6appendERKSbIcSt11char_traitsIcE14pool_allocatorIcEE
            (debugSink,(unsigned char *)&typeString);
  __ZN13TInfoSinkBase6appendEPKc(debugSink,")");
  refCountPtr = (int *)(typeStringChars + -4);
  destroyAllocatorArg[0] = typeString;
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
              ((unsigned char *)(typeStringChars + -0xc),destroyAllocatorArg);
  }
  __ZN13TInfoSinkBase6appendEPKc(debugSink,"\n");
  return 1;
}

/* OutputUnary @ 0x97b971d8 (224 bytes) */
int OutputUnary(preVisit, intermUnary, intermTraverser)
  int preVisit;
  unsigned char * intermUnary;
  unsigned char * intermTraverser;
{
  int atomicStore;
  int *refCountPtr;
  int oldRefCount;
  unsigned char * this;
  char reservation;
  byte cr0Reg;
  undefined4 typeString;
  int typeStringChars;
  undefined4 destroyAllocatorArg [4];
  
  this = *(unsigned char **)(intermTraverser + 0x30) + 8;
  ((int (*)())OutputTreeText)(*(unsigned char **)(intermTraverser + 0x30),(unsigned char *)intermUnary,*(int *)(intermTraverser + 0x20));
  __ZN13TInfoSinkBase6appendEPKc
            (this,*(char **)(PTR__operatorStrings_a7b7c0b0 + *(int *)(intermUnary + 0x30) * 4));
  __ZN13TInfoSinkBase6appendEPKc(this," (");
  ((int (*)())TType__getCompleteString)(&typeString,intermUnary + 8);
  __ZN13TInfoSinkBase6appendERKSbIcSt11char_traitsIcE14pool_allocatorIcEE(this,(unsigned char *)&typeString);
  __ZN13TInfoSinkBase6appendEPKc(this,")");
  refCountPtr = (int *)(typeStringChars + -4);
  destroyAllocatorArg[0] = typeString;
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
              ((unsigned char *)(typeStringChars + -0xc),destroyAllocatorArg);
  }
  __ZN13TInfoSinkBase6appendEPKc(this,"\n");
  return 1;
}

/* OutputAggregate @ 0x97b972b8 (80 bytes) */
int OutputAggregate(preVisit, intermAggregate, intermTraverser)
  int preVisit;
  unsigned char * intermAggregate;
  unsigned char * intermTraverser;
{
  int atomicStore;
  int *refCountPtr;
  int oldRefCount;
  unsigned char * infoSink;
  unsigned char * debugSink;
  char reservation;
  byte cr0Reg;
  undefined4 typeString;
  int typeStringChars;
  undefined4 destroyAllocatorArg [5];
  
  infoSink = *(unsigned char **)(intermTraverser + 0x30);
  if (*(int *)(intermAggregate + 0x30) == 0) {
                    
    __ZN13TInfoSinkBase6appendEPKc(infoSink + 8,"ERROR: ");
    __ZN13TInfoSinkBase6appendEPKc(infoSink + 8,"node is still EOpNull!");
  }
  else {
    ((int (*)())OutputTreeText)(infoSink,(unsigned char *)intermAggregate,*(int *)(intermTraverser + 0x20));
    debugSink = infoSink + 8;
    __ZN13TInfoSinkBase6appendEPKc
              (debugSink,*(char **)(PTR__operatorStrings_a7b7c0b0 + *(int *)(intermAggregate + 0x30) * 4));
    if ((*(int *)(intermAggregate + 0x30) != 1) && (*(int *)(intermAggregate + 0x30) != 4)) {
      __ZN13TInfoSinkBase6appendEPKc(debugSink," (");
      ((int (*)())TType__getCompleteString)(&typeString,intermAggregate + 8);
      __ZN13TInfoSinkBase6appendERKSbIcSt11char_traitsIcE14pool_allocatorIcEE
                (debugSink,(unsigned char *)&typeString);
      __ZN13TInfoSinkBase6appendEPKc(debugSink,")");
      refCountPtr = (int *)(typeStringChars + -4);
      destroyAllocatorArg[0] = typeString;
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
                  ((unsigned char *)(typeStringChars + -0xc),destroyAllocatorArg);
      }
    }
  }
  __ZN13TInfoSinkBase6appendEPKc(infoSink + 8,"\n");
  return 1;
}

/* OutputSelection @ 0x97b97450 (516 bytes) */
int OutputSelection(preVisit, intermSelection, intermTraverser)
  int preVisit;
  unsigned char * intermSelection;
  unsigned char * intermTraverser;
{
  int *falseBlock;
  int *trueBlock;
  int falseBlockTest;
  int trueBlockTest;
  int *refCountPtr;
  int oldRefCount;
  int atomicStore;
  int *condition;
  int depth;
  unsigned char * this;
  char reservation;
  byte cr0Reg;
  undefined4 typeString;
  int typeStringChars;
  undefined4 destroyAllocatorArg [4];
  
  this = *(unsigned char **)(intermTraverser + 0x30) + 8;
  ((int (*)())OutputTreeText)(*(unsigned char **)(intermTraverser + 0x30),(unsigned char *)intermSelection,*(int *)(intermTraverser + 0x20));
  __ZN13TInfoSinkBase6appendEPKc(this,"Test condition and select");
  __ZN13TInfoSinkBase6appendEPKc(this," (");
  ((int (*)())TType__getCompleteString)(&typeString,intermSelection + 8);
  __ZN13TInfoSinkBase6appendERKSbIcSt11char_traitsIcE14pool_allocatorIcEE(this,(unsigned char *)&typeString);
  __ZN13TInfoSinkBase6appendEPKc(this,")\n");
  refCountPtr = (int *)(typeStringChars + -4);
  destroyAllocatorArg[0] = typeString;
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
              ((unsigned char *)(typeStringChars + -0xc),destroyAllocatorArg);
  }
  depth = *(int *)(intermTraverser + 0x20);
  *(int *)(intermTraverser + 0x20) = depth + 1;
  ((int (*)())OutputTreeText)(*(unsigned char **)(intermTraverser + 0x30),(unsigned char *)intermSelection,depth + 1);
  __ZN13TInfoSinkBase6appendEPKc(this,"Condition\n");
  condition = (int *)(**(code **)(*(int *)intermSelection + 0x5c))(intermSelection);
  (**(code **)(*condition + 8))(condition,intermTraverser);
  ((int (*)())OutputTreeText)(*(unsigned char **)(intermTraverser + 0x30),(unsigned char *)intermSelection,*(int *)(intermTraverser + 0x20));
  trueBlockTest = (**(code **)(*(int *)intermSelection + 0x60))(intermSelection);
  if (trueBlockTest == 0) {
    __ZN13TInfoSinkBase6appendEPKc(this,"true case is null\n");
  }
  else {
    __ZN13TInfoSinkBase6appendEPKc(this,"true case\n");
    trueBlock = (int *)(**(code **)(*(int *)intermSelection + 0x60))(intermSelection);
    (**(code **)(*trueBlock + 8))(trueBlock,intermTraverser);
  }
  falseBlockTest = (**(code **)(*(int *)intermSelection + 100))(intermSelection);
  if (falseBlockTest != 0) {
    ((int (*)())OutputTreeText)(*(unsigned char **)(intermTraverser + 0x30),(unsigned char *)intermSelection,*(int *)(intermTraverser + 0x20));
    __ZN13TInfoSinkBase6appendEPKc(this,"false case\n");
    falseBlock = (int *)(**(code **)(*(int *)intermSelection + 100))(intermSelection);
    (**(code **)(*falseBlock + 8))(falseBlock,intermTraverser);
  }
  *(int *)(intermTraverser + 0x20) = *(int *)(intermTraverser + 0x20) + -1;
  return 0;
}

/* OutputConstantUnion @ 0x97b97654 (628 bytes) */
int OutputConstantUnion(intermConstantUnion, intermTraverser)
  unsigned char * intermConstantUnion;
  unsigned char * intermTraverser;
{
  uint sourceLoc;
  undefined *atomicStore;
  int componentCount;
  uint componentBasicType;
  undefined **refCountPtr;
  undefined *oldRefCount;
  undefined4 getTypeResult;
  undefined4 intermTraverserCopy;
  char *boolText;
  undefined ***appendText;
  uint sourceLine;
  int componentIndex;
  unsigned char * lineSink;
  unsigned char * infoSink;
  char reservation;
  byte cr0Flags;
  double scratchF3;
  double scratchF4;
  double scratchF5;
  double scratchF6;
  double scratchF7;
  double scratchF8;
  double leftoverStackArg0;
  double leftoverStackArg1;
  double leftoverStackArg2;
  double leftoverStackArg3;
  double leftoverStackArg4;
  undefined **typeTemp1Overlay [4];
  char locTextBuf [20];
  uint typeTemp1Bits;
  undefined **typeTemp2 [6];
  int typeTemp2Structure;
  unsigned char allocatorDummy [4];
  uint typeTemp2Bits;
  char floatTextBuf [312];
  
  infoSink = *(unsigned char **)(intermTraverser + 0x30);
  (**(code **)(*(int *)intermConstantUnion + 0x38))(typeTemp1Overlay,intermConstantUnion);
  typeTemp1Overlay[0] = &PTR___ZN5TTypeD1Ev_a7b7d080;
  if ((typeTemp1Bits >> 0x13 & 0x3f) == 0xe) {
    (**(code **)(*(int *)intermConstantUnion + 0x38))(typeTemp2,intermConstantUnion);
    componentCount = typeTemp2Structure;
  }
  else {
    (**(code **)(*(int *)intermConstantUnion + 0x38))(typeTemp2,intermConstantUnion);
    if ((typeTemp2Bits & 0x400) == 0) {
      componentCount = (int)(typeTemp2Bits << 0xd | typeTemp2Bits >> 0x13) >> 0x18;
    }
    else {
      componentCount = (int)(typeTemp2Bits << 0xd | typeTemp2Bits >> 0x13) >> 0x18;
      componentCount = componentCount * componentCount;
    }
  }
  typeTemp2[0] = &PTR___ZN5TTypeD1Ev_a7b7d080;
  componentIndex = 0;
  if (0 < componentCount) {
    do {
      ((int (*)())OutputTreeText)(infoSink,(unsigned char *)intermConstantUnion,*(int *)(intermTraverser + 0x20));
      getTypeResult = (**(code **)(*(int *)intermConstantUnion + 0x38))(typeTemp1Overlay,intermConstantUnion);
      componentBasicType = typeTemp1Bits >> 0x13 & 0x3f;
      typeTemp1Overlay[0] = &PTR___ZN5TTypeD1Ev_a7b7d080;
      if (componentBasicType == 2) {
        _sprintf((char *)typeTemp1Overlay,"%d (%s)",*(undefined4 *)(*(int *)(intermConstantUnion + 0x30) + componentIndex * 4),
                 "const int");
        appendText = typeTemp1Overlay;
LAB_97b977f0:
        __ZN13TInfoSinkBase6appendEPKc(infoSink + 8,(char *)appendText);
LAB_97b977f8:
        lineSink = infoSink + 8;
      }
      else {
        if (componentBasicType < 3) {
          if (componentBasicType == 1) {
            ((char * (*)())_glp_dtostr)(getTypeResult,intermTraverserCopy,floatTextBuf,300,
                        (double)*(float *)(*(int *)(intermConstantUnion + 0x30) + componentIndex * 4),DOUBLE_97c30a70,
                        scratchF3,scratchF4,scratchF5,scratchF6,scratchF7,scratchF8,leftoverStackArg0,leftoverStackArg1,
                        leftoverStackArg2,leftoverStackArg3,leftoverStackArg4);
            _sprintf(floatTextBuf,"%s (%s)",floatTextBuf,"const float");
            __ZN13TInfoSinkBase6appendEPKc(infoSink + 8,floatTextBuf);
            goto LAB_97b977f8;
          }
        }
        else if (componentBasicType == 3) {
          if (*(int *)(*(int *)(intermConstantUnion + 0x30) + componentIndex * 4) == 0) {
            boolText = "false";
          }
          else {
            boolText = "true";
          }
          lineSink = infoSink + 8;
          __ZN13TInfoSinkBase6appendEPKc(lineSink,boolText);
          __ZN13TInfoSinkBase6appendEPKc(lineSink," (");
          __ZN13TInfoSinkBase6appendEPKc(lineSink,"const bool");
          appendText = (undefined ***)")";
          goto LAB_97b977f0;
        }
        sourceLoc = (*(code *)**(undefined4 **)intermConstantUnion)(intermConstantUnion,intermTraverserCopy);
                    
        __ZN13TInfoSinkBase6appendEPKc(infoSink,"INTERNAL ERROR: ");
        sourceLine = sourceLoc & 0xffff;
        cr0Flags = (sourceLine == 0) << 1;
        if (sourceLine == 0) {
          _sprintf(locTextBuf,"%d:? ",(int)sourceLoc >> 0x10);
        }
        else {
          _sprintf(locTextBuf,"%d:%d",(int)sourceLoc >> 0x10,sourceLine);
        }
        __ZNSsC1EPKcRKSaIcE(typeTemp1Overlay,locTextBuf,allocatorDummy);
        *(undefined *)((int)typeTemp1Overlay[0] + (int)typeTemp1Overlay[0][-3]) = *PTR__S_terminal_a7b7c0b8;
        __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)typeTemp1Overlay[0]);
        refCountPtr = typeTemp1Overlay[0] + -1;
        do {
          oldRefCount = *refCountPtr;
          if (reservation != '\0') {
            atomicStore = (undefined *)storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
            *refCountPtr = atomicStore;
            cr0Flags = 2;
          }
        } while (!(bool)(cr0Flags >> 1 & 1));
        if ((int)oldRefCount < 1) {
          __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(typeTemp1Overlay[0] + -3));
        }
        __ZN13TInfoSinkBase6appendEPKc(infoSink,": ");
        __ZN13TInfoSinkBase6appendEPKc(infoSink,"Unknown constant");
        lineSink = infoSink;
      }
      componentIndex = componentIndex + 1;
      __ZN13TInfoSinkBase6appendEPKc(lineSink,"\n");
    } while (componentIndex < componentCount);
  }
  return;
}

/* OutputLoop @ 0x97b97a04 (400 bytes) */
int OutputLoop(preVisit, intermLoop, intermTraverser)
  int preVisit;
  unsigned char * intermLoop;
  unsigned char * intermTraverser;
{
  int depth;
  unsigned char * this;
  
  this = *(unsigned char **)(intermTraverser + 0x30) + 8;
  ((int (*)())OutputTreeText)(*(unsigned char **)(intermTraverser + 0x30),(unsigned char *)intermLoop,*(int *)(intermTraverser + 0x20));
  __ZN13TInfoSinkBase6appendEPKc(this,"Loop with condition ");
  if (*(int *)(intermLoop + 0x14) == 0) {
    __ZN13TInfoSinkBase6appendEPKc(this,"not ");
  }
  __ZN13TInfoSinkBase6appendEPKc(this,"tested first\n");
  depth = *(int *)(intermTraverser + 0x20);
  *(int *)(intermTraverser + 0x20) = depth + 1;
  ((int (*)())OutputTreeText)(*(unsigned char **)(intermTraverser + 0x30),(unsigned char *)intermLoop,depth + 1);
  if (*(int *)(intermLoop + 0xc) == 0) {
    __ZN13TInfoSinkBase6appendEPKc(this,"No loop condition\n");
  }
  else {
    __ZN13TInfoSinkBase6appendEPKc(this,"Loop Condition\n");
    (**(code **)(**(int **)(intermLoop + 0xc) + 8))(*(int **)(intermLoop + 0xc),intermTraverser);
  }
  ((int (*)())OutputTreeText)(*(unsigned char **)(intermTraverser + 0x30),(unsigned char *)intermLoop,*(int *)(intermTraverser + 0x20));
  if (*(int *)(intermLoop + 8) == 0) {
    __ZN13TInfoSinkBase6appendEPKc(this,"No loop body\n");
  }
  else {
    __ZN13TInfoSinkBase6appendEPKc(this,"Loop Body\n");
    (**(code **)(**(int **)(intermLoop + 8) + 8))(*(int **)(intermLoop + 8),intermTraverser);
  }
  if (*(int *)(intermLoop + 0x10) != 0) {
    ((int (*)())OutputTreeText)(*(unsigned char **)(intermTraverser + 0x30),(unsigned char *)intermLoop,*(int *)(intermTraverser + 0x20));
    __ZN13TInfoSinkBase6appendEPKc(this,"Loop Terminal Expression\n");
    (**(code **)(**(int **)(intermLoop + 0x10) + 8))(*(int **)(intermLoop + 0x10),intermTraverser);
  }
  *(int *)(intermTraverser + 0x20) = *(int *)(intermTraverser + 0x20) + -1;
  return 0;
}

/* OutputBranch @ 0x97b97b94 (200 bytes) */
int OutputBranch(preVisit, intermBranch, intermTraverser)
  int preVisit;
  unsigned char * intermBranch;
  unsigned char * intermTraverser;
{
  unsigned char * this;
  
  this = *(unsigned char **)(intermTraverser + 0x30) + 8;
  ((int (*)())OutputTreeText)(*(unsigned char **)(intermTraverser + 0x30),(unsigned char *)intermBranch,*(int *)(intermTraverser + 0x20));
  __ZN13TInfoSinkBase6appendEPKc
            (this,*(char **)(PTR__operatorStrings_a7b7c0b0 + *(int *)(intermBranch + 8) * 4));
  if (*(int *)(intermBranch + 0xc) == 0) {
    __ZN13TInfoSinkBase6appendEPKc(this,"\n");
  }
  else {
    __ZN13TInfoSinkBase6appendEPKc(this," with expression\n");
    *(int *)(intermTraverser + 0x20) = *(int *)(intermTraverser + 0x20) + 1;
    (**(code **)(**(int **)(intermBranch + 0xc) + 8))(*(int **)(intermBranch + 0xc),intermTraverser);
    *(int *)(intermTraverser + 0x20) = *(int *)(intermTraverser + 0x20) + -1;
  }
  return 0;
}

/* TIntermediate__outputTree @ 0x97b97c5c (228 bytes) */
int TIntermediate__outputTree(this, intermNode)
  unsigned char * this;
  unsigned char * intermNode;
{
  undefined4 visitSymbolFn;
  undefined4 visitConstantUnionFn;
  undefined4 visitBinaryFn;
  undefined4 visitUnaryFn;
  undefined4 visitSelectionFn;
  undefined4 visitAggregateFn;
  undefined4 visitLoopFn;
  undefined4 visitBranchFn;
  undefined4 depth;
  undefined4 preVisit;
  undefined4 postVisit;
  undefined4 rightToLeft;
  int infoSink;
  
  if (intermNode != (unsigned char *)0x0) {
    infoSink = *(int *)this;
    visitAggregateFn = DAT_a7b7b9dc;
    visitBinaryFn = DAT_a7b7b9d8;
    visitConstantUnionFn = DAT_a7b7b9d4;
    visitSelectionFn = DAT_a7b7b9d0;
    visitSymbolFn = DAT_a7b7b9cc;
    visitUnaryFn = DAT_a7b7b9c8;
    visitLoopFn = DAT_a7b7b9c4;
    rightToLeft = 0;
    visitBranchFn = DAT_a7b7b9c0;
    depth = 0;
    preVisit = 1;
    postVisit = 0;
    __ZN13TInfoSinkBase6appendEPKc
              ((void *)(infoSink + 8),"\nIntermediate Parse Tree\n========================\n");
    postVisit = 1;
    preVisit = 1;
    (**(code **)(*(int *)intermNode + 8))(intermNode,&visitSymbolFn);
  }
  return;
}

/* TIntermSymbol__traverse @ 0x97b97d40 (20 bytes) */
int TIntermSymbol__traverse(this, intermTraverser)
  unsigned char * this;
  unsigned char * intermTraverser;
{
  if (*(code **)intermTraverser == (code *)0x0) {
    return;
  }
                    
                    
  (**(code **)intermTraverser)(this,intermTraverser);
  return;
}

/* TIntermConstantUnion__traverse @ 0x97b97d54 (20 bytes) */
int TIntermConstantUnion__traverse(this, intermTraverser)
  unsigned char * this;
  unsigned char * intermTraverser;
{
  if (*(code **)(intermTraverser + 4) == (code *)0x0) {
    return;
  }
                    
                    
  (**(code **)(intermTraverser + 4))(this);
  return;
}

/* TIntermBinary__traverse @ 0x97b97d68 (324 bytes) */
int TIntermBinary__traverse(this, intermTraverser)
  unsigned char * this;
  unsigned char * intermTraverser;
{
  int *right;
  int *left;
  int visit;
  int *childNode;
  
  visit = 1;
  if ((*(int *)(intermTraverser + 0x24) != 0) && (*(code **)(intermTraverser + 8) != (code *)0x0)) {
    visit = (**(code **)(intermTraverser + 8))(1,this,intermTraverser);
  }
  if (visit != 0) {
    *(int *)(intermTraverser + 0x20) = *(int *)(intermTraverser + 0x20) + 1;
    if (*(int *)(intermTraverser + 0x2c) == 0) {
      left = *(int **)(this + 0x34);
      if (left != (int *)0x0) {
        (**(code **)(*left + 8))(left,intermTraverser);
      }
      childNode = *(int **)(this + 0x38);
    }
    else {
      right = *(int **)(this + 0x38);
      if (right != (int *)0x0) {
        (**(code **)(*right + 8))(right,intermTraverser);
      }
      childNode = *(int **)(this + 0x34);
    }
    if (childNode != (int *)0x0) {
      (**(code **)(*childNode + 8))(childNode,intermTraverser);
    }
    *(int *)(intermTraverser + 0x20) = *(int *)(intermTraverser + 0x20) + -1;
    if ((*(int *)(intermTraverser + 0x28) != 0) && (*(code **)(intermTraverser + 8) != (code *)0x0)) {
                    
                    
      (**(code **)(intermTraverser + 8))(0,this,intermTraverser);
      return;
    }
  }
  return;
}

/* TIntermUnary__traverse @ 0x97b97eac (240 bytes) */
int TIntermUnary__traverse(this, intermTraverser)
  unsigned char * this;
  unsigned char * intermTraverser;
{
  int visit;
  
  if (((*(int *)(intermTraverser + 0x24) == 0) || (*(code **)(intermTraverser + 0xc) == (code *)0x0)) ||
     (visit = (**(code **)(intermTraverser + 0xc))(1,this,intermTraverser), visit != 0)) {
    *(int *)(intermTraverser + 0x20) = *(int *)(intermTraverser + 0x20) + 1;
    (**(code **)(**(int **)(this + 0x34) + 8))(*(int **)(this + 0x34),intermTraverser);
    *(int *)(intermTraverser + 0x20) = *(int *)(intermTraverser + 0x20) + -1;
    if ((*(int *)(intermTraverser + 0x28) != 0) && (*(code **)(intermTraverser + 0xc) != (code *)0x0)) {
                    
                    
      (**(code **)(intermTraverser + 0xc))(0,this,intermTraverser);
      return;
    }
  }
  return;
}

/* TIntermAggregate__traverse @ 0x97b97f9c (292 bytes) */
int TIntermAggregate__traverse(this, intermTraverser)
  unsigned char * this;
  unsigned char * intermTraverser;
{
  int visit;
  undefined4 *childCursor;
  
  visit = 1;
  if ((*(int *)(intermTraverser + 0x24) != 0) && (*(code **)(intermTraverser + 0x14) != (code *)0x0)) {
    visit = (**(code **)(intermTraverser + 0x14))(1,this,intermTraverser);
  }
  if (visit != 0) {
    *(int *)(intermTraverser + 0x20) = *(int *)(intermTraverser + 0x20) + 1;
    if (*(int *)(intermTraverser + 0x2c) == 0) {
      for (childCursor = *(undefined4 **)(this + 0x38); childCursor != *(undefined4 **)(this + 0x3c);
          childCursor = childCursor + 1) {
        (**(code **)(*(int *)*childCursor + 8))((int *)*childCursor,intermTraverser);
      }
    }
    else {
      childCursor = *(undefined4 **)(this + 0x3c);
      while (childCursor != *(undefined4 **)(this + 0x38)) {
        childCursor = childCursor + -1;
        (**(code **)(*(int *)*childCursor + 8))((int *)*childCursor,intermTraverser);
      }
    }
    *(int *)(intermTraverser + 0x20) = *(int *)(intermTraverser + 0x20) + -1;
    if ((*(int *)(intermTraverser + 0x28) != 0) && (*(code **)(intermTraverser + 0x14) != (code *)0x0)) {
      (**(code **)(intermTraverser + 0x14))(0,this,intermTraverser);
    }
  }
  return;
}

/* TIntermSelection__traverse @ 0x97b980c0 (388 bytes) */
int TIntermSelection__traverse(this, intermTraverser)
  unsigned char * this;
  unsigned char * intermTraverser;
{
  int nodeVtable;
  int *falseBlock;
  int *trueBlock;
  int visit;
  int *childNode;
  
  visit = 1;
  if ((*(int *)(intermTraverser + 0x24) != 0) && (*(code **)(intermTraverser + 0x10) != (code *)0x0)) {
    visit = (**(code **)(intermTraverser + 0x10))(1,this,intermTraverser);
  }
  if (visit == 0) {
    return;
  }
  *(int *)(intermTraverser + 0x20) = *(int *)(intermTraverser + 0x20) + 1;
  if (*(int *)(intermTraverser + 0x2c) == 0) {
    (**(code **)(**(int **)(this + 0x30) + 8))(*(int **)(this + 0x30),intermTraverser);
    trueBlock = *(int **)(this + 0x34);
    if (trueBlock != (int *)0x0) {
      (**(code **)(*trueBlock + 8))(trueBlock,intermTraverser);
    }
    childNode = *(int **)(this + 0x38);
    if (childNode == (int *)0x0) goto LAB_97b981d4;
    nodeVtable = *childNode;
  }
  else {
    falseBlock = *(int **)(this + 0x38);
    if (falseBlock != (int *)0x0) {
      (**(code **)(*falseBlock + 8))(falseBlock,intermTraverser);
    }
    trueBlock = *(int **)(this + 0x34);
    if (trueBlock != (int *)0x0) {
      (**(code **)(*trueBlock + 8))(trueBlock,intermTraverser);
    }
    childNode = *(int **)(this + 0x30);
    nodeVtable = *childNode;
  }
  (**(code **)(nodeVtable + 8))(childNode,intermTraverser);
LAB_97b981d4:
  *(int *)(intermTraverser + 0x20) = *(int *)(intermTraverser + 0x20) + -1;
  if ((*(int *)(intermTraverser + 0x28) != 0) && (*(code **)(intermTraverser + 0x10) != (code *)0x0)) {
                    
                    
    (**(code **)(intermTraverser + 0x10))(0,this,intermTraverser);
    return;
  }
  return;
}

/* TIntermLoop__traverse @ 0x97b98244 (388 bytes) */
int TIntermLoop__traverse(this, intermTraverser)
  unsigned char * this;
  unsigned char * intermTraverser;
{
  int visit;
  int *childNode;
  
  visit = 1;
  if ((*(int *)(intermTraverser + 0x24) != 0) && (*(code **)(intermTraverser + 0x18) != (code *)0x0)) {
    visit = (**(code **)(intermTraverser + 0x18))(1,this,intermTraverser);
  }
  if (visit != 0) {
    *(int *)(intermTraverser + 0x20) = *(int *)(intermTraverser + 0x20) + 1;
    if (*(int *)(intermTraverser + 0x2c) == 0) {
      childNode = *(int **)(this + 0xc);
      if (childNode != (int *)0x0) {
        (**(code **)(*childNode + 8))(childNode,intermTraverser);
      }
      childNode = *(int **)(this + 8);
      if (childNode != (int *)0x0) {
        (**(code **)(*childNode + 8))(childNode,intermTraverser);
      }
      childNode = *(int **)(this + 0x10);
    }
    else {
      childNode = *(int **)(this + 0x10);
      if (childNode != (int *)0x0) {
        (**(code **)(*childNode + 8))(childNode,intermTraverser);
      }
      childNode = *(int **)(this + 8);
      if (childNode != (int *)0x0) {
        (**(code **)(*childNode + 8))(childNode,intermTraverser);
      }
      childNode = *(int **)(this + 0xc);
    }
    if (childNode != (int *)0x0) {
      (**(code **)(*childNode + 8))(childNode,intermTraverser);
    }
    *(int *)(intermTraverser + 0x20) = *(int *)(intermTraverser + 0x20) + -1;
    if ((*(int *)(intermTraverser + 0x28) != 0) && (*(code **)(intermTraverser + 0x18) != (code *)0x0)) {
                    
                    
      (**(code **)(intermTraverser + 0x18))(0,this,intermTraverser);
      return;
    }
  }
  return;
}

/* TIntermBranch__traverse @ 0x97b983c8 (216 bytes) */
int TIntermBranch__traverse(this, intermTraverser)
  unsigned char * this;
  unsigned char * intermTraverser;
{
  int visit;
  
  visit = 1;
  if ((*(int *)(intermTraverser + 0x24) != 0) && (*(code **)(intermTraverser + 0x1c) != (code *)0x0)) {
    visit = (**(code **)(intermTraverser + 0x1c))(1,this,intermTraverser);
  }
  if (visit != 0) {
    if (*(int *)(this + 0xc) != 0) {
      *(int *)(intermTraverser + 0x20) = *(int *)(intermTraverser + 0x20) + 1;
      (**(code **)(**(int **)(this + 0xc) + 8))(*(int **)(this + 0xc),intermTraverser);
      *(int *)(intermTraverser + 0x20) = *(int *)(intermTraverser + 0x20) + -1;
    }
    if ((*(int *)(intermTraverser + 0x28) != 0) && (*(code **)(intermTraverser + 0x1c) != (code *)0x0)) {
                    
                    
      (**(code **)(intermTraverser + 0x1c))(0,this,intermTraverser);
      return;
    }
  }
  return;
}

/* ParseSymbol @ 0x97b984a0 (332 bytes) */
int ParseSymbol(intermSymbol, intermTraverser)
  unsigned char * intermSymbol;
  unsigned char * intermTraverser;
{
  int foundVariable;
  uint lineInString;
  uint sourceLoc;
  uint traverserBasicType;
  uint variableTypeBits;
  int intValue;
  int constArray;
  int objectSize;
  int componentCount;
  int variableBasicType;
  int symbolName;
  int *refCountPtr;
  int newRefCount;
  int oldRefCount;
  bool isNotMatrix;
  undefined *atomicStore;
  int *levelsVector;
  undefined **refCountPtr2;
  undefined *oldRefCount2;
  undefined4 symbolNameString;
  unsigned char * this;
  uint variableBasicTypeU;
  int componentSrcBasicType;
  undefined4 intermTraverserCopy;
  undefined4 r4Out0;
  undefined ***messageText;
  uint traverserTypeBits;
  int levelsBegin;
  int variableType;
  int resultArray;
  int instanceSize;
  int componentIndex;
  void *infoSink;
  int level;
  int levelIndex;
  char reservation;
  byte cr0Reg;
  byte cr0Flags;
  double i2dBias;
  undefined8 constArrayAlloc;
  undefined **stackType;
  int stackTypeArraySize;
  unsigned char locTextBuf [20];
  uint stackTypeBits;
  undefined **messageBuf [8];
  unsigned char allocatorDummy [128];
  char *locString [4];
  char locTextBuf2 [32];
  undefined **destroyAllocatorArg [4];
  char locTextBuf3 [16];
  unsigned char allocatorDummy2 [48];
  int findResult [2];
  longlong d2iScratch;
  undefined4 i2dHi;
  uint i2dLo;
  
  (**(code **)(*(int *)intermSymbol + 0x38))(&stackType,intermSymbol);
  traverserTypeBits = *(uint *)(intermTraverser + 0x60);
  stackType = &PTR___ZN5TTypeD1Ev_a7b7d488;
  resultArray = *(int *)(intermTraverser + 0x34);
  if ((traverserTypeBits >> 0x13 & 0x3f) == 0xe) {
    instanceSize = *(int *)(intermTraverser + 0x54);
  }
  else {
    isNotMatrix = (traverserTypeBits & 0x400) == 0;
    cr0Reg = isNotMatrix << 1;
    if (isNotMatrix) {
      instanceSize = (int)(traverserTypeBits << 0xd | traverserTypeBits >> 0x13) >> 0x18;
    }
    else {
      instanceSize = (int)(traverserTypeBits << 0xd | traverserTypeBits >> 0x13) >> 0x18;
      instanceSize = instanceSize * instanceSize;
    }
  }
  if (*(int *)(intermTraverser + 0x30) < instanceSize) {
    if (stackTypeBits >> 0x19 == 2) {
      levelsVector = *(int **)(intermTraverser + 0x70);
      symbolNameString = (**(code **)(*(int *)intermSymbol + 0x60))(intermSymbol,intermTraverserCopy);
      levelsBegin = *levelsVector;
      levelIndex = (levelsVector[1] - levelsBegin >> 2) + -1;
      while( true ) {
        level = *(int *)(levelsBegin + levelIndex * 4);
        foundVariable = 0;
        std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______find((unsigned char *)findResult,level,symbolNameString);
        if (findResult[0] != *(int *)(level + 4)) {
          foundVariable = *(int *)(findResult[0] + 0x18);
        }
        levelIndex = levelIndex + -1;
        if ((foundVariable != 0) || (levelIndex < 0)) break;
        levelsBegin = *levelsVector;
      }
      constArrayAlloc = CONCAT44(*(int *)(foundVariable + 0x38),r4Out0);
      if (*(int *)(foundVariable + 0x38) == 0) {
        if (*(int *)(foundVariable + 0x14) == 0) {
          variableTypeBits = *(uint *)(foundVariable + 0x30);
          if ((variableTypeBits & 0x400) == 0) {
            objectSize = (int)(variableTypeBits << 0xd | variableTypeBits >> 0x13) >> 0x18;
          }
          else {
            objectSize = (int)(variableTypeBits << 0xd | variableTypeBits >> 0x13) >> 0x18;
            objectSize = objectSize * objectSize;
          }
        }
        else {
          objectSize = *(int *)(foundVariable + 0x24);
        }
        this = (unsigned char *)GetGlobalPoolAllocator();
        constArrayAlloc = TPoolAllocator__allocate(this,objectSize << 2);
        *(int *)(foundVariable + 0x38) = (int)((ulonglong)constArrayAlloc >> 0x20);
      }
      constArray = (int)((ulonglong)constArrayAlloc >> 0x20);
      if (constArray != 0) {
        variableType = foundVariable + 0xc;
        variableBasicType = (**(code **)(*(int *)(foundVariable + 0xc) + 0x20))(variableType,(int)constArrayAlloc);
        if (variableBasicType == 0xe) {
          componentCount = *(int *)(foundVariable + 0x24);
        }
        else {
          componentCount = (**(code **)(*(int *)(foundVariable + 0xc) + 0x30))(variableType);
        }
        componentIndex = 0;
        if (componentCount < 1) {
          return;
        }
        do {
          if (instanceSize <= *(int *)(intermTraverser + 0x30)) {
            return;
          }
          variableBasicTypeU = (**(code **)(*(int *)(foundVariable + 0xc) + 0x20))(variableType);
          traverserBasicType = *(uint *)(intermTraverser + 0x60) >> 0x13 & 0x3f;
          if ((variableBasicTypeU == traverserBasicType) || (traverserBasicType == 0xe)) {
code_r0x97b98c14:
            *(undefined4 *)(resultArray + *(int *)(intermTraverser + 0x30) * 4) =
                 *(undefined4 *)(componentIndex * 4 + constArray);
          }
          else {
            componentSrcBasicType = (**(code **)(*(int *)(foundVariable + 0xc) + 0x20))(variableType);
            if (componentSrcBasicType == 2) {
              traverserBasicType = *(uint *)(intermTraverser + 0x60) >> 0x13 & 0x3f;
              if (traverserBasicType == 1) {
                i2dLo = *(uint *)(componentIndex * 4 + constArray) ^ 0x80000000;
                i2dBias = DOUBLE_97c30a58;
code_r0x97b98bfc:
                i2dHi = 0x43300000;
                *(float *)(resultArray + *(int *)(intermTraverser + 0x30) * 4) =
                     (float)((double)CONCAT44(0x43300000,i2dLo) - i2dBias);
              }
              else {
                if (traverserBasicType != 3) {
                  infoSink = *(void **)(intermTraverser + 0x6c);
                  sourceLoc = (*(code *)**(undefined4 **)intermSymbol)(intermSymbol);
                    
                  goto override_jmp_97b98aec_case_0;
                }
                *(uint *)(resultArray + *(int *)(intermTraverser + 0x30) * 4) =
                     (uint)(*(int *)(componentIndex * 4 + constArray) != 0);
              }
            }
            else {
              if (componentSrcBasicType < 3) {
                if (componentSrcBasicType == 1) {
                  traverserBasicType = *(uint *)(intermTraverser + 0x60) >> 0x13 & 0x3f;
                  if (traverserBasicType == 2) {
                    intValue = (int)*(float *)(componentIndex * 4 + constArray);
                    d2iScratch = (longlong)intValue;
                    *(int *)(*(int *)(intermTraverser + 0x30) * 4 + resultArray) = intValue;
                  }
                  else {
                    if (traverserBasicType != 3) {
                      infoSink = *(void **)(intermTraverser + 0x6c);
                      sourceLoc = (*(code *)**(undefined4 **)intermSymbol)(intermSymbol);
                    
                      goto override_jmp_97b98aec_case_0;
                    }
                    *(uint *)(*(int *)(intermTraverser + 0x30) * 4 + resultArray) =
                         (uint)((double)*(float *)(componentIndex * 4 + constArray) != DOUBLE_97c30a48);
                  }
                  goto code_r0x97b98dd8;
                }
              }
              else if (componentSrcBasicType == 3) {
                traverserBasicType = *(uint *)(intermTraverser + 0x60) >> 0x13 & 0x3f;
                if (traverserBasicType == 1) {
                  i2dLo = *(uint *)(componentIndex * 4 + constArray);
                  i2dBias = DOUBLE_97c30a68;
                  goto code_r0x97b98bfc;
                }
                if (traverserBasicType != 2) {
                  infoSink = *(void **)(intermTraverser + 0x6c);
                  sourceLoc = (*(code *)**(undefined4 **)intermSymbol)(intermSymbol);
                    
                  goto override_jmp_97b98aec_case_0;
                }
                goto code_r0x97b98c14;
              }
              infoSink = *(void **)(intermTraverser + 0x6c);
              sourceLoc = (*(code *)**(undefined4 **)intermSymbol)(intermSymbol);
                    
override_jmp_97b98aec_case_0:
              __ZN13TInfoSinkBase6appendEPKc(infoSink,"INTERNAL ERROR: ");
              lineInString = sourceLoc & 0xffff;
              cr0Flags = (lineInString == 0) << 1;
              if (lineInString == 0) {
                _sprintf((char *)locTextBuf,"%d:? ",(int)sourceLoc >> 0x10);
              }
              else {
                _sprintf((char *)locTextBuf,"%d:%d",(int)sourceLoc >> 0x10,lineInString);
              }
              __ZNSsC1EPKcRKSaIcE(&stackType,(char *)locTextBuf,allocatorDummy);
              *(undefined *)((int)stackType + (int)stackType[-3]) = *PTR__S_terminal_a7b7c0b8;
              __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)stackType);
              refCountPtr2 = stackType + -1;
              do {
                oldRefCount2 = *refCountPtr2;
                if (reservation != '\0') {
                  atomicStore = (undefined *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr2);
                  *refCountPtr2 = atomicStore;
                  cr0Flags = 2;
                }
              } while (!(bool)(cr0Flags >> 1 & 1));
              if ((int)oldRefCount2 < 1) {
                __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(stackType + -3));
              }
              __ZN13TInfoSinkBase6appendEPKc(infoSink,": ");
              __ZN13TInfoSinkBase6appendEPKc(infoSink,"Incorrect type, cannot parse symbol");
              __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
            }
          }
code_r0x97b98dd8:
          componentIndex = componentIndex + 1;
          *(int *)(intermTraverser + 0x30) = *(int *)(intermTraverser + 0x30) + 1;
          if (componentCount <= componentIndex) {
            return;
          }
        } while( true );
      }
      symbolName = (**(code **)(*(int *)intermSymbol + 0x60))(intermSymbol);
      *(undefined1 *)(*(int *)(symbolName + 4) + *(int *)(*(int *)(symbolName + 4) + -0xc)) = *DAT_a7b7ba10;
      _sprintf((char *)&stackType,
               "\'constructor\' : constant \'%s\' has not been initialized correctly",
               *(undefined4 *)(symbolName + 4));
      infoSink = *(void **)(intermTraverser + 0x6c);
      sourceLoc = (*(code *)**(undefined4 **)intermSymbol)(intermSymbol);
                    
      __ZN13TInfoSinkBase6appendEPKc(infoSink,"ERROR: ");
      lineInString = sourceLoc & 0xffff;
      cr0Flags = (lineInString == 0) << 1;
      if (lineInString == 0) {
        _sprintf(locTextBuf2,"%d:? ",(int)sourceLoc >> 0x10);
      }
      else {
        _sprintf(locTextBuf2,"%d:%d",(int)sourceLoc >> 0x10,lineInString);
      }
      __ZNSsC1EPKcRKSaIcE(locString,locTextBuf2,allocatorDummy2);
      locString[0][*(int *)(locString[0] + -0xc)] = *PTR__S_terminal_a7b7c0b8;
      __ZN13TInfoSinkBase6appendEPKc(infoSink,locString[0]);
      refCountPtr = (int *)(locString[0] + -4);
      do {
        oldRefCount = *refCountPtr;
        if (reservation != '\0') {
          newRefCount = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
          *refCountPtr = newRefCount;
          cr0Flags = 2;
        }
      } while (!(bool)(cr0Flags >> 1 & 1));
      if (oldRefCount < 1) {
        __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(locString[0] + -0xc));
      }
      __ZN13TInfoSinkBase6appendEPKc(infoSink,": ");
      messageText = &stackType;
    }
    else {
      ((int (*)())TType__getCompleteString)(&stackType,intermTraverser + 0x3c);
      messageText = messageBuf;
      *(undefined1 *)(stackTypeArraySize + *(int *)(stackTypeArraySize + -0xc)) = *DAT_a7b7ba10;
      _sprintf((char *)messageText,"\'constructor\' : assigning non-constant to %s",stackTypeArraySize);
      refCountPtr = (int *)(stackTypeArraySize + -4);
      destroyAllocatorArg[0] = stackType;
      do {
        oldRefCount = *refCountPtr;
        if (reservation != '\0') {
          newRefCount = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
          *refCountPtr = newRefCount;
          cr0Reg = 2;
        }
      } while (!(bool)(cr0Reg >> 1 & 1));
      if (oldRefCount < 1) {
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                  ((unsigned char *)(stackTypeArraySize + -0xc),destroyAllocatorArg);
      }
      infoSink = *(void **)(intermTraverser + 0x6c);
      sourceLoc = (*(code *)**(undefined4 **)intermSymbol)(intermSymbol);
                    
      __ZN13TInfoSinkBase6appendEPKc(infoSink,"ERROR: ");
      lineInString = sourceLoc & 0xffff;
      cr0Flags = (lineInString == 0) << 1;
      if (lineInString == 0) {
        _sprintf(locTextBuf3,"%d:? ",(int)sourceLoc >> 0x10);
      }
      else {
        _sprintf(locTextBuf3,"%d:%d",(int)sourceLoc >> 0x10,lineInString);
      }
      __ZNSsC1EPKcRKSaIcE(&stackType,locTextBuf3,locTextBuf);
      *(undefined *)((int)stackType + (int)stackType[-3]) = *PTR__S_terminal_a7b7c0b8;
      __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)stackType);
      refCountPtr2 = stackType + -1;
      do {
        oldRefCount2 = *refCountPtr2;
        if (reservation != '\0') {
          atomicStore = (undefined *)storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr2);
          *refCountPtr2 = atomicStore;
          cr0Flags = 2;
        }
      } while (!(bool)(cr0Flags >> 1 & 1));
      if ((int)oldRefCount2 < 1) {
        __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(stackType + -3));
      }
      __ZN13TInfoSinkBase6appendEPKc(infoSink,": ");
    }
    __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)messageText);
    __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
    *(undefined4 *)(intermTraverser + 0x74) = 1;
  }
  return;
}

/* ParseBinary @ 0x97b98e04 (308 bytes) */
int ParseBinary(preVisit, intermBinary, intermTraverser)
  int preVisit;
  unsigned char * intermBinary;
  unsigned char * intermTraverser;
{
  int atomicStore2;
  undefined *atomicStore;
  int *refCountPtr;
  undefined **refCountPtr2;
  int oldRefCount2;
  undefined *oldRefCount;
  uint sourceLoc;
  uint lineInString;
  void *infoSink;
  char reservation;
  byte cr0Reg;
  byte cr0Flags;
  undefined **stackType;
  int stackTypeArraySize;
  unsigned char locTextBuf [20];
  uint stackTypeBits;
  char messageBuf [32];
  unsigned char allocatorDummy [176];
  undefined **destroyAllocatorArg [4];
  char locTextBuf2 [72];
  
  (**(code **)(*(int *)intermBinary + 0x38))(&stackType,intermBinary,intermTraverser);
  stackType = &PTR___ZN5TTypeD1Ev_a7b7d488;
  if (stackTypeBits >> 0x19 == 2) {
    infoSink = *(void **)(intermTraverser + 0x6c);
    sourceLoc = (*(code *)**(undefined4 **)intermBinary)(intermBinary);
    __ZN13TInfoSinkBase6appendEPKc(infoSink,"INTERNAL ERROR: ");
    lineInString = sourceLoc & 0xffff;
    cr0Flags = (lineInString == 0) << 1;
    if (lineInString == 0) {
      _sprintf((char *)locTextBuf,"%d:? ",(int)sourceLoc >> 0x10);
    }
    else {
      _sprintf((char *)locTextBuf,"%d:%d",(int)sourceLoc >> 0x10,lineInString);
    }
    __ZNSsC1EPKcRKSaIcE(&stackType,(char *)locTextBuf,allocatorDummy);
    *(undefined *)((int)stackType + (int)stackType[-3]) = *PTR__S_terminal_a7b7c0b8;
    __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)stackType);
    refCountPtr2 = stackType + -1;
    do {
      oldRefCount = *refCountPtr2;
      if (reservation != '\0') {
        atomicStore = (undefined *)storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr2);
        *refCountPtr2 = atomicStore;
        cr0Flags = 2;
      }
    } while (!(bool)(cr0Flags >> 1 & 1));
    if ((int)oldRefCount < 1) {
      __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(stackType + -3),locTextBuf);
    }
    __ZN13TInfoSinkBase6appendEPKc(infoSink,": ");
    __ZN13TInfoSinkBase6appendEPKc(infoSink,"Binary Node found in constant constructor");
    __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
  }
  else {
    ((int (*)())TType__getCompleteString)(&stackType,intermTraverser + 0x3c);
    *(undefined1 *)(stackTypeArraySize + *(int *)(stackTypeArraySize + -0xc)) = *DAT_a7b7ba10;
    _sprintf(messageBuf,"\'constructor\' : assigning non-constant to %s",stackTypeArraySize);
    refCountPtr = (int *)(stackTypeArraySize + -4);
    destroyAllocatorArg[0] = stackType;
    do {
      oldRefCount2 = *refCountPtr;
      if (reservation != '\0') {
        atomicStore2 = storeWordConditionalIndexed(oldRefCount2 + -1,0,refCountPtr);
        *refCountPtr = atomicStore2;
        cr0Reg = 2;
      }
    } while (!(bool)(cr0Reg >> 1 & 1));
    if (oldRefCount2 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(stackTypeArraySize + -0xc),destroyAllocatorArg);
    }
    infoSink = *(void **)(intermTraverser + 0x6c);
    sourceLoc = (*(code *)**(undefined4 **)intermBinary)(intermBinary);
    __ZN13TInfoSinkBase6appendEPKc(infoSink,"ERROR: ");
    lineInString = sourceLoc & 0xffff;
    cr0Flags = (lineInString == 0) << 1;
    if (lineInString == 0) {
      _sprintf(locTextBuf2,"%d:? ",(int)sourceLoc >> 0x10);
    }
    else {
      _sprintf(locTextBuf2,"%d:%d",(int)sourceLoc >> 0x10,lineInString);
    }
    __ZNSsC1EPKcRKSaIcE(&stackType,locTextBuf2,locTextBuf);
    *(undefined *)((int)stackType + (int)stackType[-3]) = *PTR__S_terminal_a7b7c0b8;
    __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)stackType);
    refCountPtr2 = stackType + -1;
    do {
      oldRefCount = *refCountPtr2;
      if (reservation != '\0') {
        atomicStore = (undefined *)storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr2);
        *refCountPtr2 = atomicStore;
        cr0Flags = 2;
      }
    } while (!(bool)(cr0Flags >> 1 & 1));
    if ((int)oldRefCount < 1) {
      __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(stackType + -3),locTextBuf);
    }
    __ZN13TInfoSinkBase6appendEPKc(infoSink,": ");
    __ZN13TInfoSinkBase6appendEPKc(infoSink,messageBuf);
    __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
    *(undefined4 *)(intermTraverser + 0x74) = 1;
  }
  return 0;
}

/* ParseBinary__errorReportTail @ 0x97b9907c (12 bytes) */
int ParseBinary__errorReportTail()
{
  bool columnIsZero;
  int atomicStore;
  int *refCountPtr;
  int oldRefCount;
  char *messageText;
  void *infoSink;
  uint sourceLoc;
  int picBase;
  char reservation;
  byte cr0Flags;
  
  __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)(picBase + 0x8f990));
  columnIsZero = (sourceLoc & 0xffff) == 0;
  cr0Flags = columnIsZero << 1;
  if (columnIsZero) {
    _sprintf(&STACKARG(0x50),(char *)(picBase + 0x8f9d8),(int)sourceLoc >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x50),(char *)(picBase + 0x8f9d0),(int)sourceLoc >> 0x10);
  }
  __ZNSsC1EPKcRKSaIcE(&STACKARG(0x40),&STACKARG(0x50),(unsigned char *)&STACKARG(0x90));
  (*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40))[*(int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -0xc)] = **(char **)(picBase + 0xffe32a4);
  __ZN13TInfoSinkBase6appendEPKc(infoSink,(*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)));
  refCountPtr = (int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -4);
  do {
    oldRefCount = *refCountPtr;
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
      *refCountPtr = atomicStore;
      cr0Flags = 2;
    }
  } while (!(bool)(cr0Flags >> 1 & 1));
  if (oldRefCount < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -0xc));
  }
  __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)(picBase + 0x8f9e0));
  __ZN13TInfoSinkBase6appendEPKc(infoSink,messageText);
  __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)(picBase + 0x8de24));
  return 0;
}

/* ParseUnary @ 0x97b99198 (196 bytes) */
int ParseUnary(preVisit, intermUnary, intermTraverser)
  int preVisit;
  unsigned char * intermUnary;
  unsigned char * intermTraverser;
{
  int atomicStore;
  int *refCountPtr;
  int oldRefCount;
  uint sourceLoc;
  uint sourceLine;
  void *this;
  char reservation;
  byte cr0Reg;
  byte cr0Flags;
  char messageBuf [208];
  char *typeString;
  int typeStringChars;
  char *destroyAllocatorArg [4];
  char locTextBuf [64];
  unsigned char allocatorDummy [28];
  
  ((int (*)())TType__getCompleteString)(&typeString,intermTraverser + 0x3c);
  *(undefined1 *)(typeStringChars + *(int *)(typeStringChars + -0xc)) = *DAT_a7b7ba10;
  _sprintf(messageBuf,"\'constructor\' : assigning non-constant to \'%s\'",typeStringChars);
  refCountPtr = (int *)(typeStringChars + -4);
  destroyAllocatorArg[0] = typeString;
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
              ((unsigned char *)(typeStringChars + -0xc),destroyAllocatorArg);
  }
  this = *(void **)(intermTraverser + 0x6c);
  sourceLoc = (*(code *)**(undefined4 **)intermUnary)(intermUnary);
  __ZN13TInfoSinkBase6appendEPKc(this,"ERROR: ");
  sourceLine = sourceLoc & 0xffff;
  cr0Flags = (sourceLine == 0) << 1;
  if (sourceLine == 0) {
    _sprintf(locTextBuf,"%d:? ",(int)sourceLoc >> 0x10);
  }
  else {
    _sprintf(locTextBuf,"%d:%d",(int)sourceLoc >> 0x10,sourceLine);
  }
  __ZNSsC1EPKcRKSaIcE(&typeString,locTextBuf,allocatorDummy);
  typeString[*(int *)(typeString + -0xc)] = *PTR__S_terminal_a7b7c0b8;
  __ZN13TInfoSinkBase6appendEPKc(this,typeString);
  refCountPtr = (int *)(typeString + -4);
  do {
    oldRefCount = *refCountPtr;
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
      *refCountPtr = atomicStore;
      cr0Flags = 2;
    }
  } while (!(bool)(cr0Flags >> 1 & 1));
  if (oldRefCount < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(typeString + -0xc));
  }
  __ZN13TInfoSinkBase6appendEPKc(this,": ");
  __ZN13TInfoSinkBase6appendEPKc(this,messageBuf);
  __ZN13TInfoSinkBase6appendEPKc(this,"\n");
  *(undefined4 *)(intermTraverser + 0x74) = 1;
  return 0;
}

/* ParseUnary__errorReportTail @ 0x97b99274 (12 bytes) */
int ParseUnary__errorReportTail()
{
  bool columnIsZero;
  int atomicStore;
  int *refCountPtr;
  int oldRefCount;
  void *locStringObj;
  int traverser;
  uint sourceLoc;
  void *infoSink;
  int picBase;
  char reservation;
  byte cr0Flags;
  
  __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)(picBase + 0x8f5fc));
  columnIsZero = (sourceLoc & 0xffff) == 0;
  cr0Flags = columnIsZero << 1;
  if (columnIsZero) {
    _sprintf(&STACKARG(0x130),(char *)(picBase + 0x8f644),(int)sourceLoc >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x130),(char *)(picBase + 0x8f63c),(int)sourceLoc >> 0x10);
  }
  __ZNSsC1EPKcRKSaIcE(locStringObj,&STACKARG(0x130),(unsigned char *)&STACKARG(0x170));
  (*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x110))[*(int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x110)) + -0xc)] = **(char **)(picBase + 0xffe2f10);
  __ZN13TInfoSinkBase6appendEPKc(infoSink,(*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x110)));
  refCountPtr = (int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x110)) + -4);
  do {
    oldRefCount = *refCountPtr;
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
      *refCountPtr = atomicStore;
      cr0Flags = 2;
    }
  } while (!(bool)(cr0Flags >> 1 & 1));
  if (oldRefCount < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x110)) + -0xc));
  }
  __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)(picBase + 0x8f64c));
  __ZN13TInfoSinkBase6appendEPKc(infoSink,&STACKARG(0x40));
  __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)(picBase + 0x8da90));
  *(undefined4 *)(traverser + 0x74) = 1;
  return 0;
}

/* ParseAggregate @ 0x97b99398 (232 bytes) */
int ParseAggregate(preVisit, intermAggregate, intermTraverser, scratchR6, scratchR7, scratchR8)
  int preVisit;
  unsigned char * intermAggregate;
  unsigned char * intermTraverser;
  undefined4 scratchR6;
  undefined4 scratchR7;
  undefined4 scratchR8;
{
  int objectSize;
  int firstChildConstUnion;
  int *refCountPtr;
  int newRefCount;
  int oldRefCount;
  bool singleConstantParam;
  int *firstChildTyped;
  int sequence;
  uint sourceLoc;
  undefined4 intermAggregateCopy;
  unsigned char * intermTraverserCopy;
  uint sourceLine;
  int firstChildVtable;
  void *this;
  undefined4 *childCursor;
  char reservation;
  byte cr0Reg;
  byte cr0Flags;
  undefined8 isConstructorResult;
  undefined **typeTemp1 [9];
  uint typeTemp1Bits;
  undefined **typeTemp2 [6];
  undefined4 typeTemp2StructureSize;
  uint typeTemp2Bits;
  char *typeString;
  int typeStringChars;
  char *destroyAllocatorArg [4];
  char locTextBuf [64];
  unsigned char allocatorDummy [24];
  
  intermTraverserCopy = intermTraverser;
  isConstructorResult = ((int (*)())TIntermOperator__isConstructor)((unsigned char *)intermAggregate);
  if (((int)((ulonglong)isConstructorResult >> 0x20) == 0) && (*(int *)(intermAggregate + 0x30) != 0x25)) {
    ((int (*)())TType__getCompleteString)(&typeString,intermTraverser + 0x3c);
    *(undefined1 *)(typeStringChars + *(int *)(typeStringChars + -0xc)) = *DAT_a7b7ba10;
    _sprintf((char *)typeTemp1,"\'constructor\' : assigning non-constant to \'%s\'",typeStringChars);
    refCountPtr = (int *)(typeStringChars + -4);
    destroyAllocatorArg[0] = typeString;
    do {
      oldRefCount = *refCountPtr;
      if (reservation != '\0') {
        newRefCount = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
        *refCountPtr = newRefCount;
        cr0Reg = 2;
      }
    } while (!(bool)(cr0Reg >> 1 & 1));
    if (oldRefCount < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(typeStringChars + -0xc),destroyAllocatorArg);
    }
    this = *(void **)(intermTraverser + 0x6c);
    sourceLoc = (*(code *)**(undefined4 **)intermAggregate)(intermAggregate);
                    
    __ZN13TInfoSinkBase6appendEPKc(this,"ERROR: ");
    sourceLine = sourceLoc & 0xffff;
    cr0Flags = (sourceLine == 0) << 1;
    if (sourceLine == 0) {
      _sprintf(locTextBuf,"%d:? ",(int)sourceLoc >> 0x10);
    }
    else {
      _sprintf(locTextBuf,"%d:%d",(int)sourceLoc >> 0x10,sourceLine);
    }
    __ZNSsC1EPKcRKSaIcE(&typeString,locTextBuf,allocatorDummy);
    typeString[*(int *)(typeString + -0xc)] = *PTR__S_terminal_a7b7c0b8;
    __ZN13TInfoSinkBase6appendEPKc(this,typeString);
    refCountPtr = (int *)(typeString + -4);
    do {
      oldRefCount = *refCountPtr;
      if (reservation != '\0') {
        newRefCount = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
        *refCountPtr = newRefCount;
        cr0Flags = 2;
      }
    } while (!(bool)(cr0Flags >> 1 & 1));
    if (oldRefCount < 1) {
      __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(typeString + -0xc));
    }
    __ZN13TInfoSinkBase6appendEPKc(this,": ");
    __ZN13TInfoSinkBase6appendEPKc(this,(char *)typeTemp1);
    __ZN13TInfoSinkBase6appendEPKc(this,"\n");
  }
  else {
    sequence = (**(code **)(*(int *)intermAggregate + 100))(intermAggregate,(int)isConstructorResult);
    if ((uint)(*(int *)(sequence + 8) - *(int *)(sequence + 4)) >> 2 != 0) {
      singleConstantParam = false;
      sequence = (**(code **)(*(int *)intermAggregate + 100))(intermAggregate);
      if (*(int *)(sequence + 8) - *(int *)(sequence + 4) >> 2 == 1) {
        sequence = (**(code **)(*(int *)intermAggregate + 100))(intermAggregate);
        firstChildVtable = *(int *)**(undefined4 **)(sequence + 4);
        firstChildTyped = (int *)(**(code **)(firstChildVtable + 0x14))
                                  ((int *)**(undefined4 **)(sequence + 4),intermAggregateCopy,intermTraverserCopy,scratchR6,scratchR7,scratchR8
                                   ,firstChildVtable);
        firstChildConstUnion = (**(code **)(*firstChildTyped + 0x18))(firstChildTyped);
        if (firstChildConstUnion != 0) {
          singleConstantParam = true;
        }
      }
      if (singleConstantParam) {
        *(undefined4 *)(intermTraverser + 0x68) = 1;
        *(undefined4 *)(intermTraverser + 100) = *(undefined4 *)(intermAggregate + 0x30);
        (**(code **)(*(int *)intermAggregate + 0x38))
                  (typeTemp1,intermAggregate,intermTraverserCopy,scratchR6,scratchR7,scratchR8,*(int *)intermAggregate);
        typeTemp1[0] = &PTR___ZN5TTypeD1Ev_a7b7d488;
        if ((typeTemp1Bits >> 0x13 & 0x3f) == 0xe) {
          (**(code **)(*(int *)intermAggregate + 0x38))(typeTemp2,intermAggregate);
          *(undefined4 *)(intermTraverser + 0x78) = typeTemp2StructureSize;
        }
        else {
          (**(code **)(*(int *)intermAggregate + 0x38))(typeTemp2,intermAggregate);
          if ((typeTemp2Bits & 0x400) == 0) {
            objectSize = (int)(typeTemp2Bits << 0xd | typeTemp2Bits >> 0x13) >> 0x18;
          }
          else {
            objectSize = (int)(typeTemp2Bits << 0xd | typeTemp2Bits >> 0x13) >> 0x18;
            objectSize = objectSize * objectSize;
          }
          *(int *)(intermTraverser + 0x78) = objectSize;
        }
        typeTemp2[0] = &PTR___ZN5TTypeD1Ev_a7b7d488;
        (**(code **)(*(int *)intermAggregate + 0x38))(typeTemp1,intermAggregate);
        typeTemp1[0] = &PTR___ZN5TTypeD1Ev_a7b7d488;
        if ((typeTemp1Bits & 0x400) != 0) {
          *(undefined4 *)(intermTraverser + 0x7c) = 1;
          (**(code **)(*(int *)intermAggregate + 0x38))
                    (typeTemp2,intermAggregate,intermTraverserCopy,scratchR6,scratchR7,scratchR8,typeTemp1Bits & 0x400);
          typeTemp2[0] = &PTR___ZN5TTypeD1Ev_a7b7d488;
          *(int *)(intermTraverser + 0x80) = (int)(typeTemp2Bits << 0xd | typeTemp2Bits >> 0x13) >> 0x18;
        }
      }
      sequence = (**(code **)(*(int *)intermAggregate + 100))(intermAggregate);
      for (childCursor = *(undefined4 **)(sequence + 4);
          sequence = (**(code **)(*(int *)intermAggregate + 100))(intermAggregate),
          childCursor != *(undefined4 **)(sequence + 8); childCursor = childCursor + 1) {
        if (*(int *)(intermAggregate + 0x30) == 0x25) {
          *(undefined4 *)(intermTraverser + 0x30) = 0;
        }
        (**(code **)(*(int *)*childCursor + 8))((int *)*childCursor,intermTraverser);
      }
      if (!singleConstantParam) {
        return 0;
      }
      *(undefined4 *)(intermTraverser + 0x80) = 0;
      *(undefined4 *)(intermTraverser + 0x68) = 0;
      *(undefined4 *)(intermTraverser + 100) = 0;
      *(undefined4 *)(intermTraverser + 0x78) = 0;
      *(undefined4 *)(intermTraverser + 0x7c) = 0;
      return 0;
    }
  }
  *(undefined4 *)(intermTraverser + 0x74) = 1;
  return 0;
}

/* ParseSelection @ 0x97b9982c (88 bytes) */
int ParseSelection(preVisit, intermSelection, intermTraverser)
  int preVisit;
  unsigned char * intermSelection;
  unsigned char * intermTraverser;
{
  int atomicStore;
  int *refCountPtr;
  int oldRefCount;
  uint sourceLoc;
  uint sourceLine;
  void *this;
  char reservation;
  byte cr0Flags;
  char *locString [4];
  char locTextBuf [64];
  unsigned char allocatorDummy [28];
  
  this = *(void **)(intermTraverser + 0x6c);
  sourceLoc = (*(code *)**(undefined4 **)intermSelection)(intermSelection,intermSelection,intermTraverser);
  __ZN13TInfoSinkBase6appendEPKc(this,"INTERNAL ERROR: ");
  sourceLine = sourceLoc & 0xffff;
  cr0Flags = (sourceLine == 0) << 1;
  if (sourceLine == 0) {
    _sprintf(locTextBuf,"%d:? ",(int)sourceLoc >> 0x10);
  }
  else {
    _sprintf(locTextBuf,"%d:%d",(int)sourceLoc >> 0x10,sourceLine);
  }
  __ZNSsC1EPKcRKSaIcE(locString,locTextBuf,allocatorDummy);
  locString[0][*(int *)(locString[0] + -0xc)] = *PTR__S_terminal_a7b7c0b8;
  __ZN13TInfoSinkBase6appendEPKc(this,locString[0]);
  refCountPtr = (int *)(locString[0] + -4);
  do {
    oldRefCount = *refCountPtr;
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
      *refCountPtr = atomicStore;
      cr0Flags = 2;
    }
  } while (!(bool)(cr0Flags >> 1 & 1));
  if (oldRefCount < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(locString[0] + -0xc),locTextBuf);
  }
  __ZN13TInfoSinkBase6appendEPKc(this,": ");
  __ZN13TInfoSinkBase6appendEPKc(this,"Selection Node found in constant constructor");
  __ZN13TInfoSinkBase6appendEPKc(this,"\n");
  *(undefined4 *)(intermTraverser + 0x74) = 1;
  return 0;
}

/* ParseSelection__errorReportTail @ 0x97b9989c (12 bytes) */
int ParseSelection__errorReportTail()
{
  bool columnIsZero;
  int atomicStore;
  int *refCountPtr;
  int oldRefCount;
  int traverser;
  char *messageText;
  uint sourceLoc;
  void *infoSink;
  int picBase;
  char reservation;
  byte cr0Flags;
  
  __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)(picBase + 0x8ef68));
  columnIsZero = (sourceLoc & 0xffff) == 0;
  cr0Flags = columnIsZero << 1;
  if (columnIsZero) {
    _sprintf(&STACKARG(0x50),(char *)(picBase + 0x8efb0),(int)sourceLoc >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x50),(char *)(picBase + 0x8efa8),(int)sourceLoc >> 0x10);
  }
  __ZNSsC1EPKcRKSaIcE(&STACKARG(0x40),&STACKARG(0x50),(unsigned char *)&STACKARG(0x90));
  (*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40))[*(int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -0xc)] = **(char **)(picBase + 0xffe287c);
  __ZN13TInfoSinkBase6appendEPKc(infoSink,(*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)));
  refCountPtr = (int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -4);
  do {
    oldRefCount = *refCountPtr;
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
      *refCountPtr = atomicStore;
      cr0Flags = 2;
    }
  } while (!(bool)(cr0Flags >> 1 & 1));
  if (oldRefCount < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -0xc));
  }
  __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)(picBase + 0x8efb8));
  __ZN13TInfoSinkBase6appendEPKc(infoSink,messageText);
  __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)(picBase + 0x8d3fc));
  *(undefined4 *)(traverser + 0x74) = 1;
  return 0;
}

/* ParseConstantUnion @ 0x97b999c0 (1160 bytes) */
int ParseConstantUnion(intermConstantUnion, intermTraverser, scratchR5, scratchR6, scratchR7, scratchR8)
  unsigned char * intermConstantUnion;
  unsigned char * intermTraverser;
  undefined4 scratchR5;
  undefined4 scratchR6;
  undefined4 scratchR7;
  undefined4 scratchR8;
{
  int copyIndex;
  int fillIndex;
  int nodeObjectSize;
  bool typeTemp3Live;
  bool typeTemp2Live;
  bool typeTempLive;
  bool advanceSource;
  int nodeObjectSizeB;
  uint traverserTypeBits;
  undefined4 *srcCursor;
  undefined4 srcValue;
  unsigned char * traverserField3c;
  int matrixSize;
  int totalSize;
  int instanceSize;
  int resultArray;
  int startIndex;
  undefined4 *dstCursor;
  undefined **typeTemp1 [9];
  uint typeTemp1Bits;
  undefined **typeTemp2a [6];
  int typeTemp2aStructureSize;
  uint typeTemp2aBits;
  undefined **typeTemp2b [6];
  int typeTemp2bStructureSize;
  uint typeTemp2bBits;
  undefined **typeTemp3a [9];
  uint typeTemp3aBits;
  undefined **typeTemp3b [9];
  uint typeTemp3bBits;
  
  traverserField3c = intermTraverser + 0x3c;
  traverserTypeBits = *(uint *)(intermTraverser + 0x60);
  resultArray = *(int *)(intermTraverser + 0x34);
  if ((traverserTypeBits >> 0x13 & 0x3f) == 0xe) {
    instanceSize = *(int *)(intermTraverser + 0x54);
  }
  else if ((traverserTypeBits & 0x400) == 0) {
    instanceSize = (int)(traverserTypeBits << 0xd | traverserTypeBits >> 0x13) >> 0x18;
  }
  else {
    instanceSize = (int)(traverserTypeBits << 0xd | traverserTypeBits >> 0x13) >> 0x18;
    instanceSize = instanceSize * instanceSize;
  }
  startIndex = *(int *)(intermTraverser + 0x30);
  if (startIndex < instanceSize) {
    if (*(int *)(intermTraverser + 0x68) == 0) {
      (**(code **)(*(int *)intermConstantUnion + 0x38))(typeTemp1,intermConstantUnion);
      typeTemp1[0] = &PTR___ZN5TTypeD1Ev_a7b7d488;
      if ((typeTemp1Bits >> 0x13 & 0x3f) == 0xe) {
        (**(code **)(*(int *)intermConstantUnion + 0x38))(typeTemp2a,intermConstantUnion);
      }
      else {
        (**(code **)(*(int *)intermConstantUnion + 0x38))(typeTemp2a,intermConstantUnion,scratchR5,scratchR6,scratchR7,scratchR8,traverserField3c);
        if ((typeTemp2aBits & 0x400) == 0) {
          typeTemp2aStructureSize = (int)(typeTemp2aBits << 0xd | typeTemp2aBits >> 0x13) >> 0x18;
        }
        else {
          typeTemp2aStructureSize = (int)(typeTemp2aBits << 0xd | typeTemp2aBits >> 0x13) >> 0x18;
          typeTemp2aStructureSize = typeTemp2aStructureSize * typeTemp2aStructureSize;
        }
      }
      copyIndex = 0;
      srcCursor = *(undefined4 **)(intermConstantUnion + 0x30);
      if (0 < typeTemp2aStructureSize) {
        do {
          if (instanceSize <= *(int *)(intermTraverser + 0x30)) {
            return;
          }
          srcValue = *srcCursor;
          copyIndex = copyIndex + 1;
          srcCursor = srcCursor + 1;
          *(undefined4 *)(resultArray + *(int *)(intermTraverser + 0x30) * 4) = srcValue;
          *(int *)(intermTraverser + 0x30) = *(int *)(intermTraverser + 0x30) + 1;
        } while (copyIndex < typeTemp2aStructureSize);
      }
    }
    else {
      matrixSize = *(int *)(intermTraverser + 0x80);
      totalSize = startIndex + *(int *)(intermTraverser + 0x78);
      srcCursor = *(undefined4 **)(intermConstantUnion + 0x30);
      if (*(int *)(intermTraverser + 0x7c) == 0) {
        if (startIndex < totalSize) {
          dstCursor = (undefined4 *)(startIndex * 4 + resultArray);
          do {
            if (instanceSize <= startIndex) {
              return;
            }
            advanceSource = false;
            *dstCursor = *srcCursor;
            typeTempLive = false;
            dstCursor = dstCursor + 1;
            typeTemp2Live = false;
            typeTemp3Live = false;
            *(int *)(intermTraverser + 0x30) = *(int *)(intermTraverser + 0x30) + 1;
            (**(code **)(*(int *)intermConstantUnion + 0x38))
                      (typeTemp1,intermConstantUnion,scratchR5,scratchR6,scratchR7,scratchR8,*(int *)intermConstantUnion);
            if ((typeTemp1Bits >> 0x13 & 0x3f) == 0xe) {
              typeTempLive = true;
              (**(code **)(*(int *)intermConstantUnion + 0x38))(typeTemp2b,intermConstantUnion);
              if (typeTemp2bStructureSize < 2) goto LAB_97b99bf0;
LAB_97b99c64:
              advanceSource = true;
              if (typeTemp3Live) {
LAB_97b99c70:
                typeTemp3b[0] = &PTR___ZN5TTypeD1Ev_a7b7d488;
              }
            }
            else {
LAB_97b99bf0:
              typeTemp2Live = true;
              (**(code **)(*(int *)intermConstantUnion + 0x38))(typeTemp3a,intermConstantUnion);
              if ((typeTemp3aBits >> 0x13 & 0x3f) != 0xe) {
                typeTemp3Live = true;
                (**(code **)(*(int *)intermConstantUnion + 0x38))(typeTemp3b,intermConstantUnion);
                if ((typeTemp3bBits & 0x400) == 0) {
                  nodeObjectSize = (int)(typeTemp3bBits << 0xd | typeTemp3bBits >> 0x13) >> 0x18;
                }
                else {
                  nodeObjectSize = (int)(typeTemp3bBits << 0xd | typeTemp3bBits >> 0x13) >> 0x18;
                  nodeObjectSize = nodeObjectSize * nodeObjectSize;
                }
                if (1 < nodeObjectSize) goto LAB_97b99c64;
                goto LAB_97b99c70;
              }
            }
            if (typeTemp2Live) {
              typeTemp3a[0] = &PTR___ZN5TTypeD1Ev_a7b7d488;
            }
            if (typeTempLive) {
              typeTemp2b[0] = &PTR___ZN5TTypeD1Ev_a7b7d488;
            }
            typeTemp1[0] = &PTR___ZN5TTypeD1Ev_a7b7d488;
            if (advanceSource) {
              srcCursor = srcCursor + 1;
            }
            startIndex = startIndex + 1;
          } while (startIndex < totalSize);
        }
      }
      else if (startIndex < totalSize) {
        dstCursor = (undefined4 *)(startIndex * 4 + resultArray);
        fillIndex = startIndex;
        do {
          if (instanceSize <= fillIndex) {
            return;
          }
          if ((startIndex == fillIndex) ||
             (fillIndex - startIndex == ((fillIndex - startIndex) / (matrixSize + 1)) * (matrixSize + 1))) {
            *dstCursor = *srcCursor;
          }
          else {
            *dstCursor = 0;
          }
          advanceSource = false;
          typeTempLive = false;
          *(int *)(intermTraverser + 0x30) = *(int *)(intermTraverser + 0x30) + 1;
          typeTemp2Live = false;
          typeTemp3Live = false;
          (**(code **)(*(int *)intermConstantUnion + 0x38))
                    (typeTemp1,intermConstantUnion,scratchR5,scratchR6,scratchR7,scratchR8,*(int *)intermConstantUnion);
          if ((typeTemp1Bits >> 0x13 & 0x3f) == 0xe) {
            typeTempLive = true;
            (**(code **)(*(int *)intermConstantUnion + 0x38))(typeTemp2a,intermConstantUnion);
            if (typeTemp2aStructureSize < 2) goto LAB_97b99d78;
LAB_97b99dec:
            advanceSource = true;
            if (typeTemp3Live) {
LAB_97b99df8:
              typeTemp3a[0] = &PTR___ZN5TTypeD1Ev_a7b7d488;
            }
          }
          else {
LAB_97b99d78:
            typeTemp2Live = true;
            (**(code **)(*(int *)intermConstantUnion + 0x38))(typeTemp2b,intermConstantUnion);
            if ((typeTemp2bBits >> 0x13 & 0x3f) != 0xe) {
              typeTemp3Live = true;
              (**(code **)(*(int *)intermConstantUnion + 0x38))(typeTemp3a,intermConstantUnion);
              if ((typeTemp3aBits & 0x400) == 0) {
                nodeObjectSizeB = (int)(typeTemp3aBits << 0xd | typeTemp3aBits >> 0x13) >> 0x18;
              }
              else {
                nodeObjectSizeB = (int)(typeTemp3aBits << 0xd | typeTemp3aBits >> 0x13) >> 0x18;
                nodeObjectSizeB = nodeObjectSizeB * nodeObjectSizeB;
              }
              if (1 < nodeObjectSizeB) goto LAB_97b99dec;
              goto LAB_97b99df8;
            }
          }
          if (typeTemp2Live) {
            typeTemp2b[0] = &PTR___ZN5TTypeD1Ev_a7b7d488;
          }
          if (typeTempLive) {
            typeTemp2a[0] = &PTR___ZN5TTypeD1Ev_a7b7d488;
          }
          typeTemp1[0] = &PTR___ZN5TTypeD1Ev_a7b7d488;
          if (advanceSource) {
            srcCursor = srcCursor + 1;
          }
          fillIndex = fillIndex + 1;
          dstCursor = dstCursor + 1;
        } while (fillIndex < totalSize);
      }
    }
  }
  return;
}

/* ParseLoop @ 0x97b99e48 (88 bytes) */
int ParseLoop(preVisit, intermLoop, intermTraverser)
  int preVisit;
  unsigned char * intermLoop;
  unsigned char * intermTraverser;
{
  int atomicStore;
  int *refCountPtr;
  int oldRefCount;
  uint sourceLoc;
  uint sourceLine;
  void *this;
  char reservation;
  byte cr0Flags;
  char *locString [4];
  char locTextBuf [64];
  unsigned char allocatorDummy [28];
  
  this = *(void **)(intermTraverser + 0x6c);
  sourceLoc = (*(code *)**(undefined4 **)intermLoop)(intermLoop,intermLoop,intermTraverser);
  __ZN13TInfoSinkBase6appendEPKc(this,"INTERNAL ERROR: ");
  sourceLine = sourceLoc & 0xffff;
  cr0Flags = (sourceLine == 0) << 1;
  if (sourceLine == 0) {
    _sprintf(locTextBuf,"%d:? ",(int)sourceLoc >> 0x10);
  }
  else {
    _sprintf(locTextBuf,"%d:%d",(int)sourceLoc >> 0x10,sourceLine);
  }
  __ZNSsC1EPKcRKSaIcE(locString,locTextBuf,allocatorDummy);
  locString[0][*(int *)(locString[0] + -0xc)] = *PTR__S_terminal_a7b7c0b8;
  __ZN13TInfoSinkBase6appendEPKc(this,locString[0]);
  refCountPtr = (int *)(locString[0] + -4);
  do {
    oldRefCount = *refCountPtr;
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
      *refCountPtr = atomicStore;
      cr0Flags = 2;
    }
  } while (!(bool)(cr0Flags >> 1 & 1));
  if (oldRefCount < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(locString[0] + -0xc),locTextBuf);
  }
  __ZN13TInfoSinkBase6appendEPKc(this,": ");
  __ZN13TInfoSinkBase6appendEPKc(this,"Loop Node found in constant constructor");
  __ZN13TInfoSinkBase6appendEPKc(this,"\n");
  *(undefined4 *)(intermTraverser + 0x74) = 1;
  return 0;
}

/* ParseLoop__errorReportTail @ 0x97b99eb8 (12 bytes) */
int ParseLoop__errorReportTail()
{
  bool columnIsZero;
  int atomicStore;
  int *refCountPtr;
  int oldRefCount;
  int traverser;
  char *messageText;
  uint sourceLoc;
  void *infoSink;
  int picBase;
  char reservation;
  byte cr0Flags;
  
  __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)(picBase + 0x8e94c));
  columnIsZero = (sourceLoc & 0xffff) == 0;
  cr0Flags = columnIsZero << 1;
  if (columnIsZero) {
    _sprintf(&STACKARG(0x50),(char *)(picBase + 0x8e994),(int)sourceLoc >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x50),(char *)(picBase + 0x8e98c),(int)sourceLoc >> 0x10);
  }
  __ZNSsC1EPKcRKSaIcE(&STACKARG(0x40),&STACKARG(0x50),(unsigned char *)&STACKARG(0x90));
  (*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40))[*(int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -0xc)] = **(char **)(picBase + 0xffe2260);
  __ZN13TInfoSinkBase6appendEPKc(infoSink,(*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)));
  refCountPtr = (int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -4);
  do {
    oldRefCount = *refCountPtr;
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
      *refCountPtr = atomicStore;
      cr0Flags = 2;
    }
  } while (!(bool)(cr0Flags >> 1 & 1));
  if (oldRefCount < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -0xc));
  }
  __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)(picBase + 0x8e99c));
  __ZN13TInfoSinkBase6appendEPKc(infoSink,messageText);
  __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)(picBase + 0x8cde0));
  *(undefined4 *)(traverser + 0x74) = 1;
  return 0;
}

/* ParseBranch @ 0x97b99fdc (88 bytes) */
int ParseBranch(preVisit, intermBranch, intermTraverser)
  int preVisit;
  unsigned char * intermBranch;
  unsigned char * intermTraverser;
{
  int atomicStore;
  int *refCountPtr;
  int oldRefCount;
  uint sourceLoc;
  uint sourceLine;
  void *this;
  char reservation;
  byte cr0Flags;
  char *locString [4];
  char locTextBuf [64];
  unsigned char allocatorDummy [28];
  
  this = *(void **)(intermTraverser + 0x6c);
  sourceLoc = (*(code *)**(undefined4 **)intermBranch)(intermBranch,intermBranch,intermTraverser);
  __ZN13TInfoSinkBase6appendEPKc(this,"INTERNAL ERROR: ");
  sourceLine = sourceLoc & 0xffff;
  cr0Flags = (sourceLine == 0) << 1;
  if (sourceLine == 0) {
    _sprintf(locTextBuf,"%d:? ",(int)sourceLoc >> 0x10);
  }
  else {
    _sprintf(locTextBuf,"%d:%d",(int)sourceLoc >> 0x10,sourceLine);
  }
  __ZNSsC1EPKcRKSaIcE(locString,locTextBuf,allocatorDummy);
  locString[0][*(int *)(locString[0] + -0xc)] = *PTR__S_terminal_a7b7c0b8;
  __ZN13TInfoSinkBase6appendEPKc(this,locString[0]);
  refCountPtr = (int *)(locString[0] + -4);
  do {
    oldRefCount = *refCountPtr;
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
      *refCountPtr = atomicStore;
      cr0Flags = 2;
    }
  } while (!(bool)(cr0Flags >> 1 & 1));
  if (oldRefCount < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(locString[0] + -0xc),locTextBuf);
  }
  __ZN13TInfoSinkBase6appendEPKc(this,": ");
  __ZN13TInfoSinkBase6appendEPKc(this,"Branch Node found in constant constructor");
  __ZN13TInfoSinkBase6appendEPKc(this,"\n");
  *(undefined4 *)(intermTraverser + 0x74) = 1;
  return 0;
}

/* ParseBranch__errorReportTail @ 0x97b9a04c (12 bytes) */
int ParseBranch__errorReportTail()
{
  bool columnIsZero;
  int atomicStore;
  int *refCountPtr;
  int oldRefCount;
  int traverser;
  char *messageText;
  uint sourceLoc;
  void *infoSink;
  int picBase;
  char reservation;
  byte cr0Flags;
  
  __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)(picBase + 0x8e7b8));
  columnIsZero = (sourceLoc & 0xffff) == 0;
  cr0Flags = columnIsZero << 1;
  if (columnIsZero) {
    _sprintf(&STACKARG(0x50),(char *)(picBase + 0x8e800),(int)sourceLoc >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x50),(char *)(picBase + 0x8e7f8),(int)sourceLoc >> 0x10);
  }
  __ZNSsC1EPKcRKSaIcE(&STACKARG(0x40),&STACKARG(0x50),(unsigned char *)&STACKARG(0x90));
  (*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40))[*(int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -0xc)] = **(char **)(picBase + 0xffe20cc);
  __ZN13TInfoSinkBase6appendEPKc(infoSink,(*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)));
  refCountPtr = (int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -4);
  do {
    oldRefCount = *refCountPtr;
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
      *refCountPtr = atomicStore;
      cr0Flags = 2;
    }
  } while (!(bool)(cr0Flags >> 1 & 1));
  if (oldRefCount < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -0xc));
  }
  __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)(picBase + 0x8e808));
  __ZN13TInfoSinkBase6appendEPKc(infoSink,messageText);
  __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)(picBase + 0x8cc4c));
  *(undefined4 *)(traverser + 0x74) = 1;
  return 0;
}

/* TIntermediate__parseConstTree @ 0x97b9a170 (428 bytes) */
int TIntermediate__parseConstTree(this, unusedLine, intermNode, constUnion, op, symbolTable, type, singleConstantParam)
  unsigned char * this;
  int unusedLine;
  unsigned char * intermNode;
  unsigned char * constUnion;
  undefined4 op;
  undefined4 symbolTable;
  int type;
  undefined4 singleConstantParam;
{
  undefined4 result;
  uint typeBits;
  undefined4 visitSymbolFn;
  undefined4 visitConstantUnionFn;
  undefined4 visitBinaryFn;
  undefined4 visitUnaryFn;
  undefined4 visitSelectionFn;
  undefined4 visitAggregateFn;
  undefined4 visitLoopFn;
  undefined4 visitBranchFn;
  undefined4 depth;
  undefined4 preVisit;
  undefined4 postVisit;
  undefined4 rightToLeft;
  undefined4 index;
  unsigned char * unionArray;
  undefined4 unusedField38;
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
  undefined4 travConstructorType;
  undefined4 travSingleConstantParam;
  undefined4 travInfoSink;
  undefined4 travSymbolTable;
  int errorFlag;
  undefined4 isMatrix;
  undefined4 matrixSize;
  
  result = 0;
  if (intermNode != (unsigned char *)0x0) {
    typeBits = *(uint *)(type + 0x24);
    travInfoSink = *(undefined4 *)this;
    stackTypeStructure = *(undefined4 *)(type + 8);
    stackTypeFieldName = *(undefined4 *)(type + 0xc);
    stackTypeTypeName = *(undefined4 *)(type + 0x10);
    stackTypeArraySize = *(undefined4 *)(type + 4);
    stackTypeWord14 = *(undefined4 *)(type + 0x14);
    stackTypeBits = (typeBits >> 9 & 1) << 9 |
               (typeBits >> 10 & 1) << 10 |
               typeBits & 0x7f800 |
               (typeBits >> 0x13 & 0x3f) << 0x13 | typeBits & 0xfe000000 | stackTypeBits & 0x1ff;
    stackTypeStructureSize = *(undefined4 *)(type + 0x18);
    stackTypeWord1c = *(undefined4 *)(type + 0x1c);
    stackTypeWord20 = *(undefined4 *)(type + 0x20);
    preVisit = 1;
    depth = 0;
    postVisit = 0;
    rightToLeft = 0;
    errorFlag = 0;
    isMatrix = 0;
    matrixSize = 0;
    stackType = &PTR___ZN5TTypeD1Ev_a7b7d488;
    index = 0;
    unusedField38 = 0;
    visitAggregateFn = DAT_a7b7ba0c;
    visitBinaryFn = DAT_a7b7ba08;
    visitConstantUnionFn = DAT_a7b7ba04;
    visitSelectionFn = DAT_a7b7ba00;
    visitSymbolFn = DAT_a7b7b9fc;
    visitUnaryFn = DAT_a7b7b9f8;
    visitLoopFn = DAT_a7b7b9f4;
    visitBranchFn = DAT_a7b7b9f0;
    unionArray = constUnion;
    travConstructorType = op;
    travSingleConstantParam = singleConstantParam;
    travSymbolTable = symbolTable;
    (**(code **)(*(int *)intermNode + 8))
              (intermNode,&visitSymbolFn,stackTypeWord14,stackTypeTypeName,stackTypeFieldName,stackTypeStructure,DAT_a7b7b9f0,stackTypeArraySize);
    if (errorFlag == 0) {
      result = 0;
    }
    else {
      result = 1;
    }
  }
  return result;
}

/* TParseContext__parseVectorFields @ 0x97b9a31c (612 bytes) */
int TParseContext__parseVectorFields(this, text, vecSize, vectorFields, line)
  unsigned char * this;
  unsigned char * text;
  int vecSize;
  unsigned char * vectorFields;
  int line;
{
  undefined4 result;
  int textCharsB;
  int fieldValue;
  int errTextLength;
  int componentIndex;
  int textChars;
  byte terminalChar;
  int fieldCount;
  int textLengthB;
  undefined4 fieldSetId;
  char *errorMessage;
  char *errorToken;
  int fieldIndex;
  int *fieldSetCursor;
  int fieldSets [8];
  
  fieldCount = *(int *)(*(int *)(text + 4) + -0xc);
  *(int *)(vectorFields + 0x10) = fieldCount;
  if (fieldCount < 5) {
    fieldIndex = 0;
    if (fieldCount < 1) {
      fieldCount = *(int *)(vectorFields + 0x10);
    }
    else {
      do {
        textChars = *(int *)(text + 4);
        switch(*(char *)(textChars + fieldIndex) + -0x61) {
        case '\0':
          componentIndex = 1;
          break;
        case '\x01':
          componentIndex = 1;
          goto LAB_97b9a4dc;
        default:
          textLengthB = *(int *)(textChars + -0xc);
          goto LAB_97b9a54c;
        case '\x06':
          componentIndex = 1;
          goto LAB_97b9a4f0;
        case '\x0f':
          componentIndex = 2;
          goto LAB_97b9a4f0;
        case '\x10':
          componentIndex = 2;
          break;
        case '\x11':
          componentIndex = 1;
          goto LAB_97b9a490;
        case '\x12':
          componentIndex = 2;
LAB_97b9a490:
          fieldSetId = 0;
          goto LAB_97b9a528;
        case '\x13':
          componentIndex = 2;
          goto LAB_97b9a4bc;
        case '\x16':
          componentIndex = 0;
          break;
        case '\x17':
          componentIndex = 0;
LAB_97b9a4f0:
          fieldSets[fieldIndex + 1] = componentIndex;
          *(int *)(vectorFields + fieldIndex * 4) = componentIndex;
          goto LAB_97b9a570;
        case '\x18':
          componentIndex = 0;
LAB_97b9a4bc:
          fieldSetId = 1;
          goto LAB_97b9a528;
        case '\x19':
          componentIndex = 0;
LAB_97b9a4dc:
          fieldSetId = 2;
          goto LAB_97b9a528;
        }
        fieldSetId = 3;
LAB_97b9a528:
        fieldSets[fieldIndex + 1] = componentIndex;
        *(undefined4 *)(vectorFields + fieldIndex * 4) = fieldSetId;
LAB_97b9a570:
        fieldCount = *(int *)(vectorFields + 0x10);
        fieldIndex = fieldIndex + 1;
      } while (fieldIndex < fieldCount);
    }
    fieldIndex = 0;
    if (0 < fieldCount) {
      fieldSetCursor = fieldSets;
      do {
        fieldValue = *(int *)vectorFields;
        vectorFields = vectorFields + 4;
        if (vecSize <= fieldValue) {
          textCharsB = *(int *)(text + 4);
          errTextLength = *(int *)(textCharsB + -0xc);
          terminalChar = *DAT_a7b7ba18;
          errorMessage = "vector field selection out of range";
LAB_97b9a3b8:
          *(byte *)(textCharsB + errTextLength) = terminalChar;
          errorToken = *(char **)(text + 4);
          goto LAB_97b9a560;
        }
        if ((0 < fieldIndex) && (fieldSetCursor[1] != *fieldSetCursor)) {
          textCharsB = *(int *)(text + 4);
          errTextLength = *(int *)(textCharsB + -0xc);
          terminalChar = *DAT_a7b7ba18;
          errorMessage = "illegal - vector component fields not from the same set";
          goto LAB_97b9a3b8;
        }
        fieldIndex = fieldIndex + 1;
        fieldSetCursor = fieldSetCursor + 1;
      } while (fieldIndex < fieldCount);
    }
    result = 1;
  }
  else {
    textChars = *(int *)(text + 4);
    textLengthB = *(int *)(textChars + -0xc);
LAB_97b9a54c:
    terminalChar = *DAT_a7b7ba18;
    *(byte *)(textChars + textLengthB) = terminalChar;
    errorToken = *(char **)(text + 4);
    errorMessage = "illegal vector field selection";
LAB_97b9a560:
    error((int)this,(char *)line,errorMessage,errorToken,"",line,(uint)terminalChar,fieldIndex);
    result = 0;
  }
  return result;
}

/* TParseContext__parseMatrixFields @ 0x97b9a5e8 (464 bytes) */
int TParseContext__parseMatrixFields(this, text, matSize, matrixFields, line)
  unsigned char * this;
  unsigned char * text;
  int matSize;
  unsigned char * matrixFields;
  int line;
{
  char secondChar;
  int firstChar;
  char *errorMessage;
  uint fieldTextLengthReg;
  char *textChars;
  
  *(undefined4 *)(matrixFields + 4) = 0;
  *(undefined4 *)(matrixFields + 0xc) = 0xffffffff;
  *(undefined4 *)matrixFields = 0;
  *(undefined4 *)(matrixFields + 8) = 0xffffffff;
  textChars = *(char **)(text + 4);
  fieldTextLengthReg = *(uint *)(textChars + -0xc);
  if (fieldTextLengthReg == 2) {
    firstChar = (int)*textChars;
    if (firstChar == 0x5f) {
      if (('/' < textChars[1]) && (textChars[1] < '4')) {
        *(undefined4 *)(matrixFields + 4) = 1;
LAB_97b9a738:
        *(int *)(matrixFields + 0xc) = *(char *)(*(int *)(text + 4) + 1) + -0x30;
LAB_97b9a74c:
        if ((*(int *)(matrixFields + 8) < matSize) && (*(int *)(matrixFields + 0xc) < matSize)) {
          return 1;
        }
        fieldTextLengthReg = (uint)*DAT_a7b7ba18;
        errorMessage = "matrix field selection out of range";
        *(byte *)(*(int *)(text + 4) + *(int *)(*(int *)(text + 4) + -0xc)) = *DAT_a7b7ba18;
        goto LAB_97b9a790;
      }
LAB_97b9a6a4:
      textChars[2] = *DAT_a7b7ba18;
    }
    else {
      secondChar = textChars[1];
      if (secondChar == '_') {
        if ((0x2f < firstChar) && (firstChar < 0x34)) {
          *(undefined4 *)matrixFields = 1;
          *(int *)(matrixFields + 8) = **(char **)(text + 4) + -0x30;
          goto LAB_97b9a74c;
        }
        goto LAB_97b9a6a4;
      }
      if ((((0x2f < firstChar) && (firstChar < 0x34)) && ('/' < secondChar)) && (secondChar < '4')) {
        *(int *)(matrixFields + 8) = firstChar + -0x30;
        goto LAB_97b9a738;
      }
      fieldTextLengthReg = (uint)*DAT_a7b7ba18;
      textChars[*(int *)(textChars + -0xc)] = *DAT_a7b7ba18;
    }
    textChars = *(char **)(text + 4);
    errorMessage = "illegal matrix field selection";
  }
  else {
    errorMessage = "illegal length of matrix field selection";
    textChars[fieldTextLengthReg] = *DAT_a7b7ba18;
LAB_97b9a790:
    textChars = *(char **)(text + 4);
  }
  error((int)this,(char *)line,errorMessage,textChars,"",this,fieldTextLengthReg,line);
  return 0;
}

/* TParseContext__recover @ 0x97b9a7b8 (12 bytes) */
int TParseContext__recover(this)
  unsigned char * this;
{
  *(undefined4 *)(this + 0x14) = 1;
  return;
}

/* TParseContext__error @ 0x97b9a7c4 (104 bytes) */
int TParseContext__error(this, sourceLoc, reason, str, extraInfoFormat, varArg1, varArg2, varArg3)
  int this;
  char *sourceLoc;
  char *reason;
  char *str;
  char *extraInfoFormat;
  undefined4 varArg1;
  undefined4 varArg2;
  undefined4 varArg3;
{
  unsigned int ghidra_home[8] = { this, sourceLoc, reason, str, extraInfoFormat, varArg1, varArg2, varArg3 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  int atomicStore;
  int *refCountPtr;
  int oldRefCount;
  uint sourceLine;
  void *infoSink;
  char reservation;
  byte cr0Flags;
  char formattedInfoBuf [400];
  char *locString [4];
  char locTextBuf [64];
  unsigned char allocatorDummy [24];
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 20)) = varArg1;
  (*(unsigned int *)((unsigned char *)ghidra_home + 24)) = varArg2;
  (*(unsigned int *)((unsigned char *)ghidra_home + 28)) = varArg3;
  _vsnprintf(formattedInfoBuf,400,extraInfoFormat,&(*(unsigned int *)((unsigned char *)ghidra_home + 20)));
  __ZN13TInfoSinkBase6appendEPKc(*(void **)(this + 8),"ERROR: ");
  infoSink = *(void **)(this + 8);
  sourceLine = (uint)sourceLoc & 0xffff;
  cr0Flags = (sourceLine == 0) << 1;
  if (sourceLine == 0) {
    _sprintf(locTextBuf,"%d:? ",(int)sourceLoc >> 0x10);
  }
  else {
    _sprintf(locTextBuf,"%d:%d",(int)sourceLoc >> 0x10,sourceLine);
  }
  __ZNSsC1EPKcRKSaIcE(locString,locTextBuf,allocatorDummy);
  locString[0][*(int *)(locString[0] + -0xc)] = *PTR__S_terminal_a7b7c0b8;
  __ZN13TInfoSinkBase6appendEPKc(infoSink,locString[0]);
  refCountPtr = (int *)(locString[0] + -4);
  do {
    oldRefCount = *refCountPtr;
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
      *refCountPtr = atomicStore;
      cr0Flags = 2;
    }
  } while (!(bool)(cr0Flags >> 1 & 1));
  if (oldRefCount < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(locString[0] + -0xc));
  }
  __ZN13TInfoSinkBase6appendEPKc(infoSink,": ");
  infoSink = *(void **)(this + 8);
  __ZN13TInfoSinkBase6appendEPKc(infoSink,"\'");
  __ZN13TInfoSinkBase6appendEPKc(infoSink,str);
  __ZN13TInfoSinkBase6appendEPKc(infoSink,"\' : ");
  __ZN13TInfoSinkBase6appendEPKc(infoSink,reason);
  __ZN13TInfoSinkBase6appendEPKc(infoSink," ");
  __ZN13TInfoSinkBase6appendEPKc(infoSink,formattedInfoBuf);
  __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
  *(int *)(this + 0x18) = *(int *)(this + 0x18) + 1;
  return;
}

/* TParseContext__error__tail @ 0x97b9a844 (12 bytes) */
int TParseContext__error__tail(infoSink)
  void *infoSink;
{
  bool columnIsZero;
  int atomicStore;
  int *refCountPtr;
  int oldRefCount;
  char *reason;
  char *token;
  uint sourceLoc;
  void *infoSink2;
  int parseContext;
  int picBase;
  char reservation;
  byte cr0Flags;
  
  __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)(picBase + 0x8dfd0));
  infoSink2 = *(void **)(parseContext + 8);
  columnIsZero = (sourceLoc & 0xffff) == 0;
  cr0Flags = columnIsZero << 1;
  if (columnIsZero) {
    _sprintf(&STACKARG(0x1e0),(char *)(picBase + 0x8e018),(int)sourceLoc >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x1e0),(char *)(picBase + 0x8e010),(int)sourceLoc >> 0x10);
  }
  __ZNSsC1EPKcRKSaIcE(&STACKARG(0x1d0),&STACKARG(0x1e0),(unsigned char *)&STACKARG(0x220));
  (*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x1d0))[*(int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x1d0)) + -0xc)] = **(char **)(picBase + 0xffe18e4);
  __ZN13TInfoSinkBase6appendEPKc(infoSink2,(*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x1d0)));
  refCountPtr = (int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x1d0)) + -4);
  do {
    oldRefCount = *refCountPtr;
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
      *refCountPtr = atomicStore;
      cr0Flags = 2;
    }
  } while (!(bool)(cr0Flags >> 1 & 1));
  if (oldRefCount < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x1d0)) + -0xc));
  }
  __ZN13TInfoSinkBase6appendEPKc(infoSink2,(char *)(picBase + 0x8e020));
  infoSink2 = *(void **)(parseContext + 8);
  __ZN13TInfoSinkBase6appendEPKc(infoSink2,(char *)(picBase + 0x8e9e0));
  __ZN13TInfoSinkBase6appendEPKc(infoSink2,token);
  __ZN13TInfoSinkBase6appendEPKc(infoSink2,(char *)(picBase + 0x8e9e4));
  __ZN13TInfoSinkBase6appendEPKc(infoSink2,reason);
  __ZN13TInfoSinkBase6appendEPKc(infoSink2,(char *)(picBase + 0x8e9ec));
  __ZN13TInfoSinkBase6appendEPKc(infoSink2,&STACKARG(0x40));
  __ZN13TInfoSinkBase6appendEPKc(infoSink2,(char *)(picBase + 0x8c464));
  *(int *)(parseContext + 0x18) = *(int *)(parseContext + 0x18) + 1;
  return;
}

/* TParseContext__assignError @ 0x97b9a9b4 (96 bytes) */
int TParseContext__assignError(this, sourceLoc, str, text1, text2)
  unsigned char * this;
  int sourceLoc;
  char *str;
  int text1;
  int text2;
{
  byte terminalChar;
  byte *terminalPtr;
  undefined4 text1Chars;
  
  terminalPtr = DAT_a7b7ba18;
  *(byte *)(*(int *)(text1 + 4) + *(int *)(*(int *)(text1 + 4) + -0xc)) = *DAT_a7b7ba18;
  terminalChar = *terminalPtr;
  text1Chars = *(undefined4 *)(text1 + 4);
  *(byte *)(*(int *)(text2 + 4) + *(int *)(*(int *)(text2 + 4) + -0xc)) = terminalChar;
  return error((int)this,(char *)sourceLoc,"",str,"cannot convert from \'%s\' to \'%s\'",
        *(undefined4 *)(text2 + 4),text1Chars,(uint)terminalChar);
}

/* TParseContext__unaryOpError @ 0x97b9aa14 (84 bytes) */
int TParseContext__unaryOpError(this, sourceLoc, str, text)
  unsigned char * this;
  int sourceLoc;
  char *str;
  int text;
{
  *(undefined1 *)(*(int *)(text + 4) + *(int *)(*(int *)(text + 4) + -0xc)) = *DAT_a7b7ba18;
  return error((int)this,(char *)sourceLoc," wrong operand type",str,
        "no operation \'%s\' exists that takes an operand of type %s (or there is no acceptable conversion)"
        ,str,*(undefined4 *)(text + 4),text);
}

/* TParseContext__binaryOpError @ 0x97b9aa68 (104 bytes) */
int TParseContext__binaryOpError(this, sourceLoc, str, text1, text2)
  unsigned char * this;
  int sourceLoc;
  char *str;
  int text1;
  int text2;
{
  undefined1 *terminalPtr;
  undefined4 text2Chars;
  
  terminalPtr = DAT_a7b7ba18;
  *(undefined1 *)(*(int *)(text2 + 4) + *(int *)(*(int *)(text2 + 4) + -0xc)) = *DAT_a7b7ba18;
  text2Chars = *(undefined4 *)(text2 + 4);
  *(undefined1 *)(*(int *)(text1 + 4) + *(int *)(*(int *)(text1 + 4) + -0xc)) = *terminalPtr;
  return error((int)this,(char *)sourceLoc," wrong operand types ",str,
        "no operation \'%s\' exists that takes a left-hand operand of type \'%s\' and a right operand of type \'%s\' (or there is no acceptable conversion)"
        ,str,*(undefined4 *)(text1 + 4),text2Chars);
}

/* TParseContext__lValueErrorCheck @ 0x97b9aad0 (944 bytes) */
int TParseContext__lValueErrorCheck(this, sourceLoc, str, intermTyped, scratchR7, scratchR8, scratchR9, scratchR10)
  unsigned char * this;
  int sourceLoc;
  char *str;
  unsigned char * intermTyped;
  undefined4 scratchR7;
  undefined4 scratchR8;
  uint scratchR9;
  undefined4 scratchR10;
{
  unsigned char *leftOperand;
  int *swizzleElement;
  int *swizzleAggregate;
  char *errorReason;
  int componentSeenCount;
  int swizzleSequence;
  int binaryOp;
  int basicType;
  int lValueErrorCheckResult;
  bool hasSymbolNode;
  int symbolName;
  int *symbolNode;
  int *binaryNode;
  unsigned char *intermTypedCopy;
  int componentConstUnion;
  uint qualifier;
  undefined4 r4Out0;
  undefined4 r4Out1;
  undefined4 staleR4;
  undefined4 sourceLocCopy;
  char *tokenCopy;
  char *extraInfoFormat;
  undefined4 *elementCursor;
  undefined4 symbolNameChars;
  char *modifyReason;
  int componentSeen [4];
  
  tokenCopy = str;
  intermTypedCopy = intermTyped;
  symbolNode = (int *)(**(code **)(*(int *)intermTyped + 0x28))(intermTyped);
  binaryNode = (int *)(**(code **)(*(int *)intermTyped + 0x20))(intermTyped);
  if (binaryNode == (int *)0x0) {
    hasSymbolNode = symbolNode != (int *)0x0;
    symbolNameChars = 0;
    staleR4 = r4Out0;
    if (hasSymbolNode) {
      symbolName = (**(code **)(*symbolNode + 0x60))(symbolNode);
      scratchR9 = (uint)*DAT_a7b7ba18;
      *(byte *)(*(int *)(symbolName + 4) + *(int *)(*(int *)(symbolName + 4) + -0xc)) = *DAT_a7b7ba18;
      symbolNameChars = *(undefined4 *)(symbolName + 4);
      staleR4 = r4Out1;
    }
    modifyReason = (char *)0x0;
    qualifier = (**(code **)(*(int *)intermTyped + 0x44))(intermTyped,staleR4,tokenCopy,intermTypedCopy,scratchR7,scratchR8,scratchR9);
    if (qualifier < 0x12) {
      scratchR9 = qualifier * 4;
      switch(qualifier) {
      default:
        goto switchD_97b9ace4_caseD_0;
      case 2:
      case 0xc:
        modifyReason = "can\'t modify a const";
        break;
      case 3:
        modifyReason = "can\'t modify an attribute";
        break;
      case 4:
        modifyReason = "can\'t modify a varying";
        break;
      case 6:
        modifyReason = "can\'t modify a uniform";
        break;
      case 7:
        modifyReason = "can\'t modify an input";
        break;
      case 0x10:
        modifyReason = "can\'t modify gl_FrontFace";
        break;
      case 0x11:
        modifyReason = "can\'t modify gl_FragCoord";
      }
    }
    else {
switchD_97b9ace4_caseD_0:
      basicType = (**(code **)(*(int *)intermTyped + 0x40))
                        (intermTyped,sourceLocCopy,tokenCopy,intermTypedCopy,scratchR7,scratchR8,scratchR9);
      if (basicType - 5U < 8) {
        modifyReason = "can\'t modify a sampler";
      }
      else {
        basicType = (**(code **)(*(int *)intermTyped + 0x40))(intermTyped);
        if (basicType == 0) {
          modifyReason = "can\'t modify void";
        }
        else {
          basicType = (**(code **)(*(int *)intermTyped + 0x40))(intermTyped);
          if (basicType == 0xf) {
            modifyReason = "can\'t modify an address";
          }
        }
      }
    }
    if (modifyReason != (char *)0x0) {
      if (hasSymbolNode) {
        error((int)this,(char *)sourceLoc," l-value required",str,"\"%s\" (%s)",symbolNameChars,modifyReason,
              scratchR10);
        return 1;
      }
      errorReason = " l-value required";
      extraInfoFormat = "(%s)";
      goto LAB_97b9aea4;
    }
    if (hasSymbolNode) {
      return 0;
    }
LAB_97b9ae0c:
    errorReason = " l-value required";
  }
  else {
    binaryOp = binaryNode[0xc];
    if (binaryOp < 0x2d) goto LAB_97b9ae0c;
    if (binaryOp < 0x30) {
      leftOperand = (unsigned char *)(**(code **)(*binaryNode + 0x68))(binaryNode);
      lValueErrorCheckResult = ((int (*)())TParseContext__lValueErrorCheck)(this,sourceLoc,str,leftOperand,scratchR7,scratchR8,scratchR9,scratchR10);
      return lValueErrorCheckResult;
    }
    if (binaryOp != 0x30) goto LAB_97b9ae0c;
    leftOperand = (unsigned char *)(**(code **)(*binaryNode + 0x68))(binaryNode);
    componentSeen[0] = ((int (*)())TParseContext__lValueErrorCheck)(this,sourceLoc,str,leftOperand,scratchR7,scratchR8,scratchR9,scratchR10);
    if (componentSeen[0] != 0) {
      return componentSeen[0];
    }
    componentSeen[1] = componentSeen[0];
    componentSeen[2] = componentSeen[0];
    componentSeen[3] = componentSeen[0];
    swizzleAggregate = (int *)(**(code **)(*binaryNode + 0x6c))(binaryNode);
    swizzleAggregate = (int *)(**(code **)(*swizzleAggregate + 0x1c))(swizzleAggregate);
    swizzleSequence = (**(code **)(*swizzleAggregate + 100))(swizzleAggregate);
    elementCursor = *(undefined4 **)(swizzleSequence + 4);
    while( true ) {
      swizzleSequence = (**(code **)(*swizzleAggregate + 100))(swizzleAggregate);
      if (elementCursor == *(undefined4 **)(swizzleSequence + 8)) {
        return 0;
      }
      swizzleElement = (int *)(**(code **)(*(int *)*elementCursor + 0x14))((int *)*elementCursor);
      componentConstUnion = (**(code **)(*swizzleElement + 0x18))(swizzleElement);
      componentSeenCount = componentSeen[**(int **)(componentConstUnion + 0x30)];
      componentSeen[**(int **)(componentConstUnion + 0x30)] = componentSeenCount + 1;
      if (1 < componentSeenCount + 1) break;
      elementCursor = elementCursor + 1;
    }
    errorReason = " l-value of swizzle cannot have duplicate components";
  }
  extraInfoFormat = "";
  modifyReason = extraInfoFormat;
LAB_97b9aea4:
  error((int)this,(char *)sourceLoc,errorReason,str,extraInfoFormat,modifyReason,scratchR9,scratchR10);
  return 1;
}

/* TParseContext__constErrorCheck @ 0x97b9aec8 (140 bytes) */
int TParseContext__constErrorCheck(this, intermTyped)
  unsigned char * this;
  unsigned char * intermTyped;
{
  int qualifier;
  char *sourceLoc;
  undefined4 scratchR8;
  undefined4 scratchR9;
  undefined4 scratchR10;
  
  qualifier = (**(code **)(*(int *)intermTyped + 0x44))(intermTyped,intermTyped);
  if (qualifier != 2) {
    sourceLoc = (char *)(*(code *)**(undefined4 **)intermTyped)(intermTyped);
    error((int)this,sourceLoc,"constant expression required","","",scratchR8,scratchR9,scratchR10);
  }
  return qualifier != 2;
}

/* TParseContext__integerErrorCheck @ 0x97b9af54 (172 bytes) */
int TParseContext__integerErrorCheck(this, intermTyped, str)
  unsigned char * this;
  unsigned char * intermTyped;
  char *str;
{
  int basicTypeThenSize;
  char *sourceLoc;
  undefined4 scratchR8;
  undefined4 scratchR9;
  undefined4 scratchR10;
  
  basicTypeThenSize = (**(code **)(*(int *)intermTyped + 0x40))(intermTyped,intermTyped,str);
  if ((basicTypeThenSize == 2) && (basicTypeThenSize = (**(code **)(*(int *)intermTyped + 0x48))(intermTyped), basicTypeThenSize == 1)) {
    return 0;
  }
  sourceLoc = (char *)(*(code *)**(undefined4 **)intermTyped)(intermTyped);
  error((int)this,sourceLoc,"integer expression required",str,"",scratchR8,scratchR9,scratchR10);
  return 1;
}

/* TParseContext__globalErrorCheck @ 0x97b9b000 (84 bytes) */
int TParseContext__globalErrorCheck(this, sourceLoc, isGlobalScope, str, scratchR7, scratchR8)
  unsigned char * this;
  int sourceLoc;
  int isGlobalScope;
  char *str;
  undefined4 scratchR7;
  undefined4 scratchR8;
{
  undefined4 scratchR9;
  undefined4 scratchR10;
  
  if (isGlobalScope == 0) {
    error((int)this,(char *)sourceLoc,"only allowed at global scope",str,"",scratchR8,scratchR9,scratchR10);
  }
  return isGlobalScope == 0;
}

/* TParseContext__reservedErrorCheck @ 0x97b9b054 (376 bytes) */
int TParseContext__reservedErrorCheck(this, sourceLoc, text)
  unsigned char * this;
  int sourceLoc;
  unsigned char * text;
{
  int compareResult;
  int atomicStore;
  int levelCount;
  int *refCountPtr;
  int oldRefCount;
  uint *minLengthPtr;
  undefined4 scratchR8;
  undefined4 scratchR10;
  uint reservedPrefixLength;
  uint namePrefixLength;
  char reservation;
  byte cr0Flags;
  undefined4 namePrefix;
  int namePrefixChars;
  undefined4 reservedPrefix;
  int reservedPrefixChars;
  undefined4 allocatorArg [4];
  undefined4 destroyArgA [4];
  undefined4 destroyArgB [4];
  uint prefixLength;
  uint prefixLengths [4];
  
  levelCount = (*(int **)(this + 4))[1] - **(int **)(this + 4) >> 2;
  if ((levelCount != 1) && (levelCount != 2)) {
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_mm(&namePrefix,text,0,3);
    allocatorArg[0] = GetGlobalPoolAllocator();
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_(&reservedPrefix,"gl_",(unsigned char *)allocatorArg)
    ;
    minLengthPtr = prefixLengths;
    reservedPrefixLength = *(uint *)(reservedPrefixChars + -0xc);
    prefixLength = reservedPrefixLength;
    namePrefixLength = *(uint *)(namePrefixChars + -0xc);
    prefixLengths[0] = namePrefixLength;
    if (reservedPrefixLength <= namePrefixLength) {
      minLengthPtr = &prefixLength;
    }
    compareResult = _memcmp(reservedPrefixChars,namePrefixChars,*minLengthPtr);
    cr0Flags = (compareResult == 0) << 1;
    if (compareResult == 0) {
      compareResult = reservedPrefixLength - namePrefixLength;
    }
    refCountPtr = (int *)(reservedPrefixChars + -4);
    destroyArgA[0] = reservedPrefix;
    do {
      oldRefCount = *refCountPtr;
      if (reservation != '\0') {
        atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
        *refCountPtr = atomicStore;
        cr0Flags = 2;
      }
    } while (!(bool)(cr0Flags >> 1));
    if (oldRefCount < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(reservedPrefixChars + -0xc),destroyArgA);
    }
    refCountPtr = (int *)(namePrefixChars + -4);
    destroyArgB[0] = namePrefix;
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
                ((unsigned char *)(namePrefixChars + -0xc),destroyArgB);
    }
    if (compareResult == 0) {
      error((int)this,(char *)sourceLoc,"reserved built-in name","gl_","",scratchR8,namePrefixChars,scratchR10);
      return 1;
    }
  }
  return 0;
}

/* TParseContext__constructorErrorCheck @ 0x97b9b1cc (2036 bytes) */
int TParseContext__constructorErrorCheck(this, sourceLoc, intermNode, function, op, type)
  unsigned char * this;
  int sourceLoc;
  unsigned char * intermNode;
  unsigned char * function;
  int op;
  int *type;
{
  int argBasicType;
  int paramIsArray;
  int paramTypeVtable;
  int *argTyped;
  char *errorReason;
  int totalSize;
  int paramSizeResult;
  int *refCountPtr;
  int oldRefCount;
  int newRefCount;
  int paramOffset;
  bool full;
  bool constType;
  bool arrayArg;
  bool matrixInMatrix;
  bool overFull;
  int *paramType;
  int ctorNominalSize;
  unsigned char * functionName;
  unsigned char * poolAllocator;
  void *newTypeNameString;
  uint *functionParam;
  int r4Out0;
  int r4Out1;
  int r4Out2;
  undefined4 sourceLocCopy;
  undefined4 r4Out3;
  undefined4 r4Out4;
  undefined4 sourceLocCopy2;
  int r4Out5;
  int r4Out6;
  int r4Out7;
  undefined4 sourceLocCopy3;
  undefined4 r4Out8;
  undefined4 scratchR4;
  unsigned char * scratchR5;
  char *structNameChars;
  unsigned char * functionCopy;
  char *errorToken;
  int opCopy;
  char *extraInfoFormat;
  int *typeCopy;
  uint constructorScratch;
  uint ctorTypeBits;
  int paramTypeVtableArg;
  int scratchR10;
  unsigned char * structFieldList;
  int paramIndex;
  char reservation;
  byte cr0Flags;
  undefined8 allocPair;
  undefined **stackType;
  int stackTypeArraySize;
  unsigned char * stackTypeStructure;
  int stackTypeFieldName;
  void *stackTypeTypeName;
  int stackTypeWord14;
  int stackTypeStructureSize;
  int stackTypeWord1c;
  int stackTypeWord20;
  uint stackTypeBits;
  undefined4 nameCopy1;
  int savedR10;
  undefined4 nameCopy2;
  char *nameCopy2Chars;
  undefined4 allocatorArg [4];
  undefined4 destroyArgA [4];
  undefined4 destroyArgB [4];
  
  constructorScratch = op - 0x66;
  paramSizeResult = sourceLoc;
  scratchR5 = intermNode;
  functionCopy = function;
  opCopy = op;
  typeCopy = type;
  switch(constructorScratch) {
  case 0:
    ctorTypeBits = stackTypeBits & 0xfff | 0x100800;
    goto LAB_97b9b330;
  case 1:
    ctorNominalSize = 1;
    ctorTypeBits = stackTypeBits & 0x1fffff | 0x180000;
    break;
  case 2:
    ctorNominalSize = 1;
    goto LAB_97b9b2f0;
  case 3:
    ctorTypeBits = stackTypeBits & 0xfffff | 0x80000;
    goto LAB_97b9b2e4;
  case 4:
    ctorNominalSize = 3;
    ctorTypeBits = stackTypeBits & 0xfffff | 0x80000;
    break;
  case 5:
    ctorTypeBits = stackTypeBits & 0xfffff | 0x80000;
    goto LAB_97b9b3cc;
  case 6:
    ctorTypeBits = stackTypeBits & 0x1fffff | 0x180000;
LAB_97b9b2e4:
    ctorNominalSize = 2;
    break;
  case 7:
    ctorNominalSize = 3;
    goto LAB_97b9b2f0;
  case 8:
    ctorTypeBits = stackTypeBits & 0x1fffff | 0x180000;
    goto LAB_97b9b3cc;
  case 9:
    ctorNominalSize = 2;
LAB_97b9b2f0:
    ctorTypeBits = ctorNominalSize << 0x13 | stackTypeBits & 0x7ffff;
    break;
  case 10:
    ctorTypeBits = stackTypeBits & 0x1fff | 0x101800;
LAB_97b9b330:
    constructorScratch = 0;
    stackTypeBits = ctorTypeBits & 0xfffff9ff;
    savedR10 = stackTypeBits << 0xd;
    typeCopy = (int *)0x0;
    type[8] = 0;
    type[9] = ctorTypeBits & 0x7f800 | ctorTypeBits & 0xfff80000 | type[9] & 0x1ffU;
    stackTypeArraySize = 0;
    stackTypeStructure = (unsigned char *)0x0;
    stackTypeFieldName = 0;
    stackTypeTypeName = (void *)0x0;
    stackTypeWord14 = 0;
    stackTypeStructureSize = 0;
    stackTypeWord1c = 0;
    stackType = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
    stackTypeWord20 = 0;
    type[1] = 0;
    type[2] = 0;
    type[3] = 0;
    type[4] = 0;
    type[5] = 0;
    type[6] = 0;
    type[7] = 0;
    goto LAB_97b9b714;
  case 0xb:
    ctorTypeBits = stackTypeBits & 0x7ffff | 0x100000;
LAB_97b9b3cc:
    ctorNominalSize = 4;
    break;
  case 0xc:
    ctorNominalSize = 2;
    goto LAB_97b9b490;
  case 0xd:
    ctorTypeBits = stackTypeBits & 0x1bff | 0x81800;
    goto LAB_97b9b4a0;
  case 0xe:
    ctorNominalSize = 4;
LAB_97b9b490:
    ctorTypeBits = ctorNominalSize << 0xb | stackTypeBits & 0x3ff | 0x80000;
LAB_97b9b4a0:
    constructorScratch = ctorTypeBits & 0xfffffdff | 0x400;
    type[9] = ctorTypeBits & 0x7f800 | ctorTypeBits & 0xfff80000 | type[9] & 0x1ffU | 0x400;
    type[8] = 0;
    stackTypeArraySize = 0;
    stackTypeStructure = (unsigned char *)0x0;
    stackTypeFieldName = 0;
    stackTypeTypeName = (void *)0x0;
    stackTypeWord14 = 0;
    stackTypeStructureSize = 0;
    stackTypeWord1c = 0;
    stackType = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
    stackTypeWord20 = 0;
    type[1] = 0;
    type[2] = 0;
    type[3] = 0;
    type[4] = 0;
    type[5] = 0;
    type[6] = 0;
    type[7] = 0;
    savedR10 = scratchR10;
    stackTypeBits = constructorScratch;
    goto LAB_97b9b714;
  case 0xf:
    structFieldList = *(unsigned char **)(function + 0x24);
    functionName = (unsigned char *)
             (**(code **)(*(int *)(function + 0x1c) + 0x18))
                       (function + 0x1c,sourceLoc,intermNode,function,op,type,function + 0x1c);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_((unsigned char *)&nameCopy1,functionName);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&nameCopy2,(unsigned char *)&nameCopy1);
    stackTypeBits = stackTypeBits & 0x9ff | 0x700800;
    stackType = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
    stackTypeWord20 = 0;
    stackTypeArraySize = 0;
    stackTypeFieldName = 0;
    stackTypeWord14 = 0;
    stackTypeWord1c = 0;
    stackTypeStructure = structFieldList;
    stackTypeStructureSize = TType__setStructSize((unsigned char *)&stackType,structFieldList);
    structNameChars = nameCopy2Chars;
    nameCopy2Chars[*(int *)(nameCopy2Chars + -0xc)] = *DAT_a7b7ba18;
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    allocPair = TPoolAllocator__allocate(poolAllocator,8);
    newTypeNameString = (void *)((ulonglong)allocPair >> 0x20);
    paramSizeResult = (int)allocPair;
    cr0Flags = (newTypeNameString == (void *)0x0) << 1;
    stackTypeTypeName = (void *)0x0;
    if (newTypeNameString != (void *)0x0) {
      allocatorArg[0] = GetGlobalPoolAllocator();
      scratchR5 = (unsigned char *)allocatorArg;
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                (newTypeNameString,structNameChars,(unsigned char *)scratchR5);
      stackTypeTypeName = newTypeNameString;
      paramSizeResult = r4Out0;
    }
    refCountPtr = (int *)(nameCopy2Chars + -4);
    destroyArgA[0] = nameCopy2;
    do {
      oldRefCount = *refCountPtr;
      if (reservation != '\0') {
        newRefCount = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
        *refCountPtr = newRefCount;
        cr0Flags = 2;
      }
    } while (!(bool)(cr0Flags >> 1 & 1));
    if (oldRefCount < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(nameCopy2Chars + -0xc),destroyArgA);
      paramSizeResult = r4Out1;
    }
    type[1] = stackTypeArraySize;
    type[2] = (int)stackTypeStructure;
    type[3] = stackTypeFieldName;
    type[4] = (int)stackTypeTypeName;
    type[5] = stackTypeWord14;
    type[6] = stackTypeStructureSize;
    type[7] = stackTypeWord1c;
    type[9] = (stackTypeBits >> 9 & 1) << 9 |
                 (stackTypeBits >> 10 & 1) << 10 |
                 stackTypeBits & 0x7f800 |
                 (stackTypeBits >> 0x13 & 0x3f) << 0x13 | stackTypeBits & 0xfe000000 | type[9] & 0x1ffU;
    refCountPtr = (int *)(savedR10 + -4);
    type[8] = stackTypeWord20;
    stackType = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
    destroyArgB[0] = nameCopy1;
    do {
      oldRefCount = *refCountPtr;
      constructorScratch = oldRefCount - 1;
      if (reservation != '\0') {
        newRefCount = storeWordConditionalIndexed(constructorScratch,0,refCountPtr);
        *refCountPtr = newRefCount;
        cr0Flags = 2;
      }
    } while (!(bool)(cr0Flags >> 1 & 1));
    if (oldRefCount < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(savedR10 + -0xc),destroyArgB);
      paramSizeResult = r4Out2;
    }
    goto LAB_97b9b714;
  default:
    errorReason = "expected constructor";
    errorToken = "Internal Error";
    goto LAB_97b9b9d8;
  }
  constructorScratch = ctorNominalSize << 0xb | ctorTypeBits & 0xfff801ff;
  savedR10 = constructorScratch << 0xd;
  type[9] = ctorNominalSize << 0xb | ctorTypeBits & 0xfff80000 | type[9] & 0x1ffU;
  type[8] = 0;
  stackTypeArraySize = 0;
  stackTypeStructure = (unsigned char *)0x0;
  stackTypeFieldName = 0;
  stackTypeTypeName = (void *)0x0;
  stackTypeWord14 = 0;
  stackTypeStructureSize = 0;
  stackTypeWord1c = 0;
  stackType = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  stackTypeWord20 = 0;
  type[1] = 0;
  type[2] = 0;
  type[3] = 0;
  type[4] = 0;
  type[5] = 0;
  type[6] = 0;
  type[7] = 0;
  stackTypeBits = constructorScratch;
LAB_97b9b714:
  totalSize = 0;
  constType = true;
  full = false;
  overFull = false;
  matrixInMatrix = false;
  arrayArg = false;
  scratchR10 = savedR10;
  for (paramIndex = 0; paramIndex < *(int *)(function + 0x14) - *(int *)(function + 0x10) >> 3;
      paramIndex = paramIndex + 1) {
    paramOffset = paramIndex * 8;
    paramType = *(int **)(*(int *)(function + 0x10) + paramOffset + 4);
    paramTypeVtableArg = *paramType;
    paramSizeResult = (**(code **)(paramTypeVtableArg + 0x30))(paramType,paramSizeResult,scratchR5,functionCopy,opCopy,typeCopy,paramTypeVtableArg);
    totalSize = totalSize + paramSizeResult;
    scratchR4 = sourceLocCopy;
    if ((op - 0x72U < 3) &&
       (paramType = *(int **)(*(int *)(function + 0x10) + paramOffset + 4), paramSizeResult = *paramType,
       paramSizeResult = (**(code **)(paramSizeResult + 0x34))(paramType,sourceLocCopy,scratchR5,functionCopy,opCopy,typeCopy,paramSizeResult),
       scratchR4 = r4Out3, paramSizeResult != 0)) {
      matrixInMatrix = true;
    }
    if (full) {
      overFull = true;
    }
    if ((op != 0x75) &&
       (paramSizeResult = (**(code **)(*type + 0x30))(type), scratchR4 = r4Out4, paramSizeResult <= totalSize))
    {
      full = true;
    }
    paramType = *(int **)(*(int *)(function + 0x10) + paramOffset + 4);
    paramTypeVtable = *paramType;
    paramTypeVtable = (**(code **)(paramTypeVtable + 0x24))(paramType,scratchR4,scratchR5,functionCopy,opCopy,typeCopy,paramTypeVtable);
    if (paramTypeVtable != 2) {
      constType = false;
    }
    functionParam = *(uint **)(*(int *)(function + 0x10) + paramOffset + 4);
    constructorScratch = *functionParam;
    paramIsArray = (**(code **)(constructorScratch + 0x38))(functionParam,sourceLocCopy2,scratchR5,functionCopy,opCopy,typeCopy,constructorScratch);
    if (paramIsArray != 0) {
      arrayArg = true;
    }
    paramSizeResult = r4Out5;
  }
  if (constType) {
    (**(code **)(*type + 0x28))(type,2);
    paramSizeResult = r4Out6;
  }
  if (arrayArg) {
    errorReason = "constructing from a non-dereferenced array";
  }
  else {
    if (matrixInMatrix) {
      errorReason = "constructing matrix from matrix";
      errorToken = "constructor";
      extraInfoFormat = "(reserved)";
      goto LAB_97b9b9dc;
    }
    if (overFull) {
      errorReason = "too many arguments";
    }
    else if (((totalSize == 1) ||
             (paramIndex = (**(code **)(*type + 0x30))(type,paramSizeResult,scratchR5,functionCopy,opCopy),
             paramSizeResult = r4Out7, paramIndex <= totalSize)) && ((0 < totalSize || (op != 0x75)))) {
      argTyped = (int *)(**(code **)(*(int *)intermNode + 0x14))(intermNode,paramSizeResult,scratchR5,functionCopy,opCopy);
      if (argTyped == (int *)0x0) {
        errorReason = "constructor argument does not have a type";
      }
      else {
        scratchR4 = sourceLocCopy3;
        if ((op == 0x75) ||
           (paramSizeResult = (**(code **)(*argTyped + 0x40))(argTyped,sourceLocCopy3,scratchR5,functionCopy,opCopy),
           scratchR4 = r4Out8, 7 < paramSizeResult - 5U)) {
          argBasicType = (**(code **)(*argTyped + 0x40))(argTyped,scratchR4,scratchR5,functionCopy,opCopy);
          if (argBasicType != 0) {
            return 0;
          }
          errorReason = "cannot convert a void";
        }
        else {
          errorReason = "cannot convert a sampler";
        }
      }
    }
    else {
      errorReason = "not enough data provided for construction";
    }
  }
  errorToken = "constructor";
LAB_97b9b9d8:
  extraInfoFormat = "";
LAB_97b9b9dc:
  error((int)this,(char *)sourceLoc,errorReason,errorToken,extraInfoFormat,typeCopy,constructorScratch,scratchR10);
  return 1;
}

/* TParseContext__voidErrorCheck @ 0x97b9ba00 (120 bytes) */
int TParseContext__voidErrorCheck(this, sourceLoc, text, publicType)
  unsigned char * this;
  int sourceLoc;
  unsigned char * text;
  unsigned char * publicType;
{
  byte terminalChar;
  int basicType;
  undefined4 scratchR8;
  
  basicType = *(int *)publicType;
  if (basicType == 0) {
    terminalChar = *DAT_a7b7ba18;
    *(byte *)(*(int *)(text + 4) + *(int *)(*(int *)(text + 4) + -0xc)) = terminalChar;
    error((int)this,(char *)sourceLoc,"illegal use of type \'void\'",*(char **)(text + 4),"",scratchR8,
          (uint)terminalChar,text);
  }
  return basicType == 0;
}

