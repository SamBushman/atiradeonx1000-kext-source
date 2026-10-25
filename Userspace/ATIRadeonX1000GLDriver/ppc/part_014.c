#include "decls.h"

/* FUN_000934f0 @ 0x934f0 (20 bytes) */
int FUN_000934f0(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined1 auStack_a8 [4];
  undefined4 uStack_a4;
  undefined1 auStack_a0 [16];
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined1 auStack_80 [4];
  undefined4 uStack_7c;
  undefined1 auStack_78 [16];
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_5c;
  
  if (param_1 == 0) {
    return 1;
  }
  uVar1 = 0;
  iVar3 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x4e8) == -1) {
    if ((*(int *)(param_1 + 0x4c0) == -1) &&
       (FUN_00092350(param_1), *(int *)(param_1 + 0x4c0) == -1)) {
      return 2;
    }
    iVar2 = ffvpAllocTempRegister(param_1,1,param_1 + 0x4e4);
    if (iVar2 == 0) {
      uVar1 = *(undefined4 *)(param_1 + 0x4e8);
      iVar2 = ffvpAllocTempRegister(param_1,2,auStack_a8);
      if (iVar2 == 0) {
        iVar2 = ffvpAllocTempRegister(param_1,2,auStack_80);
        if (iVar2 == 0) {
          uVar5 = **(undefined4 **)(param_1 + 0x3ec);
          uVar4 = **(undefined4 **)(param_1 + 0x3f0);
          (**(code **)(((unsigned char *)0x000012f0) + iVar3))
                    (param_1,uVar4,uStack_a4,auStack_a0,uVar5,uStack_a4,&DAT_001dbdb4,&DAT_001fa5e8,uVar5,uStack_a4,&DAT_001dbdb4,&DAT_001fa5e8)
          ;
          uStack_d8 = 4;
          uStack_d4 = 4;
          uStack_cc = 4;
          uStack_d0 = uStack_88;
          (**(code **)(((unsigned char *)0x000012f4) + iVar3))
                    (param_1,uVar4,uVar1,&DAT_001dbd84,uVar5,uStack_a4,&uStack_90,&DAT_001fa5e8,uVar5,(*(int *)((int)param_1 + 1216)),(&DAT_001dbd74),&DAT_001fa5e8,uVar5,uStack_a4,(&uStack_d8),&DAT_001fa5e8);
          (**(code **)(((unsigned char *)0x000012e4) + iVar3))
                    (param_1,uVar4,uStack_a4,auStack_a0,uVar5,uVar1,&DAT_001dbd74,&DAT_001fa5e8,uVar5,uVar1,&DAT_001dbd74,&DAT_001fa5e8);
          (**(code **)(((unsigned char *)0x00001318) + iVar3))
                    (param_1,uVar4,uStack_a4,auStack_a0,uVar5,uStack_a4,&uStack_90,&DAT_001fa5e8);
          (**(code **)(((unsigned char *)0x0000131c) + iVar3))
                    (param_1,uVar4,uStack_7c,auStack_78,uVar5,uStack_7c,&DAT_001dbdb4,&DAT_001dbd94)
          ;
          uStack_c8 = *(undefined4 *)(param_1 + 0x4d4);
          uStack_c4 = *(undefined4 *)(param_1 + 0x4d8);
          uStack_b0 = 4;
          uStack_d0 = 4;
          uStack_cc = 4;
          uStack_d8 = uStack_90;
          uStack_d4 = uStack_8c;
          uStack_c0 = 4;
          uStack_bc = 4;
          uStack_b8 = uStack_68;
          uStack_b4 = uStack_64;
          uStack_ac = uStack_5c;
          (**(code **)(((unsigned char *)0x000012f4) + iVar3))
                    (param_1,uVar4,uVar1,&DAT_001dbd84,uVar5,uStack_a4,&uStack_d8,&DAT_001fa5e8,uVar5,(*(int *)((int)param_1 + 1216)),(&uStack_c8),&DAT_001fa5e8,uVar5,uStack_7c,(&uStack_b8),&DAT_001fa5e8);
          FUN_000911a0(param_1,auStack_a8);
          FUN_000911a0(param_1,auStack_80);
          return 0;
        }
      }
    }
    uVar1 = 7;
  }
  return uVar1;
}

/* FUN_00093510 @ 0x93510 (1220 bytes) */
int FUN_00093510(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  uint param_3;
  int param_4;
{
  uint loopIndex;
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  uint uVar9;
  undefined1 auStack_e8 [4];
  undefined4 local_e4;
  undefined1 auStack_c0 [4];
  undefined4 local_bc;
  undefined1 auStack_98 [4];
  undefined4 local_94;
  undefined *local_68;
  undefined *local_64;
  undefined *local_60;
  undefined1 *local_5c;
  int *local_58;
  undefined1 *local_54;
  int iVarS1;
  int iVarS2;
  
  if (param_1 == 0) {
    return 1;
  }
  if (4 < param_3) {
    return 4;
  }
  if (param_3 != 0) {
    iVar2 = 0;
    iVar3 = param_1;
    uVar9 = param_3;
    do {
      iVar1 = *(int *)(param_2 + iVar2 * 4);
      if (iVar1 == 0) {
        iVar1 = *(int *)(param_1 + 4);
      }
      else {
        if (iVar1 != 1) {
          return 3;
        }
        iVar1 = *(int *)(param_1 + 100);
      }
      if (iVar1 == -1) {
        return 2;
      }
      if (*(int *)(iVar3 + 0xc4) == -1) {
        return 2;
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 4;
      uVar9 = uVar9 - 1;
    } while (uVar9 != 0);
  }
  if ((param_3 < 4) && (param_4 != 0)) {
    iVar3 = *(int *)(param_2 + param_3 * 4);
    if (iVar3 == 0) {
      iVar3 = *(int *)(param_1 + 4);
    }
    else {
      if (iVar3 != 1) {
        return 3;
      }
      iVar3 = *(int *)(param_1 + 100);
    }
    if (iVar3 == -1) {
      return 2;
    }
    if (*(int *)(param_3 * 4 + param_1 + 0xc4) == -1) {
      return 2;
    }
  }
  iVar3 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x448) != -1) {
    return 0;
  }
  if ((*(int *)(param_1 + 0x560) == -1) &&
     (FUN_00091eb0(param_1,param_3,param_4), *(int *)(param_1 + 0x560) == -1)) {
    return 2;
  }
  if ((param_3 < 4) && (param_4 != 0)) {
    param_3 = param_3 + 1;
  }
  iVar2 = ffvpAllocTempRegister(param_1,1,param_1 + 0x444);
  if ((iVar2 == 0) && (iVar2 = ffvpAllocTempRegister(param_1,0,auStack_e8), iVar2 == 0)) {
    local_5c = auStack_c0;
    iVar2 = ffvpAllocTempRegister(param_1,0,local_5c);
    if (iVar2 == 0) {
      local_54 = auStack_98;
      iVar2 = ffvpAllocTempRegister(param_1,0,local_54);
      if (iVar2 == 0) {
        puVar7 = *(undefined4 **)(param_1 + 0x3ec);
        uVar6 = puVar7[2];
        uVar4 = **(undefined4 **)(param_1 + 0x3f0);
        if (param_3 == 0) {
          local_68 = &DAT_001e3520;
          local_64 = &DAT_001e3520;
          local_60 = &DAT_001e3520;
LAB_0009388c:
          uVar8 = *puVar7;
          uVar6 = *(undefined4 *)(param_1 + 0x448);
          iVarS1 = *(int *)((int)param_1 + 1376);
          (**(code **)(((unsigned char *)0x000012e4) + iVar3))
                    (param_1,uVar4,uVar6,local_68 + -0x781c,uVar8,local_e4,&DAT_001dbd14,
                     &DAT_001fa5e8,uVar8,iVarS1,&DAT_001dbd14,&DAT_001fa5e8);
          (**(code **)(((unsigned char *)0x000012e4) + iVar3))
                    (param_1,uVar4,uVar6,local_64 + -0x77bc,uVar8,local_bc,&DAT_001dbd14,
                     &DAT_001fa5e8,uVar8,iVarS1,&DAT_001dbd14,&DAT_001fa5e8);
          (**(code **)(((unsigned char *)0x000012e4) + iVar3))
                    (param_1,uVar4,uVar6,local_60 + -0x77cc,uVar8,local_94,&DAT_001dbd14,
                     &DAT_001fa5e8,uVar8,iVarS1,&DAT_001dbd14,&DAT_001fa5e8);
          FUN_000911a0(param_1,auStack_e8);
          FUN_000911a0(param_1,local_5c);
          FUN_000911a0(param_1,local_54);
          return 0;
        }
        local_58 = (int *)(param_1 + 0xc4);
        local_68 = &DAT_001e3520;
        local_64 = &DAT_001e3520;
        local_60 = &DAT_001e3520;
LAB_00093754:
        loopIndex = 0;
        puVar7 = (undefined4 *)(local_68 + -0x781c);
        piVar5 = local_58;
        do {
          iVar2 = *piVar5;
          loopIndex = loopIndex + 1;
          iVarS2 = *(int *)((int)*(int *)((int)param_1 + 1004) + 4);
          (**(code **)(((unsigned char *)0x000012e4) + iVar3))
                    (param_1,uVar4,local_e4,puVar7,uVar6,iVar2,&DAT_001dbd74,&DAT_001fa5e8,iVarS2,(*(int *)(param_2 + (loopIndex - 1) * 4) == 0 ? *(int *)(param_1 + 4) : (*(int *)(param_2 + (loopIndex - 1) * 4) == 1 ? *(int *)(param_1 + 100) : 0)),&DAT_001dbd74,&DAT_001fa5e8);
          (**(code **)(((unsigned char *)0x000012e4) + iVar3))
                    (param_1,uVar4,local_bc,puVar7,uVar6,iVar2 + 1,&DAT_001dbd74,&DAT_001fa5e8,iVarS2,(*(int *)(param_2 + (loopIndex - 1) * 4) == 0 ? *(int *)(param_1 + 4) : (*(int *)(param_2 + (loopIndex - 1) * 4) == 1 ? *(int *)(param_1 + 100) : 0)),&DAT_001dbd74,&DAT_001fa5e8);
          (**(code **)(((unsigned char *)0x000012e4) + iVar3))
                    (param_1,uVar4,local_94,puVar7,uVar6,iVar2 + 2,&DAT_001dbd74,&DAT_001fa5e8,iVarS2,(*(int *)(param_2 + (loopIndex - 1) * 4) == 0 ? *(int *)(param_1 + 4) : (*(int *)(param_2 + (loopIndex - 1) * 4) == 1 ? *(int *)(param_1 + 100) : 0)),&DAT_001dbd74,&DAT_001fa5e8);
          if (param_3 <= loopIndex) {
            puVar7 = *(undefined4 **)(param_1 + 0x3ec);
            goto LAB_0009388c;
          }
          if (loopIndex == 1) {
            puVar7 = (undefined4 *)(local_64 + -0x77bc);
          }
          else {
            if (loopIndex == 0) goto LAB_00093754;
            if (loopIndex == 2) {
              puVar7 = (undefined4 *)(local_60 + -0x77cc);
            }
            else {
              puVar7 = (undefined4 *)0x0;
              if (loopIndex == 3) {
                puVar7 = &DAT_001dbd44;
              }
            }
          }
          piVar5 = piVar5 + 1;
        } while( true );
      }
    }
  }
  return 7;
}

/* FUN_000939e0 @ 0x939e0 (52 bytes) */
int FUN_000939e0(param_1)
  int param_1;
{
  undefined4 uVar1;
  
  uVar1 = 1;
  if (param_1 != 0) {
    if ((*(int *)(param_1 + 4) != -1) && (*(int *)(param_1 + 0x344) != -1)) {
      uVar1 = FUN_00091d70(param_1);
      return uVar1;
    }
    uVar1 = 2;
  }
  return uVar1;
}

/* FUN_00093a20 @ 0x93a20 (24 bytes) */
int FUN_00093a20(param_1)
  int param_1;
{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 4) != -1) {
    uVar1 = FUN_00091b90(param_1);
    return uVar1;
  }
  return 2;
}

/* FUN_00093a40 @ 0x93a40 (3576 bytes) */
int FUN_00093a40(param_1, param_2, param_3, param_4, param_5, param_6)
  int *param_1;
  int param_2;
  uint param_3;
  int param_4;
  int param_5;
  uint param_6;
{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  undefined *puVar10;
  undefined *puVar11;
  undefined *puVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  uint uVar15;
  uint uStack0000002c;
  undefined1 auStack_1c8 [4];
  int local_1c4;
  undefined1 auStack_1a0 [4];
  undefined4 local_19c;
  undefined1 auStack_178 [4];
  int local_174;
  undefined1 auStack_150 [4];
  undefined4 local_14c;
  undefined1 auStack_128 [4];
  undefined4 local_124 [9];
  undefined1 auStack_100 [4];
  undefined4 local_fc;
  undefined1 auStack_d8 [4];
  undefined4 local_d4;
  undefined1 auStack_b0 [4];
  undefined4 local_ac;
  undefined *local_88;
  undefined1 *local_84;
  undefined *local_80;
  undefined1 *local_7c;
  undefined1 *local_78;
  undefined *local_74;
  undefined1 *local_70;
  undefined1 *local_6c;
  undefined1 *local_68;
  undefined *local_64;
  undefined *local_60;
  undefined *local_5c;
  undefined *local_58;
  undefined *local_54;
  int iVarS1;
  int iVarS2;
  int iVarS3;
  int iVarS4;
  int iVarS5;
  int iVarS6;
  int iVarS7;
  int iVarS8;
  int iVarS9;
  int iVarS10;
  int iVarS11;
  int iVarS12;
  int iVarS13;
  int iVarS14;
  int iVarS15;
  int iVarS16;
  int iVarS17;
  int iVarS18;
  int iVarS19;
  int iVarS20;
  int iVarS21;
  int iVarS22;
  int iVarS23;
  int iVarS24;
  int iVarS25;
  int iVarS26;
  int iVarS27;
  
  if (param_1 == (int *)0x0) {
    return 1;
  }
  if (4 < param_3) {
    return 4;
  }
  if (param_3 != 0) {
    iVar4 = 0;
    piVar6 = param_1;
    uVar15 = param_3;
    do {
      iVar2 = *(int *)(param_2 + iVar4 * 4);
      if (iVar2 == 0) {
        iVar2 = *param_1;
      }
      else {
        if (iVar2 != 1) {
          return 3;
        }
        iVar2 = param_1[0x18];
      }
      if (iVar2 == -1) {
        return 2;
      }
      if (piVar6[0x29] == -1) {
        return 2;
      }
      iVar4 = iVar4 + 1;
      piVar6 = piVar6 + 1;
      uVar15 = uVar15 - 1;
    } while (uVar15 != 0);
  }
  if ((param_3 < 4) && (param_4 != 0)) {
    iVar4 = *(int *)(param_2 + param_3 * 4);
    if (iVar4 == 0) {
      iVar4 = *param_1;
    }
    else {
      if (iVar4 != 1) {
        return 3;
      }
      iVar4 = param_1[0x18];
    }
    if (iVar4 == -1) {
      return 2;
    }
    if (param_1[param_3 + 0x29] == -1) {
      return 2;
    }
  }
  if (param_1[0x1a] != -1) {
    bVar1 = param_5 == 0;
    if (!bVar1) {
      if (7 < param_6) {
        return 3;
      }
      if (param_1[param_6 + 0x21] == -1) {
        return 2;
      }
    }
    iVar4 = param_1[0xf5];
    uStack0000002c = param_6;
    if ((*(uint *)(((unsigned char *)0x000013c0) + iVar4) & 4) == 0) {
      if ((param_1[0x158] != -1) || (FUN_00091eb0(param_1,param_3,param_4), param_1[0x158] != -1)) {
        if ((param_3 < 4) && (param_4 != 0)) {
          param_3 = param_3 + 1;
        }
        local_68 = auStack_1a0;
        iVar2 = ffvpAllocTempRegister(param_1,0,local_68);
        if ((iVar2 == 0) && (iVar2 = ffvpAllocTempRegister(param_1,0,auStack_1c8), iVar2 == 0)) {
          local_84 = auStack_150;
          iVar2 = ffvpAllocTempRegister(param_1,0,local_84);
          if (iVar2 == 0) {
            local_7c = auStack_128;
            iVar2 = ffvpAllocTempRegister(param_1,0,local_7c);
            if (iVar2 == 0) {
              uVar8 = *(undefined4 *)param_1[0xfc];
              uVar7 = *(undefined4 *)param_1[0xfb];
              uVar13 = ((undefined4 *)param_1[0xfb])[2];
              if (param_3 == 0) {
LAB_000944c4:
                if (bVar1) {
                  uVar8 = *(undefined4 *)(param_1[0xfc] + 8);
                  iVar2 = param_1[0x1a];
                }
                else {
                  iVar2 = ffvpAllocTempRegister(param_1,0,auStack_178);
                  if (iVar2 != 0) {
                    return 7;
                  }
                  uVar8 = *(undefined4 *)param_1[0xfc];
                  iVar2 = local_174;
                }
                local_88 = &DAT_001e3a54;
                local_80 = &DAT_001f3a54;
                iVarS1 = *(int *)((int)param_1 + 1376);
                (**(code **)(((unsigned char *)0x000012e4) + iVar4))
                          (param_1,uVar8,iVar2,&DAT_001dbd04,uVar7,local_19c,&DAT_001dbd14,
                           &DAT_001fa5e8,uVar7,iVarS1,&DAT_001dbd14,&DAT_001fa5e8);
                (**(code **)(((unsigned char *)0x000012e4) + iVar4))
                          (param_1,uVar8,iVar2,&DAT_001dbd64,uVar7,local_1c4,&DAT_001dbd14,
                           &DAT_001fa5e8,uVar7,iVarS1,&DAT_001dbd14,&DAT_001fa5e8);
                (**(code **)(((unsigned char *)0x000012e4) + iVar4))
                          (param_1,uVar8,iVar2,&DAT_001dbd54,uVar7,local_14c,&DAT_001dbd14,
                           &DAT_001fa5e8,uVar7,iVarS1,&DAT_001dbd14,&DAT_001fa5e8);
                if ((*(char *)(param_1 + 0x1d1) == '\0') || (param_1[0x1a8] != -1)) {
                  iVarS2 = *(int *)((int)param_1 + 1376);
                  (**(code **)(((unsigned char *)0x000012e4) + iVar4))
                            (param_1,uVar8,iVar2,&DAT_001dbd44,uVar7,local_124[0],&DAT_001dbd14,
                             &DAT_001fa5e8,uVar7,iVarS2,&DAT_001dbd14,&DAT_001fa5e8);
                  FUN_000911a0(param_1,local_68);
                  FUN_000911a0(param_1,auStack_1c8);
                  FUN_000911a0(param_1,local_84);
                  FUN_000911a0(param_1,local_7c);
                }
                else {
                  iVarS3 = *(int *)((int)param_1 + 1376);
                  (**(code **)(((unsigned char *)0x000012e4) + iVar4))
                            (param_1,*(undefined4 *)param_1[0xfc],local_19c,&DAT_001dbd44,uVar7,
                             local_124[0],&DAT_001dbd14,&DAT_001fa5e8,uVar7,iVarS3,&DAT_001dbd14,&DAT_001fa5e8);
                  (**(code **)(((unsigned char *)0x000012e8) + iVar4))
                            (param_1,uVar8,iVar2,&DAT_001dbd44,uVar7,local_19c,&DAT_001dbcd4,
                             &DAT_001fa5e8);
                  FUN_00091980(param_1,uVar7,local_19c);
                  FUN_000911a0(param_1,local_68);
                  FUN_000911a0(param_1,auStack_1c8);
                  FUN_000911a0(param_1,local_84);
                  FUN_000911a0(param_1,local_7c);
                  if (param_1[0x1a8] == -1) {
                    FUN_000911a0(param_1,auStack_178);
                    return 2;
                  }
                }
                if (!bVar1) {
                  puVar11 = local_88 + -0x7d40;
                  puVar10 = local_80 + 0x6b94;
                  (**(code **)(((unsigned char *)0x000012e8) + iVar4))
                            (param_1,*(undefined4 *)(param_1[0xfc] + 8),param_1[0x1a],&DAT_001dbd24,
                             uVar7,local_174,puVar11,puVar10);
                  (**(code **)(((unsigned char *)0x000012e8) + iVar4))
                            (param_1,*(undefined4 *)(param_1[0xfc] + 0x14),
                             param_1[uStack0000002c + 0x21],&DAT_001dbd24,uVar7,local_174,puVar11,
                             puVar10);
                  FUN_000911a0(param_1,auStack_178);
                }
                return 0;
              }
              local_88 = &DAT_001e3a54;
              local_80 = &DAT_001f3a54;
              local_74 = &DAT_001e3a54;
LAB_00094348:
              uVar15 = 0;
              puVar3 = (undefined4 *)(local_74 + -0x7d50);
              piVar6 = param_1 + 0x29;
              do {
                iVar2 = *piVar6;
                uVar15 = uVar15 + 1;
                puVar11 = local_88 + -0x7d40;
                puVar10 = local_80 + 0x6b94;
                iVarS4 = *(int *)((int)*(int *)((int)param_1 + 1004) + 4);
                (**(code **)(((unsigned char *)0x000012e4) + iVar4))
                          (param_1,uVar8,local_19c,puVar3,uVar13,iVar2,puVar11,puVar10,iVarS4,iVar4,puVar11,puVar10);
                (**(code **)(((unsigned char *)0x000012e4) + iVar4))
                          (param_1,uVar8,local_1c4,puVar3,uVar13,iVar2 + 1,puVar11,puVar10,iVarS4,iVar4,puVar11,puVar10);
                (**(code **)(((unsigned char *)0x000012e4) + iVar4))
                          (param_1,uVar8,local_14c,puVar3,uVar13,iVar2 + 2,puVar11,puVar10,iVarS4,iVar4,puVar11,puVar10);
                (**(code **)(((unsigned char *)0x000012e4) + iVar4))
                          (param_1,uVar8,local_124[0],puVar3,uVar13,iVar2 + 3,puVar11,puVar10,iVarS4,iVar4,puVar11,puVar10);
                if (param_3 <= uVar15) goto LAB_000944c4;
                if (uVar15 == 1) {
                  puVar3 = &DAT_001dbd64;
                }
                else {
                  if (uVar15 == 0) goto LAB_00094348;
                  if (uVar15 == 2) {
                    puVar3 = &DAT_001dbd54;
                  }
                  else {
                    puVar3 = (undefined4 *)0x0;
                    if (uVar15 == 3) {
                      puVar3 = &DAT_001dbd44;
                    }
                  }
                }
                piVar6 = piVar6 + 1;
              } while( true );
            }
          }
        }
        return 7;
      }
    }
    else if ((param_1[0x158] != -1) || (FUN_00091eb0(param_1,param_3,param_4), param_1[0x158] != -1)
            ) {
      if ((param_3 < 4) && (param_4 != 0)) {
        param_3 = param_3 + 1;
      }
      local_7c = auStack_128;
      iVar2 = ffvpAllocTempRegister(param_1,0,local_7c);
      if (iVar2 != 0) {
        return 7;
      }
      local_78 = auStack_100;
      iVar2 = ffvpAllocTempRegister(param_1,0,local_78);
      if (iVar2 != 0) {
        return 7;
      }
      local_70 = auStack_d8;
      iVar2 = ffvpAllocTempRegister(param_1,0,local_70);
      if (iVar2 != 0) {
        return 7;
      }
      local_6c = auStack_b0;
      iVar2 = ffvpAllocTempRegister(param_1,0,local_6c);
      if (iVar2 != 0) {
        return 7;
      }
      iVar2 = ffvpAllocTempRegister(param_1,0,auStack_1c8);
      if (iVar2 != 0) {
        return 7;
      }
      puVar5 = (undefined4 *)param_1[0xfb];
      puVar3 = (undefined4 *)param_1[0xfc];
      uVar7 = *puVar5;
      uVar13 = *puVar3;
      uVar8 = puVar5[2];
      if (param_3 == 0) {
        local_54 = &DAT_001e3a54;
        local_88 = &DAT_001e3a54;
        local_80 = &DAT_001f3a54;
        local_64 = &DAT_001e3a54;
        local_58 = &DAT_001e3a54;
        local_5c = &DAT_001e3a54;
        local_60 = &DAT_001f3a54;
      }
      else {
        local_54 = &DAT_001e3a54;
        local_88 = &DAT_001e3a54;
        local_80 = &DAT_001f3a54;
        local_64 = &DAT_001e3a54;
        local_5c = &DAT_001e3a54;
        local_58 = &DAT_001e3a54;
        uVar15 = 0;
        local_60 = &DAT_001f3a54;
        puVar3 = local_124;
        piVar6 = param_1;
        do {
          iVar2 = piVar6[0x29];
          uVar14 = *puVar3;
          uVar15 = uVar15 + 1;
          piVar6 = piVar6 + 1;
          puVar3 = puVar3 + 10;
          iVarS5 = *(int *)((int)*(int *)((int)param_1 + 1004) + 4);
          iVarS6 = *(int *)((int)*(int *)((int)param_1 + 980) + 4844);
          iVarS21 = *(int *)((int)*(int *)((int)param_1 + 1004) + 4);
          iVarS22 = (int)local_64 + -32128;
          (**(code **)(((unsigned char *)0x000012ec) + iVar4))
                    (param_1,uVar13,uVar14,&DAT_001dbd24,uVar8,iVar2 + 3,&DAT_001dbd14,&DAT_001fa5e8,iVarS21,iVar4,iVarS22,&DAT_001fa5e8);
          iVarS14 = *(int *)((int)*(int *)((int)param_1 + 1004) + 4);
          iVarS15 = (int)local_58 + -32096;
          (**(code **)(((unsigned char *)0x000012f4) + iVar4))
                    (param_1,uVar13,uVar14,&DAT_001dbd24,uVar8,iVar2 + 2,&DAT_001dbd14,&DAT_001fa5e8
                    ,iVarS14,iVar4,iVarS15,&DAT_001fa5e8,uVar13,uVar14,&DAT_001dbd14,&DAT_001fa5e8);
          iVarS16 = (int)local_5c + -32112;
          (**(code **)(((unsigned char *)0x000012f4) + iVar4))
                    (param_1,uVar13,uVar14,&DAT_001dbd24,uVar8,iVar2 + 1,&DAT_001dbd14,&DAT_001fa5e8
                    ,iVarS14,iVar4,iVarS16,&DAT_001fa5e8,uVar13,uVar14,&DAT_001dbd14,&DAT_001fa5e8);
          iVarS17 = (int)local_60 + 27556;
          (**(code **)(((unsigned char *)0x000012f4) + iVar4))
                    (param_1,uVar13,uVar14,&DAT_001dbd24,uVar8,iVar2,&DAT_001dbd14,&DAT_001fa5e8,iVarS14,iVar4,iVarS17,&DAT_001fa5e8,uVar13,uVar14,&DAT_001dbd14,&DAT_001fa5e8);
        } while (param_3 != uVar15);
        puVar3 = (undefined4 *)param_1[0xfc];
        puVar5 = (undefined4 *)param_1[0xfb];
      }
      iVar2 = local_1c4;
      if (bVar1) {
        uVar8 = puVar3[2];
        iVar9 = param_1[0x1a];
      }
      else {
        uVar8 = *puVar3;
        iVar9 = local_1c4;
      }
      uVar13 = *puVar5;
      puVar12 = local_80 + 0x6b94;
      puVar11 = local_88 + -0x7d40;
      puVar10 = local_54 + -0x7d30;
      iVarS12 = *(int *)((int)param_1 + 1376);
      iVarS13 = (int)local_64 + -32128;
      (**(code **)(((unsigned char *)0x000012ec) + iVar4))
                (param_1,uVar13,local_1c4,puVar10,uVar7,local_ac,puVar11,puVar12,uVar13,iVarS12,iVarS13,puVar12);
      iVarS7 = *(int *)((int)param_1 + 1376);
      iVarS8 = *(int *)((int)*(int *)((int)param_1 + 980) + 4852);
      iVarS23 = *(int *)((int)param_1 + 1376);
      iVarS24 = (int)local_58 + -32096;
      (**(code **)(((unsigned char *)0x000012f4) + iVar4))
                (param_1,uVar13,iVar2,puVar10,uVar7,local_d4,puVar11,puVar12,uVar13,iVarS23,iVarS24,puVar12,uVar13,iVar2,puVar11,puVar12);
      iVarS9 = *(int *)((int)*(int *)((int)param_1 + 980) + 4852);
      iVarS25 = (int)local_5c + -32112;
      (**(code **)(((unsigned char *)0x000012f4) + iVar4))
                (param_1,uVar13,iVar2,puVar10,uVar7,local_fc,puVar11,puVar12,uVar13,iVarS23,iVarS25,puVar12,uVar13,iVar2,puVar11,puVar12);
      if ((*(char *)(param_1 + 0x1d1) == '\0') || (param_1[0x1a8] != -1)) {
        iVarS18 = *(int *)((int)param_1 + 1376);
        iVarS19 = (int)local_60 + 27556;
        iVarS20 = local_1c4;
        (**(code **)(((unsigned char *)0x000012f4) + iVar4))
                  (param_1,uVar8,iVar9,puVar10,uVar7,local_124[0],puVar11,puVar12,uVar7,iVarS18,iVarS19,puVar12,uVar7,iVarS20,puVar11,puVar12);
      }
      else {
        iVarS10 = *(int *)((int)param_1 + 1376);
        iVarS11 = *(int *)((int)*(int *)((int)param_1 + 980) + 4852);
        iVarS26 = *(int *)((int)param_1 + 1376);
        iVarS27 = (int)local_60 + 27556;
        (**(code **)(((unsigned char *)0x000012f4) + iVar4))
                  (param_1,uVar13,iVar2,puVar10,uVar7,local_124[0],puVar11,puVar12,uVar13,iVarS26,iVarS27,puVar12,uVar13,iVar2,puVar11,puVar12);
        if (bVar1) {
          (**(code **)(((unsigned char *)0x000012e8) + iVar4))
                    (param_1,*(undefined4 *)(param_1[0xfc] + 8),param_1[0x1a],puVar10,uVar7,
                     local_1c4,puVar11,puVar12);
        }
        FUN_00091980(param_1,uVar7,local_1c4);
        if (param_1[0x1a8] == -1) {
          FUN_000911a0(param_1,local_7c);
          FUN_000911a0(param_1,local_78);
          FUN_000911a0(param_1,local_70);
          FUN_000911a0(param_1,local_6c);
          FUN_000911a0(param_1,auStack_1c8);
          return 2;
        }
      }
      if (!bVar1) {
        puVar12 = local_54 + -0x7d30;
        puVar11 = local_88 + -0x7d40;
        puVar10 = local_80 + 0x6b94;
        (**(code **)(((unsigned char *)0x000012e8) + iVar4))
                  (param_1,*(undefined4 *)(param_1[0xfc] + 8),param_1[0x1a],puVar12,uVar7,local_1c4,
                   puVar11,puVar10);
        (**(code **)(((unsigned char *)0x000012e8) + iVar4))
                  (param_1,*(undefined4 *)(param_1[0xfc] + 0x14),param_1[uStack0000002c + 0x21],
                   puVar12,uVar7,local_1c4,puVar11,puVar10);
      }
      FUN_000911a0(param_1,local_7c);
      FUN_000911a0(param_1,local_78);
      FUN_000911a0(param_1,local_70);
      FUN_000911a0(param_1,local_6c);
      FUN_000911a0(param_1,auStack_1c8);
      return 0;
    }
  }
  return 2;
}

/* FUN_00094840 @ 0x94840 (3400 bytes) */
int FUN_00094840(param_1, param_2, param_3, param_4, param_5)
  int *param_1;
  int param_2;
  uint param_3;
  int param_4;
  int param_5;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  code *pcVar7;
  undefined4 *puVar8;
  code *pcVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined **ppuVar12;
  uint uVar13;
  undefined1 auStack_1b8 [4];
  undefined4 local_1b4;
  undefined1 auStack_190 [4];
  undefined4 local_18c;
  undefined1 auStack_168 [4];
  undefined4 local_164;
  undefined1 auStack_140 [4];
  undefined4 local_13c [9];
  undefined1 auStack_118 [4];
  undefined4 local_114;
  undefined1 auStack_f0 [4];
  undefined4 local_ec;
  undefined1 auStack_c8 [4];
  undefined4 local_c4;
  undefined1 *local_98;
  undefined1 *local_94;
  undefined1 *local_90;
  undefined **local_8c;
  code *local_88;
  undefined1 *local_84;
  code *local_80;
  undefined **local_7c;
  code *local_78;
  code *local_74;
  code *local_70;
  code *local_6c;
  code *local_68;
  code *local_64;
  undefined1 *local_60;
  code *local_5c;
  int iVarS1;
  int iVarS2;
  int iVarS3;
  int iVarS4;
  int iVarS5;
  int iVarS6;
  int iVarS7;
  int iVarS8;
  int iVarS9;
  int iVarS10;
  int iVarS11;
  int iVarS12;
  int iVarS13;
  int iVarS14;
  int iVarS15;
  int iVarS16;
  int iVarS17;
  int iVarS18;
  int iVarS19;
  
  if (param_1 == (int *)0x0) {
    return 1;
  }
  if (4 < param_3) {
    return 4;
  }
  if (param_3 != 0) {
    iVar2 = 0;
    piVar4 = param_1;
    uVar13 = param_3;
    do {
      iVar1 = *(int *)(param_2 + iVar2 * 4);
      if (iVar1 == 0) {
        iVar1 = *param_1;
      }
      else {
        if (iVar1 != 1) {
          return 3;
        }
        iVar1 = param_1[0x18];
      }
      if (iVar1 == -1) {
        return 2;
      }
      if (piVar4[0x2d] == -1) {
        return 2;
      }
      iVar2 = iVar2 + 1;
      piVar4 = piVar4 + 1;
      uVar13 = uVar13 - 1;
    } while (uVar13 != 0);
  }
  if ((param_3 < 4) && (param_4 != 0)) {
    iVar2 = *(int *)(param_2 + param_3 * 4);
    if (iVar2 == 0) {
      iVar2 = *param_1;
    }
    else {
      if (iVar2 != 1) {
        return 3;
      }
      iVar2 = param_1[0x18];
    }
    if (iVar2 == -1) {
      return 2;
    }
    if (param_1[param_3 + 0x2d] == -1) {
      return 2;
    }
  }
  iVar2 = param_1[0xf5];
  if ((*(uint *)(((unsigned char *)0x000013c0) + iVar2) & 4) == 0) {
    if (param_1[0xfe] != -1) {
      return 0;
    }
    iVar1 = param_1[0x158];
    if (iVar1 == -1) {
      FUN_00091eb0(param_1,param_3,param_4);
      iVar1 = param_1[0x158];
      if (iVar1 == -1) {
        return 2;
      }
    }
    if ((param_3 < 4) && (param_4 != 0)) {
      param_3 = param_3 + 1;
    }
    iVar3 = ffvpAllocTempRegister(param_1,0,param_1 + 0xfd);
    if ((iVar3 == 0) && (iVar3 = ffvpAllocTempRegister(param_1,0,auStack_1b8), iVar3 == 0)) {
      iVar3 = ffvpAllocTempRegister(param_1,0,auStack_190);
      if (iVar3 == 0) {
        local_60 = auStack_168;
        iVar3 = ffvpAllocTempRegister(param_1,0,local_60);
        if (iVar3 == 0) {
          local_98 = auStack_140;
          iVar3 = ffvpAllocTempRegister(param_1,0,local_98);
          if (iVar3 == 0) {
            puVar8 = (undefined4 *)param_1[0xfb];
            uVar6 = puVar8[2];
            uVar5 = *(undefined4 *)param_1[0xfc];
            if ((param_3 < 3) && (param_5 != 0)) {
              if (param_3 != 0) {
                local_88 = IrFetchTextureMapBias__dtor;
                local_8c = &PTR_DAT_001f4850;
                local_6c = IrFetchTextureMapBias__dtor;
                local_68 = IrFetchTextureMapBias__dtor;
                local_64 = IrFetchTextureMapBias__dtor;
                local_70 = IrFetchTextureMapBias__dtor;
                do {
                  uVar13 = 0;
                  uVar10 = local_1b4;
                  piVar4 = param_1 + 0x2d;
                  while( true ) {
                    iVar3 = *piVar4;
                    uVar13 = uVar13 + 1;
                    pcVar7 = local_88 + 0x74c4;
                    ppuVar12 = local_8c + 0x1766;
                    iVarS1 = *(int *)((int)*(int *)((int)param_1 + 1004) + 4);
                    (**(code **)(((unsigned char *)0x000012e4) + iVar2))
                              (param_1,uVar5,uVar10,local_6c + 0x74b4,uVar6,iVar3,pcVar7,ppuVar12,iVarS1,iVar2,pcVar7,ppuVar12);
                    (**(code **)(((unsigned char *)0x000012e4) + iVar2))
                              (param_1,uVar5,uVar10,local_68 + 0x7514,uVar6,iVar3 + 1,pcVar7,
                               ppuVar12,iVarS1,iVar2,pcVar7,ppuVar12);
                    (**(code **)(((unsigned char *)0x000012e4) + iVar2))
                              (param_1,uVar5,uVar10,local_64 + 0x7504,uVar6,iVar3 + 2,pcVar7,
                               ppuVar12,iVarS1,iVar2,pcVar7,ppuVar12);
                    (**(code **)(((unsigned char *)0x000012e4) + iVar2))
                              (param_1,uVar5,uVar10,local_70 + 0x74f4,uVar6,iVar3 + 3,pcVar7,
                               ppuVar12,iVarS1,iVar2,pcVar7,ppuVar12);
                    if (param_3 <= uVar13) {
                      puVar8 = (undefined4 *)param_1[0xfb];
                      goto LAB_0009510c;
                    }
                    if (uVar13 == 0) break;
                    uVar10 = 0;
                    if (uVar13 == 1) {
                      uVar10 = local_18c;
                    }
                    piVar4 = piVar4 + 1;
                  }
                } while( true );
              }
              local_88 = IrFetchTextureMapBias__dtor;
              local_8c = &PTR_DAT_001f4850;
LAB_0009510c:
              uVar6 = *puVar8;
              iVar3 = param_1[0xfe];
              ppuVar12 = local_8c + 0x1766;
              iVarS4 = local_1b4;
              iVarS5 = (int)local_88 + 29892;
              (**(code **)(((unsigned char *)0x000012ec) + iVar2))
                        (param_1,uVar5,iVar3,&DAT_001dbd24,uVar6,iVar1,&DAT_001fa5f8,ppuVar12,uVar6,iVarS4,iVarS5,ppuVar12);
              iVarS10 = local_18c;
              iVarS11 = (int)local_88 + 29892;
              (**(code **)(((unsigned char *)0x000012f4) + iVar2))
                        (param_1,uVar5,iVar3,&DAT_001dbd24,uVar6,iVar1,&DAT_001dbce4,ppuVar12,uVar6,iVarS10,iVarS11,ppuVar12,uVar6,iVar3,iVarS11,ppuVar12);
            }
            else {
              if (param_3 != 0) {
                local_88 = IrFetchTextureMapBias__dtor;
                local_8c = &PTR_DAT_001f4850;
                local_6c = IrFetchTextureMapBias__dtor;
                local_68 = IrFetchTextureMapBias__dtor;
                local_64 = IrFetchTextureMapBias__dtor;
                local_70 = IrFetchTextureMapBias__dtor;
LAB_00095234:
                uVar13 = 0;
                pcVar7 = local_6c + 0x74b4;
                piVar4 = param_1 + 0x2d;
                do {
                  iVar1 = *piVar4;
                  uVar13 = uVar13 + 1;
                  pcVar9 = local_88 + 0x74c4;
                  ppuVar12 = local_8c + 0x1766;
                  iVarS2 = *(int *)((int)*(int *)((int)param_1 + 1004) + 4);
                  (**(code **)(((unsigned char *)0x000012e4) + iVar2))
                            (param_1,uVar5,local_1b4,pcVar7,uVar6,iVar1,pcVar9,ppuVar12,iVarS2,iVar2,pcVar9,ppuVar12);
                  (**(code **)(((unsigned char *)0x000012e4) + iVar2))
                            (param_1,uVar5,local_18c,pcVar7,uVar6,iVar1 + 1,pcVar9,ppuVar12,iVarS2,iVar2,pcVar9,ppuVar12);
                  (**(code **)(((unsigned char *)0x000012e4) + iVar2))
                            (param_1,uVar5,local_164,pcVar7,uVar6,iVar1 + 2,pcVar9,ppuVar12,iVarS2,iVar2,pcVar9,ppuVar12);
                  (**(code **)(((unsigned char *)0x000012e4) + iVar2))
                            (param_1,uVar5,local_13c[0],pcVar7,uVar6,iVar1 + 3,pcVar9,ppuVar12,iVarS2,iVar2,pcVar9,ppuVar12);
                  if (param_3 <= uVar13) {
                    puVar8 = (undefined4 *)param_1[0xfb];
                    goto LAB_000953b4;
                  }
                  if (uVar13 == 1) {
                    pcVar7 = local_68 + 0x7514;
                  }
                  else {
                    if (uVar13 == 0) goto LAB_00095234;
                    if (uVar13 == 2) {
                      pcVar7 = local_64 + 0x7504;
                    }
                    else {
                      pcVar7 = (code *)0x0;
                      if (uVar13 == 3) {
                        pcVar7 = local_70 + 0x74f4;
                      }
                    }
                  }
                  piVar4 = piVar4 + 1;
                } while( true );
              }
              local_88 = IrFetchTextureMapBias__dtor;
              local_8c = &PTR_DAT_001f4850;
              local_6c = IrFetchTextureMapBias__dtor;
              local_68 = IrFetchTextureMapBias__dtor;
              local_64 = IrFetchTextureMapBias__dtor;
              local_70 = IrFetchTextureMapBias__dtor;
LAB_000953b4:
              uVar6 = *puVar8;
              iVar1 = param_1[0xfe];
              pcVar7 = local_88 + 0x74c4;
              ppuVar12 = local_8c + 0x1766;
              iVarS3 = *(int *)((int)param_1 + 1376);
              (**(code **)(((unsigned char *)0x000012e4) + iVar2))
                        (param_1,uVar5,iVar1,local_6c + 0x74b4,uVar6,local_1b4,pcVar7,ppuVar12,uVar6,iVarS3,pcVar7,ppuVar12);
              (**(code **)(((unsigned char *)0x000012e4) + iVar2))
                        (param_1,uVar5,iVar1,local_68 + 0x7514,uVar6,local_18c,pcVar7,ppuVar12,uVar6,iVarS3,pcVar7,ppuVar12);
              (**(code **)(((unsigned char *)0x000012e4) + iVar2))
                        (param_1,uVar5,iVar1,local_64 + 0x7504,uVar6,local_164,pcVar7,ppuVar12,uVar6,iVarS3,pcVar7,ppuVar12);
              (**(code **)(((unsigned char *)0x000012e4) + iVar2))
                        (param_1,uVar5,iVar1,local_70 + 0x74f4,uVar6,local_13c[0],pcVar7,ppuVar12,uVar6,iVarS3,pcVar7,ppuVar12);
            }
            FUN_000911a0(param_1,auStack_1b8);
            FUN_000911a0(param_1,auStack_190);
            FUN_000911a0(param_1,local_60);
            FUN_000911a0(param_1,local_98);
            return 0;
          }
        }
      }
    }
  }
  else {
    if (param_1[0xfe] != -1) {
      return 0;
    }
    if ((param_1[0x158] == -1) && (FUN_00091eb0(param_1,param_3,param_4), param_1[0x158] == -1)) {
      return 2;
    }
    if ((param_3 < 4) && (param_4 != 0)) {
      param_3 = param_3 + 1;
    }
    iVar1 = ffvpAllocTempRegister(param_1,0,param_1 + 0xfd);
    if (iVar1 == 0) {
      local_98 = auStack_140;
      iVar1 = ffvpAllocTempRegister(param_1,0,local_98);
      if (iVar1 == 0) {
        local_94 = auStack_118;
        iVar1 = ffvpAllocTempRegister(param_1,0,local_94);
        if (iVar1 == 0) {
          local_90 = auStack_f0;
          iVar1 = ffvpAllocTempRegister(param_1,0,local_90);
          if (iVar1 == 0) {
            local_84 = auStack_c8;
            iVar1 = ffvpAllocTempRegister(param_1,0,local_84);
            if (iVar1 == 0) {
              puVar8 = (undefined4 *)param_1[0xfb];
              uVar5 = *puVar8;
              uVar10 = *(undefined4 *)param_1[0xfc];
              uVar6 = puVar8[2];
              if (param_3 == 0) {
                local_5c = IrFetchTextureMapBias__dtor;
                local_88 = IrFetchTextureMapBias__dtor;
                local_8c = &PTR_DAT_001f4850;
                local_80 = IrFetchTextureMapBias__dtor;
                local_74 = IrFetchTextureMapBias__dtor;
                local_78 = IrFetchTextureMapBias__dtor;
                local_7c = &PTR_DAT_001f4850;
              }
              else {
                local_5c = IrFetchTextureMapBias__dtor;
                local_88 = IrFetchTextureMapBias__dtor;
                local_8c = &PTR_DAT_001f4850;
                local_80 = IrFetchTextureMapBias__dtor;
                local_78 = IrFetchTextureMapBias__dtor;
                local_74 = IrFetchTextureMapBias__dtor;
                uVar13 = 0;
                local_7c = &PTR_DAT_001f4850;
                puVar8 = local_13c;
                piVar4 = param_1;
                do {
                  iVar1 = piVar4[0x2d];
                  uVar11 = *puVar8;
                  uVar13 = uVar13 + 1;
                  piVar4 = piVar4 + 1;
                  puVar8 = puVar8 + 10;
                  iVarS6 = *(int *)((int)*(int *)((int)param_1 + 1004) + 4);
                  iVarS7 = (int)local_80 + 29828;
                  (**(code **)(((unsigned char *)0x000012ec) + iVar2))
                            (param_1,uVar10,uVar11,&DAT_001dbd24,uVar6,iVar1 + 3,&DAT_001dbd14,
                             &DAT_001fa5e8,iVarS6,iVar2,iVarS7,&DAT_001fa5e8);
                  iVarS12 = *(int *)((int)*(int *)((int)param_1 + 1004) + 4);
                  iVarS13 = (int)local_74 + 29860;
                  (**(code **)(((unsigned char *)0x000012f4) + iVar2))
                            (param_1,uVar10,uVar11,&DAT_001dbd24,uVar6,iVar1 + 2,&DAT_001dbd14,
                             &DAT_001fa5e8,iVarS12,iVar2,iVarS13,&DAT_001fa5e8,uVar10,uVar11,&DAT_001dbd14,&DAT_001fa5e8);
                  iVarS14 = (int)local_78 + 29844;
                  (**(code **)(((unsigned char *)0x000012f4) + iVar2))
                            (param_1,uVar10,uVar11,&DAT_001dbd24,uVar6,iVar1 + 1,&DAT_001dbd14,
                             &DAT_001fa5e8,iVarS12,iVar2,iVarS14,&DAT_001fa5e8,uVar10,uVar11,&DAT_001dbd14,&DAT_001fa5e8);
                  iVarS15 = (int)local_7c + 23976;
                  (**(code **)(((unsigned char *)0x000012f4) + iVar2))
                            (param_1,uVar10,uVar11,&DAT_001dbd24,uVar6,iVar1,&DAT_001dbd14,
                             &DAT_001fa5e8,iVarS12,iVar2,iVarS15,&DAT_001fa5e8,uVar10,uVar11,&DAT_001dbd14,&DAT_001fa5e8);
                } while (param_3 != uVar13);
                puVar8 = (undefined4 *)param_1[0xfb];
              }
              iVar1 = param_1[0xfe];
              uVar6 = *puVar8;
              ppuVar12 = local_8c + 0x1766;
              pcVar7 = local_5c + 0x74d4;
              pcVar9 = local_88 + 0x74c4;
              iVarS8 = *(int *)((int)param_1 + 1376);
              iVarS9 = (int)local_80 + 29828;
              (**(code **)(((unsigned char *)0x000012ec) + iVar2))
                        (param_1,uVar6,iVar1,pcVar7,uVar5,local_c4,pcVar9,ppuVar12,uVar6,iVarS8,iVarS9,ppuVar12);
              iVarS16 = *(int *)((int)param_1 + 1376);
              iVarS17 = (int)local_74 + 29860;
              (**(code **)(((unsigned char *)0x000012f4) + iVar2))
                        (param_1,uVar6,iVar1,pcVar7,uVar5,local_ec,pcVar9,ppuVar12,uVar6,iVarS16,iVarS17,ppuVar12,uVar6,iVar1,pcVar9,ppuVar12);
              iVarS18 = (int)local_78 + 29844;
              (**(code **)(((unsigned char *)0x000012f4) + iVar2))
                        (param_1,uVar6,iVar1,pcVar7,uVar5,local_114,pcVar9,ppuVar12,uVar6,iVarS16,iVarS18,ppuVar12,uVar6,iVar1,pcVar9,ppuVar12);
              iVarS19 = (int)local_7c + 23976;
              (**(code **)(((unsigned char *)0x000012f4) + iVar2))
                        (param_1,uVar6,iVar1,pcVar7,uVar5,local_13c[0],pcVar9,ppuVar12,uVar6,iVarS16,iVarS19,ppuVar12,uVar6,iVar1,pcVar9,ppuVar12);
              FUN_000911a0(param_1,local_98);
              FUN_000911a0(param_1,local_94);
              FUN_000911a0(param_1,local_90);
              FUN_000911a0(param_1,local_84);
              return 0;
            }
          }
        }
      }
    }
  }
  return 7;
}

/* FUN_000955a0 @ 0x955a0 (20 bytes) */
int FUN_000955a0(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 == 0) {
    return 1;
  }
  uVar1 = 0;
  iVar3 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x538) == -1) {
    iVar4 = *(int *)(param_1 + 0x510);
    if (iVar4 == -1) {
      FUN_00091880(param_1);
      iVar4 = *(int *)(param_1 + 0x510);
      if (iVar4 == -1) {
        return 2;
      }
    }
    iVar2 = ffvpAllocTempRegister(param_1,2,param_1 + 0x534);
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

/* FUN_000955c0 @ 0x955c0 (20 bytes) */
int FUN_000955c0(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 == 0) {
    return 1;
  }
  iVar3 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x420) != -1) {
    return 0;
  }
  iVar4 = *(int *)(param_1 + 0x538);
  if (iVar4 == -1) {
    FUN_00092150(param_1);
    iVar4 = *(int *)(param_1 + 0x538);
    if (iVar4 != -1) goto LAB_0009226c;
LAB_00092320:
    uVar1 = 2;
  }
  else {
LAB_0009226c:
    if (*(int *)(param_1 + 0x3f8) == -1) {
      if ((*(uint *)(((unsigned char *)0x000013c0) + iVar3) & 4) == 0) {
        FUN_000916d0(param_1);
      }
      else {
        FUN_000914e0(param_1);
      }
      if (*(int *)(param_1 + 0x3f8) == -1) goto LAB_00092320;
    }
    iVar2 = ffvpAllocTempRegister(param_1,1,param_1 + 0x41c);
    uVar1 = 7;
    if (iVar2 == 0) {
      (**(code **)(((unsigned char *)0x000012ec) + iVar3))
                (param_1,**(undefined4 **)(param_1 + 0x3f0),*(undefined4 *)(param_1 + 0x420),
                 &DAT_001dbd84,**(undefined4 **)(param_1 + 0x3ec),iVar4,param_1 + 0x54c,&DAT_001fa5e8,
                 **(undefined4 **)(param_1 + 0x3ec),*(int *)((int)param_1 + 1016),&DAT_001dbd74,&DAT_001fa5e8);
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* FUN_000955e0 @ 0x955e0 (40 bytes) */
int FUN_000955e0(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 uVar1;
  
  uVar1 = 1;
  if ((param_1 != 0) && (uVar1 = 2, *(int *)(param_1 + 0x5c) != -1)) {
    uVar1 = FUN_00091eb0(param_1,param_2,param_3);
    return uVar1;
  }
  return uVar1;
}

/* FUN_00095610 @ 0x95610 (1840 bytes) */
int FUN_00095610(param_1, param_2, param_3)
  int param_1;
  int param_2;
  uint param_3;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined1 auStack_a8 [4];
  undefined4 local_a4;
  undefined1 auStack_80 [4];
  undefined4 local_7c;
  int iVarS1;
  int iVarS2;
  int iVarS3;
  int iVarS4;
  int iVarS5;
  int iVarS6;
  int iVarS7;
  int iVarS8;
  int iVarS9;
  int iVarS10;
  int iVarS11;
  int iVarS12;
  int iVarS13;
  int iVarS14;
  int iVarS15;
  int iVarS16;
  int iVarS17;
  int iVarS18;
  int iVarS19;
  int iVarS20;
  int iVarS21;
  int iVarS22;
  int iVarS23;
  int iVarS24;
  
  if (param_1 == 0) {
    return 1;
  }
  if ((*(int *)(param_1 + 0x68) == -1) || (*(int *)(param_1 + 0xd4) == -1)) {
LAB_00095d30:
    uVar5 = 2;
  }
  else {
    bVar1 = param_2 == 0;
    if (!bVar1) {
      if (7 < param_3) {
        return 3;
      }
      if (*(int *)(param_3 * 4 + param_1 + 0x84) == -1) goto LAB_00095d30;
    }
    iVar7 = *(int *)(param_1 + 0x3d4);
    if ((*(uint *)(((unsigned char *)0x000013c0) + iVar7) & 4) == 0) {
      if ((*(int *)(param_1 + 0x3f8) == -1) &&
         (FUN_000916d0(param_1), *(int *)(param_1 + 0x3f8) == -1)) goto LAB_00095d30;
      if (bVar1) {
        uVar6 = *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 8);
        uVar5 = *(undefined4 *)(param_1 + 0x68);
      }
      else {
        iVar2 = ffvpAllocTempRegister(param_1,0,auStack_a8);
        if (iVar2 != 0) {
          return 7;
        }
        uVar6 = **(undefined4 **)(param_1 + 0x3f0);
        uVar5 = local_a4;
      }
      iVar2 = *(int *)(param_1 + 0xd4);
      uVar4 = **(undefined4 **)(param_1 + 0x3ec);
      uVar8 = (*(undefined4 **)(param_1 + 0x3ec))[2];
      iVarS1 = *(int *)((int)*(int *)((int)param_1 + 1004) + 0);
      iVarS2 = *(int *)((int)param_1 + 1016);
      (**(code **)(((unsigned char *)0x000012e4) + iVar7))
                (param_1,uVar6,uVar5,&DAT_001dbd04,uVar8,iVar2,&DAT_001dbd14,&DAT_001fa5e8,iVarS1,iVarS2,&DAT_001dbd14,&DAT_001fa5e8);
      (**(code **)(((unsigned char *)0x000012e4) + iVar7))
                (param_1,uVar6,uVar5,&DAT_001dbd64,uVar8,iVar2 + 1,&DAT_001dbd14,&DAT_001fa5e8,iVarS1,iVarS2,&DAT_001dbd14,&DAT_001fa5e8);
      (**(code **)(((unsigned char *)0x000012e4) + iVar7))
                (param_1,uVar6,uVar5,&DAT_001dbd54,uVar8,iVar2 + 2,&DAT_001dbd14,&DAT_001fa5e8,iVarS1,iVarS2,&DAT_001dbd14,&DAT_001fa5e8);
      if ((*(char *)(param_1 + 0x744) == '\0') || (*(int *)(param_1 + 0x6a0) != -1)) {
        iVarS3 = *(int *)((int)*(int *)((int)param_1 + 1004) + 0);
        iVarS4 = *(int *)((int)param_1 + 1016);
        (**(code **)(((unsigned char *)0x000012e4) + iVar7))
                  (param_1,uVar6,uVar5,&DAT_001dbd44,uVar8,iVar2 + 3,&DAT_001dbd14,&DAT_001fa5e8,iVarS3,iVarS4,&DAT_001dbd14,&DAT_001fa5e8);
      }
      else {
        uVar9 = **(undefined4 **)(param_1 + 0x3f0);
        iVar3 = ffvpAllocTempRegister(param_1,0,auStack_80);
        if (iVar3 != 0) {
          return 7;
        }
        iVarS5 = *(int *)((int)*(int *)((int)param_1 + 1004) + 0);
        (**(code **)(((unsigned char *)0x000012e4) + iVar7))
                  (param_1,uVar9,local_7c,&DAT_001dbd44,uVar8,iVar2 + 3,&DAT_001dbd14,&DAT_001fa5e8,iVarS5,iVarS2,&DAT_001dbd14,&DAT_001fa5e8)
        ;
        (**(code **)(((unsigned char *)0x000012e8) + iVar7))
                  (param_1,uVar6,uVar5,&DAT_001dbd44,uVar4,local_7c,&DAT_001dbcd4,&DAT_001fa5e8);
        FUN_00091980(param_1,uVar4,local_7c);
        FUN_000911a0(param_1,auStack_80);
        if (*(int *)(param_1 + 0x6a0) == -1) goto LAB_00095d30;
      }
      if (!bVar1) {
        uVar5 = **(undefined4 **)(param_1 + 0x3ec);
        (**(code **)(((unsigned char *)0x000012e8) + iVar7))
                  (param_1,*(undefined4 *)(*(int *)(param_1 + 0x3f0) + 8),
                   *(undefined4 *)(param_1 + 0x68),&DAT_001dbd24,uVar5,local_a4,&DAT_001dbd14,
                   &DAT_001fa5e8);
        (**(code **)(((unsigned char *)0x000012e8) + iVar7))
                  (param_1,*(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x14),
                   *(undefined4 *)(param_3 * 4 + param_1 + 0x84),&DAT_001dbd24,uVar5,local_a4,
                   &DAT_001dbd14,&DAT_001fa5e8);
        goto LAB_00095d10;
      }
    }
    else {
      uVar5 = **(undefined4 **)(param_1 + 0x3ec);
      if ((*(int *)(param_1 + 0x3f8) == -1) &&
         (FUN_000914e0(param_1), *(int *)(param_1 + 0x3f8) == -1)) goto LAB_00095d30;
      iVar2 = ffvpAllocTempRegister(param_1,0,auStack_a8);
      uVar6 = local_a4;
      if (iVar2 != 0) {
        return 7;
      }
      if (bVar1) {
        uVar4 = *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 8);
        uVar8 = *(undefined4 *)(param_1 + 0x68);
      }
      else {
        uVar4 = **(undefined4 **)(param_1 + 0x3f0);
        uVar8 = local_a4;
      }
      iVar2 = *(int *)(param_1 + 0xd4);
      uVar9 = **(undefined4 **)(param_1 + 0x3ec);
      uVar10 = (*(undefined4 **)(param_1 + 0x3ec))[2];
      iVarS6 = *(int *)((int)param_1 + 1016);
      iVarS7 = &DAT_001dbcd4;
      (**(code **)(((unsigned char *)0x000012ec) + iVar7))
                (param_1,uVar9,local_a4,&DAT_001dbd24,uVar10,iVar2 + 3,&DAT_001dbd14,&DAT_001fa5e8,uVar9,iVarS6,iVarS7,&DAT_001fa5e8);
      iVarS8 = *(int *)((int)param_1 + 1016);
      iVarS9 = &DAT_001dbcf4;
      (**(code **)(((unsigned char *)0x000012f4) + iVar7))
                (param_1,uVar9,uVar6,&DAT_001dbd24,uVar10,iVar2 + 2,&DAT_001dbd14,&DAT_001fa5e8,uVar9,iVarS8,iVarS9,&DAT_001fa5e8,uVar9,uVar6,&DAT_001dbd14,&DAT_001fa5e8);
      iVarS10 = *(int *)((int)*(int *)((int)param_1 + 980) + 4852);
      iVarS18 = *(int *)((int)param_1 + 1016);
      iVarS19 = &DAT_001dbce4;
      (**(code **)(((unsigned char *)0x000012f4) + iVar7))
                (param_1,uVar9,uVar6,&DAT_001dbd24,uVar10,iVar2 + 1,&DAT_001dbd14,&DAT_001fa5e8,uVar9,iVarS18,iVarS19,&DAT_001fa5e8,uVar9,uVar6,&DAT_001dbd14,&DAT_001fa5e8);
      if ((*(char *)(param_1 + 0x744) == '\0') || (*(int *)(param_1 + 0x6a0) != -1)) {
        iVarS11 = *(int *)((int)*(int *)((int)param_1 + 1004) + 0);
        iVarS12 = *(int *)((int)param_1 + 1016);
        iVarS13 = &DAT_001fa5f8;
        iVarS14 = *(int *)((int)*(int *)((int)param_1 + 1004) + 0);
        iVarS15 = *(int *)((int)*(int *)((int)param_1 + 980) + 4852);
        iVarS20 = *(int *)((int)*(int *)((int)param_1 + 1004) + 0);
        iVarS21 = *(int *)((int)param_1 + 1016);
        iVarS22 = &DAT_001fa5f8;
        iVarS23 = *(int *)((int)*(int *)((int)param_1 + 1004) + 0);
        iVarS24 = local_a4;
        (**(code **)(((unsigned char *)0x000012f4) + iVar7))
                  (param_1,uVar4,uVar8,&DAT_001dbd24,uVar10,iVar2,&DAT_001dbd14,&DAT_001fa5e8,iVarS20,iVarS21,iVarS22,&DAT_001fa5e8,iVarS23,iVarS24,&DAT_001dbd14,&DAT_001fa5e8);
      }
      else {
        iVarS16 = *(int *)((int)param_1 + 1016);
        iVarS17 = &DAT_001fa5f8;
        (**(code **)(((unsigned char *)0x000012f4) + iVar7))
                  (param_1,**(undefined4 **)(param_1 + 0x3ec),local_a4,&DAT_001dbd24,uVar10,iVar2,
                   &DAT_001dbd14,&DAT_001fa5e8,**(undefined4 **)(param_1 + 0x3ec),iVarS16,iVarS17,&DAT_001fa5e8,**(undefined4 **)(param_1 + 0x3ec),local_a4,&DAT_001dbd14,&DAT_001fa5e8);
        if (bVar1) {
          (**(code **)(((unsigned char *)0x000012e8) + iVar7))
                    (param_1,*(undefined4 *)(*(int *)(param_1 + 0x3f0) + 8),
                     *(undefined4 *)(param_1 + 0x68),&DAT_001dbd24,uVar5,local_a4,&DAT_001dbd14,
                     &DAT_001fa5e8);
        }
        FUN_00091980(param_1,uVar5,local_a4);
        if (*(int *)(param_1 + 0x6a0) == -1) {
          FUN_000911a0(param_1,auStack_a8);
          return 2;
        }
      }
      if (!bVar1) {
        uVar5 = **(undefined4 **)(param_1 + 0x3ec);
        (**(code **)(((unsigned char *)0x000012e8) + iVar7))
                  (param_1,*(undefined4 *)(*(int *)(param_1 + 0x3f0) + 8),
                   *(undefined4 *)(param_1 + 0x68),&DAT_001dbd24,uVar5,local_a4,&DAT_001dbd14,
                   &DAT_001fa5e8);
        (**(code **)(((unsigned char *)0x000012e8) + iVar7))
                  (param_1,*(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x14),
                   *(undefined4 *)(param_3 * 4 + param_1 + 0x84),&DAT_001dbd24,uVar5,local_a4,
                   &DAT_001dbd14,&DAT_001fa5e8);
      }
LAB_00095d10:
      FUN_000911a0(param_1,auStack_a8);
    }
    uVar5 = 0;
  }
  return uVar5;
}

/* FUN_00095d70 @ 0x95d70 (72 bytes) */
int FUN_00095d70(param_1)
  int *param_1;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  uVar1 = 1;
  if (param_1 != (int *)0x0) {
    if ((param_1[0x2d] != -1) && (*param_1 != -1)) {
      if ((*(uint *)(((unsigned char *)0x000013c0) + param_1[0xf5]) & 4) != 0) {
        uVar1 = 0;
        iVar3 = param_1[0xf5];
        if (param_1[0xfe] == -1) {
          iVar2 = ffvpAllocTempRegister(param_1,0,param_1 + 0xfd);
          uVar1 = 7;
          if (iVar2 == 0) {
            uVar4 = *(undefined4 *)param_1[0xfc];
            uVar1 = *(undefined4 *)(param_1[0xfb] + 8);
            iVar5 = param_1[0xfe];
            iVar2 = param_1[0x2d];
            (**(code **)(((unsigned char *)0x000012ec) + iVar3))
                      (param_1,uVar4,iVar5,&DAT_001dbd24,uVar1,iVar2 + 3,&DAT_001dbd14,&DAT_001fa5e8,
                       ((int *)param_1[0xfb])[1],param_1[0],&DAT_001dbcd4,&DAT_001fa5e8);
            (**(code **)(((unsigned char *)0x000012f4) + iVar3))
                      (param_1,uVar4,iVar5,&DAT_001dbd24,uVar1,iVar2 + 2,&DAT_001dbd14,&DAT_001fa5e8,
                       ((int *)param_1[0xfb])[1],param_1[0],&DAT_001dbcf4,&DAT_001fa5e8,uVar4,iVar5,&DAT_001dbd14,&DAT_001fa5e8);
            (**(code **)(((unsigned char *)0x000012f4) + iVar3))
                      (param_1,uVar4,iVar5,&DAT_001dbd24,uVar1,iVar2 + 1,&DAT_001dbd14,&DAT_001fa5e8,
                       ((int *)param_1[0xfb])[1],param_1[0],&DAT_001dbce4,&DAT_001fa5e8,uVar4,iVar5,&DAT_001dbd14,&DAT_001fa5e8);
            (**(code **)(((unsigned char *)0x000012f4) + iVar3))
                      (param_1,uVar4,iVar5,&DAT_001dbd24,uVar1,iVar2,&DAT_001dbd14,&DAT_001fa5e8,
                       ((int *)param_1[0xfb])[1],param_1[0],&DAT_001fa5f8,&DAT_001fa5e8,uVar4,iVar5,&DAT_001dbd14,&DAT_001fa5e8);
            uVar1 = 0;
          }
        }
        return uVar1;
      }
      uVar1 = 0;
      iVar3 = param_1[0xf5];
      if (param_1[0xfe] == -1) {
        iVar2 = ffvpAllocTempRegister(param_1,0,param_1 + 0xfd);
        uVar1 = 7;
        if (iVar2 == 0) {
          uVar1 = *(undefined4 *)(param_1[0xfb] + 8);
          uVar4 = *(undefined4 *)param_1[0xfc];
          iVar5 = param_1[0xfe];
          iVar2 = param_1[0x2d];
          (**(code **)(((unsigned char *)0x000012e4) + iVar3))
                    (param_1,uVar4,iVar5,&DAT_001dbd04,uVar1,iVar2,&DAT_001dbd14,&DAT_001fa5e8,((int *)param_1[0xfb])[1],param_1[0],&DAT_001dbd14,&DAT_001fa5e8);
          (**(code **)(((unsigned char *)0x000012e4) + iVar3))
                    (param_1,uVar4,iVar5,&DAT_001dbd64,uVar1,iVar2 + 1,&DAT_001dbd14,&DAT_001fa5e8,((int *)param_1[0xfb])[1],param_1[0],&DAT_001dbd14,&DAT_001fa5e8);
          (**(code **)(((unsigned char *)0x000012e4) + iVar3))
                    (param_1,uVar4,iVar5,&DAT_001dbd54,uVar1,iVar2 + 2,&DAT_001dbd14,&DAT_001fa5e8,((int *)param_1[0xfb])[1],param_1[0],&DAT_001dbd14,&DAT_001fa5e8);
          (**(code **)(((unsigned char *)0x000012e4) + iVar3))
                    (param_1,uVar4,iVar5,&DAT_001dbd44,uVar1,iVar2 + 3,&DAT_001dbd14,&DAT_001fa5e8,((int *)param_1[0xfb])[1],param_1[0],&DAT_001dbd14,&DAT_001fa5e8);
          uVar1 = 0;
        }
      }
      return uVar1;
    }
    uVar1 = 2;
  }
  return uVar1;
}

/* FUN_00095dd0 @ 0x95dd0 (1792 bytes) */
int FUN_00095dd0(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  uint param_3;
{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 uVar9;
  undefined1 auStack_a8 [4];
  int local_a4;
  undefined1 auStack_80 [4];
  undefined4 local_7c;
  int iVarS1;
  int iVarS2;
  int iVarS3;
  int iVarS4;
  int iVarS5;
  int iVarS6;
  int iVarS7;
  int iVarS8;
  int iVarS9;
  int iVarS10;
  int iVarS11;
  int iVarS12;
  int iVarS13;
  int iVarS14;
  int iVarS15;
  int iVarS16;
  int iVarS17;
  int iVarS18;
  int iVarS19;
  int iVarS20;
  int iVarS21;
  int iVarS22;
  int iVarS23;
  int iVarS24;
  int iVarS25;
  int iVarS26;
  int iVarS27;
  int iVarS28;
  int iVarS29;
  
  if (param_1 == (int *)0x0) {
    return 1;
  }
  if (((param_1[0x1a] == -1) || (iVar8 = param_1[0x29], iVar8 == -1)) || (*param_1 == -1)) {
    return 2;
  }
  bVar1 = param_2 == 0;
  if (!bVar1) {
    if (7 < param_3) {
      return 3;
    }
    if (param_1[param_3 + 0x21] == -1) {
      return 2;
    }
  }
  iVar5 = param_1[0xf5];
  if ((*(uint *)(((unsigned char *)0x000013c0) + iVar5) & 4) == 0) {
    if (bVar1) {
      uVar4 = *(undefined4 *)(param_1[0xfc] + 8);
      iVar2 = param_1[0x1a];
    }
    else {
      iVar8 = ffvpAllocTempRegister(param_1,0,auStack_a8);
      if (iVar8 != 0) {
        return 7;
      }
      iVar8 = param_1[0x29];
      uVar4 = *(undefined4 *)param_1[0xfc];
      iVar2 = local_a4;
    }
    uVar3 = *(undefined4 *)(param_1[0xfb] + 8);
    /* issue #64 live-repro (crash #9, past the local_98-cluster fix): this indirect dispatch
     * (through the per-instance function-pointer table at 0x12e4+iVar5) reaches arbEmitRecord2Src_op01
     * on real hardware, whose real signature takes 12 parameters - but every call at this
     * shared call shape only supplies 8, matching the project's known dropped-call-args
     * defect class (Tools/userspace/indirect_args.py, detect_dropped_args.py). Since the call
     * is an untyped raw function-pointer invocation, the missing param_9-12 are simply never
     * pushed; arbEmitRecord2Src_op01 reads whatever stale stack memory happens to be there instead.
     * Live-verified on real hardware: it crashed dereferencing param_11 as a null pointer.
     * arbEmitRecord2Src_op01's own body applies the IDENTICAL bit-packing pattern to (param_5,param_6,
     * param_7,param_8) as it does to (param_9,param_10,param_11,param_12) - one group at
     * iVar15+4, the other at iVar15+8 - matching OpenGL's separate front/back stencil-state
     * encoding; when front and back use the same function (the common, non-"Separate" case
     * exercised here), both groups are the same values. Fixed by supplying uVar3/iVar8+N/
     * &DAT_001dbd14/&DAT_001fa5e8 again as param_9-12 at every call site reaching this same
     * dispatch slot in this function.
     * CORRECTION (#81, from the stock's outgoing stack stores at 0x96220-0x96234 etc.): the real
     * words are NOT copies of param_5-8 - param_9 is rec[1] (`*(param_1[0xfb] + 4)`), param_10 is
     * *param_1, and param_11/12 are the PIC constants - so the calls now pass those. */
    iVarS16 = *(int *)((int)*(int *)((int)param_1 + 1004) + 4);
    iVarS17 = *(int *)((int)param_1 + 0);
    (**(code **)(((unsigned char *)0x000012e4) + iVar5))
              (param_1,uVar4,iVar2,&DAT_001dbd04,uVar3,iVar8,&DAT_001dbd14,&DAT_001fa5e8,iVarS16,iVarS17,&DAT_001dbd14,&DAT_001fa5e8);
    (**(code **)(((unsigned char *)0x000012e4) + iVar5))
              (param_1,uVar4,iVar2,&DAT_001dbd64,uVar3,iVar8 + 1,&DAT_001dbd14,&DAT_001fa5e8,iVarS16,iVarS17,&DAT_001dbd14,&DAT_001fa5e8);
    (**(code **)(((unsigned char *)0x000012e4) + iVar5))
              (param_1,uVar4,iVar2,&DAT_001dbd54,uVar3,iVar8 + 2,&DAT_001dbd14,&DAT_001fa5e8,iVarS16,iVarS17,&DAT_001dbd14,&DAT_001fa5e8);
    if ((*(char *)(param_1 + 0x1d1) == '\0') || (param_1[0x1a8] != -1)) {
      iVarS18 = *(int *)((int)*(int *)((int)param_1 + 1004) + 4);
      iVarS19 = *(int *)((int)param_1 + 0);
      (**(code **)(((unsigned char *)0x000012e4) + iVar5))
                (param_1,uVar4,iVar2,&DAT_001dbd44,uVar3,iVar8 + 3,&DAT_001dbd14,&DAT_001fa5e8,iVarS18,iVarS19,&DAT_001dbd14,&DAT_001fa5e8);
    }
    else {
      uVar9 = *(undefined4 *)param_1[0xfc];
      uVar7 = *(undefined4 *)param_1[0xfb];
      iVar6 = ffvpAllocTempRegister(param_1,0,auStack_80);
      if (iVar6 != 0) {
        return 7;
      }
      iVarS20 = *(int *)((int)*(int *)((int)param_1 + 1004) + 4);
      iVarS21 = *(int *)((int)param_1 + 0);
      (**(code **)(((unsigned char *)0x000012e4) + iVar5))
                (param_1,uVar9,local_7c,&DAT_001dbd44,uVar3,iVar8 + 3,&DAT_001dbd14,&DAT_001fa5e8,iVarS20,iVarS21,&DAT_001dbd14,&DAT_001fa5e8);
      (**(code **)(((unsigned char *)0x000012e8) + iVar5))
                (param_1,uVar4,iVar2,&DAT_001dbd44,uVar7,local_7c,&DAT_001dbcd4,&DAT_001fa5e8);
      FUN_00091980(param_1,uVar7,local_7c);
      FUN_000911a0(param_1,auStack_80);
      if (param_1[0x1a8] == -1) {
        return 2;
      }
    }
    if (bVar1) {
      return 0;
    }
    uVar4 = *(undefined4 *)param_1[0xfb];
    (**(code **)(((unsigned char *)0x000012e8) + iVar5))
              (param_1,*(undefined4 *)(param_1[0xfc] + 8),param_1[0x1a],&DAT_001dbd24,uVar4,local_a4
               ,&DAT_001dbd14,&DAT_001fa5e8);
    (**(code **)(((unsigned char *)0x000012e8) + iVar5))
              (param_1,*(undefined4 *)(param_1[0xfc] + 0x14),param_1[param_3 + 0x21],&DAT_001dbd24,
               uVar4,local_a4,&DAT_001dbd14,&DAT_001fa5e8);
  }
  else {
    uVar4 = *(undefined4 *)param_1[0xfb];
    iVar2 = ffvpAllocTempRegister(param_1,0,auStack_a8);
    iVar8 = local_a4;
    if (iVar2 != 0) {
      return 7;
    }
    if (bVar1) {
      uVar3 = *(undefined4 *)(param_1[0xfc] + 8);
      iVar2 = param_1[0x1a];
    }
    else {
      uVar3 = *(undefined4 *)param_1[0xfc];
      iVar2 = local_a4;
    }
    iVar6 = param_1[0x29];
    uVar9 = *(undefined4 *)param_1[0xfb];
    uVar7 = ((undefined4 *)param_1[0xfb])[2];
    iVarS1 = *(int *)((int)*(int *)((int)param_1 + 1004) + 4);
    iVarS2 = *(int *)((int)param_1 + 0);
    iVarS3 = &DAT_001dbcd4;
    (**(code **)(((unsigned char *)0x000012ec) + iVar5))
              (param_1,uVar9,local_a4,&DAT_001dbd24,uVar7,iVar6 + 3,&DAT_001dbd14,&DAT_001fa5e8,iVarS1,iVarS2,iVarS3,&DAT_001fa5e8);
    iVarS4 = *(int *)((int)*(int *)((int)param_1 + 1004) + 4);
    iVarS5 = *(int *)((int)param_1 + 0);
    iVarS6 = &DAT_001dbcf4;
    (**(code **)(((unsigned char *)0x000012f4) + iVar5))
              (param_1,uVar9,iVar8,&DAT_001dbd24,uVar7,iVar6 + 2,&DAT_001dbd14,&DAT_001fa5e8,iVarS4,iVarS5,iVarS6,&DAT_001fa5e8,uVar9,iVar8,&DAT_001dbd14,&DAT_001fa5e8);
    iVarS7 = *(int *)((int)*(int *)((int)param_1 + 980) + 4852);
    iVarS22 = *(int *)((int)*(int *)((int)param_1 + 1004) + 4);
    iVarS23 = *(int *)((int)param_1 + 0);
    iVarS24 = &DAT_001dbce4;
    (**(code **)(((unsigned char *)0x000012f4) + iVar5))
              (param_1,uVar9,iVar8,&DAT_001dbd24,uVar7,iVar6 + 1,&DAT_001dbd14,&DAT_001fa5e8,iVarS22,iVarS23,iVarS24,&DAT_001fa5e8,uVar9,iVar8,&DAT_001dbd14,&DAT_001fa5e8);
    if ((*(char *)(param_1 + 0x1d1) == '\0') || (param_1[0x1a8] != -1)) {
      iVarS8 = *(int *)((int)*(int *)((int)param_1 + 1004) + 4);
      iVarS9 = *(int *)((int)param_1 + 0);
      iVarS10 = &DAT_001fa5f8;
      iVarS11 = *(int *)((int)*(int *)((int)param_1 + 1004) + 0);
      iVarS12 = *(int *)((int)*(int *)((int)param_1 + 980) + 4852);
      iVarS25 = *(int *)((int)*(int *)((int)param_1 + 1004) + 4);
      iVarS26 = *(int *)((int)param_1 + 0);
      iVarS27 = &DAT_001fa5f8;
      iVarS28 = *(int *)((int)*(int *)((int)param_1 + 1004) + 0);
      iVarS29 = local_a4;
      (**(code **)(((unsigned char *)0x000012f4) + iVar5))
                (param_1,uVar3,iVar2,&DAT_001dbd24,uVar7,iVar6,&DAT_001dbd14,&DAT_001fa5e8,iVarS25,iVarS26,iVarS27,&DAT_001fa5e8,iVarS28,iVarS29,&DAT_001dbd14,&DAT_001fa5e8);
    }
    else {
      iVarS13 = *(int *)((int)*(int *)((int)param_1 + 1004) + 4);
      iVarS14 = *(int *)((int)param_1 + 0);
      iVarS15 = &DAT_001fa5f8;
      (**(code **)(((unsigned char *)0x000012f4) + iVar5))
                (param_1,*(undefined4 *)param_1[0xfb],local_a4,&DAT_001dbd24,uVar7,iVar6,
                 &DAT_001dbd14,&DAT_001fa5e8,iVarS13,iVarS14,iVarS15,&DAT_001fa5e8,*(undefined4 *)param_1[0xfb],local_a4,&DAT_001dbd14,&DAT_001fa5e8);
      if (bVar1) {
        (**(code **)(((unsigned char *)0x000012e8) + iVar5))
                  (param_1,*(undefined4 *)(param_1[0xfc] + 8),param_1[0x1a],&DAT_001dbd24,uVar4,
                   local_a4,&DAT_001dbd14,&DAT_001fa5e8);
      }
      FUN_00091980(param_1,uVar4,local_a4);
      if (param_1[0x1a8] == -1) {
        FUN_000911a0(param_1,auStack_a8);
        return 2;
      }
    }
    if (!bVar1) {
      uVar4 = *(undefined4 *)param_1[0xfb];
      (**(code **)(((unsigned char *)0x000012e8) + iVar5))
                (param_1,*(undefined4 *)(param_1[0xfc] + 8),param_1[0x1a],&DAT_001dbd24,uVar4,
                 local_a4,&DAT_001dbd14,&DAT_001fa5e8);
      (**(code **)(((unsigned char *)0x000012e8) + iVar5))
                (param_1,*(undefined4 *)(param_1[0xfc] + 0x14),param_1[param_3 + 0x21],&DAT_001dbd24
                 ,uVar4,local_a4,&DAT_001dbd14,&DAT_001fa5e8);
    }
  }
  FUN_000911a0(param_1,auStack_a8);
  return 0;
}

/* FUN_00096500 @ 0x96500 (52 bytes) */
int FUN_00096500(param_1)
  int param_1;
{
  undefined4 uVar1;
  
  uVar1 = 1;
  if (param_1 != 0) {
    if ((*(int *)(param_1 + 0xc4) != -1) && (*(int *)(param_1 + 4) != -1)) {
      uVar1 = FUN_00091a30(param_1);
      return uVar1;
    }
    uVar1 = 2;
  }
  return uVar1;
}

/* FUN_00096540 @ 0x96540 (172 bytes) */
int FUN_00096540(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  
  if ((*(int *)(param_1 + 0x330) == -1) || (iVar2 = *(int *)(param_1 + 0x70), iVar2 == -1)) {
    return 2;
  }
  if (*(short *)(((unsigned char *)0x00002e06) + *(int *)(*(int *)(*(int *)(param_1 + 0x3d4) + 4) + 0x10)) ==
      -0x7baf) {
    if (*(int *)(param_1 + 0x50) == -1) {
      return 2;
    }
    if (3 < *(uint *)(param_1 + 0x54)) {
      return 3;
    }
  }
  if ((((*(int *)(param_1 + 0x3d8) == 0) && (iVar2 != *(int *)(param_1 + 0x74))) &&
      (iVar2 != *(int *)(param_1 + 0x78))) &&
     ((iVar2 != *(int *)(param_1 + 0x7c) && (iVar2 != *(int *)(param_1 + 0x80))))) {
    return 3;
  }
  *(undefined1 *)(*(int *)(param_1 + 0x3d4) + 0x12e) = 0;
  uVar1 = FUN_000928a0(param_1);
  return uVar1;
}

/* FUN_00096600 @ 0x96600 (1872 bytes) */
int FUN_00096600(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  uint param_2;
  undefined4 param_3;
  uint param_4;
  int param_5;
  uint param_6;
  uint param_7;
{
  bool bVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  char cVar5;
  undefined4 uVar6;
  int iVar7;
  int iVarSa;
  int iVarSb;
  undefined4 *puVar8;
  undefined4 *puVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  uint uVar16;
  undefined4 uVar17;
  undefined *puVar18;
  undefined4 uStack00000020;
  undefined1 auStack_b8 [4];
  undefined4 local_b4;
  undefined1 auStack_90 [4];
  undefined4 local_8c;
  undefined4 local_68;
  undefined4 local_64;
  int local_60;
  int local_5c;
  int iVarS1;
  int iVarS2;
  
  bVar2 = param_5 == 0;
  uStack00000020 = param_3;
  if ((bVar2) && (param_7 == 0)) {
    uVar6 = FUN_00093000(param_1,param_2,param_3,param_4,0,param_6,0);
    return uVar6;
  }
  if (param_1 == 0) {
    return 1;
  }
  if (((7 < param_2) || (7 < param_4)) || (7 < param_6)) {
    return 3;
  }
  iVar3 = param_2 * 4;
  if (((*(int *)(iVar3 + param_1 + 0x84) == -1) || (*(int *)(iVar3 + param_1 + 0x2c) == -1)) ||
     ((bVar1 = *(char *)(param_1 + 0x744) != '\0', bVar1 && (*(int *)(param_1 + 0xa4) == -1)))) {
    return 2;
  }
  iVar11 = *(int *)(param_1 + 0x3d4);
  if ((bVar1) || ((param_7 != 0 && (!bVar2)))) {
    iVar7 = ffvpAllocTempRegister(param_1,0,auStack_b8);
    if (iVar7 != 0) {
      return 7;
    }
    cVar5 = *(char *)(param_1 + 0x744);
    local_5c = 1;
  }
  else {
    local_5c = 0;
    cVar5 = '\0';
  }
  bVar1 = param_7 == 0;
  if (cVar5 == '\0') {
    if (bVar1) {
      puVar8 = *(undefined4 **)(param_1 + 0x3f0);
      uVar12 = 0;
      local_b4 = 0;
    }
    else if (bVar2) {
      puVar8 = *(undefined4 **)(param_1 + 0x3f0);
      local_b4 = *(undefined4 *)(iVar3 + param_1 + 0x84);
      uVar12 = puVar8[5];
    }
    else {
      puVar8 = *(undefined4 **)(param_1 + 0x3f0);
      uVar12 = *puVar8;
    }
    uVar15 = puVar8[5];
    uVar6 = *(undefined4 *)(iVar3 + param_1 + 0x84);
    if (bVar1) {
      local_60 = 0;
      local_68 = 0;
      local_64 = 0;
      goto LAB_00096b24;
    }
    local_60 = 0;
    local_68 = 0;
    local_64 = 0;
    uVar17 = local_b4;
  }
  else {
    if (bVar1) {
      local_64 = local_b4;
      uVar15 = **(undefined4 **)(param_1 + 0x3f0);
      local_60 = 0;
      uVar6 = local_b4;
      local_68 = uVar15;
      goto LAB_00096b24;
    }
    uVar12 = **(undefined4 **)(param_1 + 0x3f0);
    uVar17 = local_b4;
    if (bVar2) {
      local_64 = local_b4;
      uVar15 = 0;
      local_60 = 0;
      uVar6 = 0;
      local_68 = uVar12;
    }
    else {
      if (*(int *)(param_1 + 0x6a0) == -1) {
        if (local_5c == 0) {
          return 2;
        }
        FUN_000911a0(param_1,auStack_b8);
        return 2;
      }
      iVar7 = ffvpAllocTempRegister(param_1,0,auStack_90);
      if (iVar7 != 0) {
        if (local_5c == 0) {
          return 7;
        }
        FUN_000911a0(param_1,auStack_b8);
        return 7;
      }
      local_64 = local_8c;
      uVar15 = **(undefined4 **)(param_1 + 0x3f0);
      local_60 = 1;
      uVar6 = local_8c;
      local_68 = uVar15;
    }
  }
  if (((((param_7 & 7) == 0) || ((param_7 & 0x38) == 0)) || ((param_7 & 0x1c0) == 0)) ||
     ((param_7 & 0xe00) == 0)) {
    (**(code **)(((unsigned char *)0x000012e8) + iVar11))
              (param_1,uVar12,uVar17,&DAT_001dbd24,*(undefined4 *)(*(int *)(param_1 + 0x3ec) + 4),
               *(undefined4 *)(iVar3 + param_1 + 0x2c),&DAT_001dbd14,&DAT_001fa5e8);
  }
  uVar16 = 0;
  puVar18 = &DAT_001dbdfc;
  puVar8 = (undefined4 *)(param_2 * 0x10 + param_1 + 0x348);
  do {
    uVar4 = param_7 >> (uVar16 & 0x3f) & 7;
    if (uVar4 == 0) goto switchD_0009696c_default;
    puVar9 = *(undefined4 **)(param_1 + 0x3ec);
    iVar7 = *(int *)(param_1 + 0x3d4);
    uVar13 = *puVar8;
    uVar14 = puVar9[2];
    switch(uVar4) {
    case 1:
      if (*(int *)(param_1 + 0x3f8) == -1) {
        if ((*(uint *)(((unsigned char *)0x000013c0) + iVar7) & 4) == 0) {
          FUN_000916d0(param_1);
        }
        else {
          FUN_000914e0(param_1);
        }
      }
      /* #70 stack words: case 1 (stock 0x969a8) passes (rec[0], *(param_1 + 0x3f8)) as the 9th / 10th arguments below, case 2
       * (0x96988) passes (rec[4], *param_1); the 11th / 12th are the PIC constants on both paths */
      iVarSa = *puVar9;
      iVarSb = *(int *)(param_1 + 0x3f8);
      goto LAB_000969f0;
    case 2:
      iVarSa = puVar9[1];
      iVarSb = *(int *)param_1;
LAB_000969f0:
      /* issue #79 class: the stock sets r9 / r10 (`addi r9,r11,0x5700`, `addi r10,r10,0x3fd4` from the PIC base 0x96614 =
       * &DAT_001dbd14 / &DAT_001fa5e8) for the `bctrl` at 0x96a20 - the same 7th / 8th arguments every sibling call through
       * this slot passes - and stores them again as stack words, which is why the same-block count stopped at r8 */
      (**(code **)(((unsigned char *)0x000012e4) + iVar7))(param_1,uVar12,uVar17,puVar18,uVar14,uVar13,&DAT_001dbd14,&DAT_001fa5e8,iVarSa,iVarSb,&DAT_001dbd14,&DAT_001fa5e8);
      goto switchD_0009696c_default;
    case 3:
      iVar10 = *(int *)(param_1 + 0x4e8);
      uVar13 = *puVar9;
      if (iVar10 == -1) {
        FUN_00092570(param_1);
        iVar10 = *(int *)(param_1 + 0x4e8);
      }
      break;
    case 4:
      uVar13 = *puVar9;
      if (*(char *)(iVar7 + 0x128) == '\0') {
        if (*(char *)(iVar7 + 300) == '\0') {
          iVar10 = *(int *)(param_1 + 0x448);
          if (iVar10 == -1) {
            FUN_00091a30(param_1);
            iVar10 = *(int *)(param_1 + 0x448);
          }
        }
        else {
          iVar10 = *(int *)(param_1 + 0x470);
          if (iVar10 == -1) {
            FUN_00091d70(param_1);
            iVar10 = *(int *)(param_1 + 0x470);
          }
        }
      }
      else {
        iVar10 = *(int *)(param_1 + 0x498);
        if (iVar10 == -1) {
          FUN_00091b90(param_1);
          iVar10 = *(int *)(param_1 + 0x498);
        }
      }
      break;
    case 5:
      iVar10 = *(int *)(param_1 + 0x4c0);
      uVar13 = *puVar9;
      if (iVar10 == -1) {
        FUN_00092350(param_1);
        iVar10 = *(int *)(param_1 + 0x4c0);
      }
      break;
    default:
      goto switchD_0009696c_default;
    }
    (**(code **)(((unsigned char *)0x000012e8) + iVar7))
              (param_1,uVar12,uVar17,puVar18,uVar13,iVar10,&DAT_001dbd14,&DAT_001fa5e8);
switchD_0009696c_default:
    bVar1 = uVar16 != 9;
    puVar18 = puVar18 + 0x10;
    puVar8 = puVar8 + 1;
    uVar16 = uVar16 + 3;
  } while (bVar1);
LAB_00096b24:
  if (!bVar2) {
    iVar7 = *(int *)(param_6 * 4 + param_1 + 0xd8);
    uVar17 = *(undefined4 *)(*(int *)(param_1 + 0x3ec) + 8);
    (**(code **)(((unsigned char *)0x000012e4) + iVar11))
              (param_1,uVar15,uVar6,&DAT_001dbd04,uVar17,iVar7,&DAT_001dbd14,&DAT_001fa5e8,(bVar1 ? (*(int **)(param_1 + 0x3ec))[1] : bVar2 ? 0 : **(int **)(param_1 + 0x3ec)),(bVar1 ? *(int *)(iVar3 + param_1 + 0x2c) : bVar2 ? 0 : local_b4),(param_3 != 0 ? ((unsigned char *)&DAT_001dbdc0 + 4) : &DAT_001dbd14),&DAT_001fa5e8);
    (**(code **)(((unsigned char *)0x000012e4) + iVar11))
              (param_1,uVar15,uVar6,&DAT_001dbd64,uVar17,iVar7 + 1,&DAT_001dbd14,&DAT_001fa5e8,(bVar1 ? (*(int **)(param_1 + 0x3ec))[1] : bVar2 ? 0 : **(int **)(param_1 + 0x3ec)),(bVar1 ? *(int *)(iVar3 + param_1 + 0x2c) : bVar2 ? 0 : local_b4),(param_3 != 0 ? ((unsigned char *)&DAT_001dbdc0 + 4) : &DAT_001dbd14),&DAT_001fa5e8);
    (**(code **)(((unsigned char *)0x000012e4) + iVar11))
              (param_1,uVar15,uVar6,&DAT_001dbd54,uVar17,iVar7 + 2,&DAT_001dbd14,&DAT_001fa5e8,(bVar1 ? (*(int **)(param_1 + 0x3ec))[1] : bVar2 ? 0 : **(int **)(param_1 + 0x3ec)),(bVar1 ? *(int *)(iVar3 + param_1 + 0x2c) : bVar2 ? 0 : local_b4),(param_3 != 0 ? ((unsigned char *)&DAT_001dbdc0 + 4) : &DAT_001dbd14),&DAT_001fa5e8);
    (**(code **)(((unsigned char *)0x000012e4) + iVar11))
              (param_1,uVar15,uVar6,&DAT_001dbd44,uVar17,iVar7 + 3,&DAT_001dbd14,&DAT_001fa5e8,(bVar1 ? (*(int **)(param_1 + 0x3ec))[1] : bVar2 ? 0 : **(int **)(param_1 + 0x3ec)),(bVar1 ? *(int *)(iVar3 + param_1 + 0x2c) : bVar2 ? 0 : local_b4),(param_3 != 0 ? ((unsigned char *)&DAT_001dbdc0 + 4) : &DAT_001dbd14),&DAT_001fa5e8);
  }
  if (*(char *)(param_1 + 0x744) != '\0') {
    iVarS1 = *(int *)((int)*(int *)((int)param_1 + 1004) + 0);
    iVarS2 = (int)param_1 + 1716;
    (**(code **)(((unsigned char *)0x000012ec) + iVar11))
              (param_1,*(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x14),
               *(undefined4 *)(iVar3 + param_1 + 0x84),&DAT_001dbd24,local_68,local_64,&DAT_001dbd14
               ,&DAT_001fa5e8,iVarS1,*(int *)(param_1 + 0x6a0),iVarS2,&DAT_001fa5e8);
  }
  if (local_5c != 0) {
    FUN_000911a0(param_1,auStack_b8);
  }
  if (local_60 != 0) {
    FUN_000911a0(param_1,auStack_90);
  }
  return 0;
}

/* FUN_00096d80 @ 0x96d80 (1700 bytes) */
int FUN_00096d80(param_1)
  int param_1;
{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  undefined4 *puVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  undefined4 uVar17;
  uint loopIndex;
  int iVar19;
  int iVar20;
  undefined4 local_98;
  undefined1 auStack_94 [4];
  int local_90;
  undefined1 auStack_8c [4];
  int local_88 [4];
  undefined4 local_78 [4];
  int local_68;
  int *local_64;
  int local_60;
  int *local_5c;
  int local_58;
  int iVarS1;
  int iVarS2;
  int iVarS3;
  int iVarS4;
  int iVarS5;
  int iVarS6;
  int iVarS7;
  int iVarS8;
  int iVarS9;
  int iVarS10;
  int iVarS11;
  int iVarS12;
  int iVarS13;
  int iVarS14;
  int iVarS15;
  int iVarS16;
  int iVarS17;
  int iVarS18;
  int iVarS19;
  int iVarS20;
  int iVarS21;
  
  iVar5 = 1;
  if (param_1 != 0) {
    iVar16 = *(int *)(param_1 + 0x3d4);
    loopIndex = 0;
    iVar15 = *(int *)(*(int *)(iVar16 + 4) + 0x10);
    iVar5 = iVar16;
    iVar20 = param_1;
    do {
      iVar6 = FUN_000912f0(param_1,*(undefined4 *)(iVar5 + 0x270),0,auStack_8c,auStack_94);
      if (iVar6 != 0) {
        return iVar6;
      }
      iVar6 = FUN_000912f0(param_1,*(undefined4 *)(iVar5 + 0x278),1,auStack_8c,auStack_94);
      if (iVar6 != 0) {
        return iVar6;
      }
      if ((*(int *)(iVar16 + 0x13c) == 1) && (*(int *)(iVar20 + 0x2f8) == -1)) goto LAB_00097408;
      loopIndex = loopIndex + 1;
      iVar5 = iVar5 + 4;
      iVar20 = iVar20 + 0x24;
    } while (loopIndex <= (byte)((unsigned char *)0x00002d48)[iVar15 + 4]);
    if (*(int *)(param_1 + 0x328) == -1) {
LAB_00097408:
      iVar5 = 2;
    }
    else {
      iVar16 = *(int *)(param_1 + 0x3d4);
      loopIndex = 0;
      iVar6 = 0;
      iVar15 = (*(undefined4 **)(param_1 + 0x3ec))[2];
      uVar13 = **(undefined4 **)(param_1 + 0x3ec);
      local_5c = local_88 + 2;
      uVar12 = **(undefined4 **)(param_1 + 0x3f0);
      iVar20 = *(int *)(*(int *)(iVar16 + 4) + 0x10);
      iVar5 = iVar16;
      do {
        puVar11 = (undefined4 *)(iVar5 + 0x278);
        loopIndex = loopIndex + 1;
        iVar5 = iVar5 + 4;
        FUN_000912f0(param_1,*puVar11,1,(int)local_88 + iVar6,iVar6 + (int)local_5c);
        iVar6 = iVar6 + 4;
      } while (loopIndex <= (byte)((unsigned char *)0x00002d48)[iVar20 + 4]);
      if ((((byte)((unsigned char *)0x00002d48)[iVar20 + 4] == 0) || (local_88[0] != local_88[1])) ||
         (bVar1 = true, local_88[2] != local_88[3])) {
        bVar1 = false;
      }
      bVar1 = !bVar1;
      local_64 = &local_90;
      local_60 = param_1 + 0x5ac;
      local_58 = 0x1d6d90;
      local_68 = 0x1d6d90;
      loopIndex = 0;
      iVar14 = 0;
      iVar10 = 0;
      iVar5 = param_1;
      iVar6 = iVar16;
      iVar19 = param_1;
      do {
        iVar7 = ffvpAllocTempRegister(param_1,0,local_60 + iVar10);
        if (iVar7 != 0) {
          return 7;
        }
        iVar7 = *(int *)((int)local_88 + iVar14);
        uVar17 = *(undefined4 *)(iVar19 + 0x5b0);
        *(undefined4 *)((int)local_78 + iVar14) = uVar17;
        if (iVar15 == iVar7) {
          iVar7 = ffvpAllocTempRegister(param_1,1,param_1 + 0x64c + iVar10);
          if (iVar7 != 0) {
            return 7;
          }
          *(undefined4 *)(iVar19 + 0x64c) = uVar13;
          puVar4 = PTR_DAT_001e9778;
          puVar3 = PTR_DAT_001e9774;
          puVar2 = PTR_DAT_001e9770;
          (**(code **)(((unsigned char *)0x000012e8) + iVar16))
                    (param_1,uVar12,*(undefined4 *)(iVar19 + 0x650),PTR_DAT_001e9770,iVar15,
                     *(undefined4 *)(iVar14 + (int)local_5c),PTR_DAT_001e9774,PTR_DAT_001e9778);
          FUN_000912f0(param_1,*(undefined4 *)(iVar6 + 0x270),0,&local_90,&local_98);
          if (iVar15 == local_90) {
            local_98 = *(undefined4 *)(iVar5 + 0x2f8);
            (**(code **)(((unsigned char *)0x000012e8) + iVar16))
                      (param_1,uVar12,uVar17,puVar2,iVar15,local_98,puVar3,puVar4);
          }
          else {
            iVarS16 = *(int *)((int)*(int *)((int)param_1 + 1004) + 8);
            iVarS17 = *(int *)((int)param_1 + 808);
            iVarS18 = &DAT_001dbd14;
            iVarS19 = &DAT_001fa5e8;
            iVarS20 = local_90;
            iVarS21 = local_98;
            (**(code **)(((unsigned char *)0x000012f4) + iVar16))
                      (param_1,uVar12,uVar17,PTR_DAT_001e9770,uVar13,*(undefined4 *)(iVar19 + 0x650)
                       ,PTR_DAT_001e9774,PTR_DAT_001e9778,iVarS16,iVarS17,iVarS18,iVarS19,iVarS20,iVarS21,iVarS18,iVarS19);
          }
          if (*(int *)(param_1 + 0x32c) != -1) {
            uVar8 = *(undefined4 *)(iVar19 + 0x650);
            uVar9 = uVar13;
            iVar7 = local_58;
LAB_00097360:
            (**(code **)(((unsigned char *)0x000012f4) + iVar16))
                      (param_1,uVar12,uVar17,((unsigned char *)0x00004ff4) + iVar7,uVar9,uVar8,PTR_DAT_001e9774,
                       PTR_DAT_001e9778,(*(int *)((int)*(int *)((int)param_1 + 1004) + 8)),*(int *)(param_1 + 0x32c),&DAT_001dbd14,&DAT_001fa5e8,uVar13,uVar17,&DAT_001dbd14,&DAT_001fa5e8);
          }
        }
        else {
          *(int *)(iVar19 + 0x64c) = iVar7;
          uVar9 = *(undefined4 *)(iVar14 + (int)local_5c);
          puVar11 = (undefined4 *)(iVar14 + (int)local_5c);
          *(undefined4 *)(iVar19 + 0x650) = uVar9;
          if (((bVar1) || (loopIndex == 0)) &&
             ((**(code **)(((unsigned char *)0x000012ec) + iVar16))
                        (param_1,uVar12,uVar17,PTR_DAT_001e9770,iVar7,uVar9,PTR_DAT_001e9774,
                         PTR_DAT_001e9778,(*(int *)((int)*(int *)((int)param_1 + 1004) + 8)),(*(int *)((int)param_1 + 808)),PTR_DAT_001e9774,PTR_DAT_001e9778), bVar1)) {
            FUN_000912f0(param_1,*(undefined4 *)(iVar6 + 0x270),0,&local_90,&local_98);
            uVar9 = uVar17;
LAB_000972c8:
            (**(code **)(((unsigned char *)0x000012f0) + iVar16))
                      (param_1,uVar12,uVar9,PTR_DAT_001e9770,uVar13,uVar9,PTR_DAT_001e9774,
                       PTR_DAT_001e9778,local_90,local_98,&DAT_001dbd14,&DAT_001fa5e8);
          }
          else if (loopIndex == 1) {
            FUN_000912f0(param_1,*(undefined4 *)(iVar16 + 0x274),0,local_64,&local_98);
            uVar9 = local_78[0];
            iVarS12 = local_90;
            iVarS13 = local_98;
            iVarS14 = &DAT_001dbd14;
            iVarS15 = &DAT_001fa5e8;
            (**(code **)(((unsigned char *)0x000012f0) + iVar16))
                      (param_1,uVar12,local_78[1],PTR_DAT_001e9770,uVar13,local_78[0],
                       PTR_DAT_001e9774,PTR_DAT_001e9778,iVarS12,iVarS13,iVarS14,iVarS15);
            FUN_000912f0(param_1,*(undefined4 *)(iVar16 + 0x270),0,local_64,&local_98);
            goto LAB_000972c8;
          }
          if ((*(int *)(param_1 + 0x32c) != -1) && ((bVar1 || (loopIndex == 0)))) {
            uVar9 = *(undefined4 *)((int)local_88 + iVar14);
            uVar8 = *puVar11;
            iVar7 = local_68;
            goto LAB_00097360;
          }
        }
        if (*(char *)(iVar16 + 0x12d) != '\0') {
          if (*(short *)(((unsigned char *)0x00002d48) + iVar20) == -0x7e06) {
            iVar7 = ffvpAllocTempRegister(param_1,1,param_1 + 0x5fc + iVar10);
            if (iVar7 != 0) {
              return 7;
            }
          }
          else {
            _memcpy(iVar19 + 0x5fc,iVar19 + 0x5ac,0x28);
          }
        }
        loopIndex = loopIndex + 1;
        iVar10 = iVar10 + 0x28;
        iVar19 = iVar19 + 0x28;
        iVar14 = iVar14 + 4;
        iVar5 = iVar5 + 0x24;
        iVar6 = iVar6 + 4;
      } while (loopIndex <= (byte)((unsigned char *)0x00002d48)[iVar20 + 4]);
      iVar5 = 0;
    }
  }
  return iVar5;
}

/* FUN_00097440 @ 0x97440 (4212 bytes) */
int FUN_00097440(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
  int param_7;
{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined *puVar10;
  int iVar11;
  undefined4 *puVar12;
  int iVar13;
  int iVar14;
  undefined4 a1;
  int iVar15;
  int iVar16;
  int iVar17;
  undefined *puVar18;
  uint uVar19;
  undefined4 uVar20;
  int iVar21;
  undefined1 *puVar22;
  int iStack00000020;
  int iStack00000024;
  int iStack0000002c;
  int iStack00000030;
  int iVarS9;
  int local_1b8;
  int local_1b4;
  undefined1 auStack_1b0 [4];
  undefined1 auStack_1ac [4];
  undefined4 local_1a8;
  undefined4 local_1a4;
  undefined4 local_1a0;
  undefined4 local_19c;
  undefined1 auStack_198 [16];
  undefined1 auStack_188 [4];
  undefined4 local_184;
  undefined1 auStack_180 [16];
  undefined1 auStack_170 [16];
  undefined1 auStack_160 [4];
  undefined4 local_15c;
  undefined1 auStack_158 [16];
  undefined1 auStack_148 [16];
  undefined1 auStack_138 [4];
  undefined4 local_134;
  undefined1 auStack_110 [4];
  undefined4 local_10c;
  undefined1 auStack_108 [16];
  undefined1 auStack_f8 [16];
  undefined1 auStack_e8 [4];
  undefined4 local_e4;
  undefined1 auStack_e0 [16];
  undefined1 auStack_d0 [56];
  uint local_98;
  uint local_94;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  undefined1 *local_78;
  undefined1 *local_74;
  undefined4 *local_70;
  int *local_6c;
  undefined1 *local_68;
  undefined1 *local_64;
  undefined1 *local_60;
  undefined1 *local_5c;
  int iVarS10;
  int iVarS11;
  int iVarS12;
  int iVarS13;
  int iVarS14;
  int iVarS15;
  int iVarS16;
  int iVarS17;
  int iVarS18;
  int iVarS19;
  int iVarS20;
  int iVarS21;
  int iVarS22;
  int iVarS23;
  int iVarS24;
  int iVarS25;
  int iVarS26;
  int iVarS27;
  int iVarS28;
  int iVarS29;
  int iVarS30;
  int iVarS31;
  int iVarS32;
  int iVarS33;
  int iVarS34;
  int iVarS35;
  int iVarS36;
  int iVarS37;
  int iVarS38;
  int iVarS39;
  int iVarS40;
  int iVarS41;
  int iVarS42;
  int iVarS43;
  int iVarS44;
  int iVarS45;
  int iVarS46;
  int iVarS47;
  int iVarS48;
  int iVarS49;
  int iVarS50;
  int iVarS51;
  int iVarS52;
  int iVarS53;
  int iVarS54;
  int iVarS55;
  int iVarS56;
  int iVarS57;
  int iVarS58;
  int iVarS59;
  int iVarS60;
  int iVarS61;
  int iVarS62;
  int iVarS63;
  int iVarS64;
  int iVarS65;
  int iVarS66;
  int iVarS67;
  int iVarS68;
  int iVarS69;
  int iVarS70;
  int iVarS71;
  
  iVar15 = param_1 + 0xf8 + param_2 * 0x3c;
  iVar11 = *(int *)(param_1 + 0x3d4);
  iVar17 = *(int *)(*(int *)(iVar11 + 4) + 0x10);
  if ((*(int *)(iVar15 + 0x24) == -1) || ((param_5 == 2 && (*(int *)(iVar15 + 4) == -1)))) {
LAB_000984b0:
    iVar11 = 2;
  }
  else {
    if (param_6 == 2) {
      iVar3 = (byte)((unsigned char *)0x00002d48)[iVar17 + 4] + 1;
      iVar8 = iVar15;
      do {
        if ((*(int *)(iVar8 + 0xc) == -1) && (*(int *)(iVar15 + 8) == -1)) goto LAB_000984b0;
        iVar8 = iVar8 + 4;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    bVar1 = param_7 == 0;
    iStack00000020 = param_3;
    iStack00000024 = param_4;
    iStack0000002c = param_6;
    iStack00000030 = param_7;
    if (!bVar1) {
      uVar19 = 0;
      do {
        iVar8 = FUN_000913e0(param_1,*(undefined4 *)(iVar11 + 0x290),auStack_1b0,auStack_1ac,
                             auStack_198);
        if (iVar8 != 0) {
          return iVar8;
        }
        uVar19 = uVar19 + 1;
        iVar11 = iVar11 + 4;
      } while (uVar19 <= (byte)((unsigned char *)0x00002d48)[iVar17 + 4]);
      if ((((unsigned char *)0x00002d48)[iVar17 + 5] == '\0') && (*(int *)(iVar15 + 0x28) == -1))
      goto LAB_000984b0;
    }
    if (iStack00000030 == 2) {
      iVar17 = (byte)((unsigned char *)0x00002d48)[iVar17 + 4] + 1;
      iVar11 = iVar15;
      do {
        if ((*(int *)(iVar11 + 0x18) == -1) && (*(int *)(iVar15 + 0x14) == -1)) goto LAB_000984b0;
        iVar11 = iVar11 + 4;
        iVar17 = iVar17 + -1;
      } while (iVar17 != 0);
    }
    iVar17 = *(int *)(param_1 + 0x3d4);
    iVar11 = *(int *)(*(int *)(iVar17 + 4) + 0x10);
    /* #70 stack words (stackargs_overrides.json): the stock's r16, the 9th argument of the ctx+0x12e4 calls below, is rec[0]
     * on three arms and rec[4] (`lwz r16,0x4(r2)` at 0x97638) on the arm that takes iVar8 = *(param_1 + 4); Ghidra dropped
     * the dead loads */
    iVarS9 = **(int **)(param_1 + 0x3ec);
    if (*(char *)(iVar17 + 0x128) == '\0') {
      if (*(char *)(iVar17 + 300) == '\0') {
        if (*(char *)(iVar17 + 0x12a) == '\0') {
          iVar8 = *(int *)(param_1 + 4);
          iVarS9 = (*(int **)(param_1 + 0x3ec))[1];
        }
        else {
          if (*(int *)(param_1 + 0x448) != -1) goto LAB_00097650;
          FUN_00091a30(param_1);
          iVar8 = *(int *)(param_1 + 0x448);
        }
      }
      else {
        if (*(int *)(param_1 + 0x470) != -1) goto LAB_00097650;
        FUN_00091d70(param_1);
        iVar8 = *(int *)(param_1 + 0x470);
      }
LAB_0009763c:
      if (iVar8 == -1) goto LAB_000984b0;
    }
    else if (*(int *)(param_1 + 0x498) == -1) {
      FUN_00091b90(param_1);
      iVar8 = *(int *)(param_1 + 0x498);
      goto LAB_0009763c;
    }
LAB_00097650:
    local_64 = auStack_160;
    iVar8 = ffvpAllocTempRegister(param_1,2,local_64);
    if (iVar8 == 0) {
      a1 = **(undefined4 **)(param_1 + 0x3f0);
      iVar8 = (*(int **)(param_1 + 0x3ec))[2];
      iVar3 = **(int **)(param_1 + 0x3ec);
      (**(code **)(((unsigned char *)0x000012e4) + iVar17))
                (param_1,a1,local_15c,auStack_158,iVar8,*(undefined4 *)(iVar15 + 0x24),&DAT_001dbd74
                 ,&DAT_001fa5e8,iVarS9,(*(char *)(iVar17 + 0x128) == '\0' ? (*(char *)(iVar17 + 300) == '\0' ? (*(char *)(iVar17 + 0x12a) == '\0' ? *(int *)(param_1 + 4) : *(int *)(param_1 + 0x448)) : *(int *)(param_1 + 0x470)) : *(int *)(param_1 + 0x498)),&DAT_001dbd74,&DAT_001fa5e8);
      if ((param_5 != 0) && (param_5 != 3)) {
        uVar19 = 0;
        iVar21 = param_1;
        do {
          uVar5 = *(undefined4 *)(iVar21 + 0x5b0);
          if (param_5 == 1) {
            (**(code **)(((unsigned char *)0x000012f0) + iVar17))
                      (param_1,a1,uVar5,&DAT_001dbd84,iVar3,uVar5,&DAT_001dbd14,&DAT_001fa5e8,*(int *)(iVar21 + 0x64c),*(int *)(iVar21 + 0x650),&DAT_001dbd14,&DAT_001fa5e8);
          }
          else {
            iVarS45 = *(int *)((int)*(int *)((int)param_1 + 1004) + 8);
            iVarS46 = *(int *)((int)iVar15 + 4);
            iVarS47 = *(int *)((int)*(int *)((int)param_1 + 1004) + 0);
            (**(code **)(((unsigned char *)0x000012f4) + iVar17))
                      (param_1,a1,uVar5,&DAT_001dbd84,*(undefined4 *)(iVar21 + 0x64c),
                       *(undefined4 *)(iVar21 + 0x650),&DAT_001dbd14,&DAT_001fa5e8,iVarS45,iVarS46,&DAT_001dbd14,&DAT_001fa5e8,iVarS47,uVar5,&DAT_001dbd14,&DAT_001fa5e8);
          }
          uVar19 = uVar19 + 1;
          iVar21 = iVar21 + 0x28;
        } while (uVar19 <= (byte)((unsigned char *)0x00002d48)[iVar11 + 4]);
      }
      puVar22 = auStack_e8;
      uVar19 = 0;
      local_74 = puVar22;
      do {
        iVar21 = ffvpAllocTempRegister(param_1,1,puVar22);
        if (iVar21 != 0) goto LAB_000984a0;
        uVar19 = uVar19 + 1;
        puVar22 = puVar22 + 0x28;
      } while (uVar19 <= (byte)((unsigned char *)0x00002d48)[iVar11 + 4]);
      if (bVar1) {
        local_70 = &local_e4;
        local_60 = auStack_148;
        do {
          uVar19 = 0;
          puVar12 = local_70;
          do {
            iVar21 = uVar19 * 0x28;
            uVar19 = uVar19 + 1;
            /* stack words, stock 0x97b88-0x97b9c: the 4th (0x44) is the r2 of the first pass (r18 + 0x3194) or of the later ones (0x14_0000 + 0x4940) */
            (**(code **)(((unsigned char *)0x0000132c) + iVar17))
                      (param_1,a1,*puVar12,local_74 + iVar21 + 8,iVar3,local_15c,&DAT_001dbd34,
                       &DAT_001fa5e8,iVar3,local_15c,local_60,(uVar19 == 1 ? &DAT_001fa5e8 : &DAT_001dbd94),iVar3,local_15c,&DAT_001dbdb4,&DAT_001fa5e8);
            if ((byte)((unsigned char *)0x00002d48)[iVar11 + 4] < uVar19) goto LAB_00097bd4;
            puVar12 = puVar12 + 10;
          } while (uVar19 != 0);
        } while( true );
      }
      local_78 = auStack_110;
      iVar21 = ffvpAllocTempRegister(param_1,2,local_78);
      if (iVar21 == 0) {
        local_68 = auStack_188;
        iVar21 = ffvpAllocTempRegister(param_1,2,local_68);
        if (iVar21 == 0) {
          if (((unsigned char *)0x00002d48)[iVar11 + 5] == '\0') {
            local_70 = &local_e4;
            local_6c = &local_1b4;
            local_60 = auStack_148;
            (**(code **)(((unsigned char *)0x000012e4) + iVar17))
                      (param_1,a1,local_10c,auStack_108,iVar8,*(undefined4 *)(iVar15 + 0x28),
                       &DAT_001dbd74,&DAT_001fa5e8,iVarS9,(*(char *)(iVar17 + 0x128) == '\0' ? (*(char *)(iVar17 + 300) == '\0' ? (*(char *)(iVar17 + 0x12a) == '\0' ? *(int *)(param_1 + 4) : *(int *)(param_1 + 0x448)) : *(int *)(param_1 + 0x470)) : *(int *)(param_1 + 0x498)),&DAT_001dbd74,&DAT_001fa5e8);
LAB_00097a58:
            puVar9 = (undefined4 *)(iVar17 + 0x290);
            puVar18 = &DAT_001fa5e8;
            uVar19 = 0;
            puVar12 = local_70;
LAB_00097a68:
            FUN_000913e0(param_1,*puVar9,&local_1b8,local_6c,&local_1a8);
            iVar21 = uVar19 * 0x28;
            uVar19 = uVar19 + 1;
            iVarS15 = *(int *)((int)*(int *)((int)param_1 + 980) + 4908);
            iVarS16 = &DAT_001dbdb4;
            iVarS60 = local_15c;
            iVarS61 = local_60;
            iVarS62 = local_1b8;
            iVarS63 = local_1b4;
            iVarS64 = &local_1a8;
            iVarS65 = &DAT_001fa5e8;
            (**(code **)(((unsigned char *)0x0000132c) + iVar17))
                      (param_1,a1,*puVar12,local_74 + iVar21 + 8,iVar3,local_10c,auStack_f8,puVar18,iVar3,iVarS60,iVarS61,puVar18,iVarS62,iVarS63,iVarS64,iVarS65)
            ;
            if (uVar19 <= (byte)((unsigned char *)0x00002d48)[iVar11 + 4]) goto LAB_00097a40;
            FUN_000911a0(param_1,local_78);
            FUN_000911a0(param_1,local_68);
LAB_00097bd4:
            local_90 = 0x1d7454;
            local_8c = 0x1d7454;
            local_80 = 0x1d7454;
            bVar2 = iStack00000020 == 0;
            local_88 = 0x1d7454;
            local_94 = 0x81fa;
            local_98 = 0;
            local_84 = 0x1d7454;
            local_7c = 0x1d7454;
            puVar12 = local_70;
            iVar21 = iVar17;
            iVar13 = param_1;
            iVar14 = iVar15;
            iVar16 = param_1;
            while (bVar1) {
              if (((!bVar2) && (*(char *)(iVar17 + 0x12d) != '\0')) &&
                 (*(ushort *)(((unsigned char *)0x00002d48) + iVar11) == local_94)) {
                iVarS23 = &DAT_001dbd34;
                (**(code **)(((unsigned char *)0x000012ec) + iVar17))
                          (param_1,a1,*(undefined4 *)(iVar16 + 0x600),((unsigned char *)0x00004930) + local_90,iVar3
                           ,*(undefined4 *)(iVar16 + 0x600),((unsigned char *)0x000048c0) + local_8c,&DAT_001fa5e8,iVar3,*(undefined4 *)(iVar16 + 0x600),iVarS23,&DAT_001fa5e8);
              }
LAB_000980d0:
              if (iStack0000002c == 0) {
                if (iStack00000024 != 0) {
                  uVar20 = *(undefined4 *)(iVar13 + 0x74);
                  uVar5 = *(undefined4 *)(iVar16 + 0x5b0);
                  uVar7 = *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0xc);
                  FUN_000912f0(param_1,*(undefined4 *)(iVar21 + 0x280),2,&local_1b8,&local_1b4);
                  local_19c = 3;
                  local_1a0 = 5;
                  local_1a8 = 5;
                  local_1a4 = 5;
                  iVarS24 = local_1b8;
                  iVarS25 = local_1b4;
                  iVarS26 = &local_1a8;
                  (**(code **)(((unsigned char *)0x000012ec) + iVar17))
                            (param_1,uVar7,uVar20,((unsigned char *)0x000048d0) + local_84,iVar3,uVar5,
                             ((unsigned char *)0x00004970) + local_7c,&DAT_001fa5e8,iVarS24,iVarS25,iVarS26,&DAT_001fa5e8);
                }
              }
              else {
                uVar5 = *(undefined4 *)(iVar16 + 0x5b0);
                iVarS33 = uVar5; /* stock r29, the 6th stack word of the 12f4 call below (0x981a4) */
                if (iStack00000024 == 0) {
                  uVar20 = **(undefined4 **)(param_1 + 0x3f0);
                  puVar18 = ((unsigned char *)0x00004930) + local_90;
                }
                else {
                  uVar5 = *(undefined4 *)(iVar13 + 0x74);
                  uVar20 = *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0xc);
                  puVar18 = ((unsigned char *)0x000048d0) + local_84;
                }
                if (*(int *)(iVar14 + 0xc) == -1) {
                  FUN_000912f0(param_1,*(undefined4 *)(iVar21 + 0x280),2,&local_1b8,&local_1b4);
                }
                iVar4 = local_1b8;
                iVar6 = local_1b4;
                if ((iStack0000002c == 1) ||
                   (iVar4 = iVar8, iVar6 = *(int *)(iVar14 + 0xc), *(int *)(iVar14 + 0xc) != -1)) {
                  iVarS52 = *(int *)((int)*(int *)((int)param_1 + 1004) + 0);
                  iVarS53 = *(int *)((int)puVar12 + 0);
                  iVarS54 = ((unsigned char *)&DAT_001dbdc0 + 44);
                  iVarS55 = &DAT_001dbd74;
                  (**(code **)(((unsigned char *)0x000012f4) + iVar17))
                            (param_1,uVar20,uVar5,puVar18,iVar4,iVar6,((unsigned char *)0x000048c0) + local_8c,
                             &DAT_001fa5e8,iVarS52,iVarS53,iVarS54,&DAT_001fa5e8,iVarS52,iVarS33,iVarS55,&DAT_001fa5e8);
                }
                else {
                  local_5c = auStack_138;
                  iVar4 = ffvpAllocTempRegister(param_1,0,local_5c);
                  if (iVar4 != 0) goto LAB_000984a0;
                  if (iVar8 == local_1b8) {
                    iVarS27 = *(int *)((int)*(int *)((int)param_1 + 1004) + 0);
                    iVarS28 = *(int *)((int)puVar12 + 0);
                    iVarS29 = ((unsigned char *)&DAT_001dbdc0 + 44);
                    (**(code **)(((unsigned char *)0x000012ec) + iVar17))
                              (param_1,a1,local_134,puVar18,iVar8,local_1b4,&DAT_001dbd14,
                               &DAT_001fa5e8,iVarS27,iVarS28,iVarS29,&DAT_001fa5e8);
                    puVar10 = ((unsigned char *)0x00004970) + local_7c;
                    uVar7 = *(undefined4 *)(iVar15 + 8);
                    iVar4 = iVar8;
                  }
                  else {
                    iVarS30 = local_1b8;
                    iVarS31 = local_1b4;
                    iVarS32 = &DAT_001dbd14;
                    (**(code **)(((unsigned char *)0x000012ec) + iVar17))
                              (param_1,a1,local_134,puVar18,iVar8,*(undefined4 *)(iVar15 + 8),
                               ((unsigned char *)0x00004970) + local_7c,&DAT_001fa5e8,iVarS30,iVarS31,iVarS32,&DAT_001fa5e8);
                    uVar7 = *puVar12;
                    puVar10 = ((unsigned char *)0x00004998) + local_80;
                    iVar4 = iVar3;
                  }
                  iVarS68 = *(int *)((int)*(int *)((int)param_1 + 1004) + 0);
                  iVarS69 = local_134;
                  (**(code **)(((unsigned char *)0x000012f4) + iVar17))
                            (param_1,uVar20,uVar5,puVar18,iVar4,uVar7,puVar10,&DAT_001fa5e8,iVarS68,iVarS69,&DAT_001dbd14,&DAT_001fa5e8,iVarS68,iVarS33,&DAT_001dbd74,&DAT_001fa5e8);
                  FUN_000911a0(param_1,local_5c);
                }
              }
              puVar22 = local_74;
              puVar12 = puVar12 + 10;
              iVar13 = iVar13 + 4;
              iVar16 = iVar16 + 0x28;
              iVar21 = iVar21 + 4;
              iVar14 = iVar14 + 4;
              local_98 = local_98 + 1;
              if ((byte)((unsigned char *)0x00002d48)[iVar11 + 4] < local_98) {
                uVar19 = 0;
                FUN_000911a0(param_1,local_64);
                do {
                  uVar19 = uVar19 + 1;
                  FUN_000911a0(param_1,puVar22);
                  puVar22 = puVar22 + 0x28;
                } while (uVar19 <= (byte)((unsigned char *)0x00002d48)[iVar11 + 4]);
                return 0;
              }
            }
            uVar5 = *(undefined4 *)(iVar16 + 0x600);
            if (*(int *)(iVar14 + 0x18) == -1) {
              FUN_000912f0(param_1,*(undefined4 *)(iVar21 + 0x288),3,&local_1b8,&local_1b4);
            }
            if (iStack00000030 == 1) {
              iVar4 = local_1b8;
              iVar6 = local_1b4;
              if ((!bVar2) && (*(ushort *)(((unsigned char *)0x00002d48) + iVar11) == local_94))
              goto LAB_00097d1c;
LAB_00097d70:
              (**(code **)(((unsigned char *)0x000012f4) + iVar17))
                        (param_1,a1,uVar5,((unsigned char *)0x00004930) + local_90,iVar4,iVar6,&DAT_001dbd14,
                         &DAT_001fa5e8,(*(int *)((int)*(int *)((int)param_1 + 1004) + 0)),(*(int *)((int)puVar12 + 0)),(&DAT_001dbcf4),&DAT_001fa5e8,(*(int *)((int)*(int *)((int)param_1 + 1004) + 0)),uVar5,(&DAT_001dbd14),&DAT_001fa5e8);
              goto LAB_000980d0;
            }
            iVar6 = *(int *)(iVar14 + 0x18);
            if (iVar6 != -1) {
              iVar4 = iVar8;
              if ((bVar2) || (*(ushort *)(((unsigned char *)0x00002d48) + iVar11) != local_94))
              goto LAB_00097d70;
LAB_00097d1c:
              (**(code **)(((unsigned char *)0x000012ec) + iVar17))
                        (param_1,a1,uVar5,((unsigned char *)0x00004930) + local_90,iVar4,iVar6,
                         ((unsigned char *)0x000048c0) + local_8c,&DAT_001fa5e8,(*(int *)((int)*(int *)((int)param_1 + 1004) + 0)),(*(int *)((int)puVar12 + 0)),(&DAT_001dbcf4),&DAT_001fa5e8);
              goto LAB_000980d0;
            }
            local_5c = auStack_138;
            iVar4 = ffvpAllocTempRegister(param_1,1,local_5c);
            if (iVar4 == 0) {
              if (iVar8 == local_1b8) {
                iVarS36 = *(int *)((int)*(int *)((int)param_1 + 1004) + 0);
                iVarS37 = *(int *)((int)puVar12 + 0);
                iVarS38 = &DAT_001dbcf4;
                iVarS39 = &DAT_001fa5e8;
                (**(code **)(((unsigned char *)0x000012ec) + iVar17))
                          (param_1,a1,local_134,&DAT_001dbd84,iVar8,local_1b4,&DAT_001dbd14,
                           &DAT_001fa5e8,iVarS36,iVarS37,iVarS38,iVarS39);
                if ((!bVar2) && (*(ushort *)(((unsigned char *)0x00002d48) + iVar11) == local_94)) {
                  puVar9 = &DAT_001dbd14;
                  uVar20 = *(undefined4 *)(iVar15 + 0x14);
                  iVar4 = iVar8;
                  goto LAB_00097fd4;
                }
                puVar9 = &DAT_001dbd14;
                uVar20 = *(undefined4 *)(iVar15 + 0x14);
                iVar4 = iVar8;
LAB_00098038:
                (**(code **)(((unsigned char *)0x000012f4) + iVar17))
                          (param_1,a1,uVar5,&DAT_001dbd84,iVar4,uVar20,puVar9,&DAT_001fa5e8,(*(int *)((int)*(int *)((int)param_1 + 1004) + 0)),(local_134),&DAT_001dbd14,&DAT_001fa5e8,(*(int *)((int)*(int *)((int)param_1 + 1004) + 0)),uVar5,&DAT_001dbd14,&DAT_001fa5e8);
              }
              else {
                iVarS40 = local_1b8;
                iVarS41 = local_1b4;
                iVarS42 = &DAT_001dbd14;
                iVarS43 = &DAT_001fa5e8;
                (**(code **)(((unsigned char *)0x000012ec) + iVar17))
                          (param_1,a1,local_134,&DAT_001dbd84,iVar8,*(undefined4 *)(iVar15 + 0x14),
                           &DAT_001dbd14,&DAT_001fa5e8,iVarS40,iVarS41,iVarS42,iVarS43);
                if ((bVar2) || (*(ushort *)(((unsigned char *)0x00002d48) + iVar11) != local_94)) {
                  uVar20 = *puVar12;
                  puVar9 = (undefined4 *)(((unsigned char *)0x000048a0) + local_88);
                  iVar4 = iVar3;
                  goto LAB_00098038;
                }
                uVar20 = *puVar12;
                puVar9 = (undefined4 *)(((unsigned char *)0x000048a0) + local_88);
                iVar4 = iVar3;
LAB_00097fd4:
                (**(code **)(((unsigned char *)0x000012ec) + iVar17))
                          (param_1,a1,uVar5,&DAT_001dbd84,iVar4,uVar20,puVar9,&DAT_001fa5e8,(*(int *)((int)*(int *)((int)param_1 + 1004) + 0)),(local_134),&DAT_001dbd14,&DAT_001fa5e8);
              }
              FUN_000911a0(param_1,local_5c);
              goto LAB_000980d0;
            }
            goto LAB_000984a0;
          }
          if ((*(int *)(param_1 + 0x420) != -1) ||
             (FUN_00092220(param_1), *(int *)(param_1 + 0x420) != -1)) {
            local_6c = &local_1b4;
            local_70 = &local_e4;
            iVarS12 = *(int *)((int)*(int *)((int)param_1 + 1004) + 0);
            iVarS13 = *(int *)((int)*(int *)((int)param_1 + 980) + 4848);
            iVarS14 = &local_e4;
            iVarS57 = *(int *)((int)*(int *)((int)param_1 + 1004) + 0);
            iVarS58 = *(int *)((int)param_1 + 1056);
            iVarS59 = &DAT_001dbd94;
            (**(code **)(((unsigned char *)0x000012f0) + iVar17))
                      (param_1,a1,local_e4,auStack_e0,iVar8,*(undefined4 *)(iVar15 + 0x24),&DAT_001dbd14,&DAT_001fa5e8,iVarS57,iVarS58,&DAT_001dbd14,iVarS59);
            local_60 = auStack_148;
            (**(code **)(((unsigned char *)0x000012e4) + iVar17))
                      (param_1,a1,local_10c,auStack_108,iVar3,local_e4,auStack_d0,&DAT_001fa5e8,iVar3,local_e4,auStack_d0,&DAT_001fa5e8);
            iVarS10 = *(int *)((int)*(int *)((int)param_1 + 980) + 4836);
            iVarS56 = &DAT_001dbd74;
            (**(code **)(((unsigned char *)0x000012e4) + iVar17))
                      (param_1,a1,local_184,auStack_180,iVar3,local_e4,auStack_d0,&DAT_001fa5e8,iVarS9,(*(char *)(iVar17 + 0x128) == '\0' ? (*(char *)(iVar17 + 300) == '\0' ? (*(char *)(iVar17 + 0x12a) == '\0' ? *(int *)(param_1 + 4) : *(int *)(param_1 + 0x448)) : *(int *)(param_1 + 0x470)) : *(int *)(param_1 + 0x498)),iVarS56,&DAT_001fa5e8);
            (**(code **)(((unsigned char *)0x00001318) + iVar17))
                      (param_1,a1,local_10c,auStack_108,iVar3,local_10c,auStack_f8,&DAT_001fa5e8);
            iVarS44 = &auStack_f8;
            (**(code **)(((unsigned char *)0x000012ec) + iVar17))
                      (param_1,a1,local_10c,auStack_108,iVar3,local_184,auStack_170,&DAT_001fa5e8,iVar3,local_10c,iVarS44,&DAT_001fa5e8);
            goto LAB_00097a58;
          }
          goto LAB_000984b0;
        }
      }
    }
LAB_000984a0:
    iVar11 = 7;
  }
  return iVar11;
LAB_00097a40:
  puVar9 = puVar9 + 1;
  puVar12 = puVar12 + 10;
  puVar18 = &DAT_001dbd94;
  if (uVar19 == 0) goto LAB_00097a58;
  goto LAB_00097a68;
}

/* ffvpEmitLight @ 0x98500 (6432 bytes) */
int ffvpEmitLight(programBuilder, lightIndex, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10)
  int programBuilder;
  int lightIndex;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
  int param_7;
  int param_8;
  int param_9;
  int param_10;
{
  int iVarSw0;
  int iVarSw1;
  int iVarSw2;
  bool bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined *puVar11;
  undefined4 *puVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  undefined4 a1;
  int lightRecord;
  int a4;
  int iVar17;
  undefined4 uVar18;
  undefined *puVar19;
  uint uVar20;
  code *pcVar21;
  undefined4 uVar22;
  undefined1 *puVar23;
  undefined1 *puVar24;
  int iStack00000020;
  int iStack00000024;
  int local_228;
  undefined1 auStack_224 [4];
  undefined1 auStack_220 [4];
  int local_21c;
  undefined1 auStack_218 [16];
  undefined4 local_208;
  undefined4 local_204;
  undefined4 local_200;
  undefined4 local_1fc;
  int local_1f8;
  undefined4 local_1f4;
  undefined4 local_1f0;
  undefined4 local_1ec;
  undefined1 auStack_1e8 [4];
  undefined4 local_1e4;
  undefined1 auStack_1e0 [32];
  undefined1 auStack_1c0 [4];
  undefined4 local_1bc;
  undefined1 auStack_1b8 [16];
  undefined1 auStack_1a8 [16];
  undefined1 auStack_198 [4];
  undefined4 local_194;
  undefined1 auStack_190 [16];
  undefined1 auStack_180 [16];
  undefined1 auStack_170 [4];
  undefined4 local_16c;
  undefined1 auStack_168 [16];
  undefined1 auStack_158 [16];
  undefined1 auStack_148 [4];
  undefined4 local_144;
  undefined1 auStack_140 [32];
  undefined1 auStack_120 [4];
  undefined4 local_11c;
  undefined1 auStack_118 [16];
  undefined1 auStack_108 [16];
  undefined1 auStack_f8 [4];
  undefined4 local_f4;
  undefined1 auStack_f0 [16];
  undefined1 auStack_e0 [56];
  uint local_a8;
  int local_a4;
  undefined1 *local_a0;
  uint local_9c;
  code *local_98;
  code *local_94;
  code *local_90;
  code *local_8c;
  code *local_88;
  undefined1 *local_84;
  code *local_80;
  undefined1 *local_7c;
  undefined1 *local_78;
  code *local_74;
  undefined1 *local_70;
  undefined1 *local_6c;
  undefined1 *local_68;
  undefined *local_64;
  code *local_60;
  int iVarS1;
  int iVarS2;
  int iVarS3;
  int iVarS4;
  int iVarS5;
  int iVarS6;
  int iVarS7;
  int iVarS8;
  int iVarS9;
  int iVarS10;
  int iVarS11;
  int iVarS12;
  int iVarS13;
  int iVarS14;
  int iVarS15;
  int iVarS16;
  int iVarS17;
  int iVarS18;
  int iVarS19;
  int iVarS20;
  int iVarS21;
  int iVarS22;
  int iVarS23;
  int iVarS24;
  int iVarS25;
  int iVarS26;
  int iVarS27;
  int iVarS28;
  int iVarS29;
  int iVarS30;
  int iVarS31;
  int iVarS32;
  int iVarS33;
  int iVarS34;
  int iVarS35;
  int iVarS36;
  int iVarS37;
  int iVarS38;
  int iVarS39;
  int iVarS40;
  int iVarS41;
  int iVarS42;
  int iVarS43;
  int iVarS44;
  int iVarS45;
  int iVarS46;
  int iVarS47;
  int iVarS48;
  int iVarS49;
  int iVarS50;
  int iVarS51;
  int iVarS52;
  int iVarS53;
  int iVarS54;
  int iVarS55;
  int iVarS56;
  int iVarS57;
  int iVarS58;
  int iVarS59;
  int iVarS60;
  int iVarS61;
  int iVarS62;
  int iVarS63;
  int iVarS64;
  int iVarS65;
  int iVarS66;
  int iVarS67;
  int iVarS68;
  int iVarS69;
  int iVarS70;
  int iVarS71;
  int iVarS72;
  int iVarS73;
  int iVarS74;
  int iVarS75;
  int iVarS76;
  int iVarS77;
  int iVarS78;
  int iVarS79;
  int iVarS80;
  int iVarS81;
  int iVarS82;
  int iVarS83;
  int iVarS84;
  int iVarS85;
  int iVarS86;
  int iVarS87;
  int iVarS88;
  int iVarS89;
  int iVarS90;
  int iVarS91;
  int iVarS92;
  int iVarS93;
  int iVarS94;
  int iVarS95;
  int iVarS96;
  int iVarS97;
  
  if (programBuilder == 0) {
    return 1;
  }
  lightRecord = programBuilder + 0xf8 + lightIndex * 0x3c;
  if (*(int *)(lightRecord + 0x24) == -1) {
    return 2;
  }
  bVar1 = param_5 != 0;
  if (bVar1) {
    if (param_6 == 0) {
      iVar4 = *(int *)(lightRecord + 0x2c);
    }
    else {
      iVar4 = *(int *)(lightRecord + 0x34);
    }
    if (iVar4 == -1) {
      return 2;
    }
  }
  iVar4 = *(int *)(programBuilder + 0x3d4);
  iVar17 = *(int *)(*(int *)(iVar4 + 4) + 0x10);
  if (((unsigned char *)0x0000150c)[lightIndex * 0x6c + iVar4] != '\0') {
    if (*(int *)(lightRecord + 0x28) == -1) {
      return 2;
    }
    if (*(int *)(lightRecord + 0x30) == -1) {
      return 2;
    }
    if ((*(float *)(lightIndex * 0x80 + iVar17 + 0x251c) != 0.0) && (*(int *)(lightRecord + 0x38) == -1)) {
      return 2;
    }
  }
  if ((param_8 == 2) && (*(int *)(lightRecord + 4) == -1)) {
    return 2;
  }
  if (param_9 == 2) {
    iVar5 = (byte)((unsigned char *)0x00002d48)[iVar17 + 4] + 1;
    iVar9 = lightRecord;
    do {
      if ((*(int *)(iVar9 + 0xc) == -1) && (*(int *)(lightRecord + 8) == -1)) {
        return 2;
      }
      iVar9 = iVar9 + 4;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  bVar2 = param_10 == 0;
  iStack00000020 = param_3;
  iStack00000024 = param_4;
  if (!bVar2) {
    uVar20 = 0;
    do {
      iVar9 = FUN_000913e0(programBuilder,*(undefined4 *)(iVar4 + 0x290),auStack_224,auStack_220,
                           auStack_218);
      if (iVar9 != 0) {
        return iVar9;
      }
      uVar20 = uVar20 + 1;
      iVar4 = iVar4 + 4;
    } while (uVar20 <= (byte)((unsigned char *)0x00002d48)[iVar17 + 4]);
  }
  if (param_10 == 2) {
    iVar17 = (byte)((unsigned char *)0x00002d48)[iVar17 + 4] + 1;
    iVar4 = lightRecord;
    do {
      if ((*(int *)(iVar4 + 0x18) == -1) && (*(int *)(lightRecord + 0x14) == -1)) {
        return 2;
      }
      iVar4 = iVar4 + 4;
      iVar17 = iVar17 + -1;
    } while (iVar17 != 0);
  }
  local_84 = auStack_1e8;
  iVar9 = *(int *)(programBuilder + 0x3d4);
  iVar17 = *(int *)(*(int *)(iVar9 + 4) + 0x10);
  iVar4 = ffvpAllocTempRegister(programBuilder,1,local_84);
  if (iVar4 != 0) {
    return 7;
  }
  local_7c = auStack_198;
  iVar4 = ffvpAllocTempRegister(programBuilder,1,local_7c);
  if (iVar4 != 0) {
    return 7;
  }
  local_70 = auStack_148;
  iVar4 = ffvpAllocTempRegister(programBuilder,2,local_70);
  if (iVar4 != 0) {
    return 7;
  }
  iVar4 = ffvpAllocTempRegister(programBuilder,2,auStack_120);
  if (iVar4 != 0) {
    return 7;
  }
  iVar4 = *(int *)(programBuilder + 0x3f8);
  if (iVar4 == -1) {
    if ((*(uint *)(((unsigned char *)0x000013c0) + iVar9) & 4) == 0) {
      FUN_000916d0(programBuilder);
    }
    else {
      FUN_000914e0(programBuilder);
    }
    iVar4 = *(int *)(programBuilder + 0x3f8);
    if (iVar4 == -1) {
      return 2;
    }
  }
  if (*(char *)(iVar9 + 0x128) == '\0') {
    if (*(char *)(iVar9 + 300) == '\0') {
      if (*(int *)(programBuilder + 0x448) != -1) goto LAB_00098818;
      FUN_00091a30(programBuilder);
      iVar5 = *(int *)(programBuilder + 0x448);
    }
    else {
      if (*(int *)(programBuilder + 0x470) != -1) goto LAB_00098818;
      FUN_00091d70(programBuilder);
      iVar5 = *(int *)(programBuilder + 0x470);
    }
  }
  else {
    if (*(int *)(programBuilder + 0x498) != -1) goto LAB_00098818;
    FUN_00091b90(programBuilder);
    iVar5 = *(int *)(programBuilder + 0x498);
  }
  if (iVar5 == -1) {
    return 2;
  }
LAB_00098818:
  iVar5 = (*(int **)(programBuilder + 0x3ec))[2];
  a1 = **(undefined4 **)(programBuilder + 0x3f0);
  a4 = **(int **)(programBuilder + 0x3ec);
  if (param_7 == 0) {
    local_64 = &DAT_001f8514;
    local_60 = KhanVs__deleting_dtor_1d8514;
    local_80 = KhanVs__deleting_dtor_1d8514;
    iVarS11 = *(int *)((int)*(int *)((int)programBuilder + 1004) + 8);
    iVarS12 = *(int *)((int)lightRecord + 36);
    iVarS13 = &DAT_001dbd14;
    (**(code **)(((unsigned char *)0x000012ec) + iVar9))
              (programBuilder,a1,local_1e4,auStack_1e0,a4,iVar4,&DAT_001dbcd4,&DAT_001fa5e8,iVarS11,iVarS12,iVarS13,&DAT_001fa5e8);
    iVarS48 = *(int *)((int)*(int *)((int)programBuilder + 1004) + 0);
    iVarS49 = *(int *)((int)programBuilder + 1016);
    iVarS50 = &DAT_001dbd14;
    iVarS51 = &DAT_001fa5e8;
    (**(code **)(((unsigned char *)0x000012f4) + iVar9))
              (programBuilder,a1,local_1e4,auStack_1e0,iVar5,*(undefined4 *)(lightRecord + 0x24),&DAT_001dbcd4,
               ((unsigned char *)0x00003880) + (int)local_80,iVarS48,iVarS49,iVarS50,iVarS51,iVarS48,local_1e4,iVarS50,iVarS51);
  }
  else {
    local_64 = &DAT_001f8514;
    local_60 = KhanVs__deleting_dtor_1d8514;
    local_80 = KhanVs__deleting_dtor_1d8514;
    iVarS52 = *(int *)((int)*(int *)((int)programBuilder + 1004) + 8);
    iVarS53 = *(int *)((int)lightRecord + 36);
    iVarS54 = &DAT_001dbd14;
    iVarS55 = &DAT_001dbd94;
    (**(code **)(((unsigned char *)0x000012f4) + iVar9))
              (programBuilder,a1,local_1e4,auStack_1e0,a4,iVar4,&DAT_001dbcd4,&DAT_001fa5e8,iVarS52,iVarS53,iVarS54,&DAT_001fa5e8,a4,iVar4,iVarS54,iVarS55);
  }
  local_6c = auStack_108;
  local_74 = KhanVs__deleting_dtor_1d8514;
  pcVar21 = 0x000020d4 + (int)local_64;
  (**(code **)(((unsigned char *)0x000012e4) + iVar9))
            (programBuilder,a1,local_194,&DAT_001dbd04,a4,local_1e4,&DAT_001dbd74,pcVar21,a4,local_1e4,&DAT_001dbd74,pcVar21);
  (**(code **)(((unsigned char *)0x00001318) + iVar9))
            (programBuilder,a1,local_11c,auStack_118,a4,local_194,&DAT_001fa5f8,pcVar21);
  iVarS14 = (int)local_60 + 14336;
  (**(code **)(((unsigned char *)0x000012ec) + iVar9))
            (programBuilder,a1,local_1e4,auStack_1e0,a4,local_11c,local_6c,pcVar21,a4,local_1e4,iVarS14,pcVar21);
  if ((bVar1) && (param_6 == 0)) {
    iVarS15 = &DAT_001fa5f8;
    (**(code **)(((unsigned char *)0x000012ec) + iVar9))
              (programBuilder,a1,local_194,&DAT_001dbd64,a4,local_11c,local_6c,pcVar21,a4,local_194,iVarS15,pcVar21);
    local_1f4 = 1;
    local_1f0 = 5;
    local_1ec = 4;
    local_1f8 = param_6;
    iVarS1 = *(int *)((int)*(int *)((int)programBuilder + 1004) + 0);
    iVarS2 = *(int *)((int)*(int *)((int)programBuilder + 980) + 4836);
    iVarS3 = &local_1f8;
    iVarS89 = *(int *)((int)*(int *)((int)programBuilder + 1004) + 0);
    iVarS90 = local_194;
    iVarS91 = &local_1f8;
    (**(code **)(((unsigned char *)0x000012e4) + iVar9))
              (programBuilder,a1,local_11c,auStack_118,iVar5,*(undefined4 *)(lightRecord + 0x2c),&DAT_001dbd74,pcVar21,iVarS89,iVarS90,iVarS91,pcVar21);
    (**(code **)(((unsigned char *)0x00001314) + iVar9))
              (programBuilder,a1,local_11c,auStack_118,a4,local_11c,local_6c,pcVar21);
  }
  if (((unsigned char *)0x0000150c)[lightIndex * 0x6c + iVar9] == '\0') {
    local_a0 = auStack_120;
    if (bVar1) {
      if (param_6 == 0) {
        local_a4 = 1;
      }
      else {
        local_a4 = 1;
        (**(code **)(((unsigned char *)0x000012e8) + iVar9))
                  (programBuilder,a1,local_11c,auStack_118,iVar5,*(undefined4 *)(lightRecord + 0x34),
                   local_60 + 0x3800,0x000020d4 + (int)local_64);
      }
    }
    else {
      local_a4 = 0;
    }
  }
  else {
    iVar4 = ffvpAllocTempRegister(programBuilder,2,auStack_1c0);
    if (iVar4 != 0) {
      return 7;
    }
    pcVar21 = 0x000020d4 + (int)local_64;
    iVarS4 = *(int *)((int)*(int *)((int)programBuilder + 1004) + 0);
    iVarS5 = *(int *)((int)*(int *)((int)programBuilder + 980) + 4836);
    iVarS92 = *(int *)((int)*(int *)((int)programBuilder + 1004) + 0);
    iVarS93 = local_1e4;
    (**(code **)(((unsigned char *)0x000012e4) + iVar9))
              (programBuilder,a1,local_1bc,auStack_1b8,iVar5,*(undefined4 *)(lightRecord + 0x28),((unsigned char *)0x00003860) + (int)local_74,pcVar21,iVarS92,iVarS93,((unsigned char *)0x00003860) + (int)local_74,pcVar21);
    if (*(float *)(lightIndex * 0x80 + iVar17 + 0x251c) == 0.0) {
      iVarS62 = *(int *)((int)*(int *)((int)programBuilder + 1004) + 8);
      iVarS63 = *(int *)((int)lightRecord + 48);
      iVarS64 = (int)local_60 + 14336;
      (**(code **)(((unsigned char *)0x0000130c) + iVar9))
                (programBuilder,a1,local_1bc,auStack_1b8,a4,local_1bc,auStack_1a8,pcVar21,iVarS62,iVarS63,iVarS64,pcVar21);
    }
    else {
      iVar4 = ffvpAllocTempRegister(programBuilder,2,auStack_170);
      if (iVar4 != 0) {
        return 7;
      }
      iVarS65 = *(int *)((int)*(int *)((int)programBuilder + 1004) + 8);
      iVarS66 = *(int *)((int)lightRecord + 48);
      iVarS67 = (int)local_60 + 14336;
      (**(code **)(((unsigned char *)0x0000130c) + iVar9))
                (programBuilder,a1,local_16c,auStack_168,a4,local_1bc,auStack_1a8,pcVar21,iVarS65,iVarS66,iVarS67,pcVar21);
      iVarS16 = local_16c;
      iVarS17 = &auStack_158;
      (**(code **)(((unsigned char *)0x000012ec) + iVar9))
                (programBuilder,a1,local_1bc,auStack_1b8,a4,local_1bc,auStack_1a8,pcVar21,a4,iVarS16,iVarS17,pcVar21);
      iVarS68 = *(int *)((int)*(int *)((int)programBuilder + 1004) + 8);
      iVarS69 = *(int *)((int)lightRecord + 56);
      iVarS70 = (int)local_60 + 14336;
      (**(code **)(((unsigned char *)0x00001324) + iVar9))
                (programBuilder,a1,local_1bc,auStack_1b8,a4,local_1bc,auStack_1a8,pcVar21,iVarS68,iVarS69,iVarS70,pcVar21);
      FUN_000911a0(programBuilder,auStack_170);
    }
    if (bVar1) {
      if (param_6 == 0) {
        iVarS18 = local_11c;
        iVarS19 = local_6c;
        (**(code **)(((unsigned char *)0x000012ec) + iVar9))
                  (programBuilder,a1,local_1bc,auStack_1b8,a4,local_1bc,auStack_1a8,
                   0x000020d4 + (int)local_64,a4,iVarS18,iVarS19,0x000020d4 + (int)local_64);
      }
      else {
        iVarS20 = *(int *)((int)*(int *)((int)programBuilder + 1004) + 8);
        iVarS21 = *(int *)((int)lightRecord + 52);
        iVarS22 = (int)local_60 + 14336;
        (**(code **)(((unsigned char *)0x000012ec) + iVar9))
                  (programBuilder,a1,local_1bc,auStack_1b8,a4,local_1bc,auStack_1a8,
                   0x000020d4 + (int)local_64,iVarS20,iVarS21,iVarS22,0x000020d4 + (int)local_64);
      }
    }
    local_a0 = auStack_1c0;
    FUN_000911a0(programBuilder,auStack_120);
    local_a4 = 1;
  }
  pcVar21 = 0x000020d4 + (int)local_64;
  (**(code **)(((unsigned char *)0x000012e4) + iVar9))
            (programBuilder,a1,local_144,auStack_140,a4,local_1e4,((unsigned char *)0x00003860) + (int)local_74,pcVar21,a4,(*(char *)(iVar9 + 0x128) == '\0' ? (*(char *)(iVar9 + 300) == '\0' ? *(int *)(programBuilder + 0x448) : *(int *)(programBuilder + 0x470)) : *(int *)(programBuilder + 0x498)),((unsigned char *)0x00003860) + (int)local_74,pcVar21);
  FUN_000911a0(programBuilder,local_7c);
  if ((param_8 != 0) && (param_8 != 3)) {
    uVar20 = 0;
    bVar1 = local_a4 == 0;
    iVar4 = programBuilder;
    do {
      uVar18 = *(undefined4 *)(iVar4 + 0x5b0);
      uVar22 = *(undefined4 *)(iVar4 + 0x64c);
      if (param_8 == 1) {
        if (bVar1) {
          iVarS7 = *(int *)((int)*(int *)((int)programBuilder + 1004) + 0);
          (**(code **)(((unsigned char *)0x000012f0) + iVar9))
                    (programBuilder,a1,uVar18,&DAT_001dbd84,uVar22,*(undefined4 *)(iVar4 + 0x650),
                     &DAT_001dbd14,pcVar21,iVarS7,uVar18,&DAT_001dbd14,pcVar21);
        }
        else {
          /* stack words 9-11 of the shared call below: arm A = stock 0x98f18 (words from local_a0), arm B = stock 0x99058 (goto below) */
          iVarSw0 = a4;
          iVarSw1 = *(int *)((int)local_a0 + 4);
          iVarSw2 = (int)local_a0 + 24;
          uVar7 = *(undefined4 *)(iVar4 + 0x650);
LAB_00099084:
          (**(code **)(((unsigned char *)0x000012f4) + iVar9))
                    (programBuilder,a1,uVar18,&DAT_001dbd84,uVar22,uVar7,&DAT_001dbd14,pcVar21,iVarSw0,iVarSw1,iVarSw2,pcVar21,a4,uVar18,&DAT_001dbd14,pcVar21);
        }
      }
      else {
        if (bVar1) {
          iVarSw0 = *(int *)((int)*(int *)((int)programBuilder + 1004) + 8);
          iVarSw1 = *(int *)((int)lightRecord + 4);
          iVarSw2 = &DAT_001dbd14;
          uVar7 = *(undefined4 *)(iVar4 + 0x650);
          goto LAB_00099084;
        }
        iVar13 = ffvpAllocTempRegister(programBuilder,0,local_7c);
        if (iVar13 != 0) {
          return 7;
        }
        iVarS23 = *(int *)((int)*(int *)((int)programBuilder + 1004) + 8);
        iVarS24 = *(int *)((int)lightRecord + 4);
        (**(code **)(((unsigned char *)0x000012ec) + iVar9))
                  (programBuilder,a1,local_194,&DAT_001dbd24,uVar22,*(undefined4 *)(iVar4 + 0x650),
                   &DAT_001dbd14,pcVar21,iVarS23,iVarS24,&DAT_001dbd14,pcVar21);
        iVarS56 = *(int *)((int)local_a0 + 4);
        iVarS57 = (int)local_a0 + 24;
        (**(code **)(((unsigned char *)0x000012f4) + iVar9))
                  (programBuilder,a1,uVar18,&DAT_001dbd84,a4,local_194,&DAT_001dbd14,pcVar21,a4,iVarS56,iVarS57,pcVar21,a4,uVar18,&DAT_001dbd14,pcVar21);
        FUN_000911a0(programBuilder,local_7c);
      }
      uVar20 = uVar20 + 1;
      iVar4 = iVar4 + 0x28;
    } while (uVar20 <= (byte)((unsigned char *)0x00002d48)[iVar17 + 4]);
  }
  puVar23 = auStack_f8;
  uVar20 = 0;
  local_68 = puVar23;
  do {
    iVar4 = ffvpAllocTempRegister(programBuilder,1,puVar23);
    if (iVar4 != 0) {
      return 7;
    }
    uVar20 = uVar20 + 1;
    puVar23 = puVar23 + 0x28;
  } while (uVar20 <= (byte)((unsigned char *)0x00002d48)[iVar17 + 4]);
  if (bVar2) {
    do {
      uVar20 = 0;
      puVar12 = &local_f4;
      do {
        iVar4 = uVar20 * 0x28;
        uVar20 = uVar20 + 1;
        iVarS87 = ((unsigned char *)auStack_140 + 16);
        iVarS88 = &DAT_001dbdb4;
        (**(code **)(((unsigned char *)0x0000132c) + iVar9))
                  (programBuilder,a1,*puVar12,local_68 + iVar4 + 8,a4,local_144,&DAT_001dbd34,
                   0x000020d4 + (int)local_64,a4,local_144,iVarS87,(uVar20 == 1 ? (0x000020d4 + (int)local_64) : ((int)local_80 + 14464)),a4,local_144,iVarS88,0x000020d4 + (int)local_64);
        if ((byte)((unsigned char *)0x00002d48)[iVar17 + 4] < uVar20) goto LAB_000994dc;
        puVar12 = puVar12 + 10;
      } while (uVar20 != 0);
    } while( true );
  }
  iVar4 = ffvpAllocTempRegister(programBuilder,2,local_7c);
  if (iVar4 == 0) {
    local_78 = auStack_170;
    iVar4 = ffvpAllocTempRegister(programBuilder,2,local_78);
    if (iVar4 == 0) {
      if (((unsigned char *)0x00002d48)[iVar17 + 5] == '\0') {
        local_1f8 = 4;
        local_1f4 = 4;
        local_1ec = 4;
        local_1f0 = 5;
        iVarS8 = *(int *)((int)*(int *)((int)programBuilder + 980) + 4848);
        iVarS95 = &local_1f8;
        (**(code **)(((unsigned char *)0x000012f0) + iVar9))
                  (programBuilder,a1,local_f4,auStack_f0,a4,local_1e4,local_60 + 0x3800,0x000020d4 + (int)local_64,a4,local_1e4,iVarS95,0x000020d4 + (int)local_64);
      }
      else {
        if ((*(int *)(programBuilder + 0x420) == -1) &&
           (FUN_00092220(programBuilder), *(int *)(programBuilder + 0x420) == -1)) {
          return 2;
        }
        iVarS9 = *(int *)((int)programBuilder + 1056);
        iVarS10 = (int)local_80 + 14464;
        (**(code **)(((unsigned char *)0x000012f0) + iVar9))
                  (programBuilder,a1,local_f4,auStack_f0,a4,local_1e4,local_60 + 0x3800,
                   0x000020d4 + (int)local_64,a4,iVarS9,local_60 + 0x3800,iVarS10);
      }
      pcVar21 = 0x000020d4 + (int)local_64;
      (**(code **)(((unsigned char *)0x000012e4) + iVar9))
                (programBuilder,a1,local_194,auStack_190,a4,local_f4,auStack_e0,pcVar21,a4,local_f4,auStack_e0,pcVar21);
      iVarS6 = *(int *)((int)*(int *)((int)programBuilder + 980) + 4836);
      iVarS94 = (int)local_74 + 14432;
      (**(code **)(((unsigned char *)0x000012e4) + iVar9))
                (programBuilder,a1,local_16c,auStack_168,a4,local_f4,auStack_e0,pcVar21,a4,(*(char *)(iVar9 + 0x128) == '\0' ? (*(char *)(iVar9 + 300) == '\0' ? *(int *)(programBuilder + 0x448) : *(int *)(programBuilder + 0x470)) : *(int *)(programBuilder + 0x498)),iVarS94,pcVar21);
      (**(code **)(((unsigned char *)0x00001318) + iVar9))
                (programBuilder,a1,local_194,auStack_190,a4,local_194,auStack_180,pcVar21);
      iVarS25 = &auStack_180;
      (**(code **)(((unsigned char *)0x000012ec) + iVar9))
                (programBuilder,a1,local_194,auStack_190,a4,local_16c,auStack_158,pcVar21,a4,local_194,iVarS25,pcVar21);
      do {
        uVar20 = 0;
        pcVar21 = 0x000020d4 + (int)local_64;
        puVar12 = (undefined4 *)(iVar9 + 0x290);
        puVar10 = &local_f4;
        do {
          FUN_000913e0(programBuilder,*puVar12,&local_228,&local_21c,&local_208);
          iVar4 = uVar20 * 0x28;
          uVar20 = uVar20 + 1;
          iVarS71 = local_144;
          iVarS72 = ((unsigned char *)auStack_140 + 16);
          iVarS73 = local_228;
          iVarS74 = local_21c;
          iVarS75 = &local_208;
          iVarS76 = (int)local_64 + 8404;
          (**(code **)(((unsigned char *)0x0000132c) + iVar9))
                    (programBuilder,a1,*puVar10,local_68 + iVar4 + 8,a4,local_194,auStack_180,pcVar21,a4,iVarS71,iVarS72,pcVar21,iVarS73,iVarS74,iVarS75,iVarS76);
          if ((byte)((unsigned char *)0x00002d48)[iVar17 + 4] < uVar20) {
            FUN_000911a0(programBuilder,local_7c);
            FUN_000911a0(programBuilder,local_78);
LAB_000994dc:
            puVar12 = &local_f4;
            local_98 = KhanVs__deleting_dtor_1d8514;
            local_94 = KhanVs__deleting_dtor_1d8514;
            bVar1 = local_a4 != 0;
            local_8c = KhanVs__deleting_dtor_1d8514;
            bVar3 = iStack00000020 == 0;
            local_9c = 0x81fa;
            local_a8 = 0;
            local_90 = KhanVs__deleting_dtor_1d8514;
            puVar23 = local_68 + 8;
            local_88 = KhanVs__deleting_dtor_1d8514;
            iVar4 = iVar9;
            iVar13 = programBuilder;
            iVar14 = programBuilder;
            iVar15 = lightRecord;
            do {
              if (bVar1) {
                iVarS26 = &DAT_001dbd14;
                (**(code **)(((unsigned char *)0x000012ec) + iVar9))
                          (programBuilder,a1,*puVar12,puVar23,a4,*(undefined4 *)(local_a0 + 4),
                           local_a0 + 0x18,&DAT_001fa5e8,a4,*puVar12,iVarS26,&DAT_001fa5e8);
              }
              if (bVar2) {
                if (((!bVar3) && (*(char *)(iVar9 + 0x12d) != '\0')) &&
                   (*(ushort *)(((unsigned char *)0x00002d48) + iVar17) == local_9c)) {
                  iVarS27 = *(int *)((int)*(int *)((int)programBuilder + 1004) + 0);
                  iVarS28 = *(int *)((int)puVar12 + 0);
                  iVarS29 = &DAT_001dbcf4;
                  (**(code **)(((unsigned char *)0x000012ec) + iVar9))
                            (programBuilder,a1,*(undefined4 *)(iVar14 + 0x600),
                             ((unsigned char *)0x00003870) + (int)local_98,a4,*(undefined4 *)(iVar14 + 0x600),
                             local_60 + 0x3800,&DAT_001fa5e8,iVarS27,iVarS28,iVarS29,&DAT_001fa5e8);
                }
              }
              else {
                uVar18 = *(undefined4 *)(iVar14 + 0x600);
                if (*(int *)(iVar15 + 0x18) == -1) {
                  FUN_000912f0(programBuilder,*(undefined4 *)(iVar4 + 0x288),3,&local_228,&local_21c);
                }
                if (param_10 == 1) {
                  iVar6 = local_228;
                  iVar8 = local_21c;
                  if ((!bVar3) && (*(ushort *)(((unsigned char *)0x00002d48) + iVar17) == local_9c))
                  goto LAB_0009966c;
LAB_000996c0:
                  (**(code **)(((unsigned char *)0x000012f4) + iVar9))
                            (programBuilder,a1,uVar18,((unsigned char *)0x00003870) + (int)local_98,iVar6,iVar8,
                             &DAT_001dbd14,&DAT_001fa5e8,(*(int *)((int)*(int *)((int)programBuilder + 1004) + 0)),(*(int *)((int)puVar12 + 0)),(&DAT_001dbcf4),&DAT_001fa5e8,(*(int *)((int)*(int *)((int)programBuilder + 1004) + 0)),uVar18,(&DAT_001dbd14),&DAT_001fa5e8);
                }
                else {
                  iVar8 = *(int *)(iVar15 + 0x18);
                  if (iVar8 == -1) {
                    iVar6 = ffvpAllocTempRegister(programBuilder,1,local_7c);
                    if (iVar6 != 0) {
                      return 7;
                    }
                    if (iVar5 == local_228) {
                      iVarS30 = *(int *)((int)*(int *)((int)programBuilder + 1004) + 0);
                      iVarS31 = *(int *)((int)puVar12 + 0);
                      iVarS32 = &DAT_001dbcf4;
                      iVarS33 = &DAT_001fa5e8;
                      (**(code **)(((unsigned char *)0x000012ec) + iVar9))
                                (programBuilder,a1,local_194,&DAT_001dbd84,iVar5,local_21c,&DAT_001dbd14,
                                 &DAT_001fa5e8,iVarS30,iVarS31,iVarS32,iVarS33);
                      if ((bVar3) || (*(ushort *)(((unsigned char *)0x00002d48) + iVar17) != local_9c)) {
                        uVar22 = *(undefined4 *)(lightRecord + 0x14);
                        puVar10 = &DAT_001dbd14;
                        iVar6 = iVar5;
                        goto LAB_00099980;
                      }
                      uVar22 = *(undefined4 *)(lightRecord + 0x14);
                      puVar10 = &DAT_001dbd14;
                      iVar6 = iVar5;
LAB_0009991c:
                      (**(code **)(((unsigned char *)0x000012ec) + iVar9))
                                (programBuilder,a1,uVar18,&DAT_001dbd84,iVar6,uVar22,puVar10,&DAT_001fa5e8,(*(int *)((int)*(int *)((int)programBuilder + 1004) + 0)),(local_194),&DAT_001dbd14,&DAT_001fa5e8)
                      ;
                    }
                    else {
                      iVarS34 = local_228;
                      iVarS35 = local_21c;
                      iVarS36 = &DAT_001dbd14;
                      iVarS37 = &DAT_001fa5e8;
                      (**(code **)(((unsigned char *)0x000012ec) + iVar9))
                                (programBuilder,a1,local_194,&DAT_001dbd84,iVar5,
                                 *(undefined4 *)(lightRecord + 0x14),&DAT_001dbd14,&DAT_001fa5e8,iVarS34,iVarS35,iVarS36,iVarS37);
                      if ((!bVar3) && (*(ushort *)(((unsigned char *)0x00002d48) + iVar17) == local_9c)) {
                        uVar22 = *puVar12;
                        puVar10 = (undefined4 *)(((unsigned char *)0x000037e0) + (int)local_94);
                        iVar6 = a4;
                        goto LAB_0009991c;
                      }
                      uVar22 = *puVar12;
                      puVar10 = (undefined4 *)(((unsigned char *)0x000037e0) + (int)local_94);
                      iVar6 = a4;
LAB_00099980:
                      (**(code **)(((unsigned char *)0x000012f4) + iVar9))
                                (programBuilder,a1,uVar18,&DAT_001dbd84,iVar6,uVar22,puVar10,&DAT_001fa5e8,(*(int *)((int)*(int *)((int)programBuilder + 1004) + 0)),(local_194),&DAT_001dbd14,&DAT_001fa5e8,(*(int *)((int)*(int *)((int)programBuilder + 1004) + 0)),uVar18,&DAT_001dbd14,&DAT_001fa5e8)
                      ;
                    }
                    FUN_000911a0(programBuilder,local_7c);
                  }
                  else {
                    iVar6 = iVar5;
                    if ((bVar3) || (*(ushort *)(((unsigned char *)0x00002d48) + iVar17) != local_9c))
                    goto LAB_000996c0;
LAB_0009966c:
                    (**(code **)(((unsigned char *)0x000012ec) + iVar9))
                              (programBuilder,a1,uVar18,((unsigned char *)0x00003870) + (int)local_98,iVar6,iVar8,
                               local_60 + 0x3800,&DAT_001fa5e8,iVar6,uVar18,(&DAT_001dbd34),&DAT_001fa5e8);
                  }
                }
              }
              if (param_9 == 0) {
                if (iStack00000024 != 0) {
                  uVar22 = *(undefined4 *)(iVar13 + 0x74);
                  uVar18 = *(undefined4 *)(iVar14 + 0x5b0);
                  uVar7 = *(undefined4 *)(*(int *)(programBuilder + 0x3f0) + 0xc);
                  FUN_000912f0(programBuilder,*(undefined4 *)(iVar4 + 0x280),2,&local_228,&local_21c);
                  local_1fc = 3;
                  local_200 = 5;
                  local_208 = 5;
                  local_204 = 5;
                  iVarS39 = local_228;
                  iVarS40 = local_21c;
                  iVarS41 = &local_208;
                  (**(code **)(((unsigned char *)0x000012ec) + iVar9))
                            (programBuilder,uVar7,uVar22,((unsigned char *)0x00003810) + (int)local_90,a4,uVar18,
                             ((unsigned char *)0x000038b0) + (int)local_88,&DAT_001fa5e8,iVarS39,iVarS40,iVarS41,&DAT_001fa5e8);
                }
              }
              else {
                uVar18 = *(undefined4 *)(iVar14 + 0x5b0);
                if (iStack00000024 == 0) {
                  uVar22 = **(undefined4 **)(programBuilder + 0x3f0);
                  puVar19 = ((unsigned char *)0x00003870) + (int)local_98;
                }
                else {
                  uVar18 = *(undefined4 *)(iVar13 + 0x74);
                  uVar22 = *(undefined4 *)(*(int *)(programBuilder + 0x3f0) + 0xc);
                  puVar19 = ((unsigned char *)0x00003810) + (int)local_90;
                }
                if (*(int *)(iVar15 + 0xc) == -1) {
                  FUN_000912f0(programBuilder,*(undefined4 *)(iVar4 + 0x280),2,&local_228,&local_21c);
                }
                iVar6 = local_228;
                iVar8 = local_21c;
                if ((param_9 == 1) ||
                   (iVar6 = iVar5, iVar8 = *(int *)(iVar15 + 0xc), *(int *)(iVar15 + 0xc) != -1)) {
                  iVarS79 = *(int *)((int)*(int *)((int)programBuilder + 1004) + 0);
                  iVarS80 = *(int *)((int)puVar12 + 0);
                  iVarS81 = ((unsigned char *)&DAT_001dbdc0 + 44);
                  iVarS82 = *(int *)((int)iVar14 + 1456);
                  iVarS83 = &DAT_001dbd74;
                  (**(code **)(((unsigned char *)0x000012f4) + iVar9))
                            (programBuilder,uVar22,uVar18,puVar19,iVar6,iVar8,local_60 + 0x3800,
                             &DAT_001fa5e8,iVarS79,iVarS80,iVarS81,&DAT_001fa5e8,iVarS79,iVarS82,iVarS83,&DAT_001fa5e8);
                }
                else {
                  iVar6 = ffvpAllocTempRegister(programBuilder,0,local_7c);
                  if (iVar6 != 0) {
                    return 7;
                  }
                  if (iVar5 == local_228) {
                    iVarS42 = *(int *)((int)*(int *)((int)programBuilder + 1004) + 0);
                    iVarS43 = *(int *)((int)puVar12 + 0);
                    iVarS44 = ((unsigned char *)&DAT_001dbdc0 + 44);
                    (**(code **)(((unsigned char *)0x000012ec) + iVar9))
                              (programBuilder,a1,local_194,puVar19,iVar5,local_21c,&DAT_001dbd14,
                               &DAT_001fa5e8,iVarS42,iVarS43,iVarS44,&DAT_001fa5e8);
                    uVar7 = *(undefined4 *)(lightRecord + 8);
                    puVar11 = ((unsigned char *)0x000038b0) + (int)local_88;
                    iVar6 = iVar5;
                  }
                  else {
                    iVarS45 = local_228;
                    iVarS46 = local_21c;
                    iVarS47 = &DAT_001dbd14;
                    (**(code **)(((unsigned char *)0x000012ec) + iVar9))
                              (programBuilder,a1,local_194,puVar19,iVar5,*(undefined4 *)(lightRecord + 8),
                               ((unsigned char *)0x000038b0) + (int)local_88,&DAT_001fa5e8,iVarS45,iVarS46,iVarS47,&DAT_001fa5e8);
                    uVar7 = *puVar12;
                    puVar11 = ((unsigned char *)0x000038d8) + (int)local_8c;
                    iVar6 = a4;
                  }
                  iVarS84 = *(int *)((int)*(int *)((int)programBuilder + 1004) + 0);
                  iVarS85 = local_194;
                  iVarS86 = *(int *)((int)iVar14 + 1456);
                  (**(code **)(((unsigned char *)0x000012f4) + iVar9))
                            (programBuilder,uVar22,uVar18,puVar19,iVar6,uVar7,puVar11,&DAT_001fa5e8,iVarS84,iVarS85,&DAT_001dbd14,&DAT_001fa5e8,iVarS84,iVarS86,&DAT_001dbd74,&DAT_001fa5e8);
                  FUN_000911a0(programBuilder,local_7c);
                }
              }
              puVar24 = local_68;
              puVar23 = puVar23 + 0x28;
              puVar12 = puVar12 + 10;
              iVar13 = iVar13 + 4;
              iVar14 = iVar14 + 0x28;
              iVar4 = iVar4 + 4;
              iVar15 = iVar15 + 4;
              local_a8 = local_a8 + 1;
              if ((byte)((unsigned char *)0x00002d48)[iVar17 + 4] < local_a8) {
                uVar20 = 0;
                FUN_000911a0(programBuilder,local_84);
                FUN_000911a0(programBuilder,local_70);
                FUN_000911a0(programBuilder,local_a0);
                do {
                  uVar20 = uVar20 + 1;
                  FUN_000911a0(programBuilder,puVar24);
                  puVar24 = puVar24 + 0x28;
                } while (uVar20 <= (byte)((unsigned char *)0x00002d48)[iVar17 + 4]);
                return 0;
              }
            } while( true );
          }
          puVar12 = puVar12 + 1;
          puVar10 = puVar10 + 10;
          pcVar21 = (code *)(((unsigned char *)0x00003880) + (int)local_80);
        } while (uVar20 != 0);
      } while( true );
    }
  }
  return 7;
}

/* FUN_00099e50 @ 0x99e50 (1796 bytes) */
int FUN_00099e50(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  int param_3;
{
  bool bVar1;
  bool bVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 a1;
  undefined4 a4;
  undefined4 a4_00;
  int iVar7;
  undefined4 uVar8;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  int local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  int local_d0;
  int local_cc;
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
  undefined1 auStack_a0 [32];
  undefined1 auStack_80 [4];
  undefined4 local_7c;
  undefined1 auStack_78 [16];
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  int iVarS1;
  int iVarS2;
  int iVarS3;
  int iVarS4;
  int iVarS5;
  int iVarS6;
  int iVarS7;
  int iVarS8;
  int iVarS9;
  int iVarS10;
  int iVarS11;
  int iVarS12;
  int iVarS13;
  int iVarS14;
  int iVarS15;
  int iVarS16;
  int iVarS17;
  int iVarS18;
  int iVarS19;
  int iVarS20;
  int iVarS21;
  int iVarS22;
  int iVarS23;
  int iVarS24;
  int iVarS25;
  
  if (param_1 == 0) {
    return 1;
  }
  uVar5 = 4;
  switch(param_2) {
  case 0:
    if (*(int *)(param_1 + 0x4c) == -1) {
      return 2;
    }
  case 2:
    iVar3 = *(int *)(param_1 + 0x334);
    break;
  case 1:
    iVar3 = *(int *)(param_1 + 0x4c);
    break;
  case 3:
    if (*(int *)(param_1 + 0x4c) == -1) {
      return 2;
    }
  case 4:
    iVar3 = *(int *)(param_1 + 0x334);
    goto joined_r0x00099f10;
  default:
    goto switchD_00099ea8_default;
  }
  if (iVar3 == -1) {
    return 2;
  }
  iVar3 = *(int *)(param_1 + 0x338);
joined_r0x00099f10:
  if (iVar3 == -1) {
    return 2;
  }
  if (*(int *)(param_1 + 0x340) == -1) {
    return 2;
  }
  if (*(int *)(param_1 + 0x6c) == -1) {
    return 2;
  }
  iVar7 = *(int *)(param_1 + 0x3d4);
  iVar3 = ffvpAllocTempRegister(param_1,2,auStack_80);
  bVar1 = param_2 < 3;
  if (iVar3 != 0) {
    return 7;
  }
  if ((bVar1) && (iVar3 = ffvpAllocTempRegister(param_1,1,auStack_a8), iVar3 != 0)) {
    return 7;
  }
  puVar4 = *(undefined4 **)(param_1 + 0x3ec);
  local_58 = (*(undefined4 **)(param_1 + 0x3f0))[7];
  a4 = puVar4[2];
  a1 = **(undefined4 **)(param_1 + 0x3f0);
  uVar5 = *puVar4;
  a4_00 = puVar4[1];
  if (param_2 == 0) {
    iVarS6 = *(int *)((int)*(int *)((int)param_1 + 1004) + 8);
    iVarS7 = *(int *)((int)*(int *)((int)param_1 + 980) + 4844);
    iVarS8 = &DAT_001dbcf4;
    iVarS15 = *(int *)((int)*(int *)((int)param_1 + 1004) + 8);
    iVarS16 = *(int *)((int)param_1 + 820);
    iVarS17 = &DAT_001dbcf4;
    (**(code **)(((unsigned char *)0x000012ec) + iVar7))
              (param_1,a1,local_a4,&DAT_001dbd54,a4_00,*(undefined4 *)(param_1 + 0x4c),&DAT_001fa5f8,&DAT_001fa5e8,iVarS15,iVarS16,iVarS17,&DAT_001fa5e8);
  }
  if (bVar1) {
    if ((*(int *)(param_1 + 0x510) == -1) &&
       (FUN_00091880(param_1), *(int *)(param_1 + 0x510) == -1)) {
      return 2;
    }
    uVar6 = *(undefined4 *)(param_1 + 0x338);
    if (param_3 == 0) {
      iVar3 = *(int *)(param_1 + 0x538);
      if (iVar3 == -1) {
        FUN_00092150(param_1);
        iVar3 = *(int *)(param_1 + 0x538);
        if (iVar3 == -1) {
          return 2;
        }
      }
      local_d8 = 1;
      local_d4 = 1;
      local_e0 = 4;
      local_dc = 4;
      local_e4 = 5;
      local_e8 = *(undefined4 *)(param_1 + 0x54c);
      local_d0 = param_3;
      local_cc = param_3;
      iVarS9 = &auStack_78;
      iVarS10 = (int)param_1 + 1316;
      iVarS18 = *(int *)((int)param_1 + 1296);
      iVarS19 = (int)param_1 + 1316;
      (**(code **)(((unsigned char *)0x000012ec) + iVar7))
                (param_1,a1,local_a4,&local_d8,uVar5,iVar3,&local_e8,&DAT_001fa5e8,uVar5,iVarS18,iVarS19,&DAT_001fa5e8);
      local_e8 = 1;
      local_e0 = 5;
      local_dc = 4;
      local_e4 = param_3;
      iVarS1 = *(int *)((int)*(int *)((int)param_1 + 1004) + 0);
      iVarS2 = *(int *)((int)*(int *)((int)param_1 + 980) + 4836);
      iVarS20 = *(int *)((int)*(int *)((int)param_1 + 1004) + 0);
      iVarS21 = local_a4;
      iVarS22 = &local_e8;
      (**(code **)(((unsigned char *)0x000012e4) + iVar7))
                (param_1,a1,local_7c,auStack_78,a4,uVar6,&DAT_001dbd74,&DAT_001fa5e8,iVarS20,iVarS21,iVarS22,&DAT_001fa5e8);
    }
    else {
      local_e8 = *(undefined4 *)(param_1 + 0x524);
      local_e0 = 5;
      local_dc = 4;
      local_e4 = 4;
      iVarS3 = *(int *)((int)*(int *)((int)param_1 + 1004) + 0);
      iVarS4 = *(int *)((int)*(int *)((int)param_1 + 980) + 4836);
      iVarS5 = &local_e8;
      iVarS23 = *(int *)((int)*(int *)((int)param_1 + 1004) + 0);
      iVarS24 = *(int *)((int)param_1 + 1296);
      iVarS25 = &local_e8;
      (**(code **)(((unsigned char *)0x000012e4) + iVar7))
                (param_1,a1,local_7c,auStack_78,a4,uVar6,&DAT_001dbd74,&DAT_001fa5e8,iVarS23,iVarS24,iVarS25,&DAT_001fa5e8);
    }
    (**(code **)(((unsigned char *)0x00001318) + iVar7))
              (param_1,a1,local_7c,auStack_78,uVar5,local_7c,&local_68,&DAT_001fa5e8);
  }
  uVar6 = local_7c;
  switch(param_2) {
  case 0:
    bVar2 = false;
    local_c8 = DAT_001dbcf4;
    local_c4 = DAT_001dbcf8;
    local_f4 = local_64;
    local_c0 = DAT_001dbcfc;
    local_bc = DAT_001dbd00;
    local_f8 = local_68;
    local_ec = local_5c;
    local_f0 = local_60;
    a4_00 = uVar5;
    uVar8 = local_a4;
    break;
  case 1:
    uVar8 = *(undefined4 *)(param_1 + 0x4c);
    bVar2 = false;
    local_c8 = DAT_001fa5f8;
    local_c4 = DAT_001fa5fc;
    local_f4 = local_64;
    local_c0 = DAT_001fa600;
    local_bc = DAT_001fa604;
    local_f8 = local_68;
    local_ec = local_5c;
    local_f0 = local_60;
    break;
  case 2:
    local_c4 = local_64;
    local_c8 = local_68;
    local_bc = local_5c;
    local_c0 = local_60;
    goto LAB_0009a3bc;
  case 3:
    local_7c = *(undefined4 *)(param_1 + 0x4c);
    local_c8 = DAT_001fa5f8;
    local_bc = DAT_001fa604;
    local_c4 = DAT_001fa5fc;
    local_c0 = DAT_001fa600;
    uVar5 = a4_00;
    goto LAB_0009a3bc;
  case 4:
    local_7c = *(undefined4 *)(param_1 + 0x340);
    local_c8 = DAT_001dbdb4;
    local_bc = DAT_001dbdc0;
    local_c4 = DAT_001dbdb8;
    local_c0 = DAT_001dbdbc;
    uVar5 = a4;
LAB_0009a3bc:
    bVar2 = true;
    local_f8 = DAT_001dbcf4;
    local_f4 = DAT_001dbcf8;
    local_f0 = DAT_001dbcfc;
    local_ec = DAT_001dbd00;
    a4_00 = uVar5;
    uVar8 = local_7c;
    uVar5 = a4;
    uVar6 = *(undefined4 *)(param_1 + 0x334);
    break;
  default:
    bVar2 = false;
    a4_00 = 0;
    uVar8 = 0;
    uVar5 = 0;
    uVar6 = 0;
  }
  if (bVar1) {
    FUN_000911a0(param_1,auStack_a8);
  }
  local_b8 = 0;
  local_b0 = 4;
  local_b4 = 4;
  local_ac = 1;
  if (bVar2) {
    iVar3 = ffvpAllocTempRegister(param_1,2,auStack_a8);
    if (iVar3 != 0) {
      return 7;
    }
    (**(code **)(((unsigned char *)0x000012e8) + iVar7))
              (param_1,a1,local_a4,auStack_a0,uVar5,uVar6,&local_f8,&DAT_001fa5e8);
    /* stack words, stock 0x9a468-0x9a4a8: r20 = rec[0], local_a4, &local_90 (= auStack_a0 + 16), &DAT_001fa5e8, r17 = rec[2] (a4), *(param_1 + 0x340), &local_b8, &DAT_001fa5e8 */
    (**(code **)(((unsigned char *)0x000012fc) + iVar7))
              (param_1,local_58,*(undefined4 *)(param_1 + 0x6c),&DAT_001dbd24,a4_00,uVar8,&local_c8,
               &DAT_001fa5e8,**(int **)(param_1 + 0x3ec),local_a4,auStack_a0 + 16,&DAT_001fa5e8,a4,*(int *)(param_1 + 0x340),&local_b8,&DAT_001fa5e8);
    FUN_000911a0(param_1,auStack_a8);
  }
  else {
    /* stack words, stock 0x9a4d8-0x9a520: uVar5, uVar6 (the stock's r27/r28), &local_f8, &DAT_001fa5e8, r17 = rec[2] (a4), *(param_1 + 0x340), &local_b8, &DAT_001fa5e8 */
    (**(code **)(((unsigned char *)0x000012fc) + iVar7))
              (param_1,local_58,*(undefined4 *)(param_1 + 0x6c),&DAT_001dbd24,a4_00,uVar8,&local_c8,
               &DAT_001fa5e8,uVar5,uVar6,&local_f8,&DAT_001fa5e8,a4,*(int *)(param_1 + 0x340),&local_b8,&DAT_001fa5e8);
  }
  FUN_000911a0(param_1,auStack_80);
  uVar5 = 0;
switchD_00099ea8_default:
  return uVar5;
}

/* FUN_0009a590 @ 0x9a590 (848 bytes) */
int FUN_0009a590(param_1)
  int param_1;
{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined1 auStack_68 [4];
  undefined4 local_64;
  int iVarS1;
  int iVarS2;
  
  if (param_1 == 0) {
    return 1;
  }
  iVar7 = *(int *)(param_1 + 0x70);
  if (iVar7 != -1) {
    iVar8 = *(int *)(param_1 + 0x3d4);
    uVar6 = *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x18);
    if (*(short *)(((unsigned char *)0x00002e06) + *(int *)(*(int *)(iVar8 + 4) + 0x10)) == -0x7bae) {
      iVar9 = *(int *)(param_1 + 0x3f8);
      if (iVar9 == -1) {
        if ((*(uint *)(((unsigned char *)0x000013c0) + iVar8) & 4) == 0) {
          FUN_000916d0(param_1);
        }
        else {
          FUN_000914e0(param_1);
        }
        iVar9 = *(int *)(param_1 + 0x3f8);
        if (iVar9 == -1) {
          return 2;
        }
        iVar8 = *(int *)(param_1 + 0x3d4);
      }
      iVar3 = *(int *)(*(int *)(iVar8 + 4) + 0x10);
      uVar5 = **(undefined4 **)(param_1 + 0x3ec);
      if ((*(short *)(((unsigned char *)0x00002e06) + iVar3) != -0x7bae) ||
         (*(short *)(((unsigned char *)0x00002e08) + iVar3) == -0x7aa4)) {
        iVarS2 = &DAT_001dbd94;
        (**(code **)(((unsigned char *)0x00001304) + iVar8))
                  (param_1,uVar6,iVar7,&DAT_001dbd04,uVar5,iVar9,&DAT_001dbcf4,&DAT_001fa5e8,uVar5,iVar9,&DAT_001dbcf4,iVarS2);
        return 0;
      }
      if (*(short *)(((unsigned char *)0x00002e08) + iVar3) != -0x7aa5) {
        (**(code **)(((unsigned char *)0x000012e8) + iVar8))
                  (param_1,uVar6,iVar7,&DAT_001dbd04,uVar5,iVar9,&DAT_001dbcf4,&DAT_001dbd94);
        return 0;
      }
      uVar4 = **(undefined4 **)(param_1 + 0x3f0);
      iVar3 = ffvpAllocTempRegister(param_1,1,auStack_68);
      if (iVar3 == 0) {
        (**(code **)(((unsigned char *)0x000012e4) + iVar8))
                  (param_1,uVar4,local_64,&DAT_001dbd04,uVar5,iVar9,&DAT_001dbd74,&DAT_001fa5e8,uVar5,iVar9,&DAT_001dbd74,&DAT_001fa5e8);
        (**(code **)(((unsigned char *)0x00001318) + iVar8))
                  (param_1,uVar4,local_64,&DAT_001dbd64,uVar5,local_64,&DAT_001fa5f8,&DAT_001fa5e8);
        iVarS1 = ((unsigned char *)&DAT_001dbdc0 + 244);
        (**(code **)(((unsigned char *)0x000012e4) + iVar8))
                  (param_1,uVar6,iVar7,&DAT_001dbd04,uVar5,local_64,&DAT_001dbec4,&DAT_001fa5e8,uVar5,local_64,iVarS1,&DAT_001fa5e8);
        FUN_000911a0(param_1,auStack_68);
        return 0;
      }
      return 7;
    }
    if (*(int *)(param_1 + 0x50) != -1) {
      uVar1 = *(uint *)(param_1 + 0x54);
      if (uVar1 < 4) {
        if (uVar1 == 2) {
          puVar2 = &DAT_001dbcf4;
        }
        else if (uVar1 == 3) {
          puVar2 = &DAT_001dbcd4;
        }
        else if (uVar1 == 1) {
          puVar2 = &DAT_001dbce4;
        }
        else {
          puVar2 = &DAT_001fa5f8;
        }
        (**(code **)(((unsigned char *)0x000012e8) + iVar8))
                  (param_1,uVar6,iVar7,&DAT_001dbd04,*(undefined4 *)(*(int *)(param_1 + 0x3ec) + 4),
                   *(int *)(param_1 + 0x50),puVar2,&DAT_001fa5e8);
        return 0;
      }
      return 3;
    }
  }
  return 2;
}

/* FUN_0009a910 @ 0x9a910 (120 bytes) */
int FUN_0009a910(param_1)
  int param_1;
{
  undefined4 uVar1;
  
  if (*(code **)(((unsigned char *)0x000012d8) + *(int *)(param_1 + 0x3d4)) != (code *)0x0) {
    (**(code **)(((unsigned char *)0x000012d8) + *(int *)(param_1 + 0x3d4)))(*(int *)(param_1 + 0x3d4),param_1);
  }
  if ((*(int *)(param_1 + 0x3d8) != 0) ||
     (uVar1 = 6, *(uint *)(param_1 + 0x3cc) <= *(uint *)(param_1 + 0x3e4))) {
    uVar1 = 0;
  }
  return uVar1;
}

/* fpVariantProgramFree @ 0x9a990 (104 bytes) */
int fpVariantProgramFree(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 uVar1;
  
  uVar1 = 1;
  if (param_2 != 0) {
    if (*(int *)(param_2 + 0x3c8) != 0) {
      (**(code **)(param_1 + 0x18))(*(int *)(param_2 + 0x3c8));
    }
    (**(code **)(param_1 + 0x18))(param_2);
    uVar1 = 0;
  }
  return uVar1;
}

/* FUN_0009aa00 @ 0x9aa00 (1232 bytes) */
int FUN_0009aa00(param_1)
  int param_1;
{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 a4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 a1;
  undefined4 a2;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
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
  undefined1 auStack_a0 [24];
  undefined4 local_88;
  undefined1 auStack_80 [4];
  undefined4 local_7c;
  int iVarS1;
  int iVarS2;
  int iVarS3;
  int iVarS4;
  int iVarS5;
  int iVarS6;
  int iVarS7;
  int iVarS8;
  int iVarS9;
  int iVarS10;
  int iVarS11;
  int iVarS12;
  int iVarS13;
  int iVarS14;
  int iVarS15;
  
  iVar8 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x588) != -1) {
    return 0;
  }
  puVar2 = *(undefined4 **)(param_1 + 0x3ec);
  uVar4 = *(undefined4 *)(param_1 + 0x330);
  a1 = **(undefined4 **)(param_1 + 0x3f0);
  a4 = puVar2[2];
  if (*(short *)(((unsigned char *)0x00002e06) + *(int *)(*(int *)(iVar8 + 4) + 0x10)) == -0x7bae) {
    iVar3 = *(int *)(param_1 + 0x3f8);
    if (iVar3 == -1) {
      if ((*(uint *)(((unsigned char *)0x000013c0) + iVar8) & 4) == 0) {
        FUN_000916d0(param_1);
      }
      else {
        FUN_000914e0(param_1);
      }
      iVar3 = *(int *)(param_1 + 0x3f8);
      if (iVar3 == -1) {
        return 2;
      }
      puVar2 = *(undefined4 **)(param_1 + 0x3ec);
    }
    uVar9 = *puVar2;
    puVar2 = &DAT_001dbcf4;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x54);
    uVar9 = puVar2[1];
    iVar3 = *(int *)(param_1 + 0x50);
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
  iVar1 = ffvpAllocTempRegister(param_1,2,param_1 + 0x584);
  if (iVar1 == 0) {
    a2 = *(undefined4 *)(param_1 + 0x588);
    iVar1 = ffvpAllocTempRegister(param_1,2,auStack_a8);
    if (iVar1 == 0) {
      iVar7 = *(int *)(param_1 + 0x3d4);
      iVar1 = *(int *)(*(int *)(iVar7 + 4) + 0x10);
      if ((*(short *)(((unsigned char *)0x00002e06) + iVar1) == -0x7bae) &&
         (*(short *)(((unsigned char *)0x00002e08) + iVar1) != -0x7aa4)) {
        if (*(short *)(((unsigned char *)0x00002e08) + iVar1) == -0x7aa5) {
          uVar5 = **(undefined4 **)(param_1 + 0x3f0);
          uVar6 = **(undefined4 **)(param_1 + 0x3ec);
          iVar1 = ffvpAllocTempRegister(param_1,1,auStack_80);
          if (iVar1 != 0) {
            return 7;
          }
          (**(code **)(((unsigned char *)0x000012e4) + iVar7))
                    (param_1,uVar5,local_7c,&DAT_001dbd04,uVar9,iVar3,&DAT_001dbd74,&DAT_001fa5e8,uVar9,iVar3,&DAT_001dbd74,&DAT_001fa5e8);
          (**(code **)(((unsigned char *)0x00001318) + iVar7))
                    (param_1,uVar5,local_7c,&DAT_001dbd64,uVar6,local_7c,&DAT_001fa5f8,&DAT_001fa5e8
                    );
          iVarS1 = ((unsigned char *)&DAT_001dbdc0 + 244);
          (**(code **)(((unsigned char *)0x000012e4) + iVar7))
                    (param_1,a1,local_a4,auStack_a0,uVar6,local_7c,&DAT_001dbec4,&DAT_001fa5e8,uVar6,local_7c,iVarS1,&DAT_001fa5e8);
          FUN_000911a0(param_1,auStack_80);
        }
        else {
          (**(code **)(((unsigned char *)0x000012e8) + iVar7))
                    (param_1,a1,local_a4,auStack_a0,uVar9,iVar3,puVar2,&DAT_001dbd94);
        }
      }
      else {
        iVarS8 = &DAT_001dbd94;
        (**(code **)(((unsigned char *)0x00001304) + iVar7))
                  (param_1,a1,local_a4,auStack_a0,uVar9,iVar3,puVar2,&DAT_001fa5e8,uVar9,iVar3,puVar2,iVarS8);
      }
      uVar9 = **(undefined4 **)(param_1 + 0x3ec);
      local_ac = 4;
      local_c8 = 4;
      local_c0 = 2;
      local_c4 = 1;
      local_bc = 4;
      local_b8 = 4;
      local_b4 = 5;
      local_b0 = local_88;
      if (*(int *)(param_1 + 0x3d8) != 0) {
        iVarS2 = *(int *)((int)*(int *)((int)param_1 + 1004) + 0);
        iVarS3 = *(int *)((int)*(int *)((int)param_1 + 980) + 4836);
        iVarS4 = &local_b8;
        iVarS10 = *(int *)((int)*(int *)((int)param_1 + 1004) + 0);
        iVarS11 = local_a4;
        iVarS12 = &local_b8;
        (**(code **)(((unsigned char *)0x000012e4) + iVar8))
                  (param_1,*(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x18),*(undefined4 *)(param_1 + 0x70),&DAT_001dbd04,a4,uVar4,&local_c8,&DAT_001fa5e8,iVarS10,iVarS11,iVarS12,&DAT_001fa5e8);
        FUN_000911a0(param_1,auStack_a8);
        return 0;
      }
      puVar2 = (undefined4 *)(param_1 + 0x58c);
      iVarS5 = *(int *)((int)*(int *)((int)param_1 + 1004) + 0);
      iVarS6 = *(int *)((int)*(int *)((int)param_1 + 980) + 4836);
      iVarS7 = &local_b8;
      iVarS13 = *(int *)((int)*(int *)((int)param_1 + 1004) + 0);
      iVarS14 = local_a4;
      iVarS15 = &local_b8;
      (**(code **)(((unsigned char *)0x000012e4) + iVar8))(param_1,a1,a2,puVar2,a4,uVar4,&local_c8,&DAT_001fa5e8,iVarS13,iVarS14,iVarS15,&DAT_001fa5e8);
      FUN_000911a0(param_1,auStack_a8);
      uVar4 = a2;
      if (-1 < *(int *)(iVar8 + 0x44)) {
        uVar4 = *(undefined4 *)(param_1 + 0x70);
        puVar2 = &DAT_001dbd44;
        a1 = *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x18);
      }
      iVarS9 = &DAT_001dbdb4;
      (**(code **)(((unsigned char *)0x00001328) + iVar8))
                (param_1,a1,uVar4,puVar2,uVar9,a2,param_1 + 0x59c,&DAT_001fa5e8,uVar9,a2,iVarS9,&DAT_001fa5e8);
      return 0;
    }
  }
  return 7;
}

/* FUN_0009af00 @ 0x9af00 (172 bytes) */
int FUN_0009af00(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  
  if ((*(int *)(param_1 + 0x330) == -1) || (iVar2 = *(int *)(param_1 + 0x70), iVar2 == -1)) {
    return 2;
  }
  if (*(short *)(((unsigned char *)0x00002e06) + *(int *)(*(int *)(*(int *)(param_1 + 0x3d4) + 4) + 0x10)) ==
      -0x7baf) {
    if (*(int *)(param_1 + 0x50) == -1) {
      return 2;
    }
    if (3 < *(uint *)(param_1 + 0x54)) {
      return 3;
    }
  }
  if ((((*(int *)(param_1 + 0x3d8) == 0) && (iVar2 != *(int *)(param_1 + 0x74))) &&
      (iVar2 != *(int *)(param_1 + 0x78))) &&
     ((iVar2 != *(int *)(param_1 + 0x7c) && (iVar2 != *(int *)(param_1 + 0x80))))) {
    return 3;
  }
  *(undefined1 *)(*(int *)(param_1 + 0x3d4) + 0x12e) = 0;
  uVar1 = ((int (*)())FUN_0009aa00)(param_1);
  return uVar1;
}

/* FUN_0009afc0 @ 0x9afc0 (1084 bytes) */
int FUN_0009afc0(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 a4;
  undefined4 a5;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 a1;
  undefined4 uVar9;
  int iVar10;
  undefined1 auStack_a8 [4];
  undefined4 local_a4;
  undefined1 auStack_a0 [16];
  undefined1 auStack_90 [16];
  undefined1 auStack_80 [4];
  undefined4 local_7c;
  int iVarS1;
  int iVarS2;
  int iVarS3;
  int iVarS4;
  
  iVar10 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x588) != -1) {
    return 0;
  }
  puVar3 = *(undefined4 **)(param_1 + 0x3ec);
  a5 = *(undefined4 *)(param_1 + 0x330);
  a1 = **(undefined4 **)(param_1 + 0x3f0);
  a4 = puVar3[2];
  if (*(short *)(((unsigned char *)0x00002e06) + *(int *)(*(int *)(iVar10 + 4) + 0x10)) == -0x7bae) {
    iVar4 = *(int *)(param_1 + 0x3f8);
    if (iVar4 == -1) {
      if ((*(uint *)(((unsigned char *)0x000013c0) + iVar10) & 4) == 0) {
        FUN_000916d0(param_1);
      }
      else {
        FUN_000914e0(param_1);
      }
      iVar4 = *(int *)(param_1 + 0x3f8);
      if (iVar4 == -1) {
        return 2;
      }
      puVar3 = *(undefined4 **)(param_1 + 0x3ec);
    }
    uVar9 = *puVar3;
    puVar3 = &DAT_001dbcf4;
  }
  else {
    iVar2 = *(int *)(param_1 + 0x54);
    uVar9 = puVar3[1];
    iVar4 = *(int *)(param_1 + 0x50);
    if (iVar2 == 1) {
      puVar3 = &DAT_001dbce4;
    }
    else if (iVar2 == 0) {
      puVar3 = &DAT_001fa5f8;
    }
    else if (iVar2 == 2) {
      puVar3 = &DAT_001dbcf4;
    }
    else if (iVar2 == 3) {
      puVar3 = &DAT_001dbcd4;
    }
    else {
      puVar3 = &DAT_001dbd14;
    }
  }
  iVar2 = ffvpAllocTempRegister(param_1,2,param_1 + 0x584);
  if (iVar2 == 0) {
    uVar7 = *(undefined4 *)(param_1 + 0x588);
    iVar2 = ffvpAllocTempRegister(param_1,2,auStack_a8);
    uVar1 = local_a4;
    if (iVar2 == 0) {
      iVar8 = *(int *)(param_1 + 0x3d4);
      iVar2 = *(int *)(*(int *)(iVar8 + 4) + 0x10);
      if ((*(short *)(((unsigned char *)0x00002e06) + iVar2) == -0x7bae) &&
         (*(short *)(((unsigned char *)0x00002e08) + iVar2) != -0x7aa4)) {
        if (*(short *)(((unsigned char *)0x00002e08) + iVar2) == -0x7aa5) {
          uVar5 = **(undefined4 **)(param_1 + 0x3f0);
          uVar6 = **(undefined4 **)(param_1 + 0x3ec);
          iVar2 = ffvpAllocTempRegister(param_1,1,auStack_80);
          if (iVar2 != 0) {
            return 7;
          }
          (**(code **)(((unsigned char *)0x000012e4) + iVar8))
                    (param_1,uVar5,local_7c,&DAT_001dbd04,uVar9,iVar4,&DAT_001dbd74,&DAT_001fa5e8,uVar9,iVar4,&DAT_001dbd74,&DAT_001fa5e8);
          (**(code **)(((unsigned char *)0x00001318) + iVar8))
                    (param_1,uVar5,local_7c,&DAT_001dbd64,uVar6,local_7c,&DAT_001fa5f8,&DAT_001fa5e8
                    );
          iVarS1 = ((unsigned char *)&DAT_001dbdc0 + 244);
          (**(code **)(((unsigned char *)0x000012e4) + iVar8))
                    (param_1,a1,uVar1,auStack_a0,uVar6,local_7c,&DAT_001dbec4,&DAT_001fa5e8,uVar6,local_7c,iVarS1,&DAT_001fa5e8);
          FUN_000911a0(param_1,auStack_80);
        }
        else {
          (**(code **)(((unsigned char *)0x000012e8) + iVar8))
                    (param_1,a1,local_a4,auStack_a0,uVar9,iVar4,puVar3,&DAT_001dbd94);
        }
      }
      else {
        iVarS4 = &DAT_001dbd94;
        (**(code **)(((unsigned char *)0x00001304) + iVar8))
                  (param_1,a1,local_a4,auStack_a0,uVar9,iVar4,puVar3,&DAT_001fa5e8,uVar9,iVar4,puVar3,iVarS4);
      }
      uVar9 = **(undefined4 **)(param_1 + 0x3ec);
      iVarS2 = *(int *)((int)*(int *)((int)param_1 + 1004) + 0);
      iVarS3 = &auStack_90;
      (**(code **)(((unsigned char *)0x000012ec) + iVar10))
                (param_1,a1,local_a4,auStack_a0,a4,a5,&DAT_001dbcf4,&DAT_001fa5e8,iVarS2,local_a4,iVarS3,&DAT_001fa5e8);
      if (*(int *)(param_1 + 0x3d8) == 0) {
        puVar3 = (undefined4 *)(param_1 + 0x58c);
        if (-1 < *(int *)(iVar10 + 0x44)) {
          uVar7 = *(undefined4 *)(param_1 + 0x70);
          puVar3 = &DAT_001dbd44;
          a1 = *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x18);
        }
      }
      else {
        uVar7 = *(undefined4 *)(param_1 + 0x70);
        puVar3 = &DAT_001dbd04;
        a1 = *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x18);
      }
      (**(code **)(((unsigned char *)0x00001320) + iVar10))
                (param_1,a1,uVar7,puVar3,uVar9,local_a4,auStack_90,&DAT_001fa5e8);
      FUN_000911a0(param_1,auStack_a8);
      return 0;
    }
  }
  return 7;
}

/* FUN_0009b430 @ 0x9b430 (848 bytes) */
int FUN_0009b430(param_1, param_2)
  int param_1;
  int param_2;
{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint loopIndex;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  undefined *puVar13;
  undefined4 uVar14;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  int local_74;
  undefined *local_68;
  undefined *local_64;
  undefined4 *local_60;
  undefined *local_5c;
  int iVarS1;
  int iVarS2;
  int iVarS3;
  int iVarS4;
  int iVarS5;
  
  uVar3 = 1;
  if (param_1 != 0) {
    iVar11 = *(int *)(param_1 + 0x3d4);
    local_60 = &local_80;
    loopIndex = 0;
    uVar3 = **(undefined4 **)(param_1 + 0x3ec);
    iVar6 = *(int *)(*(int *)(iVar11 + 4) + 0x10);
    local_68 = &DAT_001db440;
    local_64 = &DAT_001db440;
    local_5c = &DAT_001db440;
    iVar8 = param_1;
    iVar9 = iVar11;
    iVar10 = param_1;
    do {
      uVar12 = *(undefined4 *)(iVar10 + 0x5b0);
      uVar7 = *(undefined4 *)(iVar10 + 0x600);
      uVar14 = *(undefined4 *)(iVar8 + 0x74);
      FUN_000912f0(param_1,*(undefined4 *)(iVar9 + 0x280),2,&local_88,&local_84);
      local_80 = 5;
      local_7c = 5;
      local_78 = 5;
      local_74 = 3;
      if (param_2 == 0) {
        iVarS1 = local_88;
        iVarS2 = local_84;
        iVarS3 = local_60;
        (**(code **)(((unsigned char *)0x000012ec) + iVar11))
                  (param_1,*(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0xc),uVar14,local_68 + 0x8e4,
                   uVar3,uVar12,local_64 + 0x984,&DAT_001fa5e8,iVarS1,iVarS2,iVarS3,&DAT_001fa5e8);
      }
      if ((((*(short *)(((unsigned char *)0x00002d48) + iVar6) == -0x7e06) && (*(char *)(iVar11 + 0x12d) != '\0')
           ) || (((*(uint *)(iVar11 + 0x44) & 0x1000000) != 0 && (*(char *)(iVar11 + 0x121) == '\0')
                 ))) || ((*(uint *)(iVar11 + 0x44) & 0xa10000) != 0)) {
        iVar4 = *(int *)(iVar8 + 0x7c);
        uVar12 = *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x10);
        FUN_000912f0(param_1,*(undefined4 *)(iVar9 + 0x288),3,&local_88,&local_84);
        if (((*(short *)(((unsigned char *)0x00002d48) + iVar6) != -0x7e06) ||
            (*(char *)(iVar11 + 0x12d) == '\0')) || (param_2 == 0)) {
          puVar13 = local_5c + 0x964;
          uVar7 = local_84;
          uVar14 = local_88;
        }
        else {
          puVar13 = local_64 + 0x984;
          uVar14 = uVar3;
        }
        /* stack words 9/10 of the last call: the stock (0x9b6fc/0x9b708) passes (local_88, local_84) unless the two arms below replace them */
        iVarS4 = local_88;
        iVarS5 = local_84;
        if ((((*(uint *)(iVar11 + 0x44) & 0x1000000) != 0) && (*(char *)(iVar11 + 0x121) == '\0'))
           && ((*(int *)(param_1 + 0x3d8) == 0 && (iVar4 == *(int *)(param_1 + 0x70))))) {
          if (*(char *)(iVar11 + 0x12e) == '\0') {
            if (*(int *)(param_1 + 0x588) == -1) {
              sVar1 = *(short *)(((unsigned char *)0x00002e04) + iVar6);
              if (sVar1 == 0x801) {
                FUN_000928a0(param_1);
                iVar2 = *(int *)(param_1 + 0x588);
              }
              else if (sVar1 == 0x2601) {
                ((int (*)())FUN_0009aa00)(param_1);
                iVar2 = *(int *)(param_1 + 0x588);
              }
              else {
                if (sVar1 != 0x800) {
                  return 2;
                }
                ((int (*)())FUN_0009afc0)(param_1);
                iVar2 = *(int *)(param_1 + 0x588);
              }
              if (iVar2 == -1) {
                return 2;
              }
            }
            local_74 = *(int *)(param_1 + 0x5a8);
            iVarS4 = uVar3;
            iVarS5 = *(int *)(param_1 + 0x588);
          }
          else {
            iVarS4 = (*(int **)(param_1 + 0x3ec))[1];
            iVarS5 = *(int *)(param_1 + 0x50);
            local_74 = *(int *)(param_1 + 0x54);
            if (local_74 != 1) {
              if (local_74 == 0) {
                local_74 = 0;
              }
              else if ((local_74 != 2) && (local_74 != 3)) {
                local_74 = 3;
              }
            }
          }
        }
        (**(code **)(((unsigned char *)0x000012ec) + iVar11))
                  (param_1,uVar12,iVar4,local_68 + 0x8e4,uVar14,uVar7,puVar13,&DAT_001fa5e8,iVarS4,iVarS5,local_60,&DAT_001fa5e8);
      }
      loopIndex = loopIndex + 1;
      iVar10 = iVar10 + 0x28;
      iVar8 = iVar8 + 4;
      iVar9 = iVar9 + 4;
    } while (loopIndex <= (byte)((unsigned char *)0x00002d48)[iVar6 + 4]);
    uVar3 = 0;
  }
  return uVar3;
}

/* FUN_0009b790 @ 0x9b790 (172 bytes) */
int FUN_0009b790(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  
  if ((*(int *)(param_1 + 0x330) == -1) || (iVar2 = *(int *)(param_1 + 0x70), iVar2 == -1)) {
    return 2;
  }
  if (*(short *)(((unsigned char *)0x00002e06) + *(int *)(*(int *)(*(int *)(param_1 + 0x3d4) + 4) + 0x10)) ==
      -0x7baf) {
    if (*(int *)(param_1 + 0x50) == -1) {
      return 2;
    }
    if (3 < *(uint *)(param_1 + 0x54)) {
      return 3;
    }
  }
  if ((((*(int *)(param_1 + 0x3d8) == 0) && (iVar2 != *(int *)(param_1 + 0x74))) &&
      (iVar2 != *(int *)(param_1 + 0x78))) &&
     ((iVar2 != *(int *)(param_1 + 0x7c) && (iVar2 != *(int *)(param_1 + 0x80))))) {
    return 3;
  }
  *(undefined1 *)(*(int *)(param_1 + 0x3d4) + 0x12e) = 0;
  uVar1 = ((int (*)())FUN_0009afc0)(param_1);
  return uVar1;
}

/* FUN_0009b850 @ 0x9b850 (892 bytes) */
int FUN_0009b850(param_1, param_2)
  int param_1;
  uint param_2;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  uint local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined1 auStack_68 [4];
  undefined4 local_64;
  int iVarS1;
  int iVarS2;
  
  if (param_1 == 0) {
    return 1;
  }
  if (param_2 < 8) {
    iVar7 = *(int *)(param_2 * 4 + param_1 + 0x84);
    if (iVar7 != -1) {
      iVar8 = *(int *)(param_1 + 0x3d4);
      uVar6 = *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x14);
      local_74 = DAT_001dbda8;
      local_78 = DAT_001dbda4;
      local_70 = DAT_001dbdac;
      local_6c = DAT_001dbdb0;
      if (*(short *)(((unsigned char *)0x00002e06) + *(int *)(*(int *)(iVar8 + 4) + 0x10)) == -0x7bae) {
        iVar5 = *(int *)(param_1 + 0x3f8);
        if (iVar5 != -1) {
LAB_0009b914:
          uVar4 = **(undefined4 **)(param_1 + 0x3ec);
          local_78 = 2;
          iVar1 = *(int *)(*(int *)(iVar8 + 4) + 0x10);
          if (*(short *)(((unsigned char *)0x00002e06) + iVar1) != -0x7bae) {
            iVarS2 = &DAT_001dbd94;
            (**(code **)(((unsigned char *)0x00001304) + iVar8))
                      (param_1,uVar6,iVar7,&DAT_001dbd24,uVar4,iVar5,&local_78,&DAT_001fa5e8,uVar4,iVar5,&local_78,iVarS2);
            return 0;
          }
          if (*(short *)(((unsigned char *)0x00002e08) + iVar1) == -0x7aa5) {
            uVar3 = **(undefined4 **)(param_1 + 0x3ec);
            uVar2 = **(undefined4 **)(param_1 + 0x3f0);
            iVar1 = ffvpAllocTempRegister(param_1,1,auStack_68);
            if (iVar1 != 0) {
              return 7;
            }
            (**(code **)(((unsigned char *)0x000012e4) + iVar8))
                      (param_1,uVar2,local_64,&DAT_001dbd04,uVar4,iVar5,&DAT_001dbd74,&DAT_001fa5e8,uVar4,iVar5,&DAT_001dbd74,&DAT_001fa5e8)
            ;
            (**(code **)(((unsigned char *)0x00001318) + iVar8))
                      (param_1,uVar2,local_64,&DAT_001dbd64,uVar3,local_64,&DAT_001fa5f8,
                       &DAT_001fa5e8);
            iVarS1 = ((unsigned char *)&DAT_001dbdc0 + 244);
            (**(code **)(((unsigned char *)0x000012e4) + iVar8))
                      (param_1,uVar6,iVar7,&DAT_001dbd24,uVar3,local_64,&DAT_001dbec4,&DAT_001fa5e8,uVar3,local_64,iVarS1,&DAT_001fa5e8)
            ;
            FUN_000911a0(param_1,auStack_68);
            return 0;
          }
          (**(code **)(((unsigned char *)0x000012e8) + iVar8))
                    (param_1,uVar6,iVar7,&DAT_001dbd24,uVar4,iVar5,&local_78,&DAT_001dbd94);
          return 0;
        }
        if ((*(uint *)(((unsigned char *)0x000013c0) + iVar8) & 4) == 0) {
          FUN_000916d0(param_1);
        }
        else {
          FUN_000914e0(param_1);
        }
        iVar5 = *(int *)(param_1 + 0x3f8);
        if (iVar5 != -1) {
          iVar8 = *(int *)(param_1 + 0x3d4);
          goto LAB_0009b914;
        }
      }
      else if (*(int *)(param_1 + 0x50) != -1) {
        local_78 = *(uint *)(param_1 + 0x54);
        if (local_78 < 4) {
          if (local_78 != 1) {
            if (local_78 == 0) {
              local_78 = 0;
            }
            else if ((local_78 != 2) && (local_78 != 3)) {
              local_78 = 4;
            }
          }
          (**(code **)(((unsigned char *)0x000012e8) + iVar8))
                    (param_1,uVar6,iVar7,&DAT_001dbd24,
                     *(undefined4 *)(*(int *)(param_1 + 0x3ec) + 4),*(int *)(param_1 + 0x50),
                     &local_78,&DAT_001fa5e8);
          return 0;
        }
        goto LAB_0009bbb0;
      }
    }
    uVar6 = 2;
  }
  else {
LAB_0009bbb0:
    uVar6 = 3;
  }
  return uVar6;
}

/* FUN_0009bbf0 @ 0x9bbf0 (28 bytes) */
int FUN_0009bbf0(param_1, param_2, param_3)
  int param_1;
  undefined8 *param_2;
  int param_3;
{
  undefined8 uVar1;
  
  uVar1 = param_2[1];
  *(undefined8 *)(param_3 * 0x10 + param_1) = *param_2;
  *(undefined8 *)(param_3 * 0x10 + param_1 + 8) = uVar1;
  return;
}

/* FUN_0009bc10 @ 0x9bc10 (228 bytes) */
int FUN_0009bc10(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  undefined4 *param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  
  iVar1 = param_4 * 0x10;
  uVar9 = param_3[0xf];
  uVar5 = param_3[1];
  uVar16 = param_3[2];
  iVar2 = iVar1 + param_2;
  uVar13 = param_3[3];
  uVar7 = param_3[4];
  uVar3 = param_3[5];
  uVar15 = param_3[6];
  uVar12 = param_3[7];
  uVar8 = param_3[8];
  uVar10 = param_3[9];
  uVar14 = param_3[10];
  uVar11 = param_3[0xb];
  uVar6 = param_3[0xc];
  uVar17 = param_3[0xd];
  uVar4 = param_3[0xe];
  if (param_1 == 0) {
    *(undefined4 *)(iVar1 + param_2) = *param_3;
    *(undefined4 *)(iVar2 + 0x3c) = uVar9;
    *(undefined4 *)(iVar2 + 4) = uVar7;
    *(undefined4 *)(iVar2 + 8) = uVar8;
    *(undefined4 *)(iVar2 + 0xc) = uVar6;
    *(undefined4 *)(iVar2 + 0x10) = uVar5;
    *(undefined4 *)(iVar2 + 0x14) = uVar3;
    *(undefined4 *)(iVar2 + 0x18) = uVar10;
    *(undefined4 *)(iVar2 + 0x1c) = uVar17;
    *(undefined4 *)(iVar2 + 0x20) = uVar16;
    *(undefined4 *)(iVar2 + 0x24) = uVar15;
    *(undefined4 *)(iVar2 + 0x28) = uVar14;
    *(undefined4 *)(iVar2 + 0x2c) = uVar4;
    *(undefined4 *)(iVar2 + 0x30) = uVar13;
    *(undefined4 *)(iVar2 + 0x34) = uVar12;
    *(undefined4 *)(iVar2 + 0x38) = uVar11;
  }
  else {
    *(undefined4 *)(iVar1 + param_2) = *param_3;
    *(undefined4 *)(iVar2 + 0x3c) = uVar9;
    *(undefined4 *)(iVar2 + 4) = uVar5;
    *(undefined4 *)(iVar2 + 8) = uVar16;
    *(undefined4 *)(iVar2 + 0xc) = uVar13;
    *(undefined4 *)(iVar2 + 0x10) = uVar7;
    *(undefined4 *)(iVar2 + 0x14) = uVar3;
    *(undefined4 *)(iVar2 + 0x18) = uVar15;
    *(undefined4 *)(iVar2 + 0x1c) = uVar12;
    *(undefined4 *)(iVar2 + 0x20) = uVar8;
    *(undefined4 *)(iVar2 + 0x24) = uVar10;
    *(undefined4 *)(iVar2 + 0x28) = uVar14;
    *(undefined4 *)(iVar2 + 0x2c) = uVar11;
    *(undefined4 *)(iVar2 + 0x30) = uVar6;
    *(undefined4 *)(iVar2 + 0x34) = uVar17;
    *(undefined4 *)(iVar2 + 0x38) = uVar4;
  }
  return;
}

/* FUN_0009bd00 @ 0x9bd00 (96 bytes) */
int FUN_0009bd00(param_1)
  int param_1;
{
  ushort uVar1;
  int *piVar2;
  
  uVar1 = *(ushort *)(((unsigned char *)0x000013be) + param_1);
  piVar2 = (int *)(**(code **)(param_1 + 0xc))((uint)uVar1 * 8 + 0xc);
  piVar2[2] = 0;
  *piVar2 = (int)(piVar2 + 3);
  piVar2[1] = (int)(piVar2 + 3 + uVar1);
  return piVar2;
}

/* FUN_0009bd60 @ 0x9bd60 (160 bytes) */
int FUN_0009bd60(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  int iVar2;
  
  *(undefined1 *)(param_1 + 0x131) = (undefined1)param_2;
  *(undefined1 *)(param_1 + 0x12f) = 0;
  *(undefined4 *)(param_1 + 0x14c) = 0;
  *(undefined1 *)(param_1 + 0x125) = 0;
  *(undefined1 *)(param_1 + 0x124) = 0;
  *(undefined4 *)(param_1 + 0x13c) = 0;
  *(undefined4 *)(param_1 + 0x148) = 0;
  *(undefined1 *)(param_1 + 0x12d) = 0;
  *(code **)(((unsigned char *)0x000012cc) + param_1) = FUN_0009bbf0;
  *(code **)(((unsigned char *)0x000012c8) + param_1) = FUN_0009bc10;
  iVar2 = 8;
  iVar1 = param_1;
  do {
    *(undefined4 *)(iVar1 + 0x150) = 0;
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  iVar1 = param_1 + 0x3a0;
  iVar2 = 8;
  do {
    *(uint *)(iVar1 + 8) = *(uint *)(iVar1 + 8) & 0xffffff;
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined1 *)(param_1 + 299) = 0;
  *(undefined1 *)(param_1 + 0x126) = 0;
  return;
}

/* FUN_0009be00 @ 0x9be00 (2216 bytes) */
int FUN_0009be00(param_1)
  int param_1;
{
  char cVar1;
  char cVar2;
  char cVar3;
  float fVar4;
  float fVar5;
  bool bVar6;
  float fVar7;
  undefined4 uVar8;
  char cVar9;
  undefined1 uVar11;
  int iVar10;
  byte bVar12;
  int iVar13;
  undefined4 *puVar14;
  int iVar15;
  int iVar16;
  uint *puVar17;
  undefined4 uVar18;
  int iVar19;
  undefined4 uVar20;
  uint uVar21;
  uint *puVar22;
  uint uVar23;
  bool bVar24;
  int iVar25;
  byte *pbVar26;
  int iVar27;
  int iVar28;
  
  iVar16 = param_1 + 0x124;
  cVar1 = *(char *)(param_1 + 0x12f);
  iVar28 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  cVar9 = *(char *)(iVar28 + 0x24ad);
  cVar2 = *(char *)(iVar28 + 0x24ae);
  if (-1 < *(int *)(param_1 + 0x44)) {
    if ((*(uint *)(param_1 + 0x8c) & 0xc000000) != 0) {
      *(char *)(param_1 + 300) = cVar2;
      return;
    }
    *(undefined1 *)(param_1 + 300) = 0;
    return;
  }
  puVar22 = (uint *)(param_1 + 0x1874);
  cVar3 = ((unsigned char *)0x00002d48)[iVar28 + 5];
  bVar24 = *(short *)(((unsigned char *)0x00002d48) + iVar28) == -0x7e06;
  uVar23 = (uint)bVar24;
  uVar8 = *(undefined4 *)
           (&DAT_001dbed4 +
           (uint)(byte)((unsigned char *)0x00002d48)[iVar28 + 3] *
           ((*(ushort *)(((unsigned char *)0x00002d44) + iVar28) & 1 | *(ushort *)(((unsigned char *)0x00002d44) + iVar28) >> 2 & 2)
           + ((*(ushort *)(((unsigned char *)0x00002d46) + iVar28) >> 8 & 4) +
             (*(ushort *)(((unsigned char *)0x00002d46) + iVar28) & 0xf)) * 3 + 1) * 4);
  *(undefined4 *)(param_1 + 0x26c) = uVar8;
  if (*(int *)(param_1 + 0x13c) != 1) {
    uVar8 = 0;
  }
  *(undefined4 *)(param_1 + 0x1890) = uVar8;
  *(undefined1 *)(param_1 + 0x12f) = 0;
  if ((cVar3 != '\0') && (cVar2 == '\0')) {
    *(undefined1 *)(param_1 + 300) = 0;
    if ((*(uint *)(param_1 + 0x40) & 0x10000) != 0) {
      uVar21 = (uint)(byte)((unsigned char *)0x000013b5)[param_1];
      if (uVar21 != 0) {
        iVar15 = param_1;
        if ((uVar21 == 0) || (uVar21 == 0x80000000)) {
          uVar21 = 1;
        }
        do {
          *(byte *)(iVar15 + 0x1814) = *(byte *)(iVar15 + 0x1814) | 0x18;
          iVar15 = iVar15 + 1;
          uVar21 = uVar21 - 1;
        } while (uVar21 != 0);
      }
    }
    goto LAB_0009bfa0;
  }
  if (((*(uint *)(param_1 + 0x8c) >> 0x1a & 1) != 0 || (*(uint *)(param_1 + 0x8c) >> 0x1b & 1) != 0)
     && ((*(uint *)(param_1 + 0x40) & 0x10000) != 0)) {
    uVar21 = (uint)(byte)((unsigned char *)0x000013b5)[param_1];
    if (uVar21 != 0) {
      iVar15 = param_1;
      if ((uVar21 == 0) || (uVar21 == 0x80000000)) {
        uVar21 = 1;
      }
      do {
        *(byte *)(iVar15 + 0x1814) = *(byte *)(iVar15 + 0x1814) | 0x18;
        iVar15 = iVar15 + 1;
        uVar21 = uVar21 - 1;
      } while (uVar21 != 0);
    }
  }
  if ((cVar2 == '\0') || (cVar9 != '\0')) {
    cVar9 = *(char *)(param_1 + 0x12f);
LAB_0009bf34:
    uVar11 = 0;
  }
  else {
    cVar9 = *(char *)(param_1 + 0x12f);
    uVar11 = 1;
    if (cVar9 != '\0') goto LAB_0009bf34;
  }
  *(undefined1 *)(param_1 + 300) = uVar11;
  if (cVar1 != cVar9) {
    uVar21 = (uint)(byte)((unsigned char *)0x000013b5)[param_1];
    if (uVar21 != 0) {
      iVar15 = param_1;
      if ((uVar21 == 0) || (uVar21 == 0x80000000)) {
        uVar21 = 1;
      }
      do {
        *(byte *)(iVar15 + 0x1814) = *(byte *)(iVar15 + 0x1814) | 0x18;
        iVar15 = iVar15 + 1;
        uVar21 = uVar21 - 1;
      } while (uVar21 != 0);
    }
  }
LAB_0009bfa0:
  if ((*(uint *)(param_1 + 0x180c) & 1) != 0) {
    *(uint *)(param_1 + 0x180c) = *(uint *)(param_1 + 0x180c) & 0xfffffffe;
  }
  fVar7 = FLOAT_001aa0e8;
  uVar21 = *(uint *)(param_1 + 0x88);
  if (uVar21 != 0) {
    iVar27 = 0;
    bVar6 = false;
    iVar25 = 0;
    iVar15 = param_1;
    puVar17 = puVar22;
    iVar19 = iVar16;
    do {
      if ((uVar21 & 1) != 0) {
        pbVar26 = (byte *)(iVar15 + 0x1814);
        iVar13 = iVar27 * 0x80 + iVar28 + 0x24c0;
        puVar14 = (undefined4 *)(((unsigned char *)0x000014a4) + iVar25 + param_1);
        if (*(byte *)(iVar15 + 0x1814) != 0) {
          if ((*(byte *)(iVar15 + 0x1814) & 1) != 0) {
            fVar5 = *(float *)(iVar27 * 0x80 + iVar28 + 0x24c0);
            if (((fVar5 == FLOAT_001aa0d4) && (*(float *)(iVar13 + 4) == FLOAT_001aa0d4)) &&
               (*(float *)(iVar13 + 8) == FLOAT_001aa0d4)) {
              iVar10 = iVar27 * 4 + iVar16;
              *(uint *)(iVar10 + 0x284) = *(uint *)(iVar10 + 0x284) & 0x3fffffff;
              *(ushort *)(puVar17 + 8) = *(ushort *)(puVar17 + 8) & 0x9fff;
            }
            else if (((fVar5 == FLOAT_001aa0e8) && (*(float *)(iVar13 + 4) == FLOAT_001aa0e8)) &&
                    (*(float *)(iVar13 + 8) == FLOAT_001aa0e8)) {
              iVar10 = iVar27 * 4 + iVar16;
              *(uint *)(iVar10 + 0x284) = *(uint *)(iVar10 + 0x284) & 0x3fffffff | 0x40000000;
              *(ushort *)(puVar17 + 8) = *(ushort *)(puVar17 + 8) & 0x9fff | 0x2000;
            }
            else if (((*(float *)(iVar13 + 0x50) == fVar7) &&
                     (*(float *)(iVar13 + 0x54) == FLOAT_001aa0d4)) &&
                    ((*(float *)(iVar13 + 0x58) == FLOAT_001aa0d4 &&
                     (*(char *)(puVar14 + 0x1a) == '\0')))) {
              bVar6 = true;
              iVar10 = iVar27 * 4 + iVar16;
              *(uint *)(iVar10 + 0x284) = *(uint *)(iVar10 + 0x284) & 0x3fffffff | 0xc0000000;
              *(ushort *)(puVar17 + 8) = *(ushort *)(puVar17 + 8) | 0x6000;
            }
            else {
              iVar10 = iVar27 * 4 + iVar16;
              *(uint *)(iVar10 + 0x284) = *(uint *)(iVar10 + 0x284) & 0x3fffffff | 0x80000000;
              *(ushort *)(puVar17 + 8) = *(ushort *)(puVar17 + 8) & 0x9fff | 0x4000;
            }
          }
          iVar10 = iVar27 * 4;
          bVar12 = *pbVar26;
          if ((bVar12 & 2) != 0) {
            if (((*(float *)(iVar13 + 0x10) == FLOAT_001aa0d4) &&
                (*(float *)(iVar13 + 0x14) == FLOAT_001aa0d4)) &&
               (*(float *)(iVar13 + 0x18) == FLOAT_001aa0d4)) {
              *(uint *)(iVar10 + iVar16 + 0x284) = *(uint *)(iVar10 + iVar16 + 0x284) & 0xcfffffff;
              *(ushort *)(puVar17 + 8) = *(ushort *)(puVar17 + 8) & 0xe7ff;
              bVar12 = *pbVar26;
            }
            else if (((*(float *)(iVar13 + 0x10) == FLOAT_001aa0e8) &&
                     (*(float *)(iVar13 + 0x14) == FLOAT_001aa0e8)) &&
                    (*(float *)(iVar13 + 0x18) == FLOAT_001aa0e8)) {
              *(uint *)(iVar10 + iVar16 + 0x284) =
                   *(uint *)(iVar10 + iVar16 + 0x284) & 0xcfffffff | 0x10000000;
              *(ushort *)(puVar17 + 8) = *(ushort *)(puVar17 + 8) & 0xe7ff | 0x800;
              bVar12 = *pbVar26;
            }
            else {
              *(uint *)(iVar10 + iVar16 + 0x284) =
                   *(uint *)(iVar10 + iVar16 + 0x284) & 0xcfffffff | 0x20000000;
              *(ushort *)(puVar17 + 8) = *(ushort *)(puVar17 + 8) & 0xe7ff | 0x1000;
              bVar12 = *pbVar26;
            }
          }
          if ((bVar12 & 4) != 0) {
            if (((*(float *)(iVar13 + 0x20) == FLOAT_001aa0d4) &&
                (*(float *)(iVar13 + 0x24) == FLOAT_001aa0d4)) &&
               (*(float *)(iVar13 + 0x28) == FLOAT_001aa0d4)) {
              *(uint *)(iVar10 + iVar16 + 0x284) = *(uint *)(iVar10 + iVar16 + 0x284) & 0xf3ffffff;
              *(ushort *)(puVar17 + 8) = *(ushort *)(puVar17 + 8) & 63999;
              bVar12 = *pbVar26;
            }
            else if (((*(float *)(iVar13 + 0x20) == FLOAT_001aa0e8) &&
                     (*(float *)(iVar13 + 0x24) == FLOAT_001aa0e8)) &&
                    (*(float *)(iVar13 + 0x28) == FLOAT_001aa0e8)) {
              *(uint *)(iVar10 + iVar16 + 0x284) =
                   *(uint *)(iVar10 + iVar16 + 0x284) & 0xf3ffffff | 0x4000000;
              *(ushort *)(puVar17 + 8) = *(ushort *)(puVar17 + 8) & 63999 | 0x200;
              bVar12 = *pbVar26;
            }
            else {
              *(uint *)(iVar10 + iVar16 + 0x284) =
                   *(uint *)(iVar10 + iVar16 + 0x284) & 0xf3ffffff | 0x8000000;
              *(ushort *)(puVar17 + 8) = *(ushort *)(puVar17 + 8) & 63999 | 0x400;
              bVar12 = *pbVar26;
            }
          }
          if ((bVar12 & 0x20) != 0) {
            if ((*(float *)(iVar13 + 0x54) == FLOAT_001aa0d4) &&
               (*(float *)(iVar13 + 0x58) == FLOAT_001aa0d4)) {
              if ((*(float *)(iVar13 + 0x50) == fVar7) ||
                 (*(float *)(iVar13 + 0x50) == FLOAT_001aa0d4)) {
                *(uint *)(iVar10 + iVar16 + 0x284) = *(uint *)(iVar10 + iVar16 + 0x284) & 0xfcffffff
                ;
                *(ushort *)(puVar17 + 8) = *(ushort *)(puVar17 + 8) & 0xffe7;
              }
              else {
                *(uint *)(iVar10 + iVar16 + 0x284) = *(uint *)(iVar10 + iVar16 + 0x284) | 0x3000000;
                *(ushort *)(puVar17 + 8) = *(ushort *)(puVar17 + 8) | 0x18;
                *(byte *)(iVar15 + 0x181c) = *(byte *)(iVar15 + 0x181c) | 4;
              }
            }
            else {
              *(uint *)(iVar10 + iVar16 + 0x284) =
                   *(uint *)(iVar10 + iVar16 + 0x284) & 0xfeffffff | 0x2000000;
              *(ushort *)(puVar17 + 8) = *(ushort *)(puVar17 + 8) & 0xfff7 | 0x10;
            }
          }
          if (*(float *)(iVar13 + 0x3c) == FLOAT_001aa0d4) {
            if (*(char *)(param_1 + 0x12f) == '\0') {
              uVar8 = puVar14[0x15];
              uVar18 = puVar14[0x16];
              uVar20 = puVar14[0x17];
              *(undefined4 *)(iVar19 + 0x174) = puVar14[0x14];
              *(undefined4 *)(iVar19 + 0x178) = uVar8;
              *(undefined4 *)(iVar19 + 0x17c) = uVar18;
              *(undefined4 *)(iVar19 + 0x180) = uVar20;
              uVar8 = puVar14[0x10];
              uVar18 = puVar14[0x11];
              uVar20 = puVar14[0x12];
              *(undefined4 *)(iVar19 + 0x200) = puVar14[0x13];
              *(undefined4 *)(iVar19 + 500) = uVar8;
              *(undefined4 *)(iVar19 + 0x1f8) = uVar18;
              *(undefined4 *)(iVar19 + 0x1fc) = uVar20;
            }
            else {
              uVar8 = puVar14[0xd];
              uVar18 = puVar14[0xe];
              uVar20 = puVar14[0xf];
              *(undefined4 *)(iVar19 + 0x174) = puVar14[0xc];
              *(undefined4 *)(iVar19 + 0x178) = uVar8;
              *(undefined4 *)(iVar19 + 0x17c) = uVar18;
              *(undefined4 *)(iVar19 + 0x180) = uVar20;
              uVar8 = puVar14[8];
              uVar18 = puVar14[9];
              uVar20 = puVar14[10];
              *(undefined4 *)(iVar19 + 0x200) = puVar14[0xb];
              *(undefined4 *)(iVar19 + 500) = uVar8;
              *(undefined4 *)(iVar19 + 0x1f8) = uVar18;
              *(undefined4 *)(iVar19 + 0x1fc) = uVar20;
            }
          }
          else {
            uVar8 = *puVar14;
            uVar18 = puVar14[2];
            uVar20 = puVar14[3];
            *(undefined4 *)(iVar19 + 0x178) = puVar14[1];
            *(undefined4 *)(iVar19 + 0x174) = uVar8;
            *(undefined4 *)(iVar19 + 0x17c) = uVar18;
            *(undefined4 *)(iVar19 + 0x180) = uVar20;
            fVar5 = GH_U2F((unsigned int)(puVar14[4]));
            fVar4 = GH_U2F((unsigned int)(puVar14[5]));
            *(float *)(iVar19 + 0x1fc) = -GH_U2F((unsigned int)(puVar14[6]));
            *(float *)(iVar19 + 500) = -fVar5;
            *(float *)(iVar19 + 0x1f8) = -fVar4;
            *(uint *)(iVar10 + iVar16 + 0x284) =
                 (uint)(*(float *)(iVar13 + 0x3c) == fVar7) << 0x17 |
                 *(uint *)(iVar10 + iVar16 + 0x284) & 0xff7fffff;
          }
          *pbVar26 = 0;
        }
        if (*(char *)(iVar15 + 0x181c) != '\0') {
          *(undefined1 *)(iVar15 + 0x181c) = 0;
        }
        uVar23 = uVar23 | -(uint)(*(uint *)(iVar27 * 4 + iVar16 + 0x284) >> 0x1a & 3) >> 0x1f;
      }
      bVar24 = SUB41(uVar23,0);
      uVar21 = uVar21 >> 1;
      iVar27 = iVar27 + 1;
      iVar25 = iVar25 + 0x6c;
      puVar17 = (uint *)((int)puVar17 + 2);
      iVar15 = iVar15 + 1;
      iVar19 = iVar19 + 0x10;
    } while (uVar21 != 0);
    if (bVar6) {
      *(undefined4 *)(param_1 + 0x3a0) = 0;
      *(undefined4 *)(param_1 + 0x398) = 0;
      *(undefined4 *)(param_1 + 0x39c) = 0;
      *puVar22 = *puVar22 | 4;
      uVar23 = *(uint *)(param_1 + 0x88);
      if (uVar23 != 0) {
        iVar16 = 0x24c0;
        puVar22 = (uint *)(param_1 + 0x3a8);
        do {
          if (((uVar23 & 1) != 0) && (*puVar22 >> 0x1e == 3)) {
            *(float *)(param_1 + 0x398) = *(float *)(param_1 + 0x398) + *(float *)(iVar28 + iVar16);
            *(float *)(param_1 + 0x39c) =
                 *(float *)(param_1 + 0x39c) + *(float *)(iVar28 + iVar16 + 4);
            *(float *)(param_1 + 0x3a0) =
                 *(float *)(param_1 + 0x3a0) + *(float *)(iVar28 + iVar16 + 8);
          }
          uVar23 = uVar23 >> 1;
          puVar22 = puVar22 + 1;
          iVar16 = iVar16 + 0x80;
        } while (uVar23 != 0);
      }
    }
  }
  *(bool *)(param_1 + 0x12d) = bVar24;
  return;
}

/* fpVariantCacheFlush @ 0x9c700 (248 bytes) */
int fpVariantCacheFlush(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  undefined4 a1;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  uint loopIndex;
  int a0;
  
  loopIndex = 0;
  if (*(int *)(((unsigned char *)0x0000111c) + param_1) != 0) {
    do {
      iVar2 = *(int *)(((unsigned char *)0x00001118) + param_1);
      iVar1 = loopIndex * 4;
      a0 = *(int *)(iVar1 + iVar2);
      while (a0 != 0) {
        *(undefined4 *)(iVar1 + iVar2) = *(undefined4 *)(a0 + 0x5c);
        ((int (*)())fpVariantProgramFree)(param_1,*(undefined4 *)(a0 + 0x54));
        if (*(int *)(a0 + 0x4c) != 0) {
          (**(code **)(param_1 + 0x18))(*(int *)(a0 + 0x4c));
        }
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(a0 + 0x50));
        (**(code **)(param_1 + 0x18))(a0,a1,in_r5,in_r6,in_r7,in_r8,*(code **)(param_1 + 0x18));
        iVar2 = *(int *)(((unsigned char *)0x00001118) + param_1);
        a0 = *(int *)(iVar1 + iVar2);
      }
      loopIndex = loopIndex + 1;
      *(undefined4 *)(iVar1 + iVar2) = 0;
    } while (loopIndex < *(uint *)(((unsigned char *)0x0000111c) + param_1));
  }
  *(undefined4 *)(((unsigned char *)0x0000148c) + param_1) = 0;
  *(undefined4 *)(param_1 + 0x3c8) = 0;
  *(undefined4 *)(param_1 + 0x14c) = 0;
  return;
}

/* FUN_0009c800 @ 0x9c800 (744 bytes) */
int FUN_0009c800(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint *param_2;
  int param_3;
  undefined4 param_4;
  undefined4 param_5;
  int param_6;
  undefined4 *param_7;
  undefined4 param_8;
{
  uint uVar1;
  uint *puVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint *puVar9;
  uint *puVar10;
  int iVar11;
  
  iVar6 = (**(code **)(param_1 + 0xc))(0x60,param_2,param_3,param_4,param_5,param_6,param_7,param_8)
  ;
  uVar8 = *(uint *)(param_1 + 0x3c8);
  if (1000000 < uVar8) {
    ((int (*)())fpVariantCacheFlush)(param_1);
    uVar8 = *(uint *)(param_1 + 0x3c8);
  }
  if (((unsigned char *)0x00001120)[param_1] == '\0') {
    puVar9 = param_2 + 0xc;
    uVar4 = 0;
    puVar2 = param_2;
    while (puVar2 + 0xb <= puVar9) {
      uVar4 = uVar4 ^ *puVar2 ^ (puVar2[1] << 3 | puVar2[1] >> 0x1d) ^
              (puVar2[2] << 6 | puVar2[2] >> 0x1a) ^ (puVar2[3] << 9 | puVar2[3] >> 0x17) ^
              (puVar2[4] << 0xc | puVar2[4] >> 0x14) ^ (puVar2[5] << 0xf | puVar2[5] >> 0x11) ^
              (puVar2[6] << 0x12 | puVar2[6] >> 0xe) ^ (puVar2[7] << 0x15 | puVar2[7] >> 0xb) ^
              (puVar2[8] << 0x18 | puVar2[8] >> 8) ^ (puVar2[9] << 0x1b | puVar2[9] >> 5) ^
              (puVar2[10] << 0x1e | puVar2[10] >> 2);
      puVar2 = puVar2 + 0xb;
    }
    puVar10 = puVar2 + 5;
    if (puVar9 < puVar10) {
      uVar5 = 0;
      puVar10 = puVar2;
    }
    else {
      uVar5 = 0xf;
      uVar4 = uVar4 ^ *puVar2 ^ (puVar2[1] << 3 | puVar2[1] >> 0x1d) ^
              (puVar2[2] << 6 | puVar2[2] >> 0x1a) ^ (puVar2[3] << 9 | puVar2[3] >> 0x17) ^
              (puVar2[4] << 0xc | puVar2[4] >> 0x14);
    }
    for (; puVar10 < puVar9; puVar10 = puVar10 + 1) {
      uVar1 = uVar5 & 0x1f;
      uVar5 = uVar5 + 3;
      uVar4 = uVar4 ^ (*puVar10 << uVar1 | *puVar10 >> 0x20 - uVar1);
    }
    iVar11 = uVar4 - (uVar4 / *(uint *)(((unsigned char *)0x0000111c) + param_1)) *
                     *(uint *)(((unsigned char *)0x0000111c) + param_1);
  }
  else {
    uVar4 = *param_2 + param_2[2] + param_2[3];
    iVar11 = uVar4 - (uVar4 / *(uint *)(((unsigned char *)0x0000111c) + param_1)) *
                     *(uint *)(((unsigned char *)0x0000111c) + param_1);
  }
  *(uint *)(iVar6 + 0x30) = uVar8;
  *(int *)(param_1 + 0x3c8) = *(int *)(param_1 + 0x3c8) + 1;
  _memcpy(iVar6,param_2,0x30);
  *(undefined4 *)(iVar6 + 0x3c) = param_4;
  *(undefined4 *)(iVar6 + 0x40) = param_5;
  *(int *)(iVar6 + 0x54) = param_3;
  uVar3 = *(undefined4 *)(param_3 + 0x3d0);
  *(int *)(iVar6 + 0x48) = param_6;
  *(undefined4 *)(iVar6 + 0x44) = uVar3;
  if (param_7 == (undefined4 *)0x0) {
    iVar7 = ((int (*)())FUN_0009bd00)(param_1);
    *(int *)(iVar6 + 0x50) = iVar7;
    *(undefined4 *)(iVar7 + 8) = 0;
    *(undefined4 *)(iVar6 + 0x4c) = 0;
    *(undefined1 *)(iVar6 + 0x58) = 0;
  }
  else {
    *(undefined4 **)(iVar6 + 0x50) = param_7;
    if (((param_7[2] == 1) && (*(int *)*param_7 == 0)) && (*(int *)param_7[1] == 0)) {
      *(undefined1 *)(iVar6 + 0x58) = 1;
      *(undefined4 *)(iVar6 + 0x4c) = 0;
    }
    else {
      *(undefined1 *)(iVar6 + 0x58) = 0;
      uVar3 = (**(code **)(param_1 + 0xc))(param_6 << 4);
      *(undefined4 *)(iVar6 + 0x4c) = uVar3;
    }
  }
  *(char *)(iVar6 + 0x59) = (char)param_8;
  *(undefined4 *)(iVar6 + 0x5c) = *(undefined4 *)(*(int *)(((unsigned char *)0x00001118) + param_1) + iVar11 * 4);
  *(int *)(iVar11 * 4 + *(int *)(((unsigned char *)0x00001118) + param_1)) = iVar6;
  return iVar6;
}

/* FUN_0009cb10 @ 0x9cb10 (280 bytes) */
int FUN_0009cb10(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c [4];
  
  iVar4 = *(int *)(param_2 + 0x54);
  uVar1 = (**(code **)(param_1 + 0xc))(param_4 * *(int *)(iVar4 + 0x3cc),param_2,param_3,param_4);
  *(undefined4 *)(param_3 + 4) = *(undefined4 *)(iVar4 + 0x3c8);
  uVar3 = *(undefined4 *)(iVar4 + 0x3cc);
  *(int **)(param_3 + 0x1c) = &local_38;
  *(undefined4 **)(param_3 + 0x28) = &local_34;
  *(undefined4 *)(param_3 + 0x18) = uVar1;
  *(undefined4 **)(param_3 + 0x2c) = &local_30;
  *(undefined4 *)(param_3 + 8) = uVar3;
  *(undefined4 **)(param_3 + 0x30) = local_2c;
  iVar2 = recordProgramBuildDependencies(param_3);
  if (iVar2 == 0) {
    _memcpy(*(undefined4 *)(iVar4 + 0x3c8),uVar1,param_4 * local_38);
    *(int *)(iVar4 + 0x3cc) = local_38;
    *(undefined4 *)(param_2 + 0x38) = local_30;
    *(undefined4 *)(param_2 + 0x44) = local_2c[0];
    *(undefined4 *)(param_2 + 0x34) = local_34;
  }
  else {
    _memcpy(*(undefined4 *)(iVar4 + 0x3c8),uVar1,param_4 * *(int *)(iVar4 + 0x3cc));
  }
  (**(code **)(param_1 + 0x18))(uVar1);
  return iVar2 == 0;
}

/* FUN_0009cc30 @ 0x9cc30 (712 bytes) */
int FUN_0009cc30(param_1)
  int param_1;
{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  ushort uVar5;
  ushort uVar6;
  ushort uVar7;
  ushort uVar8;
  ushort uVar9;
  ushort uVar10;
  ushort uVar11;
  ushort uVar12;
  float fVar13;
  float fVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  uint uVar18;
  int iVar19;
  bool bVar20;
  uint uVar21;
  ushort *puVar22;
  int iVar23;
  bool bVar24;
  int iVar25;
  
  iVar23 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if (*(char *)(iVar23 + 0x24ad) == '\0') {
    uVar18 = *(uint *)(param_1 + 0x44);
    bVar20 = false;
    bVar4 = false;
    uVar21 = 0;
  }
  else {
    uVar18 = *(uint *)(param_1 + 0x44);
    if (((int)uVar18 < 0) && (uVar21 = *(uint *)(param_1 + 0x88), uVar21 != 0)) {
      bVar20 = false;
      bVar4 = false;
      iVar19 = iVar23;
      do {
        if ((uVar21 & 1) != 0) {
          bVar24 = *(float *)(iVar19 + 0x24fc) == FLOAT_001aa0d4;
          bVar4 = (bool)(bVar24 | bVar4);
          bVar20 = (bool)(!bVar24 | bVar20);
        }
        uVar21 = uVar21 >> 1;
        iVar19 = iVar19 + 0x80;
      } while (uVar21 != 0);
    }
    else {
      bVar20 = false;
      bVar4 = false;
    }
    uVar21 = -(uint)(*(uint *)(param_1 + 0x8c) & 0xc000000) >> 0x1f;
  }
  uVar15 = *(uint *)(param_1 + 0x1874);
  uVar2 = ((byte)((unsigned char *)0x00002d48)[iVar23 + 5] & 1) << 0x1d;
  uVar3 = (*(byte *)(param_1 + 300) & 1) << 0x1a;
  *(uint *)(param_1 + 0x1874) = uVar3 | uVar2 | uVar15 & 0xdbffffff;
  if (((uVar21 != 0) || (bVar20)) || (iVar19 = 0, bVar4)) {
    iVar19 = 1;
  }
  uVar21 = iVar19 << 0x18;
  uVar16 = uVar21 | uVar3 | uVar2 | uVar15 & 0xdaffffff;
  *(uint *)(param_1 + 0x1874) = uVar16;
  if ((int)uVar18 < 0) {
    uVar18 = *(uint *)(param_1 + 0x88);
    iVar25 = 8;
    *(uint *)(param_1 + 0x1874) = uVar16 | 0x800;
    fVar14 = FLOAT_001aa0e8;
    fVar13 = FLOAT_001aa0d4;
    puVar22 = (ushort *)(param_1 + 0x1894);
    iVar17 = 0;
    iVar19 = param_1 + 0x3a8;
    uVar16 = (uint)(*(short *)(((unsigned char *)0x00002d48) + iVar23) == -0x7e06) << 10;
    *(uint *)(param_1 + 0x1874) = uVar16 | uVar21 | uVar3 | uVar2 | uVar15 & 0xdafffbff | 0x800;
    *(uint *)(param_1 + 0x1874) =
         (*(byte *)(param_1 + 0x12d) & 1) << 8 |
         ((byte)((unsigned char *)0x00002d48)[iVar23 + 4] & 1) << 9 |
         uVar16 | uVar21 | uVar3 | uVar2 | uVar15 & 0xdafff8ff | 0x800;
    do {
      if ((uVar18 & 1) == 0) {
        *puVar22 = 0;
      }
      else {
        uVar1 = *puVar22;
        *puVar22 = uVar1 | 0x8000;
        uVar8 = (ushort)((uint)*(undefined4 *)(iVar19 + iVar17) >> 0x11) & 0x6000;
        *puVar22 = uVar8 | uVar1 & 0x9fff | 0x8000;
        uVar9 = (*(byte *)(iVar19 + iVar17) & 0x30) << 7;
        *puVar22 = uVar8 | uVar1 & 0x87ff | 0x8000 | uVar9;
        uVar10 = (*(byte *)(iVar19 + iVar17) & 0xc) << 7;
        *puVar22 = uVar8 | uVar1 & 0x81ff | 0x8000 | uVar9 | uVar10;
        uVar5 = (ushort)(*(float *)(iVar23 + 0x24fc) != fVar13) << 8;
        *puVar22 = uVar8 | uVar1 & 0x80ff | 0x8000 | uVar9 | uVar10 | uVar5;
        uVar6 = (ushort)(*(float *)(iVar23 + 0x24fc) == fVar14) << 7;
        *puVar22 = uVar8 | uVar1 & 0x807f | 0x8000 | uVar9 | uVar10 | uVar5 | uVar6;
        uVar11 = ((byte)((unsigned char *)0x0000150c)[param_1] & 1) << 6;
        *puVar22 = uVar8 | uVar1 & 0x803f | 0x8000 | uVar9 | uVar10 | uVar5 | uVar6 | uVar11;
        uVar7 = (ushort)(*(float *)(iVar23 + 0x251c) != fVar13) << 5;
        *puVar22 = uVar8 | uVar1 & 0x801f | 0x8000 | uVar9 | uVar10 | uVar5 | uVar6 | uVar11 | uVar7
        ;
        uVar12 = (ushort)((uint)*(undefined4 *)(iVar19 + iVar17) >> 0x15) & 0x10;
        *puVar22 = uVar12 | uVar8 | uVar1 & 0x800f | 0x8000 | uVar9 | uVar10 | uVar5 | uVar6 |
                            uVar11 | uVar7;
        *puVar22 = uVar12 | uVar8 | uVar1 & 0x8007 | 0x8000 | uVar9 | uVar10 | uVar5 | uVar6 |
                            uVar11 | uVar7 | (*(byte *)(iVar19 + iVar17) & 1) << 3;
      }
      uVar18 = uVar18 >> 1;
      puVar22 = puVar22 + 1;
      iVar17 = iVar17 + 4;
      iVar23 = iVar23 + 0x80;
      param_1 = param_1 + 0x6c;
      iVar25 = iVar25 + -1;
    } while (iVar25 != 0);
  }
  else {
    iVar23 = 8;
    *(uint *)(param_1 + 0x1874) =
         -(uVar18 & 0xa10000) >> 0x18 & 0x80 | uVar21 | uVar3 | uVar2 | uVar15 & 0xdafff07f;
    do {
      *(undefined2 *)(param_1 + 0x1894) = 0;
      param_1 = param_1 + 2;
      iVar23 = iVar23 + -1;
    } while (iVar23 != 0);
  }
  return;
}

/* FUN_0009cf10 @ 0x9cf10 (224 bytes) */
int FUN_0009cf10(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  short sVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if (((*(uint *)(param_1 + 0x44) & 0x1000000) != 0) && (*(char *)(param_1 + 0x121) == '\0')) {
    sVar1 = *(short *)(((unsigned char *)0x00002e04) + iVar2);
    uVar3 = 2;
    if ((sVar1 != 0x801) && (uVar3 = 3, sVar1 != 0x2601)) {
      uVar3 = (uint)(sVar1 == 0x800);
    }
    *(uint *)(param_1 + 0x1874) =
         (uint)(*(short *)(((unsigned char *)0x00002e06) + iVar2) == -0x7baf) << 4 |
         uVar3 << 5 | *(uint *)(param_1 + 0x1874) & 0xffffff8f;
    sVar1 = *(short *)(((unsigned char *)0x00002e08) + iVar2);
    if (sVar1 == -0x7aa5) {
      uVar3 = 2;
    }
    else if (sVar1 == -0x7aa4) {
      uVar3 = 0;
    }
    else if (sVar1 == 0x2502) {
      uVar3 = 1;
    }
    *(uint *)(param_1 + 0x1878) = uVar3 << 0x12 | *(uint *)(param_1 + 0x1878) & 0xfff3ffff;
    return;
  }
  *(uint *)(param_1 + 0x1874) = *(uint *)(param_1 + 0x1874) & 0xffffff8f;
  *(uint *)(param_1 + 0x1878) = *(uint *)(param_1 + 0x1878) & 0xfff3ffff;
  return;
}

/* FUN_0009cff0 @ 0x9cff0 (132 bytes) */
int FUN_0009cff0(param_1)
  int param_1;
{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if ((((unsigned char *)0x00004301)[iVar4] != '\0') && (*(byte *)(param_1 + 0x91) != 0)) {
    uVar3 = *(uint *)(param_1 + 0x1874);
    bVar1 = ((unsigned char *)0x000013a9)[param_1];
    bVar2 = ((unsigned char *)0x000013aa)[param_1];
    *(uint *)(param_1 + 0x1874) = uVar3 | 0x8000000;
    *(uint *)(param_1 + 0x1874) =
         (bVar2 & 1) << 0xf |
         (bVar1 & 1) << 0x10 |
         (*(byte *)(param_1 + 0x91) & 7) << 0x11 |
         (uint)(*(char *)(param_1 + 0x90) == '\x02') << 0x14 |
         (*(uint *)(param_1 + 0x8c) & 0x80000) << 2 |
         ((byte)((unsigned char *)0x00004302)[iVar4] & 1) << 0x16 | uVar3 & 0xff807fff | 0x8000000;
    return;
  }
  *(uint *)(param_1 + 0x1874) = *(uint *)(param_1 + 0x1874) & 0xf7807fff;
  return;
}

/* FUN_0009d080 @ 0x9d080 (596 bytes) */
int FUN_0009d080(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  bool bVar1;
  bool bVar2;
  float fVar3;
  uint uVar4;
  undefined1 uVar5;
  int iVar6;
  byte bVar7;
  int iVar8;
  uint *puVar9;
  bool bVar10;
  
  iVar6 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  *(undefined1 *)(param_1 + 0x128) = 0;
  *(undefined1 *)(param_1 + 0x129) = 0;
  *(undefined1 *)(param_1 + 0x130) = 0;
  *(undefined1 *)(param_1 + 0x12a) = 0;
  if (*(int *)(param_1 + 0x44) < 0) {
    if (*(int *)(param_1 + 0x13c) == 1) {
      uVar4 = *(uint *)(param_1 + 0x26c);
      *(undefined4 *)(param_1 + 0x290) = 2;
      *(uint *)(param_1 + 0x278) = uVar4 >> 4 & 0xf;
      *(uint *)(param_1 + 0x270) = uVar4 & 0xf;
      *(uint *)(param_1 + 0x280) = uVar4 >> 8 & 0xf;
      *(uint *)(param_1 + 0x28c) = uVar4 >> 0x1c;
      *(uint *)(param_1 + 0x288) = uVar4 >> 0xc & 0xf;
      *(uint *)(param_1 + 0x274) = uVar4 >> 0x10 & 0xf;
      *(uint *)(param_1 + 0x27c) = uVar4 >> 0x14 & 0xf;
      *(undefined4 *)(param_1 + 0x294) = 3;
      *(uint *)(param_1 + 0x284) = uVar4 >> 0x18 & 0xf;
    }
    else {
      *(undefined4 *)(param_1 + 0x280) = 2;
      *(undefined4 *)(param_1 + 0x288) = 3;
      *(undefined4 *)(param_1 + 0x290) = 0;
      *(undefined4 *)(param_1 + 0x294) = 1;
      *(undefined4 *)(param_1 + 0x274) = 4;
      *(undefined4 *)(param_1 + 0x27c) = 5;
      *(undefined4 *)(param_1 + 0x270) = 0;
      *(undefined4 *)(param_1 + 0x278) = 1;
      *(undefined4 *)(param_1 + 0x284) = 6;
      *(undefined4 *)(param_1 + 0x28c) = 7;
    }
    fVar3 = FLOAT_001aa0d4;
    uVar4 = *(uint *)(param_1 + 0x88);
    if (uVar4 != 0) {
      bVar1 = false;
      bVar2 = false;
      puVar9 = (uint *)(param_1 + 0x3a8);
      iVar8 = iVar6;
      do {
        if ((uVar4 & 1) != 0) {
          if ((((*puVar9 & 0xc000000) == 0) || (*(short *)(((unsigned char *)0x00002d48) + iVar6) != -0x7e06)) ||
             (bVar7 = 1, ((unsigned char *)0x00002d48)[iVar6 + 5] == '\0')) {
            bVar7 = 0;
          }
          *(byte *)(param_1 + 0x130) = bVar7 | *(byte *)(param_1 + 0x130);
          bVar10 = *(float *)(iVar8 + 0x24fc) == fVar3;
          bVar1 = (bool)(bVar10 | bVar1);
          bVar2 = (bool)(!bVar10 | bVar2);
        }
        uVar4 = uVar4 >> 1;
        puVar9 = puVar9 + 1;
        iVar8 = iVar8 + 0x80;
      } while (uVar4 != 0);
      goto LAB_0009d228;
    }
  }
  bVar1 = false;
  bVar2 = false;
LAB_0009d228:
  uVar4 = *(uint *)(param_1 + 0x8c) >> 0x1b & 1 | *(uint *)(param_1 + 0x8c) >> 0x1a & 1;
  if ((uVar4 == 0) || (bVar7 = 1, ((unsigned char *)0x00002d48)[iVar6 + 5] == '\0')) {
    bVar7 = 0;
  }
  bVar7 = *(byte *)(param_1 + 0x130) | bVar7;
  *(byte *)(param_1 + 0x130) = bVar7;
  *(byte *)(param_1 + 0x129) = bVar2 | bVar7;
  if ((((uVar4 == 0) && (!bVar2)) && (!bVar1)) || (uVar5 = 1, *(char *)(iVar6 + 0x24ad) == '\0')) {
    uVar5 = 0;
  }
  *(undefined1 *)(param_1 + 0x128) = uVar5;
  if ((*(char *)(param_1 + 0x12f) != '\0') || (bVar7 = 1, -1 < *(int *)(param_1 + 0x44))) {
    bVar7 = 0;
  }
  *(byte *)(param_1 + 0x12a) = bVar7 | (byte)uVar4;
  return;
}

/* FUN_0009d2e0 @ 0x9d2e0 (184 bytes) */
int FUN_0009d2e0(param_1)
  int param_1;
{
  code *UNRECOVERED_JUMPTABLE;
  int iVar1;
  
  if (*(char *)(param_1 + 0x3d4) != '\0') {
    return;
  }
  if (*(char *)(param_1 + 0x124) == '\0') {
    if ((*(uint *)(param_1 + 0x44) & 0x100000) != 0) {
      return;
    }
    iVar1 = *(int *)(param_1 + 0x14c);
    if (iVar1 == 0) {
      return;
    }
    (**(code **)(((unsigned char *)0x000012d0) + param_1))(param_1,iVar1);
    UNRECOVERED_JUMPTABLE = *(code **)(((unsigned char *)0x000012c4) + param_1);
  }
  else {
    iVar1 = *(int *)(param_1 + 0x14c);
    if (iVar1 == 0) {
      return;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(((unsigned char *)0x000012d0) + param_1);
  }
                    
                    
  (*UNRECOVERED_JUMPTABLE)(param_1,iVar1);
  return;
}

/* FUN_0009d3b0 @ 0x9d3b0 (64 bytes) */
int FUN_0009d3b0(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  if (param_1 == 0) {
    return;
  }
  *(undefined1 *)(param_1 + 0x3d4) = 0;
  if ((*(uint *)(param_1 + 0x44) & 0x100000) != 0) {
    if (*(char *)(param_1 + 0x1868) != '\0') {
                    
                    
      (**(code **)((int)((unsigned char *)0x000011cc) + param_1))();
      return;
    }
    FUN_00064f40(param_1,param_2);
    return;
  }
  ((int (*)())FUN_0009d2e0)(param_1);
  return;
}

/* ffvpBuildProgram @ 0x9d410 (5944 bytes) */
int ffvpBuildProgram(ctx, passThroughArg2, passThroughArg3, constRegCountOut, paramList, unusedArg6, unusedArg7, unusedArg8)
  int ctx;
  undefined4 passThroughArg2;
  undefined4 passThroughArg3;
  int *constRegCountOut;
  int *paramList;
  undefined4 unusedArg6;
  undefined4 unusedArg7;
  undefined4 unusedArg8;
{
  int lightIndex;
  int ctxUnitCursor;
  int activeLightCount;
  int texUnitCtxCursor;
  int genIndex;
  int lastParamReg;
  int programTypeResult;
  int emittedLightIndex;
  int regPlus1;
  int paramCountSnapshot;
  int regCursor;
  int ctxCursor;
  int matrixLoopCount;
  int lightStateCursor;
  int texUnitStateCursor;
  float zeroConst;
  undefined4 paramKind;
  uint lightControlWord;
  int lastActiveLight;
  int texUnitEnableCursor;
  uint lightMaskLoop;
  uint texUnitIndex;
  uint ctxByte11d2;
  uint lightMaskCopy;
  uint texUnitCount;
  uint texUnitLimit;
  uint tableCount;
  uint lightMaskShifting;
  uint ctxFlags44;
  uint unitMask;
  uint matrixIndex;
  byte lightEnableByte;
  byte matrixCountByte;
  short fogMode;
  bool needsLightModelParam;
  uint ctxFlags8c;
  uint texGenFlags;
  uint ctxFlags44B;
  int programRecord;
  int nextConstReg;
  uint texUnitIndexMap;
  undefined4 programFlag;
  int *mapCursorA;
  float matrixCursor;
  int *mapCursorB;
  int regAfterLightPair;
  int regAfterFour;
  int regPlus4;
  int paramKinds;
  int unaff_r17;
  int unaff_r18;
  float unaff_r19;
  undefined4 ctxFlag400Active;
  int stateBlock;
  int stateBlockCopy;
  int *paramMapCursor;
  uint *lightControlPtr;
  int unitKindIndex;
  ushort *texCoordMapPtr;
  int unitCountdown;
  float local_78;
  uint local_74 [4];
  float local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  float local_50;
  int local_4c;
  int local_48;
  
  stateBlock = *(int *)(*(int *)(ctx + 4) + 0x10);
  if ((*(uint *)(ctx + 0x1874) & 0xc0000000) != 0x40000000) {
    ctxFlags44B = *(uint *)(ctx + 0x44);
    goto LAB_0009d494;
  }
  if ((*(uint *)(ctx + 0x8c) & 0x800000) != 0) {
    ctxFlags44B = *(uint *)(ctx + 0x44);
    goto LAB_0009d4b8;
  }
  ctxFlags44B = *(uint *)(ctx + 0x44);
  if ((ctxFlags44B & 0x20000) == 0) {
LAB_0009d494:
    programFlag = 0;
  }
  else {
    if ((ctxFlags44B & 0x2000) == 0) {
      if (((unsigned char *)0x00001135)[ctx] != '\0') goto LAB_0009d4b8;
      goto LAB_0009d494;
    }
    if (((unsigned char *)0x000011d3)[ctx] == '\0') goto LAB_0009d494;
LAB_0009d4b8:
    programFlag = 1;
    if ((*(uint *)(((unsigned char *)0x000013c0) + ctx) & 1) == 0) goto LAB_0009d494;
  }
  if (((ctxFlags44B & 0x400) == 0) || (ctxFlag400Active = 1, (*(uint *)(((unsigned char *)0x000013c0) + ctx) & 2) == 0)) {
    ctxFlag400Active = 0;
  }
  ctxByte11d2 = (uint)(byte)((unsigned char *)0x000011d2)[ctx];
  programRecord = FUN_00092bf0(ctx,passThroughArg2,programFlag);
  (**(code **)(((unsigned char *)0x000012c0) + ctx))(ctx,programRecord,&local_78,passThroughArg3);
  if (*(int *)(ctx + 0x13c) == 1) {
    _memcpy(programRecord,ctx + 0x19c,0x68);
  }
  else {
    _memcpy(programRecord,ctx + 0x204,0x68);
  }
  paramMapCursor = (int *)(programRecord + 0xa4);
  stateBlockCopy = *(int *)(*(int *)(ctx + 4) + 0x10);
  _memset(paramMapCursor,0xffffffff,0x324);
  paramList[2] = 0;
  if (((unsigned char *)0x00004301)[stateBlockCopy] == '\0') {
    local_78 = GH_U2F((unsigned int)((stateBlockCopy + 0x2460)));
    nextConstReg = 0;
    if ((((((local_74[0] != 0 || local_74[1] != 0) || local_74[2] != 0) ||
          FLOAT_001aa0e8 != local_78) ||
         (((local_74[3] != 0 || local_60 != 0) || local_5c != 0) || FLOAT_001aa0e8 != local_64)) ||
        (((local_58 != 0 || local_54 != 0) || local_4c != 0) || FLOAT_001aa0e8 != local_50)) ||
        (((local_48 != 0 || unaff_r17 != 0) || unaff_r18 != 0) || FLOAT_001aa0e8 != unaff_r19)) {
      *(undefined4 *)(programRecord + 0xa4) = 0;
      nextConstReg = 4;
      *(undefined4 *)(paramList[2] * 4 + *paramList) = 0;
      *(undefined4 *)(paramList[2] * 4 + paramList[1]) = 0;
      paramList[2] = paramList[2] + 1;
    }
    ctxFlags8c = *(uint *)(ctx + 0x8c);
    if ((ctxFlags8c & 0x80000) != 0) {
      *(int *)(programRecord + 0xb4) = nextConstReg;
      regPlus4 = nextConstReg + 4;
      nextConstReg = nextConstReg + 8;
      *(undefined4 *)(paramList[2] * 4 + *paramList) = 1;
      *(undefined4 *)(paramList[2] * 4 + paramList[1]) = 0;
      paramList[2] = paramList[2] + 1;
      *(int *)(programRecord + 0xc4) = regPlus4;
      *(undefined4 *)(paramList[2] * 4 + *paramList) = 2;
      *(undefined4 *)(paramList[2] * 4 + paramList[1]) = 0;
      paramList[2] = paramList[2] + 1;
      ctxFlags8c = *(uint *)(ctx + 0x8c);
    }
  }
  else {
    matrixCountByte = ((unsigned char *)0x00004300)[stateBlockCopy];
    nextConstReg = 0;
    matrixLoopCount = 4;
    matrixIndex = 0;
    matrixCursor = GH_U2F((unsigned int)((stateBlockCopy + 0x1960)));
    mapCursorA = paramMapCursor;
    do {
      if (((1 << (matrixCountByte & 0x3f)) - 1U & 1 << (matrixIndex & 0x3f)) != 0) {
        if ((((((local_74[0] != 0 || local_74[1] != 0) || local_74[2] != 0) ||
              FLOAT_001aa0e8 != matrixCursor) ||
             (((local_74[3] != 0 || local_60 != 0) || local_5c != 0) || FLOAT_001aa0e8 != local_64))
            || (((local_58 != 0 || local_54 != 0) || local_4c != 0) || FLOAT_001aa0e8 != local_50))
            || (((local_48 != 0 || unaff_r17 != 0) || unaff_r18 != 0) || FLOAT_001aa0e8 != unaff_r19
               )) {
          *mapCursorA = nextConstReg;
          nextConstReg = nextConstReg + 4;
          *(undefined4 *)(paramList[2] * 4 + *paramList) = 0;
          *(uint *)(paramList[2] * 4 + paramList[1]) = matrixIndex;
          paramList[2] = paramList[2] + 1;
        }
        local_78 = matrixCursor;
        if ((*(uint *)(ctx + 0x8c) & 0x80000) != 0) {
          mapCursorA[4] = nextConstReg;
          regAfterFour = nextConstReg + 4;
          nextConstReg = nextConstReg + 8;
          *(undefined4 *)(paramList[2] * 4 + *paramList) = 1;
          *(uint *)(paramList[2] * 4 + paramList[1]) = matrixIndex;
          paramList[2] = paramList[2] + 1;
          mapCursorA[8] = regAfterFour;
          *(undefined4 *)(paramList[2] * 4 + *paramList) = 2;
          *(uint *)(paramList[2] * 4 + paramList[1]) = matrixIndex;
          paramList[2] = paramList[2] + 1;
        }
      }
      matrixIndex = matrixIndex + 1;
      matrixCursor = GH_U2F((unsigned int)(((int)GH_F2U(matrixCursor) + 0x40)));
      mapCursorA = mapCursorA + 1;
      matrixLoopCount = matrixLoopCount + -1;
    } while (matrixLoopCount != 0);
    *(int *)(programRecord + 0xd4) = nextConstReg;
    nextConstReg = nextConstReg + 4;
    *(undefined4 *)(paramList[2] * 4 + *paramList) = 3;
    *(undefined4 *)(paramList[2] * 4 + paramList[1]) = 0;
    paramList[2] = paramList[2] + 1;
    ctxFlags8c = *(uint *)(ctx + 0x8c);
  }
  if ((ctxFlags8c & 0x800000) != 0) {
    unitMask = 0xff;
    if ((*(uint *)(ctx + 0x44) & 0x20000) != 0) {
      if ((*(uint *)(ctx + 0x44) & 0x2000) == 0) {
        unitMask = (uint)(byte)((unsigned char *)0x00001135)[ctx];
      }
      else {
        unitMask = (uint)(byte)((unsigned char *)0x000011d3)[ctx];
      }
    }
    unitCountdown = 8;
    texUnitIndexMap = 0;
    unitKindIndex = 0;
    texUnitStateCursor = ctx + 0x450;
    mapCursorA = paramMapCursor;
    mapCursorB = paramMapCursor;
    ctxCursor = ctx;
    do {
      if ((unitMask & 1 << (texUnitIndexMap & 0x3f)) != 0) {
        texGenFlags = *(uint *)(ctxCursor + 0x48);
        if (((texGenFlags & 0x20) != 0) && ((ushort)(*(short *)(texUnitStateCursor + 0x3c) + 0xdc00U) < 2)) {
          mapCursorA[0xa9] = nextConstReg;
          nextConstReg = nextConstReg + 1;
          *(undefined4 *)(paramList[2] * 4 + *paramList) = 0x1a;
          *(int *)(paramList[2] * 4 + paramList[1]) = unitKindIndex;
          paramList[2] = paramList[2] + 1;
        }
        if (((texGenFlags & 0x40) != 0) && ((ushort)(*(short *)(texUnitStateCursor + 0x60) + 0xdc00U) < 2)) {
          mapCursorA[0xaa] = nextConstReg;
          nextConstReg = nextConstReg + 1;
          *(undefined4 *)(paramList[2] * 4 + *paramList) = 0x1a;
          *(int *)(paramList[2] * 4 + paramList[1]) = unitKindIndex + 1;
          paramList[2] = paramList[2] + 1;
        }
        if (((texGenFlags & 0x80) != 0) && ((ushort)(*(short *)(texUnitStateCursor + 0x84) + 0xdc00U) < 2)) {
          mapCursorA[0xab] = nextConstReg;
          nextConstReg = nextConstReg + 1;
          *(undefined4 *)(paramList[2] * 4 + *paramList) = 0x1a;
          *(int *)(paramList[2] * 4 + paramList[1]) = unitKindIndex + 2;
          paramList[2] = paramList[2] + 1;
        }
        if (((texGenFlags & 0x100) != 0) && ((ushort)(*(short *)(texUnitStateCursor + 0xa8) + 0xdc00U) < 2)) {
          mapCursorA[0xac] = nextConstReg;
          nextConstReg = nextConstReg + 1;
          *(undefined4 *)(paramList[2] * 4 + *paramList) = 0x1a;
          *(int *)(paramList[2] * 4 + paramList[1]) = unitKindIndex + 3;
          paramList[2] = paramList[2] + 1;
        }
        if (*(int *)(ctxCursor + 0x150) != 0) {
          mapCursorB[0xd] = nextConstReg;
          nextConstReg = nextConstReg + 4;
          *(undefined4 *)(paramList[2] * 4 + *paramList) = 4;
          *(uint *)(paramList[2] * 4 + paramList[1]) = texUnitIndexMap;
          paramList[2] = paramList[2] + 1;
        }
      }
      texUnitIndexMap = texUnitIndexMap + 1;
      texUnitStateCursor = texUnitStateCursor + 0xcc;
      unitKindIndex = unitKindIndex + 4;
      mapCursorB = mapCursorB + 1;
      ctxCursor = ctxCursor + 4;
      mapCursorA = mapCursorA + 4;
      unitCountdown = unitCountdown + -1;
    } while (unitCountdown != 0);
  }
  zeroConst = FLOAT_001aa0d4;
  ctxFlags44 = *(uint *)(ctx + 0x44);
  if ((int)ctxFlags44 < 0) {
    lightMaskShifting = *(uint *)(ctx + 0x88);
    if (lightMaskShifting == 0) {
      needsLightModelParam = false;
      regCursor = nextConstReg;
    }
    else {
      lightIndex = 0;
      needsLightModelParam = false;
      lightStateCursor = stateBlockCopy;
      ctxUnitCursor = ctx;
      do {
        lightControlPtr = (uint *)(lightIndex * 4 + ctx + 0x3a8);
        regCursor = nextConstReg;
        if (((lightMaskShifting & 1) != 0) &&
           (lightControlWord = *(uint *)(ctx + 0x3a8 + lightIndex * 4), (lightControlWord & 0xfc000000) != 0)) {
          lightControlWord = lightControlWord & 0xc0000000;
          if (lightControlWord == 0x80000000) {
            paramMapCursor[0x16] = nextConstReg;
            nextConstReg = nextConstReg + 1;
            *(undefined4 *)(paramList[2] * 4 + *paramList) = 5;
            *(int *)(paramList[2] * 4 + paramList[1]) = lightIndex;
            paramList[2] = paramList[2] + 1;
          }
          else if (lightControlWord == 0xc0000000) {
            needsLightModelParam = true;
          }
          lightControlWord = *lightControlPtr;
          if ((lightControlWord & 0x30000000) == 0x20000000) {
            if (*(int *)(ctx + 0x13c) == 1) {
              if (7 < *(uint *)(ctx + 0x280)) {
                paramMapCursor[0x18] = nextConstReg;
                nextConstReg = nextConstReg + 1;
                *(undefined4 *)(paramList[2] * 4 + *paramList) = 0x1c;
                *(int *)(paramList[2] * 4 + paramList[1]) = lightIndex << 1;
                paramList[2] = paramList[2] + 1;
              }
              if ((((unsigned char *)0x00002d48)[stateBlockCopy + 4] != '\0') && (7 < *(uint *)(ctx + 0x284))) {
                paramMapCursor[0x19] = nextConstReg;
                nextConstReg = nextConstReg + 1;
                *(undefined4 *)(paramList[2] * 4 + *paramList) = 0x1c;
                *(uint *)(paramList[2] * 4 + paramList[1]) = lightIndex << 1 | 1;
                paramList[2] = paramList[2] + 1;
              }
            }
            if ((paramMapCursor[0x18] == -1) ||
               ((((unsigned char *)0x00002d48)[stateBlockCopy + 4] != '\0' && (paramMapCursor[0x19] == -1)))) {
              paramMapCursor[0x17] = nextConstReg;
              nextConstReg = nextConstReg + 1;
              *(undefined4 *)(paramList[2] * 4 + *paramList) = 6;
              *(int *)(paramList[2] * 4 + paramList[1]) = lightIndex;
              paramList[2] = paramList[2] + 1;
              lightControlWord = *lightControlPtr;
            }
            else {
              lightControlWord = *lightControlPtr;
            }
          }
          if ((lightControlWord & 0xc000000) == 0x8000000) {
            if (*(int *)(ctx + 0x13c) == 1) {
              if (7 < *(uint *)(ctx + 0x288)) {
                paramMapCursor[0x1b] = nextConstReg;
                nextConstReg = nextConstReg + 1;
                *(undefined4 *)(paramList[2] * 4 + *paramList) = 0x1d;
                *(int *)(paramList[2] * 4 + paramList[1]) = lightIndex << 1;
                paramList[2] = paramList[2] + 1;
              }
              if ((((unsigned char *)0x00002d48)[stateBlockCopy + 4] != '\0') && (7 < *(uint *)(ctx + 0x28c))) {
                paramMapCursor[0x1c] = nextConstReg;
                nextConstReg = nextConstReg + 1;
                *(undefined4 *)(paramList[2] * 4 + *paramList) = 0x1d;
                *(uint *)(paramList[2] * 4 + paramList[1]) = lightIndex << 1 | 1;
                paramList[2] = paramList[2] + 1;
              }
            }
            if ((paramMapCursor[0x1b] == -1) ||
               ((((unsigned char *)0x00002d48)[stateBlockCopy + 4] != '\0' && (paramMapCursor[0x1c] == -1)))) {
              paramMapCursor[0x1a] = nextConstReg;
              nextConstReg = nextConstReg + 1;
              *(undefined4 *)(paramList[2] * 4 + *paramList) = 7;
              *(int *)(paramList[2] * 4 + paramList[1]) = lightIndex;
              paramList[2] = paramList[2] + 1;
            }
          }
          paramMapCursor[0x1e] = nextConstReg;
          regAfterLightPair = nextConstReg + 2;
          *(undefined4 *)(paramList[2] * 4 + *paramList) = 8;
          *(int *)(paramList[2] * 4 + paramList[1]) = lightIndex;
          paramList[2] = paramList[2] + 1;
          paramMapCursor[0x1f] = nextConstReg + 1;
          *(undefined4 *)(paramList[2] * 4 + *paramList) = 9;
          *(int *)(paramList[2] * 4 + paramList[1]) = lightIndex;
          paramList[2] = paramList[2] + 1;
          regCursor = regAfterLightPair;
          if (*(float *)(lightStateCursor + 0x24fc) != zeroConst) {
            if ((*lightControlPtr & 0x2000000) != 0) {
              if ((*lightControlPtr & 0x1000000) == 0) {
                paramMapCursor[0x20] = regAfterLightPair;
                paramKind = 10;
                paramCountSnapshot = paramList[2];
                paramKinds = *paramList;
              }
              else {
                paramMapCursor[0x22] = regAfterLightPair;
                paramKind = 0xc;
                paramCountSnapshot = paramList[2];
                paramKinds = *paramList;
              }
              regAfterLightPair = nextConstReg + 3;
              *(undefined4 *)(paramCountSnapshot * 4 + paramKinds) = paramKind;
              *(int *)(paramList[2] * 4 + paramList[1]) = lightIndex;
              paramList[2] = paramList[2] + 1;
            }
            regCursor = regAfterLightPair;
            if (((unsigned char *)0x0000150c)[ctxUnitCursor] != '\0') {
              paramMapCursor[0x21] = regAfterLightPair;
              regCursor = regAfterLightPair + 1;
              *(undefined4 *)(paramList[2] * 4 + *paramList) = 0xb;
              *(int *)(paramList[2] * 4 + paramList[1]) = lightIndex;
              paramList[2] = paramList[2] + 1;
              if (*(float *)(lightStateCursor + 0x251c) != zeroConst) {
                paramMapCursor[0x23] = regCursor;
                regCursor = regAfterLightPair + 2;
                *(undefined4 *)(paramList[2] * 4 + *paramList) = 0xd;
                *(int *)(paramList[2] * 4 + paramList[1]) = lightIndex;
                paramList[2] = paramList[2] + 1;
              }
            }
          }
        }
        lightMaskShifting = lightMaskShifting >> 1;
        lightIndex = lightIndex + 1;
        paramMapCursor = paramMapCursor + 0xf;
        lightStateCursor = lightStateCursor + 0x80;
        ctxUnitCursor = ctxUnitCursor + 0x6c;
        nextConstReg = regCursor;
      } while (lightMaskShifting != 0);
    }
    if (*(int *)(ctx + 0x13c) == 1) {
      if (7 < *(uint *)(ctx + 0x270)) {
        *(int *)(programRecord + 0x2d8) = regCursor;
        regCursor = regCursor + 1;
        *(undefined4 *)(paramList[2] * 4 + *paramList) = 0xe;
        *(undefined4 *)(paramList[2] * 4 + paramList[1]) = 0;
        paramList[2] = paramList[2] + 1;
      }
      if (7 < *(uint *)(ctx + 0x278)) {
        *(int *)(programRecord + 0x2dc) = regCursor;
        regCursor = regCursor + 1;
        *(undefined4 *)(paramList[2] * 4 + *paramList) = 0xf;
        *(undefined4 *)(paramList[2] * 4 + paramList[1]) = 0;
        paramList[2] = paramList[2] + 1;
      }
      if (7 < *(uint *)(ctx + 0x280)) {
        *(int *)(programRecord + 0x2e0) = regCursor;
        regCursor = regCursor + 1;
        *(undefined4 *)(paramList[2] * 4 + *paramList) = 0x10;
        *(undefined4 *)(paramList[2] * 4 + paramList[1]) = 0;
        paramList[2] = paramList[2] + 1;
      }
      if (7 < *(uint *)(ctx + 0x288)) {
        *(int *)(programRecord + 0x2ec) = regCursor;
        regCursor = regCursor + 1;
        *(undefined4 *)(paramList[2] * 4 + *paramList) = 0x11;
        *(undefined4 *)(paramList[2] * 4 + paramList[1]) = 0;
        paramList[2] = paramList[2] + 1;
      }
      if ((7 < *(uint *)(ctx + 0x270)) || (7 < *(uint *)(ctx + 0x278))) {
        *(int *)(programRecord + 0x2f8) = regCursor;
        regCursor = regCursor + 1;
        *(undefined4 *)(paramList[2] * 4 + *paramList) = 0x12;
        *(undefined4 *)(paramList[2] * 4 + paramList[1]) = 0;
        paramList[2] = paramList[2] + 1;
      }
      if (1 < *(uint *)(ctx + 0x290)) {
        *(int *)(programRecord + 800) = regCursor;
        regCursor = regCursor + 1;
        *(undefined4 *)(paramList[2] * 4 + *paramList) = 0x13;
        *(undefined4 *)(paramList[2] * 4 + paramList[1]) = 0;
        paramList[2] = paramList[2] + 1;
      }
      if (((unsigned char *)0x00002d48)[stateBlockCopy + 4] != '\0') {
        if (7 < *(uint *)(ctx + 0x274)) {
          *(int *)(programRecord + 0x2fc) = regCursor;
          regCursor = regCursor + 1;
          *(undefined4 *)(paramList[2] * 4 + *paramList) = 0xe;
          *(undefined4 *)(paramList[2] * 4 + paramList[1]) = 1;
          paramList[2] = paramList[2] + 1;
        }
        if (7 < *(uint *)(ctx + 0x27c)) {
          *(int *)(programRecord + 0x300) = regCursor;
          regCursor = regCursor + 1;
          *(undefined4 *)(paramList[2] * 4 + *paramList) = 0xf;
          *(undefined4 *)(paramList[2] * 4 + paramList[1]) = 1;
          paramList[2] = paramList[2] + 1;
        }
        if (7 < *(uint *)(ctx + 0x284)) {
          *(int *)(programRecord + 0x304) = regCursor;
          regCursor = regCursor + 1;
          *(undefined4 *)(paramList[2] * 4 + *paramList) = 0x10;
          *(undefined4 *)(paramList[2] * 4 + paramList[1]) = 1;
          paramList[2] = paramList[2] + 1;
        }
        if (7 < *(uint *)(ctx + 0x28c)) {
          *(int *)(programRecord + 0x310) = regCursor;
          regCursor = regCursor + 1;
          *(undefined4 *)(paramList[2] * 4 + *paramList) = 0x11;
          *(undefined4 *)(paramList[2] * 4 + paramList[1]) = 1;
          paramList[2] = paramList[2] + 1;
        }
        if ((7 < *(uint *)(ctx + 0x274)) || (7 < *(uint *)(ctx + 0x27c))) {
          *(int *)(programRecord + 0x31c) = regCursor;
          regCursor = regCursor + 1;
          *(undefined4 *)(paramList[2] * 4 + *paramList) = 0x12;
          *(undefined4 *)(paramList[2] * 4 + paramList[1]) = 1;
          paramList[2] = paramList[2] + 1;
        }
        if (1 < *(uint *)(ctx + 0x294)) {
          *(int *)(programRecord + 0x324) = regCursor;
          regCursor = regCursor + 1;
          *(undefined4 *)(paramList[2] * 4 + *paramList) = 0x13;
          *(undefined4 *)(paramList[2] * 4 + paramList[1]) = 1;
          paramList[2] = paramList[2] + 1;
        }
      }
    }
    *(int *)(programRecord + 0x328) = regCursor;
    nextConstReg = regCursor + 1;
    *(undefined4 *)(paramList[2] * 4 + *paramList) = 0x14;
    *(undefined4 *)(paramList[2] * 4 + paramList[1]) = 0;
    paramList[2] = paramList[2] + 1;
    if (needsLightModelParam) {
      *(int *)(programRecord + 0x32c) = nextConstReg;
      nextConstReg = regCursor + 2;
      *(undefined4 *)(paramList[2] * 4 + *paramList) = 0x1b;
      *(undefined4 *)(paramList[2] * 4 + paramList[1]) = 0;
      paramList[2] = paramList[2] + 1;
      ctxFlags44 = *(uint *)(ctx + 0x44);
    }
    else {
      ctxFlags44 = *(uint *)(ctx + 0x44);
    }
  }
  if (((ctxFlags44 & 0x1000000) != 0) && (*(char *)(ctx + 0x121) == '\0')) {
    *(int *)(programRecord + 0x330) = nextConstReg;
    nextConstReg = nextConstReg + 1;
    *(undefined4 *)(paramList[2] * 4 + *paramList) = 0x15;
    *(undefined4 *)(paramList[2] * 4 + paramList[1]) = 0;
    paramList[2] = paramList[2] + 1;
  }
  if ((*(uint *)(ctx + 0x1874) & 0xc0000000) == 0x80000000) {
    *(int *)(programRecord + 0x334) = nextConstReg;
    regPlus1 = nextConstReg + 1;
    lastParamReg = nextConstReg + 2;
    nextConstReg = nextConstReg + 3;
    *(undefined4 *)(paramList[2] * 4 + *paramList) = 0x16;
    *(undefined4 *)(paramList[2] * 4 + paramList[1]) = 0;
    paramList[2] = paramList[2] + 1;
    *(int *)(programRecord + 0x338) = regPlus1;
    *(undefined4 *)(paramList[2] * 4 + *paramList) = 0x17;
    *(undefined4 *)(paramList[2] * 4 + paramList[1]) = 0;
    paramList[2] = paramList[2] + 1;
    *(int *)(programRecord + 0x340) = lastParamReg;
    *(undefined4 *)(paramList[2] * 4 + *paramList) = 0x18;
    *(undefined4 *)(paramList[2] * 4 + paramList[1]) = 0;
    paramList[2] = paramList[2] + 1;
  }
  if (*(char *)(ctx + 300) != '\0') {
    *(int *)(programRecord + 0x344) = nextConstReg;
    nextConstReg = nextConstReg + 1;
    *(undefined4 *)(paramList[2] * 4 + *paramList) = 0x19;
    *(undefined4 *)(paramList[2] * 4 + paramList[1]) = 0;
    paramList[2] = paramList[2] + 1;
  }
  *constRegCountOut = nextConstReg;
  if (((unsigned char *)0x00004301)[stateBlock] == '\0') {
    local_78 = GH_U2F((unsigned int)((stateBlock + 0x1960)));
    if ((((((local_74[0] == 0 && local_74[1] == 0) && local_74[2] == 0) &&
          FLOAT_001aa0e8 == local_78) &&
         (((local_74[3] == 0 && local_60 == 0) && local_5c == 0) && FLOAT_001aa0e8 == local_64)) &&
        (((local_58 == 0 && local_54 == 0) && local_4c == 0) && FLOAT_001aa0e8 == local_50)) &&
        (((local_48 == 0 && unaff_r17 == 0) && unaff_r18 == 0) && FLOAT_001aa0e8 == unaff_r19)) {
      FUN_00092d40(programRecord,ctxFlag400Active,ctxByte11d2);
    }
    else {
      ((int (*)())FUN_00095dd0)(programRecord,ctxFlag400Active,ctxByte11d2);
    }
    if (*(char *)(ctx + 0x12a) != '\0') {
      ((int (*)())FUN_00096500)(programRecord);
    }
  }
  else {
    tableCount = (uint)*(byte *)(ctx + 0x90);
    if (tableCount != 0) {
      genIndex = 0;
      texUnitEnableCursor = ctx;
      if (tableCount == 0) {
        tableCount = 1;
      }
      do {
        local_74[genIndex] = (uint)(byte)((unsigned char *)0x000013a9)[texUnitEnableCursor];
        tableCount = tableCount - 1;
        genIndex = genIndex + 1;
        texUnitEnableCursor = texUnitEnableCursor + 1;
      } while (tableCount != 0);
    }
    ((int (*)())FUN_000955e0)(programRecord,(uint)*(byte *)(ctx + 0x91),(uint)(byte)((unsigned char *)0x00004302)[stateBlock]);
    if (*(char *)(ctx + 0x129) == '\0') {
      ((int (*)())FUN_00093a40)(programRecord,local_74,(uint)*(byte *)(ctx + 0x91),
                   (uint)(byte)((unsigned char *)0x00004302)[stateBlock],ctxFlag400Active,ctxByte11d2);
    }
    else {
      ((int (*)())FUN_00094840)(programRecord,local_74,(uint)*(byte *)(ctx + 0x91),
                   (uint)(byte)((unsigned char *)0x00004302)[stateBlock],(uint)(*(char *)(ctx + 0x90) == '\x02'));
      ((int (*)())FUN_00095610)(programRecord,ctxFlag400Active,ctxByte11d2);
    }
    if (*(char *)(ctx + 0x12a) != '\0') {
      ((int (*)())FUN_00093510)(programRecord,local_74,(uint)*(byte *)(ctx + 0x91),
                   (uint)(byte)((unsigned char *)0x00004302)[stateBlock]);
    }
  }
  if (*(char *)(ctx + 0x128) == '\0') {
    if (*(char *)(ctx + 300) != '\0') {
      ((int (*)())FUN_000939e0)(programRecord);
    }
  }
  else {
    ((int (*)())FUN_00093a20)(programRecord);
  }
  ctxFlags44B = *(uint *)(ctx + 0x44);
  if ((((ctxFlags44B & 0x1000000) != 0) && (*(char *)(ctx + 0x121) == '\0')) &&
     ((*(int *)(programRecord + 0x3d8) == 0 || ((ctxFlags44B & 0x2000) == 0)))) {
    fogMode = *(short *)(((unsigned char *)0x00002e04) + stateBlock);
    if (fogMode == 0x801) {
      ((int (*)())FUN_00096540)(programRecord);
      ctxFlags44B = *(uint *)(ctx + 0x44);
    }
    else if (fogMode == 0x2601) {
      ((int (*)())FUN_0009af00)(programRecord);
      ctxFlags44B = *(uint *)(ctx + 0x44);
    }
    else if (fogMode == 0x800) {
      ((int (*)())FUN_0009b790)(programRecord);
      ctxFlags44B = *(uint *)(ctx + 0x44);
    }
  }
  if ((ctxFlags44B & 0x20000) == 0) {
    if ((*(uint *)(ctx + 0x8c) & 0x800000) == 0) goto LAB_0009e8dc;
    texUnitLimit = (uint)*(byte *)(ctx + 0x2b);
    if ((uint)(byte)((unsigned char *)0x000013b0)[ctx] < (uint)*(byte *)(ctx + 0x2b)) {
      texUnitLimit = (uint)(byte)((unsigned char *)0x000013b0)[ctx];
    }
    if (texUnitLimit == 0) goto LAB_0009e8dc;
    texUnitIndex = 0;
    texCoordMapPtr = (ushort *)(ctx + 0x187c);
    texUnitCtxCursor = ctx;
    texUnitEnableCursor = ctx;
    do {
      if (((unsigned char *)0x00001438)[texUnitEnableCursor] != '\0') {
        ((int (*)())FUN_00096600)(programRecord,texUnitIndex,0,texUnitIndex,(uint)*(byte *)(texUnitCtxCursor + 0x153),texUnitIndex,*texCoordMapPtr >> 2 & 0xfff
                    );
      }
      texUnitIndex = texUnitIndex + 1;
      texCoordMapPtr = texCoordMapPtr + 1;
      texUnitEnableCursor = texUnitEnableCursor + 1;
      texUnitCtxCursor = texUnitCtxCursor + 4;
    } while (texUnitLimit != texUnitIndex);
  }
  else {
    if ((ctxFlags44B & 0x2000) == 0) {
      lightEnableByte = ((unsigned char *)0x00001135)[ctx];
    }
    else {
      lightEnableByte = ((unsigned char *)0x000011d3)[ctx];
    }
    texUnitCount = (uint)(byte)((unsigned char *)0x000013b0)[ctx];
    if (texUnitCount == 0) goto LAB_0009e8dc;
    texUnitIndex = 0;
    texCoordMapPtr = (ushort *)(ctx + 0x187c);
    texUnitCtxCursor = ctx;
    do {
      if (((uint)lightEnableByte & 1 << (texUnitIndex & 0x3f)) != 0) {
        ((int (*)())FUN_00096600)(programRecord,texUnitIndex,0,texUnitIndex,(uint)*(byte *)(texUnitCtxCursor + 0x153),texUnitIndex,*texCoordMapPtr >> 2 & 0xfff
                    );
        texUnitCount = (uint)(byte)((unsigned char *)0x000013b0)[ctx];
      }
      texUnitIndex = texUnitIndex + 1;
      texCoordMapPtr = texCoordMapPtr + 1;
      texUnitCtxCursor = texUnitCtxCursor + 4;
    } while ((int)texUnitIndex < (int)texUnitCount);
  }
  ctxFlags44B = *(uint *)(ctx + 0x44);
LAB_0009e8dc:
  if ((int)ctxFlags44B < 0) {
    activeLightCount = 0;
    ((int (*)())FUN_00096d80)(programRecord);
    zeroConst = FLOAT_001aa0d4;
    lightMaskLoop = *(uint *)(ctx + 0x88);
    if (lightMaskLoop != 0) {
      activeLightCount = 0;
      lastActiveLight = 0;
      lightControlPtr = (uint *)(ctx + 0x3a8);
      lightMaskCopy = lightMaskLoop;
      do {
        if (((lightMaskCopy & 1) != 0) && ((*lightControlPtr & 0xfc000000) != 0)) {
          lastActiveLight = activeLightCount;
        }
        lightMaskCopy = lightMaskCopy >> 1;
        activeLightCount = activeLightCount + 1;
        lightControlPtr = lightControlPtr + 1;
      } while (lightMaskCopy != 0);
      activeLightCount = 0;
      emittedLightIndex = 0;
      lightControlPtr = (uint *)(ctx + 0x3a8);
      do {
        if (((lightMaskLoop & 1) != 0) && (lightMaskCopy = *lightControlPtr, (lightMaskCopy & 0xfc000000) != 0)) {
          if (*(float *)(stateBlock + 0x24fc) == zeroConst) {
            ((int (*)())FUN_00097440)(programRecord,emittedLightIndex,(uint)(activeLightCount == 0),(uint)(emittedLightIndex == lastActiveLight),lightMaskCopy >> 0x1e,
                         lightMaskCopy >> 0x1c & 3,lightMaskCopy >> 0x1a & 3);
          }
          else {
            ((int (*)())ffvpEmitLight)(programRecord,emittedLightIndex,(uint)(activeLightCount == 0),(uint)(emittedLightIndex == lastActiveLight),lightMaskCopy >> 0x19 & 1,
                         lightMaskCopy >> 0x18 & 1,lightMaskCopy >> 0x17 & 1,lightMaskCopy >> 0x1e,lightMaskCopy >> 0x1c & 3,
                         lightMaskCopy >> 0x1a & 3);
          }
          activeLightCount = activeLightCount + 1;
        }
        lightMaskLoop = lightMaskLoop >> 1;
        emittedLightIndex = emittedLightIndex + 1;
        lightControlPtr = lightControlPtr + 1;
        stateBlock = stateBlock + 0x80;
      } while (lightMaskLoop != 0);
    }
    ((int (*)())FUN_0009b430)(programRecord,activeLightCount);
  }
  else {
    FUN_00092ea0(programRecord,3,0,0);
    if ((*(uint *)(ctx + 0x44) & 0xa10000) != 0) {
      FUN_00092ea0(programRecord,4,1,0);
    }
  }
  if ((*(uint *)(ctx + 0x1874) & 0xc0000000) == 0x80000000) {
    ((int (*)())FUN_00099e50)(programRecord,2,(uint)(*(float *)(ctx + 0x114) == FLOAT_001aa0d4));
  }
  if ((*(uint *)(ctx + 0x44) & 0x800) == 0) {
    if (*(char *)(ctx + 0x121) != '\0') {
      ((int (*)())FUN_0009b850)(programRecord,(uint)*(byte *)(ctx + 0x120));
    }
  }
  else if (*(int *)(programRecord + 0x3d8) == 0) {
    ((int (*)())FUN_0009b850)(programRecord,(uint)(byte)((unsigned char *)0x000011d1)[ctx]);
  }
  else {
    ((int (*)())FUN_0009a590)(programRecord);
  }
  programTypeResult = ((int (*)())FUN_0009a910)(programRecord);
  if (programTypeResult == 6) {
    *(undefined1 *)(ctx + 0x126) = 1;
  }
  return programRecord;
}

/* fpVariantCacheGrow @ 0x9eb90 (560 bytes) */
int fpVariantCacheGrow(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  uint *puVar6;
  uint uVar7;
  uint *puVar8;
  uint *puVar9;
  uint *puVar10;
  int iVar11;
  int loopIndex;
  
  iVar11 = *(int *)(((unsigned char *)0x0000111c) + param_1);
  if (iVar11 != 0xfb2f) {
    *(int *)(((unsigned char *)0x0000111c) + param_1) = iVar11 + param_2;
    if (0xfb2f < (uint)(iVar11 + param_2)) {
      *(undefined4 *)(((unsigned char *)0x0000111c) + param_1) = 0xfb2f;
    }
    iVar3 = (**(code **)(param_1 + 0x10))(1,*(int *)(((unsigned char *)0x0000111c) + param_1) << 2);
    if (iVar11 == 0) {
      iVar4 = *(int *)(((unsigned char *)0x00001118) + param_1);
    }
    else {
      iVar4 = *(int *)(((unsigned char *)0x00001118) + param_1);
      loopIndex = 0;
      do {
        puVar5 = *(uint **)(loopIndex * 4 + iVar4);
        if (puVar5 != (uint *)0x0) {
          do {
            puVar10 = puVar5 + 0xc;
            if (puVar10 < puVar5 + 0xb) {
              uVar7 = 0;
              puVar6 = puVar5;
            }
            else {
              uVar7 = 0;
              puVar9 = puVar5 + 0xb;
              puVar8 = puVar5;
              do {
                puVar6 = puVar9;
                uVar7 = uVar7 ^ *puVar8 ^ (puVar8[1] << 3 | puVar8[1] >> 0x1d) ^
                        (puVar8[2] << 6 | puVar8[2] >> 0x1a) ^ (puVar8[3] << 9 | puVar8[3] >> 0x17)
                        ^ (puVar8[4] << 0xc | puVar8[4] >> 0x14) ^
                        (puVar8[5] << 0xf | puVar8[5] >> 0x11) ^
                        (puVar8[6] << 0x12 | puVar8[6] >> 0xe) ^
                        (puVar8[7] << 0x15 | puVar8[7] >> 0xb) ^
                        (puVar8[8] << 0x18 | puVar8[8] >> 8) ^ (puVar8[9] << 0x1b | puVar8[9] >> 5)
                        ^ (puVar8[10] << 0x1e | puVar8[10] >> 2);
                puVar9 = puVar6 + 0xb;
                puVar8 = puVar6;
              } while (puVar6 + 0xb <= puVar10);
            }
            puVar9 = puVar6 + 5;
            if (puVar10 < puVar9) {
              uVar2 = 0;
              puVar9 = puVar6;
            }
            else {
              uVar2 = 0xf;
              uVar7 = uVar7 ^ *puVar6 ^ (puVar6[1] << 3 | puVar6[1] >> 0x1d) ^
                      (puVar6[2] << 6 | puVar6[2] >> 0x1a) ^ (puVar6[3] << 9 | puVar6[3] >> 0x17) ^
                      (puVar6[4] << 0xc | puVar6[4] >> 0x14);
            }
            for (; puVar9 < puVar10; puVar9 = puVar9 + 1) {
              uVar1 = uVar2 & 0x1f;
              uVar2 = uVar2 + 3;
              uVar7 = uVar7 ^ (*puVar9 << uVar1 | *puVar9 >> 0x20 - uVar1);
            }
            puVar10 = (uint *)puVar5[0x17];
            iVar4 = (uVar7 - (uVar7 / *(uint *)(((unsigned char *)0x0000111c) + param_1)) *
                             *(uint *)(((unsigned char *)0x0000111c) + param_1)) * 4;
            puVar5[0x17] = *(uint *)(iVar3 + iVar4);
            *(uint **)(iVar3 + iVar4) = puVar5;
            puVar5 = puVar10;
          } while (puVar10 != (uint *)0x0);
          iVar4 = *(int *)(((unsigned char *)0x00001118) + param_1);
        }
        loopIndex = loopIndex + 1;
      } while (iVar11 != loopIndex);
    }
    (**(code **)(param_1 + 0x18))(iVar4);
    *(int *)(((unsigned char *)0x00001118) + param_1) = iVar3;
  }
  return;
}

/* FUN_0009edd0 @ 0x9edd0 (708 bytes) */
int FUN_0009edd0(param_1, param_2)
  int param_1;
  uint *param_2;
{
  bool bVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int compareResult;
  uint *puVar8;
  uint *puVar9;
  uint uVar10;
  int loopIndex;
  
  bVar1 = ((unsigned char *)0x00001120)[param_1] == '\0';
  if (bVar1) {
    puVar8 = param_2 + 0xc;
    uVar10 = *(uint *)(((unsigned char *)0x0000111c) + param_1);
    uVar4 = 0;
    puVar3 = param_2;
    while (puVar3 + 0xb <= puVar8) {
      uVar4 = uVar4 ^ *puVar3 ^ (puVar3[1] << 3 | puVar3[1] >> 0x1d) ^
              (puVar3[2] << 6 | puVar3[2] >> 0x1a) ^ (puVar3[3] << 9 | puVar3[3] >> 0x17) ^
              (puVar3[4] << 0xc | puVar3[4] >> 0x14) ^ (puVar3[5] << 0xf | puVar3[5] >> 0x11) ^
              (puVar3[6] << 0x12 | puVar3[6] >> 0xe) ^ (puVar3[7] << 0x15 | puVar3[7] >> 0xb) ^
              (puVar3[8] << 0x18 | puVar3[8] >> 8) ^ (puVar3[9] << 0x1b | puVar3[9] >> 5) ^
              (puVar3[10] << 0x1e | puVar3[10] >> 2);
      puVar3 = puVar3 + 0xb;
    }
    puVar9 = puVar3 + 5;
    if (puVar8 < puVar9) {
      uVar6 = 0;
      puVar9 = puVar3;
    }
    else {
      uVar6 = 0xf;
      uVar4 = uVar4 ^ *puVar3 ^ (puVar3[1] << 3 | puVar3[1] >> 0x1d) ^
              (puVar3[2] << 6 | puVar3[2] >> 0x1a) ^ (puVar3[3] << 9 | puVar3[3] >> 0x17) ^
              (puVar3[4] << 0xc | puVar3[4] >> 0x14);
    }
    for (; puVar9 < puVar8; puVar9 = puVar9 + 1) {
      uVar2 = uVar6 & 0x1f;
      uVar6 = uVar6 + 3;
      uVar4 = uVar4 ^ (*puVar9 << uVar2 | *puVar9 >> 0x20 - uVar2);
    }
    iVar5 = uVar4 - (uVar4 / uVar10) * uVar10;
  }
  else {
    uVar10 = *(uint *)(((unsigned char *)0x0000111c) + param_1);
    uVar4 = *param_2 + param_2[2] + param_2[3];
    iVar5 = uVar4 - (uVar4 / uVar10) * uVar10;
  }
  iVar5 = *(int *)(iVar5 * 4 + *(int *)(((unsigned char *)0x00001118) + param_1));
  if (*(char *)(param_1 + 0x2f) == '\0') {
    loopIndex = 0;
    if (iVar5 != 0) {
      do {
        compareResult = _memcmp(iVar5,param_2,0x30);
        if (compareResult == 0) {
          return iVar5;
        }
        iVar5 = *(int *)(iVar5 + 0x5c);
        loopIndex = loopIndex + 1;
      } while (iVar5 != 0);
      goto LAB_0009f014;
    }
  }
  else {
    loopIndex = 0;
    if (iVar5 != 0) {
      do {
        compareResult = _memcmp(iVar5,param_2,0x18);
        if (compareResult == 0) {
          return iVar5;
        }
        iVar5 = *(int *)(iVar5 + 0x5c);
        loopIndex = loopIndex + 1;
      } while (iVar5 != 0);
      goto LAB_0009f014;
    }
  }
  loopIndex = 0;
LAB_0009f014:
  if ((bVar1) || (loopIndex < 5)) {
    if ((loopIndex < 8) || (0xfb2e < uVar10)) {
      return 0;
    }
    if (bVar1) {
      ((int (*)())fpVariantCacheGrow)(param_1,0x859);
      return 0;
    }
  }
  ((int (*)())fpVariantCacheGrow)(param_1,0);
  ((unsigned char *)0x00001120)[param_1] = 0;
  return 0;
}

/* programFillStateConstants @ 0x9f0b0 (4444 bytes) */
void programFillStateConstants(int ctx,int program,undefined4 unusedArg3,undefined4 unusedArg4,undefined4 unusedArg5,undefined4 unusedArg6,undefined4 unusedArg7,undefined4 unusedArg8,double scratchProduct,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  undefined4 slotAlt01;
  undefined4 mvpCopy31;
  undefined4 slotAlt12;
  undefined4 mvpCopy12;
  undefined4 slotAlt23;
  undefined4 mvpCopy02;
  undefined4 slotAlt02;
  undefined4 mvpCopy22;
  undefined4 slotAlt13;
  undefined4 mvpCopy03;
  undefined4 slotAlt03;
  undefined4 mvpCopy23;
  undefined4 slotAlt33;
  undefined4 mvpCopy13;
  undefined4 slotAlt20;
  undefined4 mvpCopy10;
  uint texUnit;
  undefined4 slotAlt31;
  undefined4 mvpCopy20;
  undefined4 slotAlt10;
  undefined4 mvpCopy30;
  undefined4 slotAlt21;
  undefined4 mvpCopy01;
  undefined4 slotAlt32;
  undefined4 mvpCopy21;
  undefined4 slotAlt11;
  undefined4 mvpCopy11;
  undefined4 slotAlt22;
  undefined4 mvpCopy32;
  undefined4 slotAlt30;
  undefined4 mvpCopy33;
  int materialState;
  int lightState2;
  int ctxUnitState;
  int slotMatrixAlt;
  int texUnitState;
  int constDest;
  int ctxVec4Entry;
  int lightState;
  int constIndex;
  int constOffset;
  float stateF24a4;
  float minor2;
  float invSrc10;
  float invSrc30;
  float invSrc20;
  float invSrc31;
  float mulSlot32;
  float mulSlot22;
  float mulSlot12;
  float invSrc21;
  float invSrc11;
  float invDeterminant;
  float invSrc01;
  float invSrc00;
  float mulSlot33;
  float mulSlot23;
  float mulSlot13;
  float minor6;
  float mulSlot31;
  float mulSlot21;
  float mulSlot11;
  float minor5;
  float minor4;
  float minor3;
  double minor13;
  double mulSlot30;
  double mulSlot20;
  double mulSlot10;
  double invSrc23;
  double minor8;
  double minor7;
  double invSrc13;
  float mvp11;
  float mvp12;
  float mvp13;
  float mulSlot01;
  float mvp32;
  float mulSlot03;
  float mvp20;
  float mvp21;
  float mvp22;
  float mvp23;
  float mulSlot02;
  float mvp33;
  float mvp30;
  float mvp31;
  float mvp10;
  uint texGenComponent;
  undefined4 copySlot32;
  int paramMap;
  undefined4 copySlot11;
  undefined4 copySlot21;
  undefined4 copySlot01;
  undefined4 copySlot30;
  undefined4 copySlot20;
  undefined4 copySlot33;
  int slotMatrix;
  undefined8 *texGenPlane;
  uint paramCount;
  int slotMatrixCopy;
  undefined4 copySlot10;
  int constAddr;
  int ctxState;
  uint paramIndex;
  int paramMapEntries;
  int paramOffset;
  int stateBlock;
  int constantBuffer;
  undefined4 copySlot13;
  undefined4 copySlot23;
  undefined4 copySlot03;
  undefined4 copySlot22;
  undefined4 copySlot02;
  undefined4 copySlot12;
  undefined4 copySlot31;
  uint elementIndex;
  int *paramList;
  undefined8 valueXY;
  double mvp03;
  double mvp02;
  double mvp01;
  double mvp00;
  double minor11;
  double mulSlot00;
  double minor10;
  double minor12;
  double minor9;
  undefined8 valueZW;
  double invSrc33;
  double invSrc32;
  double invSrc03;
  double invSrc12;
  double invSrc02;
  double invSrc22;
  float stateVecX;
  float stateVecY;
  float stateVecZ;
  undefined4 stateVecW;
  float result00;
  float result10;
  float result20;
  float result30;
  float result01;
  float result11;
  float result21;
  float result31;
  float result02;
  float result12;
  float result22;
  float result32;
  float result03;
  float result13;
  float result23;
  float result33;
  undefined4 intToDoubleHiA;
  uint intToDoubleLoA;
  undefined4 intToDoubleHiB;
  uint intToDoubleLoB;
  float minor1;
  float cofactor30;
  float cofactor20;
  float cofactor10;
  float cofactor00;
  float determinant;
  float minorProduct;
  
  paramList = *(int **)(program + 0x50);
  ctxState = *(int *)(ctx + 4);
  paramMap = *(int *)(program + 0x54);
  constantBuffer = *(int *)(program + 0x4c);
  paramCount = paramList[2];
  stateBlock = *(int *)(ctxState + 0x10);
  paramMapEntries = paramMap + 0xa4;
  if (paramCount != 0) {
    paramIndex = 0;
    paramOffset = 0;
    do {
      elementIndex = *(uint *)(paramList[1] + paramOffset);
      switch(*(undefined4 *)(*paramList + paramOffset)) {
      case 0:
        mvp00 = (double)*(float *)(stateBlock + 0x1920);
        slotMatrix = stateBlock + 0x1860 + elementIndex * 0x40;
        mvp10 = *(float *)(stateBlock + 0x1930);
        mvp11 = *(float *)(stateBlock + 0x1934);
        mvp12 = *(float *)(stateBlock + 0x1938);
        mvp13 = *(float *)(stateBlock + 0x193c);
        mulSlot00 = (double)*(float *)(slotMatrix + 0x100);
        mvp01 = (double)*(float *)(stateBlock + 0x1924);
        mulSlot01 = *(float *)(slotMatrix + 0x104);
        mvp02 = (double)*(float *)(stateBlock + 0x1928);
        mvp03 = (double)*(float *)(stateBlock + 0x192c);
        mvp20 = *(float *)(stateBlock + 0x1940);
        mvp21 = *(float *)(stateBlock + 0x1944);
        mvp22 = *(float *)(stateBlock + 0x1948);
        mvp23 = *(float *)(stateBlock + 0x194c);
        mulSlot02 = *(float *)(slotMatrix + 0x108);
        mvp33 = *(float *)(stateBlock + 0x195c);
        mvp30 = *(float *)(stateBlock + 0x1950);
        mvp31 = *(float *)(stateBlock + 0x1954);
        mvp32 = *(float *)(stateBlock + 0x1958);
        mulSlot03 = *(float *)(slotMatrix + 0x10c);
        result30 = mvp33 * mulSlot03 +
                    mvp23 * mulSlot02 + (float)(mvp03 * mulSlot00 + (double)(mvp13 * mulSlot01));
        result00 = mvp30 * mulSlot03 +
                    mvp20 * mulSlot02 + (float)(mvp00 * mulSlot00 + (double)(mvp10 * mulSlot01));
        result10 = mvp31 * mulSlot03 +
                    mvp21 * mulSlot02 + (float)(mvp01 * mulSlot00 + (double)(mvp11 * mulSlot01));
        result20 = mvp32 * mulSlot03 +
                    mvp22 * mulSlot02 + (float)(mvp02 * mulSlot00 + (double)(mvp12 * mulSlot01));
        mulSlot11 = *(float *)(slotMatrix + 0x114);
        mulSlot10 = (double)*(float *)(slotMatrix + 0x110);
        mulSlot12 = *(float *)(slotMatrix + 0x118);
        mulSlot13 = *(float *)(slotMatrix + 0x11c);
        result31 = mvp33 * mulSlot13 +
                    mvp23 * mulSlot12 + (float)(mvp03 * mulSlot10 + (double)(mvp13 * mulSlot11));
        result01 = mvp30 * mulSlot13 +
                    mvp20 * mulSlot12 + (float)(mvp00 * mulSlot10 + (double)(mvp10 * mulSlot11));
        result11 = mvp31 * mulSlot13 +
                    mvp21 * mulSlot12 + (float)(mvp01 * mulSlot10 + (double)(mvp11 * mulSlot11));
        result21 = mvp32 * mulSlot13 +
                    mvp22 * mulSlot12 + (float)(mvp02 * mulSlot10 + (double)(mvp12 * mulSlot11));
        mulSlot21 = *(float *)(slotMatrix + 0x124);
        mulSlot20 = (double)*(float *)(slotMatrix + 0x120);
        mulSlot22 = *(float *)(slotMatrix + 0x128);
        mulSlot23 = *(float *)(slotMatrix + 300);
        result32 = mvp33 * mulSlot23 +
                    mvp23 * mulSlot22 + (float)(mvp03 * mulSlot20 + (double)(mvp13 * mulSlot21));
        result02 = mvp30 * mulSlot23 +
                    mvp20 * mulSlot22 + (float)(mvp00 * mulSlot20 + (double)(mvp10 * mulSlot21));
        result12 = mvp31 * mulSlot23 +
                    mvp21 * mulSlot22 + (float)(mvp01 * mulSlot20 + (double)(mvp11 * mulSlot21));
        result22 = mvp32 * mulSlot23 +
                    mvp22 * mulSlot22 + (float)(mvp02 * mulSlot20 + (double)(mvp12 * mulSlot21));
        mulSlot31 = *(float *)(slotMatrix + 0x134);
        mulSlot30 = (double)*(float *)(slotMatrix + 0x130);
        mulSlot32 = *(float *)(slotMatrix + 0x138);
        mulSlot33 = *(float *)(slotMatrix + 0x13c);
        scratchProduct = (double)(mvp11 * mulSlot31);
        result33 = mvp33 * mulSlot33 +
                    mvp23 * mulSlot32 + (float)(mvp03 * mulSlot30 + (double)(mvp13 * mulSlot31));
        result03 = mvp30 * mulSlot33 +
                    mvp20 * mulSlot32 + (float)(mvp00 * mulSlot30 + (double)(mvp10 * mulSlot31));
        result13 = mvp31 * mulSlot33 + mvp21 * mulSlot32 + (float)(mvp01 * mulSlot30 + scratchProduct);
        result23 = mvp32 * mulSlot33 +
                    mvp22 * mulSlot32 + (float)(mvp02 * mulSlot30 + (double)(mvp12 * mulSlot31));
        constOffset = *(int *)(elementIndex * 4 + paramMapEntries) * 0x10;
        constAddr = constantBuffer + constOffset;
        if ((*(uint *)(((unsigned char *)0x000013c0) + ctx) & 4) == 0) {
          *(float *)(constantBuffer + constOffset) = result00;
          *(float *)(constAddr + 0x3c) = result33;
          *(float *)(constAddr + 4) = result01;
          *(float *)(constAddr + 8) = result02;
          *(float *)(constAddr + 0xc) = result03;
          *(float *)(constAddr + 0x10) = result10;
          *(float *)(constAddr + 0x14) = result11;
          *(float *)(constAddr + 0x18) = result12;
          *(float *)(constAddr + 0x1c) = result13;
          *(float *)(constAddr + 0x20) = result20;
          *(float *)(constAddr + 0x24) = result21;
          *(float *)(constAddr + 0x28) = result22;
          *(float *)(constAddr + 0x2c) = result23;
          *(float *)(constAddr + 0x30) = result30;
          *(float *)(constAddr + 0x34) = result31;
          *(float *)(constAddr + 0x38) = result32;
          paramCount = paramList[2];
        }
        else {
          *(float *)(constantBuffer + constOffset) = result00;
          *(float *)(constAddr + 0x3c) = result33;
          *(float *)(constAddr + 4) = result10;
          *(float *)(constAddr + 8) = result20;
          *(float *)(constAddr + 0xc) = result30;
          *(float *)(constAddr + 0x10) = result01;
          *(float *)(constAddr + 0x14) = result11;
          *(float *)(constAddr + 0x18) = result21;
          *(float *)(constAddr + 0x1c) = result31;
          *(float *)(constAddr + 0x20) = result02;
          *(float *)(constAddr + 0x24) = result12;
          *(float *)(constAddr + 0x28) = result22;
          *(float *)(constAddr + 0x2c) = result32;
          *(float *)(constAddr + 0x30) = result03;
          *(float *)(constAddr + 0x34) = result13;
          *(float *)(constAddr + 0x38) = result23;
          paramCount = paramList[2];
        }
        break;
      case 1:
        slotMatrixCopy = stateBlock + 0x1860 + elementIndex * 0x40;
        constOffset = *(int *)(elementIndex * 4 + paramMapEntries + 0x10) * 0x10;
        copySlot01 = *(undefined4 *)(slotMatrixCopy + 0x104);
        copySlot33 = *(undefined4 *)(slotMatrixCopy + 0x13c);
        constAddr = constantBuffer + constOffset;
        copySlot02 = *(undefined4 *)(slotMatrixCopy + 0x108);
        copySlot03 = *(undefined4 *)(slotMatrixCopy + 0x10c);
        copySlot10 = *(undefined4 *)(slotMatrixCopy + 0x110);
        copySlot11 = *(undefined4 *)(slotMatrixCopy + 0x114);
        copySlot12 = *(undefined4 *)(slotMatrixCopy + 0x118);
        copySlot13 = *(undefined4 *)(slotMatrixCopy + 0x11c);
        copySlot20 = *(undefined4 *)(slotMatrixCopy + 0x120);
        copySlot21 = *(undefined4 *)(slotMatrixCopy + 0x124);
        copySlot22 = *(undefined4 *)(slotMatrixCopy + 0x128);
        copySlot23 = *(undefined4 *)(slotMatrixCopy + 300);
        copySlot30 = *(undefined4 *)(slotMatrixCopy + 0x130);
        copySlot31 = *(undefined4 *)(slotMatrixCopy + 0x134);
        copySlot32 = *(undefined4 *)(slotMatrixCopy + 0x138);
        if ((*(uint *)(((unsigned char *)0x000013c0) + ctx) & 4) == 0) {
          *(undefined4 *)(constantBuffer + constOffset) = *(undefined4 *)(slotMatrixCopy + 0x100);
          *(undefined4 *)(constAddr + 0x3c) = copySlot33;
          *(undefined4 *)(constAddr + 4) = copySlot10;
          *(undefined4 *)(constAddr + 8) = copySlot20;
          *(undefined4 *)(constAddr + 0xc) = copySlot30;
          *(undefined4 *)(constAddr + 0x10) = copySlot01;
          *(undefined4 *)(constAddr + 0x14) = copySlot11;
          *(undefined4 *)(constAddr + 0x18) = copySlot21;
          *(undefined4 *)(constAddr + 0x1c) = copySlot31;
          *(undefined4 *)(constAddr + 0x20) = copySlot02;
          *(undefined4 *)(constAddr + 0x24) = copySlot12;
          *(undefined4 *)(constAddr + 0x28) = copySlot22;
          *(undefined4 *)(constAddr + 0x2c) = copySlot32;
          *(undefined4 *)(constAddr + 0x30) = copySlot03;
          *(undefined4 *)(constAddr + 0x34) = copySlot13;
          *(undefined4 *)(constAddr + 0x38) = copySlot23;
          paramCount = paramList[2];
        }
        else {
          *(undefined4 *)(constantBuffer + constOffset) = *(undefined4 *)(slotMatrixCopy + 0x100);
          *(undefined4 *)(constAddr + 0x3c) = copySlot33;
          *(undefined4 *)(constAddr + 4) = copySlot01;
          *(undefined4 *)(constAddr + 8) = copySlot02;
          *(undefined4 *)(constAddr + 0xc) = copySlot03;
          *(undefined4 *)(constAddr + 0x10) = copySlot10;
          *(undefined4 *)(constAddr + 0x14) = copySlot11;
          *(undefined4 *)(constAddr + 0x18) = copySlot12;
          *(undefined4 *)(constAddr + 0x1c) = copySlot13;
          *(undefined4 *)(constAddr + 0x20) = copySlot20;
          *(undefined4 *)(constAddr + 0x24) = copySlot21;
          *(undefined4 *)(constAddr + 0x28) = copySlot22;
          *(undefined4 *)(constAddr + 0x2c) = copySlot23;
          *(undefined4 *)(constAddr + 0x30) = copySlot30;
          *(undefined4 *)(constAddr + 0x34) = copySlot31;
          *(undefined4 *)(constAddr + 0x38) = copySlot32;
          paramCount = paramList[2];
        }
        break;
      case 2:
        slotMatrix = stateBlock + 0x1860 + elementIndex * 0x40;
        invSrc00 = *(float *)(slotMatrix + 0x100);
        invSrc32 = (double)*(float *)(slotMatrix + 0x138);
        invSrc13 = (double)*(float *)(slotMatrix + 0x11c);
        invSrc12 = (double)*(float *)(slotMatrix + 0x118);
        invSrc33 = (double)*(float *)(slotMatrix + 0x13c);
        invSrc03 = (double)*(float *)(slotMatrix + 0x10c);
        invSrc02 = (double)*(float *)(slotMatrix + 0x108);
        invSrc22 = (double)*(float *)(slotMatrix + 0x128);
        invSrc01 = *(float *)(slotMatrix + 0x104);
        invSrc11 = *(float *)(slotMatrix + 0x114);
        invSrc21 = *(float *)(slotMatrix + 0x124);
        minor1 = (float)(invSrc12 * invSrc33 - (double)(float)(invSrc13 * invSrc32));
        minor2 = (float)(invSrc02 * invSrc33 - (double)(float)(invSrc03 * invSrc32));
        minor3 = (float)(invSrc02 * invSrc13 - (double)(float)(invSrc03 * invSrc12));
        invSrc23 = (double)*(float *)(slotMatrix + 300);
        invSrc31 = *(float *)(slotMatrix + 0x134);
        invSrc20 = *(float *)(slotMatrix + 0x120);
        minor4 = (float)(invSrc02 * invSrc23 - (double)(float)(invSrc03 * invSrc22));
        minor5 = (float)(invSrc12 * invSrc23 - (double)(float)(invSrc13 * invSrc22));
        cofactor20 = invSrc31 * minor3 + (invSrc01 * minor1 - invSrc11 * minor2);
        minor6 = (float)(invSrc22 * invSrc33 - (double)(float)(invSrc23 * invSrc32));
        minor7 = (double)(invSrc00 * invSrc21 - invSrc01 * invSrc20);
        cofactor30 = -(invSrc01 * minor5 - (invSrc11 * minor4 - invSrc21 * minor3));
        cofactor10 = -(invSrc01 * minor6 - (invSrc21 * minor2 - invSrc31 * minor4));
        cofactor00 = invSrc31 * minor5 + (invSrc11 * minor6 - invSrc21 * minor1);
        invSrc30 = *(float *)(slotMatrix + 0x130);
        invSrc10 = *(float *)(slotMatrix + 0x110);
        minor8 = (double)(invSrc10 * invSrc21 - invSrc11 * invSrc20);
        minor9 = (double)(invSrc00 * invSrc31 - invSrc01 * invSrc30);
        minor10 = (double)(invSrc00 * invSrc11 - invSrc01 * invSrc10);
        minor11 = (double)(invSrc10 * invSrc31 - invSrc11 * invSrc30);
        minor12 = (double)(invSrc20 * invSrc31 - invSrc21 * invSrc30);
        determinant = invSrc00 * cofactor00 + invSrc10 * cofactor10 + invSrc30 * cofactor30 + invSrc20 * cofactor20;
        minorProduct = (float)(minor11 * invSrc23);
        scratchProduct = (double)(float)(minor7 * invSrc13 - (double)(float)(minor10 * invSrc23));
        minor13 = minor8 * invSrc03 - scratchProduct;
        if (determinant != FLOAT_001aa0d4) {
          invDeterminant = FLOAT_001aa0e8 / determinant;
          result00 = cofactor00 * invDeterminant;
          result02 = cofactor20 * invDeterminant;
          result01 = cofactor10 * invDeterminant;
          result30 = -(float)(minor12 * invSrc12 -
                              (double)(float)(minor11 * invSrc22 - (double)(float)(minor8 * invSrc32))) *
                      invDeterminant;
          result33 = (float)(minor10 * invSrc22 +
                             (double)(float)(minor8 * invSrc02 - (double)(float)(minor7 * invSrc12))) *
                      invDeterminant;
          result10 = invDeterminant * -(invSrc10 * minor6 - (invSrc20 * minor1 - invSrc30 * minor5));
          result20 = (float)(minor8 * invSrc33 + (double)(float)(minor12 * invSrc13 - (double)minorProduct))
                      * invDeterminant;
          result11 = invDeterminant * (invSrc30 * minor4 + (invSrc00 * minor6 - invSrc20 * minor2));
          result21 = -(float)(minor12 * invSrc03 -
                              (double)(float)(minor9 * invSrc23 - (double)(float)(minor7 * invSrc33))) *
                      invDeterminant;
          result12 = invDeterminant * -(invSrc00 * minor1 - (invSrc10 * minor2 - invSrc30 * minor3));
          result31 = (float)(minor7 * invSrc32 +
                             (double)(float)(minor12 * invSrc02 - (double)(float)(minor9 * invSrc22))) *
                      invDeterminant;
          result13 = invDeterminant * (invSrc20 * minor3 + (invSrc00 * minor5 - invSrc10 * minor4));
          result03 = cofactor30 * invDeterminant;
          result32 = -(float)(minor11 * invSrc02 -
                              (double)(float)(minor9 * invSrc12 - (double)(float)(minor10 * invSrc32))) *
                      invDeterminant;
          result22 = (float)(minor10 * invSrc33 +
                             (double)(float)(minor11 * invSrc03 - (double)(float)(minor9 * invSrc13))) *
                      invDeterminant;
          scratchProduct = (double)result22;
          result23 = -(float)minor13 * invDeterminant;
        }
        constOffset = *(int *)(elementIndex * 4 + paramMapEntries + 0x20) * 0x10;
        constAddr = constantBuffer + constOffset;
        *(float *)(constantBuffer + constOffset) = result00;
        *(float *)(constAddr + 0x3c) = result33;
        *(float *)(constAddr + 4) = result01;
        *(float *)(constAddr + 8) = result02;
        *(float *)(constAddr + 0xc) = result03;
        *(float *)(constAddr + 0x10) = result10;
        *(float *)(constAddr + 0x14) = result11;
        *(float *)(constAddr + 0x18) = result12;
        *(float *)(constAddr + 0x1c) = result13;
        *(float *)(constAddr + 0x20) = result20;
        *(float *)(constAddr + 0x24) = result21;
        *(float *)(constAddr + 0x28) = result22;
        *(float *)(constAddr + 0x2c) = result23;
        *(float *)(constAddr + 0x30) = result30;
        *(float *)(constAddr + 0x34) = result31;
        *(float *)(constAddr + 0x38) = result32;
        paramCount = paramList[2];
        break;
      case 3:
        mvpCopy01 = *(undefined4 *)(stateBlock + 0x1924);
        mvpCopy02 = *(undefined4 *)(stateBlock + 0x1928);
        mvpCopy03 = *(undefined4 *)(stateBlock + 0x192c);
        mvpCopy11 = *(undefined4 *)(stateBlock + 0x1934);
        constOffset = *(int *)(paramMap + 0xd4) * 0x10;
        mvpCopy33 = *(undefined4 *)(stateBlock + 0x195c);
        mvpCopy10 = *(undefined4 *)(stateBlock + 0x1930);
        mvpCopy12 = *(undefined4 *)(stateBlock + 0x1938);
        mvpCopy13 = *(undefined4 *)(stateBlock + 0x193c);
        mvpCopy20 = *(undefined4 *)(stateBlock + 0x1940);
        constAddr = constantBuffer + constOffset;
        mvpCopy21 = *(undefined4 *)(stateBlock + 0x1944);
        mvpCopy22 = *(undefined4 *)(stateBlock + 0x1948);
        mvpCopy23 = *(undefined4 *)(stateBlock + 0x194c);
        mvpCopy30 = *(undefined4 *)(stateBlock + 0x1950);
        mvpCopy31 = *(undefined4 *)(stateBlock + 0x1954);
        mvpCopy32 = *(undefined4 *)(stateBlock + 0x1958);
        if ((*(uint *)(((unsigned char *)0x000013c0) + ctx) & 4) == 0) {
          *(undefined4 *)(constantBuffer + constOffset) = *(undefined4 *)(stateBlock + 0x1920);
          *(undefined4 *)(constAddr + 0x3c) = mvpCopy33;
          *(undefined4 *)(constAddr + 4) = mvpCopy10;
          *(undefined4 *)(constAddr + 8) = mvpCopy20;
          *(undefined4 *)(constAddr + 0xc) = mvpCopy30;
          *(undefined4 *)(constAddr + 0x10) = mvpCopy01;
          *(undefined4 *)(constAddr + 0x14) = mvpCopy11;
          *(undefined4 *)(constAddr + 0x18) = mvpCopy21;
          *(undefined4 *)(constAddr + 0x1c) = mvpCopy31;
          *(undefined4 *)(constAddr + 0x20) = mvpCopy02;
          *(undefined4 *)(constAddr + 0x24) = mvpCopy12;
          *(undefined4 *)(constAddr + 0x28) = mvpCopy22;
          *(undefined4 *)(constAddr + 0x2c) = mvpCopy32;
          *(undefined4 *)(constAddr + 0x30) = mvpCopy03;
          *(undefined4 *)(constAddr + 0x34) = mvpCopy13;
          *(undefined4 *)(constAddr + 0x38) = mvpCopy23;
          paramCount = paramList[2];
        }
        else {
          *(undefined4 *)(constantBuffer + constOffset) = *(undefined4 *)(stateBlock + 0x1920);
          *(undefined4 *)(constAddr + 0x3c) = mvpCopy33;
          *(undefined4 *)(constAddr + 4) = mvpCopy01;
          *(undefined4 *)(constAddr + 8) = mvpCopy02;
          *(undefined4 *)(constAddr + 0xc) = mvpCopy03;
          *(undefined4 *)(constAddr + 0x10) = mvpCopy10;
          *(undefined4 *)(constAddr + 0x14) = mvpCopy11;
          *(undefined4 *)(constAddr + 0x18) = mvpCopy12;
          *(undefined4 *)(constAddr + 0x1c) = mvpCopy13;
          *(undefined4 *)(constAddr + 0x20) = mvpCopy20;
          *(undefined4 *)(constAddr + 0x24) = mvpCopy21;
          *(undefined4 *)(constAddr + 0x28) = mvpCopy22;
          *(undefined4 *)(constAddr + 0x2c) = mvpCopy23;
          *(undefined4 *)(constAddr + 0x30) = mvpCopy30;
          *(undefined4 *)(constAddr + 0x34) = mvpCopy31;
          *(undefined4 *)(constAddr + 0x38) = mvpCopy32;
          paramCount = paramList[2];
        }
        break;
      case 4:
        slotMatrixAlt = *(int *)(ctxState + 0x10) + 0x1860 + elementIndex * 0x40;
        constOffset = *(int *)(elementIndex * 4 + paramMapEntries + 0x34) * 0x10;
        slotAlt20 = *(undefined4 *)(slotMatrixAlt + 0x420);
        slotAlt33 = *(undefined4 *)(slotMatrixAlt + 0x43c);
        constAddr = constantBuffer + constOffset;
        slotAlt01 = *(undefined4 *)(slotMatrixAlt + 0x404);
        slotAlt02 = *(undefined4 *)(slotMatrixAlt + 0x408);
        slotAlt03 = *(undefined4 *)(slotMatrixAlt + 0x40c);
        slotAlt10 = *(undefined4 *)(slotMatrixAlt + 0x410);
        slotAlt11 = *(undefined4 *)(slotMatrixAlt + 0x414);
        slotAlt12 = *(undefined4 *)(slotMatrixAlt + 0x418);
        slotAlt13 = *(undefined4 *)(slotMatrixAlt + 0x41c);
        slotAlt21 = *(undefined4 *)(slotMatrixAlt + 0x424);
        slotAlt22 = *(undefined4 *)(slotMatrixAlt + 0x428);
        slotAlt23 = *(undefined4 *)(slotMatrixAlt + 0x42c);
        slotAlt30 = *(undefined4 *)(slotMatrixAlt + 0x430);
        slotAlt31 = *(undefined4 *)(slotMatrixAlt + 0x434);
        slotAlt32 = *(undefined4 *)(slotMatrixAlt + 0x438);
        *(undefined4 *)(constantBuffer + constOffset) = *(undefined4 *)(slotMatrixAlt + 0x400);
        *(undefined4 *)(constAddr + 8) = slotAlt20;
        *(undefined4 *)(constAddr + 4) = slotAlt10;
        *(undefined4 *)(constAddr + 0x10) = slotAlt01;
        *(undefined4 *)(constAddr + 0x14) = slotAlt11;
        *(undefined4 *)(constAddr + 0xc) = slotAlt30;
        *(undefined4 *)(constAddr + 0x18) = slotAlt21;
        *(undefined4 *)(constAddr + 0x1c) = slotAlt31;
        *(undefined4 *)(constAddr + 0x20) = slotAlt02;
        *(undefined4 *)(constAddr + 0x24) = slotAlt12;
        *(undefined4 *)(constAddr + 0x28) = slotAlt22;
        *(undefined4 *)(constAddr + 0x2c) = slotAlt32;
        *(undefined4 *)(constAddr + 0x30) = slotAlt03;
        *(undefined4 *)(constAddr + 0x34) = slotAlt13;
        *(undefined4 *)(constAddr + 0x38) = slotAlt23;
        *(undefined4 *)(constAddr + 0x3c) = slotAlt33;
        paramCount = paramList[2];
        break;
      case 5:
        valueXY = *(undefined8 *)(stateBlock + 0x24c0 + elementIndex * 0x80);
        valueZW = *(undefined8 *)(stateBlock + 0x24c0 + elementIndex * 0x80 + 8);
        constIndex = *(int *)(elementIndex * 0x3c + paramMapEntries + 0x58);
        goto LAB_0009fa50;
      case 6:
        lightState = stateBlock + 0x24c0 + elementIndex * 0x80;
        valueXY = *(undefined8 *)(lightState + 0x10);
        valueZW = *(undefined8 *)(lightState + 0x18);
        constIndex = *(int *)(elementIndex * 0x3c + paramMapEntries + 0x5c);
        goto LAB_0009fa50;
      case 7:
        lightState = stateBlock + 0x24c0 + elementIndex * 0x80;
        valueXY = *(undefined8 *)(lightState + 0x20);
        valueZW = *(undefined8 *)(lightState + 0x28);
        constIndex = *(int *)(elementIndex * 0x3c + paramMapEntries + 0x68);
        goto LAB_0009fa50;
      case 8:
        if ((*(char *)(ctx + 0x12f) != '\0') && ((*(uint *)(stateBlock + 0x24ac) & 0xffff00) != 0))
        {
          if (*(char *)(stateBlock + 0x24ad) == '\0') {
            if (*(char *)(stateBlock + 0x24ae) != '\0') {
              stateF24a4 = *(float *)(stateBlock + 0x24a4);
              ctxVec4Entry = elementIndex * 0x10 + ctx;
              stateVecZ = stateF24a4 * *(float *)(ctxVec4Entry + 0x2a0);
              stateVecX = stateF24a4 * *(float *)(ctxVec4Entry + 0x298);
              stateVecY = stateF24a4 * *(float *)(ctxVec4Entry + 0x29c);
            }
          }
          else {
            scratchProduct = (double)(**(code **)(((unsigned char *)0x00001348) + ctx))
                                         (&stateVecX,elementIndex * 0x10 + ctx + 0x298);
          }
          stateVecW = 0x3f800000;
          constIndex = *(int *)(elementIndex * 0x3c + paramMapEntries + 0x78);
          goto LAB_0009fb60;
        }
        ctxVec4Entry = ctx + elementIndex * 0x10 + 0x290;
        valueXY = *(undefined8 *)(ctxVec4Entry + 8);
        valueZW = *(undefined8 *)(ctxVec4Entry + 0x10);
        constIndex = *(int *)(elementIndex * 0x3c + paramMapEntries + 0x78);
        goto LAB_0009fa50;
      case 9:
        if ((*(char *)(ctx + 0x12f) != '\0') && ((*(uint *)(stateBlock + 0x24ac) & 0xffff00) != 0))
        {
          if (*(char *)(stateBlock + 0x24ad) == '\0') {
            if (*(char *)(stateBlock + 0x24ae) != '\0') {
              stateF24a4 = *(float *)(stateBlock + 0x24a4);
              ctxVec4Entry = elementIndex * 0x10 + ctx;
              stateVecZ = stateF24a4 * *(float *)(ctxVec4Entry + 800);
              stateVecX = stateF24a4 * *(float *)(ctxVec4Entry + 0x318);
              stateVecY = stateF24a4 * *(float *)(ctxVec4Entry + 0x31c);
            }
          }
          else {
            scratchProduct = (double)(**(code **)(((unsigned char *)0x00001348) + ctx))
                                         (scratchProduct,&stateVecX,elementIndex * 0x10 + ctx + 0x318);
          }
          stateVecW = 0x3f800000;
          constIndex = *(int *)(elementIndex * 0x3c + paramMapEntries + 0x7c);
          goto LAB_0009fb60;
        }
        ctxVec4Entry = ctx + elementIndex * 0x10 + 0x310;
        valueXY = *(undefined8 *)(ctxVec4Entry + 8);
        valueZW = *(undefined8 *)(ctxVec4Entry + 0x10);
        constIndex = *(int *)(elementIndex * 0x3c + paramMapEntries + 0x7c);
        goto LAB_0009fa50;
      case 10:
        lightState = stateBlock + 0x24c0 + elementIndex * 0x80;
        stateVecX = *(float *)(lightState + 0x58);
        stateVecY = *(float *)(lightState + 0x54);
        stateVecZ = *(float *)(lightState + 0x50);
        stateVecW = 0;
        constIndex = *(int *)(elementIndex * 0x3c + paramMapEntries + 0x80);
        goto LAB_0009fb60;
      case 0xb:
        ctxUnitState = ctx + elementIndex * 0x6c;
        constDest = *(int *)(elementIndex * 0x3c + paramMapEntries + 0x84) * 0x10;
        *(undefined4 *)(constantBuffer + constDest) = *(undefined4 *)(((unsigned char *)0x00001500) + ctxUnitState + 4);
        constDest = constantBuffer + constDest;
        *(undefined4 *)(constDest + 4) = *(undefined4 *)(((unsigned char *)0x00001500) + ctxUnitState + 4);
        *(undefined4 *)(constDest + 8) = *(undefined4 *)(((unsigned char *)0x00001500) + ctxUnitState + 4);
        *(undefined4 *)(constDest + 0xc) = *(undefined4 *)(((unsigned char *)0x00001500) + ctxUnitState + 4);
        paramCount = paramList[2];
        break;
      case 0xc:
        ctxUnitState = ctx + elementIndex * 0x6c;
        constDest = *(int *)(elementIndex * 0x3c + paramMapEntries + 0x88) * 0x10;
        *(undefined4 *)(constantBuffer + constDest) = *(undefined4 *)(((unsigned char *)0x00001500) + ctxUnitState + 8);
        constDest = constantBuffer + constDest;
        *(undefined4 *)(constDest + 4) = *(undefined4 *)(((unsigned char *)0x00001500) + ctxUnitState + 8);
        *(undefined4 *)(constDest + 8) = *(undefined4 *)(((unsigned char *)0x00001500) + ctxUnitState + 8);
        *(undefined4 *)(constDest + 0xc) = *(undefined4 *)(((unsigned char *)0x00001500) + ctxUnitState + 8);
        paramCount = paramList[2];
        break;
      case 0xd:
        lightState2 = stateBlock + 0x24c0 + elementIndex * 0x80;
        constDest = *(int *)(elementIndex * 0x3c + paramMapEntries + 0x8c) * 0x10;
        *(undefined4 *)(constantBuffer + constDest) = *(undefined4 *)(lightState2 + 0x5c);
        constDest = constantBuffer + constDest;
        *(undefined4 *)(constDest + 4) = *(undefined4 *)(lightState2 + 0x5c);
        *(undefined4 *)(constDest + 8) = *(undefined4 *)(lightState2 + 0x5c);
        *(undefined4 *)(constDest + 0xc) = *(undefined4 *)(lightState2 + 0x5c);
        paramCount = paramList[2];
        break;
      case 0xe:
        if (elementIndex == 0) {
          valueZW = *(undefined8 *)(stateBlock + 0x28f8);
          valueXY = *(undefined8 *)(stateBlock + 0x28f0);
          constIndex = *(int *)(paramMap + 0x2d8);
        }
        else {
          valueZW = *(undefined8 *)(((unsigned char *)0x00002b38) + stateBlock);
          valueXY = *(undefined8 *)(stateBlock + 0x2b30);
          constIndex = *(int *)(elementIndex * 0x24 + paramMapEntries + 0x234);
        }
        goto LAB_0009fa50;
      case 0xf:
        if (elementIndex == 0) {
          valueZW = *(undefined8 *)(stateBlock + 0x28c8);
          valueXY = *(undefined8 *)(stateBlock + 0x28c0);
          constIndex = *(int *)(paramMap + 0x2dc);
        }
        else {
          valueZW = *(undefined8 *)(stateBlock + 0x2b08);
          valueXY = *(undefined8 *)(stateBlock + 0x2b00);
          constIndex = *(int *)(elementIndex * 0x24 + paramMapEntries + 0x238);
        }
        goto LAB_0009fa50;
      case 0x10:
        if (elementIndex == 0) {
          valueZW = *(undefined8 *)(stateBlock + 0x28d8);
          valueXY = *(undefined8 *)(stateBlock + 0x28d0);
          constIndex = *(int *)(paramMap + 0x2e0);
        }
        else {
          valueZW = *(undefined8 *)(stateBlock + 0x2b18);
          valueXY = *(undefined8 *)(stateBlock + 0x2b10);
          constIndex = *(int *)(elementIndex * 0x24 + paramMapEntries + 0x23c);
        }
        goto LAB_0009fa50;
      case 0x11:
        if (elementIndex == 0) {
          valueZW = *(undefined8 *)(stateBlock + 0x28e8);
          valueXY = *(undefined8 *)(stateBlock + 0x28e0);
          constIndex = *(int *)(paramMap + 0x2ec);
        }
        else {
          valueZW = *(undefined8 *)(stateBlock + 0x2b28);
          valueXY = *(undefined8 *)(stateBlock + 0x2b20);
          constIndex = *(int *)(elementIndex * 0x24 + paramMapEntries + 0x248);
        }
        goto LAB_0009fa50;
      case 0x12:
        if (elementIndex == 0) {
          stateVecX = *(float *)(stateBlock + 0x28c0) * *(float *)(stateBlock + 0x24b0) +
                      *(float *)(stateBlock + 0x28f0);
          stateVecY = *(float *)(stateBlock + 0x28c4) * *(float *)(stateBlock + 0x24b4) +
                       *(float *)(stateBlock + 0x28f4);
          stateVecZ = *(float *)(stateBlock + 0x28c8) * *(float *)(stateBlock + 0x24b8) +
                      *(float *)(stateBlock + 0x28f8);
        }
        else {
          stateVecX = *(float *)(stateBlock + 0x2b00) * *(float *)(stateBlock + 0x24b0) +
                      *(float *)(stateBlock + 0x2b30);
          stateVecY = *(float *)(stateBlock + 0x2b04) * *(float *)(stateBlock + 0x24b4) +
                       *(float *)(stateBlock + 0x2b34);
          stateVecZ = *(float *)(stateBlock + 0x2b08) * *(float *)(stateBlock + 0x24b8) +
                      *(float *)(((unsigned char *)0x00002b38) + stateBlock);
        }
        constOffset = *(int *)(elementIndex * 0x24 + paramMapEntries + 0x254) * 0x10;
        *(ulonglong *)(constantBuffer + constOffset) = CONCAT44(stateVecX,stateVecY);
        *(ulonglong *)(constantBuffer + constOffset + 8) = CONCAT44(stateVecZ,stateVecW);
        paramCount = paramList[2];
        break;
      case 0x13:
        if (elementIndex == 0) {
          constDest = *(int *)(paramMap + 800) * 0x10;
          *(undefined4 *)(constantBuffer + constDest) = *(undefined4 *)(stateBlock + 0x2900);
          constDest = constantBuffer + constDest;
          *(undefined4 *)(constDest + 4) = *(undefined4 *)(stateBlock + 0x2900);
          *(undefined4 *)(constDest + 8) = *(undefined4 *)(stateBlock + 0x2900);
          *(undefined4 *)(constDest + 0xc) = *(undefined4 *)(stateBlock + 0x2900);
          paramCount = paramList[2];
        }
        else {
          constDest = *(int *)(elementIndex * 4 + paramMapEntries + 0x27c) * 0x10;
          *(undefined4 *)(constantBuffer + constDest) = *(undefined4 *)(((unsigned char *)0x00002b40) + stateBlock);
          constDest = constantBuffer + constDest;
          *(undefined4 *)(constDest + 4) = *(undefined4 *)(((unsigned char *)0x00002b40) + stateBlock);
          *(undefined4 *)(constDest + 8) = *(undefined4 *)(((unsigned char *)0x00002b40) + stateBlock);
          *(undefined4 *)(constDest + 0xc) = *(undefined4 *)(((unsigned char *)0x00002b40) + stateBlock);
          paramCount = paramList[2];
        }
        break;
      case 0x14:
        valueZW = *(undefined8 *)(stateBlock + 0x24b8);
        valueXY = *(undefined8 *)(stateBlock + 0x24b0);
        constIndex = *(int *)(paramMap + 0x328);
        goto LAB_0009fa50;
      case 0x15:
        stateVecY = *(float *)(ctx + 0x134);
        stateVecZ = *(float *)(ctx + 0x138);
        stateVecW = 0;
        stateVecX = 0.0;
        constIndex = *(int *)(paramMap + 0x330);
        goto LAB_0009fb60;
      case 0x16:
        stateVecX = *(float *)(ctx + 400);
        stateVecY = *(float *)(ctx + 0x194);
        stateVecZ = *(float *)(ctx + 0xf0);
        stateVecW = *(undefined4 *)(ctx + 0x198);
        constIndex = *(int *)(paramMap + 0x334);
        goto LAB_0009fb60;
      case 0x17:
        stateVecX = *(float *)(ctx + 0x118);
        stateVecY = *(float *)(ctx + 0x114);
        stateVecZ = *(float *)(ctx + 0x110);
        stateVecW = 0;
        constOffset = *(int *)(paramMap + 0x338) * 0x10;
        *(ulonglong *)(constantBuffer + constOffset) = CONCAT44(stateVecX,stateVecY);
        *(ulonglong *)(constantBuffer + constOffset + 8) = (ulonglong)(uint)GH_F2U(stateVecZ) << 0x20;
        paramCount = paramList[2];
        break;
      case 0x18:
        if ((*(uint *)(ctx + 0x44) & 0x40000000) == 0) {
          intToDoubleHiB = 0x43300000;
          intToDoubleHiA = 0x43300000;
          intToDoubleLoA = *(uint *)(ctx + 0x108) ^ 0x80000000;
          intToDoubleLoB = *(uint *)(ctx + 0x10c) ^ 0x80000000;
          stateVecX = (float)((double)CONCAT44(0x43300000,intToDoubleLoA) - DOUBLE_001aa1e0);
          stateVecY = (float)((double)CONCAT44(0x43300000,intToDoubleLoB) - DOUBLE_001aa1e0);
        }
        else {
          stateVecX = *(float *)(ctx + 0x100);
          stateVecY = *(float *)(ctx + 0x104);
        }
        stateVecW = 0;
        stateVecZ = 0.0;
        constIndex = *(int *)(paramMap + 0x340);
        goto LAB_0009fb60;
      case 0x19:
        constDest = *(int *)(paramMap + 0x344) * 0x10;
        *(undefined4 *)(constantBuffer + constDest) = *(undefined4 *)(stateBlock + 0x24a4);
        constDest = constantBuffer + constDest;
        *(undefined4 *)(constDest + 4) = *(undefined4 *)(stateBlock + 0x24a4);
        *(undefined4 *)(constDest + 8) = *(undefined4 *)(stateBlock + 0x24a4);
        *(undefined4 *)(constDest + 0xc) = *(undefined4 *)(stateBlock + 0x24a4);
        paramCount = paramList[2];
        break;
      case 0x1a:
        texGenComponent = elementIndex & 3;
        texUnit = elementIndex >> 2;
        if (texGenComponent == 1) {
          texUnitState = texUnit * 0xcc + ctx;
          if (*(short *)(texUnitState + 0x4b0) == 0x2401) {
            texGenPlane = (undefined8 *)(texUnitState + 0x4c4);
          }
          else {
            texGenPlane = (undefined8 *)(texUnit * 0xcc + ctx + 0x4b4);
          }
        }
        else if (texGenComponent == 0) {
          texUnitState = texUnit * 0xcc + ctx;
          if (*(short *)(texUnitState + 0x48c) == 0x2401) {
            texGenPlane = (undefined8 *)(texUnitState + 0x4a0);
          }
          else {
            texGenPlane = (undefined8 *)(texUnit * 0xcc + ctx + 0x490);
          }
        }
        else if (texGenComponent == 2) {
          texUnitState = texUnit * 0xcc + ctx;
          if (*(short *)(texUnitState + 0x4d4) == 0x2401) {
            texGenPlane = (undefined8 *)(texUnitState + 0x4e8);
          }
          else {
            texGenPlane = (undefined8 *)(texUnit * 0xcc + ctx + 0x4d8);
          }
        }
        else {
          texGenPlane = (undefined8 *)0x0;
          if (texGenComponent == 3) {
            texUnitState = texUnit * 0xcc + ctx;
            if (*(short *)(texUnitState + 0x4f8) == 0x2401) {
              texGenPlane = (undefined8 *)(texUnitState + 0x50c);
            }
            else {
              texGenPlane = (undefined8 *)(texUnit * 0xcc + ctx + 0x4fc);
            }
          }
        }
        valueXY = texGenPlane[1];
        constOffset = *(int *)(elementIndex * 4 + paramMapEntries + 0x2a4) * 0x10;
        *(undefined8 *)(constantBuffer + constOffset) = *texGenPlane;
        *(undefined8 *)(constantBuffer + constOffset + 8) = valueXY;
        paramCount = paramList[2];
        break;
      case 0x1b:
        valueZW = *(undefined8 *)(ctx + 0x3a0);
        valueXY = *(undefined8 *)(ctx + 0x398);
        constIndex = *(int *)(paramMap + 0x32c);
LAB_0009fa50:
        *(undefined8 *)(constantBuffer + constIndex * 0x10) = valueXY;
        *(undefined8 *)(constantBuffer + constIndex * 0x10 + 8) = valueZW;
        paramCount = paramList[2];
        break;
      case 0x1c:
        lightState = stateBlock + 0x24c0 + (elementIndex >> 1) * 0x80;
        materialState = (elementIndex & 1) * 0x240 + stateBlock;
        stateVecX = *(float *)(lightState + 0x10) * *(float *)(materialState + 0x28d0);
        stateVecY = *(float *)(lightState + 0x14) * *(float *)(materialState + 0x28d4);
        stateVecZ = *(float *)(lightState + 0x18) * *(float *)(materialState + 0x28d8);
        stateVecW = *(undefined4 *)(materialState + 0x28dc);
        constIndex = *(int *)(((elementIndex >> 1) * 0xf + (elementIndex & 1)) * 4 + paramMapEntries + 0x60);
        goto LAB_0009fb60;
      case 0x1d:
        lightState = stateBlock + 0x24c0 + (elementIndex >> 1) * 0x80;
        materialState = (elementIndex & 1) * 0x240 + stateBlock;
        stateVecX = *(float *)(lightState + 0x20) * *(float *)(materialState + 0x28e0);
        stateVecY = *(float *)(lightState + 0x24) * *(float *)(materialState + 0x28e4);
        stateVecW = 0x3f800000;
        stateVecZ = *(float *)(lightState + 0x28) * *(float *)(materialState + 0x28e8);
        constIndex = *(int *)(((elementIndex >> 1) * 0xf + (elementIndex & 1)) * 4 + paramMapEntries + 0x6c);
LAB_0009fb60:
        *(ulonglong *)(constantBuffer + constIndex * 0x10) = CONCAT44(stateVecX,stateVecY);
        *(ulonglong *)(constantBuffer + constIndex * 0x10 + 8) = CONCAT44(stateVecZ,stateVecW);
        paramCount = paramList[2];
      }
      paramIndex = paramIndex + 1;
      paramOffset = paramOffset + 4;
    } while (paramIndex < paramCount);
  }
  _restf14();
  return;
}

/* arbProgramFindIndex @ 0xa0290 (96 bytes) */
int arbProgramFindIndex(ctx, programTable, programId)
  undefined4 ctx;
  int programTable;
  int programId;
{
  bool searching;
  uint entryIndex;
  int idOffset;
  
  if (programId != 0) {
    entryIndex = 3;
    idOffset = 0x48;
    searching = true;
    while (entryIndex < *(uint *)(programTable + 4)) {
      if (!searching) {
        return entryIndex;
      }
      if (programId == *(int *)(idOffset + *(int *)(programTable + 8))) {
        searching = false;
      }
      else {
        entryIndex = entryIndex + 1;
        idOffset = idOffset + 0x18;
      }
    }
    if (!searching) {
      return entryIndex;
    }
  }
  return 0;
}

/* glProgramStringARB_impl @ 0xa0300 (80 bytes) */
int glProgramStringARB_impl(ctx, target, format, length, param_5, param_6, param_7, param_8)
  int ctx;
  int target;
  int format;
  int length;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  *(undefined4 *)(((unsigned char *)0x00001124) + ctx) = 0xffffffff;
  **(undefined1 **)(((unsigned char *)0x00001128) + ctx) = 0;
  if (length < 1) {
    return;
  }
  if (format != 0x8875) {
    return;
  }
  if (target != 0x8804) {
    return;
  }
  return arbfpProgramString(ctx,0x8875,length,param_5);
}

/* FUN_000a0350 @ 0xa0350 (36 bytes) */
int FUN_000a0350(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  param_2[5] = 0;
  param_2[3] = 0xffffffff;
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[4] = 0;
  return;
}

/* glBindProgramARB_impl @ 0xa0380 (476 bytes) */
int glBindProgramARB_impl(ctx, target, programId, param_4, param_5, param_6, param_7)
  int ctx;
  int target;
  int programId;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  int param_7;
{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 a1;
  int a2;
  undefined4 in_r10;
  int iVar4;
  int iVar5;
  
  if ((target == 0x8620) || (target == 0x8804)) {
    iVar5 = *(int *)(((unsigned char *)0x0000112c) + ctx);
    a2 = programId;
    iVar2 = ((int (*)())arbProgramFindIndex)(ctx,iVar5,programId);
    if (iVar2 == 0) {
      if (programId != 0) {
        uVar1 = *(uint *)(iVar5 + 4);
        if ((uVar1 & 7) == 0) {
          iVar2 = (**(code **)(ctx + 0xc))(uVar1 * 0x18 + 0xc0);
          if (iVar2 == 0) {
            return;
          }
          a2 = *(int *)(iVar5 + 4) * 0x18;
          (**(code **)(((unsigned char *)0x00001344) + ctx))(iVar2,*(undefined4 *)(iVar5 + 8),a2);
          (**(code **)(ctx + 0x18))(*(undefined4 *)(iVar5 + 8));
          *(int *)(iVar5 + 8) = iVar2;
          uVar1 = *(uint *)(iVar5 + 4);
        }
        ((int (*)())FUN_000a0350)(ctx,uVar1 * 0x18 + *(int *)(iVar5 + 8));
        *(int *)(*(int *)(iVar5 + 4) * 0x18 + *(int *)(iVar5 + 8) + 4) = target;
        *(int *)(*(int *)(iVar5 + 4) * 0x18 + *(int *)(iVar5 + 8)) = programId;
        if (target == 0x8804) {
          iVar2 = *(int *)(iVar5 + 8);
          iVar4 = *(int *)(iVar5 + 4) * 0x18 + iVar2;
          uVar3 = (**(code **)(ctx + 0xc))(0x78,a1,a2,param_4,param_5,param_6,iVar2);
          *(undefined4 *)(iVar4 + 0x14) = uVar3;
          arbfpProgramObjectInit(ctx,*(undefined4 *)
                                (*(int *)(iVar5 + 4) * 0x18 + *(int *)(iVar5 + 8) + 0x14));
          arbfpBindProgram(ctx,*(undefined4 *)(iVar5 + 4),a2,param_4,param_5,param_6,iVar2,in_r10);
        }
        *(int *)(iVar5 + 4) = *(int *)(iVar5 + 4) + 1;
        return;
      }
    }
    else {
      param_7 = *(int *)(iVar5 + 8);
      if (target != *(int *)(iVar2 * 0x18 + param_7 + 4)) {
        return;
      }
    }
    if (target == 0x8804) {
      if (iVar2 == 0) {
        iVar2 = *(int *)(((unsigned char *)0x0000126c) + ctx);
      }
      arbfpBindProgram(ctx,iVar2,a2,param_4,param_5,param_6,param_7,in_r10);
      return;
    }
  }
  return;
}

/* glGenProgramsARB_impl @ 0xa0570 (124 bytes) */
int glGenProgramsARB_impl(ctx, count, ids)
  int ctx;
  int count;
  int ids;
{
  int iVar1;
  int loopIndex;
  int *piVar3;
  int iVar4;
  
  if (0 < count) {
    piVar3 = *(int **)(((unsigned char *)0x0000112c) + ctx);
    loopIndex = 0;
    iVar4 = *piVar3;
    do {
      while (iVar1 = ((int (*)())arbProgramFindIndex)(ctx,piVar3,iVar4), iVar1 != 0) {
        iVar4 = iVar4 + 1;
      }
      iVar1 = loopIndex * 4;
      loopIndex = loopIndex + 1;
      *(int *)(ids + iVar1) = iVar4;
      iVar4 = iVar4 + 1;
    } while (count != loopIndex);
    *piVar3 = iVar4;
  }
  return;
}

/* glGetProgramivARB_impl @ 0xa05f0 (704 bytes) */
int glGetProgramivARB_impl(ctx, target, pname, params)
  int ctx;
  int target;
  int pname;
  uint *params;
{
  int iVar1;
  int iVar2;
  
  if (target == 0x8620) {
    iVar2 = *(int *)(((unsigned char *)0x000014a0) + ctx);
  }
  else {
    if (target != 0x8804) {
      return;
    }
    iVar2 = *(int *)(((unsigned char *)0x00001270) + ctx);
  }
  iVar1 = *(int *)(((unsigned char *)0x0000112c) + ctx);
  if (pname == 0x8627) {
    *params = *(uint *)(iVar2 * 0x18 + *(int *)(iVar1 + 8) + 0xc);
    return;
  }
  if (pname == 0x8876) {
    *params = *(uint *)(iVar2 * 0x18 + *(int *)(iVar1 + 8) + 8);
    return;
  }
  if (pname != 0x8677) {
    if (target == 0x8804) {
      iVar2 = *(int *)(iVar2 * 0x18 + *(int *)(iVar1 + 8) + 0x14);
      switch(pname) {
      case 0x8805:
        *params = *(uint *)(*(int *)(iVar2 + 0x74) + 0x6c);
        return;
      case 0x8806:
        *params = *(uint *)(*(int *)(iVar2 + 0x74) + 0x70);
        return;
      case 0x8807:
        *params = *(uint *)(*(int *)(iVar2 + 0x74) + 0x74);
        return;
      case 0x8808:
        *params = *(uint *)(iVar2 + 0x54);
        return;
      case 0x8809:
        *params = *(uint *)(iVar2 + 0x58);
        return;
      case 0x880a:
        *params = *(uint *)(iVar2 + 0x5c);
switchD_000a0718_caseD_8811:
        return;
      case 0x880b:
        *params = *(uint *)(((unsigned char *)0x00001204) + ctx);
        return;
      case 0x880c:
        *params = *(uint *)(((unsigned char *)0x00001208) + ctx);
        return;
      case 0x880d:
        *params = *(uint *)(((unsigned char *)0x0000120cU) + ctx);
        return;
      case 0x880e:
        *params = *(uint *)(((unsigned char *)0x00001210) + ctx);
        return;
      case 0x880f:
        *params = *(uint *)(((unsigned char *)0x00001214) + ctx);
        return;
      case 0x8810:
        *params = *(uint *)(((unsigned char *)0x00001218) + ctx);
        return;
      case 0x8811:
      case 0x8812:
      case 0x8813:
      case 0x8814:
      case 0x8815:
      case 0x8816:
      case 0x8817:
      case 0x8818:
      case 0x8819:
      case 0x881a:
      case 0x881b:
      case 0x881c:
      case 0x881d:
      case 0x881e:
      case 0x881f:
      case 0x8820:
      case 0x8821:
      case 0x8822:
      case 0x8823:
      case 0x8824:
      case 0x8825:
      case 0x8826:
      case 0x8827:
      case 0x8828:
      case 0x8829:
      case 0x882a:
      case 0x882b:
      case 0x882c:
      case 0x882d:
      case 0x882e:
      case 0x882f:
      case 0x8830:
      case 0x8831:
      case 0x8832:
      case 0x8833:
      case 0x8834:
      case 0x8835:
      case 0x8836:
      case 0x8837:
      case 0x8838:
      case 0x8839:
      case 0x883a:
      case 0x883b:
      case 0x883c:
      case 0x883d:
      case 0x883e:
      case 0x883f:
      case 0x8840:
      case 0x8841:
      case 0x8842:
      case 0x8843:
      case 0x8844:
      case 0x8845:
      case 0x8846:
      case 0x8847:
      case 0x8848:
      case 0x8849:
      case 0x884a:
      case 0x884b:
      case 0x884c:
      case 0x884d:
      case 0x884e:
      case 0x884f:
      case 0x8850:
      case 0x8851:
      case 0x8852:
      case 0x8853:
      case 0x8854:
      case 0x8855:
      case 0x8856:
      case 0x8857:
      case 0x8858:
      case 0x8859:
      case 0x885a:
      case 0x885b:
      case 0x885c:
      case 0x885d:
      case 0x885e:
      case 0x885f:
      case 0x8860:
      case 0x8861:
      case 0x8862:
      case 0x8863:
      case 0x8864:
      case 0x8865:
      case 0x8866:
      case 0x8867:
      case 0x8868:
      case 0x8869:
      case 0x886a:
      case 0x886b:
      case 0x886c:
      case 0x886d:
      case 0x886e:
      case 0x886f:
      case 0x8870:
      case 0x8871:
      case 0x8872:
      case 0x8873:
      case 0x8874:
      case 0x8875:
      case 0x8876:
      case 0x8877:
      case 0x8878:
      case 0x8879:
      case 0x887a:
      case 0x887b:
      case 0x887c:
      case 0x887d:
      case 0x887e:
      case 0x887f:
      case 0x8880:
      case 0x8881:
      case 0x8882:
      case 0x8883:
      case 0x8884:
      case 0x8885:
      case 0x8886:
      case 0x8887:
      case 0x8888:
      case 0x8889:
      case 0x888a:
      case 0x888b:
      case 0x888c:
      case 0x888d:
      case 0x888e:
      case 0x888f:
      case 0x8890:
      case 0x8891:
      case 0x8892:
      case 0x8893:
      case 0x8894:
      case 0x8895:
      case 0x8896:
      case 0x8897:
      case 0x8898:
      case 0x8899:
      case 0x889a:
      case 0x889b:
      case 0x889c:
      case 0x889d:
      case 0x889e:
      case 0x889f:
        goto switchD_000a0718_caseD_8811;
      case 0x88a0:
        *params = *(uint *)(*(int *)(iVar2 + 0x74) + 0x68);
        return;
      case 0x88a1:
        *params = *(uint *)(((unsigned char *)0x000011d4) + ctx);
        return;
      case 0x88a2:
        *params = *(uint *)(iVar2 + 0x50);
        return;
      case 0x88a3:
        *params = *(uint *)(((unsigned char *)0x000011d8) + ctx);
        return;
      case 0x88a4:
        *params = *(uint *)(*(int *)(iVar2 + 0x74) + 0x88);
        return;
      case 0x88a5:
        *params = *(uint *)(((unsigned char *)0x000011dc) + ctx);
        return;
      case 0x88a6:
        *params = *(uint *)(iVar2 + 0x68);
        return;
      case 0x88a7:
        *params = *(uint *)(((unsigned char *)0x000011e0) + ctx);
        return;
      case 0x88a8:
        *params = *(uint *)(*(int *)(iVar2 + 0x74) + 0x84);
        return;
      case 0x88a9:
        *params = *(uint *)(((unsigned char *)0x000011e4) + ctx);
        return;
      case 0x88aa:
        *params = *(uint *)(iVar2 + 100);
        return;
      case 0x88ab:
        *params = *(uint *)(((unsigned char *)0x000011e8) + ctx);
        return;
      case 0x88ac:
        *params = *(uint *)(*(int *)(iVar2 + 0x74) + 0x7c);
        return;
      case 0x88ad:
        *params = *(uint *)(((unsigned char *)0x000011ec) + ctx);
        return;
      case 0x88ae:
        *params = *(uint *)(iVar2 + 0x60);
        return;
      case 0x88af:
        *params = *(uint *)(((unsigned char *)0x000011f0) + ctx);
        return;
      case 0x88b0:
      case 0x88b2:
        *params = 0;
        return;
      case 0x88b1:
        *params = *(uint *)(((unsigned char *)0x000011f4) + ctx);
        return;
      case 0x88b3:
        *params = *(uint *)(((unsigned char *)0x000011f8) + ctx);
        return;
      case 0x88b4:
        *params = *(uint *)(((unsigned char *)0x000011fc) + ctx);
        return;
      case 0x88b5:
        *params = *(uint *)(((unsigned char *)0x00001200) + ctx);
        return;
      case 0x88b6:
        *params = (uint)*(byte *)(iVar2 + 0x6c);
        return;
      default:
        return;
      }
    }
    return;
  }
  *params = *(uint *)(iVar2 * 0x18 + *(int *)(iVar1 + 8));
  return;
}

/* arbProgramEntryFree @ 0xa0ba0 (188 bytes) */
int arbProgramEntryFree(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  int iVar1;
  
  iVar1 = param_2[5];
  if (iVar1 != 0) {
    if (param_2[1] == 0x8804) {
      arbfpProgramObjectFree(param_1,iVar1);
      iVar1 = param_2[5];
    }
    (**(code **)(param_1 + 0x18))(iVar1);
    param_2[5] = 0;
  }
  if (param_2[4] != 0) {
    (**(code **)(param_1 + 0x18))(param_2[4]);
    param_2[4] = 0;
  }
  param_2[2] = 0;
  param_2[3] = 0xffffffff;
  *param_2 = 0;
  param_2[1] = 0;
  return;
}

/* arbProgramTableRelease @ 0xa0c60 (260 bytes) */
int arbProgramTableRelease(ctx)
  int ctx;
{
  int entry;
  uint loopIndex;
  int entryOffset;
  int programTable;
  
  FUN_0008dc40(ctx);
  if (*(int *)(((unsigned char *)0x00001128) + ctx) != 0) {
    (**(code **)(ctx + 0x18))(*(int *)(((unsigned char *)0x00001128) + ctx));
    *(undefined4 *)(((unsigned char *)0x00001128) + ctx) = 0;
  }
  *(int *)(*(int *)(((unsigned char *)0x0000112c) + ctx) + 0xc) =
       *(int *)(*(int *)(((unsigned char *)0x0000112c) + ctx) + 0xc) + -1;
  if (*(int *)(*(int *)(((unsigned char *)0x0000112c) + ctx) + 0xc) == 0) {
    programTable = *(int *)(((unsigned char *)0x0000112c) + ctx);
    if (*(int *)(programTable + 4) != 0) {
      loopIndex = 0;
      entryOffset = 0;
      do {
        loopIndex = loopIndex + 1;
        entry = entryOffset + *(int *)(programTable + 8);
        entryOffset = entryOffset + 0x18;
        ((int (*)())arbProgramEntryFree)(ctx,entry);
      } while (loopIndex < *(uint *)(programTable + 4));
    }
    *(undefined4 *)(programTable + 4) = 0;
    if (*(int *)(programTable + 8) != 0) {
      (**(code **)(ctx + 0x18))(*(int *)(programTable + 8));
      *(undefined4 *)(programTable + 8) = 0;
    }
    (**(code **)(ctx + 0x18))(programTable);
    *(undefined4 *)(((unsigned char *)0x0000112c) + ctx) = 0;
  }
  return;
}

/* glDeleteProgramsARB_impl @ 0xa0d70 (372 bytes) */
int glDeleteProgramsARB_impl(ctx, count, ids)
  int ctx;
  int count;
  int *ids;
{
  uint entryIndex;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar2;
  int loopIndex;
  int entryOffset;
  int programTable;
  
  if (0 < count) {
    programTable = *(int *)(((unsigned char *)0x0000112c) + ctx);
    loopIndex = 0;
    do {
      entryIndex = ((int (*)())arbProgramFindIndex)(ctx,programTable,*ids);
      if (entryIndex != 0) {
        iVar2 = *(int *)(programTable + 8);
        entryOffset = entryIndex * 0x18;
        if ((*(int *)(iVar2 + entryOffset + 4) == 0x8804) &&
           (*(int *)(*(int *)(((unsigned char *)0x00001270) + ctx) * 0x18 + iVar2) == *ids)) {
          ((int (*)())glBindProgramARB_impl)(ctx,0x8804,0,in_r6,in_r7,in_r8,*ids);
          iVar2 = *(int *)(programTable + 8);
        }
        ((int (*)())arbProgramEntryFree)(ctx,entryOffset + iVar2);
        entryOffset = entryOffset + *(int *)(programTable + 8);
        _memmove(entryOffset,entryOffset + 0x18,(*(int *)(programTable + 4) - entryIndex) * 0x18 + -0x18);
        entryOffset = *(int *)(programTable + 4) + -1;
        *(int *)(programTable + 4) = entryOffset;
        *(undefined4 *)(entryOffset * 0x18 + *(int *)(programTable + 8) + 8) = 0;
        *(undefined4 *)(*(int *)(programTable + 4) * 0x18 + *(int *)(programTable + 8)) = 0;
        *(undefined4 *)(*(int *)(programTable + 4) * 0x18 + *(int *)(programTable + 8) + 0xc) = 0xffffffff;
        *(undefined4 *)(*(int *)(programTable + 4) * 0x18 + *(int *)(programTable + 8) + 0x10) = 0;
        *(undefined4 *)(*(int *)(programTable + 4) * 0x18 + *(int *)(programTable + 8) + 4) = 0;
        *(undefined4 *)(*(int *)(programTable + 4) * 0x18 + *(int *)(programTable + 8) + 0x14) = 0;
        if (entryIndex < *(uint *)(((unsigned char *)0x00001270) + ctx)) {
          *(uint *)(((unsigned char *)0x00001270) + ctx) = *(uint *)(((unsigned char *)0x00001270) + ctx) - 1;
        }
      }
      loopIndex = loopIndex + 1;
      ids = ids + 1;
    } while (count != loopIndex);
  }
  return;
}

/* FUN_000a0ef0 @ 0xa0ef0 (144 bytes) */
int FUN_000a0ef0(param_1)
  int param_1;
{
  undefined4 uVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(((unsigned char *)0x0000112c) + param_1);
  puVar3[3] = 1;
  *puVar3 = 1;
  puVar3[4] = 1;
  puVar3[1] = 3;
  uVar1 = (**(code **)(param_1 + 0xc))(0xc0);
  puVar3[2] = uVar1;
  *(undefined4 *)(((unsigned char *)0x00001124) + param_1) = 0xffffffff;
  puVar2 = (undefined1 *)(**(code **)(param_1 + 0xc))(1);
  *(undefined1 **)(((unsigned char *)0x00001128) + param_1) = puVar2;
  *puVar2 = 0;
  *(undefined4 *)(((unsigned char *)0x00001130) + param_1) = 0;
  return arbfpInitProgramState(param_1);
}

/* noop_a0f80 @ 0xa0f80 (4 bytes) */
int noop_a0f80()
{
  return;
}

/* FUN_000a0f90 @ 0xa0f90 (152 bytes) */
int FUN_000a0f90(param_1)
  int param_1;
{
  uint uVar1;
  undefined *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  puVar2 = PTR_FUN_001e89f0;
  *(code **)(((unsigned char *)0x00001160) + param_1) = noop_a0f80;
  *(code **)(((unsigned char *)0x0000115c) + param_1) = noop_a0f80;
  *(undefined **)(((unsigned char *)0x00001164) + param_1) = puVar2;
  atifsResetState(param_1);
  uVar5 = *(uint *)(param_1 + 0x27bc);
  uVar4 = 0;
  iVar6 = 0x10;
  iVar3 = param_1;
  do {
    uVar1 = uVar4 & 0x3f;
    *(undefined4 *)(iVar3 + 0x27c0) = 0xff;
    uVar4 = uVar4 + 1;
    iVar3 = iVar3 + 4;
    uVar5 = 1 << uVar1 | uVar5;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  *(uint *)(param_1 + 0x27bc) = uVar5;
  return 1;
}

/* FUN_000a1040 @ 0xa1040 (20 bytes) */
int FUN_000a1040(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  if (param_2 != 0) {
    return 0x125;
  }
  return 2;
}

/* FUN_000a1060 @ 0xa1060 (44 bytes) */
int FUN_000a1060(param_1)
  int param_1;
{
  if (((param_1 != -0x1134) && (*(int *)(((unsigned char *)0x00001144) + param_1) != 0)) &&
     (*(char *)(*(int *)(((unsigned char *)0x00001144) + param_1) + 0x74) != '\0')) {
    return 1;
  }
  return 0;
}

