#include "decls.h"

/* TIntermNode__getAsSymbolNode @ 0x97c31d90 (8 bytes) */
int TIntermNode__getAsSymbolNode()
{
  return 0;
}

/* TIntermTyped__getAsTyped @ 0x97c31d98 (4 bytes) */
int TIntermTyped__getAsTyped()
{
  return;
}

/* TIntermTyped__setType @ 0x97c31d9c (152 bytes) */
int TIntermTyped__setType(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  
  uVar6 = *(undefined4 *)(param_1 + 8);
  uVar10 = *(undefined4 *)(param_1 + 0xc);
  uVar12 = *(undefined4 *)(param_1 + 0x10);
  uVar11 = *(undefined4 *)(param_1 + 0x14);
  uVar9 = *(undefined4 *)(param_1 + 0x18);
  uVar8 = *(undefined4 *)(param_1 + 0x1c);
  uVar7 = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 0x10) = uVar6;
  *(undefined4 *)(this + 0x14) = uVar10;
  *(undefined4 *)(this + 0x18) = uVar12;
  *(undefined4 *)(this + 0x1c) = uVar11;
  *(undefined4 *)(this + 0x20) = uVar9;
  *(undefined4 *)(this + 0x24) = uVar8;
  *(undefined4 *)(this + 0x28) = uVar7;
  uVar5 = *(uint *)(this + 0x2c);
  uVar2 = *(uint *)(param_1 + 0x24) & 0xfe000000;
  *(uint *)(this + 0x2c) = uVar2 | uVar5 & 0x1ffffff;
  uVar3 = (*(uint *)(param_1 + 0x24) >> 0x13 & 0x3f) << 0x13;
  *(uint *)(this + 0x2c) = uVar3 | uVar2 | uVar5 & 0x7ffff;
  uVar1 = *(uint *)(param_1 + 0x24) & 0x7f800;
  *(uint *)(this + 0x2c) = uVar1 | uVar3 | uVar2 | uVar5 & 0x7ff;
  uVar4 = (*(uint *)(param_1 + 0x24) >> 10 & 1) << 10;
  *(uint *)(this + 0x2c) = uVar4 | uVar1 | uVar3 | uVar2 | uVar5 & 0x3ff;
  *(uint *)(this + 0x2c) =
       (*(uint *)(param_1 + 0x24) >> 9 & 1) << 9 | uVar4 | uVar1 | uVar3 | uVar2 | uVar5 & 0x1ff;
  return;
}

/* TIntermTyped__getType @ 0x97c31e34 (192 bytes) */
int TIntermTyped__getType()
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *in_r3;
  int in_r4;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  
  uVar12 = *(undefined4 *)(in_r4 + 0x28);
  uVar11 = *(undefined4 *)(in_r4 + 0x10);
  uVar10 = *(undefined4 *)(in_r4 + 0x14);
  uVar9 = *(undefined4 *)(in_r4 + 0x18);
  uVar8 = *(undefined4 *)(in_r4 + 0x1c);
  uVar7 = *(undefined4 *)(in_r4 + 0x20);
  uVar6 = *(undefined4 *)(in_r4 + 0x24);
  in_r3[1] = *(undefined4 *)(in_r4 + 0xc);
  in_r3[2] = uVar11;
  in_r3[3] = uVar10;
  in_r3[4] = uVar9;
  in_r3[5] = uVar8;
  in_r3[6] = uVar7;
  in_r3[7] = uVar6;
  in_r3[8] = uVar12;
  *in_r3 = &PTR__TType_a7b7cff8;
  uVar5 = in_r3[9];
  uVar2 = *(uint *)(in_r4 + 0x2c) & 0xfe000000;
  in_r3[9] = uVar2 | uVar5 & 0x1ffffff;
  uVar3 = (*(uint *)(in_r4 + 0x2c) >> 0x13 & 0x3f) << 0x13;
  in_r3[9] = uVar3 | uVar2 | uVar5 & 0x7ffff;
  uVar1 = *(uint *)(in_r4 + 0x2c) & 0x7f800;
  in_r3[9] = uVar1 | uVar3 | uVar2 | uVar5 & 0x7ff;
  uVar4 = (*(uint *)(in_r4 + 0x2c) >> 10 & 1) << 10;
  in_r3[9] = uVar4 | uVar1 | uVar3 | uVar2 | uVar5 & 0x3ff;
  in_r3[9] = (*(uint *)(in_r4 + 0x2c) >> 9 & 1) << 9 | uVar4 | uVar1 | uVar3 | uVar2 | uVar5 & 0x1ff
  ;
  return;
}

/* TIntermTyped__getTypePointer @ 0x97c31ef4 (8 bytes) */
int TIntermTyped__getTypePointer(this)
  unsigned char * this;
{
  return this + 8;
}

/* TIntermTyped__getBasicType @ 0x97c31efc (12 bytes) */
int TIntermTyped__getBasicType(this)
  unsigned char * this;
{
  return *(uint *)(this + 0x2c) >> 0x13 & 0x3f;
}

/* TIntermTyped__getQualifier @ 0x97c31f08 (12 bytes) */
int TIntermTyped__getQualifier(this)
  unsigned char * this;
{
  return *(uint *)(this + 0x2c) >> 0x19;
}

/* TIntermTyped__getNominalSize @ 0x97c31f14 (16 bytes) */
int TIntermTyped__getNominalSize(this)
  unsigned char * this;
{
  return (int)(*(uint *)(this + 0x2c) << 0xd | *(uint *)(this + 0x2c) >> 0x13) >> 0x18;
}

/* TIntermTyped__getSize @ 0x97c31f24 (40 bytes) */
int TIntermTyped__getSize(this)
  unsigned char * this;
{
  uint uVar1;
  int iVar2;
  
  uVar1 = *(uint *)(this + 0x2c);
  if ((uVar1 & 0x400) != 0) {
    iVar2 = (int)(uVar1 << 0xd | uVar1 >> 0x13) >> 0x18;
    return iVar2 * iVar2;
  }
  return (int)(uVar1 << 0xd | uVar1 >> 0x13) >> 0x18;
}

/* TIntermTyped__isMatrix @ 0x97c31f4c (12 bytes) */
int TIntermTyped__isMatrix(this)
  unsigned char * this;
{
  return *(uint *)(this + 0x2c) >> 10 & 1;
}

/* TIntermTyped__isArray @ 0x97c31f58 (12 bytes) */
int TIntermTyped__isArray(this)
  unsigned char * this;
{
  return *(uint *)(this + 0x2c) >> 9 & 1;
}

/* TIntermTyped__isVector @ 0x97c31f64 (40 bytes) */
int TIntermTyped__isVector(this)
  unsigned char * this;
{
  uint uVar1;
  
  uVar1 = *(uint *)(this + 0x2c);
  if ((int)(uVar1 << 0xd | uVar1 >> 0x13) >> 0x18 < 2) {
    return 0;
  }
  if ((uVar1 & 0x400) != 0) {
    return 0;
  }
  return 1;
}

/* TIntermTyped___TIntermTyped @ 0x97c31f8c (52 bytes) */
int TIntermTyped___TIntermTyped(this)
  unsigned char * this;
{
  *(undefined ***)this = &PTR_getLine_a7b7d040;
  *(undefined ***)(this + 8) = &PTR__TType_a7b7cff8;
  return;
}

/* TIntermTyped___TIntermTyped_97c31fc0 @ 0x97c31fc0 (52 bytes) */
int TIntermTyped___TIntermTyped_97c31fc0(this)
  unsigned char * this;
{
  *(undefined ***)this = &PTR_getLine_a7b7d040;
  *(undefined ***)(this + 8) = &PTR__TType_a7b7cff8;
  return;
}

/* std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string______M_erase @ 0x97c31ff4 (192 bytes) */
int std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string______M_erase( unsigned char
           *this, unsigned char *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  unsigned char * p_Var5;
  char in_RESERVE;
  byte bVar6;
  
  bVar6 = (param_1 == (unsigned char *)0x0) << 1;
  if (param_1 != (unsigned char *)0x0) {
    do {
      ((int (*)())std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string______M_erase)((unsigned char *)this);
      iVar4 = *(int *)(param_1 + 0x1c);
      piVar2 = (int *)(iVar4 + -4);
      p_Var5 = *(unsigned char **)(param_1 + 8);
      do {
        iVar3 = *piVar2;
        if (in_RESERVE != '\0') {
          iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
          *piVar2 = iVar1;
          bVar6 = 2;
        }
      } while (!(bool)(bVar6 >> 1 & 1));
      if (iVar3 < 1) {
        std__string___Rep___M_destroy((unsigned char *)(iVar4 + -0xc));
      }
      iVar4 = *(int *)(param_1 + 0x14);
      piVar2 = (int *)(iVar4 + -4);
      do {
        iVar3 = *piVar2;
        if (in_RESERVE != '\0') {
          iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
          *piVar2 = iVar1;
          bVar6 = 2;
        }
      } while (!(bool)(bVar6 >> 1 & 1));
      if (iVar3 < 1) {
        std__string___Rep___M_destroy((unsigned char *)(iVar4 + -0xc));
      }
      param_1 = p_Var5;
    } while (p_Var5 != (unsigned char *)0x0);
  }
  return;
}

/* TIntermNode__getAsTyped @ 0x97c320b4 (8 bytes) */
int TIntermNode__getAsTyped()
{
  return 0;
}

/* TIntermNode___TIntermNode @ 0x97c320bc (36 bytes) */
int TIntermNode___TIntermNode(this)
  unsigned char * this;
{
  *(undefined ***)this = &PTR_getLine_a7b7d040;
  return;
}

/* TIntermNode___TIntermNode_97c320e0 @ 0x97c320e0 (36 bytes) */
int TIntermNode___TIntermNode_97c320e0(this)
  unsigned char * this;
{
  *(undefined ***)this = &PTR_getLine_a7b7d040;
  return;
}

/* getQualifierString @ 0x97c32104 (280 bytes) */
int getQualifierString(param_1)
  undefined4 param_1;
{
  switch(param_1) {
  case 0:
    return "Temporary";
  case 1:
    return "Global";
  case 2:
  case 0xc:
    return "const";
  case 3:
    return "attribute";
  case 4:
  case 5:
    return "varying";
  case 6:
    return "uniform";
  case 7:
    return "input";
  case 8:
    return "output";
  case 9:
    return "in";
  case 10:
    return "out";
  case 0xb:
    return "inout";
  case 0xd:
    return "Position";
  case 0xe:
    return "PointSize";
  case 0xf:
    return "ClipVertex";
  case 0x10:
    return "Face";
  case 0x11:
    return "FragCoord";
  case 0x12:
    return "FragColor";
  case 0x13:
    return "FragDepth";
  default:
    return "unknown qualifier";
  }
}

/* TType__getBasicString @ 0x97c3226c (220 bytes) */
int TType__getBasicString(param_1)
  undefined4 param_1;
{
  switch(param_1) {
  case 0:
    return "void";
  case 1:
    return "float";
  case 2:
    return "int";
  case 3:
    return "bool";
  default:
    return "unknown type";
  case 5:
    return "sampler1D";
  case 6:
    return "sampler2D";
  case 7:
    return "sampler3D";
  case 8:
    return "samplerCube";
  case 9:
    return "sampler1DShadow";
  case 10:
    return "sampler2DShadow";
  case 0xb:
    return "sampler2DRect";
  case 0xc:
    return "sampler2DRectShadow";
  case 0xe:
    return "structure";
  }
}

/* TIntermSymbol__getId @ 0x97c32384 (8 bytes) */
int TIntermSymbol__getId(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 0x30);
}

/* TIntermSymbol__getSymbol @ 0x97c3238c (8 bytes) */
int TIntermSymbol__getSymbol(this)
  unsigned char * this;
{
  return this + 0x34;
}

/* TIntermSymbol__getAsSymbolNode @ 0x97c32394 (4 bytes) */
int TIntermSymbol__getAsSymbolNode()
{
  return;
}

/* TIntermConstantUnion__getAsConstantUnion @ 0x97c32398 (4 bytes) */
int TIntermConstantUnion__getAsConstantUnion()
{
  return;
}

/* TIntermOperator__promote @ 0x97c3239c (8 bytes) */
int TIntermOperator__promote(param_1)
  unsigned char * param_1;
{
  return 1;
}

/* TIntermBinary__setLeft @ 0x97c323a4 (8 bytes) */
int TIntermBinary__setLeft(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  *(unsigned char **)(this + 0x34) = param_1;
  return;
}

/* TIntermBinary__setRight @ 0x97c323ac (8 bytes) */
int TIntermBinary__setRight(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  *(unsigned char **)(this + 0x38) = param_1;
  return;
}

/* TIntermBinary__getLeft @ 0x97c323b4 (8 bytes) */
int TIntermBinary__getLeft(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 0x34);
}

/* TIntermBinary__getRight @ 0x97c323bc (8 bytes) */
int TIntermBinary__getRight(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 0x38);
}

/* TIntermBinary__getAsBinaryNode @ 0x97c323c4 (4 bytes) */
int TIntermBinary__getAsBinaryNode()
{
  return;
}

/* TIntermUnary__setOperand @ 0x97c323c8 (8 bytes) */
int TIntermUnary__setOperand(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  *(unsigned char **)(this + 0x34) = param_1;
  return;
}

/* TIntermUnary__getOperand @ 0x97c323d0 (8 bytes) */
int TIntermUnary__getOperand(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 0x34);
}

/* TIntermAggregate___TIntermAggregate @ 0x97c323d8 (176 bytes) */
int TIntermAggregate___TIntermAggregate(this)
  unsigned char * this;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  char in_RESERVE;
  byte in_cr0;
  
  pvVar5 = *(void **)(this + 0x68);
  *(undefined ***)this = &PTR_getLine_a7b7d1b8;
  if (pvVar5 != (void *)0x0) {
    ((int (*)())std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string_____clear)();
    operator_delete(pvVar5);
  }
  iVar4 = *(int *)(this + 0x58);
  piVar2 = (int *)(iVar4 + -4);
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar3 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(iVar4 + -0xc));
  }
  *(undefined ***)this = &PTR_getLine_a7b7d400;
  *(undefined ***)(this + 8) = &PTR__TType_a7b7d440;
  return;
}

/* TIntermAggregate___TIntermAggregate_97c32488 @ 0x97c32488 (176 bytes) */
int TIntermAggregate___TIntermAggregate_97c32488(this)
  unsigned char * this;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  char in_RESERVE;
  byte in_cr0;
  
  pvVar5 = *(void **)(this + 0x68);
  *(undefined ***)this = &PTR_getLine_a7b7d1b8;
  if (pvVar5 != (void *)0x0) {
    ((int (*)())std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string_____clear)();
    operator_delete(pvVar5);
  }
  iVar4 = *(int *)(this + 0x58);
  piVar2 = (int *)(iVar4 + -4);
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar3 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(iVar4 + -0xc));
  }
  *(undefined ***)this = &PTR_getLine_a7b7d400;
  *(undefined ***)(this + 8) = &PTR__TType_a7b7d440;
  return;
}

/* TIntermAggregate__getAsAggregate @ 0x97c32538 (4 bytes) */
int TIntermAggregate__getAsAggregate()
{
  return;
}

/* TIntermAggregate__setOperator @ 0x97c3253c (8 bytes) */
int TIntermAggregate__setOperator(this, param_2)
  unsigned char * this;
  undefined4 param_2;
{
  *(undefined4 *)(this + 0x30) = param_2;
  return;
}

/* TIntermAggregate__getSequence @ 0x97c32544 (8 bytes) */
int TIntermAggregate__getSequence(this)
  unsigned char * this;
{
  return this + 0x34;
}

/* TIntermAggregate__setName @ 0x97c3254c (8 bytes) */
int TIntermAggregate__setName(param_1)
  unsigned char * param_1;
{
  std__string__assign(param_1 + 0x54);
  return;
}

/* TIntermAggregate__getName @ 0x97c32554 (8 bytes) */
int TIntermAggregate__getName(this)
  unsigned char * this;
{
  return this + 0x54;
}

/* TIntermAggregate__setUserDefined @ 0x97c3255c (12 bytes) */
int TIntermAggregate__setUserDefined(this)
  unsigned char * this;
{
  *(undefined4 *)(this + 0x5c) = 1;
  return;
}

/* TIntermAggregate__isUserDefined @ 0x97c32568 (8 bytes) */
int TIntermAggregate__isUserDefined(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 0x5c);
}

/* TIntermAggregate__getQualifier @ 0x97c32570 (8 bytes) */
int TIntermAggregate__getQualifier(this)
  unsigned char * this;
{
  return this + 0x44;
}

/* TIntermSelection__getCondition @ 0x97c32578 (8 bytes) */
int TIntermSelection__getCondition(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 0x30);
}

/* TIntermSelection__getTrueBlock @ 0x97c32580 (8 bytes) */
int TIntermSelection__getTrueBlock(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 0x34);
}

/* TIntermSelection__getFalseBlock @ 0x97c32588 (8 bytes) */
int TIntermSelection__getFalseBlock(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 0x38);
}

/* TIntermSelection__getAsSelectionNode @ 0x97c32590 (4 bytes) */
int TIntermSelection__getAsSelectionNode()
{
  return;
}

/* std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string_____clear @ 0x97c32594 (96 bytes) */
int std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string_____clear( unsigned char
        *this)

{
  if (*(int *)(this + 8) != 0) {
    ((int (*)())std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string______M_erase)((unsigned char *)this);
    *(int *)(*(int *)(this + 4) + 8) = *(int *)(this + 4);
    *(undefined4 *)(*(int *)(this + 4) + 4) = 0;
    *(int *)(*(int *)(this + 4) + 0xc) = *(int *)(this + 4);
    *(undefined4 *)(this + 8) = 0;
  }
  return;
}

/* TIntermBranch___TIntermBranch @ 0x97c325f4 (36 bytes) */
int TIntermBranch___TIntermBranch(this)
  unsigned char * this;
{
  *(undefined ***)this = &PTR_getLine_a7b7d400;
  return;
}

/* TIntermBranch___TIntermBranch_97c32618 @ 0x97c32618 (36 bytes) */
int TIntermBranch___TIntermBranch_97c32618(this)
  unsigned char * this;
{
  *(undefined ***)this = &PTR_getLine_a7b7d400;
  return;
}

/* TIntermLoop___TIntermLoop @ 0x97c3263c (36 bytes) */
int TIntermLoop___TIntermLoop(this)
  unsigned char * this;
{
  *(undefined ***)this = &PTR_getLine_a7b7d400;
  return;
}

/* TIntermLoop___TIntermLoop_97c32660 @ 0x97c32660 (36 bytes) */
int TIntermLoop___TIntermLoop_97c32660(this)
  unsigned char * this;
{
  *(undefined ***)this = &PTR_getLine_a7b7d400;
  return;
}

/* TIntermSelection___TIntermSelection @ 0x97c32684 (52 bytes) */
int TIntermSelection___TIntermSelection(this)
  unsigned char * this;
{
  *(undefined ***)this = &PTR_getLine_a7b7d400;
  *(undefined ***)(this + 8) = &PTR__TType_a7b7d440;
  return;
}

/* TIntermSelection___TIntermSelection_97c326b8 @ 0x97c326b8 (52 bytes) */
int TIntermSelection___TIntermSelection_97c326b8(this)
  unsigned char * this;
{
  *(undefined ***)this = &PTR_getLine_a7b7d400;
  *(undefined ***)(this + 8) = &PTR__TType_a7b7d440;
  return;
}

/* TIntermUnary___TIntermUnary @ 0x97c326ec (52 bytes) */
int TIntermUnary___TIntermUnary(this)
  unsigned char * this;
{
  *(undefined ***)this = &PTR_getLine_a7b7d400;
  *(undefined ***)(this + 8) = &PTR__TType_a7b7d440;
  return;
}

/* TIntermUnary___TIntermUnary_97c32720 @ 0x97c32720 (52 bytes) */
int TIntermUnary___TIntermUnary_97c32720(this)
  unsigned char * this;
{
  *(undefined ***)this = &PTR_getLine_a7b7d400;
  *(undefined ***)(this + 8) = &PTR__TType_a7b7d440;
  return;
}

/* TIntermBinary___TIntermBinary @ 0x97c32754 (52 bytes) */
int TIntermBinary___TIntermBinary(this)
  unsigned char * this;
{
  *(undefined ***)this = &PTR_getLine_a7b7d400;
  *(undefined ***)(this + 8) = &PTR__TType_a7b7d440;
  return;
}

/* TIntermBinary___TIntermBinary_97c32788 @ 0x97c32788 (52 bytes) */
int TIntermBinary___TIntermBinary_97c32788(this)
  unsigned char * this;
{
  *(undefined ***)this = &PTR_getLine_a7b7d400;
  *(undefined ***)(this + 8) = &PTR__TType_a7b7d440;
  return;
}

/* TIntermConstantUnion___TIntermConstantUnion @ 0x97c327bc (52 bytes) */
int TIntermConstantUnion___TIntermConstantUnion(this)
  unsigned char * this;
{
  *(undefined ***)this = &PTR_getLine_a7b7d400;
  *(undefined ***)(this + 8) = &PTR__TType_a7b7d440;
  return;
}

/* TIntermConstantUnion___TIntermConstantUnion_97c327f0 @ 0x97c327f0 (52 bytes) */
int TIntermConstantUnion___TIntermConstantUnion_97c327f0(this)
  unsigned char * this;
{
  *(undefined ***)this = &PTR_getLine_a7b7d400;
  *(undefined ***)(this + 8) = &PTR__TType_a7b7d440;
  return;
}

/* TIntermSymbol___TIntermSymbol @ 0x97c32824 (148 bytes) */
int TIntermSymbol___TIntermSymbol(this)
  unsigned char * this;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  char in_RESERVE;
  byte in_cr0;
  
  iVar4 = *(int *)(this + 0x38);
  *(undefined ***)this = &PTR_getLine_a7b7d390;
  piVar2 = (int *)(iVar4 + -4);
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar3 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(iVar4 + -0xc));
  }
  *(undefined ***)this = &PTR_getLine_a7b7d400;
  *(undefined ***)(this + 8) = &PTR__TType_a7b7d440;
  return;
}

