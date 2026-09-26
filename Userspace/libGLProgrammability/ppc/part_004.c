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
    iVar2 = (**(code **)(**(int **)(param_1 + 0x34) + 0x40))(*(int **)(param_1 + 0x34));
    bVar1 = iVar2 == 2;
LAB_97b9055c:
    if (!bVar1) {
      return 0;
    }
  }
  else {
    if (iVar2 < 9) {
      if (iVar2 == 6) {
        iVar2 = (**(code **)(**(int **)(param_1 + 0x34) + 0x40))(*(int **)(param_1 + 0x34));
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
      iVar2 = (**(code **)(**(int **)(param_1 + 0x34) + 0x40))(*(int **)(param_1 + 0x34));
      bVar1 = iVar2 == 1;
      goto LAB_97b9055c;
    }
    iVar2 = (**(code **)(**(int **)(param_1 + 0x34) + 0x40))(*(int **)(param_1 + 0x34));
    if (iVar2 == 3) {
      return 0;
    }
  }
  (**(code **)(**(int **)(param_1 + 0x34) + 0x38))(local_40,*(int **)(param_1 + 0x34));
  (**(code **)(*(int *)param_1 + 0x34))(param_1,local_40);
  return 1;
}

/* TIntermBinary__promote @ 0x97b905bc (1680 bytes) */
int TIntermBinary__promote(this, param_2, param_3, param_4, param_5, param_6)
  unsigned char * this;
  unsigned char * param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
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
  undefined4 a1;
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
  
  uVar6 = (**(code **)(**(int **)(this + 0x34) + 0x48))
                    (*(int **)(this + 0x34),param_2,param_3,param_4,param_5,param_6);
  iVar7 = (**(code **)(**(int **)(this + 0x38) + 0x48))(*(int **)(this + 0x38));
  if ((int)uVar6 < iVar7) {
    uVar6 = (**(code **)(**(int **)(this + 0x38) + 0x48))(*(int **)(this + 0x38));
  }
  uVar8 = (**(code **)(**(int **)(this + 0x34) + 0x40))(*(int **)(this + 0x34));
  iVar7 = (**(code **)(**(int **)(this + 0x34) + 0x54))(*(int **)(this + 0x34));
  if (iVar7 != 0) {
    return 0;
  }
  local_9c = (**(code **)(**(int **)(this + 0x38) + 0x54))(*(int **)(this + 0x38));
  if (local_9c != 0) {
    return 0;
  }
  uVar9 = (**(code **)(**(int **)(this + 0x34) + 0x48))(*(int **)(this + 0x34));
  uVar10 = (**(code **)(**(int **)(this + 0x34) + 0x50))(*(int **)(this + 0x34));
  local_7c = (uVar10 & 1) << 10 | (uVar9 & 0xff) << 0xb | (uVar8 & 0x3f) << 0x13 | local_7c & 0x1ff;
  local_a0 = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  local_98 = local_9c;
  local_94 = local_9c;
  local_90 = local_9c;
  local_8c = local_9c;
  local_88 = local_9c;
  local_84 = local_9c;
  local_80 = local_9c;
  (**(code **)(*(int *)this + 0x34))(this,&local_a0);
  local_a0 = &PTR___ZN5TTypeD1Ev_a7b7cff8;
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
          iVar7 = (**(code **)(**(int **)(this + 0x34) + 0x40))(*(int **)(this + 0x34));
          if (iVar7 != 2) {
            return 0;
          }
          iVar7 = (**(code **)(**(int **)(this + 0x38) + 0x40))(*(int **)(this + 0x38));
          bVar1 = iVar7 == 2;
          goto LAB_97b90940;
        }
        if (iVar7 < 0x1f) goto LAB_97b90770;
      }
    }
    else {
      if (iVar7 == 0x2c) {
LAB_97b907c4:
        iVar7 = (**(code **)(**(int **)(this + 0x34) + 0x40))(*(int **)(this + 0x34),a1);
        if (iVar7 != 3) {
          return 0;
        }
        iVar7 = (**(code **)(**(int **)(this + 0x38) + 0x40))(*(int **)(this + 0x38));
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
        local_a0 = &PTR___ZN5TTypeD1Ev_a7b7cff8;
        (**(code **)(iVar7 + 0x34))(this,&local_a0,param_3,param_4,param_5,param_6,iVar7);
        return 1;
      }
      if (iVar7 < 0x2d) {
        if (iVar7 == 0x2a) goto LAB_97b907c4;
      }
      else if (iVar7 - 0x7fU < 6) {
        iVar7 = (**(code **)(**(int **)(this + 0x34) + 0x40))(*(int **)(this + 0x34));
        if (iVar7 != 2) {
          return 0;
        }
        iVar7 = (**(code **)(**(int **)(this + 0x38) + 0x40))(*(int **)(this + 0x38));
        if (iVar7 != 2) {
          return 0;
        }
      }
    }
    iVar7 = (**(code **)(**(int **)(this + 0x34) + 0x40))(*(int **)(this + 0x34));
    iVar11 = (**(code **)(**(int **)(this + 0x38) + 0x40))(*(int **)(this + 0x38));
    if (iVar7 != iVar11) {
      return 0;
    }
    iVar7 = (**(code **)(**(int **)(this + 0x34) + 0x50))(*(int **)(this + 0x34));
    iVar11 = (**(code **)(**(int **)(this + 0x38) + 0x50))(*(int **)(this + 0x38));
    bVar1 = iVar7 == iVar11;
LAB_97b90940:
    if (!bVar1) {
      return 0;
    }
    return 1;
  }
  uVar9 = (**(code **)(**(int **)(this + 0x34) + 0x48))(*(int **)(this + 0x34));
  if ((uVar9 != uVar6) &&
     (iVar7 = (**(code **)(**(int **)(this + 0x34) + 0x48))(*(int **)(this + 0x34)), iVar7 != 1)) {
    return 0;
  }
  uVar9 = (**(code **)(**(int **)(this + 0x38) + 0x48))(*(int **)(this + 0x38));
  uVar4 = extraout_r4;
  if ((uVar9 != uVar6) &&
     (iVar7 = (**(code **)(**(int **)(this + 0x38) + 0x48))(*(int **)(this + 0x38)),
     uVar4 = extraout_r4_00, iVar7 != 1)) {
    return 0;
  }
  uVar9 = *(int *)(this + 0x30) - 0x13;
  if (0x6c < uVar9) {
    return 0;
  }
  iVar7 = uVar9 * 4;
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
    iVar11 = (**(code **)(**(int **)(this + 0x34) + 0x50))
                       (*(int **)(this + 0x34),uVar4,param_3,param_4,param_5,param_6,iVar7);
    uVar4 = extraout_r4_01;
    if ((iVar11 == 0) &&
       (iVar11 = (**(code **)(**(int **)(this + 0x38) + 0x50))(*(int **)(this + 0x38)),
       uVar4 = extraout_r4_02, iVar11 != 0)) {
      iVar7 = (**(code **)(**(int **)(this + 0x34) + 0x58))(*(int **)(this + 0x34));
      if (iVar7 != 0) {
        uVar4 = 0x27;
        goto LAB_97b9100c;
      }
      local_7c = (uVar6 & 0xff) << 0xb | (uVar8 & 0x3f) << 0x13 | local_7c & 0x5ff | 0x400;
      iVar7 = *(int *)this;
      *(undefined4 *)(this + 0x30) = 0x29;
    }
    else {
      iVar11 = (**(code **)(**(int **)(this + 0x34) + 0x50))
                         (*(int **)(this + 0x34),uVar4,param_3,param_4,param_5,param_6,iVar7);
      uVar4 = extraout_r4_03;
      if ((iVar11 == 0) ||
         (iVar11 = (**(code **)(**(int **)(this + 0x38) + 0x50))(*(int **)(this + 0x38)),
         uVar4 = extraout_r4_04, iVar11 != 0)) {
        iVar11 = (**(code **)(**(int **)(this + 0x34) + 0x50))
                           (*(int **)(this + 0x34),uVar4,param_3,param_4,param_5,param_6,iVar7);
        if (iVar11 != 0) {
          iVar11 = (**(code **)(**(int **)(this + 0x38) + 0x50))(*(int **)(this + 0x38));
          uVar4 = 0x56;
          if (iVar11 != 0) goto LAB_97b9100c;
        }
        iVar11 = (**(code **)(**(int **)(this + 0x34) + 0x50))(*(int **)(this + 0x34));
        uVar4 = extraout_r4_05;
        if ((iVar11 != 0) ||
           (iVar11 = (**(code **)(**(int **)(this + 0x38) + 0x50))(*(int **)(this + 0x38)),
           uVar4 = extraout_r4_06, iVar11 != 0)) {
          uVar6 = (*(code *)**(undefined4 **)this)(this,uVar4,param_3,param_4,param_5,param_6,iVar7)
          ;
                    
          __ZN13TInfoSinkBase6appendEPKc(param_2,"INTERNAL ERROR: ");
          uVar8 = uVar6 & 0xffff;
          bVar13 = (uVar8 == 0) << 1;
          if (uVar8 == 0) {
            _sprintf(local_70,"%d:? ",(int)uVar6 >> 0x10);
          }
          else {
            _sprintf(local_70,"%d:%d",(int)uVar6 >> 0x10,uVar8);
          }
          __ZNSsC1EPKcRKSaIcE(&local_a0,local_70,(unsigned char *)&local_90);
          *(undefined *)((int)local_a0 + (int)local_a0[-3]) = *PTR__S_terminal_a7b7c0b8;
          __ZN13TInfoSinkBase6appendEPKc(param_2,(char *)local_a0);
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
            __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(local_a0 + -3),(unsigned char *)&local_90);
          }
          __ZN13TInfoSinkBase6appendEPKc(param_2,": ");
code_r0x97b91274:
          __ZN13TInfoSinkBase6appendEPKc(param_2,"Missing elses");
          __ZN13TInfoSinkBase6appendEPKc(param_2,"\n");
          return 0;
        }
        iVar7 = (**(code **)(**(int **)(this + 0x34) + 0x58))(*(int **)(this + 0x34));
        if (((iVar7 != 0) &&
            (iVar7 = (**(code **)(**(int **)(this + 0x38) + 0x58))(*(int **)(this + 0x38)),
            iVar7 != 0)) ||
           ((iVar7 = (**(code **)(**(int **)(this + 0x34) + 0x58))(*(int **)(this + 0x34)),
            iVar7 == 0 &&
            (iVar7 = (**(code **)(**(int **)(this + 0x38) + 0x58))(*(int **)(this + 0x38)),
            iVar7 == 0)))) goto LAB_97b91520;
        iVar7 = *(int *)this;
        uVar8 = (uVar8 & 0x3f) << 0x13 | local_7c & 0x7ffff;
        uVar4 = 0x26;
      }
      else {
        iVar7 = (**(code **)(**(int **)(this + 0x38) + 0x58))(*(int **)(this + 0x38));
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
    iVar7 = (**(code **)(**(int **)(this + 0x34) + 0x50))
                      (*(int **)(this + 0x34),uVar4,param_3,param_4,param_5,param_6,iVar7);
    if ((iVar7 != 0) &&
       (iVar7 = (**(code **)(**(int **)(this + 0x38) + 0x58))(*(int **)(this + 0x38)), iVar7 != 0))
    {
      return 0;
    }
    iVar7 = (**(code **)(**(int **)(this + 0x34) + 0x58))(*(int **)(this + 0x34));
    if ((iVar7 != 0) &&
       (iVar7 = (**(code **)(**(int **)(this + 0x38) + 0x50))(*(int **)(this + 0x38)), iVar7 != 0))
    {
      return 0;
    }
    iVar7 = (**(code **)(**(int **)(this + 0x34) + 0x40))(*(int **)(this + 0x34));
    iVar11 = (**(code **)(**(int **)(this + 0x38) + 0x40))(*(int **)(this + 0x38));
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
    iVar11 = (**(code **)(**(int **)(this + 0x34) + 0x50))(*(int **)(this + 0x34),uVar4);
    if ((iVar11 == 0) &&
       (iVar11 = (**(code **)(**(int **)(this + 0x38) + 0x50))(*(int **)(this + 0x38)), iVar11 != 0)
       ) {
      iVar7 = (**(code **)(**(int **)(this + 0x34) + 0x58))(*(int **)(this + 0x34));
      if (iVar7 == 0) {
        return 0;
      }
      uVar4 = 0x7a;
    }
    else {
      iVar11 = (**(code **)(**(int **)(this + 0x34) + 0x50))(*(int **)(this + 0x34));
      if ((iVar11 == 0) ||
         (iVar11 = (**(code **)(**(int **)(this + 0x38) + 0x50))(*(int **)(this + 0x38)),
         iVar11 != 0)) {
        iVar11 = (**(code **)(**(int **)(this + 0x34) + 0x50))(*(int **)(this + 0x34));
        if ((iVar11 == 0) ||
           (iVar11 = (**(code **)(**(int **)(this + 0x38) + 0x50))(*(int **)(this + 0x38)),
           iVar11 == 0)) {
          iVar11 = (**(code **)(**(int **)(this + 0x34) + 0x50))(*(int **)(this + 0x34));
          uVar4 = extraout_r4_07;
          if ((iVar11 != 0) ||
             (iVar11 = (**(code **)(**(int **)(this + 0x38) + 0x50))(*(int **)(this + 0x38)),
             uVar4 = extraout_r4_08, iVar11 != 0)) {
            uVar6 = (*(code *)**(undefined4 **)this)
                              (this,uVar4,param_3,param_4,param_5,param_6,iVar7);
                    
            __ZN13TInfoSinkBase6appendEPKc(param_2,"INTERNAL ERROR: ");
            uVar8 = uVar6 & 0xffff;
            bVar13 = (uVar8 == 0) << 1;
            if (uVar8 == 0) {
              _sprintf((char *)&local_90,"%d:? ",(int)uVar6 >> 0x10);
            }
            else {
              _sprintf((char *)&local_90,"%d:%d",(int)uVar6 >> 0x10,uVar8);
            }
            __ZNSsC1EPKcRKSaIcE(&local_a0,(char *)&local_90,aaStack_50);
            *(undefined *)((int)local_a0 + (int)local_a0[-3]) = *PTR__S_terminal_a7b7c0b8;
            __ZN13TInfoSinkBase6appendEPKc(param_2,(char *)local_a0);
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
              __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(local_a0 + -3),&local_90);
            }
            __ZN13TInfoSinkBase6appendEPKc(param_2,": ");
            goto code_r0x97b91274;
          }
          iVar7 = (**(code **)(**(int **)(this + 0x34) + 0x58))(*(int **)(this + 0x34));
          if (((iVar7 != 0) &&
              (iVar7 = (**(code **)(**(int **)(this + 0x38) + 0x58))(*(int **)(this + 0x38)),
              iVar7 != 0)) ||
             ((iVar7 = (**(code **)(**(int **)(this + 0x34) + 0x58))(*(int **)(this + 0x34)),
              iVar7 == 0 &&
              (iVar7 = (**(code **)(**(int **)(this + 0x38) + 0x58))(*(int **)(this + 0x38)),
              iVar7 == 0)))) goto LAB_97b91520;
          iVar7 = (**(code **)(**(int **)(this + 0x34) + 0x58))(*(int **)(this + 0x34));
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
        iVar7 = (**(code **)(**(int **)(this + 0x38) + 0x58))(*(int **)(this + 0x38));
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
  iVar7 = (**(code **)(**(int **)(this + 0x34) + 0x48))(*(int **)(this + 0x34),uVar4);
  iVar11 = (**(code **)(**(int **)(this + 0x38) + 0x48))(*(int **)(this + 0x38));
  if (iVar7 != iVar11) {
    return 0;
  }
switchD_97b909e0_caseD_13:
  iVar7 = (**(code **)(**(int **)(this + 0x34) + 0x50))(*(int **)(this + 0x34));
  if (((iVar7 == 0) ||
      (iVar7 = (**(code **)(**(int **)(this + 0x38) + 0x58))(*(int **)(this + 0x38)), iVar7 == 0))
     && ((iVar7 = (**(code **)(**(int **)(this + 0x34) + 0x58))(*(int **)(this + 0x34)), iVar7 == 0
         || (iVar7 = (**(code **)(**(int **)(this + 0x38) + 0x50))(*(int **)(this + 0x38)),
            iVar7 == 0)))) {
    iVar7 = (**(code **)(**(int **)(this + 0x34) + 0x40))(*(int **)(this + 0x34));
    iVar11 = (**(code **)(**(int **)(this + 0x38) + 0x40))(*(int **)(this + 0x38));
    if (iVar7 == iVar11) {
      iVar11 = 0;
      iVar7 = (**(code **)(**(int **)(this + 0x34) + 0x50))(*(int **)(this + 0x34));
      if ((iVar7 != 0) ||
         (iVar7 = (**(code **)(**(int **)(this + 0x38) + 0x50))(*(int **)(this + 0x38)), iVar7 != 0)
         ) {
        iVar11 = 1;
      }
      iVar7 = *(int *)this;
      local_7c = iVar11 << 10 | (uVar6 & 0xff) << 0xb | (uVar8 & 0x3f) << 0x13 | local_7c & 0x1ff;
      pcVar12 = *(code **)(iVar7 + 0x34);
LAB_97b91508:
      local_80 = 0;
      local_a0 = &PTR___ZN5TTypeD1Ev_a7b7cff8;
      local_9c = local_80;
      local_98 = local_80;
      local_94 = local_80;
      local_90 = local_80;
      local_8c = local_80;
      local_88 = local_80;
      local_84 = local_80;
      (*pcVar12)(this,&local_a0,param_3,param_4,param_5,param_6,iVar7);
      local_a0 = &PTR___ZN5TTypeD1Ev_a7b7cff8;
LAB_97b91520:
      iVar7 = *(int *)(this + 0x30);
      if ((0x75 < iVar7) && ((iVar7 < 0x7a || (iVar7 - 0x7eU < 7)))) {
        (**(code **)(*(int *)this + 0x38))(&local_a0,this);
        (**(code **)(**(int **)(this + 0x34) + 0x38))(local_70,*(int **)(this + 0x34));
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
  int *a0;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 uVar3;
  unsigned char * a2;
  int *a3;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  undefined8 uVar9;
  
  uVar6 = 0;
  iVar7 = *(int *)(param_1 + 8);
  iVar2 = *(int *)(iVar7 + 4);
  uVar5 = *(int *)(iVar7 + 8) - iVar2 >> 3;
  a2 = param_3;
  a3 = param_4;
  if (uVar5 == 0) {
    return 1;
  }
  do {
    iVar1 = uVar6 * 8;
    iVar8 = 0;
    iVar2 = (**(code **)(**(int **)(iVar2 + iVar1) + 0x30))(*(int **)(iVar2 + iVar1));
    uVar3 = extraout_r4;
    if (0 < iVar2) {
      do {
        a0 = *(int **)(*(int *)(iVar7 + 4) + iVar1);
        iVar4 = *a0;
        iVar4 = (**(code **)(iVar4 + 0x20))(a0,uVar3,a2,a3,in_r7,in_r8,iVar4);
        uVar3 = extraout_r4_00;
        if (iVar4 == 2) {
LAB_97b916a8:
          iVar4 = *param_4;
          if (*(int *)(param_3 + iVar4 * 4) != *(int *)(param_2 + iVar4 * 4)) {
            return 0;
          }
LAB_97b916c8:
          *param_4 = iVar4 + 1;
        }
        else if (iVar4 < 3) {
          if (iVar4 == 1) {
            iVar4 = *param_4;
            if (*(float *)(param_3 + iVar4 * 4) != *(float *)(param_2 + iVar4 * 4)) {
              return 0;
            }
            goto LAB_97b916c8;
          }
        }
        else {
          if (iVar4 == 3) goto LAB_97b916a8;
          if (iVar4 == 0xe) {
            a2 = param_3;
            a3 = param_4;
            uVar9 = ((int (*)())compareStructure)(*(unsigned char **)(*(int *)(iVar7 + 4) + iVar1),param_2,param_3,
                                     param_4);
            uVar3 = (undefined4)uVar9;
            if ((int)((ulonglong)uVar9 >> 0x20) == 0) {
              return 0;
            }
          }
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 < iVar2);
    }
    uVar6 = uVar6 + 1;
    if (uVar5 <= uVar6) {
      return 1;
    }
    iVar2 = *(int *)(iVar7 + 4);
  } while( true );
}

/* TIntermConstantUnion__fold @ 0x97b91724 (792 bytes) */
int TIntermConstantUnion__fold(this, param_2, param_3, param_4, param_5, param_6, param_7)
  unsigned char * this;
  int param_2;
  unsigned char * param_3;
  void *param_4;
  int param_5;
  undefined4 param_6;
  uint param_7;
{
  bool bVar1;
  undefined *puVar2;
  uint uVar3;
  undefined **ppuVar4;
  float fVar5;
  float fVar6;
  uint uVar7;
  undefined *puVar8;
  unsigned char * pcVar9;
  uint uVar10;
  undefined4 *puVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int *a0;
  uint *puVar15;
  unsigned char * pTVar16;
  int iVar17;
  unsigned char * pTVar18;
  undefined4 uVar19;
  unsigned char * paVar20;
  uint uVar21;
  undefined4 a1;
  undefined4 a1_00;
  undefined4 a1_01;
  undefined4 a1_02;
  undefined4 a1_03;
  undefined4 a1_04;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 a1_05;
  undefined4 a1_06;
  undefined4 a1_07;
  undefined4 extraout_r4_01;
  undefined4 extraout_r4_02;
  undefined4 a1_08;
  undefined4 a1_09;
  undefined4 a1_10;
  undefined4 a1_11;
  undefined4 extraout_r4_03;
  undefined4 extraout_r4_04;
  undefined4 extraout_r4_05;
  undefined4 extraout_r4_06;
  undefined4 extraout_r4_07;
  undefined4 extraout_r4_08;
  undefined4 extraout_r4_09;
  undefined4 extraout_r4_10;
  unsigned char * paVar22;
  undefined4 extraout_r4_11;
  void *a3;
  int iVar23;
  float *pfVar24;
  uint uVar25;
  float *pfVar26;
  unsigned char * pcVar27;
  int iVar28;
  undefined **ppuVar29;
  char *pcVar30;
  bool bVar31;
  char in_RESERVE;
  byte bVar32;
  int iVar33;
  undefined8 uVar34;
  undefined **local_1d0;
  undefined4 local_1cc;
  undefined4 local_1c8;
  undefined4 local_1c4;
  undefined4 local_1c0;
  undefined4 local_1bc;
  undefined4 local_1b8;
  undefined4 local_1b4;
  undefined4 local_1b0;
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
  uint local_4c;
  
  pcVar27 = *(unsigned char **)(this + 0x30);
  if (param_3 == (unsigned char *)0x0) {
    iVar12 = 0;
    iVar17 = (**(code **)(*(int *)this + 0x4c))(this,param_2);
    pTVar16 = (unsigned char *)GetGlobalPoolAllocator();
    pfVar26 = (float *)TPoolAllocator__allocate(pTVar16,iVar17 << 2);
    iVar17 = (**(code **)(*(int *)this + 0x4c))(this);
    if (1 < iVar17) {
      for (; iVar17 = (**(code **)(*(int *)this + 0x4c))(this), iVar12 < iVar17; iVar12 = iVar12 + 1
          ) {
        if (param_2 == 5) {
          (**(code **)(*(int *)this + 0x38))(&local_1d0,this);
          uVar21 = local_1ac >> 0x13 & 0x3f;
          local_1d0 = &PTR___ZN5TTypeD1Ev_a7b7cff8;
          if (uVar21 != 1) {
            if (uVar21 == 2) {
              fVar6 = GH_U2F((unsigned int)(-*(int *)(pcVar27 + iVar12 * 4)));
              goto LAB_97b956a0;
            }
            uVar21 = (*(code *)**(undefined4 **)this)(this);
                    
            goto override_jmp_97b95640_case_0;
          }
          pfVar26[iVar12] = -*(float *)(pcVar27 + iVar12 * 4);
        }
        else {
          if (param_2 != 6) {
            return (unsigned char *)0x0;
          }
          (**(code **)(*(int *)this + 0x38))(&local_1d0,this);
          local_1d0 = &PTR___ZN5TTypeD1Ev_a7b7cff8;
          if ((local_1ac >> 0x13 & 0x3f) != 3) {
            uVar21 = (*(code *)**(undefined4 **)this)(this);
                    
            goto override_jmp_97b95640_case_0;
          }
          fVar6 = GH_U2F((unsigned int)((*(uint *)(pcVar27 + iVar12 * 4) ^ 1)));
LAB_97b956a0:
          pfVar26[iVar12] = fVar6;
        }
        local_1d0 = &PTR___ZN5TTypeD1Ev_a7b7cff8;
      }
      pTVar16 = (unsigned char *)GetGlobalPoolAllocator();
      puVar11 = (undefined4 *)TPoolAllocator__allocate(pTVar16,0x34);
      (**(code **)(*(int *)this + 0x38))(&local_1d0,this);
      uVar34 = CONCAT44(puVar11,extraout_r4_11);
      puVar11[1] = 0;
      *puVar11 = &PTR_getLine_a7b7cf90;
      puVar11[3] = local_1cc;
      puVar11[4] = local_1c8;
      puVar11[5] = local_1c4;
      puVar11[6] = local_1c0;
      puVar11[7] = local_1bc;
      puVar11[8] = local_1b8;
      puVar11[2] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
      puVar11[9] = local_1b4;
      puVar11[10] = local_1b0;
      uVar7 = puVar11[0xb];
      uVar10 = local_1ac & 0xfe000000;
      puVar11[0xb] = uVar10 | uVar7 & 0x1ffffff;
      uVar25 = (local_1ac >> 0x13 & 0x3f) << 0x13;
      puVar11[0xb] = uVar25 | uVar10 | uVar7 & 0x7ffff;
      uVar21 = local_1ac & 0x7f800;
      puVar11[0xb] = uVar21 | uVar25 | uVar10 | uVar7 & 0x7ff;
      uVar3 = (local_1ac >> 10 & 1) << 10;
      puVar11[0xb] = uVar3 | uVar21 | uVar25 | uVar10 | uVar7 & 0x3ff;
      puVar8 = PTR_vtable_a7b7c0c8;
      puVar11[0xb] = (local_1ac >> 9 & 1) << 9 | uVar3 | uVar21 | uVar25 | uVar10 | uVar7 & 0x1ff;
      puVar11[0xc] = pfVar26;
      *puVar11 = puVar8 + 8;
      goto LAB_97b95bbc;
    }
    if (param_2 == 5) {
      (**(code **)(*(int *)this + 0x38))(&local_1d0,this);
      uVar21 = local_1ac >> 0x13 & 0x3f;
      local_1d0 = &PTR___ZN5TTypeD1Ev_a7b7cff8;
      if (uVar21 == 1) {
        *pfVar26 = -**(float **)(this + 0x30);
        pTVar16 = (unsigned char *)GetGlobalPoolAllocator();
        uVar34 = TPoolAllocator__allocate(pTVar16,0x34);
        uVar21 = local_1ac & 0x7ff | 0x4080000;
        goto LAB_97b9597c;
      }
      if (uVar21 == 2) {
        *pfVar26 = GH_U2F((unsigned int)(-**(int **)(this + 0x30)));
        pTVar16 = (unsigned char *)GetGlobalPoolAllocator();
        uVar34 = TPoolAllocator__allocate(pTVar16,0x34);
        iVar17 = 2;
        goto LAB_97b9596c;
      }
      uVar21 = *(uint *)(this + 4);
                    
    }
    else {
      if (param_2 != 6) {
        return (unsigned char *)0x0;
      }
      (**(code **)(*(int *)this + 0x38))(&local_1d0,this);
      local_1d0 = &PTR___ZN5TTypeD1Ev_a7b7cff8;
      if ((local_1ac >> 0x13 & 0x3f) == 3) {
        *pfVar26 = GH_U2F((unsigned int)((**(uint **)(this + 0x30) ^ 1)));
        pTVar16 = (unsigned char *)GetGlobalPoolAllocator();
        uVar34 = TPoolAllocator__allocate(pTVar16,0x34);
        iVar17 = 3;
LAB_97b9596c:
        uVar21 = iVar17 << 0x13 | local_1ac & 0xfff | 0x4000000;
LAB_97b9597c:
        puVar11 = (undefined4 *)((ulonglong)uVar34 >> 0x20);
        local_1ac = uVar21 & 0xfffff9ff | 0x800;
        local_1cc = 0;
        local_1c8 = 0;
        local_1c4 = 0;
        local_1c0 = 0;
        local_1bc = 0;
        local_1b8 = 0;
        local_1b4 = 0;
        local_1b0 = 0;
        puVar11[1] = 0;
        *puVar11 = &PTR_getLine_a7b7cf90;
        puVar11[3] = 0;
        puVar11[4] = 0;
        puVar11[5] = 0;
        puVar11[6] = 0;
        puVar11[7] = 0;
        puVar11[8] = 0;
        puVar11[2] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
        puVar11[9] = 0;
        puVar11[10] = 0;
        uVar25 = puVar11[0xb];
        uVar10 = uVar21 & 0xfe000000;
        puVar11[0xb] = uVar10 | uVar25 & 0x1ffffff;
        uVar21 = (uVar21 >> 0x13 & 0x3f) << 0x13;
        puVar11[0xb] = uVar21 | uVar10 | uVar25 & 0x7ffff;
        puVar11[0xb] = uVar21 | uVar10 | uVar25 & 0x7ff | 0x800;
        puVar11[0xb] = uVar21 | uVar10 | uVar25 & 0x3ff | 0x800;
        puVar8 = PTR_vtable_a7b7c0c8;
        puVar11[0xb] = uVar21 | uVar10 | uVar25 & 0x1ff | 0x800;
        puVar11[0xc] = pfVar26;
        *puVar11 = puVar8 + 8;
LAB_97b95bbc:
        pTVar18 = (unsigned char *)((ulonglong)uVar34 >> 0x20);
        local_1d0 = &PTR___ZN5TTypeD1Ev_a7b7cff8;
        iVar17 = *(int *)pTVar18;
        uVar19 = (*(code *)**(undefined4 **)this)(this,(int)uVar34);
        (**(code **)(iVar17 + 4))(pTVar18,uVar19);
        return pTVar18;
      }
      uVar21 = *(uint *)(this + 4);
                    
    }
override_jmp_97b95640_case_0:
    pcVar30 = "Unary operation not folded into constant";
    __ZN13TInfoSinkBase6appendEPKc(param_4,"INTERNAL ERROR: ");
    uVar10 = uVar21 & 0xffff;
    bVar32 = (uVar10 == 0) << 1;
    if (uVar10 == 0) {
      _sprintf((char *)&local_1c0,"%d:? ",(int)uVar21 >> 0x10);
    }
    else {
      _sprintf((char *)&local_1c0,"%d:%d",(int)uVar21 >> 0x10,uVar10);
    }
    paVar22 = (unsigned char *)&local_1c0;
    __ZNSsC1EPKcRKSaIcE(&local_1d0,(char *)paVar22,(unsigned char *)&local_180);
                    
    *(undefined *)((int)local_1d0 + (int)local_1d0[-3]) = *PTR__S_terminal_a7b7c0b8;
    __ZN13TInfoSinkBase6appendEPKc(param_4,(char *)local_1d0);
    ppuVar29 = local_1d0;
code_r0x97b95b60:
    ppuVar4 = ppuVar29 + -1;
    do {
      puVar8 = *ppuVar4;
                    
      if (in_RESERVE != '\0') {
        puVar2 = (undefined *)storeWordConditionalIndexed(puVar8 + -1,0,ppuVar4);
        *ppuVar4 = puVar2;
        bVar32 = 2;
      }
    } while (!(bool)(bVar32 >> 1 & 1));
joined_r0x97b95b7c:
    if ((int)puVar8 < 1) {
      __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(ppuVar29 + -3),paVar22);
    }
    __ZN13TInfoSinkBase6appendEPKc(param_4,": ");
code_r0x97b95ba0:
    __ZN13TInfoSinkBase6appendEPKc(param_4,pcVar30);
    __ZN13TInfoSinkBase6appendEPKc(param_4,"\n");
switchD_97b94d20_caseD_17:
    return (unsigned char *)0x0;
  }
  bVar31 = false;
  pTVar18 = param_3;
  a3 = param_4;
  iVar17 = param_5;
  iVar12 = (**(code **)(*(int *)param_3 + 0x18))(param_3);
  if ((iVar12 != 0) && (iVar12 = (**(code **)(*(int *)param_3 + 0x4c))(param_3), iVar12 == 1)) {
    (**(code **)(*(int *)param_3 + 0x38))(&local_1d0,param_3);
    if (((local_1ac >> 0x13 & 0x3f) != 0xe) &&
       (iVar12 = (**(code **)(*(int *)this + 0x4c))(this), 1 < iVar12)) {
      bVar31 = true;
    }
    local_4c = 0xa7b81734;
    local_1d0 = &PTR___ZN5TTypeD1Ev_a7b7cff8;
    if (!bVar31) goto LAB_97b92a7c;
    iVar12 = (**(code **)(*(int *)param_3 + 0x18))(param_3);
    uVar21 = param_2 - 0x13;
    if (uVar21 < 0x1a) {
      iVar28 = uVar21 * 4;
      switch(uVar21) {
      case 0:
        local_4c = 0xa7b81734;
        iVar28 = (**(code **)(*(int *)this + 0x4c))(this,uVar21,pTVar18,a3,iVar17,param_6,iVar28);
        pTVar16 = (unsigned char *)GetGlobalPoolAllocator();
        iVar13 = TPoolAllocator__allocate(pTVar16,iVar28 << 2);
        for (iVar28 = 0; iVar14 = (**(code **)(*(int *)this + 0x4c))(this), iVar28 < iVar14;
            iVar28 = iVar28 + 1) {
          (**(code **)(*(int *)this + 0x38))(&local_1a0,this);
          uVar21 = local_17c >> 0x13 & 0x3f;
          local_1a0 = (undefined **)(local_4c - 0x473c);
          if (uVar21 != 1) {
            if (uVar21 == 2) {
              *(int *)(iVar28 * 4 + iVar13) =
                   *(int *)(pcVar27 + iVar28 * 4) + **(int **)(iVar12 + 0x30);
              goto LAB_97b919a8;
            }
            pcVar30 = "Constant folding cannot be done for \"+\"";
            uVar21 = (*(code *)**(undefined4 **)this)(this,a1,pTVar18,a3,iVar17,param_6,local_4c);
                    
override_jmp_97b9198c_case_0:
            __ZN13TInfoSinkBase6appendEPKc(param_4,"INTERNAL ERROR: ");
            uVar10 = uVar21 & 0xffff;
            bVar32 = (uVar10 == 0) << 1;
            if (uVar10 == 0) {
              _sprintf((char *)&local_190,"%d:? ",(int)uVar21 >> 0x10);
            }
            else {
              _sprintf((char *)&local_190,"%d:%d",(int)uVar21 >> 0x10,uVar10);
            }
            paVar22 = (unsigned char *)&local_190;
            __ZNSsC1EPKcRKSaIcE(&local_1a0,(char *)paVar22,(unsigned char *)&local_150);
            *(undefined *)((int)local_1a0 + (int)local_1a0[-3]) = *PTR__S_terminal_a7b7c0b8;
            __ZN13TInfoSinkBase6appendEPKc(param_4,(char *)local_1a0);
            ppuVar29 = local_1a0 + -1;
            paVar20 = (unsigned char *)(local_1a0 + -3);
            do {
              puVar8 = *ppuVar29;
              if (in_RESERVE != '\0') {
                puVar2 = (undefined *)storeWordConditionalIndexed(puVar8 + -1,0,ppuVar29);
                *ppuVar29 = puVar2;
                bVar32 = 2;
              }
            } while (!(bool)(bVar32 >> 1 & 1));
            bVar31 = 0 < (int)puVar8;
            goto code_r0x97b93fb8;
          }
          *(float *)(iVar13 + iVar28 * 4) =
               *(float *)(pcVar27 + iVar28 * 4) + **(float **)(iVar12 + 0x30);
LAB_97b919a8: ;
        }
        break;
      case 1:
        local_4c = 0xa7b81734;
        iVar28 = (**(code **)(*(int *)this + 0x4c))(this);
        pTVar16 = (unsigned char *)GetGlobalPoolAllocator();
        iVar13 = TPoolAllocator__allocate(pTVar16,iVar28 << 2);
        for (iVar28 = 0; iVar14 = (**(code **)(*(int *)this + 0x4c))(this), iVar28 < iVar14;
            iVar28 = iVar28 + 1) {
          (**(code **)(*(int *)this + 0x38))(&local_1a0,this);
          uVar21 = local_17c >> 0x13 & 0x3f;
          local_1a0 = (undefined **)(local_4c - 0x473c);
          if (uVar21 == 1) {
            if (param_5 == 0) {
              fVar6 = *(float *)(pcVar27 + iVar28 * 4);
              fVar5 = **(float **)(iVar12 + 0x30);
            }
            else {
              fVar5 = *(float *)(pcVar27 + iVar28 * 4);
              fVar6 = **(float **)(iVar12 + 0x30);
            }
            *(float *)(iVar13 + iVar28 * 4) = fVar5 - fVar6;
          }
          else {
            if (uVar21 != 2) {
              pcVar30 = "Constant folding cannot be done for \"-\"";
              uVar21 = (*(code *)**(undefined4 **)this)
                                 (this,a1_01,pTVar18,a3,iVar17,param_6,local_4c);
                    
              goto override_jmp_97b9198c_case_0;
            }
            if (param_5 == 0) {
              iVar14 = **(int **)(iVar12 + 0x30) - *(int *)(pcVar27 + iVar28 * 4);
            }
            else {
              iVar14 = *(int *)(pcVar27 + iVar28 * 4) - **(int **)(iVar12 + 0x30);
            }
            *(int *)(iVar28 * 4 + iVar13) = iVar14;
          }
        }
        break;
      default:
        goto switchD_97b91834_caseD_15;
      case 3:
        local_4c = 0xa7b81734;
        iVar17 = (**(code **)(*(int *)this + 0x4c))(this);
        pTVar16 = (unsigned char *)GetGlobalPoolAllocator();
        iVar13 = TPoolAllocator__allocate(pTVar16,iVar17 << 2);
        for (iVar17 = 0; iVar28 = (**(code **)(*(int *)this + 0x4c))(this), iVar17 < iVar28;
            iVar17 = iVar17 + 1) {
          (**(code **)(*(int *)this + 0x38))(&local_1a0,this);
          uVar21 = local_17c >> 0x13 & 0x3f;
          local_1a0 = (undefined **)(local_4c - 0x473c);
          if (uVar21 == 1) {
            if (param_5 == 0) {
              if (*(float *)(pcVar27 + iVar17 * 4) == 0.0) {
                uVar21 = (*(code *)**(undefined4 **)this)(this);
                    
                __ZN13TInfoSinkBase6appendEPKc(param_4,"WARNING: ");
                uVar10 = uVar21 & 0xffff;
                bVar32 = (uVar10 == 0) << 1;
                if (uVar10 == 0) {
                  _sprintf((char *)&local_190,"%d:? ",(int)uVar21 >> 0x10);
                }
                else {
                  _sprintf((char *)&local_190,"%d:%d",(int)uVar21 >> 0x10,uVar10);
                }
                __ZNSsC1EPKcRKSaIcE(&local_1a0,(char *)&local_190,(unsigned char *)&local_150);
                *(undefined *)((int)local_1a0 + (int)local_1a0[-3]) = *PTR__S_terminal_a7b7c0b8;
                __ZN13TInfoSinkBase6appendEPKc(param_4,(char *)local_1a0);
                ppuVar29 = local_1a0 + -1;
                do {
                  puVar8 = *ppuVar29;
                  if (in_RESERVE != '\0') {
                    puVar2 = (undefined *)storeWordConditionalIndexed(puVar8 + -1,0,ppuVar29);
                    *ppuVar29 = puVar2;
                    bVar32 = 2;
                  }
                } while (!(bool)(bVar32 >> 1 & 1));
                if ((int)puVar8 < 1) {
                  __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(local_1a0 + -3),&local_190);
                }
                __ZN13TInfoSinkBase6appendEPKc(param_4,": ");
                __ZN13TInfoSinkBase6appendEPKc
                          (param_4,"Divide by zero error during constant folding");
                __ZN13TInfoSinkBase6appendEPKc(param_4,"\n");
                fVar6 = 3.4028235e+38;
              }
              else {
                fVar6 = **(float **)(iVar12 + 0x30) / *(float *)(pcVar27 + iVar17 * 4);
              }
              *(float *)(iVar17 * 4 + iVar13) = fVar6;
            }
            else {
              if (**(float **)(iVar12 + 0x30) == 0.0) {
                uVar21 = (*(code *)**(undefined4 **)this)(this);
                    
                __ZN13TInfoSinkBase6appendEPKc(param_4,"WARNING: ");
                uVar10 = uVar21 & 0xffff;
                bVar32 = (uVar10 == 0) << 1;
                if (uVar10 == 0) {
                  _sprintf((char *)&local_190,"%d:? ",(int)uVar21 >> 0x10);
                }
                else {
                  _sprintf((char *)&local_190,"%d:%d",(int)uVar21 >> 0x10,uVar10);
                }
                __ZNSsC1EPKcRKSaIcE(&local_1a0,(char *)&local_190,(unsigned char *)&local_150);
                *(undefined *)((int)local_1a0 + (int)local_1a0[-3]) = *PTR__S_terminal_a7b7c0b8;
                __ZN13TInfoSinkBase6appendEPKc(param_4,(char *)local_1a0);
                ppuVar29 = local_1a0 + -1;
                do {
                  puVar8 = *ppuVar29;
                  if (in_RESERVE != '\0') {
                    puVar2 = (undefined *)storeWordConditionalIndexed(puVar8 + -1,0,ppuVar29);
                    *ppuVar29 = puVar2;
                    bVar32 = 2;
                  }
                } while (!(bool)(bVar32 >> 1 & 1));
                if ((int)puVar8 < 1) {
                  __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(local_1a0 + -3),&local_190);
                }
                __ZN13TInfoSinkBase6appendEPKc(param_4,": ");
                __ZN13TInfoSinkBase6appendEPKc
                          (param_4,"Divide by zero error during constant folding");
                __ZN13TInfoSinkBase6appendEPKc(param_4,"\n");
                iVar28 = iVar17 << 2;
                fVar6 = 3.4028235e+38;
              }
              else {
                iVar28 = iVar17 * 4;
                fVar6 = *(float *)(pcVar27 + iVar28) / **(float **)(iVar12 + 0x30);
              }
              *(float *)(iVar13 + iVar28) = fVar6;
            }
          }
          else {
            if (uVar21 != 2) {
              pcVar30 = "Constant folding cannot be done for \"/\"";
              uVar21 = (*(code *)**(undefined4 **)this)(this);
                    
              goto override_jmp_97b9198c_case_0;
            }
            if (param_5 == 0) {
              if (*(int *)(pcVar27 + iVar17 * 4) == 0) {
                uVar21 = (*(code *)**(undefined4 **)this)(this);
                    
                __ZN13TInfoSinkBase6appendEPKc(param_4,"WARNING: ");
                uVar10 = uVar21 & 0xffff;
                bVar32 = (uVar10 == 0) << 1;
                if (uVar10 == 0) {
                  _sprintf((char *)&local_190,"%d:? ",(int)uVar21 >> 0x10);
                }
                else {
                  _sprintf((char *)&local_190,"%d:%d",(int)uVar21 >> 0x10,uVar10);
                }
                __ZNSsC1EPKcRKSaIcE(&local_1a0,(char *)&local_190,(unsigned char *)&local_150);
                *(undefined *)((int)local_1a0 + (int)local_1a0[-3]) = *PTR__S_terminal_a7b7c0b8;
                __ZN13TInfoSinkBase6appendEPKc(param_4,(char *)local_1a0);
                ppuVar29 = local_1a0 + -1;
                do {
                  puVar8 = *ppuVar29;
                  if (in_RESERVE != '\0') {
                    puVar2 = (undefined *)storeWordConditionalIndexed(puVar8 + -1,0,ppuVar29);
                    *ppuVar29 = puVar2;
                    bVar32 = 2;
                  }
                } while (!(bool)(bVar32 >> 1 & 1));
                if ((int)puVar8 < 1) {
                  __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(local_1a0 + -3),&local_190);
                }
                __ZN13TInfoSinkBase6appendEPKc(param_4,": ");
                __ZN13TInfoSinkBase6appendEPKc
                          (param_4,"Divide by zero error during constant folding");
                __ZN13TInfoSinkBase6appendEPKc(param_4,"\n");
                iVar28 = 0x7fffffff;
              }
              else {
                iVar28 = **(int **)(iVar12 + 0x30) / *(int *)(pcVar27 + iVar17 * 4);
              }
              *(int *)(iVar17 * 4 + iVar13) = iVar28;
            }
            else {
              if (**(int **)(iVar12 + 0x30) == 0) {
                uVar21 = (*(code *)**(undefined4 **)this)(this);
                    
                __ZN13TInfoSinkBase6appendEPKc(param_4,"WARNING: ");
                uVar10 = uVar21 & 0xffff;
                bVar32 = (uVar10 == 0) << 1;
                if (uVar10 == 0) {
                  _sprintf((char *)&local_190,"%d:? ",(int)uVar21 >> 0x10);
                }
                else {
                  _sprintf((char *)&local_190,"%d:%d",(int)uVar21 >> 0x10,uVar10);
                }
                __ZNSsC1EPKcRKSaIcE(&local_1a0,(char *)&local_190,(unsigned char *)&local_150);
                *(undefined *)((int)local_1a0 + (int)local_1a0[-3]) = *PTR__S_terminal_a7b7c0b8;
                __ZN13TInfoSinkBase6appendEPKc(param_4,(char *)local_1a0);
                ppuVar29 = local_1a0 + -1;
                do {
                  puVar8 = *ppuVar29;
                  if (in_RESERVE != '\0') {
                    puVar2 = (undefined *)storeWordConditionalIndexed(puVar8 + -1,0,ppuVar29);
                    *ppuVar29 = puVar2;
                    bVar32 = 2;
                  }
                } while (!(bool)(bVar32 >> 1 & 1));
                if ((int)puVar8 < 1) {
                  __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(local_1a0 + -3),&local_190);
                }
                __ZN13TInfoSinkBase6appendEPKc(param_4,": ");
                __ZN13TInfoSinkBase6appendEPKc
                          (param_4,"Divide by zero error during constant folding");
                __ZN13TInfoSinkBase6appendEPKc(param_4,"\n");
                iVar14 = 0x7fffffff;
                iVar28 = iVar17 << 2;
              }
              else {
                iVar28 = iVar17 * 4;
                iVar14 = *(int *)(pcVar27 + iVar28) / **(int **)(iVar12 + 0x30);
              }
              *(int *)(iVar28 + iVar13) = iVar14;
            }
          }
        }
        break;
      case 0x13:
      case 0x16:
        local_4c = 0xa7b81734;
        iVar28 = (**(code **)(*(int *)this + 0x4c))(this);
        pTVar16 = (unsigned char *)GetGlobalPoolAllocator();
        uVar34 = TPoolAllocator__allocate(pTVar16,iVar28 << 2);
        iVar13 = (int)((ulonglong)uVar34 >> 0x20);
        uVar19 = (undefined4)uVar34;
        for (iVar28 = 0; iVar14 = (**(code **)(*(int *)this + 0x4c))(this,uVar19), iVar28 < iVar14;
            iVar28 = iVar28 + 1) {
          (**(code **)(*(int *)this + 0x38))(&local_1a0,this);
          uVar21 = local_17c >> 0x13 & 0x3f;
          local_1a0 = (undefined **)(local_4c - 0x473c);
          if (uVar21 == 1) {
            *(float *)(iVar13 + iVar28 * 4) =
                 *(float *)(pcVar27 + iVar28 * 4) * **(float **)(iVar12 + 0x30);
          }
          else {
            if (uVar21 != 2) {
              pcVar30 = "Constant folding cannot be done for \"*\"";
              uVar21 = (*(code *)**(undefined4 **)this)
                                 (this,a1_00,pTVar18,a3,iVar17,param_6,local_4c);
                    
              __ZN13TInfoSinkBase6appendEPKc(param_4,"INTERNAL ERROR: ");
              uVar10 = uVar21 & 0xffff;
              bVar32 = (uVar10 == 0) << 1;
              if (uVar10 == 0) {
                _sprintf((char *)local_140,"%d:? ",(int)uVar21 >> 0x10);
              }
              else {
                _sprintf((char *)local_140,"%d:%d",(int)uVar21 >> 0x10,uVar10);
              }
              paVar22 = (unsigned char *)&local_190;
              __ZNSsC1EPKcRKSaIcE(&local_1a0,(char *)local_140,paVar22);
              *(undefined *)((int)local_1a0 + (int)local_1a0[-3]) = *PTR__S_terminal_a7b7c0b8;
              __ZN13TInfoSinkBase6appendEPKc(param_4,(char *)local_1a0);
              ppuVar29 = local_1a0;
              goto code_r0x97b932f0;
            }
            *(int *)(iVar28 * 4 + iVar13) =
                 *(int *)(pcVar27 + iVar28 * 4) * **(int **)(iVar12 + 0x30);
          }
          uVar19 = a1_00;
        }
        break;
      case 0x17:
        local_4c = 0xa7b81734;
        iVar28 = (**(code **)(*(int *)this + 0x4c))(this);
        pTVar16 = (unsigned char *)GetGlobalPoolAllocator();
        uVar34 = TPoolAllocator__allocate(pTVar16,iVar28 << 2);
        iVar13 = (int)((ulonglong)uVar34 >> 0x20);
        uVar19 = (undefined4)uVar34;
        for (iVar28 = 0; iVar14 = (**(code **)(*(int *)this + 0x4c))(this,uVar19), iVar28 < iVar14;
            iVar28 = iVar28 + 1) {
          (**(code **)(*(int *)this + 0x38))(&local_1a0,this);
          local_1a0 = (undefined **)(local_4c - 0x473c);
          if ((local_17c >> 0x13 & 0x3f) != 3) {
            pcVar30 = "Constant folding cannot be done for \"||\"";
            uVar21 = (*(code *)**(undefined4 **)this)(this,a1_04,pTVar18,a3,iVar17,param_6,local_4c)
            ;
                    
            goto override_jmp_97b9198c_case_0;
          }
          uVar19 = 0;
          if ((*(int *)(pcVar27 + iVar28 * 4) != 0) || (**(int **)(iVar12 + 0x30) != 0)) {
            uVar19 = 1;
          }
          *(undefined4 *)(iVar28 * 4 + iVar13) = uVar19;
          uVar19 = a1_04;
        }
        break;
      case 0x18:
        local_4c = 0xa7b81734;
        iVar13 = (**(code **)(*(int *)this + 0x4c))(this);
        pTVar16 = (unsigned char *)GetGlobalPoolAllocator();
        uVar34 = TPoolAllocator__allocate(pTVar16,iVar13 << 2);
        iVar13 = (int)((ulonglong)uVar34 >> 0x20);
        uVar19 = (undefined4)uVar34;
        for (iVar14 = 0;
            iVar28 = (**(code **)(*(int *)this + 0x4c))
                               (this,uVar19,pTVar18,a3,iVar17,param_6,iVar28), iVar14 < iVar28;
            iVar14 = iVar14 + 1) {
          (**(code **)(*(int *)this + 0x38))(&local_1a0,this);
          local_1a0 = (undefined **)(local_4c - 0x473c);
          if ((local_17c >> 0x13 & 0x3f) != 3) {
            pcVar30 = "Constant folding cannot be done for \"^^\"";
            uVar21 = (*(code *)**(undefined4 **)this)(this,a1_03,pTVar18,a3,iVar17,param_6,local_4c)
            ;
                    
            goto override_jmp_97b9198c_case_0;
          }
          uVar21 = *(uint *)(pcVar27 + iVar14 * 4) ^ **(uint **)(iVar12 + 0x30);
          iVar28 = uVar21 - 1;
          *(uint *)(iVar14 * 4 + iVar13) = uVar21 - (iVar28 + (uint)(uVar21 == 0));
          uVar19 = a1_03;
        }
        break;
      case 0x19:
        local_4c = 0xa7b81734;
        iVar28 = (**(code **)(*(int *)this + 0x4c))(this,uVar21);
        pTVar16 = (unsigned char *)GetGlobalPoolAllocator();
        iVar13 = TPoolAllocator__allocate(pTVar16,iVar28 << 2);
        for (iVar28 = 0; iVar14 = (**(code **)(*(int *)this + 0x4c))(this), iVar28 < iVar14;
            iVar28 = iVar28 + 1) {
          (**(code **)(*(int *)this + 0x38))(&local_1a0,this);
          local_1a0 = (undefined **)(local_4c - 0x473c);
          if ((local_17c >> 0x13 & 0x3f) != 3) {
            pcVar30 = "Constant folding cannot be done for \"&&\"";
            uVar21 = (*(code *)**(undefined4 **)this)(this,a1_02,pTVar18,a3,iVar17,param_6,local_4c)
            ;
                    
            goto override_jmp_97b9198c_case_0;
          }
          uVar19 = 0;
          if ((*(int *)(pcVar27 + iVar28 * 4) != 0) && (**(int **)(iVar12 + 0x30) != 0)) {
            uVar19 = 1;
          }
          *(undefined4 *)(iVar28 * 4 + iVar13) = uVar19;
        }
      }
      pTVar16 = (unsigned char *)GetGlobalPoolAllocator();
      pTVar18 = (unsigned char *)TPoolAllocator__allocate(pTVar16,0x34);
      (**(code **)(*(int *)this + 0x38))(&local_1a0,this);
      *(int *)(pTVar18 + 4) = 0;
      *(undefined ***)pTVar18 = &PTR_getLine_a7b7cf90;
      *(int *)(pTVar18 + 0xc) = local_19c;
      local_1a0 = (undefined **)(local_4c - 0x473c);
      *(int *)(pTVar18 + 0x10) = local_198;
      *(int *)(pTVar18 + 0x14) = local_194;
      *(int *)(pTVar18 + 0x18) = local_190;
      *(int *)(pTVar18 + 0x1c) = local_18c;
      *(int *)(pTVar18 + 0x20) = local_188;
      *(undefined ***)(pTVar18 + 8) = local_1a0;
      *(int *)(pTVar18 + 0x24) = local_184;
      *(int *)(pTVar18 + 0x28) = local_180;
      uVar7 = *(uint *)(pTVar18 + 0x2c);
      uVar10 = local_17c & 0xfe000000;
      *(uint *)(pTVar18 + 0x2c) = uVar10 | uVar7 & 0x1ffffff;
      uVar25 = (local_17c >> 0x13 & 0x3f) << 0x13;
      *(uint *)(pTVar18 + 0x2c) = uVar25 | uVar10 | uVar7 & 0x7ffff;
      uVar21 = local_17c & 0x7f800;
      *(uint *)(pTVar18 + 0x2c) = uVar21 | uVar25 | uVar10 | uVar7 & 0x7ff;
      uVar3 = (local_17c >> 10 & 1) << 10;
      *(uint *)(pTVar18 + 0x2c) = uVar3 | uVar21 | uVar25 | uVar10 | uVar7 & 0x3ff;
      puVar8 = PTR_vtable_a7b7c0c8;
      *(uint *)(pTVar18 + 0x2c) =
           (local_17c >> 9 & 1) << 9 | uVar3 | uVar21 | uVar25 | uVar10 | uVar7 & 0x1ff;
      *(undefined **)pTVar18 = puVar8 + 8;
      *(int *)(pTVar18 + 0x30) = iVar13;
      goto LAB_97b94758;
    }
switchD_97b91834_caseD_15:
    pcVar30 = "Invalid operator for constant folding";
    uVar21 = (*(code *)**(undefined4 **)this)(this);
                    
    __ZN13TInfoSinkBase6appendEPKc(param_4,"INTERNAL ERROR: ");
    uVar10 = uVar21 & 0xffff;
    bVar32 = (uVar10 == 0) << 1;
    if (uVar10 == 0) {
      _sprintf((char *)&local_190,"%d:? ",(int)uVar21 >> 0x10);
    }
    else {
      _sprintf((char *)&local_190,"%d:%d",(int)uVar21 >> 0x10,uVar10);
    }
    paVar22 = (unsigned char *)&local_190;
    __ZNSsC1EPKcRKSaIcE(&local_1a0,(char *)paVar22,(unsigned char *)&local_150);
    *(undefined *)((int)local_1a0 + (int)local_1a0[-3]) = *PTR__S_terminal_a7b7c0b8;
    __ZN13TInfoSinkBase6appendEPKc(param_4,(char *)local_1a0);
    ppuVar4 = local_1a0 + -1;
    do {
      puVar8 = *ppuVar4;
      if (in_RESERVE != '\0') {
        puVar2 = (undefined *)storeWordConditionalIndexed(puVar8 + -1,0,ppuVar4);
        *ppuVar4 = puVar2;
        bVar32 = 2;
      }
      ppuVar29 = local_1a0;
    } while (!(bool)(bVar32 >> 1 & 1));
    goto joined_r0x97b95b7c;
  }
LAB_97b92a7c:
  iVar12 = (**(code **)(*(int *)param_3 + 0x18))(param_3);
  if (iVar12 != 0) {
    iVar12 = (**(code **)(*(int *)this + 0x4c))(this);
    uVar19 = extraout_r4;
    if (iVar12 < 2) {
      local_4c = 0xa7b81734;
      (**(code **)(*(int *)this + 0x38))(&local_1a0,this);
      local_1a0 = (undefined **)(local_4c - 0x473c);
      uVar19 = extraout_r4_00;
      param_7 = local_4c;
      if ((local_17c >> 0x13 & 0x3f) != 0xe) goto LAB_97b9478c;
    }
    iVar12 = 0;
    bVar31 = false;
    a0 = (int *)(**(code **)(*(int *)param_3 + 0x18))
                          (param_3,uVar19,pTVar18,a3,iVar17,param_6,param_7);
    uVar21 = param_2 - 0x13;
    pfVar26 = (float *)a0[0xc];
    local_50 = 0;
    if (0x43 < uVar21) {
switchD_97b92b40_caseD_17:
      pcVar30 = "Invalid operator for constant folding";
      uVar21 = (*(code *)**(undefined4 **)this)(this);
                    
override_jmp_97b938f4_case_0:
      __ZN13TInfoSinkBase6appendEPKc(param_4,"INTERNAL ERROR: ");
      uVar10 = uVar21 & 0xffff;
      bVar32 = (uVar10 == 0) << 1;
      if (uVar10 == 0) {
        _sprintf((char *)&local_160,"%d:? ",(int)uVar21 >> 0x10);
      }
      else {
        _sprintf((char *)&local_160,"%d:%d",(int)uVar21 >> 0x10,uVar10);
      }
code_r0x97b945f4:
      __ZNSsC1EPKcRKSaIcE(&local_170,(char *)&local_160,aaStack_120);
      *(undefined *)((int)local_170 + (int)local_170[-3]) = *PTR__S_terminal_a7b7c0b8;
      __ZN13TInfoSinkBase6appendEPKc(param_4,(char *)local_170);
      ppuVar29 = local_170 + -1;
      do {
        puVar8 = *ppuVar29;
        if (in_RESERVE != '\0') {
          puVar2 = (undefined *)storeWordConditionalIndexed(puVar8 + -1,0,ppuVar29);
          *ppuVar29 = puVar2;
          bVar32 = 2;
        }
      } while (!(bool)(bVar32 >> 1 & 1));
      paVar22 = (unsigned char *)&local_160;
      ppuVar29 = local_170;
      goto joined_r0x97b95b7c;
    }
    iVar28 = uVar21 * 4;
    switch(uVar21) {
    case 0:
      local_4c = 0xa7b81734;
      iVar12 = (**(code **)(*(int *)this + 0x4c))(this,uVar21,pTVar18,a3,iVar17,param_6,iVar28);
      pTVar16 = (unsigned char *)GetGlobalPoolAllocator();
      uVar34 = TPoolAllocator__allocate(pTVar16,iVar12 << 2);
      iVar12 = (int)((ulonglong)uVar34 >> 0x20);
      uVar19 = (undefined4)uVar34;
      for (iVar28 = 0; iVar13 = (**(code **)(*(int *)this + 0x4c))(this,uVar19), iVar28 < iVar13;
          iVar28 = iVar28 + 1) {
        (**(code **)(*(int *)this + 0x38))(&local_170,this);
        uVar21 = local_14c >> 0x13 & 0x3f;
        local_170 = (undefined **)(local_4c - 0x473c);
        if (uVar21 != 1) {
          if (uVar21 == 2) {
            *(int *)(iVar12 + iVar28 * 4) = *(int *)(pcVar27 + iVar28 * 4) + (int)GH_F2U(pfVar26[iVar28]);
            goto LAB_97b92dd4;
          }
          pcVar30 = "Constant folding cannot be done for \"+\"";
          uVar21 = (*(code *)**(undefined4 **)this)(this,a1_05,pTVar18,a3,iVar17,param_6,local_4c);
                    
          __ZN13TInfoSinkBase6appendEPKc(param_4,"INTERNAL ERROR: ");
          uVar10 = uVar21 & 0xffff;
          bVar32 = (uVar10 == 0) << 1;
          if (uVar10 == 0) {
            _sprintf((char *)&local_160,"%d:? ",(int)uVar21 >> 0x10);
          }
          else {
            _sprintf((char *)&local_160,"%d:%d",(int)uVar21 >> 0x10,uVar10);
          }
          paVar22 = (unsigned char *)&local_100;
code_r0x97b93f6c:
          __ZNSsC1EPKcRKSaIcE(&local_170,(char *)&local_160,paVar22);
          *(undefined *)((int)local_170 + (int)local_170[-3]) = *PTR__S_terminal_a7b7c0b8;
          __ZN13TInfoSinkBase6appendEPKc(param_4,(char *)local_170);
          ppuVar29 = local_170 + -1;
          paVar20 = (unsigned char *)(local_170 + -3);
          do {
            puVar8 = *ppuVar29;
            if (in_RESERVE != '\0') {
              puVar2 = (undefined *)storeWordConditionalIndexed(puVar8 + -1,0,ppuVar29);
              *ppuVar29 = puVar2;
              bVar32 = 2;
            }
          } while (!(bool)(bVar32 >> 1 & 1));
          bVar31 = 0 < (int)puVar8;
          paVar22 = (unsigned char *)&local_160;
          goto code_r0x97b93fb8;
        }
        *(float *)(iVar12 + iVar28 * 4) = *(float *)(pcVar27 + iVar28 * 4) + pfVar26[iVar28];
LAB_97b92dd4:
        uVar19 = a1_05;
      }
      break;
    case 1:
      local_4c = 0xa7b81734;
      iVar12 = (**(code **)(*(int *)this + 0x4c))(this);
      pTVar16 = (unsigned char *)GetGlobalPoolAllocator();
      uVar34 = TPoolAllocator__allocate(pTVar16,iVar12 << 2);
      iVar12 = (int)((ulonglong)uVar34 >> 0x20);
      uVar19 = (undefined4)uVar34;
      for (iVar28 = 0; iVar13 = (**(code **)(*(int *)this + 0x4c))(this,uVar19), iVar28 < iVar13;
          iVar28 = iVar28 + 1) {
        (**(code **)(*(int *)this + 0x38))(&local_170,this);
        uVar21 = local_14c >> 0x13 & 0x3f;
        local_170 = (undefined **)(local_4c - 0x473c);
        if (uVar21 == 1) {
          if (param_5 == 0) {
            fVar6 = pfVar26[iVar28];
            fVar5 = *(float *)(pcVar27 + iVar28 * 4);
          }
          else {
            fVar6 = *(float *)(pcVar27 + iVar28 * 4);
            fVar5 = pfVar26[iVar28];
          }
          *(float *)(iVar12 + iVar28 * 4) = fVar6 - fVar5;
        }
        else {
          if (uVar21 != 2) {
            pcVar30 = "Constant folding cannot be done for \"-\"";
            uVar21 = (*(code *)**(undefined4 **)this)(this,a1_06,pTVar18,a3,iVar17,param_6,local_4c)
            ;
                    
            __ZN13TInfoSinkBase6appendEPKc(param_4,"INTERNAL ERROR: ");
            uVar10 = uVar21 & 0xffff;
            bVar32 = (uVar10 == 0) << 1;
            if (uVar10 == 0) {
              _sprintf((char *)&local_160,"%d:? ",(int)uVar21 >> 0x10);
            }
            else {
              _sprintf((char *)&local_160,"%d:%d",(int)uVar21 >> 0x10,uVar10);
            }
            paVar22 = (unsigned char *)&local_f0;
            goto code_r0x97b93f6c;
          }
          if (param_5 == 0) {
            fVar6 = pfVar26[iVar28];
            fVar5 = *(float *)(pcVar27 + iVar28 * 4);
          }
          else {
            fVar6 = *(float *)(pcVar27 + iVar28 * 4);
            fVar5 = pfVar26[iVar28];
          }
          *(int *)(iVar12 + iVar28 * 4) = (int)GH_F2U(fVar6) - (int)GH_F2U(fVar5);
        }
        uVar19 = a1_06;
      }
      break;
    case 2:
      iVar28 = (**(code **)(*(int *)this + 0x58))(this);
      if (iVar28 != 0) {
        iVar13 = 0;
        iVar28 = (**(code **)(*(int *)this + 0x4c))(this);
        pTVar16 = (unsigned char *)GetGlobalPoolAllocator();
        iVar12 = TPoolAllocator__allocate(pTVar16,iVar28 << 2);
        if (0 < iVar28) {
          local_4c = 0xa7b81734;
          do {
            (**(code **)(*(int *)this + 0x38))(&local_170,this);
            uVar21 = local_14c >> 0x13 & 0x3f;
            local_170 = (undefined **)(local_4c - 0x473c);
            if (uVar21 == 1) {
              *(float *)(iVar12 + iVar13 * 4) = *(float *)(pcVar27 + iVar13 * 4) * pfVar26[iVar13];
            }
            else {
              if (uVar21 != 2) {
                pcVar30 = "Constant folding cannot be done for vector multiply";
                uVar21 = (*(code *)**(undefined4 **)this)
                                   (this,a1_07,pTVar18,a3,iVar17,param_6,local_4c);
                    
                __ZN13TInfoSinkBase6appendEPKc(param_4,"INTERNAL ERROR: ");
                uVar10 = uVar21 & 0xffff;
                bVar32 = (uVar10 == 0) << 1;
                if (uVar10 == 0) {
                  _sprintf((char *)&local_160,"%d:? ",(int)uVar21 >> 0x10);
                }
                else {
                  _sprintf((char *)&local_160,"%d:%d",(int)uVar21 >> 0x10,uVar10);
                }
                paVar22 = aaStack_e0;
                goto code_r0x97b93f6c;
              }
              *(int *)(iVar12 + iVar13 * 4) = *(int *)(pcVar27 + iVar13 * 4) * (int)GH_F2U(pfVar26[iVar13]);
            }
            iVar13 = iVar13 + 1;
          } while (iVar13 < iVar28);
          break;
        }
      }
      local_4c = 0xa7b81734;
      break;
    case 3:
      local_4c = 0xa7b81734;
      iVar17 = (**(code **)(*(int *)this + 0x4c))(this);
      pTVar16 = (unsigned char *)GetGlobalPoolAllocator();
      iVar12 = TPoolAllocator__allocate(pTVar16,iVar17 << 2);
      for (iVar17 = 0; iVar28 = (**(code **)(*(int *)this + 0x4c))(this), iVar17 < iVar28;
          iVar17 = iVar17 + 1) {
        (**(code **)(*(int *)this + 0x38))(&local_170,this);
        uVar21 = local_14c >> 0x13 & 0x3f;
        local_170 = (undefined **)(local_4c - 0x473c);
        if (uVar21 != 1) {
          if (uVar21 == 2) {
            if (param_5 == 0) {
              fVar6 = *(float *)(pcVar27 + iVar17 * 4);
              if (fVar6 == 0.0) {
                uVar21 = (*(code *)**(undefined4 **)this)(this);
                    
                goto override_jmp_97b93698_case_0;
              }
              fVar5 = pfVar26[iVar17];
code_r0x97b93828:
              iVar28 = (int)GH_F2U(fVar5) / (int)GH_F2U(fVar6);
            }
            else {
              fVar6 = pfVar26[iVar17];
              if (fVar6 != 0.0) {
                fVar5 = *(float *)(pcVar27 + iVar17 * 4);
                goto code_r0x97b93828;
              }
              uVar21 = (*(code *)**(undefined4 **)this)(this);
                    
override_jmp_97b93698_case_0:
              __ZN13TInfoSinkBase6appendEPKc(param_4,"WARNING: ");
              uVar10 = uVar21 & 0xffff;
              bVar32 = (uVar10 == 0) << 1;
              if (uVar10 == 0) {
                _sprintf((char *)&local_160,"%d:? ",(int)uVar21 >> 0x10);
              }
              else {
                _sprintf((char *)&local_160,"%d:%d",(int)uVar21 >> 0x10,uVar10);
              }
              __ZNSsC1EPKcRKSaIcE(&local_170,(char *)&local_160,aaStack_120);
              *(undefined *)((int)local_170 + (int)local_170[-3]) = *PTR__S_terminal_a7b7c0b8;
              __ZN13TInfoSinkBase6appendEPKc(param_4,(char *)local_170);
              ppuVar29 = local_170 + -1;
              do {
                puVar8 = *ppuVar29;
                if (in_RESERVE != '\0') {
                  puVar2 = (undefined *)storeWordConditionalIndexed(puVar8 + -1,0,ppuVar29);
                  *ppuVar29 = puVar2;
                  bVar32 = 2;
                }
              } while (!(bool)(bVar32 >> 1 & 1));
              if ((int)puVar8 < 1) {
                __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(local_170 + -3),&local_160);
              }
              __ZN13TInfoSinkBase6appendEPKc(param_4,": ");
              __ZN13TInfoSinkBase6appendEPKc(param_4,"Divide by zero error during constant folding")
              ;
              __ZN13TInfoSinkBase6appendEPKc(param_4,"\n");
              iVar28 = 0x7fffffff;
            }
            *(int *)(iVar17 * 4 + iVar12) = iVar28;
            goto code_r0x97b93884;
          }
          pcVar30 = "Constant folding cannot be done for \"/\"";
          uVar21 = (*(code *)**(undefined4 **)this)(this);
                    
override_jmp_97b93868_case_0:
          __ZN13TInfoSinkBase6appendEPKc(param_4,"INTERNAL ERROR: ");
          uVar10 = uVar21 & 0xffff;
          bVar32 = (uVar10 == 0) << 1;
          if (uVar10 == 0) {
            _sprintf((char *)&local_160,"%d:? ",(int)uVar21 >> 0x10);
          }
          else {
            _sprintf((char *)&local_160,"%d:%d",(int)uVar21 >> 0x10,uVar10);
          }
          paVar22 = aaStack_120;
          goto code_r0x97b93f6c;
        }
        if (param_5 == 0) {
          fVar6 = *(float *)(pcVar27 + iVar17 * 4);
          if (fVar6 == 0.0) {
            uVar21 = (*(code *)**(undefined4 **)this)(this);
                    
            goto override_jmp_97b934a8_case_0;
          }
          fVar5 = pfVar26[iVar17];
code_r0x97b93640:
          fVar5 = fVar5 / fVar6;
        }
        else {
          fVar6 = pfVar26[iVar17];
          if (fVar6 != 0.0) {
            fVar5 = *(float *)(pcVar27 + iVar17 * 4);
            goto code_r0x97b93640;
          }
          uVar21 = (*(code *)**(undefined4 **)this)(this);
                    
override_jmp_97b934a8_case_0:
          __ZN13TInfoSinkBase6appendEPKc(param_4,"WARNING: ");
          uVar10 = uVar21 & 0xffff;
          bVar32 = (uVar10 == 0) << 1;
          if (uVar10 == 0) {
            _sprintf((char *)&local_160,"%d:? ",(int)uVar21 >> 0x10);
          }
          else {
            _sprintf((char *)&local_160,"%d:%d",(int)uVar21 >> 0x10,uVar10);
          }
          __ZNSsC1EPKcRKSaIcE(&local_170,(char *)&local_160,aaStack_120);
          *(undefined *)((int)local_170 + (int)local_170[-3]) = *PTR__S_terminal_a7b7c0b8;
          __ZN13TInfoSinkBase6appendEPKc(param_4,(char *)local_170);
          ppuVar29 = local_170 + -1;
          do {
            puVar8 = *ppuVar29;
            if (in_RESERVE != '\0') {
              puVar2 = (undefined *)storeWordConditionalIndexed(puVar8 + -1,0,ppuVar29);
              *ppuVar29 = puVar2;
              bVar32 = 2;
            }
          } while (!(bool)(bVar32 >> 1 & 1));
          if ((int)puVar8 < 1) {
            __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(local_170 + -3),&local_160);
          }
          __ZN13TInfoSinkBase6appendEPKc(param_4,": ");
          __ZN13TInfoSinkBase6appendEPKc(param_4,"Divide by zero error during constant folding");
          __ZN13TInfoSinkBase6appendEPKc(param_4,"\n");
          fVar5 = 3.4028235e+38;
        }
        *(float *)(iVar17 * 4 + iVar12) = fVar5;
code_r0x97b93884: ;
      }
      break;
    default:
      goto switchD_97b92b40_caseD_17;
    case 10:
      local_4c = 0xa7b81734;
      (**(code **)(*(int *)this + 0x38))((unsigned char *)&local_170,this);
      uVar21 = local_14c >> 0x13 & 0x3f;
      ppuVar29 = (undefined **)(local_4c - 0x473c);
      local_170 = ppuVar29;
      if (uVar21 == 2) {
        uVar19 = extraout_r4_03;
        fVar6 = GH_U2F((unsigned int)(local_4c));
        for (iVar12 = 0;
            iVar28 = (**(code **)(*(int *)this + 0x4c))(this,uVar19,pTVar18,a3,iVar17,param_6,fVar6)
            , iVar12 < iVar28; iVar12 = iVar12 + 1) {
          fVar6 = pfVar26[iVar12];
          if (*(float *)(pcVar27 + iVar12 * 4) != fVar6) goto LAB_97b94304;
          uVar19 = extraout_r4_05;
        }
        goto LAB_97b943d4;
      }
      if (2 < uVar21) {
        if (uVar21 == 3) {
          uVar19 = extraout_r4_03;
          fVar6 = GH_U2F((unsigned int)(local_4c));
          for (iVar12 = 0;
              iVar28 = (**(code **)(*(int *)this + 0x4c))
                                 (this,uVar19,pTVar18,a3,iVar17,param_6,fVar6), iVar12 < iVar28;
              iVar12 = iVar12 + 1) {
            fVar6 = pfVar26[iVar12];
            if (*(float *)(pcVar27 + iVar12 * 4) != fVar6) goto LAB_97b94304;
            uVar19 = extraout_r4_06;
          }
        }
        else {
          if (uVar21 != 0xe) goto LAB_97b9414c;
          pcVar9 = (unsigned char *)a0[0xc];
          (**(code **)(*a0 + 0x38))((unsigned char *)&local_170,a0);
          iVar17 = ((int (*)())compareStructure)((unsigned char *)&local_170,pcVar9,pcVar27,&local_50);
          bVar1 = iVar17 == 1;
LAB_97b942fc:
          local_170 = ppuVar29;
          if (!bVar1) {
LAB_97b94304:
            bVar31 = true;
          }
        }
        goto LAB_97b943d4;
      }
      if (uVar21 == 1) {
        uVar19 = extraout_r4_03;
        uVar21 = local_4c;
        for (iVar12 = 0;
            iVar28 = (**(code **)(*(int *)this + 0x4c))
                               (this,uVar19,pTVar18,a3,iVar17,param_6,uVar21), iVar12 < iVar28;
            iVar12 = iVar12 + 1) {
          if (*(float *)(pcVar27 + iVar12 * 4) != pfVar26[iVar12]) goto LAB_97b94304;
          uVar19 = extraout_r4_04;
        }
        goto LAB_97b943d4;
      }
LAB_97b9414c:
      pcVar30 = "Constant folding cannot be done for \"==\"";
      uVar21 = (*(code *)**(undefined4 **)this)(this);
                    
override_jmp_97b94180_case_0:
      __ZN13TInfoSinkBase6appendEPKc(param_4,"INTERNAL ERROR: ");
      uVar10 = uVar21 & 0xffff;
      bVar32 = (uVar10 == 0) << 1;
      if (uVar10 == 0) {
        _sprintf((char *)&local_160,"%d:? ",(int)uVar21 >> 0x10);
      }
      else {
        _sprintf((char *)&local_160,"%d:%d",(int)uVar21 >> 0x10,uVar10);
      }
      goto code_r0x97b945f4;
    case 0xb:
      local_4c = 0xa7b81734;
      (**(code **)(*(int *)this + 0x38))((unsigned char *)&local_170,this);
      uVar21 = local_14c >> 0x13 & 0x3f;
      ppuVar29 = (undefined **)(local_4c - 0x473c);
      local_170 = ppuVar29;
      if (uVar21 == 2) {
        uVar19 = extraout_r4_07;
        fVar6 = GH_U2F((unsigned int)(local_4c));
        for (iVar12 = 0;
            iVar28 = (**(code **)(*(int *)this + 0x4c))(this,uVar19,pTVar18,a3,iVar17,param_6,fVar6)
            , iVar12 < iVar28; iVar12 = iVar12 + 1) {
          fVar6 = pfVar26[iVar12];
          if (*(float *)(pcVar27 + iVar12 * 4) == fVar6) goto LAB_97b94304;
          uVar19 = extraout_r4_09;
        }
      }
      else if (uVar21 < 3) {
        if (uVar21 != 1) {
LAB_97b9430c:
          pcVar30 = "Constant folding cannot be done for \"!=\"";
          uVar21 = (*(code *)**(undefined4 **)this)(this);
                    
          goto override_jmp_97b94180_case_0;
        }
        uVar19 = extraout_r4_07;
        uVar21 = local_4c;
        for (iVar12 = 0;
            iVar28 = (**(code **)(*(int *)this + 0x4c))
                               (this,uVar19,pTVar18,a3,iVar17,param_6,uVar21), iVar12 < iVar28;
            iVar12 = iVar12 + 1) {
          if (*(float *)(pcVar27 + iVar12 * 4) == pfVar26[iVar12]) goto LAB_97b94304;
          uVar19 = extraout_r4_08;
        }
      }
      else {
        if (uVar21 != 3) {
          if (uVar21 == 0xe) {
            pcVar9 = (unsigned char *)a0[0xc];
            (**(code **)(*a0 + 0x38))((unsigned char *)&local_170,a0);
            iVar17 = ((int (*)())compareStructure)((unsigned char *)&local_170,pcVar9,pcVar27,&local_50);
            bVar1 = iVar17 == 0;
            goto LAB_97b942fc;
          }
          goto LAB_97b9430c;
        }
        uVar19 = extraout_r4_07;
        fVar6 = GH_U2F((unsigned int)(local_4c));
        for (iVar12 = 0;
            iVar28 = (**(code **)(*(int *)this + 0x4c))(this,uVar19,pTVar18,a3,iVar17,param_6,fVar6)
            , iVar12 < iVar28; iVar12 = iVar12 + 1) {
          fVar6 = pfVar26[iVar12];
          if (*(float *)(pcVar27 + iVar12 * 4) == fVar6) goto LAB_97b94304;
          uVar19 = extraout_r4_10;
        }
      }
LAB_97b943d4:
      pTVar16 = (unsigned char *)GetGlobalPoolAllocator();
      puVar15 = (uint *)TPoolAllocator__allocate(pTVar16,4);
      *puVar15 = (uint)!bVar31;
      pTVar16 = (unsigned char *)GetGlobalPoolAllocator();
      pTVar18 = (unsigned char *)TPoolAllocator__allocate(pTVar16,0x34);
      local_14c = local_14c & 0x1801ff | 0x4180800;
      local_170 = (undefined **)(local_4c - 0x473c);
      local_16c = 0;
      local_164 = 0;
      local_160 = 0;
      local_15c = 0;
      local_158 = 0;
      local_154 = 0;
      local_150 = 0;
      local_168 = 0;
      *(int *)(pTVar18 + 4) = 0;
      *(undefined ***)pTVar18 = &PTR_getLine_a7b7cf90;
      *(int *)(pTVar18 + 0xc) = 0;
      *(int *)(pTVar18 + 0x10) = 0;
      *(int *)(pTVar18 + 0x14) = 0;
      *(int *)(pTVar18 + 0x18) = 0;
      *(int *)(pTVar18 + 0x1c) = 0;
      *(int *)(pTVar18 + 0x20) = 0;
      *(undefined ***)(pTVar18 + 8) = local_170;
      *(int *)(pTVar18 + 0x24) = 0;
      *(int *)(pTVar18 + 0x28) = 0;
      uVar10 = *(uint *)(pTVar18 + 0x2c);
      *(uint *)(pTVar18 + 0x2c) = uVar10 & 0x1ffffff | 0x4000000;
      uVar21 = (local_14c >> 0x13 & 0x3f) << 0x13;
      *(uint *)(pTVar18 + 0x2c) = uVar21 | uVar10 & 0x7ffff | 0x4000000;
      *(uint *)(pTVar18 + 0x2c) = uVar21 | uVar10 & 0x7ff | 0x4000000 | 0x800;
      *(uint *)(pTVar18 + 0x2c) = uVar21 | uVar10 & 0x3ff | 0x4000000 | 0x800;
      puVar8 = PTR_vtable_a7b7c0c8;
      *(uint *)(pTVar18 + 0x2c) = uVar21 | uVar10 & 0x1ff | 0x4000000 | 0x800;
      *(uint **)(pTVar18 + 0x30) = puVar15;
      *(undefined **)pTVar18 = puVar8 + 8;
      puVar11 = *(undefined4 **)this;
      param_3 = this;
LAB_97b953d4:
      iVar17 = *(int *)pTVar18;
      uVar19 = (*(code *)*puVar11)(param_3);
      (**(code **)(iVar17 + 4))(pTVar18,uVar19);
      return pTVar18;
    case 0x14:
      local_4c = 0xa7b81734;
      (**(code **)(*(int *)this + 0x38))(&local_170,this);
      local_170 = (undefined **)(local_4c - 0x473c);
      if ((local_14c >> 0x13 & 0x3f) != 1) {
        pcVar30 = "Constant Folding cannot be done for vector times matrix";
        uVar21 = (*(code *)**(undefined4 **)this)(this,a1_08,pTVar18,a3,iVar17,param_6,local_4c);
                    
        __ZN13TInfoSinkBase6appendEPKc(param_4,"INTERNAL ERROR: ");
        uVar10 = uVar21 & 0xffff;
        bVar32 = (uVar10 == 0) << 1;
        if (uVar10 == 0) {
          _sprintf((char *)aaStack_130,"%d:? ",(int)uVar21 >> 0x10);
        }
        else {
          _sprintf((char *)aaStack_130,"%d:%d",(int)uVar21 >> 0x10,uVar10);
        }
        paVar22 = aaStack_130;
        __ZNSsC1EPKcRKSaIcE(local_140,(char *)paVar22,(unsigned char *)&local_f0);
        *(undefined *)((int)local_140[0] + (int)local_140[0][-3]) = *PTR__S_terminal_a7b7c0b8;
        __ZN13TInfoSinkBase6appendEPKc(param_4,(char *)local_140[0]);
        ppuVar29 = local_140[0];
        goto code_r0x97b95b60;
      }
      iVar17 = (**(code **)(*(int *)this + 0x48))(this,a1_08);
      pTVar16 = (unsigned char *)GetGlobalPoolAllocator();
      iVar12 = TPoolAllocator__allocate(pTVar16,iVar17 << 2);
      iVar17 = (**(code **)(*(int *)this + 0x48))(this);
      iVar28 = 0;
      if (0 < iVar17) {
        iVar13 = 0;
        do {
          iVar14 = iVar28 * 4;
          *(undefined4 *)(iVar14 + iVar12) = 0;
          if (0 < iVar17) {
            pfVar24 = pfVar26 + iVar13;
            pcVar9 = pcVar27;
            iVar23 = iVar17;
            do {
              fVar6 = *(float *)pcVar9;
              pcVar9 = pcVar9 + 4;
              fVar5 = *pfVar24;
              pfVar24 = pfVar24 + 1;
              *(float *)(iVar14 + iVar12) = fVar6 * fVar5 + *(float *)(iVar14 + iVar12);
              iVar23 = iVar23 + -1;
            } while (iVar23 != 0);
          }
          iVar28 = iVar28 + 1;
          iVar13 = iVar13 + iVar17;
        } while (iVar28 < iVar17);
      }
      break;
    case 0x15:
      iVar17 = (**(code **)(*a0 + 0x40))(a0,uVar21);
      if (iVar17 != 1) {
        pcVar30 = "Constant Folding cannot be done for matrix times vector";
        uVar21 = (*(code *)**(undefined4 **)this)(this);
                    
        goto override_jmp_97b938f4_case_0;
      }
      iVar17 = (**(code **)(*(int *)this + 0x48))(this);
      pTVar16 = (unsigned char *)GetGlobalPoolAllocator();
      iVar12 = TPoolAllocator__allocate(pTVar16,iVar17 << 2);
      iVar17 = (**(code **)(*(int *)this + 0x48))(this);
      iVar28 = 0;
      if (0 < iVar17) {
        iVar13 = 0;
        do {
          *(undefined4 *)(iVar13 + iVar12) = 0;
          if (0 < iVar17) {
            pcVar9 = pcVar27 + iVar13;
            pfVar24 = pfVar26;
            iVar14 = iVar17;
            do {
              fVar6 = *(float *)pcVar9;
              pcVar9 = pcVar9 + iVar17 * 4;
              fVar5 = *pfVar24;
              pfVar24 = pfVar24 + 1;
              *(float *)(iVar13 + iVar12) = fVar6 * fVar5 + *(float *)(iVar13 + iVar12);
              iVar14 = iVar14 + -1;
            } while (iVar14 != 0);
          }
          iVar28 = iVar28 + 1;
          iVar13 = iVar13 + 4;
        } while (iVar28 < iVar17);
      }
      pTVar16 = (unsigned char *)GetGlobalPoolAllocator();
      pTVar18 = (unsigned char *)TPoolAllocator__allocate(pTVar16,0x34);
      (**(code **)(*a0 + 0x38))(&local_170,a0);
      *(undefined ***)pTVar18 = &PTR_getLine_a7b7cf90;
      puVar8 = &TType__vtable;
      *(int *)(pTVar18 + 4) = 0;
      goto LAB_97b946a4;
    case 0x17:
      local_4c = 0xa7b81734;
      iVar12 = (**(code **)(*(int *)this + 0x4c))(this);
      pTVar16 = (unsigned char *)GetGlobalPoolAllocator();
      uVar34 = TPoolAllocator__allocate(pTVar16,iVar12 << 2);
      iVar12 = (int)((ulonglong)uVar34 >> 0x20);
      uVar19 = (undefined4)uVar34;
      for (iVar28 = 0; iVar13 = (**(code **)(*(int *)this + 0x4c))(this,uVar19), iVar28 < iVar13;
          iVar28 = iVar28 + 1) {
        (**(code **)(*(int *)this + 0x38))(&local_170,this);
        local_170 = (undefined **)(local_4c - 0x473c);
        if ((local_14c >> 0x13 & 0x3f) != 3) {
          pcVar30 = "Constant folding cannot be done for \"||\"";
          uVar21 = (*(code *)**(undefined4 **)this)(this,a1_11,pTVar18,a3,iVar17,param_6,local_4c);
                    
          goto override_jmp_97b93868_case_0;
        }
        uVar19 = 0;
        if ((*(int *)(pcVar27 + iVar28 * 4) != 0) || (pfVar26[iVar28] != 0.0)) {
          uVar19 = 1;
        }
        *(undefined4 *)(iVar28 * 4 + iVar12) = uVar19;
        uVar19 = a1_11;
      }
      break;
    case 0x18:
      local_4c = 0xa7b81734;
      iVar12 = (**(code **)(*(int *)this + 0x4c))(this);
      pTVar16 = (unsigned char *)GetGlobalPoolAllocator();
      uVar34 = TPoolAllocator__allocate(pTVar16,iVar12 << 2);
      iVar12 = (int)((ulonglong)uVar34 >> 0x20);
      uVar19 = (undefined4)uVar34;
      for (iVar13 = 0;
          iVar28 = (**(code **)(*(int *)this + 0x4c))(this,uVar19,pTVar18,a3,iVar17,param_6,iVar28),
          iVar13 < iVar28; iVar13 = iVar13 + 1) {
        (**(code **)(*(int *)this + 0x38))(&local_170,this);
        local_170 = (undefined **)(local_4c - 0x473c);
        if ((local_14c >> 0x13 & 0x3f) != 3) {
          pcVar30 = "Constant folding cannot be done for \"^^\"";
          uVar21 = (*(code *)**(undefined4 **)this)(this,a1_10,pTVar18,a3,iVar17,param_6,local_4c);
                    
          goto override_jmp_97b93868_case_0;
        }
        iVar28 = iVar13 * 4;
        *(uint *)(iVar28 + iVar12) = (uint)(*(float *)(pcVar27 + iVar28) != pfVar26[iVar13]);
        uVar19 = a1_10;
      }
      break;
    case 0x19:
      local_4c = 0xa7b81734;
      iVar12 = (**(code **)(*(int *)this + 0x4c))(this);
      pTVar16 = (unsigned char *)GetGlobalPoolAllocator();
      iVar12 = TPoolAllocator__allocate(pTVar16,iVar12 << 2);
      for (iVar28 = 0; iVar13 = (**(code **)(*(int *)this + 0x4c))(this), iVar28 < iVar13;
          iVar28 = iVar28 + 1) {
        (**(code **)(*(int *)this + 0x38))(&local_170,this);
        local_170 = (undefined **)(local_4c - 0x473c);
        if ((local_14c >> 0x13 & 0x3f) != 3) {
          pcVar30 = "Constant folding cannot be done for \"&&\"";
          uVar21 = (*(code *)**(undefined4 **)this)(this,a1_09,pTVar18,a3,iVar17,param_6,local_4c);
                    
          goto override_jmp_97b93868_case_0;
        }
        uVar19 = 0;
        if ((*(int *)(pcVar27 + iVar28 * 4) != 0) && (pfVar26[iVar28] != 0.0)) {
          uVar19 = 1;
        }
        *(undefined4 *)(iVar28 * 4 + iVar12) = uVar19;
      }
      break;
    case 0x43:
      bVar31 = false;
      (**(code **)(*(int *)this + 0x38))(&local_170,this);
      uVar19 = extraout_r4_01;
      if (((local_14c >> 0x13 & 0x3f) != 1) ||
         (iVar17 = (**(code **)(*a0 + 0x40))(a0), uVar19 = extraout_r4_02, iVar17 != 1)) {
        bVar31 = true;
      }
      local_4c = 0xa7b81734;
      local_170 = &PTR___ZN5TTypeD1Ev_a7b7cff8;
      if (!bVar31) {
        iVar17 = (**(code **)(*(int *)this + 0x48))(this,uVar19);
        pTVar16 = (unsigned char *)GetGlobalPoolAllocator();
        iVar12 = TPoolAllocator__allocate(pTVar16,iVar17 * iVar17 * 4);
        iVar28 = 0;
        if (0 < iVar17) {
          do {
            if (0 < iVar17) {
              iVar23 = 0;
              iVar13 = iVar28 * 4;
              iVar14 = iVar17;
              do {
                *(undefined4 *)(iVar13 + iVar12) = 0;
                if (0 < iVar17) {
                  pfVar24 = pfVar26 + iVar23;
                  pcVar9 = pcVar27 + iVar28 * 4;
                  iVar33 = iVar17;
                  do {
                    fVar6 = *(float *)pcVar9;
                    pcVar9 = pcVar9 + iVar17 * 4;
                    fVar5 = *pfVar24;
                    pfVar24 = pfVar24 + 1;
                    *(float *)(iVar12 + iVar13) = fVar6 * fVar5 + *(float *)(iVar12 + iVar13);
                    iVar33 = iVar33 + -1;
                  } while (iVar33 != 0);
                }
                iVar14 = iVar14 + -1;
                iVar23 = iVar23 + iVar17;
                iVar13 = iVar13 + iVar17 * 4;
              } while (iVar14 != 0);
            }
            iVar28 = iVar28 + 1;
          } while (iVar28 < iVar17);
        }
        break;
      }
      pcVar30 = "Constant Folding cannot be done for matrix multiply";
      uVar21 = (*(code *)**(undefined4 **)this)(this);
                    
      __ZN13TInfoSinkBase6appendEPKc(param_4,"INTERNAL ERROR: ");
      uVar10 = uVar21 & 0xffff;
      bVar32 = (uVar10 == 0) << 1;
      if (uVar10 == 0) {
        _sprintf(acStack_d0,"%d:? ",(int)uVar21 >> 0x10);
      }
      else {
        _sprintf(acStack_d0,"%d:%d",(int)uVar21 >> 0x10,uVar10);
      }
      paVar22 = aaStack_130;
      __ZNSsC1EPKcRKSaIcE(local_140,acStack_d0,paVar22);
      *(undefined *)((int)local_140[0] + (int)local_140[0][-3]) = *PTR__S_terminal_a7b7c0b8;
      __ZN13TInfoSinkBase6appendEPKc(param_4,(char *)local_140[0]);
      ppuVar29 = local_140[0];
code_r0x97b932f0:
      ppuVar4 = ppuVar29 + -1;
      paVar20 = (unsigned char *)(ppuVar29 + -3);
      do {
        puVar8 = *ppuVar4;
        if (in_RESERVE != '\0') {
          puVar2 = (undefined *)storeWordConditionalIndexed(puVar8 + -1,0,ppuVar4);
          *ppuVar4 = puVar2;
          bVar32 = 2;
        }
      } while (!(bool)(bVar32 >> 1 & 1));
      bVar31 = 0 < (int)puVar8;
code_r0x97b93fb8:
      if (!bVar31) goto code_r0x97b95524;
      goto code_r0x97b95528;
    }
    pTVar16 = (unsigned char *)GetGlobalPoolAllocator();
    pTVar18 = (unsigned char *)TPoolAllocator__allocate(pTVar16,0x34);
    (**(code **)(*(int *)this + 0x38))(&local_170,this);
    *(int *)(pTVar18 + 4) = 0;
    *(undefined ***)pTVar18 = &PTR_getLine_a7b7cf90;
    puVar8 = (undefined *)(local_4c - 0x4744);
LAB_97b946a4:
    local_170 = (undefined **)(puVar8 + 8);
    *(int *)(pTVar18 + 0xc) = local_16c;
    *(int *)(pTVar18 + 0x10) = local_168;
    *(int *)(pTVar18 + 0x14) = local_164;
    *(int *)(pTVar18 + 0x18) = local_160;
    *(int *)(pTVar18 + 0x1c) = local_15c;
    *(int *)(pTVar18 + 0x20) = local_158;
    *(undefined ***)(pTVar18 + 8) = local_170;
    *(int *)(pTVar18 + 0x24) = local_154;
    *(int *)(pTVar18 + 0x28) = local_150;
    uVar7 = *(uint *)(pTVar18 + 0x2c);
    uVar10 = local_14c & 0xfe000000;
    *(uint *)(pTVar18 + 0x2c) = uVar10 | uVar7 & 0x1ffffff;
    uVar25 = (local_14c >> 0x13 & 0x3f) << 0x13;
    *(uint *)(pTVar18 + 0x2c) = uVar25 | uVar10 | uVar7 & 0x7ffff;
    uVar21 = local_14c & 0x7f800;
    *(uint *)(pTVar18 + 0x2c) = uVar21 | uVar25 | uVar10 | uVar7 & 0x7ff;
    uVar3 = (local_14c >> 10 & 1) << 10;
    *(uint *)(pTVar18 + 0x2c) = uVar3 | uVar21 | uVar25 | uVar10 | uVar7 & 0x3ff;
    puVar8 = PTR_vtable_a7b7c0c8;
    *(uint *)(pTVar18 + 0x2c) =
         (local_14c >> 9 & 1) << 9 | uVar3 | uVar21 | uVar25 | uVar10 | uVar7 & 0x1ff;
    *(int *)(pTVar18 + 0x30) = iVar12;
    *(undefined **)pTVar18 = puVar8 + 8;
LAB_97b94758:
    iVar17 = *(int *)pTVar18;
    uVar19 = (*(code *)**(undefined4 **)this)(this);
    (**(code **)(iVar17 + 4))(pTVar18,uVar19);
    return pTVar18;
  }
LAB_97b9478c:
  bVar31 = false;
  iVar12 = (**(code **)(*(int *)this + 0x4c))(this);
  if (iVar12 != 1) {
    return this;
  }
  (**(code **)(*(int *)this + 0x38))(&local_170,this);
  if (((local_14c >> 0x13 & 0x3f) != 0xe) &&
     (iVar12 = (**(code **)(*(int *)param_3 + 0x4c))(param_3), iVar12 == 1)) {
    (**(code **)(*(int *)param_3 + 0x38))(local_140,param_3);
    bVar31 = (local_11c >> 0x13 & 0x3f) != 0xe;
    local_140[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  }
  local_170 = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  if (!bVar31) {
    return this;
  }
  pTVar16 = (unsigned char *)GetGlobalPoolAllocator();
  pfVar26 = (float *)TPoolAllocator__allocate(pTVar16,4);
  local_4c = 0xa7b81734;
  (**(code **)(*(int *)this + 0x38))(&local_110,this);
  local_110 = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  uVar21 = local_ec >> 0x13 & 0x3f;
  if (uVar21 != 2) {
    if (2 < uVar21) {
      if (uVar21 != 3) goto LAB_97b95400;
      iVar17 = (**(code **)(*(int *)param_3 + 0x18))(param_3);
      uVar10 = **(uint **)(iVar17 + 0x30);
      uVar21 = **(uint **)(this + 0x30);
      if (param_2 == 0x2b) {
        bVar31 = uVar21 == uVar10;
LAB_97b9529c:
        *pfVar26 = GH_U2F((unsigned int)((1 - (uint)bVar31)));
        pTVar16 = (unsigned char *)GetGlobalPoolAllocator();
        pTVar18 = (unsigned char *)TPoolAllocator__allocate(pTVar16,0x34);
        local_ec = local_ec & 0x1801ff | 0x4180800;
        local_110 = (undefined **)(local_4c - 0x473c);
        local_10c = 0;
        local_104 = 0;
        local_100 = 0;
        local_fc = 0;
        local_f8 = 0;
        local_f4 = 0;
        local_f0 = 0;
        local_108 = 0;
        *(int *)(pTVar18 + 4) = 0;
        *(undefined ***)pTVar18 = &PTR_getLine_a7b7cf90;
        *(int *)(pTVar18 + 0xc) = 0;
        *(int *)(pTVar18 + 0x10) = 0;
        *(int *)(pTVar18 + 0x14) = 0;
        *(int *)(pTVar18 + 0x18) = 0;
        *(int *)(pTVar18 + 0x1c) = 0;
        *(int *)(pTVar18 + 0x20) = 0;
        *(undefined ***)(pTVar18 + 8) = local_110;
        *(int *)(pTVar18 + 0x24) = 0;
        *(int *)(pTVar18 + 0x28) = 0;
        uVar10 = *(uint *)(pTVar18 + 0x2c);
        *(uint *)(pTVar18 + 0x2c) = uVar10 & 0x1ffffff | 0x4000000;
        uVar21 = (local_ec >> 0x13 & 0x3f) << 0x13;
        *(uint *)(pTVar18 + 0x2c) = uVar21 | uVar10 & 0x7ffff | 0x4000000;
        *(uint *)(pTVar18 + 0x2c) = uVar21 | uVar10 & 0x7ff | 0x4000000 | 0x800;
        *(uint *)(pTVar18 + 0x2c) = uVar21 | uVar10 & 0x3ff | 0x4000000 | 0x800;
        puVar8 = PTR_vtable_a7b7c0c8;
        *(uint *)(pTVar18 + 0x2c) = uVar21 | uVar10 & 0x1ff | 0x4000000 | 0x800;
        *(float **)(pTVar18 + 0x30) = pfVar26;
        *(undefined **)pTVar18 = puVar8 + 8;
        puVar11 = *(undefined4 **)param_3;
        goto LAB_97b953d4;
      }
      if (param_2 < 0x2c) {
        if (param_2 == 0x2a) {
          uVar21 = uVar21 | uVar10;
LAB_97b95254:
          bVar31 = uVar21 == 0;
          goto LAB_97b9529c;
        }
      }
      else {
        uVar21 = uVar21 & uVar10;
        if (param_2 == 0x2c) goto LAB_97b95254;
      }
      pcVar30 = "Binary operator cannot be folded into constant bool";
      uVar21 = *(uint *)(this + 4);
                    
override_jmp_97b95280_case_0:
      __ZN13TInfoSinkBase6appendEPKc(param_4,"INTERNAL ERROR: ");
      uVar10 = uVar21 & 0xffff;
      bVar32 = (uVar10 == 0) << 1;
      if (uVar10 == 0) {
        _sprintf((char *)&local_100,"%d:? ",(int)uVar21 >> 0x10);
      }
      else {
        _sprintf((char *)&local_100,"%d:%d",(int)uVar21 >> 0x10,uVar10);
      }
      paVar22 = (unsigned char *)&local_100;
      __ZNSsC1EPKcRKSaIcE(&local_110,(char *)paVar22,aaStack_c0);
                    
      *(undefined *)((int)local_110 + (int)local_110[-3]) = *PTR__S_terminal_a7b7c0b8;
      __ZN13TInfoSinkBase6appendEPKc(param_4,(char *)local_110);
      ppuVar29 = local_110 + -1;
      paVar20 = (unsigned char *)(local_110 + -3);
      do {
        puVar8 = *ppuVar29;
                    
        if (in_RESERVE != '\0') {
          puVar2 = (undefined *)storeWordConditionalIndexed(puVar8 + -1,0,ppuVar29);
          *ppuVar29 = puVar2;
          bVar32 = 2;
        }
      } while (!(bool)(bVar32 >> 1 & 1));
      if ((int)puVar8 < 1) {
code_r0x97b95524:
        __ZNSs4_Rep10_M_destroyERKSaIcE(paVar20,paVar22);
      }
code_r0x97b95528:
      __ZN13TInfoSinkBase6appendEPKc(param_4,": ");
      goto code_r0x97b95ba0;
    }
    if (uVar21 != 1) {
LAB_97b95400:
      pcVar30 = "Cannot fold constant";
      uVar21 = (*(code *)**(undefined4 **)this)(this);
                    
      goto override_jmp_97b95280_case_0;
    }
    iVar12 = (**(code **)(*(int *)param_3 + 0x18))(param_3);
    uVar21 = param_2 - 0x13;
    fVar6 = **(float **)(iVar12 + 0x30);
    fVar5 = **(float **)(this + 0x30);
    if (0x11 < uVar21) {
      return (unsigned char *)0x0;
    }
    switch(uVar21) {
    case 0:
      fVar5 = fVar5 + fVar6;
      goto LAB_97b94ef8;
    case 1:
      fVar5 = fVar5 - fVar6;
      goto LAB_97b94ef8;
    case 2:
      fVar5 = fVar5 * fVar6;
      goto LAB_97b94ef8;
    case 3:
      if (fVar6 == 0.0) {
        uVar21 = (*(code *)**(undefined4 **)this)(this,uVar21,pTVar18,a3,iVar17,param_6,uVar21 * 4);
                    
        __ZN13TInfoSinkBase6appendEPKc(param_4,"WARNING: ");
        uVar10 = uVar21 & 0xffff;
        bVar32 = (uVar10 == 0) << 1;
        if (uVar10 == 0) {
          _sprintf((char *)&local_100,"%d:? ",(int)uVar21 >> 0x10);
        }
        else {
          _sprintf((char *)&local_100,"%d:%d",(int)uVar21 >> 0x10,uVar10);
        }
        __ZNSsC1EPKcRKSaIcE(&local_110,(char *)&local_100,aaStack_c0);
        *(undefined *)((int)local_110 + (int)local_110[-3]) = *PTR__S_terminal_a7b7c0b8;
        __ZN13TInfoSinkBase6appendEPKc(param_4,(char *)local_110);
        ppuVar29 = local_110 + -1;
        do {
          puVar8 = *ppuVar29;
          if (in_RESERVE != '\0') {
            puVar2 = (undefined *)storeWordConditionalIndexed(puVar8 + -1,0,ppuVar29);
            *ppuVar29 = puVar2;
            bVar32 = 2;
          }
        } while (!(bool)(bVar32 >> 1 & 1));
        if ((int)puVar8 < 1) {
          __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(local_110 + -3),&local_100);
        }
        __ZN13TInfoSinkBase6appendEPKc(param_4,": ");
        __ZN13TInfoSinkBase6appendEPKc(param_4,"Divide by zero error during constant folding");
        __ZN13TInfoSinkBase6appendEPKc(param_4,"\n");
        fVar5 = 3.4028235e+38;
      }
      else {
        fVar5 = fVar5 / fVar6;
      }
LAB_97b94ef8:
      *pfVar26 = fVar5;
      goto code_r0x97b95098;
    default:
      goto switchD_97b94d20_caseD_17;
    case 10:
      fVar6 = GH_U2F((unsigned int)((uint)(fVar5 == fVar6)));
      break;
    case 0xb:
      fVar6 = GH_U2F((unsigned int)((uint)(fVar5 != fVar6)));
      break;
    case 0xe:
      fVar6 = GH_U2F((unsigned int)((uint)(fVar5 < fVar6)));
      break;
    case 0xf:
      fVar6 = GH_U2F((unsigned int)((uint)(fVar6 < fVar5)));
      break;
    case 0x10:
      bVar31 = fVar5 <= fVar6;
      goto LAB_97b94f58;
    case 0x11:
      bVar31 = fVar6 <= fVar5;
LAB_97b94f58:
      fVar6 = GH_U2F((unsigned int)((uint)bVar31));
    }
    *pfVar26 = fVar6;
    pTVar16 = (unsigned char *)GetGlobalPoolAllocator();
    pTVar18 = (unsigned char *)TPoolAllocator__allocate(pTVar16,0x34);
    local_ec = local_ec & 0x1801ff | 0x4180800;
    local_110 = (undefined **)(local_4c - 0x473c);
    local_10c = 0;
    local_104 = 0;
    local_100 = 0;
    local_fc = 0;
    local_f8 = 0;
    local_f4 = 0;
    local_f0 = 0;
    local_108 = 0;
    *(int *)(pTVar18 + 4) = 0;
    *(undefined ***)pTVar18 = &PTR_getLine_a7b7cf90;
    *(int *)(pTVar18 + 0xc) = 0;
    *(int *)(pTVar18 + 0x10) = 0;
    *(int *)(pTVar18 + 0x14) = 0;
    *(int *)(pTVar18 + 0x18) = 0;
    *(int *)(pTVar18 + 0x1c) = 0;
    *(int *)(pTVar18 + 0x20) = 0;
    *(int *)(pTVar18 + 0x24) = 0;
    *(undefined ***)(pTVar18 + 8) = local_110;
    *(int *)(pTVar18 + 0x28) = 0;
    uVar10 = *(uint *)(pTVar18 + 0x2c);
    *(uint *)(pTVar18 + 0x2c) = uVar10 & 0x1ffffff | 0x4000000;
    uVar21 = (local_ec >> 0x13 & 0x3f) << 0x13;
    *(uint *)(pTVar18 + 0x2c) = uVar21 | uVar10 & 0x7ffff | 0x4000000;
    *(uint *)(pTVar18 + 0x2c) = uVar21 | uVar10 & 0x7ff | 0x4000000 | 0x800;
    *(uint *)(pTVar18 + 0x2c) = uVar21 | uVar10 & 0x3ff | 0x4000000 | 0x800;
    puVar8 = PTR_vtable_a7b7c0c8;
    *(uint *)(pTVar18 + 0x2c) = uVar21 | uVar10 & 0x1ff | 0x4000000 | 0x800;
    *(float **)(pTVar18 + 0x30) = pfVar26;
    *(undefined **)pTVar18 = puVar8 + 8;
    if (pTVar18 != (unsigned char *)0x0) goto LAB_97b951c0;
code_r0x97b95098:
    pTVar16 = (unsigned char *)GetGlobalPoolAllocator();
    pTVar18 = (unsigned char *)TPoolAllocator__allocate(pTVar16,0x34);
    uVar21 = local_ec & 0x7ff | 0x4080000;
    goto code_r0x97b950c8;
  }
  iVar12 = (**(code **)(*(int *)param_3 + 0x18))(param_3);
  uVar21 = param_2 - 0x13;
  uVar25 = **(uint **)(iVar12 + 0x30);
  uVar10 = **(uint **)(this + 0x30);
  if (0x11 < uVar21) {
    return (unsigned char *)0x0;
  }
  switch(uVar21) {
  case 0:
    fVar6 = GH_U2F((unsigned int)((uVar10 + uVar25)));
    break;
  case 1:
    fVar6 = GH_U2F((unsigned int)((uVar10 - uVar25)));
    break;
  case 2:
    fVar6 = GH_U2F((unsigned int)((uVar10 * uVar25)));
    break;
  case 3:
    if (uVar25 == 0) {
      uVar21 = (*(code *)**(undefined4 **)this)
                         (this,uVar21,pTVar18,a3,iVar17,param_6,uVar21 * 4,uVar10);
                    
      __ZN13TInfoSinkBase6appendEPKc(param_4,"WARNING: ");
      uVar10 = uVar21 & 0xffff;
      bVar32 = (uVar10 == 0) << 1;
      if (uVar10 == 0) {
        _sprintf(acStack_90,"%d:? ",(int)uVar21 >> 0x10);
      }
      else {
        _sprintf(acStack_90,"%d:%d",(int)uVar21 >> 0x10,uVar10);
      }
      __ZNSsC1EPKcRKSaIcE(&local_110,acStack_90,(unsigned char *)&local_100);
      *(undefined *)((int)local_110 + (int)local_110[-3]) = *PTR__S_terminal_a7b7c0b8;
      __ZN13TInfoSinkBase6appendEPKc(param_4,(char *)local_110);
      ppuVar29 = local_110 + -1;
      do {
        puVar8 = *ppuVar29;
        if (in_RESERVE != '\0') {
          puVar2 = (undefined *)storeWordConditionalIndexed(puVar8 + -1,0,ppuVar29);
          *ppuVar29 = puVar2;
          bVar32 = 2;
        }
      } while (!(bool)(bVar32 >> 1 & 1));
      if ((int)puVar8 < 1) {
        __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(local_110 + -3),(unsigned char *)&local_100);
      }
      __ZN13TInfoSinkBase6appendEPKc(param_4,": ");
      __ZN13TInfoSinkBase6appendEPKc(param_4,"Divide by zero error during constant folding");
      __ZN13TInfoSinkBase6appendEPKc(param_4,"\n");
      fVar6 = GH_U2F(0x7fffffffU);
    }
    else {
      fVar6 = GH_U2F((unsigned int)(((int)uVar10 / (int)uVar25)));
    }
    break;
  case 4:
    fVar6 = GH_U2F((unsigned int)((uVar10 - ((int)uVar10 / (int)uVar25) * uVar25)));
    break;
  case 5:
    fVar6 = GH_U2F((unsigned int)(((int)uVar10 >> (uVar25 & 0x3f))));
    break;
  case 6:
    fVar6 = GH_U2F((unsigned int)((uVar10 << (uVar25 & 0x3f))));
    break;
  case 7:
    fVar6 = GH_U2F((unsigned int)((uVar10 & uVar25)));
    break;
  case 8:
    fVar6 = GH_U2F((unsigned int)((uVar10 | uVar25)));
    break;
  case 9:
    fVar6 = GH_U2F((unsigned int)((uVar10 ^ uVar25)));
    break;
  case 10:
    fVar6 = GH_U2F((unsigned int)((uint)(uVar10 == uVar25)));
    goto LAB_97b94b6c;
  case 0xb:
    *pfVar26 = GH_U2F((unsigned int)((uint)(uVar10 != uVar25)));
    goto LAB_97b94b70;
  default:
    goto switchD_97b94d20_caseD_17;
  case 0xe:
    fVar6 = 1.4013e-45;
    if ((int)uVar25 <= (int)uVar10) {
LAB_97b94b68:
      fVar6 = 0.0;
    }
    goto LAB_97b94b6c;
  case 0xf:
    fVar6 = 1.4013e-45;
    if ((int)uVar10 <= (int)uVar25) goto LAB_97b94b68;
    goto LAB_97b94b6c;
  case 0x10:
    fVar6 = 1.4013e-45;
    if ((int)uVar25 < (int)uVar10) goto LAB_97b94b68;
    goto LAB_97b94b6c;
  case 0x11:
    fVar6 = 1.4013e-45;
    if ((int)uVar10 < (int)uVar25) goto LAB_97b94b68;
LAB_97b94b6c:
    *pfVar26 = fVar6;
LAB_97b94b70:
    pTVar16 = (unsigned char *)GetGlobalPoolAllocator();
    pTVar18 = (unsigned char *)TPoolAllocator__allocate(pTVar16,0x34);
    local_ec = local_ec & 0x1801ff | 0x4180800;
    local_110 = (undefined **)(local_4c - 0x473c);
    local_10c = 0;
    local_104 = 0;
    local_100 = 0;
    local_fc = 0;
    local_f8 = 0;
    local_f4 = 0;
    local_f0 = 0;
    local_108 = 0;
    *(int *)(pTVar18 + 4) = 0;
    *(undefined ***)pTVar18 = &PTR_getLine_a7b7cf90;
    *(int *)(pTVar18 + 0xc) = 0;
    *(int *)(pTVar18 + 0x10) = 0;
    *(int *)(pTVar18 + 0x14) = 0;
    *(int *)(pTVar18 + 0x18) = 0;
    *(int *)(pTVar18 + 0x1c) = 0;
    *(int *)(pTVar18 + 0x20) = 0;
    *(int *)(pTVar18 + 0x24) = 0;
    *(undefined ***)(pTVar18 + 8) = local_110;
    *(int *)(pTVar18 + 0x28) = 0;
    uVar10 = *(uint *)(pTVar18 + 0x2c);
    *(uint *)(pTVar18 + 0x2c) = uVar10 & 0x1ffffff | 0x4000000;
    uVar21 = (local_ec >> 0x13 & 0x3f) << 0x13;
    *(uint *)(pTVar18 + 0x2c) = uVar21 | uVar10 & 0x7ffff | 0x4000000;
    *(uint *)(pTVar18 + 0x2c) = uVar21 | uVar10 & 0x7ff | 0x4000000 | 0x800;
    *(uint *)(pTVar18 + 0x2c) = uVar21 | uVar10 & 0x3ff | 0x4000000 | 0x800;
    puVar8 = PTR_vtable_a7b7c0c8;
    *(uint *)(pTVar18 + 0x2c) = uVar21 | uVar10 & 0x1ff | 0x4000000 | 0x800;
    *(float **)(pTVar18 + 0x30) = pfVar26;
    *(undefined **)pTVar18 = puVar8 + 8;
    if (pTVar18 != (unsigned char *)0x0) goto LAB_97b951c0;
    goto code_r0x97b94ca4;
  }
  *pfVar26 = fVar6;
code_r0x97b94ca4:
  pTVar16 = (unsigned char *)GetGlobalPoolAllocator();
  pTVar18 = (unsigned char *)TPoolAllocator__allocate(pTVar16,0x34);
  uVar21 = local_ec & 0xfff | 0x4100000;
code_r0x97b950c8:
  local_110 = (undefined **)(local_4c - 0x473c);
  local_ec = uVar21 & 0xfffff9ff | 0x800;
  *(int *)(pTVar18 + 4) = 0;
  *(undefined ***)pTVar18 = &PTR_getLine_a7b7cf90;
  *(int *)(pTVar18 + 0xc) = 0;
  *(int *)(pTVar18 + 0x10) = 0;
  *(int *)(pTVar18 + 0x14) = 0;
  *(int *)(pTVar18 + 0x18) = 0;
  *(int *)(pTVar18 + 0x1c) = 0;
  *(int *)(pTVar18 + 0x20) = 0;
  *(undefined ***)(pTVar18 + 8) = local_110;
  *(int *)(pTVar18 + 0x24) = 0;
  *(int *)(pTVar18 + 0x28) = 0;
  uVar25 = *(uint *)(pTVar18 + 0x2c);
  uVar10 = uVar21 & 0xfe000000;
  *(uint *)(pTVar18 + 0x2c) = uVar10 | uVar25 & 0x1ffffff;
  uVar21 = uVar21 & 0x1f80000;
  *(uint *)(pTVar18 + 0x2c) = uVar21 | uVar10 | uVar25 & 0x7ffff;
  *(uint *)(pTVar18 + 0x2c) = uVar21 | uVar10 | uVar25 & 0x7ff | 0x800;
  *(uint *)(pTVar18 + 0x2c) = uVar21 | uVar10 | uVar25 & 0x3ff | 0x800;
  puVar8 = PTR_vtable_a7b7c0c8;
  *(uint *)(pTVar18 + 0x2c) = uVar21 | uVar10 | uVar25 & 0x1ff | 0x800;
  *(float **)(pTVar18 + 0x30) = pfVar26;
  *(undefined **)pTVar18 = puVar8 + 8;
LAB_97b951c0:
  local_f0 = 0;
  iVar17 = *(int *)pTVar18;
  local_10c = local_f0;
  local_108 = local_f0;
  local_104 = local_f0;
  local_100 = local_f0;
  local_fc = local_f0;
  local_f8 = local_f0;
  local_f4 = local_f0;
  uVar19 = (*(code *)**(undefined4 **)param_3)(param_3);
  (**(code **)(iVar17 + 4))(pTVar18,uVar19);
  return pTVar18;
}

/* TIntermediate__changeAggrToTempConst @ 0x97b95c0c (484 bytes) */
int TIntermediate__changeAggrToTempConst(this, param_2, param_3, param_4)
  unsigned char * this;
  unsigned char * param_2;
  unsigned char * param_3;
  int param_4;
{
  int iVar1;
  unsigned char * this_00;
  int *a0;
  int iVar2;
  undefined4 uVar3;
  undefined4 a1;
  unsigned char * a2;
  undefined4 in_r7;
  undefined4 in_r8;
  int a6;
  unsigned char * pcVar4;
  undefined8 uVar5;
  undefined **local_60 [9];
  uint local_3c;
  
  a2 = param_3;
  iVar2 = param_4;
  (**(code **)(*(int *)param_2 + 0x38))(local_60,param_2,param_3,param_4);
  if ((local_3c & 0x400) == 0) {
    iVar1 = (int)(local_3c << 0xd | local_3c >> 0x13) >> 0x18;
  }
  else {
    iVar1 = (int)(local_3c << 0xd | local_3c >> 0x13) >> 0x18;
    iVar1 = iVar1 * iVar1;
  }
  this_00 = (unsigned char *)GetGlobalPoolAllocator();
  uVar5 = TPoolAllocator__allocate(this_00,iVar1 << 2);
  pcVar4 = (unsigned char *)((ulonglong)uVar5 >> 0x20);
  local_60[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  iVar1 = (**(code **)(*(int *)param_2 + 100))
                    (param_2,(int)uVar5,a2,iVar2,in_r7,in_r8,*(int *)param_2);
  if (*(int *)(iVar1 + 8) - *(int *)(iVar1 + 4) >> 2 == 1) {
    iVar1 = (**(code **)(*(int *)param_2 + 100))(param_2);
    a6 = *(int *)**(undefined4 **)(iVar1 + 4);
    a0 = (int *)(**(code **)(a6 + 0x14))
                          ((int *)**(undefined4 **)(iVar1 + 4),a1,a2,iVar2,in_r7,in_r8,a6);
    iVar2 = (**(code **)(*a0 + 0x18))(a0);
    if (iVar2 != 0) {
      (**(code **)(*(int *)param_2 + 0x38))(local_60,param_2);
      iVar2 = ((int (*)())TIntermediate__parseConstTree)(this,param_4,(unsigned char *)param_2,pcVar4,*(undefined4 *)(param_2 + 0x30),
                         param_3,local_60,1);
      goto LAB_97b95d90;
    }
  }
  (**(code **)(*(int *)param_2 + 0x38))(local_60,param_2);
  iVar2 = ((int (*)())TIntermediate__parseConstTree)(this,param_4,(unsigned char *)param_2,pcVar4,*(undefined4 *)(param_2 + 0x30),
                     param_3,local_60,0);
LAB_97b95d90:
  local_60[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  if (iVar2 != 0) {
    pcVar4 = (unsigned char *)0x0;
  }
  (**(code **)(*(int *)param_2 + 0x38))(local_60,param_2);
  iVar2 = (*(code *)**(undefined4 **)param_2)(param_2);
  uVar3 = TIntermediate__addConstantUnion(this,pcVar4,(unsigned char *)local_60,iVar2);
  return uVar3;
}

/* TIntermediate__copyConstUnion @ 0x97b95df0 (336 bytes) */
int TIntermediate__copyConstUnion(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  int iVar1;
  int iVar2;
  unsigned char * this_00;
  int iVar3;
  unsigned char * pTVar4;
  int iVar5;
  int iVar6;
  undefined **local_b0 [9];
  uint local_8c;
  undefined **local_80 [2];
  unsigned char * local_78;
  uint local_5c;
  undefined **local_50 [14];
  
  iVar6 = *(int *)(param_2 + 0x30);
  pTVar4 = (unsigned char *)0x0;
  if (iVar6 != 0) {
    (**(code **)(*(int *)param_2 + 0x38))(local_b0);
    local_b0[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
    if ((local_8c >> 0x13 & 0x3f) == 0xe) {
      (**(code **)(*(int *)param_2 + 0x38))(local_80,param_2);
      (**(code **)(*(int *)param_2 + 0x38))((unsigned char *)local_50,param_2);
      iVar2 = TType__setStructSize((unsigned char *)local_50,local_78);
      local_50[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
    }
    else {
      (**(code **)(*(int *)param_2 + 0x38))(local_80,param_2);
      if ((local_5c & 0x400) == 0) {
        iVar2 = (int)(local_5c << 0xd | local_5c >> 0x13) >> 0x18;
      }
      else {
        iVar2 = (int)(local_5c << 0xd | local_5c >> 0x13) >> 0x18;
        iVar2 = iVar2 * iVar2;
      }
    }
    local_80[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
    this_00 = (unsigned char *)GetGlobalPoolAllocator();
    iVar3 = TPoolAllocator__allocate(this_00,iVar2 << 2);
    iVar5 = 0;
    if (0 < iVar2) {
      do {
        iVar1 = iVar5 * 4;
        iVar5 = iVar5 + 1;
        *(undefined4 *)(iVar3 + iVar1) = *(undefined4 *)(iVar6 + iVar1);
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    *(int *)(param_2 + 0x30) = iVar3;
    pTVar4 = param_2;
  }
  return pTVar4;
}

/* TIntermediate__promoteConstantUnion @ 0x97b95f40 (876 bytes) */
int TIntermediate__promoteConstantUnion(this, param_2, param_3)
  unsigned char * this;
  uint param_2;
  int *param_3;
{
  undefined *puVar1;
  int iVar2;
  undefined **ppuVar3;
  undefined *puVar4;
  unsigned char * this_00;
  unsigned char * pcVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 a1;
  undefined4 a1_00;
  undefined4 a1_01;
  int *a2;
  undefined4 in_r6;
  uint a1_02;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined *in_r9;
  int iVar8;
  char *pcVar9;
  int iVar10;
  void *this_01;
  char in_RESERVE;
  byte bVar11;
  double dVar12;
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
  
  iVar8 = param_3[0xc];
  a2 = param_3;
  (**(code **)(*param_3 + 0x38))(local_c0,param_3,param_3);
  if ((local_9c & 0x400) == 0) {
    iVar2 = (int)(local_9c << 0xd | local_9c >> 0x13) >> 0x18;
  }
  else {
    iVar2 = (int)(local_9c << 0xd | local_9c >> 0x13) >> 0x18;
    iVar2 = iVar2 * iVar2;
  }
  local_c0[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  this_00 = (unsigned char *)GetGlobalPoolAllocator();
  iVar10 = 0;
  pcVar5 = (unsigned char *)TPoolAllocator__allocate(this_00,iVar2 << 2);
  if (0 < iVar2) {
    do {
      if (param_2 == 2) {
        (**(code **)(*param_3 + 0x38))(local_c0,param_3);
        uVar6 = local_9c >> 0x13 & 0x3f;
        local_c0[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
        if (uVar6 == 2) {
LAB_97b96230:
          uVar6 = *(uint *)(iVar10 * 4 + iVar8);
        }
        else {
          if (2 < uVar6) {
            if (uVar6 != 3) goto LAB_97b96174;
            goto LAB_97b96230;
          }
          if (uVar6 != 1) {
LAB_97b96174:
            this_01 = *(void **)this;
            pcVar9 = "Cannot promote";
            uVar6 = (**(code **)*param_3)(param_3);
                    
            goto override_jmp_97b960f0_case_0;
          }
          uVar6 = (uint)(int)*(float *)(iVar10 * 4 + iVar8);
          local_40 = (longlong)(int)uVar6;
        }
LAB_97b9625c:
        *(uint *)(pcVar5 + iVar10 * 4) = uVar6;
      }
      else if ((int)param_2 < 3) {
        if (param_2 != 1) {
LAB_97b962b8:
          this_01 = *(void **)this;
          pcVar9 = "Incorrect data type found";
          uVar6 = (**(code **)*param_3)(param_3);
                    
override_jmp_97b960f0_case_0:
          __ZN13TInfoSinkBase6appendEPKc(this_01,"INTERNAL ERROR: ");
          a1_02 = uVar6 & 0xffff;
          bVar11 = (a1_02 == 0) << 1;
          if (a1_02 == 0) {
            _sprintf((char *)&local_80,"%d:? ",(int)uVar6 >> 0x10);
          }
          else {
            _sprintf((char *)&local_80,"%d:%d",(int)uVar6 >> 0x10,a1_02);
          }
          __ZNSsC1EPKcRKSaIcE(local_c0,(char *)&local_80,aaStack_b0);
          *(undefined *)((int)local_c0[0] + (int)local_c0[0][-3]) = *PTR__S_terminal_a7b7c0b8;
          __ZN13TInfoSinkBase6appendEPKc(this_01,(char *)local_c0[0]);
          ppuVar3 = local_c0[0] + -1;
          do {
            puVar4 = *ppuVar3;
            if (in_RESERVE != '\0') {
              puVar1 = (undefined *)storeWordConditionalIndexed(puVar4 + -1,0,ppuVar3);
              *ppuVar3 = puVar1;
              bVar11 = 2;
            }
          } while (!(bool)(bVar11 >> 1 & 1));
          if ((int)puVar4 < 1) {
            __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(local_c0[0] + -3),aaStack_b0);
          }
          __ZN13TInfoSinkBase6appendEPKc(this_01,": ");
          __ZN13TInfoSinkBase6appendEPKc(this_01,pcVar9);
          __ZN13TInfoSinkBase6appendEPKc(this_01,"\n");
          return 0;
        }
        (**(code **)(*param_3 + 0x38))(local_c0,param_3);
        uVar6 = local_9c >> 0x13 & 0x3f;
        local_c0[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
        if (uVar6 != 2) {
          if (uVar6 < 3) {
            if (uVar6 == 1) {
              *(undefined4 *)(pcVar5 + iVar10 * 4) = *(undefined4 *)(iVar8 + iVar10 * 4);
              goto LAB_97b9641c;
            }
          }
          else if (uVar6 == 3) {
            uStack_8c = *(uint *)(iVar10 * 4 + iVar8);
            dVar12 = 4503599627370496.0;
            goto LAB_97b96098;
          }
          this_01 = *(void **)this;
          pcVar9 = "Cannot promote";
          uVar6 = (**(code **)*param_3)(param_3,a1,a2,in_r6,in_r7,in_r8,in_r9);
                    
          goto override_jmp_97b960f0_case_0;
        }
        uStack_8c = *(uint *)(iVar10 * 4 + iVar8) ^ 0x80000000;
        dVar12 = 4503601774854144.0;
LAB_97b96098:
        in_r9 = (undefined *)(iVar10 * 4);
        local_90 = 0x43300000;
        *(float *)(pcVar5 + (int)in_r9) = (float)((double)CONCAT44(0x43300000,uStack_8c) - dVar12);
      }
      else {
        if (param_2 != 3) goto LAB_97b962b8;
        (**(code **)(*param_3 + 0x38))(local_c0,param_3);
        uVar6 = local_9c >> 0x13 & 0x3f;
        local_c0[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
        if (uVar6 != 2) {
          if (uVar6 < 3) {
            if (uVar6 == 1) {
              in_r9 = &DAT_97c35f58;
              uVar6 = (uint)(*(float *)(iVar10 * 4 + iVar8) != 0.0);
              goto LAB_97b9625c;
            }
          }
          else if (uVar6 == 3) goto LAB_97b96230;
          this_01 = *(void **)this;
          pcVar9 = "Cannot promote";
          uVar6 = (**(code **)*param_3)(param_3,a1_00,a2,in_r6,in_r7,in_r8,in_r9);
                    
          goto override_jmp_97b960f0_case_0;
        }
        in_r9 = (undefined *)(uint)(*(int *)(iVar8 + iVar10 * 4) != 0);
        *(undefined **)(pcVar5 + iVar10 * 4) = in_r9;
      }
LAB_97b9641c:
      local_c0[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
      iVar10 = iVar10 + 1;
    } while (iVar10 < iVar2);
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
  local_80 = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  iVar8 = (**(code **)*param_3)(param_3,a1_01,a2,in_r6,in_r7,in_r8,(undefined4 *)*param_3);
  uVar7 = TIntermediate__addConstantUnion(this,pcVar5,(unsigned char *)&local_80,iVar8);
  return uVar7;
}

/* __ZN13TIntermediate15removeChildNodeER7TVectorIP11TIntermNodeER5TTypeRiRN9__gnu_cxx17__normal_iteratorIPS2_St6vectorIS2_14pool_allocatorIS2_EEEEP16TIntermAggregate @ 0x97b964e8 (824 bytes) */
int __ZN13TIntermediate15removeChildNodeER7TVectorIP11TIntermNodeER5TTypeRiRN9__gnu_cxx17__normal_iteratorIPS2_St6vectorIS2_14pool_allocatorIS2_EEEEP16TIntermAggregate(this, param_2, param_3, param_4, param_5, param_6)
  void *this;
  unsigned char * param_2;
  unsigned char * param_3;
  int *param_4;
  unsigned char * param_5;
  unsigned char * param_6;
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
  unsigned char * pTVar10;
  undefined4 *puVar11;
  int *a0;
  int *a1;
  undefined4 a1_00;
  undefined4 a1_01;
  unsigned char * a3;
  int a4;
  unsigned char * a5;
  int iVar12;
  undefined *puVar13;
  undefined8 uVar14;
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
  
  if (param_6 != (unsigned char *)0x0) {
    *(int *)param_5 = *(int *)(param_2 + 4) + *param_4 * 4;
    a5 = param_6;
    iVar8 = (**(code **)(*(int *)param_6 + 100))
                      (param_6,param_2,param_3,param_4,param_5,param_6,*(int *)param_6);
    iVar12 = *(int *)(param_2 + 8);
    iVar7 = *(int *)(param_2 + 4);
    if (*(int *)(iVar8 + 8) - *(int *)(iVar8 + 4) >> 2 == 1) {
      a4 = *param_4;
      a3 = param_6;
      iVar9 = ((int (*)())TIntermediate__removeMatrixConstNode)(this,param_2,param_3,param_6,a4);
      if (iVar9 == 0) {
        iVar9 = 0;
        puVar13 = PTR_vtable_a7b7c0c8 + 8;
        while( true ) {
          (**(code **)(*(int *)param_6 + 0x38))(local_b0,param_6);
          if ((local_8c & 0x400) == 0) {
            iVar6 = (int)(local_8c << 0xd | local_8c >> 0x13) >> 0x18;
          }
          else {
            iVar6 = (int)(local_8c << 0xd | local_8c >> 0x13) >> 0x18;
            iVar6 = iVar6 * iVar6;
          }
          local_b0[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
          if (iVar6 <= iVar9) break;
          pTVar10 = (unsigned char *)GetGlobalPoolAllocator();
          puVar11 = (undefined4 *)TPoolAllocator__allocate(pTVar10,4);
          iVar9 = iVar9 + 1;
          iVar6 = (**(code **)(*(int *)**(undefined4 **)(iVar8 + 4) + 0x18))
                            ((int *)**(undefined4 **)(iVar8 + 4));
          *puVar11 = **(undefined4 **)(iVar6 + 0x30);
          pTVar10 = (unsigned char *)GetGlobalPoolAllocator();
          uVar14 = TPoolAllocator__allocate(pTVar10,0x34);
          a0 = (int *)((ulonglong)uVar14 >> 0x20);
          iVar6 = *(int *)**(undefined4 **)(iVar8 + 4);
          a1 = (int *)(**(code **)(iVar6 + 0x18))
                                ((int *)**(undefined4 **)(iVar8 + 4),(int)uVar14,param_3,a3,a4,a5,
                                 iVar6);
          (**(code **)(*a1 + 0x38))(&local_80,a1);
          *a0 = (int)&PTR_getLine_a7b7cf90;
          a0[1] = 0;
          a0[3] = local_7c;
          a0[4] = local_78;
          a0[5] = local_74;
          a0[6] = local_70;
          a0[7] = local_6c;
          a0[8] = local_68;
          a0[2] = (int)&PTR___ZN5TTypeD1Ev_a7b7cff8;
          a0[9] = local_64;
          a0[10] = local_60;
          uVar5 = a0[0xb];
          uVar2 = local_5c & 0xfe000000;
          a0[0xb] = uVar2 | uVar5 & 0x1ffffff;
          uVar3 = (local_5c >> 0x13 & 0x3f) << 0x13;
          a0[0xb] = uVar3 | uVar2 | uVar5 & 0x7ffff;
          uVar1 = local_5c & 0x7f800;
          a0[0xb] = uVar1 | uVar3 | uVar2 | uVar5 & 0x7ff;
          uVar4 = (local_5c >> 10 & 1) << 10;
          a0[0xb] = uVar4 | uVar1 | uVar3 | uVar2 | uVar5 & 0x3ff;
          a0[0xb] = (local_5c >> 9 & 1) << 9 | uVar4 | uVar1 | uVar3 | uVar2 | uVar5 & 0x1ff;
          a0[0xc] = (int)puVar11;
          *a0 = (int)puVar13;
          local_80 = &PTR___ZN5TTypeD1Ev_a7b7cff8;
          iVar6 = *a0;
          a1_00 = (*(code *)**(undefined4 **)param_6)(param_6,a1_01,param_3,a3,a4,a5,a0 + 2);
          (**(code **)(iVar6 + 4))(a0,a1_00);
          param_3 = (unsigned char *)(*(int *)(param_2 + 4) + *param_4 * 4);
          a3 = (unsigned char *)local_4c;
          *(unsigned char **)param_5 = param_3;
          local_4c[0] = a0;
          std__vector_TIntermNode__pool_allocator_TIntermNode_____insert
                    (&local_50,param_2,param_3,a3);
        }
      }
    }
    else {
      std__vector_TIntermNode__pool_allocator_TIntermNode______M_range_insert___gnu_cxx____normal_iterator_TIntermNode___std__vector_TIntermNode__pool_allocator_TIntermNode_____
                (param_2,*(undefined4 *)param_5,*(int *)(iVar8 + 4),*(int *)(iVar8 + 8));
    }
    iVar7 = (*param_4 + (*(int *)(param_2 + 8) - *(int *)(param_2 + 4) >> 2)) -
            (iVar12 - iVar7 >> 2);
    *param_4 = iVar7;
    iVar7 = *(int *)(param_2 + 4) + iVar7 * 4;
    *(int *)param_5 = iVar7;
    std__vector_TIntermNode__pool_allocator_TIntermNode_____erase(&local_50,param_2,iVar7);
    *(undefined4 *)param_5 = local_50;
    *param_4 = *param_4 + -1;
    *(int *)param_5 = *(int *)param_5 + -4;
  }
  return;
}

/* __ZN13TIntermediate15removeChildNodeEP12TIntermTypedP5TTypeP16TIntermAggregate @ 0x97b96820 (496 bytes) */
int __ZN13TIntermediate15removeChildNodeEP12TIntermTypedP5TTypeP16TIntermAggregate(this, param_2, param_3, param_4)
  void *this;
  unsigned char * param_2;
  unsigned char * param_3;
  unsigned char * param_4;
{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int *a0;
  unsigned char * this_00;
  int iVar4;
  int iVar5;
  undefined4 a1;
  unsigned char * a2;
  unsigned char * a3;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined1 auStack_30 [20];
  
  a2 = param_3;
  a3 = param_4;
  iVar3 = (**(code **)(*(int *)param_3 + 0x30))(param_3,param_2,param_3,param_4);
  if (iVar3 == 1) {
    iVar3 = (**(code **)(*(int *)param_4 + 100))(param_4);
    iVar4 = *(int *)**(undefined4 **)(iVar3 + 4);
    param_2 = (unsigned char *)
              (**(code **)(iVar4 + 0x14))
                        ((int *)**(undefined4 **)(iVar3 + 4),a1,a2,a3,in_r7,in_r8,iVar4);
  }
  else {
    iVar3 = (**(code **)(*(int *)param_3 + 0x30))(param_3);
    a0 = (int *)(**(code **)(*(int *)param_2 + 0x1c))(param_2);
    this_00 = (unsigned char *)(**(code **)(*a0 + 100))(a0);
    iVar4 = (**(code **)(*(int *)param_4 + 100))(param_4);
    if (*(int *)(iVar4 + 8) - *(int *)(iVar4 + 4) >> 2 == 1) {
      iVar3 = ((int (*)())TIntermediate__removeMatrixConstNode)(this,(unsigned char *)this_00,param_3,param_4,1);
      if (iVar3 == 0) {
        iVar3 = (**(code **)(*(int *)param_4 + 100))(param_4);
        puVar1 = *(undefined4 **)(this_00 + 8);
        if (puVar1 == *(undefined4 **)(this_00 + 0xc)) {
          std__vector_TIntermNode__pool_allocator_TIntermNode______M_insert_aux
                    (this_00,puVar1,*(undefined4 **)(iVar3 + 4));
        }
        else {
          iVar4 = 0;
          if (puVar1 != (undefined4 *)0x0) {
            *puVar1 = **(undefined4 **)(iVar3 + 4);
            iVar4 = *(int *)(this_00 + 8);
          }
          *(int *)(this_00 + 8) = iVar4 + 4;
        }
      }
    }
    else {
      iVar4 = 0;
      if (0 < iVar3) {
        do {
          iVar5 = (**(code **)(*(int *)param_4 + 100))(param_4);
          puVar1 = *(undefined4 **)(this_00 + 8);
          if (puVar1 == *(undefined4 **)(this_00 + 0xc)) {
            std__vector_TIntermNode__pool_allocator_TIntermNode______M_insert_aux
                      (this_00,puVar1,*(int *)(iVar5 + 4) + iVar4 * 4);
          }
          else {
            iVar2 = 0;
            if (puVar1 != (undefined4 *)0x0) {
              *puVar1 = *(undefined4 *)(*(int *)(iVar5 + 4) + iVar4 * 4);
              iVar2 = *(int *)(this_00 + 8);
            }
            *(int *)(this_00 + 8) = iVar2 + 4;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < iVar3);
      }
    }
    std__vector_TIntermNode__pool_allocator_TIntermNode_____erase
              (auStack_30,this_00,*(undefined4 *)(this_00 + 4));
  }
  return param_2;
}

/* TIntermediate__removeMatrixConstNode @ 0x97b96a10 (776 bytes) */
int TIntermediate__removeMatrixConstNode(this, param_2, param_3, param_4, param_5)
  unsigned char * this;
  unsigned char * param_2;
  unsigned char * param_3;
  unsigned char * param_4;
  int param_5;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  unsigned char * pTVar9;
  undefined4 *puVar10;
  int *a0;
  int *piVar11;
  undefined4 a1;
  undefined4 a1_00;
  unsigned char * a2;
  unsigned char * a3;
  int a4;
  undefined4 in_r8;
  undefined *puVar12;
  int iVar13;
  undefined8 uVar14;
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
  if (param_4 != (unsigned char *)0x0) {
    a2 = param_3;
    a3 = param_4;
    a4 = param_5;
    iVar8 = (**(code **)(*(int *)param_4 + 100))(param_4);
    uVar7 = 0;
    if (*(int *)(param_4 + 0x30) - 0x72U < 3) {
      iVar13 = 0;
      puVar12 = PTR_vtable_a7b7c0c8 + 8;
      while( true ) {
        (**(code **)(*(int *)param_4 + 0x38))(local_b0,param_4);
        if ((local_8c & 0x400) == 0) {
          iVar6 = (int)(local_8c << 0xd | local_8c >> 0x13) >> 0x18;
        }
        else {
          iVar6 = (int)(local_8c << 0xd | local_8c >> 0x13) >> 0x18;
          iVar6 = iVar6 * iVar6;
        }
        local_b0[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
        uVar7 = 1;
        if (iVar6 <= iVar13) break;
        pTVar9 = (unsigned char *)GetGlobalPoolAllocator();
        puVar10 = (undefined4 *)TPoolAllocator__allocate(pTVar9,4);
        (**(code **)(*(int *)param_4 + 0x38))(&local_80,param_4);
        local_80 = &PTR___ZN5TTypeD1Ev_a7b7cff8;
        iVar6 = ((int)(local_5c << 0xd | local_5c >> 0x13) >> 0x18) + 1;
        if (iVar13 == (iVar13 / iVar6) * iVar6) {
          iVar6 = *(int *)**(undefined4 **)(iVar8 + 4);
          iVar6 = (**(code **)(iVar6 + 0x18))
                            ((int *)**(undefined4 **)(iVar8 + 4),a1,a2,a3,a4,in_r8,iVar6);
          *puVar10 = **(undefined4 **)(iVar6 + 0x30);
        }
        else {
          iVar6 = (**(code **)(*(int *)param_3 + 0x20))(param_3);
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
        pTVar9 = (unsigned char *)GetGlobalPoolAllocator();
        uVar14 = TPoolAllocator__allocate(pTVar9,0x34);
        a0 = (int *)((ulonglong)uVar14 >> 0x20);
        piVar11 = (int *)**(undefined4 **)(iVar8 + 4);
        piVar11 = (int *)(**(code **)(*piVar11 + 0x18))
                                   (piVar11,(int)uVar14,a2,a3,a4,in_r8,*(undefined4 **)(iVar8 + 4));
        (**(code **)(*piVar11 + 0x38))(&local_80,piVar11);
        *a0 = (int)&PTR_getLine_a7b7cf90;
        a0[1] = 0;
        a0[3] = local_7c;
        a0[4] = local_78;
        a0[5] = local_74;
        a0[6] = local_70;
        a0[7] = local_6c;
        a0[8] = local_68;
        a0[2] = (int)&PTR___ZN5TTypeD1Ev_a7b7cff8;
        a0[9] = local_64;
        a0[10] = local_60;
        uVar5 = a0[0xb];
        uVar2 = local_5c & 0xfe000000;
        a0[0xb] = uVar2 | uVar5 & 0x1ffffff;
        uVar3 = (local_5c >> 0x13 & 0x3f) << 0x13;
        a0[0xb] = uVar3 | uVar2 | uVar5 & 0x7ffff;
        uVar1 = local_5c & 0x7f800;
        a0[0xb] = uVar1 | uVar3 | uVar2 | uVar5 & 0x7ff;
        uVar4 = (local_5c >> 10 & 1) << 10;
        a0[0xb] = uVar4 | uVar1 | uVar3 | uVar2 | uVar5 & 0x3ff;
        a0[0xb] = (local_5c >> 9 & 1) << 9 | uVar4 | uVar1 | uVar3 | uVar2 | uVar5 & 0x1ff;
        a0[0xc] = (int)puVar10;
        *a0 = (int)puVar12;
        local_80 = &PTR___ZN5TTypeD1Ev_a7b7cff8;
        iVar6 = *a0;
        uVar7 = (*(code *)**(undefined4 **)param_4)(param_4,a1_00,a2,a3,a4,in_r8,a0 + 2);
        (**(code **)(iVar6 + 4))(a0,uVar7);
        a2 = (unsigned char *)(*(int *)(param_2 + 4) + param_5 * 4 + iVar13 * 4);
        a3 = (unsigned char *)local_4c;
        iVar13 = iVar13 + 1;
        local_4c[0] = a0;
        std__vector_TIntermNode__pool_allocator_TIntermNode_____insert(auStack_50,param_2,a2,a3);
      }
    }
  }
  return uVar7;
}

/* TIntermAggregate__addToPragmaTable @ 0x97b96d18 (184 bytes) */
int TIntermAggregate__addToPragmaTable(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  unsigned char * this_00;
  unsigned char * this_01;
  int *piVar1;
  int iVar2;
  
  iVar2 = *(int *)(this + 0x68);
  if (iVar2 != 0) {
    ___eprintf("%s:%u: failed assertion `%s\'\n",
               "/SourceCache/OpenGL/OpenGL-4.7.14/GLProgrammability/glslang/MachineIndependent/Intermediate.cpp"
               ,0x865,"!pragmaTable");
  }
  this_00 = operator_new(0x10);
  this_01 = (unsigned char *)GetGlobalPoolAllocator();
  *(unsigned char **)this_00 = this_01;
  *(int *)(this_00 + 4) = iVar2;
  piVar1 = (int *)TPoolAllocator__allocate(this_01,0x20);
  *(int *)(this_00 + 8) = iVar2;
  *(int **)(this_00 + 4) = piVar1;
  *piVar1 = iVar2;
  *(int *)(*(int *)(this_00 + 4) + 4) = iVar2;
  *(int *)(*(int *)(this_00 + 4) + 8) = *(int *)(this_00 + 4);
  *(int *)(*(int *)(this_00 + 4) + 0xc) = *(int *)(this_00 + 4);
  *(unsigned char
    **)(this + 0x68) = this_00;
  std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string_____operator_(this_00,(unsigned char *)param_2);
  return;
}

/* TType__getCompleteString @ 0x97b96dd0 (276 bytes) */
int TType__getCompleteString(param_1, param_2)
  void *param_1;
  int param_2;
{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  char acStack_90 [112];
  undefined4 local_20 [4];
  
  uVar3 = *(uint *)(param_2 + 0x24);
  pcVar4 = acStack_90;
  if (1 < uVar3 >> 0x19) {
    uVar1 = getQualifierString(uVar3 >> 0x19);
    iVar2 = _sprintf(pcVar4,"%s ",uVar1);
    uVar3 = *(uint *)(param_2 + 0x24);
    pcVar4 = pcVar4 + iVar2;
  }
  if ((uVar3 & 0x200) != 0) {
    iVar2 = _sprintf(pcVar4,"array of ");
    uVar3 = *(uint *)(param_2 + 0x24);
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
  uVar3 = *(uint *)(param_2 + 0x24);
  pcVar4 = pcVar4 + iVar2;
LAB_97b96e98:
  uVar1 = TType__getBasicString(uVar3 >> 0x13 & 0x3f);
  _sprintf(pcVar4,"%s",uVar1);
  local_20[0] = GetGlobalPoolAllocator();
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
            (param_1,acStack_90,(unsigned char *)local_20);
  return param_1;
}

/* OutputTreeText @ 0x97b96ee4 (240 bytes) */
int OutputTreeText(param_1, param_2, param_3)
  unsigned char * param_1;
  unsigned char * param_2;
  int param_3;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint a1;
  char in_RESERVE;
  byte bVar5;
  int local_80 [4];
  char acStack_70 [64];
  unsigned char aaStack_30 [28];
  
  uVar4 = (*(code *)**(undefined4 **)param_2)(param_2,param_2,param_3);
  a1 = uVar4 & 0xffff;
  bVar5 = (a1 == 0) << 1;
  if (a1 == 0) {
    _sprintf(acStack_70,"%d:? ",(int)uVar4 >> 0x10);
  }
  else {
    _sprintf(acStack_70,"%d:%d",(int)uVar4 >> 0x10,a1);
  }
  __ZNSsC1EPKcRKSaIcE(local_80,acStack_70,aaStack_30);
  __ZN13TInfoSinkBase6appendERKSs(param_1 + 8,(unsigned char *)local_80);
  piVar2 = (int *)(local_80[0] + -4);
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = iVar1;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar3 < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(local_80[0] + -0xc),acStack_70);
  }
  if (0 < param_3) {
    do {
      __ZN13TInfoSinkBase6appendEPKc(param_1 + 8,"  ");
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}

/* OutputSymbol @ 0x97b96fd4 (268 bytes) */
int OutputSymbol(param_1, param_2, param_3, param_4, param_5, param_6)
  unsigned char * param_1;
  unsigned char * param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  undefined1 *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 a1;
  undefined4 a1_00;
  int a2;
  int a6;
  undefined4 uVar6;
  char in_RESERVE;
  byte in_cr0;
  char acStack_b0 [112];
  undefined4 local_40;
  int local_3c;
  undefined4 local_30 [7];
  
  a2 = *(int *)(param_2 + 0x20);
  ((int (*)())OutputTreeText)(*(unsigned char **)(param_2 + 0x30),(unsigned char *)param_1,a2);
  ((int (*)())TType__getCompleteString)(&local_40,param_1 + 8);
  iVar3 = local_3c;
  puVar1 = DAT_a7b7b9e0;
  *(undefined1 *)(local_3c + *(int *)(local_3c + -0xc)) = *DAT_a7b7b9e0;
  iVar4 = (**(code **)(*(int *)param_1 + 0x60))(param_1,a1,a2,param_4,param_5,param_6,local_3c);
  a6 = *(int *)(iVar4 + 4);
  *(undefined1 *)(a6 + *(int *)(a6 + -0xc)) = *puVar1;
  uVar6 = *(undefined4 *)(iVar4 + 4);
  uVar5 = (**(code **)(*(int *)param_1 + 0x5c))(param_1,a1_00,a2,param_4,param_5,param_6,a6,iVar4);
  _sprintf(acStack_b0,"\'%s\' (%s) id: %d\n",uVar6,iVar3,uVar5);
  piVar2 = (int *)(local_3c + -4);
  local_30[0] = local_40;
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      iVar4 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = iVar4;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar3 < 1) {
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
              ((unsigned char *)(local_3c + -0xc),local_30);
  }
  __ZN13TInfoSinkBase6appendEPKc((void *)(*(int *)(param_2 + 0x30) + 8),acStack_b0);
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
  char *pcVar4;
  unsigned char * pTVar5;
  char in_RESERVE;
  byte in_cr0;
  undefined4 local_30;
  int local_2c;
  undefined4 local_20 [5];
  
  pTVar5 = *(unsigned char **)(param_3 + 0x30);
  ((int (*)())OutputTreeText)(pTVar5,(unsigned char *)param_2,*(int *)(param_3 + 0x20));
  if (*(int *)(param_2 + 0x30) == 0x15) {
    pcVar4 = "Multiply";
  }
  else {
    pcVar4 = *(char **)(PTR__operatorStrings_a7b7c0b0 + *(int *)(param_2 + 0x30) * 4);
  }
  pTVar5 = pTVar5 + 8;
  __ZN13TInfoSinkBase6appendEPKc(pTVar5,pcVar4);
  __ZN13TInfoSinkBase6appendEPKc(pTVar5," (");
  ((int (*)())TType__getCompleteString)(&local_30,param_2 + 8);
  __ZN13TInfoSinkBase6appendERKSbIcSt11char_traitsIcE14pool_allocatorIcEE
            (pTVar5,(unsigned char *)&local_30);
  __ZN13TInfoSinkBase6appendEPKc(pTVar5,")");
  piVar2 = (int *)(local_2c + -4);
  local_20[0] = local_30;
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar3 < 1) {
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
              ((unsigned char *)(local_2c + -0xc),local_20);
  }
  __ZN13TInfoSinkBase6appendEPKc(pTVar5,"\n");
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
  unsigned char * this;
  char in_RESERVE;
  byte in_cr0;
  undefined4 local_30;
  int local_2c;
  undefined4 local_20 [4];
  
  this = *(unsigned char **)(param_3 + 0x30) + 8;
  ((int (*)())OutputTreeText)(*(unsigned char **)(param_3 + 0x30),(unsigned char *)param_2,*(int *)(param_3 + 0x20));
  __ZN13TInfoSinkBase6appendEPKc
            (this,*(char **)(PTR__operatorStrings_a7b7c0b0 + *(int *)(param_2 + 0x30) * 4));
  __ZN13TInfoSinkBase6appendEPKc(this," (");
  ((int (*)())TType__getCompleteString)(&local_30,param_2 + 8);
  __ZN13TInfoSinkBase6appendERKSbIcSt11char_traitsIcE14pool_allocatorIcEE(this,(unsigned char *)&local_30);
  __ZN13TInfoSinkBase6appendEPKc(this,")");
  piVar2 = (int *)(local_2c + -4);
  local_20[0] = local_30;
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar3 < 1) {
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
              ((unsigned char *)(local_2c + -0xc),local_20);
  }
  __ZN13TInfoSinkBase6appendEPKc(this,"\n");
  return 1;
}

/* OutputAggregate @ 0x97b972b8 (80 bytes) */
int OutputAggregate(param_1, param_2, param_3)
  int param_1;
  unsigned char * param_2;
  unsigned char * param_3;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  unsigned char * pTVar4;
  unsigned char * this;
  char in_RESERVE;
  byte in_cr0;
  undefined4 local_30;
  int local_2c;
  undefined4 local_20 [5];
  
  pTVar4 = *(unsigned char **)(param_3 + 0x30);
  if (*(int *)(param_2 + 0x30) == 0) {
                    
    __ZN13TInfoSinkBase6appendEPKc(pTVar4 + 8,"ERROR: ");
    __ZN13TInfoSinkBase6appendEPKc(pTVar4 + 8,"node is still EOpNull!");
  }
  else {
    ((int (*)())OutputTreeText)(pTVar4,(unsigned char *)param_2,*(int *)(param_3 + 0x20));
    this = pTVar4 + 8;
    __ZN13TInfoSinkBase6appendEPKc
              (this,*(char **)(PTR__operatorStrings_a7b7c0b0 + *(int *)(param_2 + 0x30) * 4));
    if ((*(int *)(param_2 + 0x30) != 1) && (*(int *)(param_2 + 0x30) != 4)) {
      __ZN13TInfoSinkBase6appendEPKc(this," (");
      ((int (*)())TType__getCompleteString)(&local_30,param_2 + 8);
      __ZN13TInfoSinkBase6appendERKSbIcSt11char_traitsIcE14pool_allocatorIcEE
                (this,(unsigned char *)&local_30);
      __ZN13TInfoSinkBase6appendEPKc(this,")");
      piVar2 = (int *)(local_2c + -4);
      local_20[0] = local_30;
      do {
        iVar3 = *piVar2;
        if (in_RESERVE != '\0') {
          iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
          *piVar2 = iVar1;
          in_cr0 = 2;
        }
      } while (!(bool)(in_cr0 >> 1 & 1));
      if (iVar3 < 1) {
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                  ((unsigned char *)(local_2c + -0xc),local_20);
      }
    }
  }
  __ZN13TInfoSinkBase6appendEPKc(pTVar4 + 8,"\n");
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
  unsigned char * this;
  char in_RESERVE;
  byte in_cr0;
  undefined4 local_30;
  int local_2c;
  undefined4 local_20 [4];
  
  this = *(unsigned char **)(param_3 + 0x30) + 8;
  ((int (*)())OutputTreeText)(*(unsigned char **)(param_3 + 0x30),(unsigned char *)param_2,*(int *)(param_3 + 0x20));
  __ZN13TInfoSinkBase6appendEPKc(this,"Test condition and select");
  __ZN13TInfoSinkBase6appendEPKc(this," (");
  ((int (*)())TType__getCompleteString)(&local_30,param_2 + 8);
  __ZN13TInfoSinkBase6appendERKSbIcSt11char_traitsIcE14pool_allocatorIcEE(this,(unsigned char *)&local_30);
  __ZN13TInfoSinkBase6appendEPKc(this,")\n");
  piVar2 = (int *)(local_2c + -4);
  local_20[0] = local_30;
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar3 < 1) {
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
              ((unsigned char *)(local_2c + -0xc),local_20);
  }
  iVar3 = *(int *)(param_3 + 0x20);
  *(int *)(param_3 + 0x20) = iVar3 + 1;
  ((int (*)())OutputTreeText)(*(unsigned char **)(param_3 + 0x30),(unsigned char *)param_2,iVar3 + 1);
  __ZN13TInfoSinkBase6appendEPKc(this,"Condition\n");
  piVar2 = (int *)(**(code **)(*(int *)param_2 + 0x5c))(param_2);
  (**(code **)(*piVar2 + 8))(piVar2,param_3);
  ((int (*)())OutputTreeText)(*(unsigned char **)(param_3 + 0x30),(unsigned char *)param_2,*(int *)(param_3 + 0x20));
  iVar3 = (**(code **)(*(int *)param_2 + 0x60))(param_2);
  if (iVar3 == 0) {
    __ZN13TInfoSinkBase6appendEPKc(this,"true case is null\n");
  }
  else {
    __ZN13TInfoSinkBase6appendEPKc(this,"true case\n");
    piVar2 = (int *)(**(code **)(*(int *)param_2 + 0x60))(param_2);
    (**(code **)(*piVar2 + 8))(piVar2,param_3);
  }
  iVar3 = (**(code **)(*(int *)param_2 + 100))(param_2);
  if (iVar3 != 0) {
    ((int (*)())OutputTreeText)(*(unsigned char **)(param_3 + 0x30),(unsigned char *)param_2,*(int *)(param_3 + 0x20));
    __ZN13TInfoSinkBase6appendEPKc(this,"false case\n");
    piVar2 = (int *)(**(code **)(*(int *)param_2 + 100))(param_2);
    (**(code **)(*piVar2 + 8))(piVar2,param_3);
  }
  *(int *)(param_3 + 0x20) = *(int *)(param_3 + 0x20) + -1;
  return 0;
}

/* OutputConstantUnion @ 0x97b97654 (628 bytes) */
int OutputConstantUnion(param_1, param_2)
  unsigned char * param_1;
  unsigned char * param_2;
{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  undefined **ppuVar4;
  undefined *puVar5;
  undefined4 uVar6;
  undefined4 a1;
  char *pcVar7;
  undefined ***pppuVar8;
  uint a1_00;
  int iVar9;
  unsigned char * pTVar10;
  unsigned char * this;
  char in_RESERVE;
  byte bVar11;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  double in_stack_fffffe08;
  double in_stack_fffffe10;
  double in_stack_fffffe18;
  double in_stack_fffffe20;
  double in_stack_fffffe28;
  undefined **local_1c0 [4];
  char acStack_1b0 [20];
  uint local_19c;
  undefined **local_190 [6];
  int local_178;
  unsigned char aaStack_170 [4];
  uint local_16c;
  char acStack_160 [312];
  
  this = *(unsigned char **)(param_2 + 0x30);
  (**(code **)(*(int *)param_1 + 0x38))(local_1c0,param_1);
  local_1c0[0] = &PTR___ZN5TTypeD1Ev_a7b7d080;
  if ((local_19c >> 0x13 & 0x3f) == 0xe) {
    (**(code **)(*(int *)param_1 + 0x38))(local_190,param_1);
    iVar2 = local_178;
  }
  else {
    (**(code **)(*(int *)param_1 + 0x38))(local_190,param_1);
    if ((local_16c & 0x400) == 0) {
      iVar2 = (int)(local_16c << 0xd | local_16c >> 0x13) >> 0x18;
    }
    else {
      iVar2 = (int)(local_16c << 0xd | local_16c >> 0x13) >> 0x18;
      iVar2 = iVar2 * iVar2;
    }
  }
  local_190[0] = &PTR___ZN5TTypeD1Ev_a7b7d080;
  iVar9 = 0;
  if (0 < iVar2) {
    do {
      ((int (*)())OutputTreeText)(this,(unsigned char *)param_1,*(int *)(param_2 + 0x20));
      uVar6 = (**(code **)(*(int *)param_1 + 0x38))(local_1c0,param_1);
      uVar3 = local_19c >> 0x13 & 0x3f;
      local_1c0[0] = &PTR___ZN5TTypeD1Ev_a7b7d080;
      if (uVar3 == 2) {
        _sprintf((char *)local_1c0,"%d (%s)",*(undefined4 *)(*(int *)(param_1 + 0x30) + iVar9 * 4),
                 "const int");
        pppuVar8 = local_1c0;
LAB_97b977f0:
        __ZN13TInfoSinkBase6appendEPKc(this + 8,(char *)pppuVar8);
LAB_97b977f8:
        pTVar10 = this + 8;
      }
      else {
        if (uVar3 < 3) {
          if (uVar3 == 1) {
            ((char * (*)())_glp_dtostr)(uVar6,a1,acStack_160,300,
                        (double)*(float *)(*(int *)(param_1 + 0x30) + iVar9 * 4),DOUBLE_97c30a70,
                        in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,in_stack_fffffe08,in_stack_fffffe10,
                        in_stack_fffffe18,in_stack_fffffe20,in_stack_fffffe28);
            _sprintf(acStack_160,"%s (%s)",acStack_160,"const float");
            __ZN13TInfoSinkBase6appendEPKc(this + 8,acStack_160);
            goto LAB_97b977f8;
          }
        }
        else if (uVar3 == 3) {
          if (*(int *)(*(int *)(param_1 + 0x30) + iVar9 * 4) == 0) {
            pcVar7 = "false";
          }
          else {
            pcVar7 = "true";
          }
          pTVar10 = this + 8;
          __ZN13TInfoSinkBase6appendEPKc(pTVar10,pcVar7);
          __ZN13TInfoSinkBase6appendEPKc(pTVar10," (");
          __ZN13TInfoSinkBase6appendEPKc(pTVar10,"const bool");
          pppuVar8 = (undefined ***)")";
          goto LAB_97b977f0;
        }
        uVar3 = (*(code *)**(undefined4 **)param_1)(param_1,a1);
                    
        __ZN13TInfoSinkBase6appendEPKc(this,"INTERNAL ERROR: ");
        a1_00 = uVar3 & 0xffff;
        bVar11 = (a1_00 == 0) << 1;
        if (a1_00 == 0) {
          _sprintf(acStack_1b0,"%d:? ",(int)uVar3 >> 0x10);
        }
        else {
          _sprintf(acStack_1b0,"%d:%d",(int)uVar3 >> 0x10,a1_00);
        }
        __ZNSsC1EPKcRKSaIcE(local_1c0,acStack_1b0,aaStack_170);
        *(undefined *)((int)local_1c0[0] + (int)local_1c0[0][-3]) = *PTR__S_terminal_a7b7c0b8;
        __ZN13TInfoSinkBase6appendEPKc(this,(char *)local_1c0[0]);
        ppuVar4 = local_1c0[0] + -1;
        do {
          puVar5 = *ppuVar4;
          if (in_RESERVE != '\0') {
            puVar1 = (undefined *)storeWordConditionalIndexed(puVar5 + -1,0,ppuVar4);
            *ppuVar4 = puVar1;
            bVar11 = 2;
          }
        } while (!(bool)(bVar11 >> 1 & 1));
        if ((int)puVar5 < 1) {
          __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(local_1c0[0] + -3));
        }
        __ZN13TInfoSinkBase6appendEPKc(this,": ");
        __ZN13TInfoSinkBase6appendEPKc(this,"Unknown constant");
        pTVar10 = this;
      }
      iVar9 = iVar9 + 1;
      __ZN13TInfoSinkBase6appendEPKc(pTVar10,"\n");
    } while (iVar9 < iVar2);
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
  unsigned char * this;
  
  this = *(unsigned char **)(param_3 + 0x30) + 8;
  ((int (*)())OutputTreeText)(*(unsigned char **)(param_3 + 0x30),(unsigned char *)param_2,*(int *)(param_3 + 0x20));
  __ZN13TInfoSinkBase6appendEPKc(this,"Loop with condition ");
  if (*(int *)(param_2 + 0x14) == 0) {
    __ZN13TInfoSinkBase6appendEPKc(this,"not ");
  }
  __ZN13TInfoSinkBase6appendEPKc(this,"tested first\n");
  iVar1 = *(int *)(param_3 + 0x20);
  *(int *)(param_3 + 0x20) = iVar1 + 1;
  ((int (*)())OutputTreeText)(*(unsigned char **)(param_3 + 0x30),(unsigned char *)param_2,iVar1 + 1);
  if (*(int *)(param_2 + 0xc) == 0) {
    __ZN13TInfoSinkBase6appendEPKc(this,"No loop condition\n");
  }
  else {
    __ZN13TInfoSinkBase6appendEPKc(this,"Loop Condition\n");
    (**(code **)(**(int **)(param_2 + 0xc) + 8))(*(int **)(param_2 + 0xc),param_3);
  }
  ((int (*)())OutputTreeText)(*(unsigned char **)(param_3 + 0x30),(unsigned char *)param_2,*(int *)(param_3 + 0x20));
  if (*(int *)(param_2 + 8) == 0) {
    __ZN13TInfoSinkBase6appendEPKc(this,"No loop body\n");
  }
  else {
    __ZN13TInfoSinkBase6appendEPKc(this,"Loop Body\n");
    (**(code **)(**(int **)(param_2 + 8) + 8))(*(int **)(param_2 + 8),param_3);
  }
  if (*(int *)(param_2 + 0x10) != 0) {
    ((int (*)())OutputTreeText)(*(unsigned char **)(param_3 + 0x30),(unsigned char *)param_2,*(int *)(param_3 + 0x20));
    __ZN13TInfoSinkBase6appendEPKc(this,"Loop Terminal Expression\n");
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
  unsigned char * this;
  
  this = *(unsigned char **)(param_3 + 0x30) + 8;
  ((int (*)())OutputTreeText)(*(unsigned char **)(param_3 + 0x30),(unsigned char *)param_2,*(int *)(param_3 + 0x20));
  __ZN13TInfoSinkBase6appendEPKc
            (this,*(char **)(PTR__operatorStrings_a7b7c0b0 + *(int *)(param_2 + 8) * 4));
  if (*(int *)(param_2 + 0xc) == 0) {
    __ZN13TInfoSinkBase6appendEPKc(this,"\n");
  }
  else {
    __ZN13TInfoSinkBase6appendEPKc(this," with expression\n");
    *(int *)(param_3 + 0x20) = *(int *)(param_3 + 0x20) + 1;
    (**(code **)(**(int **)(param_2 + 0xc) + 8))(*(int **)(param_2 + 0xc),param_3);
    *(int *)(param_3 + 0x20) = *(int *)(param_3 + 0x20) + -1;
  }
  return 0;
}

/* TIntermediate__outputTree @ 0x97b97c5c (228 bytes) */
int TIntermediate__outputTree(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
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
  
  if (param_2 != (unsigned char *)0x0) {
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
    __ZN13TInfoSinkBase6appendEPKc
              ((void *)(local_20 + 8),"\nIntermediate Parse Tree\n========================\n");
    local_28 = 1;
    local_2c = 1;
    (**(code **)(*(int *)param_2 + 8))(param_2,&local_50);
  }
  return;
}

/* TIntermSymbol__traverse @ 0x97b97d40 (20 bytes) */
int TIntermSymbol__traverse(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  if (*(code **)param_2 == (code *)0x0) {
    return;
  }
                    
                    
  (**(code **)param_2)(this,param_2);
  return;
}

/* TIntermConstantUnion__traverse @ 0x97b97d54 (20 bytes) */
int TIntermConstantUnion__traverse(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  if (*(code **)(param_2 + 4) == (code *)0x0) {
    return;
  }
                    
                    
  (**(code **)(param_2 + 4))(this);
  return;
}

/* TIntermBinary__traverse @ 0x97b97d68 (324 bytes) */
int TIntermBinary__traverse(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  int iVar1;
  int *piVar2;
  
  iVar1 = 1;
  if ((*(int *)(param_2 + 0x24) != 0) && (*(code **)(param_2 + 8) != (code *)0x0)) {
    iVar1 = (**(code **)(param_2 + 8))(1,this,param_2);
  }
  if (iVar1 != 0) {
    *(int *)(param_2 + 0x20) = *(int *)(param_2 + 0x20) + 1;
    if (*(int *)(param_2 + 0x2c) == 0) {
      piVar2 = *(int **)(this + 0x34);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2,param_2);
      }
      piVar2 = *(int **)(this + 0x38);
    }
    else {
      piVar2 = *(int **)(this + 0x38);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2,param_2);
      }
      piVar2 = *(int **)(this + 0x34);
    }
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2,param_2);
    }
    *(int *)(param_2 + 0x20) = *(int *)(param_2 + 0x20) + -1;
    if ((*(int *)(param_2 + 0x28) != 0) && (*(code **)(param_2 + 8) != (code *)0x0)) {
                    
                    
      (**(code **)(param_2 + 8))(0,this,param_2);
      return;
    }
  }
  return;
}

/* TIntermUnary__traverse @ 0x97b97eac (240 bytes) */
int TIntermUnary__traverse(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  int iVar1;
  
  if (((*(int *)(param_2 + 0x24) == 0) || (*(code **)(param_2 + 0xc) == (code *)0x0)) ||
     (iVar1 = (**(code **)(param_2 + 0xc))(1,this,param_2), iVar1 != 0)) {
    *(int *)(param_2 + 0x20) = *(int *)(param_2 + 0x20) + 1;
    (**(code **)(**(int **)(this + 0x34) + 8))(*(int **)(this + 0x34),param_2);
    *(int *)(param_2 + 0x20) = *(int *)(param_2 + 0x20) + -1;
    if ((*(int *)(param_2 + 0x28) != 0) && (*(code **)(param_2 + 0xc) != (code *)0x0)) {
                    
                    
      (**(code **)(param_2 + 0xc))(0,this,param_2);
      return;
    }
  }
  return;
}

/* TIntermAggregate__traverse @ 0x97b97f9c (292 bytes) */
int TIntermAggregate__traverse(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = 1;
  if ((*(int *)(param_2 + 0x24) != 0) && (*(code **)(param_2 + 0x14) != (code *)0x0)) {
    iVar1 = (**(code **)(param_2 + 0x14))(1,this,param_2);
  }
  if (iVar1 != 0) {
    *(int *)(param_2 + 0x20) = *(int *)(param_2 + 0x20) + 1;
    if (*(int *)(param_2 + 0x2c) == 0) {
      for (puVar2 = *(undefined4 **)(this + 0x38); puVar2 != *(undefined4 **)(this + 0x3c);
          puVar2 = puVar2 + 1) {
        (**(code **)(*(int *)*puVar2 + 8))((int *)*puVar2,param_2);
      }
    }
    else {
      puVar2 = *(undefined4 **)(this + 0x3c);
      while (puVar2 != *(undefined4 **)(this + 0x38)) {
        puVar2 = puVar2 + -1;
        (**(code **)(*(int *)*puVar2 + 8))((int *)*puVar2,param_2);
      }
    }
    *(int *)(param_2 + 0x20) = *(int *)(param_2 + 0x20) + -1;
    if ((*(int *)(param_2 + 0x28) != 0) && (*(code **)(param_2 + 0x14) != (code *)0x0)) {
      (**(code **)(param_2 + 0x14))(0,this,param_2);
    }
  }
  return;
}

/* TIntermSelection__traverse @ 0x97b980c0 (388 bytes) */
int TIntermSelection__traverse(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  int iVar1;
  int *piVar2;
  
  iVar1 = 1;
  if ((*(int *)(param_2 + 0x24) != 0) && (*(code **)(param_2 + 0x10) != (code *)0x0)) {
    iVar1 = (**(code **)(param_2 + 0x10))(1,this,param_2);
  }
  if (iVar1 == 0) {
    return;
  }
  *(int *)(param_2 + 0x20) = *(int *)(param_2 + 0x20) + 1;
  if (*(int *)(param_2 + 0x2c) == 0) {
    (**(code **)(**(int **)(this + 0x30) + 8))(*(int **)(this + 0x30),param_2);
    piVar2 = *(int **)(this + 0x34);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2,param_2);
    }
    piVar2 = *(int **)(this + 0x38);
    if (piVar2 == (int *)0x0) goto LAB_97b981d4;
    iVar1 = *piVar2;
  }
  else {
    piVar2 = *(int **)(this + 0x38);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2,param_2);
    }
    piVar2 = *(int **)(this + 0x34);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2,param_2);
    }
    piVar2 = *(int **)(this + 0x30);
    iVar1 = *piVar2;
  }
  (**(code **)(iVar1 + 8))(piVar2,param_2);
LAB_97b981d4:
  *(int *)(param_2 + 0x20) = *(int *)(param_2 + 0x20) + -1;
  if ((*(int *)(param_2 + 0x28) != 0) && (*(code **)(param_2 + 0x10) != (code *)0x0)) {
                    
                    
    (**(code **)(param_2 + 0x10))(0,this,param_2);
    return;
  }
  return;
}

/* TIntermLoop__traverse @ 0x97b98244 (388 bytes) */
int TIntermLoop__traverse(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  int iVar1;
  int *piVar2;
  
  iVar1 = 1;
  if ((*(int *)(param_2 + 0x24) != 0) && (*(code **)(param_2 + 0x18) != (code *)0x0)) {
    iVar1 = (**(code **)(param_2 + 0x18))(1,this,param_2);
  }
  if (iVar1 != 0) {
    *(int *)(param_2 + 0x20) = *(int *)(param_2 + 0x20) + 1;
    if (*(int *)(param_2 + 0x2c) == 0) {
      piVar2 = *(int **)(this + 0xc);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2,param_2);
      }
      piVar2 = *(int **)(this + 8);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2,param_2);
      }
      piVar2 = *(int **)(this + 0x10);
    }
    else {
      piVar2 = *(int **)(this + 0x10);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2,param_2);
      }
      piVar2 = *(int **)(this + 8);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2,param_2);
      }
      piVar2 = *(int **)(this + 0xc);
    }
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2,param_2);
    }
    *(int *)(param_2 + 0x20) = *(int *)(param_2 + 0x20) + -1;
    if ((*(int *)(param_2 + 0x28) != 0) && (*(code **)(param_2 + 0x18) != (code *)0x0)) {
                    
                    
      (**(code **)(param_2 + 0x18))(0,this,param_2);
      return;
    }
  }
  return;
}

/* TIntermBranch__traverse @ 0x97b983c8 (216 bytes) */
int TIntermBranch__traverse(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  int iVar1;
  
  iVar1 = 1;
  if ((*(int *)(param_2 + 0x24) != 0) && (*(code **)(param_2 + 0x1c) != (code *)0x0)) {
    iVar1 = (**(code **)(param_2 + 0x1c))(1,this,param_2);
  }
  if (iVar1 != 0) {
    if (*(int *)(this + 0xc) != 0) {
      *(int *)(param_2 + 0x20) = *(int *)(param_2 + 0x20) + 1;
      (**(code **)(**(int **)(this + 0xc) + 8))(*(int **)(this + 0xc),param_2);
      *(int *)(param_2 + 0x20) = *(int *)(param_2 + 0x20) + -1;
    }
    if ((*(int *)(param_2 + 0x28) != 0) && (*(code **)(param_2 + 0x1c) != (code *)0x0)) {
                    
                    
      (**(code **)(param_2 + 0x1c))(0,this,param_2);
      return;
    }
  }
  return;
}

/* ParseSymbol @ 0x97b984a0 (332 bytes) */
int ParseSymbol(param_1, param_2)
  unsigned char * param_1;
  unsigned char * param_2;
{
  bool bVar1;
  undefined *puVar2;
  int *piVar3;
  undefined **ppuVar4;
  undefined *puVar5;
  undefined4 uVar6;
  unsigned char * this;
  uint uVar7;
  int iVar8;
  undefined4 a1;
  undefined4 extraout_r4;
  undefined ***pppuVar9;
  uint uVar10;
  int iVar11;
  int a0;
  int iVar12;
  int iVar13;
  int iVar14;
  void *pvVar15;
  int iVar16;
  int iVar17;
  char in_RESERVE;
  byte in_cr0;
  byte bVar18;
  double dVar19;
  undefined8 uVar20;
  undefined **local_1b0;
  int local_1ac;
  unsigned char aaStack_1a0 [20];
  uint local_18c;
  undefined **appuStack_180 [8];
  unsigned char aaStack_160 [128];
  char *apcStack_e0 [4];
  char acStack_d0 [32];
  undefined **local_b0 [4];
  char acStack_a0 [16];
  unsigned char aaStack_90 [48];
  int local_60 [2];
  longlong local_58;
  undefined4 local_50;
  uint uStack_4c;
  
  (**(code **)(*(int *)param_1 + 0x38))(&local_1b0,param_1);
  uVar10 = *(uint *)(param_2 + 0x60);
  local_1b0 = &PTR___ZN5TTypeD1Ev_a7b7d488;
  iVar12 = *(int *)(param_2 + 0x34);
  if ((uVar10 >> 0x13 & 0x3f) == 0xe) {
    iVar13 = *(int *)(param_2 + 0x54);
  }
  else {
    bVar1 = (uVar10 & 0x400) == 0;
    in_cr0 = bVar1 << 1;
    if (bVar1) {
      iVar13 = (int)(uVar10 << 0xd | uVar10 >> 0x13) >> 0x18;
    }
    else {
      iVar13 = (int)(uVar10 << 0xd | uVar10 >> 0x13) >> 0x18;
      iVar13 = iVar13 * iVar13;
    }
  }
  if (*(int *)(param_2 + 0x30) < iVar13) {
    if (local_18c >> 0x19 == 2) {
      piVar3 = *(int **)(param_2 + 0x70);
      uVar6 = (**(code **)(*(int *)param_1 + 0x60))(param_1,a1);
      iVar11 = *piVar3;
      iVar17 = (piVar3[1] - iVar11 >> 2) + -1;
      while( true ) {
        iVar16 = *(int *)(iVar11 + iVar17 * 4);
        iVar11 = 0;
        std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______find((unsigned char *)local_60,iVar16,uVar6);
        if (local_60[0] != *(int *)(iVar16 + 4)) {
          iVar11 = *(int *)(local_60[0] + 0x18);
        }
        iVar17 = iVar17 + -1;
        if ((iVar11 != 0) || (iVar17 < 0)) break;
        iVar11 = *piVar3;
      }
      uVar20 = CONCAT44(*(int *)(iVar11 + 0x38),extraout_r4);
      if (*(int *)(iVar11 + 0x38) == 0) {
        if (*(int *)(iVar11 + 0x14) == 0) {
          uVar10 = *(uint *)(iVar11 + 0x30);
          if ((uVar10 & 0x400) == 0) {
            iVar17 = (int)(uVar10 << 0xd | uVar10 >> 0x13) >> 0x18;
          }
          else {
            iVar17 = (int)(uVar10 << 0xd | uVar10 >> 0x13) >> 0x18;
            iVar17 = iVar17 * iVar17;
          }
        }
        else {
          iVar17 = *(int *)(iVar11 + 0x24);
        }
        this = (unsigned char *)GetGlobalPoolAllocator();
        uVar20 = TPoolAllocator__allocate(this,iVar17 << 2);
        *(int *)(iVar11 + 0x38) = (int)((ulonglong)uVar20 >> 0x20);
      }
      iVar17 = (int)((ulonglong)uVar20 >> 0x20);
      if (iVar17 != 0) {
        a0 = iVar11 + 0xc;
        iVar16 = (**(code **)(*(int *)(iVar11 + 0xc) + 0x20))(a0,(int)uVar20);
        if (iVar16 == 0xe) {
          iVar16 = *(int *)(iVar11 + 0x24);
        }
        else {
          iVar16 = (**(code **)(*(int *)(iVar11 + 0xc) + 0x30))(a0);
        }
        iVar14 = 0;
        if (iVar16 < 1) {
          return;
        }
        do {
          if (iVar13 <= *(int *)(param_2 + 0x30)) {
            return;
          }
          uVar7 = (**(code **)(*(int *)(iVar11 + 0xc) + 0x20))(a0);
          uVar10 = *(uint *)(param_2 + 0x60) >> 0x13 & 0x3f;
          if ((uVar7 == uVar10) || (uVar10 == 0xe)) {
code_r0x97b98c14:
            *(undefined4 *)(iVar12 + *(int *)(param_2 + 0x30) * 4) =
                 *(undefined4 *)(iVar14 * 4 + iVar17);
          }
          else {
            iVar8 = (**(code **)(*(int *)(iVar11 + 0xc) + 0x20))(a0);
            if (iVar8 == 2) {
              uVar10 = *(uint *)(param_2 + 0x60) >> 0x13 & 0x3f;
              if (uVar10 == 1) {
                uStack_4c = *(uint *)(iVar14 * 4 + iVar17) ^ 0x80000000;
                dVar19 = DOUBLE_97c30a58;
code_r0x97b98bfc:
                local_50 = 0x43300000;
                *(float *)(iVar12 + *(int *)(param_2 + 0x30) * 4) =
                     (float)((double)CONCAT44(0x43300000,uStack_4c) - dVar19);
              }
              else {
                if (uVar10 != 3) {
                  pvVar15 = *(void **)(param_2 + 0x6c);
                  uVar10 = (*(code *)**(undefined4 **)param_1)(param_1);
                    
                  goto override_jmp_97b98aec_case_0;
                }
                *(uint *)(iVar12 + *(int *)(param_2 + 0x30) * 4) =
                     (uint)(*(int *)(iVar14 * 4 + iVar17) != 0);
              }
            }
            else {
              if (iVar8 < 3) {
                if (iVar8 == 1) {
                  uVar10 = *(uint *)(param_2 + 0x60) >> 0x13 & 0x3f;
                  if (uVar10 == 2) {
                    iVar8 = (int)*(float *)(iVar14 * 4 + iVar17);
                    local_58 = (longlong)iVar8;
                    *(int *)(*(int *)(param_2 + 0x30) * 4 + iVar12) = iVar8;
                  }
                  else {
                    if (uVar10 != 3) {
                      pvVar15 = *(void **)(param_2 + 0x6c);
                      uVar10 = (*(code *)**(undefined4 **)param_1)(param_1);
                    
                      goto override_jmp_97b98aec_case_0;
                    }
                    *(uint *)(*(int *)(param_2 + 0x30) * 4 + iVar12) =
                         (uint)((double)*(float *)(iVar14 * 4 + iVar17) != DOUBLE_97c30a48);
                  }
                  goto code_r0x97b98dd8;
                }
              }
              else if (iVar8 == 3) {
                uVar10 = *(uint *)(param_2 + 0x60) >> 0x13 & 0x3f;
                if (uVar10 == 1) {
                  uStack_4c = *(uint *)(iVar14 * 4 + iVar17);
                  dVar19 = DOUBLE_97c30a68;
                  goto code_r0x97b98bfc;
                }
                if (uVar10 != 2) {
                  pvVar15 = *(void **)(param_2 + 0x6c);
                  uVar10 = (*(code *)**(undefined4 **)param_1)(param_1);
                    
                  goto override_jmp_97b98aec_case_0;
                }
                goto code_r0x97b98c14;
              }
              pvVar15 = *(void **)(param_2 + 0x6c);
              uVar10 = (*(code *)**(undefined4 **)param_1)(param_1);
                    
override_jmp_97b98aec_case_0:
              __ZN13TInfoSinkBase6appendEPKc(pvVar15,"INTERNAL ERROR: ");
              uVar7 = uVar10 & 0xffff;
              bVar18 = (uVar7 == 0) << 1;
              if (uVar7 == 0) {
                _sprintf((char *)aaStack_1a0,"%d:? ",(int)uVar10 >> 0x10);
              }
              else {
                _sprintf((char *)aaStack_1a0,"%d:%d",(int)uVar10 >> 0x10,uVar7);
              }
              __ZNSsC1EPKcRKSaIcE(&local_1b0,(char *)aaStack_1a0,aaStack_160);
              *(undefined *)((int)local_1b0 + (int)local_1b0[-3]) = *PTR__S_terminal_a7b7c0b8;
              __ZN13TInfoSinkBase6appendEPKc(pvVar15,(char *)local_1b0);
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
                __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(local_1b0 + -3));
              }
              __ZN13TInfoSinkBase6appendEPKc(pvVar15,": ");
              __ZN13TInfoSinkBase6appendEPKc(pvVar15,"Incorrect type, cannot parse symbol");
              __ZN13TInfoSinkBase6appendEPKc(pvVar15,"\n");
            }
          }
code_r0x97b98dd8:
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
      pvVar15 = *(void **)(param_2 + 0x6c);
      uVar10 = (*(code *)**(undefined4 **)param_1)(param_1);
                    
      __ZN13TInfoSinkBase6appendEPKc(pvVar15,"ERROR: ");
      uVar7 = uVar10 & 0xffff;
      bVar18 = (uVar7 == 0) << 1;
      if (uVar7 == 0) {
        _sprintf(acStack_d0,"%d:? ",(int)uVar10 >> 0x10);
      }
      else {
        _sprintf(acStack_d0,"%d:%d",(int)uVar10 >> 0x10,uVar7);
      }
      __ZNSsC1EPKcRKSaIcE(apcStack_e0,acStack_d0,aaStack_90);
      apcStack_e0[0][*(int *)(apcStack_e0[0] + -0xc)] = *PTR__S_terminal_a7b7c0b8;
      __ZN13TInfoSinkBase6appendEPKc(pvVar15,apcStack_e0[0]);
      piVar3 = (int *)(apcStack_e0[0] + -4);
      do {
        iVar12 = *piVar3;
        if (in_RESERVE != '\0') {
          iVar13 = storeWordConditionalIndexed(iVar12 + -1,0,piVar3);
          *piVar3 = iVar13;
          bVar18 = 2;
        }
      } while (!(bool)(bVar18 >> 1 & 1));
      if (iVar12 < 1) {
        __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(apcStack_e0[0] + -0xc));
      }
      __ZN13TInfoSinkBase6appendEPKc(pvVar15,": ");
      pppuVar9 = &local_1b0;
    }
    else {
      ((int (*)())TType__getCompleteString)(&local_1b0,param_2 + 0x3c);
      pppuVar9 = appuStack_180;
      *(undefined1 *)(local_1ac + *(int *)(local_1ac + -0xc)) = *DAT_a7b7ba10;
      _sprintf((char *)pppuVar9,"\'constructor\' : assigning non-constant to %s",local_1ac);
      piVar3 = (int *)(local_1ac + -4);
      local_b0[0] = local_1b0;
      do {
        iVar12 = *piVar3;
        if (in_RESERVE != '\0') {
          iVar13 = storeWordConditionalIndexed(iVar12 + -1,0,piVar3);
          *piVar3 = iVar13;
          in_cr0 = 2;
        }
      } while (!(bool)(in_cr0 >> 1 & 1));
      if (iVar12 < 1) {
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                  ((unsigned char *)(local_1ac + -0xc),local_b0);
      }
      pvVar15 = *(void **)(param_2 + 0x6c);
      uVar10 = (*(code *)**(undefined4 **)param_1)(param_1);
                    
      __ZN13TInfoSinkBase6appendEPKc(pvVar15,"ERROR: ");
      uVar7 = uVar10 & 0xffff;
      bVar18 = (uVar7 == 0) << 1;
      if (uVar7 == 0) {
        _sprintf(acStack_a0,"%d:? ",(int)uVar10 >> 0x10);
      }
      else {
        _sprintf(acStack_a0,"%d:%d",(int)uVar10 >> 0x10,uVar7);
      }
      __ZNSsC1EPKcRKSaIcE(&local_1b0,acStack_a0,aaStack_1a0);
      *(undefined *)((int)local_1b0 + (int)local_1b0[-3]) = *PTR__S_terminal_a7b7c0b8;
      __ZN13TInfoSinkBase6appendEPKc(pvVar15,(char *)local_1b0);
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
        __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(local_1b0 + -3));
      }
      __ZN13TInfoSinkBase6appendEPKc(pvVar15,": ");
    }
    __ZN13TInfoSinkBase6appendEPKc(pvVar15,(char *)pppuVar9);
    __ZN13TInfoSinkBase6appendEPKc(pvVar15,"\n");
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
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  undefined **ppuVar4;
  int iVar5;
  undefined *puVar6;
  uint uVar7;
  uint uVar8;
  void *pvVar9;
  char in_RESERVE;
  byte in_cr0;
  byte bVar10;
  undefined **local_170;
  int local_16c;
  unsigned char aaStack_160 [20];
  uint local_14c;
  char acStack_140 [32];
  unsigned char aaStack_120 [176];
  undefined **local_70 [4];
  char acStack_60 [72];
  
  (**(code **)(*(int *)param_2 + 0x38))(&local_170,param_2,param_3);
  local_170 = &PTR___ZN5TTypeD1Ev_a7b7d488;
  if (local_14c >> 0x19 == 2) {
    pvVar9 = *(void **)(param_3 + 0x6c);
    uVar7 = (*(code *)**(undefined4 **)param_2)(param_2);
    __ZN13TInfoSinkBase6appendEPKc(pvVar9,"INTERNAL ERROR: ");
    uVar8 = uVar7 & 0xffff;
    bVar10 = (uVar8 == 0) << 1;
    if (uVar8 == 0) {
      _sprintf((char *)aaStack_160,"%d:? ",(int)uVar7 >> 0x10);
    }
    else {
      _sprintf((char *)aaStack_160,"%d:%d",(int)uVar7 >> 0x10,uVar8);
    }
    __ZNSsC1EPKcRKSaIcE(&local_170,(char *)aaStack_160,aaStack_120);
    *(undefined *)((int)local_170 + (int)local_170[-3]) = *PTR__S_terminal_a7b7c0b8;
    __ZN13TInfoSinkBase6appendEPKc(pvVar9,(char *)local_170);
    ppuVar4 = local_170 + -1;
    do {
      puVar6 = *ppuVar4;
      if (in_RESERVE != '\0') {
        puVar2 = (undefined *)storeWordConditionalIndexed(puVar6 + -1,0,ppuVar4);
        *ppuVar4 = puVar2;
        bVar10 = 2;
      }
    } while (!(bool)(bVar10 >> 1 & 1));
    if ((int)puVar6 < 1) {
      __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(local_170 + -3),aaStack_160);
    }
    __ZN13TInfoSinkBase6appendEPKc(pvVar9,": ");
    __ZN13TInfoSinkBase6appendEPKc(pvVar9,"Binary Node found in constant constructor");
    __ZN13TInfoSinkBase6appendEPKc(pvVar9,"\n");
  }
  else {
    ((int (*)())TType__getCompleteString)(&local_170,param_3 + 0x3c);
    *(undefined1 *)(local_16c + *(int *)(local_16c + -0xc)) = *DAT_a7b7ba10;
    _sprintf(acStack_140,"\'constructor\' : assigning non-constant to %s",local_16c);
    piVar3 = (int *)(local_16c + -4);
    local_70[0] = local_170;
    do {
      iVar5 = *piVar3;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar5 + -1,0,piVar3);
        *piVar3 = iVar1;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar5 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_16c + -0xc),local_70);
    }
    pvVar9 = *(void **)(param_3 + 0x6c);
    uVar7 = (*(code *)**(undefined4 **)param_2)(param_2);
    __ZN13TInfoSinkBase6appendEPKc(pvVar9,"ERROR: ");
    uVar8 = uVar7 & 0xffff;
    bVar10 = (uVar8 == 0) << 1;
    if (uVar8 == 0) {
      _sprintf(acStack_60,"%d:? ",(int)uVar7 >> 0x10);
    }
    else {
      _sprintf(acStack_60,"%d:%d",(int)uVar7 >> 0x10,uVar8);
    }
    __ZNSsC1EPKcRKSaIcE(&local_170,acStack_60,aaStack_160);
    *(undefined *)((int)local_170 + (int)local_170[-3]) = *PTR__S_terminal_a7b7c0b8;
    __ZN13TInfoSinkBase6appendEPKc(pvVar9,(char *)local_170);
    ppuVar4 = local_170 + -1;
    do {
      puVar6 = *ppuVar4;
      if (in_RESERVE != '\0') {
        puVar2 = (undefined *)storeWordConditionalIndexed(puVar6 + -1,0,ppuVar4);
        *ppuVar4 = puVar2;
        bVar10 = 2;
      }
    } while (!(bool)(bVar10 >> 1 & 1));
    if ((int)puVar6 < 1) {
      __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(local_170 + -3),aaStack_160);
    }
    __ZN13TInfoSinkBase6appendEPKc(pvVar9,": ");
    __ZN13TInfoSinkBase6appendEPKc(pvVar9,acStack_140);
    __ZN13TInfoSinkBase6appendEPKc(pvVar9,"\n");
    *(undefined4 *)(param_3 + 0x74) = 1;
  }
  return 0;
}

/* FUN_97b9907c @ 0x97b9907c (12 bytes) */
int FUN_97b9907c()
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  char *unaff_r28;
  void *unaff_r29;
  uint unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar5;
  
  __ZN13TInfoSinkBase6appendEPKc(unaff_r29,(char *)(unaff_r31 + 0x8f990));
  bVar1 = (unaff_r30 & 0xffff) == 0;
  bVar5 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8f9d8),(int)unaff_r30 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8f9d0),(int)unaff_r30 >> 0x10);
  }
  __ZNSsC1EPKcRKSaIcE(&STACKARG(0x40),&STACKARG(0x50),(unsigned char *)&STACKARG(0x90));
  (*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40))[*(int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -0xc)] = **(char **)(unaff_r31 + 0xffe32a4);
  __ZN13TInfoSinkBase6appendEPKc(unaff_r29,(*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)));
  piVar3 = (int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar4 < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -0xc));
  }
  __ZN13TInfoSinkBase6appendEPKc(unaff_r29,(char *)(unaff_r31 + 0x8f9e0));
  __ZN13TInfoSinkBase6appendEPKc(unaff_r29,unaff_r28);
  __ZN13TInfoSinkBase6appendEPKc(unaff_r29,(char *)(unaff_r31 + 0x8de24));
  return 0;
}

/* ParseUnary @ 0x97b99198 (196 bytes) */
int ParseUnary(param_1, param_2, param_3)
  int param_1;
  unsigned char * param_2;
  unsigned char * param_3;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint a1;
  void *this;
  char in_RESERVE;
  byte in_cr0;
  byte bVar5;
  char acStack_160 [208];
  char *local_90;
  int local_8c;
  char *local_80 [4];
  char acStack_70 [64];
  unsigned char aaStack_30 [28];
  
  ((int (*)())TType__getCompleteString)(&local_90,param_3 + 0x3c);
  *(undefined1 *)(local_8c + *(int *)(local_8c + -0xc)) = *DAT_a7b7ba10;
  _sprintf(acStack_160,"\'constructor\' : assigning non-constant to \'%s\'",local_8c);
  piVar2 = (int *)(local_8c + -4);
  local_80[0] = local_90;
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar3 < 1) {
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
              ((unsigned char *)(local_8c + -0xc),local_80);
  }
  this = *(void **)(param_3 + 0x6c);
  uVar4 = (*(code *)**(undefined4 **)param_2)(param_2);
  __ZN13TInfoSinkBase6appendEPKc(this,"ERROR: ");
  a1 = uVar4 & 0xffff;
  bVar5 = (a1 == 0) << 1;
  if (a1 == 0) {
    _sprintf(acStack_70,"%d:? ",(int)uVar4 >> 0x10);
  }
  else {
    _sprintf(acStack_70,"%d:%d",(int)uVar4 >> 0x10,a1);
  }
  __ZNSsC1EPKcRKSaIcE(&local_90,acStack_70,aaStack_30);
  local_90[*(int *)(local_90 + -0xc)] = *PTR__S_terminal_a7b7c0b8;
  __ZN13TInfoSinkBase6appendEPKc(this,local_90);
  piVar2 = (int *)(local_90 + -4);
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = iVar1;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar3 < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(local_90 + -0xc));
  }
  __ZN13TInfoSinkBase6appendEPKc(this,": ");
  __ZN13TInfoSinkBase6appendEPKc(this,acStack_160);
  __ZN13TInfoSinkBase6appendEPKc(this,"\n");
  *(undefined4 *)(param_3 + 0x74) = 1;
  return 0;
}

/* FUN_97b99274 @ 0x97b99274 (12 bytes) */
int FUN_97b99274()
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  void *unaff_r27;
  int unaff_r28;
  uint unaff_r29;
  void *unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar5;
  
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(char *)(unaff_r31 + 0x8f5fc));
  bVar1 = (unaff_r29 & 0xffff) == 0;
  bVar5 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x130),(char *)(unaff_r31 + 0x8f644),(int)unaff_r29 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x130),(char *)(unaff_r31 + 0x8f63c),(int)unaff_r29 >> 0x10);
  }
  __ZNSsC1EPKcRKSaIcE(unaff_r27,&STACKARG(0x130),(unsigned char *)&STACKARG(0x170));
  (*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x110))[*(int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x110)) + -0xc)] = **(char **)(unaff_r31 + 0xffe2f10);
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x110)));
  piVar3 = (int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x110)) + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar4 < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x110)) + -0xc));
  }
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(char *)(unaff_r31 + 0x8f64c));
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,&STACKARG(0x40));
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(char *)(unaff_r31 + 0x8da90));
  *(undefined4 *)(unaff_r28 + 0x74) = 1;
  return 0;
}

/* ParseAggregate @ 0x97b99398 (232 bytes) */
int ParseAggregate(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  unsigned char * param_2;
  unsigned char * param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  bool bVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  undefined4 a1;
  unsigned char * a2;
  uint a1_00;
  int iVar5;
  void *this;
  undefined4 *puVar6;
  char in_RESERVE;
  byte in_cr0;
  byte bVar7;
  undefined8 uVar8;
  undefined **local_160 [9];
  uint local_13c;
  undefined **local_130 [6];
  undefined4 local_118;
  uint local_10c;
  char *local_90;
  int local_8c;
  char *local_80 [4];
  char acStack_70 [64];
  unsigned char aaStack_30 [24];
  
  a2 = param_3;
  uVar8 = ((int (*)())TIntermOperator__isConstructor)((unsigned char *)param_2);
  if (((int)((ulonglong)uVar8 >> 0x20) == 0) && (*(int *)(param_2 + 0x30) != 0x25)) {
    ((int (*)())TType__getCompleteString)(&local_90,param_3 + 0x3c);
    *(undefined1 *)(local_8c + *(int *)(local_8c + -0xc)) = *DAT_a7b7ba10;
    _sprintf((char *)local_160,"\'constructor\' : assigning non-constant to \'%s\'",local_8c);
    piVar2 = (int *)(local_8c + -4);
    local_80[0] = local_90;
    do {
      iVar3 = *piVar2;
      if (in_RESERVE != '\0') {
        iVar5 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
        *piVar2 = iVar5;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar3 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_8c + -0xc),local_80);
    }
    this = *(void **)(param_3 + 0x6c);
    uVar4 = (*(code *)**(undefined4 **)param_2)(param_2);
                    
    __ZN13TInfoSinkBase6appendEPKc(this,"ERROR: ");
    a1_00 = uVar4 & 0xffff;
    bVar7 = (a1_00 == 0) << 1;
    if (a1_00 == 0) {
      _sprintf(acStack_70,"%d:? ",(int)uVar4 >> 0x10);
    }
    else {
      _sprintf(acStack_70,"%d:%d",(int)uVar4 >> 0x10,a1_00);
    }
    __ZNSsC1EPKcRKSaIcE(&local_90,acStack_70,aaStack_30);
    local_90[*(int *)(local_90 + -0xc)] = *PTR__S_terminal_a7b7c0b8;
    __ZN13TInfoSinkBase6appendEPKc(this,local_90);
    piVar2 = (int *)(local_90 + -4);
    do {
      iVar3 = *piVar2;
      if (in_RESERVE != '\0') {
        iVar5 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
        *piVar2 = iVar5;
        bVar7 = 2;
      }
    } while (!(bool)(bVar7 >> 1 & 1));
    if (iVar3 < 1) {
      __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(local_90 + -0xc));
    }
    __ZN13TInfoSinkBase6appendEPKc(this,": ");
    __ZN13TInfoSinkBase6appendEPKc(this,(char *)local_160);
    __ZN13TInfoSinkBase6appendEPKc(this,"\n");
  }
  else {
    iVar3 = (**(code **)(*(int *)param_2 + 100))(param_2,(int)uVar8);
    if ((uint)(*(int *)(iVar3 + 8) - *(int *)(iVar3 + 4)) >> 2 != 0) {
      bVar1 = false;
      iVar3 = (**(code **)(*(int *)param_2 + 100))(param_2);
      if (*(int *)(iVar3 + 8) - *(int *)(iVar3 + 4) >> 2 == 1) {
        iVar3 = (**(code **)(*(int *)param_2 + 100))(param_2);
        iVar5 = *(int *)**(undefined4 **)(iVar3 + 4);
        piVar2 = (int *)(**(code **)(iVar5 + 0x14))
                                  ((int *)**(undefined4 **)(iVar3 + 4),a1,a2,param_4,param_5,param_6
                                   ,iVar5);
        iVar3 = (**(code **)(*piVar2 + 0x18))(piVar2);
        if (iVar3 != 0) {
          bVar1 = true;
        }
      }
      if (bVar1) {
        *(undefined4 *)(param_3 + 0x68) = 1;
        *(undefined4 *)(param_3 + 100) = *(undefined4 *)(param_2 + 0x30);
        (**(code **)(*(int *)param_2 + 0x38))
                  (local_160,param_2,a2,param_4,param_5,param_6,*(int *)param_2);
        local_160[0] = &PTR___ZN5TTypeD1Ev_a7b7d488;
        if ((local_13c >> 0x13 & 0x3f) == 0xe) {
          (**(code **)(*(int *)param_2 + 0x38))(local_130,param_2);
          *(undefined4 *)(param_3 + 0x78) = local_118;
        }
        else {
          (**(code **)(*(int *)param_2 + 0x38))(local_130,param_2);
          if ((local_10c & 0x400) == 0) {
            iVar3 = (int)(local_10c << 0xd | local_10c >> 0x13) >> 0x18;
          }
          else {
            iVar3 = (int)(local_10c << 0xd | local_10c >> 0x13) >> 0x18;
            iVar3 = iVar3 * iVar3;
          }
          *(int *)(param_3 + 0x78) = iVar3;
        }
        local_130[0] = &PTR___ZN5TTypeD1Ev_a7b7d488;
        (**(code **)(*(int *)param_2 + 0x38))(local_160,param_2);
        local_160[0] = &PTR___ZN5TTypeD1Ev_a7b7d488;
        if ((local_13c & 0x400) != 0) {
          *(undefined4 *)(param_3 + 0x7c) = 1;
          (**(code **)(*(int *)param_2 + 0x38))
                    (local_130,param_2,a2,param_4,param_5,param_6,local_13c & 0x400);
          local_130[0] = &PTR___ZN5TTypeD1Ev_a7b7d488;
          *(int *)(param_3 + 0x80) = (int)(local_10c << 0xd | local_10c >> 0x13) >> 0x18;
        }
      }
      iVar3 = (**(code **)(*(int *)param_2 + 100))(param_2);
      for (puVar6 = *(undefined4 **)(iVar3 + 4);
          iVar3 = (**(code **)(*(int *)param_2 + 100))(param_2),
          puVar6 != *(undefined4 **)(iVar3 + 8); puVar6 = puVar6 + 1) {
        if (*(int *)(param_2 + 0x30) == 0x25) {
          *(undefined4 *)(param_3 + 0x30) = 0;
        }
        (**(code **)(*(int *)*puVar6 + 8))((int *)*puVar6,param_3);
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
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint a1;
  void *this;
  char in_RESERVE;
  byte bVar5;
  char *apcStack_80 [4];
  char acStack_70 [64];
  unsigned char aaStack_30 [28];
  
  this = *(void **)(param_3 + 0x6c);
  uVar4 = (*(code *)**(undefined4 **)param_2)(param_2,param_2,param_3);
  __ZN13TInfoSinkBase6appendEPKc(this,"INTERNAL ERROR: ");
  a1 = uVar4 & 0xffff;
  bVar5 = (a1 == 0) << 1;
  if (a1 == 0) {
    _sprintf(acStack_70,"%d:? ",(int)uVar4 >> 0x10);
  }
  else {
    _sprintf(acStack_70,"%d:%d",(int)uVar4 >> 0x10,a1);
  }
  __ZNSsC1EPKcRKSaIcE(apcStack_80,acStack_70,aaStack_30);
  apcStack_80[0][*(int *)(apcStack_80[0] + -0xc)] = *PTR__S_terminal_a7b7c0b8;
  __ZN13TInfoSinkBase6appendEPKc(this,apcStack_80[0]);
  piVar2 = (int *)(apcStack_80[0] + -4);
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = iVar1;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar3 < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(apcStack_80[0] + -0xc),acStack_70);
  }
  __ZN13TInfoSinkBase6appendEPKc(this,": ");
  __ZN13TInfoSinkBase6appendEPKc(this,"Selection Node found in constant constructor");
  __ZN13TInfoSinkBase6appendEPKc(this,"\n");
  *(undefined4 *)(param_3 + 0x74) = 1;
  return 0;
}

/* FUN_97b9989c @ 0x97b9989c (12 bytes) */
int FUN_97b9989c()
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int unaff_r27;
  char *unaff_r28;
  uint unaff_r29;
  void *unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar5;
  
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(char *)(unaff_r31 + 0x8ef68));
  bVar1 = (unaff_r29 & 0xffff) == 0;
  bVar5 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8efb0),(int)unaff_r29 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8efa8),(int)unaff_r29 >> 0x10);
  }
  __ZNSsC1EPKcRKSaIcE(&STACKARG(0x40),&STACKARG(0x50),(unsigned char *)&STACKARG(0x90));
  (*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40))[*(int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -0xc)] = **(char **)(unaff_r31 + 0xffe287c);
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)));
  piVar3 = (int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar4 < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -0xc));
  }
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(char *)(unaff_r31 + 0x8efb8));
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,unaff_r28);
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(char *)(unaff_r31 + 0x8d3fc));
  *(undefined4 *)(unaff_r27 + 0x74) = 1;
  return 0;
}

/* ParseConstantUnion @ 0x97b999c0 (1160 bytes) */
int ParseConstantUnion(param_1, param_2, param_3, param_4, param_5, param_6)
  unsigned char * param_1;
  unsigned char * param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  unsigned char * a6;
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
  
  a6 = param_2 + 0x3c;
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
      local_130[0] = &PTR___ZN5TTypeD1Ev_a7b7d488;
      if ((local_10c >> 0x13 & 0x3f) == 0xe) {
        (**(code **)(*(int *)param_1 + 0x38))(local_100,param_1);
      }
      else {
        (**(code **)(*(int *)param_1 + 0x38))(local_100,param_1,param_3,param_4,param_5,param_6,a6);
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
            (**(code **)(*(int *)param_1 + 0x38))
                      (local_130,param_1,param_3,param_4,param_5,param_6,*(int *)param_1);
            if ((local_10c >> 0x13 & 0x3f) == 0xe) {
              bVar3 = true;
              (**(code **)(*(int *)param_1 + 0x38))(local_d0,param_1);
              if (local_b8 < 2) goto LAB_97b99bf0;
LAB_97b99c64:
              bVar4 = true;
              if (bVar1) {
LAB_97b99c70:
                local_70[0] = &PTR___ZN5TTypeD1Ev_a7b7d488;
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
              local_a0[0] = &PTR___ZN5TTypeD1Ev_a7b7d488;
            }
            if (bVar3) {
              local_d0[0] = &PTR___ZN5TTypeD1Ev_a7b7d488;
            }
            local_130[0] = &PTR___ZN5TTypeD1Ev_a7b7d488;
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
          (**(code **)(*(int *)param_1 + 0x38))
                    (local_130,param_1,param_3,param_4,param_5,param_6,*(int *)param_1);
          if ((local_10c >> 0x13 & 0x3f) == 0xe) {
            bVar3 = true;
            (**(code **)(*(int *)param_1 + 0x38))(local_100,param_1);
            if (local_e8 < 2) goto LAB_97b99d78;
LAB_97b99dec:
            bVar4 = true;
            if (bVar1) {
LAB_97b99df8:
              local_a0[0] = &PTR___ZN5TTypeD1Ev_a7b7d488;
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
            local_d0[0] = &PTR___ZN5TTypeD1Ev_a7b7d488;
          }
          if (bVar3) {
            local_100[0] = &PTR___ZN5TTypeD1Ev_a7b7d488;
          }
          local_130[0] = &PTR___ZN5TTypeD1Ev_a7b7d488;
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
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint a1;
  void *this;
  char in_RESERVE;
  byte bVar5;
  char *apcStack_80 [4];
  char acStack_70 [64];
  unsigned char aaStack_30 [28];
  
  this = *(void **)(param_3 + 0x6c);
  uVar4 = (*(code *)**(undefined4 **)param_2)(param_2,param_2,param_3);
  __ZN13TInfoSinkBase6appendEPKc(this,"INTERNAL ERROR: ");
  a1 = uVar4 & 0xffff;
  bVar5 = (a1 == 0) << 1;
  if (a1 == 0) {
    _sprintf(acStack_70,"%d:? ",(int)uVar4 >> 0x10);
  }
  else {
    _sprintf(acStack_70,"%d:%d",(int)uVar4 >> 0x10,a1);
  }
  __ZNSsC1EPKcRKSaIcE(apcStack_80,acStack_70,aaStack_30);
  apcStack_80[0][*(int *)(apcStack_80[0] + -0xc)] = *PTR__S_terminal_a7b7c0b8;
  __ZN13TInfoSinkBase6appendEPKc(this,apcStack_80[0]);
  piVar2 = (int *)(apcStack_80[0] + -4);
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = iVar1;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar3 < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(apcStack_80[0] + -0xc),acStack_70);
  }
  __ZN13TInfoSinkBase6appendEPKc(this,": ");
  __ZN13TInfoSinkBase6appendEPKc(this,"Loop Node found in constant constructor");
  __ZN13TInfoSinkBase6appendEPKc(this,"\n");
  *(undefined4 *)(param_3 + 0x74) = 1;
  return 0;
}

/* FUN_97b99eb8 @ 0x97b99eb8 (12 bytes) */
int FUN_97b99eb8()
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int unaff_r27;
  char *unaff_r28;
  uint unaff_r29;
  void *unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar5;
  
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(char *)(unaff_r31 + 0x8e94c));
  bVar1 = (unaff_r29 & 0xffff) == 0;
  bVar5 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8e994),(int)unaff_r29 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8e98c),(int)unaff_r29 >> 0x10);
  }
  __ZNSsC1EPKcRKSaIcE(&STACKARG(0x40),&STACKARG(0x50),(unsigned char *)&STACKARG(0x90));
  (*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40))[*(int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -0xc)] = **(char **)(unaff_r31 + 0xffe2260);
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)));
  piVar3 = (int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar4 < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -0xc));
  }
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(char *)(unaff_r31 + 0x8e99c));
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,unaff_r28);
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(char *)(unaff_r31 + 0x8cde0));
  *(undefined4 *)(unaff_r27 + 0x74) = 1;
  return 0;
}

/* ParseBranch @ 0x97b99fdc (88 bytes) */
int ParseBranch(param_1, param_2, param_3)
  int param_1;
  unsigned char * param_2;
  unsigned char * param_3;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint a1;
  void *this;
  char in_RESERVE;
  byte bVar5;
  char *apcStack_80 [4];
  char acStack_70 [64];
  unsigned char aaStack_30 [28];
  
  this = *(void **)(param_3 + 0x6c);
  uVar4 = (*(code *)**(undefined4 **)param_2)(param_2,param_2,param_3);
  __ZN13TInfoSinkBase6appendEPKc(this,"INTERNAL ERROR: ");
  a1 = uVar4 & 0xffff;
  bVar5 = (a1 == 0) << 1;
  if (a1 == 0) {
    _sprintf(acStack_70,"%d:? ",(int)uVar4 >> 0x10);
  }
  else {
    _sprintf(acStack_70,"%d:%d",(int)uVar4 >> 0x10,a1);
  }
  __ZNSsC1EPKcRKSaIcE(apcStack_80,acStack_70,aaStack_30);
  apcStack_80[0][*(int *)(apcStack_80[0] + -0xc)] = *PTR__S_terminal_a7b7c0b8;
  __ZN13TInfoSinkBase6appendEPKc(this,apcStack_80[0]);
  piVar2 = (int *)(apcStack_80[0] + -4);
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = iVar1;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar3 < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(apcStack_80[0] + -0xc),acStack_70);
  }
  __ZN13TInfoSinkBase6appendEPKc(this,": ");
  __ZN13TInfoSinkBase6appendEPKc(this,"Branch Node found in constant constructor");
  __ZN13TInfoSinkBase6appendEPKc(this,"\n");
  *(undefined4 *)(param_3 + 0x74) = 1;
  return 0;
}

/* FUN_97b9a04c @ 0x97b9a04c (12 bytes) */
int FUN_97b9a04c()
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int unaff_r27;
  char *unaff_r28;
  uint unaff_r29;
  void *unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar5;
  
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(char *)(unaff_r31 + 0x8e7b8));
  bVar1 = (unaff_r29 & 0xffff) == 0;
  bVar5 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8e800),(int)unaff_r29 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8e7f8),(int)unaff_r29 >> 0x10);
  }
  __ZNSsC1EPKcRKSaIcE(&STACKARG(0x40),&STACKARG(0x50),(unsigned char *)&STACKARG(0x90));
  (*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40))[*(int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -0xc)] = **(char **)(unaff_r31 + 0xffe20cc);
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)));
  piVar3 = (int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar4 < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -0xc));
  }
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(char *)(unaff_r31 + 0x8e808));
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,unaff_r28);
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(char *)(unaff_r31 + 0x8cc4c));
  *(undefined4 *)(unaff_r27 + 0x74) = 1;
  return 0;
}

/* TIntermediate__parseConstTree @ 0x97b9a170 (428 bytes) */
int TIntermediate__parseConstTree(this, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  unsigned char * this;
  int param_2;
  unsigned char * param_3;
  unsigned char * param_4;
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
  unsigned char * local_7c;
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
  if (param_3 != (unsigned char *)0x0) {
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
    local_74 = &PTR___ZN5TTypeD1Ev_a7b7d488;
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
    local_7c = param_4;
    local_4c = param_5;
    local_48 = param_8;
    local_40 = param_6;
    (**(code **)(*(int *)param_3 + 8))
              (param_3,&local_b0,local_60,local_64,local_68,local_6c,DAT_a7b7b9f0,local_70);
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
int TParseContext__parseVectorFields(this, param_2, param_3, param_4, param_5)
  unsigned char * this;
  unsigned char * param_2;
  int param_3;
  unsigned char * param_4;
  int param_5;
{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  char *pcVar6;
  int in_r10;
  int *piVar7;
  int local_24 [8];
  
  iVar2 = *(int *)(*(int *)(param_2 + 4) + -0xc);
  *(int *)(param_4 + 0x10) = iVar2;
  if (iVar2 < 5) {
    in_r10 = 0;
    if (iVar2 < 1) {
      iVar2 = *(int *)(param_4 + 0x10);
    }
    else {
      do {
        iVar2 = *(int *)(param_2 + 4);
        switch(*(char *)(iVar2 + in_r10) + -0x61) {
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
          uVar4 = 0;
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
          local_24[in_r10 + 1] = iVar2;
          *(int *)(param_4 + in_r10 * 4) = iVar2;
          goto LAB_97b9a570;
        case '\x18':
          iVar2 = 0;
LAB_97b9a4bc:
          uVar4 = 1;
          goto LAB_97b9a528;
        case '\x19':
          iVar2 = 0;
LAB_97b9a4dc:
          uVar4 = 2;
          goto LAB_97b9a528;
        }
        uVar4 = 3;
LAB_97b9a528:
        local_24[in_r10 + 1] = iVar2;
        *(undefined4 *)(param_4 + in_r10 * 4) = uVar4;
LAB_97b9a570:
        iVar2 = *(int *)(param_4 + 0x10);
        in_r10 = in_r10 + 1;
      } while (in_r10 < iVar2);
    }
    in_r10 = 0;
    if (0 < iVar2) {
      piVar7 = local_24;
      do {
        iVar3 = *(int *)param_4;
        param_4 = param_4 + 4;
        if (param_3 <= iVar3) {
          iVar3 = *(int *)(param_2 + 4);
          iVar2 = *(int *)(iVar3 + -0xc);
          bVar1 = *DAT_a7b7ba18;
          pcVar5 = "vector field selection out of range";
LAB_97b9a3b8:
          *(byte *)(iVar3 + iVar2) = bVar1;
          pcVar6 = *(char **)(param_2 + 4);
          goto LAB_97b9a560;
        }
        if ((0 < in_r10) && (piVar7[1] != *piVar7)) {
          iVar3 = *(int *)(param_2 + 4);
          iVar2 = *(int *)(iVar3 + -0xc);
          bVar1 = *DAT_a7b7ba18;
          pcVar5 = "illegal - vector component fields not from the same set";
          goto LAB_97b9a3b8;
        }
        in_r10 = in_r10 + 1;
        piVar7 = piVar7 + 1;
      } while (in_r10 < iVar2);
    }
    uVar4 = 1;
  }
  else {
    iVar2 = *(int *)(param_2 + 4);
    iVar3 = *(int *)(iVar2 + -0xc);
LAB_97b9a54c:
    bVar1 = *DAT_a7b7ba18;
    *(byte *)(iVar2 + iVar3) = bVar1;
    pcVar6 = *(char **)(param_2 + 4);
    pcVar5 = "illegal vector field selection";
LAB_97b9a560:
    error((int)this,(char *)param_5,pcVar5,pcVar6,"",param_5,(uint)bVar1,in_r10);
    uVar4 = 0;
  }
  return uVar4;
}

/* TParseContext__parseMatrixFields @ 0x97b9a5e8 (464 bytes) */
int TParseContext__parseMatrixFields(this, param_2, param_3, param_4, param_5)
  unsigned char * this;
  unsigned char * param_2;
  int param_3;
  unsigned char * param_4;
  int param_5;
{
  char cVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  char *pcVar5;
  
  *(undefined4 *)(param_4 + 4) = 0;
  *(undefined4 *)(param_4 + 0xc) = 0xffffffff;
  *(undefined4 *)param_4 = 0;
  *(undefined4 *)(param_4 + 8) = 0xffffffff;
  pcVar5 = *(char **)(param_2 + 4);
  uVar4 = *(uint *)(pcVar5 + -0xc);
  if (uVar4 == 2) {
    iVar2 = (int)*pcVar5;
    if (iVar2 == 0x5f) {
      if (('/' < pcVar5[1]) && (pcVar5[1] < '4')) {
        *(undefined4 *)(param_4 + 4) = 1;
LAB_97b9a738:
        *(int *)(param_4 + 0xc) = *(char *)(*(int *)(param_2 + 4) + 1) + -0x30;
LAB_97b9a74c:
        if ((*(int *)(param_4 + 8) < param_3) && (*(int *)(param_4 + 0xc) < param_3)) {
          return 1;
        }
        uVar4 = (uint)*DAT_a7b7ba18;
        pcVar3 = "matrix field selection out of range";
        *(byte *)(*(int *)(param_2 + 4) + *(int *)(*(int *)(param_2 + 4) + -0xc)) = *DAT_a7b7ba18;
        goto LAB_97b9a790;
      }
LAB_97b9a6a4:
      pcVar5[2] = *DAT_a7b7ba18;
    }
    else {
      cVar1 = pcVar5[1];
      if (cVar1 == '_') {
        if ((0x2f < iVar2) && (iVar2 < 0x34)) {
          *(undefined4 *)param_4 = 1;
          *(int *)(param_4 + 8) = **(char **)(param_2 + 4) + -0x30;
          goto LAB_97b9a74c;
        }
        goto LAB_97b9a6a4;
      }
      if ((((0x2f < iVar2) && (iVar2 < 0x34)) && ('/' < cVar1)) && (cVar1 < '4')) {
        *(int *)(param_4 + 8) = iVar2 + -0x30;
        goto LAB_97b9a738;
      }
      uVar4 = (uint)*DAT_a7b7ba18;
      pcVar5[*(int *)(pcVar5 + -0xc)] = *DAT_a7b7ba18;
    }
    pcVar5 = *(char **)(param_2 + 4);
    pcVar3 = "illegal matrix field selection";
  }
  else {
    pcVar3 = "illegal length of matrix field selection";
    pcVar5[uVar4] = *DAT_a7b7ba18;
LAB_97b9a790:
    pcVar5 = *(char **)(param_2 + 4);
  }
  error((int)this,(char *)param_5,pcVar3,pcVar5,"",this,uVar4,param_5);
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
int TParseContext__error(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  char *param_2;
  char *param_3;
  char *param_4;
  char *param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  unsigned int ghidra_home[8] = { param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  int iVar1;
  int *piVar2;
  int iVar3;
  uint a1;
  void *pvVar4;
  char in_RESERVE;
  byte bVar5;
  char acStack_210 [400];
  char *apcStack_80 [4];
  char acStack_70 [64];
  unsigned char aaStack_30 [24];
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 20)) = param_6;
  (*(unsigned int *)((unsigned char *)ghidra_home + 24)) = param_7;
  (*(unsigned int *)((unsigned char *)ghidra_home + 28)) = param_8;
  _vsnprintf(acStack_210,400,param_5,&(*(unsigned int *)((unsigned char *)ghidra_home + 20)));
  __ZN13TInfoSinkBase6appendEPKc(*(void **)(param_1 + 8),"ERROR: ");
  pvVar4 = *(void **)(param_1 + 8);
  a1 = (uint)param_2 & 0xffff;
  bVar5 = (a1 == 0) << 1;
  if (a1 == 0) {
    _sprintf(acStack_70,"%d:? ",(int)param_2 >> 0x10);
  }
  else {
    _sprintf(acStack_70,"%d:%d",(int)param_2 >> 0x10,a1);
  }
  __ZNSsC1EPKcRKSaIcE(apcStack_80,acStack_70,aaStack_30);
  apcStack_80[0][*(int *)(apcStack_80[0] + -0xc)] = *PTR__S_terminal_a7b7c0b8;
  __ZN13TInfoSinkBase6appendEPKc(pvVar4,apcStack_80[0]);
  piVar2 = (int *)(apcStack_80[0] + -4);
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = iVar1;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar3 < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(apcStack_80[0] + -0xc));
  }
  __ZN13TInfoSinkBase6appendEPKc(pvVar4,": ");
  pvVar4 = *(void **)(param_1 + 8);
  __ZN13TInfoSinkBase6appendEPKc(pvVar4,"\'");
  __ZN13TInfoSinkBase6appendEPKc(pvVar4,param_4);
  __ZN13TInfoSinkBase6appendEPKc(pvVar4,"\' : ");
  __ZN13TInfoSinkBase6appendEPKc(pvVar4,param_3);
  __ZN13TInfoSinkBase6appendEPKc(pvVar4," ");
  __ZN13TInfoSinkBase6appendEPKc(pvVar4,acStack_210);
  __ZN13TInfoSinkBase6appendEPKc(pvVar4,"\n");
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
  return;
}

/* FUN_97b9a844 @ 0x97b9a844 (12 bytes) */
int FUN_97b9a844(param_1)
  void *param_1;
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  char *unaff_r26;
  char *unaff_r27;
  uint unaff_r28;
  void *pvVar5;
  int unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar6;
  
  __ZN13TInfoSinkBase6appendEPKc(param_1,(char *)(unaff_r31 + 0x8dfd0));
  pvVar5 = *(void **)(unaff_r30 + 8);
  bVar1 = (unaff_r28 & 0xffff) == 0;
  bVar6 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x1e0),(char *)(unaff_r31 + 0x8e018),(int)unaff_r28 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x1e0),(char *)(unaff_r31 + 0x8e010),(int)unaff_r28 >> 0x10);
  }
  __ZNSsC1EPKcRKSaIcE(&STACKARG(0x1d0),&STACKARG(0x1e0),(unsigned char *)&STACKARG(0x220));
  (*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x1d0))[*(int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x1d0)) + -0xc)] = **(char **)(unaff_r31 + 0xffe18e4);
  __ZN13TInfoSinkBase6appendEPKc(pvVar5,(*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x1d0)));
  piVar3 = (int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x1d0)) + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar6 = 2;
    }
  } while (!(bool)(bVar6 >> 1 & 1));
  if (iVar4 < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x1d0)) + -0xc));
  }
  __ZN13TInfoSinkBase6appendEPKc(pvVar5,(char *)(unaff_r31 + 0x8e020));
  pvVar5 = *(void **)(unaff_r30 + 8);
  __ZN13TInfoSinkBase6appendEPKc(pvVar5,(char *)(unaff_r31 + 0x8e9e0));
  __ZN13TInfoSinkBase6appendEPKc(pvVar5,unaff_r27);
  __ZN13TInfoSinkBase6appendEPKc(pvVar5,(char *)(unaff_r31 + 0x8e9e4));
  __ZN13TInfoSinkBase6appendEPKc(pvVar5,unaff_r26);
  __ZN13TInfoSinkBase6appendEPKc(pvVar5,(char *)(unaff_r31 + 0x8e9ec));
  __ZN13TInfoSinkBase6appendEPKc(pvVar5,&STACKARG(0x40));
  __ZN13TInfoSinkBase6appendEPKc(pvVar5,(char *)(unaff_r31 + 0x8c464));
  *(int *)(unaff_r30 + 0x18) = *(int *)(unaff_r30 + 0x18) + 1;
  return;
}

/* TParseContext__assignError @ 0x97b9a9b4 (96 bytes) */
int TParseContext__assignError(this, param_2, param_3, param_4, param_5)
  unsigned char * this;
  int param_2;
  char *param_3;
  int param_4;
  int param_5;
{
  byte bVar1;
  byte *pbVar2;
  undefined4 uVar3;
  
  pbVar2 = DAT_a7b7ba18;
  *(byte *)(*(int *)(param_4 + 4) + *(int *)(*(int *)(param_4 + 4) + -0xc)) = *DAT_a7b7ba18;
  bVar1 = *pbVar2;
  uVar3 = *(undefined4 *)(param_4 + 4);
  *(byte *)(*(int *)(param_5 + 4) + *(int *)(*(int *)(param_5 + 4) + -0xc)) = bVar1;
  error((int)this,(char *)param_2,"",param_3,"cannot convert from \'%s\' to \'%s\'",
        *(undefined4 *)(param_5 + 4),uVar3,(uint)bVar1);
  return;
}

/* TParseContext__unaryOpError @ 0x97b9aa14 (84 bytes) */
int TParseContext__unaryOpError(this, param_2, param_3, param_4)
  unsigned char * this;
  int param_2;
  char *param_3;
  int param_4;
{
  *(undefined1 *)(*(int *)(param_4 + 4) + *(int *)(*(int *)(param_4 + 4) + -0xc)) = *DAT_a7b7ba18;
  error((int)this,(char *)param_2," wrong operand type",param_3,
        "no operation \'%s\' exists that takes an operand of type %s (or there is no acceptable conversion)"
        ,param_3,*(undefined4 *)(param_4 + 4),param_4);
  return;
}

/* TParseContext__binaryOpError @ 0x97b9aa68 (104 bytes) */
int TParseContext__binaryOpError(this, param_2, param_3, param_4, param_5)
  unsigned char * this;
  int param_2;
  char *param_3;
  int param_4;
  int param_5;
{
  undefined1 *puVar1;
  undefined4 uVar2;
  
  puVar1 = DAT_a7b7ba18;
  *(undefined1 *)(*(int *)(param_5 + 4) + *(int *)(*(int *)(param_5 + 4) + -0xc)) = *DAT_a7b7ba18;
  uVar2 = *(undefined4 *)(param_5 + 4);
  *(undefined1 *)(*(int *)(param_4 + 4) + *(int *)(*(int *)(param_4 + 4) + -0xc)) = *puVar1;
  error((int)this,(char *)param_2," wrong operand types ",param_3,
        "no operation \'%s\' exists that takes a left-hand operand of type \'%s\' and a right operand of type \'%s\' (or there is no acceptable conversion)"
        ,param_3,*(undefined4 *)(param_4 + 4),uVar2);
  return;
}

/* TParseContext__lValueErrorCheck @ 0x97b9aad0 (944 bytes) */
int TParseContext__lValueErrorCheck(this, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  unsigned char * this;
  int param_2;
  char *param_3;
  unsigned char * param_4;
  undefined4 param_5;
  undefined4 param_6;
  uint param_7;
  undefined4 param_8;
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  unsigned char * pTVar5;
  int iVar6;
  uint uVar7;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 a1;
  undefined4 a1_00;
  char *pcVar8;
  char *pcVar9;
  undefined4 *puVar10;
  undefined4 uVar11;
  char *pcVar12;
  int local_30 [4];
  
  pcVar8 = param_3;
  pTVar5 = param_4;
  piVar3 = (int *)(**(code **)(*(int *)param_4 + 0x28))(param_4);
  piVar4 = (int *)(**(code **)(*(int *)param_4 + 0x20))(param_4);
  if (piVar4 == (int *)0x0) {
    bVar1 = piVar3 != (int *)0x0;
    uVar11 = 0;
    a1 = extraout_r4;
    if (bVar1) {
      iVar2 = (**(code **)(*piVar3 + 0x60))(piVar3);
      param_7 = (uint)*DAT_a7b7ba18;
      *(byte *)(*(int *)(iVar2 + 4) + *(int *)(*(int *)(iVar2 + 4) + -0xc)) = *DAT_a7b7ba18;
      uVar11 = *(undefined4 *)(iVar2 + 4);
      a1 = extraout_r4_00;
    }
    pcVar12 = (char *)0x0;
    uVar7 = (**(code **)(*(int *)param_4 + 0x44))(param_4,a1,pcVar8,pTVar5,param_5,param_6,param_7);
    if (uVar7 < 0x12) {
      param_7 = uVar7 * 4;
      switch(uVar7) {
      default:
        goto switchD_97b9ace4_caseD_0;
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
    }
    else {
switchD_97b9ace4_caseD_0:
      iVar2 = (**(code **)(*(int *)param_4 + 0x40))
                        (param_4,a1_00,pcVar8,pTVar5,param_5,param_6,param_7);
      if (iVar2 - 5U < 8) {
        pcVar12 = "can\'t modify a sampler";
      }
      else {
        iVar2 = (**(code **)(*(int *)param_4 + 0x40))(param_4);
        if (iVar2 == 0) {
          pcVar12 = "can\'t modify void";
        }
        else {
          iVar2 = (**(code **)(*(int *)param_4 + 0x40))(param_4);
          if (iVar2 == 0xf) {
            pcVar12 = "can\'t modify an address";
          }
        }
      }
    }
    if (pcVar12 != (char *)0x0) {
      if (bVar1) {
        error((int)this,(char *)param_2," l-value required",param_3,"\"%s\" (%s)",uVar11,pcVar12,
              param_8);
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
      pTVar5 = (unsigned char *)(**(code **)(*piVar4 + 0x68))(piVar4);
      iVar2 = ((int (*)())TParseContext__lValueErrorCheck)(this,param_2,param_3,pTVar5,param_5,param_6,param_7,param_8);
      return iVar2;
    }
    if (iVar2 != 0x30) goto LAB_97b9ae0c;
    pTVar5 = (unsigned char *)(**(code **)(*piVar4 + 0x68))(piVar4);
    local_30[0] = ((int (*)())TParseContext__lValueErrorCheck)(this,param_2,param_3,pTVar5,param_5,param_6,param_7,param_8);
    if (local_30[0] != 0) {
      return local_30[0];
    }
    local_30[1] = local_30[0];
    local_30[2] = local_30[0];
    local_30[3] = local_30[0];
    piVar3 = (int *)(**(code **)(*piVar4 + 0x6c))(piVar4);
    piVar3 = (int *)(**(code **)(*piVar3 + 0x1c))(piVar3);
    iVar2 = (**(code **)(*piVar3 + 100))(piVar3);
    puVar10 = *(undefined4 **)(iVar2 + 4);
    while( true ) {
      iVar2 = (**(code **)(*piVar3 + 100))(piVar3);
      if (puVar10 == *(undefined4 **)(iVar2 + 8)) {
        return 0;
      }
      piVar4 = (int *)(**(code **)(*(int *)*puVar10 + 0x14))((int *)*puVar10);
      iVar6 = (**(code **)(*piVar4 + 0x18))(piVar4);
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
  error((int)this,(char *)param_2,pcVar8,param_3,pcVar9,pcVar12,param_7,param_8);
  return 1;
}

/* TParseContext__constErrorCheck @ 0x97b9aec8 (140 bytes) */
int TParseContext__constErrorCheck(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  int iVar1;
  char *pcVar2;
  undefined4 in_r8;
  undefined4 in_r9;
  undefined4 in_r10;
  
  iVar1 = (**(code **)(*(int *)param_2 + 0x44))(param_2,param_2);
  if (iVar1 != 2) {
    pcVar2 = (char *)(*(code *)**(undefined4 **)param_2)(param_2);
    error((int)this,pcVar2,"constant expression required","","",in_r8,in_r9,in_r10);
  }
  return iVar1 != 2;
}

/* TParseContext__integerErrorCheck @ 0x97b9af54 (172 bytes) */
int TParseContext__integerErrorCheck(this, param_2, param_3)
  unsigned char * this;
  unsigned char * param_2;
  char *param_3;
{
  int iVar1;
  char *pcVar2;
  undefined4 in_r8;
  undefined4 in_r9;
  undefined4 in_r10;
  
  iVar1 = (**(code **)(*(int *)param_2 + 0x40))(param_2,param_2,param_3);
  if ((iVar1 == 2) && (iVar1 = (**(code **)(*(int *)param_2 + 0x48))(param_2), iVar1 == 1)) {
    return 0;
  }
  pcVar2 = (char *)(*(code *)**(undefined4 **)param_2)(param_2);
  error((int)this,pcVar2,"integer expression required",param_3,"",in_r8,in_r9,in_r10);
  return 1;
}

/* TParseContext__globalErrorCheck @ 0x97b9b000 (84 bytes) */
int TParseContext__globalErrorCheck(this, param_2, param_3, param_4, param_5, param_6)
  unsigned char * this;
  int param_2;
  int param_3;
  char *param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  undefined4 in_r9;
  undefined4 in_r10;
  
  if (param_3 == 0) {
    error((int)this,(char *)param_2,"only allowed at global scope",param_4,"",param_6,in_r9,in_r10);
  }
  return param_3 == 0;
}

/* TParseContext__reservedErrorCheck @ 0x97b9b054 (376 bytes) */
int TParseContext__reservedErrorCheck(this, param_2, param_3)
  unsigned char * this;
  int param_2;
  unsigned char * param_3;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint *puVar5;
  undefined4 in_r8;
  undefined4 in_r10;
  uint uVar6;
  uint uVar7;
  char in_RESERVE;
  byte bVar8;
  undefined4 local_80;
  int local_7c;
  undefined4 local_70;
  int local_6c;
  undefined4 local_60 [4];
  undefined4 local_50 [4];
  undefined4 local_40 [4];
  uint local_30;
  uint local_2c [4];
  
  iVar2 = (*(int **)(this + 4))[1] - **(int **)(this + 4) >> 2;
  if ((iVar2 != 1) && (iVar2 != 2)) {
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_mm(&local_80,param_3,0,3);
    local_60[0] = GetGlobalPoolAllocator();
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_(&local_70,"gl_",(unsigned char *)local_60)
    ;
    puVar5 = local_2c;
    uVar6 = *(uint *)(local_6c + -0xc);
    local_30 = uVar6;
    uVar7 = *(uint *)(local_7c + -0xc);
    local_2c[0] = uVar7;
    if (uVar6 <= uVar7) {
      puVar5 = &local_30;
    }
    iVar2 = _memcmp(local_6c,local_7c,*puVar5);
    bVar8 = (iVar2 == 0) << 1;
    if (iVar2 == 0) {
      iVar2 = uVar6 - uVar7;
    }
    piVar3 = (int *)(local_6c + -4);
    local_50[0] = local_70;
    do {
      iVar4 = *piVar3;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
        *piVar3 = iVar1;
        bVar8 = 2;
      }
    } while (!(bool)(bVar8 >> 1));
    if (iVar4 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_6c + -0xc),local_50);
    }
    piVar3 = (int *)(local_7c + -4);
    local_40[0] = local_80;
    do {
      iVar4 = *piVar3;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
        *piVar3 = iVar1;
        bVar8 = 2;
      }
    } while (!(bool)(bVar8 >> 1 & 1));
    if (iVar4 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_7c + -0xc),local_40);
    }
    if (iVar2 == 0) {
      error((int)this,(char *)param_2,"reserved built-in name","gl_","",in_r8,local_7c,in_r10);
      return 1;
    }
  }
  return 0;
}

/* TParseContext__constructorErrorCheck @ 0x97b9b1cc (2036 bytes) */
int TParseContext__constructorErrorCheck(this, param_2, param_3, param_4, param_5, param_6)
  unsigned char * this;
  int param_2;
  unsigned char * param_3;
  unsigned char * param_4;
  int param_5;
  int *param_6;
{
  int iVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  int *piVar7;
  int iVar8;
  unsigned char * psVar9;
  unsigned char * this_00;
  void *this_01;
  uint *a0;
  int iVar10;
  int extraout_r4;
  int extraout_r4_00;
  int extraout_r4_01;
  undefined4 a1;
  undefined4 extraout_r4_02;
  undefined4 extraout_r4_03;
  undefined4 a1_00;
  int extraout_r4_04;
  int extraout_r4_05;
  int extraout_r4_06;
  undefined4 a1_01;
  undefined4 extraout_r4_07;
  undefined4 uVar11;
  unsigned char * pTVar12;
  char *pcVar13;
  unsigned char * pTVar14;
  char *pcVar15;
  int iVar16;
  char *pcVar17;
  int *piVar18;
  uint a6;
  uint uVar19;
  int a6_00;
  int in_r10;
  unsigned char * pTVar20;
  int iVar21;
  char in_RESERVE;
  byte bVar22;
  undefined8 uVar23;
  undefined **local_c0;
  int local_bc;
  unsigned char * local_b8;
  int local_b4;
  void *local_b0;
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
  undefined4 local_60 [4];
  undefined4 local_50 [4];
  
  a6 = param_5 - 0x66;
  iVar10 = param_2;
  pTVar12 = param_3;
  pTVar14 = param_4;
  iVar16 = param_5;
  piVar18 = param_6;
  switch(a6) {
  case 0:
    uVar19 = local_9c & 0xfff | 0x100800;
    goto LAB_97b9b330;
  case 1:
    iVar8 = 1;
    uVar19 = local_9c & 0x1fffff | 0x180000;
    break;
  case 2:
    iVar8 = 1;
    goto LAB_97b9b2f0;
  case 3:
    uVar19 = local_9c & 0xfffff | 0x80000;
    goto LAB_97b9b2e4;
  case 4:
    iVar8 = 3;
    uVar19 = local_9c & 0xfffff | 0x80000;
    break;
  case 5:
    uVar19 = local_9c & 0xfffff | 0x80000;
    goto LAB_97b9b3cc;
  case 6:
    uVar19 = local_9c & 0x1fffff | 0x180000;
LAB_97b9b2e4:
    iVar8 = 2;
    break;
  case 7:
    iVar8 = 3;
    goto LAB_97b9b2f0;
  case 8:
    uVar19 = local_9c & 0x1fffff | 0x180000;
    goto LAB_97b9b3cc;
  case 9:
    iVar8 = 2;
LAB_97b9b2f0:
    uVar19 = iVar8 << 0x13 | local_9c & 0x7ffff;
    break;
  case 10:
    uVar19 = local_9c & 0x1fff | 0x101800;
LAB_97b9b330:
    a6 = 0;
    local_9c = uVar19 & 0xfffff9ff;
    local_8c = local_9c << 0xd;
    piVar18 = (int *)0x0;
    param_6[8] = 0;
    param_6[9] = uVar19 & 0x7f800 | uVar19 & 0xfff80000 | param_6[9] & 0x1ffU;
    local_bc = 0;
    local_b8 = (unsigned char *)0x0;
    local_b4 = 0;
    local_b0 = (void *)0x0;
    local_ac = 0;
    local_a8 = 0;
    local_a4 = 0;
    local_c0 = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
    local_a0 = 0;
    param_6[1] = 0;
    param_6[2] = 0;
    param_6[3] = 0;
    param_6[4] = 0;
    param_6[5] = 0;
    param_6[6] = 0;
    param_6[7] = 0;
    goto LAB_97b9b714;
  case 0xb:
    uVar19 = local_9c & 0x7ffff | 0x100000;
LAB_97b9b3cc:
    iVar8 = 4;
    break;
  case 0xc:
    iVar8 = 2;
    goto LAB_97b9b490;
  case 0xd:
    uVar19 = local_9c & 0x1bff | 0x81800;
    goto LAB_97b9b4a0;
  case 0xe:
    iVar8 = 4;
LAB_97b9b490:
    uVar19 = iVar8 << 0xb | local_9c & 0x3ff | 0x80000;
LAB_97b9b4a0:
    a6 = uVar19 & 0xfffffdff | 0x400;
    param_6[9] = uVar19 & 0x7f800 | uVar19 & 0xfff80000 | param_6[9] & 0x1ffU | 0x400;
    param_6[8] = 0;
    local_bc = 0;
    local_b8 = (unsigned char *)0x0;
    local_b4 = 0;
    local_b0 = (void *)0x0;
    local_ac = 0;
    local_a8 = 0;
    local_a4 = 0;
    local_c0 = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
    local_a0 = 0;
    param_6[1] = 0;
    param_6[2] = 0;
    param_6[3] = 0;
    param_6[4] = 0;
    param_6[5] = 0;
    param_6[6] = 0;
    param_6[7] = 0;
    local_8c = in_r10;
    local_9c = a6;
    goto LAB_97b9b714;
  case 0xf:
    pTVar20 = *(unsigned char **)(param_4 + 0x24);
    psVar9 = (unsigned char *)
             (**(code **)(*(int *)(param_4 + 0x1c) + 0x18))
                       (param_4 + 0x1c,param_2,param_3,param_4,param_5,param_6,param_4 + 0x1c);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_((unsigned char *)&local_90,psVar9);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&local_80,(unsigned char *)&local_90);
    local_9c = local_9c & 0x9ff | 0x700800;
    local_c0 = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
    local_a0 = 0;
    local_bc = 0;
    local_b4 = 0;
    local_ac = 0;
    local_a4 = 0;
    local_b8 = pTVar20;
    local_a8 = TType__setStructSize((unsigned char *)&local_c0,pTVar20);
    pcVar13 = local_7c;
    local_7c[*(int *)(local_7c + -0xc)] = *DAT_a7b7ba18;
    this_00 = (unsigned char *)GetGlobalPoolAllocator();
    uVar23 = TPoolAllocator__allocate(this_00,8);
    this_01 = (void *)((ulonglong)uVar23 >> 0x20);
    iVar10 = (int)uVar23;
    bVar22 = (this_01 == (void *)0x0) << 1;
    local_b0 = (void *)0x0;
    if (this_01 != (void *)0x0) {
      local_70[0] = GetGlobalPoolAllocator();
      pTVar12 = (unsigned char *)local_70;
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                (this_01,pcVar13,(unsigned char *)pTVar12);
      local_b0 = this_01;
      iVar10 = extraout_r4;
    }
    piVar7 = (int *)(local_7c + -4);
    local_60[0] = local_80;
    do {
      iVar8 = *piVar7;
      if (in_RESERVE != '\0') {
        iVar21 = storeWordConditionalIndexed(iVar8 + -1,0,piVar7);
        *piVar7 = iVar21;
        bVar22 = 2;
      }
    } while (!(bool)(bVar22 >> 1 & 1));
    if (iVar8 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_7c + -0xc),local_60);
      iVar10 = extraout_r4_00;
    }
    param_6[1] = local_bc;
    param_6[2] = (int)local_b8;
    param_6[3] = local_b4;
    param_6[4] = (int)local_b0;
    param_6[5] = local_ac;
    param_6[6] = local_a8;
    param_6[7] = local_a4;
    param_6[9] = (local_9c >> 9 & 1) << 9 |
                 (local_9c >> 10 & 1) << 10 |
                 local_9c & 0x7f800 |
                 (local_9c >> 0x13 & 0x3f) << 0x13 | local_9c & 0xfe000000 | param_6[9] & 0x1ffU;
    piVar7 = (int *)(local_8c + -4);
    param_6[8] = local_a0;
    local_c0 = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
    local_50[0] = local_90;
    do {
      iVar8 = *piVar7;
      a6 = iVar8 - 1;
      if (in_RESERVE != '\0') {
        iVar21 = storeWordConditionalIndexed(a6,0,piVar7);
        *piVar7 = iVar21;
        bVar22 = 2;
      }
    } while (!(bool)(bVar22 >> 1 & 1));
    if (iVar8 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_8c + -0xc),local_50);
      iVar10 = extraout_r4_01;
    }
    goto LAB_97b9b714;
  default:
    pcVar13 = "expected constructor";
    pcVar15 = "Internal Error";
    goto LAB_97b9b9d8;
  }
  a6 = iVar8 << 0xb | uVar19 & 0xfff801ff;
  local_8c = a6 << 0xd;
  param_6[9] = iVar8 << 0xb | uVar19 & 0xfff80000 | param_6[9] & 0x1ffU;
  param_6[8] = 0;
  local_bc = 0;
  local_b8 = (unsigned char *)0x0;
  local_b4 = 0;
  local_b0 = (void *)0x0;
  local_ac = 0;
  local_a8 = 0;
  local_a4 = 0;
  local_c0 = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  local_a0 = 0;
  param_6[1] = 0;
  param_6[2] = 0;
  param_6[3] = 0;
  param_6[4] = 0;
  param_6[5] = 0;
  param_6[6] = 0;
  param_6[7] = 0;
  local_9c = a6;
LAB_97b9b714:
  iVar8 = 0;
  bVar3 = true;
  bVar2 = false;
  bVar6 = false;
  bVar5 = false;
  bVar4 = false;
  in_r10 = local_8c;
  for (iVar21 = 0; iVar21 < *(int *)(param_4 + 0x14) - *(int *)(param_4 + 0x10) >> 3;
      iVar21 = iVar21 + 1) {
    iVar1 = iVar21 * 8;
    piVar7 = *(int **)(*(int *)(param_4 + 0x10) + iVar1 + 4);
    a6_00 = *piVar7;
    iVar10 = (**(code **)(a6_00 + 0x30))(piVar7,iVar10,pTVar12,pTVar14,iVar16,piVar18,a6_00);
    iVar8 = iVar8 + iVar10;
    uVar11 = a1;
    if ((param_5 - 0x72U < 3) &&
       (piVar7 = *(int **)(*(int *)(param_4 + 0x10) + iVar1 + 4), iVar10 = *piVar7,
       iVar10 = (**(code **)(iVar10 + 0x34))(piVar7,a1,pTVar12,pTVar14,iVar16,piVar18,iVar10),
       uVar11 = extraout_r4_02, iVar10 != 0)) {
      bVar5 = true;
    }
    if (bVar2) {
      bVar6 = true;
    }
    if ((param_5 != 0x75) &&
       (iVar10 = (**(code **)(*param_6 + 0x30))(param_6), uVar11 = extraout_r4_03, iVar10 <= iVar8))
    {
      bVar2 = true;
    }
    piVar7 = *(int **)(*(int *)(param_4 + 0x10) + iVar1 + 4);
    iVar10 = *piVar7;
    iVar10 = (**(code **)(iVar10 + 0x24))(piVar7,uVar11,pTVar12,pTVar14,iVar16,piVar18,iVar10);
    if (iVar10 != 2) {
      bVar3 = false;
    }
    a0 = *(uint **)(*(int *)(param_4 + 0x10) + iVar1 + 4);
    a6 = *a0;
    iVar10 = (**(code **)(a6 + 0x38))(a0,a1_00,pTVar12,pTVar14,iVar16,piVar18,a6);
    if (iVar10 != 0) {
      bVar4 = true;
    }
    iVar10 = extraout_r4_04;
  }
  if (bVar3) {
    (**(code **)(*param_6 + 0x28))(param_6,2);
    iVar10 = extraout_r4_05;
  }
  if (bVar4) {
    pcVar13 = "constructing from a non-dereferenced array";
  }
  else {
    if (bVar5) {
      pcVar13 = "constructing matrix from matrix";
      pcVar15 = "constructor";
      pcVar17 = "(reserved)";
      goto LAB_97b9b9dc;
    }
    if (bVar6) {
      pcVar13 = "too many arguments";
    }
    else if (((iVar8 == 1) ||
             (iVar21 = (**(code **)(*param_6 + 0x30))(param_6,iVar10,pTVar12,pTVar14,iVar16),
             iVar10 = extraout_r4_06, iVar21 <= iVar8)) && ((0 < iVar8 || (param_5 != 0x75)))) {
      piVar7 = (int *)(**(code **)(*(int *)param_3 + 0x14))(param_3,iVar10,pTVar12,pTVar14,iVar16);
      if (piVar7 == (int *)0x0) {
        pcVar13 = "constructor argument does not have a type";
      }
      else {
        uVar11 = a1_01;
        if ((param_5 == 0x75) ||
           (iVar10 = (**(code **)(*piVar7 + 0x40))(piVar7,a1_01,pTVar12,pTVar14,iVar16),
           uVar11 = extraout_r4_07, 7 < iVar10 - 5U)) {
          iVar10 = (**(code **)(*piVar7 + 0x40))(piVar7,uVar11,pTVar12,pTVar14,iVar16);
          if (iVar10 != 0) {
            return 0;
          }
          pcVar13 = "cannot convert a void";
        }
        else {
          pcVar13 = "cannot convert a sampler";
        }
      }
    }
    else {
      pcVar13 = "not enough data provided for construction";
    }
  }
  pcVar15 = "constructor";
LAB_97b9b9d8:
  pcVar17 = "";
LAB_97b9b9dc:
  error((int)this,(char *)param_2,pcVar13,pcVar15,pcVar17,piVar18,a6,in_r10);
  return 1;
}

/* TParseContext__voidErrorCheck @ 0x97b9ba00 (120 bytes) */
int TParseContext__voidErrorCheck(this, param_2, param_3, param_4)
  unsigned char * this;
  int param_2;
  unsigned char * param_3;
  unsigned char * param_4;
{
  byte bVar1;
  int iVar2;
  undefined4 in_r8;
  
  iVar2 = *(int *)param_4;
  if (iVar2 == 0) {
    bVar1 = *DAT_a7b7ba18;
    *(byte *)(*(int *)(param_3 + 4) + *(int *)(*(int *)(param_3 + 4) + -0xc)) = bVar1;
    error((int)this,(char *)param_2,"illegal use of type \'void\'",*(char **)(param_3 + 4),"",in_r8,
          (uint)bVar1,param_3);
  }
  return iVar2 == 0;
}

