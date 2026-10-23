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
  int queryResultOrOperator;
  uint leftBasicType;
  uint leftNominalSize;
  uint leftIsMatrix;
  int rightBasicType;
  undefined4 a1;
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
  char typeTempOrTextBuf [8];
  int typeTempStructure;
  unsigned char allocatorDummy [4];
  uint typeTempBits;
  
  resultNominalSize = (**(code **)(**(int **)(this + 0x34) + 0x48))
                    (*(int **)(this + 0x34),infoSink,scratchR5,scratchR6,scratchR7,scratchR8);
  queryResultOrOperator = (**(code **)(**(int **)(this + 0x38) + 0x48))(*(int **)(this + 0x38));
  if ((int)resultNominalSize < queryResultOrOperator) {
    resultNominalSize = (**(code **)(**(int **)(this + 0x38) + 0x48))(*(int **)(this + 0x38));
  }
  leftBasicType = (**(code **)(**(int **)(this + 0x34) + 0x40))(*(int **)(this + 0x34));
  queryResultOrOperator = (**(code **)(**(int **)(this + 0x34) + 0x54))(*(int **)(this + 0x34));
  if (queryResultOrOperator != 0) {
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
    queryResultOrOperator = *(int *)(this + 0x30);
    if (queryResultOrOperator < 0x25) {
      if (0x20 < queryResultOrOperator) {
LAB_97b90770:
        queryResultOrOperator = *(int *)this;
        stackTypeBits = stackTypeBits & 0x1801ff;
        goto LAB_97b90850;
      }
      if (0x16 < queryResultOrOperator) {
        if (queryResultOrOperator < 0x1d) {
          queryResultOrOperator = (**(code **)(**(int **)(this + 0x34) + 0x40))(*(int **)(this + 0x34));
          if (queryResultOrOperator != 2) {
            return 0;
          }
          queryResultOrOperator = (**(code **)(**(int **)(this + 0x38) + 0x40))(*(int **)(this + 0x38));
          operandTypesMatch = queryResultOrOperator == 2;
          goto LAB_97b90940;
        }
        if (queryResultOrOperator < 0x1f) goto LAB_97b90770;
      }
    }
    else {
      if (queryResultOrOperator == 0x2c) {
LAB_97b907c4:
        queryResultOrOperator = (**(code **)(**(int **)(this + 0x34) + 0x40))(*(int **)(this + 0x34),a1);
        if (queryResultOrOperator != 3) {
          return 0;
        }
        queryResultOrOperator = (**(code **)(**(int **)(this + 0x38) + 0x40))(*(int **)(this + 0x38));
        if (queryResultOrOperator != 3) {
          return 0;
        }
        queryResultOrOperator = *(int *)this;
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
        (**(code **)(queryResultOrOperator + 0x34))(this,&stackType,scratchR5,scratchR6,scratchR7,scratchR8,queryResultOrOperator);
        return 1;
      }
      if (queryResultOrOperator < 0x2d) {
        if (queryResultOrOperator == 0x2a) goto LAB_97b907c4;
      }
      else if (queryResultOrOperator - 0x7fU < 6) {
        queryResultOrOperator = (**(code **)(**(int **)(this + 0x34) + 0x40))(*(int **)(this + 0x34));
        if (queryResultOrOperator != 2) {
          return 0;
        }
        queryResultOrOperator = (**(code **)(**(int **)(this + 0x38) + 0x40))(*(int **)(this + 0x38));
        if (queryResultOrOperator != 2) {
          return 0;
        }
      }
    }
    queryResultOrOperator = (**(code **)(**(int **)(this + 0x34) + 0x40))(*(int **)(this + 0x34));
    rightBasicType = (**(code **)(**(int **)(this + 0x38) + 0x40))(*(int **)(this + 0x38));
    if (queryResultOrOperator != rightBasicType) {
      return 0;
    }
    queryResultOrOperator = (**(code **)(**(int **)(this + 0x34) + 0x50))(*(int **)(this + 0x34));
    rightMatrixFlag = (**(code **)(**(int **)(this + 0x38) + 0x50))(*(int **)(this + 0x38));
    operandTypesMatch = queryResultOrOperator == rightMatrixFlag;
LAB_97b90940:
    if (!operandTypesMatch) {
      return 0;
    }
    return 1;
  }
  leftNominalSize = (**(code **)(**(int **)(this + 0x34) + 0x48))(*(int **)(this + 0x34));
  if ((leftNominalSize != resultNominalSize) &&
     (queryResultOrOperator = (**(code **)(**(int **)(this + 0x34) + 0x48))(*(int **)(this + 0x34)), queryResultOrOperator != 1)) {
    return 0;
  }
  leftNominalSize = (**(code **)(**(int **)(this + 0x38) + 0x48))(*(int **)(this + 0x38));
  scratchR4 = r4Out0;
  if ((leftNominalSize != resultNominalSize) &&
     (queryResultOrOperator = (**(code **)(**(int **)(this + 0x38) + 0x48))(*(int **)(this + 0x38)),
     scratchR4 = r4Out1, queryResultOrOperator != 1)) {
    return 0;
  }
  leftNominalSize = *(int *)(this + 0x30) - 0x13;
  if (0x6c < leftNominalSize) {
    return 0;
  }
  queryResultOrOperator = leftNominalSize * 4;
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
                       (*(int **)(this + 0x34),scratchR4,scratchR5,scratchR6,scratchR7,scratchR8,queryResultOrOperator);
    scratchR4 = r4Out2;
    if ((leftMatrixFlag == 0) &&
       (leftMatrixFlag = (**(code **)(**(int **)(this + 0x38) + 0x50))(*(int **)(this + 0x38)),
       scratchR4 = r4Out3, leftMatrixFlag != 0)) {
      queryResultOrOperator = (**(code **)(**(int **)(this + 0x34) + 0x58))(*(int **)(this + 0x34));
      if (queryResultOrOperator != 0) {
        newOperator = 0x27;
        goto LAB_97b9100c;
      }
      stackTypeBits = (resultNominalSize & 0xff) << 0xb | (leftBasicType & 0x3f) << 0x13 | stackTypeBits & 0x5ff | 0x400;
      queryResultOrOperator = *(int *)this;
      *(undefined4 *)(this + 0x30) = 0x29;
    }
    else {
      leftMatrixFlag = (**(code **)(**(int **)(this + 0x34) + 0x50))
                         (*(int **)(this + 0x34),scratchR4,scratchR5,scratchR6,scratchR7,scratchR8,queryResultOrOperator);
      scratchR4 = r4Out4;
      if ((leftMatrixFlag == 0) ||
         (leftMatrixFlag = (**(code **)(**(int **)(this + 0x38) + 0x50))(*(int **)(this + 0x38)),
         scratchR4 = r4Out5, leftMatrixFlag != 0)) {
        leftMatrixFlag = (**(code **)(**(int **)(this + 0x34) + 0x50))
                           (*(int **)(this + 0x34),scratchR4,scratchR5,scratchR6,scratchR7,scratchR8,queryResultOrOperator);
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
          resultNominalSize = (*(code *)**(undefined4 **)this)(this,scratchR4,scratchR5,scratchR6,scratchR7,scratchR8,queryResultOrOperator)
          ;
                    
          __ZN13TInfoSinkBase6appendEPKc(infoSink,"INTERNAL ERROR: ");
          leftBasicType = resultNominalSize & 0xffff;
          cr0Flags = (leftBasicType == 0) << 1;
          if (leftBasicType == 0) {
            _sprintf(typeTempOrTextBuf,"%d:? ",(int)resultNominalSize >> 0x10);
          }
          else {
            _sprintf(typeTempOrTextBuf,"%d:%d",(int)resultNominalSize >> 0x10,leftBasicType);
          }
          __ZNSsC1EPKcRKSaIcE(&stackType,typeTempOrTextBuf,(unsigned char *)&stackTypeTypeName);
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
        queryResultOrOperator = (**(code **)(**(int **)(this + 0x34) + 0x58))(*(int **)(this + 0x34));
        if (((queryResultOrOperator != 0) &&
            (queryResultOrOperator = (**(code **)(**(int **)(this + 0x38) + 0x58))(*(int **)(this + 0x38)),
            queryResultOrOperator != 0)) ||
           ((queryResultOrOperator = (**(code **)(**(int **)(this + 0x34) + 0x58))(*(int **)(this + 0x34)),
            queryResultOrOperator == 0 &&
            (queryResultOrOperator = (**(code **)(**(int **)(this + 0x38) + 0x58))(*(int **)(this + 0x38)),
            queryResultOrOperator == 0)))) goto LAB_97b91520;
        queryResultOrOperator = *(int *)this;
        leftBasicType = (leftBasicType & 0x3f) << 0x13 | stackTypeBits & 0x7ffff;
        newOperator = 0x26;
      }
      else {
        queryResultOrOperator = (**(code **)(**(int **)(this + 0x38) + 0x58))(*(int **)(this + 0x38));
        newOperator = 0x29;
        if (queryResultOrOperator == 0) goto LAB_97b9100c;
        queryResultOrOperator = *(int *)this;
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
    queryResultOrOperator = (**(code **)(**(int **)(this + 0x34) + 0x50))
                      (*(int **)(this + 0x34),scratchR4,scratchR5,scratchR6,scratchR7,scratchR8,queryResultOrOperator);
    if ((queryResultOrOperator != 0) &&
       (queryResultOrOperator = (**(code **)(**(int **)(this + 0x38) + 0x58))(*(int **)(this + 0x38)), queryResultOrOperator != 0))
    {
      return 0;
    }
    queryResultOrOperator = (**(code **)(**(int **)(this + 0x34) + 0x58))(*(int **)(this + 0x34));
    if ((queryResultOrOperator != 0) &&
       (queryResultOrOperator = (**(code **)(**(int **)(this + 0x38) + 0x50))(*(int **)(this + 0x38)), queryResultOrOperator != 0))
    {
      return 0;
    }
    queryResultOrOperator = (**(code **)(**(int **)(this + 0x34) + 0x40))(*(int **)(this + 0x34));
    rightBasicType = (**(code **)(**(int **)(this + 0x38) + 0x40))(*(int **)(this + 0x38));
    if (queryResultOrOperator != rightBasicType) {
      return 0;
    }
    queryResultOrOperator = *(int *)this;
    stackTypeBits = stackTypeBits & 0x1801ff | 0x180800;
LAB_97b914fc:
    setTypeFn = *(code **)(queryResultOrOperator + 0x34);
    goto LAB_97b91508;
  case 0x76:
    break;
  case 0x79:
    leftMatrixFlag = (**(code **)(**(int **)(this + 0x34) + 0x50))(*(int **)(this + 0x34),scratchR4);
    if ((leftMatrixFlag == 0) &&
       (leftMatrixFlag = (**(code **)(**(int **)(this + 0x38) + 0x50))(*(int **)(this + 0x38)), leftMatrixFlag != 0)
       ) {
      queryResultOrOperator = (**(code **)(**(int **)(this + 0x34) + 0x58))(*(int **)(this + 0x34));
      if (queryResultOrOperator == 0) {
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
                              (this,scratchR4,scratchR5,scratchR6,scratchR7,scratchR8,queryResultOrOperator);
                    
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
          queryResultOrOperator = (**(code **)(**(int **)(this + 0x34) + 0x58))(*(int **)(this + 0x34));
          if (((queryResultOrOperator != 0) &&
              (queryResultOrOperator = (**(code **)(**(int **)(this + 0x38) + 0x58))(*(int **)(this + 0x38)),
              queryResultOrOperator != 0)) ||
             ((queryResultOrOperator = (**(code **)(**(int **)(this + 0x34) + 0x58))(*(int **)(this + 0x34)),
              queryResultOrOperator == 0 &&
              (queryResultOrOperator = (**(code **)(**(int **)(this + 0x38) + 0x58))(*(int **)(this + 0x38)),
              queryResultOrOperator == 0)))) goto LAB_97b91520;
          queryResultOrOperator = (**(code **)(**(int **)(this + 0x34) + 0x58))(*(int **)(this + 0x34));
          if (queryResultOrOperator == 0) {
            return 0;
          }
          queryResultOrOperator = *(int *)this;
          newOperator = 0x7b;
          leftBasicType = (leftBasicType & 0x3f) << 0x13 | stackTypeBits & 0x7ffff;
          goto LAB_97b910f8;
        }
        newOperator = 0x7d;
      }
      else {
        queryResultOrOperator = (**(code **)(**(int **)(this + 0x38) + 0x58))(*(int **)(this + 0x38));
        if (queryResultOrOperator != 0) {
          return 0;
        }
        newOperator = 0x7c;
      }
    }
LAB_97b9100c:
    *(undefined4 *)(this + 0x30) = newOperator;
    goto LAB_97b91520;
  }
  queryResultOrOperator = (**(code **)(**(int **)(this + 0x34) + 0x48))(*(int **)(this + 0x34),scratchR4);
  rightNominalSize = (**(code **)(**(int **)(this + 0x38) + 0x48))(*(int **)(this + 0x38));
  if (queryResultOrOperator != rightNominalSize) {
    return 0;
  }
switchD_97b909e0_caseD_13:
  queryResultOrOperator = (**(code **)(**(int **)(this + 0x34) + 0x50))(*(int **)(this + 0x34));
  if (((queryResultOrOperator == 0) ||
      (queryResultOrOperator = (**(code **)(**(int **)(this + 0x38) + 0x58))(*(int **)(this + 0x38)), queryResultOrOperator == 0))
     && ((queryResultOrOperator = (**(code **)(**(int **)(this + 0x34) + 0x58))(*(int **)(this + 0x34)), queryResultOrOperator == 0
         || (queryResultOrOperator = (**(code **)(**(int **)(this + 0x38) + 0x50))(*(int **)(this + 0x38)),
            queryResultOrOperator == 0)))) {
    queryResultOrOperator = (**(code **)(**(int **)(this + 0x34) + 0x40))(*(int **)(this + 0x34));
    rightBasicType = (**(code **)(**(int **)(this + 0x38) + 0x40))(*(int **)(this + 0x38));
    if (queryResultOrOperator == rightBasicType) {
      resultIsMatrix = 0;
      queryResultOrOperator = (**(code **)(**(int **)(this + 0x34) + 0x50))(*(int **)(this + 0x34));
      if ((queryResultOrOperator != 0) ||
         (queryResultOrOperator = (**(code **)(**(int **)(this + 0x38) + 0x50))(*(int **)(this + 0x38)), queryResultOrOperator != 0)
         ) {
        resultIsMatrix = 1;
      }
      queryResultOrOperator = *(int *)this;
      stackTypeBits = resultIsMatrix << 10 | (resultNominalSize & 0xff) << 0xb | (leftBasicType & 0x3f) << 0x13 | stackTypeBits & 0x1ff;
      setTypeFn = *(code **)(queryResultOrOperator + 0x34);
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
      (*setTypeFn)(this,&stackType,scratchR5,scratchR6,scratchR7,scratchR8,queryResultOrOperator);
      stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
LAB_97b91520:
      queryResultOrOperator = *(int *)(this + 0x30);
      if ((0x75 < queryResultOrOperator) && ((queryResultOrOperator < 0x7a || (queryResultOrOperator - 0x7eU < 7)))) {
        (**(code **)(*(int *)this + 0x38))(&stackType,this);
        (**(code **)(**(int **)(this + 0x34) + 0x38))(typeTempOrTextBuf,*(int **)(this + 0x34));
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
  int fieldSize;
  int constIndex;
  int fieldOffset;
  int fieldsBegin;
  int *a0;
  undefined4 r4Out0;
  undefined4 r4Out1;
  undefined4 scratchR4;
  unsigned char * a2;
  int *a3;
  undefined4 scratchR7;
  undefined4 scratchR8;
  int fieldVtableThenBasicType;
  uint fieldCount;
  uint fieldIndex;
  int typeList;
  int memberIndex;
  undefined8 nestedResult;
  
  fieldIndex = 0;
  typeList = *(int *)(type + 8);
  fieldsBegin = *(int *)(typeList + 4);
  fieldCount = *(int *)(typeList + 8) - fieldsBegin >> 3;
  a2 = constUnion2;
  a3 = constIndexPtr;
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
        a0 = *(int **)(*(int *)(typeList + 4) + fieldOffset);
        fieldVtableThenBasicType = *a0;
        fieldVtableThenBasicType = (**(code **)(fieldVtableThenBasicType + 0x20))(a0,scratchR4,a2,a3,scratchR7,scratchR8,fieldVtableThenBasicType);
        scratchR4 = r4Out1;
        if (fieldVtableThenBasicType == 2) {
LAB_97b916a8:
          constIndex = *constIndexPtr;
          if (*(int *)(constUnion2 + constIndex * 4) != *(int *)(constUnion1 + constIndex * 4)) {
            return 0;
          }
LAB_97b916c8:
          *constIndexPtr = constIndex + 1;
        }
        else if (fieldVtableThenBasicType < 3) {
          if (fieldVtableThenBasicType == 1) {
            constIndex = *constIndexPtr;
            if (*(float *)(constUnion2 + constIndex * 4) != *(float *)(constUnion1 + constIndex * 4)) {
              return 0;
            }
            goto LAB_97b916c8;
          }
        }
        else {
          if (fieldVtableThenBasicType == 3) goto LAB_97b916a8;
          if (fieldVtableThenBasicType == 0xe) {
            a2 = constUnion2;
            a3 = constIndexPtr;
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
  bool sizeFlag;
  undefined *newRefCount;
  uint typeBit10;
  undefined **refCountPtrCopy;
  float leftValue;
  float rightOrResultValue;
  uint nodeBitsBefore;
  undefined *refCountOrVtable;
  unsigned char * thisOrRightCursor;
  uint bitsOrLine;
  undefined4 *nodeOrVtable;
  int sizeOrArrayOrIndex;
  int resultOrOffset;
  int countOrResult;
  int *rightConstUnion;
  uint *resultBool;
  unsigned char * poolAllocator;
  int sizeOrIndex;
  unsigned char * newNodeOrRightArg;
  undefined4 r4Value;
  unsigned char * stringRep;
  uint typeBitsOrLoc;
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
  uint typeFieldOrInt;
  float *resultOrRightFloats;
  unsigned char * thisUnion;
  int sizeOrLoopIndex;
  undefined **refCountPtr;
  char *message;
  bool flagOrCompare;
  char reservation;
  byte reservationOk;
  int columnsLeft;
  undefined8 allocPair;
  undefined **unaryTypeVtbl;
  undefined4 unaryTypeWord1;
  undefined4 unaryTypeWord2;
  undefined4 unaryTypeWord3;
  undefined4 unaryTypeWord4OrLocText;
  undefined4 unaryTypeWord5;
  undefined4 unaryTypeWord6;
  undefined4 unaryTypeWord7;
  undefined4 unaryTypeWord8;
  uint unaryTypeBits;
  undefined **binaryTypeVtbl;
  int binaryTypeWord1;
  int binaryTypeWord2;
  int binaryTypeWord3;
  int binaryTypeWord4OrLocText;
  int binaryTypeWord5;
  int binaryTypeWord6;
  int binaryTypeWord7;
  int binaryTypeWord8;
  uint binaryTypeBits;
  undefined **compareTypeVtbl;
  int compareTypeWord1;
  int compareTypeWord2;
  int compareTypeWord3;
  int compareTypeWord4OrLocText;
  int compareTypeWord5;
  int compareTypeWord6;
  int compareTypeWord7;
  int compareTypeWord8;
  uint compareTypeBits;
  undefined **rightTypeOrString [4];
  unsigned char locTextBuf [16];
  unsigned char stringAllocator [4];
  uint rightTypeBits;
  undefined **tailTypeVtbl;
  undefined4 tailTypeWord1;
  undefined4 tailTypeWord2;
  undefined4 tailTypeWord3;
  undefined4 tailTypeWord4OrLocText;
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
    sizeOrArrayOrIndex = 0;
    sizeOrIndex = (**(code **)(*(int *)this + 0x4c))(this,op);
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    resultOrRightFloats = (float *)TPoolAllocator__allocate(poolAllocator,sizeOrIndex << 2);
    sizeOrIndex = (**(code **)(*(int *)this + 0x4c))(this);
    if (1 < sizeOrIndex) {
      for (; sizeOrIndex = (**(code **)(*(int *)this + 0x4c))(this), sizeOrArrayOrIndex < sizeOrIndex; sizeOrArrayOrIndex = sizeOrArrayOrIndex + 1
          ) {
        if (op == 5) {
          (**(code **)(*(int *)this + 0x38))(&unaryTypeVtbl,this);
          typeBitsOrLoc = unaryTypeBits >> 0x13 & 0x3f;
          unaryTypeVtbl = &PTR___ZN5TTypeD1Ev_a7b7cff8;
          if (typeBitsOrLoc != 1) {
            if (typeBitsOrLoc == 2) {
              rightOrResultValue = GH_U2F((unsigned int)(-*(int *)(thisUnion + sizeOrArrayOrIndex * 4)));
              goto LAB_97b956a0;
            }
            typeBitsOrLoc = (*(code *)**(undefined4 **)this)(this);
                    
            goto override_jmp_97b95640_case_0;
          }
          resultOrRightFloats[sizeOrArrayOrIndex] = -*(float *)(thisUnion + sizeOrArrayOrIndex * 4);
        }
        else {
          if (op != 6) {
            return (unsigned char *)0x0;
          }
          (**(code **)(*(int *)this + 0x38))(&unaryTypeVtbl,this);
          unaryTypeVtbl = &PTR___ZN5TTypeD1Ev_a7b7cff8;
          if ((unaryTypeBits >> 0x13 & 0x3f) != 3) {
            typeBitsOrLoc = (*(code *)**(undefined4 **)this)(this);
                    
            goto override_jmp_97b95640_case_0;
          }
          rightOrResultValue = GH_U2F((unsigned int)((*(uint *)(thisUnion + sizeOrArrayOrIndex * 4) ^ 1)));
LAB_97b956a0:
          resultOrRightFloats[sizeOrArrayOrIndex] = rightOrResultValue;
        }
        unaryTypeVtbl = &PTR___ZN5TTypeD1Ev_a7b7cff8;
      }
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      nodeOrVtable = (undefined4 *)TPoolAllocator__allocate(poolAllocator,0x34);
      (**(code **)(*(int *)this + 0x38))(&unaryTypeVtbl,this);
      allocPair = CONCAT44(nodeOrVtable,r4Out12);
      nodeOrVtable[1] = 0;
      *nodeOrVtable = &PTR_getLine_a7b7cf90;
      nodeOrVtable[3] = unaryTypeWord1;
      nodeOrVtable[4] = unaryTypeWord2;
      nodeOrVtable[5] = unaryTypeWord3;
      nodeOrVtable[6] = unaryTypeWord4OrLocText;
      nodeOrVtable[7] = unaryTypeWord5;
      nodeOrVtable[8] = unaryTypeWord6;
      nodeOrVtable[2] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
      nodeOrVtable[9] = unaryTypeWord7;
      nodeOrVtable[10] = unaryTypeWord8;
      nodeBitsBefore = nodeOrVtable[0xb];
      bitsOrLine = unaryTypeBits & 0xfe000000;
      nodeOrVtable[0xb] = bitsOrLine | nodeBitsBefore & 0x1ffffff;
      typeFieldOrInt = (unaryTypeBits >> 0x13 & 0x3f) << 0x13;
      nodeOrVtable[0xb] = typeFieldOrInt | bitsOrLine | nodeBitsBefore & 0x7ffff;
      typeBitsOrLoc = unaryTypeBits & 0x7f800;
      nodeOrVtable[0xb] = typeBitsOrLoc | typeFieldOrInt | bitsOrLine | nodeBitsBefore & 0x7ff;
      typeBit10 = (unaryTypeBits >> 10 & 1) << 10;
      nodeOrVtable[0xb] = typeBit10 | typeBitsOrLoc | typeFieldOrInt | bitsOrLine | nodeBitsBefore & 0x3ff;
      refCountOrVtable = PTR_vtable_a7b7c0c8;
      nodeOrVtable[0xb] = (unaryTypeBits >> 9 & 1) << 9 | typeBit10 | typeBitsOrLoc | typeFieldOrInt | bitsOrLine | nodeBitsBefore & 0x1ff;
      nodeOrVtable[0xc] = resultOrRightFloats;
      *nodeOrVtable = refCountOrVtable + 8;
      goto LAB_97b95bbc;
    }
    if (op == 5) {
      (**(code **)(*(int *)this + 0x38))(&unaryTypeVtbl,this);
      typeBitsOrLoc = unaryTypeBits >> 0x13 & 0x3f;
      unaryTypeVtbl = &PTR___ZN5TTypeD1Ev_a7b7cff8;
      if (typeBitsOrLoc == 1) {
        *resultOrRightFloats = -**(float **)(this + 0x30);
        poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
        allocPair = TPoolAllocator__allocate(poolAllocator,0x34);
        typeBitsOrLoc = unaryTypeBits & 0x7ff | 0x4080000;
        goto LAB_97b9597c;
      }
      if (typeBitsOrLoc == 2) {
        *resultOrRightFloats = GH_U2F((unsigned int)(-**(int **)(this + 0x30)));
        poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
        allocPair = TPoolAllocator__allocate(poolAllocator,0x34);
        sizeOrIndex = 2;
        goto LAB_97b9596c;
      }
      typeBitsOrLoc = *(uint *)(this + 4);
                    
    }
    else {
      if (op != 6) {
        return (unsigned char *)0x0;
      }
      (**(code **)(*(int *)this + 0x38))(&unaryTypeVtbl,this);
      unaryTypeVtbl = &PTR___ZN5TTypeD1Ev_a7b7cff8;
      if ((unaryTypeBits >> 0x13 & 0x3f) == 3) {
        *resultOrRightFloats = GH_U2F((unsigned int)((**(uint **)(this + 0x30) ^ 1)));
        poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
        allocPair = TPoolAllocator__allocate(poolAllocator,0x34);
        sizeOrIndex = 3;
LAB_97b9596c:
        typeBitsOrLoc = sizeOrIndex << 0x13 | unaryTypeBits & 0xfff | 0x4000000;
LAB_97b9597c:
        nodeOrVtable = (undefined4 *)((ulonglong)allocPair >> 0x20);
        unaryTypeBits = typeBitsOrLoc & 0xfffff9ff | 0x800;
        unaryTypeWord1 = 0;
        unaryTypeWord2 = 0;
        unaryTypeWord3 = 0;
        unaryTypeWord4OrLocText = 0;
        unaryTypeWord5 = 0;
        unaryTypeWord6 = 0;
        unaryTypeWord7 = 0;
        unaryTypeWord8 = 0;
        nodeOrVtable[1] = 0;
        *nodeOrVtable = &PTR_getLine_a7b7cf90;
        nodeOrVtable[3] = 0;
        nodeOrVtable[4] = 0;
        nodeOrVtable[5] = 0;
        nodeOrVtable[6] = 0;
        nodeOrVtable[7] = 0;
        nodeOrVtable[8] = 0;
        nodeOrVtable[2] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
        nodeOrVtable[9] = 0;
        nodeOrVtable[10] = 0;
        typeFieldOrInt = nodeOrVtable[0xb];
        bitsOrLine = typeBitsOrLoc & 0xfe000000;
        nodeOrVtable[0xb] = bitsOrLine | typeFieldOrInt & 0x1ffffff;
        typeBitsOrLoc = (typeBitsOrLoc >> 0x13 & 0x3f) << 0x13;
        nodeOrVtable[0xb] = typeBitsOrLoc | bitsOrLine | typeFieldOrInt & 0x7ffff;
        nodeOrVtable[0xb] = typeBitsOrLoc | bitsOrLine | typeFieldOrInt & 0x7ff | 0x800;
        nodeOrVtable[0xb] = typeBitsOrLoc | bitsOrLine | typeFieldOrInt & 0x3ff | 0x800;
        refCountOrVtable = PTR_vtable_a7b7c0c8;
        nodeOrVtable[0xb] = typeBitsOrLoc | bitsOrLine | typeFieldOrInt & 0x1ff | 0x800;
        nodeOrVtable[0xc] = resultOrRightFloats;
        *nodeOrVtable = refCountOrVtable + 8;
LAB_97b95bbc:
        newNodeOrRightArg = (unsigned char *)((ulonglong)allocPair >> 0x20);
        unaryTypeVtbl = &PTR___ZN5TTypeD1Ev_a7b7cff8;
        sizeOrIndex = *(int *)newNodeOrRightArg;
        r4Value = (*(code *)**(undefined4 **)this)(this,(int)allocPair);
        (**(code **)(sizeOrIndex + 4))(newNodeOrRightArg,r4Value);
        return newNodeOrRightArg;
      }
      typeBitsOrLoc = *(uint *)(this + 4);
                    
    }
override_jmp_97b95640_case_0:
    message = "Unary operation not folded into constant";
    __ZN13TInfoSinkBase6appendEPKc(infoSink,"INTERNAL ERROR: ");
    bitsOrLine = typeBitsOrLoc & 0xffff;
    reservationOk = (bitsOrLine == 0) << 1;
    if (bitsOrLine == 0) {
      _sprintf((char *)&unaryTypeWord4OrLocText,"%d:? ",(int)typeBitsOrLoc >> 0x10);
    }
    else {
      _sprintf((char *)&unaryTypeWord4OrLocText,"%d:%d",(int)typeBitsOrLoc >> 0x10,bitsOrLine);
    }
    locText = (unsigned char *)&unaryTypeWord4OrLocText;
    __ZNSsC1EPKcRKSaIcE(&unaryTypeVtbl,(char *)locText,(unsigned char *)&binaryTypeWord8);
                    
    *(undefined *)((int)unaryTypeVtbl + (int)unaryTypeVtbl[-3]) = *PTR__S_terminal_a7b7c0b8;
    __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)unaryTypeVtbl);
    refCountPtr = unaryTypeVtbl;
code_r0x97b95b60:
    refCountPtrCopy = refCountPtr + -1;
    do {
      refCountOrVtable = *refCountPtrCopy;
                    
      if (reservation != '\0') {
        newRefCount = (undefined *)storeWordConditionalIndexed(refCountOrVtable + -1,0,refCountPtrCopy);
        *refCountPtrCopy = newRefCount;
        reservationOk = 2;
      }
    } while (!(bool)(reservationOk >> 1 & 1));
joined_r0x97b95b7c:
    if ((int)refCountOrVtable < 1) {
      __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(refCountPtr + -3),locText);
    }
    __ZN13TInfoSinkBase6appendEPKc(infoSink,": ");
code_r0x97b95ba0:
    __ZN13TInfoSinkBase6appendEPKc(infoSink,message);
    __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
switchD_97b94d20_caseD_17:
    return (unsigned char *)0x0;
  }
  flagOrCompare = false;
  newNodeOrRightArg = rightOperand;
  infoSinkArg = infoSink;
  sizeOrIndex = swapOperands;
  sizeOrArrayOrIndex = (**(code **)(*(int *)rightOperand + 0x18))(rightOperand);
  if ((sizeOrArrayOrIndex != 0) && (sizeOrArrayOrIndex = (**(code **)(*(int *)rightOperand + 0x4c))(rightOperand), sizeOrArrayOrIndex == 1)) {
    (**(code **)(*(int *)rightOperand + 0x38))(&unaryTypeVtbl,rightOperand);
    if (((unaryTypeBits >> 0x13 & 0x3f) != 0xe) &&
       (sizeOrArrayOrIndex = (**(code **)(*(int *)this + 0x4c))(this), 1 < sizeOrArrayOrIndex)) {
      flagOrCompare = true;
    }
    picBase = 0xa7b81734;
    unaryTypeVtbl = &PTR___ZN5TTypeD1Ev_a7b7cff8;
    if (!flagOrCompare) goto LAB_97b92a7c;
    sizeOrArrayOrIndex = (**(code **)(*(int *)rightOperand + 0x18))(rightOperand);
    typeBitsOrLoc = op - 0x13;
    if (typeBitsOrLoc < 0x1a) {
      sizeOrLoopIndex = typeBitsOrLoc * 4;
      switch(typeBitsOrLoc) {
      case 0:
        picBase = 0xa7b81734;
        sizeOrLoopIndex = (**(code **)(*(int *)this + 0x4c))(this,typeBitsOrLoc,newNodeOrRightArg,infoSinkArg,sizeOrIndex,unusedArg6,sizeOrLoopIndex);
        poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
        resultOrOffset = TPoolAllocator__allocate(poolAllocator,sizeOrLoopIndex << 2);
        for (sizeOrLoopIndex = 0; countOrResult = (**(code **)(*(int *)this + 0x4c))(this), sizeOrLoopIndex < countOrResult;
            sizeOrLoopIndex = sizeOrLoopIndex + 1) {
          (**(code **)(*(int *)this + 0x38))(&binaryTypeVtbl,this);
          typeBitsOrLoc = binaryTypeBits >> 0x13 & 0x3f;
          binaryTypeVtbl = (undefined **)(picBase - 0x473c);
          if (typeBitsOrLoc != 1) {
            if (typeBitsOrLoc == 2) {
              *(int *)(sizeOrLoopIndex * 4 + resultOrOffset) =
                   *(int *)(thisUnion + sizeOrLoopIndex * 4) + **(int **)(sizeOrArrayOrIndex + 0x30);
              goto LAB_97b919a8;
            }
            message = "Constant folding cannot be done for \"+\"";
            typeBitsOrLoc = (*(code *)**(undefined4 **)this)(this,r4In0,newNodeOrRightArg,infoSinkArg,sizeOrIndex,unusedArg6,picBase);
                    
override_jmp_97b9198c_case_0:
            __ZN13TInfoSinkBase6appendEPKc(infoSink,"INTERNAL ERROR: ");
            bitsOrLine = typeBitsOrLoc & 0xffff;
            reservationOk = (bitsOrLine == 0) << 1;
            if (bitsOrLine == 0) {
              _sprintf((char *)&binaryTypeWord4OrLocText,"%d:? ",(int)typeBitsOrLoc >> 0x10);
            }
            else {
              _sprintf((char *)&binaryTypeWord4OrLocText,"%d:%d",(int)typeBitsOrLoc >> 0x10,bitsOrLine);
            }
            locText = (unsigned char *)&binaryTypeWord4OrLocText;
            __ZNSsC1EPKcRKSaIcE(&binaryTypeVtbl,(char *)locText,(unsigned char *)&compareTypeWord8);
            *(undefined *)((int)binaryTypeVtbl + (int)binaryTypeVtbl[-3]) = *PTR__S_terminal_a7b7c0b8;
            __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)binaryTypeVtbl);
            refCountPtr = binaryTypeVtbl + -1;
            stringRep = (unsigned char *)(binaryTypeVtbl + -3);
            do {
              refCountOrVtable = *refCountPtr;
              if (reservation != '\0') {
                newRefCount = (undefined *)storeWordConditionalIndexed(refCountOrVtable + -1,0,refCountPtr);
                *refCountPtr = newRefCount;
                reservationOk = 2;
              }
            } while (!(bool)(reservationOk >> 1 & 1));
            flagOrCompare = 0 < (int)refCountOrVtable;
            goto code_r0x97b93fb8;
          }
          *(float *)(resultOrOffset + sizeOrLoopIndex * 4) =
               *(float *)(thisUnion + sizeOrLoopIndex * 4) + **(float **)(sizeOrArrayOrIndex + 0x30);
LAB_97b919a8: ;
        }
        break;
      case 1:
        picBase = 0xa7b81734;
        sizeOrLoopIndex = (**(code **)(*(int *)this + 0x4c))(this);
        poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
        resultOrOffset = TPoolAllocator__allocate(poolAllocator,sizeOrLoopIndex << 2);
        for (sizeOrLoopIndex = 0; countOrResult = (**(code **)(*(int *)this + 0x4c))(this), sizeOrLoopIndex < countOrResult;
            sizeOrLoopIndex = sizeOrLoopIndex + 1) {
          (**(code **)(*(int *)this + 0x38))(&binaryTypeVtbl,this);
          typeBitsOrLoc = binaryTypeBits >> 0x13 & 0x3f;
          binaryTypeVtbl = (undefined **)(picBase - 0x473c);
          if (typeBitsOrLoc == 1) {
            if (swapOperands == 0) {
              rightOrResultValue = *(float *)(thisUnion + sizeOrLoopIndex * 4);
              leftValue = **(float **)(sizeOrArrayOrIndex + 0x30);
            }
            else {
              leftValue = *(float *)(thisUnion + sizeOrLoopIndex * 4);
              rightOrResultValue = **(float **)(sizeOrArrayOrIndex + 0x30);
            }
            *(float *)(resultOrOffset + sizeOrLoopIndex * 4) = leftValue - rightOrResultValue;
          }
          else {
            if (typeBitsOrLoc != 2) {
              message = "Constant folding cannot be done for \"-\"";
              typeBitsOrLoc = (*(code *)**(undefined4 **)this)
                                 (this,r4In2,newNodeOrRightArg,infoSinkArg,sizeOrIndex,unusedArg6,picBase);
                    
              goto override_jmp_97b9198c_case_0;
            }
            if (swapOperands == 0) {
              countOrResult = **(int **)(sizeOrArrayOrIndex + 0x30) - *(int *)(thisUnion + sizeOrLoopIndex * 4);
            }
            else {
              countOrResult = *(int *)(thisUnion + sizeOrLoopIndex * 4) - **(int **)(sizeOrArrayOrIndex + 0x30);
            }
            *(int *)(sizeOrLoopIndex * 4 + resultOrOffset) = countOrResult;
          }
        }
        break;
      default:
        goto switchD_97b91834_caseD_15;
      case 3:
        picBase = 0xa7b81734;
        sizeOrIndex = (**(code **)(*(int *)this + 0x4c))(this);
        poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
        resultOrOffset = TPoolAllocator__allocate(poolAllocator,sizeOrIndex << 2);
        for (sizeOrIndex = 0; sizeOrLoopIndex = (**(code **)(*(int *)this + 0x4c))(this), sizeOrIndex < sizeOrLoopIndex;
            sizeOrIndex = sizeOrIndex + 1) {
          (**(code **)(*(int *)this + 0x38))(&binaryTypeVtbl,this);
          typeBitsOrLoc = binaryTypeBits >> 0x13 & 0x3f;
          binaryTypeVtbl = (undefined **)(picBase - 0x473c);
          if (typeBitsOrLoc == 1) {
            if (swapOperands == 0) {
              if (*(float *)(thisUnion + sizeOrIndex * 4) == 0.0) {
                typeBitsOrLoc = (*(code *)**(undefined4 **)this)(this);
                    
                __ZN13TInfoSinkBase6appendEPKc(infoSink,"WARNING: ");
                bitsOrLine = typeBitsOrLoc & 0xffff;
                reservationOk = (bitsOrLine == 0) << 1;
                if (bitsOrLine == 0) {
                  _sprintf((char *)&binaryTypeWord4OrLocText,"%d:? ",(int)typeBitsOrLoc >> 0x10);
                }
                else {
                  _sprintf((char *)&binaryTypeWord4OrLocText,"%d:%d",(int)typeBitsOrLoc >> 0x10,bitsOrLine);
                }
                __ZNSsC1EPKcRKSaIcE(&binaryTypeVtbl,(char *)&binaryTypeWord4OrLocText,(unsigned char *)&compareTypeWord8);
                *(undefined *)((int)binaryTypeVtbl + (int)binaryTypeVtbl[-3]) = *PTR__S_terminal_a7b7c0b8;
                __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)binaryTypeVtbl);
                refCountPtr = binaryTypeVtbl + -1;
                do {
                  refCountOrVtable = *refCountPtr;
                  if (reservation != '\0') {
                    newRefCount = (undefined *)storeWordConditionalIndexed(refCountOrVtable + -1,0,refCountPtr);
                    *refCountPtr = newRefCount;
                    reservationOk = 2;
                  }
                } while (!(bool)(reservationOk >> 1 & 1));
                if ((int)refCountOrVtable < 1) {
                  __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(binaryTypeVtbl + -3),&binaryTypeWord4OrLocText);
                }
                __ZN13TInfoSinkBase6appendEPKc(infoSink,": ");
                __ZN13TInfoSinkBase6appendEPKc
                          (infoSink,"Divide by zero error during constant folding");
                __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
                rightOrResultValue = 3.4028235e+38;
              }
              else {
                rightOrResultValue = **(float **)(sizeOrArrayOrIndex + 0x30) / *(float *)(thisUnion + sizeOrIndex * 4);
              }
              *(float *)(sizeOrIndex * 4 + resultOrOffset) = rightOrResultValue;
            }
            else {
              if (**(float **)(sizeOrArrayOrIndex + 0x30) == 0.0) {
                typeBitsOrLoc = (*(code *)**(undefined4 **)this)(this);
                    
                __ZN13TInfoSinkBase6appendEPKc(infoSink,"WARNING: ");
                bitsOrLine = typeBitsOrLoc & 0xffff;
                reservationOk = (bitsOrLine == 0) << 1;
                if (bitsOrLine == 0) {
                  _sprintf((char *)&binaryTypeWord4OrLocText,"%d:? ",(int)typeBitsOrLoc >> 0x10);
                }
                else {
                  _sprintf((char *)&binaryTypeWord4OrLocText,"%d:%d",(int)typeBitsOrLoc >> 0x10,bitsOrLine);
                }
                __ZNSsC1EPKcRKSaIcE(&binaryTypeVtbl,(char *)&binaryTypeWord4OrLocText,(unsigned char *)&compareTypeWord8);
                *(undefined *)((int)binaryTypeVtbl + (int)binaryTypeVtbl[-3]) = *PTR__S_terminal_a7b7c0b8;
                __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)binaryTypeVtbl);
                refCountPtr = binaryTypeVtbl + -1;
                do {
                  refCountOrVtable = *refCountPtr;
                  if (reservation != '\0') {
                    newRefCount = (undefined *)storeWordConditionalIndexed(refCountOrVtable + -1,0,refCountPtr);
                    *refCountPtr = newRefCount;
                    reservationOk = 2;
                  }
                } while (!(bool)(reservationOk >> 1 & 1));
                if ((int)refCountOrVtable < 1) {
                  __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(binaryTypeVtbl + -3),&binaryTypeWord4OrLocText);
                }
                __ZN13TInfoSinkBase6appendEPKc(infoSink,": ");
                __ZN13TInfoSinkBase6appendEPKc
                          (infoSink,"Divide by zero error during constant folding");
                __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
                sizeOrLoopIndex = sizeOrIndex << 2;
                rightOrResultValue = 3.4028235e+38;
              }
              else {
                sizeOrLoopIndex = sizeOrIndex * 4;
                rightOrResultValue = *(float *)(thisUnion + sizeOrLoopIndex) / **(float **)(sizeOrArrayOrIndex + 0x30);
              }
              *(float *)(resultOrOffset + sizeOrLoopIndex) = rightOrResultValue;
            }
          }
          else {
            if (typeBitsOrLoc != 2) {
              message = "Constant folding cannot be done for \"/\"";
              typeBitsOrLoc = (*(code *)**(undefined4 **)this)(this);
                    
              goto override_jmp_97b9198c_case_0;
            }
            if (swapOperands == 0) {
              if (*(int *)(thisUnion + sizeOrIndex * 4) == 0) {
                typeBitsOrLoc = (*(code *)**(undefined4 **)this)(this);
                    
                __ZN13TInfoSinkBase6appendEPKc(infoSink,"WARNING: ");
                bitsOrLine = typeBitsOrLoc & 0xffff;
                reservationOk = (bitsOrLine == 0) << 1;
                if (bitsOrLine == 0) {
                  _sprintf((char *)&binaryTypeWord4OrLocText,"%d:? ",(int)typeBitsOrLoc >> 0x10);
                }
                else {
                  _sprintf((char *)&binaryTypeWord4OrLocText,"%d:%d",(int)typeBitsOrLoc >> 0x10,bitsOrLine);
                }
                __ZNSsC1EPKcRKSaIcE(&binaryTypeVtbl,(char *)&binaryTypeWord4OrLocText,(unsigned char *)&compareTypeWord8);
                *(undefined *)((int)binaryTypeVtbl + (int)binaryTypeVtbl[-3]) = *PTR__S_terminal_a7b7c0b8;
                __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)binaryTypeVtbl);
                refCountPtr = binaryTypeVtbl + -1;
                do {
                  refCountOrVtable = *refCountPtr;
                  if (reservation != '\0') {
                    newRefCount = (undefined *)storeWordConditionalIndexed(refCountOrVtable + -1,0,refCountPtr);
                    *refCountPtr = newRefCount;
                    reservationOk = 2;
                  }
                } while (!(bool)(reservationOk >> 1 & 1));
                if ((int)refCountOrVtable < 1) {
                  __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(binaryTypeVtbl + -3),&binaryTypeWord4OrLocText);
                }
                __ZN13TInfoSinkBase6appendEPKc(infoSink,": ");
                __ZN13TInfoSinkBase6appendEPKc
                          (infoSink,"Divide by zero error during constant folding");
                __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
                sizeOrLoopIndex = 0x7fffffff;
              }
              else {
                sizeOrLoopIndex = **(int **)(sizeOrArrayOrIndex + 0x30) / *(int *)(thisUnion + sizeOrIndex * 4);
              }
              *(int *)(sizeOrIndex * 4 + resultOrOffset) = sizeOrLoopIndex;
            }
            else {
              if (**(int **)(sizeOrArrayOrIndex + 0x30) == 0) {
                typeBitsOrLoc = (*(code *)**(undefined4 **)this)(this);
                    
                __ZN13TInfoSinkBase6appendEPKc(infoSink,"WARNING: ");
                bitsOrLine = typeBitsOrLoc & 0xffff;
                reservationOk = (bitsOrLine == 0) << 1;
                if (bitsOrLine == 0) {
                  _sprintf((char *)&binaryTypeWord4OrLocText,"%d:? ",(int)typeBitsOrLoc >> 0x10);
                }
                else {
                  _sprintf((char *)&binaryTypeWord4OrLocText,"%d:%d",(int)typeBitsOrLoc >> 0x10,bitsOrLine);
                }
                __ZNSsC1EPKcRKSaIcE(&binaryTypeVtbl,(char *)&binaryTypeWord4OrLocText,(unsigned char *)&compareTypeWord8);
                *(undefined *)((int)binaryTypeVtbl + (int)binaryTypeVtbl[-3]) = *PTR__S_terminal_a7b7c0b8;
                __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)binaryTypeVtbl);
                refCountPtr = binaryTypeVtbl + -1;
                do {
                  refCountOrVtable = *refCountPtr;
                  if (reservation != '\0') {
                    newRefCount = (undefined *)storeWordConditionalIndexed(refCountOrVtable + -1,0,refCountPtr);
                    *refCountPtr = newRefCount;
                    reservationOk = 2;
                  }
                } while (!(bool)(reservationOk >> 1 & 1));
                if ((int)refCountOrVtable < 1) {
                  __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(binaryTypeVtbl + -3),&binaryTypeWord4OrLocText);
                }
                __ZN13TInfoSinkBase6appendEPKc(infoSink,": ");
                __ZN13TInfoSinkBase6appendEPKc
                          (infoSink,"Divide by zero error during constant folding");
                __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
                countOrResult = 0x7fffffff;
                sizeOrLoopIndex = sizeOrIndex << 2;
              }
              else {
                sizeOrLoopIndex = sizeOrIndex * 4;
                countOrResult = *(int *)(thisUnion + sizeOrLoopIndex) / **(int **)(sizeOrArrayOrIndex + 0x30);
              }
              *(int *)(sizeOrLoopIndex + resultOrOffset) = countOrResult;
            }
          }
        }
        break;
      case 0x13:
      case 0x16:
        picBase = 0xa7b81734;
        sizeOrLoopIndex = (**(code **)(*(int *)this + 0x4c))(this);
        poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
        allocPair = TPoolAllocator__allocate(poolAllocator,sizeOrLoopIndex << 2);
        resultOrOffset = (int)((ulonglong)allocPair >> 0x20);
        r4Value = (undefined4)allocPair;
        for (sizeOrLoopIndex = 0; countOrResult = (**(code **)(*(int *)this + 0x4c))(this,r4Value), sizeOrLoopIndex < countOrResult;
            sizeOrLoopIndex = sizeOrLoopIndex + 1) {
          (**(code **)(*(int *)this + 0x38))(&binaryTypeVtbl,this);
          typeBitsOrLoc = binaryTypeBits >> 0x13 & 0x3f;
          binaryTypeVtbl = (undefined **)(picBase - 0x473c);
          if (typeBitsOrLoc == 1) {
            *(float *)(resultOrOffset + sizeOrLoopIndex * 4) =
                 *(float *)(thisUnion + sizeOrLoopIndex * 4) * **(float **)(sizeOrArrayOrIndex + 0x30);
          }
          else {
            if (typeBitsOrLoc != 2) {
              message = "Constant folding cannot be done for \"*\"";
              typeBitsOrLoc = (*(code *)**(undefined4 **)this)
                                 (this,r4In1,newNodeOrRightArg,infoSinkArg,sizeOrIndex,unusedArg6,picBase);
                    
              __ZN13TInfoSinkBase6appendEPKc(infoSink,"INTERNAL ERROR: ");
              bitsOrLine = typeBitsOrLoc & 0xffff;
              reservationOk = (bitsOrLine == 0) << 1;
              if (bitsOrLine == 0) {
                _sprintf((char *)rightTypeOrString,"%d:? ",(int)typeBitsOrLoc >> 0x10);
              }
              else {
                _sprintf((char *)rightTypeOrString,"%d:%d",(int)typeBitsOrLoc >> 0x10,bitsOrLine);
              }
              locText = (unsigned char *)&binaryTypeWord4OrLocText;
              __ZNSsC1EPKcRKSaIcE(&binaryTypeVtbl,(char *)rightTypeOrString,locText);
              *(undefined *)((int)binaryTypeVtbl + (int)binaryTypeVtbl[-3]) = *PTR__S_terminal_a7b7c0b8;
              __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)binaryTypeVtbl);
              refCountPtr = binaryTypeVtbl;
              goto code_r0x97b932f0;
            }
            *(int *)(sizeOrLoopIndex * 4 + resultOrOffset) =
                 *(int *)(thisUnion + sizeOrLoopIndex * 4) * **(int **)(sizeOrArrayOrIndex + 0x30);
          }
          r4Value = r4In1;
        }
        break;
      case 0x17:
        picBase = 0xa7b81734;
        sizeOrLoopIndex = (**(code **)(*(int *)this + 0x4c))(this);
        poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
        allocPair = TPoolAllocator__allocate(poolAllocator,sizeOrLoopIndex << 2);
        resultOrOffset = (int)((ulonglong)allocPair >> 0x20);
        r4Value = (undefined4)allocPair;
        for (sizeOrLoopIndex = 0; countOrResult = (**(code **)(*(int *)this + 0x4c))(this,r4Value), sizeOrLoopIndex < countOrResult;
            sizeOrLoopIndex = sizeOrLoopIndex + 1) {
          (**(code **)(*(int *)this + 0x38))(&binaryTypeVtbl,this);
          binaryTypeVtbl = (undefined **)(picBase - 0x473c);
          if ((binaryTypeBits >> 0x13 & 0x3f) != 3) {
            message = "Constant folding cannot be done for \"||\"";
            typeBitsOrLoc = (*(code *)**(undefined4 **)this)(this,r4In5,newNodeOrRightArg,infoSinkArg,sizeOrIndex,unusedArg6,picBase)
            ;
                    
            goto override_jmp_97b9198c_case_0;
          }
          r4Value = 0;
          if ((*(int *)(thisUnion + sizeOrLoopIndex * 4) != 0) || (**(int **)(sizeOrArrayOrIndex + 0x30) != 0)) {
            r4Value = 1;
          }
          *(undefined4 *)(sizeOrLoopIndex * 4 + resultOrOffset) = r4Value;
          r4Value = r4In5;
        }
        break;
      case 0x18:
        picBase = 0xa7b81734;
        resultOrOffset = (**(code **)(*(int *)this + 0x4c))(this);
        poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
        allocPair = TPoolAllocator__allocate(poolAllocator,resultOrOffset << 2);
        resultOrOffset = (int)((ulonglong)allocPair >> 0x20);
        r4Value = (undefined4)allocPair;
        for (countOrResult = 0;
            sizeOrLoopIndex = (**(code **)(*(int *)this + 0x4c))
                               (this,r4Value,newNodeOrRightArg,infoSinkArg,sizeOrIndex,unusedArg6,sizeOrLoopIndex), countOrResult < sizeOrLoopIndex;
            countOrResult = countOrResult + 1) {
          (**(code **)(*(int *)this + 0x38))(&binaryTypeVtbl,this);
          binaryTypeVtbl = (undefined **)(picBase - 0x473c);
          if ((binaryTypeBits >> 0x13 & 0x3f) != 3) {
            message = "Constant folding cannot be done for \"^^\"";
            typeBitsOrLoc = (*(code *)**(undefined4 **)this)(this,r4In4,newNodeOrRightArg,infoSinkArg,sizeOrIndex,unusedArg6,picBase)
            ;
                    
            goto override_jmp_97b9198c_case_0;
          }
          typeBitsOrLoc = *(uint *)(thisUnion + countOrResult * 4) ^ **(uint **)(sizeOrArrayOrIndex + 0x30);
          sizeOrLoopIndex = typeBitsOrLoc - 1;
          *(uint *)(countOrResult * 4 + resultOrOffset) = typeBitsOrLoc - (sizeOrLoopIndex + (uint)(typeBitsOrLoc == 0));
          r4Value = r4In4;
        }
        break;
      case 0x19:
        picBase = 0xa7b81734;
        sizeOrLoopIndex = (**(code **)(*(int *)this + 0x4c))(this,typeBitsOrLoc);
        poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
        resultOrOffset = TPoolAllocator__allocate(poolAllocator,sizeOrLoopIndex << 2);
        for (sizeOrLoopIndex = 0; countOrResult = (**(code **)(*(int *)this + 0x4c))(this), sizeOrLoopIndex < countOrResult;
            sizeOrLoopIndex = sizeOrLoopIndex + 1) {
          (**(code **)(*(int *)this + 0x38))(&binaryTypeVtbl,this);
          binaryTypeVtbl = (undefined **)(picBase - 0x473c);
          if ((binaryTypeBits >> 0x13 & 0x3f) != 3) {
            message = "Constant folding cannot be done for \"&&\"";
            typeBitsOrLoc = (*(code *)**(undefined4 **)this)(this,r4In3,newNodeOrRightArg,infoSinkArg,sizeOrIndex,unusedArg6,picBase)
            ;
                    
            goto override_jmp_97b9198c_case_0;
          }
          r4Value = 0;
          if ((*(int *)(thisUnion + sizeOrLoopIndex * 4) != 0) && (**(int **)(sizeOrArrayOrIndex + 0x30) != 0)) {
            r4Value = 1;
          }
          *(undefined4 *)(sizeOrLoopIndex * 4 + resultOrOffset) = r4Value;
        }
      }
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      newNodeOrRightArg = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x34);
      (**(code **)(*(int *)this + 0x38))(&binaryTypeVtbl,this);
      *(int *)(newNodeOrRightArg + 4) = 0;
      *(undefined ***)newNodeOrRightArg = &PTR_getLine_a7b7cf90;
      *(int *)(newNodeOrRightArg + 0xc) = binaryTypeWord1;
      binaryTypeVtbl = (undefined **)(picBase - 0x473c);
      *(int *)(newNodeOrRightArg + 0x10) = binaryTypeWord2;
      *(int *)(newNodeOrRightArg + 0x14) = binaryTypeWord3;
      *(int *)(newNodeOrRightArg + 0x18) = binaryTypeWord4OrLocText;
      *(int *)(newNodeOrRightArg + 0x1c) = binaryTypeWord5;
      *(int *)(newNodeOrRightArg + 0x20) = binaryTypeWord6;
      *(undefined ***)(newNodeOrRightArg + 8) = binaryTypeVtbl;
      *(int *)(newNodeOrRightArg + 0x24) = binaryTypeWord7;
      *(int *)(newNodeOrRightArg + 0x28) = binaryTypeWord8;
      nodeBitsBefore = *(uint *)(newNodeOrRightArg + 0x2c);
      bitsOrLine = binaryTypeBits & 0xfe000000;
      *(uint *)(newNodeOrRightArg + 0x2c) = bitsOrLine | nodeBitsBefore & 0x1ffffff;
      typeFieldOrInt = (binaryTypeBits >> 0x13 & 0x3f) << 0x13;
      *(uint *)(newNodeOrRightArg + 0x2c) = typeFieldOrInt | bitsOrLine | nodeBitsBefore & 0x7ffff;
      typeBitsOrLoc = binaryTypeBits & 0x7f800;
      *(uint *)(newNodeOrRightArg + 0x2c) = typeBitsOrLoc | typeFieldOrInt | bitsOrLine | nodeBitsBefore & 0x7ff;
      typeBit10 = (binaryTypeBits >> 10 & 1) << 10;
      *(uint *)(newNodeOrRightArg + 0x2c) = typeBit10 | typeBitsOrLoc | typeFieldOrInt | bitsOrLine | nodeBitsBefore & 0x3ff;
      refCountOrVtable = PTR_vtable_a7b7c0c8;
      *(uint *)(newNodeOrRightArg + 0x2c) =
           (binaryTypeBits >> 9 & 1) << 9 | typeBit10 | typeBitsOrLoc | typeFieldOrInt | bitsOrLine | nodeBitsBefore & 0x1ff;
      *(undefined **)newNodeOrRightArg = refCountOrVtable + 8;
      *(int *)(newNodeOrRightArg + 0x30) = resultOrOffset;
      goto LAB_97b94758;
    }
switchD_97b91834_caseD_15:
    message = "Invalid operator for constant folding";
    typeBitsOrLoc = (*(code *)**(undefined4 **)this)(this);
                    
    __ZN13TInfoSinkBase6appendEPKc(infoSink,"INTERNAL ERROR: ");
    bitsOrLine = typeBitsOrLoc & 0xffff;
    reservationOk = (bitsOrLine == 0) << 1;
    if (bitsOrLine == 0) {
      _sprintf((char *)&binaryTypeWord4OrLocText,"%d:? ",(int)typeBitsOrLoc >> 0x10);
    }
    else {
      _sprintf((char *)&binaryTypeWord4OrLocText,"%d:%d",(int)typeBitsOrLoc >> 0x10,bitsOrLine);
    }
    locText = (unsigned char *)&binaryTypeWord4OrLocText;
    __ZNSsC1EPKcRKSaIcE(&binaryTypeVtbl,(char *)locText,(unsigned char *)&compareTypeWord8);
    *(undefined *)((int)binaryTypeVtbl + (int)binaryTypeVtbl[-3]) = *PTR__S_terminal_a7b7c0b8;
    __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)binaryTypeVtbl);
    refCountPtrCopy = binaryTypeVtbl + -1;
    do {
      refCountOrVtable = *refCountPtrCopy;
      if (reservation != '\0') {
        newRefCount = (undefined *)storeWordConditionalIndexed(refCountOrVtable + -1,0,refCountPtrCopy);
        *refCountPtrCopy = newRefCount;
        reservationOk = 2;
      }
      refCountPtr = binaryTypeVtbl;
    } while (!(bool)(reservationOk >> 1 & 1));
    goto joined_r0x97b95b7c;
  }
LAB_97b92a7c:
  sizeOrArrayOrIndex = (**(code **)(*(int *)rightOperand + 0x18))(rightOperand);
  if (sizeOrArrayOrIndex != 0) {
    sizeOrArrayOrIndex = (**(code **)(*(int *)this + 0x4c))(this);
    r4Value = r4Out0;
    if (sizeOrArrayOrIndex < 2) {
      picBase = 0xa7b81734;
      (**(code **)(*(int *)this + 0x38))(&binaryTypeVtbl,this);
      binaryTypeVtbl = (undefined **)(picBase - 0x473c);
      r4Value = r4Out1;
      unusedArg7 = picBase;
      if ((binaryTypeBits >> 0x13 & 0x3f) != 0xe) goto LAB_97b9478c;
    }
    sizeOrArrayOrIndex = 0;
    flagOrCompare = false;
    rightConstUnion = (int *)(**(code **)(*(int *)rightOperand + 0x18))
                          (rightOperand,r4Value,newNodeOrRightArg,infoSinkArg,sizeOrIndex,unusedArg6,unusedArg7);
    typeBitsOrLoc = op - 0x13;
    resultOrRightFloats = (float *)rightConstUnion[0xc];
    compareStructureOut = 0;
    if (0x43 < typeBitsOrLoc) {
switchD_97b92b40_caseD_17:
      message = "Invalid operator for constant folding";
      typeBitsOrLoc = (*(code *)**(undefined4 **)this)(this);
                    
override_jmp_97b938f4_case_0:
      __ZN13TInfoSinkBase6appendEPKc(infoSink,"INTERNAL ERROR: ");
      bitsOrLine = typeBitsOrLoc & 0xffff;
      reservationOk = (bitsOrLine == 0) << 1;
      if (bitsOrLine == 0) {
        _sprintf((char *)&compareTypeWord4OrLocText,"%d:? ",(int)typeBitsOrLoc >> 0x10);
      }
      else {
        _sprintf((char *)&compareTypeWord4OrLocText,"%d:%d",(int)typeBitsOrLoc >> 0x10,bitsOrLine);
      }
code_r0x97b945f4:
      __ZNSsC1EPKcRKSaIcE(&compareTypeVtbl,(char *)&compareTypeWord4OrLocText,stringAllocator);
      *(undefined *)((int)compareTypeVtbl + (int)compareTypeVtbl[-3]) = *PTR__S_terminal_a7b7c0b8;
      __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)compareTypeVtbl);
      refCountPtr = compareTypeVtbl + -1;
      do {
        refCountOrVtable = *refCountPtr;
        if (reservation != '\0') {
          newRefCount = (undefined *)storeWordConditionalIndexed(refCountOrVtable + -1,0,refCountPtr);
          *refCountPtr = newRefCount;
          reservationOk = 2;
        }
      } while (!(bool)(reservationOk >> 1 & 1));
      locText = (unsigned char *)&compareTypeWord4OrLocText;
      refCountPtr = compareTypeVtbl;
      goto joined_r0x97b95b7c;
    }
    sizeOrLoopIndex = typeBitsOrLoc * 4;
    switch(typeBitsOrLoc) {
    case 0:
      picBase = 0xa7b81734;
      sizeOrArrayOrIndex = (**(code **)(*(int *)this + 0x4c))(this,typeBitsOrLoc,newNodeOrRightArg,infoSinkArg,sizeOrIndex,unusedArg6,sizeOrLoopIndex);
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      allocPair = TPoolAllocator__allocate(poolAllocator,sizeOrArrayOrIndex << 2);
      sizeOrArrayOrIndex = (int)((ulonglong)allocPair >> 0x20);
      r4Value = (undefined4)allocPair;
      for (sizeOrLoopIndex = 0; resultOrOffset = (**(code **)(*(int *)this + 0x4c))(this,r4Value), sizeOrLoopIndex < resultOrOffset;
          sizeOrLoopIndex = sizeOrLoopIndex + 1) {
        (**(code **)(*(int *)this + 0x38))(&compareTypeVtbl,this);
        typeBitsOrLoc = compareTypeBits >> 0x13 & 0x3f;
        compareTypeVtbl = (undefined **)(picBase - 0x473c);
        if (typeBitsOrLoc != 1) {
          if (typeBitsOrLoc == 2) {
            *(int *)(sizeOrArrayOrIndex + sizeOrLoopIndex * 4) = *(int *)(thisUnion + sizeOrLoopIndex * 4) + (int)GH_F2U(resultOrRightFloats[sizeOrLoopIndex]);
            goto LAB_97b92dd4;
          }
          message = "Constant folding cannot be done for \"+\"";
          typeBitsOrLoc = (*(code *)**(undefined4 **)this)(this,r4In6,newNodeOrRightArg,infoSinkArg,sizeOrIndex,unusedArg6,picBase);
                    
          __ZN13TInfoSinkBase6appendEPKc(infoSink,"INTERNAL ERROR: ");
          bitsOrLine = typeBitsOrLoc & 0xffff;
          reservationOk = (bitsOrLine == 0) << 1;
          if (bitsOrLine == 0) {
            _sprintf((char *)&compareTypeWord4OrLocText,"%d:? ",(int)typeBitsOrLoc >> 0x10);
          }
          else {
            _sprintf((char *)&compareTypeWord4OrLocText,"%d:%d",(int)typeBitsOrLoc >> 0x10,bitsOrLine);
          }
          locText = (unsigned char *)&tailTypeWord4OrLocText;
code_r0x97b93f6c:
          __ZNSsC1EPKcRKSaIcE(&compareTypeVtbl,(char *)&compareTypeWord4OrLocText,locText);
          *(undefined *)((int)compareTypeVtbl + (int)compareTypeVtbl[-3]) = *PTR__S_terminal_a7b7c0b8;
          __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)compareTypeVtbl);
          refCountPtr = compareTypeVtbl + -1;
          stringRep = (unsigned char *)(compareTypeVtbl + -3);
          do {
            refCountOrVtable = *refCountPtr;
            if (reservation != '\0') {
              newRefCount = (undefined *)storeWordConditionalIndexed(refCountOrVtable + -1,0,refCountPtr);
              *refCountPtr = newRefCount;
              reservationOk = 2;
            }
          } while (!(bool)(reservationOk >> 1 & 1));
          flagOrCompare = 0 < (int)refCountOrVtable;
          locText = (unsigned char *)&compareTypeWord4OrLocText;
          goto code_r0x97b93fb8;
        }
        *(float *)(sizeOrArrayOrIndex + sizeOrLoopIndex * 4) = *(float *)(thisUnion + sizeOrLoopIndex * 4) + resultOrRightFloats[sizeOrLoopIndex];
LAB_97b92dd4:
        r4Value = r4In6;
      }
      break;
    case 1:
      picBase = 0xa7b81734;
      sizeOrArrayOrIndex = (**(code **)(*(int *)this + 0x4c))(this);
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      allocPair = TPoolAllocator__allocate(poolAllocator,sizeOrArrayOrIndex << 2);
      sizeOrArrayOrIndex = (int)((ulonglong)allocPair >> 0x20);
      r4Value = (undefined4)allocPair;
      for (sizeOrLoopIndex = 0; resultOrOffset = (**(code **)(*(int *)this + 0x4c))(this,r4Value), sizeOrLoopIndex < resultOrOffset;
          sizeOrLoopIndex = sizeOrLoopIndex + 1) {
        (**(code **)(*(int *)this + 0x38))(&compareTypeVtbl,this);
        typeBitsOrLoc = compareTypeBits >> 0x13 & 0x3f;
        compareTypeVtbl = (undefined **)(picBase - 0x473c);
        if (typeBitsOrLoc == 1) {
          if (swapOperands == 0) {
            rightOrResultValue = resultOrRightFloats[sizeOrLoopIndex];
            leftValue = *(float *)(thisUnion + sizeOrLoopIndex * 4);
          }
          else {
            rightOrResultValue = *(float *)(thisUnion + sizeOrLoopIndex * 4);
            leftValue = resultOrRightFloats[sizeOrLoopIndex];
          }
          *(float *)(sizeOrArrayOrIndex + sizeOrLoopIndex * 4) = rightOrResultValue - leftValue;
        }
        else {
          if (typeBitsOrLoc != 2) {
            message = "Constant folding cannot be done for \"-\"";
            typeBitsOrLoc = (*(code *)**(undefined4 **)this)(this,r4In7,newNodeOrRightArg,infoSinkArg,sizeOrIndex,unusedArg6,picBase)
            ;
                    
            __ZN13TInfoSinkBase6appendEPKc(infoSink,"INTERNAL ERROR: ");
            bitsOrLine = typeBitsOrLoc & 0xffff;
            reservationOk = (bitsOrLine == 0) << 1;
            if (bitsOrLine == 0) {
              _sprintf((char *)&compareTypeWord4OrLocText,"%d:? ",(int)typeBitsOrLoc >> 0x10);
            }
            else {
              _sprintf((char *)&compareTypeWord4OrLocText,"%d:%d",(int)typeBitsOrLoc >> 0x10,bitsOrLine);
            }
            locText = (unsigned char *)&tailTypeWord8;
            goto code_r0x97b93f6c;
          }
          if (swapOperands == 0) {
            rightOrResultValue = resultOrRightFloats[sizeOrLoopIndex];
            leftValue = *(float *)(thisUnion + sizeOrLoopIndex * 4);
          }
          else {
            rightOrResultValue = *(float *)(thisUnion + sizeOrLoopIndex * 4);
            leftValue = resultOrRightFloats[sizeOrLoopIndex];
          }
          *(int *)(sizeOrArrayOrIndex + sizeOrLoopIndex * 4) = (int)GH_F2U(rightOrResultValue) - (int)GH_F2U(leftValue);
        }
        r4Value = r4In7;
      }
      break;
    case 2:
      sizeOrLoopIndex = (**(code **)(*(int *)this + 0x58))(this);
      if (sizeOrLoopIndex != 0) {
        resultOrOffset = 0;
        sizeOrLoopIndex = (**(code **)(*(int *)this + 0x4c))(this);
        poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
        sizeOrArrayOrIndex = TPoolAllocator__allocate(poolAllocator,sizeOrLoopIndex << 2);
        if (0 < sizeOrLoopIndex) {
          picBase = 0xa7b81734;
          do {
            (**(code **)(*(int *)this + 0x38))(&compareTypeVtbl,this);
            typeBitsOrLoc = compareTypeBits >> 0x13 & 0x3f;
            compareTypeVtbl = (undefined **)(picBase - 0x473c);
            if (typeBitsOrLoc == 1) {
              *(float *)(sizeOrArrayOrIndex + resultOrOffset * 4) = *(float *)(thisUnion + resultOrOffset * 4) * resultOrRightFloats[resultOrOffset];
            }
            else {
              if (typeBitsOrLoc != 2) {
                message = "Constant folding cannot be done for vector multiply";
                typeBitsOrLoc = (*(code *)**(undefined4 **)this)
                                   (this,r4In8,newNodeOrRightArg,infoSinkArg,sizeOrIndex,unusedArg6,picBase);
                    
                __ZN13TInfoSinkBase6appendEPKc(infoSink,"INTERNAL ERROR: ");
                bitsOrLine = typeBitsOrLoc & 0xffff;
                reservationOk = (bitsOrLine == 0) << 1;
                if (bitsOrLine == 0) {
                  _sprintf((char *)&compareTypeWord4OrLocText,"%d:? ",(int)typeBitsOrLoc >> 0x10);
                }
                else {
                  _sprintf((char *)&compareTypeWord4OrLocText,"%d:%d",(int)typeBitsOrLoc >> 0x10,bitsOrLine);
                }
                locText = stringAllocator2;
                goto code_r0x97b93f6c;
              }
              *(int *)(sizeOrArrayOrIndex + resultOrOffset * 4) = *(int *)(thisUnion + resultOrOffset * 4) * (int)GH_F2U(resultOrRightFloats[resultOrOffset]);
            }
            resultOrOffset = resultOrOffset + 1;
          } while (resultOrOffset < sizeOrLoopIndex);
          break;
        }
      }
      picBase = 0xa7b81734;
      break;
    case 3:
      picBase = 0xa7b81734;
      sizeOrIndex = (**(code **)(*(int *)this + 0x4c))(this);
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      sizeOrArrayOrIndex = TPoolAllocator__allocate(poolAllocator,sizeOrIndex << 2);
      for (sizeOrIndex = 0; sizeOrLoopIndex = (**(code **)(*(int *)this + 0x4c))(this), sizeOrIndex < sizeOrLoopIndex;
          sizeOrIndex = sizeOrIndex + 1) {
        (**(code **)(*(int *)this + 0x38))(&compareTypeVtbl,this);
        typeBitsOrLoc = compareTypeBits >> 0x13 & 0x3f;
        compareTypeVtbl = (undefined **)(picBase - 0x473c);
        if (typeBitsOrLoc != 1) {
          if (typeBitsOrLoc == 2) {
            if (swapOperands == 0) {
              rightOrResultValue = *(float *)(thisUnion + sizeOrIndex * 4);
              if (rightOrResultValue == 0.0) {
                typeBitsOrLoc = (*(code *)**(undefined4 **)this)(this);
                    
                goto override_jmp_97b93698_case_0;
              }
              leftValue = resultOrRightFloats[sizeOrIndex];
code_r0x97b93828:
              sizeOrLoopIndex = (int)GH_F2U(leftValue) / (int)GH_F2U(rightOrResultValue);
            }
            else {
              rightOrResultValue = resultOrRightFloats[sizeOrIndex];
              if (rightOrResultValue != 0.0) {
                leftValue = *(float *)(thisUnion + sizeOrIndex * 4);
                goto code_r0x97b93828;
              }
              typeBitsOrLoc = (*(code *)**(undefined4 **)this)(this);
                    
override_jmp_97b93698_case_0:
              __ZN13TInfoSinkBase6appendEPKc(infoSink,"WARNING: ");
              bitsOrLine = typeBitsOrLoc & 0xffff;
              reservationOk = (bitsOrLine == 0) << 1;
              if (bitsOrLine == 0) {
                _sprintf((char *)&compareTypeWord4OrLocText,"%d:? ",(int)typeBitsOrLoc >> 0x10);
              }
              else {
                _sprintf((char *)&compareTypeWord4OrLocText,"%d:%d",(int)typeBitsOrLoc >> 0x10,bitsOrLine);
              }
              __ZNSsC1EPKcRKSaIcE(&compareTypeVtbl,(char *)&compareTypeWord4OrLocText,stringAllocator);
              *(undefined *)((int)compareTypeVtbl + (int)compareTypeVtbl[-3]) = *PTR__S_terminal_a7b7c0b8;
              __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)compareTypeVtbl);
              refCountPtr = compareTypeVtbl + -1;
              do {
                refCountOrVtable = *refCountPtr;
                if (reservation != '\0') {
                  newRefCount = (undefined *)storeWordConditionalIndexed(refCountOrVtable + -1,0,refCountPtr);
                  *refCountPtr = newRefCount;
                  reservationOk = 2;
                }
              } while (!(bool)(reservationOk >> 1 & 1));
              if ((int)refCountOrVtable < 1) {
                __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(compareTypeVtbl + -3),&compareTypeWord4OrLocText);
              }
              __ZN13TInfoSinkBase6appendEPKc(infoSink,": ");
              __ZN13TInfoSinkBase6appendEPKc(infoSink,"Divide by zero error during constant folding")
              ;
              __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
              sizeOrLoopIndex = 0x7fffffff;
            }
            *(int *)(sizeOrIndex * 4 + sizeOrArrayOrIndex) = sizeOrLoopIndex;
            goto code_r0x97b93884;
          }
          message = "Constant folding cannot be done for \"/\"";
          typeBitsOrLoc = (*(code *)**(undefined4 **)this)(this);
                    
override_jmp_97b93868_case_0:
          __ZN13TInfoSinkBase6appendEPKc(infoSink,"INTERNAL ERROR: ");
          bitsOrLine = typeBitsOrLoc & 0xffff;
          reservationOk = (bitsOrLine == 0) << 1;
          if (bitsOrLine == 0) {
            _sprintf((char *)&compareTypeWord4OrLocText,"%d:? ",(int)typeBitsOrLoc >> 0x10);
          }
          else {
            _sprintf((char *)&compareTypeWord4OrLocText,"%d:%d",(int)typeBitsOrLoc >> 0x10,bitsOrLine);
          }
          locText = stringAllocator;
          goto code_r0x97b93f6c;
        }
        if (swapOperands == 0) {
          rightOrResultValue = *(float *)(thisUnion + sizeOrIndex * 4);
          if (rightOrResultValue == 0.0) {
            typeBitsOrLoc = (*(code *)**(undefined4 **)this)(this);
                    
            goto override_jmp_97b934a8_case_0;
          }
          leftValue = resultOrRightFloats[sizeOrIndex];
code_r0x97b93640:
          leftValue = leftValue / rightOrResultValue;
        }
        else {
          rightOrResultValue = resultOrRightFloats[sizeOrIndex];
          if (rightOrResultValue != 0.0) {
            leftValue = *(float *)(thisUnion + sizeOrIndex * 4);
            goto code_r0x97b93640;
          }
          typeBitsOrLoc = (*(code *)**(undefined4 **)this)(this);
                    
override_jmp_97b934a8_case_0:
          __ZN13TInfoSinkBase6appendEPKc(infoSink,"WARNING: ");
          bitsOrLine = typeBitsOrLoc & 0xffff;
          reservationOk = (bitsOrLine == 0) << 1;
          if (bitsOrLine == 0) {
            _sprintf((char *)&compareTypeWord4OrLocText,"%d:? ",(int)typeBitsOrLoc >> 0x10);
          }
          else {
            _sprintf((char *)&compareTypeWord4OrLocText,"%d:%d",(int)typeBitsOrLoc >> 0x10,bitsOrLine);
          }
          __ZNSsC1EPKcRKSaIcE(&compareTypeVtbl,(char *)&compareTypeWord4OrLocText,stringAllocator);
          *(undefined *)((int)compareTypeVtbl + (int)compareTypeVtbl[-3]) = *PTR__S_terminal_a7b7c0b8;
          __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)compareTypeVtbl);
          refCountPtr = compareTypeVtbl + -1;
          do {
            refCountOrVtable = *refCountPtr;
            if (reservation != '\0') {
              newRefCount = (undefined *)storeWordConditionalIndexed(refCountOrVtable + -1,0,refCountPtr);
              *refCountPtr = newRefCount;
              reservationOk = 2;
            }
          } while (!(bool)(reservationOk >> 1 & 1));
          if ((int)refCountOrVtable < 1) {
            __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(compareTypeVtbl + -3),&compareTypeWord4OrLocText);
          }
          __ZN13TInfoSinkBase6appendEPKc(infoSink,": ");
          __ZN13TInfoSinkBase6appendEPKc(infoSink,"Divide by zero error during constant folding");
          __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
          leftValue = 3.4028235e+38;
        }
        *(float *)(sizeOrIndex * 4 + sizeOrArrayOrIndex) = leftValue;
code_r0x97b93884: ;
      }
      break;
    default:
      goto switchD_97b92b40_caseD_17;
    case 10:
      picBase = 0xa7b81734;
      (**(code **)(*(int *)this + 0x38))((unsigned char *)&compareTypeVtbl,this);
      typeBitsOrLoc = compareTypeBits >> 0x13 & 0x3f;
      refCountPtr = (undefined **)(picBase - 0x473c);
      compareTypeVtbl = refCountPtr;
      if (typeBitsOrLoc == 2) {
        r4Value = r4Out4;
        rightOrResultValue = GH_U2F((unsigned int)(picBase));
        for (sizeOrArrayOrIndex = 0;
            sizeOrLoopIndex = (**(code **)(*(int *)this + 0x4c))(this,r4Value,newNodeOrRightArg,infoSinkArg,sizeOrIndex,unusedArg6,rightOrResultValue)
            , sizeOrArrayOrIndex < sizeOrLoopIndex; sizeOrArrayOrIndex = sizeOrArrayOrIndex + 1) {
          rightOrResultValue = resultOrRightFloats[sizeOrArrayOrIndex];
          if (*(float *)(thisUnion + sizeOrArrayOrIndex * 4) != rightOrResultValue) goto LAB_97b94304;
          r4Value = r4Out6;
        }
        goto LAB_97b943d4;
      }
      if (2 < typeBitsOrLoc) {
        if (typeBitsOrLoc == 3) {
          r4Value = r4Out4;
          rightOrResultValue = GH_U2F((unsigned int)(picBase));
          for (sizeOrArrayOrIndex = 0;
              sizeOrLoopIndex = (**(code **)(*(int *)this + 0x4c))
                                 (this,r4Value,newNodeOrRightArg,infoSinkArg,sizeOrIndex,unusedArg6,rightOrResultValue), sizeOrArrayOrIndex < sizeOrLoopIndex;
              sizeOrArrayOrIndex = sizeOrArrayOrIndex + 1) {
            rightOrResultValue = resultOrRightFloats[sizeOrArrayOrIndex];
            if (*(float *)(thisUnion + sizeOrArrayOrIndex * 4) != rightOrResultValue) goto LAB_97b94304;
            r4Value = r4Out7;
          }
        }
        else {
          if (typeBitsOrLoc != 0xe) goto LAB_97b9414c;
          thisOrRightCursor = (unsigned char *)rightConstUnion[0xc];
          (**(code **)(*rightConstUnion + 0x38))((unsigned char *)&compareTypeVtbl,rightConstUnion);
          sizeOrIndex = ((int (*)())compareStructure)((unsigned char *)&compareTypeVtbl,thisOrRightCursor,thisUnion,&compareStructureOut);
          sizeFlag = sizeOrIndex == 1;
LAB_97b942fc:
          compareTypeVtbl = refCountPtr;
          if (!sizeFlag) {
LAB_97b94304:
            flagOrCompare = true;
          }
        }
        goto LAB_97b943d4;
      }
      if (typeBitsOrLoc == 1) {
        r4Value = r4Out4;
        typeBitsOrLoc = picBase;
        for (sizeOrArrayOrIndex = 0;
            sizeOrLoopIndex = (**(code **)(*(int *)this + 0x4c))
                               (this,r4Value,newNodeOrRightArg,infoSinkArg,sizeOrIndex,unusedArg6,typeBitsOrLoc), sizeOrArrayOrIndex < sizeOrLoopIndex;
            sizeOrArrayOrIndex = sizeOrArrayOrIndex + 1) {
          if (*(float *)(thisUnion + sizeOrArrayOrIndex * 4) != resultOrRightFloats[sizeOrArrayOrIndex]) goto LAB_97b94304;
          r4Value = r4Out5;
        }
        goto LAB_97b943d4;
      }
LAB_97b9414c:
      message = "Constant folding cannot be done for \"==\"";
      typeBitsOrLoc = (*(code *)**(undefined4 **)this)(this);
                    
override_jmp_97b94180_case_0:
      __ZN13TInfoSinkBase6appendEPKc(infoSink,"INTERNAL ERROR: ");
      bitsOrLine = typeBitsOrLoc & 0xffff;
      reservationOk = (bitsOrLine == 0) << 1;
      if (bitsOrLine == 0) {
        _sprintf((char *)&compareTypeWord4OrLocText,"%d:? ",(int)typeBitsOrLoc >> 0x10);
      }
      else {
        _sprintf((char *)&compareTypeWord4OrLocText,"%d:%d",(int)typeBitsOrLoc >> 0x10,bitsOrLine);
      }
      goto code_r0x97b945f4;
    case 0xb:
      picBase = 0xa7b81734;
      (**(code **)(*(int *)this + 0x38))((unsigned char *)&compareTypeVtbl,this);
      typeBitsOrLoc = compareTypeBits >> 0x13 & 0x3f;
      refCountPtr = (undefined **)(picBase - 0x473c);
      compareTypeVtbl = refCountPtr;
      if (typeBitsOrLoc == 2) {
        r4Value = r4Out8;
        rightOrResultValue = GH_U2F((unsigned int)(picBase));
        for (sizeOrArrayOrIndex = 0;
            sizeOrLoopIndex = (**(code **)(*(int *)this + 0x4c))(this,r4Value,newNodeOrRightArg,infoSinkArg,sizeOrIndex,unusedArg6,rightOrResultValue)
            , sizeOrArrayOrIndex < sizeOrLoopIndex; sizeOrArrayOrIndex = sizeOrArrayOrIndex + 1) {
          rightOrResultValue = resultOrRightFloats[sizeOrArrayOrIndex];
          if (*(float *)(thisUnion + sizeOrArrayOrIndex * 4) == rightOrResultValue) goto LAB_97b94304;
          r4Value = r4Out10;
        }
      }
      else if (typeBitsOrLoc < 3) {
        if (typeBitsOrLoc != 1) {
LAB_97b9430c:
          message = "Constant folding cannot be done for \"!=\"";
          typeBitsOrLoc = (*(code *)**(undefined4 **)this)(this);
                    
          goto override_jmp_97b94180_case_0;
        }
        r4Value = r4Out8;
        typeBitsOrLoc = picBase;
        for (sizeOrArrayOrIndex = 0;
            sizeOrLoopIndex = (**(code **)(*(int *)this + 0x4c))
                               (this,r4Value,newNodeOrRightArg,infoSinkArg,sizeOrIndex,unusedArg6,typeBitsOrLoc), sizeOrArrayOrIndex < sizeOrLoopIndex;
            sizeOrArrayOrIndex = sizeOrArrayOrIndex + 1) {
          if (*(float *)(thisUnion + sizeOrArrayOrIndex * 4) == resultOrRightFloats[sizeOrArrayOrIndex]) goto LAB_97b94304;
          r4Value = r4Out9;
        }
      }
      else {
        if (typeBitsOrLoc != 3) {
          if (typeBitsOrLoc == 0xe) {
            thisOrRightCursor = (unsigned char *)rightConstUnion[0xc];
            (**(code **)(*rightConstUnion + 0x38))((unsigned char *)&compareTypeVtbl,rightConstUnion);
            sizeOrIndex = ((int (*)())compareStructure)((unsigned char *)&compareTypeVtbl,thisOrRightCursor,thisUnion,&compareStructureOut);
            sizeFlag = sizeOrIndex == 0;
            goto LAB_97b942fc;
          }
          goto LAB_97b9430c;
        }
        r4Value = r4Out8;
        rightOrResultValue = GH_U2F((unsigned int)(picBase));
        for (sizeOrArrayOrIndex = 0;
            sizeOrLoopIndex = (**(code **)(*(int *)this + 0x4c))(this,r4Value,newNodeOrRightArg,infoSinkArg,sizeOrIndex,unusedArg6,rightOrResultValue)
            , sizeOrArrayOrIndex < sizeOrLoopIndex; sizeOrArrayOrIndex = sizeOrArrayOrIndex + 1) {
          rightOrResultValue = resultOrRightFloats[sizeOrArrayOrIndex];
          if (*(float *)(thisUnion + sizeOrArrayOrIndex * 4) == rightOrResultValue) goto LAB_97b94304;
          r4Value = r4Out11;
        }
      }
LAB_97b943d4:
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      resultBool = (uint *)TPoolAllocator__allocate(poolAllocator,4);
      *resultBool = (uint)!flagOrCompare;
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      newNodeOrRightArg = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x34);
      compareTypeBits = compareTypeBits & 0x1801ff | 0x4180800;
      compareTypeVtbl = (undefined **)(picBase - 0x473c);
      compareTypeWord1 = 0;
      compareTypeWord3 = 0;
      compareTypeWord4OrLocText = 0;
      compareTypeWord5 = 0;
      compareTypeWord6 = 0;
      compareTypeWord7 = 0;
      compareTypeWord8 = 0;
      compareTypeWord2 = 0;
      *(int *)(newNodeOrRightArg + 4) = 0;
      *(undefined ***)newNodeOrRightArg = &PTR_getLine_a7b7cf90;
      *(int *)(newNodeOrRightArg + 0xc) = 0;
      *(int *)(newNodeOrRightArg + 0x10) = 0;
      *(int *)(newNodeOrRightArg + 0x14) = 0;
      *(int *)(newNodeOrRightArg + 0x18) = 0;
      *(int *)(newNodeOrRightArg + 0x1c) = 0;
      *(int *)(newNodeOrRightArg + 0x20) = 0;
      *(undefined ***)(newNodeOrRightArg + 8) = compareTypeVtbl;
      *(int *)(newNodeOrRightArg + 0x24) = 0;
      *(int *)(newNodeOrRightArg + 0x28) = 0;
      bitsOrLine = *(uint *)(newNodeOrRightArg + 0x2c);
      *(uint *)(newNodeOrRightArg + 0x2c) = bitsOrLine & 0x1ffffff | 0x4000000;
      typeBitsOrLoc = (compareTypeBits >> 0x13 & 0x3f) << 0x13;
      *(uint *)(newNodeOrRightArg + 0x2c) = typeBitsOrLoc | bitsOrLine & 0x7ffff | 0x4000000;
      *(uint *)(newNodeOrRightArg + 0x2c) = typeBitsOrLoc | bitsOrLine & 0x7ff | 0x4000000 | 0x800;
      *(uint *)(newNodeOrRightArg + 0x2c) = typeBitsOrLoc | bitsOrLine & 0x3ff | 0x4000000 | 0x800;
      refCountOrVtable = PTR_vtable_a7b7c0c8;
      *(uint *)(newNodeOrRightArg + 0x2c) = typeBitsOrLoc | bitsOrLine & 0x1ff | 0x4000000 | 0x800;
      *(uint **)(newNodeOrRightArg + 0x30) = resultBool;
      *(undefined **)newNodeOrRightArg = refCountOrVtable + 8;
      nodeOrVtable = *(undefined4 **)this;
      rightOperand = this;
LAB_97b953d4:
      sizeOrIndex = *(int *)newNodeOrRightArg;
      r4Value = (*(code *)*nodeOrVtable)(rightOperand);
      (**(code **)(sizeOrIndex + 4))(newNodeOrRightArg,r4Value);
      return newNodeOrRightArg;
    case 0x14:
      picBase = 0xa7b81734;
      (**(code **)(*(int *)this + 0x38))(&compareTypeVtbl,this);
      compareTypeVtbl = (undefined **)(picBase - 0x473c);
      if ((compareTypeBits >> 0x13 & 0x3f) != 1) {
        message = "Constant Folding cannot be done for vector times matrix";
        typeBitsOrLoc = (*(code *)**(undefined4 **)this)(this,r4In9,newNodeOrRightArg,infoSinkArg,sizeOrIndex,unusedArg6,picBase);
                    
        __ZN13TInfoSinkBase6appendEPKc(infoSink,"INTERNAL ERROR: ");
        bitsOrLine = typeBitsOrLoc & 0xffff;
        reservationOk = (bitsOrLine == 0) << 1;
        if (bitsOrLine == 0) {
          _sprintf((char *)locTextBuf,"%d:? ",(int)typeBitsOrLoc >> 0x10);
        }
        else {
          _sprintf((char *)locTextBuf,"%d:%d",(int)typeBitsOrLoc >> 0x10,bitsOrLine);
        }
        locText = locTextBuf;
        __ZNSsC1EPKcRKSaIcE(rightTypeOrString,(char *)locText,(unsigned char *)&tailTypeWord8);
        *(undefined *)((int)rightTypeOrString[0] + (int)rightTypeOrString[0][-3]) = *PTR__S_terminal_a7b7c0b8;
        __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)rightTypeOrString[0]);
        refCountPtr = rightTypeOrString[0];
        goto code_r0x97b95b60;
      }
      sizeOrIndex = (**(code **)(*(int *)this + 0x48))(this,r4In9);
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      sizeOrArrayOrIndex = TPoolAllocator__allocate(poolAllocator,sizeOrIndex << 2);
      sizeOrIndex = (**(code **)(*(int *)this + 0x48))(this);
      sizeOrLoopIndex = 0;
      if (0 < sizeOrIndex) {
        resultOrOffset = 0;
        do {
          countOrResult = sizeOrLoopIndex * 4;
          *(undefined4 *)(countOrResult + sizeOrArrayOrIndex) = 0;
          if (0 < sizeOrIndex) {
            resultCursor = resultOrRightFloats + resultOrOffset;
            thisOrRightCursor = thisUnion;
            columnOffset = sizeOrIndex;
            do {
              rightOrResultValue = *(float *)thisOrRightCursor;
              thisOrRightCursor = thisOrRightCursor + 4;
              leftValue = *resultCursor;
              resultCursor = resultCursor + 1;
              *(float *)(countOrResult + sizeOrArrayOrIndex) = rightOrResultValue * leftValue + *(float *)(countOrResult + sizeOrArrayOrIndex);
              columnOffset = columnOffset + -1;
            } while (columnOffset != 0);
          }
          sizeOrLoopIndex = sizeOrLoopIndex + 1;
          resultOrOffset = resultOrOffset + sizeOrIndex;
        } while (sizeOrLoopIndex < sizeOrIndex);
      }
      break;
    case 0x15:
      sizeOrIndex = (**(code **)(*rightConstUnion + 0x40))(rightConstUnion,typeBitsOrLoc);
      if (sizeOrIndex != 1) {
        message = "Constant Folding cannot be done for matrix times vector";
        typeBitsOrLoc = (*(code *)**(undefined4 **)this)(this);
                    
        goto override_jmp_97b938f4_case_0;
      }
      sizeOrIndex = (**(code **)(*(int *)this + 0x48))(this);
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      sizeOrArrayOrIndex = TPoolAllocator__allocate(poolAllocator,sizeOrIndex << 2);
      sizeOrIndex = (**(code **)(*(int *)this + 0x48))(this);
      sizeOrLoopIndex = 0;
      if (0 < sizeOrIndex) {
        resultOrOffset = 0;
        do {
          *(undefined4 *)(resultOrOffset + sizeOrArrayOrIndex) = 0;
          if (0 < sizeOrIndex) {
            thisOrRightCursor = thisUnion + resultOrOffset;
            resultCursor = resultOrRightFloats;
            countOrResult = sizeOrIndex;
            do {
              rightOrResultValue = *(float *)thisOrRightCursor;
              thisOrRightCursor = thisOrRightCursor + sizeOrIndex * 4;
              leftValue = *resultCursor;
              resultCursor = resultCursor + 1;
              *(float *)(resultOrOffset + sizeOrArrayOrIndex) = rightOrResultValue * leftValue + *(float *)(resultOrOffset + sizeOrArrayOrIndex);
              countOrResult = countOrResult + -1;
            } while (countOrResult != 0);
          }
          sizeOrLoopIndex = sizeOrLoopIndex + 1;
          resultOrOffset = resultOrOffset + 4;
        } while (sizeOrLoopIndex < sizeOrIndex);
      }
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      newNodeOrRightArg = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x34);
      (**(code **)(*rightConstUnion + 0x38))(&compareTypeVtbl,rightConstUnion);
      *(undefined ***)newNodeOrRightArg = &PTR_getLine_a7b7cf90;
      refCountOrVtable = &TType__vtable;
      *(int *)(newNodeOrRightArg + 4) = 0;
      goto LAB_97b946a4;
    case 0x17:
      picBase = 0xa7b81734;
      sizeOrArrayOrIndex = (**(code **)(*(int *)this + 0x4c))(this);
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      allocPair = TPoolAllocator__allocate(poolAllocator,sizeOrArrayOrIndex << 2);
      sizeOrArrayOrIndex = (int)((ulonglong)allocPair >> 0x20);
      r4Value = (undefined4)allocPair;
      for (sizeOrLoopIndex = 0; resultOrOffset = (**(code **)(*(int *)this + 0x4c))(this,r4Value), sizeOrLoopIndex < resultOrOffset;
          sizeOrLoopIndex = sizeOrLoopIndex + 1) {
        (**(code **)(*(int *)this + 0x38))(&compareTypeVtbl,this);
        compareTypeVtbl = (undefined **)(picBase - 0x473c);
        if ((compareTypeBits >> 0x13 & 0x3f) != 3) {
          message = "Constant folding cannot be done for \"||\"";
          typeBitsOrLoc = (*(code *)**(undefined4 **)this)(this,r4In12,newNodeOrRightArg,infoSinkArg,sizeOrIndex,unusedArg6,picBase);
                    
          goto override_jmp_97b93868_case_0;
        }
        r4Value = 0;
        if ((*(int *)(thisUnion + sizeOrLoopIndex * 4) != 0) || (resultOrRightFloats[sizeOrLoopIndex] != 0.0)) {
          r4Value = 1;
        }
        *(undefined4 *)(sizeOrLoopIndex * 4 + sizeOrArrayOrIndex) = r4Value;
        r4Value = r4In12;
      }
      break;
    case 0x18:
      picBase = 0xa7b81734;
      sizeOrArrayOrIndex = (**(code **)(*(int *)this + 0x4c))(this);
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      allocPair = TPoolAllocator__allocate(poolAllocator,sizeOrArrayOrIndex << 2);
      sizeOrArrayOrIndex = (int)((ulonglong)allocPair >> 0x20);
      r4Value = (undefined4)allocPair;
      for (resultOrOffset = 0;
          sizeOrLoopIndex = (**(code **)(*(int *)this + 0x4c))(this,r4Value,newNodeOrRightArg,infoSinkArg,sizeOrIndex,unusedArg6,sizeOrLoopIndex),
          resultOrOffset < sizeOrLoopIndex; resultOrOffset = resultOrOffset + 1) {
        (**(code **)(*(int *)this + 0x38))(&compareTypeVtbl,this);
        compareTypeVtbl = (undefined **)(picBase - 0x473c);
        if ((compareTypeBits >> 0x13 & 0x3f) != 3) {
          message = "Constant folding cannot be done for \"^^\"";
          typeBitsOrLoc = (*(code *)**(undefined4 **)this)(this,r4In11,newNodeOrRightArg,infoSinkArg,sizeOrIndex,unusedArg6,picBase);
                    
          goto override_jmp_97b93868_case_0;
        }
        sizeOrLoopIndex = resultOrOffset * 4;
        *(uint *)(sizeOrLoopIndex + sizeOrArrayOrIndex) = (uint)(*(float *)(thisUnion + sizeOrLoopIndex) != resultOrRightFloats[resultOrOffset]);
        r4Value = r4In11;
      }
      break;
    case 0x19:
      picBase = 0xa7b81734;
      sizeOrArrayOrIndex = (**(code **)(*(int *)this + 0x4c))(this);
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      sizeOrArrayOrIndex = TPoolAllocator__allocate(poolAllocator,sizeOrArrayOrIndex << 2);
      for (sizeOrLoopIndex = 0; resultOrOffset = (**(code **)(*(int *)this + 0x4c))(this), sizeOrLoopIndex < resultOrOffset;
          sizeOrLoopIndex = sizeOrLoopIndex + 1) {
        (**(code **)(*(int *)this + 0x38))(&compareTypeVtbl,this);
        compareTypeVtbl = (undefined **)(picBase - 0x473c);
        if ((compareTypeBits >> 0x13 & 0x3f) != 3) {
          message = "Constant folding cannot be done for \"&&\"";
          typeBitsOrLoc = (*(code *)**(undefined4 **)this)(this,r4In10,newNodeOrRightArg,infoSinkArg,sizeOrIndex,unusedArg6,picBase);
                    
          goto override_jmp_97b93868_case_0;
        }
        r4Value = 0;
        if ((*(int *)(thisUnion + sizeOrLoopIndex * 4) != 0) && (resultOrRightFloats[sizeOrLoopIndex] != 0.0)) {
          r4Value = 1;
        }
        *(undefined4 *)(sizeOrLoopIndex * 4 + sizeOrArrayOrIndex) = r4Value;
      }
      break;
    case 0x43:
      flagOrCompare = false;
      (**(code **)(*(int *)this + 0x38))(&compareTypeVtbl,this);
      r4Value = r4Out2;
      if (((compareTypeBits >> 0x13 & 0x3f) != 1) ||
         (sizeOrIndex = (**(code **)(*rightConstUnion + 0x40))(rightConstUnion), r4Value = r4Out3, sizeOrIndex != 1)) {
        flagOrCompare = true;
      }
      picBase = 0xa7b81734;
      compareTypeVtbl = &PTR___ZN5TTypeD1Ev_a7b7cff8;
      if (!flagOrCompare) {
        sizeOrIndex = (**(code **)(*(int *)this + 0x48))(this,r4Value);
        poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
        sizeOrArrayOrIndex = TPoolAllocator__allocate(poolAllocator,sizeOrIndex * sizeOrIndex * 4);
        sizeOrLoopIndex = 0;
        if (0 < sizeOrIndex) {
          do {
            if (0 < sizeOrIndex) {
              columnOffset = 0;
              resultOrOffset = sizeOrLoopIndex * 4;
              countOrResult = sizeOrIndex;
              do {
                *(undefined4 *)(resultOrOffset + sizeOrArrayOrIndex) = 0;
                if (0 < sizeOrIndex) {
                  resultCursor = resultOrRightFloats + columnOffset;
                  thisOrRightCursor = thisUnion + sizeOrLoopIndex * 4;
                  columnsLeft = sizeOrIndex;
                  do {
                    rightOrResultValue = *(float *)thisOrRightCursor;
                    thisOrRightCursor = thisOrRightCursor + sizeOrIndex * 4;
                    leftValue = *resultCursor;
                    resultCursor = resultCursor + 1;
                    *(float *)(sizeOrArrayOrIndex + resultOrOffset) = rightOrResultValue * leftValue + *(float *)(sizeOrArrayOrIndex + resultOrOffset);
                    columnsLeft = columnsLeft + -1;
                  } while (columnsLeft != 0);
                }
                countOrResult = countOrResult + -1;
                columnOffset = columnOffset + sizeOrIndex;
                resultOrOffset = resultOrOffset + sizeOrIndex * 4;
              } while (countOrResult != 0);
            }
            sizeOrLoopIndex = sizeOrLoopIndex + 1;
          } while (sizeOrLoopIndex < sizeOrIndex);
        }
        break;
      }
      message = "Constant Folding cannot be done for matrix multiply";
      typeBitsOrLoc = (*(code *)**(undefined4 **)this)(this);
                    
      __ZN13TInfoSinkBase6appendEPKc(infoSink,"INTERNAL ERROR: ");
      bitsOrLine = typeBitsOrLoc & 0xffff;
      reservationOk = (bitsOrLine == 0) << 1;
      if (bitsOrLine == 0) {
        _sprintf(locTextBuf2,"%d:? ",(int)typeBitsOrLoc >> 0x10);
      }
      else {
        _sprintf(locTextBuf2,"%d:%d",(int)typeBitsOrLoc >> 0x10,bitsOrLine);
      }
      locText = locTextBuf;
      __ZNSsC1EPKcRKSaIcE(rightTypeOrString,locTextBuf2,locText);
      *(undefined *)((int)rightTypeOrString[0] + (int)rightTypeOrString[0][-3]) = *PTR__S_terminal_a7b7c0b8;
      __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)rightTypeOrString[0]);
      refCountPtr = rightTypeOrString[0];
code_r0x97b932f0:
      refCountPtrCopy = refCountPtr + -1;
      stringRep = (unsigned char *)(refCountPtr + -3);
      do {
        refCountOrVtable = *refCountPtrCopy;
        if (reservation != '\0') {
          newRefCount = (undefined *)storeWordConditionalIndexed(refCountOrVtable + -1,0,refCountPtrCopy);
          *refCountPtrCopy = newRefCount;
          reservationOk = 2;
        }
      } while (!(bool)(reservationOk >> 1 & 1));
      flagOrCompare = 0 < (int)refCountOrVtable;
code_r0x97b93fb8:
      if (!flagOrCompare) goto code_r0x97b95524;
      goto code_r0x97b95528;
    }
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    newNodeOrRightArg = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x34);
    (**(code **)(*(int *)this + 0x38))(&compareTypeVtbl,this);
    *(int *)(newNodeOrRightArg + 4) = 0;
    *(undefined ***)newNodeOrRightArg = &PTR_getLine_a7b7cf90;
    refCountOrVtable = (undefined *)(picBase - 0x4744);
LAB_97b946a4:
    compareTypeVtbl = (undefined **)(refCountOrVtable + 8);
    *(int *)(newNodeOrRightArg + 0xc) = compareTypeWord1;
    *(int *)(newNodeOrRightArg + 0x10) = compareTypeWord2;
    *(int *)(newNodeOrRightArg + 0x14) = compareTypeWord3;
    *(int *)(newNodeOrRightArg + 0x18) = compareTypeWord4OrLocText;
    *(int *)(newNodeOrRightArg + 0x1c) = compareTypeWord5;
    *(int *)(newNodeOrRightArg + 0x20) = compareTypeWord6;
    *(undefined ***)(newNodeOrRightArg + 8) = compareTypeVtbl;
    *(int *)(newNodeOrRightArg + 0x24) = compareTypeWord7;
    *(int *)(newNodeOrRightArg + 0x28) = compareTypeWord8;
    nodeBitsBefore = *(uint *)(newNodeOrRightArg + 0x2c);
    bitsOrLine = compareTypeBits & 0xfe000000;
    *(uint *)(newNodeOrRightArg + 0x2c) = bitsOrLine | nodeBitsBefore & 0x1ffffff;
    typeFieldOrInt = (compareTypeBits >> 0x13 & 0x3f) << 0x13;
    *(uint *)(newNodeOrRightArg + 0x2c) = typeFieldOrInt | bitsOrLine | nodeBitsBefore & 0x7ffff;
    typeBitsOrLoc = compareTypeBits & 0x7f800;
    *(uint *)(newNodeOrRightArg + 0x2c) = typeBitsOrLoc | typeFieldOrInt | bitsOrLine | nodeBitsBefore & 0x7ff;
    typeBit10 = (compareTypeBits >> 10 & 1) << 10;
    *(uint *)(newNodeOrRightArg + 0x2c) = typeBit10 | typeBitsOrLoc | typeFieldOrInt | bitsOrLine | nodeBitsBefore & 0x3ff;
    refCountOrVtable = PTR_vtable_a7b7c0c8;
    *(uint *)(newNodeOrRightArg + 0x2c) =
         (compareTypeBits >> 9 & 1) << 9 | typeBit10 | typeBitsOrLoc | typeFieldOrInt | bitsOrLine | nodeBitsBefore & 0x1ff;
    *(int *)(newNodeOrRightArg + 0x30) = sizeOrArrayOrIndex;
    *(undefined **)newNodeOrRightArg = refCountOrVtable + 8;
LAB_97b94758:
    sizeOrIndex = *(int *)newNodeOrRightArg;
    r4Value = (*(code *)**(undefined4 **)this)(this);
    (**(code **)(sizeOrIndex + 4))(newNodeOrRightArg,r4Value);
    return newNodeOrRightArg;
  }
LAB_97b9478c:
  flagOrCompare = false;
  sizeOrArrayOrIndex = (**(code **)(*(int *)this + 0x4c))(this);
  if (sizeOrArrayOrIndex != 1) {
    return this;
  }
  (**(code **)(*(int *)this + 0x38))(&compareTypeVtbl,this);
  if (((compareTypeBits >> 0x13 & 0x3f) != 0xe) &&
     (sizeOrArrayOrIndex = (**(code **)(*(int *)rightOperand + 0x4c))(rightOperand), sizeOrArrayOrIndex == 1)) {
    (**(code **)(*(int *)rightOperand + 0x38))(rightTypeOrString,rightOperand);
    flagOrCompare = (rightTypeBits >> 0x13 & 0x3f) != 0xe;
    rightTypeOrString[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  }
  compareTypeVtbl = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  if (!flagOrCompare) {
    return this;
  }
  poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
  resultOrRightFloats = (float *)TPoolAllocator__allocate(poolAllocator,4);
  picBase = 0xa7b81734;
  (**(code **)(*(int *)this + 0x38))(&tailTypeVtbl,this);
  tailTypeVtbl = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  typeBitsOrLoc = tailTypeBits >> 0x13 & 0x3f;
  if (typeBitsOrLoc != 2) {
    if (2 < typeBitsOrLoc) {
      if (typeBitsOrLoc != 3) goto LAB_97b95400;
      sizeOrIndex = (**(code **)(*(int *)rightOperand + 0x18))(rightOperand);
      bitsOrLine = **(uint **)(sizeOrIndex + 0x30);
      typeBitsOrLoc = **(uint **)(this + 0x30);
      if (op == 0x2b) {
        flagOrCompare = typeBitsOrLoc == bitsOrLine;
LAB_97b9529c:
        *resultOrRightFloats = GH_U2F((unsigned int)((1 - (uint)flagOrCompare)));
        poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
        newNodeOrRightArg = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x34);
        tailTypeBits = tailTypeBits & 0x1801ff | 0x4180800;
        tailTypeVtbl = (undefined **)(picBase - 0x473c);
        tailTypeWord1 = 0;
        tailTypeWord3 = 0;
        tailTypeWord4OrLocText = 0;
        tailTypeWord5 = 0;
        tailTypeWord6 = 0;
        tailTypeWord7 = 0;
        tailTypeWord8 = 0;
        tailTypeWord2 = 0;
        *(int *)(newNodeOrRightArg + 4) = 0;
        *(undefined ***)newNodeOrRightArg = &PTR_getLine_a7b7cf90;
        *(int *)(newNodeOrRightArg + 0xc) = 0;
        *(int *)(newNodeOrRightArg + 0x10) = 0;
        *(int *)(newNodeOrRightArg + 0x14) = 0;
        *(int *)(newNodeOrRightArg + 0x18) = 0;
        *(int *)(newNodeOrRightArg + 0x1c) = 0;
        *(int *)(newNodeOrRightArg + 0x20) = 0;
        *(undefined ***)(newNodeOrRightArg + 8) = tailTypeVtbl;
        *(int *)(newNodeOrRightArg + 0x24) = 0;
        *(int *)(newNodeOrRightArg + 0x28) = 0;
        bitsOrLine = *(uint *)(newNodeOrRightArg + 0x2c);
        *(uint *)(newNodeOrRightArg + 0x2c) = bitsOrLine & 0x1ffffff | 0x4000000;
        typeBitsOrLoc = (tailTypeBits >> 0x13 & 0x3f) << 0x13;
        *(uint *)(newNodeOrRightArg + 0x2c) = typeBitsOrLoc | bitsOrLine & 0x7ffff | 0x4000000;
        *(uint *)(newNodeOrRightArg + 0x2c) = typeBitsOrLoc | bitsOrLine & 0x7ff | 0x4000000 | 0x800;
        *(uint *)(newNodeOrRightArg + 0x2c) = typeBitsOrLoc | bitsOrLine & 0x3ff | 0x4000000 | 0x800;
        refCountOrVtable = PTR_vtable_a7b7c0c8;
        *(uint *)(newNodeOrRightArg + 0x2c) = typeBitsOrLoc | bitsOrLine & 0x1ff | 0x4000000 | 0x800;
        *(float **)(newNodeOrRightArg + 0x30) = resultOrRightFloats;
        *(undefined **)newNodeOrRightArg = refCountOrVtable + 8;
        nodeOrVtable = *(undefined4 **)rightOperand;
        goto LAB_97b953d4;
      }
      if (op < 0x2c) {
        if (op == 0x2a) {
          typeBitsOrLoc = typeBitsOrLoc | bitsOrLine;
LAB_97b95254:
          flagOrCompare = typeBitsOrLoc == 0;
          goto LAB_97b9529c;
        }
      }
      else {
        typeBitsOrLoc = typeBitsOrLoc & bitsOrLine;
        if (op == 0x2c) goto LAB_97b95254;
      }
      message = "Binary operator cannot be folded into constant bool";
      typeBitsOrLoc = *(uint *)(this + 4);
                    
override_jmp_97b95280_case_0:
      __ZN13TInfoSinkBase6appendEPKc(infoSink,"INTERNAL ERROR: ");
      bitsOrLine = typeBitsOrLoc & 0xffff;
      reservationOk = (bitsOrLine == 0) << 1;
      if (bitsOrLine == 0) {
        _sprintf((char *)&tailTypeWord4OrLocText,"%d:? ",(int)typeBitsOrLoc >> 0x10);
      }
      else {
        _sprintf((char *)&tailTypeWord4OrLocText,"%d:%d",(int)typeBitsOrLoc >> 0x10,bitsOrLine);
      }
      locText = (unsigned char *)&tailTypeWord4OrLocText;
      __ZNSsC1EPKcRKSaIcE(&tailTypeVtbl,(char *)locText,stringAllocator3);
                    
      *(undefined *)((int)tailTypeVtbl + (int)tailTypeVtbl[-3]) = *PTR__S_terminal_a7b7c0b8;
      __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)tailTypeVtbl);
      refCountPtr = tailTypeVtbl + -1;
      stringRep = (unsigned char *)(tailTypeVtbl + -3);
      do {
        refCountOrVtable = *refCountPtr;
                    
        if (reservation != '\0') {
          newRefCount = (undefined *)storeWordConditionalIndexed(refCountOrVtable + -1,0,refCountPtr);
          *refCountPtr = newRefCount;
          reservationOk = 2;
        }
      } while (!(bool)(reservationOk >> 1 & 1));
      if ((int)refCountOrVtable < 1) {
code_r0x97b95524:
        __ZNSs4_Rep10_M_destroyERKSaIcE(stringRep,locText);
      }
code_r0x97b95528:
      __ZN13TInfoSinkBase6appendEPKc(infoSink,": ");
      goto code_r0x97b95ba0;
    }
    if (typeBitsOrLoc != 1) {
LAB_97b95400:
      message = "Cannot fold constant";
      typeBitsOrLoc = (*(code *)**(undefined4 **)this)(this);
                    
      goto override_jmp_97b95280_case_0;
    }
    sizeOrArrayOrIndex = (**(code **)(*(int *)rightOperand + 0x18))(rightOperand);
    typeBitsOrLoc = op - 0x13;
    rightOrResultValue = **(float **)(sizeOrArrayOrIndex + 0x30);
    leftValue = **(float **)(this + 0x30);
    if (0x11 < typeBitsOrLoc) {
      return (unsigned char *)0x0;
    }
    switch(typeBitsOrLoc) {
    case 0:
      leftValue = leftValue + rightOrResultValue;
      goto LAB_97b94ef8;
    case 1:
      leftValue = leftValue - rightOrResultValue;
      goto LAB_97b94ef8;
    case 2:
      leftValue = leftValue * rightOrResultValue;
      goto LAB_97b94ef8;
    case 3:
      if (rightOrResultValue == 0.0) {
        typeBitsOrLoc = (*(code *)**(undefined4 **)this)(this,typeBitsOrLoc,newNodeOrRightArg,infoSinkArg,sizeOrIndex,unusedArg6,typeBitsOrLoc * 4);
                    
        __ZN13TInfoSinkBase6appendEPKc(infoSink,"WARNING: ");
        bitsOrLine = typeBitsOrLoc & 0xffff;
        reservationOk = (bitsOrLine == 0) << 1;
        if (bitsOrLine == 0) {
          _sprintf((char *)&tailTypeWord4OrLocText,"%d:? ",(int)typeBitsOrLoc >> 0x10);
        }
        else {
          _sprintf((char *)&tailTypeWord4OrLocText,"%d:%d",(int)typeBitsOrLoc >> 0x10,bitsOrLine);
        }
        __ZNSsC1EPKcRKSaIcE(&tailTypeVtbl,(char *)&tailTypeWord4OrLocText,stringAllocator3);
        *(undefined *)((int)tailTypeVtbl + (int)tailTypeVtbl[-3]) = *PTR__S_terminal_a7b7c0b8;
        __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)tailTypeVtbl);
        refCountPtr = tailTypeVtbl + -1;
        do {
          refCountOrVtable = *refCountPtr;
          if (reservation != '\0') {
            newRefCount = (undefined *)storeWordConditionalIndexed(refCountOrVtable + -1,0,refCountPtr);
            *refCountPtr = newRefCount;
            reservationOk = 2;
          }
        } while (!(bool)(reservationOk >> 1 & 1));
        if ((int)refCountOrVtable < 1) {
          __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(tailTypeVtbl + -3),&tailTypeWord4OrLocText);
        }
        __ZN13TInfoSinkBase6appendEPKc(infoSink,": ");
        __ZN13TInfoSinkBase6appendEPKc(infoSink,"Divide by zero error during constant folding");
        __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
        leftValue = 3.4028235e+38;
      }
      else {
        leftValue = leftValue / rightOrResultValue;
      }
LAB_97b94ef8:
      *resultOrRightFloats = leftValue;
      goto code_r0x97b95098;
    default:
      goto switchD_97b94d20_caseD_17;
    case 10:
      rightOrResultValue = GH_U2F((unsigned int)((uint)(leftValue == rightOrResultValue)));
      break;
    case 0xb:
      rightOrResultValue = GH_U2F((unsigned int)((uint)(leftValue != rightOrResultValue)));
      break;
    case 0xe:
      rightOrResultValue = GH_U2F((unsigned int)((uint)(leftValue < rightOrResultValue)));
      break;
    case 0xf:
      rightOrResultValue = GH_U2F((unsigned int)((uint)(rightOrResultValue < leftValue)));
      break;
    case 0x10:
      flagOrCompare = leftValue <= rightOrResultValue;
      goto LAB_97b94f58;
    case 0x11:
      flagOrCompare = rightOrResultValue <= leftValue;
LAB_97b94f58:
      rightOrResultValue = GH_U2F((unsigned int)((uint)flagOrCompare));
    }
    *resultOrRightFloats = rightOrResultValue;
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    newNodeOrRightArg = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x34);
    tailTypeBits = tailTypeBits & 0x1801ff | 0x4180800;
    tailTypeVtbl = (undefined **)(picBase - 0x473c);
    tailTypeWord1 = 0;
    tailTypeWord3 = 0;
    tailTypeWord4OrLocText = 0;
    tailTypeWord5 = 0;
    tailTypeWord6 = 0;
    tailTypeWord7 = 0;
    tailTypeWord8 = 0;
    tailTypeWord2 = 0;
    *(int *)(newNodeOrRightArg + 4) = 0;
    *(undefined ***)newNodeOrRightArg = &PTR_getLine_a7b7cf90;
    *(int *)(newNodeOrRightArg + 0xc) = 0;
    *(int *)(newNodeOrRightArg + 0x10) = 0;
    *(int *)(newNodeOrRightArg + 0x14) = 0;
    *(int *)(newNodeOrRightArg + 0x18) = 0;
    *(int *)(newNodeOrRightArg + 0x1c) = 0;
    *(int *)(newNodeOrRightArg + 0x20) = 0;
    *(int *)(newNodeOrRightArg + 0x24) = 0;
    *(undefined ***)(newNodeOrRightArg + 8) = tailTypeVtbl;
    *(int *)(newNodeOrRightArg + 0x28) = 0;
    bitsOrLine = *(uint *)(newNodeOrRightArg + 0x2c);
    *(uint *)(newNodeOrRightArg + 0x2c) = bitsOrLine & 0x1ffffff | 0x4000000;
    typeBitsOrLoc = (tailTypeBits >> 0x13 & 0x3f) << 0x13;
    *(uint *)(newNodeOrRightArg + 0x2c) = typeBitsOrLoc | bitsOrLine & 0x7ffff | 0x4000000;
    *(uint *)(newNodeOrRightArg + 0x2c) = typeBitsOrLoc | bitsOrLine & 0x7ff | 0x4000000 | 0x800;
    *(uint *)(newNodeOrRightArg + 0x2c) = typeBitsOrLoc | bitsOrLine & 0x3ff | 0x4000000 | 0x800;
    refCountOrVtable = PTR_vtable_a7b7c0c8;
    *(uint *)(newNodeOrRightArg + 0x2c) = typeBitsOrLoc | bitsOrLine & 0x1ff | 0x4000000 | 0x800;
    *(float **)(newNodeOrRightArg + 0x30) = resultOrRightFloats;
    *(undefined **)newNodeOrRightArg = refCountOrVtable + 8;
    if (newNodeOrRightArg != (unsigned char *)0x0) goto LAB_97b951c0;
code_r0x97b95098:
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    newNodeOrRightArg = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x34);
    typeBitsOrLoc = tailTypeBits & 0x7ff | 0x4080000;
    goto code_r0x97b950c8;
  }
  sizeOrArrayOrIndex = (**(code **)(*(int *)rightOperand + 0x18))(rightOperand);
  typeBitsOrLoc = op - 0x13;
  typeFieldOrInt = **(uint **)(sizeOrArrayOrIndex + 0x30);
  bitsOrLine = **(uint **)(this + 0x30);
  if (0x11 < typeBitsOrLoc) {
    return (unsigned char *)0x0;
  }
  switch(typeBitsOrLoc) {
  case 0:
    rightOrResultValue = GH_U2F((unsigned int)((bitsOrLine + typeFieldOrInt)));
    break;
  case 1:
    rightOrResultValue = GH_U2F((unsigned int)((bitsOrLine - typeFieldOrInt)));
    break;
  case 2:
    rightOrResultValue = GH_U2F((unsigned int)((bitsOrLine * typeFieldOrInt)));
    break;
  case 3:
    if (typeFieldOrInt == 0) {
      typeBitsOrLoc = (*(code *)**(undefined4 **)this)
                         (this,typeBitsOrLoc,newNodeOrRightArg,infoSinkArg,sizeOrIndex,unusedArg6,typeBitsOrLoc * 4,bitsOrLine);
                    
      __ZN13TInfoSinkBase6appendEPKc(infoSink,"WARNING: ");
      bitsOrLine = typeBitsOrLoc & 0xffff;
      reservationOk = (bitsOrLine == 0) << 1;
      if (bitsOrLine == 0) {
        _sprintf(locTextBuf3,"%d:? ",(int)typeBitsOrLoc >> 0x10);
      }
      else {
        _sprintf(locTextBuf3,"%d:%d",(int)typeBitsOrLoc >> 0x10,bitsOrLine);
      }
      __ZNSsC1EPKcRKSaIcE(&tailTypeVtbl,locTextBuf3,(unsigned char *)&tailTypeWord4OrLocText);
      *(undefined *)((int)tailTypeVtbl + (int)tailTypeVtbl[-3]) = *PTR__S_terminal_a7b7c0b8;
      __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)tailTypeVtbl);
      refCountPtr = tailTypeVtbl + -1;
      do {
        refCountOrVtable = *refCountPtr;
        if (reservation != '\0') {
          newRefCount = (undefined *)storeWordConditionalIndexed(refCountOrVtable + -1,0,refCountPtr);
          *refCountPtr = newRefCount;
          reservationOk = 2;
        }
      } while (!(bool)(reservationOk >> 1 & 1));
      if ((int)refCountOrVtable < 1) {
        __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(tailTypeVtbl + -3),(unsigned char *)&tailTypeWord4OrLocText);
      }
      __ZN13TInfoSinkBase6appendEPKc(infoSink,": ");
      __ZN13TInfoSinkBase6appendEPKc(infoSink,"Divide by zero error during constant folding");
      __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
      rightOrResultValue = GH_U2F(0x7fffffffU);
    }
    else {
      rightOrResultValue = GH_U2F((unsigned int)(((int)bitsOrLine / (int)typeFieldOrInt)));
    }
    break;
  case 4:
    rightOrResultValue = GH_U2F((unsigned int)((bitsOrLine - ((int)bitsOrLine / (int)typeFieldOrInt) * typeFieldOrInt)));
    break;
  case 5:
    rightOrResultValue = GH_U2F((unsigned int)(((int)bitsOrLine >> (typeFieldOrInt & 0x3f))));
    break;
  case 6:
    rightOrResultValue = GH_U2F((unsigned int)((bitsOrLine << (typeFieldOrInt & 0x3f))));
    break;
  case 7:
    rightOrResultValue = GH_U2F((unsigned int)((bitsOrLine & typeFieldOrInt)));
    break;
  case 8:
    rightOrResultValue = GH_U2F((unsigned int)((bitsOrLine | typeFieldOrInt)));
    break;
  case 9:
    rightOrResultValue = GH_U2F((unsigned int)((bitsOrLine ^ typeFieldOrInt)));
    break;
  case 10:
    rightOrResultValue = GH_U2F((unsigned int)((uint)(bitsOrLine == typeFieldOrInt)));
    goto LAB_97b94b6c;
  case 0xb:
    *resultOrRightFloats = GH_U2F((unsigned int)((uint)(bitsOrLine != typeFieldOrInt)));
    goto LAB_97b94b70;
  default:
    goto switchD_97b94d20_caseD_17;
  case 0xe:
    rightOrResultValue = 1.4013e-45;
    if ((int)typeFieldOrInt <= (int)bitsOrLine) {
LAB_97b94b68:
      rightOrResultValue = 0.0;
    }
    goto LAB_97b94b6c;
  case 0xf:
    rightOrResultValue = 1.4013e-45;
    if ((int)bitsOrLine <= (int)typeFieldOrInt) goto LAB_97b94b68;
    goto LAB_97b94b6c;
  case 0x10:
    rightOrResultValue = 1.4013e-45;
    if ((int)typeFieldOrInt < (int)bitsOrLine) goto LAB_97b94b68;
    goto LAB_97b94b6c;
  case 0x11:
    rightOrResultValue = 1.4013e-45;
    if ((int)bitsOrLine < (int)typeFieldOrInt) goto LAB_97b94b68;
LAB_97b94b6c:
    *resultOrRightFloats = rightOrResultValue;
LAB_97b94b70:
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    newNodeOrRightArg = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x34);
    tailTypeBits = tailTypeBits & 0x1801ff | 0x4180800;
    tailTypeVtbl = (undefined **)(picBase - 0x473c);
    tailTypeWord1 = 0;
    tailTypeWord3 = 0;
    tailTypeWord4OrLocText = 0;
    tailTypeWord5 = 0;
    tailTypeWord6 = 0;
    tailTypeWord7 = 0;
    tailTypeWord8 = 0;
    tailTypeWord2 = 0;
    *(int *)(newNodeOrRightArg + 4) = 0;
    *(undefined ***)newNodeOrRightArg = &PTR_getLine_a7b7cf90;
    *(int *)(newNodeOrRightArg + 0xc) = 0;
    *(int *)(newNodeOrRightArg + 0x10) = 0;
    *(int *)(newNodeOrRightArg + 0x14) = 0;
    *(int *)(newNodeOrRightArg + 0x18) = 0;
    *(int *)(newNodeOrRightArg + 0x1c) = 0;
    *(int *)(newNodeOrRightArg + 0x20) = 0;
    *(int *)(newNodeOrRightArg + 0x24) = 0;
    *(undefined ***)(newNodeOrRightArg + 8) = tailTypeVtbl;
    *(int *)(newNodeOrRightArg + 0x28) = 0;
    bitsOrLine = *(uint *)(newNodeOrRightArg + 0x2c);
    *(uint *)(newNodeOrRightArg + 0x2c) = bitsOrLine & 0x1ffffff | 0x4000000;
    typeBitsOrLoc = (tailTypeBits >> 0x13 & 0x3f) << 0x13;
    *(uint *)(newNodeOrRightArg + 0x2c) = typeBitsOrLoc | bitsOrLine & 0x7ffff | 0x4000000;
    *(uint *)(newNodeOrRightArg + 0x2c) = typeBitsOrLoc | bitsOrLine & 0x7ff | 0x4000000 | 0x800;
    *(uint *)(newNodeOrRightArg + 0x2c) = typeBitsOrLoc | bitsOrLine & 0x3ff | 0x4000000 | 0x800;
    refCountOrVtable = PTR_vtable_a7b7c0c8;
    *(uint *)(newNodeOrRightArg + 0x2c) = typeBitsOrLoc | bitsOrLine & 0x1ff | 0x4000000 | 0x800;
    *(float **)(newNodeOrRightArg + 0x30) = resultOrRightFloats;
    *(undefined **)newNodeOrRightArg = refCountOrVtable + 8;
    if (newNodeOrRightArg != (unsigned char *)0x0) goto LAB_97b951c0;
    goto code_r0x97b94ca4;
  }
  *resultOrRightFloats = rightOrResultValue;
code_r0x97b94ca4:
  poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
  newNodeOrRightArg = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x34);
  typeBitsOrLoc = tailTypeBits & 0xfff | 0x4100000;
code_r0x97b950c8:
  tailTypeVtbl = (undefined **)(picBase - 0x473c);
  tailTypeBits = typeBitsOrLoc & 0xfffff9ff | 0x800;
  *(int *)(newNodeOrRightArg + 4) = 0;
  *(undefined ***)newNodeOrRightArg = &PTR_getLine_a7b7cf90;
  *(int *)(newNodeOrRightArg + 0xc) = 0;
  *(int *)(newNodeOrRightArg + 0x10) = 0;
  *(int *)(newNodeOrRightArg + 0x14) = 0;
  *(int *)(newNodeOrRightArg + 0x18) = 0;
  *(int *)(newNodeOrRightArg + 0x1c) = 0;
  *(int *)(newNodeOrRightArg + 0x20) = 0;
  *(undefined ***)(newNodeOrRightArg + 8) = tailTypeVtbl;
  *(int *)(newNodeOrRightArg + 0x24) = 0;
  *(int *)(newNodeOrRightArg + 0x28) = 0;
  typeFieldOrInt = *(uint *)(newNodeOrRightArg + 0x2c);
  bitsOrLine = typeBitsOrLoc & 0xfe000000;
  *(uint *)(newNodeOrRightArg + 0x2c) = bitsOrLine | typeFieldOrInt & 0x1ffffff;
  typeBitsOrLoc = typeBitsOrLoc & 0x1f80000;
  *(uint *)(newNodeOrRightArg + 0x2c) = typeBitsOrLoc | bitsOrLine | typeFieldOrInt & 0x7ffff;
  *(uint *)(newNodeOrRightArg + 0x2c) = typeBitsOrLoc | bitsOrLine | typeFieldOrInt & 0x7ff | 0x800;
  *(uint *)(newNodeOrRightArg + 0x2c) = typeBitsOrLoc | bitsOrLine | typeFieldOrInt & 0x3ff | 0x800;
  refCountOrVtable = PTR_vtable_a7b7c0c8;
  *(uint *)(newNodeOrRightArg + 0x2c) = typeBitsOrLoc | bitsOrLine | typeFieldOrInt & 0x1ff | 0x800;
  *(float **)(newNodeOrRightArg + 0x30) = resultOrRightFloats;
  *(undefined **)newNodeOrRightArg = refCountOrVtable + 8;
LAB_97b951c0:
  tailTypeWord8 = 0;
  sizeOrIndex = *(int *)newNodeOrRightArg;
  tailTypeWord1 = tailTypeWord8;
  tailTypeWord2 = tailTypeWord8;
  tailTypeWord3 = tailTypeWord8;
  tailTypeWord4OrLocText = tailTypeWord8;
  tailTypeWord5 = tailTypeWord8;
  tailTypeWord6 = tailTypeWord8;
  tailTypeWord7 = tailTypeWord8;
  r4Value = (*(code *)**(undefined4 **)rightOperand)(rightOperand);
  (**(code **)(sizeOrIndex + 4))(newNodeOrRightArg,r4Value);
  return newNodeOrRightArg;
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
  unsigned char * this_00;
  int *a0;
  int lineCopy;
  undefined4 constNode;
  undefined4 a1;
  unsigned char * a2;
  undefined4 scratchR7;
  undefined4 scratchR8;
  int a6;
  unsigned char * constArray;
  undefined8 constArrayAlloc;
  undefined **typeTemp [9];
  uint typeTempBits;
  
  a2 = symbolTable;
  lineCopy = line;
  (**(code **)(*(int *)intermAggregate + 0x38))(typeTemp,intermAggregate,symbolTable,line);
  if ((typeTempBits & 0x400) == 0) {
    objectSize = (int)(typeTempBits << 0xd | typeTempBits >> 0x13) >> 0x18;
  }
  else {
    objectSize = (int)(typeTempBits << 0xd | typeTempBits >> 0x13) >> 0x18;
    objectSize = objectSize * objectSize;
  }
  this_00 = (unsigned char *)GetGlobalPoolAllocator();
  constArrayAlloc = TPoolAllocator__allocate(this_00,objectSize << 2);
  constArray = (unsigned char *)((ulonglong)constArrayAlloc >> 0x20);
  typeTemp[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  childSequence = (**(code **)(*(int *)intermAggregate + 100))
                    (intermAggregate,(int)constArrayAlloc,a2,lineCopy,scratchR7,scratchR8,*(int *)intermAggregate);
  if (*(int *)(childSequence + 8) - *(int *)(childSequence + 4) >> 2 == 1) {
    childSequence = (**(code **)(*(int *)intermAggregate + 100))(intermAggregate);
    a6 = *(int *)**(undefined4 **)(childSequence + 4);
    a0 = (int *)(**(code **)(a6 + 0x14))
                          ((int *)**(undefined4 **)(childSequence + 4),a1,a2,lineCopy,scratchR7,scratchR8,a6);
    childConstUnion = (**(code **)(*a0 + 0x18))(a0);
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
  unsigned char * this_00;
  int newConstArray;
  unsigned char * pTVar4;
  int componentIndex;
  int oldConstArray;
  undefined **typeTemp1 [9];
  uint typeTemp1Bits;
  undefined **typeTemp2 [2];
  unsigned char * typeTemp2Structure;
  uint typeTemp2Bits;
  undefined **typeTemp3 [14];
  
  oldConstArray = *(int *)(intermConstantUnion + 0x30);
  pTVar4 = (unsigned char *)0x0;
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
    this_00 = (unsigned char *)GetGlobalPoolAllocator();
    newConstArray = TPoolAllocator__allocate(this_00,objectSize << 2);
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
    pTVar4 = intermConstantUnion;
  }
  return pTVar4;
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
  unsigned char * this_00;
  unsigned char * newConstArray;
  uint srcBasicType;
  undefined4 constNode;
  undefined4 a1;
  undefined4 a1_00;
  undefined4 a1_01;
  int *a2;
  undefined4 scratchR6;
  uint a1_02;
  undefined4 scratchR7;
  undefined4 scratchR8;
  undefined *scratchR9;
  int srcConstArray;
  char *errorText;
  int componentIndex;
  void *this_01;
  char reservation;
  byte cr0Flags;
  double i2dBias;
  undefined **typeTempOrTextBuf [4];
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
  a2 = intermConstantUnion;
  (**(code **)(*intermConstantUnion + 0x38))(typeTempOrTextBuf,intermConstantUnion,intermConstantUnion);
  if ((typeTempBits & 0x400) == 0) {
    componentCount = (int)(typeTempBits << 0xd | typeTempBits >> 0x13) >> 0x18;
  }
  else {
    componentCount = (int)(typeTempBits << 0xd | typeTempBits >> 0x13) >> 0x18;
    componentCount = componentCount * componentCount;
  }
  typeTempOrTextBuf[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  this_00 = (unsigned char *)GetGlobalPoolAllocator();
  componentIndex = 0;
  newConstArray = (unsigned char *)TPoolAllocator__allocate(this_00,componentCount << 2);
  if (0 < componentCount) {
    do {
      if (basicType == 2) {
        (**(code **)(*intermConstantUnion + 0x38))(typeTempOrTextBuf,intermConstantUnion);
        srcBasicType = typeTempBits >> 0x13 & 0x3f;
        typeTempOrTextBuf[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
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
            this_01 = *(void **)this;
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
          this_01 = *(void **)this;
          errorText = "Incorrect data type found";
          sourceLoc = (**(code **)*intermConstantUnion)(intermConstantUnion);
                    
override_jmp_97b960f0_case_0:
          __ZN13TInfoSinkBase6appendEPKc(this_01,"INTERNAL ERROR: ");
          a1_02 = sourceLoc & 0xffff;
          cr0Flags = (a1_02 == 0) << 1;
          if (a1_02 == 0) {
            _sprintf((char *)&stackType,"%d:? ",(int)sourceLoc >> 0x10);
          }
          else {
            _sprintf((char *)&stackType,"%d:%d",(int)sourceLoc >> 0x10,a1_02);
          }
          __ZNSsC1EPKcRKSaIcE(typeTempOrTextBuf,(char *)&stackType,allocatorDummy);
          *(undefined *)((int)typeTempOrTextBuf[0] + (int)typeTempOrTextBuf[0][-3]) = *PTR__S_terminal_a7b7c0b8;
          __ZN13TInfoSinkBase6appendEPKc(this_01,(char *)typeTempOrTextBuf[0]);
          refCountPtr = typeTempOrTextBuf[0] + -1;
          do {
            oldRefCount = *refCountPtr;
            if (reservation != '\0') {
              atomicStore = (undefined *)storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
              *refCountPtr = atomicStore;
              cr0Flags = 2;
            }
          } while (!(bool)(cr0Flags >> 1 & 1));
          if ((int)oldRefCount < 1) {
            __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(typeTempOrTextBuf[0] + -3),allocatorDummy);
          }
          __ZN13TInfoSinkBase6appendEPKc(this_01,": ");
          __ZN13TInfoSinkBase6appendEPKc(this_01,errorText);
          __ZN13TInfoSinkBase6appendEPKc(this_01,"\n");
          return 0;
        }
        (**(code **)(*intermConstantUnion + 0x38))(typeTempOrTextBuf,intermConstantUnion);
        srcBasicType = typeTempBits >> 0x13 & 0x3f;
        typeTempOrTextBuf[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
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
          this_01 = *(void **)this;
          errorText = "Cannot promote";
          sourceLoc = (**(code **)*intermConstantUnion)(intermConstantUnion,a1,a2,scratchR6,scratchR7,scratchR8,scratchR9);
                    
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
        (**(code **)(*intermConstantUnion + 0x38))(typeTempOrTextBuf,intermConstantUnion);
        srcBasicType = typeTempBits >> 0x13 & 0x3f;
        typeTempOrTextBuf[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
        if (srcBasicType != 2) {
          if (srcBasicType < 3) {
            if (srcBasicType == 1) {
              scratchR9 = &DAT_97c35f58;
              srcValue = (uint)(*(float *)(componentIndex * 4 + srcConstArray) != 0.0);
              goto LAB_97b9625c;
            }
          }
          else if (srcBasicType == 3) goto LAB_97b96230;
          this_01 = *(void **)this;
          errorText = "Cannot promote";
          sourceLoc = (**(code **)*intermConstantUnion)(intermConstantUnion,a1_00,a2,scratchR6,scratchR7,scratchR8,scratchR9);
                    
          goto override_jmp_97b960f0_case_0;
        }
        scratchR9 = (undefined *)(uint)(*(int *)(srcConstArray + componentIndex * 4) != 0);
        *(undefined **)(newConstArray + componentIndex * 4) = scratchR9;
      }
LAB_97b9641c:
      typeTempOrTextBuf[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
      componentIndex = componentIndex + 1;
    } while (componentIndex < componentCount);
  }
  (**(code **)(*intermConstantUnion + 0x38))(typeTempOrTextBuf,intermConstantUnion);
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
  line = (**(code **)*intermConstantUnion)(intermConstantUnion,a1_01,a2,scratchR6,scratchR7,scratchR8,(undefined4 *)*intermConstantUnion);
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
  int *a0;
  int *a1;
  undefined4 a1_00;
  undefined4 a1_01;
  unsigned char * a3;
  int a4;
  unsigned char * a5;
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
    a5 = intermAggregate;
    aggregateSequence = (**(code **)(*(int *)intermAggregate + 100))
                      (intermAggregate,vector,type,indexPtr,__normal_iterator,intermAggregate,*(int *)intermAggregate);
    oldSequenceEnd = *(int *)(vector + 8);
    oldSequenceBegin = *(int *)(vector + 4);
    if (*(int *)(aggregateSequence + 8) - *(int *)(aggregateSequence + 4) >> 2 == 1) {
      a4 = *indexPtr;
      a3 = intermAggregate;
      removeMatrixConstNodeResult = ((int (*)())TIntermediate__removeMatrixConstNode)(this,vector,type,intermAggregate,a4);
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
          a0 = (int *)((ulonglong)newNodeAlloc >> 0x20);
          childVtable = *(int *)**(undefined4 **)(aggregateSequence + 4);
          a1 = (int *)(**(code **)(childVtable + 0x18))
                                ((int *)**(undefined4 **)(aggregateSequence + 4),(int)newNodeAlloc,type,a3,a4,a5,
                                 childVtable);
          (**(code **)(*a1 + 0x38))(&stackType,a1);
          *a0 = (int)&PTR_getLine_a7b7cf90;
          a0[1] = 0;
          a0[3] = stackTypeArraySize;
          a0[4] = stackTypeStructure;
          a0[5] = stackTypeFieldName;
          a0[6] = stackTypeTypeName;
          a0[7] = stackTypeWord14;
          a0[8] = stackTypeStructureSize;
          a0[2] = (int)&PTR___ZN5TTypeD1Ev_a7b7cff8;
          a0[9] = stackTypeWord1c;
          a0[10] = stackTypeWord20;
          oldTypeBits = a0[0xb];
          typeQualifierBits = stackTypeBits & 0xfe000000;
          a0[0xb] = typeQualifierBits | oldTypeBits & 0x1ffffff;
          typeBasicTypeBits = (stackTypeBits >> 0x13 & 0x3f) << 0x13;
          a0[0xb] = typeBasicTypeBits | typeQualifierBits | oldTypeBits & 0x7ffff;
          typeSizeBits = stackTypeBits & 0x7f800;
          a0[0xb] = typeSizeBits | typeBasicTypeBits | typeQualifierBits | oldTypeBits & 0x7ff;
          typeMatrixBit = (stackTypeBits >> 10 & 1) << 10;
          a0[0xb] = typeMatrixBit | typeSizeBits | typeBasicTypeBits | typeQualifierBits | oldTypeBits & 0x3ff;
          a0[0xb] = (stackTypeBits >> 9 & 1) << 9 | typeMatrixBit | typeSizeBits | typeBasicTypeBits | typeQualifierBits | oldTypeBits & 0x1ff;
          a0[0xc] = (int)constValueSlot;
          *a0 = (int)constantUnionVtable;
          stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
          nodeVtable = *a0;
          a1_00 = (*(code *)**(undefined4 **)intermAggregate)(intermAggregate,a1_01,type,a3,a4,a5,a0 + 2);
          (**(code **)(nodeVtable + 4))(a0,a1_00);
          type = (unsigned char *)(*(int *)(vector + 4) + *indexPtr * 4);
          a3 = (unsigned char *)insertNodeSlot;
          *(unsigned char **)__normal_iterator = type;
          insertNodeSlot[0] = a0;
          std__vector_TIntermNode__pool_allocator_TIntermNode_____insert
                    (&insertResult,vector,type,a3);
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
  int *a0;
  unsigned char * this_00;
  int firstChildVtable;
  int elementSequence;
  undefined4 a1;
  unsigned char * a2;
  unsigned char * a3;
  undefined4 scratchR7;
  undefined4 scratchR8;
  undefined1 eraseResultSlot [20];
  
  a2 = type;
  a3 = intermAggregate;
  typeObjectSize = (**(code **)(*(int *)type + 0x30))(type,intermTyped,type,intermAggregate);
  if (typeObjectSize == 1) {
    aggregateSequence = (**(code **)(*(int *)intermAggregate + 100))(intermAggregate);
    firstChildVtable = *(int *)**(undefined4 **)(aggregateSequence + 4);
    intermTyped = (unsigned char *)
              (**(code **)(firstChildVtable + 0x14))
                        ((int *)**(undefined4 **)(aggregateSequence + 4),a1,a2,a3,scratchR7,scratchR8,firstChildVtable);
  }
  else {
    typeObjectSize = (**(code **)(*(int *)type + 0x30))(type);
    a0 = (int *)(**(code **)(*(int *)intermTyped + 0x1c))(intermTyped);
    this_00 = (unsigned char *)(**(code **)(*a0 + 100))(a0);
    checkSequence = (**(code **)(*(int *)intermAggregate + 100))(intermAggregate);
    if (*(int *)(checkSequence + 8) - *(int *)(checkSequence + 4) >> 2 == 1) {
      removeMatrixConstNodeResult = ((int (*)())TIntermediate__removeMatrixConstNode)(this,(unsigned char *)this_00,type,intermAggregate,1);
      if (removeMatrixConstNodeResult == 0) {
        aggregateSequence = (**(code **)(*(int *)intermAggregate + 100))(intermAggregate);
        sequenceFinish = *(undefined4 **)(this_00 + 8);
        if (sequenceFinish == *(undefined4 **)(this_00 + 0xc)) {
          std__vector_TIntermNode__pool_allocator_TIntermNode______M_insert_aux
                    (this_00,sequenceFinish,*(undefined4 **)(aggregateSequence + 4));
        }
        else {
          elementIndex = 0;
          if (sequenceFinish != (undefined4 *)0x0) {
            *sequenceFinish = **(undefined4 **)(aggregateSequence + 4);
            elementIndex = *(int *)(this_00 + 8);
          }
          *(int *)(this_00 + 8) = elementIndex + 4;
        }
      }
    }
    else {
      elementIndex = 0;
      if (0 < typeObjectSize) {
        do {
          elementSequence = (**(code **)(*(int *)intermAggregate + 100))(intermAggregate);
          sequenceFinish = *(undefined4 **)(this_00 + 8);
          if (sequenceFinish == *(undefined4 **)(this_00 + 0xc)) {
            std__vector_TIntermNode__pool_allocator_TIntermNode______M_insert_aux
                      (this_00,sequenceFinish,*(int *)(elementSequence + 4) + elementIndex * 4);
          }
          else {
            prevFinish = 0;
            if (sequenceFinish != (undefined4 *)0x0) {
              *sequenceFinish = *(undefined4 *)(*(int *)(elementSequence + 4) + elementIndex * 4);
              prevFinish = *(int *)(this_00 + 8);
            }
            *(int *)(this_00 + 8) = prevFinish + 4;
          }
          elementIndex = elementIndex + 1;
        } while (elementIndex < typeObjectSize);
      }
    }
    std__vector_TIntermNode__pool_allocator_TIntermNode_____erase
              (eraseResultSlot,this_00,*(undefined4 *)(this_00 + 4));
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
  int *a0;
  int *childNode;
  undefined4 a1;
  undefined4 a1_00;
  unsigned char * a2;
  unsigned char * a3;
  int a4;
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
    a2 = type;
    a3 = intermAggregate;
    a4 = index;
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
                            ((int *)**(undefined4 **)(aggregateSequence + 4),a1,a2,a3,a4,scratchR8,childVtable);
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
        a0 = (int *)((ulonglong)newNodeAlloc >> 0x20);
        childNode = (int *)**(undefined4 **)(aggregateSequence + 4);
        childNode = (int *)(**(code **)(*childNode + 0x18))
                                   (childNode,(int)newNodeAlloc,a2,a3,a4,scratchR8,*(undefined4 **)(aggregateSequence + 4));
        (**(code **)(*childNode + 0x38))(&stackType,childNode);
        *a0 = (int)&PTR_getLine_a7b7cf90;
        a0[1] = 0;
        a0[3] = stackTypeArraySize;
        a0[4] = stackTypeStructure;
        a0[5] = stackTypeFieldName;
        a0[6] = stackTypeTypeName;
        a0[7] = stackTypeWord14;
        a0[8] = stackTypeStructureSize;
        a0[2] = (int)&PTR___ZN5TTypeD1Ev_a7b7cff8;
        a0[9] = stackTypeWord1c;
        a0[10] = stackTypeWord20;
        oldTypeBits = a0[0xb];
        typeQualifierBits = stackTypeBits & 0xfe000000;
        a0[0xb] = typeQualifierBits | oldTypeBits & 0x1ffffff;
        typeBasicTypeBits = (stackTypeBits >> 0x13 & 0x3f) << 0x13;
        a0[0xb] = typeBasicTypeBits | typeQualifierBits | oldTypeBits & 0x7ffff;
        typeSizeBits = stackTypeBits & 0x7f800;
        a0[0xb] = typeSizeBits | typeBasicTypeBits | typeQualifierBits | oldTypeBits & 0x7ff;
        typeMatrixBit = (stackTypeBits >> 10 & 1) << 10;
        a0[0xb] = typeMatrixBit | typeSizeBits | typeBasicTypeBits | typeQualifierBits | oldTypeBits & 0x3ff;
        a0[0xb] = (stackTypeBits >> 9 & 1) << 9 | typeMatrixBit | typeSizeBits | typeBasicTypeBits | typeQualifierBits | oldTypeBits & 0x1ff;
        a0[0xc] = (int)constValueSlot;
        *a0 = (int)constantUnionVtable;
        stackType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
        nodeVtable = *a0;
        result = (*(code *)**(undefined4 **)intermAggregate)(intermAggregate,a1_00,a2,a3,a4,scratchR8,a0 + 2);
        (**(code **)(nodeVtable + 4))(a0,result);
        a2 = (unsigned char *)(*(int *)(vector + 4) + index * 4 + elementIndex * 4);
        a3 = (unsigned char *)insertNodeSlot;
        elementIndex = elementIndex + 1;
        insertNodeSlot[0] = a0;
        std__vector_TIntermNode__pool_allocator_TIntermNode_____insert(insertResultSlot,vector,a2,a3);
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
  unsigned char * this_00;
  unsigned char * this_01;
  int *headerNode;
  int existingPragmaTable;
  
  existingPragmaTable = *(int *)(this + 0x68);
  if (existingPragmaTable != 0) {
    ___eprintf("%s:%u: failed assertion `%s\'\n",
               "/SourceCache/OpenGL/OpenGL-4.7.14/GLProgrammability/glslang/MachineIndependent/Intermediate.cpp"
               ,0x865,"!pragmaTable");
  }
  this_00 = operator_new(0x10);
  this_01 = (unsigned char *)GetGlobalPoolAllocator();
  *(unsigned char **)this_00 = this_01;
  *(int *)(this_00 + 4) = existingPragmaTable;
  headerNode = (int *)TPoolAllocator__allocate(this_01,0x20);
  *(int *)(this_00 + 8) = existingPragmaTable;
  *(int **)(this_00 + 4) = headerNode;
  *headerNode = existingPragmaTable;
  *(int *)(*(int *)(this_00 + 4) + 4) = existingPragmaTable;
  *(int *)(*(int *)(this_00 + 4) + 8) = *(int *)(this_00 + 4);
  *(int *)(*(int *)(this_00 + 4) + 0xc) = *(int *)(this_00 + 4);
  *(unsigned char
    **)(this + 0x68) = this_00;
  return std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string_____operator_(this_00,(unsigned char *)map);
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
  uint a1;
  char reservation;
  byte cr0Flags;
  int locString [4];
  char locTextBuf [64];
  unsigned char allocatorDummy [28];
  
  sourceLoc = (*(code *)**(undefined4 **)intermNode)(intermNode,intermNode,depth);
  a1 = sourceLoc & 0xffff;
  cr0Flags = (a1 == 0) << 1;
  if (a1 == 0) {
    _sprintf(locTextBuf,"%d:? ",(int)sourceLoc >> 0x10);
  }
  else {
    _sprintf(locTextBuf,"%d:%d",(int)sourceLoc >> 0x10,a1);
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
  undefined4 a1;
  undefined4 a1_00;
  int a2;
  int a6;
  undefined4 nameChars;
  char reservation;
  byte cr0Reg;
  char symbolTextBuf [112];
  undefined4 typeString;
  int typeStringChars;
  undefined4 destroyAllocatorArg [7];
  
  a2 = *(int *)(intermTraverser + 0x20);
  ((int (*)())OutputTreeText)(*(unsigned char **)(intermTraverser + 0x30),(unsigned char *)intermSymbol,a2);
  ((int (*)())TType__getCompleteString)(&typeString,intermSymbol + 8);
  typeCharsCopy = typeStringChars;
  stringTerminal = DAT_a7b7b9e0;
  *(undefined1 *)(typeStringChars + *(int *)(typeStringChars + -0xc)) = *DAT_a7b7b9e0;
  symbolName = (**(code **)(*(int *)intermSymbol + 0x60))(intermSymbol,a1,a2,scratchR6,scratchR7,scratchR8,typeStringChars);
  a6 = *(int *)(symbolName + 4);
  *(undefined1 *)(a6 + *(int *)(a6 + -0xc)) = *stringTerminal;
  nameChars = *(undefined4 *)(symbolName + 4);
  symbolId = (**(code **)(*(int *)intermSymbol + 0x5c))(intermSymbol,a1_00,a2,scratchR6,scratchR7,scratchR8,a6,symbolName);
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
  int atomicStore;
  int *refCountPtr;
  int oldRefCount;
  char *opName;
  unsigned char * pTVar5;
  char reservation;
  byte cr0Reg;
  undefined4 typeString;
  int typeStringChars;
  undefined4 destroyAllocatorArg [5];
  
  pTVar5 = *(unsigned char **)(intermTraverser + 0x30);
  ((int (*)())OutputTreeText)(pTVar5,(unsigned char *)intermBinary,*(int *)(intermTraverser + 0x20));
  if (*(int *)(intermBinary + 0x30) == 0x15) {
    opName = "Multiply";
  }
  else {
    opName = *(char **)(PTR__operatorStrings_a7b7c0b0 + *(int *)(intermBinary + 0x30) * 4);
  }
  pTVar5 = pTVar5 + 8;
  __ZN13TInfoSinkBase6appendEPKc(pTVar5,opName);
  __ZN13TInfoSinkBase6appendEPKc(pTVar5," (");
  ((int (*)())TType__getCompleteString)(&typeString,intermBinary + 8);
  __ZN13TInfoSinkBase6appendERKSbIcSt11char_traitsIcE14pool_allocatorIcEE
            (pTVar5,(unsigned char *)&typeString);
  __ZN13TInfoSinkBase6appendEPKc(pTVar5,")");
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
  __ZN13TInfoSinkBase6appendEPKc(pTVar5,"\n");
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
  unsigned char * pTVar4;
  unsigned char * this;
  char reservation;
  byte cr0Reg;
  undefined4 typeString;
  int typeStringChars;
  undefined4 destroyAllocatorArg [5];
  
  pTVar4 = *(unsigned char **)(intermTraverser + 0x30);
  if (*(int *)(intermAggregate + 0x30) == 0) {
                    
    __ZN13TInfoSinkBase6appendEPKc(pTVar4 + 8,"ERROR: ");
    __ZN13TInfoSinkBase6appendEPKc(pTVar4 + 8,"node is still EOpNull!");
  }
  else {
    ((int (*)())OutputTreeText)(pTVar4,(unsigned char *)intermAggregate,*(int *)(intermTraverser + 0x20));
    this = pTVar4 + 8;
    __ZN13TInfoSinkBase6appendEPKc
              (this,*(char **)(PTR__operatorStrings_a7b7c0b0 + *(int *)(intermAggregate + 0x30) * 4));
    if ((*(int *)(intermAggregate + 0x30) != 1) && (*(int *)(intermAggregate + 0x30) != 4)) {
      __ZN13TInfoSinkBase6appendEPKc(this," (");
      ((int (*)())TType__getCompleteString)(&typeString,intermAggregate + 8);
      __ZN13TInfoSinkBase6appendERKSbIcSt11char_traitsIcE14pool_allocatorIcEE
                (this,(unsigned char *)&typeString);
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
    }
  }
  __ZN13TInfoSinkBase6appendEPKc(pTVar4 + 8,"\n");
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
  undefined4 a1;
  char *boolText;
  undefined ***pppuVar8;
  uint a1_00;
  int componentIndex;
  unsigned char * pTVar10;
  unsigned char * this;
  char reservation;
  byte cr0Flags;
  double scratchF3;
  double scratchF4;
  double scratchF5;
  double scratchF6;
  double scratchF7;
  double scratchF8;
  double in_stack_fffffe08;
  double in_stack_fffffe10;
  double in_stack_fffffe18;
  double in_stack_fffffe20;
  double in_stack_fffffe28;
  undefined **typeTemp1OrTextBuf [4];
  char locTextBuf [20];
  uint typeTemp1Bits;
  undefined **typeTemp2 [6];
  int typeTemp2Structure;
  unsigned char allocatorDummy [4];
  uint typeTemp2Bits;
  char floatTextBuf [312];
  
  this = *(unsigned char **)(intermTraverser + 0x30);
  (**(code **)(*(int *)intermConstantUnion + 0x38))(typeTemp1OrTextBuf,intermConstantUnion);
  typeTemp1OrTextBuf[0] = &PTR___ZN5TTypeD1Ev_a7b7d080;
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
      ((int (*)())OutputTreeText)(this,(unsigned char *)intermConstantUnion,*(int *)(intermTraverser + 0x20));
      getTypeResult = (**(code **)(*(int *)intermConstantUnion + 0x38))(typeTemp1OrTextBuf,intermConstantUnion);
      componentBasicType = typeTemp1Bits >> 0x13 & 0x3f;
      typeTemp1OrTextBuf[0] = &PTR___ZN5TTypeD1Ev_a7b7d080;
      if (componentBasicType == 2) {
        _sprintf((char *)typeTemp1OrTextBuf,"%d (%s)",*(undefined4 *)(*(int *)(intermConstantUnion + 0x30) + componentIndex * 4),
                 "const int");
        pppuVar8 = typeTemp1OrTextBuf;
LAB_97b977f0:
        __ZN13TInfoSinkBase6appendEPKc(this + 8,(char *)pppuVar8);
LAB_97b977f8:
        pTVar10 = this + 8;
      }
      else {
        if (componentBasicType < 3) {
          if (componentBasicType == 1) {
            ((char * (*)())_glp_dtostr)(getTypeResult,a1,floatTextBuf,300,
                        (double)*(float *)(*(int *)(intermConstantUnion + 0x30) + componentIndex * 4),DOUBLE_97c30a70,
                        scratchF3,scratchF4,scratchF5,scratchF6,scratchF7,scratchF8,in_stack_fffffe08,in_stack_fffffe10,
                        in_stack_fffffe18,in_stack_fffffe20,in_stack_fffffe28);
            _sprintf(floatTextBuf,"%s (%s)",floatTextBuf,"const float");
            __ZN13TInfoSinkBase6appendEPKc(this + 8,floatTextBuf);
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
          pTVar10 = this + 8;
          __ZN13TInfoSinkBase6appendEPKc(pTVar10,boolText);
          __ZN13TInfoSinkBase6appendEPKc(pTVar10," (");
          __ZN13TInfoSinkBase6appendEPKc(pTVar10,"const bool");
          pppuVar8 = (undefined ***)")";
          goto LAB_97b977f0;
        }
        sourceLoc = (*(code *)**(undefined4 **)intermConstantUnion)(intermConstantUnion,a1);
                    
        __ZN13TInfoSinkBase6appendEPKc(this,"INTERNAL ERROR: ");
        a1_00 = sourceLoc & 0xffff;
        cr0Flags = (a1_00 == 0) << 1;
        if (a1_00 == 0) {
          _sprintf(locTextBuf,"%d:? ",(int)sourceLoc >> 0x10);
        }
        else {
          _sprintf(locTextBuf,"%d:%d",(int)sourceLoc >> 0x10,a1_00);
        }
        __ZNSsC1EPKcRKSaIcE(typeTemp1OrTextBuf,locTextBuf,allocatorDummy);
        *(undefined *)((int)typeTemp1OrTextBuf[0] + (int)typeTemp1OrTextBuf[0][-3]) = *PTR__S_terminal_a7b7c0b8;
        __ZN13TInfoSinkBase6appendEPKc(this,(char *)typeTemp1OrTextBuf[0]);
        refCountPtr = typeTemp1OrTextBuf[0] + -1;
        do {
          oldRefCount = *refCountPtr;
          if (reservation != '\0') {
            atomicStore = (undefined *)storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
            *refCountPtr = atomicStore;
            cr0Flags = 2;
          }
        } while (!(bool)(cr0Flags >> 1 & 1));
        if ((int)oldRefCount < 1) {
          __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(typeTemp1OrTextBuf[0] + -3));
        }
        __ZN13TInfoSinkBase6appendEPKc(this,": ");
        __ZN13TInfoSinkBase6appendEPKc(this,"Unknown constant");
        pTVar10 = this;
      }
      componentIndex = componentIndex + 1;
      __ZN13TInfoSinkBase6appendEPKc(pTVar10,"\n");
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
  undefined4 a1;
  undefined4 r4Out0;
  undefined ***pppuVar9;
  uint traverserTypeBits;
  int levelsBeginOrVariable;
  int a0;
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
      symbolNameString = (**(code **)(*(int *)intermSymbol + 0x60))(intermSymbol,a1);
      levelsBeginOrVariable = *levelsVector;
      levelIndex = (levelsVector[1] - levelsBeginOrVariable >> 2) + -1;
      while( true ) {
        level = *(int *)(levelsBeginOrVariable + levelIndex * 4);
        levelsBeginOrVariable = 0;
        std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______find((unsigned char *)findResult,level,symbolNameString);
        if (findResult[0] != *(int *)(level + 4)) {
          levelsBeginOrVariable = *(int *)(findResult[0] + 0x18);
        }
        levelIndex = levelIndex + -1;
        if ((levelsBeginOrVariable != 0) || (levelIndex < 0)) break;
        levelsBeginOrVariable = *levelsVector;
      }
      constArrayAlloc = CONCAT44(*(int *)(levelsBeginOrVariable + 0x38),r4Out0);
      if (*(int *)(levelsBeginOrVariable + 0x38) == 0) {
        if (*(int *)(levelsBeginOrVariable + 0x14) == 0) {
          variableTypeBits = *(uint *)(levelsBeginOrVariable + 0x30);
          if ((variableTypeBits & 0x400) == 0) {
            objectSize = (int)(variableTypeBits << 0xd | variableTypeBits >> 0x13) >> 0x18;
          }
          else {
            objectSize = (int)(variableTypeBits << 0xd | variableTypeBits >> 0x13) >> 0x18;
            objectSize = objectSize * objectSize;
          }
        }
        else {
          objectSize = *(int *)(levelsBeginOrVariable + 0x24);
        }
        this = (unsigned char *)GetGlobalPoolAllocator();
        constArrayAlloc = TPoolAllocator__allocate(this,objectSize << 2);
        *(int *)(levelsBeginOrVariable + 0x38) = (int)((ulonglong)constArrayAlloc >> 0x20);
      }
      constArray = (int)((ulonglong)constArrayAlloc >> 0x20);
      if (constArray != 0) {
        a0 = levelsBeginOrVariable + 0xc;
        variableBasicType = (**(code **)(*(int *)(levelsBeginOrVariable + 0xc) + 0x20))(a0,(int)constArrayAlloc);
        if (variableBasicType == 0xe) {
          componentCount = *(int *)(levelsBeginOrVariable + 0x24);
        }
        else {
          componentCount = (**(code **)(*(int *)(levelsBeginOrVariable + 0xc) + 0x30))(a0);
        }
        componentIndex = 0;
        if (componentCount < 1) {
          return;
        }
        do {
          if (instanceSize <= *(int *)(intermTraverser + 0x30)) {
            return;
          }
          variableBasicTypeU = (**(code **)(*(int *)(levelsBeginOrVariable + 0xc) + 0x20))(a0);
          traverserBasicType = *(uint *)(intermTraverser + 0x60) >> 0x13 & 0x3f;
          if ((variableBasicTypeU == traverserBasicType) || (traverserBasicType == 0xe)) {
code_r0x97b98c14:
            *(undefined4 *)(resultArray + *(int *)(intermTraverser + 0x30) * 4) =
                 *(undefined4 *)(componentIndex * 4 + constArray);
          }
          else {
            componentSrcBasicType = (**(code **)(*(int *)(levelsBeginOrVariable + 0xc) + 0x20))(a0);
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
      pppuVar9 = &stackType;
    }
    else {
      ((int (*)())TType__getCompleteString)(&stackType,intermTraverser + 0x3c);
      pppuVar9 = messageBuf;
      *(undefined1 *)(stackTypeArraySize + *(int *)(stackTypeArraySize + -0xc)) = *DAT_a7b7ba10;
      _sprintf((char *)pppuVar9,"\'constructor\' : assigning non-constant to %s",stackTypeArraySize);
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
    __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)pppuVar9);
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
  uint a1;
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
  a1 = sourceLoc & 0xffff;
  cr0Flags = (a1 == 0) << 1;
  if (a1 == 0) {
    _sprintf(locTextBuf,"%d:? ",(int)sourceLoc >> 0x10);
  }
  else {
    _sprintf(locTextBuf,"%d:%d",(int)sourceLoc >> 0x10,a1);
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
  undefined4 a1;
  unsigned char * a2;
  uint a1_00;
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
  
  a2 = intermTraverser;
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
    a1_00 = sourceLoc & 0xffff;
    cr0Flags = (a1_00 == 0) << 1;
    if (a1_00 == 0) {
      _sprintf(locTextBuf,"%d:? ",(int)sourceLoc >> 0x10);
    }
    else {
      _sprintf(locTextBuf,"%d:%d",(int)sourceLoc >> 0x10,a1_00);
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
                                  ((int *)**(undefined4 **)(sequence + 4),a1,a2,scratchR6,scratchR7,scratchR8
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
                  (typeTemp1,intermAggregate,a2,scratchR6,scratchR7,scratchR8,*(int *)intermAggregate);
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
                    (typeTemp2,intermAggregate,a2,scratchR6,scratchR7,scratchR8,typeTemp1Bits & 0x400);
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
  uint a1;
  void *this;
  char reservation;
  byte cr0Flags;
  char *locString [4];
  char locTextBuf [64];
  unsigned char allocatorDummy [28];
  
  this = *(void **)(intermTraverser + 0x6c);
  sourceLoc = (*(code *)**(undefined4 **)intermSelection)(intermSelection,intermSelection,intermTraverser);
  __ZN13TInfoSinkBase6appendEPKc(this,"INTERNAL ERROR: ");
  a1 = sourceLoc & 0xffff;
  cr0Flags = (a1 == 0) << 1;
  if (a1 == 0) {
    _sprintf(locTextBuf,"%d:? ",(int)sourceLoc >> 0x10);
  }
  else {
    _sprintf(locTextBuf,"%d:%d",(int)sourceLoc >> 0x10,a1);
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
  unsigned char * a6;
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
  
  a6 = intermTraverser + 0x3c;
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
        (**(code **)(*(int *)intermConstantUnion + 0x38))(typeTemp2a,intermConstantUnion,scratchR5,scratchR6,scratchR7,scratchR8,a6);
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
  uint a1;
  void *this;
  char reservation;
  byte cr0Flags;
  char *locString [4];
  char locTextBuf [64];
  unsigned char allocatorDummy [28];
  
  this = *(void **)(intermTraverser + 0x6c);
  sourceLoc = (*(code *)**(undefined4 **)intermLoop)(intermLoop,intermLoop,intermTraverser);
  __ZN13TInfoSinkBase6appendEPKc(this,"INTERNAL ERROR: ");
  a1 = sourceLoc & 0xffff;
  cr0Flags = (a1 == 0) << 1;
  if (a1 == 0) {
    _sprintf(locTextBuf,"%d:? ",(int)sourceLoc >> 0x10);
  }
  else {
    _sprintf(locTextBuf,"%d:%d",(int)sourceLoc >> 0x10,a1);
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
  uint a1;
  void *this;
  char reservation;
  byte cr0Flags;
  char *locString [4];
  char locTextBuf [64];
  unsigned char allocatorDummy [28];
  
  this = *(void **)(intermTraverser + 0x6c);
  sourceLoc = (*(code *)**(undefined4 **)intermBranch)(intermBranch,intermBranch,intermTraverser);
  __ZN13TInfoSinkBase6appendEPKc(this,"INTERNAL ERROR: ");
  a1 = sourceLoc & 0xffff;
  cr0Flags = (a1 == 0) << 1;
  if (a1 == 0) {
    _sprintf(locTextBuf,"%d:? ",(int)sourceLoc >> 0x10);
  }
  else {
    _sprintf(locTextBuf,"%d:%d",(int)sourceLoc >> 0x10,a1);
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
  uint textLengthOrTerminal;
  char *textChars;
  
  *(undefined4 *)(matrixFields + 4) = 0;
  *(undefined4 *)(matrixFields + 0xc) = 0xffffffff;
  *(undefined4 *)matrixFields = 0;
  *(undefined4 *)(matrixFields + 8) = 0xffffffff;
  textChars = *(char **)(text + 4);
  textLengthOrTerminal = *(uint *)(textChars + -0xc);
  if (textLengthOrTerminal == 2) {
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
        textLengthOrTerminal = (uint)*DAT_a7b7ba18;
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
      textLengthOrTerminal = (uint)*DAT_a7b7ba18;
      textChars[*(int *)(textChars + -0xc)] = *DAT_a7b7ba18;
    }
    textChars = *(char **)(text + 4);
    errorMessage = "illegal matrix field selection";
  }
  else {
    errorMessage = "illegal length of matrix field selection";
    textChars[textLengthOrTerminal] = *DAT_a7b7ba18;
LAB_97b9a790:
    textChars = *(char **)(text + 4);
  }
  error((int)this,(char *)line,errorMessage,textChars,"",this,textLengthOrTerminal,line);
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
  uint a1;
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
  a1 = (uint)sourceLoc & 0xffff;
  cr0Flags = (a1 == 0) << 1;
  if (a1 == 0) {
    _sprintf(locTextBuf,"%d:? ",(int)sourceLoc >> 0x10);
  }
  else {
    _sprintf(locTextBuf,"%d:%d",(int)sourceLoc >> 0x10,a1);
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
  unsigned char * pTVar5;
  int componentConstUnion;
  uint qualifier;
  undefined4 r4Out0;
  undefined4 r4Out1;
  undefined4 a1;
  undefined4 a1_00;
  char *tokenCopy;
  char *extraInfoFormat;
  undefined4 *elementCursor;
  undefined4 symbolNameChars;
  char *modifyReason;
  int componentSeen [4];
  
  tokenCopy = str;
  pTVar5 = intermTyped;
  symbolNode = (int *)(**(code **)(*(int *)intermTyped + 0x28))(intermTyped);
  binaryNode = (int *)(**(code **)(*(int *)intermTyped + 0x20))(intermTyped);
  if (binaryNode == (int *)0x0) {
    hasSymbolNode = symbolNode != (int *)0x0;
    symbolNameChars = 0;
    a1 = r4Out0;
    if (hasSymbolNode) {
      symbolName = (**(code **)(*symbolNode + 0x60))(symbolNode);
      scratchR9 = (uint)*DAT_a7b7ba18;
      *(byte *)(*(int *)(symbolName + 4) + *(int *)(*(int *)(symbolName + 4) + -0xc)) = *DAT_a7b7ba18;
      symbolNameChars = *(undefined4 *)(symbolName + 4);
      a1 = r4Out1;
    }
    modifyReason = (char *)0x0;
    qualifier = (**(code **)(*(int *)intermTyped + 0x44))(intermTyped,a1,tokenCopy,pTVar5,scratchR7,scratchR8,scratchR9);
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
                        (intermTyped,a1_00,tokenCopy,pTVar5,scratchR7,scratchR8,scratchR9);
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
      pTVar5 = (unsigned char *)(**(code **)(*binaryNode + 0x68))(binaryNode);
      lValueErrorCheckResult = ((int (*)())TParseContext__lValueErrorCheck)(this,sourceLoc,str,pTVar5,scratchR7,scratchR8,scratchR9,scratchR10);
      return lValueErrorCheckResult;
    }
    if (binaryOp != 0x30) goto LAB_97b9ae0c;
    pTVar5 = (unsigned char *)(**(code **)(*binaryNode + 0x68))(binaryNode);
    componentSeen[0] = ((int (*)())TParseContext__lValueErrorCheck)(this,sourceLoc,str,pTVar5,scratchR7,scratchR8,scratchR9,scratchR10);
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
  int *argTyped;
  char *errorReason;
  int totalSize;
  int argBasicType;
  int paramIsArray;
  int paramTypeVtable;
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
  unsigned char * this_00;
  void *this_01;
  uint *a0;
  int paramSizeOrScratchR4;
  int r4Out0;
  int r4Out1;
  int r4Out2;
  undefined4 a1;
  undefined4 r4Out3;
  undefined4 r4Out4;
  undefined4 a1_00;
  int r4Out5;
  int r4Out6;
  int r4Out7;
  undefined4 a1_01;
  undefined4 r4Out8;
  undefined4 scratchR4;
  unsigned char * pTVar12;
  char *structNameChars;
  unsigned char * pTVar14;
  char *errorToken;
  int opCopy;
  char *extraInfoFormat;
  int *typeCopy;
  uint a6;
  uint ctorTypeBits;
  int a6_00;
  int scratchR10;
  unsigned char * pTVar20;
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
  int nameCopy1CharsOrScratch;
  undefined4 nameCopy2;
  char *nameCopy2Chars;
  undefined4 allocatorArg [4];
  undefined4 destroyArgA [4];
  undefined4 destroyArgB [4];
  
  a6 = op - 0x66;
  paramSizeOrScratchR4 = sourceLoc;
  pTVar12 = intermNode;
  pTVar14 = function;
  opCopy = op;
  typeCopy = type;
  switch(a6) {
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
    a6 = 0;
    stackTypeBits = ctorTypeBits & 0xfffff9ff;
    nameCopy1CharsOrScratch = stackTypeBits << 0xd;
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
    a6 = ctorTypeBits & 0xfffffdff | 0x400;
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
    nameCopy1CharsOrScratch = scratchR10;
    stackTypeBits = a6;
    goto LAB_97b9b714;
  case 0xf:
    pTVar20 = *(unsigned char **)(function + 0x24);
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
    stackTypeStructure = pTVar20;
    stackTypeStructureSize = TType__setStructSize((unsigned char *)&stackType,pTVar20);
    structNameChars = nameCopy2Chars;
    nameCopy2Chars[*(int *)(nameCopy2Chars + -0xc)] = *DAT_a7b7ba18;
    this_00 = (unsigned char *)GetGlobalPoolAllocator();
    allocPair = TPoolAllocator__allocate(this_00,8);
    this_01 = (void *)((ulonglong)allocPair >> 0x20);
    paramSizeOrScratchR4 = (int)allocPair;
    cr0Flags = (this_01 == (void *)0x0) << 1;
    stackTypeTypeName = (void *)0x0;
    if (this_01 != (void *)0x0) {
      allocatorArg[0] = GetGlobalPoolAllocator();
      pTVar12 = (unsigned char *)allocatorArg;
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                (this_01,structNameChars,(unsigned char *)pTVar12);
      stackTypeTypeName = this_01;
      paramSizeOrScratchR4 = r4Out0;
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
      paramSizeOrScratchR4 = r4Out1;
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
    refCountPtr = (int *)(nameCopy1CharsOrScratch + -4);
    type[8] = stackTypeWord20;
    stackType = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
    destroyArgB[0] = nameCopy1;
    do {
      oldRefCount = *refCountPtr;
      a6 = oldRefCount - 1;
      if (reservation != '\0') {
        newRefCount = storeWordConditionalIndexed(a6,0,refCountPtr);
        *refCountPtr = newRefCount;
        cr0Flags = 2;
      }
    } while (!(bool)(cr0Flags >> 1 & 1));
    if (oldRefCount < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(nameCopy1CharsOrScratch + -0xc),destroyArgB);
      paramSizeOrScratchR4 = r4Out2;
    }
    goto LAB_97b9b714;
  default:
    errorReason = "expected constructor";
    errorToken = "Internal Error";
    goto LAB_97b9b9d8;
  }
  a6 = ctorNominalSize << 0xb | ctorTypeBits & 0xfff801ff;
  nameCopy1CharsOrScratch = a6 << 0xd;
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
  stackTypeBits = a6;
LAB_97b9b714:
  totalSize = 0;
  constType = true;
  full = false;
  overFull = false;
  matrixInMatrix = false;
  arrayArg = false;
  scratchR10 = nameCopy1CharsOrScratch;
  for (paramIndex = 0; paramIndex < *(int *)(function + 0x14) - *(int *)(function + 0x10) >> 3;
      paramIndex = paramIndex + 1) {
    paramOffset = paramIndex * 8;
    paramType = *(int **)(*(int *)(function + 0x10) + paramOffset + 4);
    a6_00 = *paramType;
    paramSizeOrScratchR4 = (**(code **)(a6_00 + 0x30))(paramType,paramSizeOrScratchR4,pTVar12,pTVar14,opCopy,typeCopy,a6_00);
    totalSize = totalSize + paramSizeOrScratchR4;
    scratchR4 = a1;
    if ((op - 0x72U < 3) &&
       (paramType = *(int **)(*(int *)(function + 0x10) + paramOffset + 4), paramSizeOrScratchR4 = *paramType,
       paramSizeOrScratchR4 = (**(code **)(paramSizeOrScratchR4 + 0x34))(paramType,a1,pTVar12,pTVar14,opCopy,typeCopy,paramSizeOrScratchR4),
       scratchR4 = r4Out3, paramSizeOrScratchR4 != 0)) {
      matrixInMatrix = true;
    }
    if (full) {
      overFull = true;
    }
    if ((op != 0x75) &&
       (paramSizeOrScratchR4 = (**(code **)(*type + 0x30))(type), scratchR4 = r4Out4, paramSizeOrScratchR4 <= totalSize))
    {
      full = true;
    }
    paramType = *(int **)(*(int *)(function + 0x10) + paramOffset + 4);
    paramTypeVtable = *paramType;
    paramTypeVtable = (**(code **)(paramTypeVtable + 0x24))(paramType,scratchR4,pTVar12,pTVar14,opCopy,typeCopy,paramTypeVtable);
    if (paramTypeVtable != 2) {
      constType = false;
    }
    a0 = *(uint **)(*(int *)(function + 0x10) + paramOffset + 4);
    a6 = *a0;
    paramIsArray = (**(code **)(a6 + 0x38))(a0,a1_00,pTVar12,pTVar14,opCopy,typeCopy,a6);
    if (paramIsArray != 0) {
      arrayArg = true;
    }
    paramSizeOrScratchR4 = r4Out5;
  }
  if (constType) {
    (**(code **)(*type + 0x28))(type,2);
    paramSizeOrScratchR4 = r4Out6;
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
             (paramIndex = (**(code **)(*type + 0x30))(type,paramSizeOrScratchR4,pTVar12,pTVar14,opCopy),
             paramSizeOrScratchR4 = r4Out7, paramIndex <= totalSize)) && ((0 < totalSize || (op != 0x75)))) {
      argTyped = (int *)(**(code **)(*(int *)intermNode + 0x14))(intermNode,paramSizeOrScratchR4,pTVar12,pTVar14,opCopy);
      if (argTyped == (int *)0x0) {
        errorReason = "constructor argument does not have a type";
      }
      else {
        scratchR4 = a1_01;
        if ((op == 0x75) ||
           (paramSizeOrScratchR4 = (**(code **)(*argTyped + 0x40))(argTyped,a1_01,pTVar12,pTVar14,opCopy),
           scratchR4 = r4Out8, 7 < paramSizeOrScratchR4 - 5U)) {
          argBasicType = (**(code **)(*argTyped + 0x40))(argTyped,scratchR4,pTVar12,pTVar14,opCopy);
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
  error((int)this,(char *)sourceLoc,errorReason,errorToken,extraInfoFormat,typeCopy,a6,scratchR10);
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

