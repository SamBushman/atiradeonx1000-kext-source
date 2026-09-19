#include "decls.h"

/* _FindMatchingAvailableCopy @ 0x97c06700 (164 bytes) */
int _FindMatchingAvailableCopy(param_1, param_2)
  int param_1;
  uint *param_2;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  if (*param_2 != 0) {
    iVar2 = 0;
    do {
      iVar1 = iVar2 + param_2[1];
      if ((((*(int *)(iVar2 + param_2[1]) != 0) && (*(int *)(iVar1 + 4) == *(int *)(param_1 + 4)))
          && (*(int *)(iVar1 + 8) == *(int *)(param_1 + 8))) &&
         (((*(int *)(iVar1 + 0xc) == *(int *)(param_1 + 0xc) &&
           (*(int *)(iVar1 + 0x10) == *(int *)(param_1 + 0x10))) &&
          ((*(int *)(iVar1 + 0x38) == *(int *)(param_1 + 0x38) &&
           (*(int *)(iVar1 + 0x3c) == *(int *)(param_1 + 0x3c))))))) {
        return iVar1;
      }
      uVar3 = uVar3 + 1;
      iVar2 = iVar2 + 0x48;
    } while (uVar3 < *param_2);
  }
  return 0;
}

/* _UpdateACUsingAvailableCopyTable @ 0x97c067a4 (444 bytes) */
int _UpdateACUsingAvailableCopyTable(param_1, param_2, param_3)
  int param_1;
  uint *param_2;
  undefined4 param_3;
{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  
  uVar7 = 0;
  if (*param_2 != 0) {
    piVar6 = (int *)param_2[1];
    iVar4 = 0;
    do {
      if (((*piVar6 != 0) && (piVar6[1] == *(int *)(param_1 + 0xc))) &&
         (piVar6[2] == *(int *)(param_1 + 0x10))) {
        uVar10 = *(uint *)(param_1 + 0x14);
        bVar1 = true;
        iVar5 = 0;
        uVar2 = 0;
        iVar8 = param_1;
        do {
          if (((uVar2 <= uVar10) && (*(int *)(iVar8 + 0x28) != 0)) &&
             (uVar2 = uVar2 + 1, piVar6[*(int *)(iVar8 + 0x18) + 10] != 1)) {
            bVar1 = false;
          }
          iVar5 = iVar5 + 1;
          iVar8 = iVar8 + 4;
          if (3 < iVar5) {
            if (bVar1) {
              *(int *)(param_1 + 0xc) = piVar6[3];
              *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(iVar4 + param_2[1] + 0x10);
              if (*(int *)(param_1 + 0x38) == 0) {
                iVar8 = *(int *)(iVar4 + param_2[1] + 0x38);
              }
              else {
                iVar8 = 1 - *(int *)(iVar4 + param_2[1] + 0x38);
              }
              *(int *)(param_1 + 0x38) = iVar8;
              iVar5 = 4;
              iVar8 = 0;
              uVar7 = 0;
              do {
                if ((uVar10 < uVar7) || (iVar9 = iVar8 * 4 + param_1, *(int *)(iVar9 + 0x28) == 0))
                {
                  *(int *)(iVar8 * 4 + param_1 + 0x18) = iVar8;
                }
                else {
                  uVar7 = uVar7 + 1;
                  *(undefined4 *)(iVar9 + 0x18) =
                       *(undefined4 *)(*(int *)(iVar9 + 0x18) * 4 + iVar4 + param_2[1] + 0x18);
                }
                iVar8 = iVar8 + 1;
                iVar5 = iVar5 + -1;
              } while (iVar5 != 0);
              uVar3 = _GetStreamArray(*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x10)
                                      ,param_3);
              *(undefined4 *)(param_1 + 0x44) = uVar3;
              return 1;
            }
            break;
          }
        } while (bVar1);
      }
      uVar7 = uVar7 + 1;
      iVar4 = iVar4 + 0x48;
      piVar6 = piVar6 + 0x12;
    } while (uVar7 < *param_2);
  }
  return 0;
}

/* _AddToAvailableCopyTable @ 0x97c06960 (1196 bytes) */
int _AddToAvailableCopyTable(param_1, param_2, param_3)
  uint *param_1;
  uint *param_2;
  undefined4 param_3;
{
  uint uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  void *pvVar6;
  void *pvVar7;
  uint uVar8;
  void *pvVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  undefined4 local_80;
  uint local_7c;
  int local_78;
  uint local_74;
  int local_70;
  uint local_6c;
  uint local_68 [4];
  uint local_58 [4];
  uint local_48 [8];
  
  iVar14 = 1;
  if (((((*param_1 >> 0x12 & 0xff) == 0) && (uVar12 = param_1[3], -1 < (int)uVar12)) &&
      (uVar11 = param_1[4], -1 < (int)uVar11)) &&
     ((uVar8 = param_1[2], (uVar8 >> 0x11 & 7) != (uVar11 >> 0x17 & 7) ||
      (*(short *)((int)param_1 + 0xe) != *(short *)((int)param_1 + 0x16))))) {
    uVar1 = param_1[1];
    if ((uVar1 & 0x10000000) != 0) {
      iVar14 = (uVar1 >> 0x1a & 3) + 1;
    }
    iVar15 = 0;
    if (iVar14 != 0) {
      do {
        local_78 = (uVar12 & 0xffff) + iVar15;
        local_6c = uVar1 >> 0x1a & 3;
        local_70 = (uint)*(ushort *)((int)param_1 + 0x16) + iVar15;
        local_74 = uVar11 >> 0x17 & 7;
        local_7c = uVar8 >> 0x11 & 7;
        local_48[0] = uVar11 >> 0x1b & 1;
        iVar16 = 4;
        local_80 = 1;
        iVar10 = 0;
        uVar12 = 0;
        puVar3 = &local_80;
        do {
          uVar13 = 0;
          uVar1 = 0;
          if (uVar12 <= local_6c) {
            if (iVar10 == 1) {
              uVar13 = uVar8 >> 0xe & 1;
              uVar1 = uVar8 >> 6 & 3;
            }
            else if (iVar10 < 2) {
              if (iVar10 == 0) {
                uVar13 = uVar8 >> 0xd & 1;
                uVar1 = uVar8 >> 8 & 3;
              }
            }
            else if (iVar10 == 2) {
              uVar13 = uVar8 >> 0xf & 1;
              uVar1 = uVar8 >> 4 & 3;
            }
            else if (iVar10 == 3) {
              uVar13 = uVar8 >> 0x10 & 1;
              uVar1 = uVar8 >> 2 & 3;
            }
          }
          uVar12 = uVar12 + uVar13;
          puVar3[10] = uVar13;
          if (uVar1 == 1) {
            puVar3[6] = uVar11 >> 0x13 & 3;
          }
          else if (uVar1 == 0) {
            puVar3[6] = uVar11 >> 0x15 & 3;
          }
          else if (uVar1 == 2) {
            puVar3[6] = uVar11 >> 0x11 & 3;
          }
          else if (uVar1 == 3) {
            puVar3[6] = uVar11 >> 0xf & 3;
          }
          iVar10 = iVar10 + 1;
          puVar3 = puVar3 + 1;
          iVar16 = iVar16 + -1;
        } while (iVar16 != 0);
        if (iVar10 < 4) {
          piVar4 = &local_70;
          iVar10 = 0;
          do {
            piVar4[10] = 0;
            piVar4[6] = 0;
            piVar4 = piVar4 + 1;
            iVar10 = iVar10 + -1;
          } while (iVar10 != 0);
        }
        local_48[2] = _GetStreamArray(local_7c,local_78,param_3);
        local_48[3] = _GetStreamArray(local_74,local_70,param_3);
        if (((param_1[1] & 0x10000000) != 0) && (iVar15 == 0)) {
          local_48[1] = 1;
          iVar10 = ((int (*)())_FindMatchingAvailableCopy)(&local_80,param_2);
          if (iVar10 == 0) {
            uVar12 = *param_2;
            if ((uVar12 & 7) == 0) {
              uVar11 = 0;
              pvVar7 = _malloc(uVar12 * 0x48 + 0x240);
              _memset(pvVar7,0,*param_2 * 0x48 + 0x240);
              uVar12 = 0;
              if (*param_2 != 0) {
                iVar10 = 0;
                do {
                  pvVar6 = (void *)(iVar10 + (int)pvVar7);
                  pvVar9 = (void *)(iVar10 + param_2[1]);
                  iVar10 = iVar10 + 0x48;
                  _memcpy(pvVar6,pvVar9,0x48);
                  uVar12 = *param_2;
                  uVar11 = uVar11 + 1;
                } while (uVar11 < uVar12);
              }
              if ((void *)param_2[1] != (void *)0x0) {
                _free((void *)param_2[1]);
                uVar12 = *param_2;
              }
              param_2[1] = (uint)pvVar7;
            }
            _memcpy((void *)(uVar12 * 0x48 + param_2[1]),&local_80,0x48);
            *param_2 = *param_2 + 1;
          }
          else {
            iVar17 = 4;
            puVar3 = &local_80;
            iVar16 = iVar10;
            do {
              if ((puVar3[10] == 1) && (*(int *)(iVar16 + 0x28) == 0)) {
                iVar5 = *(int *)(iVar10 + 0x14);
                uVar2 = puVar3[6];
                *(undefined4 *)(iVar16 + 0x28) = 1;
                *(int *)(iVar10 + 0x14) = iVar5 + 1;
LAB_97c06bf0:
                *(undefined4 *)(iVar16 + 0x18) = uVar2;
              }
              else if (puVar3[10] == 1) {
                uVar2 = puVar3[6];
                goto LAB_97c06bf0;
              }
              iVar16 = iVar16 + 4;
              puVar3 = puVar3 + 1;
              iVar17 = iVar17 + -1;
            } while (iVar17 != 0);
          }
        }
        local_48[1] = 0;
        do {
          iVar10 = ((int (*)())_UpdateACUsingAvailableCopyTable)(&local_80,param_2,param_3);
        } while (iVar10 != 0);
        iVar10 = ((int (*)())_FindMatchingAvailableCopy)(&local_80,param_2);
        if (iVar10 == 0) {
          uVar12 = *param_2;
          if ((uVar12 & 7) == 0) {
            uVar11 = 0;
            pvVar7 = _malloc(uVar12 * 0x48 + 0x240);
            _memset(pvVar7,0,*param_2 * 0x48 + 0x240);
            uVar12 = 0;
            if (*param_2 != 0) {
              iVar10 = 0;
              do {
                uVar11 = uVar11 + 1;
                _memcpy((void *)(iVar10 + (int)pvVar7),(void *)(iVar10 + param_2[1]),0x48);
                uVar12 = *param_2;
                iVar10 = iVar10 + 0x48;
              } while (uVar11 < uVar12);
            }
            if ((void *)param_2[1] != (void *)0x0) {
              _free((void *)param_2[1]);
              uVar12 = *param_2;
            }
            param_2[1] = (uint)pvVar7;
          }
          _memcpy((void *)(uVar12 * 0x48 + param_2[1]),&local_80,0x48);
          *param_2 = *param_2 + 1;
        }
        else {
          iVar17 = 4;
          puVar3 = &local_80;
          iVar16 = iVar10;
          do {
            if ((puVar3[10] == 1) && (*(int *)(iVar16 + 0x28) == 0)) {
              iVar5 = *(int *)(iVar10 + 0x14);
              uVar2 = puVar3[6];
              *(undefined4 *)(iVar16 + 0x28) = 1;
              *(int *)(iVar10 + 0x14) = iVar5 + 1;
LAB_97c06d30:
              *(undefined4 *)(iVar16 + 0x18) = uVar2;
            }
            else if (puVar3[10] == 1) {
              uVar2 = puVar3[6];
              goto LAB_97c06d30;
            }
            iVar16 = iVar16 + 4;
            puVar3 = puVar3 + 1;
            iVar17 = iVar17 + -1;
          } while (iVar17 != 0);
        }
        iVar15 = iVar15 + 1;
        if (iVar14 <= iVar15) {
          return;
        }
        uVar12 = param_1[3];
        uVar11 = param_1[4];
        uVar8 = param_1[2];
        uVar1 = param_1[1];
      } while( true );
    }
  }
  return;
}

/* _FindInAvailableCopyTableSource @ 0x97c06e0c (304 bytes) */
int _FindInAvailableCopyTableSource(param_1, param_2, param_3)
  uint param_1;
  uint param_2;
  uint *param_3;
{
  bool bVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  
  bVar1 = false;
  uVar4 = 0;
  if (*param_3 != 0) {
    piVar3 = (int *)param_3[1];
    do {
      if (((((*piVar3 != 0) && (piVar3[1] == (param_1 >> 0x17 & 7))) &&
           (piVar3[2] == (param_2 & 0xffff))) &&
          ((piVar3[0xf] == (param_1 >> 0xe & 1) &&
           (uVar2 = param_1 >> 0xc & 3, uVar2 <= (uint)piVar3[5])))) && (-1 < (int)param_1)) {
        bVar1 = true;
        if (uVar2 == 1) {
LAB_97c06ed8:
          if (*(int *)((int)piVar3 + (param_1 >> 0x11 & 0xc) + 0x28) == 1) {
LAB_97c06eec:
            if (*(int *)((int)piVar3 + (param_1 >> 0x13 & 0xc) + 0x28) == 1) goto LAB_97c06f04;
          }
        }
        else {
          if (uVar2 < 2) {
            if (uVar2 != 0) goto LAB_97c06f04;
            goto LAB_97c06eec;
          }
          if (uVar2 == 2) {
LAB_97c06ec4:
            if (*(int *)((int)piVar3 + (param_1 >> 0xf & 0xc) + 0x28) == 1) goto LAB_97c06ed8;
          }
          else {
            if (uVar2 != 3) goto LAB_97c06f04;
            if (*(int *)((int)piVar3 + (param_1 >> 0xd & 0xc) + 0x28) == 1) goto LAB_97c06ec4;
          }
        }
        bVar1 = false;
      }
LAB_97c06f04:
      uVar4 = uVar4 + 1;
      piVar3 = piVar3 + 0x12;
    } while ((uVar4 < *param_3) && (!bVar1));
  }
  if (bVar1) {
    return param_3[1] + (uVar4 - 1) * 0x48;
  }
  return 0;
}

/* _CheckRemoveAvailableCopyTable @ 0x97c06f3c (756 bytes) */
int _CheckRemoveAvailableCopyTable(param_1, param_2, param_3, param_4, param_5, param_6)
  uint param_1;
  uint param_2;
  int param_3;
  int param_4;
  uint *param_5;
  undefined4 param_6;
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uStack00000018;
  uint uStack0000001c;
  
  iVar4 = -1;
  uStack00000018 = param_1;
  uStack0000001c = param_2;
  if ((int)param_2 < 0) {
    iVar4 = _GetStreamArray(param_1 >> 0x11 & 7,(param_2 & 0xffff) + param_3,param_6);
  }
  uVar6 = *param_5;
  uVar5 = 0;
  if (uVar6 != 0) {
    iVar9 = 0;
    do {
      uVar10 = param_5[1];
      if (*(int *)(iVar9 + uVar10) != 0) {
        bVar1 = false;
        if ((iVar4 < 0) || (iVar4 != *(int *)(iVar9 + uVar10 + 0x40))) {
          iVar7 = iVar9 + uVar10;
          if ((*(int *)(iVar7 + 0x3c) != 0) &&
             (*(uint *)(iVar7 + 4) == (uStack00000018 >> 0x11 & 7))) {
            uVar6 = (uStack0000001c & 0xffff) + param_3;
            if ((*(uint *)(iVar7 + 8) <= uVar6) &&
               (uVar6 <= *(uint *)(iVar7 + 8) + *(int *)(iVar7 + 0x14))) goto LAB_97c070dc;
          }
          iVar7 = iVar9 + uVar10;
          if ((*(uint *)(iVar7 + 4) == (uStack00000018 >> 0x11 & 7)) &&
             ((*(int *)(iVar7 + 8) == (uStack0000001c & 0xffff) + param_3 &&
              (*(int *)(iVar7 + 0x3c) == param_4)))) {
            piVar3 = (int *)(iVar7 + 0x28);
            iVar7 = 0;
            do {
              iVar8 = *piVar3;
              piVar3 = piVar3 + 1;
              if (iVar8 == 1) {
                if (iVar7 == 1) {
                  uVar6 = uStack00000018 >> 0xe & 1;
                }
                else if (iVar7 < 2) {
                  uVar6 = uStack00000018 >> 0xd & 1;
                  if (iVar7 != 0) goto LAB_97c070c8;
                }
                else if (iVar7 == 2) {
                  uVar6 = uStack00000018 >> 0xf & 1;
                }
                else {
                  if (iVar7 != 3) goto LAB_97c070c8;
                  uVar6 = uStack00000018 >> 0x10 & 1;
                }
                if (uVar6 == 1) {
                  bVar1 = true;
                  break;
                }
              }
LAB_97c070c8:
              iVar7 = iVar7 + 1;
            } while (iVar7 <= (int)(uStack00000018 >> 10 & 3));
            if (bVar1) goto LAB_97c070dc;
          }
        }
        else {
LAB_97c070dc:
          *(undefined4 *)(iVar9 + uVar10) = 0;
          uVar10 = param_5[1];
        }
        bVar1 = false;
        if ((iVar4 < 0) || (iVar4 != *(int *)(iVar9 + uVar10 + 0x44))) {
          iVar7 = iVar9 + uVar10;
          if ((*(int *)(iVar7 + 0x3c) != 0) &&
             (*(uint *)(iVar7 + 0xc) == (uStack00000018 >> 0x11 & 7))) {
            uVar6 = (uStack0000001c & 0xffff) + param_3;
            if ((*(uint *)(iVar7 + 0x10) <= uVar6) &&
               (uVar6 <= *(uint *)(iVar7 + 0x10) + *(int *)(iVar7 + 0x14))) goto LAB_97c07204;
          }
          iVar7 = iVar9 + uVar10;
          if ((*(uint *)(iVar7 + 0xc) == (uStack00000018 >> 0x11 & 7)) &&
             ((*(int *)(iVar7 + 0x10) == (uStack0000001c & 0xffff) + param_3 &&
              (*(int *)(iVar7 + 0x3c) == param_4)))) {
            iVar8 = 0;
            do {
              if (*(int *)(iVar7 + 0x28) == 1) {
                iVar2 = *(int *)(iVar7 + 0x18);
                if (iVar2 == 1) {
                  uVar6 = uStack00000018 >> 0xe & 1;
                }
                else {
                  uVar6 = uStack00000018 >> 0xd & 1;
                  if (iVar2 != 0) {
                    if (iVar2 == 2) {
                      uVar6 = uStack00000018 >> 0xf & 1;
                    }
                    else {
                      if (iVar2 != 3) goto LAB_97c071ec;
                      uVar6 = uStack00000018 >> 0x10 & 1;
                    }
                  }
                }
                if (uVar6 == 1) {
                  bVar1 = true;
                  break;
                }
              }
LAB_97c071ec:
              iVar8 = iVar8 + 1;
              iVar7 = iVar7 + 4;
            } while (iVar8 <= (int)(uStack00000018 >> 10 & 3));
          }
          if (bVar1) goto LAB_97c07204;
        }
        else {
LAB_97c07204:
          *(undefined4 *)(iVar9 + uVar10) = 0;
        }
        uVar6 = *param_5;
      }
      uVar5 = uVar5 + 1;
      iVar9 = iVar9 + 0x48;
    } while (uVar5 < uVar6);
  }
  return;
}

/* _ReplaceUsingAvailableCopyTable @ 0x97c07230 (580 bytes) */
int _ReplaceUsingAvailableCopyTable(param_1, param_2)
  uint *param_1;
  undefined4 param_2;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  
  iVar4 = 0;
  puVar5 = param_1;
  if (*param_1 >> 0x1d != 0) {
    do {
      iVar2 = ((int (*)())_FindInAvailableCopyTableSource)(puVar5[4],puVar5[5],param_2);
      if (iVar2 != 0) {
        uVar3 = puVar5[4];
        uVar1 = (*(uint *)(iVar2 + 0xc) & 7) << 0x17;
        puVar5[4] = uVar1 | uVar3 & 0xfc7fffff;
        *(undefined2 *)((int)puVar5 + 0x16) = *(undefined2 *)(iVar2 + 0x12);
        if ((uVar3 & 0x8000000) == 0) {
          puVar5[4] = (*(uint *)(iVar2 + 0x38) & 1) << 0x1b | uVar1 | uVar3 & 0xf47fffff;
        }
        else {
          puVar5[4] = (1 - *(int *)(iVar2 + 0x38)) * 0x8000000 & 0x8000000U |
                      uVar1 | uVar3 & 0xf47fffff;
        }
        uVar1 = puVar5[4];
        uVar3 = uVar1 >> 0xc & 3;
        if (uVar3 == 1) goto LAB_97c07398;
        if (uVar3 < 2) {
          if (uVar3 != 0) goto LAB_97c07448;
        }
        else {
          if (uVar3 == 2) goto LAB_97c07340;
          if (uVar3 != 3) goto LAB_97c07448;
          uVar3 = uVar1 >> 0xf & 3;
          if (uVar3 == 1) {
            uVar3 = *(uint *)(iVar2 + 0x1c);
LAB_97c07338:
            puVar5[4] = (uVar3 & 3) << 0xf | uVar1 & 0xfffe7fff;
          }
          else {
            if (1 < uVar3) {
              if (uVar3 == 2) {
                uVar3 = *(uint *)(iVar2 + 0x20);
              }
              else {
                if (uVar3 != 3) goto LAB_97c07340;
                uVar3 = *(uint *)(iVar2 + 0x24);
              }
              goto LAB_97c07338;
            }
            if (uVar3 == 0) {
              uVar3 = *(uint *)(iVar2 + 0x18);
              goto LAB_97c07338;
            }
          }
LAB_97c07340:
          uVar1 = puVar5[4] >> 0x11 & 3;
          if (uVar1 == 1) {
            uVar1 = *(uint *)(iVar2 + 0x1c);
LAB_97c07390:
            puVar5[4] = (uVar1 & 3) << 0x11 | puVar5[4] & 0xfff9ffff;
          }
          else {
            if (1 < uVar1) {
              if (uVar1 == 2) {
                uVar1 = *(uint *)(iVar2 + 0x20);
              }
              else {
                if (uVar1 != 3) goto LAB_97c07398;
                uVar1 = *(uint *)(iVar2 + 0x24);
              }
              goto LAB_97c07390;
            }
            if (uVar1 == 0) {
              uVar1 = *(uint *)(iVar2 + 0x18);
              goto LAB_97c07390;
            }
          }
LAB_97c07398:
          uVar1 = puVar5[4] >> 0x13 & 3;
          if (uVar1 == 1) {
            uVar1 = *(uint *)(iVar2 + 0x1c);
          }
          else if (uVar1 < 2) {
            if (uVar1 != 0) goto LAB_97c073f0;
            uVar1 = *(uint *)(iVar2 + 0x18);
          }
          else if (uVar1 == 2) {
            uVar1 = *(uint *)(iVar2 + 0x20);
          }
          else {
            if (uVar1 != 3) goto LAB_97c073f0;
            uVar1 = *(uint *)(iVar2 + 0x24);
          }
          puVar5[4] = (uVar1 & 3) << 0x13 | puVar5[4] & 0xffe7ffff;
        }
LAB_97c073f0:
        uVar1 = puVar5[4] >> 0x15 & 3;
        if (uVar1 == 1) {
          uVar1 = *(uint *)(iVar2 + 0x1c);
        }
        else if (uVar1 < 2) {
          if (uVar1 != 0) goto LAB_97c07448;
          uVar1 = *(uint *)(iVar2 + 0x18);
        }
        else if (uVar1 == 2) {
          uVar1 = *(uint *)(iVar2 + 0x20);
        }
        else {
          if (uVar1 != 3) goto LAB_97c07448;
          uVar1 = *(uint *)(iVar2 + 0x24);
        }
        puVar5[4] = (uVar1 & 3) << 0x15 | puVar5[4] & 0xff9fffff;
      }
LAB_97c07448:
      iVar4 = iVar4 + 1;
      puVar5 = puVar5 + 2;
    } while (iVar4 < (int)(*param_1 >> 0x1d));
  }
  return;
}

/* _RemoveFromAvailableCopyTable @ 0x97c07474 (152 bytes) */
int _RemoveFromAvailableCopyTable(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = *(uint *)(param_1 + 8);
  iVar2 = 1;
  if ((uVar1 & 0x1000) != 0) {
    iVar2 = (uVar1 >> 10 & 3) + 1;
    ((int (*)())_CheckRemoveAvailableCopyTable)(uVar1,*(undefined4 *)(param_1 + 0xc),0,1,param_2,param_3);
  }
  iVar3 = 0;
  if (iVar2 != 0) {
    do {
      iVar4 = iVar3 + 1;
      ((int (*)())_CheckRemoveAvailableCopyTable)(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),iVar3,0,param_2,param_3
                );
      iVar3 = iVar4;
    } while (iVar4 < iVar2);
  }
  return;
}

/* _CopyPropagateOperation @ 0x97c0750c (80 bytes) */
int _CopyPropagateOperation(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_ReplaceUsingAvailableCopyTable)();
  ((int (*)())_RemoveFromAvailableCopyTable)(param_1,param_2,param_3);
  ((int (*)())_AddToAvailableCopyTable)(param_1,param_2,param_3);
  return;
}

/* _EndLocalAvailableCopyList @ 0x97c0755c (132 bytes) */
int _EndLocalAvailableCopyList(param_1)
  uint *param_1;
{
  uint uVar1;
  
  uVar1 = *param_1 >> 0x12 & 0xff;
  if (((((uVar1 != 0x4c) && (uVar1 != 0x55)) && (uVar1 != 0x58)) &&
      ((((uVar1 != 0x6a && (uVar1 != 0x6b)) &&
        ((uVar1 != 0x59 && ((uVar1 != 0x69 && (uVar1 != 0x54)))))) && (uVar1 != 0x4d)))) &&
     ((((uVar1 != 0x4b && (uVar1 != 0x57)) && (uVar1 != 0x5b)) &&
      ((uVar1 != 0x56 && (uVar1 != 0x5a)))))) {
    return 0;
  }
  return 1;
}

/* _LocalCopyPropagator @ 0x97c075e0 (236 bytes) */
int _LocalCopyPropagator(param_1)
  int param_1;
{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  iVar4 = **(int **)(param_1 + 0x20);
  puVar1 = _malloc(8);
  puVar1[1] = 0;
  *puVar1 = 0;
  for (; iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    iVar2 = ((int (*)())_EndLocalAvailableCopyList)(iVar4 + 0xc,puVar1,param_1);
    if ((iVar2 != 0) && (uVar5 = 0, *puVar1 != 0)) {
      iVar2 = 0;
      do {
        iVar3 = _IsParamSampler(*(undefined4 *)(iVar2 + puVar1[1] + 0xc),
                                *(undefined4 *)(iVar2 + puVar1[1] + 0x10),param_1);
        if (iVar3 == 0) {
          *(undefined4 *)(iVar2 + puVar1[1]) = 0;
        }
        uVar5 = uVar5 + 1;
        iVar2 = iVar2 + 0x48;
      } while (uVar5 < *puVar1);
    }
    ((int (*)())_CopyPropagateOperation)(iVar4 + 0xc,puVar1,param_1);
  }
  if ((void *)puVar1[1] != (void *)0x0) {
    _free((void *)puVar1[1]);
  }
  _free(puVar1);
  return;
}

/* _EmbedSamplerParamIndices @ 0x97c076cc (144 bytes) */
int _EmbedSamplerParamIndices(param_1)
  int param_1;
{
  bool bVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = **(int **)(param_1 + 0x20);
  if (iVar5 == 0) {
    return;
  }
  do {
    uVar3 = *(uint *)(iVar5 + 0xc) >> 0x12 & 0xff;
    if ((0x41 < uVar3) && ((uVar3 < 0x48 || (uVar3 == 0x62)))) {
      iVar4 = **(int **)(param_1 + 0x10);
      bVar1 = iVar4 == 0;
      if (!bVar1) {
        sVar2 = *(short *)(iVar4 + 0x12);
        while (*(short *)(iVar5 + 0x2a) != sVar2) {
          iVar4 = *(int *)(iVar4 + 8);
          if (iVar4 == 0) goto LAB_97c0774c;
          bVar1 = false;
          sVar2 = *(short *)(iVar4 + 0x12);
        }
        if ((!bVar1) && ((*(uint *)(iVar4 + 0xc) >> 0x10 & 0x1f) == 1)) {
          *(short *)(iVar5 + 0x32) = (short)*(uint *)(iVar4 + 0xc);
        }
      }
    }
LAB_97c0774c:
    iVar5 = *(int *)(iVar5 + 8);
    if (iVar5 == 0) {
      return;
    }
  } while( true );
}

/* _LinearizeFixOutputReads @ 0x97c0775c (916 bytes) */
int _LinearizeFixOutputReads(param_1)
  int param_1;
{
  ushort uVar1;
  int iVar2;
  int *piVar3;
  short sVar4;
  bool bVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint local_80;
  undefined4 local_7c;
  int local_78;
  int local_74;
  undefined4 local_70;
  uint local_6c;
  uint local_68;
  uint local_64;
  uint local_60;
  uint local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  
  iVar9 = **(int **)(param_1 + 0x1c);
  do {
    if (iVar9 == 0) {
      return;
    }
    bVar5 = false;
    uVar1 = *(ushort *)(iVar9 + 0x12);
    local_7c = **(int **)(param_1 + 0x20);
    if (local_7c != 0) {
      do {
        uVar6 = 0;
        uVar7 = *(uint *)(local_7c + 0xc) >> 0x1d;
        if (uVar7 != 0) {
          iVar2 = local_7c + 0x10;
          do {
            if ((((*(uint *)(iVar2 + 0xc) >> 0x17 & 7) == 3) && (*(ushort *)(iVar2 + 0x12) == uVar1)
                ) || (((*(uint *)(local_7c + 0xc) >> 0x12 & 0xff) == 0x6d &&
                      (((*(uint *)(local_7c + 0x14) >> 0x11 & 7) == 3 &&
                       (*(ushort *)(local_7c + 0x1a) == uVar1)))))) {
              bVar5 = true;
              break;
            }
            if (bVar5) break;
            uVar6 = uVar6 + 1;
            iVar2 = iVar2 + 8;
          } while (uVar6 < uVar7);
        }
        local_7c = *(int *)(local_7c + 8);
      } while (local_7c != 0);
      if (bVar5) {
        local_80 = 0;
        local_78 = local_7c;
        local_74 = local_7c;
        sVar4 = _PPStreamChunkListGetMaxIndex(*(undefined4 *)(param_1 + 4));
        local_7c = CONCAT22((*(unsigned short *)((unsigned char *)&(local_7c) + 0)),sVar4 + 1);
        local_80 = (*(uint *)(iVar9 + 0xc) >> 0x18 & 3) << 0x18 |
                   (*(uint *)(iVar9 + 0xc) >> 0x1a & 7) << 0x1a |
                   *(uint *)(iVar9 + 0xc) & 0xe0000000 | local_80 & 0xffffff;
        _PPStreamAddTempUsage(param_1,&local_80);
        piVar3 = *(int **)(param_1 + 0x20);
        iVar2 = *piVar3;
        if (iVar2 != 0) {
          do {
            if (((*(uint *)(iVar2 + 0x14) >> 0x11 & 7) == 3) && (*(ushort *)(iVar2 + 0x1a) == uVar1)
               ) {
              *(uint *)(iVar2 + 0x14) = *(uint *)(iVar2 + 0x14) & 0xfff1ffff | 0x20000;
              *(undefined2 *)(iVar2 + 0x1a) = (*(unsigned short *)((unsigned char *)&(local_7c) + 2));
            }
            uVar6 = *(uint *)(iVar2 + 0xc);
            uVar7 = 0;
            if (uVar6 >> 0x1d != 0) {
              iVar8 = iVar2 + 0x10;
              do {
                if (((*(uint *)(iVar8 + 0xc) >> 0x17 & 7) == 3) &&
                   (*(ushort *)(iVar8 + 0x12) == uVar1)) {
                  *(uint *)(iVar8 + 0xc) = *(uint *)(iVar8 + 0xc) & 0xfc7fffff | 0x800000;
                  *(undefined2 *)(iVar8 + 0x12) = (*(unsigned short *)((unsigned char *)&(local_7c) + 2));
                  uVar6 = *(uint *)(iVar2 + 0xc);
                }
                uVar7 = uVar7 + 1;
                iVar8 = iVar8 + 8;
              } while (uVar7 < uVar6 >> 0x1d);
            }
            iVar2 = *(int *)(iVar2 + 8);
          } while (iVar2 != 0);
          piVar3 = *(int **)(param_1 + 0x20);
        }
        for (iVar2 = *piVar3; iVar2 != 0; iVar2 = *(int *)(iVar2 + 8)) {
          if ((*(uint *)(iVar2 + 0xc) >> 0x12 & 0xff) == 0x4d) {
            uVar7 = local_80 >> 0x18 & 3;
            local_68 = uVar7 << 10 | 0x6c;
            local_58 = 0;
            local_54 = 0;
            local_50 = 0;
            local_4c = 0;
            local_48 = 0;
            local_44 = 0;
            local_40 = *(undefined4 *)(iVar2 + 0x3c);
            local_70 = 0x20000000;
            local_3c = 0;
            if (uVar7 == 1) {
LAB_97c07a24:
              local_68 = local_68 | 0x4000;
LAB_97c07a2c:
              local_68 = local_68 | 0x2000;
            }
            else {
              if (1 < uVar7) {
                if (uVar7 != 2) {
                  if (uVar7 != 3) goto LAB_97c07a34;
                  local_68 = 0x10c6c;
                }
                local_68 = local_68 | 0x8000;
                goto LAB_97c07a24;
              }
              if (uVar7 == 0) goto LAB_97c07a2c;
            }
LAB_97c07a34:
            uVar7 = local_80 >> 0x18 & 3;
            local_6c = (local_80 >> 0x1d & 3) << 0x12 |
                       uVar7 << 0x1a | (local_80 >> 0x1a & 7) << 0x17;
            local_68 = local_68 | 0x60000;
            local_60 = uVar7 << 0xc | 0x8d8000;
            local_5c = local_7c & 0xffff;
            local_64 = (uint)uVar1;
            iVar8 = _PPStreamInsertOperationAfterChunk
                              (param_1,&local_70,0,0,*(undefined4 *)(iVar2 + 4));
            _PPStreamChangeBranchTargets
                      (param_1,*(uint *)(iVar2 + 0xc) & 0x3ffff,*(uint *)(iVar8 + 0xc) & 0x3ffff);
          }
        }
      }
    }
    iVar9 = *(int *)(iVar9 + 8);
  } while( true );
}

/* _glpPPShaderLinearizeStreamMgr @ 0x97c07af0 (320 bytes) */
int _glpPPShaderLinearizeStreamMgr(param_1, param_2)
  undefined4 param_1;
  uint param_2;
{
  undefined4 uVar1;
  
  if ((param_2 & 1) != 0) {
    _InlineFunctionsBranch();
  }
  if ((param_2 & 0x102) != 0) {
    _DetectConstantLoopsSimple(param_1);
    _UnrollConstantLoopsSimple(param_1,param_2 & 0x100);
  }
  if ((param_2 & 4) != 0) {
    _PPStreamPackIndices(param_1);
    _FlattenIfs(param_1);
  }
  if ((param_2 & 0x106) != 0) {
    ((int (*)())_LinearizeFixOutputReads)(param_1);
  }
  if ((param_2 & 0x80) != 0) {
    _ConstantPropagateFold(param_1);
  }
  if ((param_2 & 8) != 0) {
    ((int (*)())_LocalCopyPropagator)(param_1);
  }
  if ((param_2 & 0x10) != 0) {
    ((int (*)())_EmbedSamplerParamIndices)(param_1);
  }
  uVar1 = 0;
  if (param_2 != 0) {
    _PPStreamPackIndices(param_1);
    uVar1 = _ProgramNew(param_1);
    _Registerify();
    _Blockify(uVar1);
  }
  if ((param_2 & 0x60) != 0) {
    ((int (*)())_BuildGenKill)(uVar1);
    ((int (*)())_BuildLiveOut)(uVar1);
  }
  if ((param_2 & 0x40) != 0) {
    ((int (*)())_DeadCodeEliminationSimple)(uVar1);
  }
  if ((param_2 & 0x20) != 0) {
    ((int (*)())_BuildInterferenceSets)(uVar1);
    ((int (*)())_RegistersMerge)(uVar1);
  }
  if (param_2 != 0) {
    _RegistersCleanup(uVar1);
    _ProgramFree(uVar1);
  }
  _PPStreamPackIndices(param_1);
  return;
}

/* _glpPPShaderLinearize @ 0x97c07c30 (156 bytes) */
int _glpPPShaderLinearize(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  undefined4 uVar1;
  void *pvVar2;
  int local_30 [7];
  
  pvVar2 = (void *)0x0;
  local_30[0] = 0;
  uVar1 = _PPStreamCreate();
  _PPStreamAttachStream(uVar1,param_1);
  ((int (*)())_glpPPShaderLinearizeStreamMgr)(uVar1,param_2);
  _PPStreamGetStream(uVar1,0,local_30);
  if (local_30[0] != 0) {
    pvVar2 = _malloc(local_30[0] * 8 + 0xfU & 0xfffffff0);
    _PPStreamGetStream(uVar1,pvVar2,local_30);
  }
  _PPStreamFree(uVar1);
  return pvVar2;
}

/* _glpFreePPShaderLinearize @ 0x97c07ccc (12 bytes) */
int _glpFreePPShaderLinearize(param_1)
  void *param_1;
{
  if (param_1 == (void *)0x0) {
    return;
  }
  _free(param_1);
  return;
}

/* _BitSetNew @ 0x97c07cd8 (104 bytes) */
int _BitSetNew(param_1)
  uint param_1;
{
  uint *puVar1;
  void *pvVar2;
  size_t sVar3;
  
  sVar3 = (param_1 >> 3 & 0x1ffffffc) + 4;
  puVar1 = _malloc(0xc);
  *puVar1 = param_1;
  puVar1[1] = sVar3;
  pvVar2 = _malloc(sVar3);
  puVar1[2] = (uint)pvVar2;
  ((int (*)())_BitSetSetRangeEqualsInternal)(puVar1,0,param_1,0);
  return puVar1;
}

/* _BitSetClone @ 0x97c07d40 (64 bytes) */
int _BitSetClone(param_1)
  undefined4 *param_1;
{
  undefined4 uVar1;
  
  uVar1 = ((int (*)())_BitSetNew)(*param_1);
  ((int (*)())_BitSetCopyEquals)(uVar1,param_1);
  return uVar1;
}

/* _BitSetFree @ 0x97c07d80 (52 bytes) */
int _BitSetFree(param_1)
  void *param_1;
{
  _free(*(void **)((int)param_1 + 8));
  _free(param_1);
  return;
}

/* _BitSetGetSizeInBits @ 0x97c07db4 (8 bytes) */
int _BitSetGetSizeInBits(param_1)
  undefined4 *param_1;
{
  return *param_1;
}

/* _BitSetGetEquals @ 0x97c07dbc (88 bytes) */
int _BitSetGetEquals(param_1, param_2)
  int param_1;
  uint param_2;
{
  ((int (*)())_BitSetExpandEquals)(param_1,param_2 + 1);
  return (*(uint *)((param_2 >> 3 & 0x1ffffffc) + *(int *)(param_1 + 8)) & 1 << (param_2 & 0x1f)) !=
         0;
}

/* _BitSetSetEquals @ 0x97c07e14 (88 bytes) */
int _BitSetSetEquals(param_1, param_2)
  int param_1;
  uint param_2;
{
  uint uVar1;
  
  ((int (*)())_BitSetExpandEquals)(param_1,param_2 + 1);
  uVar1 = param_2 >> 3 & 0x1ffffffc;
  *(uint *)(uVar1 + *(int *)(param_1 + 8)) =
       *(uint *)(uVar1 + *(int *)(param_1 + 8)) | 1 << (param_2 & 0x1f);
  return param_1;
}

/* _BitSetClearEquals @ 0x97c07e6c (88 bytes) */
int _BitSetClearEquals(param_1, param_2)
  int param_1;
  uint param_2;
{
  uint uVar1;
  
  ((int (*)())_BitSetExpandEquals)(param_1,param_2 + 1);
  uVar1 = param_2 >> 3 & 0x1ffffffc;
  *(uint *)(uVar1 + *(int *)(param_1 + 8)) =
       *(uint *)(uVar1 + *(int *)(param_1 + 8)) &
       (-2 << (param_2 & 0x1f) | 0xfffffffeU >> 0x20 - (param_2 & 0x1f));
  return param_1;
}

/* _BitSetSetRangeEquals @ 0x97c07ec4 (84 bytes) */
int _BitSetSetRangeEquals(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())_BitSetExpandEquals)(param_1,param_3);
  ((int (*)())_BitSetSetRangeEqualsInternal)(param_1,param_2,param_3,param_4);
  return param_1;
}

/* _BitSetSetRangeEqualsInternal @ 0x97c07f18 (100 bytes) */
int _BitSetSetRangeEqualsInternal(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  uint param_3;
  int param_4;
{
  int iVar1;
  uint uVar2;
  
  if (param_3 <= param_2) {
    return;
  }
  iVar1 = param_3 - param_2;
  do {
    if (param_4 == 0) {
      uVar2 = param_2 >> 3 & 0x1ffffffc;
      *(uint *)(uVar2 + *(int *)(param_1 + 8)) =
           *(uint *)(uVar2 + *(int *)(param_1 + 8)) & ~(1 << (param_2 & 0x1f));
    }
    else {
      uVar2 = param_2 >> 3 & 0x1ffffffc;
      *(uint *)(uVar2 + *(int *)(param_1 + 8)) =
           *(uint *)(uVar2 + *(int *)(param_1 + 8)) | 1 << (param_2 & 0x1f);
    }
    param_2 = param_2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}

/* _BitSetExpandEquals @ 0x97c07f7c (60 bytes) */
int _BitSetExpandEquals(param_1, param_2)
  uint *param_1;
  uint param_2;
{
  if (*param_1 < param_2) {
    ((int (*)())_BitSetSetSizeEquals)();
  }
  return param_1;
}

/* _BitSetSetSizeEquals @ 0x97c07fb8 (112 bytes) */
int _BitSetSetSizeEquals(param_1, param_2)
  uint *param_1;
  uint param_2;
{
  void *pvVar1;
  size_t sVar2;
  
  if (*param_1 != param_2) {
    sVar2 = (param_2 >> 3 & 0x1ffffffc) + 4;
    pvVar1 = _realloc((void *)param_1[2],sVar2);
    param_1[2] = (uint)pvVar1;
    ((int (*)())_BitSetSetRangeEqualsInternal)(param_1,*param_1,param_2,0);
    *param_1 = param_2;
    param_1[1] = sVar2;
  }
  return param_1;
}

/* _BitSetNextSetBit @ 0x97c08030 (136 bytes) */
int _BitSetNextSetBit(param_1, param_2)
  uint *param_1;
  int param_2;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = param_2 + 1U >> 5;
  uVar3 = param_2 + 1U & 0x1f;
  if (uVar4 < param_1[1] >> 2) {
    do {
      uVar1 = *(uint *)(uVar4 * 4 + param_1[2]);
      if ((uVar1 != 0) && (uVar3 < 0x20)) {
        do {
          if (((uVar1 & 1 << (uVar3 & 0x3f)) != 0) &&
             (uVar2 = uVar4 * 0x20 + uVar3, uVar2 < *param_1)) {
            return uVar2;
          }
          uVar3 = uVar3 + 1;
        } while (uVar3 < 0x20);
      }
      uVar4 = uVar4 + 1;
      uVar3 = 0;
    } while ((int)uVar4 < (int)(param_1[1] >> 2));
  }
  return 0xffffffff;
}

/* _BitSetAndEquals @ 0x97c080b8 (128 bytes) */
int _BitSetAndEquals(param_1, param_2)
  undefined4 *param_1;
  undefined4 *param_2;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  ((int (*)())_BitSetExpandEquals)(param_1,*param_2);
  ((int (*)())_BitSetExpandEquals)(param_2,*param_1);
  iVar2 = 0;
  for (uVar3 = (uint)param_1[1] >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    iVar1 = iVar2 * 4;
    iVar2 = iVar2 + 1;
    *(uint *)(iVar1 + param_1[2]) = *(uint *)(iVar1 + param_1[2]) & *(uint *)(iVar1 + param_2[2]);
  }
  return param_1;
}

/* _BitSetAndNotEquals @ 0x97c08138 (128 bytes) */
int _BitSetAndNotEquals(param_1, param_2)
  undefined4 *param_1;
  undefined4 *param_2;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  ((int (*)())_BitSetExpandEquals)(param_1,*param_2);
  ((int (*)())_BitSetExpandEquals)(param_2,*param_1);
  iVar2 = 0;
  for (uVar3 = (uint)param_1[1] >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    iVar1 = iVar2 * 4;
    iVar2 = iVar2 + 1;
    *(uint *)(iVar1 + param_1[2]) = *(uint *)(iVar1 + param_1[2]) & ~*(uint *)(iVar1 + param_2[2]);
  }
  return param_1;
}

/* _BitSetOrEquals @ 0x97c081b8 (128 bytes) */
int _BitSetOrEquals(param_1, param_2)
  undefined4 *param_1;
  undefined4 *param_2;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  ((int (*)())_BitSetExpandEquals)(param_1,*param_2);
  ((int (*)())_BitSetExpandEquals)(param_2,*param_1);
  iVar2 = 0;
  for (uVar3 = (uint)param_1[1] >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    iVar1 = iVar2 * 4;
    iVar2 = iVar2 + 1;
    *(uint *)(iVar1 + param_1[2]) = *(uint *)(iVar1 + param_1[2]) | *(uint *)(iVar1 + param_2[2]);
  }
  return param_1;
}

/* _BitSetXorEquals @ 0x97c08238 (128 bytes) */
int _BitSetXorEquals(param_1, param_2)
  undefined4 *param_1;
  undefined4 *param_2;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  ((int (*)())_BitSetExpandEquals)(param_1,*param_2);
  ((int (*)())_BitSetExpandEquals)(param_2,*param_1);
  iVar2 = 0;
  for (uVar3 = (uint)param_1[1] >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    iVar1 = iVar2 * 4;
    iVar2 = iVar2 + 1;
    *(uint *)(iVar1 + param_1[2]) = *(uint *)(iVar1 + param_1[2]) ^ *(uint *)(iVar1 + param_2[2]);
  }
  return param_1;
}

/* _BitSetCopyEquals @ 0x97c082b8 (120 bytes) */
int _BitSetCopyEquals(param_1, param_2)
  undefined4 *param_1;
  undefined4 *param_2;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  ((int (*)())_BitSetExpandEquals)(param_1,*param_2);
  ((int (*)())_BitSetExpandEquals)(param_2,*param_1);
  iVar2 = 0;
  for (uVar3 = (uint)param_1[1] >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    iVar1 = iVar2 * 4;
    iVar2 = iVar2 + 1;
    *(undefined4 *)(iVar1 + param_1[2]) = *(undefined4 *)(iVar1 + param_2[2]);
  }
  return param_1;
}

/* _BitSetEqualsTest @ 0x97c08330 (144 bytes) */
int _BitSetEqualsTest(param_1, param_2)
  int *param_1;
  undefined4 *param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  uVar4 = 1;
  ((int (*)())_BitSetExpandEquals)(param_1,*param_2);
  iVar5 = 0;
  ((int (*)())_BitSetExpandEquals)(param_2,*param_1);
  iVar3 = *param_1;
  if (0 < iVar3) {
    do {
      iVar1 = ((int (*)())_BitSetGetEquals)(param_1,iVar5);
      iVar2 = ((int (*)())_BitSetGetEquals)(param_2,iVar5);
      if (iVar1 != iVar2) {
        uVar4 = 0;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar3);
  }
  return uVar4;
}

/* _BitSetAndTest @ 0x97c083c0 (136 bytes) */
int _BitSetAndTest(param_1, param_2)
  int *param_1;
  undefined4 *param_2;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  uVar4 = 0;
  ((int (*)())_BitSetExpandEquals)(param_1,*param_2);
  ((int (*)())_BitSetExpandEquals)(param_2,*param_1);
  iVar3 = *param_1;
  iVar5 = 0;
  if (0 < iVar3) {
    do {
      uVar1 = ((int (*)())_BitSetGetEquals)(param_1,iVar5);
      iVar6 = iVar5 + 1;
      uVar2 = ((int (*)())_BitSetGetEquals)(param_2,iVar5);
      uVar4 = uVar4 | uVar1 & uVar2;
      iVar5 = iVar6;
    } while (iVar6 < iVar3);
  }
  return uVar4;
}

/* _BitSetAndNotTest @ 0x97c08448 (136 bytes) */
int _BitSetAndNotTest(param_1, param_2)
  int *param_1;
  undefined4 *param_2;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  uVar4 = 0;
  ((int (*)())_BitSetExpandEquals)(param_1,*param_2);
  ((int (*)())_BitSetExpandEquals)(param_2,*param_1);
  iVar3 = *param_1;
  iVar5 = 0;
  if (0 < iVar3) {
    do {
      uVar1 = ((int (*)())_BitSetGetEquals)(param_1,iVar5);
      iVar6 = iVar5 + 1;
      uVar2 = ((int (*)())_BitSetGetEquals)(param_2,iVar5);
      uVar4 = uVar4 | uVar1 & ~uVar2;
      iVar5 = iVar6;
    } while (iVar6 < iVar3);
  }
  return uVar4;
}

/* _BitSetOrTest @ 0x97c084d0 (136 bytes) */
int _BitSetOrTest(param_1, param_2)
  int *param_1;
  undefined4 *param_2;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  uVar4 = 0;
  ((int (*)())_BitSetExpandEquals)(param_1,*param_2);
  ((int (*)())_BitSetExpandEquals)(param_2,*param_1);
  iVar3 = *param_1;
  iVar5 = 0;
  if (0 < iVar3) {
    do {
      uVar1 = ((int (*)())_BitSetGetEquals)(param_1,iVar5);
      iVar6 = iVar5 + 1;
      uVar2 = ((int (*)())_BitSetGetEquals)(param_2,iVar5);
      uVar4 = uVar4 | uVar1 | uVar2;
      iVar5 = iVar6;
    } while (iVar6 < iVar3);
  }
  return uVar4;
}

/* _BitSetXorTest @ 0x97c08558 (136 bytes) */
int _BitSetXorTest(param_1, param_2)
  int *param_1;
  undefined4 *param_2;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  uVar4 = 0;
  ((int (*)())_BitSetExpandEquals)(param_1,*param_2);
  ((int (*)())_BitSetExpandEquals)(param_2,*param_1);
  iVar3 = *param_1;
  iVar5 = 0;
  if (0 < iVar3) {
    do {
      uVar1 = ((int (*)())_BitSetGetEquals)(param_1,iVar5);
      iVar6 = iVar5 + 1;
      uVar2 = ((int (*)())_BitSetGetEquals)(param_2,iVar5);
      uVar4 = uVar4 | uVar1 ^ uVar2;
      iVar5 = iVar6;
    } while (iVar6 < iVar3);
  }
  return uVar4;
}

/* _defaultHashFunction @ 0x97c085e0 (4 bytes) */
int _defaultHashFunction()
{
  return;
}

/* _defaultEqualsFunction @ 0x97c085e4 (8 bytes) */
int _defaultEqualsFunction(param_1, param_2)
  int param_1;
  int param_2;
{
  return param_1 - param_2;
}

/* _HashSetNew @ 0x97c085ec (192 bytes) */
int _HashSetNew(param_1, param_2, param_3)
  uint param_1;
  uint param_2;
  uint param_3;
{
  int iVar1;
  uint *puVar2;
  void *pvVar3;
  uint uVar4;
  uint uVar5;
  
  puVar2 = _malloc(0x10);
  if (param_2 == 0) {
    param_2 = DAT_a7b7bf70;
  }
  puVar2[2] = param_2;
  if (param_3 == 0) {
    param_3 = DAT_a7b7bf6c;
  }
  puVar2[3] = param_3;
  *puVar2 = param_1;
  pvVar3 = _malloc(param_1 << 3);
  uVar4 = 0;
  puVar2[1] = (uint)pvVar3;
  if (*puVar2 != 0) {
    do {
      uVar5 = puVar2[1];
      iVar1 = uVar4 * 8;
      uVar4 = uVar4 + 1;
      *(undefined4 *)(uVar5 + iVar1) = 0;
      pvVar3 = _malloc(4);
      *(void **)(uVar5 + iVar1 + 4) = pvVar3;
    } while (uVar4 < *puVar2);
  }
  return puVar2;
}

/* _HashSetFree @ 0x97c086ac (132 bytes) */
int _HashSetFree(param_1)
  uint *param_1;
{
  void *pvVar1;
  void *pvVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = 0;
  uVar3 = *param_1;
  if (uVar3 == 0) {
    pvVar1 = (void *)param_1[1];
  }
  else {
    pvVar1 = (void *)param_1[1];
    do {
      pvVar2 = *(void **)((int)pvVar1 + uVar4 * 8 + 4);
      if (pvVar2 != (void *)0x0) {
        _free(pvVar2);
        uVar3 = *param_1;
        pvVar1 = (void *)param_1[1];
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar3);
  }
  if (pvVar1 != (void *)0x0) {
    _free(pvVar1);
  }
  _free(param_1);
  return;
}

/* _HashSetAdd @ 0x97c08730 (272 bytes) */
int _HashSetAdd(param_1, param_2)
  uint *param_1;
  undefined4 param_2;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  void *pvVar4;
  uint uVar5;
  uint *puVar6;
  
  uVar5 = 0;
  uVar3 = 0xffffffff;
  uVar1 = (*(code *)param_1[2])(param_2);
  iVar2 = (uVar1 - (uVar1 / *param_1) * *param_1) * 8;
  puVar6 = (uint *)(param_1[1] + iVar2);
  if (*(int *)(param_1[1] + iVar2) == 0) {
    pvVar4 = (void *)puVar6[1];
  }
  else {
    pvVar4 = (void *)puVar6[1];
    do {
      iVar2 = *(int *)((int)pvVar4 + uVar5 * 4);
      if (iVar2 == 0) {
        if (uVar3 == 0xffffffff) {
          uVar3 = uVar5;
        }
      }
      else {
        iVar2 = (*(code *)param_1[3])(iVar2,param_2);
        if (iVar2 == 0) {
          *(undefined4 *)((int)pvVar4 + uVar5 * 4) = param_2;
          return param_1;
        }
        pvVar4 = (void *)puVar6[1];
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < *puVar6);
  }
  if (uVar3 == 0xffffffff) {
    uVar3 = *puVar6;
    *puVar6 = uVar3 + 1;
    pvVar4 = _realloc(pvVar4,(uVar3 + 1) * 4);
    puVar6[1] = (uint)pvVar4;
    *(undefined4 *)((int)pvVar4 + *puVar6 * 4 + -4) = param_2;
  }
  else {
    *(undefined4 *)((int)pvVar4 + uVar3 * 4) = param_2;
  }
  return param_1;
}

/* _HashSetGet @ 0x97c08840 (176 bytes) */
int _HashSetGet(param_1, param_2)
  uint *param_1;
  undefined4 param_2;
{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  
  uVar4 = 0;
  uVar1 = (*(code *)param_1[2])(param_2);
  iVar2 = (uVar1 - (uVar1 / *param_1) * *param_1) * 8;
  puVar3 = (uint *)(param_1[1] + iVar2);
  if (*(int *)(param_1[1] + iVar2) != 0) {
    do {
      uVar1 = puVar3[1];
      iVar2 = *(int *)(uVar1 + uVar4 * 4);
      if ((iVar2 != 0) && (iVar2 = (*(code *)param_1[3])(iVar2,param_2), iVar2 == 0)) {
        return *(undefined4 *)(uVar1 + uVar4 * 4);
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < *puVar3);
  }
  return 0;
}

/* _HashSetRemove @ 0x97c088f0 (184 bytes) */
int _HashSetRemove(param_1, param_2)
  uint *param_1;
  undefined4 param_2;
{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  
  uVar6 = 0;
  uVar3 = (*(code *)param_1[2])(param_2);
  iVar1 = (uVar3 - (uVar3 / *param_1) * *param_1) * 8;
  puVar5 = (uint *)(param_1[1] + iVar1);
  if (*(int *)(param_1[1] + iVar1) != 0) {
    do {
      uVar3 = puVar5[1];
      iVar1 = uVar6 * 4;
      if ((*(int *)(uVar3 + iVar1) != 0) &&
         (iVar4 = (*(code *)param_1[3])(*(int *)(uVar3 + iVar1),param_2), iVar4 == 0)) {
        uVar2 = *(undefined4 *)(uVar3 + iVar1);
        *(undefined4 *)(uVar3 + iVar1) = 0;
        return uVar2;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < *puVar5);
  }
  return 0;
}

/* _HashSetIteratorSetup @ 0x97c089a8 (24 bytes) */
int _HashSetIteratorSetup(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  *param_2 = param_1;
  param_2[2] = 0;
  param_2[1] = 0;
  return param_2;
}

/* _HashSetIteratorNext @ 0x97c089c0 (160 bytes) */
int _HashSetIteratorNext(param_1)
  undefined4 *param_1;
{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  
  puVar3 = (uint *)*param_1;
  uVar1 = param_1[1];
  if (uVar1 < *puVar3) {
    do {
      uVar5 = param_1[2];
      puVar4 = (uint *)(puVar3[1] + uVar1 * 8);
      if (uVar5 < *(uint *)(puVar3[1] + uVar1 * 8)) {
        iVar2 = uVar5 << 2;
        do {
          uVar5 = uVar5 + 1;
          uVar1 = puVar4[1];
          if (*(int *)(uVar1 + iVar2) != 0) {
            param_1[2] = uVar5;
            return *(undefined4 *)(uVar1 + iVar2);
          }
          param_1[2] = uVar5;
          iVar2 = iVar2 + 4;
        } while (uVar5 < *puVar4);
      }
      param_1[2] = 0;
      uVar1 = param_1[1] + 1;
      param_1[1] = uVar1;
    } while (uVar1 < *puVar3);
  }
  return 0;
}

/* _HashTableNew @ 0x97c08a60 (84 bytes) */
int _HashTableNew(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = _malloc(4);
  uVar2 = ((int (*)())_HashSetNew)(param_1,param_2,param_3);
  *puVar1 = uVar2;
  return puVar1;
}

/* _HashTableFree @ 0x97c08ab4 (160 bytes) */
int _HashTableFree(param_1)
  int *param_1;
{
  uint *puVar1;
  void *pvVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  
  uVar4 = 0;
  puVar1 = (uint *)*param_1;
  uVar3 = *puVar1;
  if (uVar3 != 0) {
    do {
      uVar6 = 0;
      puVar5 = (uint *)(puVar1[1] + uVar4 * 8);
      if (*(int *)(puVar1[1] + uVar4 * 8) != 0) {
        do {
          pvVar2 = *(void **)(puVar5[1] + uVar6 * 4);
          if (pvVar2 != (void *)0x0) {
            _free(pvVar2);
          }
          uVar6 = uVar6 + 1;
        } while (uVar6 < *puVar5);
        uVar3 = *puVar1;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar3);
    puVar1 = (uint *)*param_1;
  }
  ((int (*)())_HashSetFree)(puVar1);
  _free(param_1);
  return;
}

/* _HashTableAdd @ 0x97c08b54 (336 bytes) */
int _HashTableAdd(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  void *pvVar8;
  uint *puVar9;
  
  puVar6 = (uint *)*param_1;
  uVar7 = 0;
  uVar5 = 0xffffffff;
  uVar2 = (*(code *)puVar6[2])(param_2);
  iVar1 = (uVar2 - (uVar2 / *puVar6) * *puVar6) * 8;
  puVar9 = (uint *)(puVar6[1] + iVar1);
  if (*(int *)(puVar6[1] + iVar1) == 0) {
    pvVar8 = (void *)puVar9[1];
  }
  else {
    pvVar8 = (void *)puVar9[1];
    do {
      iVar1 = uVar7 * 4;
      if (*(undefined4 **)((int)pvVar8 + iVar1) == (undefined4 *)0x0) {
        if (uVar5 == 0xffffffff) {
          uVar5 = uVar7;
        }
      }
      else {
        iVar3 = (*(code *)puVar6[3])(**(undefined4 **)((int)pvVar8 + iVar1),param_2);
        if (iVar3 == 0) {
          **(undefined4 **)((int)pvVar8 + iVar1) = param_2;
          *(undefined4 *)(*(int *)((int)pvVar8 + iVar1) + 4) = param_3;
          return param_1;
        }
        pvVar8 = (void *)puVar9[1];
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < *puVar9);
  }
  if (uVar5 == 0xffffffff) {
    uVar5 = *puVar9;
    *puVar9 = uVar5 + 1;
    pvVar8 = _realloc(pvVar8,(uVar5 + 1) * 4);
    uVar5 = *puVar9;
    puVar9[1] = (uint)pvVar8;
    puVar4 = _malloc(8);
    *(undefined4 **)((int)pvVar8 + uVar5 * 4 + -4) = puVar4;
    *puVar4 = param_2;
    iVar1 = *(int *)((int)pvVar8 + uVar5 * 4 + -4);
  }
  else {
    puVar4 = _malloc(8);
    *(undefined4 **)((int)pvVar8 + uVar5 * 4) = puVar4;
    *puVar4 = param_2;
    iVar1 = *(int *)((int)pvVar8 + uVar5 * 4);
  }
  *(undefined4 *)(iVar1 + 4) = param_3;
  return param_1;
}

/* _HashTableGet @ 0x97c08ca4 (184 bytes) */
int _HashTableGet(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  
  uVar6 = 0;
  puVar4 = (uint *)*param_1;
  uVar1 = (*(code *)puVar4[2])(param_2);
  iVar3 = (uVar1 - (uVar1 / *puVar4) * *puVar4) * 8;
  puVar5 = (uint *)(puVar4[1] + iVar3);
  if (*(int *)(puVar4[1] + iVar3) != 0) {
    do {
      uVar1 = puVar5[1];
      puVar2 = *(undefined4 **)(uVar1 + uVar6 * 4);
      if ((puVar2 != (undefined4 *)0x0) &&
         (iVar3 = (*(code *)puVar4[3])(*puVar2,param_2), iVar3 == 0)) {
        return *(undefined4 *)(*(int *)(uVar1 + uVar6 * 4) + 4);
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < *puVar5);
  }
  return 0;
}

/* _HashTableRemove @ 0x97c08d5c (196 bytes) */
int _HashTableRemove(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  undefined4 uVar7;
  
  uVar6 = 0;
  puVar4 = (uint *)*param_1;
  uVar2 = (*(code *)puVar4[2])(param_2);
  iVar1 = (uVar2 - (uVar2 / *puVar4) * *puVar4) * 8;
  puVar5 = (uint *)(puVar4[1] + iVar1);
  if (*(int *)(puVar4[1] + iVar1) != 0) {
    do {
      uVar2 = puVar5[1];
      iVar1 = uVar6 * 4;
      if ((*(undefined4 **)(uVar2 + iVar1) != (undefined4 *)0x0) &&
         (iVar3 = (*(code *)puVar4[3])(**(undefined4 **)(uVar2 + iVar1),param_2), iVar3 == 0)) {
        uVar7 = *(undefined4 *)((int)*(void **)(uVar2 + iVar1) + 4);
        _free(*(void **)(uVar2 + iVar1));
        *(undefined4 *)(uVar2 + iVar1) = 0;
        return uVar7;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < *puVar5);
  }
  return 0;
}

/* _GetValidArgs @ 0x97c08e20 (32 bytes) */
int _GetValidArgs(param_1)
  int param_1;
{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0xc) >> 0x1d;
  if (3 < (*(uint *)(param_1 + 0xc) >> 0x12 & 0xff) - 0x42) {
    return uVar1;
  }
  return uVar1 - 1;
}

/* _GetStreamArray_97c08e40 @ 0x97c08e40 (164 bytes) */
int _GetStreamArray_97c08e40(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint param_2;
  int param_3;
  uint *param_4;
  uint *param_5;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = 0;
  if (param_1 == 1) {
    for (iVar1 = **(int **)(param_3 + 8); iVar1 != 0; iVar1 = *(int *)(iVar1 + 8)) {
      uVar3 = (uint)*(ushort *)(iVar1 + 0xe);
      if ((uVar3 <= param_2) && (param_2 <= *(ushort *)(iVar1 + 0x12))) {
LAB_97c08e8c:
        *param_4 = uVar3;
        *param_5 = (uint)*(ushort *)(iVar1 + 0x12);
        return iVar2;
      }
      iVar2 = iVar2 + 1;
    }
  }
  else if (param_1 == 2) {
    for (iVar1 = **(int **)(param_3 + 0x14); iVar1 != 0; iVar1 = *(int *)(iVar1 + 8)) {
      uVar3 = (uint)*(ushort *)(iVar1 + 0xe);
      if ((uVar3 <= param_2) && (param_2 <= *(ushort *)(iVar1 + 0x12))) goto LAB_97c08e8c;
      iVar2 = iVar2 + 1;
    }
  }
  return -1;
}

/* _GetRegisterIndicies @ 0x97c08ee4 (168 bytes) */
int _GetRegisterIndicies(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  int *param_2;
  int *param_3;
  undefined4 param_4;
  int param_5;
  int param_6;
  int param_7;
  int param_8;
{
  int iVar1;
  
  *param_2 = 0;
  *param_3 = -1;
  if (param_6 != 0) {
    _GetStreamArray(param_4,param_5,param_1,param_2,param_3);
  }
  iVar1 = *param_3;
  if (((iVar1 == -1) && (param_7 != 0)) && (1 < param_8 + 1)) {
    iVar1 = param_5 + param_8;
    *param_2 = param_5;
    *param_3 = iVar1;
  }
  if (iVar1 == -1) {
    *param_2 = param_5;
    *param_3 = param_5;
  }
  return;
}

/* _GetRegister @ 0x97c08f8c (160 bytes) */
int _GetRegister(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  int param_3;
  int param_4;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0;
  uVar2 = 0;
  switch(param_2) {
  case 0:
    iVar3 = *(int *)(param_1 + 0x24);
    uVar2 = *(uint *)(param_1 + 0x38);
    break;
  case 1:
    iVar3 = *(int *)(param_1 + 0x20);
    uVar2 = *(uint *)(param_1 + 0x34);
    break;
  case 2:
    iVar3 = *(int *)(param_1 + 0x28);
    uVar2 = *(uint *)(param_1 + 0x3c);
    break;
  case 3:
    iVar3 = *(int *)(param_1 + 0x1c);
    uVar2 = *(uint *)(param_1 + 0x30);
    break;
  case 4:
    iVar3 = *(int *)(param_1 + 0x2c);
    uVar2 = *(uint *)(param_1 + 0x40);
  }
  uVar1 = iVar3 + param_3 * 4 + param_4;
  if (uVar1 < uVar2) {
    return *(int *)(param_1 + 0x10) + uVar1 * 0x2c;
  }
  return 0;
}

/* _BuildGenKill @ 0x97c09040 (364 bytes) */
int _BuildGenKill(param_1)
  int param_1;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  uint *puVar7;
  int iVar8;
  undefined4 *puVar9;
  uint uVar10;
  
  uVar3 = 0;
  if (*(int *)(param_1 + 4) != 0) {
    iVar4 = 0;
    do {
      iVar8 = *(int *)(param_1 + 8);
      uVar5 = 0;
      puVar6 = (uint *)(iVar8 + iVar4);
      uVar1 = ((int (*)())_BitSetNew)(*(undefined4 *)(param_1 + 0xc));
      puVar6[9] = uVar1;
      uVar1 = ((int (*)())_BitSetNew)(*(undefined4 *)(param_1 + 0xc));
      puVar6[10] = uVar1;
      uVar1 = ((int (*)())_BitSetNew)(*(undefined4 *)(param_1 + 0xc));
      iVar8 = *(int *)(iVar8 + iVar4);
      puVar6[6] = uVar1;
      if (iVar8 != 0) {
        iVar8 = 0;
        do {
          puVar7 = (uint *)(puVar6[1] + iVar8);
          if (puVar7[5] == 0) {
            uVar1 = 0;
            if (*(int *)(puVar6[1] + iVar8) != 0) {
              do {
                puVar9 = *(undefined4 **)(uVar1 * 4 + puVar7[1]);
                if (puVar9[6] == 0) {
                  iVar2 = ((int (*)())_BitSetGetEquals)(puVar6[10],*puVar9);
                  if (iVar2 == 0) {
                    ((int (*)())_BitSetSetEquals)(puVar6[9],*puVar9);
                  }
                  puVar9[9] = puVar9[9] + 1;
                }
                uVar1 = uVar1 + 1;
              } while (uVar1 < *puVar7);
            }
            uVar1 = puVar7[2];
            uVar10 = 0;
            if (uVar1 != 0) {
              do {
                puVar9 = *(undefined4 **)(uVar10 * 4 + puVar7[3]);
                if (puVar9[6] == 0) {
                  ((int (*)())_BitSetSetEquals)(puVar6[10],*puVar9);
                  puVar9[9] = puVar9[9] + 1;
                  uVar1 = puVar7[2];
                }
                uVar10 = uVar10 + 1;
              } while (uVar10 < uVar1);
            }
          }
          uVar5 = uVar5 + 1;
          iVar8 = iVar8 + 0x1c;
        } while (uVar5 < *puVar6);
      }
      uVar3 = uVar3 + 1;
      iVar4 = iVar4 + 0x2c;
    } while (uVar3 < *(uint *)(param_1 + 4));
  }
  return;
}

/* _BuildLiveOut @ 0x97c091ac (240 bytes) */
int _BuildLiveOut(param_1)
  int param_1;
{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  uVar2 = *(uint *)(param_1 + 4);
  do {
    bVar1 = false;
    uVar5 = 0;
    if (uVar2 != 0) {
      iVar6 = 0;
      do {
        uVar2 = 0;
        iVar8 = *(int *)(param_1 + 8) + iVar6;
        uVar3 = ((int (*)())_BitSetClone)(*(undefined4 *)(iVar8 + 0x18));
        if (*(int *)(iVar8 + 0x10) != 0) {
          do {
            iVar7 = uVar2 * 4;
            uVar2 = uVar2 + 1;
            iVar7 = *(int *)(iVar7 + *(int *)(iVar8 + 0x14));
            uVar4 = ((int (*)())_BitSetClone)(*(undefined4 *)(iVar7 + 0x18));
            ((int (*)())_BitSetAndNotEquals)(uVar4,*(undefined4 *)(iVar7 + 0x28));
            ((int (*)())_BitSetOrEquals)(uVar4,*(undefined4 *)(iVar7 + 0x24));
            ((int (*)())_BitSetOrEquals)(*(undefined4 *)(iVar8 + 0x18),uVar4);
            ((int (*)())_BitSetFree)(uVar4);
          } while (uVar2 < *(uint *)(iVar8 + 0x10));
        }
        uVar5 = uVar5 + 1;
        iVar6 = iVar6 + 0x2c;
        iVar8 = ((int (*)())_BitSetEqualsTest)(uVar3,*(undefined4 *)(iVar8 + 0x18));
        bVar1 = (bool)(bVar1 | iVar8 == 0);
        ((int (*)())_BitSetFree)(uVar3);
        uVar2 = *(uint *)(param_1 + 4);
      } while (uVar5 < uVar2);
    }
  } while (bVar1);
  return;
}

/* _BuildInterferenceSets @ 0x97c0929c (436 bytes) */
int _BuildInterferenceSets(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint *puVar8;
  undefined4 *puVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  
  uVar4 = 0;
  if (*(int *)(param_1 + 4) != 0) {
    iVar5 = 0;
    do {
      iVar11 = *(int *)(param_1 + 8);
      iVar6 = iVar11 + iVar5;
      uVar1 = ((int (*)())_BitSetClone)(*(undefined4 *)(iVar6 + 0x18));
      iVar11 = *(int *)(iVar11 + iVar5) + -1;
      if (-1 < iVar11) {
        iVar7 = iVar11 * 0x1c;
        do {
          puVar8 = (uint *)(*(int *)(iVar6 + 4) + iVar7);
          if (puVar8[5] == 0) {
            uVar3 = puVar8[2];
            uVar10 = 0;
            if (uVar3 != 0) {
              do {
                puVar9 = *(undefined4 **)(uVar10 * 4 + puVar8[3]);
                if (puVar9[6] == 0) {
                  for (iVar2 = _BitSetFirstSetBit(uVar1); iVar2 != -1;
                      iVar2 = ((int (*)())_BitSetNextSetBit)(uVar1,iVar2)) {
                    iVar12 = *(int *)(param_1 + 0x10) + iVar2 * 0x2c;
                    if (*(int *)(iVar12 + 0x18) == 0) {
                      ((int (*)())_BitSetSetEquals)(puVar9[2],
                                       *(undefined4 *)(*(int *)(param_1 + 0x10) + iVar2 * 0x2c));
                      ((int (*)())_BitSetSetEquals)(*(undefined4 *)(iVar12 + 8),*puVar9);
                    }
                  }
                  uVar3 = puVar8[2];
                }
                uVar10 = uVar10 + 1;
              } while (uVar10 < uVar3);
            }
            uVar10 = 0;
            if (uVar3 != 0) {
              do {
                puVar9 = *(undefined4 **)(uVar10 * 4 + puVar8[3]);
                if (puVar9[6] == 0) {
                  ((int (*)())_BitSetClearEquals)(uVar1,*puVar9);
                  uVar3 = puVar8[2];
                }
                uVar10 = uVar10 + 1;
              } while (uVar10 < uVar3);
            }
            uVar3 = *puVar8;
            uVar10 = 0;
            if (uVar3 != 0) {
              do {
                puVar9 = *(undefined4 **)(uVar10 * 4 + puVar8[1]);
                if (puVar9[6] == 0) {
                  ((int (*)())_BitSetSetEquals)(uVar1,*puVar9);
                  uVar3 = *puVar8;
                }
                uVar10 = uVar10 + 1;
              } while (uVar10 < uVar3);
            }
          }
          iVar11 = iVar11 + -1;
          iVar7 = iVar7 + -0x1c;
        } while (-1 < iVar11);
      }
      uVar4 = uVar4 + 1;
      ((int (*)())_BitSetFree)(uVar1);
      iVar5 = iVar5 + 0x2c;
    } while (uVar4 < *(uint *)(param_1 + 4));
  }
  return;
}

/* _RegistersMerge @ 0x97c09450 (612 bytes) */
int _RegistersMerge(param_1)
  int param_1;
{
  undefined4 *puVar1;
  size_t sVar2;
  bool bVar3;
  int iVar4;
  int *piVar5;
  void *pvVar6;
  void *pvVar7;
  int *piVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  int local_50 [6];
  
  pvVar6 = _malloc(8);
  iVar12 = 0;
  pvVar7 = _malloc(0x10);
  piVar8 = _realloc(pvVar7,0x10);
  iVar16 = 4;
  uVar14 = 1;
  iVar9 = 0;
  piVar5 = piVar8;
  do {
    iVar4 = *(int *)(param_1 + 0x10) + iVar9;
    iVar9 = iVar9 + 0x2c;
    *piVar5 = iVar4;
    piVar5 = piVar5 + 1;
    iVar16 = iVar16 + -1;
  } while (iVar16 != 0);
  uVar13 = 4;
  if (4 < *(uint *)(param_1 + 0xc)) {
    iVar9 = 0xb0;
    do {
      iVar16 = iVar9 + *(int *)(param_1 + 0x10);
      iVar4 = 4;
      piVar5 = local_50;
      do {
        *piVar5 = iVar16;
        piVar5 = piVar5 + 1;
        iVar16 = iVar16 + 0x2c;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      bVar3 = false;
      iVar16 = _RegisterVectorIsFixed(local_50);
      if (iVar16 == 0) {
        uVar15 = 0;
        piVar5 = piVar8;
        if (uVar14 != 0) {
LAB_97c09514:
          iVar16 = _RegisterVectorCanMerge(piVar5,local_50);
          if (iVar16 == 0) goto LAB_97c09608;
          iVar4 = 0;
          iVar16 = 3;
          do {
            iVar12 = iVar12 + 1;
            sVar2 = iVar12 * 8;
            ((int (*)())_BitSetOrEquals)(*(undefined4 *)(*(int *)(iVar4 + (int)piVar5) + 8),
                            *(undefined4 *)(*(int *)(iVar4 + (int)local_50) + 8));
            *(int *)(*(int *)(iVar4 + (int)piVar5) + 0x24) =
                 *(int *)(*(int *)(iVar4 + (int)piVar5) + 0x24) +
                 *(int *)(*(int *)(iVar4 + (int)local_50) + 0x24);
            *(undefined4 *)(*(int *)(iVar4 + (int)local_50) + 0x18) = 1;
            _RegistersReInterfere
                      (param_1,*(undefined4 *)(iVar4 + (int)local_50),
                       *(undefined4 *)(iVar4 + (int)piVar5));
            pvVar6 = _realloc(pvVar6,sVar2);
            iVar16 = iVar16 + -1;
            *(undefined4 *)((int)pvVar6 + (sVar2 - 8)) = *(undefined4 *)(iVar4 + (int)local_50);
            puVar1 = (undefined4 *)(iVar4 + (int)piVar5);
            iVar4 = iVar4 + 4;
            *(undefined4 *)((int)pvVar6 + (sVar2 - 4)) = *puVar1;
          } while (-1 < iVar16);
          if ((*(int *)(*piVar5 + 0x14) == 1) && (*(int *)(local_50[0] + 0x14) == 1)) {
            iVar16 = *(int *)(*piVar5 + 0x28);
            uVar11 = *(uint *)(iVar16 + 0xc);
            uVar15 = *(uint *)(*(int *)(local_50[0] + 0x28) + 0xc) >> 0x18 & 3;
            uVar10 = uVar11 >> 0x18 & 3;
            if (uVar15 < uVar10) {
              uVar15 = uVar10;
            }
            *(uint *)(iVar16 + 0xc) = uVar15 << 0x18 | uVar11 & 0xfcffffff;
          }
          bVar3 = true;
        }
LAB_97c09618:
        if (!bVar3) goto LAB_97c09620;
      }
      else {
LAB_97c09620:
        uVar14 = uVar14 + 1;
        piVar8 = _realloc(piVar8,uVar14 * 0x10);
        iVar4 = 4;
        iVar16 = 0;
        do {
          *(undefined4 *)((int)piVar8 + iVar16 + (uVar14 * 0x10 - 0x10)) =
               *(undefined4 *)(iVar16 + (int)local_50);
          iVar16 = iVar16 + 4;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
      uVar13 = uVar13 + 4;
      iVar9 = iVar9 + 0xb0;
    } while (uVar13 < *(uint *)(param_1 + 0xc));
  }
  if (piVar8 != (int *)0x0) {
    _free(piVar8);
  }
  _RegistersReplace(param_1,iVar12,pvVar6);
  if (pvVar6 != (void *)0x0) {
    _free(pvVar6);
  }
  return;
LAB_97c09608:
  uVar15 = uVar15 + 1;
  piVar5 = piVar5 + 4;
  if (uVar14 <= uVar15) goto LAB_97c09618;
  goto LAB_97c09514;
}

/* _DeadCodeEliminationSimple @ 0x97c096b4 (440 bytes) */
int _DeadCodeEliminationSimple(param_1)
  undefined4 *param_1;
{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint *puVar12;
  
  uVar6 = 0;
  if (param_1[1] != 0) {
    iVar7 = 0;
    do {
      iVar10 = param_1[2];
      iVar8 = iVar10 + iVar7;
      uVar2 = ((int (*)())_BitSetClone)(*(undefined4 *)(iVar8 + 0x18));
      iVar10 = *(int *)(iVar10 + iVar7) + -1;
      if (-1 < iVar10) {
        iVar9 = iVar10 * 0x1c;
        do {
          puVar12 = (uint *)(*(int *)(iVar8 + 4) + iVar9);
          if (puVar12[5] == 0) {
            uVar5 = puVar12[2];
            uVar11 = 0;
            if (uVar5 == 0) {
              bVar1 = puVar12[4] == 0;
LAB_97c0978c:
              if (bVar1) {
                _PPStreamRemoveOperation(*param_1,puVar12[6]);
                puVar12[5] = 1;
                goto LAB_97c09828;
              }
            }
            else {
              bVar1 = puVar12[4] == 0;
              if (bVar1) {
                do {
                  puVar4 = *(undefined4 **)(uVar11 * 4 + puVar12[3]);
                  if (puVar4[6] == 0) {
                    iVar3 = ((int (*)())_BitSetGetEquals)(uVar2,*puVar4);
                    if (iVar3 != 0) {
                      bVar1 = false;
                    }
                    uVar5 = puVar12[2];
                  }
                  uVar11 = uVar11 + 1;
                  if (uVar5 <= uVar11) goto LAB_97c0978c;
                } while (bVar1);
              }
            }
            uVar11 = 0;
            if (uVar5 != 0) {
              do {
                puVar4 = *(undefined4 **)(uVar11 * 4 + puVar12[3]);
                if (puVar4[6] == 0) {
                  ((int (*)())_BitSetClearEquals)(uVar2,*puVar4);
                  uVar5 = puVar12[2];
                }
                uVar11 = uVar11 + 1;
              } while (uVar11 < uVar5);
            }
            uVar5 = *puVar12;
            uVar11 = 0;
            if (uVar5 != 0) {
              do {
                puVar4 = *(undefined4 **)(uVar11 * 4 + puVar12[1]);
                if (puVar4[6] == 0) {
                  ((int (*)())_BitSetSetEquals)(uVar2,*puVar4);
                  uVar5 = *puVar12;
                }
                uVar11 = uVar11 + 1;
              } while (uVar11 < uVar5);
            }
          }
LAB_97c09828:
          iVar10 = iVar10 + -1;
          iVar9 = iVar9 + -0x1c;
        } while (-1 < iVar10);
      }
      uVar6 = uVar6 + 1;
      ((int (*)())_BitSetFree)(uVar2);
      iVar7 = iVar7 + 0x2c;
    } while (uVar6 < (uint)param_1[1]);
  }
  return;
}

