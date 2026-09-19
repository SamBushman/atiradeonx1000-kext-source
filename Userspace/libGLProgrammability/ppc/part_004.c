#include "decls.h"

/* TIntermConstantUnion__traverse @ 0x97b97d54 (20 bytes) */
int TIntermConstantUnion__traverse(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  if (*(code **)(param_1 + 4) == (code *)0x0) {
    return;
  }
                    
                    
  (**(code **)(param_1 + 4))();
  return;
}

/* TIntermBinary__traverse @ 0x97b97d68 (324 bytes) */
int TIntermBinary__traverse(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  int iVar1;
  int *piVar2;
  
  iVar1 = 1;
  if ((*(int *)(param_1 + 0x24) != 0) && (*(code **)(param_1 + 8) != (code *)0x0)) {
    iVar1 = (**(code **)(param_1 + 8))(1,this,param_1);
  }
  if (iVar1 != 0) {
    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
    if (*(int *)(param_1 + 0x2c) == 0) {
      piVar2 = *(int **)(this + 0x34);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2,param_1);
      }
      piVar2 = *(int **)(this + 0x38);
    }
    else {
      piVar2 = *(int **)(this + 0x38);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2,param_1);
      }
      piVar2 = *(int **)(this + 0x34);
    }
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2,param_1);
    }
    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + -1;
    if ((*(int *)(param_1 + 0x28) != 0) && (*(code **)(param_1 + 8) != (code *)0x0)) {
                    
                    
      (**(code **)(param_1 + 8))(0,this,param_1);
      return;
    }
  }
  return;
}

/* TIntermUnary__traverse @ 0x97b97eac (240 bytes) */
int TIntermUnary__traverse(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  int iVar1;
  
  if (((*(int *)(param_1 + 0x24) == 0) || (*(code **)(param_1 + 0xc) == (code *)0x0)) ||
     (iVar1 = (**(code **)(param_1 + 0xc))(1,this,param_1), iVar1 != 0)) {
    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
    (**(code **)(**(int **)(this + 0x34) + 8))(*(int **)(this + 0x34),param_1);
    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + -1;
    if ((*(int *)(param_1 + 0x28) != 0) && (*(code **)(param_1 + 0xc) != (code *)0x0)) {
                    
                    
      (**(code **)(param_1 + 0xc))(0,this,param_1);
      return;
    }
  }
  return;
}

/* TIntermAggregate__traverse @ 0x97b97f9c (292 bytes) */
int TIntermAggregate__traverse(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = 1;
  if ((*(int *)(param_1 + 0x24) != 0) && (*(code **)(param_1 + 0x14) != (code *)0x0)) {
    iVar1 = (**(code **)(param_1 + 0x14))(1,this,param_1);
  }
  if (iVar1 != 0) {
    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
    if (*(int *)(param_1 + 0x2c) == 0) {
      for (puVar2 = *(undefined4 **)(this + 0x38); puVar2 != *(undefined4 **)(this + 0x3c);
          puVar2 = puVar2 + 1) {
        (**(code **)(*(int *)*puVar2 + 8))((int *)*puVar2,param_1);
      }
    }
    else {
      puVar2 = *(undefined4 **)(this + 0x3c);
      while (puVar2 != *(undefined4 **)(this + 0x38)) {
        puVar2 = puVar2 + -1;
        (**(code **)(*(int *)*puVar2 + 8))((int *)*puVar2,param_1);
      }
    }
    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + -1;
    if ((*(int *)(param_1 + 0x28) != 0) && (*(code **)(param_1 + 0x14) != (code *)0x0)) {
      (**(code **)(param_1 + 0x14))(0,this,param_1);
    }
  }
  return;
}

/* TIntermSelection__traverse @ 0x97b980c0 (388 bytes) */
int TIntermSelection__traverse(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  int iVar1;
  int *piVar2;
  
  iVar1 = 1;
  if ((*(int *)(param_1 + 0x24) != 0) && (*(code **)(param_1 + 0x10) != (code *)0x0)) {
    iVar1 = (**(code **)(param_1 + 0x10))(1,this,param_1);
  }
  if (iVar1 == 0) {
    return;
  }
  *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
  if (*(int *)(param_1 + 0x2c) == 0) {
    (**(code **)(**(int **)(this + 0x30) + 8))(*(int **)(this + 0x30),param_1);
    piVar2 = *(int **)(this + 0x34);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2,param_1);
    }
    piVar2 = *(int **)(this + 0x38);
    if (piVar2 == (int *)0x0) goto LAB_97b981d4;
    iVar1 = *piVar2;
  }
  else {
    piVar2 = *(int **)(this + 0x38);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2,param_1);
    }
    piVar2 = *(int **)(this + 0x34);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2,param_1);
    }
    piVar2 = *(int **)(this + 0x30);
    iVar1 = *piVar2;
  }
  (**(code **)(iVar1 + 8))(piVar2,param_1);
LAB_97b981d4:
  *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + -1;
  if ((*(int *)(param_1 + 0x28) != 0) && (*(code **)(param_1 + 0x10) != (code *)0x0)) {
                    
                    
    (**(code **)(param_1 + 0x10))(0,this,param_1);
    return;
  }
  return;
}

/* TIntermLoop__traverse @ 0x97b98244 (388 bytes) */
int TIntermLoop__traverse(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  int iVar1;
  int *piVar2;
  
  iVar1 = 1;
  if ((*(int *)(param_1 + 0x24) != 0) && (*(code **)(param_1 + 0x18) != (code *)0x0)) {
    iVar1 = (**(code **)(param_1 + 0x18))(1,this,param_1);
  }
  if (iVar1 != 0) {
    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
    if (*(int *)(param_1 + 0x2c) == 0) {
      piVar2 = *(int **)(this + 0xc);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2,param_1);
      }
      piVar2 = *(int **)(this + 8);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2,param_1);
      }
      piVar2 = *(int **)(this + 0x10);
    }
    else {
      piVar2 = *(int **)(this + 0x10);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2,param_1);
      }
      piVar2 = *(int **)(this + 8);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2,param_1);
      }
      piVar2 = *(int **)(this + 0xc);
    }
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2,param_1);
    }
    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + -1;
    if ((*(int *)(param_1 + 0x28) != 0) && (*(code **)(param_1 + 0x18) != (code *)0x0)) {
                    
                    
      (**(code **)(param_1 + 0x18))(0,this,param_1);
      return;
    }
  }
  return;
}

/* TIntermBranch__traverse @ 0x97b983c8 (216 bytes) */
int TIntermBranch__traverse(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  int iVar1;
  
  iVar1 = 1;
  if ((*(int *)(param_1 + 0x24) != 0) && (*(code **)(param_1 + 0x1c) != (code *)0x0)) {
    iVar1 = (**(code **)(param_1 + 0x1c))(1,this,param_1);
  }
  if (iVar1 != 0) {
    if (*(int *)(this + 0xc) != 0) {
      *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
      (**(code **)(**(int **)(this + 0xc) + 8))(*(int **)(this + 0xc),param_1);
      *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + -1;
    }
    if ((*(int *)(param_1 + 0x28) != 0) && (*(code **)(param_1 + 0x1c) != (code *)0x0)) {
                    
                    
      (**(code **)(param_1 + 0x1c))(0,this,param_1);
      return;
    }
  }
  return;
}

/* ParseSymbol @ 0x97b984a0 (1480 bytes) */
int ParseSymbol(param_1, param_2)
  unsigned char *param_1;
  unsigned char *param_2;
{
  bool bVar1;
  int *piVar2;
  ulong uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  char in_RESERVE;
  byte in_cr0;
  double dVar14;
  undefined **local_1b0;
  int local_1ac;
  uint local_18c;
  char acStack_180 [208];
  undefined **local_b0;
  int local_60 [2];
  longlong local_58;
  undefined4 local_50;
  uint uStack_4c;
  
  (**(code **)(*(int *)param_1 + 0x38))(&local_1b0,param_1);
  uVar6 = *(uint *)(param_2 + 0x60);
  local_1b0 = &PTR__TType_a7b7d488;
  iVar9 = *(int *)(param_2 + 0x34);
  if ((uVar6 >> 0x13 & 0x3f) == 0xe) {
    iVar10 = *(int *)(param_2 + 0x54);
  }
  else {
    bVar1 = (uVar6 & 0x400) == 0;
    in_cr0 = bVar1 << 1;
    if (bVar1) {
      iVar10 = (int)(uVar6 << 0xd | uVar6 >> 0x13) >> 0x18;
    }
    else {
      iVar10 = (int)(uVar6 << 0xd | uVar6 >> 0x13) >> 0x18;
      iVar10 = iVar10 * iVar10;
    }
  }
  if (*(int *)(param_2 + 0x30) < iVar10) {
    if (local_18c >> 0x19 != 2) {
      TType__getCompleteString();
      *(undefined1 *)(local_1ac + *(int *)(local_1ac + -0xc)) = *DAT_a7b7ba10;
      _sprintf(acStack_180,"\'constructor\' : assigning non-constant to %s",local_1ac);
      piVar2 = (int *)(local_1ac + -4);
      local_b0 = local_1b0;
      do {
        iVar9 = *piVar2;
        if (in_RESERVE != '\0') {
          iVar10 = storeWordConditionalIndexed(iVar9 + -1,0,piVar2);
          *piVar2 = iVar10;
          in_cr0 = 2;
        }
      } while (!(bool)(in_cr0 >> 1 & 1));
      if (iVar9 < 1) {
        std__string___Rep___M_destroy((unsigned char *)(local_1ac + -0xc));
      }
      (*(code *)**(undefined4 **)param_1)(param_1);
                    
                    
      (*(code *)(((unsigned char *)0x97b985ec) + (*(unsigned char *)0x97b985f4)))();
      return;
    }
    piVar2 = *(int **)(param_2 + 0x70);
    (**(code **)(*(int *)param_1 + 0x60))(param_1);
    iVar7 = *piVar2;
    iVar13 = (piVar2[1] - iVar7 >> 2) + -1;
    while( true ) {
      iVar12 = *(int *)(iVar7 + iVar13 * 4);
      iVar7 = 0;
      std::
      _Rb_tree<std::string,std::pair<std::string_const,TSymbol*>,std::_Select1st<std::pair<std::string_const,TSymbol*>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,TSymbol*>>>
      ::find((unsigned char *)local_60);
      if (local_60[0] != *(int *)(iVar12 + 4)) {
        iVar7 = *(int *)(local_60[0] + 0x18);
      }
      iVar13 = iVar13 + -1;
      if ((iVar7 != 0) || (iVar13 < 0)) break;
      iVar7 = *piVar2;
    }
    iVar13 = *(int *)(iVar7 + 0x38);
    if (iVar13 == 0) {
      uVar3 = ((int (*)())GetGlobalPoolAllocator)();
      iVar13 = TPoolAllocator__allocate(uVar3);
      *(int *)(iVar7 + 0x38) = iVar13;
    }
    if (iVar13 == 0) {
      iVar9 = (**(code **)(*(int *)param_1 + 0x60))(param_1);
      *(undefined1 *)(*(int *)(iVar9 + 4) + *(int *)(*(int *)(iVar9 + 4) + -0xc)) = *DAT_a7b7ba10;
      _sprintf((char *)&local_1b0,
               "\'constructor\' : constant \'%s\' has not been initialized correctly",
               *(undefined4 *)(iVar9 + 4));
      (*(code *)**(undefined4 **)param_1)(param_1);
                    
                    
      (*(code *)(((unsigned char *)0x97b9885c) + (*(unsigned char *)0x97b98864)))();
      return;
    }
    iVar8 = iVar7 + 0xc;
    iVar12 = (**(code **)(*(int *)(iVar7 + 0xc) + 0x20))(iVar8);
    if (iVar12 == 0xe) {
      iVar12 = *(int *)(iVar7 + 0x24);
    }
    else {
      iVar12 = (**(code **)(*(int *)(iVar7 + 0xc) + 0x30))(iVar8);
    }
    iVar11 = 0;
    if (0 < iVar12) {
      do {
        if (iVar10 <= *(int *)(param_2 + 0x30)) {
          return;
        }
        uVar4 = (**(code **)(*(int *)(iVar7 + 0xc) + 0x20))(iVar8);
        uVar6 = *(uint *)(param_2 + 0x60) >> 0x13 & 0x3f;
        if ((uVar4 == uVar6) || (uVar6 == 0xe)) {
LAB_97b98c14:
          *(undefined4 *)(iVar9 + *(int *)(param_2 + 0x30) * 4) =
               *(undefined4 *)(iVar11 * 4 + iVar13);
        }
        else {
          iVar5 = (**(code **)(*(int *)(iVar7 + 0xc) + 0x20))(iVar8);
          if (iVar5 == 2) {
            uVar6 = *(uint *)(param_2 + 0x60) >> 0x13 & 0x3f;
            if (uVar6 == 1) {
              uStack_4c = *(uint *)(iVar11 * 4 + iVar13) ^ 0x80000000;
              dVar14 = DOUBLE_97c30a58;
LAB_97b98bfc:
              local_50 = 0x43300000;
              *(float *)(iVar9 + *(int *)(param_2 + 0x30) * 4) =
                   (float)((double)CONCAT44(0x43300000,uStack_4c) - dVar14);
            }
            else {
              if (uVar6 != 3) {
                (*(code *)**(undefined4 **)param_1)(param_1);
                    
                    
                (*(code *)(((unsigned char *)0x97b98ba8) + (*(unsigned char *)0x97b98bb4)))();
                return;
              }
              *(uint *)(iVar9 + *(int *)(param_2 + 0x30) * 4) =
                   (uint)(*(int *)(iVar11 * 4 + iVar13) != 0);
            }
          }
          else {
            if (2 < iVar5) {
              if (iVar5 != 3) goto LAB_97b98c80;
              uVar6 = *(uint *)(param_2 + 0x60) >> 0x13 & 0x3f;
              if (uVar6 == 1) {
                uStack_4c = *(uint *)(iVar11 * 4 + iVar13);
                dVar14 = DOUBLE_97c30a68;
                goto LAB_97b98bfc;
              }
              if (uVar6 != 2) {
                (*(code *)**(undefined4 **)param_1)(param_1);
                    
                    
                (*(code *)(((unsigned char *)0x97b98c68) + (*(unsigned char *)0x97b98c74)))();
                return;
              }
              goto LAB_97b98c14;
            }
            if (iVar5 != 1) {
LAB_97b98c80:
              (*(code *)**(undefined4 **)param_1)(param_1);
                    
                    
              (*(code *)(((unsigned char *)0x97b98cbc) + (*(unsigned char *)0x97b98cc8)))();
              return;
            }
            uVar6 = *(uint *)(param_2 + 0x60) >> 0x13 & 0x3f;
            if (uVar6 == 2) {
              iVar5 = (int)*(float *)(iVar11 * 4 + iVar13);
              local_58 = (longlong)iVar5;
              *(int *)(*(int *)(param_2 + 0x30) * 4 + iVar9) = iVar5;
            }
            else {
              if (uVar6 != 3) {
                (*(code *)**(undefined4 **)param_1)(param_1);
                    
                    
                (*(code *)(((unsigned char *)0x97b98af0) + (*(unsigned char *)0x97b98afc)))();
                return;
              }
              *(uint *)(*(int *)(param_2 + 0x30) * 4 + iVar9) =
                   (uint)((double)*(float *)(iVar11 * 4 + iVar13) != DOUBLE_97c30a48);
            }
          }
        }
        iVar11 = iVar11 + 1;
        *(int *)(param_2 + 0x30) = *(int *)(param_2 + 0x30) + 1;
      } while (iVar11 < iVar12);
    }
  }
  return;
}

/* ParseBinary @ 0x97b98e04 (308 bytes) */
int ParseBinary(param_1, param_2, param_3)
  int param_1;
  unsigned char *param_2;
  unsigned char *param_3;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  char in_RESERVE;
  byte in_cr0;
  undefined **local_170;
  int local_16c;
  uint local_14c;
  char acStack_140 [208];
  undefined **local_70;
  
  (**(code **)(*(int *)param_2 + 0x38))(&local_170);
  local_170 = &PTR__TType_a7b7d488;
  if (local_14c >> 0x19 != 2) {
    TType__getCompleteString();
    *(undefined1 *)(local_16c + *(int *)(local_16c + -0xc)) = *DAT_a7b7ba10;
    _sprintf(acStack_140,"\'constructor\' : assigning non-constant to %s",local_16c);
    piVar2 = (int *)(local_16c + -4);
    local_70 = local_170;
    do {
      iVar3 = *piVar2;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
        *piVar2 = iVar1;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar3 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_16c + -0xc));
    }
    (*(code *)**(undefined4 **)param_2)(param_2);
                    
                    
    (*(code *)(((unsigned char *)0x97b98efc) + (*(unsigned char *)0x97b98f04)))();
    return;
  }
  (*(code *)**(undefined4 **)param_2)(param_2);
                    
                    
  (*(code *)(((unsigned char *)0x97b99064) + (*(unsigned char *)0x97b99070)))();
  return;
}

/* ParseUnary @ 0x97b99198 (196 bytes) */
int ParseUnary(param_1, param_2, param_3)
  int param_1;
  unsigned char *param_2;
  unsigned char *param_3;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  char in_RESERVE;
  byte in_cr0;
  char acStack_160 [208];
  undefined4 local_90;
  int local_8c;
  undefined4 local_80;
  
  TType__getCompleteString();
  *(undefined1 *)(local_8c + *(int *)(local_8c + -0xc)) = *DAT_a7b7ba10;
  _sprintf(acStack_160,"\'constructor\' : assigning non-constant to \'%s\'",local_8c);
  piVar2 = (int *)(local_8c + -4);
  local_80 = local_90;
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar3 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(local_8c + -0xc));
  }
  (*(code *)**(undefined4 **)param_2)(param_2);
                    
                    
  (*(code *)(((unsigned char *)0x97b9925c) + (*(unsigned char *)0x97b99264)))();
  return;
}

/* ParseAggregate @ 0x97b99398 (884 bytes) */
int ParseAggregate(param_1, param_2, param_3)
  int param_1;
  unsigned char *param_2;
  unsigned char *param_3;
{
  int iVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  char in_RESERVE;
  byte in_cr0;
  undefined **local_160 [9];
  uint local_13c;
  undefined **local_130 [6];
  undefined4 local_118;
  uint local_10c;
  undefined4 local_90;
  int local_8c;
  undefined4 local_80;
  
  iVar4 = TIntermOperator__isConstructor();
  if ((iVar4 == 0) && (*(int *)(param_2 + 0x30) != 0x25)) {
    TType__getCompleteString();
    *(undefined1 *)(local_8c + *(int *)(local_8c + -0xc)) = *DAT_a7b7ba10;
    _sprintf((char *)local_160,"\'constructor\' : assigning non-constant to \'%s\'",local_8c);
    piVar3 = (int *)(local_8c + -4);
    local_80 = local_90;
    do {
      iVar4 = *piVar3;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
        *piVar3 = iVar1;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar4 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_8c + -0xc));
    }
    (*(code *)**(undefined4 **)param_2)(param_2);
                    
                    
    uVar5 = (*(code *)(((unsigned char *)0x97b99480) + (*(unsigned char *)0x97b99488)))();
    return uVar5;
  }
  iVar4 = (**(code **)(*(int *)param_2 + 100))(param_2);
  if ((uint)(*(int *)(iVar4 + 8) - *(int *)(iVar4 + 4)) >> 2 == 0) {
    *(undefined4 *)(param_3 + 0x74) = 1;
  }
  else {
    bVar2 = false;
    iVar4 = (**(code **)(*(int *)param_2 + 100))(param_2);
    if (*(int *)(iVar4 + 8) - *(int *)(iVar4 + 4) >> 2 == 1) {
      iVar4 = (**(code **)(*(int *)param_2 + 100))(param_2);
      piVar3 = (int *)(**(code **)(*(int *)**(undefined4 **)(iVar4 + 4) + 0x14))();
      iVar4 = (**(code **)(*piVar3 + 0x18))();
      if (iVar4 != 0) {
        bVar2 = true;
      }
    }
    if (bVar2) {
      *(undefined4 *)(param_3 + 0x68) = 1;
      *(undefined4 *)(param_3 + 100) = *(undefined4 *)(param_2 + 0x30);
      (**(code **)(*(int *)param_2 + 0x38))(local_160,param_2);
      local_160[0] = &PTR__TType_a7b7d488;
      if ((local_13c >> 0x13 & 0x3f) == 0xe) {
        (**(code **)(*(int *)param_2 + 0x38))(local_130,param_2);
        *(undefined4 *)(param_3 + 0x78) = local_118;
      }
      else {
        (**(code **)(*(int *)param_2 + 0x38))(local_130,param_2);
        if ((local_10c & 0x400) == 0) {
          iVar4 = (int)(local_10c << 0xd | local_10c >> 0x13) >> 0x18;
        }
        else {
          iVar4 = (int)(local_10c << 0xd | local_10c >> 0x13) >> 0x18;
          iVar4 = iVar4 * iVar4;
        }
        *(int *)(param_3 + 0x78) = iVar4;
      }
      local_130[0] = &PTR__TType_a7b7d488;
      (**(code **)(*(int *)param_2 + 0x38))(local_160,param_2);
      local_160[0] = &PTR__TType_a7b7d488;
      if ((local_13c & 0x400) != 0) {
        *(undefined4 *)(param_3 + 0x7c) = 1;
        (**(code **)(*(int *)param_2 + 0x38))(local_130,param_2);
        local_130[0] = &PTR__TType_a7b7d488;
        *(int *)(param_3 + 0x80) = (int)(local_10c << 0xd | local_10c >> 0x13) >> 0x18;
      }
    }
    iVar4 = (**(code **)(*(int *)param_2 + 100))(param_2);
    puVar6 = *(undefined4 **)(iVar4 + 4);
    while( true ) {
      iVar4 = (**(code **)(*(int *)param_2 + 100))(param_2);
      if (puVar6 == *(undefined4 **)(iVar4 + 8)) break;
      if (*(int *)(param_2 + 0x30) == 0x25) {
        *(undefined4 *)(param_3 + 0x30) = 0;
      }
      piVar3 = (int *)*puVar6;
      puVar6 = puVar6 + 1;
      (**(code **)(*piVar3 + 8))(piVar3,param_3);
    }
    if (bVar2) {
      *(undefined4 *)(param_3 + 0x80) = 0;
      *(undefined4 *)(param_3 + 0x68) = 0;
      *(undefined4 *)(param_3 + 100) = 0;
      *(undefined4 *)(param_3 + 0x78) = 0;
      *(undefined4 *)(param_3 + 0x7c) = 0;
    }
  }
  return 0;
}

/* ParseSelection @ 0x97b9982c (88 bytes) */
int ParseSelection(param_1, param_2, param_3)
  int param_1;
  unsigned char *param_2;
  unsigned char *param_3;
{
  (*(code *)**(undefined4 **)param_2)(param_2);
                    
                    
  (*(code *)(((unsigned char *)0x97b99884) + (*(unsigned char *)0x97b99890)))();
  return;
}

/* ParseConstantUnion @ 0x97b999c0 (1160 bytes) */
int ParseConstantUnion(param_1, param_2)
  unsigned char *param_1;
  unsigned char *param_2;
{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  undefined4 *puVar14;
  undefined **local_130 [9];
  uint local_10c;
  undefined **local_100 [6];
  int local_e8;
  uint local_dc;
  undefined **local_d0 [6];
  int local_b8;
  uint local_ac;
  undefined **local_a0 [9];
  uint local_7c;
  undefined **local_70 [9];
  uint local_4c;
  
  uVar6 = *(uint *)(param_2 + 0x60);
  iVar12 = *(int *)(param_2 + 0x34);
  if ((uVar6 >> 0x13 & 0x3f) == 0xe) {
    iVar11 = *(int *)(param_2 + 0x54);
  }
  else if ((uVar6 & 0x400) == 0) {
    iVar11 = (int)(uVar6 << 0xd | uVar6 >> 0x13) >> 0x18;
  }
  else {
    iVar11 = (int)(uVar6 << 0xd | uVar6 >> 0x13) >> 0x18;
    iVar11 = iVar11 * iVar11;
  }
  iVar13 = *(int *)(param_2 + 0x30);
  if (iVar13 < iVar11) {
    if (*(int *)(param_2 + 0x68) == 0) {
      (**(code **)(*(int *)param_1 + 0x38))(local_130,param_1);
      local_130[0] = &PTR__TType_a7b7d488;
      if ((local_10c >> 0x13 & 0x3f) == 0xe) {
        (**(code **)(*(int *)param_1 + 0x38))(local_100,param_1);
      }
      else {
        (**(code **)(*(int *)param_1 + 0x38))(local_100,param_1);
        if ((local_dc & 0x400) == 0) {
          local_e8 = (int)(local_dc << 0xd | local_dc >> 0x13) >> 0x18;
        }
        else {
          local_e8 = (int)(local_dc << 0xd | local_dc >> 0x13) >> 0x18;
          local_e8 = local_e8 * local_e8;
        }
      }
      iVar13 = 0;
      puVar7 = *(undefined4 **)(param_1 + 0x30);
      if (0 < local_e8) {
        do {
          if (iVar11 <= *(int *)(param_2 + 0x30)) {
            return;
          }
          uVar8 = *puVar7;
          iVar13 = iVar13 + 1;
          puVar7 = puVar7 + 1;
          *(undefined4 *)(iVar12 + *(int *)(param_2 + 0x30) * 4) = uVar8;
          *(int *)(param_2 + 0x30) = *(int *)(param_2 + 0x30) + 1;
        } while (iVar13 < local_e8);
      }
    }
    else {
      iVar9 = *(int *)(param_2 + 0x80);
      iVar10 = iVar13 + *(int *)(param_2 + 0x78);
      puVar7 = *(undefined4 **)(param_1 + 0x30);
      if (*(int *)(param_2 + 0x7c) == 0) {
        if (iVar13 < iVar10) {
          puVar14 = (undefined4 *)(iVar13 * 4 + iVar12);
          do {
            if (iVar11 <= iVar13) {
              return;
            }
            bVar4 = false;
            *puVar14 = *puVar7;
            bVar3 = false;
            puVar14 = puVar14 + 1;
            bVar2 = false;
            bVar1 = false;
            *(int *)(param_2 + 0x30) = *(int *)(param_2 + 0x30) + 1;
            (**(code **)(*(int *)param_1 + 0x38))(local_130,param_1);
            if ((local_10c >> 0x13 & 0x3f) == 0xe) {
              bVar3 = true;
              (**(code **)(*(int *)param_1 + 0x38))(local_d0,param_1);
              if (local_b8 < 2) goto LAB_97b99bf0;
LAB_97b99c64:
              bVar4 = true;
              if (bVar1) {
LAB_97b99c70:
                local_70[0] = &PTR__TType_a7b7d488;
              }
            }
            else {
LAB_97b99bf0:
              bVar2 = true;
              (**(code **)(*(int *)param_1 + 0x38))(local_a0,param_1);
              if ((local_7c >> 0x13 & 0x3f) != 0xe) {
                bVar1 = true;
                (**(code **)(*(int *)param_1 + 0x38))(local_70,param_1);
                if ((local_4c & 0x400) == 0) {
                  iVar12 = (int)(local_4c << 0xd | local_4c >> 0x13) >> 0x18;
                }
                else {
                  iVar12 = (int)(local_4c << 0xd | local_4c >> 0x13) >> 0x18;
                  iVar12 = iVar12 * iVar12;
                }
                if (1 < iVar12) goto LAB_97b99c64;
                goto LAB_97b99c70;
              }
            }
            if (bVar2) {
              local_a0[0] = &PTR__TType_a7b7d488;
            }
            if (bVar3) {
              local_d0[0] = &PTR__TType_a7b7d488;
            }
            local_130[0] = &PTR__TType_a7b7d488;
            if (bVar4) {
              puVar7 = puVar7 + 1;
            }
            iVar13 = iVar13 + 1;
          } while (iVar13 < iVar10);
        }
      }
      else if (iVar13 < iVar10) {
        puVar14 = (undefined4 *)(iVar13 * 4 + iVar12);
        iVar12 = iVar13;
        do {
          if (iVar11 <= iVar12) {
            return;
          }
          if ((iVar13 == iVar12) ||
             (iVar12 - iVar13 == ((iVar12 - iVar13) / (iVar9 + 1)) * (iVar9 + 1))) {
            *puVar14 = *puVar7;
          }
          else {
            *puVar14 = 0;
          }
          bVar4 = false;
          bVar3 = false;
          *(int *)(param_2 + 0x30) = *(int *)(param_2 + 0x30) + 1;
          bVar2 = false;
          bVar1 = false;
          (**(code **)(*(int *)param_1 + 0x38))(local_130,param_1);
          if ((local_10c >> 0x13 & 0x3f) == 0xe) {
            bVar3 = true;
            (**(code **)(*(int *)param_1 + 0x38))(local_100,param_1);
            if (local_e8 < 2) goto LAB_97b99d78;
LAB_97b99dec:
            bVar4 = true;
            if (bVar1) {
LAB_97b99df8:
              local_a0[0] = &PTR__TType_a7b7d488;
            }
          }
          else {
LAB_97b99d78:
            bVar2 = true;
            (**(code **)(*(int *)param_1 + 0x38))(local_d0,param_1);
            if ((local_ac >> 0x13 & 0x3f) != 0xe) {
              bVar1 = true;
              (**(code **)(*(int *)param_1 + 0x38))(local_a0,param_1);
              if ((local_7c & 0x400) == 0) {
                iVar5 = (int)(local_7c << 0xd | local_7c >> 0x13) >> 0x18;
              }
              else {
                iVar5 = (int)(local_7c << 0xd | local_7c >> 0x13) >> 0x18;
                iVar5 = iVar5 * iVar5;
              }
              if (1 < iVar5) goto LAB_97b99dec;
              goto LAB_97b99df8;
            }
          }
          if (bVar2) {
            local_d0[0] = &PTR__TType_a7b7d488;
          }
          if (bVar3) {
            local_100[0] = &PTR__TType_a7b7d488;
          }
          local_130[0] = &PTR__TType_a7b7d488;
          if (bVar4) {
            puVar7 = puVar7 + 1;
          }
          iVar12 = iVar12 + 1;
          puVar14 = puVar14 + 1;
        } while (iVar12 < iVar10);
      }
    }
  }
  return;
}

/* ParseLoop @ 0x97b99e48 (88 bytes) */
int ParseLoop(param_1, param_2, param_3)
  int param_1;
  unsigned char *param_2;
  unsigned char *param_3;
{
  (*(code *)**(undefined4 **)param_2)(param_2);
                    
                    
  (*(code *)(((unsigned char *)0x97b99ea0) + (*(unsigned char *)0x97b99eac)))();
  return;
}

/* ParseBranch @ 0x97b99fdc (88 bytes) */
int ParseBranch(param_1, param_2, param_3)
  int param_1;
  unsigned char *param_2;
  unsigned char *param_3;
{
  (*(code *)**(undefined4 **)param_2)(param_2);
                    
                    
  (*(code *)(((unsigned char *)0x97b9a034) + (*(unsigned char *)0x97b9a040)))();
  return;
}

/* TIntermediate__parseConstTree @ 0x97b9a170 (428 bytes) */
int TIntermediate__parseConstTree(this, param_2_00, param_2, param_3, param_5, param_6, param_7, param_8)
  unsigned char *this;
  undefined4 param_2_00;
  int *param_2;
  undefined4 param_3;
  undefined4 param_5;
  undefined4 param_6;
  int param_7;
  undefined4 param_8;
{
  undefined4 uVar1;
  uint uVar2;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined **local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  uint local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  int local_3c;
  undefined4 local_34;
  undefined4 local_30;
  
  uVar1 = 0;
  if (param_2 != (int *)0x0) {
    uVar2 = *(uint *)(param_7 + 0x24);
    local_44 = *(undefined4 *)this;
    local_6c = *(undefined4 *)(param_7 + 8);
    local_68 = *(undefined4 *)(param_7 + 0xc);
    local_64 = *(undefined4 *)(param_7 + 0x10);
    local_70 = *(undefined4 *)(param_7 + 4);
    local_60 = *(undefined4 *)(param_7 + 0x14);
    local_50 = (uVar2 >> 9 & 1) << 9 |
               (uVar2 >> 10 & 1) << 10 |
               uVar2 & 0x7f800 |
               (uVar2 >> 0x13 & 0x3f) << 0x13 | uVar2 & 0xfe000000 | local_50 & 0x1ff;
    local_5c = *(undefined4 *)(param_7 + 0x18);
    local_58 = *(undefined4 *)(param_7 + 0x1c);
    local_54 = *(undefined4 *)(param_7 + 0x20);
    local_8c = 1;
    local_90 = 0;
    local_88 = 0;
    local_84 = 0;
    local_3c = 0;
    local_34 = 0;
    local_30 = 0;
    local_74 = &PTR__TType_a7b7d488;
    local_80 = 0;
    local_78 = 0;
    local_9c = DAT_a7b7ba0c;
    local_a8 = DAT_a7b7ba08;
    local_ac = DAT_a7b7ba04;
    local_a0 = DAT_a7b7ba00;
    local_b0 = DAT_a7b7b9fc;
    local_a4 = DAT_a7b7b9f8;
    local_98 = DAT_a7b7b9f4;
    local_94 = DAT_a7b7b9f0;
    local_7c = param_3;
    local_4c = param_5;
    local_48 = param_8;
    local_40 = param_6;
    (**(code **)(*param_2 + 8))(param_2,&local_b0);
    if (local_3c == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  return uVar1;
}

/* TParseContext__parseVectorFields @ 0x97b9a31c (612 bytes) */
int TParseContext__parseVectorFields(this, param_1, param_2, param_3, param_4)
  unsigned char *this;
  unsigned char *param_1;
  int param_2;
  unsigned char *param_3;
  int param_4;
{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  char *pcVar7;
  int *piVar8;
  int local_24 [8];
  
  iVar2 = *(int *)(*(int *)(param_1 + 4) + -0xc);
  *(int *)(param_3 + 0x10) = iVar2;
  if (iVar2 < 5) {
    iVar3 = 0;
    if (iVar2 < 1) {
      iVar2 = *(int *)(param_3 + 0x10);
    }
    else {
      do {
        iVar2 = *(int *)(param_1 + 4);
        switch(*(char *)(iVar2 + iVar3) + -0x61) {
        case '\0':
          iVar2 = 1;
          break;
        case '\x01':
          iVar2 = 1;
          goto LAB_97b9a4dc;
        default:
          iVar3 = *(int *)(iVar2 + -0xc);
          goto LAB_97b9a54c;
        case '\x06':
          iVar2 = 1;
          goto LAB_97b9a4f0;
        case '\x0f':
          iVar2 = 2;
          goto LAB_97b9a4f0;
        case '\x10':
          iVar2 = 2;
          break;
        case '\x11':
          iVar2 = 1;
          goto LAB_97b9a490;
        case '\x12':
          iVar2 = 2;
LAB_97b9a490:
          uVar5 = 0;
          goto LAB_97b9a528;
        case '\x13':
          iVar2 = 2;
          goto LAB_97b9a4bc;
        case '\x16':
          iVar2 = 0;
          break;
        case '\x17':
          iVar2 = 0;
LAB_97b9a4f0:
          local_24[iVar3 + 1] = iVar2;
          *(int *)(param_3 + iVar3 * 4) = iVar2;
          goto LAB_97b9a570;
        case '\x18':
          iVar2 = 0;
LAB_97b9a4bc:
          uVar5 = 1;
          goto LAB_97b9a528;
        case '\x19':
          iVar2 = 0;
LAB_97b9a4dc:
          uVar5 = 2;
          goto LAB_97b9a528;
        }
        uVar5 = 3;
LAB_97b9a528:
        local_24[iVar3 + 1] = iVar2;
        *(undefined4 *)(param_3 + iVar3 * 4) = uVar5;
LAB_97b9a570:
        iVar2 = *(int *)(param_3 + 0x10);
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar2);
    }
    iVar3 = 0;
    if (0 < iVar2) {
      piVar8 = local_24;
      do {
        iVar4 = *(int *)param_3;
        param_3 = param_3 + 4;
        if (param_2 <= iVar4) {
          iVar3 = *(int *)(param_1 + 4);
          iVar2 = *(int *)(iVar3 + -0xc);
          uVar1 = *DAT_a7b7ba18;
          pcVar6 = "vector field selection out of range";
LAB_97b9a3b8:
          *(undefined1 *)(iVar3 + iVar2) = uVar1;
          pcVar7 = *(char **)(param_1 + 4);
          goto LAB_97b9a560;
        }
        if ((0 < iVar3) && (piVar8[1] != *piVar8)) {
          iVar3 = *(int *)(param_1 + 4);
          iVar2 = *(int *)(iVar3 + -0xc);
          uVar1 = *DAT_a7b7ba18;
          pcVar6 = "illegal - vector component fields not from the same set";
          goto LAB_97b9a3b8;
        }
        iVar3 = iVar3 + 1;
        piVar8 = piVar8 + 1;
      } while (iVar3 < iVar2);
    }
    uVar5 = 1;
  }
  else {
    iVar2 = *(int *)(param_1 + 4);
    iVar3 = *(int *)(iVar2 + -0xc);
LAB_97b9a54c:
    *(undefined1 *)(iVar2 + iVar3) = *DAT_a7b7ba18;
    pcVar7 = *(char **)(param_1 + 4);
    pcVar6 = "illegal vector field selection";
LAB_97b9a560:
    error((int)this,(char *)param_4,pcVar6,pcVar7,"");
    uVar5 = 0;
  }
  return uVar5;
}

/* TParseContext__parseMatrixFields @ 0x97b9a5e8 (464 bytes) */
int TParseContext__parseMatrixFields(this, param_1, param_2, param_3, param_4)
  unsigned char *this;
  unsigned char *param_1;
  int param_2;
  unsigned char *param_3;
  int param_4;
{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  
  *(undefined4 *)(param_3 + 4) = 0;
  *(undefined4 *)(param_3 + 0xc) = 0xffffffff;
  *(undefined4 *)param_3 = 0;
  *(undefined4 *)(param_3 + 8) = 0xffffffff;
  pcVar4 = *(char **)(param_1 + 4);
  if (*(int *)(pcVar4 + -0xc) == 2) {
    iVar2 = (int)*pcVar4;
    if (iVar2 == 0x5f) {
      if (('/' < pcVar4[1]) && (pcVar4[1] < '4')) {
        *(undefined4 *)(param_3 + 4) = 1;
LAB_97b9a738:
        *(int *)(param_3 + 0xc) = *(char *)(*(int *)(param_1 + 4) + 1) + -0x30;
LAB_97b9a74c:
        if ((*(int *)(param_3 + 8) < param_2) && (*(int *)(param_3 + 0xc) < param_2)) {
          return 1;
        }
        pcVar3 = "matrix field selection out of range";
        *(char *)(*(int *)(param_1 + 4) + *(int *)(*(int *)(param_1 + 4) + -0xc)) = *DAT_a7b7ba18;
        goto LAB_97b9a790;
      }
LAB_97b9a6a4:
      pcVar4[2] = *DAT_a7b7ba18;
    }
    else {
      cVar1 = pcVar4[1];
      if (cVar1 == '_') {
        if ((0x2f < iVar2) && (iVar2 < 0x34)) {
          *(undefined4 *)param_3 = 1;
          *(int *)(param_3 + 8) = **(char **)(param_1 + 4) + -0x30;
          goto LAB_97b9a74c;
        }
        goto LAB_97b9a6a4;
      }
      if ((((0x2f < iVar2) && (iVar2 < 0x34)) && ('/' < cVar1)) && (cVar1 < '4')) {
        *(int *)(param_3 + 8) = iVar2 + -0x30;
        goto LAB_97b9a738;
      }
      pcVar4[*(int *)(pcVar4 + -0xc)] = *DAT_a7b7ba18;
    }
    pcVar4 = *(char **)(param_1 + 4);
    pcVar3 = "illegal matrix field selection";
  }
  else {
    pcVar3 = "illegal length of matrix field selection";
    pcVar4[*(int *)(pcVar4 + -0xc)] = *DAT_a7b7ba18;
LAB_97b9a790:
    pcVar4 = *(char **)(param_1 + 4);
  }
  error((int)this,(char *)param_4,pcVar3,pcVar4,"");
  return 0;
}

/* TParseContext__recover @ 0x97b9a7b8 (12 bytes) */
int TParseContext__recover(this)
  unsigned char *this;
{
  *(undefined4 *)(this + 0x14) = 1;
  return;
}

/* TParseContext__error @ 0x97b9a7c4 (104 bytes) */
int TParseContext__error(int param_1,char *param_2,char *param_3,char *param_4,...)

{
  char *in_r7;
  undefined4 in_r8;
  undefined4 in_r9;
  undefined4 in_r10;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  char acStack_210 [504];
  
  uStack0000002c = in_r8;
  uStack00000030 = in_r9;
  uStack00000034 = in_r10;
  _vsnprintf(acStack_210,400,in_r7,&STACKARG(0x2c));
                    
                    
  (*(code *)(((unsigned char *)0x97b9a82c) + (*(unsigned char *)0x97b9a834)))(*(undefined4 *)(param_1 + 8));
  return;
}

/* TParseContext__assignError @ 0x97b9a9b4 (96 bytes) */
int TParseContext__assignError(this, param_1, param_2, param_4, param_5)
  unsigned char *this;
  char *param_1;
  char *param_2;
  int param_4;
  int param_5;
{
  undefined1 *puVar1;
  undefined4 uVar2;
  
  puVar1 = DAT_a7b7ba18;
  *(undefined1 *)(*(int *)(param_4 + 4) + *(int *)(*(int *)(param_4 + 4) + -0xc)) = *DAT_a7b7ba18;
  uVar2 = *(undefined4 *)(param_4 + 4);
  *(undefined1 *)(*(int *)(param_5 + 4) + *(int *)(*(int *)(param_5 + 4) + -0xc)) = *puVar1;
  error((int)this,param_1,"",param_2,"cannot convert from \'%s\' to \'%s\'",
        *(undefined4 *)(param_5 + 4),uVar2);
  return;
}

/* TParseContext__unaryOpError @ 0x97b9aa14 (84 bytes) */
int TParseContext__unaryOpError(this, param_1, param_2, param_4)
  unsigned char *this;
  char *param_1;
  char *param_2;
  int param_4;
{
  *(undefined1 *)(*(int *)(param_4 + 4) + *(int *)(*(int *)(param_4 + 4) + -0xc)) = *DAT_a7b7ba18;
  error((int)this,param_1," wrong operand type",param_2,
        "no operation \'%s\' exists that takes an operand of type %s (or there is no acceptable conversion)"
        ,param_2,*(undefined4 *)(param_4 + 4));
  return;
}

/* TParseContext__binaryOpError @ 0x97b9aa68 (104 bytes) */
int TParseContext__binaryOpError(this, param_1, param_2, param_4, param_5)
  unsigned char *this;
  char *param_1;
  char *param_2;
  int param_4;
  int param_5;
{
  undefined1 *puVar1;
  undefined4 uVar2;
  
  puVar1 = DAT_a7b7ba18;
  *(undefined1 *)(*(int *)(param_5 + 4) + *(int *)(*(int *)(param_5 + 4) + -0xc)) = *DAT_a7b7ba18;
  uVar2 = *(undefined4 *)(param_5 + 4);
  *(undefined1 *)(*(int *)(param_4 + 4) + *(int *)(*(int *)(param_4 + 4) + -0xc)) = *puVar1;
  error((int)this,param_1," wrong operand types ",param_2,
        "no operation \'%s\' exists that takes a left-hand operand of type \'%s\' and a right operand of type \'%s\' (or there is no acceptable conversion)"
        ,param_2,*(undefined4 *)(param_4 + 4),uVar2);
  return;
}

/* TParseContext__lValueErrorCheck @ 0x97b9aad0 (944 bytes) */
int TParseContext__lValueErrorCheck(this, param_1, param_2, param_3)
  unsigned char *this;
  int param_1;
  char *param_2;
  unsigned char *param_3;
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  TIntermTyped *pTVar5;
  int iVar6;
  undefined4 uVar7;
  char *pcVar8;
  char *pcVar9;
  undefined4 *puVar10;
  undefined4 uVar11;
  char *pcVar12;
  int local_30 [4];
  
  piVar3 = (int *)(**(code **)(*(int *)param_3 + 0x28))(param_3);
  piVar4 = (int *)(**(code **)(*(int *)param_3 + 0x20))(param_3);
  if (piVar4 == (int *)0x0) {
    bVar1 = piVar3 != (int *)0x0;
    uVar11 = 0;
    if (bVar1) {
      iVar2 = (**(code **)(*piVar3 + 0x60))(piVar3);
      *(undefined1 *)(*(int *)(iVar2 + 4) + *(int *)(*(int *)(iVar2 + 4) + -0xc)) = *DAT_a7b7ba18;
      uVar11 = *(undefined4 *)(iVar2 + 4);
    }
    pcVar12 = (char *)0x0;
    uVar7 = (**(code **)(*(int *)param_3 + 0x44))(param_3);
    switch(uVar7) {
    default:
      iVar2 = (**(code **)(*(int *)param_3 + 0x40))(param_3);
      if (iVar2 - 5U < 8) {
        pcVar12 = "can\'t modify a sampler";
      }
      else {
        iVar2 = (**(code **)(*(int *)param_3 + 0x40))(param_3);
        if (iVar2 == 0) {
          pcVar12 = "can\'t modify void";
        }
        else {
          iVar2 = (**(code **)(*(int *)param_3 + 0x40))(param_3);
          if (iVar2 == 0xf) {
            pcVar12 = "can\'t modify an address";
          }
        }
      }
      break;
    case 2:
    case 0xc:
      pcVar12 = "can\'t modify a const";
      break;
    case 3:
      pcVar12 = "can\'t modify an attribute";
      break;
    case 4:
      pcVar12 = "can\'t modify a varying";
      break;
    case 6:
      pcVar12 = "can\'t modify a uniform";
      break;
    case 7:
      pcVar12 = "can\'t modify an input";
      break;
    case 0x10:
      pcVar12 = "can\'t modify gl_FrontFace";
      break;
    case 0x11:
      pcVar12 = "can\'t modify gl_FragCoord";
    }
    if (pcVar12 != (char *)0x0) {
      if (bVar1) {
        error((int)this,(char *)param_1," l-value required",param_2,"\"%s\" (%s)",uVar11,pcVar12);
        return 1;
      }
      pcVar8 = " l-value required";
      pcVar9 = "(%s)";
      goto LAB_97b9aea4;
    }
    if (bVar1) {
      return 0;
    }
LAB_97b9ae0c:
    pcVar8 = " l-value required";
  }
  else {
    iVar2 = piVar4[0xc];
    if (iVar2 < 0x2d) goto LAB_97b9ae0c;
    if (iVar2 < 0x30) {
      pTVar5 = (unsigned char *)(**(code **)(*piVar4 + 0x68))();
      iVar2 = ((int (*)())TParseContext__lValueErrorCheck)(this,param_1,param_2,pTVar5);
      return iVar2;
    }
    if (iVar2 != 0x30) goto LAB_97b9ae0c;
    pTVar5 = (unsigned char *)(**(code **)(*piVar4 + 0x68))();
    local_30[0] = ((int (*)())TParseContext__lValueErrorCheck)(this,param_1,param_2,pTVar5);
    if (local_30[0] != 0) {
      return local_30[0];
    }
    local_30[1] = local_30[0];
    local_30[2] = local_30[0];
    local_30[3] = local_30[0];
    piVar3 = (int *)(**(code **)(*piVar4 + 0x6c))(piVar4);
    piVar3 = (int *)(**(code **)(*piVar3 + 0x1c))();
    iVar2 = (**(code **)(*piVar3 + 100))();
    puVar10 = *(undefined4 **)(iVar2 + 4);
    while( true ) {
      iVar2 = (**(code **)(*piVar3 + 100))(piVar3);
      if (puVar10 == *(undefined4 **)(iVar2 + 8)) {
        return 0;
      }
      piVar4 = (int *)(**(code **)(*(int *)*puVar10 + 0x14))();
      iVar6 = (**(code **)(*piVar4 + 0x18))();
      iVar2 = local_30[**(int **)(iVar6 + 0x30)];
      local_30[**(int **)(iVar6 + 0x30)] = iVar2 + 1;
      if (1 < iVar2 + 1) break;
      puVar10 = puVar10 + 1;
    }
    pcVar8 = " l-value of swizzle cannot have duplicate components";
  }
  pcVar9 = "";
  pcVar12 = pcVar9;
LAB_97b9aea4:
  error((int)this,(char *)param_1,pcVar8,param_2,pcVar9,pcVar12);
  return 1;
}

/* TParseContext__constErrorCheck @ 0x97b9aec8 (140 bytes) */
int TParseContext__constErrorCheck(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  int iVar1;
  char *pcVar2;
  
  iVar1 = (**(code **)(*(int *)param_1 + 0x44))(param_1);
  if (iVar1 != 2) {
    pcVar2 = (char *)(*(code *)**(undefined4 **)param_1)(param_1);
    error((int)this,pcVar2,"constant expression required","","");
  }
  return iVar1 != 2;
}

/* TParseContext__integerErrorCheck @ 0x97b9af54 (172 bytes) */
int TParseContext__integerErrorCheck(this, param_1, param_2)
  unsigned char *this;
  unsigned char *param_1;
  char *param_2;
{
  int iVar1;
  char *pcVar2;
  
  iVar1 = (**(code **)(*(int *)param_1 + 0x40))(param_1);
  if ((iVar1 == 2) && (iVar1 = (**(code **)(*(int *)param_1 + 0x48))(param_1), iVar1 == 1)) {
    return 0;
  }
  pcVar2 = (char *)(*(code *)**(undefined4 **)param_1)(param_1);
  error((int)this,pcVar2,"integer expression required",param_2,"");
  return 1;
}

/* TParseContext__globalErrorCheck @ 0x97b9b000 (84 bytes) */
int TParseContext__globalErrorCheck(this, param_1, param_2, param_3)
  unsigned char *this;
  int param_1;
  int param_2;
  char *param_3;
{
  bool bVar1;
  undefined3 in_register_00000014;
  
  bVar1 = CONCAT31(in_register_00000014,param_2) == 0;
  if (bVar1) {
    error((int)this,(char *)param_1,"only allowed at global scope",param_3,"");
  }
  return bVar1;
}

/* TParseContext__reservedErrorCheck @ 0x97b9b054 (376 bytes) */
int TParseContext__reservedErrorCheck(this, param_1, param_2)
  unsigned char *this;
  int param_1;
  unsigned char *param_2;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  char in_RESERVE;
  byte bVar8;
  undefined4 local_80;
  void *local_7c;
  undefined4 local_70;
  void *local_6c;
  undefined4 local_60 [4];
  undefined4 local_50;
  undefined4 local_40;
  uint local_30;
  uint local_2c [4];
  
  iVar2 = (*(int **)(this + 4))[1] - **(int **)(this + 4) >> 2;
  if ((iVar2 != 1) && (iVar2 != 2)) {
    std__string__string((unsigned char *)&local_80,param_2,0,3);
    local_60[0] = ((int (*)())GetGlobalPoolAllocator)();
    std__string__string((unsigned char *)&local_70,"gl_",(unsigned char *)local_60);
    puVar5 = local_2c;
    uVar6 = *(uint *)((int)local_6c + -0xc);
    local_30 = uVar6;
    uVar7 = *(uint *)((int)local_7c + -0xc);
    local_2c[0] = uVar7;
    if (uVar6 <= uVar7) {
      puVar5 = &local_30;
    }
    iVar2 = _memcmp(local_6c,local_7c,*puVar5);
    bVar8 = (iVar2 == 0) << 1;
    if (iVar2 == 0) {
      iVar2 = uVar6 - uVar7;
    }
    piVar3 = (int *)((int)local_6c + -4);
    local_50 = local_70;
    do {
      iVar4 = *piVar3;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
        *piVar3 = iVar1;
        bVar8 = 2;
      }
    } while (!(bool)(bVar8 >> 1));
    if (iVar4 < 1) {
      std__string___Rep___M_destroy((unsigned char *)((int)local_6c + -0xc));
    }
    piVar3 = (int *)((int)local_7c + -4);
    local_40 = local_80;
    do {
      iVar4 = *piVar3;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
        *piVar3 = iVar1;
        bVar8 = 2;
      }
    } while (!(bool)(bVar8 >> 1 & 1));
    if (iVar4 < 1) {
      std__string___Rep___M_destroy((unsigned char *)((int)local_7c + -0xc));
    }
    if (iVar2 == 0) {
      error((int)this,(char *)param_1,"reserved built-in name","gl_","");
      return 1;
    }
  }
  return 0;
}

/* TParseContext__constructorErrorCheck @ 0x97b9b1cc (2036 bytes) */
int TParseContext__constructorErrorCheck(this, param_1, param_2, param_3, param_5, param_6)
  unsigned char *this;
  char *param_1;
  int *param_2;
  int param_3;
  int param_5;
  int *param_6;
{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  int *piVar6;
  string *psVar7;
  ulong uVar8;
  int iVar9;
  int iVar10;
  char *pcVar11;
  char *pcVar12;
  char *pcVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  char in_RESERVE;
  byte bVar17;
  undefined **local_c0;
  int local_bc;
  int local_b8;
  int local_b4;
  string *local_b0;
  int local_ac;
  int local_a8;
  int local_a4;
  int local_a0;
  uint local_9c;
  undefined4 local_90;
  int local_8c;
  undefined4 local_80;
  char *local_7c;
  undefined4 local_70 [4];
  undefined4 local_60;
  undefined4 local_50;
  
  switch(param_5) {
  case 0x66:
    uVar14 = local_9c & 0xfff | 0x100800;
    goto LAB_97b9b330;
  case 0x67:
    iVar15 = 1;
    uVar14 = local_9c & 0x1fffff | 0x180000;
    break;
  case 0x68:
    iVar15 = 1;
    goto LAB_97b9b2f0;
  case 0x69:
    uVar14 = local_9c & 0xfffff | 0x80000;
    goto LAB_97b9b2e4;
  case 0x6a:
    iVar15 = 3;
    uVar14 = local_9c & 0xfffff | 0x80000;
    break;
  case 0x6b:
    uVar14 = local_9c & 0xfffff | 0x80000;
    goto LAB_97b9b3cc;
  case 0x6c:
    uVar14 = local_9c & 0x1fffff | 0x180000;
LAB_97b9b2e4:
    iVar15 = 2;
    break;
  case 0x6d:
    iVar15 = 3;
    goto LAB_97b9b2f0;
  case 0x6e:
    uVar14 = local_9c & 0x1fffff | 0x180000;
    goto LAB_97b9b3cc;
  case 0x6f:
    iVar15 = 2;
LAB_97b9b2f0:
    uVar14 = iVar15 << 0x13 | local_9c & 0x7ffff;
    break;
  case 0x70:
    uVar14 = local_9c & 0x1fff | 0x101800;
LAB_97b9b330:
    local_9c = uVar14 & 0xfffff9ff;
    param_6[8] = 0;
    param_6[9] = uVar14 & 0x7f800 | uVar14 & 0xfff80000 | param_6[9] & 0x1ffU;
    local_bc = 0;
    local_b8 = 0;
    local_b4 = 0;
    local_b0 = (unsigned char *)0x0;
    local_ac = 0;
    local_a8 = 0;
    local_a4 = 0;
    local_c0 = &PTR__TType_a7b7d4d0;
    local_a0 = 0;
    param_6[1] = 0;
    param_6[2] = 0;
    param_6[3] = 0;
    param_6[4] = 0;
    param_6[5] = 0;
    param_6[6] = 0;
    param_6[7] = 0;
    goto LAB_97b9b714;
  case 0x71:
    uVar14 = local_9c & 0x7ffff | 0x100000;
LAB_97b9b3cc:
    iVar15 = 4;
    break;
  case 0x72:
    iVar15 = 2;
    goto LAB_97b9b490;
  case 0x73:
    uVar14 = local_9c & 0x1bff | 0x81800;
    goto LAB_97b9b4a0;
  case 0x74:
    iVar15 = 4;
LAB_97b9b490:
    uVar14 = iVar15 << 0xb | local_9c & 0x3ff | 0x80000;
LAB_97b9b4a0:
    local_9c = uVar14 & 0xfffffdff | 0x400;
    param_6[9] = uVar14 & 0x7f800 | uVar14 & 0xfff80000 | param_6[9] & 0x1ffU | 0x400;
    param_6[8] = 0;
    local_bc = 0;
    local_b8 = 0;
    local_b4 = 0;
    local_b0 = (unsigned char *)0x0;
    local_ac = 0;
    local_a8 = 0;
    local_a4 = 0;
    local_c0 = &PTR__TType_a7b7d4d0;
    local_a0 = 0;
    param_6[1] = 0;
    param_6[2] = 0;
    param_6[3] = 0;
    param_6[4] = 0;
    param_6[5] = 0;
    param_6[6] = 0;
    param_6[7] = 0;
    goto LAB_97b9b714;
  case 0x75:
    iVar15 = *(int *)(param_3 + 0x24);
    psVar7 = (unsigned char *)(**(code **)(*(int *)(param_3 + 0x1c) + 0x18))(param_3 + 0x1c);
    std__string__string((unsigned char *)&local_90,psVar7);
    std__string__string((unsigned char *)&local_80,(unsigned char *)&local_90);
    local_9c = local_9c & 0x9ff | 0x700800;
    local_c0 = &PTR__TType_a7b7d4d0;
    local_a0 = 0;
    local_bc = 0;
    local_b4 = 0;
    local_ac = 0;
    local_a4 = 0;
    local_b8 = iVar15;
    local_a8 = TType__setStructSize((unsigned char *)&local_c0);
    pcVar11 = local_7c;
    local_7c[*(int *)(local_7c + -0xc)] = *DAT_a7b7ba18;
    uVar8 = ((int (*)())GetGlobalPoolAllocator)();
    psVar7 = (unsigned char *)TPoolAllocator__allocate(uVar8);
    bVar17 = (psVar7 == (unsigned char *)0x0) << 1;
    local_b0 = (unsigned char *)0x0;
    if (psVar7 != (unsigned char *)0x0) {
      local_70[0] = ((int (*)())GetGlobalPoolAllocator)();
      std__string__string(psVar7,pcVar11,(unsigned char *)local_70);
      local_b0 = psVar7;
    }
    piVar6 = (int *)(local_7c + -4);
    local_60 = local_80;
    do {
      iVar15 = *piVar6;
      if (in_RESERVE != '\0') {
        iVar16 = storeWordConditionalIndexed(iVar15 + -1,0,piVar6);
        *piVar6 = iVar16;
        bVar17 = 2;
      }
    } while (!(bool)(bVar17 >> 1 & 1));
    if (iVar15 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_7c + -0xc));
    }
    param_6[1] = local_bc;
    param_6[2] = local_b8;
    param_6[3] = local_b4;
    param_6[4] = (int)local_b0;
    param_6[5] = local_ac;
    param_6[6] = local_a8;
    param_6[7] = local_a4;
    param_6[9] = (local_9c >> 9 & 1) << 9 |
                 (local_9c >> 10 & 1) << 10 |
                 local_9c & 0x7f800 |
                 (local_9c >> 0x13 & 0x3f) << 0x13 | local_9c & 0xfe000000 | param_6[9] & 0x1ffU;
    piVar6 = (int *)(local_8c + -4);
    param_6[8] = local_a0;
    local_c0 = &PTR__TType_a7b7d4d0;
    local_50 = local_90;
    do {
      iVar15 = *piVar6;
      if (in_RESERVE != '\0') {
        iVar16 = storeWordConditionalIndexed(iVar15 + -1,0,piVar6);
        *piVar6 = iVar16;
        bVar17 = 2;
      }
    } while (!(bool)(bVar17 >> 1 & 1));
    if (iVar15 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_8c + -0xc));
    }
    goto LAB_97b9b714;
  default:
    pcVar11 = "expected constructor";
    pcVar12 = "Internal Error";
    goto LAB_97b9b9d8;
  }
  local_9c = iVar15 << 0xb | uVar14 & 0xfff801ff;
  param_6[9] = iVar15 << 0xb | uVar14 & 0xfff80000 | param_6[9] & 0x1ffU;
  param_6[8] = 0;
  local_bc = 0;
  local_b8 = 0;
  local_b4 = 0;
  local_b0 = (unsigned char *)0x0;
  local_ac = 0;
  local_a8 = 0;
  local_a4 = 0;
  local_c0 = &PTR__TType_a7b7d4d0;
  local_a0 = 0;
  param_6[1] = 0;
  param_6[2] = 0;
  param_6[3] = 0;
  param_6[4] = 0;
  param_6[5] = 0;
  param_6[6] = 0;
  param_6[7] = 0;
LAB_97b9b714:
  iVar15 = 0;
  bVar2 = true;
  bVar1 = false;
  bVar5 = false;
  bVar4 = false;
  bVar3 = false;
  for (iVar16 = 0; iVar16 < *(int *)(param_3 + 0x14) - *(int *)(param_3 + 0x10) >> 3;
      iVar16 = iVar16 + 1) {
    iVar10 = iVar16 * 8;
    iVar9 = (**(code **)(**(int **)(*(int *)(param_3 + 0x10) + iVar10 + 4) + 0x30))();
    iVar15 = iVar15 + iVar9;
    if ((param_5 - 0x72U < 3) &&
       (iVar9 = (**(code **)(**(int **)(*(int *)(param_3 + 0x10) + iVar10 + 4) + 0x34))(),
       iVar9 != 0)) {
      bVar4 = true;
    }
    if (bVar1) {
      bVar5 = true;
    }
    if ((param_5 != 0x75) && (iVar9 = (**(code **)(*param_6 + 0x30))(param_6), iVar9 <= iVar15)) {
      bVar1 = true;
    }
    iVar9 = (**(code **)(**(int **)(*(int *)(param_3 + 0x10) + iVar10 + 4) + 0x24))();
    if (iVar9 != 2) {
      bVar2 = false;
    }
    iVar10 = (**(code **)(**(int **)(*(int *)(param_3 + 0x10) + iVar10 + 4) + 0x38))();
    if (iVar10 != 0) {
      bVar3 = true;
    }
  }
  if (bVar2) {
    (**(code **)(*param_6 + 0x28))(param_6,2);
  }
  if (bVar3) {
    pcVar11 = "constructing from a non-dereferenced array";
  }
  else {
    if (bVar4) {
      pcVar11 = "constructing matrix from matrix";
      pcVar12 = "constructor";
      pcVar13 = "(reserved)";
      goto LAB_97b9b9dc;
    }
    if (bVar5) {
      pcVar11 = "too many arguments";
    }
    else if (((iVar15 == 1) || (iVar16 = (**(code **)(*param_6 + 0x30))(param_6), iVar16 <= iVar15))
            && ((0 < iVar15 || (param_5 != 0x75)))) {
      piVar6 = (int *)(**(code **)(*param_2 + 0x14))(param_2);
      if (piVar6 == (int *)0x0) {
        pcVar11 = "constructor argument does not have a type";
      }
      else if ((param_5 == 0x75) || (iVar15 = (**(code **)(*piVar6 + 0x40))(), 7 < iVar15 - 5U)) {
        iVar15 = (**(code **)(*piVar6 + 0x40))(piVar6);
        if (iVar15 != 0) {
          return 0;
        }
        pcVar11 = "cannot convert a void";
      }
      else {
        pcVar11 = "cannot convert a sampler";
      }
    }
    else {
      pcVar11 = "not enough data provided for construction";
    }
  }
  pcVar12 = "constructor";
LAB_97b9b9d8:
  pcVar13 = "";
LAB_97b9b9dc:
  error((int)this,param_1,pcVar11,pcVar12,pcVar13);
  return 1;
}

/* TParseContext__voidErrorCheck @ 0x97b9ba00 (120 bytes) */
int TParseContext__voidErrorCheck(this, param_1, param_2, param_3)
  unsigned char *this;
  int param_1;
  unsigned char *param_2;
  unsigned char *param_3;
{
  int iVar1;
  
  iVar1 = *(int *)param_3;
  if (iVar1 == 0) {
    *(undefined1 *)(*(int *)(param_2 + 4) + *(int *)(*(int *)(param_2 + 4) + -0xc)) = *DAT_a7b7ba18;
    error((int)this,(char *)param_1,"illegal use of type \'void\'",*(char **)(param_2 + 4),"");
  }
  return iVar1 == 0;
}

/* TParseContext__boolErrorCheck @ 0x97b9ba78 (208 bytes) */
int TParseContext__boolErrorCheck(this, param_1, param_2)
  unsigned char *this;
  int param_1;
  unsigned char *param_2;
{
  int iVar1;
  
  iVar1 = (**(code **)(*(int *)param_2 + 0x40))(param_2);
  if ((((iVar1 == 3) && (iVar1 = (**(code **)(*(int *)param_2 + 0x54))(param_2), iVar1 == 0)) &&
      (iVar1 = (**(code **)(*(int *)param_2 + 0x50))(param_2), iVar1 == 0)) &&
     (iVar1 = (**(code **)(*(int *)param_2 + 0x58))(param_2), iVar1 == 0)) {
    return 0;
  }
  error((int)this,(char *)param_1,"boolean expression expected","","");
  return 1;
}

/* TParseContext__boolErrorCheck_97b9bb48 @ 0x97b9bb48 (132 bytes) */
int TParseContext__boolErrorCheck_97b9bb48(this, param_1, param_2)
  unsigned char *this;
  int param_1;
  unsigned char *param_2;
{
  undefined4 uVar1;
  
  if ((((*(int *)param_2 != 3) || (*(int *)(param_2 + 0x10) != 0)) || (*(int *)(param_2 + 0xc) != 0)
      ) || (uVar1 = 0, 1 < *(int *)(param_2 + 8))) {
    error((int)this,(char *)param_1,"boolean expression expected","","");
    uVar1 = 1;
  }
  return uVar1;
}

/* TParseContext__samplerErrorCheck @ 0x97b9bbcc (184 bytes) */
int TParseContext__samplerErrorCheck(this, param_1, param_2, param_3)
  unsigned char *this;
  int param_1;
  unsigned char *param_2;
  char *param_3;
{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  
  iVar1 = *(int *)param_2;
  if (iVar1 == 0xe) {
    iVar1 = ((int (*)())TParseContext__containsSampler)(this,*(TType **)(param_2 + 0x14));
    if (iVar1 == 0) {
      return 0;
    }
    pcVar2 = (char *)TType__getBasicString(*(undefined4 *)param_2);
    pcVar3 = "(structure contains a sampler)";
  }
  else {
    if (7 < iVar1 - 5U) {
      return 0;
    }
    pcVar2 = (char *)TType__getBasicString(iVar1);
    pcVar3 = "";
  }
  error((int)this,(char *)param_1,param_3,pcVar2,pcVar3);
  return 1;
}

/* TParseContext__structQualifierErrorCheck @ 0x97b9bc84 (172 bytes) */
int TParseContext__structQualifierErrorCheck(this, param_1, param_2)
  unsigned char *this;
  int param_1;
  unsigned char *param_2;
{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_2 + 4);
  if ((iVar1 - 3U < 3) && (*(int *)param_2 == 0xe)) {
    pcVar2 = (char *)getQualifierString(iVar1);
    error((int)this,(char *)param_1,"cannot be used with a structure",pcVar2,"");
    uVar3 = 1;
  }
  else {
    if ((iVar1 != 6) &&
       (iVar1 = ((int (*)())TParseContext__samplerErrorCheck)(this,param_1,param_2,"samplers must be uniform"), iVar1 != 0)) {
      return 1;
    }
    uVar3 = 0;
  }
  return uVar3;
}

/* TParseContext__parameterSamplerErrorCheck @ 0x97b9bd30 (184 bytes) */
int TParseContext__parameterSamplerErrorCheck(this, param_1, param_3, param_4)
  unsigned char *this;
  char *param_1;
  int param_3;
  int *param_4;
{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  
  if (((param_3 - 10U < 2) && (iVar1 = (**(code **)(*param_4 + 0x20))(param_4), iVar1 != 0xe)) &&
     (iVar1 = (**(code **)(*param_4 + 0x20))(param_4), iVar1 - 5U < 8)) {
    pcVar2 = (char *)TType__getBasicString((uint)param_4[9] >> 0x13 & 0x3f);
    error((int)this,param_1,"samplers cannot be output parameters",pcVar2,"");
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}

/* TParseContext__containsSampler @ 0x97b9bde8 (180 bytes) */
int TParseContext__containsSampler(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  iVar1 = (**(code **)(*(int *)param_1 + 0x20))(param_1);
  uVar2 = 1;
  if (7 < iVar1 - 5U) {
    iVar1 = (**(code **)(*(int *)param_1 + 0x20))(param_1);
    if (iVar1 == 0xe) {
      iVar1 = *(int *)(param_1 + 8);
      for (uVar4 = 0; iVar3 = *(int *)(iVar1 + 4), uVar4 < (uint)(*(int *)(iVar1 + 8) - iVar3 >> 3);
          uVar4 = uVar4 + 1) {
        iVar3 = ((int (*)())TParseContext__containsSampler)(this,*(TType **)(iVar3 + uVar4 * 8));
        if (iVar3 != 0) {
          return 1;
        }
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}

/* TParseContext__insertBuiltInArrayAtGlobalLevel @ 0x97b9be9c (740 bytes) */
int TParseContext__insertBuiltInArrayAtGlobalLevel(this)
  unsigned char *this;
{
  undefined1 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined *puVar6;
  uint uVar7;
  ulong uVar8;
  string *psVar9;
  int *piVar10;
  char *pcVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  string *psVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  int *piVar22;
  char in_RESERVE;
  byte bVar23;
  undefined4 local_80 [4];
  int local_70 [4];
  undefined4 local_60;
  int local_5c;
  undefined4 local_50;
  int local_4c;
  undefined4 local_40;
  int local_3c;
  int *local_38;
  undefined4 local_30;
  
  uVar8 = ((int (*)())GetGlobalPoolAllocator)();
  psVar9 = (unsigned char *)TPoolAllocator__allocate(uVar8);
  bVar23 = (psVar9 == (unsigned char *)0x0) << 1;
  psVar18 = (unsigned char *)0x0;
  if (psVar9 != (unsigned char *)0x0) {
    local_80[0] = ((int (*)())GetGlobalPoolAllocator)();
    std__string__string(psVar9,"gl_TexCoord",(unsigned char *)local_80);
    psVar18 = psVar9;
  }
  piVar22 = *(int **)(this + 4);
  iVar16 = *piVar22;
  iVar19 = (piVar22[1] - iVar16 >> 2) + -1;
  while( true ) {
    iVar16 = *(int *)(iVar16 + iVar19 * 4);
    std::
    _Rb_tree<std::string,std::pair<std::string_const,TSymbol*>,std::_Select1st<std::pair<std::string_const,TSymbol*>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,TSymbol*>>>
    ::find((unsigned char *)local_70);
    iVar20 = 0;
    if (local_70[0] != *(int *)(iVar16 + 4)) {
      iVar20 = *(int *)(local_70[0] + 0x18);
    }
    iVar19 = iVar19 + -1;
    if (iVar20 != 0) break;
    if (iVar19 < 0) {
      iVar19 = *(int *)(psVar18 + 4);
      iVar16 = *(int *)(iVar19 + -0xc);
      uVar1 = *DAT_a7b7ba18;
      pcVar11 = "INTERNAL ERROR finding symbol";
LAB_97b9c154:
      *(undefined1 *)(iVar19 + iVar16) = uVar1;
      error((int)this,(char *)0x0,pcVar11,*(char **)(psVar18 + 4),"");
      return 1;
    }
    iVar16 = *piVar22;
  }
  uVar8 = ((int (*)())GetGlobalPoolAllocator)();
  piVar10 = (int *)TPoolAllocator__allocate(uVar8);
  puVar6 = PTR_vtable_a7b7c0b4;
  piVar10[1] = (int)psVar18;
  *piVar10 = (int)(puVar6 + 8);
  iVar15 = *(int *)(iVar20 + 0x18);
  iVar14 = *(int *)(iVar20 + 0x1c);
  iVar13 = *(int *)(iVar20 + 0x20);
  iVar12 = *(int *)(iVar20 + 0x24);
  iVar19 = *(int *)(iVar20 + 0x28);
  iVar16 = *(int *)(iVar20 + 0x10);
  iVar17 = *(int *)(iVar20 + 0x14);
  iVar21 = *(int *)(iVar20 + 0x2c);
  piVar10[3] = (int)&PTR__TType_a7b7d4d0;
  piVar10[6] = iVar15;
  piVar10[7] = iVar14;
  piVar10[8] = iVar13;
  piVar10[9] = iVar12;
  piVar10[10] = iVar19;
  piVar10[4] = iVar16;
  piVar10[5] = iVar17;
  piVar10[0xb] = iVar21;
  uVar7 = piVar10[0xc];
  uVar3 = *(uint *)(iVar20 + 0x30) & 0xfe000000;
  piVar10[0xc] = uVar3 | uVar7 & 0x1ffffff;
  uVar4 = (*(uint *)(iVar20 + 0x30) >> 0x13 & 0x3f) << 0x13;
  piVar10[0xc] = uVar4 | uVar3 | uVar7 & 0x7ffff;
  uVar2 = *(uint *)(iVar20 + 0x30) & 0x7f800;
  piVar10[0xc] = uVar2 | uVar4 | uVar3 | uVar7 & 0x7ff;
  uVar5 = (*(uint *)(iVar20 + 0x30) >> 10 & 1) << 10;
  piVar10[0xc] = uVar5 | uVar2 | uVar4 | uVar3 | uVar7 & 0x3ff;
  piVar10[0xc] = (*(uint *)(iVar20 + 0x30) >> 9 & 1) << 9 |
                 uVar5 | uVar2 | uVar4 | uVar3 | uVar7 & 0x1ff;
  piVar10[0xd] = 0;
  piVar10[0xe] = 0;
  piVar10[0xf] = 0;
  iVar16 = *(int *)(*(int *)(this + 4) + 0xc) + 1;
  *(int *)(*(int *)(this + 4) + 0xc) = iVar16;
  piVar10[2] = iVar16;
  local_5c = 0;
  psVar9 = (unsigned char *)(**(code **)(*piVar10 + 8))();
  std__string__string((unsigned char *)&local_40,psVar9);
  local_38 = piVar10;
  std::
  _Rb_tree<std::string,std::pair<std::string_const,TSymbol*>,std::_Select1st<std::pair<std::string_const,TSymbol*>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,TSymbol*>>>
  ::insert_unique((unsigned char *)&local_50);
  local_60 = local_50;
  piVar22 = (int *)(local_3c + -4);
  local_5c = local_4c;
  local_30 = local_40;
  do {
    iVar16 = *piVar22;
    if (in_RESERVE != '\0') {
      iVar19 = storeWordConditionalIndexed(iVar16 + -1,0,piVar22);
      *piVar22 = iVar19;
      bVar23 = 2;
    }
  } while (!(bool)(bVar23 >> 1 & 1));
  if (iVar16 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(local_3c + -0xc));
  }
  if (local_5c != 0) {
    return 0;
  }
  (**(code **)(*piVar10 + 4))(piVar10);
  iVar19 = *(int *)(psVar18 + 4);
  iVar16 = *(int *)(iVar19 + -0xc);
  uVar1 = *DAT_a7b7ba18;
  pcVar11 = "INTERNAL ERROR inserting new symbol";
  goto LAB_97b9c154;
}

/* TParseContext__arrayErrorCheck @ 0x97b9c180 (2552 bytes) */
int TParseContext__arrayErrorCheck(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  unsigned char *param_1;
  char *param_2;
  unsigned char *param_3;
  uint param_4;
  uint param_5;
  uint param_6;
  uint param_7;
  uint param_8;
{
  bool bVar1;
  uint uVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  ulong uVar10;
  string *psVar11;
  string *psVar12;
  char cVar13;
  int iVar14;
  char *pcVar15;
  int *piVar16;
  int *piVar17;
  char in_RESERVE;
  byte in_cr0;
  byte bVar18;
  uint uStack00000024;
  uint uStack00000028;
  uint uStack0000002c;
  uint uStack00000030;
  uint uStack00000034;
  int *in_stack_00000038;
  undefined4 in_stack_0000003c;
  int *in_stack_00000040;
  string *local_130;
  char *local_12c;
  int local_128;
  char *local_124;
  string *local_120;
  char *local_11c;
  char *local_118;
  char *local_114;
  string *local_110;
  uint local_10c;
  undefined4 local_108;
  undefined4 local_104;
  uint local_100;
  uint local_fc;
  uint local_f8;
  uint local_f4;
  uint local_f0;
  int *local_ec;
  uint local_e8;
  uint local_e4;
  uint local_e0;
  int *local_dc;
  uint local_d8;
  uint local_d4;
  uint local_d0;
  int *local_cc;
  uint local_c8;
  uint local_c4;
  uint local_c0;
  int *local_bc;
  undefined4 local_b8;
  undefined4 local_b0 [4];
  string *local_a0;
  int local_90 [4];
  undefined4 local_80 [4];
  undefined4 local_70;
  int local_6c;
  int *local_68;
  undefined4 local_60;
  undefined4 local_50 [4];
  uint local_40;
  uint local_3c;
  
  uStack00000024 = param_4;
  uStack00000028 = param_5;
  uStack0000002c = param_6;
  uStack00000030 = param_7;
  if (((param_8 == 0) && (param_5 != 3)) && (param_5 != 2)) {
    bVar1 = in_stack_00000040 == (int *)0x0;
    uStack00000034 = 1;
    piVar7 = (int *)0x0;
    if ((bVar1) ||
       (((piVar7 = (int *)(**(code **)(*in_stack_00000040 + 0x18))(), piVar7 != (int *)0x0 &&
         (iVar9 = (**(code **)(*piVar7 + 0x40))(), iVar9 == 2)) && (0 < *(int *)piVar7[0xc])))) {
      piVar17 = *(int **)(param_1 + 4);
      local_3c = 0;
      local_40 = 0;
      iVar14 = *piVar17;
      iVar9 = (piVar17[1] - iVar14 >> 2) + -1;
      while( true ) {
        iVar14 = *(int *)(iVar14 + iVar9 * 4);
        std::
        _Rb_tree<std::string,std::pair<std::string_const,TSymbol*>,std::_Select1st<std::pair<std::string_const,TSymbol*>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,TSymbol*>>>
        ::find((unsigned char *)local_90);
        piVar16 = (int *)0x0;
        if (local_90[0] != *(int *)(iVar14 + 4)) {
          piVar16 = *(int **)(local_90[0] + 0x18);
        }
        if ((piVar16 != (int *)0x0) || (iVar9 + -1 < 0)) break;
        iVar14 = *piVar17;
        iVar9 = iVar9 + -1;
      }
      if (&STACKARG(0x0) != (undefined1 *)0x40) {
        local_40 = (uint)(iVar9 == 0);
      }
      if (&STACKARG(0x0) != (undefined1 *)0x3c) {
        local_3c = (uint)(iVar9 == (piVar17[1] - *piVar17 >> 2) + -1);
      }
      if ((piVar16 == (int *)0x0) || (local_3c == 0)) {
        local_12c = (char *)((int (*)())TParseContext__reservedErrorCheck)(param_1,(int)param_2,param_3);
        bVar18 = (local_12c == (char *)0x0) << 1;
        if (local_12c != (char *)0x0) {
          return 1;
        }
        uVar10 = ((int (*)())GetGlobalPoolAllocator)();
        piVar17 = (int *)TPoolAllocator__allocate(uVar10);
        local_10c = (uStack00000034 & 1) << 9 |
                    (uStack00000030 & 1) << 10 |
                    (uStack0000002c & 0xff) << 0xb |
                    (uStack00000024 & 0x3f) << 0x13 | uStack00000028 << 0x19 | local_10c & 0x1ff;
        local_c8 = in_stack_0000003c;
        local_130 = (unsigned char *)&PTR__TType_a7b7d4d0;
        local_100 = uStack00000024;
        local_fc = uStack00000028;
        local_f8 = uStack0000002c;
        local_f4 = uStack00000030;
        local_f0 = uStack00000034;
        local_ec = in_stack_00000038;
        local_e8 = in_stack_0000003c;
        local_e0 = uStack00000024;
        local_dc = (int *)uStack00000028;
        local_d8 = uStack0000002c;
        local_d4 = uStack00000030;
        local_d0 = uStack00000034;
        local_cc = in_stack_00000038;
        local_128 = 0;
        local_118 = (char *)0x0;
        local_124 = local_12c;
        psVar12 = (unsigned char *)0x0;
        local_11c = local_12c;
        local_114 = local_12c;
        local_110 = (unsigned char *)local_12c;
        if (in_stack_00000038 != (int *)0x0) {
          local_128 = in_stack_00000038[2];
          local_120 = (unsigned char *)local_12c;
          local_118 = local_12c;
          local_118 = (char *)TType__setStructSize((unsigned char *)&local_130);
          iVar9 = (**(code **)(*local_cc + 0x18))(local_cc);
          *(char *)(*(int *)(iVar9 + 4) + *(int *)(*(int *)(iVar9 + 4) + -0xc)) = *DAT_a7b7ba18;
          pcVar15 = *(char **)(iVar9 + 4);
          uVar10 = ((int (*)())GetGlobalPoolAllocator)();
          psVar11 = (unsigned char *)TPoolAllocator__allocate(uVar10);
          bVar18 = (psVar11 == (unsigned char *)0x0) << 1;
          psVar12 = (unsigned char *)0x0;
          if (psVar11 != (unsigned char *)0x0) {
            local_80[0] = ((int (*)())GetGlobalPoolAllocator)();
            std__string__string(psVar11,pcVar15,(unsigned char *)local_80);
            psVar12 = psVar11;
          }
        }
        local_120 = psVar12;
        piVar17[1] = (int)param_3;
        *piVar17 = (int)(PTR_vtable_a7b7c0b4 + 8);
        piVar17[4] = (int)local_12c;
        piVar17[5] = local_128;
        piVar17[6] = (int)local_124;
        piVar17[7] = (int)local_120;
        piVar17[8] = (int)local_11c;
        piVar17[9] = (int)local_118;
        piVar17[3] = (int)&PTR__TType_a7b7d4d0;
        piVar17[10] = (int)local_114;
        piVar17[0xb] = (int)local_110;
        uVar8 = piVar17[0xc];
        uVar4 = local_10c & 0xfe000000;
        piVar17[0xc] = uVar4 | uVar8 & 0x1ffffff;
        uVar5 = (local_10c >> 0x13 & 0x3f) << 0x13;
        piVar17[0xc] = uVar5 | uVar4 | uVar8 & 0x7ffff;
        uVar2 = local_10c & 0x7f800;
        piVar17[0xc] = uVar2 | uVar5 | uVar4 | uVar8 & 0x7ff;
        uVar6 = (local_10c >> 10 & 1) << 10;
        piVar17[0xc] = uVar6 | uVar2 | uVar5 | uVar4 | uVar8 & 0x3ff;
        piVar17[0xc] = (local_10c >> 9 & 1) << 9 | uVar6 | uVar2 | uVar5 | uVar4 | uVar8 & 0x1ff;
        piVar17[0xd] = 0;
        piVar17[0xe] = 0;
        piVar17[0xf] = 0;
        local_130 = (unsigned char *)&PTR__TType_a7b7d4d0;
        if (!bVar1) {
          piVar17[4] = *(int *)piVar7[0xc];
          piVar17[0xc] = piVar17[0xc] | 0x200;
        }
        iVar9 = *(int *)(*(int *)(param_1 + 4) + 0xc) + 1;
        *(int *)(*(int *)(param_1 + 4) + 0xc) = iVar9;
        piVar17[2] = iVar9;
        local_12c = (char *)0x0;
        psVar12 = (unsigned char *)(**(code **)(*piVar17 + 8))(piVar17);
        std__string__string((unsigned char *)&local_70,psVar12);
        local_68 = piVar17;
        std::
        _Rb_tree<std::string,std::pair<std::string_const,TSymbol*>,std::_Select1st<std::pair<std::string_const,TSymbol*>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,TSymbol*>>>
        ::insert_unique((unsigned char *)&local_120);
        local_130 = local_120;
        piVar7 = (int *)(local_6c + -4);
        local_12c = local_11c;
        local_60 = local_70;
        do {
          iVar9 = *piVar7;
          if (in_RESERVE != '\0') {
            iVar14 = storeWordConditionalIndexed(iVar9 + -1,0,piVar7);
            *piVar7 = iVar14;
            bVar18 = 2;
          }
        } while (!(bool)(bVar18 >> 1 & 1));
        if (iVar9 < 1) {
          std__string___Rep___M_destroy((unsigned char *)(local_6c + -0xc));
        }
        if (local_12c != (char *)0x0) {
LAB_97b9caf4:
          iVar9 = ((int (*)())TParseContext__voidErrorCheck)(param_1,(int)param_2,param_3,(unsigned char *)&STACKARG(0x24));
          if (iVar9 != 0) {
            return 1;
          }
          return 0;
        }
        if (piVar17 != (int *)0x0) {
          (**(code **)(*piVar17 + 4))(piVar17);
        }
        iVar14 = *(int *)(param_3 + 4);
        iVar9 = *(int *)(iVar14 + -0xc);
        cVar13 = *DAT_a7b7ba18;
        pcVar15 = "INTERNAL ERROR inserting new symbol";
      }
      else {
        iVar9 = (**(code **)(*piVar16 + 0x10))(piVar16);
        if (iVar9 == 0) {
          iVar14 = *(int *)(param_3 + 4);
          iVar9 = *(int *)(iVar14 + -0xc);
          cVar13 = *DAT_a7b7ba18;
          pcVar15 = "variable expected";
        }
        else {
          iVar9 = (**(code **)(piVar16[3] + 0x38))(piVar16 + 3);
          if (iVar9 == 0) {
            iVar14 = *(int *)(param_3 + 4);
            iVar9 = *(int *)(iVar14 + -0xc);
            cVar13 = *DAT_a7b7ba18;
            pcVar15 = "redeclaring non-array as array";
          }
          else if (piVar16[4] < 1) {
            local_10c = (uStack00000034 & 1) << 9 |
                        (uStack00000030 & 1) << 10 |
                        (uStack0000002c & 0xff) << 0xb |
                        (uStack00000024 & 0x3f) << 0x13 | uStack00000028 << 0x19 | local_10c & 0x1ff
            ;
            local_c8 = in_stack_0000003c;
            local_130 = (unsigned char *)&PTR__TType_a7b7d4d0;
            local_110 = (unsigned char *)0x0;
            local_100 = uStack00000024;
            local_fc = uStack00000028;
            local_f8 = uStack0000002c;
            local_f4 = uStack00000030;
            local_f0 = uStack00000034;
            local_ec = in_stack_00000038;
            local_e8 = in_stack_0000003c;
            local_e0 = uStack00000024;
            local_dc = (int *)uStack00000028;
            local_d8 = uStack0000002c;
            local_d4 = uStack00000030;
            local_d0 = uStack00000034;
            local_cc = in_stack_00000038;
            local_12c = (char *)0x0;
            local_128 = 0;
            local_124 = (char *)0x0;
            local_120 = (unsigned char *)0x0;
            local_11c = (char *)0x0;
            local_118 = (char *)0x0;
            local_114 = (char *)0x0;
            psVar12 = local_120;
            if (in_stack_00000038 != (int *)0x0) {
              local_128 = in_stack_00000038[2];
              local_118 = (char *)TType__setStructSize((unsigned char *)&local_130);
              iVar9 = (**(code **)(*local_cc + 0x18))(local_cc);
              *(char *)(*(int *)(iVar9 + 4) + *(int *)(*(int *)(iVar9 + 4) + -0xc)) = *DAT_a7b7ba18;
              pcVar15 = *(char **)(iVar9 + 4);
              uVar10 = ((int (*)())GetGlobalPoolAllocator)();
              psVar11 = (unsigned char *)TPoolAllocator__allocate(uVar10);
              psVar12 = (unsigned char *)0x0;
              if (psVar11 != (unsigned char *)0x0) {
                local_50[0] = ((int (*)())GetGlobalPoolAllocator)();
                std__string__string(psVar11,pcVar15,(unsigned char *)local_50);
                psVar12 = psVar11;
              }
            }
            local_120 = psVar12;
            bVar3 = false;
            if (((piVar16[0xc] & 0x1fffe00U) == (local_10c & 0x1fffe00)) &&
               (piVar16[5] == local_128)) {
              bVar3 = true;
            }
            local_130 = (unsigned char *)&PTR__TType_a7b7d4d0;
            if (bVar3) {
              for (iVar9 = piVar16[0xf]; iVar9 != 0; iVar9 = *(int *)(iVar9 + 0x20)) {
                if (*(int *)piVar7[0xc] < *(int *)(iVar9 + 0x1c)) {
                  iVar14 = *(int *)(param_3 + 4);
                  iVar9 = *(int *)(iVar14 + -0xc);
                  cVar13 = *DAT_a7b7ba18;
                  pcVar15 = "higher index value already used for the array";
                  goto LAB_97b9cb40;
                }
                *(int *)(iVar9 + 4) = *(int *)piVar7[0xc];
                *(uint *)(iVar9 + 0x24) = *(uint *)(iVar9 + 0x24) | 0x200;
              }
              if (!bVar1) {
                piVar16[4] = *(int *)piVar7[0xc];
                piVar16[0xc] = piVar16[0xc] | 0x200;
              }
              goto LAB_97b9caf4;
            }
            iVar14 = *(int *)(param_3 + 4);
            iVar9 = *(int *)(iVar14 + -0xc);
            cVar13 = *DAT_a7b7ba18;
            pcVar15 = "redeclaration of array with a different type";
          }
          else {
            iVar14 = *(int *)(param_3 + 4);
            iVar9 = *(int *)(iVar14 + -0xc);
            cVar13 = *DAT_a7b7ba18;
            pcVar15 = "redeclaration of array with size";
          }
        }
      }
    }
    else {
      iVar14 = *(int *)(param_3 + 4);
      iVar9 = *(int *)(iVar14 + -0xc);
      cVar13 = *DAT_a7b7ba18;
      pcVar15 = "array size must be a positive integer";
    }
LAB_97b9cb40:
    *(char *)(iVar14 + iVar9) = cVar13;
    error((int)param_1,param_2,pcVar15,*(char **)(param_3 + 4),"");
  }
  else {
    local_fc = (param_8 & 1) << 9 |
               (param_7 & 1) << 10 |
               (param_6 & 0xff) << 0xb |
               (param_4 & 0x3f) << 0x13 | param_5 << 0x19 | local_fc & 0x1ff;
    local_b8 = in_stack_0000003c;
    local_120 = (unsigned char *)&PTR__TType_a7b7d4d0;
    local_110 = (unsigned char *)0x0;
    local_100 = 0;
    local_dc = in_stack_00000038;
    local_d8 = in_stack_0000003c;
    local_bc = in_stack_00000038;
    local_11c = (char *)0x0;
    local_118 = (char *)0x0;
    local_114 = (char *)0x0;
    local_10c = 0;
    local_108 = 0;
    local_104 = 0;
    uStack00000034 = param_8;
    psVar12 = local_110;
    local_f0 = param_4;
    local_ec = (int *)param_5;
    local_e8 = param_6;
    local_e4 = param_7;
    local_e0 = param_8;
    local_d0 = param_4;
    local_cc = (int *)param_5;
    local_c8 = param_6;
    local_c4 = param_7;
    local_c0 = param_8;
    if (in_stack_00000038 != (int *)0x0) {
      local_118 = (char *)in_stack_00000038[2];
      local_108 = TType__setStructSize((unsigned char *)&local_120);
      iVar9 = (**(code **)(*local_bc + 0x18))(local_bc);
      *(char *)(*(int *)(iVar9 + 4) + *(int *)(*(int *)(iVar9 + 4) + -0xc)) = *DAT_a7b7ba18;
      pcVar15 = *(char **)(iVar9 + 4);
      uVar10 = ((int (*)())GetGlobalPoolAllocator)();
      psVar11 = (unsigned char *)TPoolAllocator__allocate(uVar10);
      in_cr0 = (psVar11 == (unsigned char *)0x0) << 1;
      psVar12 = (unsigned char *)0x0;
      if (psVar11 != (unsigned char *)0x0) {
        local_b0[0] = ((int (*)())GetGlobalPoolAllocator)();
        std__string__string(psVar11,pcVar15,(unsigned char *)local_b0);
        psVar12 = psVar11;
      }
    }
    local_110 = psVar12;
    TType__getCompleteString();
    local_12c[*(int *)(local_12c + -0xc)] = *DAT_a7b7ba18;
    error((int)param_1,param_2,"cannot declare arrays of this type",local_12c,"");
    piVar7 = (int *)(local_12c + -4);
    local_a0 = local_130;
    do {
      iVar9 = *piVar7;
      if (in_RESERVE != '\0') {
        iVar14 = storeWordConditionalIndexed(iVar9 + -1,0,piVar7);
        *piVar7 = iVar14;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar9 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_12c + -0xc));
    }
  }
  return 1;
}

/* TParseContext__arraySetMaxSize @ 0x97b9cb78 (848 bytes) */
int TParseContext__arraySetMaxSize(this, param_1, param_2, param_3, param_4, param_5)
  unsigned char *this;
  unsigned char *param_1;
  unsigned char *param_2;
  int param_3;
  int param_4;
  int param_5;
{
  int iVar1;
  char *pcVar2;
  ulong uVar3;
  undefined4 uVar4;
  undefined3 in_register_0000001c;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  char in_RESERVE;
  byte in_cr0;
  int local_e0 [4];
  undefined4 local_d0;
  int local_cc;
  undefined4 local_c0 [4];
  undefined4 local_b0;
  uint local_50;
  
  local_50 = 0;
  piVar6 = *(int **)(this + 4);
  (**(code **)(*(int *)param_1 + 0x60))(param_1);
  iVar5 = *piVar6;
  iVar1 = (piVar6[1] - iVar5 >> 2) + -1;
  while( true ) {
    iVar7 = *(int *)(iVar5 + iVar1 * 4);
    iVar5 = 0;
    std::
    _Rb_tree<std::string,std::pair<std::string_const,TSymbol*>,std::_Select1st<std::pair<std::string_const,TSymbol*>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,TSymbol*>>>
    ::find((unsigned char *)local_e0);
    if (local_e0[0] != *(int *)(iVar7 + 4)) {
      iVar5 = *(int *)(local_e0[0] + 0x18);
    }
    if ((iVar5 != 0) || (iVar1 + -1 < 0)) break;
    iVar5 = *piVar6;
    iVar1 = iVar1 + -1;
  }
  if (&STACKARG(0x0) != (undefined1 *)0x50) {
    local_50 = (uint)(iVar1 == 0);
  }
  if (iVar5 != 0) {
    *(undefined4 *)(param_2 + 0x20) = *(undefined4 *)(iVar5 + 0x3c);
    *(TType **)(iVar5 + 0x3c) = param_2;
    pcVar2 = (char *)(**(code **)(*(int *)param_1 + 0x60))(param_1);
    iVar1 = std__string__compare(pcVar2);
    if (iVar1 == 0) {
      piVar6 = *(int **)(this + 4);
      local_c0[0] = ((int (*)())GetGlobalPoolAllocator)();
      std__string__string((unsigned char *)&local_d0,"gl_MaxTextureCoords",(unsigned char *)local_c0);
      iVar7 = *piVar6;
      iVar1 = (piVar6[1] - iVar7 >> 2) + -1;
      while( true ) {
        iVar8 = *(int *)(iVar7 + iVar1 * 4);
        iVar7 = 0;
        std::
        _Rb_tree<std::string,std::pair<std::string_const,TSymbol*>,std::_Select1st<std::pair<std::string_const,TSymbol*>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,TSymbol*>>>
        ::find((unsigned char *)local_e0);
        if (local_e0[0] != *(int *)(iVar8 + 4)) {
          iVar7 = *(int *)(local_e0[0] + 0x18);
        }
        if ((iVar7 != 0) || (iVar1 + -1 < 0)) break;
        iVar7 = *piVar6;
        iVar1 = iVar1 + -1;
      }
      if (&STACKARG(0x0) != (undefined1 *)0x50) {
        local_50 = (uint)(iVar1 == 0);
      }
      piVar6 = (int *)(local_cc + -4);
      local_b0 = local_d0;
      do {
        iVar1 = *piVar6;
        if (in_RESERVE != '\0') {
          iVar8 = storeWordConditionalIndexed(iVar1 + -1,0,piVar6);
          *piVar6 = iVar8;
          in_cr0 = 2;
        }
      } while (!(bool)(in_cr0 >> 1 & 1));
      if (iVar1 < 1) {
        std__string___Rep___M_destroy((unsigned char *)(local_cc + -0xc));
      }
      if (iVar7 == 0) {
                    
                    
        uVar4 = (*(code *)(((unsigned char *)0x97b9cdd0) + (*(unsigned char *)0x97b9cddc)))();
        return uVar4;
      }
      piVar6 = *(int **)(iVar7 + 0x38);
      if (piVar6 == (int *)0x0) {
        uVar3 = ((int (*)())GetGlobalPoolAllocator)();
        piVar6 = (int *)TPoolAllocator__allocate(uVar3);
        *(int **)(iVar7 + 0x38) = piVar6;
      }
      if (*piVar6 <= param_3) {
        error((int)this,(char *)param_5,"","[",
              "gl_TexCoord can only have a max array size of up to gl_MaxTextureCoords","");
        goto LAB_97b9cf84;
      }
    }
    uVar4 = 0;
    if (CONCAT31(in_register_0000001c,param_4) != 0) {
      iVar1 = *(int *)(param_2 + 0x20);
      iVar7 = param_3 + 1;
      *(int *)(iVar5 + 0x28) = iVar7;
      *(int *)(param_2 + 0x1c) = iVar7;
      while (iVar1 != 0) {
        *(int *)(iVar1 + 0x1c) = iVar7;
        iVar1 = *(int *)(iVar1 + 0x20);
      }
      uVar4 = 0;
    }
  }
  else {
    iVar1 = (**(code **)(*(int *)param_1 + 0x60))(param_1);
    *(undefined1 *)(*(int *)(iVar1 + 4) + *(int *)(*(int *)(iVar1 + 4) + -0xc)) = *DAT_a7b7ba18;
    error((int)this,(char *)param_5," undeclared identifier",*(char **)(iVar1 + 4),"");
LAB_97b9cf84:
    uVar4 = 1;
  }
  return uVar4;
}

/* TParseContext__nonInitErrorCheck @ 0x97b9cfe8 (1008 bytes) */
int TParseContext__nonInitErrorCheck(this, param_1, param_2, param_3)
  unsigned char *this;
  int param_1;
  unsigned char *param_2;
  unsigned char *param_3;
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  ulong uVar9;
  int *piVar10;
  int iVar11;
  string *this_00;
  string *psVar12;
  char *pcVar13;
  char in_RESERVE;
  byte in_cr0;
  string *local_d0;
  int local_cc;
  int local_c8;
  int local_c4;
  string *local_c0;
  int local_bc;
  int local_b8;
  int local_b4;
  int local_b0;
  uint local_ac;
  uint local_a0;
  int local_9c;
  uint local_98;
  uint local_94;
  uint local_90;
  int *local_8c;
  undefined4 local_88;
  uint local_80;
  int local_7c;
  uint local_78;
  uint local_74;
  uint local_70;
  int *local_6c;
  undefined4 local_68;
  undefined4 local_60 [4];
  undefined4 local_50;
  int local_4c;
  int *local_48;
  undefined4 local_40;
  
  iVar8 = ((int (*)())TParseContext__reservedErrorCheck)(this,param_1,param_2);
  if (iVar8 != 0) {
    ((int (*)())TParseContext__recover)(this);
  }
  iVar8 = *(int *)(param_3 + 4);
  if (iVar8 == 2) {
    *(undefined4 *)(param_3 + 4) = 0;
  }
  uVar9 = ((int (*)())GetGlobalPoolAllocator)();
  piVar10 = (int *)TPoolAllocator__allocate(uVar9);
  local_8c = *(int **)(param_3 + 0x14);
  local_9c = *(int *)(param_3 + 4);
  local_a0 = *(uint *)param_3;
  local_98 = *(uint *)(param_3 + 8);
  local_94 = *(uint *)(param_3 + 0xc);
  local_90 = *(uint *)(param_3 + 0x10);
  local_88 = *(undefined4 *)(param_3 + 0x18);
  local_ac = (local_90 & 1) << 9 |
             (local_94 & 1) << 10 |
             (local_98 & 0xff) << 0xb |
             (local_a0 & 0x3f) << 0x13 | local_9c << 0x19 | local_ac & 0x1ff;
  local_d0 = (unsigned char *)&PTR__TType_a7b7d4d0;
  local_b0 = 0;
  local_cc = 0;
  local_c8 = 0;
  local_c4 = 0;
  local_c0 = (unsigned char *)0x0;
  local_bc = 0;
  local_b8 = 0;
  local_b4 = 0;
  psVar12 = local_c0;
  local_80 = local_a0;
  local_7c = local_9c;
  local_78 = local_98;
  local_74 = local_94;
  local_70 = local_90;
  local_6c = local_8c;
  local_68 = local_88;
  if (local_8c != (int *)0x0) {
    local_c8 = local_8c[2];
    local_b8 = TType__setStructSize((unsigned char *)&local_d0);
    iVar11 = (**(code **)(*local_6c + 0x18))(local_6c);
    *(undefined1 *)(*(int *)(iVar11 + 4) + *(int *)(*(int *)(iVar11 + 4) + -0xc)) = *DAT_a7b7ba18;
    pcVar13 = *(char **)(iVar11 + 4);
    uVar9 = ((int (*)())GetGlobalPoolAllocator)();
    this_00 = (unsigned char *)TPoolAllocator__allocate(uVar9);
    in_cr0 = (this_00 == (unsigned char *)0x0) << 1;
    psVar12 = (unsigned char *)0x0;
    if (this_00 != (unsigned char *)0x0) {
      local_60[0] = ((int (*)())GetGlobalPoolAllocator)();
      std__string__string(this_00,pcVar13,(unsigned char *)local_60);
      psVar12 = this_00;
    }
  }
  local_c0 = psVar12;
  piVar10[1] = (int)param_2;
  *piVar10 = (int)(PTR_vtable_a7b7c0b4 + 8);
  piVar10[4] = local_cc;
  piVar10[5] = local_c8;
  piVar10[6] = local_c4;
  piVar10[7] = (int)local_c0;
  piVar10[8] = local_bc;
  piVar10[9] = local_b8;
  piVar10[3] = (int)&PTR__TType_a7b7d4d0;
  piVar10[10] = local_b4;
  piVar10[0xb] = local_b0;
  uVar6 = piVar10[0xc];
  uVar3 = local_ac & 0xfe000000;
  piVar10[0xc] = uVar3 | uVar6 & 0x1ffffff;
  uVar4 = (local_ac >> 0x13 & 0x3f) << 0x13;
  piVar10[0xc] = uVar4 | uVar3 | uVar6 & 0x7ffff;
  uVar2 = local_ac & 0x7f800;
  piVar10[0xc] = uVar2 | uVar4 | uVar3 | uVar6 & 0x7ff;
  uVar5 = (local_ac >> 10 & 1) << 10;
  piVar10[0xc] = uVar5 | uVar2 | uVar4 | uVar3 | uVar6 & 0x3ff;
  piVar10[0xc] = (local_ac >> 9 & 1) << 9 | uVar5 | uVar2 | uVar4 | uVar3 | uVar6 & 0x1ff;
  piVar10[0xd] = 0;
  piVar10[0xe] = 0;
  piVar10[0xf] = 0;
  local_d0 = (unsigned char *)&PTR__TType_a7b7d4d0;
  iVar11 = *(int *)(*(int *)(this + 4) + 0xc) + 1;
  *(int *)(*(int *)(this + 4) + 0xc) = iVar11;
  piVar10[2] = iVar11;
  local_cc = 0;
  psVar12 = (unsigned char *)(**(code **)(*piVar10 + 8))(piVar10);
  std__string__string((unsigned char *)&local_50,psVar12);
  local_48 = piVar10;
  std::
  _Rb_tree<std::string,std::pair<std::string_const,TSymbol*>,std::_Select1st<std::pair<std::string_const,TSymbol*>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,TSymbol*>>>
  ::insert_unique((unsigned char *)&local_c0);
  local_d0 = local_c0;
  piVar7 = (int *)(local_4c + -4);
  local_cc = local_bc;
  local_40 = local_50;
  do {
    iVar11 = *piVar7;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar11 + -1,0,piVar7);
      *piVar7 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar11 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(local_4c + -0xc));
  }
  if (local_cc == 0) {
    iVar8 = piVar10[1];
    iVar11 = *(int *)(iVar8 + 4);
    *(undefined1 *)(iVar11 + *(int *)(iVar11 + -0xc)) = *DAT_a7b7ba18;
    error((int)this,(char *)param_1,"redefinition",*(char **)(iVar8 + 4),"");
    if (piVar10 != (int *)0x0) {
      (**(code **)(*piVar10 + 4))(piVar10);
    }
  }
  else {
    if (iVar8 != 2) {
      iVar8 = ((int (*)())TParseContext__voidErrorCheck)(this,param_1,param_2,param_3);
      return iVar8 != 0;
    }
    *(undefined1 *)(*(int *)(param_2 + 4) + *(int *)(*(int *)(param_2 + 4) + -0xc)) = *DAT_a7b7ba18;
    error((int)this,(char *)param_1,"variables with qualifier \'const\' must be initialized",
          *(char **)(param_2 + 4),"");
  }
  return true;
}

/* TParseContext__paramErrorCheck @ 0x97b9d3d8 (216 bytes) */
int TParseContext__paramErrorCheck(this, param_1, param_3, param_4, param_5)
  unsigned char *this;
  char *param_1;
  int param_3;
  int param_4;
  int *param_5;
{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  
  if (param_3 == 2) {
    if (param_4 == 9) {
      iVar1 = *param_5;
      param_4 = 0xc;
      goto LAB_97b9d48c;
    }
    pcVar2 = (char *)getQualifierString(2);
    pcVar4 = (char *)getQualifierString(param_4);
    pcVar3 = "qualifier not allowed with ";
  }
  else {
    if (param_3 == 0) {
      iVar1 = *param_5;
LAB_97b9d48c:
      (**(code **)(iVar1 + 0x28))(param_5,param_4);
      return 0;
    }
    pcVar2 = (char *)getQualifierString(param_3);
    pcVar3 = "qualifier not allowed on function parameter";
    pcVar4 = "";
  }
  error((int)this,param_1,pcVar3,pcVar2,pcVar4);
  return 1;
}

/* TParseContext__extensionErrorCheck @ 0x97b9d4b0 (920 bytes) */
int TParseContext__extensionErrorCheck(this, param_1, param_2)
  unsigned char *this;
  int param_1;
  char *param_2;
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  code *UNRECOVERED_JUMPTABLE;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  char in_RESERVE;
  byte in_cr0;
  undefined4 local_1d0;
  void *local_1cc;
  int local_1c0 [4];
  int local_1b0;
  int local_1ac;
  int local_1a0 [4];
  int local_190 [4];
  int local_180 [4];
  undefined4 local_170;
  int local_16c;
  undefined4 local_168;
  int local_160 [4];
  undefined4 local_150;
  undefined4 local_140;
  string asStack_130 [16];
  undefined4 local_120 [40];
  undefined4 local_80 [4];
  undefined4 local_70;
  int local_6c;
  undefined4 local_68;
  undefined4 local_60;
  undefined4 local_50;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  
  local_1c0[0] = ((int (*)())GetGlobalPoolAllocator)();
  std__string__string((unsigned char *)&local_1d0,param_2,(unsigned char *)local_1c0);
  std::
  _Rb_tree<std::string,std::pair<std::string_const,TBehavior>,std::_Select1st<std::pair<std::string_const,TBehavior>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,TBehavior>>>
  ::lower_bound((unsigned char *)&local_1b0);
  iVar7 = local_1b0;
  local_1a0[0] = *(int *)(this + 0x34);
  if (local_1b0 == local_1a0[0]) {
LAB_97b9d574:
    local_180[0] = iVar7;
    std__string__string((unsigned char *)&local_170,(unsigned char *)&local_1d0);
    local_168 = 0;
    local_160[0] = local_180[0];
    std::
    _Rb_tree<std::string,std::pair<std::string_const,TBehavior>,std::_Select1st<std::pair<std::string_const,TBehavior>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,TBehavior>>>
    ::insert_unique(local_190,this + 0x30,local_160,(unsigned char *)&local_170);
    piVar3 = (int *)(local_16c + -4);
    local_1b0 = local_190[0];
    local_150 = local_170;
    do {
      iVar4 = *piVar3;
      if (in_RESERVE != '\0') {
        iVar7 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
        *piVar3 = iVar7;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    iVar7 = local_190[0];
    if (iVar4 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_16c + -0xc));
      iVar7 = local_1b0;
    }
  }
  else {
    puVar5 = &local_3c;
    uVar8 = *(uint *)((int)local_1cc + -0xc);
    local_40 = uVar8;
    uVar6 = *(uint *)(*(int *)(local_1b0 + 0x14) + -0xc);
    local_3c = uVar6;
    if (uVar8 <= uVar6) {
      puVar5 = &local_40;
    }
    iVar4 = _memcmp(local_1cc,*(void **)(local_1b0 + 0x14),*puVar5);
    in_cr0 = (iVar4 == 0) << 1;
    if (iVar4 == 0) {
      iVar4 = uVar8 - uVar6;
    }
    if (iVar4 < 0) goto LAB_97b9d574;
  }
  iVar7 = *(int *)(iVar7 + 0x18);
  piVar3 = (int *)((int)local_1cc + -4);
  local_140 = local_1d0;
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar4 < 1) {
    std__string___Rep___M_destroy((unsigned char *)((int)local_1cc + -0xc));
  }
  if (iVar7 == 2) {
    local_120[0] = ((int (*)())GetGlobalPoolAllocator)();
    std__string__string(asStack_130,param_2,(unsigned char *)local_120);
    std__operator_((char *)local_1a0,(unsigned char *)"extension ");
    std__string__string((unsigned char *)&local_1b0,(unsigned char *)local_1a0);
    _strlen(" is being used");
    std__string__append((char *)&local_1b0,0x97c29948);
    UNRECOVERED_JUMPTABLE = (code *)(((unsigned char *)0x97b9d6c4) + (*(unsigned char *)0x97b9d6c8));
    *(undefined1 *)(local_1ac + *(int *)(local_1ac + -0xc)) = *DAT_a7b7ba18;
                    
                    
    uVar6 = (*UNRECOVERED_JUMPTABLE)();
    return uVar6;
  }
  local_80[0] = ((int (*)())GetGlobalPoolAllocator)();
  std__string__string((unsigned char *)&local_1d0,param_2,(unsigned char *)local_80);
  std::
  _Rb_tree<std::string,std::pair<std::string_const,TBehavior>,std::_Select1st<std::pair<std::string_const,TBehavior>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,TBehavior>>>
  ::lower_bound((unsigned char *)local_1c0);
  iVar7 = local_1c0[0];
  local_1b0 = *(int *)(this + 0x34);
  if (local_1c0[0] != local_1b0) {
    puVar5 = &local_34;
    uVar8 = *(uint *)((int)local_1cc + -0xc);
    local_38 = uVar8;
    uVar6 = *(uint *)(*(int *)(local_1c0[0] + 0x14) + -0xc);
    local_34 = uVar6;
    if (uVar8 <= uVar6) {
      puVar5 = &local_38;
    }
    iVar4 = _memcmp(local_1cc,*(void **)(local_1c0[0] + 0x14),*puVar5);
    in_cr0 = (iVar4 == 0) << 1;
    if (iVar4 == 0) {
      iVar4 = uVar8 - uVar6;
    }
    if (-1 < iVar4) goto LAB_97b9d98c;
  }
  local_190[0] = iVar7;
  std__string__string((unsigned char *)&local_70,(unsigned char *)&local_1d0);
  local_68 = 0;
  local_180[0] = local_190[0];
  std::
  _Rb_tree<std::string,std::pair<std::string_const,TBehavior>,std::_Select1st<std::pair<std::string_const,TBehavior>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,TBehavior>>>
  ::insert_unique(local_1a0,this + 0x30,local_180,(unsigned char *)&local_70);
  piVar3 = (int *)(local_6c + -4);
  local_1c0[0] = local_1a0[0];
  local_60 = local_70;
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar7 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar7;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  iVar7 = local_1a0[0];
  if (iVar4 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(local_6c + -0xc));
    iVar7 = local_1c0[0];
  }
LAB_97b9d98c:
  iVar7 = *(int *)(iVar7 + 0x18);
  piVar3 = (int *)((int)local_1cc + -4);
  local_50 = local_1d0;
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar4 < 1) {
    std__string___Rep___M_destroy((unsigned char *)((int)local_1cc + -0xc));
  }
  bVar1 = iVar7 == 3;
  if (bVar1) {
    error((int)this,(char *)param_1,"extension",param_2,"is disabled");
  }
  return (uint)bVar1;
}

/* TParseContext__findFunction @ 0x97b9da08 (356 bytes) */
int TParseContext__findFunction(this, param_1, param_2, param_3)
  unsigned char *this;
  int param_1;
  unsigned char *param_2;
  bool *param_3;
{
  undefined1 uVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int local_40 [7];
  
  piVar6 = *(int **)(this + 4);
  (**(code **)(*(int *)param_2 + 8))(param_2);
  iVar4 = *piVar6;
  iVar2 = (piVar6[1] - iVar4 >> 2) + -1;
  while( true ) {
    iVar4 = *(int *)(iVar4 + iVar2 * 4);
    std::
    _Rb_tree<std::string,std::pair<std::string_const,TSymbol*>,std::_Select1st<std::pair<std::string_const,TSymbol*>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,TSymbol*>>>
    ::find((unsigned char *)local_40);
    piVar7 = (int *)0x0;
    if (local_40[0] != *(int *)(iVar4 + 4)) {
      piVar7 = *(int **)(local_40[0] + 0x18);
    }
    if ((piVar7 != (int *)0x0) || (iVar2 + -1 < 0)) break;
    iVar4 = *piVar6;
    iVar2 = iVar2 + -1;
  }
  if (param_3 != (bool *)0x0) {
    *(uint *)param_3 = (uint)(iVar2 == 0);
  }
  if (piVar7 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar7 + 0xc))(piVar7);
    if (iVar2 != 0) {
      return piVar7;
    }
    iVar4 = *(int *)(param_2 + 4);
    iVar5 = *(int *)(iVar4 + 4);
    uVar1 = *DAT_a7b7ba18;
    iVar2 = *(int *)(iVar5 + -0xc);
    pcVar3 = "function name expected";
  }
  else {
    iVar4 = *(int *)(param_2 + 4);
    iVar5 = *(int *)(iVar4 + 4);
    uVar1 = *DAT_a7b7ba18;
    iVar2 = *(int *)(iVar5 + -0xc);
    pcVar3 = "no matching overloaded function found";
  }
  *(undefined1 *)(iVar5 + iVar2) = uVar1;
  error((int)this,(char *)param_1,pcVar3,*(char **)(iVar4 + 4),"");
  return (int *)0x0;
}

/* TParseContext__executeInitializer @ 0x97b9db6c (3572 bytes) */
int TParseContext__executeInitializer(this, param_1, param_2, param_3, param_4, param_5)
  unsigned char *this;
  int param_1;
  unsigned char *param_2;
  unsigned char *param_3;
  unsigned char *param_4;
  TIntermNode **param_5;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  ulong uVar7;
  int *piVar8;
  string *psVar9;
  string *psVar10;
  uint uVar11;
  undefined4 uVar12;
  TIntermNode *pTVar13;
  char *pcVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  bool bVar17;
  undefined4 uVar18;
  int iVar19;
  undefined4 *puVar20;
  int *piVar21;
  int iVar22;
  char *pcVar23;
  char in_RESERVE;
  byte bVar24;
  string *local_150;
  uint local_14c;
  uint local_148;
  uint local_144;
  string *local_140;
  uint local_13c;
  uint local_138;
  uint local_134;
  uint local_130;
  uint local_12c;
  undefined **local_120;
  uint local_11c;
  uint local_118;
  uint local_114;
  uint local_110;
  int *local_10c;
  undefined4 local_108;
  undefined **local_100;
  uint local_fc;
  uint local_f8;
  uint local_f4;
  uint local_f0;
  int *local_ec;
  undefined4 local_e8;
  undefined4 local_e0 [4];
  undefined4 local_d0;
  int local_cc;
  int *local_c8;
  undefined4 local_c0;
  undefined **local_b0;
  undefined4 local_a0 [4];
  undefined4 local_90 [4];
  int local_80 [4];
  string *local_70;
  string *local_60;
  string *local_50;
  
  iVar6 = ((int (*)())TParseContext__reservedErrorCheck)(this,param_1,param_2);
  if (iVar6 != 0) {
    return 1;
  }
  local_14c = ((int (*)())TParseContext__voidErrorCheck)(this,param_1,param_2,param_3);
  bVar24 = (local_14c == 0) << 1;
  if (local_14c != 0) {
    return 1;
  }
  uVar7 = ((int (*)())GetGlobalPoolAllocator)();
  piVar8 = (int *)TPoolAllocator__allocate(uVar7);
  local_10c = *(int **)(param_3 + 0x14);
  local_11c = *(uint *)(param_3 + 4);
  local_120 = *(undefined ***)param_3;
  local_118 = *(uint *)(param_3 + 8);
  local_114 = *(uint *)(param_3 + 0xc);
  local_110 = *(uint *)(param_3 + 0x10);
  local_108 = *(undefined4 *)(param_3 + 0x18);
  local_12c = (local_110 & 1) << 9 |
              (local_114 & 1) << 10 |
              (local_118 & 0xff) << 0xb |
              ((uint)local_120 & 0x3f) << 0x13 | local_11c << 0x19 | local_12c & 0x1ff;
  local_150 = (unsigned char *)&PTR__TType_a7b7d4d0;
  local_148 = 0;
  local_138 = 0;
  local_144 = local_14c;
  psVar10 = (unsigned char *)0x0;
  local_13c = local_14c;
  local_134 = local_14c;
  local_130 = local_14c;
  local_100 = local_120;
  local_fc = local_11c;
  local_f8 = local_118;
  local_f4 = local_114;
  local_f0 = local_110;
  local_ec = local_10c;
  local_e8 = local_108;
  if (local_10c != (int *)0x0) {
    local_148 = local_10c[2];
    local_140 = (unsigned char *)local_14c;
    local_138 = local_14c;
    local_138 = TType__setStructSize((unsigned char *)&local_150);
    iVar6 = (**(code **)(*local_ec + 0x18))(local_ec);
    *(undefined1 *)(*(int *)(iVar6 + 4) + *(int *)(*(int *)(iVar6 + 4) + -0xc)) = *DAT_a7b7ba18;
    pcVar23 = *(char **)(iVar6 + 4);
    uVar7 = ((int (*)())GetGlobalPoolAllocator)();
    psVar9 = (unsigned char *)TPoolAllocator__allocate(uVar7);
    bVar24 = (psVar9 == (unsigned char *)0x0) << 1;
    psVar10 = (unsigned char *)0x0;
    if (psVar9 != (unsigned char *)0x0) {
      local_e0[0] = ((int (*)())GetGlobalPoolAllocator)();
      std__string__string(psVar9,pcVar23,(unsigned char *)local_e0);
      psVar10 = psVar9;
    }
  }
  local_140 = psVar10;
  piVar8[1] = (int)param_2;
  piVar21 = piVar8 + 3;
  *piVar8 = (int)(PTR_vtable_a7b7c0b4 + 8);
  piVar8[4] = local_14c;
  piVar8[5] = local_148;
  piVar8[6] = local_144;
  piVar8[7] = (int)local_140;
  piVar8[8] = local_13c;
  piVar8[9] = local_138;
  piVar8[3] = (int)&PTR__TType_a7b7d4d0;
  piVar8[10] = local_134;
  piVar8[0xb] = local_130;
  uVar4 = piVar8[0xc];
  uVar1 = local_12c & 0xfe000000;
  piVar8[0xc] = uVar1 | uVar4 & 0x1ffffff;
  uVar2 = (local_12c >> 0x13 & 0x3f) << 0x13;
  piVar8[0xc] = uVar2 | uVar1 | uVar4 & 0x7ffff;
  uVar11 = local_12c & 0x7f800;
  piVar8[0xc] = uVar11 | uVar2 | uVar1 | uVar4 & 0x7ff;
  uVar3 = (local_12c >> 10 & 1) << 10;
  piVar8[0xc] = uVar3 | uVar11 | uVar2 | uVar1 | uVar4 & 0x3ff;
  piVar8[0xc] = (local_12c >> 9 & 1) << 9 | uVar3 | uVar11 | uVar2 | uVar1 | uVar4 & 0x1ff;
  piVar8[0xd] = 0;
  piVar8[0xe] = 0;
  piVar8[0xf] = 0;
  local_150 = (unsigned char *)&PTR__TType_a7b7d4d0;
  iVar6 = *(int *)(*(int *)(this + 4) + 0xc) + 1;
  *(int *)(*(int *)(this + 4) + 0xc) = iVar6;
  piVar8[2] = iVar6;
  local_14c = 0;
  psVar10 = (unsigned char *)(**(code **)(*piVar8 + 8))(piVar8);
  std__string__string((unsigned char *)&local_d0,psVar10);
  local_c8 = piVar8;
  std::
  _Rb_tree<std::string,std::pair<std::string_const,TSymbol*>,std::_Select1st<std::pair<std::string_const,TSymbol*>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,TSymbol*>>>
  ::insert_unique((unsigned char *)&local_140);
  local_150 = local_140;
  piVar5 = (int *)(local_cc + -4);
  local_14c = local_13c;
  local_c0 = local_d0;
  do {
    iVar6 = *piVar5;
    if (in_RESERVE != '\0') {
      iVar19 = storeWordConditionalIndexed(iVar6 + -1,0,piVar5);
      *piVar5 = iVar19;
      bVar24 = 2;
    }
  } while (!(bool)(bVar24 >> 1 & 1));
  if (iVar6 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(local_cc + -0xc));
  }
  if (local_14c == 0) {
    iVar6 = piVar8[1];
    iVar19 = *(int *)(iVar6 + 4);
    pcVar14 = "redefinition";
    *(undefined1 *)(iVar19 + *(int *)(iVar19 + -0xc)) = *DAT_a7b7ba18;
    pcVar23 = *(char **)(iVar6 + 4);
    goto LAB_97b9df14;
  }
  uVar11 = (**(code **)(piVar8[3] + 0x24))(piVar21);
  if (2 < uVar11) {
    pcVar23 = (char *)getQualifierString((uint)piVar8[0xc] >> 0x19);
    pcVar14 = " cannot initialize this type of qualifier ";
    goto LAB_97b9df14;
  }
  if (uVar11 != 2) {
    uVar12 = TIntermediate__addSymbol
                       (*(int *)this,(unsigned char *)piVar8[2],(unsigned char *)piVar8[1],(int)piVar21);
    pTVar13 = (unsigned char *)
              TIntermediate__addAssign(*(undefined4 *)this,0x76,uVar12,param_4,param_1);
    *param_5 = pTVar13;
    if (pTVar13 != (unsigned char *)0x0) {
      return 0;
    }
    TType__getCompleteString();
    TType__getCompleteString();
    ((int (*)())TParseContext__assignError)(this,param_1,"=",(unsigned char *)&local_140,&local_150);
    piVar8 = (int *)(local_13c - 4);
    local_60 = local_140;
    do {
      iVar6 = *piVar8;
      if (in_RESERVE != '\0') {
        iVar19 = storeWordConditionalIndexed(iVar6 + -1,0,piVar8);
        *piVar8 = iVar19;
        bVar24 = 2;
      }
    } while (!(bool)(bVar24 >> 1 & 1));
    if (iVar6 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_13c - 0xc));
    }
    piVar8 = (int *)(local_14c - 4);
    local_50 = local_150;
    do {
      iVar6 = *piVar8;
      if (in_RESERVE != '\0') {
        iVar19 = storeWordConditionalIndexed(iVar6 + -1,0,piVar8);
        *piVar8 = iVar19;
        bVar24 = 2;
      }
    } while (!(bool)(bVar24 >> 1 & 1));
    if (0 < iVar6) {
      return 1;
    }
    std__string___Rep___M_destroy((unsigned char *)(local_14c - 0xc));
    return 1;
  }
  (**(code **)(*(int *)param_4 + 0x38))((unsigned char *)&local_150,param_4);
  local_150 = (unsigned char *)&PTR__TType_a7b7d4d0;
  uVar11 = -((int)-(local_12c >> 0x19 ^ 2) >> 0x1f);
  bVar24 = (uVar11 == 0) << 1;
  if (uVar11 != 0) {
    TType__getCompleteString();
    *(undefined1 *)(local_11c + *(int *)(local_11c - 0xc)) = *DAT_a7b7ba18;
    error((int)this,(char *)param_1," assigning non-constant to","=","\'%s\'",local_11c);
    piVar5 = (int *)(local_11c - 4);
    do {
      iVar6 = *piVar5;
      if (in_RESERVE != '\0') {
        iVar19 = storeWordConditionalIndexed(iVar6 + -1,0,piVar5);
        *piVar5 = iVar19;
        bVar24 = 2;
      }
      local_b0 = local_120;
      uVar11 = local_11c;
    } while (!(bool)(bVar24 >> 1 & 1));
joined_r0x97b9dfd0:
    if (iVar6 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(uVar11 - 0xc));
    }
LAB_97b9e184:
    (**(code **)(piVar8[3] + 0x28))(piVar21,0);
    return 1;
  }
  local_10c = *(int **)(param_3 + 0x14);
  local_11c = *(uint *)(param_3 + 4);
  local_120 = *(undefined ***)param_3;
  local_118 = *(uint *)(param_3 + 8);
  local_114 = *(uint *)(param_3 + 0xc);
  local_110 = *(uint *)(param_3 + 0x10);
  local_108 = *(undefined4 *)(param_3 + 0x18);
  local_12c = (local_110 & 1) << 9 |
              (local_114 & 1) << 10 |
              (local_118 & 0xff) << 0xb |
              ((uint)local_120 & 0x3f) << 0x13 | local_11c << 0x19 | local_12c & 0x1ff;
  local_150 = (unsigned char *)&PTR__TType_a7b7d4d0;
  local_148 = 0;
  local_138 = 0;
  bVar24 = 2;
  local_14c = uVar11;
  local_144 = uVar11;
  psVar10 = (unsigned char *)0x0;
  local_13c = uVar11;
  local_134 = uVar11;
  local_130 = uVar11;
  local_100 = local_120;
  local_fc = local_11c;
  local_f8 = local_118;
  local_f4 = local_114;
  local_f0 = local_110;
  local_ec = local_10c;
  local_e8 = local_108;
  if (local_10c != (int *)0x0) {
    local_148 = local_10c[2];
    local_140 = (unsigned char *)uVar11;
    local_138 = uVar11;
    local_138 = TType__setStructSize((unsigned char *)&local_150);
    iVar6 = (**(code **)(*local_ec + 0x18))(local_ec);
    *(undefined1 *)(*(int *)(iVar6 + 4) + *(int *)(*(int *)(iVar6 + 4) + -0xc)) = *DAT_a7b7ba18;
    pcVar23 = *(char **)(iVar6 + 4);
    uVar7 = ((int (*)())GetGlobalPoolAllocator)();
    psVar9 = (unsigned char *)TPoolAllocator__allocate(uVar7);
    bVar24 = (psVar9 == (unsigned char *)0x0) << 1;
    psVar10 = (unsigned char *)0x0;
    if (psVar9 != (unsigned char *)0x0) {
      local_a0[0] = ((int (*)())GetGlobalPoolAllocator)();
      std__string__string(psVar9,pcVar23,(unsigned char *)local_a0);
      psVar10 = psVar9;
    }
  }
  local_140 = psVar10;
  (**(code **)(*(int *)param_4 + 0x38))(&local_120,param_4);
  bVar17 = false;
  if (((local_12c & 0x1fffe00) == (local_fc & 0x1fffe00)) && (local_148 == local_118)) {
    bVar17 = true;
  }
  local_150 = (unsigned char *)&PTR__TType_a7b7d4d0;
  local_120 = &PTR__TType_a7b7d4d0;
  if (!bVar17) {
    pcVar23 = (char *)getQualifierString((uint)piVar8[0xc] >> 0x19);
    error((int)this,(char *)param_1," non-matching types for const initializer ",pcVar23,"");
    goto LAB_97b9e184;
  }
  iVar6 = (**(code **)(*(int *)param_4 + 0x18))(param_4);
  if (iVar6 == 0) {
    iVar6 = (**(code **)(*(int *)param_4 + 0x1c))(param_4);
    if (iVar6 != 0) {
      iVar6 = piVar8[0xe];
      if (iVar6 == 0) {
        uVar7 = ((int (*)())GetGlobalPoolAllocator)();
        iVar6 = TPoolAllocator__allocate(uVar7);
        piVar8[0xe] = iVar6;
      }
      piVar5 = (int *)(**(code **)(*(int *)param_4 + 0x1c))(param_4);
      iVar19 = (**(code **)(*piVar5 + 100))();
      if (*(int *)(iVar19 + 8) - *(int *)(iVar19 + 4) >> 2 == 1) {
        piVar5 = (int *)(**(code **)(*(int *)param_4 + 0x1c))(param_4);
        iVar19 = (**(code **)(*piVar5 + 100))();
        piVar5 = (int *)(**(code **)(*(int *)**(undefined4 **)(iVar19 + 4) + 0x14))();
        iVar19 = (**(code **)(*piVar5 + 0x18))();
        if (iVar19 != 0) {
          local_14c = piVar8[4];
          local_148 = piVar8[5];
          local_144 = piVar8[6];
          local_13c = piVar8[8];
          local_138 = piVar8[9];
          local_134 = piVar8[10];
          local_130 = piVar8[0xb];
          local_140 = (unsigned char *)piVar8[7];
          local_150 = (unsigned char *)&PTR__TType_a7b7d4d0;
          local_12c = ((uint)piVar8[0xc] >> 9 & 1) << 9 |
                      ((uint)piVar8[0xc] >> 10 & 1) << 10 |
                      piVar8[0xc] & 0x7f800U |
                      ((uint)piVar8[0xc] >> 0x13 & 0x3f) << 0x13 |
                      piVar8[0xc] & 0xfe000000U | local_12c & 0x1ff;
          iVar19 = (**(code **)(*(int *)param_4 + 0x1c))(param_4);
          uVar16 = *(undefined4 *)(this + 4);
          uVar15 = *(undefined4 *)(iVar19 + 0x30);
          uVar12 = *(undefined4 *)this;
          uVar18 = 1;
          goto LAB_97b9e6d8;
        }
      }
      local_14c = piVar8[4];
      local_148 = piVar8[5];
      local_144 = piVar8[6];
      local_13c = piVar8[8];
      local_138 = piVar8[9];
      local_134 = piVar8[10];
      local_130 = piVar8[0xb];
      local_140 = (unsigned char *)piVar8[7];
      local_150 = (unsigned char *)&PTR__TType_a7b7d4d0;
      local_12c = ((uint)piVar8[0xc] >> 9 & 1) << 9 |
                  ((uint)piVar8[0xc] >> 10 & 1) << 10 |
                  piVar8[0xc] & 0x7f800U |
                  ((uint)piVar8[0xc] >> 0x13 & 0x3f) << 0x13 |
                  piVar8[0xc] & 0xfe000000U | local_12c & 0x1ff;
      iVar19 = (**(code **)(*(int *)param_4 + 0x1c))(param_4);
      uVar16 = *(undefined4 *)(this + 4);
      uVar15 = *(undefined4 *)(iVar19 + 0x30);
      uVar12 = *(undefined4 *)this;
      uVar18 = 0;
LAB_97b9e6d8:
      iVar6 = ((int (*)())TIntermediate__parseConstTree)(uVar12,param_1,param_4,iVar6,uVar15,uVar16,(unsigned char *)&local_150,uVar18);
      local_150 = (unsigned char *)&PTR__TType_a7b7d4d0;
      *param_5 = (unsigned char *)0x0;
      if (iVar6 != 0) {
        (**(code **)(piVar8[3] + 0x28))(piVar21,0);
        return iVar6;
      }
      return 0;
    }
    iVar6 = (**(code **)(*(int *)param_4 + 0x28))(param_4);
    if (iVar6 == 0) {
      TType__getCompleteString();
      *(undefined1 *)(local_14c + *(int *)(local_14c - 0xc)) = *DAT_a7b7ba18;
      error((int)this,(char *)param_1," assigning non-constant to","=","\'%s\'",local_14c);
      piVar5 = (int *)(local_14c - 4);
      do {
        iVar6 = *piVar5;
        if (in_RESERVE != '\0') {
          iVar19 = storeWordConditionalIndexed(iVar6 + -1,0,piVar5);
          *piVar5 = iVar19;
          bVar24 = 2;
        }
        uVar11 = local_14c;
        local_70 = local_150;
      } while (!(bool)(bVar24 >> 1 & 1));
      goto joined_r0x97b9dfd0;
    }
    piVar21 = *(int **)(this + 4);
    piVar5 = (int *)(**(code **)(*(int *)param_4 + 0x28))(param_4);
    (**(code **)(*piVar5 + 0x60))();
    iVar6 = *piVar21;
    iVar19 = (piVar21[1] - iVar6 >> 2) + -1;
    while( true ) {
      iVar22 = *(int *)(iVar6 + iVar19 * 4);
      std::
      _Rb_tree<std::string,std::pair<std::string_const,TSymbol*>,std::_Select1st<std::pair<std::string_const,TSymbol*>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,TSymbol*>>>
      ::find((unsigned char *)local_80);
      iVar6 = 0;
      if (local_80[0] != *(int *)(iVar22 + 4)) {
        iVar6 = *(int *)(local_80[0] + 0x18);
      }
      iVar19 = iVar19 + -1;
      if ((iVar6 != 0) || (iVar19 < 0)) break;
      iVar6 = *piVar21;
    }
    iVar6 = *(int *)(iVar6 + 0x38);
  }
  else {
    puVar20 = (undefined4 *)piVar8[0xe];
    if (puVar20 == (undefined4 *)0x0) {
      uVar7 = ((int (*)())GetGlobalPoolAllocator)();
      puVar20 = (undefined4 *)TPoolAllocator__allocate(uVar7);
      piVar8[0xe] = (int)puVar20;
    }
    uVar11 = *(uint *)(param_3 + 8);
    if (uVar11 == 1) {
      local_10c = *(int **)(param_3 + 0x14);
      local_11c = *(uint *)(param_3 + 4);
      local_120 = *(undefined ***)param_3;
      local_114 = *(uint *)(param_3 + 0xc);
      local_110 = *(uint *)(param_3 + 0x10);
      local_108 = *(undefined4 *)(param_3 + 0x18);
      local_12c = (local_110 & 1) << 9 |
                  (local_114 & 1) << 10 |
                  ((uint)local_120 & 0x3f) << 0x13 | local_11c << 0x19 | local_12c & 0x1ff | 0x800;
      local_150 = (unsigned char *)&PTR__TType_a7b7d4d0;
      local_130 = 0;
      local_14c = 0;
      local_148 = 0;
      local_144 = 0;
      local_140 = (unsigned char *)0x0;
      local_13c = 0;
      local_138 = 0;
      local_134 = 0;
      psVar10 = local_140;
      local_118 = uVar11;
      local_100 = local_120;
      local_fc = local_11c;
      local_f8 = uVar11;
      local_f4 = local_114;
      local_f0 = local_110;
      local_ec = local_10c;
      local_e8 = local_108;
      if (local_10c != (int *)0x0) {
        local_148 = local_10c[2];
        local_138 = TType__setStructSize((unsigned char *)&local_150);
        iVar6 = (**(code **)(*local_ec + 0x18))(local_ec);
        *(undefined1 *)(*(int *)(iVar6 + 4) + *(int *)(*(int *)(iVar6 + 4) + -0xc)) = *DAT_a7b7ba18;
        pcVar23 = *(char **)(iVar6 + 4);
        uVar7 = ((int (*)())GetGlobalPoolAllocator)();
        psVar9 = (unsigned char *)TPoolAllocator__allocate(uVar7);
        psVar10 = (unsigned char *)0x0;
        if (psVar9 != (unsigned char *)0x0) {
          local_90[0] = ((int (*)())GetGlobalPoolAllocator)();
          std__string__string(psVar9,pcVar23,(unsigned char *)local_90);
          psVar10 = psVar9;
        }
      }
      local_140 = psVar10;
      local_150 = (unsigned char *)&PTR__TType_a7b7d4d0;
      if ((local_12c >> 0x13 & 0x3f) != 0xe) {
        iVar6 = *(int *)param_3;
        if (iVar6 != 2) {
          if (iVar6 < 3) {
            if (iVar6 == 1) {
              iVar6 = (**(code **)(*(int *)param_4 + 0x18))(param_4);
              *puVar20 = **(undefined4 **)(iVar6 + 0x30);
              goto LAB_97b9e850;
            }
          }
          else if (iVar6 == 3) goto LAB_97b9e3bc;
          pcVar23 = "";
          pcVar14 = " cannot initialize constant of this type";
LAB_97b9df14:
          error((int)this,(char *)param_1,pcVar14,pcVar23,"");
          return 1;
        }
LAB_97b9e3bc:
        iVar6 = (**(code **)(*(int *)param_4 + 0x18))(param_4);
        *puVar20 = **(undefined4 **)(iVar6 + 0x30);
        goto LAB_97b9e850;
      }
    }
    iVar6 = (**(code **)(*(int *)param_4 + 0x18))(param_4);
    iVar6 = *(int *)(iVar6 + 0x30);
  }
  piVar8[0xe] = iVar6;
LAB_97b9e850:
  *param_5 = (unsigned char *)0x0;
  return 0;
}

/* TParseContext__canNodeBeRemoved @ 0x97b9e960 (204 bytes) */
int TParseContext__canNodeBeRemoved(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  
  piVar2 = (int *)(**(code **)(*(int *)param_1 + 0x1c))(param_1);
  uVar1 = 0;
  if (piVar2 != (int *)0x0) {
    iVar3 = TIntermOperator__isConstructor();
    if ((iVar3 == 0) || (piVar2[0xc] == 0x75)) {
      uVar1 = 0;
    }
    else {
      iVar3 = (**(code **)(*piVar2 + 100))(piVar2);
      for (puVar5 = *(undefined4 **)(iVar3 + 4); puVar5 != *(undefined4 **)(iVar3 + 8);
          puVar5 = puVar5 + 1) {
        piVar2 = (int *)(**(code **)(*(int *)*puVar5 + 0x14))();
        iVar4 = (**(code **)(*piVar2 + 0x18))();
        if (iVar4 == 0) {
          return 0;
        }
      }
      uVar1 = 1;
    }
  }
  return uVar1;
}

/* TParseContext__addConstructor @ 0x97b9ea2c (944 bytes) */
int TParseContext__addConstructor(this, param_1, param_2, param_4, param_5, param_6)
  unsigned char *this;
  unsigned char *param_1;
  unsigned char *param_2;
  int param_4;
  int param_5;
  char *param_6;
{
  bool bVar1;
  int *piVar2;
  int iVar3;
  TType *pTVar4;
  undefined4 uVar5;
  TIntermNode *pTVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined1 auStack_40 [4];
  int local_3c;
  undefined4 *local_38;
  TIntermNode *local_34;
  
  if (param_1 == (unsigned char *)0x0) {
    return (unsigned char *)0x0;
  }
  iVar8 = 0;
  bVar1 = param_4 != 0x75;
  puVar7 = (undefined4 *)0x0;
  piVar2 = (int *)(**(code **)(*(int *)param_1 + 0x1c))(param_1);
  if (!bVar1) {
    iVar8 = *(int *)(param_5 + 0x24);
    puVar7 = *(undefined4 **)(iVar8 + 4);
  }
  if (((piVar2 == (int *)0x0) || (piVar2[0xc] != 0)) ||
     (iVar3 = (**(code **)(*piVar2 + 100))(), *(int *)(iVar3 + 8) - *(int *)(iVar3 + 4) >> 2 == 1))
  {
    if (bVar1) {
      uVar5 = (*(code *)**(undefined4 **)param_1)(param_1);
      pTVar4 = (unsigned char *)((int (*)())TParseContext__constructBuiltIn)(this,param_2,param_4,param_1,uVar5,0);
      if (pTVar4 == (unsigned char *)0x0) {
        return (unsigned char *)0x0;
      }
      iVar8 = (**(code **)(*(int *)pTVar4 + 0x1c))();
      if (iVar8 == 0) {
        return pTVar4;
      }
      piVar2 = (int *)(**(code **)(*(int *)pTVar4 + 0x1c))(pTVar4);
      iVar8 = (**(code **)(*piVar2 + 100))();
      iVar8 = ((int (*)())TParseContext__canNodeBeRemoved)(this,(unsigned char *)**(undefined4 **)(iVar8 + 4));
      if (iVar8 == 0) {
        return pTVar4;
      }
      piVar2 = (int *)(**(code **)(*(int *)pTVar4 + 0x1c))(pTVar4);
      iVar8 = (**(code **)(*piVar2 + 100))();
      (**(code **)(*(int *)**(undefined4 **)(iVar8 + 4) + 0x1c))();
      pTVar4 = (unsigned char *)TIntermediate__removeChildNode(*(TIntermTyped **)this,pTVar4,param_2);
      return pTVar4;
    }
    if (*(int *)(iVar8 + 8) - *(int *)(iVar8 + 4) >> 3 == 1) {
      iVar8 = (*(code *)**(undefined4 **)param_1)(param_1);
      pTVar4 = (unsigned char *)((int (*)())TParseContext__constructStruct)(this,param_1,(unsigned char *)*puVar7,1,iVar8,false);
      return pTVar4;
    }
  }
  else {
    pTVar4 = (unsigned char *)(**(code **)(*piVar2 + 100))(piVar2);
    if ((bVar1) ||
       (*(int *)(iVar8 + 8) - *(int *)(iVar8 + 4) >> 3 ==
        *(int *)(pTVar4 + 8) - *(int *)(pTVar4 + 4) >> 2)) {
      local_3c = 0;
      puVar9 = *(undefined4 **)(pTVar4 + 4);
      do {
        iVar8 = local_3c;
        local_38 = puVar9;
        if (puVar9 == *(undefined4 **)(pTVar4 + 8)) {
          pTVar4 = (unsigned char *)TIntermediate__setAggregateOperator
                                      (*(undefined4 *)this,piVar2,param_4,param_6);
          return pTVar4;
        }
        if (bVar1) {
          uVar5 = (*(code *)**(undefined4 **)param_1)(param_1);
          pTVar6 = (unsigned char *)((int (*)())TParseContext__constructBuiltIn)(this,param_2,param_4,*puVar9,uVar5,1);
          if (pTVar6 != (unsigned char *)0x0) {
            iVar8 = ((int (*)())TParseContext__canNodeBeRemoved)(this,pTVar6);
            if (iVar8 == 0) goto LAB_97b9ed60;
            (**(code **)(*(int *)pTVar6 + 0x1c))(pTVar6);
            TIntermediate__removeChildNode
                      (*(TVector **)this,pTVar4,(int *)param_2,(unsigned char *)&local_3c,
                       (unsigned char *)&local_38);
          }
        }
        else {
          iVar3 = (*(code *)**(undefined4 **)param_1)(param_1);
          pTVar6 = (unsigned char *)
                   ((int (*)())TParseContext__constructStruct)(this,(unsigned char *)*puVar9,(unsigned char *)puVar7[iVar8 * 2],
                                   local_3c + 1,iVar3,true);
          if (pTVar6 != (unsigned char *)0x0) {
LAB_97b9ed60:
            std__vector_TIntermNode__pool_allocator_TIntermNode_____erase
                      (auStack_40,pTVar4,local_38);
            local_34 = pTVar6;
            std__vector_TIntermNode__pool_allocator_TIntermNode_____insert
                      (auStack_40,pTVar4,local_38,&local_34);
          }
        }
        local_3c = local_3c + 1;
        puVar9 = local_38 + 1;
      } while( true );
    }
  }
  error((int)this,param_6,
        "Number of constructor parameters does not match the number of structure fields",
        "constructor","");
  return (unsigned char *)0x0;
}

/* TParseContext__constructBuiltIn @ 0x97b9eddc (408 bytes) */
int TParseContext__constructBuiltIn(this, param_1, param_3, param_4, param_5, param_6)
  unsigned char *this;
  int param_1;
  undefined4 param_3;
  int *param_4;
  char *param_5;
  int param_6;
{
  bool bVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined **local_50 [2];
  int local_48;
  uint local_2c;
  
  switch(param_3) {
  case 0x66:
  case 0x6f:
  case 0x70:
  case 0x71:
    uVar4 = 0x66;
    break;
  case 0x67:
  case 0x6c:
  case 0x6d:
  case 0x6e:
    uVar4 = 0x67;
    break;
  case 0x68:
  case 0x69:
  case 0x6a:
  case 0x6b:
  case 0x72:
  case 0x73:
  case 0x74:
    uVar4 = 0x68;
    break;
  default:
    error((int)this,param_5,"unsupported construction","","");
    ((int (*)())TParseContext__recover)(this);
    goto LAB_97b9ef08;
  }
  uVar2 = (**(code **)*param_4)(param_4);
  piVar3 = (int *)TIntermediate__addUnaryMath
                            (*(undefined4 *)this,uVar4,param_4,uVar2,*(undefined4 *)(this + 4));
  if (piVar3 == (int *)0x0) {
    error((int)this,param_5,"can\'t convert","constructor","");
LAB_97b9ef08:
    piVar3 = (int *)0x0;
  }
  else if (param_6 == 0) {
    if (piVar3 != param_4) {
      (**(code **)(*piVar3 + 0x38))(local_50,piVar3);
      bVar1 = false;
      if (((local_2c & 0x1fffe00) == (*(uint *)(param_1 + 0x24) & 0x1fffe00)) &&
         (local_48 == *(int *)(param_1 + 8))) {
        bVar1 = true;
      }
      local_50[0] = &PTR__TType_a7b7d4d0;
      if (bVar1) {
        return piVar3;
      }
    }
    piVar3 = (int *)TIntermediate__setAggregateOperator(*(undefined4 *)this,piVar3,param_3,param_5);
  }
  return piVar3;
}

/* TParseContext__constructStruct @ 0x97b9efb0 (392 bytes) */
int TParseContext__constructStruct(this, param_1, param_2, param_3, param_4, param_5)
  unsigned char *this;
  unsigned char *param_1;
  unsigned char *param_2;
  int param_3;
  int param_4;
  int param_5;
{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined3 in_register_00000020;
  bool bVar4;
  undefined **local_80 [2];
  int local_78;
  uint local_5c;
  undefined **local_50 [9];
  uint local_2c;
  
  piVar1 = (int *)(**(code **)(*(int *)param_1 + 0x14))(param_1);
  (**(code **)(*piVar1 + 0x38))(local_80,piVar1);
  bVar4 = false;
  if (((*(uint *)(param_2 + 0x24) & 0x1fffe00) == (local_5c & 0x1fffe00)) &&
     (*(int *)(param_2 + 8) == local_78)) {
    bVar4 = true;
  }
  local_80[0] = &PTR__TType_a7b7d4d0;
  if (bVar4) {
    if (CONCAT31(in_register_00000020,param_5) == 0) {
      uVar2 = (**(code **)(*(int *)param_1 + 0x14))(param_1);
      uVar2 = TIntermediate__setAggregateOperator(*(undefined4 *)this,uVar2,0x75,param_4);
    }
    else {
      uVar2 = (**(code **)(*(int *)param_1 + 0x14))(param_1);
    }
  }
  else {
    uVar2 = TType__getBasicString(*(uint *)(param_2 + 0x24) >> 0x13 & 0x3f);
    piVar1 = (int *)(**(code **)(*(int *)param_1 + 0x14))(param_1);
    (**(code **)(*piVar1 + 0x38))(local_50,piVar1);
    uVar3 = TType__getBasicString(local_2c >> 0x13 & 0x3f);
    error((int)this,(char *)param_4,"","constructor",
          "cannot convert parameter %d from \'%s\' to \'%s\'",param_3,uVar3,uVar2);
    local_50[0] = &PTR__TType_a7b7d4d0;
    ((int (*)())TParseContext__recover)(this);
    uVar2 = 0;
  }
  return uVar2;
}

/* TParseContext__addConstVectorNode @ 0x97b9f138 (924 bytes) */
int TParseContext__addConstVectorNode(this, param_1, param_2, param_3)
  unsigned char *this;
  unsigned char *param_1;
  unsigned char *param_2;
  int param_3;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  ulong uVar6;
  TType *pTVar7;
  int iVar8;
  int iVar9;
  undefined **local_90 [9];
  uint local_6c;
  
  iVar2 = (**(code **)(*(int *)param_2 + 0x18))(param_2);
  piVar3 = (int *)(**(code **)(*(int *)param_2 + 0x1c))(param_2);
  if (iVar2 != 0) {
    iVar2 = *(int *)(iVar2 + 0x30);
    if (iVar2 == 0) {
                    
                    
      uVar4 = (*(code *)(((unsigned char *)0x97b9f1cc) + (*(unsigned char *)0x97b9f1d8)))();
      return uVar4;
    }
    goto LAB_97b9f4c4;
  }
  if (piVar3 == (int *)0x0) {
    error((int)this,(char *)param_3,"No aggregate or constant union node available","Internal Error"
          ,"");
    ((int (*)())TParseContext__recover)(this);
    return 0;
  }
  (**(code **)(*piVar3 + 0x38))(local_90,piVar3);
  uVar6 = ((int (*)())GetGlobalPoolAllocator)();
  iVar2 = TPoolAllocator__allocate(uVar6);
  local_90[0] = &PTR__TType_a7b7d4d0;
  piVar5 = (int *)(**(code **)(*piVar3 + 0x1c))(piVar3);
  iVar9 = (**(code **)(*piVar5 + 100))();
  if (*(int *)(iVar9 + 8) - *(int *)(iVar9 + 4) >> 2 == 1) {
    piVar5 = (int *)(**(code **)(*piVar3 + 0x1c))(piVar3);
    iVar9 = (**(code **)(*piVar5 + 100))();
    piVar5 = (int *)(**(code **)(*(int *)**(undefined4 **)(iVar9 + 4) + 0x14))();
    iVar9 = (**(code **)(*piVar5 + 0x18))();
    if (iVar9 == 0) goto LAB_97b9f438;
    (**(code **)(*piVar3 + 0x38))(local_90,piVar3);
    iVar9 = ((int (*)())TIntermediate__parseConstTree)(*(undefined4 *)this,param_3,piVar3,iVar2,piVar3[0xc],
                       *(undefined4 *)(this + 4),local_90,1);
  }
  else {
LAB_97b9f438:
    (**(code **)(*piVar3 + 0x38))(local_90,piVar3);
    iVar9 = ((int (*)())TIntermediate__parseConstTree)(*(undefined4 *)this,param_3,piVar3,iVar2,piVar3[0xc],
                       *(undefined4 *)(this + 4),local_90,0);
  }
  local_90[0] = &PTR__TType_a7b7d4d0;
  if (iVar9 != 0) {
    return 0;
  }
LAB_97b9f4c4:
  iVar9 = 0;
  uVar6 = ((int (*)())GetGlobalPoolAllocator)();
  pTVar7 = (unsigned char *)TPoolAllocator__allocate(uVar6);
  if (0 < *(int *)(param_1 + 0x10)) {
    iVar8 = 0;
    do {
      (**(code **)(*(int *)param_2 + 0x38))(local_90,param_2);
      if ((local_6c & 0x400) == 0) {
        iVar1 = (int)(local_6c << 0xd | local_6c >> 0x13) >> 0x18;
      }
      else {
        iVar1 = (int)(local_6c << 0xd | local_6c >> 0x13) >> 0x18;
        iVar1 = iVar1 * iVar1;
      }
      local_90[0] = &PTR__TType_a7b7d4d0;
      if (iVar1 <= *(int *)(param_1 + iVar8)) {
        error((int)this,(char *)param_3,"","[","vector field selection out of range \'%d\'",
              *(undefined4 *)(param_1 + iVar8));
        ((int (*)())TParseContext__recover)(this);
        *(undefined4 *)(param_1 + iVar8) = 0;
      }
      iVar9 = iVar9 + 1;
      *(undefined4 *)(pTVar7 + iVar8) = *(undefined4 *)(iVar2 + *(int *)(param_1 + iVar8) * 4);
      iVar8 = iVar8 + 4;
    } while (iVar9 < *(int *)(param_1 + 0x10));
  }
  (**(code **)(*(int *)param_2 + 0x38))(local_90,param_2);
  uVar4 = TIntermediate__addConstantUnion(*(constUnion **)this,pTVar7,(int)local_90);
  return uVar4;
}

/* TParseContext__addConstMatrixNode @ 0x97b9f600 (904 bytes) */
int TParseContext__addConstMatrixNode(this, param_1, param_2, param_3)
  unsigned char *this;
  int param_1;
  unsigned char *param_2;
  int param_3;
{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  ulong uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined **local_60 [9];
  uint local_3c;
  
  piVar1 = (int *)(**(code **)(*(int *)param_2 + 0x18))(param_2);
  piVar2 = (int *)(**(code **)(*(int *)param_2 + 0x1c))(param_2);
  (**(code **)(*(int *)param_2 + 0x38))(local_60,param_2);
  local_60[0] = &PTR__TType_a7b7d4d0;
  iVar6 = param_1;
  if ((int)(local_3c << 0xd | local_3c >> 0x13) >> 0x18 <= param_1) {
    iVar6 = 0;
    error((int)this,(char *)param_3,"","[","matrix field selection out of range \'%d\'",param_1);
    ((int (*)())TParseContext__recover)(this);
  }
  if (piVar1 != (int *)0x0) {
    iVar7 = piVar1[0xc];
    (**(code **)(*piVar1 + 0x38))(local_60,piVar1);
    local_60[0] = &PTR__TType_a7b7d4d0;
    (**(code **)(*piVar1 + 0x38))(local_60,piVar1);
    uVar3 = TIntermediate__addConstantUnion
                      (*(constUnion **)this,
                       (unsigned char *)(iVar7 + ((int)(local_3c << 0xd | local_3c >> 0x13) >> 0x18) * iVar6
                                         * 4),(int)local_60);
    return uVar3;
  }
  if (piVar2 == (int *)0x0) {
    error((int)this,(char *)param_3,"No Aggregate or Constant Union node available","Internal Error"
          ,"");
    ((int (*)())TParseContext__recover)(this);
    return 0;
  }
  (**(code **)(*piVar2 + 0x38))(local_60,piVar2);
  uVar4 = ((int (*)())GetGlobalPoolAllocator)();
  iVar7 = TPoolAllocator__allocate(uVar4);
  local_60[0] = &PTR__TType_a7b7d4d0;
  (**(code **)(*piVar2 + 0x38))(local_60,piVar2);
  local_60[0] = &PTR__TType_a7b7d4d0;
  piVar1 = (int *)(**(code **)(*piVar2 + 0x1c))(piVar2);
  iVar5 = (**(code **)(*piVar1 + 100))();
  if (*(int *)(iVar5 + 8) - *(int *)(iVar5 + 4) >> 2 == 1) {
    piVar1 = (int *)(**(code **)(*piVar2 + 0x1c))(piVar2);
    iVar5 = (**(code **)(*piVar1 + 100))();
    piVar1 = (int *)(**(code **)(*(int *)**(undefined4 **)(iVar5 + 4) + 0x14))();
    iVar5 = (**(code **)(*piVar1 + 0x18))();
    if (iVar5 != 0) {
      (**(code **)(*piVar2 + 0x38))(local_60,piVar2);
      iVar5 = ((int (*)())TIntermediate__parseConstTree)(*(undefined4 *)this,param_3,piVar2,iVar7,piVar2[0xc],
                         *(undefined4 *)(this + 4),local_60,1);
      goto LAB_97b9f8f4;
    }
  }
  (**(code **)(*piVar2 + 0x38))(local_60,piVar2);
  iVar5 = ((int (*)())TIntermediate__parseConstTree)(*(undefined4 *)this,param_3,piVar2,iVar7,piVar2[0xc],*(undefined4 *)(this + 4),
                     local_60,0);
LAB_97b9f8f4:
  local_60[0] = &PTR__TType_a7b7d4d0;
  uVar3 = 0;
  if (iVar5 == 0) {
    (**(code **)(*piVar2 + 0x38))(local_60,piVar2);
    uVar3 = TIntermediate__addConstantUnion
                      (*(constUnion **)this,
                       (unsigned char *)(iVar7 + ((int)(local_3c << 0xd | local_3c >> 0x13) >> 0x18) * iVar6
                                         * 4),(int)local_60);
  }
  return uVar3;
}

/* TParseContext__addConstStruct @ 0x97b9f988 (848 bytes) */
int TParseContext__addConstStruct(this, param_1, param_2, param_3)
  unsigned char *this;
  unsigned char *param_1;
  unsigned char *param_2;
  int param_3;
{
  int iVar1;
  int *piVar2;
  int *piVar3;
  TVector *pTVar4;
  ulong uVar5;
  undefined4 uVar6;
  uint *puVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  undefined **local_80 [2];
  int local_78;
  uint local_50;
  uint local_4c [5];
  
  iVar8 = 0;
  (**(code **)(*(int *)param_2 + 0x38))(local_80,param_2);
  local_80[0] = &PTR__TType_a7b7d4d0;
  piVar2 = (int *)(**(code **)(*(int *)param_2 + 0x18))(param_2);
  piVar3 = (int *)(**(code **)(*(int *)param_2 + 0x1c))(param_2);
  for (uVar9 = 0; uVar9 < (uint)(*(int *)(local_78 + 8) - *(int *)(local_78 + 4) >> 3);
      uVar9 = uVar9 + 1) {
    iVar11 = (**(code **)(**(int **)(*(int *)(local_78 + 4) + uVar9 * 8) + 0x1c))();
    uVar12 = *(uint *)(*(int *)(iVar11 + 4) + -0xc);
    local_50 = uVar12;
    uVar10 = *(uint *)((int)*(void **)(param_1 + 4) + -0xc);
    local_4c[0] = uVar10;
    puVar7 = local_4c;
    if (uVar12 <= uVar10) {
      puVar7 = &local_50;
    }
    iVar11 = _memcmp(*(void **)(iVar11 + 4),*(void **)(param_1 + 4),*puVar7);
    if (iVar11 == 0) {
      iVar11 = uVar12 - uVar10;
    }
    if (iVar11 == 0) break;
    pTVar4 = *(TVector **)(*(int *)(local_78 + 4) + uVar9 * 8);
    if (*(int *)(pTVar4 + 8) == 0) {
      iVar11 = (**(code **)(*(int *)pTVar4 + 0x30))();
    }
    else {
      iVar11 = TType__setStructSize(pTVar4);
    }
    iVar8 = iVar8 + iVar11;
  }
  if (piVar2 != (int *)0x0) {
    iVar1 = *piVar2;
    iVar11 = piVar2[0xc];
    piVar3 = piVar2;
    goto LAB_97b9fc60;
  }
  if (piVar3 == (int *)0x0) {
    error((int)this,(char *)param_3,"No Aggregate or Constant Union node available","Internal Error"
          ,"");
    ((int (*)())TParseContext__recover)(this);
    return 0;
  }
  (**(code **)(*piVar3 + 0x38))(local_80,piVar3);
  uVar5 = ((int (*)())GetGlobalPoolAllocator)();
  iVar11 = TPoolAllocator__allocate(uVar5);
  local_80[0] = &PTR__TType_a7b7d4d0;
  piVar2 = (int *)(**(code **)(*piVar3 + 0x1c))(piVar3);
  iVar1 = (**(code **)(*piVar2 + 100))();
  if (*(int *)(iVar1 + 8) - *(int *)(iVar1 + 4) >> 2 == 1) {
    piVar2 = (int *)(**(code **)(*piVar3 + 0x1c))(piVar3);
    iVar1 = (**(code **)(*piVar2 + 100))();
    piVar2 = (int *)(**(code **)(*(int *)**(undefined4 **)(iVar1 + 4) + 0x14))();
    iVar1 = (**(code **)(*piVar2 + 0x18))();
    if (iVar1 == 0) goto LAB_97b9fc00;
    (**(code **)(*piVar3 + 0x38))(local_80,piVar3);
    iVar1 = ((int (*)())TIntermediate__parseConstTree)(*(undefined4 *)this,param_3,piVar3,iVar11,piVar3[0xc],
                       *(undefined4 *)(this + 4),local_80,1);
  }
  else {
LAB_97b9fc00:
    (**(code **)(*piVar3 + 0x38))(local_80,piVar3);
    iVar1 = ((int (*)())TIntermediate__parseConstTree)(*(undefined4 *)this,param_3,piVar3,iVar11,piVar3[0xc],
                       *(undefined4 *)(this + 4),local_80,0);
  }
  local_80[0] = &PTR__TType_a7b7d4d0;
  if (iVar1 != 0) {
    return 0;
  }
  iVar1 = *piVar3;
LAB_97b9fc60:
  (**(code **)(iVar1 + 0x38))(local_80,piVar3);
  uVar6 = TIntermediate__addConstantUnion
                    (*(constUnion **)this,(unsigned char *)(iVar11 + iVar8 * 4),(int)local_80);
  return uVar6;
}

/* TParseContext__initializeExtensionBehavior @ 0x97b9fcd8 (380 bytes) */
int TParseContext__initializeExtensionBehavior(this)
  unsigned char *this;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  char in_RESERVE;
  byte in_cr0;
  undefined4 local_d0;
  void *local_cc;
  undefined4 local_c0 [4];
  int local_b0 [4];
  int local_a0;
  int local_90 [4];
  int local_80;
  undefined4 local_70;
  int local_6c;
  undefined4 local_68;
  int local_60 [4];
  undefined4 local_50;
  undefined4 local_40;
  uint local_30;
  uint local_2c [4];
  
  local_c0[0] = ((int (*)())GetGlobalPoolAllocator)();
  std__string__string((unsigned char *)&local_d0,"GL_ARB_texture_rectangle",(unsigned char *)local_c0);
  std::
  _Rb_tree<std::string,std::pair<std::string_const,TBehavior>,std::_Select1st<std::pair<std::string_const,TBehavior>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,TBehavior>>>
  ::lower_bound((unsigned char *)local_b0);
  iVar2 = local_b0[0];
  local_a0 = *(int *)(this + 0x34);
  if (local_b0[0] != local_a0) {
    puVar4 = local_2c;
    uVar5 = *(uint *)((int)local_cc + -0xc);
    local_30 = uVar5;
    uVar6 = *(uint *)(*(int *)(local_b0[0] + 0x14) + -0xc);
    local_2c[0] = uVar6;
    if (uVar5 <= uVar6) {
      puVar4 = &local_30;
    }
    iVar3 = _memcmp(local_cc,*(void **)(local_b0[0] + 0x14),*puVar4);
    in_cr0 = (iVar3 == 0) << 1;
    if (iVar3 == 0) {
      iVar3 = uVar5 - uVar6;
    }
    if (-1 < iVar3) goto LAB_97b9fe04;
  }
  local_80 = iVar2;
  std__string__string((unsigned char *)&local_70,(unsigned char *)&local_d0);
  local_68 = 0;
  local_60[0] = local_80;
  std::
  _Rb_tree<std::string,std::pair<std::string_const,TBehavior>,std::_Select1st<std::pair<std::string_const,TBehavior>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,TBehavior>>>
  ::insert_unique(local_90,this + 0x30,local_60,(unsigned char *)&local_70);
  piVar1 = (int *)(local_6c + -4);
  local_b0[0] = local_90[0];
  local_50 = local_70;
  do {
    iVar3 = *piVar1;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar3 + -1,0,piVar1);
      *piVar1 = iVar2;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  iVar2 = local_90[0];
  if (iVar3 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(local_6c + -0xc));
    iVar2 = local_b0[0];
  }
LAB_97b9fe04:
  *(undefined4 *)(iVar2 + 0x18) = 1;
  piVar1 = (int *)((int)local_cc + -4);
  local_40 = local_d0;
  do {
    iVar2 = *piVar1;
    if (in_RESERVE != '\0') {
      iVar3 = storeWordConditionalIndexed(iVar2 + -1,0,piVar1);
      *piVar1 = iVar3;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar2 < 1) {
    std__string___Rep___M_destroy((unsigned char *)((int)local_cc + -0xc));
  }
  return;
}

/* InitializeGlobalPools @ 0x97b9fe54 (144 bytes) */
int InitializeGlobalPools()
{
  TPoolAllocator *this;
  
  if (_gPollAllocThreadData == (undefined4 *)0x0) {
    this = operator_new(0x34);
    ((int (*)())TPoolAllocator__TPoolAllocator)(this,true,0x2000,0x10);
    _gPollAllocThreadData = operator_new(8);
    _gPollAllocThreadData[1] = 0;
    *_gPollAllocThreadData = this;
    _gPollAllocThreadData[1] = 0;
    TPoolAllocator__push(this);
    return;
  }
  return;
}

/* FreeGlobalPools @ 0x97b9fee4 (112 bytes) */
int FreeGlobalPools()
{
  TPoolAllocator *pTVar1;
  
  if (_gPollAllocThreadData != (void *)0x0) {
    pTVar1 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
    TPoolAllocator__popAll(pTVar1);
    pTVar1 = (unsigned char *)((int (*)())GetGlobalPoolAllocator)();
    if (pTVar1 != (unsigned char *)0x0) {
      TPoolAllocator___TPoolAllocator(pTVar1);
      operator_delete(pTVar1);
    }
    operator_delete(_gPollAllocThreadData);
    _gPollAllocThreadData = (void *)0x0;
  }
  return;
}

/* GetGlobalPoolAllocator @ 0x97b9ff54 (32 bytes) */
int GetGlobalPoolAllocator()
{
  return *_gPollAllocThreadData;
}

/* SetGlobalPoolAllocatorPtr @ 0x97b9ff74 (32 bytes) */
int SetGlobalPoolAllocatorPtr(param_1)
  unsigned char *param_1;
{
  *_gPollAllocThreadData = param_1;
  return;
}

/* GetCompilerPoolAllocator @ 0x97b9ff94 (32 bytes) */
int GetCompilerPoolAllocator()
{
  return _gPollAllocThreadData + 4;
}

/* TPoolAllocator__TPoolAllocator @ 0x97b9ffb4 (4 bytes) */
int TPoolAllocator__TPoolAllocator(this, param_1, param_2, param_3)
  unsigned char *this;
  int param_1;
  int param_2;
  int param_3;
{
  uint uVar1;
  undefined3 in_register_00000010;
  
  *(uint *)this = CONCAT31(in_register_00000010,param_1);
  *(int *)(this + 8) = param_3;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  *(int *)(this + 4) = param_2;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  if ((uint)param_2 < 0x1000) {
    *(undefined4 *)(this + 4) = 0x1000;
  }
  uVar1 = *(uint *)(this + 8);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(this + 4);
  *(uint *)(this + 8) = uVar1 & 0xfffffffc;
  if ((uVar1 & 0xfffffffc) < 4) {
    *(undefined4 *)(this + 8) = 4;
  }
  uVar1 = 1;
  if (1 < *(uint *)(this + 8)) {
    do {
      uVar1 = uVar1 << 1;
    } while (uVar1 < *(uint *)(this + 8));
  }
  *(uint *)(this + 8) = uVar1;
  *(uint *)(this + 0x10) = uVar1 + 7 & ~(uVar1 - 1);
  *(uint *)(this + 0xc) = uVar1 - 1;
  return;
}

/* TPoolAllocator__TPoolAllocator_97b9ffb8 @ 0x97b9ffb8 (4 bytes) */
int TPoolAllocator__TPoolAllocator_97b9ffb8(this, param_1, param_2, param_3)
  unsigned char *this;
  int param_1;
  int param_2;
  int param_3;
{
  uint uVar1;
  undefined3 in_register_00000010;
  
  *(uint *)this = CONCAT31(in_register_00000010,param_1);
  *(int *)(this + 8) = param_3;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  *(int *)(this + 4) = param_2;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  if ((uint)param_2 < 0x1000) {
    *(undefined4 *)(this + 4) = 0x1000;
  }
  uVar1 = *(uint *)(this + 8);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(this + 4);
  *(uint *)(this + 8) = uVar1 & 0xfffffffc;
  if ((uVar1 & 0xfffffffc) < 4) {
    *(undefined4 *)(this + 8) = 4;
  }
  uVar1 = 1;
  if (1 < *(uint *)(this + 8)) {
    do {
      uVar1 = uVar1 << 1;
    } while (uVar1 < *(uint *)(this + 8));
  }
  *(uint *)(this + 8) = uVar1;
  *(uint *)(this + 0x10) = uVar1 + 7 & ~(uVar1 - 1);
  *(uint *)(this + 0xc) = uVar1 - 1;
  return;
}

/* TPoolAllocator__TPoolAllocator_97b9ffbc @ 0x97b9ffbc (152 bytes) */
int TPoolAllocator__TPoolAllocator_97b9ffbc(this, param_1, param_2, param_3)
  unsigned char *this;
  int param_1;
  int param_2;
  int param_3;
{
  uint uVar1;
  undefined3 in_register_00000010;
  
  *(uint *)this = CONCAT31(in_register_00000010,param_1);
  *(int *)(this + 8) = param_3;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  *(int *)(this + 4) = param_2;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  if ((uint)param_2 < 0x1000) {
    *(undefined4 *)(this + 4) = 0x1000;
  }
  uVar1 = *(uint *)(this + 8);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(this + 4);
  *(uint *)(this + 8) = uVar1 & 0xfffffffc;
  if ((uVar1 & 0xfffffffc) < 4) {
    *(undefined4 *)(this + 8) = 4;
  }
  uVar1 = 1;
  if (1 < *(uint *)(this + 8)) {
    do {
      uVar1 = uVar1 << 1;
    } while (uVar1 < *(uint *)(this + 8));
  }
  *(uint *)(this + 8) = uVar1;
  *(uint *)(this + 0x10) = uVar1 + 7 & ~(uVar1 - 1);
  *(uint *)(this + 0xc) = uVar1 - 1;
  return;
}

