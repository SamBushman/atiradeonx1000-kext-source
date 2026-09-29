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
  unsigned int frame_[56] __attribute__((aligned(16)));
  
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
    iVar2 = FUN_00090ca0(param_1,1,param_1 + 0x4e4);
    if (iVar2 == 0) {
      uVar1 = *(undefined4 *)(param_1 + 0x4e8);
      iVar2 = FUN_00090ca0(param_1,2,((undefined1 *)((char *)frame_ + 56)));
      if (iVar2 == 0) {
        iVar2 = FUN_00090ca0(param_1,2,((undefined1 *)((char *)frame_ + 96)));
        if (iVar2 == 0) {
          uVar5 = **(undefined4 **)(param_1 + 0x3ec);
          uVar4 = **(undefined4 **)(param_1 + 0x3f0);
          (**(code **)(((unsigned char *)0x000012f0) + iVar3))
                    (param_1,uVar4,(*(undefined4 *)((char *)frame_ + 60)),((undefined1 *)((char *)frame_ + 64)),uVar5,(*(undefined4 *)((char *)frame_ + 60)),&DAT_001dbdb4,&DAT_001fa5e8,uVar5,(*(undefined4 *)((char *)frame_ + 60)),&DAT_001dbdb4,&DAT_001fa5e8)
          ;
          (*(undefined4 *)((char *)frame_ + 8)) = 4;
          (*(undefined4 *)((char *)frame_ + 12)) = 4;
          (*(undefined4 *)((char *)frame_ + 20)) = 4;
          (*(undefined4 *)((char *)frame_ + 16)) = (*(undefined4 *)((char *)frame_ + 88));
          (**(code **)(((unsigned char *)0x000012f4) + iVar3))
                    (param_1,uVar4,uVar1,&DAT_001dbd84,uVar5,(*(undefined4 *)((char *)frame_ + 60)),&(*(undefined4 *)((char *)frame_ + 80)),&DAT_001fa5e8,uVar5,(*(int *)((int)param_1 + 1216)),(&DAT_001dbd74),&DAT_001fa5e8,uVar5,(*(undefined4 *)((char *)frame_ + 60)),(&(*(undefined4 *)((char *)frame_ + 8))),&DAT_001fa5e8);
          (**(code **)(((unsigned char *)0x000012e4) + iVar3))
                    (param_1,uVar4,(*(undefined4 *)((char *)frame_ + 60)),((undefined1 *)((char *)frame_ + 64)),uVar5,uVar1,&DAT_001dbd74,&DAT_001fa5e8,uVar5,uVar1,&DAT_001dbd74,&DAT_001fa5e8);
          (**(code **)(((unsigned char *)0x00001318) + iVar3))
                    (param_1,uVar4,(*(undefined4 *)((char *)frame_ + 60)),((undefined1 *)((char *)frame_ + 64)),uVar5,(*(undefined4 *)((char *)frame_ + 60)),&(*(undefined4 *)((char *)frame_ + 80)),&DAT_001fa5e8);
          (**(code **)(((unsigned char *)0x0000131c) + iVar3))
                    (param_1,uVar4,(*(undefined4 *)((char *)frame_ + 100)),((undefined1 *)((char *)frame_ + 104)),uVar5,(*(undefined4 *)((char *)frame_ + 100)),&DAT_001dbdb4,&DAT_001dbd94)
          ;
          (*(undefined4 *)((char *)frame_ + 24)) = *(undefined4 *)(param_1 + 0x4d4);
          (*(undefined4 *)((char *)frame_ + 28)) = *(undefined4 *)(param_1 + 0x4d8);
          (*(undefined4 *)((char *)frame_ + 48)) = 4;
          (*(undefined4 *)((char *)frame_ + 16)) = 4;
          (*(undefined4 *)((char *)frame_ + 20)) = 4;
          (*(undefined4 *)((char *)frame_ + 8)) = (*(undefined4 *)((char *)frame_ + 80));
          (*(undefined4 *)((char *)frame_ + 12)) = (*(undefined4 *)((char *)frame_ + 84));
          (*(undefined4 *)((char *)frame_ + 32)) = 4;
          (*(undefined4 *)((char *)frame_ + 36)) = 4;
          (*(undefined4 *)((char *)frame_ + 40)) = (*(undefined4 *)((char *)frame_ + 120));
          (*(undefined4 *)((char *)frame_ + 44)) = (*(undefined4 *)((char *)frame_ + 124));
          (*(undefined4 *)((char *)frame_ + 52)) = (*(undefined4 *)((char *)frame_ + 132));
          (**(code **)(((unsigned char *)0x000012f4) + iVar3))
                    (param_1,uVar4,uVar1,&DAT_001dbd84,uVar5,(*(undefined4 *)((char *)frame_ + 60)),&(*(undefined4 *)((char *)frame_ + 8)),&DAT_001fa5e8,uVar5,(*(int *)((int)param_1 + 1216)),(&(*(undefined4 *)((char *)frame_ + 24))),&DAT_001fa5e8,uVar5,(*(undefined4 *)((char *)frame_ + 100)),(&(*(undefined4 *)((char *)frame_ + 40))),&DAT_001fa5e8);
          FUN_000911a0(param_1,((undefined1 *)((char *)frame_ + 56)));
          FUN_000911a0(param_1,((undefined1 *)((char *)frame_ + 96)));
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
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  uint uVar9;
  int iVarS1;
  int iVarS2;
  unsigned int frame_[60] __attribute__((aligned(16)));
  
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
  iVar2 = FUN_00090ca0(param_1,1,param_1 + 0x444);
  if ((iVar2 == 0) && (iVar2 = FUN_00090ca0(param_1,0,((undefined1 *)((char *)frame_ + 8))), iVar2 == 0)) {
    (*(undefined1 * *)((char *)frame_ + 148)) = ((undefined1 *)((char *)frame_ + 48));
    iVar2 = FUN_00090ca0(param_1,0,(*(undefined1 * *)((char *)frame_ + 148)));
    if (iVar2 == 0) {
      (*(undefined1 * *)((char *)frame_ + 156)) = ((undefined1 *)((char *)frame_ + 88));
      iVar2 = FUN_00090ca0(param_1,0,(*(undefined1 * *)((char *)frame_ + 156)));
      if (iVar2 == 0) {
        puVar7 = *(undefined4 **)(param_1 + 0x3ec);
        uVar6 = puVar7[2];
        uVar4 = **(undefined4 **)(param_1 + 0x3f0);
        if (param_3 == 0) {
          (*(undefined * *)((char *)frame_ + 136)) = &DAT_001e3520;
          (*(undefined * *)((char *)frame_ + 140)) = &DAT_001e3520;
          (*(undefined * *)((char *)frame_ + 144)) = &DAT_001e3520;
LAB_0009388c:
          uVar8 = *puVar7;
          uVar6 = *(undefined4 *)(param_1 + 0x448);
          iVarS1 = *(int *)((int)param_1 + 1376);
          (**(code **)(((unsigned char *)0x000012e4) + iVar3))
                    (param_1,uVar4,uVar6,(*(undefined * *)((char *)frame_ + 136)) + -0x781c,uVar8,(*(undefined4 *)((char *)frame_ + 12)),&DAT_001dbd14,
                     &DAT_001fa5e8,uVar8,iVarS1,&DAT_001dbd14,&DAT_001fa5e8);
          (**(code **)(((unsigned char *)0x000012e4) + iVar3))
                    (param_1,uVar4,uVar6,(*(undefined * *)((char *)frame_ + 140)) + -0x77bc,uVar8,(*(undefined4 *)((char *)frame_ + 52)),&DAT_001dbd14,
                     &DAT_001fa5e8,uVar8,iVarS1,&DAT_001dbd14,&DAT_001fa5e8);
          (**(code **)(((unsigned char *)0x000012e4) + iVar3))
                    (param_1,uVar4,uVar6,(*(undefined * *)((char *)frame_ + 144)) + -0x77cc,uVar8,(*(undefined4 *)((char *)frame_ + 92)),&DAT_001dbd14,
                     &DAT_001fa5e8,uVar8,iVarS1,&DAT_001dbd14,&DAT_001fa5e8);
          FUN_000911a0(param_1,((undefined1 *)((char *)frame_ + 8)));
          FUN_000911a0(param_1,(*(undefined1 * *)((char *)frame_ + 148)));
          FUN_000911a0(param_1,(*(undefined1 * *)((char *)frame_ + 156)));
          return 0;
        }
        (*(int * *)((char *)frame_ + 152)) = (int *)(param_1 + 0xc4);
        (*(undefined * *)((char *)frame_ + 136)) = &DAT_001e3520;
        (*(undefined * *)((char *)frame_ + 140)) = &DAT_001e3520;
        (*(undefined * *)((char *)frame_ + 144)) = &DAT_001e3520;
LAB_00093754:
        uVar9 = 0;
        puVar7 = (undefined4 *)((*(undefined * *)((char *)frame_ + 136)) + -0x781c);
        piVar5 = (*(int * *)((char *)frame_ + 152));
        do {
          iVar2 = *piVar5;
          uVar9 = uVar9 + 1;
          iVarS2 = *(int *)((int)*(int *)((int)param_1 + 1004) + 4);
          (**(code **)(((unsigned char *)0x000012e4) + iVar3))
                    (param_1,uVar4,(*(undefined4 *)((char *)frame_ + 12)),puVar7,uVar6,iVar2,&DAT_001dbd74,&DAT_001fa5e8,iVarS2,(*(int *)(param_2 + (uVar9 - 1) * 4) == 0 ? *(int *)(param_1 + 4) : (*(int *)(param_2 + (uVar9 - 1) * 4) == 1 ? *(int *)(param_1 + 100) : 0)),&DAT_001dbd74,&DAT_001fa5e8);
          (**(code **)(((unsigned char *)0x000012e4) + iVar3))
                    (param_1,uVar4,(*(undefined4 *)((char *)frame_ + 52)),puVar7,uVar6,iVar2 + 1,&DAT_001dbd74,&DAT_001fa5e8,iVarS2,(*(int *)(param_2 + (uVar9 - 1) * 4) == 0 ? *(int *)(param_1 + 4) : (*(int *)(param_2 + (uVar9 - 1) * 4) == 1 ? *(int *)(param_1 + 100) : 0)),&DAT_001dbd74,&DAT_001fa5e8);
          (**(code **)(((unsigned char *)0x000012e4) + iVar3))
                    (param_1,uVar4,(*(undefined4 *)((char *)frame_ + 92)),puVar7,uVar6,iVar2 + 2,&DAT_001dbd74,&DAT_001fa5e8,iVarS2,(*(int *)(param_2 + (uVar9 - 1) * 4) == 0 ? *(int *)(param_1 + 4) : (*(int *)(param_2 + (uVar9 - 1) * 4) == 1 ? *(int *)(param_1 + 100) : 0)),&DAT_001dbd74,&DAT_001fa5e8);
          if (param_3 <= uVar9) {
            puVar7 = *(undefined4 **)(param_1 + 0x3ec);
            goto LAB_0009388c;
          }
          if (uVar9 == 1) {
            puVar7 = (undefined4 *)((*(undefined * *)((char *)frame_ + 140)) + -0x77bc);
          }
          else {
            if (uVar9 == 0) goto LAB_00093754;
            if (uVar9 == 2) {
              puVar7 = (undefined4 *)((*(undefined * *)((char *)frame_ + 144)) + -0x77cc);
            }
            else {
              puVar7 = (undefined4 *)0x0;
              if (uVar9 == 3) {
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
  unsigned int frame_[116] __attribute__((aligned(16)));
  
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
        (*(undefined1 * *)((char *)frame_ + 360)) = ((undefined1 *)((char *)frame_ + 48));
        iVar2 = FUN_00090ca0(param_1,0,(*(undefined1 * *)((char *)frame_ + 360)));
        if ((iVar2 == 0) && (iVar2 = FUN_00090ca0(param_1,0,((undefined1 *)((char *)frame_ + 8))), iVar2 == 0)) {
          (*(undefined1 * *)((char *)frame_ + 332)) = ((undefined1 *)((char *)frame_ + 128));
          iVar2 = FUN_00090ca0(param_1,0,(*(undefined1 * *)((char *)frame_ + 332)));
          if (iVar2 == 0) {
            (*(undefined1 * *)((char *)frame_ + 340)) = ((undefined1 *)((char *)frame_ + 168));
            iVar2 = FUN_00090ca0(param_1,0,(*(undefined1 * *)((char *)frame_ + 340)));
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
                  iVar2 = FUN_00090ca0(param_1,0,((undefined1 *)((char *)frame_ + 88)));
                  if (iVar2 != 0) {
                    return 7;
                  }
                  uVar8 = *(undefined4 *)param_1[0xfc];
                  iVar2 = (*(int *)((char *)frame_ + 92));
                }
                (*(undefined * *)((char *)frame_ + 328)) = &DAT_001e3a54;
                (*(undefined * *)((char *)frame_ + 336)) = &DAT_001f3a54;
                iVarS1 = *(int *)((int)param_1 + 1376);
                (**(code **)(((unsigned char *)0x000012e4) + iVar4))
                          (param_1,uVar8,iVar2,&DAT_001dbd04,uVar7,(*(undefined4 *)((char *)frame_ + 52)),&DAT_001dbd14,
                           &DAT_001fa5e8,uVar7,iVarS1,&DAT_001dbd14,&DAT_001fa5e8);
                (**(code **)(((unsigned char *)0x000012e4) + iVar4))
                          (param_1,uVar8,iVar2,&DAT_001dbd64,uVar7,(*(int *)((char *)frame_ + 12)),&DAT_001dbd14,
                           &DAT_001fa5e8,uVar7,iVarS1,&DAT_001dbd14,&DAT_001fa5e8);
                (**(code **)(((unsigned char *)0x000012e4) + iVar4))
                          (param_1,uVar8,iVar2,&DAT_001dbd54,uVar7,(*(undefined4 *)((char *)frame_ + 132)),&DAT_001dbd14,
                           &DAT_001fa5e8,uVar7,iVarS1,&DAT_001dbd14,&DAT_001fa5e8);
                if ((*(char *)(param_1 + 0x1d1) == '\0') || (param_1[0x1a8] != -1)) {
                  iVarS2 = *(int *)((int)param_1 + 1376);
                  (**(code **)(((unsigned char *)0x000012e4) + iVar4))
                            (param_1,uVar8,iVar2,&DAT_001dbd44,uVar7,((undefined4 *)((char *)frame_ + 172))[0],&DAT_001dbd14,
                             &DAT_001fa5e8,uVar7,iVarS2,&DAT_001dbd14,&DAT_001fa5e8);
                  FUN_000911a0(param_1,(*(undefined1 * *)((char *)frame_ + 360)));
                  FUN_000911a0(param_1,((undefined1 *)((char *)frame_ + 8)));
                  FUN_000911a0(param_1,(*(undefined1 * *)((char *)frame_ + 332)));
                  FUN_000911a0(param_1,(*(undefined1 * *)((char *)frame_ + 340)));
                }
                else {
                  iVarS3 = *(int *)((int)param_1 + 1376);
                  (**(code **)(((unsigned char *)0x000012e4) + iVar4))
                            (param_1,*(undefined4 *)param_1[0xfc],(*(undefined4 *)((char *)frame_ + 52)),&DAT_001dbd44,uVar7,
                             ((undefined4 *)((char *)frame_ + 172))[0],&DAT_001dbd14,&DAT_001fa5e8,uVar7,iVarS3,&DAT_001dbd14,&DAT_001fa5e8);
                  (**(code **)(((unsigned char *)0x000012e8) + iVar4))
                            (param_1,uVar8,iVar2,&DAT_001dbd44,uVar7,(*(undefined4 *)((char *)frame_ + 52)),&DAT_001dbcd4,
                             &DAT_001fa5e8);
                  FUN_00091980(param_1,uVar7,(*(undefined4 *)((char *)frame_ + 52)));
                  FUN_000911a0(param_1,(*(undefined1 * *)((char *)frame_ + 360)));
                  FUN_000911a0(param_1,((undefined1 *)((char *)frame_ + 8)));
                  FUN_000911a0(param_1,(*(undefined1 * *)((char *)frame_ + 332)));
                  FUN_000911a0(param_1,(*(undefined1 * *)((char *)frame_ + 340)));
                  if (param_1[0x1a8] == -1) {
                    FUN_000911a0(param_1,((undefined1 *)((char *)frame_ + 88)));
                    return 2;
                  }
                }
                if (!bVar1) {
                  puVar11 = (*(undefined * *)((char *)frame_ + 328)) + -0x7d40;
                  puVar10 = (*(undefined * *)((char *)frame_ + 336)) + 0x6b94;
                  (**(code **)(((unsigned char *)0x000012e8) + iVar4))
                            (param_1,*(undefined4 *)(param_1[0xfc] + 8),param_1[0x1a],&DAT_001dbd24,
                             uVar7,(*(int *)((char *)frame_ + 92)),puVar11,puVar10);
                  (**(code **)(((unsigned char *)0x000012e8) + iVar4))
                            (param_1,*(undefined4 *)(param_1[0xfc] + 0x14),
                             param_1[uStack0000002c + 0x21],&DAT_001dbd24,uVar7,(*(int *)((char *)frame_ + 92)),puVar11,
                             puVar10);
                  FUN_000911a0(param_1,((undefined1 *)((char *)frame_ + 88)));
                }
                return 0;
              }
              (*(undefined * *)((char *)frame_ + 328)) = &DAT_001e3a54;
              (*(undefined * *)((char *)frame_ + 336)) = &DAT_001f3a54;
              (*(undefined * *)((char *)frame_ + 348)) = &DAT_001e3a54;
LAB_00094348:
              uVar15 = 0;
              puVar3 = (undefined4 *)((*(undefined * *)((char *)frame_ + 348)) + -0x7d50);
              piVar6 = param_1 + 0x29;
              do {
                iVar2 = *piVar6;
                uVar15 = uVar15 + 1;
                puVar11 = (*(undefined * *)((char *)frame_ + 328)) + -0x7d40;
                puVar10 = (*(undefined * *)((char *)frame_ + 336)) + 0x6b94;
                iVarS4 = *(int *)((int)*(int *)((int)param_1 + 1004) + 4);
                (**(code **)(((unsigned char *)0x000012e4) + iVar4))
                          (param_1,uVar8,(*(undefined4 *)((char *)frame_ + 52)),puVar3,uVar13,iVar2,puVar11,puVar10,iVarS4,iVar4,puVar11,puVar10);
                (**(code **)(((unsigned char *)0x000012e4) + iVar4))
                          (param_1,uVar8,(*(int *)((char *)frame_ + 12)),puVar3,uVar13,iVar2 + 1,puVar11,puVar10,iVarS4,iVar4,puVar11,puVar10);
                (**(code **)(((unsigned char *)0x000012e4) + iVar4))
                          (param_1,uVar8,(*(undefined4 *)((char *)frame_ + 132)),puVar3,uVar13,iVar2 + 2,puVar11,puVar10,iVarS4,iVar4,puVar11,puVar10);
                (**(code **)(((unsigned char *)0x000012e4) + iVar4))
                          (param_1,uVar8,((undefined4 *)((char *)frame_ + 172))[0],puVar3,uVar13,iVar2 + 3,puVar11,puVar10,iVarS4,iVar4,puVar11,puVar10);
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
      (*(undefined1 * *)((char *)frame_ + 340)) = ((undefined1 *)((char *)frame_ + 168));
      iVar2 = FUN_00090ca0(param_1,0,(*(undefined1 * *)((char *)frame_ + 340)));
      if (iVar2 != 0) {
        return 7;
      }
      (*(undefined1 * *)((char *)frame_ + 344)) = ((undefined1 *)((char *)frame_ + 208));
      iVar2 = FUN_00090ca0(param_1,0,(*(undefined1 * *)((char *)frame_ + 344)));
      if (iVar2 != 0) {
        return 7;
      }
      (*(undefined1 * *)((char *)frame_ + 352)) = ((undefined1 *)((char *)frame_ + 248));
      iVar2 = FUN_00090ca0(param_1,0,(*(undefined1 * *)((char *)frame_ + 352)));
      if (iVar2 != 0) {
        return 7;
      }
      (*(undefined1 * *)((char *)frame_ + 356)) = ((undefined1 *)((char *)frame_ + 288));
      iVar2 = FUN_00090ca0(param_1,0,(*(undefined1 * *)((char *)frame_ + 356)));
      if (iVar2 != 0) {
        return 7;
      }
      iVar2 = FUN_00090ca0(param_1,0,((undefined1 *)((char *)frame_ + 8)));
      if (iVar2 != 0) {
        return 7;
      }
      puVar5 = (undefined4 *)param_1[0xfb];
      puVar3 = (undefined4 *)param_1[0xfc];
      uVar7 = *puVar5;
      uVar13 = *puVar3;
      uVar8 = puVar5[2];
      if (param_3 == 0) {
        (*(undefined * *)((char *)frame_ + 380)) = &DAT_001e3a54;
        (*(undefined * *)((char *)frame_ + 328)) = &DAT_001e3a54;
        (*(undefined * *)((char *)frame_ + 336)) = &DAT_001f3a54;
        (*(undefined * *)((char *)frame_ + 364)) = &DAT_001e3a54;
        (*(undefined * *)((char *)frame_ + 376)) = &DAT_001e3a54;
        (*(undefined * *)((char *)frame_ + 372)) = &DAT_001e3a54;
        (*(undefined * *)((char *)frame_ + 368)) = &DAT_001f3a54;
      }
      else {
        (*(undefined * *)((char *)frame_ + 380)) = &DAT_001e3a54;
        (*(undefined * *)((char *)frame_ + 328)) = &DAT_001e3a54;
        (*(undefined * *)((char *)frame_ + 336)) = &DAT_001f3a54;
        (*(undefined * *)((char *)frame_ + 364)) = &DAT_001e3a54;
        (*(undefined * *)((char *)frame_ + 372)) = &DAT_001e3a54;
        (*(undefined * *)((char *)frame_ + 376)) = &DAT_001e3a54;
        uVar15 = 0;
        (*(undefined * *)((char *)frame_ + 368)) = &DAT_001f3a54;
        puVar3 = ((undefined4 *)((char *)frame_ + 172));
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
          iVarS22 = (int)(*(undefined * *)((char *)frame_ + 364)) + -32128;
          (**(code **)(((unsigned char *)0x000012ec) + iVar4))
                    (param_1,uVar13,uVar14,&DAT_001dbd24,uVar8,iVar2 + 3,&DAT_001dbd14,&DAT_001fa5e8,iVarS21,iVar4,iVarS22,&DAT_001fa5e8);
          iVarS14 = *(int *)((int)*(int *)((int)param_1 + 1004) + 4);
          iVarS15 = (int)(*(undefined * *)((char *)frame_ + 376)) + -32096;
          (**(code **)(((unsigned char *)0x000012f4) + iVar4))
                    (param_1,uVar13,uVar14,&DAT_001dbd24,uVar8,iVar2 + 2,&DAT_001dbd14,&DAT_001fa5e8
                    ,iVarS14,iVar4,iVarS15,&DAT_001fa5e8,uVar13,uVar14,&DAT_001dbd14,&DAT_001fa5e8);
          iVarS16 = (int)(*(undefined * *)((char *)frame_ + 372)) + -32112;
          (**(code **)(((unsigned char *)0x000012f4) + iVar4))
                    (param_1,uVar13,uVar14,&DAT_001dbd24,uVar8,iVar2 + 1,&DAT_001dbd14,&DAT_001fa5e8
                    ,iVarS14,iVar4,iVarS16,&DAT_001fa5e8,uVar13,uVar14,&DAT_001dbd14,&DAT_001fa5e8);
          iVarS17 = (int)(*(undefined * *)((char *)frame_ + 368)) + 27556;
          (**(code **)(((unsigned char *)0x000012f4) + iVar4))
                    (param_1,uVar13,uVar14,&DAT_001dbd24,uVar8,iVar2,&DAT_001dbd14,&DAT_001fa5e8,iVarS14,iVar4,iVarS17,&DAT_001fa5e8,uVar13,uVar14,&DAT_001dbd14,&DAT_001fa5e8);
        } while (param_3 != uVar15);
        puVar3 = (undefined4 *)param_1[0xfc];
        puVar5 = (undefined4 *)param_1[0xfb];
      }
      iVar2 = (*(int *)((char *)frame_ + 12));
      if (bVar1) {
        uVar8 = puVar3[2];
        iVar9 = param_1[0x1a];
      }
      else {
        uVar8 = *puVar3;
        iVar9 = (*(int *)((char *)frame_ + 12));
      }
      uVar13 = *puVar5;
      puVar12 = (*(undefined * *)((char *)frame_ + 336)) + 0x6b94;
      puVar11 = (*(undefined * *)((char *)frame_ + 328)) + -0x7d40;
      puVar10 = (*(undefined * *)((char *)frame_ + 380)) + -0x7d30;
      iVarS12 = *(int *)((int)param_1 + 1376);
      iVarS13 = (int)(*(undefined * *)((char *)frame_ + 364)) + -32128;
      (**(code **)(((unsigned char *)0x000012ec) + iVar4))
                (param_1,uVar13,(*(int *)((char *)frame_ + 12)),puVar10,uVar7,(*(undefined4 *)((char *)frame_ + 292)),puVar11,puVar12,uVar13,iVarS12,iVarS13,puVar12);
      iVarS7 = *(int *)((int)param_1 + 1376);
      iVarS8 = *(int *)((int)*(int *)((int)param_1 + 980) + 4852);
      iVarS23 = *(int *)((int)param_1 + 1376);
      iVarS24 = (int)(*(undefined * *)((char *)frame_ + 376)) + -32096;
      (**(code **)(((unsigned char *)0x000012f4) + iVar4))
                (param_1,uVar13,iVar2,puVar10,uVar7,(*(undefined4 *)((char *)frame_ + 252)),puVar11,puVar12,uVar13,iVarS23,iVarS24,puVar12,uVar13,iVar2,puVar11,puVar12);
      iVarS9 = *(int *)((int)*(int *)((int)param_1 + 980) + 4852);
      iVarS25 = (int)(*(undefined * *)((char *)frame_ + 372)) + -32112;
      (**(code **)(((unsigned char *)0x000012f4) + iVar4))
                (param_1,uVar13,iVar2,puVar10,uVar7,(*(undefined4 *)((char *)frame_ + 212)),puVar11,puVar12,uVar13,iVarS23,iVarS25,puVar12,uVar13,iVar2,puVar11,puVar12);
      if ((*(char *)(param_1 + 0x1d1) == '\0') || (param_1[0x1a8] != -1)) {
        iVarS18 = *(int *)((int)param_1 + 1376);
        iVarS19 = (int)(*(undefined * *)((char *)frame_ + 368)) + 27556;
        iVarS20 = (*(int *)((char *)frame_ + 12));
        (**(code **)(((unsigned char *)0x000012f4) + iVar4))
                  (param_1,uVar8,iVar9,puVar10,uVar7,((undefined4 *)((char *)frame_ + 172))[0],puVar11,puVar12,uVar7,iVarS18,iVarS19,puVar12,uVar7,iVarS20,puVar11,puVar12);
      }
      else {
        iVarS10 = *(int *)((int)param_1 + 1376);
        iVarS11 = *(int *)((int)*(int *)((int)param_1 + 980) + 4852);
        iVarS26 = *(int *)((int)param_1 + 1376);
        iVarS27 = (int)(*(undefined * *)((char *)frame_ + 368)) + 27556;
        (**(code **)(((unsigned char *)0x000012f4) + iVar4))
                  (param_1,uVar13,iVar2,puVar10,uVar7,((undefined4 *)((char *)frame_ + 172))[0],puVar11,puVar12,uVar13,iVarS26,iVarS27,puVar12,uVar13,iVar2,puVar11,puVar12);
        if (bVar1) {
          (**(code **)(((unsigned char *)0x000012e8) + iVar4))
                    (param_1,*(undefined4 *)(param_1[0xfc] + 8),param_1[0x1a],puVar10,uVar7,
                     (*(int *)((char *)frame_ + 12)),puVar11,puVar12);
        }
        FUN_00091980(param_1,uVar7,(*(int *)((char *)frame_ + 12)));
        if (param_1[0x1a8] == -1) {
          FUN_000911a0(param_1,(*(undefined1 * *)((char *)frame_ + 340)));
          FUN_000911a0(param_1,(*(undefined1 * *)((char *)frame_ + 344)));
          FUN_000911a0(param_1,(*(undefined1 * *)((char *)frame_ + 352)));
          FUN_000911a0(param_1,(*(undefined1 * *)((char *)frame_ + 356)));
          FUN_000911a0(param_1,((undefined1 *)((char *)frame_ + 8)));
          return 2;
        }
      }
      if (!bVar1) {
        puVar12 = (*(undefined * *)((char *)frame_ + 380)) + -0x7d30;
        puVar11 = (*(undefined * *)((char *)frame_ + 328)) + -0x7d40;
        puVar10 = (*(undefined * *)((char *)frame_ + 336)) + 0x6b94;
        (**(code **)(((unsigned char *)0x000012e8) + iVar4))
                  (param_1,*(undefined4 *)(param_1[0xfc] + 8),param_1[0x1a],puVar12,uVar7,(*(int *)((char *)frame_ + 12)),
                   puVar11,puVar10);
        (**(code **)(((unsigned char *)0x000012e8) + iVar4))
                  (param_1,*(undefined4 *)(param_1[0xfc] + 0x14),param_1[uStack0000002c + 0x21],
                   puVar12,uVar7,(*(int *)((char *)frame_ + 12)),puVar11,puVar10);
      }
      FUN_000911a0(param_1,(*(undefined1 * *)((char *)frame_ + 340)));
      FUN_000911a0(param_1,(*(undefined1 * *)((char *)frame_ + 344)));
      FUN_000911a0(param_1,(*(undefined1 * *)((char *)frame_ + 352)));
      FUN_000911a0(param_1,(*(undefined1 * *)((char *)frame_ + 356)));
      FUN_000911a0(param_1,((undefined1 *)((char *)frame_ + 8)));
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
  unsigned int frame_[112] __attribute__((aligned(16)));
  
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
    iVar3 = FUN_00090ca0(param_1,0,param_1 + 0xfd);
    if ((iVar3 == 0) && (iVar3 = FUN_00090ca0(param_1,0,((undefined1 *)((char *)frame_ + 8))), iVar3 == 0)) {
      iVar3 = FUN_00090ca0(param_1,0,((undefined1 *)((char *)frame_ + 48)));
      if (iVar3 == 0) {
        (*(undefined1 * *)((char *)frame_ + 352)) = ((undefined1 *)((char *)frame_ + 88));
        iVar3 = FUN_00090ca0(param_1,0,(*(undefined1 * *)((char *)frame_ + 352)));
        if (iVar3 == 0) {
          (*(undefined1 * *)((char *)frame_ + 296)) = ((undefined1 *)((char *)frame_ + 128));
          iVar3 = FUN_00090ca0(param_1,0,(*(undefined1 * *)((char *)frame_ + 296)));
          if (iVar3 == 0) {
            puVar8 = (undefined4 *)param_1[0xfb];
            uVar6 = puVar8[2];
            uVar5 = *(undefined4 *)param_1[0xfc];
            if ((param_3 < 3) && (param_5 != 0)) {
              if (param_3 != 0) {
                (*(code * *)((char *)frame_ + 312)) = FUN_001d4850;
                (*(undefined ** *)((char *)frame_ + 308)) = &PTR_DAT_001f4850;
                (*(code * *)((char *)frame_ + 340)) = FUN_001d4850;
                (*(code * *)((char *)frame_ + 344)) = FUN_001d4850;
                (*(code * *)((char *)frame_ + 348)) = FUN_001d4850;
                (*(code * *)((char *)frame_ + 336)) = FUN_001d4850;
                do {
                  uVar13 = 0;
                  uVar10 = (*(undefined4 *)((char *)frame_ + 12));
                  piVar4 = param_1 + 0x2d;
                  while( true ) {
                    iVar3 = *piVar4;
                    uVar13 = uVar13 + 1;
                    pcVar7 = (*(code * *)((char *)frame_ + 312)) + 0x74c4;
                    ppuVar12 = (*(undefined ** *)((char *)frame_ + 308)) + 0x1766;
                    iVarS1 = *(int *)((int)*(int *)((int)param_1 + 1004) + 4);
                    (**(code **)(((unsigned char *)0x000012e4) + iVar2))
                              (param_1,uVar5,uVar10,(*(code * *)((char *)frame_ + 340)) + 0x74b4,uVar6,iVar3,pcVar7,ppuVar12,iVarS1,iVar2,pcVar7,ppuVar12);
                    (**(code **)(((unsigned char *)0x000012e4) + iVar2))
                              (param_1,uVar5,uVar10,(*(code * *)((char *)frame_ + 344)) + 0x7514,uVar6,iVar3 + 1,pcVar7,
                               ppuVar12,iVarS1,iVar2,pcVar7,ppuVar12);
                    (**(code **)(((unsigned char *)0x000012e4) + iVar2))
                              (param_1,uVar5,uVar10,(*(code * *)((char *)frame_ + 348)) + 0x7504,uVar6,iVar3 + 2,pcVar7,
                               ppuVar12,iVarS1,iVar2,pcVar7,ppuVar12);
                    (**(code **)(((unsigned char *)0x000012e4) + iVar2))
                              (param_1,uVar5,uVar10,(*(code * *)((char *)frame_ + 336)) + 0x74f4,uVar6,iVar3 + 3,pcVar7,
                               ppuVar12,iVarS1,iVar2,pcVar7,ppuVar12);
                    if (param_3 <= uVar13) {
                      puVar8 = (undefined4 *)param_1[0xfb];
                      goto LAB_0009510c;
                    }
                    if (uVar13 == 0) break;
                    uVar10 = 0;
                    if (uVar13 == 1) {
                      uVar10 = (*(undefined4 *)((char *)frame_ + 52));
                    }
                    piVar4 = piVar4 + 1;
                  }
                } while( true );
              }
              (*(code * *)((char *)frame_ + 312)) = FUN_001d4850;
              (*(undefined ** *)((char *)frame_ + 308)) = &PTR_DAT_001f4850;
LAB_0009510c:
              uVar6 = *puVar8;
              iVar3 = param_1[0xfe];
              ppuVar12 = (*(undefined ** *)((char *)frame_ + 308)) + 0x1766;
              iVarS4 = (*(undefined4 *)((char *)frame_ + 12));
              iVarS5 = (int)(*(code * *)((char *)frame_ + 312)) + 29892;
              (**(code **)(((unsigned char *)0x000012ec) + iVar2))
                        (param_1,uVar5,iVar3,&DAT_001dbd24,uVar6,iVar1,&DAT_001fa5f8,ppuVar12,uVar6,iVarS4,iVarS5,ppuVar12);
              iVarS10 = (*(undefined4 *)((char *)frame_ + 52));
              iVarS11 = (int)(*(code * *)((char *)frame_ + 312)) + 29892;
              (**(code **)(((unsigned char *)0x000012f4) + iVar2))
                        (param_1,uVar5,iVar3,&DAT_001dbd24,uVar6,iVar1,&DAT_001dbce4,ppuVar12,uVar6,iVarS10,iVarS11,ppuVar12,uVar6,iVar3,iVarS11,ppuVar12);
            }
            else {
              if (param_3 != 0) {
                (*(code * *)((char *)frame_ + 312)) = FUN_001d4850;
                (*(undefined ** *)((char *)frame_ + 308)) = &PTR_DAT_001f4850;
                (*(code * *)((char *)frame_ + 340)) = FUN_001d4850;
                (*(code * *)((char *)frame_ + 344)) = FUN_001d4850;
                (*(code * *)((char *)frame_ + 348)) = FUN_001d4850;
                (*(code * *)((char *)frame_ + 336)) = FUN_001d4850;
LAB_00095234:
                uVar13 = 0;
                pcVar7 = (*(code * *)((char *)frame_ + 340)) + 0x74b4;
                piVar4 = param_1 + 0x2d;
                do {
                  iVar1 = *piVar4;
                  uVar13 = uVar13 + 1;
                  pcVar9 = (*(code * *)((char *)frame_ + 312)) + 0x74c4;
                  ppuVar12 = (*(undefined ** *)((char *)frame_ + 308)) + 0x1766;
                  iVarS2 = *(int *)((int)*(int *)((int)param_1 + 1004) + 4);
                  (**(code **)(((unsigned char *)0x000012e4) + iVar2))
                            (param_1,uVar5,(*(undefined4 *)((char *)frame_ + 12)),pcVar7,uVar6,iVar1,pcVar9,ppuVar12,iVarS2,iVar2,pcVar9,ppuVar12);
                  (**(code **)(((unsigned char *)0x000012e4) + iVar2))
                            (param_1,uVar5,(*(undefined4 *)((char *)frame_ + 52)),pcVar7,uVar6,iVar1 + 1,pcVar9,ppuVar12,iVarS2,iVar2,pcVar9,ppuVar12);
                  (**(code **)(((unsigned char *)0x000012e4) + iVar2))
                            (param_1,uVar5,(*(undefined4 *)((char *)frame_ + 92)),pcVar7,uVar6,iVar1 + 2,pcVar9,ppuVar12,iVarS2,iVar2,pcVar9,ppuVar12);
                  (**(code **)(((unsigned char *)0x000012e4) + iVar2))
                            (param_1,uVar5,((undefined4 *)((char *)frame_ + 132))[0],pcVar7,uVar6,iVar1 + 3,pcVar9,ppuVar12,iVarS2,iVar2,pcVar9,ppuVar12);
                  if (param_3 <= uVar13) {
                    puVar8 = (undefined4 *)param_1[0xfb];
                    goto LAB_000953b4;
                  }
                  if (uVar13 == 1) {
                    pcVar7 = (*(code * *)((char *)frame_ + 344)) + 0x7514;
                  }
                  else {
                    if (uVar13 == 0) goto LAB_00095234;
                    if (uVar13 == 2) {
                      pcVar7 = (*(code * *)((char *)frame_ + 348)) + 0x7504;
                    }
                    else {
                      pcVar7 = (code *)0x0;
                      if (uVar13 == 3) {
                        pcVar7 = (*(code * *)((char *)frame_ + 336)) + 0x74f4;
                      }
                    }
                  }
                  piVar4 = piVar4 + 1;
                } while( true );
              }
              (*(code * *)((char *)frame_ + 312)) = FUN_001d4850;
              (*(undefined ** *)((char *)frame_ + 308)) = &PTR_DAT_001f4850;
              (*(code * *)((char *)frame_ + 340)) = FUN_001d4850;
              (*(code * *)((char *)frame_ + 344)) = FUN_001d4850;
              (*(code * *)((char *)frame_ + 348)) = FUN_001d4850;
              (*(code * *)((char *)frame_ + 336)) = FUN_001d4850;
LAB_000953b4:
              uVar6 = *puVar8;
              iVar1 = param_1[0xfe];
              pcVar7 = (*(code * *)((char *)frame_ + 312)) + 0x74c4;
              ppuVar12 = (*(undefined ** *)((char *)frame_ + 308)) + 0x1766;
              iVarS3 = *(int *)((int)param_1 + 1376);
              (**(code **)(((unsigned char *)0x000012e4) + iVar2))
                        (param_1,uVar5,iVar1,(*(code * *)((char *)frame_ + 340)) + 0x74b4,uVar6,(*(undefined4 *)((char *)frame_ + 12)),pcVar7,ppuVar12,uVar6,iVarS3,pcVar7,ppuVar12);
              (**(code **)(((unsigned char *)0x000012e4) + iVar2))
                        (param_1,uVar5,iVar1,(*(code * *)((char *)frame_ + 344)) + 0x7514,uVar6,(*(undefined4 *)((char *)frame_ + 52)),pcVar7,ppuVar12,uVar6,iVarS3,pcVar7,ppuVar12);
              (**(code **)(((unsigned char *)0x000012e4) + iVar2))
                        (param_1,uVar5,iVar1,(*(code * *)((char *)frame_ + 348)) + 0x7504,uVar6,(*(undefined4 *)((char *)frame_ + 92)),pcVar7,ppuVar12,uVar6,iVarS3,pcVar7,ppuVar12);
              (**(code **)(((unsigned char *)0x000012e4) + iVar2))
                        (param_1,uVar5,iVar1,(*(code * *)((char *)frame_ + 336)) + 0x74f4,uVar6,((undefined4 *)((char *)frame_ + 132))[0],pcVar7,ppuVar12,uVar6,iVarS3,pcVar7,ppuVar12);
            }
            FUN_000911a0(param_1,((undefined1 *)((char *)frame_ + 8)));
            FUN_000911a0(param_1,((undefined1 *)((char *)frame_ + 48)));
            FUN_000911a0(param_1,(*(undefined1 * *)((char *)frame_ + 352)));
            FUN_000911a0(param_1,(*(undefined1 * *)((char *)frame_ + 296)));
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
    iVar1 = FUN_00090ca0(param_1,0,param_1 + 0xfd);
    if (iVar1 == 0) {
      (*(undefined1 * *)((char *)frame_ + 296)) = ((undefined1 *)((char *)frame_ + 128));
      iVar1 = FUN_00090ca0(param_1,0,(*(undefined1 * *)((char *)frame_ + 296)));
      if (iVar1 == 0) {
        (*(undefined1 * *)((char *)frame_ + 300)) = ((undefined1 *)((char *)frame_ + 168));
        iVar1 = FUN_00090ca0(param_1,0,(*(undefined1 * *)((char *)frame_ + 300)));
        if (iVar1 == 0) {
          (*(undefined1 * *)((char *)frame_ + 304)) = ((undefined1 *)((char *)frame_ + 208));
          iVar1 = FUN_00090ca0(param_1,0,(*(undefined1 * *)((char *)frame_ + 304)));
          if (iVar1 == 0) {
            (*(undefined1 * *)((char *)frame_ + 316)) = ((undefined1 *)((char *)frame_ + 248));
            iVar1 = FUN_00090ca0(param_1,0,(*(undefined1 * *)((char *)frame_ + 316)));
            if (iVar1 == 0) {
              puVar8 = (undefined4 *)param_1[0xfb];
              uVar5 = *puVar8;
              uVar10 = *(undefined4 *)param_1[0xfc];
              uVar6 = puVar8[2];
              if (param_3 == 0) {
                (*(code * *)((char *)frame_ + 356)) = FUN_001d4850;
                (*(code * *)((char *)frame_ + 312)) = FUN_001d4850;
                (*(undefined ** *)((char *)frame_ + 308)) = &PTR_DAT_001f4850;
                (*(code * *)((char *)frame_ + 320)) = FUN_001d4850;
                (*(code * *)((char *)frame_ + 332)) = FUN_001d4850;
                (*(code * *)((char *)frame_ + 328)) = FUN_001d4850;
                (*(undefined ** *)((char *)frame_ + 324)) = &PTR_DAT_001f4850;
              }
              else {
                (*(code * *)((char *)frame_ + 356)) = FUN_001d4850;
                (*(code * *)((char *)frame_ + 312)) = FUN_001d4850;
                (*(undefined ** *)((char *)frame_ + 308)) = &PTR_DAT_001f4850;
                (*(code * *)((char *)frame_ + 320)) = FUN_001d4850;
                (*(code * *)((char *)frame_ + 328)) = FUN_001d4850;
                (*(code * *)((char *)frame_ + 332)) = FUN_001d4850;
                uVar13 = 0;
                (*(undefined ** *)((char *)frame_ + 324)) = &PTR_DAT_001f4850;
                puVar8 = ((undefined4 *)((char *)frame_ + 132));
                piVar4 = param_1;
                do {
                  iVar1 = piVar4[0x2d];
                  uVar11 = *puVar8;
                  uVar13 = uVar13 + 1;
                  piVar4 = piVar4 + 1;
                  puVar8 = puVar8 + 10;
                  iVarS6 = *(int *)((int)*(int *)((int)param_1 + 1004) + 4);
                  iVarS7 = (int)(*(code * *)((char *)frame_ + 320)) + 29828;
                  (**(code **)(((unsigned char *)0x000012ec) + iVar2))
                            (param_1,uVar10,uVar11,&DAT_001dbd24,uVar6,iVar1 + 3,&DAT_001dbd14,
                             &DAT_001fa5e8,iVarS6,iVar2,iVarS7,&DAT_001fa5e8);
                  iVarS12 = *(int *)((int)*(int *)((int)param_1 + 1004) + 4);
                  iVarS13 = (int)(*(code * *)((char *)frame_ + 332)) + 29860;
                  (**(code **)(((unsigned char *)0x000012f4) + iVar2))
                            (param_1,uVar10,uVar11,&DAT_001dbd24,uVar6,iVar1 + 2,&DAT_001dbd14,
                             &DAT_001fa5e8,iVarS12,iVar2,iVarS13,&DAT_001fa5e8,uVar10,uVar11,&DAT_001dbd14,&DAT_001fa5e8);
                  iVarS14 = (int)(*(code * *)((char *)frame_ + 328)) + 29844;
                  (**(code **)(((unsigned char *)0x000012f4) + iVar2))
                            (param_1,uVar10,uVar11,&DAT_001dbd24,uVar6,iVar1 + 1,&DAT_001dbd14,
                             &DAT_001fa5e8,iVarS12,iVar2,iVarS14,&DAT_001fa5e8,uVar10,uVar11,&DAT_001dbd14,&DAT_001fa5e8);
                  iVarS15 = (int)(*(undefined ** *)((char *)frame_ + 324)) + 23976;
                  (**(code **)(((unsigned char *)0x000012f4) + iVar2))
                            (param_1,uVar10,uVar11,&DAT_001dbd24,uVar6,iVar1,&DAT_001dbd14,
                             &DAT_001fa5e8,iVarS12,iVar2,iVarS15,&DAT_001fa5e8,uVar10,uVar11,&DAT_001dbd14,&DAT_001fa5e8);
                } while (param_3 != uVar13);
                puVar8 = (undefined4 *)param_1[0xfb];
              }
              iVar1 = param_1[0xfe];
              uVar6 = *puVar8;
              ppuVar12 = (*(undefined ** *)((char *)frame_ + 308)) + 0x1766;
              pcVar7 = (*(code * *)((char *)frame_ + 356)) + 0x74d4;
              pcVar9 = (*(code * *)((char *)frame_ + 312)) + 0x74c4;
              iVarS8 = *(int *)((int)param_1 + 1376);
              iVarS9 = (int)(*(code * *)((char *)frame_ + 320)) + 29828;
              (**(code **)(((unsigned char *)0x000012ec) + iVar2))
                        (param_1,uVar6,iVar1,pcVar7,uVar5,(*(undefined4 *)((char *)frame_ + 252)),pcVar9,ppuVar12,uVar6,iVarS8,iVarS9,ppuVar12);
              iVarS16 = *(int *)((int)param_1 + 1376);
              iVarS17 = (int)(*(code * *)((char *)frame_ + 332)) + 29860;
              (**(code **)(((unsigned char *)0x000012f4) + iVar2))
                        (param_1,uVar6,iVar1,pcVar7,uVar5,(*(undefined4 *)((char *)frame_ + 212)),pcVar9,ppuVar12,uVar6,iVarS16,iVarS17,ppuVar12,uVar6,iVar1,pcVar9,ppuVar12);
              iVarS18 = (int)(*(code * *)((char *)frame_ + 328)) + 29844;
              (**(code **)(((unsigned char *)0x000012f4) + iVar2))
                        (param_1,uVar6,iVar1,pcVar7,uVar5,(*(undefined4 *)((char *)frame_ + 172)),pcVar9,ppuVar12,uVar6,iVarS16,iVarS18,ppuVar12,uVar6,iVar1,pcVar9,ppuVar12);
              iVarS19 = (int)(*(undefined ** *)((char *)frame_ + 324)) + 23976;
              (**(code **)(((unsigned char *)0x000012f4) + iVar2))
                        (param_1,uVar6,iVar1,pcVar7,uVar5,((undefined4 *)((char *)frame_ + 132))[0],pcVar9,ppuVar12,uVar6,iVarS16,iVarS19,ppuVar12,uVar6,iVar1,pcVar9,ppuVar12);
              FUN_000911a0(param_1,(*(undefined1 * *)((char *)frame_ + 296)));
              FUN_000911a0(param_1,(*(undefined1 * *)((char *)frame_ + 300)));
              FUN_000911a0(param_1,(*(undefined1 * *)((char *)frame_ + 304)));
              FUN_000911a0(param_1,(*(undefined1 * *)((char *)frame_ + 316)));
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
    iVar2 = FUN_00090ca0(param_1,2,param_1 + 0x534);
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
    iVar2 = FUN_00090ca0(param_1,1,param_1 + 0x41c);
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
  unsigned int frame_[44] __attribute__((aligned(16)));
  
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
        iVar2 = FUN_00090ca0(param_1,0,((undefined1 *)((char *)frame_ + 8)));
        if (iVar2 != 0) {
          return 7;
        }
        uVar6 = **(undefined4 **)(param_1 + 0x3f0);
        uVar5 = (*(undefined4 *)((char *)frame_ + 12));
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
        iVar3 = FUN_00090ca0(param_1,0,((undefined1 *)((char *)frame_ + 48)));
        if (iVar3 != 0) {
          return 7;
        }
        iVarS5 = *(int *)((int)*(int *)((int)param_1 + 1004) + 0);
        (**(code **)(((unsigned char *)0x000012e4) + iVar7))
                  (param_1,uVar9,(*(undefined4 *)((char *)frame_ + 52)),&DAT_001dbd44,uVar8,iVar2 + 3,&DAT_001dbd14,&DAT_001fa5e8,iVarS5,iVarS2,&DAT_001dbd14,&DAT_001fa5e8)
        ;
        (**(code **)(((unsigned char *)0x000012e8) + iVar7))
                  (param_1,uVar6,uVar5,&DAT_001dbd44,uVar4,(*(undefined4 *)((char *)frame_ + 52)),&DAT_001dbcd4,&DAT_001fa5e8);
        FUN_00091980(param_1,uVar4,(*(undefined4 *)((char *)frame_ + 52)));
        FUN_000911a0(param_1,((undefined1 *)((char *)frame_ + 48)));
        if (*(int *)(param_1 + 0x6a0) == -1) goto LAB_00095d30;
      }
      if (!bVar1) {
        uVar5 = **(undefined4 **)(param_1 + 0x3ec);
        (**(code **)(((unsigned char *)0x000012e8) + iVar7))
                  (param_1,*(undefined4 *)(*(int *)(param_1 + 0x3f0) + 8),
                   *(undefined4 *)(param_1 + 0x68),&DAT_001dbd24,uVar5,(*(undefined4 *)((char *)frame_ + 12)),&DAT_001dbd14,
                   &DAT_001fa5e8);
        (**(code **)(((unsigned char *)0x000012e8) + iVar7))
                  (param_1,*(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x14),
                   *(undefined4 *)(param_3 * 4 + param_1 + 0x84),&DAT_001dbd24,uVar5,(*(undefined4 *)((char *)frame_ + 12)),
                   &DAT_001dbd14,&DAT_001fa5e8);
        goto LAB_00095d10;
      }
    }
    else {
      uVar5 = **(undefined4 **)(param_1 + 0x3ec);
      if ((*(int *)(param_1 + 0x3f8) == -1) &&
         (FUN_000914e0(param_1), *(int *)(param_1 + 0x3f8) == -1)) goto LAB_00095d30;
      iVar2 = FUN_00090ca0(param_1,0,((undefined1 *)((char *)frame_ + 8)));
      uVar6 = (*(undefined4 *)((char *)frame_ + 12));
      if (iVar2 != 0) {
        return 7;
      }
      if (bVar1) {
        uVar4 = *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 8);
        uVar8 = *(undefined4 *)(param_1 + 0x68);
      }
      else {
        uVar4 = **(undefined4 **)(param_1 + 0x3f0);
        uVar8 = (*(undefined4 *)((char *)frame_ + 12));
      }
      iVar2 = *(int *)(param_1 + 0xd4);
      uVar9 = **(undefined4 **)(param_1 + 0x3ec);
      uVar10 = (*(undefined4 **)(param_1 + 0x3ec))[2];
      iVarS6 = *(int *)((int)param_1 + 1016);
      iVarS7 = &DAT_001dbcd4;
      (**(code **)(((unsigned char *)0x000012ec) + iVar7))
                (param_1,uVar9,(*(undefined4 *)((char *)frame_ + 12)),&DAT_001dbd24,uVar10,iVar2 + 3,&DAT_001dbd14,&DAT_001fa5e8,uVar9,iVarS6,iVarS7,&DAT_001fa5e8);
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
        iVarS24 = (*(undefined4 *)((char *)frame_ + 12));
        (**(code **)(((unsigned char *)0x000012f4) + iVar7))
                  (param_1,uVar4,uVar8,&DAT_001dbd24,uVar10,iVar2,&DAT_001dbd14,&DAT_001fa5e8,iVarS20,iVarS21,iVarS22,&DAT_001fa5e8,iVarS23,iVarS24,&DAT_001dbd14,&DAT_001fa5e8);
      }
      else {
        iVarS16 = *(int *)((int)param_1 + 1016);
        iVarS17 = &DAT_001fa5f8;
        (**(code **)(((unsigned char *)0x000012f4) + iVar7))
                  (param_1,**(undefined4 **)(param_1 + 0x3ec),(*(undefined4 *)((char *)frame_ + 12)),&DAT_001dbd24,uVar10,iVar2,
                   &DAT_001dbd14,&DAT_001fa5e8,**(undefined4 **)(param_1 + 0x3ec),iVarS16,iVarS17,&DAT_001fa5e8,**(undefined4 **)(param_1 + 0x3ec),(*(undefined4 *)((char *)frame_ + 12)),&DAT_001dbd14,&DAT_001fa5e8);
        if (bVar1) {
          (**(code **)(((unsigned char *)0x000012e8) + iVar7))
                    (param_1,*(undefined4 *)(*(int *)(param_1 + 0x3f0) + 8),
                     *(undefined4 *)(param_1 + 0x68),&DAT_001dbd24,uVar5,(*(undefined4 *)((char *)frame_ + 12)),&DAT_001dbd14,
                     &DAT_001fa5e8);
        }
        FUN_00091980(param_1,uVar5,(*(undefined4 *)((char *)frame_ + 12)));
        if (*(int *)(param_1 + 0x6a0) == -1) {
          FUN_000911a0(param_1,((undefined1 *)((char *)frame_ + 8)));
          return 2;
        }
      }
      if (!bVar1) {
        uVar5 = **(undefined4 **)(param_1 + 0x3ec);
        (**(code **)(((unsigned char *)0x000012e8) + iVar7))
                  (param_1,*(undefined4 *)(*(int *)(param_1 + 0x3f0) + 8),
                   *(undefined4 *)(param_1 + 0x68),&DAT_001dbd24,uVar5,(*(undefined4 *)((char *)frame_ + 12)),&DAT_001dbd14,
                   &DAT_001fa5e8);
        (**(code **)(((unsigned char *)0x000012e8) + iVar7))
                  (param_1,*(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x14),
                   *(undefined4 *)(param_3 * 4 + param_1 + 0x84),&DAT_001dbd24,uVar5,(*(undefined4 *)((char *)frame_ + 12)),
                   &DAT_001dbd14,&DAT_001fa5e8);
      }
LAB_00095d10:
      FUN_000911a0(param_1,((undefined1 *)((char *)frame_ + 8)));
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
          iVar2 = FUN_00090ca0(param_1,0,param_1 + 0xfd);
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
        iVar2 = FUN_00090ca0(param_1,0,param_1 + 0xfd);
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
  unsigned int frame_[44] __attribute__((aligned(16)));
  
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
      iVar8 = FUN_00090ca0(param_1,0,((undefined1 *)((char *)frame_ + 8)));
      if (iVar8 != 0) {
        return 7;
      }
      iVar8 = param_1[0x29];
      uVar4 = *(undefined4 *)param_1[0xfc];
      iVar2 = (*(int *)((char *)frame_ + 12));
    }
    uVar3 = *(undefined4 *)(param_1[0xfb] + 8);
    /* issue #64 live-repro (crash #9, past the local_98-cluster fix): this indirect dispatch
     * (through the per-instance function-pointer table at 0x12e4+iVar5) reaches FUN_000840d0
     * on real hardware, whose real signature takes 12 parameters - but every call at this
     * shared call shape only supplies 8, matching the project's known dropped-call-args
     * defect class (Tools/userspace/indirect_args.py, detect_dropped_args.py). Since the call
     * is an untyped raw function-pointer invocation, the missing param_9-12 are simply never
     * pushed; FUN_000840d0 reads whatever stale stack memory happens to be there instead.
     * Live-verified on real hardware: it crashed dereferencing param_11 as a null pointer.
     * FUN_000840d0's own body applies the IDENTICAL bit-packing pattern to (param_5,param_6,
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
      iVar6 = FUN_00090ca0(param_1,0,((undefined1 *)((char *)frame_ + 48)));
      if (iVar6 != 0) {
        return 7;
      }
      iVarS20 = *(int *)((int)*(int *)((int)param_1 + 1004) + 4);
      iVarS21 = *(int *)((int)param_1 + 0);
      (**(code **)(((unsigned char *)0x000012e4) + iVar5))
                (param_1,uVar9,(*(undefined4 *)((char *)frame_ + 52)),&DAT_001dbd44,uVar3,iVar8 + 3,&DAT_001dbd14,&DAT_001fa5e8,iVarS20,iVarS21,&DAT_001dbd14,&DAT_001fa5e8);
      (**(code **)(((unsigned char *)0x000012e8) + iVar5))
                (param_1,uVar4,iVar2,&DAT_001dbd44,uVar7,(*(undefined4 *)((char *)frame_ + 52)),&DAT_001dbcd4,&DAT_001fa5e8);
      FUN_00091980(param_1,uVar7,(*(undefined4 *)((char *)frame_ + 52)));
      FUN_000911a0(param_1,((undefined1 *)((char *)frame_ + 48)));
      if (param_1[0x1a8] == -1) {
        return 2;
      }
    }
    if (bVar1) {
      return 0;
    }
    uVar4 = *(undefined4 *)param_1[0xfb];
    (**(code **)(((unsigned char *)0x000012e8) + iVar5))
              (param_1,*(undefined4 *)(param_1[0xfc] + 8),param_1[0x1a],&DAT_001dbd24,uVar4,(*(int *)((char *)frame_ + 12))
               ,&DAT_001dbd14,&DAT_001fa5e8);
    (**(code **)(((unsigned char *)0x000012e8) + iVar5))
              (param_1,*(undefined4 *)(param_1[0xfc] + 0x14),param_1[param_3 + 0x21],&DAT_001dbd24,
               uVar4,(*(int *)((char *)frame_ + 12)),&DAT_001dbd14,&DAT_001fa5e8);
  }
  else {
    uVar4 = *(undefined4 *)param_1[0xfb];
    iVar2 = FUN_00090ca0(param_1,0,((undefined1 *)((char *)frame_ + 8)));
    iVar8 = (*(int *)((char *)frame_ + 12));
    if (iVar2 != 0) {
      return 7;
    }
    if (bVar1) {
      uVar3 = *(undefined4 *)(param_1[0xfc] + 8);
      iVar2 = param_1[0x1a];
    }
    else {
      uVar3 = *(undefined4 *)param_1[0xfc];
      iVar2 = (*(int *)((char *)frame_ + 12));
    }
    iVar6 = param_1[0x29];
    uVar9 = *(undefined4 *)param_1[0xfb];
    uVar7 = ((undefined4 *)param_1[0xfb])[2];
    iVarS1 = *(int *)((int)*(int *)((int)param_1 + 1004) + 4);
    iVarS2 = *(int *)((int)param_1 + 0);
    iVarS3 = &DAT_001dbcd4;
    (**(code **)(((unsigned char *)0x000012ec) + iVar5))
              (param_1,uVar9,(*(int *)((char *)frame_ + 12)),&DAT_001dbd24,uVar7,iVar6 + 3,&DAT_001dbd14,&DAT_001fa5e8,iVarS1,iVarS2,iVarS3,&DAT_001fa5e8);
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
      iVarS29 = (*(int *)((char *)frame_ + 12));
      (**(code **)(((unsigned char *)0x000012f4) + iVar5))
                (param_1,uVar3,iVar2,&DAT_001dbd24,uVar7,iVar6,&DAT_001dbd14,&DAT_001fa5e8,iVarS25,iVarS26,iVarS27,&DAT_001fa5e8,iVarS28,iVarS29,&DAT_001dbd14,&DAT_001fa5e8);
    }
    else {
      iVarS13 = *(int *)((int)*(int *)((int)param_1 + 1004) + 4);
      iVarS14 = *(int *)((int)param_1 + 0);
      iVarS15 = &DAT_001fa5f8;
      (**(code **)(((unsigned char *)0x000012f4) + iVar5))
                (param_1,*(undefined4 *)param_1[0xfb],(*(int *)((char *)frame_ + 12)),&DAT_001dbd24,uVar7,iVar6,
                 &DAT_001dbd14,&DAT_001fa5e8,iVarS13,iVarS14,iVarS15,&DAT_001fa5e8,*(undefined4 *)param_1[0xfb],(*(int *)((char *)frame_ + 12)),&DAT_001dbd14,&DAT_001fa5e8);
      if (bVar1) {
        (**(code **)(((unsigned char *)0x000012e8) + iVar5))
                  (param_1,*(undefined4 *)(param_1[0xfc] + 8),param_1[0x1a],&DAT_001dbd24,uVar4,
                   (*(int *)((char *)frame_ + 12)),&DAT_001dbd14,&DAT_001fa5e8);
      }
      FUN_00091980(param_1,uVar4,(*(int *)((char *)frame_ + 12)));
      if (param_1[0x1a8] == -1) {
        FUN_000911a0(param_1,((undefined1 *)((char *)frame_ + 8)));
        return 2;
      }
    }
    if (!bVar1) {
      uVar4 = *(undefined4 *)param_1[0xfb];
      (**(code **)(((unsigned char *)0x000012e8) + iVar5))
                (param_1,*(undefined4 *)(param_1[0xfc] + 8),param_1[0x1a],&DAT_001dbd24,uVar4,
                 (*(int *)((char *)frame_ + 12)),&DAT_001dbd14,&DAT_001fa5e8);
      (**(code **)(((unsigned char *)0x000012e8) + iVar5))
                (param_1,*(undefined4 *)(param_1[0xfc] + 0x14),param_1[param_3 + 0x21],&DAT_001dbd24
                 ,uVar4,(*(int *)((char *)frame_ + 12)),&DAT_001dbd14,&DAT_001fa5e8);
    }
  }
  FUN_000911a0(param_1,((undefined1 *)((char *)frame_ + 8)));
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
  int iVarS1;
  int iVarS2;
  unsigned int frame_[48] __attribute__((aligned(16)));
  
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
    iVar7 = FUN_00090ca0(param_1,0,((undefined1 *)((char *)frame_ + 8)));
    if (iVar7 != 0) {
      return 7;
    }
    cVar5 = *(char *)(param_1 + 0x744);
    (*(int *)((char *)frame_ + 100)) = 1;
  }
  else {
    (*(int *)((char *)frame_ + 100)) = 0;
    cVar5 = '\0';
  }
  bVar1 = param_7 == 0;
  if (cVar5 == '\0') {
    if (bVar1) {
      puVar8 = *(undefined4 **)(param_1 + 0x3f0);
      uVar12 = 0;
      (*(undefined4 *)((char *)frame_ + 12)) = 0;
    }
    else if (bVar2) {
      puVar8 = *(undefined4 **)(param_1 + 0x3f0);
      (*(undefined4 *)((char *)frame_ + 12)) = *(undefined4 *)(iVar3 + param_1 + 0x84);
      uVar12 = puVar8[5];
    }
    else {
      puVar8 = *(undefined4 **)(param_1 + 0x3f0);
      uVar12 = *puVar8;
    }
    uVar15 = puVar8[5];
    uVar6 = *(undefined4 *)(iVar3 + param_1 + 0x84);
    if (bVar1) {
      (*(int *)((char *)frame_ + 96)) = 0;
      (*(undefined4 *)((char *)frame_ + 88)) = 0;
      (*(undefined4 *)((char *)frame_ + 92)) = 0;
      goto LAB_00096b24;
    }
    (*(int *)((char *)frame_ + 96)) = 0;
    (*(undefined4 *)((char *)frame_ + 88)) = 0;
    (*(undefined4 *)((char *)frame_ + 92)) = 0;
    uVar17 = (*(undefined4 *)((char *)frame_ + 12));
  }
  else {
    if (bVar1) {
      (*(undefined4 *)((char *)frame_ + 92)) = (*(undefined4 *)((char *)frame_ + 12));
      uVar15 = **(undefined4 **)(param_1 + 0x3f0);
      (*(int *)((char *)frame_ + 96)) = 0;
      uVar6 = (*(undefined4 *)((char *)frame_ + 12));
      (*(undefined4 *)((char *)frame_ + 88)) = uVar15;
      goto LAB_00096b24;
    }
    uVar12 = **(undefined4 **)(param_1 + 0x3f0);
    uVar17 = (*(undefined4 *)((char *)frame_ + 12));
    if (bVar2) {
      (*(undefined4 *)((char *)frame_ + 92)) = (*(undefined4 *)((char *)frame_ + 12));
      uVar15 = 0;
      (*(int *)((char *)frame_ + 96)) = 0;
      uVar6 = 0;
      (*(undefined4 *)((char *)frame_ + 88)) = uVar12;
    }
    else {
      if (*(int *)(param_1 + 0x6a0) == -1) {
        if ((*(int *)((char *)frame_ + 100)) == 0) {
          return 2;
        }
        FUN_000911a0(param_1,((undefined1 *)((char *)frame_ + 8)));
        return 2;
      }
      iVar7 = FUN_00090ca0(param_1,0,((undefined1 *)((char *)frame_ + 48)));
      if (iVar7 != 0) {
        if ((*(int *)((char *)frame_ + 100)) == 0) {
          return 7;
        }
        FUN_000911a0(param_1,((undefined1 *)((char *)frame_ + 8)));
        return 7;
      }
      (*(undefined4 *)((char *)frame_ + 92)) = (*(undefined4 *)((char *)frame_ + 52));
      uVar15 = **(undefined4 **)(param_1 + 0x3f0);
      (*(int *)((char *)frame_ + 96)) = 1;
      uVar6 = (*(undefined4 *)((char *)frame_ + 52));
      (*(undefined4 *)((char *)frame_ + 88)) = uVar15;
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
              (param_1,uVar15,uVar6,&DAT_001dbd04,uVar17,iVar7,&DAT_001dbd14,&DAT_001fa5e8,(*(undefined4 *)((char *)frame_ + 88)),(*(undefined4 *)((char *)frame_ + 92)),(param_3 != 0 ? ((unsigned char *)&DAT_001dbdc0 + 4) : &DAT_001dbd14),&DAT_001fa5e8);
    (**(code **)(((unsigned char *)0x000012e4) + iVar11))
              (param_1,uVar15,uVar6,&DAT_001dbd64,uVar17,iVar7 + 1,&DAT_001dbd14,&DAT_001fa5e8,(*(undefined4 *)((char *)frame_ + 88)),(*(undefined4 *)((char *)frame_ + 92)),(param_3 != 0 ? ((unsigned char *)&DAT_001dbdc0 + 4) : &DAT_001dbd14),&DAT_001fa5e8);
    (**(code **)(((unsigned char *)0x000012e4) + iVar11))
              (param_1,uVar15,uVar6,&DAT_001dbd54,uVar17,iVar7 + 2,&DAT_001dbd14,&DAT_001fa5e8,(*(undefined4 *)((char *)frame_ + 88)),(*(undefined4 *)((char *)frame_ + 92)),(param_3 != 0 ? ((unsigned char *)&DAT_001dbdc0 + 4) : &DAT_001dbd14),&DAT_001fa5e8);
    (**(code **)(((unsigned char *)0x000012e4) + iVar11))
              (param_1,uVar15,uVar6,&DAT_001dbd44,uVar17,iVar7 + 3,&DAT_001dbd14,&DAT_001fa5e8,(*(undefined4 *)((char *)frame_ + 88)),(*(undefined4 *)((char *)frame_ + 92)),(param_3 != 0 ? ((unsigned char *)&DAT_001dbdc0 + 4) : &DAT_001dbd14),&DAT_001fa5e8);
  }
  if (*(char *)(param_1 + 0x744) != '\0') {
    iVarS1 = *(int *)((int)*(int *)((int)param_1 + 1004) + 0);
    iVarS2 = (int)param_1 + 1716;
    (**(code **)(((unsigned char *)0x000012ec) + iVar11))
              (param_1,*(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x14),
               *(undefined4 *)(iVar3 + param_1 + 0x84),&DAT_001dbd24,(*(undefined4 *)((char *)frame_ + 88)),(*(undefined4 *)((char *)frame_ + 92)),&DAT_001dbd14
               ,&DAT_001fa5e8,iVarS1,*(int *)(param_1 + 0x6a0),iVarS2,&DAT_001fa5e8);
  }
  if ((*(int *)((char *)frame_ + 100)) != 0) {
    FUN_000911a0(param_1,((undefined1 *)((char *)frame_ + 8)));
  }
  if ((*(int *)((char *)frame_ + 96)) != 0) {
    FUN_000911a0(param_1,((undefined1 *)((char *)frame_ + 48)));
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
  uint uVar18;
  int iVar19;
  int iVar20;
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
  unsigned int frame_[40] __attribute__((aligned(16)));
  
  iVar5 = 1;
  if (param_1 != 0) {
    iVar16 = *(int *)(param_1 + 0x3d4);
    uVar18 = 0;
    iVar15 = *(int *)(*(int *)(iVar16 + 4) + 0x10);
    iVar5 = iVar16;
    iVar20 = param_1;
    do {
      iVar6 = FUN_000912f0(param_1,*(undefined4 *)(iVar5 + 0x270),0,((undefined1 *)((char *)frame_ + 20)),((undefined1 *)((char *)frame_ + 12)));
      if (iVar6 != 0) {
        return iVar6;
      }
      iVar6 = FUN_000912f0(param_1,*(undefined4 *)(iVar5 + 0x278),1,((undefined1 *)((char *)frame_ + 20)),((undefined1 *)((char *)frame_ + 12)));
      if (iVar6 != 0) {
        return iVar6;
      }
      if ((*(int *)(iVar16 + 0x13c) == 1) && (*(int *)(iVar20 + 0x2f8) == -1)) goto LAB_00097408;
      uVar18 = uVar18 + 1;
      iVar5 = iVar5 + 4;
      iVar20 = iVar20 + 0x24;
    } while (uVar18 <= (byte)((unsigned char *)0x00002d48)[iVar15 + 4]);
    if (*(int *)(param_1 + 0x328) == -1) {
LAB_00097408:
      iVar5 = 2;
    }
    else {
      iVar16 = *(int *)(param_1 + 0x3d4);
      uVar18 = 0;
      iVar6 = 0;
      iVar15 = (*(undefined4 **)(param_1 + 0x3ec))[2];
      uVar13 = **(undefined4 **)(param_1 + 0x3ec);
      (*(int * *)((char *)frame_ + 68)) = ((int *)((char *)frame_ + 24)) + 2;
      uVar12 = **(undefined4 **)(param_1 + 0x3f0);
      iVar20 = *(int *)(*(int *)(iVar16 + 4) + 0x10);
      iVar5 = iVar16;
      do {
        puVar11 = (undefined4 *)(iVar5 + 0x278);
        uVar18 = uVar18 + 1;
        iVar5 = iVar5 + 4;
        FUN_000912f0(param_1,*puVar11,1,(int)((int *)((char *)frame_ + 24)) + iVar6,iVar6 + (int)(*(int * *)((char *)frame_ + 68)));
        iVar6 = iVar6 + 4;
      } while (uVar18 <= (byte)((unsigned char *)0x00002d48)[iVar20 + 4]);
      if ((((byte)((unsigned char *)0x00002d48)[iVar20 + 4] == 0) || (((int *)((char *)frame_ + 24))[0] != ((int *)((char *)frame_ + 24))[1])) ||
         (bVar1 = true, ((int *)((char *)frame_ + 24))[2] != ((int *)((char *)frame_ + 24))[3])) {
        bVar1 = false;
      }
      bVar1 = !bVar1;
      (*(int * *)((char *)frame_ + 60)) = &(*(int *)((char *)frame_ + 16));
      (*(int *)((char *)frame_ + 64)) = param_1 + 0x5ac;
      (*(int *)((char *)frame_ + 72)) = 0x1d6d90;
      (*(int *)((char *)frame_ + 56)) = 0x1d6d90;
      uVar18 = 0;
      iVar14 = 0;
      iVar10 = 0;
      iVar5 = param_1;
      iVar6 = iVar16;
      iVar19 = param_1;
      do {
        iVar7 = FUN_00090ca0(param_1,0,(*(int *)((char *)frame_ + 64)) + iVar10);
        if (iVar7 != 0) {
          return 7;
        }
        iVar7 = *(int *)((int)((int *)((char *)frame_ + 24)) + iVar14);
        uVar17 = *(undefined4 *)(iVar19 + 0x5b0);
        *(undefined4 *)((int)((undefined4 *)((char *)frame_ + 40)) + iVar14) = uVar17;
        if (iVar15 == iVar7) {
          iVar7 = FUN_00090ca0(param_1,1,param_1 + 0x64c + iVar10);
          if (iVar7 != 0) {
            return 7;
          }
          *(undefined4 *)(iVar19 + 0x64c) = uVar13;
          puVar4 = PTR_DAT_001e9778;
          puVar3 = PTR_DAT_001e9774;
          puVar2 = PTR_DAT_001e9770;
          (**(code **)(((unsigned char *)0x000012e8) + iVar16))
                    (param_1,uVar12,*(undefined4 *)(iVar19 + 0x650),PTR_DAT_001e9770,iVar15,
                     *(undefined4 *)(iVar14 + (int)(*(int * *)((char *)frame_ + 68))),PTR_DAT_001e9774,PTR_DAT_001e9778);
          FUN_000912f0(param_1,*(undefined4 *)(iVar6 + 0x270),0,&(*(int *)((char *)frame_ + 16)),&(*(undefined4 *)((char *)frame_ + 8)));
          if (iVar15 == (*(int *)((char *)frame_ + 16))) {
            (*(undefined4 *)((char *)frame_ + 8)) = *(undefined4 *)(iVar5 + 0x2f8);
            (**(code **)(((unsigned char *)0x000012e8) + iVar16))
                      (param_1,uVar12,uVar17,puVar2,iVar15,(*(undefined4 *)((char *)frame_ + 8)),puVar3,puVar4);
          }
          else {
            iVarS16 = *(int *)((int)*(int *)((int)param_1 + 1004) + 8);
            iVarS17 = *(int *)((int)param_1 + 808);
            iVarS18 = &DAT_001dbd14;
            iVarS19 = &DAT_001fa5e8;
            iVarS20 = (*(int *)((char *)frame_ + 16));
            iVarS21 = (*(undefined4 *)((char *)frame_ + 8));
            (**(code **)(((unsigned char *)0x000012f4) + iVar16))
                      (param_1,uVar12,uVar17,PTR_DAT_001e9770,uVar13,*(undefined4 *)(iVar19 + 0x650)
                       ,PTR_DAT_001e9774,PTR_DAT_001e9778,iVarS16,iVarS17,iVarS18,iVarS19,iVarS20,iVarS21,iVarS18,iVarS19);
          }
          if (*(int *)(param_1 + 0x32c) != -1) {
            uVar8 = *(undefined4 *)(iVar19 + 0x650);
            uVar9 = uVar13;
            iVarS22 = uVar13;
            iVar7 = (*(int *)((char *)frame_ + 72));
LAB_00097360:
            (**(code **)(((unsigned char *)0x000012f4) + iVar16))
                      (param_1,uVar12,uVar17,((unsigned char *)0x00004ff4) + iVar7,uVar9,uVar8,PTR_DAT_001e9774,
                       PTR_DAT_001e9778,(*(int *)((int)*(int *)((int)param_1 + 1004) + 8)),*(int *)(param_1 + 0x32c),&DAT_001dbd14,&DAT_001fa5e8,iVarS22,uVar17,&DAT_001dbd14,&DAT_001fa5e8);
          }
        }
        else {
          *(int *)(iVar19 + 0x64c) = iVar7;
          uVar9 = *(undefined4 *)(iVar14 + (int)(*(int * *)((char *)frame_ + 68)));
          puVar11 = (undefined4 *)(iVar14 + (int)(*(int * *)((char *)frame_ + 68)));
          *(undefined4 *)(iVar19 + 0x650) = uVar9;
          if (((bVar1) || (uVar18 == 0)) &&
             ((**(code **)(((unsigned char *)0x000012ec) + iVar16))
                        (param_1,uVar12,uVar17,PTR_DAT_001e9770,iVar7,uVar9,PTR_DAT_001e9774,
                         PTR_DAT_001e9778,(*(int *)((int)*(int *)((int)param_1 + 1004) + 8)),(*(int *)((int)param_1 + 808)),PTR_DAT_001e9774,PTR_DAT_001e9778), bVar1)) {
            FUN_000912f0(param_1,*(undefined4 *)(iVar6 + 0x270),0,&(*(int *)((char *)frame_ + 16)),&(*(undefined4 *)((char *)frame_ + 8)));
            uVar9 = uVar17;
LAB_000972c8:
            (**(code **)(((unsigned char *)0x000012f0) + iVar16))
                      (param_1,uVar12,uVar9,PTR_DAT_001e9770,uVar13,uVar9,PTR_DAT_001e9774,
                       PTR_DAT_001e9778,(*(int *)((char *)frame_ + 16)),(*(undefined4 *)((char *)frame_ + 8)),&DAT_001dbd14,&DAT_001fa5e8);
          }
          else if (uVar18 == 1) {
            FUN_000912f0(param_1,*(undefined4 *)(iVar16 + 0x274),0,(*(int * *)((char *)frame_ + 60)),&(*(undefined4 *)((char *)frame_ + 8)));
            uVar9 = ((undefined4 *)((char *)frame_ + 40))[0];
            iVarS12 = (*(int *)((char *)frame_ + 16));
            iVarS13 = (*(undefined4 *)((char *)frame_ + 8));
            iVarS14 = &DAT_001dbd14;
            iVarS15 = &DAT_001fa5e8;
            (**(code **)(((unsigned char *)0x000012f0) + iVar16))
                      (param_1,uVar12,((undefined4 *)((char *)frame_ + 40))[1],PTR_DAT_001e9770,uVar13,((undefined4 *)((char *)frame_ + 40))[0],
                       PTR_DAT_001e9774,PTR_DAT_001e9778,iVarS12,iVarS13,iVarS14,iVarS15);
            FUN_000912f0(param_1,*(undefined4 *)(iVar16 + 0x270),0,(*(int * *)((char *)frame_ + 60)),&(*(undefined4 *)((char *)frame_ + 8)));
            goto LAB_000972c8;
          }
          if ((*(int *)(param_1 + 0x32c) != -1) && ((bVar1 || (uVar18 == 0)))) {
            uVar9 = *(undefined4 *)((int)((int *)((char *)frame_ + 24)) + iVar14);
            uVar8 = *puVar11;
            iVarS22 = iVar7;
            iVar7 = (*(int *)((char *)frame_ + 56));
            goto LAB_00097360;
          }
        }
        if (*(char *)(iVar16 + 0x12d) != '\0') {
          if (*(short *)(((unsigned char *)0x00002d48) + iVar20) == -0x7e06) {
            iVar7 = FUN_00090ca0(param_1,1,param_1 + 0x5fc + iVar10);
            if (iVar7 != 0) {
              return 7;
            }
          }
          else {
            _memcpy(iVar19 + 0x5fc,iVar19 + 0x5ac,0x28);
          }
        }
        uVar18 = uVar18 + 1;
        iVar10 = iVar10 + 0x28;
        iVar19 = iVar19 + 0x28;
        iVar14 = iVar14 + 4;
        iVar5 = iVar5 + 0x24;
        iVar6 = iVar6 + 4;
      } while (uVar18 <= (byte)((unsigned char *)0x00002d48)[iVar20 + 4]);
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
  unsigned int frame_[112] __attribute__((aligned(16)));
  
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
        iVar8 = FUN_000913e0(param_1,*(undefined4 *)(iVar11 + 0x290),((undefined1 *)((char *)frame_ + 16)),((undefined1 *)((char *)frame_ + 20)),
                             ((undefined1 *)((char *)frame_ + 40)));
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
    (*(undefined1 * *)((char *)frame_ + 348)) = ((undefined1 *)((char *)frame_ + 96));
    iVar8 = FUN_00090ca0(param_1,2,(*(undefined1 * *)((char *)frame_ + 348)));
    if (iVar8 == 0) {
      a1 = **(undefined4 **)(param_1 + 0x3f0);
      iVar8 = (*(int **)(param_1 + 0x3ec))[2];
      iVar3 = **(int **)(param_1 + 0x3ec);
      (**(code **)(((unsigned char *)0x000012e4) + iVar17))
                (param_1,a1,(*(undefined4 *)((char *)frame_ + 100)),((undefined1 *)((char *)frame_ + 104)),iVar8,*(undefined4 *)(iVar15 + 0x24),&DAT_001dbd74
                 ,&DAT_001fa5e8,iVarS9,iVar8,&DAT_001dbd74,&DAT_001fa5e8);
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
      puVar22 = ((undefined1 *)((char *)frame_ + 216));
      uVar19 = 0;
      (*(undefined1 * *)((char *)frame_ + 332)) = puVar22;
      do {
        iVar21 = FUN_00090ca0(param_1,1,puVar22);
        if (iVar21 != 0) goto LAB_000984a0;
        uVar19 = uVar19 + 1;
        puVar22 = puVar22 + 0x28;
      } while (uVar19 <= (byte)((unsigned char *)0x00002d48)[iVar11 + 4]);
      if (bVar1) {
        (*(undefined4 * *)((char *)frame_ + 336)) = &(*(undefined4 *)((char *)frame_ + 220));
        (*(undefined1 * *)((char *)frame_ + 352)) = ((undefined1 *)((char *)frame_ + 120));
        do {
          uVar19 = 0;
          puVar12 = (*(undefined4 * *)((char *)frame_ + 336));
          do {
            iVar21 = uVar19 * 0x28;
            uVar19 = uVar19 + 1;
            /* stack words, stock 0x97b88-0x97b9c: the 4th (0x44) is the r2 of the first pass (r18 + 0x3194) or of the later ones (0x14_0000 + 0x4940) */
            (**(code **)(((unsigned char *)0x0000132c) + iVar17))
                      (param_1,a1,*puVar12,(*(undefined1 * *)((char *)frame_ + 332)) + iVar21 + 8,iVar3,(*(undefined4 *)((char *)frame_ + 100)),&DAT_001dbd34,
                       &DAT_001fa5e8,iVar3,(*(undefined4 *)((char *)frame_ + 100)),(*(undefined1 * *)((char *)frame_ + 352)),(uVar19 == 1 ? &DAT_001fa5e8 : &DAT_001dbd94),iVar3,(*(undefined4 *)((char *)frame_ + 100)),&DAT_001dbdb4,&DAT_001fa5e8);
            if ((byte)((unsigned char *)0x00002d48)[iVar11 + 4] < uVar19) goto LAB_00097bd4;
            puVar12 = puVar12 + 10;
          } while (uVar19 != 0);
        } while( true );
      }
      (*(undefined1 * *)((char *)frame_ + 328)) = ((undefined1 *)((char *)frame_ + 176));
      iVar21 = FUN_00090ca0(param_1,2,(*(undefined1 * *)((char *)frame_ + 328)));
      if (iVar21 == 0) {
        (*(undefined1 * *)((char *)frame_ + 344)) = ((undefined1 *)((char *)frame_ + 56));
        iVar21 = FUN_00090ca0(param_1,2,(*(undefined1 * *)((char *)frame_ + 344)));
        if (iVar21 == 0) {
          if (((unsigned char *)0x00002d48)[iVar11 + 5] == '\0') {
            (*(undefined4 * *)((char *)frame_ + 336)) = &(*(undefined4 *)((char *)frame_ + 220));
            (*(int * *)((char *)frame_ + 340)) = &(*(int *)((char *)frame_ + 12));
            (*(undefined1 * *)((char *)frame_ + 352)) = ((undefined1 *)((char *)frame_ + 120));
            (**(code **)(((unsigned char *)0x000012e4) + iVar17))
                      (param_1,a1,(*(undefined4 *)((char *)frame_ + 180)),((undefined1 *)((char *)frame_ + 184)),iVar8,*(undefined4 *)(iVar15 + 0x28),
                       &DAT_001dbd74,&DAT_001fa5e8,iVarS9,iVar8,&DAT_001dbd74,&DAT_001fa5e8);
LAB_00097a58:
            puVar9 = (undefined4 *)(iVar17 + 0x290);
            puVar18 = &DAT_001fa5e8;
            uVar19 = 0;
            puVar12 = (*(undefined4 * *)((char *)frame_ + 336));
LAB_00097a68:
            FUN_000913e0(param_1,*puVar9,&(*(int *)((char *)frame_ + 8)),(*(int * *)((char *)frame_ + 340)),&(*(undefined4 *)((char *)frame_ + 24)));
            iVar21 = uVar19 * 0x28;
            uVar19 = uVar19 + 1;
            iVarS15 = *(int *)((int)*(int *)((int)param_1 + 980) + 4908);
            iVarS16 = &DAT_001dbdb4;
            iVarS60 = (*(undefined4 *)((char *)frame_ + 100));
            iVarS61 = (*(undefined1 * *)((char *)frame_ + 352));
            iVarS62 = (*(int *)((char *)frame_ + 8));
            iVarS63 = (*(int *)((char *)frame_ + 12));
            iVarS64 = &(*(undefined4 *)((char *)frame_ + 24));
            iVarS65 = &DAT_001fa5e8;
            (**(code **)(((unsigned char *)0x0000132c) + iVar17))
                      (param_1,a1,*puVar12,(*(undefined1 * *)((char *)frame_ + 332)) + iVar21 + 8,iVar3,(*(undefined4 *)((char *)frame_ + 180)),((undefined1 *)((char *)frame_ + 200)),puVar18,iVar3,iVarS60,iVarS61,puVar18,iVarS62,iVarS63,iVarS64,iVarS65)
            ;
            if (uVar19 <= (byte)((unsigned char *)0x00002d48)[iVar11 + 4]) goto LAB_00097a40;
            FUN_000911a0(param_1,(*(undefined1 * *)((char *)frame_ + 328)));
            FUN_000911a0(param_1,(*(undefined1 * *)((char *)frame_ + 344)));
LAB_00097bd4:
            (*(int *)((char *)frame_ + 304)) = 0x1d7454;
            (*(int *)((char *)frame_ + 308)) = 0x1d7454;
            (*(int *)((char *)frame_ + 320)) = 0x1d7454;
            bVar2 = iStack00000020 == 0;
            (*(int *)((char *)frame_ + 312)) = 0x1d7454;
            (*(uint *)((char *)frame_ + 300)) = 0x81fa;
            (*(uint *)((char *)frame_ + 296)) = 0;
            (*(int *)((char *)frame_ + 316)) = 0x1d7454;
            (*(int *)((char *)frame_ + 324)) = 0x1d7454;
            puVar12 = (*(undefined4 * *)((char *)frame_ + 336));
            iVar21 = iVar17;
            iVar13 = param_1;
            iVar14 = iVar15;
            iVar16 = param_1;
            while (bVar1) {
              if (((!bVar2) && (*(char *)(iVar17 + 0x12d) != '\0')) &&
                 (*(ushort *)(((unsigned char *)0x00002d48) + iVar11) == (*(uint *)((char *)frame_ + 300)))) {
                iVarS23 = &DAT_001dbd34;
                (**(code **)(((unsigned char *)0x000012ec) + iVar17))
                          (param_1,a1,*(undefined4 *)(iVar16 + 0x600),((unsigned char *)0x00004930) + (*(int *)((char *)frame_ + 304)),iVar3
                           ,*(undefined4 *)(iVar16 + 0x600),((unsigned char *)0x000048c0) + (*(int *)((char *)frame_ + 308)),&DAT_001fa5e8,iVar3,*(undefined4 *)(iVar16 + 0x600),iVarS23,&DAT_001fa5e8);
              }
LAB_000980d0:
              if (iStack0000002c == 0) {
                if (iStack00000024 != 0) {
                  uVar20 = *(undefined4 *)(iVar13 + 0x74);
                  uVar5 = *(undefined4 *)(iVar16 + 0x5b0);
                  uVar7 = *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0xc);
                  FUN_000912f0(param_1,*(undefined4 *)(iVar21 + 0x280),2,&(*(int *)((char *)frame_ + 8)),&(*(int *)((char *)frame_ + 12)));
                  (*(undefined4 *)((char *)frame_ + 36)) = 3;
                  (*(undefined4 *)((char *)frame_ + 32)) = 5;
                  (*(undefined4 *)((char *)frame_ + 24)) = 5;
                  (*(undefined4 *)((char *)frame_ + 28)) = 5;
                  iVarS24 = (*(int *)((char *)frame_ + 8));
                  iVarS25 = (*(int *)((char *)frame_ + 12));
                  iVarS26 = &(*(undefined4 *)((char *)frame_ + 24));
                  (**(code **)(((unsigned char *)0x000012ec) + iVar17))
                            (param_1,uVar7,uVar20,((unsigned char *)0x000048d0) + (*(int *)((char *)frame_ + 316)),iVar3,uVar5,
                             ((unsigned char *)0x00004970) + (*(int *)((char *)frame_ + 324)),&DAT_001fa5e8,iVarS24,iVarS25,iVarS26,&DAT_001fa5e8);
                }
              }
              else {
                uVar5 = *(undefined4 *)(iVar16 + 0x5b0);
                iVarS33 = uVar5; /* stock r29, the 6th stack word of the 12f4 call below (0x981a4) */
                if (iStack00000024 == 0) {
                  uVar20 = **(undefined4 **)(param_1 + 0x3f0);
                  puVar18 = ((unsigned char *)0x00004930) + (*(int *)((char *)frame_ + 304));
                }
                else {
                  uVar5 = *(undefined4 *)(iVar13 + 0x74);
                  uVar20 = *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0xc);
                  puVar18 = ((unsigned char *)0x000048d0) + (*(int *)((char *)frame_ + 316));
                }
                if (*(int *)(iVar14 + 0xc) == -1) {
                  FUN_000912f0(param_1,*(undefined4 *)(iVar21 + 0x280),2,&(*(int *)((char *)frame_ + 8)),&(*(int *)((char *)frame_ + 12)));
                }
                iVar4 = (*(int *)((char *)frame_ + 8));
                iVar6 = (*(int *)((char *)frame_ + 12));
                if ((iStack0000002c == 1) ||
                   (iVar4 = iVar8, iVar6 = *(int *)(iVar14 + 0xc), *(int *)(iVar14 + 0xc) != -1)) {
                  iVarS52 = *(int *)((int)*(int *)((int)param_1 + 1004) + 0);
                  iVarS53 = *(int *)((int)puVar9 + 0);
                  iVarS54 = ((unsigned char *)&DAT_001dbdc0 + 44);
                  iVarS55 = &DAT_001dbd74;
                  (**(code **)(((unsigned char *)0x000012f4) + iVar17))
                            (param_1,uVar20,uVar5,puVar18,iVar4,iVar6,((unsigned char *)0x000048c0) + (*(int *)((char *)frame_ + 308)),
                             &DAT_001fa5e8,iVarS52,iVarS53,iVarS54,&DAT_001fa5e8,iVarS52,iVarS33,iVarS55,&DAT_001fa5e8);
                }
                else {
                  (*(undefined1 * *)((char *)frame_ + 356)) = ((undefined1 *)((char *)frame_ + 136));
                  iVar4 = FUN_00090ca0(param_1,0,(*(undefined1 * *)((char *)frame_ + 356)));
                  if (iVar4 != 0) goto LAB_000984a0;
                  if (iVar8 == (*(int *)((char *)frame_ + 8))) {
                    iVarS27 = *(int *)((int)*(int *)((int)param_1 + 1004) + 0);
                    iVarS28 = *(int *)((int)puVar9 + 0);
                    iVarS29 = ((unsigned char *)&DAT_001dbdc0 + 44);
                    (**(code **)(((unsigned char *)0x000012ec) + iVar17))
                              (param_1,a1,(*(undefined4 *)((char *)frame_ + 140)),puVar18,iVar8,(*(int *)((char *)frame_ + 12)),&DAT_001dbd14,
                               &DAT_001fa5e8,iVarS27,iVarS28,iVarS29,&DAT_001fa5e8);
                    puVar10 = ((unsigned char *)0x00004970) + (*(int *)((char *)frame_ + 324));
                    uVar7 = *(undefined4 *)(iVar15 + 8);
                    iVar4 = iVar8;
                  }
                  else {
                    iVarS30 = (*(int *)((char *)frame_ + 8));
                    iVarS31 = (*(int *)((char *)frame_ + 12));
                    iVarS32 = &DAT_001dbd14;
                    (**(code **)(((unsigned char *)0x000012ec) + iVar17))
                              (param_1,a1,(*(undefined4 *)((char *)frame_ + 140)),puVar18,iVar8,*(undefined4 *)(iVar15 + 8),
                               ((unsigned char *)0x00004970) + (*(int *)((char *)frame_ + 324)),&DAT_001fa5e8,iVarS30,iVarS31,iVarS32,&DAT_001fa5e8);
                    uVar7 = *puVar12;
                    puVar10 = ((unsigned char *)0x00004998) + (*(int *)((char *)frame_ + 320));
                    iVar4 = iVar3;
                  }
                  iVarS68 = *(int *)((int)*(int *)((int)param_1 + 1004) + 0);
                  iVarS69 = (*(undefined4 *)((char *)frame_ + 140));
                  (**(code **)(((unsigned char *)0x000012f4) + iVar17))
                            (param_1,uVar20,uVar5,puVar18,iVar4,uVar7,puVar10,&DAT_001fa5e8,iVarS68,iVarS69,&DAT_001dbd14,&DAT_001fa5e8,iVarS68,iVarS33,&DAT_001dbd74,&DAT_001fa5e8);
                  FUN_000911a0(param_1,(*(undefined1 * *)((char *)frame_ + 356)));
                }
              }
              puVar22 = (*(undefined1 * *)((char *)frame_ + 332));
              puVar12 = puVar12 + 10;
              iVar13 = iVar13 + 4;
              iVar16 = iVar16 + 0x28;
              iVar21 = iVar21 + 4;
              iVar14 = iVar14 + 4;
              (*(uint *)((char *)frame_ + 296)) = (*(uint *)((char *)frame_ + 296)) + 1;
              if ((byte)((unsigned char *)0x00002d48)[iVar11 + 4] < (*(uint *)((char *)frame_ + 296))) {
                uVar19 = 0;
                FUN_000911a0(param_1,(*(undefined1 * *)((char *)frame_ + 348)));
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
              FUN_000912f0(param_1,*(undefined4 *)(iVar21 + 0x288),3,&(*(int *)((char *)frame_ + 8)),&(*(int *)((char *)frame_ + 12)));
            }
            if (iStack00000030 == 1) {
              iVar4 = (*(int *)((char *)frame_ + 8));
              iVar6 = (*(int *)((char *)frame_ + 12));
              if ((!bVar2) && (*(ushort *)(((unsigned char *)0x00002d48) + iVar11) == (*(uint *)((char *)frame_ + 300))))
              goto LAB_00097d1c;
LAB_00097d70:
              (**(code **)(((unsigned char *)0x000012f4) + iVar17))
                        (param_1,a1,uVar5,((unsigned char *)0x00004930) + (*(int *)((char *)frame_ + 304)),iVar4,iVar6,&DAT_001dbd14,
                         &DAT_001fa5e8,(*(int *)((int)*(int *)((int)param_1 + 1004) + 0)),(*(int *)((int)puVar9 + 0)),(&DAT_001dbcf4),&DAT_001fa5e8,(*(int *)((int)*(int *)((int)param_1 + 1004) + 0)),uVar5,(&DAT_001dbd14),&DAT_001fa5e8);
              goto LAB_000980d0;
            }
            iVar6 = *(int *)(iVar14 + 0x18);
            if (iVar6 != -1) {
              iVar4 = iVar8;
              if ((bVar2) || (*(ushort *)(((unsigned char *)0x00002d48) + iVar11) != (*(uint *)((char *)frame_ + 300))))
              goto LAB_00097d70;
LAB_00097d1c:
              (**(code **)(((unsigned char *)0x000012ec) + iVar17))
                        (param_1,a1,uVar5,((unsigned char *)0x00004930) + (*(int *)((char *)frame_ + 304)),iVar4,iVar6,
                         ((unsigned char *)0x000048c0) + (*(int *)((char *)frame_ + 308)),&DAT_001fa5e8,(*(int *)((int)*(int *)((int)param_1 + 1004) + 0)),(*(int *)((int)puVar9 + 0)),(&DAT_001dbcf4),&DAT_001fa5e8);
              goto LAB_000980d0;
            }
            (*(undefined1 * *)((char *)frame_ + 356)) = ((undefined1 *)((char *)frame_ + 136));
            iVar4 = FUN_00090ca0(param_1,1,(*(undefined1 * *)((char *)frame_ + 356)));
            if (iVar4 == 0) {
              if (iVar8 == (*(int *)((char *)frame_ + 8))) {
                iVarS36 = *(int *)((int)*(int *)((int)param_1 + 1004) + 0);
                iVarS37 = *(int *)((int)puVar9 + 0);
                iVarS38 = &DAT_001dbcf4;
                iVarS39 = &DAT_001fa5e8;
                (**(code **)(((unsigned char *)0x000012ec) + iVar17))
                          (param_1,a1,(*(undefined4 *)((char *)frame_ + 140)),&DAT_001dbd84,iVar8,(*(int *)((char *)frame_ + 12)),&DAT_001dbd14,
                           &DAT_001fa5e8,iVarS36,iVarS37,iVarS38,iVarS39);
                if ((!bVar2) && (*(ushort *)(((unsigned char *)0x00002d48) + iVar11) == (*(uint *)((char *)frame_ + 300)))) {
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
                          (param_1,a1,uVar5,&DAT_001dbd84,iVar4,uVar20,puVar9,&DAT_001fa5e8,(*(int *)((int)*(int *)((int)param_1 + 1004) + 0)),((*(undefined4 *)((char *)frame_ + 140))),&DAT_001dbd14,&DAT_001fa5e8,(*(int *)((int)*(int *)((int)param_1 + 1004) + 0)),uVar5,&DAT_001dbd14,&DAT_001fa5e8);
              }
              else {
                iVarS40 = (*(int *)((char *)frame_ + 8));
                iVarS41 = (*(int *)((char *)frame_ + 12));
                iVarS42 = &DAT_001dbd14;
                iVarS43 = &DAT_001fa5e8;
                (**(code **)(((unsigned char *)0x000012ec) + iVar17))
                          (param_1,a1,(*(undefined4 *)((char *)frame_ + 140)),&DAT_001dbd84,iVar8,*(undefined4 *)(iVar15 + 0x14),
                           &DAT_001dbd14,&DAT_001fa5e8,iVarS40,iVarS41,iVarS42,iVarS43);
                if ((bVar2) || (*(ushort *)(((unsigned char *)0x00002d48) + iVar11) != (*(uint *)((char *)frame_ + 300)))) {
                  uVar20 = *puVar12;
                  puVar9 = (undefined4 *)(((unsigned char *)0x000048a0) + (*(int *)((char *)frame_ + 312)));
                  iVar4 = iVar3;
                  goto LAB_00098038;
                }
                uVar20 = *puVar12;
                puVar9 = (undefined4 *)(((unsigned char *)0x000048a0) + (*(int *)((char *)frame_ + 312)));
                iVar4 = iVar3;
LAB_00097fd4:
                (**(code **)(((unsigned char *)0x000012ec) + iVar17))
                          (param_1,a1,uVar5,&DAT_001dbd84,iVar4,uVar20,puVar9,&DAT_001fa5e8,(*(int *)((int)*(int *)((int)param_1 + 1004) + 0)),((*(undefined4 *)((char *)frame_ + 140))),&DAT_001dbd14,&DAT_001fa5e8);
              }
              FUN_000911a0(param_1,(*(undefined1 * *)((char *)frame_ + 356)));
              goto LAB_000980d0;
            }
            goto LAB_000984a0;
          }
          if ((*(int *)(param_1 + 0x420) != -1) ||
             (FUN_00092220(param_1), *(int *)(param_1 + 0x420) != -1)) {
            (*(int * *)((char *)frame_ + 340)) = &(*(int *)((char *)frame_ + 12));
            (*(undefined4 * *)((char *)frame_ + 336)) = &(*(undefined4 *)((char *)frame_ + 220));
            iVarS12 = *(int *)((int)*(int *)((int)param_1 + 1004) + 0);
            iVarS13 = *(int *)((int)*(int *)((int)param_1 + 980) + 4848);
            iVarS14 = &(*(undefined4 *)((char *)frame_ + 220));
            iVarS57 = *(int *)((int)*(int *)((int)param_1 + 1004) + 0);
            iVarS58 = *(int *)((int)param_1 + 1056);
            iVarS59 = &DAT_001dbd94;
            (**(code **)(((unsigned char *)0x000012f0) + iVar17))
                      (param_1,a1,(*(undefined4 *)((char *)frame_ + 220)),((undefined1 *)((char *)frame_ + 224)),iVar8,*(undefined4 *)(iVar15 + 0x24),&DAT_001dbd14,&DAT_001fa5e8,iVarS57,iVarS58,&DAT_001dbd14,iVarS59);
            (*(undefined1 * *)((char *)frame_ + 352)) = ((undefined1 *)((char *)frame_ + 120));
            (**(code **)(((unsigned char *)0x000012e4) + iVar17))
                      (param_1,a1,(*(undefined4 *)((char *)frame_ + 180)),((undefined1 *)((char *)frame_ + 184)),iVar3,(*(undefined4 *)((char *)frame_ + 220)),((undefined1 *)((char *)frame_ + 240)),&DAT_001fa5e8,iVar3,(*(undefined4 *)((char *)frame_ + 220)),((undefined1 *)((char *)frame_ + 240)),&DAT_001fa5e8);
            iVarS10 = *(int *)((int)*(int *)((int)param_1 + 980) + 4836);
            iVarS56 = &DAT_001dbd74;
            (**(code **)(((unsigned char *)0x000012e4) + iVar17))
                      (param_1,a1,(*(undefined4 *)((char *)frame_ + 60)),((undefined1 *)((char *)frame_ + 64)),iVar3,(*(undefined4 *)((char *)frame_ + 220)),((undefined1 *)((char *)frame_ + 240)),&DAT_001fa5e8,iVarS9,iVar8,iVarS56,&DAT_001fa5e8);
            (**(code **)(((unsigned char *)0x00001318) + iVar17))
                      (param_1,a1,(*(undefined4 *)((char *)frame_ + 180)),((undefined1 *)((char *)frame_ + 184)),iVar3,(*(undefined4 *)((char *)frame_ + 180)),((undefined1 *)((char *)frame_ + 200)),&DAT_001fa5e8);
            iVarS44 = ((undefined1 *)((char *)frame_ + 200));
            (**(code **)(((unsigned char *)0x000012ec) + iVar17))
                      (param_1,a1,(*(undefined4 *)((char *)frame_ + 180)),((undefined1 *)((char *)frame_ + 184)),iVar3,(*(undefined4 *)((char *)frame_ + 60)),((undefined1 *)((char *)frame_ + 80)),&DAT_001fa5e8,iVar3,(*(undefined4 *)((char *)frame_ + 180)),iVarS44,&DAT_001fa5e8);
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

/* FUN_00098500 @ 0x98500 (6432 bytes) */
int FUN_00098500(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10)
  int param_1;
  int param_2;
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
  int iVar16;
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
  unsigned int frame_[140] __attribute__((aligned(16)));
  
  if (param_1 == 0) {
    return 1;
  }
  iVar16 = param_1 + 0xf8 + param_2 * 0x3c;
  if (*(int *)(iVar16 + 0x24) == -1) {
    return 2;
  }
  bVar1 = param_5 != 0;
  if (bVar1) {
    if (param_6 == 0) {
      iVar4 = *(int *)(iVar16 + 0x2c);
    }
    else {
      iVar4 = *(int *)(iVar16 + 0x34);
    }
    if (iVar4 == -1) {
      return 2;
    }
  }
  iVar4 = *(int *)(param_1 + 0x3d4);
  iVar17 = *(int *)(*(int *)(iVar4 + 4) + 0x10);
  if (((unsigned char *)0x0000150c)[param_2 * 0x6c + iVar4] != '\0') {
    if (*(int *)(iVar16 + 0x28) == -1) {
      return 2;
    }
    if (*(int *)(iVar16 + 0x30) == -1) {
      return 2;
    }
    if ((*(float *)(param_2 * 0x80 + iVar17 + 0x251c) != 0.0) && (*(int *)(iVar16 + 0x38) == -1)) {
      return 2;
    }
  }
  if ((param_8 == 2) && (*(int *)(iVar16 + 4) == -1)) {
    return 2;
  }
  if (param_9 == 2) {
    iVar5 = (byte)((unsigned char *)0x00002d48)[iVar17 + 4] + 1;
    iVar9 = iVar16;
    do {
      if ((*(int *)(iVar9 + 0xc) == -1) && (*(int *)(iVar16 + 8) == -1)) {
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
      iVar9 = FUN_000913e0(param_1,*(undefined4 *)(iVar4 + 0x290),((undefined1 *)((char *)frame_ + 12)),((undefined1 *)((char *)frame_ + 16)),
                           ((undefined1 *)((char *)frame_ + 24)));
      if (iVar9 != 0) {
        return iVar9;
      }
      uVar20 = uVar20 + 1;
      iVar4 = iVar4 + 4;
    } while (uVar20 <= (byte)((unsigned char *)0x00002d48)[iVar17 + 4]);
  }
  if (param_10 == 2) {
    iVar17 = (byte)((unsigned char *)0x00002d48)[iVar17 + 4] + 1;
    iVar4 = iVar16;
    do {
      if ((*(int *)(iVar4 + 0x18) == -1) && (*(int *)(iVar16 + 0x14) == -1)) {
        return 2;
      }
      iVar4 = iVar4 + 4;
      iVar17 = iVar17 + -1;
    } while (iVar17 != 0);
  }
  (*(undefined1 * *)((char *)frame_ + 428)) = ((undefined1 *)((char *)frame_ + 72));
  iVar9 = *(int *)(param_1 + 0x3d4);
  iVar17 = *(int *)(*(int *)(iVar9 + 4) + 0x10);
  iVar4 = FUN_00090ca0(param_1,1,(*(undefined1 * *)((char *)frame_ + 428)));
  if (iVar4 != 0) {
    return 7;
  }
  (*(undefined1 * *)((char *)frame_ + 436)) = ((undefined1 *)((char *)frame_ + 152));
  iVar4 = FUN_00090ca0(param_1,1,(*(undefined1 * *)((char *)frame_ + 436)));
  if (iVar4 != 0) {
    return 7;
  }
  (*(undefined1 * *)((char *)frame_ + 448)) = ((undefined1 *)((char *)frame_ + 232));
  iVar4 = FUN_00090ca0(param_1,2,(*(undefined1 * *)((char *)frame_ + 448)));
  if (iVar4 != 0) {
    return 7;
  }
  iVar4 = FUN_00090ca0(param_1,2,((undefined1 *)((char *)frame_ + 272)));
  if (iVar4 != 0) {
    return 7;
  }
  iVar4 = *(int *)(param_1 + 0x3f8);
  if (iVar4 == -1) {
    if ((*(uint *)(((unsigned char *)0x000013c0) + iVar9) & 4) == 0) {
      FUN_000916d0(param_1);
    }
    else {
      FUN_000914e0(param_1);
    }
    iVar4 = *(int *)(param_1 + 0x3f8);
    if (iVar4 == -1) {
      return 2;
    }
  }
  if (*(char *)(iVar9 + 0x128) == '\0') {
    if (*(char *)(iVar9 + 300) == '\0') {
      if (*(int *)(param_1 + 0x448) != -1) goto LAB_00098818;
      FUN_00091a30(param_1);
      iVar5 = *(int *)(param_1 + 0x448);
    }
    else {
      if (*(int *)(param_1 + 0x470) != -1) goto LAB_00098818;
      FUN_00091d70(param_1);
      iVar5 = *(int *)(param_1 + 0x470);
    }
  }
  else {
    if (*(int *)(param_1 + 0x498) != -1) goto LAB_00098818;
    FUN_00091b90(param_1);
    iVar5 = *(int *)(param_1 + 0x498);
  }
  if (iVar5 == -1) {
    return 2;
  }
LAB_00098818:
  iVar5 = (*(int **)(param_1 + 0x3ec))[2];
  a1 = **(undefined4 **)(param_1 + 0x3f0);
  a4 = **(int **)(param_1 + 0x3ec);
  if (param_7 == 0) {
    (*(undefined * *)((char *)frame_ + 460)) = &DAT_001f8514;
    (*(code * *)((char *)frame_ + 464)) = FUN_001d8514;
    (*(code * *)((char *)frame_ + 432)) = FUN_001d8514;
    iVarS11 = *(int *)((int)*(int *)((int)param_1 + 1004) + 8);
    iVarS12 = *(int *)((int)iVar16 + 36);
    iVarS13 = &DAT_001dbd14;
    (**(code **)(((unsigned char *)0x000012ec) + iVar9))
              (param_1,a1,(*(undefined4 *)((char *)frame_ + 76)),((undefined1 *)((char *)frame_ + 80)),a4,iVar4,&DAT_001dbcd4,&DAT_001fa5e8,iVarS11,iVarS12,iVarS13,&DAT_001fa5e8);
    iVarS48 = *(int *)((int)*(int *)((int)param_1 + 1004) + 0);
    iVarS49 = *(int *)((int)param_1 + 1016);
    iVarS50 = &DAT_001dbd14;
    iVarS51 = &DAT_001fa5e8;
    (**(code **)(((unsigned char *)0x000012f4) + iVar9))
              (param_1,a1,(*(undefined4 *)((char *)frame_ + 76)),((undefined1 *)((char *)frame_ + 80)),iVar5,*(undefined4 *)(iVar16 + 0x24),&DAT_001dbcd4,
               ((unsigned char *)0x00003880) + (int)(*(code * *)((char *)frame_ + 432)),iVarS48,iVarS49,iVarS50,iVarS51,iVarS48,(*(undefined4 *)((char *)frame_ + 76)),iVarS50,iVarS51);
  }
  else {
    (*(undefined * *)((char *)frame_ + 460)) = &DAT_001f8514;
    (*(code * *)((char *)frame_ + 464)) = FUN_001d8514;
    (*(code * *)((char *)frame_ + 432)) = FUN_001d8514;
    iVarS52 = *(int *)((int)*(int *)((int)param_1 + 1004) + 8);
    iVarS53 = *(int *)((int)iVar16 + 36);
    iVarS54 = &DAT_001dbd14;
    iVarS55 = &DAT_001dbd94;
    (**(code **)(((unsigned char *)0x000012f4) + iVar9))
              (param_1,a1,(*(undefined4 *)((char *)frame_ + 76)),((undefined1 *)((char *)frame_ + 80)),a4,iVar4,&DAT_001dbcd4,&DAT_001fa5e8,iVarS52,iVarS53,iVarS54,&DAT_001fa5e8,a4,iVar4,iVarS54,iVarS55);
  }
  (*(undefined1 * *)((char *)frame_ + 452)) = ((undefined1 *)((char *)frame_ + 296));
  (*(code * *)((char *)frame_ + 444)) = FUN_001d8514;
  pcVar21 = 0x000020d4 + (int)(*(undefined * *)((char *)frame_ + 460));
  (**(code **)(((unsigned char *)0x000012e4) + iVar9))
            (param_1,a1,(*(undefined4 *)((char *)frame_ + 156)),&DAT_001dbd04,a4,(*(undefined4 *)((char *)frame_ + 76)),&DAT_001dbd74,pcVar21,a4,(*(undefined4 *)((char *)frame_ + 76)),&DAT_001dbd74,pcVar21);
  (**(code **)(((unsigned char *)0x00001318) + iVar9))
            (param_1,a1,(*(undefined4 *)((char *)frame_ + 276)),((undefined1 *)((char *)frame_ + 280)),a4,(*(undefined4 *)((char *)frame_ + 156)),&DAT_001fa5f8,pcVar21);
  iVarS14 = (int)(*(code * *)((char *)frame_ + 464)) + 14336;
  (**(code **)(((unsigned char *)0x000012ec) + iVar9))
            (param_1,a1,(*(undefined4 *)((char *)frame_ + 76)),((undefined1 *)((char *)frame_ + 80)),a4,(*(undefined4 *)((char *)frame_ + 276)),(*(undefined1 * *)((char *)frame_ + 452)),pcVar21,a4,(*(undefined4 *)((char *)frame_ + 76)),iVarS14,pcVar21);
  if ((bVar1) && (param_6 == 0)) {
    iVarS15 = &DAT_001fa5f8;
    (**(code **)(((unsigned char *)0x000012ec) + iVar9))
              (param_1,a1,(*(undefined4 *)((char *)frame_ + 156)),&DAT_001dbd64,a4,(*(undefined4 *)((char *)frame_ + 276)),(*(undefined1 * *)((char *)frame_ + 452)),pcVar21,a4,(*(undefined4 *)((char *)frame_ + 156)),iVarS15,pcVar21);
    (*(undefined4 *)((char *)frame_ + 60)) = 1;
    (*(undefined4 *)((char *)frame_ + 64)) = 5;
    (*(undefined4 *)((char *)frame_ + 68)) = 4;
    (*(int *)((char *)frame_ + 56)) = param_6;
    iVarS1 = *(int *)((int)*(int *)((int)param_1 + 1004) + 0);
    iVarS2 = *(int *)((int)*(int *)((int)param_1 + 980) + 4836);
    iVarS3 = &(*(int *)((char *)frame_ + 56));
    iVarS89 = *(int *)((int)*(int *)((int)param_1 + 1004) + 0);
    iVarS90 = (*(undefined4 *)((char *)frame_ + 156));
    iVarS91 = &(*(int *)((char *)frame_ + 56));
    (**(code **)(((unsigned char *)0x000012e4) + iVar9))
              (param_1,a1,(*(undefined4 *)((char *)frame_ + 276)),((undefined1 *)((char *)frame_ + 280)),iVar5,*(undefined4 *)(iVar16 + 0x2c),&DAT_001dbd74,pcVar21,iVarS89,iVarS90,iVarS91,pcVar21);
    (**(code **)(((unsigned char *)0x00001314) + iVar9))
              (param_1,a1,(*(undefined4 *)((char *)frame_ + 276)),((undefined1 *)((char *)frame_ + 280)),a4,(*(undefined4 *)((char *)frame_ + 276)),(*(undefined1 * *)((char *)frame_ + 452)),pcVar21);
  }
  if (((unsigned char *)0x0000150c)[param_2 * 0x6c + iVar9] == '\0') {
    (*(undefined1 * *)((char *)frame_ + 400)) = ((undefined1 *)((char *)frame_ + 272));
    if (bVar1) {
      if (param_6 == 0) {
        (*(int *)((char *)frame_ + 396)) = 1;
      }
      else {
        (*(int *)((char *)frame_ + 396)) = 1;
        (**(code **)(((unsigned char *)0x000012e8) + iVar9))
                  (param_1,a1,(*(undefined4 *)((char *)frame_ + 276)),((undefined1 *)((char *)frame_ + 280)),iVar5,*(undefined4 *)(iVar16 + 0x34),
                   (*(code * *)((char *)frame_ + 464)) + 0x3800,0x000020d4 + (int)(*(undefined * *)((char *)frame_ + 460)));
      }
    }
    else {
      (*(int *)((char *)frame_ + 396)) = 0;
    }
  }
  else {
    iVar4 = FUN_00090ca0(param_1,2,((undefined1 *)((char *)frame_ + 112)));
    if (iVar4 != 0) {
      return 7;
    }
    pcVar21 = 0x000020d4 + (int)(*(undefined * *)((char *)frame_ + 460));
    iVarS4 = *(int *)((int)*(int *)((int)param_1 + 1004) + 0);
    iVarS5 = *(int *)((int)*(int *)((int)param_1 + 980) + 4836);
    iVarS92 = *(int *)((int)*(int *)((int)param_1 + 1004) + 0);
    iVarS93 = (*(undefined4 *)((char *)frame_ + 76));
    (**(code **)(((unsigned char *)0x000012e4) + iVar9))
              (param_1,a1,(*(undefined4 *)((char *)frame_ + 116)),((undefined1 *)((char *)frame_ + 120)),iVar5,*(undefined4 *)(iVar16 + 0x28),((unsigned char *)0x00003860) + (int)(*(code * *)((char *)frame_ + 444)),pcVar21,iVarS92,iVarS93,((unsigned char *)0x00003860) + (int)(*(code * *)((char *)frame_ + 444)),pcVar21);
    if (*(float *)(param_2 * 0x80 + iVar17 + 0x251c) == 0.0) {
      iVarS62 = *(int *)((int)*(int *)((int)param_1 + 1004) + 8);
      iVarS63 = *(int *)((int)iVar16 + 48);
      iVarS64 = (int)(*(code * *)((char *)frame_ + 464)) + 14336;
      (**(code **)(((unsigned char *)0x0000130c) + iVar9))
                (param_1,a1,(*(undefined4 *)((char *)frame_ + 116)),((undefined1 *)((char *)frame_ + 120)),a4,(*(undefined4 *)((char *)frame_ + 116)),((undefined1 *)((char *)frame_ + 136)),pcVar21,iVarS62,iVarS63,iVarS64,pcVar21);
    }
    else {
      iVar4 = FUN_00090ca0(param_1,2,((undefined1 *)((char *)frame_ + 192)));
      if (iVar4 != 0) {
        return 7;
      }
      iVarS65 = *(int *)((int)*(int *)((int)param_1 + 1004) + 8);
      iVarS66 = *(int *)((int)iVar16 + 48);
      iVarS67 = (int)(*(code * *)((char *)frame_ + 464)) + 14336;
      (**(code **)(((unsigned char *)0x0000130c) + iVar9))
                (param_1,a1,(*(undefined4 *)((char *)frame_ + 196)),((undefined1 *)((char *)frame_ + 200)),a4,(*(undefined4 *)((char *)frame_ + 116)),((undefined1 *)((char *)frame_ + 136)),pcVar21,iVarS65,iVarS66,iVarS67,pcVar21);
      iVarS16 = (*(undefined4 *)((char *)frame_ + 196));
      iVarS17 = ((undefined1 *)((char *)frame_ + 216));
      (**(code **)(((unsigned char *)0x000012ec) + iVar9))
                (param_1,a1,(*(undefined4 *)((char *)frame_ + 116)),((undefined1 *)((char *)frame_ + 120)),a4,(*(undefined4 *)((char *)frame_ + 116)),((undefined1 *)((char *)frame_ + 136)),pcVar21,a4,iVarS16,iVarS17,pcVar21);
      iVarS68 = *(int *)((int)*(int *)((int)param_1 + 1004) + 8);
      iVarS69 = *(int *)((int)iVar16 + 56);
      iVarS70 = (int)(*(code * *)((char *)frame_ + 464)) + 14336;
      (**(code **)(((unsigned char *)0x00001324) + iVar9))
                (param_1,a1,(*(undefined4 *)((char *)frame_ + 116)),((undefined1 *)((char *)frame_ + 120)),a4,(*(undefined4 *)((char *)frame_ + 116)),((undefined1 *)((char *)frame_ + 136)),pcVar21,iVarS68,iVarS69,iVarS70,pcVar21);
      FUN_000911a0(param_1,((undefined1 *)((char *)frame_ + 192)));
    }
    if (bVar1) {
      if (param_6 == 0) {
        iVarS18 = (*(undefined4 *)((char *)frame_ + 276));
        iVarS19 = (*(undefined1 * *)((char *)frame_ + 452));
        (**(code **)(((unsigned char *)0x000012ec) + iVar9))
                  (param_1,a1,(*(undefined4 *)((char *)frame_ + 116)),((undefined1 *)((char *)frame_ + 120)),a4,(*(undefined4 *)((char *)frame_ + 116)),((undefined1 *)((char *)frame_ + 136)),
                   0x000020d4 + (int)(*(undefined * *)((char *)frame_ + 460)),a4,iVarS18,iVarS19,0x000020d4 + (int)(*(undefined * *)((char *)frame_ + 460)));
      }
      else {
        iVarS20 = *(int *)((int)*(int *)((int)param_1 + 1004) + 8);
        iVarS21 = *(int *)((int)iVar16 + 52);
        iVarS22 = (int)(*(code * *)((char *)frame_ + 464)) + 14336;
        (**(code **)(((unsigned char *)0x000012ec) + iVar9))
                  (param_1,a1,(*(undefined4 *)((char *)frame_ + 116)),((undefined1 *)((char *)frame_ + 120)),a4,(*(undefined4 *)((char *)frame_ + 116)),((undefined1 *)((char *)frame_ + 136)),
                   0x000020d4 + (int)(*(undefined * *)((char *)frame_ + 460)),iVarS20,iVarS21,iVarS22,0x000020d4 + (int)(*(undefined * *)((char *)frame_ + 460)));
      }
    }
    (*(undefined1 * *)((char *)frame_ + 400)) = ((undefined1 *)((char *)frame_ + 112));
    FUN_000911a0(param_1,((undefined1 *)((char *)frame_ + 272)));
    (*(int *)((char *)frame_ + 396)) = 1;
  }
  pcVar21 = 0x000020d4 + (int)(*(undefined * *)((char *)frame_ + 460));
  (**(code **)(((unsigned char *)0x000012e4) + iVar9))
            (param_1,a1,(*(undefined4 *)((char *)frame_ + 236)),((undefined1 *)((char *)frame_ + 240)),a4,(*(undefined4 *)((char *)frame_ + 76)),((unsigned char *)0x00003860) + (int)(*(code * *)((char *)frame_ + 444)),pcVar21,a4,iVar5,((unsigned char *)0x00003860) + (int)(*(code * *)((char *)frame_ + 444)),pcVar21);
  FUN_000911a0(param_1,(*(undefined1 * *)((char *)frame_ + 436)));
  if ((param_8 != 0) && (param_8 != 3)) {
    uVar20 = 0;
    bVar1 = (*(int *)((char *)frame_ + 396)) == 0;
    iVar4 = param_1;
    do {
      uVar18 = *(undefined4 *)(iVar4 + 0x5b0);
      uVar22 = *(undefined4 *)(iVar4 + 0x64c);
      if (param_8 == 1) {
        if (bVar1) {
          iVarS7 = *(int *)((int)*(int *)((int)param_1 + 1004) + 0);
          (**(code **)(((unsigned char *)0x000012f0) + iVar9))
                    (param_1,a1,uVar18,&DAT_001dbd84,uVar22,*(undefined4 *)(iVar4 + 0x650),
                     &DAT_001dbd14,pcVar21,iVarS7,uVar18,&DAT_001dbd14,pcVar21);
        }
        else {
          /* stack words 9-11 of the shared call below: arm A = stock 0x98f18 (words from (*(undefined1 * *)((char *)frame_ + 400))), arm B = stock 0x99058 (goto below) */
          iVarSw0 = a4;
          iVarSw1 = *(int *)((int)(*(undefined1 * *)((char *)frame_ + 400)) + 4);
          iVarSw2 = (int)(*(undefined1 * *)((char *)frame_ + 400)) + 24;
          uVar7 = *(undefined4 *)(iVar4 + 0x650);
LAB_00099084:
          (**(code **)(((unsigned char *)0x000012f4) + iVar9))
                    (param_1,a1,uVar18,&DAT_001dbd84,uVar22,uVar7,&DAT_001dbd14,pcVar21,iVarSw0,iVarSw1,iVarSw2,pcVar21,a4,uVar18,&DAT_001dbd14,pcVar21);
        }
      }
      else {
        if (bVar1) {
          iVarSw0 = *(int *)((int)*(int *)((int)param_1 + 1004) + 8);
          iVarSw1 = *(int *)((int)iVar16 + 4);
          iVarSw2 = &DAT_001dbd14;
          uVar7 = *(undefined4 *)(iVar4 + 0x650);
          goto LAB_00099084;
        }
        iVar13 = FUN_00090ca0(param_1,0,(*(undefined1 * *)((char *)frame_ + 436)));
        if (iVar13 != 0) {
          return 7;
        }
        iVarS23 = *(int *)((int)*(int *)((int)param_1 + 1004) + 8);
        iVarS24 = *(int *)((int)iVar16 + 4);
        (**(code **)(((unsigned char *)0x000012ec) + iVar9))
                  (param_1,a1,(*(undefined4 *)((char *)frame_ + 156)),&DAT_001dbd24,uVar22,*(undefined4 *)(iVar4 + 0x650),
                   &DAT_001dbd14,pcVar21,iVarS23,iVarS24,&DAT_001dbd14,pcVar21);
        iVarS56 = *(int *)((int)(*(undefined1 * *)((char *)frame_ + 400)) + 4);
        iVarS57 = (int)(*(undefined1 * *)((char *)frame_ + 400)) + 24;
        (**(code **)(((unsigned char *)0x000012f4) + iVar9))
                  (param_1,a1,uVar18,&DAT_001dbd84,a4,(*(undefined4 *)((char *)frame_ + 156)),&DAT_001dbd14,pcVar21,a4,iVarS56,iVarS57,pcVar21,a4,uVar18,&DAT_001dbd14,pcVar21);
        FUN_000911a0(param_1,(*(undefined1 * *)((char *)frame_ + 436)));
      }
      uVar20 = uVar20 + 1;
      iVar4 = iVar4 + 0x28;
    } while (uVar20 <= (byte)((unsigned char *)0x00002d48)[iVar17 + 4]);
  }
  puVar23 = ((undefined1 *)((char *)frame_ + 312));
  uVar20 = 0;
  (*(undefined1 * *)((char *)frame_ + 456)) = puVar23;
  do {
    iVar4 = FUN_00090ca0(param_1,1,puVar23);
    if (iVar4 != 0) {
      return 7;
    }
    uVar20 = uVar20 + 1;
    puVar23 = puVar23 + 0x28;
  } while (uVar20 <= (byte)((unsigned char *)0x00002d48)[iVar17 + 4]);
  if (bVar2) {
    do {
      uVar20 = 0;
      puVar12 = &(*(undefined4 *)((char *)frame_ + 316));
      do {
        iVar4 = uVar20 * 0x28;
        uVar20 = uVar20 + 1;
        iVarS87 = ((unsigned char *)((undefined1 *)((char *)frame_ + 240)) + 16);
        iVarS88 = &DAT_001dbdb4;
        (**(code **)(((unsigned char *)0x0000132c) + iVar9))
                  (param_1,a1,*puVar12,(*(undefined1 * *)((char *)frame_ + 456)) + iVar4 + 8,a4,(*(undefined4 *)((char *)frame_ + 236)),&DAT_001dbd34,
                   0x000020d4 + (int)(*(undefined * *)((char *)frame_ + 460)),a4,(*(undefined4 *)((char *)frame_ + 236)),iVarS87,(uVar20 == 1 ? (0x000020d4 + (int)(*(undefined * *)((char *)frame_ + 460))) : ((int)(*(code * *)((char *)frame_ + 432)) + 14464)),a4,(*(undefined4 *)((char *)frame_ + 236)),iVarS88,0x000020d4 + (int)(*(undefined * *)((char *)frame_ + 460)));
        if ((byte)((unsigned char *)0x00002d48)[iVar17 + 4] < uVar20) goto LAB_000994dc;
        puVar12 = puVar12 + 10;
      } while (uVar20 != 0);
    } while( true );
  }
  iVar4 = FUN_00090ca0(param_1,2,(*(undefined1 * *)((char *)frame_ + 436)));
  if (iVar4 == 0) {
    (*(undefined1 * *)((char *)frame_ + 440)) = ((undefined1 *)((char *)frame_ + 192));
    iVar4 = FUN_00090ca0(param_1,2,(*(undefined1 * *)((char *)frame_ + 440)));
    if (iVar4 == 0) {
      if (((unsigned char *)0x00002d48)[iVar17 + 5] == '\0') {
        (*(int *)((char *)frame_ + 56)) = 4;
        (*(undefined4 *)((char *)frame_ + 60)) = 4;
        (*(undefined4 *)((char *)frame_ + 68)) = 4;
        (*(undefined4 *)((char *)frame_ + 64)) = 5;
        iVarS8 = *(int *)((int)*(int *)((int)param_1 + 980) + 4848);
        iVarS95 = &(*(int *)((char *)frame_ + 56));
        (**(code **)(((unsigned char *)0x000012f0) + iVar9))
                  (param_1,a1,(*(undefined4 *)((char *)frame_ + 316)),((undefined1 *)((char *)frame_ + 320)),a4,(*(undefined4 *)((char *)frame_ + 76)),(*(code * *)((char *)frame_ + 464)) + 0x3800,0x000020d4 + (int)(*(undefined * *)((char *)frame_ + 460)),a4,(*(undefined4 *)((char *)frame_ + 76)),iVarS95,0x000020d4 + (int)(*(undefined * *)((char *)frame_ + 460)));
      }
      else {
        if ((*(int *)(param_1 + 0x420) == -1) &&
           (FUN_00092220(param_1), *(int *)(param_1 + 0x420) == -1)) {
          return 2;
        }
        iVarS9 = *(int *)((int)param_1 + 1056);
        iVarS10 = (int)(*(code * *)((char *)frame_ + 432)) + 14464;
        (**(code **)(((unsigned char *)0x000012f0) + iVar9))
                  (param_1,a1,(*(undefined4 *)((char *)frame_ + 316)),((undefined1 *)((char *)frame_ + 320)),a4,(*(undefined4 *)((char *)frame_ + 76)),(*(code * *)((char *)frame_ + 464)) + 0x3800,
                   0x000020d4 + (int)(*(undefined * *)((char *)frame_ + 460)),a4,iVarS9,(*(code * *)((char *)frame_ + 464)) + 0x3800,iVarS10);
      }
      pcVar21 = 0x000020d4 + (int)(*(undefined * *)((char *)frame_ + 460));
      (**(code **)(((unsigned char *)0x000012e4) + iVar9))
                (param_1,a1,(*(undefined4 *)((char *)frame_ + 156)),((undefined1 *)((char *)frame_ + 160)),a4,(*(undefined4 *)((char *)frame_ + 316)),((undefined1 *)((char *)frame_ + 336)),pcVar21,a4,(*(undefined4 *)((char *)frame_ + 316)),((undefined1 *)((char *)frame_ + 336)),pcVar21);
      iVarS6 = *(int *)((int)*(int *)((int)param_1 + 980) + 4836);
      iVarS94 = (int)(*(code * *)((char *)frame_ + 444)) + 14432;
      (**(code **)(((unsigned char *)0x000012e4) + iVar9))
                (param_1,a1,(*(undefined4 *)((char *)frame_ + 196)),((undefined1 *)((char *)frame_ + 200)),a4,(*(undefined4 *)((char *)frame_ + 316)),((undefined1 *)((char *)frame_ + 336)),pcVar21,a4,iVar5,iVarS94,pcVar21);
      (**(code **)(((unsigned char *)0x00001318) + iVar9))
                (param_1,a1,(*(undefined4 *)((char *)frame_ + 156)),((undefined1 *)((char *)frame_ + 160)),a4,(*(undefined4 *)((char *)frame_ + 156)),((undefined1 *)((char *)frame_ + 176)),pcVar21);
      iVarS25 = ((undefined1 *)((char *)frame_ + 176));
      (**(code **)(((unsigned char *)0x000012ec) + iVar9))
                (param_1,a1,(*(undefined4 *)((char *)frame_ + 156)),((undefined1 *)((char *)frame_ + 160)),a4,(*(undefined4 *)((char *)frame_ + 196)),((undefined1 *)((char *)frame_ + 216)),pcVar21,a4,(*(undefined4 *)((char *)frame_ + 156)),iVarS25,pcVar21);
      do {
        uVar20 = 0;
        pcVar21 = 0x000020d4 + (int)(*(undefined * *)((char *)frame_ + 460));
        puVar12 = (undefined4 *)(iVar9 + 0x290);
        puVar10 = &(*(undefined4 *)((char *)frame_ + 316));
        do {
          FUN_000913e0(param_1,*puVar12,&(*(int *)((char *)frame_ + 8)),&(*(int *)((char *)frame_ + 20)),&(*(undefined4 *)((char *)frame_ + 40)));
          iVar4 = uVar20 * 0x28;
          uVar20 = uVar20 + 1;
          iVarS71 = (*(undefined4 *)((char *)frame_ + 236));
          iVarS72 = ((unsigned char *)((undefined1 *)((char *)frame_ + 240)) + 16);
          iVarS73 = (*(int *)((char *)frame_ + 8));
          iVarS74 = (*(int *)((char *)frame_ + 20));
          iVarS75 = &(*(undefined4 *)((char *)frame_ + 40));
          iVarS76 = (int)(*(undefined * *)((char *)frame_ + 460)) + 8404;
          (**(code **)(((unsigned char *)0x0000132c) + iVar9))
                    (param_1,a1,*puVar10,(*(undefined1 * *)((char *)frame_ + 456)) + iVar4 + 8,a4,(*(undefined4 *)((char *)frame_ + 156)),((undefined1 *)((char *)frame_ + 176)),pcVar21,a4,iVarS71,iVarS72,pcVar21,iVarS73,iVarS74,iVarS75,iVarS76);
          if ((byte)((unsigned char *)0x00002d48)[iVar17 + 4] < uVar20) {
            FUN_000911a0(param_1,(*(undefined1 * *)((char *)frame_ + 436)));
            FUN_000911a0(param_1,(*(undefined1 * *)((char *)frame_ + 440)));
LAB_000994dc:
            puVar12 = &(*(undefined4 *)((char *)frame_ + 316));
            (*(code * *)((char *)frame_ + 408)) = FUN_001d8514;
            (*(code * *)((char *)frame_ + 412)) = FUN_001d8514;
            bVar1 = (*(int *)((char *)frame_ + 396)) != 0;
            (*(code * *)((char *)frame_ + 420)) = FUN_001d8514;
            bVar3 = iStack00000020 == 0;
            (*(uint *)((char *)frame_ + 404)) = 0x81fa;
            (*(uint *)((char *)frame_ + 392)) = 0;
            (*(code * *)((char *)frame_ + 416)) = FUN_001d8514;
            puVar23 = (*(undefined1 * *)((char *)frame_ + 456)) + 8;
            (*(code * *)((char *)frame_ + 424)) = FUN_001d8514;
            iVar4 = iVar9;
            iVar13 = param_1;
            iVar14 = param_1;
            iVar15 = iVar16;
            do {
              if (bVar1) {
                iVarS26 = &DAT_001dbd14;
                (**(code **)(((unsigned char *)0x000012ec) + iVar9))
                          (param_1,a1,*puVar12,puVar23,a4,*(undefined4 *)((*(undefined1 * *)((char *)frame_ + 400)) + 4),
                           (*(undefined1 * *)((char *)frame_ + 400)) + 0x18,&DAT_001fa5e8,a4,*puVar12,iVarS26,&DAT_001fa5e8);
              }
              if (bVar2) {
                if (((!bVar3) && (*(char *)(iVar9 + 0x12d) != '\0')) &&
                   (*(ushort *)(((unsigned char *)0x00002d48) + iVar17) == (*(uint *)((char *)frame_ + 404)))) {
                  iVarS27 = *(int *)((int)*(int *)((int)param_1 + 1004) + 0);
                  iVarS28 = *(int *)((int)puVar12 + 0);
                  iVarS29 = &DAT_001dbcf4;
                  (**(code **)(((unsigned char *)0x000012ec) + iVar9))
                            (param_1,a1,*(undefined4 *)(iVar14 + 0x600),
                             ((unsigned char *)0x00003870) + (int)(*(code * *)((char *)frame_ + 408)),a4,*(undefined4 *)(iVar14 + 0x600),
                             (*(code * *)((char *)frame_ + 464)) + 0x3800,&DAT_001fa5e8,iVarS27,iVarS28,iVarS29,&DAT_001fa5e8);
                }
              }
              else {
                uVar18 = *(undefined4 *)(iVar14 + 0x600);
                if (*(int *)(iVar15 + 0x18) == -1) {
                  FUN_000912f0(param_1,*(undefined4 *)(iVar4 + 0x288),3,&(*(int *)((char *)frame_ + 8)),&(*(int *)((char *)frame_ + 20)));
                }
                if (param_10 == 1) {
                  iVar6 = (*(int *)((char *)frame_ + 8));
                  iVar8 = (*(int *)((char *)frame_ + 20));
                  if ((!bVar3) && (*(ushort *)(((unsigned char *)0x00002d48) + iVar17) == (*(uint *)((char *)frame_ + 404))))
                  goto LAB_0009966c;
LAB_000996c0:
                  (**(code **)(((unsigned char *)0x000012f4) + iVar9))
                            (param_1,a1,uVar18,((unsigned char *)0x00003870) + (int)(*(code * *)((char *)frame_ + 408)),iVar6,iVar8,
                             &DAT_001dbd14,&DAT_001fa5e8,(*(int *)((int)*(int *)((int)param_1 + 1004) + 0)),(*(int *)((int)puVar12 + 0)),(&DAT_001dbcf4),&DAT_001fa5e8,(*(int *)((int)*(int *)((int)param_1 + 1004) + 0)),uVar18,(&DAT_001dbd14),&DAT_001fa5e8);
                }
                else {
                  iVar8 = *(int *)(iVar15 + 0x18);
                  if (iVar8 == -1) {
                    iVar6 = FUN_00090ca0(param_1,1,(*(undefined1 * *)((char *)frame_ + 436)));
                    if (iVar6 != 0) {
                      return 7;
                    }
                    if (iVar5 == (*(int *)((char *)frame_ + 8))) {
                      iVarS30 = *(int *)((int)*(int *)((int)param_1 + 1004) + 0);
                      iVarS31 = *(int *)((int)puVar12 + 0);
                      iVarS32 = &DAT_001dbcf4;
                      iVarS33 = &DAT_001fa5e8;
                      (**(code **)(((unsigned char *)0x000012ec) + iVar9))
                                (param_1,a1,(*(undefined4 *)((char *)frame_ + 156)),&DAT_001dbd84,iVar5,(*(int *)((char *)frame_ + 20)),&DAT_001dbd14,
                                 &DAT_001fa5e8,iVarS30,iVarS31,iVarS32,iVarS33);
                      if ((bVar3) || (*(ushort *)(((unsigned char *)0x00002d48) + iVar17) != (*(uint *)((char *)frame_ + 404)))) {
                        uVar22 = *(undefined4 *)(iVar16 + 0x14);
                        puVar10 = &DAT_001dbd14;
                        iVar6 = iVar5;
                        goto LAB_00099980;
                      }
                      uVar22 = *(undefined4 *)(iVar16 + 0x14);
                      puVar10 = &DAT_001dbd14;
                      iVar6 = iVar5;
LAB_0009991c:
                      (**(code **)(((unsigned char *)0x000012ec) + iVar9))
                                (param_1,a1,uVar18,&DAT_001dbd84,iVar6,uVar22,puVar10,&DAT_001fa5e8,(*(int *)((int)*(int *)((int)param_1 + 1004) + 0)),((*(undefined4 *)((char *)frame_ + 156))),&DAT_001dbd14,&DAT_001fa5e8)
                      ;
                    }
                    else {
                      iVarS34 = (*(int *)((char *)frame_ + 8));
                      iVarS35 = (*(int *)((char *)frame_ + 20));
                      iVarS36 = &DAT_001dbd14;
                      iVarS37 = &DAT_001fa5e8;
                      (**(code **)(((unsigned char *)0x000012ec) + iVar9))
                                (param_1,a1,(*(undefined4 *)((char *)frame_ + 156)),&DAT_001dbd84,iVar5,
                                 *(undefined4 *)(iVar16 + 0x14),&DAT_001dbd14,&DAT_001fa5e8,iVarS34,iVarS35,iVarS36,iVarS37);
                      if ((!bVar3) && (*(ushort *)(((unsigned char *)0x00002d48) + iVar17) == (*(uint *)((char *)frame_ + 404)))) {
                        uVar22 = *puVar12;
                        puVar10 = (undefined4 *)(((unsigned char *)0x000037e0) + (int)(*(code * *)((char *)frame_ + 412)));
                        iVar6 = a4;
                        goto LAB_0009991c;
                      }
                      uVar22 = *puVar12;
                      puVar10 = (undefined4 *)(((unsigned char *)0x000037e0) + (int)(*(code * *)((char *)frame_ + 412)));
                      iVar6 = a4;
LAB_00099980:
                      (**(code **)(((unsigned char *)0x000012f4) + iVar9))
                                (param_1,a1,uVar18,&DAT_001dbd84,iVar6,uVar22,puVar10,&DAT_001fa5e8,(*(int *)((int)*(int *)((int)param_1 + 1004) + 0)),((*(undefined4 *)((char *)frame_ + 156))),&DAT_001dbd14,&DAT_001fa5e8,(*(int *)((int)*(int *)((int)param_1 + 1004) + 0)),uVar18,&DAT_001dbd14,&DAT_001fa5e8)
                      ;
                    }
                    FUN_000911a0(param_1,(*(undefined1 * *)((char *)frame_ + 436)));
                  }
                  else {
                    iVar6 = iVar5;
                    if ((bVar3) || (*(ushort *)(((unsigned char *)0x00002d48) + iVar17) != (*(uint *)((char *)frame_ + 404))))
                    goto LAB_000996c0;
LAB_0009966c:
                    (**(code **)(((unsigned char *)0x000012ec) + iVar9))
                              (param_1,a1,uVar18,((unsigned char *)0x00003870) + (int)(*(code * *)((char *)frame_ + 408)),iVar6,iVar8,
                               (*(code * *)((char *)frame_ + 464)) + 0x3800,&DAT_001fa5e8,iVar6,uVar18,(&DAT_001dbd34),&DAT_001fa5e8);
                  }
                }
              }
              if (param_9 == 0) {
                if (iStack00000024 != 0) {
                  uVar22 = *(undefined4 *)(iVar13 + 0x74);
                  uVar18 = *(undefined4 *)(iVar14 + 0x5b0);
                  uVar7 = *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0xc);
                  FUN_000912f0(param_1,*(undefined4 *)(iVar4 + 0x280),2,&(*(int *)((char *)frame_ + 8)),&(*(int *)((char *)frame_ + 20)));
                  (*(undefined4 *)((char *)frame_ + 52)) = 3;
                  (*(undefined4 *)((char *)frame_ + 48)) = 5;
                  (*(undefined4 *)((char *)frame_ + 40)) = 5;
                  (*(undefined4 *)((char *)frame_ + 44)) = 5;
                  iVarS39 = (*(int *)((char *)frame_ + 8));
                  iVarS40 = (*(int *)((char *)frame_ + 20));
                  iVarS41 = &(*(undefined4 *)((char *)frame_ + 40));
                  (**(code **)(((unsigned char *)0x000012ec) + iVar9))
                            (param_1,uVar7,uVar22,((unsigned char *)0x00003810) + (int)(*(code * *)((char *)frame_ + 416)),a4,uVar18,
                             ((unsigned char *)0x000038b0) + (int)(*(code * *)((char *)frame_ + 424)),&DAT_001fa5e8,iVarS39,iVarS40,iVarS41,&DAT_001fa5e8);
                }
              }
              else {
                uVar18 = *(undefined4 *)(iVar14 + 0x5b0);
                if (iStack00000024 == 0) {
                  uVar22 = **(undefined4 **)(param_1 + 0x3f0);
                  puVar19 = ((unsigned char *)0x00003870) + (int)(*(code * *)((char *)frame_ + 408));
                }
                else {
                  uVar18 = *(undefined4 *)(iVar13 + 0x74);
                  uVar22 = *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0xc);
                  puVar19 = ((unsigned char *)0x00003810) + (int)(*(code * *)((char *)frame_ + 416));
                }
                if (*(int *)(iVar15 + 0xc) == -1) {
                  FUN_000912f0(param_1,*(undefined4 *)(iVar4 + 0x280),2,&(*(int *)((char *)frame_ + 8)),&(*(int *)((char *)frame_ + 20)));
                }
                iVar6 = (*(int *)((char *)frame_ + 8));
                iVar8 = (*(int *)((char *)frame_ + 20));
                if ((param_9 == 1) ||
                   (iVar6 = iVar5, iVar8 = *(int *)(iVar15 + 0xc), *(int *)(iVar15 + 0xc) != -1)) {
                  iVarS79 = *(int *)((int)*(int *)((int)param_1 + 1004) + 0);
                  iVarS80 = *(int *)((int)puVar12 + 0);
                  iVarS81 = ((unsigned char *)&DAT_001dbdc0 + 44);
                  iVarS82 = *(int *)((int)iVar14 + 1456);
                  iVarS83 = &DAT_001dbd74;
                  (**(code **)(((unsigned char *)0x000012f4) + iVar9))
                            (param_1,uVar22,uVar18,puVar19,iVar6,iVar8,(*(code * *)((char *)frame_ + 464)) + 0x3800,
                             &DAT_001fa5e8,iVarS79,iVarS80,iVarS81,&DAT_001fa5e8,iVarS79,iVarS82,iVarS83,&DAT_001fa5e8);
                }
                else {
                  iVar6 = FUN_00090ca0(param_1,0,(*(undefined1 * *)((char *)frame_ + 436)));
                  if (iVar6 != 0) {
                    return 7;
                  }
                  if (iVar5 == (*(int *)((char *)frame_ + 8))) {
                    iVarS42 = *(int *)((int)*(int *)((int)param_1 + 1004) + 0);
                    iVarS43 = *(int *)((int)puVar12 + 0);
                    iVarS44 = ((unsigned char *)&DAT_001dbdc0 + 44);
                    (**(code **)(((unsigned char *)0x000012ec) + iVar9))
                              (param_1,a1,(*(undefined4 *)((char *)frame_ + 156)),puVar19,iVar5,(*(int *)((char *)frame_ + 20)),&DAT_001dbd14,
                               &DAT_001fa5e8,iVarS42,iVarS43,iVarS44,&DAT_001fa5e8);
                    uVar7 = *(undefined4 *)(iVar16 + 8);
                    puVar11 = ((unsigned char *)0x000038b0) + (int)(*(code * *)((char *)frame_ + 424));
                    iVar6 = iVar5;
                  }
                  else {
                    iVarS45 = (*(int *)((char *)frame_ + 8));
                    iVarS46 = (*(int *)((char *)frame_ + 20));
                    iVarS47 = &DAT_001dbd14;
                    (**(code **)(((unsigned char *)0x000012ec) + iVar9))
                              (param_1,a1,(*(undefined4 *)((char *)frame_ + 156)),puVar19,iVar5,*(undefined4 *)(iVar16 + 8),
                               ((unsigned char *)0x000038b0) + (int)(*(code * *)((char *)frame_ + 424)),&DAT_001fa5e8,iVarS45,iVarS46,iVarS47,&DAT_001fa5e8);
                    uVar7 = *puVar12;
                    puVar11 = ((unsigned char *)0x000038d8) + (int)(*(code * *)((char *)frame_ + 420));
                    iVar6 = a4;
                  }
                  iVarS84 = *(int *)((int)*(int *)((int)param_1 + 1004) + 0);
                  iVarS85 = (*(undefined4 *)((char *)frame_ + 156));
                  iVarS86 = *(int *)((int)iVar14 + 1456);
                  (**(code **)(((unsigned char *)0x000012f4) + iVar9))
                            (param_1,uVar22,uVar18,puVar19,iVar6,uVar7,puVar11,&DAT_001fa5e8,iVarS84,iVarS85,&DAT_001dbd14,&DAT_001fa5e8,iVarS84,iVarS86,&DAT_001dbd74,&DAT_001fa5e8);
                  FUN_000911a0(param_1,(*(undefined1 * *)((char *)frame_ + 436)));
                }
              }
              puVar24 = (*(undefined1 * *)((char *)frame_ + 456));
              puVar23 = puVar23 + 0x28;
              puVar12 = puVar12 + 10;
              iVar13 = iVar13 + 4;
              iVar14 = iVar14 + 0x28;
              iVar4 = iVar4 + 4;
              iVar15 = iVar15 + 4;
              (*(uint *)((char *)frame_ + 392)) = (*(uint *)((char *)frame_ + 392)) + 1;
              if ((byte)((unsigned char *)0x00002d48)[iVar17 + 4] < (*(uint *)((char *)frame_ + 392))) {
                uVar20 = 0;
                FUN_000911a0(param_1,(*(undefined1 * *)((char *)frame_ + 428)));
                FUN_000911a0(param_1,(*(undefined1 * *)((char *)frame_ + 448)));
                FUN_000911a0(param_1,(*(undefined1 * *)((char *)frame_ + 400)));
                do {
                  uVar20 = uVar20 + 1;
                  FUN_000911a0(param_1,puVar24);
                  puVar24 = puVar24 + 0x28;
                } while (uVar20 <= (byte)((unsigned char *)0x00002d48)[iVar17 + 4]);
                return 0;
              }
            } while( true );
          }
          puVar12 = puVar12 + 1;
          puVar10 = puVar10 + 10;
          pcVar21 = (code *)(((unsigned char *)0x00003880) + (int)(*(code * *)((char *)frame_ + 432)));
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
  unsigned int frame_[64] __attribute__((aligned(16)));
  
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
  iVar3 = FUN_00090ca0(param_1,2,((undefined1 *)((char *)frame_ + 128)));
  bVar1 = param_2 < 3;
  if (iVar3 != 0) {
    return 7;
  }
  if ((bVar1) && (iVar3 = FUN_00090ca0(param_1,1,((undefined1 *)((char *)frame_ + 88))), iVar3 != 0)) {
    return 7;
  }
  puVar4 = *(undefined4 **)(param_1 + 0x3ec);
  (*(undefined4 *)((char *)frame_ + 168)) = (*(undefined4 **)(param_1 + 0x3f0))[7];
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
              (param_1,a1,(*(undefined4 *)((char *)frame_ + 92)),&DAT_001dbd54,a4_00,*(undefined4 *)(param_1 + 0x4c),&DAT_001fa5f8,&DAT_001fa5e8,iVarS15,iVarS16,iVarS17,&DAT_001fa5e8);
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
      (*(undefined4 *)((char *)frame_ + 40)) = 1;
      (*(undefined4 *)((char *)frame_ + 44)) = 1;
      (*(undefined4 *)((char *)frame_ + 32)) = 4;
      (*(undefined4 *)((char *)frame_ + 36)) = 4;
      (*(int *)((char *)frame_ + 28)) = 5;
      (*(undefined4 *)((char *)frame_ + 24)) = *(undefined4 *)(param_1 + 0x54c);
      (*(int *)((char *)frame_ + 48)) = param_3;
      (*(int *)((char *)frame_ + 52)) = param_3;
      iVarS9 = ((undefined1 *)((char *)frame_ + 136));
      iVarS10 = (int)param_1 + 1316;
      iVarS18 = *(int *)((int)param_1 + 1296);
      iVarS19 = (int)param_1 + 1316;
      (**(code **)(((unsigned char *)0x000012ec) + iVar7))
                (param_1,a1,(*(undefined4 *)((char *)frame_ + 92)),&(*(undefined4 *)((char *)frame_ + 40)),uVar5,iVar3,&(*(undefined4 *)((char *)frame_ + 24)),&DAT_001fa5e8,uVar5,iVarS18,iVarS19,&DAT_001fa5e8);
      (*(undefined4 *)((char *)frame_ + 24)) = 1;
      (*(undefined4 *)((char *)frame_ + 32)) = 5;
      (*(undefined4 *)((char *)frame_ + 36)) = 4;
      (*(int *)((char *)frame_ + 28)) = param_3;
      iVarS1 = *(int *)((int)*(int *)((int)param_1 + 1004) + 0);
      iVarS2 = *(int *)((int)*(int *)((int)param_1 + 980) + 4836);
      iVarS20 = *(int *)((int)*(int *)((int)param_1 + 1004) + 0);
      iVarS21 = (*(undefined4 *)((char *)frame_ + 92));
      iVarS22 = &(*(undefined4 *)((char *)frame_ + 24));
      (**(code **)(((unsigned char *)0x000012e4) + iVar7))
                (param_1,a1,(*(undefined4 *)((char *)frame_ + 132)),((undefined1 *)((char *)frame_ + 136)),a4,uVar6,&DAT_001dbd74,&DAT_001fa5e8,iVarS20,iVarS21,iVarS22,&DAT_001fa5e8);
    }
    else {
      (*(undefined4 *)((char *)frame_ + 24)) = *(undefined4 *)(param_1 + 0x524);
      (*(undefined4 *)((char *)frame_ + 32)) = 5;
      (*(undefined4 *)((char *)frame_ + 36)) = 4;
      (*(int *)((char *)frame_ + 28)) = 4;
      iVarS3 = *(int *)((int)*(int *)((int)param_1 + 1004) + 0);
      iVarS4 = *(int *)((int)*(int *)((int)param_1 + 980) + 4836);
      iVarS5 = &(*(undefined4 *)((char *)frame_ + 24));
      iVarS23 = *(int *)((int)*(int *)((int)param_1 + 1004) + 0);
      iVarS24 = *(int *)((int)param_1 + 1296);
      iVarS25 = &(*(undefined4 *)((char *)frame_ + 24));
      (**(code **)(((unsigned char *)0x000012e4) + iVar7))
                (param_1,a1,(*(undefined4 *)((char *)frame_ + 132)),((undefined1 *)((char *)frame_ + 136)),a4,uVar6,&DAT_001dbd74,&DAT_001fa5e8,iVarS23,iVarS24,iVarS25,&DAT_001fa5e8);
    }
    (**(code **)(((unsigned char *)0x00001318) + iVar7))
              (param_1,a1,(*(undefined4 *)((char *)frame_ + 132)),((undefined1 *)((char *)frame_ + 136)),uVar5,(*(undefined4 *)((char *)frame_ + 132)),&(*(undefined4 *)((char *)frame_ + 152)),&DAT_001fa5e8);
  }
  uVar6 = (*(undefined4 *)((char *)frame_ + 132));
  switch(param_2) {
  case 0:
    bVar2 = false;
    (*(undefined4 *)((char *)frame_ + 56)) = DAT_001dbcf4;
    (*(undefined4 *)((char *)frame_ + 60)) = DAT_001dbcf8;
    (*(undefined4 *)((char *)frame_ + 12)) = (*(undefined4 *)((char *)frame_ + 156));
    (*(undefined4 *)((char *)frame_ + 64)) = DAT_001dbcfc;
    (*(undefined4 *)((char *)frame_ + 68)) = DAT_001dbd00;
    (*(undefined4 *)((char *)frame_ + 8)) = (*(undefined4 *)((char *)frame_ + 152));
    (*(undefined4 *)((char *)frame_ + 20)) = (*(undefined4 *)((char *)frame_ + 164));
    (*(undefined4 *)((char *)frame_ + 16)) = (*(undefined4 *)((char *)frame_ + 160));
    a4_00 = uVar5;
    uVar8 = (*(undefined4 *)((char *)frame_ + 92));
    break;
  case 1:
    uVar8 = *(undefined4 *)(param_1 + 0x4c);
    bVar2 = false;
    (*(undefined4 *)((char *)frame_ + 56)) = DAT_001fa5f8;
    (*(undefined4 *)((char *)frame_ + 60)) = DAT_001fa5fc;
    (*(undefined4 *)((char *)frame_ + 12)) = (*(undefined4 *)((char *)frame_ + 156));
    (*(undefined4 *)((char *)frame_ + 64)) = DAT_001fa600;
    (*(undefined4 *)((char *)frame_ + 68)) = DAT_001fa604;
    (*(undefined4 *)((char *)frame_ + 8)) = (*(undefined4 *)((char *)frame_ + 152));
    (*(undefined4 *)((char *)frame_ + 20)) = (*(undefined4 *)((char *)frame_ + 164));
    (*(undefined4 *)((char *)frame_ + 16)) = (*(undefined4 *)((char *)frame_ + 160));
    break;
  case 2:
    (*(undefined4 *)((char *)frame_ + 60)) = (*(undefined4 *)((char *)frame_ + 156));
    (*(undefined4 *)((char *)frame_ + 56)) = (*(undefined4 *)((char *)frame_ + 152));
    (*(undefined4 *)((char *)frame_ + 68)) = (*(undefined4 *)((char *)frame_ + 164));
    (*(undefined4 *)((char *)frame_ + 64)) = (*(undefined4 *)((char *)frame_ + 160));
    goto LAB_0009a3bc;
  case 3:
    (*(undefined4 *)((char *)frame_ + 132)) = *(undefined4 *)(param_1 + 0x4c);
    (*(undefined4 *)((char *)frame_ + 56)) = DAT_001fa5f8;
    (*(undefined4 *)((char *)frame_ + 68)) = DAT_001fa604;
    (*(undefined4 *)((char *)frame_ + 60)) = DAT_001fa5fc;
    (*(undefined4 *)((char *)frame_ + 64)) = DAT_001fa600;
    uVar5 = a4_00;
    goto LAB_0009a3bc;
  case 4:
    (*(undefined4 *)((char *)frame_ + 132)) = *(undefined4 *)(param_1 + 0x340);
    (*(undefined4 *)((char *)frame_ + 56)) = DAT_001dbdb4;
    (*(undefined4 *)((char *)frame_ + 68)) = DAT_001dbdc0;
    (*(undefined4 *)((char *)frame_ + 60)) = DAT_001dbdb8;
    (*(undefined4 *)((char *)frame_ + 64)) = DAT_001dbdbc;
    uVar5 = a4;
LAB_0009a3bc:
    bVar2 = true;
    (*(undefined4 *)((char *)frame_ + 8)) = DAT_001dbcf4;
    (*(undefined4 *)((char *)frame_ + 12)) = DAT_001dbcf8;
    (*(undefined4 *)((char *)frame_ + 16)) = DAT_001dbcfc;
    (*(undefined4 *)((char *)frame_ + 20)) = DAT_001dbd00;
    a4_00 = uVar5;
    uVar8 = (*(undefined4 *)((char *)frame_ + 132));
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
    FUN_000911a0(param_1,((undefined1 *)((char *)frame_ + 88)));
  }
  (*(undefined4 *)((char *)frame_ + 72)) = 0;
  (*(undefined4 *)((char *)frame_ + 80)) = 4;
  (*(undefined4 *)((char *)frame_ + 76)) = 4;
  (*(undefined4 *)((char *)frame_ + 84)) = 1;
  if (bVar2) {
    iVar3 = FUN_00090ca0(param_1,2,((undefined1 *)((char *)frame_ + 88)));
    if (iVar3 != 0) {
      return 7;
    }
    (**(code **)(((unsigned char *)0x000012e8) + iVar7))
              (param_1,a1,(*(undefined4 *)((char *)frame_ + 92)),((undefined1 *)((char *)frame_ + 96)),uVar5,uVar6,&(*(undefined4 *)((char *)frame_ + 8)),&DAT_001fa5e8);
    /* stack words, stock 0x9a468-0x9a4a8: r20 = rec[0], (*(undefined4 *)((char *)frame_ + 92)), &local_90 (= ((undefined1 *)((char *)frame_ + 96)) + 16), &DAT_001fa5e8, r17 = rec[2] (a4), *(param_1 + 0x340), &(*(undefined4 *)((char *)frame_ + 72)), &DAT_001fa5e8 */
    (**(code **)(((unsigned char *)0x000012fc) + iVar7))
              (param_1,(*(undefined4 *)((char *)frame_ + 168)),*(undefined4 *)(param_1 + 0x6c),&DAT_001dbd24,a4_00,uVar8,&(*(undefined4 *)((char *)frame_ + 56)),
               &DAT_001fa5e8,**(int **)(param_1 + 0x3ec),(*(undefined4 *)((char *)frame_ + 92)),((undefined1 *)((char *)frame_ + 96)) + 16,&DAT_001fa5e8,a4,*(int *)(param_1 + 0x340),&(*(undefined4 *)((char *)frame_ + 72)),&DAT_001fa5e8);
    FUN_000911a0(param_1,((undefined1 *)((char *)frame_ + 88)));
  }
  else {
    /* stack words, stock 0x9a4d8-0x9a520: uVar5, uVar6 (the stock's r27/r28), &(*(undefined4 *)((char *)frame_ + 8)), &DAT_001fa5e8, r17 = rec[2] (a4), *(param_1 + 0x340), &(*(undefined4 *)((char *)frame_ + 72)), &DAT_001fa5e8 */
    (**(code **)(((unsigned char *)0x000012fc) + iVar7))
              (param_1,(*(undefined4 *)((char *)frame_ + 168)),*(undefined4 *)(param_1 + 0x6c),&DAT_001dbd24,a4_00,uVar8,&(*(undefined4 *)((char *)frame_ + 56)),
               &DAT_001fa5e8,uVar5,uVar6,&(*(undefined4 *)((char *)frame_ + 8)),&DAT_001fa5e8,a4,*(int *)(param_1 + 0x340),&(*(undefined4 *)((char *)frame_ + 72)),&DAT_001fa5e8);
  }
  FUN_000911a0(param_1,((undefined1 *)((char *)frame_ + 128)));
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
  int iVarS1;
  int iVarS2;
  unsigned int frame_[28] __attribute__((aligned(16)));
  
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
      iVar3 = FUN_00090ca0(param_1,1,((undefined1 *)((char *)frame_ + 8)));
      if (iVar3 == 0) {
        (**(code **)(((unsigned char *)0x000012e4) + iVar8))
                  (param_1,uVar4,(*(undefined4 *)((char *)frame_ + 12)),&DAT_001dbd04,uVar5,iVar9,&DAT_001dbd74,&DAT_001fa5e8,uVar5,iVar9,&DAT_001dbd74,&DAT_001fa5e8);
        (**(code **)(((unsigned char *)0x00001318) + iVar8))
                  (param_1,uVar4,(*(undefined4 *)((char *)frame_ + 12)),&DAT_001dbd64,uVar5,(*(undefined4 *)((char *)frame_ + 12)),&DAT_001fa5f8,&DAT_001fa5e8);
        iVarS1 = ((unsigned char *)&DAT_001dbdc0 + 244);
        (**(code **)(((unsigned char *)0x000012e4) + iVar8))
                  (param_1,uVar6,iVar7,&DAT_001dbd04,uVar5,(*(undefined4 *)((char *)frame_ + 12)),&DAT_001dbec4,&DAT_001fa5e8,uVar5,(*(undefined4 *)((char *)frame_ + 12)),iVarS1,&DAT_001fa5e8);
        FUN_000911a0(param_1,((undefined1 *)((char *)frame_ + 8)));
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

/* FUN_0009a990 @ 0x9a990 (104 bytes) */
int FUN_0009a990(param_1, param_2)
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
  unsigned int frame_[52] __attribute__((aligned(16)));
  
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
  iVar1 = FUN_00090ca0(param_1,2,param_1 + 0x584);
  if (iVar1 == 0) {
    a2 = *(undefined4 *)(param_1 + 0x588);
    iVar1 = FUN_00090ca0(param_1,2,((undefined1 *)((char *)frame_ + 40)));
    if (iVar1 == 0) {
      iVar7 = *(int *)(param_1 + 0x3d4);
      iVar1 = *(int *)(*(int *)(iVar7 + 4) + 0x10);
      if ((*(short *)(((unsigned char *)0x00002e06) + iVar1) == -0x7bae) &&
         (*(short *)(((unsigned char *)0x00002e08) + iVar1) != -0x7aa4)) {
        if (*(short *)(((unsigned char *)0x00002e08) + iVar1) == -0x7aa5) {
          uVar5 = **(undefined4 **)(param_1 + 0x3f0);
          uVar6 = **(undefined4 **)(param_1 + 0x3ec);
          iVar1 = FUN_00090ca0(param_1,1,((undefined1 *)((char *)frame_ + 80)));
          if (iVar1 != 0) {
            return 7;
          }
          (**(code **)(((unsigned char *)0x000012e4) + iVar7))
                    (param_1,uVar5,(*(undefined4 *)((char *)frame_ + 84)),&DAT_001dbd04,uVar9,iVar3,&DAT_001dbd74,&DAT_001fa5e8,uVar9,iVar3,&DAT_001dbd74,&DAT_001fa5e8);
          (**(code **)(((unsigned char *)0x00001318) + iVar7))
                    (param_1,uVar5,(*(undefined4 *)((char *)frame_ + 84)),&DAT_001dbd64,uVar6,(*(undefined4 *)((char *)frame_ + 84)),&DAT_001fa5f8,&DAT_001fa5e8
                    );
          iVarS1 = ((unsigned char *)&DAT_001dbdc0 + 244);
          (**(code **)(((unsigned char *)0x000012e4) + iVar7))
                    (param_1,a1,(*(undefined4 *)((char *)frame_ + 44)),((undefined1 *)((char *)frame_ + 48)),uVar6,(*(undefined4 *)((char *)frame_ + 84)),&DAT_001dbec4,&DAT_001fa5e8,uVar6,(*(undefined4 *)((char *)frame_ + 84)),iVarS1,&DAT_001fa5e8);
          FUN_000911a0(param_1,((undefined1 *)((char *)frame_ + 80)));
        }
        else {
          (**(code **)(((unsigned char *)0x000012e8) + iVar7))
                    (param_1,a1,(*(undefined4 *)((char *)frame_ + 44)),((undefined1 *)((char *)frame_ + 48)),uVar9,iVar3,puVar2,&DAT_001dbd94);
        }
      }
      else {
        iVarS8 = &DAT_001dbd94;
        (**(code **)(((unsigned char *)0x00001304) + iVar7))
                  (param_1,a1,(*(undefined4 *)((char *)frame_ + 44)),((undefined1 *)((char *)frame_ + 48)),uVar9,iVar3,puVar2,&DAT_001fa5e8,uVar9,iVar3,puVar2,iVarS8);
      }
      uVar9 = **(undefined4 **)(param_1 + 0x3ec);
      (*(undefined4 *)((char *)frame_ + 36)) = 4;
      (*(undefined4 *)((char *)frame_ + 8)) = 4;
      (*(undefined4 *)((char *)frame_ + 16)) = 2;
      (*(undefined4 *)((char *)frame_ + 12)) = 1;
      (*(undefined4 *)((char *)frame_ + 20)) = 4;
      (*(undefined4 *)((char *)frame_ + 24)) = 4;
      (*(undefined4 *)((char *)frame_ + 28)) = 5;
      (*(undefined4 *)((char *)frame_ + 32)) = (*(undefined4 *)((char *)frame_ + 72));
      if (*(int *)(param_1 + 0x3d8) != 0) {
        iVarS2 = *(int *)((int)*(int *)((int)param_1 + 1004) + 0);
        iVarS3 = *(int *)((int)*(int *)((int)param_1 + 980) + 4836);
        iVarS4 = &(*(undefined4 *)((char *)frame_ + 24));
        iVarS10 = *(int *)((int)*(int *)((int)param_1 + 1004) + 0);
        iVarS11 = (*(undefined4 *)((char *)frame_ + 44));
        iVarS12 = &(*(undefined4 *)((char *)frame_ + 24));
        (**(code **)(((unsigned char *)0x000012e4) + iVar8))
                  (param_1,*(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x18),*(undefined4 *)(param_1 + 0x70),&DAT_001dbd04,a4,uVar4,&(*(undefined4 *)((char *)frame_ + 8)),&DAT_001fa5e8,iVarS10,iVarS11,iVarS12,&DAT_001fa5e8);
        FUN_000911a0(param_1,((undefined1 *)((char *)frame_ + 40)));
        return 0;
      }
      puVar2 = (undefined4 *)(param_1 + 0x58c);
      iVarS5 = *(int *)((int)*(int *)((int)param_1 + 1004) + 0);
      iVarS6 = *(int *)((int)*(int *)((int)param_1 + 980) + 4836);
      iVarS7 = &(*(undefined4 *)((char *)frame_ + 24));
      iVarS13 = *(int *)((int)*(int *)((int)param_1 + 1004) + 0);
      iVarS14 = (*(undefined4 *)((char *)frame_ + 44));
      iVarS15 = &(*(undefined4 *)((char *)frame_ + 24));
      (**(code **)(((unsigned char *)0x000012e4) + iVar8))(param_1,a1,a2,puVar2,a4,uVar4,&(*(undefined4 *)((char *)frame_ + 8)),&DAT_001fa5e8,iVarS13,iVarS14,iVarS15,&DAT_001fa5e8);
      FUN_000911a0(param_1,((undefined1 *)((char *)frame_ + 40)));
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
  int iVarS1;
  int iVarS2;
  int iVarS3;
  int iVarS4;
  unsigned int frame_[44] __attribute__((aligned(16)));
  
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
  iVar2 = FUN_00090ca0(param_1,2,param_1 + 0x584);
  if (iVar2 == 0) {
    uVar7 = *(undefined4 *)(param_1 + 0x588);
    iVar2 = FUN_00090ca0(param_1,2,((undefined1 *)((char *)frame_ + 8)));
    uVar1 = (*(undefined4 *)((char *)frame_ + 12));
    if (iVar2 == 0) {
      iVar8 = *(int *)(param_1 + 0x3d4);
      iVar2 = *(int *)(*(int *)(iVar8 + 4) + 0x10);
      if ((*(short *)(((unsigned char *)0x00002e06) + iVar2) == -0x7bae) &&
         (*(short *)(((unsigned char *)0x00002e08) + iVar2) != -0x7aa4)) {
        if (*(short *)(((unsigned char *)0x00002e08) + iVar2) == -0x7aa5) {
          uVar5 = **(undefined4 **)(param_1 + 0x3f0);
          uVar6 = **(undefined4 **)(param_1 + 0x3ec);
          iVar2 = FUN_00090ca0(param_1,1,((undefined1 *)((char *)frame_ + 48)));
          if (iVar2 != 0) {
            return 7;
          }
          (**(code **)(((unsigned char *)0x000012e4) + iVar8))
                    (param_1,uVar5,(*(undefined4 *)((char *)frame_ + 52)),&DAT_001dbd04,uVar9,iVar4,&DAT_001dbd74,&DAT_001fa5e8,uVar9,iVar4,&DAT_001dbd74,&DAT_001fa5e8);
          (**(code **)(((unsigned char *)0x00001318) + iVar8))
                    (param_1,uVar5,(*(undefined4 *)((char *)frame_ + 52)),&DAT_001dbd64,uVar6,(*(undefined4 *)((char *)frame_ + 52)),&DAT_001fa5f8,&DAT_001fa5e8
                    );
          iVarS1 = ((unsigned char *)&DAT_001dbdc0 + 244);
          (**(code **)(((unsigned char *)0x000012e4) + iVar8))
                    (param_1,a1,uVar1,((undefined1 *)((char *)frame_ + 16)),uVar6,(*(undefined4 *)((char *)frame_ + 52)),&DAT_001dbec4,&DAT_001fa5e8,uVar6,(*(undefined4 *)((char *)frame_ + 52)),iVarS1,&DAT_001fa5e8);
          FUN_000911a0(param_1,((undefined1 *)((char *)frame_ + 48)));
        }
        else {
          (**(code **)(((unsigned char *)0x000012e8) + iVar8))
                    (param_1,a1,(*(undefined4 *)((char *)frame_ + 12)),((undefined1 *)((char *)frame_ + 16)),uVar9,iVar4,puVar3,&DAT_001dbd94);
        }
      }
      else {
        iVarS4 = &DAT_001dbd94;
        (**(code **)(((unsigned char *)0x00001304) + iVar8))
                  (param_1,a1,(*(undefined4 *)((char *)frame_ + 12)),((undefined1 *)((char *)frame_ + 16)),uVar9,iVar4,puVar3,&DAT_001fa5e8,uVar9,iVar4,puVar3,iVarS4);
      }
      uVar9 = **(undefined4 **)(param_1 + 0x3ec);
      iVarS2 = *(int *)((int)*(int *)((int)param_1 + 1004) + 0);
      iVarS3 = ((undefined1 *)((char *)frame_ + 32));
      (**(code **)(((unsigned char *)0x000012ec) + iVar10))
                (param_1,a1,(*(undefined4 *)((char *)frame_ + 12)),((undefined1 *)((char *)frame_ + 16)),a4,a5,&DAT_001dbcf4,&DAT_001fa5e8,iVarS2,(*(undefined4 *)((char *)frame_ + 12)),iVarS3,&DAT_001fa5e8);
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
                (param_1,a1,uVar7,puVar3,uVar9,(*(undefined4 *)((char *)frame_ + 12)),((undefined1 *)((char *)frame_ + 32)),&DAT_001fa5e8);
      FUN_000911a0(param_1,((undefined1 *)((char *)frame_ + 8)));
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
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  undefined *puVar13;
  undefined4 uVar14;
  int iVarS1;
  int iVarS2;
  int iVarS3;
  int iVarS4;
  int iVarS5;
  unsigned int frame_[36] __attribute__((aligned(16)));
  
  uVar3 = 1;
  if (param_1 != 0) {
    iVar11 = *(int *)(param_1 + 0x3d4);
    (*(undefined4 * *)((char *)frame_ + 48)) = &(*(undefined4 *)((char *)frame_ + 16));
    uVar5 = 0;
    uVar3 = **(undefined4 **)(param_1 + 0x3ec);
    iVar6 = *(int *)(*(int *)(iVar11 + 4) + 0x10);
    (*(undefined * *)((char *)frame_ + 40)) = &DAT_001db440;
    (*(undefined * *)((char *)frame_ + 44)) = &DAT_001db440;
    (*(undefined * *)((char *)frame_ + 52)) = &DAT_001db440;
    iVar8 = param_1;
    iVar9 = iVar11;
    iVar10 = param_1;
    do {
      uVar12 = *(undefined4 *)(iVar10 + 0x5b0);
      uVar7 = *(undefined4 *)(iVar10 + 0x600);
      uVar14 = *(undefined4 *)(iVar8 + 0x74);
      FUN_000912f0(param_1,*(undefined4 *)(iVar9 + 0x280),2,&(*(undefined4 *)((char *)frame_ + 8)),&(*(undefined4 *)((char *)frame_ + 12)));
      (*(undefined4 *)((char *)frame_ + 16)) = 5;
      (*(undefined4 *)((char *)frame_ + 20)) = 5;
      (*(undefined4 *)((char *)frame_ + 24)) = 5;
      (*(int *)((char *)frame_ + 28)) = 3;
      if (param_2 == 0) {
        iVarS1 = (*(undefined4 *)((char *)frame_ + 8));
        iVarS2 = (*(undefined4 *)((char *)frame_ + 12));
        iVarS3 = (*(undefined4 * *)((char *)frame_ + 48));
        (**(code **)(((unsigned char *)0x000012ec) + iVar11))
                  (param_1,*(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0xc),uVar14,(*(undefined * *)((char *)frame_ + 40)) + 0x8e4,
                   uVar3,uVar12,(*(undefined * *)((char *)frame_ + 44)) + 0x984,&DAT_001fa5e8,iVarS1,iVarS2,iVarS3,&DAT_001fa5e8);
      }
      if ((((*(short *)(((unsigned char *)0x00002d48) + iVar6) == -0x7e06) && (*(char *)(iVar11 + 0x12d) != '\0')
           ) || (((*(uint *)(iVar11 + 0x44) & 0x1000000) != 0 && (*(char *)(iVar11 + 0x121) == '\0')
                 ))) || ((*(uint *)(iVar11 + 0x44) & 0xa10000) != 0)) {
        iVar4 = *(int *)(iVar8 + 0x7c);
        uVar12 = *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x10);
        FUN_000912f0(param_1,*(undefined4 *)(iVar9 + 0x288),3,&(*(undefined4 *)((char *)frame_ + 8)),&(*(undefined4 *)((char *)frame_ + 12)));
        if (((*(short *)(((unsigned char *)0x00002d48) + iVar6) != -0x7e06) ||
            (*(char *)(iVar11 + 0x12d) == '\0')) || (param_2 == 0)) {
          puVar13 = (*(undefined * *)((char *)frame_ + 52)) + 0x964;
          uVar7 = (*(undefined4 *)((char *)frame_ + 12));
          uVar14 = (*(undefined4 *)((char *)frame_ + 8));
        }
        else {
          puVar13 = (*(undefined * *)((char *)frame_ + 44)) + 0x984;
          uVar14 = uVar3;
        }
        /* stack words 9/10 of the last call: the stock (0x9b6fc/0x9b708) passes ((*(undefined4 *)((char *)frame_ + 8)), (*(undefined4 *)((char *)frame_ + 12))) unless the two arms below replace them */
        iVarS4 = (*(undefined4 *)((char *)frame_ + 8));
        iVarS5 = (*(undefined4 *)((char *)frame_ + 12));
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
            (*(int *)((char *)frame_ + 28)) = *(int *)(param_1 + 0x5a8);
            iVarS4 = uVar3;
            iVarS5 = *(int *)(param_1 + 0x588);
          }
          else {
            iVarS4 = (*(int **)(param_1 + 0x3ec))[1];
            iVarS5 = *(int *)(param_1 + 0x50);
            (*(int *)((char *)frame_ + 28)) = *(int *)(param_1 + 0x54);
            if ((*(int *)((char *)frame_ + 28)) != 1) {
              if ((*(int *)((char *)frame_ + 28)) == 0) {
                (*(int *)((char *)frame_ + 28)) = 0;
              }
              else if (((*(int *)((char *)frame_ + 28)) != 2) && ((*(int *)((char *)frame_ + 28)) != 3)) {
                (*(int *)((char *)frame_ + 28)) = 3;
              }
            }
          }
        }
        (**(code **)(((unsigned char *)0x000012ec) + iVar11))
                  (param_1,uVar12,iVar4,(*(undefined * *)((char *)frame_ + 40)) + 0x8e4,uVar14,uVar7,puVar13,&DAT_001fa5e8,iVarS4,iVarS5,(*(undefined4 * *)((char *)frame_ + 48)),&DAT_001fa5e8);
      }
      uVar5 = uVar5 + 1;
      iVar10 = iVar10 + 0x28;
      iVar8 = iVar8 + 4;
      iVar9 = iVar9 + 4;
    } while (uVar5 <= (byte)((unsigned char *)0x00002d48)[iVar6 + 4]);
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
  int iVarS1;
  int iVarS2;
  unsigned int frame_[32] __attribute__((aligned(16)));
  
  if (param_1 == 0) {
    return 1;
  }
  if (param_2 < 8) {
    iVar7 = *(int *)(param_2 * 4 + param_1 + 0x84);
    if (iVar7 != -1) {
      iVar8 = *(int *)(param_1 + 0x3d4);
      uVar6 = *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x14);
      (*(undefined4 *)((char *)frame_ + 12)) = DAT_001dbda8;
      (*(uint *)((char *)frame_ + 8)) = DAT_001dbda4;
      (*(undefined4 *)((char *)frame_ + 16)) = DAT_001dbdac;
      (*(undefined4 *)((char *)frame_ + 20)) = DAT_001dbdb0;
      if (*(short *)(((unsigned char *)0x00002e06) + *(int *)(*(int *)(iVar8 + 4) + 0x10)) == -0x7bae) {
        iVar5 = *(int *)(param_1 + 0x3f8);
        if (iVar5 != -1) {
LAB_0009b914:
          uVar4 = **(undefined4 **)(param_1 + 0x3ec);
          (*(uint *)((char *)frame_ + 8)) = 2;
          iVar1 = *(int *)(*(int *)(iVar8 + 4) + 0x10);
          if (*(short *)(((unsigned char *)0x00002e06) + iVar1) != -0x7bae) {
            iVarS2 = &DAT_001dbd94;
            (**(code **)(((unsigned char *)0x00001304) + iVar8))
                      (param_1,uVar6,iVar7,&DAT_001dbd24,uVar4,iVar5,&(*(uint *)((char *)frame_ + 8)),&DAT_001fa5e8,uVar4,iVar5,&(*(uint *)((char *)frame_ + 8)),iVarS2);
            return 0;
          }
          if (*(short *)(((unsigned char *)0x00002e08) + iVar1) == -0x7aa5) {
            uVar3 = **(undefined4 **)(param_1 + 0x3ec);
            uVar2 = **(undefined4 **)(param_1 + 0x3f0);
            iVar1 = FUN_00090ca0(param_1,1,((undefined1 *)((char *)frame_ + 24)));
            if (iVar1 != 0) {
              return 7;
            }
            (**(code **)(((unsigned char *)0x000012e4) + iVar8))
                      (param_1,uVar2,(*(undefined4 *)((char *)frame_ + 28)),&DAT_001dbd04,uVar4,iVar5,&DAT_001dbd74,&DAT_001fa5e8,uVar4,iVar5,&DAT_001dbd74,&DAT_001fa5e8)
            ;
            (**(code **)(((unsigned char *)0x00001318) + iVar8))
                      (param_1,uVar2,(*(undefined4 *)((char *)frame_ + 28)),&DAT_001dbd64,uVar3,(*(undefined4 *)((char *)frame_ + 28)),&DAT_001fa5f8,
                       &DAT_001fa5e8);
            iVarS1 = ((unsigned char *)&DAT_001dbdc0 + 244);
            (**(code **)(((unsigned char *)0x000012e4) + iVar8))
                      (param_1,uVar6,iVar7,&DAT_001dbd24,uVar3,(*(undefined4 *)((char *)frame_ + 28)),&DAT_001dbec4,&DAT_001fa5e8,uVar3,(*(undefined4 *)((char *)frame_ + 28)),iVarS1,&DAT_001fa5e8)
            ;
            FUN_000911a0(param_1,((undefined1 *)((char *)frame_ + 24)));
            return 0;
          }
          (**(code **)(((unsigned char *)0x000012e8) + iVar8))
                    (param_1,uVar6,iVar7,&DAT_001dbd24,uVar4,iVar5,&(*(uint *)((char *)frame_ + 8)),&DAT_001dbd94);
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
        (*(uint *)((char *)frame_ + 8)) = *(uint *)(param_1 + 0x54);
        if ((*(uint *)((char *)frame_ + 8)) < 4) {
          if ((*(uint *)((char *)frame_ + 8)) != 1) {
            if ((*(uint *)((char *)frame_ + 8)) == 0) {
              (*(uint *)((char *)frame_ + 8)) = 0;
            }
            else if (((*(uint *)((char *)frame_ + 8)) != 2) && ((*(uint *)((char *)frame_ + 8)) != 3)) {
              (*(uint *)((char *)frame_ + 8)) = 4;
            }
          }
          (**(code **)(((unsigned char *)0x000012e8) + iVar8))
                    (param_1,uVar6,iVar7,&DAT_001dbd24,
                     *(undefined4 *)(*(int *)(param_1 + 0x3ec) + 4),*(int *)(param_1 + 0x50),
                     &(*(uint *)((char *)frame_ + 8)),&DAT_001fa5e8);
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

/* FUN_0009c700 @ 0x9c700 (248 bytes) */
int FUN_0009c700(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  undefined4 a1;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  uint uVar3;
  int a0;
  
  uVar3 = 0;
  if (*(int *)(((unsigned char *)0x0000111c) + param_1) != 0) {
    do {
      iVar2 = *(int *)(((unsigned char *)0x00001118) + param_1);
      iVar1 = uVar3 * 4;
      a0 = *(int *)(iVar1 + iVar2);
      while (a0 != 0) {
        *(undefined4 *)(iVar1 + iVar2) = *(undefined4 *)(a0 + 0x5c);
        ((int (*)())FUN_0009a990)(param_1,*(undefined4 *)(a0 + 0x54));
        if (*(int *)(a0 + 0x4c) != 0) {
          (**(code **)(param_1 + 0x18))(*(int *)(a0 + 0x4c));
        }
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(a0 + 0x50));
        (**(code **)(param_1 + 0x18))(a0,a1,in_r5,in_r6,in_r7,in_r8,*(code **)(param_1 + 0x18));
        iVar2 = *(int *)(((unsigned char *)0x00001118) + param_1);
        a0 = *(int *)(iVar1 + iVar2);
      }
      uVar3 = uVar3 + 1;
      *(undefined4 *)(iVar1 + iVar2) = 0;
    } while (uVar3 < *(uint *)(((unsigned char *)0x0000111c) + param_1));
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
    ((int (*)())FUN_0009c700)(param_1);
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
  unsigned int frame_[16] __attribute__((aligned(16)));
  
  iVar4 = *(int *)(param_2 + 0x54);
  uVar1 = (**(code **)(param_1 + 0xc))(param_4 * *(int *)(iVar4 + 0x3cc),param_2,param_3,param_4);
  *(undefined4 *)(param_3 + 4) = *(undefined4 *)(iVar4 + 0x3c8);
  uVar3 = *(undefined4 *)(iVar4 + 0x3cc);
  *(int **)(param_3 + 0x1c) = &(*(int *)((char *)frame_ + 8));
  *(undefined4 **)(param_3 + 0x28) = &(*(undefined4 *)((char *)frame_ + 12));
  *(undefined4 *)(param_3 + 0x18) = uVar1;
  *(undefined4 **)(param_3 + 0x2c) = &(*(undefined4 *)((char *)frame_ + 16));
  *(undefined4 *)(param_3 + 8) = uVar3;
  *(undefined4 **)(param_3 + 0x30) = ((undefined4 *)((char *)frame_ + 20));
  iVar2 = FUN_0007c760(param_3);
  if (iVar2 == 0) {
    _memcpy(*(undefined4 *)(iVar4 + 0x3c8),uVar1,param_4 * (*(int *)((char *)frame_ + 8)));
    *(int *)(iVar4 + 0x3cc) = (*(int *)((char *)frame_ + 8));
    *(undefined4 *)(param_2 + 0x38) = (*(undefined4 *)((char *)frame_ + 16));
    *(undefined4 *)(param_2 + 0x44) = ((undefined4 *)((char *)frame_ + 20))[0];
    *(undefined4 *)(param_2 + 0x34) = (*(undefined4 *)((char *)frame_ + 12));
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

/* FUN_0009d410 @ 0x9d410 (5944 bytes) */
int FUN_0009d410(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  int *param_4;
  int *param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  byte bVar1;
  short sVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  undefined4 uVar10;
  int *piVar11;
  float fVar12;
  int *piVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int unaff_r17;
  int unaff_r18;
  float unaff_r19;
  undefined4 uVar18;
  int iVar19;
  int iVar20;
  int *piVar21;
  uint *puVar22;
  int iVar23;
  ushort *puVar24;
  int iVar25;
  unsigned int frame_[32] __attribute__((aligned(16)));
  
  iVar19 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if ((*(uint *)(param_1 + 0x1874) & 0xc0000000) != 0x40000000) {
    uVar6 = *(uint *)(param_1 + 0x44);
    goto LAB_0009d494;
  }
  if ((*(uint *)(param_1 + 0x8c) & 0x800000) != 0) {
    uVar6 = *(uint *)(param_1 + 0x44);
    goto LAB_0009d4b8;
  }
  uVar6 = *(uint *)(param_1 + 0x44);
  if ((uVar6 & 0x20000) == 0) {
LAB_0009d494:
    uVar10 = 0;
  }
  else {
    if ((uVar6 & 0x2000) == 0) {
      if (((unsigned char *)0x00001135)[param_1] != '\0') goto LAB_0009d4b8;
      goto LAB_0009d494;
    }
    if (((unsigned char *)0x000011d3)[param_1] == '\0') goto LAB_0009d494;
LAB_0009d4b8:
    uVar10 = 1;
    if ((*(uint *)(((unsigned char *)0x000013c0) + param_1) & 1) == 0) goto LAB_0009d494;
  }
  if (((uVar6 & 0x400) == 0) || (uVar18 = 1, (*(uint *)(((unsigned char *)0x000013c0) + param_1) & 2) == 0)) {
    uVar18 = 0;
  }
  uVar6 = (uint)(byte)((unsigned char *)0x000011d2)[param_1];
  iVar7 = FUN_00092bf0(param_1,param_2,uVar10);
  (**(code **)(((unsigned char *)0x000012c0) + param_1))(param_1,iVar7,&(*(float *)((char *)frame_ + 8)),param_3);
  if (*(int *)(param_1 + 0x13c) == 1) {
    _memcpy(iVar7,param_1 + 0x19c,0x68);
  }
  else {
    _memcpy(iVar7,param_1 + 0x204,0x68);
  }
  piVar21 = (int *)(iVar7 + 0xa4);
  iVar20 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  _memset(piVar21,0xffffffff,0x324);
  param_5[2] = 0;
  if (((unsigned char *)0x00004301)[iVar20] == '\0') {
    (*(float *)((char *)frame_ + 8)) = GH_U2F((unsigned int)((iVar20 + 0x2460)));
    iVar8 = 0;
    if ((((((((uint *)((char *)frame_ + 12))[0] != 0 || ((uint *)((char *)frame_ + 12))[1] != 0) || ((uint *)((char *)frame_ + 12))[2] != 0) ||
          FLOAT_001aa0e8 != (*(float *)((char *)frame_ + 8))) ||
         (((((uint *)((char *)frame_ + 12))[3] != 0 || (*(int *)((char *)frame_ + 32)) != 0) || (*(int *)((char *)frame_ + 36)) != 0) || FLOAT_001aa0e8 != (*(float *)((char *)frame_ + 28)))) ||
        ((((*(int *)((char *)frame_ + 40)) != 0 || (*(int *)((char *)frame_ + 44)) != 0) || (*(int *)((char *)frame_ + 52)) != 0) || FLOAT_001aa0e8 != (*(float *)((char *)frame_ + 48)))) ||
        ((((*(int *)((char *)frame_ + 56)) != 0 || unaff_r17 != 0) || unaff_r18 != 0) || FLOAT_001aa0e8 != unaff_r19)) {
      *(undefined4 *)(iVar7 + 0xa4) = 0;
      iVar8 = 4;
      *(undefined4 *)(param_5[2] * 4 + *param_5) = 0;
      *(undefined4 *)(param_5[2] * 4 + param_5[1]) = 0;
      param_5[2] = param_5[2] + 1;
    }
    uVar4 = *(uint *)(param_1 + 0x8c);
    if ((uVar4 & 0x80000) != 0) {
      *(int *)(iVar7 + 0xb4) = iVar8;
      iVar16 = iVar8 + 4;
      iVar8 = iVar8 + 8;
      *(undefined4 *)(param_5[2] * 4 + *param_5) = 1;
      *(undefined4 *)(param_5[2] * 4 + param_5[1]) = 0;
      param_5[2] = param_5[2] + 1;
      *(int *)(iVar7 + 0xc4) = iVar16;
      *(undefined4 *)(param_5[2] * 4 + *param_5) = 2;
      *(undefined4 *)(param_5[2] * 4 + param_5[1]) = 0;
      param_5[2] = param_5[2] + 1;
      uVar4 = *(uint *)(param_1 + 0x8c);
    }
  }
  else {
    bVar1 = ((unsigned char *)0x00004300)[iVar20];
    iVar8 = 0;
    iVar16 = 4;
    uVar4 = 0;
    fVar12 = GH_U2F((unsigned int)((iVar20 + 0x1960)));
    piVar11 = piVar21;
    do {
      if (((1 << (bVar1 & 0x3f)) - 1U & 1 << (uVar4 & 0x3f)) != 0) {
        if ((((((((uint *)((char *)frame_ + 12))[0] != 0 || ((uint *)((char *)frame_ + 12))[1] != 0) || ((uint *)((char *)frame_ + 12))[2] != 0) ||
              FLOAT_001aa0e8 != fVar12) ||
             (((((uint *)((char *)frame_ + 12))[3] != 0 || (*(int *)((char *)frame_ + 32)) != 0) || (*(int *)((char *)frame_ + 36)) != 0) || FLOAT_001aa0e8 != (*(float *)((char *)frame_ + 28))))
            || ((((*(int *)((char *)frame_ + 40)) != 0 || (*(int *)((char *)frame_ + 44)) != 0) || (*(int *)((char *)frame_ + 52)) != 0) || FLOAT_001aa0e8 != (*(float *)((char *)frame_ + 48))))
            || ((((*(int *)((char *)frame_ + 56)) != 0 || unaff_r17 != 0) || unaff_r18 != 0) || FLOAT_001aa0e8 != unaff_r19
               )) {
          *piVar11 = iVar8;
          iVar8 = iVar8 + 4;
          *(undefined4 *)(param_5[2] * 4 + *param_5) = 0;
          *(uint *)(param_5[2] * 4 + param_5[1]) = uVar4;
          param_5[2] = param_5[2] + 1;
        }
        (*(float *)((char *)frame_ + 8)) = fVar12;
        if ((*(uint *)(param_1 + 0x8c) & 0x80000) != 0) {
          piVar11[4] = iVar8;
          iVar15 = iVar8 + 4;
          iVar8 = iVar8 + 8;
          *(undefined4 *)(param_5[2] * 4 + *param_5) = 1;
          *(uint *)(param_5[2] * 4 + param_5[1]) = uVar4;
          param_5[2] = param_5[2] + 1;
          piVar11[8] = iVar15;
          *(undefined4 *)(param_5[2] * 4 + *param_5) = 2;
          *(uint *)(param_5[2] * 4 + param_5[1]) = uVar4;
          param_5[2] = param_5[2] + 1;
        }
      }
      uVar4 = uVar4 + 1;
      fVar12 = GH_U2F((unsigned int)(((int)GH_F2U(fVar12) + 0x40)));
      piVar11 = piVar11 + 1;
      iVar16 = iVar16 + -1;
    } while (iVar16 != 0);
    *(int *)(iVar7 + 0xd4) = iVar8;
    iVar8 = iVar8 + 4;
    *(undefined4 *)(param_5[2] * 4 + *param_5) = 3;
    *(undefined4 *)(param_5[2] * 4 + param_5[1]) = 0;
    param_5[2] = param_5[2] + 1;
    uVar4 = *(uint *)(param_1 + 0x8c);
  }
  if ((uVar4 & 0x800000) != 0) {
    uVar4 = 0xff;
    if ((*(uint *)(param_1 + 0x44) & 0x20000) != 0) {
      if ((*(uint *)(param_1 + 0x44) & 0x2000) == 0) {
        uVar4 = (uint)(byte)((unsigned char *)0x00001135)[param_1];
      }
      else {
        uVar4 = (uint)(byte)((unsigned char *)0x000011d3)[param_1];
      }
    }
    iVar25 = 8;
    uVar9 = 0;
    iVar23 = 0;
    iVar15 = param_1 + 0x450;
    piVar11 = piVar21;
    piVar13 = piVar21;
    iVar16 = param_1;
    do {
      if ((uVar4 & 1 << (uVar9 & 0x3f)) != 0) {
        uVar5 = *(uint *)(iVar16 + 0x48);
        if (((uVar5 & 0x20) != 0) && ((ushort)(*(short *)(iVar15 + 0x3c) + 0xdc00U) < 2)) {
          piVar11[0xa9] = iVar8;
          iVar8 = iVar8 + 1;
          *(undefined4 *)(param_5[2] * 4 + *param_5) = 0x1a;
          *(int *)(param_5[2] * 4 + param_5[1]) = iVar23;
          param_5[2] = param_5[2] + 1;
        }
        if (((uVar5 & 0x40) != 0) && ((ushort)(*(short *)(iVar15 + 0x60) + 0xdc00U) < 2)) {
          piVar11[0xaa] = iVar8;
          iVar8 = iVar8 + 1;
          *(undefined4 *)(param_5[2] * 4 + *param_5) = 0x1a;
          *(int *)(param_5[2] * 4 + param_5[1]) = iVar23 + 1;
          param_5[2] = param_5[2] + 1;
        }
        if (((uVar5 & 0x80) != 0) && ((ushort)(*(short *)(iVar15 + 0x84) + 0xdc00U) < 2)) {
          piVar11[0xab] = iVar8;
          iVar8 = iVar8 + 1;
          *(undefined4 *)(param_5[2] * 4 + *param_5) = 0x1a;
          *(int *)(param_5[2] * 4 + param_5[1]) = iVar23 + 2;
          param_5[2] = param_5[2] + 1;
        }
        if (((uVar5 & 0x100) != 0) && ((ushort)(*(short *)(iVar15 + 0xa8) + 0xdc00U) < 2)) {
          piVar11[0xac] = iVar8;
          iVar8 = iVar8 + 1;
          *(undefined4 *)(param_5[2] * 4 + *param_5) = 0x1a;
          *(int *)(param_5[2] * 4 + param_5[1]) = iVar23 + 3;
          param_5[2] = param_5[2] + 1;
        }
        if (*(int *)(iVar16 + 0x150) != 0) {
          piVar13[0xd] = iVar8;
          iVar8 = iVar8 + 4;
          *(undefined4 *)(param_5[2] * 4 + *param_5) = 4;
          *(uint *)(param_5[2] * 4 + param_5[1]) = uVar9;
          param_5[2] = param_5[2] + 1;
        }
      }
      uVar9 = uVar9 + 1;
      iVar15 = iVar15 + 0xcc;
      iVar23 = iVar23 + 4;
      piVar13 = piVar13 + 1;
      iVar16 = iVar16 + 4;
      piVar11 = piVar11 + 4;
      iVar25 = iVar25 + -1;
    } while (iVar25 != 0);
  }
  fVar12 = FLOAT_001aa0d4;
  uVar4 = *(uint *)(param_1 + 0x44);
  if ((int)uVar4 < 0) {
    uVar4 = *(uint *)(param_1 + 0x88);
    if (uVar4 == 0) {
      bVar3 = false;
      iVar16 = iVar8;
    }
    else {
      iVar25 = 0;
      bVar3 = false;
      iVar15 = iVar20;
      iVar23 = param_1;
      do {
        puVar22 = (uint *)(iVar25 * 4 + param_1 + 0x3a8);
        iVar16 = iVar8;
        if (((uVar4 & 1) != 0) &&
           (uVar9 = *(uint *)(param_1 + 0x3a8 + iVar25 * 4), (uVar9 & 0xfc000000) != 0)) {
          uVar9 = uVar9 & 0xc0000000;
          if (uVar9 == 0x80000000) {
            piVar21[0x16] = iVar8;
            iVar8 = iVar8 + 1;
            *(undefined4 *)(param_5[2] * 4 + *param_5) = 5;
            *(int *)(param_5[2] * 4 + param_5[1]) = iVar25;
            param_5[2] = param_5[2] + 1;
          }
          else if (uVar9 == 0xc0000000) {
            bVar3 = true;
          }
          uVar9 = *puVar22;
          if ((uVar9 & 0x30000000) == 0x20000000) {
            if (*(int *)(param_1 + 0x13c) == 1) {
              if (7 < *(uint *)(param_1 + 0x280)) {
                piVar21[0x18] = iVar8;
                iVar8 = iVar8 + 1;
                *(undefined4 *)(param_5[2] * 4 + *param_5) = 0x1c;
                *(int *)(param_5[2] * 4 + param_5[1]) = iVar25 << 1;
                param_5[2] = param_5[2] + 1;
              }
              if ((((unsigned char *)0x00002d48)[iVar20 + 4] != '\0') && (7 < *(uint *)(param_1 + 0x284))) {
                piVar21[0x19] = iVar8;
                iVar8 = iVar8 + 1;
                *(undefined4 *)(param_5[2] * 4 + *param_5) = 0x1c;
                *(uint *)(param_5[2] * 4 + param_5[1]) = iVar25 << 1 | 1;
                param_5[2] = param_5[2] + 1;
              }
            }
            if ((piVar21[0x18] == -1) ||
               ((((unsigned char *)0x00002d48)[iVar20 + 4] != '\0' && (piVar21[0x19] == -1)))) {
              piVar21[0x17] = iVar8;
              iVar8 = iVar8 + 1;
              *(undefined4 *)(param_5[2] * 4 + *param_5) = 6;
              *(int *)(param_5[2] * 4 + param_5[1]) = iVar25;
              param_5[2] = param_5[2] + 1;
              uVar9 = *puVar22;
            }
            else {
              uVar9 = *puVar22;
            }
          }
          if ((uVar9 & 0xc000000) == 0x8000000) {
            if (*(int *)(param_1 + 0x13c) == 1) {
              if (7 < *(uint *)(param_1 + 0x288)) {
                piVar21[0x1b] = iVar8;
                iVar8 = iVar8 + 1;
                *(undefined4 *)(param_5[2] * 4 + *param_5) = 0x1d;
                *(int *)(param_5[2] * 4 + param_5[1]) = iVar25 << 1;
                param_5[2] = param_5[2] + 1;
              }
              if ((((unsigned char *)0x00002d48)[iVar20 + 4] != '\0') && (7 < *(uint *)(param_1 + 0x28c))) {
                piVar21[0x1c] = iVar8;
                iVar8 = iVar8 + 1;
                *(undefined4 *)(param_5[2] * 4 + *param_5) = 0x1d;
                *(uint *)(param_5[2] * 4 + param_5[1]) = iVar25 << 1 | 1;
                param_5[2] = param_5[2] + 1;
              }
            }
            if ((piVar21[0x1b] == -1) ||
               ((((unsigned char *)0x00002d48)[iVar20 + 4] != '\0' && (piVar21[0x1c] == -1)))) {
              piVar21[0x1a] = iVar8;
              iVar8 = iVar8 + 1;
              *(undefined4 *)(param_5[2] * 4 + *param_5) = 7;
              *(int *)(param_5[2] * 4 + param_5[1]) = iVar25;
              param_5[2] = param_5[2] + 1;
            }
          }
          piVar21[0x1e] = iVar8;
          iVar14 = iVar8 + 2;
          *(undefined4 *)(param_5[2] * 4 + *param_5) = 8;
          *(int *)(param_5[2] * 4 + param_5[1]) = iVar25;
          param_5[2] = param_5[2] + 1;
          piVar21[0x1f] = iVar8 + 1;
          *(undefined4 *)(param_5[2] * 4 + *param_5) = 9;
          *(int *)(param_5[2] * 4 + param_5[1]) = iVar25;
          param_5[2] = param_5[2] + 1;
          iVar16 = iVar14;
          if (*(float *)(iVar15 + 0x24fc) != fVar12) {
            if ((*puVar22 & 0x2000000) != 0) {
              if ((*puVar22 & 0x1000000) == 0) {
                piVar21[0x20] = iVar14;
                uVar10 = 10;
                iVar16 = param_5[2];
                iVar17 = *param_5;
              }
              else {
                piVar21[0x22] = iVar14;
                uVar10 = 0xc;
                iVar16 = param_5[2];
                iVar17 = *param_5;
              }
              iVar14 = iVar8 + 3;
              *(undefined4 *)(iVar16 * 4 + iVar17) = uVar10;
              *(int *)(param_5[2] * 4 + param_5[1]) = iVar25;
              param_5[2] = param_5[2] + 1;
            }
            iVar16 = iVar14;
            if (((unsigned char *)0x0000150c)[iVar23] != '\0') {
              piVar21[0x21] = iVar14;
              iVar16 = iVar14 + 1;
              *(undefined4 *)(param_5[2] * 4 + *param_5) = 0xb;
              *(int *)(param_5[2] * 4 + param_5[1]) = iVar25;
              param_5[2] = param_5[2] + 1;
              if (*(float *)(iVar15 + 0x251c) != fVar12) {
                piVar21[0x23] = iVar16;
                iVar16 = iVar14 + 2;
                *(undefined4 *)(param_5[2] * 4 + *param_5) = 0xd;
                *(int *)(param_5[2] * 4 + param_5[1]) = iVar25;
                param_5[2] = param_5[2] + 1;
              }
            }
          }
        }
        uVar4 = uVar4 >> 1;
        iVar25 = iVar25 + 1;
        piVar21 = piVar21 + 0xf;
        iVar15 = iVar15 + 0x80;
        iVar23 = iVar23 + 0x6c;
        iVar8 = iVar16;
      } while (uVar4 != 0);
    }
    if (*(int *)(param_1 + 0x13c) == 1) {
      if (7 < *(uint *)(param_1 + 0x270)) {
        *(int *)(iVar7 + 0x2d8) = iVar16;
        iVar16 = iVar16 + 1;
        *(undefined4 *)(param_5[2] * 4 + *param_5) = 0xe;
        *(undefined4 *)(param_5[2] * 4 + param_5[1]) = 0;
        param_5[2] = param_5[2] + 1;
      }
      if (7 < *(uint *)(param_1 + 0x278)) {
        *(int *)(iVar7 + 0x2dc) = iVar16;
        iVar16 = iVar16 + 1;
        *(undefined4 *)(param_5[2] * 4 + *param_5) = 0xf;
        *(undefined4 *)(param_5[2] * 4 + param_5[1]) = 0;
        param_5[2] = param_5[2] + 1;
      }
      if (7 < *(uint *)(param_1 + 0x280)) {
        *(int *)(iVar7 + 0x2e0) = iVar16;
        iVar16 = iVar16 + 1;
        *(undefined4 *)(param_5[2] * 4 + *param_5) = 0x10;
        *(undefined4 *)(param_5[2] * 4 + param_5[1]) = 0;
        param_5[2] = param_5[2] + 1;
      }
      if (7 < *(uint *)(param_1 + 0x288)) {
        *(int *)(iVar7 + 0x2ec) = iVar16;
        iVar16 = iVar16 + 1;
        *(undefined4 *)(param_5[2] * 4 + *param_5) = 0x11;
        *(undefined4 *)(param_5[2] * 4 + param_5[1]) = 0;
        param_5[2] = param_5[2] + 1;
      }
      if ((7 < *(uint *)(param_1 + 0x270)) || (7 < *(uint *)(param_1 + 0x278))) {
        *(int *)(iVar7 + 0x2f8) = iVar16;
        iVar16 = iVar16 + 1;
        *(undefined4 *)(param_5[2] * 4 + *param_5) = 0x12;
        *(undefined4 *)(param_5[2] * 4 + param_5[1]) = 0;
        param_5[2] = param_5[2] + 1;
      }
      if (1 < *(uint *)(param_1 + 0x290)) {
        *(int *)(iVar7 + 800) = iVar16;
        iVar16 = iVar16 + 1;
        *(undefined4 *)(param_5[2] * 4 + *param_5) = 0x13;
        *(undefined4 *)(param_5[2] * 4 + param_5[1]) = 0;
        param_5[2] = param_5[2] + 1;
      }
      if (((unsigned char *)0x00002d48)[iVar20 + 4] != '\0') {
        if (7 < *(uint *)(param_1 + 0x274)) {
          *(int *)(iVar7 + 0x2fc) = iVar16;
          iVar16 = iVar16 + 1;
          *(undefined4 *)(param_5[2] * 4 + *param_5) = 0xe;
          *(undefined4 *)(param_5[2] * 4 + param_5[1]) = 1;
          param_5[2] = param_5[2] + 1;
        }
        if (7 < *(uint *)(param_1 + 0x27c)) {
          *(int *)(iVar7 + 0x300) = iVar16;
          iVar16 = iVar16 + 1;
          *(undefined4 *)(param_5[2] * 4 + *param_5) = 0xf;
          *(undefined4 *)(param_5[2] * 4 + param_5[1]) = 1;
          param_5[2] = param_5[2] + 1;
        }
        if (7 < *(uint *)(param_1 + 0x284)) {
          *(int *)(iVar7 + 0x304) = iVar16;
          iVar16 = iVar16 + 1;
          *(undefined4 *)(param_5[2] * 4 + *param_5) = 0x10;
          *(undefined4 *)(param_5[2] * 4 + param_5[1]) = 1;
          param_5[2] = param_5[2] + 1;
        }
        if (7 < *(uint *)(param_1 + 0x28c)) {
          *(int *)(iVar7 + 0x310) = iVar16;
          iVar16 = iVar16 + 1;
          *(undefined4 *)(param_5[2] * 4 + *param_5) = 0x11;
          *(undefined4 *)(param_5[2] * 4 + param_5[1]) = 1;
          param_5[2] = param_5[2] + 1;
        }
        if ((7 < *(uint *)(param_1 + 0x274)) || (7 < *(uint *)(param_1 + 0x27c))) {
          *(int *)(iVar7 + 0x31c) = iVar16;
          iVar16 = iVar16 + 1;
          *(undefined4 *)(param_5[2] * 4 + *param_5) = 0x12;
          *(undefined4 *)(param_5[2] * 4 + param_5[1]) = 1;
          param_5[2] = param_5[2] + 1;
        }
        if (1 < *(uint *)(param_1 + 0x294)) {
          *(int *)(iVar7 + 0x324) = iVar16;
          iVar16 = iVar16 + 1;
          *(undefined4 *)(param_5[2] * 4 + *param_5) = 0x13;
          *(undefined4 *)(param_5[2] * 4 + param_5[1]) = 1;
          param_5[2] = param_5[2] + 1;
        }
      }
    }
    *(int *)(iVar7 + 0x328) = iVar16;
    iVar8 = iVar16 + 1;
    *(undefined4 *)(param_5[2] * 4 + *param_5) = 0x14;
    *(undefined4 *)(param_5[2] * 4 + param_5[1]) = 0;
    param_5[2] = param_5[2] + 1;
    if (bVar3) {
      *(int *)(iVar7 + 0x32c) = iVar8;
      iVar8 = iVar16 + 2;
      *(undefined4 *)(param_5[2] * 4 + *param_5) = 0x1b;
      *(undefined4 *)(param_5[2] * 4 + param_5[1]) = 0;
      param_5[2] = param_5[2] + 1;
      uVar4 = *(uint *)(param_1 + 0x44);
    }
    else {
      uVar4 = *(uint *)(param_1 + 0x44);
    }
  }
  if (((uVar4 & 0x1000000) != 0) && (*(char *)(param_1 + 0x121) == '\0')) {
    *(int *)(iVar7 + 0x330) = iVar8;
    iVar8 = iVar8 + 1;
    *(undefined4 *)(param_5[2] * 4 + *param_5) = 0x15;
    *(undefined4 *)(param_5[2] * 4 + param_5[1]) = 0;
    param_5[2] = param_5[2] + 1;
  }
  if ((*(uint *)(param_1 + 0x1874) & 0xc0000000) == 0x80000000) {
    *(int *)(iVar7 + 0x334) = iVar8;
    iVar16 = iVar8 + 1;
    iVar20 = iVar8 + 2;
    iVar8 = iVar8 + 3;
    *(undefined4 *)(param_5[2] * 4 + *param_5) = 0x16;
    *(undefined4 *)(param_5[2] * 4 + param_5[1]) = 0;
    param_5[2] = param_5[2] + 1;
    *(int *)(iVar7 + 0x338) = iVar16;
    *(undefined4 *)(param_5[2] * 4 + *param_5) = 0x17;
    *(undefined4 *)(param_5[2] * 4 + param_5[1]) = 0;
    param_5[2] = param_5[2] + 1;
    *(int *)(iVar7 + 0x340) = iVar20;
    *(undefined4 *)(param_5[2] * 4 + *param_5) = 0x18;
    *(undefined4 *)(param_5[2] * 4 + param_5[1]) = 0;
    param_5[2] = param_5[2] + 1;
  }
  if (*(char *)(param_1 + 300) != '\0') {
    *(int *)(iVar7 + 0x344) = iVar8;
    iVar8 = iVar8 + 1;
    *(undefined4 *)(param_5[2] * 4 + *param_5) = 0x19;
    *(undefined4 *)(param_5[2] * 4 + param_5[1]) = 0;
    param_5[2] = param_5[2] + 1;
  }
  *param_4 = iVar8;
  if (((unsigned char *)0x00004301)[iVar19] == '\0') {
    (*(float *)((char *)frame_ + 8)) = GH_U2F((unsigned int)((iVar19 + 0x1960)));
    if ((((((((uint *)((char *)frame_ + 12))[0] == 0 &((uint *)((char *)frame_ + 12))[1] == 0) &((uint *)((char *)frame_ + 12))[2] == 0) &&
          FLOAT_001aa0e8 == (*(float *)((char *)frame_ + 8))) &&
         (((((uint *)((char *)frame_ + 12))[3] == 0 && (*(int *)((char *)frame_ + 32)) == 0) && (*(int *)((char *)frame_ + 36)) == 0) && FLOAT_001aa0e8 == (*(float *)((char *)frame_ + 28)))) &&
        ((((*(int *)((char *)frame_ + 40)) == 0 && (*(int *)((char *)frame_ + 44)) == 0) && (*(int *)((char *)frame_ + 52)) == 0) && FLOAT_001aa0e8 == (*(float *)((char *)frame_ + 48)))) &&
        ((((*(int *)((char *)frame_ + 56)) == 0 && unaff_r17 == 0) && unaff_r18 == 0) && FLOAT_001aa0e8 == unaff_r19)) {
      FUN_00092d40(iVar7,uVar18,uVar6);
    }
    else {
      ((int (*)())FUN_00095dd0)(iVar7,uVar18,uVar6);
    }
    if (*(char *)(param_1 + 0x12a) != '\0') {
      ((int (*)())FUN_00096500)(iVar7);
    }
  }
  else {
    uVar4 = (uint)*(byte *)(param_1 + 0x90);
    if (uVar4 != 0) {
      iVar20 = 0;
      iVar8 = param_1;
      if (uVar4 == 0) {
        uVar4 = 1;
      }
      do {
        ((uint *)((char *)frame_ + 12))[iVar20] = (uint)(byte)((unsigned char *)0x000013a9)[iVar8];
        uVar4 = uVar4 - 1;
        iVar20 = iVar20 + 1;
        iVar8 = iVar8 + 1;
      } while (uVar4 != 0);
    }
    ((int (*)())FUN_000955e0)(iVar7,(uint)*(byte *)(param_1 + 0x91),(uint)(byte)((unsigned char *)0x00004302)[iVar19]);
    if (*(char *)(param_1 + 0x129) == '\0') {
      ((int (*)())FUN_00093a40)(iVar7,((uint *)((char *)frame_ + 12)),(uint)*(byte *)(param_1 + 0x91),
                   (uint)(byte)((unsigned char *)0x00004302)[iVar19],uVar18,uVar6);
    }
    else {
      ((int (*)())FUN_00094840)(iVar7,((uint *)((char *)frame_ + 12)),(uint)*(byte *)(param_1 + 0x91),
                   (uint)(byte)((unsigned char *)0x00004302)[iVar19],(uint)(*(char *)(param_1 + 0x90) == '\x02'));
      ((int (*)())FUN_00095610)(iVar7,uVar18,uVar6);
    }
    if (*(char *)(param_1 + 0x12a) != '\0') {
      ((int (*)())FUN_00093510)(iVar7,((uint *)((char *)frame_ + 12)),(uint)*(byte *)(param_1 + 0x91),
                   (uint)(byte)((unsigned char *)0x00004302)[iVar19]);
    }
  }
  if (*(char *)(param_1 + 0x128) == '\0') {
    if (*(char *)(param_1 + 300) != '\0') {
      ((int (*)())FUN_000939e0)(iVar7);
    }
  }
  else {
    ((int (*)())FUN_00093a20)(iVar7);
  }
  uVar6 = *(uint *)(param_1 + 0x44);
  if ((((uVar6 & 0x1000000) != 0) && (*(char *)(param_1 + 0x121) == '\0')) &&
     ((*(int *)(iVar7 + 0x3d8) == 0 || ((uVar6 & 0x2000) == 0)))) {
    sVar2 = *(short *)(((unsigned char *)0x00002e04) + iVar19);
    if (sVar2 == 0x801) {
      ((int (*)())FUN_00096540)(iVar7);
      uVar6 = *(uint *)(param_1 + 0x44);
    }
    else if (sVar2 == 0x2601) {
      ((int (*)())FUN_0009af00)(iVar7);
      uVar6 = *(uint *)(param_1 + 0x44);
    }
    else if (sVar2 == 0x800) {
      ((int (*)())FUN_0009b790)(iVar7);
      uVar6 = *(uint *)(param_1 + 0x44);
    }
  }
  if ((uVar6 & 0x20000) == 0) {
    if ((*(uint *)(param_1 + 0x8c) & 0x800000) == 0) goto LAB_0009e8dc;
    uVar4 = (uint)*(byte *)(param_1 + 0x2b);
    if ((uint)(byte)((unsigned char *)0x000013b0)[param_1] < (uint)*(byte *)(param_1 + 0x2b)) {
      uVar4 = (uint)(byte)((unsigned char *)0x000013b0)[param_1];
    }
    if (uVar4 == 0) goto LAB_0009e8dc;
    uVar6 = 0;
    puVar24 = (ushort *)(param_1 + 0x187c);
    iVar20 = param_1;
    iVar8 = param_1;
    do {
      if (((unsigned char *)0x00001438)[iVar8] != '\0') {
        ((int (*)())FUN_00096600)(iVar7,uVar6,0,uVar6,(uint)*(byte *)(iVar20 + 0x153),uVar6,*puVar24 >> 2 & 0xfff
                    );
      }
      uVar6 = uVar6 + 1;
      puVar24 = puVar24 + 1;
      iVar8 = iVar8 + 1;
      iVar20 = iVar20 + 4;
    } while (uVar4 != uVar6);
  }
  else {
    if ((uVar6 & 0x2000) == 0) {
      bVar1 = ((unsigned char *)0x00001135)[param_1];
    }
    else {
      bVar1 = ((unsigned char *)0x000011d3)[param_1];
    }
    uVar4 = (uint)(byte)((unsigned char *)0x000013b0)[param_1];
    if (uVar4 == 0) goto LAB_0009e8dc;
    uVar6 = 0;
    puVar24 = (ushort *)(param_1 + 0x187c);
    iVar20 = param_1;
    do {
      if (((uint)bVar1 & 1 << (uVar6 & 0x3f)) != 0) {
        ((int (*)())FUN_00096600)(iVar7,uVar6,0,uVar6,(uint)*(byte *)(iVar20 + 0x153),uVar6,*puVar24 >> 2 & 0xfff
                    );
        uVar4 = (uint)(byte)((unsigned char *)0x000013b0)[param_1];
      }
      uVar6 = uVar6 + 1;
      puVar24 = puVar24 + 1;
      iVar20 = iVar20 + 4;
    } while ((int)uVar6 < (int)uVar4);
  }
  uVar6 = *(uint *)(param_1 + 0x44);
LAB_0009e8dc:
  if ((int)uVar6 < 0) {
    iVar20 = 0;
    ((int (*)())FUN_00096d80)(iVar7);
    fVar12 = FLOAT_001aa0d4;
    uVar6 = *(uint *)(param_1 + 0x88);
    if (uVar6 != 0) {
      iVar20 = 0;
      iVar8 = 0;
      puVar22 = (uint *)(param_1 + 0x3a8);
      uVar4 = uVar6;
      do {
        if (((uVar4 & 1) != 0) && ((*puVar22 & 0xfc000000) != 0)) {
          iVar8 = iVar20;
        }
        uVar4 = uVar4 >> 1;
        iVar20 = iVar20 + 1;
        puVar22 = puVar22 + 1;
      } while (uVar4 != 0);
      iVar20 = 0;
      iVar16 = 0;
      puVar22 = (uint *)(param_1 + 0x3a8);
      do {
        if (((uVar6 & 1) != 0) && (uVar4 = *puVar22, (uVar4 & 0xfc000000) != 0)) {
          if (*(float *)(iVar19 + 0x24fc) == fVar12) {
            ((int (*)())FUN_00097440)(iVar7,iVar16,(uint)(iVar20 == 0),(uint)(iVar16 == iVar8),uVar4 >> 0x1e,
                         uVar4 >> 0x1c & 3,uVar4 >> 0x1a & 3);
          }
          else {
            ((int (*)())FUN_00098500)(iVar7,iVar16,(uint)(iVar20 == 0),(uint)(iVar16 == iVar8),uVar4 >> 0x19 & 1,
                         uVar4 >> 0x18 & 1,uVar4 >> 0x17 & 1,uVar4 >> 0x1e,uVar4 >> 0x1c & 3,
                         uVar4 >> 0x1a & 3);
          }
          iVar20 = iVar20 + 1;
        }
        uVar6 = uVar6 >> 1;
        iVar16 = iVar16 + 1;
        puVar22 = puVar22 + 1;
        iVar19 = iVar19 + 0x80;
      } while (uVar6 != 0);
    }
    ((int (*)())FUN_0009b430)(iVar7,iVar20);
  }
  else {
    FUN_00092ea0(iVar7,3,0,0);
    if ((*(uint *)(param_1 + 0x44) & 0xa10000) != 0) {
      FUN_00092ea0(iVar7,4,1,0);
    }
  }
  if ((*(uint *)(param_1 + 0x1874) & 0xc0000000) == 0x80000000) {
    ((int (*)())FUN_00099e50)(iVar7,2,(uint)(*(float *)(param_1 + 0x114) == FLOAT_001aa0d4));
  }
  if ((*(uint *)(param_1 + 0x44) & 0x800) == 0) {
    if (*(char *)(param_1 + 0x121) != '\0') {
      ((int (*)())FUN_0009b850)(iVar7,(uint)*(byte *)(param_1 + 0x120));
    }
  }
  else if (*(int *)(iVar7 + 0x3d8) == 0) {
    ((int (*)())FUN_0009b850)(iVar7,(uint)(byte)((unsigned char *)0x000011d1)[param_1]);
  }
  else {
    ((int (*)())FUN_0009a590)(iVar7);
  }
  iVar19 = ((int (*)())FUN_0009a910)(iVar7);
  if (iVar19 == 6) {
    *(undefined1 *)(param_1 + 0x126) = 1;
  }
  return iVar7;
}

/* FUN_0009eb90 @ 0x9eb90 (560 bytes) */
int FUN_0009eb90(param_1, param_2)
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
  int iVar12;
  
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
      iVar12 = 0;
      do {
        puVar5 = *(uint **)(iVar12 * 4 + iVar4);
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
        iVar12 = iVar12 + 1;
      } while (iVar11 != iVar12);
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
  int iVar7;
  uint *puVar8;
  uint *puVar9;
  uint uVar10;
  int iVar11;
  
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
    iVar11 = 0;
    if (iVar5 != 0) {
      do {
        iVar7 = _memcmp(iVar5,param_2,0x30);
        if (iVar7 == 0) {
          return iVar5;
        }
        iVar5 = *(int *)(iVar5 + 0x5c);
        iVar11 = iVar11 + 1;
      } while (iVar5 != 0);
      goto LAB_0009f014;
    }
  }
  else {
    iVar11 = 0;
    if (iVar5 != 0) {
      do {
        iVar7 = _memcmp(iVar5,param_2,0x18);
        if (iVar7 == 0) {
          return iVar5;
        }
        iVar5 = *(int *)(iVar5 + 0x5c);
        iVar11 = iVar11 + 1;
      } while (iVar5 != 0);
      goto LAB_0009f014;
    }
  }
  iVar11 = 0;
LAB_0009f014:
  if ((bVar1) || (iVar11 < 5)) {
    if ((iVar11 < 8) || (0xfb2e < uVar10)) {
      return 0;
    }
    if (bVar1) {
      ((int (*)())FUN_0009eb90)(param_1,0x859);
      return 0;
    }
  }
  ((int (*)())FUN_0009eb90)(param_1,0);
  ((unsigned char *)0x00001120)[param_1] = 0;
  return 0;
}

/* FUN_0009f0b0 @ 0x9f0b0 (4444 bytes) */
void FUN_0009f0b0(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  uint uVar16;
  undefined4 uVar17;
  int iVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  int iVar25;
  undefined8 *puVar26;
  uint uVar27;
  int iVar28;
  undefined4 uVar29;
  int iVar30;
  int iVar31;
  uint uVar32;
  int iVar33;
  int iVar34;
  int iVar35;
  int iVar36;
  undefined4 uVar37;
  undefined4 uVar38;
  undefined4 uVar39;
  undefined4 uVar40;
  undefined4 uVar41;
  undefined4 uVar42;
  undefined4 uVar43;
  uint uVar44;
  int *piVar45;
  undefined8 uVar46;
  double dVar47;
  double dVar48;
  double dVar49;
  double dVar50;
  double dVar51;
  double dVar52;
  double dVar53;
  double dVar54;
  double dVar55;
  undefined8 uVar56;
  double dVar57;
  double dVar58;
  double dVar59;
  double dVar60;
  double dVar61;
  double dVar62;
  unsigned int frame_[92] __attribute__((aligned(16)));
  
  piVar45 = *(int **)(param_2 + 0x50);
  iVar31 = *(int *)(param_1 + 4);
  iVar18 = *(int *)(param_2 + 0x54);
  iVar36 = *(int *)(param_2 + 0x4c);
  uVar27 = piVar45[2];
  iVar35 = *(int *)(iVar31 + 0x10);
  iVar33 = iVar18 + 0xa4;
  if (uVar27 != 0) {
    uVar32 = 0;
    iVar34 = 0;
    do {
      uVar44 = *(uint *)(piVar45[1] + iVar34);
      switch(*(undefined4 *)(*piVar45 + iVar34)) {
      case 0:
        dVar50 = (double)*(float *)(iVar35 + 0x1920);
        iVar25 = iVar35 + 0x1860 + uVar44 * 0x40;
        fVar15 = *(float *)(iVar35 + 0x1930);
        fVar1 = *(float *)(iVar35 + 0x1934);
        fVar2 = *(float *)(iVar35 + 0x1938);
        fVar3 = *(float *)(iVar35 + 0x193c);
        dVar52 = (double)*(float *)(iVar25 + 0x100);
        dVar49 = (double)*(float *)(iVar35 + 0x1924);
        fVar4 = *(float *)(iVar25 + 0x104);
        dVar48 = (double)*(float *)(iVar35 + 0x1928);
        dVar47 = (double)*(float *)(iVar35 + 0x192c);
        fVar7 = *(float *)(iVar35 + 0x1940);
        fVar8 = *(float *)(iVar35 + 0x1944);
        fVar9 = *(float *)(iVar35 + 0x1948);
        fVar10 = *(float *)(iVar35 + 0x194c);
        fVar11 = *(float *)(iVar25 + 0x108);
        fVar12 = *(float *)(iVar35 + 0x195c);
        fVar13 = *(float *)(iVar35 + 0x1950);
        fVar14 = *(float *)(iVar35 + 0x1954);
        fVar5 = *(float *)(iVar35 + 0x1958);
        fVar6 = *(float *)(iVar25 + 0x10c);
        (*(float *)((char *)frame_ + 36)) = fVar12 * fVar6 +
                    fVar10 * fVar11 + (float)(dVar47 * dVar52 + (double)(fVar3 * fVar4));
        (*(float *)((char *)frame_ + 24)) = fVar13 * fVar6 +
                    fVar7 * fVar11 + (float)(dVar50 * dVar52 + (double)(fVar15 * fVar4));
        (*(float *)((char *)frame_ + 28)) = fVar14 * fVar6 +
                    fVar8 * fVar11 + (float)(dVar49 * dVar52 + (double)(fVar1 * fVar4));
        (*(float *)((char *)frame_ + 32)) = fVar5 * fVar6 +
                    fVar9 * fVar11 + (float)(dVar48 * dVar52 + (double)(fVar2 * fVar4));
        fVar4 = *(float *)(iVar25 + 0x114);
        dVar52 = (double)*(float *)(iVar25 + 0x110);
        fVar11 = *(float *)(iVar25 + 0x118);
        fVar6 = *(float *)(iVar25 + 0x11c);
        (*(float *)((char *)frame_ + 52)) = fVar12 * fVar6 +
                    fVar10 * fVar11 + (float)(dVar47 * dVar52 + (double)(fVar3 * fVar4));
        (*(float *)((char *)frame_ + 40)) = fVar13 * fVar6 +
                    fVar7 * fVar11 + (float)(dVar50 * dVar52 + (double)(fVar15 * fVar4));
        (*(float *)((char *)frame_ + 44)) = fVar14 * fVar6 +
                    fVar8 * fVar11 + (float)(dVar49 * dVar52 + (double)(fVar1 * fVar4));
        (*(float *)((char *)frame_ + 48)) = fVar5 * fVar6 +
                    fVar9 * fVar11 + (float)(dVar48 * dVar52 + (double)(fVar2 * fVar4));
        fVar4 = *(float *)(iVar25 + 0x124);
        dVar52 = (double)*(float *)(iVar25 + 0x120);
        fVar11 = *(float *)(iVar25 + 0x128);
        fVar6 = *(float *)(iVar25 + 300);
        (*(float *)((char *)frame_ + 68)) = fVar12 * fVar6 +
                    fVar10 * fVar11 + (float)(dVar47 * dVar52 + (double)(fVar3 * fVar4));
        (*(float *)((char *)frame_ + 56)) = fVar13 * fVar6 +
                    fVar7 * fVar11 + (float)(dVar50 * dVar52 + (double)(fVar15 * fVar4));
        (*(float *)((char *)frame_ + 60)) = fVar14 * fVar6 +
                    fVar8 * fVar11 + (float)(dVar49 * dVar52 + (double)(fVar1 * fVar4));
        (*(float *)((char *)frame_ + 64)) = fVar5 * fVar6 +
                    fVar9 * fVar11 + (float)(dVar48 * dVar52 + (double)(fVar2 * fVar4));
        fVar4 = *(float *)(iVar25 + 0x134);
        dVar52 = (double)*(float *)(iVar25 + 0x130);
        fVar11 = *(float *)(iVar25 + 0x138);
        fVar6 = *(float *)(iVar25 + 0x13c);
        fparam_1 = (double)(fVar1 * fVar4);
        (*(float *)((char *)frame_ + 84)) = fVar12 * fVar6 +
                    fVar10 * fVar11 + (float)(dVar47 * dVar52 + (double)(fVar3 * fVar4));
        (*(float *)((char *)frame_ + 72)) = fVar13 * fVar6 +
                    fVar7 * fVar11 + (float)(dVar50 * dVar52 + (double)(fVar15 * fVar4));
        (*(float *)((char *)frame_ + 76)) = fVar14 * fVar6 + fVar8 * fVar11 + (float)(dVar49 * dVar52 + fparam_1);
        (*(float *)((char *)frame_ + 80)) = fVar5 * fVar6 +
                    fVar9 * fVar11 + (float)(dVar48 * dVar52 + (double)(fVar2 * fVar4));
        iVar25 = *(int *)(uVar44 * 4 + iVar33) * 0x10;
        iVar30 = iVar36 + iVar25;
        if ((*(uint *)(((unsigned char *)0x000013c0) + param_1) & 4) == 0) {
          *(float *)(iVar36 + iVar25) = (*(float *)((char *)frame_ + 24));
          *(float *)(iVar30 + 0x3c) = (*(float *)((char *)frame_ + 84));
          *(float *)(iVar30 + 4) = (*(float *)((char *)frame_ + 40));
          *(float *)(iVar30 + 8) = (*(float *)((char *)frame_ + 56));
          *(float *)(iVar30 + 0xc) = (*(float *)((char *)frame_ + 72));
          *(float *)(iVar30 + 0x10) = (*(float *)((char *)frame_ + 28));
          *(float *)(iVar30 + 0x14) = (*(float *)((char *)frame_ + 44));
          *(float *)(iVar30 + 0x18) = (*(float *)((char *)frame_ + 60));
          *(float *)(iVar30 + 0x1c) = (*(float *)((char *)frame_ + 76));
          *(float *)(iVar30 + 0x20) = (*(float *)((char *)frame_ + 32));
          *(float *)(iVar30 + 0x24) = (*(float *)((char *)frame_ + 48));
          *(float *)(iVar30 + 0x28) = (*(float *)((char *)frame_ + 64));
          *(float *)(iVar30 + 0x2c) = (*(float *)((char *)frame_ + 80));
          *(float *)(iVar30 + 0x30) = (*(float *)((char *)frame_ + 36));
          *(float *)(iVar30 + 0x34) = (*(float *)((char *)frame_ + 52));
          *(float *)(iVar30 + 0x38) = (*(float *)((char *)frame_ + 68));
          uVar27 = piVar45[2];
        }
        else {
          *(float *)(iVar36 + iVar25) = (*(float *)((char *)frame_ + 24));
          *(float *)(iVar30 + 0x3c) = (*(float *)((char *)frame_ + 84));
          *(float *)(iVar30 + 4) = (*(float *)((char *)frame_ + 28));
          *(float *)(iVar30 + 8) = (*(float *)((char *)frame_ + 32));
          *(float *)(iVar30 + 0xc) = (*(float *)((char *)frame_ + 36));
          *(float *)(iVar30 + 0x10) = (*(float *)((char *)frame_ + 40));
          *(float *)(iVar30 + 0x14) = (*(float *)((char *)frame_ + 44));
          *(float *)(iVar30 + 0x18) = (*(float *)((char *)frame_ + 48));
          *(float *)(iVar30 + 0x1c) = (*(float *)((char *)frame_ + 52));
          *(float *)(iVar30 + 0x20) = (*(float *)((char *)frame_ + 56));
          *(float *)(iVar30 + 0x24) = (*(float *)((char *)frame_ + 60));
          *(float *)(iVar30 + 0x28) = (*(float *)((char *)frame_ + 64));
          *(float *)(iVar30 + 0x2c) = (*(float *)((char *)frame_ + 68));
          *(float *)(iVar30 + 0x30) = (*(float *)((char *)frame_ + 72));
          *(float *)(iVar30 + 0x34) = (*(float *)((char *)frame_ + 76));
          *(float *)(iVar30 + 0x38) = (*(float *)((char *)frame_ + 80));
          uVar27 = piVar45[2];
        }
        break;
      case 1:
        iVar28 = iVar35 + 0x1860 + uVar44 * 0x40;
        iVar25 = *(int *)(uVar44 * 4 + iVar33 + 0x10) * 0x10;
        uVar21 = *(undefined4 *)(iVar28 + 0x104);
        uVar24 = *(undefined4 *)(iVar28 + 0x13c);
        iVar30 = iVar36 + iVar25;
        uVar41 = *(undefined4 *)(iVar28 + 0x108);
        uVar39 = *(undefined4 *)(iVar28 + 0x10c);
        uVar29 = *(undefined4 *)(iVar28 + 0x110);
        uVar19 = *(undefined4 *)(iVar28 + 0x114);
        uVar42 = *(undefined4 *)(iVar28 + 0x118);
        uVar37 = *(undefined4 *)(iVar28 + 0x11c);
        uVar23 = *(undefined4 *)(iVar28 + 0x120);
        uVar20 = *(undefined4 *)(iVar28 + 0x124);
        uVar40 = *(undefined4 *)(iVar28 + 0x128);
        uVar38 = *(undefined4 *)(iVar28 + 300);
        uVar22 = *(undefined4 *)(iVar28 + 0x130);
        uVar43 = *(undefined4 *)(iVar28 + 0x134);
        uVar17 = *(undefined4 *)(iVar28 + 0x138);
        if ((*(uint *)(((unsigned char *)0x000013c0) + param_1) & 4) == 0) {
          *(undefined4 *)(iVar36 + iVar25) = *(undefined4 *)(iVar28 + 0x100);
          *(undefined4 *)(iVar30 + 0x3c) = uVar24;
          *(undefined4 *)(iVar30 + 4) = uVar29;
          *(undefined4 *)(iVar30 + 8) = uVar23;
          *(undefined4 *)(iVar30 + 0xc) = uVar22;
          *(undefined4 *)(iVar30 + 0x10) = uVar21;
          *(undefined4 *)(iVar30 + 0x14) = uVar19;
          *(undefined4 *)(iVar30 + 0x18) = uVar20;
          *(undefined4 *)(iVar30 + 0x1c) = uVar43;
          *(undefined4 *)(iVar30 + 0x20) = uVar41;
          *(undefined4 *)(iVar30 + 0x24) = uVar42;
          *(undefined4 *)(iVar30 + 0x28) = uVar40;
          *(undefined4 *)(iVar30 + 0x2c) = uVar17;
          *(undefined4 *)(iVar30 + 0x30) = uVar39;
          *(undefined4 *)(iVar30 + 0x34) = uVar37;
          *(undefined4 *)(iVar30 + 0x38) = uVar38;
          uVar27 = piVar45[2];
        }
        else {
          *(undefined4 *)(iVar36 + iVar25) = *(undefined4 *)(iVar28 + 0x100);
          *(undefined4 *)(iVar30 + 0x3c) = uVar24;
          *(undefined4 *)(iVar30 + 4) = uVar21;
          *(undefined4 *)(iVar30 + 8) = uVar41;
          *(undefined4 *)(iVar30 + 0xc) = uVar39;
          *(undefined4 *)(iVar30 + 0x10) = uVar29;
          *(undefined4 *)(iVar30 + 0x14) = uVar19;
          *(undefined4 *)(iVar30 + 0x18) = uVar42;
          *(undefined4 *)(iVar30 + 0x1c) = uVar37;
          *(undefined4 *)(iVar30 + 0x20) = uVar23;
          *(undefined4 *)(iVar30 + 0x24) = uVar20;
          *(undefined4 *)(iVar30 + 0x28) = uVar40;
          *(undefined4 *)(iVar30 + 0x2c) = uVar38;
          *(undefined4 *)(iVar30 + 0x30) = uVar22;
          *(undefined4 *)(iVar30 + 0x34) = uVar43;
          *(undefined4 *)(iVar30 + 0x38) = uVar17;
          uVar27 = piVar45[2];
        }
        break;
      case 2:
        iVar25 = iVar35 + 0x1860 + uVar44 * 0x40;
        fVar7 = *(float *)(iVar25 + 0x100);
        dVar58 = (double)*(float *)(iVar25 + 0x138);
        dVar47 = (double)*(float *)(iVar25 + 0x11c);
        dVar60 = (double)*(float *)(iVar25 + 0x118);
        dVar57 = (double)*(float *)(iVar25 + 0x13c);
        dVar59 = (double)*(float *)(iVar25 + 0x10c);
        dVar61 = (double)*(float *)(iVar25 + 0x108);
        dVar62 = (double)*(float *)(iVar25 + 0x128);
        fVar8 = *(float *)(iVar25 + 0x104);
        fVar9 = *(float *)(iVar25 + 0x114);
        fVar10 = *(float *)(iVar25 + 0x124);
        (*(float *)((char *)frame_ + 104)) = (float)(dVar60 * dVar57 - (double)(float)(dVar47 * dVar58));
        fVar15 = (float)(dVar61 * dVar57 - (double)(float)(dVar59 * dVar58));
        fVar1 = (float)(dVar61 * dVar47 - (double)(float)(dVar59 * dVar60));
        dVar50 = (double)*(float *)(iVar25 + 300);
        fVar11 = *(float *)(iVar25 + 0x134);
        fVar12 = *(float *)(iVar25 + 0x120);
        fVar2 = (float)(dVar61 * dVar50 - (double)(float)(dVar59 * dVar62));
        fVar3 = (float)(dVar60 * dVar50 - (double)(float)(dVar47 * dVar62));
        (*(float *)((char *)frame_ + 112)) = fVar11 * fVar1 + (fVar8 * (*(float *)((char *)frame_ + 104)) - fVar9 * fVar15);
        fVar4 = (float)(dVar62 * dVar57 - (double)(float)(dVar50 * dVar58));
        dVar48 = (double)(fVar7 * fVar10 - fVar8 * fVar12);
        (*(float *)((char *)frame_ + 108)) = -(fVar8 * fVar3 - (fVar9 * fVar2 - fVar10 * fVar1));
        (*(float *)((char *)frame_ + 116)) = -(fVar8 * fVar4 - (fVar10 * fVar15 - fVar11 * fVar2));
        (*(float *)((char *)frame_ + 120)) = fVar11 * fVar3 + (fVar9 * fVar4 - fVar10 * (*(float *)((char *)frame_ + 104)));
        fVar13 = *(float *)(iVar25 + 0x130);
        fVar14 = *(float *)(iVar25 + 0x110);
        dVar49 = (double)(fVar14 * fVar10 - fVar9 * fVar12);
        dVar55 = (double)(fVar7 * fVar11 - fVar8 * fVar13);
        dVar53 = (double)(fVar7 * fVar9 - fVar8 * fVar14);
        dVar51 = (double)(fVar14 * fVar11 - fVar9 * fVar13);
        dVar54 = (double)(fVar12 * fVar11 - fVar10 * fVar13);
        (*(float *)((char *)frame_ + 124)) = fVar7 * (*(float *)((char *)frame_ + 120)) + fVar14 * (*(float *)((char *)frame_ + 116)) + fVar13 * (*(float *)((char *)frame_ + 108)) + fVar12 * (*(float *)((char *)frame_ + 112));
        (*(float *)((char *)frame_ + 128)) = (float)(dVar51 * dVar50);
        fparam_1 = (double)(float)(dVar48 * dVar47 - (double)(float)(dVar53 * dVar50));
        dVar52 = dVar49 * dVar59 - fparam_1;
        if ((*(float *)((char *)frame_ + 124)) != FLOAT_001aa0d4) {
          fVar8 = FLOAT_001aa0e8 / (*(float *)((char *)frame_ + 124));
          (*(float *)((char *)frame_ + 24)) = (*(float *)((char *)frame_ + 120)) * fVar8;
          (*(float *)((char *)frame_ + 56)) = (*(float *)((char *)frame_ + 112)) * fVar8;
          (*(float *)((char *)frame_ + 40)) = (*(float *)((char *)frame_ + 116)) * fVar8;
          (*(float *)((char *)frame_ + 36)) = -(float)(dVar54 * dVar60 -
                              (double)(float)(dVar51 * dVar62 - (double)(float)(dVar49 * dVar58))) *
                      fVar8;
          (*(float *)((char *)frame_ + 84)) = (float)(dVar53 * dVar62 +
                             (double)(float)(dVar49 * dVar61 - (double)(float)(dVar48 * dVar60))) *
                      fVar8;
          (*(float *)((char *)frame_ + 28)) = fVar8 * -(fVar14 * fVar4 - (fVar12 * (*(float *)((char *)frame_ + 104)) - fVar13 * fVar3));
          (*(float *)((char *)frame_ + 32)) = (float)(dVar49 * dVar57 + (double)(float)(dVar54 * dVar47 - (double)(*(float *)((char *)frame_ + 128))))
                      * fVar8;
          (*(float *)((char *)frame_ + 44)) = fVar8 * (fVar13 * fVar2 + (fVar7 * fVar4 - fVar12 * fVar15));
          (*(float *)((char *)frame_ + 48)) = -(float)(dVar54 * dVar59 -
                              (double)(float)(dVar55 * dVar50 - (double)(float)(dVar48 * dVar57))) *
                      fVar8;
          (*(float *)((char *)frame_ + 60)) = fVar8 * -(fVar7 * (*(float *)((char *)frame_ + 104)) - (fVar14 * fVar15 - fVar13 * fVar1));
          (*(float *)((char *)frame_ + 52)) = (float)(dVar48 * dVar58 +
                             (double)(float)(dVar54 * dVar61 - (double)(float)(dVar55 * dVar62))) *
                      fVar8;
          (*(float *)((char *)frame_ + 76)) = fVar8 * (fVar12 * fVar1 + (fVar7 * fVar3 - fVar14 * fVar2));
          (*(float *)((char *)frame_ + 72)) = (*(float *)((char *)frame_ + 108)) * fVar8;
          (*(float *)((char *)frame_ + 68)) = -(float)(dVar51 * dVar61 -
                              (double)(float)(dVar55 * dVar60 - (double)(float)(dVar53 * dVar58))) *
                      fVar8;
          (*(float *)((char *)frame_ + 64)) = (float)(dVar53 * dVar57 +
                             (double)(float)(dVar51 * dVar59 - (double)(float)(dVar55 * dVar47))) *
                      fVar8;
          fparam_1 = (double)(*(float *)((char *)frame_ + 64));
          (*(float *)((char *)frame_ + 80)) = -(float)dVar52 * fVar8;
        }
        iVar25 = *(int *)(uVar44 * 4 + iVar33 + 0x20) * 0x10;
        iVar30 = iVar36 + iVar25;
        *(float *)(iVar36 + iVar25) = (*(float *)((char *)frame_ + 24));
        *(float *)(iVar30 + 0x3c) = (*(float *)((char *)frame_ + 84));
        *(float *)(iVar30 + 4) = (*(float *)((char *)frame_ + 40));
        *(float *)(iVar30 + 8) = (*(float *)((char *)frame_ + 56));
        *(float *)(iVar30 + 0xc) = (*(float *)((char *)frame_ + 72));
        *(float *)(iVar30 + 0x10) = (*(float *)((char *)frame_ + 28));
        *(float *)(iVar30 + 0x14) = (*(float *)((char *)frame_ + 44));
        *(float *)(iVar30 + 0x18) = (*(float *)((char *)frame_ + 60));
        *(float *)(iVar30 + 0x1c) = (*(float *)((char *)frame_ + 76));
        *(float *)(iVar30 + 0x20) = (*(float *)((char *)frame_ + 32));
        *(float *)(iVar30 + 0x24) = (*(float *)((char *)frame_ + 48));
        *(float *)(iVar30 + 0x28) = (*(float *)((char *)frame_ + 64));
        *(float *)(iVar30 + 0x2c) = (*(float *)((char *)frame_ + 80));
        *(float *)(iVar30 + 0x30) = (*(float *)((char *)frame_ + 36));
        *(float *)(iVar30 + 0x34) = (*(float *)((char *)frame_ + 52));
        *(float *)(iVar30 + 0x38) = (*(float *)((char *)frame_ + 68));
        uVar27 = piVar45[2];
        break;
      case 3:
        uVar22 = *(undefined4 *)(iVar35 + 0x1924);
        uVar41 = *(undefined4 *)(iVar35 + 0x1928);
        uVar39 = *(undefined4 *)(iVar35 + 0x192c);
        uVar20 = *(undefined4 *)(iVar35 + 0x1934);
        iVar25 = *(int *)(iVar18 + 0xd4) * 0x10;
        uVar17 = *(undefined4 *)(iVar35 + 0x195c);
        uVar29 = *(undefined4 *)(iVar35 + 0x1930);
        uVar42 = *(undefined4 *)(iVar35 + 0x1938);
        uVar37 = *(undefined4 *)(iVar35 + 0x193c);
        uVar24 = *(undefined4 *)(iVar35 + 0x1940);
        iVar30 = iVar36 + iVar25;
        uVar21 = *(undefined4 *)(iVar35 + 0x1944);
        uVar40 = *(undefined4 *)(iVar35 + 0x1948);
        uVar38 = *(undefined4 *)(iVar35 + 0x194c);
        uVar23 = *(undefined4 *)(iVar35 + 0x1950);
        uVar43 = *(undefined4 *)(iVar35 + 0x1954);
        uVar19 = *(undefined4 *)(iVar35 + 0x1958);
        if ((*(uint *)(((unsigned char *)0x000013c0) + param_1) & 4) == 0) {
          *(undefined4 *)(iVar36 + iVar25) = *(undefined4 *)(iVar35 + 0x1920);
          *(undefined4 *)(iVar30 + 0x3c) = uVar17;
          *(undefined4 *)(iVar30 + 4) = uVar29;
          *(undefined4 *)(iVar30 + 8) = uVar24;
          *(undefined4 *)(iVar30 + 0xc) = uVar23;
          *(undefined4 *)(iVar30 + 0x10) = uVar22;
          *(undefined4 *)(iVar30 + 0x14) = uVar20;
          *(undefined4 *)(iVar30 + 0x18) = uVar21;
          *(undefined4 *)(iVar30 + 0x1c) = uVar43;
          *(undefined4 *)(iVar30 + 0x20) = uVar41;
          *(undefined4 *)(iVar30 + 0x24) = uVar42;
          *(undefined4 *)(iVar30 + 0x28) = uVar40;
          *(undefined4 *)(iVar30 + 0x2c) = uVar19;
          *(undefined4 *)(iVar30 + 0x30) = uVar39;
          *(undefined4 *)(iVar30 + 0x34) = uVar37;
          *(undefined4 *)(iVar30 + 0x38) = uVar38;
          uVar27 = piVar45[2];
        }
        else {
          *(undefined4 *)(iVar36 + iVar25) = *(undefined4 *)(iVar35 + 0x1920);
          *(undefined4 *)(iVar30 + 0x3c) = uVar17;
          *(undefined4 *)(iVar30 + 4) = uVar22;
          *(undefined4 *)(iVar30 + 8) = uVar41;
          *(undefined4 *)(iVar30 + 0xc) = uVar39;
          *(undefined4 *)(iVar30 + 0x10) = uVar29;
          *(undefined4 *)(iVar30 + 0x14) = uVar20;
          *(undefined4 *)(iVar30 + 0x18) = uVar42;
          *(undefined4 *)(iVar30 + 0x1c) = uVar37;
          *(undefined4 *)(iVar30 + 0x20) = uVar24;
          *(undefined4 *)(iVar30 + 0x24) = uVar21;
          *(undefined4 *)(iVar30 + 0x28) = uVar40;
          *(undefined4 *)(iVar30 + 0x2c) = uVar38;
          *(undefined4 *)(iVar30 + 0x30) = uVar23;
          *(undefined4 *)(iVar30 + 0x34) = uVar43;
          *(undefined4 *)(iVar30 + 0x38) = uVar19;
          uVar27 = piVar45[2];
        }
        break;
      case 4:
        iVar28 = *(int *)(iVar31 + 0x10) + 0x1860 + uVar44 * 0x40;
        iVar25 = *(int *)(uVar44 * 4 + iVar33 + 0x34) * 0x10;
        uVar29 = *(undefined4 *)(iVar28 + 0x420);
        uVar37 = *(undefined4 *)(iVar28 + 0x43c);
        iVar30 = iVar36 + iVar25;
        uVar43 = *(undefined4 *)(iVar28 + 0x404);
        uVar40 = *(undefined4 *)(iVar28 + 0x408);
        uVar38 = *(undefined4 *)(iVar28 + 0x40c);
        uVar23 = *(undefined4 *)(iVar28 + 0x410);
        uVar20 = *(undefined4 *)(iVar28 + 0x414);
        uVar42 = *(undefined4 *)(iVar28 + 0x418);
        uVar39 = *(undefined4 *)(iVar28 + 0x41c);
        uVar22 = *(undefined4 *)(iVar28 + 0x424);
        uVar19 = *(undefined4 *)(iVar28 + 0x428);
        uVar41 = *(undefined4 *)(iVar28 + 0x42c);
        uVar17 = *(undefined4 *)(iVar28 + 0x430);
        uVar24 = *(undefined4 *)(iVar28 + 0x434);
        uVar21 = *(undefined4 *)(iVar28 + 0x438);
        *(undefined4 *)(iVar36 + iVar25) = *(undefined4 *)(iVar28 + 0x400);
        *(undefined4 *)(iVar30 + 8) = uVar29;
        *(undefined4 *)(iVar30 + 4) = uVar23;
        *(undefined4 *)(iVar30 + 0x10) = uVar43;
        *(undefined4 *)(iVar30 + 0x14) = uVar20;
        *(undefined4 *)(iVar30 + 0xc) = uVar17;
        *(undefined4 *)(iVar30 + 0x18) = uVar22;
        *(undefined4 *)(iVar30 + 0x1c) = uVar24;
        *(undefined4 *)(iVar30 + 0x20) = uVar40;
        *(undefined4 *)(iVar30 + 0x24) = uVar42;
        *(undefined4 *)(iVar30 + 0x28) = uVar19;
        *(undefined4 *)(iVar30 + 0x2c) = uVar21;
        *(undefined4 *)(iVar30 + 0x30) = uVar38;
        *(undefined4 *)(iVar30 + 0x34) = uVar39;
        *(undefined4 *)(iVar30 + 0x38) = uVar41;
        *(undefined4 *)(iVar30 + 0x3c) = uVar37;
        uVar27 = piVar45[2];
        break;
      case 5:
        uVar46 = *(undefined8 *)(iVar35 + 0x24c0 + uVar44 * 0x80);
        uVar56 = *(undefined8 *)(iVar35 + 0x24c0 + uVar44 * 0x80 + 8);
        iVar25 = *(int *)(uVar44 * 0x3c + iVar33 + 0x58);
        goto LAB_0009fa50;
      case 6:
        iVar25 = iVar35 + 0x24c0 + uVar44 * 0x80;
        uVar46 = *(undefined8 *)(iVar25 + 0x10);
        uVar56 = *(undefined8 *)(iVar25 + 0x18);
        iVar25 = *(int *)(uVar44 * 0x3c + iVar33 + 0x5c);
        goto LAB_0009fa50;
      case 7:
        iVar25 = iVar35 + 0x24c0 + uVar44 * 0x80;
        uVar46 = *(undefined8 *)(iVar25 + 0x20);
        uVar56 = *(undefined8 *)(iVar25 + 0x28);
        iVar25 = *(int *)(uVar44 * 0x3c + iVar33 + 0x68);
        goto LAB_0009fa50;
      case 8:
        if ((*(char *)(param_1 + 0x12f) != '\0') && ((*(uint *)(iVar35 + 0x24ac) & 0xffff00) != 0))
        {
          if (*(char *)(iVar35 + 0x24ad) == '\0') {
            if (*(char *)(iVar35 + 0x24ae) != '\0') {
              fVar15 = *(float *)(iVar35 + 0x24a4);
              iVar25 = uVar44 * 0x10 + param_1;
              (*(float *)((char *)frame_ + 16)) = fVar15 * *(float *)(iVar25 + 0x2a0);
              (*(float *)((char *)frame_ + 8)) = fVar15 * *(float *)(iVar25 + 0x298);
              (*(float *)((char *)frame_ + 12)) = fVar15 * *(float *)(iVar25 + 0x29c);
            }
          }
          else {
            fparam_1 = (double)(**(code **)(((unsigned char *)0x00001348) + param_1))
                                         (&(*(float *)((char *)frame_ + 8)),uVar44 * 0x10 + param_1 + 0x298);
          }
          (*(undefined4 *)((char *)frame_ + 20)) = 0x3f800000;
          iVar25 = *(int *)(uVar44 * 0x3c + iVar33 + 0x78);
          goto LAB_0009fb60;
        }
        iVar25 = param_1 + uVar44 * 0x10 + 0x290;
        uVar46 = *(undefined8 *)(iVar25 + 8);
        uVar56 = *(undefined8 *)(iVar25 + 0x10);
        iVar25 = *(int *)(uVar44 * 0x3c + iVar33 + 0x78);
        goto LAB_0009fa50;
      case 9:
        if ((*(char *)(param_1 + 0x12f) != '\0') && ((*(uint *)(iVar35 + 0x24ac) & 0xffff00) != 0))
        {
          if (*(char *)(iVar35 + 0x24ad) == '\0') {
            if (*(char *)(iVar35 + 0x24ae) != '\0') {
              fVar15 = *(float *)(iVar35 + 0x24a4);
              iVar25 = uVar44 * 0x10 + param_1;
              (*(float *)((char *)frame_ + 16)) = fVar15 * *(float *)(iVar25 + 800);
              (*(float *)((char *)frame_ + 8)) = fVar15 * *(float *)(iVar25 + 0x318);
              (*(float *)((char *)frame_ + 12)) = fVar15 * *(float *)(iVar25 + 0x31c);
            }
          }
          else {
            fparam_1 = (double)(**(code **)(((unsigned char *)0x00001348) + param_1))
                                         (fparam_1,&(*(float *)((char *)frame_ + 8)),uVar44 * 0x10 + param_1 + 0x318);
          }
          (*(undefined4 *)((char *)frame_ + 20)) = 0x3f800000;
          iVar25 = *(int *)(uVar44 * 0x3c + iVar33 + 0x7c);
          goto LAB_0009fb60;
        }
        iVar25 = param_1 + uVar44 * 0x10 + 0x310;
        uVar46 = *(undefined8 *)(iVar25 + 8);
        uVar56 = *(undefined8 *)(iVar25 + 0x10);
        iVar25 = *(int *)(uVar44 * 0x3c + iVar33 + 0x7c);
        goto LAB_0009fa50;
      case 10:
        iVar25 = iVar35 + 0x24c0 + uVar44 * 0x80;
        (*(float *)((char *)frame_ + 8)) = *(float *)(iVar25 + 0x58);
        (*(float *)((char *)frame_ + 12)) = *(float *)(iVar25 + 0x54);
        (*(float *)((char *)frame_ + 16)) = *(float *)(iVar25 + 0x50);
        (*(undefined4 *)((char *)frame_ + 20)) = 0;
        iVar25 = *(int *)(uVar44 * 0x3c + iVar33 + 0x80);
        goto LAB_0009fb60;
      case 0xb:
        iVar30 = param_1 + uVar44 * 0x6c;
        iVar25 = *(int *)(uVar44 * 0x3c + iVar33 + 0x84) * 0x10;
        *(undefined4 *)(iVar36 + iVar25) = *(undefined4 *)(((unsigned char *)0x00001500) + iVar30 + 4);
        iVar25 = iVar36 + iVar25;
        *(undefined4 *)(iVar25 + 4) = *(undefined4 *)(((unsigned char *)0x00001500) + iVar30 + 4);
        *(undefined4 *)(iVar25 + 8) = *(undefined4 *)(((unsigned char *)0x00001500) + iVar30 + 4);
        *(undefined4 *)(iVar25 + 0xc) = *(undefined4 *)(((unsigned char *)0x00001500) + iVar30 + 4);
        uVar27 = piVar45[2];
        break;
      case 0xc:
        iVar30 = param_1 + uVar44 * 0x6c;
        iVar25 = *(int *)(uVar44 * 0x3c + iVar33 + 0x88) * 0x10;
        *(undefined4 *)(iVar36 + iVar25) = *(undefined4 *)(((unsigned char *)0x00001500) + iVar30 + 8);
        iVar25 = iVar36 + iVar25;
        *(undefined4 *)(iVar25 + 4) = *(undefined4 *)(((unsigned char *)0x00001500) + iVar30 + 8);
        *(undefined4 *)(iVar25 + 8) = *(undefined4 *)(((unsigned char *)0x00001500) + iVar30 + 8);
        *(undefined4 *)(iVar25 + 0xc) = *(undefined4 *)(((unsigned char *)0x00001500) + iVar30 + 8);
        uVar27 = piVar45[2];
        break;
      case 0xd:
        iVar30 = iVar35 + 0x24c0 + uVar44 * 0x80;
        iVar25 = *(int *)(uVar44 * 0x3c + iVar33 + 0x8c) * 0x10;
        *(undefined4 *)(iVar36 + iVar25) = *(undefined4 *)(iVar30 + 0x5c);
        iVar25 = iVar36 + iVar25;
        *(undefined4 *)(iVar25 + 4) = *(undefined4 *)(iVar30 + 0x5c);
        *(undefined4 *)(iVar25 + 8) = *(undefined4 *)(iVar30 + 0x5c);
        *(undefined4 *)(iVar25 + 0xc) = *(undefined4 *)(iVar30 + 0x5c);
        uVar27 = piVar45[2];
        break;
      case 0xe:
        if (uVar44 == 0) {
          uVar56 = *(undefined8 *)(iVar35 + 0x28f8);
          uVar46 = *(undefined8 *)(iVar35 + 0x28f0);
          iVar25 = *(int *)(iVar18 + 0x2d8);
        }
        else {
          uVar56 = *(undefined8 *)(((unsigned char *)0x00002b38) + iVar35);
          uVar46 = *(undefined8 *)(iVar35 + 0x2b30);
          iVar25 = *(int *)(uVar44 * 0x24 + iVar33 + 0x234);
        }
        goto LAB_0009fa50;
      case 0xf:
        if (uVar44 == 0) {
          uVar56 = *(undefined8 *)(iVar35 + 0x28c8);
          uVar46 = *(undefined8 *)(iVar35 + 0x28c0);
          iVar25 = *(int *)(iVar18 + 0x2dc);
        }
        else {
          uVar56 = *(undefined8 *)(iVar35 + 0x2b08);
          uVar46 = *(undefined8 *)(iVar35 + 0x2b00);
          iVar25 = *(int *)(uVar44 * 0x24 + iVar33 + 0x238);
        }
        goto LAB_0009fa50;
      case 0x10:
        if (uVar44 == 0) {
          uVar56 = *(undefined8 *)(iVar35 + 0x28d8);
          uVar46 = *(undefined8 *)(iVar35 + 0x28d0);
          iVar25 = *(int *)(iVar18 + 0x2e0);
        }
        else {
          uVar56 = *(undefined8 *)(iVar35 + 0x2b18);
          uVar46 = *(undefined8 *)(iVar35 + 0x2b10);
          iVar25 = *(int *)(uVar44 * 0x24 + iVar33 + 0x23c);
        }
        goto LAB_0009fa50;
      case 0x11:
        if (uVar44 == 0) {
          uVar56 = *(undefined8 *)(iVar35 + 0x28e8);
          uVar46 = *(undefined8 *)(iVar35 + 0x28e0);
          iVar25 = *(int *)(iVar18 + 0x2ec);
        }
        else {
          uVar56 = *(undefined8 *)(iVar35 + 0x2b28);
          uVar46 = *(undefined8 *)(iVar35 + 0x2b20);
          iVar25 = *(int *)(uVar44 * 0x24 + iVar33 + 0x248);
        }
        goto LAB_0009fa50;
      case 0x12:
        if (uVar44 == 0) {
          (*(float *)((char *)frame_ + 8)) = *(float *)(iVar35 + 0x28c0) * *(float *)(iVar35 + 0x24b0) +
                      *(float *)(iVar35 + 0x28f0);
          (*(float *)((char *)frame_ + 12)) = *(float *)(iVar35 + 0x28c4) * *(float *)(iVar35 + 0x24b4) +
                       *(float *)(iVar35 + 0x28f4);
          (*(float *)((char *)frame_ + 16)) = *(float *)(iVar35 + 0x28c8) * *(float *)(iVar35 + 0x24b8) +
                      *(float *)(iVar35 + 0x28f8);
        }
        else {
          (*(float *)((char *)frame_ + 8)) = *(float *)(iVar35 + 0x2b00) * *(float *)(iVar35 + 0x24b0) +
                      *(float *)(iVar35 + 0x2b30);
          (*(float *)((char *)frame_ + 12)) = *(float *)(iVar35 + 0x2b04) * *(float *)(iVar35 + 0x24b4) +
                       *(float *)(iVar35 + 0x2b34);
          (*(float *)((char *)frame_ + 16)) = *(float *)(iVar35 + 0x2b08) * *(float *)(iVar35 + 0x24b8) +
                      *(float *)(((unsigned char *)0x00002b38) + iVar35);
        }
        iVar25 = *(int *)(uVar44 * 0x24 + iVar33 + 0x254) * 0x10;
        *(ulonglong *)(iVar36 + iVar25) = CONCAT44((*(float *)((char *)frame_ + 8)),(*(float *)((char *)frame_ + 12)));
        *(ulonglong *)(iVar36 + iVar25 + 8) = CONCAT44((*(float *)((char *)frame_ + 16)),(*(undefined4 *)((char *)frame_ + 20)));
        uVar27 = piVar45[2];
        break;
      case 0x13:
        if (uVar44 == 0) {
          iVar25 = *(int *)(iVar18 + 800) * 0x10;
          *(undefined4 *)(iVar36 + iVar25) = *(undefined4 *)(iVar35 + 0x2900);
          iVar25 = iVar36 + iVar25;
          *(undefined4 *)(iVar25 + 4) = *(undefined4 *)(iVar35 + 0x2900);
          *(undefined4 *)(iVar25 + 8) = *(undefined4 *)(iVar35 + 0x2900);
          *(undefined4 *)(iVar25 + 0xc) = *(undefined4 *)(iVar35 + 0x2900);
          uVar27 = piVar45[2];
        }
        else {
          iVar25 = *(int *)(uVar44 * 4 + iVar33 + 0x27c) * 0x10;
          *(undefined4 *)(iVar36 + iVar25) = *(undefined4 *)(((unsigned char *)0x00002b40) + iVar35);
          iVar25 = iVar36 + iVar25;
          *(undefined4 *)(iVar25 + 4) = *(undefined4 *)(((unsigned char *)0x00002b40) + iVar35);
          *(undefined4 *)(iVar25 + 8) = *(undefined4 *)(((unsigned char *)0x00002b40) + iVar35);
          *(undefined4 *)(iVar25 + 0xc) = *(undefined4 *)(((unsigned char *)0x00002b40) + iVar35);
          uVar27 = piVar45[2];
        }
        break;
      case 0x14:
        uVar56 = *(undefined8 *)(iVar35 + 0x24b8);
        uVar46 = *(undefined8 *)(iVar35 + 0x24b0);
        iVar25 = *(int *)(iVar18 + 0x328);
        goto LAB_0009fa50;
      case 0x15:
        (*(float *)((char *)frame_ + 12)) = *(float *)(param_1 + 0x134);
        (*(float *)((char *)frame_ + 16)) = *(float *)(param_1 + 0x138);
        (*(undefined4 *)((char *)frame_ + 20)) = 0;
        (*(float *)((char *)frame_ + 8)) = 0.0;
        iVar25 = *(int *)(iVar18 + 0x330);
        goto LAB_0009fb60;
      case 0x16:
        (*(float *)((char *)frame_ + 8)) = *(float *)(param_1 + 400);
        (*(float *)((char *)frame_ + 12)) = *(float *)(param_1 + 0x194);
        (*(float *)((char *)frame_ + 16)) = *(float *)(param_1 + 0xf0);
        (*(undefined4 *)((char *)frame_ + 20)) = *(undefined4 *)(param_1 + 0x198);
        iVar25 = *(int *)(iVar18 + 0x334);
        goto LAB_0009fb60;
      case 0x17:
        (*(float *)((char *)frame_ + 8)) = *(float *)(param_1 + 0x118);
        (*(float *)((char *)frame_ + 12)) = *(float *)(param_1 + 0x114);
        (*(float *)((char *)frame_ + 16)) = *(float *)(param_1 + 0x110);
        (*(undefined4 *)((char *)frame_ + 20)) = 0;
        iVar25 = *(int *)(iVar18 + 0x338) * 0x10;
        *(ulonglong *)(iVar36 + iVar25) = CONCAT44((*(float *)((char *)frame_ + 8)),(*(float *)((char *)frame_ + 12)));
        *(ulonglong *)(iVar36 + iVar25 + 8) = (ulonglong)(uint)GH_F2U((*(float *)((char *)frame_ + 16))) << 0x20;
        uVar27 = piVar45[2];
        break;
      case 0x18:
        if ((*(uint *)(param_1 + 0x44) & 0x40000000) == 0) {
          (*(undefined4 *)((char *)frame_ + 96)) = 0x43300000;
          (*(undefined4 *)((char *)frame_ + 88)) = 0x43300000;
          (*(uint *)((char *)frame_ + 92)) = *(uint *)(param_1 + 0x108) ^ 0x80000000;
          (*(uint *)((char *)frame_ + 100)) = *(uint *)(param_1 + 0x10c) ^ 0x80000000;
          (*(float *)((char *)frame_ + 8)) = (float)((double)CONCAT44(0x43300000,(*(uint *)((char *)frame_ + 92))) - DOUBLE_001aa1e0);
          (*(float *)((char *)frame_ + 12)) = (float)((double)CONCAT44(0x43300000,(*(uint *)((char *)frame_ + 100))) - DOUBLE_001aa1e0);
        }
        else {
          (*(float *)((char *)frame_ + 8)) = *(float *)(param_1 + 0x100);
          (*(float *)((char *)frame_ + 12)) = *(float *)(param_1 + 0x104);
        }
        (*(undefined4 *)((char *)frame_ + 20)) = 0;
        (*(float *)((char *)frame_ + 16)) = 0.0;
        iVar25 = *(int *)(iVar18 + 0x340);
        goto LAB_0009fb60;
      case 0x19:
        iVar25 = *(int *)(iVar18 + 0x344) * 0x10;
        *(undefined4 *)(iVar36 + iVar25) = *(undefined4 *)(iVar35 + 0x24a4);
        iVar25 = iVar36 + iVar25;
        *(undefined4 *)(iVar25 + 4) = *(undefined4 *)(iVar35 + 0x24a4);
        *(undefined4 *)(iVar25 + 8) = *(undefined4 *)(iVar35 + 0x24a4);
        *(undefined4 *)(iVar25 + 0xc) = *(undefined4 *)(iVar35 + 0x24a4);
        uVar27 = piVar45[2];
        break;
      case 0x1a:
        uVar16 = uVar44 & 3;
        uVar27 = uVar44 >> 2;
        if (uVar16 == 1) {
          iVar25 = uVar27 * 0xcc + param_1;
          if (*(short *)(iVar25 + 0x4b0) == 0x2401) {
            puVar26 = (undefined8 *)(iVar25 + 0x4c4);
          }
          else {
            puVar26 = (undefined8 *)(uVar27 * 0xcc + param_1 + 0x4b4);
          }
        }
        else if (uVar16 == 0) {
          iVar25 = uVar27 * 0xcc + param_1;
          if (*(short *)(iVar25 + 0x48c) == 0x2401) {
            puVar26 = (undefined8 *)(iVar25 + 0x4a0);
          }
          else {
            puVar26 = (undefined8 *)(uVar27 * 0xcc + param_1 + 0x490);
          }
        }
        else if (uVar16 == 2) {
          iVar25 = uVar27 * 0xcc + param_1;
          if (*(short *)(iVar25 + 0x4d4) == 0x2401) {
            puVar26 = (undefined8 *)(iVar25 + 0x4e8);
          }
          else {
            puVar26 = (undefined8 *)(uVar27 * 0xcc + param_1 + 0x4d8);
          }
        }
        else {
          puVar26 = (undefined8 *)0x0;
          if (uVar16 == 3) {
            iVar25 = uVar27 * 0xcc + param_1;
            if (*(short *)(iVar25 + 0x4f8) == 0x2401) {
              puVar26 = (undefined8 *)(iVar25 + 0x50c);
            }
            else {
              puVar26 = (undefined8 *)(uVar27 * 0xcc + param_1 + 0x4fc);
            }
          }
        }
        uVar46 = puVar26[1];
        iVar25 = *(int *)(uVar44 * 4 + iVar33 + 0x2a4) * 0x10;
        *(undefined8 *)(iVar36 + iVar25) = *puVar26;
        *(undefined8 *)(iVar36 + iVar25 + 8) = uVar46;
        uVar27 = piVar45[2];
        break;
      case 0x1b:
        uVar56 = *(undefined8 *)(param_1 + 0x3a0);
        uVar46 = *(undefined8 *)(param_1 + 0x398);
        iVar25 = *(int *)(iVar18 + 0x32c);
LAB_0009fa50:
        *(undefined8 *)(iVar36 + iVar25 * 0x10) = uVar46;
        *(undefined8 *)(iVar36 + iVar25 * 0x10 + 8) = uVar56;
        uVar27 = piVar45[2];
        break;
      case 0x1c:
        iVar25 = iVar35 + 0x24c0 + (uVar44 >> 1) * 0x80;
        iVar30 = (uVar44 & 1) * 0x240 + iVar35;
        (*(float *)((char *)frame_ + 8)) = *(float *)(iVar25 + 0x10) * *(float *)(iVar30 + 0x28d0);
        (*(float *)((char *)frame_ + 12)) = *(float *)(iVar25 + 0x14) * *(float *)(iVar30 + 0x28d4);
        (*(float *)((char *)frame_ + 16)) = *(float *)(iVar25 + 0x18) * *(float *)(iVar30 + 0x28d8);
        (*(undefined4 *)((char *)frame_ + 20)) = *(undefined4 *)(iVar30 + 0x28dc);
        iVar25 = *(int *)(((uVar44 >> 1) * 0xf + (uVar44 & 1)) * 4 + iVar33 + 0x60);
        goto LAB_0009fb60;
      case 0x1d:
        iVar25 = iVar35 + 0x24c0 + (uVar44 >> 1) * 0x80;
        iVar30 = (uVar44 & 1) * 0x240 + iVar35;
        (*(float *)((char *)frame_ + 8)) = *(float *)(iVar25 + 0x20) * *(float *)(iVar30 + 0x28e0);
        (*(float *)((char *)frame_ + 12)) = *(float *)(iVar25 + 0x24) * *(float *)(iVar30 + 0x28e4);
        (*(undefined4 *)((char *)frame_ + 20)) = 0x3f800000;
        (*(float *)((char *)frame_ + 16)) = *(float *)(iVar25 + 0x28) * *(float *)(iVar30 + 0x28e8);
        iVar25 = *(int *)(((uVar44 >> 1) * 0xf + (uVar44 & 1)) * 4 + iVar33 + 0x6c);
LAB_0009fb60:
        *(ulonglong *)(iVar36 + iVar25 * 0x10) = CONCAT44((*(float *)((char *)frame_ + 8)),(*(float *)((char *)frame_ + 12)));
        *(ulonglong *)(iVar36 + iVar25 * 0x10 + 8) = CONCAT44((*(float *)((char *)frame_ + 16)),(*(undefined4 *)((char *)frame_ + 20)));
        uVar27 = piVar45[2];
      }
      uVar32 = uVar32 + 1;
      iVar34 = iVar34 + 4;
    } while (uVar32 < uVar27);
  }
  FUN_001a327c();
  return;
}

/* FUN_000a0290 @ 0xa0290 (96 bytes) */
int FUN_000a0290(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  int param_3;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  
  if (param_3 != 0) {
    uVar2 = 3;
    iVar3 = 0x48;
    bVar1 = true;
    while (uVar2 < *(uint *)(param_2 + 4)) {
      if (!bVar1) {
        return uVar2;
      }
      if (param_3 == *(int *)(iVar3 + *(int *)(param_2 + 8))) {
        bVar1 = false;
      }
      else {
        uVar2 = uVar2 + 1;
        iVar3 = iVar3 + 0x18;
      }
    }
    if (!bVar1) {
      return uVar2;
    }
  }
  return 0;
}

/* FUN_000a0300 @ 0xa0300 (80 bytes) */
int FUN_000a0300(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  *(undefined4 *)(((unsigned char *)0x00001124) + param_1) = 0xffffffff;
  **(undefined1 **)(((unsigned char *)0x00001128) + param_1) = 0;
  if (param_4 < 1) {
    return;
  }
  if (param_3 != 0x8875) {
    return;
  }
  if (param_2 != 0x8804) {
    return;
  }
  return FUN_0008df50(param_1,0x8875,param_4,param_5);
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

/* FUN_000a0380 @ 0xa0380 (476 bytes) */
int FUN_000a0380(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  int param_3;
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
  
  if ((param_2 == 0x8620) || (param_2 == 0x8804)) {
    iVar5 = *(int *)(((unsigned char *)0x0000112c) + param_1);
    a2 = param_3;
    iVar2 = ((int (*)())FUN_000a0290)(param_1,iVar5,param_3);
    if (iVar2 == 0) {
      if (param_3 != 0) {
        uVar1 = *(uint *)(iVar5 + 4);
        if ((uVar1 & 7) == 0) {
          iVar2 = (**(code **)(param_1 + 0xc))(uVar1 * 0x18 + 0xc0);
          if (iVar2 == 0) {
            return;
          }
          a2 = *(int *)(iVar5 + 4) * 0x18;
          (**(code **)(((unsigned char *)0x00001344) + param_1))(iVar2,*(undefined4 *)(iVar5 + 8),a2);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar5 + 8));
          *(int *)(iVar5 + 8) = iVar2;
          uVar1 = *(uint *)(iVar5 + 4);
        }
        ((int (*)())FUN_000a0350)(param_1,uVar1 * 0x18 + *(int *)(iVar5 + 8));
        *(int *)(*(int *)(iVar5 + 4) * 0x18 + *(int *)(iVar5 + 8) + 4) = param_2;
        *(int *)(*(int *)(iVar5 + 4) * 0x18 + *(int *)(iVar5 + 8)) = param_3;
        if (param_2 == 0x8804) {
          iVar2 = *(int *)(iVar5 + 8);
          iVar4 = *(int *)(iVar5 + 4) * 0x18 + iVar2;
          uVar3 = (**(code **)(param_1 + 0xc))(0x78,a1,a2,param_4,param_5,param_6,iVar2);
          *(undefined4 *)(iVar4 + 0x14) = uVar3;
          FUN_0008dc50(param_1,*(undefined4 *)
                                (*(int *)(iVar5 + 4) * 0x18 + *(int *)(iVar5 + 8) + 0x14));
          FUN_0008dbd0(param_1,*(undefined4 *)(iVar5 + 4),a2,param_4,param_5,param_6,iVar2,in_r10);
        }
        *(int *)(iVar5 + 4) = *(int *)(iVar5 + 4) + 1;
        return;
      }
    }
    else {
      param_7 = *(int *)(iVar5 + 8);
      if (param_2 != *(int *)(iVar2 * 0x18 + param_7 + 4)) {
        return;
      }
    }
    if (param_2 == 0x8804) {
      if (iVar2 == 0) {
        iVar2 = *(int *)(((unsigned char *)0x0000126c) + param_1);
      }
      FUN_0008dbd0(param_1,iVar2,a2,param_4,param_5,param_6,param_7,in_r10);
      return;
    }
  }
  return;
}

/* FUN_000a0570 @ 0xa0570 (124 bytes) */
int FUN_000a0570(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  if (0 < param_2) {
    piVar3 = *(int **)(((unsigned char *)0x0000112c) + param_1);
    iVar2 = 0;
    iVar4 = *piVar3;
    do {
      while (iVar1 = ((int (*)())FUN_000a0290)(param_1,piVar3,iVar4), iVar1 != 0) {
        iVar4 = iVar4 + 1;
      }
      iVar1 = iVar2 * 4;
      iVar2 = iVar2 + 1;
      *(int *)(param_3 + iVar1) = iVar4;
      iVar4 = iVar4 + 1;
    } while (param_2 != iVar2);
    *piVar3 = iVar4;
  }
  return;
}

/* FUN_000a05f0 @ 0xa05f0 (704 bytes) */
int FUN_000a05f0(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  uint *param_4;
{
  int iVar1;
  int iVar2;
  
  if (param_2 == 0x8620) {
    iVar2 = *(int *)(((unsigned char *)0x000014a0) + param_1);
  }
  else {
    if (param_2 != 0x8804) {
      return;
    }
    iVar2 = *(int *)(((unsigned char *)0x00001270) + param_1);
  }
  iVar1 = *(int *)(((unsigned char *)0x0000112c) + param_1);
  if (param_3 == 0x8627) {
    *param_4 = *(uint *)(iVar2 * 0x18 + *(int *)(iVar1 + 8) + 0xc);
    return;
  }
  if (param_3 == 0x8876) {
    *param_4 = *(uint *)(iVar2 * 0x18 + *(int *)(iVar1 + 8) + 8);
    return;
  }
  if (param_3 != 0x8677) {
    if (param_2 == 0x8804) {
      iVar2 = *(int *)(iVar2 * 0x18 + *(int *)(iVar1 + 8) + 0x14);
      switch(param_3) {
      case 0x8805:
        *param_4 = *(uint *)(*(int *)(iVar2 + 0x74) + 0x6c);
        return;
      case 0x8806:
        *param_4 = *(uint *)(*(int *)(iVar2 + 0x74) + 0x70);
        return;
      case 0x8807:
        *param_4 = *(uint *)(*(int *)(iVar2 + 0x74) + 0x74);
        return;
      case 0x8808:
        *param_4 = *(uint *)(iVar2 + 0x54);
        return;
      case 0x8809:
        *param_4 = *(uint *)(iVar2 + 0x58);
        return;
      case 0x880a:
        *param_4 = *(uint *)(iVar2 + 0x5c);
switchD_000a0718_caseD_8811:
        return;
      case 0x880b:
        *param_4 = *(uint *)(((unsigned char *)0x00001204) + param_1);
        return;
      case 0x880c:
        *param_4 = *(uint *)(((unsigned char *)0x00001208) + param_1);
        return;
      case 0x880d:
        *param_4 = *(uint *)((*(unsigned char *)0x0000120c) + param_1);
        return;
      case 0x880e:
        *param_4 = *(uint *)(((unsigned char *)0x00001210) + param_1);
        return;
      case 0x880f:
        *param_4 = *(uint *)(((unsigned char *)0x00001214) + param_1);
        return;
      case 0x8810:
        *param_4 = *(uint *)(((unsigned char *)0x00001218) + param_1);
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
        *param_4 = *(uint *)(*(int *)(iVar2 + 0x74) + 0x68);
        return;
      case 0x88a1:
        *param_4 = *(uint *)(((unsigned char *)0x000011d4) + param_1);
        return;
      case 0x88a2:
        *param_4 = *(uint *)(iVar2 + 0x50);
        return;
      case 0x88a3:
        *param_4 = *(uint *)(((unsigned char *)0x000011d8) + param_1);
        return;
      case 0x88a4:
        *param_4 = *(uint *)(*(int *)(iVar2 + 0x74) + 0x88);
        return;
      case 0x88a5:
        *param_4 = *(uint *)(((unsigned char *)0x000011dc) + param_1);
        return;
      case 0x88a6:
        *param_4 = *(uint *)(iVar2 + 0x68);
        return;
      case 0x88a7:
        *param_4 = *(uint *)(((unsigned char *)0x000011e0) + param_1);
        return;
      case 0x88a8:
        *param_4 = *(uint *)(*(int *)(iVar2 + 0x74) + 0x84);
        return;
      case 0x88a9:
        *param_4 = *(uint *)(((unsigned char *)0x000011e4) + param_1);
        return;
      case 0x88aa:
        *param_4 = *(uint *)(iVar2 + 100);
        return;
      case 0x88ab:
        *param_4 = *(uint *)(((unsigned char *)0x000011e8) + param_1);
        return;
      case 0x88ac:
        *param_4 = *(uint *)(*(int *)(iVar2 + 0x74) + 0x7c);
        return;
      case 0x88ad:
        *param_4 = *(uint *)(((unsigned char *)0x000011ec) + param_1);
        return;
      case 0x88ae:
        *param_4 = *(uint *)(iVar2 + 0x60);
        return;
      case 0x88af:
        *param_4 = *(uint *)(((unsigned char *)0x000011f0) + param_1);
        return;
      case 0x88b0:
      case 0x88b2:
        *param_4 = 0;
        return;
      case 0x88b1:
        *param_4 = *(uint *)(((unsigned char *)0x000011f4) + param_1);
        return;
      case 0x88b3:
        *param_4 = *(uint *)(((unsigned char *)0x000011f8) + param_1);
        return;
      case 0x88b4:
        *param_4 = *(uint *)(((unsigned char *)0x000011fc) + param_1);
        return;
      case 0x88b5:
        *param_4 = *(uint *)(((unsigned char *)0x00001200) + param_1);
        return;
      case 0x88b6:
        *param_4 = (uint)*(byte *)(iVar2 + 0x6c);
        return;
      default:
        return;
      }
    }
    return;
  }
  *param_4 = *(uint *)(iVar2 * 0x18 + *(int *)(iVar1 + 8));
  return;
}

/* FUN_000a0ba0 @ 0xa0ba0 (188 bytes) */
int FUN_000a0ba0(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  int iVar1;
  
  iVar1 = param_2[5];
  if (iVar1 != 0) {
    if (param_2[1] == 0x8804) {
      FUN_0008dda0(param_1,iVar1);
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

/* FUN_000a0c60 @ 0xa0c60 (260 bytes) */
int FUN_000a0c60(param_1)
  int param_1;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  FUN_0008dc40(param_1);
  if (*(int *)(((unsigned char *)0x00001128) + param_1) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(((unsigned char *)0x00001128) + param_1));
    *(undefined4 *)(((unsigned char *)0x00001128) + param_1) = 0;
  }
  *(int *)(*(int *)(((unsigned char *)0x0000112c) + param_1) + 0xc) =
       *(int *)(*(int *)(((unsigned char *)0x0000112c) + param_1) + 0xc) + -1;
  if (*(int *)(*(int *)(((unsigned char *)0x0000112c) + param_1) + 0xc) == 0) {
    iVar4 = *(int *)(((unsigned char *)0x0000112c) + param_1);
    if (*(int *)(iVar4 + 4) != 0) {
      uVar2 = 0;
      iVar3 = 0;
      do {
        uVar2 = uVar2 + 1;
        iVar1 = iVar3 + *(int *)(iVar4 + 8);
        iVar3 = iVar3 + 0x18;
        ((int (*)())FUN_000a0ba0)(param_1,iVar1);
      } while (uVar2 < *(uint *)(iVar4 + 4));
    }
    *(undefined4 *)(iVar4 + 4) = 0;
    if (*(int *)(iVar4 + 8) != 0) {
      (**(code **)(param_1 + 0x18))(*(int *)(iVar4 + 8));
      *(undefined4 *)(iVar4 + 8) = 0;
    }
    (**(code **)(param_1 + 0x18))(iVar4);
    *(undefined4 *)(((unsigned char *)0x0000112c) + param_1) = 0;
  }
  return;
}

/* FUN_000a0d70 @ 0xa0d70 (372 bytes) */
int FUN_000a0d70(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int *param_3;
{
  uint uVar1;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (0 < param_2) {
    iVar5 = *(int *)(((unsigned char *)0x0000112c) + param_1);
    iVar3 = 0;
    do {
      uVar1 = ((int (*)())FUN_000a0290)(param_1,iVar5,*param_3);
      if (uVar1 != 0) {
        iVar2 = *(int *)(iVar5 + 8);
        iVar4 = uVar1 * 0x18;
        if ((*(int *)(iVar2 + iVar4 + 4) == 0x8804) &&
           (*(int *)(*(int *)(((unsigned char *)0x00001270) + param_1) * 0x18 + iVar2) == *param_3)) {
          ((int (*)())FUN_000a0380)(param_1,0x8804,0,in_r6,in_r7,in_r8,*param_3);
          iVar2 = *(int *)(iVar5 + 8);
        }
        ((int (*)())FUN_000a0ba0)(param_1,iVar4 + iVar2);
        iVar4 = iVar4 + *(int *)(iVar5 + 8);
        _memmove(iVar4,iVar4 + 0x18,(*(int *)(iVar5 + 4) - uVar1) * 0x18 + -0x18);
        iVar4 = *(int *)(iVar5 + 4) + -1;
        *(int *)(iVar5 + 4) = iVar4;
        *(undefined4 *)(iVar4 * 0x18 + *(int *)(iVar5 + 8) + 8) = 0;
        *(undefined4 *)(*(int *)(iVar5 + 4) * 0x18 + *(int *)(iVar5 + 8)) = 0;
        *(undefined4 *)(*(int *)(iVar5 + 4) * 0x18 + *(int *)(iVar5 + 8) + 0xc) = 0xffffffff;
        *(undefined4 *)(*(int *)(iVar5 + 4) * 0x18 + *(int *)(iVar5 + 8) + 0x10) = 0;
        *(undefined4 *)(*(int *)(iVar5 + 4) * 0x18 + *(int *)(iVar5 + 8) + 4) = 0;
        *(undefined4 *)(*(int *)(iVar5 + 4) * 0x18 + *(int *)(iVar5 + 8) + 0x14) = 0;
        if (uVar1 < *(uint *)(((unsigned char *)0x00001270) + param_1)) {
          *(uint *)(((unsigned char *)0x00001270) + param_1) = *(uint *)(((unsigned char *)0x00001270) + param_1) - 1;
        }
      }
      iVar3 = iVar3 + 1;
      param_3 = param_3 + 1;
    } while (param_2 != iVar3);
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
  return FUN_0008f520(param_1);
}

/* FUN_000a0f80 @ 0xa0f80 (4 bytes) */
int FUN_000a0f80()
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
  *(code **)(((unsigned char *)0x00001160) + param_1) = FUN_000a0f80;
  *(code **)(((unsigned char *)0x0000115c) + param_1) = FUN_000a0f80;
  *(undefined **)(((unsigned char *)0x00001164) + param_1) = puVar2;
  FUN_000a21d0(param_1);
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

