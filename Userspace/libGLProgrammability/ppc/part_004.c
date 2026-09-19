#include "decls.h"

/* TIntermOperator__isConstructor @ 0x97b90474 (24 bytes) */
int TIntermOperator__isConstructor(this)
  unsigned char * this;
{
  return *(int *)(this + 0x30) - 0x66U < 0x10;
}

/* TIntermUnary__promote @ 0x97b9048c (304 bytes) */
int TIntermUnary__promote(param_1)
  unsigned char * param_1;
{
  bool bVar1;
  int iVar2;
  undefined1 local_40 [56];
  
  iVar2 = *(int *)(param_1 + 0x30);
  if (iVar2 == 8) {
    iVar2 = (**(code **)(**(int **)(param_1 + 0x34) + 0x40))();
    bVar1 = iVar2 == 2;
LAB_97b9055c:
    if (!bVar1) {
      return 0;
    }
  }
  else {
    if (iVar2 < 9) {
      if (iVar2 == 6) {
        iVar2 = (**(code **)(**(int **)(param_1 + 0x34) + 0x40))();
        bVar1 = iVar2 == 3;
        goto LAB_97b9055c;
      }
      if (6 < iVar2) {
        return 1;
      }
      if (iVar2 != 5) goto LAB_97b90544;
    }
    else if (0xc < iVar2) {
      if (iVar2 - 0x57U < 2) {
        return 1;
      }
LAB_97b90544:
      iVar2 = (**(code **)(**(int **)(param_1 + 0x34) + 0x40))();
      bVar1 = iVar2 == 1;
      goto LAB_97b9055c;
    }
    iVar2 = (**(code **)(**(int **)(param_1 + 0x34) + 0x40))();
    if (iVar2 == 3) {
      return 0;
    }
  }
  (**(code **)(**(int **)(param_1 + 0x34) + 0x38))(local_40);
  (**(code **)(*(int *)param_1 + 0x34))(param_1,local_40);
  return 1;
}

/* TIntermBinary__promote @ 0x97b905bc (3124 bytes) */
int TIntermBinary__promote(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  bool bVar1;
  undefined *puVar2;
  undefined **ppuVar3;
  undefined4 uVar4;
  undefined *puVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  code *pcVar12;
  char in_RESERVE;
  byte bVar13;
  undefined **local_a0;
  int local_9c;
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  int local_80;
  uint local_7c;
  char local_70 [8];
  int local_68;
  unsigned char aaStack_50 [4];
  uint local_4c;
  
  uVar6 = (**(code **)(**(int **)(this + 0x34) + 0x48))();
  iVar7 = (**(code **)(**(int **)(this + 0x38) + 0x48))();
  if ((int)uVar6 < iVar7) {
    uVar6 = (**(code **)(**(int **)(this + 0x38) + 0x48))();
  }
  uVar8 = (**(code **)(**(int **)(this + 0x34) + 0x40))();
  iVar7 = (**(code **)(**(int **)(this + 0x34) + 0x54))();
  if (iVar7 != 0) {
    return 0;
  }
  local_9c = (**(code **)(**(int **)(this + 0x38) + 0x54))();
  if (local_9c != 0) {
    return 0;
  }
  uVar9 = (**(code **)(**(int **)(this + 0x34) + 0x48))();
  uVar10 = (**(code **)(**(int **)(this + 0x34) + 0x50))();
  local_7c = (uVar10 & 1) << 10 | (uVar9 & 0xff) << 0xb | (uVar8 & 0x3f) << 0x13 | local_7c & 0x1ff;
  local_a0 = &PTR__TType_a7b7cff8;
  local_98 = local_9c;
  local_94 = local_9c;
  local_90 = local_9c;
  local_8c = local_9c;
  local_88 = local_9c;
  local_84 = local_9c;
  local_80 = local_9c;
  (**(code **)(*(int *)this + 0x34))(this,&local_a0);
  local_a0 = &PTR__TType_a7b7cff8;
  if (uVar6 == 1) {
    iVar7 = *(int *)(this + 0x30);
    if (iVar7 < 0x25) {
      if (0x20 < iVar7) {
LAB_97b90770:
        iVar7 = *(int *)this;
        local_7c = local_7c & 0x1801ff;
        goto LAB_97b90850;
      }
      if (0x16 < iVar7) {
        if (iVar7 < 0x1d) {
          iVar7 = (**(code **)(**(int **)(this + 0x34) + 0x40))();
          if (iVar7 != 2) {
            return 0;
          }
          iVar7 = (**(code **)(**(int **)(this + 0x38) + 0x40))();
          bVar1 = iVar7 == 2;
          goto LAB_97b90940;
        }
        if (iVar7 < 0x1f) goto LAB_97b90770;
      }
    }
    else {
      if (iVar7 == 0x2c) {
LAB_97b907c4:
        iVar7 = (**(code **)(**(int **)(this + 0x34) + 0x40))();
        if (iVar7 != 3) {
          return 0;
        }
        iVar7 = (**(code **)(**(int **)(this + 0x38) + 0x40))();
        if (iVar7 != 3) {
          return 0;
        }
        iVar7 = *(int *)this;
        local_7c = local_7c & 0x9ff;
LAB_97b90850:
        local_7c = local_7c | 0x180800;
        local_80 = 0;
        local_84 = 0;
        local_88 = 0;
        local_8c = 0;
        local_90 = 0;
        local_94 = 0;
        local_98 = 0;
        local_9c = 0;
        local_a0 = &PTR__TType_a7b7cff8;
        (**(code **)(iVar7 + 0x34))(this,&local_a0);
        return 1;
      }
      if (iVar7 < 0x2d) {
        if (iVar7 == 0x2a) goto LAB_97b907c4;
      }
      else if (iVar7 - 0x7fU < 6) {
        iVar7 = (**(code **)(**(int **)(this + 0x34) + 0x40))();
        if (iVar7 != 2) {
          return 0;
        }
        iVar7 = (**(code **)(**(int **)(this + 0x38) + 0x40))();
        if (iVar7 != 2) {
          return 0;
        }
      }
    }
    iVar7 = (**(code **)(**(int **)(this + 0x34) + 0x40))();
    iVar11 = (**(code **)(**(int **)(this + 0x38) + 0x40))();
    if (iVar7 != iVar11) {
      return 0;
    }
    iVar7 = (**(code **)(**(int **)(this + 0x34) + 0x50))();
    iVar11 = (**(code **)(**(int **)(this + 0x38) + 0x50))();
    bVar1 = iVar7 == iVar11;
LAB_97b90940:
    if (!bVar1) {
      return 0;
    }
    return 1;
  }
  uVar9 = (**(code **)(**(int **)(this + 0x34) + 0x48))();
  if ((uVar9 != uVar6) && (iVar7 = (**(code **)(**(int **)(this + 0x34) + 0x48))(), iVar7 != 1)) {
    return 0;
  }
  uVar9 = (**(code **)(**(int **)(this + 0x38) + 0x48))();
  if ((uVar9 != uVar6) && (iVar7 = (**(code **)(**(int **)(this + 0x38) + 0x48))(), iVar7 != 1)) {
    return 0;
  }
  switch(*(undefined4 *)(this + 0x30)) {
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
    iVar7 = (**(code **)(**(int **)(this + 0x34) + 0x50))();
    if ((iVar7 == 0) && (iVar7 = (**(code **)(**(int **)(this + 0x38) + 0x50))(), iVar7 != 0)) {
      iVar7 = (**(code **)(**(int **)(this + 0x34) + 0x58))();
      if (iVar7 != 0) {
        uVar4 = 0x27;
        goto LAB_97b9100c;
      }
      local_7c = (uVar6 & 0xff) << 0xb | (uVar8 & 0x3f) << 0x13 | local_7c & 0x5ff | 0x400;
      iVar7 = *(int *)this;
      *(undefined4 *)(this + 0x30) = 0x29;
    }
    else {
      iVar7 = (**(code **)(**(int **)(this + 0x34) + 0x50))();
      if ((iVar7 == 0) || (iVar7 = (**(code **)(**(int **)(this + 0x38) + 0x50))(), iVar7 != 0)) {
        iVar7 = (**(code **)(**(int **)(this + 0x34) + 0x50))();
        if (iVar7 != 0) {
          iVar7 = (**(code **)(**(int **)(this + 0x38) + 0x50))();
          uVar4 = 0x56;
          if (iVar7 != 0) goto LAB_97b9100c;
        }
        iVar7 = (**(code **)(**(int **)(this + 0x34) + 0x50))();
        if ((iVar7 != 0) || (iVar7 = (**(code **)(**(int **)(this + 0x38) + 0x50))(), iVar7 != 0)) {
          uVar6 = (*(code *)**(undefined4 **)this)(this);
                    
          TInfoSinkBase__append((char *)param_1);
          bVar1 = (uVar6 & 0xffff) == 0;
          bVar13 = bVar1 << 1;
          if (bVar1) {
            _sprintf(local_70,"%d:? ",(int)uVar6 >> 0x10);
          }
          else {
            _sprintf(local_70,"%d:%d",(int)uVar6 >> 0x10);
          }
          std__string__string((unsigned char *)&local_a0,local_70,(unsigned char *)&local_90);
          *(undefined *)((int)local_a0 + (int)local_a0[-3]) = *PTR__S_terminal_a7b7c0b8;
          TInfoSinkBase__append((char *)param_1);
          ppuVar3 = local_a0 + -1;
          do {
            puVar5 = *ppuVar3;
            if (in_RESERVE != '\0') {
              puVar2 = (undefined *)storeWordConditionalIndexed(puVar5 + -1,0,ppuVar3);
              *ppuVar3 = puVar2;
              bVar13 = 2;
            }
          } while (!(bool)(bVar13 >> 1 & 1));
          if ((int)puVar5 < 1) {
            std__string___Rep___M_destroy((unsigned char *)(local_a0 + -3));
          }
          TInfoSinkBase__append((char *)param_1);
LAB_97b91274:
          TInfoSinkBase__append((char *)param_1);
          TInfoSinkBase__append((char *)param_1);
          return 0;
        }
        iVar7 = (**(code **)(**(int **)(this + 0x34) + 0x58))();
        if (((iVar7 != 0) && (iVar7 = (**(code **)(**(int **)(this + 0x38) + 0x58))(), iVar7 != 0))
           || ((iVar7 = (**(code **)(**(int **)(this + 0x34) + 0x58))(), iVar7 == 0 &&
               (iVar7 = (**(code **)(**(int **)(this + 0x38) + 0x58))(), iVar7 == 0))))
        goto LAB_97b91520;
        iVar7 = *(int *)this;
        uVar8 = (uVar8 & 0x3f) << 0x13 | local_7c & 0x7ffff;
        uVar4 = 0x26;
      }
      else {
        iVar7 = (**(code **)(**(int **)(this + 0x38) + 0x58))();
        uVar4 = 0x29;
        if (iVar7 == 0) goto LAB_97b9100c;
        iVar7 = *(int *)this;
        uVar8 = (uVar8 & 0x3f) << 0x13 | local_7c & 0x7ffff;
        uVar4 = 0x28;
      }
LAB_97b910f8:
      local_7c = (uVar6 & 0xff) << 0xb | uVar8 & 0xfff801ff;
      *(undefined4 *)(this + 0x30) = uVar4;
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
    iVar7 = (**(code **)(**(int **)(this + 0x34) + 0x50))();
    if ((iVar7 != 0) && (iVar7 = (**(code **)(**(int **)(this + 0x38) + 0x58))(), iVar7 != 0)) {
      return 0;
    }
    iVar7 = (**(code **)(**(int **)(this + 0x34) + 0x58))();
    if ((iVar7 != 0) && (iVar7 = (**(code **)(**(int **)(this + 0x38) + 0x50))(), iVar7 != 0)) {
      return 0;
    }
    iVar7 = (**(code **)(**(int **)(this + 0x34) + 0x40))();
    iVar11 = (**(code **)(**(int **)(this + 0x38) + 0x40))();
    if (iVar7 != iVar11) {
      return 0;
    }
    iVar7 = *(int *)this;
    local_7c = local_7c & 0x1801ff | 0x180800;
LAB_97b914fc:
    pcVar12 = *(code **)(iVar7 + 0x34);
    goto LAB_97b91508;
  case 0x76:
    break;
  case 0x79:
    iVar7 = (**(code **)(**(int **)(this + 0x34) + 0x50))();
    if ((iVar7 == 0) && (iVar7 = (**(code **)(**(int **)(this + 0x38) + 0x50))(), iVar7 != 0)) {
      iVar7 = (**(code **)(**(int **)(this + 0x34) + 0x58))();
      if (iVar7 == 0) {
        return 0;
      }
      uVar4 = 0x7a;
    }
    else {
      iVar7 = (**(code **)(**(int **)(this + 0x34) + 0x50))();
      if ((iVar7 == 0) || (iVar7 = (**(code **)(**(int **)(this + 0x38) + 0x50))(), iVar7 != 0)) {
        iVar7 = (**(code **)(**(int **)(this + 0x34) + 0x50))();
        if ((iVar7 == 0) || (iVar7 = (**(code **)(**(int **)(this + 0x38) + 0x50))(), iVar7 == 0)) {
          iVar7 = (**(code **)(**(int **)(this + 0x34) + 0x50))();
          if ((iVar7 != 0) || (iVar7 = (**(code **)(**(int **)(this + 0x38) + 0x50))(), iVar7 != 0))
          {
            uVar6 = (*(code *)**(undefined4 **)this)(this);
                    
            TInfoSinkBase__append((char *)param_1);
            bVar1 = (uVar6 & 0xffff) == 0;
            bVar13 = bVar1 << 1;
            if (bVar1) {
              _sprintf((char *)&local_90,"%d:? ",(int)uVar6 >> 0x10);
            }
            else {
              _sprintf((char *)&local_90,"%d:%d",(int)uVar6 >> 0x10);
            }
            std__string__string((unsigned char *)&local_a0,(char *)&local_90,aaStack_50);
            *(undefined *)((int)local_a0 + (int)local_a0[-3]) = *PTR__S_terminal_a7b7c0b8;
            TInfoSinkBase__append((char *)param_1);
            ppuVar3 = local_a0 + -1;
            do {
              puVar5 = *ppuVar3;
              if (in_RESERVE != '\0') {
                puVar2 = (undefined *)storeWordConditionalIndexed(puVar5 + -1,0,ppuVar3);
                *ppuVar3 = puVar2;
                bVar13 = 2;
              }
            } while (!(bool)(bVar13 >> 1 & 1));
            if ((int)puVar5 < 1) {
              std__string___Rep___M_destroy((unsigned char *)(local_a0 + -3));
            }
            TInfoSinkBase__append((char *)param_1);
            goto LAB_97b91274;
          }
          iVar7 = (**(code **)(**(int **)(this + 0x34) + 0x58))();
          if (((iVar7 != 0) && (iVar7 = (**(code **)(**(int **)(this + 0x38) + 0x58))(), iVar7 != 0)
              ) || ((iVar7 = (**(code **)(**(int **)(this + 0x34) + 0x58))(), iVar7 == 0 &&
                    (iVar7 = (**(code **)(**(int **)(this + 0x38) + 0x58))(), iVar7 == 0))))
          goto LAB_97b91520;
          iVar7 = (**(code **)(**(int **)(this + 0x34) + 0x58))();
          if (iVar7 == 0) {
            return 0;
          }
          iVar7 = *(int *)this;
          uVar4 = 0x7b;
          uVar8 = (uVar8 & 0x3f) << 0x13 | local_7c & 0x7ffff;
          goto LAB_97b910f8;
        }
        uVar4 = 0x7d;
      }
      else {
        iVar7 = (**(code **)(**(int **)(this + 0x38) + 0x58))();
        if (iVar7 != 0) {
          return 0;
        }
        uVar4 = 0x7c;
      }
    }
LAB_97b9100c:
    *(undefined4 *)(this + 0x30) = uVar4;
    goto LAB_97b91520;
  }
  iVar7 = (**(code **)(**(int **)(this + 0x34) + 0x48))();
  iVar11 = (**(code **)(**(int **)(this + 0x38) + 0x48))();
  if (iVar7 != iVar11) {
    return 0;
  }
switchD_97b909e0_caseD_13:
  iVar7 = (**(code **)(**(int **)(this + 0x34) + 0x50))();
  if (((iVar7 == 0) || (iVar7 = (**(code **)(**(int **)(this + 0x38) + 0x58))(), iVar7 == 0)) &&
     ((iVar7 = (**(code **)(**(int **)(this + 0x34) + 0x58))(), iVar7 == 0 ||
      (iVar7 = (**(code **)(**(int **)(this + 0x38) + 0x50))(), iVar7 == 0)))) {
    iVar7 = (**(code **)(**(int **)(this + 0x34) + 0x40))();
    iVar11 = (**(code **)(**(int **)(this + 0x38) + 0x40))();
    if (iVar7 == iVar11) {
      iVar11 = 0;
      iVar7 = (**(code **)(**(int **)(this + 0x34) + 0x50))();
      if ((iVar7 != 0) || (iVar7 = (**(code **)(**(int **)(this + 0x38) + 0x50))(), iVar7 != 0)) {
        iVar11 = 1;
      }
      local_7c = iVar11 << 10 | (uVar6 & 0xff) << 0xb | (uVar8 & 0x3f) << 0x13 | local_7c & 0x1ff;
      pcVar12 = *(code **)(*(int *)this + 0x34);
LAB_97b91508:
      local_80 = 0;
      local_a0 = &PTR__TType_a7b7cff8;
      local_9c = local_80;
      local_98 = local_80;
      local_94 = local_80;
      local_90 = local_80;
      local_8c = local_80;
      local_88 = local_80;
      local_84 = local_80;
      (*pcVar12)(this,&local_a0);
      local_a0 = &PTR__TType_a7b7cff8;
LAB_97b91520:
      iVar7 = *(int *)(this + 0x30);
      if ((0x75 < iVar7) && ((iVar7 < 0x7a || (iVar7 - 0x7eU < 7)))) {
        (**(code **)(*(int *)this + 0x38))(&local_a0,this);
        (**(code **)(**(int **)(this + 0x34) + 0x38))(local_70);
        bVar1 = false;
        if (((local_7c & 0x1fffe00) == (local_4c & 0x1fffe00)) && (local_98 == local_68)) {
          bVar1 = true;
        }
        if (!bVar1) {
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
int compareStructure(param_1, param_2, param_3, param_4)
  unsigned char * param_1;
  unsigned char * param_2;
  unsigned char * param_3;
  int *param_4;
{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  uVar5 = 0;
  iVar6 = *(int *)(param_1 + 8);
  iVar2 = *(int *)(iVar6 + 4);
  uVar4 = *(int *)(iVar6 + 8) - iVar2 >> 3;
  if (uVar4 == 0) {
    return 1;
  }
  do {
    iVar1 = uVar5 * 8;
    iVar7 = 0;
    iVar2 = (**(code **)(**(int **)(iVar2 + iVar1) + 0x30))();
    if (0 < iVar2) {
      do {
        iVar3 = (**(code **)(**(int **)(*(int *)(iVar6 + 4) + iVar1) + 0x20))();
        if (iVar3 == 2) {
LAB_97b916a8:
          iVar3 = *param_4;
          if (*(int *)(param_3 + iVar3 * 4) != *(int *)(param_2 + iVar3 * 4)) {
            return 0;
          }
LAB_97b916c8:
          *param_4 = iVar3 + 1;
        }
        else if (iVar3 < 3) {
          if (iVar3 == 1) {
            iVar3 = *param_4;
            if (*(float *)(param_3 + iVar3 * 4) != *(float *)(param_2 + iVar3 * 4)) {
              return 0;
            }
            goto LAB_97b916c8;
          }
        }
        else {
          if (iVar3 == 3) goto LAB_97b916a8;
          if ((iVar3 == 0xe) &&
             (iVar3 = ((int (*)())compareStructure)(*(unsigned char **)(*(int *)(iVar6 + 4) + iVar1),param_2,param_3,
                                       param_4), iVar3 == 0)) {
            return 0;
          }
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < iVar2);
    }
    uVar5 = uVar5 + 1;
    if (uVar4 <= uVar5) {
      return 1;
    }
    iVar2 = *(int *)(iVar6 + 4);
  } while( true );
}

/* TIntermConstantUnion__fold @ 0x97b91724 (11632 bytes) */
int TIntermConstantUnion__fold(this, param_2, param_3, param_4, param_5)
  unsigned char * this;
  int param_2;
  unsigned char * param_3;
  char *param_4;
  int param_5;
{
  bool bVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  undefined **ppuVar5;
  float fVar6;
  float fVar7;
  uint uVar8;
  uint uVar9;
  undefined *puVar10;
  unsigned char * pcVar11;
  uint uVar12;
  undefined4 *puVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  int *piVar17;
  uint *puVar18;
  ulong uVar19;
  unsigned char * pTVar20;
  undefined4 uVar21;
  unsigned char * paVar22;
  int iVar23;
  float *pfVar24;
  float *pfVar25;
  unsigned char * pcVar26;
  int iVar27;
  undefined **ppuVar28;
  int iVar29;
  bool bVar30;
  char in_RESERVE;
  byte bVar31;
  int iVar32;
  double dVar33;
  double dVar34;
  undefined **local_1d0;
  int local_1cc;
  int local_1c8;
  int local_1c4;
  int local_1c0;
  int local_1bc;
  int local_1b8;
  int local_1b4;
  int local_1b0;
  uint local_1ac;
  undefined **local_1a0;
  int local_19c;
  int local_198;
  int local_194;
  int local_190;
  int local_18c;
  int local_188;
  int local_184;
  int local_180;
  uint local_17c;
  undefined **local_170;
  int local_16c;
  int local_168;
  int local_164;
  int local_160;
  int local_15c;
  int local_158;
  int local_154;
  int local_150;
  uint local_14c;
  undefined **local_140 [4];
  unsigned char aaStack_130 [16];
  unsigned char aaStack_120 [4];
  uint local_11c;
  undefined **local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  uint local_ec;
  unsigned char aaStack_e0 [16];
  char acStack_d0 [16];
  unsigned char aaStack_c0 [48];
  char acStack_90 [64];
  int local_50;
  int local_4c;
  
  pcVar26 = *(unsigned char **)(this + 0x30);
  if (param_3 == (unsigned char *)0x0) {
    iVar29 = 0;
    (**(code **)(*(int *)this + 0x4c))();
    uVar19 = GetGlobalPoolAllocator();
    pfVar25 = (float *)TPoolAllocator__allocate(uVar19);
    iVar14 = (**(code **)(*(int *)this + 0x4c))(this);
    if (1 < iVar14) {
      for (; iVar14 = (**(code **)(*(int *)this + 0x4c))(this), iVar29 < iVar14; iVar29 = iVar29 + 1
          ) {
        if (param_2 == 5) {
          (**(code **)(*(int *)this + 0x38))(&local_1d0,this);
          uVar16 = local_1ac >> 0x13 & 0x3f;
          local_1d0 = &PTR__TType_a7b7cff8;
          if (uVar16 != 1) {
            if (uVar16 == 2) {
              fVar7 = (float)-*(int *)(pcVar26 + iVar29 * 4);
              goto LAB_97b956a0;
            }
            uVar16 = (*(code *)**(undefined4 **)this)(this);
                    
            goto override_jmp_97b95640_case_0;
          }
          pfVar25[iVar29] = -*(float *)(pcVar26 + iVar29 * 4);
        }
        else {
          if (param_2 != 6) {
            return (unsigned char *)0x0;
          }
          (**(code **)(*(int *)this + 0x38))(&local_1d0,this);
          local_1d0 = &PTR__TType_a7b7cff8;
          if ((local_1ac >> 0x13 & 0x3f) != 3) {
            uVar16 = (*(code *)**(undefined4 **)this)(this);
                    
            goto override_jmp_97b95640_case_0;
          }
          fVar7 = (float)(*(uint *)(pcVar26 + iVar29 * 4) ^ 1);
LAB_97b956a0:
          pfVar25[iVar29] = fVar7;
        }
        local_1d0 = &PTR__TType_a7b7cff8;
      }
      uVar19 = GetGlobalPoolAllocator();
      pTVar20 = (unsigned char *)TPoolAllocator__allocate(uVar19);
      (**(code **)(*(int *)this + 0x38))(&local_1d0,this);
      *(int *)(pTVar20 + 4) = 0;
      *(undefined ***)pTVar20 = &PTR_getLine_a7b7cf90;
      *(int *)(pTVar20 + 0xc) = local_1cc;
      *(int *)(pTVar20 + 0x10) = local_1c8;
      *(int *)(pTVar20 + 0x14) = local_1c4;
      *(int *)(pTVar20 + 0x18) = local_1c0;
      *(int *)(pTVar20 + 0x1c) = local_1bc;
      *(int *)(pTVar20 + 0x20) = local_1b8;
      *(undefined ***)(pTVar20 + 8) = &PTR__TType_a7b7cff8;
      *(int *)(pTVar20 + 0x24) = local_1b4;
      *(int *)(pTVar20 + 0x28) = local_1b0;
      uVar8 = *(uint *)(pTVar20 + 0x2c);
      uVar12 = local_1ac & 0xfe000000;
      *(uint *)(pTVar20 + 0x2c) = uVar12 | uVar8 & 0x1ffffff;
      uVar9 = (local_1ac >> 0x13 & 0x3f) << 0x13;
      *(uint *)(pTVar20 + 0x2c) = uVar9 | uVar12 | uVar8 & 0x7ffff;
      uVar16 = local_1ac & 0x7f800;
      *(uint *)(pTVar20 + 0x2c) = uVar16 | uVar9 | uVar12 | uVar8 & 0x7ff;
      uVar3 = (local_1ac >> 10 & 1) << 10;
      *(uint *)(pTVar20 + 0x2c) = uVar3 | uVar16 | uVar9 | uVar12 | uVar8 & 0x3ff;
      puVar10 = PTR_vtable_a7b7c0c8;
      *(uint *)(pTVar20 + 0x2c) =
           (local_1ac >> 9 & 1) << 9 | uVar3 | uVar16 | uVar9 | uVar12 | uVar8 & 0x1ff;
      *(float **)(pTVar20 + 0x30) = pfVar25;
      *(undefined **)pTVar20 = puVar10 + 8;
      goto LAB_97b95bbc;
    }
    if (param_2 == 5) {
      (**(code **)(*(int *)this + 0x38))(&local_1d0,this);
      uVar16 = local_1ac >> 0x13 & 0x3f;
      local_1d0 = &PTR__TType_a7b7cff8;
      if (uVar16 == 1) {
        *pfVar25 = -**(float **)(this + 0x30);
        uVar19 = GetGlobalPoolAllocator();
        pTVar20 = (unsigned char *)TPoolAllocator__allocate(uVar19);
        uVar16 = local_1ac & 0x7ff | 0x4080000;
        goto LAB_97b9597c;
      }
      if (uVar16 == 2) {
        *pfVar25 = (float)-**(int **)(this + 0x30);
        uVar19 = GetGlobalPoolAllocator();
        pTVar20 = (unsigned char *)TPoolAllocator__allocate(uVar19);
        iVar14 = 2;
        goto LAB_97b9596c;
      }
      uVar16 = *(uint *)(this + 4);
                    
    }
    else {
      if (param_2 != 6) {
        return (unsigned char *)0x0;
      }
      (**(code **)(*(int *)this + 0x38))(&local_1d0,this);
      local_1d0 = &PTR__TType_a7b7cff8;
      if ((local_1ac >> 0x13 & 0x3f) == 3) {
        *pfVar25 = (float)(**(uint **)(this + 0x30) ^ 1);
        uVar19 = GetGlobalPoolAllocator();
        pTVar20 = (unsigned char *)TPoolAllocator__allocate(uVar19);
        iVar14 = 3;
LAB_97b9596c:
        uVar16 = iVar14 << 0x13 | local_1ac & 0xfff | 0x4000000;
LAB_97b9597c:
        local_1ac = uVar16 & 0xfffff9ff | 0x800;
        local_1cc = 0;
        local_1c8 = 0;
        local_1c4 = 0;
        local_1c0 = 0;
        local_1bc = 0;
        local_1b8 = 0;
        local_1b4 = 0;
        local_1b0 = 0;
        *(int *)(pTVar20 + 4) = 0;
        *(undefined ***)pTVar20 = &PTR_getLine_a7b7cf90;
        *(int *)(pTVar20 + 0xc) = 0;
        *(int *)(pTVar20 + 0x10) = 0;
        *(int *)(pTVar20 + 0x14) = 0;
        *(int *)(pTVar20 + 0x18) = 0;
        *(int *)(pTVar20 + 0x1c) = 0;
        *(int *)(pTVar20 + 0x20) = 0;
        *(undefined ***)(pTVar20 + 8) = &PTR__TType_a7b7cff8;
        *(int *)(pTVar20 + 0x24) = 0;
        *(int *)(pTVar20 + 0x28) = 0;
        uVar9 = *(uint *)(pTVar20 + 0x2c);
        uVar12 = uVar16 & 0xfe000000;
        *(uint *)(pTVar20 + 0x2c) = uVar12 | uVar9 & 0x1ffffff;
        uVar16 = (uVar16 >> 0x13 & 0x3f) << 0x13;
        *(uint *)(pTVar20 + 0x2c) = uVar16 | uVar12 | uVar9 & 0x7ffff;
        *(uint *)(pTVar20 + 0x2c) = uVar16 | uVar12 | uVar9 & 0x7ff | 0x800;
        *(uint *)(pTVar20 + 0x2c) = uVar16 | uVar12 | uVar9 & 0x3ff | 0x800;
        puVar10 = PTR_vtable_a7b7c0c8;
        *(uint *)(pTVar20 + 0x2c) = uVar16 | uVar12 | uVar9 & 0x1ff | 0x800;
        *(float **)(pTVar20 + 0x30) = pfVar25;
        *(undefined **)pTVar20 = puVar10 + 8;
LAB_97b95bbc:
        local_1d0 = &PTR__TType_a7b7cff8;
        iVar14 = *(int *)pTVar20;
        uVar21 = (*(code *)**(undefined4 **)this)(this);
        (**(code **)(iVar14 + 4))(pTVar20,uVar21);
        return pTVar20;
      }
      uVar16 = *(uint *)(this + 4);
                    
    }
override_jmp_97b95640_case_0:
    TInfoSinkBase__append(param_4);
    bVar30 = (uVar16 & 0xffff) == 0;
    bVar31 = bVar30 << 1;
    if (bVar30) {
      _sprintf((char *)&local_1c0,"%d:? ",(int)uVar16 >> 0x10);
    }
    else {
      _sprintf((char *)&local_1c0,"%d:%d",(int)uVar16 >> 0x10);
    }
    std__string__string((unsigned char *)&local_1d0,(char *)&local_1c0,(unsigned char *)&local_180);
    *(undefined *)((int)local_1d0 + (int)local_1d0[-3]) = *PTR__S_terminal_a7b7c0b8;
    TInfoSinkBase__append(param_4);
    ppuVar28 = local_1d0;
LAB_97b95b60:
    ppuVar5 = ppuVar28 + -1;
    do {
      puVar10 = *ppuVar5;
      if (in_RESERVE != '\0') {
        puVar2 = (undefined *)storeWordConditionalIndexed(puVar10 + -1,0,ppuVar5);
        *ppuVar5 = puVar2;
        bVar31 = 2;
      }
    } while (!(bool)(bVar31 >> 1 & 1));
    goto joined_r0x97b95b7c;
  }
  bVar30 = false;
  iVar14 = (**(code **)(*(int *)param_3 + 0x18))(param_3);
  if ((iVar14 != 0) && (iVar14 = (**(code **)(*(int *)param_3 + 0x4c))(param_3), iVar14 == 1)) {
    (**(code **)(*(int *)param_3 + 0x38))(&local_1d0,param_3);
    if (((local_1ac >> 0x13 & 0x3f) != 0xe) &&
       (iVar14 = (**(code **)(*(int *)this + 0x4c))(this), 1 < iVar14)) {
      bVar30 = true;
    }
    local_4c = -0x5847e8cc;
    local_1d0 = &PTR__TType_a7b7cff8;
    if (!bVar30) goto LAB_97b92a7c;
    iVar14 = (**(code **)(*(int *)param_3 + 0x18))(param_3);
    switch(param_2) {
    case 0x13:
      local_4c = -0x5847e8cc;
      (**(code **)(*(int *)this + 0x4c))(this);
      uVar19 = GetGlobalPoolAllocator();
      iVar29 = TPoolAllocator__allocate(uVar19);
      for (iVar27 = 0; iVar15 = (**(code **)(*(int *)this + 0x4c))(this), iVar27 < iVar15;
          iVar27 = iVar27 + 1) {
        (**(code **)(*(int *)this + 0x38))(&local_1a0,this);
        uVar16 = local_17c >> 0x13 & 0x3f;
        local_1a0 = (undefined **)(local_4c + -0x473c);
        if (uVar16 != 1) {
          if (uVar16 == 2) {
            *(int *)(iVar27 * 4 + iVar29) =
                 *(int *)(pcVar26 + iVar27 * 4) + **(int **)(iVar14 + 0x30);
            goto LAB_97b919a8;
          }
          uVar16 = (*(code *)**(undefined4 **)this)(this);
                    
override_jmp_97b9198c_case_0:
          TInfoSinkBase__append(param_4);
          bVar30 = (uVar16 & 0xffff) == 0;
          bVar31 = bVar30 << 1;
          if (bVar30) {
            _sprintf((char *)&local_190,"%d:? ",(int)uVar16 >> 0x10);
          }
          else {
            _sprintf((char *)&local_190,"%d:%d",(int)uVar16 >> 0x10);
          }
          std__string__string((unsigned char *)&local_1a0,(char *)&local_190,(unsigned char *)&local_150);
          *(undefined *)((int)local_1a0 + (int)local_1a0[-3]) = *PTR__S_terminal_a7b7c0b8;
          TInfoSinkBase__append(param_4);
          ppuVar28 = local_1a0 + -1;
          paVar22 = (unsigned char *)(local_1a0 + -3);
          do {
            puVar10 = *ppuVar28;
            if (in_RESERVE != '\0') {
              puVar2 = (undefined *)storeWordConditionalIndexed(puVar10 + -1,0,ppuVar28);
              *ppuVar28 = puVar2;
              bVar31 = 2;
            }
          } while (!(bool)(bVar31 >> 1 & 1));
          bVar30 = 0 < (int)puVar10;
          goto LAB_97b93fb8;
        }
        *(float *)(iVar29 + iVar27 * 4) =
             *(float *)(pcVar26 + iVar27 * 4) + **(float **)(iVar14 + 0x30);
LAB_97b919a8: ;
      }
      break;
    case 0x14:
      local_4c = -0x5847e8cc;
      (**(code **)(*(int *)this + 0x4c))(this);
      uVar19 = GetGlobalPoolAllocator();
      iVar29 = TPoolAllocator__allocate(uVar19);
      for (iVar27 = 0; iVar15 = (**(code **)(*(int *)this + 0x4c))(this), iVar27 < iVar15;
          iVar27 = iVar27 + 1) {
        (**(code **)(*(int *)this + 0x38))(&local_1a0,this);
        uVar16 = local_17c >> 0x13 & 0x3f;
        local_1a0 = (undefined **)(local_4c + -0x473c);
        if (uVar16 == 1) {
          if (param_5 == 0) {
            fVar7 = *(float *)(pcVar26 + iVar27 * 4);
            fVar6 = **(float **)(iVar14 + 0x30);
          }
          else {
            fVar6 = *(float *)(pcVar26 + iVar27 * 4);
            fVar7 = **(float **)(iVar14 + 0x30);
          }
          *(float *)(iVar29 + iVar27 * 4) = fVar6 - fVar7;
        }
        else {
          if (uVar16 != 2) {
            uVar16 = (*(code *)**(undefined4 **)this)(this);
                    
            goto override_jmp_97b9198c_case_0;
          }
          if (param_5 == 0) {
            iVar15 = **(int **)(iVar14 + 0x30) - *(int *)(pcVar26 + iVar27 * 4);
          }
          else {
            iVar15 = *(int *)(pcVar26 + iVar27 * 4) - **(int **)(iVar14 + 0x30);
          }
          *(int *)(iVar27 * 4 + iVar29) = iVar15;
        }
      }
      break;
    default:
      uVar16 = (*(code *)**(undefined4 **)this)(this);
                    
      TInfoSinkBase__append(param_4);
      bVar30 = (uVar16 & 0xffff) == 0;
      bVar31 = bVar30 << 1;
      if (bVar30) {
        _sprintf((char *)&local_190,"%d:? ",(int)uVar16 >> 0x10);
      }
      else {
        _sprintf((char *)&local_190,"%d:%d",(int)uVar16 >> 0x10);
      }
      std__string__string((unsigned char *)&local_1a0,(char *)&local_190,(unsigned char *)&local_150);
      *(undefined *)((int)local_1a0 + (int)local_1a0[-3]) = *PTR__S_terminal_a7b7c0b8;
      TInfoSinkBase__append(param_4);
      ppuVar5 = local_1a0 + -1;
      do {
        puVar10 = *ppuVar5;
        if (in_RESERVE != '\0') {
          puVar2 = (undefined *)storeWordConditionalIndexed(puVar10 + -1,0,ppuVar5);
          *ppuVar5 = puVar2;
          bVar31 = 2;
        }
        ppuVar28 = local_1a0;
      } while (!(bool)(bVar31 >> 1 & 1));
      goto joined_r0x97b95b7c;
    case 0x16:
      local_4c = -0x5847e8cc;
      (**(code **)(*(int *)this + 0x4c))(this);
      uVar19 = GetGlobalPoolAllocator();
      iVar29 = TPoolAllocator__allocate(uVar19);
      for (iVar27 = 0; iVar15 = (**(code **)(*(int *)this + 0x4c))(this), iVar27 < iVar15;
          iVar27 = iVar27 + 1) {
        (**(code **)(*(int *)this + 0x38))((unsigned char *)&local_1a0,this);
        uVar16 = local_17c >> 0x13 & 0x3f;
        local_1a0 = (undefined **)(local_4c + -0x473c);
        if (uVar16 == 1) {
          if (param_5 == 0) {
            if ((double)*(float *)(pcVar26 + iVar27 * 4) == DOUBLE_97c30a48) {
              uVar16 = (*(code *)**(undefined4 **)this)(this);
                    
              TInfoSinkBase__append(param_4);
              bVar30 = (uVar16 & 0xffff) == 0;
              bVar31 = bVar30 << 1;
              if (bVar30) {
                _sprintf((char *)&local_190,"%d:? ",(int)uVar16 >> 0x10);
              }
              else {
                _sprintf((char *)&local_190,"%d:%d",(int)uVar16 >> 0x10);
              }
              std__string__string((unsigned char *)&local_1a0,(char *)&local_190,(unsigned char *)&local_150);
              *(undefined *)((int)local_1a0 + (int)local_1a0[-3]) = *PTR__S_terminal_a7b7c0b8;
              TInfoSinkBase__append(param_4);
              ppuVar28 = local_1a0 + -1;
              do {
                puVar10 = *ppuVar28;
                if (in_RESERVE != '\0') {
                  puVar2 = (undefined *)storeWordConditionalIndexed(puVar10 + -1,0,ppuVar28);
                  *ppuVar28 = puVar2;
                  bVar31 = 2;
                }
              } while (!(bool)(bVar31 >> 1 & 1));
              if ((int)puVar10 < 1) {
                std__string___Rep___M_destroy((unsigned char *)(local_1a0 + -3));
              }
              TInfoSinkBase__append(param_4);
              TInfoSinkBase__append(param_4);
              TInfoSinkBase__append(param_4);
              fVar7 = FLOAT_97c3acb4;
            }
            else {
              fVar7 = (float)((double)**(float **)(iVar14 + 0x30) /
                             (double)*(float *)(pcVar26 + iVar27 * 4));
            }
            *(float *)(iVar27 * 4 + iVar29) = fVar7;
          }
          else {
            if ((double)**(float **)(iVar14 + 0x30) == DOUBLE_97c30a48) {
              uVar16 = (*(code *)**(undefined4 **)this)(this);
                    
              TInfoSinkBase__append(param_4);
              bVar30 = (uVar16 & 0xffff) == 0;
              bVar31 = bVar30 << 1;
              if (bVar30) {
                _sprintf((char *)&local_190,"%d:? ",(int)uVar16 >> 0x10);
              }
              else {
                _sprintf((char *)&local_190,"%d:%d",(int)uVar16 >> 0x10);
              }
              std__string__string((unsigned char *)&local_1a0,(char *)&local_190,(unsigned char *)&local_150);
              *(undefined *)((int)local_1a0 + (int)local_1a0[-3]) = *PTR__S_terminal_a7b7c0b8;
              TInfoSinkBase__append(param_4);
              ppuVar28 = local_1a0 + -1;
              do {
                puVar10 = *ppuVar28;
                if (in_RESERVE != '\0') {
                  puVar2 = (undefined *)storeWordConditionalIndexed(puVar10 + -1,0,ppuVar28);
                  *ppuVar28 = puVar2;
                  bVar31 = 2;
                }
              } while (!(bool)(bVar31 >> 1 & 1));
              if ((int)puVar10 < 1) {
                std__string___Rep___M_destroy((unsigned char *)(local_1a0 + -3));
              }
              TInfoSinkBase__append(param_4);
              TInfoSinkBase__append(param_4);
              TInfoSinkBase__append(param_4);
              iVar15 = iVar27 << 2;
              fVar7 = FLOAT_97c3acb4;
            }
            else {
              iVar15 = iVar27 * 4;
              fVar7 = (float)((double)*(float *)(pcVar26 + iVar15) /
                             (double)**(float **)(iVar14 + 0x30));
            }
            *(float *)(iVar29 + iVar15) = fVar7;
          }
        }
        else {
          if (uVar16 != 2) {
            uVar16 = (*(code *)**(undefined4 **)this)(this);
                    
            goto override_jmp_97b9198c_case_0;
          }
          if (param_5 == 0) {
            if (*(int *)(pcVar26 + iVar27 * 4) == 0) {
              uVar16 = (*(code *)**(undefined4 **)this)(this);
                    
              TInfoSinkBase__append(param_4);
              bVar30 = (uVar16 & 0xffff) == 0;
              bVar31 = bVar30 << 1;
              if (bVar30) {
                _sprintf((char *)&local_190,"%d:? ",(int)uVar16 >> 0x10);
              }
              else {
                _sprintf((char *)&local_190,"%d:%d",(int)uVar16 >> 0x10);
              }
              std__string__string((unsigned char *)&local_1a0,(char *)&local_190,(unsigned char *)&local_150);
              *(undefined *)((int)local_1a0 + (int)local_1a0[-3]) = *PTR__S_terminal_a7b7c0b8;
              TInfoSinkBase__append(param_4);
              ppuVar28 = local_1a0 + -1;
              do {
                puVar10 = *ppuVar28;
                if (in_RESERVE != '\0') {
                  puVar2 = (undefined *)storeWordConditionalIndexed(puVar10 + -1,0,ppuVar28);
                  *ppuVar28 = puVar2;
                  bVar31 = 2;
                }
              } while (!(bool)(bVar31 >> 1 & 1));
              if ((int)puVar10 < 1) {
                std__string___Rep___M_destroy((unsigned char *)(local_1a0 + -3));
              }
              TInfoSinkBase__append(param_4);
              TInfoSinkBase__append(param_4);
              TInfoSinkBase__append(param_4);
              iVar15 = 0x7fffffff;
            }
            else {
              iVar15 = **(int **)(iVar14 + 0x30) / *(int *)(pcVar26 + iVar27 * 4);
            }
            *(int *)(iVar27 * 4 + iVar29) = iVar15;
          }
          else {
            if (**(int **)(iVar14 + 0x30) == 0) {
              uVar16 = (*(code *)**(undefined4 **)this)(this);
                    
              TInfoSinkBase__append(param_4);
              bVar30 = (uVar16 & 0xffff) == 0;
              bVar31 = bVar30 << 1;
              if (bVar30) {
                _sprintf((char *)&local_190,"%d:? ",(int)uVar16 >> 0x10);
              }
              else {
                _sprintf((char *)&local_190,"%d:%d",(int)uVar16 >> 0x10);
              }
              std__string__string((unsigned char *)&local_1a0,(char *)&local_190,(unsigned char *)&local_150);
              *(undefined *)((int)local_1a0 + (int)local_1a0[-3]) = *PTR__S_terminal_a7b7c0b8;
              TInfoSinkBase__append(param_4);
              ppuVar28 = local_1a0 + -1;
              do {
                puVar10 = *ppuVar28;
                if (in_RESERVE != '\0') {
                  puVar2 = (undefined *)storeWordConditionalIndexed(puVar10 + -1,0,ppuVar28);
                  *ppuVar28 = puVar2;
                  bVar31 = 2;
                }
              } while (!(bool)(bVar31 >> 1 & 1));
              if ((int)puVar10 < 1) {
                std__string___Rep___M_destroy((unsigned char *)(local_1a0 + -3));
              }
              TInfoSinkBase__append(param_4);
              TInfoSinkBase__append(param_4);
              TInfoSinkBase__append(param_4);
              iVar4 = 0x7fffffff;
              iVar15 = iVar27 << 2;
            }
            else {
              iVar15 = iVar27 * 4;
              iVar4 = *(int *)(pcVar26 + iVar15) / **(int **)(iVar14 + 0x30);
            }
            *(int *)(iVar15 + iVar29) = iVar4;
          }
        }
      }
      break;
    case 0x26:
    case 0x29:
      local_4c = -0x5847e8cc;
      (**(code **)(*(int *)this + 0x4c))(this);
      uVar19 = GetGlobalPoolAllocator();
      iVar29 = TPoolAllocator__allocate(uVar19);
      for (iVar27 = 0; iVar15 = (**(code **)(*(int *)this + 0x4c))(this), iVar27 < iVar15;
          iVar27 = iVar27 + 1) {
        (**(code **)(*(int *)this + 0x38))((unsigned char *)&local_1a0,this);
        uVar16 = local_17c >> 0x13 & 0x3f;
        local_1a0 = (undefined **)(local_4c + -0x473c);
        if (uVar16 == 1) {
          *(float *)(iVar29 + iVar27 * 4) =
               *(float *)(pcVar26 + iVar27 * 4) * **(float **)(iVar14 + 0x30);
        }
        else {
          if (uVar16 != 2) {
            uVar16 = (*(code *)**(undefined4 **)this)(this);
                    
            TInfoSinkBase__append(param_4);
            bVar30 = (uVar16 & 0xffff) == 0;
            bVar31 = bVar30 << 1;
            if (bVar30) {
              _sprintf((char *)local_140,"%d:? ",(int)uVar16 >> 0x10);
            }
            else {
              _sprintf((char *)local_140,"%d:%d",(int)uVar16 >> 0x10);
            }
            std__string__string((unsigned char *)&local_1a0,(char *)local_140,(unsigned char *)&local_190);
            *(undefined *)((int)local_1a0 + (int)local_1a0[-3]) = *PTR__S_terminal_a7b7c0b8;
            TInfoSinkBase__append(param_4);
            ppuVar28 = local_1a0;
            goto LAB_97b932f0;
          }
          *(int *)(iVar27 * 4 + iVar29) = *(int *)(pcVar26 + iVar27 * 4) * **(int **)(iVar14 + 0x30)
          ;
        }
      }
      break;
    case 0x2a:
      local_4c = -0x5847e8cc;
      (**(code **)(*(int *)this + 0x4c))(this);
      uVar19 = GetGlobalPoolAllocator();
      iVar29 = TPoolAllocator__allocate(uVar19);
      for (iVar27 = 0; iVar15 = (**(code **)(*(int *)this + 0x4c))(this), iVar27 < iVar15;
          iVar27 = iVar27 + 1) {
        (**(code **)(*(int *)this + 0x38))(&local_1a0,this);
        local_1a0 = (undefined **)(local_4c + -0x473c);
        if ((local_17c >> 0x13 & 0x3f) != 3) {
          uVar16 = (*(code *)**(undefined4 **)this)(this);
                    
          goto override_jmp_97b9198c_case_0;
        }
        uVar21 = 0;
        if ((*(int *)(pcVar26 + iVar27 * 4) != 0) || (**(int **)(iVar14 + 0x30) != 0)) {
          uVar21 = 1;
        }
        *(undefined4 *)(iVar27 * 4 + iVar29) = uVar21;
      }
      break;
    case 0x2b:
      local_4c = -0x5847e8cc;
      (**(code **)(*(int *)this + 0x4c))(this);
      uVar19 = GetGlobalPoolAllocator();
      iVar29 = TPoolAllocator__allocate(uVar19);
      for (iVar27 = 0; iVar15 = (**(code **)(*(int *)this + 0x4c))(this), iVar27 < iVar15;
          iVar27 = iVar27 + 1) {
        (**(code **)(*(int *)this + 0x38))(&local_1a0,this);
        local_1a0 = (undefined **)(local_4c + -0x473c);
        if ((local_17c >> 0x13 & 0x3f) != 3) {
          uVar16 = (*(code *)**(undefined4 **)this)(this);
                    
          goto override_jmp_97b9198c_case_0;
        }
        *(uint *)(iVar27 * 4 + iVar29) =
             (uint)(*(int *)(pcVar26 + iVar27 * 4) != **(int **)(iVar14 + 0x30));
      }
      break;
    case 0x2c:
      local_4c = -0x5847e8cc;
      (**(code **)(*(int *)this + 0x4c))(this);
      uVar19 = GetGlobalPoolAllocator();
      iVar29 = TPoolAllocator__allocate(uVar19);
      for (iVar27 = 0; iVar15 = (**(code **)(*(int *)this + 0x4c))(this), iVar27 < iVar15;
          iVar27 = iVar27 + 1) {
        (**(code **)(*(int *)this + 0x38))(&local_1a0,this);
        local_1a0 = (undefined **)(local_4c + -0x473c);
        if ((local_17c >> 0x13 & 0x3f) != 3) {
          uVar16 = (*(code *)**(undefined4 **)this)(this);
                    
          goto override_jmp_97b9198c_case_0;
        }
        uVar21 = 0;
        if ((*(int *)(pcVar26 + iVar27 * 4) != 0) && (**(int **)(iVar14 + 0x30) != 0)) {
          uVar21 = 1;
        }
        *(undefined4 *)(iVar27 * 4 + iVar29) = uVar21;
      }
    }
    uVar19 = GetGlobalPoolAllocator();
    pTVar20 = (unsigned char *)TPoolAllocator__allocate(uVar19);
    (**(code **)(*(int *)this + 0x38))(&local_1a0,this);
    *(int *)(pTVar20 + 4) = 0;
    *(undefined ***)pTVar20 = &PTR_getLine_a7b7cf90;
    *(int *)(pTVar20 + 0xc) = local_19c;
    local_1a0 = (undefined **)(local_4c + -0x473c);
    *(int *)(pTVar20 + 0x10) = local_198;
    *(int *)(pTVar20 + 0x14) = local_194;
    *(int *)(pTVar20 + 0x18) = local_190;
    *(int *)(pTVar20 + 0x1c) = local_18c;
    *(int *)(pTVar20 + 0x20) = local_188;
    *(undefined ***)(pTVar20 + 8) = local_1a0;
    *(int *)(pTVar20 + 0x24) = local_184;
    *(int *)(pTVar20 + 0x28) = local_180;
    uVar8 = *(uint *)(pTVar20 + 0x2c);
    uVar12 = local_17c & 0xfe000000;
    *(uint *)(pTVar20 + 0x2c) = uVar12 | uVar8 & 0x1ffffff;
    uVar9 = (local_17c >> 0x13 & 0x3f) << 0x13;
    *(uint *)(pTVar20 + 0x2c) = uVar9 | uVar12 | uVar8 & 0x7ffff;
    uVar16 = local_17c & 0x7f800;
    *(uint *)(pTVar20 + 0x2c) = uVar16 | uVar9 | uVar12 | uVar8 & 0x7ff;
    uVar3 = (local_17c >> 10 & 1) << 10;
    *(uint *)(pTVar20 + 0x2c) = uVar3 | uVar16 | uVar9 | uVar12 | uVar8 & 0x3ff;
    puVar10 = PTR_vtable_a7b7c0c8;
    *(uint *)(pTVar20 + 0x2c) =
         (local_17c >> 9 & 1) << 9 | uVar3 | uVar16 | uVar9 | uVar12 | uVar8 & 0x1ff;
    *(undefined **)pTVar20 = puVar10 + 8;
    *(int *)(pTVar20 + 0x30) = iVar29;
    goto LAB_97b94758;
  }
LAB_97b92a7c:
  iVar14 = (**(code **)(*(int *)param_3 + 0x18))(param_3);
  if (iVar14 != 0) {
    iVar14 = (**(code **)(*(int *)this + 0x4c))(this);
    if (iVar14 < 2) {
      local_4c = -0x5847e8cc;
      (**(code **)(*(int *)this + 0x38))(&local_1a0,this);
      local_1a0 = (undefined **)(local_4c + -0x473c);
      if ((local_17c >> 0x13 & 0x3f) != 0xe) goto LAB_97b9478c;
    }
    iVar14 = 0;
    bVar30 = false;
    piVar17 = (int *)(**(code **)(*(int *)param_3 + 0x18))(param_3);
    pfVar25 = (float *)piVar17[0xc];
    local_50 = 0;
    switch(param_2) {
    case 0x13:
      local_4c = -0x5847e8cc;
      (**(code **)(*(int *)this + 0x4c))(this);
      uVar19 = GetGlobalPoolAllocator();
      iVar14 = TPoolAllocator__allocate(uVar19);
      for (iVar29 = 0; iVar27 = (**(code **)(*(int *)this + 0x4c))(this), iVar29 < iVar27;
          iVar29 = iVar29 + 1) {
        (**(code **)(*(int *)this + 0x38))(&local_170,this);
        uVar16 = local_14c >> 0x13 & 0x3f;
        local_170 = (undefined **)(local_4c + -0x473c);
        if (uVar16 != 1) {
          if (uVar16 == 2) {
            *(int *)(iVar14 + iVar29 * 4) = *(int *)(pcVar26 + iVar29 * 4) + (int)pfVar25[iVar29];
            goto LAB_97b92dd4;
          }
          uVar16 = (*(code *)**(undefined4 **)this)(this);
                    
          TInfoSinkBase__append(param_4);
          bVar30 = (uVar16 & 0xffff) == 0;
          bVar31 = bVar30 << 1;
          if (bVar30) {
            _sprintf((char *)&local_160,"%d:? ",(int)uVar16 >> 0x10);
          }
          else {
            _sprintf((char *)&local_160,"%d:%d",(int)uVar16 >> 0x10);
          }
          paVar22 = (unsigned char *)&local_100;
LAB_97b93f6c:
          std__string__string((unsigned char *)&local_170,(char *)&local_160,paVar22);
          *(undefined *)((int)local_170 + (int)local_170[-3]) = *PTR__S_terminal_a7b7c0b8;
          TInfoSinkBase__append(param_4);
          ppuVar28 = local_170 + -1;
          paVar22 = (unsigned char *)(local_170 + -3);
          do {
            puVar10 = *ppuVar28;
            if (in_RESERVE != '\0') {
              puVar2 = (undefined *)storeWordConditionalIndexed(puVar10 + -1,0,ppuVar28);
              *ppuVar28 = puVar2;
              bVar31 = 2;
            }
          } while (!(bool)(bVar31 >> 1 & 1));
          bVar30 = 0 < (int)puVar10;
          goto LAB_97b93fb8;
        }
        *(float *)(iVar14 + iVar29 * 4) = *(float *)(pcVar26 + iVar29 * 4) + pfVar25[iVar29];
LAB_97b92dd4: ;
      }
      break;
    case 0x14:
      local_4c = -0x5847e8cc;
      (**(code **)(*(int *)this + 0x4c))(this);
      uVar19 = GetGlobalPoolAllocator();
      iVar14 = TPoolAllocator__allocate(uVar19);
      for (iVar29 = 0; iVar27 = (**(code **)(*(int *)this + 0x4c))(this), iVar29 < iVar27;
          iVar29 = iVar29 + 1) {
        (**(code **)(*(int *)this + 0x38))(&local_170,this);
        uVar16 = local_14c >> 0x13 & 0x3f;
        local_170 = (undefined **)(local_4c + -0x473c);
        if (uVar16 == 1) {
          if (param_5 == 0) {
            fVar7 = pfVar25[iVar29];
            fVar6 = *(float *)(pcVar26 + iVar29 * 4);
          }
          else {
            fVar7 = *(float *)(pcVar26 + iVar29 * 4);
            fVar6 = pfVar25[iVar29];
          }
          *(float *)(iVar14 + iVar29 * 4) = fVar7 - fVar6;
        }
        else {
          if (uVar16 != 2) {
            uVar16 = (*(code *)**(undefined4 **)this)(this);
                    
            TInfoSinkBase__append(param_4);
            bVar30 = (uVar16 & 0xffff) == 0;
            bVar31 = bVar30 << 1;
            if (bVar30) {
              _sprintf((char *)&local_160,"%d:? ",(int)uVar16 >> 0x10);
            }
            else {
              _sprintf((char *)&local_160,"%d:%d",(int)uVar16 >> 0x10);
            }
            paVar22 = (unsigned char *)&local_f0;
            goto LAB_97b93f6c;
          }
          if (param_5 == 0) {
            fVar7 = pfVar25[iVar29];
            fVar6 = *(float *)(pcVar26 + iVar29 * 4);
          }
          else {
            fVar7 = *(float *)(pcVar26 + iVar29 * 4);
            fVar6 = pfVar25[iVar29];
          }
          *(int *)(iVar14 + iVar29 * 4) = (int)fVar7 - (int)fVar6;
        }
      }
      break;
    case 0x15:
      iVar29 = (**(code **)(*(int *)this + 0x58))(this);
      if (iVar29 != 0) {
        iVar27 = 0;
        iVar29 = (**(code **)(*(int *)this + 0x4c))(this);
        uVar19 = GetGlobalPoolAllocator();
        iVar14 = TPoolAllocator__allocate(uVar19);
        if (0 < iVar29) {
          local_4c = -0x5847e8cc;
          do {
            (**(code **)(*(int *)this + 0x38))(&local_170,this);
            uVar16 = local_14c >> 0x13 & 0x3f;
            local_170 = (undefined **)(local_4c + -0x473c);
            if (uVar16 == 1) {
              *(float *)(iVar14 + iVar27 * 4) = *(float *)(pcVar26 + iVar27 * 4) * pfVar25[iVar27];
            }
            else {
              if (uVar16 != 2) {
                uVar16 = (*(code *)**(undefined4 **)this)(this);
                    
                TInfoSinkBase__append(param_4);
                bVar30 = (uVar16 & 0xffff) == 0;
                bVar31 = bVar30 << 1;
                if (bVar30) {
                  _sprintf((char *)&local_160,"%d:? ",(int)uVar16 >> 0x10);
                }
                else {
                  _sprintf((char *)&local_160,"%d:%d",(int)uVar16 >> 0x10);
                }
                paVar22 = aaStack_e0;
                goto LAB_97b93f6c;
              }
              *(int *)(iVar14 + iVar27 * 4) = *(int *)(pcVar26 + iVar27 * 4) * (int)pfVar25[iVar27];
            }
            iVar27 = iVar27 + 1;
          } while (iVar27 < iVar29);
          break;
        }
      }
      local_4c = -0x5847e8cc;
      break;
    case 0x16:
      local_4c = -0x5847e8cc;
      (**(code **)(*(int *)this + 0x4c))(this);
      uVar19 = GetGlobalPoolAllocator();
      iVar14 = TPoolAllocator__allocate(uVar19);
      for (iVar29 = 0; iVar27 = (**(code **)(*(int *)this + 0x4c))(this), iVar29 < iVar27;
          iVar29 = iVar29 + 1) {
        (**(code **)(*(int *)this + 0x38))((unsigned char *)&local_170,this);
        uVar16 = local_14c >> 0x13 & 0x3f;
        local_170 = (undefined **)(local_4c + -0x473c);
        if (uVar16 != 1) {
          if (uVar16 == 2) {
            if (param_5 == 0) {
              fVar7 = *(float *)(pcVar26 + iVar29 * 4);
              if (fVar7 == 0.0) {
                uVar16 = (*(code *)**(undefined4 **)this)(this);
                    
                goto override_jmp_97b93698_case_0;
              }
              fVar6 = pfVar25[iVar29];
LAB_97b93828:
              iVar27 = (int)fVar6 / (int)fVar7;
            }
            else {
              fVar7 = pfVar25[iVar29];
              if (fVar7 != 0.0) {
                fVar6 = *(float *)(pcVar26 + iVar29 * 4);
                goto LAB_97b93828;
              }
              uVar16 = (*(code *)**(undefined4 **)this)(this);
                    
override_jmp_97b93698_case_0:
              TInfoSinkBase__append(param_4);
              bVar30 = (uVar16 & 0xffff) == 0;
              bVar31 = bVar30 << 1;
              if (bVar30) {
                _sprintf((char *)&local_160,"%d:? ",(int)uVar16 >> 0x10);
              }
              else {
                _sprintf((char *)&local_160,"%d:%d",(int)uVar16 >> 0x10);
              }
              std__string__string((unsigned char *)&local_170,(char *)&local_160,aaStack_120);
              *(undefined *)((int)local_170 + (int)local_170[-3]) = *PTR__S_terminal_a7b7c0b8;
              TInfoSinkBase__append(param_4);
              ppuVar28 = local_170 + -1;
              do {
                puVar10 = *ppuVar28;
                if (in_RESERVE != '\0') {
                  puVar2 = (undefined *)storeWordConditionalIndexed(puVar10 + -1,0,ppuVar28);
                  *ppuVar28 = puVar2;
                  bVar31 = 2;
                }
              } while (!(bool)(bVar31 >> 1 & 1));
              if ((int)puVar10 < 1) {
                std__string___Rep___M_destroy((unsigned char *)(local_170 + -3));
              }
              TInfoSinkBase__append(param_4);
              TInfoSinkBase__append(param_4);
              TInfoSinkBase__append(param_4);
              iVar27 = 0x7fffffff;
            }
            *(int *)(iVar29 * 4 + iVar14) = iVar27;
            goto LAB_97b93884;
          }
          uVar16 = (*(code *)**(undefined4 **)this)(this);
                    
override_jmp_97b93868_case_0:
          TInfoSinkBase__append(param_4);
          bVar30 = (uVar16 & 0xffff) == 0;
          bVar31 = bVar30 << 1;
          if (bVar30) {
            _sprintf((char *)&local_160,"%d:? ",(int)uVar16 >> 0x10);
          }
          else {
            _sprintf((char *)&local_160,"%d:%d",(int)uVar16 >> 0x10);
          }
          paVar22 = aaStack_120;
          goto LAB_97b93f6c;
        }
        if (param_5 == 0) {
          dVar33 = (double)*(float *)(pcVar26 + iVar29 * 4);
          if (dVar33 == DOUBLE_97c30a48) {
            uVar16 = (*(code *)**(undefined4 **)this)(this);
                    
            goto override_jmp_97b934a8_case_0;
          }
          fVar7 = pfVar25[iVar29];
LAB_97b93640:
          fVar7 = (float)((double)fVar7 / dVar33);
        }
        else {
          dVar33 = (double)pfVar25[iVar29];
          if (dVar33 != DOUBLE_97c30a48) {
            fVar7 = *(float *)(pcVar26 + iVar29 * 4);
            goto LAB_97b93640;
          }
          uVar16 = (*(code *)**(undefined4 **)this)(this);
                    
override_jmp_97b934a8_case_0:
          TInfoSinkBase__append(param_4);
          bVar30 = (uVar16 & 0xffff) == 0;
          bVar31 = bVar30 << 1;
          if (bVar30) {
            _sprintf((char *)&local_160,"%d:? ",(int)uVar16 >> 0x10);
          }
          else {
            _sprintf((char *)&local_160,"%d:%d",(int)uVar16 >> 0x10);
          }
          std__string__string((unsigned char *)&local_170,(char *)&local_160,aaStack_120);
          *(undefined *)((int)local_170 + (int)local_170[-3]) = *PTR__S_terminal_a7b7c0b8;
          TInfoSinkBase__append(param_4);
          ppuVar28 = local_170 + -1;
          do {
            puVar10 = *ppuVar28;
            if (in_RESERVE != '\0') {
              puVar2 = (undefined *)storeWordConditionalIndexed(puVar10 + -1,0,ppuVar28);
              *ppuVar28 = puVar2;
              bVar31 = 2;
            }
          } while (!(bool)(bVar31 >> 1 & 1));
          if ((int)puVar10 < 1) {
            std__string___Rep___M_destroy((unsigned char *)(local_170 + -3));
          }
          TInfoSinkBase__append(param_4);
          TInfoSinkBase__append(param_4);
          TInfoSinkBase__append(param_4);
          fVar7 = FLOAT_97c3acb4;
        }
        *(float *)(iVar29 * 4 + iVar14) = fVar7;
LAB_97b93884: ;
      }
      break;
    default:
      uVar16 = (*(code *)**(undefined4 **)this)(this);
                    
override_jmp_97b938f4_case_0:
      TInfoSinkBase__append(param_4);
      bVar30 = (uVar16 & 0xffff) == 0;
      bVar31 = bVar30 << 1;
      if (bVar30) {
        _sprintf((char *)&local_160,"%d:? ",(int)uVar16 >> 0x10);
      }
      else {
        _sprintf((char *)&local_160,"%d:%d",(int)uVar16 >> 0x10);
      }
      goto LAB_97b945f4;
    case 0x1d:
      local_4c = -0x5847e8cc;
      (**(code **)(*(int *)this + 0x38))((unsigned char *)&local_170,this);
      uVar16 = local_14c >> 0x13 & 0x3f;
      ppuVar28 = (undefined **)(local_4c + -0x473c);
      local_170 = ppuVar28;
      if (uVar16 == 2) {
        for (iVar14 = 0; iVar29 = (**(code **)(*(int *)this + 0x4c))(this), iVar14 < iVar29;
            iVar14 = iVar14 + 1) {
          if (*(float *)(pcVar26 + iVar14 * 4) != pfVar25[iVar14]) goto LAB_97b94304;
        }
        goto LAB_97b943d4;
      }
      if (2 < uVar16) {
        if (uVar16 == 3) {
          for (iVar14 = 0; iVar29 = (**(code **)(*(int *)this + 0x4c))(this), iVar14 < iVar29;
              iVar14 = iVar14 + 1) {
            if (*(float *)(pcVar26 + iVar14 * 4) != pfVar25[iVar14]) goto LAB_97b94304;
          }
        }
        else {
          if (uVar16 != 0xe) goto LAB_97b9414c;
          pcVar11 = (unsigned char *)piVar17[0xc];
          (**(code **)(*piVar17 + 0x38))((unsigned char *)&local_170,piVar17);
          iVar14 = ((int (*)())compareStructure)((unsigned char *)&local_170,pcVar11,pcVar26,&local_50);
          bVar1 = iVar14 == 1;
LAB_97b942fc:
          local_170 = ppuVar28;
          if (!bVar1) {
LAB_97b94304:
            bVar30 = true;
          }
        }
        goto LAB_97b943d4;
      }
      if (uVar16 == 1) {
        for (iVar14 = 0; iVar29 = (**(code **)(*(int *)this + 0x4c))(this), iVar14 < iVar29;
            iVar14 = iVar14 + 1) {
          if (*(float *)(pcVar26 + iVar14 * 4) != pfVar25[iVar14]) goto LAB_97b94304;
        }
        goto LAB_97b943d4;
      }
LAB_97b9414c:
      uVar16 = (*(code *)**(undefined4 **)this)(this);
                    
override_jmp_97b94180_case_0:
      TInfoSinkBase__append(param_4);
      bVar30 = (uVar16 & 0xffff) == 0;
      bVar31 = bVar30 << 1;
      if (bVar30) {
        _sprintf((char *)&local_160,"%d:? ",(int)uVar16 >> 0x10);
      }
      else {
        _sprintf((char *)&local_160,"%d:%d",(int)uVar16 >> 0x10);
      }
LAB_97b945f4:
      std__string__string((unsigned char *)&local_170,(char *)&local_160,aaStack_120);
      *(undefined *)((int)local_170 + (int)local_170[-3]) = *PTR__S_terminal_a7b7c0b8;
      TInfoSinkBase__append(param_4);
      ppuVar5 = local_170 + -1;
      do {
        puVar10 = *ppuVar5;
        if (in_RESERVE != '\0') {
          puVar2 = (undefined *)storeWordConditionalIndexed(puVar10 + -1,0,ppuVar5);
          *ppuVar5 = puVar2;
          bVar31 = 2;
        }
        ppuVar28 = local_170;
      } while (!(bool)(bVar31 >> 1 & 1));
joined_r0x97b95b7c:
      if ((int)puVar10 < 1) {
        std__string___Rep___M_destroy((unsigned char *)(ppuVar28 + -3));
      }
      TInfoSinkBase__append(param_4);
LAB_97b95ba0:
      TInfoSinkBase__append(param_4);
      TInfoSinkBase__append(param_4);
switchD_97b94d20_caseD_17:
      return (unsigned char *)0x0;
    case 0x1e:
      local_4c = -0x5847e8cc;
      (**(code **)(*(int *)this + 0x38))((unsigned char *)&local_170,this);
      uVar16 = local_14c >> 0x13 & 0x3f;
      ppuVar28 = (undefined **)(local_4c + -0x473c);
      local_170 = ppuVar28;
      if (uVar16 == 2) {
        for (iVar14 = 0; iVar29 = (**(code **)(*(int *)this + 0x4c))(this), iVar14 < iVar29;
            iVar14 = iVar14 + 1) {
          if (*(float *)(pcVar26 + iVar14 * 4) == pfVar25[iVar14]) goto LAB_97b94304;
        }
      }
      else if (uVar16 < 3) {
        if (uVar16 != 1) {
LAB_97b9430c:
          uVar16 = (*(code *)**(undefined4 **)this)(this);
                    
          goto override_jmp_97b94180_case_0;
        }
        for (iVar14 = 0; iVar29 = (**(code **)(*(int *)this + 0x4c))(this), iVar14 < iVar29;
            iVar14 = iVar14 + 1) {
          if (*(float *)(pcVar26 + iVar14 * 4) == pfVar25[iVar14]) goto LAB_97b94304;
        }
      }
      else {
        if (uVar16 != 3) {
          if (uVar16 == 0xe) {
            pcVar11 = (unsigned char *)piVar17[0xc];
            (**(code **)(*piVar17 + 0x38))((unsigned char *)&local_170,piVar17);
            iVar14 = ((int (*)())compareStructure)((unsigned char *)&local_170,pcVar11,pcVar26,&local_50);
            bVar1 = iVar14 == 0;
            goto LAB_97b942fc;
          }
          goto LAB_97b9430c;
        }
        for (iVar14 = 0; iVar29 = (**(code **)(*(int *)this + 0x4c))(this), iVar14 < iVar29;
            iVar14 = iVar14 + 1) {
          if (*(float *)(pcVar26 + iVar14 * 4) == pfVar25[iVar14]) goto LAB_97b94304;
        }
      }
LAB_97b943d4:
      uVar19 = GetGlobalPoolAllocator();
      puVar18 = (uint *)TPoolAllocator__allocate(uVar19);
      *puVar18 = (uint)!bVar30;
      uVar19 = GetGlobalPoolAllocator();
      pTVar20 = (unsigned char *)TPoolAllocator__allocate(uVar19);
      local_14c = local_14c & 0x1801ff | 0x4180800;
      local_170 = (undefined **)(local_4c + -0x473c);
      local_16c = 0;
      local_164 = 0;
      local_160 = 0;
      local_15c = 0;
      local_158 = 0;
      local_154 = 0;
      local_150 = 0;
      local_168 = 0;
      *(int *)(pTVar20 + 4) = 0;
      *(undefined ***)pTVar20 = &PTR_getLine_a7b7cf90;
      *(int *)(pTVar20 + 0xc) = 0;
      *(int *)(pTVar20 + 0x10) = 0;
      *(int *)(pTVar20 + 0x14) = 0;
      *(int *)(pTVar20 + 0x18) = 0;
      *(int *)(pTVar20 + 0x1c) = 0;
      *(int *)(pTVar20 + 0x20) = 0;
      *(undefined ***)(pTVar20 + 8) = local_170;
      *(int *)(pTVar20 + 0x24) = 0;
      *(int *)(pTVar20 + 0x28) = 0;
      uVar12 = *(uint *)(pTVar20 + 0x2c);
      *(uint *)(pTVar20 + 0x2c) = uVar12 & 0x1ffffff | 0x4000000;
      uVar16 = (local_14c >> 0x13 & 0x3f) << 0x13;
      *(uint *)(pTVar20 + 0x2c) = uVar16 | uVar12 & 0x7ffff | 0x4000000;
      *(uint *)(pTVar20 + 0x2c) = uVar16 | uVar12 & 0x7ff | 0x4000000 | 0x800;
      *(uint *)(pTVar20 + 0x2c) = uVar16 | uVar12 & 0x3ff | 0x4000000 | 0x800;
      puVar10 = PTR_vtable_a7b7c0c8;
      *(uint *)(pTVar20 + 0x2c) = uVar16 | uVar12 & 0x1ff | 0x4000000 | 0x800;
      *(uint **)(pTVar20 + 0x30) = puVar18;
      *(undefined **)pTVar20 = puVar10 + 8;
      puVar13 = *(undefined4 **)this;
LAB_97b953d4:
      iVar14 = *(int *)pTVar20;
      uVar21 = (*(code *)*puVar13)(this);
      (**(code **)(iVar14 + 4))(pTVar20,uVar21);
      return pTVar20;
    case 0x27:
      local_4c = -0x5847e8cc;
      (**(code **)(*(int *)this + 0x38))(&local_170,this);
      local_170 = (undefined **)(local_4c + -0x473c);
      if ((local_14c >> 0x13 & 0x3f) != 1) {
        uVar16 = (*(code *)**(undefined4 **)this)(this);
                    
        TInfoSinkBase__append(param_4);
        bVar30 = (uVar16 & 0xffff) == 0;
        bVar31 = bVar30 << 1;
        if (bVar30) {
          _sprintf((char *)aaStack_130,"%d:? ",(int)uVar16 >> 0x10);
        }
        else {
          _sprintf((char *)aaStack_130,"%d:%d",(int)uVar16 >> 0x10);
        }
        std__string__string((unsigned char *)local_140,(char *)aaStack_130,(unsigned char *)&local_f0);
        *(undefined *)((int)local_140[0] + (int)local_140[0][-3]) = *PTR__S_terminal_a7b7c0b8;
        TInfoSinkBase__append(param_4);
        ppuVar28 = local_140;
        goto LAB_97b95b60;
      }
      (**(code **)(*(int *)this + 0x48))(this);
      uVar19 = GetGlobalPoolAllocator();
      iVar14 = TPoolAllocator__allocate(uVar19);
      iVar29 = (**(code **)(*(int *)this + 0x48))(this);
      iVar27 = 0;
      if (0 < iVar29) {
        iVar15 = 0;
        do {
          iVar4 = iVar27 * 4;
          *(undefined4 *)(iVar4 + iVar14) = 0;
          if (0 < iVar29) {
            pfVar24 = pfVar25 + iVar15;
            pcVar11 = pcVar26;
            iVar23 = iVar29;
            do {
              fVar7 = *(float *)pcVar11;
              pcVar11 = pcVar11 + 4;
              fVar6 = *pfVar24;
              pfVar24 = pfVar24 + 1;
              *(float *)(iVar4 + iVar14) = fVar7 * fVar6 + *(float *)(iVar4 + iVar14);
              iVar23 = iVar23 + -1;
            } while (iVar23 != 0);
          }
          iVar27 = iVar27 + 1;
          iVar15 = iVar15 + iVar29;
        } while (iVar27 < iVar29);
      }
      break;
    case 0x28:
      iVar14 = (**(code **)(*piVar17 + 0x40))();
      if (iVar14 != 1) {
        uVar16 = (*(code *)**(undefined4 **)this)(this);
                    
        goto override_jmp_97b938f4_case_0;
      }
      (**(code **)(*(int *)this + 0x48))(this);
      uVar19 = GetGlobalPoolAllocator();
      iVar14 = TPoolAllocator__allocate(uVar19);
      iVar29 = (**(code **)(*(int *)this + 0x48))(this);
      iVar27 = 0;
      if (0 < iVar29) {
        iVar15 = 0;
        do {
          *(undefined4 *)(iVar15 + iVar14) = 0;
          if (0 < iVar29) {
            pcVar11 = pcVar26 + iVar15;
            pfVar24 = pfVar25;
            iVar4 = iVar29;
            do {
              fVar7 = *(float *)pcVar11;
              pcVar11 = pcVar11 + iVar29 * 4;
              fVar6 = *pfVar24;
              pfVar24 = pfVar24 + 1;
              *(float *)(iVar15 + iVar14) = fVar7 * fVar6 + *(float *)(iVar15 + iVar14);
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
          }
          iVar27 = iVar27 + 1;
          iVar15 = iVar15 + 4;
        } while (iVar27 < iVar29);
      }
      uVar19 = GetGlobalPoolAllocator();
      pTVar20 = (unsigned char *)TPoolAllocator__allocate(uVar19);
      (**(code **)(*piVar17 + 0x38))(&local_170,piVar17);
      *(undefined ***)pTVar20 = &PTR_getLine_a7b7cf90;
      puVar10 = &TType__vtable;
      *(int *)(pTVar20 + 4) = 0;
      goto LAB_97b946a4;
    case 0x2a:
      local_4c = -0x5847e8cc;
      (**(code **)(*(int *)this + 0x4c))(this);
      uVar19 = GetGlobalPoolAllocator();
      iVar14 = TPoolAllocator__allocate(uVar19);
      for (iVar29 = 0; iVar27 = (**(code **)(*(int *)this + 0x4c))(this), iVar29 < iVar27;
          iVar29 = iVar29 + 1) {
        (**(code **)(*(int *)this + 0x38))(&local_170,this);
        local_170 = (undefined **)(local_4c + -0x473c);
        if ((local_14c >> 0x13 & 0x3f) != 3) {
          uVar16 = (*(code *)**(undefined4 **)this)(this);
                    
          goto override_jmp_97b93868_case_0;
        }
        uVar21 = 0;
        if ((*(int *)(pcVar26 + iVar29 * 4) != 0) || (pfVar25[iVar29] != 0.0)) {
          uVar21 = 1;
        }
        *(undefined4 *)(iVar29 * 4 + iVar14) = uVar21;
      }
      break;
    case 0x2b:
      local_4c = -0x5847e8cc;
      (**(code **)(*(int *)this + 0x4c))(this);
      uVar19 = GetGlobalPoolAllocator();
      iVar14 = TPoolAllocator__allocate(uVar19);
      for (iVar29 = 0; iVar27 = (**(code **)(*(int *)this + 0x4c))(this), iVar29 < iVar27;
          iVar29 = iVar29 + 1) {
        (**(code **)(*(int *)this + 0x38))(&local_170,this);
        local_170 = (undefined **)(local_4c + -0x473c);
        if ((local_14c >> 0x13 & 0x3f) != 3) {
          uVar16 = (*(code *)**(undefined4 **)this)(this);
                    
          goto override_jmp_97b93868_case_0;
        }
        *(uint *)(iVar29 * 4 + iVar14) = (uint)(*(float *)(pcVar26 + iVar29 * 4) != pfVar25[iVar29])
        ;
      }
      break;
    case 0x2c:
      local_4c = -0x5847e8cc;
      (**(code **)(*(int *)this + 0x4c))(this);
      uVar19 = GetGlobalPoolAllocator();
      iVar14 = TPoolAllocator__allocate(uVar19);
      for (iVar29 = 0; iVar27 = (**(code **)(*(int *)this + 0x4c))(this), iVar29 < iVar27;
          iVar29 = iVar29 + 1) {
        (**(code **)(*(int *)this + 0x38))(&local_170,this);
        local_170 = (undefined **)(local_4c + -0x473c);
        if ((local_14c >> 0x13 & 0x3f) != 3) {
          uVar16 = (*(code *)**(undefined4 **)this)(this);
                    
          goto override_jmp_97b93868_case_0;
        }
        uVar21 = 0;
        if ((*(int *)(pcVar26 + iVar29 * 4) != 0) && (pfVar25[iVar29] != 0.0)) {
          uVar21 = 1;
        }
        *(undefined4 *)(iVar29 * 4 + iVar14) = uVar21;
      }
      break;
    case 0x56:
      bVar30 = false;
      (**(code **)(*(int *)this + 0x38))(&local_170,this);
      if (((local_14c >> 0x13 & 0x3f) != 1) ||
         (iVar14 = (**(code **)(*piVar17 + 0x40))(piVar17), iVar14 != 1)) {
        bVar30 = true;
      }
      local_4c = -0x5847e8cc;
      local_170 = &PTR__TType_a7b7cff8;
      if (bVar30) {
        uVar16 = (*(code *)**(undefined4 **)this)(this);
                    
        TInfoSinkBase__append(param_4);
        bVar30 = (uVar16 & 0xffff) == 0;
        bVar31 = bVar30 << 1;
        if (bVar30) {
          _sprintf(acStack_d0,"%d:? ",(int)uVar16 >> 0x10);
        }
        else {
          _sprintf(acStack_d0,"%d:%d",(int)uVar16 >> 0x10);
        }
        std__string__string((unsigned char *)local_140,acStack_d0,aaStack_130);
        *(undefined *)((int)local_140[0] + (int)local_140[0][-3]) = *PTR__S_terminal_a7b7c0b8;
        TInfoSinkBase__append(param_4);
        ppuVar28 = local_140;
LAB_97b932f0:
        ppuVar5 = ppuVar28 + -1;
        paVar22 = (unsigned char *)(ppuVar28 + -3);
        do {
          puVar10 = *ppuVar5;
          if (in_RESERVE != '\0') {
            puVar2 = (undefined *)storeWordConditionalIndexed(puVar10 + -1,0,ppuVar5);
            *ppuVar5 = puVar2;
            bVar31 = 2;
          }
        } while (!(bool)(bVar31 >> 1 & 1));
        bVar30 = 0 < (int)puVar10;
LAB_97b93fb8:
        if (!bVar30) goto LAB_97b95524;
        goto LAB_97b95528;
      }
      iVar29 = (**(code **)(*(int *)this + 0x48))(this);
      uVar19 = GetGlobalPoolAllocator();
      iVar14 = TPoolAllocator__allocate(uVar19);
      iVar27 = 0;
      if (0 < iVar29) {
        do {
          if (0 < iVar29) {
            iVar23 = 0;
            iVar15 = iVar27 * 4;
            iVar4 = iVar29;
            do {
              *(undefined4 *)(iVar15 + iVar14) = 0;
              if (0 < iVar29) {
                pfVar24 = pfVar25 + iVar23;
                pcVar11 = pcVar26 + iVar27 * 4;
                iVar32 = iVar29;
                do {
                  fVar7 = *(float *)pcVar11;
                  pcVar11 = pcVar11 + iVar29 * 4;
                  fVar6 = *pfVar24;
                  pfVar24 = pfVar24 + 1;
                  *(float *)(iVar14 + iVar15) = fVar7 * fVar6 + *(float *)(iVar14 + iVar15);
                  iVar32 = iVar32 + -1;
                } while (iVar32 != 0);
              }
              iVar4 = iVar4 + -1;
              iVar23 = iVar23 + iVar29;
              iVar15 = iVar15 + iVar29 * 4;
            } while (iVar4 != 0);
          }
          iVar27 = iVar27 + 1;
        } while (iVar27 < iVar29);
      }
    }
    uVar19 = GetGlobalPoolAllocator();
    pTVar20 = (unsigned char *)TPoolAllocator__allocate(uVar19);
    (**(code **)(*(int *)this + 0x38))(&local_170,this);
    *(int *)(pTVar20 + 4) = 0;
    *(undefined ***)pTVar20 = &PTR_getLine_a7b7cf90;
    puVar10 = (undefined *)(local_4c + -0x4744);
LAB_97b946a4:
    local_170 = (undefined **)(puVar10 + 8);
    *(int *)(pTVar20 + 0xc) = local_16c;
    *(int *)(pTVar20 + 0x10) = local_168;
    *(int *)(pTVar20 + 0x14) = local_164;
    *(int *)(pTVar20 + 0x18) = local_160;
    *(int *)(pTVar20 + 0x1c) = local_15c;
    *(int *)(pTVar20 + 0x20) = local_158;
    *(undefined ***)(pTVar20 + 8) = local_170;
    *(int *)(pTVar20 + 0x24) = local_154;
    *(int *)(pTVar20 + 0x28) = local_150;
    uVar8 = *(uint *)(pTVar20 + 0x2c);
    uVar12 = local_14c & 0xfe000000;
    *(uint *)(pTVar20 + 0x2c) = uVar12 | uVar8 & 0x1ffffff;
    uVar9 = (local_14c >> 0x13 & 0x3f) << 0x13;
    *(uint *)(pTVar20 + 0x2c) = uVar9 | uVar12 | uVar8 & 0x7ffff;
    uVar16 = local_14c & 0x7f800;
    *(uint *)(pTVar20 + 0x2c) = uVar16 | uVar9 | uVar12 | uVar8 & 0x7ff;
    uVar3 = (local_14c >> 10 & 1) << 10;
    *(uint *)(pTVar20 + 0x2c) = uVar3 | uVar16 | uVar9 | uVar12 | uVar8 & 0x3ff;
    puVar10 = PTR_vtable_a7b7c0c8;
    *(uint *)(pTVar20 + 0x2c) =
         (local_14c >> 9 & 1) << 9 | uVar3 | uVar16 | uVar9 | uVar12 | uVar8 & 0x1ff;
    *(int *)(pTVar20 + 0x30) = iVar14;
    *(undefined **)pTVar20 = puVar10 + 8;
LAB_97b94758:
    iVar14 = *(int *)pTVar20;
    uVar21 = (*(code *)**(undefined4 **)this)(this);
    (**(code **)(iVar14 + 4))(pTVar20,uVar21);
    return pTVar20;
  }
LAB_97b9478c:
  bVar30 = false;
  iVar14 = (**(code **)(*(int *)this + 0x4c))(this);
  if (iVar14 != 1) {
    return this;
  }
  (**(code **)(*(int *)this + 0x38))(&local_170,this);
  if (((local_14c >> 0x13 & 0x3f) != 0xe) &&
     (iVar14 = (**(code **)(*(int *)param_3 + 0x4c))(param_3), iVar14 == 1)) {
    (**(code **)(*(int *)param_3 + 0x38))(local_140,param_3);
    bVar30 = (local_11c >> 0x13 & 0x3f) != 0xe;
    local_140[0] = &PTR__TType_a7b7cff8;
  }
  local_170 = &PTR__TType_a7b7cff8;
  if (!bVar30) {
    return this;
  }
  uVar19 = GetGlobalPoolAllocator();
  pfVar25 = (float *)TPoolAllocator__allocate(uVar19);
  local_4c = -0x5847e8cc;
  (**(code **)(*(int *)this + 0x38))((unsigned char *)&local_110,this);
  local_110 = &PTR__TType_a7b7cff8;
  uVar16 = local_ec >> 0x13 & 0x3f;
  if (uVar16 != 2) {
    if (2 < uVar16) {
      if (uVar16 != 3) goto LAB_97b95400;
      iVar14 = (**(code **)(*(int *)param_3 + 0x18))(param_3);
      uVar12 = **(uint **)(iVar14 + 0x30);
      uVar16 = **(uint **)(this + 0x30);
      if (param_2 == 0x2b) {
        bVar30 = uVar16 == uVar12;
LAB_97b9529c:
        *pfVar25 = (float)(1 - bVar30);
        uVar19 = GetGlobalPoolAllocator();
        pTVar20 = (unsigned char *)TPoolAllocator__allocate(uVar19);
        local_ec = local_ec & 0x1801ff | 0x4180800;
        local_110 = (undefined **)(local_4c + -0x473c);
        local_10c = 0;
        local_104 = 0;
        local_100 = 0;
        local_fc = 0;
        local_f8 = 0;
        local_f4 = 0;
        local_f0 = 0;
        local_108 = 0;
        *(int *)(pTVar20 + 4) = 0;
        *(undefined ***)pTVar20 = &PTR_getLine_a7b7cf90;
        *(int *)(pTVar20 + 0xc) = 0;
        *(int *)(pTVar20 + 0x10) = 0;
        *(int *)(pTVar20 + 0x14) = 0;
        *(int *)(pTVar20 + 0x18) = 0;
        *(int *)(pTVar20 + 0x1c) = 0;
        *(int *)(pTVar20 + 0x20) = 0;
        *(undefined ***)(pTVar20 + 8) = local_110;
        *(int *)(pTVar20 + 0x24) = 0;
        *(int *)(pTVar20 + 0x28) = 0;
        uVar12 = *(uint *)(pTVar20 + 0x2c);
        *(uint *)(pTVar20 + 0x2c) = uVar12 & 0x1ffffff | 0x4000000;
        uVar16 = (local_ec >> 0x13 & 0x3f) << 0x13;
        *(uint *)(pTVar20 + 0x2c) = uVar16 | uVar12 & 0x7ffff | 0x4000000;
        *(uint *)(pTVar20 + 0x2c) = uVar16 | uVar12 & 0x7ff | 0x4000000 | 0x800;
        *(uint *)(pTVar20 + 0x2c) = uVar16 | uVar12 & 0x3ff | 0x4000000 | 0x800;
        puVar10 = PTR_vtable_a7b7c0c8;
        *(uint *)(pTVar20 + 0x2c) = uVar16 | uVar12 & 0x1ff | 0x4000000 | 0x800;
        *(float **)(pTVar20 + 0x30) = pfVar25;
        *(undefined **)pTVar20 = puVar10 + 8;
        puVar13 = *(undefined4 **)param_3;
        this = param_3;
        goto LAB_97b953d4;
      }
      if (param_2 < 0x2c) {
        if (param_2 == 0x2a) {
          uVar16 = uVar16 | uVar12;
LAB_97b95254:
          bVar30 = uVar16 == 0;
          goto LAB_97b9529c;
        }
      }
      else {
        uVar16 = uVar16 & uVar12;
        if (param_2 == 0x2c) goto LAB_97b95254;
      }
      uVar16 = *(uint *)(this + 4);
                    
override_jmp_97b95280_case_0:
      TInfoSinkBase__append(param_4);
      bVar30 = (uVar16 & 0xffff) == 0;
      bVar31 = bVar30 << 1;
      if (bVar30) {
        _sprintf((char *)&local_100,"%d:? ",(int)uVar16 >> 0x10);
      }
      else {
        _sprintf((char *)&local_100,"%d:%d",(int)uVar16 >> 0x10);
      }
      std__string__string((unsigned char *)&local_110,(char *)&local_100,aaStack_c0);
      *(undefined *)((int)local_110 + (int)local_110[-3]) = *PTR__S_terminal_a7b7c0b8;
      TInfoSinkBase__append(param_4);
      ppuVar28 = local_110 + -1;
      paVar22 = (unsigned char *)(local_110 + -3);
      do {
        puVar10 = *ppuVar28;
        if (in_RESERVE != '\0') {
          puVar2 = (undefined *)storeWordConditionalIndexed(puVar10 + -1,0,ppuVar28);
          *ppuVar28 = puVar2;
          bVar31 = 2;
        }
      } while (!(bool)(bVar31 >> 1 & 1));
      if ((int)puVar10 < 1) {
LAB_97b95524:
        std__string___Rep___M_destroy(paVar22);
      }
LAB_97b95528:
      TInfoSinkBase__append(param_4);
      goto LAB_97b95ba0;
    }
    if (uVar16 != 1) {
LAB_97b95400:
      uVar16 = (*(code *)**(undefined4 **)this)(this);
                    
      goto override_jmp_97b95280_case_0;
    }
    iVar14 = (**(code **)(*(int *)param_3 + 0x18))(param_3);
    dVar34 = (double)**(float **)(iVar14 + 0x30);
    dVar33 = (double)**(float **)(this + 0x30);
    switch(param_2) {
    case 0x13:
      fVar7 = (float)(dVar33 + dVar34);
      goto LAB_97b94ef8;
    case 0x14:
      fVar7 = (float)(dVar33 - dVar34);
      goto LAB_97b94ef8;
    case 0x15:
      fVar7 = (float)(dVar33 * dVar34);
      goto LAB_97b94ef8;
    case 0x16:
      if (dVar34 == DOUBLE_97c30a48) {
        uVar16 = (*(code *)**(undefined4 **)this)(this);
                    
        TInfoSinkBase__append(param_4);
        bVar30 = (uVar16 & 0xffff) == 0;
        bVar31 = bVar30 << 1;
        if (bVar30) {
          _sprintf((char *)&local_100,"%d:? ",(int)uVar16 >> 0x10);
        }
        else {
          _sprintf((char *)&local_100,"%d:%d",(int)uVar16 >> 0x10);
        }
        std__string__string((unsigned char *)&local_110,(char *)&local_100,aaStack_c0);
        *(undefined *)((int)local_110 + (int)local_110[-3]) = *PTR__S_terminal_a7b7c0b8;
        TInfoSinkBase__append(param_4);
        ppuVar28 = local_110 + -1;
        do {
          puVar10 = *ppuVar28;
          if (in_RESERVE != '\0') {
            puVar2 = (undefined *)storeWordConditionalIndexed(puVar10 + -1,0,ppuVar28);
            *ppuVar28 = puVar2;
            bVar31 = 2;
          }
        } while (!(bool)(bVar31 >> 1 & 1));
        if ((int)puVar10 < 1) {
          std__string___Rep___M_destroy((unsigned char *)(local_110 + -3));
        }
        TInfoSinkBase__append(param_4);
        TInfoSinkBase__append(param_4);
        TInfoSinkBase__append(param_4);
        fVar7 = FLOAT_97c3acb4;
      }
      else {
        fVar7 = (float)(dVar33 / dVar34);
      }
LAB_97b94ef8:
      *pfVar25 = fVar7;
      goto LAB_97b95098;
    default:
      goto switchD_97b94d20_caseD_17;
    case 0x1d:
      fVar7 = (float)(uint)(dVar33 == dVar34);
      break;
    case 0x1e:
      fVar7 = (float)(uint)(dVar33 != dVar34);
      break;
    case 0x21:
      fVar7 = (float)(uint)(dVar33 < dVar34);
      break;
    case 0x22:
      fVar7 = (float)(uint)(dVar34 < dVar33);
      break;
    case 0x23:
      bVar30 = dVar33 <= dVar34;
      goto LAB_97b94f58;
    case 0x24:
      bVar30 = dVar34 <= dVar33;
LAB_97b94f58:
      fVar7 = (float)(uint)bVar30;
    }
    *pfVar25 = fVar7;
    uVar19 = GetGlobalPoolAllocator();
    pTVar20 = (unsigned char *)TPoolAllocator__allocate(uVar19);
    local_ec = local_ec & 0x1801ff | 0x4180800;
    local_110 = (undefined **)(local_4c + -0x473c);
    local_10c = 0;
    local_104 = 0;
    local_100 = 0;
    local_fc = 0;
    local_f8 = 0;
    local_f4 = 0;
    local_f0 = 0;
    local_108 = 0;
    *(int *)(pTVar20 + 4) = 0;
    *(undefined ***)pTVar20 = &PTR_getLine_a7b7cf90;
    *(int *)(pTVar20 + 0xc) = 0;
    *(int *)(pTVar20 + 0x10) = 0;
    *(int *)(pTVar20 + 0x14) = 0;
    *(int *)(pTVar20 + 0x18) = 0;
    *(int *)(pTVar20 + 0x1c) = 0;
    *(int *)(pTVar20 + 0x20) = 0;
    *(int *)(pTVar20 + 0x24) = 0;
    *(undefined ***)(pTVar20 + 8) = local_110;
    *(int *)(pTVar20 + 0x28) = 0;
    uVar12 = *(uint *)(pTVar20 + 0x2c);
    *(uint *)(pTVar20 + 0x2c) = uVar12 & 0x1ffffff | 0x4000000;
    uVar16 = (local_ec >> 0x13 & 0x3f) << 0x13;
    *(uint *)(pTVar20 + 0x2c) = uVar16 | uVar12 & 0x7ffff | 0x4000000;
    *(uint *)(pTVar20 + 0x2c) = uVar16 | uVar12 & 0x7ff | 0x4000000 | 0x800;
    *(uint *)(pTVar20 + 0x2c) = uVar16 | uVar12 & 0x3ff | 0x4000000 | 0x800;
    puVar10 = PTR_vtable_a7b7c0c8;
    *(uint *)(pTVar20 + 0x2c) = uVar16 | uVar12 & 0x1ff | 0x4000000 | 0x800;
    *(float **)(pTVar20 + 0x30) = pfVar25;
    *(undefined **)pTVar20 = puVar10 + 8;
    if (pTVar20 != (unsigned char *)0x0) goto LAB_97b951c0;
LAB_97b95098:
    uVar19 = GetGlobalPoolAllocator();
    pTVar20 = (unsigned char *)TPoolAllocator__allocate(uVar19);
    uVar16 = local_ec & 0x7ff | 0x4080000;
    goto LAB_97b950c8;
  }
  iVar14 = (**(code **)(*(int *)param_3 + 0x18))(param_3);
  uVar12 = **(uint **)(iVar14 + 0x30);
  uVar16 = **(uint **)(this + 0x30);
  switch(param_2) {
  case 0x13:
    fVar7 = (float)(uVar16 + uVar12);
    break;
  case 0x14:
    fVar7 = (float)(uVar16 - uVar12);
    break;
  case 0x15:
    fVar7 = (float)(uVar16 * uVar12);
    break;
  case 0x16:
    if (uVar12 == 0) {
      uVar16 = (*(code *)**(undefined4 **)this)(this);
                    
      TInfoSinkBase__append(param_4);
      bVar30 = (uVar16 & 0xffff) == 0;
      bVar31 = bVar30 << 1;
      if (bVar30) {
        _sprintf(acStack_90,"%d:? ",(int)uVar16 >> 0x10);
      }
      else {
        _sprintf(acStack_90,"%d:%d",(int)uVar16 >> 0x10);
      }
      std__string__string((unsigned char *)&local_110,acStack_90,(unsigned char *)&local_100);
      *(undefined *)((int)local_110 + (int)local_110[-3]) = *PTR__S_terminal_a7b7c0b8;
      TInfoSinkBase__append(param_4);
      ppuVar28 = local_110 + -1;
      do {
        puVar10 = *ppuVar28;
        if (in_RESERVE != '\0') {
          puVar2 = (undefined *)storeWordConditionalIndexed(puVar10 + -1,0,ppuVar28);
          *ppuVar28 = puVar2;
          bVar31 = 2;
        }
      } while (!(bool)(bVar31 >> 1 & 1));
      if ((int)puVar10 < 1) {
        std__string___Rep___M_destroy((unsigned char *)(local_110 + -3));
      }
      TInfoSinkBase__append(param_4);
      TInfoSinkBase__append(param_4);
      TInfoSinkBase__append(param_4);
      fVar7 = NAN;
    }
    else {
      fVar7 = (float)((int)uVar16 / (int)uVar12);
    }
    break;
  case 0x17:
    fVar7 = (float)(uVar16 - ((int)uVar16 / (int)uVar12) * uVar12);
    break;
  case 0x18:
    fVar7 = (float)((int)uVar16 >> (uVar12 & 0x3f));
    break;
  case 0x19:
    fVar7 = (float)(uVar16 << (uVar12 & 0x3f));
    break;
  case 0x1a:
    fVar7 = (float)(uVar16 & uVar12);
    break;
  case 0x1b:
    fVar7 = (float)(uVar16 | uVar12);
    break;
  case 0x1c:
    fVar7 = (float)(uVar16 ^ uVar12);
    break;
  case 0x1d:
    fVar7 = (float)(uint)(uVar16 == uVar12);
    goto LAB_97b94b6c;
  case 0x1e:
    *pfVar25 = (float)(uint)(uVar16 != uVar12);
    goto LAB_97b94b70;
  default:
    goto switchD_97b94d20_caseD_17;
  case 0x21:
    fVar7 = 1.4013e-45;
    if ((int)uVar12 <= (int)uVar16) {
LAB_97b94b68:
      fVar7 = 0.0;
    }
    goto LAB_97b94b6c;
  case 0x22:
    fVar7 = 1.4013e-45;
    if ((int)uVar16 <= (int)uVar12) goto LAB_97b94b68;
    goto LAB_97b94b6c;
  case 0x23:
    fVar7 = 1.4013e-45;
    if ((int)uVar12 < (int)uVar16) goto LAB_97b94b68;
    goto LAB_97b94b6c;
  case 0x24:
    fVar7 = 1.4013e-45;
    if ((int)uVar16 < (int)uVar12) goto LAB_97b94b68;
LAB_97b94b6c:
    *pfVar25 = fVar7;
LAB_97b94b70:
    uVar19 = GetGlobalPoolAllocator();
    pTVar20 = (unsigned char *)TPoolAllocator__allocate(uVar19);
    local_ec = local_ec & 0x1801ff | 0x4180800;
    local_110 = (undefined **)(local_4c + -0x473c);
    local_10c = 0;
    local_104 = 0;
    local_100 = 0;
    local_fc = 0;
    local_f8 = 0;
    local_f4 = 0;
    local_f0 = 0;
    local_108 = 0;
    *(int *)(pTVar20 + 4) = 0;
    *(undefined ***)pTVar20 = &PTR_getLine_a7b7cf90;
    *(int *)(pTVar20 + 0xc) = 0;
    *(int *)(pTVar20 + 0x10) = 0;
    *(int *)(pTVar20 + 0x14) = 0;
    *(int *)(pTVar20 + 0x18) = 0;
    *(int *)(pTVar20 + 0x1c) = 0;
    *(int *)(pTVar20 + 0x20) = 0;
    *(int *)(pTVar20 + 0x24) = 0;
    *(undefined ***)(pTVar20 + 8) = local_110;
    *(int *)(pTVar20 + 0x28) = 0;
    uVar12 = *(uint *)(pTVar20 + 0x2c);
    *(uint *)(pTVar20 + 0x2c) = uVar12 & 0x1ffffff | 0x4000000;
    uVar16 = (local_ec >> 0x13 & 0x3f) << 0x13;
    *(uint *)(pTVar20 + 0x2c) = uVar16 | uVar12 & 0x7ffff | 0x4000000;
    *(uint *)(pTVar20 + 0x2c) = uVar16 | uVar12 & 0x7ff | 0x4000000 | 0x800;
    *(uint *)(pTVar20 + 0x2c) = uVar16 | uVar12 & 0x3ff | 0x4000000 | 0x800;
    puVar10 = PTR_vtable_a7b7c0c8;
    *(uint *)(pTVar20 + 0x2c) = uVar16 | uVar12 & 0x1ff | 0x4000000 | 0x800;
    *(float **)(pTVar20 + 0x30) = pfVar25;
    *(undefined **)pTVar20 = puVar10 + 8;
    if (pTVar20 != (unsigned char *)0x0) goto LAB_97b951c0;
    goto LAB_97b94ca4;
  }
  *pfVar25 = fVar7;
LAB_97b94ca4:
  uVar19 = GetGlobalPoolAllocator();
  pTVar20 = (unsigned char *)TPoolAllocator__allocate(uVar19);
  uVar16 = local_ec & 0xfff | 0x4100000;
LAB_97b950c8:
  local_110 = (undefined **)(local_4c + -0x473c);
  local_ec = uVar16 & 0xfffff9ff | 0x800;
  *(int *)(pTVar20 + 4) = 0;
  *(undefined ***)pTVar20 = &PTR_getLine_a7b7cf90;
  *(int *)(pTVar20 + 0xc) = 0;
  *(int *)(pTVar20 + 0x10) = 0;
  *(int *)(pTVar20 + 0x14) = 0;
  *(int *)(pTVar20 + 0x18) = 0;
  *(int *)(pTVar20 + 0x1c) = 0;
  *(int *)(pTVar20 + 0x20) = 0;
  *(undefined ***)(pTVar20 + 8) = local_110;
  *(int *)(pTVar20 + 0x24) = 0;
  *(int *)(pTVar20 + 0x28) = 0;
  uVar9 = *(uint *)(pTVar20 + 0x2c);
  uVar12 = uVar16 & 0xfe000000;
  *(uint *)(pTVar20 + 0x2c) = uVar12 | uVar9 & 0x1ffffff;
  uVar16 = uVar16 & 0x1f80000;
  *(uint *)(pTVar20 + 0x2c) = uVar16 | uVar12 | uVar9 & 0x7ffff;
  *(uint *)(pTVar20 + 0x2c) = uVar16 | uVar12 | uVar9 & 0x7ff | 0x800;
  *(uint *)(pTVar20 + 0x2c) = uVar16 | uVar12 | uVar9 & 0x3ff | 0x800;
  puVar10 = PTR_vtable_a7b7c0c8;
  *(uint *)(pTVar20 + 0x2c) = uVar16 | uVar12 | uVar9 & 0x1ff | 0x800;
  *(float **)(pTVar20 + 0x30) = pfVar25;
  *(undefined **)pTVar20 = puVar10 + 8;
LAB_97b951c0:
  local_f0 = 0;
  iVar14 = *(int *)pTVar20;
  local_10c = local_f0;
  local_108 = local_f0;
  local_104 = local_f0;
  local_100 = local_f0;
  local_fc = local_f0;
  local_f8 = local_f0;
  local_f4 = local_f0;
  uVar21 = (*(code *)**(undefined4 **)param_3)(param_3);
  (**(code **)(iVar14 + 4))(pTVar20,uVar21);
  return pTVar20;
}

/* TIntermediate__changeAggrToTempConst @ 0x97b95c0c (484 bytes) */
int TIntermediate__changeAggrToTempConst(this, param_1, param_2, param_3)
  unsigned char * this;
  unsigned char * param_1;
  unsigned char * param_2;
  int param_3;
{
  ulong uVar1;
  unsigned char * pcVar2;
  int iVar3;
  int *piVar4;
  undefined **local_60 [15];
  
  (**(code **)(*(int *)param_1 + 0x38))(local_60);
  uVar1 = GetGlobalPoolAllocator();
  pcVar2 = (unsigned char *)TPoolAllocator__allocate(uVar1);
  local_60[0] = &PTR__TType_a7b7cff8;
  iVar3 = (**(code **)(*(int *)param_1 + 100))(param_1);
  if (*(int *)(iVar3 + 8) - *(int *)(iVar3 + 4) >> 2 == 1) {
    iVar3 = (**(code **)(*(int *)param_1 + 100))(param_1);
    piVar4 = (int *)(**(code **)(*(int *)**(undefined4 **)(iVar3 + 4) + 0x14))();
    iVar3 = (**(code **)(*piVar4 + 0x18))();
    if (iVar3 != 0) {
      (**(code **)(*(int *)param_1 + 0x38))(local_60,param_1);
      iVar3 = ((int (*)())TIntermediate__parseConstTree)(this,param_3,param_1,pcVar2,*(undefined4 *)(param_1 + 0x30),param_2,
                         local_60,1);
      goto LAB_97b95d90;
    }
  }
  (**(code **)(*(int *)param_1 + 0x38))(local_60,param_1);
  iVar3 = ((int (*)())TIntermediate__parseConstTree)(this,param_3,param_1,pcVar2,*(undefined4 *)(param_1 + 0x30),param_2,local_60,0)
  ;
LAB_97b95d90:
  local_60[0] = &PTR__TType_a7b7cff8;
  if (iVar3 != 0) {
    pcVar2 = (unsigned char *)0x0;
  }
  (**(code **)(*(int *)param_1 + 0x38))(local_60,param_1);
  iVar3 = (*(code *)**(undefined4 **)param_1)(param_1);
  TIntermediate__addConstantUnion(this,pcVar2,(unsigned char *)local_60,iVar3);
  return;
}

/* TIntermediate__copyConstUnion @ 0x97b95df0 (336 bytes) */
int TIntermediate__copyConstUnion(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  int iVar1;
  int iVar2;
  ulong uVar3;
  int iVar4;
  unsigned char * pTVar5;
  int iVar6;
  int iVar7;
  undefined **local_b0 [9];
  uint local_8c;
  undefined **local_80 [9];
  uint local_5c;
  undefined **local_50 [14];
  
  iVar7 = *(int *)(param_1 + 0x30);
  pTVar5 = (unsigned char *)0x0;
  if (iVar7 != 0) {
    (**(code **)(*(int *)param_1 + 0x38))(local_b0);
    local_b0[0] = &PTR__TType_a7b7cff8;
    if ((local_8c >> 0x13 & 0x3f) == 0xe) {
      (**(code **)(*(int *)param_1 + 0x38))(local_80,param_1);
      (**(code **)(*(int *)param_1 + 0x38))((unsigned char *)local_50,param_1);
      iVar2 = TType__setStructSize((unsigned char *)local_50);
      local_50[0] = &PTR__TType_a7b7cff8;
    }
    else {
      (**(code **)(*(int *)param_1 + 0x38))(local_80,param_1);
      if ((local_5c & 0x400) == 0) {
        iVar2 = (int)(local_5c << 0xd | local_5c >> 0x13) >> 0x18;
      }
      else {
        iVar2 = (int)(local_5c << 0xd | local_5c >> 0x13) >> 0x18;
        iVar2 = iVar2 * iVar2;
      }
    }
    local_80[0] = &PTR__TType_a7b7cff8;
    uVar3 = GetGlobalPoolAllocator();
    iVar4 = TPoolAllocator__allocate(uVar3);
    iVar6 = 0;
    if (0 < iVar2) {
      do {
        iVar1 = iVar6 * 4;
        iVar6 = iVar6 + 1;
        *(undefined4 *)(iVar4 + iVar1) = *(undefined4 *)(iVar7 + iVar1);
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    *(int *)(param_1 + 0x30) = iVar4;
    pTVar5 = param_1;
  }
  return pTVar5;
}

/* TIntermediate__promoteConstantUnion @ 0x97b95f40 (1080 bytes) */
int TIntermediate__promoteConstantUnion(this, param_2, param_3)
  unsigned char * this;
  uint param_2;
  int *param_3;
{
  bool bVar1;
  undefined *puVar2;
  int iVar3;
  undefined **ppuVar4;
  undefined *puVar5;
  ulong uVar6;
  unsigned char * pcVar7;
  uint uVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  char *pcVar12;
  char in_RESERVE;
  byte bVar13;
  double dVar14;
  undefined **local_c0 [4];
  unsigned char aaStack_b0 [20];
  uint local_9c;
  undefined4 local_90;
  uint uStack_8c;
  undefined **local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  uint local_5c;
  longlong local_40;
  
  iVar10 = param_3[0xc];
  (**(code **)(*param_3 + 0x38))(local_c0,param_3);
  if ((local_9c & 0x400) == 0) {
    iVar3 = (int)(local_9c << 0xd | local_9c >> 0x13) >> 0x18;
  }
  else {
    iVar3 = (int)(local_9c << 0xd | local_9c >> 0x13) >> 0x18;
    iVar3 = iVar3 * iVar3;
  }
  local_c0[0] = &PTR__TType_a7b7cff8;
  uVar6 = GetGlobalPoolAllocator();
  iVar11 = 0;
  pcVar7 = (unsigned char *)TPoolAllocator__allocate(uVar6);
  if (0 < iVar3) {
    do {
      if (param_2 == 2) {
        (**(code **)(*param_3 + 0x38))(local_c0,param_3);
        uVar8 = local_9c >> 0x13 & 0x3f;
        local_c0[0] = &PTR__TType_a7b7cff8;
        if (uVar8 == 2) {
LAB_97b96230:
          uVar8 = *(uint *)(iVar11 * 4 + iVar10);
        }
        else {
          if (2 < uVar8) {
            if (uVar8 != 3) goto LAB_97b96174;
            goto LAB_97b96230;
          }
          if (uVar8 != 1) {
LAB_97b96174:
            pcVar12 = *(char **)this;
            uVar8 = (**(code **)*param_3)(param_3);
                    
            goto override_jmp_97b960f0_case_0;
          }
          uVar8 = (uint)*(float *)(iVar11 * 4 + iVar10);
          local_40 = (longlong)(int)uVar8;
        }
LAB_97b9625c:
        *(uint *)(pcVar7 + iVar11 * 4) = uVar8;
      }
      else if ((int)param_2 < 3) {
        if (param_2 != 1) {
LAB_97b962b8:
          pcVar12 = *(char **)this;
          uVar8 = (**(code **)*param_3)(param_3);
                    
override_jmp_97b960f0_case_0:
          TInfoSinkBase__append(pcVar12);
          bVar1 = (uVar8 & 0xffff) == 0;
          bVar13 = bVar1 << 1;
          if (bVar1) {
            _sprintf((char *)&local_80,"%d:? ",(int)uVar8 >> 0x10);
          }
          else {
            _sprintf((char *)&local_80,"%d:%d",(int)uVar8 >> 0x10);
          }
          std__string__string((unsigned char *)local_c0,(char *)&local_80,aaStack_b0);
          *(undefined *)((int)local_c0[0] + (int)local_c0[0][-3]) = *PTR__S_terminal_a7b7c0b8;
          TInfoSinkBase__append(pcVar12);
          ppuVar4 = local_c0[0] + -1;
          do {
            puVar5 = *ppuVar4;
            if (in_RESERVE != '\0') {
              puVar2 = (undefined *)storeWordConditionalIndexed(puVar5 + -1,0,ppuVar4);
              *ppuVar4 = puVar2;
              bVar13 = 2;
            }
          } while (!(bool)(bVar13 >> 1 & 1));
          if ((int)puVar5 < 1) {
            std__string___Rep___M_destroy((unsigned char *)(local_c0[0] + -3));
          }
          TInfoSinkBase__append(pcVar12);
          TInfoSinkBase__append(pcVar12);
          TInfoSinkBase__append(pcVar12);
          return 0;
        }
        (**(code **)(*param_3 + 0x38))(local_c0,param_3);
        uVar8 = local_9c >> 0x13 & 0x3f;
        local_c0[0] = &PTR__TType_a7b7cff8;
        if (uVar8 != 2) {
          if (uVar8 < 3) {
            if (uVar8 == 1) {
              *(undefined4 *)(pcVar7 + iVar11 * 4) = *(undefined4 *)(iVar10 + iVar11 * 4);
              goto LAB_97b9641c;
            }
          }
          else if (uVar8 == 3) {
            uStack_8c = *(uint *)(iVar11 * 4 + iVar10);
            dVar14 = DOUBLE_97c30a68;
            goto LAB_97b96098;
          }
          pcVar12 = *(char **)this;
          uVar8 = (**(code **)*param_3)(param_3);
                    
          goto override_jmp_97b960f0_case_0;
        }
        uStack_8c = *(uint *)(iVar11 * 4 + iVar10) ^ 0x80000000;
        dVar14 = DOUBLE_97c30a58;
LAB_97b96098:
        local_90 = 0x43300000;
        *(float *)(pcVar7 + iVar11 * 4) = (float)((double)CONCAT44(0x43300000,uStack_8c) - dVar14);
      }
      else {
        if (param_2 != 3) goto LAB_97b962b8;
        (**(code **)(*param_3 + 0x38))(local_c0,param_3);
        uVar8 = local_9c >> 0x13 & 0x3f;
        local_c0[0] = &PTR__TType_a7b7cff8;
        if (uVar8 != 2) {
          if (uVar8 < 3) {
            if (uVar8 == 1) {
              uVar8 = (uint)((double)*(float *)(iVar11 * 4 + iVar10) != DOUBLE_97c30a48);
              goto LAB_97b9625c;
            }
          }
          else if (uVar8 == 3) goto LAB_97b96230;
          pcVar12 = *(char **)this;
          uVar8 = (**(code **)*param_3)(param_3);
                    
          goto override_jmp_97b960f0_case_0;
        }
        *(uint *)(pcVar7 + iVar11 * 4) = (uint)(*(int *)(iVar10 + iVar11 * 4) != 0);
      }
LAB_97b9641c:
      local_c0[0] = &PTR__TType_a7b7cff8;
      iVar11 = iVar11 + 1;
    } while (iVar11 < iVar3);
  }
  (**(code **)(*param_3 + 0x38))(local_c0,param_3);
  local_5c = (local_9c >> 9 & 1) << 9 |
             (local_9c >> 10 & 1) << 10 |
             local_9c & 0x7f800 |
             (param_2 & 0x3f) << 0x13 | local_9c & 0xfe000000 | local_5c & 0x1ff;
  local_60 = 0;
  local_7c = 0;
  local_78 = 0;
  local_74 = 0;
  local_70 = 0;
  local_6c = 0;
  local_68 = 0;
  local_64 = 0;
  local_80 = &PTR__TType_a7b7cff8;
  iVar10 = (**(code **)*param_3)(param_3);
  uVar9 = TIntermediate__addConstantUnion(this,pcVar7,(unsigned char *)&local_80,iVar10);
  return uVar9;
}

/* TIntermediate__removeChildNode @ 0x97b964e8 (824 bytes) */
int TIntermediate__removeChildNode(this, param_1, param_2, param_3, param_4, param_5)
  unsigned char * this;
  unsigned char * param_1;
  unsigned char * param_2;
  int *param_3;
  unsigned char * param_4;
  unsigned char * param_5;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  ulong uVar10;
  undefined4 *puVar11;
  int *piVar12;
  int *piVar13;
  undefined4 uVar14;
  int iVar15;
  undefined *puVar16;
  undefined **local_b0 [9];
  uint local_8c;
  undefined **local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  uint local_5c;
  undefined4 local_50;
  int *local_4c [3];
  
  if (param_5 != (unsigned char *)0x0) {
    *(int *)param_4 = *(int *)(param_1 + 4) + *param_3 * 4;
    iVar8 = (**(code **)(*(int *)param_5 + 100))(param_5);
    iVar15 = *(int *)(param_1 + 8);
    iVar7 = *(int *)(param_1 + 4);
    if (*(int *)(iVar8 + 8) - *(int *)(iVar8 + 4) >> 2 == 1) {
      iVar9 = ((int (*)())TIntermediate__removeMatrixConstNode)(this,param_1,param_2,param_5,*param_3);
      if (iVar9 == 0) {
        iVar9 = 0;
        puVar16 = PTR_vtable_a7b7c0c8 + 8;
        while( true ) {
          (**(code **)(*(int *)param_5 + 0x38))(local_b0,param_5);
          if ((local_8c & 0x400) == 0) {
            iVar6 = (int)(local_8c << 0xd | local_8c >> 0x13) >> 0x18;
          }
          else {
            iVar6 = (int)(local_8c << 0xd | local_8c >> 0x13) >> 0x18;
            iVar6 = iVar6 * iVar6;
          }
          local_b0[0] = &PTR__TType_a7b7cff8;
          if (iVar6 <= iVar9) break;
          uVar10 = GetGlobalPoolAllocator();
          puVar11 = (undefined4 *)TPoolAllocator__allocate(uVar10);
          iVar9 = iVar9 + 1;
          iVar6 = (**(code **)(*(int *)**(undefined4 **)(iVar8 + 4) + 0x18))();
          *puVar11 = **(undefined4 **)(iVar6 + 0x30);
          uVar10 = GetGlobalPoolAllocator();
          piVar12 = (int *)TPoolAllocator__allocate(uVar10);
          piVar13 = (int *)(**(code **)(*(int *)**(undefined4 **)(iVar8 + 4) + 0x18))();
          (**(code **)(*piVar13 + 0x38))(&local_80,piVar13);
          *piVar12 = (int)&PTR_getLine_a7b7cf90;
          piVar12[1] = 0;
          piVar12[3] = local_7c;
          piVar12[4] = local_78;
          piVar12[5] = local_74;
          piVar12[6] = local_70;
          piVar12[7] = local_6c;
          piVar12[8] = local_68;
          piVar12[2] = (int)&PTR__TType_a7b7cff8;
          piVar12[9] = local_64;
          piVar12[10] = local_60;
          uVar5 = piVar12[0xb];
          uVar2 = local_5c & 0xfe000000;
          piVar12[0xb] = uVar2 | uVar5 & 0x1ffffff;
          uVar3 = (local_5c >> 0x13 & 0x3f) << 0x13;
          piVar12[0xb] = uVar3 | uVar2 | uVar5 & 0x7ffff;
          uVar1 = local_5c & 0x7f800;
          piVar12[0xb] = uVar1 | uVar3 | uVar2 | uVar5 & 0x7ff;
          uVar4 = (local_5c >> 10 & 1) << 10;
          piVar12[0xb] = uVar4 | uVar1 | uVar3 | uVar2 | uVar5 & 0x3ff;
          piVar12[0xb] = (local_5c >> 9 & 1) << 9 | uVar4 | uVar1 | uVar3 | uVar2 | uVar5 & 0x1ff;
          piVar12[0xc] = (int)puVar11;
          *piVar12 = (int)puVar16;
          local_80 = &PTR__TType_a7b7cff8;
          iVar6 = *piVar12;
          uVar14 = (*(code *)**(undefined4 **)param_5)(param_5);
          (**(code **)(iVar6 + 4))(piVar12,uVar14);
          iVar6 = *(int *)(param_1 + 4) + *param_3 * 4;
          *(int *)param_4 = iVar6;
          local_4c[0] = piVar12;
          std__vector_TIntermNode__pool_allocator_TIntermNode_____insert
                    (&local_50,param_1,iVar6,local_4c);
        }
      }
    }
    else {
      std__vector_TIntermNode__pool_allocator_TIntermNode______M_range_insert___gnu_cxx____normal_iterator_TIntermNode___std__vector_TIntermNode__pool_allocator_TIntermNode_____
                (param_1,*(undefined4 *)param_4,*(int *)(iVar8 + 4),*(int *)(iVar8 + 8),0);
    }
    iVar7 = (*param_3 + (*(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2)) -
            (iVar15 - iVar7 >> 2);
    *param_3 = iVar7;
    *(int *)param_4 = *(int *)(param_1 + 4) + iVar7 * 4;
    std__vector_TIntermNode__pool_allocator_TIntermNode_____erase(&local_50,param_1);
    *(undefined4 *)param_4 = local_50;
    *param_3 = *param_3 + -1;
    *(int *)param_4 = *(int *)param_4 + -4;
  }
  return;
}

/* TIntermediate__removeChildNode_97b96820 @ 0x97b96820 (496 bytes) */
int TIntermediate__removeChildNode_97b96820(this, param_1, param_2, param_3)
  unsigned char * this;
  unsigned char * param_1;
  unsigned char * param_2;
  unsigned char * param_3;
{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  unsigned char * pTVar5;
  int iVar6;
  int iVar7;
  undefined1 auStack_30 [20];
  
  iVar3 = (**(code **)(*(int *)param_2 + 0x30))(param_2);
  if (iVar3 == 1) {
    iVar3 = (**(code **)(*(int *)param_3 + 100))(param_3);
    param_1 = (unsigned char *)(**(code **)(*(int *)**(undefined4 **)(iVar3 + 4) + 0x14))();
  }
  else {
    iVar3 = (**(code **)(*(int *)param_2 + 0x30))(param_2);
    piVar4 = (int *)(**(code **)(*(int *)param_1 + 0x1c))(param_1);
    pTVar5 = (unsigned char *)(**(code **)(*piVar4 + 100))();
    iVar6 = (**(code **)(*(int *)param_3 + 100))(param_3);
    if (*(int *)(iVar6 + 8) - *(int *)(iVar6 + 4) >> 2 == 1) {
      iVar3 = ((int (*)())TIntermediate__removeMatrixConstNode)(this,pTVar5,param_2,param_3,1);
      if (iVar3 == 0) {
        iVar3 = (**(code **)(*(int *)param_3 + 100))(param_3);
        puVar1 = *(undefined4 **)(pTVar5 + 8);
        if (puVar1 == *(undefined4 **)(pTVar5 + 0xc)) {
          std__vector_TIntermNode__pool_allocator_TIntermNode______M_insert_aux(pTVar5,puVar1);
        }
        else {
          iVar6 = 0;
          if (puVar1 != (undefined4 *)0x0) {
            *puVar1 = **(undefined4 **)(iVar3 + 4);
            iVar6 = *(int *)(pTVar5 + 8);
          }
          *(int *)(pTVar5 + 8) = iVar6 + 4;
        }
      }
    }
    else {
      iVar6 = 0;
      if (0 < iVar3) {
        do {
          iVar7 = (**(code **)(*(int *)param_3 + 100))(param_3);
          puVar1 = *(undefined4 **)(pTVar5 + 8);
          if (puVar1 == *(undefined4 **)(pTVar5 + 0xc)) {
            std__vector_TIntermNode__pool_allocator_TIntermNode______M_insert_aux
                      (pTVar5,puVar1,*(int *)(iVar7 + 4) + iVar6 * 4);
          }
          else {
            iVar2 = 0;
            if (puVar1 != (undefined4 *)0x0) {
              *puVar1 = *(undefined4 *)(*(int *)(iVar7 + 4) + iVar6 * 4);
              iVar2 = *(int *)(pTVar5 + 8);
            }
            *(int *)(pTVar5 + 8) = iVar2 + 4;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < iVar3);
      }
    }
    std__vector_TIntermNode__pool_allocator_TIntermNode_____erase
              (auStack_30,pTVar5,*(undefined4 *)(pTVar5 + 4));
  }
  return param_1;
}

/* TIntermediate__removeMatrixConstNode @ 0x97b96a10 (776 bytes) */
int TIntermediate__removeMatrixConstNode(this, param_1, param_2, param_3, param_4)
  unsigned char * this;
  unsigned char * param_1;
  unsigned char * param_2;
  unsigned char * param_3;
  int param_4;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  ulong uVar9;
  undefined4 *puVar10;
  int *piVar11;
  int *piVar12;
  undefined *puVar13;
  int iVar14;
  undefined **local_b0 [9];
  uint local_8c;
  undefined **local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  uint local_5c;
  undefined1 auStack_50 [4];
  int *local_4c [3];
  
  uVar7 = 0;
  if (param_3 != (unsigned char *)0x0) {
    iVar8 = (**(code **)(*(int *)param_3 + 100))(param_3);
    uVar7 = 0;
    if (*(int *)(param_3 + 0x30) - 0x72U < 3) {
      iVar14 = 0;
      puVar13 = PTR_vtable_a7b7c0c8 + 8;
      while( true ) {
        (**(code **)(*(int *)param_3 + 0x38))(local_b0,param_3);
        if ((local_8c & 0x400) == 0) {
          iVar6 = (int)(local_8c << 0xd | local_8c >> 0x13) >> 0x18;
        }
        else {
          iVar6 = (int)(local_8c << 0xd | local_8c >> 0x13) >> 0x18;
          iVar6 = iVar6 * iVar6;
        }
        local_b0[0] = &PTR__TType_a7b7cff8;
        uVar7 = 1;
        if (iVar6 <= iVar14) break;
        uVar9 = GetGlobalPoolAllocator();
        puVar10 = (undefined4 *)TPoolAllocator__allocate(uVar9);
        (**(code **)(*(int *)param_3 + 0x38))(&local_80,param_3);
        local_80 = &PTR__TType_a7b7cff8;
        iVar6 = ((int)(local_5c << 0xd | local_5c >> 0x13) >> 0x18) + 1;
        if (iVar14 == (iVar14 / iVar6) * iVar6) {
          iVar6 = (**(code **)(*(int *)**(undefined4 **)(iVar8 + 4) + 0x18))();
          *puVar10 = **(undefined4 **)(iVar6 + 0x30);
        }
        else {
          iVar6 = (**(code **)(*(int *)param_2 + 0x20))(param_2);
          if (iVar6 == 2) {
LAB_97b96b5c:
            *puVar10 = 0;
          }
          else if (iVar6 < 3) {
            if (iVar6 == 1) {
              *puVar10 = 0;
            }
          }
          else if (iVar6 == 3) goto LAB_97b96b5c;
        }
        uVar9 = GetGlobalPoolAllocator();
        piVar11 = (int *)TPoolAllocator__allocate(uVar9);
        piVar12 = (int *)(**(code **)(*(int *)**(undefined4 **)(iVar8 + 4) + 0x18))();
        (**(code **)(*piVar12 + 0x38))(&local_80,piVar12);
        *piVar11 = (int)&PTR_getLine_a7b7cf90;
        piVar11[1] = 0;
        piVar11[3] = local_7c;
        piVar11[4] = local_78;
        piVar11[5] = local_74;
        piVar11[6] = local_70;
        piVar11[7] = local_6c;
        piVar11[8] = local_68;
        piVar11[2] = (int)&PTR__TType_a7b7cff8;
        piVar11[9] = local_64;
        piVar11[10] = local_60;
        uVar5 = piVar11[0xb];
        uVar2 = local_5c & 0xfe000000;
        piVar11[0xb] = uVar2 | uVar5 & 0x1ffffff;
        uVar3 = (local_5c >> 0x13 & 0x3f) << 0x13;
        piVar11[0xb] = uVar3 | uVar2 | uVar5 & 0x7ffff;
        uVar1 = local_5c & 0x7f800;
        piVar11[0xb] = uVar1 | uVar3 | uVar2 | uVar5 & 0x7ff;
        uVar4 = (local_5c >> 10 & 1) << 10;
        piVar11[0xb] = uVar4 | uVar1 | uVar3 | uVar2 | uVar5 & 0x3ff;
        piVar11[0xb] = (local_5c >> 9 & 1) << 9 | uVar4 | uVar1 | uVar3 | uVar2 | uVar5 & 0x1ff;
        piVar11[0xc] = (int)puVar10;
        *piVar11 = (int)puVar13;
        local_80 = &PTR__TType_a7b7cff8;
        iVar6 = *piVar11;
        uVar7 = (*(code *)**(undefined4 **)param_3)(param_3);
        (**(code **)(iVar6 + 4))(piVar11,uVar7);
        iVar6 = iVar14 * 4;
        iVar14 = iVar14 + 1;
        local_4c[0] = piVar11;
        std__vector_TIntermNode__pool_allocator_TIntermNode_____insert
                  (auStack_50,param_1,*(int *)(param_1 + 4) + param_4 * 4 + iVar6,local_4c);
      }
    }
  }
  return uVar7;
}

/* TIntermAggregate__addToPragmaTable @ 0x97b96d18 (184 bytes) */
int TIntermAggregate__addToPragmaTable(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  unsigned char * this_00;
  ulong uVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = *(int *)(this + 0x68);
  if (iVar3 != 0) {
    ___eprintf("%s:%u: failed assertion `%s\'\n",
               "/SourceCache/OpenGL/OpenGL-4.7.14/GLProgrammability/glslang/MachineIndependent/Intermediate.cpp"
               ,0x865,"!pragmaTable");
  }
  this_00 = operator_new(0x10);
  uVar1 = GetGlobalPoolAllocator();
  *(ulong *)this_00 = uVar1;
  *(int *)(this_00 + 4) = iVar3;
  piVar2 = (int *)TPoolAllocator__allocate(uVar1);
  *(int *)(this_00 + 8) = iVar3;
  *(int **)(this_00 + 4) = piVar2;
  *piVar2 = iVar3;
  *(int *)(*(int *)(this_00 + 4) + 4) = iVar3;
  *(int *)(*(int *)(this_00 + 4) + 8) = *(int *)(this_00 + 4);
  *(int *)(*(int *)(this_00 + 4) + 0xc) = *(int *)(this_00 + 4);
  *(unsigned char
    **)(this + 0x68) = this_00;
  std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string_____operator=(this_00,(unsigned char *)param_1);
  return;
}

/* TType__getCompleteString @ 0x97b96dd0 (276 bytes) */
int TType__getCompleteString()
{
  unsigned char * in_r3;
  undefined4 uVar1;
  int iVar2;
  int in_r4;
  uint uVar3;
  char *pcVar4;
  char acStack_90 [112];
  undefined4 local_20 [4];
  
  uVar3 = *(uint *)(in_r4 + 0x24);
  pcVar4 = acStack_90;
  if (1 < uVar3 >> 0x19) {
    uVar1 = getQualifierString();
    iVar2 = _sprintf(pcVar4,"%s ",uVar1);
    uVar3 = *(uint *)(in_r4 + 0x24);
    pcVar4 = pcVar4 + iVar2;
  }
  if ((uVar3 & 0x200) != 0) {
    iVar2 = _sprintf(pcVar4,"array of ");
    uVar3 = *(uint *)(in_r4 + 0x24);
    pcVar4 = pcVar4 + iVar2;
  }
  if ((uVar3 & 0x400) == 0) {
    iVar2 = (int)(uVar3 << 0xd | uVar3 >> 0x13) >> 0x18;
    if (iVar2 < 2) goto LAB_97b96e98;
    iVar2 = _sprintf(pcVar4,"%d-component vector of ",iVar2);
  }
  else {
    iVar2 = (int)(uVar3 << 0xd | uVar3 >> 0x13) >> 0x18;
    iVar2 = _sprintf(pcVar4,"%dX%d matrix of ",iVar2,iVar2);
  }
  uVar3 = *(uint *)(in_r4 + 0x24);
  pcVar4 = pcVar4 + iVar2;
LAB_97b96e98:
  uVar1 = TType__getBasicString(uVar3 >> 0x13 & 0x3f);
  _sprintf(pcVar4,"%s",uVar1);
  local_20[0] = GetGlobalPoolAllocator();
  std__string__string(in_r3,acStack_90,(unsigned char *)local_20);
  return in_r3;
}

/* OutputTreeText @ 0x97b96ee4 (240 bytes) */
int OutputTreeText(param_1, param_2, param_3)
  unsigned char * param_1;
  unsigned char * param_2;
  int param_3;
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  char in_RESERVE;
  byte bVar6;
  int local_80 [4];
  char acStack_70 [64];
  unsigned char aaStack_30 [28];
  
  uVar5 = (*(code *)**(undefined4 **)param_2)(param_2);
  bVar1 = (uVar5 & 0xffff) == 0;
  bVar6 = bVar1 << 1;
  if (bVar1) {
    _sprintf(acStack_70,"%d:? ",(int)uVar5 >> 0x10);
  }
  else {
    _sprintf(acStack_70,"%d:%d",(int)uVar5 >> 0x10);
  }
  std__string__string((unsigned char *)local_80,acStack_70,aaStack_30);
  TInfoSinkBase__append((unsigned char *)(param_1 + 8));
  piVar3 = (int *)(local_80[0] + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar6 = 2;
    }
  } while (!(bool)(bVar6 >> 1 & 1));
  if (iVar4 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(local_80[0] + -0xc));
  }
  if (0 < param_3) {
    do {
      TInfoSinkBase__append((char *)(param_1 + 8));
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}

/* OutputSymbol @ 0x97b96fd4 (268 bytes) */
int OutputSymbol(param_1, param_2)
  unsigned char * param_1;
  unsigned char * param_2;
{
  undefined1 *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  char in_RESERVE;
  byte in_cr0;
  char acStack_b0 [112];
  undefined4 local_40;
  int local_3c;
  undefined4 local_30;
  
  ((int (*)())OutputTreeText)(*(unsigned char **)(param_2 + 0x30),(unsigned char *)param_1,*(int *)(param_2 + 0x20));
  ((int (*)())TType__getCompleteString)();
  iVar3 = local_3c;
  puVar1 = DAT_a7b7b9e0;
  *(undefined1 *)(local_3c + *(int *)(local_3c + -0xc)) = *DAT_a7b7b9e0;
  iVar4 = (**(code **)(*(int *)param_1 + 0x60))(param_1);
  *(undefined1 *)(*(int *)(iVar4 + 4) + *(int *)(*(int *)(iVar4 + 4) + -0xc)) = *puVar1;
  uVar6 = *(undefined4 *)(iVar4 + 4);
  uVar5 = (**(code **)(*(int *)param_1 + 0x5c))(param_1);
  _sprintf(acStack_b0,"\'%s\' (%s) id: %d\n",uVar6,iVar3,uVar5);
  piVar2 = (int *)(local_3c + -4);
  local_30 = local_40;
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      iVar4 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = iVar4;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar3 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(local_3c + -0xc));
  }
  TInfoSinkBase__append((char *)(*(int *)(param_2 + 0x30) + 8));
  return;
}

/* OutputBinary @ 0x97b970e0 (248 bytes) */
int OutputBinary(param_1, param_2, param_3)
  int param_1;
  unsigned char * param_2;
  unsigned char * param_3;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  unsigned char * pTVar4;
  unsigned char * psVar5;
  char in_RESERVE;
  byte in_cr0;
  int local_2c;
  
  pTVar4 = *(unsigned char **)(param_3 + 0x30);
  ((int (*)())OutputTreeText)(pTVar4,(unsigned char *)param_2,*(int *)(param_3 + 0x20));
  psVar5 = (unsigned char *)(pTVar4 + 8);
  TInfoSinkBase__append((char *)psVar5);
  TInfoSinkBase__append((char *)psVar5);
  ((int (*)())TType__getCompleteString)();
  TInfoSinkBase__append(psVar5);
  TInfoSinkBase__append((char *)psVar5);
  piVar2 = (int *)(local_2c + -4);
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar3 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(local_2c + -0xc));
  }
  TInfoSinkBase__append((char *)psVar5);
  return 1;
}

/* OutputUnary @ 0x97b971d8 (224 bytes) */
int OutputUnary(param_1, param_2, param_3)
  int param_1;
  unsigned char * param_2;
  unsigned char * param_3;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  unsigned char * psVar4;
  char in_RESERVE;
  byte in_cr0;
  int local_2c;
  
  psVar4 = (unsigned char *)(*(unsigned char **)(param_3 + 0x30) + 8);
  ((int (*)())OutputTreeText)(*(unsigned char **)(param_3 + 0x30),(unsigned char *)param_2,*(int *)(param_3 + 0x20));
  TInfoSinkBase__append((char *)psVar4);
  TInfoSinkBase__append((char *)psVar4);
  ((int (*)())TType__getCompleteString)();
  TInfoSinkBase__append(psVar4);
  TInfoSinkBase__append((char *)psVar4);
  piVar2 = (int *)(local_2c + -4);
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar3 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(local_2c + -0xc));
  }
  TInfoSinkBase__append((char *)psVar4);
  return 1;
}

/* OutputAggregate @ 0x97b972b8 (292 bytes) */
int OutputAggregate(param_1, param_2, param_3)
  int param_1;
  unsigned char * param_2;
  unsigned char * param_3;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  unsigned char * pTVar4;
  unsigned char * psVar5;
  char in_RESERVE;
  byte in_cr0;
  int local_2c;
  
  pTVar4 = *(unsigned char **)(param_3 + 0x30);
  if (*(int *)(param_2 + 0x30) == 0) {
                    
    TInfoSinkBase__append((char *)(pTVar4 + 8));
    TInfoSinkBase__append((char *)(pTVar4 + 8));
  }
  else {
    ((int (*)())OutputTreeText)(pTVar4,(unsigned char *)param_2,*(int *)(param_3 + 0x20));
    psVar5 = (unsigned char *)(pTVar4 + 8);
    TInfoSinkBase__append((char *)psVar5);
    if ((*(int *)(param_2 + 0x30) != 1) && (*(int *)(param_2 + 0x30) != 4)) {
      TInfoSinkBase__append((char *)psVar5);
      ((int (*)())TType__getCompleteString)();
      TInfoSinkBase__append(psVar5);
      TInfoSinkBase__append((char *)psVar5);
      piVar2 = (int *)(local_2c + -4);
      do {
        iVar3 = *piVar2;
        if (in_RESERVE != '\0') {
          iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
          *piVar2 = iVar1;
          in_cr0 = 2;
        }
      } while (!(bool)(in_cr0 >> 1 & 1));
      if (iVar3 < 1) {
        std__string___Rep___M_destroy((unsigned char *)(local_2c + -0xc));
      }
    }
  }
  TInfoSinkBase__append((char *)(pTVar4 + 8));
  return 1;
}

/* OutputSelection @ 0x97b97450 (516 bytes) */
int OutputSelection(param_1, param_2, param_3)
  int param_1;
  unsigned char * param_2;
  unsigned char * param_3;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  unsigned char * psVar4;
  char in_RESERVE;
  byte in_cr0;
  int local_2c;
  
  psVar4 = (unsigned char *)(*(unsigned char **)(param_3 + 0x30) + 8);
  ((int (*)())OutputTreeText)(*(unsigned char **)(param_3 + 0x30),(unsigned char *)param_2,*(int *)(param_3 + 0x20));
  TInfoSinkBase__append((char *)psVar4);
  TInfoSinkBase__append((char *)psVar4);
  ((int (*)())TType__getCompleteString)();
  TInfoSinkBase__append(psVar4);
  TInfoSinkBase__append((char *)psVar4);
  piVar2 = (int *)(local_2c + -4);
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar3 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(local_2c + -0xc));
  }
  iVar3 = *(int *)(param_3 + 0x20);
  *(int *)(param_3 + 0x20) = iVar3 + 1;
  ((int (*)())OutputTreeText)(*(unsigned char **)(param_3 + 0x30),(unsigned char *)param_2,iVar3 + 1);
  TInfoSinkBase__append((char *)psVar4);
  piVar2 = (int *)(**(code **)(*(int *)param_2 + 0x5c))(param_2);
  (**(code **)(*piVar2 + 8))(piVar2,param_3);
  ((int (*)())OutputTreeText)(*(unsigned char **)(param_3 + 0x30),(unsigned char *)param_2,*(int *)(param_3 + 0x20));
  iVar3 = (**(code **)(*(int *)param_2 + 0x60))(param_2);
  if (iVar3 == 0) {
    TInfoSinkBase__append((char *)psVar4);
  }
  else {
    TInfoSinkBase__append((char *)psVar4);
    piVar2 = (int *)(**(code **)(*(int *)param_2 + 0x60))(param_2);
    (**(code **)(*piVar2 + 8))(piVar2,param_3);
  }
  iVar3 = (**(code **)(*(int *)param_2 + 100))(param_2);
  if (iVar3 != 0) {
    ((int (*)())OutputTreeText)(*(unsigned char **)(param_3 + 0x30),(unsigned char *)param_2,*(int *)(param_3 + 0x20));
    TInfoSinkBase__append((char *)psVar4);
    piVar2 = (int *)(**(code **)(*(int *)param_2 + 100))(param_2);
    (**(code **)(*piVar2 + 8))(piVar2,param_3);
  }
  *(int *)(param_3 + 0x20) = *(int *)(param_3 + 0x20) + -1;
  return 0;
}

/* OutputConstantUnion @ 0x97b97654 (664 bytes) */
int OutputConstantUnion(param_1, param_2)
  unsigned char * param_1;
  unsigned char * param_2;
{
  bool bVar1;
  undefined *puVar2;
  int iVar3;
  uint uVar4;
  undefined **ppuVar5;
  undefined *puVar6;
  int iVar7;
  unsigned char * pTVar8;
  unsigned char * pTVar9;
  char in_RESERVE;
  byte bVar10;
  undefined8 uVar11;
  undefined **local_1c0 [4];
  char acStack_1b0 [20];
  uint local_19c;
  undefined **local_190 [6];
  int local_178;
  unsigned char aaStack_170 [4];
  uint local_16c;
  char acStack_160 [312];
  
  pTVar9 = *(unsigned char **)(param_2 + 0x30);
  (**(code **)(*(int *)param_1 + 0x38))(local_1c0,param_1);
  local_1c0[0] = &PTR__TType_a7b7d080;
  if ((local_19c >> 0x13 & 0x3f) == 0xe) {
    (**(code **)(*(int *)param_1 + 0x38))(local_190,param_1);
    iVar3 = local_178;
  }
  else {
    (**(code **)(*(int *)param_1 + 0x38))(local_190,param_1);
    if ((local_16c & 0x400) == 0) {
      iVar3 = (int)(local_16c << 0xd | local_16c >> 0x13) >> 0x18;
    }
    else {
      iVar3 = (int)(local_16c << 0xd | local_16c >> 0x13) >> 0x18;
      iVar3 = iVar3 * iVar3;
    }
  }
  local_190[0] = &PTR__TType_a7b7d080;
  iVar7 = 0;
  if (0 < iVar3) {
    do {
      ((int (*)())OutputTreeText)(pTVar9,(unsigned char *)param_1,*(int *)(param_2 + 0x20));
      uVar11 = (**(code **)(*(int *)param_1 + 0x38))(local_1c0,param_1);
      uVar4 = local_19c >> 0x13 & 0x3f;
      local_1c0[0] = &PTR__TType_a7b7d080;
      if (uVar4 == 2) {
        _sprintf((char *)local_1c0,"%d (%s)",*(undefined4 *)(*(int *)(param_1 + 0x30) + iVar7 * 4),
                 "const int");
LAB_97b977f0:
        TInfoSinkBase__append((char *)(pTVar9 + 8));
LAB_97b977f8:
        pTVar8 = pTVar9 + 8;
      }
      else {
        if (uVar4 < 3) {
          if (uVar4 == 1) {
            ((char * (*)())_glp_dtostr)((double)*(float *)(*(int *)(param_1 + 0x30) + iVar7 * 4),DOUBLE_97c30a70,
                        (int)((ulonglong)uVar11 >> 0x20),(int)uVar11,acStack_160,300);
            _sprintf(acStack_160,"%s (%s)",acStack_160,"const float");
            TInfoSinkBase__append((char *)(pTVar9 + 8));
            goto LAB_97b977f8;
          }
        }
        else if (uVar4 == 3) {
          pTVar8 = pTVar9 + 8;
          TInfoSinkBase__append((char *)pTVar8);
          TInfoSinkBase__append((char *)pTVar8);
          TInfoSinkBase__append((char *)pTVar8);
          goto LAB_97b977f0;
        }
        uVar4 = (*(code *)**(undefined4 **)param_1)(param_1);
                    
        TInfoSinkBase__append((char *)pTVar9);
        bVar1 = (uVar4 & 0xffff) == 0;
        bVar10 = bVar1 << 1;
        if (bVar1) {
          _sprintf(acStack_1b0,"%d:? ",(int)uVar4 >> 0x10);
        }
        else {
          _sprintf(acStack_1b0,"%d:%d",(int)uVar4 >> 0x10);
        }
        std__string__string((unsigned char *)local_1c0,acStack_1b0,aaStack_170);
        *(undefined *)((int)local_1c0[0] + (int)local_1c0[0][-3]) = *PTR__S_terminal_a7b7c0b8;
        TInfoSinkBase__append((char *)pTVar9);
        ppuVar5 = local_1c0[0] + -1;
        do {
          puVar6 = *ppuVar5;
          if (in_RESERVE != '\0') {
            puVar2 = (undefined *)storeWordConditionalIndexed(puVar6 + -1,0,ppuVar5);
            *ppuVar5 = puVar2;
            bVar10 = 2;
          }
        } while (!(bool)(bVar10 >> 1 & 1));
        if ((int)puVar6 < 1) {
          std__string___Rep___M_destroy((unsigned char *)(local_1c0[0] + -3));
        }
        TInfoSinkBase__append((char *)pTVar9);
        TInfoSinkBase__append((char *)pTVar9);
        pTVar8 = pTVar9;
      }
      iVar7 = iVar7 + 1;
      TInfoSinkBase__append((char *)pTVar8);
    } while (iVar7 < iVar3);
  }
  return;
}

/* OutputLoop @ 0x97b97a04 (400 bytes) */
int OutputLoop(param_1, param_2, param_3)
  int param_1;
  unsigned char * param_2;
  unsigned char * param_3;
{
  int iVar1;
  unsigned char * pTVar2;
  
  pTVar2 = *(unsigned char **)(param_3 + 0x30) + 8;
  ((int (*)())OutputTreeText)(*(unsigned char **)(param_3 + 0x30),(unsigned char *)param_2,*(int *)(param_3 + 0x20));
  TInfoSinkBase__append((char *)pTVar2);
  if (*(int *)(param_2 + 0x14) == 0) {
    TInfoSinkBase__append((char *)pTVar2);
  }
  TInfoSinkBase__append((char *)pTVar2);
  iVar1 = *(int *)(param_3 + 0x20);
  *(int *)(param_3 + 0x20) = iVar1 + 1;
  ((int (*)())OutputTreeText)(*(unsigned char **)(param_3 + 0x30),(unsigned char *)param_2,iVar1 + 1);
  if (*(int *)(param_2 + 0xc) == 0) {
    TInfoSinkBase__append((char *)pTVar2);
  }
  else {
    TInfoSinkBase__append((char *)pTVar2);
    (**(code **)(**(int **)(param_2 + 0xc) + 8))(*(int **)(param_2 + 0xc),param_3);
  }
  ((int (*)())OutputTreeText)(*(unsigned char **)(param_3 + 0x30),(unsigned char *)param_2,*(int *)(param_3 + 0x20));
  if (*(int *)(param_2 + 8) == 0) {
    TInfoSinkBase__append((char *)pTVar2);
  }
  else {
    TInfoSinkBase__append((char *)pTVar2);
    (**(code **)(**(int **)(param_2 + 8) + 8))(*(int **)(param_2 + 8),param_3);
  }
  if (*(int *)(param_2 + 0x10) != 0) {
    ((int (*)())OutputTreeText)(*(unsigned char **)(param_3 + 0x30),(unsigned char *)param_2,*(int *)(param_3 + 0x20));
    TInfoSinkBase__append((char *)pTVar2);
    (**(code **)(**(int **)(param_2 + 0x10) + 8))(*(int **)(param_2 + 0x10),param_3);
  }
  *(int *)(param_3 + 0x20) = *(int *)(param_3 + 0x20) + -1;
  return 0;
}

/* OutputBranch @ 0x97b97b94 (200 bytes) */
int OutputBranch(param_1, param_2, param_3)
  int param_1;
  unsigned char * param_2;
  unsigned char * param_3;
{
  unsigned char * pTVar1;
  
  pTVar1 = *(unsigned char **)(param_3 + 0x30) + 8;
  ((int (*)())OutputTreeText)(*(unsigned char **)(param_3 + 0x30),(unsigned char *)param_2,*(int *)(param_3 + 0x20));
  TInfoSinkBase__append((char *)pTVar1);
  if (*(int *)(param_2 + 0xc) == 0) {
    TInfoSinkBase__append((char *)pTVar1);
  }
  else {
    TInfoSinkBase__append((char *)pTVar1);
    *(int *)(param_3 + 0x20) = *(int *)(param_3 + 0x20) + 1;
    (**(code **)(**(int **)(param_2 + 0xc) + 8))(*(int **)(param_2 + 0xc),param_3);
    *(int *)(param_3 + 0x20) = *(int *)(param_3 + 0x20) + -1;
  }
  return 0;
}

/* TIntermediate__outputTree @ 0x97b97c5c (228 bytes) */
int TIntermediate__outputTree(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
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
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  
  if (param_1 != (unsigned char *)0x0) {
    local_20 = *(int *)this;
    local_3c = DAT_a7b7b9dc;
    local_48 = DAT_a7b7b9d8;
    local_4c = DAT_a7b7b9d4;
    local_40 = DAT_a7b7b9d0;
    local_50 = DAT_a7b7b9cc;
    local_44 = DAT_a7b7b9c8;
    local_38 = DAT_a7b7b9c4;
    local_24 = 0;
    local_34 = DAT_a7b7b9c0;
    local_30 = 0;
    local_2c = 1;
    local_28 = 0;
    TInfoSinkBase__append((char *)(local_20 + 8));
    local_28 = 1;
    local_2c = 1;
    (**(code **)(*(int *)param_1 + 8))(param_1,&local_50);
  }
  return;
}

/* TIntermSymbol__traverse @ 0x97b97d40 (20 bytes) */
int TIntermSymbol__traverse(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  if (*(code **)param_1 == (code *)0x0) {
    return;
  }
                    
                    
  (**(code **)param_1)();
  return;
}

/* TIntermConstantUnion__traverse @ 0x97b97d54 (20 bytes) */
int TIntermConstantUnion__traverse(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  if (*(code **)(param_1 + 4) == (code *)0x0) {
    return;
  }
                    
                    
  (**(code **)(param_1 + 4))();
  return;
}

/* TIntermBinary__traverse @ 0x97b97d68 (324 bytes) */
int TIntermBinary__traverse(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
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
  unsigned char * this;
  unsigned char * param_1;
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
  unsigned char * this;
  unsigned char * param_1;
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
  unsigned char * this;
  unsigned char * param_1;
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
  unsigned char * this;
  unsigned char * param_1;
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
  unsigned char * this;
  unsigned char * param_1;
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
  unsigned char * param_1;
  unsigned char * param_2;
{
  bool bVar1;
  undefined *puVar2;
  int *piVar3;
  undefined **ppuVar4;
  undefined *puVar5;
  ulong uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  char *pcVar15;
  int iVar16;
  int iVar17;
  char in_RESERVE;
  byte in_cr0;
  byte bVar18;
  double dVar19;
  undefined **local_1b0;
  int local_1ac;
  unsigned char aaStack_1a0 [20];
  uint local_18c;
  char acStack_180 [32];
  unsigned char aaStack_160 [128];
  int aiStack_e0 [4];
  char acStack_d0 [32];
  undefined **local_b0;
  char acStack_a0 [16];
  unsigned char aaStack_90 [48];
  int local_60 [2];
  longlong local_58;
  undefined4 local_50;
  uint uStack_4c;
  
  (**(code **)(*(int *)param_1 + 0x38))(&local_1b0,param_1);
  uVar9 = *(uint *)(param_2 + 0x60);
  local_1b0 = &PTR__TType_a7b7d488;
  iVar12 = *(int *)(param_2 + 0x34);
  if ((uVar9 >> 0x13 & 0x3f) == 0xe) {
    iVar13 = *(int *)(param_2 + 0x54);
  }
  else {
    bVar1 = (uVar9 & 0x400) == 0;
    in_cr0 = bVar1 << 1;
    if (bVar1) {
      iVar13 = (int)(uVar9 << 0xd | uVar9 >> 0x13) >> 0x18;
    }
    else {
      iVar13 = (int)(uVar9 << 0xd | uVar9 >> 0x13) >> 0x18;
      iVar13 = iVar13 * iVar13;
    }
  }
  if (*(int *)(param_2 + 0x30) < iVar13) {
    if (local_18c >> 0x19 == 2) {
      piVar3 = *(int **)(param_2 + 0x70);
      (**(code **)(*(int *)param_1 + 0x60))(param_1);
      iVar10 = *piVar3;
      iVar17 = (piVar3[1] - iVar10 >> 2) + -1;
      while( true ) {
        iVar16 = *(int *)(iVar10 + iVar17 * 4);
        iVar10 = 0;
        std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______find((unsigned char *)local_60);
        if (local_60[0] != *(int *)(iVar16 + 4)) {
          iVar10 = *(int *)(local_60[0] + 0x18);
        }
        iVar17 = iVar17 + -1;
        if ((iVar10 != 0) || (iVar17 < 0)) break;
        iVar10 = *piVar3;
      }
      iVar17 = *(int *)(iVar10 + 0x38);
      if (iVar17 == 0) {
        uVar6 = GetGlobalPoolAllocator();
        iVar17 = TPoolAllocator__allocate(uVar6);
        *(int *)(iVar10 + 0x38) = iVar17;
      }
      if (iVar17 != 0) {
        iVar11 = iVar10 + 0xc;
        iVar16 = (**(code **)(*(int *)(iVar10 + 0xc) + 0x20))(iVar11);
        if (iVar16 == 0xe) {
          iVar16 = *(int *)(iVar10 + 0x24);
        }
        else {
          iVar16 = (**(code **)(*(int *)(iVar10 + 0xc) + 0x30))(iVar11);
        }
        iVar14 = 0;
        if (iVar16 < 1) {
          return;
        }
        do {
          if (iVar13 <= *(int *)(param_2 + 0x30)) {
            return;
          }
          uVar7 = (**(code **)(*(int *)(iVar10 + 0xc) + 0x20))(iVar11);
          uVar9 = *(uint *)(param_2 + 0x60) >> 0x13 & 0x3f;
          if ((uVar7 == uVar9) || (uVar9 == 0xe)) {
LAB_97b98c14:
            *(undefined4 *)(iVar12 + *(int *)(param_2 + 0x30) * 4) =
                 *(undefined4 *)(iVar14 * 4 + iVar17);
          }
          else {
            iVar8 = (**(code **)(*(int *)(iVar10 + 0xc) + 0x20))(iVar11);
            if (iVar8 == 2) {
              uVar9 = *(uint *)(param_2 + 0x60) >> 0x13 & 0x3f;
              if (uVar9 == 1) {
                uStack_4c = *(uint *)(iVar14 * 4 + iVar17) ^ 0x80000000;
                dVar19 = DOUBLE_97c30a58;
LAB_97b98bfc:
                local_50 = 0x43300000;
                *(float *)(iVar12 + *(int *)(param_2 + 0x30) * 4) =
                     (float)((double)CONCAT44(0x43300000,uStack_4c) - dVar19);
              }
              else {
                if (uVar9 != 3) {
                  pcVar15 = *(char **)(param_2 + 0x6c);
                  uVar9 = (*(code *)**(undefined4 **)param_1)(param_1);
                    
                  goto override_jmp_97b98aec_case_0;
                }
                *(uint *)(iVar12 + *(int *)(param_2 + 0x30) * 4) =
                     (uint)(*(int *)(iVar14 * 4 + iVar17) != 0);
              }
            }
            else {
              if (iVar8 < 3) {
                if (iVar8 == 1) {
                  uVar9 = *(uint *)(param_2 + 0x60) >> 0x13 & 0x3f;
                  if (uVar9 == 2) {
                    iVar8 = (int)*(float *)(iVar14 * 4 + iVar17);
                    local_58 = (longlong)iVar8;
                    *(int *)(*(int *)(param_2 + 0x30) * 4 + iVar12) = iVar8;
                  }
                  else {
                    if (uVar9 != 3) {
                      pcVar15 = *(char **)(param_2 + 0x6c);
                      uVar9 = (*(code *)**(undefined4 **)param_1)(param_1);
                    
                      goto override_jmp_97b98aec_case_0;
                    }
                    *(uint *)(*(int *)(param_2 + 0x30) * 4 + iVar12) =
                         (uint)((double)*(float *)(iVar14 * 4 + iVar17) != DOUBLE_97c30a48);
                  }
                  goto LAB_97b98dd8;
                }
              }
              else if (iVar8 == 3) {
                uVar9 = *(uint *)(param_2 + 0x60) >> 0x13 & 0x3f;
                if (uVar9 == 1) {
                  uStack_4c = *(uint *)(iVar14 * 4 + iVar17);
                  dVar19 = DOUBLE_97c30a68;
                  goto LAB_97b98bfc;
                }
                if (uVar9 != 2) {
                  pcVar15 = *(char **)(param_2 + 0x6c);
                  uVar9 = (*(code *)**(undefined4 **)param_1)(param_1);
                    
                  goto override_jmp_97b98aec_case_0;
                }
                goto LAB_97b98c14;
              }
              pcVar15 = *(char **)(param_2 + 0x6c);
              uVar9 = (*(code *)**(undefined4 **)param_1)(param_1);
                    
override_jmp_97b98aec_case_0:
              TInfoSinkBase__append(pcVar15);
              bVar1 = (uVar9 & 0xffff) == 0;
              bVar18 = bVar1 << 1;
              if (bVar1) {
                _sprintf((char *)aaStack_1a0,"%d:? ",(int)uVar9 >> 0x10);
              }
              else {
                _sprintf((char *)aaStack_1a0,"%d:%d",(int)uVar9 >> 0x10);
              }
              std__string__string((unsigned char *)&local_1b0,(char *)aaStack_1a0,aaStack_160);
              *(undefined *)((int)local_1b0 + (int)local_1b0[-3]) = *PTR__S_terminal_a7b7c0b8;
              TInfoSinkBase__append(pcVar15);
              ppuVar4 = local_1b0 + -1;
              do {
                puVar5 = *ppuVar4;
                if (in_RESERVE != '\0') {
                  puVar2 = (undefined *)storeWordConditionalIndexed(puVar5 + -1,0,ppuVar4);
                  *ppuVar4 = puVar2;
                  bVar18 = 2;
                }
              } while (!(bool)(bVar18 >> 1 & 1));
              if ((int)puVar5 < 1) {
                std__string___Rep___M_destroy((unsigned char *)(local_1b0 + -3));
              }
              TInfoSinkBase__append(pcVar15);
              TInfoSinkBase__append(pcVar15);
              TInfoSinkBase__append(pcVar15);
            }
          }
LAB_97b98dd8:
          iVar14 = iVar14 + 1;
          *(int *)(param_2 + 0x30) = *(int *)(param_2 + 0x30) + 1;
          if (iVar16 <= iVar14) {
            return;
          }
        } while( true );
      }
      iVar12 = (**(code **)(*(int *)param_1 + 0x60))(param_1);
      *(undefined1 *)(*(int *)(iVar12 + 4) + *(int *)(*(int *)(iVar12 + 4) + -0xc)) = *DAT_a7b7ba10;
      _sprintf((char *)&local_1b0,
               "\'constructor\' : constant \'%s\' has not been initialized correctly",
               *(undefined4 *)(iVar12 + 4));
      pcVar15 = *(char **)(param_2 + 0x6c);
      uVar9 = (*(code *)**(undefined4 **)param_1)(param_1);
                    
      TInfoSinkBase__append(pcVar15);
      bVar1 = (uVar9 & 0xffff) == 0;
      bVar18 = bVar1 << 1;
      if (bVar1) {
        _sprintf(acStack_d0,"%d:? ",(int)uVar9 >> 0x10);
      }
      else {
        _sprintf(acStack_d0,"%d:%d",(int)uVar9 >> 0x10);
      }
      std__string__string((unsigned char *)aiStack_e0,acStack_d0,aaStack_90);
      *(undefined *)(aiStack_e0[0] + *(int *)(aiStack_e0[0] + -0xc)) = *PTR__S_terminal_a7b7c0b8;
      TInfoSinkBase__append(pcVar15);
      piVar3 = (int *)(aiStack_e0[0] + -4);
      do {
        iVar12 = *piVar3;
        if (in_RESERVE != '\0') {
          iVar13 = storeWordConditionalIndexed(iVar12 + -1,0,piVar3);
          *piVar3 = iVar13;
          bVar18 = 2;
        }
      } while (!(bool)(bVar18 >> 1 & 1));
      if (iVar12 < 1) {
        std__string___Rep___M_destroy((unsigned char *)(aiStack_e0[0] + -0xc));
      }
      TInfoSinkBase__append(pcVar15);
    }
    else {
      ((int (*)())TType__getCompleteString)();
      *(undefined1 *)(local_1ac + *(int *)(local_1ac + -0xc)) = *DAT_a7b7ba10;
      _sprintf(acStack_180,"\'constructor\' : assigning non-constant to %s",local_1ac);
      piVar3 = (int *)(local_1ac + -4);
      local_b0 = local_1b0;
      do {
        iVar12 = *piVar3;
        if (in_RESERVE != '\0') {
          iVar13 = storeWordConditionalIndexed(iVar12 + -1,0,piVar3);
          *piVar3 = iVar13;
          in_cr0 = 2;
        }
      } while (!(bool)(in_cr0 >> 1 & 1));
      if (iVar12 < 1) {
        std__string___Rep___M_destroy((unsigned char *)(local_1ac + -0xc));
      }
      pcVar15 = *(char **)(param_2 + 0x6c);
      uVar9 = (*(code *)**(undefined4 **)param_1)(param_1);
                    
      TInfoSinkBase__append(pcVar15);
      bVar1 = (uVar9 & 0xffff) == 0;
      bVar18 = bVar1 << 1;
      if (bVar1) {
        _sprintf(acStack_a0,"%d:? ",(int)uVar9 >> 0x10);
      }
      else {
        _sprintf(acStack_a0,"%d:%d",(int)uVar9 >> 0x10);
      }
      std__string__string((unsigned char *)&local_1b0,acStack_a0,aaStack_1a0);
      *(undefined *)((int)local_1b0 + (int)local_1b0[-3]) = *PTR__S_terminal_a7b7c0b8;
      TInfoSinkBase__append(pcVar15);
      ppuVar4 = local_1b0 + -1;
      do {
        puVar5 = *ppuVar4;
        if (in_RESERVE != '\0') {
          puVar2 = (undefined *)storeWordConditionalIndexed(puVar5 + -1,0,ppuVar4);
          *ppuVar4 = puVar2;
          bVar18 = 2;
        }
      } while (!(bool)(bVar18 >> 1 & 1));
      if ((int)puVar5 < 1) {
        std__string___Rep___M_destroy((unsigned char *)(local_1b0 + -3));
      }
      TInfoSinkBase__append(pcVar15);
    }
    TInfoSinkBase__append(pcVar15);
    TInfoSinkBase__append(pcVar15);
    *(undefined4 *)(param_2 + 0x74) = 1;
  }
  return;
}

/* ParseBinary @ 0x97b98e04 (308 bytes) */
int ParseBinary(param_1, param_2, param_3)
  int param_1;
  unsigned char * param_2;
  unsigned char * param_3;
{
  bool bVar1;
  int iVar2;
  undefined *puVar3;
  int *piVar4;
  undefined **ppuVar5;
  int iVar6;
  undefined *puVar7;
  uint uVar8;
  char *pcVar9;
  char in_RESERVE;
  byte in_cr0;
  byte bVar10;
  undefined **local_170;
  int local_16c;
  unsigned char aaStack_160 [20];
  uint local_14c;
  char acStack_140 [32];
  unsigned char aaStack_120 [176];
  undefined **local_70;
  char acStack_60 [72];
  
  (**(code **)(*(int *)param_2 + 0x38))(&local_170);
  local_170 = &PTR__TType_a7b7d488;
  if (local_14c >> 0x19 == 2) {
    pcVar9 = *(char **)(param_3 + 0x6c);
    uVar8 = (*(code *)**(undefined4 **)param_2)(param_2);
                    
    TInfoSinkBase__append(pcVar9);
    bVar1 = (uVar8 & 0xffff) == 0;
    bVar10 = bVar1 << 1;
    if (bVar1) {
      _sprintf((char *)aaStack_160,"%d:? ",(int)uVar8 >> 0x10);
    }
    else {
      _sprintf((char *)aaStack_160,"%d:%d",(int)uVar8 >> 0x10);
    }
    std__string__string((unsigned char *)&local_170,(char *)aaStack_160,aaStack_120);
    *(undefined *)((int)local_170 + (int)local_170[-3]) = *PTR__S_terminal_a7b7c0b8;
    TInfoSinkBase__append(pcVar9);
    ppuVar5 = local_170 + -1;
    do {
      puVar7 = *ppuVar5;
      if (in_RESERVE != '\0') {
        puVar3 = (undefined *)storeWordConditionalIndexed(puVar7 + -1,0,ppuVar5);
        *ppuVar5 = puVar3;
        bVar10 = 2;
      }
    } while (!(bool)(bVar10 >> 1 & 1));
    if ((int)puVar7 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_170 + -3));
    }
    TInfoSinkBase__append(pcVar9);
    TInfoSinkBase__append(pcVar9);
    TInfoSinkBase__append(pcVar9);
  }
  else {
    ((int (*)())TType__getCompleteString)();
    *(undefined1 *)(local_16c + *(int *)(local_16c + -0xc)) = *DAT_a7b7ba10;
    _sprintf(acStack_140,"\'constructor\' : assigning non-constant to %s",local_16c);
    piVar4 = (int *)(local_16c + -4);
    local_70 = local_170;
    do {
      iVar6 = *piVar4;
      if (in_RESERVE != '\0') {
        iVar2 = storeWordConditionalIndexed(iVar6 + -1,0,piVar4);
        *piVar4 = iVar2;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar6 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_16c + -0xc));
    }
    pcVar9 = *(char **)(param_3 + 0x6c);
    uVar8 = (*(code *)**(undefined4 **)param_2)(param_2);
                    
    TInfoSinkBase__append(pcVar9);
    bVar1 = (uVar8 & 0xffff) == 0;
    bVar10 = bVar1 << 1;
    if (bVar1) {
      _sprintf(acStack_60,"%d:? ",(int)uVar8 >> 0x10);
    }
    else {
      _sprintf(acStack_60,"%d:%d",(int)uVar8 >> 0x10);
    }
    std__string__string((unsigned char *)&local_170,acStack_60,aaStack_160);
    *(undefined *)((int)local_170 + (int)local_170[-3]) = *PTR__S_terminal_a7b7c0b8;
    TInfoSinkBase__append(pcVar9);
    ppuVar5 = local_170 + -1;
    do {
      puVar7 = *ppuVar5;
      if (in_RESERVE != '\0') {
        puVar3 = (undefined *)storeWordConditionalIndexed(puVar7 + -1,0,ppuVar5);
        *ppuVar5 = puVar3;
        bVar10 = 2;
      }
    } while (!(bool)(bVar10 >> 1 & 1));
    if ((int)puVar7 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_170 + -3));
    }
    TInfoSinkBase__append(pcVar9);
    TInfoSinkBase__append(pcVar9);
    TInfoSinkBase__append(pcVar9);
    *(undefined4 *)(param_3 + 0x74) = 1;
  }
  return 0;
}

/* FUN_97b9907c @ 0x97b9907c (240 bytes) */
int FUN_97b9907c()
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  char *unaff_r29;
  uint unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar5;
  int in_stack_00000040;
  
  TInfoSinkBase__append(unaff_r29);
  bVar1 = (unaff_r30 & 0xffff) == 0;
  bVar5 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8f9d8),(int)unaff_r30 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8f9d0),(int)unaff_r30 >> 0x10);
  }
  std__string__string((unsigned char *)&STACKARG(0x40),&STACKARG(0x50),(unsigned char *)&STACKARG(0x90));
  *(undefined1 *)(in_stack_00000040 + *(int *)(in_stack_00000040 + -0xc)) =
       **(undefined1 **)(unaff_r31 + 0xffe32a4);
  TInfoSinkBase__append(unaff_r29);
  piVar3 = (int *)(in_stack_00000040 + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar4 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(in_stack_00000040 + -0xc));
  }
  TInfoSinkBase__append(unaff_r29);
  TInfoSinkBase__append(unaff_r29);
  TInfoSinkBase__append(unaff_r29);
  return 0;
}

/* ParseUnary @ 0x97b99198 (196 bytes) */
int ParseUnary(param_1, param_2, param_3)
  int param_1;
  unsigned char * param_2;
  unsigned char * param_3;
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  char in_RESERVE;
  byte in_cr0;
  byte bVar7;
  char acStack_160 [208];
  int local_90;
  int local_8c;
  int local_80;
  char acStack_70 [64];
  unsigned char aaStack_30 [28];
  
  ((int (*)())TType__getCompleteString)();
  *(undefined1 *)(local_8c + *(int *)(local_8c + -0xc)) = *DAT_a7b7ba10;
  _sprintf(acStack_160,"\'constructor\' : assigning non-constant to \'%s\'",local_8c);
  piVar3 = (int *)(local_8c + -4);
  local_80 = local_90;
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar4 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(local_8c + -0xc));
  }
  pcVar6 = *(char **)(param_3 + 0x6c);
  uVar5 = (*(code *)**(undefined4 **)param_2)(param_2);
                    
  TInfoSinkBase__append(pcVar6);
  bVar1 = (uVar5 & 0xffff) == 0;
  bVar7 = bVar1 << 1;
  if (bVar1) {
    _sprintf(acStack_70,"%d:? ",(int)uVar5 >> 0x10);
  }
  else {
    _sprintf(acStack_70,"%d:%d",(int)uVar5 >> 0x10);
  }
  std__string__string((unsigned char *)&local_90,acStack_70,aaStack_30);
  *(undefined *)(local_90 + *(int *)(local_90 + -0xc)) = *PTR__S_terminal_a7b7c0b8;
  TInfoSinkBase__append(pcVar6);
  piVar3 = (int *)(local_90 + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar7 = 2;
    }
  } while (!(bool)(bVar7 >> 1 & 1));
  if (iVar4 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(local_90 + -0xc));
  }
  TInfoSinkBase__append(pcVar6);
  TInfoSinkBase__append(pcVar6);
  TInfoSinkBase__append(pcVar6);
  *(undefined4 *)(param_3 + 0x74) = 1;
  return 0;
}

/* FUN_97b99274 @ 0x97b99274 (248 bytes) */
int FUN_97b99274()
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  unsigned char * unaff_r27;
  int unaff_r28;
  uint unaff_r29;
  char *unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar5;
  int in_stack_00000110;
  
  TInfoSinkBase__append(unaff_r30);
  bVar1 = (unaff_r29 & 0xffff) == 0;
  bVar5 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x130),(char *)(unaff_r31 + 0x8f644),(int)unaff_r29 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x130),(char *)(unaff_r31 + 0x8f63c),(int)unaff_r29 >> 0x10);
  }
  std__string__string(unaff_r27,&STACKARG(0x130),(unsigned char *)&STACKARG(0x170));
  *(undefined1 *)(in_stack_00000110 + *(int *)(in_stack_00000110 + -0xc)) =
       **(undefined1 **)(unaff_r31 + 0xffe2f10);
  TInfoSinkBase__append(unaff_r30);
  piVar3 = (int *)(in_stack_00000110 + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar4 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(in_stack_00000110 + -0xc));
  }
  TInfoSinkBase__append(unaff_r30);
  TInfoSinkBase__append(unaff_r30);
  TInfoSinkBase__append(unaff_r30);
  *(undefined4 *)(unaff_r28 + 0x74) = 1;
  return 0;
}

/* ParseAggregate @ 0x97b99398 (884 bytes) */
int ParseAggregate(param_1, param_2, param_3)
  int param_1;
  unsigned char * param_2;
  unsigned char * param_3;
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  undefined4 *puVar7;
  char in_RESERVE;
  byte in_cr0;
  byte bVar8;
  undefined **local_160 [9];
  uint local_13c;
  undefined **local_130 [6];
  undefined4 local_118;
  uint local_10c;
  int local_90;
  int local_8c;
  int local_80;
  char acStack_70 [64];
  unsigned char aaStack_30 [24];
  
  iVar4 = ((int (*)())TIntermOperator__isConstructor)();
  if ((iVar4 == 0) && (*(int *)(param_2 + 0x30) != 0x25)) {
    ((int (*)())TType__getCompleteString)();
    *(undefined1 *)(local_8c + *(int *)(local_8c + -0xc)) = *DAT_a7b7ba10;
    _sprintf((char *)local_160,"\'constructor\' : assigning non-constant to \'%s\'",local_8c);
    piVar3 = (int *)(local_8c + -4);
    local_80 = local_90;
    do {
      iVar4 = *piVar3;
      if (in_RESERVE != '\0') {
        iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
        *piVar3 = iVar2;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar4 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_8c + -0xc));
    }
    pcVar6 = *(char **)(param_3 + 0x6c);
    uVar5 = (*(code *)**(undefined4 **)param_2)(param_2);
                    
    TInfoSinkBase__append(pcVar6);
    bVar1 = (uVar5 & 0xffff) == 0;
    bVar8 = bVar1 << 1;
    if (bVar1) {
      _sprintf(acStack_70,"%d:? ",(int)uVar5 >> 0x10);
    }
    else {
      _sprintf(acStack_70,"%d:%d",(int)uVar5 >> 0x10);
    }
    std__string__string((unsigned char *)&local_90,acStack_70,aaStack_30);
    *(undefined *)(local_90 + *(int *)(local_90 + -0xc)) = *PTR__S_terminal_a7b7c0b8;
    TInfoSinkBase__append(pcVar6);
    piVar3 = (int *)(local_90 + -4);
    do {
      iVar4 = *piVar3;
      if (in_RESERVE != '\0') {
        iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
        *piVar3 = iVar2;
        bVar8 = 2;
      }
    } while (!(bool)(bVar8 >> 1 & 1));
    if (iVar4 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_90 + -0xc));
    }
    TInfoSinkBase__append(pcVar6);
    TInfoSinkBase__append(pcVar6);
    TInfoSinkBase__append(pcVar6);
  }
  else {
    iVar4 = (**(code **)(*(int *)param_2 + 100))(param_2);
    if ((uint)(*(int *)(iVar4 + 8) - *(int *)(iVar4 + 4)) >> 2 != 0) {
      bVar1 = false;
      iVar4 = (**(code **)(*(int *)param_2 + 100))(param_2);
      if (*(int *)(iVar4 + 8) - *(int *)(iVar4 + 4) >> 2 == 1) {
        iVar4 = (**(code **)(*(int *)param_2 + 100))(param_2);
        piVar3 = (int *)(**(code **)(*(int *)**(undefined4 **)(iVar4 + 4) + 0x14))();
        iVar4 = (**(code **)(*piVar3 + 0x18))();
        if (iVar4 != 0) {
          bVar1 = true;
        }
      }
      if (bVar1) {
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
      for (puVar7 = *(undefined4 **)(iVar4 + 4);
          iVar4 = (**(code **)(*(int *)param_2 + 100))(param_2),
          puVar7 != *(undefined4 **)(iVar4 + 8); puVar7 = puVar7 + 1) {
        if (*(int *)(param_2 + 0x30) == 0x25) {
          *(undefined4 *)(param_3 + 0x30) = 0;
        }
        (**(code **)(*(int *)*puVar7 + 8))((int *)*puVar7,param_3);
      }
      if (!bVar1) {
        return 0;
      }
      *(undefined4 *)(param_3 + 0x80) = 0;
      *(undefined4 *)(param_3 + 0x68) = 0;
      *(undefined4 *)(param_3 + 100) = 0;
      *(undefined4 *)(param_3 + 0x78) = 0;
      *(undefined4 *)(param_3 + 0x7c) = 0;
      return 0;
    }
  }
  *(undefined4 *)(param_3 + 0x74) = 1;
  return 0;
}

/* ParseSelection @ 0x97b9982c (88 bytes) */
int ParseSelection(param_1, param_2, param_3)
  int param_1;
  unsigned char * param_2;
  unsigned char * param_3;
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  char in_RESERVE;
  byte bVar7;
  int aiStack_80 [4];
  char acStack_70 [64];
  unsigned char aaStack_30 [28];
  
  pcVar6 = *(char **)(param_3 + 0x6c);
  uVar5 = (*(code *)**(undefined4 **)param_2)(param_2);
                    
  TInfoSinkBase__append(pcVar6);
  bVar1 = (uVar5 & 0xffff) == 0;
  bVar7 = bVar1 << 1;
  if (bVar1) {
    _sprintf(acStack_70,"%d:? ",(int)uVar5 >> 0x10);
  }
  else {
    _sprintf(acStack_70,"%d:%d",(int)uVar5 >> 0x10);
  }
  std__string__string((unsigned char *)aiStack_80,acStack_70,aaStack_30);
  *(undefined *)(aiStack_80[0] + *(int *)(aiStack_80[0] + -0xc)) = *PTR__S_terminal_a7b7c0b8;
  TInfoSinkBase__append(pcVar6);
  piVar3 = (int *)(aiStack_80[0] + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar7 = 2;
    }
  } while (!(bool)(bVar7 >> 1 & 1));
  if (iVar4 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(aiStack_80[0] + -0xc));
  }
  TInfoSinkBase__append(pcVar6);
  TInfoSinkBase__append(pcVar6);
  TInfoSinkBase__append(pcVar6);
  *(undefined4 *)(param_3 + 0x74) = 1;
  return 0;
}

/* FUN_97b9989c @ 0x97b9989c (248 bytes) */
int FUN_97b9989c()
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int unaff_r27;
  uint unaff_r29;
  char *unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar5;
  int in_stack_00000040;
  
  TInfoSinkBase__append(unaff_r30);
  bVar1 = (unaff_r29 & 0xffff) == 0;
  bVar5 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8efb0),(int)unaff_r29 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8efa8),(int)unaff_r29 >> 0x10);
  }
  std__string__string((unsigned char *)&STACKARG(0x40),&STACKARG(0x50),(unsigned char *)&STACKARG(0x90));
  *(undefined1 *)(in_stack_00000040 + *(int *)(in_stack_00000040 + -0xc)) =
       **(undefined1 **)(unaff_r31 + 0xffe287c);
  TInfoSinkBase__append(unaff_r30);
  piVar3 = (int *)(in_stack_00000040 + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar4 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(in_stack_00000040 + -0xc));
  }
  TInfoSinkBase__append(unaff_r30);
  TInfoSinkBase__append(unaff_r30);
  TInfoSinkBase__append(unaff_r30);
  *(undefined4 *)(unaff_r27 + 0x74) = 1;
  return 0;
}

/* ParseConstantUnion @ 0x97b999c0 (1160 bytes) */
int ParseConstantUnion(param_1, param_2)
  unsigned char * param_1;
  unsigned char * param_2;
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
  unsigned char * param_2;
  unsigned char * param_3;
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  char in_RESERVE;
  byte bVar7;
  int aiStack_80 [4];
  char acStack_70 [64];
  unsigned char aaStack_30 [28];
  
  pcVar6 = *(char **)(param_3 + 0x6c);
  uVar5 = (*(code *)**(undefined4 **)param_2)(param_2);
                    
  TInfoSinkBase__append(pcVar6);
  bVar1 = (uVar5 & 0xffff) == 0;
  bVar7 = bVar1 << 1;
  if (bVar1) {
    _sprintf(acStack_70,"%d:? ",(int)uVar5 >> 0x10);
  }
  else {
    _sprintf(acStack_70,"%d:%d",(int)uVar5 >> 0x10);
  }
  std__string__string((unsigned char *)aiStack_80,acStack_70,aaStack_30);
  *(undefined *)(aiStack_80[0] + *(int *)(aiStack_80[0] + -0xc)) = *PTR__S_terminal_a7b7c0b8;
  TInfoSinkBase__append(pcVar6);
  piVar3 = (int *)(aiStack_80[0] + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar7 = 2;
    }
  } while (!(bool)(bVar7 >> 1 & 1));
  if (iVar4 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(aiStack_80[0] + -0xc));
  }
  TInfoSinkBase__append(pcVar6);
  TInfoSinkBase__append(pcVar6);
  TInfoSinkBase__append(pcVar6);
  *(undefined4 *)(param_3 + 0x74) = 1;
  return 0;
}

/* FUN_97b99eb8 @ 0x97b99eb8 (248 bytes) */
int FUN_97b99eb8()
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int unaff_r27;
  uint unaff_r29;
  char *unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar5;
  int in_stack_00000040;
  
  TInfoSinkBase__append(unaff_r30);
  bVar1 = (unaff_r29 & 0xffff) == 0;
  bVar5 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8e994),(int)unaff_r29 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8e98c),(int)unaff_r29 >> 0x10);
  }
  std__string__string((unsigned char *)&STACKARG(0x40),&STACKARG(0x50),(unsigned char *)&STACKARG(0x90));
  *(undefined1 *)(in_stack_00000040 + *(int *)(in_stack_00000040 + -0xc)) =
       **(undefined1 **)(unaff_r31 + 0xffe2260);
  TInfoSinkBase__append(unaff_r30);
  piVar3 = (int *)(in_stack_00000040 + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar4 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(in_stack_00000040 + -0xc));
  }
  TInfoSinkBase__append(unaff_r30);
  TInfoSinkBase__append(unaff_r30);
  TInfoSinkBase__append(unaff_r30);
  *(undefined4 *)(unaff_r27 + 0x74) = 1;
  return 0;
}

/* ParseBranch @ 0x97b99fdc (88 bytes) */
int ParseBranch(param_1, param_2, param_3)
  int param_1;
  unsigned char * param_2;
  unsigned char * param_3;
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  char in_RESERVE;
  byte bVar7;
  int aiStack_80 [4];
  char acStack_70 [64];
  unsigned char aaStack_30 [28];
  
  pcVar6 = *(char **)(param_3 + 0x6c);
  uVar5 = (*(code *)**(undefined4 **)param_2)(param_2);
                    
  TInfoSinkBase__append(pcVar6);
  bVar1 = (uVar5 & 0xffff) == 0;
  bVar7 = bVar1 << 1;
  if (bVar1) {
    _sprintf(acStack_70,"%d:? ",(int)uVar5 >> 0x10);
  }
  else {
    _sprintf(acStack_70,"%d:%d",(int)uVar5 >> 0x10);
  }
  std__string__string((unsigned char *)aiStack_80,acStack_70,aaStack_30);
  *(undefined *)(aiStack_80[0] + *(int *)(aiStack_80[0] + -0xc)) = *PTR__S_terminal_a7b7c0b8;
  TInfoSinkBase__append(pcVar6);
  piVar3 = (int *)(aiStack_80[0] + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar7 = 2;
    }
  } while (!(bool)(bVar7 >> 1 & 1));
  if (iVar4 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(aiStack_80[0] + -0xc));
  }
  TInfoSinkBase__append(pcVar6);
  TInfoSinkBase__append(pcVar6);
  TInfoSinkBase__append(pcVar6);
  *(undefined4 *)(param_3 + 0x74) = 1;
  return 0;
}

/* FUN_97b9a04c @ 0x97b9a04c (248 bytes) */
int FUN_97b9a04c()
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int unaff_r27;
  uint unaff_r29;
  char *unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar5;
  int in_stack_00000040;
  
  TInfoSinkBase__append(unaff_r30);
  bVar1 = (unaff_r29 & 0xffff) == 0;
  bVar5 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8e800),(int)unaff_r29 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8e7f8),(int)unaff_r29 >> 0x10);
  }
  std__string__string((unsigned char *)&STACKARG(0x40),&STACKARG(0x50),(unsigned char *)&STACKARG(0x90));
  *(undefined1 *)(in_stack_00000040 + *(int *)(in_stack_00000040 + -0xc)) =
       **(undefined1 **)(unaff_r31 + 0xffe20cc);
  TInfoSinkBase__append(unaff_r30);
  piVar3 = (int *)(in_stack_00000040 + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar4 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(in_stack_00000040 + -0xc));
  }
  TInfoSinkBase__append(unaff_r30);
  TInfoSinkBase__append(unaff_r30);
  TInfoSinkBase__append(unaff_r30);
  *(undefined4 *)(unaff_r27 + 0x74) = 1;
  return 0;
}

/* TIntermediate__parseConstTree @ 0x97b9a170 (428 bytes) */
int TIntermediate__parseConstTree(this, param_2_00, param_2, param_3, param_5, param_6, param_7, param_8)
  unsigned char * this;
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
  unsigned char * this;
  unsigned char * param_1;
  int param_2;
  unsigned char * param_3;
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
  unsigned char * this;
  unsigned char * param_1;
  int param_2;
  unsigned char * param_3;
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
  unsigned char * this;
{
  *(undefined4 *)(this + 0x14) = 1;
  return;
}

/* TParseContext__error @ 0x97b9a7c4 (104 bytes) */
int TParseContext__error(param_1, param_2, param_3, param_4)
  int param_1;
  char *param_2;
  char *param_3;
  char *param_4;
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  char *in_r7;
  undefined4 in_r8;
  undefined4 in_r9;
  undefined4 in_r10;
  char *pcVar5;
  char in_RESERVE;
  byte bVar6;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  char acStack_210 [400];
  int aiStack_80 [4];
  char acStack_70 [64];
  unsigned char aaStack_30 [24];
  
  uStack0000002c = in_r8;
  uStack00000030 = in_r9;
  uStack00000034 = in_r10;
  _vsnprintf(acStack_210,400,in_r7,&STACKARG(0x2c));
                    
  TInfoSinkBase__append(*(char **)(param_1 + 8));
  pcVar5 = *(char **)(param_1 + 8);
  bVar1 = ((uint)param_2 & 0xffff) == 0;
  bVar6 = bVar1 << 1;
  if (bVar1) {
    _sprintf(acStack_70,"%d:? ",(int)param_2 >> 0x10);
  }
  else {
    _sprintf(acStack_70,"%d:%d",(int)param_2 >> 0x10);
  }
  std__string__string((unsigned char *)aiStack_80,acStack_70,aaStack_30);
  *(undefined *)(aiStack_80[0] + *(int *)(aiStack_80[0] + -0xc)) = *PTR__S_terminal_a7b7c0b8;
  TInfoSinkBase__append(pcVar5);
  piVar3 = (int *)(aiStack_80[0] + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar6 = 2;
    }
  } while (!(bool)(bVar6 >> 1 & 1));
  if (iVar4 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(aiStack_80[0] + -0xc));
  }
  TInfoSinkBase__append(pcVar5);
  pcVar5 = *(char **)(param_1 + 8);
  TInfoSinkBase__append(pcVar5);
  TInfoSinkBase__append(pcVar5);
  TInfoSinkBase__append(pcVar5);
  TInfoSinkBase__append(pcVar5);
  TInfoSinkBase__append(pcVar5);
  TInfoSinkBase__append(pcVar5);
  TInfoSinkBase__append(pcVar5);
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
  return;
}

/* FUN_97b9a844 @ 0x97b9a844 (324 bytes) */
int FUN_97b9a844(param_1)
  char *param_1;
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint unaff_r28;
  char *pcVar5;
  int unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar6;
  int in_stack_000001d0;
  
  TInfoSinkBase__append(param_1);
  pcVar5 = *(char **)(unaff_r30 + 8);
  bVar1 = (unaff_r28 & 0xffff) == 0;
  bVar6 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x1e0),(char *)(unaff_r31 + 0x8e018),(int)unaff_r28 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x1e0),(char *)(unaff_r31 + 0x8e010),(int)unaff_r28 >> 0x10);
  }
  std__string__string((unsigned char *)&STACKARG(0x1d0),&STACKARG(0x1e0),(unsigned char *)&STACKARG(0x220));
  *(undefined1 *)(in_stack_000001d0 + *(int *)(in_stack_000001d0 + -0xc)) =
       **(undefined1 **)(unaff_r31 + 0xffe18e4);
  TInfoSinkBase__append(pcVar5);
  piVar3 = (int *)(in_stack_000001d0 + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar6 = 2;
    }
  } while (!(bool)(bVar6 >> 1 & 1));
  if (iVar4 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(in_stack_000001d0 + -0xc));
  }
  TInfoSinkBase__append(pcVar5);
  pcVar5 = *(char **)(unaff_r30 + 8);
  TInfoSinkBase__append(pcVar5);
  TInfoSinkBase__append(pcVar5);
  TInfoSinkBase__append(pcVar5);
  TInfoSinkBase__append(pcVar5);
  TInfoSinkBase__append(pcVar5);
  TInfoSinkBase__append(pcVar5);
  TInfoSinkBase__append(pcVar5);
  *(int *)(unaff_r30 + 0x18) = *(int *)(unaff_r30 + 0x18) + 1;
  return;
}

/* TParseContext__assignError @ 0x97b9a9b4 (96 bytes) */
int TParseContext__assignError(this, param_1, param_2, param_4, param_5)
  unsigned char * this;
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
  unsigned char * this;
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
  unsigned char * this;
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
  unsigned char * this;
  int param_1;
  char *param_2;
  unsigned char * param_3;
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  unsigned char * pTVar5;
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
  unsigned char * this;
  unsigned char * param_1;
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
  unsigned char * this;
  unsigned char * param_1;
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
  unsigned char * this;
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
  unsigned char * this;
  int param_1;
  unsigned char * param_2;
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
    local_60[0] = GetGlobalPoolAllocator();
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
  unsigned char * this;
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
  unsigned char * psVar7;
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
  unsigned char * local_b0;
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
    uVar8 = GetGlobalPoolAllocator();
    psVar7 = (unsigned char *)TPoolAllocator__allocate(uVar8);
    bVar17 = (psVar7 == (unsigned char *)0x0) << 1;
    local_b0 = (unsigned char *)0x0;
    if (psVar7 != (unsigned char *)0x0) {
      local_70[0] = GetGlobalPoolAllocator();
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
  unsigned char * this;
  int param_1;
  unsigned char * param_2;
  unsigned char * param_3;
{
  int iVar1;
  
  iVar1 = *(int *)param_3;
  if (iVar1 == 0) {
    *(undefined1 *)(*(int *)(param_2 + 4) + *(int *)(*(int *)(param_2 + 4) + -0xc)) = *DAT_a7b7ba18;
    error((int)this,(char *)param_1,"illegal use of type \'void\'",*(char **)(param_2 + 4),"");
  }
  return iVar1 == 0;
}

