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
  bool bVar1;
  int iVar2;
  undefined1 local_40 [56];
  
  iVar2 = *(int *)(this + 0x30);
  if (iVar2 == 8) {
    iVar2 = (**(code **)(**(int **)(this + 0x34) + 0x40))(*(int **)(this + 0x34));
    bVar1 = iVar2 == 2;
LAB_97b9055c:
    if (!bVar1) {
      return 0;
    }
  }
  else {
    if (iVar2 < 9) {
      if (iVar2 == 6) {
        iVar2 = (**(code **)(**(int **)(this + 0x34) + 0x40))(*(int **)(this + 0x34));
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
      iVar2 = (**(code **)(**(int **)(this + 0x34) + 0x40))(*(int **)(this + 0x34));
      bVar1 = iVar2 == 1;
      goto LAB_97b9055c;
    }
    iVar2 = (**(code **)(**(int **)(this + 0x34) + 0x40))(*(int **)(this + 0x34));
    if (iVar2 == 3) {
      return 0;
    }
  }
  (**(code **)(**(int **)(this + 0x34) + 0x38))(local_40,*(int **)(this + 0x34));
  (**(code **)(*(int *)this + 0x34))(this,local_40);
  return 1;
}

/* TIntermBinary__promote @ 0x97b905bc (1680 bytes) */
int TIntermBinary__promote(this, infoSink, param_3, param_4, param_5, param_6)
  unsigned char * this;
  unsigned char * infoSink;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  bool bVar1;
  undefined *atomicStore;
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
                    (*(int **)(this + 0x34),infoSink,param_3,param_4,param_5,param_6);
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
                    
          __ZN13TInfoSinkBase6appendEPKc(infoSink,"INTERNAL ERROR: ");
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
          __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)local_a0);
          ppuVar3 = local_a0 + -1;
          do {
            puVar5 = *ppuVar3;
            if (in_RESERVE != '\0') {
              atomicStore = (undefined *)storeWordConditionalIndexed(puVar5 + -1,0,ppuVar3);
              *ppuVar3 = atomicStore;
              bVar13 = 2;
            }
          } while (!(bool)(bVar13 >> 1 & 1));
          if ((int)puVar5 < 1) {
            __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(local_a0 + -3),(unsigned char *)&local_90);
          }
          __ZN13TInfoSinkBase6appendEPKc(infoSink,": ");
code_r0x97b91274:
          __ZN13TInfoSinkBase6appendEPKc(infoSink,"Missing elses");
          __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
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
                    
            __ZN13TInfoSinkBase6appendEPKc(infoSink,"INTERNAL ERROR: ");
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
            __ZN13TInfoSinkBase6appendEPKc(infoSink,(char *)local_a0);
            ppuVar3 = local_a0 + -1;
            do {
              puVar5 = *ppuVar3;
              if (in_RESERVE != '\0') {
                atomicStore = (undefined *)storeWordConditionalIndexed(puVar5 + -1,0,ppuVar3);
                *ppuVar3 = atomicStore;
                bVar13 = 2;
              }
            } while (!(bool)(bVar13 >> 1 & 1));
            if ((int)puVar5 < 1) {
              __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(local_a0 + -3),&local_90);
            }
            __ZN13TInfoSinkBase6appendEPKc(infoSink,": ");
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
int compareStructure(type, constUnion1, constUnion2, param_4)
  unsigned char * type;
  unsigned char * constUnion1;
  unsigned char * constUnion2;
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
  iVar7 = *(int *)(type + 8);
  iVar2 = *(int *)(iVar7 + 4);
  uVar5 = *(int *)(iVar7 + 8) - iVar2 >> 3;
  a2 = constUnion2;
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
          if (*(int *)(constUnion2 + iVar4 * 4) != *(int *)(constUnion1 + iVar4 * 4)) {
            return 0;
          }
LAB_97b916c8:
          *param_4 = iVar4 + 1;
        }
        else if (iVar4 < 3) {
          if (iVar4 == 1) {
            iVar4 = *param_4;
            if (*(float *)(constUnion2 + iVar4 * 4) != *(float *)(constUnion1 + iVar4 * 4)) {
              return 0;
            }
            goto LAB_97b916c8;
          }
        }
        else {
          if (iVar4 == 3) goto LAB_97b916a8;
          if (iVar4 == 0xe) {
            a2 = constUnion2;
            a3 = param_4;
            uVar9 = ((int (*)())compareStructure)(*(unsigned char **)(*(int *)(iVar7 + 4) + iVar1),constUnion1,constUnion2,
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
int TIntermediate__changeAggrToTempConst(this, intermAggregate, symbolTable, param_4)
  unsigned char * this;
  unsigned char * intermAggregate;
  unsigned char * symbolTable;
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
  
  a2 = symbolTable;
  iVar2 = param_4;
  (**(code **)(*(int *)intermAggregate + 0x38))(local_60,intermAggregate,symbolTable,param_4);
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
  iVar1 = (**(code **)(*(int *)intermAggregate + 100))
                    (intermAggregate,(int)uVar5,a2,iVar2,in_r7,in_r8,*(int *)intermAggregate);
  if (*(int *)(iVar1 + 8) - *(int *)(iVar1 + 4) >> 2 == 1) {
    iVar1 = (**(code **)(*(int *)intermAggregate + 100))(intermAggregate);
    a6 = *(int *)**(undefined4 **)(iVar1 + 4);
    a0 = (int *)(**(code **)(a6 + 0x14))
                          ((int *)**(undefined4 **)(iVar1 + 4),a1,a2,iVar2,in_r7,in_r8,a6);
    iVar2 = (**(code **)(*a0 + 0x18))(a0);
    if (iVar2 != 0) {
      (**(code **)(*(int *)intermAggregate + 0x38))(local_60,intermAggregate);
      iVar2 = ((int (*)())TIntermediate__parseConstTree)(this,param_4,(unsigned char *)intermAggregate,pcVar4,*(undefined4 *)(intermAggregate + 0x30),
                         symbolTable,local_60,1);
      goto LAB_97b95d90;
    }
  }
  (**(code **)(*(int *)intermAggregate + 0x38))(local_60,intermAggregate);
  iVar2 = ((int (*)())TIntermediate__parseConstTree)(this,param_4,(unsigned char *)intermAggregate,pcVar4,*(undefined4 *)(intermAggregate + 0x30),
                     symbolTable,local_60,0);
LAB_97b95d90:
  local_60[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  if (iVar2 != 0) {
    pcVar4 = (unsigned char *)0x0;
  }
  (**(code **)(*(int *)intermAggregate + 0x38))(local_60,intermAggregate);
  iVar2 = (*(code *)**(undefined4 **)intermAggregate)(intermAggregate);
  uVar3 = TIntermediate__addConstantUnion(this,pcVar4,(unsigned char *)local_60,iVar2);
  return uVar3;
}

/* TIntermediate__copyConstUnion @ 0x97b95df0 (336 bytes) */
int TIntermediate__copyConstUnion(this, intermConstantUnion)
  unsigned char * this;
  unsigned char * intermConstantUnion;
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
  
  iVar6 = *(int *)(intermConstantUnion + 0x30);
  pTVar4 = (unsigned char *)0x0;
  if (iVar6 != 0) {
    (**(code **)(*(int *)intermConstantUnion + 0x38))(local_b0);
    local_b0[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
    if ((local_8c >> 0x13 & 0x3f) == 0xe) {
      (**(code **)(*(int *)intermConstantUnion + 0x38))(local_80,intermConstantUnion);
      (**(code **)(*(int *)intermConstantUnion + 0x38))((unsigned char *)local_50,intermConstantUnion);
      iVar2 = TType__setStructSize((unsigned char *)local_50,local_78);
      local_50[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
    }
    else {
      (**(code **)(*(int *)intermConstantUnion + 0x38))(local_80,intermConstantUnion);
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
    *(int *)(intermConstantUnion + 0x30) = iVar3;
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
  undefined *atomicStore;
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
  
  iVar8 = intermConstantUnion[0xc];
  a2 = intermConstantUnion;
  (**(code **)(*intermConstantUnion + 0x38))(local_c0,intermConstantUnion,intermConstantUnion);
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
      if (basicType == 2) {
        (**(code **)(*intermConstantUnion + 0x38))(local_c0,intermConstantUnion);
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
            uVar6 = (**(code **)*intermConstantUnion)(intermConstantUnion);
                    
            goto override_jmp_97b960f0_case_0;
          }
          uVar6 = (uint)(int)*(float *)(iVar10 * 4 + iVar8);
          local_40 = (longlong)(int)uVar6;
        }
LAB_97b9625c:
        *(uint *)(pcVar5 + iVar10 * 4) = uVar6;
      }
      else if ((int)basicType < 3) {
        if (basicType != 1) {
LAB_97b962b8:
          this_01 = *(void **)this;
          pcVar9 = "Incorrect data type found";
          uVar6 = (**(code **)*intermConstantUnion)(intermConstantUnion);
                    
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
              atomicStore = (undefined *)storeWordConditionalIndexed(puVar4 + -1,0,ppuVar3);
              *ppuVar3 = atomicStore;
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
        (**(code **)(*intermConstantUnion + 0x38))(local_c0,intermConstantUnion);
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
          uVar6 = (**(code **)*intermConstantUnion)(intermConstantUnion,a1,a2,in_r6,in_r7,in_r8,in_r9);
                    
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
        if (basicType != 3) goto LAB_97b962b8;
        (**(code **)(*intermConstantUnion + 0x38))(local_c0,intermConstantUnion);
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
          uVar6 = (**(code **)*intermConstantUnion)(intermConstantUnion,a1_00,a2,in_r6,in_r7,in_r8,in_r9);
                    
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
  (**(code **)(*intermConstantUnion + 0x38))(local_c0,intermConstantUnion);
  local_5c = (local_9c >> 9 & 1) << 9 |
             (local_9c >> 10 & 1) << 10 |
             local_9c & 0x7f800 |
             (basicType & 0x3f) << 0x13 | local_9c & 0xfe000000 | local_5c & 0x1ff;
  local_60 = 0;
  local_7c = 0;
  local_78 = 0;
  local_74 = 0;
  local_70 = 0;
  local_6c = 0;
  local_68 = 0;
  local_64 = 0;
  local_80 = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  iVar8 = (**(code **)*intermConstantUnion)(intermConstantUnion,a1_01,a2,in_r6,in_r7,in_r8,(undefined4 *)*intermConstantUnion);
  uVar7 = TIntermediate__addConstantUnion(this,pcVar5,(unsigned char *)&local_80,iVar8);
  return uVar7;
}

/* __ZN13TIntermediate15removeChildNodeER7TVectorIP11TIntermNodeER5TTypeRiRN9__gnu_cxx17__normal_iteratorIPS2_St6vectorIS2_14pool_allocatorIS2_EEEEP16TIntermAggregate @ 0x97b964e8 (824 bytes) */
int __ZN13TIntermediate15removeChildNodeER7TVectorIP11TIntermNodeER5TTypeRiRN9__gnu_cxx17__normal_iteratorIPS2_St6vectorIS2_14pool_allocatorIS2_EEEEP16TIntermAggregate(this, vector, type, param_4, __normal_iterator, intermAggregate)
  void *this;
  unsigned char * vector;
  unsigned char * type;
  int *param_4;
  unsigned char * __normal_iterator;
  unsigned char * intermAggregate;
{
  int loopIndex;
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  unsigned char * poolAllocator;
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
  
  if (intermAggregate != (unsigned char *)0x0) {
    *(int *)__normal_iterator = *(int *)(vector + 4) + *param_4 * 4;
    a5 = intermAggregate;
    iVar8 = (**(code **)(*(int *)intermAggregate + 100))
                      (intermAggregate,vector,type,param_4,__normal_iterator,intermAggregate,*(int *)intermAggregate);
    iVar12 = *(int *)(vector + 8);
    iVar7 = *(int *)(vector + 4);
    if (*(int *)(iVar8 + 8) - *(int *)(iVar8 + 4) >> 2 == 1) {
      a4 = *param_4;
      a3 = intermAggregate;
      iVar9 = ((int (*)())TIntermediate__removeMatrixConstNode)(this,vector,type,intermAggregate,a4);
      if (iVar9 == 0) {
        loopIndex = 0;
        puVar13 = PTR_vtable_a7b7c0c8 + 8;
        while( true ) {
          (**(code **)(*(int *)intermAggregate + 0x38))(local_b0,intermAggregate);
          if ((local_8c & 0x400) == 0) {
            iVar6 = (int)(local_8c << 0xd | local_8c >> 0x13) >> 0x18;
          }
          else {
            iVar6 = (int)(local_8c << 0xd | local_8c >> 0x13) >> 0x18;
            iVar6 = iVar6 * iVar6;
          }
          local_b0[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
          if (iVar6 <= loopIndex) break;
          poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
          puVar11 = (undefined4 *)TPoolAllocator__allocate(poolAllocator,4);
          loopIndex = loopIndex + 1;
          iVar6 = (**(code **)(*(int *)**(undefined4 **)(iVar8 + 4) + 0x18))
                            ((int *)**(undefined4 **)(iVar8 + 4));
          *puVar11 = **(undefined4 **)(iVar6 + 0x30);
          poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
          uVar14 = TPoolAllocator__allocate(poolAllocator,0x34);
          a0 = (int *)((ulonglong)uVar14 >> 0x20);
          iVar6 = *(int *)**(undefined4 **)(iVar8 + 4);
          a1 = (int *)(**(code **)(iVar6 + 0x18))
                                ((int *)**(undefined4 **)(iVar8 + 4),(int)uVar14,type,a3,a4,a5,
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
          a1_00 = (*(code *)**(undefined4 **)intermAggregate)(intermAggregate,a1_01,type,a3,a4,a5,a0 + 2);
          (**(code **)(iVar6 + 4))(a0,a1_00);
          type = (unsigned char *)(*(int *)(vector + 4) + *param_4 * 4);
          a3 = (unsigned char *)local_4c;
          *(unsigned char **)__normal_iterator = type;
          local_4c[0] = a0;
          std__vector_TIntermNode__pool_allocator_TIntermNode_____insert
                    (&local_50,vector,type,a3);
        }
      }
    }
    else {
      std__vector_TIntermNode__pool_allocator_TIntermNode______M_range_insert___gnu_cxx____normal_iterator_TIntermNode___std__vector_TIntermNode__pool_allocator_TIntermNode_____
                (vector,*(undefined4 *)__normal_iterator,*(int *)(iVar8 + 4),*(int *)(iVar8 + 8));
    }
    iVar7 = (*param_4 + (*(int *)(vector + 8) - *(int *)(vector + 4) >> 2)) -
            (iVar12 - iVar7 >> 2);
    *param_4 = iVar7;
    iVar7 = *(int *)(vector + 4) + iVar7 * 4;
    *(int *)__normal_iterator = iVar7;
    std__vector_TIntermNode__pool_allocator_TIntermNode_____erase(&local_50,vector,iVar7);
    *(undefined4 *)__normal_iterator = local_50;
    *param_4 = *param_4 + -1;
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
  
  a2 = type;
  a3 = intermAggregate;
  iVar3 = (**(code **)(*(int *)type + 0x30))(type,intermTyped,type,intermAggregate);
  if (iVar3 == 1) {
    iVar3 = (**(code **)(*(int *)intermAggregate + 100))(intermAggregate);
    iVar4 = *(int *)**(undefined4 **)(iVar3 + 4);
    intermTyped = (unsigned char *)
              (**(code **)(iVar4 + 0x14))
                        ((int *)**(undefined4 **)(iVar3 + 4),a1,a2,a3,in_r7,in_r8,iVar4);
  }
  else {
    iVar3 = (**(code **)(*(int *)type + 0x30))(type);
    a0 = (int *)(**(code **)(*(int *)intermTyped + 0x1c))(intermTyped);
    this_00 = (unsigned char *)(**(code **)(*a0 + 100))(a0);
    iVar4 = (**(code **)(*(int *)intermAggregate + 100))(intermAggregate);
    if (*(int *)(iVar4 + 8) - *(int *)(iVar4 + 4) >> 2 == 1) {
      iVar3 = ((int (*)())TIntermediate__removeMatrixConstNode)(this,(unsigned char *)this_00,type,intermAggregate,1);
      if (iVar3 == 0) {
        iVar3 = (**(code **)(*(int *)intermAggregate + 100))(intermAggregate);
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
          iVar5 = (**(code **)(*(int *)intermAggregate + 100))(intermAggregate);
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
  return intermTyped;
}

/* TIntermediate__removeMatrixConstNode @ 0x97b96a10 (776 bytes) */
int TIntermediate__removeMatrixConstNode(this, vector, type, intermAggregate, param_5)
  unsigned char * this;
  unsigned char * vector;
  unsigned char * type;
  unsigned char * intermAggregate;
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
  unsigned char * poolAllocator;
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
  if (intermAggregate != (unsigned char *)0x0) {
    a2 = type;
    a3 = intermAggregate;
    a4 = param_5;
    iVar8 = (**(code **)(*(int *)intermAggregate + 100))(intermAggregate);
    uVar7 = 0;
    if (*(int *)(intermAggregate + 0x30) - 0x72U < 3) {
      iVar13 = 0;
      puVar12 = PTR_vtable_a7b7c0c8 + 8;
      while( true ) {
        (**(code **)(*(int *)intermAggregate + 0x38))(local_b0,intermAggregate);
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
        poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
        puVar10 = (undefined4 *)TPoolAllocator__allocate(poolAllocator,4);
        (**(code **)(*(int *)intermAggregate + 0x38))(&local_80,intermAggregate);
        local_80 = &PTR___ZN5TTypeD1Ev_a7b7cff8;
        iVar6 = ((int)(local_5c << 0xd | local_5c >> 0x13) >> 0x18) + 1;
        if (iVar13 == (iVar13 / iVar6) * iVar6) {
          iVar6 = *(int *)**(undefined4 **)(iVar8 + 4);
          iVar6 = (**(code **)(iVar6 + 0x18))
                            ((int *)**(undefined4 **)(iVar8 + 4),a1,a2,a3,a4,in_r8,iVar6);
          *puVar10 = **(undefined4 **)(iVar6 + 0x30);
        }
        else {
          iVar6 = (**(code **)(*(int *)type + 0x20))(type);
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
        poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
        uVar14 = TPoolAllocator__allocate(poolAllocator,0x34);
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
        uVar7 = (*(code *)**(undefined4 **)intermAggregate)(intermAggregate,a1_00,a2,a3,a4,in_r8,a0 + 2);
        (**(code **)(iVar6 + 4))(a0,uVar7);
        a2 = (unsigned char *)(*(int *)(vector + 4) + param_5 * 4 + iVar13 * 4);
        a3 = (unsigned char *)local_4c;
        iVar13 = iVar13 + 1;
        local_4c[0] = a0;
        std__vector_TIntermNode__pool_allocator_TIntermNode_____insert(auStack_50,vector,a2,a3);
      }
    }
  }
  return uVar7;
}

/* TIntermAggregate__addToPragmaTable @ 0x97b96d18 (184 bytes) */
int TIntermAggregate__addToPragmaTable(this, map)
  unsigned char * this;
  unsigned char * map;
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
  return std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string_____operator_(this_00,(unsigned char *)map);
}

/* TType__getCompleteString @ 0x97b96dd0 (276 bytes) */
int TType__getCompleteString(param_1, param_2)
  void *param_1;
  int param_2;
{
  undefined4 basicString;
  undefined4 qualifierString;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  char acStack_90 [112];
  undefined4 local_20 [4];
  
  uVar3 = *(uint *)(param_2 + 0x24);
  pcVar4 = acStack_90;
  if (1 < uVar3 >> 0x19) {
    qualifierString = getQualifierString(uVar3 >> 0x19);
    iVar2 = _sprintf(pcVar4,"%s ",qualifierString);
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
  basicString = TType__getBasicString(uVar3 >> 0x13 & 0x3f);
  _sprintf(pcVar4,"%s",basicString);
  local_20[0] = GetGlobalPoolAllocator();
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
            (param_1,acStack_90,(unsigned char *)local_20);
  return param_1;
}

/* OutputTreeText @ 0x97b96ee4 (240 bytes) */
int OutputTreeText(infoSink, intermNode, param_3)
  unsigned char * infoSink;
  unsigned char * intermNode;
  int param_3;
{
  int atomicStore;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint a1;
  char in_RESERVE;
  byte bVar5;
  int local_80 [4];
  char acStack_70 [64];
  unsigned char aaStack_30 [28];
  
  uVar4 = (*(code *)**(undefined4 **)intermNode)(intermNode,intermNode,param_3);
  a1 = uVar4 & 0xffff;
  bVar5 = (a1 == 0) << 1;
  if (a1 == 0) {
    _sprintf(acStack_70,"%d:? ",(int)uVar4 >> 0x10);
  }
  else {
    _sprintf(acStack_70,"%d:%d",(int)uVar4 >> 0x10,a1);
  }
  __ZNSsC1EPKcRKSaIcE(local_80,acStack_70,aaStack_30);
  __ZN13TInfoSinkBase6appendERKSs(infoSink + 8,(unsigned char *)local_80);
  piVar2 = (int *)(local_80[0] + -4);
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      atomicStore = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = atomicStore;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar3 < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(local_80[0] + -0xc),acStack_70);
  }
  if (0 < param_3) {
    do {
      __ZN13TInfoSinkBase6appendEPKc(infoSink + 8,"  ");
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}

/* OutputSymbol @ 0x97b96fd4 (268 bytes) */
int OutputSymbol(intermSymbol, intermTraverser, param_3, param_4, param_5, param_6)
  unsigned char * intermSymbol;
  unsigned char * intermTraverser;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  int atomicStore;
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
  
  a2 = *(int *)(intermTraverser + 0x20);
  ((int (*)())OutputTreeText)(*(unsigned char **)(intermTraverser + 0x30),(unsigned char *)intermSymbol,a2);
  ((int (*)())TType__getCompleteString)(&local_40,intermSymbol + 8);
  iVar3 = local_3c;
  puVar1 = DAT_a7b7b9e0;
  *(undefined1 *)(local_3c + *(int *)(local_3c + -0xc)) = *DAT_a7b7b9e0;
  iVar4 = (**(code **)(*(int *)intermSymbol + 0x60))(intermSymbol,a1,a2,param_4,param_5,param_6,local_3c);
  a6 = *(int *)(iVar4 + 4);
  *(undefined1 *)(a6 + *(int *)(a6 + -0xc)) = *puVar1;
  uVar6 = *(undefined4 *)(iVar4 + 4);
  uVar5 = (**(code **)(*(int *)intermSymbol + 0x5c))(intermSymbol,a1_00,a2,param_4,param_5,param_6,a6,iVar4);
  _sprintf(acStack_b0,"\'%s\' (%s) id: %d\n",uVar6,iVar3,uVar5);
  piVar2 = (int *)(local_3c + -4);
  local_30[0] = local_40;
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      atomicStore = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = atomicStore;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar3 < 1) {
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
              ((unsigned char *)(local_3c + -0xc),local_30);
  }
  return __ZN13TInfoSinkBase6appendEPKc((void *)(*(int *)(intermTraverser + 0x30) + 8),acStack_b0);
}

/* OutputBinary @ 0x97b970e0 (248 bytes) */
int OutputBinary(param_1, intermBinary, intermTraverser)
  int param_1;
  unsigned char * intermBinary;
  unsigned char * intermTraverser;
{
  int atomicStore;
  int *piVar2;
  int iVar3;
  char *pcVar4;
  unsigned char * pTVar5;
  char in_RESERVE;
  byte in_cr0;
  undefined4 local_30;
  int local_2c;
  undefined4 local_20 [5];
  
  pTVar5 = *(unsigned char **)(intermTraverser + 0x30);
  ((int (*)())OutputTreeText)(pTVar5,(unsigned char *)intermBinary,*(int *)(intermTraverser + 0x20));
  if (*(int *)(intermBinary + 0x30) == 0x15) {
    pcVar4 = "Multiply";
  }
  else {
    pcVar4 = *(char **)(PTR__operatorStrings_a7b7c0b0 + *(int *)(intermBinary + 0x30) * 4);
  }
  pTVar5 = pTVar5 + 8;
  __ZN13TInfoSinkBase6appendEPKc(pTVar5,pcVar4);
  __ZN13TInfoSinkBase6appendEPKc(pTVar5," (");
  ((int (*)())TType__getCompleteString)(&local_30,intermBinary + 8);
  __ZN13TInfoSinkBase6appendERKSbIcSt11char_traitsIcE14pool_allocatorIcEE
            (pTVar5,(unsigned char *)&local_30);
  __ZN13TInfoSinkBase6appendEPKc(pTVar5,")");
  piVar2 = (int *)(local_2c + -4);
  local_20[0] = local_30;
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      atomicStore = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = atomicStore;
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
int OutputUnary(param_1, intermUnary, intermTraverser)
  int param_1;
  unsigned char * intermUnary;
  unsigned char * intermTraverser;
{
  int atomicStore;
  int *piVar2;
  int iVar3;
  unsigned char * this;
  char in_RESERVE;
  byte in_cr0;
  undefined4 local_30;
  int local_2c;
  undefined4 local_20 [4];
  
  this = *(unsigned char **)(intermTraverser + 0x30) + 8;
  ((int (*)())OutputTreeText)(*(unsigned char **)(intermTraverser + 0x30),(unsigned char *)intermUnary,*(int *)(intermTraverser + 0x20));
  __ZN13TInfoSinkBase6appendEPKc
            (this,*(char **)(PTR__operatorStrings_a7b7c0b0 + *(int *)(intermUnary + 0x30) * 4));
  __ZN13TInfoSinkBase6appendEPKc(this," (");
  ((int (*)())TType__getCompleteString)(&local_30,intermUnary + 8);
  __ZN13TInfoSinkBase6appendERKSbIcSt11char_traitsIcE14pool_allocatorIcEE(this,(unsigned char *)&local_30);
  __ZN13TInfoSinkBase6appendEPKc(this,")");
  piVar2 = (int *)(local_2c + -4);
  local_20[0] = local_30;
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      atomicStore = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = atomicStore;
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
int OutputAggregate(param_1, intermAggregate, intermTraverser)
  int param_1;
  unsigned char * intermAggregate;
  unsigned char * intermTraverser;
{
  int atomicStore;
  int *piVar2;
  int iVar3;
  unsigned char * pTVar4;
  unsigned char * this;
  char in_RESERVE;
  byte in_cr0;
  undefined4 local_30;
  int local_2c;
  undefined4 local_20 [5];
  
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
      ((int (*)())TType__getCompleteString)(&local_30,intermAggregate + 8);
      __ZN13TInfoSinkBase6appendERKSbIcSt11char_traitsIcE14pool_allocatorIcEE
                (this,(unsigned char *)&local_30);
      __ZN13TInfoSinkBase6appendEPKc(this,")");
      piVar2 = (int *)(local_2c + -4);
      local_20[0] = local_30;
      do {
        iVar3 = *piVar2;
        if (in_RESERVE != '\0') {
          atomicStore = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
          *piVar2 = atomicStore;
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
int OutputSelection(param_1, intermSelection, intermTraverser)
  int param_1;
  unsigned char * intermSelection;
  unsigned char * intermTraverser;
{
  int atomicStore;
  int *piVar2;
  int iVar3;
  unsigned char * this;
  char in_RESERVE;
  byte in_cr0;
  undefined4 local_30;
  int local_2c;
  undefined4 local_20 [4];
  
  this = *(unsigned char **)(intermTraverser + 0x30) + 8;
  ((int (*)())OutputTreeText)(*(unsigned char **)(intermTraverser + 0x30),(unsigned char *)intermSelection,*(int *)(intermTraverser + 0x20));
  __ZN13TInfoSinkBase6appendEPKc(this,"Test condition and select");
  __ZN13TInfoSinkBase6appendEPKc(this," (");
  ((int (*)())TType__getCompleteString)(&local_30,intermSelection + 8);
  __ZN13TInfoSinkBase6appendERKSbIcSt11char_traitsIcE14pool_allocatorIcEE(this,(unsigned char *)&local_30);
  __ZN13TInfoSinkBase6appendEPKc(this,")\n");
  piVar2 = (int *)(local_2c + -4);
  local_20[0] = local_30;
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      atomicStore = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = atomicStore;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar3 < 1) {
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
              ((unsigned char *)(local_2c + -0xc),local_20);
  }
  iVar3 = *(int *)(intermTraverser + 0x20);
  *(int *)(intermTraverser + 0x20) = iVar3 + 1;
  ((int (*)())OutputTreeText)(*(unsigned char **)(intermTraverser + 0x30),(unsigned char *)intermSelection,iVar3 + 1);
  __ZN13TInfoSinkBase6appendEPKc(this,"Condition\n");
  piVar2 = (int *)(**(code **)(*(int *)intermSelection + 0x5c))(intermSelection);
  (**(code **)(*piVar2 + 8))(piVar2,intermTraverser);
  ((int (*)())OutputTreeText)(*(unsigned char **)(intermTraverser + 0x30),(unsigned char *)intermSelection,*(int *)(intermTraverser + 0x20));
  iVar3 = (**(code **)(*(int *)intermSelection + 0x60))(intermSelection);
  if (iVar3 == 0) {
    __ZN13TInfoSinkBase6appendEPKc(this,"true case is null\n");
  }
  else {
    __ZN13TInfoSinkBase6appendEPKc(this,"true case\n");
    piVar2 = (int *)(**(code **)(*(int *)intermSelection + 0x60))(intermSelection);
    (**(code **)(*piVar2 + 8))(piVar2,intermTraverser);
  }
  iVar3 = (**(code **)(*(int *)intermSelection + 100))(intermSelection);
  if (iVar3 != 0) {
    ((int (*)())OutputTreeText)(*(unsigned char **)(intermTraverser + 0x30),(unsigned char *)intermSelection,*(int *)(intermTraverser + 0x20));
    __ZN13TInfoSinkBase6appendEPKc(this,"false case\n");
    piVar2 = (int *)(**(code **)(*(int *)intermSelection + 100))(intermSelection);
    (**(code **)(*piVar2 + 8))(piVar2,intermTraverser);
  }
  *(int *)(intermTraverser + 0x20) = *(int *)(intermTraverser + 0x20) + -1;
  return 0;
}

/* OutputConstantUnion @ 0x97b97654 (628 bytes) */
int OutputConstantUnion(intermConstantUnion, intermTraverser)
  unsigned char * intermConstantUnion;
  unsigned char * intermTraverser;
{
  undefined *atomicStore;
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
  
  this = *(unsigned char **)(intermTraverser + 0x30);
  (**(code **)(*(int *)intermConstantUnion + 0x38))(local_1c0,intermConstantUnion);
  local_1c0[0] = &PTR___ZN5TTypeD1Ev_a7b7d080;
  if ((local_19c >> 0x13 & 0x3f) == 0xe) {
    (**(code **)(*(int *)intermConstantUnion + 0x38))(local_190,intermConstantUnion);
    iVar2 = local_178;
  }
  else {
    (**(code **)(*(int *)intermConstantUnion + 0x38))(local_190,intermConstantUnion);
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
      ((int (*)())OutputTreeText)(this,(unsigned char *)intermConstantUnion,*(int *)(intermTraverser + 0x20));
      uVar6 = (**(code **)(*(int *)intermConstantUnion + 0x38))(local_1c0,intermConstantUnion);
      uVar3 = local_19c >> 0x13 & 0x3f;
      local_1c0[0] = &PTR___ZN5TTypeD1Ev_a7b7d080;
      if (uVar3 == 2) {
        _sprintf((char *)local_1c0,"%d (%s)",*(undefined4 *)(*(int *)(intermConstantUnion + 0x30) + iVar9 * 4),
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
                        (double)*(float *)(*(int *)(intermConstantUnion + 0x30) + iVar9 * 4),DOUBLE_97c30a70,
                        in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,in_stack_fffffe08,in_stack_fffffe10,
                        in_stack_fffffe18,in_stack_fffffe20,in_stack_fffffe28);
            _sprintf(acStack_160,"%s (%s)",acStack_160,"const float");
            __ZN13TInfoSinkBase6appendEPKc(this + 8,acStack_160);
            goto LAB_97b977f8;
          }
        }
        else if (uVar3 == 3) {
          if (*(int *)(*(int *)(intermConstantUnion + 0x30) + iVar9 * 4) == 0) {
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
        uVar3 = (*(code *)**(undefined4 **)intermConstantUnion)(intermConstantUnion,a1);
                    
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
            atomicStore = (undefined *)storeWordConditionalIndexed(puVar5 + -1,0,ppuVar4);
            *ppuVar4 = atomicStore;
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
int OutputLoop(param_1, intermLoop, intermTraverser)
  int param_1;
  unsigned char * intermLoop;
  unsigned char * intermTraverser;
{
  int iVar1;
  unsigned char * this;
  
  this = *(unsigned char **)(intermTraverser + 0x30) + 8;
  ((int (*)())OutputTreeText)(*(unsigned char **)(intermTraverser + 0x30),(unsigned char *)intermLoop,*(int *)(intermTraverser + 0x20));
  __ZN13TInfoSinkBase6appendEPKc(this,"Loop with condition ");
  if (*(int *)(intermLoop + 0x14) == 0) {
    __ZN13TInfoSinkBase6appendEPKc(this,"not ");
  }
  __ZN13TInfoSinkBase6appendEPKc(this,"tested first\n");
  iVar1 = *(int *)(intermTraverser + 0x20);
  *(int *)(intermTraverser + 0x20) = iVar1 + 1;
  ((int (*)())OutputTreeText)(*(unsigned char **)(intermTraverser + 0x30),(unsigned char *)intermLoop,iVar1 + 1);
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
int OutputBranch(param_1, intermBranch, intermTraverser)
  int param_1;
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
  
  if (intermNode != (unsigned char *)0x0) {
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
    (**(code **)(*(int *)intermNode + 8))(intermNode,&local_50);
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
  int iVar1;
  int *piVar2;
  
  iVar1 = 1;
  if ((*(int *)(intermTraverser + 0x24) != 0) && (*(code **)(intermTraverser + 8) != (code *)0x0)) {
    iVar1 = (**(code **)(intermTraverser + 8))(1,this,intermTraverser);
  }
  if (iVar1 != 0) {
    *(int *)(intermTraverser + 0x20) = *(int *)(intermTraverser + 0x20) + 1;
    if (*(int *)(intermTraverser + 0x2c) == 0) {
      piVar2 = *(int **)(this + 0x34);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2,intermTraverser);
      }
      piVar2 = *(int **)(this + 0x38);
    }
    else {
      piVar2 = *(int **)(this + 0x38);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2,intermTraverser);
      }
      piVar2 = *(int **)(this + 0x34);
    }
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2,intermTraverser);
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
  int iVar1;
  
  if (((*(int *)(intermTraverser + 0x24) == 0) || (*(code **)(intermTraverser + 0xc) == (code *)0x0)) ||
     (iVar1 = (**(code **)(intermTraverser + 0xc))(1,this,intermTraverser), iVar1 != 0)) {
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
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = 1;
  if ((*(int *)(intermTraverser + 0x24) != 0) && (*(code **)(intermTraverser + 0x14) != (code *)0x0)) {
    iVar1 = (**(code **)(intermTraverser + 0x14))(1,this,intermTraverser);
  }
  if (iVar1 != 0) {
    *(int *)(intermTraverser + 0x20) = *(int *)(intermTraverser + 0x20) + 1;
    if (*(int *)(intermTraverser + 0x2c) == 0) {
      for (puVar2 = *(undefined4 **)(this + 0x38); puVar2 != *(undefined4 **)(this + 0x3c);
          puVar2 = puVar2 + 1) {
        (**(code **)(*(int *)*puVar2 + 8))((int *)*puVar2,intermTraverser);
      }
    }
    else {
      puVar2 = *(undefined4 **)(this + 0x3c);
      while (puVar2 != *(undefined4 **)(this + 0x38)) {
        puVar2 = puVar2 + -1;
        (**(code **)(*(int *)*puVar2 + 8))((int *)*puVar2,intermTraverser);
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
  int iVar1;
  int *piVar2;
  
  iVar1 = 1;
  if ((*(int *)(intermTraverser + 0x24) != 0) && (*(code **)(intermTraverser + 0x10) != (code *)0x0)) {
    iVar1 = (**(code **)(intermTraverser + 0x10))(1,this,intermTraverser);
  }
  if (iVar1 == 0) {
    return;
  }
  *(int *)(intermTraverser + 0x20) = *(int *)(intermTraverser + 0x20) + 1;
  if (*(int *)(intermTraverser + 0x2c) == 0) {
    (**(code **)(**(int **)(this + 0x30) + 8))(*(int **)(this + 0x30),intermTraverser);
    piVar2 = *(int **)(this + 0x34);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2,intermTraverser);
    }
    piVar2 = *(int **)(this + 0x38);
    if (piVar2 == (int *)0x0) goto LAB_97b981d4;
    iVar1 = *piVar2;
  }
  else {
    piVar2 = *(int **)(this + 0x38);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2,intermTraverser);
    }
    piVar2 = *(int **)(this + 0x34);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2,intermTraverser);
    }
    piVar2 = *(int **)(this + 0x30);
    iVar1 = *piVar2;
  }
  (**(code **)(iVar1 + 8))(piVar2,intermTraverser);
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
  int iVar1;
  int *piVar2;
  
  iVar1 = 1;
  if ((*(int *)(intermTraverser + 0x24) != 0) && (*(code **)(intermTraverser + 0x18) != (code *)0x0)) {
    iVar1 = (**(code **)(intermTraverser + 0x18))(1,this,intermTraverser);
  }
  if (iVar1 != 0) {
    *(int *)(intermTraverser + 0x20) = *(int *)(intermTraverser + 0x20) + 1;
    if (*(int *)(intermTraverser + 0x2c) == 0) {
      piVar2 = *(int **)(this + 0xc);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2,intermTraverser);
      }
      piVar2 = *(int **)(this + 8);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2,intermTraverser);
      }
      piVar2 = *(int **)(this + 0x10);
    }
    else {
      piVar2 = *(int **)(this + 0x10);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2,intermTraverser);
      }
      piVar2 = *(int **)(this + 8);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2,intermTraverser);
      }
      piVar2 = *(int **)(this + 0xc);
    }
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2,intermTraverser);
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
  int iVar1;
  
  iVar1 = 1;
  if ((*(int *)(intermTraverser + 0x24) != 0) && (*(code **)(intermTraverser + 0x1c) != (code *)0x0)) {
    iVar1 = (**(code **)(intermTraverser + 0x1c))(1,this,intermTraverser);
  }
  if (iVar1 != 0) {
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
  bool bVar1;
  undefined *atomicStore;
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
  
  (**(code **)(*(int *)intermSymbol + 0x38))(&local_1b0,intermSymbol);
  uVar10 = *(uint *)(intermTraverser + 0x60);
  local_1b0 = &PTR___ZN5TTypeD1Ev_a7b7d488;
  iVar12 = *(int *)(intermTraverser + 0x34);
  if ((uVar10 >> 0x13 & 0x3f) == 0xe) {
    iVar13 = *(int *)(intermTraverser + 0x54);
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
  if (*(int *)(intermTraverser + 0x30) < iVar13) {
    if (local_18c >> 0x19 == 2) {
      piVar3 = *(int **)(intermTraverser + 0x70);
      uVar6 = (**(code **)(*(int *)intermSymbol + 0x60))(intermSymbol,a1);
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
          if (iVar13 <= *(int *)(intermTraverser + 0x30)) {
            return;
          }
          uVar7 = (**(code **)(*(int *)(iVar11 + 0xc) + 0x20))(a0);
          uVar10 = *(uint *)(intermTraverser + 0x60) >> 0x13 & 0x3f;
          if ((uVar7 == uVar10) || (uVar10 == 0xe)) {
code_r0x97b98c14:
            *(undefined4 *)(iVar12 + *(int *)(intermTraverser + 0x30) * 4) =
                 *(undefined4 *)(iVar14 * 4 + iVar17);
          }
          else {
            iVar8 = (**(code **)(*(int *)(iVar11 + 0xc) + 0x20))(a0);
            if (iVar8 == 2) {
              uVar10 = *(uint *)(intermTraverser + 0x60) >> 0x13 & 0x3f;
              if (uVar10 == 1) {
                uStack_4c = *(uint *)(iVar14 * 4 + iVar17) ^ 0x80000000;
                dVar19 = DOUBLE_97c30a58;
code_r0x97b98bfc:
                local_50 = 0x43300000;
                *(float *)(iVar12 + *(int *)(intermTraverser + 0x30) * 4) =
                     (float)((double)CONCAT44(0x43300000,uStack_4c) - dVar19);
              }
              else {
                if (uVar10 != 3) {
                  pvVar15 = *(void **)(intermTraverser + 0x6c);
                  uVar10 = (*(code *)**(undefined4 **)intermSymbol)(intermSymbol);
                    
                  goto override_jmp_97b98aec_case_0;
                }
                *(uint *)(iVar12 + *(int *)(intermTraverser + 0x30) * 4) =
                     (uint)(*(int *)(iVar14 * 4 + iVar17) != 0);
              }
            }
            else {
              if (iVar8 < 3) {
                if (iVar8 == 1) {
                  uVar10 = *(uint *)(intermTraverser + 0x60) >> 0x13 & 0x3f;
                  if (uVar10 == 2) {
                    iVar8 = (int)*(float *)(iVar14 * 4 + iVar17);
                    local_58 = (longlong)iVar8;
                    *(int *)(*(int *)(intermTraverser + 0x30) * 4 + iVar12) = iVar8;
                  }
                  else {
                    if (uVar10 != 3) {
                      pvVar15 = *(void **)(intermTraverser + 0x6c);
                      uVar10 = (*(code *)**(undefined4 **)intermSymbol)(intermSymbol);
                    
                      goto override_jmp_97b98aec_case_0;
                    }
                    *(uint *)(*(int *)(intermTraverser + 0x30) * 4 + iVar12) =
                         (uint)((double)*(float *)(iVar14 * 4 + iVar17) != DOUBLE_97c30a48);
                  }
                  goto code_r0x97b98dd8;
                }
              }
              else if (iVar8 == 3) {
                uVar10 = *(uint *)(intermTraverser + 0x60) >> 0x13 & 0x3f;
                if (uVar10 == 1) {
                  uStack_4c = *(uint *)(iVar14 * 4 + iVar17);
                  dVar19 = DOUBLE_97c30a68;
                  goto code_r0x97b98bfc;
                }
                if (uVar10 != 2) {
                  pvVar15 = *(void **)(intermTraverser + 0x6c);
                  uVar10 = (*(code *)**(undefined4 **)intermSymbol)(intermSymbol);
                    
                  goto override_jmp_97b98aec_case_0;
                }
                goto code_r0x97b98c14;
              }
              pvVar15 = *(void **)(intermTraverser + 0x6c);
              uVar10 = (*(code *)**(undefined4 **)intermSymbol)(intermSymbol);
                    
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
                  atomicStore = (undefined *)storeWordConditionalIndexed(puVar5 + -1,0,ppuVar4);
                  *ppuVar4 = atomicStore;
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
          *(int *)(intermTraverser + 0x30) = *(int *)(intermTraverser + 0x30) + 1;
          if (iVar16 <= iVar14) {
            return;
          }
        } while( true );
      }
      iVar12 = (**(code **)(*(int *)intermSymbol + 0x60))(intermSymbol);
      *(undefined1 *)(*(int *)(iVar12 + 4) + *(int *)(*(int *)(iVar12 + 4) + -0xc)) = *DAT_a7b7ba10;
      _sprintf((char *)&local_1b0,
               "\'constructor\' : constant \'%s\' has not been initialized correctly",
               *(undefined4 *)(iVar12 + 4));
      pvVar15 = *(void **)(intermTraverser + 0x6c);
      uVar10 = (*(code *)**(undefined4 **)intermSymbol)(intermSymbol);
                    
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
      ((int (*)())TType__getCompleteString)(&local_1b0,intermTraverser + 0x3c);
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
      pvVar15 = *(void **)(intermTraverser + 0x6c);
      uVar10 = (*(code *)**(undefined4 **)intermSymbol)(intermSymbol);
                    
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
          atomicStore = (undefined *)storeWordConditionalIndexed(puVar5 + -1,0,ppuVar4);
          *ppuVar4 = atomicStore;
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
    *(undefined4 *)(intermTraverser + 0x74) = 1;
  }
  return;
}

/* ParseBinary @ 0x97b98e04 (308 bytes) */
int ParseBinary(param_1, intermBinary, intermTraverser)
  int param_1;
  unsigned char * intermBinary;
  unsigned char * intermTraverser;
{
  int atomicStore2;
  undefined *atomicStore;
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
  
  (**(code **)(*(int *)intermBinary + 0x38))(&local_170,intermBinary,intermTraverser);
  local_170 = &PTR___ZN5TTypeD1Ev_a7b7d488;
  if (local_14c >> 0x19 == 2) {
    pvVar9 = *(void **)(intermTraverser + 0x6c);
    uVar7 = (*(code *)**(undefined4 **)intermBinary)(intermBinary);
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
        atomicStore = (undefined *)storeWordConditionalIndexed(puVar6 + -1,0,ppuVar4);
        *ppuVar4 = atomicStore;
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
    ((int (*)())TType__getCompleteString)(&local_170,intermTraverser + 0x3c);
    *(undefined1 *)(local_16c + *(int *)(local_16c + -0xc)) = *DAT_a7b7ba10;
    _sprintf(acStack_140,"\'constructor\' : assigning non-constant to %s",local_16c);
    piVar3 = (int *)(local_16c + -4);
    local_70[0] = local_170;
    do {
      iVar5 = *piVar3;
      if (in_RESERVE != '\0') {
        atomicStore2 = storeWordConditionalIndexed(iVar5 + -1,0,piVar3);
        *piVar3 = atomicStore2;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar5 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_16c + -0xc),local_70);
    }
    pvVar9 = *(void **)(intermTraverser + 0x6c);
    uVar7 = (*(code *)**(undefined4 **)intermBinary)(intermBinary);
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
        atomicStore = (undefined *)storeWordConditionalIndexed(puVar6 + -1,0,ppuVar4);
        *ppuVar4 = atomicStore;
        bVar10 = 2;
      }
    } while (!(bool)(bVar10 >> 1 & 1));
    if ((int)puVar6 < 1) {
      __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(local_170 + -3),aaStack_160);
    }
    __ZN13TInfoSinkBase6appendEPKc(pvVar9,": ");
    __ZN13TInfoSinkBase6appendEPKc(pvVar9,acStack_140);
    __ZN13TInfoSinkBase6appendEPKc(pvVar9,"\n");
    *(undefined4 *)(intermTraverser + 0x74) = 1;
  }
  return 0;
}

/* FUN_97b9907c @ 0x97b9907c (12 bytes) */
int FUN_97b9907c()
{
  bool bVar1;
  int atomicStore;
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
      atomicStore = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = atomicStore;
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
int ParseUnary(param_1, intermUnary, intermTraverser)
  int param_1;
  unsigned char * intermUnary;
  unsigned char * intermTraverser;
{
  int atomicStore;
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
  
  ((int (*)())TType__getCompleteString)(&local_90,intermTraverser + 0x3c);
  *(undefined1 *)(local_8c + *(int *)(local_8c + -0xc)) = *DAT_a7b7ba10;
  _sprintf(acStack_160,"\'constructor\' : assigning non-constant to \'%s\'",local_8c);
  piVar2 = (int *)(local_8c + -4);
  local_80[0] = local_90;
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      atomicStore = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = atomicStore;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar3 < 1) {
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
              ((unsigned char *)(local_8c + -0xc),local_80);
  }
  this = *(void **)(intermTraverser + 0x6c);
  uVar4 = (*(code *)**(undefined4 **)intermUnary)(intermUnary);
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
      atomicStore = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = atomicStore;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar3 < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(local_90 + -0xc));
  }
  __ZN13TInfoSinkBase6appendEPKc(this,": ");
  __ZN13TInfoSinkBase6appendEPKc(this,acStack_160);
  __ZN13TInfoSinkBase6appendEPKc(this,"\n");
  *(undefined4 *)(intermTraverser + 0x74) = 1;
  return 0;
}

/* FUN_97b99274 @ 0x97b99274 (12 bytes) */
int FUN_97b99274()
{
  bool bVar1;
  int atomicStore;
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
      atomicStore = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = atomicStore;
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
int ParseAggregate(param_1, intermAggregate, intermTraverser, param_4, param_5, param_6)
  int param_1;
  unsigned char * intermAggregate;
  unsigned char * intermTraverser;
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
  
  a2 = intermTraverser;
  uVar8 = ((int (*)())TIntermOperator__isConstructor)((unsigned char *)intermAggregate);
  if (((int)((ulonglong)uVar8 >> 0x20) == 0) && (*(int *)(intermAggregate + 0x30) != 0x25)) {
    ((int (*)())TType__getCompleteString)(&local_90,intermTraverser + 0x3c);
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
    this = *(void **)(intermTraverser + 0x6c);
    uVar4 = (*(code *)**(undefined4 **)intermAggregate)(intermAggregate);
                    
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
    iVar3 = (**(code **)(*(int *)intermAggregate + 100))(intermAggregate,(int)uVar8);
    if ((uint)(*(int *)(iVar3 + 8) - *(int *)(iVar3 + 4)) >> 2 != 0) {
      bVar1 = false;
      iVar3 = (**(code **)(*(int *)intermAggregate + 100))(intermAggregate);
      if (*(int *)(iVar3 + 8) - *(int *)(iVar3 + 4) >> 2 == 1) {
        iVar3 = (**(code **)(*(int *)intermAggregate + 100))(intermAggregate);
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
        *(undefined4 *)(intermTraverser + 0x68) = 1;
        *(undefined4 *)(intermTraverser + 100) = *(undefined4 *)(intermAggregate + 0x30);
        (**(code **)(*(int *)intermAggregate + 0x38))
                  (local_160,intermAggregate,a2,param_4,param_5,param_6,*(int *)intermAggregate);
        local_160[0] = &PTR___ZN5TTypeD1Ev_a7b7d488;
        if ((local_13c >> 0x13 & 0x3f) == 0xe) {
          (**(code **)(*(int *)intermAggregate + 0x38))(local_130,intermAggregate);
          *(undefined4 *)(intermTraverser + 0x78) = local_118;
        }
        else {
          (**(code **)(*(int *)intermAggregate + 0x38))(local_130,intermAggregate);
          if ((local_10c & 0x400) == 0) {
            iVar3 = (int)(local_10c << 0xd | local_10c >> 0x13) >> 0x18;
          }
          else {
            iVar3 = (int)(local_10c << 0xd | local_10c >> 0x13) >> 0x18;
            iVar3 = iVar3 * iVar3;
          }
          *(int *)(intermTraverser + 0x78) = iVar3;
        }
        local_130[0] = &PTR___ZN5TTypeD1Ev_a7b7d488;
        (**(code **)(*(int *)intermAggregate + 0x38))(local_160,intermAggregate);
        local_160[0] = &PTR___ZN5TTypeD1Ev_a7b7d488;
        if ((local_13c & 0x400) != 0) {
          *(undefined4 *)(intermTraverser + 0x7c) = 1;
          (**(code **)(*(int *)intermAggregate + 0x38))
                    (local_130,intermAggregate,a2,param_4,param_5,param_6,local_13c & 0x400);
          local_130[0] = &PTR___ZN5TTypeD1Ev_a7b7d488;
          *(int *)(intermTraverser + 0x80) = (int)(local_10c << 0xd | local_10c >> 0x13) >> 0x18;
        }
      }
      iVar3 = (**(code **)(*(int *)intermAggregate + 100))(intermAggregate);
      for (puVar6 = *(undefined4 **)(iVar3 + 4);
          iVar3 = (**(code **)(*(int *)intermAggregate + 100))(intermAggregate),
          puVar6 != *(undefined4 **)(iVar3 + 8); puVar6 = puVar6 + 1) {
        if (*(int *)(intermAggregate + 0x30) == 0x25) {
          *(undefined4 *)(intermTraverser + 0x30) = 0;
        }
        (**(code **)(*(int *)*puVar6 + 8))((int *)*puVar6,intermTraverser);
      }
      if (!bVar1) {
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
int ParseSelection(param_1, intermSelection, intermTraverser)
  int param_1;
  unsigned char * intermSelection;
  unsigned char * intermTraverser;
{
  int atomicStore;
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
  
  this = *(void **)(intermTraverser + 0x6c);
  uVar4 = (*(code *)**(undefined4 **)intermSelection)(intermSelection,intermSelection,intermTraverser);
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
      atomicStore = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = atomicStore;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar3 < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(apcStack_80[0] + -0xc),acStack_70);
  }
  __ZN13TInfoSinkBase6appendEPKc(this,": ");
  __ZN13TInfoSinkBase6appendEPKc(this,"Selection Node found in constant constructor");
  __ZN13TInfoSinkBase6appendEPKc(this,"\n");
  *(undefined4 *)(intermTraverser + 0x74) = 1;
  return 0;
}

/* FUN_97b9989c @ 0x97b9989c (12 bytes) */
int FUN_97b9989c()
{
  bool bVar1;
  int atomicStore;
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
      atomicStore = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = atomicStore;
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
int ParseConstantUnion(intermConstantUnion, intermTraverser, param_3, param_4, param_5, param_6)
  unsigned char * intermConstantUnion;
  unsigned char * intermTraverser;
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
  
  a6 = intermTraverser + 0x3c;
  uVar6 = *(uint *)(intermTraverser + 0x60);
  iVar12 = *(int *)(intermTraverser + 0x34);
  if ((uVar6 >> 0x13 & 0x3f) == 0xe) {
    iVar11 = *(int *)(intermTraverser + 0x54);
  }
  else if ((uVar6 & 0x400) == 0) {
    iVar11 = (int)(uVar6 << 0xd | uVar6 >> 0x13) >> 0x18;
  }
  else {
    iVar11 = (int)(uVar6 << 0xd | uVar6 >> 0x13) >> 0x18;
    iVar11 = iVar11 * iVar11;
  }
  iVar13 = *(int *)(intermTraverser + 0x30);
  if (iVar13 < iVar11) {
    if (*(int *)(intermTraverser + 0x68) == 0) {
      (**(code **)(*(int *)intermConstantUnion + 0x38))(local_130,intermConstantUnion);
      local_130[0] = &PTR___ZN5TTypeD1Ev_a7b7d488;
      if ((local_10c >> 0x13 & 0x3f) == 0xe) {
        (**(code **)(*(int *)intermConstantUnion + 0x38))(local_100,intermConstantUnion);
      }
      else {
        (**(code **)(*(int *)intermConstantUnion + 0x38))(local_100,intermConstantUnion,param_3,param_4,param_5,param_6,a6);
        if ((local_dc & 0x400) == 0) {
          local_e8 = (int)(local_dc << 0xd | local_dc >> 0x13) >> 0x18;
        }
        else {
          local_e8 = (int)(local_dc << 0xd | local_dc >> 0x13) >> 0x18;
          local_e8 = local_e8 * local_e8;
        }
      }
      iVar13 = 0;
      puVar7 = *(undefined4 **)(intermConstantUnion + 0x30);
      if (0 < local_e8) {
        do {
          if (iVar11 <= *(int *)(intermTraverser + 0x30)) {
            return;
          }
          uVar8 = *puVar7;
          iVar13 = iVar13 + 1;
          puVar7 = puVar7 + 1;
          *(undefined4 *)(iVar12 + *(int *)(intermTraverser + 0x30) * 4) = uVar8;
          *(int *)(intermTraverser + 0x30) = *(int *)(intermTraverser + 0x30) + 1;
        } while (iVar13 < local_e8);
      }
    }
    else {
      iVar9 = *(int *)(intermTraverser + 0x80);
      iVar10 = iVar13 + *(int *)(intermTraverser + 0x78);
      puVar7 = *(undefined4 **)(intermConstantUnion + 0x30);
      if (*(int *)(intermTraverser + 0x7c) == 0) {
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
            *(int *)(intermTraverser + 0x30) = *(int *)(intermTraverser + 0x30) + 1;
            (**(code **)(*(int *)intermConstantUnion + 0x38))
                      (local_130,intermConstantUnion,param_3,param_4,param_5,param_6,*(int *)intermConstantUnion);
            if ((local_10c >> 0x13 & 0x3f) == 0xe) {
              bVar3 = true;
              (**(code **)(*(int *)intermConstantUnion + 0x38))(local_d0,intermConstantUnion);
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
              (**(code **)(*(int *)intermConstantUnion + 0x38))(local_a0,intermConstantUnion);
              if ((local_7c >> 0x13 & 0x3f) != 0xe) {
                bVar1 = true;
                (**(code **)(*(int *)intermConstantUnion + 0x38))(local_70,intermConstantUnion);
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
          *(int *)(intermTraverser + 0x30) = *(int *)(intermTraverser + 0x30) + 1;
          bVar2 = false;
          bVar1 = false;
          (**(code **)(*(int *)intermConstantUnion + 0x38))
                    (local_130,intermConstantUnion,param_3,param_4,param_5,param_6,*(int *)intermConstantUnion);
          if ((local_10c >> 0x13 & 0x3f) == 0xe) {
            bVar3 = true;
            (**(code **)(*(int *)intermConstantUnion + 0x38))(local_100,intermConstantUnion);
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
            (**(code **)(*(int *)intermConstantUnion + 0x38))(local_d0,intermConstantUnion);
            if ((local_ac >> 0x13 & 0x3f) != 0xe) {
              bVar1 = true;
              (**(code **)(*(int *)intermConstantUnion + 0x38))(local_a0,intermConstantUnion);
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
int ParseLoop(param_1, intermLoop, intermTraverser)
  int param_1;
  unsigned char * intermLoop;
  unsigned char * intermTraverser;
{
  int atomicStore;
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
  
  this = *(void **)(intermTraverser + 0x6c);
  uVar4 = (*(code *)**(undefined4 **)intermLoop)(intermLoop,intermLoop,intermTraverser);
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
      atomicStore = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = atomicStore;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar3 < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(apcStack_80[0] + -0xc),acStack_70);
  }
  __ZN13TInfoSinkBase6appendEPKc(this,": ");
  __ZN13TInfoSinkBase6appendEPKc(this,"Loop Node found in constant constructor");
  __ZN13TInfoSinkBase6appendEPKc(this,"\n");
  *(undefined4 *)(intermTraverser + 0x74) = 1;
  return 0;
}

/* FUN_97b99eb8 @ 0x97b99eb8 (12 bytes) */
int FUN_97b99eb8()
{
  bool bVar1;
  int atomicStore;
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
      atomicStore = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = atomicStore;
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
int ParseBranch(param_1, intermBranch, intermTraverser)
  int param_1;
  unsigned char * intermBranch;
  unsigned char * intermTraverser;
{
  int atomicStore;
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
  
  this = *(void **)(intermTraverser + 0x6c);
  uVar4 = (*(code *)**(undefined4 **)intermBranch)(intermBranch,intermBranch,intermTraverser);
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
      atomicStore = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = atomicStore;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar3 < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(apcStack_80[0] + -0xc),acStack_70);
  }
  __ZN13TInfoSinkBase6appendEPKc(this,": ");
  __ZN13TInfoSinkBase6appendEPKc(this,"Branch Node found in constant constructor");
  __ZN13TInfoSinkBase6appendEPKc(this,"\n");
  *(undefined4 *)(intermTraverser + 0x74) = 1;
  return 0;
}

/* FUN_97b9a04c @ 0x97b9a04c (12 bytes) */
int FUN_97b9a04c()
{
  bool bVar1;
  int atomicStore;
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
      atomicStore = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = atomicStore;
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
int TIntermediate__parseConstTree(this, param_2, intermNode, constUnion, op, symbolTable, type, param_8)
  unsigned char * this;
  int param_2;
  unsigned char * intermNode;
  unsigned char * constUnion;
  undefined4 op;
  undefined4 symbolTable;
  int type;
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
  if (intermNode != (unsigned char *)0x0) {
    uVar2 = *(uint *)(type + 0x24);
    local_44 = *(undefined4 *)this;
    local_6c = *(undefined4 *)(type + 8);
    local_68 = *(undefined4 *)(type + 0xc);
    local_64 = *(undefined4 *)(type + 0x10);
    local_70 = *(undefined4 *)(type + 4);
    local_60 = *(undefined4 *)(type + 0x14);
    local_50 = (uVar2 >> 9 & 1) << 9 |
               (uVar2 >> 10 & 1) << 10 |
               uVar2 & 0x7f800 |
               (uVar2 >> 0x13 & 0x3f) << 0x13 | uVar2 & 0xfe000000 | local_50 & 0x1ff;
    local_5c = *(undefined4 *)(type + 0x18);
    local_58 = *(undefined4 *)(type + 0x1c);
    local_54 = *(undefined4 *)(type + 0x20);
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
    local_7c = constUnion;
    local_4c = op;
    local_48 = param_8;
    local_40 = symbolTable;
    (**(code **)(*(int *)intermNode + 8))
              (intermNode,&local_b0,local_60,local_64,local_68,local_6c,DAT_a7b7b9f0,local_70);
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
int TParseContext__parseVectorFields(this, text, param_3, vectorFields, param_5)
  unsigned char * this;
  unsigned char * text;
  int param_3;
  unsigned char * vectorFields;
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
  
  iVar2 = *(int *)(*(int *)(text + 4) + -0xc);
  *(int *)(vectorFields + 0x10) = iVar2;
  if (iVar2 < 5) {
    in_r10 = 0;
    if (iVar2 < 1) {
      iVar2 = *(int *)(vectorFields + 0x10);
    }
    else {
      do {
        iVar2 = *(int *)(text + 4);
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
          *(int *)(vectorFields + in_r10 * 4) = iVar2;
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
        *(undefined4 *)(vectorFields + in_r10 * 4) = uVar4;
LAB_97b9a570:
        iVar2 = *(int *)(vectorFields + 0x10);
        in_r10 = in_r10 + 1;
      } while (in_r10 < iVar2);
    }
    in_r10 = 0;
    if (0 < iVar2) {
      piVar7 = local_24;
      do {
        iVar3 = *(int *)vectorFields;
        vectorFields = vectorFields + 4;
        if (param_3 <= iVar3) {
          iVar3 = *(int *)(text + 4);
          iVar2 = *(int *)(iVar3 + -0xc);
          bVar1 = *DAT_a7b7ba18;
          pcVar5 = "vector field selection out of range";
LAB_97b9a3b8:
          *(byte *)(iVar3 + iVar2) = bVar1;
          pcVar6 = *(char **)(text + 4);
          goto LAB_97b9a560;
        }
        if ((0 < in_r10) && (piVar7[1] != *piVar7)) {
          iVar3 = *(int *)(text + 4);
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
    iVar2 = *(int *)(text + 4);
    iVar3 = *(int *)(iVar2 + -0xc);
LAB_97b9a54c:
    bVar1 = *DAT_a7b7ba18;
    *(byte *)(iVar2 + iVar3) = bVar1;
    pcVar6 = *(char **)(text + 4);
    pcVar5 = "illegal vector field selection";
LAB_97b9a560:
    error((int)this,(char *)param_5,pcVar5,pcVar6,"",param_5,(uint)bVar1,in_r10);
    uVar4 = 0;
  }
  return uVar4;
}

/* TParseContext__parseMatrixFields @ 0x97b9a5e8 (464 bytes) */
int TParseContext__parseMatrixFields(this, text, param_3, matrixFields, param_5)
  unsigned char * this;
  unsigned char * text;
  int param_3;
  unsigned char * matrixFields;
  int param_5;
{
  char cVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  char *pcVar5;
  
  *(undefined4 *)(matrixFields + 4) = 0;
  *(undefined4 *)(matrixFields + 0xc) = 0xffffffff;
  *(undefined4 *)matrixFields = 0;
  *(undefined4 *)(matrixFields + 8) = 0xffffffff;
  pcVar5 = *(char **)(text + 4);
  uVar4 = *(uint *)(pcVar5 + -0xc);
  if (uVar4 == 2) {
    iVar2 = (int)*pcVar5;
    if (iVar2 == 0x5f) {
      if (('/' < pcVar5[1]) && (pcVar5[1] < '4')) {
        *(undefined4 *)(matrixFields + 4) = 1;
LAB_97b9a738:
        *(int *)(matrixFields + 0xc) = *(char *)(*(int *)(text + 4) + 1) + -0x30;
LAB_97b9a74c:
        if ((*(int *)(matrixFields + 8) < param_3) && (*(int *)(matrixFields + 0xc) < param_3)) {
          return 1;
        }
        uVar4 = (uint)*DAT_a7b7ba18;
        pcVar3 = "matrix field selection out of range";
        *(byte *)(*(int *)(text + 4) + *(int *)(*(int *)(text + 4) + -0xc)) = *DAT_a7b7ba18;
        goto LAB_97b9a790;
      }
LAB_97b9a6a4:
      pcVar5[2] = *DAT_a7b7ba18;
    }
    else {
      cVar1 = pcVar5[1];
      if (cVar1 == '_') {
        if ((0x2f < iVar2) && (iVar2 < 0x34)) {
          *(undefined4 *)matrixFields = 1;
          *(int *)(matrixFields + 8) = **(char **)(text + 4) + -0x30;
          goto LAB_97b9a74c;
        }
        goto LAB_97b9a6a4;
      }
      if ((((0x2f < iVar2) && (iVar2 < 0x34)) && ('/' < cVar1)) && (cVar1 < '4')) {
        *(int *)(matrixFields + 8) = iVar2 + -0x30;
        goto LAB_97b9a738;
      }
      uVar4 = (uint)*DAT_a7b7ba18;
      pcVar5[*(int *)(pcVar5 + -0xc)] = *DAT_a7b7ba18;
    }
    pcVar5 = *(char **)(text + 4);
    pcVar3 = "illegal matrix field selection";
  }
  else {
    pcVar3 = "illegal length of matrix field selection";
    pcVar5[uVar4] = *DAT_a7b7ba18;
LAB_97b9a790:
    pcVar5 = *(char **)(text + 4);
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
  int atomicStore;
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
      atomicStore = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = atomicStore;
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
int TParseContext__assignError(this, param_2, str, text1, text2)
  unsigned char * this;
  int param_2;
  char *str;
  int text1;
  int text2;
{
  byte bVar1;
  byte *pbVar2;
  undefined4 uVar3;
  
  pbVar2 = DAT_a7b7ba18;
  *(byte *)(*(int *)(text1 + 4) + *(int *)(*(int *)(text1 + 4) + -0xc)) = *DAT_a7b7ba18;
  bVar1 = *pbVar2;
  uVar3 = *(undefined4 *)(text1 + 4);
  *(byte *)(*(int *)(text2 + 4) + *(int *)(*(int *)(text2 + 4) + -0xc)) = bVar1;
  return error((int)this,(char *)param_2,"",str,"cannot convert from \'%s\' to \'%s\'",
        *(undefined4 *)(text2 + 4),uVar3,(uint)bVar1);
}

/* TParseContext__unaryOpError @ 0x97b9aa14 (84 bytes) */
int TParseContext__unaryOpError(this, param_2, str, text)
  unsigned char * this;
  int param_2;
  char *str;
  int text;
{
  *(undefined1 *)(*(int *)(text + 4) + *(int *)(*(int *)(text + 4) + -0xc)) = *DAT_a7b7ba18;
  return error((int)this,(char *)param_2," wrong operand type",str,
        "no operation \'%s\' exists that takes an operand of type %s (or there is no acceptable conversion)"
        ,str,*(undefined4 *)(text + 4),text);
}

/* TParseContext__binaryOpError @ 0x97b9aa68 (104 bytes) */
int TParseContext__binaryOpError(this, param_2, str, text1, text2)
  unsigned char * this;
  int param_2;
  char *str;
  int text1;
  int text2;
{
  undefined1 *puVar1;
  undefined4 uVar2;
  
  puVar1 = DAT_a7b7ba18;
  *(undefined1 *)(*(int *)(text2 + 4) + *(int *)(*(int *)(text2 + 4) + -0xc)) = *DAT_a7b7ba18;
  uVar2 = *(undefined4 *)(text2 + 4);
  *(undefined1 *)(*(int *)(text1 + 4) + *(int *)(*(int *)(text1 + 4) + -0xc)) = *puVar1;
  return error((int)this,(char *)param_2," wrong operand types ",str,
        "no operation \'%s\' exists that takes a left-hand operand of type \'%s\' and a right operand of type \'%s\' (or there is no acceptable conversion)"
        ,str,*(undefined4 *)(text1 + 4),uVar2);
}

/* TParseContext__lValueErrorCheck @ 0x97b9aad0 (944 bytes) */
int TParseContext__lValueErrorCheck(this, param_2, str, intermTyped, param_5, param_6, param_7, param_8)
  unsigned char * this;
  int param_2;
  char *str;
  unsigned char * intermTyped;
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
  
  pcVar8 = str;
  pTVar5 = intermTyped;
  piVar3 = (int *)(**(code **)(*(int *)intermTyped + 0x28))(intermTyped);
  piVar4 = (int *)(**(code **)(*(int *)intermTyped + 0x20))(intermTyped);
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
    uVar7 = (**(code **)(*(int *)intermTyped + 0x44))(intermTyped,a1,pcVar8,pTVar5,param_5,param_6,param_7);
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
      iVar2 = (**(code **)(*(int *)intermTyped + 0x40))
                        (intermTyped,a1_00,pcVar8,pTVar5,param_5,param_6,param_7);
      if (iVar2 - 5U < 8) {
        pcVar12 = "can\'t modify a sampler";
      }
      else {
        iVar2 = (**(code **)(*(int *)intermTyped + 0x40))(intermTyped);
        if (iVar2 == 0) {
          pcVar12 = "can\'t modify void";
        }
        else {
          iVar2 = (**(code **)(*(int *)intermTyped + 0x40))(intermTyped);
          if (iVar2 == 0xf) {
            pcVar12 = "can\'t modify an address";
          }
        }
      }
    }
    if (pcVar12 != (char *)0x0) {
      if (bVar1) {
        error((int)this,(char *)param_2," l-value required",str,"\"%s\" (%s)",uVar11,pcVar12,
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
      iVar2 = ((int (*)())TParseContext__lValueErrorCheck)(this,param_2,str,pTVar5,param_5,param_6,param_7,param_8);
      return iVar2;
    }
    if (iVar2 != 0x30) goto LAB_97b9ae0c;
    pTVar5 = (unsigned char *)(**(code **)(*piVar4 + 0x68))(piVar4);
    local_30[0] = ((int (*)())TParseContext__lValueErrorCheck)(this,param_2,str,pTVar5,param_5,param_6,param_7,param_8);
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
  error((int)this,(char *)param_2,pcVar8,str,pcVar9,pcVar12,param_7,param_8);
  return 1;
}

/* TParseContext__constErrorCheck @ 0x97b9aec8 (140 bytes) */
int TParseContext__constErrorCheck(this, intermTyped)
  unsigned char * this;
  unsigned char * intermTyped;
{
  int iVar1;
  char *pcVar2;
  undefined4 in_r8;
  undefined4 in_r9;
  undefined4 in_r10;
  
  iVar1 = (**(code **)(*(int *)intermTyped + 0x44))(intermTyped,intermTyped);
  if (iVar1 != 2) {
    pcVar2 = (char *)(*(code *)**(undefined4 **)intermTyped)(intermTyped);
    error((int)this,pcVar2,"constant expression required","","",in_r8,in_r9,in_r10);
  }
  return iVar1 != 2;
}

/* TParseContext__integerErrorCheck @ 0x97b9af54 (172 bytes) */
int TParseContext__integerErrorCheck(this, intermTyped, str)
  unsigned char * this;
  unsigned char * intermTyped;
  char *str;
{
  int iVar1;
  char *pcVar2;
  undefined4 in_r8;
  undefined4 in_r9;
  undefined4 in_r10;
  
  iVar1 = (**(code **)(*(int *)intermTyped + 0x40))(intermTyped,intermTyped,str);
  if ((iVar1 == 2) && (iVar1 = (**(code **)(*(int *)intermTyped + 0x48))(intermTyped), iVar1 == 1)) {
    return 0;
  }
  pcVar2 = (char *)(*(code *)**(undefined4 **)intermTyped)(intermTyped);
  error((int)this,pcVar2,"integer expression required",str,"",in_r8,in_r9,in_r10);
  return 1;
}

/* TParseContext__globalErrorCheck @ 0x97b9b000 (84 bytes) */
int TParseContext__globalErrorCheck(this, param_2, param_3, str, param_5, param_6)
  unsigned char * this;
  int param_2;
  int param_3;
  char *str;
  undefined4 param_5;
  undefined4 param_6;
{
  undefined4 in_r9;
  undefined4 in_r10;
  
  if (param_3 == 0) {
    error((int)this,(char *)param_2,"only allowed at global scope",str,"",param_6,in_r9,in_r10);
  }
  return param_3 == 0;
}

/* TParseContext__reservedErrorCheck @ 0x97b9b054 (376 bytes) */
int TParseContext__reservedErrorCheck(this, param_2, text)
  unsigned char * this;
  int param_2;
  unsigned char * text;
{
  int atomicStore;
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
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_mm(&local_80,text,0,3);
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
        atomicStore = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
        *piVar3 = atomicStore;
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
        atomicStore = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
        *piVar3 = atomicStore;
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
int TParseContext__constructorErrorCheck(this, param_2, intermNode, function, op, type)
  unsigned char * this;
  int param_2;
  unsigned char * intermNode;
  unsigned char * function;
  int op;
  int *type;
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
  
  a6 = op - 0x66;
  iVar10 = param_2;
  pTVar12 = intermNode;
  pTVar14 = function;
  iVar16 = op;
  piVar18 = type;
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
    type[8] = 0;
    type[9] = uVar19 & 0x7f800 | uVar19 & 0xfff80000 | type[9] & 0x1ffU;
    local_bc = 0;
    local_b8 = (unsigned char *)0x0;
    local_b4 = 0;
    local_b0 = (void *)0x0;
    local_ac = 0;
    local_a8 = 0;
    local_a4 = 0;
    local_c0 = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
    local_a0 = 0;
    type[1] = 0;
    type[2] = 0;
    type[3] = 0;
    type[4] = 0;
    type[5] = 0;
    type[6] = 0;
    type[7] = 0;
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
    type[9] = uVar19 & 0x7f800 | uVar19 & 0xfff80000 | type[9] & 0x1ffU | 0x400;
    type[8] = 0;
    local_bc = 0;
    local_b8 = (unsigned char *)0x0;
    local_b4 = 0;
    local_b0 = (void *)0x0;
    local_ac = 0;
    local_a8 = 0;
    local_a4 = 0;
    local_c0 = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
    local_a0 = 0;
    type[1] = 0;
    type[2] = 0;
    type[3] = 0;
    type[4] = 0;
    type[5] = 0;
    type[6] = 0;
    type[7] = 0;
    local_8c = in_r10;
    local_9c = a6;
    goto LAB_97b9b714;
  case 0xf:
    pTVar20 = *(unsigned char **)(function + 0x24);
    psVar9 = (unsigned char *)
             (**(code **)(*(int *)(function + 0x1c) + 0x18))
                       (function + 0x1c,param_2,intermNode,function,op,type,function + 0x1c);
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
    type[1] = local_bc;
    type[2] = (int)local_b8;
    type[3] = local_b4;
    type[4] = (int)local_b0;
    type[5] = local_ac;
    type[6] = local_a8;
    type[7] = local_a4;
    type[9] = (local_9c >> 9 & 1) << 9 |
                 (local_9c >> 10 & 1) << 10 |
                 local_9c & 0x7f800 |
                 (local_9c >> 0x13 & 0x3f) << 0x13 | local_9c & 0xfe000000 | type[9] & 0x1ffU;
    piVar7 = (int *)(local_8c + -4);
    type[8] = local_a0;
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
  type[9] = iVar8 << 0xb | uVar19 & 0xfff80000 | type[9] & 0x1ffU;
  type[8] = 0;
  local_bc = 0;
  local_b8 = (unsigned char *)0x0;
  local_b4 = 0;
  local_b0 = (void *)0x0;
  local_ac = 0;
  local_a8 = 0;
  local_a4 = 0;
  local_c0 = &PTR___ZN5TTypeD1Ev_a7b7d4d0;
  local_a0 = 0;
  type[1] = 0;
  type[2] = 0;
  type[3] = 0;
  type[4] = 0;
  type[5] = 0;
  type[6] = 0;
  type[7] = 0;
  local_9c = a6;
LAB_97b9b714:
  iVar8 = 0;
  bVar3 = true;
  bVar2 = false;
  bVar6 = false;
  bVar5 = false;
  bVar4 = false;
  in_r10 = local_8c;
  for (iVar21 = 0; iVar21 < *(int *)(function + 0x14) - *(int *)(function + 0x10) >> 3;
      iVar21 = iVar21 + 1) {
    iVar1 = iVar21 * 8;
    piVar7 = *(int **)(*(int *)(function + 0x10) + iVar1 + 4);
    a6_00 = *piVar7;
    iVar10 = (**(code **)(a6_00 + 0x30))(piVar7,iVar10,pTVar12,pTVar14,iVar16,piVar18,a6_00);
    iVar8 = iVar8 + iVar10;
    uVar11 = a1;
    if ((op - 0x72U < 3) &&
       (piVar7 = *(int **)(*(int *)(function + 0x10) + iVar1 + 4), iVar10 = *piVar7,
       iVar10 = (**(code **)(iVar10 + 0x34))(piVar7,a1,pTVar12,pTVar14,iVar16,piVar18,iVar10),
       uVar11 = extraout_r4_02, iVar10 != 0)) {
      bVar5 = true;
    }
    if (bVar2) {
      bVar6 = true;
    }
    if ((op != 0x75) &&
       (iVar10 = (**(code **)(*type + 0x30))(type), uVar11 = extraout_r4_03, iVar10 <= iVar8))
    {
      bVar2 = true;
    }
    piVar7 = *(int **)(*(int *)(function + 0x10) + iVar1 + 4);
    iVar10 = *piVar7;
    iVar10 = (**(code **)(iVar10 + 0x24))(piVar7,uVar11,pTVar12,pTVar14,iVar16,piVar18,iVar10);
    if (iVar10 != 2) {
      bVar3 = false;
    }
    a0 = *(uint **)(*(int *)(function + 0x10) + iVar1 + 4);
    a6 = *a0;
    iVar10 = (**(code **)(a6 + 0x38))(a0,a1_00,pTVar12,pTVar14,iVar16,piVar18,a6);
    if (iVar10 != 0) {
      bVar4 = true;
    }
    iVar10 = extraout_r4_04;
  }
  if (bVar3) {
    (**(code **)(*type + 0x28))(type,2);
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
             (iVar21 = (**(code **)(*type + 0x30))(type,iVar10,pTVar12,pTVar14,iVar16),
             iVar10 = extraout_r4_06, iVar21 <= iVar8)) && ((0 < iVar8 || (op != 0x75)))) {
      piVar7 = (int *)(**(code **)(*(int *)intermNode + 0x14))(intermNode,iVar10,pTVar12,pTVar14,iVar16);
      if (piVar7 == (int *)0x0) {
        pcVar13 = "constructor argument does not have a type";
      }
      else {
        uVar11 = a1_01;
        if ((op == 0x75) ||
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
int TParseContext__voidErrorCheck(this, param_2, text, publicType)
  unsigned char * this;
  int param_2;
  unsigned char * text;
  unsigned char * publicType;
{
  byte bVar1;
  int iVar2;
  undefined4 in_r8;
  
  iVar2 = *(int *)publicType;
  if (iVar2 == 0) {
    bVar1 = *DAT_a7b7ba18;
    *(byte *)(*(int *)(text + 4) + *(int *)(*(int *)(text + 4) + -0xc)) = bVar1;
    error((int)this,(char *)param_2,"illegal use of type \'void\'",*(char **)(text + 4),"",in_r8,
          (uint)bVar1,text);
  }
  return iVar2 == 0;
}

